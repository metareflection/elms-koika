package elms.test

import scala.language.implicitConversions

import elms.prelude.{_, given}
import elms.helpers.{SimpleSnippetDriver, DslOps}
import elms.codegen.CCodegen

// Bodies with a distinct coefficient per parameter, so a version that dropped
// one or swapped two could not land on the right answer anyway.
@virtualize
trait Arith extends DslOps {
  def weigh2(a: Rep[Int], b: Rep[Int]): Rep[Int] = a + b * unit(10)
  def weigh3(a: Rep[Int], b: Rep[Int], c: Rep[Int]): Rep[Int] = a + b * unit(10) +
    c * unit(100)
}

object Arith {
  def weigh2(a: Int, b: Int): Int = a + b * 10
  def weigh3(a: Int, b: Int, c: Int): Int = a + b * 10 + c * 100
}

@virtualize
class FunArityTests extends SnapshotFunSuite {
  val under = "cfun/"

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

  test("a two-argument function is one C function with two parameters") {
    object Snippet extends CDriver[Int, Int] with Arith {
      def snippet(x: Rep[Int]): Rep[Int] =
        fun2[Int, Int, Int]("weigh")(weigh2)(x, unit(7))
    }
    val code = Snippet.code
    check("weigh2", code)
    assert(code.contains("int weigh(int x1, int x2)"))
  }

  test("a three-argument function is one C function with three parameters") {
    object Snippet extends CDriver[Int, Int] with Arith {
      def snippet(x: Rep[Int]): Rep[Int] =
        fun3[Int, Int, Int, Int]("weigh")(weigh3)(x, unit(7), unit(2))
    }
    check("weigh3", Snippet.code)
  }

  // The parameter list and the call have to agree about dropping it, and only
  // one of the two sites did the dropping before there was a list to drop from.
  test("a unit parameter leaves both the signature and the call") {
    object Snippet extends CDriver[Int, Int] {
      def snippet(x: Rep[Int]): Rep[Int] = fun2[Int, Unit, Int]("keep") { (a, _) =>
        a + unit(1)
      }(x, unit(()))
    }
    val code = Snippet.code
    check("unit-arg2", code)
    assert(code.contains("int keep(int x1)"))
    assert(!code.contains("keep(x0, "))
  }

  // What the memo is for, at two arguments: each mention of `gauss` re-evaluates
  // the same `fun2 {...}`, so the re-entry has to find the name already
  // registered rather than stage the body again forever. A `fun2` with a
  // funTable of its own would not come back from this test.
  test("a recursive two-argument function calls itself") {
    object Snippet extends CDriver[Int, Int] {
      def gauss: Rep[(Int, Int) => Int] = fun2[Int, Int, Int]("gauss") {
        (n: Rep[Int], acc: Rep[Int]) =>
          if n <= unit(0) then acc else gauss(n - unit(1), acc + n)
      }

      def snippet(x: Rep[Int]): Rep[Int] = gauss(x, unit(0))
    }
    val code = Snippet.code
    check("gauss", code)
    assert("int gauss\\(".r.findAllIn(code).size == 2, code)
  }

  test("the emitted Scala agrees with the plain functions") {
    object Two extends DslDriver[Int, Int] with Arith with EvalScalaSnippet[Int, Int] {
      val prefix = "fun2-test"
      val name = "weighTwo"
      def snippet(x: Rep[Int]): Rep[Int] =
        fun2[Int, Int, Int]("weigh")(weigh2)(x, unit(7))
    }
    object Three
        extends DslDriver[Int, Int] with Arith with EvalScalaSnippet[Int, Int] {
      val prefix = "fun3-test"
      val name = "weighThree"
      def snippet(x: Rep[Int]): Rep[Int] =
        fun3[Int, Int, Int, Int]("weigh")(weigh3)(x, unit(7), unit(2))
    }

    FunArityTests.inputs.foreach { n =>
      assertResult(Arith.weigh2(n, 7), s"two on $n") { Two.eval(n) }
      assertResult(Arith.weigh3(n, 7, 2), s"three on $n") { Three.eval(n) }
    }
  }
}

object FunArityTests {
  val inputs: Seq[Int] = Seq(0, 1, -4, 9, 123)
}

// A C function of two parameters is the thing that did not exist, so what
// settles it is a C caller passing two and getting the right number back.
@virtualize
class FunArityRuntimeTests extends org.scalatest.funsuite.AnyFunSuite {
  abstract class CDriver[A: Typable, B: Typable]
      extends SimpleSnippetDriver[A, B] with DslOps {
    override val codegen = CCodegen()
  }

  private def agrees(code: String, ns: Seq[Int], expected: Int => Int): Unit = {
    val calls = ns.map { n => s"""  printf("%d\\n", snippet($n));""" }.mkString("\n")
    val main = s"""#include <stdio.h>
         |int snippet(int x0);
         |int main(void) {
         |$calls
         |  return 0;
         |}
         |""".stripMargin

    CRunner.run(code, main) match {
      case None      => cancel("no C compiler on this machine")
      case Some(out) =>
        assert(out.linesIterator.toVector == ns.map(expected).map(_.toString).toVector)
    }
  }

  test("a two-argument call computes what the plain function does") {
    object Snippet extends CDriver[Int, Int] with Arith {
      def snippet(x: Rep[Int]): Rep[Int] =
        fun2[Int, Int, Int]("weigh")(weigh2)(x, unit(7))
    }
    val ns = FunArityTests.inputs
    assert(ns.map(Arith.weigh2(_, 7)).distinct.length == ns.length)
    agrees(Snippet.code, ns, Arith.weigh2(_, 7))
  }

  test("a three-argument call computes what the plain function does") {
    object Snippet extends CDriver[Int, Int] with Arith {
      def snippet(x: Rep[Int]): Rep[Int] =
        fun3[Int, Int, Int, Int]("weigh")(weigh3)(x, unit(7), unit(2))
    }
    val ns = FunArityTests.inputs
    assert(ns.map(Arith.weigh3(_, 7, 2)).distinct.length == ns.length)
    agrees(Snippet.code, ns, Arith.weigh3(_, 7, 2))
  }

  test("a recursive two-argument function computes what its Scala twin does") {
    object Snippet extends CDriver[Int, Int] {
      def gauss: Rep[(Int, Int) => Int] = fun2[Int, Int, Int]("gauss") {
        (n: Rep[Int], acc: Rep[Int]) =>
          if n <= unit(0) then acc else gauss(n - unit(1), acc + n)
      }

      def snippet(x: Rep[Int]): Rep[Int] = gauss(x, unit(0))
    }
    // Its own inputs: `gauss` counts down to zero, so a negative one never
    // terminates and the shared set holds one.
    val ns = Seq(0, 1, 5, 12)
    assert(ns.map(n => (1 to n).sum).distinct.length == ns.length)
    agrees(Snippet.code, ns, n => (1 to n).sum)
  }

  // Order is the thing a symmetric body cannot check: `weigh` with its
  // arguments rotated is a different number for every input here.
  test("the arguments arrive in the order they were passed") {
    object Snippet extends CDriver[Int, Int] with Arith {
      def snippet(x: Rep[Int]): Rep[Int] =
        fun3[Int, Int, Int, Int]("weigh")(weigh3)(unit(1), unit(2), x)
    }
    val ns = FunArityTests.inputs
    agrees(Snippet.code, ns, n => Arith.weigh3(1, 2, n))
  }
}
