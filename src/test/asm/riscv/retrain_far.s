# `retrain.s` with the two halves pushed apart, which is the limit of a bounded
# history written down as a program.
#
# The first half is `retrain.s` unchanged: `trainer` and `anti` answer opposite
# ways on the secret, a cold predictor is wrong at exactly one of them, and the
# fifteen cycles land on both runs. What it leaves behind is a history that is
# the secret.
#
# Then five public branches run, and only then does the second half read what
# the first half wrote. A predictor that keeps a bit per branch still has it:
# `trainer`'s own entry was not touched by anything in between, so the leak is
# the one `retrain.s` reports. A predictor whose history is a shift register of
# the last four outcomes does not: the register the second half indexes with
# has none of the secret left in it, the entry it reaches was never trained,
# and both runs guess cold and agree.
#
# So the two models disagree here, and neither is wrong about its own machine.
# The bounded one is right about a machine with four history bits and the
# program really is constant-time on one. What it cannot do is answer for a
# machine with more, and that is the whole of what boundedness costs: a leak
# this reports clean is a leak on any machine whose predictor reaches further
# back than the model's.
#
# Both arms of every branch here are `addi` then `j`, so nothing in it leaks
# for want of balance and the four columns with no predictor read clean.

	.text
	.globl	retrain_far
	.type	retrain_far,@function
retrain_far:
	addi	x12, x0, SECRET		# the secret base, and it is public
	lw	x16, 0(x12)		# a secret word, drawn in [0, 20]
	call	trainer			# cold: wrong iff the secret is low
	call	anti			# cold: wrong iff the secret is high
	addi	x16, x0, 20		# public from here on
	addi	x17, x0, 10
	blt	x16, x17, p1_low	# public, and it shifts the register
	addi	x18, x0, 1
	j	p1_done
p1_low:
	addi	x18, x0, 2
	j	p1_done
p1_done:
	addi	x17, x0, 10
	blt	x16, x17, p2_low	# public, and it shifts the register
	addi	x18, x0, 1
	j	p2_done
p2_low:
	addi	x18, x0, 2
	j	p2_done
p2_done:
	addi	x17, x0, 10
	blt	x16, x17, p3_low	# public, and it shifts the register
	addi	x18, x0, 1
	j	p3_done
p3_low:
	addi	x18, x0, 2
	j	p3_done
p3_done:
	addi	x17, x0, 10
	blt	x16, x17, p4_low	# public, and it shifts the register
	addi	x18, x0, 1
	j	p4_done
p4_low:
	addi	x18, x0, 2
	j	p4_done
p4_done:
	addi	x17, x0, 10
	blt	x16, x17, p5_low	# public, and it shifts the register
	addi	x18, x0, 1
	j	p5_done
p5_low:
	addi	x18, x0, 2
	j	p5_done
p5_done:
	call	trainer			# four bits on, the secret is gone
	call	anti
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
