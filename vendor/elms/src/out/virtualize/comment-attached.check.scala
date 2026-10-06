def snippet(x0: Int): Unit = {
  val x1 = x0 + x0
  //@ free-standing, above the guard;
  val x3 = 1
  val x4 = x1 == x3
  //@ attached, below it;
  //@ bracket
  val x7 = if x4 then {
    val x5 = println(x1)
    x5
  } else {
    val x6 = println(x0)
    x6
  }
  //end @ bracket
  x7
}

