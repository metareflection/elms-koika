# The FaCT suite

[FaCT](https://github.com/PLSysSec/FaCT) is a DSL whose type system rejects
programs that branch on a secret or index memory with one, whose Z3-backed
checker rejects programs it cannot prove stay in bounds, and whose compiler
emits a branchless selection in place of the branch you would have written.
[`src/test/fact`](../src/test/fact) holds eleven programs it accepts, lowered
into twelve objects. Nine of them come from FaCT's own repositories:
`example.fact`, which is what the compiler ships to show what it does, and
eight out of [fact-eval](https://github.com/PLSysSec/fact-eval), the case
studies published alongside the paper. The other two are written here. Nine of
the twelve objects verify clean under every model and three do not, and which
is which is not a property of FaCT's type system.

We do not build the FaCT frontend to run it. What is checked in is the LLVM that
`factc` emitted, and

`./src/test/fact/build`

lowers it to RV32IM with stock `opt`, `llc` and `clang`. Two scripts put the
`.ll` there and no test run needs either. `./src/test/fact/factc` compiles the
`.fact` sources beside it, under `podman` from the image FaCT's authors
published; `./src/test/fact/extract` pulls one `define` out of a fact-eval
module into a file of its own, and clones fact-eval the first time it is asked
for one.

`factc --eval <module>` is where the two meet. The `.ll` fact-eval ships was
built without `-no-inline-asm`, so every selection in it is an x86 `cmovnz`
that `llc` for riscv32 will not take; `--eval` rebuilds the module in place
with the flag on, and `extract` then reads the result and says in the file's
header which of the two it got.

## Salsa20

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

Thirty-eight of those 277 instructions are stores, more than twice what any
other file here has, which makes this the one that really exercises
`forwarding` and the reason that model is a column rather than a rewrite: it
stages, and it still verifies.

Being multi-function is not what stops the rest of the case studies. A direct
call to a `static` callee leaves no relocation on its `auipc`/`jalr` pair, so
the reader computes the target and the tower walks in on a staging-time return
stack.

What stops them was measured rather than argued. Marking every non-entry
`define` `alwaysinline` collapses curve25519-donna to one function and
`crypto_secretbox` to two, which leaves 9957 and 5997 IR instructions against
the 462 of the salsa20 already ported, and that one already needed `-Xss`
raised. That is the whole of what is left. RV32M used to sit under it and no
longer does: the tower decodes `mul`, `mulh`, `mulhsu` and `mulhu`, and
`fscalar_product` is ported below.

`openssl-mee` and the Lucky13 fix in `openssl-ssl3/s3_cbc.fact` are the two
with no feature that unblocks them. `s3_cbc.fact` opens by declaring `extern
void SHA1_Transform`, and a symbol outside the object is a target no `auipc`
inside it computed.

## The case-study leaves

Seven leaf functions out of the two case studies, one `define` apiece, which is
what `extract` exists for. Not one of them calls anything, so not one of them
needs the inlining the paragraph above puts out of reach, and `build` globs
`*.ll` so nothing else had to change either.

| function | module | what it is | CBMC, naive through forwarding |
|---|---|---|---|
| `hsalsa20` | crypto_secretbox | the HSalsa20 core | 4.9s, 6.5s, 6.6s, 7.6s, 7.7s |
| `salsa_keysetup` | crypto_secretbox | key expansion | 0.2s, 1.9s, 1.9s, 1.9s, 2.0s |
| `poly1305_init` | crypto_secretbox | the MAC's `r` clamping | 0.2s, 1.2s, 1.2s, 1.2s, 1.3s |
| `crypto_verify_16` | crypto_secretbox | the 16-byte compare | 0.6s, 1.1s, 1.2s, 1.3s, 1.3s |
| `fsum` | curve25519-donna | field addition | 0.2s, 1.1s, 1.1s, 1.1s, 1.2s |
| `fdifference_backwards` | curve25519-donna | field subtraction | 0.3s, 1.2s, 1.2s, 1.2s, 1.4s |
| `swap_conditional` | curve25519-donna | the ladder's swap | 0.5s, 1.5s, 1.5s, 1.8s, 1.9s |

All 35 cells are clean, CBMC certifies every one of them at unwind 65, and Eva
agrees on the set in 76 seconds. That is the expected result and it is the
reason to run them: these are primitives whose authors built a type system to
keep them from leaking, and the question the tower asks is whether the
guarantee survives a microarchitecture that type system never modelled.
`guarded` below is that answer coming back no. These seven are it coming back
yes, which means something only because both were asked the same way.

Sizes and taint are read off each function's FaCT signature rather than off its
body, and each `Program` entry quotes the signature it used. The signature is
the only thing that says which argument the author meant to be secret, and two
of these would have been got wrong by reading the code: `fsum` and
`fdifference_backwards` take a `mut` first argument that they read before they
write, so it draws as a secret rather than as scratch.

### `crypto_verify_16` and `cmp`

`stdlib.fact` writes the 16-byte compare like this:

```
for (uint32 i from 0 to 16) {
  if (x[i] != y[i]) {
    return false;
  }
}
return true;
```

and [`cmp.c`](../src/test/asm/riscv/cmp.c), which has been in the tree far
longer, writes it like this:

```
for (i = 0; i < n; i++) {
  if (guess[i] != secret[i]) return 0;
}
return 1;
```

`cmp` leaks on `naive`, with neither a cache nor a predictor in the model,
because clang stops the loop at the first mismatch and the trip count is the
secret. FaCT's nineteen instructions run all sixteen iterations whatever the
bytes hold:

```
lbu  a6, 0(a6)
lbu  a7, 0(a7)
xor  a6, a6, a7
snez a6, a6
and  a6, a6, a4
and  a7, a6, a2
xor  a4, a4, a6
xor  a2, a2, a7
```

The `snez` and the two `and`s are where the early return went. The only branch
in the object counts against a 15 that llc put in a register. One algorithm,
two compilers, opposite verdicts, and the difference is the thing FaCT was
built to do.

This port and `swap_conditional` are the two that needed `factc --eval`. Both
select with FaCT's `cmovnz`, so both are unbuildable from the `.ll` fact-eval
ships and both come out of a module rebuilt with `-no-inline-asm`. That is the
same flag `choose` and `folded` turn on below, so the arithmetic selection they
are a story about is the selection in these two as well.

### KLEE answers one cell of five

`fdifference_backwards` is the second port marked `LikelyTimeout` and the only
leaf that carries it. On `naive` KLEE closes it clean in 224 seconds of its
1200. On the other four it dies at the default 2GB cap after 26 seconds with
152 states killed, and at a 16GB cap it spends a whole 720-second run without
closing a path, so what stops it is the search and not the memory.

Nothing about the program says which of those it would be. `fsum` is the same
five limbs through the same five models and settles everywhere in seconds.
`hsalsa20` has four times the residue and a loop in it and settles too. CBMC
answers all five cells in 1.4 seconds or less apiece. So `FactNaiveTests`
carries a `settles` map that puts `Reach.Settles` back on the one cell that
answers, which is `FactCacheTests`'s `widens` pointing the other way.

## `guarded`

[`guarded.fact`](../src/test/fact/guarded.fact) is a guarded table lookup that
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
argument. `spectre.s` fills the same row of [the table](../README.md#what-each-model-reports) with eight
instructions written to leak. This one fills it with a program a published
constant-time compiler signed off on.

What FaCT refuses is worth naming too, since it is what the demo had to be
shaped around. `if (idx < lim)` on a bound the caller passes is what the Spectre
paper's victim function says, and the bounds checker will not have it: `lim` is
arbitrary, `table[idx]` is not provable, and `factc` answers `value could be
#x0000000080000000`. A statically sized table is the only shape that gets
through. Two smaller details are the models' rather than FaCT's, and both are
commented where they sit in the source.

## `choose` and `folded`

[`choose.fact`](../src/test/fact/choose.fact) is FaCT's own example program,
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
[`build`](../src/test/fact/build) stops at `mem2reg` for everything else in the
directory.

## `fscalar_product`

[`fscalar_product.fact`](../src/test/fact/fscalar_product.fact) is `folded` with
no extra pass to blame. It is `donna/curve25519-c64.fact`'s limb-wise multiply
out of fact-eval, built with the same `mem2reg` everything else here gets, and
it leaks under every model:

| naive | cache | static | predictive | forwarding |
|---|---|---|---|---|
| leak, 8.5s | leak, 14.4s | leak, 14.5s | leak, 14.6s | leak, 15.6s |

Eva agrees on all five, in 25 seconds for the set. KLEE does not answer, and
this is the first of the two ports marked `LikelyTimeout`. On `naive`, the
cheapest cell, it spends the whole 1200-second budget and halts on its own
timer with 111 live states, no completed path and no error file: 46434
instructions and 21257 queries in twenty minutes. `folded` is the same leak in
five instructions on one secret bit; here the branch is four deep in a
215-instruction residue and what it tests is a carry out of a 64x64 product
over full symbolic words.

There is no conditional in the source. Every index is a literal, the scalar is
multiplied whatever it holds, and the `.ll` FaCT emits contains no `br`, no
`icmp` and no `select`. `llc` emits four `beq`s anyway:

```
beq  t2, t4, .LBB0_2
sltu t3, t2, t4
.LBB0_2:
```

That is how a 64-bit `sltu` lowers on a 32-bit target. The limbs are `uint64`
and the accumulator is `uint128`, so comparing a carry means comparing a pair
of words, and the branch is on the high half of a secret product. Its two arms
differ by one instruction. `naive` catches it, which is to say no cache and no
speculation were needed, the same sentence `folded` earns one section up.

### What RV32M had to be for

Five `uint64 * uint64` widening multiplies are 22 `mul` and 21 `mulhu` on
ilp32, and the object has no libcall in it. Without the extension every one of
them is `__mulsi3` or `__muldi3`, and a call to a symbol no `auipc` in the
object computed is the dynamic jump [`Decode`](../src/test/scala/elms/riscv/elf/Decode.scala)
refuses, so the port does not load at all.

`mulh`, `mulhsu` and `mulhu` want the top 32 bits of a 64-bit product and ELMS
has no `Rep[Long]` to ask for one, so
[`Multiplier`](../src/test/scala/elms/riscv/Mul.scala) builds them out of four
16-bit partial products and a carry. One trait, mixed into both towers, because
the single-run tower has no test that runs one and two transcriptions would
mean a dropped carry only one of them had. `SquaredRunSuite` runs all four
against a Scala `Long` over a grid of boundary values and 500 random pairs;
dropping the `mid >>> 16` term fails three of the four rows.

`div` and `rem` are the other half of RV32M and are still refused, at the
decoder, with a message that names them. Nothing measured needs a divider, and
its data-dependent latency is a different question from a multiplier's. The
multiplier's own latency is a question this tree does not ask either: `tick`
charges 1 per instruction, `mul` included. Small cores ship variable-latency
multipliers and the latency is itself a published channel, so that is a
modelling choice rather than a neutral default, and it is written down on
`Tower.tick` where a reader goes looking for what an instruction costs.

### The draw bound is part of the claim

`fscalar_product` reads clean if its secrets are drawn from `[0, 20]`, which is
the bound every other FaCT port uses. CBMC proves it in four seconds. The proof
is worth nothing: products of numbers below 21 do not carry, all four
branches go the same way in both runs, and the only path that distinguishes
them was assumed away by `koika_assume`.

So the bound moved to `Int.MaxValue`, every non-negative word, and
`Fill.Secret` carries it per port rather than hardcoding 20 in the driver. The
cost of the wider draw was measured on two of the three backends: CBMC's naive
cell goes from 4.4s to 8.5s, and Eva's five cells together go from 24.4s to
24.7s. KLEE was only run at the wider bound. This is the one place in the tree
where a checker's answer turns on how the inputs were constrained, and it is
worth knowing that `clean` can mean "the interesting path was out of range".
