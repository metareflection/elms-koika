package elms.test

import scala.language.implicitConversions

import elms.prelude.{_, given}
import elms.helpers.{SimpleSnippetDriver, DslOps}
import elms.core.StructManifest
import elms.codegen.CCodegen

// A C array decays to a pointer and a pointer does not know how long it is, so
// an element type something measures gets a struct that carries the length
// beside the data.
//
// Promotion is per element type and program-wide, which is what these pin: the
// rule is coarse on purpose, and the alternative is a whole-program fixpoint.
@virtualize
class FatArrayTests extends SnapshotFunSuite {
  val under = "carray/"

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

  case class Box(xs: Array[Int], n: Int) derives StructManifest
  case class Buffer(xs: FixedArray[16, Int], n: Int) derives StructManifest

  test("an array that gets measured carries its length") {
    object Snippet extends CDriver[Int, Int] {
      def snippet(x: Rep[Int]): Rep[Int] = {
        val a = newArray[Int](x)
        a.set(unit(0), x)
        a.length + a.get(unit(0))
      }
    }
    val code = Snippet.code
    check("array-length", code)
    assert(!code.contains("ERROR"))
    assert(code.contains("ELMS_ARR_DECL(elms_arr_int, int)"))
  }

  // The whole point of promoting on demand, and the assertion that catches a
  // regression to always-fat.
  test("an array nobody measures stays a bare pointer") {
    object Snippet extends CDriver[Int, Int] {
      def snippet(x: Rep[Int]): Rep[Int] = {
        val a = newArray[Int](x)
        a.set(unit(0), x)
        a.get(unit(0))
      }
    }
    val code = Snippet.code
    check("array-no-length", code)
    assert(code.contains("malloc"))
    assert(!code.contains("elms_arr"))
  }

  // The property the per-element-type rule buys. A caller and a callee have to
  // agree on a parameter's C type, and a rule keyed on the use site would have
  // to prove that agreement rather than getting it by construction.
  test("a measured array crosses a call boundary") {
    object Snippet extends CDriver[Int, Int] {
      def measure(a: Rep[Array[Int]]): Rep[Int] = a.length
      def snippet(x: Rep[Int]): Rep[Int] = {
        val a = newArray[Int](x)
        a.set(unit(0), unit(9))
        fun(measure)(a) + a.get(unit(0))
      }
    }
    val code = Snippet.code
    check("array-across-call", code)
    assert(!code.contains("ERROR"))
    assert(code.contains("int x5(elms_arr_int x6);"))
  }

  // Promotion follows the element type, so measuring one array does not widen
  // an unrelated one. This is the analysis, read off the output.
  test("only the measured element type is promoted") {
    object Snippet extends CDriver[Int, Int] {
      def snippet(x: Rep[Int]): Rep[Int] = {
        val ints = newArray[Int](x)
        val chars = newArray[Char](x)
        chars.set(unit(0), unit('z'))
        ints.length
      }
    }
    val code = Snippet.code
    check("array-two-elems", code)
    assert(code.contains("elms_arr_int"))
    assert(!code.contains("elms_arr_char"))
    assert(code.contains("char * "))
  }

  // `renderDeclarator` falls through to `renderType` for anything but a
  // fixed-length member, so a fat member needs no work of its own. Unlike the
  // bare pointer it replaces, copying the struct now copies a length that is
  // right.
  test("a struct member is promoted with its element type") {
    object Snippet extends CDriver[Box, Int] {
      def snippet(b: Rep[Box]): Rep[Int] =
        b.get("xs").asInstanceOf[Rep[Array[Int]]].length
    }
    val code = Snippet.code
    check("array-in-struct", code)
    assert(!code.contains("ERROR"))
    assert(code.contains("elms_arr_int xs;"))
  }

  // The declaration has to come out before the struct that names it, and the
  // other direction needs no ordering, because a struct element renders as
  // `struct Box *` and a pointer to an incomplete type is fine in a typedef.
  test("an array of structs declares in the right order") {
    object Snippet extends CDriver[Int, Int] {
      def snippet(x: Rep[Int]): Rep[Int] = newArray[Box](x).length
    }
    val code = Snippet.code
    check("array-of-struct", code)
    assert(!code.contains("ERROR"))
    assert(code.indexOf("ELMS_ARR_DECL") < code.indexOf("struct Box {"))
  }

  // `elemTag` recurses, so this is the case that needs the declarations sorted
  // by nesting depth. Shipping the recursion untested is how an ordering bug
  // gets in.
  test("a fat array of fat arrays declares inner first") {
    object Snippet extends CDriver[Int, Int] {
      def snippet(x: Rep[Int]): Rep[Int] = {
        val outer = newArray[Array[Int]](x)
        outer.set(unit(0), newArray[Int](x))
        outer.length + outer.get(unit(0)).length
      }
    }
    val code = Snippet.code
    check("array-nested", code)
    assert(!code.contains("ERROR"))
    assert(code.indexOf("ELMS_ARR_DECL(elms_arr_int,") <
      code.indexOf("ELMS_ARR_DECL(elms_arr_arr_int,"))
  }

  // A fixed-length array knows its length statically, so measuring one asks
  // nothing of the analysis.
  test("a fixed-length member needs no promotion") {
    object Snippet extends CDriver[Buffer, Int] {
      def snippet(b: Rep[Buffer]): Rep[Int] =
        b.get("xs").asInstanceOf[Rep[Array[Int]]].length
    }
    val code = Snippet.code
    check("array-fixed", code)
    assert(!code.contains("elms_arr"))
    assert(code.contains("16"))
  }

  test("fatArrays off reports the option by name") {
    val code = new TunedDriver[Int, Int](
      CCodegen(opts = CCodegen.Options(fatArrays = false))
    ) {
      def snippet(x: Rep[Int]): Rep[Int] = {
        val a = newArray[Int](x)
        a.set(unit(0), x)
        a.length + a.get(unit(0))
      }
    }.code

    assert(!code.contains("elms_arr"))
    assert(!code.contains("elms_lib.h"))
    assert(code.contains("malloc"))

    val refusals = code.linesIterator.filter(_.contains("ERROR")).toVector
    assert(refusals.length == 1)
    assert(refusals.head.contains("`fatArrays` is on"))
  }
}
