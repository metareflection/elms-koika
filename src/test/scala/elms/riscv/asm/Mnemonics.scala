package elms.koika.test.riscv.asm

import elms.koika.test.riscv.RiscV
import RiscV.{AluOp, Cmp, Imm, Instr, Reg, Width, x0}

// What each mnemonic means.
object Mnemonics {
  def insn(m: String, ops: List[Operand]): Either[String, List[Slot]] = {
    def shaped[A](s: Option[A])(f: A => List[Slot]): Either[String, List[Slot]] =
      s.map(f).toRight(s"`$m` does not take these operands")

    m match {
      case _ if aluR.contains(m) =>
        shaped(rrr(ops))((rd, a, b) => one(Instr.Op(aluR(m), rd, a, b)))
      case _ if aluI.contains(m) =>
        shaped(rri(ops))((rd, a, f) => hole(f)(Instr.OpImm(aluI(m), rd, a, _)))
      case _ if branches.contains(m) =>
        shaped(rrl(ops))((a, b, f) => hole(f)(Instr.Branch(branches(m), a, b, _)))
      case _ if loads.contains(m) =>
        shaped(rm(ops))((rd, f, base) => hole(f)(Instr.Load(loads(m), rd, base, _)))
      case _ if stores.contains(m) =>
        shaped(rm(ops))((rs, f, base) => hole(f)(Instr.Store(stores(m), rs, base, _)))
      case "lui"   => shaped(ri(ops))((rd, f) => hole(f)(Instr.Lui(rd, _)))
      case "auipc" => shaped(ri(ops))((rd, f) => hole(f)(Instr.Auipc(rd, _)))
      // Dropping the link register is how `jal` is written when the return
      // address is wanted in `ra`, which is the only place it ever goes.
      case "jal" =>
        if (ops.length == 1) { shaped(lbl(ops))(f => hole(f)(Instr.Jal(Reg(1), _))) }
        else { shaped(rl(ops))((rd, f) => hole(f)(Instr.Jal(rd, _))) }

      case _ => Left(s"unknown mnemonic `$m`")
    }
  }

  private def one(i: Instr): List[Slot] = List(Slot.Fixed(i))
  private def hole(f: Fixup)(fill: Imm => Instr): List[Slot] = List(Slot.Open(f, fill))

  // An immediate position: a number, an absolute symbol value, or one half of a
  // `%hi`/`%lo` pair.
  private def imm(o: Operand): Option[Fixup] = o match {
    case Operand.Num(v)    => Some(Fixup.Lit(v))
    case Operand.Sym(n, k) => Some(Fixup.Abs(n, k))
    case Operand.Hi(n, k)  => Some(Fixup.Hi(n, k))
    case Operand.Lo(n, k)  => Some(Fixup.Lo(n, k))
    case Operand.R(_)      => None
    case Operand.Mem(_, _) => None
  }

  // A branch or jump target, where a bare symbol means the offset to it rather
  // than its own value.
  private def tgt(o: Operand): Option[Fixup] = o match {
    case Operand.Sym(n, k) => Some(Fixup.Rel(n, k))
    case Operand.Num(v)    => Some(Fixup.Lit(v))
    case _                 => None
  }

  private def rrr(ops: List[Operand]): Option[(Reg, Reg, Reg)] = ops match {
    case List(Operand.R(a), Operand.R(b), Operand.R(c)) => Some((a, b, c))
    case _                                              => None
  }
  private def rri(ops: List[Operand]): Option[(Reg, Reg, Fixup)] = ops match {
    case List(Operand.R(a), Operand.R(b), o) => imm(o).map(f => (a, b, f))
    case _                                   => None
  }
  private def ri(ops: List[Operand]): Option[(Reg, Fixup)] = ops match {
    case List(Operand.R(a), o) => imm(o).map(f => (a, f))
    case _                     => None
  }
  private def rm(ops: List[Operand]): Option[(Reg, Fixup, Reg)] = ops match {
    case List(Operand.R(a), Operand.Mem(o, base)) => imm(o).map(f => (a, f, base))
    case _                                        => None
  }
  private def rl(ops: List[Operand]): Option[(Reg, Fixup)] = ops match {
    case List(Operand.R(a), o) => tgt(o).map(f => (a, f))
    case _                     => None
  }
  private def rrl(ops: List[Operand]): Option[(Reg, Reg, Fixup)] = ops match {
    case List(Operand.R(a), Operand.R(b), o) => tgt(o).map(f => (a, b, f))
    case _                                   => None
  }
  private def lbl(ops: List[Operand]): Option[Fixup] = ops match {
    case List(o) => tgt(o)
    case _       => None
  }

  private val aluR: Map[String, AluOp] = Map(
    "add" -> AluOp.Add,
    "sub" -> AluOp.Sub,
    "sll" -> AluOp.Sll,
    "slt" -> AluOp.Slt,
    "sltu" -> AluOp.Sltu,
    "xor" -> AluOp.Xor,
    "srl" -> AluOp.Srl,
    "sra" -> AluOp.Sra,
    "or" -> AluOp.Or,
    "and" -> AluOp.And
  )

  private val aluI: Map[String, AluOp] = Map(
    "addi" -> AluOp.Add,
    "slti" -> AluOp.Slt,
    "sltiu" -> AluOp.Sltu,
    "xori" -> AluOp.Xor,
    "ori" -> AluOp.Or,
    "andi" -> AluOp.And,
    "slli" -> AluOp.Sll,
    "srli" -> AluOp.Srl,
    "srai" -> AluOp.Sra
  )

  private val branches: Map[String, Cmp] = Map(
    "beq" -> Cmp.Eq,
    "bne" -> Cmp.Ne,
    "blt" -> Cmp.Lt,
    "bge" -> Cmp.Ge,
    "bltu" -> Cmp.Ltu,
    "bgeu" -> Cmp.Geu
  )

  private val loads: Map[String, Width] = Map(
    "lb" -> Width.B,
    "lh" -> Width.H,
    "lw" -> Width.W,
    "lbu" -> Width.Bu,
    "lhu" -> Width.Hu
  )

  private val stores: Map[String, Width] =
    Map("sb" -> Width.B, "sh" -> Width.H, "sw" -> Width.W)
}
