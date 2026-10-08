package elms.koika.test.riscv

import elms.prelude.*
import elms.prelude.given

import elms.core.StructManifest

import elms.koika.test.{KoikaSuite, Verdict}
import elms.koika.test.common.{Init, Static, StateT}
import elms.koika.test.squared.StateT2
import elf.{Datum, Taint}

// How an argument register is drawn, and what the C calls the draw.
//
// Two of the three take their bound out of the image rather than from the test
// site, because both bounds are facts about where the linker put things and a
// number written down in Scala would be a second copy of one.
enum Arg derives CanEqual {
  // As many words as the attacker's own array holds. `cmp`'s argument is how
  // many to compare, and anything larger walks off the end of a global.
  case Count(name: String)
  // An index into the attacker's array, drawn far enough past the end of it to
  // reach the secret behind it. Anything smaller reads the attacker's own data
  // back, which is what would make a Spectre gadget leak nothing.
  case Index(name: String)
  // A scalar the image says nothing about.
  case Word(name: String, bound: Int)
}

// A program that came out of a C compiler rather than out of someone's head.
// [objectFile] says which one and [args] says what the caller left in a0, a1
// and so on; everything else is read back out of the image, because the
// section headers are where the threat model actually lives.
//
// [objectFile] is a `def` and the members derived from it are lazy, because a
// subclass supplies it from a constructor parameter and the parameter is the
// only thing set before this trait's body runs. [prog] is the exception and
// cannot be lazy, since [Common] declares it a `val`, which is what pins the
// parameter down to a parameter.
trait CompiledShell[S: StructManifest] extends RiscVShell[64, S] {
  def objectFile: String
  def args: List[Arg]

  private lazy val image = elf.Elf.load(objectFile)
  val prog: Vector[RiscV.Instr] = image.prog

  private def base(d: Datum): Int = d.addr / 4
  private def length(d: Datum): Int = d.size / 4
  private def span(d: Datum): Range = base(d) until (base(d) + length(d))

  // Sorted by address, because a [Map]'s iteration order would otherwise put
  // the register writes in the generated C in `hashCode` order.
  private def tainted(t: Taint): Seq[(String, Datum)] =
    image.globals.toSeq.filter((_, d) => d.taint == t).sortBy((_, d) => d.addr)

  private lazy val secrets = tainted(Taint.Secret)
  private lazy val attackers = tainted(Taint.Attacker)

  // Words a `bounded(…)` is about to write, so the image's own bytes for them
  // are noise. Emitting them anyway is how the hand-written version came to
  // set `mem[0..3] = 11, 22, 33, 44` and then bury them one line later.
  private lazy val nondet: Set[Int] =
    (secrets ++ attackers).flatMap((_, d) => span(d)).toSet

  // `init` zeroes `mem`, so only the nonzero words need writing.
  private lazy val publicData: String = {
    val lines = image.data.zipWithIndex
      .filter((w, i) => w != 0 && !nondet(i))
      .map((w, i) => s"  s1.mem[$i] = $w;\n  s2.mem[$i] = $w;")
    if (lines.isEmpty) { "" }
    else { s"\n  // public data, where the section headers put it\n${lines.mkString("\n")}" }
  }

  // One draw, written into both states. The attacker chose it, and both runs
  // face the same attacker.
  private def shared(name: String, d: Datum): String =
    s"""
       |  // $name, the attacker's: the same draw in both states
       |  for (int i=0; i<${length(d)}; i++) {
       |    int v = bounded(0, 20);
       |    s1.mem[${base(d)} + i] = v;
       |    s2.mem[${base(d)} + i] = v;
       |  }""".stripMargin

  // Two draws. The whole question is whether the timer can tell them apart.
  private def split(name: String, d: Datum): String =
    s"""
       |  // $name, secret: a different draw in each state
       |  for (int i=0; i<${length(d)}; i++) {
       |    s1.mem[${base(d)} + i] = secret(0, 20);
       |    s2.mem[${base(d)} + i] = secret(0, 20);
       |  }""".stripMargin

  // Both arrays are the same length, so the attacker's own size is the bound.
  private lazy val count: Int = attackers.map((_, d) => length(d)).minOption.getOrElse(0)

  // The largest index that still lands inside a secret, counted from whichever
  // attacker array the linker put closest under one. The `require` is the
  // demo's premise and not a sanity check: an [Arg.Index] into an array with
  // nothing secret above it draws a number that cannot leak.
  private lazy val reach: Int = {
    val lowest = secrets.map((_, d) => d.addr).minOption
    val highest = secrets.map((_, d) => d.addr + d.size).maxOption
    val under = attackers.map((_, d) => d.addr).filter(a => lowest.exists(a < _))
    require(
      highest.isDefined && under.nonEmpty,
      s"$objectFile has no attacker array under a secret, so an index reaches nothing"
    )
    (highest.get - under.max) / 4 - 1
  }

  private def drawn(a: Arg, reg: Int): String = {
    val (name, hi) = a match {
      case Arg.Count(n)      => (n, count)
      case Arg.Index(n)      => (n, reach)
      case Arg.Word(n, bund) => (n, bund)
    }
    s"""
       |  int $name = bounded(0, $hi);
       |  s1.regs[$reg] = $name;
       |  s2.regs[$reg] = $name;""".stripMargin
  }

  // Arguments and the attacker's arrays are public, so they are identical in
  // the two runs and only the secret differs. Folded in here rather than given
  // its own hook, because `main` already interpolates this string.
  override lazy val initialize_input: String = {
    val regs = args.zipWithIndex.map((a, i) => drawn(a, 10 + i)).mkString
    s"$publicData$regs${attackers.map(shared).mkString}"
  }

  override lazy val initialize_secret: String = secrets.map(split).mkString
}

// The C, the command that compiled it, and why it is `-O1` are all in
// `src/test/asm/riscv/cmp.c`. `cmp`'s argument is how many words to compare.
//
// At file scope rather than inside the suite, because it is the longest and
// branchiest demo in the tree and so the one anything measuring a checker wants
// to reach for.
trait CmpShell[S: StructManifest] extends CompiledShell[S] {
  override def objectFile: String = "src/test/asm/riscv/cmp.o"
  override def args: List[Arg] = List(Arg.Count("n"))
}

trait CompiledDriver extends RiscVDriver[64] with CmpShell[StateT[32, 64, 24, 12]]

// The same demo, run in step.
trait SquaredCompiledDriver
    extends SquaredRiscVDriver[64]
    with CmpShell[StateT2[32, 64, 24, 12]]

@virtualize
class RiscVCompiledTests extends KoikaSuite {
  val under = "riscv/compiled/"

  test("riscv compiled naive") {
    val snippet = new CompiledDriver {
      override val init = Init.naive(stateT)
    }
    check("naive", snippet, Verdict.Leak)
  }

  test("riscv compiled static") {
    val snippet = new CompiledDriver with Static {
      override val init = Init.speculative(stateT)
    }
    check("static", snippet, Verdict.Leak)
  }

  // [PredictiveDriver] already carries the `init` the other two spell out, plus
  // the predictor's own field, so there is nothing left to say here.
  test("riscv compiled predictive") {
    val snippet = new CompiledDriver with PredictiveDriver {}
    check("predictive", snippet, Verdict.Leak)
  }
}
