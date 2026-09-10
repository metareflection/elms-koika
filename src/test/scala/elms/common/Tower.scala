package elms.koika.test.common

import scala.collection.mutable

import elms.prelude.*
import elms.prelude.given

@virtualize
trait Common extends Isa {
  val prog: Vector[Instr]
  def useCache: Boolean

  lazy val cache: Array[Option[Rep[StateT => StateT]]] =
    (for (p <- prog) yield None).toArray

  def tick(s: Rep[StateT]): Rep[Unit] = s.timer = s.timer + 1

  // The indirection via `execute` is necessary to generate functions for
  // each instruction. [Speculative] is the only thing that overrides it, and
  // when it wants plain semantics it asks for [step] rather than [super]:
  // "the next `execute` in the chain" would depend on where the ISA lands in
  // the linearization, which is exactly the coupling this split removes.
  def execute(pc: Int, s: Rep[StateT]): Rep[StateT] = step(pc, s)

  def call(i: Int, s: Rep[StateT]): Rep[StateT] =
    if (useCache) {
      if (i < cache.length) {
        val f = cache(i) match {
          case None => {
            val f = fun { (s: Rep[StateT]) => execute(i, s) }
            cache(i) = Some(f)
            f
          }
          case Some(f) => f
        }
        f(s)
      } else { s }
    } else { execute(i, s) }

  def snippet(s: Rep[StateT]): Rep[StateT] = call(0, s)
}

// A register file and a memory with no cache in front of either.
@virtualize
trait Direct extends Common {
  override def useCache = true

  override def get_reg(s: Rep[StateT], i: Rep[Int]): Rep[Int] = s.regs(i)
  override def set_reg(s: Rep[StateT], i: Rep[Int], v: Rep[Int]): Rep[Unit] =
    s.regs(i) = v

  override def get_mem(s: Rep[StateT], i: Rep[Int]): Rep[Int] = s.mem(i)
  override def set_mem(s: Rep[StateT], i: Rep[Int], v: Rep[Int]): Rep[Unit] =
    s.mem(i) = v
}

@virtualize
trait Cached extends Direct {
  def pushLRU(s: Rep[StateT], addr: Rep[Int], v: Rep[Int]): Rep[Unit] = {
    s.cache_keys(1) = s.cache_keys(0)
    s.cache_vals(1) = s.cache_vals(0)

    s.cache_keys(0) = addr
    s.cache_vals(0) = v
  }

  def runCache(s: Rep[StateT], addr: Rep[Int], v: Option[Rep[Int]]): Rep[Int] = {
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

  override def get_mem(s: Rep[StateT], addr: Rep[Int]): Rep[Int] =
    runCache(s, addr, None)

  override def set_mem(s: Rep[StateT], addr: Rep[Int], v: Rep[Int]): Rep[Unit] = {
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

  def saveForRollback(s: Rep[StateT], rd: Reg): Rep[Unit] = {
    if (!savedRegisters.contains(rd)) {
      s.saved_regs(regIndex(rd)) = get_reg(s, regIndex(rd))
      savedRegisters += rd
    }
    unit(())
  }
  def rollback(s: Rep[StateT]): Rep[Unit] = {
    s.timer += 15
    for (rd <- savedRegisters) { set_reg(s, regIndex(rd), s.saved_regs(regIndex(rd))) }
    unit(())
  }
  def resetSaved(): Unit = { savedRegisters.clear() }

  var inBranch: Option[(Cond, Int)] = None

  override def useCache: Boolean = inBranch.isEmpty
  override def execute(pc: Int, s: Rep[StateT]): Rep[StateT] = inBranch match {
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
            var result: Rep[StateT] = s
            inBranch = None
            if (evalCond(s, cnd)) {
              rollback(s)
              result = call(tgt, s)
            } else { result = step(pc, s) }
            resetSaved()
            result
          }
        }
      } else { s }
    }
  }
}
