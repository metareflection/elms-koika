/* Kocher variant 20: the load is hoisted above the guard.
 *
 * Same as 17 in that the read happens unconditionally, and not the same in
 * what follows it: the value only reaches `probe` on the in-bounds arm, so the
 * address channel needs the branch to be mispredicted even though the read did
 * not.
 *
 * The dead `else` is the original's. It is what stops the compiler sinking the
 * load back under the guard.
 */
#include "pht.h"

void v20(uint32_t x) {
  uint32_t y = publicarray[x];
  if (x < publicarray_size) {
    temp &= probe[(y & 7) * 2];
  } else {
    y = 0;
  }
}
