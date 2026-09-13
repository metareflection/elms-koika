# The minimal branch-then-dependent-loads program, and the RISC-V twin of
# NanoRisc's `spec_small`. The `beq` is shorter than `B(Eq, r0, Imm(0))` had to
# be, because x0 being hardwired zero is exactly what that spelled out.
#
# The `slli` is the byte-addressing tax. `mem` is word-indexed, so a secret used
# directly as a byte address only reaches word `secret >> 2` and can never
# collide with the word the first load already pulled in. Scaling it first is
# what real Spectre gadgets do with the cache line size, and it is what makes
# the second probe land in the same range as the first.
#
# `done` is one past the last instruction, which is how the tower halts. No
# `ret` here or in any of these: the program falls off the end instead.

	.text
	.globl	spec_small
	.type	spec_small,@function
spec_small:
	beq	x10, x0, done
	lw	x11, 0(x10)
	slli	x11, x11, 2
	lw	x12, 16(x11)
done:
