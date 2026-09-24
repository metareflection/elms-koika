package elms.koika.test.squared

import elms.core.macros.virtualize

import elms.prelude.given

import elms.koika.test.riscv.RiscV.Reg

// A store queue in front of the cache, and the load that reads around it, over
// a pair of runs.
//
// The model is [elms.koika.test.common.Forwarding]'s and that file is where
// the argument for it lives: a store sits in the queue rather than committing,
// a load issued before its address resolves reads around it on a guess, and a
// load past it forwards on a partial tag match that can be wrong. That is
// Spectre v4, and it is a channel no branch predictor sees.
//
// This is the first model in the tower that inlines, and so the first thing to
// use the seam [Squared.enter] describes. While the window is open [inlined]
// is true, `call` runs the next instruction where it stands, and no slot
// begins, so the clocks are not compared until the window closes. That is not
// an optimization: inside the window one run can be mid-miss while the other
// is not, and comparing there would report a drift the rest of the window was
// going to close.
//
// The queue is the other thing that is not like the models to the left. What
// it holds is a [Rep], and a [Rep] belongs to the run that computed it, so
// there are two queues here rather than one queue of pairs. [set_mem] and
// [get_mem] are single-run operations and reach the queue for whichever run
// [Squared.running] says they are running as.
@virtualize
trait Forwarding extends Predictive {
  // Instructions after a store before its address resolves. A load inside that
  // bypasses the queue; a load past it forwards on a match.
  val storeLatency: Int = 2

  // Instructions the store stays in the queue. At least [storeLatency], or the
  // window closes before anything could have read around it and the model is
  // [Predictive] with extra steps.
  val storeWindow: Int = 4
  require(storeWindow >= storeLatency, s"storeWindow $storeWindow < storeLatency $storeLatency")

  // What a forwarded load costs instead of a cache probe.
  //
  // The same as [Cached]'s first-level hit, which is worth knowing when
  // reading a counterexample: the forward arm and the hit arm are
  // indistinguishable in the timer, so a gap is never attributable to the
  // forwarding decision alone.
  val forwardCost: Int = 1

  // How many low bits of the word index the queue compares before deciding to
  // forward. Fewer than the whole address, which is what real hardware does
  // and is the only reason this model has a channel of its own: a partial
  // match on a different full address forwards the wrong value.
  val forwardBits: Int = 2

  private def tag(a: Rep[Int]): Rep[Int] = a & unit((1 << forwardBits) - 1)

  // The window itself, which both runs share because nothing that decides it
  // is a [Rep]: which pc opened it, how far it reaches and which registers it
  // has saved are all staging-time facts. [saved] is a field here rather than
  // in a slot key because this window is inlined and so never reaches one.
  private case class Opening(at: Int, saved: Vector[Reg])
  private var opening: Option[Opening] = None

  // What one run put in its own queue. [entry] is empty between opening the
  // window and [set_mem] filling it in, which is the state a narrow store's
  // read-modify-write is observed in. [bypassed] is the addresses of the loads
  // that read around the store and [forwarded] of the ones that took its
  // value, both in program order, and the close checks each against the
  // address the store turned out to have.
  private case class Held(
      entry: Option[(Rep[Int], Rep[Int])],
      bypassed: Vector[Rep[Int]],
      forwarded: Vector[Rep[Int]]
  )

  private def drained: Vector[Held] = Vector.fill(2)(Held(None, Vector(), Vector()))
  private var held: Vector[Held] = drained

  private def amend(f: Held => Held): Unit = held = held.updated(running, f(held(running)))

  // A load forwarded because its tag matched, and the queue was wrong to let
  // it whenever the full addresses differ.
  private def misforwarded(a: Rep[Int], addr: Rep[Int]): Rep[Boolean] =
    (tag(a) === tag(addr)) & (a !== addr)

  // The pc the window is currently at. [get_mem] needs it in order to know
  // whether the store's address has resolved yet, and it is not one of its
  // arguments.
  private var current: Int = 0

  private def resolved: Boolean = opening.exists(o => current >= o.at + 1 + storeLatency)

  override def inlined: Boolean = super.inlined || opening.nonEmpty

  // [Cached]'s, reached by name rather than through `super` inside a lambda.
  private def commit(h: Half, addr: Rep[Int], v: Rep[Int]): Rep[Unit] =
    super.set_mem(h, addr, v)

  // The store the window opened for. It goes in this run's queue, and the
  // cache does not hear about it until [close].
  override def set_mem(h: Half, addr: Rep[Int], v: Rep[Int]): Rep[Unit] =
    opening match {
      case Some(_) if held(running).entry.isEmpty => {
        amend(_.copy(entry = Some((addr, v))))
        unit(())
      }

      // One entry per run, and this run's is taken. Passing this write to
      // [Cached] would commit it ahead of the store already waiting, which is
      // a reordering nothing in the residue would show. Unreachable as the
      // tower stands, because a store is not [speculable] and so closes the
      // window before a second one could run.
      case Some(o) =>
        sys.error(s"forwarding: a second store reached run $running's queue at ${o.at}")

      case None => super.set_mem(h, addr, v)
    }

  override def get_mem(h: Half, addr: Rep[Int]): Rep[Int] = opening match {
    case Some(_) => held(running).entry match {
        case Some((qaddr, qval)) if resolved => {
          // The address has resolved, so the queue answers on a tag match. It
          // is on the list either way: whether the match was the real thing is
          // [close]'s question, and this load took the value on trust.
          amend(q => q.copy(forwarded = q.forwarded :+ addr))
          // The arms have to be the value of the virtualized `if` rather than
          // assignments to a `var`. A `var` here is an ordinary Scala variable
          // holding a [Rep], so it would name whichever arm was staged last
          // and the emitted C would read a symbol declared in the other block.
          if (tag(qaddr) === tag(addr)) {
            h.timer = h.timer + unit(forwardCost)
            qval
          } else { super.get_mem(h, addr) }
        }

        case Some(_) => {
          // Unresolved. The predictor guesses no-alias and this load reads
          // around the queue, which is only correct if the guess holds; the
          // address goes on the list [close] checks it against.
          amend(q => q.copy(bypassed = q.bypassed :+ addr))
          super.get_mem(h, addr)
        }

        // The window is opening and the store has not reached [set_mem] yet,
        // which is a narrow store reading the word it is about to modify.
        case None => super.get_mem(h, addr)
      }
    case None => super.get_mem(h, addr)
  }

  override protected def run(pc: Int, w: Option[Window], s: Pair): Pair =
    opening match {
      case Some(o) => inside(pc, o, s)
      // A store window opens only with no branch window already open, and no
      // branch runs inside a store window because [speculable] refuses one.
      // That is what keeps the two from nesting.
      case None =>
        if (w.isEmpty && pc < prog.length && isStore(prog(pc))) { open(pc, s) }
        else { super.run(pc, w, s) }
    }

  // [step] runs the store, [set_mem] diverts it into each run's queue, and the
  // `call(pc + 1, s)` at the end of [step] finds [inlined] true and runs the
  // rest of the window where it stands. So everything after this line happens
  // inside [step]'s continuation, and the close is [inside]'s to do.
  private def open(at: Int, s: Pair): Pair = {
    opening = Some(Opening(at, Vector()))
    held = drained
    current = at
    step(at, s)
  }

  private def inside(pc: Int, o: Opening, s: Pair): Pair =
    if (pc >= prog.length || pc >= o.at + 1 + storeWindow) { close(o, pc, s) }
    else {
      speculable(prog(pc)) match {
        // No [reads] check, unlike [Predictive]'s window. A branch condition
        // is evaluated against the live register file at the join point, so a
        // speculated write to one of its inputs corrupts it; the store's
        // address and the bypassing loads' are [Rep]s captured where they were
        // computed, and a later write to the register they came from cannot
        // reach them.
        case Some(rd) => {
          opening = Some(o.copy(saved = save(s, o.saved, rd)))
          current = pc
          step(pc, s)
        }
        case None => close(o, pc, s)
      }
    }

  // Whether this run's queue got it wrong. Two ways, and they are opposites: a
  // load that read around the store should not have aliased it, and one that
  // forwarded out of it should have, where only the tag said so. [StrictOr]
  // and not `||`, which takes regions and would put each test in a block of
  // its own.
  private def wrong(q: Held, addr: Rep[Int]): Rep[Boolean] =
    (q.bypassed.map(_ === addr) ++ q.forwarded.map(misforwarded(_, addr))).reduce(_ | _)

  private def close(o: Opening, at: Int, s: Pair): Pair = {
    val runs = held

    // Assigned before either [call], because it re-enables memoization and is
    // what makes them emit real C calls rather than inlining.
    opening = None
    held = drained

    // The store commits whichever way the alias goes, so it sits outside the
    // test rather than being written into both arms.
    each(s)(h => runs(running).entry.foreach((addr, v) => commit(h, addr, v)))

    // The two runs walked the same instructions, so their queues hold the same
    // number of addresses. Only the addresses themselves differ, which is the
    // question below.
    require(
      runs(0).bypassed.length == runs(1).bypassed.length &&
        runs(0).forwarded.length == runs(1).forwarded.length,
      s"forwarding: the two runs' queues came out different shapes at ${o.at}"
    )

    runs(0).entry match {
      case Some(_) if runs(0).bypassed.nonEmpty || runs(0).forwarded.nonEmpty => {
        // [rollback] is [Predictive]'s, penalty included: a memory ordering
        // violation costs what a mispredicted branch costs, and both restore
        // every register the window saved. That is why control restarts past
        // the store rather than at the load that aliased.
        //
        // Asked of both runs and answered once. A violation in one run and not
        // the other is two programs from here on, which is the same thing a
        // branch resolving two ways would be.
        val missed = Sided(
          wrong(runs(0), runs(0).entry.get._1),
          wrong(runs(1), runs(1).entry.get._1)
        )
        agree(missed) {
          rollback(s, o.saved)
          call(o.at + 1, s)
        } { call(at, s) }
      }

      // Nothing read around the store and nothing forwarded out of it, so
      // there is nothing to have got wrong.
      case _ => call(at, s)
    }
  }
}
