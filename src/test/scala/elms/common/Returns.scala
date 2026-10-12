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
  // Whether a source-level call is specialized into the caller.
  //
  // True is the scheme this trait was written for: the callee is staged once
  // per call site, every transfer in the residue is a tail call, and the
  // return stack below is what makes the second copy come back somewhere
  // different from the first.
  //
  // False keys a slot on its pc alone, so the callee is one residue function
  // however many sites reach it, and a `ret` is a C `return` rather than a
  // tail call to a predicted pc. The return stack then stays empty and
  // nothing in here is reached. What it costs is in [Predictive]: a shared
  // function has one exit and the staging-time history at that exit depends
  // on the path taken inside it, so a predictor's history cannot flow back
  // out to the caller.
  def inlineCalls: Boolean = true

  // Whether the call to [target] in particular may be shared, once
  // [inlineCalls] has said the tower is willing to share at all.
  //
  // The two are separate because the second question is the program's and not
  // the model's. A model that carries staging-time state a `ret` would have to
  // carry back answers this per callee, and [riscv.Flow] is where that is
  // worked out; everything else shares every call it is offered.
  def shareable(target: Int): Boolean = true

  // Whether this model keeps a branch predictor's history at staging time.
  //
  // The one piece of state a shared callee cannot hand back, because a
  // function with one exit cannot say which path reached it. [Predictive] is
  // what sets this, and [Static] is what puts it back: a predictor that
  // records nothing has nothing to lose at a `ret`.
  def carriesHistory: Boolean = false

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
