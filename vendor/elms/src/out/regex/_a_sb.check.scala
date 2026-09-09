object _a_sb {
  def snippet(x0: String): Boolean = {
      val x84 = {var x20: Int = -1
      var x21: Boolean = false
      val x81 = while {
        val x22 = x21
        val x105 = !x22
        val x26 = if x105 then {
          val x24 = x20
          val x108 = x24 < (x0.length)
          x108
        } else {
          false
        }
        x26
      } do {
        val x28 = x20
        val x111 = x28 + 1
        val x29 = x20 = x111
        val x30 = x20
        var x31: Int = x30
        val x32 = x31
        val x114 = x32 < (x0.length)
        val x38 = if x114 then {
          val x36 = {val x118 = 'b' == (x0.charAt(x32))
          x118}
          x36
        } else {
          false
        }
        val x41 = if x38 then {
          true
        } else {
          false
        }
        var x42: Boolean = x41
        var x43: Boolean = false
        val x73 = while {
          val x44 = x43
          val x124 = !x44
          val x48 = if x124 then {
            val x46 = x42
            val x127 = !x46
            x127
          } else {
            false
          }
          val x52 = if x48 then {
            val x50 = x31
            val x130 = x50 < (x0.length)
            x130
          } else {
            false
          }
          x52
        } do {
          val x54 = x31
          val x57 = {val x134 = 'a' == (x0.charAt(x54))
          x134}
          val x136 = !x57
          val x58 = x43 = x136
          val x59 = x31
          val x137 = x59 + 1
          val x60 = x31 = x137
          val x61 = x31
          val x138 = x61 < (x0.length)
          val x67 = if x138 then {
            val x65 = {val x142 = 'b' == (x0.charAt(x61))
            x142}
            x65
          } else {
            false
          }
          val x70 = if x67 then {
            true
          } else {
            false
          }
          val x71 = x42 = x70
          ()
        }
        
        val x74 = x43
        val x150 = !x74
        val x78 = if x150 then {
          val x76 = x42
          x76
        } else {
          false
        }
        val x79 = x21 = x78
        ()
      }
      
      val x82 = x21
      x82}
      x84
    }


}