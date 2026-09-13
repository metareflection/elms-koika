# SPECTRE vulnerability. Takes SECRET, a byte offset, from the caller.
#
# Two instructions here that the NanoRisc version does not need, and both are
# the ISA rather than the demo. RV32I has no register-plus-register addressing,
# so the address wants an `add`; and `mem` is word-indexed, so the secret wants
# scaling before it can be used as one. Both sit inside the speculation window,
# which is why `Exec.speculable` admits ALU ops.

	.text
	.globl	spectre
	.type	spectre,@function
spectre:
	addi	x13, x0, 0		# base
	addi	x10, x0, SECRET		# index, out of bounds
	addi	x15, x0, SECRET		# bound
	bge	x10, x15, done		# and it is taken
	add	x5, x13, x10
	lw	x11, 0(x5)		# speculative secret load
	slli	x11, x11, 2
	lw	x12, 0(x11)		# secret-dependent address, the channel
done:
