package elms.koika.test.common

import scala.collection.mutable

import elms.prelude.*
import elms.prelude.given

// Speculation driven by a predictor with history rather than by a fixed guess.
//
// [Speculative] guesses not-taken everywhere, which is a constant, so its
// window is a static object and it turns memoization off to inline one. Here it
// depends on what the branch did last, so a pc becomes reachable under more
// than one window and under more than one thing the predictor believes.
// Memoization stays on and keys on all three, which is why a backward target is
// emitted once rather than inlined forever: [Speculative]'s forwards-only guard
// buys nothing here and is gone.
//
// The predictor's history is staging-time rather than a field of [State], and
// that is the whole performance story. A [Rep] guess would force both
// continuations of every branch to be staged, and the residue's branching call
// sites are what a bounded checker's cost is exponential in. Specializing on
// the history instead stages one continuation per branch and pays for it in
// distinct functions, which is the cheaper axis. The cost is that nothing in
// the generated C is the predictor any more; it is which function you are in.
@virtualize
trait Predictive extends Cached {
  // A branch that has been guessed at and not yet resolved. [at] is its pc,
  // which is also what [Key.learned] keys it by, and [recovery] is where control
  // belongs if [guess] was wrong.
  case class Pending(at: Int, cond: Cond, recovery: Int, guess: Boolean)

  // [saved] is in the order [resolve] replays it, which is why it is a [Vector]
  // and not a set. Set equality ignores that order, and two windows whose
  // rollbacks write the registers in different orders are different code.
  case class Window(pending: Pending, saved: Vector[Reg])

  // Everything the generated function for a pc depends on beyond the [Rep]
  // state. No conditional branch is [speculable], so a window can never open
  // inside another one and that is an [Option] rather than a stack.
  //
  // [learned] is keyed by branch pc and holds each branch's last outcome. A
  // branch missing from it has not run yet and predicts not-taken, which is the
  // cold start [Speculative] hardcodes for every branch forever.
  case class Key(pc: Int, window: Option[Window], learned: Map[Int, Boolean])

  private val interned = mutable.ArrayBuffer[Key]()
  private val numbered = mutable.Map[Key, Int]()

  private def intern(k: Key): Int =
    numbered.getOrElseUpdate(k, { interned += k; interned.length - 1 })

  // [Isa.step] recurses through `call(pc + 1, s)` with a bare pc, so the rest
  // of the lookahead has to be ambient rather than threaded.
  private var window: Option[Window] = None
  private var learned: Map[Int, Boolean] = Map()

  // Staging one arm of a virtualized `if` runs [call]s that leave the ambient
  // state wherever they finished, so each arm is staged under the lookahead it
  // belongs to rather than under whatever the arm before it left behind.
  private def under[A](w: Option[Window], l: Map[Int, Boolean])(body: => A): A = {
    val (outerWindow, outerLearned) = (window, learned)
    window = w
    learned = l
    try { body }
    finally { window = outerWindow; learned = outerLearned }
  }

  private def goto(
      w: Option[Window],
      l: Map[Int, Boolean],
      pc: Int,
      s: Rep[State]
  ): Rep[State] = under(w, l) { call(pc, s) }

  override def slot(pc: Int): Int = intern(Key(pc, window, learned))

  override def live(at: Int): Boolean = interned(at) match {
    // Running off the end of [prog] with a branch still in flight is a real
    // slot: something has to resolve it.
    case Key(pc, w, _) => pc < prog.length || w.isDefined
  }

  override def resume(at: Int, s: Rep[State]): Rep[State] = interned(at) match {
    case Key(pc, w, l) => under(w, l) { run(pc, w, s) }
  }

  private def opening(at: Int, cond: Cond, recovery: Int, guess: Boolean): Option[Window] =
    Some(Window(Pending(at, cond, recovery, guess), Vector()))

  private def run(pc: Int, w: Option[Window], s: Rep[State]): Rep[State] = w match {
    // [live] has already ruled out `pc == prog.length` on this arm.
    case None => branch(pc, prog(pc)) match {
        case Some((cnd, tgt)) => {
          // A branch is an instruction. [Speculative] charges nothing for one,
          // which is an artifact of it skipping [step] to open a window.
          tick(s)
          // Static, so only the guessed continuation is staged. The other one
          // is reached by whichever key holds the opposite history.
          if (predict(pc)) {
            goto(opening(pc, cnd, recovery = pc + 1, guess = true), learned, tgt, s)
          } else {
            goto(opening(pc, cnd, recovery = tgt, guess = false), learned, pc + 1, s)
          }
        }
        case None => step(pc, s)
      }
    case Some(Window(p, saved)) =>
      // Off the end of [prog], or an instruction that cannot run speculatively,
      // or one that would clobber an input to the condition still waiting to be
      // evaluated. [evalCond] runs against the live register file at resolution
      // rather than at the branch, which is what makes that last case matter.
      prog.lift(pc).flatMap(speculable).filter(rd => !reads(p.cond).contains(rd)) match {
        case Some(rd) =>
          if (saved.contains(rd)) { step(pc, s) }
          else {
            s.saved_regs(regIndex(rd)) = get_reg(s, regIndex(rd))
            under(Some(Window(p, saved :+ rd)), learned) { step(pc, s) }
          }
        case None => resolve(pc, p, saved, s)
      }
  }

  val mispredictPenalty: Int = 15

  // Reached exactly once per dynamic branch. A window advances only by
  // `pc + 1`, since [speculable] admits no control flow, so its walk is a
  // straight line that ends here or at [prog]'s end.
  private def resolve(pc: Int, p: Pending, saved: Vector[Reg], s: Rep[State]): Rep[State] = {
    val taken = evalCond(s, p.cond)
    if (taken) { settle(pc, p, saved, taken = true, s) }
    else { settle(pc, p, saved, taken = false, s) }
  }

  // [taken] is static in here, so whether the guess held is settled while
  // staging. The emitted C tests the condition and nothing else.
  private def settle(
      pc: Int,
      p: Pending,
      saved: Vector[Reg],
      taken: Boolean,
      s: Rep[State]
  ): Rep[State] = {
    // The branch is what the predictor learns from, and it learns the truth
    // rather than the guess.
    val next = learned.updated(p.at, taken)
    // [pc] has not run yet, whether or not the guess held.
    if (taken == p.guess) { goto(None, next, pc, s) }
    else {
      s.timer += mispredictPenalty
      for (rd <- saved) { set_reg(s, regIndex(rd), s.saved_regs(regIndex(rd))) }
      // Cache effects are deliberately not undone. They are the channel the
      // whole model exists to expose.
      goto(None, next, p.recovery, s)
    }
  }

  // One bit of history per branch, its last outcome, and no aliasing between
  // branches. A real BHT indexes low pc bits and does alias, which only ever
  // adds channels; keeping them apart is what makes a leak in a snapshot
  // attributable to the program. A two-bit saturating counter is this method
  // and [Key.learned]'s value type, and nothing else.
  def predict(pc: Int): Boolean = learned.getOrElse(pc, false)
}
