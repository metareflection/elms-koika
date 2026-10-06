package elms.pipeline.eqsat

import elms.core.{Op, Type, Name, CommentMeta}
import elms.core.tree.Note

import foresight.eqsat.EClassCall

// Whether anything ever asked for the value a read defines.
//
// Mutable, and set during elaboration rather than worked out afterwards: the
// elaboration resolving a read's class is the only way a value of it can be
// wanted, so the demand is known exactly where it happens and costs nothing to
// record. A cell and not a field on the AST, because it belongs to the CFG and
// never needs to leave the builder.
final class Weak {
  var demanded: Boolean = false
}

// A note before its arguments have been elaborated. The CFG holds classes where
// the AST holds terms, so a note waits here until `elabNotes` resolves it.
case class PendingNote(
    parts: Seq[String],
    args: Seq[EClassCall],
    side: Note.Side,
    meta: Option[CommentMeta]
)

enum Stmt {
  case Return(node: EClassCall)
  case Let(x: Name, lhs: Stmt, tail: Stmt, notes: Seq[PendingNote])
  case Effect(op: Op.Effectful, children: Seq[EClassCall])
  // A read, which is an effect that is ordered but not necessarily wanted.
  case Read(op: Op.Read, children: Seq[EClassCall], weak: Weak)
  case If(cond: EClassCall, thn: Stmt, els: Stmt)
  case RangeFor(v: Name, st: EClassCall, end: EClassCall, body: Stmt)
  case While(cond: Stmt, body: Stmt)
  case Lambda(args: Seq[(Name, Type)], outty: Type, body: Stmt, notes: Seq[PendingNote])
}
