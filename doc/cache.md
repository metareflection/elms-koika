# What the cache is

```
L1   2 sets x 2 ways x 2 words   1 cycle
L2   4 sets x 2 ways x 2 words   12 cycles
mem  64 words                    100 cycles
```

Twelve line frames over thirty-two lines of memory, LRU within a set,
write-allocate, write-through at L1 and write-back at L2. That is
[`Geometry.default`](../src/test/scala/elms/common/Geometry.scala), and everything
in it is a knob.

Three tiers rather than two is what `evict` reads. Its counterexample is 420
cycles against 409, and the eleven between them is exactly
`L2.hitCost - L1.hitCost`: one run answers its last probe out of L1 and the
other has to go a level down for it. Under one level that same gap would have
been ninety-nine, indistinguishable from any other miss, and
`Forwarding.forwardCost` would still be colliding with it.

What it replaces was two entries of one word each, fully associative, with no
valid bit and no dirty bit. That was enough to demonstrate a channel, which is
what it was for. It could not state the argument real constant-time code makes,
because every one of those is about lines and about sets.

A lookup table is safe because it fits in a cache line. A model whose line is
one word reports sixteen distinct probes where the hardware has one, so it
cannot tell a table that fits from a table that does not, and the distinction is
the entire claim. Prime+Probe works by filling a set. With two fully associative
entries an attacker evicts the whole cache by touching two addresses, so the
canonical cache attack was not expressible here at all.

## Three knobs, and only one of them costs

Sets are free. The set index is a `Rep`, so `cache_tags(base + set * ways + w)`
is one symbolic subscript into inline storage however many sets there are, which
is what `mem` already was.

Ways are nearly free, and that takes doing. The obvious spelling of a W-way
lookup is a chain of `if`s, which is W+1 arms in the residue and (W+1)^n paths
over n probes. This one compares tags in arithmetic instead:

```scala
// -1 when the two are equal and 0 otherwise, out of a sign bit rather than out
// of a comparison. `d | -d` has its top bit set for every d but zero.
private def eqMask(a: Rep[Int], b: Rep[Int]): Rep[Int] = {
  val d = a ^ b
  ~((d | (unit(0) - d)) >> unit(31))
}
```

At most one way can match, so the matching way number is the `or` of the masked
way indices and whether there was one is the `or` of the masks. W ways is W
expressions and still exactly two arms. The LRU ages and the victim choice go
the same way, off the sign bit of a subtraction.

Staging `2ctr` against a four-way L1 rather than the two-way one says how well
that holds. Seven `else` branches in the residue either way, the same seven, and
557 lines against 489. Double the associativity for fourteen percent of the
width and none of the depth, which is the whole reason the geometry is a
parameter rather than a rewrite.

Levels are what costs, one arm apiece. So a probe forks threefold, into L1, L2
and memory, which is exactly what the two-entry LRU did with head-hit, tail-hit
and miss.

The bill is width rather than depth. `riscv/cache/2ctr` is 489 lines of residue
against 266, and `fact/cache/salsa20` is 19993 against 8410. That much a reader
would predict, and it is not where the interesting cost turned out to be.

## What it costs a checker, and where that cost actually is

The path space did not move. Both models fork threefold per probe, so
`branchy`'s walk is (3^n + 1) / 2 paths either way. What got expensive is each
individual query, and the reason is one line of the old model:

The old cache compared `cache_keys[0]` against `cache_keys[1]`. Constant
subscripts, which a solver treats as two scalars. A set-indexed cache subscripts
every one of its arrays with an expression nobody knows, so every read is a
select over a chain of updates at unknown indices, and the run issues a hundred
or so of those.

Both backends pay it, and they show it differently. CBMC builds one formula and
its cost lands there: `branchy` runs 1.4s at four probes against 38.5s at six,
where the old model did twelve in 6.1s. KLEE pays per path, and inside a
two-minute budget it does not finish even one: 0 completed against 23 partially
completed, which is why those files carry `Reach.LikelyTimeout` again after a
spell without it. Give it the 1200 the budget has since grown to and it does
finish, in 814s. Counting paths is what nobody should guess from: `2ctr` walks
exactly 3 completed paths under both models, the old one and this one, and its
KLEE verdict never moved.

So `branchy` ships four probes where it used to ship twelve. The demo's job is
to be the one file in the tree whose cost is the solver, and it still is; the
count was always a dial and the dial moved.

Nothing without a symbolic address in it noticed, which is the other half of the
same sentence. `salsa20` is 277 instructions of literal indices, so every set
index folds at staging time and no subscript is ever unknown. It went from 5.4s
to 9.0s, a residue 2.4x wider and a solver doing the work it always did.

## Where a store stops

L1 is write-through and L2 is write-back, which is a real design and is also the
only one that keeps the model honest about ordering. A dirty line has to be
written back when it is evicted, and a write-back from level i mutates level i+1
in the middle of an access that has already read level i+1's tags. Nothing above
the bottom is ever dirty, so that never happens.

The alternative worth naming is the one that looks cheapest and is wrong.
Write-back at L1 with the eviction going straight to memory leaves L2 holding a
stale copy of a line L1 has already superseded, and the next L1 miss reads it.

Valid bits retire a bug the old model shipped. It keyed on the address and left
`-1` in the key to mean nothing-here, so the first two misses wrote their
evicted line back through `s->mem[-1]`, which given `int regs[32]; int mem[64];`
is register x31. It was invisible because every CBMC run passes
`--no-standard-checks`, which turns off exactly the array-bounds property that
would have caught it. A masked tag comparison cannot match an invalid entry, so
there is nothing to write back and nothing to get wrong.

Dirty bits retire a question rather than a bug. The old `runCache` carried a
`CR-soon` worrying that a speculative instruction which evicts an entry writes
back too early. A clean line writes nothing, so there is nothing to undo, and a
dirty line was dirtied by a committed store: `Isa.speculable` refuses a store
outright and `Forwarding` holds one in its queue until `close`. So a write-back
is always a write-back of committed data, and when it happens is not
architecturally observable. The cache's own state is another matter, and
deliberately so, since that is the channel.
