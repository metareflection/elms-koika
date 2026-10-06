val x1 = Array[Int](3,1,4,1,5)
def snippet(x0: Int): Int = {
  val x2 = 5
  val x3 = new Array[Int](x2)
  val x4 = 5
  val x5 = Array.copy(x1, 0, x3, 0, x4)
  val x6 = x3(x0)
  x6
}

