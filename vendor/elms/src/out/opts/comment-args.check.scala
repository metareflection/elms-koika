def snippet(x0: Int): Int = {
  val x5 = (0 until (x0 * 2)).start
  val x6 = (0 until (x0 * 2)).end
  //@ loop invariant 0 <= i <= (x0 * 2);
  val x4 = for (x1 <- x5 until x6) {
    //@ assert x1 < (x0 * 2);
    val x2 = println(x1)
    x2
  }
  
  val x9 = x0 * 2
  x9
}

