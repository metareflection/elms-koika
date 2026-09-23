package elms.koika.test.common

import elms.prelude.*
import elms.prelude.given
import elms.codegen.CCodegen
import elms.core.StructManifest
import elms.pipeline.eqsat.Ruleset

abstract class DslDriver[A: Typable, B: Typable]
    extends OptimizingSnippetDriver[A, B](Ruleset(Seq())) with DslOps

// [R] registers, [M] words of memory, [C] words of cache data and [T] cache
// entries, fixed here because this is the last place that can see all four at
// once: the struct members get them from [State], and the `#define`s the
// hand-written C reads get them from `valueOf`. One literal each, so the two
// cannot drift.
//
// [S] is what a slot is handed. One state for a model that runs once, and a
// pair of them for the lockstep tower next door. Everything below is the C
// around the residue and does not care which: `main` is the one thing that
// does, and it is overridable for exactly that reason.
abstract class KoikaDriver[
    R <: Int: ValueOf,
    M <: Int: ValueOf,
    C <: Int: ValueOf,
    T <: Int: ValueOf,
    S
](using repr: StructManifest[S]) extends DslDriver[S, S] {
  type State = S
  given stateManifest: StructManifest[State] = repr

  override val codegen = CCodegen()

  // Final, because the struct's members are already laid out at these lengths
  // and an override would only desync the `#define`s from them.
  final val num_regs: Int = valueOf[R]
  final val mem_size: Int = valueOf[M]
  final val cache_words: Int = valueOf[C]
  final val cache_entries: Int = valueOf[T]
  val secret_size: Int = 10
  val secret_offset: Int = 20

  // The shape [Cached] reads, declared here because this is where the lengths
  // it has to agree with are. A model with no cache in it still has one, which
  // costs nothing: [Direct] never asks.
  def geometry: Geometry = Geometry.default

  // Two lengths in the type and two in the geometry, and nothing else would
  // notice them disagreeing. The struct would be laid out at one size and
  // indexed at another, which in C is a read of the member after it rather
  // than a failure.
  //
  // Lazy and forced from [defines] rather than run in the constructor, because
  // [geometry] is overridable and a subclass's override is not initialized
  // while this class's body is still running.
  private lazy val checked: Unit = {
    require(
      geometry.words == cache_words && geometry.entries == cache_entries,
      s"${geometry.describe} wants ${geometry.entries} entries of ${geometry.words}" +
        s" words, and the state has $cache_entries of $cache_words"
    )
    // A secret that straddles a line boundary is a demo whose verdict is about
    // where it happened to land, so the offset is line-aligned and says so.
    require(
      secret_offset % geometry.lineWords == 0,
      s"secret_offset $secret_offset is not a multiple of ${geometry.lineWords} words"
    )
  }

  val stateT: String = "StateT"

  // What `--unwind` has to clear before the residue's own recursion is even the
  // question. Every loop in the hand-written C around the residue counts to one
  // of these four, and CBMC wants the exit test as well as the body.
  //
  // Fall short and a `clean` verdict is a statement about a program CBMC never
  // finished looking at, which is why `verify --certify` exists. A demo whose
  // recursion runs deeper than its loops overrides this.
  def unwind: Int =
    Seq(num_regs, mem_size, cache_words, cache_entries, secret_size).max + 1

  // The struct itself comes out of the generator, which reads the same four
  // lengths off [State]. These are for the hand-written C around it. A model
  // that needs state of its own appends here.
  def defines: Seq[(String, Int)] = {
    checked
    Seq(
      "NUM_REGS" -> num_regs,
      "MEM_SIZE" -> mem_size,
      "SECRET_SIZE" -> secret_size,
      "SECRET_OFFSET" -> secret_offset,
      "CACHE_ENTRIES" -> cache_entries,
      "CACHE_WORDS" -> cache_words
    )
  }

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

  // Takes the prover only so [SquaredKoikaDriver] can, which needs it for the
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

// The tower's own driver: one state in, one state out, and the two runs
// compared by `main` after the residue has been called twice.
abstract class GenericKoikaDriver[
    R <: Int: ValueOf,
    M <: Int: ValueOf,
    C <: Int: ValueOf,
    T <: Int: ValueOf
] extends KoikaDriver[R, M, C, T, StateT[R, M, C, T]] with StateTOps
