package elms.koika.test.riscv

import elms.prelude.*
import elms.prelude.given

import elms.koika.test.{KoikaSuite, Verdict}
import elms.koika.test.common.Speculative

@virtualize
class RiscVSpecTests extends KoikaSuite {
  val under = "riscv/speculative/"

  trait SpecDriver extends RiscVDriver[30] with Speculative {
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
      override val prog = demo("shortcircuit")
    }
    check("shortcircuit", snippet.code, Verdict.Leak)
  }

  test("riscv spec 2ctr") {
    val snippet = new SpecDriver {
      override val prog = demo("2ctr")
    }
    check("2ctr", snippet.code, Verdict.Leak)
  }

  test("riscv spec spectre") {
    val snippet = new SpecDriver {
      override val prog = demo("spectre")
    }
    check("spectre", snippet.code, Verdict.Leak)
  }

  test("riscv spec constant_time") {
    val snippet = new SpecDriver {
      override val prog = demo("constant_time")
    }
    check("constant_time", snippet.code, Verdict.Clean)
  }
}
