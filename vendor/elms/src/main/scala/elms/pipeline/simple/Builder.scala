package elms.pipeline.simple

// A bog-standard builder producing an IR in ANF form according to Rompf '16.

import elms.core.{Type, Op, Name, StaticData, CommentMeta}, Op._
import elms.pipeline
import elms.core.tree as ast
import elms.core.tree.Note
import elms.runtime.Log
import elms.util.{Plumbing, Counter}

class Builder extends pipeline.Builder {
  type Exp = ast.Term

  var roots: List[(Name, ast.Function)] = Nil
  var stBlock: List[(Name, Exp, Seq[Note])] = Nil

  // Notes raised with no statement to live on yet. The next statement pushed
  // adopts them, and whatever is still here when the region closes degrades
  // into a free-standing comment rather than being dropped.
  var pending: List[Note] = Nil

  // The contract of the function currently being filled. Separate from
  // `pending`, because no statement in the body may adopt a clause that belongs
  // to the signature.
  var contracts: List[Note] = Nil

  import ast._

  def variable(name: Name): Exp = V(name)

  def collect(tail: => Exp): Exp = {
    val outerPending = pending
    pending = Nil
    stBlock = Nil

    val last = tail
    flushPending()

    val result = stBlock.foldLeft(last) { case (e2, (name, e1, notes)) =>
      Let(name, e1, e2, notes)
    }

    pending = outerPending
    result
  }

  override def fun(
      name: Name,
      top: Boolean,
      args: Seq[(Name, Type)],
      outty: Type
  ): FunctionStub = {
    def fill(body: => Exp): Unit = {
      // Nothing blanks `stBlock` here. `region` below opens on an empty block
      // and puts the caller's back when it closes, so a function defined part
      // way through another body leaves that body's statements where they were.
      //
      // A clause raised inside a lambda belongs to the lambda, so the enclosing
      // function's contract goes aside for the duration.
      val outerContracts = contracts
      contracts = Nil

      val bodyexp = region(body)
      val f = ast.Function(args, outty, bodyexp, contracts.reverse)

      contracts = outerContracts

      if top then roots ::= (name, f) else stBlock ::= (name, f, Seq())
    }

    FunctionStub(variable(name), fill)
  }

  def reflect(op: Op, children: Seq[Exp]): Exp = {
    val name = fresh()

    // A pure binding never adopts, to match `eqsat`, where a pure op never
    // reaches the CFG and so has no statement for a note to sit on.
    val adopted = op match {
      case _: Op.Pure => Seq()
      case _          => takePending()
    }

    stBlock ::= (name, ast.E(op, children), adopted)
    variable(name)
  }

  def note(
      parts: Seq[String],
      args: Seq[Exp],
      side: Note.Side,
      meta: Option[CommentMeta]
  ): Unit = {
    val n = Note(parts, args, side, meta)

    side match {
      case Note.Side.Before => pending ::= n
      case Note.Side.After  => stBlock match {
          case (name, e, notes) :: rest => stBlock = (name, e, notes :+ n) :: rest
          // Nothing has been pushed yet, so there is no statement to sit after.
          // The free-standing form says the same thing in the same place.
          case Nil => degrade(n)
        }
    }
  }

  def contract(
      parts: Seq[String],
      args: Seq[Exp],
      side: Note.Side,
      meta: Option[CommentMeta]
  ): Unit = { contracts ::= Note(parts, args, side, meta) }

  // Notes raised in source order, since `pending` is a stack.
  private def takePending(): Seq[Note] = {
    val taken = pending.reverse
    pending = Nil
    taken
  }

  private def flushPending(): Unit = takePending().foreach(degrade)

  // A note with nothing to attach to becomes the free-standing form, which is
  // what the caller should have written. Losing it silently is the one outcome
  // that is not acceptable.
  private def degrade(n: Note): Unit = {
    val name = fresh()
    stBlock ::= (name, ast.E(Op.Comment(n.parts, n.meta), n.args), Seq())
  }

  def region(f: => Exp): Exp = {
    val prev = stBlock
    val result = collect(f)
    stBlock = prev
    result
  }

  def extract(): ast.Program = {
    if (!stBlock.isEmpty) {
      Log.warning("BUG: attempted to `extract` with non-empty `stBlock`")
    }

    ast.Program(roots, staticData.toSeq)
  }
}
