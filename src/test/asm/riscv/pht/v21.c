/* Kocher variant 21: the bound check is a loop condition.
 *
 * Two iterations, and the index of the second is the value the first read, so
 * the walk goes wherever `publicarray` points it. No `probe` at all: `temp &= x`
 * is the sink, which makes this the one variant whose channel is a value rather
 * than an address.
 *
 * It is also the only backward conditional branch here, so it is the one that
 * opens a `Predictive` window toward a lower pc. `cmp.c` is the other, and it
 * says what that costs to check.
 */
#include "pht.h"

void v21(uint32_t x) {
  int y = 0;
  for (; y < 2 && x < publicarray_size; y++) {
    x = publicarray[x];
    temp &= x;
  }
}
