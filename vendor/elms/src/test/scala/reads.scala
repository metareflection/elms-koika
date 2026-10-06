package elms.test

import scala.language.implicitConversions

import org.scalatest.funsuite.AnyFunSuite

import elms.prelude.{_, given}
import elms.helpers.{DslOps, SnippetDriver}
import elms.core.tree as ast
import elms.pipeline.Propagate
import elms.pipeline.eqsat
import elms.util.Plumbing.*

// `DslDriver` fixes the builder's config, so a test that wants `dropDeadReads`
// off needs a driver of its own. `Propagate.run` is here for the reason
// `OptimizingSnippetDriver` runs it: without it every value is reached through
// an alias binding and a count of the emitted loads means nothing.
abstract class ReadDriver[A: Typable, B: Typable](dropDeadReads: Boolean)
    extends SnippetDriver[A, B] with DslOps with EvalScalaSnippet[A, B] {
  override val builder = eqsat
    .Builder(eqsat.Builder.Config(dropDeadReads = dropDeadReads))

  override def extract(): ast.Program = {
    val prog = super.extract()
    ast.Program(prog.functions.map(_.mapRight(_.map(Propagate.run))), prog.staticData)
  }
}

object Reads {
  // Five inputs, so a test whose answer came out constant has nowhere to hide.
  val inputs: Seq[Int] = Seq(0, 1, 7, -3, 1000)

  // A rendered array load is `val xN = xM(i)` and a rendered store is
  // `val xN = xM(i) = v`, so the `=` inside the subscript is the whole of what
  // tells the two apart.
  private val load = raw"\s*val x\d+ = x\d+\([^=]*\)\s*".r

  def loads(code: String): Int = code.linesIterator.count(load.matches)

  // Runs the compiled snippet against the answer worked out by hand, having
  // first checked that the answer moves at all: an oracle that is flat across
  // every input agrees with a broken snippet for the wrong reason.
  def agrees(name: String, run: Int => Int, reference: Int => Int): Unit = {
    assert(
      inputs.map(reference).distinct.length == inputs.length,
      s"$name: flat oracle"
    )
    inputs.foreach { x => assert(run(x) == reference(x), s"$name on $x") }
  }
}

// A snapshot cannot see ordering. Break an invalidation rule and the snapshot
// moves while every binding in it still looks plausible, so these generate
// Scala, compile it, run it and compare against the answer worked out by hand.
@virtualize
class ReadOrderTests extends AnyFunSuite {
  test("an array read after a write is a second load") {
    object Snippet extends DslDriver[Int, Int] with EvalScalaSnippet[Int, Int] {
      val prefix = "read-order"
      val name = "arrayAcrossWrite"

      def snippet(x: Rep[Int]): Rep[Int] = {
        val a = newArray[Int](1)
        a.set(0, x)
        val before = a.get(0)
        a.set(0, 9)
        before * 100 + a.get(0)
      }
    }

    Reads.agrees("array across write", Snippet.eval, x => x * 100 + 9)
  }

  test("a variable read after a write is a second load") {
    object Snippet extends DslDriver[Int, Int] with EvalScalaSnippet[Int, Int] {
      val prefix = "read-order"
      val name = "varAcrossWrite"

      def snippet(x: Rep[Int]): Rep[Int] = {
        val v = newVar(x)
        val before = v.get
        v := v.get + 1
        before * 100 + v.get
      }
    }

    Reads.agrees("var across write", Snippet.eval, x => x * 100 + x + 1)
  }

  // The one that needs the region boundary. Nothing writes between `before` and
  // the loop, so the memo still holds `before` when the body's read is reflected
  // and only clearing at the boundary stops the body reusing it. Reused, every
  // iteration sees the original and the sum comes out `4x` rather than `4x + 6`.
  test("a loop body read is not the read made before the loop") {
    object Snippet extends DslDriver[Int, Int] with EvalScalaSnippet[Int, Int] {
      val prefix = "read-order"
      val name = "loopBodyRead"

      def snippet(x: Rep[Int]): Rep[Int] = {
        val arr = newArray[Int](4)
        arr.set(0, x)
        val acc = newVar(0)
        val before = arr.get(0)

        for (i <- (0.until(unit(4))): Rep[Range]) {
          val seen = arr.get(0)
          arr.set(0, seen + 1)
          acc := acc.get + seen
        }

        acc.get + before * 1000
      }
    }

    Reads.agrees("loop body read", Snippet.eval, x => 4 * x + 6 + 1000 * x)
  }

  // A read under a short-circuit guard has to stay inside the `if` the guard
  // compiles to. Hoisted out, the read runs on an index the guard just ruled
  // out and the snippet throws instead of answering false.
  test("a guarded read stays under its guard") {
    object Snippet extends DslDriver[Int, Boolean] with EvalScalaSnippet[Int, Boolean] {
      val prefix = "read-order"
      val name = "guardedRead"

      def snippet(x: Rep[Int]): Rep[Boolean] = {
        val a = newArray[Int](1)
        a.set(0, 5)
        (x < 1) && (a.get(x) > 0)
      }
    }

    assertResult(true, "in range") { Snippet.eval(0) }
    assertResult(false, "out of range") { Snippet.eval(7) }
  }
}

// Two reads with no write between them are one load, and a read nothing wanted
// is no load at all.
@virtualize
class DeadReadTests extends AnyFunSuite {
  test("three reads of one cell are one load") {
    object Snippet extends DslDriver[Int, Int] with EvalScalaSnippet[Int, Int] {
      val prefix = "dead-read"
      val name = "threeReads"

      def snippet(x: Rep[Int]): Rep[Int] = {
        val a = newArray[Int](1)
        a.set(0, x)
        a.get(0) + a.get(0) + a.get(0)
      }
    }

    Reads.agrees("three reads", Snippet.eval, x => 3 * x)
    assertResult(1, "loads emitted") { Reads.loads(Snippet.code) }
  }

  test("dropDeadReads decides whether the dead load survives") {
    // Two reads at different indices, so the memo cannot collapse them and the
    // load that disappears is the one the option removed rather than a hit.
    abstract class Snippet(drop: Boolean) extends ReadDriver[Int, Int](drop) {
      val prefix = "dead-read"

      def snippet(x: Rep[Int]): Rep[Int] = {
        val a = newArray[Int](2)
        a.set(0, x)
        a.set(1, x + 1)
        val _ = a.get(1)
        a.get(0)
      }
    }

    object Kept extends Snippet(false) {
      val name = "deadKept"
    }
    object Dropped extends Snippet(true) {
      val name = "deadDropped"
    }

    assertResult(2, "with dropDeadReads off") { Reads.loads(Kept.code) }
    assertResult(1, "with dropDeadReads on") { Reads.loads(Dropped.code) }

    Reads.agrees("dead kept", Kept.eval, identity)
    Reads.agrees("dead dropped", Dropped.eval, identity)
  }

  // Demand is recorded while elaborating and before anything is dropped, so the
  // outer read marks the inner one as wanted and then goes away itself. One
  // load survives a shape nobody writes on purpose, pinned here so it stays a
  // decision rather than a surprise.
  test("a nested dead read leaves its inner load behind") {
    object Snippet extends DslDriver[Int, Int] with EvalScalaSnippet[Int, Int] {
      val prefix = "dead-read"
      val name = "nestedDead"

      def snippet(x: Rep[Int]): Rep[Int] = {
        val a = newArray[Int](2)
        a.set(0, 1)
        a.set(1, x)
        val _ = a.get(a.get(0))
        unit(7)
      }
    }

    assertResult(1, "loads emitted") { Reads.loads(Snippet.code) }
    Reads.inputs.foreach { x => assertResult(7, s"on $x") { Snippet.eval(x) } }
  }
}
