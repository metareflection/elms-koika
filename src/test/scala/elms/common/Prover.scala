package elms.koika.test.common

// A checker the residue can be handed to.
//
// The residue body is the same text under every backend. What differs is the
// three macros it reaches the checker through, where its snapshot lands, and
// which `verify` script reads a verdict out of that snapshot. Adding a backend
// is adding a case here.
enum Prover derives CanEqual {
  case CBMC
  case KLEE

  // Snapshot root. A subtree each, so a `verify` globbing `**/*.check.c` from
  // where it sits is never handed a file spelled for the other backend.
  def root: String = this match {
    case CBMC => "src/out/cbmc/"
    case KLEE => "src/out/klee/"
  }

  // The `-D` the snapshot's intrinsics are guarded by. Undefined, a snapshot
  // still compiles and runs natively with its assertions stubbed out, which is
  // what the `#else` arm in [prelude] is for.
  def guard: String = toString

  // What the checker prints for a residue whose assertion holds, and for one
  // where it does not.
  //
  // For whoever reads the snapshot. `verify` takes its verdict from an exit
  // code or an error file, so nothing depends on this text.
  def holds: String = this match {
    case CBMC => "VERIFICATION SUCCESSFUL"
    case KLEE => "no failing assertion"
  }

  def fails: String = this match {
    case CBMC => "VERIFICATION FAILED"
    case KLEE => "a failing assertion"
  }

  // The enabled arm of [prelude]: how this checker spells an assertion, an
  // assumption, and a draw from the nondeterministic input.
  private def intrinsics: String = this match {
    case CBMC =>
      """int nondet_uint();
        |#define koika_assert(b, s) __CPROVER_assert(b, s)
        |#define koika_assume(b) __CPROVER_assume(b)
        |#define koika_draw(x) ((x) = nondet_uint())""".stripMargin

    // The message is dropped, because KLEE reports a failing assertion by file
    // and line rather than by name. Two assertions in one residue stay
    // distinguishable; which of them fired just comes out of the `.err` file
    // instead of out of the string.
    case KLEE =>
      """#include <assert.h>
        |#include <klee/klee.h>
        |#define koika_assert(b, s) klee_assert(b)
        |#define koika_assume(b) klee_assume(b)
        |#define koika_draw(x) klee_make_symbolic(&(x), sizeof(x), #x)""".stripMargin
  }

  // Everything the generated code and the hand-written C around it need before
  // either can be compiled.
  //
  // Only [intrinsics] differs between backends. `bounded` and the stubbed arm
  // are shared text, which is what makes two snapshots of one demo diff down
  // to this block.
  def prelude: String =
    s"""#ifdef $guard
       |$intrinsics
       |#else
       |#define koika_assert(b, s) 0
       |#define koika_assume(b) 0
       |#define koika_draw(x) ((x) = 0)
       |#endif
       |int bounded(int low, int high) {
       |  int x;
       |  koika_draw(x);
       |  koika_assume(low <= x && x <= high);
       |  return x;
       |}""".stripMargin
}

// Whether KLEE is expected to get through a residue's path space.
//
// [Verdict] is a claim about the program and every backend that finishes agrees
// on it. This is a claim about the backend, and `branchy` under a cache is the
// only demo that needs one.
//
// Not because of its path space, which is small: `runCache` answers out of L1,
// out of L2 or out of memory, so four probes are (3^4 + 1) / 2 paths and CBMC
// is done in 1.4s. What KLEE cannot get through is a single one of them. A
// set-indexed cache subscripts every array with an expression nobody knows, so
// each step of each path is a query over a chain of updates at unknown indices,
// and the count at the end of a two-minute run is 0 completed paths against 23
// partially completed. Ten minutes does not change it, which is what separates
// this from [budgetSeconds] and the leaks that were merely being cut off.
//
// `naive/branchy` walks the same four addresses with nothing in front of
// memory and settles, which is the control for all of that.
//
// CBMC needs no equivalent, since it finishes every residue in the tree and
// `verify --certify` is what checks its bound. A second symbolic executor is
// when this stops being a KLEE-shaped parameter.
enum Reach derives CanEqual {
  // KLEE walks the whole space, and what it finds has to be [Verdict].
  case Settles

  // KLEE probably runs out of budget first, and `verify` skips these unless
  // asked for them.
  //
  // "Likely" and not "does", because a run that does finish still has to agree
  // with [Verdict]. What this says is that not finishing is not a failure, so a
  // faster solver or a smaller demo turns one of these green rather than
  // breaking it.
  case LikelyTimeout
}

object Reach {
  // What `verify` gives KLEE per file, written onto the line so the script does
  // not have to hold an opinion.
  //
  // This was 120 and the comment said slack rather than measurement, because
  // every residue KLEE finished did so in under a second. A set-associative
  // cache ended that. `fact/speculative/guarded` now takes 275s and
  // `riscv/forwarding/bypass` 570s, both of them leaks KLEE does find and was
  // simply being cut off before it could: a budget that small turned "not yet"
  // into a failing test.
  //
  // A cap and not a cost, so the files that settled in under a second still do,
  // and the only ones that spend it are the ones marked [LikelyTimeout] and
  // skipped by default. The headroom over 570 is deliberate, since that number
  // was measured on a loaded machine and a budget that a slower box fails is a
  // flake rather than a claim.
  val budgetSeconds: Int = 1200
}
