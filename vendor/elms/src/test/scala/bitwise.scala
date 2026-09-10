package elms.test

import scala.language.implicitConversions

import elms.prelude.{_, given}
import elms.helpers.SimpleSnippetDriver
import elms.helpers.DslOps
import elms.codegen.CCodegen

// The expression every test in this file stages. It mixes all seven operators,
// and the `>>` sitting next to the `>>>` is what makes a negative input tell the
// two apart.
@virtualize
trait Mixed extends DslOps {
  def mixed(x: Rep[Int]): Rep[Int] =
    ((x & 0xf0) | (x ^ 0x0f)) + ~x + (x << 3) + (x >> 2) + (x >>> 4)
}

object Mixed {
  // The same expression in plain Scala, which is what a compiled snippet has to
  // agree with.
  def reference(x: Int): Int =
    ((x & 0xf0) | (x ^ 0x0f)) + ~x + (x << 3) + (x >> 2) + (x >>> 4)

  val inputs: Seq[Int] = Seq(0, 1, 42, -1, -42, Int.MinValue, Int.MaxValue)
}

@virtualize
class BitwiseTests extends SnapshotFunSuite {
  val under = "bitwise/"

  // Unoptimized, so every operator has to survive to the snapshot rather than
  // being folded into the constants sitting next to it.
  test("every operator renders") {
    object Snippet extends SimpleSnippetDriver[Int, Int] with Mixed {
      def snippet(x: Rep[Int]): Rep[Int] = mixed(x)
    }
    check("mixed", Snippet.code)
  }

  test("the emitted Scala agrees with Int's own operators") {
    object Snippet
        extends DslDriver[Int, Int] with Mixed with EvalScalaSnippet[Int, Int] {
      val prefix = "bitwise-test"
      val name = "bitwise"
      def snippet(x: Rep[Int]): Rep[Int] = mixed(x)
    }

    Mixed.inputs.foreach { x =>
      assertResult(Mixed.reference(x), s"on $x") { Snippet.eval(x) }
    }
  }

  // `x & x` is the sharp end of this: without the rule it stays two nodes, and
  // with it the whole snippet is just `x`.
  test("identities collapse under saturation") {
    object Snippet extends DslDriver[Int, Int] {
      def snippet(x: Rep[Int]): Rep[Int] = ((x & x) | 0) ^ 0
    }
    check("identities", Snippet.code)
  }

  test("a mask folds into one literal") {
    object Snippet extends DslDriver[Int, Int] {
      def snippet(x: Rep[Int]): Rep[Int] = x & ((0xf0 | 0x0f) << 4)
    }
    check("fold-mask", Snippet.code)
  }
}

@virtualize
class BitwiseCTests extends SnapshotFunSuite {
  val under = "cbitwise/"

  override def check(
      label: String,
      actual: String,
      ext: String = "c",
      accept: Boolean = false
  ) = super.check(label, actual, ext, accept)

  abstract class CSnippetDriver[A: Typable, B: Typable]
      extends SimpleSnippetDriver[A, B] with DslOps {
    override val codegen = CCodegen()
  }

  test("every operator renders") {
    object Snippet extends CSnippetDriver[Int, Int] with Mixed {
      def snippet(x: Rep[Int]): Rep[Int] = mixed(x)
    }
    check("mixed", Snippet.code)
  }

  // C has no `>>>`, so this pins the detour through `unsigned int` on its own.
  test("logical shift right goes through unsigned") {
    object Snippet extends CSnippetDriver[Int, Int] {
      def snippet(x: Rep[Int]): Rep[Int] = x >>> 4
    }
    check("ushr", Snippet.code)
  }
}
