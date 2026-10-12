# The predictor's history crossing a `ret`, with its cold start cancelled out.
# Takes SECRET, a byte offset, from the caller.
#
# Two callees and four calls. `trainer` branches on `x16 < 10` and `anti`
# branches on `x16 >= 10`, so on the secret they answer opposite ways, and a
# cold predictor guessing not-taken is wrong at exactly one of them whichever
# the secret is. That is fifteen cycles on both runs' clocks and the first half
# of the program is constant-time by construction. `balanced.s` is the same
# trick with one branch; it is here twice so that the penalty cancels instead
# of landing on one run.
#
# What the first half leaves behind is a history, and it is the secret:
# `trainer`'s bit says `x16 < 10` and `anti`'s says the opposite. The second
# half calls both again with a public 20, where `trainer` is not taken and
# `anti` is. A model that carries the history out of a `ret` guesses both from
# what the secret wrote and is wrong at both of them exactly when the secret
# was low, so one run pays thirty and the other nothing.
#
# So the verdict says which model it is run on, and the demo exists for the
# line between those:
#
#   naive, cache, nonblocking   clean, because nothing here predicts
#   static                      clean, because it has no history to carry
#   predictive, forwarding      leak, and the leak is the history alone
#
# A tower that emits one function per callee and returns from it has nowhere to
# put that history, since a shared function has one exit and what it learned
# there depends on the path. Such a tower reports clean in the last row, and
# that is the whole reason this object is in the tree.
#
# Both arms of both branches are `addi` then `j`, so neither branch costs its
# two outcomes differently and the four clean columns are about the predictor
# rather than about the arms. x18 and x19 are the accumulators, apart from
# regs[10] for the reason `constant_time.s` gives.

	.text
	.globl	retrain
	.type	retrain,@function
retrain:
	addi	x12, x0, SECRET		# the secret base, and it is public
	lw	x16, 0(x12)		# a secret word, drawn in [0, 20]
	call	trainer			# cold: wrong iff the secret is low
	call	anti			# cold: wrong iff the secret is high
	addi	x16, x0, 20		# public, and not taken by `trainer`
	call	trainer			# wrong iff the secret trained it taken
	call	anti			# wrong iff the secret trained it not
	ret

	.type	trainer,@function
trainer:
	addi	x17, x0, 10
	blt	x16, x17, t_low
	addi	x18, x0, 1
	j	t_done
t_low:
	addi	x18, x0, 2
	j	t_done
t_done:
	ret

	.type	anti,@function
anti:
	addi	x17, x0, 10
	bge	x16, x17, a_high
	addi	x19, x0, 1
	j	a_done
a_high:
	addi	x19, x0, 2
	j	a_done
a_done:
	ret
