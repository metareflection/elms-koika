package elms.koika.test.squared

import elms.prelude.given

import elms.koika.test.riscv.RiscV

// One value per run.
final case class Sided[A](a: A, b: A)

// Two runs of one program, in step.
//
// The squared semantics of a language evaluates every expression in both
// states and lets control flow go one way only. That is the whole of this
// trait: [each] is the first half and [agree] is the second, and everything
// underneath in [Machine] is written for a single run because a single run is
// all it ever sees.
//
// Two obligations come out of that, and they are not the same obligation. The
// clocks are compared on the way into every slot, which is the question the
// whole project is asking. The branch conditions are compared at every
// conditional, which is not a question but a precondition: two runs at
// different program counters have no shared control flow left to share, and
// nothing downstream would notice.
//
// Both comparisons are also assumptions when this stages. A pair that has
// already drifted leaves the search instead of being enumerated and rejected,
// which is the only thing this arrangement can buy over running the residue
// twice and comparing at the end.
//
// The precondition that is easy to lose: the two runs' addresses have to be
// provably equal for an assumption to be worth anything. Anything reached
// through `mem` at an index nobody knows is a word nothing can prove the two
// runs agree on, and `branchy.s` keeps its indices in registers for exactly
// this reason.
//
// [each] runs its body once per side, so a model that carries staging-time
// state between instructions in a Scala `var` sees two visits per rule and has
// to snapshot it. Nothing in [Flat] or [Cached] does. Whoever adds speculation
// here is who that sentence is for.
trait Squared extends Machine {
  // Both runs at once: a pointer at a pair of states when this stages, and an
  // ordinary pair when it runs.
  type Pair

  // One ISA, so there is no [Isa] to abstract over. An abstraction with one
  // instance abstracts nothing.
  val prog: Vector[RiscV.Instr]

  def half(s: Pair, i: Int): Half

  // Evaluate [body] in each run's own machine. Half the squared semantics, and
  // the half that covers everything that is not control flow.
  final def each[A](s: Pair)(body: Half => A): Sided[A] =
    Sided(body(half(s, 0)), body(half(s, 1)))

  // The clocks agree on the way into a slot. The leak, if there is one.
  def sameClock(x: Sided[Rep[Int]]): Unit

  // The two runs are about to go the same way. A precondition rather than a
  // question: fusing the branch is only sound while it holds.
  def sameWay(x: Sided[Rep[Boolean]]): Unit

  // One arm, taken once, for both runs.
  protected def choose(c: Rep[Boolean])(t: => Pair)(e: => Pair): Pair

  // The other half of the squared semantics. [c] came out of [each], so it is
  // one condition per run, and this is where they are made into one.
  final def agree(c: Sided[Rep[Boolean]])(t: => Pair)(e: => Pair): Pair = {
    sameWay(c)
    choose(c.a)(t)(e)
  }

  final def live(at: Int): Boolean = at < prog.length

  // A slot's body: the clocks compared on the way in, then the instruction.
  final def resume(at: Int, s: Pair): Pair = {
    sameClock(each(s)(_.timer))
    step(at, s)
  }

  // Non-speculative semantics for one instruction, over both runs.
  def step(pc: Int, s: Pair): Pair

  // Hand control to slot [i]. A slot is an emitted C function when this
  // stages and an ordinary call when it runs, and either way it is the one
  // thing the two runs share. That sharing is what makes the clocks
  // comparable on the way in.
  def call(i: Int, s: Pair): Pair

  // Where a pair of runs enters the program. This is also what
  // `SnippetDriver.snippet` wants when the interpreter stages, which is why it
  // takes and returns the same type the emitted `snippet` does.
  def snippet(s: Pair): Pair = call(0, s)
}
