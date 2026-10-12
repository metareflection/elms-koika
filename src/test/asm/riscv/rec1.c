/* clang --target=riscv32 -march=rv32i -mabi=ilp32 -O1 -mno-relax -S rec1.c -o rec1.s
 *
 * `rec.c` with the depth turned down, which is what makes it checkable.
 *
 * Under the scheme that stages a callee per call site, depth is what decides
 * whether the tower answers at all, and `rec.c` is there to be refused. Under
 * one that emits a callee once and returns from it, the recursion reaches the
 * residue and the bound becomes CBMC's problem instead, where it costs a
 * nesting of the whole 19-function cycle `down` compiles into. `n & 1` is two
 * frames, so the same question fits in a formula somebody can wait for.
 *
 * No `probe[]` and no load in the recursive function on purpose. What is being
 * measured is the call, and a cache model would otherwise spend the whole
 * formula on the array.
 *
 * `optnone` keeps clang from turning `down` into a loop. Without it -O1 sees
 * the tail call and the object has no recursion left in it to stage.
 *
 * -O1 and -mno-relax for the reasons `cmp.c` gives.
 */
#include <stdint.h>
__attribute__((section(".attacker"))) uint32_t temp;
static __attribute__((noinline,optnone)) uint32_t down(uint32_t n) {
  if (n == 0) return 0;
  return down(n - 1) + 1;
}
void victim(uint32_t n) { temp &= down(n & 1); }
