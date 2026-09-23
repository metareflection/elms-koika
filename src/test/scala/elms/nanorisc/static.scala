package elms.koika.test.nanorisc

import elms.prelude.*
import elms.prelude.given

import elms.koika.test.{KoikaSuite, Verdict}
import elms.koika.test.common.{Init, Static}

@virtualize
class StaticTests extends KoikaSuite {
  val under = "nanorisc/static/"

  trait StaticDriver extends NanoRiscDriver with Static {
    override val init = Init.speculative(stateT)
  }

  test("nanorisc static shortcircuit") {
    val snippet = new StaticDriver {
      override val prog = NanoRiscDemos.build_shortcircuit_demo(secret_offset, 4)
    }
    check("shortcircuit", snippet, Verdict.Leak)
  }

  test("nanorisc static 2ctr") {
    val snippet = new StaticDriver {
      override val prog = NanoRiscDemos.spec_small
    }
    check("2ctr", snippet, Verdict.Leak)
  }

  test("nanorisc static spectre") {
    val snippet = new StaticDriver {
      override val prog = NanoRiscDemos.build_spectre_demo(secret_offset)
    }
    check("spectre", snippet, Verdict.Leak)
  }
}
