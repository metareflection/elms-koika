package elms.koika.test.riscv.elf

import elms.koika.test.riscv.RiscV

// Who a global belongs to. Three because the driver has three behaviours: a
// secret is written independently into the two states, an attacker's input
// identically into both, and public data comes straight out of the image.
enum Taint derives CanEqual { case Secret, Attacker, Public }

// A global in the data image: where it starts, how big it is, and whose it is.
case class Datum(addr: Int, size: Int, taint: Taint) derives CanEqual

// [data] is word-indexed, so `data(k)` is `mem[k]`. [Datum.addr] and [consts]
// are byte counts; [entries] and [entry] are indices into [prog].
case class Image(
    prog: Vector[RiscV.Instr],
    data: Vector[Int],
    globals: Map[String, Datum],
    entries: Map[String, Int],
    consts: Map[String, Int],
    entry: Int
)

// Something in the object the tower cannot represent, with enough of a locus to
// find it by eye. There is no source line to point at, so the locus is the
// section and the byte offset within it.
//
// These accumulate rather than throw, because the first question anyone asks of
// a new object is which parts of it are out of scope, and that wants the whole
// list at once.
case class ElfError(where: String, msg: String) derives CanEqual {
  override def toString: String = s"$where: $msg"
}

class ElfException(val errors: List[ElfError]) extends RuntimeException(errors.mkString("\n"))
