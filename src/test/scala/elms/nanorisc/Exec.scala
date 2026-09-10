package elms.koika.test.nanorisc

import elms.prelude.*
import elms.prelude.given

import elms.koika.test.common.{Direct, StateT}

import NanoRisc.*

// The NanoRisc half of the tower: everything [Isa] asks for, and nothing about
// caching or speculation.
@virtualize
trait Exec extends Direct with NanoRisc.Ops {
  type Instr = NanoRisc.Instr
  type Reg = NanoRisc.Reg
  // Everything `B` carries besides its target.
  type Cond = (Cmp, NanoRisc.Reg, Operand)

  override def regIndex(r: Reg): Int = r.unReg

  override def branch(pc: Int, i: Instr): Option[(Cond, Int)] = i match {
    case B(Some(cnd), tgt) => Some((cnd, tgt.unAddr))
    case _                 => None
  }

  override def speculable(i: Instr): Option[Reg] = i match {
    case Load(rd, _, _) => Some(rd)
    case _              => None
  }

  override def reads(c: Cond): Set[Reg] = c match {
    case (_, src1, src2) => Set(src1) ++ (src2 match {
        case r: NanoRisc.Reg => Set(r)
        case _               => Set.empty
      })
  }

  override def evalCond(s: Rep[StateT], c: Cond): Rep[Boolean] = c match {
    case (cmp, src1, src2) => cmp.eval(operand(s, src1), operand(s, src2))
  }

  def operand(s: Rep[StateT], vl: Operand): Rep[Int] = vl match {
    case Imm(i) => i
    case Reg(i) => get_reg(s, i)
  }

  override def step(pc: Int, s: Rep[StateT]): Rep[StateT] =
    if (pc < prog.length) {
      tick(s)
      prog(pc) match {
        case Mov(dst, src) => {
          set_reg(s, dst.unReg, operand(s, src))
          call(pc + 1, s)
        }
        case Binop(op, dst, src1, src2) => {
          set_reg(s, dst.unReg, op.eval(operand(s, src1), operand(s, src2)))
          call(pc + 1, s)
        }
        case Load(dst, src, im) => {
          set_reg(s, dst.unReg, get_mem(s, operand(s, src) + operand(s, im)))
          call(pc + 1, s)
        }
        case Store(dst, src, im) => {
          set_mem(s, operand(s, src) + operand(s, im), operand(s, dst))
          call(pc + 1, s)
        }
        case B(None, tgt)                    => call(tgt.unAddr, s)
        case B(Some((cmp, src1, src2)), tgt) =>
          if (cmp.eval(operand(s, src1), operand(s, src2))) { call(tgt.unAddr, s) }
          else { call(pc + 1, s) }
      }
    } else { s }
}
