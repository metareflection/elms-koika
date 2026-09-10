package elms.core

import scala.annotation.targetName

import elms.core.Op._

trait BooleanOps extends Base with poly.BooleanOps {
  extension (lhs: Rep[Boolean])
    def &&(rhs: => Rep[Boolean]): Rep[Boolean] = unsafeReflect(And, region(lhs), region(rhs))
    def ||(rhs: => Rep[Boolean]): Rep[Boolean] = unsafeReflect(Or, region(lhs), region(rhs))
    def unary_! = (unsafeReflect(Not, lhs): Rep[Boolean])
    // `Rep` erases, so these would collide with `IntegerOps`'s operators of the
    // same name on their JVM signature. The target names keep them apart.
    @targetName("boolAnd")
    def &(rhs: Rep[Boolean]): Rep[Boolean] = unsafeReflect(StrictAnd, lhs, rhs)
    @targetName("boolOr")
    def |(rhs: Rep[Boolean]): Rep[Boolean] = unsafeReflect(StrictOr, lhs, rhs)
    @targetName("boolXor")
    def ^(rhs: Rep[Boolean]): Rep[Boolean] = unsafeReflect(Xor, lhs, rhs)
}
