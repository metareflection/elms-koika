# The positive control the suite lacks: a branchless comparison that accumulates
# `xor` into an `or` and turns the result into a bit with `sltiu`. Every
# iteration runs, the trip count is public, and no address depends on a secret
# value. Takes SECRET and SIZE, both byte counts, from the caller.
#
# The accumulator is x16 and not x10 on purpose. `initialize_input` writes the
# attacker-controlled value into regs[10], which the two SPECTRE demos do read,
# and reusing it here as scratch would read as though it mattered.
#
# All drivers should pass (no leak). The only conditional branch is the loop
# exit, whose outcome is the public trip count, so Predictive mispredicts in
# both runs at exactly the same place. A failure here is a finding about the
# model rather than about the demo.

	.text
	.globl	constant_time
	.type	constant_time,@function
constant_time:
	addi	x12, x0, 0		# guess base
	addi	x13, x0, SECRET		# secret base
	addi	x14, x0, 0		# i, in bytes
	addi	x15, x0, SIZE		# size, in bytes
	addi	x5, x0, 0		# acc
loop:
	bge	x14, x15, done
	add	x6, x12, x14
	lw	x7, 0(x6)
	add	x8, x13, x14
	lw	x9, 0(x8)
	xor	x16, x7, x9
	or	x5, x5, x16
	addi	x14, x14, 4
	j	loop
done:
	sltiu	x11, x5, 1
