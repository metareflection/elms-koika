# The probe-count dial

`riscv/cache/branchy` is the one demo here whose bill is a path space rather
than a formula, and for most of this tree's life its four probes were written
out in an `.irp` in the assembly. So every claim about how a checker scales was
a claim about two points somebody had measured months apart.
[`probe.s`](../src/test/asm/riscv/probe.s) is that demo with the count as a
`--defsym`, one source assembled into `probe1.o` through `probe6.o`, and
[`probe.scala`](../src/test/scala/elms/riscv/probe.scala) stages each of them
under both towers. Twelve snapshots per backend under `src/out/*/probe`, held
back from a default `verify` because the settings at the top of the dial are
the entire point of having one.

[`doc/squared-vs-self-composition.md`](squared-vs-self-composition.md) is
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

## What is actually cheaper

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

## Why the assumptions cannot help a symbolic executor

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

## What it costs everywhere else

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

## What this leaves open

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
