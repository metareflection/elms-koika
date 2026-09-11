package elms.koika.test.riscv

import org.scalatest.funsuite.AnyFunSuite

// Only for the `Typable` instance that lets a [RiscVDriver] be named, which is
// where the assembler constants are compared against. Nothing here stages.
import elms.prelude.given

import RiscV.*
import elf.{Datum, Decode, Decoded, Elf, Image, Taint}

// The decoder is plain Scala over hand-written hex, so this needs neither
// staging, nor snapshots, nor a RISC-V toolchain on the box. Every literal here
// came out of `llvm-objdump -d` on clang's own output.
class RiscVDecodeTests extends AnyFunSuite {
  private def insn(word: Int): Instr = Decode.insn(word) match {
    case Right(Decoded.Insn(i)) => i
    case Right(Decoded.Ret)     => fail(f"0x$word%08x decoded as `ret`")
    case Left(e)                => fail(e)
  }

  private def why(word: Int): String =
    Decode.insn(word).fold(identity, d => fail(s"0x${word.toHexString} decoded as $d"))

  private def offset(i: Instr): Int = i match {
    case Instr.Branch(_, _, _, o) => o.i
    case Instr.Jal(_, o)          => o.i
    case _                        => fail(s"$i carries no pc-relative offset")
  }

  private def decodes(cases: (Int, Instr)*): Unit =
    assert(cases.filter((w, i) => insn(w) != i).map((w, _) => f"0x$w%08x") == Vector())

  test("the register-register ALU ops, one per funct3 and funct7") {
    decodes(
      0x015a09b3 -> Instr.Op(AluOp.Add, Reg(19), Reg(20), Reg(21)),
      0x418b8b33 -> Instr.Op(AluOp.Sub, Reg(22), Reg(23), Reg(24)),
      0x01bd1cb3 -> Instr.Op(AluOp.Sll, Reg(25), Reg(26), Reg(27)),
      0x01eeae33 -> Instr.Op(AluOp.Slt, Reg(28), Reg(29), Reg(30)),
      0x0020bfb3 -> Instr.Op(AluOp.Sltu, Reg(31), Reg(1), Reg(2)),
      0x005241b3 -> Instr.Op(AluOp.Xor, Reg(3), Reg(4), Reg(5)),
      0x0083d333 -> Instr.Op(AluOp.Srl, Reg(6), Reg(7), Reg(8)),
      0x40b554b3 -> Instr.Op(AluOp.Sra, Reg(9), Reg(10), Reg(11)),
      0x00e6e633 -> Instr.Op(AluOp.Or, Reg(12), Reg(13), Reg(14)),
      0x011877b3 -> Instr.Op(AluOp.And, Reg(15), Reg(16), Reg(17))
    )
  }

  // `srai` sets bit 30, so reading a shift-immediate the I-type way would give
  // 1031 rather than 7. `funct7` is the discriminator there and part of the
  // immediate everywhere else.
  test("the immediate ALU ops, and a shift takes a shamt rather than an immediate") {
    decodes(
      0xfef10093 -> Instr.OpImm(AluOp.Add, Reg(1), Reg(2), Imm(-17)),
      0xffb52493 -> Instr.OpImm(AluOp.Slt, Reg(9), Reg(10), Imm(-5)),
      0x00563593 -> Instr.OpImm(AluOp.Sltu, Reg(11), Reg(12), Imm(5)),
      0x0ff74693 -> Instr.OpImm(AluOp.Xor, Reg(13), Reg(14), Imm(255)),
      0xf0086793 -> Instr.OpImm(AluOp.Or, Reg(15), Reg(16), Imm(-256)),
      0x00197893 -> Instr.OpImm(AluOp.And, Reg(17), Reg(18), Imm(1)),
      0x01f21193 -> Instr.OpImm(AluOp.Sll, Reg(3), Reg(4), Imm(31)),
      0x00145393 -> Instr.OpImm(AluOp.Srl, Reg(7), Reg(8), Imm(1)),
      0x40735293 -> Instr.OpImm(AluOp.Sra, Reg(5), Reg(6), Imm(7))
    )
  }

  test("the six branch conditions") {
    decodes(
      0x04208863 -> Instr.Branch(Cmp.Eq, Reg(1), Reg(2), Imm(80)),
      0x04419663 -> Instr.Branch(Cmp.Ne, Reg(3), Reg(4), Imm(76)),
      0x0462c463 -> Instr.Branch(Cmp.Lt, Reg(5), Reg(6), Imm(72)),
      0x0483d263 -> Instr.Branch(Cmp.Ge, Reg(7), Reg(8), Imm(68)),
      0x04a4e063 -> Instr.Branch(Cmp.Ltu, Reg(9), Reg(10), Imm(64)),
      0x02c5fe63 -> Instr.Branch(Cmp.Geu, Reg(11), Reg(12), Imm(60))
    )
  }

  // A store names its value register in `rs2` and its base in `rs1`, which is
  // the reverse of how the assembly reads.
  test("loads and stores, signed and unsigned") {
    decodes(
      0x00410083 -> Instr.Load(Width.B, Reg(1), Reg(2), Imm(4)),
      0xffc21183 -> Instr.Load(Width.H, Reg(3), Reg(4), Imm(-4)),
      0x00832283 -> Instr.Load(Width.W, Reg(5), Reg(6), Imm(8)),
      0x00144383 -> Instr.Load(Width.Bu, Reg(7), Reg(8), Imm(1)),
      0x00255483 -> Instr.Load(Width.Hu, Reg(9), Reg(10), Imm(2)),
      0x00110223 -> Instr.Store(Width.B, Reg(1), Reg(2), Imm(4)),
      0xfe321e23 -> Instr.Store(Width.H, Reg(3), Reg(4), Imm(-4)),
      0x00532423 -> Instr.Store(Width.W, Reg(5), Reg(6), Imm(8))
    )
  }

  // [Exec] shifts these itself, `unit(imm.i << 12)`, so the twenty bits arrive
  // unshifted and unsigned. `lui ra, 0xfffff` is the one that says which.
  test("lui and auipc keep the unshifted twenty bits") {
    decodes(
      0xfffff0b7 -> Instr.Lui(Reg(1), Imm(0xfffff)),
      0x00001137 -> Instr.Lui(Reg(2), Imm(1)),
      0x12345197 -> Instr.Auipc(Reg(3), Imm(0x12345))
    )
  }

  test("a branch offset is sign-extended, in both directions") {
    val back = insn(0xfe0594e3)
    val fwd = insn(0x0a059263)
    assert(back == Instr.Branch(Cmp.Ne, Reg(11), Reg(0), Imm(-24)))
    assert(fwd == Instr.Branch(Cmp.Ne, Reg(11), Reg(0), Imm(164)))
    // Two offsets of the same sign would leave half of the scramble untested.
    assert(offset(back) < 0 && offset(fwd) > 0)
  }

  test("a jump offset is sign-extended, in both directions") {
    val back = insn(0xff1ff06f)
    val fwd = insn(0x00c000ef)
    assert(back == Instr.Jal(Reg(0), Imm(-16)))
    assert(fwd == Instr.Jal(Reg(1), Imm(12)))
    assert(offset(back) < 0 && offset(fwd) > 0)
  }

  // `ret` is `jalr x0, 0(x1)`, and it is the only `jalr` whose target the reader
  // can work out without running the program.
  test("ret is its own thing, and every other jalr is an error") {
    assert(Decode.insn(Decode.ret) == Right(Decoded.Ret))
    // `jalr a0, 0(a1)`, `jalr x0, 4(x1)` and `jr a0`.
    assert(why(0x00058567).contains("register value"))
    assert(why(0x00408067).contains("register value"))
    assert(why(0x00050067).contains("register value"))
  }

  test("what the tower does not decode says what to do about it") {
    assert(why(0x023100b3).contains("-march=rv32i"))
    assert(why(0x0ff0000f).contains("`fence`"))
    assert(why(0x00000073).contains("out of scope"))
    // A `lw` with no width, and a compressed instruction, neither of which has
    // a fix to suggest.
    assert(why(0x00033283).contains("not an RV32I load"))
    assert(why(0x00004501).contains("no RV32I instruction"))
  }
}

// The reader, against objects `src/test/asm/riscv/build` makes. Separate from
// [RiscVDecodeTests] so that the decoder still runs on a clone where nobody has
// run the script yet, and this one aborts with a message saying to.
class RiscVElfTests extends AnyFunSuite {
  private val dir = "src/test/asm/riscv/"

  private def bytes(name: String): Array[Byte] =
    java.nio.file.Files.readAllBytes(java.nio.file.Path.of(dir + name))

  private def read(name: String, bs: Array[Byte]): Image =
    Elf.read(name, bs).fold(es => fail(es.mkString("\n")), identity)

  private val cmp = read("cmp.o", bytes("cmp.o"))

  // `demo` and the two byte counts live on the driver, and nothing here stages,
  // so one bare instance is enough to read them off.
  private val driver = new RiscVDriver { override val init = ""; override val prog = Vector() }

  private def rejects(name: String): List[String] =
    Elf.read(name, bytes(name)).fold(_.map(_.toString), i => fail(s"read ${i.prog}"))

  // A byte-patched copy, with the offsets found rather than hardcoded. Most of
  // what the reader refuses is one field wide, and setting that field is a
  // fairer test than an assembler invocation that happens to produce it.
  private def patched(edits: (Int, Int)*): List[String] = {
    val bs = bytes("cmp.o")
    for ((at, v) <- edits) { bs(at) = v.toByte }
    Elf.read("cmp.o", bs).fold(_.map(_.toString), i => fail(s"read ${i.prog}"))
  }

  // The reader walks the section headers too, and walking them again here is
  // only to aim a patch: a hardcoded file offset would break on the next clang
  // that reorders a section.
  private def sectionAt(name: String): Int = {
    val bs = bytes("cmp.o")
    val b = java.nio.ByteBuffer.wrap(bs).order(java.nio.ByteOrder.LITTLE_ENDIAN)
    val shoff = b.getInt(32)
    val names = b.getInt(shoff + 40 * b.getShort(50) + 16)
    val i = (0 until b.getShort(48)).find { i =>
      val at = names + b.getInt(shoff + 40 * i)
      bs(at + name.length) == 0 && new String(bs, at, name.length, "UTF-8") == name
    }
    b.getInt(shoff + 40 * i.getOrElse(fail(s"no `$name` in cmp.o")) + 16)
  }

  private def regs(i: Instr): Set[Reg] = i match {
    case Instr.Op(_, rd, rs1, rs2)    => Set(rd, rs1, rs2)
    case Instr.OpImm(_, rd, rs1, _)   => Set(rd, rs1)
    case Instr.Lui(rd, _)             => Set(rd)
    case Instr.Auipc(rd, _)           => Set(rd)
    case Instr.Jal(rd, _)             => Set(rd)
    case Instr.Branch(_, rs1, rs2, _) => Set(rs1, rs2)
    case Instr.Load(_, rd, rs1, _)    => Set(rd, rs1)
    case Instr.Store(_, rs2, rs1, _)  => Set(rs2, rs1)
  }

  test("the program is what clang emitted, with both `ret`s pointed past the end") {
    assert(cmp.prog == Vector(
      Instr.OpImm(AluOp.Add, Reg(11), Reg(10), Imm(0)),
      Instr.OpImm(AluOp.Add, Reg(10), Reg(0), Imm(1)),
      Instr.Branch(Cmp.Ge, Reg(0), Reg(11), Imm(48)),
      Instr.Lui(Reg(12), Imm(0)),
      Instr.OpImm(AluOp.Add, Reg(12), Reg(12), Imm(16)),
      Instr.Lui(Reg(13), Imm(0)),
      Instr.OpImm(AluOp.Add, Reg(13), Reg(13), Imm(0)),
      Instr.Load(Width.W, Reg(14), Reg(12), Imm(0)),
      Instr.Load(Width.W, Reg(15), Reg(13), Imm(0)),
      Instr.Branch(Cmp.Ne, Reg(14), Reg(15), Imm(24)),
      Instr.OpImm(AluOp.Add, Reg(11), Reg(11), Imm(-1)),
      Instr.OpImm(AluOp.Add, Reg(12), Reg(12), Imm(4)),
      Instr.OpImm(AluOp.Add, Reg(13), Reg(13), Imm(4)),
      Instr.Branch(Cmp.Ne, Reg(11), Reg(0), Imm(-24)),
      Instr.Jal(Reg(0), Imm(12)),
      Instr.OpImm(AluOp.Add, Reg(10), Reg(0), Imm(0)),
      Instr.Jal(Reg(0), Imm(4))
    ))
  }

  // The two `%hi`/`%lo` pairs are the whole reason relocations are handled at
  // all, and what they compute is a `mem` byte address. `lui` of zero looks
  // like nothing happened, so the `addi` beside it is the evidence.
  test("a %hi and %lo pair computes where the reader put the global") {
    val addrs = cmp.globals.view.mapValues(_.addr).toMap
    assert(addrs == Map("secret" -> 0, "guess" -> 16))
    assert(cmp.prog(4) == Instr.OpImm(AluOp.Add, Reg(12), Reg(12), Imm(addrs("guess"))))
    assert(cmp.prog(6) == Instr.OpImm(AluOp.Add, Reg(13), Reg(13), Imm(addrs("secret"))))
    // Two globals at the same address would make either `addi` pass for the
    // other's.
    assert(addrs.values.toSet.size == 2)
  }

  // `st_shndx` names the section, so the `__attribute__` in `cmp.c` is the
  // threat model and no symbol name is hardcoded. `st_size` says 16 rather than
  // somebody keeping a `val words = 4` in sync by hand.
  test("taint and size come out of the symbol, not out of the name") {
    assert(cmp.globals == Map(
      "secret" -> Datum(0, 16, Taint.Secret),
      "guess" -> Datum(16, 16, Taint.Attacker)
    ))
  }

  test("the data image is the initialized bytes then the zeroed ones") {
    assert(cmp.data == Vector(11, 22, 33, 44, 0, 0, 0, 0))
  }

  test("st_info tells a function from an object") {
    assert(cmp.entries == Map("cmp" -> 0))
    assert(cmp.entry == 0)
    assert(cmp.globals.keySet == Set("secret", "guess"))
  }

  // The build script duplicates these out of `GenericKoikaDriver`, because a
  // real assembler cannot hear Scala. `--defsym` leaves them behind as ABS
  // symbols, which is what lets the drift be caught here instead of in a
  // snapshot.
  test("the assembler constants survive as ABS symbols") {
    assert(cmp.consts("SECRET") == driver.secret_offset_bytes)
    assert(cmp.consts("SIZE") == driver.password_size_bytes)
    // The `.file` symbol is ABS too, and it is not a constant.
    assert(cmp.consts.keySet == Set("SECRET", "SIZE"))
  }

  // `sp` starts at 0 and `mem` is 30 words, so a frame would index `mem` at
  // `(-4) >>> 2`. That is why `cmp.c` is built at -O1, and this is the test
  // that notices if the flag ever comes off.
  test("the fixture never touches sp") {
    assert(cmp.prog.flatMap(regs).filter(_ == Reg(2)) == Vector())
  }

  // The one relocation form nothing else in the tree produces, and the third
  // row of the taint table: `.data` is neither secret nor the attacker's.
  test("a store relocation lands on the store's own displacement") {
    val store = read("store.o", bytes("store.o"))
    assert(store.globals == Map("v" -> Datum(12, 4, Taint.Public)))
    assert(store.prog == Vector(
      Instr.Lui(Reg(11), Imm(0)),
      Instr.Store(Width.W, Reg(10), Reg(11), Imm(12))
    ))
    assert(store.data == Vector(0, 0, 0, 7))
  }

  test("two functions in .text say why one is the limit") {
    val es = rejects("two_functions.o")
    assert(es.length == 1)
    assert(es.head.contains("`f`") && es.head.contains("`g`") && es.head.contains("`call`"))
  }

  test("an rv64 object is one byte away and says which flags to use") {
    assert(patched(4 -> 2).mkString.contains("--target=riscv32"))
  }

  // Relaxation lets the linker insert or drop NOPs, so an object built without
  // -mno-relax has every offset computed against a sequence nobody meant to
  // keep. Its absence is otherwise silent.
  test("a relaxation relocation says which flag is missing") {
    val info = sectionAt(".rela.text") + 4
    assert(patched(info -> 51).mkString.contains("-mno-relax"))
    assert(patched(info -> 43).mkString.contains("-mno-relax"))
  }

  test("a relocation out of scope names its type") {
    val info = sectionAt(".rela.text") + 4
    assert(patched(info -> 19).mkString.contains("R_RISCV_CALL_PLT"))
    // `-fpic` output reaches a global through the `auipc` that defined a label,
    // which needs a second lookup the reader does not do.
    assert(patched(info -> 23).mkString.contains("-fno-pic"))
  }

  // A `%hi` on anything but a `lui` or an `auipc` has no twenty-bit field to
  // land in, and dropping the immediate would leave a program that runs.
  test("a relocation on the wrong instruction form is an error, not a dropped immediate") {
    val es = patched(sectionAt(".rela.text") -> 0x1c)
    assert(es.length == 1)
    assert(es.head.contains("%hi wants a `lui`") && es.head.contains("cmp.o .text+0x1c"))
  }

  test("what the tower cannot execute is rejected where it sits") {
    val text = sectionAt(".text")
    // `mul a0, a1, a2` and `jalr a0, 0(a1)`, over the `mv a1, a0` at .text+0.
    assert(patched(text -> 0x33, text + 1 -> 0x85, text + 2 -> 0xc5, text + 3 -> 0x02)
      .mkString.contains("-march=rv32i"))
    assert(patched(text -> 0x67, text + 1 -> 0x85, text + 2 -> 0x05, text + 3 -> 0x00)
      .mkString.contains("cmp.o .text+0x0"))
  }

  // The hand-assembled vectors are the oracle for the migration, and they are
  // deleted along with them once this has run. Without it the snapshot check is
  // circular: the reader and the snapshots could be wrong together.
  test("the demos decode to the vectors they replace") {
    val secret = driver.secret_offset_bytes
    val size = driver.password_size_bytes
    assert(driver.demo("2ctr") == RiscVDemos.spec_small)
    assert(driver.demo("spectre") == RiscVDemos.build_spectre_demo(secret))
    assert(driver.demo("shortcircuit") == RiscVDemos.build_shortcircuit_demo(secret, size))
    assert(driver.demo("constant_time") == RiscVDemos.build_constant_time_demo(secret, size))
  }

  // Four equalities against four oracles prove nothing if the oracles coincide.
  test("the demo vectors are pairwise distinct") {
    val names = Vector("2ctr", "spectre", "shortcircuit", "constant_time")
    assert(names.map(driver.demo).distinct.length == names.length)
  }

  test("a missing object says to run the script") {
    val e = intercept[elf.ElfException](Elf.load(dir + "nope.o"))
    assert(e.getMessage.contains("src/test/asm/riscv/build"))
  }
}
