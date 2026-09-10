package elms.koika.test.nanorisc

import elms.prelude.*
import elms.prelude.given

object NanoRisc {
  abstract sealed trait Operand derives CanEqual

  // CR cwong: It's not clear to me how much these newtypes actually help; we
  // just end up peppering the code with `unReg` everywhere.
  case class Imm(i: Int) extends Operand {
    def unImm = i
  }
  case class Reg(i: Int) extends Operand {
    def unReg = i
  }

  case class Addr(i: Int) {
    def unAddr = i
  }

  abstract sealed trait Cmp derives CanEqual
  case object Eq extends Cmp
  case object Ne extends Cmp
  case object Lt extends Cmp
  case object Ge extends Cmp

  abstract sealed trait Op derives CanEqual
  case object Plus extends Op
  case object Sub extends Op
  case object Mul extends Op

  abstract sealed class Instr
  case class Mov(dst: Reg, src: Operand) extends Instr
  case class Binop(op: Op, dst: Reg, src1: Reg, src2: Operand) extends Instr
  case class Load(dst: Reg, src: Reg, offs: Operand) extends Instr
  case class Store(dst: Reg, src: Reg, offs: Operand) extends Instr
  case class B(cmp: Option[(Cmp, Reg, Operand)], tgt: Addr) extends Instr

  trait Ops extends DslOps {
    extension (cmp: Cmp)
      def eval(op1: Rep[Int], op2: Rep[Int]): Rep[Boolean] = cmp match {
        case Eq => op1 === op2
        case Ne => op1 !== op2
        case Lt => op1 < op2
        case Ge => op1 >= op2
      }

    extension (op: Op)
      def eval(op1: Rep[Int], op2: Rep[Int]): Rep[Int] = op match {
        case Plus => op1 + op2
        case Sub  => op1 - op2
        case Mul  => op1 * op2
      }
  }
}
