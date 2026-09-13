package elms.koika.test.nanorisc

import elms.prelude.*
import elms.prelude.given

import elms.koika.test.{KoikaSuite, Verdict}
import elms.koika.test.common.{GenericKoikaDriver, StateT}

@virtualize
class NaiveTests extends KoikaSuite {
  val under = "nanorisc/naive/"

  trait NaiveDriver extends GenericKoikaDriver[StateT, StateT] with Exec {
    // In the naive driver, we don't use caching or speculation, so we don't
    // need to initialize everything except [regs], [timer] and [mem].
    override val init = s"""void init(struct $stateT *s) {
         |  for (int i=0; i<NUM_REGS; i++) {
         |    s->regs[i] = 0;
         |  }
         |  s->timer = 0;
         |  for (int i=0; i<MEM_SIZE; i++) {
         |    s->mem[i] = 0;
         |  }
         |}""".stripMargin
  }

  test("nanorisc naive shortcircuit") {
    val snippet = new NaiveDriver {
      override val prog = NanoRiscDemos.build_shortcircuit_demo(secret_offset, 4)
    }
    check("shortcircuit", snippet.code, Verdict.Leak)
  }

  test("nanorisc naive 2ctr") {
    val snippet = new NaiveDriver {
      override val prog = NanoRiscDemos.spec_small
    }
    check("2ctr", snippet.code, Verdict.Clean)
  }

  test("nanorisc naive spectre") {
    val snippet = new NaiveDriver {
      override val prog = NanoRiscDemos.build_spectre_demo(secret_offset)
    }
    check("spectre", snippet.code, Verdict.Clean)
  }
}
