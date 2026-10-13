package elms.koika.test.mono

import elms.prelude.*
import elms.prelude.given

import elms.koika.test.KoikaSuite
import elms.koika.test.common.{Cached, Forwarding, Init, Predictive, Static}

// Monocypher's `fe_ccopy` against every model, four ways.
//
// The library's source comment names two mitigations against a compiler
// turning its masked copy into a timing leak, `volatile` on the mask and
// unrolling the copy loop, and says they work "when applied separately or
// together". On clang targeting RV32IM at -O2 the second half of that is
// false, and these twenty cells are what says so: `shipped` and `volatile`
// keep the `volatile` and are clean on every model, `unrolled` keeps only the
// unrolling and leaks on every model, exactly as hard as `plain`, which keeps
// neither.
//
// The leak is in the control flow and in an address, so no model has to
// speculate to find it. All four variants answer the same on all five columns,
// which is the claim: this is about what llc emitted and not about what a
// machine does with it afterwards.
//
// Nothing here is a finding about the shipped library, which keeps the
// mitigation that works. `doc/candidates.md` has the `invsqrt` disassembly
// that says so and `src/test/mono/ccopy.c` has the rest of the story.

@virtualize
class MonoNaiveTests extends KoikaSuite {
  val under = "mono/naive/"

  for (p <- Program.all) {
    test(s"mono naive ${p.name}") {
      val snippet = new MonoDriver(p) {
        override val init = Init.Spilling.naive(stateT)
      }
      check(p.name, snippet, p.expect.naive)
    }
  }
}

@virtualize
class MonoCacheTests extends KoikaSuite {
  val under = "mono/cache/"

  for (p <- Program.all) {
    test(s"mono cache ${p.name}") {
      val snippet = new MonoDriver(p) with Cached {
        override val init = Init.Spilling.cache(stateT)
      }
      check(p.name, snippet, p.expect.cache)
    }
  }
}

@virtualize
class MonoStaticTests extends KoikaSuite {
  val under = "mono/static/"

  for (p <- Program.all) {
    test(s"mono static ${p.name}") {
      val snippet = new MonoDriver(p) with Static {
        override val init = Init.Spilling.speculative(stateT)
      }
      check(p.name, snippet, p.expect.static)
    }
  }
}

@virtualize
class MonoPredictiveTests extends KoikaSuite {
  val under = "mono/predictive/"

  for (p <- Program.all) {
    test(s"mono predictive ${p.name}") {
      val snippet = new MonoDriver(p) with Predictive {
        override val init = Init.Spilling.speculative(stateT)
      }
      check(p.name, snippet, p.expect.predictive)
    }
  }
}

@virtualize
class MonoForwardingTests extends KoikaSuite {
  val under = "mono/forwarding/"

  for (p <- Program.all) {
    test(s"mono forwarding ${p.name}") {
      val snippet = new MonoDriver(p) with Forwarding {
        override val init = Init.Spilling.forwarding(stateT)
      }
      check(p.name, snippet, p.expect.forwarding)
    }
  }
}
