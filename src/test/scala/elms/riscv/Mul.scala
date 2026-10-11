package elms.koika.test.riscv

import elms.prelude.given

import elms.core.poly.{IntegerOps, PrimitiveOps}

import RiscV.MulOp

// RV32M's four multiplies, over whatever the value domain turns out to be.
//
// Shared rather than transcribed into each tower the way [Exec]'s `alu` is.
// The three high-half rules are a carry chain and the single-run tower has no
// test that runs one, so two copies would mean a dropped carry that only one
// of them has.
trait Multiplier extends IntegerOps with PrimitiveOps {
  // The high 32 bits of an unsigned 32x32 product, out of four 16-bit partial
  // products, because there is no `Rep[Long]` to ask for them directly.
  //
  // Each partial fits in 32 bits unsigned and so may read negative as an
  // `Int`; `>>>` is what makes that a split rather than a sign extension.
  // [mid] carries what the low halves of the two middle partials and the high
  // half of the lowest one contribute above bit 31.
  private def mulhu(a: Rep[Int], b: Rep[Int]): Rep[Int] = {
    val a0 = a & unit(0xffff)
    val a1 = a >>> unit(16)
    val b0 = b & unit(0xffff)
    val b1 = b >>> unit(16)
    val lo = a0 * b0
    val m1 = a0 * b1
    val m2 = a1 * b0
    val mid = (lo >>> unit(16)) + (m1 & unit(0xffff)) + (m2 & unit(0xffff))
    a1 * b1 + (m1 >>> unit(16)) + (m2 >>> unit(16)) + (mid >>> unit(16))
  }

  // A negative operand is its unsigned reading minus 2^32, and the 2^32 term
  // lands exactly one word up, so each signed operand costs one subtraction of
  // the other. `x >> 31` is the mask that says which. Written as a conditional
  // the way `alu`'s `Slt` is, each would be a path the checker splits, and a
  // program that multiplies in a loop does it tens of times.
  protected def mulOp(op: MulOp, a: Rep[Int], b: Rep[Int]): Rep[Int] = op match {
    case MulOp.Mul    => a * b
    case MulOp.Mulhu  => mulhu(a, b)
    case MulOp.Mulhsu => mulhu(a, b) - ((a >> unit(31)) & b)
    case MulOp.Mulh   => mulhu(a, b) - ((a >> unit(31)) & b) - ((b >> unit(31)) & a)
  }
}
