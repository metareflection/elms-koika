package elms.koika.test.riscv.asm

// Assembly is line-oriented and regular, so this is a hand-rolled scanner.
// There is no parser-combinator dependency in the build and this grammar does
// not earn one.
object Parse {
  def stmts(file: String, src: String): (List[Stmt], List[AsmError]) = {
    val out = src.linesIterator.zipWithIndex.flatMap { (text, i) =>
      line(Loc(file, i + 1), text)
    }.toList
    (out.collect { case Right(s) => s }, out.collect { case Left(e) => e })
  }

  // One physical line can be several statements, because a label may share a
  // line with the instruction it names.
  private def line(loc: Loc, text: String): List[Either[AsmError, Stmt]] = {
    val (labels, rest) = peel(strip(text).trim)
    val bound = labels.map(l => Right(Stmt(loc, Form.Label(l))))
    if (rest.isEmpty) { bound }
    else if (rest.startsWith(".")) { bound :+ Right(directive(loc, rest)) }
    else { bound :+ insn(loc, rest) }
  }

  // A `#` comment runs to end of line. Quote-aware, so `.asciz "a#b"` survives.
  private def strip(text: String): String = {
    val quotes = text.scanLeft(0)((n, c) => if (c == '"') { n + 1 } else { n })
    text.indices.find(j => text(j) == '#' && quotes(j) % 2 == 0).fold(text)(text.take)
  }

  private val labelAt = "^([A-Za-z_.$][A-Za-z0-9_.$]*):\\s*".r
  private val hiLoAt = "^%([a-z_]+)\\((.*)\\)$".r
  private val memAt = "^(.*)\\(([^()]+)\\)$".r
  private val symAt = "^([A-Za-z_.$][A-Za-z0-9_.$]*)(?:\\s*([+-])\\s*(.+))?$".r

  private def peel(text: String): (List[String], String) =
    labelAt.findPrefixMatchOf(text) match {
      case Some(m) => {
        val (more, rest) = peel(m.after.toString)
        (m.group(1) :: more, rest)
      }
      case None => (Nil, text)
    }

  private def directive(loc: Loc, text: String): Stmt = {
    val (name, args) = text.span(!_.isWhitespace)
    Stmt(loc, Form.Dir(name, split(args.trim)))
  }

  private def insn(loc: Loc, text: String): Either[AsmError, Stmt] = {
    val (m, args) = text.span(!_.isWhitespace)
    val parsed = split(args.trim).map(operand)
    parsed
      .collectFirst { case Left(e) => AsmError(loc, e) }
      .toLeft(Stmt(loc, Form.Insn(m.toLowerCase, parsed.collect { case Right(o) => o })))
  }

  // Commas at paren depth zero, so `%lo(name)(a1)` stays one operand.
  private def split(text: String): List[String] = {
    val (cur, done, _, _) = text.foldLeft(("", List.empty[String], 0, false)) {
      case ((cur, done, depth, quoted), c) =>
        if (quoted) { (cur + c, done, depth, c != '"') }
        else {
          c match {
            case '"'               => (cur + c, done, depth, true)
            case '('               => (cur + c, done, depth + 1, false)
            case ')'               => (cur + c, done, depth - 1, false)
            case ',' if depth == 0 => ("", done :+ cur.trim, depth, false)
            case _                 => (cur + c, done, depth, false)
          }
        }
    }
    (done :+ cur.trim).filter(_.nonEmpty)
  }

  def operand(s: String): Either[String, Operand] = s match {
    // The displacement of a memory operand is whatever precedes the *last*
    // paren group, which is why this is greedy: clang writes `%lo(name)(a1)`.
    // Requiring the base to name a register is what keeps `%lo(name)` on its
    // own from matching here.
    case memAt(off, base) if Regs.byName.contains(base.trim) => {
      val displacement =
        if (off.trim.isEmpty) { Right(Operand.Num(0)) } else { operand(off.trim) }
      displacement.map(Operand.Mem(_, Regs.byName(base.trim)))
    }
    case hiLoAt(kind, inner) =>
      sym(inner.trim).toRight(s"cannot parse the symbol in `$s`").flatMap { (n, k) =>
        kind match {
          case "hi" => Right(Operand.Hi(n, k))
          case "lo" => Right(Operand.Lo(n, k))
          case _    => Left(s"`%$kind` is a PIC relocation; rebuild with -fno-pic")
        }
      }
    case _ if Regs.byName.contains(s) => Right(Operand.R(Regs.byName(s)))
    case _ =>
      num(s)
        .map(Operand.Num(_))
        .orElse(sym(s).map((n, k) => Operand.Sym(n, k)))
        .toRight(s"cannot parse operand `$s`")
  }

  def sym(s: String): Option[(String, Int)] = s match {
    case symAt(n, null, _)  => Some((n, 0))
    case symAt(n, sign, k)  => num(k).map(v => (n, if (sign == "-") { -v } else { v }))
    case _                  => None
  }

  def num(s: String): Option[Int] = {
    val (sign, body) =
      if (s.startsWith("-")) { (-1, s.drop(1)) }
      else if (s.startsWith("+")) { (1, s.drop(1)) }
      else { (1, s) }
    try {
      if (body.startsWith("0x") || body.startsWith("0X")) {
        Some(sign * java.lang.Long.parseLong(body.drop(2), 16).toInt)
      } else if (body.nonEmpty && body.forall(_.isDigit)) {
        Some(sign * body.toInt)
      } else { None }
    } catch { case _: NumberFormatException => None }
  }
}
