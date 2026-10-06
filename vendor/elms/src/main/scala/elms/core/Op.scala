// Contains the operations supported by LMS.

package elms.core

sealed trait Op derives CanEqual

object Op {
  sealed abstract class Pure extends Op

  // An effect, split by what it does to memory.
  //
  // A `Read` observes the store: it has to stay in order relative to a write,
  // but nothing forces it to be emitted if no one wants its value, and two of
  // them with no write between are the same value.
  //
  // A `Write` changes the store, or does something the compiler cannot see
  // through such as I/O or a call. Always emitted, always in order.
  sealed abstract class Effectful extends Op
  sealed abstract class Read extends Effectful
  sealed abstract class Write extends Effectful

  sealed abstract class Control extends Op

  // The `equals` is not the one a case class would derive, and it has to be
  // written out. Scala's cooperative equality makes `'A' == 65` true, and a
  // case class only compares its first parameter list, so `Const('A')` and
  // `Const(65)` are one value to anything that hashes them. The e-graph does:
  // the two e-classes merge, extraction picks whichever node it likes, and a
  // `char` literal lands where the program wanted an `int`.
  case class Const[T](val v: T)(using val prim: Primitive[T]) extends Pure {
    override def equals(other: Any): Boolean = other match {
      // `Objects.equals` and not `==`, because cooperative equality is the
      // thing being avoided and `==` is how it gets in.
      case that: Const[?] => prim == that.prim && java.util.Objects.equals(v, that.v)
      case _              => false
    }

    override def hashCode: Int = (prim, v).##
  }

  case class VarNew(val typ: Type) extends Write
  case object VarGet extends Read
  case object VarSet extends Write

  case object App extends Write

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

  case object Print extends Write
  case object Println extends Write

  // A comment standing on its own, as a statement. The children are the values
  // the text mentions, interleaved between `parts` the way a `StringContext`
  // interleaves them.
  //
  // `Write` and not `Read`: a comment is always emitted, always in order, never
  // deduped against another and never dropped for want of a use.
  case class Comment(val parts: Seq[String], val meta: Option[CommentMeta] = None)
      extends Write

  // Scala's `Char.toInt`. No narrowing counterpart, because what wants this is
  // arithmetic on a character that came out of `charAt` and there is nothing
  // yet that wants to put one back.
  case object CharToInt extends Pure

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

  case class ArrayNew(val typ: Type) extends Write
  // A bulk copy between two arrays, which is `memcpy` in C and `Array.copy` on
  // the JVM. Separate from a loop of `ArraySet`s because a backend can do it in
  // one call, and because nothing in a loop says the regions do not overlap.
  case object ArrayCopy extends Write // (dst, src, len)
  case object ArrayGet extends Read
  case object ArraySet extends Write
  case object ArrayLength extends Pure

  case class StructGet(val repr: StructRepr, val field: String) extends Read
  case class StructSet(val field: String) extends Write

  case class Custom(val name: String, val ty: Type) extends Write
}
