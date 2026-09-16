# SPECULATIVE STORE BYPASS. Takes SECRET, a byte offset, from the caller.
#
# A store scrubs a secret word and the load right behind it reads the word
# anyway, because the store is still sitting in the queue and the
# disambiguation predictor guessed the two addresses do not alias. What comes
# back is the secret rather than the zero, and the next instruction turns it
# into an address. The rollback puts the registers back. The cache keeps what it
# learned, which is what the timing assertion reads.
#
# Only `forwarding` sees this. Every model to its left commits the store where
# it stands, so the load reads the zero and the channel address is 0 in both
# runs. That is also why this is a row of its own rather than a second way to
# fill in `spectre`'s: nothing here is a mispredicted branch, and there is no
# branch in the program at all.
#
# The address is computed rather than a literal on purpose. A store to a
# constant slot would leave the store's address and the load's as one expression
# that CSE collapses, which exercises the queue without ever asking whether an
# address the generator does not know can travel through it.
#
# `andi` by 28 picks one of eight words, `SECRET` is where `initialize_secret`
# starts writing, and the secret words themselves are drawn up to 20, so
# `slli` by 2 lands the channel address inside `mem` the same way `spectre.s`
# does.

	.text
	.globl	bypass
	.type	bypass,@function
bypass:
	andi	x6, x10, 28		# the attacker picks which word
	addi	x6, x6, SECRET		# p = &secret[(a0 >> 2) & 7]
	addi	x7, x0, 0		# the sanitizer
	sw	x7, 0(x6)		# scrub it. queued, not committed.
	lw	x11, 0(x6)		# read around the queue, so this is the secret
	slli	x11, x11, 2		# mem is word-indexed, so scale
	lw	x12, 0(x11)		# secret-dependent address, the channel
