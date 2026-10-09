# A bounds mask the load reads around, so the index arrives unmasked. Takes
# SECRET, a byte offset, from the caller.
#
# Case 7 of the Spectre-STL litmus set from Haunted (Daniel, Bardin and Rezk,
# NDSS 2021), whose `src/litmus-stl/programs/spectrev4.c` keeps the mask in a
# global `case7_mask` initialized to `UINT32_MAX` and stores the real
# `array_size - 1` into it before masking. A load that reads around that store
# gets the all-ones mask, the `and` masks nothing, and the attacker's index
# walks straight out of the public array.
#
# So the guard here is arithmetic rather than a branch, which is why no model
# left of `forwarding` sees it. There is no misprediction: the `and` is always
# executed and always correct for the mask it was handed, and the only thing
# wrong is which mask that was.
#
# `a0` is drawn up to `4 * secret_offset`, which is byte 80, which is the first
# secret word exactly. Masked by 28 the index reaches eight words of public
# array and no further; unmasked it reaches that one secret word, and one word
# is all a channel needs. That boundary is the tree's and not this demo's:
# `RiscVShell.initialize_input` draws to it so a demo can be written against it.
#
# m lives at word 13, whose two low bits differ from word 20's. A load past
# `storeLatency` forwards out of the queue on a `forwardBits` match instead of
# reading memory, and the load that fetches the secret is one of those, so a
# word that agreed there would hand it 28 instead and the gadget would quietly
# stop being one.

	.text
	.globl	stale_mask
	.type	stale_mask,@function
stale_mask:
	addi	x5, x0, -1		# the mask that masks nothing
	sw	x5, 52(x0)		# m = ~0. setup, and it commits.
	addi	x7, x0, 28		# the real mask: eight words of public array
	sw	x7, 52(x0)		# m = 28. queued, not committed.
	lw	x8, 52(x0)		# read around the queue, so m is still ~0
	and	x9, x10, x8		# the attacker's index, unmasked
	lw	x11, 0(x9)		# a0 of 80 is the first secret word
	lw	x12, 0(x11)		# secret-dependent address, the channel
