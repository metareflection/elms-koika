# `2ctr`'s channel with somewhere for the miss to hide.
#
# The gadget is the same: prime a line, derive an address from the secret, probe
# it, and the two runs disagree about whether that probe hits. Every model with
# a cache in it sees that. What differs here is what comes after, which is a
# loop long enough that a machine able to run it during the miss has finished
# paying for the miss before it runs out of work.
#
# So this is the one demo in the tree meant to go *clean* one column to the
# right. `cache` reports the full miss penalty because it stops the world for
# it; a machine with non-blocking loads reports the part of it the program could
# not fill, and here that part is nothing. The blameworthy model is the one that
# stalls, and what it is wrong about is the size of the channel rather than its
# existence.
#
# The filler is straight-line rather than a loop, and that is about the checker
# rather than the machine. A loop reuses one slot, so the residue reaches it by
# recursing once per iteration and `--unwind` has to cover the trip count. A
# `.rept` is one slot apiece called once, which costs residue width and leaves
# the bound where every other demo leaves it.
#
# FILL has to outlast a miss on its own, so it is sized against `memCost` rather
# than against anything the secret does.

	.set	FILL, 220

	.text
	.globl	hidden
	.type	hidden,@function
hidden:
	lw	x5, 0(x10)		# the attacker's word, which brings in a line
	lw	x6, SECRET(x0)		# the secret
	andi	x6, x6, 7
	slli	x6, x6, 2
	lw	x7, 0(x6)		# the probe. nothing below reads x7.

	addi	x8, x0, 0		# work that does not wait on any of it
	.rept	FILL
	addi	x8, x8, 1
	.endr
