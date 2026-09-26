package elms.koika.test.squared

import scala.collection.mutable

import elms.prelude.given

import elms.koika.test.riscv.RiscV.Reg

// Speculation driven by a predictor with history, over a pair of runs.
//
// The model is [elms.koika.test.common.Predictive]'s and that file is where
// the argument for it lives: the history is staging-time rather than a field
// of the state, so a pc becomes several emitted functions rather than the
// residue growing a branch per guess. Nothing in the generated C is the
// predictor; it is which function you are in.
//
// Two things here are the squared semantics rather than the model.
//
// Which way a branch actually went is compared, at the point the model asks
// rather than left to the clock downstream. A pair that resolves it two ways
// is running two different programs from there on, and a timer that happens
// to agree afterwards would say nothing about that.
//
// Everything else is not. A window is emitted as functions rather than
// inlined, so every instruction in one is its own slot and the clocks get
// compared on the way into each, exactly as they do outside a window. That is
// what makes this model easier to square than an inlining one: there is no
// stretch of straight-line code where the two runs are mid-flight and not yet
// comparable.
//
// The saved registers travel in [Window] as a [Vector] rather than in a
// mutable set, so none of the bookkeeping has to be hoisted out of [each].
trait Predictive extends Cached with Exec {
  // A branch that has been guessed at and not yet resolved. [at] is its pc,
  // which is also what [Key.learned] keys it by, and [recovery] is where
  // control belongs if [guess] was wrong.
  case class Pending(at: Int, cond: Cond, recovery: Int, guess: Boolean)

  // [saved] is in the order [rollback] replays it, which is why it is a
  // [Vector] and not a set. Set equality ignores that order, and two windows
  // whose rollbacks write the registers in different orders are different
  // code.
  case class Window(pending: Pending, saved: Vector[Reg])

  // Everything the generated function for a pc depends on beyond the state.
  // No conditional branch is [speculable], so a window can never open inside
  // another one and that is an [Option] rather than a stack.
  //
  // [active] is the whole of [Squared.slot]'s key and it is one of these for
  // the same reason. A lookahead walked by one run emits a different function
  // from the same lookahead walked by a pair.
  case class Key(pc: Int, active: Vector[Int], window: Option[Window], learned: Map[Int, Boolean])

  private val interned = mutable.ArrayBuffer[Key]()
  private val numbered = mutable.Map[Key, Int]()

  private def intern(k: Key): Int =
    numbered.getOrElseUpdate(k, { interned += k; interned.length - 1 })

  // [step] recurses through `call(pc + 1, s)` with a bare pc, so the rest of
  // the lookahead has to be ambient rather than threaded.
  private var window: Option[Window] = None
  private var learned: Map[Int, Boolean] = Map()

  // Staging one arm of an [agree] runs [call]s that leave the ambient state
  // wherever they finished, so each arm is staged under the lookahead it
  // belongs to rather than under whatever the arm before it left behind.
  private def under[A](w: Option[Window], l: Map[Int, Boolean])(body: => A): A = {
    val (outerWindow, outerLearned) = (window, learned)
    window = w
    learned = l
    try { body }
    finally { window = outerWindow; learned = outerLearned }
  }

  private def goto(w: Option[Window], l: Map[Int, Boolean], pc: Int, s: Pair): Pair =
    under(w, l) { call(pc, s) }

  override def slot(pc: Int): Int = intern(Key(pc, active, window, learned))

  override def live(at: Int): Boolean = interned(at) match {
    // Running off the end of [prog] with a branch still in flight is a real
    // slot: something has to resolve it.
    case Key(pc, _, w, _) => pc < prog.length || w.isDefined
  }

  override def resume(at: Int, s: Pair): Pair = interned(at) match {
    case Key(pc, _, w, l) => under(w, l) { run(pc, w, s) }
  }

  private def opening(at: Int, cond: Cond, recovery: Int, guess: Boolean): Option[Window] =
    Some(Window(Pending(at, cond, recovery, guess), Vector()))

  // Where a subclass gets at an instruction, [Squared.resume] being where this
  // model takes it over. [w] is handed over rather than read back out of the
  // ambient, so that an override can dispatch on it.
  protected def run(pc: Int, w: Option[Window], s: Pair): Pair = w match {
    // [live] has already ruled out `pc == prog.length` on this arm.
    case None => branch(pc, prog(pc)) match {
        case Some((cnd, tgt)) => {
          // A branch is an instruction, and opening a window does not excuse
          // it from the clock the way skipping [step] would.
          each(s)(tick)
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
      // Off the end of [prog], or an instruction that cannot run
      // speculatively, or one that would clobber an input to the condition
      // still waiting to be evaluated. [evalCond] runs against the live
      // register file at resolution rather than at the branch, which is what
      // makes that last case matter.
      prog.lift(pc).flatMap(speculable).filter(rd => !reads(p.cond).contains(rd)) match {
        case Some(rd) => under(Some(Window(p, save(s, saved, rd))), learned) { step(pc, s) }
        case None     => resolve(pc, p, saved, s)
      }
  }

  val mispredictPenalty: Int = 15

  // Reached exactly once per dynamic branch. A window advances only by
  // `pc + 1`, since [speculable] admits no control flow, so its walk is a
  // straight line that ends here or at [prog]'s end.
  //
  // This is the one [agree] the model owns, and the branch is asked about
  // here rather than where it was guessed at. The two runs have to answer it
  // the same way or there is nothing left to compare.
  private def resolve(pc: Int, p: Pending, saved: Vector[Reg], s: Pair): Pair = {
    // The branch ticked where it was staged, several instructions back. This
    // is that same read moved to where the answer is wanted, and [run]
    // excludes [reads] from the window so that it is the same read.
    val taken = each(s)(h => untimed { evalCond(h, p.cond) })
    agree(taken) {
      settle(pc, p, saved, taken = true, s)
    } {
      settle(pc, p, saved, taken = false, s)
    }
  }

  // [taken] is static in here, so whether the guess held is settled while
  // staging. The emitted C tests the condition and nothing else.
  private def settle(
      pc: Int,
      p: Pending,
      saved: Vector[Reg],
      taken: Boolean,
      s: Pair
  ): Pair = {
    // The branch is what the predictor learns from, and it learns the truth
    // rather than the guess.
    val next = learn(p.at, taken)
    // [pc] has not run yet, whether or not the guess held.
    if (taken == p.guess) { goto(None, next, pc, s) }
    else {
      rollback(s, saved)
      goto(None, next, p.recovery, s)
    }
  }

  // [rd]'s value on the way into the window, recorded once. Saving it a
  // second time would overwrite the architectural value with a speculative
  // one, and the rollback would then put the wrong number back.
  //
  // Which registers are saved is one staging-time fact and the [Vector] that
  // holds it is threaded rather than mutated, so the guard can sit outside
  // [each] without either run seeing the other's bookkeeping.
  protected def save(s: Pair, saved: Vector[Reg], rd: Reg): Vector[Reg] =
    if (saved.contains(rd)) { saved }
    else {
      each(s)(h => h.saved_regs(unit(rd.i)) = untimed { get_reg(h, unit(rd.i)) })
      saved :+ rd
    }

  // Throw a window away, at the price of one. Cache effects are deliberately
  // not undone: they are the channel the whole model exists to expose.
  protected def rollback(s: Pair, saved: Vector[Reg]): Unit = {
    each(s) { h =>
      h.timer = h.timer + unit(mispredictPenalty)
      untimed { for (rd <- saved) { set_reg(h, unit(rd.i), h.saved_regs(unit(rd.i))) } }
    }
    squash(s)
  }

  // One bit of history per branch, its last outcome, and no aliasing between
  // branches. A real BHT indexes low pc bits and does alias, which only ever
  // adds channels; keeping them apart is what makes a leak in a snapshot
  // attributable to the program.
  def predict(pc: Int): Boolean = learned.getOrElse(pc, false)

  // What the predictor knows once [at] has resolved [taken]. A seam of its
  // own rather than a line inside [settle], because the history is also
  // [Key]'s third component: what a model records here is what decides how
  // many slots one pc is numbered into.
  def learn(at: Int, taken: Boolean): Map[Int, Boolean] = learned.updated(at, taken)
}

// The guess a machine with no history bits makes, which is not-taken at every
// branch forever.
//
// [learn] and not [predict] is the override. Nothing is ever recorded, so
// [Key.learned] is empty at every slot and the inherited [predict] answers
// `false` on its own; overriding the guess instead would leave the history in
// the key and number one pc into a slot per history, each staging the same
// code.
trait Static extends Predictive {
  override def learn(at: Int, taken: Boolean): Map[Int, Boolean] = Map.empty
}
