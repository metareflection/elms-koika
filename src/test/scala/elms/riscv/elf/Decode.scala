package elms.koika.test.riscv.elf

import elms.koika.test.riscv.RiscV
import RiscV.{AluOp, Cmp, Imm, Instr, Reg, Width}

// One word, decoded. [Ret] stands apart from [Instr] because `jalr x0, 0(x1)`
// only becomes a jump once the length of the program is known, and that is the
// reader's business rather than the decoder's.
enum Decoded derives CanEqual {
  case Insn(i: Instr)
  case Ret
}

// RV32I encodings, back to [RiscV.Instr]. No files, no ELF and no state, so the
// two scrambled immediate formats are testable on hand-written hex, which
// matters because the object files this feeds are generated and gitignored.
object Decode {
  // `jalr x0, 0(x1)`, the only dynamic jump with a static meaning.
  val ret: Int = 0x00008067

  def insn(word: Int): Either[String, Decoded] =
    if (word == ret) { Right(Decoded.Ret) } else { form(word).map(Decoded.Insn(_)) }

  private def bits(w: Int, hi: Int, lo: Int): Int = (w >>> lo) & ((1 << (hi - lo + 1)) - 1)

  private def sext(v: Int, width: Int): Int = (v << (32 - width)) >> (32 - width)

  // I-type sign-extends the top twelve bits, so the arithmetic shift is the
  // whole decode.
  private def iImm(w: Int): Int = w >> 20

  private def sImm(w: Int): Int = sext((bits(w, 31, 25) << 5) | bits(w, 11, 7), 12)

  // `imm[12|10:5]` in bits 31:25 and `imm[4:1|11]` in bits 11:7, with bit 0
  // implicitly zero. Scrambled so that B and S keep the same bits of the
  // immediate in the same places wherever they can.
  private def bImm(w: Int): Int = sext(
    (bits(w, 31, 31) << 12) | (bits(w, 7, 7) << 11) | (bits(w, 30, 25) << 5) |
      (bits(w, 11, 8) << 1),
    13
  )

  // `imm[20|10:1|11|19:12]` in bits 31:12, the same trick against U-type.
  private def jImm(w: Int): Int = sext(
    (bits(w, 31, 31) << 20) | (bits(w, 19, 12) << 12) | (bits(w, 20, 20) << 11) |
      (bits(w, 30, 21) << 1),
    21
  )

  // The *unshifted* twenty bits, because [Exec] does the shifting itself.
  private def uImm(w: Int): Int = bits(w, 31, 12)

  private val alu: Map[(Int, Int), AluOp] = Map(
    (0, 0x00) -> AluOp.Add,
    (0, 0x20) -> AluOp.Sub,
    (1, 0x00) -> AluOp.Sll,
    (2, 0x00) -> AluOp.Slt,
    (3, 0x00) -> AluOp.Sltu,
    (4, 0x00) -> AluOp.Xor,
    (5, 0x00) -> AluOp.Srl,
    (5, 0x20) -> AluOp.Sra,
    (6, 0x00) -> AluOp.Or,
    (7, 0x00) -> AluOp.And
  )

  private val cmps: Map[Int, Cmp] =
    Map(0 -> Cmp.Eq, 1 -> Cmp.Ne, 4 -> Cmp.Lt, 5 -> Cmp.Ge, 6 -> Cmp.Ltu, 7 -> Cmp.Geu)

  private val loads: Map[Int, Width] =
    Map(0 -> Width.B, 1 -> Width.H, 2 -> Width.W, 4 -> Width.Bu, 5 -> Width.Hu)

  private val stores: Map[Int, Width] = Map(0 -> Width.B, 1 -> Width.H, 2 -> Width.W)

  private def form(w: Int): Either[String, Instr] = {
    val rd = Reg(bits(w, 11, 7))
    val rs1 = Reg(bits(w, 19, 15))
    val rs2 = Reg(bits(w, 24, 20))
    val funct3 = bits(w, 14, 12)
    val funct7 = bits(w, 31, 25)
    val shamt = bits(w, 24, 20)

    def pick[K, V](table: Map[K, V], key: K, what: String): Either[String, V] =
      table.get(key).toRight(f"0x$w%08x is not an RV32I $what")

    bits(w, 6, 0) match {
      case 0x37 => Right(Instr.Lui(rd, Imm(uImm(w))))
      case 0x17 => Right(Instr.Auipc(rd, Imm(uImm(w))))
      case 0x6f => Right(Instr.Jal(rd, Imm(jImm(w))))
      case 0x63 => pick(cmps, funct3, "branch").map(Instr.Branch(_, rs1, rs2, Imm(bImm(w))))
      case 0x03 => pick(loads, funct3, "load").map(Instr.Load(_, rd, rs1, Imm(iImm(w))))
      case 0x23 => pick(stores, funct3, "store").map(Instr.Store(_, rs2, rs1, Imm(sImm(w))))
      // A shift-immediate's `funct7` discriminates `srli` from `srai` rather
      // than forming part of the immediate, so its shamt is the low five bits.
      case 0x13 if funct3 == 1 || funct3 == 5 =>
        pick(alu, (funct3, funct7), "shift").map(Instr.OpImm(_, rd, rs1, Imm(shamt)))
      case 0x13 => pick(alu, (funct3, 0x00), "op-imm").map(Instr.OpImm(_, rd, rs1, Imm(iImm(w))))
      case 0x33 if funct7 == 0x01 => Left("RV32M is out of scope; rebuild with -march=rv32i")
      case 0x33 => pick(alu, (funct3, funct7), "op").map(Instr.Op(_, rd, rs1, rs2))
      // Every other `jalr` reads its target out of a register, and the tower's
      // program counter is a static `Int`, so there is nothing to stage.
      case 0x67 => Left("`jalr` jumps to a register value, which a static pc cannot follow")
      case 0x0f => Left("`fence` has nothing to order in this model")
      case 0x73 => Left("`ecall`, `ebreak` and the CSRs are out of scope")
      case _    => Left(f"no RV32I instruction encodes as 0x$w%08x")
    }
  }
}
