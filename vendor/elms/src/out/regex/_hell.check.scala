object _hell {
  def snippet(x0: String): Boolean = {
      val x81 = {var x29: Int = -1
      var x30: Boolean = false
      val x78 = while {
        val x31 = x30
        val x110 = !x31
        val x35 = if x110 then {
          val x33 = x29
          val x113 = x33 < (x0.length)
          x113
        } else {
          false
        }
        x35
      } do {
        val x37 = x29
        val x116 = x37 + 1
        val x38 = x29 = x116
        val x39 = x29
        val x117 = x39 < (x0.length)
        val x45 = if x117 then {
          val x43 = {val x121 = 'h' == (x0.charAt(x39))
          x121}
          x43
        } else {
          false
        }
        val x75 = if x45 then {
          val x124 = (x39 + 1) < (x0.length)
          val x51 = if x124 then {
            val x49 = {val x128 = 'e' == (x0.charAt((x39 + 1)))
            x128}
            x49
          } else {
            false
          }
          val x72 = if x51 then {
            val x131 = (x39 + 2) < (x0.length)
            val x57 = if x131 then {
              val x55 = {val x135 = 'l' == (x0.charAt((x39 + 2)))
              x135}
              x55
            } else {
              false
            }
            val x69 = if x57 then {
              val x138 = (x39 + 3) < (x0.length)
              val x63 = if x138 then {
                val x61 = {val x142 = 'l' == (x0.charAt((x39 + 3)))
                x142}
                x61
              } else {
                false
              }
              val x66 = if x63 then {
                true
              } else {
                false
              }
              x66
            } else {
              false
            }
            x69
          } else {
            false
          }
          x72
        } else {
          false
        }
        val x76 = x30 = x75
        ()
      }
      
      val x79 = x30
      x79}
      x81
    }


}