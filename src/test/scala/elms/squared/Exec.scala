package elms.koika.test.squared

import elms.prelude.given
import elms.core.macros.virtualize

import elms.koika.test.riscv.RiscV
import RiscV.*

// RV32I over a pair of runs.
//
// Every rule reads the same: the effects go through [each], because they are
// each run's own, and where control goes next is shared. The branch is the
// only rule that has to reconcile the two, and [agree] is what does it.
//
// The single-run halves below are a transcription of
// [elms.koika.test.riscv.Exec], which is where the ISA arguments live.
@virtualize
trait Exec extends Squared {
  // A byte offset lands on an instruction index, and a misaligned one is a bug
  // in the demo rather than something the generated C should have to check.
  private def target(pc: Int, offset: Imm): Int = {
    require(offset.i % 4 == 0, s"misaligned branch offset ${offset.i} at pc $pc")
    pc + offset.i / 4
  }

  private def flip(x: Rep[Int]): Rep[Int] = x ^ unit(Int.MinValue)

  private def evalCond(h: Half, cmp: Cmp, rs1: Reg, rs2: Reg): Rep[Boolean] = {
    val a = read(h, rs1)
    val b = read(h, rs2)
    cmp match {
      case Cmp.Eq => a === b
      case Cmp.Ne => a !== b
      case Cmp.Lt => a < b
      case Cmp.Ge => a >= b
      // Unsigned compare with no unsigned type: flipping the sign bit of both
      // sides turns the unsigned order into the signed one.
      case Cmp.Ltu => flip(a) < flip(b)
      case Cmp.Geu => flip(a) >= flip(b)
    }
  }

  // x0 is hardwired, and register names are static, so both halves of that
  // resolve before anything runs: reading it is the literal 0, and writing it
  // emits nothing at all.
  private def read(h: Half, rs: Reg): Rep[Int] = rs match {
    case RiscV.Reg(0) => unit(0)
    case _            => get_reg(h, unit(rs.i))
  }

  private def write(h: Half, rd: Reg, v: Rep[Int]): Rep[Unit] = rd match {
    case RiscV.Reg(0) => unit(())
    case _            => set_reg(h, unit(rd.i), v)
  }

  // [get_mem] and [set_mem] are word-indexed, and [Cached] splits a word index
  // again into the line holding it and the word within. RISC-V addresses are
  // bytes, so the first split happens here: the word holding one, and the byte
  // within that.
  private def wordOf(addr: Rep[Int]): Rep[Int] = addr >>> unit(2)
  private def shiftOf(addr: Rep[Int]): Rep[Int] = (addr & unit(3)) << unit(3)

  // `SLL` and friends use only the low five bits of the shift amount. C leaves
  // a shift of 32 or more undefined, so the mask is both the ISA's semantics
  // and what makes the two backends agree.
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
  // alignment in the generated C would add checker noise to every load.
  private def loadValue(h: Half, w: Width, addr: Rep[Int]): Rep[Int] = {
    val word = get_mem(h, wordOf(addr))
    w match {
      case Width.W  => word
      case Width.Bu => (word >>> shiftOf(addr)) & unit(0xff)
      case Width.Hu => (word >>> shiftOf(addr)) & unit(0xffff)
      case Width.B  => (word << (unit(24) - shiftOf(addr))) >> unit(24)
      case Width.H  => (word << (unit(16) - shiftOf(addr))) >> unit(16)
    }
  }

  // `SB` and `SH` are read-modify-write, so they cost two cache probes. That
  // is what a write-allocate cache really does.
  private def storeValue(h: Half, w: Width, addr: Rep[Int], v: Rep[Int]): Rep[Unit] =
    w match {
      case Width.W => set_mem(h, wordOf(addr), v)
      case _ => {
        val mask = w match {
          case Width.H | Width.Hu => unit(0xffff)
          case _                  => unit(0xff)
        }
        val sh = shiftOf(addr)
        val old = get_mem(h, wordOf(addr))
        set_mem(h, wordOf(addr), (old & ~(mask << sh)) | ((v & mask) << sh))
      }
    }

  override def step(pc: Int, s: Pair): Pair =
    if (live(pc)) {
      each(s)(tick)
      prog(pc) match {
        case Instr.Op(op, rd, rs1, rs2) => {
          each(s)(h => write(h, rd, alu(op, read(h, rs1), read(h, rs2))))
          call(pc + 1, s)
        }
        case Instr.OpImm(op, rd, rs1, imm) => {
          each(s)(h => write(h, rd, alu(op, read(h, rs1), unit(imm.i))))
          call(pc + 1, s)
        }
        case Instr.Lui(rd, imm) => {
          each(s)(h => write(h, rd, unit(imm.i << 12)))
          call(pc + 1, s)
        }
        case Instr.Auipc(rd, imm) => {
          each(s)(h => write(h, rd, unit(4 * pc + (imm.i << 12))))
          call(pc + 1, s)
        }
        case Instr.Jal(rd, off) => {
          each(s)(h => write(h, rd, unit(4 * (pc + 1))))
          call(target(pc, off), s)
        }
        case Instr.Branch(cmp, rs1, rs2, off) =>
          agree(each(s)(h => evalCond(h, cmp, rs1, rs2))) {
            call(target(pc, off), s)
          } {
            call(pc + 1, s)
          }
        case Instr.Load(w, rd, rs1, imm) => {
          each(s)(h => write(h, rd, loadValue(h, w, read(h, rs1) + unit(imm.i))))
          call(pc + 1, s)
        }
        case Instr.Store(w, rs2, rs1, imm) => {
          each(s)(h => storeValue(h, w, read(h, rs1) + unit(imm.i), read(h, rs2)))
          call(pc + 1, s)
        }
      }
    } else { s }
}
