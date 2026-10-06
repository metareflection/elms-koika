package elms.test

import org.scalatest.funsuite.AnyFunSuite

import elms.core.{Name, Op}
import elms.core.given
import elms.core.tree.*
import elms.pipeline.InlineRanges

// The pass is general, so it is tested on terms. Going through the C backend
// would tie it to that backend's formatting and hide what the pass did behind
// what the emitter chose to print.
class InlineRangesTests extends AnyFunSuite {
  private val a = Name.from("a")
  private val b = Name.from("b")
  private val r = Name.from("r")
  private val i = Name.from("i")

  private def range(st: Name, en: Name): Term = E(Op.Range, Seq(V(st), V(en)))

  // What `RangeOps.foreach` builds: the range is bound, and both endpoints are
  // read back out of it rather than taken from the terms it was built from.
  private def foreachShape(body: Term, notes: Seq[Note] = Seq()): Term = Let(
    r,
    range(a, b),
    E(
      Op.RangeForEach(i),
      Seq(E(Op.RangeStart, Seq(V(r))), E(Op.RangeEnd, Seq(V(r))), body)
    ),
    notes
  )

  test("a foreach loses its range and reads the original endpoints") {
    val body = V(i)
    val expected = E(Op.RangeForEach(i), Seq(V(a), V(b), body))

    assert(InlineRanges.run(foreachShape(body)) == expected)
  }

  // Unreachable from the DSL: `simple.Builder.reflect` gives `Seq()` to every
  // `Op.Pure`, so nothing can put a note on a range. The guard exists so that a
  // future note is not silently deleted along with the binding, and a
  // hand-built term is the only way to reach it.
  test("a note keeps a range binding that nothing else names") {
    val note = Note(Seq("@ assert 1;"), Seq(), Note.Side.Before)
    val orphan = Let(r, range(a, b), V(i), Seq(note))

    assert(InlineRanges.run(orphan) == orphan)
  }

  test("a range nothing names is dropped") {
    assert(InlineRanges.run(Let(r, range(a, b), V(i), Seq())) == V(i))
  }

  // Both loops read their bounds off a name in scope, so a pass that kept one
  // set of bounds for the whole term would hand the inner loop the outer ones.
  test("two ranges in scope do not cross") {
    val s = Name.from("s")
    val j = Name.from("j")

    val inner = Let(
      s,
      range(i, b),
      E(
        Op.RangeForEach(j),
        Seq(E(Op.RangeStart, Seq(V(s))), E(Op.RangeEnd, Seq(V(s))), V(j))
      ),
      Seq()
    )

    val expected = E(
      Op.RangeForEach(i),
      Seq(V(a), V(b), E(Op.RangeForEach(j), Seq(V(i), V(b), V(j))))
    )

    assert(InlineRanges.run(foreachShape(inner)) == expected)
  }

  // The projection rewrites to a term that needs no binding of its own, so the
  // binding `foreach` put in front of the loop goes with it.
  test("an endpoint binding is not left behind") {
    val st = Name.from("st")
    val term = Let(r, range(a, b), Let(st, E(Op.RangeStart, Seq(V(r))), V(st), Seq()), Seq())

    assert(InlineRanges.run(term) == V(a))
  }

  // A projection off something that is not a range binding cannot be rewritten,
  // and its binding has to survive: this is the shape a first-class range
  // leaves behind, and dropping it would lose the read.
  test("a projection the pass cannot see through keeps its binding") {
    val st = Name.from("st")
    val term = Let(st, E(Op.RangeStart, Seq(V(Name.from("o")))), V(st), Seq())

    assert(InlineRanges.run(term) == term)
  }

  // Nothing in a term without a range has any business changing.
  test("a term with no range is untouched") {
    val term =
      Let(a, E(Op.Const(1), Seq()), Let(b, E(Op.Plus, Seq(V(a), V(a))), V(b), Seq()), Seq())

    assert(InlineRanges.run(term) == term)
  }
}
