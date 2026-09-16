package elms.koika.test.fact

import elms.prelude.*
import elms.prelude.given

import elms.koika.test.KoikaSuite
import elms.koika.test.common.{Cached, Predictive, Speculative}

// The FaCT ports against the four models.
//
// `salsa20` is the positive control, and what it controls for is size.
// Everything else in the tree that verifies clean does so in under twenty
// instructions, which is not much of a claim; this one is 277, and no model
// fails it.
//
// `guarded` is the negative one, and the only port whose verdict moves with the
// model. FaCT typechecks it and FaCT's bounds checker proves every index in
// range, and the residue still hands the key to anything that speculates.
//
// `src/test/fact/salsa20.fact` and `src/test/fact/guarded.fact` have the rest
// of both stories.

@virtualize
class FactNaiveTests extends KoikaSuite {
  val under = "fact/naive/"

  for (p <- Program.all) {
    test(s"fact naive ${p.name}") {
      val snippet = new FactDriver(p) {
        override val init = Init.naive(stateT)
      }
      check(p.name, snippet, p.expect.naive)
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
      check(p.name, snippet, p.expect.cache)
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
      check(p.name, snippet, p.expect.speculative)
    }
  }
}

@virtualize
class FactPredictiveTests extends KoikaSuite {
  val under = "fact/predictive/"

  for (p <- Program.all) {
    test(s"fact predictive ${p.name}") {
      val snippet = new FactDriver(p) with Predictive {
        override val init = Init.speculative(stateT)
      }
      check(p.name, snippet, p.expect.predictive)
    }
  }
}
