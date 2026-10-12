package elms.koika.test

import java.nio.file.{Files, Path}

import org.scalatest.funsuite.AnyFunSuite

import elms.prelude.*
import elms.prelude.given

import elms.koika.test.common.{
  Cached,
  Forwarding,
  Init,
  KoikaDriver,
  NonBlocking,
  Predictive,
  Prover,
  Static
}
import elms.koika.test.riscv.{Flow, RiscV, RiscVDriver, SquaredRiscVDriver, elf}

// The prototype: one residue function per source-level function, and a `ret`
// that really returns.
//
// Not a snapshot suite and not a claim about any model. It renders the three
// objects in the tree that have a call in them under both schemes, writes the
// C out where CBMC can be pointed at it, and counts what came out. What the
// assertions here pin is the shape of the residue, which is the thing the
// change is about; the verdicts are settled by running the checker over
// `target/proto`.
//
// No `@virtualize` on it: nothing here is staged, and the `for` that generates
// the cases is a `for` the annotation would rewrite.
class CallProtoSuite extends AnyFunSuite {
  private val out = Path.of("target/proto")

  // `victim` is not a leaf, so it spills `ra` into a frame, and a frame below
  // a stack pointer of zero indexes `mem` at `(-4) >>> 2`. Same argument
  // [CallSuite] makes: a demo with a call in it has to be given an `sp` a
  // frame fits under.
  private def arrive(words: Int): String =
    s"""
       |  s1.regs[2] = ${4 * words};
       |  s2.regs[2] = ${4 * words};
       |  int x = bounded(0, 7);
       |  s1.regs[10] = x;
       |  s2.regs[10] = x;""".stripMargin

  private def image(name: String) = elf.Elf.load(s"src/test/asm/riscv/$name.o").prog

  // One model, one object, one scheme. [shared] is the prototype and its
  // negation is what the tree ships.
  private def naive(name: String, shared: Boolean) = new RiscVDriver[64] {
    override val prog = image(name)
    override val init = Init.Spilling.naive(stateT)
    override lazy val initialize_input: String = arrive(mem_size)
    override def inlineCalls: Boolean = !shared
  }

  private def cached(name: String, shared: Boolean) = new RiscVDriver[64] with Cached {
    override val prog = image(name)
    override val init = Init.Spilling.cache(stateT)
    override lazy val initialize_input: String = arrive(mem_size)
    override def inlineCalls: Boolean = !shared
  }

  private def static(name: String, shared: Boolean) = new RiscVDriver[64] with Static {
    override val prog = image(name)
    override val init = Init.Spilling.speculative(stateT)
    override lazy val initialize_input: String = arrive(mem_size)
    override def inlineCalls: Boolean = !shared
  }

  private def predictive(name: String, shared: Boolean) = new RiscVDriver[64] with Predictive {
    override val prog = image(name)
    override val init = Init.Spilling.speculative(stateT)
    override lazy val initialize_input: String = arrive(mem_size)
    override def inlineCalls: Boolean = !shared
  }

  private def forwarding(name: String, shared: Boolean) = new RiscVDriver[64] with Forwarding {
    override val prog = image(name)
    override val init = Init.Spilling.forwarding(stateT)
    override lazy val initialize_input: String = arrive(mem_size)
    override def inlineCalls: Boolean = !shared
  }

  private def nonblocking(name: String, shared: Boolean) = new RiscVDriver[64] with NonBlocking {
    override val prog = image(name)
    override val init = Init.nonblocking(stateT)
    override lazy val initialize_input: String = arrive(mem_size)
    override def inlineCalls: Boolean = !shared
  }

  private def squared(name: String, shared: Boolean) = new SquaredRiscVDriver[64] {
    override val prog = image(name)
    override val init = Init.Spilling.naive(stateT)
    override lazy val initialize_input: String = arrive(mem_size)
    override def inlineCalls: Boolean = !shared
  }

  private val models: Vector[(String, (String, Boolean) => KoikaDriver[?, ?, ?, ?, ?])] =
    Vector(
      "naive" -> naive,
      "cache" -> cached,
      "static" -> static,
      "predictive" -> predictive,
      "forwarding" -> forwarding,
      "nonblocking" -> nonblocking,
      "squared" -> squared
    )

  // How many functions the residue has, and how many `ret_assert` calls are in
  // it. Both read off the C rather than off the tower, because what a checker
  // sees is the question.
  // The definition and not the prototype, which `CCodegen` emits for every
  // function and which would double every count here.
  private def funcs(c: String): Int =
    """(?m)^struct \w+ \* slot_\d+\([^;]*\{$""".r.findAllIn(c).size

  // Which slots sit on a cycle in the emitted call graph, which under this
  // scheme is the residue's own recursion rather than a loop the program had.
  // A checker's `--unwind` has to clear this nesting as well as the loops in
  // the hand-written C around it, and the two want very different numbers.
  private def cyclic(c: String): Set[String] = {
    val bodies =
      """(?ms)^struct \w+ \* (slot_\d+)\([^;]*\{$(.*?)^\}""".r
        .findAllMatchIn(c)
        .map(m => m.group(1) -> """\bslot_\d+\(""".r.findAllIn(m.group(2)).map(_.dropRight(1)).toSet)
        .toMap
    def reach(n: String): Set[String] = {
      var seen = Set.empty[String]
      var todo = List(n)
      while (todo.nonEmpty) {
        val h = todo.head
        todo = todo.tail
        for (m <- bodies.getOrElse(h, Set.empty) if !seen(m)) { seen += m; todo = m :: todo }
      }
      seen
    }
    bodies.keySet.filter(n => reach(n)(n))
  }

  // Indented, so this is the calls and not the two declarations.
  private def asserts(c: String): Int = """(?m)^\s+ret_assert\(""".r.findAllIn(c).size

  private def write(name: String, model: String, scheme: String, c: String): Unit = {
    val dir = out.resolve(scheme)
    Files.createDirectories(dir)
    Files.writeString(dir.resolve(s"$name-$model.c"), c)
  }

  // `--unwind` has to clear the residue's own recursion before anything else
  // is the question, and under the prototype `rec.o` has some: `down` calls
  // itself at most seven times, so eight frames plus the exit test.
  private def unwindLine(n: Int) = s"// verify: clean (CBMC should report VERIFICATION SUCCESSFUL) [unwind $n]\n"

  // All three backends, because the question of what sharing costs is not the
  // same question for each: CBMC and KLEE expand a call either way, and Eva is
  // an abstract interpreter, where one function analysed under the join of two
  // call sites is a weaker answer than two functions analysed apart.
  private def render(name: String, model: String, shared: Boolean, unwind: Int): String = {
    val driver = models.toMap.apply(model)(name, shared)
    val scheme = if (shared) { "shared" } else { "inlined" }
    for (prover <- Prover.values) {
      val suffix = prover.toString.toLowerCase
      write(s"$name-$suffix", model, scheme, unwindLine(unwind) + driver.render(prover))
    }
    unwindLine(unwind) + driver.render(Prover.CBMC)
  }

  for ((model, _) <- models) {
    test(s"twocall under $model: one callee, two sites, one emitted function") {
      val inlined = render("twocall", model, shared = false, 65)
      val shared = render("twocall", model, shared = true, 65)
      // The whole claim. Inlining stages `mask` twice and each copy ends in a
      // tail call back to its own site; sharing stages it once and the two
      // sites get a C call each.
      assert(funcs(shared) < funcs(inlined))
      // One per call site either way, and `twocall` has two. The squared
      // tower checks each run's own `ra` against the same constant, so it is
      // two assertions per site rather than one.
      val perSite = if (model == "squared") { 2 } else { 1 }
      assert(asserts(inlined) == 2 * perSite)
      assert(asserts(shared) == 2 * perSite)
      info(s"$model twocall: ${funcs(inlined)} functions inlined, ${funcs(shared)} shared")
    }
  }

  // Both recursion fixtures, because they answer different halves of the
  // question. `rec` is the one [CallSuite] pins as refused, so staging it at
  // all is the claim; `rec1` is the same shape two frames deep, which is what
  // makes it cheap enough to hand a checker.
  for ((model, _) <- models; name <- Vector("rec", "rec1")) {
    test(s"$name under $model: recursion stages instead of being refused") {
      val shared = render(name, model, shared = true, 70)
      assert(shared.contains("slot_"))
      // The residue is recursive, which is the whole point: the old scheme
      // could not emit this at all.
      assert(cyclic(shared).nonEmpty)
      info(s"$model $name: ${funcs(shared)} functions, ${cyclic(shared).size} on a cycle")
    }
  }

  // The history fixture. Rendered under both schemes for every model so the
  // two can be handed a checker; what the verdicts have to be is a question
  // about the model and is settled by running CBMC, not here.
  for ((model, _) <- models) {
    test(s"retrain renders under $model") {
      val inlined = render("retrain", model, shared = false, 65)
      val shared = render("retrain", model, shared = true, 65)
      info(s"$model retrain: ${funcs(inlined)} functions inlined, ${funcs(shared)} shared")
    }
  }

  private def callTargets(prog: Vector[RiscV.Instr]): Vector[Int] =
    prog.collect { case RiscV.Instr.Call(_, t) => t }

  // The rule [Flow] exists for, on the two objects that sit either side of it.
  //
  // `mask` has no branch in it, so a call to it writes no history and sharing
  // it drops nothing. `trainer` and `anti` each have one, and `retrain` calls
  // both again after the first pair has returned, so what they wrote is read
  // back and a shared copy would have nowhere to have kept it.
  test("a callee is shared only when nothing reads the history it wrote") {
    val two = image("twocall")
    val twoC = Flow.consultedAfterAnyCall(two)
    assert(callTargets(two).nonEmpty)
    assert(callTargets(two).forall(t => Flow.historySafe(two, t, twoC)))

    val re = image("retrain")
    val reC = Flow.consultedAfterAnyCall(re)
    assert(callTargets(re).nonEmpty)
    assert(callTargets(re).forall(t => !Flow.historySafe(re, t, reC)))

    // `down`'s branch runs on the way in and never after a return, so the
    // recursion is shareable even though the callee branches. Precision here
    // is what keeps the analysis from collapsing to "no callee may branch".
    val rec = image("rec")
    val recC = Flow.consultedAfterAnyCall(rec)
    assert(callTargets(rec).forall(t => Flow.historySafe(rec, t, recC)))
  }

  // End to end: the model that carries a history declines the callee the
  // analysis declined, and emits what it would have emitted inlining.
  test("predictive shares twocall's callee and refuses retrain's") {
    assert(funcs(render("twocall", "predictive", shared = true, 65)) <
      funcs(render("twocall", "predictive", shared = false, 65)))
    assert(funcs(render("retrain", "predictive", shared = true, 65)) ==
      funcs(render("retrain", "predictive", shared = false, 65)))
    // And a model with no history shares it either way, so the refusal is
    // [carriesHistory]'s and not the program's alone.
    assert(funcs(render("retrain", "naive", shared = true, 65)) <
      funcs(render("retrain", "naive", shared = false, 65)))
  }

  test("two_functions still halts at the first ret under both schemes") {
    val inlined = render("two_functions", "naive", shared = false, 10)
    val shared = render("two_functions", "naive", shared = true, 10)
    // No call in the object, so nothing declares the assertion and the two
    // schemes have nothing to disagree about.
    assert(!inlined.contains("ret_assert"))
    assert(!shared.contains("ret_assert"))
    assert(funcs(inlined) == funcs(shared))
  }
}
