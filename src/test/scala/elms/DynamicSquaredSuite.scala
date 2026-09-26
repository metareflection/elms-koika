package elms.koika.test

import elms.prelude.*
import elms.prelude.given

import elms.koika.test.common.Init
import elms.koika.test.squared.{Cached, DynamicSquared}
import elms.koika.test.riscv.SquaredRiscVDriver

// The squared tower with the control-flow assumption taken out, which is an
// open question rather than a model the tree ships. Both `verify` scripts hold
// this whole subtree back from a default run and `--full` is what spends a
// checker on it; `src/out/cbmc/verify` says why.
//
// `static` and `dynamic` here name when a conditional is settled and not which
// branch predictor is in front of it. The `static` in `squared/riscv/static`
// is the other word entirely.
//
// One demo, because `balanced` is the one demo where the assumption changes an
// answer. Its cells read `Clean` and agree with `riscv/naive/balanced` and
// `riscv/cache/balanced`, where the static squared cells next door read
// `Leak`. That is the whole result. The two towers can be made to agree again,
// and what it takes is giving up the pruning `squared_assume` was there for.
@virtualize
class DynamicSquaredSuite extends KoikaSuite {
  val under = "dynamic/riscv/"

  test("dynamic squared riscv naive balanced") {
    val snippet = new SquaredRiscVDriver[64] with DynamicSquared {
      override val init = Init.naive(stateT)
      override val prog = demo("balanced")
    }
    check("naive/balanced", snippet, Verdict.Clean)
  }

  test("dynamic squared riscv cache balanced") {
    val snippet = new SquaredRiscVDriver[64] with Cached with DynamicSquared {
      override val init = Init.cache(stateT)
      override val prog = demo("balanced")
    }
    check("cache/balanced", snippet, Verdict.Clean)
  }
}
