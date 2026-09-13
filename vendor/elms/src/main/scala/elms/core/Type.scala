package elms.core

import annotation.implicitNotFound

trait Type derives CanEqual

// `len` is C storage layout and nothing else: it decides whether a struct
// member is inline `int xs[16]` or a pointer. The JVM has no fixed-length array
// type, so `ScalaCodegen` drops it. The two backends therefore disagree on what
// copying a struct does to the field, and the C one is right.
case class ARRAY(inner: Type, len: Option[Int] = None) extends Type
case class ARROW(args: Type, out: Type) extends Type

sealed trait Primitive[A] extends Type {
  def is[B](other: Primitive[B]): Option[A =:= B]
}

case object UNIT extends Primitive[Unit] {
  def is[B](other: Primitive[B]): Option[Unit =:= B] = other match {
    case UNIT => Some(summon[Unit =:= Unit])
    case _ => None
  }
}

case object INT extends Primitive[Int] {
  def is[B](other: Primitive[B]): Option[Int =:= B] = other match {
    case INT => Some(summon[Int =:= Int])
    case _ => None
  }
}

case object BOOL extends Primitive[Boolean] {
  def is[B](other: Primitive[B]): Option[Boolean =:= B] = other match {
    case BOOL => Some(summon[Boolean =:= Boolean])
    case _ => None
  }
}

case object CHAR extends Primitive[Char] {
  def is[B](other: Primitive[B]): Option[Char =:= B] = other match {
    case CHAR => Some(summon[Char =:= Char])
    case _ => None
  }
}

case object STRING extends Primitive[String] {
  def is[B](other: Primitive[B]): Option[String =:= B] = other match {
    case STRING => Some(summon[String =:= String])
    case _ => None
  }
}

@implicitNotFound("${A} is not a DSL type")
abstract class Typable[A] {
  val identity: Type
}

given primUnit: Primitive[Unit] = UNIT
given primInt: Primitive[Int] = INT
given primBool: Primitive[Boolean] = BOOL
given primChar: Primitive[Char] = CHAR
given primString: Primitive[String] = STRING

given typPrim[A](using prim: Primitive[A]): Typable[A] with
  val identity = prim

given typArray[A](using inner: Typable[A]): Typable[Array[A]] with
  val identity = ARRAY(inner.identity)

given typFixedArray[N <: Int, A](using n: ValueOf[N], inner: Typable[A])
    : Typable[FixedArray[N, A]] with
  val identity = ARRAY(inner.identity, Some(n.value))
