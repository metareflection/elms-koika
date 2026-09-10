package elms.koika.test.riscv

// RV32I, minus `JALR`, `FENCE`, `ECALL`, `EBREAK` and the CSR instructions.
// `JALR` is the interesting omission: its target is a register value, and the
// tower's program counter is a static `Int`, so a dynamic jump cannot be staged
// at all. Rather than ship a constructor whose semantics always throw, it is
// not in the ADT. The others have no meaning in this model.
object RiscV {
  // x0 reads as zero and swallows writes. Register names are static, so both
  // happen at staging time and the generated C never mentions regs[0].
  case class Reg(i: Int) derives CanEqual
  case class Imm(i: Int) derives CanEqual

  enum AluOp derives CanEqual {
    case Add, Sub, Sll, Slt, Sltu, Xor, Srl, Sra, Or, And
  }
  enum Cmp derives CanEqual { case Eq, Ne, Lt, Ge, Ltu, Geu }
  enum Width derives CanEqual { case B, H, W, Bu, Hu }

  // Branch and jump offsets are PC-relative in bytes, the way RISC-V assembly
  // writes them. They are static, so the conversion to an index into `prog`
  // happens at staging time.
  enum Instr derives CanEqual {
    case Op(op: AluOp, rd: Reg, rs1: Reg, rs2: Reg)
    case OpImm(op: AluOp, rd: Reg, rs1: Reg, imm: Imm)
    case Lui(rd: Reg, imm: Imm)
    case Auipc(rd: Reg, imm: Imm)
    case Jal(rd: Reg, offset: Imm)
    case Branch(cmp: Cmp, rs1: Reg, rs2: Reg, offset: Imm)
    case Load(w: Width, rd: Reg, rs1: Reg, imm: Imm)
    case Store(w: Width, rs2: Reg, rs1: Reg, imm: Imm)
  }

  val x0: Reg = Reg(0)
}
