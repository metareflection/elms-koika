package elms.koika.test.riscv

import elms.prelude.*
import elms.prelude.given

import elms.koika.test.{KoikaSuite, Taint, Verdict}
import elms.koika.test.common.{Cached, Geometry, GenericKoikaDriver, Init, Level}

// The cache this tower used to have, spelled as a geometry: one set of two
// ways over one-word lines, with nothing underneath it.
//
// It exists to be the control for `evict.s`. That demo's whole claim is that
// the channel is a set conflict rather than an address, and a claim about what
// a model cannot see is worth a test rather than a paragraph: run the same
// program against a cache with no sets in it and the leak has to disappear.
//
// The costs are not the old model's and cannot be. That one charged 0 for the
// head of its LRU and 1 for the tail, which is a channel of its own and one no
// real cache has, since a hit is a hit whichever way answered it.
@virtualize
class RiscVFlatTests extends KoikaSuite {
  val under = "riscv/flat/"

  trait FlatDriver extends GenericKoikaDriver[32, 64, 2, 2] with Exec with Cached {
    override def geometry: Geometry =
      Geometry(lineWords = 1, levels = Vector(Level("flat", sets = 1, ways = 2, hitCost = 1)))

    override val codegen = elms.codegen.CCodegen(
      elms.codegen.Config.cDefault.copy(varPrefix = "v")
    )
    override val init = Init.cache(stateT)
    override lazy val initialize_input: String =
      s"""
         |  int x = bounded(0, ${4 * secret_offset});
         |  s1.regs[10] = x;
         |  s2.regs[10] = x;""".stripMargin
    def demo(name: String): Vector[RiscV.Instr] =
      elf.Elf.load(s"src/test/asm/riscv/$name.o").prog
  }

  // The set conflict, invisible without sets. Eva still sees the secret reach
  // `cache_age`, which is the over-approximation rather than a second channel.
  test("riscv flat evict") {
    val snippet = new FlatDriver {
      override val prog = demo("evict")
    }
    check("evict", snippet, Verdict.Clean, eva = Taint.Widens)
  }

  // The control for the control. `2ctr` leaks through an address rather than
  // through a set, so a cache with one set still reports it and this suite is
  // not just a model too weak to see anything.
  test("riscv flat 2ctr") {
    val snippet = new FlatDriver {
      override val prog = demo("2ctr")
    }
    check("2ctr", snippet, Verdict.Leak)
  }
}
