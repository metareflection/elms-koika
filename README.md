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
An off-the-shelf analyzer (like [CBMC](#cbmc)) can then analyze the residue C file to check whether the first-order timing and secret inputs are noninterfering.

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
`llc` and a `clang` that can target RV32IM. The FaCT compiler is not among
them, because what is checked in is the LLVM it emitted. Skip this and the five
FaCT suites fail twenty-five times over with a missing object.

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

The examples go through three checkers, one tree of snapshots each.
[CBMC](#cbmc) and [KLEE](#klee) both decide the timing claim outright and agree
on every residue in the tree; [Frama-C](#frama-c) answers a weaker question,
whether the secret reaches the timer at all, and pays for the speed by calling
some clean programs leaky. How each one is invoked, and how a verdict is read
back out of it, is [`doc/cbmc.md`](doc/cbmc.md),
[`doc/klee.md`](doc/klee.md) and [`doc/frama-c.md`](doc/frama-c.md).

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

`./src/out/cbmc/verify [--certify] [--corpus] [--full] [file.c ...]`

Three tiers, nested. With no arguments it takes the main suite. `--corpus` adds
the ported litmus variants under `pht/` and `stl/`. `--full` adds `lockstep/`,
`dynamic/`, `probe/` and `ghr/` on top of that, which is every snapshot in the
tree: 389 files, and 12 minutes of CBMC on the machine that measured it.

The corpus tier is the ported litmus variants, held back on volume. `pht/` is
six of Kocher's Spectre v1 variants and a seventh that probes the cache after
one of them, against all seven models. `stl/` is five Haunted Spectre-STL
shapes against seven models and five more in the squared tower, and the four
that leak do it in the one column `bypass` already leaks in. Between them that
is half the main suite again, and no verdict the tree cannot already state. A
default run is for noticing that a model stopped detecting what it detected; a
corpus is for reading across, and the flag is so that reading across does not
mean running everything.

The `--full` tier is four trees held back for reasons of their own, none of
them volume. `lockstep/` is five demos `squared/` also answers, by the
construction `squared/` replaced, and it is held back because it agrees and
costs time. `dynamic/` is held back because it is not settled. It drops the
control-flow assumption rather than making it, which is an open question about
the construction and not a second opinion on a closed one.
[`probe/`](doc/probe-dial.md) is held back on cost alone: it is one demo at six
sizes under both towers, and the sizes at the top are the whole point.
[`ghr/`](doc/global-history.md) is the fourth and is held back for `dynamic/`'s
reason rather than for cost. Every column of the table above is computed with
the predictor's history in the slot key, a bit per branch pc, so its state is
the residue's control flow; `ghr/` bounds the history to a shift register and
puts the table in the struct beside the cache instead. It is more expensive
on every demo here and is meant to be, since the crossover is at as many live
branches as the register has bits and nothing in this tree has more than four.
What it is for is the other side of that crossover, which is the code this
project has not reached yet.

`sbt testFull` regenerates all five whichever flag anybody passes, so what the
two flags buy is the check rather than the C. Naming files runs exactly those,
main suite or not.
It prints one line per file and exits non-zero if CBMC says anything other than
what the file claims, so a model that stops detecting what it used to detect is
a failing run rather than a stale comment. The claims themselves are greppable
without running anything:

`head -qn1 src/out/cbmc/**/*.check.c`

## What each model reports

Seven models against every demo in the tree. The first three demos exist for
both NanoRisc and RISC-V and answer the same on each, so the table does not
split them; NanoRisc has only the first three models, and RISC-V is what fills
the rest. The blanks are suites nobody has written. The seven `v` rows are the
Kocher ports under `pht/` and the five below them are the Haunted Spectre-STL
ports under `stl/`, both families behind `--corpus`; everything above them is
the main suite.

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
| `hsalsa20` | clean | clean | clean | clean | clean | | |
| `salsa_keysetup` | clean | clean | clean | clean | clean | | |
| `poly1305_init` | clean | clean | clean | clean | clean | | |
| `crypto_verify_16` | clean | clean | clean | clean | clean | | |
| `guarded` | clean | clean | leak | leak | leak | | |
| `choose` | clean | clean | clean | clean | clean | | |
| `folded` | leak | leak | leak | leak | leak | | |
| `fscalar_product` | leak | leak | leak | leak | leak | | |
| `fsum` | clean | clean | clean | clean | clean | | |
| `fdifference_backwards` | clean | clean | clean | clean | clean | | |
| `swap_conditional` | clean | clean | clean | clean | clean | | |
| `branchy` | clean | clean | clean | clean | | clean | clean |
| `bypass` | clean | clean | clean | clean | leak | clean | clean |
| `bypass_ct` | clean | clean | clean | clean | clean | clean | clean |
| `bypass_late` | clean | clean | clean | clean | leak | clean | clean |
| `dynstore` | clean | clean | clean | clean | clean | clean | clean |
| `bypass_alias` | clean | clean | clean | clean | leak | clean | clean |
| `balanced` | clean | clean | leak | leak | leak | clean | clean |
| `v08` | clean | leak | leak | leak | leak | leak | leak |
| `v10` | clean | clean | clean | clean | clean | clean | clean |
| `v17` | leak | leak | leak | leak | leak | leak | leak |
| `v20` | clean | clean | leak | leak | leak | clean | clean |
| `v20r` | clean | clean | leak | leak | leak | clean | leak |
| `v21` | clean | clean | clean | clean | clean | clean | clean |
| `v25` | clean | clean | clean | clean | clean | clean | clean |
| `stale_ptr` | clean | clean | clean | clean | leak | clean | clean |
| `stale_mask` | clean | clean | clean | clean | leak | clean | clean |
| `stale_index` | clean | clean | clean | clean | leak | clean | clean |
| `inflight` | clean | clean | clean | clean | leak | clean | clean |
| `retired` | clean | clean | clean | clean | clean | clean | clean |

[`doc/models.md`](doc/models.md) reads across it: which rows the geometry was
for, where the chain of models stops being a chain, and why the two columns on
the right take rows away rather than adding them.

Four of those seven columns have a branch predictor in them, and all four
specialize over its history rather than reifying it. A slot is keyed on what
the predictor believes, so the predictor in the generated C is which function
you are in: the functions one pc is numbered into are its state, written as
control flow instead of as a table. Nothing is missing from the end-to-end
account, since the unstaged interpreter has the predictor whichever side of the
staging boundary it ends up on. What moves is the representation, and the slot
key is the line it moves across.

That is the model the whole table is computed on and it is the cheaper
representation on every demo here.
[`doc/global-history.md`](doc/global-history.md) moves the same state to the
other side of that line, held back behind `--full`, and it is where the
question of how far any of this reaches gets asked.

## Documentation

The README is the map. Everything measured, and every model written out in
full, lives under [`doc/`](doc).

| | |
|---|---|
| [`models.md`](doc/models.md) | the table above, read across: which demo says what about which model, and why |
| [`cache.md`](doc/cache.md) | the three-level set-associative cache, what each knob costs, and where a store stops |
| [`store-forwarding.md`](doc/store-forwarding.md) | the store queue, the bypass, and the forward that should not have happened |
| [`non-blocking.md`](doc/non-blocking.md) | loads that land after the instruction that issued them, and the rows that go away when they do |
| [`squared-tower.md`](doc/squared-tower.md) | interpreting a program over a pair of states, and what the static and dynamic constructions each decide |
| [`squared-vs-self-composition.md`](doc/squared-vs-self-composition.md) | the measurement record behind that comparison |
| [`probe-dial.md`](doc/probe-dial.md) | one demo at six sizes under both towers, which is how the two constructions get compared at all |
| [`cbmc.md`](doc/cbmc.md) | the first backend: the flags, the unwinding bound, and what `--certify` is for |
| [`klee.md`](doc/klee.md) | the second backend, how a verdict is read out of it, and which files run out of budget |
| [`frama-c.md`](doc/frama-c.md) | the third backend, which answers a weaker question and says where that stops |
| [`fact.md`](doc/fact.md) | the FaCT ports, and the three of five objects that leak |
| [`global-history.md`](doc/global-history.md) | the predictor as a bounded register, what it costs on this tree and what it buys past it |

Those files carry timings. Every one was measured on one machine at one commit
and none of them is a number a test checks, so treat them as the shape of a
cost rather than as a figure to reproduce.

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
and, on this tree, not a cheaper one. 33.0 (Arsenic) is the version
[`doc/frama-c.md`](doc/frama-c.md) measured against.

- [website](https://frama-c.com/) and [the repository](https://git.frama-c.com/pub/frama-c)
- [the Eva manual](https://frama-c.com/download/frama-c-eva-manual.pdf), whose
  taint chapter covers `-eva-domains taint` and the `taints` clause
- [the ACSL specification](https://frama-c.com/download/acsl.pdf), for
  `\tainted` and for what `taints` means on a declaration
