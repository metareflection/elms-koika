package elms.koika.test

import elms.prelude.*
import elms.prelude.given

import elms.koika.test.common.{Init, Reach}
import elms.koika.test.squared.{Cached, Predictive, Static}
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

  // Speculation is where the two constructions of the product stop agreeing
  // about what to assert. `Lockstep` fused a branch only when it happened to
  // contain a slot call, and it decided that syntactically. These ask where
  // the model resolves the branch, because a pair that resolves it two ways
  // is running two programs from there on.
  //
  // Three demos under each of the two predictors, and the two answer alike on
  // all six. That is the point rather than a redundancy: `static` is the
  // guess a machine with no history bits makes, so a leak it finds is a claim
  // about the program rather than about a trained predictor.
  trait StaticDriver extends SquaredRiscVDriver[64] with Static {
    override val init = Init.speculative(stateT)
  }

  trait PredictiveDriver extends SquaredRiscVDriver[64] with Predictive {
    override val init = Init.speculative(stateT)
  }

  // Every demo `src/out/*/riscv/static` answers, so the two trees are the same
  // question asked two ways rather than a sample of it.
  //
  // Paired with the verdict rather than tested for it, because `@virtualize`
  // looks a `unit` up on the enclosing class before it decides whether an
  // `if` is one of its own, and a suite is not a `DslOps`.
  private val guessed = Seq(
    "2ctr" -> Verdict.Leak,
    "bypass" -> Verdict.Clean,
    "bypass_alias" -> Verdict.Clean,
    "bypass_ct" -> Verdict.Clean,
    "bypass_late" -> Verdict.Clean,
    "constant_time" -> Verdict.Clean,
    "dynstore" -> Verdict.Clean,
    "evict" -> Verdict.Leak,
    "hidden" -> Verdict.Leak,
    "reload" -> Verdict.Leak,
    "shortcircuit" -> Verdict.Leak,
    "spectre" -> Verdict.Leak
  )

  for ((demoName, expect) <- guessed) {
    test(s"squared riscv static $demoName") {
      val snippet = new StaticDriver { override val prog = demo(demoName) }
      check(s"static/$demoName", snippet, expect)
    }

    test(s"squared riscv predictive $demoName") {
      val snippet = new PredictiveDriver { override val prog = demo(demoName) }
      check(s"predictive/$demoName", snippet, expect)
    }
  }

  // `branchy.s` brings its own `initialize_input` and its own `init`, so it
  // comes through [SquaredBranchyDriver] rather than through the loop above.
  test("squared riscv static branchy") {
    val snippet = new SquaredBranchyDriver with Static {}
    check("static/branchy", snippet, Verdict.Clean, klee = Reach.LikelyTimeout)
  }

  test("squared riscv predictive branchy") {
    val snippet = new SquaredBranchyDriver with Predictive {}
    check("predictive/branchy", snippet, Verdict.Clean, klee = Reach.LikelyTimeout)
  }
}
