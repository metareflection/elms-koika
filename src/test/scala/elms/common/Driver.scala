package elms.koika.test.common

import elms.prelude.*
import elms.prelude.given
import elms.codegen.CCodegen
import elms.pipeline.eqsat.Ruleset

abstract class DslDriver[A: Typable, B: Typable]
    extends OptimizingSnippetDriver[A, B](Ruleset(Seq())) with DslOps

abstract class GenericKoikaDriver[A: Typable, B: Typable] extends DslDriver[A, B] {
  override val codegen = CCodegen()

  val num_regs: Int = 8
  val mem_size: Int = 30
  val secret_size: Int = 10
  val secret_offset: Int = 20
  val cache_size: Int = 10

  val stateT: String = "StateT"

  // CR cwong: In theory, this should be derivable from the StateT manifest.
  // However, CBMC doesn't really like dealing with unknown-length arrays, so
  // for now we hardcode this. What we *should* do is introduce some kind of
  // `KnownLengthArray`.
  val stateTDef: String = s"""struct $stateT {
  |  int regs[NUM_REGS];
  |  int mem[MEM_SIZE];
  |  int saved_regs[NUM_REGS];
  |  int cache_keys[CACHE_LRU_SIZE];
  |  int cache_vals[CACHE_LRU_SIZE];
  |  int timer;
  |};""".stripMargin

  lazy val header: String = s"""
#define NUM_REGS $num_regs
#define MEM_SIZE $mem_size
#define SECRET_SIZE $secret_size
#define SECRET_OFFSET $secret_offset
#define CACHE_LRU_SIZE $cache_size
#ifndef CBMC
#define __CPROVER_assert(b,s) 0
#define nondet_uint() 0
#else
int nondet_uint();
#endif
int bounded(int low, int high) {
  int x = nondet_uint();
  __CPROVER_assume(low <= x && x <= high);
  return x;
}
$stateTDef
"""

  val init: String

  lazy val initialize_input: String =
    """
      |  int x = bounded(0, 20);
      |  s1.regs[0] = x;
      |  s2.regs[0] = x;""".stripMargin

  lazy val initialize_secret: String =
    """
      |  // initialize secret
      |  for (int i=0; i<SECRET_SIZE; i++) {
      |    s1.mem[SECRET_OFFSET+i] = bounded(0, 20);
      |    s2.mem[SECRET_OFFSET+i] = bounded(0, 20);
      |  }""".stripMargin

  lazy val main: String =
    s"""int main(int argc, char* argv[]) {
       |  struct $stateT s1, s2;
       |  init(&s1);
       |  init(&s2);
       |  $initialize_input
       |  $initialize_secret
       |  struct $stateT *s1_ = snippet(&s1);
       |  struct $stateT *s2_ = snippet(&s2);
       |  __CPROVER_assert(s1_->timer==s2_->timer, "timing leak");
       |  return 0;
       |}""".stripMargin

  override def code =
    s"""$header
       |$init
       |
       |/*****************************************
       |Emitting C Generated Code
       |*******************************************/
       |
       |${super.code}
       |
       |/*****************************************
       |End of C Generated Code
       |*******************************************/
       |
       |$main""".stripMargin
}
