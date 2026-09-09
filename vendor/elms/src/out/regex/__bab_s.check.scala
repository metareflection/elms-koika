object __bab_s {
  def snippet(x0: String): Boolean = {
      val x105 = {val x107 = 0 < (x0.length)
      val x6 = if x107 then {
        val x4 = {val x111 = 'a' == (x0.charAt(0))
        x111}
        x4
      } else {
        false
      }
      val x39 = if x6 then {
        var x7: Int = 1
        val x8 = x7
        var x9: Boolean = true
        var x10: Boolean = false
        val x31 = while {
          val x11 = x10
          val x119 = !x11
          val x15 = if x119 then {
            val x13 = x9
            val x122 = !x13
            x122
          } else {
            false
          }
          val x19 = if x15 then {
            val x17 = x7
            val x125 = x17 < (x0.length)
            x125
          } else {
            false
          }
          x19
        } do {
          val x21 = x7
          val x24 = {val x128 = 'b' == (x0.charAt(x21))
          x128}
          val x130 = !x24
          val x25 = x10 = x130
          val x26 = x7
          val x131 = x26 + 1
          val x27 = x7 = x131
          val x28 = x7
          val x29 = x9 = true
          ()
        }
        
        val x32 = x10
        val x135 = !x32
        val x36 = if x135 then {
          val x34 = x9
          x34
        } else {
          false
        }
        x36
      } else {
        false
      }
      x39}
      x105
    }


}