package elms.koika.test.squared

import elms.prelude.given
import elms.core.poly.{ArrayOps, BooleanOps, EqualityOps, HasRep, IntegerOps, PrimitiveOps}

// One run's machine, over whatever the value domain turns out to be.
//
// Nothing below this line ever sees a pair. [Squared] is what runs a rule
// twice, so every rule is written as if there were one execution, and `Rep` is
// an ordinary `Int` when the interpreter runs and an IR node when it stages.
// The two instantiations are [Run] and [Stage], and they share every line of
// the semantics.
//
// The field names are [elms.koika.test.common.StateT]'s, so the memory model
// here and the one in `common/Tower.scala` diff against each other.
trait Machine
    extends HasRep
    with PrimitiveOps
    with IntegerOps
    with BooleanOps
    with EqualityOps
    with ArrayOps {
  type Half

  extension (h: Half)
    def regs: Rep[Array[Int]]
    def mem: Rep[Array[Int]]
    def cache_tags: Rep[Array[Int]]
    def cache_dirty: Rep[Array[Int]]
    def cache_age: Rep[Array[Int]]
    def cache_vals: Rep[Array[Int]]
    def timer: Rep[Int]
    def timer_=(v: Rep[Int]): Rep[Unit]

  def get_reg(h: Half, i: Rep[Int]): Rep[Int]
  def set_reg(h: Half, i: Rep[Int], v: Rep[Int]): Rep[Unit]

  // Word-indexed, not byte-addressed. [Cached] splits whatever comes through
  // here into a line and a word within it, so the byte offset is gone by the
  // time the cache sees an address.
  def get_mem(h: Half, i: Rep[Int]): Rep[Int]
  def set_mem(h: Half, i: Rep[Int], v: Rep[Int]): Rep[Unit]

  def tick(h: Half): Rep[Unit] = h.timer = h.timer + unit(1)

  // Cycles the clock pays for, now. There is no [Common.defer] here, because
  // nothing in this tower lets the instructions behind a load keep going, and
  // a name with one meaning is not a distinction.
  def spend(h: Half, lat: Rep[Int]): Rep[Unit] = h.timer = h.timer + lat
}
