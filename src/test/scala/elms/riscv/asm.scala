package elms.koika.test.riscv

import org.scalatest.funsuite.AnyFunSuite

import RiscV.*
import asm.{Asm, Form, Image, Loc, Operand, Parse, Regs, Stmt}

// The frontend is plain Scala with no `Rep` anywhere in it, so this needs
// neither staging nor snapshots.
class RiscVAsmTests extends AnyFunSuite {
  private def image(src: String): Image =
    Asm.assemble("test.s", src.stripMargin).fold(es => fail(es.mkString("\n")), identity)

  private def prog(src: String): Vector[Instr] = image(src).prog

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

  test("label offsets count from the branch itself, in both directions") {
    val p = prog("""|back:
                    |  addi a0, a0, 1
                    |  beq a0, a1, fwd
                    |  jal x0, back
                    |fwd:""")
    // Forward and backward, so a resolver that dropped the sign cannot pass.
    assert(p(1) == Instr.Branch(Cmp.Eq, Reg(10), Reg(11), Imm(8)))
    assert(p(2) == Instr.Jal(x0, Imm(-8)))
  }

  test("a label at the bottom targets one past the last instruction") {
    val p = prog("""|  beq a0, a1, out
                    |  addi a0, a0, 1
                    |out:""")
    assert(p.length == 2)
    assert(p(0) == Instr.Branch(Cmp.Eq, Reg(10), Reg(11), Imm(8)))
  }

  test("a store names its value first") {
    assert(prog("sw a1, 8(sp)") == Vector(Instr.Store(Width.W, Reg(11), Reg(2), Imm(8))))
    assert(prog("lw a1, 8(sp)") == Vector(Instr.Load(Width.W, Reg(11), Reg(2), Imm(8))))
  }

  test("a hi and lo pair reaches a data symbol, sign extension included") {
    val a0 = Reg(10)
    val p = prog("""|  lui a0, %hi(far)
                    |  addi a0, a0, %lo(far)
                    |  .data
                    |near:
                    |  .zero 4000
                    |far:
                    |  .word 7""")
    assert(p == Vector(Instr.Lui(a0, Imm(1)), Instr.OpImm(AluOp.Add, a0, a0, Imm(-96))))
    // The rounding in `%hi` is correct only because `%lo` sign-extends.
    assert((1 << 12) + -96 == 4000)
  }

  test("a memory operand can carry a lo relocation") {
    val p = prog("""|  lbu a1, %lo(g)(a0)
                    |  .data
                    |  .zero 8
                    |g:
                    |  .byte 7""")
    assert(p == Vector(Instr.Load(Width.Bu, Reg(11), Reg(10), Imm(8))))
  }

  test("data directives lay out a little-endian word image") {
    val img = image("""|  .data
                       |g:
                       |  .word 1
                       |  .byte 2
                       |  .byte 3
                       |  .half 4
                       |s:
                       |  .asciz "ab"""")
    assert(img.data == Vector(1, 0x00040302, 0x00006261))
    assert(img.symbols("g") == 0)
    assert(img.symbols("s") == 8)
  }

  test("p2align pads a data section") {
    val img = image("""|  .data
                       |  .byte 1
                       |  .p2align 2, 0x0
                       |g:
                       |  .word 9""")
    assert(img.symbols("g") == 4)
    assert(img.data == Vector(1, 9))
  }

  test("caller-supplied constants stand in for the macros there are none of") {
    val src = """|  addi a0, x0, SECRET
                 |  addi a1, x0, SIZE"""
    val p = Asm
      .assemble("test.s", src.stripMargin, Map("SECRET" -> 80, "SIZE" -> 16))
      .fold(es => fail(es.mkString("\n")), _.prog)
    assert(p == Vector(
      Instr.OpImm(AluOp.Add, Reg(10), x0, Imm(80)),
      Instr.OpImm(AluOp.Add, Reg(11), x0, Imm(16))
    ))
  }

  test("the entry defaults to the first globl function, not the first globl") {
    val img = image("""|  .text
                       |  .globl secret
                       |  .type secret,@object
                       |  .globl cmp
                       |  .type cmp,@function
                       |pre:
                       |  addi x0, x0, 0
                       |cmp:
                       |  addi a0, x0, 1""")
    assert(img.entry == 1)
    assert(img.entries("pre") == 0)
  }
}
