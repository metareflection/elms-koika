package elms.koika.test.riscv.asm

import elms.koika.test.riscv.RiscV
import RiscV.{AluOp, Cmp, Imm, Instr, Reg, Width, x0}

// What each mnemonic means, real and pseudo, and what to tell someone who wrote
// one this tower has no home for.
object Mnemonics {
  def insn(
      m: String,
      ops: List[Operand],
      consts: Map[String, Int]
  ): Either[String, List[Slot]] = {
    def bad: Either[String, List[Slot]] = Left(s"`$m` does not take these operands")
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

      case "nop" => if (ops.isEmpty) { Right(one(Instr.OpImm(AluOp.Add, x0, x0, Imm(0)))) }
        else { bad }
      // `ret` targets one past the last instruction, where [Common.call] hands
      // the state back unchanged. For a leaf function with its result already
      // in `a0`, that is exactly returning.
      case "ret" => if (ops.isEmpty) { Right(hole(Fixup.End)(Instr.Jal(x0, _))) } else { bad }
      case "j"   => shaped(lbl(ops))(f => hole(f)(Instr.Jal(x0, _)))
      case "mv"  => shaped(rr(ops))((rd, rs) => one(Instr.OpImm(AluOp.Add, rd, rs, Imm(0))))
      case "not" => shaped(rr(ops))((rd, rs) => one(Instr.OpImm(AluOp.Xor, rd, rs, Imm(-1))))
      case "neg" => shaped(rr(ops))((rd, rs) => one(Instr.Op(AluOp.Sub, rd, x0, rs)))
      case "seqz" => shaped(rr(ops))((rd, rs) => one(Instr.OpImm(AluOp.Sltu, rd, rs, Imm(1))))
      case "snez" => shaped(rr(ops))((rd, rs) => one(Instr.Op(AluOp.Sltu, rd, x0, rs)))
      case "sltz" => shaped(rr(ops))((rd, rs) => one(Instr.Op(AluOp.Slt, rd, rs, x0)))
      case "sgtz" => shaped(rr(ops))((rd, rs) => one(Instr.Op(AluOp.Slt, rd, x0, rs)))
      case _ if zeroBranches.contains(m) =>
        shaped(rl(ops))((rs, f) => hole(f)(Instr.Branch(zeroBranches(m), rs, x0, _)))
      case "blez" => shaped(rl(ops))((rs, f) => hole(f)(Instr.Branch(Cmp.Ge, x0, rs, _)))
      case "bgtz" => shaped(rl(ops))((rs, f) => hole(f)(Instr.Branch(Cmp.Lt, x0, rs, _)))
      case _ if swapped.contains(m) =>
        shaped(rrl(ops))((a, b, f) => hole(f)(Instr.Branch(swapped(m), b, a, _)))
      case "li" => ops match {
          case List(Operand.R(rd), o) => value(o, consts).map(v => li(rd, v))
          case _                      => bad
        }
      case "la" | "lla" => ops match {
          case List(Operand.R(rd), Operand.Sym(n, k)) =>
            Right(
              hole(Fixup.Hi(n, k))(Instr.Lui(rd, _)) ++
                hole(Fixup.Lo(n, k))(Instr.OpImm(AluOp.Add, rd, rd, _))
            )
          case _ => bad
        }

      case _ => Left(unsupported.getOrElse(m, s"unknown mnemonic `$m`"))
    }
  }

  private def one(i: Instr): List[Slot] = List(Slot.Fixed(i))
  private def hole(f: Fixup)(fill: Imm => Instr): List[Slot] = List(Slot.Open(f, fill))

  // `li` is one instruction when the value fits the twelve-bit immediate and two
  // when it does not, and that is the whole reason resolution needs two passes.
  private def li(rd: Reg, v: Int): List[Slot] =
    if (v >= -2048 && v <= 2047) { one(Instr.OpImm(AluOp.Add, rd, x0, Imm(v))) }
    else {
      // [Exec] does the shifting, so [Lui] takes the unshifted twenty bits and
      // the `addi` has to be the sign-extended low twelve for the rounding in
      // `hi` to cancel.
      val hi = ((v + 0x800) >>> 12) & 0xfffff
      val lo = (v << 20) >> 20
      if (lo == 0) { one(Instr.Lui(rd, Imm(hi))) }
      else { one(Instr.Lui(rd, Imm(hi))) ++ one(Instr.OpImm(AluOp.Add, rd, rd, Imm(lo))) }
    }

  // `li`'s width depends on its value, and pass 1 needs the width, so the value
  // has to be in hand before any label has an address. A literal or a
  // caller-supplied constant is; a label is not, and that is what `la` is for.
  private def value(o: Operand, consts: Map[String, Int]): Either[String, Int] = o match {
    case Operand.Num(v) => Right(v)
    case Operand.Sym(n, k) =>
      consts
        .get(n)
        .map(_ + k)
        .toRight(s"`$n` is not a compile-time constant; use `la` for a label's address")
    case _ => Left("expected an immediate")
  }

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
  private def rr(ops: List[Operand]): Option[(Reg, Reg)] = ops match {
    case List(Operand.R(a), Operand.R(b)) => Some((a, b))
    case _                                => None
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

  // These put the zero on the right. `blez` and `bgtz` cannot, because `0 >= rs`
  // and `0 < rs` are what they mean, so they swap instead and get their own
  // cases above.
  private val zeroBranches: Map[String, Cmp] =
    Map("beqz" -> Cmp.Eq, "bnez" -> Cmp.Ne, "bltz" -> Cmp.Lt, "bgez" -> Cmp.Ge)

  private val swapped: Map[String, Cmp] =
    Map("bgt" -> Cmp.Lt, "ble" -> Cmp.Ge, "bgtu" -> Cmp.Ltu, "bleu" -> Cmp.Geu)

  // Mnemonics with no home in [RiscV.Instr], and what to do instead. A table
  // rather than a case each, so the message is one lookup and the list reads.
  private val unsupported: Map[String, String] = {
    def all(ms: String, why: String) = ms.split(" ").map(_ -> why).toMap

    all(
      "jalr jr",
      "a computed jump cannot be staged: the tower's pc is a static Int, so `RiscV.Instr` " +
        "has no JALR. A direct `jal ra, sym` does assemble; returning through `ra` does not."
    ) ++
      all(
        "call tail",
        "a call needs `jalr` to return through. Assemble the callee on its own, or compile " +
          "with it inlined."
      ) ++
      all(
        "ecall ebreak fence fence.i fence.tso sfence.vma wfi mret sret uret",
        "not modelled: this tower has no traps or fences"
      ) ++
      all(
        "csrr csrw csrs csrc csrwi csrsi csrci csrrw csrrs csrrc csrrwi csrrsi csrrci " +
          "rdcycle rdcycleh rdtime rdtimeh rdinstret rdinstreth",
        "not modelled: this tower has no CSRs"
      ) ++
      all(
        "mul mulh mulhu mulhsu div divu rem remu",
        "the M extension is not modelled; compile with -march=rv32i"
      ) ++
      all(
        "ld sd lwu addiw addw subw sllw srlw sraw slliw srliw sraiw mulw divw divuw remw " +
          "remuw sext.w negw",
        "an RV64 instruction; compile with --target=riscv32 -march=rv32i -mabi=ilp32"
      ) ++
      all(
        "flw fsw fld fsd fadd.s fsub.s fmul.s fdiv.s fsqrt.s fmv.w.x fmv.x.w fcvt.w.s " +
          "fcvt.s.w fmv.s flt.s fle.s feq.s",
        "the F and D extensions are not modelled; compile with -march=rv32i"
      )
  }
}
