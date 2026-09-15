package elms.koika.test.nanorisc

import elms.prelude.*
import elms.prelude.given

import elms.koika.test.{KoikaSuite, Verdict}
import elms.koika.test.common.Speculative

@virtualize
class SpecTests extends KoikaSuite {
  val under = "nanorisc/speculative/"

  trait SpecDriver extends NanoRiscDriver with Speculative {
    override val init = s"""void init(struct $stateT *s) {
         |  for (int i=0; i<NUM_REGS; i++) {
         |    s->regs[i] = 0;
         |    s->saved_regs[i] = 0;
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

  test("nanorisc spec shortcircuit") {
    val snippet = new SpecDriver {
      override val prog = NanoRiscDemos.build_shortcircuit_demo(secret_offset, 4)
    }
    check("shortcircuit", snippet, Verdict.Leak)
  }

  test("nanorisc spec 2ctr") {
    val snippet = new SpecDriver {
      override val prog = NanoRiscDemos.spec_small
    }
    check("2ctr", snippet, Verdict.Leak)
  }

  test("nanorisc spec spectre") {
    val snippet = new SpecDriver {
      override val prog = NanoRiscDemos.build_spectre_demo(secret_offset)
    }
    check("spectre", snippet, Verdict.Leak)
  }
}
