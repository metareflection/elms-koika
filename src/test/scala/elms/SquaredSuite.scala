package elms.koika.test

import elms.prelude.*
import elms.prelude.given

import elms.koika.test.common.{Init, Reach}
import elms.koika.test.squared.Cached
import elms.koika.test.riscv.{SquaredBranchyDriver, SquaredCompiledDriver, SquaredRiscVDriver}

// The same demos as `src/out/*/riscv`, answered by the squared interpreter
// instead of by self-composition. Every verdict here has to match the one next
// door, because the two are answering the same question about the same
// program, and that agreement is what keeps the two towers from drifting.
//
// Labels carry the model, so a residue lands beside its twin's path with
// `squared/` on the front.
@virtualize
class SquaredSuite extends KoikaSuite {
  val under = "squared/riscv/"

  test("squared riscv cache 2ctr") {
    val snippet = new SquaredRiscVDriver[64] with Cached {
      override val init = Init.cache(stateT)
      override val prog = demo("2ctr")
    }
    check("cache/2ctr", snippet, Verdict.Leak)
  }

  test("squared riscv cache constant_time") {
    val snippet = new SquaredRiscVDriver[64] with Cached {
      override val init = Init.cache(stateT)
      override val prog = demo("constant_time")
    }
    check("cache/constant_time", snippet, Verdict.Clean)
  }

  test("squared riscv cache shortcircuit") {
    val snippet = new SquaredRiscVDriver[64] with Cached {
      override val init = Init.cache(stateT)
      override val prog = demo("shortcircuit")
    }
    check("cache/shortcircuit", snippet, Verdict.Leak)
  }

  // The demo the tower exists for: clean, and solver-bound rather than
  // symex-bound, so the assumptions have a path space to cut down.
  //
  // Cutting it is not the same as clearing it. The assumptions get KLEE from
  // zero completed paths to a few hundred of 265,721, because `squared_assume`
  // prunes a solver's formula and KLEE has already paid for the fork by the
  // time it runs.
  test("squared riscv cache branchy") {
    val snippet = new SquaredBranchyDriver with Cached {}
    check("cache/branchy", snippet, Verdict.Clean, klee = Reach.LikelyTimeout)
  }

  test("squared riscv compiled naive") {
    val snippet = new SquaredCompiledDriver {
      override val init = Init.naive(stateT)
    }
    check("compiled/naive", snippet, Verdict.Leak)
  }
}
