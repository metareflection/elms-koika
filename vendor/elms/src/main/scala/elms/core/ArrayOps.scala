package elms.core

import scala.reflect.ClassTag

import elms.core.Op._

trait ArrayOps extends PrimitiveOps with poly.ArrayOps {
  def newArray[A: Typable](i: Rep[Int]): Rep[Array[A]] =
    unsafeReflect(ArrayNew(summon[Typable[A]].identity), i)

  // A read-only template plus one copy, rather than a store per element. The
  // result has to be fresh, mutable and able to outlive the block it was built
  // in, and that combination rules out handing back the template (shared),
  // and a compound literal (block scoped). Three lines of C for three
  // elements, and three for a hundred.
  def initFrom[A: Typable: AsStaticData: ClassTag](entries: Seq[A]): Rep[Array[A]] = {
    val src = staticData(entries.toArray)
    val dst = newArray[A](unit(entries.length))
    val _ = arrayCopy(dst, src, unit(entries.length))
    dst
  }

  def arrayCopy[A](dst: Rep[Array[A]], src: Rep[Array[A]], len: Rep[Int]): Rep[Unit] =
    unsafeReflect(ArrayCopy, dst, src, len)

  extension [A](arr: Rep[Array[A]])
    def get(i: Rep[Int]): Rep[A] = unsafeReflect(ArrayGet, arr, i)
    def set(i: Rep[Int], x: Rep[A]): Rep[Unit] = unsafeReflect(ArraySet, arr, i, x)

  given arrayLength[A]: RepLength[Array[A]] with
    def run(arr: Rep[Array[A]]): Rep[Int] = unsafeReflect(ArrayLength, arr)
}
