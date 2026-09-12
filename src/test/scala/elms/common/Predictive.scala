package elms.koika.test.common

import scala.collection.mutable

import elms.prelude.*
import elms.prelude.given

// Speculation driven by a predictor that lives at runtime instead of at
// staging time.
//
// [Speculative] guesses not-taken everywhere and knows that at staging time,
// so its window is a static object and it turns memoization off to inline one.
// Here the guess is a [Rep], both continuations get staged, and a pc becomes
// reachable under more than one window. Memoization stays on and keys on the
// window as well as the pc, which is why a backward target is emitted once
// rather than inlined forever: [Speculative]'s forwards-only guard buys nothing
// here and is gone.
@virtualize
trait Predictive extends Cached {
  // A branch that has been guessed at and not yet resolved. [at] is both the
  // branch's pc and its index into the predictor, and [recovery] is where
  // control belongs if [guess] was wrong.
  case class Pending(at: Int, cond: Cond, recovery: Int, guess: Boolean)

  // [saved] is in the order [resolve] replays it, which is why it is a [Vector]
  // and not a set. Set equality ignores that order, and two windows whose
  // rollbacks write the registers in different orders are different code.
  case class Window(pending: Pending, saved: Vector[Reg])

  // Everything the generated function for a pc depends on beyond the [Rep]
  // state. No conditional branch is [speculable], so a window can never open
  // inside another one and this is an [Option] rather than a stack.
  case class Key(pc: Int, window: Option[Window])

  private val interned = mutable.ArrayBuffer[Key]()
  private val numbered = mutable.Map[Key, Int]()

  private def intern(k: Key): Int =
    numbered.getOrElseUpdate(k, { interned += k; interned.length - 1 })

  // [Isa.step] recurses through `call(pc + 1, s)` with a bare pc, so the rest
  // of the lookahead has to be ambient rather than threaded.
  private var window: Option[Window] = None

  // Staging one arm of a virtualized `if` runs [call]s that leave [window]
  // wherever they finished, so each arm is staged under the lookahead it
  // belongs to rather than under whatever the arm before it left behind.
  private def under[A](w: Option[Window])(body: => A): A = {
    val outer = window
    window = w
    try { body }
    finally { window = outer }
  }

  private def goto(w: Option[Window], pc: Int, s: Rep[StateT]): Rep[StateT] =
    under(w) { call(pc, s) }

  override def slot(pc: Int): Int = intern(Key(pc, window))

  override def live(at: Int): Boolean = interned(at) match {
    // Running off the end of [prog] with a branch still in flight is a real
    // slot: something has to resolve it.
    case Key(pc, w) => pc < prog.length || w.isDefined
  }

  override def resume(at: Int, s: Rep[StateT]): Rep[StateT] = interned(at) match {
    case Key(pc, w) => under(w) { run(pc, w, s) }
  }

  private def opening(at: Int, cond: Cond, recovery: Int, guess: Boolean): Option[Window] =
    Some(Window(Pending(at, cond, recovery, guess), Vector()))

  private def run(pc: Int, w: Option[Window], s: Rep[StateT]): Rep[StateT] = w match {
    // [live] has already ruled out `pc == prog.length` on this arm.
    case None => branch(pc, prog(pc)) match {
        case Some((cnd, tgt)) => {
          // A branch is an instruction. [Speculative] charges nothing for one,
          // which is an artifact of it skipping [step] to open a window.
          tick(s)
          // Neither arm may be an assignment to a Scala `var` holding a [Rep]:
          // the arm staged last would win the name and the emitted C would
          // return a symbol declared inside the other block.
          if (predict(s, pc)) { goto(opening(pc, cnd, recovery = pc + 1, guess = true), tgt, s) }
          else { goto(opening(pc, cnd, recovery = tgt, guess = false), pc + 1, s) }
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
            under(Some(Window(p, saved :+ rd))) { step(pc, s) }
          }
        case None => resolve(pc, p, saved, s)
      }
  }

  val mispredictPenalty: Int = 15

  // Reached exactly once per dynamic branch. A window advances only by
  // `pc + 1`, since [speculable] admits no control flow, so its walk is a
  // straight line that ends here or at [prog]'s end.
  private def resolve(pc: Int, p: Pending, saved: Vector[Reg], s: Rep[StateT]): Rep[StateT] = {
    val taken = evalCond(s, p.cond)
    train(s, p.at, taken)
    if (taken) { settle(pc, p, saved, taken = true, s) }
    else { settle(pc, p, saved, taken = false, s) }
  }

  // [taken] is static in here, so the emitted C tests the condition once rather
  // than comparing it against a stored guess.
  private def settle(
      pc: Int,
      p: Pending,
      saved: Vector[Reg],
      taken: Boolean,
      s: Rep[StateT]
  ): Rep[StateT] =
    // [pc] has not run yet, whether or not the guess held.
    if (taken == p.guess) { goto(None, pc, s) }
    else {
      s.timer += mispredictPenalty
      for (rd <- saved) { set_reg(s, regIndex(rd), s.saved_regs(regIndex(rd))) }
      // Cache effects are deliberately not undone. They are the channel the
      // whole model exists to expose.
      goto(None, p.recovery, s)
    }

  // One entry per conditional branch, so no two of them alias. A real BHT
  // indexes low pc bits and does alias, which only ever adds channels; keeping
  // them apart is what makes a leak in a snapshot attributable to the program.
  lazy val bhtIndex: Map[Int, Int] =
    prog.indices.filter(pc => branch(pc, prog(pc)).isDefined).zipWithIndex.toMap

  lazy val bhtSize: Int = bhtIndex.size.max(1)

  // One bit of history, the last outcome. The index is static, so the generated
  // C subscripts a constant and never computes one. A two-bit saturating
  // counter is these two methods over the same array and nothing else.
  def predict(s: Rep[StateT], pc: Int): Rep[Boolean] = s.bht(bhtIndex(pc)) !== unit(0)

  def train(s: Rep[StateT], pc: Int, taken: Rep[Boolean]): Rep[Unit] =
    s.bht(bhtIndex(pc)) = if (taken) { unit(1) } else { unit(0) }
}
