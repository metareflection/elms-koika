package elms.codegen

import elms.core.*
import elms.core.Op.*
import elms.core.Name
import elms.core.tree as ast
import elms.core.tree.{Note, View}
import elms.core.given
import elms.util.IndentedWriter
import elms.util.collection.*
import elms.util.Plumbing.{mapRight, traverse}
import elms.pipeline.InlineRanges
import elms.runtime.{Log, LMSRuntimeException}

object CCodegen {
  // What the emitted C is allowed to rely on.
  //
  // `autoIncludes` is about the file, not the features: a program generated to
  // be `#include`d into another translation unit already has its headers, and
  // repeating them is noise. Turning it off never changes what is emitted below
  // the includes, so the two are independent knobs.
  case class Options(
      autoIncludes: Boolean = true,
      fatArrays: Boolean = true,
      firstClassRanges: Boolean = true
  )
}

class CCodegen(
    cfg: Config = Config.cDefault,
    opts: CCodegen.Options = CCodegen.Options()
) extends Backend(cfg) {
  import ast._

  // C has no closures, and the three backstop sites below cannot produce
  // anything that compiles. `SnippetDriver` reads this and refuses a `lam`
  // where it was written, which is the only place the line number still exists.
  override def supportsLambdas: Boolean = false

  // The body decides the includes, so it is emitted into a buffer first and the
  // includes are written in front of whatever it turned out to ask for.
  //
  // `captured` is not reused for this: it builds its writer at indent level 0,
  // and the one other caller wants exactly that.
  def emit(prog: Program, out: java.io.PrintStream): Unit = {
    headers.clear()

    val buf = new java.io.ByteArrayOutputStream()
    emitBody(prog, makeIndentedWriter(new java.io.PrintStream(buf)))

    val w = makeIndentedWriter(out)
    if opts.autoIncludes && headers.nonEmpty then {
      headers.toSeq.sortBy(_.ordinal).foreach { h => w.emitln(h.render) }
      w.emitln("")
    }

    out.print(buf.toString("utf-8"))
  }

  private def emitBody(prog: Program, w: IndentedWriter): Unit = {
    // Every loop reaches here with a range value in it that C has no type for,
    // so they come out before anything looks at the program. Before `structsIn`
    // and `customSignatures` so that both see the lowered form.
    //
    // `ScalaCodegen` does not do this. `x until y`, `.start` and `.end` all
    // emit correctly there, and running the pass would churn its snapshots to
    // tidy output that was already right.
    val lowered = Program(
      prog.functions.map(_.mapRight(_.map(InlineRanges.run))),
      prog.staticData
    )

    // Static data is named in the program the same way a function is, so it
    // belongs in the same env: `inferType` has no other way to reach its type.
    val topEnv: Env = lowered.functions.map { (fname, fdef) =>
      fname -> functionType(fdef)
    }.toMap ++ lowered.staticData.map { (name, data) => name -> data.ty }

    // Before anything renders a type, since `renderType` reads the answer. With
    // `fatArrays` off this stays empty and every array below takes its
    // bare-pointer branch.
    fatElems =
      if !opts.fatArrays then Set.empty
      else lowered.functions.flatMap { (_, fdef) =>
        fatElementTypes(topEnv ++ fdef.args)(fdef.body)
      }.toSet.filter { elem => elemTag(elem).isDefined }

    // Ahead of the struct declarations, because a struct can have a fat array
    // as a member and would then name a type that did not exist yet. The other
    // direction needs no ordering: a struct element renders as `struct Foo *`,
    // and a pointer to an incomplete type is fine in a typedef.
    //
    // Among themselves they go in dependency order, since `elms_arr_arr_int`
    // is declared in terms of `elms_arr_int`. That edge is nesting depth, so
    // sorting on it is the whole topological sort.
    val fatDecls = fatElems.toSeq
      .flatMap { elem => fatName(elem).map { name => (depth(elem), name, elem) } }
      .sortBy { (d, name, _) => (d, name) }

    fatDecls.foreach { (_, name, elem) =>
      w.emitln(s"ELMS_ARR_DECL($name, ${elem.render})")
    }
    if fatDecls.nonEmpty then w.emitln("")

    structsIn(lowered).foreach { repr => w.emitStructDecl(repr) }

    val customs = lowered.functions.flatMap { (_, fdef) =>
      customSignatures(topEnv ++ fdef.args)(fdef.body)
    }.distinct

    customs.groupBy(_._1).foreach { (name, sigs) =>
      if sigs.length > 1 then
        Log.error(s"Custom operation `$name` is called at more than one type")
    }

    customs.foreach { (name, ty, argTys) => w.emitCustomHeader(name, ty, argTys) }
    if customs.nonEmpty then w.emitln("")

    lowered.staticData.foreach { (name, data) => w.emitNamedStaticData(name, data) }
    if lowered.staticData.nonEmpty then w.emitln("")

    lowered.functions
      .foreach { (fname, fdef) => w.emitFunctionHeader(topEnv)(fname, fdef) }

    lowered.functions.foreach { (fname, fdef) => w.emitFunction(topEnv)(fname, fdef) }
  }

  // A unit parameter is spelled as C's empty parameter list. `void` cannot name
  // a parameter, and a caller has nothing to pass for it anyway.
  // `void` when nothing survives, which is what `emitArgTerms` already does at
  // the call: C cannot pass a unit and nothing generated computes one by
  // passing it. A parameter list that is all units is therefore empty, not a
  // list of nothings.
  private def renderArgs(args: Seq[(Name, Type)]): String = {
    val passed = args.filterNot { (_, ty) => ty == UNIT }
    if passed.isEmpty then "void"
    else passed.map { (n, ty) => s"${ty.renderParam} ${n.render(cfg.varPrefix)}" }
      .mkString(", ")
  }

  extension [A: Primitive](x: A)
    def render: String = summon[Primitive[A]] match {
      case UNIT   => s"/* unit */"
      case INT    => s"$x"
      case BOOL   => {
        need(Header.StdBool)
        if x.asInstanceOf[Boolean] then "true" else "false"
      }
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
      case BOOL         => { need(Header.StdBool); "bool" }
      case CHAR         => "char"
      case STRING       => "const char *"
      // A known length never reaches here. It is storage layout, so it only
      // goes through `renderDeclarator`; elsewhere the array has decayed to a
      // pointer, or to the struct that carries the length the pointer lost.
      case ty @ ARRAY(t, _) => fatName(t) match {
          case Some(name) if isFat(ty) => {
            need(Header.ElmsLib)
            name
          }
          case _ => s"${t.render} *"
        }
      case STRUCT(repr) => s"struct ${repr.name} *"

      case RANGE => elmsRange("elms_range")

      // Its own case rather than the generic branch, which would say
      // `Unsupported type ARROW(INT,INT)` and leave the reader to work out
      // that a name is the fix.
      case ARROW(_, _) => {
        val msg = "no C type for a function value; C has no closures, so give" +
          " the function a name with `fun` and call it directly"
        Log.error(msg)
        s"/* ERROR: $msg */"
      }

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
      case View.Extractors.RangeStart(_)  => true
      case View.Extractors.RangeEnd(_)    => true
      case View.Extractors.App(_, _)      => true
      case _                              => false
    }

    // Terms with no good C expression form: a `let` needs a GNU statement-
    // expression, and an `if` needs one as soon as either branch has bindings.
    private def needsStatements: Boolean = View.view(t) match {
      case Some(View.Let(_, _, _, _, _))  => true
      case Some(View.IfThenElse(_, _, _)) => true
      case _                              => false
    }

  private type Env = Map[Name, Type]

  // What an interpolated argument looks like in the text. It goes through the
  // same parenthesisation an operand gets, or `$y * 2` with `y = a + b` comes
  // out as `a + b * 2`, which is a different predicate.
  private def operand(env: Env)(t: Term): String =
    captured { w => w.emitMaybeParenthesizedExpr(env)(t) }

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

  // Which C headers the emitted body turned out to need. Recorded while
  // emitting rather than worked out beforehand: the emitter deciding to write
  // `malloc` is the only thing that makes `stdlib.h` necessary, so the two
  // cannot drift.
  //
  // Declaration order is emission order, so the includes come out the same way
  // whatever order the emitter discovered them in.
  private enum Header derives CanEqual {
    case StdBool, StdIO, StdLib, String, ElmsLib

    def render: String = this match {
      case StdBool => "#include <stdbool.h>"
      case StdIO   => "#include <stdio.h>"
      case StdLib  => "#include <stdlib.h>"
      case String  => "#include <string.h>"
      // Quoted and not angled: it is ours, and it is found next to the
      // generated file rather than on the system include path.
      case ElmsLib => "#include \"elms_lib.h\""
    }
  }

  // Reset at the top of `emit`. A `CCodegen` is reusable, and a header the last
  // program needed is not a header this one does.
  private val headers = scala.collection.mutable.Set[Header]()
  private def need(h: Header): Unit = { val _ = headers.add(h) }

  // `text` when the emitted C is allowed to name `elms_range`, and a refusal
  // naming the option to turn back on when it is not.
  //
  // A range only reaches one of these positions if it survived `InlineRanges`,
  // so it really did escape its `foreach`. Every position that would name the
  // struct comes through here, which is what stops the option being off from
  // leaving a reference to a type the file no longer includes. `text` is
  // by-name so a refused position renders no operands either.
  private def elmsRange(text: => String): String =
    if opts.firstClassRanges then {
      need(Header.ElmsLib)
      text
    } else {
      val msg = "a range escaped its `foreach`, and `firstClassRanges` is off:" +
        " enable it, or keep the range inside the loop"
      Log.error(msg)
      s"/* ERROR: $msg */"
    }

  // Element types whose dynamic arrays carry their length. Reset at the top of
  // `emit`, for the same reason `headers` is.
  //
  // Promotion is per element type and program-wide: if anything measures an
  // `ARRAY(INT, None)` then every one of them is a struct. A caller and a
  // callee have to agree on a parameter's C type, and keying on the type is
  // what makes them agree without a whole-program fixpoint over parameters,
  // returns, members and elements. It is coarser than necessary, and an
  // `Array[Int]` nobody measures pays a word and an indirection for it.
  private var fatElems: Set[Type] = Set.empty

  private def isFat(ty: Type): Boolean = ty match {
    case ARRAY(elem, None) => fatElems.contains(elem)
    case _                 => false
  }

  // A C identifier for an element type, so `ELMS_ARR_DECL` has a name to
  // declare. `None` is a type whose arrays cannot be promoted: `UNIT` has no
  // storage, `ARROW` has no C type at all, and a fixed-length element needs
  // declarator syntax `renderType` cannot build.
  private def elemTag(ty: Type): Option[String] = ty match {
    case INT            => Some("int")
    case BOOL           => Some("bool")
    case CHAR           => Some("char")
    case STRING         => Some("str")
    case STRUCT(repr)   => Some(repr.name)
    case ARRAY(t, None) => elemTag(t).map("arr_" + _)
    case _              => None
  }

  private def fatName(elem: Type): Option[String] = elemTag(elem).map("elms_arr_" + _)

  // How many arrays deep a type is, which is the only ordering the
  // instantiations need: a fat array of a fat array comes after the one it is
  // declared in terms of.
  private def depth(ty: Type): Int = ty match {
    case ARRAY(t, None) => 1 + depth(t)
    case _              => 0
  }

  // Every element type whose dynamic arrays something takes the length of. A
  // fixed-length array already knows its length statically, so it contributes
  // nothing.
  //
  // `inferType` answers in `Type` and never asks how a type renders, so this
  // can run before anything is emitted and `renderType` can read the result.
  private def fatElementTypes(env: Env)(term: Term): Set[Type] = term match {
    case V(_) => Set.empty

    case Let(x, e1, e2, _) => fatElementTypes(env)(e1) ++
        fatElementTypes(env.setOrRemove(x, inferType(env)(e1)))(e2)

    case Function(args, _, body, _) => fatElementTypes(env ++ args)(body)

    case E(op, children) => {
      val nested = children.flatMap(fatElementTypes(env)).toSet
      op match {
        case Op.ArrayLength => children.headOption.flatMap(inferType(env)) match {
            case Some(ARRAY(elem, None)) => nested + elem
            case _                       => nested
          }
        case _ => nested
      }
    }
  }

  private def loopInExpr(what: String, term: Term): LMSRuntimeException =
    LMSRuntimeException(
      s"BUG: a `$what` reached a value position; a loop is UNIT-typed and ANF" +
        s" binds it to a name before any use: $term"
    )

  // What to hand back for `ty` when there is nothing real to hand back.
  private def zero(ty: Type): String = ty match {
    case INT | CHAR => "0"
    case BOOL       => "false"
    // `NULL` is not a value of a struct type. Only reachable once an error has
    // already been reported, but a second breakage on top of the first is what
    // makes the output hard to read.
    case RANGE => elmsRange("elms_range_mk(0, 0)")
    // `NULL` is not a value of a struct type, so a fat array needs one of its
    // own. Only reachable once an error has been reported, which is not a
    // reason to emit a second one on top.
    case ty @ ARRAY(t, _) if isFat(ty) => fatName(t) match {
        case Some(name) => {
          need(Header.ElmsLib)
          s"${name}_zero()"
        }
        case None => "NULL"
      }
    case _ => "NULL"
  }

  // CR-soon cwong: We can probably perform `inferType` at the same time
  // we walk the tree to print it. This would be a quadratic speedup in term
  // size, but I'm reasonably sure that it won't be noticable in practice.

  private def inferType(env: Env)(term: Term): Option[Type] = View.view(term).flatMap {
    case View.V(name) => env.get(name)

    case const @ View.Const(_) => Some(const.prim)

    case View.Custom(name, ty, e) => Some(ty)

    case View.Let(x, _ty, e1, e2, _) => inferType(env)(e1).flatMap { ty1 =>
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
    case View.Range(_, _)                      => Some(RANGE)
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
    case View.ArrayCopy(_, _, _)        => Some(UNIT)
    case View.ArrayLength(_)            => Some(INT)
    case View.StructGet(repr, _, field) => repr.get(field)
    case View.StructSet(_, _, _)        => Some(UNIT)

    case View.App(f, x) => inferType(env)(f) match {
        case Some(ARROW(_, out)) => Some(out)
        case _                   => None
      }

    case View.Function(args, outty, _, _) => Some(ARROW(args.map(_._2), outty))

    case View.Print(_) | View.Println(_) => Some(UNIT)
    // `UNIT`, the route `Print` already takes, which is what keeps `emitAssign`
    // from declaring a variable for a comment.
    case View.Comment(_, _, _)           => Some(UNIT)

    case View.CharToInt(_)             => Some(INT)
    case View.StringLength(_)          => Some(INT)
    case View.StringCharAt(_, _)       => Some(CHAR)
    case View.StringDrop(_, _)         => Some(STRING)
    case View.StringTake(_, _)         => Some(STRING)
    case View.StringStartsWith(_, _)   => Some(BOOL)
    case View.StringEndsWith(_, _)     => Some(BOOL)
    case View.StringSubstring(_, _, _) => Some(STRING)
  }

  private def functionType(fdef: Function): Type = ARROW(fdef.args.map(_._2), fdef.outty)

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
      case ARROW(a, b)     => a.flatMap(fromType(seen)) ++ fromType(seen)(b)
      case _               => Seq()
    }

    def fromOp(op: Op): Seq[Type] = op match {
      case Op.VarNew(ty)         => Seq(ty)
      case Op.ArrayNew(ty)       => Seq(ty)
      case Op.StructGet(repr, _) => Seq(STRUCT(repr))
      case Op.Custom(_, ty)      => Seq(ty)
      case _                     => Seq()
    }

    def fromTerm(term: Term): Seq[Type] = term match {
      case V(_)                           => Seq()
      case Let(_, e1, e2, _)                 => fromTerm(e1) ++ fromTerm(e2)
      case Function(args, outty, body, _) => args.map(_._2) ++ (outty +: fromTerm(body))
      case E(op, children)                => fromOp(op) ++ children.flatMap(fromTerm)
    }

    prog.functions.flatMap { (_, fdef) =>
      (fdef.args.map(_._2) ++ (fdef.outty +: fromTerm(fdef.body))).flatMap(fromType(Set()))
    }.distinctBy(_.name)
  }

  // Every custom operation the program calls, with the types of its call site.
  // `Op.Custom` carries only the result type, so the arguments have to come out
  // of inference.
  private def customSignatures(env: Env)(term: Term): Seq[(String, Type, Seq[Type])] =
    term match {
      case V(_) => Seq()

      case Let(x, e1, e2, _) => customSignatures(env)(e1) ++
          customSignatures(env.setOrRemove(x, inferType(env)(e1)))(e2)

      case Function(args, _, body, _) => customSignatures(env ++ args)(body)

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

    private def emitNotes(env: Env)(notes: Seq[Note], side: Note.Side): Unit =
      renderNotes(notes, side, operand(env)).foreach(out.emitln)

    // CR cwong: merge this with `emitFunction`
    //
    // The contract goes on the declaration and not the definition. That is what
    // a caller sees, and ACSL takes one contract per function, so writing it in
    // both places is a duplicate rather than a repetition.
    private inline def emitFunctionHeader(topEnv: Env)(fname: Name, fdef: Function)
        : Unit = {
      val Function(args, outty, body, notes) = fdef
      renderContract(notes, operand(topEnv ++ args)).foreach(out.emitln)
      val argsS = renderArgs(args)
      out.emitln(s"${outty.render} ${fname.render(cfg.varPrefix)}($argsS);")
    }

    // No source-level cause at all, now that `Op.ArrayInit` is gone. What is
    // left is arity: `View.view`'s helpers answer `None` for a term with the
    // wrong number of children, having already logged which op and how.
    private inline def withView(t: Term)(k: View => Unit): Unit = View.view(t)
      .fold { out.invalidTerm(s"BUG: no `View` for a term the backend reached: $t") }(k)

    // A `lam` that got past `SnippetDriver`, which means a `Driver` built
    // against this backend directly. The line that wrote it is long gone by
    // here, so this is a backstop and says so rather than pretending to be the
    // diagnostic.
    private def lambdaBackstop(): Unit = out.unsupported(
      "`lam` has no C representation",
      "C has no closures, and this is the backstop for a driver that did not" +
        " go through `SnippetDriver`, which reports at the call with a location",
      "give the function a name with `fun` so it becomes a top-level function"
    )

    // The three things a reader needs: which construct, why C has no form for
    // it, and what to write instead. A message missing the third is a dead end,
    // and six hand-written strings drift.
    private def unsupported(construct: String, why: String, instead: String): Unit =
      out.invalidTerm(s"$construct: $why; $instead")

    private def invalidTerm(msg: String): Unit = {
      Log.error(msg)
      out.emit("/* ERROR: ")
      out.emit(msg.replace("*/", "* /"))
      out.emit(" */")
    }

    private def emitFunction(topEnv: Env)(fname: Name, fdef: Function): Unit = {
      val Function(args, outty, body, _) = fdef

      val env = topEnv ++ args
      val argsS = renderArgs(args)

      out.emitln(s"${outty.render} ${fname.render(cfg.varPrefix)}($argsS) {")
      out.indented {
        if outty == UNIT then out.emitStmt(env)(body)
        else out.emitInto(env, Sink.Return(outty))(body)
      }
      out.emitln("}")
      out.emitln("")
    }

    // `memcpy` wants bytes, so the element type comes off the destination. A
    // fat destination is copied into through the pointer it carries, which is
    // the same `.data` an index goes through.
    private def emitMemcpy(env: Env)(dst: Term, src: Term, len: Term): Unit =
      inferType(env)(dst) match {
        case Some(ARRAY(elem, _)) => {
          need(Header.String)
          out.emit("memcpy(")
          out.emitSubscriptable(env)(dst)
          out.emit(", ")
          out.emitSubscriptable(env)(src)
          out.emit(s", sizeof(${elem.render}) * ")
          out.emitExpr(env)(len)
          out.emitln(");")
        }

        case ty => {
          out.invalidTerm(s"C backend cannot copy into a $ty: $dst")
          out.emitln(";")
        }
      }

    private def emitStrHelper(env: Env)(name: String, args: Term*): Unit = {
      need(Header.ElmsLib)
      out.emit(s"$name(")
      args.zipWithIndex.foreach { (t, i) =>
        if i != 0 then out.emit(", ")
        out.emitExpr(env)(t)
      }
      out.emit(")")
    }

    // The thing `[i]` goes after. A bare pointer is subscripted directly and a
    // fat array through the pointer it carries.
    private def emitSubscriptable(env: Env)(t: Term): Unit = {
      if inferType(env)(t).exists(isFat) then {
        out.emitMaybeParenthesizedExpr(env)(t)
        out.emit(".data")
      } else out.emitExpr(env)(t)
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
          // Ranges used to reach this, and now have a type. What is left is a
          // malformed term, which `View.view` has already logged about, or an
          // `ARROW` from a lambda. Both are bugs rather than programs someone
          // wrote, and neither throws: the malformed term came from outside the
          // backend.
          out.invalidTerm(
            "BUG: no C type inferred for a let-bound term, so it is either" +
              s" malformed or a function value: $e"
          )
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
      case View.Lt(x, y)     => out.emitCompare(env)("<", x, y)
      case View.Gt(x, y)     => out.emitCompare(env)(">", x, y)
      case View.Le(x, y)     => out.emitCompare(env)("<=", x, y)
      case View.Ge(x, y)     => out.emitCompare(env)(">=", x, y)
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

      // `(int)c` on its own reads a negative number out of a `char` the target
      // chose to make signed, where Scala's `Char.toInt` is unsigned whatever
      // the target does. Same cast the orderings take, for the same reason.
      case View.CharToInt(t) => {
        out.emit("(int)(unsigned char)")
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

      case View.ArrayNew(ty, t) => ty match {
        // Reads like a policy and is really a gap. `renderDeclarator` knows how
        // to wrap a name in `int xs[16]`, and an allocation has no name to wrap
        // yet, so nothing here can build `int (*)[16]` or the `sizeof` to match.
        case ARRAY(_, Some(_)) => out.unsupported(
            s"cannot allocate an array whose elements are $ty",
            "that needs the declarator form `int (*)[16]`, which `renderType`" +
              " has no name to wrap and so cannot build",
            "allocate an array of pointers, or add the declarator path"
          )

        // A fat array allocates through its own constructor, which is where
        // the length it carries gets set. `elms_lib.h` pulls in `stdlib.h`
        // itself, so only the bare-pointer branch asks for it here.
        case _ if isFat(ARRAY(ty)) => {
          need(Header.ElmsLib)
          out.emit(s"${ARRAY(ty).render}_new(")
          out.emitExpr(env)(t)
          out.emit(")")
        }

        case _ => {
          need(Header.StdLib)
          out.emit(s"(${ARRAY(ty).render})malloc(sizeof(${ty.render}) * ")
          out.emitExpr(env)(t)
          out.emit(")")
        }
      }

      case View.ArrayGet(arr, i) => {
        out.emitSubscriptable(env)(arr)
        out.emit("[")
        out.emitExpr(env)(i)
        out.emit("]")
      }

      case View.ArraySet(_, _, _) | View.ArrayCopy(_, _, _) => {
        out.emit("({")
        out.emitStmt(env)(term)
        out.emit("})")
      }

      case View.ArrayLength(arr) => inferType(env)(arr) match {
        case Some(ARRAY(_, Some(n))) => out.emit(n.toString)

        case Some(ty) if isFat(ty) => {
          out.emitMaybeParenthesizedExpr(env)(arr)
          out.emit(".len")
        }

        case Some(ARRAY(_, None)) if !opts.fatArrays => out.invalidTerm(
            "a dynamic array only knows its length when `fatArrays` is on, and" +
              " it is off: enable it, or use a `FixedArray`"
          )

        case Some(ARRAY(elem, None)) => out.invalidTerm(
            s"C backend has no name for an array of $elem, so it cannot carry" +
              s" a length: $arr"
          )

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

      case View.RangeStart(t) => {
        out.emitMaybeParenthesizedExpr(env)(t)
        out.emit(".start")
      }

      case View.RangeEnd(t) => {
        out.emitMaybeParenthesizedExpr(env)(t)
        out.emit(".end")
      }

      case View.Range(st, end) => out.emit(
          elmsRange(s"elms_range_mk(${operand(env)(st)}, ${operand(env)(end)})")
        )

      case View.Let(x, _ty, e1, e2, notes) => out.emitLetExpr(env)(x, e1, e2, notes)

      // Unreachable, and a comment in the residue for an unreachable case
      // means the file still compiles and the bug ships. A loop is `UNIT` per
      // `inferType`, `emitAssign` routes a `Some(UNIT)` binding to `emitStmt`,
      // and ANF binds a loop to a name before anything can use it, so an
      // operand position only ever sees the `V`. Getting here means `inferType`
      // stopped saying `UNIT` or the IR stopped being in ANF.
      case View.RangeForEach(_, _, _, _) => throw loopInExpr("RangeForEach", term)
      case View.While(_, _)              => throw loopInExpr("While", term)

      case View.Function(_, _, _, _) => out.lambdaBackstop()

      case View.Comment(parts, meta, args) =>
        renderInterpolated(parts, args.map(operand(env)), meta).foreach(out.emitln)

      case View.Print(t)   => out.emitPrintf(env)(t, "")
      case View.Println(t) => out.emitPrintf(env)(t, "\\n")

      // `strlen` answers in `size_t`, and `inferType` says this is an `INT`.
      // The cast is not cosmetic: unsigned, the value changes what a
      // comparison against a negative number means.
      case View.StringLength(t) => {
        need(Header.String)
        out.emit("(int)strlen(")
        out.emitExpr(env)(t)
        out.emit(")")
      }

      // Inline because there is nothing to wrap, and asking for a header here
      // would pull `string.h` into every program that reads a character.
      case View.StringCharAt(t, i) => {
        out.emitExpr(env)(t)
        out.emit("[")
        out.emitExpr(env)(i)
        out.emit("]")
      }

      // The rest go through `elms_lib.h`. Inline, `endsWith` alone needs four
      // `strlen` calls across two operands, the allocating ones would need a
      // GNU statement-expression, and the out-of-range clamping has nowhere to
      // live in an expression.
      case View.StringDrop(t, n)  => out.emitStrHelper(env)("elms_str_drop", t, n)
      case View.StringTake(t, n)  => out.emitStrHelper(env)("elms_str_take", t, n)
      case View.StringStartsWith(t, p) => out
          .emitStrHelper(env)("elms_str_startswith", t, p)
      case View.StringEndsWith(t, p) => out
          .emitStrHelper(env)("elms_str_endswith", t, p)
      case View.StringSubstring(t, a, b) => out
          .emitStrHelper(env)("elms_str_substring", t, a, b)
    }

    // CR-someday cwong: There is a decent amount of duplication when emitting
    // the same term in statement or expr position.

    private def emitStmt(env: Env)(term: Term): Unit = out.withView(term) {
      case View.Let(x, _ty, e1, e2, notes) => {
        out.emitNotes(env)(notes, Note.Side.Before)
        val ty = emitAssign(env)(x, e1)
        out.emitNotes(env)(notes, Note.Side.After)
        out.emitStmt(env.setOrRemove(x, ty))(e2)
      }

      case View.Comment(parts, meta, args) =>
        renderInterpolated(parts, args.map(operand(env)), meta).foreach(out.emitln)

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
        out.emitSubscriptable(env)(arr)
        out.emit("[")
        out.emitExpr(env)(i)
        out.emit("] = ")
        out.emitExpr(env)(x)
        out.emitln(";")
      }

      case View.ArrayCopy(dst, src, len) => out.emitMemcpy(env)(dst, src, len)

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
          out.unsupported(
            s"cannot assign to the fixed-length member `$field` as a whole",
            "C has no assignment operator for an array",
            "write through it with `.set(i, x)`"
          )
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
        out.lambdaBackstop()
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
        case View.Let(x, _ty, e1, e2, notes) => {
          out.emitNotes(env)(notes, Note.Side.Before)
          // `setOrRemove` and not `getOrElse(UNIT)`: defaulting a failed
          // inference to `UNIT` put the name in the env as a unit, so every
          // later use emitted `/* unit */` and an `int` function ended with
          // `return /* unit */;` a long way from the reported error. Dropping
          // the name emits the name, which is at least an undeclared
          // identifier on the right line.
          val ty = emitAssign(env)(x, e1)
          out.emitNotes(env)(notes, Note.Side.After)
          out.emitInto(env.setOrRemove(x, ty), sink)(e2)
        }

        case View.Comment(parts, meta, args) => {
          renderInterpolated(parts, args.map(operand(env)), meta).foreach(out.emitln)
          out.emitFallback(sink)
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

        // Unreachable for the same reason as the expression-position pair.
        case View.RangeForEach(_, _, _, _) => throw loopInExpr("RangeForEach", term)
        case View.While(_, _)              => throw loopInExpr("While", term)

        case View.Function(_, _, _, _) => {
          out.lambdaBackstop()
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

    private def emitLetExpr(
        env: Env
    )(x: Name, e1: Term, e2: Term, notes: Seq[Note]): Unit = {
      out.emitln("({")
      out.indented {
        out.emitNotes(env)(notes, Note.Side.Before)
        val ty = emitAssign(env)(x, e1)
        out.emitNotes(env)(notes, Note.Side.After)
        out.emitExprResult(env.setOrRemove(x, ty))(e2)
      }
      out.emit("})")
    }

    private def emitExprResult(env: Env)(term: Term): Unit = out.withView(term) {
      case View.Let(x, _ty, e1, e2, notes) => {
        out.emitNotes(env)(notes, Note.Side.Before)
        val ty = emitAssign(env)(x, e1)
        out.emitNotes(env)(notes, Note.Side.After)
        out.emitExprResult(env.setOrRemove(x, ty))(e2)
      }

      case View.Comment(parts, meta, args) => {
        renderInterpolated(parts, args.map(operand(env)), meta).foreach(out.emitln)
        out.emitln("/* unit */;")
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
        out.emitSubscriptable(env)(arr)
        out.emit("[")
        out.emitExpr(env)(i)
        out.emit("] = ")
        out.emitExpr(env)(x)
        out.emitln(";")
      }

      case View.ArrayCopy(dst, src, len) => out.emitMemcpy(env)(dst, src, len)

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
    // Nothing is lost by dropping them: see `emitPrintf`'s `UNIT` case.
    // `printf` needs the conversion that matches its argument, and `%s` was only
    // ever right for strings.
    private def emitPrintf(env: Env)(t: Term, terminator: String): Unit = {
      need(Header.StdIO)

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

        // The argument is dropped and nothing is lost with it. ANF binds a
        // unit-producing term to a name before the print, so whatever computed
        // it already ran as a statement and what got dropped is a `V` that
        // computes nothing.
        case Some(UNIT) => out.emit(s"""printf("()$terminator")""")

        // No right answer rather than a missing one. Scala's `println` on an
        // array prints an identity hash, `%p` prints an address, and `[1, 2, 3]`
        // is what the reader wanted and matches neither. Guessing makes the two
        // backends disagree about what a program prints, which is the one thing
        // their being comparable is for.
        case Some(ty) => out.unsupported(
            s"cannot print a value of type $ty",
            "C has no `printf` conversion for it, and every candidate" +
              " disagrees with what the Scala backend prints",
            "print the elements one at a time"
          )

        case None => out
            .invalidTerm(s"BUG: no type inferred for the argument of a print: $t")
      }
    }

    private def emitArgTerms(env: Env)(args: Seq[Term]): Unit = {
      // Dropped for the reason `emitPrintf` gives: ANF already ran whatever
      // produced the unit, so the argument left here computes nothing.
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

    // An ordering on `char` goes through `unsigned char`, because whether plain
    // `char` is signed is the target's choice: `'\xe9' < 'a'` is true on x86 and
    // false on ARM. Scala's `Char` is unsigned, so the cast is also what makes
    // the two backends agree on the same program.
    //
    // `Equals` wants none of this. Both operands convert the same way whichever
    // signedness the target picked, so the bits that compare equal are the same
    // bits either way.
    private def emitCompare(env: Env)(sym: String, x: Term, y: Term): Unit =
      if Seq(x, y).exists(t => inferType(env)(t).exists(_ == CHAR)) then {
        out.emit("(unsigned char)")
        out.emitMaybeParenthesizedExpr(env)(x)
        out.emit(s" $sym (unsigned char)")
        out.emitMaybeParenthesizedExpr(env)(y)
      } else out.emitBinop(env)(sym, x, y)

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
