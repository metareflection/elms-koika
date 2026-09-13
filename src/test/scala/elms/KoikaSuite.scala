package elms.koika.test

import elms.prelude.*
import elms.prelude.given

// What CBMC should say about a residue program.
//
// Stated where the test is and written into the snapshot, so `src/out/verify`
// can run the checker and fail when it says something else. That is the whole
// point of the type: a verdict in a comment is a claim nobody ever settles.
enum Verdict derives CanEqual {
  // The timing assertion holds. Either a positive control, or a model too weak
  // to see the channel this demo uses.
  case Clean
  // The timing assertion is violated, and CBMC reports it.
  case Leak

  // First line of every generated file, and the only part `verify` parses.
  def marker: String = this match {
    case Clean => "// verify: clean (CBMC should report VERIFICATION SUCCESSFUL)"
    case Leak  => "// verify: leak (CBMC should report VERIFICATION FAILED)"
  }
}

abstract class KoikaSuite extends SnapshotFunSuite {
  // Every snapshot in this project is a CBMC input, so [expect] is required
  // rather than defaulted. A demo nobody has made a claim about is not a test.
  def check(label: String, actual: String, expect: Verdict): Unit =
    snapshot(label, s"${expect.marker}\n$actual", "c")
}
