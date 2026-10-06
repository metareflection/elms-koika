package elms.core

import scala.collection.mutable

import elms.core.{Op, Name}
import elms.core.tree as ast
import elms.core.tree.Note
import elms.pipeline
import elms.runtime.LMSStagingException
import elms.util.{ClosureCompare, SourceContext}

abstract class Driver extends Base with ClosureCompare {
  protected val builder: pipeline.Builder
  protected type Exp = builder.Exp
  case class Rep[+T](wrapped: Exp) extends __Virtualized[T]

  def variable[A](name: Name): Rep[A] = unsafeWrap(builder.variable(name))

  val funTable: mutable.Map[String, Exp] = mutable.Map()

  // Which closure took each name. Two closures asking for one name is the
  // error: both functions are emitted under it, and what comes out is one
  // definition, a call that resolves to neither, and a backend reporting that
  // it cannot infer a type.
  //
  // Keyed on every name and not only the ones a caller wrote, because a name
  // from `builder.fresh()` is new by construction and so can never be the one
  // that collides. That saves threading a flag down from `fun`.
  private val claimedNames: mutable.Map[Name, String] = mutable.Map()

  // Every arity is the same three steps: key the closure, register a stub so a
  // recursive call finds one, then fill it. Only the shape of the callback
  // differs, so that is the only thing the arities pass in.
  //
  // `body` speaks `Exp` and not `Rep`, because `Rep` is covariant and a
  // `Seq[Rep[Any]]` cannot be taken apart into the `Rep[A1]` and `Rep[A2]` the
  // caller's function wants without a cast.
  private def makeFunN[F](
      name: Name,
      top: Boolean,
      intys: Seq[Type],
      outty: Type,
      closure: Serializable,
      body: Seq[Exp] => Exp
  ): Rep[F] = {
    val key = canonicalize(closure)

    claimedNames.get(name) match {
      case Some(taken) if taken != key =>
        throw LMSStagingException(
          s"two different functions were staged under the name " +
            s"`${name.render("")}`. A name given to `fun` has to be unique " +
            "across the program: rename one of them, or share a single `val` " +
            "if they were meant to be the same function."
        )
      case _ => claimedNames(name) = key
    }

    funTable.get(key) match {
      case Some(symb) => unsafeWrap(symb)
      case None       => {
        val args = intys.map { ty => (builder.fresh(), ty) }

        val stub = builder.fun(name, top, args, outty)
        funTable(key) = stub.symbol

        stub.fill { body(args.map { (n, _) => builder.variable(n) }) }

        unsafeWrap(stub.symbol)
      }
    }
  }

  def makeFun[A: Typable, B: Typable](
      name: Name,
      top: Boolean,
      f: Rep[A] => Rep[B]
  ): Rep[A => B] = makeFunN(
    name,
    top,
    Seq(summon[Typable[A]].identity),
    summon[Typable[B]].identity,
    f.asInstanceOf[Serializable],
    es => unsafeUnwrap(f(unsafeWrap(es(0))))
  )

  def makeFun2[A1: Typable, A2: Typable, B: Typable](
      name: Name,
      top: Boolean,
      f: (Rep[A1], Rep[A2]) => Rep[B]
  ): Rep[(A1, A2) => B] = makeFunN(
    name,
    top,
    Seq(summon[Typable[A1]].identity, summon[Typable[A2]].identity),
    summon[Typable[B]].identity,
    f.asInstanceOf[Serializable],
    es => unsafeUnwrap(f(unsafeWrap(es(0)), unsafeWrap(es(1))))
  )

  def makeFun3[A1: Typable, A2: Typable, A3: Typable, B: Typable](
      name: Name,
      top: Boolean,
      f: (Rep[A1], Rep[A2], Rep[A3]) => Rep[B]
  ): Rep[(A1, A2, A3) => B] = makeFunN(
    name,
    top,
    Seq(
      summon[Typable[A1]].identity,
      summon[Typable[A2]].identity,
      summon[Typable[A3]].identity
    ),
    summon[Typable[B]].identity,
    f.asInstanceOf[Serializable],
    es => unsafeUnwrap(f(unsafeWrap(es(0)), unsafeWrap(es(1)), unsafeWrap(es(2))))
  )

  override def fun[A: Typable, B: Typable](name: Option[Name])(
      f: Rep[A] => Rep[B]
  ): Rep[A => B] = makeFun[A, B](name.getOrElse { builder.fresh() }, true, f)
  override def lam[A: Typable, B: Typable](f: Rep[A] => Rep[B])(using
      SourceContext
  ): Rep[A => B] = makeFun[A, B](builder.fresh(), false, f)

  override def fun2[A1: Typable, A2: Typable, B: Typable](
      name: Option[Name]
  )(f: (Rep[A1], Rep[A2]) => Rep[B]): Rep[(A1, A2) => B] =
    makeFun2[A1, A2, B](name.getOrElse { builder.fresh() }, true, f)

  override def fun3[A1: Typable, A2: Typable, A3: Typable, B: Typable](
      name: Option[Name]
  )(f: (Rep[A1], Rep[A2], Rep[A3]) => Rep[B]): Rep[(A1, A2, A3) => B] =
    makeFun3[A1, A2, A3, B](name.getOrElse { builder.fresh() }, true, f)

  override def region[A](exp: => Rep[A]): Rep[A] =
    unsafeWrap(builder.region { unsafeUnwrap(exp) })

  override def staticData[A: AsStaticData](data: A): Rep[A] =
    unsafeWrap(builder.registerStaticData(data.asStaticData))

  override def unsafeWrap[T](exp: Exp): Rep[T] = Rep(exp)
  override def unsafeUnwrap[T](rep: Rep[T]): Exp = rep.wrapped
  override def unsafeRegister(op: Op, children: Exp*): Exp = builder
    .reflect(op, children.toVector)

  override def unsafeNote(
      parts: Seq[String],
      args: Seq[Rep[Any]],
      side: Note.Side,
      meta: Option[CommentMeta]
  ): Unit = builder.note(parts, args.map(unsafeUnwrap), side, meta)

  override def unsafeContract(
      parts: Seq[String],
      args: Seq[Rep[Any]],
      side: Note.Side,
      meta: Option[CommentMeta]
  ): Unit = builder.contract(parts, args.map(unsafeUnwrap), side, meta)

  override def unsafeDeclare[T](name: String): Rep[T] = variable(builder.name(name))

  override def unsafeWithFresh[A, B](f: (Name, Rep[A]) => Rep[B]): Rep[B] = {
    val name = builder.fresh()
    val v = variable(name)
    f(name, v)
  }

  // Every driver and both builders, because staging the same helper twice is a
  // fact about how `makeFun` keys its memo rather than about any one of them.
  def extract(): ast.Program = pipeline.DedupFunctions.run(builder.extract())
}
