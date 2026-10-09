# A table of two base addresses and a selector the load reads around, so the
# secret's base is chosen. Takes SECRET, a byte offset, from the caller.
#
# Case 6 of the Spectre-STL litmus set from Haunted (Daniel, Bardin and Rezk,
# NDSS 2021), whose `src/litmus-stl/programs/spectrev4.c` keeps
# `case6_array[2] = {secretarray, publicarray}` and a `case6_idx` starting at 0.
# The gadget stores 1 into the selector and then indexes the table with it, so a
# load that reads around the store picks entry 0 and reads the secret's base.
#
# Neither `init` nor the attacker has to write the stale selector, because 0 is
# what `init` leaves and 0 is already the secret entry. The same zeroing hands
# the public entry over for free: `table[1]` is never written and a null base is
# the bottom of `mem`, which is public. So the only setup store is `table[0]`.
#
# The selector is stored already scaled, 4 rather than 1, because the window is
# four instructions wide and the chain needs all four for loads. A `slli`
# between the selector's load and the table's would push the channel past the
# window.
#
# sel lives at word 14, which agrees modulo 4 with secret words 22 and 26. A
# load past `storeLatency` forwards out of the queue on a `forwardBits` match
# rather than reading memory, and the load that fetches the secret is one of
# those, so two of the attacker's eight choices get the selector's own value
# back instead of a secret. The other six are the demo.

	.text
	.globl	stale_index
	.type	stale_index,@function
stale_index:
	andi	x5, x10, 28		# the attacker picks which word
	addi	x6, x5, SECRET		# &secret[i], the table's secret entry
	sw	x6, 40(x0)		# table[0]. table[1] is the zero `init` left.
	addi	x7, x0, 4		# the public entry, already scaled
	sw	x7, 56(x0)		# sel = 1. queued, not committed.
	lw	x8, 56(x0)		# read around the queue, so sel is still 0
	lw	x9, 40(x8)		# table[sel], which is the secret's base
	lw	x11, 0(x9)		# the secret
	lw	x12, 0(x11)		# secret-dependent address, the channel
