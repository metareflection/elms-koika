package elms.test

import scala.language.implicitConversions

import elms.prelude.{_, given}
import elms.helpers.{SimpleSnippetDriver, DslOps}
import elms.codegen.CCodegen

// The reason `Rep[Char]` has an ordering at all. As a fold of `===` a digit
// class is ten comparisons, and every branch the generator emits is a branch
// something downstream has to reason about.
@virtualize
trait DigitClass extends DslOps {
  def isDigit(c: Rep[Char]): Rep[Boolean] = unit('0') <= c && c <= unit('9')
}

// The other half of reading a decimal digit. Without `toInt` the value needs a
// ten-way dispatch even once the guard is two comparisons, which is where the
// goals were actually going.
@virtualize
trait DigitValue extends DslOps {
  def digitValue(c: Rep[Char]): Rep[Int] = c.toInt - unit('0').toInt
}

@virtualize
class CharOrderingTests extends SnapshotFunSuite {
  val under = "cchar/"

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

  test("a digit class is two comparisons") {
    object Snippet extends CDriver[Char, Int] with DigitClass {
      def snippet(c: Rep[Char]): Rep[Int] = if isDigit(c) then unit(1) else unit(0)
    }
    val code = Snippet.code
    check("digit-class", code)
    assert("<=".r.findAllIn(code).size == 2)
    assert(!code.contains("=="))
  }

  // `char`'s signedness belongs to the target, so an ordering that renders as
  // the bare operator is a program whose answer depends on where it is
  // compiled. Equality is unaffected and would be noise in the output.
  test("an ordering casts and an equality does not") {
    object Ordered extends CDriver[Char, Int] {
      def snippet(c: Rep[Char]): Rep[Int] = if c >= unit('a') then unit(1) else unit(0)
    }
    object Equal extends CDriver[Char, Int] {
      def snippet(c: Rep[Char]): Rep[Int] = if c === unit('a') then unit(1) else unit(0)
    }
    check("char-ge", Ordered.code)
    assert(Ordered.code.contains("(unsigned char)"))
    assert(!Equal.code.contains("(unsigned char)"))
  }

  test("an int comparison is left alone") {
    object Snippet extends CDriver[Int, Int] {
      def snippet(x: Rep[Int]): Rep[Int] = if x >= unit(97) then unit(1) else unit(0)
    }
    assert(!Snippet.code.contains("(unsigned char)"))
  }

  // `!==` has been declared on `Rep[T]` all along with no call site anywhere in
  // the repo, so nothing has ever checked that it resolves past the `===` that
  // `core.EqualityOps` reimplements.
  test("!== resolves and negates") {
    object Snippet extends CDriver[Char, Boolean] {
      def snippet(c: Rep[Char]): Rep[Boolean] = c !== unit('a')
    }
    assert(Snippet.code.contains("!"))
  }

  test("a digit value is one subtraction") {
    object Snippet extends CDriver[Char, Int] with DigitValue {
      def snippet(c: Rep[Char]): Rep[Int] = digitValue(c)
    }
    val code = Snippet.code
    check("digit-value", code)
    assert(code.contains("(int)(unsigned char)"))
    assert(!code.contains("if"))
  }

  // The e-graph hash-conses `Op.Const`, and Scala's cooperative equality makes
  // `'A' == 65`. A case class compares only its first parameter list, so without
  // the hand-written `equals` these are one node, the two e-classes merge, and
  // extraction is free to hand back the `char`.
  test("a char constant and its code point are different constants") {
    import elms.core.Op
    import elms.core.instances.given
    assert(Op.Const('A') != Op.Const(65))
    assert(Op.Const('A') == Op.Const('A'))
    assert(Op.Const(65) == Op.Const(65))
  }

  test("a widened char constant folds") {
    object Snippet extends DslDriver[Int, Int] {
      def snippet(x: Rep[Int]): Rep[Int] = unit('A').toInt
    }
    val code = Snippet.code
    assert(code.contains("65"), code)
    assert(!code.contains("toInt"), code)
  }

  test("two char constants fold") {
    object Snippet extends DslDriver[Int, Boolean] {
      def snippet(x: Rep[Int]): Rep[Boolean] = unit('0') <= unit('9') &&
        unit('z') < unit('a')
    }
    val code = Snippet.code
    assert(!code.contains("<"), code)
    assert(code.contains("false"), code)
  }

  test("the emitted Scala agrees with Char's own toInt") {
    object Snippet
        extends DslDriver[Char, Int] with DigitValue with EvalScalaSnippet[Char, Int] {
      val prefix = "char-value-test"
      val name = "charvalues"
      def snippet(c: Rep[Char]): Rep[Int] = digitValue(c)
    }

    CharOrderingTests.inputs.foreach { c =>
      assertResult(c.toInt - '0'.toInt, s"on $c") { Snippet.eval(c) }
    }
  }

  test("the emitted Scala agrees with Char's own operators") {
    object Snippet
        extends DslDriver[Char, Boolean]
        with DigitClass
        with EvalScalaSnippet[Char, Boolean] {
      val prefix = "char-test"
      val name = "chars"
      def snippet(c: Rep[Char]): Rep[Boolean] = isDigit(c)
    }

    CharOrderingTests.inputs.foreach { c =>
      assertResult(c >= '0' && c <= '9', s"on $c") { Snippet.eval(c) }
    }
  }
}

object CharOrderingTests {
  // `é` is the one that matters: it is 233, which a signed `char` holds as
  // -23, so it lands on the far side of `'a'` from where Scala puts it.
  val inputs: Seq[Char] = Seq('\u0000', '/', '0', '5', '9', ':', 'a', '\u007f', 'é')
}

// What a snapshot cannot check. Whether the generated C agrees with Scala about
// `'\u00e9' >= 'a'` is a property of the compiled program, and the answer
// without the cast is the one this machine's `char` happens to have.
class CharRuntimeTests extends org.scalatest.funsuite.AnyFunSuite {
  abstract class CDriver[A: Typable, B: Typable]
      extends SimpleSnippetDriver[A, B] with DslOps {
    override val codegen = CCodegen()
  }

  // The snippets answer in `bool` and the ternary picking a word for it lives
  // in the C, so nothing here needs virtualizing.
  private def agrees(code: String, cs: Seq[Char], expected: Char => Boolean): Unit = {
    val calls = cs.map { c =>
      s"""  printf("%s\\n", snippet((char)${c.toInt}) ? "true" : "false");"""
    }.mkString("\n")
    val main = s"""#include <stdbool.h>
         |#include <stdio.h>
         |bool snippet(char x0);
         |int main(void) {
         |$calls
         |  return 0;
         |}
         |""".stripMargin

    CRunner.run(code, main) match {
      case None      => cancel("no C compiler on this machine")
      case Some(out) =>
        assert(out.linesIterator.toVector == cs.map(expected).map(_.toString).toVector)
    }
  }

  private def agreesInt(code: String, cs: Seq[Char], expected: Char => Int): Unit = {
    val calls = cs.map { c => s"""  printf("%d\\n", snippet((char)${c.toInt}));""" }
      .mkString("\n")
    val main = s"""#include <stdio.h>
         |int snippet(char x0);
         |int main(void) {
         |$calls
         |  return 0;
         |}
         |""".stripMargin

    CRunner.run(code, main) match {
      case None      => cancel("no C compiler on this machine")
      case Some(out) =>
        assert(out.linesIterator.toVector == cs.map(expected).map(_.toString).toVector)
    }
  }

  // `\u00e9` is 233 and a signed `char` holds it as -23, so an uncast `(int)c`
  // is off by 256 here and nowhere else in the set.
  test("a digit value agrees with Scala's on a high-bit character") {
    object Snippet extends CDriver[Char, Int] with DigitValue {
      def snippet(c: Rep[Char]): Rep[Int] = digitValue(c)
    }
    val cs = CharOrderingTests.inputs
    assert(cs.map(c => c.toInt - '0'.toInt).distinct.length == cs.length)
    assert(cs.exists(_.toInt > 127))
    agreesInt(Snippet.code, cs, c => c.toInt - '0'.toInt)
  }

  test("a digit class agrees with Scala's") {
    object Snippet extends CDriver[Char, Boolean] with DigitClass {
      def snippet(c: Rep[Char]): Rep[Boolean] = isDigit(c)
    }
    val cs = CharOrderingTests.inputs
    assert(cs.map(c => c >= '0' && c <= '9').distinct.length == 2)
    agrees(Snippet.code, cs, c => c >= '0' && c <= '9')
  }

  // One comparison rather than a class, because a range test brackets the
  // high-bit character out on both sides and would pass on a signed `char` for
  // the wrong reason.
  test("a bare >= agrees with Scala's on a high-bit character") {
    object Snippet extends CDriver[Char, Boolean] {
      def snippet(c: Rep[Char]): Rep[Boolean] = c >= unit('a')
    }
    val cs = CharOrderingTests.inputs
    assert(cs.map(_ >= 'a').distinct.length == 2)
    assert(cs.exists(c => c.toInt > 127 && c >= 'a'))
    agrees(Snippet.code, cs, _ >= 'a')
  }
}
