package elms.koika.test.squared

import elms.core.macros.virtualize

import elms.prelude.given

// A load the instructions behind it can hide, over a pair of runs.
//
// The model is [elms.koika.test.common.NonBlocking]'s and that file is where
// the argument for it lives: the clock counts issues, every value carries the
// cycle it lands on, and what a program cost is the critical path through its
// dependences rather than the sum of its latencies. A miss then stops being
// worth a fixed hundred cycles and starts being worth however much of it the
// program could not fill, which is a property of the code around the load and
// so a channel with no secret-dependent address in it.
//
// This is the model the [Machine.defer], [Squared.untimed], [Squared.squash]
// and [Squared.finish] seams were put there for. Every one of them had no
// instance until now, which is why each says in its own comment what it would
// mean rather than what it does.
//
// The two accumulators hold a [Rep] apiece and a [Rep] belongs to the run that
// computed it, so there are two of each here rather than one of each holding a
// pair. That is [Forwarding]'s arrangement for the same reason, and
// [Squared.running] is what reaches the right one.
@virtualize
trait NonBlocking extends Cached with Squared {
  // Supplied by the driver, which is where the register file's length is
  // fixed.
  def num_regs: Int

  // The later of two cycle counts, without a comparison in it: `b + max(a-b,
  // 0)` off the sign bit of the subtraction. Counts are small positives here,
  // so the subtraction cannot reach the sign bit for any other reason.
  //
  // Branchless because this runs twice per instruction and once per register
  // at the end, and a fork apiece would be a path space built out of
  // arithmetic. Doubly so here, where every fork is two.
  private def later(a: Rep[Int], b: Rep[Int]): Rep[Int] = {
    val d = a - b
    b + (d & ~(d >> unit(31)))
  }

  // When the instruction being staged can start, and what memory has charged
  // it so far, for each run. Both hold [Rep]s, which is sound for the reason
  // [Forwarding]'s queue is: they are written and read inside one [Exec.step]
  // and [tick] resets them at the top of the next, so neither ever crosses a
  // slot boundary into a function where its symbol means something else.
  private var issueAt: Vector[Option[Rep[Int]]] = Vector(None, None)
  private var waiting: Vector[Option[Rep[Int]]] = Vector(None, None)

  // Whether the register accesses going past are the program's. Static, and so
  // one flag rather than two: which accesses are the tower's own is a fact
  // about the model and not about either run.
  private var timing: Boolean = true

  override def untimed[A](body: => A): A = {
    val outer = timing
    timing = false
    try { body }
    finally { timing = outer }
  }

  // Every source an instruction reads passes through here, so accumulating the
  // latest of them is the same as asking when the last operand arrives.
  override def get_reg(h: Half, i: Rep[Int]): Rep[Int] = {
    if (timing) {
      val ready = h.reg_ready(i)
      issueAt = issueAt.updated(running, Some(issueAt(running).fold(ready)(later(_, ready))))
    }
    super.get_reg(h, i)
  }

  // And every destination passes through here, after all of that
  // instruction's reads. x0 never arrives, because [Exec] resolves a write to
  // it away at staging time rather than emitting one.
  override def set_reg(h: Half, i: Rep[Int], v: Rep[Int]): Rep[Unit] = {
    if (timing) {
      val at = issueAt(running).getOrElse(h.timer)
      h.reg_ready(i) = waiting(running).fold(at + unit(1))(at + unit(1) + _)
    }
    super.set_reg(h, i, v)
  }

  // A load is the whole point: whoever reads the value pays, and the clock
  // does not. A store still goes through [spend], since nothing waits on one.
  override def defer(h: Half, lat: Rep[Int]): Rep[Unit] = {
    waiting = waiting.updated(running, Some(waiting(running).fold(lat)(_ + lat)))
    unit(())
  }

  // The clock advances by the issue, and the accumulators start again.
  //
  // [issueAt] starts at the clock rather than empty, because an instruction
  // cannot start before the machine has got to it however early its operands
  // landed: issue is in program order even when completion is not. Leaving
  // that out makes a dependent chain come out cheaper than its own
  // instruction count.
  override def tick(h: Half): Rep[Unit] = {
    issueAt = issueAt.updated(running, Some(h.timer))
    waiting = waiting.updated(running, None)
    super.tick(h)
  }

  // In-order retirement: the program is not over until the last value has
  // landed, so a miss nobody waited for is still paid for at the end. Without
  // this a load whose value is never read would be free, which is the one
  // thing a machine with a reorder buffer does not do.
  //
  // Which is also why the clocks are comparable at the end at all. [enter]
  // compares them on the way into a slot, and the last slot's outstanding
  // misses land after the last of those; `main`'s final comparison is reading
  // what this wrote.
  override def finish(s: Pair): Pair = {
    each(s)(h => for (i <- 0 until num_regs) { h.timer = later(h.timer, h.reg_ready(unit(i))) })
    s
  }

  // Nothing survives a squash, so nothing is still on its way either. Every
  // register is available at the clock and the misses the window had
  // outstanding are never charged to anyone.
  //
  // That is a claim, and it is the one place this model asserts something a
  // real machine only approximately does. What survives a squash here is the
  // cache, which is where the speculative channel lives anyway.
  override def squash(s: Pair): Unit =
    each(s)(h => for (i <- 0 until num_regs) { h.reg_ready(unit(i)) = h.timer })
}

// Non-blocking loads behind a branch predictor, which is the first model here
// with both a front end that runs ahead and a memory side that does not stop.
//
// The composition needed no arithmetic of its own, and squaring it needs none
// either. [Predictive] says which register accesses are the machine's and
// which are its own bookkeeping, [NonBlocking] answers both halves of that,
// and the two runs are kept together by the same [agree] at the same branch.
//
// It is a join rather than a step, and neither half decides its verdicts.
// `spectre` reads clean here, the way it does under [NonBlocking] alone, and
// `reload` reads leak, the way it does under [Predictive] alone. What
// separates those two demos is whether anything asks the cache a question
// after the squash, which is the only thing a machine like this leaves behind.
@virtualize
trait PredictiveNonBlocking extends Predictive with NonBlocking
