package elms.core

// An array whose length is known at compile time, which is the only way a
// struct member gets inline storage instead of a pointer.
//
// Opaque so that `Typable[FixedArray[16, Int]]` is a different summon from
// `Typable[Array[Int]]`. A transparent alias would make the two givens
// ambiguous and there would be no way to write the length down. It lives in its
// own file because opacity does not apply inside the scope that defines it, and
// `typFixedArray` has to see the abstract form to register against it.
opaque type FixedArray[N <: Int, A] = Array[A]
