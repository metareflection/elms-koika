package elms.koika.test.riscv

import elms.prelude.*
import elms.prelude.given

import elms.koika.test.KoikaSuite
import elms.koika.test.common.Speculative

@virtualize
class RiscVSpecTests extends KoikaSuite {
  val under = "riscv/speculative/"

  trait SpecDriver extends RiscVDriver with Speculative {
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

  test("riscv spec shortcircuit") {
    val snippet = new SpecDriver {
      override val prog =
        RiscVDemos.build_shortcircuit_demo(secret_offset_bytes, password_size_bytes)
    }
    check("shortcircuit", snippet.code)
  }

  test("riscv spec 2ctr") {
    val snippet = new SpecDriver {
      override val prog = RiscVDemos.spec_small
    }
    check("2ctr", snippet.code)
  }

  test("riscv spec spectre") {
    val snippet = new SpecDriver {
      override val prog = RiscVDemos.build_spectre_demo(secret_offset_bytes)
    }
    check("spectre", snippet.code)
  }

  test("riscv spec constant_time") {
    val snippet = new SpecDriver {
      override val prog =
        RiscVDemos.build_constant_time_demo(secret_offset_bytes, password_size_bytes)
    }
    check("constant_time", snippet.code)
  }
}
