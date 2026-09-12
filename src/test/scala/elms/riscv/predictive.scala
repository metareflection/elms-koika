package elms.koika.test.riscv

import elms.prelude.*
import elms.prelude.given

import elms.koika.test.KoikaSuite
import elms.koika.test.common.Predictive

// The predictor's table hangs off the state rather than sitting in a C global.
// Two states sharing one would train each other, and whether the secret shows
// up in what the predictor has learned is the whole question.
trait PredictiveDriver extends RiscVDriver with Predictive {
  override def defines: Seq[(String, Int)] = super.defines :+ ("BHT_SIZE" -> bhtSize)
  override def stateTFields: Seq[String] = super.stateTFields :+ "int bht[BHT_SIZE];"

  // A cold table predicts not-taken, which is what [Speculative] does
  // unconditionally. It is also what keeps `spectre` speculating over its
  // gadget: that `bge` is always taken, so a table starting at taken would
  // never open the window the demo exists to show.
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
       |  for (int i=0; i<BHT_SIZE; i++) {
       |    s->bht[i] = 0;
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
