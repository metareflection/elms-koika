package elms.core

import elms.core.tree.Note

trait Builtins extends PrimitiveOps {
  // The interpolators sit on the trait rather than inside the object below,
  // because `Builtins.comment"@ assert $y >= 0;"` does not parse: Scala wants a
  // bare identifier before the quote. Out here all three resolve unqualified in
  // any driver that mixes `DslOps`.
  //
  // The parts go through untouched, escapes and all. An annotation language is
  // full of backslashes, and `\result` has to reach the residue as `\result`
  // rather than as a carriage return.
  extension (sc: StringContext) {
    def comment(args: Rep[Any]*): Unit = Builtins.raw(sc.parts.toSeq, args.toSeq, None)
    def attach(args: Rep[Any]*): Unit =
      unsafeNote(sc.parts.toSeq, args.toSeq, Note.Side.Before, None)
    def contract(args: Rep[Any]*): Unit =
      unsafeContract(sc.parts.toSeq, args.toSeq, Note.Side.Before, None)
  }

  object Builtins {
    def print[A](s: Rep[A]): Rep[Unit] = unsafeReflect(Op.Print, s)
    def println[A](s: Rep[A]): Rep[Unit] = unsafeReflect(Op.Println, s)

    // A statement of its own, landing exactly where it was written.
    //
    // It gives back no `Rep`, so a bare `comment(...)` in tail position of a
    // `Rep[Unit]` snippet is lifted to `unit(())` and emits a stray `()` beside
    // it. Put something after it if that matters.
    def comment(text: String, meta: Option[CommentMeta] = None): Unit =
      raw(Seq(text), Seq(), meta)

    // Carried by the next statement rather than standing on its own, so an
    // elaboration that hoists cannot get between the two.
    def attach(text: String, meta: Option[CommentMeta] = None): Unit =
      unsafeNote(Seq(text), Seq(), Note.Side.Before, meta)

    // Scopes over the whole function and is rendered above its signature,
    // wherever in the body the call happens.
    def contract(text: String, meta: Option[CommentMeta] = None): Unit =
      unsafeContract(Seq(text), Seq(), Note.Side.Before, meta)

    // Brackets `body` by approximation: the opening marker goes to the pending
    // buffer and the closing one to the most recently pushed statement. Over a
    // body that pushes no statement at all, the opening marker drifts onto
    // whatever comes next and lands outside the bracket.
    def withComment[T](s: String)(body: => T): T = {
      attach(s)
      val result = body
      unsafeNote(Seq(s"end $s"), Seq(), Note.Side.After, None)
      result
    }

    private[core] def raw(
        parts: Seq[String],
        args: Seq[Rep[Any]],
        meta: Option[CommentMeta]
    ): Unit = { val _ = unsafeReflect[Unit](Op.Comment(parts, meta), args*) }
  }
}
