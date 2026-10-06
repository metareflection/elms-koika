def snippet(x0: Int): Unit = {
  val x1 = 0
  val x2 = x1 until x0
  val x4 = x2.start
  val x5 = x2.end
  //@ loop invariant 0 <= i <= x0;
  val x7 = for (x3 <- x4 until x5) {
    val x6 = println(x3)
    x6
  }
  
  val x8 = ()
  x8
}

