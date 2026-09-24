package elms.koika.test

import elms.prelude.*
import elms.prelude.given

import elms.koika.test.common.{Init, Reach}
import elms.koika.test.squared.{
  Cached,
  Forwarding,
  NonBlocking,
  Predictive,
  PredictiveNonBlocking,
  Static
}
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

  // The three residues KLEE does not get through, measured rather than
  // guessed: 1500 seconds apiece with no verdict, against 453 for the slowest
  // one that does finish. `--max-time` stops KLEE forking new states and does
  // not interrupt a query already in flight, so the 1200-second budget is not
  // a wall clock, and a file like this hangs a default run rather than failing
  // it.
  //
  // All three are where the squared model carries the most. The two `bypass`
  // rows are the store queue's deferred alias check over addresses nobody
  // knows, doubled. `predictive_nb/reload` is the join, where a squash
  // rewrites every register's arrival time in both runs and the probe still
  // asks the cache afterwards.
  private val slow: Map[String, Reach] =
    Seq("forwarding/bypass_alias", "forwarding/bypass_late", "predictive_nb/reload")
      .map(_ -> Reach.LikelyTimeout)
      .toMap

  private def reach(label: String): Reach = slow.getOrElse(label, Reach.Settles)

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
      val label = s"static/$demoName"
      check(label, snippet, expect, klee = reach(label))
    }

    test(s"squared riscv predictive $demoName") {
      val snippet = new PredictiveDriver { override val prog = demo(demoName) }
      val label = s"predictive/$demoName"
      check(label, snippet, expect, klee = reach(label))
    }
  }

  // The store queue, and the first model here that inlines. Three demos come
  // out differently from the two predictors above: `bypass`, `bypass_alias`
  // and `bypass_late` are clean under a machine that commits a store the
  // instant it runs and are not under one that queues it.
  trait ForwardingDriver extends SquaredRiscVDriver[64] with Forwarding {
    override val init = Init.forwarding(stateT)
  }

  private val queued = Seq(
    "2ctr" -> Verdict.Leak,
    "bypass" -> Verdict.Leak,
    "bypass_alias" -> Verdict.Leak,
    "bypass_ct" -> Verdict.Clean,
    "bypass_late" -> Verdict.Leak,
    "constant_time" -> Verdict.Clean,
    "dynstore" -> Verdict.Clean,
    "evict" -> Verdict.Leak,
    "hidden" -> Verdict.Leak,
    "reload" -> Verdict.Leak,
    "shortcircuit" -> Verdict.Leak,
    "spectre" -> Verdict.Leak
  )

  for ((demoName, expect) <- queued) {
    test(s"squared riscv forwarding $demoName") {
      val snippet = new ForwardingDriver { override val prog = demo(demoName) }
      val label = s"forwarding/$demoName"
      check(label, snippet, expect, klee = reach(label))
    }
  }


  // A load the instructions behind it can hide. A miss stops being worth a
  // fixed hundred cycles and starts being worth whatever the program could not
  // fill, so most of what the cache column reports goes away here.
  trait NonBlockingDriver extends SquaredRiscVDriver[64] with NonBlocking {
    override val init = Init.nonblocking(stateT)
  }

  // Both halves of the state, since this model saves registers and tracks when
  // they land.
  trait PredNbDriver extends SquaredRiscVDriver[64] with PredictiveNonBlocking {
    override val init = Init.all(stateT)
  }

  // Two rows survive a memory system that does not stop.
  private val hiddenMiss = Seq(
    "2ctr" -> Verdict.Leak,
    "bypass" -> Verdict.Clean,
    "bypass_alias" -> Verdict.Clean,
    "bypass_ct" -> Verdict.Clean,
    "bypass_late" -> Verdict.Clean,
    "constant_time" -> Verdict.Clean,
    "dynstore" -> Verdict.Clean,
    "evict" -> Verdict.Clean,
    "hidden" -> Verdict.Clean,
    "reload" -> Verdict.Clean,
    "shortcircuit" -> Verdict.Leak,
    "spectre" -> Verdict.Clean
  )

  // And a third once a predictor runs ahead of it. `reload` is `spectre`
  // with the probe an attacker would actually perform, which is the row that
  // says the speculative channel is the cache line rather than the stall.
  private val joined = Seq(
    "2ctr" -> Verdict.Leak,
    "bypass" -> Verdict.Clean,
    "bypass_alias" -> Verdict.Clean,
    "bypass_ct" -> Verdict.Clean,
    "bypass_late" -> Verdict.Clean,
    "constant_time" -> Verdict.Clean,
    "dynstore" -> Verdict.Clean,
    "evict" -> Verdict.Clean,
    "hidden" -> Verdict.Clean,
    "reload" -> Verdict.Leak,
    "shortcircuit" -> Verdict.Leak,
    "spectre" -> Verdict.Clean
  )

  for ((demoName, expect) <- hiddenMiss) {
    test(s"squared riscv nonblocking $demoName") {
      val snippet = new NonBlockingDriver { override val prog = demo(demoName) }
      val label = s"nonblocking/$demoName"
      check(label, snippet, expect, klee = reach(label))
    }
  }

  for ((demoName, expect) <- joined) {
    test(s"squared riscv predictive_nb $demoName") {
      val snippet = new PredNbDriver { override val prog = demo(demoName) }
      val label = s"predictive_nb/$demoName"
      check(label, snippet, expect, klee = reach(label))
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

  test("squared riscv nonblocking branchy") {
    val snippet = new SquaredBranchyDriver with NonBlocking {}
    check("nonblocking/branchy", snippet, Verdict.Clean, klee = Reach.LikelyTimeout)
  }

  test("squared riscv predictive_nb branchy") {
    val snippet = new SquaredBranchyDriver with PredictiveNonBlocking {}
    check("predictive_nb/branchy", snippet, Verdict.Clean, klee = Reach.LikelyTimeout)
  }
}
