package elms.koika.test.riscv

import org.scalatest.funsuite.AnyFunSuite

import RiscV.*
import elf.{Decode, Decoded}

// The decoder is plain Scala over hand-written hex, so this needs neither
// staging, nor snapshots, nor a RISC-V toolchain on the box. Every literal here
// came out of `llvm-objdump -d` on clang's own output.
class RiscVDecodeTests extends AnyFunSuite {
  private def insn(word: Int): Instr = Decode.insn(word) match {
    case Right(Decoded.Insn(i)) => i
    case Right(Decoded.Ret)     => fail(f"0x$word%08x decoded as `ret`")
    case Left(e)                => fail(e)
  }

  private def why(word: Int): String =
    Decode.insn(word).fold(identity, d => fail(s"0x${word.toHexString} decoded as $d"))

  private def offset(i: Instr): Int = i match {
    case Instr.Branch(_, _, _, o) => o.i
    case Instr.Jal(_, o)          => o.i
    case _                        => fail(s"$i carries no pc-relative offset")
  }

  private def decodes(cases: (Int, Instr)*): Unit =
    assert(cases.filter((w, i) => insn(w) != i).map((w, _) => f"0x$w%08x") == Vector())

  test("the register-register ALU ops, one per funct3 and funct7") {
    decodes(
      0x015a09b3 -> Instr.Op(AluOp.Add, Reg(19), Reg(20), Reg(21)),
      0x418b8b33 -> Instr.Op(AluOp.Sub, Reg(22), Reg(23), Reg(24)),
      0x01bd1cb3 -> Instr.Op(AluOp.Sll, Reg(25), Reg(26), Reg(27)),
      0x01eeae33 -> Instr.Op(AluOp.Slt, Reg(28), Reg(29), Reg(30)),
      0x0020bfb3 -> Instr.Op(AluOp.Sltu, Reg(31), Reg(1), Reg(2)),
      0x005241b3 -> Instr.Op(AluOp.Xor, Reg(3), Reg(4), Reg(5)),
      0x0083d333 -> Instr.Op(AluOp.Srl, Reg(6), Reg(7), Reg(8)),
      0x40b554b3 -> Instr.Op(AluOp.Sra, Reg(9), Reg(10), Reg(11)),
      0x00e6e633 -> Instr.Op(AluOp.Or, Reg(12), Reg(13), Reg(14)),
      0x011877b3 -> Instr.Op(AluOp.And, Reg(15), Reg(16), Reg(17))
    )
  }

  // `srai` sets bit 30, so reading a shift-immediate the I-type way would give
  // 1031 rather than 7. `funct7` is the discriminator there and part of the
  // immediate everywhere else.
  test("the immediate ALU ops, and a shift takes a shamt rather than an immediate") {
    decodes(
      0xfef10093 -> Instr.OpImm(AluOp.Add, Reg(1), Reg(2), Imm(-17)),
      0xffb52493 -> Instr.OpImm(AluOp.Slt, Reg(9), Reg(10), Imm(-5)),
      0x00563593 -> Instr.OpImm(AluOp.Sltu, Reg(11), Reg(12), Imm(5)),
      0x0ff74693 -> Instr.OpImm(AluOp.Xor, Reg(13), Reg(14), Imm(255)),
      0xf0086793 -> Instr.OpImm(AluOp.Or, Reg(15), Reg(16), Imm(-256)),
      0x00197893 -> Instr.OpImm(AluOp.And, Reg(17), Reg(18), Imm(1)),
      0x01f21193 -> Instr.OpImm(AluOp.Sll, Reg(3), Reg(4), Imm(31)),
      0x00145393 -> Instr.OpImm(AluOp.Srl, Reg(7), Reg(8), Imm(1)),
      0x40735293 -> Instr.OpImm(AluOp.Sra, Reg(5), Reg(6), Imm(7))
    )
  }

  test("the six branch conditions") {
    decodes(
      0x04208863 -> Instr.Branch(Cmp.Eq, Reg(1), Reg(2), Imm(80)),
      0x04419663 -> Instr.Branch(Cmp.Ne, Reg(3), Reg(4), Imm(76)),
      0x0462c463 -> Instr.Branch(Cmp.Lt, Reg(5), Reg(6), Imm(72)),
      0x0483d263 -> Instr.Branch(Cmp.Ge, Reg(7), Reg(8), Imm(68)),
      0x04a4e063 -> Instr.Branch(Cmp.Ltu, Reg(9), Reg(10), Imm(64)),
      0x02c5fe63 -> Instr.Branch(Cmp.Geu, Reg(11), Reg(12), Imm(60))
    )
  }

  // A store names its value register in `rs2` and its base in `rs1`, which is
  // the reverse of how the assembly reads.
  test("loads and stores, signed and unsigned") {
    decodes(
      0x00410083 -> Instr.Load(Width.B, Reg(1), Reg(2), Imm(4)),
      0xffc21183 -> Instr.Load(Width.H, Reg(3), Reg(4), Imm(-4)),
      0x00832283 -> Instr.Load(Width.W, Reg(5), Reg(6), Imm(8)),
      0x00144383 -> Instr.Load(Width.Bu, Reg(7), Reg(8), Imm(1)),
      0x00255483 -> Instr.Load(Width.Hu, Reg(9), Reg(10), Imm(2)),
      0x00110223 -> Instr.Store(Width.B, Reg(1), Reg(2), Imm(4)),
      0xfe321e23 -> Instr.Store(Width.H, Reg(3), Reg(4), Imm(-4)),
      0x00532423 -> Instr.Store(Width.W, Reg(5), Reg(6), Imm(8))
    )
  }

  // [Exec] shifts these itself, `unit(imm.i << 12)`, so the twenty bits arrive
  // unshifted and unsigned. `lui ra, 0xfffff` is the one that says which.
  test("lui and auipc keep the unshifted twenty bits") {
    decodes(
      0xfffff0b7 -> Instr.Lui(Reg(1), Imm(0xfffff)),
      0x00001137 -> Instr.Lui(Reg(2), Imm(1)),
      0x12345197 -> Instr.Auipc(Reg(3), Imm(0x12345))
    )
  }

  test("a branch offset is sign-extended, in both directions") {
    val back = insn(0xfe0594e3)
    val fwd = insn(0x0a059263)
    assert(back == Instr.Branch(Cmp.Ne, Reg(11), Reg(0), Imm(-24)))
    assert(fwd == Instr.Branch(Cmp.Ne, Reg(11), Reg(0), Imm(164)))
    // Two offsets of the same sign would leave half of the scramble untested.
    assert(offset(back) < 0 && offset(fwd) > 0)
  }

  test("a jump offset is sign-extended, in both directions") {
    val back = insn(0xff1ff06f)
    val fwd = insn(0x00c000ef)
    assert(back == Instr.Jal(Reg(0), Imm(-16)))
    assert(fwd == Instr.Jal(Reg(1), Imm(12)))
    assert(offset(back) < 0 && offset(fwd) > 0)
  }

  // `ret` is `jalr x0, 0(x1)`, and it is the only `jalr` whose target the reader
  // can work out without running the program.
  test("ret is its own thing, and every other jalr is an error") {
    assert(Decode.insn(Decode.ret) == Right(Decoded.Ret))
    // `jalr a0, 0(a1)`, `jalr x0, 4(x1)` and `jr a0`.
    assert(why(0x00058567).contains("register value"))
    assert(why(0x00408067).contains("register value"))
    assert(why(0x00050067).contains("register value"))
  }

  test("what the tower does not decode says what to do about it") {
    assert(why(0x023100b3).contains("-march=rv32i"))
    assert(why(0x0ff0000f).contains("`fence`"))
    assert(why(0x00000073).contains("out of scope"))
    // A `lw` with no width, and a compressed instruction, neither of which has
    // a fix to suggest.
    assert(why(0x00033283).contains("not an RV32I load"))
    assert(why(0x00004501).contains("no RV32I instruction"))
  }
}
