package elms.koika.test.riscv

import elms.prelude.*
import elms.prelude.given

import elms.koika.test.{KoikaSuite, Taint, Verdict}
import elms.koika.test.common.{Init, Static}

@virtualize
class RiscVStaticTests extends KoikaSuite {
  val under = "riscv/static/"

  trait StaticDriver extends RiscVDriver[64] with Static {
    override val init = Init.speculative(stateT)
  }

  test("riscv static shortcircuit") {
    val snippet = new StaticDriver {
      override val prog = demo("shortcircuit")
    }
    check("shortcircuit", snippet, Verdict.Leak)
  }

  test("riscv static 2ctr") {
    val snippet = new StaticDriver {
      override val prog = demo("2ctr")
    }
    check("2ctr", snippet, Verdict.Leak)
  }

  test("riscv static spectre") {
    val snippet = new StaticDriver {
      override val prog = demo("spectre")
    }
    check("spectre", snippet, Verdict.Leak)
  }

  test("riscv static constant_time") {
    val snippet = new StaticDriver {
      override val prog = demo("constant_time")
    }
    check("constant_time", snippet, Verdict.Clean)
  }

  test("riscv static bypass") {
    val snippet = new StaticDriver {
      override val prog = demo("bypass")
    }
    check("bypass", snippet, Verdict.Clean, eva = Taint.Widens)
  }

  test("riscv static bypass_ct") {
    val snippet = new StaticDriver {
      override val prog = demo("bypass_ct")
    }
    check("bypass_ct", snippet, Verdict.Clean)
  }

  test("riscv static bypass_late") {
    val snippet = new StaticDriver {
      override val prog = demo("bypass_late")
    }
    check("bypass_late", snippet, Verdict.Clean, eva = Taint.Widens)
  }

  test("riscv static dynstore") {
    val snippet = new StaticDriver {
      override val prog = demo("dynstore")
    }
    check("dynstore", snippet, Verdict.Clean)
  }

  test("riscv static bypass_alias") {
    val snippet = new StaticDriver {
      override val prog = demo("bypass_alias")
    }
    check("bypass_alias", snippet, Verdict.Clean)
  }

  // The eviction set. Inherited from [Cached] rather than added by this model,
  // the way most of this column is.
  test("riscv static evict") {
    val snippet = new StaticDriver {
      override val prog = demo("evict")
    }
    check("evict", snippet, Verdict.Leak)
  }

  // The same channel as `2ctr` with a loop after it long enough to hide the
  // miss. `hidden.s` says which way each column is meant to answer and why.
  test("riscv static hidden") {
    val snippet = new StaticDriver {
      override val prog = demo("hidden")
    }
    check("hidden", snippet, Verdict.Leak)
  }

  // `spectre.s` with the reload step. `reload.s` says why that is a different
  // claim from the one `spectre` makes, and this column answers both the same.
  test("riscv static reload") {
    val snippet = new StaticDriver {
      override val prog = demo("reload")
    }
    check("reload", snippet, Verdict.Leak)
  }

  // Where the balanced branch stops being balanced, and the first column that
  // says so. The branch is cold in both runs, so both guess not-taken; the run
  // that takes it pays the fifteen and the other pays nothing.
  //
  // The arms costing the same is what makes this a claim about the predictor
  // rather than about the program. Take the speculation away and the demo is
  // constant-time, which is what the three clean columns report.
  test("riscv static balanced") {
    val snippet = new StaticDriver {
      override val prog = demo("balanced")
    }
    check("balanced", snippet, Verdict.Leak)
  }
}
