package elms.koika.test

import elms.prelude.*
import elms.prelude.given

import scala.util.{Failure, Try}

import elms.koika.test.common.{KoikaDriver, Prover, Reach}

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

// Eva's answer, where taint's over-approximation makes it not [Verdict].
//
// A may-analysis over one run, so a timer the secret reaches syntactically is a
// leak to Eva whether or not the arithmetic can tell the two runs apart.
// `balanced` is the shape: both arms cost the same, the dependence is real, the
// difference is not.
//
// Two cases and not three. A residue Eva cannot reach the end of would want a
// third, and the unroll bound removed the need, since the swept tree has no
// such file. Add it the day one appears rather than carrying a case nothing
// constructs.
//
// An enum rather than `eva: Verdict = expect`, because Scala cannot default a
// parameter to another in the same list, and rather than `Option[Verdict]`
// because [Widens] makes the unsound direction unrepresentable. A leak
// narrowed to clean is not a label anyone can write.
//
// Nothing to do with `elf.Taint`, which says who a global in a RISC-V image
// belongs to. `riscv/compiled.scala` imports that one by name and so keeps it.
enum Taint derives CanEqual {
  // Eva proves what [Verdict] claims.
  case Agrees

  // The program is clean and Eva reports a leak anyway.
  //
  // Per file rather than per assertion, which is what the squared tower gives
  // up here. Every `squared_assert` in a residue, 228 of them in the worst one,
  // expands to the one `koika_check` inside the wrapper, so Eva says the file
  // leaks and never which slot. Recoverable by putting the contract on
  // `squared_assert`'s own declaration, at the price of a `prover match` in
  // `Stage.scala`.
  case Widens
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
      snippet: KoikaDriver[?, ?, ?, ?, ?],
      expect: Verdict,
      klee: Reach = Reach.Settles,
      eva: Taint = Taint.Agrees
  ): Unit =
    // Every backend is written before any assertion fires. Letting the first
    // mismatch throw left the second backend's snapshot unwritten, so one
    // backend's diff hid the other's and a run only ever fixed one of them.
    Prover.values.toSeq
      .map { prover =>
        val body = s"${line(prover, expect, snippet.unwind, klee, eva)}\n${snippet.render(prover)}"
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
      klee: Reach,
      eva: Taint
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

      // Same bound CBMC unwinds to, spent on Eva's recursive calls. Some demos
      // stage a loop into a cycle of slots, and Eva declines to unroll one
      // unless told how far. Left at the default it widens an index to top,
      // proves the out-of-bounds access that follows, and reduces the state to
      // bottom, so `main` never reaches the sink and the file answers nothing.
      case Prover.EVA =>
        val bound = s"[unroll $unwind]"
        eva match {
          case Taint.Agrees =>
            s"// verify: ${expect.word} (Eva should report $says) $bound"
          // The word after the verdict is what stops this reading as a flat
          // disagreement with the other two trees, the way `likely-timeout`
          // does for KLEE. `verify` parses up to the first space either way.
          case Taint.Widens =>
            s"// verify: ${Verdict.Leak.word} widened" +
              s" (the program is clean; Eva cannot prove it) $bound"
        }
    }
  }
}
