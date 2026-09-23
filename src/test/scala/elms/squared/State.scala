package elms.koika.test.squared

import elms.prelude.given
import elms.core.StructManifest

import elms.koika.test.common.StateT

// Two [StateT]s, by pointer. `CCodegen` renders a struct member as
// `struct StateT *` and reaches every member with `->`, so `p->a->regs` is
// what the backend already emits for a chain of two of these, and the field
// names on the far side never have to change.
//
// By pointer and not by value, so `main` can hand over the two states each
// model's own `init` has already filled in.
case class StateT2[R <: Int, M <: Int, C <: Int, T <: Int](
    a: StateT[R, M, C, T],
    b: StateT[R, M, C, T]
)

object StateT2 {
  // Spelled out rather than `derives`, for the reason [StateT.manifest] is:
  // the derivation summons a `Typable` per field, and the one for a [StateT]
  // wants four `ValueOf`s that a `derives` clause has no way to ask for.
  given manifest[R <: Int: ValueOf, M <: Int: ValueOf, C <: Int: ValueOf, T <: Int: ValueOf]
      : StructManifest[StateT2[R, M, C, T]] = StructManifest.derived
}
