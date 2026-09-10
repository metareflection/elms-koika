def snippet(x0: Int): Int = {
  val x1 = 240
  val x2 = x0 & x1
  val x3 = 15
  val x4 = x0 ^ x3
  val x5 = x2 | x4
  val x6 = ~x0
  val x7 = x5 + x6
  val x8 = 3
  val x9 = x0 << x8
  val x10 = x7 + x9
  val x11 = 2
  val x12 = x0 >> x11
  val x13 = x10 + x12
  val x14 = 4
  val x15 = x0 >>> x14
  val x16 = x13 + x15
  x16
}

