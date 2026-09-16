# A store to an address nobody knows, in a loop, which is the shape the
# one-entry queue has the least to say about. Takes SECRET and SIZE, both byte
# counts, from the caller.
#
# Nothing here is a gadget. It exists because `bypass.s` stores to an address
# the attacker picks once, and that is not the same as storing through an index
# that moves: the window opens at the same pc on every trip, the address is a
# different `Rep` each time in the machine and the same one in the residue, and
# the instruction after the store reads back through the same unknown index.
#
# What it pins down is two things. The queue costs nothing structural: the window
# closes at the backward jump because no control flow is `speculable`, so the
# loop is still one slot per pc and the residue does not grow with the trip
# count. A store in a loop that inlined its window past the jump would not
# terminate, which is the failure this demo would show as a hang.
#
# And it is the only demo where a store window opens with a branch window's
# saved registers still on the list. `bge` speculates the `add` and the `lw`
# before the store closes it, so x8 and x5 are saved, and the store window has
# to start its own list rather than inherit theirs: a squash here that restored
# x8 would undo a register the branch got right. `Forwarding.closing` is where
# that handoff happens and this is what exercises it.
#
# The value stored is the secret, so the load behind it reads around the queue
# and gets whatever the last trip left rather than what this trip wrote.

	.text
	.globl	dynstore
	.type	dynstore,@function
dynstore:
	addi	x6, x0, 0		# i, in bytes
	addi	x7, x0, SIZE		# limit, in bytes
	addi	x9, x0, SECRET		# where the secret lives
loop:
	bge	x6, x7, done
	add	x8, x9, x6		# the secret's word for this trip
	lw	x5, 0(x8)		# read it
	sw	x5, 0(x6)		# and write it low down, at a moving index
	lw	x11, 0(x6)		# read around the queue
	addi	x6, x6, 4
	j	loop
done:
