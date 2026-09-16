package elms.koika.test.common

// Each model zeroes whatever it has.
//
// This lived in the FaCT driver, where it was written so that a model could be
// a parameter rather than a copied string, while nine other suites went on
// spelling the same three loops out apiece. Naming them once here is the same
// idea applied to the rest of the tree: what a model initializes is a fact
// about the model, and it should be written down once per model rather than
// once per suite.
object Init {
  private val lru =
    """
      |  for (int i=0; i<CACHE_LRU_SIZE; i++) {
      |    s->cache_keys[i] = -1;
      |    s->cache_vals[i] = -1;
      |  }""".stripMargin

  // [stack] points `sp` one past the top of `mem`, growing down toward the
  // arguments at the bottom. The demos all fit in registers, so `sp` staying 0
  // never mattered to them; a hundred lines of Salsa20 is 32 live values on 32
  // registers and spills. [FactDriver.mem_size] is what keeps the two from
  // meeting.
  private def body(stateT: String, saved: Boolean, cache: Boolean, stack: Boolean): String = {
    val savedRegs = if (saved) { "\n    s->saved_regs[i] = 0;" } else { "" }
    val sp = if (stack) { "\n  s->regs[2] = 4 * MEM_SIZE;" } else { "" }
    val lines = if (cache) { lru } else { "" }
    s"""void init(struct $stateT *s) {
       |  for (int i=0; i<NUM_REGS; i++) {
       |    s->regs[i] = 0;$savedRegs
       |  }$sp
       |  s->timer = 0;
       |  for (int i=0; i<MEM_SIZE; i++) {
       |    s->mem[i] = 0;
       |  }$lines
       |}""".stripMargin
  }

  def naive(stateT: String): String = body(stateT, saved = false, cache = false, stack = false)
  def cache(stateT: String): String = body(stateT, saved = false, cache = true, stack = false)
  def speculative(stateT: String): String =
    body(stateT, saved = true, cache = true, stack = false)
  // The queue is staging-time, so this model's state is [Speculative]'s.
  def forwarding(stateT: String): String = speculative(stateT)

  // The same four, for a program that spills.
  object Spilling {
    def naive(stateT: String): String = body(stateT, saved = false, cache = false, stack = true)
    def cache(stateT: String): String = body(stateT, saved = false, cache = true, stack = true)
    def speculative(stateT: String): String =
      body(stateT, saved = true, cache = true, stack = true)
    def forwarding(stateT: String): String = speculative(stateT)
  }
}
