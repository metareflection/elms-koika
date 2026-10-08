# Generated, do not edit. See twocall.c for the command that made it.
	.attribute	4, 16
	.attribute	5, "rv32i2p1"
	.file	"twocall.c"
	.text
	.globl	victim                          # -- Begin function victim
	.p2align	2
	.type	victim,@function
victim:                                 # @victim
# %bb.0:
	addi	sp, sp, -16
	sw	ra, 12(sp)                      # 4-byte Folded Spill
	sw	s0, 8(sp)                       # 4-byte Folded Spill
	sw	s1, 4(sp)                       # 4-byte Folded Spill
	andi	a0, a0, 7
	slli	a0, a0, 2
	lui	s1, %hi(.L_MergedGlobals)
	addi	s1, s1, %lo(.L_MergedGlobals)
	add	a0, s1, a0
	lw	a0, 4(a0)
	call	mask
	mv	s0, a0
	addi	a0, a0, 1
	call	mask
	xor	a0, a0, s0
	slli	a0, a0, 3
	add	a0, s1, a0
	lw	a1, 0(s1)
	lw	a0, 36(a0)
	and	a0, a1, a0
	sw	a0, 0(s1)
	lw	ra, 12(sp)                      # 4-byte Folded Reload
	lw	s0, 8(sp)                       # 4-byte Folded Reload
	lw	s1, 4(sp)                       # 4-byte Folded Reload
	addi	sp, sp, 16
	ret
.Lfunc_end0:
	.size	victim, .Lfunc_end0-victim
                                        # -- End function
	.p2align	2                               # -- Begin function mask
	.type	mask,@function
mask:                                   # @mask
# %bb.0:
	andi	a0, a0, 7
	ret
.Lfunc_end1:
	.size	mask, .Lfunc_end1-mask
                                        # -- End function
	.type	secretarray,@object             # @secretarray
	.section	.secret,"aw",@progbits
	.globl	secretarray
	.p2align	2, 0x0
secretarray:
	.zero	32
	.size	secretarray, 32

	.type	.L_MergedGlobals,@object        # @_MergedGlobals
	.section	.attacker,"aw",@progbits
	.p2align	2, 0x0
.L_MergedGlobals:
	.zero	100
	.size	.L_MergedGlobals, 100

	.globl	temp
temp = .L_MergedGlobals
	.size	temp, 4
	.globl	publicarray
publicarray = .L_MergedGlobals+4
	.size	publicarray, 32
	.globl	probe
probe = .L_MergedGlobals+36
	.size	probe, 64
	.ident	"clang version 22.1.6 (Fedora 22.1.6-1.fc44)"
	.section	".note.GNU-stack","",@progbits
	.addrsig
	.addrsig_sym .L_MergedGlobals
