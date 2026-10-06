package elms.test

import scala.language.implicitConversions

import elms.prelude.{_, given}
import elms.helpers.{SimpleSnippetDriver, DslOps}
import elms.codegen.CCodegen

// All seven string operations used to be bare `???` in the C backend, so
// reaching one took the pipeline down rather than reporting anything. Five of
// them now go through `elms_lib.h`; `length` and `charAt` stay inline because
// there is nothing to wrap.
@virtualize
class StringTests extends SnapshotFunSuite {
  val under = "cstring/"

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

  // Before any of the rest. A `NotImplementedError` out of a codegen pass is
  // what this is really fixing, and a snapshot that happens to exist does not
  // assert it.
  test("none of the seven throws") {
    object Snippet extends CDriver[String, Int] {
      def snippet(s: Rep[String]): Rep[Int] = {
        val c = s.charAt(unit(0))
        val hit =
          if s.startsWith(unit("he")) then unit(1)
          else if s.endsWith(unit("lo")) then unit(2)
          else if c === unit('x') then unit(3)
          else unit(0)
        s.length + s.drop(unit(2)).length + s.take(unit(3)).length +
          s.substring(unit(1), unit(4)).length + hit
      }
    }

    val code = Snippet.code
    check("string-ops", code)
    assert(!code.contains("ERROR"))
    assert(!code.contains("???"))
  }

  // Keeping `length` inline is the point of not putting it in the header, and
  // that is invisible unless something asserts the header is absent.
  test("length needs string.h and no helper") {
    object Snippet extends CDriver[String, Int] {
      def snippet(s: Rep[String]): Rep[Int] = s.length
    }
    val code = Snippet.code
    check("string-length", code)
    assert(code.contains("(int)strlen("))
    assert(code.contains("#include <string.h>"))
    assert(!code.contains("elms_lib.h"))
  }

  // `charAt` calls nothing, so it asks for nothing. Requesting `string.h` from
  // a `renderType(STRING)` hook instead would pull it into every program that
  // so much as mentions a string.
  test("charAt needs neither header") {
    object Snippet extends CDriver[String, Char] {
      def snippet(s: Rep[String]): Rep[Char] = s.charAt(unit(0))
    }
    val code = Snippet.code
    check("string-charat", code)
    assert(!code.contains("#include"))
  }

  // `strndup` is POSIX 2008, hidden on glibc without a feature-test macro and
  // missing on MSVC. The helper rolls its own `malloc` and `memcpy` and needs
  // none of that.
  test("substring goes through the header and needs no feature macro") {
    object Snippet extends CDriver[String, String] {
      def snippet(s: Rep[String]): Rep[String] = s.substring(unit(1), unit(4))
    }
    val code = Snippet.code
    check("string-substring", code)
    assert(code.contains("elms_str_substring("))
    assert(code.contains("#include \"elms_lib.h\""))
    assert(!code.contains("_POSIX_C_SOURCE"))
  }

  test("autoIncludes off keeps the helper call") {
    val code = new TunedDriver[String, String](
      CCodegen(opts = CCodegen.Options(autoIncludes = false))
    ) {
      def snippet(s: Rep[String]): Rep[String] = s.substring(unit(1), unit(4))
    }.code

    assert(!code.contains("#include"))
    assert(code.contains("elms_str_substring("))
  }
}

// What a snapshot cannot check. `strncmp(s, p, strlen(p))` and
// `strncmp(p, s, strlen(s))` look equally plausible on the page and compute
// different things, and the clamping only exists so the two backends agree.
@virtualize
class StringRuntimeTests extends org.scalatest.funsuite.AnyFunSuite {
  abstract class CDriver[A: Typable, B: Typable]
      extends SimpleSnippetDriver[A, B] with DslOps {
    override val codegen = CCodegen()
  }

  // One compile per snippet, run over every bound, with the answers printed one
  // per line so they line up with the reference.
  private def agrees(code: String, ns: Seq[Int], expected: Int => String): Unit = {
    val calls = ns.map { n => s"""  printf("%s\\n", snippet($n));""" }.mkString("\n")
    val main =
      s"""#include <stdio.h>
         |const char * snippet(int x0);
         |int main(void) {
         |$calls
         |  return 0;
         |}
         |""".stripMargin

    CRunner.run(code, main) match {
      case None      => cancel("no C compiler on this machine")
      case Some(out) => assert(out.linesIterator.toVector == ns.map(expected).toVector)
    }
  }

  test("drop clamps the way Scala's does") {
    object Snippet extends CDriver[Int, String] {
      def snippet(n: Rep[Int]): Rep[String] = unit("hello").drop(n)
    }
    val ns = Seq(-3, 0, 2, 5, 99)
    assert(ns.map("hello".drop).distinct.length == 3)
    agrees(Snippet.code, ns, n => "hello".drop(n))
  }

  test("take clamps the way Scala's does") {
    object Snippet extends CDriver[Int, String] {
      def snippet(n: Rep[Int]): Rep[String] = unit("hello").take(n)
    }
    val ns = Seq(-1, 0, 3, 5, 99)
    assert(ns.map("hello".take).distinct.length == 3)
    agrees(Snippet.code, ns, n => "hello".take(n))
  }

  // A backwards slice is where the clamp earns its keep: without it, `b - a` is
  // negative, converting it to `size_t` asks `malloc` for a number near 2^64,
  // and nothing checks the `NULL` that comes back.
  test("substring clamps the way Scala's slice does") {
    object Snippet extends CDriver[Int, String] {
      def snippet(n: Rep[Int]): Rep[String] = unit("hello").substring(n, unit(3))
    }
    val ns = Seq(-2, 0, 1, 3, 4, 99)
    assert(ns.map("hello".slice(_, 3)).distinct.length == 3)
    agrees(Snippet.code, ns, n => "hello".slice(n, 3))
  }

  test("startsWith and endsWith take their arguments the right way round") {
    object Snippet extends CDriver[Int, String] {
      def snippet(n: Rep[Int]): Rep[String] = {
        val s = unit("hello")
        // Four answers, so swapping the two operands of either helper shows up.
        if s.startsWith(unit("he")) && s.endsWith(unit("lo")) then unit("both")
        else if s.startsWith(unit("he")) then unit("start")
        else if s.endsWith(unit("lo")) then unit("end")
        else unit("neither")
      }
    }
    agrees(Snippet.code, Seq(0), _ => "both")
  }

  // `hello` starts with `hello` and ends with `hello`, and neither helper may
  // read past the end when the needle is the longer of the two.
  test("a needle longer than the haystack matches nothing") {
    object Snippet extends CDriver[Int, String] {
      def snippet(n: Rep[Int]): Rep[String] = {
        val s = unit("hi")
        if s.startsWith(unit("hello")) then unit("start")
        else if s.endsWith(unit("hello")) then unit("end")
        else unit("neither")
      }
    }
    agrees(Snippet.code, Seq(0), _ => "neither")
  }
}
