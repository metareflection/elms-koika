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

Running `sbt test` from the root will run all the tests,
generating `.actual` files and checking them against the `.check` files in [`src/out`](src/out).
Failing tests will leave the generated `.actual` files for inspection.
Snapshot files mostly follow the naming convention of `[testfile]/[suffix].check.c`.

The examples are verified using [CBMC](#CBMC) as follows:

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
`max(num_regs, mem_size, cache_size, secret_size) + 1`, which is every loop in
the hand-written C around the residue plus the exit test, and a demo whose own
recursion runs deeper than that overrides it. 33 for the RISC-V demos and 65 for
the FaCT ports, where the tree used to run everything at 1000 and pay 172
seconds for `compiled/naive` alone.

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
[`verify`](src/out/verify) reads it back out and runs the checker:

`./src/out/verify [--certify] [file.c ...]`

With no arguments it takes every snapshot in the tree, 41 of them in 58 seconds.
It prints one line per file and exits non-zero if CBMC says anything other than
what the file claims, so a model that stops detecting what it used to detect is
a failing run rather than a stale comment. The claims themselves are greppable
without running anything:

`head -qn1 src/out/**/*.check.c`

The tree under [`src/out/lockstep`](src/out/lockstep) is the same demos answered
a different way. `Lockstep` rewrites a residue into a product of itself with
itself, so one run of one copy of the control flow carries both states and the
timers are compared on entry to every slot rather than once at the end. Every
verdict there has to match its twin next door, because the two are answering the
same question about the same program.

What that buys depends on who is holding the bill. It is a rewrite of the
formula's shape and not of its size, so on an elaborator-bound demo it comes out
a little slower; where the solver is the cost it is worth a lot, and more as the
path space grows. `branchy` at the twelve probes it ships with is 6.1s against
6.7s, and at eighteen it is 30.1s against 149.9s.

Here is what they currently say. The first three demos exist for both NanoRisc
and RISC-V and answer the same on each, so the table does not split them;
NanoRisc has no predictive model, and RISC-V is what fills that column. The one
blank is `cmp` under cache, which is a suite nobody has written.

| demo | naive | cache | speculative | predictive |
|---|---|---|---|---|
| `shortcircuit` | leak | leak | leak | leak |
| `2ctr` | clean | leak | leak | leak |
| `spectre` | clean | clean | leak | leak |
| `constant_time` | clean | clean | clean | clean |
| `cmp` | leak | | leak | leak |
| `salsa20` | clean | clean | clean | clean |
| `branchy` | clean | clean | clean | clean |

Reading across a row is the tower. No model loses a leak the one to its left
could see, and `2ctr` and `spectre` are where it starts seeing more: `2ctr`
needs a cache before the second load's address can cost anything, and `spectre`
needs speculation before that load happens at all.

`branchy` is the odd one out and is RISC-V only, because it indexes `mem` with
five bits and so wants an array of exactly 32 words where every other demo here
runs on 30. It is a walk over twelve addresses nobody knows and everybody
agrees on, which is the one shape in this tree whose cost is the solver rather
than the elaborator: under `cache` it spends 5.8 of its 6.1 seconds in the
solver, where `salsa20` spends 4.3 of its 4.8 in symbolic execution. Every other clean demo
is cheap for the wrong reason, `constant_time` because it has three branches and
`salsa20` because it has none, so neither says anything about a checker that has
to rule out a path space rather than exhibit one member of it.

## The FaCT suite

[FaCT](https://github.com/PLSysSec/FaCT) is a DSL whose type system rejects
programs that branch on a secret or index memory with one, and whose compiler
emits a branchless selection in place of the branch you would have written.
[`src/test/fact`](src/test/fact) ports the Salsa20 core from
[fact-eval](https://github.com/PLSysSec/fact-eval), the case studies published
alongside the FaCT paper.

We do not build the FaCT frontend to run it. What is checked in is the LLVM that
`factc` emitted, and

`./src/test/fact/build`

lowers it to RV32I with stock `opt`, `llc` and `clang`.
`./src/test/fact/factc` regenerates the `.ll` from the `.fact` source beside it
and is the only thing here that wants the FaCT compiler; it builds it under
`podman` from the image its authors published, and no test run needs it.

This is a positive control and there is no leaky twin. Salsa20 has no
conditional anywhere in it: every index is a literal and the only loop runs ten
times whatever the key is, so no model fails. What it adds over
`constant_time.s` is size. Everything else in the tree that verifies clean does
so in under twenty instructions; this is 277, and CBMC clears all four models:

| naive | cache | speculative | predictive |
|---|---|---|---|
| 4.6s | 5.2s | 5.2s | 6.5s |

Two things it needs that the assembly demos do not. It is the first demo that
spills, so `init` points `sp` at the top of `mem` rather than leaving it at 0,
and `mem_size` is computed from the frame the object actually declares. And
Speculative alone wants a bigger stack than the JVM's default 1MB, so
`build.sbt` raises `-Xss` for the forked test JVM. It inlines a speculation
window into the function that opened it, salsa20's longest runs 1696
statements, and ELMS elaborates a function body by recursing once per
statement. Nothing else here comes near that; naive, cache and predictive all
stage salsa20 on the default stack.

It is also the only case study the tower can take. curve25519-donna, poly1305,
both OpenSSL MEE versions and the Lucky13 fix in `openssl-ssl3/s3_cbc.fact` are
all multi-function, and `s3_cbc.fact` opens by declaring `extern void
SHA1_Transform`. One function per object is the whole budget, because a dynamic
jump cannot be staged against a static program counter.

## CBMC

We use the C Bounded Model Checker (CBMC) as an off-the-shelf analyzer since our residue C programs are ordinary programs where timing is an ordinary first-order variable. Some pointers:

- [original CMBC website](https://www.cprover.org/cbmc/)
- [a maintained implementation](https://github.com/diffblue/cbmc) with [latest releases](https://github.com/diffblue/cbmc/releases)
- [original manual](http://www.cprover.org/cprover-manual/) also in [PDF](https://www.cprover.org/cbmc/doc/manual.pdf)
