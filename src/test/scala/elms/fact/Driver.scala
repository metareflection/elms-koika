package elms.koika.test.fact

import elms.prelude.*
import elms.prelude.given

import elms.koika.test.Verdict
import elms.koika.test.common.Reach
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
//
// [bound] is the top of the range each word draws from, and it is load
// bearing rather than a knob. `fscalar_product` reads clean at 20 and leaks at
// `Int.MaxValue`, because the branch its verdict turns on is a carry out of a
// product, and products of small numbers do not carry. A bound chosen for
// checker cost is a bound that can answer the wrong question, so every port
// writes its own down.
enum Fill derives CanEqual {
  // A draw in each state, from `[0, bound]`. Whether the timer can tell them
  // apart is the question.
  case Secret(bound: Int)
  // One draw, written into both. The attacker chose it, and both runs face the
  // same attacker.
  case Public(bound: Int)
  // Nothing. `init` has already zeroed `mem` and the function only writes here,
  // so a draw would be nondets CBMC carries around for no reason.
  case Out
}

// One parameter of a ported FaCT function, in the order the RISC-V calling
// convention puts them: a0, a1, and so on.
enum Param derives CanEqual {
  // A scalar in an argument register, drawn from `[0, bound]`.
  case Word(secret: Boolean, bound: Int)
  // A `uint64`, which ilp32 passes in two registers, low half first. Each half
  // is its own draw from `[0, bound]`.
  case Wide(secret: Boolean, bound: Int)
  // A run of `mem`, whose base address is what the register holds.
  case Arr(words: Int, fill: Fill)
}

// What each model should say about a port, one field per column of the README's
// table.
//
// A verdict per model and not one, because `guarded` answers differently on
// each. FaCT's own claim is that the model does not matter, so a port that
// claim covers says [uniform]; anything else is a statement about where the
// claim stops.
//
// [static] is [predictive] with the history bits taken away, so the two sit
// next to each other and a port that answers differently on them is a port
// whose leak needed a trained predictor. [forwarding] is last because it
// extends [predictive] and so catches everything every column to its left
// catches, and the queue as well.
case class Expect(
    naive: Verdict,
    cache: Verdict,
    static: Verdict,
    predictive: Verdict,
    forwarding: Verdict
) derives CanEqual

object Expect {
  def uniform(v: Verdict): Expect = Expect(v, v, v, v, v)
}

// A ported function and what its arguments mean. [name] is both the object file
// under `src/test/fact` and the label on the snapshot. [stack] is how many bytes
// of frame it spills, which the layout has to leave room for.
//
// [klee] is a claim about the backend rather than about the program, which is
// why it sits beside [expect] rather than inside it: CBMC and Eva answer every
// port, and KLEE has a budget.
case class Program(
    name: String,
    params: List[Param],
    stack: Int,
    expect: Expect,
    klee: Reach = Reach.Settles
) derives CanEqual

object Program {
  // FaCT's `choose(secret bool cond, public uint32 a, public uint32 b)`, shared
  // because `choose.o` and `folded.o` are one source lowered two ways and so
  // take the same arguments. Only `cond` can move the timer, and only an object
  // that branches on it does.
  private val choose: List[Param] = List(
    Param.Word(secret = true, bound = 1),
    Param.Word(secret = false, bound = 20),
    Param.Word(secret = false, bound = 20)
  )

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
        Param.Arr(4, Fill.Secret(20)),
        Param.Arr(8, Fill.Secret(20))
      ),
      stack = 96,
      expect = Expect.uniform(Verdict.Clean)
    ),
    // Four leaves out of fact-eval's `crypto_secretbox`, which is the module
    // `salsa20` above was lifted out of by hand. These came out whole, one
    // `define` apiece, and `src/test/fact/extract` is what did it; the header
    // of each `.ll` names the module and the commit.
    //
    // Sizes and taint are read off each function's FaCT signature, quoted
    // above the entry. The signature is the only thing that says which argument
    // the author meant to be a secret, and guessing from the body is how a port
    // ends up proving something nobody claimed.
    //
    // `(secret mut uint8[32] out, secret uint8[16] input, secret uint8[32] k)`.
    // This is `salsa20` above with different numbers, and the only branch llc
    // emits is the ten-round loop counting against a trip count it set to 9.
    Program(
      "hsalsa20",
      List(
        Param.Arr(8, Fill.Out),
        Param.Arr(4, Fill.Secret(20)),
        Param.Arr(8, Fill.Secret(20))
      ),
      stack = 48,
      expect = Expect.uniform(Verdict.Clean)
    ),
    // `(secret mut uint32[16] ctx, secret uint8[32] k)`. Sixteen of the 20
    // frame words are a `public uint32[16]` permutation table, which `mem2reg`
    // leaves alone because it promotes scalars and not arrays. llc then folds
    // every read of it into a literal and the stores that fill it are dead, so
    // the frame is written once and never loaded.
    Program(
      "salsa_keysetup",
      List(Param.Arr(16, Fill.Out), Param.Arr(8, Fill.Secret(20))),
      stack = 80,
      expect = Expect.uniform(Verdict.Clean)
    ),
    // `(mut poly1305_state_internal_t state, secret uint8[32] key)`. The struct
    // is two `uint64[3]`, a `uint64[2]`, a `uint64`, a `uint8[16]` and one more
    // byte, which the 32-bit layout rounds to 96. `init` only writes it, down
    // to the `sb` at byte 88, so the whole 24 words draw as [Fill.Out].
    Program(
      "poly1305_init",
      List(Param.Arr(24, Fill.Out), Param.Arr(8, Fill.Secret(20))),
      stack = 0,
      expect = Expect.uniform(Verdict.Clean)
    ),
    // `secret bool _crypto_verify_16(secret uint8[16] x, secret uint8[16] y)`,
    // and the body of it is
    //
    //   for (uint32 i from 0 to 16) { if (x[i] != y[i]) { return false; } }
    //
    // which is `src/test/asm/riscv/cmp.c` with the names changed. That one
    // leaks on `naive`, with neither a cache nor a predictor in the model,
    // because clang stops the loop at the first mismatch and the trip count is
    // the secret. FaCT runs all sixteen iterations whatever the bytes are and
    // puts `xor`, `snez` and two `and`s where the early return was, so the only
    // branch in the object counts against a 15 that llc put in a register. One
    // algorithm, two compilers, opposite verdicts.
    //
    // This is the port that needed `factc -no-inline-asm`. FaCT's default
    // selection is an x86 `cmovnz` written as inline assembly and every `.ll`
    // fact-eval ships was built with it, which `llc` for riscv32 will not
    // take; `./factc --eval crypto_secretbox` is what rebuilt the module this
    // came out of.
    Program(
      "crypto_verify_16",
      List(Param.Arr(4, Fill.Secret(20)), Param.Arr(4, Fill.Secret(20))),
      stack = 0,
      expect = Expect.uniform(Verdict.Clean)
    ),
    // The gadget FaCT accepts, whose story is in `src/test/fact/guarded.fact`.
    // Words 0 to 15 are `table` and 16 to 23 are the key, and `idx` is drawn up
    // to 23 so that an out-of-bounds `table[idx]` reaches the key and stops
    // there. That is the bound `RiscVDriver.initialize_input` already draws
    // `spectre`'s index against, spelled in elements rather than bytes.
    Program(
      "guarded",
      List(
        Param.Word(secret = false, bound = 23),
        Param.Arr(16, Fill.Public(20)),
        Param.Arr(8, Fill.Secret(20)),
        Param.Arr(8, Fill.Out)
      ),
      stack = 0,
      expect =
        Expect(Verdict.Clean, Verdict.Clean, Verdict.Leak, Verdict.Leak, Verdict.Leak)
    ),
    // The pair `src/test/fact/choose.fact` exists for. One source, lowered once
    // as FaCT compiled it and once with one more optimizer pass, and the branch
    // that pass puts back is on a secret, so nothing has to speculate for the
    // timer to notice.
    Program("choose", choose, stack = 0, expect = Expect.uniform(Verdict.Clean)),
    Program("folded", choose, stack = 0, expect = Expect.uniform(Verdict.Leak)),
    // `folded` again with the optimizer replaced by the backend, and the story
    // is in `src/test/fact/fscalar_product.fact`. Five `uint64` limbs times a
    // `uint64` scalar is 22 `mul` and 21 `mulhu` on ilp32, which is why this
    // is the port RV32M exists for, and it is also four `beq`s: llc lowers a
    // 64-bit carry comparison as a branch, its arms differ by one `sltu`, and
    // the value it tests is a secret. Nobody wrote that branch. It leaks on
    // every column, including `naive`, which has neither a cache nor a
    // predictor in it.
    //
    // `Int.MaxValue` and not the 20 above it, because the bound is what makes
    // the verdict mean anything here. At 20 no product carries, all four
    // branches go the same way in both runs, and CBMC proves clean in four
    // seconds about a program whose only interesting path it was told to skip.
    Program(
      "fscalar_product",
      List(
        Param.Arr(10, Fill.Out),
        Param.Arr(10, Fill.Secret(Int.MaxValue)),
        Param.Wide(secret = true, bound = Int.MaxValue)
      ),
      stack = 16,
      expect = Expect.uniform(Verdict.Leak),
      // The only port that carries this, and the label was measured on
      // `naive`, the cheapest of the five cells. KLEE spent the whole 1200
      // seconds, halted on its own timer with 111 live states and no completed
      // path, and wrote no `.assert.err`: 46434 instructions and 21257 queries
      // in twenty minutes, which is a rate, not an answer.
      //
      // Why this one and not `folded`, which is the same leak. `folded` is
      // five instructions and the secret is one bit. Here the branch is four
      // deep in a 215-instruction residue, what it tests is a carry out of a
      // 64x64 product, and every operand is a full symbolic word.
      //
      // A run that does finish still has to say `leak`, which is what the
      // label buys: expensive rather than unreachable.
      klee = Reach.LikelyTimeout
    ),
    // `fscalar_product`'s two neighbours in `donna/curve25519-c64.fact`, and
    // the pair that says what in it leaks. These add and subtract the same
    // five `uint64` limbs and never leave 64 bits, where a carry is an `sltu`
    // and nothing branches. The accumulator above is `uint128`, llc lowers a
    // comparison at that width as a branch, and that is where its four `beq`s
    // came from.
    //
    // `(secret mut uint64[5] output, secret uint64[5] input)`, and `output` is
    // read as well as written: the body is `output[i] += input[i]`. So it is a
    // secret rather than a [Fill.Out], and the ten `lw`s off a0 in `fsum.s`
    // are what says so.
    Program(
      "fsum",
      List(Param.Arr(10, Fill.Secret(20)), Param.Arr(10, Fill.Secret(20))),
      stack = 0,
      expect = Expect.uniform(Verdict.Clean)
    ),
    // `(secret mut uint64[5] out, secret uint64[5] input)`, whose body is
    // `out[i] = input[i] + two54m8 - out[i]`. Same in-out first argument.
    Program(
      "fdifference_backwards",
      List(Param.Arr(10, Fill.Secret(20)), Param.Arr(10, Fill.Secret(20))),
      stack = 0,
      expect = Expect.uniform(Verdict.Clean),
      // The second port to carry this, and the one that shows the label is
      // about the backend and nothing else. CBMC answers all five cells in
      // 1.4 seconds or less apiece and Eva agrees, and KLEE closes only
      // `naive`, in 224 seconds of its 1200. The other four die on KLEE's
      // default 2GB cap after 26 seconds with 152 states killed, and at a 16GB
      // cap they spend a whole 720-second run without closing a path, so what
      // stops them is the search and not the memory.
      //
      // Nothing about the program says which of these it would be. `fsum` is
      // the same five limbs through the same models and settles everywhere in
      // seconds, and `hsalsa20` has four times the residue and settles too.
      // `FactNaiveTests` is where the one cell that answers gets its label
      // back.
      klee = Reach.LikelyTimeout
    ),
    // `(secret mut uint64[5] a, secret mut uint64[5] b, secret uint64 swapi)`,
    // the swap `cmult` drives the Montgomery ladder with, and the other port
    // `-no-inline-asm` unlocked. `swapi` is `byte >> 7` at both call sites, so
    // it draws against 1 the way `choose`'s condition does.
    //
    // FaCT's `if (swapi == 1)` is gone before llc sees it. The mask is one
    // `snez` and one `addi -1`, the body is four `xor`s and two `and`s a limb,
    // and the only branch left counts the five iterations.
    Program(
      "swap_conditional",
      List(
        Param.Arr(10, Fill.Secret(20)),
        Param.Arr(10, Fill.Secret(20)),
        Param.Wide(secret = true, bound = 1)
      ),
      stack = 0,
      expect = Expect.uniform(Verdict.Clean)
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
abstract class FactDriver(val program: Program) extends RiscVDriver[64] {
  override val prog: Vector[RiscV.Instr] =
    elf.Elf.load(s"src/test/fact/${program.name}.o").prog

  // A parameter, the register it arrives in, and for an array the word of `mem`
  // where its contents start.
  private case class Slot(param: Param, reg: Int, at: Int)

  // How many argument registers a parameter takes, and how many words of `mem`
  // its contents want.
  private def width(p: Param): (Int, Int) = p match {
    case Param.Arr(n, _)  => (1, n)
    case Param.Word(_, _) => (1, 0)
    case Param.Wide(_, _) => (2, 0)
  }

  // a0 is regs[10], and arrays stack up from the bottom of `mem` in parameter
  // order. Nothing in the object constrains either choice.
  private lazy val slots: List[Slot] =
    program.params
      .foldLeft((List.empty[Slot], 10, 0)) { case ((acc, reg, free), p) =>
        val (regs, words) = width(p)
        (acc :+ Slot(p, reg, free), reg + regs, free + words)
      }
      ._1

  // ilp32 wants a `uint64` in an *aligned* even-odd pair, so a [Param.Wide]
  // landing on an odd register is one the ABI would have pushed along by one.
  // Nothing ported so far does that, and guessing at the rule for a case
  // nothing exercises is how it comes out wrong.
  require(
    slots.collect { case Slot(Param.Wide(_, _), r, _) => r }.forall(_ % 2 == 0),
    s"${program.name} puts a uint64 on an odd register; ilp32 would skip one"
  )

  private lazy val argWords: Int = program.params.map(p => width(p)._2).sum

  // Arguments from word 0 up and the frame from the top down, which the 30
  // words the demos run on cannot hold between them. The length is pinned in
  // the type now, so this checks it rather than deriving one.
  require(
    argWords + (program.stack + 3) / 4 <= mem_size,
    s"${program.name} wants more than $mem_size words of memory"
  )

  // `mem` is word-indexed and the program does its own arithmetic in bytes.
  private def address(at: Int): Int = 4 * at

  private def public(s: Slot): String = s match {
    case Slot(Param.Arr(n, fill), r, at) => {
      val contents = fill match {
        case Fill.Public(hi) =>
          s"""
             |  // its contents, public: the same draw in both states
             |  for (int i=0; i<$n; i++) {
             |    int v = bounded(0, $hi);
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
    case Slot(Param.Wide(false, hi), r, _) =>
      s"""
         |  // a$r and a${r + 1}, public: a uint64's halves, one draw each,
         |  // written into both states
         |  int a$r = bounded(0, $hi);
         |  int a${r + 1} = bounded(0, $hi);
         |  s1.regs[$r] = a$r;
         |  s2.regs[$r] = a$r;
         |  s1.regs[${r + 1}] = a${r + 1};
         |  s2.regs[${r + 1}] = a${r + 1};""".stripMargin
    case Slot(Param.Word(true, _), _, _) => ""
    case Slot(Param.Wide(true, _), _, _) => ""
  }

  // Two draws. The whole question is whether the timer can tell them apart.
  private def secret(s: Slot): String = s match {
    case Slot(Param.Arr(n, Fill.Secret(hi)), r, at) =>
      s"""
         |  // a$r's contents, secret: a different draw in each state
         |  for (int i=0; i<$n; i++) {
         |    s1.mem[$at + i] = secret(0, $hi);
         |    s2.mem[$at + i] = secret(0, $hi);
         |  }""".stripMargin
    case Slot(Param.Word(true, hi), r, _) =>
      s"""
         |  // a$r, secret: a different draw in each state
         |  s1.regs[$r] = secret(0, $hi);
         |  s2.regs[$r] = secret(0, $hi);""".stripMargin
    case Slot(Param.Wide(true, hi), r, _) =>
      s"""
         |  // a$r and a${r + 1}, secret: a uint64's halves, drawn separately
         |  // in each state
         |  s1.regs[$r] = secret(0, $hi);
         |  s2.regs[$r] = secret(0, $hi);
         |  s1.regs[${r + 1}] = secret(0, $hi);
         |  s2.regs[${r + 1}] = secret(0, $hi);""".stripMargin
    case _ => ""
  }

  override lazy val initialize_input: String = slots.map(public).mkString
  override lazy val initialize_secret: String = slots.map(secret).mkString
}
