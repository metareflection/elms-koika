package elms.koika.test.riscv

import elms.prelude.*
import elms.prelude.given

import elms.koika.test.KoikaSuite
import elms.koika.test.common.Cached

@virtualize
class RiscVCacheTests extends KoikaSuite {
  val under = "riscv/cache/"

  trait CacheDriver extends RiscVDriver with Cached {
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
      override val prog =
        RiscVDemos.build_shortcircuit_demo(secret_offset_bytes, password_size_bytes)
    }
    check("shortcircuit", snippet.code)
  }

  test("riscv cache 2ctr") {
    val snippet = new CacheDriver {
      override val prog = RiscVDemos.spec_small
    }
    check("2ctr", snippet.code)
  }

  test("riscv cache spectre") {
    val snippet = new CacheDriver {
      override val prog = RiscVDemos.build_spectre_demo(secret_offset_bytes)
    }
    check("spectre", snippet.code)
  }

  test("riscv cache constant_time") {
    val snippet = new CacheDriver {
      override val prog =
        RiscVDemos.build_constant_time_demo(secret_offset_bytes, password_size_bytes)
    }
    check("constant_time", snippet.code)
  }
}
