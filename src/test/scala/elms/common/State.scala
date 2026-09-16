package elms.koika.test.common

import elms.prelude.*
import elms.prelude.given
import elms.core.StructManifest

// [R] registers, [M] words of memory, [C] words of cache data and [T] cache
// entries to describe them, as type parameters rather than fields. A
// `FixedArray`'s length is what decides whether the C backend gives a member
// inline storage or a pointer, and only the inline form is something CBMC can
// reason about: `main` declares its two states by value.
//
// [C] and [T] count every level at once. A hierarchy lays its levels out at
// static offsets inside one pair of arrays rather than taking a type parameter
// apiece, which is what keeps this list from growing by four per level; see
// [Geometry].
case class StateT[R <: Int, M <: Int, C <: Int, T <: Int](
    regs: FixedArray[R, Int],
    mem: FixedArray[M, Int],
    saved_regs: FixedArray[R, Int],
    reg_ready: FixedArray[R, Int],
    cache_tags: FixedArray[T, Int],
    cache_dirty: FixedArray[T, Int],
    cache_age: FixedArray[T, Int],
    cache_vals: FixedArray[C, Int],
    timer: Int
)

object StateT {
  // Spelled out rather than `derives`, because the derivation summons a
  // `Typable` per field and `Typable[FixedArray[R, Int]]` wants a `ValueOf[R]`
  // that a `derives` clause has no way to ask for.
  given manifest[R <: Int: ValueOf, M <: Int: ValueOf, C <: Int: ValueOf, T <: Int: ValueOf]
      : StructManifest[StateT[R, M, C, T]] = StructManifest.derived
}

// The fields, against whatever [StateT] the driver fixed. [State] is abstract
// so that the four lengths stop at [GenericKoikaDriver] rather than being
// threaded through every trait that touches a register.
trait StateTOps extends DslOps {
  type State
  given stateManifest: StructManifest[State]

  extension (st: Rep[State])
    def regs: Rep[Array[Int]] = st.get("regs").asInstanceOf[Rep[Array[Int]]]
    def mem: Rep[Array[Int]] = st.get("mem").asInstanceOf[Rep[Array[Int]]]
    def saved_regs: Rep[Array[Int]] = st.get("saved_regs").asInstanceOf[Rep[Array[Int]]]

    // The cycle each register's value lands, for [NonBlocking]. Indexed by the
    // same static register number [regs] is, so the subscript is a constant and
    // none of what a set-indexed cache costs a checker applies here.
    def reg_ready: Rep[Array[Int]] = st.get("reg_ready").asInstanceOf[Rep[Array[Int]]]

    // One entry per line frame, in [Geometry.entries] order. The tag is the
    // whole line number rather than its high bits, which costs nothing in a
    // model and buys a valid bit for free: -1 is a line no address can name, so
    // an empty frame is one the tag comparison never matches. That is one fewer
    // symbolic array read per way per probe, on the hottest path there is.
    def cache_tags: Rep[Array[Int]] = st.get("cache_tags").asInstanceOf[Rep[Array[Int]]]
    def cache_dirty: Rep[Array[Int]] = st.get("cache_dirty").asInstanceOf[Rep[Array[Int]]]
    def cache_age: Rep[Array[Int]] = st.get("cache_age").asInstanceOf[Rep[Array[Int]]]

    // [Geometry.lineWords] words per entry, so entry `e` owns
    // `[e * lineWords, (e + 1) * lineWords)`.
    def cache_vals: Rep[Array[Int]] = st.get("cache_vals").asInstanceOf[Rep[Array[Int]]]

    def timer: Rep[Int] = st.get("timer").asInstanceOf[Rep[Int]]

    // No setter for the arrays. They are inline storage now, and C has no
    // assignment operator for an array, so the backend refuses the whole-member
    // write. Indexing into one is unaffected.
    def timer_=(v: Rep[Int]): Rep[Unit] = st.set("timer", v)
}
