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
  Static,
  StateT
}

// What each model should say about a variant, one field per column of the
// README's table.
//
// Seven and not five, which is where this differs from `fact/Driver.scala`'s
// version of the same idea. The FaCT ports are about a type system's guarantee
// and answer the same on both halves of the load pipeline; these are about
// speculation, and [nonblocking] is the column that says a model can reorder
// loads without ever running the wrong instruction.
case class Expect(
    naive: Verdict,
    cache: Verdict,
    static: Verdict,
    predictive: Verdict,
    forwarding: Verdict,
    nonblocking: Verdict,
    predictive_nb: Verdict
) derives CanEqual

object Expect {
  def uniform(v: Verdict): Expect = Expect(v, v, v, v, v, v, v)
}

// One ported variant: the object under `src/test/asm/riscv/pht`, what the
// caller leaves in a0 onward, and what each model owes.
case class Variant(name: String, args: List[Arg], expect: Expect) derives CanEqual

object Variant {
  // Every variant takes the attacker's index. `Arg.Index` is what draws it far
  // enough past `publicarray` to reach `secretarray`, which the image says and
  // nothing here repeats.
  private val index: List[Arg] = List(Arg.Index("x"))

  // Three of the six are clean on every model, the speculative ones included,
  // and each is clean for a reason of its own. The reasons are one shape: a
  // window is a straight line of [speculable] instructions from the branch, so
  // whatever control flow a compiler left between the guard and the gadget
  // ends the window before the gadget runs. Each variant below says which
  // piece of control flow it was, which is what the corpus is for.
  //
  // It used to be four. A window also ended on a write to one of the
  // condition's own registers, and since a bounds check compares the index and
  // the body's first move is to scale it, that ended every one of these at the
  // first instruction. `v20` is the row that came back when it stopped.
  private val stopsShort: Expect = Expect.uniform(Verdict.Clean)

  val all: List[Variant] = List(
    // The index is computed branchlessly, so there is no bounds check to run
    // ahead of and `x + 1` walks one word past the end on its own. The only
    // variant here whose leak is already there before anything speculates and
    // still needs a cache to be seen.
    Variant(
      "v08",
      index,
      Expect(
        naive = Verdict.Clean,
        cache = Verdict.Leak,
        static = Verdict.Leak,
        predictive = Verdict.Leak,
        forwarding = Verdict.Leak,
        nonblocking = Verdict.Leak,
        predictive_nb = Verdict.Leak
      )
    ),
    // The leak is the inner branch, and a window cannot open inside a window.
    // The secret does arrive in a0 speculatively, and the only thing left in
    // the window to do with it is the test that closes the window.
    //
    // `k` is the attacker's guess at the byte, so it is public and drawn the
    // way the other demos draw an attacker's word.
    Variant("v10", index :+ Arg.Word("k", 20), stopsShort),
    // The guard reads the array it is guarding, so the out-of-bounds load is
    // architectural and `naive` already has it.
    Variant("v17", index, Expect.uniform(Verdict.Leak)),
    // Nothing on the architectural path and a straight run from the guard to
    // the probe, so this is the row a Spectre-PHT variant is supposed to have.
    // It is `riscv/spectre`'s row cell for cell, which is the control these
    // six were ported to get: the gadget somebody wrote by hand for this model
    // and the gadget clang emitted answer the same under all seven models.
    Variant(
      "v20",
      index,
      Expect(
        naive = Verdict.Clean,
        cache = Verdict.Clean,
        static = Verdict.Leak,
        predictive = Verdict.Leak,
        forwarding = Verdict.Leak,
        nonblocking = Verdict.Clean,
        predictive_nb = Verdict.Clean
      )
    ),
    // `v20` with the attacker's probe after it, which is the one demo here
    // that is not one of the 27. `riscv/reload` is `riscv/spectre` the same
    // way, and for the same reason: a victim function never probes anything,
    // so a tower whose observation is the victim's own clock cannot see a line
    // nothing asks about. The two columns it moves against `v20` are the
    // answer to whether the line was there.
    Variant(
      "v20r",
      index,
      Expect(
        naive = Verdict.Clean,
        cache = Verdict.Clean,
        static = Verdict.Leak,
        predictive = Verdict.Leak,
        forwarding = Verdict.Leak,
        nonblocking = Verdict.Clean,
        predictive_nb = Verdict.Leak
      )
    ),
    // The secret-dependent address is the second iteration's, and reaching it
    // means going round the loop's backward branch. The first iteration reads
    // the secret and ands it into an accumulator, which is a value and not an
    // address, so the window ends holding something no timer can see.
    Variant("v21", index, stopsShort),
    // The `j` that joins the switch's two arms sits between the guard and the
    // gadget, and an unconditional jump is not [speculable] either.
    Variant("v25", index, stopsShort)
  )
}

// A class and not a trait for the reason `FactDriver` is one: [objectFile]
// reads [variant], and a constructor parameter is set before the body where an
// abstract member would not be.
//
// One `init` for all seven models rather than the four the per-model suites
// spell out between them. These variants exist to be compared across the
// columns, and which fields a model leaves untouched is not the comparison.
abstract class PhtDriver(val variant: Variant)
    extends RiscVDriver[64]
    with CompiledShell[StateT[32, 64, 24, 12]] {
  override def objectFile: String = s"src/test/asm/riscv/pht/${variant.name}.o"
  override def args: List[Arg] = variant.args
  override val init = Init.all(stateT)
}

// Eva's answer where it is not [Verdict]'s. A may-analysis over one run taints
// a load it cannot bound and never untaints it, so a secret that reaches a
// branch or an address at all is a leak to Eva whether or not the arithmetic
// can tell the two runs apart.
//
// Which it does split on is where the secret went. `v10` and `v21` put it in a
// branch condition, and taint follows that whether or not the model has a
// cache. `v20` and `v25` put it in an address, which can only move a clock
// that has a cache behind it, so under `naive` those two come back clean to
// Eva as well. `v08` and `v17` leak, and a leak has nothing to widen.
//
// At file scope rather than in the suites, because `@virtualize` claims any
// `if` in the class it annotates and then cannot find a `unit` to build one
// out of.
private val branchers = Set("v10", "v21")
private val addressers = Set("v20", "v20r", "v25")

private def eva(v: Variant, says: Verdict, cached: Boolean): Taint =
  if (says == Verdict.Leak) { Taint.Agrees }
  else if (branchers(v.name) || (cached && addressers(v.name))) { Taint.Widens }
  else { Taint.Agrees }

// Six of Kocher's Spectre v1 variants, ported in `src/test/asm/riscv/pht`, run
// against every model the tree has, and a seventh that is `v20` with the
// attacker's probe on the end.
//
// Three more of them are already here under other names and are not re-ported.
// `spectre.s` is variant 1 written by hand, `fact/guarded` is variant 1 reached
// through a program FaCT's type system accepts, and `fact/folded` is the
// secret-dependent branch variant 8 arrives at through a ternary. `reload.s`
// is `spectre.s` probed, which is what `v20r` is to `v20`.
//
// Held back from a default `verify` on volume: 147 files for one family, none
// of which is a verdict the tree cannot already state. `src/out/*/verify
// --corpus` is what checks them, alongside the Spectre-STL ports under `stl/`,
// which are held back for the same reason.

@virtualize
class PhtNaiveTests extends KoikaSuite {
  val under = "pht/naive/"

  for (v <- Variant.all) {
    test(s"pht naive ${v.name}") {
      val snippet = new PhtDriver(v) {}
      val says = v.expect.naive
      check(v.name, snippet, says, eva = eva(v, says, cached = false))
    }
  }
}

@virtualize
class PhtCacheTests extends KoikaSuite {
  val under = "pht/cache/"

  for (v <- Variant.all) {
    test(s"pht cache ${v.name}") {
      val snippet = new PhtDriver(v) with Cached {}
      val says = v.expect.cache
      check(v.name, snippet, says, eva = eva(v, says, cached = true))
    }
  }
}

@virtualize
class PhtStaticTests extends KoikaSuite {
  val under = "pht/static/"

  for (v <- Variant.all) {
    test(s"pht static ${v.name}") {
      val snippet = new PhtDriver(v) with Static {}
      val says = v.expect.static
      check(v.name, snippet, says, eva = eva(v, says, cached = true))
    }
  }
}

@virtualize
class PhtPredictiveTests extends KoikaSuite {
  val under = "pht/predictive/"

  for (v <- Variant.all) {
    test(s"pht predictive ${v.name}") {
      val snippet = new PhtDriver(v) with Predictive {}
      val says = v.expect.predictive
      check(v.name, snippet, says, eva = eva(v, says, cached = true))
    }
  }
}

@virtualize
class PhtForwardingTests extends KoikaSuite {
  val under = "pht/forwarding/"

  for (v <- Variant.all) {
    test(s"pht forwarding ${v.name}") {
      val snippet = new PhtDriver(v) with Forwarding {}
      val says = v.expect.forwarding
      check(v.name, snippet, says, eva = eva(v, says, cached = true))
    }
  }
}

@virtualize
class PhtNonBlockingTests extends KoikaSuite {
  val under = "pht/nonblocking/"

  for (v <- Variant.all) {
    test(s"pht nonblocking ${v.name}") {
      val snippet = new PhtDriver(v) with NonBlocking {}
      val says = v.expect.nonblocking
      check(v.name, snippet, says, eva = eva(v, says, cached = true))
    }
  }
}

@virtualize
class PhtPredictiveNonBlockingTests extends KoikaSuite {
  val under = "pht/predictive_nb/"

  for (v <- Variant.all) {
    test(s"pht predictive_nb ${v.name}") {
      val snippet = new PhtDriver(v) with PredictiveNonBlocking {}
      val says = v.expect.predictive_nb
      check(v.name, snippet, says, eva = eva(v, says, cached = true))
    }
  }
}
