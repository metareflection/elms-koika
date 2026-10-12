package elms.koika.test.riscv

import elms.prelude.*
import elms.prelude.given

import elms.codegen.{CCodegen, Config}
import elms.core.StructManifest

import elms.koika.test.common.{GlobalHistory, KoikaDriver, StateG, StateT}
import elms.koika.test.squared.{Flat, SquaredKoikaDriver, StateT2}

// What RISC-V needs from the driver that NanoRisc does not. [M] stays open
// because the FaCT ports spill and the demos do not, so memory is the one
// length these two do not agree on.
//
// [S] is [KoikaDriver]'s and nothing here reads it. The C around a residue is
// the same whether a slot is handed one state or two, which is what lets the
// squared tower reuse every line of it.
trait RiscVShell[M <: Int: ValueOf, S: StructManifest] extends KoikaDriver[32, M, 24, 12, S] {
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

// What a `ret` asserts, declared only where a [RiscV.Instr.Ret] has somewhere
// to return through. A program with no call in it never reaches the assertion,
// and declaring the function anyway would move every snapshot in the tree for
// a line nothing calls.
//
// Both towers emit the same call, so both declare it from here.
def retAssert(prog: Vector[RiscV.Instr]): String =
  if (prog.exists { case RiscV.Instr.Call(_, _) => true; case _ => false }) {
    """void ret_assert(bool c) { koika_assert(c, "return address"); }
      |
      |""".stripMargin
  } else { "" }

// The same shell, over a state that carries a pattern history table.
//
// [P] is the table's length and is a type parameter for the reason the other
// four are: a `FixedArray`'s length decides whether the C backend gives the
// member inline storage, and only the inline form is something CBMC can read.
trait RiscVGhrDriver[M <: Int: ValueOf, P <: Int: ValueOf]
    extends RiscVShell[M, StateG[32, M, 24, 12, P]]
    with Exec
    with GlobalHistory {
  override def helpers: String = retAssert(prog)
  // The struct the hand-written C around the residue declares. [StateG] and
  // not [StateT], because the generator names it after the case class and
  // `init` dereferences one.
  override val stateT: String = "StateG"

  override def phtEntries: Int = valueOf[P]

  // Three numbers that have to agree and nothing else would notice them
  // disagreeing: the register's width, how many branches the program has, and
  // how long the table in the struct is. The first two decide how many entries
  // get asked for and the third is laid out by [P], so a mismatch is an index
  // past the end of a member rather than a failure.
  //
  // Lazy and forced from [defines] rather than run in the constructor, because
  // [historyBits] is overridable and a subclass's override is not initialized
  // while this class's body is still running. Same reason [KoikaDriver.checked]
  // is.
  private lazy val checkedHistory: Unit = {
    require(historyBits >= 1 && historyBits <= 16, s"historyBits is $historyBits, not in [1, 16]")
    val branches = prog.count { case RiscV.Instr.Branch(_, _, _, _) => true; case _ => false }
    val wanted = branches * (1 << historyBits)
    require(
      wanted <= phtEntries,
      s"$branches branch(es) at $historyBits history bits want $wanted pht entries" +
        s" and the state has $phtEntries"
    )
  }

  override def defines: Seq[(String, Int)] = {
    checkedHistory
    super.defines ++ Seq("PHT_ENTRIES" -> phtEntries, "HISTORY_BITS" -> historyBits)
  }
  // `init` loops over the table too, and a bound that falls short of it leaves
  // two states disagreeing on whatever was in the entries it never wrote.
  override def unwind: Int = math.max(super.unwind, phtEntries + 1)
}

trait RiscVDriver[M <: Int: ValueOf] extends RiscVShell[M, StateT[32, M, 24, 12]] with Exec {
  override def helpers: String = retAssert(prog)
}

// The same demos, run in step. Everything above is unchanged; what differs is
// that a slot takes both states and the clocks are compared on the way into
// each one.
//
// [Flat] here is what `Exec extends Direct` is on the line above: the memory
// model a demo gets when it asks for none, and the one a `with Cached` at the
// test site displaces.
trait SquaredRiscVDriver[M <: Int: ValueOf]
    extends SquaredKoikaDriver[32, M, 24, 12]
    with RiscVShell[M, StateT2[32, M, 24, 12]]
    with Flat {
  override def helpers: String = retAssert(prog)
}
