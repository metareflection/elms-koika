package elms.koika.test

import org.scalatest.funsuite.AnyFunSuite

import elms.prelude.*
import elms.prelude.given

import elms.koika.test.common.{Init, Prover}
import elms.koika.test.riscv.{RiscV, RiscVDriver, SquaredRiscVDriver, elf}
import elms.koika.test.squared.{Chip, FlatRun, Outcome}

// A program with a call in it, through both towers.
//
// `twocall.o` reaches one callee from two sites, and that is the whole
// question. The return stack is staging-time, so the callee is emitted once
// per site and each copy comes back somewhere different. A tower that keyed
// its slots on pc alone would emit one copy, and nothing downstream would
// notice: the residue would be well formed, a checker would report SUCCESS,
// and the program it checked would be a program that returns to the same
// place twice.
//
// Not a snapshot suite. What is worth pinning here is the shape, and the
// numbering underneath it moves whenever anything upstream allocates a node.
//
// The verdict, at `--unwind 65`: `naive`, `predictive` and the squared tower
// all report SUCCESS on this object, `return address` included. Editing one
// predicted address in the residue by hand turns that one into a FAILURE, so
// it is live rather than true for want of anything to say.
@virtualize
class CallSuite extends AnyFunSuite {
  private val image = elf.Elf.load("src/test/asm/riscv/twocall.o")
  private val rec = elf.Elf.load("src/test/asm/riscv/rec.o")

  // `victim` is not a leaf, so it spills `ra` into a frame, and a frame below
  // a stack pointer of zero indexes `mem` at `(-4) >>> 2`. Every other demo in
  // the tree is built so this never comes up, and `cmp.c` says in its header
  // that -O1 is what keeps it away. A demo with a call in it cannot dodge it,
  // so the driver has to put `sp` somewhere a frame fits.
  private def arrive(words: Int): String =
    s"""
       |  s1.regs[2] = ${4 * words};
       |  s2.regs[2] = ${4 * words};
       |  int x = bounded(0, 7);
       |  s1.regs[10] = x;
       |  s2.regs[10] = x;""".stripMargin

  private trait Demo extends RiscVDriver[64] {
    override val prog = image.prog
    override val init = Init.Spilling.naive(stateT)
    override lazy val initialize_input: String = arrive(mem_size)
  }

  // What each `ret` site in the residue asserts `regs[1]` holds. Read out of
  // the C rather than off the tower, because the question is what a checker
  // will see.
  private def predicted(c: String): Vector[Int] =
    """== (\d+);\s*ret_assert\(""".r.findAllMatchIn(c).map(_.group(1).toInt).toVector

  // The instruction a return address comes back to is one past a call, so this
  // is where a prediction is checked against the program rather than against
  // another copy of itself.
  private def calls(at: Int): Boolean = image.prog(at / 4 - 1) match {
    case RiscV.Instr.Call(_, _) => true
    case _                      => false
  }

  test("the callee is staged once per call site, and each copy returns somewhere else") {
    val got = predicted(new Demo {}.render(Prover.CBMC))
    assert(got.length == 2)
    // One slot shared between the two sites would show up here as one
    // constant twice.
    assert(got.distinct.length == 2)
    assert(got.forall(a => a % 4 == 0 && calls(a)))
  }

  // The squared residue carries the same obligation twice, once per run,
  // because it is each run's own and not a comparison between them. Both
  // against the same constant, which is what makes fusing the return sound.
  test("the squared tower checks the return address in both runs") {
    val got = predicted(new SquaredRiscVDriver[64] {
      override val prog = image.prog
      override val init = Init.Spilling.naive(stateT)
      override lazy val initialize_input: String = arrive(mem_size)
    }.render(Prover.CBMC))
    assert(got.length == 4)
    assert(got.distinct.length == 2)
    assert(got.groupBy(identity).values.forall(_.length == 2))
    assert(got.forall(calls))
  }

  // A pc that comes back to itself grows the stack forever, and every frame is
  // a fresh slot key, so without the cap the worklist never empties and the
  // symptom is sbt sitting there.
  test("recursion is refused at staging, and the message says it is recursion") {
    val e = intercept[RuntimeException] {
      new Demo { override val prog = rec.prog }.render(Prover.CBMC)
    }
    assert(e.getMessage.contains("recursion"))
  }

  // The same object, under a cap low enough that `victim` calling `down` trips
  // it before `down` has reached itself. A chain of distinct pcs is a program
  // that nests too deep, and raising the cap is the fix rather than the thing
  // that cannot help, so the two cases say different things.
  test("merely nesting too deep says to raise the cap instead") {
    val e = intercept[RuntimeException] {
      new Demo {
        override val prog = rec.prog
        override def maxCallDepth = 1
      }.render(Prover.CBMC)
    }
    assert(e.getMessage.contains("maxCallDepth"))
    assert(!e.getMessage.contains("recursion"))
  }

  // The interpreter walks the same rules the residue is made of, so it is the
  // cheap place for a wrong return address to show up. [Run.returnsTo] is a
  // `require` rather than an [Outcome] because a run that comes back somewhere
  // the stack did not predict is a program this walk models wrong, and there
  // is nothing left for it to report.
  test("the interpreter walks both calls and stays in step") {
    val run = FlatRun(image.prog)
    def chip(secret: Int): Chip = {
      val c = run.blank
      c.regs(2) = 4 * run.mem_size
      c.regs(10) = 3
      for (i <- 0 until 8) { c.mem(i) = secret }
      c
    }
    assert(run(chip(1), chip(2)).isInstanceOf[Outcome.InStep])
  }
}
