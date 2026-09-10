package elms.pipeline.eqsat

import foresight.eqsat.Slot
import foresight.eqsat.collections.SlotMap
import foresight.eqsat.metadata.Analysis

import elms.core.Op
import elms.core.instances.given

// What each e-class is known to evaluate to, when it is known at all. This is the
// half of `pipeline.Propagate` that a pattern rule cannot express, since folding
// has to compute the result rather than match it.
object ConstantAnalysis extends Analysis[ElmsNode, Option[Op.Const[?]]] {
  def name: String = "ConstantAnalysis"

  def rename(result: Option[Op.Const[?]], renaming: SlotMap): Option[Op.Const[?]] =
    result

  def make(
      node: ElmsNode,
      defs: Seq[Slot],
      uses: Seq[Slot],
      args: Seq[Option[Op.Const[?]]]
  ): Option[Op.Const[?]] = node match {
    case ElmsNode.Var(_)              => None
    case ElmsNode.Pure(c: Op.Const[?]) => Some(c)
    case ElmsNode.Pure(op) =>
      if args.forall(_.isDefined) then fold(op, args.flatten.map(_.v)) else None
  }

  // Two constants in one class would mean the program has two different values
  // for one expression, so a disagreement here is a bug in the rules and not
  // something to paper over.
  def join(left: Option[Op.Const[?]], right: Option[Op.Const[?]]): Option[Op.Const[?]] =
    (left, right) match {
      case (Some(l), Some(r)) =>
        require(l == r, s"e-class holds two constants: ${l.v} and ${r.v}")
        Some(l)
      case (Some(l), None) => Some(l)
      case (None, r)       => r
    }

  private def inWidth(count: Int): Boolean = 0 <= count && count < 32

  // The values arrive as `Any` because `Op.Const` is typed and the graph is not.
  // Same runtime type tests `Propagate` already does with its `Ext.Const[T]`
  // extractors; anything unrecognised just stays unfolded.
  private def fold(op: Op.Pure, args: Seq[Any]): Option[Op.Const[?]] =
    (op, args) match {
      case (Op.Negate, Seq(x: Int))          => Some(Op.Const(-x))
      case (Op.Plus, Seq(x: Int, y: Int))    => Some(Op.Const(x + y))
      case (Op.Minus, Seq(x: Int, y: Int))   => Some(Op.Const(x - y))
      case (Op.Times, Seq(x: Int, y: Int))   => Some(Op.Const(x * y))
      case (Op.Lt, Seq(x: Int, y: Int))      => Some(Op.Const(x < y))
      case (Op.Gt, Seq(x: Int, y: Int))      => Some(Op.Const(x > y))
      case (Op.Le, Seq(x: Int, y: Int))      => Some(Op.Const(x <= y))
      case (Op.Ge, Seq(x: Int, y: Int))      => Some(Op.Const(x >= y))
      case (Op.Not, Seq(b: Boolean))         => Some(Op.Const(!b))

      case (Op.StrictAnd, Seq(x: Boolean, y: Boolean)) => Some(Op.Const(x & y))
      case (Op.StrictOr, Seq(x: Boolean, y: Boolean))  => Some(Op.Const(x | y))
      case (Op.Xor, Seq(x: Boolean, y: Boolean))       => Some(Op.Const(x ^ y))

      case (Op.BitAnd, Seq(x: Int, y: Int)) => Some(Op.Const(x & y))
      case (Op.BitOr, Seq(x: Int, y: Int))  => Some(Op.Const(x | y))
      case (Op.BitXor, Seq(x: Int, y: Int)) => Some(Op.Const(x ^ y))
      case (Op.BitNot, Seq(x: Int))         => Some(Op.Const(~x))

      // Shifts fold only for counts both backends agree on. Scala masks the
      // count to five bits where C leaves anything at or past the width
      // undefined, so folding a wider count would bake one backend's answer
      // into a program the other renders differently.
      case (Op.Shl, Seq(x: Int, y: Int)) if inWidth(y)  => Some(Op.Const(x << y))
      case (Op.Shr, Seq(x: Int, y: Int)) if inWidth(y)  => Some(Op.Const(x >> y))
      case (Op.UShr, Seq(x: Int, y: Int)) if inWidth(y) => Some(Op.Const(x >>> y))

      case (Op.Equals, Seq(x: Int, y: Int))         => Some(Op.Const(x == y))
      case (Op.Equals, Seq(x: Boolean, y: Boolean)) => Some(Op.Const(x == y))
      case (Op.Equals, Seq(x: Char, y: Char))       => Some(Op.Const(x == y))
      case (Op.Equals, Seq(x: String, y: String))   => Some(Op.Const(x == y))
      case (Op.Equals, Seq(_: Unit, _: Unit))       => Some(Op.Const(true))

      case (Op.StringLength, Seq(s: String))     => Some(Op.Const(s.length))
      case (Op.StringTake, Seq(s: String, i: Int)) => Some(Op.Const(s.take(i)))
      case (Op.StringDrop, Seq(s: String, i: Int)) => Some(Op.Const(s.drop(i)))
      case (Op.StringCharAt, Seq(s: String, i: Int)) => s.lift(i).map(Op.Const(_))
      case (Op.StringStartsWith, Seq(s: String, p: String)) =>
        Some(Op.Const(s.startsWith(p)))
      case (Op.StringEndsWith, Seq(s: String, p: String)) =>
        Some(Op.Const(s.endsWith(p)))
      case (Op.StringSubstring, Seq(s: String, st: Int, end: Int)) =>
        Some(Op.Const(s.slice(st, end)))

      case _ => None
    }
}
