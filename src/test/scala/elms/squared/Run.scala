package elms.koika.test.squared

import elms.prelude.given
import elms.core.poly.eval.Interp

import elms.koika.test.common.Geometry
import elms.koika.test.riscv.RiscV

// One run's machine, as ordinary Scala. The field names are
// [elms.koika.test.common.StateT]'s, minus the two fields only speculation
// and non-blocking loads ever read.
final case class Chip(
    regs: Array[Int],
    mem: Array[Int],
    saved_regs: Array[Int],
    cache_tags: Array[Int],
    cache_dirty: Array[Int],
    cache_age: Array[Int],
    cache_vals: Array[Int],
    var timer: Int
)

object Chip {
  // What [elms.koika.test.common.Init] emits as C, in Scala. Every frame
  // starts empty, and -1 is what says so: a line number no address can name,
  // so the tag comparison never matches one.
  def blank(numRegs: Int, memSize: Int, g: Geometry): Chip = Chip(
    regs = new Array[Int](numRegs),
    mem = new Array[Int](memSize),
    saved_regs = new Array[Int](numRegs),
    cache_tags = Array.fill(g.entries)(-1),
    cache_dirty = new Array[Int](g.entries),
    cache_age = new Array[Int](g.entries),
    cache_vals = new Array[Int](g.words),
    timer = 0
  )
}

// What a pair of runs came to.
enum Outcome derives CanEqual {
  // The clocks agreed the whole way, and this is what they read.
  case InStep(cycles: Int)

  // The clocks differed. The leak, and the question the whole project asks.
  case Drifted(at: Int)

  // The two runs wanted different program counters. Not a leak so much as the
  // end of the question, since nothing downstream of it is comparable.
  case Diverged(at: Int)
}

// The squared interpreter, run rather than staged.
//
// Every rule in [Exec], [Flat] and [Cached] is the same text that emits the
// residue; what differs is that `Rep` here is an ordinary value, so the
// interpreter walks the program instead of writing one down. An assumption is
// the end of a pair for a checker, so it is the end of the run here too: the
// first mismatch stops and says where.
//
// This is what the AST pass it replaces could never be. A product semantics
// you can run answers in milliseconds and needs no checker, which makes it the
// cheapest place to be wrong.
abstract class Run(val prog: Vector[RiscV.Instr]) extends Exec with Interp {
  type Half = Rep[Chip]
  type Pair = (Chip, Chip)

  def numRegs: Int = 32
  def memSize: Int = 64

  // Which slot is being interpreted. Only ever read to say where a mismatch
  // happened.
  private var at: Int = 0

  private case class Stop(outcome: Outcome)
      extends RuntimeException(null, null, false, false)

  extension (h: Half) {
    def regs: Rep[Array[Int]] = Rep(h.v.regs)
    def mem: Rep[Array[Int]] = Rep(h.v.mem)
    def saved_regs: Rep[Array[Int]] = Rep(h.v.saved_regs)
    def cache_tags: Rep[Array[Int]] = Rep(h.v.cache_tags)
    def cache_dirty: Rep[Array[Int]] = Rep(h.v.cache_dirty)
    def cache_age: Rep[Array[Int]] = Rep(h.v.cache_age)
    def cache_vals: Rep[Array[Int]] = Rep(h.v.cache_vals)
    def timer: Rep[Int] = Rep(h.v.timer)
    def timer_=(v: Rep[Int]): Rep[Unit] = { h.v.timer = v.v; Rep(()) }
  }

  override def half(s: Pair, i: Int): Half = Rep(if (i == 0) { s._1 } else { s._2 })

  override def sameClock(x: Sided[Rep[Int]]): Unit =
    if (x.a.v != x.b.v) { throw Stop(Outcome.Drifted(at)) }

  override def sameWay(x: Sided[Rep[Boolean]]): Unit =
    if (x.a.v != x.b.v) { throw Stop(Outcome.Diverged(at)) }

  override protected def choose(c: Rep[Boolean])(t: => Pair)(e: => Pair): Pair =
    if (c.v) { t } else { e }

  override protected def transfer(to: Int, s: Pair): Pair = {
    at = to
    enter(to, s)
  }

  // [a] and [b] are mutated in place, so a caller wanting to inspect them
  // afterwards already holds them.
  def apply(a: Chip, b: Chip): Outcome =
    try {
      val (x, y) = snippet((a, b))
      // [enter] compares on the way into a slot, so the last instruction's
      // cost has not been looked at yet. The residue's `main` ends with the
      // same comparison for the same reason.
      if (x.timer != y.timer) { Outcome.Drifted(at) } else { Outcome.InStep(x.timer) }
    } catch { case Stop(o) => o }

  def blank: Chip = Chip.blank(numRegs, memSize, shape)

  // How long the cache arrays are. [Flat] has no cache to describe, and it
  // still gets them: `struct StateT` is one shape whatever the model, and a
  // model that never probes leaves them at zero.
  protected def shape: Geometry = Geometry.default
}

final class FlatRun(prog: Vector[RiscV.Instr]) extends Run(prog) with Flat

final class CachedRun(prog: Vector[RiscV.Instr], val geometry: Geometry = Geometry.default)
    extends Run(prog)
    with Cached {
  override protected def shape: Geometry = geometry
}

// [Predictive]'s interning table is a staging-time index into emitted
// functions when this tower emits, and it is a walk's own bookkeeping when it
// runs: one concrete run takes one path through the lookahead, so a key it
// mints is a key it visits. Which means a [Run] is good for one pair of chips
// and the suites below build a fresh one per sample.
final class StaticRun(prog: Vector[RiscV.Instr], val geometry: Geometry = Geometry.default)
    extends Run(prog)
    with Static {
  override protected def shape: Geometry = geometry
}

final class PredictiveRun(prog: Vector[RiscV.Instr], val geometry: Geometry = Geometry.default)
    extends Run(prog)
    with Predictive {
  override protected def shape: Geometry = geometry
}

final class ForwardingRun(prog: Vector[RiscV.Instr], val geometry: Geometry = Geometry.default)
    extends Run(prog)
    with Forwarding {
  override protected def shape: Geometry = geometry
}
