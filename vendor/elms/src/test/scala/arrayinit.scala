package elms.test

import scala.language.implicitConversions

import org.scalatest.funsuite.AnyFunSuite

import elms.prelude.{_, given}
import elms.helpers.{SimpleSnippetDriver, OptimizingSnippetDriver, DslOps}
import elms.core.StructManifest
import elms.core.poly.eval.Interp
import elms.codegen.CCodegen

// Written against the polymorphic `DslOps`, so the same source runs in the
// interpreter and in both staged backends. `initFrom` is one of the few
// operations with an interpreter implementation to disagree with.
@virtualize
trait Pick extends elms.helpers.poly.DslOps {
  def run(i: Rep[Int]): Rep[Int] = initFrom(Seq(3, 1, 4, 1, 5)).get(i)
}

// `Op.ArrayInit` was an opcode with no `View`, no backend and no way to build
// one but `unsafeReflect`, and `initFrom` was `???` in every staged backend.
// It is gone: `initFrom` is now a static template, an allocation and one
// `ArrayCopy`, all of which every backend already emitted.
@virtualize
class ArrayInitTests extends SnapshotFunSuite {
  val under = "cinit/"

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

  case class Point(x: Int, y: Int) derives StructManifest

  test("initFrom emits a template and a copy") {
    object Snippet extends CDriver[Int, Int] with Pick {
      def snippet(x: Rep[Int]): Rep[Int] = run(x)
    }
    val code = Snippet.code
    check("init-from", code)
    assert(!code.contains("ERROR"))
    assert(code.contains("static const int"))
    assert(code.contains("memcpy("))
  }

  // `arrayCopy` is a public operation now rather than an implementation detail
  // of `initFrom`, so it gets a test that does not go through one.
  test("arrayCopy on its own") {
    object Snippet extends CDriver[Int, Int] {
      def snippet(x: Rep[Int]): Rep[Int] = {
        val src = newArray[Int](unit(4))
        src.set(unit(0), x)
        val dst = newArray[Int](unit(4))
        arrayCopy(dst, src, unit(4))
        dst.get(unit(0))
      }
    }
    val code = Snippet.code
    check("array-copy", code)
    assert(!code.contains("ERROR"))
    assert(code.contains("memcpy("))
  }

  // The deleted `structsIn` line was the only route by which a struct
  // reachable only as an `initFrom` element type got declared. `Op.ArrayNew`
  // carries it now, and the two lines looked interchangeable without being so:
  // one read `ARRAY(ai.elemTy)` and the other reads `ty`.
  test("a struct element type is still declared") {
    object Snippet extends CDriver[Int, Int] {
      def snippet(x: Rep[Int]): Rep[Int] = {
        val src = newArray[Point](unit(2))
        val dst = newArray[Point](unit(2))
        arrayCopy(dst, src, unit(2))
        x
      }
    }
    val code = Snippet.code
    check("init-struct-elem", code)
    assert(code.contains("struct Point {"))
  }
}

@virtualize
class ArrayInitScalaTests extends SnapshotFunSuite {
  val under = "init/"

  test("initFrom in the Scala backend") {
    object Snippet extends SimpleSnippetDriver[Int, Int] with DslOps with Pick {
      def snippet(x: Rep[Int]): Rep[Int] = run(x)
    }
    val code = Snippet.code
    check("init-from", code)
    assert(code.contains("Array.copy("))
  }

  // Nothing per-element is a constant any more, so saturation has nothing to
  // fold and this should differ from the simple form only in numbering.
  test("initFrom under the optimizing driver") {
    object Snippet extends OptimizingSnippetDriver[Int, Int] with DslOps with Pick {
      def snippet(x: Rep[Int]): Rep[Int] = run(x)
    }
    val code = Snippet.code
    check("init-from-opt", code)
    assert(code.contains("Array.copy("))
  }
}

// What a snapshot cannot see: that the result is fresh, mutable and agrees
// with the interpreter.
@virtualize
class ArrayInitRuntimeTests extends AnyFunSuite {
  abstract class CDriver[A: Typable, B: Typable]
      extends SimpleSnippetDriver[A, B] with DslOps {
    override val codegen = CCodegen()
  }

  val inputs = Seq(0, 1, 2, 3, 4)

  test("the staged backends agree with the interpreter") {
    object Interpreted extends Interp with Pick
    object Staged extends DslDriver[Int, Int] with EvalScalaSnippet[Int, Int] with Pick {
      val prefix = "init-from"
      val name = "pick"
      def snippet(x: Rep[Int]): Rep[Int] = run(x)
    }

    val reference = Seq(3, 1, 4, 1, 5)
    assert(inputs.map(reference).distinct.length == 4)

    inputs.foreach { i =>
      assert(Interpreted.run(Interpreted.Rep(i)).v == reference(i), s"interp on $i")
      assert(Staged.eval(i) == reference(i), s"staged on $i")
    }
  }

  // The property that rules out handing back the `static const` template
  // directly. Two calls with the same elements have to be two arrays, and
  // writing through one must not be visible through the other.
  test("two initFrom calls do not share storage") {
    object Snippet extends CDriver[Int, Int] {
      def snippet(x: Rep[Int]): Rep[Int] = {
        val a = initFrom(Seq(3, 1, 4))
        val b = initFrom(Seq(3, 1, 4))
        a.set(unit(0), unit(99))
        b.get(unit(0)) * unit(1000) + a.get(unit(0))
      }
    }

    val main =
      """#include <stdio.h>
        |int snippet(int x0);
        |int main(void) { printf("%d\n", snippet(0)); return 0; }
        |""".stripMargin

    CRunner.run(Snippet.code, main) match {
      case None      => cancel("no C compiler on this machine")
      // `b` still reads its 3 and `a` reads the 99 written through it. Shared,
      // both would read 99 and this would be 99099.
      case Some(out) => assert(out.trim == "3099")
    }
  }

  // The template is read-only, so the copy is what makes the result writable.
  // Writing through the result and reading it back is the whole of that.
  test("the copied array is mutable") {
    object Snippet extends CDriver[Int, Int] {
      def snippet(x: Rep[Int]): Rep[Int] = {
        val a = initFrom(Seq(3, 1, 4, 1, 5))
        a.set(x, unit(7))
        a.get(x)
      }
    }

    val calls = inputs.map { i => s"""  printf("%d\\n", snippet($i));""" }.mkString("\n")
    val main =
      s"""#include <stdio.h>
         |int snippet(int x0);
         |int main(void) {
         |$calls
         |  return 0;
         |}
         |""".stripMargin

    CRunner.run(Snippet.code, main) match {
      case None      => cancel("no C compiler on this machine")
      case Some(out) => assert(out.linesIterator.toVector == inputs.map(_ => "7"))
    }
  }
}
