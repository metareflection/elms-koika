package elms.koika.test.riscv

import elms.prelude.*
import elms.prelude.given

import elms.koika.test.{KoikaSuite, Verdict}
import elms.koika.test.common.Reach
import elms.koika.test.common.Cached as DirectCached
import elms.koika.test.squared.Cached as SquaredCached

// How far up the dial a default KLEE run goes, and the reason it is a
// file-scope definition rather than a method on the suite: `@virtualize`
// rewrites every `if` in the class it annotates into a staged one, and this
// one is about which label to write.
//
// Measured rather than guessed, at the 1200s budget these files carry. On an
// idle box the self-composed column runs 3.9s, 27.5s and 156.2s at one through
// three. Four is 929s against the squared column's 606s, taken with one other
// job on the machine, and five and six have not been seen to finish. So four
// is where a default run stops being something to spend on this.
private def probeReach(k: Int): Reach =
  if (k >= 4) Reach.LikelyTimeout else Reach.Settles

// The probe-count dial, run through both constructions at every setting.
//
// `riscv/cache/branchy` is the one demo in this tree whose bill is a path space
// rather than a formula, and until now its four probes were written out in the
// assembly, so the size of that space was not something anyone could vary
// without editing a `.s` and rebuilding. Every statement about how a checker
// scales was therefore a statement about two points measured months apart.
// `probe.s` is that demo with the count as a `--defsym`, and this suite stages
// it at one through six under the two towers that answer the same question.
//
// Both columns are clean at every k, and that is the arrangement rather than a
// result: a program with nothing to report is a program whose checker has to
// clear the whole space instead of stopping at the first witness. Which is what
// makes the pair a measurement of cost.
//
// `self/k4` and `riscv/cache/branchy` are the same program at the same size,
// which is the control saying the dial reproduces the demo it generalizes.
@virtualize
class RiscVProbeTests extends KoikaSuite {
  val under = "probe/"

  // One object per k, assembled by `src/test/asm/riscv/build`. Widening this
  // means widening `PROBE_COUNTS` there too, and a missing object aborts with
  // the script's name rather than with a decode error.
  private val counts = 1 to 6

  for (k <- counts) {
    // `BranchyDriver` brings `branchy.s`'s own `initialize_input`, which seeds
    // the walk's indices into registers rather than into `mem`, and its `init`.
    // `probe.s` wants both and differs only in how many probes follow.
    test(s"riscv probe self $k") {
      val snippet = new BranchyDriver with DirectCached {
        override val prog = demo(s"probe$k")
      }
      check(s"self/k$k", snippet, Verdict.Clean, klee = probeReach(k))
    }

    test(s"riscv probe squared $k") {
      val snippet = new SquaredBranchyDriver with SquaredCached {
        override val prog = demo(s"probe$k")
      }
      check(s"squared/k$k", snippet, Verdict.Clean, klee = probeReach(k))
    }
  }
}
