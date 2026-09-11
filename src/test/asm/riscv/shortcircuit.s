# Standard short-circuiting password-checker loop, leaks whether some prefix of
# the guess is correct. Takes SECRET and SIZE, both byte counts, from the
# caller. The counter steps by 4, because addresses are bytes.
#
# The leak here is in the control flow rather than in the speculation, so every
# driver sees it.
#
# All drivers should detect a timing leak (CBMC should fail).

	.text
	.globl	shortcircuit
	.type	shortcircuit,@function
shortcircuit:
	addi	x12, x0, 0		# guess base
	addi	x13, x0, SECRET		# secret base
	addi	x14, x0, 0		# i, in bytes
	addi	x15, x0, SIZE		# size, in bytes
loop:
	bge	x14, x15, right
	add	x5, x12, x14
	lw	x10, 0(x5)
	add	x6, x13, x14
	lw	x11, 0(x6)
	bne	x10, x11, wrong
	addi	x14, x14, 4
	j	loop
wrong:
	addi	x10, x0, 0
	j	done
right:
	addi	x10, x0, 1
done:
