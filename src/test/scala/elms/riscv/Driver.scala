package elms.koika.test.riscv

import elms.prelude.*
import elms.prelude.given

import elms.codegen.{CCodegen, Config}
import elms.koika.test.common.GenericKoikaDriver

// What RISC-V needs from the driver that NanoRisc does not. [M] stays open
// because the FaCT ports spill and the demos do not, so memory is the one
// length these two do not agree on.
trait RiscVDriver[M <: Int: ValueOf] extends GenericKoikaDriver[32, M, 10] with Exec {
  // `CCodegen` names generated C variables `x0`, `x1`, and so does RISC-V name
  // its registers. Nothing breaks, but anyone reading a snapshot would read
  // `x11[0] = 20` as a register write when it is an array of them.
  override val codegen = CCodegen(Config.cDefault.copy(varPrefix = "v"))

  // Two changes from the generic version. `regs[0]` here is x0 and has to stay
  // zero, so the attacker-controlled value lands in a0, where an argument would
  // actually arrive. And the bound is in bytes: the NanoRisc `bounded(0, 20)`
  // is a word index that reaches exactly the first secret word, and the
  // byte-addressed equivalent of that is `4 * secret_offset`.
  override lazy val initialize_input: String =
    s"""
       |  int x = bounded(0, $secret_offset_bytes);
       |  s1.regs[10] = x;
       |  s2.regs[10] = x;""".stripMargin

  // `SECRET_OFFSET` stays a word index, because `initialize_secret` indexes
  // `mem` directly. The demos take bytes.
  val secret_offset_bytes: Int = 4 * secret_offset
  val password_size_bytes: Int = 16

  // The demos live as object files under `src/test/asm/riscv`, assembled by the
  // `build` script beside them. The two byte counts above reach them through
  // that script's `--defsym` flags and not from here, since a real assembler
  // cannot hear Scala; [RiscVElfTests] is what compares the two back.
  def demo(name: String): Vector[RiscV.Instr] = elf.Elf.load(s"src/test/asm/riscv/$name.o").prog
}
