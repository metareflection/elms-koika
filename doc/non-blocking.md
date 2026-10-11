# Running through a miss

```
	lw	x7, 0(x6)		# the probe. nothing below reads x7.
	addi	x8, x0, 0		# work that does not wait on any of it
	.rept	220
	addi	x8, x8, 1
	.endr
```

That is the bottom of [`hidden.s`](../src/test/asm/riscv/hidden.s). The top is
`2ctr`'s channel unchanged: prime a line, derive an address from the secret,
probe it, and the two runs disagree about whether that probe hits. Measured
natively across every secret the harness can draw:

| model | cycles |
|---|---|
| `cache` | 427 or 526 |
| `nonblocking` | 226, every time |

Every model to the left of `nonblocking` spends a miss the moment it happens, so
a hundred cycles of memory latency is a hundred cycles in which nothing else
runs. Hardware does not stop there. The load's destination is marked not-ready,
everything behind it issues anyway, and only the instruction that reads the
value waits. Ninety-nine cycles of that probe's miss fit inside the two hundred
and twenty instructions after it, so a machine able to run them has finished
paying for the miss before it runs out of work.

What that buys a side-channel model is that a miss stops being worth a fixed
hundred cycles. It is worth however much of it the program could not fill, which
is a property of the code around the load rather than of the load. So a secret
that moves a consumer nearer to or further from its producer is a channel with
no secret-dependent address anywhere in it, and a secret that only picks which
line gets installed may be no channel at all.

## What the model is

[`NonBlocking.scala`](../src/test/scala/elms/common/NonBlocking.scala) is sixty
lines of code under eighty of comment, and it is that short because `get_reg`
and `set_reg` are the single funnels for every register access in both ISAs.
The clock counts issues, one per instruction, and `reg_ready[i]` carries the
cycle register `i`'s value lands on. So:

- `get_reg` folds `max(issueAt, reg_ready[i])` into whatever is being staged,
  which is the same as asking when its last operand arrives;
- `set_reg` lands `reg_ready[rd] = issueAt + 1 + waiting`, after all of that
  instruction's reads have happened;
- `defer`, which is what a load calls and a store does not, records the latency
  instead of spending it;
- `finish`, at the end of `snippet`, folds `max(timer, reg_ready[i])` over every
  register.

`Isa` gained no method and neither `Exec` changed at all. No interpreter case
had to declare what it reads or what it writes, because going through the two
funnels is already that declaration.

That last hook is in-order retirement, and it is what keeps a load nobody waited
for from being free, which is the one thing a machine with a reorder buffer does
not do. What the program cost is then the later of the clock and the last value
to land, which is the critical path through the dependences rather than the sum
of the latencies.

`issueAt` starts at the clock rather than at the operands' arrival, and that is
not a rounding-up. Issue is in program order even when completion is not, so an
instruction cannot start before the machine has reached it however early its
inputs landed. An earlier version left that out and `2ctr` came out at 203
cycles with 204 instructions to issue.

## Two rows nobody wrote a demo for

`hidden.s` was written to go clean. `evict` and `spectre` were not.

`evict`'s gap is the eleven cycles between answering the probe out of L1 and out
of L2, and the load that carried the secret into a set is still outstanding when
that probe issues. The eleven land inside a hundred somebody is already paying
for, so they are not observable: 420 or 409 under `cache`, and 205 flat under
`nonblocking`.

`spectre`'s is the bigger one, and what it is about is the demo rather than the
cache. [`spectre.s`](../src/test/asm/riscv/spectre.s) never asks the cache anything
after the squash. Its gap is the *speculated* load's own latency, 124 cycles
against 223 under `predictive` depending on whether the line the secret picked
was already resident, and a machine that does not stall on a load never charges
a squashed one to anybody. `predictive_nb` answers 23 whatever the secret is,
which is eight instructions and a fifteen-cycle mispredict penalty.

That is the model being right and the demo being incomplete. Spectre is a
Flush+Reload attack and `spectre.s` has no reload in it.

## The reload

[`reload.s`](../src/test/asm/riscv/reload.s) is `spectre.s` with the probe put
back:

```
	bge	x10, x15, done		# taken, and the predictor says otherwise
	add	x5, x13, x10
	lw	x11, 0(x5)		# speculative secret load
	slli	x11, x11, 2		# mem is word-indexed, so scale
	lw	x12, 0(x11)		# secret-dependent address, installs the line
done:
	j	probe			# ends the window before the probe runs
probe:
	lw	x14, 0(x0)		# the reload, after the registers came back
```

| model | cycles |
|---|---|
| `cache` | 106, every time |
| `static` | 226 or 325 |
| `predictive` | 226 or 325 |
| `predictive_nb` | 26 or 125 |

The middle two rows agree because the branch runs once, so there is no history
for `predictive` to hold that `static` does not.

The last row is the point. The registers came back and the line did not, so a
model that throws away everything the window had in flight still reports
ninety-nine cycles, and they are the cache's rather than the stall's. `spectre`
and `reload` next to each other are what separate those two, and neither row
means much on its own.

The `j` is load-bearing, and it is about the model rather than about the
machine. `Predictive` resolves a window at the first instruction it cannot
speculate and tests nothing at the branch's own target, so a window walks
straight past that target and keeps going. Put the probe directly at `done` and
it runs inside the window, installs line 0 whatever the secret was, and the
re-executed probe after the squash hits every time. That was the first draft of
this demo, and it read clean for a reason that had nothing to do with the
claim.

## What a squash does to what is in flight

`Predictive.settle` charges the mispredict penalty and puts the saved registers
back. What it says about in-flight ready times it now says through two hooks on
`Common`, both of which are nothing for every model that stalls:

`untimed` marks the register traffic that is the tower's rather than the
program's. Saving a register against a rollback, putting one back, and reading a
branch's operands at the join point where the answer is wanted are all
bookkeeping, and a model that times register accesses has to be told so. Without
it, a saved copy's arrival folds into whatever instruction happens to be
staging, which is both wrong and quiet: the accumulators are `Rep`s belonging to
one generated function, so a save at a slot boundary mixes in a symbol from
another one.

`squash` is what a flush does. `NonBlocking` answers `reg_ready[i] = timer` for
every `i`, because a machine that has just thrown its work away is waiting on
none of it. That is the one place this model asserts something a real machine
only approximately does: a discarded miss still occupies the memory system, so a
later miss queues behind it, and modelling that means modelling how many can be
outstanding at once. Nothing else in this tower has a structural hazard in it.

The other answer is to let the window's outstanding misses land at retirement
anyway, which is what happens with no hook at all, and it is not obviously
wrong. It reports `spectre` at 208 cycles against 109 and `reload` at 208
against 125. So the two readings of a squash disagree on exactly the demo with
no probe in it, and agree that the one with a probe leaks.

What `squash` must not undo is the cache, and that is the other half of what
`reload` tests.

## What it costs a checker, which the cache taught the hard way

Nothing here costs what the set-associative cache cost. A set-indexed cache
subscripts every array with an expression nobody knows and array theory is what
a bounded model checker charges for; `branchy` went from 6.1s to over 600s and
had to drop from twelve probes to four.

Register numbers are static in this staging model, so `reg_ready` subscripts are
*constants* in the residue: `reg_ready[11]`, never `reg_ready[i]`. The bill is
width only, and `max` is branchless, `b + max(a-b, 0)` off the sign bit, so it
adds no arms. Same trick the tag comparison uses.

| file | lines | CBMC |
|---|---|---|
| `riscv/cache/2ctr` | 490 | 0.35s |
| `riscv/nonblocking/2ctr` | 666 | 0.44s |
| `riscv/predictive/2ctr` | 516 | 0.37s |
| `riscv/predictive_nb/2ctr` | 786 | 0.53s |

Most of each difference is the thirty-two unrolled `max`es in the drain, which
is emitted whether or not the program ever wrote the register. Folding over only
the registers a program touches is a staging-time question and would cut most of
it.
