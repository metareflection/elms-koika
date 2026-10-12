package elms.koika.test.common

import scala.collection.mutable

import elms.prelude.*
import elms.prelude.given

// A predictor whose history is a bounded shift register rather than a bit per
// branch.
//
// [Predictive] specializes on the whole history, so what the machine believes
// is which emitted function the program is in and the residue has no predictor
// in it at all. That is free in the residue and exponential in the key: k
// branches that can each still run put 2^k histories in the table, and the
// measurement is in `HistoryFanoutSuite`. Four branches is as deep as anything
// in this tree goes and a bignum modexp is fifteen, so the exponent is not
// binding here and is the whole problem on the code this is meant to reach.
//
// This takes the trade the other way. The history is [historyBits] of global
// outcome, so there are at most 2^[historyBits] of them whatever the program
// does, and the slot table is bounded by a constant nobody has to measure. The
// predictor's learned state moves into [StateG.pht], where it is an ordinary
// array and the residue reads it.
//
// What that costs is a [Rep] guess, which stages both continuations of every
// branch where [Predictive] staged one. They are not two paths forever: given
// the branch's real outcome, both arms end at the same pc under the same
// history, so each one closes at the resolution point. A checker that builds
// one formula pays for a join; one that enumerates paths pays for a fork, and
// that is the difference to watch when this reaches KLEE.
//
// gshare, which is the index being `pc ^ history` rather than either alone.
// Both halves are known while this stages, so the subscript in the residue is
// a constant and none of what a symbolic array read costs applies.
@virtualize
trait GlobalHistory extends Speculative with PhtOps {
  // How many outcomes the register keeps.
  //
  // The dial this model exists for. The slot table is bounded by 2^this on the
  // history axis whatever the program does, so it trades what the predictor
  // can tell apart against what the tower pays to tell it, and the crossover
  // against a bit per branch is at this many live branches: `HistoryFanoutSuite`
  // measures a seven-branch loop at 123x for the bit-per-branch key and 15.6x
  // for four bits of register.
  //
  // It is also the whole of what this model cannot answer for. A machine whose
  // predictor reaches further back than this one has channels this cannot see,
  // and `retrain.s` is the program where that shows: a bit per branch reports
  // the leak and every width here reports clean.
  //
  // Four by default, which is low. Nothing picked it but the demos, and a
  // driver that knows what it is modelling should say so.
  def historyBits: Int = 4

  // Entries in the table the history indexes. Fixed by [StateG]'s length, and
  // a driver that disagrees with its own struct would index past it.
  def phtEntries: Int

  override type History = Int
  override protected def emptyHistory: History = 0

  // Nothing here is attributable to a branch, so there is nothing to drop. A
  // bit set by one branch is read by whichever branch the register next
  // reaches, which is what a global history means.
  override protected def restrict(h: History, live: Set[Int]): History = h

  // One outcome shifted in, and the oldest shifted off the end. [at] is not
  // read: that is what makes this history global rather than per branch, and
  // it is the whole reason the register is bounded.
  override def learn(at: Int, taken: Boolean): History =
    ((learned << 1) | (if (taken) { 1 } else { 0 })) & ((1 << historyBits) - 1)

  // The outcome, into the entry the guess was read from.
  //
  // Written at the index the branch was *staged* under, which is the history
  // as it was before [learn] shifted this outcome in. Using the new one would
  // train an entry the branch will never be guessed from.
  //
  // [untimed] because a predictor update is the tower's traffic and not the
  // program's: no instruction waits on it.
  override protected def record(at: Int, taken: Boolean, s: Rep[State]): Rep[Unit] =
    untimed {
      s.pht(unit(phtIndex(at, learned))) = unit(if (taken) { 1 } else { 0 })
    }

  // Where [pc] under the current history lands in the table.
  //
  // Both operands are staging-time, so this is one number and the residue
  // spells it as a literal.
  // Where [pc] under history [h] lands in the table.
  //
  // A branch's number times the width of the history, plus the history. That
  // is a concatenation rather than a hash, so it is injective and no two
  // branches ever share an entry.
  //
  // Real hardware hashes, usually `pc ^ history`, and aliases heavily as a
  // result. This does not, for the reason [Predictive] gives for keeping its
  // branches apart: an entry two branches share is one where the second
  // overwrites what the first learned, so a secret stops being visible and the
  // residue comes out clean having lost a channel rather than gained one. The
  // direction matters more here than the realism does.
  //
  // It was `pc ^ h` to begin with, on the grounds that gshare is what a real
  // predictor does. `retrain_far.s` is 50 instructions and it collided on the
  // first try: pc 14 under history 7 and pc 8 under history 1 both want entry
  // 9. A hash wide enough to avoid that over a whole program is a table far
  // larger than this one, and numbering the branches costs nothing.
  //
  // Both halves are staging-time, so the residue spells this as a literal and
  // never computes a subscript.
  protected def phtIndex(pc: Int, h: History): Int = {
    val i = branchNumber(pc) * (1 << historyBits) + h
    require(
      i < phtEntries,
      s"pht entry $i is past the end of a table of $phtEntries. The program has " +
        s"${ordinal.size} branch(es) in it and the register is $historyBits bits, so it " +
        s"wants ${ordinal.size * (1 << historyBits)}"
    )
    i
  }

  // Which branch this is, in the order they were first staged. The numbering
  // is the tower's and has nothing to do with the pc: what it buys is a table
  // sized by how many branches a program has rather than by how long it is.
  private def branchNumber(pc: Int): Int = ordinal.getOrElseUpdate(pc, ordinal.size)

  private val ordinal = mutable.Map[Int, Int]()

  // The guess, read out of the table. A [Rep], which is what makes both arms
  // of the branch below get staged.
  override protected def guessing(pc: Int, s: Rep[State])(
      taken: => Rep[State]
  )(nottaken: => Rep[State]): Rep[State] = {
    val entry = untimed { s.pht(unit(phtIndex(pc, learned))) }
    __ifThenElse(entry !== unit(0), taken, nottaken)
  }
}
