package elms.koika.test.fact

import elms.prelude.*
import elms.prelude.given

import elms.koika.test.KoikaSuite
import elms.koika.test.common.{Cached, Speculative}
import elms.koika.test.riscv.PredictiveDriver

// The Salsa20 core against the four models. There is no leaky twin here and no
// model is expected to fail: this is a positive control, and what it is control
// for is size. Everything else in the tree that verifies clean does so in under
// twenty instructions, which is not much of a claim. This one is 277.
//
// `src/test/fact/salsa20.fact` has the provenance and says why it is the only
// thing in `fact-eval` the tower can take.

@virtualize
class FactNaiveTests extends KoikaSuite {
  val under = "fact/naive/"

  for (p <- Program.all) {
    test(s"fact naive ${p.name}") {
      val snippet = new FactDriver(p) {
        override val init = Init.naive(stateT)
      }
      check(p.name, snippet.code)
    }
  }
}

@virtualize
class FactCacheTests extends KoikaSuite {
  val under = "fact/cache/"

  for (p <- Program.all) {
    test(s"fact cache ${p.name}") {
      val snippet = new FactDriver(p) with Cached {
        override val init = Init.cache(stateT)
      }
      check(p.name, snippet.code)
    }
  }
}

@virtualize
class FactSpecTests extends KoikaSuite {
  val under = "fact/speculative/"

  for (p <- Program.all) {
    test(s"fact spec ${p.name}") {
      val snippet = new FactDriver(p) with Speculative {
        override val init = Init.speculative(stateT)
      }
      check(p.name, snippet.code)
    }
  }
}

// [PredictiveDriver] carries an `init` of its own, and it is the RISC-V one,
// which leaves `sp` at 0. Overriding it is what gives this suite the stack the
// other three get from [Init].
@virtualize
class FactPredictiveTests extends KoikaSuite {
  val under = "fact/predictive/"

  for (p <- Program.all) {
    test(s"fact predictive ${p.name}") {
      val snippet = new FactDriver(p) with PredictiveDriver {
        override val init = Init.speculative(stateT)
      }
      check(p.name, snippet.code)
    }
  }
}
