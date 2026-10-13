# What the models share

Here are two of the seven, as they are declared at the test site:

```scala
// src/test/scala/elms/riscv/naive.scala
trait NaiveDriver extends RiscVDriver[64] {
  override val init = Init.naive(stateT)
}

// src/test/scala/elms/riscv/nonblocking.scala
trait NbDriver extends RiscVDriver[64] with NonBlocking {
  override val init = Init.nonblocking(stateT)
}
```

One is an in-order machine that stops the world for a hundred cycles on a cache
miss. The other issues past the miss, tracks when every register's value lands,
and reports a program's cost as the critical path through its dependences. The
difference between them in the source is `with NonBlocking` and which C
initializer gets emitted.

And the join of the two most complicated models is this, in full:

```scala
// src/test/scala/elms/common/NonBlocking.scala
@virtualize
trait PredictiveNonBlocking extends Predictive with NonBlocking
```

The body is empty because there was nothing to write. This document is about
what has to be true of an interpreter for that to be the case.

## One `step` per ISA, and nobody overrides it

`Isa.step` is the non-speculative semantics of one instruction, and the whole
tree defines it exactly three times: once in `riscv/Exec.scala`, once in
`nanorisc/Exec.scala`, and once in `squared/Exec.scala` for the pair-of-runs
tower. No micro-architectural model overrides it. Not the cache, not the branch
predictor, not the store queue, not the non-blocking memory system.

Here is the whole of the RV32I register-register ALU rule:

```scala
case Instr.Op(op, rd, rs1, rs2) => {
  write(s, rd, alu(op, readReg(s, rs1), readReg(s, rs2)))
  call(pc + 1, s)
}
```

Two things in that are not the ISA's. `call(pc + 1, s)` is how control leaves,
and `tick(s)` at the top of `step` is the clock. Everything else is RISC-V.
There is no cache in it, no timing beyond the one tick, and no mention of
whether the machine is speculating.

That is the shape the rest of this rests on, so it is worth stating as a rule
rather than as an observation. **The ISA writes the data path. The model writes
what the data path costs and where it goes next.** The ISA never asks which
model it is running under, and no model reaches into a rule to change what an
instruction computes.

## Where does a model get in, then?

Through a fixed vocabulary of seams on `Common`, each with a default that makes
the naive model fall out of doing nothing.

| Seam | Default | Overridden by |
| --- | --- | --- |
| `tick(s)` | `timer += 1` | `NonBlocking`, to reset its accumulators |
| `spend(s, lat)` | `timer += lat` | nobody |
| `defer(s, lat)` | `spend(s, lat)` | `NonBlocking`, to charge a waiter instead of the clock |
| `untimed(body)` | `body` | `NonBlocking`, to exclude the tower's own register traffic |
| `squash(s, saved)` | nothing | `NonBlocking`, to release the window's registers |
| `finish(s)` | `s` | `NonBlocking`, for in-order retirement |
| `get_reg` / `set_reg` | the array | `Direct`, then `NonBlocking` |
| `get_mem` / `set_mem` | the array | `Direct`, then `Cached` |
| `slot(pc)` | `(pc, retstack)` | `Speculative`, `Squared` |
| `resume(at, s)` | `step(pcOf(at), s)` | `Speculative`, which inserts `run` |

`spend` and `defer` do the same thing in `Common`, and the split is the single
most load-bearing line in the file:

```scala
def spend(s: Rep[State], lat: Rep[Int]): Rep[Unit] = s.timer += lat
def defer(s: Rep[State], lat: Rep[Int]): Rep[Unit] = spend(s, lat)
```

A store goes through `spend` because nothing waits on one. A load goes through
`defer` because somebody does. In a blocking model those are the same sentence,
so `Cached` can be written without knowing the difference exists, and `Cached`
is where every latency in the tower is computed:

```scala
case Some(x) => { spend(s, latency(ps)); store(...); x }
case None    => { defer(s, latency(ps)); s.cache_vals(...) }
```

`latency(ps)` is selected arithmetically out of the probe masks rather than
charged inside the arms of an `if`, so the number exists as a `Rep[Int]` in its
own right. A model that wants to hand it to somebody other than the clock has
something to hand over. A cache that had already spent it would not.

## How the naive and non-blocking interpreters are related

Literally: by prefix.

```
Common  <-  Direct  <-  Cached  <-  NonBlocking
   ^           ^
   |           |
   |        naive = Direct (via riscv.Exec)
   |
 the worklist, the seams, the slot protocol
```

`riscv.Exec extends Direct`, `Cached extends Direct`, `NonBlocking extends
Cached`. The naive model's linearization is a prefix of the non-blocking one's.
Everything the naive model is, the non-blocking model still is. The two traits
stacked on top override nine methods between them and introduce no new ones
into the interface the ISA sees.

`NonBlocking` overrides seven: `tick`, `defer`, `untimed`, `squash`, `finish`,
`get_reg` and `set_reg`. The first five are the seams above. The last two are
the interesting part.

### Operand interception

No method in `Isa` says what an instruction reads or writes. There is no
`sources(i): Set[Reg]` and no `dest(i): Option[Reg]`, and adding either would
have meant writing the dependence structure of RV32I a second time, beside the
copy already implicit in `step`.

Instead, `NonBlocking` intercepts the register file:

```scala
override def get_reg(s: Rep[State], i: Rep[Int]): Rep[Int] = {
  if (timing) { issueAt = Some(issueAt.fold(s.reg_ready(i))(later(_, s.reg_ready(i)))) }
  super.get_reg(s, i)
}

override def set_reg(s: Rep[State], i: Rep[Int], v: Rep[Int]): Rep[Unit] = {
  if (timing) {
    val at = issueAt.getOrElse(s.timer)
    s.reg_ready(i) = waiting.fold(at + unit(1))(at + unit(1) + _)
  }
  super.set_reg(s, i, v)
}
```

Every operand an instruction reads passes through the first, so accumulating
the later of them is the same question as "when does the last operand arrive".
Every destination passes through the second, after all of that instruction's
reads, because `step` is written in direct style and Scala evaluates the
argument before the call. The dependence graph is recovered from the order of
effects during staging rather than declared anywhere.

Call it **operand interception**, because it is what the next two sections are
about. It is also why a new ISA gets non-blocking loads for free: `nanorisc` has
never heard of `reg_ready`, and `NonBlocking` has never heard of NanoRisc, and
mixing them works because both of them go through `get_reg`.

The discipline interception demands is that a model must be able to tell the
program's register traffic from the tower's. A `Predictive` window copies a
register into `saved_regs` before letting a speculated instruction write it, and
resolves a branch's condition several instructions after the branch was staged.
Neither is an access a machine would make, and folding either into whatever
instruction happens to be staging is both wrong and quiet. `untimed` is the
declaration:

```scala
val taken = untimed { evalCond(asOfBranch(s, saved), p.cond) }
```

In `Common` it is the identity function, which costs the five models that do not
time register accesses nothing at all. In `NonBlocking` it flips a flag that the
two interceptors read. That one seam is the entirety of what `Predictive` and
`NonBlocking` had to agree about in order to compose, and it is why the join
needed no body.

### What it does to the residue

Here is `slot_2` of `2ctr`, which is one `slli`, under the naive model and under
the non-blocking one. Same demo, same slot number, same program:

```c
/* src/out/cbmc/riscv/naive/2ctr.check.c */
struct StateT * slot_2(struct StateT * v38) {
  int v39 = v38->timer;
  int v46 = v39 + 1;
  v38->timer = v46;
  int * v41 = v38->regs;
  int v42 = v41[11];
  int v49 = v42 << 2;
  v41[11] = v49;
  struct StateT * v44 = slot_3(v38);
  return v44;
}

/* src/out/cbmc/riscv/nonblocking/2ctr.check.c */
struct StateT * slot_2(struct StateT * v230) {
  int v231 = v230->timer;
  int v242 = v231 + 1;
  v230->timer = v242;
  int * v233 = v230->reg_ready;
  int v234 = v233[11];
  int * v235 = v230->regs;
  int v236 = v235[11];
  int v246 = (v234 + ((v231 - v234) & (~((v231 - v234) >> 31)))) + 1;
  v233[11] = v246;
  int * v238 = v230->regs;
  int v248 = v236 << 2;
  v238[11] = v248;
  struct StateT * v240 = slot_3(v230);
  return v240;
}
```

The architectural lines are the same lines. `timer + 1`, `regs[11] << 2` back
into `regs[11]`, tail call to `slot_3`. What the second one adds is a read of
`reg_ready[11]`, the branchless maximum of that against the clock, and a write
of the result plus one. The subscript is a constant in both, which is why none
of what a set-indexed cache costs a bounded checker applies to the register
file.

`finish` is the other half and it lands in `snippet` rather than in a slot: one
`later(timer, reg_ready[i])` per register, thirty-two of them in a row, so that a
miss nobody waited for is still paid for at the end. That is in-order retirement
and it is the reason a load whose value is never read is not free.

## Staging-time state, and the two places it can live

Every model in the tower carries state that exists while the interpreter runs
and not afterwards. The return stack, the branch predictor's history, the
pending branch window, the store queue, the two non-blocking accumulators. Where
each one goes is the design decision the whole tower turns on, and there are
exactly two answers.

**Interned into the slot key.** `Common.slot` keys an emitted function on
`(pc, retstack)`. `Speculative.slot` keys on `Key(pc, window, learned, stack)`.
`Squared.slot` keys on `(pc, active, retstack)`. Anything in the key survives a
control transfer, because the transfer is to a function that was staged under
that key and no other.

**Scoped inside one instruction.** `NonBlocking`'s `issueAt` and `waiting` are
ordinary Scala `var`s holding `Rep[Int]`, which is normally a staging bug: a
`Rep` names a class in the e-graph of whichever function is open, so one that
outlived a function boundary would reach whatever that index happens to mean in
the next one. They are sound because `tick` resets them at the top of every
`step` and both are consumed before that `step` returns. Neither ever crosses a
slot boundary.

`Predictive` says the general version of this better than a summary would:

> The slot key is the specialization boundary. What goes in it is partially
> evaluated and what stays in `State` is residual, and the two together are
> what the end-to-end system accounts for.

A predictor whose history is in the key has no predictor in the generated C at
all. The functions one pc is numbered into *are* the predictor, written as
control flow rather than as a table. That is free in the residue and exponential
in the key. Two measurements from `HistoryFanoutSuite`, and they are different
cases rather than one number twice. Seven balanced branches in a row number one
pc into 985 functions when the key holds the whole history map and 46 when it
holds only the entries something downstream can still read, which is what the
model emits carrying no history at all. Inside a loop no entry is dead, so that
drop buys nothing, and the seven-branch loop is 123x for a bit per branch
against 15.6x for four bits of global register. `GlobalHistory` is the identical
model with that one boundary moved, and `doc/global-history.md` is the
measurement.

A cache index was never a candidate for the key, because it is data-dependent
and cannot be anywhere but `State`. That asymmetry is the whole content of the
phrase "which micro-architectural state is specialized away".

### The third place, and the switch that makes it work

`Forwarding`'s store queue is a `Rep` pair in a Scala field that has to survive
*several* instructions, which is neither of the two answers above. It works
because of one line:

```scala
override def useCache: Boolean = super.useCache && queued.isEmpty
```

`useCache` is `Common.call`'s inline-or-emit switch. While the queue is
occupied, `call` stages the rest of the window inline instead of declaring a
slot for it, so there is no function boundary for the captured `Rep`s to cross.
The queue drains, `useCache` goes back to true, and the next `call` emits a real
C call again.

It is worth naming because it is the one escape hatch in the tower, and it is
the reason `Forwarding` can model Spectre v4 at all: the store sits in the queue
for `storeWindow` instructions, loads behind it read around it, and a squash
discards the store before `Cached` ever hears about it. A model that committed
the store at `set_mem` could not have that channel, which is what
`Isa.speculable` refusing stores outright is there to enforce in the five models
that do.

## The slot protocol

`Common.call` is six lines and all seven models inherit it unchanged:

```scala
def call(i: Int, s: Rep[State]): Rep[State] = {
  if (useCache) {
    val at = slot(i)
    if (live(at)) { declare(at)(s) } else { s }
  } else { resume(slot(i), s) }
}
```

`declare` puts the slot on a worklist the first time anything asks for it and
hands the call site an `unsafeDeclare` of the name that slot's function *will*
be given. Nothing is staged there. A separate `drain()` loop pops the worklist
and calls `fun(slotName(at)) { s => resume(at, s) }` per slot, so every body is
staged at the same depth.

The reason that matters is a bug this shape fixes: staging a body inline nested
one `fill` per instruction, and a few hundred instructions of RISC-V is enough
to overflow the JVM stack. Emitting the residue as a worklist of mutually
tail-calling C functions makes how deep the program's own call graph runs stop
being a question about the host's stack.

Two things ride along with the worklist. `checkpoint()` captures the
staging-time state a slot's body will need and the `drain` loop restores it
before staging, which is how a `var` that the ISA rules read can be correct at a
point in the program far from where the `call` that asked for the slot sat.
Every model but `Common` interns the rest of its own into the slot number
instead.

And `shareable(target)` decides per callee whether a function is specialized
into its caller or emitted once. The two questions are separate on purpose:
`inlineCalls` is the model's willingness to share, `shareable` is whether this
particular call can be. A shared callee has one exit, so the staging-time
history at that exit depends on which path reached it, so a predictor's history
cannot flow back out to the caller. `carriesHistory` is the flag, `riscv/Flow`
is the analysis that answers it per call site, and `Static` turns the whole
question off by recording nothing.

## Two towers, one skeleton

`common/` and `squared/` have no ancestor between them, and the correspondence
between them is one-for-one anyway:

| `common/` | `squared/` |
| --- | --- |
| `Common` | `Squared` |
| `Direct` | `Flat` |
| `Cached` | `Cached` |
| `NonBlocking` | `NonBlocking` |
| `Speculative` / `Predictive` | `Speculative` / `Predictive` |
| `Returns` | `Returns`, the same file |
| `Isa.step` | `Squared.step` |
| `State` | `Half`, under a `Pair` |

The seam names line up too: `tick`, `spend`, `defer`, `untimed`, `squash`,
`finish`, `slot`, `resume`, `checkpoint`, `liveBranchesAt`. The squared
`NonBlocking` says in its header that those seams "had no instance until now,
which is why each says in its own comment what it would mean rather than what it
does", which is the honest version of what a seam with one implementation is.

A reviewer will ask why this is not one hierarchy, and there are two answers
rather than one.

The arity differs. A `common` slot takes one state and a squared slot takes a
pair, and `Squared.each` is what runs a rule once per side. Every rule under
`Machine` is still written for a single run, so the duplication is of the
plumbing rather than of the semantics.

The value domain differs. `Machine` abstracts over `Rep` so the same semantics
instantiates twice: `Stage`, where `Rep` builds IR and a slot becomes an emitted
C function, and `Run`, where `Rep` is the identity and the same rules are an
ordinary Scala interpreter over `Chip`. `common` has no such instantiation,
because `Rep` there is always the staged one. A `Run` that executes the same
lines `Stage` stages is a cheap correctness oracle for the staging, and that is
worth more than collapsing the two trait hierarchies would be.

That said, the duplication is real and it is maintained by hand. `squared/Exec`
is described in its own header as "a transcription of
`elms.koika.test.riscv.Exec`", and `Machine`'s field names are `StateT`'s on
purpose, "so the memory model here and the one in `common/Tower.scala` diff
against each other". The two caches agreeing is a thing someone checks by
reading, not a thing the type system enforces.

## What this buys, as a claim

The models are a lattice and not a line. `naive` is the bottom, `Cached` sits
above it, `Static`, `Predictive` and `Forwarding` chain on top of `Cached`,
`NonBlocking` is a second branch off `Cached`, and `PredictiveNonBlocking` is
the join. `doc/models.md` reads the verdict table across that lattice and says
which rows each step adds and which rows `NonBlocking` takes away.

The structural claim is that the join needed no code. Two micro-architectural
features that interact in hardware, a front end that runs ahead of the branch
and a memory side that does not stop for a miss, compose as a Scala trait
intersection because each of them only ever touched seams the other had answers
for. `Predictive` says which register accesses are the machine's through
`untimed`. `NonBlocking` answers both halves of that. Everything else the two do
is disjoint, since one decides which instructions run and the other decides when
their values land.

It is a join and not a step, and neither half decides its verdicts. `spectre`
reads clean under `PredictiveNonBlocking` the way it does under `NonBlocking`
alone, and `reload` reads leak the way it does under `Predictive` alone. What
separates those two demos is whether anything asks the cache a question after
the squash.

## Where the shape is weakest

Two places, and they are worth stating in a paper rather than discovering in
review.

The seams were designed against the models that exist. `defer` is a seam because
somebody wanted `NonBlocking`, and `untimed` is a seam because `Predictive` and
`NonBlocking` had to meet. A model nobody has written yet may need a seam that
is not there: a variable-latency multiplier wants `tick` to take the instruction
rather than nothing, and `Common`'s comment says so and declines to add it.

`squash` is the one place `NonBlocking` asserts something a real machine only
approximately does. A miss the squash discards still occupies the memory system,
so a later miss queues behind it, and modelling that means modelling how many
can be outstanding at once. That is a structural hazard and nothing else in this
tower has one.
