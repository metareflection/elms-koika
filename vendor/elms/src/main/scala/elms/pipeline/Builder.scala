package elms.pipeline

import elms.core.{Type, Op, Name, StaticData, CommentMeta}
import elms.core.tree.{Note, Program}
import elms.util.Counter

abstract class Builder {
  type Exp

  protected case class FunctionStub(symbol: Exp, fill: (=> Exp) => Unit)

  private val counter = Counter()

  val staticData = scala.collection.mutable.Map[Name, StaticData]()

  def name(s: String): Name = Name.from(s)
  def fresh(): Name = Name.from(counter.tick())
  def variable(name: Name): Exp

  def fun(name: Name, top: Boolean, args: Seq[(Name, Type)], outty: Type): FunctionStub

  def reflect(op: Op, children: Seq[Exp]): Exp

  // Raise a note. It has no home yet: for `Before`, the next statement this
  // builder pushes adopts it, and a pure op is never that statement, because it
  // may not survive to be a binding at all. For `After` it goes to the most
  // recently pushed statement.
  //
  // Arguments stay as `Exp`, so each builder resolves them at the point it can.
  def note(
      parts: Seq[String],
      args: Seq[Exp],
      side: Note.Side,
      meta: Option[CommentMeta]
  ): Unit

  // Raise a note against the function currently being built, wherever in its
  // body the call happens. Its own buffer, because a contract clause belongs to
  // the signature and no statement inside can adopt it.
  def contract(
      parts: Seq[String],
      args: Seq[Exp],
      side: Note.Side,
      meta: Option[CommentMeta]
  ): Unit

  def region(f: => Exp): Exp

  def registerStaticData(data: StaticData): Exp = {
    val name = fresh()
    staticData(name) = data
    variable(name)
  }

  def extract(): Program
}
