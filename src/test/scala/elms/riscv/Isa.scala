package elms.koika.test.riscv

// RV32I plus RV32M's four multiplies, minus `FENCE`, `ECALL`, `EBREAK` and the
// CSR instructions, which have no meaning in this model. `div` and `rem` are
// the rest of RV32M and are not here.
//
// `JALR` appears only in the two shapes a compiler emits it in. An
// `auipc`/`jalr` pair with no relocation left on it has a target the reader can
// compute, so it arrives here as [Call] with a static index. A `jalr x0, 0(x1)`
// arrives as [Ret], whose target is whichever [Call] is on the staging-time
// return stack. Every other `jalr` reads an address the reader cannot predict
// and is still rejected where it sits.
object RiscV {
  // x0 reads as zero and swallows writes. Register names are static, so both
  // happen at staging time and the generated C never mentions regs[0].
  case class Reg(i: Int) derives CanEqual
  case class Imm(i: Int) derives CanEqual

  enum AluOp derives CanEqual {
    case Add, Sub, Sll, Slt, Sltu, Xor, Srl, Sra, Or, And
  }
  // Separate from [AluOp] because there is no `muli` and nothing here shares a
  // shape with an op-imm. `div` and `rem` stay out: nothing measured needs
  // them, and a divider's data-dependent latency is a different question from a
  // multiplier's.
  enum MulOp derives CanEqual { case Mul, Mulh, Mulhsu, Mulhu }
  enum Cmp derives CanEqual { case Eq, Ne, Lt, Ge, Ltu, Geu }
  enum Width derives CanEqual { case B, H, W, Bu, Hu }

  // Branch and jump offsets are PC-relative in bytes, the way RISC-V assembly
  // writes them. They are static, so the conversion to an index into `prog`
  // happens at staging time.
  enum Instr derives CanEqual {
    case Op(op: AluOp, rd: Reg, rs1: Reg, rs2: Reg)
    case Mul(op: MulOp, rd: Reg, rs1: Reg, rs2: Reg)
    case OpImm(op: AluOp, rd: Reg, rs1: Reg, imm: Imm)
    case Lui(rd: Reg, imm: Imm)
    case Auipc(rd: Reg, imm: Imm)
    case Jal(rd: Reg, offset: Imm)
    case Branch(cmp: Cmp, rs1: Reg, rs2: Reg, offset: Imm)
    case Load(w: Width, rd: Reg, rs1: Reg, imm: Imm)
    case Store(w: Width, rs2: Reg, rs1: Reg, imm: Imm)
    // A direct call. [target] is an index into `prog`, not a byte offset, and
    // the reader has already done the arithmetic that an `auipc` and a `jalr`
    // between them encode.
    case Call(rd: Reg, target: Int)
    // A return. Where it goes is not in the instruction: it is the top of the
    // return stack the tower carries at staging time, and `rs1` holding
    // something else is an assertion in the residue rather than a second edge.
    case Ret
  }

  val x0: Reg = Reg(0)
}
