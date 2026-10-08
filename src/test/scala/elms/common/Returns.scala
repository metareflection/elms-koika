package elms.koika.test.common

// The staging-time return stack: where each call still in flight will come
// back to, innermost first.
//
// This is the tower's return stack buffer, and it is a prediction rather than
// the truth. What a machine would really return to is whatever `regs[1]`
// holds, and where the two differ the ISA raises an assertion rather than a
// second edge.
//
// Both towers carry one and neither can inherit it from the other, since
// [Common] and [Squared] have no ancestor between them. What each still owes
// after mixing this in is interning [retstack] into its own slot key: a pc
// arrived at under two different stacks is two different continuations, and
// sharing a slot between them returns one of the calls to the wrong place.
trait Returns {
  protected var retstack: List[Int] = Nil

  // How deep the stack is allowed to get.
  //
  // A program whose recursion the reader cannot bound grows one forever, and
  // every frame is a fresh slot key, so the worklist never empties. Without a
  // cap the symptom is sbt sitting there, which is the least readable way a
  // model can decline to answer. Generous on purpose: the deepest chain in
  // anything portable here is `crypto_secretbox`'s seven, and a demo that
  // really is deeper can say so.
  def maxCallDepth: Int = 32

  // One frame, checked. [at] is the call and [resume] is where it comes back
  // to.
  //
  // A pc appearing twice in the chain is recursion and raising the cap will
  // not help. A chain of distinct pcs is a program that nests further than the
  // cap, and raising it is exactly the fix. Those want different answers from
  // whoever reads the message, so the message says which it is first and shows
  // the frames second.
  protected def deepen(at: Int, resume: Int): List[Int] = {
    val next = resume :: retstack
    if (next.length > maxCallDepth) {
      val twice = next.groupBy(identity).collect { case (pc, hits) if hits.length > 1 => pc }
      val what =
        if (twice.isEmpty) {
          s"nests past `maxCallDepth` ($maxCallDepth); raise it if the program really is this deep"
        } else {
          s"returns to pc ${twice.toSeq.sorted.mkString(", ")} again," +
            " which is recursion no static return stack can bound"
        }
      sys.error(s"call at pc $at $what. Frames, innermost first: ${frames(next)}")
    }
    next
  }

  // Runs collapsed, because the interesting part of a recursive chain is that
  // one pc repeats and not how many times the cap let it.
  private def frames(st: List[Int]): String = {
    val runs = st.foldRight(List.empty[(Int, Int)]) {
      case (pc, (p, n) :: rest) if p == pc => (p, n + 1) :: rest
      case (pc, acc)                       => (pc, 1) :: acc
    }
    val shown = runs.take(8).map { case (pc, 1) => s"$pc"; case (pc, n) => s"$pc x$n" }
    (shown ++ Option.when(runs.length > 8)("...")).mkString(" <- ")
  }

  protected def withStack[A](st: List[Int])(body: => A): A = {
    val outer = retstack
    retstack = st
    try { body }
    finally { retstack = outer }
  }
}
