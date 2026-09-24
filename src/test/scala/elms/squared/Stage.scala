package elms.koika.test.squared

import scala.collection.mutable

import elms.prelude.*
import elms.prelude.given
import elms.core.{Op, StructManifest, UNIT}

import elms.koika.test.common.{KoikaDriver, Prover, StateT}

// The squared interpreter, staged.
//
// Every rule it runs is the one [Run] runs; what differs is that `Rep` builds
// IR here, so walking the program writes one down instead. A slot becomes an
// emitted C function taking both states at once, and the two comparisons
// [Squared] owes become `squared_assert` followed by `squared_assume`.
//
// The assertion is the report. The assumption is the only thing this
// arrangement can buy over calling the residue twice and comparing at the
// end: a pair that has already come apart leaves the search rather than being
// enumerated and rejected.
abstract class SquaredKoikaDriver[
    R <: Int: ValueOf,
    M <: Int: ValueOf,
    C <: Int: ValueOf,
    T <: Int: ValueOf
] extends KoikaDriver[R, M, C, T, StateT2[R, M, C, T]]
    with Exec {
  // One run's struct, which is the one every model in the tree already emits.
  private given solo: StructManifest[StateT[R, M, C, T]] = StateT.manifest

  type Half = Rep[StateT[R, M, C, T]]
  type Pair = Rep[State]

  private def words(h: Half, field: String): Rep[Array[Int]] =
    h.get(field).asInstanceOf[Rep[Array[Int]]]

  extension (h: Half) {
    def regs: Rep[Array[Int]] = words(h, "regs")
    def mem: Rep[Array[Int]] = words(h, "mem")
    def saved_regs: Rep[Array[Int]] = words(h, "saved_regs")
    def reg_ready: Rep[Array[Int]] = words(h, "reg_ready")
    def cache_tags: Rep[Array[Int]] = words(h, "cache_tags")
    def cache_dirty: Rep[Array[Int]] = words(h, "cache_dirty")
    def cache_age: Rep[Array[Int]] = words(h, "cache_age")
    def cache_vals: Rep[Array[Int]] = words(h, "cache_vals")
    def timer: Rep[Int] = h.get("timer").asInstanceOf[Rep[Int]]
    def timer_=(v: Rep[Int]): Rep[Unit] = h.set("timer", v)
  }

  override def half(s: Pair, i: Int): Half =
    s.get(if (i == 0) { "a" } else { "b" }).asInstanceOf[Half]

  // Through [Op.Custom] and not a `#define`, because `CCodegen` emits a
  // prototype for a custom op and a macro would be expanded into it.
  // `koika_assert` is a macro, so the names below are wrapped in functions by
  // [main] rather than called directly.
  //
  // Both obligations prune as well as report, so both take the same assumption
  // afterwards. They assert under separate names because they are not the same
  // obligation. A clock that came apart is the question this tower asks. A
  // branch that came apart is the precondition it needs in order to ask it, and
  // a counterexample that cannot say which of them failed is a counterexample
  // nobody can read.
  private def claim(assertion: String, c: Rep[Boolean]): Unit = {
    unsafeReflect[Unit](Op.Custom(assertion, UNIT), c)
    unsafeReflect[Unit](Op.Custom("squared_assume", UNIT), c)
  }

  override def sameClock(x: Sided[Rep[Int]]): Unit = claim("squared_assert", x.a === x.b)
  override def sameWay(x: Sided[Rep[Boolean]]): Unit = claim("squared_diverged", x.a === x.b)

  override protected def choose(c: Rep[Boolean])(t: => Pair)(e: => Pair): Pair =
    __ifThenElse(c, t, e)

  private val declared = mutable.Set[Int]()

  // Slots asked for but not yet staged, and how to put the staging-time state
  // back the way the [call] that asked left it.
  private val pending = mutable.Queue[(Int, () => Unit)]()

  private def slotName(at: Int): String = s"slot_$at"

  // The name is the forward reference. `fun` stages a body the moment it is
  // handed one, so a call site that wants a slot the worklist has not reached
  // has nothing to apply but the name that slot's function will be given.
  private def declare(at: Int): Rep[State => State] = {
    if (declared.add(at)) { pending.enqueue((at, checkpoint())) }
    unsafeDeclare[State => State](slotName(at))
  }

  override protected def transfer(to: Int, s: Pair): Pair = declare(to)(s)

  // Slots come off this list and go back on it while it drains, which is the
  // point: every body is staged at the same depth, so how deep the program's
  // own call graph runs stops being a question about the JVM stack.
  private def drain(): Unit =
    while (pending.nonEmpty) {
      val (at, restore) = pending.dequeue()
      restore()
      fun(slotName(at)) { (p: Pair) => enter(at, p) }
    }

  override def snippet(s: Pair): Pair = {
    val entry = call(0, s)
    drain()
    finish(entry)
  }

  // The two states are built the way every model already builds them, one at
  // a time through its own `init`, and the product is two pointers at them.
  // Nothing is copied and nothing here knows which fields a given model
  // bothers to initialize.
  //
  // [enter] compares the clocks on the way into a slot, so the last
  // instruction's cost has not been looked at when the residue returns. The
  // comparison below is what looks at it.
  override def main(prover: Prover): String = {
    val paired = stateManifest.name
    s"""void squared_assert(bool c) { koika_assert(c, "timer drift"); }
       |void squared_diverged(bool c) { koika_assert(c, "control flow diverged"); }
       |void squared_assume(bool c) { koika_assume(c); }
       |
       |int main(int argc, char* argv[]) {
       |  struct $stateT s1, s2;
       |  init(&s1);
       |  init(&s2);
       |  $initialize_input
       |  $initialize_secret
       |  struct $paired p = { .a = &s1, .b = &s2 };
       |  struct $paired *p_ = snippet(&p);
       |  koika_assert(p_->a->timer==p_->b->timer, "timing leak");
       |  return 0;
       |}""".stripMargin
  }
}
