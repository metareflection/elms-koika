package elms.koika.test.riscv

import elms.prelude.*
import elms.prelude.given

import elms.koika.test.{KoikaSuite, Taint, Verdict}
import elms.koika.test.common.{
  Cached,
  Forwarding,
  Init,
  NonBlocking,
  Predictive,
  PredictiveNonBlocking,
  Reach,
  Static
}

// Five Spectre-STL litmus shapes, ported in `src/test/asm/riscv`, run against
// every model the tree has.
//
// Kocher's variants cover Spectre-PHT and nothing equivalent existed for v4,
// which is why Daniel, Bardin and Rezk wrote these for *Hunting the Haunter*
// (NDSS 2021) alongside the Haunted RelSE checker. They follow Kocher's
// philosophy for PHT by way of Pitchfork's adaptation of it
// (github.com/cdisselkoen/pitchfork, `new-testcases/spectrev1.c`, from Cauligi
// et al., *Constant-Time Foundations for the New Spectre Era*, PLDI 2020), and
// what is ported here is `src/litmus-stl/programs/spectrev4.c` from
// github.com/binsec/haunted_bench.
//
// Each `.s` file carries its case number, which is what keeps that
// correspondence findable, and says what the port had to change. The originals
// pin a value into `edx` to force the distinction between an index that lives
// in a register and one that goes through the stack; RV32I has no such idiom,
// so the ports are hand-written and spell the distinction out in
// instructions.
//
// What they add comes in two parts. `stale_ptr`, `stale_mask` and `stale_index`
// bypass a sanitizer, which nothing in the tree did before: every store-queue
// gadget here bypasses a scrub, a zero written over the secret word, and
// `bypass.s` reads that word anyway. These three never touch the secret. What
// the store was about to fix is the pointer, the mask or the selector that
// decides where the load goes, and the queue cannot tell that from a scrub.
//
// `inflight` and `retired` are the other two and are the scrub again, as a
// pair. The only thing that differs between the two files is how many
// `addi x0, x0, 0` sit between the store and the load. `Forwarding.storeWindow`
// is 4, so the load is at distance 1 in one and distance 5 in the other, which
// measures the window from inside a program rather than reading it off the
// model.
//
// The `insecure` and `secure` labels the originals carry in comments are
// measured against gcc-10.2.0 -O0 -m32 on a real machine, so they are not
// predictions about a tower with a two-bit store-queue tag, a four-instruction
// window and twelve cache frames. Nothing below was seeded from them. Every
// `leak` is a pair of secrets [SquaredRunSuite] witnessed before CBMC was
// asked, and every `clean` is CBMC's.
//
// Derived separately they agree anyway, and where they agree is the result.
// The original calls cases 5, 6, 7 and 9bis insecure and case 9 secure, and so
// does the `forwarding` column, five for five. The other six columns call all
// five clean, which is the same table saying those labels describe a machine
// with a store queue rather than a program.
//
// `retired` is the narrowest of the five agreements, because the two answers
// come from different mechanisms. The original earns `secure` from a
// 200-iteration loop retiring the store; this port earns it from four
// `addi x0, x0, 0`, since a backward branch is not `speculable` and a loop here
// would end the window at the jump rather than at `storeWindow`.
//
// Held back from a default `verify`, both towers, and `src/out/*/verify
// --corpus` is what checks them. Sixty files per backend and 180 across the
// three, and not one of them a verdict the tree cannot already state: the four
// that leak do it in the column `bypass` already leaks in. KLEE gives the
// sharper reason. `stale_ptr` and `stale_index` produce no verdict at all in
// this tower, and the four cells that do settle cost between 112 and 354
// seconds apiece, so a default run reaching them would spend most of six
// budgets on answers CBMC has in thirty seconds.
//
// `--corpus` and not `--full`, which holds back something else: `lockstep/` is
// a second opinion, `dynamic/` is an open question and `probe/` is a scaling
// study. These are a corpus, and a corpus is for reading across.
//
// [SquaredStlSuite] is the other tower's half and reads the table below rather
// than keeping one of its own.
object Stl {
  // Four of the five answer alike in all seven columns, which is the corpus's
  // claim rather than a redundancy in it: these shapes need a store queue, and
  // every model to the left of one commits a store where it stands and so has
  // nothing to read around. There is no branch in any of the five programs, so
  // the two predictors have nothing to mispredict either.
  private val queued: Expect = Expect(
    naive = Verdict.Clean,
    cache = Verdict.Clean,
    static = Verdict.Clean,
    predictive = Verdict.Clean,
    forwarding = Verdict.Leak,
    nonblocking = Verdict.Clean,
    predictive_nb = Verdict.Clean
  )

  // [Expect] is `pht.scala`'s, one field per column of the README's table.
  val all: List[(String, Expect)] = List(
    "stale_ptr" -> queued,
    "stale_mask" -> queued,
    "stale_index" -> queued,
    "inflight" -> queued,
    // The half of the pair where the store has landed. Clean everywhere, and
    // that includes the column that reports the other four, which is the whole
    // reason it is here.
    "retired" -> Expect.uniform(Verdict.Clean)
  )

  // Where Eva reports a leak the program does not have, measured by
  // `src/out/eva/verify` rather than reasoned out.
  //
  // Two of the five and not all of them. `inflight.s` and `retired.s` scrub the
  // secret word and then read that same word back, so the load's address is the
  // secret's whatever the store did with the value, and from there the taint is
  // on the channel. Whether the zero that came back could have moved a clock is
  // the question Eva does not ask. The three `stale_*` shapes never load through
  // the secret's address at all once the store has committed, which is what
  // every model but `forwarding` does, so there is nothing to start a taint
  // from.
  //
  // And nothing widens under `naive`, where an address has no cache behind it
  // and so cannot reach the timer at all. Both towers run the same rule, which
  // is why it lives here rather than in either suite.
  private val scrubbed = Set("inflight", "retired")

  def eva(name: String, says: Verdict, cached: Boolean): Taint =
    if (says == Verdict.Leak) { Taint.Agrees }
    else if (cached && scrubbed(name)) { Taint.Widens }
    else { Taint.Agrees }

  // Where `src/out/klee/verify` comes back with nothing, which is two cells
  // rather than six and only in the single tower.
  //
  // `verify` passes `--exit-on-error` as of this landing, and that is what
  // moved. KLEE finds the witness in these and then prints `now ignoring this
  // error at this location` and carries on through a space that may never
  // close, so before the flag the verdict was written to `klee-out` and nobody
  // read it. All nine residues in the tree declaring `leak` have since been run
  // with it, and five stop at their witness: the three squared shapes here at
  // 112, 125 and 209 seconds, `stl/forwarding/stale_mask` at 354, and
  // `squared/riscv/forwarding/bypass_late` at 108 next door.
  //
  // The two left are `stale_ptr` and `stale_index` single-tower, which found
  // nothing at all inside 360 seconds while their squared twins are the cheap
  // ones. That is backwards from the file sizes and backwards from
  // `bypass_alias`, where the single tower settles in 89 seconds and the
  // squared one does not finish even with the flag. Two shapes, opposite
  // directions, and nothing anybody has named predicts the sign.
  //
  // Both carry the label on a 360-second run rather than on the 1200 they
  // declare, so whether they settle inside their own budget is open. That run
  // is for whoever has the machine the full sweep goes on.
  private val hangs = Set("stale_ptr", "stale_index")

  // The tower is a parameter here where it is not in [eva], because
  // `--exit-on-error` split the two halves apart and nothing about the shape
  // says which way a given cell goes.
  def klee(name: String, squared: Boolean): Reach =
    if (!squared && hangs(name)) { Reach.LikelyTimeout } else { Reach.Settles }
}

// A class and not a trait for the reason [PhtDriver] is one: [prog] reads
// [name], and a constructor parameter is set before the body where an abstract
// member would not be.
//
// One `init` for all seven models rather than the four the per-model suites
// spell out between them. These exist to be compared across the columns, and
// which fields a model leaves untouched is not the comparison.
abstract class StlDriver(val name: String) extends RiscVDriver[64] {
  override val prog = demo(name)
  override val init = Init.all(stateT)
}

@virtualize
class StlNaiveTests extends KoikaSuite {
  val under = "stl/naive/"

  for ((name, expect) <- Stl.all) {
    test(s"stl naive $name") {
      val snippet = new StlDriver(name) {}
      val says = expect.naive
      check(name, snippet, says, eva = Stl.eva(name, says, cached = false))
    }
  }
}

@virtualize
class StlCacheTests extends KoikaSuite {
  val under = "stl/cache/"

  for ((name, expect) <- Stl.all) {
    test(s"stl cache $name") {
      val snippet = new StlDriver(name) with Cached {}
      val says = expect.cache
      check(name, snippet, says, eva = Stl.eva(name, says, cached = true))
    }
  }
}

@virtualize
class StlStaticTests extends KoikaSuite {
  val under = "stl/static/"

  for ((name, expect) <- Stl.all) {
    test(s"stl static $name") {
      val snippet = new StlDriver(name) with Static {}
      val says = expect.static
      check(name, snippet, says, eva = Stl.eva(name, says, cached = true))
    }
  }
}

@virtualize
class StlPredictiveTests extends KoikaSuite {
  val under = "stl/predictive/"

  for ((name, expect) <- Stl.all) {
    test(s"stl predictive $name") {
      val snippet = new StlDriver(name) with Predictive {}
      val says = expect.predictive
      check(name, snippet, says, eva = Stl.eva(name, says, cached = true))
    }
  }
}

@virtualize
class StlForwardingTests extends KoikaSuite {
  val under = "stl/forwarding/"

  for ((name, expect) <- Stl.all) {
    test(s"stl forwarding $name") {
      val snippet = new StlDriver(name) with Forwarding {}
      val says = expect.forwarding
      check(name, snippet, says, klee = Stl.klee(name, squared = false), eva = Stl.eva(name, says, cached = true))
    }
  }
}

@virtualize
class StlNonBlockingTests extends KoikaSuite {
  val under = "stl/nonblocking/"

  for ((name, expect) <- Stl.all) {
    test(s"stl nonblocking $name") {
      val snippet = new StlDriver(name) with NonBlocking {}
      val says = expect.nonblocking
      check(name, snippet, says, eva = Stl.eva(name, says, cached = true))
    }
  }
}

@virtualize
class StlPredictiveNonBlockingTests extends KoikaSuite {
  val under = "stl/predictive_nb/"

  for ((name, expect) <- Stl.all) {
    test(s"stl predictive_nb $name") {
      val snippet = new StlDriver(name) with PredictiveNonBlocking {}
      val says = expect.predictive_nb
      check(name, snippet, says, eva = Stl.eva(name, says, cached = true))
    }
  }
}
