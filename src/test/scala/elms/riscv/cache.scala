package elms.koika.test.riscv

import elms.prelude.*
import elms.prelude.given

import elms.koika.test.{KoikaSuite, Taint, Verdict}
import elms.koika.test.common.{Cached, Init}

@virtualize
class RiscVCacheTests extends KoikaSuite {
  val under = "riscv/cache/"

  trait CacheDriver extends RiscVDriver[64] with Cached {
    override val init = Init.cache(stateT)
  }

  test("riscv cache shortcircuit") {
    val snippet = new CacheDriver {
      override val prog = demo("shortcircuit")
    }
    check("shortcircuit", snippet, Verdict.Leak)
  }

  test("riscv cache 2ctr") {
    val snippet = new CacheDriver {
      override val prog = demo("2ctr")
    }
    check("2ctr", snippet, Verdict.Leak)
  }

  test("riscv cache spectre") {
    val snippet = new CacheDriver {
      override val prog = demo("spectre")
    }
    check("spectre", snippet, Verdict.Clean)
  }

  test("riscv cache constant_time") {
    val snippet = new CacheDriver {
      override val prog = demo("constant_time")
    }
    check("constant_time", snippet, Verdict.Clean)
  }

  test("riscv cache bypass") {
    val snippet = new CacheDriver {
      override val prog = demo("bypass")
    }
    check("bypass", snippet, Verdict.Clean, eva = Taint.Widens)
  }

  test("riscv cache bypass_ct") {
    val snippet = new CacheDriver {
      override val prog = demo("bypass_ct")
    }
    check("bypass_ct", snippet, Verdict.Clean)
  }

  test("riscv cache bypass_late") {
    val snippet = new CacheDriver {
      override val prog = demo("bypass_late")
    }
    check("bypass_late", snippet, Verdict.Clean, eva = Taint.Widens)
  }

  test("riscv cache dynstore") {
    val snippet = new CacheDriver {
      override val prog = demo("dynstore")
    }
    check("dynstore", snippet, Verdict.Clean)
  }

  test("riscv cache bypass_alias") {
    val snippet = new CacheDriver {
      override val prog = demo("bypass_alias")
    }
    check("bypass_alias", snippet, Verdict.Clean)
  }

  // The eviction set, which is the demo the geometry exists for.
  test("riscv cache evict") {
    val snippet = new CacheDriver {
      override val prog = demo("evict")
    }
    check("evict", snippet, Verdict.Leak)
  }

  // The same channel as `2ctr` with a loop after it long enough to hide the
  // miss. `hidden.s` says which way each column is meant to answer and why.
  test("riscv cache hidden") {
    val snippet = new CacheDriver {
      override val prog = demo("hidden")
    }
    check("hidden", snippet, Verdict.Leak)
  }

  // `spectre.s` with the reload step. The gadget is behind a branch this model
  // never guesses past, so the only load it runs is the probe and both runs
  // miss on it.
  test("riscv cache reload") {
    val snippet = new CacheDriver {
      override val prog = demo("reload")
    }
    check("reload", snippet, Verdict.Clean)
  }

  // The balanced branch again. Neither arm touches memory and the program's one
  // load is at a public address, so a cache has nothing to say about which way
  // the branch went.
  test("riscv cache balanced") {
    val snippet = new CacheDriver {
      override val prog = demo("balanced")
    }
    check("balanced", snippet, Verdict.Clean, eva = Taint.Widens)
  }
}
