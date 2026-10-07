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

`./src/test/fact/build` is the same story for the FaCT suites, and wants `opt`,
`llc` and a `clang` that can target RV32I. The FaCT compiler is not among them,
because what is checked in is the LLVM it emitted. Skip this and the five FaCT
suites fail twenty times over with a missing object.

Running `sbt testFull` from the root will run all the tests, generating
`.actual` files and checking them against the `.check` files under
[`src/out/cbmc`](src/out/cbmc), [`src/out/klee`](src/out/klee) and
[`src/out/eva`](src/out/eva), one tree per backend.
Failing tests will leave the generated `.actual` files for inspection.
Snapshot files mostly follow the naming convention of `[testfile]/[suffix].check.c`.

`testFull` and not `test`: under sbt 2 the latter is incremental, and a suite
whose sources have not changed does not run. That is usually what is wanted and
is exactly wrong when the thing being checked is a tree of snapshots, since a
model two traits up can change what a suite writes without that suite's own
file being touched.

The examples go through three checkers. [CBMC](#CBMC) and [KLEE](#KLEE) both
decide the timing claim outright and agree on every residue in the tree.
[Frama-C](#frama-c) answers a weaker question, whether the secret reaches the
timer at all, and pays for the speed by calling some clean programs leaky.
CBMC first.

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
of the generated C, which makes it part of the snapshot `sbt testFull` pins,
and [`verify`](src/out/cbmc/verify) reads it back out and runs the checker:

`./src/out/cbmc/verify [--certify] [--full] [file.c ...]`

With no arguments it takes the main suite, all 207 snapshots of it. Three trees
are held back, for three different reasons. `lockstep/` is five demos
`squared/` also answers, by the construction `squared/` replaced, and it is
held back because it agrees and costs time. `dynamic/` is held back because it
is not settled. It drops the control-flow assumption rather than making it,
which is an open question about the construction and not a second opinion on a
closed one. [`probe/`](#the-probe-count-dial) is held back on cost alone: it is
one demo at six sizes under both towers, and the sizes at the top are the whole
point. `sbt testFull` regenerates all three either way, so what `--full` buys
is the check rather than the C. Naming files runs exactly those, main suite or not.
It prints one line per file and exits non-zero if CBMC says anything other than
what the file claims, so a model that stops detecting what it used to detect is
a failing run rather than a stale comment. The claims themselves are greppable
without running anything:

`head -qn1 src/out/cbmc/**/*.check.c`

The tree under [`src/out/cbmc/squared`](src/out/cbmc/squared) is the same demos answered
a different way. A second tower, under
[`src/test/scala/elms/squared`](src/test/scala/elms/squared), interprets a
program over a pair of states rather than one, so a slot takes both, the two
runs share one copy of the control flow, and the timers are compared on the way
into every slot rather than once at the end. Every verdict there has to match
its twin next door, because the two are answering the same question about the
same program.

That is the squared semantics and nothing more. An expression is evaluated in
both states, and a branch stays a branch only where the two runs provably agree
about which way to go, which is asserted at the point it is needed rather than
left to the timer downstream. The rules underneath are written for a single run
over an abstract value domain, and the pair is what runs them twice.

Which is also why the same source can be *run*. Substitute ordinary `Int`s for
the staged values and the interpreter walks the program instead of writing one
down, and `SquaredRunSuite` does exactly that: every column of the table
below, on sampled inputs, in about twenty seconds with no checker anywhere. A
witnessed leak is a proof and a clean sample is not, which is what `src/out`
and CBMC are for, but a product semantics that only ever existed as C had to be
wrong in C before anyone found out.

What the sharing buys depends on who is holding the bill, and the bill changed
hands when the cache did. Sharing the control flow makes every timer comparison
an assumption as well as a question, so a pair that has already drifted leaves
the search instead of being enumerated and rejected. That is a claim about a
path space, and against the old two-entry cache it was worth five times:
`branchy` at eighteen probes was 30.1s as a product against 149.9s
self-composed.

A set-associative cache moved the cost somewhere the sharing does not reach.
What is expensive now is array theory over subscripts nobody knows, and running
two states doubles the updates in flight while pruning none of them. `branchy`
at the four probes it ships with is 1.43s squared against 1.31s self-composed.
Twice the work, no difference, and if anything the wrong way.

The probe count is a dial now rather than a line of assembly, which is what
[`probe/`](#the-probe-count-dial) is, and turning it says the same thing
louder. CBMC on the two constructions, one through six probes:

| probes | self-composed | squared |
|---|---|---|
| 1 | 0.20s | 0.21s |
| 2 | 0.31s | 0.34s |
| 3 | 0.57s | 0.61s |
| 4 | 1.50s | 1.39s |
| 5 | 5.79s | 7.11s |
| 6 | 17.25s | **25.80s** |

The gap grows with the space the sharing was supposed to prune. So under this
backend the construction does not merely fail to pay off, it loses ground
exactly where its argument was.

So it earns nothing in time here, and costs a little: see
[what each one charges](#three-ways-to-ask-and-what-each-one-charges) for the
per-file numbers. It is kept for the other thing it does. Every clock verdict in
that tree matches its twin next door, which is a second opinion on the same
program from a differently shaped formula, and where the declared verdicts
differ it is the control-flow obligation talking rather than the clock. Under a
symbolic executor the same dial goes the other way, and the section on it says
why that is not the sharing either.

[`src/out/cbmc/lockstep`](src/out/cbmc/lockstep) is a third answer to five of
them, and a historical one. `Lockstep` built the product by rewriting the
residue after staging, deciding which branches to fuse by whether they happened
to contain a slot call, and it is what the interpreter replaced. It stays
because a second construction of the same product is worth having on the day
they disagree, and it stays out of a default `verify` because they do not: the
same five verdicts, at 1.47s on the `branchy` measurement above, which is the
interpreter's number plus the noise.

`sbt testFull` still regenerates it, so the C never goes stale while nobody is
looking at it. What `--full` adds is a checker's opinion of it, which is the
part that costs something.

The two constructions decide what to assert differently, and that is the
argument for having kept both. `Lockstep` fused a branch when it happened to
contain a slot call, which is a syntactic proxy for "is this control flow".
The interpreter is told instead: `agree` is the rule's author saying the two
runs have to go the same way, and a branch written any other way is data each
run settles for itself. Under `Predictive` the model owns exactly one `agree`,
where a window resolves, which asks whether the two runs' branch came out the
same at the point the model asks it rather than leaving it to the clock
afterwards.

`squared/riscv/static` and `squared/riscv/predictive` are every demo the two
columns next door answer, fourteen each, so the two trees are the same
question asked two ways rather than a sample of it. Between them they show the
other half of what the table claims: the two predictors agree on every
verdict, and `constant_time` still stages into 1401 lines of residue under one
and 2462 under the other, because a branch that resolves taken leaves
`predictive` holding a history `static` never records.

`squared/riscv/forwarding` is thirteen more, everything the store-queue column
answers. It is the first model here that inlines, so it is the first thing to
use the seam the clock comparison rule exists for: while a store window is
open, `call` runs the next instruction where it stands and no slot begins, so
the two runs are not compared until the window closes. You can read that off
the residue. Counting writes to the clock in each emitted function of
`squared/riscv/forwarding/bypass` gives 1, 2, 1, 2, 1, 9, 1; the same count
under `predictive` gives 1, 2, 1, 2, 1, 2, 1. The nine is the window, five
instructions and their cache costs in the slot that opened it.

`nonblocking` and `predictive_nb` finish the set, twenty-eight more, and with
them every model in the table has a squared twin. They are what the
`defer`, `untimed`, `squash` and `finish` seams in `squared/Squared` were put
there for: each one had a comment saying what it would mean and no instance
behind it until a model arrived that lets a load land after the instruction
that issued it.

Widening the guessed set from three demos to thirteen is what found the only
bug the squared tower has had. `Squared.live` takes a slot number and `Exec.step` was
handing it a pc, which are the same number until `Predictive` numbers one pc
into several and then are not. Ten demos never noticed. `shortcircuit` asked
whether slot 14 existed when what it meant was whether the program had a
fourteenth instruction, and fell over rather than answering wrong, which is
the good version of that mistake.

`Squared.agree` compares the two runs' branch conditions and assumes them
equal, which is what makes this tower decide a stronger property than the
column next door decides, and the `balanced` row below is where the difference
shows. Call that the *static* squared construction, since which way a
conditional goes is settled while it stages. Everything above is one, and the
`static` in `squared/riscv/static` is a different word, a branch predictor
rather than a staging discipline.

`src/out/*/dynamic/riscv` is the dynamic construction, where a conditional is
settled by the runs instead. `DynamicSquared` overrides the one seam `agree`
leaves for it, and a conditional stops having one thing it can do:

```c
if (v_ca) {
  if (v_cb) { p = slot_6(p); }
  else      { p = slot_9(p);  p = slot_10(p); }
} else {
  if (v_cb) { p = slot_11(p); p = slot_12(p); }
  else      { p = slot_4(p); }
}
```

That is `dynamic/riscv/naive/balanced` at its `blt`. Four arms, no dispatch,
and no runtime test of which side anything is, because the pairing is still
erased at staging time. The two arms where the runs disagree walk each run's
tail on its own, and a solo slot reads one half of the pair and compares its
clock against itself:

```c
struct StateT2 * slot_9(struct StateT2 * v232) {
  struct StateT * v233 = v232->a;
  int v234 = v233->timer;
  bool v246 = v234 == v234;
  squared_assert(v246);
```

Nothing below `Squared` knows about any of that. `each` with one run live
evaluates its body once and pairs the result with itself, which is what makes
`v234 == v234` the whole of the clock comparison and leaves an `agree` on that
arm an ordinary conditional. No model underneath needed a line.

Both cells come back `clean`. That is the result the two files exist for. They
agree with `riscv/naive/balanced` and `riscv/cache/balanced`, where the static
squared cells next door read `leak`, so what `balanced` exposes really is the
control-flow obligation and nothing else, and the obligation can be given up.

What giving it up costs is the pruning. On a shared path `squared_assume` cuts
a pair that has already come apart, which is the only thing the squared
construction buys over running the residue twice and comparing at the end. On a
split path there is no pair left to cut and the solver walks both tails, which
is self-composition's path space arriving exactly where the program was already
going to be expensive. That, and the question being open rather than settled,
is why both `verify` scripts hold the subtree back from a default run.

Two models and one demo, so as not to overstate the shape of it. `Predictive`
can split with a window still open, and `Forwarding.close` requires the two
runs' queues to be the same shape, which after a split they are not. Both are
follow-on work, and behind `--full` there is no pressure to rush them.

Here is what they currently say. The first three demos exist for both NanoRisc
and RISC-V and answer the same on each, so the table does not split them;
NanoRisc has only the first three models, and RISC-V is what fills the rest.
The blanks are suites nobody has written: `cmp` under cache, `cmp` and
`branchy` under forwarding, and the FaCT and NanoRisc programs under the last
two columns, which are RISC-V only so far.

| demo | naive | cache | static | predictive | forwarding | nonblocking | predictive_nb |
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
| `balanced` | clean | clean | leak | leak | leak | clean | leak |

`evict` is the row the geometry was for, and it is a stronger statement than
`2ctr` next to it. `2ctr` needs a cache of some kind. `evict` needs a cache with
*sets* in it: the secret picks which set gets a line installed, so the channel
is a conflict rather than an address. The program has no branch in it and reads
around no store, which is why `static`, `predictive` and `forwarding` are
copies of the `cache` answer. The last two columns are not, and the section on
running through a miss is about why.

That a cache without sets answers clean here is a claim about what a model
cannot see, so it is a test rather than a sentence.
[`RiscVFlatTests`](src/test/scala/elms/riscv/flat.scala) is the same `Cached`
at one set of two ways over one-word lines, which is the shape this tower
carried before, and `src/out/*/riscv/flat` is two files: `evict` clean, and
`2ctr` still leaking so that the control is not merely a model too weak to
report anything.

Reading across the first five columns is the tower. No model there loses a leak
the one to its left could see, and `2ctr` and `spectre` are where it starts
seeing more: `2ctr` needs a cache before the second load's address can cost
anything, and `spectre` needs speculation before that load happens at all.
`guarded` is `spectre`'s row written again and `folded` is `shortcircuit`'s, and
the FaCT section below is why either was worth a demo of its own.

`static` is the one place in that chain where inheritance runs against
capability. It is `Predictive` with the history taken away, overriding `learn`
to record nothing, so every branch gets the cold-start guess of not-taken and
goes on getting it. That is what a machine with no history bits does, and it is
why the column is worth keeping next to `predictive`: a leak in it did not need
a predictor to be trained, which is a claim about the threat model rather than
about the predictor. No demo tells the two apart by verdict. Eight of them do
stage differently, `shortcircuit`, `constant_time`, `reload`, `dynstore`, `cmp`,
`folded`, `guarded` and `salsa20`, because a branch that resolves taken leaves
`predictive` holding a history `static` never records, and the two then number
the instructions after it into different slots.

`balanced` is a row about the predictor and nothing else. A secret word decides
a branch whose two arms are the same length, so a machine that does not
speculate runs two instructions either way and the clocks come back together.
Three columns report that. The four with a predictor in them do not: the branch
is cold in both runs, so both guess not-taken, and only the run that takes it
pays the fifteen. A balanced branch is a constant-time idiom for exactly as
long as nobody is predicting it.

It is in the tree for a second reason, which is what it does to the squared
tower. `Squared.agree` asserts that the two runs take each conditional the same
way, so a squared twin of the three clean cells above cannot come back clean
whatever the arms cost. That twin is written now, and CBMC on one demo out of
each tower says it directly:

```
# src/out/cbmc/riscv/naive/balanced.check.c
[main.assertion.1] line 181 timing leak: SUCCESS

# src/out/cbmc/squared/riscv/naive/balanced.check.c
[main.assertion.1]             line 328 timing leak:           SUCCESS
[squared_assert.assertion.1]   line 308 timer drift:           SUCCESS
[squared_diverged.assertion.1] line 309 control flow diverged: FAILURE
```

Different declared verdicts, `clean` next door and `leak` here, and the
assertion that fails is never the clock. `timer drift` succeeds in all seven
squared columns, the four with a predictor included. Under `static` that is
the sharp version. The self-composed leak there is a real pair of clocks, 106
cycles against 122, and every pair that reaches those two numbers is one that
took the branch two ways, so `squared_assume` has cut it before anything looks
at a timer.

Neither answer is a bug and neither is the other one's approximation.
Self-composition decides whether the two clocks can differ. The squared tower
decides that and whether the control flow can, which together are the classical
constant-time discipline, and this is the first program here that separates the
two. `squared/riscv/naive` is the one squared column holding a single demo,
because one demo is all it takes to say this and `Flat` is the model with the
least left in it to blame. `dynamic/riscv/naive/balanced` is that same demo a
third time, with the control-flow obligation dropped, and it reads `clean`
again.

That sentence stops at the fifth column, and the two after it are each a
different reason why.

`nonblocking` is the one that breaks the shape. It takes rows away. `evict`,
`hidden` and `spectre` all read leak under `cache` or under `static` and clean
under a model that does not stop the world for a miss, and in every one of them
the column to the left is what is wrong: the gap it reports is a stall the
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
`static`, `predictive` and `forwarding` in a chain on top of it, with
`nonblocking` a second branch off cache and `predictive_nb` the join. Only the
first five columns are also ordered by what they report.

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
to 9.0s, a residue 2.4x wider and a solver doing the work it always did.

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

[`dynstore.s`](src/test/asm/riscv/dynstore.s) is what pins that down, and it is
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

`diff src/out/cbmc/riscv/{predictive,forwarding}/spectre.check.c`

is empty, and so are nineteen other pairs. Twenty of the thirty-two snapshots in
this column are their predictive twin to the byte, which is worth generating: a
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

`src/out/klee` is the same 207 residues checked by [KLEE](#KLEE) instead, and
[`src/out/klee/verify`](src/out/klee/verify) is its script:

`./src/out/klee/verify [--slow | --only-slow] [--full] [file.c ...]`

`--full` means what it means next door: the five under `lockstep/` are held
back from a default run, because a KLEE budget is the last thing to spend
confirming that two constructions of one product still agree.

Both trees agree, 207 verdicts for 207, model sensitivity included. That
agreement is the point of having two: a residue really is an ordinary C program,
and nothing about the claim depends on which checker reads it.

Only the prelude differs between a pair of snapshots, so

`diff src/out/{cbmc,klee}/riscv/cache/2ctr.check.c`

changes thirteen lines, and so does every one of the other 213 pairs.
`Prover.intrinsics` is that block. The residue, `init` and `main` are one text
spelled in terms of `koika_assert`, `koika_assume`, `koika_draw` and
`koika_secret`, which each backend defines its own way and a file compiled with
none of `-DCBMC`, `-DKLEE` or `-DEVA` stubs out so it can still be run
natively. Adding a third backend was adding a case to
[`Prover`](src/test/scala/elms/common/Prover.scala), which is
[Frama-C](#frama-c) below.

What does not carry over is how a verdict is read. CBMC exits 0 or 10; KLEE
exits 0 either way and writes `*.assert.err` into its output directory, so a
verdict there takes three conditions rather than one. Any error file is a leak.
No error file is only clean if the run also finished, which is
`completed paths > 0` with `partially completed paths == 0` and no
`halting execution` on stderr. Drop the last two and an exploration that ran out
of time reports exactly like a proof.

Twenty files in the tree are marked for that case, fourteen in the main suite
and six more under `probe/`, and they say so where they call `check`:

```scala
check("cache/branchy", snippet, Verdict.Clean, klee = Reach.LikelyTimeout)
```

which writes `clean likely-timeout` onto the line. The verdict is still the
program's, and a run that finishes has to produce it; what `LikelyTimeout` adds
is that running out of budget is also a pass. Demanding the timeout would turn a
faster solver into a failing test, and demanding the verdict asks KLEE for
something it could not give when the label went on, so either outcome is
accepted and a wrong one still is not.

The label means two different things now, and which one a file gets is
measured rather than assumed.

Eleven of the fourteen are `branchy` with a cache in front of the walk, one per
model that has one and one per squared twin, and every one of them finishes
inside the budget. At 120 seconds `cache/branchy` ends with 0 completed paths
against 23 partially completed, and at ten minutes it ends the same way, which
is where the label came from. At the 1200 the budget has since grown to it
takes 814 seconds, every path completed, clean; the two the squared tower added
last take 958 and 970. So for those eleven `LikelyTimeout` means expensive
rather than unreachable, and it is kept because a quarter of an hour apiece is
not something a default run should spend.

The other three do not finish, and they are the squared tower's:
`squared/riscv/forwarding/bypass_alias`, the same under `bypass_late`, and
`squared/riscv/predictive_nb/reload`. Each was given 1500 seconds of wall clock
and produced no verdict, against 453 for the slowest squared residue that does.
`--max-time` stops KLEE forking new states and does not interrupt a query
already in flight, so the budget is a search bound and not a wall clock, and a
file like this hangs a default run rather than failing it. All three are where
the squared model carries the most: the two `bypass` rows are the store queue's
deferred alias check over addresses nobody knows, doubled, and
`predictive_nb/reload` is the join, where a squash rewrites every register's
arrival time in both runs and the probe still asks the cache afterwards.

None of this is for want of a path space. `runCache` answers out of L1, out of
L2 or out of memory, so four probes are (3^4 + 1) / 2 paths and CBMC is done in
1.4s. What KLEE spends its fourteen minutes on is each individual path, and
`naive/branchy` walks the same four addresses with nothing in front of memory
and verifies in under a second, which is the control that makes this a statement
about the cache rather than about the walk.

The other half of that distinction is what `Reach.budgetSeconds` is for, and it
had to grow from 120 to 1200 with the cache. Five residues started reporting
`unknown` that had been settling in under a second, and none of them was this
case: `fact/static/guarded` finds its leak in 326s and
`riscv/forwarding/bypass` in 485s, so the old budget was turning "not yet" into
a failing test. A budget is a cap and not a cost, so the files that settled
quickly still do, and the only ones that spend most of one are the fourteen
above.

Each of those costs a full budget or more, so a default run skips them and says
which it skipped:

```
skip     19 under lockstep/, dynamic/ and probe/ (pass --full to check them)
skip     src/out/klee/riscv/cache/branchy.check.c (likely-timeout; pass --slow to run it)
all 194 agree (13 skipped, 19 held back for --full)
```

Those counts are the tree's arithmetic and not a transcript. 207 snapshots in
the main suite, thirteen of them labelled. Every one of the 194 has been
checked on its own, and the three that hang were found by checking them on
their own; what nobody has sat through is all 194 in a single run.

`--slow` adds them back, and `--only-slow` runs nothing else, which is the one
to reach for after touching the squared tower or the cache model.

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
on `riscv/cache/branchy`. Both backends finish every residue in the main suite;
six of them need KLEE to be given twenty minutes. Outside it, the top two
settings of the [probe-count dial](#the-probe-count-dial) are the first files
here CBMC answers and KLEE does not, which is the same cliff with the dial
turned far enough to fall off it.

## The probe-count dial

`riscv/cache/branchy` is the one demo here whose bill is a path space rather
than a formula, and for most of this tree's life its four probes were written
out in an `.irp` in the assembly. So every claim about how a checker scales was
a claim about two points somebody had measured months apart.
[`probe.s`](src/test/asm/riscv/probe.s) is that demo with the count as a
`--defsym`, one source assembled into `probe1.o` through `probe6.o`, and
[`probe.scala`](src/test/scala/elms/riscv/probe.scala) stages each of them
under both towers. Twelve snapshots per backend under `src/out/*/probe`, held
back from a default `verify` because the settings at the top of the dial are
the entire point of having one.

[`doc/squared-vs-self-composition.md`](doc/squared-vs-self-composition.md) is
the measurement record behind this section: the method, the counters, the
control experiment and what each number was taken under. What follows is the
conclusions.

Every cell is clean, and that is the arrangement rather than a result. A
program with nothing to report is a program whose checker has to clear the
whole space instead of stopping at the first witness, which is what makes the
pair a measurement of cost. `probe/self/k4` stages into the same 1130 lines as
`riscv/cache/branchy` and `probe/squared/k4` into the same 2281, which is the
control saying the dial reproduces the demo it generalises.

KLEE, 1200s budget:

| probes | self-composed | squared | squared/self | completed paths |
|---|---|---|---|---|
| 1 | 3.9s | 3.8s | 0.97 | 2 and 2 |
| 2 | 27.5s | 27.0s | 0.98 | 4 and 4 |
| 3 | 156.2s | 130.9s | 0.84 | 9 and 9 |
| 4 | 928.6s | **605.7s** | **0.65** | 23 and 23 |
| 5 | n/a | n/a | | neither finishes |
| 6 | n/a | n/a | | neither finishes |

One through three were taken on an idle box and four with one other job on the
machine, so read 0.65 as the shape rather than as three digits.

That is the squared tower winning, on the one demo it was supposed to win on,
with the margin growing in the size of the space. And the fourth column says it
is not winning for the advertised reason. The completed path counts are equal
at every setting. Nothing is being pruned.

### What is actually cheaper

Self-composition's `main` calls the residue twice:

```c
struct StateT *s1_ = snippet(&s1);
struct StateT *s2_ = snippet(&s2);
```

The squared one calls it once, carrying both states:

```c
struct StateT2 p = { .a = &s1, .b = &s2 };
struct StateT2 *p_ = snippet(&p);
```

Same paths, shorter path. At four probes that is 72,215 instructions against
146,180 and 1283 solver queries against 2003, which is the 0.65 and all of it.
The sharing has nothing to do with it, and neither does the residue being twice
as wide, because the work along a path is the same either way and the number of
paths it is spent on is halved.

### Why the assumptions cannot help a symbolic executor

Every squared slot emits this pair:

```c
squared_assert(v1316);
squared_assume(v1316);
```

KLEE's `klee_assert(e)` expands to `e ? (void)0 : __assert_fail(...)`. KLEE
forks on `e`, terminates the false branch with an `assert.err`, and the state
that survives already carries `e` in its path condition. The `klee_assume` on
the next line constrains something that is already there. Same for the
`squared_diverged` pair a few lines down.

So the pruning that makes `__CPROVER_assume` worth emitting, where the assertion
adds no constraint and the assumption does, is under KLEE subsumed by the
assertion sitting immediately above it. The paths it would cut are exactly the
ones KLEE has already terminated as counterexamples: on a clean program there
are none, and on a leaky one the search stops at the first.

That is an argument rather than a measurement, so here is the measurement.
Rewriting `squared_assume` to a no-op in five squared residues, two runs each:

| residue | assume on | assume off | completed paths |
|---|---|---|---|
| `squared/cache/constant_time` | 0.9s, 0.8s | 0.8s, 0.8s | 4 and 4 |
| `squared/static/bypass_ct` | 15.9s, 15.7s | 15.2s, 15.0s | 1 and 1 |
| `squared/predictive_nb/evict` | 14.7s, 14.3s | 13.5s, 13.0s | 4 and 4 |
| `squared/static/bypass` | 35.2s, 34.9s | 26.7s, 26.0s | 1 and 1 |
| `probe/squared/k3` | 151.5s, 147.4s | 199.7s, 191.4s | 9 and 9 |

Identical path counts in all five. The times move a quarter in both directions,
which is the constraint making individual queries easier or harder rather than
fewer of them.

### What it costs everywhere else

All 76 pairs that exist in both towers, 60 seconds apiece. Of the 61 where both
settled, 52 have identical completed path counts; the nine that differ are
`balanced`, where the squared column is answering its second question, and
leaks, where the search stops at whichever witness the randomised searcher
reaches first. Among the pairs costing more than five seconds:

| | pairs | median squared/self |
|---|---|---|
| clean, so a proof | 16 | 1.55, range 0.94 to 1.66 |
| leak, so a witness | 14 | 0.94, range 0.78 to 1.12 |

The 6% on leaks is the squared tower asserting at the slot where the drift
starts rather than after both runs have finished. The 1.55 is the bill for a
residue twice as wide on a path space the sharing did not shrink.

`hidden` is the worst of it, and it is the most informative file in the
comparison. On an idle box at a 900s budget it is 54 to 57 seconds
self-composed against 214 to 229 squared, about four times, the same under
`static`, `predictive` and `forwarding`. That residue holds 227
`squared_assert` calls, and the query count goes from 279 to 898. CBMC folds
227 assertions into one formula and charges once. KLEE pays a solver query per
fork point. Comparing the clocks at every slot is cheap for a bounded model
checker and expensive for a symbolic executor, and the tree had no way to see
that until the two backends were run on the same pairs.

### What this leaves open

The single pass and the per-slot comparison are separable, and the measurements
point opposite ways: the pass is worth a third of the time at four probes, the
comparisons cost four times on `hidden`. A construction that interleaves the two
runs without comparing clocks at every slot would take the first without paying
the second. It would also stop deciding the stronger property, which is the
whole reason the comparisons are there, so this is a question about what the
tower is for rather than a missing optimisation. Nobody has built it.

Sharper, and untested: `squared_assert` demands the clocks agree at *every*
slot, which is strictly stronger than agreeing at the end. A program whose
clocks drift and reconverge is clean to self-composition and a leak to the
squared tower. No demo in this tree has that shape, so the two towers agreeing
on sixty-nine verdicts is weaker evidence than it looks.

## Checking with Frama-C

`src/out/eva` is the same 207 residues read by a taint analysis rather than by a
model checker, and [`src/out/eva/verify`](src/out/eva/verify) is its script:

`./src/out/eva/verify [--full] [file.c ...]`

The whole tree, held-back subtrees included, comes out in under three minutes:

```
all 226 agree
```

`fact/naive/salsa20` is the slowest file in it at 11 seconds and a typical
residue answers in about one.

A default run leaves out the same three trees the other two scripts leave out,
and `--full` adds them back. The reasons for leaving them out are theirs rather
than Eva's, which is cheap on all three. What the holdback buys here is that a default run
of all three scripts covers the same 207 files, so a three-way disagreement is
about the backends rather than about which tree somebody remembered to check.

The question is weaker on purpose. CBMC and KLEE both read the self-composed
program and decide whether the two timers can actually differ. Eva asks only
whether the secret reaches the timer at all, so it is a may-analysis, and it
calls a program leaky that the other two prove clean. What that buys is not
speed, which the numbers below say plainly. It is a checker whose
incompleteness is visible in the verdict. An over-approximation prints `leak` on
a clean program and anybody can see it, where an exhausted budget prints nothing
and reads like a proof.

`frama-c -cpp-extra-args=-DEVA -eva -eva-domains taint -eva-unroll-recursive-calls <N> <file.c>`

ACSL is a C comment, which was the problem and is now the whole trick. No macro
expands to `//@ assert`, so the obligation cannot be written where the other two
backends write theirs. It does not have to be. ELMS writes comments into
generated code, so the annotation goes into `main` beside the comparison it is
about:

```c
//@ assert untainted_timer: !\tainted(s1_->timer==s2_->timer);
koika_assert(s1_->timer==s2_->timer, "timing leak");
```

Both lines are the same text in all three trees. CBMC and KLEE preprocess the
first away and check the second; Eva does the reverse, since `koika_assert` is
nothing under `-DEVA`. The source end stays a contract, with `koika_secret`
calling a stub whose `taints *p` clause marks the draw, because `taints` is a
clause about a function and nothing generated writes one.

One obligation per residue, and not one per slot even under the squared and
lockstep towers, which compare the clocks on the way into every slot. Those
comparisons prune the search and name the slot a drift began in, and both are
worth paying for to a checker deciding whether the timers can actually differ.
Taint asks whether the secret arrives at all, and the end of the run answers
that as well as the middle does. The towers are there to be more precise than
this backend rather than to be read by it.

`koika_assume(b)` becomes `if (!(b)) Frama_C_abort();`. Eva drops the states
that reach the abort, which is exactly what an assumption does, so
`bounded(0, 20)` gives Eva `[0..20]` and the shared body needs no per-backend
arm. The abort branch is bottom rather than joined, which also means an
assumption on a tainted condition does not taint everything after it.

An explicit-flow tracker would not do, because cache timing leaks two ways at
once. The hit and miss latencies are branchless arithmetic over the tag
comparisons, so the timer picks the secret up by data flow. But `cache_age` is
written inside an `if` and subscripted by the address, and it decides the next
eviction, which is the whole of what `evict` reports. Eva's taint domain crosses
both edges, and the negative control is what says so rather than the
documentation:

```c
int s = Frama_C_interval(0, 20);
koika_mark(&s);          // drop this line and both come out untainted
int implicit = 0;
if (s > 10) implicit = 1;
//@ assert !\tainted(implicit);   // unknown: control dependence
//@ assert !\tainted(arr[s]);     // unknown: through the index
```

### Telling the secret draw apart from the public one

Self-composition encodes the public/secret split structurally, by drawing the
secret twice and copying the public input into both states, and nothing in the
generated C ever said which was which because nothing needed to know. Taint
does, so `bounded` gained a companion:

```c
int secret(int low, int high) {
  int x = bounded(low, high);
  koika_secret(x);
  return x;
}
```

Both are shared text and `koika_secret` is nothing under CBMC and KLEE, so the
three functions that emit a secret draw say `secret(` where they said
`bounded(` and no verdict next door moves. Every residue in the tree has at
least one, which is the invariant the unsound direction would hide behind: a
demo with no secret draw would have Eva prove it clean because nothing was ever
tainted, which is a true statement about a program nobody wrote.

### Reading a verdict, which is where this gets sharp

Eva exits 0 whether or not the assertion holds, so the verdict comes out of
`-report`, which prints one row for the one property this backend cares about:

```
clean       [  Valid  ] Assertion 'untainted_timer' ("subject.c", line 502)
leak        [    -    ] Assertion 'untainted_timer' ("subject.c", line 251)
unknown     no row at all
```

The absent row is the half worth having. Some demos stage a loop into a cycle of
slots; Eva declines to unroll one past its bound, the imprecision widens an index
to top, and the out-of-bounds access that follows is proved invalid and reduces
the state to bottom. The sink is then never evaluated, Eva never complains about
the assertion, and a reader that takes no complaint for a proof reports one it
never had. An early sweep here did exactly that and had to be thrown out.

A row says Eva reached the obligation and decided it. No row says it did not get
there, which is the question, and it is a better question than the one this used
to ask. The reader before it checked whether `main` reached its last statement,
which is a proxy: `main` can terminate on a state too imprecise to prove
anything, and under `-eva-no-results` it does not print an end state at all.

Which is the same shape as KLEE's exit 0 on a run that stopped early. `unknown`
is the third outcome and never counts as agreement. Nothing in the tree produces
one at the bound it runs at, and the case is in the script because the day
something does it has to fail rather than pass.

None of this is the exit code, which is 0 with an unproven assertion and 1 when
a state went to bottom, so it answers neither question. `-report-exit-code`
would make it mean something and is deliberately not passed.

Naming the assertion is what makes the table readable at all. An earlier version
of this backend put the obligation on a precondition of an uninterpreted stub,
and there the table printed a row only when Eva had a complaint, so a proof and
a run that never got there were both an absence.

### The bound

`<N>` is the same `[unwind N]` CBMC gets, spent on recursive calls instead of
loops, and not giving Eva one produced every vacuous answer above. Thirty-one of
the 214 residues need it to answer what the tree claims, and they are three
demos, `constant_time` at fourteen models, `dynstore` at twelve and `salsa20` at
five. Each stages a loop into a cycle of slots deeper than Eva will follow.

At the default bound those thirty-one fail two different ways and only one of
them is honest. Eight never reach the obligation at all, so `-report` prints no
row and the answer is `unknown`; every one of those is a model whose memory
system does not stall. The other twenty-three reach it in a state too imprecise
to prove anything and report `leak` on a program the tree calls clean. Both are
mismatches and `verify` fails either way, so a short bound gets past nothing.
What the second kind costs is the diagnostic: `unknown` says the bound is short,
`leak` says the secret reached the timer, and only one of those points at the
fix. Under the stub encoding this replaced, all thirty-one came out the first
way.

| file | default | `-eva-unroll-recursive-calls 65` |
|---|---|---|
| `riscv/cache/spectre` | clean, 0.4s | clean, 0.4s |
| `riscv/cache/constant_time` | leak, 0.4s | clean, 0.4s |
| `riscv/cache/dynstore` | leak, 0.4s | clean, 0.5s |
| `lockstep/riscv/cache/constant_time` | leak, 0.4s | clean, 0.5s |
| `fact/naive/salsa20` | leak, 0.8s | clean, 7.2s |

Free where there is no recursion and the whole answer where there is.
`salsa20` is the one file that pays, and it pays the same at any bound that
covers it, 7.2s at 16 and 7.2s at 64 against the 7.3s above. So what that row
buys is following the recursion at all rather than being told how deep.

The termination check is the cheap half of catching a short bound. `main`
reaching its last statement says the sink was evaluated, not that the state it
was evaluated in was precise, so the equivalent of `verify --certify` here would
compare a run at `N` against one at `2N` and fail on any verdict that moves.
That is not built.

### What it costs, which is one flag

CBMC answers its 207 residues in 247 seconds. Eva answers all 226, the three
held-back trees included, in 174.

It did not start there. The first working version of this backend took 1543
seconds over 207 files, six times CBMC's cost for a weaker question, and the
whole difference is `-eva-no-results`. Eva keeps a state per statement by
default, which is where the time went and which nothing here reads. The saving
scales with the size of the residue, so the files that dominated the bill are
the ones that moved:

| file | states kept | `-eva-no-results` | |
|---|---|---|---|
| `fact/naive/salsa20` | 137.5s | 11.3s | 12.2x |
| `riscv/compiled/static` | 55.2s | 9.0s | 6.1x |
| `squared/riscv/forwarding/hidden` | 11.6s | 3.3s | 3.5x |
| `riscv/cache/branchy` | 1.7s | 1.2s | 1.4x |
| `fact/naive/guarded` | 0.7s | 0.7s | 1.0x |

The five `salsa20` residues were 1170 seconds of that 1543, three quarters of
the bill on five files out of 214. They are under a minute of the 174 now.

What the flag takes away is the per-statement states, and the only thing here
that read them was the termination check. `-report` does that job better, which
is the verdict section above.

The taint domain is nearly free on top, 137.5s against 120.2s with it switched
off, about fourteen per cent. Switching it off also makes every residue report
`leak`, since `\tainted` stops being provable, so that doubles as the negative
control for the whole arrangement.

Against KLEE the margin is the one the model predicts rather than anything a
flag bought:

| file | CBMC | KLEE | Eva |
|---|---|---|---|
| `riscv/cache/branchy` | 1.8s | 814s | 1.2s |
| `riscv/cache/2ctr` | 0.5s | 36s | 0.7s |
| `fact/naive/salsa20` | 7.0s | 0.7s | 11.3s |

A set-indexed cache in front of the load costs KLEE every path and costs an
abstract interpreter nothing. `salsa20` reverses it, because 277 instructions of
straight-line code is what a symbolic executor just runs. CBMC is cheap on both
and Eva is now within a factor of two of it on both, which leaves KLEE as the
only one of the three with a cliff in it.

### Three ways to ask, and what each one charges

Sixty-nine demos exist in both the self-composed tree and the squared one, so
all three backends can be put on the same programs. The largest of them, on an
otherwise idle machine:

| demo | CBMC self-composed | CBMC squared | Eva |
|---|---|---|---|
| `predictive_nb/hidden` | 1.54s | 2.07s | 0.97s |
| `nonblocking/hidden` | 1.54s | 2.10s | 0.97s |
| `static/hidden` | 1.15s | 1.95s | 0.81s |
| `forwarding/hidden` | 1.18s | 1.97s | 0.80s |
| `predictive_nb/branchy` | 1.68s | 1.65s | 0.54s |
| `static/branchy` | 1.32s | 1.31s | 0.49s |

The squared column is the expensive one, which is worth saying because the
construction was built to be the cheap one. Over all sixty-nine pairs its
residue is 2.04x the lines, and everywhere except `branchy` that width costs
more than the sharing saves. `branchy` is where it breaks even, and `branchy`
is the one demo whose bill is a path space rather than a formula.

"Saves" and not "prunes", which is the one word this table used to get wrong.
The [probe-count dial](#the-probe-count-dial) turns `branchy` into six sizes
and runs both towers over all of them, and the completed path counts come back
equal at every size. Whatever the squared column is buying on this row, it is
not a smaller search. The dial also says which way the row tips once the space
is bigger than four probes, and under CBMC it tips against the squared tower:
17.25s self-composed against 25.80s squared at six.

Cost tracks how much is being asked, and the three ask different amounts. The
squared tower decides whether the clocks can differ and whether the control flow
can, which is two obligations. Self-composition decides the first alone. Eva
decides neither, and asks instead whether the secret reaches the timer at all,
which over-approximates both. So the order is squared, self-composed, Eva,
descending on what is asked and descending on what it costs, and the two
orderings agree.

What that costs in answers is not symmetric. The first two give the same verdict
about the clock on all sixty-nine, and the places they differ are the places the
squared tower is answering its second question rather than disagreeing about the
first. Eva differs from self-composition on thirteen of the sixty-nine, and on
thirty-three of the full 214, always a clean program widened to `leak` and never
the other way.

### What it agrees on

181 of the 214 residues come out matching `Verdict`, and all 33 that do not are
a `clean` widened to a `leak`. None goes the other way, which is the direction
that would matter. Nothing in the tree answers `unknown` and nothing errors.

Six demos account for the 33. `bypass` and `bypass_late` are nine each, one per
model with a cache in front of the load that also commits its store the instant
it runs. The load takes a secret address and then costs the same either way, so
the dependence is real and the difference is not. Under `forwarding`, which
queues the store, both are genuine leaks and Eva agrees with the other two.

`balanced` is five and is the clearest of them, since both arms of the branch
cost exactly the same. `evict` is five, four where the memory system does not
stall and one where the cache has a single set and so cannot have a conflict at
all, and `hidden` is four, the same non-stalling models. In all of those the
secret reaches `cache_age` through the `if` that writes it, and nothing Eva
tracks says the eviction it decides costs nothing here. The last of the 33 is
`fact/cache/guarded`.

Each says so where it calls `check`:

```scala
check("balanced", snippet, Verdict.Clean, eva = Taint.Widens)
```

which writes `leak widened` onto the line, so that a three-way diff shows a
declared disagreement rather than a surprise:

```
src/out/cbmc/riscv/cache/balanced.check.c:// verify: clean (CBMC should report VERIFICATION SUCCESSFUL) [unwind 65]
src/out/klee/riscv/cache/balanced.check.c:// verify: clean (KLEE should report no failing assertion) [budget 1200s]
src/out/eva/riscv/cache/balanced.check.c:// verify: leak widened (the program is clean; Eva cannot prove it) [unroll 65]
```

`Taint` has two cases rather than three, and `Widens` is one of them so that the
unsound direction, a leak narrowed to clean, cannot be written down at all.
Every divergence measured goes the one way.

What the backend gives up is granularity, and it gives it up on purpose. A
squared residue asserts once per slot rather than once at the end, 228
`squared_assert` calls in `squared/riscv/forwarding/hidden`, and CBMC reports
which of them fired and whether it was `squared_assert`'s "timer drift" or
`squared_diverged`'s "control flow diverged". Eva is told none of that. It gets
the one assertion in `main` and names the file.

Writing an `//@ assert` at each of those sites would get the slot back, and it
is not worth what it costs. The residue is staged once and all three trees read
the same text, so every annotation lands in all of them; two hundred of them per
file would be paid for in three trees to tell one backend something a timer the
secret reaches at slot nine already tells it at the end. The per-slot
comparisons are there to prune a search and to make a counterexample readable,
and this backend does neither.

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

| naive | cache | static | predictive | forwarding |
|---|---|---|---|---|
| 5.7s | 9.0s | 10.7s | 11.1s | 11.3s |

Two things it needs that the assembly demos do not. It is the first demo that
spills, so `init` points `sp` at the top of `mem` rather than leaving it at 0,
and `mem_size` is computed from the frame the object actually declares. And
`build.sbt` raises `-Xss` for the forked test JVM, because ELMS elaborates a
function body by recursing once per statement and `forwarding` inlines a store
window into the function that opened it. Thirty-eight stores make salsa20's
longest slot 986 statements of that, against 260 for every model that inlines
nothing. It fits the default 1MB stack now, where the 1696-statement branch
window this model used to inherit did not, so the flag is margin rather than a
requirement. Kept as margin: the number is a property of one demo, and the next
demo is free to be longer.

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

| naive | cache | static | predictive | forwarding |
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

| object | passes | naive | cache | static | predictive | forwarding |
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

## Frama-C

Frama-C's Eva plugin is an abstract interpreter, and its taint domain is the
third off-the-shelf analyzer the residues are checked with. It is the one of
the three that does not decide the timing claim. It tracks where the secret
reaches and reports every timer it cannot rule out, which is a weaker question
and, on this tree, not a cheaper one. 33.0 (Arsenic) is what the numbers above
were measured on.

- [website](https://frama-c.com/) and [the repository](https://git.frama-c.com/pub/frama-c)
- [the Eva manual](https://frama-c.com/download/frama-c-eva-manual.pdf), whose
  taint chapter covers `-eva-domains taint` and the `taints` clause
- [the ACSL specification](https://frama-c.com/download/acsl.pdf), for
  `\tainted` and for what `taints` means on a declaration
