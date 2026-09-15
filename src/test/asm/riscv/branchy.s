# A table walk at public indices. Clean under every model, and the only demo
# here whose cost is the solver rather than the elaborator.
#
# Every other clean demo in this tree is cheap for the wrong reason.
# `constant_time` has three branches and `salsa20` has none, so CBMC answers
# both by building a formula with almost nothing in it to decide. Here every
# probe is a real hit-or-miss question at an address nobody knows, and a
# checker has to rule out every pair of answers rather than exhibit one.
#
# There is no branch in it at all. The secret reaches the accumulator and the
# cache, and never an address, which is the whole claim.
#
# The table is every word of `mem`, the secret's ten included, which is the
# point rather than an oversight. A probe that lands on the secret reads a
# different value in each run and carries it into the cache, so the two runs
# hold different bytes behind the same tags and what has to be shown is that
# the timer never learns which. Keep the probes off the secret and the whole
# thing collapses to a formula about public data.
#
# The indices come out of two registers rather than out of memory, and that is
# load-bearing rather than tidy. `Cached` writes an evicted line back with
# `mem[keys[1]] = vals[1]`, a store at an index nobody knows, so anything left
# in `mem` is a word nothing can prove the two runs still agree on. Put the
# indices there and the addresses stop being provably equal, which is a
# different and much harder question than the one this demo is asking.

	.set	MASK, 31		# `mem` is 32 words, so five bits names one

# One probe, off bits [\sh, \sh+5) of \r. Both the shift and the mask are
# static, so what varies is only which word gets read.
#
# `BranchyDriver` finds the registers to seed by collecting the `srli` operands
# out of the decoded program, so adding one to the list below is the whole edit
# and the two halves cannot fall out of step.
	.macro	probe r, sh
	srli	x6, \r, \sh
	andi	x6, x6, MASK
	slli	x6, x6, 2
	lw	x7, 0(x6)
	xor	x5, x5, x7
	.endm

	.text
	.globl	branchy
	.type	branchy,@function
branchy:
	addi	x5, x0, 0		# acc

	# Read first, so the secret is what the probes are evicting. Its address
	# is a literal either way; what this buys is that its value is live in
	# the cache while the walk runs, and gets written back to memory when
	# some probe or other displaces it.
	lw	x9, SECRET(x0)
	xor	x5, x5, x9

	.irp	r, x10, x11
	.irp	sh, 0, 5, 10, 15, 20, 25
	probe	\r, \sh
	.endr
	.endr
