package elms.koika.test.riscv

import elms.prelude.*
import elms.prelude.given

import elms.koika.test.{KoikaSuite, Verdict}
import elms.koika.test.common.{Init, NonBlocking}

@virtualize
class RiscVNonBlockingTests extends KoikaSuite {
  val under = "riscv/nonblocking/"

  trait NbDriver extends RiscVDriver[64] with NonBlocking {
    override val init = Init.nonblocking(stateT)
  }

  test("riscv nonblocking 2ctr") {
    val snippet = new NbDriver {
      override val prog = demo("2ctr")
    }
    check("2ctr", snippet, Verdict.Leak)
  }

  test("riscv nonblocking constant_time") {
    val snippet = new NbDriver {
      override val prog = demo("constant_time")
    }
    check("constant_time", snippet, Verdict.Clean)
  }

  // The same channel as `2ctr` with a loop after it long enough to hide the
  // miss. `hidden.s` says which way each column is meant to answer and why.
  test("riscv nonblocking hidden") {
    val snippet = new NbDriver {
      override val prog = demo("hidden")
    }
    check("hidden", snippet, Verdict.Clean)
  }
}
