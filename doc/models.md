# Reading the table

Seven models against every demo, one verdict per cell, and
[the table itself](../README.md#what-each-model-reports) is in the README. What
follows is what each row is for and where the chain of models stops being a
chain.

`evict` is the row the geometry was for, and it is a stronger statement than
`2ctr` next to it. `2ctr` needs a cache of some kind. `evict` needs a cache with
*sets* in it: the secret picks which set gets a line installed, so the channel
is a conflict rather than an address. The program has no branch in it and reads
around no store, which is why `static`, `predictive` and `forwarding` are
copies of the `cache` answer. The last two columns are not, and
[`non-blocking.md`](non-blocking.md) is about why.

That a cache without sets answers clean here is a claim about what a model
cannot see, so it is a test rather than a sentence.
[`RiscVFlatTests`](../src/test/scala/elms/riscv/flat.scala) is the same `Cached`
at one set of two ways over one-word lines, which is the shape this tower
carried before, and `src/out/*/riscv/flat` is two files: `evict` clean, and
`2ctr` still leaking so that the control is not merely a model too weak to
report anything.

Reading across the first five columns is the tower. No model there loses a leak
the one to its left could see, and `2ctr` and `spectre` are where it starts
seeing more: `2ctr` needs a cache before the second load's address can cost
anything, and `spectre` needs speculation before that load happens at all.
`guarded` is `spectre`'s row written again and `folded` is `shortcircuit`'s, and
[`fact.md`](fact.md) is why either was worth a demo of its own.

`static` is the one place in that chain where inheritance runs against
capability. It is `Predictive` with the history taken away, overriding `learn`
to record nothing, so every branch gets the cold-start guess of not-taken and
goes on getting it. That is what a machine with no history bits does, and it is
why the column is worth keeping next to `predictive`: a leak in it did not need
a predictor to be trained, which is a claim about the threat model rather than
about the predictor. No demo tells the two apart by verdict. Fourteen of them do
stage differently, because a branch that resolves taken leaves `predictive`
holding a history `static` never records, and the two then number the
instructions after it into different slots. Eight are in the main suite,
`shortcircuit`, `constant_time`, `reload`, `dynstore`, `cmp`, `folded`,
`guarded` and `salsa20`. The rest are the `v` rows, every one of them but
`v08`, which has no conditional branch for a history to be about.

`balanced` is a row about the predictor and nothing else. A secret word decides
a branch whose two arms are the same length, so a machine that does not
speculate runs two instructions either way and the clocks come back together.
Three columns report that. The three with a predictor and a blocking cache do
not: the branch is cold in both runs, so both guess not-taken, and only the run
that takes it pays the fifteen. A balanced branch is a constant-time idiom for
exactly as long as nobody is predicting it.

`predictive_nb` is the fourth column with a predictor and it reads clean, which
is the penalty being real and unobservable rather than absent. The secret the
branch tests arrives by a load that has not landed yet, so the fifteen is spent
inside the shadow of a hundred-cycle miss and in-order retirement floors both
runs at the cycle the load completes. Lengthen the arms past the miss and the
row should come back.

It is in the tree for a second reason, which is what it does to the squared
tower. `Squared.agree` asserts that the two runs take each conditional the same
way, so a squared twin of the three clean cells above cannot come back clean
whatever the arms cost. That twin is written now, and CBMC on one demo out of
each tower says it directly:

```
# src/out/cbmc/riscv/naive/balanced.check.c
[main.assertion.1] line 181 timing leak: SUCCESS

# src/out/cbmc/squared/riscv/naive/balanced.check.c
[main.assertion.1]             line 328 timing leak:           SUCCESS
[squared_assert.assertion.1]   line 308 timer drift:           SUCCESS
[squared_diverged.assertion.1] line 309 control flow diverged: FAILURE
```

Different declared verdicts, `clean` next door and `leak` here, and the
assertion that fails is never the clock. `timer drift` succeeds in all seven
squared columns, the four with a predictor included. Under `static` that is
the sharp version. The self-composed leak there is a real pair of clocks, 106
cycles against 122, and every pair that reaches those two numbers is one that
took the branch two ways, so `squared_assume` has cut it before anything looks
at a timer.

Neither answer is a bug and neither is the other one's approximation.
Self-composition decides whether the two clocks can differ. The squared tower
decides that and whether the control flow can, which together are the classical
constant-time discipline, and this is the first program here that separates the
two. `squared/riscv/naive` is the one squared column holding a single demo,
because one demo is all it takes to say this and `Flat` is the model with the
least left in it to blame. `dynamic/riscv/naive/balanced` is that same demo a
third time, with the control-flow obligation dropped, and it reads `clean`
again.

That sentence stops at the fifth column, and the two after it are each a
different reason why.

`nonblocking` is the one that breaks the shape. It takes rows away. `evict`,
`hidden` and `spectre` all read leak under `cache` or under `static` and clean
under a model that does not stop the world for a miss, and in every one of them
the column to the left is what is wrong: the gap it reports is a stall the
program could have run through.

That is a different kind of column and it should be read as one. A model that
only ever adds channels can only ever be too careful, so its clean verdicts are
cheap to trust. This one can be too permissive, so a clean answer here is a
claim about the machine as well as about the program. What keeps each of those
rows honest is its twin next door. `cache/hidden` still leaks, so
`nonblocking/hidden` going clean cannot be somebody having flattened the
gadget.

`predictive_nb` is the join of the two either side of it, and it exists because
neither alone settles what speculation leaks. It agrees with `nonblocking` on
every row but `reload` and `v20r`, which are `spectre` and `v20` with the probe
an attacker would actually perform, and those two rows are the ones that say the
speculative channel is the cache line rather than the stall.

So the traits are a lattice rather than a line: naive, then cache, then
`static`, `predictive` and `forwarding` in a chain on top of it, with
`nonblocking` a second branch off cache and `predictive_nb` the join. Only the
first five columns are also ordered by what they report.

The seven `v` rows are Spectre v1 variants, ported in
[`src/test/asm/riscv/pht`](../src/test/asm/riscv/pht). Paul Kocher wrote fifteen
of them to show which gadgets each compiler's mitigation missed, and the
[Spectector](https://arxiv.org/abs/1812.08639) authors grew the set to 27 and
used it as their evaluation corpus; six are ported here, and what makes them
worth having is that a compiler emitted them. `v20` is `spectre`'s row cell for cell
and `v20r` is `reload`'s, which is the control the family was ported to get:
the gadget somebody wrote by hand for this tower and the one clang emitted from
Kocher's C answer the same under all seven models. `v20r` is the only file
there that is not one of the 27, because a victim function never probes
anything and the probe is what an observer made of a clock needs. Porting them
is also what found the window rule the tower used to carry. A window ended on a
write to one of the branch condition's own registers, a bounds check compares
the index, and the body's first move is to scale it, so every one of these lost
its whole window to a register name; branch resolution now reads the operands
the branch was staged with.

`v10`, `v21` and `v25` are clean in every column and each is clean for its own
reason. A window here is a straight line of `speculable` instructions, so
control flow between the guard and the gadget ends it first: `v10`'s leak is an
inner branch and a window cannot open inside a window, `v21`'s secret-dependent
address belongs to the loop's second iteration and reaching it means the
backward branch, and `v25` joins the switch's two arms with a `j`. Spectector
calls all three leaks, since its observation is a load's address rather than a
clock and its window is an instruction budget under always-mispredict. The
other two rows need no predictor at all. `v17`'s bounds check reads the array
it is guarding, so `naive` already has it, and `v08`'s is a branchless ternary
whose `x + 1` walks one word past the end, which wants a cache rather than
speculation.

`branchy` is RISC-V only, and it is a walk over four addresses nobody knows and
everybody agrees on. That is the one shape in this tree whose cost is the
solver rather than the elaborator. Every other clean demo is cheap for the wrong
reason, `constant_time` because it has three branches and `salsa20` because it
has none, so neither says anything about a checker that has to rule out a path
space rather than exhibit one member of it.
