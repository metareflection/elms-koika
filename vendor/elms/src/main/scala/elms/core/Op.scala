// Contains the operations supported by LMS.

package elms.core

sealed trait Op derives CanEqual

object Op {
  sealed abstract class Pure extends Op
  sealed abstract class Effectful extends Op
  sealed abstract class Control extends Op

  case class Const[T](val v: T)(using val prim: Primitive[T]) extends Pure

  case class VarNew(val typ: Type) extends Effectful
  case object VarGet extends Effectful
  case object VarSet extends Effectful

  case object App extends Effectful

  case object Negate extends Pure
  case object Plus extends Pure
  case object Minus extends Pure
  case object Times extends Pure

  case object Equals extends Pure
  case object Lt extends Pure
  case object Gt extends Pure
  case object Le extends Pure
  case object Ge extends Pure

  case object Not extends Pure
  case object And extends Control
  case object Or extends Control

  // `And` and `Or` above take regions and compile to an `if`, which is what
  // makes them `Control`. These take values, so they are `Pure` and the rewrite
  // rules can see them. `Xor` needs no qualifier: there is no lazy form of it.
  case object StrictAnd extends Pure
  case object StrictOr extends Pure
  case object Xor extends Pure

  case object BitAnd extends Pure
  case object BitOr extends Pure
  case object BitXor extends Pure
  case object BitNot extends Pure
  case object Shl extends Pure
  // `Shr` keeps the sign bit and `UShr` shifts in zeroes, exactly Scala's `>>`
  // and `>>>`. C has no operator for the latter, so `CCodegen` routes it
  // through `unsigned int`.
  case object Shr extends Pure
  case object UShr extends Pure

  case object Print extends Effectful
  case object Println extends Effectful

  case object StringLength extends Pure
  case object StringTake extends Pure
  case object StringDrop extends Pure
  case object StringStartsWith extends Pure
  case object StringCharAt extends Pure
  case object StringEndsWith extends Pure
  case object StringSubstring extends Pure

  case object Range extends Pure
  case class RangeForEach(x: Name) extends Control
  case object RangeStart extends Pure
  case object RangeEnd extends Pure

  case object IfThenElse extends Control
  case object While extends Control

  case class ArrayNew(val typ: Type) extends Effectful
  case class ArrayInit[T: Typable](init: Seq[T]) extends Effectful
  case object ArrayGet extends Effectful
  case object ArraySet extends Effectful
  case object ArrayLength extends Pure

  case class StructGet(val repr: StructRepr, val field: String) extends Effectful
  case class StructSet(val field: String) extends Effectful

  case class Custom(val name: String, val ty: Type) extends Effectful
}
