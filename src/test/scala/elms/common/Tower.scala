package elms.koika.test.common

import scala.collection.mutable

import elms.prelude.*
import elms.prelude.given

@virtualize
trait Common extends Isa {
  val prog: Vector[Instr]
  def useCache: Boolean

  // One emitted C function per slot. A slot is a pc in every model but
  // [Predictive], which needs one per lookahead state and so hands out its own
  // numbering.
  //
  // The number is the function's identity, not a hint: it is what [slotName]
  // spells and what every call site to that slot writes down. Two slots that
  // number the same are one function whether or not they mean the same thing.
  def slot(pc: Int): Int = pc
  def resume(at: Int, s: Rep[State]): Rep[State] = execute(at, s)
  def live(at: Int): Boolean = at < prog.length

  private val declared = mutable.Set[Int]()

  // Slots asked for but not yet staged, and how to put the staging-time state
  // back the way the [call] that asked left it.
  private val pending = mutable.Queue[(Int, () => Unit)]()

  // The name is the forward reference. `fun` stages a body the moment it is
  // handed one, so a call site that wants a slot the worklist has not reached
  // has nothing to apply but the name that slot's function will be given.
  private def slotName(at: Int): String = s"slot_$at"

  // A slot's body is staged where the worklist reaches it rather than where the
  // [call] that asked for it sits, so a model that carries staging-time state
  // in a `var` between instructions has to send a copy along. [Predictive]
  // interns all of its into the slot number and so needs nothing here.
  def checkpoint(): () => Unit = () => ()

  def tick(s: Rep[State]): Rep[Unit] = s.timer = s.timer + 1

  // The indirection via `execute` is necessary to generate functions for
  // each instruction. [Speculative] is the only thing that overrides it, and
  // when it wants plain semantics it asks for [step] rather than [super]:
  // "the next `execute` in the chain" would depend on where the ISA lands in
  // the linearization, which is exactly the coupling this split removes.
  def execute(pc: Int, s: Rep[State]): Rep[State] = step(pc, s)

  def call(i: Int, s: Rep[State]): Rep[State] = {
    require(i >= 0, s"jump to negative pc $i")
    if (useCache) {
      val at = slot(i)
      if (live(at)) { declare(at)(s) } else { s }
    } else { resume(slot(i), s) }
  }

  // Put [at] on the worklist the first time anything asks for it, and hand this
  // call site a reference to the function it will be given. Nothing is staged
  // here, which is what keeps [call] from re-entering itself: the old version
  // staged the body inline and so nested one `fill` per instruction, which a
  // few hundred instructions of RISC-V is enough to overflow the stack with.
  //
  // The reference is rebuilt per call site rather than memoized with the slot.
  // What comes back names a class in the e-graph of whichever function is open,
  // and every function has its own, so one handed to a second function reaches
  // whatever that index happens to mean over there.
  private def declare(at: Int): Rep[State => State] = {
    if (declared.add(at)) { pending.enqueue((at, checkpoint())) }
    unsafeDeclare[State => State](slotName(at))
  }

  // Slots come off this list and go back on it while it drains, which is the
  // point: every body is staged at the same depth, so how deep the program's
  // own call graph runs stops being a question about the JVM stack.
  private def drain(): Unit =
    while (pending.nonEmpty) {
      val (at, restore) = pending.dequeue()
      restore()
      fun(slotName(at)) { (s: Rep[State]) => resume(at, s) }
    }

  def snippet(s: Rep[State]): Rep[State] = {
    val entry = call(0, s)
    drain()
    entry
  }
}

// A register file and a memory with no cache in front of either.
@virtualize
trait Direct extends Common {
  override def useCache = true

  override def get_reg(s: Rep[State], i: Rep[Int]): Rep[Int] = s.regs(i)
  override def set_reg(s: Rep[State], i: Rep[Int], v: Rep[Int]): Rep[Unit] =
    s.regs(i) = v

  override def get_mem(s: Rep[State], i: Rep[Int]): Rep[Int] = s.mem(i)
  override def set_mem(s: Rep[State], i: Rep[Int], v: Rep[Int]): Rep[Unit] =
    s.mem(i) = v
}

@virtualize
trait Cached extends Direct {
  def pushLRU(s: Rep[State], addr: Rep[Int], v: Rep[Int]): Rep[Unit] = {
    s.cache_keys(1) = s.cache_keys(0)
    s.cache_vals(1) = s.cache_vals(0)

    s.cache_keys(0) = addr
    s.cache_vals(0) = v
  }

  def runCache(s: Rep[State], addr: Rep[Int], v: Option[Rep[Int]]): Rep[Int] = {
    if (s.cache_keys(0) === addr) {
      // address is in cache, return value
      v match {
        case Some(x) => {
          s.cache_vals(0) = x
          x
        }
        case None => s.cache_vals(0)
      }
    } else if (s.cache_keys(1) === addr) {
      // key is at tail of LRU queue, so set addr as head
      val result = v match {
        case Some(x) => x
        case None    => s.cache_vals(1)
      }

      pushLRU(s, addr, result)

      s.timer += 1
      result
    } else {
      // address not in cache
      val result = v match {
        case Some(x) => x
        case None    => s.mem(addr)
      }

      // evict LRU and write back to memory
      // CR-soon cwong: Triple-check that this is correct -- I think we might
      // accidentally write back to memory too soon if a speculative
      // instruction evicts an entry.
      s.mem(s.cache_keys(1)) = s.cache_vals(1)

      pushLRU(s, addr, result)

      s.timer += 100

      result
    }
  }

  override def get_mem(s: Rep[State], addr: Rep[Int]): Rep[Int] =
    runCache(s, addr, None)

  override def set_mem(s: Rep[State], addr: Rep[Int], v: Rep[Int]): Rep[Unit] = {
    runCache(s, addr, Some(v))
    unit(())
  }
}

@virtualize
trait Speculative extends Cached {
  given liftable: Liftable[Unit] = summon[Liftable[Unit]]

  // Insertion-ordered on purpose: [rollback] iterates this to emit code, so a
  // plain [Set] would make the register order in the generated C a function of
  // [Reg]'s `hashCode`.
  val savedRegisters = mutable.LinkedHashSet[Reg]()

  def saveForRollback(s: Rep[State], rd: Reg): Rep[Unit] = {
    if (!savedRegisters.contains(rd)) {
      s.saved_regs(regIndex(rd)) = get_reg(s, regIndex(rd))
      savedRegisters += rd
    }
    unit(())
  }
  def rollback(s: Rep[State]): Rep[Unit] = {
    s.timer += 15
    for (rd <- savedRegisters) { set_reg(s, regIndex(rd), s.saved_regs(regIndex(rd))) }
    unit(())
  }
  def resetSaved(): Unit = { savedRegisters.clear() }

  var inBranch: Option[(Cond, Int)] = None

  // [useCache] is `inBranch.isEmpty`, so a slot only ever reaches the worklist
  // with the window closed and there is nothing to remember about that. The
  // saved registers are another matter: the join-point arm of [execute] calls
  // before it clears them, so the set travels with the slot.
  override def checkpoint(): () => Unit = {
    val saved = savedRegisters.toVector
    () => {
      inBranch = None
      resetSaved()
      savedRegisters ++= saved
    }
  }

  override def useCache: Boolean = inBranch.isEmpty
  override def execute(pc: Int, s: Rep[State]): Rep[State] = inBranch match {
    case None if pc < prog.length => branch(pc, prog(pc)) match {
        // Forwards only, and the test belongs here rather than in [Isa.branch].
        // While speculating [useCache] is false, so [call] inlines [execute]
        // instead of going through the memo table; a backward target inside a
        // speculation window inlines forever.
        case Some((cnd, tgt)) if tgt > pc => {
          inBranch = Some((cnd, tgt))
          call(pc + 1, s)
        }
        case _ => step(pc, s)
      }
    case None => step(pc, s)
    case Some((cnd, tgt)) => {
      // The join-point test comes before the bounds test: [tgt] can be
      // `prog.length`, and with [useCache] false [call] no longer filters
      // out-of-range indices.
      if (pc == tgt) {
        // Assigned before [call], because it re-enables memoization and is what
        // makes that call emit a real C function call rather than inlining.
        inBranch = None
        if (evalCond(s, cnd)) {
          rollback(s)
          call(tgt, s)
        }
        resetSaved()
        s
      } else if (pc < prog.length) {
        speculable(prog(pc)) match {
          case Some(rd) if !reads(cnd).contains(rd) => {
            saveForRollback(s, rd)
            step(pc, s)
          }
          case _ => {
            inBranch = None
            // The two arms have to be the value of the virtualized `if` rather
            // than assignments to a `var`. A `var` here is an ordinary Scala
            // variable holding a `Rep`, so it ends up naming whichever arm was
            // staged last, and the emitted C returns a symbol declared inside
            // the other branch's block.
            val result =
              if (evalCond(s, cnd)) {
                rollback(s)
                call(tgt, s)
              } else { step(pc, s) }
            resetSaved()
            result
          }
        }
      } else { s }
    }
  }
}
