package elms.koika.test.riscv

import elms.prelude.*
import elms.prelude.given

import elms.koika.test.{KoikaSuite, Verdict}
import elms.koika.test.common.{Init, Speculative}

@virtualize
class RiscVSpecTests extends KoikaSuite {
  val under = "riscv/speculative/"

  trait SpecDriver extends RiscVDriver[64] with Speculative {
    override val init = Init.speculative(stateT)
  }

  test("riscv spec shortcircuit") {
    val snippet = new SpecDriver {
      override val prog = demo("shortcircuit")
    }
    check("shortcircuit", snippet, Verdict.Leak)
  }

  test("riscv spec 2ctr") {
    val snippet = new SpecDriver {
      override val prog = demo("2ctr")
    }
    check("2ctr", snippet, Verdict.Leak)
  }

  test("riscv spec spectre") {
    val snippet = new SpecDriver {
      override val prog = demo("spectre")
    }
    check("spectre", snippet, Verdict.Leak)
  }

  test("riscv spec constant_time") {
    val snippet = new SpecDriver {
      override val prog = demo("constant_time")
    }
    check("constant_time", snippet, Verdict.Clean)
  }

  test("riscv spec bypass") {
    val snippet = new SpecDriver {
      override val prog = demo("bypass")
    }
    check("bypass", snippet, Verdict.Clean)
  }

  test("riscv spec bypass_ct") {
    val snippet = new SpecDriver {
      override val prog = demo("bypass_ct")
    }
    check("bypass_ct", snippet, Verdict.Clean)
  }

  test("riscv spec bypass_late") {
    val snippet = new SpecDriver {
      override val prog = demo("bypass_late")
    }
    check("bypass_late", snippet, Verdict.Clean)
  }

  test("riscv spec dynstore") {
    val snippet = new SpecDriver {
      override val prog = demo("dynstore")
    }
    check("dynstore", snippet, Verdict.Clean)
  }

  test("riscv spec bypass_alias") {
    val snippet = new SpecDriver {
      override val prog = demo("bypass_alias")
    }
    check("bypass_alias", snippet, Verdict.Clean)
  }

  // The eviction set. Inherited from [Cached] rather than added by this model,
  // the way most of this column is.
  test("riscv spec evict") {
    val snippet = new SpecDriver {
      override val prog = demo("evict")
    }
    check("evict", snippet, Verdict.Leak)
  }

  // The same channel as `2ctr` with a loop after it long enough to hide the
  // miss. `hidden.s` says which way each column is meant to answer and why.
  test("riscv spec hidden") {
    val snippet = new SpecDriver {
      override val prog = demo("hidden")
    }
    check("hidden", snippet, Verdict.Leak)
  }

  // `spectre.s` with the reload step. `reload.s` says why that is a different
  // claim from the one `spectre` makes, and this column answers both the same.
  test("riscv spec reload") {
    val snippet = new SpecDriver {
      override val prog = demo("reload")
    }
    check("reload", snippet, Verdict.Leak)
  }
}
