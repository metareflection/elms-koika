package elms.koika.test.riscv

import elms.prelude.*
import elms.prelude.given

import elms.koika.test.{KoikaSuite, Verdict}
import elms.koika.test.common.{Forwarding, Init}

// The four demos [RiscVSpecTests] runs, against a model with a store queue in
// it. None of them contains a store, so every snapshot here is its twin under
// `speculative` to the byte, and that is what the suite is for: a model that
// only ever adds a channel has to leave a program with no store alone.
//
// `bypass.s` and `bypass_ct.s` are where this column says something of its own.
@virtualize
class RiscVForwardingTests extends KoikaSuite {
  val under = "riscv/forwarding/"

  trait FwdDriver extends RiscVDriver[30] with Forwarding {
    override val init = Init.forwarding(stateT)
  }

  test("riscv forwarding shortcircuit") {
    val snippet = new FwdDriver {
      override val prog = demo("shortcircuit")
    }
    check("shortcircuit", snippet, Verdict.Leak)
  }

  test("riscv forwarding 2ctr") {
    val snippet = new FwdDriver {
      override val prog = demo("2ctr")
    }
    check("2ctr", snippet, Verdict.Leak)
  }

  test("riscv forwarding spectre") {
    val snippet = new FwdDriver {
      override val prog = demo("spectre")
    }
    check("spectre", snippet, Verdict.Leak)
  }

  test("riscv forwarding constant_time") {
    val snippet = new FwdDriver {
      override val prog = demo("constant_time")
    }
    check("constant_time", snippet, Verdict.Clean)
  }

  test("riscv forwarding bypass") {
    val snippet = new FwdDriver {
      override val prog = demo("bypass")
    }
    check("bypass", snippet, Verdict.Leak)
  }

  test("riscv forwarding bypass_ct") {
    val snippet = new FwdDriver {
      override val prog = demo("bypass_ct")
    }
    check("bypass_ct", snippet, Verdict.Clean)
  }

  test("riscv forwarding bypass_late") {
    val snippet = new FwdDriver {
      override val prog = demo("bypass_late")
    }
    check("bypass_late", snippet, Verdict.Leak)
  }

  test("riscv forwarding dynstore") {
    val snippet = new FwdDriver {
      override val prog = demo("dynstore")
    }
    check("dynstore", snippet, Verdict.Clean)
  }

  test("riscv forwarding bypass_alias") {
    val snippet = new FwdDriver {
      override val prog = demo("bypass_alias")
    }
    check("bypass_alias", snippet, Verdict.Leak)
  }
}
