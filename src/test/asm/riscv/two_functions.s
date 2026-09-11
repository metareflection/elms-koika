# A fixture, not a demo, and the reader rejects it. `ret` is read as a jump one
# past the end of the program, where the tower halts, which is only what
# returning means for a leaf. A callee's `ret` would have to go back to its
# caller, and there is nothing in the tower to go back through.

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
