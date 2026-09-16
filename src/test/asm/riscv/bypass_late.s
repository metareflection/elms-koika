# `bypass.s` with a bounds check in front of the store, which is where the queue
# used to stop existing. Takes SECRET, a byte offset, from the caller.
#
# The gadget is the same one: the store is held, the load behind it reads around
# it and comes back with the secret rather than the zero, and the load after
# that turns the secret into an address. What is new is how the store is
# reached. `bge` opens a speculation window, `Isa.speculable` refuses a store,
# and so the store is the instruction that closes the window. [Speculative] runs
# that instruction through `step` rather than `call`, which skips `execute`, so
# for a while `Forwarding` never saw a store in this position and this program
# was its `speculative` twin to the byte. `Speculative.closing` is the hook that
# fixed it.
#
# The check always passes. `a0 & 28` is at most 28 and the bound is 32, so the
# not-taken guess is right and the rollback arm is dead. That is deliberate: the
# demo is about the store, and a branch that resolved correctly is the case the
# window-close path is for. `guarded.fact` is the other order, where the check
# is what goes wrong.
#
# x5 and x9 hold the compared values and the window writes x6 and x7, so nothing
# speculated clobbers an input to the condition. Reorder these and the window
# closes at the `addi` instead and the store is never reached under speculation
# at all.

	.text
	.globl	bypass_late
	.type	bypass_late,@function
bypass_late:
	andi	x5, x10, 28		# the attacker picks which word
	addi	x9, x0, 32		# the bound it cannot reach
	bge	x5, x9, done		# so this is never taken
	addi	x6, x5, SECRET		# p = &secret[(a0 >> 2) & 7]
	addi	x7, x0, 0		# the sanitizer
	sw	x7, 0(x6)		# closes the branch window, opens the store's
	lw	x11, 0(x6)		# read around the queue, so this is the secret
	slli	x11, x11, 2		# mem is word-indexed, so scale
	lw	x12, 0(x11)		# secret-dependent address, the channel
done:
