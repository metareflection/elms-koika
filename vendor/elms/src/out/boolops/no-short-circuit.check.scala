def snippet(x0: Unit): Boolean = {
  val x1 = "a"
  val x2 = println(x1)
  val x3 = false
  val x4 = "b"
  val x5 = println(x4)
  val x6 = true
  val x7 = x3 & x6
  val x8 = "c"
  val x9 = println(x8)
  val x10 = false
  val x11 = "d"
  val x12 = println(x11)
  val x13 = true
  val x14 = x10 ^ x13
  val x15 = x7 | x14
  x15
}

