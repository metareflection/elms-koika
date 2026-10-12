# Generated, do not edit. See rec1.c for the command that made it.
	.attribute	4, 16
	.attribute	5, "rv32i2p1"
	.file	"rec1.c"
	.text
	.globl	victim                          # -- Begin function victim
	.p2align	2
	.type	victim,@function
victim:                                 # @victim
# %bb.0:
	addi	sp, sp, -16
	sw	ra, 12(sp)                      # 4-byte Folded Spill
	andi	a0, a0, 1
	call	down
	lui	a1, %hi(temp)
	lw	a2, %lo(temp)(a1)
	and	a0, a2, a0
	sw	a0, %lo(temp)(a1)
	lw	ra, 12(sp)                      # 4-byte Folded Reload
	addi	sp, sp, 16
	ret
.Lfunc_end0:
	.size	victim, .Lfunc_end0-victim
                                        # -- End function
	.p2align	2                               # -- Begin function down
	.type	down,@function
down:                                   # @down
# %bb.0:
	addi	sp, sp, -16
	sw	ra, 12(sp)                      # 4-byte Folded Spill
	sw	a0, 4(sp)
	lw	a0, 4(sp)
	bnez	a0, .LBB1_2
	j	.LBB1_1
.LBB1_1:
	sw	zero, 8(sp)
	j	.LBB1_3
.LBB1_2:
	lw	a0, 4(sp)
	addi	a0, a0, -1
	call	down
	addi	a0, a0, 1
	sw	a0, 8(sp)
	j	.LBB1_3
.LBB1_3:
	lw	a0, 8(sp)
	lw	ra, 12(sp)                      # 4-byte Folded Reload
	addi	sp, sp, 16
	ret
.Lfunc_end1:
	.size	down, .Lfunc_end1-down
                                        # -- End function
	.type	temp,@object                    # @temp
	.section	.attacker,"aw",@progbits
	.globl	temp
	.p2align	2, 0x0
temp:
	.word	0                               # 0x0
	.size	temp, 4

	.ident	"clang version 22.1.6 (Fedora 22.1.6-1.fc44)"
	.section	".note.GNU-stack","",@progbits
	.addrsig
