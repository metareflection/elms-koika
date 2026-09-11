package elms.koika.test.riscv.asm

import elms.koika.test.riscv.RiscV
import RiscV.{AluOp, Cmp, Imm, Instr, Reg, Width, x0}

// The immediate an instruction wants, before the symbol it may be hiding in has
// an address.
enum Fixup derives CanEqual {
  case Lit(v: Int)
  case Abs(sym: String, addend: Int)
  case Rel(label: String, addend: Int)
  case Hi(sym: String, addend: Int)
  case Lo(sym: String, addend: Int)
}

// One machine instruction whose single immediate is still symbolic. RV32I has
// at most one immediate per instruction, so a one-hole context is everything
// pass 2 needs and no second ADT has to shadow [Instr]. No [CanEqual]: [Open]
// holds a function and nothing compares slots.
enum Slot {
  case Fixed(i: Instr)
  case Open(fixup: Fixup, fill: Imm => Instr)
}

// [symbols] are byte addresses, and text and data share that numeric space.
// [entries] maps a text symbol to its index into [prog], and [entry] is the
// default pick among them.
case class Image(
    prog: Vector[Instr],
    data: Vector[Int],
    symbols: Map[String, Int],
    entries: Map[String, Int],
    entry: Int
)

object Asm {
  def assemble(
      file: String,
      src: String,
      defines: Map[String, Int] = Map.empty
  ): Either[List[AsmError], Image] = {
    val (stmts, lexErrors) = Parse.stmts(file, src)
    val consts = defines ++ equs(stmts)
    val laid = stmts.foldLeft(Layout())((acc, s) => stmt(acc, s))
    val addrs = consts ++ laid.dataSyms ++ laid.labels.map((n, i) => n -> 4 * i)
    val (prog, linkErrors) = link(laid.slots, laid.labels, addrs)
    val errors = lexErrors ++ laid.errors ++ linkErrors
    if (errors.nonEmpty) { Left(errors) }
    else { Right(Image(prog, words(laid.data), addrs, laid.labels, entry(stmts, laid.labels))) }
  }

  // Throws. For `override val prog = …`, where an [Either] would only be
  // unwrapped again at every use site.
  def load(path: String, defines: Map[String, Int] = Map.empty): Image =
    assemble(path, java.nio.file.Files.readString(java.nio.file.Path.of(path)), defines)
      .fold(es => throw new AsmException(es), identity)

  private enum Section derives CanEqual { case Text, Data, Other }

  private case class Layout(
      slots: Vector[(Loc, Slot)] = Vector.empty,
      labels: Map[String, Int] = Map.empty,
      data: Vector[Int] = Vector.empty,
      dataSyms: Map[String, Int] = Map.empty,
      section: Section = Section.Text,
      errors: List[AsmError] = List.empty
  ) {
    def fail(loc: Loc, msg: String): Layout = copy(errors = errors :+ AsmError(loc, msg))
    def emit(bs: Seq[Int]): Layout = copy(data = data ++ bs)
  }

  // Pass 1. A label binds inside the fold rather than after it, since one at
  // the bottom of the file legitimately binds to the final length.
  private def stmt(l: Layout, s: Stmt): Layout = s.form match {
    case Form.Label(n) => l.section match {
        case Section.Text  => l.copy(labels = l.labels + (n -> l.slots.length))
        case Section.Data  => l.copy(dataSyms = l.dataSyms + (n -> l.data.length))
        case Section.Other => l
      }
    case Form.Dir(n, args) => directive(l, s.loc, n, args)
    case Form.Insn(m, ops) => l.section match {
        case Section.Text => Mnemonics.insn(m, ops) match {
            case Right(ss) => l.copy(slots = l.slots ++ ss.map((s.loc, _)))
            case Left(e)   => l.fail(s.loc, e)
          }
        case _ => l.fail(s.loc, s"`$m` outside .text")
      }
  }

  private def directive(l: Layout, loc: Loc, name: String, args: List[String]): Layout =
    name match {
      case ".text" => l.copy(section = Section.Text)
      case ".data" | ".bss" | ".rodata" | ".sdata" | ".sbss" | ".srodata" | ".tdata" | ".tbss" =>
        l.copy(section = Section.Data)
      case ".section" => l.copy(section = sectionOf(args))
      case ".p2align" | ".align" => align(l, args, n => 1 << n)
      case ".balign"             => align(l, args, identity)
      case ".comm" | ".lcomm"    => common(l, loc, args)
      case ".word" | ".long" | ".4byte"   => datum(l, loc, name, args, 4)
      case ".half" | ".short" | ".2byte"  => datum(l, loc, name, args, 2)
      case ".byte"                        => datum(l, loc, name, args, 1)
      case ".asciz" | ".string"           => text(l, loc, name, args, true)
      case ".ascii"                       => text(l, loc, name, args, false)
      case ".zero" | ".space" | ".skip"   => zero(l, loc, name, args)
      // Skipped by default rather than rejected. gcc's output differs from
      // clang's mostly in directives, and a whitelist would turn lines that
      // carry no semantics into failures.
      case _ => l
    }

  private def sectionOf(args: List[String]): Section = {
    val n = args.headOption.getOrElse("").filter(_ != '"')
    val dataish = List(".data", ".bss", ".rodata", ".sdata", ".sbss", ".srodata")
    if (n.startsWith(".text")) { Section.Text }
    else if (dataish.exists(n.startsWith)) { Section.Data }
    else { Section.Other }
  }

  // Alignment padding is load-bearing in a data section. In `.text` every
  // instruction is four bytes and the base is 0, so anything up to four is a
  // no-op; a larger one would need padding, and dropping it silently shifts
  // nothing here while shifting everything on a real machine.
  private def align(l: Layout, args: List[String], to: Int => Int): Layout =
    args.headOption.flatMap(Parse.num) match {
      case None    => l
      case Some(n) => l.section match {
          case Section.Data => pad(l, math.max(1, to(n)))
          case Section.Text  => l
          case Section.Other => l
        }
    }

  private def pad(l: Layout, to: Int): Layout = {
    val over = l.data.length % to
    if (over == 0) { l } else { l.emit(Vector.fill(to - over)(0)) }
  }

  private def inData(l: Layout, loc: Loc, name: String)(f: Layout => Layout): Layout =
    l.section match {
      case Section.Data  => f(l)
      case Section.Other => l
      case Section.Text  => l.fail(loc, s"`$name` inside .text")
    }

  private def datum(l: Layout, loc: Loc, name: String, args: List[String], w: Int): Layout =
    inData(l, loc, name) { start =>
      args.foldLeft(start) { (acc, v) =>
        Parse.num(v) match {
          case Some(x) => acc.emit((0 until w).map(i => (x >>> (8 * i)) & 0xff))
          case None    => acc.fail(loc, s"`$name` wants a constant, got `$v`")
        }
      }
    }

  private def text(l: Layout, loc: Loc, name: String, args: List[String], nul: Boolean): Layout =
    inData(l, loc, name) { start =>
      args.foldLeft(start) { (acc, v) =>
        if (v.startsWith("\"") && v.endsWith("\"") && v.length >= 2) {
          acc.emit(unescape(v.drop(1).dropRight(1)) ++ (if (nul) { List(0) } else { Nil }))
        } else { acc.fail(loc, s"`$name` wants a quoted string, got `$v`") }
      }
    }

  private def zero(l: Layout, loc: Loc, name: String, args: List[String]): Layout =
    inData(l, loc, name) { start =>
      args.headOption.flatMap(Parse.num) match {
        case Some(n) => start.emit(Vector.fill(n)(0))
        case None    => start.fail(loc, s"`$name` wants a size")
      }
    }

  // `.comm name, size[, align]` declares a zero-filled object wherever it
  // appears, so it does not go through [inData].
  private def common(l: Layout, loc: Loc, args: List[String]): Layout = args match {
    case n :: size :: rest =>
      (Parse.num(size), rest.headOption.flatMap(Parse.num).getOrElse(4)) match {
        case (Some(sz), a) => {
          val at = pad(l, math.max(1, a))
          at.copy(dataSyms = at.dataSyms + (n -> at.data.length)).emit(Vector.fill(sz)(0))
        }
        case (None, _) => l.fail(loc, s"`.comm` wants a size, got `$size`")
      }
    case _ => l.fail(loc, "`.comm` wants a name and a size")
  }

  // Just enough of gas's string escapes for what a C compiler emits: octal, the
  // usual control characters, and escaped quotes.
  private val escapes: Map[Char, Int] =
    Map('n' -> 10, 't' -> 9, 'r' -> 13, 'b' -> 8, 'f' -> 12, 'a' -> 7, 'v' -> 11)

  private def unescape(s: String): List[Int] = {
    def go(cs: List[Char], acc: List[Int]): List[Int] = cs match {
      case Nil => acc.reverse
      case '\\' :: rest => {
        val (digits, tail) = rest.span(c => c >= '0' && c <= '7')
        if (digits.nonEmpty) {
          go(digits.drop(3) ++ tail, Integer.parseInt(digits.take(3).mkString, 8) :: acc)
        } else {
          rest match {
            case c :: t => go(t, escapes.getOrElse(c, c.toInt) :: acc)
            case Nil    => acc.reverse
          }
        }
      }
      case c :: rest => go(rest, c.toInt :: acc)
    }
    go(s.toList, Nil)
  }

  // Little-endian, the way RISC-V reads them, so `words(k)` is `mem[k]`.
  private def words(bytes: Vector[Int]): Vector[Int] =
    bytes
      .grouped(4)
      .map(g => g.zipWithIndex.foldLeft(0)((acc, p) => acc | ((p._1 & 0xff) << (8 * p._2))))
      .toVector

  private def equs(stmts: List[Stmt]): Map[String, Int] =
    stmts.collect {
      case Stmt(_, Form.Dir(".equ" | ".set", List(n, v))) => Parse.num(v).map(n -> _)
    }.flatten.toMap

  // The first symbol that is both `.globl` and `.type …,@function`, else `main`,
  // else index 0. The `@function` half is load-bearing on real output, where
  // `.globl secret` also appears and is `.type secret,@object`.
  private def entry(stmts: List[Stmt], entries: Map[String, Int]): Int = {
    val globls = stmts.collect { case Stmt(_, Form.Dir(".globl" | ".global", List(n))) => n }
    val funcs = stmts.collect {
      case Stmt(_, Form.Dir(".type", List(n, t))) if t == "@function" => n
    }.toSet
    globls.find(funcs.contains).flatMap(entries.get).orElse(entries.get("main")).getOrElse(0)
  }

  // Pass 2. Every hole sees its own index, which is what [Fixup.Rel] needs.
  private def link(
      slots: Vector[(Loc, Slot)],
      labels: Map[String, Int],
      addrs: Map[String, Int]
  ): (Vector[Instr], List[AsmError]) = {
    val filled = slots.zipWithIndex.map { case ((loc, slot), at) =>
      val i = slot match {
        case Slot.Fixed(i)      => Right(i)
        case Slot.Open(f, fill) => resolve(at, labels, addrs, f).map(fill)
      }
      i.flatMap(check).left.map(AsmError(loc, _))
    }
    (filled.collect { case Right(i) => i }, filled.collect { case Left(e) => e }.toList)
  }

  private def resolve(
      at: Int,
      labels: Map[String, Int],
      addrs: Map[String, Int],
      f: Fixup
  ): Either[String, Imm] = {
    def addr(s: String): Either[String, Int] = addrs.get(s).toRight(s"undefined symbol `$s`")

    f match {
      case Fixup.Lit(v) => Right(Imm(v))
      // [Exec.target] is `pc + offset.i / 4` with [pc] the branch's own index,
      // so the offset counts from the branch and not from what follows it.
      case Fixup.Rel(l, k) => labels.get(l) match {
          case Some(i) => Right(Imm(4 * (i - at) + k))
          case None if addrs.contains(l) =>
            Left(s"`$l` is not a label in .text, so it has no pc-relative offset")
          case None => Left(s"undefined label `$l`")
        }
      case Fixup.Abs(s, k) => addr(s).map(a => Imm(a + k))
      // [Exec] does the shifting, `write(s, rd, unit(imm.i << 12))`, so [Lui]
      // takes the unshifted twenty bits. The rounding here is what the
      // sign-extended `%lo` below cancels.
      case Fixup.Hi(s, k) => addr(s).map(a => Imm(((a + k + 0x800) >>> 12) & 0xfffff))
      case Fixup.Lo(s, k) => addr(s).map(a => Imm(((a + k) << 20) >> 20))
    }
  }

  // [Exec.target] `require`s four-byte alignment and would fail during staging,
  // where there is no source line left to point at.
  private def check(i: Instr): Either[String, Instr] = i match {
    case Instr.Branch(_, _, _, o) => range(i, o, -4096, 4094, true)
    case Instr.Jal(_, o)          => range(i, o, -1048576, 1048574, true)
    case Instr.Lui(_, o)          => range(i, o, -0x80000, 0xfffff, false)
    case Instr.Auipc(_, o)        => range(i, o, -0x80000, 0xfffff, false)
    // `SLL` and friends read only the low five bits, and [Exec] masks with 31,
    // so an unchecked shift of 32 would quietly mean a shift of zero.
    case Instr.OpImm(AluOp.Sll | AluOp.Srl | AluOp.Sra, _, _, o) => range(i, o, 0, 31, false)
    case Instr.OpImm(_, _, _, o) => range(i, o, -2048, 2047, false)
    case Instr.Load(_, _, _, o)  => range(i, o, -2048, 2047, false)
    case Instr.Store(_, _, _, o) => range(i, o, -2048, 2047, false)
    case Instr.Op(_, _, _, _)    => Right(i)
  }

  private def range(i: Instr, o: Imm, lo: Int, hi: Int, aligned: Boolean): Either[String, Instr] =
    if (o.i < lo || o.i > hi) { Left(s"immediate ${o.i} is outside [$lo, $hi]") }
    else if (aligned && o.i % 4 != 0) { Left(s"offset ${o.i} is not a multiple of 4") }
    else { Right(i) }
}
