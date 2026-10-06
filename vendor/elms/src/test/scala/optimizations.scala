package elms.test

import scala.language.implicitConversions

import elms.prelude.{_, given}
import elms.helpers.OptimizingSnippetDriver
import elms.helpers.DslOps

@virtualize
class OptimizerTests extends SnapshotFunSuite {
  val under = "opts/"

  // These two tests are intended to ensure that scoped elaboration correctly
  // respects scopes. For example,
  //
  // if {
  //   val x = 1
  //   x == 2
  // } {
  //   // ...
  // }
  //
  // does not expose `x`.

  test("if scope") {
    object Snippet extends DslDriver[Int, Int] {
      def snippet(x: Rep[Int]): Rep[Int] = {
        val y = newVar(x)
        val result = newVar(0)
        if {
          y := y.get + 2
          y.get > 0
        } then {
          result := result.get + y.get
        }

        result.get
      }
    }
    check("if-scope", Snippet.code)
  }

  test("while scope") {
    object Snippet extends DslDriver[Int, Int] {
      def snippet(x: Rep[Int]): Rep[Int] = {
        val y = newVar(x)
        val result = newVar(0)
        while y.get > 0 do {
          result := result.get + y.get
          y := y.get - 1
        }

        result.get
      }
    }
    check("while-scope", Snippet.code)
  }

  // The `eqsat` pipeline hoists a loop's bounds above the loop, so a comment
  // written against the loop has two bindings to drift past. It cannot, because
  // it is carried by the loop's own binding rather than standing beside it.
  test("an invariant survives the elaboration hoisting past it") {
    object Snippet extends DslDriver[Int, Unit] {
      def snippet(x: Rep[Int]): Rep[Unit] = {
        attach"@ loop invariant 0 <= i <= $x;"
        for (i <- (0.until(x)): Rep[Range]) { Builtins.println(i) }
      }
    }

    val code = Snippet.code
    check("comment-loop", code)
    assertCommentAgainst(code, "//@ loop invariant", "for (")
  }

  test("naming a value in a comment binds nothing") {
    object Snippet extends DslDriver[Int, Int] {
      def snippet(x: Rep[Int]): Rep[Int] = {
        val y = x * 2
        attach"@ loop invariant 0 <= i <= $y;"
        for (i <- (0.until(y)): Rep[Range]) {
          attach"@ assert $i < $y;"
          Builtins.println(i)
        }
        y
      }
    }
    check("comment-args", Snippet.code)
  }

  // A `while` opens two regions, its guard and its body, so a note raised before
  // it has to survive both before the loop's own statement adopts it. The range
  // loop above only opens one.
  //
  // Nothing in the `eqsat` builder can break this today. Each `RegionBuilder`
  // owns its pending buffer, so the isolation is structural rather than a rule
  // somebody wrote. This is here to catch a refactor that gives them a shared
  // one, which is why it never fails.
  test("a note survives both of a while loop's regions") {
    object Snippet extends DslDriver[Int, Unit] {
      def snippet(x: Rep[Int]): Rep[Unit] = {
        val v = newVar(x)
        attach"@ loop invariant $x >= 0;"
        while v.get > 0 do { v := v.get - 1 }
      }
    }

    assertCommentAgainst(Snippet.code, "//@ loop invariant", "while")
  }

  // Ensure that boolean operators respect short-circuiting

  test("short-circuit") {
    val snippet = new DslDriver[Boolean, Boolean] {
      def foo(s: String, out: Boolean): Rep[Boolean] = {
        Builtins.println(s)
        unit(out)
      }

      def snippet(x: Rep[Boolean]): Rep[Boolean] = {
        val nab = foo("a", false) && foo("b", true)
        val anb = foo("a", true) || foo("b", false)

        (x || nab) || (x && anb)
      }
    }
    check("short-circuit", snippet.code)
  }
}
