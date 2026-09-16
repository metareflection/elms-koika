# Prime and probe, at the scale of a twelve-frame cache.
#
# The secret never becomes an address here. It picks a *set*, and the whole
# channel is which set gets a line installed in it. That is the one shape the
# model this replaces could not state: two fully associative entries have no
# sets, so every new line evicts whatever was there and there is nothing for a
# secret to choose between.
#
# L1 is two sets of two ways over two-word lines, so word `w` is in line
# `w >> 1` and line `l` is in set `l & 1`. Three lines that agree in that bit
# are one more than the set holds, which is the eviction set and is four
# instructions.
#
#	line 0  words 0-1    byte 0    set 0
#	line 2  words 4-5    byte 16   set 0
#	line 4  words 8-9    byte 32   set 0	<- the secret's arm
#	line 5  words 10-11  byte 40   set 1	<- the other one
#
# Both arms miss and both install a line. They differ in where: one displaces
# the probe target out of set 0 and the other lands in set 1 and leaves it
# alone. The probe then answers out of L1 for 1 or out of L2 for 12, and 11 is
# the gap the two runs disagree by.
#
# Nothing in it is speculative and nothing reads around a store, so every model
# from `cache` rightward reports it and the two to the left of that do not.

	.text
	.globl	evict
	.type	evict,@function
evict:
	lw	x5, SECRET(x0)		# the secret, at a literal address
	andi	x6, x5, 1		# one bit of it
	slli	x6, x6, 3		# 0 or 8
	addi	x6, x6, 32		# byte 32, set 0, or byte 40, set 1

	lw	x7, 0(x0)		# prime: line 0 into set 0
	lw	x8, 16(x0)		# prime: line 2 into set 0, and line 0 is now its LRU

	lw	x9, 0(x6)		# set 0 displaces line 0; set 1 does not

	lw	x11, 0(x0)		# probe: L1 for 1 cycle, or L2 for 12
