/* clang --target=riscv32 -march=rv32i -mabi=ilp32 -O1 -mno-relax -S rec.c -o rec.s
 *
 * Self-recursion, which no static return stack can bound. The reader accepts
 * this object: every `jalr` in it is paired with an `auipc` and every target is
 * inside `.text`. It is the tower that has to refuse it, and the test is that
 * it says "recursion" rather than filling memory.
 *
 * `optnone` keeps clang from turning `down` into a loop. Without it -O1 sees
 * the tail call and the object has no recursion left in it to refuse.
 *
 * -O1 and -mno-relax for the reasons `cmp.c` gives.
 */
#include <stdint.h>
__attribute__((section(".attacker"))) uint32_t probe[16];
__attribute__((section(".attacker"))) uint32_t temp;
static __attribute__((noinline,optnone)) uint32_t down(uint32_t n) {
  if (n == 0) return 0;
  temp &= probe[n & 7];
  return down(n - 1) + 1;
}
void victim(uint32_t n) { temp &= down(n & 7); }
