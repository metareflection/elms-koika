package elms.koika.test.riscv

import elms.prelude.*
import elms.prelude.given

import elms.koika.test.{KoikaSuite, Taint, Verdict}
import elms.koika.test.common.{Init, PredictiveNonBlocking}

// The join of the two columns either side of it: a branch predictor in front of
// loads the instructions behind them can hide.
//
// Reading this against `predictive` is what the suite is for. A row that answers
// differently is a row where speculation's gap was the stall rather than the
// cache, and `spectre` against `reload` is the whole of it: the gadget with no
// probe in it goes clean here, and the same gadget with a probe does not.
@virtualize
class RiscVPredictiveNonBlockingTests extends KoikaSuite {
  val under = "riscv/predictive_nb/"

  // Both halves of the state, since this model saves registers and tracks when
  // they land.
  trait PredNbDriver extends RiscVDriver[64] with PredictiveNonBlocking {
    override val init = Init.all(stateT)
  }

  test("riscv predictive_nb shortcircuit") {
    val snippet = new PredNbDriver {
      override val prog = demo("shortcircuit")
    }
    check("shortcircuit", snippet, Verdict.Leak)
  }

  test("riscv predictive_nb 2ctr") {
    val snippet = new PredNbDriver {
      override val prog = demo("2ctr")
    }
    check("2ctr", snippet, Verdict.Leak)
  }

  // The row that says what `spectre.s` was actually measuring. Its gap is the
  // speculated probe's own latency, 124 cycles against 223 under `predictive`,
  // and there is no reload in the program to ask the cache about afterwards. A
  // machine that does not stall on a load never charges a squashed one to
  // anybody, so this comes out 23 whatever the secret is.
  //
  // `reload` below is the same gadget with the probe put back, and it leaks
  // here. Neither row means much without the other.
  test("riscv predictive_nb spectre") {
    val snippet = new PredNbDriver {
      override val prog = demo("spectre")
    }
    check("spectre", snippet, Verdict.Clean)
  }

  test("riscv predictive_nb constant_time") {
    val snippet = new PredNbDriver {
      override val prog = demo("constant_time")
    }
    check("constant_time", snippet, Verdict.Clean)
  }

  test("riscv predictive_nb bypass") {
    val snippet = new PredNbDriver {
      override val prog = demo("bypass")
    }
    check("bypass", snippet, Verdict.Clean, eva = Taint.Widens)
  }

  test("riscv predictive_nb bypass_ct") {
    val snippet = new PredNbDriver {
      override val prog = demo("bypass_ct")
    }
    check("bypass_ct", snippet, Verdict.Clean)
  }

  test("riscv predictive_nb bypass_late") {
    val snippet = new PredNbDriver {
      override val prog = demo("bypass_late")
    }
    check("bypass_late", snippet, Verdict.Clean, eva = Taint.Widens)
  }

  test("riscv predictive_nb dynstore") {
    val snippet = new PredNbDriver {
      override val prog = demo("dynstore")
    }
    check("dynstore", snippet, Verdict.Clean)
  }

  test("riscv predictive_nb bypass_alias") {
    val snippet = new PredNbDriver {
      override val prog = demo("bypass_alias")
    }
    check("bypass_alias", snippet, Verdict.Clean)
  }

  test("riscv predictive_nb evict") {
    val snippet = new PredNbDriver {
      override val prog = demo("evict")
    }
    check("evict", snippet, Verdict.Clean, eva = Taint.Widens)
  }

  test("riscv predictive_nb hidden") {
    val snippet = new PredNbDriver {
      override val prog = demo("hidden")
    }
    check("hidden", snippet, Verdict.Clean, eva = Taint.Widens)
  }

  // The row this column exists to answer. `spectre` goes clean here because its
  // gap was the stall, and this is the same gadget with the probe that asks the
  // cache instead. A squash puts the registers back and does not put the line
  // back, so the leak survives a machine that hides its misses.
  test("riscv predictive_nb reload") {
    val snippet = new PredNbDriver {
      override val prog = demo("reload")
    }
    check("reload", snippet, Verdict.Leak)
  }

  // The predictor is back, so the misprediction is back. A machine that hides
  // its misses still pays in full for a branch it got wrong, because a squash
  // is not a miss.
  test("riscv predictive_nb balanced") {
    val snippet = new PredNbDriver {
      override val prog = demo("balanced")
    }
    check("balanced", snippet, Verdict.Leak)
  }
}
