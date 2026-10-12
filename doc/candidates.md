# Picking a real-world object to port

The tree's largest port is `salsa20`, 277 instructions and two branches. This is
the screen that was run to find the next one, what it measured, and which
candidate came out of it.

The answer is Monocypher's field arithmetic, entered at `fe_mul`. 1215
instructions, no branch, no call and no loop, and it verifies clean in 4 seconds
under `naive` and 29 seconds and 1.8 GB under `cache`. That is 4.4 times the
largest object in the tree and, under `naive`, faster in absolute terms than the
277-instruction program it replaces. `fe_tobytes` at 666 instructions is clean
too, and the same function with its conditional subtraction written as a branch
leaks on both models, which is what makes the clean cells worth quoting.

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
pc, maximised over pcs. A screen that walks the CFG without following `jalr` only
reaches a callee's branches when the linker happened to lay it next, which is
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

Neither object is in the tree. Both are built by a script and a Monocypher checkout
that are not in the tree either, so landing the pair means vendoring the source or
scripting the build.

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
the dial does not rescue it: eight bits is still fourteen times the fixture. So
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

`fe_mul` and `fe_tobytes` are the two objects here a tower has run on. Everything else is static:
instruction counts, branch counts, call resolution, section counts, opcode
screening and `auipc`/`jalr` pairing, each checked against the rejection sites in
`Decode.scala` and `Elf.scala`. No other object in this document has been loaded
through the Scala reader, and no checker has seen a residue from one.

So the three remaining leaves are inference from two cells plus a screen, and the
inference is that zero branches is what those cells are about rather than 1215
being a safe size.

Both clean verdicts are close to structural, for the reason written out above, and
what makes them mean anything is the broken `fe_tobytes` beside them rather than
either cell alone. That pair is three cells and one source edit, on two objects
neither of which is in the tree.

The unwind sweep was run on a fixture of 21 instructions and the ladder estimate
scales it by 450, which is a long way outside it. What that supports is a refusal
rather than a budget.

Everything was measured on one machine at one commit, one run each, and no test
checks any of it, so treat them as the shape of a cost rather than as figures to
reproduce.
