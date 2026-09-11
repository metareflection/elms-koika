package elms.koika.test.riscv

import elms.prelude.*
import elms.prelude.given

import elms.koika.test.KoikaSuite
import elms.koika.test.common.Speculative
import elf.{Datum, Taint}

// A program that came out of a C compiler rather than out of someone's head.
// The C, the command that compiled it, and why it is `-O1` are all in
// `src/test/asm/riscv/cmp.c`.
@virtualize
class RiscVCompiledTests extends KoikaSuite {
  val under = "riscv/compiled/"

  private val image = elf.Elf.load("src/test/asm/riscv/cmp.o")

  trait CompiledDriver extends RiscVDriver {
    override val prog = image.prog

    private def base(d: Datum): Int = d.addr / 4
    private def length(d: Datum): Int = d.size / 4
    private def span(d: Datum): Range = base(d) until (base(d) + length(d))

    // Sorted by address, because a [Map]'s iteration order would otherwise put
    // the register writes in the generated C in `hashCode` order.
    private def tainted(t: Taint): Seq[(String, Datum)] =
      image.globals.toSeq.filter((_, d) => d.taint == t).sortBy((_, d) => d.addr)

    private val secrets = tainted(Taint.Secret)
    private val attackers = tainted(Taint.Attacker)

    // Words a `bounded(…)` is about to write, so the image's own bytes for them
    // are noise. Emitting them anyway is how the hand-written version came to
    // set `mem[0..3] = 11, 22, 33, 44` and then bury them one line later.
    private val nondet: Set[Int] =
      (secrets ++ attackers).flatMap((_, d) => span(d)).toSet

    // `init` zeroes `mem`, so only the nonzero words need writing.
    private val publicData: String = {
      val lines = image.data.zipWithIndex
        .filter((w, i) => w != 0 && !nondet(i))
        .map((w, i) => s"  s1.mem[$i] = $w;\n  s2.mem[$i] = $w;")
      if (lines.isEmpty) { "" }
      else { s"\n  // public data, where the section headers put it\n${lines.mkString("\n")}" }
    }

    // One draw, written into both states. The attacker chose it, and both runs
    // face the same attacker.
    private def shared(name: String, d: Datum): String =
      s"""
         |  // $name, the attacker's: the same draw in both states
         |  for (int i=0; i<${length(d)}; i++) {
         |    int v = bounded(0, 20);
         |    s1.mem[${base(d)} + i] = v;
         |    s2.mem[${base(d)} + i] = v;
         |  }""".stripMargin

    // Two draws. The whole question is whether the timer can tell them apart.
    private def split(name: String, d: Datum): String =
      s"""
         |  // $name, secret: a different draw in each state
         |  for (int i=0; i<${length(d)}; i++) {
         |    s1.mem[${base(d)} + i] = bounded(0, 20);
         |    s2.mem[${base(d)} + i] = bounded(0, 20);
         |  }""".stripMargin

    // `cmp`'s argument is how many words to compare. Both arrays are the same
    // length, so the attacker's own size is the bound; anything larger walks
    // off the end of a global.
    private val bound: Int = attackers.map((_, d) => length(d)).minOption.getOrElse(0)

    // `n` in a0 and `guess` in memory are both public, so they are identical in
    // the two runs and only the secret differs. Folded in here rather than
    // given its own hook, because `main` already interpolates this string.
    override lazy val initialize_input: String =
      s"""$publicData
         |  int n = bounded(0, $bound);
         |  s1.regs[10] = n;
         |  s2.regs[10] = n;${attackers.map(shared).mkString}""".stripMargin

    override lazy val initialize_secret: String = secrets.map(split).mkString
  }

  test("riscv compiled naive") {
    val snippet = new CompiledDriver {
      override val init = s"""void init(struct $stateT *s) {
           |  for (int i=0; i<NUM_REGS; i++) {
           |    s->regs[i] = 0;
           |  }
           |  s->timer = 0;
           |  for (int i=0; i<MEM_SIZE; i++) {
           |    s->mem[i] = 0;
           |  }
           |}""".stripMargin
    }
    check("naive", snippet.code)
  }

  test("riscv compiled speculative") {
    val snippet = new CompiledDriver with Speculative {
      override val init = s"""void init(struct $stateT *s) {
           |  for (int i=0; i<NUM_REGS; i++) {
           |    s->regs[i] = 0;
           |    s->saved_regs[i] = 0;
           |  }
           |  s->timer = 0;
           |  for (int i=0; i<MEM_SIZE; i++) {
           |    s->mem[i] = 0;
           |  }
           |  for (int i=0; i<CACHE_LRU_SIZE; i++) {
           |    s->cache_keys[i] = -1;
           |    s->cache_vals[i] = -1;
           |  }
           |}""".stripMargin
    }
    check("speculative", snippet.code)
  }
}
