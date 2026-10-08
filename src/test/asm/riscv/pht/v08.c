/* Kocher variant 8: the bound check is a ternary feeding the index.
 *
 * Nothing branches around the load, so a predictor has no bounds check to run
 * ahead of. What it has is `x + 1`, which at `x == publicarray_size - 1` is one
 * past the end with no speculation at all.
 */
#include "pht.h"

void v08(uint32_t x) {
  temp &= probe[(publicarray[x < publicarray_size ? (x + 1) : 0] & 7) * 2];
}
