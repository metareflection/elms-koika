package elms.koika.test.riscv

import elms.prelude.*
import elms.prelude.given

import elms.koika.test.{KoikaSuite, Verdict}
import elms.koika.test.common.{Init, Predictive}

// Nothing here that [SpecDriver] does not also want. The predictor leaves no
// trace in the struct, because its history is specialized away: what it
// believes is which generated function the program is in.
trait PredictiveDriver extends RiscVDriver[30] with Predictive {
  override val init = Init.speculative(stateT)
}

@virtualize
class RiscVPredictiveTests extends KoikaSuite {
  val under = "riscv/predictive/"

  test("riscv predictive shortcircuit") {
    val snippet = new PredictiveDriver {
      override val prog = demo("shortcircuit")
    }
    check("shortcircuit", snippet, Verdict.Leak)
  }

  test("riscv predictive 2ctr") {
    val snippet = new PredictiveDriver {
      override val prog = demo("2ctr")
    }
    check("2ctr", snippet, Verdict.Leak)
  }

  test("riscv predictive spectre") {
    val snippet = new PredictiveDriver {
      override val prog = demo("spectre")
    }
    check("spectre", snippet, Verdict.Leak)
  }

  test("riscv predictive constant_time") {
    val snippet = new PredictiveDriver {
      override val prog = demo("constant_time")
    }
    check("constant_time", snippet, Verdict.Clean)
  }

  test("riscv predictive bypass") {
    val snippet = new PredictiveDriver {
      override val prog = demo("bypass")
    }
    check("bypass", snippet, Verdict.Clean)
  }

  test("riscv predictive bypass_ct") {
    val snippet = new PredictiveDriver {
      override val prog = demo("bypass_ct")
    }
    check("bypass_ct", snippet, Verdict.Clean)
  }

  test("riscv predictive bypass_late") {
    val snippet = new PredictiveDriver {
      override val prog = demo("bypass_late")
    }
    check("bypass_late", snippet, Verdict.Clean)
  }

  test("riscv predictive dynstore") {
    val snippet = new PredictiveDriver {
      override val prog = demo("dynstore")
    }
    check("dynstore", snippet, Verdict.Clean)
  }

  test("riscv predictive bypass_alias") {
    val snippet = new PredictiveDriver {
      override val prog = demo("bypass_alias")
    }
    check("bypass_alias", snippet, Verdict.Clean)
  }
}
