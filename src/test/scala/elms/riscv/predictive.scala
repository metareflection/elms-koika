package elms.koika.test.riscv

import elms.prelude.*
import elms.prelude.given

import elms.koika.test.KoikaSuite
import elms.koika.test.common.Predictive

// Nothing here that [SpecDriver] does not also want. The predictor leaves no
// trace in the struct, because its history is specialized away: what it
// believes is which generated function the program is in.
trait PredictiveDriver extends RiscVDriver with Predictive {
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

@virtualize
class RiscVPredictiveTests extends KoikaSuite {
  val under = "riscv/predictive/"

  test("riscv predictive shortcircuit") {
    val snippet = new PredictiveDriver {
      override val prog = demo("shortcircuit")
    }
    check("shortcircuit", snippet.code)
  }

  test("riscv predictive 2ctr") {
    val snippet = new PredictiveDriver {
      override val prog = demo("2ctr")
    }
    check("2ctr", snippet.code)
  }

  test("riscv predictive spectre") {
    val snippet = new PredictiveDriver {
      override val prog = demo("spectre")
    }
    check("spectre", snippet.code)
  }

  test("riscv predictive constant_time") {
    val snippet = new PredictiveDriver {
      override val prog = demo("constant_time")
    }
    check("constant_time", snippet.code)
  }
}
