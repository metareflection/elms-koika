package elms.test

import scala.language.implicitConversions

import elms.prelude.{_, given}
import elms.helpers.SimpleSnippetDriver
import elms.helpers.DslOps
import elms.codegen.CCodegen

// Two independent booleans out of one `Int`, so a one-argument snippet can drive
// both operands of every operator. The `!` is there to catch a rewrite turning
// `x ^ true` into one, and the whole thing is `a == b`, which is what makes the
// answer depend on the input rather than coming out true either way.
@virtualize
trait MixedBool extends DslOps {
  def mixedBool(x: Rep[Int]): Rep[Boolean] = {
    val a = x > 0
    val b = (x & 1) === 0
    (a & b) | (a ^ !b)
  }
}

object MixedBool {
  // The same expression in plain Scala, which is what a compiled snippet has to
  // agree with.
  def reference(x: Int): Boolean = {
    val a = x > 0
    val b = (x & 1) == 0
    (a & b) | (a ^ !b)
  }

  val inputs: Seq[Int] = Seq(0, 1, 2, 3, -1, -2, Int.MinValue, Int.MaxValue)
}

@virtualize
class BoolOpsTests extends SnapshotFunSuite {
  val under = "boolops/"

  // Unoptimized, so every operator has to survive to the snapshot rather than
  // being folded into the constants sitting next to it.
  test("every operator renders") {
    object Snippet extends SimpleSnippetDriver[Int, Boolean] with MixedBool {
      def snippet(x: Rep[Int]): Rep[Boolean] = mixedBool(x)
    }
    check("mixed", Snippet.code)
  }

  test("the emitted Scala agrees with Boolean's own operators") {
    object Snippet
        extends DslDriver[Int, Boolean]
        with MixedBool
        with EvalScalaSnippet[Int, Boolean] {
      val prefix = "boolops-test"
      val name = "boolops"
      def snippet(x: Rep[Int]): Rep[Boolean] = mixedBool(x)
    }

    MixedBool.inputs.foreach { x =>
      assertResult(MixedBool.reference(x), s"on $x") { Snippet.eval(x) }
    }

    // A boolean expression is easy to write so that it collapses to a constant,
    // and then agreeing with the reference proves nothing.
    assert(MixedBool.inputs.map(MixedBool.reference).distinct.length == 2)
  }

  // The whole reason these ops exist. `&&` compiles to an `if`, so the right
  // operand only runs when the left is true; `&` has to print both either way.
  test("no short-circuit") {
    object Snippet extends SimpleSnippetDriver[Unit, Boolean] with DslOps {
      def foo(s: String, out: Boolean): Rep[Boolean] = {
        Builtins.println(s)
        unit(out)
      }

      def snippet(_x: Rep[Unit]): Rep[Boolean] = {
        val ab = foo("a", false) & foo("b", true)
        val cd = foo("c", false) ^ foo("d", true)
        ab | cd
      }
    }
    check("no-short-circuit", Snippet.code)
  }

  test("identities collapse under saturation") {
    object Snippet extends DslDriver[Boolean, Boolean] {
      def snippet(b: Rep[Boolean]): Rep[Boolean] = ((b & b) | false) ^ false
    }
    check("identities", Snippet.code)
  }

  // `b ^ true` is `!b`, and the two `!`s that leaves have to cancel or the
  // rewrite makes the output worse than it found it.
  test("xor with true becomes a negation") {
    object Snippet extends DslDriver[Boolean, Boolean] {
      def snippet(b: Rep[Boolean]): Rep[Boolean] = (b ^ true) ^ true
    }
    check("xor-true", Snippet.code)
  }
}

@virtualize
class BoolOpsCTests extends SnapshotFunSuite {
  val under = "cboolops/"

  override def check(
      label: String,
      actual: String,
      ext: String = "c",
      accept: Boolean = false
  ) = super.check(label, actual, ext, accept)

  test("every operator renders") {
    object Snippet extends SimpleSnippetDriver[Int, Boolean] with MixedBool {
      override val codegen = CCodegen()
      def snippet(x: Rep[Int]): Rep[Boolean] = mixedBool(x)
    }
    check("mixed", Snippet.code)
  }
}
