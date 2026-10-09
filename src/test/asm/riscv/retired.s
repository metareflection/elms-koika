# The scrub, with the load far enough behind it that the store has landed.
# Takes SECRET, a byte offset, from the caller.
#
# Case 9 of the Spectre-STL litmus set from Haunted (Daniel, Bardin and Rezk,
# NDSS 2021), whose `src/litmus-stl/programs/spectrev4.c` zeroes the secret
# element and then spins two hundred times before reading it back, which is long
# enough for the store to retire. `inflight.s` is the same program with ten, and
# the pair is what pins the window down: the only thing that differs between the
# two files is how many `addi x0, x0, 0` sit in the middle.
#
# Four of them, which is `Forwarding.storeWindow` exactly. The window covers the
# four instructions after the store, so the load lands at distance 5, by which
# point `close` has committed the store and nothing is left to read around. The
# load gets the zero in both runs and the channel address is 0 whatever the
# secret was.
#
# A nop and not a spare `addi` to an unused register, because the filler must be
# `speculable` and must do nothing. Writes to x0 are discarded at staging time,
# so these cost the window four slots and leave no register for a rollback to
# have to put back.
#
# This answering clean is the claim. It coming back `leak` would not be a bug in
# the demo, it would mean the queue holds a store longer than `storeWindow`
# advertises, and `Forwarding.resolved` is the line to read before touching
# anything here.

	.text
	.globl	retired
	.type	retired,@function
retired:
	andi	x6, x10, 28		# the attacker picks which word
	addi	x6, x6, SECRET		# p = &secret[(a0 >> 2) & 7]
	sw	x0, 0(x6)		# scrub it. queued, not committed.
	addi	x0, x0, 0		# four of these, which is storeWindow
	addi	x0, x0, 0
	addi	x0, x0, 0
	addi	x0, x0, 0
	lw	x11, 0(x6)		# distance 5, so the store landed four back
	lw	x12, 0(x11)		# the zero's address, the same in both runs
