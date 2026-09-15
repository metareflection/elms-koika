package elms.koika.test.common

import elms.prelude.*
import elms.prelude.given
import elms.core.tree as ast

// [GenericKoikaDriver] with the residue put through [Lockstep].
//
// The two states are built the way every model already builds them, one at a
// time through its own `init`, and the product is two pointers at them. Nothing
// is copied and nothing here knows which fields a given model bothers to
// initialize.
trait Lockstepped[R <: Int: ValueOf, M <: Int: ValueOf, C <: Int: ValueOf]
    extends GenericKoikaDriver[R, M, C] {
  private def state = stateManifest.repr
  private def paired = Lockstep.pair(state)

  override def extract(): ast.Program =
    Lockstep.run(state, clock = "timer")(super.extract())

  // Declared by the generated code, defined here, because a `#define` would be
  // macro-expanded into the prototype `CCodegen` emits for it.
  override lazy val main: String =
    s"""void lockstep_assert(bool c) { __CPROVER_assert(c, "lockstep drift"); }
       |void lockstep_assume(bool c) { __CPROVER_assume(c); }
       |
       |int main(int argc, char* argv[]) {
       |  struct $stateT s1, s2;
       |  init(&s1);
       |  init(&s2);
       |  $initialize_input
       |  $initialize_secret
       |  struct ${paired.name} p = { .a = &s1, .b = &s2 };
       |  struct ${paired.name} *p_ = snippet(&p);
       |  __CPROVER_assert(p_->a->timer==p_->b->timer, "timing leak");
       |  return 0;
       |}""".stripMargin
}
