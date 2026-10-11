# Checking with CBMC

`src/out/cbmc` is every residue in the tree checked by
[CBMC](../README.md#cbmc), and [`src/out/cbmc/verify`](../src/out/cbmc/verify)
is its script. One invocation per file:

`cbmc -DCBMC --verbosity 4 --slice-formula --unwind <N> --refine --compact-trace --no-standard-checks <file.c>`

`--no-standard-checks` leaves CBMC nothing to check but the residue's own
assertions. Without it, it also checks every automatic property it generates,
which on `fact/naive/salsa20.check.c` is 6536 of them: pointer dereference
checks, overflow, array bounds, undefined shift. Those ask about the generated
C rather than about the program it models, and on anything past the
twenty-instruction demos they are the entire cost. That file answers in four and
a half seconds with the flag and had not finished in seventy-two minutes
without. No verdict moves either way.

Naming the one property instead, which is what this used to do, is a hair
slower and no longer correct: a product residue under `squared/` or `lockstep/`
asserts once per slot rather than once at the end, and any of them is the leak.

## The bound

`<N>` comes out of the file. `GenericKoikaDriver.unwind` is
`max(num_regs, mem_size, cache_words, cache_entries, secret_size) + 1`, which is
every loop in the hand-written C around the residue plus the exit test, and a
demo whose own recursion runs deeper than that overrides it. 65 everywhere now
that the demos and the FaCT ports run on the same 64 words of memory, where the
tree used to run everything at 1000 and pay 172 seconds for `compiled/naive`
alone.

Falling short does not make a leak disappear, it invents one. The initializer
loops in `init` are the first thing a low bound cuts, and two states left
half-written disagree on garbage, which is indistinguishable from a real finding
by exit code. So `verify --certify` re-runs every file with
`--unwinding-assertions` and fails on any bound that does not cover what it
claims to.
