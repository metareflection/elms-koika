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
[`verify`](src/out/cbmc/verify) reads it back out and runs the checker:

`./src/out/cbmc/verify [--certify] [file.c ...]`

With no arguments it takes every snapshot in the tree, 86 of them in 64 seconds.
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

What that buys depends on who is holding the bill. It is a rewrite of the
formula's shape and not of its size, so on an elaborator-bound demo it comes out
a little slower; where the solver is the cost it is worth a lot, and more as the
path space grows. `branchy` at the twelve probes it ships with is 6.1s against
6.7s, and at eighteen it is 30.1s against 149.9s.

Here is what they currently say. The first three demos exist for both NanoRisc
and RISC-V and answer the same on each, so the table does not split them;
NanoRisc has neither a predictive nor a forwarding model, and RISC-V is what
fills those columns. The blanks are suites nobody has written: `cmp` under
cache, and `cmp` and `branchy` under forwarding.

| demo | naive | cache | speculative | predictive | forwarding |
|---|---|---|---|---|---|
| `shortcircuit` | leak | leak | leak | leak | leak |
| `2ctr` | clean | leak | leak | leak | leak |
| `spectre` | clean | clean | leak | leak | leak |
| `constant_time` | clean | clean | clean | clean | clean |
| `cmp` | leak | | leak | leak | |
| `salsa20` | clean | clean | clean | clean | clean |
| `guarded` | clean | clean | leak | leak | leak |
| `choose` | clean | clean | clean | clean | clean |
| `folded` | leak | leak | leak | leak | leak |
| `branchy` | clean | clean | clean | clean | |
| `bypass` | clean | clean | clean | clean | leak |
| `bypass_ct` | clean | clean | clean | clean | clean |
| `bypass_late` | clean | clean | clean | clean | leak |
| `dynstore` | clean | clean | clean | clean | clean |
| `bypass_alias` | clean | clean | clean | clean | leak |

Reading across the first four columns is the tower. No model loses a leak the
one to its left could see, and `2ctr` and `spectre` are where it starts seeing
more: `2ctr` needs a cache before the second load's address can cost anything,
and `spectre` needs speculation before that load happens at all. `guarded` is
`spectre`'s row written again and `folded` is `shortcircuit`'s, and the FaCT
section below is why either was worth a demo of its own.

The fifth column is not the fifth step of that chain. `forwarding` extends
`speculative` and so catches everything it does, but `predictive` catches
`bypass` no better than `naive` does and `forwarding` has no branch predictor in
it, so the two are unordered and the columns are a lattice rather than a line.
The order is naive, then cache, then speculative, then either of the last two.

`branchy` is the odd one out and is RISC-V only, because it indexes `mem` with
five bits and so wants an array of exactly 32 words where every other demo here
runs on 30. It is a walk over twelve addresses nobody knows and everybody
agrees on, which is the one shape in this tree whose cost is the solver rather
than the elaborator: under `cache` it spends 5.8 of its 6.1 seconds in the
solver, where `salsa20` spends 4.3 of its 4.8 in symbolic execution. Every other clean demo
is cheap for the wrong reason, `constant_time` because it has three branches and
`salsa20` because it has none, so neither says anything about a checker that has
to rule out a path space rather than exhibit one member of it.

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
fill their row by getting a bounds check wrong, and the four models to the left
of this one see nothing here at all: they commit the store where it stands, the
load reads the zero, and the channel address is 0 in both runs. Two knobs decide
the rest, `storeLatency` and `storeWindow` on `Forwarding`, at two and four
instructions.

CBMC's counterexample is worth reading, because the residue has two channels in
it and the witness picks the cheaper one. Both runs draw the attacker index 28,
so both queue the same store address and both read around it at word 27. The
secret sitting there is 0 in one run and 18 in the other, so the last load
probes word 0 against word 18, the alias resolves, and both runs squash. The
registers come back. The cache does not, so when the re-run probes word 0 the
run that already touched it pays a cycle for the LRU's tail and the other pays a
hundred for a miss. 227 cycles against 326, and 99 is the difference between
those two.

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
`Forwarding.forwardCost` is 1 and `Cached`'s LRU tail hit is also 1, so those
two arms are not even distinguishable in the timer.

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
again for a cycle. 429 against 330. The close catches both false forwards and
squashes, and the cache keeps the line.

Under every other model the load reads word 0 and gets the public zero, so the
channel address is word 0 in both runs and there is nothing to report. This is
the 4K-aliasing shape, scaled to thirty words the way the two-entry cache is
scaled: a real queue compares a twelve-bit page offset, which over an address
space is a curiosity and over `mem` would be exact.

### Most of the column is a copy

Only five programs in the tree put a store inside reach of a window. `2ctr`,
`spectre`, `shortcircuit`, `constant_time`, `choose.o` and `folded.o` contain no
store at all, and `guarded.o`'s is its last instruction, so

`diff src/out/cbmc/riscv/{speculative,forwarding}/spectre.check.c`

is empty, and so are thirteen other pairs. Fourteen of the twenty-six snapshots
in this column are their speculative twin to the byte, which is worth
generating: a model that only ever adds a channel has to leave a program with no
store alone, and the snapshots are the proof rather than the claim. The twelve
that differ are `salsa20`, `bypass`, `bypass_ct`, `bypass_late`, `dynstore` and
`bypass_alias`, once per backend.

## Checking with KLEE

`src/out/klee` is the same 86 residues checked by [KLEE](#KLEE) instead, and
[`src/out/klee/verify`](src/out/klee/verify) is its script:

`./src/out/klee/verify [--slow | --only-slow] [file.c ...]`

Both trees agree, 86 verdicts for 86, model sensitivity included. That agreement
is the point of having two: a residue really is an ordinary C program, and
nothing about the claim depends on which checker reads it.

Only the prelude differs between a pair of snapshots, so

`diff src/out/{cbmc,klee}/riscv/cache/2ctr.check.c`

changes thirteen lines, and so does every one of the other 85 pairs.
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

That case is real and four files in the tree are it. `runCache` is a two-way LRU
with three arms, so it forks threefold per symbolic load, and `branchy`'s twelve
probes are (3^12 + 1) / 2 paths. CBMC answers each in under eight seconds and
KLEE does not arrive, so those tests say so where they call `check`:

```scala
check("cache/branchy", snippet, Verdict.Clean, klee = Reach.LikelyTimeout)
```

which writes `clean likely-timeout` onto the line. The verdict is still the
program's, and a run that somehow finishes has to produce it; what
`LikelyTimeout` adds is that running out of budget is also a pass. Demanding the
timeout would turn a faster solver into a failing test, and demanding the
verdict asks KLEE for something it cannot give here, so either outcome is
accepted and a wrong one still is not. `naive/branchy` has no cache in front of
those probes, walks one path, and verifies.

Each of those four costs a full budget, so a default run skips them and says
which it skipped:

```
skip     src/out/klee/riscv/cache/branchy.check.c (likely-timeout; pass --slow to run it)
all 49 agree (4 skipped)
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
load and it reverses, from 4x behind on a five-path space to not answering at
all. CBMC finishes every residue here; KLEE finishes 82 of 86.

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
clears every model:

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
