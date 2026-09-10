package elms.core.poly

import scala.annotation.targetName

trait BooleanOps extends HasRep {
  extension (lhs: Rep[Boolean])
    def &&(rhs: => Rep[Boolean]): Rep[Boolean]
    def ||(rhs: => Rep[Boolean]): Rep[Boolean]
    def unary_! : Rep[Boolean]
    // `Rep` erases, so these would collide with `IntegerOps`'s operators of the
    // same name on their JVM signature. The target names keep them apart.
    @targetName("boolAnd")
    def &(rhs: Rep[Boolean]): Rep[Boolean]
    @targetName("boolOr")
    def |(rhs: Rep[Boolean]): Rep[Boolean]
    @targetName("boolXor")
    def ^(rhs: Rep[Boolean]): Rep[Boolean]
}
