package elms.test

import scala.language.implicitConversions

import org.scalatest.funsuite.AnyFunSuite

import elms.prelude.{_, given}
import elms.helpers.{SimpleSnippetDriver, DslOps}
import elms.core.StructManifest
import elms.codegen.CCodegen

// `Typable[Range]` is what lets a range sit anywhere a DSL value can: a
// parameter, an array element, a struct member. Each of those is a position
// `InlineRanges` cannot rewrite, so each one lands on `elms_range`.
@virtualize
class RangeTypeTests extends SnapshotFunSuite {
  val under = "crange/"

  override def check(
      label: String,
      actual: String,
      ext: String = "c",
      accept: Boolean = false
  ) = super.check(label, actual, ext, accept)

  abstract class CDriver[A: Typable, B: Typable]
      extends SimpleSnippetDriver[A, B] with DslOps {
    override val codegen = CCodegen()
  }

  case class Span(r: Range, tag: Int) derives StructManifest

  // Passed by value, which is the whole reason `elms_range` is a struct and not
  // a pointer: the callee gets a copy and there is no lifetime to get wrong.
  test("a range is a parameter") {
    object Snippet extends CDriver[Range, Int] {
      def snippet(r: Rep[Range]): Rep[Int] = {
        val v = newVar(unit(0))
        for (i <- r) { v := v.get + i }
        v.get
      }
    }
    val code = Snippet.code
    check("param", code)
    assert(!code.contains("ERROR"))
    assert(code.contains("int snippet(elms_range x0);"))
  }

  // `elms_range *` and a `sizeof` that matches it. A fixed-length array of them
  // would need a declarator `renderType` cannot build, the same limit
  // `ArrayNew` already reports for any element type.
  test("a range is an array element") {
    object Snippet extends CDriver[Int, Int] {
      def snippet(x: Rep[Int]): Rep[Int] = {
        val arr = newArray[Range](x)
        arr.set(unit(0), 0.until(x))
        arr.get(unit(0)).end
      }
    }
    val code = Snippet.code
    check("array", code)
    assert(!code.contains("ERROR"))
    assert(code.contains("malloc(sizeof(elms_range)"))
  }

  // Inline storage, where a nested `STRUCT` member would be a pointer. Reading
  // one out copies it.
  test("a range is a struct member") {
    object Snippet extends CDriver[Span, Int] {
      def snippet(s: Rep[Span]): Rep[Int] =
        s.get("r").asInstanceOf[Rep[Range]].end + s.get("tag").asInstanceOf[Rep[Int]]
    }
    val code = Snippet.code
    check("member", code)
    assert(!code.contains("ERROR"))
    assert(code.contains("elms_range r;"))
  }
}

// The Scala side of the same given. `ScalaCodegen` emitted `???` for the
// parameter type before it learned `RANGE`, and everything under that line was
// already correct, so generating the code and running it is what tells the two
// apart: a snapshot would pin either one.
@virtualize
class RangeScalaTests extends AnyFunSuite {
  test("a generated Range parameter compiles and runs") {
    object Snippet extends DslDriver[Range, Int] with EvalScalaSnippet[Range, Int] {
      val prefix = "range-type"
      val name = "sumRange"

      def snippet(r: Rep[Range]): Rep[Int] = {
        val v = newVar(unit(0))
        for (i <- r) { v := v.get + i }
        v.get
      }
    }

    assert(Snippet.code.contains("def snippet(x0: Range): Int"))

    // Empty, backwards and non-empty, with three distinct answers between them,
    // so a snippet that always handed back the same number could not pass.
    val cases = Seq(0.until(0), 0.until(5), 3.until(3), 7.until(2), 1.until(101))
    assert(cases.map(_.sum).distinct.length == 3)

    cases.foreach { r => assert(Snippet.eval(r) == r.sum, s"disagreed on $r") }
  }
}
