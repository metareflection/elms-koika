object __bab_s_e {
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
        val x117 = x8 == (x0.length)
        var x9: Boolean = x117
        var x10: Boolean = false
        val x31 = while {
          val x11 = x10
          val x120 = !x11
          val x15 = if x120 then {
            val x13 = x9
            val x123 = !x13
            x123
          } else {
            false
          }
          val x19 = if x15 then {
            val x17 = x7
            val x126 = x17 < (x0.length)
            x126
          } else {
            false
          }
          x19
        } do {
          val x21 = x7
          val x24 = {val x129 = 'b' == (x0.charAt(x21))
          x129}
          val x131 = !x24
          val x25 = x10 = x131
          val x26 = x7
          val x132 = x26 + 1
          val x27 = x7 = x132
          val x28 = x7
          val x134 = x28 == (x0.length)
          val x29 = x9 = x134
          ()
        }
        
        val x32 = x10
        val x137 = !x32
        val x36 = if x137 then {
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