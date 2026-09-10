package elms.pipeline.eqsat

import elms.core.{Name, Op}
import elms.core.given

// The alphabet the e-graph is built over. `Var` covers four different things
// today: real DSL variables, and the opaque results of effectful ops, control
// ops and regions. None of them carry binders, so every node goes in unslotted.
enum ElmsNode derives CanEqual {
  case Pure(op: Op.Pure)
  case Var(name: Name)
}

object ElmsNode {
  given Ordering[ElmsNode] with {
    def compare(a: ElmsNode, b: ElmsNode): Int = (a, b) match {
      case (Var(x), Var(y))   => Ordering[Name].compare(x, y)
      case (Var(_), Pure(_))  => -1
      case (Pure(_), Var(_))  => 1
      case (Pure(p), Pure(q)) => comparePure(p, q)
    }
  }

  private def comparePure(a: Op.Pure, b: Op.Pure): Int = {
    val byRank = rank(a).compare(rank(b))

    if byRank != 0 then byRank
    else (a, b) match {
      // `Const`'s `Primitive` sits in a second parameter list, so `Const(1)` and
      // `Const(1L)` are already the same node to the graph. This orders on the
      // pair that would have told them apart.
      case (Op.Const(x), Op.Const(y)) => Ordering[(String, String)]
          .compare((x.getClass.getName, x.toString), (y.getClass.getName, y.toString))
      case _ => 0
    }
  }

  // Spelled out rather than derived, so `-Wconf:msg=match may not be
  // exhaustive:e` turns a new opcode into a compile error right here. Extraction
  // tie-breaks on this, which means it decides snapshot output.
  private def rank(op: Op.Pure): Int = op match {
    case Op.Const(_)          => 0
    case Op.Negate            => 1
    case Op.Plus              => 2
    case Op.Minus             => 3
    case Op.Times             => 4
    case Op.Equals            => 5
    case Op.Lt                => 6
    case Op.Gt                => 7
    case Op.Le                => 8
    case Op.Ge                => 9
    case Op.Not               => 10
    case Op.StrictAnd         => 11
    case Op.StrictOr          => 12
    case Op.Xor               => 13
    case Op.BitAnd            => 14
    case Op.BitOr             => 15
    case Op.BitXor            => 16
    case Op.BitNot            => 17
    case Op.Shl               => 18
    case Op.Shr               => 19
    case Op.UShr              => 20
    case Op.StringLength      => 21
    case Op.StringTake        => 22
    case Op.StringDrop        => 23
    case Op.StringStartsWith  => 24
    case Op.StringCharAt      => 25
    case Op.StringEndsWith    => 26
    case Op.StringSubstring   => 27
    case Op.Range             => 28
    case Op.RangeStart        => 29
    case Op.RangeEnd          => 30
    case Op.ArrayLength       => 31
  }
}
