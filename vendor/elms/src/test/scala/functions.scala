package elms.test

import scala.language.implicitConversions

import elms.prelude._
import elms.prelude.given
import elms.helpers.DslOps
import elms.runtime.LMSStagingException

// Tests to ensure that implicit resolution is set up correctly.
// These should all typecheck and compile.
trait RepFunTypecheckSuite extends DslOps {
  def void(f: Rep[() => Int]) = f()
  def unary(f: Rep[Int => Int]) = f(1)
  def binary(f: Rep[(Int, String) => Int]) = f(1, "")
  def trinary(f: Rep[(Int, String, Boolean) => Int]) = f(1, "", false)
}

// `DslDriver` runs the eqsat builder, so a test that wants the simple one has
// to say so.
abstract class SimpleEvalDriver[A: Typable, B: Typable]
    extends elms.helpers.SnippetDriver[A, B] with DslOps with EvalScalaSnippet[A, B] {
  override val builder = elms.pipeline.simple.Builder()
}

// Two `fun` calls in one body, which nothing else in the suite does: every
// other "function" in these tests is a plain Scala method the front end inlines
// at staging time, so nothing ever reached `fill` a second time.
//
// Both builders, because only one of them had the bug and the pair of them
// agreeing is the property worth keeping.
@virtualize
class NestedFunTests extends org.scalatest.funsuite.AnyFunSuite {
  val inputs = Seq(0, 1, 7, -3, 100)

  // Distinct answers throughout, so a snippet that lost one of its calls could
  // not pass by landing on the right number anyway.
  def check(
      eval: Int => Int,
      expected: Int => Int,
      what: String,
      over: Seq[Int] = inputs
  ): Unit = {
    assert(over.map(expected).distinct.length == over.length)
    over.foreach { n => assert(eval(n) == expected(n), s"$what disagreed on $n") }
  }

  def expected(n: Int): Int = n * 2 + (n + 1) * 3

  test("two functions, simple builder") {
    object Snippet extends SimpleEvalDriver[Int, Int] {
      val prefix = "nested-fun"
      val name = "twoSimple"

      def twice(n: Rep[Int]): Rep[Int] = n * unit(2)
      def thrice(n: Rep[Int]): Rep[Int] = n * unit(3)

      def snippet(x: Rep[Int]): Rep[Int] = fun(twice)(x) + fun(thrice)(x + unit(1))
    }
    check(Snippet.eval, expected, "simple")
  }

  test("two functions, eqsat builder") {
    object Snippet extends DslDriver[Int, Int] with EvalScalaSnippet[Int, Int] {
      val prefix = "nested-fun"
      val name = "twoEqsat"

      def twice(n: Rep[Int]): Rep[Int] = n * unit(2)
      def thrice(n: Rep[Int]): Rep[Int] = n * unit(3)

      def snippet(x: Rep[Int]): Rep[Int] = fun(twice)(x) + fun(thrice)(x + unit(1))
    }
    check(Snippet.eval, expected, "eqsat")
  }

  // `makeFun` keys its memo on the serialized closure, and two eta-expansions
  // of the same method are two lambda classes and two keys, so this reached
  // codegen as two copies of the same helper under two names. Verified against
  // lms-clean's own `ClosureCompare` under Scala 2.12, which behaves the same
  // way, so `DedupFunctions` compares what came out instead.
  def staged(code: String): Int = raw"def x\d+\(".r.findAllIn(code).length

  test("the same helper staged twice is emitted once, simple builder") {
    object Snippet extends SimpleEvalDriver[Int, Int] {
      val prefix = "nested-fun"
      val name = "dupeSimple"

      def twice(n: Rep[Int]): Rep[Int] = n * unit(2)

      def snippet(x: Rep[Int]): Rep[Int] = fun(twice)(x) + fun(twice)(x + unit(1))
    }
    assert(staged(Snippet.code) == 1)
    check(Snippet.eval, n => n * 2 + (n + 1) * 2, "dupe simple")
  }

  test("the same helper staged twice is emitted once, eqsat builder") {
    object Snippet extends DslDriver[Int, Int] with EvalScalaSnippet[Int, Int] {
      val prefix = "nested-fun"
      val name = "dupeEqsat"

      def twice(n: Rep[Int]): Rep[Int] = n * unit(2)

      def snippet(x: Rep[Int]): Rep[Int] = fun(twice)(x) + fun(twice)(x + unit(1))
    }
    assert(staged(Snippet.code) == 1)
    check(Snippet.eval, n => n * 2 + (n + 1) * 2, "dupe eqsat")
  }

  // The other half of the same property: merging must not reach two helpers
  // that only look alike.
  test("two different helpers stay two") {
    object Snippet extends SimpleEvalDriver[Int, Int] {
      val prefix = "nested-fun"
      val name = "distinctSimple"

      def twice(n: Rep[Int]): Rep[Int] = n * unit(2)
      def thrice(n: Rep[Int]): Rep[Int] = n * unit(3)

      def snippet(x: Rep[Int]): Rep[Int] = fun(twice)(x) + fun(thrice)(x + unit(1))
    }
    assert(staged(Snippet.code) == 2)
    check(Snippet.eval, expected, "distinct")
  }

  // What the memo in `makeFun` is actually for. Each mention of `fact`
  // re-evaluates the same `fun {...}`, so the re-entry finds the name already
  // registered and calls it instead of staging the body again forever.
  test("a recursive function calls itself") {
    object Snippet extends SimpleEvalDriver[Int, Int] {
      val prefix = "nested-fun"
      val name = "factorial"

      def fact: Rep[Int => Int] = fun { (n: Rep[Int]) =>
        if n === unit(0) then unit(1) else n * fact(n - unit(1))
      }

      def snippet(x: Rep[Int]): Rep[Int] = fact(x)
    }

    assert(staged(Snippet.code) == 1)
    // Its own inputs: `fact` counts down to zero, so a negative one never
    // terminates, and the shared set holds a 100 that would overflow.
    check(Snippet.eval, n => (1 to n).product, "factorial", Seq(0, 2, 5, 10))
  }

  // Two `fun` calls under one name used to reach codegen as two functions both
  // claiming it, which came out as one definition, a call resolving to neither
  // and a `BUG: no C type inferred` where the other call should have been. The
  // memo does not save it: two eta-expansions of `twice` are two lambda classes
  // and two keys, so nothing upstream notices they are the same method.
  test("two functions under one name is an error") {
    object Snippet extends SimpleEvalDriver[Int, Int] {
      val prefix = "nested-fun"
      val name = "collide"

      def twice(n: Rep[Int]): Rep[Int] = n * unit(2)

      def snippet(x: Rep[Int]): Rep[Int] =
        fun[Int, Int]("dbl")(twice)(x) + fun[Int, Int]("dbl")(twice)(x)
    }

    val e = intercept[LMSStagingException] { Snippet.code }
    assert(e.getMessage.contains("`dbl`"), e.getMessage)
    // The three things the message owes a reader: what happened, the rule, and
    // what to write instead.
    assert(e.getMessage.contains("has to be unique"), e.getMessage)
    assert(e.getMessage.contains("rename"), e.getMessage)
  }

  // The three ways one name legitimately comes back, none of which may trip the
  // check above. A recursion is the sharp one: every mention re-enters `fun`
  // under the same name, and rejecting the second would reject the feature.
  test("a name may come back when it is the same function") {
    object Rec extends SimpleEvalDriver[Int, Int] {
      val prefix = "nested-fun"
      val name = "recTwice"

      def fact: Rep[Int => Int] = fun[Int, Int]("fact") { (n: Rep[Int]) =>
        if n === unit(0) then unit(1) else n * fact(n - unit(1))
      }

      def snippet(x: Rep[Int]): Rep[Int] = fact(x) + fact(x)
    }
    check(Rec.eval, n => 2 * (1 to n).product, "named recursion", Seq(0, 2, 5))

    // A second `code` re-enters `fun("snippet")` with the same closure.
    object Twice extends SimpleEvalDriver[Int, Int] {
      val prefix = "nested-fun"
      val name = "codeTwice"

      def snippet(x: Rep[Int]): Rep[Int] = x * unit(2)
    }
    assert(Twice.code == Twice.code)

    // Unnamed `fun`s take a fresh name each, so two of them never meet.
    object Fresh extends SimpleEvalDriver[Int, Int] {
      val prefix = "nested-fun"
      val name = "freshTwice"

      def twice(n: Rep[Int]): Rep[Int] = n * unit(2)

      def snippet(x: Rep[Int]): Rep[Int] = fun(twice)(x) + fun(twice)(x + unit(1))
    }
    check(Fresh.eval, n => n * 2 + (n + 1) * 2, "fresh names")
  }

  // Three calls, so the block has to survive two more `fill`s after the first
  // statement went into it rather than just one.
  test("three functions, simple builder") {
    object Snippet extends SimpleEvalDriver[Int, Int] {
      val prefix = "nested-fun"
      val name = "threeSimple"

      def a(n: Rep[Int]): Rep[Int] = n * unit(2)
      def b(n: Rep[Int]): Rep[Int] = n * unit(3)
      def c(n: Rep[Int]): Rep[Int] = n * unit(5)

      def snippet(x: Rep[Int]): Rep[Int] =
        fun(a)(x) + fun(b)(x + unit(1)) + fun(c)(x + unit(2))
    }
    check(Snippet.eval, n => n * 2 + (n + 1) * 3 + (n + 2) * 5, "three")
  }
}
