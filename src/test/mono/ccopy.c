/* Monocypher's `fe_ccopy`, four ways, and the one word that decides it.
 *
 * The first of the four is the function as Monocypher ships it, copied out of
 * `monocypher.c` unchanged. The comment above it there says a compiler may
 * turn the masked copy into a timing leak, and names two mitigations:
 *
 *   We apply two mitigations here:
 *   - Add `volatile` in the mask declaration.
 *   - Unroll the copy loop (costs couple hundred bytes of binary code).
 *
 *   As of June 2026, those mitigation work when applied separately or
 *   together.  Applying them both is currently overkill, but may help
 *   delay the day compilers grow clever enough to defeat it.
 *
 * For clang targeting RV32IM at -O2 that last sentence does not hold, and the
 * reason is sharper than the four variants suggest. The four objects `build`
 * produces are two. Strip the leading address off each disassembled line and
 * the function name out of each branch annotation, and `shipped` and
 * `volatile` come out identical, as do `unrolled` and `plain`. Strip only the
 * address and all four look distinct, because the annotations carry the names,
 * so the normalization is part of the claim and not an aside.
 *
 * clang unrolls a ten-iteration loop over a literal bound whether or not the
 * source already did. The second mitigation therefore does not reach the object
 * here, and `volatile` is carrying the whole thing.
 *
 * That is about this compiler at this optimization level. The comment is
 * defending against compilers in general, and on one that does not unroll, the
 * written-out loop is doing the job it was put there for. Nobody measured such
 * a compiler. The measured claim is that the unrolling is not load bearing on
 * clang at -O2 for RV32IM.
 *
 * `unrolled` is the variant that says so. It keeps one mitigation, applied
 * separately, exactly as the comment says suffices, and it leaks as hard as
 * keeping neither.
 *
 * What triggers it is the condition arriving as a comparison. That is what
 * hands instcombine an `i1`, which is what lets it fold the mask arithmetic
 * back into a `select`, and RV32I has no conditional move so llc lowers a
 * `select` as a branch. `src/test/fact/build` writes the same mechanism down
 * for FaCT's selection idiom; this is it firing on a shipped library instead
 * of on a `.fact` file.
 *
 * Every entry below writes the comparison inline, next to the copy. That is a
 * construction and not a transcription, and the difference matters. `invsqrt`
 * calls
 *
 *   fe_ccopy(isr, t0, 1 - (m1 | ms));
 *
 * where `m1` and `ms` are `fe_isequal` results, and at -O2 clang leaves
 * `fe_isequal` out of line, so what reaches the copy is a returned `int` rather
 * than an `i1` and instcombine never gets the fold. Writing the comparison here
 * is what puts the `i1` in front of it.
 *
 * So the shipped library is not affected, and measurably so: delete `volatile`
 * from `monocypher.c` outright and no branch count moves in `crypto_x25519`,
 * `crypto_elligator_map`, `crypto_eddsa_sign` or `crypto_x25519_dirty_small`.
 * Force `fe_isequal` inline, though, and `invsqrt` goes from 3 branches to 13
 * without `volatile` and stays at 3 with it. The mitigation is load bearing in
 * the real library; it is one inlining decision away from being needed, which is
 * what the comment means by delaying the day compilers grow clever enough.
 * `doc/candidates.md` has both tables.
 *
 * The ladder's `fe_cswap` is the other contrast and the reason this file is
 * about `fe_ccopy`: its condition is a bit shifted out of the scalar, so there
 * is no comparison and no `i1` to find, and it stays branch-free with both
 * mitigations removed. A conditional swap also writes both destinations, so
 * there is no `select` to fold in the first place.
 *
 * `f` is the accumulator `fe_ccopy` conditionally overwrites and `g` is the
 * other candidate, so both are secret. `h` and `k` stand in for the constants
 * `invsqrt` compares against, which are public.
 *
 * Taken from a git checkout of monocypher.c, whose header gives its version as
 * `__git__` rather than a release number, so there is no tag to cite. The
 * function is at lines 1027 to 1041 of that file and the comment above it is
 * dated June 2026.
 */

#include <stdint.h>

typedef int32_t i32;
typedef i32 fe[10];

/* As shipped: volatile mask, unrolled copy. Both mitigations. */
static void copy_shipped(fe f, const fe g, int b)
{
	volatile i32 mask = -b; // -1 = 0xffffffff
	i32 x0 = (f[0] ^ g[0]) & mask;    f[0] = f[0] ^ x0;
	i32 x1 = (f[1] ^ g[1]) & mask;    f[1] = f[1] ^ x1;
	i32 x2 = (f[2] ^ g[2]) & mask;    f[2] = f[2] ^ x2;
	i32 x3 = (f[3] ^ g[3]) & mask;    f[3] = f[3] ^ x3;
	i32 x4 = (f[4] ^ g[4]) & mask;    f[4] = f[4] ^ x4;
	i32 x5 = (f[5] ^ g[5]) & mask;    f[5] = f[5] ^ x5;
	i32 x6 = (f[6] ^ g[6]) & mask;    f[6] = f[6] ^ x6;
	i32 x7 = (f[7] ^ g[7]) & mask;    f[7] = f[7] ^ x7;
	i32 x8 = (f[8] ^ g[8]) & mask;    f[8] = f[8] ^ x8;
	i32 x9 = (f[9] ^ g[9]) & mask;    f[9] = f[9] ^ x9;
}

/* Mitigation 1 taken away. Still unrolled, which the comment says is enough. */
static void copy_unrolled(fe f, const fe g, int b)
{
	i32 mask = -b;
	i32 x0 = (f[0] ^ g[0]) & mask;    f[0] = f[0] ^ x0;
	i32 x1 = (f[1] ^ g[1]) & mask;    f[1] = f[1] ^ x1;
	i32 x2 = (f[2] ^ g[2]) & mask;    f[2] = f[2] ^ x2;
	i32 x3 = (f[3] ^ g[3]) & mask;    f[3] = f[3] ^ x3;
	i32 x4 = (f[4] ^ g[4]) & mask;    f[4] = f[4] ^ x4;
	i32 x5 = (f[5] ^ g[5]) & mask;    f[5] = f[5] ^ x5;
	i32 x6 = (f[6] ^ g[6]) & mask;    f[6] = f[6] ^ x6;
	i32 x7 = (f[7] ^ g[7]) & mask;    f[7] = f[7] ^ x7;
	i32 x8 = (f[8] ^ g[8]) & mask;    f[8] = f[8] ^ x8;
	i32 x9 = (f[9] ^ g[9]) & mask;    f[9] = f[9] ^ x9;
}

/* Mitigation 2 taken away. The mask is still volatile. */
static void copy_volatile(fe f, const fe g, int b)
{
	volatile i32 mask = -b;
	for (int i = 0; i < 10; i++) {
		i32 x = (f[i] ^ g[i]) & mask;    f[i] = f[i] ^ x;
	}
}

/* Neither mitigation. What the comment is written against. */
static void copy_plain(fe f, const fe g, int b)
{
	i32 mask = -b;
	for (int i = 0; i < 10; i++) {
		i32 x = (f[i] ^ g[i]) & mask;    f[i] = f[i] ^ x;
	}
}

/* One entry per variant, each the shape of `invsqrt`'s call site. `build`
 * internalizes against one of these at a time, so every object holds exactly
 * one function and the tower enters it at pc 0. */
#define ENTRY(N)                                                              \
	void ccopy_##N(fe f, const fe g, const fe h, const fe k)              \
	{                                                                     \
		int m1 = (f[0] == h[0]);                                      \
		int ms = (f[1] == k[1]);                                      \
		copy_##N(f, g, 1 - (m1 | ms));                                \
	}

ENTRY(shipped)
ENTRY(unrolled)
ENTRY(volatile)
ENTRY(plain)
