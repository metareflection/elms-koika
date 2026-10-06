package elms.core.poly

import scala.annotation.targetName

trait CharOps extends HasRep {
  extension (lhs: Rep[Char])
    // `Rep` erases, so these would collide with `IntegerOps`'s operators of the
    // same name on their JVM signature. The target names keep them apart.
    @targetName("charLt")
    def <(rhs: Rep[Char]): Rep[Boolean]
    @targetName("charGt")
    def >(rhs: Rep[Char]): Rep[Boolean]
    @targetName("charLe")
    def <=(rhs: Rep[Char]): Rep[Boolean]
    @targetName("charGe")
    def >=(rhs: Rep[Char]): Rep[Boolean]
    def toInt: Rep[Int]
}
