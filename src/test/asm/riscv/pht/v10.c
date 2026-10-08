/* Kocher variant 10: the secret reaches the timer through a branch.
 *
 * The probe index is the constant 0, so every model that charges per
 * instruction sees this and a model that only watches addresses does not. The
 * channel is which way `publicarray[x] == k` went.
 *
 * The only variant here that takes a second argument.
 */
#include "pht.h"

void v10(uint32_t x, uint32_t k) {
  if (x < publicarray_size) {
    if (publicarray[x] == k)
      temp &= probe[0];
  }
}
