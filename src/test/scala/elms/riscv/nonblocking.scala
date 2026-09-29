package elms.koika.test.riscv

import elms.prelude.*
import elms.prelude.given

import elms.koika.test.{KoikaSuite, Taint, Verdict}
import elms.koika.test.common.{Init, NonBlocking}

@virtualize
class RiscVNonBlockingTests extends KoikaSuite {
  val under = "riscv/nonblocking/"

  trait NbDriver extends RiscVDriver[64] with NonBlocking {
    override val init = Init.nonblocking(stateT)
  }

  test("riscv nonblocking shortcircuit") {
    val snippet = new NbDriver {
      override val prog = demo("shortcircuit")
    }
    check("shortcircuit", snippet, Verdict.Leak)
  }

  test("riscv nonblocking 2ctr") {
    val snippet = new NbDriver {
      override val prog = demo("2ctr")
    }
    check("2ctr", snippet, Verdict.Leak)
  }

  test("riscv nonblocking spectre") {
    val snippet = new NbDriver {
      override val prog = demo("spectre")
    }
    check("spectre", snippet, Verdict.Clean)
  }

  test("riscv nonblocking constant_time") {
    val snippet = new NbDriver {
      override val prog = demo("constant_time")
    }
    check("constant_time", snippet, Verdict.Clean)
  }

  test("riscv nonblocking bypass") {
    val snippet = new NbDriver {
      override val prog = demo("bypass")
    }
    check("bypass", snippet, Verdict.Clean, eva = Taint.Widens)
  }

  test("riscv nonblocking bypass_ct") {
    val snippet = new NbDriver {
      override val prog = demo("bypass_ct")
    }
    check("bypass_ct", snippet, Verdict.Clean)
  }

  test("riscv nonblocking bypass_late") {
    val snippet = new NbDriver {
      override val prog = demo("bypass_late")
    }
    check("bypass_late", snippet, Verdict.Clean, eva = Taint.Widens)
  }

  test("riscv nonblocking dynstore") {
    val snippet = new NbDriver {
      override val prog = demo("dynstore")
    }
    check("dynstore", snippet, Verdict.Clean)
  }

  test("riscv nonblocking bypass_alias") {
    val snippet = new NbDriver {
      override val prog = demo("bypass_alias")
    }
    check("bypass_alias", snippet, Verdict.Clean)
  }

  // The second row this model takes away, and nobody wrote a demo for it.
  // `evict`'s gap is the eleven cycles between answering the probe out of L1
  // and out of L2, and the load that carries the secret into a set is still
  // outstanding when that probe issues. So the eleven land inside a hundred
  // that is already being paid for, and both runs retire at 205.
  //
  // `cache/evict` leaking is what keeps this honest: an edit that flattened
  // the eviction set would make this clean for a reason that has nothing to do
  // with the model.
  test("riscv nonblocking evict") {
    val snippet = new NbDriver {
      override val prog = demo("evict")
    }
    check("evict", snippet, Verdict.Clean, eva = Taint.Widens)
  }

  // The same channel as `2ctr` with a loop after it long enough to hide the
  // miss. `hidden.s` says which way each column is meant to answer and why.
  test("riscv nonblocking hidden") {
    val snippet = new NbDriver {
      override val prog = demo("hidden")
    }
    check("hidden", snippet, Verdict.Clean, eva = Taint.Widens)
  }

  // `spectre.s` with the reload step. No speculation here, so the gadget never
  // runs and the probe misses in both runs.
  test("riscv nonblocking reload") {
    val snippet = new NbDriver {
      override val prog = demo("reload")
    }
    check("reload", snippet, Verdict.Clean)
  }

  // Clean, for the reason `naive` and `cache` are. Nothing in this column
  // speculates, so neither arm pays a penalty the other does not, and the one
  // load's address is public so the miss costs both runs the same whichever
  // way the branch went.
  test("riscv nonblocking balanced") {
    val snippet = new NbDriver {
      override val prog = demo("balanced")
    }
    check("balanced", snippet, Verdict.Clean, eva = Taint.Widens)
  }
}
