package elms.koika.test.nanorisc

import elms.prelude.*
import elms.prelude.given

import elms.koika.test.{KoikaSuite, Verdict}
import elms.koika.test.common.Init

@virtualize
class NaiveTests extends KoikaSuite {
  val under = "nanorisc/naive/"

  trait NaiveDriver extends NanoRiscDriver {
    // In the naive driver, we don't use caching or speculation, so we don't
    // need to initialize everything except [regs], [timer] and [mem].
    override val init = Init.naive(stateT)
  }

  test("nanorisc naive shortcircuit") {
    val snippet = new NaiveDriver {
      override val prog = NanoRiscDemos.build_shortcircuit_demo(secret_offset, 4)
    }
    check("shortcircuit", snippet, Verdict.Leak)
  }

  test("nanorisc naive 2ctr") {
    val snippet = new NaiveDriver {
      override val prog = NanoRiscDemos.spec_small
    }
    check("2ctr", snippet, Verdict.Clean)
  }

  test("nanorisc naive spectre") {
    val snippet = new NaiveDriver {
      override val prog = NanoRiscDemos.build_spectre_demo(secret_offset)
    }
    check("spectre", snippet, Verdict.Clean)
  }
}
