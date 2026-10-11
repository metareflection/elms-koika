# Reading around a store

`forwarding` is the fifth model and the only one with anything in flight. Every
other model commits a store the instant it executes, which is what
`Isa.speculable` demands: rollback restores registers and nothing else, so a
store that ran speculatively could never be taken back. A queue removes the
demand rather than working around it. The store waits, a squash discards it, and
the write-back to memory that `runCache` carries a `CR-soon` about never happens.

What that buys is a channel speculation alone does not have. A load issued
before the queued store's address has resolved cannot know whether the two
alias, so the disambiguation predictor guesses they do not and the load reads
memory: the word the store was about to overwrite rather than the word it wrote.
[`bypass.s`](../src/test/asm/riscv/bypass.s) is seven instructions of that.

```
	andi	x6, x10, 28		# the attacker picks which word
	addi	x6, x6, SECRET		# p = &secret[(a0 >> 2) & 7]
	addi	x7, x0, 0		# the sanitizer
	sw	x7, 0(x6)		# scrub it. queued, not committed.
	lw	x11, 0(x6)		# read around the queue, so this is the secret
	slli	x11, x11, 2		# mem is word-indexed, so scale
	lw	x12, 0(x11)		# secret-dependent address, the channel
```

There is no branch in it, which is the point. `spectre.s` and `guarded` both
fill their row by getting a bounds check wrong, and every other model in the
tree sees nothing here at all: they commit the store where it stands, the load
reads the zero, and the channel address is 0 in both runs. Two knobs decide
the rest, `storeLatency` and `storeWindow` on `Forwarding`, at two and four
instructions.

CBMC's counterexample is worth reading, because the residue has two channels in
it and the witness picks the cheaper one. Both runs draw the attacker index 28,
so both queue the same store address and both read around it at word 27. The
secret sitting there is 0 in one run and 18 in the other, so the last load
probes word 0 against word 18, the alias resolves, and both runs squash. The
registers come back. The cache does not, so when the re-run probes word 0 the
run that already touched it pays a cycle for an L1 hit and the other pays a
hundred for a trip to memory. 228 cycles against 327, and 99 is the difference
between those two.

So this leaks the way `spectre` leaks, through a line the squash does not undo,
with the bypass rather than a mispredicted branch as the thing that gets a
secret into an address. The forwarding test itself is the second channel and the
witness does not use it: it reads `FALSE` in both runs above, because it is only
true when the secret equals the word index the attacker chose. It is a live fork
either way, and the arm it guards charges 1 where a miss charges 100.

[`bypass_ct.s`](../src/test/asm/riscv/bypass_ct.s) is the control, and the two
differ in one operand: the last load's base register is `x6` rather than `x11`.
Everything about the queue still happens, the secret still comes back from a
load that read around a store, and the forward still fires. What does not happen
is the secret becoming an address, and no model reports anything. One leaking
program says the channel exists; this one says the channel is the address rather
than the queue.

## Where the store is reached from

[`bypass_late.s`](../src/test/asm/riscv/bypass_late.s) is the same gadget behind a
bounds check that always passes, and it is the one that says where a store gets
noticed from. `Isa.speculable` refuses a store, so a store after a branch is the
instruction that *closes* the speculation window. The model this column used to
extend inlined its window, so it ran that closing instruction through `step`
rather than `call`, because `call` would have emitted a function call where the
rest of the window was straight-line code. `step` skips `execute`. So the
subclass heard about every instruction except the one most likely to interest
it, a store in this position queued nothing, and this program was clean under
`forwarding` and its speculating twin to the byte. A guarded write is an
ordinary shape, which made that most of the column going missing without a
failing test. The fix at the time was a hook in the base model, `closing`,
defaulting to `step` so nothing else moved.

The hook is gone and nothing replaced it. `Predictive` does not inline a window.
It resolves one by going back around through `Common.call`, so the instruction
that closed it reaches `run` the way every other instruction does and opens its
own window there with no special case. The saved registers sort themselves out
for the same reason: the branch's list rides in the slot key and is spent
resolving the branch, and `Forwarding.Queued` opens an empty one. Before, that
took an explicit save-clear-restore, so that a store window would not squash a
register the branch had got right.

[`dynstore.s`](../src/test/asm/riscv/dynstore.s) is what pins that down, and it is
the other question a one-entry queue invites: a store through an index that
moves, in a loop. Its `bge` speculates two instructions before the store closes
the window, so both lists are non-empty, and they now land in functions of their
own:

```c
struct StateT * slot_6(struct StateT * v334) {   // resolving the branch
  int v359 = v339 + 15;   v334->timer = v359;
  int v342 = v341[8];     v343[8] = v342;        // x8 and x5, the branch's
  int v346 = v345[5];     v347[5] = v346;

struct StateT * slot_8(struct StateT * v371) {   // inside the store window
  int v1037 = v720 + 15;  v371->timer = v1037;
  int v723 = v722[11];    v724[11] = v723;       // x11 and x6, the store's
  int v727 = v726[6];     v728[6] = v727;
  struct StateT * v730 = slot_9(v371);           // restart just past the store
```

It also says the queue costs nothing structural. The store window closes at the
backward jump, because no control flow is `speculable`, so the loop's slots are
the ones `predictive` would have emitted anyway and the residue does not grow
with the trip count. A window that inlined past that jump would not terminate.

## The forward that should not have happened

Everything above is the bypass. The forwarding path is in the residue too, and
until `bypass_alias.s` nothing in the tree leaked through it, for a reason worth
writing down rather than treating as a gap in the demos.

Forwarding out of a store to the same address is architecturally transparent.
The load gets the word memory would have given it, so no value anywhere in the
machine differs between an execution that forwards and one that probes, and the
only thing left to observe is the timer. The arm is chosen by comparing two
addresses, so for a secret to pick it one of those addresses has to be
secret-derived, which is what `runCache` charges for and `cache` therefore sees.
The one escape is an address that becomes secret-derived only on a path the
other models do not take, and the bypass is the only such path.

So forwarding can contribute to a gap, and in `bypass.s` it does, but never
without a bypass in front of it to put a secret where the comparison can reach.
It cannot be the whole story. There is a blunter version of the same point:
`Forwarding.forwardCost` is 1 and an L1 hit is also 1, so those two arms are not
even distinguishable in the timer. A second level is what makes that a statement
about L1 rather than about the whole cache, since a forward is now cheaper than
an answer from L2 by eleven cycles.

What is not transparent is a forward the queue should not have made.
`forwardBits` low bits of the word index decide it, not the whole address, which
is what hardware does and is where the channel comes from: a load whose tag
matches a store to a *different* word takes that store's value, which is the
wrong one. [`bypass_alias.s`](../src/test/asm/riscv/bypass_alias.s) is nine
instructions of that, with no branch and nothing bypassed.

```
	addi	x6, x0, SECRET		# word 20, where the secret lives
	lw	x5, 0(x6)		# read it, which every model does
	addi	x8, x0, 96		# word 24
	addi	x9, x0, 0		# word 0, public, and 0 == 24 mod 4
	sw	x5, 0(x8)		# the secret goes to word 24. queued.
	addi	x7, x0, 0		# two instructions of address latency
	addi	x7, x7, 1
	lw	x11, 0(x9)		# asks for word 0, gets word 24's secret
	lw	x12, 0(x11)		# secret-dependent address, the channel
```

Both addresses are `li` immediates, so the tag comparison folds and the load at
word 0 always takes the secret. The channel load then has a tag of its own,
`(secret >> 2) & 3`, and the witness is the two runs disagreeing about it: one
probes the cache at the secret's word for a miss and the other falsely forwards
again for a cycle. 430 against 331. The close catches both false forwards and
squashes, and the cache keeps the line.

Under every other model the load reads word 0 and gets the public zero, so the
channel address is word 0 in both runs and there is nothing to report. This is
the 4K-aliasing shape, scaled to sixty-four words the way the cache is scaled:
a real queue compares a twelve-bit page offset, which over an address space is a
curiosity and over `mem` would be exact.

## Most of the column is a copy

Only five programs in the tree put a store inside reach of a window. `2ctr`,
`spectre`, `reload`, `shortcircuit`, `constant_time`, `evict`, `hidden`,
`choose.o` and `folded.o` contain no store at all, and `guarded.o`'s is its last
instruction, so

`diff src/out/cbmc/riscv/{predictive,forwarding}/spectre.check.c`

is empty, and so are nineteen other pairs. Twenty of the thirty-two snapshots in
this column are their predictive twin to the byte, which is worth generating: a
model that only ever adds a channel has to leave a program with no store alone,
and the snapshots are the proof rather than the claim. The twelve that differ
are `salsa20`, `bypass`, `bypass_ct`, `bypass_late`, `dynstore` and
`bypass_alias`, once per backend.
