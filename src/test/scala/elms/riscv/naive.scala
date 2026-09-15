package elms.koika.test.riscv

import elms.prelude.*
import elms.prelude.given

import elms.koika.test.{KoikaSuite, Verdict}

@virtualize
class RiscVNaiveTests extends KoikaSuite {
  val under = "riscv/naive/"

  trait NaiveDriver extends RiscVDriver[30] {
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
      override val prog = demo("shortcircuit")
    }
    check("shortcircuit", snippet, Verdict.Leak)
  }

  test("riscv naive 2ctr") {
    val snippet = new NaiveDriver {
      override val prog = demo("2ctr")
    }
    check("2ctr", snippet, Verdict.Clean)
  }

  test("riscv naive spectre") {
    val snippet = new NaiveDriver {
      override val prog = demo("spectre")
    }
    check("spectre", snippet, Verdict.Clean)
  }

  test("riscv naive constant_time") {
    val snippet = new NaiveDriver {
      override val prog = demo("constant_time")
    }
    check("constant_time", snippet, Verdict.Clean)
  }
}
