/* clang --target=riscv32 -march=rv32i -mabi=ilp32 -O1 -mno-relax -S twocall.c -o twocall.s
 *
 * Two call sites to one callee, which is what the return stack is for. `mask`
 * is reached twice and has to come back to a different place each time, so a
 * tower that keyed its slots on pc alone would return both calls to whichever
 * site it staged first.
 *
 * `static` on `mask` is what keeps the relocation off the `auipc`/`jalr` pair.
 * A global callee leaves `R_RISCV_CALL_PLT` on the `auipc` for the linker, and
 * a target the linker still owes is one the reader cannot compute.
 *
 * `victim` is not a leaf, so -O1 gives it a frame and spills `ra` into it. That
 * is the case the residue's `ret_assert` exists for: the value reloaded off the
 * stack is what a real machine would jump to, and the assertion is where it
 * meets the tower's static guess.
 *
 * -O1 and -mno-relax for the reasons `cmp.c` gives.
 *
 * The leak is `probe[(a ^ b) * 2]`, which is attacker-indexed and says nothing
 * about the secret. Nothing here is meant to leak; it is the smallest program
 * with two calls in it.
 */
#include <stdint.h>
__attribute__((section(".secret")))   uint32_t secretarray[8];
__attribute__((section(".attacker"))) uint32_t publicarray[8];
__attribute__((section(".attacker"))) uint32_t probe[16];
__attribute__((section(".attacker"))) uint32_t temp;

static __attribute__((noinline)) uint32_t mask(uint32_t x) { return x & 7; }

void victim(uint32_t x) {
  uint32_t a = mask(publicarray[x & 7]);
  uint32_t b = mask(a + 1);
  temp &= probe[(a ^ b) * 2];
}
