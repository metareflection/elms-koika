package elms.koika.test.common

// A checker the residue can be handed to.
//
// The residue body is the same text under every backend. What differs is the
// four macros it reaches the checker through, where its snapshot lands, and
// which `verify` script reads a verdict out of that snapshot. Adding a backend
// is adding a case here.
enum Prover derives CanEqual {
  case CBMC
  case KLEE
  case EVA

  // Snapshot root. A subtree each, so a `verify` globbing `**/*.check.c` from
  // where it sits is never handed a file spelled for the other backend.
  def root: String = this match {
    case CBMC => "src/out/cbmc/"
    case KLEE => "src/out/klee/"
    case EVA  => "src/out/eva/"
  }

  // The `-D` the snapshot's intrinsics are guarded by. Undefined, a snapshot
  // still compiles and runs natively with its assertions stubbed out, which is
  // what the `#else` arm in [prelude] is for.
  def guard: String = toString

  // What the checker prints for a residue whose assertion holds, and for one
  // where it does not.
  //
  // For whoever reads the snapshot. `verify` takes its verdict from an exit
  // code, an error file or a log line, so nothing depends on this text.
  //
  // Eva's wording is a property's status and not a sentence, because Eva never
  // reports a leak. It fails to prove one is absent, and `unknown` is the word
  // it uses for that.
  def holds: String = this match {
    case CBMC => "VERIFICATION SUCCESSFUL"
    case KLEE => "no failing assertion"
    case EVA  => "untainted_timer: Valid"
  }

  def fails: String = this match {
    case CBMC => "VERIFICATION FAILED"
    case KLEE => "a failing assertion"
    case EVA  => "untainted_timer: unknown"
  }

  // The enabled arm of [prelude]: how this checker spells an assertion, an
  // assumption, a draw from the nondeterministic input, and the mark that says
  // a draw was the secret one.
  private def intrinsics: String = this match {
    case CBMC =>
      """int nondet_uint();
        |#define koika_assert(b, s) __CPROVER_assert(b, s)
        |#define koika_assume(b) __CPROVER_assume(b)
        |#define koika_draw(x) ((x) = nondet_uint())
        |#define koika_secret(x) ((void)0)""".stripMargin

    // The message is dropped, because KLEE reports a failing assertion by file
    // and line rather than by name. Two assertions in one residue stay
    // distinguishable; which of them fired just comes out of the `.err` file
    // instead of out of the string.
    case KLEE =>
      """#include <assert.h>
        |#include <klee/klee.h>
        |#define koika_assert(b, s) klee_assert(b)
        |#define koika_assume(b) klee_assume(b)
        |#define koika_draw(x) klee_make_symbolic(&(x), sizeof(x), #x)
        |#define koika_secret(x) ((void)0)""".stripMargin

    // Nothing here asserts, because the assertion is not a macro's to make.
    // ACSL is a C comment, and `main` writes the one this backend reads,
    // `//@ assert untainted_timer:` beside the timer comparison. That is text
    // every backend gets and only this one treats as more than a comment, so
    // `koika_assert` is where CBMC and KLEE put a checker and where Eva puts
    // nothing.
    //
    // One obligation per residue and not one per slot, even under the squared
    // and lockstep towers, which assert on the way into every slot. Those
    // comparisons are there to prune a search and to say which slot a drift
    // began in, and both are worth paying for only to a checker that decides
    // whether the timers can differ. Taint asks whether the secret arrives at
    // all, which the end of the run answers as well as the middle does.
    //
    // `koika_mark` is the source and has to stay a declaration, since `taints`
    // is a clause about a function and nothing generated writes one.
    // `assigns \nothing` only silences the warning Eva prints when it has to
    // assume a declaration writes everything.
    //
    // `koika_assume` aborting is the other half. Eva drops the states that
    // reach `Frama_C_abort`, which is what an assumption does, so the shared
    // `bounded` reduces here the same way it does under the other two. The
    // abort branch is bottom rather than joined, so an assumption on a
    // tainted condition does not taint everything after it either.
    case EVA =>
      """#include "__fc_builtin.h"
        |/*@ assigns *p \from \nothing;
        |    taints *p; */
        |void koika_mark(int *p);
        |#define koika_assert(b, s) ((void)0)
        |#define koika_assume(b) do { if (!(b)) Frama_C_abort(); } while (0)
        |#define koika_draw(x) ((x) = Frama_C_interval(-2147483647-1, 2147483647))
        |#define koika_secret(x) koika_mark(&(x))""".stripMargin
  }

  // Everything the generated code and the hand-written C around it need before
  // either can be compiled.
  //
  // Only [intrinsics] differs between backends. `bounded`, `secret` and the
  // stubbed arm are shared text, which is what makes two snapshots of one demo
  // diff down to this block.
  def prelude: String =
    s"""#ifdef $guard
       |$intrinsics
       |#else
       |#define koika_assert(b, s) 0
       |#define koika_assume(b) 0
       |#define koika_draw(x) ((x) = 0)
       |#define koika_secret(x) ((void)0)
       |#endif
       |int bounded(int low, int high) {
       |  int x;
       |  koika_draw(x);
       |  koika_assume(low <= x && x <= high);
       |  return x;
       |}
       |// Same draw as `bounded`, said of the secret, so a backend that tracks
       |// where the secret goes has somewhere to start. Self-composition already
       |// encodes the split by drawing these twice, which is why the mark is
       |// nothing under a checker that reads the two runs exactly.
       |int secret(int low, int high) {
       |  int x = bounded(low, high);
       |  koika_secret(x);
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
  //
  // Which is what happened. Every file carrying this now finishes at
  // [budgetSeconds], `riscv/cache/branchy` in 814s of the 1200, and the label
  // was measured at 120 and 600. So it currently means expensive rather than
  // unreachable, and it is kept for what `verify` does with it: fourteen
  // minutes apiece is not something a default run should spend.
  case LikelyTimeout
}

object Reach {
  // What `verify` gives KLEE per file, written onto the line so the script does
  // not have to hold an opinion.
  //
  // This was 120 and the comment said slack rather than measurement, because
  // every residue KLEE finished did so in under a second. A set-associative
  // cache ended that. `fact/static/guarded` now takes 326s and
  // `riscv/forwarding/bypass` 485s, both of them leaks KLEE does find and was
  // simply being cut off before it could: a budget that small turned "not yet"
  // into a failing test.
  //
  // A cap and not a cost, so the files that settled in under a second still do,
  // and the only ones that spend most of it are the ones marked [LikelyTimeout]
  // and skipped by default. The headroom over 570 is deliberate, since that number
  // was measured on a loaded machine and a budget that a slower box fails is a
  // flake rather than a claim.
  val budgetSeconds: Int = 1200
}
