# Generated, do not edit. See cmp.c for the command that made it.
	.attribute	4, 16
	.attribute	5, "rv32i2p1"
	.file	"cmp.c"
	.text
	.globl	cmp                             # -- Begin function cmp
	.p2align	2
	.type	cmp,@function
cmp:                                    # @cmp
# %bb.0:
	mv	a1, a0
	li	a0, 1
	blez	a1, .LBB0_4
# %bb.1:
	lui	a2, %hi(guess)
	addi	a2, a2, %lo(guess)
	lui	a3, %hi(secret)
	addi	a3, a3, %lo(secret)
.LBB0_2:                                # =>This Inner Loop Header: Depth=1
	lw	a4, 0(a2)
	lw	a5, 0(a3)
	bne	a4, a5, .LBB0_5
# %bb.3:                                #   in Loop: Header=BB0_2 Depth=1
	addi	a1, a1, -1
	addi	a2, a2, 4
	addi	a3, a3, 4
	bnez	a1, .LBB0_2
.LBB0_4:
	ret
.LBB0_5:
	li	a0, 0
	ret
.Lfunc_end0:
	.size	cmp, .Lfunc_end0-cmp
                                        # -- End function
	.type	secret,@object                  # @secret
	.section	.secret,"aw",@progbits
	.globl	secret
	.p2align	2, 0x0
secret:
	.word	11                              # 0xb
	.word	22                              # 0x16
	.word	33                              # 0x21
	.word	44                              # 0x2c
	.size	secret, 16

	.type	guess,@object                   # @guess
	.section	.attacker,"aw",@progbits
	.globl	guess
	.p2align	2, 0x0
guess:
	.zero	16
	.size	guess, 16

	.ident	"clang version 22.1.6 (Fedora 22.1.6-1.fc44)"
	.section	".note.GNU-stack","",@progbits
	.addrsig
