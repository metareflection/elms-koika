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

  // What `--unwind` has to clear before the residue's own recursion is even the
  // question. Every loop in the hand-written C around the residue counts to one
  // of these four, and CBMC wants the exit test as well as the body.
  //
  // Fall short and a `clean` verdict is a statement about a program CBMC never
  // finished looking at, which is why `verify --certify` exists. A demo whose
  // recursion runs deeper than its loops overrides this.
  def unwind: Int = Seq(num_regs, mem_size, cache_size, secret_size).max + 1

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

  def header(prover: Prover): String =
    s"""${defines.map((k, v) => s"#define $k $v").mkString("\n")}
       |
       |${prover.prelude}""".stripMargin

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

  // Takes the prover only so [Lockstepped] can, which needs it for the two
  // helpers it declares. Nothing here does.
  def main(prover: Prover): String =
    s"""int main(int argc, char* argv[]) {
       |  struct $stateT s1, s2;
       |  init(&s1);
       |  init(&s2);
       |  $initialize_input
       |  $initialize_secret
       |  struct $stateT *s1_ = snippet(&s1);
       |  struct $stateT *s2_ = snippet(&s2);
       |  koika_assert(s1_->timer==s2_->timer, "timing leak");
       |  return 0;
       |}""".stripMargin

  // Memoized, because [SnippetDriver.code] stages `snippet` into the builder
  // as a side effect of rendering it and [render] now runs once per backend.
  override lazy val code: String = super.code

  // [init] and [main] come after the generated code and not before it, because
  // `struct StateT` is now the generator's to declare and both of them
  // dereference one.
  def render(prover: Prover): String =
    s"""${header(prover)}
       |
       |/*****************************************
       |Emitting C Generated Code
       |*******************************************/
       |
       |$code
       |
       |/*****************************************
       |End of C Generated Code
       |*******************************************/
       |
       |$init
       |
       |${main(prover)}""".stripMargin
}
