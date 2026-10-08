/* Kocher variant 25: the bound check is one arm of a switch.
 *
 * `case 0` is in range by construction and carries no check, `default` carries
 * the one variant 1 would have had, and both arms end in the same gadget. The
 * question is whether a model distinguishes the arm that was proved from the
 * arm that was predicted.
 */
#include "pht.h"

void v25(uint32_t x) {
  switch (x) {
  case 0:
    temp &= probe[(publicarray[x] & 7) * 2];
    break;
  default:
    if (x < publicarray_size) {
      temp &= probe[(publicarray[x] & 7) * 2];
    }
  }
}
