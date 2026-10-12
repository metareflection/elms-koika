package elms.koika.test

import java.nio.file.{Files, Path}

import org.scalatest.funsuite.AnyFunSuite

import elms.koika.test.common.{Init, Predictive, Prover, Static}
import elms.koika.test.riscv.{RiscVDriver, elf}

// How many functions one pc is numbered into, against how many branches ran
// before it.
//
// [common.Predictive.Key] carries the predictor's whole history, so k branches
// can put 2^k of them in the table. Whether they do is what the three families
// out of `src/test/asm/riscv/fanout` separate, and the answer is not one
// answer:
//
//   straight    every entry is dead the moment it is written, because nothing
//               re-executes. The whole-map key still numbers one pc into many,
//               and [Predictive.liveHistoryOnly] takes it back to exactly what
//               a model with no history at all emits.
//   loop-same   every entry stays live, so there is nothing dead to drop and
//               the live key saves a few percent. What is left doubles per
//               branch and is the price of specializing at staging time.
//   loop-indep  the same, with all 2^k histories genuinely reachable rather
//               than two of them. It costs about what `loop-same` costs, which
//               is how one can tell the tower is counting branches rather than
//               machine states.
//
// Reads its objects out of a directory named by `KOIKA_FANOUT_DIR`, with one
// subdirectory per family. An environment variable and not a `-D`, because the
// tests fork and a property set on sbt's own JVM does not follow them; note
// that sbt's server outlives a run, so a changed value wants a `sbt shutdown`
// first. Skipped when it is unset.
class HistoryFanoutSuite extends AnyFunSuite {
  private val root = sys.env.get("KOIKA_FANOUT_DIR").map(Path.of(_))

  private def keys(c: String): Int = {
    val n = """\bslot_(\d+)\b""".r.findAllMatchIn(c).map(_.group(1).toInt).toVector
    // [Predictive.intern] hands out 0, 1, 2 ... in the order it is asked, so
    // the highest one emitted is a floor on how many it handed out.
    if (n.isEmpty) { 0 } else { n.max + 1 }
  }

  private def render(o: Path, history: Boolean, liveOnly: Boolean = false): String = {
    val image = elf.Elf.load(o.toString).prog
    val d =
      if (history) {
        new RiscVDriver[64] with Predictive {
          override val prog = image
          override val init = Init.speculative(stateT)
          override def liveHistoryOnly: Boolean = liveOnly
        }
      } else {
        new RiscVDriver[64] with Static {
          override val prog = image
          override val init = Init.speculative(stateT)
        }
      }
    d.render(Prover.CBMC)
  }

  // [k], and the slot count under each of the three keyings.
  private def sweep(family: String): Vector[(Int, Int, Int, Int)] = {
    val dir = root.get.resolve(family)
    (1 to 7).toVector.flatMap { k =>
      val o = dir.resolve(s"fanout$k.o")
      Option.when(Files.exists(o)) {
        val s = keys(render(o, history = false))
        val p = keys(render(o, history = true))
        val l = keys(render(o, history = true, liveOnly = true))
        info(f"$family%-11s k=$k%d  static $s%4d  full $p%4d (${p.toDouble / s}%4.1fx)" +
          f"  live $l%4d (${l.toDouble / s}%4.1fx)")
        (k, s, p, l)
      }
    }
  }

  private def check(family: String)(body: Vector[(Int, Int, Int, Int)] => Unit): Unit =
    test(s"$family: what the predictor's history costs") {
      assume(root.isDefined, "set KOIKA_FANOUT_DIR to run this")
      assume(Files.isDirectory(root.get.resolve(family)), s"no $family objects; run ./fanout")
      val got = sweep(family)
      assert(got.nonEmpty)
      // True of every family: restricting a key never splits one.
      got.foreach { case (_, s, p, l) => assert(l <= p && s <= p) }
      body(got)
    }

  // Dead entries are the whole of the difference here, so the live key lands
  // exactly on the no-history count, and the full key does not.
  check("straight") { got =>
    got.foreach { case (_, s, _, l) => assert(l == s) }
    assert(got.find(_._1 == 4).exists { case (_, s, p, _) => p > 3 * s })
  }

  // Nothing is dead, so the live key saves almost nothing and what is left
  // doubles per branch. This is the cost that belongs to specializing on the
  // history at all rather than to how the key is spelled.
  check("loop-same") { got =>
    got.foreach { case (_, s, p, l) => assert(l > s && l * 10 > p * 9) }
    assert(got.find(_._1 == 4).exists { case (_, s, _, l) => l > 12 * s })
  }

  // All 2^k histories reachable rather than two, and it costs within a quarter
  // of what two did. The table is counting branches and not machine states.
  check("loop-indep") { got =>
    got.foreach { case (_, s, _, l) => assert(l > s) }
    assert(got.find(_._1 == 4).exists { case (_, s, _, l) => l > 12 * s })
  }
}
