/* Kocher variant 20 with the reload step the benchmark leaves out.
 *
 * Not one of the 27. The Spectector sources are victim functions, and a victim
 * function never probes anything: the Flush+Reload is the attacker's code, and
 * a checker whose observation is a trace of load addresses reads the channel
 * straight off the speculated load without needing it. This tower's
 * observation is the victim's own clock, so the probe has to be in the
 * program, and `reload.s` is the hand-written demo that says so.
 *
 * What `v20` leaves on the table is a cache line. Under a model with
 * non-blocking loads the misses the window had outstanding are discarded with
 * the window, so `v20` reads clean under `nonblocking` and `predictive_nb`
 * while the line it installed is still sitting there. This asks for it.
 *
 * `probe[0]` because the line the speculation installed is `(y & 7)`'s, so the
 * reload hits exactly when the secret picked line 0. One word is enough: the
 * question is whether two runs disagree, not which line an attacker would have
 * to hunt for.
 *
 * The reload is the bounds check's own branch target, which in `reload.s`
 * would have put it inside the window. It does not here because the predictor
 * is cold at that branch and so guesses not-taken, which sends the window down
 * the gadget instead. Teach the predictor otherwise and this demo stops being
 * one.
 */
#include "pht.h"

void v20r(uint32_t x) {
  uint32_t y = publicarray[x];
  if (x < publicarray_size) {
    temp &= probe[(y & 7) * 2];
  } else {
    y = 0;
  }
  temp &= probe[0];
}
