package elms.core.tree

import elms.core.{Op, Type, Name, StaticData, CommentMeta}
import elms.util.Plumbing.*

sealed abstract class Term derives CanEqual

case class E(op: Op, children: Seq[Term]) extends Term
case class V(name: Name) extends Term
case class Let(x: Name, e1: Term, e2: Term, notes: Seq[Note]) extends Term

// Text a backend drops into the residue next to the binding that carries it.
// The free-standing form is `Op.Comment`, which is a statement of its own.
//
// Adjacency here is structural: an elaboration can hoist whatever it likes and
// still cannot get between a note and its host, because the note is part of the
// host.
case class Note(
    parts: Seq[String],
    args: Seq[Term],
    side: Note.Side,
    meta: Option[CommentMeta] = None
) derives CanEqual

object Note {
  enum Side derives CanEqual {
    case Before, After
  }
}

// `notes` is the function's contract, which a backend renders above the
// signature rather than inside the body. An annotation language that scopes a
// clause to the whole function has nowhere else to put it: ACSL's `requires`
// is a syntax error anywhere but here.
case class Function(
    args: Seq[(Name, Type)],
    outty: Type,
    body: Term,
    notes: Seq[Note]
) extends Term {
  def map(f: Term => Term): Function = Function(args, outty, f(body), notes)
}

case class Program(functions: Seq[(Name, Function)], staticData: Seq[(Name, StaticData)])

object Term {
  // Annotations are not part of the program, so they do not count towards its
  // size. Extraction tie-breaks on this and a note must not move a tie.
  def size(e: Term): Int = e match {
    case E(_, children) => 1 + children.map(size).sum
    case V(_) => 1
    case Let(_, e1, e2, _) => 1 + size(e1) + size(e2)
    case Function(_, _, body, _) => 1 + size(body)
  }
}

extension (t: Term)
  def size: Int = Term.size(t)
