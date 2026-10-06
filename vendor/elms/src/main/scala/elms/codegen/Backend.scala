package elms.codegen

import elms.core.{Type, CommentMeta}
import elms.core.tree as ast
import elms.core.tree.Note
import elms.util.IndentedWriter

abstract class Backend(cfg: Config) {
  def emit(prog: ast.Program, out: java.io.PrintStream): Unit

  def render(prog: ast.Program): String = {
    val w = new java.io.ByteArrayOutputStream()
    emit(prog, new java.io.PrintStream(w))
    w.toString("utf-8")
  }

  protected def renderType(ty: Type): String

  // Whether a first-class function value has a representation in this target. C
  // has no closures, so `lam` is rejected where it is called rather than
  // emitted as something that cannot compile.
  def supportsLambdas: Boolean = true

  protected def makeIndentedWriter(out: java.io.PrintStream): IndentedWriter =
    IndentedWriter(out, cfg.baseIndentLevel, cfg.indentKind)

  // How a comment reaches the residue: the text behind `//`, one line each. A
  // backend that understands the annotation language overrides this and reads
  // `meta`. Both forms come through here, with arguments already interpolated.
  //
  // `//` and not `// `, so `comment("@ assert x1 > 0;")` comes out as ACSL and
  // prose is written `comment(" plain")`.
  protected def renderComment(text: String, meta: Option[CommentMeta]): Seq[String] =
    text.split("\n", -1).map("//" + _).toSeq

  // `parts` interleaved with `args` the way a `StringContext` interleaves them:
  // one more part than argument, argument `i` between parts `i` and `i + 1`.
  //
  // Separate from `renderInterpolated` because a backend that assembles its own
  // annotation syntax needs the text, not the comment lines around it.
  protected final def interpolate(parts: Seq[String], args: Seq[String]): String = parts
    .zipAll(args, "", "").map { (part, arg) => part + arg }.mkString

  protected final def renderInterpolated(
      parts: Seq[String],
      args: Seq[String],
      meta: Option[CommentMeta]
  ): Seq[String] = renderComment(interpolate(parts, args), meta)

  // Each backend renders an operand its own way, so the interleave lives here
  // and the spelling of a name does not.
  protected final def renderNote(note: Note, operand: ast.Term => String): Seq[String] =
    renderInterpolated(note.parts, note.args.map(operand), note.meta)

  // A whole contract at once, rather than a note at a time. An annotation
  // language can require the clauses to arrive as a single unit: consecutive
  // one-line ACSL annotations are a syntax error where one multi-clause block
  // is fine, and only a hook over the sequence can produce that. The default
  // keeps them independent.
  protected def renderContract(
      notes: Seq[Note],
      operand: ast.Term => String
  ): Seq[String] = notes.flatMap(renderNote(_, operand))

  // One side of a statement's notes, as a unit, for the same reason. A loop
  // carrying an invariant and an `assigns` needs both in one block.
  protected def renderNotes(
      notes: Seq[Note],
      side: Note.Side,
      operand: ast.Term => String
  ): Seq[String] = notes.filter(_.side == side).flatMap(renderNote(_, operand))

  // A comment's text is one string, so an operand has to come back as one.
  // Every emitter writes to a stream, hence the detour through a buffer.
  protected final def captured(f: IndentedWriter => Unit): String = {
    val buf = new java.io.ByteArrayOutputStream()
    f(IndentedWriter(new java.io.PrintStream(buf), 0, cfg.indentKind))
    buf.toString("utf-8")
  }
}
