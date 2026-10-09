# A secret-dependent branch whose two arms cost the same. Takes SECRET, a byte
# offset, from the caller.
#
# Both arms are two instructions and neither touches memory, so on a machine
# that does not speculate the two runs' clocks come back together and the
# program is constant-time by the observable this tree measures. `naive`,
# `cache` and `nonblocking` are clean for that reason.
#
# `static`, `predictive` and `forwarding` are not, and that is the demo's own
# claim rather than a quirk. The branch is cold in both runs, so both guess
# not-taken; whichever run takes it pays the misprediction and the other does
# not, and the penalty lands on one clock only. A balanced branch is
# constant-time on a machine with no history bits and is not on one with them.
#
# `predictive_nb` is clean, and that is the fourth column with a predictor in
# it saying the penalty is real and unobservable here. `lw x16` is still on its
# way when the branch resolves, so the fifteen is spent inside the shadow of a
# hundred-cycle miss and in-order retirement floors both runs at the cycle the
# load lands on. Lengthen the arms past the miss and the row should come back.
#
# It used to read leak there, for a reason that was neither the penalty nor the
# miss: a squash cleared every register's readiness rather than the window's,
# so the mispredicting run forgot the load it had issued before the branch and
# finished at 22 against the other's 102. In-order retirement cannot do that.
#
# It is here for a second reason, which is what it does to the squared tower.
# `Squared.agree` asserts that the two runs take each conditional the same way,
# so a squared twin of the four clean columns cannot come back clean whatever
# the arms cost. All seven twins are written and all seven read leak. Neither
# answer is a bug: self-composition decides whether the two clocks can differ,
# and the squared tower decides that and whether the control flow can, and this
# is the first program here that separates the two.
#
# The accumulator is x18 and the secret lands in x16, for the reason
# `constant_time.s` gives: `initialize_input` writes the attacker-controlled
# value into regs[10], and reusing that register as scratch would read as
# though it mattered here.

	.text
	.globl	balanced
	.type	balanced,@function
balanced:
	addi	x12, x0, SECRET		# the secret base, and it is public
	lw	x16, 0(x12)		# a secret word, drawn in [0, 20]
	addi	x17, x0, 10		# the midpoint of that range
	blt	x16, x17, low		# the secret-dependent branch
	addi	x18, x0, 1
	j	done
low:
	addi	x18, x0, 2
	j	done
done:
