package elms.koika.test.riscv

import elms.prelude.*
import elms.prelude.given

import elms.koika.test.KoikaSuite
import elms.koika.test.common.Speculative

// A program that came out of a C compiler rather than out of someone's head.
// The C, the command that compiled it, and why it is `-O1` are all in
// `src/test/asm/riscv/cmp.c`.
@virtualize
class RiscVCompiledTests extends KoikaSuite {
  val under = "riscv/compiled/"

  private val image = asm.Asm.load("src/test/asm/riscv/cmp.s")

  // `secret` and `guess` are both `int[4]` in the C.
  private val words = 4

  trait CompiledDriver extends RiscVDriver {
    override val prog = image.prog

    // The assembler decided where the globals went, so the driver asks it
    // rather than pinning `secret` to `SECRET_OFFSET`. That is what keeps the
    // frontend from needing a way to place a symbol.
    private val secretWord = image.symbols("secret") / 4
    private val guessWord = image.symbols("guess") / 4

    // `init` zeroes `mem`, so only the nonzero words of the image need writing.
    private val data = image.data.zipWithIndex
      .filter((w, _) => w != 0)
      .map((w, i) => s"  s1.mem[$i] = $w;\n  s2.mem[$i] = $w;")
      .mkString("\n")

    // `n` in a0 and `guess` in memory are both public, so they are identical in
    // the two runs and only the secret differs. Folded in here rather than
    // given its own hook, because `main` already interpolates this string.
    override lazy val initialize_input: String =
      s"""
         |  // the data section, where the assembler put it
         |$data
         |  int n = bounded(0, $words);
         |  s1.regs[10] = n;
         |  s2.regs[10] = n;
         |  for (int i=0; i<$words; i++) {
         |    int g = bounded(0, 20);
         |    s1.mem[$guessWord + i] = g;
         |    s2.mem[$guessWord + i] = g;
         |  }""".stripMargin

    override lazy val initialize_secret: String =
      s"""
         |  // initialize secret
         |  for (int i=0; i<$words; i++) {
         |    s1.mem[$secretWord + i] = bounded(0, 20);
         |    s2.mem[$secretWord + i] = bounded(0, 20);
         |  }""".stripMargin
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
