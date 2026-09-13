package elms.codegen

import elms.core.*
import elms.core.Op.*
import elms.core.Name
import elms.core.tree as ast
import elms.core.tree.View
import elms.core.given
import elms.util.IndentedWriter
import elms.util.collection.*
import elms.util.Plumbing.traverse
import elms.runtime.Log

class CCodegen(cfg: Config = Config.cDefault) extends Backend(cfg) {
  import ast._

  def emit(prog: Program, out: java.io.PrintStream): Unit = {
    val w = makeIndentedWriter(out)

    w.emitln("#include <stdbool.h>")
    w.emitln("#include <stdio.h>")
    w.emitln("#include <stdlib.h>")
    w.emitln("")

    // Static data is named in the program the same way a function is, so it
    // belongs in the same env: `inferType` has no other way to reach its type.
    val topEnv: Env = prog.functions.map { (fname, fdef) =>
      fname -> functionType(fdef)
    }.toMap ++ prog.staticData.map { (name, data) => name -> data.ty }

    structsIn(prog).foreach { repr => w.emitStructDecl(repr) }

    val customs = prog.functions.flatMap { (_, fdef) =>
      customSignatures(topEnv + (fdef.arg -> fdef.inty))(fdef.body)
    }.distinct

    customs.groupBy(_._1).foreach { (name, sigs) =>
      if sigs.length > 1 then
        Log.error(s"Custom operation `$name` is called at more than one type")
    }

    customs.foreach { (name, ty, argTys) => w.emitCustomHeader(name, ty, argTys) }
    if customs.nonEmpty then w.emitln("")

    prog.staticData.foreach { (name, data) => w.emitNamedStaticData(name, data) }
    if prog.staticData.nonEmpty then w.emitln("")

    prog.functions.foreach { (fname, fdef) => w.emitFunctionHeader(fname, fdef) }

    prog.functions.foreach { (fname, fdef) => w.emitFunction(topEnv)(fname, fdef) }
  }

  // A unit parameter is spelled as C's empty parameter list. `void` cannot name
  // a parameter, and a caller has nothing to pass for it anyway.
  private def renderArgs(name: Name, ty: Type): String = ty match {
    case UNIT => "void"
    case _    => s"${ty.renderParam} ${name.render(cfg.varPrefix)}"
  }

  extension [A: Primitive](x: A)
    def render: String = summon[Primitive[A]] match {
      case UNIT   => s"/* unit */"
      case INT    => s"$x"
      case BOOL   => if x.asInstanceOf[Boolean] then "true" else "false"
      case CHAR   => s"'${escapeChar(x.asInstanceOf[Char])}'"
      case STRING => s"\"${escapeString(x.asInstanceOf[String])}\""
    }

  private def escapeChar(c: Char): String = c match {
    case '\n'             => "\\n"
    case '\r'             => "\\r"
    case '\t'             => "\\t"
    case '\b'             => "\\b"
    case '\f'             => "\\f"
    case '\''             => "\\'"
    case '"'              => "\\\""
    case '\\'             => "\\\\"
    case c if c.isControl => f"\\x${c.toInt}%02x"
    case c                => c.toString
  }

  private def escapeString(s: String): String = s.flatMap {
    case '\n'             => "\\n"
    case '\r'             => "\\r"
    case '\t'             => "\\t"
    case '\b'             => "\\b"
    case '\f'             => "\\f"
    case '"'              => "\\\""
    case '\\'             => "\\\\"
    case c if c.isControl => f"\\x${c.toInt}%02x"
    case c                => c.toString
  }

  protected def renderType(ty: Type): String = ty match {
      case UNIT         => "void"
      case INT          => "int"
      case BOOL         => "bool"
      case CHAR         => "char"
      case STRING       => "const char *"
      // A known length never reaches here. It is storage layout, so it only
      // goes through `renderDeclarator`; elsewhere the array has decayed.
      case ARRAY(t, _)  => s"${t.render} *"
      case STRUCT(repr) => s"struct ${repr.name} *"
      case _ => {
        Log.error(s"Attempted to render unsupported type $ty")
        s"/* Unsupported type $ty */ ???"
      }
    }

  // C declarator syntax wraps the name: a fixed-length array is `int xs[16]`,
  // not `int[16] xs`. Only the positions that lay out storage need it, which is
  // struct members and static data.
  private def renderDeclarator(ty: Type, name: String): String = ty match {
    case ARRAY(inner, Some(n)) => s"${inner.render} $name[$n]"
    case _                     => s"${ty.render} $name"
  }

  extension (ty: Type)
    private def render: String = renderType(ty)
    private def renderParam: String = ty.render
    private def renderElement: String = ty match {
      case ARRAY(t, _) => t.render
      case _           => ty.render
    }

  extension (t: Term)
    private def isSimpleExpr: Boolean = t match {
      case V(_) | E(_: Const[_], Nil)     => true
      case View.Extractors.ArrayGet(_, _) => true
      case View.Extractors.ArrayLength(_) => true
      case View.Extractors.App(_, _)      => true
      case _                              => false
    }

    // Terms with no good C expression form: a `let` needs a GNU statement-
    // expression, and an `if` needs one as soon as either branch has bindings.
    private def needsStatements: Boolean = View.view(t) match {
      case Some(View.Let(_, _, _, _))     => true
      case Some(View.IfThenElse(_, _, _)) => true
      case _                              => false
    }

  private type Env = Map[Name, Type]

  // Where a term's value goes once the statements that compute it have run.
  private enum Sink(val resultTy: Type) {
    case Return(ty: Type) extends Sink(ty)
    case Assign(x: Name, ty: Type) extends Sink(ty)

    // The C that consumes a finished expression, written immediately before it.
    def store: String = this match {
      case Return(_)    => "return "
      case Assign(x, _) => s"${x.render(cfg.varPrefix)} = "
    }
  }

  // A short-circuiting operator, named by when it goes on to evaluate its right
  // operand: `&&` only when the left was true, `||` only when it was false.
  private enum ShortCircuit derives CanEqual { case AndAlso, OrElse }

  // What to hand back for `ty` when there is nothing real to hand back.
  private def zero(ty: Type): String = ty match {
    case INT | CHAR => "0"
    case BOOL       => "false"
    case _          => "NULL"
  }

  // CR-soon cwong: We can probably perform `inferType` at the same time
  // we walk the tree to print it. This would be a quadratic speedup in term
  // size, but I'm reasonably sure that it won't be noticable in practice.

  private def inferType(env: Env)(term: Term): Option[Type] = View.view(term).flatMap {
    case View.V(name) => env.get(name)

    case const @ View.Const(_) => Some(const.prim)

    case View.Custom(name, ty, e) => Some(ty)

    case View.Let(x, _ty, e1, e2) => inferType(env)(e1).flatMap { ty1 =>
        inferType(env + (x -> ty1))(e2)
      }

    case View.IfThenElse(_, tthen, telse) =>
      (inferType(env)(tthen), inferType(env)(telse)) match {
        case (Some(a), Some(b)) if a == b => Some(a)
        case _                            => None
      }

    case View.Negate(_)                                        => Some(INT)
    case View.Plus(_, _) | View.Times(_, _) | View.Minus(_, _) => Some(INT)
    case View.BitAnd(_, _) | View.BitOr(_, _) | View.BitXor(_, _) | View.BitNot(_) |
        View.Shl(_, _) | View.Shr(_, _) | View.UShr(_, _) => Some(INT)
    case View.Equals(_, _) | View.Lt(_, _) | View.Gt(_, _) | View.Le(_, _) | View
          .Ge(_, _) | View.And(_, _) | View.Or(_, _) | View.Not(_) => Some(BOOL)
    case View.StrictAnd(_, _) | View.StrictOr(_, _) | View.Xor(_, _) => Some(BOOL)
    case View.Range(_, _)                      => None
    case View.RangeStart(_) | View.RangeEnd(_) => Some(INT)

    case View.VarNew(ty, t) => Some(ty)
    case View.VarGet(t)     => inferType(env)(t)
    case View.VarSet(_, _)  => Some(UNIT)

    case View.RangeForEach(_, _, _, _) => Some(UNIT)
    case View.While(_, _)              => Some(UNIT)

    case View.ArrayNew(ty, _) => Some(ARRAY(ty))

    case View.ArrayGet(arr, _) => inferType(env)(arr) match {
        case Some(ARRAY(elemTy, _)) => Some(elemTy)
        case _                      => None
      }
    case View.ArraySet(_, _, _)         => Some(UNIT)
    case View.ArrayLength(_)            => Some(INT)
    case View.StructGet(repr, _, field) => repr.get(field)
    case View.StructSet(_, _, _)        => Some(UNIT)

    case View.App(f, x) => inferType(env)(f) match {
        case Some(ARROW(_, out)) => Some(out)
        case _                   => None
      }

    case View.Function(arg, inty, outty, _) => Some(ARROW(inty, outty))

    case View.Print(_) | View.Println(_) => Some(UNIT)

    case View.StringLength(_)          => Some(INT)
    case View.StringCharAt(_, _)       => Some(CHAR)
    case View.StringDrop(_, _)         => Some(STRING)
    case View.StringTake(_, _)         => Some(STRING)
    case View.StringStartsWith(_, _)   => Some(BOOL)
    case View.StringEndsWith(_, _)     => Some(BOOL)
    case View.StringSubstring(_, _, _) => Some(STRING)
  }

  private def functionType(fdef: Function): Type = ARROW(fdef.inty, fdef.outty)

  // `Op.StructSet` carries only the field name, so the receiver's type is the
  // only route to what that field was declared as.
  private def memberType(env: Env)(receiver: Term, field: String): Option[Type] =
    inferType(env)(receiver) match {
      case Some(STRUCT(repr)) => repr.get(field)
      case _                  => None
    }

  // Every struct the program mentions, including any reached only through
  // another struct's fields. A struct is always behind a pointer in the C this
  // backend emits, so nothing depends on the order these come out in.
  private def structsIn(prog: Program): Seq[StructRepr] = {
    def fromType(seen: Set[String])(ty: Type): Seq[StructRepr] = ty match {
      case STRUCT(repr) if seen(repr.name) => Seq()
      case STRUCT(repr) => repr +: repr.members.values.toSeq
          .flatMap(fromType(seen + repr.name))
      case ARRAY(inner, _) => fromType(seen)(inner)
      case ARROW(a, b)     => fromType(seen)(a) ++ fromType(seen)(b)
      case _               => Seq()
    }

    def fromOp(op: Op): Seq[Type] = op match {
      case Op.VarNew(ty)         => Seq(ty)
      case Op.ArrayNew(ty)       => Seq(ty)
      case ai @ Op.ArrayInit(_)  => Seq(ARRAY(ai.elemTy))
      case Op.StructGet(repr, _) => Seq(STRUCT(repr))
      case Op.Custom(_, ty)      => Seq(ty)
      case _                     => Seq()
    }

    def fromTerm(term: Term): Seq[Type] = term match {
      case V(_)                           => Seq()
      case Let(_, e1, e2)                 => fromTerm(e1) ++ fromTerm(e2)
      case Function(_, inty, outty, body) => inty +: outty +: fromTerm(body)
      case E(op, children)                => fromOp(op) ++ children.flatMap(fromTerm)
    }

    prog.functions.flatMap { (_, fdef) =>
      (fdef.inty +: fdef.outty +: fromTerm(fdef.body)).flatMap(fromType(Set()))
    }.distinctBy(_.name)
  }

  // Every custom operation the program calls, with the types of its call site.
  // `Op.Custom` carries only the result type, so the arguments have to come out
  // of inference.
  private def customSignatures(env: Env)(term: Term): Seq[(String, Type, Seq[Type])] =
    term match {
      case V(_) => Seq()

      case Let(x, e1, e2) => customSignatures(env)(e1) ++
          customSignatures(env.setOrRemove(x, inferType(env)(e1)))(e2)

      case Function(arg, inty, _, body) => customSignatures(env + (arg -> inty))(body)

      case E(op, children) => {
        val nested = children.flatMap(customSignatures(env))

        op match {
          case Op.Custom(name, ty) => children.map(inferType(env)).traverse match {
              case Some(argTys) => (name, ty, argTys.filterNot(_ == UNIT)) +: nested
              case None         => {
                Log.error(s"Could not infer the argument types of `$name`: $term")
                nested
              }
            }

          case _ => nested
        }
      }
    }

  extension (out: IndentedWriter)
    private def emitStructDecl(repr: StructRepr): Unit = {
      out.emitln(s"struct ${repr.name} {")
      out.indented {
        repr.members.foreach { (field, ty) =>
          out.emitln(s"${renderDeclarator(ty, field)};")
        }
      }
      out.emitln("};")
      out.emitln("")
    }

    private def emitCustomHeader(name: String, ty: Type, argTys: Seq[Type]): Unit = {
      val params =
        if argTys.isEmpty then "void" else argTys.map(_.renderParam).mkString(", ")
      out.emitln(s"${ty.render} $name($params);")
    }

    // CR cwong: merge this with `emitFunction`
    private inline def emitFunctionHeader(fname: Name, fdef: Function): Unit = {
      val Function(arg, inty, outty, body) = fdef
      val argsS = renderArgs(arg, inty)
      out.emitln(s"${outty.render} ${fname.render(cfg.varPrefix)}($argsS);")
    }

    private inline def withView(t: Term)(k: View => Unit): Unit = View.view(t)
      .fold { out.invalidTerm(s"Got invalid expression term: $t") }(k)

    private def invalidTerm(msg: String): Unit = {
      Log.error(msg)
      out.emit("/* ERROR: ")
      out.emit(msg.replace("*/", "* /"))
      out.emit(" */")
    }

    private def emitFunction(topEnv: Env)(fname: Name, fdef: Function): Unit = {
      val Function(arg, inty, outty, body) = fdef

      val env = topEnv + (arg -> inty)
      val argsS = renderArgs(arg, inty)

      out.emitln(s"${outty.render} ${fname.render(cfg.varPrefix)}($argsS) {")
      out.indented {
        if outty == UNIT then out.emitStmt(env)(body)
        else out.emitInto(env, Sink.Return(outty))(body)
      }
      out.emitln("}")
      out.emitln("")
    }

    private def emitMaybeParenthesizedExpr(env: Env)(t: Term): Unit = {
      if t.isSimpleExpr then out.emitExpr(env)(t)
      else {
        out.emit("(")
        out.emitExpr(env)(t)
        out.emit(")")
      }
    }

    private def emitAssign(env: Env)(x: Name, e: Term): Option[Type] = {
      val ty = inferType(env)(e)

      ty match {
        case Some(UNIT) => out.emitStmt(env)(e)

        case Some(ty) => View.view(e) match {
          case Some(View.And(lhs, rhs)) if rhs.needsStatements =>
            out.emitShortCircuit(env)(x, lhs, rhs, ShortCircuit.AndAlso)

          case Some(View.Or(lhs, rhs)) if rhs.needsStatements =>
            out.emitShortCircuit(env)(x, lhs, rhs, ShortCircuit.OrElse)

          // Declare the variable up front and let the term assign into it. Its
          // pieces only fit in a C expression inside a GNU statement-expression.
          case _ if e.needsStatements => {
            out.emitln(s"${ty.render} ${x.render(cfg.varPrefix)};")
            out.emitInto(env, Sink.Assign(x, ty))(e)
          }

          case _ => {
            out.emit(s"${ty.render} ${x.render(cfg.varPrefix)} = ")
            out.emitExpr(env)(e)
            out.emitln(";")
          }
        }

        case None => {
          out.invalidTerm(s"Could not infer C type for let-bound term: $e")
          out.emitln(";")
        }
      }

      ty
    }

    private def emitExpr(env: Env)(term: Term): Unit = out.withView(term) {
      // A unit-typed name has no C value behind it. A unit parameter is not in
      // the signature, and a unit-typed binding declares no variable.
      case View.V(name) => env.get(name) match {
        case Some(UNIT) => out.emit("/* unit */")
        case _          => out.emit(name.render(cfg.varPrefix))
      }

      case const @ View.Const(_) => out.emit(const.value.render(using const.prim))

      case View.App(f, args) => {
        out.emitMaybeParenthesizedExpr(env)(f)
        out.emitArgTerms(env)(args)
      }

      case View.Custom(name, ty, args) => {
        out.emit(name)
        out.emitArgTerms(env)(args)
      }

      case View.Negate(t) => {
        out.emit("-")
        out.emitMaybeParenthesizedExpr(env)(t)
      }

      case View.Plus(x, y)   => out.emitBinop(env)("+", x, y)
      case View.Times(x, y)  => out.emitBinop(env)("*", x, y)
      case View.Minus(x, y)  => out.emitBinop(env)("-", x, y)
      case View.Equals(x, y) => out.emitBinop(env)("==", x, y)
      case View.Lt(x, y)     => out.emitBinop(env)("<", x, y)
      case View.Gt(x, y)     => out.emitBinop(env)(">", x, y)
      case View.Le(x, y)     => out.emitBinop(env)("<=", x, y)
      case View.Ge(x, y)     => out.emitBinop(env)(">=", x, y)
      case View.And(x, y)    => out.emitBinop(env)("&&", x, y)
      case View.Or(x, y)     => out.emitBinop(env)("||", x, y)
      case View.Not(t)       => {
        out.emit("!")
        out.emitMaybeParenthesizedExpr(env)(t)
      }

      // Two `bool`s under C's `&` promote to `int` and come back 0 or 1, so the
      // plain operator is already the right thing here.
      case View.StrictAnd(x, y) => out.emitBinop(env)("&", x, y)
      case View.StrictOr(x, y)  => out.emitBinop(env)("|", x, y)
      case View.Xor(x, y)       => out.emitBinop(env)("^", x, y)

      case View.BitAnd(x, y) => out.emitBinop(env)("&", x, y)
      case View.BitOr(x, y)  => out.emitBinop(env)("|", x, y)
      case View.BitXor(x, y) => out.emitBinop(env)("^", x, y)
      case View.Shl(x, y)    => out.emitBinop(env)("<<", x, y)
      case View.Shr(x, y)    => out.emitBinop(env)(">>", x, y)
      case View.BitNot(t)    => {
        out.emit("~")
        out.emitMaybeParenthesizedExpr(env)(t)
      }

      // `>>` on a signed `int` is arithmetic, so the zero-fill has to happen in
      // `unsigned int` and come back. The outer cast is what keeps the result
      // typed `int` for `inferType`; it is implementation-defined for shifts
      // that land above `INT_MAX`, which is as close as C gets to Scala's
      // wrapping `>>>`.
      case View.UShr(x, y) => {
        out.emit("(int)((unsigned int)")
        out.emitMaybeParenthesizedExpr(env)(x)
        out.emit(" >> ")
        out.emitMaybeParenthesizedExpr(env)(y)
        out.emit(")")
      }

      // Only reachable from an operand position. Anything bound to a variable
      // takes the statement form in `emitAssign`.
      case View.IfThenElse(guard, tthen, telse) => {
        out.emit("(")
        out.emitExpr(env)(guard)
        out.emit(" ? ")
        out.emitExpr(env)(tthen)
        out.emit(" : ")
        out.emitExpr(env)(telse)
        out.emit(")")
      }

      case View.VarNew(ty, t) => out.emitExpr(env)(t)
      case View.VarGet(t)     => out.emitExpr(env)(t)
      case View.VarSet(_, _)  => {
        out.emit("({")
        out.emitStmt(env)(term)
        out.emit("})")
      }

      // An array of fixed-length arrays needs `int (*)[16]` and a `sizeof` to
      // match, and `renderType` has no declarator to build either from.
      case View.ArrayNew(ty, t) => ty match {
        case ARRAY(_, Some(_)) => out
            .invalidTerm(s"C backend cannot allocate fixed-length arrays: $ty")

        case _ => {
          out.emit(s"(${ARRAY(ty).render})malloc(sizeof(${ty.render}) * ")
          out.emitExpr(env)(t)
          out.emit(")")
        }
      }

      case View.ArrayGet(arr, i) => {
        out.emitExpr(env)(arr)
        out.emit("[")
        out.emitExpr(env)(i)
        out.emit("]")
      }

      case View.ArraySet(_, _, _) => {
        out.emit("({")
        out.emitStmt(env)(term)
        out.emit("})")
      }

      case View.ArrayLength(arr) => inferType(env)(arr) match {
        case Some(ARRAY(_, Some(n))) => out.emit(n.toString)
        case _ => out.invalidTerm(
            s"C backend cannot emit array length without explicit length metadata: $arr"
          )
      }

      case View.StructGet(repr, t, field) => {
        out.emitMaybeParenthesizedExpr(env)(t)
        out.emit(s"->$field")
      }

      case View.StructSet(_, _, _) => {
        out.emit("({")
        out.emitStmt(env)(term)
        out.emit("})")
      }

      case View.RangeStart(t) => out
          .invalidTerm(s"C backend has no first-class range value: $t")

      case View.RangeEnd(t) => out
          .invalidTerm(s"C backend has no first-class range value: $t")

      case View.Range(_, _) => out.invalidTerm(
          s"C backend only supports ranges directly in foreach loops: $term"
        )

      case View.Let(x, _ty, e1, e2) => out.emitLetExpr(env)(x, e1, e2)

      case View.RangeForEach(_, _, _, _) => out
          .invalidTerm(s"for-loop cannot be emitted as a C expression: $term")

      case View.While(_, _) => out
          .invalidTerm(s"while-loop cannot be emitted as a C expression: $term")

      case View.Function(_, _, _, _) => out
          .invalidTerm(s"C backend does not support anonymous functions/lambdas: $term")

      case View.Print(t)   => out.emitPrintf(env)(t, "")
      case View.Println(t) => out.emitPrintf(env)(t, "\\n")

      case View.StringLength(_)          => ???
      case View.StringCharAt(_, _)       => ???
      case View.StringDrop(_, _)         => ???
      case View.StringTake(_, _)         => ???
      case View.StringStartsWith(_, _)   => ???
      case View.StringEndsWith(_, _)     => ???
      case View.StringSubstring(_, _, _) => ???
    }

    // CR-someday cwong: There is a decent amount of duplication when emitting
    // the same term in statement or expr position.

    private def emitStmt(env: Env)(term: Term): Unit = out.withView(term) {
      case View.Let(x, _ty, e1, e2) => {
        val ty = emitAssign(env)(x, e1)
        out.emitStmt(env.setOrRemove(x, ty))(e2)
      }

      case View.IfThenElse(guard, tthen, telse) => {
        out.emit("if (")
        out.emitExpr(env)(guard)
        out.emitln(") {")
        out.indented { out.emitStmt(env)(tthen) }
        out.emitln("} else {")
        out.indented { out.emitStmt(env)(telse) }
        out.emitln("}")
      }

      case View.RangeForEach(name, st, end, body) => {
        out.emit(s"for (int ${name.render(cfg.varPrefix)} = ")
        out.emitExpr(env)(st)
        out.emit("; ")
        out.emit(name.render(cfg.varPrefix))
        out.emit(" < ")
        out.emitExpr(env)(end)
        out.emit("; ")
        out.emit(name.render(cfg.varPrefix))
        out.emitln("++) {")
        out.indented { out.emitStmt(env + (name -> INT))(body) }
        out.emitln("}")
      }

      case View.While(guard, body) => {
        out.emit("while (")
        out.emitExpr(env)(guard)
        out.emitln(") {")
        out.indented { out.emitStmt(env)(body) }
        out.emitln("}")
      }

      case View.ArraySet(arr, i, x) => {
        out.emitExpr(env)(arr)
        out.emit("[")
        out.emitExpr(env)(i)
        out.emit("] = ")
        out.emitExpr(env)(x)
        out.emitln(";")
      }

      case View.VarSet(x, v) => {
        out.emitExpr(env)(x)
        out.emit(" = ")
        out.emitExpr(env)(v)
        out.emitln(";")
      }

      // A fixed-length member is inline storage, and C has no assignment
      // operator for an array, so `s->xs = v` does not compile. Indexing into
      // the member is unaffected and still goes through `ArraySet`.
      //
      // CR-someday cwong: To allow the whole-member write, we could emit
      // `memcpy(s->xs, v, sizeof s->xs)`. However, that may lead to soundness
      // errors, as we won't be able to ensure that the source and target are
      // the right length due to `structSet` taking `Rep[Any]`.
      case View.StructSet(x, field, v) => memberType(env)(x, field) match {
        case Some(ARRAY(_, Some(_))) => {
          out.invalidTerm(s"Cannot assign to fixed-length array member `$field`")
          out.emitln(";")
        }

        case _ => {
          out.emitMaybeParenthesizedExpr(env)(x)
          out.emit(s"->$field = ")
          out.emitExpr(env)(v)
          out.emitln(";")
        }
      }

      case View.App(_, _) => {
        out.emitExpr(env)(term)
        out.emitln(";")
      }

      case View.Function(_, _, _, _) => {
        out
          .invalidTerm(s"C backend does not support anonymous functions/lambdas: $term")
        out.emitln(";")
      }

      case const @ View.Const(_) if const.prim.is(UNIT).isDefined => out.emitln(";")

      case _ => {
        out.emitExpr(env)(term)
        out.emitln(";")
      }
    }

    // Evaluate the left operand into `x`, then overwrite it from inside the `if`
    // that decides whether the right operand runs. Statements belonging to the
    // right operand cannot sit beside the expression, because it only sometimes
    // runs.
    private def emitShortCircuit(
        env: Env
    )(x: Name, lhs: Term, rhs: Term, op: ShortCircuit): Unit = {
      val ty = emitAssign(env)(x, lhs).getOrElse(BOOL)
      val test = op match {
        case ShortCircuit.AndAlso => x.render(cfg.varPrefix)
        case ShortCircuit.OrElse  => s"!${x.render(cfg.varPrefix)}"
      }

      out.emitln(s"if ($test) {")
      out.indented { out.emitInto(env, Sink.Assign(x, ty))(rhs) }
      out.emitln("}")
    }

    private def emitInto(env: Env, sink: Sink)(term: Term): Unit = out
      .withView(term) {
        case View.Let(x, _ty, e1, e2) => {
          val ty = emitAssign(env)(x, e1).getOrElse(UNIT)
          out.emitInto(env + (x -> ty), sink)(e2)
        }

        case View.IfThenElse(guard, tthen, telse) => {
          out.emit("if (")
          out.emitExpr(env)(guard)
          out.emitln(") {")
          out.indented { out.emitInto(env, sink)(tthen) }
          out.emitln("} else {")
          out.indented { out.emitInto(env, sink)(telse) }
          out.emitln("}")
        }

        case View.RangeForEach(_, _, _, _) => {
          out.invalidTerm(s"Cannot use the result of a for-loop in C: $term")
          out.emitln(";")
          out.emitFallback(sink)
        }

        case View.While(_, _) => {
          out.invalidTerm(s"Cannot use the result of a while-loop in C: $term")
          out.emitln(";")
          out.emitFallback(sink)
        }

        case View.Function(_, _, _, _) => {
          out.invalidTerm(
            s"C backend does not support anonymous functions/lambdas: $term"
          )
          out.emitln(";")
          out.emitFallback(sink)
        }

        case _ => {
          out.emit(sink.store)
          out.emitExpr(env)(term)
          out.emitln(";")
        }
      }

    // Store something of the right type after a term that has no C form at all.
    // The error itself is already logged; this only keeps the surrounding
    // function compiling.
    private def emitFallback(sink: Sink): Unit = sink match {
      case Sink.Return(UNIT) => out.emitln("return;")
      case _                 => out.emitln(s"${sink.store}${zero(sink.resultTy)};")
    }

    private def emitLetExpr(env: Env)(x: Name, e1: Term, e2: Term): Unit = {
      out.emitln("({")
      out.indented {
        val ty = emitAssign(env)(x, e1)
        out.emitExprResult(env.setOrRemove(x, ty))(e2)
      }
      out.emit("})")
    }

    private def emitExprResult(env: Env)(term: Term): Unit = out.withView(term) {
      case View.Let(x, _ty, e1, e2) => {
        val ty = emitAssign(env)(x, e1)
        out.emitExprResult(env.setOrRemove(x, ty))(e2)
      }

      case View.IfThenElse(guard, tthen, telse) => {
        out.emit("if (")
        out.emitExpr(env)(guard)
        out.emitln(") {")
        out.indented { out.emitExprResult(env)(tthen) }
        out.emitln("} else {")
        out.indented { out.emitExprResult(env)(telse) }
        out.emitln("}")
      }

      case View.RangeForEach(name, st, end, body) => {
        out.emit(s"for (int ${name.render(cfg.varPrefix)} = ")
        out.emitExpr(env)(st)
        out.emit("; ")
        out.emit(name.render(cfg.varPrefix))
        out.emit(" < ")
        out.emitExpr(env)(end)
        out.emit("; ")
        out.emit(name.render(cfg.varPrefix))
        out.emitln("++) {")
        out.indented { out.emitStmt(env + (name -> INT))(body) }
        out.emitln("}")
        out.emitln("/* unit */;")
      }

      case View.While(guard, body) => {
        out.emit("while (")
        out.emitExpr(env)(guard)
        out.emitln(") {")
        out.indented { out.emitStmt(env)(body) }
        out.emitln("}")
        out.emitln("/* unit */;")
      }

      case View.ArraySet(arr, i, x) => {
        out.emitExpr(env)(arr)
        out.emit("[")
        out.emitExpr(env)(i)
        out.emit("] = ")
        out.emitExpr(env)(x)
        out.emitln(";")
      }

      case View.Function(_, _, _, _) => {
        out
          .invalidTerm(s"C backend does not support anonymous functions/lambdas: $term")
        out.emitln(";")
      }

      case _ => {
        out.emitExpr(env)(term)
        out.emitln(";")
      }
    }

    // Unit arguments are dropped, to match the parameter list `renderArgs` built.
    // `printf` needs the conversion that matches its argument, and `%s` was only
    // ever right for strings.
    private def emitPrintf(env: Env)(t: Term, terminator: String): Unit = {
      def call(conv: String)(arg: => Unit): Unit = {
        out.emit(s"""printf("$conv$terminator", """)
        arg
        out.emit(")")
      }

      inferType(env)(t) match {
        case Some(STRING) => call("%s") { out.emitExpr(env)(t) }
        case Some(INT)    => call("%d") { out.emitExpr(env)(t) }
        case Some(CHAR)   => call("%c") { out.emitExpr(env)(t) }

        // A `bool` has no conversion of its own, so it prints the two words
        // Scala's `println` would have printed for it.
        case Some(BOOL) => call("%s") {
            out.emitMaybeParenthesizedExpr(env)(t)
            out.emit(" ? \"true\" : \"false\"")
          }

        case Some(UNIT) => out.emit(s"""printf("()$terminator")""")

        case ty => out
            .invalidTerm(s"C backend cannot print a value of type $ty: $t")
      }
    }

    private def emitArgTerms(env: Env)(args: Seq[Term]): Unit = {
      val passed = args.filterNot { t => inferType(env)(t).exists(_ == UNIT) }

      out.emit("(")
      passed.zipWithIndex.foreach { case (t, i) =>
        if i != 0 then out.emit(", ")
        out.emitExpr(env)(t)
      }
      out.emit(")")
    }

    private def emitBinop(env: Env)(sym: String, x: Term, y: Term): Unit = {
      out.emitMaybeParenthesizedExpr(env)(x)
      out.emit(s" $sym ")
      out.emitMaybeParenthesizedExpr(env)(y)
    }

    private def emitNamedStaticData(name: Name, data: StaticData): Unit = {
      val decl = renderDeclarator(data.ty, name.render(cfg.varPrefix))
      out.emitln(s"static const $decl = ${renderStaticDataInitializer(data)};")
    }

    private def renderStaticDataInitializer(data: StaticData): String = data match {
      case s @ Scalar(x) => x.render(using s.prim)

      case SArray(_, elems) => elems.map(renderStaticDataInitializer)
          .mkString("{", ", ", "}")
    }
}
