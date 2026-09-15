package elms.koika.test

import elms.prelude.*
import elms.prelude.given

import elms.koika.test.common.{Cached, Lockstepped}
import elms.koika.test.riscv.{BranchyDriver, CompiledDriver, RiscVDriver}

// The same demos as `src/out/riscv`, checked by [Lockstep] instead of by
// self-composition. Every verdict here has to match the one next door, because
// the two are answering the same question about the same program.
//
// Labels carry the model, so a residue lands beside its twin's path with
// `lockstep/` on the front.
@virtualize
class LockstepSuite extends KoikaSuite {
  val under = "lockstep/riscv/"

  private val cacheInit = (stateT: String) => s"""void init(struct $stateT *s) {
       |  for (int i=0; i<NUM_REGS; i++) {
       |    s->regs[i] = 0;
       |  }
       |  s->timer = 0;
       |  for (int i=0; i<MEM_SIZE; i++) {
       |    s->mem[i] = 0;
       |  }
       |  for (int i=0; i<CACHE_LRU_SIZE; i++) {
       |    s->cache_keys[i] = -1;
       |    s->cache_vals[i] = -1;
       |  }
       |}""".stripMargin

  test("lockstep riscv cache 2ctr") {
    val snippet = new RiscVDriver[30] with Cached with Lockstepped[32, 30, 10] {
      override val init = cacheInit(stateT)
      override val prog = demo("2ctr")
    }
    check("cache/2ctr", snippet, Verdict.Leak)
  }

  test("lockstep riscv cache constant_time") {
    val snippet = new RiscVDriver[30] with Cached with Lockstepped[32, 30, 10] {
      override val init = cacheInit(stateT)
      override val prog = demo("constant_time")
    }
    check("cache/constant_time", snippet, Verdict.Clean)
  }

  test("lockstep riscv cache shortcircuit") {
    val snippet = new RiscVDriver[30] with Cached with Lockstepped[32, 30, 10] {
      override val init = cacheInit(stateT)
      override val prog = demo("shortcircuit")
    }
    check("cache/shortcircuit", snippet, Verdict.Leak)
  }

  // The demo the pass exists for: clean, and solver-bound rather than
  // symex-bound, so the assumptions have a path space to cut down.
  test("lockstep riscv cache branchy") {
    val snippet = new BranchyDriver with Cached with Lockstepped[32, 32, 10] {}
    check("cache/branchy", snippet, Verdict.Clean)
  }

  test("lockstep riscv compiled naive") {
    val snippet = new CompiledDriver with Lockstepped[32, 30, 10] {
      override val init = s"""void init(struct $stateT *s) {
           |  for (int i=0; i<NUM_REGS; i++) {
           |    s->regs[i] = 0;
           |  }
           |  s->timer = 0;
           |  for (int i=0; i<MEM_SIZE; i++) {
           |    s->mem[i] = 0;
           |  }
           |}""".stripMargin
    }
    check("compiled/naive", snippet, Verdict.Leak)
  }
}
