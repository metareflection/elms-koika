package elms.koika.test.fact

import elms.prelude.*
import elms.prelude.given

import elms.koika.test.{KoikaSuite, Taint}
import elms.koika.test.common.{Cached, Forwarding, Init, Predictive, Reach, Static}

// The FaCT ports against every model. Twelve programs, nine that hold up and
// three that say where FaCT's guarantee stops.
//
// `salsa20` is the positive control, and what it controls for is size.
// Everything else in the tree that verifies clean does so in under twenty
// instructions, which is not much of a claim; this one is 277, and no model
// fails it.
//
// `hsalsa20`, `salsa_keysetup`, `poly1305_init`, `fsum`,
// `fdifference_backwards` and `swap_conditional` are six more leaves out of
// the same two case studies, and they are here to be boring. Every branch llc
// emits across the six counts a public loop, and every address in them is a
// constant offset from a public base pointer. Thirty cells, none of which
// moves with the model, which is the claim FaCT makes and `guarded` is the
// exception to.
//
// `crypto_verify_16` is the one that says something on its own, because the
// tree already carries the same algorithm compiled by clang.
// `src/test/asm/riscv/cmp.c` loops until the first mismatch and leaks on
// `naive`; FaCT's `stdlib.fact` writes that loop the same way and emits
// sixteen unconditional iterations of mask arithmetic. `Program` has the
// bodies side by side.
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
// `fscalar_product` is that pair's third member and needs no extra pass to be
// it. The source has no conditional and neither does the `.ll`, and llc still
// emits four `beq`s, because a 64-bit carry comparison on a 32-bit target
// lowers as a branch. It leaks under every model for the same reason `folded`
// does. `fsum` and `fdifference_backwards` sit beside it in the same FaCT file
// over the same five limbs and stay clean, so the leak is the `uint128`
// accumulator rather than anything about curve25519.
//
// `forwarding` is a fifth column and says nothing new about any of these
// five, which is worth having anyway. Neither `choose.o` nor `folded.o`
// contains a store, so their snapshots there are their `predictive` twins to
// the byte; `guarded.o` has one, `fscalar_product.o` has sixteen and `salsa20.o`
// has thirty-eight, and none of them turns a verdict. The demos that exercise
// the queue are `riscv/bypass`.
//
// `src/test/fact/*.fact` has the rest of all of it.

@virtualize
class FactNaiveTests extends KoikaSuite {
  val under = "fact/naive/"

  // The one cell KLEE answers out of a port it cannot answer, which is the
  // other direction from `FactCacheTests`'s `widens`. `fdifference_backwards`
  // is [Reach.LikelyTimeout] because four of its five models spend a whole
  // budget and get nowhere, and this one closes in 224 seconds, so leaving the
  // program's label on it would drop a verdict the default run can afford.
  //
  // A map for the same reason that one is a map: `@virtualize` claims any `if`
  // in a suite body and then cannot find a `unit` to build one out of.
  private val settles = Map("fdifference_backwards" -> Reach.Settles)

  for (p <- Program.all) {
    test(s"fact naive ${p.name}") {
      val snippet = new FactDriver(p) {
        override val init = Init.Spilling.naive(stateT)
      }
      check(p.name, snippet, p.expect.naive, klee = settles.getOrElse(p.name, p.klee))
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
      check(p.name, snippet, p.expect.cache, klee = p.klee, eva = eva)
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
      check(p.name, snippet, p.expect.static, klee = p.klee)
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
      check(p.name, snippet, p.expect.predictive, klee = p.klee)
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
      check(p.name, snippet, p.expect.forwarding, klee = p.klee)
    }
  }
}
