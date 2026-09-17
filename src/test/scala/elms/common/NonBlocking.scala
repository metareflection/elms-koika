package elms.koika.test.common

import elms.prelude.*
import elms.prelude.given

// A load the instructions behind it can hide.
//
// Every model to the left of this one spends a miss the moment it happens, so a
// hundred cycles of memory latency is a hundred cycles in which nothing else
// runs. Hardware does not stop there. The load's destination is marked
// not-ready, everything behind it issues anyway, and only the instruction that
// reads the value waits.
//
// What that buys a side-channel model is that a miss stops being worth a fixed
// hundred cycles. It is worth however much of it the program could not fill,
// which is a property of the code around the load rather than of the load, so a
// secret that moves a consumer nearer to or further from its producer is a
// channel with no secret-dependent address anywhere in it.
//
// The clock counts issues, one per instruction, and every value carries the
// cycle it lands on. What the program cost is then the later of the two, which
// is the critical path through the dependences rather than the sum of the
// latencies.
@virtualize
trait NonBlocking extends Cached {
  // Supplied by [GenericKoikaDriver], which is where the register file's length
  // is fixed.
  def num_regs: Int

  // The later of two cycle counts, without a comparison in it: `b + max(a-b, 0)`
  // off the sign bit of the subtraction. Counts are small positives here, so the
  // subtraction cannot reach the sign bit for any other reason.
  //
  // Branchless because this runs twice per instruction and once per register at
  // the end, and a fork apiece would be a path space built out of arithmetic.
  private def later(a: Rep[Int], b: Rep[Int]): Rep[Int] = {
    val d = a - b
    b + (d & ~(d >> unit(31)))
  }

  // When the instruction being staged can start, and what memory has charged it
  // so far. Both are [Rep]s in ordinary Scala fields, which is sound for the
  // reason [Forwarding]'s queue is: they are written and read inside one
  // [Isa.step], and [tick] resets them at the top of the next one, so neither
  // ever crosses a slot boundary into a function where its symbol means
  // something else.
  private var issueAt: Option[Rep[Int]] = None
  private var waiting: Option[Rep[Int]] = None

  // Whether the register accesses going past are the program's. A tower that
  // speculates does register traffic of its own, and folding a saved copy's
  // arrival into whatever instruction happens to be staging is both wrong and
  // quiet: the two accumulators below are [Rep]s belonging to one function, and
  // a save or a restore at a slot boundary would mix a foreign symbol into
  // them. [Common.untimed] is where the tower says which accesses are which.
  private var timing: Boolean = true

  override def untimed[A](body: => A): A = {
    val outer = timing
    timing = false
    try { body }
    finally { timing = outer }
  }

  // Every source an instruction reads passes through here, so accumulating the
  // latest of them is the same as asking when the last operand arrives. No
  // [Isa] method says what an instruction reads and none needs to.
  override def get_reg(s: Rep[State], i: Rep[Int]): Rep[Int] = {
    if (timing) { issueAt = Some(issueAt.fold(s.reg_ready(i))(later(_, s.reg_ready(i)))) }
    super.get_reg(s, i)
  }

  // And every destination passes through here, after all of that instruction's
  // reads. x0 never arrives, because [Exec] resolves a write to it away at
  // staging time rather than emitting one.
  override def set_reg(s: Rep[State], i: Rep[Int], v: Rep[Int]): Rep[Unit] = {
    if (timing) {
      val at = issueAt.getOrElse(s.timer)
      s.reg_ready(i) = waiting.fold(at + unit(1))(at + unit(1) + _)
    }
    super.set_reg(s, i, v)
  }

  // A load is the whole point: whoever reads the value pays, and the clock does
  // not. A store still goes through [spend], since nothing waits on one.
  override def defer(s: Rep[State], lat: Rep[Int]): Rep[Unit] = {
    waiting = Some(waiting.fold(lat)(_ + lat))
    unit(())
  }

  // The clock advances by the issue, and the accumulators start again.
  //
  // [issueAt] starts at the clock rather than empty, because an instruction
  // cannot start before the machine has got to it however early its operands
  // landed: issue is in program order even when completion is not. Leaving that
  // out makes a dependent chain come out cheaper than its own instruction count.
  override def tick(s: Rep[State]): Rep[Unit] = {
    issueAt = Some(s.timer)
    waiting = None
    super.tick(s)
  }

  // In-order retirement: the program is not over until the last value has
  // landed, so a miss nobody waited for is still paid for at the end. Without
  // this a load whose value is never read would be free, which is the one thing
  // a machine with a reorder buffer does not do.
  override def finish(s: Rep[State]): Rep[State] = {
    for (i <- 0 until num_regs) { s.timer = later(s.timer, s.reg_ready(unit(i))) }
    s
  }

  // Nothing survives a squash, so nothing is still on its way either. Every
  // register is available at the clock and the misses the window had
  // outstanding are never charged to anyone.
  //
  // That is a claim, and it is the one place this model asserts something a
  // real machine only approximately does. A miss the squash discards still
  // occupies the memory system, so a later miss queues behind it; modelling
  // that means modelling how many can be outstanding at once, which is a
  // structural hazard and nothing else in this tower has one. What survives a
  // squash here is the cache, which is where [Speculative]'s channel lives
  // anyway.
  override def squash(s: Rep[State]): Rep[Unit] = {
    for (i <- 0 until num_regs) { s.reg_ready(unit(i)) = s.timer }
    unit(())
  }
}

// Non-blocking loads behind a branch predictor, which is the first model here
// with both a front end that runs ahead and a memory side that does not stop.
//
// The composition needed no arithmetic of its own. [Predictive] says which
// register accesses are the machine's and which are its own bookkeeping, and
// [NonBlocking] answers both halves of that; everything else the two do is
// disjoint, since one of them decides which instructions run and the other
// decides when their values land.
//
// It is a join rather than a step, and neither half decides its verdicts.
// `spectre` reads clean here, the way it does under [NonBlocking] alone, and
// `reload` reads leak, the way it does under [Predictive] alone. What separates
// those two demos is whether anything asks the cache a question after the
// squash, which is the only thing a machine like this leaves behind.
@virtualize
trait PredictiveNonBlocking extends Predictive with NonBlocking
