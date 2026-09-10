def snippet(x0: Int): Boolean = {
  val x1 = 0
  val x2 = x0 > x1
  val x3 = 1
  val x4 = x0 & x3
  val x5 = 0
  val x6 = x4 == x5
  val x7 = x2 & x6
  val x8 = !x6
  val x9 = x2 ^ x8
  val x10 = x7 | x9
  x10
}

