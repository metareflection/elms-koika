# `spectre.s` with the reload step the original leaves out. Takes SECRET, a byte
# offset, from the caller.
#
# The first eight instructions are `spectre.s` unchanged: a bounds check the
# predictor gets wrong, a load of a word past the end, and a second load that
# turns that word into an address. What is new is the probe at the bottom, which
# asks the cache for a line the speculation may or may not have installed, after
# the squash has already put the registers back.
#
# That is what a real Flush+Reload does and it is the reason this demo exists.
# `spectre.s` never probes anything: its gap is the *speculated* load's own
# latency, which a machine that stops the world for a miss pays on the spot and
# a machine with non-blocking loads throws away with the rest of the window. So
# `spectre` reads clean under `predictive_nb`, which says the gap the other
# speculating models report there is the stall rather than the cache.
#
# This one survives both. The line the speculation installed is still there when
# the probe asks for it, which is the thing no squash undoes and the thing the
# attacker was after in the first place.
#
# The probe is word 0, so it hits exactly when the secret picked line 0, which
# is `secret >> 1 == 0`. One word is enough here because the question is whether
# two runs disagree rather than which line an attacker would have to hunt for.
#
# The `j` is load-bearing and is about the model rather than about the machine.
# `Predictive` resolves a window at the first instruction it cannot speculate,
# with no join-point test of the kind `Speculative` has, so a window walks
# straight past the branch's own target and keeps going. Put the probe directly
# at `done` and it runs *inside* the window, installs line 0 whatever the secret
# was, and the re-executed probe after the squash hits every time. A jump is not
# speculable, so this one ends the window where the branch target is.

	.text
	.globl	reload
	.type	reload,@function
reload:
	addi	x13, x0, 0		# base
	addi	x10, x0, SECRET		# index, out of bounds
	addi	x15, x0, SECRET		# bound
	bge	x10, x15, done		# and it is taken
	add	x5, x13, x10
	lw	x11, 0(x5)		# speculative secret load
	slli	x11, x11, 2		# mem is word-indexed, so scale
	lw	x12, 0(x11)		# secret-dependent address, installs the line
done:
	j	probe			# ends the window before the probe runs
probe:
	lw	x14, 0(x0)		# the reload, after the registers came back
