package elms.core.poly

import scala.reflect.ClassTag

import elms.core.{Typable, AsStaticData}

trait ArrayOps extends PrimitiveOps {
  def newArray[A: Typable](i: Rep[Int]): Rep[Array[A]]

  // `ClassTag` is what `Seq.toArray` wants and nothing more: the elements go
  // into an `Array[A]` before they can be static data.
  def initFrom[A: Typable: AsStaticData: ClassTag](entries: Seq[A]): Rep[Array[A]]

  // `len` elements from the front of `src` to the front of `dst`. Neither
  // length is checked, here or anywhere.
  def arrayCopy[A](dst: Rep[Array[A]], src: Rep[Array[A]], len: Rep[Int]): Rep[Unit]

  extension [A](arr: Rep[Array[A]])
    def get(i: Rep[Int]): Rep[A]
    def set(i: Rep[Int], x: Rep[A]): Rep[Unit]
    def update(i: Rep[Int], x: Rep[A]): Rep[Unit] = arr.set(i, x)

  given [A]: RepApply1[Array[A], Int, A] with
    def run(arr: Rep[Array[A]], i: Rep[Int]): Rep[A] = arr.get(i)

  given arrayLength[A]: RepLength[Array[A]]
}
