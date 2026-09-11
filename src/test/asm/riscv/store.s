# A fixture, not a demo. `-O1` on the demos materialises a base address and then
# stores through a plain displacement, so nothing else in the tree produces an
# `R_RISCV_LO12_S` and this is the only thing holding that path down.
#
# `v` is padded away from the start of its section on purpose: a zero
# displacement would read the same as a dropped immediate.

	.text
	.globl	f
	.type	f,@function
f:
	lui	a1, %hi(v)
	sw	a0, %lo(v)(a1)

	.section	.data,"aw",@progbits
	.p2align	2, 0x0
	.word	0, 0, 0
	.type	v,@object
	.globl	v
v:
	.word	7
	.size	v, 4
