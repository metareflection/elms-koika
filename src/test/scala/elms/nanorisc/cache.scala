package elms.koika.test.nanorisc

import elms.prelude.*
import elms.prelude.given

import elms.koika.test.{KoikaSuite, Verdict}
import elms.koika.test.common.{Cached, Init}

@virtualize
class CacheTests extends KoikaSuite {
  val under = "nanorisc/cache/"

  trait CacheDriver extends NanoRiscDriver with Cached {
    override val init = Init.cache(stateT)
  }

  test("nanorisc cache shortcircuit") {
    val snippet = new CacheDriver {
      override val prog = NanoRiscDemos.build_shortcircuit_demo(secret_offset, 4)
    }
    check("shortcircuit", snippet, Verdict.Leak)
  }

  test("nanorisc cache 2ctr") {
    val snippet = new CacheDriver {
      override val prog = NanoRiscDemos.spec_small
    }
    check("2ctr", snippet, Verdict.Leak)
  }

  test("nanorisc cache spectre") {
    val snippet = new CacheDriver {
      override val prog = NanoRiscDemos.build_spectre_demo(secret_offset)
    }
    check("spectre", snippet, Verdict.Clean)
  }
}
