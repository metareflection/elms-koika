package elms.koika.test.riscv.asm

import elms.koika.test.riscv.RiscV

case class Loc(file: String, line: Int) derives CanEqual {
  override def toString: String = s"$file:$line"
}

// A line the frontend could not use, with enough of the source to find it by
// eye. These accumulate rather than throw, because the first question anyone
// asks of a new `.s` file is which parts of it are out of scope, and that wants
// the whole list at once.
case class AsmError(loc: Loc, msg: String) derives CanEqual {
  override def toString: String = s"$loc: $msg"
}

class AsmException(val errors: List[AsmError])
    extends RuntimeException(errors.mkString("\n"))

enum Operand derives CanEqual {
  case R(r: RiscV.Reg)
  case Num(i: Int)
  case Sym(name: String, addend: Int)
  case Hi(name: String, addend: Int)
  case Lo(name: String, addend: Int)
  case Mem(off: Operand, base: RiscV.Reg)
}

// The `loc` lives on [Stmt] rather than on each case of [Form], so building an
// error only ever needs `stmt.loc`.
case class Stmt(loc: Loc, form: Form) derives CanEqual

enum Form derives CanEqual {
  case Label(name: String)
  case Dir(name: String, args: List[String])
  case Insn(mnemonic: String, operands: List[Operand])
}

object Regs {
  // A table and not arithmetic, because two of the ABI ranges are
  // discontiguous: `t0`-`t2` are x5-x7 while `t3`-`t6` are x28-x31, and
  // `s0`/`s1` are x8/x9 while `s2`-`s11` are x18-x27. Getting one of those
  // wrong yields a program that assembles and computes something else.
  val byName: Map[String, RiscV.Reg] = {
    val named = Map("zero" -> 0, "ra" -> 1, "sp" -> 2, "gp" -> 3, "tp" -> 4, "fp" -> 8)
    val t = (0 to 6).map(i => s"t$i" -> (if (i < 3) { 5 + i } else { 25 + i }))
    val s = (0 to 11).map(i => s"s$i" -> (if (i < 2) { 8 + i } else { 16 + i }))
    val a = (0 to 7).map(i => s"a$i" -> (10 + i))
    val x = (0 to 31).map(i => s"x$i" -> i)
    (named ++ t ++ s ++ a ++ x).map((n, i) => n -> RiscV.Reg(i))
  }
}
