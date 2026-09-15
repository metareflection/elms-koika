package elms.koika.test

import elms.prelude.*
import elms.prelude.given

import scala.util.{Failure, Try}

import elms.koika.test.common.{GenericKoikaDriver, Prover, Reach}

// What a checker should say about a residue program.
//
// A claim about the program and not about the backend, so every backend that
// finishes agrees on it. [Reach] is the other half, for the one that does not
// always finish.
enum Verdict derives CanEqual {
  // The timing assertion holds. Either a positive control, or a model too weak
  // to see the channel this demo uses.
  case Clean
  // The timing assertion is violated, and the checker reports it.
  case Leak

  def word: String = this match {
    case Clean => "clean"
    case Leak  => "leak"
  }
}

abstract class KoikaSuite extends SnapshotFunSuite {
  // Every snapshot in this project is a checker's input, so [expect] is
  // required rather than defaulted. A demo nobody has made a claim about is not
  // a test.
  //
  // Takes the driver and not its rendering, because one call writes one
  // snapshot per backend and the bound each `verify` runs at comes off the same
  // object as the program it runs on.
  def check(
      label: String,
      snippet: GenericKoikaDriver[?, ?, ?],
      expect: Verdict,
      klee: Reach = Reach.Settles
  ): Unit =
    // Every backend is written before any assertion fires. Letting the first
    // mismatch throw left the second backend's snapshot unwritten, so one
    // backend's diff hid the other's and a run only ever fixed one of them.
    Prover.values.toSeq
      .map { prover =>
        val body = s"${line(prover, expect, snippet.unwind, klee)}\n${snippet.render(prover)}"
        Try(snapshot(label, body, "c", root = prover.root))
      }
      .collectFirst { case Failure(e) => e }
      .foreach(throw _)

  // First line of every snapshot, and the only thing a `verify` script parses
  // out of one. The verdict lives here rather than in a comment somewhere
  // because a claim a script cannot read is a claim nobody settles.
  private def line(
      prover: Prover,
      expect: Verdict,
      unwind: Int,
      klee: Reach
  ): String = {
    val says = expect match {
      case Verdict.Clean => prover.holds
      case Verdict.Leak  => prover.fails
    }
    prover match {
      case Prover.CBMC =>
        s"// verify: ${expect.word} (CBMC should report $says) [unwind $unwind]"

      case Prover.KLEE =>
        val budget = s"[budget ${Reach.budgetSeconds}s]"
        klee match {
          case Reach.Settles =>
            s"// verify: ${expect.word} (KLEE should report $says) $budget"
          // Still the program's verdict, since a finishing run has to produce
          // it. The word after it is what lets `verify` accept a run that ran
          // out of budget instead, and what it skips these on by default.
          case Reach.LikelyTimeout =>
            s"// verify: ${expect.word} likely-timeout" +
              s" (KLEE probably does not finish this path space) $budget"
        }
    }
  }
}
