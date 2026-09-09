object _hel_s_e {
  def snippet(x0: String): Boolean = {
      val x105 = {var x41: Int = -1
      var x42: Boolean = false
      val x102 = while {
        val x43 = x42
        val x144 = !x43
        val x47 = if x144 then {
          val x45 = x41
          val x147 = x45 < (x0.length)
          x147
        } else {
          false
        }
        x47
      } do {
        val x49 = x41
        val x150 = x49 + 1
        val x50 = x41 = x150
        val x51 = x41
        val x151 = x51 < (x0.length)
        val x57 = if x151 then {
          val x55 = {val x155 = 'h' == (x0.charAt(x51))
          x155}
          x55
        } else {
          false
        }
        val x99 = if x57 then {
          val x158 = (x51 + 1) < (x0.length)
          val x63 = if x158 then {
            val x61 = {val x162 = 'e' == (x0.charAt((x51 + 1)))
            x162}
            x61
          } else {
            false
          }
          val x96 = if x63 then {
            val x165 = x51 + 2
            var x64: Int = x165
            val x65 = x64
            val x167 = x65 == (x0.length)
            var x66: Boolean = x167
            var x67: Boolean = false
            val x88 = while {
              val x68 = x67
              val x169 = !x68
              val x72 = if x169 then {
                val x70 = x66
                val x172 = !x70
                x172
              } else {
                false
              }
              val x76 = if x72 then {
                val x74 = x64
                val x175 = x74 < (x0.length)
                x175
              } else {
                false
              }
              x76
            } do {
              val x78 = x64
              val x81 = {val x179 = 'l' == (x0.charAt(x78))
              x179}
              val x181 = !x81
              val x82 = x67 = x181
              val x83 = x64
              val x182 = x83 + 1
              val x84 = x64 = x182
              val x85 = x64
              val x184 = x85 == (x0.length)
              val x86 = x66 = x184
              ()
            }
            
            val x89 = x67
            val x187 = !x89
            val x93 = if x187 then {
              val x91 = x66
              x91
            } else {
              false
            }
            x93
          } else {
            false
          }
          x96
        } else {
          false
        }
        val x100 = x42 = x99
        ()
      }
      
      val x103 = x42
      x103}
      x105
    }


}