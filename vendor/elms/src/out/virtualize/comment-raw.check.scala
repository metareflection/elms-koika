def snippet(x0: Int): Int = {
  val x1 = x0 + x0
  //@ assert x1 >= 0;
  val x3 = println(x1)
  val x4 = 2
  val x5 = x1 * x4
  x5
}

