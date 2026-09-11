/* clang --target=riscv32 -march=rv32i -mabi=ilp32 -O1 -S cmp.c -o cmp.s
 *
 * The `shortcircuit` demo's shape, arrived at from C rather than by hand: the
 * loop stops at the first mismatch, so the trip count depends on the secret and
 * every driver should see the leak.
 *
 * -O1 on purpose. At -O0 this grows a stack frame, and `sp` starts at 0 in the
 * tower, so `addi sp, sp, -32` walks off the bottom of a 30-word memory.
 *
 * Naive/Speculative: CBMC fails (leak detected). The leak is in the control
 * flow, so it does not need the cache or the speculation to show up.
 */
int secret[4] = {11, 22, 33, 44};
int guess[4];

int cmp(int n) {
  int i;
  for (i = 0; i < n; i++) {
    if (guess[i] != secret[i]) return 0;
  }
  return 1;
}
