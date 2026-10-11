# Checking with Frama-C

`src/out/eva` is every residue in the tree read by a taint analysis rather than by a
model checker, and [`src/out/eva/verify`](../src/out/eva/verify) is its script:

`./src/out/eva/verify [--corpus] [--full] [file.c ...]`

The whole tree, held-back subtrees included, comes out in about four minutes.
That run was made before the `fscalar_product` port and the seven case-study
leaves after it, and said

```
all 335 agree
```

The tree holds 375 residues now. A default run over 247 of them, the other 128
held back, takes four and a half minutes.

`fact/naive/salsa20` is the slowest file in it at 11 seconds and a typical
residue answers in about one.

A default run leaves out the same five trees the other two scripts leave out,
in the same two tiers, and `--corpus` and `--full` add them back the same way.
The reasons for leaving them out are theirs rather than Eva's, which is cheap
on all five: 174 seconds for the main suite, 230 with the corpus and 241 for
everything. What the tiers buy here is that a default run of all three scripts
covers the same files, so a three-way disagreement is about the backends
rather than about which tree somebody remembered to check.

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

## Telling the secret draw apart from the public one

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

## Reading a verdict, which is where this gets sharp

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

## The bound

`<N>` is the same `[unwind N]` CBMC gets, spent on recursive calls instead of
loops, and not giving Eva one produced every vacuous answer above. Thirty-one of
the 214 residues the tree then held need it to answer what the tree claims, and they are three
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

## What it costs, which is one flag

One sitting, one machine, and the tree as it stood before the
`fscalar_product` port and the seven case-study leaves after it, which added
five and thirty-five files per backend between them. The counts below are that
tree's and the seconds were taken together, so they compare to each other and
not to a run made today. The thirty-five leaf residues were timed on their own
and Eva answers the set in 76 seconds, which is the only number here that was
taken later.

CBMC answers the main suite's 207 residues in 171 seconds, 316 with `--corpus`
in 272, and all 335 in 339. Eva's three tiers are 174, 230 and 241. Level on
the default run and a hundred seconds cheaper on everything, which is the
opposite of where it started.

Where it started was 1543 seconds over those same 207 files, six times what
CBMC cost at the time, for a weaker question. The whole difference is
`-eva-no-results`. Eva keeps a state per statement by
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
is [reading a verdict](#reading-a-verdict-which-is-where-this-gets-sharp)
above.

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

## Three ways to ask, and what each one charges

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
The [probe-count dial](probe-dial.md) turns `branchy` into six sizes
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
seventy-nine of the full 323, always a clean program widened to `leak` and
never the other way.

## What it agrees on

244 of the 323 residues come out matching `Verdict`, and all 79 that do not are
a `clean` widened to a `leak`. None goes the other way, which is the direction
that would matter. Nothing in the tree answers `unknown` and nothing errors.

Thirteen demos account for the 79. `bypass` and `bypass_late` are nine each, one
per model with a cache in front of the load that also commits its store the
instant it runs. The load takes a secret address and then costs the same either
way, so the dependence is real and the difference is not. Under `forwarding`,
which queues the store, both are genuine leaks and Eva agrees with the other
two.

`retired` is eleven and `inflight` nine, the two Spectre-STL shapes that scrub
the secret word and then read that same word back. The load's address is the
secret's whether or not the store landed, so from there the taint is on the
channel, and whether the zero that came back could have moved a clock is the
question Eva does not ask. `inflight` is two short of `retired` because under
`forwarding` it is a genuine leak and Eva agrees about those. The three
`stale_*` shapes widen nowhere, since none of them loads through the secret's
address once the store has committed.

`balanced` is six and is the clearest of them, since both arms of the branch
cost exactly the same. `evict` is five, four where the memory system does not
stall and one where the cache has a single set and so cannot have a conflict at
all, and `hidden` is four, the same non-stalling models. In all of those the
secret reaches `cache_age` through the `if` that writes it, and nothing Eva
tracks says the eviction it decides costs nothing here.

The Kocher ports are twenty-five between them: `v10` and `v21` seven each, `v25`
six, `v20` three and `v20r` two. That is every clean cell they have except the
`naive` ones belonging to the three whose channel is an address, because without
a cache an address cannot move a clock and Eva has nothing to over-approximate.
`v10` and `v21` put the secret in a branch condition instead, which taint
follows whether or not a model has a cache, so their `naive` cells widen too.
The last of the 79 is `fact/cache/guarded`.

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
