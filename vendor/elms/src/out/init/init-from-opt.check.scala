val x1 = Array[Int](3,1,4,1,5)
def snippet(x0: Int): Int = {
  val x2 = new Array[Int](5)
  val x3 = Array.copy(x1, 0, x2, 0, 5)
  val x4 = x2(x0)
  x4
}

