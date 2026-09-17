package elms.koika.test.common

// Each model zeroes whatever it has.
//
// Lived in the FaCT driver, where it was written so that a model could be a
// parameter instead of a copied string, while the eight other suites went on
// spelling it out apiece. A cache with five arrays in it rather than two is
// what finally made eight copies untenable.
object Init {
  // Every frame starts empty, and -1 is what says so: a line number no address
  // can name, so the tag comparison never matches one.
  //
  // The old model spelled that `cache_keys[i] = -1` too, and then wrote an
  // evicted line back without checking it, so a cold miss stored through
  // `s->mem[-1]`, which given `int regs[NUM_REGS]; int mem[MEM_SIZE];` is the
  // last register. Every CBMC run passes `--no-standard-checks`, which turns off
  // exactly the array-bounds property that would have caught it.
  private val lru =
    """
      |  for (int i=0; i<CACHE_ENTRIES; i++) {
      |    s->cache_tags[i] = -1;
      |    s->cache_dirty[i] = 0;
      |    s->cache_age[i] = 0;
      |  }
      |  for (int i=0; i<CACHE_WORDS; i++) {
      |    s->cache_vals[i] = 0;
      |  }""".stripMargin

  // [stack] points `sp` one past the top of `mem`, growing down toward the
  // arguments at the bottom. The demos all fit in registers, so `sp` staying 0
  // never mattered to them; a hundred lines of Salsa20 is 32 live values on 32
  // registers and spills. [FactDriver.mem_size] is what keeps the two from
  // meeting.
  private def body(
      stateT: String,
      saved: Boolean,
      cache: Boolean,
      stack: Boolean,
      ready: Boolean = false
  ): String = {
    val savedRegs = if (saved) { "\n    s->saved_regs[i] = 0;" } else { "" }
    // Every register starts available. Zero is before the program begins, so
    // nothing waits on a value it never read.
    val regReady = if (ready) { "\n    s->reg_ready[i] = 0;" } else { "" }
    val sp = if (stack) { "\n  s->regs[2] = 4 * MEM_SIZE;" } else { "" }
    val lines = if (cache) { lru } else { "" }
    s"""void init(struct $stateT *s) {
       |  for (int i=0; i<NUM_REGS; i++) {
       |    s->regs[i] = 0;$savedRegs$regReady
       |  }$sp
       |  s->timer = 0;
       |  for (int i=0; i<MEM_SIZE; i++) {
       |    s->mem[i] = 0;
       |  }$lines
       |}""".stripMargin
  }

  def naive(stateT: String): String = body(stateT, saved = false, cache = false, stack = false)
  def cache(stateT: String): String = body(stateT, saved = false, cache = true, stack = false)
  def speculative(stateT: String): String = body(stateT, saved = true, cache = true, stack = false)
  // The queue is staging-time, so this model's state is [Predictive]'s.
  def forwarding(stateT: String): String = speculative(stateT)
  def nonblocking(stateT: String): String =
    body(stateT, saved = false, cache = true, stack = false, ready = true)

  // Every field there is, for a suite that runs one program against several
  // models. Which fields a model leaves untouched is not what [RiscVBranchyTests]
  // is measuring, and a per-model initializer there would only make its six
  // residues differ in a line none of them reads.
  def all(stateT: String): String =
    body(stateT, saved = true, cache = true, stack = false, ready = true)

  // The same four, for a program that spills.
  object Spilling {
    def naive(stateT: String): String = body(stateT, saved = false, cache = false, stack = true)
    def cache(stateT: String): String = body(stateT, saved = false, cache = true, stack = true)
    def speculative(stateT: String): String =
      body(stateT, saved = true, cache = true, stack = true)
    def forwarding(stateT: String): String = speculative(stateT)
  }
}
