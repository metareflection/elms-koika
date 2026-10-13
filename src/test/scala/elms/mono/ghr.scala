package elms.koika.test.mono

import elms.prelude.*
import elms.prelude.given

import elms.koika.test.KoikaSuite
import elms.koika.test.common.Init

// The `fe_ccopy` objects under a bounded history register, which is where the
// argument `doc/candidates.md` makes from their branch count gets measured and
// does not survive.
//
// That argument: the crossover against a bit per branch is at `historyBits`
// live branches, `unrolled` and `plain` have twelve branches against a
// four-bit register, so they are the first objects in this tree on the winning
// side of it. Every number below says the opposite, and by a wide margin.
//
// Staged, against `mono/predictive`'s 84 slots on the same object:
//
//   h=1   200 slots     h=3   618 slots
//   h=2   342 slots     h=4  1117 slots
//
// The register pays `2^historyBits` on all 68 instructions and the
// bit-per-branch key pays almost nothing. Checked, under an 8 GB cap:
//
//   predictive   leak  128s  2.94 GB      h=3  killed  359s  >8 GB
//   h=1          leak  138s  3.07 GB      h=4  killed  355s  >8 GB
//   h=2          leak  147s  3.15 GB
//
// So these cells run at two bits, which is the widest register that answers
// about this object at all. Not the four every other `ghr/` cell uses, and
// the gap is the result rather than a concession to cost.
//
// Why the argument failed is the part worth keeping. The crossover is at as
// many live branches as the register has bits, and `live.py` calls all twelve
// of these live, but [Exec.liveBranchesAt] does not: it keys a slot on
// `Flow.trains(prog, pc) ++ consulted`, the branches whose recorded outcome
// something still reads. These twelve are twelve copies of one unrolled body,
// each executed once, so nothing ever consults what they recorded and the key
// drops all of them. A branch count is not what decides the trade. Whether
// branch outcomes get reused is, and that is a loop, which is what
// `HistoryFanoutSuite`'s `loop-same` family has and this object does not.
//
// Not the unwind bound, which is the other thing it could have been:
// [RiscVGhrDriver.unwind] raises it to `phtEntries + 1`, so h=3 and h=4 run at
// 97 and 193 where h=2 runs at 65. Staging h=2 and checking it at 193 costs
// 148s and 3.30 GB against 147s and 3.15 GB at 65. The bound is nearly free
// and the slots are not.
@virtualize
class MonoGhrTests extends KoikaSuite {
  val under = "ghr/mono/"

  for (p <- Program.all) {
    test(s"mono ghr ${p.name}") {
      // Twelve branches at two bits want 48 entries and the clean pair wants
      // none, so 48 is the leaking pair's number exactly. Sized and not
      // generous: a spare entry is paid for by every file here.
      val snippet = new MonoGhrDriver[48](p) {
        override val init = Init.globalHistory(stateT)
        override def historyBits: Int = 2
      }
      // [Predictive]'s verdict, which is what every other `ghr/` cell checks
      // too. The register is a different representation of the same state, so
      // a different answer here would be a fidelity bug and not a finding.
      // The cost is where they differ and the verdict is not.
      check(s"${p.name}-h2", snippet, p.expect.predictive)
    }
  }
}
