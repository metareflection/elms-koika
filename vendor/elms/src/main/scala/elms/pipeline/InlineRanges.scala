package elms.pipeline

import elms.core.{Name, Op}
import elms.core.tree.*

// Takes the range value back out of a `foreach`.
//
// `RangeOps.foreach` does not read the endpoints off the range it was called
// on. It reflects `RangeForEach(RangeStart(r), RangeEnd(r), body)`, so every
// loop in the language arrives with an `r` in it, and C has no type for one.
// This rewrites each projection to the endpoint the range was built from and
// drops the binding once nothing names it.
object InlineRanges {
  def run(t: Term): Term = go(t, Map.empty, Map.empty)._1

  // A rewritten term and the names it still mentions. The name set ignores
  // binding structure inside an `E`, so it is an over-approximation, and the
  // only thing it decides is whether a binding survives. Erring high keeps a
  // binding that could have gone, which is the harmless direction.
  private type Rewritten = (Term, Set[Name])

  // What each range-bound name was built from, already rewritten.
  private type Bounds = Map[Name, (Rewritten, Rewritten)]

  // A binding this pass rewrote down to something that needs no binding of its
  // own, and what goes at its use sites instead.
  private type Atoms = Map[Name, Rewritten]

  // Free to copy to every use site: a name costs nothing to repeat and a
  // literal costs less.
  private def isAtomic(t: Term): Boolean = t match {
    case V(_)                   => true
    case E(Op.Const(_), Seq())  => true
    case _                      => false
  }

  private def go(t: Term, ranges: Bounds, atoms: Atoms): Rewritten = t match {
    case V(name) => atoms.getOrElse(name, (V(name), Set(name)))

    // No scope check is needed to substitute the endpoint here, and that is the
    // reason this pass gets to be as simple as it is: in ANF the endpoint is
    // bound before the range and the range before this use, so the endpoint's
    // scope already covers every site being rewritten.
    case E(Op.RangeStart, Seq(V(x))) if ranges.contains(x) => ranges(x)._1
    case E(Op.RangeEnd, Seq(V(x))) if ranges.contains(x)   => ranges(x)._2

    // The same rewrite for a range that something upstream already inlined into
    // the projection. Cheap, and it means the pass still fires on a term that
    // is not in ANF.
    case E(Op.RangeStart, Seq(E(Op.Range, Seq(a, _)))) => go(a, ranges, atoms)
    case E(Op.RangeEnd, Seq(E(Op.Range, Seq(_, b))))   => go(b, ranges, atoms)

    case Let(x, E(Op.Range, Seq(a, b)), e2, notes) => {
      val start = go(a, ranges, atoms)
      val end = go(b, ranges, atoms)
      val (body, used) = go(e2, ranges + (x -> (start, end)), atoms)
      val (ns, un) = goNotes(notes, ranges, atoms)

      // Dropping the binding is sound because `Op.Range` is `Pure`: with
      // nothing left naming it, it computes nothing anyone can observe.
      // Reclassify `Range` as effectful and this rule has to go with it.
      //
      // A note keeps the binding whatever else happens. Nothing can put a note
      // on a range today, since `simple.Builder.reflect` hands `Seq()` to every
      // `Op.Pure` and in `eqsat` a pure op never reaches the CFG, so the guard
      // is dead. It is also the difference between a future note landing on a
      // range and a future note being silently deleted.
      if used.contains(x) || ns.nonEmpty then {
        val kept = Let(x, E(Op.Range, Seq(start._1, end._1)), body, ns)
        (kept, (used - x) ++ start._2 ++ end._2 ++ un)
      } else (body, used ++ un)
    }

    // `foreach` binds both endpoints before reading them, so inlining the range
    // leaves `x = x2` in front of every loop. Only a projection this pass just
    // rewrote can land here, so no copy the front end wrote is touched.
    case Let(x, e1 @ (E(Op.RangeStart, _) | E(Op.RangeEnd, _)), e2, notes)
        if notes.isEmpty => {
      val rewritten = go(e1, ranges, atoms)
      if isAtomic(rewritten._1) then go(e2, ranges, atoms + (x -> rewritten))
      else {
        val (t2, u2) = go(e2, ranges, atoms)
        (Let(x, rewritten._1, t2, Seq()), rewritten._2 ++ (u2 - x))
      }
    }

    case Let(x, e1, e2, notes) => {
      val (t1, u1) = go(e1, ranges, atoms)
      val (t2, u2) = go(e2, ranges, atoms)
      val (ns, un) = goNotes(notes, ranges, atoms)
      (Let(x, t1, t2, ns), u1 ++ un ++ (u2 - x))
    }

    case Function(args, outty, body, notes) => {
      val (b, ub) = go(body, ranges, atoms)
      val (ns, un) = goNotes(notes, ranges, atoms)
      (Function(args, outty, b, ns), (ub -- args.map(_._1)) ++ un)
    }

    // A range bound inside a loop body cannot be named outside it, so nothing
    // has to unwind `ranges` at a region boundary. Threading the maps through
    // `go` rather than holding them in a field is what gets that for free.
    case E(op, children) => {
      val (cs, used) = children.map(go(_, ranges, atoms)).unzip
      (E(op, cs), used.foldLeft(Set.empty[Name])(_ ++ _))
    }
  }

  private def goNotes(
      notes: Seq[Note],
      ranges: Bounds,
      atoms: Atoms
  ): (Seq[Note], Set[Name]) = {
    val rewritten = notes.map { note =>
      val (args, used) = note.args.map(go(_, ranges, atoms)).unzip
      (note.copy(args = args), used.foldLeft(Set.empty[Name])(_ ++ _))
    }
    (rewritten.map(_._1), rewritten.map(_._2).foldLeft(Set.empty[Name])(_ ++ _))
  }
}
