package elms.koika.test.common

import elms.prelude.*
import elms.prelude.given
import elms.codegen.CCodegen
import elms.core.StructManifest
import elms.pipeline.eqsat.Ruleset

abstract class DslDriver[A: Typable, B: Typable]
    extends OptimizingSnippetDriver[A, B](Ruleset(Seq())) with DslOps

// [R] registers, [M] words of memory and [C] cache lines, fixed here because
// this is the last place that can see all three at once: the struct members get
// them from [State], and the `#define`s the hand-written C reads get them from
// `valueOf`. One literal each, so the two cannot drift.
abstract class GenericKoikaDriver[R <: Int: ValueOf, M <: Int: ValueOf, C <: Int: ValueOf]
    extends DslDriver[StateT[R, M, C], StateT[R, M, C]] with StateTOps {
  override type State = StateT[R, M, C]
  override given stateManifest: StructManifest[State] = StateT.manifest

  override val codegen = CCodegen()

  // Final, because the struct's members are already laid out at these lengths
  // and an override would only desync the `#define`s from them.
  final val num_regs: Int = valueOf[R]
  final val mem_size: Int = valueOf[M]
  final val cache_size: Int = valueOf[C]
  val secret_size: Int = 10
  val secret_offset: Int = 20

  val stateT: String = "StateT"

  // The struct itself comes out of the generator, which reads the same three
  // lengths off [State]. These are for the hand-written C around it. A model
  // that needs state of its own appends here.
  def defines: Seq[(String, Int)] = Seq(
    "NUM_REGS" -> num_regs,
    "MEM_SIZE" -> mem_size,
    "SECRET_SIZE" -> secret_size,
    "SECRET_OFFSET" -> secret_offset,
    "CACHE_LRU_SIZE" -> cache_size
  )

  lazy val header: String = s"""
${defines.map((k, v) => s"#define $k $v").mkString("\n")}
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

  // [init] and [main] come after the generated code and not before it, because
  // `struct StateT` is now the generator's to declare and both of them
  // dereference one.
  override def code =
    s"""$header
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
       |$init
       |
       |$main""".stripMargin
}
