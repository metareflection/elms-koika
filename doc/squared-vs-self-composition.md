# What the squared tower buys a symbolic executor

Measured 2026-10-06 and 2026-10-07 against the tree at
`turn the probe count into a dial, and run both towers up it`.

The squared interpreter runs a program over a pair of states, shares one copy
of the control flow between the two runs, and compares their clocks on the way
into every slot. Self-composition runs the residue twice and compares the two
clocks once at the end. Under CBMC the first is known to cost more than the
second, so the question here is whether a symbolic executor, whose bill is a
path space rather than a formula, pays differently.

It does, in both directions, and not for the reason the construction was built
on.

- **The squared assumptions prune nothing under KLEE.** This is structural
  rather than a property of the demos. Each slot emits `squared_assert(c)`
  immediately followed by `squared_assume(c)`, and KLEE's assertion already
  forks on `c`, terminates the failing branch and leaves `c` in the surviving
  state's path condition. Rewriting every `squared_assume` to a no-op leaves
  the completed path count unchanged on all five residues tried.
- **The squared tower nevertheless wins on the one demo whose cost is a path
  space**, by 1.53x at four probes, with the margin growing in the size of the
  space. The cause is that each path walks the program once rather than twice:
  half the instructions and two thirds of the solver queries.
- **It loses between 1.5x and 4x everywhere else**, worst on residues with many
  slots. CBMC folds a residue's assertions into one formula; KLEE pays a solver
  query per fork point, so comparing clocks at every slot is cheap for one
  backend and expensive for the other.
- **CBMC and KLEE disagree about which construction scales.** On the same dial,
  CBMC goes from parity at four probes to 1.50x against the squared tower at
  six, while KLEE goes from parity at two to 0.65 in its favour at four.

## Method

KLEE 3.1 from `docker.io/klee/klee:3.1` under `podman`, with the image's own
`clang` at `-O0`, which is the pairing `src/out/klee/verify` uses. Verdicts are
read by that script's three conditions: any `*.err` file is a leak, and a clean
verdict additionally requires `completed paths > 0`, `partially completed paths
== 0` and no `halting execution` on stderr. Counters are KLEE's own, out of the
`info` file and `run.stats`.

CBMC through `src/out/cbmc/verify`, so the flags and the unwinding bound are the
tree's rather than this experiment's. Eva likewise.

Twenty-core machine. Where a measurement was taken with other jobs on the box,
the table says so. KLEE's searcher is randomised, so a single run near its
budget is not reproducible: `riscv/static/hidden` read `unknown` at a 60s budget
in one run and settled in 53.9s in the next. Every number below that a
conclusion rests on was re-taken at a budget the file comfortably fits inside.

## Why the assumptions are inert

A squared slot emits the comparison twice, once as a question and once as a
constraint:

```c
bool v1316 = v1293 == v1295;
squared_assert(v1316);
squared_assume(v1316);
```

Under CBMC these are two different things. `__CPROVER_assert` adds a proof
obligation and no constraint, `__CPROVER_assume` adds a constraint and no
obligation, and the second genuinely shrinks the formula the solver is handed.

Under KLEE they are not. `klee_assert(e)` expands to
`e ? (void)0 : __assert_fail(...)`. KLEE forks on `e`, reports the false branch
as an error and terminates it, and the branch that continues carries `e` in its
path condition. The `klee_assume(e)` on the next line therefore asserts
something already implied. The same holds for the `squared_diverged` pair that
guards a shared conditional.

The consequence is sharper than "the assumption is redundant". The set of paths
`squared_assume` could cut is exactly the set `squared_assert` has already
reported as counterexamples. On a program the squared tower calls clean that
set is empty. On a program it calls leaky, the search stops at the first member.
There is no third case in which the pruning could fire.

### The control

`squared_assume` is emitted as a one-line C function, so neutering it is a
one-line edit. Five residues, two runs of each, 900s budget:

| residue | assume on | assume off | completed paths |
|---|---|---|---|
| `squared/riscv/cache/constant_time` | 0.9s, 0.8s | 0.8s, 0.8s | 4 and 4 |
| `squared/riscv/static/bypass_ct` | 15.9s, 15.7s | 15.2s, 15.0s | 1 and 1 |
| `squared/riscv/predictive_nb/evict` | 14.7s, 14.3s | 13.5s, 13.0s | 4 and 4 |
| `squared/riscv/static/bypass` | 35.2s, 34.9s | 26.7s, 26.0s | 1 and 1 |
| `probe/squared/k3` | 151.5s, 147.4s | 199.7s, 191.4s | 9 and 9 |

The path counts are identical in every case. The times move by about a quarter
in both directions, which is the extra constraint making individual queries
easier or harder rather than removing any.

## The probe-count dial

`riscv/cache/branchy` is the only demo in the tree whose cost is a path space
rather than a formula: it walks a table at addresses nobody knows, each load
forks three ways, and the program is clean, so a checker has to clear the space
instead of exhibiting one member of it. Its probe count was written out in the
assembly, which made it a fixed point rather than a parameter.
`src/test/asm/riscv/probe.s` is that demo with the count as a `--defsym`, staged
at one through six under both constructions by
`src/test/scala/elms/riscv/probe.scala`.

`probe/self/k4` and `riscv/cache/branchy` stage into residues of the same
length, 1130 lines, and their squared twins into 2281. That is the control
saying the dial reproduces the demo it generalises.

### KLEE

| probes | self-composed | squared | ratio | completed paths | queries | instructions |
|---|---|---|---|---|---|---|
| 1 | 3.9s | 3.8s | 0.97 | 2 and 2 | 79 / 71 | 11,646 / 11,087 |
| 2 | 27.5s | 27.0s | 0.98 | 4 and 4 | 220 / 207 | 22,145 / 18,141 |
| 3 | 156.2s | 130.9s | 0.84 | 9 and 9 | 637 / 511 | 51,938 / 33,612 |
| 4 | 928.6s | 605.7s | 0.65 | 23 and 23 | 2003 / 1283 | 146,180 / 72,215 |
| 5 | no verdict | no verdict | | | | |
| 6 | no verdict | no verdict | | | | |

The wall times at one through three were re-taken on an idle machine; four was
taken with one other job running. The counter columns come from the earlier
instrumented pass, which ran under more load, so read them against each other
rather than against the clock beside them.

The fourth column is the result. The completed path counts are equal at every
setting, so whatever the squared column is saving, it is not search. What it
saves is the length of each path. Self-composition's `main` calls the residue
twice:

```c
struct StateT *s1_ = snippet(&s1);
struct StateT *s2_ = snippet(&s2);
```

The squared one calls it once, carrying both states:

```c
struct StateT2 p = { .a = &s1, .b = &s2 };
struct StateT2 *p_ = snippet(&p);
```

Same paths, half the work along each. The 72,215 against 146,180 instructions
at four probes is that, and the 0.65 follows from it.

### CBMC

| probes | self-composed | squared |
|---|---|---|
| 1 | 0.20s | 0.21s |
| 2 | 0.31s | 0.34s |
| 3 | 0.57s | 0.61s |
| 4 | 1.50s | 1.39s |
| 5 | 5.79s | 7.11s |
| 6 | 17.25s | 25.80s |

The same dial, the opposite slope. CBMC's cost is one formula over the whole
space, so the squared residue's extra width is charged once and its extra
assertions are charged once, and both grow with the space. Eva answers all
twelve in about a second each, because taint does not care how large a path
space is.

## The rest of the tree

Every demo that exists in both towers, 76 pairs, 60 seconds apiece. Sixty-one
settled on both sides within that budget, and 52 of those have identical
completed path counts. The nine that differ are `balanced`, where the squared
column is answering its second question and reports a different verdict, and
leaks, where the search stops at whichever witness the randomised searcher
reaches first.

Restricting to pairs where at least one side cost more than five seconds, so
that the ratio means something:

| | pairs | median squared/self | range |
|---|---|---|---|
| clean, so a proof | 16 | 1.55 | 0.94 to 1.66 |
| leak, so a witness | 14 | 0.94 | 0.78 to 1.12 |

The `bypass` family supplies most of the first row at 1.46 to 1.66. The 6% in
the second row is the squared tower asserting at the slot where the drift starts
rather than after both runs have finished.

### Where the per-slot comparison is expensive

`hidden` is the worst case and the most informative one. At a 900s budget on an
idle machine:

| model | self-composed | squared |
|---|---|---|
| `static` | 53.9s | 228.8s |
| `predictive` | 57.1s | 215.1s |
| `forwarding` | 57.0s | 214.2s |

That residue carries 227 `squared_assert` calls, against 8 to 11 for the
`bypass` family. The query count goes from 279 to 898 and the instruction count
from 99,744 to 121,853, so the extra time is the assertions rather than the
width. Each one is a fork point KLEE pays a solver query for, and all but the
last are provably true along the path that reaches them.

This is the clearest statement of the backend asymmetry. Comparing the clocks
once per slot is close to free for a bounded model checker, which folds the
whole residue into one formula, and is linear in the slot count for a symbolic
executor.

## Threats to validity

The dial varies one demo. `branchy` is the only program in the tree whose cost
is a path space, so the k=4 result is one data point about one shape, taken
four times at different sizes.

The 60s sweep caps 15 of the 76 pairs on at least one side, and those rows are
excluded from the ratios above rather than counted as ties. The pairs that
remain are the cheap half of the tree, so the 1.55 median is a statement about
residues costing seconds, not minutes. The three `hidden` pairs are the only
expensive ones re-taken at a real budget, and they are worse than the median
rather than better.

Machine load varies across the tables, as each one says. No ratio quoted here
rests on a difference smaller than 15%, except the leak row, where the claim is
that the two are close.

## Open questions

**The single pass and the per-slot comparison are separable, and nobody has
separated them.** The pass is worth a third of the time at four probes; the
comparisons cost four times on `hidden`. A construction that interleaves the two
runs without comparing clocks at every slot would take the first without paying
the second. It would also stop deciding the stronger property, which is what
the comparisons are for, so this is a question about what the tower is for
rather than a missing optimisation.

**`squared_assert` decides a stronger property than anyone has written down.**
It demands the two clocks agree at *every* slot, which is strictly stronger than
agreeing at the end. A program whose clocks drift and reconverge is clean to
self-composition and a leak to the squared tower, by the same mechanism that
makes `balanced` disagree on control flow. No demo in this tree has that shape,
so the two towers agreeing on sixty-nine verdicts is weaker evidence of
equivalence than it appears. Constructing one is the obvious next demo: two
loads at secret-permuted addresses with equal total cost would do it without a
branch anywhere.
