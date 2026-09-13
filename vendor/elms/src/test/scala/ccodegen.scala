package elms.test

import scala.language.implicitConversions

import elms.prelude.{_, given}
import elms.helpers.SimpleSnippetDriver
import elms.helpers.DslOps
import elms.codegen.CCodegen

@virtualize
class CCodegenTests extends SnapshotFunSuite {
  val under = "c/"

  override def check(
      label: String,
      actual: String,
      ext: String = "c",
      accept: Boolean = false
  ) = super.check(label, actual, ext, accept)

  abstract class CSnippetDriver[A: Typable, B: Typable] extends SimpleSnippetDriver[A,B]
    with DslOps {
    override val codegen = CCodegen()
  }

  test("pow5") {
    object Snippet extends CSnippetDriver[Int, Int] {
      def pow(x: Rep[Int], n: Int): Rep[Int] = if n == 0 then 1 else x * pow(x, n - 1)
      def snippet(x: Rep[Int]): Rep[Int] = pow(x, 5)
    }
    check("pow5", Snippet.code)
  }

  test("simple if") {
    object Snippet extends CSnippetDriver[Boolean, Int] {
      def snippet(x: Rep[Boolean]): Rep[Int] = if x then 1 else 0
    }
    check("if-basic", Snippet.code)
  }

  test("if nested") {
    object Snippet extends CSnippetDriver[Boolean, Int] {
      def snippet(x: Rep[Boolean]): Rep[Int] = {
        if x then { if x then 1 else 2 } else { 0 }
      }
    }
    check("if-nested", Snippet.code)
  }

  test("equality guard") {
    object Snippet extends CSnippetDriver[Int, Int] {
      def snippet(x: Rep[Int]): Rep[Int] = { if (x === 1) 2 else x }
    }
    check("if-tutorial", Snippet.code)
  }

  test("pow-square") {
    object Snippet extends CSnippetDriver[Int, Int] {
      def square(x: Rep[Int]): Rep[Int] = x * x

      def power(b: Rep[Int], n: Int): Rep[Int] =
        if (n == 0) 1
        else if (n % 2 == 0) square(power(b, n / 2))
        else b * power(b, n - 1)

      def snippet(b: Rep[Int]): Rep[Int] = power(b, 7)
    }
    check("pow-square", Snippet.code)
  }

  test("function calls") {
    object Snippet extends CSnippetDriver[Int, Int] {
      def snippet(x: Rep[Int]) = {
        def compute(b: Rep[Boolean]): Rep[Int] = {
          // the if is deferred to the second stage
          if (b) 1 else x
        }
        compute(x === 1)
      }
    }
    check("func-tutorial", Snippet.code)
  }

  test("recursive functions") {
    object Snippet extends CSnippetDriver[Int, Int] {
      def fact: Rep[Int => Int] = fun { (x: Rep[Int]) =>
        if x === 0 then unit(1) else snippet(x - 1)
      }
      def snippet(x: Rep[Int]) = fact(x)
    }
    check("fact", Snippet.code)
  }

  test("while") {
    object Snippet extends CSnippetDriver[Int, Int] {
      def snippet(x: Rep[Int]): Rep[Int] = {
        while (x === 0) do Builtins.println(x)
        x
      }
    }
    //check("while", Snippet.code)
  }

  test("vars") {
    object Snippet extends CSnippetDriver[Int, Int] {
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
    //check("var", Snippet.code)
  }

  test("if effects") {
    object Snippet extends CSnippetDriver[Int, Int] {
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
    //check("if-guard-effects", Snippet.code)
  }

  test("start-1") {
    val snippet = new CSnippetDriver[Int,Int] {
      def snippet(x: Rep[Int]) = {

        def compute(b: Boolean): Rep[Int] = {
          // the if is executed in the first stage
          if (b) 1 else x
        }
        compute(true)+compute(1==1)

      }
    }
    check("1", snippet.code)
  }

  test("power") {
    val snippet = new CSnippetDriver[Int,Int] {
      def square(x: Rep[Int]): Rep[Int] = x*x

      def power(b: Rep[Int], n: Int): Rep[Int] =
        if (n == 0) 1
        else if (n % 2 == 0) square(power(b, n/2))
        else b * power(b, n-1)

      def snippet(b: Rep[Int]) =
        power(b, 7)

    }
    check("power", snippet.code)
  }

  test("short-circuit") {
    val snippet = new CSnippetDriver[Unit, Boolean] {
      def foo(s: String, out: Boolean): Rep[Boolean] = {
        Builtins.println(s)
        unit(out)
      }

      def snippet(_x: Rep[Unit]): Rep[Boolean] = {
        val nab = foo("a", false) && foo("b", true)
        val anb = foo("a", true) || foo("b", false)

        nab && anb
      }
    }
    check("short-circuit", snippet.code)
  }

  test("custom nodes") {
    val snippet = new CSnippetDriver[Int, String] {
      def foo(x: Rep[Int]): Rep[String] = {
        unsafeReflect(elms.core.Op.Custom("hello", elms.core.STRING), x, "world")
      }

      def snippet(x: Rep[Int]): Rep[String] = foo(x)
    }
    check("custom-op", snippet.code)
  }

  test("if inside a short-circuit region") {
    val snippet = new CSnippetDriver[Int, Boolean] {
      def snippet(x: Rep[Int]): Rep[Boolean] = {
        (x > 0) && {
          Builtins.println("checking")
          if x > 5 then x < 100 else x === 3
        }
      }
    }
    check("if-in-region", snippet.code)
  }

  test("nested short-circuit regions") {
    val snippet = new CSnippetDriver[Int, Boolean] {
      def snippet(x: Rep[Int]): Rep[Boolean] = {
        (x > 0) && {
          Builtins.println("p")
          (x > 1) && {
            Builtins.println("q")
            x > 2
          }
        }
      }
    }
    check("nested-regions", snippet.code)
  }

  test("unit parameter") {
    val snippet = new CSnippetDriver[Unit, Int] {
      def snippet(x: Rep[Unit]): Rep[Int] = { Builtins.println("hi"); 1 }
    }
    check("unit-param", snippet.code)
  }

  test("unit parameter returned") {
    val snippet = new CSnippetDriver[Unit, Unit] {
      def snippet(x: Rep[Unit]): Rep[Unit] = x
    }
    check("unit-param-returned", snippet.code)
  }

  test("unit argument at a call site") {
    val snippet = new CSnippetDriver[Int, Int] {
      def noop: Rep[Unit => Int] = fun { (u: Rep[Unit]) => unit(7) }
      def snippet(x: Rep[Int]): Rep[Int] = noop(unit(())) + x
    }
    check("unit-arg", snippet.code)
  }

  test("printing each type") {
    val snippet = new CSnippetDriver[Int, Int] {
      def snippet(x: Rep[Int]): Rep[Int] = {
        Builtins.println("s")
        Builtins.println(x)
        Builtins.println(x > 0)
        Builtins.print(unit('c'))
        x
      }
    }
    check("print-types", snippet.code)
  }

  test("custom node with no arguments") {
    val snippet = new CSnippetDriver[Int, Int] {
      def now: Rep[Int] = unsafeReflect(elms.core.Op.Custom("now", elms.core.INT))
      def snippet(x: Rep[Int]): Rep[Int] = now + x
    }
    check("custom-op-nullary", snippet.code)
  }

  test("static data") {
    val snippet = new CSnippetDriver[Int, Int] {
      def snippet(x: Rep[Int]): Rep[Int] =
        staticData(Array(3, 1, 4)).get(x) + staticData(7)
    }
    check("static-data", snippet.code)
  }

  // `ArrayInit` has no implementation yet. What this pins is that reaching it
  // degrades into a reported error rather than throwing out of the pipeline.
  test("an unimplemented op is reported, not thrown") {
    val snippet = new CSnippetDriver[Int, Int] {
      def snippet(x: Rep[Int]): Rep[Int] = {
        val arr: Rep[Array[Int]] = unsafeReflect(elms.core.Op.ArrayInit(Seq(1, 2, 3)))
        arr.get(x)
      }
    }
    // No snapshot: the output is deliberately not valid C, and pinning it would
    // be a trap for anyone who later compiles every check file.
    assert(snippet.code.contains("ERROR") && snippet.code.contains("ArrayInit"))
  }

}
