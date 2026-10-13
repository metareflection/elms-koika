package elms.koika.test.mono

import elms.prelude.*
import elms.prelude.given

import elms.core.StructManifest

import elms.koika.test.Verdict
import elms.koika.test.common.{StateG, StateT}
import elms.koika.test.riscv.{RiscV, RiscVDriver, RiscVGhrDriver, RiscVShell, elf}

// One of the four objects `src/test/mono/build` produces, and what every model
// owes it.
//
// [Expect] has the five columns `fact/Driver.scala` has rather than the seven
// `riscv/pht.scala` has, for the same reason that one does: this is a question
// about what a compiler emitted, and the answer does not need a machine that
// reorders loads to be interesting.
case class Expect(
    naive: Verdict,
    cache: Verdict,
    static: Verdict,
    predictive: Verdict,
    forwarding: Verdict
) derives CanEqual

object Expect {
  def uniform(v: Verdict): Expect = Expect(v, v, v, v, v)
}

// [name] is both the object under `src/test/mono` and the label on the
// snapshot. [stack] is the frame the object spills, which the layout leaves
// room for, and it is the tell: the two variants that keep `volatile` spill
// sixteen bytes to hold a mask the optimizer is not allowed to fold, and the
// two that leak have no frame at all.
case class Program(name: String, stack: Int, expect: Expect) derives CanEqual

object Program {
  // The four variants of `src/test/mono/ccopy.c`, which is where the whole
  // story is written down.
  //
  // `shipped` and `volatile` are the clean pair and `unrolled` and `plain` are
  // the leaking one, which is not the split the library's own comment predicts.
  // It names two mitigations and says either works alone; `unrolled` is the one
  // that keeps only the unrolling, and it leaks exactly as hard as keeping
  // neither.
  val all: List[Program] = List(
    Program("shipped", stack = 16, expect = Expect.uniform(Verdict.Clean)),
    Program("volatile", stack = 16, expect = Expect.uniform(Verdict.Clean)),
    Program("unrolled", stack = 0, expect = Expect.uniform(Verdict.Leak)),
    Program("plain", stack = 0, expect = Expect.uniform(Verdict.Leak))
  )
}

// `void ccopy_X(fe f, const fe g, const fe h, const fe k)`, four pointers to
// ten words each.
//
// A fixed signature rather than `fact/Driver.scala`'s [Param] list, because all
// four objects have this one and nothing here has to describe a second shape.
// What it keeps from that file is the threat model: a pointer the caller chose
// is public and identical in both runs, and only what it points at is drawn
// twice.
trait MonoShell[S: StructManifest] extends RiscVShell[64, S] {
  def program: Program

  // [program] is a constructor parameter of the class that mixes this in,
  // and a parameter accessor is assigned before the superclass constructor
  // runs, so it is readable here. A `val` in a subclass body would not be.
  val prog: Vector[RiscV.Instr] =
    elf.Elf.load(s"src/test/mono/${program.name}.o").prog

  private val limbs = 10

  // f, g, h, k stacked from the bottom of `mem` in argument order, and the
  // frame comes off the top. Nothing in the object constrains either choice.
  private val at: List[Int] = List(0, limbs, 2 * limbs, 3 * limbs)

  require(
    4 * limbs + (program.stack + 3) / 4 <= mem_size,
    s"${program.name} wants more than $mem_size words of memory"
  )

  // The bound is load bearing and not a knob, which is `fscalar_product`'s
  // lesson in `fact/Driver.scala` applied here.
  //
  // What the two runs can disagree about is `f[0] == h[0]` and `f[1] == k[1]`,
  // and those are the only values that reach control flow. Drawn from a wide
  // range the two are never equal in either run, every branch goes the same way
  // both times, and a checker proves clean about a program whose only
  // interesting path it was told to skip. One bit each is what makes both
  // outcomes reachable.
  private val condBound = 1
  // The limbs being copied are not compared against anything, so their range
  // only has to be wide enough to be a draw.
  private val limbBound = 20

  // a0, f: the accumulator `fe_ccopy` conditionally overwrites, and the operand
  // whose first two words decide the condition. a1, g: the other candidate.
  // Both secret.
  override lazy val initialize_secret: String =
    s"""
       |  // a10's contents, secret: a different draw in each state. f[0] and
       |  // f[1] are what the comparisons read, so they draw against
       |  // $condBound and the rest against $limbBound.
       |  s1.mem[${at(0)}] = secret(0, $condBound);
       |  s2.mem[${at(0)}] = secret(0, $condBound);
       |  s1.mem[${at(0) + 1}] = secret(0, $condBound);
       |  s2.mem[${at(0) + 1}] = secret(0, $condBound);
       |  for (int i=2; i<$limbs; i++) {
       |    s1.mem[${at(0)} + i] = secret(0, $limbBound);
       |    s2.mem[${at(0)} + i] = secret(0, $limbBound);
       |  }
       |  // a11's contents, secret: the value copied in, drawn separately
       |  for (int i=0; i<$limbs; i++) {
       |    s1.mem[${at(1)} + i] = secret(0, $limbBound);
       |    s2.mem[${at(1)} + i] = secret(0, $limbBound);
       |  }""".stripMargin

  // a2 and a3 stand in for the constants `invsqrt` compares its quartic
  // against, so they are public: one draw written into both states.
  override lazy val initialize_input: String = {
    val regs = at.zipWithIndex
      .map { case (w, i) =>
        s"""
           |  // a${10 + i}, $limbs words: the address is public
           |  s1.regs[${10 + i}] = ${4 * w};
           |  s2.regs[${10 + i}] = ${4 * w};""".stripMargin
      }
      .mkString
    val public = List(at(2), at(3))
      .map { w =>
        s"""
           |  // its contents, public: the same draw in both states
           |  for (int i=0; i<$limbs; i++) {
           |    int v = bounded(0, $condBound);
           |    s1.mem[$w + i] = v;
           |    s2.mem[$w + i] = v;
           |  }""".stripMargin
      }
      .mkString
    regs + public
  }
}

// The four objects over the state every model but one takes.
abstract class MonoDriver(val program: Program)
    extends RiscVDriver[64]
    with MonoShell[StateT[32, 64, 24, 12]]

// The same four over a state that carries a pattern history table.
//
// [P] is spelled at the use site rather than fixed here, because what the
// table has to hold is the program's branch count times `2^historyBits` and
// the two objects that leak have twelve branches where the two that do not
// have none.
abstract class MonoGhrDriver[P <: Int: ValueOf](val program: Program)
    extends RiscVGhrDriver[64, P]
    with MonoShell[StateG[32, 64, 24, 12, P]]
