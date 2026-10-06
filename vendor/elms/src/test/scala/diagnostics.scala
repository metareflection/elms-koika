package elms.test

import scala.language.implicitConversions

import org.scalatest.funsuite.AnyFunSuite

import elms.prelude.{_, given}
import elms.helpers.{SimpleSnippetDriver, DslOps}
import elms.core.{Name, Op, Typable as CoreTypable, INT, StructManifest}
import elms.core.tree as ast
import elms.codegen.CCodegen
import elms.runtime.{LMSRuntimeException, LMSUnsupportedException}

// Three constructs stay errors, and the split is whether someone could have
// written the thing. If yes, report into the residue and carry on, so the file
// still shows everything that did work. If no, throw, because a comment in the
// residue for a backend bug means the file compiles and the bug ships.
//
// Asserting on message text is usually a trap. Here the text is the deliverable:
// a message that says what failed without saying what to write instead is a
// dead end.
@virtualize
class DiagnosticsTests extends AnyFunSuite {
  abstract class CDriver[A: Typable, B: Typable]
      extends SimpleSnippetDriver[A, B] with DslOps {
    override val codegen = CCodegen()
  }

  case class Buffer(xs: FixedArray[16, Int], n: Int) derives StructManifest

  private def errors(code: String): Vector[String] =
    code.linesIterator.filter(_.contains("ERROR")).toVector

  test("assigning a whole fixed-length member says to write through it") {
    object Snippet extends CDriver[Buffer, Unit] {
      def snippet(b: Rep[Buffer]): Rep[Unit] = b.set("xs", newArray[Int](unit(16)))
    }
    val es = errors(Snippet.code)
    assert(es.length == 1)
    assert(es.head.contains("C has no assignment operator for an array"))
    assert(es.head.contains(".set(i, x)"))
  }

  // "cannot allocate fixed-length arrays" read like a policy. It is a missing
  // declarator path, and someone who knows that can close it in an afternoon.
  test("allocating an array of fixed-length arrays says what is missing") {
    object Snippet extends CDriver[Int, Int] {
      def snippet(x: Rep[Int]): Rep[Int] = {
        val a = newArray[FixedArray[16, Int]](x)
        x
      }
    }
    val es = errors(Snippet.code)
    assert(es.nonEmpty)
    assert(es.head.contains("int (*)[16]"))
    assert(es.head.contains("declarator"))
  }

  test("printing an array says to print the elements") {
    object Snippet extends CDriver[Int, Int] {
      def snippet(x: Rep[Int]): Rep[Int] = {
        Builtins.println(newArray[Int](x))
        x
      }
    }
    val es = errors(Snippet.code)
    assert(es.length == 1)
    assert(es.head.contains("print the elements"))
    // It used to print `Some(ARRAY(INT,None))`, because the match was on the
    // `Option` rather than on the type inside it.
    assert(!es.head.contains("Some("))
  }

  // The assertion that catches a future change making the four hard failures
  // reachable, which is exactly when throwing becomes the wrong choice. A loop
  // is UNIT-typed and ANF binds it to a name, so an operand position only ever
  // sees the name.
  test("a loop in an operand position is a name, not a loop") {
    object Snippet extends CDriver[Int, Boolean] {
      def snippet(x: Rep[Int]): Rep[Boolean] = {
        val v = newVar(unit(0))
        val w = __whileDo(v.get < x, v := v.get + unit(1))
        w === w
      }
    }
    val code = Snippet.code
    assert(code.contains("while ("))
    assert(code.contains("/* unit */"))
    assert(errors(code).isEmpty)
  }

  // Malformed, so `View.view` answers `None` and inference follows. It came
  // from outside the backend and `View.view` has already logged, so this
  // reports rather than throwing.
  test("a malformed term reports a BUG and does not throw") {
    object Snippet extends CDriver[Int, Int] {
      def snippet(x: Rep[Int]): Rep[Int] = {
        val bad: Rep[Int] = unsafeReflect(Op.Plus, x)
        bad + unit(1)
      }
    }
    val code = Snippet.code
    assert(errors(code).exists(_.contains("BUG")))
  }

  // The failed binding used to enter the env as `UNIT`, so every later use
  // emitted `/* unit */` and an `int` function ended with `return /* unit */;`
  // a long way from the reported error. Invisible in every snapshot, because
  // no snapshot has a malformed term in it.
  test("a failed inference does not turn later uses into unit") {
    object Snippet extends CDriver[Int, Int] {
      def snippet(x: Rep[Int]): Rep[Int] = {
        val bad: Rep[Int] = unsafeReflect(Op.Plus, x)
        bad
      }
    }
    assert(!Snippet.code.contains("return /* unit */"))
  }
}

// C has no closures. The refusal happens where `lam` was written, because that
// is the last point at which the line number exists: by the time a `Function`
// term reaches the backend all that is left is `Fresh(2)`.
@virtualize
class LambdaTests extends AnyFunSuite {
  abstract class CDriver[A: Typable, B: Typable]
      extends SimpleSnippetDriver[A, B] with DslOps {
    override val codegen = CCodegen()
  }

  test("lam in a C driver throws, with a location and a way out") {
    object Snippet extends CDriver[Int, Int] {
      def snippet(x: Rep[Int]): Rep[Int] = lam[Int, Int](y => y + unit(1))(x)
    }

    val thrown = intercept[LMSUnsupportedException] { Snippet.code }
    assert(thrown.msg.contains("diagnostics.scala"))
    assert(thrown.msg.contains("fun"))
  }

  test("a named fun in a C driver is unaffected") {
    object Snippet extends CDriver[Int, Int] {
      def twice(n: Rep[Int]): Rep[Int] = n * unit(2)
      def snippet(x: Rep[Int]): Rep[Int] = fun(twice)(x)
    }
    val code = Snippet.code
    assert(!code.contains("ERROR"))
    assert(code.contains("int x1(int x2)"))
  }

  // `SnippetDriver` covers every driver in the repo, and `Driver` is public, so
  // the backstop in the backend is reachable by building the term directly.
  // Without this it is untested code with a comment claiming it is reachable.
  test("a lambda that reaches the backend reports rather than throwing") {
    val body = ast.Let(
      Name.from("y"),
      ast.E(Op.Plus, Seq(ast.V(Name.from("a")), ast.V(Name.from("a")))),
      ast.V(Name.from("y")),
      Seq()
    )
    val lambda = ast.Function(Seq((Name.from("a"), INT)), INT, body, Seq())

    val main = ast.Function(
      Seq((Name.from("x"), INT)),
      INT,
      ast.Let(Name.from("f"), lambda, ast.V(Name.from("x")), Seq()),
      Seq()
    )

    // Typed as `Backend`, because `CCodegen` has a private `render` extension
    // on primitives that the bare call is ambiguous against.
    val gen: elms.codegen.Backend = CCodegen()
    val code = gen.render(ast.Program(Seq(Name.from("snippet") -> main), Seq()))

    val es = code.linesIterator.filter(_.contains("ERROR")).toVector
    assert(es.nonEmpty)
    assert(es.forall(_.contains("fun")))
    // The term dump is gone: it was 300 characters of `Fresh(2)` for a
    // four-line snippet.
    assert(!code.contains("Function(Fresh"))
  }
}
