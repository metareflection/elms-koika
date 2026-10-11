# Checking with KLEE

`src/out/klee` is every residue in the tree checked by
[KLEE](../README.md#klee) instead, and
[`src/out/klee/verify`](../src/out/klee/verify) is its script:

`./src/out/klee/verify [--slow | --only-slow] [--corpus] [--full] [file.c ...]`

The two tier flags mean what they mean next door. `--corpus` adds the ported
litmus variants, and this script has a reason of its own for holding those
back: six cells under `stl/forwarding` spend a full budget and produce nothing.
`--full` adds `lockstep/`, `dynamic/` and `probe/`, where a KLEE budget is the
last thing to spend confirming that two constructions of one product still
agree.

Both trees agree, verdict for verdict, model sensitivity included. That
agreement is the point of having two: a residue really is an ordinary C program,
and nothing about the claim depends on which checker reads it.

Only the prelude differs between a pair of snapshots, so

`diff src/out/{cbmc,klee}/riscv/cache/2ctr.check.c`

changes thirteen lines, and so does every one of the other 213 pairs.
`Prover.intrinsics` is that block. The residue, `init` and `main` are one text
spelled in terms of `koika_assert`, `koika_assume`, `koika_draw` and
`koika_secret`, which each backend defines its own way and a file compiled with
none of `-DCBMC`, `-DKLEE` or `-DEVA` stubs out so it can still be run
natively. Adding a third backend was adding a case to
[`Prover`](../src/test/scala/elms/common/Prover.scala), which is
[Frama-C](frama-c.md) below.

What does not carry over is how a verdict is read. CBMC exits 0 or 10; KLEE
exits 0 either way and writes `*.assert.err` into its output directory, so a
verdict there takes three conditions rather than one. Any error file is a leak.
No error file is only clean if the run also finished, which is
`completed paths > 0` with `partially completed paths == 0` and no
`halting execution` on stderr. Drop the last two and an exploration that ran out
of time reports exactly like a proof.

Twenty-one files in the tree are marked for that case, twelve in the main
suite, seven under `lockstep/` and `probe/` and two in the corpus tier, and they
say so where they call `check`:

```scala
check("cache/branchy", snippet, Verdict.Clean, klee = Reach.LikelyTimeout)
```

which writes `clean likely-timeout` onto the line. The verdict is still the
program's, and a run that finishes has to produce it; what `LikelyTimeout` adds
is that running out of budget is also a pass. Demanding the timeout would turn a
faster solver into a failing test, and demanding the verdict asks KLEE for
something it could not give when the label went on, so either outcome is
accepted and a wrong one still is not.

The label means two different things now, and which one a file gets is
measured rather than assumed.

Eleven of the twenty-one are `branchy` with a cache in front of the walk, one per
model that has one and one per squared twin, and every one of them finishes
inside the budget. At 120 seconds `cache/branchy` ends with 0 completed paths
against 23 partially completed, and at ten minutes it ends the same way, which
is where the label came from. At the 1200 the budget has since grown to it
takes 814 seconds, every path completed, clean; the two the squared tower added
last take 958 and 970. So for those eleven `LikelyTimeout` means expensive
rather than unreachable, and it is kept because a quarter of an hour apiece is
not something a default run should spend.

Six of the other ten are `probe/`'s count dial, which has a section of its
own. The four left each have a store queue or a join under them:
`squared/riscv/forwarding/bypass_alias`, `squared/riscv/predictive_nb/reload`,
and `stale_ptr` and `stale_index` under `stl/forwarding`.

Every one of the nine residues in the tree declaring `leak` has been run with
`--exit-on-error`, and five stop at a witness: `bypass_late` at 108 seconds, the
three squared Spectre-STL shapes at 112, 125 and 209, and
`stl/forwarding/stale_mask` at 354. The other four find nothing. `stale_ptr`
and `stale_index` in the single tower stopped on their own `--max-time` at 360,
where `bypass_alias` and `reload` ran past theirs and had to be killed at 400,
which is the same budget on the same box minutes apart and nobody can say what
separates them. That is why `check_one` wraps the call in `timeout -k` as well.

All five that stop have moved to `Settles` and are checked normally. The last
of them was `bypass_late`, whose label lived in `SquaredSuite.scala` and came
off separately; the 1500 seconds that file used to claim for all three of its
rows was the script waiting rather than the search running.

It is the queue and not the size of the residue, which needs saying because the
line counts say the opposite twice over. `squared/stl/static/stale_index` is
2407 lines with the queue taken out from under it and settles in one second,
where `squared/stl/forwarding/stale_ptr` is 3055 and needs 125. Sharper than
that: `stl/forwarding/stale_ptr` is 1545 lines, half its squared twin, and it is
the one that finds nothing at all. The two scrub shapes stay cheap on the same
column, since neither has a forwarded load to disambiguate:
`squared/stl/forwarding/inflight` finds its leak in 123 seconds against
`stl/forwarding/inflight`'s 151, and `retired` is clean in 31 and 18.

None of this is for want of a path space. `runCache` answers out of L1, out of
L2 or out of memory, so four probes are (3^4 + 1) / 2 paths and CBMC is done in
1.4s. What KLEE spends its fourteen minutes on is each individual path, and
`naive/branchy` walks the same four addresses with nothing in front of memory
and verifies in under a second, which is the control that makes this a statement
about the cache rather than about the walk.

The other half of that distinction is what `Reach.budgetSeconds` is for, and it
had to grow from 120 to 1200 with the cache. Five residues started reporting
`unknown` that had been settling in under a second, and none of them was this
case: `fact/static/guarded` finds its leak in 326s and
`riscv/forwarding/bypass` in 485s, so the old budget was turning "not yet" into
a failing test. A budget is a cap and not a cost, so the files that settled
quickly still do, and the only ones that spend most of one are the twenty-one
above.

Each of those costs a full budget or more, so a default run skips them and says
which it skipped:

```
skip     109 under pht/ and stl/ (pass --corpus to check them)
skip     19 under lockstep/, dynamic/ and probe/ (pass --full to check them)
skip     src/out/klee/riscv/cache/branchy.check.c (likely-timeout; pass --slow to run it)
all 195 agree (12 skipped, 128 held back)
```

Those counts are the tree's arithmetic and not a transcript, and they are the
main suite as it stood before the `fscalar_product` port: 207 snapshots, twelve
of them labelled. Every one of the 195 has been checked
on its own, `bypass_late` at 108 seconds among them, and so were the two
labelled files that are not `branchy`: `bypass_alias` and `reload` both found
nothing. What nobody has sat through is all 195 in a single run.

Two more are in the corpus tier, `stale_ptr` and `stale_index` under
`stl/forwarding`, and they are why this script holds that tier back as well as
the one next door. Eleven of the sixty files there have been run: the three
squared Spectre-STL shapes stop at 112, 125 and 209, `stl/forwarding/stale_mask`
at 354, `static/stale_index` is clean in a second, `retired` is clean in 31 and
18, `inflight` leaks in 123 and 151, and the two labelled ones find nothing in
360. Both carry the label on that 360 rather than on the 1200 they declare, so
whether they would settle inside their own budget is open. The other forty-nine
carry `Settles` because CBMC and Eva settle them and nothing in their shape is
what the label is for.

`--slow` adds them back, and `--only-slow` runs nothing else, which is the one
to reach for after touching the squared tower or the cache model.

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
load and it reverses, from 4x behind on a five-path space to 814s against 1.4s
on `riscv/cache/branchy`. Both backends finish every residue in the main suite;
six of them need KLEE to be given twenty minutes. Outside it, the top two
settings of the [probe-count dial](probe-dial.md) are the first files
here CBMC answers and KLEE does not, which is the same cliff with the dial
turned far enough to fall off it.
