package elms.koika.test.common

import elms.prelude.*
import elms.prelude.given

// A store queue in front of the cache, and the load that reads around it.
//
// Every model to the left of this one commits a store the instant it executes,
// which [Isa.speculable] writes down as a requirement: a squash restores
// registers and nothing else, so a store that ran speculatively could never be
// taken back. A queue removes the requirement rather than working around it.
// The store sits in the queue for a while, a squash discards it, and never
// reaches [Cached] to dirty a line in the first place.
//
// What that buys is a channel no branch predictor sees. A load issued before
// the queued store's address has resolved cannot know whether it aliases, so
// the disambiguation predictor guesses that it does not and the load reads
// memory: the word the store was about to overwrite, rather than the word it
// wrote. That is Spectre v4, and `bypass.s` is eight instructions of it.
//
// The queue holds [Rep]s in an ordinary Scala field, and [useCache] is what
// makes that sound. A [Rep] names a class in the e-graph of whichever function
// is open, so one that outlived a slot boundary would reach whatever that
// index happens to mean in the next function. [useCache] is false while the
// queue is occupied, so [Common.call] inlines the rest of the window rather
// than declaring a slot for it, and nothing here crosses a boundary.
//
// The branch window is [Predictive]'s and travels in the slot key, so the two
// windows never have to know about each other. A store is not [speculable], so
// a branch window ends at one: by the time [run] sees the store,
// [Predictive]'s [settle] has closed the branch window and gone back around
// through [Common.call], and the store opens its own with the ambient one
// empty. `bypass_late.s` is that program, and on the tower's previous shape it
// needed a hook in the base model to work at all.
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
  // The same as [Cached]'s first-level hit, which is worth knowing when reading
  // a counterexample: the forward arm and the hit arm are indistinguishable in
  // the timer, so a gap is never attributable to the forwarding decision alone.
  val forwardCost: Int = 1

  // How many low bits of the word index the queue compares before deciding to
  // forward. Fewer than the whole address, which is what real hardware does and
  // is the only reason this model has a channel of its own: a partial match on
  // a different full address forwards the wrong value.
  //
  // Two bits against thirty words of memory, scaled the way the cache is. A
  // real queue compares the page offset, twelve bits, which over an address
  // space is rare enough to be a curiosity and over `mem` would be exact.
  val forwardBits: Int = 2

  private def tag(a: Rep[Int]): Rep[Int] = a & unit((1 << forwardBits) - 1)

  // [at] is the store's pc, which is both where the window opened and where
  // control restarts if the guess was wrong. [entry] is empty between opening
  // the window and [set_mem] filling it in, which is the state a narrow store's
  // read-modify-write is observed in. [bypassed] is the addresses of the loads
  // that read around the store, in program order, and the only thing the
  // deferred alias check reads. [saved] is what [Predictive.Window] carries in
  // the slot key; it is a field here because this window is inlined and so
  // never reaches a key.
  private case class Queued(
      at: Int,
      entry: Option[(Rep[Int], Rep[Int])],
      bypassed: Vector[Rep[Int]],
      forwarded: Vector[Rep[Int]],
      saved: Vector[Reg]
  )
  private var queued: Option[Queued] = None

  // A load forwarded because its tag matched, and the queue was wrong to let it
  // whenever the full addresses differ. Recomputed here rather than carried out
  // of the arm that staged it, because a [Rep] built inside a virtualized `if`
  // names a symbol declared in that block; CSE merges the two tag comparisons.
  private def misforwarded(a: Rep[Int], addr: Rep[Int]): Rep[Boolean] =
    (tag(a) === tag(addr)) & (a !== addr)

  // The pc the window is currently at. [get_mem] needs it in order to know
  // whether the store's address has resolved yet, and it is not one of its
  // arguments. Ambient rather than threaded, which is what [Predictive] does
  // with its lookahead for the same reason: [Isa.step] recurses through
  // `call(pc + 1, s)` with a bare pc.
  private var current: Int = 0

  private def resolved(q: Queued): Boolean = current >= q.at + 1 + storeLatency

  override def useCache: Boolean = super.useCache && queued.isEmpty

  // The store the window opened for. It goes in the queue, and the cache does
  // not hear about it until [close].
  override def set_mem(s: Rep[State], addr: Rep[Int], v: Rep[Int]): Rep[Unit] =
    queued match {
      case Some(q) if q.entry.isEmpty => {
        queued = Some(q.copy(entry = Some((addr, v))))
        unit(())
      }

      // One entry, and it is taken. Passing this write to [Cached] would commit
      // it ahead of the store already waiting, which is a reordering nothing in
      // the residue would show. Unreachable as the tower stands, because a
      // store is not [speculable] and so closes the window before a second one
      // could run; an ISA that lowers one instruction into two [set_mem] calls,
      // or a window that learns to hold more than one store, arrives here.
      case Some(q) =>
        sys.error(
          s"forwarding: a second store reached the queue inside the window at ${q.at}"
        )

      case None => super.set_mem(s, addr, v)
    }

  override def get_mem(s: Rep[State], addr: Rep[Int]): Rep[Int] = queued match {
    case Some(q) => q.entry match {
        case Some((qaddr, qval)) if resolved(q) => {
          // The address has resolved, so the queue answers on a tag match. It
          // is on the list either way: whether the match was the real thing is
          // [close]'s question, and this load took the value on trust.
          queued = Some(q.copy(forwarded = q.forwarded :+ addr))
          // The arms have to be the value of the virtualized `if` rather than
          // assignments to a `var`. A `var` here is an ordinary Scala variable
          // holding a [Rep], so it would name whichever arm was staged last and
          // the emitted C would read a symbol declared inside the other block.
          if (tag(qaddr) === tag(addr)) {
            s.timer += forwardCost
            qval
          } else { super.get_mem(s, addr) }
        }

        case Some(_) => {
          // Unresolved. The predictor guesses no-alias and this load reads
          // around the queue, which is only correct if the guess holds; the
          // address goes on the list [close] checks it against.
          queued = Some(q.copy(bypassed = q.bypassed :+ addr))
          super.get_mem(s, addr)
        }

        // The window is opening and the store has not reached [set_mem] yet,
        // which is a narrow store reading the word it is about to modify.
        case None => super.get_mem(s, addr)
      }
    case None => super.get_mem(s, addr)
  }

  override protected def run(pc: Int, w: Option[Window], s: Rep[State]): Rep[State] =
    queued match {
      case Some(q) => inside(pc, q, s)
      // A store window opens only with no branch window already open, and no
      // branch runs inside a store window because [speculable] refuses one.
      // That is what keeps the two from nesting.
      case None =>
        if (w.isEmpty && pc < prog.length && isStore(prog(pc))) { open(pc, s) }
        else { super.run(pc, w, s) }
    }

  // [step] runs the store, [set_mem] diverts it into the queue, and the
  // `call(pc + 1, s)` at the end of [step] finds [useCache] false and inlines
  // the rest of the window. So everything after this line happens inside
  // [step]'s continuation, and the close is [inside]'s to do rather than this
  // method's.
  private def open(at: Int, s: Rep[State]): Rep[State] = {
    queued = Some(Queued(at, None, Vector(), Vector(), Vector()))
    current = at
    step(at, s)
  }

  private def inside(pc: Int, q: Queued, s: Rep[State]): Rep[State] =
    if (pc >= prog.length || pc >= q.at + 1 + storeWindow) { close(q, pc, s) }
    else {
      speculable(prog(pc)) match {
        // No [reads] check, unlike [Predictive]'s window. A branch condition is
        // evaluated against the live register file at the join point, so a
        // speculated write to one of its inputs corrupts it; the store's
        // address and the bypassing loads' are [Rep]s captured where they were
        // computed, and a later write to the register they came from cannot
        // reach them.
        case Some(rd) => {
          queued = Some(q.copy(saved = save(s, q.saved, rd)))
          current = pc
          step(pc, s)
        }
        case None => close(q, pc, s)
      }
    }

  private def close(q: Queued, at: Int, s: Rep[State]): Rep[State] = {
    // Assigned before either [call], because it re-enables memoization and is
    // what makes them emit real C calls rather than inlining.
    queued = None

    // The store commits whichever way the alias goes, so it sits outside the
    // test rather than being written into both arms.
    q.entry.foreach((addr, v) => super.set_mem(s, addr, v))

    q.entry match {
      case Some((addr, _)) if q.bypassed.nonEmpty || q.forwarded.nonEmpty =>
        // [rollback] is [Predictive]'s, penalty included: a memory ordering
        // violation costs what a mispredicted branch costs, and both restore
        // every register the window saved. That is why control restarts past
        // the store rather than at the load that aliased. [q.saved] accumulates
        // from the window's open, so the offending load's pc is not a point the
        // register file was ever consistent at, and which load it was is a
        // runtime fact that a static program counter cannot be handed anyway.
        //
        // Two ways to have been wrong, and they are opposites. A load that read
        // around the store should not have aliased it; one that forwarded out
        // of it should have, and only the tag said so. [StrictOr] and not `||`,
        // which takes regions and would put each test in a block of its own.
        val wrong = q.bypassed.map(_ === addr) ++ q.forwarded.map(misforwarded(_, addr))
        if (wrong.reduce(_ | _)) {
          rollback(s, q.saved)
          call(q.at + 1, s)
        } else { call(at, s) }

      // Nothing read around the store and nothing forwarded out of it, so
      // there is nothing to have got wrong.
      case _ => call(at, s)
    }
  }
}
