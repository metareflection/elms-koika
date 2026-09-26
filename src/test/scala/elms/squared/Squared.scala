package elms.koika.test.squared

import scala.collection.mutable

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
// to keep the bookkeeping outside it. Nothing in [Flat] or [Cached] has any;
// [Speculative.saveForRollback] is the one place in the tower that does, and
// it is worth reading before adding a second.
trait Squared extends Machine {
  // Both runs at once: a pointer at a pair of states when this stages, and an
  // ordinary pair when it runs.
  type Pair

  // One ISA, so there is no [Isa] to abstract over. An abstraction with one
  // instance abstracts nothing.
  val prog: Vector[RiscV.Instr]

  def half(s: Pair, i: Int): Half

  private var side: Int = -1

  private var walking: Vector[Int] = Vector(0, 1)

  // Which runs are still being walked. Both, and it stays both for every model
  // in the tower as it ships. A conditional fuses, so the pair either goes one
  // way together or leaves the search, and [DynamicSquared] is the experiment
  // in letting it come apart instead.
  protected def active: Vector[Int] = walking

  // [body], with [i] the only run still being walked. Scoped rather than a
  // setter, because a model that forgot to put this back would go on emitting
  // half-width slots for a pair that is still whole.
  protected def solo[A](i: Int)(body: => A): A = {
    val outer = walking
    walking = Vector(i)
    try { body } finally { walking = outer }
  }

  // Which run [each] is evaluating its body for, which a model needs when the
  // state it keeps between instructions holds a value one run computed.
  // [Forwarding]'s queue is the only such state in the tower.
  //
  // Meaningful only inside an [each] body, and it says so rather than
  // answering 0 outside one. A wrong answer here is a residue that reads a
  // symbol belonging to the other run, which is not a thing a checker would
  // report.
  protected def running: Int = {
    require(side >= 0, "the running side was read outside [each]")
    side
  }

  // Evaluate [body] in each run's own machine. Half the squared semantics, and
  // the half that covers everything that is not control flow.
  //
  // One run left is the case that keeps everything below this trait written
  // for a pair. The body runs once and the result is paired with itself, so
  // `sameClock(Sided(t, t))` asserts `t == t` and the slicer drops it, and
  // `agree(Sided(c, c))` has nothing to compare and falls through to an
  // ordinary [choose], which is what a branch in a single-run walk should be.
  // No model underneath needs a solo case of its own.
  final def each[A](s: Pair)(body: Half => A): Sided[A] = {
    val outer = side
    try {
      active match {
        case Vector(i) => {
          side = i
          val x = body(half(s, i))
          Sided(x, x)
        }
        case _ => {
          side = 0
          val a = body(half(s, 0))
          side = 1
          val b = body(half(s, 1))
          Sided(a, b)
        }
      }
    } finally { side = outer }
  }

  // The clocks agree on the way into a slot. The leak, if there is one.
  def sameClock(x: Sided[Rep[Int]]): Unit

  // The two runs are about to go the same way. A precondition rather than a
  // question: fusing the branch is only sound while it holds.
  def sameWay(x: Sided[Rep[Boolean]]): Unit

  // One arm, taken once, for both runs.
  protected def choose(c: Rep[Boolean])(t: => Pair)(e: => Pair): Pair

  // The other half of the squared semantics. [c] came out of [each], so it is
  // one condition per run, and this is where they are made into one.
  //
  // With one run left there is nothing to make into one, and the two sides of
  // [c] are the same value, so this is an ordinary conditional.
  final def agree(c: Sided[Rep[Boolean]])(t: => Pair)(e: => Pair): Pair =
    if (active.length < 2) { choose(c.a)(t)(e) } else { fuseOrSplit(c)(t)(e) }

  // What a conditional does while both runs are still being walked. Fusing
  // them is the static squared construction, which is the behaviour of every
  // model that ships, and [DynamicSquared] is the only thing that overrides
  // it.
  protected def fuseOrSplit(c: Sided[Rep[Boolean]])(t: => Pair)(e: => Pair): Pair = {
    sameWay(c)
    choose(c.a)(t)(e)
  }

  // Whether slot [at] is a function worth emitting. [at] is a slot number and
  // not a pc; the two agree until a walk splits or [Predictive] numbers one pc
  // into several, and a caller that means "does the program go this far" wants
  // `pc < prog.length` instead.
  def live(at: Int): Boolean = pcOf(at) < prog.length

  // Solo slots, in the order they were first asked for. Both runs walking is
  // the overwhelmingly common case and gets no table at all, so this is empty
  // for every model in the tower as it ships.
  private val solos = mutable.ArrayBuffer[(Int, Int)]()
  private val soloSlots = mutable.Map[(Int, Int), Int]()

  // One emitted function per slot, and a slot is a pc together with the runs
  // walking it. [Predictive] needs a third and a fourth component and hands
  // out its own numbering.
  //
  // A pair keeps the pc as its own slot number, which is what makes this
  // invisible to everything that never splits. The same functions come out
  // under the same names they had before [DynamicSquared] existed. A solo walk
  // is numbered past the end of the program, because the function it emits is
  // a different function, half the width and with no comparison left in it.
  def slot(pc: Int): Int = active match {
    case Vector(i) =>
      soloBase + soloSlots.getOrElseUpdate((pc, i), { solos += ((pc, i)); solos.length - 1 })
    case _ => pc
  }

  // One past the last number a pair can take. [call] asks for `prog.length`
  // whenever the program runs off the end, so the pc's own range is closed at
  // both ends and a solo slot starts above it.
  private def soloBase: Int = prog.length + 1

  // [slot] read backwards. Private because the two callers are both here and
  // [Predictive] overrides them off its own table rather than inverting this.
  private def pcOf(at: Int): Int =
    if (at < soloBase) { at } else { solos(at - soloBase)._1 }

  // Whether the next [call] really leaves, which is [Common.useCache] under a
  // name that does not collide with [Cached]. Nothing in this tower says no
  // yet: [Predictive] emits a window as functions rather than inlining one.
  // The seam is here because the rule [enter] states depends on it, and a
  // model that starts inlining without it would start asserting inside a
  // window without anyone noticing.
  def inlined: Boolean = false

  // Staging-time state a slot carries that the worklist will not, and how to
  // put it back. Which runs are walking is the one piece every model has,
  // because [enter] compares the clocks before [resume] has decoded anything.
  // [Predictive] interns the rest of its own into the slot number.
  def checkpoint(): () => Unit = {
    val was = walking
    () => { walking = was }
  }

  // Register traffic that is the tower's rather than the program's: copying a
  // register somewhere a rollback can find it, and reading a branch's operands
  // where the answer is wanted rather than where it was asked for. Nothing,
  // for a model that times none of them.
  def untimed[A](body: => A): A = body

  // A squash, after the penalty has been charged. What this must not undo is
  // the cache, which is the channel every model that speculates exists to
  // expose.
  def squash(s: Pair): Unit = ()

  // A slot's body. The clocks are compared here and nowhere else, because a
  // slot boundary is the only place the two runs have provably done the same
  // amount of work. Inside an inlined window they have not: one run can be
  // mid-miss while the other is not, and a comparison there would report a
  // drift that the rest of the window was going to close.
  final def enter(at: Int, s: Pair): Pair = {
    sameClock(each(s)(_.timer))
    resume(at, s)
  }

  // Where a model takes an instruction over. [step] is the ISA's and stays
  // that way.
  def resume(at: Int, s: Pair): Pair = step(pcOf(at), s)

  // Non-speculative semantics for one instruction, over both runs.
  def step(pc: Int, s: Pair): Pair

  final def call(i: Int, s: Pair): Pair = {
    require(i >= 0, s"jump to negative pc $i")
    val at = slot(i)
    if (inlined) { resume(at, s) }
    else if (live(at)) { transfer(at, s) }
    else { s }
  }

  // Control really leaving for [at]: an emitted function call when this
  // stages and an ordinary one when it runs, and either way the one thing the
  // two runs share. That sharing is what makes the clocks comparable on the
  // way in.
  protected def transfer(at: Int, s: Pair): Pair

  // What the model still owes when the program runs out of instructions.
  // Nothing, for every model that has already spent every cycle it charged.
  def finish(s: Pair): Pair = s

  // Where a pair of runs enters the program. This is also what
  // `SnippetDriver.snippet` wants when the interpreter stages, which is why it
  // takes and returns the same type the emitted `snippet` does.
  def snippet(s: Pair): Pair = finish(call(0, s))
}
