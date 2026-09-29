// verify: clean (Eva should report untainted: Valid) [unroll 65]
#define NUM_REGS 32
#define MEM_SIZE 64
#define SECRET_SIZE 10
#define SECRET_OFFSET 20
#define CACHE_ENTRIES 12
#define CACHE_WORDS 24

#ifdef EVA
#include "__fc_builtin.h"
/*@ requires untainted: !\tainted(b);
    assigns \nothing; */
void koika_check(int b);
/*@ assigns *p \from \nothing;
    taints *p; */
void koika_mark(int *p);
#define koika_assert(b, s) koika_check(b)
#define koika_assume(b) do { if (!(b)) Frama_C_abort(); } while (0)
#define koika_draw(x) ((x) = Frama_C_interval(-2147483647-1, 2147483647))
#define koika_secret(x) koika_mark(&(x))
#else
#define koika_assert(b, s) 0
#define koika_assume(b) 0
#define koika_draw(x) ((x) = 0)
#define koika_secret(x) ((void)0)
#endif
int bounded(int low, int high) {
  int x;
  koika_draw(x);
  koika_assume(low <= x && x <= high);
  return x;
}
// Same draw as `bounded`, said of the secret, so a backend that tracks
// where the secret goes has somewhere to start. Self-composition already
// encodes the split by drawing these twice, which is why the mark is
// nothing under a checker that reads the two runs exactly.
int secret(int low, int high) {
  int x = bounded(low, high);
  koika_secret(x);
  return x;
}

/*****************************************
Emitting C Generated Code
*******************************************/

#include <stdbool.h>

struct StateT2 {
  struct StateT * a;
  struct StateT * b;
};

struct StateT {
  int regs[32];
  int mem[64];
  int saved_regs[32];
  int reg_ready[32];
  int cache_tags[12];
  int cache_dirty[12];
  int cache_age[12];
  int cache_vals[24];
  int timer;
};

void squared_assert(bool);
void squared_assume(bool);
void squared_diverged(bool);

struct StateT2 * slot_12(struct StateT2 * v2338);
struct StateT2 * slot_14(struct StateT2 * v2423);
struct StateT2 * slot_6(struct StateT2 * v631);
struct StateT2 * slot_2(struct StateT2 * v74);
struct StateT2 * snippet(struct StateT2 * v0);
struct StateT2 * slot_10(struct StateT2 * v2299);
struct StateT2 * slot_1(struct StateT2 * v38);
struct StateT2 * slot_8(struct StateT2 * v707);
struct StateT2 * slot_4(struct StateT2 * v134);
struct StateT2 * slot_9(struct StateT2 * v1855);
struct StateT2 * slot_11(struct StateT2 * v2273);
struct StateT2 * slot_0(struct StateT2 * v2);
struct StateT2 * slot_12(struct StateT2 * v2338) {
  struct StateT * v2339 = v2338->a;
  int v2340 = v2339->timer;
  struct StateT * v2341 = v2338->b;
  int v2342 = v2341->timer;
  bool v2355 = v2340 == v2342;
  squared_assert(v2355);
  squared_assume(v2355);
  struct StateT * v2345 = v2338->a;
  int v2346 = v2345->timer;
  int v2357 = v2346 + 1;
  v2345->timer = v2357;
  struct StateT * v2348 = v2338->b;
  int v2349 = v2348->timer;
  int v2359 = v2349 + 1;
  v2348->timer = v2359;
  struct StateT2 * v2351 = slot_4(v2338);
  return v2351;
}

struct StateT2 * slot_14(struct StateT2 * v2423) {
  struct StateT * v2424 = v2423->a;
  int v2425 = v2424->timer;
  struct StateT * v2426 = v2423->b;
  int v2427 = v2426->timer;
  bool v2664 = v2425 == v2427;
  squared_assert(v2664);
  squared_assume(v2664);
  struct StateT * v2430 = v2423->a;
  int * v2431 = v2430->saved_regs;
  int * v2432 = v2430->regs;
  int v2433 = v2432[5];
  v2431[5] = v2433;
  struct StateT * v2435 = v2423->b;
  int * v2436 = v2435->saved_regs;
  int * v2437 = v2435->regs;
  int v2438 = v2437[5];
  v2436[5] = v2438;
  struct StateT * v2440 = v2423->a;
  int v2441 = v2440->timer;
  int v2675 = v2441 + 1;
  v2440->timer = v2675;
  struct StateT * v2443 = v2423->b;
  int v2444 = v2443->timer;
  int v2677 = v2444 + 1;
  v2443->timer = v2677;
  struct StateT * v2446 = v2423->a;
  int * v2447 = v2446->regs;
  int v2448 = v2447[8];
  int * v2449 = v2446->cache_tags;
  int v2682 = (((int)((unsigned int)((int)((unsigned int)v2448 >> 2)) >> 1)) & 1) * 2;
  int v2450 = v2449[v2682];
  int v2683 = ((((int)((unsigned int)((int)((unsigned int)v2448 >> 2)) >> 1)) & 1) * 2) + 1;
  int v2451 = v2449[v2683];
  int v2684 = 4 + ((((int)((unsigned int)((int)((unsigned int)v2448 >> 2)) >> 1)) & 3) * 2);
  int v2452 = v2449[v2684];
  int v2685 = (4 + ((((int)((unsigned int)((int)((unsigned int)v2448 >> 2)) >> 1)) & 3) * 2)) + 1;
  int v2453 = v2449[v2685];
  int v2454 = v2446->timer;
  int v2686 = v2454 + ((100 ^ (((~(((v2452 ^ ((int)((unsigned int)((int)((unsigned int)v2448 >> 2)) >> 1))) | (-(v2452 ^ ((int)((unsigned int)((int)((unsigned int)v2448 >> 2)) >> 1))))) >> 31)) | (~(((v2453 ^ ((int)((unsigned int)((int)((unsigned int)v2448 >> 2)) >> 1))) | (-(v2453 ^ ((int)((unsigned int)((int)((unsigned int)v2448 >> 2)) >> 1))))) >> 31))) & 104)) ^ (((~(((v2450 ^ ((int)((unsigned int)((int)((unsigned int)v2448 >> 2)) >> 1))) | (-(v2450 ^ ((int)((unsigned int)((int)((unsigned int)v2448 >> 2)) >> 1))))) >> 31)) | (~(((v2451 ^ ((int)((unsigned int)((int)((unsigned int)v2448 >> 2)) >> 1))) | (-(v2451 ^ ((int)((unsigned int)((int)((unsigned int)v2448 >> 2)) >> 1))))) >> 31))) & (1 ^ (100 ^ (((~(((v2452 ^ ((int)((unsigned int)((int)((unsigned int)v2448 >> 2)) >> 1))) | (-(v2452 ^ ((int)((unsigned int)((int)((unsigned int)v2448 >> 2)) >> 1))))) >> 31)) | (~(((v2453 ^ ((int)((unsigned int)((int)((unsigned int)v2448 >> 2)) >> 1))) | (-(v2453 ^ ((int)((unsigned int)((int)((unsigned int)v2448 >> 2)) >> 1))))) >> 31))) & 104)))));
  v2446->timer = v2686;
  int * v2456 = v2446->cache_vals;
  bool v2687 = !(((~(((v2450 ^ ((int)((unsigned int)((int)((unsigned int)v2448 >> 2)) >> 1))) | (-(v2450 ^ ((int)((unsigned int)((int)((unsigned int)v2448 >> 2)) >> 1))))) >> 31)) | (~(((v2451 ^ ((int)((unsigned int)((int)((unsigned int)v2448 >> 2)) >> 1))) | (-(v2451 ^ ((int)((unsigned int)((int)((unsigned int)v2448 >> 2)) >> 1))))) >> 31))) == 0);
  int v2549;
  if (v2687) {
    int * v2457 = v2446->cache_age;
    int v2689 = ((((int)((unsigned int)((int)((unsigned int)v2448 >> 2)) >> 1)) & 1) * 2) + ((~(((v2451 ^ ((int)((unsigned int)((int)((unsigned int)v2448 >> 2)) >> 1))) | (-(v2451 ^ ((int)((unsigned int)((int)((unsigned int)v2448 >> 2)) >> 1))))) >> 31)) & 1);
    int v2458 = v2457[v2689];
    int v2459 = v2457[v2682];
    int v2690 = v2459 + ((int)((unsigned int)(v2459 - v2458) >> 31));
    v2457[v2682] = v2690;
    int * v2461 = v2446->cache_age;
    int v2462 = v2461[v2683];
    int v2692 = v2462 + ((int)((unsigned int)(v2462 - v2458) >> 31));
    v2461[v2683] = v2692;
    int * v2464 = v2446->cache_age;
    v2464[v2689] = 0;
    v2549 = v2689;
  } else {
    int * v2467 = v2446->cache_age;
    int v2696 = (((int)((unsigned int)((int)((unsigned int)v2448 >> 2)) >> 1)) & 1) * 2;
    int v2468 = v2467[v2696];
    int * v2469 = v2446->cache_tags;
    int v2470 = v2469[v2696];
    int v2471 = v2467[v2683];
    int v2472 = v2469[v2683];
    bool v2698 = !(((~(((v2452 ^ ((int)((unsigned int)((int)((unsigned int)v2448 >> 2)) >> 1))) | (-(v2452 ^ ((int)((unsigned int)((int)((unsigned int)v2448 >> 2)) >> 1))))) >> 31)) | (~(((v2453 ^ ((int)((unsigned int)((int)((unsigned int)v2448 >> 2)) >> 1))) | (-(v2453 ^ ((int)((unsigned int)((int)((unsigned int)v2448 >> 2)) >> 1))))) >> 31))) == 0);
    int v2526;
    if (v2698) {
      int * v2473 = v2446->cache_age;
      int v2700 = (4 + ((((int)((unsigned int)((int)((unsigned int)v2448 >> 2)) >> 1)) & 3) * 2)) + ((~(((v2453 ^ ((int)((unsigned int)((int)((unsigned int)v2448 >> 2)) >> 1))) | (-(v2453 ^ ((int)((unsigned int)((int)((unsigned int)v2448 >> 2)) >> 1))))) >> 31)) & 1);
      int v2474 = v2473[v2700];
      int v2475 = v2473[v2684];
      int v2701 = v2475 + ((int)((unsigned int)(v2475 - v2474) >> 31));
      v2473[v2684] = v2701;
      int * v2477 = v2446->cache_age;
      int v2478 = v2477[v2685];
      int v2703 = v2478 + ((int)((unsigned int)(v2478 - v2474) >> 31));
      v2477[v2685] = v2703;
      int * v2480 = v2446->cache_age;
      v2480[v2700] = 0;
      v2526 = v2700;
    } else {
      int * v2483 = v2446->cache_age;
      int v2707 = 4 + ((((int)((unsigned int)((int)((unsigned int)v2448 >> 2)) >> 1)) & 3) * 2);
      int v2484 = v2483[v2707];
      int * v2485 = v2446->cache_tags;
      int v2486 = v2485[v2707];
      int v2487 = v2483[v2685];
      int v2488 = v2485[v2685];
      int * v2489 = v2446->cache_dirty;
      int v2710 = (4 + ((((int)((unsigned int)((int)((unsigned int)v2448 >> 2)) >> 1)) & 3) * 2)) + ((((v2484 + ((~(((v2486 ^ -1) | (-(v2486 ^ -1))) >> 31)) & 2)) - (v2487 + ((~(((v2488 ^ -1) | (-(v2488 ^ -1))) >> 31)) & 2))) >> 31) & 1);
      int v2490 = v2489[v2710];
      bool v2711 = !(v2490 == 0);
      if (v2711) {
        int * v2491 = v2446->cache_tags;
        int v2492 = v2491[v2710];
        int * v2493 = v2446->cache_vals;
        int v2714 = ((4 + ((((int)((unsigned int)((int)((unsigned int)v2448 >> 2)) >> 1)) & 3) * 2)) + ((((v2484 + ((~(((v2486 ^ -1) | (-(v2486 ^ -1))) >> 31)) & 2)) - (v2487 + ((~(((v2488 ^ -1) | (-(v2488 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
        int v2494 = v2493[v2714];
        int v2715 = (((4 + ((((int)((unsigned int)((int)((unsigned int)v2448 >> 2)) >> 1)) & 3) * 2)) + ((((v2484 + ((~(((v2486 ^ -1) | (-(v2486 ^ -1))) >> 31)) & 2)) - (v2487 + ((~(((v2488 ^ -1) | (-(v2488 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
        int v2495 = v2493[v2715];
        int * v2496 = v2446->mem;
        int v2717 = v2492 * 2;
        v2496[v2717] = v2494;
        int * v2498 = v2446->mem;
        int v2720 = (v2492 * 2) + 1;
        v2498[v2720] = v2495;
        ;
      } else {
        ;
      }
      int * v2503 = v2446->mem;
      int v2725 = ((int)((unsigned int)((int)((unsigned int)v2448 >> 2)) >> 1)) * 2;
      int v2504 = v2503[v2725];
      int v2726 = (((int)((unsigned int)((int)((unsigned int)v2448 >> 2)) >> 1)) * 2) + 1;
      int v2505 = v2503[v2726];
      int * v2506 = v2446->cache_vals;
      int v2728 = ((4 + ((((int)((unsigned int)((int)((unsigned int)v2448 >> 2)) >> 1)) & 3) * 2)) + ((((v2484 + ((~(((v2486 ^ -1) | (-(v2486 ^ -1))) >> 31)) & 2)) - (v2487 + ((~(((v2488 ^ -1) | (-(v2488 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
      v2506[v2728] = v2504;
      int * v2508 = v2446->cache_vals;
      int v2731 = (((4 + ((((int)((unsigned int)((int)((unsigned int)v2448 >> 2)) >> 1)) & 3) * 2)) + ((((v2484 + ((~(((v2486 ^ -1) | (-(v2486 ^ -1))) >> 31)) & 2)) - (v2487 + ((~(((v2488 ^ -1) | (-(v2488 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
      v2508[v2731] = v2505;
      int * v2510 = v2446->cache_tags;
      int v2734 = (int)((unsigned int)((int)((unsigned int)v2448 >> 2)) >> 1);
      v2510[v2710] = v2734;
      int * v2512 = v2446->cache_dirty;
      v2512[v2710] = 0;
      int * v2514 = v2446->cache_age;
      v2514[v2710] = 1;
      int * v2516 = v2446->cache_age;
      int v2517 = v2516[v2710];
      int v2518 = v2516[v2684];
      int v2740 = v2518 + ((int)((unsigned int)(v2518 - v2517) >> 31));
      v2516[v2684] = v2740;
      int * v2520 = v2446->cache_age;
      int v2521 = v2520[v2685];
      int v2742 = v2521 + ((int)((unsigned int)(v2521 - v2517) >> 31));
      v2520[v2685] = v2742;
      int * v2523 = v2446->cache_age;
      v2523[v2710] = 0;
      v2526 = v2710;
    }
    int * v2527 = v2446->cache_vals;
    int v2745 = v2526 * 2;
    int v2528 = v2527[v2745];
    int v2746 = (v2526 * 2) + 1;
    int v2529 = v2527[v2746];
    int v2747 = (((((int)((unsigned int)((int)((unsigned int)v2448 >> 2)) >> 1)) & 1) * 2) + ((((v2468 + ((~(((v2470 ^ -1) | (-(v2470 ^ -1))) >> 31)) & 2)) - (v2471 + ((~(((v2472 ^ -1) | (-(v2472 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
    v2527[v2747] = v2528;
    int * v2531 = v2446->cache_vals;
    int v2750 = ((((((int)((unsigned int)((int)((unsigned int)v2448 >> 2)) >> 1)) & 1) * 2) + ((((v2468 + ((~(((v2470 ^ -1) | (-(v2470 ^ -1))) >> 31)) & 2)) - (v2471 + ((~(((v2472 ^ -1) | (-(v2472 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
    v2531[v2750] = v2529;
    int * v2533 = v2446->cache_tags;
    int v2753 = ((((int)((unsigned int)((int)((unsigned int)v2448 >> 2)) >> 1)) & 1) * 2) + ((((v2468 + ((~(((v2470 ^ -1) | (-(v2470 ^ -1))) >> 31)) & 2)) - (v2471 + ((~(((v2472 ^ -1) | (-(v2472 ^ -1))) >> 31)) & 2))) >> 31) & 1);
    int v2754 = (int)((unsigned int)((int)((unsigned int)v2448 >> 2)) >> 1);
    v2533[v2753] = v2754;
    int * v2535 = v2446->cache_dirty;
    v2535[v2753] = 0;
    int * v2537 = v2446->cache_age;
    v2537[v2753] = 1;
    int * v2539 = v2446->cache_age;
    int v2540 = v2539[v2753];
    int v2541 = v2539[v2682];
    int v2760 = v2541 + ((int)((unsigned int)(v2541 - v2540) >> 31));
    v2539[v2682] = v2760;
    int * v2543 = v2446->cache_age;
    int v2544 = v2543[v2683];
    int v2762 = v2544 + ((int)((unsigned int)(v2544 - v2540) >> 31));
    v2543[v2683] = v2762;
    int * v2546 = v2446->cache_age;
    v2546[v2753] = 0;
    v2549 = v2753;
  }
  int v2765 = (v2549 * 2) + (((int)((unsigned int)v2448 >> 2)) & 1);
  int v2550 = v2456[v2765];
  int * v2551 = v2446->regs;
  v2551[5] = v2550;
  struct StateT * v2553 = v2423->b;
  int * v2554 = v2553->regs;
  int v2555 = v2554[8];
  int * v2556 = v2553->cache_tags;
  int v2771 = (((int)((unsigned int)((int)((unsigned int)v2555 >> 2)) >> 1)) & 1) * 2;
  int v2557 = v2556[v2771];
  int v2772 = ((((int)((unsigned int)((int)((unsigned int)v2555 >> 2)) >> 1)) & 1) * 2) + 1;
  int v2558 = v2556[v2772];
  int v2773 = 4 + ((((int)((unsigned int)((int)((unsigned int)v2555 >> 2)) >> 1)) & 3) * 2);
  int v2559 = v2556[v2773];
  int v2774 = (4 + ((((int)((unsigned int)((int)((unsigned int)v2555 >> 2)) >> 1)) & 3) * 2)) + 1;
  int v2560 = v2556[v2774];
  int v2561 = v2553->timer;
  int v2775 = v2561 + ((100 ^ (((~(((v2559 ^ ((int)((unsigned int)((int)((unsigned int)v2555 >> 2)) >> 1))) | (-(v2559 ^ ((int)((unsigned int)((int)((unsigned int)v2555 >> 2)) >> 1))))) >> 31)) | (~(((v2560 ^ ((int)((unsigned int)((int)((unsigned int)v2555 >> 2)) >> 1))) | (-(v2560 ^ ((int)((unsigned int)((int)((unsigned int)v2555 >> 2)) >> 1))))) >> 31))) & 104)) ^ (((~(((v2557 ^ ((int)((unsigned int)((int)((unsigned int)v2555 >> 2)) >> 1))) | (-(v2557 ^ ((int)((unsigned int)((int)((unsigned int)v2555 >> 2)) >> 1))))) >> 31)) | (~(((v2558 ^ ((int)((unsigned int)((int)((unsigned int)v2555 >> 2)) >> 1))) | (-(v2558 ^ ((int)((unsigned int)((int)((unsigned int)v2555 >> 2)) >> 1))))) >> 31))) & (1 ^ (100 ^ (((~(((v2559 ^ ((int)((unsigned int)((int)((unsigned int)v2555 >> 2)) >> 1))) | (-(v2559 ^ ((int)((unsigned int)((int)((unsigned int)v2555 >> 2)) >> 1))))) >> 31)) | (~(((v2560 ^ ((int)((unsigned int)((int)((unsigned int)v2555 >> 2)) >> 1))) | (-(v2560 ^ ((int)((unsigned int)((int)((unsigned int)v2555 >> 2)) >> 1))))) >> 31))) & 104)))));
  v2553->timer = v2775;
  int * v2563 = v2553->cache_vals;
  bool v2776 = !(((~(((v2557 ^ ((int)((unsigned int)((int)((unsigned int)v2555 >> 2)) >> 1))) | (-(v2557 ^ ((int)((unsigned int)((int)((unsigned int)v2555 >> 2)) >> 1))))) >> 31)) | (~(((v2558 ^ ((int)((unsigned int)((int)((unsigned int)v2555 >> 2)) >> 1))) | (-(v2558 ^ ((int)((unsigned int)((int)((unsigned int)v2555 >> 2)) >> 1))))) >> 31))) == 0);
  int v2656;
  if (v2776) {
    int * v2564 = v2553->cache_age;
    int v2778 = ((((int)((unsigned int)((int)((unsigned int)v2555 >> 2)) >> 1)) & 1) * 2) + ((~(((v2558 ^ ((int)((unsigned int)((int)((unsigned int)v2555 >> 2)) >> 1))) | (-(v2558 ^ ((int)((unsigned int)((int)((unsigned int)v2555 >> 2)) >> 1))))) >> 31)) & 1);
    int v2565 = v2564[v2778];
    int v2566 = v2564[v2771];
    int v2779 = v2566 + ((int)((unsigned int)(v2566 - v2565) >> 31));
    v2564[v2771] = v2779;
    int * v2568 = v2553->cache_age;
    int v2569 = v2568[v2772];
    int v2781 = v2569 + ((int)((unsigned int)(v2569 - v2565) >> 31));
    v2568[v2772] = v2781;
    int * v2571 = v2553->cache_age;
    v2571[v2778] = 0;
    v2656 = v2778;
  } else {
    int * v2574 = v2553->cache_age;
    int v2785 = (((int)((unsigned int)((int)((unsigned int)v2555 >> 2)) >> 1)) & 1) * 2;
    int v2575 = v2574[v2785];
    int * v2576 = v2553->cache_tags;
    int v2577 = v2576[v2785];
    int v2578 = v2574[v2772];
    int v2579 = v2576[v2772];
    bool v2787 = !(((~(((v2559 ^ ((int)((unsigned int)((int)((unsigned int)v2555 >> 2)) >> 1))) | (-(v2559 ^ ((int)((unsigned int)((int)((unsigned int)v2555 >> 2)) >> 1))))) >> 31)) | (~(((v2560 ^ ((int)((unsigned int)((int)((unsigned int)v2555 >> 2)) >> 1))) | (-(v2560 ^ ((int)((unsigned int)((int)((unsigned int)v2555 >> 2)) >> 1))))) >> 31))) == 0);
    int v2633;
    if (v2787) {
      int * v2580 = v2553->cache_age;
      int v2789 = (4 + ((((int)((unsigned int)((int)((unsigned int)v2555 >> 2)) >> 1)) & 3) * 2)) + ((~(((v2560 ^ ((int)((unsigned int)((int)((unsigned int)v2555 >> 2)) >> 1))) | (-(v2560 ^ ((int)((unsigned int)((int)((unsigned int)v2555 >> 2)) >> 1))))) >> 31)) & 1);
      int v2581 = v2580[v2789];
      int v2582 = v2580[v2773];
      int v2790 = v2582 + ((int)((unsigned int)(v2582 - v2581) >> 31));
      v2580[v2773] = v2790;
      int * v2584 = v2553->cache_age;
      int v2585 = v2584[v2774];
      int v2792 = v2585 + ((int)((unsigned int)(v2585 - v2581) >> 31));
      v2584[v2774] = v2792;
      int * v2587 = v2553->cache_age;
      v2587[v2789] = 0;
      v2633 = v2789;
    } else {
      int * v2590 = v2553->cache_age;
      int v2796 = 4 + ((((int)((unsigned int)((int)((unsigned int)v2555 >> 2)) >> 1)) & 3) * 2);
      int v2591 = v2590[v2796];
      int * v2592 = v2553->cache_tags;
      int v2593 = v2592[v2796];
      int v2594 = v2590[v2774];
      int v2595 = v2592[v2774];
      int * v2596 = v2553->cache_dirty;
      int v2799 = (4 + ((((int)((unsigned int)((int)((unsigned int)v2555 >> 2)) >> 1)) & 3) * 2)) + ((((v2591 + ((~(((v2593 ^ -1) | (-(v2593 ^ -1))) >> 31)) & 2)) - (v2594 + ((~(((v2595 ^ -1) | (-(v2595 ^ -1))) >> 31)) & 2))) >> 31) & 1);
      int v2597 = v2596[v2799];
      bool v2800 = !(v2597 == 0);
      if (v2800) {
        int * v2598 = v2553->cache_tags;
        int v2599 = v2598[v2799];
        int * v2600 = v2553->cache_vals;
        int v2803 = ((4 + ((((int)((unsigned int)((int)((unsigned int)v2555 >> 2)) >> 1)) & 3) * 2)) + ((((v2591 + ((~(((v2593 ^ -1) | (-(v2593 ^ -1))) >> 31)) & 2)) - (v2594 + ((~(((v2595 ^ -1) | (-(v2595 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
        int v2601 = v2600[v2803];
        int v2804 = (((4 + ((((int)((unsigned int)((int)((unsigned int)v2555 >> 2)) >> 1)) & 3) * 2)) + ((((v2591 + ((~(((v2593 ^ -1) | (-(v2593 ^ -1))) >> 31)) & 2)) - (v2594 + ((~(((v2595 ^ -1) | (-(v2595 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
        int v2602 = v2600[v2804];
        int * v2603 = v2553->mem;
        int v2806 = v2599 * 2;
        v2603[v2806] = v2601;
        int * v2605 = v2553->mem;
        int v2809 = (v2599 * 2) + 1;
        v2605[v2809] = v2602;
        ;
      } else {
        ;
      }
      int * v2610 = v2553->mem;
      int v2814 = ((int)((unsigned int)((int)((unsigned int)v2555 >> 2)) >> 1)) * 2;
      int v2611 = v2610[v2814];
      int v2815 = (((int)((unsigned int)((int)((unsigned int)v2555 >> 2)) >> 1)) * 2) + 1;
      int v2612 = v2610[v2815];
      int * v2613 = v2553->cache_vals;
      int v2817 = ((4 + ((((int)((unsigned int)((int)((unsigned int)v2555 >> 2)) >> 1)) & 3) * 2)) + ((((v2591 + ((~(((v2593 ^ -1) | (-(v2593 ^ -1))) >> 31)) & 2)) - (v2594 + ((~(((v2595 ^ -1) | (-(v2595 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
      v2613[v2817] = v2611;
      int * v2615 = v2553->cache_vals;
      int v2820 = (((4 + ((((int)((unsigned int)((int)((unsigned int)v2555 >> 2)) >> 1)) & 3) * 2)) + ((((v2591 + ((~(((v2593 ^ -1) | (-(v2593 ^ -1))) >> 31)) & 2)) - (v2594 + ((~(((v2595 ^ -1) | (-(v2595 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
      v2615[v2820] = v2612;
      int * v2617 = v2553->cache_tags;
      int v2823 = (int)((unsigned int)((int)((unsigned int)v2555 >> 2)) >> 1);
      v2617[v2799] = v2823;
      int * v2619 = v2553->cache_dirty;
      v2619[v2799] = 0;
      int * v2621 = v2553->cache_age;
      v2621[v2799] = 1;
      int * v2623 = v2553->cache_age;
      int v2624 = v2623[v2799];
      int v2625 = v2623[v2773];
      int v2829 = v2625 + ((int)((unsigned int)(v2625 - v2624) >> 31));
      v2623[v2773] = v2829;
      int * v2627 = v2553->cache_age;
      int v2628 = v2627[v2774];
      int v2831 = v2628 + ((int)((unsigned int)(v2628 - v2624) >> 31));
      v2627[v2774] = v2831;
      int * v2630 = v2553->cache_age;
      v2630[v2799] = 0;
      v2633 = v2799;
    }
    int * v2634 = v2553->cache_vals;
    int v2834 = v2633 * 2;
    int v2635 = v2634[v2834];
    int v2835 = (v2633 * 2) + 1;
    int v2636 = v2634[v2835];
    int v2836 = (((((int)((unsigned int)((int)((unsigned int)v2555 >> 2)) >> 1)) & 1) * 2) + ((((v2575 + ((~(((v2577 ^ -1) | (-(v2577 ^ -1))) >> 31)) & 2)) - (v2578 + ((~(((v2579 ^ -1) | (-(v2579 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
    v2634[v2836] = v2635;
    int * v2638 = v2553->cache_vals;
    int v2839 = ((((((int)((unsigned int)((int)((unsigned int)v2555 >> 2)) >> 1)) & 1) * 2) + ((((v2575 + ((~(((v2577 ^ -1) | (-(v2577 ^ -1))) >> 31)) & 2)) - (v2578 + ((~(((v2579 ^ -1) | (-(v2579 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
    v2638[v2839] = v2636;
    int * v2640 = v2553->cache_tags;
    int v2842 = ((((int)((unsigned int)((int)((unsigned int)v2555 >> 2)) >> 1)) & 1) * 2) + ((((v2575 + ((~(((v2577 ^ -1) | (-(v2577 ^ -1))) >> 31)) & 2)) - (v2578 + ((~(((v2579 ^ -1) | (-(v2579 ^ -1))) >> 31)) & 2))) >> 31) & 1);
    int v2843 = (int)((unsigned int)((int)((unsigned int)v2555 >> 2)) >> 1);
    v2640[v2842] = v2843;
    int * v2642 = v2553->cache_dirty;
    v2642[v2842] = 0;
    int * v2644 = v2553->cache_age;
    v2644[v2842] = 1;
    int * v2646 = v2553->cache_age;
    int v2647 = v2646[v2842];
    int v2648 = v2646[v2771];
    int v2849 = v2648 + ((int)((unsigned int)(v2648 - v2647) >> 31));
    v2646[v2771] = v2849;
    int * v2650 = v2553->cache_age;
    int v2651 = v2650[v2772];
    int v2851 = v2651 + ((int)((unsigned int)(v2651 - v2647) >> 31));
    v2650[v2772] = v2851;
    int * v2653 = v2553->cache_age;
    v2653[v2842] = 0;
    v2656 = v2842;
  }
  int v2854 = (v2656 * 2) + (((int)((unsigned int)v2555 >> 2)) & 1);
  int v2657 = v2563[v2854];
  int * v2658 = v2553->regs;
  v2658[5] = v2657;
  struct StateT2 * v2660 = slot_6(v2423);
  return v2660;
}

struct StateT2 * slot_6(struct StateT2 * v631) {
  struct StateT * v632 = v631->a;
  int v633 = v632->timer;
  struct StateT * v634 = v631->b;
  int v635 = v634->timer;
  bool v677 = v633 == v635;
  squared_assert(v677);
  squared_assume(v677);
  struct StateT * v638 = v631->a;
  int * v639 = v638->regs;
  int v640 = v639[6];
  int v641 = v639[7];
  struct StateT * v642 = v631->b;
  int * v643 = v642->regs;
  int v644 = v643[6];
  int v645 = v643[7];
  bool v684 = (v640 >= v641) == (v644 >= v645);
  squared_diverged(v684);
  squared_assume(v684);
  bool v685 = v640 >= v641;
  struct StateT2 * v673;
  if (v685) {
    struct StateT * v648 = v631->a;
    int v649 = v648->timer;
    int v687 = v649 + 15;
    v648->timer = v687;
    int * v651 = v648->saved_regs;
    int v652 = v651[8];
    int * v653 = v648->regs;
    v653[8] = v652;
    int * v655 = v648->saved_regs;
    int v656 = v655[5];
    int * v657 = v648->regs;
    v657[5] = v656;
    struct StateT * v659 = v631->b;
    int v660 = v659->timer;
    int v697 = v660 + 15;
    v659->timer = v697;
    int * v662 = v659->saved_regs;
    int v663 = v662[8];
    int * v664 = v659->regs;
    v664[8] = v663;
    int * v666 = v659->saved_regs;
    int v667 = v666[5];
    int * v668 = v659->regs;
    v668[5] = v667;
    v673 = v631;
  } else {
    struct StateT2 * v671 = slot_8(v631);
    v673 = v671;
  }
  return v673;
}

struct StateT2 * slot_2(struct StateT2 * v74) {
  struct StateT * v75 = v74->a;
  int v76 = v75->timer;
  struct StateT * v77 = v74->b;
  int v78 = v77->timer;
  bool v97 = v76 == v78;
  squared_assert(v97);
  squared_assume(v97);
  struct StateT * v81 = v74->a;
  int v82 = v81->timer;
  int v99 = v82 + 1;
  v81->timer = v99;
  struct StateT * v84 = v74->b;
  int v85 = v84->timer;
  int v101 = v85 + 1;
  v84->timer = v101;
  struct StateT * v87 = v74->a;
  int * v88 = v87->regs;
  v88[9] = 80;
  struct StateT * v90 = v74->b;
  int * v91 = v90->regs;
  v91[9] = 80;
  struct StateT2 * v93 = slot_12(v74);
  return v93;
}

struct StateT2 * snippet(struct StateT2 * v0) {
  struct StateT2 * v1 = slot_0(v0);
  return v1;
}

struct StateT2 * slot_10(struct StateT2 * v2299) {
  struct StateT * v2300 = v2299->a;
  int v2301 = v2300->timer;
  struct StateT * v2302 = v2299->b;
  int v2303 = v2302->timer;
  bool v2324 = v2301 == v2303;
  squared_assert(v2324);
  squared_assume(v2324);
  struct StateT * v2306 = v2299->a;
  int v2307 = v2306->timer;
  int v2326 = v2307 + 1;
  v2306->timer = v2326;
  struct StateT * v2309 = v2299->b;
  int v2310 = v2309->timer;
  int v2328 = v2310 + 1;
  v2309->timer = v2328;
  struct StateT * v2312 = v2299->a;
  int * v2313 = v2312->regs;
  int v2314 = v2313[6];
  int v2332 = v2314 + 4;
  v2313[6] = v2332;
  struct StateT * v2316 = v2299->b;
  int * v2317 = v2316->regs;
  int v2318 = v2317[6];
  int v2335 = v2318 + 4;
  v2317[6] = v2335;
  struct StateT2 * v2320 = slot_11(v2299);
  return v2320;
}

struct StateT2 * slot_1(struct StateT2 * v38) {
  struct StateT * v39 = v38->a;
  int v40 = v39->timer;
  struct StateT * v41 = v38->b;
  int v42 = v41->timer;
  bool v61 = v40 == v42;
  squared_assert(v61);
  squared_assume(v61);
  struct StateT * v45 = v38->a;
  int v46 = v45->timer;
  int v63 = v46 + 1;
  v45->timer = v63;
  struct StateT * v48 = v38->b;
  int v49 = v48->timer;
  int v65 = v49 + 1;
  v48->timer = v65;
  struct StateT * v51 = v38->a;
  int * v52 = v51->regs;
  v52[7] = 16;
  struct StateT * v54 = v38->b;
  int * v55 = v54->regs;
  v55[7] = 16;
  struct StateT2 * v57 = slot_2(v38);
  return v57;
}

struct StateT2 * slot_8(struct StateT2 * v707) {
  struct StateT * v708 = v707->a;
  int v709 = v708->timer;
  struct StateT * v710 = v707->b;
  int v711 = v710->timer;
  bool v1340 = v709 == v711;
  squared_assert(v1340);
  squared_assume(v1340);
  struct StateT * v714 = v707->a;
  int v715 = v714->timer;
  int v1342 = v715 + 1;
  v714->timer = v1342;
  struct StateT * v717 = v707->b;
  int v718 = v717->timer;
  int v1344 = v718 + 1;
  v717->timer = v1344;
  struct StateT * v720 = v707->a;
  int * v721 = v720->regs;
  int v722 = v721[6];
  int v723 = v721[5];
  struct StateT * v724 = v707->b;
  int * v725 = v724->regs;
  int v726 = v725[6];
  int v727 = v725[5];
  int * v728 = v720->saved_regs;
  int v729 = v721[11];
  v728[11] = v729;
  struct StateT * v731 = v707->b;
  int * v732 = v731->saved_regs;
  int * v733 = v731->regs;
  int v734 = v733[11];
  v732[11] = v734;
  struct StateT * v736 = v707->a;
  int v737 = v736->timer;
  int v1359 = v737 + 1;
  v736->timer = v1359;
  struct StateT * v739 = v707->b;
  int v740 = v739->timer;
  int v1361 = v740 + 1;
  v739->timer = v1361;
  struct StateT * v742 = v707->a;
  int * v743 = v742->regs;
  int v744 = v743[6];
  int * v745 = v742->cache_tags;
  int v1365 = (((int)((unsigned int)((int)((unsigned int)v744 >> 2)) >> 1)) & 1) * 2;
  int v746 = v745[v1365];
  int v1366 = ((((int)((unsigned int)((int)((unsigned int)v744 >> 2)) >> 1)) & 1) * 2) + 1;
  int v747 = v745[v1366];
  int v1367 = 4 + ((((int)((unsigned int)((int)((unsigned int)v744 >> 2)) >> 1)) & 3) * 2);
  int v748 = v745[v1367];
  int v1368 = (4 + ((((int)((unsigned int)((int)((unsigned int)v744 >> 2)) >> 1)) & 3) * 2)) + 1;
  int v749 = v745[v1368];
  int v750 = v742->timer;
  int v1369 = v750 + ((100 ^ (((~(((v748 ^ ((int)((unsigned int)((int)((unsigned int)v744 >> 2)) >> 1))) | (-(v748 ^ ((int)((unsigned int)((int)((unsigned int)v744 >> 2)) >> 1))))) >> 31)) | (~(((v749 ^ ((int)((unsigned int)((int)((unsigned int)v744 >> 2)) >> 1))) | (-(v749 ^ ((int)((unsigned int)((int)((unsigned int)v744 >> 2)) >> 1))))) >> 31))) & 104)) ^ (((~(((v746 ^ ((int)((unsigned int)((int)((unsigned int)v744 >> 2)) >> 1))) | (-(v746 ^ ((int)((unsigned int)((int)((unsigned int)v744 >> 2)) >> 1))))) >> 31)) | (~(((v747 ^ ((int)((unsigned int)((int)((unsigned int)v744 >> 2)) >> 1))) | (-(v747 ^ ((int)((unsigned int)((int)((unsigned int)v744 >> 2)) >> 1))))) >> 31))) & (1 ^ (100 ^ (((~(((v748 ^ ((int)((unsigned int)((int)((unsigned int)v744 >> 2)) >> 1))) | (-(v748 ^ ((int)((unsigned int)((int)((unsigned int)v744 >> 2)) >> 1))))) >> 31)) | (~(((v749 ^ ((int)((unsigned int)((int)((unsigned int)v744 >> 2)) >> 1))) | (-(v749 ^ ((int)((unsigned int)((int)((unsigned int)v744 >> 2)) >> 1))))) >> 31))) & 104)))));
  v742->timer = v1369;
  int * v752 = v742->cache_vals;
  bool v1370 = !(((~(((v746 ^ ((int)((unsigned int)((int)((unsigned int)v744 >> 2)) >> 1))) | (-(v746 ^ ((int)((unsigned int)((int)((unsigned int)v744 >> 2)) >> 1))))) >> 31)) | (~(((v747 ^ ((int)((unsigned int)((int)((unsigned int)v744 >> 2)) >> 1))) | (-(v747 ^ ((int)((unsigned int)((int)((unsigned int)v744 >> 2)) >> 1))))) >> 31))) == 0);
  int v845;
  if (v1370) {
    int * v753 = v742->cache_age;
    int v1372 = ((((int)((unsigned int)((int)((unsigned int)v744 >> 2)) >> 1)) & 1) * 2) + ((~(((v747 ^ ((int)((unsigned int)((int)((unsigned int)v744 >> 2)) >> 1))) | (-(v747 ^ ((int)((unsigned int)((int)((unsigned int)v744 >> 2)) >> 1))))) >> 31)) & 1);
    int v754 = v753[v1372];
    int v755 = v753[v1365];
    int v1373 = v755 + ((int)((unsigned int)(v755 - v754) >> 31));
    v753[v1365] = v1373;
    int * v757 = v742->cache_age;
    int v758 = v757[v1366];
    int v1375 = v758 + ((int)((unsigned int)(v758 - v754) >> 31));
    v757[v1366] = v1375;
    int * v760 = v742->cache_age;
    v760[v1372] = 0;
    v845 = v1372;
  } else {
    int * v763 = v742->cache_age;
    int v1379 = (((int)((unsigned int)((int)((unsigned int)v744 >> 2)) >> 1)) & 1) * 2;
    int v764 = v763[v1379];
    int * v765 = v742->cache_tags;
    int v766 = v765[v1379];
    int v767 = v763[v1366];
    int v768 = v765[v1366];
    bool v1381 = !(((~(((v748 ^ ((int)((unsigned int)((int)((unsigned int)v744 >> 2)) >> 1))) | (-(v748 ^ ((int)((unsigned int)((int)((unsigned int)v744 >> 2)) >> 1))))) >> 31)) | (~(((v749 ^ ((int)((unsigned int)((int)((unsigned int)v744 >> 2)) >> 1))) | (-(v749 ^ ((int)((unsigned int)((int)((unsigned int)v744 >> 2)) >> 1))))) >> 31))) == 0);
    int v822;
    if (v1381) {
      int * v769 = v742->cache_age;
      int v1383 = (4 + ((((int)((unsigned int)((int)((unsigned int)v744 >> 2)) >> 1)) & 3) * 2)) + ((~(((v749 ^ ((int)((unsigned int)((int)((unsigned int)v744 >> 2)) >> 1))) | (-(v749 ^ ((int)((unsigned int)((int)((unsigned int)v744 >> 2)) >> 1))))) >> 31)) & 1);
      int v770 = v769[v1383];
      int v771 = v769[v1367];
      int v1384 = v771 + ((int)((unsigned int)(v771 - v770) >> 31));
      v769[v1367] = v1384;
      int * v773 = v742->cache_age;
      int v774 = v773[v1368];
      int v1386 = v774 + ((int)((unsigned int)(v774 - v770) >> 31));
      v773[v1368] = v1386;
      int * v776 = v742->cache_age;
      v776[v1383] = 0;
      v822 = v1383;
    } else {
      int * v779 = v742->cache_age;
      int v1390 = 4 + ((((int)((unsigned int)((int)((unsigned int)v744 >> 2)) >> 1)) & 3) * 2);
      int v780 = v779[v1390];
      int * v781 = v742->cache_tags;
      int v782 = v781[v1390];
      int v783 = v779[v1368];
      int v784 = v781[v1368];
      int * v785 = v742->cache_dirty;
      int v1393 = (4 + ((((int)((unsigned int)((int)((unsigned int)v744 >> 2)) >> 1)) & 3) * 2)) + ((((v780 + ((~(((v782 ^ -1) | (-(v782 ^ -1))) >> 31)) & 2)) - (v783 + ((~(((v784 ^ -1) | (-(v784 ^ -1))) >> 31)) & 2))) >> 31) & 1);
      int v786 = v785[v1393];
      bool v1394 = !(v786 == 0);
      if (v1394) {
        int * v787 = v742->cache_tags;
        int v788 = v787[v1393];
        int * v789 = v742->cache_vals;
        int v1397 = ((4 + ((((int)((unsigned int)((int)((unsigned int)v744 >> 2)) >> 1)) & 3) * 2)) + ((((v780 + ((~(((v782 ^ -1) | (-(v782 ^ -1))) >> 31)) & 2)) - (v783 + ((~(((v784 ^ -1) | (-(v784 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
        int v790 = v789[v1397];
        int v1398 = (((4 + ((((int)((unsigned int)((int)((unsigned int)v744 >> 2)) >> 1)) & 3) * 2)) + ((((v780 + ((~(((v782 ^ -1) | (-(v782 ^ -1))) >> 31)) & 2)) - (v783 + ((~(((v784 ^ -1) | (-(v784 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
        int v791 = v789[v1398];
        int * v792 = v742->mem;
        int v1400 = v788 * 2;
        v792[v1400] = v790;
        int * v794 = v742->mem;
        int v1403 = (v788 * 2) + 1;
        v794[v1403] = v791;
        ;
      } else {
        ;
      }
      int * v799 = v742->mem;
      int v1408 = ((int)((unsigned int)((int)((unsigned int)v744 >> 2)) >> 1)) * 2;
      int v800 = v799[v1408];
      int v1409 = (((int)((unsigned int)((int)((unsigned int)v744 >> 2)) >> 1)) * 2) + 1;
      int v801 = v799[v1409];
      int * v802 = v742->cache_vals;
      int v1411 = ((4 + ((((int)((unsigned int)((int)((unsigned int)v744 >> 2)) >> 1)) & 3) * 2)) + ((((v780 + ((~(((v782 ^ -1) | (-(v782 ^ -1))) >> 31)) & 2)) - (v783 + ((~(((v784 ^ -1) | (-(v784 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
      v802[v1411] = v800;
      int * v804 = v742->cache_vals;
      int v1414 = (((4 + ((((int)((unsigned int)((int)((unsigned int)v744 >> 2)) >> 1)) & 3) * 2)) + ((((v780 + ((~(((v782 ^ -1) | (-(v782 ^ -1))) >> 31)) & 2)) - (v783 + ((~(((v784 ^ -1) | (-(v784 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
      v804[v1414] = v801;
      int * v806 = v742->cache_tags;
      int v1417 = (int)((unsigned int)((int)((unsigned int)v744 >> 2)) >> 1);
      v806[v1393] = v1417;
      int * v808 = v742->cache_dirty;
      v808[v1393] = 0;
      int * v810 = v742->cache_age;
      v810[v1393] = 1;
      int * v812 = v742->cache_age;
      int v813 = v812[v1393];
      int v814 = v812[v1367];
      int v1423 = v814 + ((int)((unsigned int)(v814 - v813) >> 31));
      v812[v1367] = v1423;
      int * v816 = v742->cache_age;
      int v817 = v816[v1368];
      int v1425 = v817 + ((int)((unsigned int)(v817 - v813) >> 31));
      v816[v1368] = v1425;
      int * v819 = v742->cache_age;
      v819[v1393] = 0;
      v822 = v1393;
    }
    int * v823 = v742->cache_vals;
    int v1428 = v822 * 2;
    int v824 = v823[v1428];
    int v1429 = (v822 * 2) + 1;
    int v825 = v823[v1429];
    int v1430 = (((((int)((unsigned int)((int)((unsigned int)v744 >> 2)) >> 1)) & 1) * 2) + ((((v764 + ((~(((v766 ^ -1) | (-(v766 ^ -1))) >> 31)) & 2)) - (v767 + ((~(((v768 ^ -1) | (-(v768 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
    v823[v1430] = v824;
    int * v827 = v742->cache_vals;
    int v1433 = ((((((int)((unsigned int)((int)((unsigned int)v744 >> 2)) >> 1)) & 1) * 2) + ((((v764 + ((~(((v766 ^ -1) | (-(v766 ^ -1))) >> 31)) & 2)) - (v767 + ((~(((v768 ^ -1) | (-(v768 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
    v827[v1433] = v825;
    int * v829 = v742->cache_tags;
    int v1436 = ((((int)((unsigned int)((int)((unsigned int)v744 >> 2)) >> 1)) & 1) * 2) + ((((v764 + ((~(((v766 ^ -1) | (-(v766 ^ -1))) >> 31)) & 2)) - (v767 + ((~(((v768 ^ -1) | (-(v768 ^ -1))) >> 31)) & 2))) >> 31) & 1);
    int v1437 = (int)((unsigned int)((int)((unsigned int)v744 >> 2)) >> 1);
    v829[v1436] = v1437;
    int * v831 = v742->cache_dirty;
    v831[v1436] = 0;
    int * v833 = v742->cache_age;
    v833[v1436] = 1;
    int * v835 = v742->cache_age;
    int v836 = v835[v1436];
    int v837 = v835[v1365];
    int v1443 = v837 + ((int)((unsigned int)(v837 - v836) >> 31));
    v835[v1365] = v1443;
    int * v839 = v742->cache_age;
    int v840 = v839[v1366];
    int v1445 = v840 + ((int)((unsigned int)(v840 - v836) >> 31));
    v839[v1366] = v1445;
    int * v842 = v742->cache_age;
    v842[v1436] = 0;
    v845 = v1436;
  }
  int v1448 = (v845 * 2) + (((int)((unsigned int)v744 >> 2)) & 1);
  int v846 = v752[v1448];
  int * v847 = v742->regs;
  v847[11] = v846;
  struct StateT * v849 = v707->b;
  int * v850 = v849->regs;
  int v851 = v850[6];
  int * v852 = v849->cache_tags;
  int v1454 = (((int)((unsigned int)((int)((unsigned int)v851 >> 2)) >> 1)) & 1) * 2;
  int v853 = v852[v1454];
  int v1455 = ((((int)((unsigned int)((int)((unsigned int)v851 >> 2)) >> 1)) & 1) * 2) + 1;
  int v854 = v852[v1455];
  int v1456 = 4 + ((((int)((unsigned int)((int)((unsigned int)v851 >> 2)) >> 1)) & 3) * 2);
  int v855 = v852[v1456];
  int v1457 = (4 + ((((int)((unsigned int)((int)((unsigned int)v851 >> 2)) >> 1)) & 3) * 2)) + 1;
  int v856 = v852[v1457];
  int v857 = v849->timer;
  int v1458 = v857 + ((100 ^ (((~(((v855 ^ ((int)((unsigned int)((int)((unsigned int)v851 >> 2)) >> 1))) | (-(v855 ^ ((int)((unsigned int)((int)((unsigned int)v851 >> 2)) >> 1))))) >> 31)) | (~(((v856 ^ ((int)((unsigned int)((int)((unsigned int)v851 >> 2)) >> 1))) | (-(v856 ^ ((int)((unsigned int)((int)((unsigned int)v851 >> 2)) >> 1))))) >> 31))) & 104)) ^ (((~(((v853 ^ ((int)((unsigned int)((int)((unsigned int)v851 >> 2)) >> 1))) | (-(v853 ^ ((int)((unsigned int)((int)((unsigned int)v851 >> 2)) >> 1))))) >> 31)) | (~(((v854 ^ ((int)((unsigned int)((int)((unsigned int)v851 >> 2)) >> 1))) | (-(v854 ^ ((int)((unsigned int)((int)((unsigned int)v851 >> 2)) >> 1))))) >> 31))) & (1 ^ (100 ^ (((~(((v855 ^ ((int)((unsigned int)((int)((unsigned int)v851 >> 2)) >> 1))) | (-(v855 ^ ((int)((unsigned int)((int)((unsigned int)v851 >> 2)) >> 1))))) >> 31)) | (~(((v856 ^ ((int)((unsigned int)((int)((unsigned int)v851 >> 2)) >> 1))) | (-(v856 ^ ((int)((unsigned int)((int)((unsigned int)v851 >> 2)) >> 1))))) >> 31))) & 104)))));
  v849->timer = v1458;
  int * v859 = v849->cache_vals;
  bool v1459 = !(((~(((v853 ^ ((int)((unsigned int)((int)((unsigned int)v851 >> 2)) >> 1))) | (-(v853 ^ ((int)((unsigned int)((int)((unsigned int)v851 >> 2)) >> 1))))) >> 31)) | (~(((v854 ^ ((int)((unsigned int)((int)((unsigned int)v851 >> 2)) >> 1))) | (-(v854 ^ ((int)((unsigned int)((int)((unsigned int)v851 >> 2)) >> 1))))) >> 31))) == 0);
  int v952;
  if (v1459) {
    int * v860 = v849->cache_age;
    int v1461 = ((((int)((unsigned int)((int)((unsigned int)v851 >> 2)) >> 1)) & 1) * 2) + ((~(((v854 ^ ((int)((unsigned int)((int)((unsigned int)v851 >> 2)) >> 1))) | (-(v854 ^ ((int)((unsigned int)((int)((unsigned int)v851 >> 2)) >> 1))))) >> 31)) & 1);
    int v861 = v860[v1461];
    int v862 = v860[v1454];
    int v1462 = v862 + ((int)((unsigned int)(v862 - v861) >> 31));
    v860[v1454] = v1462;
    int * v864 = v849->cache_age;
    int v865 = v864[v1455];
    int v1464 = v865 + ((int)((unsigned int)(v865 - v861) >> 31));
    v864[v1455] = v1464;
    int * v867 = v849->cache_age;
    v867[v1461] = 0;
    v952 = v1461;
  } else {
    int * v870 = v849->cache_age;
    int v1468 = (((int)((unsigned int)((int)((unsigned int)v851 >> 2)) >> 1)) & 1) * 2;
    int v871 = v870[v1468];
    int * v872 = v849->cache_tags;
    int v873 = v872[v1468];
    int v874 = v870[v1455];
    int v875 = v872[v1455];
    bool v1470 = !(((~(((v855 ^ ((int)((unsigned int)((int)((unsigned int)v851 >> 2)) >> 1))) | (-(v855 ^ ((int)((unsigned int)((int)((unsigned int)v851 >> 2)) >> 1))))) >> 31)) | (~(((v856 ^ ((int)((unsigned int)((int)((unsigned int)v851 >> 2)) >> 1))) | (-(v856 ^ ((int)((unsigned int)((int)((unsigned int)v851 >> 2)) >> 1))))) >> 31))) == 0);
    int v929;
    if (v1470) {
      int * v876 = v849->cache_age;
      int v1472 = (4 + ((((int)((unsigned int)((int)((unsigned int)v851 >> 2)) >> 1)) & 3) * 2)) + ((~(((v856 ^ ((int)((unsigned int)((int)((unsigned int)v851 >> 2)) >> 1))) | (-(v856 ^ ((int)((unsigned int)((int)((unsigned int)v851 >> 2)) >> 1))))) >> 31)) & 1);
      int v877 = v876[v1472];
      int v878 = v876[v1456];
      int v1473 = v878 + ((int)((unsigned int)(v878 - v877) >> 31));
      v876[v1456] = v1473;
      int * v880 = v849->cache_age;
      int v881 = v880[v1457];
      int v1475 = v881 + ((int)((unsigned int)(v881 - v877) >> 31));
      v880[v1457] = v1475;
      int * v883 = v849->cache_age;
      v883[v1472] = 0;
      v929 = v1472;
    } else {
      int * v886 = v849->cache_age;
      int v1479 = 4 + ((((int)((unsigned int)((int)((unsigned int)v851 >> 2)) >> 1)) & 3) * 2);
      int v887 = v886[v1479];
      int * v888 = v849->cache_tags;
      int v889 = v888[v1479];
      int v890 = v886[v1457];
      int v891 = v888[v1457];
      int * v892 = v849->cache_dirty;
      int v1482 = (4 + ((((int)((unsigned int)((int)((unsigned int)v851 >> 2)) >> 1)) & 3) * 2)) + ((((v887 + ((~(((v889 ^ -1) | (-(v889 ^ -1))) >> 31)) & 2)) - (v890 + ((~(((v891 ^ -1) | (-(v891 ^ -1))) >> 31)) & 2))) >> 31) & 1);
      int v893 = v892[v1482];
      bool v1483 = !(v893 == 0);
      if (v1483) {
        int * v894 = v849->cache_tags;
        int v895 = v894[v1482];
        int * v896 = v849->cache_vals;
        int v1486 = ((4 + ((((int)((unsigned int)((int)((unsigned int)v851 >> 2)) >> 1)) & 3) * 2)) + ((((v887 + ((~(((v889 ^ -1) | (-(v889 ^ -1))) >> 31)) & 2)) - (v890 + ((~(((v891 ^ -1) | (-(v891 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
        int v897 = v896[v1486];
        int v1487 = (((4 + ((((int)((unsigned int)((int)((unsigned int)v851 >> 2)) >> 1)) & 3) * 2)) + ((((v887 + ((~(((v889 ^ -1) | (-(v889 ^ -1))) >> 31)) & 2)) - (v890 + ((~(((v891 ^ -1) | (-(v891 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
        int v898 = v896[v1487];
        int * v899 = v849->mem;
        int v1489 = v895 * 2;
        v899[v1489] = v897;
        int * v901 = v849->mem;
        int v1492 = (v895 * 2) + 1;
        v901[v1492] = v898;
        ;
      } else {
        ;
      }
      int * v906 = v849->mem;
      int v1497 = ((int)((unsigned int)((int)((unsigned int)v851 >> 2)) >> 1)) * 2;
      int v907 = v906[v1497];
      int v1498 = (((int)((unsigned int)((int)((unsigned int)v851 >> 2)) >> 1)) * 2) + 1;
      int v908 = v906[v1498];
      int * v909 = v849->cache_vals;
      int v1500 = ((4 + ((((int)((unsigned int)((int)((unsigned int)v851 >> 2)) >> 1)) & 3) * 2)) + ((((v887 + ((~(((v889 ^ -1) | (-(v889 ^ -1))) >> 31)) & 2)) - (v890 + ((~(((v891 ^ -1) | (-(v891 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
      v909[v1500] = v907;
      int * v911 = v849->cache_vals;
      int v1503 = (((4 + ((((int)((unsigned int)((int)((unsigned int)v851 >> 2)) >> 1)) & 3) * 2)) + ((((v887 + ((~(((v889 ^ -1) | (-(v889 ^ -1))) >> 31)) & 2)) - (v890 + ((~(((v891 ^ -1) | (-(v891 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
      v911[v1503] = v908;
      int * v913 = v849->cache_tags;
      int v1506 = (int)((unsigned int)((int)((unsigned int)v851 >> 2)) >> 1);
      v913[v1482] = v1506;
      int * v915 = v849->cache_dirty;
      v915[v1482] = 0;
      int * v917 = v849->cache_age;
      v917[v1482] = 1;
      int * v919 = v849->cache_age;
      int v920 = v919[v1482];
      int v921 = v919[v1456];
      int v1512 = v921 + ((int)((unsigned int)(v921 - v920) >> 31));
      v919[v1456] = v1512;
      int * v923 = v849->cache_age;
      int v924 = v923[v1457];
      int v1514 = v924 + ((int)((unsigned int)(v924 - v920) >> 31));
      v923[v1457] = v1514;
      int * v926 = v849->cache_age;
      v926[v1482] = 0;
      v929 = v1482;
    }
    int * v930 = v849->cache_vals;
    int v1517 = v929 * 2;
    int v931 = v930[v1517];
    int v1518 = (v929 * 2) + 1;
    int v932 = v930[v1518];
    int v1519 = (((((int)((unsigned int)((int)((unsigned int)v851 >> 2)) >> 1)) & 1) * 2) + ((((v871 + ((~(((v873 ^ -1) | (-(v873 ^ -1))) >> 31)) & 2)) - (v874 + ((~(((v875 ^ -1) | (-(v875 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
    v930[v1519] = v931;
    int * v934 = v849->cache_vals;
    int v1522 = ((((((int)((unsigned int)((int)((unsigned int)v851 >> 2)) >> 1)) & 1) * 2) + ((((v871 + ((~(((v873 ^ -1) | (-(v873 ^ -1))) >> 31)) & 2)) - (v874 + ((~(((v875 ^ -1) | (-(v875 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
    v934[v1522] = v932;
    int * v936 = v849->cache_tags;
    int v1525 = ((((int)((unsigned int)((int)((unsigned int)v851 >> 2)) >> 1)) & 1) * 2) + ((((v871 + ((~(((v873 ^ -1) | (-(v873 ^ -1))) >> 31)) & 2)) - (v874 + ((~(((v875 ^ -1) | (-(v875 ^ -1))) >> 31)) & 2))) >> 31) & 1);
    int v1526 = (int)((unsigned int)((int)((unsigned int)v851 >> 2)) >> 1);
    v936[v1525] = v1526;
    int * v938 = v849->cache_dirty;
    v938[v1525] = 0;
    int * v940 = v849->cache_age;
    v940[v1525] = 1;
    int * v942 = v849->cache_age;
    int v943 = v942[v1525];
    int v944 = v942[v1454];
    int v1532 = v944 + ((int)((unsigned int)(v944 - v943) >> 31));
    v942[v1454] = v1532;
    int * v946 = v849->cache_age;
    int v947 = v946[v1455];
    int v1534 = v947 + ((int)((unsigned int)(v947 - v943) >> 31));
    v946[v1455] = v1534;
    int * v949 = v849->cache_age;
    v949[v1525] = 0;
    v952 = v1525;
  }
  int v1537 = (v952 * 2) + (((int)((unsigned int)v851 >> 2)) & 1);
  int v953 = v859[v1537];
  int * v954 = v849->regs;
  v954[11] = v953;
  struct StateT * v956 = v707->a;
  int * v957 = v956->saved_regs;
  int * v958 = v956->regs;
  int v959 = v958[6];
  v957[6] = v959;
  struct StateT * v961 = v707->b;
  int * v962 = v961->saved_regs;
  int * v963 = v961->regs;
  int v964 = v963[6];
  v962[6] = v964;
  struct StateT * v966 = v707->a;
  int v967 = v966->timer;
  int v1549 = v967 + 1;
  v966->timer = v1549;
  struct StateT * v969 = v707->b;
  int v970 = v969->timer;
  int v1551 = v970 + 1;
  v969->timer = v1551;
  struct StateT * v972 = v707->a;
  int * v973 = v972->regs;
  int v974 = v973[6];
  int v1554 = v974 + 4;
  v973[6] = v1554;
  struct StateT * v976 = v707->b;
  int * v977 = v976->regs;
  int v978 = v977[6];
  int v1557 = v978 + 4;
  v977[6] = v1557;
  struct StateT * v980 = v707->a;
  int * v981 = v980->cache_tags;
  int v1560 = (((int)((unsigned int)((int)((unsigned int)v722 >> 2)) >> 1)) & 1) * 2;
  int v982 = v981[v1560];
  int v1561 = ((((int)((unsigned int)((int)((unsigned int)v722 >> 2)) >> 1)) & 1) * 2) + 1;
  int v983 = v981[v1561];
  int v1562 = 4 + ((((int)((unsigned int)((int)((unsigned int)v722 >> 2)) >> 1)) & 3) * 2);
  int v984 = v981[v1562];
  int v1563 = (4 + ((((int)((unsigned int)((int)((unsigned int)v722 >> 2)) >> 1)) & 3) * 2)) + 1;
  int v985 = v981[v1563];
  int v986 = v980->timer;
  int v1564 = v986 + ((100 ^ (((~(((v984 ^ ((int)((unsigned int)((int)((unsigned int)v722 >> 2)) >> 1))) | (-(v984 ^ ((int)((unsigned int)((int)((unsigned int)v722 >> 2)) >> 1))))) >> 31)) | (~(((v985 ^ ((int)((unsigned int)((int)((unsigned int)v722 >> 2)) >> 1))) | (-(v985 ^ ((int)((unsigned int)((int)((unsigned int)v722 >> 2)) >> 1))))) >> 31))) & 104)) ^ (((~(((v982 ^ ((int)((unsigned int)((int)((unsigned int)v722 >> 2)) >> 1))) | (-(v982 ^ ((int)((unsigned int)((int)((unsigned int)v722 >> 2)) >> 1))))) >> 31)) | (~(((v983 ^ ((int)((unsigned int)((int)((unsigned int)v722 >> 2)) >> 1))) | (-(v983 ^ ((int)((unsigned int)((int)((unsigned int)v722 >> 2)) >> 1))))) >> 31))) & (1 ^ (100 ^ (((~(((v984 ^ ((int)((unsigned int)((int)((unsigned int)v722 >> 2)) >> 1))) | (-(v984 ^ ((int)((unsigned int)((int)((unsigned int)v722 >> 2)) >> 1))))) >> 31)) | (~(((v985 ^ ((int)((unsigned int)((int)((unsigned int)v722 >> 2)) >> 1))) | (-(v985 ^ ((int)((unsigned int)((int)((unsigned int)v722 >> 2)) >> 1))))) >> 31))) & 104)))));
  v980->timer = v1564;
  bool v1565 = !(((~(((v982 ^ ((int)((unsigned int)((int)((unsigned int)v722 >> 2)) >> 1))) | (-(v982 ^ ((int)((unsigned int)((int)((unsigned int)v722 >> 2)) >> 1))))) >> 31)) | (~(((v983 ^ ((int)((unsigned int)((int)((unsigned int)v722 >> 2)) >> 1))) | (-(v983 ^ ((int)((unsigned int)((int)((unsigned int)v722 >> 2)) >> 1))))) >> 31))) == 0);
  int v1080;
  if (v1565) {
    int * v988 = v980->cache_age;
    int v1567 = ((((int)((unsigned int)((int)((unsigned int)v722 >> 2)) >> 1)) & 1) * 2) + ((~(((v983 ^ ((int)((unsigned int)((int)((unsigned int)v722 >> 2)) >> 1))) | (-(v983 ^ ((int)((unsigned int)((int)((unsigned int)v722 >> 2)) >> 1))))) >> 31)) & 1);
    int v989 = v988[v1567];
    int v990 = v988[v1560];
    int v1568 = v990 + ((int)((unsigned int)(v990 - v989) >> 31));
    v988[v1560] = v1568;
    int * v992 = v980->cache_age;
    int v993 = v992[v1561];
    int v1570 = v993 + ((int)((unsigned int)(v993 - v989) >> 31));
    v992[v1561] = v1570;
    int * v995 = v980->cache_age;
    v995[v1567] = 0;
    v1080 = v1567;
  } else {
    int * v998 = v980->cache_age;
    int v1574 = (((int)((unsigned int)((int)((unsigned int)v722 >> 2)) >> 1)) & 1) * 2;
    int v999 = v998[v1574];
    int * v1000 = v980->cache_tags;
    int v1001 = v1000[v1574];
    int v1002 = v998[v1561];
    int v1003 = v1000[v1561];
    bool v1576 = !(((~(((v984 ^ ((int)((unsigned int)((int)((unsigned int)v722 >> 2)) >> 1))) | (-(v984 ^ ((int)((unsigned int)((int)((unsigned int)v722 >> 2)) >> 1))))) >> 31)) | (~(((v985 ^ ((int)((unsigned int)((int)((unsigned int)v722 >> 2)) >> 1))) | (-(v985 ^ ((int)((unsigned int)((int)((unsigned int)v722 >> 2)) >> 1))))) >> 31))) == 0);
    int v1057;
    if (v1576) {
      int * v1004 = v980->cache_age;
      int v1578 = (4 + ((((int)((unsigned int)((int)((unsigned int)v722 >> 2)) >> 1)) & 3) * 2)) + ((~(((v985 ^ ((int)((unsigned int)((int)((unsigned int)v722 >> 2)) >> 1))) | (-(v985 ^ ((int)((unsigned int)((int)((unsigned int)v722 >> 2)) >> 1))))) >> 31)) & 1);
      int v1005 = v1004[v1578];
      int v1006 = v1004[v1562];
      int v1579 = v1006 + ((int)((unsigned int)(v1006 - v1005) >> 31));
      v1004[v1562] = v1579;
      int * v1008 = v980->cache_age;
      int v1009 = v1008[v1563];
      int v1581 = v1009 + ((int)((unsigned int)(v1009 - v1005) >> 31));
      v1008[v1563] = v1581;
      int * v1011 = v980->cache_age;
      v1011[v1578] = 0;
      v1057 = v1578;
    } else {
      int * v1014 = v980->cache_age;
      int v1585 = 4 + ((((int)((unsigned int)((int)((unsigned int)v722 >> 2)) >> 1)) & 3) * 2);
      int v1015 = v1014[v1585];
      int * v1016 = v980->cache_tags;
      int v1017 = v1016[v1585];
      int v1018 = v1014[v1563];
      int v1019 = v1016[v1563];
      int * v1020 = v980->cache_dirty;
      int v1588 = (4 + ((((int)((unsigned int)((int)((unsigned int)v722 >> 2)) >> 1)) & 3) * 2)) + ((((v1015 + ((~(((v1017 ^ -1) | (-(v1017 ^ -1))) >> 31)) & 2)) - (v1018 + ((~(((v1019 ^ -1) | (-(v1019 ^ -1))) >> 31)) & 2))) >> 31) & 1);
      int v1021 = v1020[v1588];
      bool v1589 = !(v1021 == 0);
      if (v1589) {
        int * v1022 = v980->cache_tags;
        int v1023 = v1022[v1588];
        int * v1024 = v980->cache_vals;
        int v1592 = ((4 + ((((int)((unsigned int)((int)((unsigned int)v722 >> 2)) >> 1)) & 3) * 2)) + ((((v1015 + ((~(((v1017 ^ -1) | (-(v1017 ^ -1))) >> 31)) & 2)) - (v1018 + ((~(((v1019 ^ -1) | (-(v1019 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
        int v1025 = v1024[v1592];
        int v1593 = (((4 + ((((int)((unsigned int)((int)((unsigned int)v722 >> 2)) >> 1)) & 3) * 2)) + ((((v1015 + ((~(((v1017 ^ -1) | (-(v1017 ^ -1))) >> 31)) & 2)) - (v1018 + ((~(((v1019 ^ -1) | (-(v1019 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
        int v1026 = v1024[v1593];
        int * v1027 = v980->mem;
        int v1595 = v1023 * 2;
        v1027[v1595] = v1025;
        int * v1029 = v980->mem;
        int v1598 = (v1023 * 2) + 1;
        v1029[v1598] = v1026;
        ;
      } else {
        ;
      }
      int * v1034 = v980->mem;
      int v1603 = ((int)((unsigned int)((int)((unsigned int)v722 >> 2)) >> 1)) * 2;
      int v1035 = v1034[v1603];
      int v1604 = (((int)((unsigned int)((int)((unsigned int)v722 >> 2)) >> 1)) * 2) + 1;
      int v1036 = v1034[v1604];
      int * v1037 = v980->cache_vals;
      int v1606 = ((4 + ((((int)((unsigned int)((int)((unsigned int)v722 >> 2)) >> 1)) & 3) * 2)) + ((((v1015 + ((~(((v1017 ^ -1) | (-(v1017 ^ -1))) >> 31)) & 2)) - (v1018 + ((~(((v1019 ^ -1) | (-(v1019 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
      v1037[v1606] = v1035;
      int * v1039 = v980->cache_vals;
      int v1609 = (((4 + ((((int)((unsigned int)((int)((unsigned int)v722 >> 2)) >> 1)) & 3) * 2)) + ((((v1015 + ((~(((v1017 ^ -1) | (-(v1017 ^ -1))) >> 31)) & 2)) - (v1018 + ((~(((v1019 ^ -1) | (-(v1019 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
      v1039[v1609] = v1036;
      int * v1041 = v980->cache_tags;
      int v1612 = (int)((unsigned int)((int)((unsigned int)v722 >> 2)) >> 1);
      v1041[v1588] = v1612;
      int * v1043 = v980->cache_dirty;
      v1043[v1588] = 0;
      int * v1045 = v980->cache_age;
      v1045[v1588] = 1;
      int * v1047 = v980->cache_age;
      int v1048 = v1047[v1588];
      int v1049 = v1047[v1562];
      int v1618 = v1049 + ((int)((unsigned int)(v1049 - v1048) >> 31));
      v1047[v1562] = v1618;
      int * v1051 = v980->cache_age;
      int v1052 = v1051[v1563];
      int v1620 = v1052 + ((int)((unsigned int)(v1052 - v1048) >> 31));
      v1051[v1563] = v1620;
      int * v1054 = v980->cache_age;
      v1054[v1588] = 0;
      v1057 = v1588;
    }
    int * v1058 = v980->cache_vals;
    int v1623 = v1057 * 2;
    int v1059 = v1058[v1623];
    int v1624 = (v1057 * 2) + 1;
    int v1060 = v1058[v1624];
    int v1625 = (((((int)((unsigned int)((int)((unsigned int)v722 >> 2)) >> 1)) & 1) * 2) + ((((v999 + ((~(((v1001 ^ -1) | (-(v1001 ^ -1))) >> 31)) & 2)) - (v1002 + ((~(((v1003 ^ -1) | (-(v1003 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
    v1058[v1625] = v1059;
    int * v1062 = v980->cache_vals;
    int v1628 = ((((((int)((unsigned int)((int)((unsigned int)v722 >> 2)) >> 1)) & 1) * 2) + ((((v999 + ((~(((v1001 ^ -1) | (-(v1001 ^ -1))) >> 31)) & 2)) - (v1002 + ((~(((v1003 ^ -1) | (-(v1003 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
    v1062[v1628] = v1060;
    int * v1064 = v980->cache_tags;
    int v1631 = ((((int)((unsigned int)((int)((unsigned int)v722 >> 2)) >> 1)) & 1) * 2) + ((((v999 + ((~(((v1001 ^ -1) | (-(v1001 ^ -1))) >> 31)) & 2)) - (v1002 + ((~(((v1003 ^ -1) | (-(v1003 ^ -1))) >> 31)) & 2))) >> 31) & 1);
    int v1632 = (int)((unsigned int)((int)((unsigned int)v722 >> 2)) >> 1);
    v1064[v1631] = v1632;
    int * v1066 = v980->cache_dirty;
    v1066[v1631] = 0;
    int * v1068 = v980->cache_age;
    v1068[v1631] = 1;
    int * v1070 = v980->cache_age;
    int v1071 = v1070[v1631];
    int v1072 = v1070[v1560];
    int v1638 = v1072 + ((int)((unsigned int)(v1072 - v1071) >> 31));
    v1070[v1560] = v1638;
    int * v1074 = v980->cache_age;
    int v1075 = v1074[v1561];
    int v1640 = v1075 + ((int)((unsigned int)(v1075 - v1071) >> 31));
    v1074[v1561] = v1640;
    int * v1077 = v980->cache_age;
    v1077[v1631] = 0;
    v1080 = v1631;
  }
  int * v1081 = v980->cache_vals;
  int v1643 = (v1080 * 2) + (((int)((unsigned int)v722 >> 2)) & 1);
  v1081[v1643] = v723;
  int * v1083 = v980->cache_tags;
  int v1084 = v1083[v1562];
  int v1085 = v1083[v1563];
  bool v1646 = !(((~(((v1084 ^ ((int)((unsigned int)((int)((unsigned int)v722 >> 2)) >> 1))) | (-(v1084 ^ ((int)((unsigned int)((int)((unsigned int)v722 >> 2)) >> 1))))) >> 31)) | (~(((v1085 ^ ((int)((unsigned int)((int)((unsigned int)v722 >> 2)) >> 1))) | (-(v1085 ^ ((int)((unsigned int)((int)((unsigned int)v722 >> 2)) >> 1))))) >> 31))) == 0);
  int v1139;
  if (v1646) {
    int * v1086 = v980->cache_age;
    int v1648 = (4 + ((((int)((unsigned int)((int)((unsigned int)v722 >> 2)) >> 1)) & 3) * 2)) + ((~(((v1085 ^ ((int)((unsigned int)((int)((unsigned int)v722 >> 2)) >> 1))) | (-(v1085 ^ ((int)((unsigned int)((int)((unsigned int)v722 >> 2)) >> 1))))) >> 31)) & 1);
    int v1087 = v1086[v1648];
    int v1088 = v1086[v1562];
    int v1649 = v1088 + ((int)((unsigned int)(v1088 - v1087) >> 31));
    v1086[v1562] = v1649;
    int * v1090 = v980->cache_age;
    int v1091 = v1090[v1563];
    int v1651 = v1091 + ((int)((unsigned int)(v1091 - v1087) >> 31));
    v1090[v1563] = v1651;
    int * v1093 = v980->cache_age;
    v1093[v1648] = 0;
    v1139 = v1648;
  } else {
    int * v1096 = v980->cache_age;
    int v1655 = 4 + ((((int)((unsigned int)((int)((unsigned int)v722 >> 2)) >> 1)) & 3) * 2);
    int v1097 = v1096[v1655];
    int * v1098 = v980->cache_tags;
    int v1099 = v1098[v1655];
    int v1100 = v1096[v1563];
    int v1101 = v1098[v1563];
    int * v1102 = v980->cache_dirty;
    int v1658 = (4 + ((((int)((unsigned int)((int)((unsigned int)v722 >> 2)) >> 1)) & 3) * 2)) + ((((v1097 + ((~(((v1099 ^ -1) | (-(v1099 ^ -1))) >> 31)) & 2)) - (v1100 + ((~(((v1101 ^ -1) | (-(v1101 ^ -1))) >> 31)) & 2))) >> 31) & 1);
    int v1103 = v1102[v1658];
    bool v1659 = !(v1103 == 0);
    if (v1659) {
      int * v1104 = v980->cache_tags;
      int v1105 = v1104[v1658];
      int * v1106 = v980->cache_vals;
      int v1662 = ((4 + ((((int)((unsigned int)((int)((unsigned int)v722 >> 2)) >> 1)) & 3) * 2)) + ((((v1097 + ((~(((v1099 ^ -1) | (-(v1099 ^ -1))) >> 31)) & 2)) - (v1100 + ((~(((v1101 ^ -1) | (-(v1101 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
      int v1107 = v1106[v1662];
      int v1663 = (((4 + ((((int)((unsigned int)((int)((unsigned int)v722 >> 2)) >> 1)) & 3) * 2)) + ((((v1097 + ((~(((v1099 ^ -1) | (-(v1099 ^ -1))) >> 31)) & 2)) - (v1100 + ((~(((v1101 ^ -1) | (-(v1101 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
      int v1108 = v1106[v1663];
      int * v1109 = v980->mem;
      int v1665 = v1105 * 2;
      v1109[v1665] = v1107;
      int * v1111 = v980->mem;
      int v1668 = (v1105 * 2) + 1;
      v1111[v1668] = v1108;
      ;
    } else {
      ;
    }
    int * v1116 = v980->mem;
    int v1673 = ((int)((unsigned int)((int)((unsigned int)v722 >> 2)) >> 1)) * 2;
    int v1117 = v1116[v1673];
    int v1674 = (((int)((unsigned int)((int)((unsigned int)v722 >> 2)) >> 1)) * 2) + 1;
    int v1118 = v1116[v1674];
    int * v1119 = v980->cache_vals;
    int v1676 = ((4 + ((((int)((unsigned int)((int)((unsigned int)v722 >> 2)) >> 1)) & 3) * 2)) + ((((v1097 + ((~(((v1099 ^ -1) | (-(v1099 ^ -1))) >> 31)) & 2)) - (v1100 + ((~(((v1101 ^ -1) | (-(v1101 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
    v1119[v1676] = v1117;
    int * v1121 = v980->cache_vals;
    int v1679 = (((4 + ((((int)((unsigned int)((int)((unsigned int)v722 >> 2)) >> 1)) & 3) * 2)) + ((((v1097 + ((~(((v1099 ^ -1) | (-(v1099 ^ -1))) >> 31)) & 2)) - (v1100 + ((~(((v1101 ^ -1) | (-(v1101 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
    v1121[v1679] = v1118;
    int * v1123 = v980->cache_tags;
    int v1682 = (int)((unsigned int)((int)((unsigned int)v722 >> 2)) >> 1);
    v1123[v1658] = v1682;
    int * v1125 = v980->cache_dirty;
    v1125[v1658] = 0;
    int * v1127 = v980->cache_age;
    v1127[v1658] = 1;
    int * v1129 = v980->cache_age;
    int v1130 = v1129[v1658];
    int v1131 = v1129[v1562];
    int v1688 = v1131 + ((int)((unsigned int)(v1131 - v1130) >> 31));
    v1129[v1562] = v1688;
    int * v1133 = v980->cache_age;
    int v1134 = v1133[v1563];
    int v1690 = v1134 + ((int)((unsigned int)(v1134 - v1130) >> 31));
    v1133[v1563] = v1690;
    int * v1136 = v980->cache_age;
    v1136[v1658] = 0;
    v1139 = v1658;
  }
  int * v1140 = v980->cache_vals;
  int v1693 = (v1139 * 2) + (((int)((unsigned int)v722 >> 2)) & 1);
  v1140[v1693] = v723;
  int * v1142 = v980->cache_dirty;
  v1142[v1139] = 1;
  struct StateT * v1144 = v707->b;
  int * v1145 = v1144->cache_tags;
  int v1699 = (((int)((unsigned int)((int)((unsigned int)v726 >> 2)) >> 1)) & 1) * 2;
  int v1146 = v1145[v1699];
  int v1700 = ((((int)((unsigned int)((int)((unsigned int)v726 >> 2)) >> 1)) & 1) * 2) + 1;
  int v1147 = v1145[v1700];
  int v1701 = 4 + ((((int)((unsigned int)((int)((unsigned int)v726 >> 2)) >> 1)) & 3) * 2);
  int v1148 = v1145[v1701];
  int v1702 = (4 + ((((int)((unsigned int)((int)((unsigned int)v726 >> 2)) >> 1)) & 3) * 2)) + 1;
  int v1149 = v1145[v1702];
  int v1150 = v1144->timer;
  int v1703 = v1150 + ((100 ^ (((~(((v1148 ^ ((int)((unsigned int)((int)((unsigned int)v726 >> 2)) >> 1))) | (-(v1148 ^ ((int)((unsigned int)((int)((unsigned int)v726 >> 2)) >> 1))))) >> 31)) | (~(((v1149 ^ ((int)((unsigned int)((int)((unsigned int)v726 >> 2)) >> 1))) | (-(v1149 ^ ((int)((unsigned int)((int)((unsigned int)v726 >> 2)) >> 1))))) >> 31))) & 104)) ^ (((~(((v1146 ^ ((int)((unsigned int)((int)((unsigned int)v726 >> 2)) >> 1))) | (-(v1146 ^ ((int)((unsigned int)((int)((unsigned int)v726 >> 2)) >> 1))))) >> 31)) | (~(((v1147 ^ ((int)((unsigned int)((int)((unsigned int)v726 >> 2)) >> 1))) | (-(v1147 ^ ((int)((unsigned int)((int)((unsigned int)v726 >> 2)) >> 1))))) >> 31))) & (1 ^ (100 ^ (((~(((v1148 ^ ((int)((unsigned int)((int)((unsigned int)v726 >> 2)) >> 1))) | (-(v1148 ^ ((int)((unsigned int)((int)((unsigned int)v726 >> 2)) >> 1))))) >> 31)) | (~(((v1149 ^ ((int)((unsigned int)((int)((unsigned int)v726 >> 2)) >> 1))) | (-(v1149 ^ ((int)((unsigned int)((int)((unsigned int)v726 >> 2)) >> 1))))) >> 31))) & 104)))));
  v1144->timer = v1703;
  bool v1704 = !(((~(((v1146 ^ ((int)((unsigned int)((int)((unsigned int)v726 >> 2)) >> 1))) | (-(v1146 ^ ((int)((unsigned int)((int)((unsigned int)v726 >> 2)) >> 1))))) >> 31)) | (~(((v1147 ^ ((int)((unsigned int)((int)((unsigned int)v726 >> 2)) >> 1))) | (-(v1147 ^ ((int)((unsigned int)((int)((unsigned int)v726 >> 2)) >> 1))))) >> 31))) == 0);
  int v1244;
  if (v1704) {
    int * v1152 = v1144->cache_age;
    int v1706 = ((((int)((unsigned int)((int)((unsigned int)v726 >> 2)) >> 1)) & 1) * 2) + ((~(((v1147 ^ ((int)((unsigned int)((int)((unsigned int)v726 >> 2)) >> 1))) | (-(v1147 ^ ((int)((unsigned int)((int)((unsigned int)v726 >> 2)) >> 1))))) >> 31)) & 1);
    int v1153 = v1152[v1706];
    int v1154 = v1152[v1699];
    int v1707 = v1154 + ((int)((unsigned int)(v1154 - v1153) >> 31));
    v1152[v1699] = v1707;
    int * v1156 = v1144->cache_age;
    int v1157 = v1156[v1700];
    int v1709 = v1157 + ((int)((unsigned int)(v1157 - v1153) >> 31));
    v1156[v1700] = v1709;
    int * v1159 = v1144->cache_age;
    v1159[v1706] = 0;
    v1244 = v1706;
  } else {
    int * v1162 = v1144->cache_age;
    int v1713 = (((int)((unsigned int)((int)((unsigned int)v726 >> 2)) >> 1)) & 1) * 2;
    int v1163 = v1162[v1713];
    int * v1164 = v1144->cache_tags;
    int v1165 = v1164[v1713];
    int v1166 = v1162[v1700];
    int v1167 = v1164[v1700];
    bool v1715 = !(((~(((v1148 ^ ((int)((unsigned int)((int)((unsigned int)v726 >> 2)) >> 1))) | (-(v1148 ^ ((int)((unsigned int)((int)((unsigned int)v726 >> 2)) >> 1))))) >> 31)) | (~(((v1149 ^ ((int)((unsigned int)((int)((unsigned int)v726 >> 2)) >> 1))) | (-(v1149 ^ ((int)((unsigned int)((int)((unsigned int)v726 >> 2)) >> 1))))) >> 31))) == 0);
    int v1221;
    if (v1715) {
      int * v1168 = v1144->cache_age;
      int v1717 = (4 + ((((int)((unsigned int)((int)((unsigned int)v726 >> 2)) >> 1)) & 3) * 2)) + ((~(((v1149 ^ ((int)((unsigned int)((int)((unsigned int)v726 >> 2)) >> 1))) | (-(v1149 ^ ((int)((unsigned int)((int)((unsigned int)v726 >> 2)) >> 1))))) >> 31)) & 1);
      int v1169 = v1168[v1717];
      int v1170 = v1168[v1701];
      int v1718 = v1170 + ((int)((unsigned int)(v1170 - v1169) >> 31));
      v1168[v1701] = v1718;
      int * v1172 = v1144->cache_age;
      int v1173 = v1172[v1702];
      int v1720 = v1173 + ((int)((unsigned int)(v1173 - v1169) >> 31));
      v1172[v1702] = v1720;
      int * v1175 = v1144->cache_age;
      v1175[v1717] = 0;
      v1221 = v1717;
    } else {
      int * v1178 = v1144->cache_age;
      int v1724 = 4 + ((((int)((unsigned int)((int)((unsigned int)v726 >> 2)) >> 1)) & 3) * 2);
      int v1179 = v1178[v1724];
      int * v1180 = v1144->cache_tags;
      int v1181 = v1180[v1724];
      int v1182 = v1178[v1702];
      int v1183 = v1180[v1702];
      int * v1184 = v1144->cache_dirty;
      int v1727 = (4 + ((((int)((unsigned int)((int)((unsigned int)v726 >> 2)) >> 1)) & 3) * 2)) + ((((v1179 + ((~(((v1181 ^ -1) | (-(v1181 ^ -1))) >> 31)) & 2)) - (v1182 + ((~(((v1183 ^ -1) | (-(v1183 ^ -1))) >> 31)) & 2))) >> 31) & 1);
      int v1185 = v1184[v1727];
      bool v1728 = !(v1185 == 0);
      if (v1728) {
        int * v1186 = v1144->cache_tags;
        int v1187 = v1186[v1727];
        int * v1188 = v1144->cache_vals;
        int v1731 = ((4 + ((((int)((unsigned int)((int)((unsigned int)v726 >> 2)) >> 1)) & 3) * 2)) + ((((v1179 + ((~(((v1181 ^ -1) | (-(v1181 ^ -1))) >> 31)) & 2)) - (v1182 + ((~(((v1183 ^ -1) | (-(v1183 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
        int v1189 = v1188[v1731];
        int v1732 = (((4 + ((((int)((unsigned int)((int)((unsigned int)v726 >> 2)) >> 1)) & 3) * 2)) + ((((v1179 + ((~(((v1181 ^ -1) | (-(v1181 ^ -1))) >> 31)) & 2)) - (v1182 + ((~(((v1183 ^ -1) | (-(v1183 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
        int v1190 = v1188[v1732];
        int * v1191 = v1144->mem;
        int v1734 = v1187 * 2;
        v1191[v1734] = v1189;
        int * v1193 = v1144->mem;
        int v1737 = (v1187 * 2) + 1;
        v1193[v1737] = v1190;
        ;
      } else {
        ;
      }
      int * v1198 = v1144->mem;
      int v1742 = ((int)((unsigned int)((int)((unsigned int)v726 >> 2)) >> 1)) * 2;
      int v1199 = v1198[v1742];
      int v1743 = (((int)((unsigned int)((int)((unsigned int)v726 >> 2)) >> 1)) * 2) + 1;
      int v1200 = v1198[v1743];
      int * v1201 = v1144->cache_vals;
      int v1745 = ((4 + ((((int)((unsigned int)((int)((unsigned int)v726 >> 2)) >> 1)) & 3) * 2)) + ((((v1179 + ((~(((v1181 ^ -1) | (-(v1181 ^ -1))) >> 31)) & 2)) - (v1182 + ((~(((v1183 ^ -1) | (-(v1183 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
      v1201[v1745] = v1199;
      int * v1203 = v1144->cache_vals;
      int v1748 = (((4 + ((((int)((unsigned int)((int)((unsigned int)v726 >> 2)) >> 1)) & 3) * 2)) + ((((v1179 + ((~(((v1181 ^ -1) | (-(v1181 ^ -1))) >> 31)) & 2)) - (v1182 + ((~(((v1183 ^ -1) | (-(v1183 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
      v1203[v1748] = v1200;
      int * v1205 = v1144->cache_tags;
      int v1751 = (int)((unsigned int)((int)((unsigned int)v726 >> 2)) >> 1);
      v1205[v1727] = v1751;
      int * v1207 = v1144->cache_dirty;
      v1207[v1727] = 0;
      int * v1209 = v1144->cache_age;
      v1209[v1727] = 1;
      int * v1211 = v1144->cache_age;
      int v1212 = v1211[v1727];
      int v1213 = v1211[v1701];
      int v1756 = v1213 + ((int)((unsigned int)(v1213 - v1212) >> 31));
      v1211[v1701] = v1756;
      int * v1215 = v1144->cache_age;
      int v1216 = v1215[v1702];
      int v1758 = v1216 + ((int)((unsigned int)(v1216 - v1212) >> 31));
      v1215[v1702] = v1758;
      int * v1218 = v1144->cache_age;
      v1218[v1727] = 0;
      v1221 = v1727;
    }
    int * v1222 = v1144->cache_vals;
    int v1761 = v1221 * 2;
    int v1223 = v1222[v1761];
    int v1762 = (v1221 * 2) + 1;
    int v1224 = v1222[v1762];
    int v1763 = (((((int)((unsigned int)((int)((unsigned int)v726 >> 2)) >> 1)) & 1) * 2) + ((((v1163 + ((~(((v1165 ^ -1) | (-(v1165 ^ -1))) >> 31)) & 2)) - (v1166 + ((~(((v1167 ^ -1) | (-(v1167 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
    v1222[v1763] = v1223;
    int * v1226 = v1144->cache_vals;
    int v1766 = ((((((int)((unsigned int)((int)((unsigned int)v726 >> 2)) >> 1)) & 1) * 2) + ((((v1163 + ((~(((v1165 ^ -1) | (-(v1165 ^ -1))) >> 31)) & 2)) - (v1166 + ((~(((v1167 ^ -1) | (-(v1167 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
    v1226[v1766] = v1224;
    int * v1228 = v1144->cache_tags;
    int v1769 = ((((int)((unsigned int)((int)((unsigned int)v726 >> 2)) >> 1)) & 1) * 2) + ((((v1163 + ((~(((v1165 ^ -1) | (-(v1165 ^ -1))) >> 31)) & 2)) - (v1166 + ((~(((v1167 ^ -1) | (-(v1167 ^ -1))) >> 31)) & 2))) >> 31) & 1);
    int v1770 = (int)((unsigned int)((int)((unsigned int)v726 >> 2)) >> 1);
    v1228[v1769] = v1770;
    int * v1230 = v1144->cache_dirty;
    v1230[v1769] = 0;
    int * v1232 = v1144->cache_age;
    v1232[v1769] = 1;
    int * v1234 = v1144->cache_age;
    int v1235 = v1234[v1769];
    int v1236 = v1234[v1699];
    int v1775 = v1236 + ((int)((unsigned int)(v1236 - v1235) >> 31));
    v1234[v1699] = v1775;
    int * v1238 = v1144->cache_age;
    int v1239 = v1238[v1700];
    int v1777 = v1239 + ((int)((unsigned int)(v1239 - v1235) >> 31));
    v1238[v1700] = v1777;
    int * v1241 = v1144->cache_age;
    v1241[v1769] = 0;
    v1244 = v1769;
  }
  int * v1245 = v1144->cache_vals;
  int v1780 = (v1244 * 2) + (((int)((unsigned int)v726 >> 2)) & 1);
  v1245[v1780] = v727;
  int * v1247 = v1144->cache_tags;
  int v1248 = v1247[v1701];
  int v1249 = v1247[v1702];
  bool v1783 = !(((~(((v1248 ^ ((int)((unsigned int)((int)((unsigned int)v726 >> 2)) >> 1))) | (-(v1248 ^ ((int)((unsigned int)((int)((unsigned int)v726 >> 2)) >> 1))))) >> 31)) | (~(((v1249 ^ ((int)((unsigned int)((int)((unsigned int)v726 >> 2)) >> 1))) | (-(v1249 ^ ((int)((unsigned int)((int)((unsigned int)v726 >> 2)) >> 1))))) >> 31))) == 0);
  int v1303;
  if (v1783) {
    int * v1250 = v1144->cache_age;
    int v1785 = (4 + ((((int)((unsigned int)((int)((unsigned int)v726 >> 2)) >> 1)) & 3) * 2)) + ((~(((v1249 ^ ((int)((unsigned int)((int)((unsigned int)v726 >> 2)) >> 1))) | (-(v1249 ^ ((int)((unsigned int)((int)((unsigned int)v726 >> 2)) >> 1))))) >> 31)) & 1);
    int v1251 = v1250[v1785];
    int v1252 = v1250[v1701];
    int v1786 = v1252 + ((int)((unsigned int)(v1252 - v1251) >> 31));
    v1250[v1701] = v1786;
    int * v1254 = v1144->cache_age;
    int v1255 = v1254[v1702];
    int v1788 = v1255 + ((int)((unsigned int)(v1255 - v1251) >> 31));
    v1254[v1702] = v1788;
    int * v1257 = v1144->cache_age;
    v1257[v1785] = 0;
    v1303 = v1785;
  } else {
    int * v1260 = v1144->cache_age;
    int v1792 = 4 + ((((int)((unsigned int)((int)((unsigned int)v726 >> 2)) >> 1)) & 3) * 2);
    int v1261 = v1260[v1792];
    int * v1262 = v1144->cache_tags;
    int v1263 = v1262[v1792];
    int v1264 = v1260[v1702];
    int v1265 = v1262[v1702];
    int * v1266 = v1144->cache_dirty;
    int v1795 = (4 + ((((int)((unsigned int)((int)((unsigned int)v726 >> 2)) >> 1)) & 3) * 2)) + ((((v1261 + ((~(((v1263 ^ -1) | (-(v1263 ^ -1))) >> 31)) & 2)) - (v1264 + ((~(((v1265 ^ -1) | (-(v1265 ^ -1))) >> 31)) & 2))) >> 31) & 1);
    int v1267 = v1266[v1795];
    bool v1796 = !(v1267 == 0);
    if (v1796) {
      int * v1268 = v1144->cache_tags;
      int v1269 = v1268[v1795];
      int * v1270 = v1144->cache_vals;
      int v1799 = ((4 + ((((int)((unsigned int)((int)((unsigned int)v726 >> 2)) >> 1)) & 3) * 2)) + ((((v1261 + ((~(((v1263 ^ -1) | (-(v1263 ^ -1))) >> 31)) & 2)) - (v1264 + ((~(((v1265 ^ -1) | (-(v1265 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
      int v1271 = v1270[v1799];
      int v1800 = (((4 + ((((int)((unsigned int)((int)((unsigned int)v726 >> 2)) >> 1)) & 3) * 2)) + ((((v1261 + ((~(((v1263 ^ -1) | (-(v1263 ^ -1))) >> 31)) & 2)) - (v1264 + ((~(((v1265 ^ -1) | (-(v1265 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
      int v1272 = v1270[v1800];
      int * v1273 = v1144->mem;
      int v1802 = v1269 * 2;
      v1273[v1802] = v1271;
      int * v1275 = v1144->mem;
      int v1805 = (v1269 * 2) + 1;
      v1275[v1805] = v1272;
      ;
    } else {
      ;
    }
    int * v1280 = v1144->mem;
    int v1810 = ((int)((unsigned int)((int)((unsigned int)v726 >> 2)) >> 1)) * 2;
    int v1281 = v1280[v1810];
    int v1811 = (((int)((unsigned int)((int)((unsigned int)v726 >> 2)) >> 1)) * 2) + 1;
    int v1282 = v1280[v1811];
    int * v1283 = v1144->cache_vals;
    int v1813 = ((4 + ((((int)((unsigned int)((int)((unsigned int)v726 >> 2)) >> 1)) & 3) * 2)) + ((((v1261 + ((~(((v1263 ^ -1) | (-(v1263 ^ -1))) >> 31)) & 2)) - (v1264 + ((~(((v1265 ^ -1) | (-(v1265 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
    v1283[v1813] = v1281;
    int * v1285 = v1144->cache_vals;
    int v1816 = (((4 + ((((int)((unsigned int)((int)((unsigned int)v726 >> 2)) >> 1)) & 3) * 2)) + ((((v1261 + ((~(((v1263 ^ -1) | (-(v1263 ^ -1))) >> 31)) & 2)) - (v1264 + ((~(((v1265 ^ -1) | (-(v1265 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
    v1285[v1816] = v1282;
    int * v1287 = v1144->cache_tags;
    int v1819 = (int)((unsigned int)((int)((unsigned int)v726 >> 2)) >> 1);
    v1287[v1795] = v1819;
    int * v1289 = v1144->cache_dirty;
    v1289[v1795] = 0;
    int * v1291 = v1144->cache_age;
    v1291[v1795] = 1;
    int * v1293 = v1144->cache_age;
    int v1294 = v1293[v1795];
    int v1295 = v1293[v1701];
    int v1824 = v1295 + ((int)((unsigned int)(v1295 - v1294) >> 31));
    v1293[v1701] = v1824;
    int * v1297 = v1144->cache_age;
    int v1298 = v1297[v1702];
    int v1826 = v1298 + ((int)((unsigned int)(v1298 - v1294) >> 31));
    v1297[v1702] = v1826;
    int * v1300 = v1144->cache_age;
    v1300[v1795] = 0;
    v1303 = v1795;
  }
  int * v1304 = v1144->cache_vals;
  int v1829 = (v1303 * 2) + (((int)((unsigned int)v726 >> 2)) & 1);
  v1304[v1829] = v727;
  int * v1306 = v1144->cache_dirty;
  v1306[v1303] = 1;
  bool v1832 = (((int)((unsigned int)v744 >> 2)) == ((int)((unsigned int)v722 >> 2))) == (((int)((unsigned int)v851 >> 2)) == ((int)((unsigned int)v726 >> 2)));
  squared_diverged(v1832);
  squared_assume(v1832);
  bool v1833 = ((int)((unsigned int)v744 >> 2)) == ((int)((unsigned int)v722 >> 2));
  struct StateT2 * v1336;
  if (v1833) {
    struct StateT * v1310 = v707->a;
    int v1311 = v1310->timer;
    int v1835 = v1311 + 15;
    v1310->timer = v1835;
    int * v1313 = v1310->saved_regs;
    int v1314 = v1313[11];
    int * v1315 = v1310->regs;
    v1315[11] = v1314;
    int * v1317 = v1310->saved_regs;
    int v1318 = v1317[6];
    int * v1319 = v1310->regs;
    v1319[6] = v1318;
    struct StateT * v1321 = v707->b;
    int v1322 = v1321->timer;
    int v1843 = v1322 + 15;
    v1321->timer = v1843;
    int * v1324 = v1321->saved_regs;
    int v1325 = v1324[11];
    int * v1326 = v1321->regs;
    v1326[11] = v1325;
    int * v1328 = v1321->saved_regs;
    int v1329 = v1328[6];
    int * v1330 = v1321->regs;
    v1330[6] = v1329;
    struct StateT2 * v1332 = slot_9(v707);
    v1336 = v1332;
  } else {
    struct StateT2 * v1334 = slot_11(v707);
    v1336 = v1334;
  }
  return v1336;
}

struct StateT2 * slot_4(struct StateT2 * v134) {
  struct StateT * v135 = v134->a;
  int v136 = v135->timer;
  struct StateT * v137 = v134->b;
  int v138 = v137->timer;
  bool v171 = v136 == v138;
  squared_assert(v171);
  squared_assume(v171);
  struct StateT * v141 = v134->a;
  int * v142 = v141->saved_regs;
  int * v143 = v141->regs;
  int v144 = v143[8];
  v142[8] = v144;
  struct StateT * v146 = v134->b;
  int * v147 = v146->saved_regs;
  int * v148 = v146->regs;
  int v149 = v148[8];
  v147[8] = v149;
  struct StateT * v151 = v134->a;
  int v152 = v151->timer;
  int v182 = v152 + 1;
  v151->timer = v182;
  struct StateT * v154 = v134->b;
  int v155 = v154->timer;
  int v184 = v155 + 1;
  v154->timer = v184;
  struct StateT * v157 = v134->a;
  int * v158 = v157->regs;
  int v159 = v158[9];
  int v160 = v158[6];
  int v189 = v159 + v160;
  v158[8] = v189;
  struct StateT * v162 = v134->b;
  int * v163 = v162->regs;
  int v164 = v163[9];
  int v165 = v163[6];
  int v192 = v164 + v165;
  v163[8] = v192;
  struct StateT2 * v167 = slot_14(v134);
  return v167;
}

struct StateT2 * slot_9(struct StateT2 * v1855) {
  struct StateT * v1856 = v1855->a;
  int v1857 = v1856->timer;
  struct StateT * v1858 = v1855->b;
  int v1859 = v1858->timer;
  bool v2086 = v1857 == v1859;
  squared_assert(v2086);
  squared_assume(v2086);
  struct StateT * v1862 = v1855->a;
  int v1863 = v1862->timer;
  int v2088 = v1863 + 1;
  v1862->timer = v2088;
  struct StateT * v1865 = v1855->b;
  int v1866 = v1865->timer;
  int v2090 = v1866 + 1;
  v1865->timer = v2090;
  struct StateT * v1868 = v1855->a;
  int * v1869 = v1868->regs;
  int v1870 = v1869[6];
  int * v1871 = v1868->cache_tags;
  int v2095 = (((int)((unsigned int)((int)((unsigned int)v1870 >> 2)) >> 1)) & 1) * 2;
  int v1872 = v1871[v2095];
  int v2096 = ((((int)((unsigned int)((int)((unsigned int)v1870 >> 2)) >> 1)) & 1) * 2) + 1;
  int v1873 = v1871[v2096];
  int v2097 = 4 + ((((int)((unsigned int)((int)((unsigned int)v1870 >> 2)) >> 1)) & 3) * 2);
  int v1874 = v1871[v2097];
  int v2098 = (4 + ((((int)((unsigned int)((int)((unsigned int)v1870 >> 2)) >> 1)) & 3) * 2)) + 1;
  int v1875 = v1871[v2098];
  int v1876 = v1868->timer;
  int v2099 = v1876 + ((100 ^ (((~(((v1874 ^ ((int)((unsigned int)((int)((unsigned int)v1870 >> 2)) >> 1))) | (-(v1874 ^ ((int)((unsigned int)((int)((unsigned int)v1870 >> 2)) >> 1))))) >> 31)) | (~(((v1875 ^ ((int)((unsigned int)((int)((unsigned int)v1870 >> 2)) >> 1))) | (-(v1875 ^ ((int)((unsigned int)((int)((unsigned int)v1870 >> 2)) >> 1))))) >> 31))) & 104)) ^ (((~(((v1872 ^ ((int)((unsigned int)((int)((unsigned int)v1870 >> 2)) >> 1))) | (-(v1872 ^ ((int)((unsigned int)((int)((unsigned int)v1870 >> 2)) >> 1))))) >> 31)) | (~(((v1873 ^ ((int)((unsigned int)((int)((unsigned int)v1870 >> 2)) >> 1))) | (-(v1873 ^ ((int)((unsigned int)((int)((unsigned int)v1870 >> 2)) >> 1))))) >> 31))) & (1 ^ (100 ^ (((~(((v1874 ^ ((int)((unsigned int)((int)((unsigned int)v1870 >> 2)) >> 1))) | (-(v1874 ^ ((int)((unsigned int)((int)((unsigned int)v1870 >> 2)) >> 1))))) >> 31)) | (~(((v1875 ^ ((int)((unsigned int)((int)((unsigned int)v1870 >> 2)) >> 1))) | (-(v1875 ^ ((int)((unsigned int)((int)((unsigned int)v1870 >> 2)) >> 1))))) >> 31))) & 104)))));
  v1868->timer = v2099;
  int * v1878 = v1868->cache_vals;
  bool v2100 = !(((~(((v1872 ^ ((int)((unsigned int)((int)((unsigned int)v1870 >> 2)) >> 1))) | (-(v1872 ^ ((int)((unsigned int)((int)((unsigned int)v1870 >> 2)) >> 1))))) >> 31)) | (~(((v1873 ^ ((int)((unsigned int)((int)((unsigned int)v1870 >> 2)) >> 1))) | (-(v1873 ^ ((int)((unsigned int)((int)((unsigned int)v1870 >> 2)) >> 1))))) >> 31))) == 0);
  int v1971;
  if (v2100) {
    int * v1879 = v1868->cache_age;
    int v2102 = ((((int)((unsigned int)((int)((unsigned int)v1870 >> 2)) >> 1)) & 1) * 2) + ((~(((v1873 ^ ((int)((unsigned int)((int)((unsigned int)v1870 >> 2)) >> 1))) | (-(v1873 ^ ((int)((unsigned int)((int)((unsigned int)v1870 >> 2)) >> 1))))) >> 31)) & 1);
    int v1880 = v1879[v2102];
    int v1881 = v1879[v2095];
    int v2103 = v1881 + ((int)((unsigned int)(v1881 - v1880) >> 31));
    v1879[v2095] = v2103;
    int * v1883 = v1868->cache_age;
    int v1884 = v1883[v2096];
    int v2105 = v1884 + ((int)((unsigned int)(v1884 - v1880) >> 31));
    v1883[v2096] = v2105;
    int * v1886 = v1868->cache_age;
    v1886[v2102] = 0;
    v1971 = v2102;
  } else {
    int * v1889 = v1868->cache_age;
    int v2109 = (((int)((unsigned int)((int)((unsigned int)v1870 >> 2)) >> 1)) & 1) * 2;
    int v1890 = v1889[v2109];
    int * v1891 = v1868->cache_tags;
    int v1892 = v1891[v2109];
    int v1893 = v1889[v2096];
    int v1894 = v1891[v2096];
    bool v2111 = !(((~(((v1874 ^ ((int)((unsigned int)((int)((unsigned int)v1870 >> 2)) >> 1))) | (-(v1874 ^ ((int)((unsigned int)((int)((unsigned int)v1870 >> 2)) >> 1))))) >> 31)) | (~(((v1875 ^ ((int)((unsigned int)((int)((unsigned int)v1870 >> 2)) >> 1))) | (-(v1875 ^ ((int)((unsigned int)((int)((unsigned int)v1870 >> 2)) >> 1))))) >> 31))) == 0);
    int v1948;
    if (v2111) {
      int * v1895 = v1868->cache_age;
      int v2113 = (4 + ((((int)((unsigned int)((int)((unsigned int)v1870 >> 2)) >> 1)) & 3) * 2)) + ((~(((v1875 ^ ((int)((unsigned int)((int)((unsigned int)v1870 >> 2)) >> 1))) | (-(v1875 ^ ((int)((unsigned int)((int)((unsigned int)v1870 >> 2)) >> 1))))) >> 31)) & 1);
      int v1896 = v1895[v2113];
      int v1897 = v1895[v2097];
      int v2114 = v1897 + ((int)((unsigned int)(v1897 - v1896) >> 31));
      v1895[v2097] = v2114;
      int * v1899 = v1868->cache_age;
      int v1900 = v1899[v2098];
      int v2116 = v1900 + ((int)((unsigned int)(v1900 - v1896) >> 31));
      v1899[v2098] = v2116;
      int * v1902 = v1868->cache_age;
      v1902[v2113] = 0;
      v1948 = v2113;
    } else {
      int * v1905 = v1868->cache_age;
      int v2120 = 4 + ((((int)((unsigned int)((int)((unsigned int)v1870 >> 2)) >> 1)) & 3) * 2);
      int v1906 = v1905[v2120];
      int * v1907 = v1868->cache_tags;
      int v1908 = v1907[v2120];
      int v1909 = v1905[v2098];
      int v1910 = v1907[v2098];
      int * v1911 = v1868->cache_dirty;
      int v2123 = (4 + ((((int)((unsigned int)((int)((unsigned int)v1870 >> 2)) >> 1)) & 3) * 2)) + ((((v1906 + ((~(((v1908 ^ -1) | (-(v1908 ^ -1))) >> 31)) & 2)) - (v1909 + ((~(((v1910 ^ -1) | (-(v1910 ^ -1))) >> 31)) & 2))) >> 31) & 1);
      int v1912 = v1911[v2123];
      bool v2124 = !(v1912 == 0);
      if (v2124) {
        int * v1913 = v1868->cache_tags;
        int v1914 = v1913[v2123];
        int * v1915 = v1868->cache_vals;
        int v2127 = ((4 + ((((int)((unsigned int)((int)((unsigned int)v1870 >> 2)) >> 1)) & 3) * 2)) + ((((v1906 + ((~(((v1908 ^ -1) | (-(v1908 ^ -1))) >> 31)) & 2)) - (v1909 + ((~(((v1910 ^ -1) | (-(v1910 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
        int v1916 = v1915[v2127];
        int v2128 = (((4 + ((((int)((unsigned int)((int)((unsigned int)v1870 >> 2)) >> 1)) & 3) * 2)) + ((((v1906 + ((~(((v1908 ^ -1) | (-(v1908 ^ -1))) >> 31)) & 2)) - (v1909 + ((~(((v1910 ^ -1) | (-(v1910 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
        int v1917 = v1915[v2128];
        int * v1918 = v1868->mem;
        int v2130 = v1914 * 2;
        v1918[v2130] = v1916;
        int * v1920 = v1868->mem;
        int v2133 = (v1914 * 2) + 1;
        v1920[v2133] = v1917;
        ;
      } else {
        ;
      }
      int * v1925 = v1868->mem;
      int v2138 = ((int)((unsigned int)((int)((unsigned int)v1870 >> 2)) >> 1)) * 2;
      int v1926 = v1925[v2138];
      int v2139 = (((int)((unsigned int)((int)((unsigned int)v1870 >> 2)) >> 1)) * 2) + 1;
      int v1927 = v1925[v2139];
      int * v1928 = v1868->cache_vals;
      int v2141 = ((4 + ((((int)((unsigned int)((int)((unsigned int)v1870 >> 2)) >> 1)) & 3) * 2)) + ((((v1906 + ((~(((v1908 ^ -1) | (-(v1908 ^ -1))) >> 31)) & 2)) - (v1909 + ((~(((v1910 ^ -1) | (-(v1910 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
      v1928[v2141] = v1926;
      int * v1930 = v1868->cache_vals;
      int v2144 = (((4 + ((((int)((unsigned int)((int)((unsigned int)v1870 >> 2)) >> 1)) & 3) * 2)) + ((((v1906 + ((~(((v1908 ^ -1) | (-(v1908 ^ -1))) >> 31)) & 2)) - (v1909 + ((~(((v1910 ^ -1) | (-(v1910 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
      v1930[v2144] = v1927;
      int * v1932 = v1868->cache_tags;
      int v2147 = (int)((unsigned int)((int)((unsigned int)v1870 >> 2)) >> 1);
      v1932[v2123] = v2147;
      int * v1934 = v1868->cache_dirty;
      v1934[v2123] = 0;
      int * v1936 = v1868->cache_age;
      v1936[v2123] = 1;
      int * v1938 = v1868->cache_age;
      int v1939 = v1938[v2123];
      int v1940 = v1938[v2097];
      int v2153 = v1940 + ((int)((unsigned int)(v1940 - v1939) >> 31));
      v1938[v2097] = v2153;
      int * v1942 = v1868->cache_age;
      int v1943 = v1942[v2098];
      int v2155 = v1943 + ((int)((unsigned int)(v1943 - v1939) >> 31));
      v1942[v2098] = v2155;
      int * v1945 = v1868->cache_age;
      v1945[v2123] = 0;
      v1948 = v2123;
    }
    int * v1949 = v1868->cache_vals;
    int v2158 = v1948 * 2;
    int v1950 = v1949[v2158];
    int v2159 = (v1948 * 2) + 1;
    int v1951 = v1949[v2159];
    int v2160 = (((((int)((unsigned int)((int)((unsigned int)v1870 >> 2)) >> 1)) & 1) * 2) + ((((v1890 + ((~(((v1892 ^ -1) | (-(v1892 ^ -1))) >> 31)) & 2)) - (v1893 + ((~(((v1894 ^ -1) | (-(v1894 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
    v1949[v2160] = v1950;
    int * v1953 = v1868->cache_vals;
    int v2163 = ((((((int)((unsigned int)((int)((unsigned int)v1870 >> 2)) >> 1)) & 1) * 2) + ((((v1890 + ((~(((v1892 ^ -1) | (-(v1892 ^ -1))) >> 31)) & 2)) - (v1893 + ((~(((v1894 ^ -1) | (-(v1894 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
    v1953[v2163] = v1951;
    int * v1955 = v1868->cache_tags;
    int v2166 = ((((int)((unsigned int)((int)((unsigned int)v1870 >> 2)) >> 1)) & 1) * 2) + ((((v1890 + ((~(((v1892 ^ -1) | (-(v1892 ^ -1))) >> 31)) & 2)) - (v1893 + ((~(((v1894 ^ -1) | (-(v1894 ^ -1))) >> 31)) & 2))) >> 31) & 1);
    int v2167 = (int)((unsigned int)((int)((unsigned int)v1870 >> 2)) >> 1);
    v1955[v2166] = v2167;
    int * v1957 = v1868->cache_dirty;
    v1957[v2166] = 0;
    int * v1959 = v1868->cache_age;
    v1959[v2166] = 1;
    int * v1961 = v1868->cache_age;
    int v1962 = v1961[v2166];
    int v1963 = v1961[v2095];
    int v2173 = v1963 + ((int)((unsigned int)(v1963 - v1962) >> 31));
    v1961[v2095] = v2173;
    int * v1965 = v1868->cache_age;
    int v1966 = v1965[v2096];
    int v2175 = v1966 + ((int)((unsigned int)(v1966 - v1962) >> 31));
    v1965[v2096] = v2175;
    int * v1968 = v1868->cache_age;
    v1968[v2166] = 0;
    v1971 = v2166;
  }
  int v2178 = (v1971 * 2) + (((int)((unsigned int)v1870 >> 2)) & 1);
  int v1972 = v1878[v2178];
  int * v1973 = v1868->regs;
  v1973[11] = v1972;
  struct StateT * v1975 = v1855->b;
  int * v1976 = v1975->regs;
  int v1977 = v1976[6];
  int * v1978 = v1975->cache_tags;
  int v2185 = (((int)((unsigned int)((int)((unsigned int)v1977 >> 2)) >> 1)) & 1) * 2;
  int v1979 = v1978[v2185];
  int v2186 = ((((int)((unsigned int)((int)((unsigned int)v1977 >> 2)) >> 1)) & 1) * 2) + 1;
  int v1980 = v1978[v2186];
  int v2187 = 4 + ((((int)((unsigned int)((int)((unsigned int)v1977 >> 2)) >> 1)) & 3) * 2);
  int v1981 = v1978[v2187];
  int v2188 = (4 + ((((int)((unsigned int)((int)((unsigned int)v1977 >> 2)) >> 1)) & 3) * 2)) + 1;
  int v1982 = v1978[v2188];
  int v1983 = v1975->timer;
  int v2189 = v1983 + ((100 ^ (((~(((v1981 ^ ((int)((unsigned int)((int)((unsigned int)v1977 >> 2)) >> 1))) | (-(v1981 ^ ((int)((unsigned int)((int)((unsigned int)v1977 >> 2)) >> 1))))) >> 31)) | (~(((v1982 ^ ((int)((unsigned int)((int)((unsigned int)v1977 >> 2)) >> 1))) | (-(v1982 ^ ((int)((unsigned int)((int)((unsigned int)v1977 >> 2)) >> 1))))) >> 31))) & 104)) ^ (((~(((v1979 ^ ((int)((unsigned int)((int)((unsigned int)v1977 >> 2)) >> 1))) | (-(v1979 ^ ((int)((unsigned int)((int)((unsigned int)v1977 >> 2)) >> 1))))) >> 31)) | (~(((v1980 ^ ((int)((unsigned int)((int)((unsigned int)v1977 >> 2)) >> 1))) | (-(v1980 ^ ((int)((unsigned int)((int)((unsigned int)v1977 >> 2)) >> 1))))) >> 31))) & (1 ^ (100 ^ (((~(((v1981 ^ ((int)((unsigned int)((int)((unsigned int)v1977 >> 2)) >> 1))) | (-(v1981 ^ ((int)((unsigned int)((int)((unsigned int)v1977 >> 2)) >> 1))))) >> 31)) | (~(((v1982 ^ ((int)((unsigned int)((int)((unsigned int)v1977 >> 2)) >> 1))) | (-(v1982 ^ ((int)((unsigned int)((int)((unsigned int)v1977 >> 2)) >> 1))))) >> 31))) & 104)))));
  v1975->timer = v2189;
  int * v1985 = v1975->cache_vals;
  bool v2190 = !(((~(((v1979 ^ ((int)((unsigned int)((int)((unsigned int)v1977 >> 2)) >> 1))) | (-(v1979 ^ ((int)((unsigned int)((int)((unsigned int)v1977 >> 2)) >> 1))))) >> 31)) | (~(((v1980 ^ ((int)((unsigned int)((int)((unsigned int)v1977 >> 2)) >> 1))) | (-(v1980 ^ ((int)((unsigned int)((int)((unsigned int)v1977 >> 2)) >> 1))))) >> 31))) == 0);
  int v2078;
  if (v2190) {
    int * v1986 = v1975->cache_age;
    int v2192 = ((((int)((unsigned int)((int)((unsigned int)v1977 >> 2)) >> 1)) & 1) * 2) + ((~(((v1980 ^ ((int)((unsigned int)((int)((unsigned int)v1977 >> 2)) >> 1))) | (-(v1980 ^ ((int)((unsigned int)((int)((unsigned int)v1977 >> 2)) >> 1))))) >> 31)) & 1);
    int v1987 = v1986[v2192];
    int v1988 = v1986[v2185];
    int v2193 = v1988 + ((int)((unsigned int)(v1988 - v1987) >> 31));
    v1986[v2185] = v2193;
    int * v1990 = v1975->cache_age;
    int v1991 = v1990[v2186];
    int v2195 = v1991 + ((int)((unsigned int)(v1991 - v1987) >> 31));
    v1990[v2186] = v2195;
    int * v1993 = v1975->cache_age;
    v1993[v2192] = 0;
    v2078 = v2192;
  } else {
    int * v1996 = v1975->cache_age;
    int v2199 = (((int)((unsigned int)((int)((unsigned int)v1977 >> 2)) >> 1)) & 1) * 2;
    int v1997 = v1996[v2199];
    int * v1998 = v1975->cache_tags;
    int v1999 = v1998[v2199];
    int v2000 = v1996[v2186];
    int v2001 = v1998[v2186];
    bool v2201 = !(((~(((v1981 ^ ((int)((unsigned int)((int)((unsigned int)v1977 >> 2)) >> 1))) | (-(v1981 ^ ((int)((unsigned int)((int)((unsigned int)v1977 >> 2)) >> 1))))) >> 31)) | (~(((v1982 ^ ((int)((unsigned int)((int)((unsigned int)v1977 >> 2)) >> 1))) | (-(v1982 ^ ((int)((unsigned int)((int)((unsigned int)v1977 >> 2)) >> 1))))) >> 31))) == 0);
    int v2055;
    if (v2201) {
      int * v2002 = v1975->cache_age;
      int v2203 = (4 + ((((int)((unsigned int)((int)((unsigned int)v1977 >> 2)) >> 1)) & 3) * 2)) + ((~(((v1982 ^ ((int)((unsigned int)((int)((unsigned int)v1977 >> 2)) >> 1))) | (-(v1982 ^ ((int)((unsigned int)((int)((unsigned int)v1977 >> 2)) >> 1))))) >> 31)) & 1);
      int v2003 = v2002[v2203];
      int v2004 = v2002[v2187];
      int v2204 = v2004 + ((int)((unsigned int)(v2004 - v2003) >> 31));
      v2002[v2187] = v2204;
      int * v2006 = v1975->cache_age;
      int v2007 = v2006[v2188];
      int v2206 = v2007 + ((int)((unsigned int)(v2007 - v2003) >> 31));
      v2006[v2188] = v2206;
      int * v2009 = v1975->cache_age;
      v2009[v2203] = 0;
      v2055 = v2203;
    } else {
      int * v2012 = v1975->cache_age;
      int v2210 = 4 + ((((int)((unsigned int)((int)((unsigned int)v1977 >> 2)) >> 1)) & 3) * 2);
      int v2013 = v2012[v2210];
      int * v2014 = v1975->cache_tags;
      int v2015 = v2014[v2210];
      int v2016 = v2012[v2188];
      int v2017 = v2014[v2188];
      int * v2018 = v1975->cache_dirty;
      int v2213 = (4 + ((((int)((unsigned int)((int)((unsigned int)v1977 >> 2)) >> 1)) & 3) * 2)) + ((((v2013 + ((~(((v2015 ^ -1) | (-(v2015 ^ -1))) >> 31)) & 2)) - (v2016 + ((~(((v2017 ^ -1) | (-(v2017 ^ -1))) >> 31)) & 2))) >> 31) & 1);
      int v2019 = v2018[v2213];
      bool v2214 = !(v2019 == 0);
      if (v2214) {
        int * v2020 = v1975->cache_tags;
        int v2021 = v2020[v2213];
        int * v2022 = v1975->cache_vals;
        int v2217 = ((4 + ((((int)((unsigned int)((int)((unsigned int)v1977 >> 2)) >> 1)) & 3) * 2)) + ((((v2013 + ((~(((v2015 ^ -1) | (-(v2015 ^ -1))) >> 31)) & 2)) - (v2016 + ((~(((v2017 ^ -1) | (-(v2017 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
        int v2023 = v2022[v2217];
        int v2218 = (((4 + ((((int)((unsigned int)((int)((unsigned int)v1977 >> 2)) >> 1)) & 3) * 2)) + ((((v2013 + ((~(((v2015 ^ -1) | (-(v2015 ^ -1))) >> 31)) & 2)) - (v2016 + ((~(((v2017 ^ -1) | (-(v2017 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
        int v2024 = v2022[v2218];
        int * v2025 = v1975->mem;
        int v2220 = v2021 * 2;
        v2025[v2220] = v2023;
        int * v2027 = v1975->mem;
        int v2223 = (v2021 * 2) + 1;
        v2027[v2223] = v2024;
        ;
      } else {
        ;
      }
      int * v2032 = v1975->mem;
      int v2228 = ((int)((unsigned int)((int)((unsigned int)v1977 >> 2)) >> 1)) * 2;
      int v2033 = v2032[v2228];
      int v2229 = (((int)((unsigned int)((int)((unsigned int)v1977 >> 2)) >> 1)) * 2) + 1;
      int v2034 = v2032[v2229];
      int * v2035 = v1975->cache_vals;
      int v2231 = ((4 + ((((int)((unsigned int)((int)((unsigned int)v1977 >> 2)) >> 1)) & 3) * 2)) + ((((v2013 + ((~(((v2015 ^ -1) | (-(v2015 ^ -1))) >> 31)) & 2)) - (v2016 + ((~(((v2017 ^ -1) | (-(v2017 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
      v2035[v2231] = v2033;
      int * v2037 = v1975->cache_vals;
      int v2234 = (((4 + ((((int)((unsigned int)((int)((unsigned int)v1977 >> 2)) >> 1)) & 3) * 2)) + ((((v2013 + ((~(((v2015 ^ -1) | (-(v2015 ^ -1))) >> 31)) & 2)) - (v2016 + ((~(((v2017 ^ -1) | (-(v2017 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
      v2037[v2234] = v2034;
      int * v2039 = v1975->cache_tags;
      int v2237 = (int)((unsigned int)((int)((unsigned int)v1977 >> 2)) >> 1);
      v2039[v2213] = v2237;
      int * v2041 = v1975->cache_dirty;
      v2041[v2213] = 0;
      int * v2043 = v1975->cache_age;
      v2043[v2213] = 1;
      int * v2045 = v1975->cache_age;
      int v2046 = v2045[v2213];
      int v2047 = v2045[v2187];
      int v2243 = v2047 + ((int)((unsigned int)(v2047 - v2046) >> 31));
      v2045[v2187] = v2243;
      int * v2049 = v1975->cache_age;
      int v2050 = v2049[v2188];
      int v2245 = v2050 + ((int)((unsigned int)(v2050 - v2046) >> 31));
      v2049[v2188] = v2245;
      int * v2052 = v1975->cache_age;
      v2052[v2213] = 0;
      v2055 = v2213;
    }
    int * v2056 = v1975->cache_vals;
    int v2248 = v2055 * 2;
    int v2057 = v2056[v2248];
    int v2249 = (v2055 * 2) + 1;
    int v2058 = v2056[v2249];
    int v2250 = (((((int)((unsigned int)((int)((unsigned int)v1977 >> 2)) >> 1)) & 1) * 2) + ((((v1997 + ((~(((v1999 ^ -1) | (-(v1999 ^ -1))) >> 31)) & 2)) - (v2000 + ((~(((v2001 ^ -1) | (-(v2001 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
    v2056[v2250] = v2057;
    int * v2060 = v1975->cache_vals;
    int v2253 = ((((((int)((unsigned int)((int)((unsigned int)v1977 >> 2)) >> 1)) & 1) * 2) + ((((v1997 + ((~(((v1999 ^ -1) | (-(v1999 ^ -1))) >> 31)) & 2)) - (v2000 + ((~(((v2001 ^ -1) | (-(v2001 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
    v2060[v2253] = v2058;
    int * v2062 = v1975->cache_tags;
    int v2256 = ((((int)((unsigned int)((int)((unsigned int)v1977 >> 2)) >> 1)) & 1) * 2) + ((((v1997 + ((~(((v1999 ^ -1) | (-(v1999 ^ -1))) >> 31)) & 2)) - (v2000 + ((~(((v2001 ^ -1) | (-(v2001 ^ -1))) >> 31)) & 2))) >> 31) & 1);
    int v2257 = (int)((unsigned int)((int)((unsigned int)v1977 >> 2)) >> 1);
    v2062[v2256] = v2257;
    int * v2064 = v1975->cache_dirty;
    v2064[v2256] = 0;
    int * v2066 = v1975->cache_age;
    v2066[v2256] = 1;
    int * v2068 = v1975->cache_age;
    int v2069 = v2068[v2256];
    int v2070 = v2068[v2185];
    int v2263 = v2070 + ((int)((unsigned int)(v2070 - v2069) >> 31));
    v2068[v2185] = v2263;
    int * v2072 = v1975->cache_age;
    int v2073 = v2072[v2186];
    int v2265 = v2073 + ((int)((unsigned int)(v2073 - v2069) >> 31));
    v2072[v2186] = v2265;
    int * v2075 = v1975->cache_age;
    v2075[v2256] = 0;
    v2078 = v2256;
  }
  int v2268 = (v2078 * 2) + (((int)((unsigned int)v1977 >> 2)) & 1);
  int v2079 = v1985[v2268];
  int * v2080 = v1975->regs;
  v2080[11] = v2079;
  struct StateT2 * v2082 = slot_10(v1855);
  return v2082;
}

struct StateT2 * slot_11(struct StateT2 * v2273) {
  struct StateT * v2274 = v2273->a;
  int v2275 = v2274->timer;
  struct StateT * v2276 = v2273->b;
  int v2277 = v2276->timer;
  bool v2292 = v2275 == v2277;
  squared_assert(v2292);
  squared_assume(v2292);
  struct StateT * v2280 = v2273->a;
  int v2281 = v2280->timer;
  int v2294 = v2281 + 1;
  v2280->timer = v2294;
  struct StateT * v2283 = v2273->b;
  int v2284 = v2283->timer;
  int v2296 = v2284 + 1;
  v2283->timer = v2296;
  struct StateT2 * v2288 = slot_12(v2273);
  return v2288;
}

struct StateT2 * slot_0(struct StateT2 * v2) {
  struct StateT * v3 = v2->a;
  int v4 = v3->timer;
  struct StateT * v5 = v2->b;
  int v6 = v5->timer;
  bool v25 = v4 == v6;
  squared_assert(v25);
  squared_assume(v25);
  struct StateT * v9 = v2->a;
  int v10 = v9->timer;
  int v27 = v10 + 1;
  v9->timer = v27;
  struct StateT * v12 = v2->b;
  int v13 = v12->timer;
  int v29 = v13 + 1;
  v12->timer = v29;
  struct StateT * v15 = v2->a;
  int * v16 = v15->regs;
  v16[6] = 0;
  struct StateT * v18 = v2->b;
  int * v19 = v18->regs;
  v19[6] = 0;
  struct StateT2 * v21 = slot_1(v2);
  return v21;
}



/*****************************************
End of C Generated Code
*******************************************/

void init(struct StateT *s) {
  for (int i=0; i<NUM_REGS; i++) {
    s->regs[i] = 0;
    s->saved_regs[i] = 0;
  }
  s->timer = 0;
  for (int i=0; i<MEM_SIZE; i++) {
    s->mem[i] = 0;
  }
  for (int i=0; i<CACHE_ENTRIES; i++) {
    s->cache_tags[i] = -1;
    s->cache_dirty[i] = 0;
    s->cache_age[i] = 0;
  }
  for (int i=0; i<CACHE_WORDS; i++) {
    s->cache_vals[i] = 0;
  }
}

void squared_assert(bool c) { koika_assert(c, "timer drift"); }
void squared_diverged(bool c) { koika_assert(c, "control flow diverged"); }
void squared_assume(bool c) { koika_assume(c); }

int main(int argc, char* argv[]) {
  struct StateT s1, s2;
  init(&s1);
  init(&s2);
  
  int x = bounded(0, 80);
  s1.regs[10] = x;
  s2.regs[10] = x;
  
  // initialize secret
  for (int i=0; i<SECRET_SIZE; i++) {
    s1.mem[SECRET_OFFSET+i] = secret(0, 20);
    s2.mem[SECRET_OFFSET+i] = secret(0, 20);
  }
  struct StateT2 p = { .a = &s1, .b = &s2 };
  struct StateT2 *p_ = snippet(&p);
  koika_assert(p_->a->timer==p_->b->timer, "timing leak");
  return 0;
}