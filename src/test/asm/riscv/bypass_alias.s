# FALSE STORE-TO-LOAD FORWARDING. Takes SECRET, a byte offset, from the caller.
#
# The one leak in this tree that the queue's forwarding path is solely
# responsible for, and it needs saying why the others are not. Forwarding out of
# a store to the same address is architecturally transparent: the load gets what
# memory would have given it, so no value anywhere differs and the only thing
# left to observe is the timer. `Forwarding.forwardCost` is 1, which is exactly
# what `Cached`'s LRU tail hit costs, so even the timer cannot tell the two
# apart. Every other leak here is the bypass, not the forward.
#
# What is not transparent is a forward the queue should not have made. It
# compares `forwardBits` low bits of the word index and not the whole thing, so
# a load whose tag matches a store to a different word forwards that store's
# value, which is the wrong one. Words 0 and 24 agree modulo 4. The store holds
# a secret and word 0 holds a public zero, and the load asks for word 0.
#
# So this is the 4K-aliasing shape, scaled to thirty words of memory the way the
# two-entry cache is scaled. A real queue compares a twelve-bit page offset,
# which over an address space is a curiosity and over `mem` would be exact.
#
# Every other model reads word 0 and gets the zero, so the channel address is
# word 0 in both runs and nothing leaks. There is no branch in the program and
# nothing is bypassed: the load sits past `storeLatency`, so the queue has
# decided its address has resolved and answers from the tag.
#
# The secret is a byte count drawn up to 20 and is used unscaled, so the channel
# address is its word rather than itself. Coarser than `bypass.s` on purpose:
# dropping the `slli` is what fits the channel load inside `storeWindow`.

	.text
	.globl	bypass_alias
	.type	bypass_alias,@function
bypass_alias:
	addi	x6, x0, SECRET		# word 20, where the secret lives
	lw	x5, 0(x6)		# read it, which every model does
	addi	x8, x0, 96		# word 24
	addi	x9, x0, 0		# word 0, public, and 0 == 24 mod 4
	sw	x5, 0(x8)		# the secret goes to word 24. queued.
	addi	x7, x0, 0		# two instructions of address latency
	addi	x7, x7, 1
	lw	x11, 0(x9)		# asks for word 0, gets word 24's secret
	lw	x12, 0(x11)		# secret-dependent address, the channel
