package elms.koika.test.riscv

import org.scalatest.funsuite.AnyFunSuite

import RiscV.*
import asm.{Form, Loc, Operand, Parse, Regs, Stmt}

// The frontend is plain Scala with no `Rep` anywhere in it, so this needs
// neither staging nor snapshots.
class RiscVAsmTests extends AnyFunSuite {
  private def op(s: String): Operand = Parse.operand(s).fold(e => fail(e), identity)
  private def why(s: String): String = Parse.operand(s).fold(identity, _ => "")

  test("ABI register names and xN agree") {
    val abi = Vector(
      "zero", "ra", "sp", "gp", "tp", "t0", "t1", "t2", "s0", "s1", "a0", "a1", "a2", "a3",
      "a4", "a5", "a6", "a7", "s2", "s3", "s4", "s5", "s6", "s7", "s8", "s9", "s10", "s11",
      "t3", "t4", "t5", "t6"
    )
    assert(abi.length == 32)
    assert(abi.zipWithIndex.filter((n, i) => Regs.byName(n) != Reg(i)) == Vector())
    assert(Regs.byName("fp") == Regs.byName("s0"))
  }

  test("a comment runs to end of line, but not out of a string") {
    val (stmts, errors) = Parse.stmts("t.s", "  nop # nop\n  .asciz \"a#b\"")
    assert(errors == Nil)
    assert(stmts == List(
      Stmt(Loc("t.s", 1), Form.Insn("nop", Nil)),
      Stmt(Loc("t.s", 2), Form.Dir(".asciz", List("\"a#b\"")))
    ))
  }

  test("labels peel off the front of the line they share") {
    val (stmts, _) = Parse.stmts("t.s", "sum:  # @sum\nouter: inner: nop")
    assert(stmts == List(
      Stmt(Loc("t.s", 1), Form.Label("sum")),
      Stmt(Loc("t.s", 2), Form.Label("outer")),
      Stmt(Loc("t.s", 2), Form.Label("inner")),
      Stmt(Loc("t.s", 2), Form.Insn("nop", Nil))
    ))
  }

  test("a memory operand takes the last paren group") {
    assert(op("8(sp)") == Operand.Mem(Operand.Num(8), Reg(2)))
    assert(op("-8(s0)") == Operand.Mem(Operand.Num(-8), Reg(8)))
    // Bare `(sp)` leaves the displacement empty, which means zero.
    assert(op("(sp)") == Operand.Mem(Operand.Num(0), Reg(2)))
    // The split has to be greedy: clang writes the relocation and the base as
    // two paren groups in a row.
    assert(op("%lo(g)(a1)") == Operand.Mem(Operand.Lo("g", 0), Reg(11)))
  }

  test("symbols, addends and the number bases gas writes") {
    assert(op("g") == Operand.Sym("g", 0))
    assert(op(".LBB0_2") == Operand.Sym(".LBB0_2", 0))
    assert(op("g+8") == Operand.Sym("g", 8))
    assert(op("g-8") == Operand.Sym("g", -8))
    assert(op("%hi(g+8)") == Operand.Hi("g", 8))
    assert(op("17") == Operand.Num(17))
    assert(op("-17") == Operand.Num(-17))
    assert(op("0x10") == Operand.Num(16))
  }

  // `-fpic` output reaches a global through `%pcrel_hi`/`%pcrel_lo` instead,
  // which needs the `auipc` that defined the label and is out of scope.
  test("a PIC relocation says what to rebuild with") {
    assert(why("%pcrel_hi(g)").contains("-fno-pic"))
    assert(why("%pcrel_lo(.Lpcrel_hi0)").contains("-fno-pic"))
  }
}
