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
    val code = Snippet.code
    check("pow5", code)
    // Nothing here is a `bool`, prints or allocates, so there is no include
    // block and no blank line where one would have been.
    assert(code.startsWith("int snippet(int x0);"))
  }

  // The guard is what tells the two forms apart. It reflects two bindings of its
  // own between the annotations, so the free-standing one lands above them and
  // the attached one below, carried by the `if` it was written against. Over a
  // snippet with nothing in between, either form would look identical.
  test("both statement forms in one function") {
    object Snippet extends CSnippetDriver[Int, Int] {
      def snippet(x: Rep[Int]): Rep[Int] = {
        val y = x + x
        comment"@ assert $y >= 0;"
        attach"@ assert $y != 1;"
        if (y === 1) then 1 else 0
      }
    }

    val code = Snippet.code
    check("comment", code)
    assertCommentAgainst(code, "//@ assert x1 >= 0;", "int x3 = 1;")
    // The declaration and not the `if`: a C `if` that produces a value opens by
    // declaring the variable it assigns into, so that line is the head of the
    // statement the note is attached to.
    assertCommentAgainst(code, "//@ assert x1 != 1;", "int x7;")
  }

  test("a contract sits above the declaration") {
    object Snippet extends CSnippetDriver[Int, Int] {
      def snippet(x: Rep[Int]): Rep[Int] = {
        contract"@ requires $x > 0;"
        contract"@ ensures \result > 0;"
        x + 1
      }
    }

    val code = Snippet.code
    check("contract", code)
    assertCommentAgainst(code, "//@ requires x0 > 0;", "//@ ensures")
    assertCommentAgainst(code, "//@ ensures", "int snippet(int x0);")
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

  // The motivating case. `foreach` reads its bounds back off the range it was
  // called on, so before `InlineRanges` this emitted three errors and no usable
  // loop. The `ERROR` assertion is the point of the test: a snapshot on its own
  // would happily pin the broken output.
  test("a foreach becomes a for loop") {
    object Snippet extends CSnippetDriver[Int, Unit] {
      def snippet(x: Rep[Int]): Rep[Unit] = {
        val arr = newArray[Int](x)
        for (i <- (0.until(x)): Rep[Range]) { arr.set(i, i * 2) }
      }
    }
    val code = Snippet.code
    check("range-foreach", code)
    assert(!code.contains("ERROR"))
  }

  test("a foreach over constant bounds") {
    object Snippet extends CSnippetDriver[Int, Int] {
      def snippet(x: Rep[Int]): Rep[Int] = {
        val acc = newVar(unit(0))
        for (i <- (0.until(unit(10))): Rep[Range]) { acc := acc.get + i }
        acc.get
      }
    }
    val code = Snippet.code
    check("range-foreach-const", code)
    assert(!code.contains("ERROR"))
  }

  // Two ranges are in scope at once inside the inner loop, and the inner one is
  // built from the outer loop variable. A pass that confused them would emit a
  // loop over the wrong bounds and still produce C that compiles.
  test("nested foreach loops keep their own bounds") {
    object Snippet extends CSnippetDriver[Int, Int] {
      def snippet(x: Rep[Int]): Rep[Int] = {
        val acc = newVar(unit(0))
        for (i <- (0.until(x)): Rep[Range]) {
          for (j <- (0.until(i)): Rep[Range]) { acc := acc.get + j }
        }
        acc.get
      }
    }
    val code = Snippet.code
    check("range-nested", code)
    assert(!code.contains("ERROR"))
  }

  // `__ifThenElse[T]` is unconstrained in `T`, which makes this the only way a
  // range outlives the `foreach` it was written for: nothing else in the DSL
  // has a `Typable[Range]` to summon. `InlineRanges` cannot see through the
  // `if`, so this is the shape `elms_range` exists for.
  test("a range bound by an if gets a struct") {
    object Snippet extends CSnippetDriver[Int, Int] {
      def snippet(x: Rep[Int]): Rep[Int] = {
        val r: Rep[Range] = if x === unit(0) then 0.until(x) else x.until(unit(10))
        val v = newVar(unit(0))
        for (i <- r) { v := v.get + i }
        v.get
      }
    }
    val code = Snippet.code
    check("range-first-class", code)
    assert(!code.contains("ERROR"))
    assert(code.contains("elms_range"))
    assert(code.contains("#include \"elms_lib.h\""))
  }

  // With the feature off, the file has to name no part of it: no `elms_range`,
  // no constructor, no header. Refusing the type while still emitting a call to
  // `elms_range_mk` would leave the option half-applied, and a file that
  // includes a header for a feature it was told not to use.
  test("firstClassRanges off leaves no trace of the struct") {
    val code = new TunedDriver[Int, Int](
      CCodegen(opts = CCodegen.Options(firstClassRanges = false))
    ) {
      def snippet(x: Rep[Int]): Rep[Int] = {
        val r: Rep[Range] = if x === unit(0) then 0.until(x) else x.until(unit(10))
        val v = newVar(unit(0))
        for (i <- r) { v := v.get + i }
        v.get
      }
    }.code

    assert(!code.contains("elms_range"))
    assert(!code.contains("elms_lib.h"))

    // Each refused position is a line that does not compile, so each one says
    // so and each names the option, rather than the first one saying it and
    // the rest pointing back at it.
    val refusals = code.linesIterator.filter(_.contains("ERROR")).toVector
    assert(refusals.nonEmpty)
    assert(refusals.forall(_.contains("`firstClassRanges` is off")))
  }

  // Tier 1's whole purpose is that an ordinary loop needs no runtime support.
  // That is invisible unless something asserts the header is absent.
  test("only a first-class range asks for elms_lib.h") {
    object Loop extends CSnippetDriver[Int, Int] {
      def snippet(x: Rep[Int]): Rep[Int] = {
        val acc = newVar(unit(0))
        for (i <- (0.until(x)): Rep[Range]) { acc := acc.get + i }
        acc.get
      }
    }

    assert(!Loop.code.contains("elms_lib.h"))
  }

  // The flag suppresses the include lines and changes nothing else. Asserting
  // that by diff is what stops it from quietly disabling the feature the
  // includes were there for.
  test("autoIncludes off drops the includes and nothing else") {
    def build(opts: CCodegen.Options): Vector[String] =
      new TunedDriver[Boolean, Unit](CCodegen(opts = opts)) {
        def snippet(x: Rep[Boolean]): Rep[Unit] = Builtins.println(x)
      }.code.linesIterator.toVector

    val full = build(CCodegen.Options())
    val bare = build(CCodegen.Options(autoIncludes = false))

    val (includes, rest) = full.span(_.startsWith("#include"))
    assert(includes == Vector("#include <stdbool.h>", "#include <stdio.h>"))
    assert(rest.head.isEmpty)
    assert(rest.tail == bare)
  }

  // One instance, two programs. The leak this rules out is invisible in every
  // snapshot, because each of those builds its own driver and its own backend.
  test("headers do not leak between programs") {
    val gen = CCodegen()

    val loud = new TunedDriver[Int, Unit](gen) {
      def snippet(x: Rep[Int]): Rep[Unit] = Builtins.println(x)
    }
    val quiet = new TunedDriver[Int, Int](gen) {
      def snippet(x: Rep[Int]): Rep[Int] = x + 1
    }

    assert(loud.code.contains("#include <stdio.h>"))
    assert(!quiet.code.contains("#include"))
  }

}
