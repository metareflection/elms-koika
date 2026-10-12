package elms.koika.test

import elms.prelude.*
import elms.prelude.given

import elms.koika.test.common.Init
import elms.koika.test.riscv.RiscVGhrDriver

// The predictor as a bounded history register, which is a question about how
// far this tower reaches rather than a model the tree ships. Every `verify`
// holds the subtree back from a default run and `--full` is what spends a
// checker on it; `src/out/cbmc/verify` says why.
//
// [common.Predictive] keys a slot on the whole history, so the predictor is
// specialized over rather than reified: what the machine believes is which
// emitted function the program is in, and the functions one pc is numbered
// into are the predictor written as control flow. That is the model every
// column of the README's table is computed on, and it is the cheaper
// representation on every demo in the tree. [common.GlobalHistory] moves the
// same state across the staging boundary: `historyBits` of it stay in the key
// and the table goes in the struct beside the cache, where a checker reads
// it.
//
// The register costs more here and is meant to. The crossover against a bit
// per branch is at `historyBits` live branches and nothing in this tree has
// more than four, so these cells tie or lose: `spectre` is 9 slots against 15,
// `2ctr` is 5 against 10. What the trade buys is on the other side of that
// crossover, where a seven-branch loop is 6144 slots against 779, and
// `HistoryFanoutSuite` is where it is measured rather than here.
//
// The verdicts are the point of the subtree. They are [Predictive]'s verdicts
// on every demo below, which is what says the two models answer alike wherever
// the tree can compare them, and `retrain` is where they stop: see
// `GhrFidelitySuite`.
@virtualize
class GhrSuite extends KoikaSuite {
  val under = "ghr/riscv/"

  // Four bits, which is the default and is low. It is also past the live
  // branch count of every demo here, so these cells say what the model does
  // with room to spare rather than what it does when the register is the
  // binding constraint.
  //
  // 128 entries, because the widest demo here has seven branches and seven at
  // four bits wants 112. Sized rather than generous: `unwind` has to clear the
  // loop `init` runs over the table, so every spare entry is paid for by every
  // file.
  private trait GhrDriver extends RiscVGhrDriver[64, 128] {
    override val init = Init.globalHistory(stateT)
  }

  private def demoAt(name: String, bits: Int, expect: Verdict, eva: Taint = Taint.Agrees): Unit =
    test(s"ghr riscv $name at $bits bits") {
      val snippet = new GhrDriver {
        override val prog = demo(name)
        override def historyBits: Int = bits
      }
      check(s"$name-h$bits", snippet, expect, eva = eva)
    }

  // The same eight [Predictive] answers for, at the default width. Every
  // verdict below is the one `riscv/predictive/<demo>` claims.
  demoAt("constant_time", 4, Verdict.Clean)
  demoAt("spectre", 4, Verdict.Leak)
  demoAt("reload", 4, Verdict.Leak)
  demoAt("2ctr", 4, Verdict.Leak)
  demoAt("balanced", 4, Verdict.Leak)
  demoAt("dynstore", 4, Verdict.Clean)
  demoAt("bypass_late", 4, Verdict.Clean)
  demoAt("shortcircuit", 4, Verdict.Leak)
}

// Where the two predictors stop agreeing, which is the one thing a bounded
// history cannot be swapped in without.
//
// `retrain.s` trains a branch on the secret and reads it back two branches
// later. A bit per branch still has it and reports the leak, which is
// `riscv/predictive/retrain`'s cell. A register does not, at any width here,
// and the reason is not that four branches shifted it out: the secret makes
// the two runs' registers diverge, which sends them to different entries, both
// cold, and the channel is gone.
//
// `retrain_far.s` is the same program with five public branches in between and
// it leaks at every width, because those shift zeros in until the register is
// back where the first call left it. So distance is not what decides it, and
// that is why both objects are here rather than one.
//
// Neither model is wrong about its own machine. A machine with a four-bit
// global history really is constant-time on `retrain`. What the register
// cannot do is answer for one that reaches further back, and these cells are
// where that is written down.
@virtualize
class GhrFidelitySuite extends KoikaSuite {
  val under = "ghr/riscv/"

  // 512, because these go to six bits and `retrain_far`'s seven branches at
  // six bits want 448.
  private trait GhrDriver extends RiscVGhrDriver[64, 512] {
    override val init = Init.globalHistory(stateT)
  }

  for (bits <- Seq(2, 4, 6)) {
    test(s"ghr riscv retrain at $bits bits") {
      val snippet = new GhrDriver {
        override val prog = demo("retrain")
        override def historyBits: Int = bits
      }
      // Clean, and `riscv/predictive/retrain` is a leak. The disagreement is
      // the cell.
      check(s"retrain-h$bits", snippet, Verdict.Clean)
    }

    test(s"ghr riscv retrain_far at $bits bits") {
      val snippet = new GhrDriver {
        override val prog = demo("retrain_far")
        override def historyBits: Int = bits
      }
      check(s"retrain_far-h$bits", snippet, Verdict.Leak)
    }
  }
}
