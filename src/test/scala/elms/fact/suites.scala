package elms.koika.test.fact

import elms.prelude.*
import elms.prelude.given

import elms.koika.test.{KoikaSuite, Taint}
import elms.koika.test.common.{Cached, Forwarding, Init, Predictive, Static}

// The FaCT ports against every model. Four programs, two that hold up and two
// that say where FaCT's guarantee stops.
//
// `salsa20` is the positive control, and what it controls for is size.
// Everything else in the tree that verifies clean does so in under twenty
// instructions, which is not much of a claim; this one is 277, and no model
// fails it.
//
// `guarded` is the only port whose verdict moves with the model. FaCT
// typechecks it and FaCT's bounds checker proves every index in range, and the
// residue still hands the key to anything that speculates.
//
// `choose` and `folded` are one source lowered two ways. `choose` is what
// `factc` emits for a secret conditional, and it is clean under every model.
// `folded` is the same LLVM with `instcombine` after it, which puts the branch
// back, and it leaks under every model. Nothing speculates in that one.
//
// `forwarding` is a fifth column and says nothing new about any of these four,
// which is worth having anyway. Neither `choose.o` nor `folded.o` contains a
// store, so their snapshots there are their `predictive` twins to the byte;
// `guarded.o` has one and `salsa20.o` has thirty-eight, and neither turns a
// verdict. The demos that exercise the queue are `riscv/bypass`.
//
// `src/test/fact/*.fact` has the rest of all of it.

@virtualize
class FactNaiveTests extends KoikaSuite {
  val under = "fact/naive/"

  for (p <- Program.all) {
    test(s"fact naive ${p.name}") {
      val snippet = new FactDriver(p) {
        override val init = Init.Spilling.naive(stateT)
      }
      check(p.name, snippet, p.expect.naive)
    }
  }
}

@virtualize
class FactCacheTests extends KoikaSuite {
  val under = "fact/cache/"

  // The one FaCT cell Eva widens, out of twenty. `guarded` indexes a table with
  // a public `idx` and the key sits past the end of it, so the load is tainted
  // whether or not the machine speculates far enough to time it. Every other
  // cell here Eva calls the way the other two backends do.
  //
  // A map rather than a test on `p.name`, because `@virtualize` claims any `if`
  // in a suite body and then cannot find a `unit` to build one out of.
  private val widens = Map("guarded" -> Taint.Widens)

  for (p <- Program.all) {
    test(s"fact cache ${p.name}") {
      val snippet = new FactDriver(p) with Cached {
        override val init = Init.Spilling.cache(stateT)
      }
      val eva = widens.getOrElse(p.name, Taint.Agrees)
      check(p.name, snippet, p.expect.cache, eva = eva)
    }
  }
}

@virtualize
class FactStaticTests extends KoikaSuite {
  val under = "fact/static/"

  for (p <- Program.all) {
    test(s"fact static ${p.name}") {
      val snippet = new FactDriver(p) with Static {
        override val init = Init.Spilling.speculative(stateT)
      }
      check(p.name, snippet, p.expect.static)
    }
  }
}

@virtualize
class FactPredictiveTests extends KoikaSuite {
  val under = "fact/predictive/"

  for (p <- Program.all) {
    test(s"fact predictive ${p.name}") {
      val snippet = new FactDriver(p) with Predictive {
        override val init = Init.Spilling.speculative(stateT)
      }
      check(p.name, snippet, p.expect.predictive)
    }
  }
}

@virtualize
class FactForwardingTests extends KoikaSuite {
  val under = "fact/forwarding/"

  for (p <- Program.all) {
    test(s"fact forwarding ${p.name}") {
      val snippet = new FactDriver(p) with Forwarding {
        override val init = Init.Spilling.forwarding(stateT)
      }
      check(p.name, snippet, p.expect.forwarding)
    }
  }
}
