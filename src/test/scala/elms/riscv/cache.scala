package elms.koika.test.riscv

import elms.prelude.*
import elms.prelude.given

import elms.koika.test.{KoikaSuite, Verdict}
import elms.koika.test.common.Cached

@virtualize
class RiscVCacheTests extends KoikaSuite {
  val under = "riscv/cache/"

  trait CacheDriver extends RiscVDriver[30] with Cached {
    override val init = s"""void init(struct $stateT *s) {
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
  }

  test("riscv cache shortcircuit") {
    val snippet = new CacheDriver {
      override val prog = demo("shortcircuit")
    }
    check("shortcircuit", snippet.code, Verdict.Leak)
  }

  test("riscv cache 2ctr") {
    val snippet = new CacheDriver {
      override val prog = demo("2ctr")
    }
    check("2ctr", snippet.code, Verdict.Leak)
  }

  test("riscv cache spectre") {
    val snippet = new CacheDriver {
      override val prog = demo("spectre")
    }
    check("spectre", snippet.code, Verdict.Clean)
  }

  test("riscv cache constant_time") {
    val snippet = new CacheDriver {
      override val prog = demo("constant_time")
    }
    check("constant_time", snippet.code, Verdict.Clean)
  }
}
