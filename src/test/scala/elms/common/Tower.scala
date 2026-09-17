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

  // Cycles the clock pays for, now.
  def spend(s: Rep[State], lat: Rep[Int]): Rep[Unit] = s.timer += lat

  // What a load costs. The same thing, for every model that stalls on one, and
  // that is every model up to here. It is a separate name because a load is the
  // one access somebody is waiting on: a machine that lets the instructions
  // behind it keep going charges this to the register that waits rather than to
  // the clock, and a memory system that had already spent it would have nothing
  // left to hand over.
  def defer(s: Rep[State], lat: Rep[Int]): Rep[Unit] = spend(s, lat)

  // Register traffic that is the tower's rather than the program's: copying a
  // register somewhere a rollback can find it, putting one back, and reading a
  // branch's operands at the join point where the answer is wanted rather than
  // at the branch that wanted it. A model that times register accesses has to
  // be told which ones a machine would actually have performed, and this is
  // where it is told. Nothing, for a model that times none of them.
  def untimed[A](body: => A): A = body

  // A squash, after the penalty has been charged. A machine that has just
  // thrown away everything it was working on has nothing in flight, so a model
  // carrying in-flight state clears it here.
  //
  // What this must not undo is the cache. A load that missed has already moved
  // the line, a re-executed load to that address hits, and that is the channel
  // every model from [Speculative] rightward exists to expose.
  def squash(s: Rep[State]): Rep[Unit] = unit(())

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

  // What the model still owes when the program runs out of instructions.
  // Nothing, for every model that has already spent every cycle it charged.
  def finish(s: Rep[State]): Rep[State] = s

  def snippet(s: Rep[State]): Rep[State] = {
    val entry = call(0, s)
    drain()
    finish(entry)
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

// A set-associative, LRU, line-granular cache hierarchy in front of memory.
//
// Three knobs decide how much of this reaches the residue and they do not cost
// the same. Sets are free: the set index is a [Rep], so
// `cache_tags(base + set * ways + w)` is one symbolic subscript into inline
// storage however many sets there are, which is what `mem` already was. Ways
// are nearly free, because the tag comparison is arithmetic rather than a
// chain of `if`s: [eqMask] turns equality into a bit mask and the matching way
// number falls out of an `or`, so W ways is W expressions and still exactly
// two arms. Levels are what costs, one arm apiece.
//
// That is the whole reason the shape below is worth the trouble. Two levels
// fork threefold per access, which is exactly what the two-entry LRU this
// replaces already did, so `branchy`'s path space is the one it was written
// for and the way count can grow without touching it.
//
// [Isa.get_mem] is word-indexed, so what arrives is a word address and its
// line is `addr >>> lineBits`. An entry holds a line rather than a word, which
// is the point of the exercise: a lookup table that fits inside one line is
// one probe, and "the table fits in a line" is the argument real constant-time
// code actually makes.
//
// A dirty bit also answers a worry the old model carried in a `CR-soon`, about
// writing an evicted line back too early when a speculative instruction is what
// displaced it. A clean line writes nothing, so there is nothing to undo, and a
// dirty line was dirtied by a committed store: [Isa.speculable] refuses a store
// outright and [Forwarding] holds one in its queue until `close`. So a
// write-back is always a write-back of committed data, and when it happens is
// not architecturally observable. The cache's own state is another matter, and
// deliberately so, since that is the channel.
@virtualize
trait Cached extends Direct {
  // Supplied by [GenericKoikaDriver], which is where the state lengths this
  // has to agree with are fixed.
  def geometry: Geometry

  // What a line costs when no level has it.
  def memCost: Int = 100

  private def lineWords: Int = geometry.lineWords
  private def levels: Vector[Level] = geometry.levels

  // -1 when the two are equal and 0 otherwise, out of a sign bit rather than
  // out of a comparison. `d | -d` has its top bit set for every d but zero, so
  // this is equality with no branch in it, which is what lets a way count grow
  // without the residue forking per way.
  private def eqMask(a: Rep[Int], b: Rep[Int]): Rep[Int] = {
    val d = a ^ b
    ~((d | (unit(0) - d)) >> unit(31))
  }

  // [t] where [m] is all ones, [f] where it is zero.
  private def pick(m: Rep[Int], t: Rep[Int], f: Rep[Int]): Rep[Int] = f ^ (m & (t ^ f))

  // Where [line] would live at [level], and whether it is there.
  //
  // [hit] is a mask and not a [Rep[Boolean]] on purpose: the caller both tests
  // it and selects a latency with it, and a mask does the second without a
  // second comparison.
  private case class Probe(level: Int, set: Rep[Int], hit: Rep[Int], entry: Rep[Int])

  // One symbolic array read per way, which is the whole budget. The tag stored
  // is the line number itself, so an empty frame's -1 fails the comparison on
  // its own and there is no valid bit to read alongside it.
  private def probe(s: Rep[State], level: Int, line: Rep[Int]): Probe = {
    val g = levels(level)
    val set = line & unit(g.sets - 1)
    val base = unit(geometry.base(level)) + set * unit(g.ways)

    // Accumulated in ordinary Scala vars, which is safe here and nowhere near
    // a virtualized `if`: these are straight-line expressions, so what the var
    // names at the end is the whole chain rather than whichever arm was staged
    // last.
    var hit: Rep[Int] = unit(0)
    var way: Rep[Int] = unit(0)
    for (w <- 0 until g.ways) {
      val m = eqMask(s.cache_tags(base + unit(w)), line)
      hit = hit | m
      way = way | (m & unit(w))
    }
    Probe(level, set, hit, base + way)
  }

  // Exact LRU. Age 0 is the most recent, and everything younger than the entry
  // just touched ages by one, which over [ways] entries keeps the ages a
  // permutation of `0 until ways`. The comparison is the sign bit of a
  // subtraction rather than an `if`, for the reason [eqMask] is.
  private def touch(s: Rep[State], level: Int, set: Rep[Int], entry: Rep[Int]): Rep[Unit] = {
    val g = levels(level)
    val base = unit(geometry.base(level)) + set * unit(g.ways)
    val was = s.cache_age(entry)
    for (w <- 0 until g.ways) {
      val e = base + unit(w)
      val a = s.cache_age(e)
      s.cache_age(e) = a + ((a - was) >>> unit(31))
    }
    s.cache_age(entry) = unit(0)
  }

  // The entry a fill would take: the oldest, and an invalid one ahead of any
  // valid one. An invalid entry is given an age of [ways], which is one past
  // anything a valid entry can hold, so "prefer invalid" needs no test of its
  // own.
  private def victim(s: Rep[State], level: Int, set: Rep[Int]): Rep[Int] = {
    val g = levels(level)
    val base = unit(geometry.base(level)) + set * unit(g.ways)
    // `-1 & ways` is `ways`, so an empty frame reads one older than the oldest
    // live one without a test of its own.
    def age(e: Rep[Int]): Rep[Int] =
      s.cache_age(e) + (eqMask(s.cache_tags(e), unit(-1)) & unit(g.ways))

    var bestWay: Rep[Int] = unit(0)
    var bestAge: Rep[Int] = age(base)
    for (w <- 1 until g.ways) {
      val a = age(base + unit(w))
      val older = (bestAge - a) >> unit(31)
      bestWay = pick(older, unit(w), bestWay)
      bestAge = pick(older, a, bestAge)
    }
    base + bestWay
  }

  private def word(entry: Rep[Int], offset: Rep[Int]): Rep[Int] =
    entry * unit(lineWords) + offset

  private def readEntry(s: Rep[State], entry: Rep[Int]): Vector[Rep[Int]] =
    (0 until lineWords).toVector.map(i => s.cache_vals(word(entry, unit(i))))

  private def writeEntry(s: Rep[State], entry: Rep[Int], ws: Vector[Rep[Int]]): Rep[Unit] = {
    ws.zipWithIndex.foreach((x, i) => s.cache_vals(word(entry, unit(i))) = x)
    unit(())
  }

  private def readMemLine(s: Rep[State], line: Rep[Int]): Vector[Rep[Int]] =
    (0 until lineWords).toVector.map(i => s.mem(line * unit(lineWords) + unit(i)))

  private def writeMemLine(s: Rep[State], line: Rep[Int], ws: Vector[Rep[Int]]): Rep[Unit] = {
    ws.zipWithIndex.foreach((x, i) => s.mem(line * unit(lineWords) + unit(i)) = x)
    unit(())
  }

  // [line] present at [level], and its entry.
  //
  // [ps] is the probe each level was seen in before anything moved. A level
  // whose entry is [None] is probed again here, which is what a second visit to
  // a level in one access needs: the first visit may have installed the line,
  // and a mask read before that would describe the wrong state.
  private def bring(
      s: Rep[State],
      level: Int,
      line: Rep[Int],
      ps: Vector[Option[Probe]]
  ): Rep[Int] = {
    val p = ps(level).getOrElse(probe(s, level, line))
    if (p.hit !== unit(0)) {
      touch(s, level, p.set, p.entry)
      p.entry
    } else {
      val e = victim(s, level, p.set)

      // Only the bottom level is ever dirty, so this is one `if` in one place
      // rather than one per level. See [Geometry.writeBack]: a level that can
      // be dirty is a level whose eviction mutates the one below it, in the
      // middle of an access that has already read that level's tags.
      //
      // Dirty implies live, so there is no emptiness test here either: a frame
      // is only ever dirtied by a store to a line it is holding, and a fill
      // clears the bit before anything can write to that frame again. The tag
      // is the line, so the write-back needs no arithmetic to find its address.
      if (geometry.writeBack(level)) {
        if (s.cache_dirty(e) !== unit(0)) {
          writeMemLine(s, s.cache_tags(e), readEntry(s, e))
        }
      }

      writeEntry(s, e, fill(s, level + 1, line, ps))
      s.cache_tags(e) = line
      s.cache_dirty(e) = unit(0)

      // Oldest first, and only then touched. [touch] ages what is younger than
      // the entry it is given, so handing it one that still reads 0 from a
      // cold start would age nothing and leave two frames tied at 0 with no
      // way to tell which to evict next. In the steady state the victim is
      // already the oldest and this writes what was there.
      s.cache_age(e) = unit(levels(level).ways - 1)
      touch(s, level, p.set, e)
      e
    }
  }

  // A whole line out of [level], which is memory once the hierarchy runs out.
  // Line-granular and not word-granular, which is what real hardware does and
  // is also what keeps a fill from forking once per word.
  private def fill(
      s: Rep[State],
      level: Int,
      line: Rep[Int],
      ps: Vector[Option[Probe]]
  ): Vector[Rep[Int]] =
    if (level == levels.length) { readMemLine(s, line) }
    else { readEntry(s, bring(s, level, line, ps)) }

  // One word, written at [level] and at every level below it. The bottom takes
  // the write and marks the line dirty; everything above takes it and passes
  // it on, which is what [Geometry.writeBack] means by write-through.
  private def store(
      s: Rep[State],
      level: Int,
      line: Rep[Int],
      offset: Rep[Int],
      v: Rep[Int],
      ps: Vector[Option[Probe]]
  ): Rep[Unit] =
    if (level == levels.length) { s.mem(line * unit(lineWords) + offset) = v }
    else {
      val e = bring(s, level, line, ps)
      s.cache_vals(word(e, offset)) = v
      if (geometry.writeBack(level)) { s.cache_dirty(e) = unit(1) }
      // Everything below has been visited already: this level's fill went
      // through all of them. So the write down re-probes rather than trusting
      // a mask that predates its own fill.
      else { store(s, level + 1, line, offset, v, ps.map(_ => None)) }
    }

  // What the access costs, read off the state it arrived in and before any of
  // it moves. Selected arithmetically rather than charged inside the arms, so
  // that the number exists as a [Rep] in its own right: a non-blocking load
  // charges this to whoever waits for the value rather than to the clock, and
  // a cache that had already spent it would have nothing to hand over.
  private def latency(ps: Vector[Probe]): Rep[Int] =
    ps.foldRight(unit(memCost))((p, below) => pick(p.hit, unit(levels(p.level).hitCost), below))

  def runCache(s: Rep[State], addr: Rep[Int], v: Option[Rep[Int]]): Rep[Int] = {
    val offset = addr & unit(lineWords - 1)
    val line = addr >>> unit(lineBits)

    // One probe per level, shared by the latency and by the data path. Both
    // want the state the access arrived in, and a symbolic tag read is the
    // most expensive thing in here: doing it twice was most of the formula.
    val ps = levels.indices.toVector.map(probe(s, _, line))
    val some = ps.map(Some(_))
    v match {
      case Some(x) => {
        spend(s, latency(ps))
        store(s, 0, line, offset, x, some)
        x
      }
      case None => {
        defer(s, latency(ps))
        s.cache_vals(word(bring(s, 0, line, some), offset))
      }
    }
  }

  private def lineBits: Int = geometry.lineBits

  override def get_mem(s: Rep[State], addr: Rep[Int]): Rep[Int] =
    runCache(s, addr, None)

  override def set_mem(s: Rep[State], addr: Rep[Int], v: Rep[Int]): Rep[Unit] = {
    runCache(s, addr, Some(v))
    unit(())
  }
}

// Speculation with no history: not-taken at every branch, and the window
// inlined rather than emitted as functions.
//
// [Static] is what this model became. It reaches the same guess through
// [Predictive]'s window, which costs a slot per lookahead state and buys
// backward branches. This one refuses those, because with the window inlined a
// backward target inside one inlines forever, and that is a fact about the
// generator rather than about any machine.
//
// Kept for the NanoRISC suite, which is here for continuity with an earlier
// version of this work and should go on answering the way it did. Nothing else
// extends it.
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
            //
            // The instruction that closed the window has not run yet, and it
            // runs through [step] rather than [call]: a window is inlined, and
            // [call] would emit a function call where every snapshot in the
            // tree has straight-line code.
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
