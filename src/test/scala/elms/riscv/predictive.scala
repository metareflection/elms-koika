package elms.koika.test.riscv

import elms.prelude.*
import elms.prelude.given

import elms.koika.test.{KoikaSuite, Verdict}
import elms.koika.test.common.{Init, Predictive}

// Nothing here that [SpecDriver] does not also want. The predictor leaves no
// trace in the struct, because its history is specialized away: what it
// believes is which generated function the program is in.
trait PredictiveDriver extends RiscVDriver[64] with Predictive {
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

  // The eviction set. Inherited from [Cached] rather than added by this model,
  // the way most of this column is.
  test("riscv predictive evict") {
    val snippet = new PredictiveDriver {
      override val prog = demo("evict")
    }
    check("evict", snippet, Verdict.Leak)
  }

  // The same channel as `2ctr` with a loop after it long enough to hide the
  // miss. `hidden.s` says which way each column is meant to answer and why.
  test("riscv predictive hidden") {
    val snippet = new PredictiveDriver {
      override val prog = demo("hidden")
    }
    check("hidden", snippet, Verdict.Leak)
  }

  // `spectre.s` with the reload step. `reload.s` says why that is a different
  // claim from the one `spectre` makes, and this column answers both the same.
  test("riscv predictive reload") {
    val snippet = new PredictiveDriver {
      override val prog = demo("reload")
    }
    check("reload", snippet, Verdict.Leak)
  }
}
