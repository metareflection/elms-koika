# SPECULATIVE STORE BYPASS THROUGH A STALE POINTER. Takes SECRET, a byte
# offset, from the caller.
#
# Case 5 of the Spectre-STL litmus set from Haunted (Daniel, Bardin and Rezk,
# NDSS 2021), whose `src/litmus-stl/programs/spectrev4.c` keeps a
# `uint8_t *case5_ptr` aimed at `secretarray` and sanitizes it by storing the
# public array's address over it. A load that reads around that store still
# goes through the old pointer, so the index the attacker chose lands in the
# secret rather than in public data.
#
# What this does that `bypass.s` does not is bypass a sanitizer rather than a
# scrub. `bypass.s` writes a zero over the secret word itself and reads the
# word anyway; here the secret is never touched and what the store was about to
# fix is the address. The queue cannot tell the two apart, which is the claim
# this shape is ported to make.
#
# Two stores, and the first is setup. The original gets `case5_ptr` pointed at
# `secretarray` from the loader, and `init` leaves `mem` zeroed, so somebody has
# to write the stale value in. A store is not `speculable`, so the second store
# is the instruction that closes the first one's window and opens its own in the
# same step, the way `bypass_late.s` does on the way out of a branch window.
# Nothing read around the first store, so it commits and costs a rollback
# nothing.
#
# The attacker's index is folded into the stored pointer rather than added after
# the load, which is the one thing the port cannot keep. `Forwarding.storeWindow`
# is 4 and the chain already needs three loads; an `add` between the first two
# would push the channel past the window and the demo would prove nothing.
#
# p lives at word 9 and not inside the channel's range on purpose. The channel
# reads words 0 to 5, and a load at `storeLatency` or more past the store
# forwards out of the queue on a `forwardBits` match rather than probing the
# cache. Word 9 agrees modulo 4 with words 1 and 5, so two of the six words the
# channel can name take the forwarding arm and the other four take the probe.
# Which arm it was is secret-dependent either way, so the clock moves either way.

	.text
	.globl	stale_ptr
	.type	stale_ptr,@function
stale_ptr:
	andi	x5, x10, 28		# the attacker picks which word
	addi	x6, x5, SECRET		# &secret[i], which is where p starts
	sw	x6, 36(x0)		# p = &secret[i]. setup, and it commits.
	sw	x5, 36(x0)		# p = &public[i]. queued, not committed.
	lw	x8, 36(x0)		# read around the queue, so p is the stale one
	lw	x11, 0(x8)		# and so this is the secret
	lw	x12, 0(x11)		# secret-dependent address, the channel
