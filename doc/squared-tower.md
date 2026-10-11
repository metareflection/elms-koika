# The squared tower

The tree under [`src/out/cbmc/squared`](../src/out/cbmc/squared) is the same demos answered
a different way. A second tower, under
[`src/test/scala/elms/squared`](../src/test/scala/elms/squared), interprets a
program over a pair of states rather than one, so a slot takes both, the two
runs share one copy of the control flow, and the timers are compared on the way
into every slot rather than once at the end. Every verdict there has to match
its twin next door, because the two are answering the same question about the
same program.

That is the squared semantics and nothing more. An expression is evaluated in
both states, and a branch stays a branch only where the two runs provably agree
about which way to go, which is asserted at the point it is needed rather than
left to the timer downstream. The rules underneath are written for a single run
over an abstract value domain, and the pair is what runs them twice.

Which is also why the same source can be *run*. Substitute ordinary `Int`s for
the staged values and the interpreter walks the program instead of writing one
down, and `SquaredRunSuite` does exactly that: every column of
[the table](../README.md#what-each-model-reports), on sampled inputs, in about
twenty seconds with no checker anywhere. A
witnessed leak is a proof and a clean sample is not, which is what `src/out`
and CBMC are for, but a product semantics that only ever existed as C had to be
wrong in C before anyone found out.

What the sharing buys depends on who is holding the bill, and the bill changed
hands when the cache did. Sharing the control flow makes every timer comparison
an assumption as well as a question, so a pair that has already drifted leaves
the search instead of being enumerated and rejected. That is a claim about a
path space, and against the old two-entry cache it was worth five times:
`branchy` at eighteen probes was 30.1s as a product against 149.9s
self-composed.

A set-associative cache moved the cost somewhere the sharing does not reach.
What is expensive now is array theory over subscripts nobody knows, and running
two states doubles the updates in flight while pruning none of them. `branchy`
at the four probes it ships with is 1.43s squared against 1.31s self-composed.
Twice the work, no difference, and if anything the wrong way.

The probe count is a dial now rather than a line of assembly, which is what
[`probe/`](probe-dial.md) is, and turning it says the same thing
louder. CBMC on the two constructions, one through six probes:

| probes | self-composed | squared |
|---|---|---|
| 1 | 0.20s | 0.21s |
| 2 | 0.31s | 0.34s |
| 3 | 0.57s | 0.61s |
| 4 | 1.50s | 1.39s |
| 5 | 5.79s | 7.11s |
| 6 | 17.25s | **25.80s** |

The gap grows with the space the sharing was supposed to prune. So under this
backend the construction does not merely fail to pay off, it loses ground
exactly where its argument was.

So it earns nothing in time here, and costs a little: see
[what each one charges](frama-c.md#three-ways-to-ask-and-what-each-one-charges) for the
per-file numbers. It is kept for the other thing it does. Every clock verdict in
that tree matches its twin next door, which is a second opinion on the same
program from a differently shaped formula, and where the declared verdicts
differ it is the control-flow obligation talking rather than the clock. Under a
symbolic executor the same dial goes the other way, and
[`probe-dial.md`](probe-dial.md) says why that is not the sharing either.

[`src/out/cbmc/lockstep`](../src/out/cbmc/lockstep) is a third answer to five of
them, and a historical one. `Lockstep` built the product by rewriting the
residue after staging, deciding which branches to fuse by whether they happened
to contain a slot call, and it is what the interpreter replaced. It stays
because a second construction of the same product is worth having on the day
they disagree, and it stays out of a default `verify` because they do not: the
same five verdicts, at 1.47s on the `branchy` measurement above, which is the
interpreter's number plus the noise.

`sbt testFull` still regenerates it, so the C never goes stale while nobody is
looking at it. What `--full` adds is a checker's opinion of it, which is the
part that costs something.

The two constructions decide what to assert differently, and that is the
argument for having kept both. `Lockstep` fused a branch when it happened to
contain a slot call, which is a syntactic proxy for "is this control flow".
The interpreter is told instead: `agree` is the rule's author saying the two
runs have to go the same way, and a branch written any other way is data each
run settles for itself. Under `Predictive` the model owns exactly one `agree`,
where a window resolves, which asks whether the two runs' branch came out the
same at the point the model asks it rather than leaving it to the clock
afterwards.

`squared/riscv/static` and `squared/riscv/predictive` are every demo the two
columns next door answer, fourteen each, so the two trees are the same
question asked two ways rather than a sample of it. Between them they show the
other half of what the table claims: the two predictors agree on every
verdict, and `constant_time` still stages into 1401 lines of residue under one
and 2462 under the other, because a branch that resolves taken leaves
`predictive` holding a history `static` never records.

`squared/riscv/forwarding` is thirteen more, everything the store-queue column
answers. It is the first model here that inlines, so it is the first thing to
use the seam the clock comparison rule exists for: while a store window is
open, `call` runs the next instruction where it stands and no slot begins, so
the two runs are not compared until the window closes. You can read that off
the residue. Counting writes to the clock in each emitted function of
`squared/riscv/forwarding/bypass` gives 1, 2, 1, 2, 1, 9, 1; the same count
under `predictive` gives 1, 2, 1, 2, 1, 2, 1. The nine is the window, five
instructions and their cache costs in the slot that opened it.

`nonblocking` and `predictive_nb` finish the set, twenty-eight more, and with
them every model in the table has a squared twin. They are what the
`defer`, `untimed`, `squash` and `finish` seams in `squared/Squared` were put
there for: each one had a comment saying what it would mean and no instance
behind it until a model arrived that lets a load land after the instruction
that issued it.

Widening the guessed set from three demos to thirteen is what found the only
bug the squared tower has had. `Squared.live` takes a slot number and `Exec.step` was
handing it a pc, which are the same number until `Predictive` numbers one pc
into several and then are not. Ten demos never noticed. `shortcircuit` asked
whether slot 14 existed when what it meant was whether the program had a
fourteenth instruction, and fell over rather than answering wrong, which is
the good version of that mistake.

`Squared.agree` compares the two runs' branch conditions and assumes them
equal, which is what makes this tower decide a stronger property than the
column next door decides, and the `balanced` row of
[the table](../README.md#what-each-model-reports) is where the difference
shows. Call that the *static* squared construction, since which way a
conditional goes is settled while it stages. Everything above is one, and the
`static` in `squared/riscv/static` is a different word, a branch predictor
rather than a staging discipline.

`src/out/*/dynamic/riscv` is the dynamic construction, where a conditional is
settled by the runs instead. `DynamicSquared` overrides the one seam `agree`
leaves for it, and a conditional stops having one thing it can do:

```c
if (v_ca) {
  if (v_cb) { p = slot_6(p); }
  else      { p = slot_9(p);  p = slot_10(p); }
} else {
  if (v_cb) { p = slot_11(p); p = slot_12(p); }
  else      { p = slot_4(p); }
}
```

That is `dynamic/riscv/naive/balanced` at its `blt`. Four arms, no dispatch,
and no runtime test of which side anything is, because the pairing is still
erased at staging time. The two arms where the runs disagree walk each run's
tail on its own, and a solo slot reads one half of the pair and compares its
clock against itself:

```c
struct StateT2 * slot_9(struct StateT2 * v232) {
  struct StateT * v233 = v232->a;
  int v234 = v233->timer;
  bool v246 = v234 == v234;
  squared_assert(v246);
```

Nothing below `Squared` knows about any of that. `each` with one run live
evaluates its body once and pairs the result with itself, which is what makes
`v234 == v234` the whole of the clock comparison and leaves an `agree` on that
arm an ordinary conditional. No model underneath needed a line.

Both cells come back `clean`. That is the result the two files exist for. They
agree with `riscv/naive/balanced` and `riscv/cache/balanced`, where the static
squared cells next door read `leak`, so what `balanced` exposes really is the
control-flow obligation and nothing else, and the obligation can be given up.

What giving it up costs is the pruning. On a shared path `squared_assume` cuts
a pair that has already come apart, which is the only thing the squared
construction buys over running the residue twice and comparing at the end. On a
split path there is no pair left to cut and the solver walks both tails, which
is self-composition's path space arriving exactly where the program was already
going to be expensive. That, and the question being open rather than settled,
is why both `verify` scripts hold the subtree back from a default run.

Two models and one demo, so as not to overstate the shape of it. `Predictive`
can split with a window still open, and `Forwarding.close` requires the two
runs' queues to be the same shape, which after a split they are not. Both are
follow-on work, and behind `--full` there is no pressure to rush them.
