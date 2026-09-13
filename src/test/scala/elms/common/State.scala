package elms.koika.test.common

import elms.prelude.*
import elms.prelude.given
import elms.core.StructManifest

// [R] registers, [M] words of memory, [C] cache lines, as type parameters
// rather than fields. A `FixedArray`'s length is what decides whether the C
// backend gives a member inline storage or a pointer, and only the inline form
// is something CBMC can reason about: `main` declares its two states by value.
case class StateT[R <: Int, M <: Int, C <: Int](
    regs: FixedArray[R, Int],
    mem: FixedArray[M, Int],
    saved_regs: FixedArray[R, Int],
    cache_keys: FixedArray[C, Int],
    cache_vals: FixedArray[C, Int],
    timer: Int
)

object StateT {
  // Spelled out rather than `derives`, because the derivation summons a
  // `Typable` per field and `Typable[FixedArray[R, Int]]` wants a `ValueOf[R]`
  // that a `derives` clause has no way to ask for.
  given manifest[R <: Int: ValueOf, M <: Int: ValueOf, C <: Int: ValueOf]
      : StructManifest[StateT[R, M, C]] = StructManifest.derived
}

// The fields, against whatever [StateT] the driver fixed. [State] is abstract
// so that the three lengths stop at [GenericKoikaDriver] rather than being
// threaded through every trait that touches a register.
trait StateTOps extends DslOps {
  type State
  given stateManifest: StructManifest[State]

  extension (st: Rep[State])
    def regs: Rep[Array[Int]] = st.get("regs").asInstanceOf[Rep[Array[Int]]]
    def mem: Rep[Array[Int]] = st.get("mem").asInstanceOf[Rep[Array[Int]]]
    def saved_regs: Rep[Array[Int]] = st.get("saved_regs").asInstanceOf[Rep[Array[Int]]]
    def cache_keys: Rep[Array[Int]] = st.get("cache_keys").asInstanceOf[Rep[Array[Int]]]
    def cache_vals: Rep[Array[Int]] = st.get("cache_vals").asInstanceOf[Rep[Array[Int]]]
    def timer: Rep[Int] = st.get("timer").asInstanceOf[Rep[Int]]

    // No setter for the arrays. They are inline storage now, and C has no
    // assignment operator for an array, so the backend refuses the whole-member
    // write. Indexing into one is unaffected.
    def timer_=(v: Rep[Int]): Rep[Unit] = st.set("timer", v)
}
