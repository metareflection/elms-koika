object _ab {
  def snippet(x0: String): Boolean = {
      val x45 = {var x11: Int = -1
      var x12: Boolean = false
      val x42 = while {
        val x13 = x12
        val x58 = !x13
        val x17 = if x58 then {
          val x15 = x11
          val x61 = x15 < (x0.length)
          x61
        } else {
          false
        }
        x17
      } do {
        val x19 = x11
        val x64 = x19 + 1
        val x20 = x11 = x64
        val x21 = x11
        val x65 = x21 < (x0.length)
        val x27 = if x65 then {
          val x25 = {val x69 = 'a' == (x0.charAt(x21))
          x69}
          x25
        } else {
          false
        }
        val x39 = if x27 then {
          val x72 = (x21 + 1) < (x0.length)
          val x33 = if x72 then {
            val x31 = {val x76 = 'b' == (x0.charAt((x21 + 1)))
            x76}
            x31
          } else {
            false
          }
          val x36 = if x33 then {
            true
          } else {
            false
          }
          x36
        } else {
          false
        }
        val x40 = x12 = x39
        ()
      }
      
      val x43 = x12
      x43}
      x45
    }


}