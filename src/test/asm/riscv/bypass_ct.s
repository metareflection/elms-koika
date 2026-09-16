# The negative control for `bypass.s`, and the two differ in one operand: the
# base register of the last load. Takes SECRET, a byte offset, from the caller.
#
# Everything about the queue still happens. The store is held, the load behind
# it reads around it and comes back with the secret, and the load after that
# forwards out of the queue rather than probing the cache. What does not happen
# is the secret becoming an address, so no model has anything to report.
#
# Worth having as its own demo because it separates two claims that a single
# leaking program cannot. `bypass.s` leaking says the channel exists; this one
# verifying says the channel is the address and not the queue, and that a
# program can read around a store without paying for it.

	.text
	.globl	bypass_ct
	.type	bypass_ct,@function
bypass_ct:
	andi	x6, x10, 28		# the attacker picks which word
	addi	x6, x6, SECRET		# p, attacker-chosen and so public
	addi	x7, x0, 0		# the sanitizer
	sw	x7, 0(x6)		# scrub it. queued, not committed.
	lw	x11, 0(x6)		# read around the queue, so this is the secret
	slli	x11, x11, 2		# and it is still the secret
	lw	x12, 0(x6)		# but the address here is p, which is public
