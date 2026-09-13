package elms.koika.test.riscv

import elms.prelude.*
import elms.prelude.given

import elms.koika.test.common.Direct

import RiscV.*

// The RISC-V half of the tower. Everything [Isa] asks for, in ordinary
// `Rep[Int]` operators, so the generated C nests instead of let-binding every
// shift-and-mask step.
//
// `@virtualize` is per-class, and forgetting it here does not fail to compile:
// the guard conversion throws at staging time instead.
@virtualize
trait Exec extends Direct {
  type Instr = RiscV.Instr
  type Reg = RiscV.Reg
  type Cond = (Cmp, RiscV.Reg, RiscV.Reg)

  override def regIndex(r: Reg): Int = r.i

  // A byte offset lands on an instruction index, and a misaligned one is a bug
  // in the demo rather than something the generated C should have to check.
  private def target(pc: Int, offset: Imm): Int = {
    require(offset.i % 4 == 0, s"misaligned branch offset ${offset.i} at pc $pc")
    pc + offset.i / 4
  }

  override def branch(pc: Int, i: Instr): Option[(Cond, Int)] = i match {
    case Instr.Branch(cmp, rs1, rs2, off) => Some(((cmp, rs1, rs2), target(pc, off)))
    case _                                => None
  }

  // Wider than the NanoRisc answer, and it has to be. RV32I has no
  // register-plus-register addressing and no scaled index, so the arithmetic
  // that turns a secret into a cache index is its own instruction; refusing to
  // speculate it would close the window before the gadget ran. Writing `rd` is
  // the only effect any of these has, which is exactly what [rollback] undoes.
  // Stores are absent on purpose, and so is control flow.
  override def speculable(i: Instr): Option[Reg] = i match {
    case Instr.Load(_, rd, _, _) => Some(rd)
    case Instr.Op(_, rd, _, _)   => Some(rd)
    case Instr.OpImm(_, rd, _, _) => Some(rd)
    case Instr.Lui(rd, _)        => Some(rd)
    case Instr.Auipc(rd, _)      => Some(rd)
    case _                       => None
  }

  override def reads(c: Cond): Set[Reg] = c match {
    case (_, rs1, rs2) => Set(rs1, rs2)
  }

  override def evalCond(s: Rep[State], c: Cond): Rep[Boolean] = c match {
    case (cmp, rs1, rs2) => {
      val a = read(s, rs1)
      val b = read(s, rs2)
      cmp match {
        case Cmp.Eq  => a === b
        case Cmp.Ne  => a !== b
        case Cmp.Lt  => a < b
        case Cmp.Ge  => a >= b
        // Unsigned compare with no unsigned type: flipping the sign bit of both
        // sides turns the unsigned order into the signed one.
        case Cmp.Ltu => flip(a) < flip(b)
        case Cmp.Geu => flip(a) >= flip(b)
      }
    }
  }

  private def flip(x: Rep[Int]): Rep[Int] = x ^ unit(Int.MinValue)

  // x0 is hardwired, and register names are static, so both halves of that
  // resolve at staging time: reading it is the literal 0, and writing it emits
  // nothing at all. No branch in the generated C, and no override of
  // [set_reg] that would make the mixin order load-bearing again.
  private def read(s: Rep[State], rs: Reg): Rep[Int] = rs match {
    case RiscV.Reg(0) => unit(0)
    case _            => get_reg(s, rs.i)
  }

  private def write(s: Rep[State], rd: Reg, v: Rep[Int]): Rep[Unit] = rd match {
    case RiscV.Reg(0) => unit(())
    case _            => set_reg(s, rd.i, v)
  }

  // [get_mem] and [set_mem] are word-indexed, which is what keeps one cache
  // entry equal to one word and leaves [Cached] untouched. RISC-V addresses are
  // bytes, so they split into the word holding them and the byte within.
  private def wordOf(addr: Rep[Int]): Rep[Int] = addr >>> unit(2)
  private def shiftOf(addr: Rep[Int]): Rep[Int] = (addr & unit(3)) << unit(3)

  // `SLL` and friends use only the low five bits of the shift amount. C leaves a
  // shift of 32 or more undefined, so the mask is both the ISA's semantics and
  // what makes the C and Scala backends agree.
  private def alu(op: AluOp, a: Rep[Int], b: Rep[Int]): Rep[Int] = op match {
    case AluOp.Add  => a + b
    case AluOp.Sub  => a - b
    case AluOp.Sll  => a << (b & unit(31))
    case AluOp.Srl  => a >>> (b & unit(31))
    case AluOp.Sra  => a >> (b & unit(31))
    case AluOp.And  => a & b
    case AluOp.Or   => a | b
    case AluOp.Xor  => a ^ b
    case AluOp.Slt  => if (a < b) { unit(1) } else { unit(0) }
    case AluOp.Sltu => if (flip(a) < flip(b)) { unit(1) } else { unit(0) }
  }

  // Unaligned `LW`/`LH` are unsupported: the demos are aligned, and asserting
  // alignment in the generated C would add `__CPROVER_assert` noise to every
  // load.
  private def loadValue(s: Rep[State], w: Width, addr: Rep[Int]): Rep[Int] = {
    val word = get_mem(s, wordOf(addr))
    w match {
      case Width.W  => word
      case Width.Bu => (word >>> shiftOf(addr)) & unit(0xff)
      case Width.Hu => (word >>> shiftOf(addr)) & unit(0xffff)
      case Width.B  => (word << (unit(24) - shiftOf(addr))) >> unit(24)
      case Width.H  => (word << (unit(16) - shiftOf(addr))) >> unit(16)
    }
  }

  // `SB` and `SH` are read-modify-write, so they cost two cache probes. That is
  // what a write-allocate cache really does.
  private def storeValue(s: Rep[State], w: Width, addr: Rep[Int], v: Rep[Int]): Rep[Unit] =
    w match {
      case Width.W => set_mem(s, wordOf(addr), v)
      case _       => {
        val mask = w match {
          case Width.H | Width.Hu => unit(0xffff)
          case _                  => unit(0xff)
        }
        val sh = shiftOf(addr)
        val old = get_mem(s, wordOf(addr))
        set_mem(s, wordOf(addr), (old & ~(mask << sh)) | ((v & mask) << sh))
      }
    }

  override def step(pc: Int, s: Rep[State]): Rep[State] =
    if (pc < prog.length) {
      tick(s)
      prog(pc) match {
        case Instr.Op(op, rd, rs1, rs2) => {
          write(s, rd, alu(op, read(s, rs1), read(s, rs2)))
          call(pc + 1, s)
        }
        case Instr.OpImm(op, rd, rs1, imm) => {
          write(s, rd, alu(op, read(s, rs1), unit(imm.i)))
          call(pc + 1, s)
        }
        case Instr.Lui(rd, imm) => {
          write(s, rd, unit(imm.i << 12))
          call(pc + 1, s)
        }
        case Instr.Auipc(rd, imm) => {
          write(s, rd, unit(4 * pc + (imm.i << 12)))
          call(pc + 1, s)
        }
        case Instr.Jal(rd, off) => {
          write(s, rd, unit(4 * (pc + 1)))
          call(target(pc, off), s)
        }
        case Instr.Branch(cmp, rs1, rs2, off) =>
          if (evalCond(s, (cmp, rs1, rs2))) { call(target(pc, off), s) }
          else { call(pc + 1, s) }
        case Instr.Load(w, rd, rs1, imm) => {
          write(s, rd, loadValue(s, w, read(s, rs1) + unit(imm.i)))
          call(pc + 1, s)
        }
        case Instr.Store(w, rs2, rs1, imm) => {
          storeValue(s, w, read(s, rs1) + unit(imm.i), read(s, rs2))
          call(pc + 1, s)
        }
      }
    } else { s }
}
