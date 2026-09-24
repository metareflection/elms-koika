package elms.koika.test.riscv

import elms.prelude.*
import elms.prelude.given

import elms.koika.test.{KoikaSuite, Verdict}
import elms.koika.test.common.{Forwarding, Init}

// Every demo the rest of the tower runs, against a model with a store queue in
// front of the cache.
//
// A program with no store in it is as much the point as one with. A model that
// only ever adds a channel has to leave such a program alone, and every
// storeless demo here is its `predictive` twin to the byte.
//
// `bypass.s` and `bypass_ct.s` are where this column says something of its own,
// and `bypass_late.s` is where the store window opens on a branch window's way
// out.
@virtualize
class RiscVForwardingTests extends KoikaSuite {
  val under = "riscv/forwarding/"

  trait FwdDriver extends RiscVDriver[64] with Forwarding {
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

  // The eviction set. Inherited from [Cached] rather than added by this model,
  // the way most of this column is.
  test("riscv forwarding evict") {
    val snippet = new FwdDriver {
      override val prog = demo("evict")
    }
    check("evict", snippet, Verdict.Leak)
  }

  // The same channel as `2ctr` with a loop after it long enough to hide the
  // miss. `hidden.s` says which way each column is meant to answer and why.
  test("riscv forwarding hidden") {
    val snippet = new FwdDriver {
      override val prog = demo("hidden")
    }
    check("hidden", snippet, Verdict.Leak)
  }

  // `spectre.s` with the reload step. Nothing this model adds is in it: there
  // is no store, so this snapshot is its `predictive` twin to the byte.
  test("riscv forwarding reload") {
    val snippet = new FwdDriver {
      override val prog = demo("reload")
    }
    check("reload", snippet, Verdict.Leak)
  }

  // No store in the program, so this snapshot is its `predictive` twin to the
  // byte and the leak is the misprediction that column already reports.
  test("riscv forwarding balanced") {
    val snippet = new FwdDriver {
      override val prog = demo("balanced")
    }
    check("balanced", snippet, Verdict.Leak)
  }
}
