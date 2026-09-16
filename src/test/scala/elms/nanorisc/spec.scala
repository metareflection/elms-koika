package elms.koika.test.nanorisc

import elms.prelude.*
import elms.prelude.given

import elms.koika.test.{KoikaSuite, Verdict}
import elms.koika.test.common.{Init, Speculative}

@virtualize
class SpecTests extends KoikaSuite {
  val under = "nanorisc/speculative/"

  trait SpecDriver extends NanoRiscDriver with Speculative {
    override val init = Init.speculative(stateT)
  }

  test("nanorisc spec shortcircuit") {
    val snippet = new SpecDriver {
      override val prog = NanoRiscDemos.build_shortcircuit_demo(secret_offset, 4)
    }
    check("shortcircuit", snippet, Verdict.Leak)
  }

  test("nanorisc spec 2ctr") {
    val snippet = new SpecDriver {
      override val prog = NanoRiscDemos.spec_small
    }
    check("2ctr", snippet, Verdict.Leak)
  }

  test("nanorisc spec spectre") {
    val snippet = new SpecDriver {
      override val prog = NanoRiscDemos.build_spectre_demo(secret_offset)
    }
    check("spectre", snippet, Verdict.Leak)
  }
}
