# The scrub, with the load one instruction behind it. Takes SECRET, a
# byte offset, from the caller.
#
# Case 9bis of the Spectre-STL litmus set from Haunted (Daniel, Bardin and Rezk,
# NDSS 2021), whose `src/litmus-stl/programs/spectrev4.c` zeroes the secret
# element and then spins ten times before reading it back. Ten iterations is not
# enough for the store to retire, so the load reads around it and gets the
# secret. `retired.s` is the same program with two hundred, and the pair is what
# pins the window down.
#
# The filler is a count of instructions here rather than a loop, and it has to
# be. A backward branch is not `speculable`, so a loop between the store and the
# load would close the window at the jump and the distance the demo is about
# would never be reached. `Forwarding.storeWindow` is 4, which is the number
# `retired.s` writes out as four `addi x0, x0, 0`; this file is the same gadget
# with none of them.
#
# Both loads are inside `storeLatency`, so both read around the queue rather
# than forwarding out of it, and neither consults `forwardBits`. That is the
# other half of why there is no scale instruction between them: the channel
# address is the secret's word rather than the secret, coarser than `bypass.s`
# on purpose, so that the only thing moving between this file and `retired.s`
# is the filler.

	.text
	.globl	inflight
	.type	inflight,@function
inflight:
	andi	x6, x10, 28		# the attacker picks which word
	addi	x6, x6, SECRET		# p = &secret[(a0 >> 2) & 7]
	sw	x0, 0(x6)		# scrub it. queued, not committed.
	lw	x11, 0(x6)		# distance 1, so this reads around the queue
	lw	x12, 0(x11)		# secret-dependent address, the channel
