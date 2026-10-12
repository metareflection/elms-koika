# The predictor as a bounded register

The slot key is where the staging boundary falls. Whatever goes in it is
partially evaluated and whatever stays in `State` is residual, and the two
together are what the end-to-end system accounts for. A cache index is
data-dependent, so [`Cached`](../src/test/scala/elms/common/Tower.scala) has
never had a choice about which side it sits on. A branch predictor does.

Every column of the README's table puts it in the key.
[`common/Predictive.scala`](../src/test/scala/elms/common/Predictive.scala)
keys a slot on a map of one bit per branch pc, so the predictor in the
generated C is which function you are in. That is not the predictor going
missing. The functions one pc is numbered into **are** its state, written as
control flow rather than as a table, and a program whose seven live branches
put 6144 slots in the residue is carrying every bit a table would have held.

`ghr/` moves the same state across that line: `historyBits` of history stay in
the key and the rest becomes an array in the struct beside the cache, where a
checker reads it. It is behind `--full` for `dynamic/`'s reason rather than for
cost, because it asks a question about where the boundary should fall rather
than giving a second opinion about a program.

So the two are one model at two settings of one dial, and the crossover below
is the setting at which specializing over the predictor stops paying for
itself.

## Why the table is not computed on it

Because it is more expensive on every demo in the tree. Slots emitted, against
the bit-per-branch model, at four register widths:

| demo | a bit per branch | h=1 | h=2 | h=3 | h=4 |
|---|---|---|---|---|---|
| `hidden` | 226 | 226 | 226 | 226 | 226 |
| `shortcircuit` | 27 | 27 | 27 | 27 | 27 |
| `constant_time` | 26 | 26 | 26 | 26 | 26 |
| `branchy` | 23 | 23 | 23 | 23 | 23 |
| `bypass_late` | 11 | 14 | 14 | 14 | 14 |
| `reload` | 11 | 19 | 19 | 19 | 19 |
| `balanced` | 9 | 11 | 11 | 11 | 11 |
| `spectre` | 9 | 15 | 15 | 15 | 15 |
| `2ctr` | 5 | 10 | 10 | 10 | 10 |

Seven tie and five lose, up to twofold, and no width wins anywhere. The counts
are flat across widths because these demos have at most two branches, so the
register never fills.

Reading those numbers as overhead is the mistake the dial framing avoids. Both
columns represent the same predictor; the left one spends functions on it and
the right one spends an array plus a fork per branch. On this tree the
functions are cheaper.

## What it is for

The crossover is at as many live branches as the register has bits. Nothing in
this tree has more than four, which is why every cell above is on the losing
side of it. `HistoryFanoutSuite`'s `loop-same` family is the other side, where
every branch in a loop stays live:

| live branches | a bit per branch | h=4 |
|---|---|---|
| 1 | 2.6x | 8.6x |
| 4 | 16.5x | 13.8x |
| 5 | 32.0x | 14.6x |
| 7 | **122.9x** | **15.6x** |

Multiples of what the same program costs with no history at all. The
bit-per-branch key doubles per live branch and the register converges on
sixteen, which is two to the fourth. At seven branches that is 6144 slots
against 779.

A bignum modular exponentiation compiled for RV32IM has fifteen live branches.
Two to the fifteenth is 32768, and 198 instructions at that multiplier is not a
residue anybody stages. That is the code this is for, and the tree has not
reached it yet: the reader refuses the object, because clang leaves
`R_RISCV_CALL_PLT` on the calls between its helpers and a target the linker
still owes is one the reader cannot compute.

## Where the two models disagree

`retrain.s` trains a branch on the secret and reads it back two branches later.
`riscv/predictive/retrain` is a leak. Every width in `ghr/` reports it clean.

The reason is not that the secret shifted out of a four-bit window. It is that
the secret makes the two runs' registers diverge, and a divergent register is a
divergent table index, so the two runs read different entries, both cold, and
the channel is gone.

`retrain_far.s` is the same program with five public branches in between, and
it leaks at every width. Those branches all resolve not-taken, so they shift
zeros in until the register is back at the value the first call was staged
under, and the second call re-selects the entry the first one trained. Distance
is not what decides it, which is why both objects are in the tree.

Neither model is wrong about its own machine. A machine with a four-bit global
history really is constant-time on `retrain`. What the register cannot do is
answer for one that reaches further back, and that is the whole of what
bounding it costs.

## Two choices worth knowing about

The table does not alias. Real hardware hashes, usually `pc ^ history`, and
this numbers the branches instead so the index is a concatenation and injective.
gshare was what it did first, and it collided on the first fifty-instruction
program it was pointed at: pc 14 under history 7 and pc 8 under history 1 both
want entry 9. An entry two branches share is one where the second destroys what
the first learned, so a secret stops being visible and the residue comes out
clean having lost a channel rather than gained one.
[`Predictive`](../src/test/scala/elms/common/Predictive.scala) gives the same
reason for keeping its own branches apart.

The guess is a `Rep`, so both continuations of every branch are staged where
the specialized model staged one. They are not two paths forever: given the
branch's real outcome both arms end at the same pc under the same history, so
the fork closes at the resolution point. CBMC joins it and agrees with the
specialized model on all eight demos at 1.0 to 1.2 times the time. KLEE forks
and does not merge, and paid 1.4 times on the three it was tried on.

Those timings were measured on one machine at one commit and no test checks
them, so treat them as the shape of a cost rather than as figures to reproduce.
