package elms.koika.test.riscv.elf

import elms.koika.test.riscv.RiscV
import RiscV.{Imm, Instr}

// An ET_REL RISC-V object, read into the shape the tower wants. Reading fields
// rather than parsing assembly is what buys the three things a text frontend
// cannot get: `st_shndx` says which section a global lives in and so what its
// taint is, `st_size` says how big it is, and `st_info` says whether it is code
// or data.
object Elf {
  private val script = "./src/test/asm/riscv/build"

  def read(name: String, bytes: Array[Byte]): Either[List[ElfError], Image] =
    try { relocatable(Obj(name, bytes)) }
    catch {
      case _: IndexOutOfBoundsException =>
        Left(List(ElfError(name, s"truncated: ${bytes.length} bytes")))
    }

  // Throws. For `override val prog = …`, where an [Either] would only be
  // unwrapped again at every use site.
  def load(path: String): Image = {
    val bytes =
      try { java.nio.file.Files.readAllBytes(java.nio.file.Path.of(path)) }
      catch {
        case _: java.io.IOException =>
          throw new ElfException(List(ElfError(path, s"no such object; run $script")))
      }
    read(path, bytes).fold(es => throw new ElfException(es), identity)
  }

  // Spelled the way the spec spells them, so they grep against it.
  private val ELFCLASS32 = 1
  private val ELFDATA2LSB = 1
  private val ET_REL = 1
  private val EM_RISCV = 243
  private val SHT_SYMTAB = 2
  private val SHT_RELA = 4
  private val SHT_NOBITS = 8
  private val SHF_ALLOC = 2
  private val SHF_EXECINSTR = 4
  private val STT_NOTYPE = 0
  private val STT_OBJECT = 1
  private val STT_FUNC = 2
  private val SHN_ABS = 0xfff1
  private val R_RISCV_HI20 = 26
  private val R_RISCV_LO12_I = 27
  private val R_RISCV_LO12_S = 28
  private val R_RISCV_ALIGN = 43
  private val R_RISCV_RELAX = 51

  // Enough type names for a rejection to say what it saw. `BRANCH` and `JAL`
  // only appear under relaxation, where the [R_RISCV_RELAX] entry beside them
  // is the one carrying the fix.
  private val relocNames: Map[Int, String] = Map(
    16 -> "R_RISCV_BRANCH",
    17 -> "R_RISCV_JAL",
    18 -> "R_RISCV_CALL",
    19 -> "R_RISCV_CALL_PLT",
    23 -> "R_RISCV_PCREL_HI20",
    24 -> "R_RISCV_PCREL_LO12_I",
    25 -> "R_RISCV_PCREL_LO12_S"
  )

  // A PIC build reaches a global through the `auipc` that defined a label
  // rather than through an absolute address, which needs a second lookup the
  // reader does not do.
  private val pcrel: Set[Int] = Set(23, 24, 25)

  private class Obj(val name: String, bytes: Array[Byte]) {
    private val buf =
      java.nio.ByteBuffer.wrap(bytes).order(java.nio.ByteOrder.LITTLE_ENDIAN)

    def u8(at: Int): Int = buf.get(at) & 0xff
    def u16(at: Int): Int = buf.getShort(at) & 0xffff
    def i32(at: Int): Int = buf.getInt(at)

    // A NUL-terminated name out of a string table.
    def str(table: Int, at: Int): String = {
      val end = Iterator.from(table + at).find(i => buf.get(i) == 0).get
      new String(bytes, table + at, end - (table + at), "UTF-8")
    }
  }

  private case class Sec(
      i: Int,
      name: String,
      kind: Int,
      flags: Int,
      off: Int,
      size: Int,
      link: Int,
      info: Int,
      align: Int,
      entsize: Int
  ) {
    def alloc: Boolean = (flags & SHF_ALLOC) != 0
    def code: Boolean = alloc && (flags & SHF_EXECINSTR) != 0
  }

  private case class Sym(name: String, value: Int, size: Int, info: Int, shndx: Int) {
    def kind: Int = info & 0xf
  }

  private def roundUp(x: Int, to: Int): Int = ((x + to - 1) / to) * to

  // An rv64 build is ELFCLASS64 and says so in one byte, which is strictly
  // better evidence than a string match on a `.attribute` line.
  private def header(o: Obj): List[ElfError] = {
    def bad(msg: String) = ElfError(o.name, msg)
    val magic = (0 to 3).map(o.u8)
    if (magic != Seq(0x7f, 'E'.toInt, 'L'.toInt, 'F'.toInt)) { List(bad("not an ELF file")) }
    else {
      List(
        Option.when(o.u8(4) != ELFCLASS32)(
          bad("ELFCLASS64; rebuild with --target=riscv32 -march=rv32i -mabi=ilp32")
        ),
        Option.when(o.u8(5) != ELFDATA2LSB)(bad("big-endian")),
        Option.when(o.u16(16) != ET_REL)(bad("not ET_REL; the reader wants a `-c` object")),
        Option.when(o.u16(18) != EM_RISCV)(bad(s"e_machine is ${o.u16(18)}, not RISC-V")),
        Option.when(o.u16(46) != 40)(bad(s"e_shentsize is ${o.u16(46)}, not 40"))
      ).flatten
    }
  }

  private def sections(o: Obj): Vector[Sec] = {
    val shoff = o.i32(32)
    val shnum = o.u16(48)
    val names = o.i32(shoff + 40 * o.u16(50) + 16)
    (0 until shnum).map { i =>
      val at = shoff + 40 * i
      Sec(
        i = i,
        name = o.str(names, o.i32(at)),
        kind = o.i32(at + 4),
        flags = o.i32(at + 8),
        off = o.i32(at + 16),
        size = o.i32(at + 20),
        link = o.i32(at + 24),
        info = o.i32(at + 28),
        align = o.i32(at + 32),
        entsize = o.i32(at + 36)
      )
    }.toVector
  }

  private def symbols(o: Obj, tab: Sec): Vector[Sym] = {
    val stride = if (tab.entsize > 0) { tab.entsize } else { 16 }
    val strs = o.i32(o.i32(32) + 40 * tab.link + 16)
    (0 until tab.size / stride).map { i =>
      val at = tab.off + stride * i
      Sym(o.str(strs, o.i32(at)), o.i32(at + 4), o.i32(at + 8), o.u8(at + 12), o.u16(at + 14))
    }.toVector
  }

  // One byte cursor across every allocatable data section, in header order.
  // Header order is the only thing in a relocatable object that says which
  // global comes first, and it is what puts `.secret` at byte 0 and
  // `.attacker` at byte 16.
  private def layout(o: Obj, secs: Vector[Sec]): (Vector[Int], Map[Int, Int]) =
    secs.foldLeft((Vector.empty[Int], Map.empty[Int, Int])) { case ((bytes, base), s) =>
      val at = roundUp(bytes.length, math.max(1, s.align))
      val body =
        if (s.kind == SHT_NOBITS) { Vector.fill(s.size)(0) }
        else { (0 until s.size).map(i => o.u8(s.off + i)).toVector }
      (bytes ++ Vector.fill(at - bytes.length)(0) ++ body, base + (s.i -> at))
    }

  // Little-endian, the way RISC-V reads them, so `words(k)` is `mem[k]`.
  private def words(bytes: Vector[Int]): Vector[Int] =
    bytes
      .grouped(4)
      .map(g => g.zipWithIndex.foldLeft(0)((w, p) => w | ((p._1 & 0xff) << (8 * p._2))))
      .toVector

  // Taint is the section name and nothing else, which is what makes the
  // `__attribute__((section(…)))` in the C the threat model.
  private def taint(section: String): Taint = section match {
    case ".secret"   => Taint.Secret
    case ".attacker" => Taint.Attacker
    case _           => Taint.Public
  }

  private def relocatable(o: Obj): Either[List[ElfError], Image] = header(o) match {
    case es @ (_ :: _) => Left(es)
    case Nil           => {
      val secs = sections(o)
      val data = secs.filter(s => s.alloc && !s.code)
      val (bytes, base) = layout(o, data)

      val found = for {
        code <- one(o, secs.filter(_.code), "allocatable executable section")
        tab <- one(o, secs.filter(_.kind == SHT_SYMTAB), "`.symtab`")
      } yield (code, tab)

      found match {
        case Left(e)            => Left(List(e))
        case Right((code, tab)) => {
          val syms = symbols(o, tab)
          val (prog, textErrors) = text(o, code)
          val (globals, dataErrors) = objects(o, syms, secs, base)
          val (patched, relErrors) = relocate(o, secs, code, prog, addresses(syms, base))

          val entries = syms.filter(s => s.kind == STT_FUNC && s.shndx == code.i)
          val entryErrors =
            entries.toList.flatMap(misplaced(o, code, prog.length)) ++ crowded(o, code, entries)

          val errors = textErrors ++ dataErrors ++ relErrors ++ entryErrors
          if (errors.nonEmpty) { Left(errors) }
          else {
            Right(Image(
              prog = patched,
              data = words(bytes),
              globals = globals,
              entries = entries.map(s => s.name -> s.value / 4).toMap,
              consts = syms.filter(s => s.kind == STT_NOTYPE && s.shndx == SHN_ABS)
                .map(s => s.name -> s.value).toMap,
              entry = entries.headOption.map(_.value / 4).getOrElse(0)
            ))
          }
        }
      }
    }
  }

  private def one(o: Obj, secs: Vector[Sec], what: String): Either[ElfError, Sec] =
    secs match {
      case Vector(s) => Right(s)
      case _         => Left(ElfError(o.name, s"wanted one $what, found ${secs.length}"))
    }

  private def misplaced(o: Obj, code: Sec, n: Int)(s: Sym): Option[ElfError] =
    Option.when(s.value % 4 != 0 || s.value / 4 > n)(
      ElfError(o.name, s"`${s.name}` starts at ${locus(o, code, s.value)}, which is no instruction")
    )

  // One `ret` becomes a jump past the end of [prog], which halts. A callee's
  // `ret` would have to return to its caller instead, and there is nothing in
  // the tower for it to return through.
  private def crowded(o: Obj, code: Sec, entries: Vector[Sym]): List[ElfError] =
    Option.when(entries.length > 1) {
      val names = entries.map(s => s"`${s.name}`").mkString(", ")
      val what = s"${entries.length} functions in `${code.name}` ($names)"
      ElfError(o.name, s"$what; the tower has no `call` to reach them with")
    }.toList

  private def text(o: Obj, s: Sec): (Vector[Instr], List[ElfError]) =
    if (s.size % 4 != 0) {
      val msg = s"`${s.name}` is ${s.size} bytes, not a whole number of instructions"
      (Vector.empty, List(ElfError(o.name, msg)))
    } else {
      val n = s.size / 4
      val decoded = (0 until n).map { at =>
        Decode.insn(o.i32(s.off + 4 * at)) match {
          // [Common.call] hands the state back unchanged one past the end,
          // which is how the tower halts. For a leaf function with its result
          // in a0 that is exactly what returning does.
          case Right(Decoded.Ret)     => Right(Instr.Jal(RiscV.x0, Imm(4 * (n - at))))
          case Right(Decoded.Insn(i)) => Right(i)
          case Left(e)                => Left(ElfError(locus(o, s, 4 * at), e))
        }
      }.toVector
      (decoded.collect { case Right(i) => i }, decoded.collect { case Left(e) => e }.toList)
    }

  private def locus(o: Obj, s: Sec, off: Int): String = f"${o.name} ${s.name}+0x$off%x"

  // `st_info` is what makes this a field lookup rather than a heuristic pairing
  // `.globl` against `.type …,@object`.
  private def objects(
      o: Obj,
      syms: Vector[Sym],
      secs: Vector[Sec],
      base: Map[Int, Int]
  ): (Map[String, Datum], List[ElfError]) = {
    val (placed, adrift) =
      syms.filter(_.kind == STT_OBJECT).partition(s => base.contains(s.shndx))
    val globals = placed.map { s =>
      s.name -> Datum(base(s.shndx) + s.value, s.size, taint(secs(s.shndx).name))
    }
    // A global the driver cannot place is a silent hole rather than a missing
    // feature: the code would read it and nothing would ever initialize it.
    val errors = adrift.toList.map { s =>
      ElfError(o.name, s"`${s.name}` is in no allocatable data section, so nothing would place it")
    }
    (globals.toMap, errors)
  }

  // Symbol index to byte address in the data image. Code addresses are absent
  // on purpose: [prog] is indexed separately from `mem`, so a `%hi` of a
  // function has nowhere to point.
  private def addresses(syms: Vector[Sym], base: Map[Int, Int]): Map[Int, Int] =
    syms.zipWithIndex.collect {
      case (s, i) if base.contains(s.shndx) => i -> (base(s.shndx) + s.value)
      case (s, i) if s.shndx == SHN_ABS     => i -> s.value
    }.toMap

  private def relocate(
      o: Obj,
      secs: Vector[Sec],
      code: Sec,
      prog: Vector[Instr],
      addr: Map[Int, Int]
  ): (Vector[Instr], List[ElfError]) = {
    val (mine, theirs) = secs.filter(_.kind == SHT_RELA).partition(_.info == code.i)
    // A relocation against the data image would be a pointer, and nothing in
    // the tower would fill it in.
    val wrongSection = theirs.filter(s => secs(s.info).alloc).toList.map { s =>
      ElfError(o.name, s"`${s.name}` relocates `${secs(s.info).name}`, which is data")
    }
    val entries = mine.flatMap { s =>
      val stride = if (s.entsize > 0) { s.entsize } else { 12 }
      (0 until s.size / stride).map(i => s.off + stride * i)
    }

    entries.foldLeft((prog, wrongSection)) { case ((p, es), at) =>
      val off = o.i32(at)
      val info = o.i32(at + 4)
      val where = locus(o, code, off)
      patch(p, addr, off, info >>> 8, info & 0xff, o.i32(at + 8)) match {
        case Right(q) => (q, es)
        case Left(e)  => (p, es :+ ElfError(where, e))
      }
    }
  }

  private def patch(
      prog: Vector[Instr],
      addr: Map[Int, Int],
      off: Int,
      sym: Int,
      kind: Int,
      addend: Int
  ): Either[String, Vector[Instr]] =
    if (kind == R_RISCV_ALIGN || kind == R_RISCV_RELAX) {
      // Relaxation lets the linker insert or drop NOPs, so every offset in the
      // object was computed against a sequence nobody meant to keep.
      Left("built with relaxation; rebuild with -mno-relax")
    } else if (off % 4 != 0 || off / 4 >= prog.length) {
      Left(s"relocation offset $off is not an instruction")
    } else if (!Set(R_RISCV_HI20, R_RISCV_LO12_I, R_RISCV_LO12_S).contains(kind)) {
      val what = relocNames.getOrElse(kind, s"relocation type $kind")
      Left(if (pcrel(kind)) { s"$what; rebuild with -fno-pic" } else { s"$what is out of scope" })
    } else {
      addr.get(sym).toRight("relocation against a symbol with no address in `mem`").flatMap { s =>
        // The rounding in `%hi` is what the sign extension in `%lo` cancels.
        val v = s + addend
        val at = off / 4
        val patched = kind match {
          case R_RISCV_HI20 => hi(Imm(((v + 0x800) >>> 12) & 0xfffff), prog(at))
          case _            => lo(Imm((v << 20) >> 20), kind, prog(at))
        }
        patched.map(prog.updated(at, _))
      }
    }

  // The relocation has to land on a field that exists, and the ADT is what says
  // so. A dropped immediate would otherwise read as a program that works.
  private def hi(imm: Imm, i: Instr): Either[String, Instr] = i match {
    case Instr.Lui(rd, _)   => Right(Instr.Lui(rd, imm))
    case Instr.Auipc(rd, _) => Right(Instr.Auipc(rd, imm))
    case _                  => Left(s"%hi wants a `lui` or an `auipc`, found $i")
  }

  private def lo(imm: Imm, kind: Int, i: Instr): Either[String, Instr] = (kind, i) match {
    case (R_RISCV_LO12_I, Instr.OpImm(op, rd, rs1, _)) => Right(Instr.OpImm(op, rd, rs1, imm))
    case (R_RISCV_LO12_I, Instr.Load(w, rd, rs1, _))   => Right(Instr.Load(w, rd, rs1, imm))
    case (R_RISCV_LO12_I, _) => Left(s"%lo wants an `addi` or a load, found $i")
    case (_, Instr.Store(w, rs2, rs1, _)) => Right(Instr.Store(w, rs2, rs1, imm))
    case (_, _) => Left(s"%lo wants a store, found $i")
  }
}
