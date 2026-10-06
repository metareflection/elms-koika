package elms.codegen

import elms.core.*
import elms.core.Op.*
import elms.core.Name
import elms.core.tree as ast
import elms.core.tree.{Note, View}
import elms.util.IndentedWriter
import elms.runtime.Log

class ScalaCodegen(cfg: Config = Config.scalaDefault) extends Backend(cfg) {
  import ast._

  def emit(prog: Program, out: java.io.PrintStream): Unit = {
    val w = makeIndentedWriter(out)
    prog.staticData.foreach { (name, data) => w.emitNamedStaticData(name, data) }
    prog.functions.foreach { (fname, fdef) => w.emitFunction(fname, fdef) }
  }

  private def renderArgs(args: Seq[(Name, Type)]): String =
    args.map { (n, ty) => s"${n.render(cfg.varPrefix)}: ${ty.render}" }.mkString(", ")

  // Scala writes a one-argument function type without the parentheses, so this
  // keeps `Char => T` rather than turning every existing signature into
  // `(Char) => T`.
  private def renderArrow(args: Seq[Type], out: Type): String = args match {
    case Seq(one) => s"${one.render} => ${out.render}"
    case many     => s"(${many.map(_.render).mkString(", ")}) => ${out.render}"
  }

  extension [A: Primitive](x: A)
    def render: String = summon[Primitive[A]] match {
      case UNIT   => s"()"
      case INT    => s"$x"
      case BOOL   => s"$x"
      case CHAR   => s"'$x'"
      case STRING => s"\"$x\""
    }

  protected def renderType(ty: Type): String = ty match {
    case UNIT        => "Unit"
    case INT         => "Int"
    case BOOL        => "Boolean"
    case CHAR        => "Char"
    case STRING      => "String"
    case ARRAY(t, _) => s"Array[${t.render}]"
    // `scala.Range` carries a step that `RANGE` does not, which costs nothing
    // while `until` is the only constructor and every range has step 1.
    case RANGE       => "Range"
    case _           => {
      Log.error(s"Attempted to render unsupported type $ty")
      s"/* Unsupported type $ty */ ???"
    }
  }

  extension (ty: Type) private def render: String = renderType(ty)

  // What an interpolated argument looks like in the text. It goes through the
  // same parenthesisation an operand gets, or `$y * 2` with `y = a + b` comes
  // out as `a + b * 2`, which is a different predicate.
  private def operand(t: ast.Term): String = captured { w =>
    w.emitMaybeParenthesized(t)
  }

  extension (out: IndentedWriter)
    private def invalidTerm(msg: String): Unit = {
      Log.error(msg)
      out.emit("???")
    }

    private def emitNotes(notes: Seq[Note], side: Note.Side): Unit =
      renderNotes(notes, side, operand).foreach(out.emitln)

    private def emitFunction(fname: Name, fdef: Function): Unit = {
      val Function(args, outty, body, notes) = fdef

      renderContract(notes, operand).foreach(out.emitln)
      val argsS = renderArgs(args)
      val header = s"def ${fname.render(cfg.varPrefix)}($argsS): ${outty.render} = {"
      out.emitln(header)
      out.indented { out.emitTerm(body) }
      out.emitln("")
      out.emitln("}\n")
    }

    private def emitMaybeParenthesized(t: Term): Unit = {
      val (l, r) = t match {
        case V(_) | E(_: Const[_], Nil) => ("", "")
        case Let(_, _, _, _)            => ("{", "}")
        case _                          => ("(", ")")
      }
      out.emit(l)
      out.emitTerm(t)
      out.emit(r)
    }

    private def emitAsExpr(t: Term): Unit = {
      val (l, r) = t match {
        case Let(_, _, _, _) => ("{", "}")
        case _               => ("", "")
      }
      out.emit(l)
      out.emitTerm(t)
      out.emit(r)
    }

    private def emitTerm(term: Term): Unit = ast.view(term).map({
      case View.V(name)                      => out.emit(name.render(cfg.varPrefix))
      case View.Let(x, mutTy, e1, e2, notes) => {
        out.emitNotes(notes, Note.Side.Before)

        View.view(e1) match {
          // A comment binds nothing, so the text goes where the dead `val`
          // would have gone.
          case Some(View.Comment(parts, meta, args)) =>
            renderInterpolated(parts, args.map(operand), meta).foreach(out.emitln)

          case _ => {
            // CR cwong: This sucks. Instead, we should use the same `inferType`
            // mechanism as CCodegen to determine whether the RHS is a function
            // type.
            val (vkd, annotation) = mutTy match {
              case Some(ty) => ("var", s": ${ty.render}")
              case None     => e1 match {
                  case Function(args, outty, _, _) =>
                    ("lazy val", s": (${renderArrow(args.map(_._2), outty)})")
                  case _ => ("val", "")
                }
            }

            out.emit(s"$vkd ${x.render(cfg.varPrefix)}$annotation = ")
            out.emitAsExpr(e1)
            out.emitln("")
          }
        }

        out.emitNotes(notes, Note.Side.After)
        out.emitTerm(e2)
      }
      case View.Comment(parts, meta, args) =>
        renderInterpolated(parts, args.map(operand), meta).foreach(out.emitln)
      case View.Function(args, _outty, body, _) => {
        out.emit("(")
        out.emit(renderArgs(args))
        out.emitln(") => {")
        out.indented { out.emitTerm(body) }
        out.emitln("}")
      }
      case const @ View.Const(_) => out.emit(const.value.render(using const.prim))
      case View.Custom(name, _ty, args) => {
        out.emit(name)
        out.emitArgTerms(args)
        out.emit("")
      }

      // CR-soon cwong: This is likely subtly broken in the case that the `Var`
      // under inspection comes from something like a `Rep[Array[Var[T]]]`.
      case View.VarNew(ty, v) => ???
      case View.VarGet(x)     => out.emitTerm(x)
      case View.VarSet(x, v)  => {
        out.emitTerm(x)
        out.emit(" = ")
        out.emitMaybeParenthesized(v)
      }
      case View.IfThenElse(guard, tthen, telse) => {
        out.emit("if ")
        out.emitMaybeParenthesized(guard)
        out.emitln(" then {")
        out.indented { out.emitTerm(tthen) }
        out.emitln("")
        out.emitln("} else {")
        out.indented { out.emitTerm(telse) }
        out.emitln("")
        out.emit("}")
      }
      case View.App(f, args) => {
        out.emitMaybeParenthesized(f)
        out.emitArgTerms(args)
      }
      case View.Negate(t) => {
        out.emit("-")
        out.emitMaybeParenthesized(t)
      }
      case View.Plus(x, y)   => out.emitBinop("+", x, y)
      case View.Times(x, y)  => out.emitBinop("*", x, y)
      case View.Minus(x, y)  => out.emitBinop("-", x, y)
      case View.Equals(x, y) => out.emitBinop("==", x, y)
      case View.Lt(x, y)     => out.emitBinop("<", x, y)
      case View.Gt(x, y)     => out.emitBinop(">", x, y)
      case View.Le(x, y)     => out.emitBinop("<=", x, y)
      case View.Ge(x, y)     => out.emitBinop(">=", x, y)
      case View.And(x, y)    => out.emitBinop("&&", x, y)
      case View.Or(x, y)     => out.emitBinop("||", x, y)
      case View.Not(t)       => {
        out.emit("!")
        out.emitMaybeParenthesized(t)
      }
      case View.StrictAnd(x, y) => out.emitBinop("&", x, y)
      case View.StrictOr(x, y)  => out.emitBinop("|", x, y)
      case View.Xor(x, y)       => out.emitBinop("^", x, y)
      case View.BitAnd(x, y)    => out.emitBinop("&", x, y)
      case View.BitOr(x, y)     => out.emitBinop("|", x, y)
      case View.BitXor(x, y)    => out.emitBinop("^", x, y)
      case View.Shl(x, y)       => out.emitBinop("<<", x, y)
      case View.Shr(x, y)       => out.emitBinop(">>", x, y)
      case View.UShr(x, y)      => out.emitBinop(">>>", x, y)
      case View.BitNot(t)       => {
        out.emit("~")
        out.emitMaybeParenthesized(t)
      }
      // `Array.copy` takes offsets that `Op.ArrayCopy` does not have, and both
      // ends always start at zero.
      case View.ArrayCopy(dst, src, len) => {
        out.emit("Array.copy(")
        out.emitTerm(src)
        out.emit(", 0, ")
        out.emitTerm(dst)
        out.emit(", 0, ")
        out.emitTerm(len)
        out.emit(")")
      }
      case View.Range(x, y)   => out.emitBinop("until", x, y)
      case View.RangeStart(t) => {
        out.emitMaybeParenthesized(t)
        out.emit(".start")
      }
      case View.RangeEnd(t) => {
        out.emitMaybeParenthesized(t)
        out.emit(".end")
      }
      case View.While(guard, body) => {
        out.emitln(s"while {")
        out.indented { out.emitTerm(guard) }
        out.emitln("")
        out.emitln("} do {")
        out.indented { out.emitTerm(body) }
        out.emitln("")
        out.emitln("}")
      }
      case View.RangeForEach(name, st, end, body) => {
        out.emit(s"for (${name.render(cfg.varPrefix)} <- ")
        out.emitMaybeParenthesized(st)
        out.emit(" until ")
        out.emitMaybeParenthesized(end)
        out.emitln(") {")
        out.indented { out.emitTerm(body) }
        out.emitln("")
        out.emitln("}")
      }
      case View.ArrayNew(ty, t) => {
        out.emit(s"new Array[${ty.render}](")
        out.emitTerm(t)
        out.emit(")")
      }
      case View.ArrayGet(arr, i) => {
        out.emitMaybeParenthesized(arr)
        out.emit("(")
        out.emitTerm(i)
        out.emit(")")
      }
      case View.ArraySet(arr, i, x) => {
        out.emitMaybeParenthesized(arr)
        out.emit("(")
        out.emitTerm(i)
        out.emit(") = ")
        out.emitTerm(x)
      }
      case View.ArrayLength(arr) => {
        out.emitMaybeParenthesized(arr)
        out.emit(".length")
      }
      case View.Print(t) => {
        out.emit("print(")
        out.emitTerm(t)
        out.emit(")")
      }
      case View.Println(t) => {
        out.emit("println(")
        out.emitTerm(t)
        out.emit(")")
      }
      case View.CharToInt(t) => {
        out.emitMaybeParenthesized(t)
        out.emit(".toInt")
      }
      case View.StringLength(s) => {
        out.emitMaybeParenthesized(s)
        out.emit(".length")
      }
      case View.StringTake(s, n) => {
        out.emitMaybeParenthesized(s)
        out.emit(".take(")
        out.emitMaybeParenthesized(n)
        out.emit(")")
      }
      case View.StringDrop(s, n) => {
        out.emitMaybeParenthesized(s)
        out.emit(".drop(")
        out.emitMaybeParenthesized(n)
        out.emit(")")
      }
      case View.StringStartsWith(s, prefix) => {
        out.emitMaybeParenthesized(s)
        out.emit(".startsWith(")
        out.emitMaybeParenthesized(prefix)
        out.emit(")")
      }
      case View.StringEndsWith(s, suffix) => {
        out.emitMaybeParenthesized(s)
        out.emit(".endsWith(")
        out.emitMaybeParenthesized(suffix)
        out.emit(")")
      }
      case View.StringCharAt(s, i) => {
        out.emitMaybeParenthesized(s)
        out.emit(".charAt(")
        out.emitMaybeParenthesized(i)
        out.emit(")")
      }
      case View.StringSubstring(s, start, end) => {
        out.emitMaybeParenthesized(s)
        out.emit(".slice(")
        out.emitMaybeParenthesized(start)
        out.emit(", ")
        out.emitMaybeParenthesized(end)
        out.emit(")")
      }
      case View.StructGet(repr, t, field) => {
        out.emitMaybeParenthesized(t)
        out.emit(s".$field")
      }
      case View.StructSet(t, field, v) => {
        out.emitMaybeParenthesized(t)
        out.emit(s".$field = ")
        out.emitTerm(v)
      }
    })

    private def emitArgTerms(args: Seq[Term]): Unit = {
      out.emit("(")
      args.zipWithIndex.foreach {
        case (t, i) => {
          if i != 0 then out.emit(", ")
          out.emitTerm(t)
        }
      }
      out.emit(")")
    }

    private def emitBinop(sym: String, x: Term, y: Term): Unit = {
      out.emitMaybeParenthesized(x)
      out.emit(s" $sym ")
      out.emitMaybeParenthesized(y)
    }

    private def emitNamedStaticData(name: Name, data: StaticData): Unit = {
      out.emitln(s"val ${name.render(cfg.varPrefix)} = ${renderStaticData(data)}")
    }

    private def renderStaticData(data: StaticData): String = data match {
      case s @ Scalar(x)         => x.render(using s.prim)
      case SArray(elemTy, elems) => {
        val renderedElems = elems.map(renderStaticData).mkString(",")
        s"Array[${elemTy.render}]($renderedElems)"
      }
    }
}
