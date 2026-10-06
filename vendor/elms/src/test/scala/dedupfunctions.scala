package elms.test

import org.scalatest.funsuite.AnyFunSuite

import elms.core.{Name, Op, INT}
import elms.core.given
import elms.core.tree.*
import elms.pipeline.DedupFunctions

// Term-level, because what the pass decides is whether two bodies are the same
// up to the numbers the counter handed out, and going through a driver would
// only ever produce the numbering that driver happened to produce.
class DedupFunctionsTests extends AnyFunSuite {
  private def n(s: String): Name = Name.from(s)

  // `Name` has no `CanEqual`, and what these assert is which functions are left
  // rather than anything about the names themselves.
  private def names(p: Program): Seq[String] = p.functions.map(_._1.render("x"))

  // `f(arg) = arg * k`, with the bound names given, so two callers can build
  // the same function under different numbering.
  private def times(arg: Name, tmp: Name, k: Int): Function = Function(
    Seq((arg, INT)),
    INT,
    Let(tmp, E(Op.Times, Seq(V(arg), E(Op.Const(k), Seq()))), V(tmp), Seq()),
    Seq()
  )

  private def prog(fns: (Name, Function)*): Program = Program(fns.toSeq, Seq())

  test("two functions that differ only in their bound names become one") {
    val a = times(n("x1"), n("x2"), 2)
    val b = times(n("x7"), n("x8"), 2)

    val out = DedupFunctions.run(prog(n("f") -> a, n("g") -> b))

    assert(names(out) == Seq("f"))
  }

  test("two functions with different bodies both survive") {
    val a = times(n("x1"), n("x2"), 2)
    val b = times(n("x7"), n("x8"), 3)

    val out = DedupFunctions.run(prog(n("f") -> a, n("g") -> b))

    assert(names(out) == Seq("f", "g"))
  }

  test("a call to the function that went away is redirected") {
    val a = times(n("x1"), n("x2"), 2)
    val b = times(n("x7"), n("x8"), 2)

    // `main(y) = g(y)`, naming the copy rather than the original.
    val main = Function(
      Seq((n("y"), INT)),
      INT,
      Let(n("r"), E(Op.App, Seq(V(n("g")), V(n("y")))), V(n("r")), Seq()),
      Seq()
    )

    val out = DedupFunctions.run(prog(n("f") -> a, n("g") -> b, n("main") -> main))

    assert(names(out) == Seq("f", "main"))
    assert(out.functions.toMap.apply(n("main")).body ==
      Let(n("r"), E(Op.App, Seq(V(n("f")), V(n("y")))), V(n("r")), Seq()))
  }

  // A function's own name is free in its body, so without binding it the two
  // would differ in exactly one place: the name each one calls.
  test("a recursive function and a copy of it become one") {
    def loop(self: Name, arg: Name, tmp: Name): Function = Function(
      Seq((arg, INT)),
      INT,
      Let(tmp, E(Op.App, Seq(V(self), V(arg))), V(tmp), Seq()),
      Seq()
    )

    val out = DedupFunctions.run(
      prog(n("f") -> loop(n("f"), n("x1"), n("x2")), n("g") -> loop(n("g"), n("x7"), n("x8")))
    )

    assert(names(out) == Seq("f"))
  }

  // Two callers are only equal once the two names they call have become one,
  // so this needs a second round to settle.
  test("a merge that makes two callers equal is followed through") {
    def caller(callee: Name, arg: Name, tmp: Name): Function = Function(
      Seq((arg, INT)),
      INT,
      Let(tmp, E(Op.App, Seq(V(callee), V(arg))), V(tmp), Seq()),
      Seq()
    )

    val out = DedupFunctions.run(prog(
      n("f") -> times(n("x1"), n("x2"), 2),
      n("g") -> times(n("x7"), n("x8"), 2),
      n("callsF") -> caller(n("f"), n("y1"), n("y2")),
      n("callsG") -> caller(n("g"), n("y7"), n("y8"))
    ))

    assert(names(out) == Seq("f", "callsF"))
  }

  test("a program with nothing to merge is handed back as it was") {
    val p = prog(n("f") -> times(n("x1"), n("x2"), 2), n("g") -> times(n("x7"), n("x8"), 3))

    val out = DedupFunctions.run(p)
    assert(names(out) == names(p))
    assert(out.functions.map(_._2.body) == p.functions.map(_._2.body))
  }
}
