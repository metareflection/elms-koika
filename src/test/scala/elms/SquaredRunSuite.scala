package elms.koika.test

import scala.collection.mutable
import scala.util.Random

import org.scalatest.funsuite.AnyFunSuite

import elms.koika.test.squared.{CachedRun, Chip, FlatRun, Outcome, PredictiveRun, Run, StaticRun}
import elms.koika.test.riscv.{RiscV, elf}

// The squared interpreter, run rather than staged.
//
// The residue tree answers whether a leak is reachable, which takes a checker
// and takes minutes. This answers whether one is reachable over a sample, and
// takes milliseconds. That is a weaker question and a much faster one, and it
// is the one worth asking while the interpreter is being written: a product
// semantics nobody can run has to be wrong in C before anyone finds out.
//
// The table below is [README.md]'s, first four columns. Every cell is a verdict
// the staged tower already publishes, so this is a second opinion on the same
// models from a semantics that emits nothing.
//
// What a sample can and cannot settle. A `leak` cell is witnessed: some pair
// of secrets drove the two runs apart, and a witness is a proof. A `clean`
// cell is not settled at all, only unfalsified, which is what `src/out` and a
// checker are for. Both directions still fail loudly if the interpreter
// breaks, since an oracle stuck at "in step" loses every leak row and one
// stuck at "drifted" loses every clean row.
class SquaredRunSuite extends AnyFunSuite {
  // [GenericKoikaDriver]'s, and the demos are assembled against them.
  private val secretOffset = 20
  private val secretSize = 10
  private val secretOffsetBytes = 4 * secretOffset

  private def demo(name: String): Vector[RiscV.Instr] =
    elf.Elf.load(s"src/test/asm/riscv/$name.o").prog

  private def bounded(r: Random, lo: Int, hi: Int): Int = lo + r.nextInt(hi - lo + 1)

  // One draw, written into both runs. `initialize_input`, in Scala.
  private type Public = Chip => Unit

  // A draw apiece. `initialize_secret`, and the whole question is whether the
  // clock can tell the two apart.
  private type Secret = Chip => Unit

  // Word-aligned, where the C draws any byte in the range. `loadValue` reads
  // the word holding an address, so three quarters of a byte-granular sample
  // is a repeat of the draw below it, and the reach of the sample is what
  // decides whether a leak gets witnessed at all.
  private def publicArg(r: Random): Public = {
    val x = 4 * bounded(r, 0, secretOffsetBytes / 4)
    c => c.regs(10) = x
  }

  // `branchy.s` seeds the walk's indices into registers rather than into
  // `mem`, and [BranchyDriver] says why: an address nobody can prove the two
  // runs agree on makes an assumption about the clock worth nothing.
  private def branchyArg(prog: Vector[RiscV.Instr])(r: Random): Public = {
    val regs = prog.collect {
      case RiscV.Instr.OpImm(RiscV.AluOp.Srl, _, rs1, _) => rs1.i
    }.distinct.sorted
    require(regs.nonEmpty, "branchy.s has no `srli`, so nothing would vary")
    val draws = regs.map(rg => (rg, bounded(r, 0, 1073741823)))
    c => draws.foreach((rg, v) => c.regs(rg) = v)
  }

  private def secretWords(r: Random): Secret = {
    val ws = Vector.fill(secretSize)(bounded(r, 0, 20))
    c => ws.zipWithIndex.foreach((v, i) => c.mem(secretOffset + i) = v)
  }

  private def start(run: Run, pub: Public, sec: Secret): Chip = {
    val c = run.blank
    pub(c)
    sec(c)
    c
  }

  // A squared residue asserts on the way into every slot and again at every
  // branch, and any of them firing is the leak. So is either of these.
  private def leaked(o: Outcome): Boolean = o match {
    case Outcome.InStep(_) => false
    case _                 => true
  }

  // Enough to reach the one public address that puts a secret word into the
  // second load's address. `2ctr` is the demo that sets this: its channel is
  // open for one draw in twenty-one, and only then for the secrets that
  // collide with the line the first load installed.
  private val samples = 2000

  // What a demo cost when both runs were given the same secret, per model.
  // Read back by the last test in the file.
  private val cost = mutable.Map.empty[(String, String), Int]

  // [model] names which column of the table this is, and [leaks] is what that
  // column says.
  private def cell(
      model: String,
      build: Vector[RiscV.Instr] => Run,
      name: String,
      leaks: Boolean,
      input: Vector[RiscV.Instr] => Random => Public = _ => publicArg
  ): Unit = test(s"squared run $model $name") {
    val prog = demo(name)
    val r = Random(0xc0ffee)
    val pubOf = input(prog)

    var witness: Option[Outcome] = None
    for (_ <- 0 until samples) {
      val pub = pubOf(r)

      // The same secret in both runs. Nothing about the model or the program
      // can make these disagree, so a failure here is the interpreter rather
      // than the demo.
      val same = secretWords(r)
      val one = build(prog)
      one(start(one, pub, same), start(one, pub, same)) match {
        case Outcome.InStep(n) => cost((model, name)) = n
        case other             => fail(s"$name: identical secrets came apart: $other")
      }

      val two = build(prog)
      val o = two(start(two, pub, secretWords(r)), start(two, pub, secretWords(r)))
      if (leaked(o) && witness.isEmpty) { witness = Some(o) }
    }

    witness match {
      case Some(o) => assert(leaks, s"$name: a sampled pair came apart: $o")
      case None    => assert(!leaks, s"$name: no sampled pair of secrets came apart")
    }
  }

  private def naive(name: String, leaks: Boolean): Unit =
    cell("naive", FlatRun(_), name, leaks)
  private def cached(name: String, leaks: Boolean): Unit =
    cell("cache", CachedRun(_), name, leaks)
  private def static(name: String, leaks: Boolean): Unit =
    cell("static", StaticRun(_), name, leaks)
  private def predictive(name: String, leaks: Boolean): Unit =
    cell("predictive", PredictiveRun(_), name, leaks)

  naive("shortcircuit", leaks = true)
  naive("2ctr", leaks = false)
  naive("spectre", leaks = false)
  naive("constant_time", leaks = false)
  naive("evict", leaks = false)
  naive("hidden", leaks = false)
  naive("reload", leaks = false)
  naive("bypass", leaks = false)
  naive("bypass_alias", leaks = false)
  naive("bypass_ct", leaks = false)
  naive("bypass_late", leaks = false)
  naive("dynstore", leaks = false)

  cached("shortcircuit", leaks = true)
  cached("2ctr", leaks = true)
  cached("spectre", leaks = false)
  cached("constant_time", leaks = false)
  cached("evict", leaks = true)
  cached("hidden", leaks = true)
  cached("reload", leaks = false)
  cached("bypass", leaks = false)
  cached("bypass_alias", leaks = false)
  cached("bypass_ct", leaks = false)
  cached("bypass_late", leaks = false)
  cached("dynstore", leaks = false)

  static("shortcircuit", leaks = true)
  static("2ctr", leaks = true)
  static("spectre", leaks = true)
  static("constant_time", leaks = false)
  static("evict", leaks = true)
  static("hidden", leaks = true)
  static("reload", leaks = true)
  static("bypass", leaks = false)
  static("bypass_alias", leaks = false)
  static("bypass_ct", leaks = false)
  static("bypass_late", leaks = false)
  static("dynstore", leaks = false)

  predictive("shortcircuit", leaks = true)
  predictive("2ctr", leaks = true)
  predictive("spectre", leaks = true)
  predictive("constant_time", leaks = false)
  predictive("evict", leaks = true)
  predictive("hidden", leaks = true)
  predictive("reload", leaks = true)
  predictive("bypass", leaks = false)
  predictive("bypass_alias", leaks = false)
  predictive("bypass_ct", leaks = false)
  predictive("bypass_late", leaks = false)
  predictive("dynstore", leaks = false)

  cell("naive", FlatRun(_), "branchy", leaks = false, input = branchyArg)
  cell("cache", CachedRun(_), "branchy", leaks = false, input = branchyArg)
  cell("static", StaticRun(_), "branchy", leaks = false, input = branchyArg)
  cell("predictive", PredictiveRun(_), "branchy", leaks = false, input = branchyArg)

  // `spectre.s` sets its own index and bound to the same constant, so the
  // bounds check is always taken and neither of the first two models reaches
  // the load behind it. That is the whole reason the demo needs speculation
  // to be interesting, and it is why it is the one row that cannot say
  // anything about a cache.
  private val neverLoads = Set("spectre")

  // A model that charged nothing for what the one before it added would pass
  // every clean row above for the wrong reason, and the clean rows are what
  // the leak rows are read against. [Flat] spends nothing, so a naive run's
  // clock is its instruction count and anything over that came from a model.
  test("each model charges for what it added") {
    val demos = cost.keys.collect { case ("cache", d) => d }.toSeq.sorted
    assert(demos.nonEmpty)
    demos.foreach { d =>
      val flat = cost(("naive", d))
      val cached = cost(("cache", d))
      if (neverLoads(d)) { assert(cached == flat, s"$d: $cached cycles, and it runs no load") }
      else { assert(cached > flat, s"$d: $cached cycles with a cache and $flat without one") }
    }

    // `spectre` reaches a load only by speculating past a bounds check, which
    // is the row `neverLoads` exempts above saying the same thing from the
    // other side. Both predictors guess not-taken on a cold branch, so both
    // have to show it.
    for (model <- Seq("static", "predictive")) {
      assert(
        cost((model, "spectre")) > cost(("cache", "spectre")),
        s"$model: speculation did not reach the load behind the bounds check"
      )
    }
  }
}
