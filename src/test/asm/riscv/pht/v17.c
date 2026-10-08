/* Kocher variant 17: the guard reads the array it is guarding.
 *
 * `x` is bounded by nothing, so the out-of-bounds read is on the architectural
 * path and the branch after it is already on a secret. Kept as the original
 * wrote it; the row it fills is what a variant that needs no speculation looks
 * like next to five that do.
 */
#include "pht.h"

void v17(uint32_t x) {
  if (publicarray[x] < publicarray_size) {
    temp &= probe[(publicarray[x] & 7) * 2];
  }
}
