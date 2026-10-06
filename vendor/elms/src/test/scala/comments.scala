package elms.test

import scala.language.implicitConversions

import org.scalatest.funsuite.AnyFunSuite

import elms.prelude.{_, given}
import elms.helpers.{DslOps, SimpleSnippetDriver}
import elms.core.CommentMeta
import elms.codegen.{Config, ScalaCodegen}

// A vocabulary of one, which is all it takes to show that `meta` reaches the
// backend rather than being dropped on the way.
case object Block extends CommentMeta

// Renders anything carrying `Block` as a C-style block and everything else the
// default way, so a note that came through with `None` looks different from one
// that kept its meta.
class BlockCodegen extends ScalaCodegen(Config.scalaDefault) {
  override protected def renderComment(
      text: String,
      meta: Option[CommentMeta]
  ): Seq[String] = meta match {
    case Some(Block) => Seq(s"/*$text */")
    case _           => super.renderComment(text, meta)
  }
}

// One snippet body with the annotations behind an abstract method, so the
// annotated and the plain version really are the same program and a difference
// in binding count can only have come from the annotations.
@virtualize
trait Annotated extends DslOps {
  def annotate(y: Rep[Int], i: Rep[Int]): Unit

  def body(x: Rep[Int]): Rep[Int] = {
    val y = x * 2
    val acc = newVar(0)

    for (i <- (0.until(y)): Rep[Range]) {
      annotate(y, i)
      acc := acc.get + i
    }

    acc.get + y
  }
}

object Annotated {
  // The same thing in plain Scala. Written as the loop rather than closed form,
  // because a negative input makes the range empty and the closed form does not
  // know that.
  def reference(x: Int): Int = {
    val y = x * 2
    (0 until y).sum + y
  }
}

object Comments {
  private val binding = raw"\s*(val|var|lazy val) x\d+.*".r

  def bindings(code: String): Int = code.linesIterator.count(binding.matches)

  // Both spellings, because a backend that knows the annotation language
  // renders a block rather than a line and the point of collecting these is to
  // see which one it chose.
  def commentLines(code: String): Seq[String] = code.linesIterator.map(_.trim)
    .filter { l => l.startsWith("//") || l.startsWith("/*") }.toSeq
}

@virtualize
class CommentTests extends AnyFunSuite {
  test("an annotation adds no binding to the program it annotates") {
    object Plain extends DslDriver[Int, Int] with Annotated {
      def annotate(y: Rep[Int], i: Rep[Int]): Unit = ()
      def snippet(x: Rep[Int]): Rep[Int] = body(x)
    }

    object Noted extends DslDriver[Int, Int] with Annotated {
      def annotate(y: Rep[Int], i: Rep[Int]): Unit = attach"@ assert $i < $y;"
      def snippet(x: Rep[Int]): Rep[Int] = body(x)
    }

    val plain = Plain.code
    val noted = Noted.code

    // Both guards, or the counts agree for the wrong reason: a snippet with no
    // bindings, or an annotated version that never got annotated.
    assert(Comments.bindings(plain) > 0, plain)
    assert(noted.contains("//@ assert"), noted)
    assertResult(Comments.bindings(plain), noted) { Comments.bindings(noted) }
  }

  // Bare, `$y * 2` with `y = a + b` reads as `a + b * 2`, which is a different
  // predicate over the same names.
  test("an interpolated argument is parenthesised") {
    object Snippet extends DslDriver[Int, Int] {
      def snippet(x: Rep[Int]): Rep[Int] = {
        val y = x + x
        comment"@ assert $y * 2 > 0;"
        x + 1
      }
    }

    val code = Snippet.code
    // Spelled out rather than just `") * 2"`: an argument that came out as a
    // name would be parenthesised by nobody, and the test would pass on a
    // snippet where the precedence question never arose.
    assert(code.contains("//@ assert (x0 + x0) * 2 > 0;"), code)
  }

  test("an orphan note becomes a free-standing comment, in both pipelines") {
    object Simple extends SimpleSnippetDriver[Int, Int] with DslOps {
      def snippet(x: Rep[Int]): Rep[Int] = {
        Builtins.attach("@ orphan, nothing follows;")
        x + x
      }
    }

    object Eqsat extends DslDriver[Int, Int] {
      def snippet(x: Rep[Int]): Rep[Int] = {
        Builtins.attach("@ orphan, nothing follows;")
        x + x
      }
    }

    assert(Simple.code.contains("//@ orphan, nothing follows;"), Simple.code)
    assert(Eqsat.code.contains("//@ orphan, nothing follows;"), Eqsat.code)
  }

  test("every line of a comment survives") {
    object Snippet extends SimpleSnippetDriver[Int, Int] with DslOps {
      def snippet(x: Rep[Int]): Rep[Int] = {
        Builtins.comment("@ first\n@ second")
        Builtins.comment("")
        x + 1
      }
    }

    assertResult(Seq("//@ first", "//@ second", "//")) {
      Comments.commentLines(Snippet.code)
    }
  }

  test("meta reaches the backend from both the statement and the contract") {
    object Snippet extends DslDriver[Int, Int] {
      override val codegen = BlockCodegen()

      def snippet(x: Rep[Int]): Rep[Int] = {
        Builtins.contract("@ requires x0 > 0;", Some(Block))
        Builtins.comment("@ assert true;", Some(Block))
        Builtins.comment("@ plain;")
        x + 1
      }
    }

    val lines = Comments.commentLines(Snippet.code)
    assert(lines.contains("/*@ requires x0 > 0; */"), lines.toString)
    assert(lines.contains("/*@ assert true; */"), lines.toString)
    // A note with no meta still takes the default route, or the override is
    // just rendering everything one way.
    assert(lines.contains("//@ plain;"), lines.toString)
  }

  // A comment is a `Write`, and a write clears the read memo. If a comment
  // cleared it too, writing one between two reads of the same cell would turn
  // them into two loads, and the annotation would have changed the program.
  test("a comment between two reads does not force a second load") {
    object Snippet extends DslDriver[Int, Int] with EvalScalaSnippet[Int, Int] {
      val prefix = "comment-eval"
      val name = "commentBetweenReads"

      def snippet(x: Rep[Int]): Rep[Int] = {
        val a = newArray[Int](1)
        a.set(0, x)
        val first = a.get(0)
        Builtins.comment("@ between;")
        first + a.get(0)
      }
    }

    assertResult(1, "loads emitted") { Reads.loads(Snippet.code) }
    Reads.agrees("comment between reads", Snippet.eval, x => 2 * x)
  }

  test("the annotated Scala still compiles and runs") {
    object Snippet
        extends DslDriver[Int, Int] with EvalScalaSnippet[Int, Int] with Annotated {
      val prefix = "comment-eval"
      val name = "annotated"

      def annotate(y: Rep[Int], i: Rep[Int]): Unit = {
        comment"@ assert $i < $y;"
        attach"@ assert $i >= 0;"
      }

      def snippet(x: Rep[Int]): Rep[Int] = body(x)
    }

    Reads.agrees("annotated body", Snippet.eval, Annotated.reference)
  }
}
