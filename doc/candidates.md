# Picking a real-world object to port

The tree's largest port is `salsa20`, 277 instructions and two branches. This is
the screen that was run to find the next one, what it measured, and which
candidate came out of it.

The answer is Monocypher's field arithmetic. The screen reached it through
`fe_mul`, 1215 instructions with no branch, no call and no loop, which verifies
clean in 4 seconds under `naive` and 29 seconds and 1.8 GB under `cache`. That is
4.4 times the largest object in the tree and, under `naive`, faster in absolute
terms than the 277-instruction program it replaces.

What landed is not `fe_mul`. Straight-line multiply-accumulate is constant-time by
construction and nobody ever suspected it, so a clean cell on it says the pipeline
works rather than that the library is safe. The port that says something is
[`fe_ccopy`](#what-landed-fe_ccopy-four-ways), the masked conditional copy, whose
own source comment names two mitigations against a compiler turning it into a
timing leak and claims either works alone. For clang targeting RV32IM at -O2 that
claim is half wrong, and `src/test/mono` is four objects that say which half.

Monocypher's `crypto_x25519` whole is the thing that does not fit, and the reason
is measured below.

## What a port is actually gated on

Three gates, and only the first two are about the object.

**The ISA.** [`Decode`](../src/test/scala/elms/riscv/elf/Decode.scala) takes RV32I
and RV32M's four multiplies. `div` and `rem` are refused by name, and so are
`fence`, `ecall`, `ebreak` and the CSRs. Nothing else encodes.

**The relocations.** [`Elf`](../src/test/scala/elms/riscv/elf/Elf.scala) wants one
allocatable executable section, no `R_RISCV_CALL_PLT`, no PC-relative `HI20`, and
every `jalr` paired with the `auipc` one word before it that computed its target.
Absolute `HI20`/`LO12` against data are fine and are what `--relocation-model=static`
emits.

**The branches.** The predictor's history axis costs two to the power of the live
branch count, so a program with 35 of them wants 2^35 slots under the bit-per-branch
key that every column of [the README's table](../README.md#what-each-model-reports)
is computed on. Four is the most anything in the tree has.
[`global-history.md`](global-history.md) is the other side of that.

A fourth gate is not about the object at all and is where the biggest candidate
died. It is the unwind bound, and it has its own section.

### `internalize` is what clears the relocations

A call to a `static` callee leaves no relocation, which is how the FaCT ports walk
in on a staging-time return stack. A call to a global one leaves
`R_RISCV_CALL_PLT`, and marking the callee `alwaysinline` does not help: inlining
does not change linkage, and six relocations survived it on a hand-written bignum.

`internalize` does change linkage. Lower through IR rather than compiling straight
to an object:

```
clang --target=riscv32 -march=rv32im -mabi=ilp32 -mno-relax -O2 \
      -ffreestanding -fno-builtin -emit-llvm -S -o $b.ll $b.c      # per TU
llvm-link -S -o all.ll *.ll
opt -passes='internalize,globaldce' -internalize-public-api-list=<entry> \
    -S all.ll -o int.ll
llc -mtriple=riscv32 -mattr=+m -O2 --relocation-model=static -o out.s int.ll
clang --target=riscv32 -march=rv32im -mabi=ilp32 -mno-relax -c out.s -o out.o
```

Every function but the entry becomes `internal`, the assembler resolves the calls
on the spot, and `globaldce` drops whatever the entry does not reach. That last
pass is also what makes the instruction counts below honest, since a library
compiled whole would carry the rest of itself.

So a dynamic jump was never what stopped a multi-function port, and neither was
the relocation. The relocation is an artifact of compiling straight to an object,
and the reader accepts the same program once it is gone. A 16-limb modexp the
reader had refused was accepted at 402 instructions after nothing changed but the
build.

Two things bite anyone copying the recipe. `libc` has to be shimmed, because
BearSSL and most of the rest include `string.h`, and the shim has to define
`memcpy`, `memset` and friends as `static inline`. `-ffreestanding` and
`-fno-builtin` together do not stop clang emitting a `memset` call for an
aggregate zero-init like `uint32_t t[2*N] = {0}`, which is a `CALL_PLT` and a
refusal; the inline definition in the shim is what catches it.

## The screen

Every candidate below was built with the recipe above and read with
`llvm-objdump`. Every one has one executable section, zero undefined symbols, zero
refused relocations, and zero `div`, `rem`, `fence`, `ecall`, CSR, atomic or float
instructions. Every `jalr` in every one of them is preceded by its `auipc`.

| object | what it is | insns | branches | max live | calls |
|---|---|---|---|---|---|
| `mono_x25519` | Monocypher X25519 | 5101 | 5 | **4** | 95 |
| `mono_poly1305` | Monocypher Poly1305 | 609 | 13 | 7 | 6 |
| `kyber_indcpa_dec` | ML-KEM-768 CPA decrypt | 697 | 18 | 7 | 33 |
| `i15_modpow` | BearSSL `br_i15_modpow` | 531 | 35 | 24 | 7 |
| `tn_sm` | TweetNaCl X25519 | 1377 | 34 | 26 | 15 |
| `kyber_dec` | ML-KEM-768 decapsulation | 3995 | 77 | 26 | 101 |

Leaves from the same builds, all clean on every gate: `mono_verify32` at 125
instructions and no branches, `kyber_verify` at 14, `kyber_cmov` at 13,
`kyber_poly_tomsg` at 66, `kyber_poly_compress` at 96, `i15_montymul` at 174.

### A screening tool has to count calls

Max live branches is the number of distinct conditional branches reachable from a
pc, maximised over pcs. Two warnings before the table, one about how the walk is
done and one about what the number is good for.

The second is the sharper one and it was learned the hard way, in
[Twelve branches is not twelve live branches](#twelve-branches-is-not-twelve-live-branches).
This is a static reachability count and it is not what the tower computes.
`Exec.liveBranchesAt` keys on the branches whose recorded outcome something still
goes on to read, so a program whose branches each execute once and are never
consulted again keys at zero of them however many the CFG holds. Straight-line
unrolled code is exactly that shape. The number below is a sound upper bound and a
fine filter for "could this be expensive"; it is not a prediction of what the
predictor models will charge, and it does not say which side of `ghr/`'s crossover
an object falls on. Only reuse of a branch outcome does that, and reuse means a
loop.

The first is about the walk. A screen that walks the CFG without following `jalr`
only reaches a callee's branches when the linker happened to lay it next, which is
sound for a one-function leaf and wrong for everything in the table above. The two
readings differ by about half:

| object | calls not followed | calls followed |
|---|---|---|
| `mono_x25519` | 3 | 4 |
| `i15_modpow` | 12 | 24 |
| `i31_modpow` | 11 | 25 |
| `tn_sm` | 17 | 26 |
| `kyber_dec` | 15 | 26 |

Following them means pairing `auipc` and `jalr` by `Elf.text`'s rule and giving a
call site both the callee's entry and its own next instruction. The two readings
agree on `salsa20`, `hsalsa20`, `fscalar_product` and `hidden`, which have no calls
in them at all.

This is a property of one throwaway screening script and not of anything in the
tree. [`Flow`](../src/test/scala/elms/riscv/Flow.scala) has followed calls since it
was written, `case Instr.Call(_, target) => (List(pc + 1), Some(target))`, and that
is what `shareable` and the live-history key are computed on. No verdict in the
tree is affected.

## Why Monocypher

Because it is large on the axis that is cheap and small on the axis that is not.

`hidden` is 226 instructions with no branches and clears `naive` in 609ms.
`hsalsa20` is 214 instructions with two branches and takes 4932ms. Eight times the
time for fewer instructions, same model and same flags, which is instruction count
failing to predict the bill. Residue size does no better: `salsa20` under
`predictive` emits 637 slots and 24279 lines against `naive`'s 277 and 3947 and
costs less than `cache` does. So 5101 instructions is not the expensive part, and
five branches is why.

Five is low for a reason, and the reason is the representation. `fe` is ten `i32`
limbs at radix 2^25.5, so a carry propagates by shift and mask rather than by
comparison. The 64-bit arithmetic is all there, 188 `mul` and 168 `mulh*`, and it
produces 231 `sltu` and not one branch.
[`fscalar_product`](fact.md#fscalar_product) is the same arithmetic written on
`uint64` limbs with a `uint128` accumulator, where comparing a carry means
comparing a pair of words, and that is where its four branches and its leak come
from. Monocypher never compares one.

The five that survive are all loop back-edges over public trip counts: a 32-byte
zero check in `crypto_x25519`, the ladder in `scalarmult`, and three squaring
chains in `invsqrt`. Not one is a conditional on data.

So the expected verdict is clean under every model, and the result is worth having
either way. Monocypher claims constant-time, has no secret-dependent branch in the
source, and is shipped. A leak would be the `guarded` result against a library
rather than against a demo.

## One object, nine entries

`internalize` leaves every function as a `FUNC` symbol, so `Elf.entries` holds all
nine of them and a driver names the one it wants. `Elf.starts` falls back to the
first global, which is `crypto_x25519`, and everything else is reachable by name.
That is what makes this a ladder rather than a single port:

| entry | insns | branches | calls | loop |
|---|---|---|---|---|
| `fe_mul_small` | 234 | 0 | 0 | no |
| `fe_frombytes_mask` | 254 | 0 | 0 | no |
| `fe_isequal` | 294 | 0 | 2 | no |
| `fe_sq` | 664 | 0 | 0 | no |
| `fe_tobytes` | 666 | 0 | 0 | no |
| `scalarmult` | 1119 | 1 | 17 | 255 trips |
| `fe_mul` | 1215 | 0 | 0 | no |
| `invsqrt` | 600 | 3 | 75 | yes |
| `crypto_x25519` | 55 | 1 | 1 | 32 trips |

Five of those have no branch, no call and no loop in them, which means they move
the instruction count and nothing else. `fe_mul` is the largest and is the
function the whole of X25519 rests on. `fe_tobytes` is the constant-time freeze
modulo 2^255-19, which is the step in a ref10-shaped implementation most worth
asking about.

The deepest chain is `crypto_x25519` into `scalarmult` into `invsqrt` into
`fe_mul`, whose frames are 48, 496, 160 and 784 bytes, so a whole-object port wants
1488 bytes of stack against `salsa20`'s 96. A leaf port wants one frame.
`mem_size` is free to CBMC either way.

### `fe_mul`, measured

The whole 5101-instruction object loads and the walk starts at `fe_mul`'s symbol,
at `unwind` 513 and `mem_size` 512 words, which is what the 784-byte frame wants.
Both operands drawn symbolic:

| model | slots | lines | staging | CBMC | peak RSS | verdict |
|---|---|---|---|---|---|---|
| `naive` | 1215 | 18325 | 2.0s | 4.0s | 274 MB | clean |
| `cache` | 1215 | 106551 | 4.7s | 29s | 1843 MB | clean |

Against `salsa20`, 277 instructions and two branches, that is 5.2s to 4.0s under
`naive` and 10.0s to 29s under `cache`. So 4.4 times the instruction count at zero
branches is *cheaper* in absolute terms under `naive`, and under `cache`
instruction count does cost but sublinearly across this pair. The branch finding
has no stronger form in this tree.

Drawing only one operand symbolic gives 30s and 1821 MB against the two-operand
29s and 1843 MB, so the formula is dominated by the instruction stream rather than
by the data. The figures above are the two-operand ones.

Clean is the expected answer for a constant-time field multiply and this is a cost
cell rather than a deep functional test: the addresses are fixed and there is no
control flow, so clean is close to structural here. The memory number is the one to
plan on. 1.8 GB for 1215 instructions under `cache` is what decides whether a step
up fits, and `scalarmult` at 1119 instructions is a comparable size but a different
shape, with seventeen calls and a branch, and has not been measured.

### `fe_tobytes`, measured

666 instructions, the constant-time freeze modulo 2^255-19, at `unwind` 129 and
`mem_size` 128 for its 192-byte frame. Staging 1.2s and 3.4s.

| model | slots | lines | CBMC | peak RSS | verdict |
|---|---|---|---|---|---|
| `naive` | 666 | 10012 | 3s | 147 MB | clean |
| `cache` | 666 | 101796 | 17s | 964 MB | clean |

The secret is drawn at ten limbs over `[0, 2^26-1]`, the radix the representation
uses, rather than at the tree's `secret(0, 20)`. A field element drawn below 21
never makes the conditional subtraction live, so the narrow draw would have left
the one thing worth testing untouched. That is
[`fscalar_product`'s draw bound](fact.md#the-draw-bound-is-part-of-the-claim)
again, pointing the same way.

The tower and the screen agree on the object: 666 instructions, 0 branches, 0
calls, 0 `jal`, one `ret`.

### What the two clean cells do and do not say

`fe_tobytes` is not the stronger result its subject matter suggests, and the
conditional count is why. Its `naive` residue holds zero `if` statements, so the
residue is straight-line and the timer is a constant chain; clean there confirms
the shape. Its `cache` residue holds 1958, all of them the three-level probe
forking per access, and CBMC spends 17 seconds and 964 MB proving they resolve
alike across the two runs. They resolve alike because the addresses are
compile-time constants, which is the shape again.

So what both cells establish is one property, machine-checked across 666 and 1215
instructions and a three-level cache: no secret reaches a branch and no secret
reaches an address. That is the property a ref10-shaped implementation gets wrong
when it writes the freeze as `if (carry) subtract()`, and the tower would catch
that. It is not a property that distinguishes Monocypher from any other
branch-free constant-address routine, and the freeze being arithmetic is readable
off the object before the tower runs.

The section to write about these five leaves is that they verify free of
secret-dependent control flow and addressing. Not that a finding came out of one.

[`fe_ccopy`](#what-landed-fe_ccopy-four-ways) is the one a finding came out of,
and the difference is not that it is more important code. It is that its
constant-time property is one the compiler can take away, so there is a pair to
run and a sentence of the library's own documentation to check. A routine nothing
could plausibly break is a routine whose clean cell was never in doubt.

### The positive control

So the clean cell is run against a broken one. `fe_tobytes` reduces by folding the
top limb back in:

```c
q *= 19;
FOR (i, 0, 5) { t[i*2] += q; q = t[i*2] >> 26; t[i*2] -= q * (1<<26); ... }
```

`q` is 0 or -1 according to whether `h` was already reduced, which is the secret.
Guard that loop on `if (q != 0)` and the secret is in the control flow. One edit in
`monocypher.c`, same entry symbol, same argument layout, same draw, same
`mem_size` and so the same `unwind`, and the same `port.sh` otherwise untouched:

| | `naive` | `cache` |
|---|---|---|
| `fe_tobytes` | clean, 3s, 147 MB | clean, 17s, 964 MB |
| `fe_tobytes` with the branch | **leak**, 3s, 193 MB | **leak**, 19s, 995 MB |

The object goes from 666 instructions and no branch to 631 and one. The branch is
`beqz a3, +0x678`, skipping 414 instructions, so its two arms are wildly unbalanced
and it leaks under `naive` as well: no cache and no speculation were needed, which
is the sentence [`folded`](fact.md#choose-and-folded) and
[`fscalar_product`](fact.md#fscalar_product) both earn.

The residue is where the diff is legible. The `naive` residue goes from zero `if`
statements to exactly one, and that is the whole of it. Under `cache` the 1795
conditionals against the clean 1958 are the probe's own arms in both.

That is what the clean cells are worth, and they are worth it only as the pair.
One pipeline, one entry, one draw, one branch introduced, and the verdict flips.
The broken variant is not functionally equivalent and is not meant to be; it is
[`guarded`](fact.md#guarded)'s construction aimed at a shipped library rather than
at a FaCT program.

Neither object is in the tree, and neither needs to be. The pair below is the same
construction with the branch supplied by the compiler instead of by hand, which is
a different class of evidence, and it is what `src/test/mono` holds.

## What landed: `fe_ccopy`, four ways

`fe_ccopy` is the masked conditional copy `invsqrt` finishes on. Monocypher's
comment above it says a compiler may

> replace the arithmetic by a secret dependent branch, or (as has been observed),
> swap pointers instead of values, which introduces a secret dependent index

and names two mitigations, `volatile` on the mask and unrolling the copy loop,
with the claim that "those mitigation work when applied separately or together".

Four objects, built by [`src/test/mono/build`](../src/test/mono/build) out of one
source file holding all four bodies verbatim, so the differences are readable side
by side:

| object | mitigations | insns | branches | loads | frame |
|---|---|---|---|---|---|
| `shipped` | both | 82 | 0 | 32 | 16 B |
| `volatile` | `volatile` only | 82 | 0 | 32 | 16 B |
| `unrolled` | unrolling only | 68 | **12** | 14 | none |
| `plain` | neither | 68 | **12** | 14 | none |

`unrolled` is the row the comment does not predict. It carries one of the two
mitigations, applied separately, exactly as the comment says is sufficient, and it
leaks as hard as carrying neither.

The four objects are two. Disassemble all four, drop the leading address on each
line and the function name inside each branch annotation, and `shipped` and
`volatile` hash to one value while `unrolled` and `plain` hash to another.

Say what was normalized or the check disagrees with itself. The annotation on
every branch carries the name of the function it is in, and those differ by
construction, so stripping only the address reports all four objects as distinct.
That is the first answer anyone reproducing this gets, and it is wrong. The
partition into two was run twice, independently, with different stripping details
and so different hash values, which is why the procedure is written out here and
no hash is quoted to match against.

So the unrolling mitigation does not reach the object at all. At -O2 clang unrolls
a ten-iteration loop over a literal bound whether or not the source already did,
which makes the written-out version redundant rather than weak, and `volatile` is
carrying the whole thing alone.

That is a statement about this compiler at this optimization level. Monocypher's
comment is defending against compilers in general, including ones that do not
unroll, and on such a compiler the written-out loop is doing exactly what it was
put there to do. Nobody measured one. What is measured here is that the unrolling
is not load bearing on clang at -O2 for RV32IM, not that writing it was a mistake.

Twenty cells, five models each, and every one agrees with the row above it:

| | `naive` | `cache` | `static` | `predictive` | `forwarding` |
|---|---|---|---|---|---|
| `shipped` | clean | clean | clean | clean | clean |
| `volatile` | clean | clean | clean | clean | clean |
| `unrolled` | **leak** | **leak** | **leak** | **leak** | **leak** |
| `plain` | **leak** | **leak** | **leak** | **leak** | **leak** |

Uniform across the five columns is the claim. The branch is on the secret and its
arms are unbalanced, so `naive` finds it with neither a cache nor a predictor in
the model, which is the sentence [`folded`](fact.md#choose-and-folded) and
[`fscalar_product`](fact.md#fscalar_product) both earn. Nothing here needs a
machine to speculate; the leak is in what llc emitted.

The cost is not uniform. The four `naive` cells answer in 53 seconds together and
the other sixteen take 17 minutes, almost all of it on the two leaking objects
under `predictive` and `forwarding`, which peaked near 3 GB.

### Twelve branches is not twelve live branches

The obvious thing to say about a twelve-branch object is that it is finally past
the crossover [`global-history.md`](global-history.md) measures, where the tree's
own maximum is four live branches and nothing in it is on the winning side of the
dial. That was said here, and it is wrong. Measured, against `predictive`'s 84
slots on the same object:

| | slots | | slots |
|---|---|---|---|
| `h=1` | 200 | `h=3` | 618 |
| `h=2` | 342 | `h=4` | 1117 |

The bounded register is more expensive at every width, and at the width the
argument named it does not answer at all. Under an 8 GB cap, `predictive` settles
in 128s and 2.94 GB, `h=1` and `h=2` in 138s and 147s, and `h=3` and `h=4` are
killed at the cap after about six minutes.

The reason is the correction worth carrying, because it is about screening rather
than about this object. `live.py` and its successor count every branch in the
program as live. [`Exec.liveBranchesAt`](../src/test/scala/elms/riscv/Exec.scala)
does not: it keys on `Flow.trains(prog, pc) ++ consulted`, the branches whose
recorded outcome something still goes on to read. These twelve are twelve copies of
one unrolled body, each executed once, so nothing ever consults what they recorded
and the key drops all twelve. That is why `predictive` stays at 84 slots on a
twelve-branch program, and why `predictive` being slow here is not branch fanout
either.

So branch count does not decide the trade and neither does a screening tool's
maximum-live figure. Reuse of a branch outcome decides it, and reuse means a loop.
`HistoryFanoutSuite`'s `loop-same` family has one and this object does not, and no
number either session was quoting tells those two apart.

What would qualify, stated so the retired claim is replaced rather than deleted: a
loop whose branch outcomes are still being read by later branches, so the key has
to carry them. A bignum modular exponentiation with fifteen live branches inside
its ladder is the candidate, which is what
[`global-history.md`](global-history.md) already says the dial is waiting for, and
that admission stands untouched by anything here.

The unwind bound was ruled out as the explanation rather than assumed away.
`RiscVGhrDriver` raises `unwind` to `phtEntries + 1`, so `h=3` and `h=4` run at 97
and 193 where `h=2` runs at 65, and that alone could have been the whole effect.
Staging `h=2` and checking it at 193 costs 148s and 3.30 GB against 147s and
3.15 GB at 65. The bound is nearly free. The slots are not.

What is in the tree is four cells at two bits, the widest register that answers
about this object. All four agree with `predictive`, which is the point: the
register changes the bill and not the verdict.

They are worth keeping for a reason the slot counts do not show. Every other place
the two predictor representations meet in this tree is a program written to make
them meet: `GhrSuite`'s eight demos are built to exercise a predictor, and
`GhrFidelitySuite`'s `retrain` is a fixture built specifically to make the two
models disagree. The leaking pair is the only object a compiler produced on which
the two are compared, and the two agreeing there is a claim neither of the others
makes.

The clean pair is the control and a good one, 0 branches, 82 slots under both
models and two seconds under both, so a bounded register costs exactly nothing
where there is no history to keep.

The cost is lopsided, which decides what to drop first if the `--full` budget ever
binds. The set is 300 seconds and the clean pair is about 3 of them. The control is
nearly free and the interesting half is all of the bill.

If a number is wanted for the leaking pair at four bits, the honest one is that the
register cannot check them inside 8 GB.

Residue size runs the other way, and the pair is the cleanest test of why that this
tree has. The clean objects emit the larger residues, 8490 lines against 5903 under
`cache` and 13290 against 6438 under `forwarding`, because doing the work
unconditionally is 32 loads to model rather than 14. They are also enormously
cheaper to check:

| `predictive` | loads | time | memory |
|---|---|---|---|
| `shipped` | 32, all at literal offsets | 2s | 0.10 GB |
| `unrolled` | 14, some secret-derived | 128s | 2.94 GB |

Fewer than half the loads and sixty times the time. What costs is a load at an
address the solver cannot pin down, and the broken pair's `addi a3, a1, 0x8`
against `addi a3, a0, 0x8` followed by a `lw` is exactly that shape, while reading
both operands at fixed offsets and masking is exactly what is not. The tree already
had this measured on a synthetic 401-instruction program, 1.3s with no loads, 4.9s
with literal-offset loads and 62.8s with one secret-derived address per five
instructions; this is the same effect on an object a compiler produced.

It inverts the obvious reading of the load column. The constant-time version does
twice the memory traffic and is sixty times cheaper to verify, and it is cheaper
for the same property that makes it constant-time. The tower is cheapest on exactly
the programs worth checking.

The load column is the better number, because zero branches only says the hazard
you already know about is absent. 32 loads against 14 is the constant-time property
itself: the clean pair reads both operands every time and masks between them, and
the leaking pair reads whichever operand the branch selected. The frame column is
the mechanism in one number, since the sixteen bytes the clean pair spills are the
`volatile` mask, and a mask the optimizer must keep in memory is one it cannot
fold.

Both hazards the comment names turn up in the same compile. In `plain.o` the
`bnez a2, 0x40` at `0x24` guards an extra `lw a5, 0x0(a1)`, so its two arms differ
by a load and the leak needs no cache to find it. By the third limb the shape has
changed: `0x38` computes `addi a3, a0, 0x8` and `0x58` computes `addi a3, a1, 0x8`,
the two paths meet at `0x5c`, and what that `lw a3, 0x0(a3)` reads is an address
the secret chose. One compile, both hazards, neither written by hand.

### Why `fe_ccopy` and not `fe_cswap`

The comment covers both and says the problem "has yet to surface in `fe_cswap()`".
Two things keep it there, and neither is distance.

A conditional swap writes both destinations, so there is no `select` to fold back
into. A conditional copy chooses one of two values for one destination, which is a
`select` exactly.

And the condition has to arrive as a comparison, in the same basic block, where
instcombine can see it. That is what gives it an `i1` and lets it recognise `-b`
as a mask. The ladder's condition is `scalar_bit`, a shift and an `and`, so there
is no comparison and no `i1`; taking the `volatile` out of `fe_cswap` and inlining
it into a ladder-step driver gives 98 instructions and zero branches.

The entries here write that comparison inline, and that is a construction rather
than a transcription. `invsqrt` calls `fe_ccopy(isr, t0, 1 - (m1 | ms))` where `m1`
and `ms` come from `fe_isequal`, which at -O2 clang leaves out of line, so what
reaches the copy is a returned `int` and not an `i1` and the fold never happens.
The next section is what repairs the gap between the two.

This is [`src/test/fact/build`](../src/test/fact/build)'s mechanism, which already
records that instcombine folds FaCT's selection idiom into a `select` and that
RV32I, having no conditional move, lowers a `select` as a branch. The tree
demonstrates that on a synthetic `.fact` file. These four objects are the same
mechanism firing on a shipped library, and the `i1`-from-comparison detail is the
part the synthetic version cannot show, because it is what decides which of two
near-identical functions in the same library is affected.

### The shipped library is fine, and the reason is not the one you would guess

Worth stating plainly, because the table above reads like a vulnerability report
and is not one. Nothing here says Monocypher leaks.

The strong version of that is a diff rather than a reading. Build `monocypher.c`
as shipped, build it again with `volatile` deleted from both `fe_ccopy` and
`fe_cswap`, and compare four entries:

| entry | shipped | mitigation deleted |
|---|---|---|
| `crypto_x25519` | 5101 insns, 5 br | 5220 insns, 5 br |
| `crypto_elligator_map` | 4143 insns, 3 br | 4121 insns, 3 br |
| `crypto_eddsa_sign` | 13468 insns, 51 br | 13473 insns, 51 br |
| `crypto_x25519_dirty_small` | 5146 insns, 6 br | 5265 insns, 6 br |

Taking the mitigation away changes no branch count anywhere, `crypto_elligator_map`
and `crypto_eddsa_sign` included, and those are the two entries whose conditions
come from comparisons. So at -O2 on this clang the library is not relying on
`volatile`. The trigger does not fire, because `fe_isequal` stays out of line and
what reaches the copy is a returned `int`.

Which is a worse reason to be safe than having a mitigation, because it is one
inlining decision wide. Force `fe_isequal` inline and nothing else:

| `invsqrt`, `fe_isequal` inlined | unrolled | rolled |
|---|---|---|
| `volatile` | 3 branches | 3 branches |
| no `volatile` | **13 branches** | **13 branches** |

Three branches is the loop back-edges and is the clean answer. Thirteen is those
three plus ten the compiler put on the secret, in Monocypher's own `invsqrt`, with
no edit to it beyond the mitigation. So `volatile` is load bearing in the real
library; it is simply not being exercised at this optimization level.

Those two results have to be read together or the first one is dangerous. On its
own, "deleting the mitigation changes nothing" reads as "the mitigation is
unnecessary", which is advice someone might act on, and the matrix underneath it is
the only thing that says otherwise.

`always_inline` is a construction too, and saying so is the point rather than a
hedge. What makes it a better construction than writing the comparison inline is an
asymmetry worth one sentence. Writing the comparison out by hand is a change to the
source that nobody would make, so it produces a shape the library does not have.
Inlining a small leaf function is a decision this compiler already makes everywhere
else and declines here for reasons that have nothing to do with security, so it
produces a shape the library has not been given yet. Neither is what ships. Only one
of them is a plausible next build.

That is the comment doing its job. It says the mitigations "may help delay the day
compilers grow clever enough to defeat it", and one inlining decision is that day.
What the four objects add is which of the two would survive it.

One claim here carries no caveat, and it is the one worth keeping. Unrolling is
inert in every configuration measured: with `volatile` and without it, in the
fixture and in `invsqrt`, at both -O2 shapes. clang unrolls the loop whether or not
the source does, so the written-out version never reaches the object, and `volatile`
is doing all of the work in every cell where any work was needed.

### What it costs to land

A source file and a build line. `ccopy.c` is four functions and a macro, `build`
runs clang once and then `opt -passes='internalize,globaldce'` once per entry, and
what comes out is four objects with one function apiece that the tower enters at
pc 0 like every other fixture.

That matters more than the size does. The earlier plan for the `fe_tobytes` pair
needed a vendored Monocypher checkout and `port.sh`, which is why it was parked;
this needs neither, so what the branch is waiting on is no longer a frontend for
vendoring. It is whatever handles the calls in a multi-function port, which is
what `crypto_poly1305` needs and a leaf never did.

Four single-entry objects rather than one object with four entries, deliberately.
`Common.entryPc` has no override anywhere in the tree, so the first fixture to use
it is the first to find out whether the seam is right; a fixture whose verdicts are
the finding is the wrong place to discover that. Poly1305 is where it gets
exercised, because there it is load bearing rather than a convenience.

### What a leaf port costs now

A driver and an argument layout. `Common.entryPc` defaults to 0, so
`override def entryPc = image.entries("fe_sq")` is the whole of naming a different
entry, and nothing in the tree moves.

That is true as of one fix, and anyone working from an older tree hits the bug it
closed. `retAssert` declared `void ret_assert(bool c)` whenever `prog` held a call
anywhere, which was fine while `prog` was one function. Entering at a leaf inside a
nine-function object declares a helper nothing calls, and a leaf with no branch in
it has no `bool` anywhere in its residue, so nothing pulls in `<stdbool.h>` and the
declaration does not parse. The failure is a CBMC parse error in 0 seconds rather
than a verdict, which is a cell that looks like it ran. `Flow.callsFrom(prog, from)`
keys the declaration on reachability from the entry instead.

## The unwind bound is what stops the whole ladder

`scalarmult` runs 255 times and `GenericKoikaDriver.unwind` is 65. A residue with a
loop in it has a slot cycle, one global `--unwind` has to serve both that cycle and
the `init` loops over `mem`, and there is no per-function bound plumbed through the
drivers or through [`verify`](../src/out/cbmc/verify).

The bound is also the one thing in this tree measured to fail hard. `rec-cache.c`
at `--unwind 70` exhausted 30GB and took the machine down, because the residue held
a nineteen-function mutual recursion cycle and the bound was covering seventy
nested frames of it. The same file completes clean in 63 seconds with
`--unwindset slot_N:10` on the cycle functions and the global left at 70.

A loop is not that shape. Swept on a fixture, one loop at 255 trips, back-edge via
`bne`:

| body | model | unwind | time | peak RSS |
|---|---|---|---|---|
| 18 `addi`, no memory | naive | 80 | 2s | 98 MB |
| | naive | 260 | 12s | 457 MB |
| | naive | 320 | 12s | 456 MB |
| 27 insns, 13 loads and stores | naive | 260 | 18s | 589 MB |
| | cache | 80 | 10s | 293 MB |
| | cache | 260 | 62s | 1455 MB |

Memory grows about linearly in the bound and flattens once the bound passes the
real trip count, and the recursion that killed the machine nests frames where a
loop back-edge stages as a chain of tail calls that unrolls to a straight line.
The two cost curves are measured; that mechanism is read off the two structures.

What kills `crypto_x25519` is the product rather than the bound. The ladder's
back edge spans 496 straight-line instructions and calls `fe_mul` five times,
`fe_sq` four and `fe_mul_small` once, all leaves, so one iteration is 9461
instruction instances:

| `nb_bits` | instruction instances |
|---|---|
| 2 | 18,922 |
| 8 | 75,688 |
| 32 | 302,752 |
| 255 | 2,412,555 |

The 1455 MB cell above is 5400 instances. At 255 trips this is 447 times that, and
turning `nb_bits` down does not rescue it: eight bits is still fourteen times the
fixture. So
`scalarmult` is not a first port at any setting, and the five leaves are, because
none of them has a loop for the bound to cover.

`scalarmult(q, scalar, p, nb_bits)` taking the bit count as an argument is still
worth knowing, since it makes the loop a dial in the sense [`probe.s`](probe-dial.md)
is one. It is the thing to reach for after a leaf has been through and after
somebody has plumbed a per-function bound.

## Why not a bignum modular exponentiation

[`global-history.md`](global-history.md) names one as the code `ghr/` is for, and
it still is. It is not the first port.

BearSSL's `br_i15_modpow` is a complete constant-time modexp in 531 instructions
with no `div` anywhere, because Montgomery multiplication is how BearSSL avoids
one. It builds clean under the recipe above. It also has 35 branches and 24 max
live, against the tree's four, and the measured fanout at seven live branches is
122.9x the no-history model under the bit-per-branch key and 15.6x under `h=4`.
Twenty-four is far past where either of those was measured. A hand-written 16-limb
modexp built the same way reads 42 branches at 42 max live, which is the same
verdict from a second source.

Max live is a static count and
[Twelve branches is not twelve live branches](#twelve-branches-is-not-twelve-live-branches)
is where it fails, so it is worth saying why it is trusted here and was not there.
`fe_ccopy`'s twelve are twelve copies of one body, each executed once, and nothing
reads back what they recorded. A modexp's are a ladder: the same branches run every
trip and later trips consult what earlier ones did, which is the reuse the tower's
key actually charges for. Same number, opposite meaning, and the loop is what
separates them.

`br_i31_modpow` is the same algorithm at 31-bit limbs, 649 instructions, 13 `mul`
and 11 `mulhu` where i15 has 13 and none. That pair is `choose` and `folded`'s
shape, one algorithm and two lowerings, and it is worth running once the branch
count is something the models can answer for.

## Why not OpenSSL

`crypto/bn/bn_exp.c` is 1520 lines calling 79 distinct external `BN_`, `bn_`,
`OPENSSL_` and `ERR_` symbols, with 28 allocation sites and 17 conditional
compilation blocks choosing between C and per-architecture assembly for
`bn_mul_mont`. Those symbols sit in other translation units behind `BN_CTX`, and
`BN_CTX` is a heap allocator. The port would be of a memory manager.

[`fact.md`](fact.md) has the smaller version of the same verdict already:
`openssl-mee` and the Lucky13 fix in `openssl-ssl3/s3_cbc.fact` are the two case
studies with no feature that unblocks them, and `s3_cbc.fact` is stopped by one
`extern void SHA1_Transform`.

The one file in the OpenSSL tree that would port is `crypto/ec/curve25519.c`,
which is vendored ref10 with no `BN_` in it. It is the same algorithm as
Monocypher's with more headers in front of it.

Nothing here is a statement about OpenSSL's branch counts, because no OpenSSL
object was read. What was read is the call graph around the one function worth
reading.

## What is not measured

The four `fe_ccopy` objects are in the tree and `MonoNaiveTests` and its four
siblings are what run them, so those twenty cells are a test rather than a
measurement in a document. `fe_mul` and `fe_tobytes` are two more objects a tower
has run on, out of tree, one run each.

Everything else here is static: instruction counts, branch counts, call
resolution, section counts, opcode screening and `auipc`/`jalr` pairing, each
checked against the rejection sites in `Decode.scala` and `Elf.scala`. No other
object in this document has been loaded through the Scala reader, and no checker
has seen a residue from one. So the three remaining leaves are inference from two
cells plus a screen, and the inference is that zero branches is what those cells
are about rather than 1215 being a safe size.

`crypto_poly1305` has been screened and not run. Zero relocations, one `.text`, no
undefined symbols, 609 instructions over five functions, and five calls between
them reaching three deep through `crypto_poly1305` to `update` to `poly_blocks`.
Whether the multi-function residue path handles that is not something any cell
here answers.

The claim about `fe_cswap` is one compile, not a sweep. Four variants of it
inlined into a ladder-step driver emit no branch, which says the condition's shape
is what keeps it clean on this compiler at this optimization level. A different
clang could fold it tomorrow, which is the possibility Monocypher's comment is
written against and the reason it keeps a mitigation it believes is redundant.

The library audit is static and narrow in the same way. Four entries, one clang,
one optimization level, branch counts off `llvm-objdump` and no checker involved.
It says the mitigation is not exercised at -O2 and becomes load bearing when one
inlining decision changes. It does not sweep optimization levels, clang versions,
LTO, or targets with a conditional move, where a folded `select` lowers to `cmov`
and stays constant-time. That last case is probably why the comment's claim about
unrolling held wherever it was written, and nobody here measured it.

Nothing in this document is a leak in shipped Monocypher. The two objects that
leak are variants built by deleting a word, and they are in the tree as a control
for the two that do not.

The unwind sweep was run on a fixture of 21 instructions and the ladder estimate
scales it by 450, which is a long way outside it. What that supports is a refusal
rather than a budget.

Everything was measured on one machine at one commit, one run each, and no test
checks any of it, so treat them as the shape of a cost rather than as figures to
reproduce.
