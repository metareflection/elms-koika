# Collapsing Towers for Side-Channel Security

We explore multi-stage programming to detect side-channel
vulnerabilities in hardware-software systems via the technique of
_[Collapsing Towers of Interpreters](http://popl18.namin.net)_.
The idea is to specialize
an assembly program
wrt
a hardware processor written as a staged interpreter (including micro-architectural details like speculation and data caching)
and produce a *residue* C program
semantically equivalent to the original assembly program
but with explicit micro-architectural details, including the side-channel information reified into first-order variables.
An off-the-shelf analyzer (like [CBMC](#CBMC)) can then analyze the residue C file to check whether the first-order timing and secret inputs are noninterfering.

## Publications

This work is an adaptation of the work described in [PEPM '25](https://popl25.sigplan.org/details/pepm-2025-papers/4/Collapsing-Towers-for-Side-Channel-Security-Short-Paper-) to Scala 3 and [ELMS](https://github.com/metareflection/elms).

The source code corresponding to that paper can be found in [`src/test/scala/elms`](src/test/scala/elms).

## Running the examples

This generator project requires [sbt](https://www.scala-sbt.org/) and Java version >21.
We depend on [ELMS](https://github.com/metareflection/elms)
([vendored](vendor/elms)).

The RISC-V tests read their programs out of object files rather than out of
Scala, so those have to be assembled first:

`./src/test/asm/riscv/build`

That wants either `clang`, whose integrated assembler covers RISC-V and so needs
no cross toolchain, or a `riscv{64,32}-*-gcc`. The `.o` files are not checked in,
and a suite that cannot find one aborts with a message naming the script.

Running `sbt test` from the root will run all the tests, generating `.actual`
files and checking them against the `.check` files under
[`src/out/cbmc`](src/out/cbmc) and [`src/out/klee`](src/out/klee), one tree
per backend.
Failing tests will leave the generated `.actual` files for inspection.
Snapshot files mostly follow the naming convention of `[testfile]/[suffix].check.c`.

The examples are verified twice, once with [CBMC](#CBMC) and once with
[KLEE](#KLEE). CBMC first.

`cbmc -DCBMC --verbosity 4 --slice-formula --unwind <N> --refine --compact-trace --no-standard-checks <file.c>`

`--no-standard-checks` leaves CBMC nothing to check but the residue's own
assertions. Without it, it also checks every automatic property it generates,
which on `fact/naive/salsa20.check.c` is 6536 of them: pointer dereference
checks, overflow, array bounds, undefined shift. Those ask about the generated
C rather than about the program it models, and on anything past the
twenty-instruction demos they are the entire cost. That file answers in four and
a half seconds with the flag and had not finished in seventy-two minutes
without. No verdict moves either way.

`<N>` comes out of the file. `GenericKoikaDriver.unwind` is
`max(num_regs, mem_size, cache_words, cache_entries, secret_size) + 1`, which is
every loop in the hand-written C around the residue plus the exit test, and a
demo whose own recursion runs deeper than that overrides it. 65 everywhere now
that the demos and the FaCT ports run on the same 64 words of memory, where the
tree used to run everything at 1000 and pay 172 seconds for `compiled/naive`
alone.

Falling short does not make a leak disappear, it invents one. The initializer
loops in `init` are the first thing a low bound cuts, and two states left
half-written disagree on garbage, which is indistinguishable from a real finding
by exit code. So `verify --certify` re-runs every file with
`--unwinding-assertions` and fails on any bound that does not cover what it
claims to.

Most `.check.c` files are not expected to verify. They are demonstrations that
CBMC can find a vulnerability, so the leak is the result and a clean run would
be the failure. Which is which is a property of the pair, the demo and the model
it runs on, and each test says so where it calls `check`:

```scala
test("riscv naive spectre") {
  val snippet = new NaiveDriver {
    override val prog = demo("spectre")
  }
  check("spectre", snippet, Verdict.Clean)
}
```

`Verdict` is a required argument, so a new demo does not compile until somebody
has said what should happen to it. `check` writes the claim into the first line
of the generated C, which makes it part of the snapshot `sbt test` pins, and
[`verify`](src/out/cbmc/verify) reads it back out and runs the checker:

`./src/out/cbmc/verify [--certify] [file.c ...]`

With no arguments it takes every snapshot in the tree, 129 of them in 126
seconds.
It prints one line per file and exits non-zero if CBMC says anything other than
what the file claims, so a model that stops detecting what it used to detect is
a failing run rather than a stale comment. The claims themselves are greppable
without running anything:

`head -qn1 src/out/cbmc/**/*.check.c`

The tree under [`src/out/cbmc/lockstep`](src/out/cbmc/lockstep) is the same demos answered
a different way. `Lockstep` rewrites a residue into a product of itself with
itself, so one run of one copy of the control flow carries both states and the
timers are compared on entry to every slot rather than once at the end. Every
verdict there has to match its twin next door, because the two are answering the
same question about the same program.

What that buys depends on who is holding the bill, and the bill changed hands
when the cache did. Sharing the control flow makes every timer comparison an
assumption as well as a question, so a pair that has already drifted leaves the
search instead of being enumerated and rejected. That is a claim about a path
space, and against the old two-entry cache it was worth five times: `branchy` at
eighteen probes was 30.1s lockstepped against 149.9s self-composed.

A set-associative cache moved the cost somewhere the pass does not reach. What
is expensive now is array theory over subscripts nobody knows, and lockstepping
doubles the updates in flight while pruning none of them. `branchy` at six
probes is 41.2s against 40.4s, and at the four it ships with it is 1.63s against
1.48s. Twice, no difference, and if anything the wrong way.

So the pass currently earns nothing in time, and it is kept for the other thing
it does: every verdict in that tree has to match its twin next door, which is a
second opinion on the same program from a differently shaped formula. Its speed
argument is waiting on a demo whose cost is a path space, and the tree does not
have one at the moment.

Here is what they currently say. The first three demos exist for both NanoRisc
and RISC-V and answer the same on each, so the table does not split them;
NanoRisc has only the first three models, and RISC-V is what fills the rest.
The blanks are suites nobody has written: `cmp` under cache, `cmp` and
`branchy` under forwarding, and the FaCT and NanoRisc programs under the last
two columns, which are RISC-V only so far.

| demo | naive | cache | speculative | predictive | forwarding | nonblocking | predictive_nb |
|---|---|---|---|---|---|---|---|
| `shortcircuit` | leak | leak | leak | leak | leak | leak | leak |
| `2ctr` | clean | leak | leak | leak | leak | leak | leak |
| `evict` | clean | leak | leak | leak | leak | clean | clean |
| `hidden` | clean | leak | leak | leak | leak | clean | clean |
| `spectre` | clean | clean | leak | leak | leak | clean | clean |
| `reload` | clean | clean | leak | leak | leak | clean | leak |
| `constant_time` | clean | clean | clean | clean | clean | clean | clean |
| `cmp` | leak | | leak | leak | | | |
| `salsa20` | clean | clean | clean | clean | clean | | |
| `guarded` | clean | clean | leak | leak | leak | | |
| `choose` | clean | clean | clean | clean | clean | | |
| `folded` | leak | leak | leak | leak | leak | | |
| `branchy` | clean | clean | clean | clean | | clean | clean |
| `bypass` | clean | clean | clean | clean | leak | clean | clean |
| `bypass_ct` | clean | clean | clean | clean | clean | clean | clean |
| `bypass_late` | clean | clean | clean | clean | leak | clean | clean |
| `dynstore` | clean | clean | clean | clean | clean | clean | clean |
| `bypass_alias` | clean | clean | clean | clean | leak | clean | clean |

`evict` is the row the geometry was for, and it is a stronger statement than
`2ctr` next to it. `2ctr` needs a cache of some kind. `evict` needs a cache with
*sets* in it: the secret picks which set gets a line installed, so the channel
is a conflict rather than an address. The program has no branch in it and reads
around no store, which is why `speculative`, `predictive` and `forwarding` are
copies of the `cache` answer. The last two columns are not, and the section on
running through a miss is about why.

That a cache without sets answers clean here is a claim about what a model
cannot see, so it is a test rather than a sentence.
[`RiscVFlatTests`](src/test/scala/elms/riscv/flat.scala) is the same `Cached`
at one set of two ways over one-word lines, which is the shape this tower
carried before, and `src/out/*/riscv/flat` is two files: `evict` clean, and
`2ctr` still leaking so that the control is not merely a model too weak to
report anything.

Reading across the first four columns is the tower. No model there loses a leak
the one to its left could see, and `2ctr` and `spectre` are where it starts
seeing more: `2ctr` needs a cache before the second load's address can cost
anything, and `spectre` needs speculation before that load happens at all.
`guarded` is `spectre`'s row written again and `folded` is `shortcircuit`'s, and
the FaCT section below is why either was worth a demo of its own.

That sentence stops at the fourth column, and the three after it are each a
different reason why. `forwarding` is merely unordered against `predictive`: it
extends `speculative` and so catches everything that does, but it has no branch
predictor in it and `predictive` catches `bypass` no better than `naive` does.

`nonblocking` is the one that breaks the shape. It takes rows away. `evict`,
`hidden` and `spectre` all read leak under `cache` or under `speculative` and
clean under a model that does not stop the world for a miss, and in every one of
them the column to the left is what is wrong: the gap it reports is a stall the
program could have run through.

That is a different kind of column and it should be read as one. A model that
only ever adds channels can only ever be too careful, so its clean verdicts are
cheap to trust. This one can be too permissive, so a clean answer here is a
claim about the machine as well as about the program. What keeps each of those
rows honest is its twin next door. `cache/hidden` still leaks, so
`nonblocking/hidden` going clean cannot be somebody having flattened the
gadget.

`predictive_nb` is the join of the two either side of it, and it exists because
neither alone settles what speculation leaks. It agrees with `nonblocking` on
every row but `reload`, which is `spectre` with the probe an attacker would
actually perform, and that row is the one that says the speculative channel is
the cache line rather than the stall.

So the traits are a lattice rather than a line: naive, then cache, then
speculative or nonblocking on top of that, with `forwarding` and `predictive_nb`
as joins. Only the first four columns are also ordered by what they report.

`branchy` is RISC-V only, and it is a walk over four addresses nobody knows and
everybody agrees on. That is the one shape in this tree whose cost is the
solver rather than the elaborator. Every other clean demo is cheap for the wrong
reason, `constant_time` because it has three branches and `salsa20` because it
has none, so neither says anything about a checker that has to rule out a path
space rather than exhibit one member of it.

## What the cache is

```
L1   2 sets x 2 ways x 2 words   1 cycle
L2   4 sets x 2 ways x 2 words   12 cycles
mem  64 words                    100 cycles
```

Twelve line frames over thirty-two lines of memory, LRU within a set,
write-allocate, write-through at L1 and write-back at L2. That is
[`Geometry.default`](src/test/scala/elms/common/Geometry.scala), and everything
in it is a knob.

Three tiers rather than two is what `evict` reads. Its counterexample is 420
cycles against 409, and the eleven between them is exactly
`L2.hitCost - L1.hitCost`: one run answers its last probe out of L1 and the
other has to go a level down for it. Under one level that same gap would have
been ninety-nine, indistinguishable from any other miss, and
`Forwarding.forwardCost` would still be colliding with it.

What it replaces was two entries of one word each, fully associative, with no
valid bit and no dirty bit. That was enough to demonstrate a channel, which is
what it was for. It could not state the argument real constant-time code makes,
because every one of those is about lines and about sets.

A lookup table is safe because it fits in a cache line. A model whose line is
one word reports sixteen distinct probes where the hardware has one, so it
cannot tell a table that fits from a table that does not, and the distinction is
the entire claim. Prime+Probe works by filling a set. With two fully associative
entries an attacker evicts the whole cache by touching two addresses, so the
canonical cache attack was not expressible here at all.

### Three knobs, and only one of them costs

Sets are free. The set index is a `Rep`, so `cache_tags(base + set * ways + w)`
is one symbolic subscript into inline storage however many sets there are, which
is what `mem` already was.

Ways are nearly free, and that takes doing. The obvious spelling of a W-way
lookup is a chain of `if`s, which is W+1 arms in the residue and (W+1)^n paths
over n probes. This one compares tags in arithmetic instead:

```scala
// -1 when the two are equal and 0 otherwise, out of a sign bit rather than out
// of a comparison. `d | -d` has its top bit set for every d but zero.
private def eqMask(a: Rep[Int], b: Rep[Int]): Rep[Int] = {
  val d = a ^ b
  ~((d | (unit(0) - d)) >> unit(31))
}
```

At most one way can match, so the matching way number is the `or` of the masked
way indices and whether there was one is the `or` of the masks. W ways is W
expressions and still exactly two arms. The LRU ages and the victim choice go
the same way, off the sign bit of a subtraction.

Staging `2ctr` against a four-way L1 rather than the two-way one says how well
that holds. Seven `else` branches in the residue either way, the same seven, and
557 lines against 489. Double the associativity for fourteen percent of the
width and none of the depth, which is the whole reason the geometry is a
parameter rather than a rewrite.

Levels are what costs, one arm apiece. So a probe forks threefold, into L1, L2
and memory, which is exactly what the two-entry LRU did with head-hit, tail-hit
and miss.

The bill is width rather than depth. `riscv/cache/2ctr` is 489 lines of residue
against 266, and `fact/cache/salsa20` is 19993 against 8410. That much a reader
would predict, and it is not where the interesting cost turned out to be.

### What it costs a checker, and where that cost actually is

The path space did not move. Both models fork threefold per probe, so
`branchy`'s walk is (3^n + 1) / 2 paths either way. What got expensive is each
individual query, and the reason is one line of the old model:

The old cache compared `cache_keys[0]` against `cache_keys[1]`. Constant
subscripts, which a solver treats as two scalars. A set-indexed cache subscripts
every one of its arrays with an expression nobody knows, so every read is a
select over a chain of updates at unknown indices, and the run issues a hundred
or so of those.

Both backends pay it, and they show it differently. CBMC builds one formula and
its cost lands there: `branchy` runs 1.4s at four probes against 38.5s at six,
where the old model did twelve in 6.1s. KLEE pays per path, and inside a
two-minute budget it does not finish even one: 0 completed against 23 partially
completed, which is why those files carry `Reach.LikelyTimeout` again after a
spell without it. Give it the 1200 the budget has since grown to and it does
finish, in 814s. Counting paths is what nobody should guess from: `2ctr` walks
exactly 3 completed paths under both models, the old one and this one, and its
KLEE verdict never moved.

So `branchy` ships four probes where it used to ship twelve. The demo's job is
to be the one file in the tree whose cost is the solver, and it still is; the
count was always a dial and the dial moved.

Nothing without a symbolic address in it noticed, which is the other half of the
same sentence. `salsa20` is 277 instructions of literal indices, so every set
index folds at staging time and no subscript is ever unknown. It went from 5.4s
to 9.5s, a residue 2.4x wider and a solver doing the work it always did.

### Where a store stops

L1 is write-through and L2 is write-back, which is a real design and is also the
only one that keeps the model honest about ordering. A dirty line has to be
written back when it is evicted, and a write-back from level i mutates level i+1
in the middle of an access that has already read level i+1's tags. Nothing above
the bottom is ever dirty, so that never happens.

The alternative worth naming is the one that looks cheapest and is wrong.
Write-back at L1 with the eviction going straight to memory leaves L2 holding a
stale copy of a line L1 has already superseded, and the next L1 miss reads it.

Valid bits retire a bug the old model shipped. It keyed on the address and left
`-1` in the key to mean nothing-here, so the first two misses wrote their
evicted line back through `s->mem[-1]`, which given `int regs[32]; int mem[64];`
is register x31. It was invisible because every CBMC run passes
`--no-standard-checks`, which turns off exactly the array-bounds property that
would have caught it. A masked tag comparison cannot match an invalid entry, so
there is nothing to write back and nothing to get wrong.

Dirty bits retire a question rather than a bug. The old `runCache` carried a
`CR-soon` worrying that a speculative instruction which evicts an entry writes
back too early. A clean line writes nothing, so there is nothing to undo, and a
dirty line was dirtied by a committed store: `Isa.speculable` refuses a store
outright and `Forwarding` holds one in its queue until `close`. So a write-back
is always a write-back of committed data, and when it happens is not
architecturally observable. The cache's own state is another matter, and
deliberately so, since that is the channel.

## Reading around a store

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
[`bypass.s`](src/test/asm/riscv/bypass.s) is seven instructions of that.

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

[`bypass_ct.s`](src/test/asm/riscv/bypass_ct.s) is the control, and the two
differ in one operand: the last load's base register is `x6` rather than `x11`.
Everything about the queue still happens, the secret still comes back from a
load that read around a store, and the forward still fires. What does not happen
is the secret becoming an address, and no model reports anything. One leaking
program says the channel exists; this one says the channel is the address rather
than the queue.

### Where the store is reached from

[`bypass_late.s`](src/test/asm/riscv/bypass_late.s) is the same gadget behind a
bounds check that always passes, and it is the one that says where a store gets
noticed from. `Isa.speculable` refuses a store, so a store after a branch is the
instruction that *closes* the speculation window, and `Speculative` runs that
one through `step` rather than `call` because a window is inlined and `call`
would emit a function call. `step` skips `execute`. So a subclass hears about
every instruction except the one most likely to interest it, and a store in this
position queued nothing: this program was clean under `forwarding` and its
`speculative` twin to the byte. A guarded write is an ordinary shape, which made
that most of the column going missing without a failing test.

`Speculative.closing` is the hook, defaulting to `step` so nothing else moves,
and `Forwarding` overrides it to open a window when the closing instruction is a
store. What the override mostly does is hand over the saved registers.
`savedRegisters` still holds what the branch speculated, and the arm that
reaches the close is the one where the branch's guess held, so a store window
that inherited that list would restore a correctly speculated register on its
own squash.

[`dynstore.s`](src/test/asm/riscv/dynstore.s) is what pins that down, and it is
the other question a one-entry queue invites: a store through an index that
moves, in a loop. Its `bge` speculates two instructions before the store closes
the window, so the two lists are both non-empty and the residue shows them kept
apart:

```c
int v121 = v120[8];  v122[8] = v121;   // the branch window's, x8 and x5
int v125 = v124[5];  v126[5] = v125;
...
int v254 = v253[11]; v255[11] = v254;  // the store window's, x11 and x6
int v258 = v257[6];  v259[6] = v258;
struct StateT * v261 = slot_7(v41);    // then restarts just past the store
```

It also says the queue costs nothing structural. The window closes at the
backward jump, because no control flow is `speculable`, so the loop is still one
slot per pc and the residue does not grow with the trip count. A window that
inlined past that jump would not terminate.

### The forward that should not have happened

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
wrong one. [`bypass_alias.s`](src/test/asm/riscv/bypass_alias.s) is nine
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

### Most of the column is a copy

Only five programs in the tree put a store inside reach of a window. `2ctr`,
`spectre`, `reload`, `shortcircuit`, `constant_time`, `evict`, `hidden`,
`choose.o` and `folded.o` contain no store at all, and `guarded.o`'s is its last
instruction, so

`diff src/out/cbmc/riscv/{speculative,forwarding}/spectre.check.c`

is empty, and so are nineteen other pairs. Twenty of the thirty-two snapshots in
this column are their speculative twin to the byte, which is worth generating: a
model that only ever adds a channel has to leave a program with no store alone,
and the snapshots are the proof rather than the claim. The twelve that differ
are `salsa20`, `bypass`, `bypass_ct`, `bypass_late`, `dynstore` and
`bypass_alias`, once per backend.

## Running through a miss

```
	lw	x7, 0(x6)		# the probe. nothing below reads x7.
	addi	x8, x0, 0		# work that does not wait on any of it
	.rept	220
	addi	x8, x8, 1
	.endr
```

That is the bottom of [`hidden.s`](src/test/asm/riscv/hidden.s). The top is
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

### What the model is

[`NonBlocking.scala`](src/test/scala/elms/common/NonBlocking.scala) is sixty
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

### Two rows nobody wrote a demo for

`hidden.s` was written to go clean. `evict` and `spectre` were not.

`evict`'s gap is the eleven cycles between answering the probe out of L1 and out
of L2, and the load that carried the secret into a set is still outstanding when
that probe issues. The eleven land inside a hundred somebody is already paying
for, so they are not observable: 420 or 409 under `cache`, and 205 flat under
`nonblocking`.

`spectre`'s is the bigger one, and what it is about is the demo rather than the
cache. [`spectre.s`](src/test/asm/riscv/spectre.s) never asks the cache anything
after the squash. Its gap is the *speculated* load's own latency, 124 cycles
against 223 under `predictive` depending on whether the line the secret picked
was already resident, and a machine that does not stall on a load never charges
a squashed one to anybody. `predictive_nb` answers 23 whatever the secret is,
which is eight instructions and a fifteen-cycle mispredict penalty.

That is the model being right and the demo being incomplete. Spectre is a
Flush+Reload attack and `spectre.s` has no reload in it.

### The reload

[`reload.s`](src/test/asm/riscv/reload.s) is `spectre.s` with the probe put
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
| `speculative` | 225 or 324 |
| `predictive` | 226 or 325 |
| `predictive_nb` | 26 or 125 |

The last row is the point. The registers came back and the line did not, so a
model that throws away everything the window had in flight still reports
ninety-nine cycles, and they are the cache's rather than the stall's. `spectre`
and `reload` next to each other are what separate those two, and neither row
means much on its own.

The `j` is load-bearing, and it is about the model rather than about the
machine. `Predictive` resolves a window at the first instruction it cannot
speculate and has no join-point test of the kind `Speculative` carries, so a
window walks straight past the branch's own target and keeps going. Put the
probe directly at `done` and it runs inside the window, installs line 0
whatever the secret was, and the re-executed probe after the squash hits every
time. That was the first draft of this demo, and it read clean for a reason that
had nothing to do with the claim.

### What a squash does to what is in flight

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

### What it costs a checker, which the cache taught the hard way

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

## Checking with KLEE

`src/out/klee` is the same 129 residues checked by [KLEE](#KLEE) instead, and
[`src/out/klee/verify`](src/out/klee/verify) is its script:

`./src/out/klee/verify [--slow | --only-slow] [file.c ...]`

Both trees agree, 129 verdicts for 129, model sensitivity included. That
agreement is the point of having two: a residue really is an ordinary C program,
and nothing about the claim depends on which checker reads it.

Only the prelude differs between a pair of snapshots, so

`diff src/out/{cbmc,klee}/riscv/cache/2ctr.check.c`

changes thirteen lines, and so does every one of the other 128 pairs.
`Prover.intrinsics` is that block. The residue, `init` and `main` are one text
spelled in terms of `koika_assert`,
`koika_assume` and `koika_draw`, which each backend defines its own way and a
file compiled with neither `-DCBMC` nor `-DKLEE` stubs out so it can still be
run natively. Adding a third backend is adding a case to
[`Prover`](src/test/scala/elms/common/Prover.scala).

What does not carry over is how a verdict is read. CBMC exits 0 or 10; KLEE
exits 0 either way and writes `*.assert.err` into its output directory, so a
verdict there takes three conditions rather than one. Any error file is a leak.
No error file is only clean if the run also finished, which is
`completed paths > 0` with `partially completed paths == 0` and no
`halting execution` on stderr. Drop the last two and an exploration that ran out
of time reports exactly like a proof.

Six files in the tree are marked for that case, every one of them `branchy`
with a cache in front of the walk, and they say so where they call `check`:

```scala
check("cache/branchy", snippet, Verdict.Clean, klee = Reach.LikelyTimeout)
```

which writes `clean likely-timeout` onto the line. The verdict is still the
program's, and a run that finishes has to produce it; what `LikelyTimeout` adds
is that running out of budget is also a pass. Demanding the timeout would turn a
faster solver into a failing test, and demanding the verdict asks KLEE for
something it could not give when the label went on, so either outcome is
accepted and a wrong one still is not.

The name overstates it now, and the measurement is worth writing down rather
than leaving as a label nobody re-ran. At 120 seconds `cache/branchy` ends with
0 completed paths against 23 partially completed, and at ten minutes it ends the
same way, which is where the label came from. At the 1200 the budget has since
grown to, it finishes: 814 seconds, every path completed, clean. All six do. So
`LikelyTimeout` currently means expensive rather than unreachable, and it is
kept because fourteen minutes apiece is still not something a default run should
spend. What would retire it is a demo whose path space KLEE genuinely cannot
walk, and `branchy` at twelve probes was that demo before the cache made it too
slow for CBMC.

None of this is for want of a path space. `runCache` answers out of L1, out of
L2 or out of memory, so four probes are (3^4 + 1) / 2 paths and CBMC is done in
1.4s. What KLEE spends its fourteen minutes on is each individual path, and
`naive/branchy` walks the same four addresses with nothing in front of memory
and verifies in under a second, which is the control that makes this a statement
about the cache rather than about the walk.

The other half of that distinction is what `Reach.budgetSeconds` is for, and it
had to grow from 120 to 1200 with the cache. Five residues started reporting
`unknown` that had been settling in under a second, and none of them was this
case: `fact/speculative/guarded` finds its leak in 275s and
`riscv/forwarding/bypass` in 570s, so the old budget was turning "not yet" into
a failing test. A budget is a cap and not a cost, so the files that settled
quickly still do, and the only ones that spend most of one are the six above.

Each of those six costs about fourteen minutes, so a default run skips them and
says which it skipped:

```
skip     src/out/klee/riscv/cache/branchy.check.c (likely-timeout; pass --slow to run it)
all 123 agree (6 skipped)
```

`--slow` adds them back, and `--only-slow` runs nothing else, which is the one
to reach for after touching `Lockstep` or the cache model.

KLEE reads bitcode, and bitcode only loads into a KLEE built against the same
LLVM, so the script compiles and checks inside a pinned
`docker.io/klee/klee:3.1` under `podman` rather than pairing the host's `clang`
with whatever `klee` is nearby. `KOIKA_KLEE_NATIVE=1` uses a `klee` and `clang`
from `PATH` instead, and `KOIKA_KLEE_IMAGE` names a different image.

Which backend wins is predictable from the model rather than from the program,
and the two do not overlap much. A `naive` residue never branches on a load, so
KLEE walks one path and beats CBMC on a large one: `fact/naive/salsa20` is 0.68s
against 4.53s, because CBMC's cost is a formula over 277 instructions and 6536
generated properties while KLEE just runs it. Put a cache in front of a symbolic
load and it reverses, from 4x behind on a five-path space to 814s against 1.4s
on `riscv/cache/branchy`. Both backends finish every residue in the tree; six of
them need KLEE to be given twenty minutes.

## The FaCT suite

[FaCT](https://github.com/PLSysSec/FaCT) is a DSL whose type system rejects
programs that branch on a secret or index memory with one, whose Z3-backed
checker rejects programs it cannot prove stay in bounds, and whose compiler
emits a branchless selection in place of the branch you would have written.
[`src/test/fact`](src/test/fact) holds three programs it accepts, lowered into
four objects. Two of the programs come from FaCT's own repositories: the Salsa20
core from [fact-eval](https://github.com/PLSysSec/fact-eval), the case studies
published alongside the paper, and `example.fact`, which is what the compiler
ships to show what it does. The third is written here. Two of the four objects
verify clean under every model and two do not, and which is which is not a
property of FaCT's type system.

We do not build the FaCT frontend to run it. What is checked in is the LLVM that
`factc` emitted, and

`./src/test/fact/build`

lowers it to RV32I with stock `opt`, `llc` and `clang`.
`./src/test/fact/factc` regenerates the `.ll` from the `.fact` source beside it
and is the only thing here that wants the FaCT compiler; it builds it under
`podman` from the image its authors published, and no test run needs it.

### Salsa20

Salsa20 is the positive control, and what it controls for is size. It has no
conditional anywhere in it: every index is a literal and the only loop runs ten
times whatever the key is, so no model fails. Everything else in the tree that
verifies clean does so in under twenty instructions; this is 277, and CBMC
clears every model the FaCT suites cover:

| naive | cache | speculative | predictive | forwarding |
|---|---|---|---|---|
| 4.7s | 5.4s | 5.4s | 6.6s | 5.4s |

Two things it needs that the assembly demos do not. It is the first demo that
spills, so `init` points `sp` at the top of `mem` rather than leaving it at 0,
and `mem_size` is computed from the frame the object actually declares. And
Speculative wants a bigger stack than the JVM's default 1MB, so `build.sbt`
raises `-Xss` for the forked test JVM. It inlines a speculation window into the
function that opened it, salsa20's longest runs 1696 statements, and ELMS
elaborates a function body by recursing once per statement. Forwarding extends
Speculative and inherits that window, 1676 statements of it, so it wants the
same. Naive, cache and predictive emit nothing over 104 statements and stage
salsa20 on the default stack.

Thirty-eight of those 277 instructions are stores, which makes this the one file
in the tree that really exercises `forwarding`, and it is the reason that model
is a column rather than a rewrite: it stages, and it still verifies.

It is also the only case study the tower can take. curve25519-donna, poly1305,
both OpenSSL MEE versions and the Lucky13 fix in `openssl-ssl3/s3_cbc.fact` are
all multi-function, and `s3_cbc.fact` opens by declaring `extern void
SHA1_Transform`. One function per object is the whole budget, because a dynamic
jump cannot be staged against a static program counter.

### `guarded`

[`guarded.fact`](src/test/fact/guarded.fact) is a guarded table lookup that
FaCT typechecks, that FaCT's bounds checker proves memory-safe, and that hands
the key to any model with a branch predictor in it.

```
secret mut uint32 acc = key[0] ^ table[3];

if (idx < 16) {
  public uint32 t = table[idx];
  acc = acc + table[t & 15];
}

out[idx & 7] = acc;
```

| naive | cache | speculative | predictive | forwarding |
|---|---|---|---|---|
| clean | clean | leak | leak | leak |

Everything FaCT says about this is true. `idx` is public and so is `table`, the
one secret the function reads reaches `acc` and then `out` without ever becoming
an address or a condition, and `idx < 16` is what the bounds checker needs in
order to admit `table[idx]` against a table of sixteen. `factc` compiles it
without a word.

All of that is about the architectural execution. Call it with `idx` past 16 and
the guard is a branch the predictor gets wrong: `table[idx]` runs anyway, finds
a word of the key sitting past the end of the table, and the load after it turns
that word into an address. The rollback puts the registers back. The cache keeps
what it learned, which is what `koika_assert(s1->timer == s2->timer, ...)` reads
back out. No model spends more than 0.2s on it.

Neither half of that is news. FaCT never claimed a speculative semantics, and a
bounds check the predictor gets wrong is the original Spectre v1 gadget. What
the demo is for is that the two halves land in one place: the program carrying
FaCT's certificate and the residue carrying CBMC's counterexample are the same
program, so the distance between the two threat models is a diff rather than an
argument. `spectre.s` fills the same row of the table above with eight
instructions written to leak. This one fills it with a program a published
constant-time compiler signed off on.

What FaCT refuses is worth naming too, since it is what the demo had to be
shaped around. `if (idx < lim)` on a bound the caller passes is what the Spectre
paper's victim function says, and the bounds checker will not have it: `lim` is
arbitrary, `table[idx]` is not provable, and `factc` answers `value could be
#x0000000080000000`. A statically sized table is the only shape that gets
through. Two smaller details are the models' rather than FaCT's, and both are
commented where they sit in the source.

### `choose` and `folded`

[`choose.fact`](src/test/fact/choose.fact) is FaCT's own example program,
`example/example.fact` in its repository, unchanged:

```
secret mut uint32 output = a;
if (cond) {
  output = b;
}
return output;
```

`cond` is secret, which is the case FaCT exists for: the type system permits the
branch and the compiler takes it away, substituting
`output ^ (mask & (b ^ output))`. That is five RV32I instructions with no branch
among them. It is lowered twice.

| object | passes | naive | cache | speculative | predictive | forwarding |
|---|---|---|---|---|---|---|
| `choose.o` | `mem2reg` | clean | clean | clean | clean | clean |
| `folded.o` | `mem2reg,instcombine` | leak | leak | leak | leak | leak |

One `.fact` file, one `factc` invocation, one `.ll` checked in, one extra
optimizer pass, and two objects that disagree about whether the program is safe
to run. `instcombine` recognises the selection idiom and folds it back into an
LLVM `select`, RV32I has no conditional move, so `llc` lowers that `select` as a
branch, one arm carries a `mv` the other does not, and the instruction count
becomes a function of `cond`. `naive` catches it, which is to say no cache and
no speculation were needed. A timer that counts instructions is enough.

`mem2reg,instcombine` and `default<O2>` emit a byte-identical object here, so
the short pass list is not a cherry-picked one. It is written out because it
names the pass that does the folding.

The scope is narrower than "FaCT is broken" and worth stating exactly. FaCT's
default selection primitive is an x86 `cmovnz` written as inline assembly, which
`instcombine` cannot see into, and the arithmetic form above only appears
because `factc` runs with `-no-inline-asm`. That flag is the only way to compile
FaCT for a target that is not x86, since nothing portable keeps the cmov. So
this is a statement about FaCT away from x86, and it is why
[`build`](src/test/fact/build) stops at `mem2reg` for everything else in the
directory.

## CBMC

We use the C Bounded Model Checker (CBMC) as an off-the-shelf analyzer since our residue C programs are ordinary programs where timing is an ordinary first-order variable. Some pointers:

- [original CMBC website](https://www.cprover.org/cbmc/)
- [a maintained implementation](https://github.com/diffblue/cbmc) with [latest releases](https://github.com/diffblue/cbmc/releases)
- [original manual](http://www.cprover.org/cprover-manual/) also in [PDF](https://www.cprover.org/cbmc/doc/manual.pdf)

## KLEE

KLEE is a symbolic execution engine over LLVM bitcode, and the second
off-the-shelf analyzer the residues are checked with. It answers the same
questions CBMC does and charges for them differently, per path rather than per
formula, which is what makes having both worth the plumbing.

- [website](https://klee-se.org/)
- [the repository](https://github.com/klee/klee) and its [releases](https://github.com/klee/klee/releases)
- [the tutorials](https://klee-se.org/tutorials/), of which the first covers `klee_make_symbolic` and `klee_assume`
