package elms.koika.test.riscv

import elms.prelude.*
import elms.prelude.given

import elms.koika.test.KoikaSuite

@virtualize
class RiscVNaiveTests extends KoikaSuite {
  val under = "riscv/naive/"

  trait NaiveDriver extends RiscVDriver {
    // In the naive driver, we don't use caching or speculation, so we don't
    // need to initialize everything except [regs], [timer] and [mem].
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

  test("riscv naive shortcircuit") {
    val snippet = new NaiveDriver {
      override val prog =
        RiscVDemos.build_shortcircuit_demo(secret_offset_bytes, password_size_bytes)
    }
    check("shortcircuit", snippet.code)
  }

  test("riscv naive 2ctr") {
    val snippet = new NaiveDriver {
      override val prog = RiscVDemos.spec_small
    }
    check("2ctr", snippet.code)
  }

  test("riscv naive spectre") {
    val snippet = new NaiveDriver {
      override val prog = RiscVDemos.build_spectre_demo(secret_offset_bytes)
    }
    check("spectre", snippet.code)
  }

  test("riscv naive constant_time") {
    val snippet = new NaiveDriver {
      override val prog =
        RiscVDemos.build_constant_time_demo(secret_offset_bytes, password_size_bytes)
    }
    check("constant_time", snippet.code)
  }
}
