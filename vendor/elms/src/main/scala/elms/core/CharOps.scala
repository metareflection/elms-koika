package elms.core

import scala.annotation.targetName

import elms.core.Op._

// What this buys over `EqualityOps` alone is a character class as two
// comparisons rather than a fold of equalities, which is `'0' <= c && c <= '9'`
// against ten `===`. `Lt` and friends record no operand type and both backends
// render them as the bare operator, so the four methods below are the whole
// change on this side; `CCodegen` handles `char`'s signedness separately.
trait CharOps extends Base with poly.CharOps {
  extension (lhs: Rep[Char])
    @targetName("charLt")
    def <(rhs: Rep[Char]): Rep[Boolean] = unsafeReflect(Lt, lhs, rhs)
    @targetName("charGt")
    def >(rhs: Rep[Char]): Rep[Boolean] = unsafeReflect(Gt, lhs, rhs)
    @targetName("charLe")
    def <=(rhs: Rep[Char]): Rep[Boolean] = unsafeReflect(Le, lhs, rhs)
    @targetName("charGe")
    def >=(rhs: Rep[Char]): Rep[Boolean] = unsafeReflect(Ge, lhs, rhs)
    def toInt: Rep[Int] = unsafeReflect(CharToInt, lhs)
}
