package elms.koika.test.mono

import elms.prelude.*
import elms.prelude.given
import org.scalatest.funsuite.AnyFunSuite

import elms.koika.test.common.{Cached, Forwarding, Init, Predictive, Prover, Static}
import elms.core.StructManifest
import elms.koika.test.common.{StateG, StateT}
import elms.koika.test.riscv.{RiscV, RiscVDriver, RiscVGhrDriver, RiscVShell, elf}

// `void crypto_poly1305(u8 mac[16], const u8 *message, size_t size, const u8 key[32])`
// a0 mac, a1 message, a2 size, a3 key.
//
// 80 words of memory: the deepest frame chain is crypto_poly1305's 96 bytes,
// crypto_poly1305_update's 16 and poly_blocks' 128, which is 60 words, and the
// four arguments take 16 more. [Driver.unwind] is one past `mem_size`, so a
// generous figure here is paid for by every file.
object PolyDriver {
  val obj = "src/test/mono/poly.o"
}

trait PolyShell[S: StructManifest] extends RiscVShell[96, S] {
  private val img = elf.Elf.load(PolyDriver.obj)
  val prog: Vector[RiscV.Instr] = img.prog

  // The object holds five functions and the entry is the last of them, so
  // pc 0 is `crypto_poly1305_init` and starting there would run the wrong
  // program. [Common.entryPc] is what names it and this is its first caller
  // in the tree; it arrives through [Exec], which this trait does not mix in,
  // so the two concrete classes below are where the override goes.
  protected def entryIndex: Int = img.entries("crypto_poly1305")

  private val macAt = 0
  private val msgAt = 4
  private val msgWords = 4
  private val keyAt = msgAt + msgWords

  // The key is the secret and the question: a different draw in each state.
  override lazy val initialize_secret: String =
    s"""
       |  for (int i=0; i<8; i++) {
       |    s1.mem[$keyAt + i] = secret(0, 255);
       |    s2.mem[$keyAt + i] = secret(0, 255);
       |  }""".stripMargin

  // Message, length and all three pointers are public: one draw into both
  // states. The thirteen branches are all on the length, so a public length is
  // what makes a clean answer the expected one.
  override lazy val initialize_input: String =
    s"""
       |  s1.regs[10] = ${4 * macAt};    s2.regs[10] = ${4 * macAt};
       |  s1.regs[11] = ${4 * msgAt};    s2.regs[11] = ${4 * msgAt};
       |  s1.regs[12] = ${4 * msgWords}; s2.regs[12] = ${4 * msgWords};
       |  s1.regs[13] = ${4 * keyAt};    s2.regs[13] = ${4 * keyAt};
       |  for (int i=0; i<$msgWords; i++) {
       |    int v = bounded(0, 255);
       |    s1.mem[$msgAt + i] = v;
       |    s2.mem[$msgAt + i] = v;
       |  }""".stripMargin
}

// Not a suite: no cell here declares a verdict, because nothing in this tree
// has produced one. It writes the five residues per backend into a directory
// a machine with more memory can run on its own. `-Dpoly.models=` picks which.
// The state every model but one takes.
abstract class PolyDriver extends RiscVDriver[96] with PolyShell[StateT[32, 96, 24, 12]] {
  override def entryPc: Int = entryIndex
}

// The same program over a state carrying a pattern history table.
//
// [predictive] keys a slot on the live part of the history, and `consulted`
// puts all thirteen of this object's branches into every pc's key, because
// six call sites each contribute the branches reachable after they return.
// That is 2^13 per pc against 1792 pcs. A register is bounded by its width
// instead, which is the whole claim `doc/global-history.md` makes and the
// first object in this tree where the bound is what makes staging possible.
abstract class PolyGhrDriver[P <: Int: ValueOf]
    extends RiscVGhrDriver[96, P]
    with PolyShell[StateG[32, 96, 24, 12, P]] {
  override def entryPc: Int = entryIndex
}

class PolyBundle extends AnyFunSuite {
  private val out = "/tmp/claude-1000/-home-cam-Documents-lms-elms-koika/99900c31-0fbb-4de2-947e-da00b445064b/scratchpad/poly-bundle"

  private def driver(model: String): PolyDriver = model match {
    case "naive"      => new PolyDriver { override val init = Init.Spilling.naive(stateT) }
    case "cache"      => new PolyDriver with Cached { override val init = Init.Spilling.cache(stateT) }
    case "static"     => new PolyDriver with Static {
        override val init = Init.Spilling.speculative(stateT)
      }
    case "predictive" => new PolyDriver with Predictive {
        override val init = Init.Spilling.speculative(stateT)
      }
    case _            => new PolyDriver with Forwarding {
        override val init = Init.Spilling.forwarding(stateT)
      }
  }

  // The register, at the only widths that stage. Thirteen branches want
  // `13 * 2^bits` table entries, and [Init.Spilling.globalHistory] rather than
  // [Init.globalHistory] because this program has a frame: the non-spilling one
  // leaves `sp` at zero and the first store goes through `mem[-1]`. CBMC runs
  // with `--no-standard-checks` and reports nothing; KLEE found it.
  private def ghr(bits: Int): PolyGhrDriver[?] = bits match {
    case 1 => new PolyGhrDriver[26] {
        override val init = Init.Spilling.globalHistory(stateT)
        override def historyBits: Int = 1
      }
    case _ => new PolyGhrDriver[52] {
        override val init = Init.Spilling.globalHistory(stateT)
        override def historyBits: Int = 2
      }
  }

  // Opt-in, for two reasons. The object it reads is a build artifact and is
  // gitignored, so a fresh checkout does not have one. And `predictive` and
  // `forwarding` do not finish staging in fifteen minutes, so a default run
  // would hang `testFull` rather than fail it.
  test("emit the bundle") {
    val want = sys.props.getOrElse("poly.models", "")
    if (want.isEmpty) {
      cancel("set -Dpoly.models=naive,cache,... to emit; see doc for why it is opt-in")
    }
    if (!java.nio.file.Files.exists(java.nio.file.Path.of(PolyDriver.obj))) {
      cancel(s"${PolyDriver.obj} is not built; run ./src/test/mono/build")
    }
    for (model <- want.split(",").toSeq) {
      val d = if (model.startsWith("ghr")) ghr(model.drop(3).toInt) else driver(model)
      for (p <- Seq(Prover.CBMC, Prover.KLEE, Prover.EVA)) {
        val c = d.render(p)
        val dir = java.nio.file.Path.of(out, p.toString.toLowerCase)
        java.nio.file.Files.createDirectories(dir)
        java.nio.file.Files.writeString(dir.resolve(s"$model.c"), c)
      }
      val c = d.render(Prover.CBMC)
      val n = """\bslot_(\d+)\b""".r.findAllMatchIn(c).map(_.group(1).toInt).max + 1
      info(f"$model%-11s slots=$n%5d lines=${c.linesIterator.size}%6d unwind=${d.unwind}%d")
    }
  }
}
