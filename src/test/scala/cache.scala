package elms.koika.test

import elms.prelude.*
import elms.prelude.given

@virtualize
class CacheTests extends KoikaSuite {
  val under = "cache/"

  trait CacheDriver extends GenericKoikaDriver[StateT, StateT] with Cached {
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

  test("nanorisc cache shortcircuit") {
    val snippet = new CacheDriver {
      override val prog = NanoRiscDemos.build_shortcircuit_demo(secret_offset, 4)
    }
    check("shortcircuit", snippet.code)
  }

  test("nanorisc cache 2ctr") {
    val snippet = new CacheDriver {
      override val prog = NanoRiscDemos.spec_small
    }
    check("2ctr", snippet.code)
  }

  test("nanorisc cache spectre") {
    val snippet = new CacheDriver {
      override val prog = NanoRiscDemos.build_spectre_demo(secret_offset)
    }
    check("spectre", snippet.code)
  }
}
