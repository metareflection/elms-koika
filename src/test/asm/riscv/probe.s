# `branchy.s` with the probe count turned into a dial. One source, six objects:
# `probe1.o` through `probe6.o`, assembled from here with `--defsym PROBES=k`.
#
# `branchy.s` says why a walk at unknown addresses is the one demo in this tree
# whose bill is a path space rather than a formula. What it does not have is a
# way to change the size of that space, because its four probes are written out
# in an `.irp` and a reader who wants five has to edit the assembly. Every claim
# about a checker's asymptotics was therefore a claim about two points somebody
# had measured months apart.
#
# Each probe forks three ways, a hit in L1, a hit in L2 and a trip to memory, so
# k probes are 3^k combinations and k is the only thing that moves. That makes
# this the place to ask which of two constructions scales, which is what
# `probe.scala` next door uses it for.
#
# The shifts are five apart here where `branchy.s` spaces them by eight. Eight
# fits four disjoint six-bit fields in a 32-bit register and does not fit six,
# and a dial whose spacing changes partway up the range is a dial measuring two
# things. Overlapping fields cost a checker nothing: the addresses are still
# unknown, still public, and still provably equal between the runs. `probe4` and
# `riscv/cache/branchy` stage into residues of the same length, which is the
# control that says the spacing is not what this measures.

	.set	MASK, 63		# `mem` is 64 words, so six bits names one

	.macro	probe r, sh
	srli	x6, \r, \sh
	andi	x6, x6, MASK
	slli	x6, x6, 2
	lw	x7, 0(x6)
	xor	x5, x5, x7
	.endm

	.text
	.globl	probe
	.type	probe,@function
probe:
	addi	x5, x0, 0		# acc

	# Read first, so the secret is live in the cache while the walk runs and
	# gets written back when some probe or other displaces it. `branchy.s`
	# is where that is argued.
	lw	x9, SECRET(x0)
	xor	x5, x5, x9

	# `PROBES` arrives from the build script's `--defsym`. `SH` is an
	# assembler variable rather than a macro argument because `.rept` has no
	# index of its own.
	.set	SH, 0
	.rept	PROBES
	probe	x10, SH
	.set	SH, SH + 5
	.endr
