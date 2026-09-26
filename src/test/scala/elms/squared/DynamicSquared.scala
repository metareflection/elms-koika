package elms.koika.test.squared

import elms.prelude.given

// A conditional the two runs are allowed to answer differently.
//
// [Squared.agree] compares the two branch conditions and assumes them equal,
// so the tower decides the classical constant-time discipline rather than the
// question `src/out/*/riscv` asks. Those are not the same property and
// `balanced.s` is the demo where they come apart, with
// `squared/riscv/naive/balanced` the residue where a checker says so.
//
// Call that the static squared construction, since which way a conditional
// goes is settled while it stages. This is the dynamic one, where the answer
// is settled by the runs. A conditional stops having one thing it can do and
// grows four arms, and the two where the runs disagree walk each run's tail on
// its own:
//
//   if (v_ca) {
//     if (v_cb) { p = slot_T_both(p); }
//     else      { p = slot_T_solo0(p); p = slot_E_solo1(p); }
//   } else {
//     if (v_cb) { p = slot_E_solo0(p); p = slot_T_solo1(p); }
//     else      { p = slot_E_both(p); }
//   }
//
// No dispatch anywhere, and no runtime test of which side anything is. The
// pairing is still erased at staging time. What is given up is the sharing,
// and only on the two arms that have none left to give.
//
// Nothing else in the tower needs a solo case. [Squared.each] with one run
// live evaluates its body once and pairs the result with itself, so
// `sameClock` asserts `t == t` and the slicer drops it, and an [agree] with
// one run left is an ordinary conditional.
//
// What it costs is one extra copy of the tail per divergent branch site, and
// nothing compounds. Once a run is walking alone its branches are ordinary
// conditionals and cannot diverge again.
//
// The real cost is the assumption going away. On a shared path
// `squared_assume` prunes a pair that has already come apart, which is the
// only thing the squared construction buys over running the residue twice and
// comparing at the end. On a split path there is no pair left to prune and the
// solver walks both tails, which is self-composition's path space arriving
// exactly where the program was already going to be expensive. That is the
// other reason `dynamic/` is held back from a default `verify`.
//
// Phase one is [Flat] and [Cached], which is what `balanced` needs and where
// the disagreement lives. The two models above them each raise a question of
// their own. [Predictive] can split with a window still open, and its [Window]
// is staging-time and shared, so both solo walks inherit the same saved list
// and then resolve independently, which is right on both counts and still
// wants a test rather than an assumption. [Forwarding.close] requires the two
// runs' queues to be the same shape, which after a split they are not, so that
// `require` has to learn about [Squared.active] first.
trait DynamicSquared extends Squared {
  override protected def fuseOrSplit(
      c: Sided[Rep[Boolean]]
  )(t: => Pair)(e: => Pair): Pair =
    choose(c.a) {
      choose(c.b) { t } { split(t, e) }
    } {
      choose(c.b) { split(e, t) } { e }
    }

  // Run 0 walks [x] alone and then run 1 walks [y] alone. The two touch
  // disjoint halves of one struct, so sequencing them is sound, and either
  // walk hands back the same pair it was given, so the second one's result is
  // the pair both have finished with.
  private def split(x: => Pair, y: => Pair): Pair = {
    solo(0) { x }
    solo(1) { y }
  }
}
