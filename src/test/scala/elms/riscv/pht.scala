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

  // Four of the six are clean on every model, the speculative ones included,
  // and that is a fact about the tower rather than about them.
  //
  // [Predictive.run] closes a window on any instruction that writes a register
  // the pending condition reads, because [evalCond] runs at resolution against
  // the live register file. A bounds check compares the index, and the first
  // thing a body does with an index is scale it, so a register allocator
  // writes the scaled value back into the register the compare just read:
  //
  //   bgeu a0, a1, .exit
  //   slli a0, a0, 2
  //
  // The window closes on that second line with nothing saved and nothing
  // speculated. `v21` gets four instructions further and still stops two short
  // of the load. Identical at -O1, -O2, -Os and -O3, so it is the shape of the
  // gadget and not a choice of flags.
  //
  // `spectre.s` is the same gadget by hand and it leaks, because the hand that
  // wrote it branched on x10 and x15 and then touched x5, x11 and x12. That is
  // the difference these six are here to show: a gadget written for this model
  // against a gadget written by a compiler that cannot see it.
  //
  // A machine reads a branch's operands when the branch issues, so the rule
  // costs leaks rather than inventing them, and every `leak` already in the
  // tree stands. Fixing it moves snapshots in seven other suites, so it is its
  // own change rather than this one.
  private val windowCloses: Expect = Expect.uniform(Verdict.Clean)

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
    // `k` is the attacker's guess at the byte, so it is public and drawn the
    // way the other demos draw an attacker's word.
    Variant("v10", index :+ Arg.Word("k", 20), windowCloses),
    // The guard reads the array it is guarding, so the out-of-bounds load is
    // architectural and `naive` already has it.
    Variant("v17", index, Expect.uniform(Verdict.Leak)),
    Variant("v20", index, windowCloses),
    Variant("v21", index, windowCloses),
    Variant("v25", index, windowCloses)
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
// a load it cannot bound and never untaints it, so a secret that reaches an
// address or a branch at all is a leak to Eva whether or not the arithmetic
// can tell the two runs apart.
//
// The four [Variant.windowCloses] variants are exactly the four it widens,
// which is the shape to expect: a window closing is a fact about the model,
// and where a program's values go is not. `v08` and `v17` leak outright, so
// there is nothing left for Eva to widen.
//
// A map rather than a test on the name, because `@virtualize` claims any `if`
// in a suite body and then cannot find a `unit` to build one out of.
private val widens: Map[String, Taint] =
  Map("v10" -> Taint.Widens, "v20" -> Taint.Widens, "v21" -> Taint.Widens, "v25" -> Taint.Widens)

// Two of them rather than four, because without a cache the probe's address
// cannot move the clock at all. `v10` and `v21` branch on the loaded value,
// which is the one thing taint does follow.
private val widensNaive: Map[String, Taint] =
  Map("v10" -> Taint.Widens, "v21" -> Taint.Widens)

// Six of Kocher's Spectre v1 variants, ported in `src/test/asm/riscv/pht`, run
// against every model the tree has.
//
// Three more of them are already here under other names and are not re-ported.
// `spectre.s` is variant 1 written by hand, `fact/guarded` is variant 1 reached
// through a program FaCT's type system accepts, and `fact/folded` is the
// secret-dependent branch variant 8 arrives at through a ternary.
//
// Held back from a default `verify` on cost: 126 files for one family, none of
// which is a verdict the tree cannot already state. `src/out/*/verify --full`
// is what checks them.

@virtualize
class PhtNaiveTests extends KoikaSuite {
  val under = "pht/naive/"

  for (v <- Variant.all) {
    test(s"pht naive ${v.name}") {
      val snippet = new PhtDriver(v) {}
      check(v.name, snippet, v.expect.naive, eva = widensNaive.getOrElse(v.name, Taint.Agrees))
    }
  }
}

@virtualize
class PhtCacheTests extends KoikaSuite {
  val under = "pht/cache/"

  for (v <- Variant.all) {
    test(s"pht cache ${v.name}") {
      val snippet = new PhtDriver(v) with Cached {}
      check(v.name, snippet, v.expect.cache, eva = widens.getOrElse(v.name, Taint.Agrees))
    }
  }
}

@virtualize
class PhtStaticTests extends KoikaSuite {
  val under = "pht/static/"

  for (v <- Variant.all) {
    test(s"pht static ${v.name}") {
      val snippet = new PhtDriver(v) with Static {}
      check(v.name, snippet, v.expect.static, eva = widens.getOrElse(v.name, Taint.Agrees))
    }
  }
}

@virtualize
class PhtPredictiveTests extends KoikaSuite {
  val under = "pht/predictive/"

  for (v <- Variant.all) {
    test(s"pht predictive ${v.name}") {
      val snippet = new PhtDriver(v) with Predictive {}
      check(v.name, snippet, v.expect.predictive, eva = widens.getOrElse(v.name, Taint.Agrees))
    }
  }
}

@virtualize
class PhtForwardingTests extends KoikaSuite {
  val under = "pht/forwarding/"

  for (v <- Variant.all) {
    test(s"pht forwarding ${v.name}") {
      val snippet = new PhtDriver(v) with Forwarding {}
      check(v.name, snippet, v.expect.forwarding, eva = widens.getOrElse(v.name, Taint.Agrees))
    }
  }
}

@virtualize
class PhtNonBlockingTests extends KoikaSuite {
  val under = "pht/nonblocking/"

  for (v <- Variant.all) {
    test(s"pht nonblocking ${v.name}") {
      val snippet = new PhtDriver(v) with NonBlocking {}
      check(v.name, snippet, v.expect.nonblocking, eva = widens.getOrElse(v.name, Taint.Agrees))
    }
  }
}

@virtualize
class PhtPredictiveNonBlockingTests extends KoikaSuite {
  val under = "pht/predictive_nb/"

  for (v <- Variant.all) {
    test(s"pht predictive_nb ${v.name}") {
      val snippet = new PhtDriver(v) with PredictiveNonBlocking {}
      check(v.name, snippet, v.expect.predictive_nb, eva = widens.getOrElse(v.name, Taint.Agrees))
    }
  }
}
