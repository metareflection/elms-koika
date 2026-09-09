package elms.pipeline.eqsat

import elms.core.{Op, Type, Name}

import foresight.eqsat.EClassCall

enum Stmt {
  case Return(node: EClassCall)
  case Let(x: Name, lhs: Stmt, tail: Stmt)
  case Effect(op: Op.Effectful, children: Seq[EClassCall])
  case If(cond: EClassCall, thn: Stmt, els: Stmt)
  case RangeFor(v: Name, st: EClassCall, end: EClassCall, body: Stmt)
  case While(cond: Stmt, body: Stmt)
  case Lambda(arg: Name, inty: Type, outty: Type, body: Stmt)
}
