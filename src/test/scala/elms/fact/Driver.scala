package elms.koika.test.fact

import elms.prelude.*
import elms.prelude.given

import elms.koika.test.riscv.{RiscV, RiscVDriver, elf}

// What the driver puts in an array before entry.
//
// The split is `test/ctverif_semantics.c`'s, which is where the FaCT suite
// writes its threat model down. A wrapper there reads
//
//   int32_t paramArrAccess_wrapper(const int32_t arr[5]) {
//       public_in(__SMACK_value(arr));
//       return paramArrAccess(arr);
//   }
//
// and `__SMACK_value(arr)` is the pointer rather than what it points at. So an
// array's base address is always public and identical in the two runs, and this
// is only about the contents.
enum Fill derives CanEqual {
  // A draw in each state. Whether the timer can tell them apart is the question.
  case Secret
  // One draw, written into both. The attacker chose it, and both runs face the
  // same attacker.
  case Public
  // Nothing. `init` has already zeroed `mem` and the function only writes here,
  // so a draw would be nondets CBMC carries around for no reason.
  case Out
}

// One parameter of a ported FaCT function, in the order the RISC-V calling
// convention puts them: a0, a1, and so on.
enum Param derives CanEqual {
  // A scalar in an argument register, drawn from `[0, bound]`.
  case Word(secret: Boolean, bound: Int)
  // A run of `mem`, whose base address is what the register holds.
  case Arr(words: Int, fill: Fill)
}

// A ported function and what its arguments mean. [name] is both the object file
// under `src/test/fact` and the label on the snapshot. [stack] is how many bytes
// of frame it spills, which the layout has to leave room for.
case class Program(name: String, params: List[Param], stack: Int) derives CanEqual

object Program {
  // Sizes are FaCT's, in words: `uint8[64]`, `uint8[16]`, `uint8[32]`.
  //
  // `input` is the nonce and counter, which the secretbox protocol around this
  // makes public. It is drawn as a secret anyway, because FaCT's own signature
  // says `secret uint8[16]` and because the stronger claim is the one worth
  // checking: nothing about either argument reaches the timer.
  val all: List[Program] = List(
    Program(
      "salsa20",
      List(
        Param.Arr(16, Fill.Out),
        Param.Arr(4, Fill.Secret),
        Param.Arr(8, Fill.Secret)
      ),
      stack = 96
    )
  )
}

// What the FaCT objects need that the RISC-V demos do not: somewhere to put an
// array, and a stack.
//
// The demos declare their globals and let the section headers place them, so
// [RiscVCompiledTests] can read a layout out of the image. A FaCT module has no
// globals at all; every array arrives as a pointer, and the caller is who
// decides where it points. That caller is this file.
//
// A class and not a trait, because [Common.prog] is a strict `val` and so has
// to read [program] while this constructor is still running. As a parameter it
// is set before the body; as an abstract member it would not be set until the
// subclass body ran, which is afterwards.
abstract class FactDriver(val program: Program) extends RiscVDriver {
  override val prog: Vector[RiscV.Instr] =
    elf.Elf.load(s"src/test/fact/${program.name}.o").prog

  // A parameter, the register it arrives in, and for an array the word of `mem`
  // where its contents start.
  private case class Slot(param: Param, reg: Int, at: Int)

  // a0 is regs[10], and arrays stack up from the bottom of `mem` in parameter
  // order. Nothing in the object constrains either choice.
  private lazy val slots: List[Slot] =
    program.params.zipWithIndex
      .foldLeft((List.empty[Slot], 0)) { case ((acc, free), (p, i)) =>
        val next = p match {
          case Param.Arr(n, _)  => free + n
          case Param.Word(_, _) => free
        }
        (acc :+ Slot(p, 10 + i, free), next)
      }
      ._1

  private lazy val argWords: Int =
    program.params.map { case Param.Arr(n, _) => n; case Param.Word(_, _) => 0 }.sum

  // Arguments from word 0 up, frame from the top down, and the default 30 words
  // is not enough for either. Rounded to a multiple of 16 so that the number in
  // the snapshot is a size rather than the exact sum of two accidents.
  override val mem_size: Int = {
    val need = argWords + (program.stack + 3) / 4
    math.max(30, ((need + 15) / 16) * 16)
  }

  // `mem` is word-indexed and the program does its own arithmetic in bytes.
  private def address(at: Int): Int = 4 * at

  private def public(s: Slot): String = s match {
    case Slot(Param.Arr(n, fill), r, at) => {
      val contents = fill match {
        case Fill.Public =>
          s"""
             |  // its contents, public: the same draw in both states
             |  for (int i=0; i<$n; i++) {
             |    int v = bounded(0, 20);
             |    s1.mem[$at + i] = v;
             |    s2.mem[$at + i] = v;
             |  }""".stripMargin
        case _ => ""
      }
      val what = if (fill == Fill.Out) { "written" } else { "read" }
      s"""
         |  // a$r, $n words $what by the callee: the address is public
         |  s1.regs[$r] = ${address(at)};
         |  s2.regs[$r] = ${address(at)};$contents""".stripMargin
    }
    case Slot(Param.Word(false, hi), r, _) =>
      s"""
         |  // a$r, public: one draw, written into both states
         |  int a$r = bounded(0, $hi);
         |  s1.regs[$r] = a$r;
         |  s2.regs[$r] = a$r;""".stripMargin
    case Slot(Param.Word(true, _), _, _) => ""
  }

  // Two draws. The whole question is whether the timer can tell them apart.
  private def secret(s: Slot): String = s match {
    case Slot(Param.Arr(n, Fill.Secret), r, at) =>
      s"""
         |  // a$r's contents, secret: a different draw in each state
         |  for (int i=0; i<$n; i++) {
         |    s1.mem[$at + i] = bounded(0, 20);
         |    s2.mem[$at + i] = bounded(0, 20);
         |  }""".stripMargin
    case Slot(Param.Word(true, hi), r, _) =>
      s"""
         |  // a$r, secret: a different draw in each state
         |  s1.regs[$r] = bounded(0, $hi);
         |  s2.regs[$r] = bounded(0, $hi);""".stripMargin
    case _ => ""
  }

  override lazy val initialize_input: String = slots.map(public).mkString
  override lazy val initialize_secret: String = slots.map(secret).mkString
}

// Each model zeroes whatever it has. The RISC-V suites spell these out once per
// file; naming them once here is what lets a model be a parameter instead.
object Init {
  private def body(stateT: String, saved: Boolean, cache: Boolean): String = {
    val savedRegs = if (saved) { "\n    s->saved_regs[i] = 0;" } else { "" }
    val lru =
      if (cache) {
        s"""
           |  for (int i=0; i<CACHE_LRU_SIZE; i++) {
           |    s->cache_keys[i] = -1;
           |    s->cache_vals[i] = -1;
           |  }""".stripMargin
      } else { "" }
    // The demos all fit in registers, so `sp` staying 0 never mattered and the
    // RISC-V suites never set it. A hundred lines of Salsa20 is 32 live values
    // on 32 registers and spills, so here the machine starts with a stack: `sp`
    // one past the top of `mem`, growing down toward the arguments at the
    // bottom. [FactDriver.mem_size] is what keeps the two from meeting.
    s"""void init(struct $stateT *s) {
       |  for (int i=0; i<NUM_REGS; i++) {
       |    s->regs[i] = 0;$savedRegs
       |  }
       |  s->regs[2] = 4 * MEM_SIZE;
       |  s->timer = 0;
       |  for (int i=0; i<MEM_SIZE; i++) {
       |    s->mem[i] = 0;
       |  }$lru
       |}""".stripMargin
  }

  def naive(stateT: String): String = body(stateT, saved = false, cache = false)
  def cache(stateT: String): String = body(stateT, saved = false, cache = true)
  def speculative(stateT: String): String = body(stateT, saved = true, cache = true)
}
