package elms.koika.test.riscv

import elms.prelude.*
import elms.prelude.given

import elms.koika.test.{KoikaSuite, Verdict}
import elms.koika.test.common.Init

@virtualize
class RiscVNaiveTests extends KoikaSuite {
  val under = "riscv/naive/"

  trait NaiveDriver extends RiscVDriver[64] {
    // In the naive driver, we don't use caching or speculation, so we don't
    // need to initialize everything except [regs], [timer] and [mem].
    override val init = Init.naive(stateT)
  }

  test("riscv naive shortcircuit") {
    val snippet = new NaiveDriver {
      override val prog = demo("shortcircuit")
    }
    check("shortcircuit", snippet, Verdict.Leak)
  }

  test("riscv naive 2ctr") {
    val snippet = new NaiveDriver {
      override val prog = demo("2ctr")
    }
    check("2ctr", snippet, Verdict.Clean)
  }

  test("riscv naive spectre") {
    val snippet = new NaiveDriver {
      override val prog = demo("spectre")
    }
    check("spectre", snippet, Verdict.Clean)
  }

  test("riscv naive constant_time") {
    val snippet = new NaiveDriver {
      override val prog = demo("constant_time")
    }
    check("constant_time", snippet, Verdict.Clean)
  }

  test("riscv naive bypass") {
    val snippet = new NaiveDriver {
      override val prog = demo("bypass")
    }
    check("bypass", snippet, Verdict.Clean)
  }

  test("riscv naive bypass_ct") {
    val snippet = new NaiveDriver {
      override val prog = demo("bypass_ct")
    }
    check("bypass_ct", snippet, Verdict.Clean)
  }

  test("riscv naive bypass_late") {
    val snippet = new NaiveDriver {
      override val prog = demo("bypass_late")
    }
    check("bypass_late", snippet, Verdict.Clean)
  }

  test("riscv naive dynstore") {
    val snippet = new NaiveDriver {
      override val prog = demo("dynstore")
    }
    check("dynstore", snippet, Verdict.Clean)
  }

  test("riscv naive bypass_alias") {
    val snippet = new NaiveDriver {
      override val prog = demo("bypass_alias")
    }
    check("bypass_alias", snippet, Verdict.Clean)
  }

  // The eviction set. `evict.s` says what it needs from the geometry; nothing
  // here has a cache in front of it, so nothing here can see it.
  test("riscv naive evict") {
    val snippet = new NaiveDriver {
      override val prog = demo("evict")
    }
    check("evict", snippet, Verdict.Clean)
  }

  // The same channel as `2ctr` with a loop after it long enough to hide the
  // miss. Nothing here has a cache in front of it, so there was never a miss
  // to hide and the instruction count is the same either way.
  test("riscv naive hidden") {
    val snippet = new NaiveDriver {
      override val prog = demo("hidden")
    }
    check("hidden", snippet, Verdict.Clean)
  }

  // `spectre.s` with the reload step, which is the demo that says the channel
  // is the cache line rather than the stall. Nothing here has either.
  test("riscv naive reload") {
    val snippet = new NaiveDriver {
      override val prog = demo("reload")
    }
    check("reload", snippet, Verdict.Clean)
  }
}
