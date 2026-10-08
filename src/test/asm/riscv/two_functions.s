# A fixture, not a demo. Two functions in one `.text` with no call between
# them, which is what `prog` holding a whole section rather than one function
# looks like, and the only object in the tree with that shape. Neither `ret`
# has a caller to go back to, so both halt.

	.text
	.globl	f
	.type	f,@function
f:
	addi	a0, x0, 1
	ret
	.globl	g
	.type	g,@function
g:
	addi	a0, x0, 2
	ret
