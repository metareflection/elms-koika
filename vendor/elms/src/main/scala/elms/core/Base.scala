package elms.core

import elms.core.poly.Lift
import elms.core.tree.Note
import elms.util.SourceContext

trait Base extends Lift {
  protected type Exp

  def fun[A: Typable, B: Typable](name: Option[Name])(
      f: Rep[A] => Rep[B]
  ): Rep[A => B]
  // The location is for the backends with no representation for a lambda: the
  // message they raise is only actionable if it names the line that wrote one.
  def lam[A: Typable, B: Typable](f: Rep[A] => Rep[B])(using
      SourceContext
  ): Rep[A => B]

  def fun[A: Typable, B: Typable](f: Rep[A] => Rep[B]): Rep[A => B] = fun(None)(f)
  def fun[A: Typable, B: Typable](name: Name)(f: Rep[A] => Rep[B]): Rep[A => B] =
    fun(Some(name))(f)
  def fun[A: Typable, B: Typable](name: String)(f: Rep[A] => Rep[B]): Rep[A => B] =
    fun(Name.from(name))(f)

  // Separate names rather than overloads of `fun`. A `Rep[A] => Rep[B]` and a
  // `(Rep[A1], Rep[A2]) => Rep[B]` are different enough to pick apart, but a
  // caller who gets the arity wrong then reads an inference failure about which
  // overload applies rather than one about how many arguments they passed.
  //
  // There is no `lam2`. Nothing in either backend can hold a closure of any
  // arity, and adding one only moves where the refusal comes from.
  def fun2[A1: Typable, A2: Typable, B: Typable](name: Option[Name])(
      f: (Rep[A1], Rep[A2]) => Rep[B]
  ): Rep[(A1, A2) => B]

  def fun2[A1: Typable, A2: Typable, B: Typable](
      f: (Rep[A1], Rep[A2]) => Rep[B]
  ): Rep[(A1, A2) => B] = fun2(None)(f)
  def fun2[A1: Typable, A2: Typable, B: Typable](name: Name)(
      f: (Rep[A1], Rep[A2]) => Rep[B]
  ): Rep[(A1, A2) => B] = fun2(Some(name))(f)
  def fun2[A1: Typable, A2: Typable, B: Typable](name: String)(
      f: (Rep[A1], Rep[A2]) => Rep[B]
  ): Rep[(A1, A2) => B] = fun2(Name.from(name))(f)

  def fun3[A1: Typable, A2: Typable, A3: Typable, B: Typable](name: Option[Name])(
      f: (Rep[A1], Rep[A2], Rep[A3]) => Rep[B]
  ): Rep[(A1, A2, A3) => B]

  def fun3[A1: Typable, A2: Typable, A3: Typable, B: Typable](
      f: (Rep[A1], Rep[A2], Rep[A3]) => Rep[B]
  ): Rep[(A1, A2, A3) => B] = fun3(None)(f)
  def fun3[A1: Typable, A2: Typable, A3: Typable, B: Typable](name: Name)(
      f: (Rep[A1], Rep[A2], Rep[A3]) => Rep[B]
  ): Rep[(A1, A2, A3) => B] = fun3(Some(name))(f)
  def fun3[A1: Typable, A2: Typable, A3: Typable, B: Typable](name: String)(
      f: (Rep[A1], Rep[A2], Rep[A3]) => Rep[B]
  ): Rep[(A1, A2, A3) => B] = fun3(Name.from(name))(f)

  def region[A](exp: => Rep[A]): Rep[A]

  def staticData[A: AsStaticData](data: A): Rep[A]

  def unsafeWrap[T](exp: Exp): Rep[T]
  def unsafeUnwrap[T](rep: Rep[T]): Exp
  def unsafeRegister(op: Op, children: Exp*): Exp

  def unsafeLift[A: Liftable](x: A): Exp = unsafeUnwrap(unit(x))

  def unsafeReflect[T](op: Op, children: Rep[Any]*): Rep[T] =
    unsafeWrap(unsafeRegister(op, children.map(unsafeUnwrap)*))

  // Neither of these gives back a `Rep`. An annotation is not a value: nothing
  // may name one, and reflecting a `unit(())` beside it would put a binding in
  // the residue that the source never asked for.
  def unsafeNote(
      parts: Seq[String],
      args: Seq[Rep[Any]],
      side: Note.Side,
      meta: Option[CommentMeta]
  ): Unit

  def unsafeContract(
      parts: Seq[String],
      args: Seq[Rep[Any]],
      side: Note.Side,
      meta: Option[CommentMeta]
  ): Unit

  def unsafeDeclare[T](name: String): Rep[T]

  def unsafeWithFresh[A, B](f: (Name, Rep[A]) => Rep[B]): Rep[B]
}
