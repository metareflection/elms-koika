package elms.pipeline.eqsat

import foresight.eqsat.{EClassCall, EClassRef, ENode, MixedTree, Slot, Tree}

// None of foresight's types derive `CanEqual`, and ELMS compiles under
// `-language:strictEquality`. Same shape as `elms.core.instances`.
object instances {
  given CanEqual[EClassCall, EClassCall] = CanEqual.derived
  given CanEqual[EClassRef, EClassRef] = CanEqual.derived
  given CanEqual[Slot, Slot] = CanEqual.derived
  given [A]: CanEqual[ENode[A], ENode[A]] = CanEqual.derived
  given [A]: CanEqual[Tree[A], Tree[A]] = CanEqual.derived
  given [A, B]: CanEqual[MixedTree[A, B], MixedTree[A, B]] = CanEqual.derived
}
