// verify: clean (CBMC should report VERIFICATION SUCCESSFUL) [unwind 65]
#define NUM_REGS 32
#define MEM_SIZE 64
#define SECRET_SIZE 10
#define SECRET_OFFSET 20
#define CACHE_ENTRIES 12
#define CACHE_WORDS 24

#ifdef CBMC
int nondet_uint();
#define koika_assert(b, s) __CPROVER_assert(b, s)
#define koika_assume(b) __CPROVER_assume(b)
#define koika_draw(x) ((x) = nondet_uint())
#define koika_secret(x) ((void)0)
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

struct StateT * slot_12(struct StateT * v813);
struct StateT * slot_34(struct StateT * v2542);
struct StateT * slot_43(struct StateT * v3367);
struct StateT * slot_6(struct StateT * v486);
struct StateT * slot_29(struct StateT * v2275);
struct StateT * slot_25(struct StateT * v1906);
struct StateT * slot_16(struct StateT * v1068);
struct StateT * slot_23(struct StateT * v1685);
struct StateT * slot_5(struct StateT * v279);
struct StateT * slot_2(struct StateT * v225);
struct StateT * slot_7(struct StateT * v509);
struct StateT * slot_21(struct StateT * v1657);
struct StateT * slot_31(struct StateT * v2482);
struct StateT * slot_3(struct StateT * v233);
struct StateT * slot_45(struct StateT * v3626);
struct StateT * slot_26(struct StateT * v1927);
struct StateT * slot_10(struct StateT * v582);
struct StateT * slot_1(struct StateT * v18);
struct StateT * slot_19(struct StateT * v1330);
struct StateT * slot_13(struct StateT * v1055);
struct StateT * slot_38(struct StateT * v3103);
struct StateT * slot_0(struct StateT * v2);
struct StateT * slot_14(struct StateT * v1060);
struct StateT * slot_42(struct StateT * v3160);
struct StateT * slot_44(struct StateT * v3398);
struct StateT * slot_32(struct StateT * v2506);
struct StateT * slot_17(struct StateT * v1096);
struct StateT * slot_33(struct StateT * v2514);
struct StateT * slot_36(struct StateT * v2776);
struct StateT * snippet(struct StateT * v0);
struct StateT * slot_40(struct StateT * v3136);
struct StateT * slot_8(struct StateT * v530);
struct StateT * slot_27(struct StateT * v2246);
struct StateT * slot_4(struct StateT * v256);
struct StateT * slot_9(struct StateT * v558);
struct StateT * slot_11(struct StateT * v789);
struct StateT * slot_12(struct StateT * v813) {
  int * v814 = v813->saved_regs;
  int v815 = v814[10];
  int * v816 = v813->regs;
  int v817 = v816[11];
  bool v942 = (v815 ^ -2147483648) >= (v817 ^ -2147483648);
  struct StateT * v936;
  if (v942) {
    int v818 = v813->timer;
    int v943 = v818 + 15;
    v813->timer = v943;
    int * v820 = v813->saved_regs;
    int v821 = v820[13];
    int * v822 = v813->regs;
    v822[13] = v821;
    int * v824 = v813->saved_regs;
    int v825 = v824[12];
    int * v826 = v813->regs;
    v826[12] = v825;
    int * v828 = v813->saved_regs;
    int v829 = v828[14];
    int * v830 = v813->regs;
    v830[14] = v829;
    int * v832 = v813->saved_regs;
    int v833 = v832[10];
    int * v834 = v813->regs;
    v834[10] = v833;
    int * v836 = v813->reg_ready;
    int v837 = v813->timer;
    v836[0] = v837;
    int * v839 = v813->reg_ready;
    int v840 = v813->timer;
    v839[1] = v840;
    int * v842 = v813->reg_ready;
    int v843 = v813->timer;
    v842[2] = v843;
    int * v845 = v813->reg_ready;
    int v846 = v813->timer;
    v845[3] = v846;
    int * v848 = v813->reg_ready;
    int v849 = v813->timer;
    v848[4] = v849;
    int * v851 = v813->reg_ready;
    int v852 = v813->timer;
    v851[5] = v852;
    int * v854 = v813->reg_ready;
    int v855 = v813->timer;
    v854[6] = v855;
    int * v857 = v813->reg_ready;
    int v858 = v813->timer;
    v857[7] = v858;
    int * v860 = v813->reg_ready;
    int v861 = v813->timer;
    v860[8] = v861;
    int * v863 = v813->reg_ready;
    int v864 = v813->timer;
    v863[9] = v864;
    int * v866 = v813->reg_ready;
    int v867 = v813->timer;
    v866[10] = v867;
    int * v869 = v813->reg_ready;
    int v870 = v813->timer;
    v869[11] = v870;
    int * v872 = v813->reg_ready;
    int v873 = v813->timer;
    v872[12] = v873;
    int * v875 = v813->reg_ready;
    int v876 = v813->timer;
    v875[13] = v876;
    int * v878 = v813->reg_ready;
    int v879 = v813->timer;
    v878[14] = v879;
    int * v881 = v813->reg_ready;
    int v882 = v813->timer;
    v881[15] = v882;
    int * v884 = v813->reg_ready;
    int v885 = v813->timer;
    v884[16] = v885;
    int * v887 = v813->reg_ready;
    int v888 = v813->timer;
    v887[17] = v888;
    int * v890 = v813->reg_ready;
    int v891 = v813->timer;
    v890[18] = v891;
    int * v893 = v813->reg_ready;
    int v894 = v813->timer;
    v893[19] = v894;
    int * v896 = v813->reg_ready;
    int v897 = v813->timer;
    v896[20] = v897;
    int * v899 = v813->reg_ready;
    int v900 = v813->timer;
    v899[21] = v900;
    int * v902 = v813->reg_ready;
    int v903 = v813->timer;
    v902[22] = v903;
    int * v905 = v813->reg_ready;
    int v906 = v813->timer;
    v905[23] = v906;
    int * v908 = v813->reg_ready;
    int v909 = v813->timer;
    v908[24] = v909;
    int * v911 = v813->reg_ready;
    int v912 = v813->timer;
    v911[25] = v912;
    int * v914 = v813->reg_ready;
    int v915 = v813->timer;
    v914[26] = v915;
    int * v917 = v813->reg_ready;
    int v918 = v813->timer;
    v917[27] = v918;
    int * v920 = v813->reg_ready;
    int v921 = v813->timer;
    v920[28] = v921;
    int * v923 = v813->reg_ready;
    int v924 = v813->timer;
    v923[29] = v924;
    int * v926 = v813->reg_ready;
    int v927 = v813->timer;
    v926[30] = v927;
    int * v929 = v813->reg_ready;
    int v930 = v813->timer;
    v929[31] = v930;
    struct StateT * v932 = slot_13(v813);
    v936 = v932;
  } else {
    struct StateT * v934 = slot_14(v813);
    v936 = v934;
  }
  return v936;
}

struct StateT * slot_34(struct StateT * v2542) {
  int * v2543 = v2542->saved_regs;
  int v2544 = v2543[13];
  bool v2655 = !(v2544 == 0);
  struct StateT * v2651;
  if (v2655) {
    int v2545 = v2542->timer;
    int v2656 = v2545 + 15;
    v2542->timer = v2656;
    int * v2547 = v2542->saved_regs;
    int v2548 = v2547[13];
    int * v2549 = v2542->regs;
    v2549[13] = v2548;
    int * v2551 = v2542->reg_ready;
    int v2552 = v2542->timer;
    v2551[0] = v2552;
    int * v2554 = v2542->reg_ready;
    int v2555 = v2542->timer;
    v2554[1] = v2555;
    int * v2557 = v2542->reg_ready;
    int v2558 = v2542->timer;
    v2557[2] = v2558;
    int * v2560 = v2542->reg_ready;
    int v2561 = v2542->timer;
    v2560[3] = v2561;
    int * v2563 = v2542->reg_ready;
    int v2564 = v2542->timer;
    v2563[4] = v2564;
    int * v2566 = v2542->reg_ready;
    int v2567 = v2542->timer;
    v2566[5] = v2567;
    int * v2569 = v2542->reg_ready;
    int v2570 = v2542->timer;
    v2569[6] = v2570;
    int * v2572 = v2542->reg_ready;
    int v2573 = v2542->timer;
    v2572[7] = v2573;
    int * v2575 = v2542->reg_ready;
    int v2576 = v2542->timer;
    v2575[8] = v2576;
    int * v2578 = v2542->reg_ready;
    int v2579 = v2542->timer;
    v2578[9] = v2579;
    int * v2581 = v2542->reg_ready;
    int v2582 = v2542->timer;
    v2581[10] = v2582;
    int * v2584 = v2542->reg_ready;
    int v2585 = v2542->timer;
    v2584[11] = v2585;
    int * v2587 = v2542->reg_ready;
    int v2588 = v2542->timer;
    v2587[12] = v2588;
    int * v2590 = v2542->reg_ready;
    int v2591 = v2542->timer;
    v2590[13] = v2591;
    int * v2593 = v2542->reg_ready;
    int v2594 = v2542->timer;
    v2593[14] = v2594;
    int * v2596 = v2542->reg_ready;
    int v2597 = v2542->timer;
    v2596[15] = v2597;
    int * v2599 = v2542->reg_ready;
    int v2600 = v2542->timer;
    v2599[16] = v2600;
    int * v2602 = v2542->reg_ready;
    int v2603 = v2542->timer;
    v2602[17] = v2603;
    int * v2605 = v2542->reg_ready;
    int v2606 = v2542->timer;
    v2605[18] = v2606;
    int * v2608 = v2542->reg_ready;
    int v2609 = v2542->timer;
    v2608[19] = v2609;
    int * v2611 = v2542->reg_ready;
    int v2612 = v2542->timer;
    v2611[20] = v2612;
    int * v2614 = v2542->reg_ready;
    int v2615 = v2542->timer;
    v2614[21] = v2615;
    int * v2617 = v2542->reg_ready;
    int v2618 = v2542->timer;
    v2617[22] = v2618;
    int * v2620 = v2542->reg_ready;
    int v2621 = v2542->timer;
    v2620[23] = v2621;
    int * v2623 = v2542->reg_ready;
    int v2624 = v2542->timer;
    v2623[24] = v2624;
    int * v2626 = v2542->reg_ready;
    int v2627 = v2542->timer;
    v2626[25] = v2627;
    int * v2629 = v2542->reg_ready;
    int v2630 = v2542->timer;
    v2629[26] = v2630;
    int * v2632 = v2542->reg_ready;
    int v2633 = v2542->timer;
    v2632[27] = v2633;
    int * v2635 = v2542->reg_ready;
    int v2636 = v2542->timer;
    v2635[28] = v2636;
    int * v2638 = v2542->reg_ready;
    int v2639 = v2542->timer;
    v2638[29] = v2639;
    int * v2641 = v2542->reg_ready;
    int v2642 = v2542->timer;
    v2641[30] = v2642;
    int * v2644 = v2542->reg_ready;
    int v2645 = v2542->timer;
    v2644[31] = v2645;
    struct StateT * v2647 = slot_45(v2542);
    v2651 = v2647;
  } else {
    struct StateT * v2649 = slot_36(v2542);
    v2651 = v2649;
  }
  return v2651;
}

struct StateT * slot_43(struct StateT * v3367) {
  int * v3368 = v3367->saved_regs;
  int * v3369 = v3367->regs;
  int v3370 = v3369[12];
  v3368[12] = v3370;
  int v3372 = v3367->timer;
  int v3389 = v3372 + 1;
  v3367->timer = v3389;
  int * v3374 = v3367->reg_ready;
  int v3375 = v3374[12];
  int * v3376 = v3367->regs;
  int v3377 = v3376[12];
  int v3378 = v3374[10];
  int v3379 = v3376[10];
  int v3393 = (v3378 + (((v3375 + ((v3372 - v3375) & (~((v3372 - v3375) >> 31)))) - v3378) & (~(((v3375 + ((v3372 - v3375) & (~((v3372 - v3375) >> 31)))) - v3378) >> 31)))) + 1;
  v3374[12] = v3393;
  int * v3381 = v3367->regs;
  int v3395 = v3377 & v3379;
  v3381[12] = v3395;
  struct StateT * v3383 = slot_44(v3367);
  return v3383;
}

struct StateT * slot_6(struct StateT * v486) {
  int * v487 = v486->saved_regs;
  int * v488 = v486->regs;
  int v489 = v488[14];
  v487[14] = v489;
  int v491 = v486->timer;
  int v503 = v491 + 1;
  v486->timer = v503;
  int * v493 = v486->reg_ready;
  v493[14] = v503;
  int * v495 = v486->regs;
  v495[14] = 0;
  struct StateT * v497 = slot_7(v486);
  return v497;
}

struct StateT * slot_29(struct StateT * v2275) {
  int v2276 = v2275->timer;
  int v2388 = v2276 + 1;
  v2275->timer = v2388;
  int * v2278 = v2275->reg_ready;
  int v2279 = v2278[10];
  int * v2280 = v2275->regs;
  int v2281 = v2280[10];
  int * v2282 = v2275->cache_tags;
  int v2393 = (((int)((unsigned int)((int)((unsigned int)v2281 >> 2)) >> 1)) & 1) * 2;
  int v2283 = v2282[v2393];
  int v2394 = ((((int)((unsigned int)((int)((unsigned int)v2281 >> 2)) >> 1)) & 1) * 2) + 1;
  int v2284 = v2282[v2394];
  int v2395 = 4 + ((((int)((unsigned int)((int)((unsigned int)v2281 >> 2)) >> 1)) & 3) * 2);
  int v2285 = v2282[v2395];
  int v2396 = (4 + ((((int)((unsigned int)((int)((unsigned int)v2281 >> 2)) >> 1)) & 3) * 2)) + 1;
  int v2286 = v2282[v2396];
  int * v2287 = v2275->cache_vals;
  bool v2397 = !(((~(((v2283 ^ ((int)((unsigned int)((int)((unsigned int)v2281 >> 2)) >> 1))) | (-(v2283 ^ ((int)((unsigned int)((int)((unsigned int)v2281 >> 2)) >> 1))))) >> 31)) | (~(((v2284 ^ ((int)((unsigned int)((int)((unsigned int)v2281 >> 2)) >> 1))) | (-(v2284 ^ ((int)((unsigned int)((int)((unsigned int)v2281 >> 2)) >> 1))))) >> 31))) == 0);
  int v2380;
  if (v2397) {
    int * v2288 = v2275->cache_age;
    int v2399 = ((((int)((unsigned int)((int)((unsigned int)v2281 >> 2)) >> 1)) & 1) * 2) + ((~(((v2284 ^ ((int)((unsigned int)((int)((unsigned int)v2281 >> 2)) >> 1))) | (-(v2284 ^ ((int)((unsigned int)((int)((unsigned int)v2281 >> 2)) >> 1))))) >> 31)) & 1);
    int v2289 = v2288[v2399];
    int v2290 = v2288[v2393];
    int v2400 = v2290 + ((int)((unsigned int)(v2290 - v2289) >> 31));
    v2288[v2393] = v2400;
    int * v2292 = v2275->cache_age;
    int v2293 = v2292[v2394];
    int v2402 = v2293 + ((int)((unsigned int)(v2293 - v2289) >> 31));
    v2292[v2394] = v2402;
    int * v2295 = v2275->cache_age;
    v2295[v2399] = 0;
    v2380 = v2399;
  } else {
    int * v2298 = v2275->cache_age;
    int v2406 = (((int)((unsigned int)((int)((unsigned int)v2281 >> 2)) >> 1)) & 1) * 2;
    int v2299 = v2298[v2406];
    int * v2300 = v2275->cache_tags;
    int v2301 = v2300[v2406];
    int v2302 = v2298[v2394];
    int v2303 = v2300[v2394];
    bool v2408 = !(((~(((v2285 ^ ((int)((unsigned int)((int)((unsigned int)v2281 >> 2)) >> 1))) | (-(v2285 ^ ((int)((unsigned int)((int)((unsigned int)v2281 >> 2)) >> 1))))) >> 31)) | (~(((v2286 ^ ((int)((unsigned int)((int)((unsigned int)v2281 >> 2)) >> 1))) | (-(v2286 ^ ((int)((unsigned int)((int)((unsigned int)v2281 >> 2)) >> 1))))) >> 31))) == 0);
    int v2357;
    if (v2408) {
      int * v2304 = v2275->cache_age;
      int v2410 = (4 + ((((int)((unsigned int)((int)((unsigned int)v2281 >> 2)) >> 1)) & 3) * 2)) + ((~(((v2286 ^ ((int)((unsigned int)((int)((unsigned int)v2281 >> 2)) >> 1))) | (-(v2286 ^ ((int)((unsigned int)((int)((unsigned int)v2281 >> 2)) >> 1))))) >> 31)) & 1);
      int v2305 = v2304[v2410];
      int v2306 = v2304[v2395];
      int v2411 = v2306 + ((int)((unsigned int)(v2306 - v2305) >> 31));
      v2304[v2395] = v2411;
      int * v2308 = v2275->cache_age;
      int v2309 = v2308[v2396];
      int v2413 = v2309 + ((int)((unsigned int)(v2309 - v2305) >> 31));
      v2308[v2396] = v2413;
      int * v2311 = v2275->cache_age;
      v2311[v2410] = 0;
      v2357 = v2410;
    } else {
      int * v2314 = v2275->cache_age;
      int v2417 = 4 + ((((int)((unsigned int)((int)((unsigned int)v2281 >> 2)) >> 1)) & 3) * 2);
      int v2315 = v2314[v2417];
      int * v2316 = v2275->cache_tags;
      int v2317 = v2316[v2417];
      int v2318 = v2314[v2396];
      int v2319 = v2316[v2396];
      int * v2320 = v2275->cache_dirty;
      int v2420 = (4 + ((((int)((unsigned int)((int)((unsigned int)v2281 >> 2)) >> 1)) & 3) * 2)) + ((((v2315 + ((~(((v2317 ^ -1) | (-(v2317 ^ -1))) >> 31)) & 2)) - (v2318 + ((~(((v2319 ^ -1) | (-(v2319 ^ -1))) >> 31)) & 2))) >> 31) & 1);
      int v2321 = v2320[v2420];
      bool v2421 = !(v2321 == 0);
      if (v2421) {
        int * v2322 = v2275->cache_tags;
        int v2323 = v2322[v2420];
        int * v2324 = v2275->cache_vals;
        int v2424 = ((4 + ((((int)((unsigned int)((int)((unsigned int)v2281 >> 2)) >> 1)) & 3) * 2)) + ((((v2315 + ((~(((v2317 ^ -1) | (-(v2317 ^ -1))) >> 31)) & 2)) - (v2318 + ((~(((v2319 ^ -1) | (-(v2319 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
        int v2325 = v2324[v2424];
        int v2425 = (((4 + ((((int)((unsigned int)((int)((unsigned int)v2281 >> 2)) >> 1)) & 3) * 2)) + ((((v2315 + ((~(((v2317 ^ -1) | (-(v2317 ^ -1))) >> 31)) & 2)) - (v2318 + ((~(((v2319 ^ -1) | (-(v2319 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
        int v2326 = v2324[v2425];
        int * v2327 = v2275->mem;
        int v2427 = v2323 * 2;
        v2327[v2427] = v2325;
        int * v2329 = v2275->mem;
        int v2430 = (v2323 * 2) + 1;
        v2329[v2430] = v2326;
        ;
      } else {
        ;
      }
      int * v2334 = v2275->mem;
      int v2435 = ((int)((unsigned int)((int)((unsigned int)v2281 >> 2)) >> 1)) * 2;
      int v2335 = v2334[v2435];
      int v2436 = (((int)((unsigned int)((int)((unsigned int)v2281 >> 2)) >> 1)) * 2) + 1;
      int v2336 = v2334[v2436];
      int * v2337 = v2275->cache_vals;
      int v2438 = ((4 + ((((int)((unsigned int)((int)((unsigned int)v2281 >> 2)) >> 1)) & 3) * 2)) + ((((v2315 + ((~(((v2317 ^ -1) | (-(v2317 ^ -1))) >> 31)) & 2)) - (v2318 + ((~(((v2319 ^ -1) | (-(v2319 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
      v2337[v2438] = v2335;
      int * v2339 = v2275->cache_vals;
      int v2441 = (((4 + ((((int)((unsigned int)((int)((unsigned int)v2281 >> 2)) >> 1)) & 3) * 2)) + ((((v2315 + ((~(((v2317 ^ -1) | (-(v2317 ^ -1))) >> 31)) & 2)) - (v2318 + ((~(((v2319 ^ -1) | (-(v2319 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
      v2339[v2441] = v2336;
      int * v2341 = v2275->cache_tags;
      int v2444 = (int)((unsigned int)((int)((unsigned int)v2281 >> 2)) >> 1);
      v2341[v2420] = v2444;
      int * v2343 = v2275->cache_dirty;
      v2343[v2420] = 0;
      int * v2345 = v2275->cache_age;
      v2345[v2420] = 1;
      int * v2347 = v2275->cache_age;
      int v2348 = v2347[v2420];
      int v2349 = v2347[v2395];
      int v2450 = v2349 + ((int)((unsigned int)(v2349 - v2348) >> 31));
      v2347[v2395] = v2450;
      int * v2351 = v2275->cache_age;
      int v2352 = v2351[v2396];
      int v2452 = v2352 + ((int)((unsigned int)(v2352 - v2348) >> 31));
      v2351[v2396] = v2452;
      int * v2354 = v2275->cache_age;
      v2354[v2420] = 0;
      v2357 = v2420;
    }
    int * v2358 = v2275->cache_vals;
    int v2455 = v2357 * 2;
    int v2359 = v2358[v2455];
    int v2456 = (v2357 * 2) + 1;
    int v2360 = v2358[v2456];
    int v2457 = (((((int)((unsigned int)((int)((unsigned int)v2281 >> 2)) >> 1)) & 1) * 2) + ((((v2299 + ((~(((v2301 ^ -1) | (-(v2301 ^ -1))) >> 31)) & 2)) - (v2302 + ((~(((v2303 ^ -1) | (-(v2303 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
    v2358[v2457] = v2359;
    int * v2362 = v2275->cache_vals;
    int v2460 = ((((((int)((unsigned int)((int)((unsigned int)v2281 >> 2)) >> 1)) & 1) * 2) + ((((v2299 + ((~(((v2301 ^ -1) | (-(v2301 ^ -1))) >> 31)) & 2)) - (v2302 + ((~(((v2303 ^ -1) | (-(v2303 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
    v2362[v2460] = v2360;
    int * v2364 = v2275->cache_tags;
    int v2463 = ((((int)((unsigned int)((int)((unsigned int)v2281 >> 2)) >> 1)) & 1) * 2) + ((((v2299 + ((~(((v2301 ^ -1) | (-(v2301 ^ -1))) >> 31)) & 2)) - (v2302 + ((~(((v2303 ^ -1) | (-(v2303 ^ -1))) >> 31)) & 2))) >> 31) & 1);
    int v2464 = (int)((unsigned int)((int)((unsigned int)v2281 >> 2)) >> 1);
    v2364[v2463] = v2464;
    int * v2366 = v2275->cache_dirty;
    v2366[v2463] = 0;
    int * v2368 = v2275->cache_age;
    v2368[v2463] = 1;
    int * v2370 = v2275->cache_age;
    int v2371 = v2370[v2463];
    int v2372 = v2370[v2393];
    int v2470 = v2372 + ((int)((unsigned int)(v2372 - v2371) >> 31));
    v2370[v2393] = v2470;
    int * v2374 = v2275->cache_age;
    int v2375 = v2374[v2394];
    int v2472 = v2375 + ((int)((unsigned int)(v2375 - v2371) >> 31));
    v2374[v2394] = v2472;
    int * v2377 = v2275->cache_age;
    v2377[v2463] = 0;
    v2380 = v2463;
  }
  int v2475 = (v2380 * 2) + (((int)((unsigned int)v2281 >> 2)) & 1);
  int v2381 = v2287[v2475];
  int * v2382 = v2275->reg_ready;
  int v2477 = ((v2279 + ((v2276 - v2279) & (~((v2276 - v2279) >> 31)))) + 1) + ((100 ^ (((~(((v2285 ^ ((int)((unsigned int)((int)((unsigned int)v2281 >> 2)) >> 1))) | (-(v2285 ^ ((int)((unsigned int)((int)((unsigned int)v2281 >> 2)) >> 1))))) >> 31)) | (~(((v2286 ^ ((int)((unsigned int)((int)((unsigned int)v2281 >> 2)) >> 1))) | (-(v2286 ^ ((int)((unsigned int)((int)((unsigned int)v2281 >> 2)) >> 1))))) >> 31))) & 104)) ^ (((~(((v2283 ^ ((int)((unsigned int)((int)((unsigned int)v2281 >> 2)) >> 1))) | (-(v2283 ^ ((int)((unsigned int)((int)((unsigned int)v2281 >> 2)) >> 1))))) >> 31)) | (~(((v2284 ^ ((int)((unsigned int)((int)((unsigned int)v2281 >> 2)) >> 1))) | (-(v2284 ^ ((int)((unsigned int)((int)((unsigned int)v2281 >> 2)) >> 1))))) >> 31))) & (1 ^ (100 ^ (((~(((v2285 ^ ((int)((unsigned int)((int)((unsigned int)v2281 >> 2)) >> 1))) | (-(v2285 ^ ((int)((unsigned int)((int)((unsigned int)v2281 >> 2)) >> 1))))) >> 31)) | (~(((v2286 ^ ((int)((unsigned int)((int)((unsigned int)v2281 >> 2)) >> 1))) | (-(v2286 ^ ((int)((unsigned int)((int)((unsigned int)v2281 >> 2)) >> 1))))) >> 31))) & 104)))));
  v2382[10] = v2477;
  int * v2384 = v2275->regs;
  v2384[10] = v2381;
  struct StateT * v2386 = slot_31(v2275);
  return v2386;
}

struct StateT * slot_25(struct StateT * v1906) {
  int v1907 = v1906->timer;
  int v1918 = v1907 + 1;
  v1906->timer = v1918;
  int * v1909 = v1906->reg_ready;
  int v1910 = v1909[10];
  int * v1911 = v1906->regs;
  int v1912 = v1911[10];
  int v1922 = (v1910 + ((v1907 - v1910) & (~((v1907 - v1910) >> 31)))) + 1;
  v1909[10] = v1922;
  int * v1914 = v1906->regs;
  int v1924 = v1912 << 2;
  v1914[10] = v1924;
  struct StateT * v1916 = slot_27(v1906);
  return v1916;
}

struct StateT * slot_16(struct StateT * v1068) {
  int * v1069 = v1068->saved_regs;
  int * v1070 = v1068->regs;
  int v1071 = v1070[13];
  v1069[13] = v1071;
  int v1073 = v1068->timer;
  int v1088 = v1073 + 1;
  v1068->timer = v1088;
  int * v1075 = v1068->reg_ready;
  int v1076 = v1075[13];
  int * v1077 = v1068->regs;
  int v1078 = v1077[13];
  int v1091 = (v1076 + ((v1073 - v1076) & (~((v1073 - v1076) >> 31)))) + 1;
  v1075[13] = v1091;
  int * v1080 = v1068->regs;
  int v1093 = v1078 + -1;
  v1080[13] = v1093;
  struct StateT * v1082 = slot_17(v1068);
  return v1082;
}

struct StateT * slot_23(struct StateT * v1685) {
  int * v1686 = v1685->saved_regs;
  int v1687 = v1686[10];
  int * v1688 = v1685->regs;
  int v1689 = v1688[11];
  bool v1802 = (v1687 ^ -2147483648) < (v1689 ^ -2147483648);
  struct StateT * v1796;
  if (v1802) {
    int v1690 = v1685->timer;
    int v1803 = v1690 + 15;
    v1685->timer = v1803;
    int * v1692 = v1685->saved_regs;
    int v1693 = v1692[10];
    int * v1694 = v1685->regs;
    v1694[10] = v1693;
    int * v1696 = v1685->reg_ready;
    int v1697 = v1685->timer;
    v1696[0] = v1697;
    int * v1699 = v1685->reg_ready;
    int v1700 = v1685->timer;
    v1699[1] = v1700;
    int * v1702 = v1685->reg_ready;
    int v1703 = v1685->timer;
    v1702[2] = v1703;
    int * v1705 = v1685->reg_ready;
    int v1706 = v1685->timer;
    v1705[3] = v1706;
    int * v1708 = v1685->reg_ready;
    int v1709 = v1685->timer;
    v1708[4] = v1709;
    int * v1711 = v1685->reg_ready;
    int v1712 = v1685->timer;
    v1711[5] = v1712;
    int * v1714 = v1685->reg_ready;
    int v1715 = v1685->timer;
    v1714[6] = v1715;
    int * v1717 = v1685->reg_ready;
    int v1718 = v1685->timer;
    v1717[7] = v1718;
    int * v1720 = v1685->reg_ready;
    int v1721 = v1685->timer;
    v1720[8] = v1721;
    int * v1723 = v1685->reg_ready;
    int v1724 = v1685->timer;
    v1723[9] = v1724;
    int * v1726 = v1685->reg_ready;
    int v1727 = v1685->timer;
    v1726[10] = v1727;
    int * v1729 = v1685->reg_ready;
    int v1730 = v1685->timer;
    v1729[11] = v1730;
    int * v1732 = v1685->reg_ready;
    int v1733 = v1685->timer;
    v1732[12] = v1733;
    int * v1735 = v1685->reg_ready;
    int v1736 = v1685->timer;
    v1735[13] = v1736;
    int * v1738 = v1685->reg_ready;
    int v1739 = v1685->timer;
    v1738[14] = v1739;
    int * v1741 = v1685->reg_ready;
    int v1742 = v1685->timer;
    v1741[15] = v1742;
    int * v1744 = v1685->reg_ready;
    int v1745 = v1685->timer;
    v1744[16] = v1745;
    int * v1747 = v1685->reg_ready;
    int v1748 = v1685->timer;
    v1747[17] = v1748;
    int * v1750 = v1685->reg_ready;
    int v1751 = v1685->timer;
    v1750[18] = v1751;
    int * v1753 = v1685->reg_ready;
    int v1754 = v1685->timer;
    v1753[19] = v1754;
    int * v1756 = v1685->reg_ready;
    int v1757 = v1685->timer;
    v1756[20] = v1757;
    int * v1759 = v1685->reg_ready;
    int v1760 = v1685->timer;
    v1759[21] = v1760;
    int * v1762 = v1685->reg_ready;
    int v1763 = v1685->timer;
    v1762[22] = v1763;
    int * v1765 = v1685->reg_ready;
    int v1766 = v1685->timer;
    v1765[23] = v1766;
    int * v1768 = v1685->reg_ready;
    int v1769 = v1685->timer;
    v1768[24] = v1769;
    int * v1771 = v1685->reg_ready;
    int v1772 = v1685->timer;
    v1771[25] = v1772;
    int * v1774 = v1685->reg_ready;
    int v1775 = v1685->timer;
    v1774[26] = v1775;
    int * v1777 = v1685->reg_ready;
    int v1778 = v1685->timer;
    v1777[27] = v1778;
    int * v1780 = v1685->reg_ready;
    int v1781 = v1685->timer;
    v1780[28] = v1781;
    int * v1783 = v1685->reg_ready;
    int v1784 = v1685->timer;
    v1783[29] = v1784;
    int * v1786 = v1685->reg_ready;
    int v1787 = v1685->timer;
    v1786[30] = v1787;
    int * v1789 = v1685->reg_ready;
    int v1790 = v1685->timer;
    v1789[31] = v1790;
    struct StateT * v1792 = slot_25(v1685);
    v1796 = v1792;
  } else {
    struct StateT * v1794 = slot_26(v1685);
    v1796 = v1794;
  }
  return v1796;
}

struct StateT * slot_5(struct StateT * v279) {
  int v280 = v279->timer;
  int v392 = v280 + 1;
  v279->timer = v392;
  int * v282 = v279->reg_ready;
  int v283 = v282[12];
  int * v284 = v279->regs;
  int v285 = v284[12];
  int * v286 = v279->cache_tags;
  int v397 = (((int)((unsigned int)((int)((unsigned int)(v285 + 68) >> 2)) >> 1)) & 1) * 2;
  int v287 = v286[v397];
  int v398 = ((((int)((unsigned int)((int)((unsigned int)(v285 + 68) >> 2)) >> 1)) & 1) * 2) + 1;
  int v288 = v286[v398];
  int v399 = 4 + ((((int)((unsigned int)((int)((unsigned int)(v285 + 68) >> 2)) >> 1)) & 3) * 2);
  int v289 = v286[v399];
  int v400 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v285 + 68) >> 2)) >> 1)) & 3) * 2)) + 1;
  int v290 = v286[v400];
  int * v291 = v279->cache_vals;
  bool v401 = !(((~(((v287 ^ ((int)((unsigned int)((int)((unsigned int)(v285 + 68) >> 2)) >> 1))) | (-(v287 ^ ((int)((unsigned int)((int)((unsigned int)(v285 + 68) >> 2)) >> 1))))) >> 31)) | (~(((v288 ^ ((int)((unsigned int)((int)((unsigned int)(v285 + 68) >> 2)) >> 1))) | (-(v288 ^ ((int)((unsigned int)((int)((unsigned int)(v285 + 68) >> 2)) >> 1))))) >> 31))) == 0);
  int v384;
  if (v401) {
    int * v292 = v279->cache_age;
    int v403 = ((((int)((unsigned int)((int)((unsigned int)(v285 + 68) >> 2)) >> 1)) & 1) * 2) + ((~(((v288 ^ ((int)((unsigned int)((int)((unsigned int)(v285 + 68) >> 2)) >> 1))) | (-(v288 ^ ((int)((unsigned int)((int)((unsigned int)(v285 + 68) >> 2)) >> 1))))) >> 31)) & 1);
    int v293 = v292[v403];
    int v294 = v292[v397];
    int v404 = v294 + ((int)((unsigned int)(v294 - v293) >> 31));
    v292[v397] = v404;
    int * v296 = v279->cache_age;
    int v297 = v296[v398];
    int v406 = v297 + ((int)((unsigned int)(v297 - v293) >> 31));
    v296[v398] = v406;
    int * v299 = v279->cache_age;
    v299[v403] = 0;
    v384 = v403;
  } else {
    int * v302 = v279->cache_age;
    int v410 = (((int)((unsigned int)((int)((unsigned int)(v285 + 68) >> 2)) >> 1)) & 1) * 2;
    int v303 = v302[v410];
    int * v304 = v279->cache_tags;
    int v305 = v304[v410];
    int v306 = v302[v398];
    int v307 = v304[v398];
    bool v412 = !(((~(((v289 ^ ((int)((unsigned int)((int)((unsigned int)(v285 + 68) >> 2)) >> 1))) | (-(v289 ^ ((int)((unsigned int)((int)((unsigned int)(v285 + 68) >> 2)) >> 1))))) >> 31)) | (~(((v290 ^ ((int)((unsigned int)((int)((unsigned int)(v285 + 68) >> 2)) >> 1))) | (-(v290 ^ ((int)((unsigned int)((int)((unsigned int)(v285 + 68) >> 2)) >> 1))))) >> 31))) == 0);
    int v361;
    if (v412) {
      int * v308 = v279->cache_age;
      int v414 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v285 + 68) >> 2)) >> 1)) & 3) * 2)) + ((~(((v290 ^ ((int)((unsigned int)((int)((unsigned int)(v285 + 68) >> 2)) >> 1))) | (-(v290 ^ ((int)((unsigned int)((int)((unsigned int)(v285 + 68) >> 2)) >> 1))))) >> 31)) & 1);
      int v309 = v308[v414];
      int v310 = v308[v399];
      int v415 = v310 + ((int)((unsigned int)(v310 - v309) >> 31));
      v308[v399] = v415;
      int * v312 = v279->cache_age;
      int v313 = v312[v400];
      int v417 = v313 + ((int)((unsigned int)(v313 - v309) >> 31));
      v312[v400] = v417;
      int * v315 = v279->cache_age;
      v315[v414] = 0;
      v361 = v414;
    } else {
      int * v318 = v279->cache_age;
      int v421 = 4 + ((((int)((unsigned int)((int)((unsigned int)(v285 + 68) >> 2)) >> 1)) & 3) * 2);
      int v319 = v318[v421];
      int * v320 = v279->cache_tags;
      int v321 = v320[v421];
      int v322 = v318[v400];
      int v323 = v320[v400];
      int * v324 = v279->cache_dirty;
      int v424 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v285 + 68) >> 2)) >> 1)) & 3) * 2)) + ((((v319 + ((~(((v321 ^ -1) | (-(v321 ^ -1))) >> 31)) & 2)) - (v322 + ((~(((v323 ^ -1) | (-(v323 ^ -1))) >> 31)) & 2))) >> 31) & 1);
      int v325 = v324[v424];
      bool v425 = !(v325 == 0);
      if (v425) {
        int * v326 = v279->cache_tags;
        int v327 = v326[v424];
        int * v328 = v279->cache_vals;
        int v428 = ((4 + ((((int)((unsigned int)((int)((unsigned int)(v285 + 68) >> 2)) >> 1)) & 3) * 2)) + ((((v319 + ((~(((v321 ^ -1) | (-(v321 ^ -1))) >> 31)) & 2)) - (v322 + ((~(((v323 ^ -1) | (-(v323 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
        int v329 = v328[v428];
        int v429 = (((4 + ((((int)((unsigned int)((int)((unsigned int)(v285 + 68) >> 2)) >> 1)) & 3) * 2)) + ((((v319 + ((~(((v321 ^ -1) | (-(v321 ^ -1))) >> 31)) & 2)) - (v322 + ((~(((v323 ^ -1) | (-(v323 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
        int v330 = v328[v429];
        int * v331 = v279->mem;
        int v431 = v327 * 2;
        v331[v431] = v329;
        int * v333 = v279->mem;
        int v434 = (v327 * 2) + 1;
        v333[v434] = v330;
        ;
      } else {
        ;
      }
      int * v338 = v279->mem;
      int v439 = ((int)((unsigned int)((int)((unsigned int)(v285 + 68) >> 2)) >> 1)) * 2;
      int v339 = v338[v439];
      int v440 = (((int)((unsigned int)((int)((unsigned int)(v285 + 68) >> 2)) >> 1)) * 2) + 1;
      int v340 = v338[v440];
      int * v341 = v279->cache_vals;
      int v442 = ((4 + ((((int)((unsigned int)((int)((unsigned int)(v285 + 68) >> 2)) >> 1)) & 3) * 2)) + ((((v319 + ((~(((v321 ^ -1) | (-(v321 ^ -1))) >> 31)) & 2)) - (v322 + ((~(((v323 ^ -1) | (-(v323 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
      v341[v442] = v339;
      int * v343 = v279->cache_vals;
      int v445 = (((4 + ((((int)((unsigned int)((int)((unsigned int)(v285 + 68) >> 2)) >> 1)) & 3) * 2)) + ((((v319 + ((~(((v321 ^ -1) | (-(v321 ^ -1))) >> 31)) & 2)) - (v322 + ((~(((v323 ^ -1) | (-(v323 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
      v343[v445] = v340;
      int * v345 = v279->cache_tags;
      int v448 = (int)((unsigned int)((int)((unsigned int)(v285 + 68) >> 2)) >> 1);
      v345[v424] = v448;
      int * v347 = v279->cache_dirty;
      v347[v424] = 0;
      int * v349 = v279->cache_age;
      v349[v424] = 1;
      int * v351 = v279->cache_age;
      int v352 = v351[v424];
      int v353 = v351[v399];
      int v454 = v353 + ((int)((unsigned int)(v353 - v352) >> 31));
      v351[v399] = v454;
      int * v355 = v279->cache_age;
      int v356 = v355[v400];
      int v456 = v356 + ((int)((unsigned int)(v356 - v352) >> 31));
      v355[v400] = v456;
      int * v358 = v279->cache_age;
      v358[v424] = 0;
      v361 = v424;
    }
    int * v362 = v279->cache_vals;
    int v459 = v361 * 2;
    int v363 = v362[v459];
    int v460 = (v361 * 2) + 1;
    int v364 = v362[v460];
    int v461 = (((((int)((unsigned int)((int)((unsigned int)(v285 + 68) >> 2)) >> 1)) & 1) * 2) + ((((v303 + ((~(((v305 ^ -1) | (-(v305 ^ -1))) >> 31)) & 2)) - (v306 + ((~(((v307 ^ -1) | (-(v307 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
    v362[v461] = v363;
    int * v366 = v279->cache_vals;
    int v464 = ((((((int)((unsigned int)((int)((unsigned int)(v285 + 68) >> 2)) >> 1)) & 1) * 2) + ((((v303 + ((~(((v305 ^ -1) | (-(v305 ^ -1))) >> 31)) & 2)) - (v306 + ((~(((v307 ^ -1) | (-(v307 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
    v366[v464] = v364;
    int * v368 = v279->cache_tags;
    int v467 = ((((int)((unsigned int)((int)((unsigned int)(v285 + 68) >> 2)) >> 1)) & 1) * 2) + ((((v303 + ((~(((v305 ^ -1) | (-(v305 ^ -1))) >> 31)) & 2)) - (v306 + ((~(((v307 ^ -1) | (-(v307 ^ -1))) >> 31)) & 2))) >> 31) & 1);
    int v468 = (int)((unsigned int)((int)((unsigned int)(v285 + 68) >> 2)) >> 1);
    v368[v467] = v468;
    int * v370 = v279->cache_dirty;
    v370[v467] = 0;
    int * v372 = v279->cache_age;
    v372[v467] = 1;
    int * v374 = v279->cache_age;
    int v375 = v374[v467];
    int v376 = v374[v397];
    int v474 = v376 + ((int)((unsigned int)(v376 - v375) >> 31));
    v374[v397] = v474;
    int * v378 = v279->cache_age;
    int v379 = v378[v398];
    int v476 = v379 + ((int)((unsigned int)(v379 - v375) >> 31));
    v378[v398] = v476;
    int * v381 = v279->cache_age;
    v381[v467] = 0;
    v384 = v467;
  }
  int v479 = (v384 * 2) + (((int)((unsigned int)(v285 + 68) >> 2)) & 1);
  int v385 = v291[v479];
  int * v386 = v279->reg_ready;
  int v481 = ((v283 + ((v280 - v283) & (~((v280 - v283) >> 31)))) + 1) + ((100 ^ (((~(((v289 ^ ((int)((unsigned int)((int)((unsigned int)(v285 + 68) >> 2)) >> 1))) | (-(v289 ^ ((int)((unsigned int)((int)((unsigned int)(v285 + 68) >> 2)) >> 1))))) >> 31)) | (~(((v290 ^ ((int)((unsigned int)((int)((unsigned int)(v285 + 68) >> 2)) >> 1))) | (-(v290 ^ ((int)((unsigned int)((int)((unsigned int)(v285 + 68) >> 2)) >> 1))))) >> 31))) & 104)) ^ (((~(((v287 ^ ((int)((unsigned int)((int)((unsigned int)(v285 + 68) >> 2)) >> 1))) | (-(v287 ^ ((int)((unsigned int)((int)((unsigned int)(v285 + 68) >> 2)) >> 1))))) >> 31)) | (~(((v288 ^ ((int)((unsigned int)((int)((unsigned int)(v285 + 68) >> 2)) >> 1))) | (-(v288 ^ ((int)((unsigned int)((int)((unsigned int)(v285 + 68) >> 2)) >> 1))))) >> 31))) & (1 ^ (100 ^ (((~(((v289 ^ ((int)((unsigned int)((int)((unsigned int)(v285 + 68) >> 2)) >> 1))) | (-(v289 ^ ((int)((unsigned int)((int)((unsigned int)(v285 + 68) >> 2)) >> 1))))) >> 31)) | (~(((v290 ^ ((int)((unsigned int)((int)((unsigned int)(v285 + 68) >> 2)) >> 1))) | (-(v290 ^ ((int)((unsigned int)((int)((unsigned int)(v285 + 68) >> 2)) >> 1))))) >> 31))) & 104)))));
  v386[12] = v481;
  int * v388 = v279->regs;
  v388[12] = v385;
  struct StateT * v390 = slot_6(v279);
  return v390;
}

struct StateT * slot_2(struct StateT * v225) {
  int v226 = v225->timer;
  int v230 = v226 + 1;
  v225->timer = v230;
  struct StateT * v228 = slot_3(v225);
  return v228;
}

struct StateT * slot_7(struct StateT * v509) {
  int v510 = v509->timer;
  int v521 = v510 + 1;
  v509->timer = v521;
  int * v512 = v509->reg_ready;
  int v513 = v512[14];
  int * v514 = v509->regs;
  int v515 = v514[14];
  int v525 = (v513 + ((v510 - v513) & (~((v510 - v513) >> 31)))) + 1;
  v512[14] = v525;
  int * v517 = v509->regs;
  int v527 = v515 + 72;
  v517[14] = v527;
  struct StateT * v519 = slot_8(v509);
  return v519;
}

struct StateT * slot_21(struct StateT * v1657) {
  int * v1658 = v1657->saved_regs;
  int * v1659 = v1657->regs;
  int v1660 = v1659[10];
  v1658[10] = v1660;
  int v1662 = v1657->timer;
  int v1674 = v1662 + 1;
  v1657->timer = v1674;
  int * v1664 = v1657->reg_ready;
  v1664[10] = v1674;
  int * v1666 = v1657->regs;
  v1666[10] = 0;
  struct StateT * v1668 = slot_23(v1657);
  return v1668;
}

struct StateT * slot_31(struct StateT * v2482) {
  int v2483 = v2482->timer;
  int v2496 = v2483 + 1;
  v2482->timer = v2496;
  int * v2485 = v2482->reg_ready;
  int v2486 = v2485[12];
  int * v2487 = v2482->regs;
  int v2488 = v2487[12];
  int v2489 = v2485[10];
  int v2490 = v2487[10];
  int v2501 = (v2489 + (((v2486 + ((v2483 - v2486) & (~((v2483 - v2486) >> 31)))) - v2489) & (~(((v2486 + ((v2483 - v2486) & (~((v2483 - v2486) >> 31)))) - v2489) >> 31)))) + 1;
  v2485[12] = v2501;
  int * v2492 = v2482->regs;
  int v2503 = v2488 & v2490;
  v2492[12] = v2503;
  struct StateT * v2494 = slot_32(v2482);
  return v2494;
}

struct StateT * slot_3(struct StateT * v233) {
  int * v234 = v233->saved_regs;
  int * v235 = v233->regs;
  int v236 = v235[13];
  v234[13] = v236;
  int v238 = v233->timer;
  int v250 = v238 + 1;
  v233->timer = v250;
  int * v240 = v233->reg_ready;
  v240[13] = v250;
  int * v242 = v233->regs;
  v242[13] = 0;
  struct StateT * v244 = slot_4(v233);
  return v244;
}

struct StateT * slot_45(struct StateT * v3626) {
  int v3627 = v3626->timer;
  int v3635 = v3627 + 1;
  v3626->timer = v3635;
  int * v3629 = v3626->reg_ready;
  v3629[10] = v3635;
  int * v3631 = v3626->regs;
  v3631[10] = 0;
  struct StateT * v3633 = slot_26(v3626);
  return v3633;
}

struct StateT * slot_26(struct StateT * v1927) {
  int v1928 = v1927->timer;
  int v2101 = v1928 + 1;
  v1927->timer = v2101;
  int * v1930 = v1927->reg_ready;
  int * v1932 = v1927->regs;
  int v1933 = v1932[10];
  int v1935 = v1932[12];
  int * v1936 = v1927->cache_tags;
  int v2107 = (((int)((unsigned int)((int)((unsigned int)(v1933 + 68) >> 2)) >> 1)) & 1) * 2;
  int v1937 = v1936[v2107];
  int v2108 = ((((int)((unsigned int)((int)((unsigned int)(v1933 + 68) >> 2)) >> 1)) & 1) * 2) + 1;
  int v1938 = v1936[v2108];
  int v2109 = 4 + ((((int)((unsigned int)((int)((unsigned int)(v1933 + 68) >> 2)) >> 1)) & 3) * 2);
  int v1939 = v1936[v2109];
  int v2110 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v1933 + 68) >> 2)) >> 1)) & 3) * 2)) + 1;
  int v1940 = v1936[v2110];
  int v1941 = v1927->timer;
  int v2111 = v1941 + ((100 ^ (((~(((v1939 ^ ((int)((unsigned int)((int)((unsigned int)(v1933 + 68) >> 2)) >> 1))) | (-(v1939 ^ ((int)((unsigned int)((int)((unsigned int)(v1933 + 68) >> 2)) >> 1))))) >> 31)) | (~(((v1940 ^ ((int)((unsigned int)((int)((unsigned int)(v1933 + 68) >> 2)) >> 1))) | (-(v1940 ^ ((int)((unsigned int)((int)((unsigned int)(v1933 + 68) >> 2)) >> 1))))) >> 31))) & 104)) ^ (((~(((v1937 ^ ((int)((unsigned int)((int)((unsigned int)(v1933 + 68) >> 2)) >> 1))) | (-(v1937 ^ ((int)((unsigned int)((int)((unsigned int)(v1933 + 68) >> 2)) >> 1))))) >> 31)) | (~(((v1938 ^ ((int)((unsigned int)((int)((unsigned int)(v1933 + 68) >> 2)) >> 1))) | (-(v1938 ^ ((int)((unsigned int)((int)((unsigned int)(v1933 + 68) >> 2)) >> 1))))) >> 31))) & (1 ^ (100 ^ (((~(((v1939 ^ ((int)((unsigned int)((int)((unsigned int)(v1933 + 68) >> 2)) >> 1))) | (-(v1939 ^ ((int)((unsigned int)((int)((unsigned int)(v1933 + 68) >> 2)) >> 1))))) >> 31)) | (~(((v1940 ^ ((int)((unsigned int)((int)((unsigned int)(v1933 + 68) >> 2)) >> 1))) | (-(v1940 ^ ((int)((unsigned int)((int)((unsigned int)(v1933 + 68) >> 2)) >> 1))))) >> 31))) & 104)))));
  v1927->timer = v2111;
  bool v2112 = !(((~(((v1937 ^ ((int)((unsigned int)((int)((unsigned int)(v1933 + 68) >> 2)) >> 1))) | (-(v1937 ^ ((int)((unsigned int)((int)((unsigned int)(v1933 + 68) >> 2)) >> 1))))) >> 31)) | (~(((v1938 ^ ((int)((unsigned int)((int)((unsigned int)(v1933 + 68) >> 2)) >> 1))) | (-(v1938 ^ ((int)((unsigned int)((int)((unsigned int)(v1933 + 68) >> 2)) >> 1))))) >> 31))) == 0);
  int v2035;
  if (v2112) {
    int * v1943 = v1927->cache_age;
    int v2114 = ((((int)((unsigned int)((int)((unsigned int)(v1933 + 68) >> 2)) >> 1)) & 1) * 2) + ((~(((v1938 ^ ((int)((unsigned int)((int)((unsigned int)(v1933 + 68) >> 2)) >> 1))) | (-(v1938 ^ ((int)((unsigned int)((int)((unsigned int)(v1933 + 68) >> 2)) >> 1))))) >> 31)) & 1);
    int v1944 = v1943[v2114];
    int v1945 = v1943[v2107];
    int v2115 = v1945 + ((int)((unsigned int)(v1945 - v1944) >> 31));
    v1943[v2107] = v2115;
    int * v1947 = v1927->cache_age;
    int v1948 = v1947[v2108];
    int v2117 = v1948 + ((int)((unsigned int)(v1948 - v1944) >> 31));
    v1947[v2108] = v2117;
    int * v1950 = v1927->cache_age;
    v1950[v2114] = 0;
    v2035 = v2114;
  } else {
    int * v1953 = v1927->cache_age;
    int v2121 = (((int)((unsigned int)((int)((unsigned int)(v1933 + 68) >> 2)) >> 1)) & 1) * 2;
    int v1954 = v1953[v2121];
    int * v1955 = v1927->cache_tags;
    int v1956 = v1955[v2121];
    int v1957 = v1953[v2108];
    int v1958 = v1955[v2108];
    bool v2123 = !(((~(((v1939 ^ ((int)((unsigned int)((int)((unsigned int)(v1933 + 68) >> 2)) >> 1))) | (-(v1939 ^ ((int)((unsigned int)((int)((unsigned int)(v1933 + 68) >> 2)) >> 1))))) >> 31)) | (~(((v1940 ^ ((int)((unsigned int)((int)((unsigned int)(v1933 + 68) >> 2)) >> 1))) | (-(v1940 ^ ((int)((unsigned int)((int)((unsigned int)(v1933 + 68) >> 2)) >> 1))))) >> 31))) == 0);
    int v2012;
    if (v2123) {
      int * v1959 = v1927->cache_age;
      int v2125 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v1933 + 68) >> 2)) >> 1)) & 3) * 2)) + ((~(((v1940 ^ ((int)((unsigned int)((int)((unsigned int)(v1933 + 68) >> 2)) >> 1))) | (-(v1940 ^ ((int)((unsigned int)((int)((unsigned int)(v1933 + 68) >> 2)) >> 1))))) >> 31)) & 1);
      int v1960 = v1959[v2125];
      int v1961 = v1959[v2109];
      int v2126 = v1961 + ((int)((unsigned int)(v1961 - v1960) >> 31));
      v1959[v2109] = v2126;
      int * v1963 = v1927->cache_age;
      int v1964 = v1963[v2110];
      int v2128 = v1964 + ((int)((unsigned int)(v1964 - v1960) >> 31));
      v1963[v2110] = v2128;
      int * v1966 = v1927->cache_age;
      v1966[v2125] = 0;
      v2012 = v2125;
    } else {
      int * v1969 = v1927->cache_age;
      int v2132 = 4 + ((((int)((unsigned int)((int)((unsigned int)(v1933 + 68) >> 2)) >> 1)) & 3) * 2);
      int v1970 = v1969[v2132];
      int * v1971 = v1927->cache_tags;
      int v1972 = v1971[v2132];
      int v1973 = v1969[v2110];
      int v1974 = v1971[v2110];
      int * v1975 = v1927->cache_dirty;
      int v2135 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v1933 + 68) >> 2)) >> 1)) & 3) * 2)) + ((((v1970 + ((~(((v1972 ^ -1) | (-(v1972 ^ -1))) >> 31)) & 2)) - (v1973 + ((~(((v1974 ^ -1) | (-(v1974 ^ -1))) >> 31)) & 2))) >> 31) & 1);
      int v1976 = v1975[v2135];
      bool v2136 = !(v1976 == 0);
      if (v2136) {
        int * v1977 = v1927->cache_tags;
        int v1978 = v1977[v2135];
        int * v1979 = v1927->cache_vals;
        int v2139 = ((4 + ((((int)((unsigned int)((int)((unsigned int)(v1933 + 68) >> 2)) >> 1)) & 3) * 2)) + ((((v1970 + ((~(((v1972 ^ -1) | (-(v1972 ^ -1))) >> 31)) & 2)) - (v1973 + ((~(((v1974 ^ -1) | (-(v1974 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
        int v1980 = v1979[v2139];
        int v2140 = (((4 + ((((int)((unsigned int)((int)((unsigned int)(v1933 + 68) >> 2)) >> 1)) & 3) * 2)) + ((((v1970 + ((~(((v1972 ^ -1) | (-(v1972 ^ -1))) >> 31)) & 2)) - (v1973 + ((~(((v1974 ^ -1) | (-(v1974 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
        int v1981 = v1979[v2140];
        int * v1982 = v1927->mem;
        int v2142 = v1978 * 2;
        v1982[v2142] = v1980;
        int * v1984 = v1927->mem;
        int v2145 = (v1978 * 2) + 1;
        v1984[v2145] = v1981;
        ;
      } else {
        ;
      }
      int * v1989 = v1927->mem;
      int v2150 = ((int)((unsigned int)((int)((unsigned int)(v1933 + 68) >> 2)) >> 1)) * 2;
      int v1990 = v1989[v2150];
      int v2151 = (((int)((unsigned int)((int)((unsigned int)(v1933 + 68) >> 2)) >> 1)) * 2) + 1;
      int v1991 = v1989[v2151];
      int * v1992 = v1927->cache_vals;
      int v2153 = ((4 + ((((int)((unsigned int)((int)((unsigned int)(v1933 + 68) >> 2)) >> 1)) & 3) * 2)) + ((((v1970 + ((~(((v1972 ^ -1) | (-(v1972 ^ -1))) >> 31)) & 2)) - (v1973 + ((~(((v1974 ^ -1) | (-(v1974 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
      v1992[v2153] = v1990;
      int * v1994 = v1927->cache_vals;
      int v2156 = (((4 + ((((int)((unsigned int)((int)((unsigned int)(v1933 + 68) >> 2)) >> 1)) & 3) * 2)) + ((((v1970 + ((~(((v1972 ^ -1) | (-(v1972 ^ -1))) >> 31)) & 2)) - (v1973 + ((~(((v1974 ^ -1) | (-(v1974 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
      v1994[v2156] = v1991;
      int * v1996 = v1927->cache_tags;
      int v2159 = (int)((unsigned int)((int)((unsigned int)(v1933 + 68) >> 2)) >> 1);
      v1996[v2135] = v2159;
      int * v1998 = v1927->cache_dirty;
      v1998[v2135] = 0;
      int * v2000 = v1927->cache_age;
      v2000[v2135] = 1;
      int * v2002 = v1927->cache_age;
      int v2003 = v2002[v2135];
      int v2004 = v2002[v2109];
      int v2165 = v2004 + ((int)((unsigned int)(v2004 - v2003) >> 31));
      v2002[v2109] = v2165;
      int * v2006 = v1927->cache_age;
      int v2007 = v2006[v2110];
      int v2167 = v2007 + ((int)((unsigned int)(v2007 - v2003) >> 31));
      v2006[v2110] = v2167;
      int * v2009 = v1927->cache_age;
      v2009[v2135] = 0;
      v2012 = v2135;
    }
    int * v2013 = v1927->cache_vals;
    int v2170 = v2012 * 2;
    int v2014 = v2013[v2170];
    int v2171 = (v2012 * 2) + 1;
    int v2015 = v2013[v2171];
    int v2172 = (((((int)((unsigned int)((int)((unsigned int)(v1933 + 68) >> 2)) >> 1)) & 1) * 2) + ((((v1954 + ((~(((v1956 ^ -1) | (-(v1956 ^ -1))) >> 31)) & 2)) - (v1957 + ((~(((v1958 ^ -1) | (-(v1958 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
    v2013[v2172] = v2014;
    int * v2017 = v1927->cache_vals;
    int v2175 = ((((((int)((unsigned int)((int)((unsigned int)(v1933 + 68) >> 2)) >> 1)) & 1) * 2) + ((((v1954 + ((~(((v1956 ^ -1) | (-(v1956 ^ -1))) >> 31)) & 2)) - (v1957 + ((~(((v1958 ^ -1) | (-(v1958 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
    v2017[v2175] = v2015;
    int * v2019 = v1927->cache_tags;
    int v2178 = ((((int)((unsigned int)((int)((unsigned int)(v1933 + 68) >> 2)) >> 1)) & 1) * 2) + ((((v1954 + ((~(((v1956 ^ -1) | (-(v1956 ^ -1))) >> 31)) & 2)) - (v1957 + ((~(((v1958 ^ -1) | (-(v1958 ^ -1))) >> 31)) & 2))) >> 31) & 1);
    int v2179 = (int)((unsigned int)((int)((unsigned int)(v1933 + 68) >> 2)) >> 1);
    v2019[v2178] = v2179;
    int * v2021 = v1927->cache_dirty;
    v2021[v2178] = 0;
    int * v2023 = v1927->cache_age;
    v2023[v2178] = 1;
    int * v2025 = v1927->cache_age;
    int v2026 = v2025[v2178];
    int v2027 = v2025[v2107];
    int v2185 = v2027 + ((int)((unsigned int)(v2027 - v2026) >> 31));
    v2025[v2107] = v2185;
    int * v2029 = v1927->cache_age;
    int v2030 = v2029[v2108];
    int v2187 = v2030 + ((int)((unsigned int)(v2030 - v2026) >> 31));
    v2029[v2108] = v2187;
    int * v2032 = v1927->cache_age;
    v2032[v2178] = 0;
    v2035 = v2178;
  }
  int * v2036 = v1927->cache_vals;
  int v2190 = (v2035 * 2) + (((int)((unsigned int)(v1933 + 68) >> 2)) & 1);
  v2036[v2190] = v1935;
  int * v2038 = v1927->cache_tags;
  int v2039 = v2038[v2109];
  int v2040 = v2038[v2110];
  bool v2193 = !(((~(((v2039 ^ ((int)((unsigned int)((int)((unsigned int)(v1933 + 68) >> 2)) >> 1))) | (-(v2039 ^ ((int)((unsigned int)((int)((unsigned int)(v1933 + 68) >> 2)) >> 1))))) >> 31)) | (~(((v2040 ^ ((int)((unsigned int)((int)((unsigned int)(v1933 + 68) >> 2)) >> 1))) | (-(v2040 ^ ((int)((unsigned int)((int)((unsigned int)(v1933 + 68) >> 2)) >> 1))))) >> 31))) == 0);
  int v2094;
  if (v2193) {
    int * v2041 = v1927->cache_age;
    int v2195 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v1933 + 68) >> 2)) >> 1)) & 3) * 2)) + ((~(((v2040 ^ ((int)((unsigned int)((int)((unsigned int)(v1933 + 68) >> 2)) >> 1))) | (-(v2040 ^ ((int)((unsigned int)((int)((unsigned int)(v1933 + 68) >> 2)) >> 1))))) >> 31)) & 1);
    int v2042 = v2041[v2195];
    int v2043 = v2041[v2109];
    int v2196 = v2043 + ((int)((unsigned int)(v2043 - v2042) >> 31));
    v2041[v2109] = v2196;
    int * v2045 = v1927->cache_age;
    int v2046 = v2045[v2110];
    int v2198 = v2046 + ((int)((unsigned int)(v2046 - v2042) >> 31));
    v2045[v2110] = v2198;
    int * v2048 = v1927->cache_age;
    v2048[v2195] = 0;
    v2094 = v2195;
  } else {
    int * v2051 = v1927->cache_age;
    int v2202 = 4 + ((((int)((unsigned int)((int)((unsigned int)(v1933 + 68) >> 2)) >> 1)) & 3) * 2);
    int v2052 = v2051[v2202];
    int * v2053 = v1927->cache_tags;
    int v2054 = v2053[v2202];
    int v2055 = v2051[v2110];
    int v2056 = v2053[v2110];
    int * v2057 = v1927->cache_dirty;
    int v2205 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v1933 + 68) >> 2)) >> 1)) & 3) * 2)) + ((((v2052 + ((~(((v2054 ^ -1) | (-(v2054 ^ -1))) >> 31)) & 2)) - (v2055 + ((~(((v2056 ^ -1) | (-(v2056 ^ -1))) >> 31)) & 2))) >> 31) & 1);
    int v2058 = v2057[v2205];
    bool v2206 = !(v2058 == 0);
    if (v2206) {
      int * v2059 = v1927->cache_tags;
      int v2060 = v2059[v2205];
      int * v2061 = v1927->cache_vals;
      int v2209 = ((4 + ((((int)((unsigned int)((int)((unsigned int)(v1933 + 68) >> 2)) >> 1)) & 3) * 2)) + ((((v2052 + ((~(((v2054 ^ -1) | (-(v2054 ^ -1))) >> 31)) & 2)) - (v2055 + ((~(((v2056 ^ -1) | (-(v2056 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
      int v2062 = v2061[v2209];
      int v2210 = (((4 + ((((int)((unsigned int)((int)((unsigned int)(v1933 + 68) >> 2)) >> 1)) & 3) * 2)) + ((((v2052 + ((~(((v2054 ^ -1) | (-(v2054 ^ -1))) >> 31)) & 2)) - (v2055 + ((~(((v2056 ^ -1) | (-(v2056 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
      int v2063 = v2061[v2210];
      int * v2064 = v1927->mem;
      int v2212 = v2060 * 2;
      v2064[v2212] = v2062;
      int * v2066 = v1927->mem;
      int v2215 = (v2060 * 2) + 1;
      v2066[v2215] = v2063;
      ;
    } else {
      ;
    }
    int * v2071 = v1927->mem;
    int v2220 = ((int)((unsigned int)((int)((unsigned int)(v1933 + 68) >> 2)) >> 1)) * 2;
    int v2072 = v2071[v2220];
    int v2221 = (((int)((unsigned int)((int)((unsigned int)(v1933 + 68) >> 2)) >> 1)) * 2) + 1;
    int v2073 = v2071[v2221];
    int * v2074 = v1927->cache_vals;
    int v2223 = ((4 + ((((int)((unsigned int)((int)((unsigned int)(v1933 + 68) >> 2)) >> 1)) & 3) * 2)) + ((((v2052 + ((~(((v2054 ^ -1) | (-(v2054 ^ -1))) >> 31)) & 2)) - (v2055 + ((~(((v2056 ^ -1) | (-(v2056 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
    v2074[v2223] = v2072;
    int * v2076 = v1927->cache_vals;
    int v2226 = (((4 + ((((int)((unsigned int)((int)((unsigned int)(v1933 + 68) >> 2)) >> 1)) & 3) * 2)) + ((((v2052 + ((~(((v2054 ^ -1) | (-(v2054 ^ -1))) >> 31)) & 2)) - (v2055 + ((~(((v2056 ^ -1) | (-(v2056 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
    v2076[v2226] = v2073;
    int * v2078 = v1927->cache_tags;
    int v2229 = (int)((unsigned int)((int)((unsigned int)(v1933 + 68) >> 2)) >> 1);
    v2078[v2205] = v2229;
    int * v2080 = v1927->cache_dirty;
    v2080[v2205] = 0;
    int * v2082 = v1927->cache_age;
    v2082[v2205] = 1;
    int * v2084 = v1927->cache_age;
    int v2085 = v2084[v2205];
    int v2086 = v2084[v2109];
    int v2235 = v2086 + ((int)((unsigned int)(v2086 - v2085) >> 31));
    v2084[v2109] = v2235;
    int * v2088 = v1927->cache_age;
    int v2089 = v2088[v2110];
    int v2237 = v2089 + ((int)((unsigned int)(v2089 - v2085) >> 31));
    v2088[v2110] = v2237;
    int * v2091 = v1927->cache_age;
    v2091[v2205] = 0;
    v2094 = v2205;
  }
  int * v2095 = v1927->cache_vals;
  int v2240 = (v2094 * 2) + (((int)((unsigned int)(v1933 + 68) >> 2)) & 1);
  v2095[v2240] = v1935;
  int * v2097 = v1927->cache_dirty;
  v2097[v2094] = 1;
  struct StateT * v2099 = slot_13(v1927);
  return v2099;
}

struct StateT * slot_10(struct StateT * v582) {
  int v583 = v582->timer;
  int v695 = v583 + 1;
  v582->timer = v695;
  int * v585 = v582->reg_ready;
  int v586 = v585[10];
  int * v587 = v582->regs;
  int v588 = v587[10];
  int * v589 = v582->cache_tags;
  int v700 = (((int)((unsigned int)((int)((unsigned int)v588 >> 2)) >> 1)) & 1) * 2;
  int v590 = v589[v700];
  int v701 = ((((int)((unsigned int)((int)((unsigned int)v588 >> 2)) >> 1)) & 1) * 2) + 1;
  int v591 = v589[v701];
  int v702 = 4 + ((((int)((unsigned int)((int)((unsigned int)v588 >> 2)) >> 1)) & 3) * 2);
  int v592 = v589[v702];
  int v703 = (4 + ((((int)((unsigned int)((int)((unsigned int)v588 >> 2)) >> 1)) & 3) * 2)) + 1;
  int v593 = v589[v703];
  int * v594 = v582->cache_vals;
  bool v704 = !(((~(((v590 ^ ((int)((unsigned int)((int)((unsigned int)v588 >> 2)) >> 1))) | (-(v590 ^ ((int)((unsigned int)((int)((unsigned int)v588 >> 2)) >> 1))))) >> 31)) | (~(((v591 ^ ((int)((unsigned int)((int)((unsigned int)v588 >> 2)) >> 1))) | (-(v591 ^ ((int)((unsigned int)((int)((unsigned int)v588 >> 2)) >> 1))))) >> 31))) == 0);
  int v687;
  if (v704) {
    int * v595 = v582->cache_age;
    int v706 = ((((int)((unsigned int)((int)((unsigned int)v588 >> 2)) >> 1)) & 1) * 2) + ((~(((v591 ^ ((int)((unsigned int)((int)((unsigned int)v588 >> 2)) >> 1))) | (-(v591 ^ ((int)((unsigned int)((int)((unsigned int)v588 >> 2)) >> 1))))) >> 31)) & 1);
    int v596 = v595[v706];
    int v597 = v595[v700];
    int v707 = v597 + ((int)((unsigned int)(v597 - v596) >> 31));
    v595[v700] = v707;
    int * v599 = v582->cache_age;
    int v600 = v599[v701];
    int v709 = v600 + ((int)((unsigned int)(v600 - v596) >> 31));
    v599[v701] = v709;
    int * v602 = v582->cache_age;
    v602[v706] = 0;
    v687 = v706;
  } else {
    int * v605 = v582->cache_age;
    int v713 = (((int)((unsigned int)((int)((unsigned int)v588 >> 2)) >> 1)) & 1) * 2;
    int v606 = v605[v713];
    int * v607 = v582->cache_tags;
    int v608 = v607[v713];
    int v609 = v605[v701];
    int v610 = v607[v701];
    bool v715 = !(((~(((v592 ^ ((int)((unsigned int)((int)((unsigned int)v588 >> 2)) >> 1))) | (-(v592 ^ ((int)((unsigned int)((int)((unsigned int)v588 >> 2)) >> 1))))) >> 31)) | (~(((v593 ^ ((int)((unsigned int)((int)((unsigned int)v588 >> 2)) >> 1))) | (-(v593 ^ ((int)((unsigned int)((int)((unsigned int)v588 >> 2)) >> 1))))) >> 31))) == 0);
    int v664;
    if (v715) {
      int * v611 = v582->cache_age;
      int v717 = (4 + ((((int)((unsigned int)((int)((unsigned int)v588 >> 2)) >> 1)) & 3) * 2)) + ((~(((v593 ^ ((int)((unsigned int)((int)((unsigned int)v588 >> 2)) >> 1))) | (-(v593 ^ ((int)((unsigned int)((int)((unsigned int)v588 >> 2)) >> 1))))) >> 31)) & 1);
      int v612 = v611[v717];
      int v613 = v611[v702];
      int v718 = v613 + ((int)((unsigned int)(v613 - v612) >> 31));
      v611[v702] = v718;
      int * v615 = v582->cache_age;
      int v616 = v615[v703];
      int v720 = v616 + ((int)((unsigned int)(v616 - v612) >> 31));
      v615[v703] = v720;
      int * v618 = v582->cache_age;
      v618[v717] = 0;
      v664 = v717;
    } else {
      int * v621 = v582->cache_age;
      int v724 = 4 + ((((int)((unsigned int)((int)((unsigned int)v588 >> 2)) >> 1)) & 3) * 2);
      int v622 = v621[v724];
      int * v623 = v582->cache_tags;
      int v624 = v623[v724];
      int v625 = v621[v703];
      int v626 = v623[v703];
      int * v627 = v582->cache_dirty;
      int v727 = (4 + ((((int)((unsigned int)((int)((unsigned int)v588 >> 2)) >> 1)) & 3) * 2)) + ((((v622 + ((~(((v624 ^ -1) | (-(v624 ^ -1))) >> 31)) & 2)) - (v625 + ((~(((v626 ^ -1) | (-(v626 ^ -1))) >> 31)) & 2))) >> 31) & 1);
      int v628 = v627[v727];
      bool v728 = !(v628 == 0);
      if (v728) {
        int * v629 = v582->cache_tags;
        int v630 = v629[v727];
        int * v631 = v582->cache_vals;
        int v731 = ((4 + ((((int)((unsigned int)((int)((unsigned int)v588 >> 2)) >> 1)) & 3) * 2)) + ((((v622 + ((~(((v624 ^ -1) | (-(v624 ^ -1))) >> 31)) & 2)) - (v625 + ((~(((v626 ^ -1) | (-(v626 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
        int v632 = v631[v731];
        int v732 = (((4 + ((((int)((unsigned int)((int)((unsigned int)v588 >> 2)) >> 1)) & 3) * 2)) + ((((v622 + ((~(((v624 ^ -1) | (-(v624 ^ -1))) >> 31)) & 2)) - (v625 + ((~(((v626 ^ -1) | (-(v626 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
        int v633 = v631[v732];
        int * v634 = v582->mem;
        int v734 = v630 * 2;
        v634[v734] = v632;
        int * v636 = v582->mem;
        int v737 = (v630 * 2) + 1;
        v636[v737] = v633;
        ;
      } else {
        ;
      }
      int * v641 = v582->mem;
      int v742 = ((int)((unsigned int)((int)((unsigned int)v588 >> 2)) >> 1)) * 2;
      int v642 = v641[v742];
      int v743 = (((int)((unsigned int)((int)((unsigned int)v588 >> 2)) >> 1)) * 2) + 1;
      int v643 = v641[v743];
      int * v644 = v582->cache_vals;
      int v745 = ((4 + ((((int)((unsigned int)((int)((unsigned int)v588 >> 2)) >> 1)) & 3) * 2)) + ((((v622 + ((~(((v624 ^ -1) | (-(v624 ^ -1))) >> 31)) & 2)) - (v625 + ((~(((v626 ^ -1) | (-(v626 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
      v644[v745] = v642;
      int * v646 = v582->cache_vals;
      int v748 = (((4 + ((((int)((unsigned int)((int)((unsigned int)v588 >> 2)) >> 1)) & 3) * 2)) + ((((v622 + ((~(((v624 ^ -1) | (-(v624 ^ -1))) >> 31)) & 2)) - (v625 + ((~(((v626 ^ -1) | (-(v626 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
      v646[v748] = v643;
      int * v648 = v582->cache_tags;
      int v751 = (int)((unsigned int)((int)((unsigned int)v588 >> 2)) >> 1);
      v648[v727] = v751;
      int * v650 = v582->cache_dirty;
      v650[v727] = 0;
      int * v652 = v582->cache_age;
      v652[v727] = 1;
      int * v654 = v582->cache_age;
      int v655 = v654[v727];
      int v656 = v654[v702];
      int v757 = v656 + ((int)((unsigned int)(v656 - v655) >> 31));
      v654[v702] = v757;
      int * v658 = v582->cache_age;
      int v659 = v658[v703];
      int v759 = v659 + ((int)((unsigned int)(v659 - v655) >> 31));
      v658[v703] = v759;
      int * v661 = v582->cache_age;
      v661[v727] = 0;
      v664 = v727;
    }
    int * v665 = v582->cache_vals;
    int v762 = v664 * 2;
    int v666 = v665[v762];
    int v763 = (v664 * 2) + 1;
    int v667 = v665[v763];
    int v764 = (((((int)((unsigned int)((int)((unsigned int)v588 >> 2)) >> 1)) & 1) * 2) + ((((v606 + ((~(((v608 ^ -1) | (-(v608 ^ -1))) >> 31)) & 2)) - (v609 + ((~(((v610 ^ -1) | (-(v610 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
    v665[v764] = v666;
    int * v669 = v582->cache_vals;
    int v767 = ((((((int)((unsigned int)((int)((unsigned int)v588 >> 2)) >> 1)) & 1) * 2) + ((((v606 + ((~(((v608 ^ -1) | (-(v608 ^ -1))) >> 31)) & 2)) - (v609 + ((~(((v610 ^ -1) | (-(v610 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
    v669[v767] = v667;
    int * v671 = v582->cache_tags;
    int v770 = ((((int)((unsigned int)((int)((unsigned int)v588 >> 2)) >> 1)) & 1) * 2) + ((((v606 + ((~(((v608 ^ -1) | (-(v608 ^ -1))) >> 31)) & 2)) - (v609 + ((~(((v610 ^ -1) | (-(v610 ^ -1))) >> 31)) & 2))) >> 31) & 1);
    int v771 = (int)((unsigned int)((int)((unsigned int)v588 >> 2)) >> 1);
    v671[v770] = v771;
    int * v673 = v582->cache_dirty;
    v673[v770] = 0;
    int * v675 = v582->cache_age;
    v675[v770] = 1;
    int * v677 = v582->cache_age;
    int v678 = v677[v770];
    int v679 = v677[v700];
    int v777 = v679 + ((int)((unsigned int)(v679 - v678) >> 31));
    v677[v700] = v777;
    int * v681 = v582->cache_age;
    int v682 = v681[v701];
    int v779 = v682 + ((int)((unsigned int)(v682 - v678) >> 31));
    v681[v701] = v779;
    int * v684 = v582->cache_age;
    v684[v770] = 0;
    v687 = v770;
  }
  int v782 = (v687 * 2) + (((int)((unsigned int)v588 >> 2)) & 1);
  int v688 = v594[v782];
  int * v689 = v582->reg_ready;
  int v784 = ((v586 + ((v583 - v586) & (~((v583 - v586) >> 31)))) + 1) + ((100 ^ (((~(((v592 ^ ((int)((unsigned int)((int)((unsigned int)v588 >> 2)) >> 1))) | (-(v592 ^ ((int)((unsigned int)((int)((unsigned int)v588 >> 2)) >> 1))))) >> 31)) | (~(((v593 ^ ((int)((unsigned int)((int)((unsigned int)v588 >> 2)) >> 1))) | (-(v593 ^ ((int)((unsigned int)((int)((unsigned int)v588 >> 2)) >> 1))))) >> 31))) & 104)) ^ (((~(((v590 ^ ((int)((unsigned int)((int)((unsigned int)v588 >> 2)) >> 1))) | (-(v590 ^ ((int)((unsigned int)((int)((unsigned int)v588 >> 2)) >> 1))))) >> 31)) | (~(((v591 ^ ((int)((unsigned int)((int)((unsigned int)v588 >> 2)) >> 1))) | (-(v591 ^ ((int)((unsigned int)((int)((unsigned int)v588 >> 2)) >> 1))))) >> 31))) & (1 ^ (100 ^ (((~(((v592 ^ ((int)((unsigned int)((int)((unsigned int)v588 >> 2)) >> 1))) | (-(v592 ^ ((int)((unsigned int)((int)((unsigned int)v588 >> 2)) >> 1))))) >> 31)) | (~(((v593 ^ ((int)((unsigned int)((int)((unsigned int)v588 >> 2)) >> 1))) | (-(v593 ^ ((int)((unsigned int)((int)((unsigned int)v588 >> 2)) >> 1))))) >> 31))) & 104)))));
  v689[10] = v784;
  int * v691 = v582->regs;
  v691[10] = v688;
  struct StateT * v693 = slot_11(v582);
  return v693;
}

struct StateT * slot_1(struct StateT * v18) {
  int v19 = v18->timer;
  int v131 = v19 + 1;
  v18->timer = v131;
  int * v21 = v18->reg_ready;
  int v22 = v21[11];
  int * v23 = v18->regs;
  int v24 = v23[11];
  int * v25 = v18->cache_tags;
  int v136 = (((int)((unsigned int)((int)((unsigned int)v24 >> 2)) >> 1)) & 1) * 2;
  int v26 = v25[v136];
  int v137 = ((((int)((unsigned int)((int)((unsigned int)v24 >> 2)) >> 1)) & 1) * 2) + 1;
  int v27 = v25[v137];
  int v138 = 4 + ((((int)((unsigned int)((int)((unsigned int)v24 >> 2)) >> 1)) & 3) * 2);
  int v28 = v25[v138];
  int v139 = (4 + ((((int)((unsigned int)((int)((unsigned int)v24 >> 2)) >> 1)) & 3) * 2)) + 1;
  int v29 = v25[v139];
  int * v30 = v18->cache_vals;
  bool v140 = !(((~(((v26 ^ ((int)((unsigned int)((int)((unsigned int)v24 >> 2)) >> 1))) | (-(v26 ^ ((int)((unsigned int)((int)((unsigned int)v24 >> 2)) >> 1))))) >> 31)) | (~(((v27 ^ ((int)((unsigned int)((int)((unsigned int)v24 >> 2)) >> 1))) | (-(v27 ^ ((int)((unsigned int)((int)((unsigned int)v24 >> 2)) >> 1))))) >> 31))) == 0);
  int v123;
  if (v140) {
    int * v31 = v18->cache_age;
    int v142 = ((((int)((unsigned int)((int)((unsigned int)v24 >> 2)) >> 1)) & 1) * 2) + ((~(((v27 ^ ((int)((unsigned int)((int)((unsigned int)v24 >> 2)) >> 1))) | (-(v27 ^ ((int)((unsigned int)((int)((unsigned int)v24 >> 2)) >> 1))))) >> 31)) & 1);
    int v32 = v31[v142];
    int v33 = v31[v136];
    int v143 = v33 + ((int)((unsigned int)(v33 - v32) >> 31));
    v31[v136] = v143;
    int * v35 = v18->cache_age;
    int v36 = v35[v137];
    int v145 = v36 + ((int)((unsigned int)(v36 - v32) >> 31));
    v35[v137] = v145;
    int * v38 = v18->cache_age;
    v38[v142] = 0;
    v123 = v142;
  } else {
    int * v41 = v18->cache_age;
    int v149 = (((int)((unsigned int)((int)((unsigned int)v24 >> 2)) >> 1)) & 1) * 2;
    int v42 = v41[v149];
    int * v43 = v18->cache_tags;
    int v44 = v43[v149];
    int v45 = v41[v137];
    int v46 = v43[v137];
    bool v151 = !(((~(((v28 ^ ((int)((unsigned int)((int)((unsigned int)v24 >> 2)) >> 1))) | (-(v28 ^ ((int)((unsigned int)((int)((unsigned int)v24 >> 2)) >> 1))))) >> 31)) | (~(((v29 ^ ((int)((unsigned int)((int)((unsigned int)v24 >> 2)) >> 1))) | (-(v29 ^ ((int)((unsigned int)((int)((unsigned int)v24 >> 2)) >> 1))))) >> 31))) == 0);
    int v100;
    if (v151) {
      int * v47 = v18->cache_age;
      int v153 = (4 + ((((int)((unsigned int)((int)((unsigned int)v24 >> 2)) >> 1)) & 3) * 2)) + ((~(((v29 ^ ((int)((unsigned int)((int)((unsigned int)v24 >> 2)) >> 1))) | (-(v29 ^ ((int)((unsigned int)((int)((unsigned int)v24 >> 2)) >> 1))))) >> 31)) & 1);
      int v48 = v47[v153];
      int v49 = v47[v138];
      int v154 = v49 + ((int)((unsigned int)(v49 - v48) >> 31));
      v47[v138] = v154;
      int * v51 = v18->cache_age;
      int v52 = v51[v139];
      int v156 = v52 + ((int)((unsigned int)(v52 - v48) >> 31));
      v51[v139] = v156;
      int * v54 = v18->cache_age;
      v54[v153] = 0;
      v100 = v153;
    } else {
      int * v57 = v18->cache_age;
      int v160 = 4 + ((((int)((unsigned int)((int)((unsigned int)v24 >> 2)) >> 1)) & 3) * 2);
      int v58 = v57[v160];
      int * v59 = v18->cache_tags;
      int v60 = v59[v160];
      int v61 = v57[v139];
      int v62 = v59[v139];
      int * v63 = v18->cache_dirty;
      int v163 = (4 + ((((int)((unsigned int)((int)((unsigned int)v24 >> 2)) >> 1)) & 3) * 2)) + ((((v58 + ((~(((v60 ^ -1) | (-(v60 ^ -1))) >> 31)) & 2)) - (v61 + ((~(((v62 ^ -1) | (-(v62 ^ -1))) >> 31)) & 2))) >> 31) & 1);
      int v64 = v63[v163];
      bool v164 = !(v64 == 0);
      if (v164) {
        int * v65 = v18->cache_tags;
        int v66 = v65[v163];
        int * v67 = v18->cache_vals;
        int v167 = ((4 + ((((int)((unsigned int)((int)((unsigned int)v24 >> 2)) >> 1)) & 3) * 2)) + ((((v58 + ((~(((v60 ^ -1) | (-(v60 ^ -1))) >> 31)) & 2)) - (v61 + ((~(((v62 ^ -1) | (-(v62 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
        int v68 = v67[v167];
        int v168 = (((4 + ((((int)((unsigned int)((int)((unsigned int)v24 >> 2)) >> 1)) & 3) * 2)) + ((((v58 + ((~(((v60 ^ -1) | (-(v60 ^ -1))) >> 31)) & 2)) - (v61 + ((~(((v62 ^ -1) | (-(v62 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
        int v69 = v67[v168];
        int * v70 = v18->mem;
        int v170 = v66 * 2;
        v70[v170] = v68;
        int * v72 = v18->mem;
        int v173 = (v66 * 2) + 1;
        v72[v173] = v69;
        ;
      } else {
        ;
      }
      int * v77 = v18->mem;
      int v178 = ((int)((unsigned int)((int)((unsigned int)v24 >> 2)) >> 1)) * 2;
      int v78 = v77[v178];
      int v179 = (((int)((unsigned int)((int)((unsigned int)v24 >> 2)) >> 1)) * 2) + 1;
      int v79 = v77[v179];
      int * v80 = v18->cache_vals;
      int v181 = ((4 + ((((int)((unsigned int)((int)((unsigned int)v24 >> 2)) >> 1)) & 3) * 2)) + ((((v58 + ((~(((v60 ^ -1) | (-(v60 ^ -1))) >> 31)) & 2)) - (v61 + ((~(((v62 ^ -1) | (-(v62 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
      v80[v181] = v78;
      int * v82 = v18->cache_vals;
      int v184 = (((4 + ((((int)((unsigned int)((int)((unsigned int)v24 >> 2)) >> 1)) & 3) * 2)) + ((((v58 + ((~(((v60 ^ -1) | (-(v60 ^ -1))) >> 31)) & 2)) - (v61 + ((~(((v62 ^ -1) | (-(v62 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
      v82[v184] = v79;
      int * v84 = v18->cache_tags;
      int v187 = (int)((unsigned int)((int)((unsigned int)v24 >> 2)) >> 1);
      v84[v163] = v187;
      int * v86 = v18->cache_dirty;
      v86[v163] = 0;
      int * v88 = v18->cache_age;
      v88[v163] = 1;
      int * v90 = v18->cache_age;
      int v91 = v90[v163];
      int v92 = v90[v138];
      int v193 = v92 + ((int)((unsigned int)(v92 - v91) >> 31));
      v90[v138] = v193;
      int * v94 = v18->cache_age;
      int v95 = v94[v139];
      int v195 = v95 + ((int)((unsigned int)(v95 - v91) >> 31));
      v94[v139] = v195;
      int * v97 = v18->cache_age;
      v97[v163] = 0;
      v100 = v163;
    }
    int * v101 = v18->cache_vals;
    int v198 = v100 * 2;
    int v102 = v101[v198];
    int v199 = (v100 * 2) + 1;
    int v103 = v101[v199];
    int v200 = (((((int)((unsigned int)((int)((unsigned int)v24 >> 2)) >> 1)) & 1) * 2) + ((((v42 + ((~(((v44 ^ -1) | (-(v44 ^ -1))) >> 31)) & 2)) - (v45 + ((~(((v46 ^ -1) | (-(v46 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
    v101[v200] = v102;
    int * v105 = v18->cache_vals;
    int v203 = ((((((int)((unsigned int)((int)((unsigned int)v24 >> 2)) >> 1)) & 1) * 2) + ((((v42 + ((~(((v44 ^ -1) | (-(v44 ^ -1))) >> 31)) & 2)) - (v45 + ((~(((v46 ^ -1) | (-(v46 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
    v105[v203] = v103;
    int * v107 = v18->cache_tags;
    int v206 = ((((int)((unsigned int)((int)((unsigned int)v24 >> 2)) >> 1)) & 1) * 2) + ((((v42 + ((~(((v44 ^ -1) | (-(v44 ^ -1))) >> 31)) & 2)) - (v45 + ((~(((v46 ^ -1) | (-(v46 ^ -1))) >> 31)) & 2))) >> 31) & 1);
    int v207 = (int)((unsigned int)((int)((unsigned int)v24 >> 2)) >> 1);
    v107[v206] = v207;
    int * v109 = v18->cache_dirty;
    v109[v206] = 0;
    int * v111 = v18->cache_age;
    v111[v206] = 1;
    int * v113 = v18->cache_age;
    int v114 = v113[v206];
    int v115 = v113[v136];
    int v213 = v115 + ((int)((unsigned int)(v115 - v114) >> 31));
    v113[v136] = v213;
    int * v117 = v18->cache_age;
    int v118 = v117[v137];
    int v215 = v118 + ((int)((unsigned int)(v118 - v114) >> 31));
    v117[v137] = v215;
    int * v120 = v18->cache_age;
    v120[v206] = 0;
    v123 = v206;
  }
  int v218 = (v123 * 2) + (((int)((unsigned int)v24 >> 2)) & 1);
  int v124 = v30[v218];
  int * v125 = v18->reg_ready;
  int v220 = ((v22 + ((v19 - v22) & (~((v19 - v22) >> 31)))) + 1) + ((100 ^ (((~(((v28 ^ ((int)((unsigned int)((int)((unsigned int)v24 >> 2)) >> 1))) | (-(v28 ^ ((int)((unsigned int)((int)((unsigned int)v24 >> 2)) >> 1))))) >> 31)) | (~(((v29 ^ ((int)((unsigned int)((int)((unsigned int)v24 >> 2)) >> 1))) | (-(v29 ^ ((int)((unsigned int)((int)((unsigned int)v24 >> 2)) >> 1))))) >> 31))) & 104)) ^ (((~(((v26 ^ ((int)((unsigned int)((int)((unsigned int)v24 >> 2)) >> 1))) | (-(v26 ^ ((int)((unsigned int)((int)((unsigned int)v24 >> 2)) >> 1))))) >> 31)) | (~(((v27 ^ ((int)((unsigned int)((int)((unsigned int)v24 >> 2)) >> 1))) | (-(v27 ^ ((int)((unsigned int)((int)((unsigned int)v24 >> 2)) >> 1))))) >> 31))) & (1 ^ (100 ^ (((~(((v28 ^ ((int)((unsigned int)((int)((unsigned int)v24 >> 2)) >> 1))) | (-(v28 ^ ((int)((unsigned int)((int)((unsigned int)v24 >> 2)) >> 1))))) >> 31)) | (~(((v29 ^ ((int)((unsigned int)((int)((unsigned int)v24 >> 2)) >> 1))) | (-(v29 ^ ((int)((unsigned int)((int)((unsigned int)v24 >> 2)) >> 1))))) >> 31))) & 104)))));
  v125[11] = v220;
  int * v127 = v18->regs;
  v127[11] = v124;
  struct StateT * v129 = slot_2(v18);
  return v129;
}

struct StateT * slot_19(struct StateT * v1330) {
  int v1331 = v1330->timer;
  int v1335 = v1331 + 1;
  v1330->timer = v1335;
  struct StateT * v1333 = slot_21(v1330);
  return v1333;
}

struct StateT * slot_13(struct StateT * v1055) {
  int v1056 = v1055->timer;
  int v1059 = v1056 + 1;
  v1055->timer = v1059;
  return v1055;
}

struct StateT * slot_38(struct StateT * v3103) {
  int * v3104 = v3103->saved_regs;
  int * v3105 = v3103->regs;
  int v3106 = v3105[10];
  v3104[10] = v3106;
  int v3108 = v3103->timer;
  int v3123 = v3108 + 1;
  v3103->timer = v3123;
  int * v3110 = v3103->reg_ready;
  int v3111 = v3110[10];
  int * v3112 = v3103->regs;
  int v3113 = v3112[10];
  int v3126 = (v3111 + ((v3108 - v3111) & (~((v3108 - v3111) >> 31)))) + 1;
  v3110[10] = v3126;
  int * v3115 = v3103->regs;
  int v3128 = v3113 << 2;
  v3115[10] = v3128;
  struct StateT * v3117 = slot_40(v3103);
  return v3117;
}

struct StateT * slot_0(struct StateT * v2) {
  int v3 = v2->timer;
  int v11 = v3 + 1;
  v2->timer = v11;
  int * v5 = v2->reg_ready;
  v5[11] = v11;
  int * v7 = v2->regs;
  v7[11] = 0;
  struct StateT * v9 = slot_1(v2);
  return v9;
}

struct StateT * slot_14(struct StateT * v1060) {
  int v1061 = v1060->timer;
  int v1065 = v1061 + 1;
  v1060->timer = v1065;
  struct StateT * v1063 = slot_16(v1060);
  return v1063;
}

struct StateT * slot_42(struct StateT * v3160) {
  int v3161 = v3160->timer;
  int v3273 = v3161 + 1;
  v3160->timer = v3273;
  int * v3163 = v3160->reg_ready;
  int v3164 = v3163[10];
  int * v3165 = v3160->regs;
  int v3166 = v3165[10];
  int * v3167 = v3160->cache_tags;
  int v3278 = (((int)((unsigned int)((int)((unsigned int)v3166 >> 2)) >> 1)) & 1) * 2;
  int v3168 = v3167[v3278];
  int v3279 = ((((int)((unsigned int)((int)((unsigned int)v3166 >> 2)) >> 1)) & 1) * 2) + 1;
  int v3169 = v3167[v3279];
  int v3280 = 4 + ((((int)((unsigned int)((int)((unsigned int)v3166 >> 2)) >> 1)) & 3) * 2);
  int v3170 = v3167[v3280];
  int v3281 = (4 + ((((int)((unsigned int)((int)((unsigned int)v3166 >> 2)) >> 1)) & 3) * 2)) + 1;
  int v3171 = v3167[v3281];
  int * v3172 = v3160->cache_vals;
  bool v3282 = !(((~(((v3168 ^ ((int)((unsigned int)((int)((unsigned int)v3166 >> 2)) >> 1))) | (-(v3168 ^ ((int)((unsigned int)((int)((unsigned int)v3166 >> 2)) >> 1))))) >> 31)) | (~(((v3169 ^ ((int)((unsigned int)((int)((unsigned int)v3166 >> 2)) >> 1))) | (-(v3169 ^ ((int)((unsigned int)((int)((unsigned int)v3166 >> 2)) >> 1))))) >> 31))) == 0);
  int v3265;
  if (v3282) {
    int * v3173 = v3160->cache_age;
    int v3284 = ((((int)((unsigned int)((int)((unsigned int)v3166 >> 2)) >> 1)) & 1) * 2) + ((~(((v3169 ^ ((int)((unsigned int)((int)((unsigned int)v3166 >> 2)) >> 1))) | (-(v3169 ^ ((int)((unsigned int)((int)((unsigned int)v3166 >> 2)) >> 1))))) >> 31)) & 1);
    int v3174 = v3173[v3284];
    int v3175 = v3173[v3278];
    int v3285 = v3175 + ((int)((unsigned int)(v3175 - v3174) >> 31));
    v3173[v3278] = v3285;
    int * v3177 = v3160->cache_age;
    int v3178 = v3177[v3279];
    int v3287 = v3178 + ((int)((unsigned int)(v3178 - v3174) >> 31));
    v3177[v3279] = v3287;
    int * v3180 = v3160->cache_age;
    v3180[v3284] = 0;
    v3265 = v3284;
  } else {
    int * v3183 = v3160->cache_age;
    int v3291 = (((int)((unsigned int)((int)((unsigned int)v3166 >> 2)) >> 1)) & 1) * 2;
    int v3184 = v3183[v3291];
    int * v3185 = v3160->cache_tags;
    int v3186 = v3185[v3291];
    int v3187 = v3183[v3279];
    int v3188 = v3185[v3279];
    bool v3293 = !(((~(((v3170 ^ ((int)((unsigned int)((int)((unsigned int)v3166 >> 2)) >> 1))) | (-(v3170 ^ ((int)((unsigned int)((int)((unsigned int)v3166 >> 2)) >> 1))))) >> 31)) | (~(((v3171 ^ ((int)((unsigned int)((int)((unsigned int)v3166 >> 2)) >> 1))) | (-(v3171 ^ ((int)((unsigned int)((int)((unsigned int)v3166 >> 2)) >> 1))))) >> 31))) == 0);
    int v3242;
    if (v3293) {
      int * v3189 = v3160->cache_age;
      int v3295 = (4 + ((((int)((unsigned int)((int)((unsigned int)v3166 >> 2)) >> 1)) & 3) * 2)) + ((~(((v3171 ^ ((int)((unsigned int)((int)((unsigned int)v3166 >> 2)) >> 1))) | (-(v3171 ^ ((int)((unsigned int)((int)((unsigned int)v3166 >> 2)) >> 1))))) >> 31)) & 1);
      int v3190 = v3189[v3295];
      int v3191 = v3189[v3280];
      int v3296 = v3191 + ((int)((unsigned int)(v3191 - v3190) >> 31));
      v3189[v3280] = v3296;
      int * v3193 = v3160->cache_age;
      int v3194 = v3193[v3281];
      int v3298 = v3194 + ((int)((unsigned int)(v3194 - v3190) >> 31));
      v3193[v3281] = v3298;
      int * v3196 = v3160->cache_age;
      v3196[v3295] = 0;
      v3242 = v3295;
    } else {
      int * v3199 = v3160->cache_age;
      int v3302 = 4 + ((((int)((unsigned int)((int)((unsigned int)v3166 >> 2)) >> 1)) & 3) * 2);
      int v3200 = v3199[v3302];
      int * v3201 = v3160->cache_tags;
      int v3202 = v3201[v3302];
      int v3203 = v3199[v3281];
      int v3204 = v3201[v3281];
      int * v3205 = v3160->cache_dirty;
      int v3305 = (4 + ((((int)((unsigned int)((int)((unsigned int)v3166 >> 2)) >> 1)) & 3) * 2)) + ((((v3200 + ((~(((v3202 ^ -1) | (-(v3202 ^ -1))) >> 31)) & 2)) - (v3203 + ((~(((v3204 ^ -1) | (-(v3204 ^ -1))) >> 31)) & 2))) >> 31) & 1);
      int v3206 = v3205[v3305];
      bool v3306 = !(v3206 == 0);
      if (v3306) {
        int * v3207 = v3160->cache_tags;
        int v3208 = v3207[v3305];
        int * v3209 = v3160->cache_vals;
        int v3309 = ((4 + ((((int)((unsigned int)((int)((unsigned int)v3166 >> 2)) >> 1)) & 3) * 2)) + ((((v3200 + ((~(((v3202 ^ -1) | (-(v3202 ^ -1))) >> 31)) & 2)) - (v3203 + ((~(((v3204 ^ -1) | (-(v3204 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
        int v3210 = v3209[v3309];
        int v3310 = (((4 + ((((int)((unsigned int)((int)((unsigned int)v3166 >> 2)) >> 1)) & 3) * 2)) + ((((v3200 + ((~(((v3202 ^ -1) | (-(v3202 ^ -1))) >> 31)) & 2)) - (v3203 + ((~(((v3204 ^ -1) | (-(v3204 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
        int v3211 = v3209[v3310];
        int * v3212 = v3160->mem;
        int v3312 = v3208 * 2;
        v3212[v3312] = v3210;
        int * v3214 = v3160->mem;
        int v3315 = (v3208 * 2) + 1;
        v3214[v3315] = v3211;
        ;
      } else {
        ;
      }
      int * v3219 = v3160->mem;
      int v3320 = ((int)((unsigned int)((int)((unsigned int)v3166 >> 2)) >> 1)) * 2;
      int v3220 = v3219[v3320];
      int v3321 = (((int)((unsigned int)((int)((unsigned int)v3166 >> 2)) >> 1)) * 2) + 1;
      int v3221 = v3219[v3321];
      int * v3222 = v3160->cache_vals;
      int v3323 = ((4 + ((((int)((unsigned int)((int)((unsigned int)v3166 >> 2)) >> 1)) & 3) * 2)) + ((((v3200 + ((~(((v3202 ^ -1) | (-(v3202 ^ -1))) >> 31)) & 2)) - (v3203 + ((~(((v3204 ^ -1) | (-(v3204 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
      v3222[v3323] = v3220;
      int * v3224 = v3160->cache_vals;
      int v3326 = (((4 + ((((int)((unsigned int)((int)((unsigned int)v3166 >> 2)) >> 1)) & 3) * 2)) + ((((v3200 + ((~(((v3202 ^ -1) | (-(v3202 ^ -1))) >> 31)) & 2)) - (v3203 + ((~(((v3204 ^ -1) | (-(v3204 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
      v3224[v3326] = v3221;
      int * v3226 = v3160->cache_tags;
      int v3329 = (int)((unsigned int)((int)((unsigned int)v3166 >> 2)) >> 1);
      v3226[v3305] = v3329;
      int * v3228 = v3160->cache_dirty;
      v3228[v3305] = 0;
      int * v3230 = v3160->cache_age;
      v3230[v3305] = 1;
      int * v3232 = v3160->cache_age;
      int v3233 = v3232[v3305];
      int v3234 = v3232[v3280];
      int v3335 = v3234 + ((int)((unsigned int)(v3234 - v3233) >> 31));
      v3232[v3280] = v3335;
      int * v3236 = v3160->cache_age;
      int v3237 = v3236[v3281];
      int v3337 = v3237 + ((int)((unsigned int)(v3237 - v3233) >> 31));
      v3236[v3281] = v3337;
      int * v3239 = v3160->cache_age;
      v3239[v3305] = 0;
      v3242 = v3305;
    }
    int * v3243 = v3160->cache_vals;
    int v3340 = v3242 * 2;
    int v3244 = v3243[v3340];
    int v3341 = (v3242 * 2) + 1;
    int v3245 = v3243[v3341];
    int v3342 = (((((int)((unsigned int)((int)((unsigned int)v3166 >> 2)) >> 1)) & 1) * 2) + ((((v3184 + ((~(((v3186 ^ -1) | (-(v3186 ^ -1))) >> 31)) & 2)) - (v3187 + ((~(((v3188 ^ -1) | (-(v3188 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
    v3243[v3342] = v3244;
    int * v3247 = v3160->cache_vals;
    int v3345 = ((((((int)((unsigned int)((int)((unsigned int)v3166 >> 2)) >> 1)) & 1) * 2) + ((((v3184 + ((~(((v3186 ^ -1) | (-(v3186 ^ -1))) >> 31)) & 2)) - (v3187 + ((~(((v3188 ^ -1) | (-(v3188 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
    v3247[v3345] = v3245;
    int * v3249 = v3160->cache_tags;
    int v3348 = ((((int)((unsigned int)((int)((unsigned int)v3166 >> 2)) >> 1)) & 1) * 2) + ((((v3184 + ((~(((v3186 ^ -1) | (-(v3186 ^ -1))) >> 31)) & 2)) - (v3187 + ((~(((v3188 ^ -1) | (-(v3188 ^ -1))) >> 31)) & 2))) >> 31) & 1);
    int v3349 = (int)((unsigned int)((int)((unsigned int)v3166 >> 2)) >> 1);
    v3249[v3348] = v3349;
    int * v3251 = v3160->cache_dirty;
    v3251[v3348] = 0;
    int * v3253 = v3160->cache_age;
    v3253[v3348] = 1;
    int * v3255 = v3160->cache_age;
    int v3256 = v3255[v3348];
    int v3257 = v3255[v3278];
    int v3355 = v3257 + ((int)((unsigned int)(v3257 - v3256) >> 31));
    v3255[v3278] = v3355;
    int * v3259 = v3160->cache_age;
    int v3260 = v3259[v3279];
    int v3357 = v3260 + ((int)((unsigned int)(v3260 - v3256) >> 31));
    v3259[v3279] = v3357;
    int * v3262 = v3160->cache_age;
    v3262[v3348] = 0;
    v3265 = v3348;
  }
  int v3360 = (v3265 * 2) + (((int)((unsigned int)v3166 >> 2)) & 1);
  int v3266 = v3172[v3360];
  int * v3267 = v3160->reg_ready;
  int v3362 = ((v3164 + ((v3161 - v3164) & (~((v3161 - v3164) >> 31)))) + 1) + ((100 ^ (((~(((v3170 ^ ((int)((unsigned int)((int)((unsigned int)v3166 >> 2)) >> 1))) | (-(v3170 ^ ((int)((unsigned int)((int)((unsigned int)v3166 >> 2)) >> 1))))) >> 31)) | (~(((v3171 ^ ((int)((unsigned int)((int)((unsigned int)v3166 >> 2)) >> 1))) | (-(v3171 ^ ((int)((unsigned int)((int)((unsigned int)v3166 >> 2)) >> 1))))) >> 31))) & 104)) ^ (((~(((v3168 ^ ((int)((unsigned int)((int)((unsigned int)v3166 >> 2)) >> 1))) | (-(v3168 ^ ((int)((unsigned int)((int)((unsigned int)v3166 >> 2)) >> 1))))) >> 31)) | (~(((v3169 ^ ((int)((unsigned int)((int)((unsigned int)v3166 >> 2)) >> 1))) | (-(v3169 ^ ((int)((unsigned int)((int)((unsigned int)v3166 >> 2)) >> 1))))) >> 31))) & (1 ^ (100 ^ (((~(((v3170 ^ ((int)((unsigned int)((int)((unsigned int)v3166 >> 2)) >> 1))) | (-(v3170 ^ ((int)((unsigned int)((int)((unsigned int)v3166 >> 2)) >> 1))))) >> 31)) | (~(((v3171 ^ ((int)((unsigned int)((int)((unsigned int)v3166 >> 2)) >> 1))) | (-(v3171 ^ ((int)((unsigned int)((int)((unsigned int)v3166 >> 2)) >> 1))))) >> 31))) & 104)))));
  v3267[10] = v3362;
  int * v3269 = v3160->regs;
  v3269[10] = v3266;
  struct StateT * v3271 = slot_43(v3160);
  return v3271;
}

struct StateT * slot_44(struct StateT * v3398) {
  int * v3399 = v3398->saved_regs;
  int v3400 = v3399[10];
  int * v3401 = v3398->regs;
  int v3402 = v3401[11];
  bool v3519 = (v3400 ^ -2147483648) < (v3402 ^ -2147483648);
  struct StateT * v3513;
  if (v3519) {
    struct StateT * v3403 = slot_32(v3398);
    v3513 = v3403;
  } else {
    int v3405 = v3398->timer;
    int v3522 = v3405 + 15;
    v3398->timer = v3522;
    int * v3407 = v3398->saved_regs;
    int v3408 = v3407[10];
    int * v3409 = v3398->regs;
    v3409[10] = v3408;
    int * v3411 = v3398->saved_regs;
    int v3412 = v3411[12];
    int * v3413 = v3398->regs;
    v3413[12] = v3412;
    int * v3415 = v3398->reg_ready;
    int v3416 = v3398->timer;
    v3415[0] = v3416;
    int * v3418 = v3398->reg_ready;
    int v3419 = v3398->timer;
    v3418[1] = v3419;
    int * v3421 = v3398->reg_ready;
    int v3422 = v3398->timer;
    v3421[2] = v3422;
    int * v3424 = v3398->reg_ready;
    int v3425 = v3398->timer;
    v3424[3] = v3425;
    int * v3427 = v3398->reg_ready;
    int v3428 = v3398->timer;
    v3427[4] = v3428;
    int * v3430 = v3398->reg_ready;
    int v3431 = v3398->timer;
    v3430[5] = v3431;
    int * v3433 = v3398->reg_ready;
    int v3434 = v3398->timer;
    v3433[6] = v3434;
    int * v3436 = v3398->reg_ready;
    int v3437 = v3398->timer;
    v3436[7] = v3437;
    int * v3439 = v3398->reg_ready;
    int v3440 = v3398->timer;
    v3439[8] = v3440;
    int * v3442 = v3398->reg_ready;
    int v3443 = v3398->timer;
    v3442[9] = v3443;
    int * v3445 = v3398->reg_ready;
    int v3446 = v3398->timer;
    v3445[10] = v3446;
    int * v3448 = v3398->reg_ready;
    int v3449 = v3398->timer;
    v3448[11] = v3449;
    int * v3451 = v3398->reg_ready;
    int v3452 = v3398->timer;
    v3451[12] = v3452;
    int * v3454 = v3398->reg_ready;
    int v3455 = v3398->timer;
    v3454[13] = v3455;
    int * v3457 = v3398->reg_ready;
    int v3458 = v3398->timer;
    v3457[14] = v3458;
    int * v3460 = v3398->reg_ready;
    int v3461 = v3398->timer;
    v3460[15] = v3461;
    int * v3463 = v3398->reg_ready;
    int v3464 = v3398->timer;
    v3463[16] = v3464;
    int * v3466 = v3398->reg_ready;
    int v3467 = v3398->timer;
    v3466[17] = v3467;
    int * v3469 = v3398->reg_ready;
    int v3470 = v3398->timer;
    v3469[18] = v3470;
    int * v3472 = v3398->reg_ready;
    int v3473 = v3398->timer;
    v3472[19] = v3473;
    int * v3475 = v3398->reg_ready;
    int v3476 = v3398->timer;
    v3475[20] = v3476;
    int * v3478 = v3398->reg_ready;
    int v3479 = v3398->timer;
    v3478[21] = v3479;
    int * v3481 = v3398->reg_ready;
    int v3482 = v3398->timer;
    v3481[22] = v3482;
    int * v3484 = v3398->reg_ready;
    int v3485 = v3398->timer;
    v3484[23] = v3485;
    int * v3487 = v3398->reg_ready;
    int v3488 = v3398->timer;
    v3487[24] = v3488;
    int * v3490 = v3398->reg_ready;
    int v3491 = v3398->timer;
    v3490[25] = v3491;
    int * v3493 = v3398->reg_ready;
    int v3494 = v3398->timer;
    v3493[26] = v3494;
    int * v3496 = v3398->reg_ready;
    int v3497 = v3398->timer;
    v3496[27] = v3497;
    int * v3499 = v3398->reg_ready;
    int v3500 = v3398->timer;
    v3499[28] = v3500;
    int * v3502 = v3398->reg_ready;
    int v3503 = v3398->timer;
    v3502[29] = v3503;
    int * v3505 = v3398->reg_ready;
    int v3506 = v3398->timer;
    v3505[30] = v3506;
    int * v3508 = v3398->reg_ready;
    int v3509 = v3398->timer;
    v3508[31] = v3509;
    struct StateT * v3511 = slot_45(v3398);
    v3513 = v3511;
  }
  return v3513;
}

struct StateT * slot_32(struct StateT * v2506) {
  int v2507 = v2506->timer;
  int v2511 = v2507 + 1;
  v2506->timer = v2511;
  struct StateT * v2509 = slot_33(v2506);
  return v2509;
}

struct StateT * slot_17(struct StateT * v1096) {
  int * v1097 = v1096->saved_regs;
  int v1098 = v1097[13];
  bool v1209 = !(v1098 == 0);
  struct StateT * v1205;
  if (v1209) {
    int v1099 = v1096->timer;
    int v1210 = v1099 + 15;
    v1096->timer = v1210;
    int * v1101 = v1096->saved_regs;
    int v1102 = v1101[13];
    int * v1103 = v1096->regs;
    v1103[13] = v1102;
    int * v1105 = v1096->reg_ready;
    int v1106 = v1096->timer;
    v1105[0] = v1106;
    int * v1108 = v1096->reg_ready;
    int v1109 = v1096->timer;
    v1108[1] = v1109;
    int * v1111 = v1096->reg_ready;
    int v1112 = v1096->timer;
    v1111[2] = v1112;
    int * v1114 = v1096->reg_ready;
    int v1115 = v1096->timer;
    v1114[3] = v1115;
    int * v1117 = v1096->reg_ready;
    int v1118 = v1096->timer;
    v1117[4] = v1118;
    int * v1120 = v1096->reg_ready;
    int v1121 = v1096->timer;
    v1120[5] = v1121;
    int * v1123 = v1096->reg_ready;
    int v1124 = v1096->timer;
    v1123[6] = v1124;
    int * v1126 = v1096->reg_ready;
    int v1127 = v1096->timer;
    v1126[7] = v1127;
    int * v1129 = v1096->reg_ready;
    int v1130 = v1096->timer;
    v1129[8] = v1130;
    int * v1132 = v1096->reg_ready;
    int v1133 = v1096->timer;
    v1132[9] = v1133;
    int * v1135 = v1096->reg_ready;
    int v1136 = v1096->timer;
    v1135[10] = v1136;
    int * v1138 = v1096->reg_ready;
    int v1139 = v1096->timer;
    v1138[11] = v1139;
    int * v1141 = v1096->reg_ready;
    int v1142 = v1096->timer;
    v1141[12] = v1142;
    int * v1144 = v1096->reg_ready;
    int v1145 = v1096->timer;
    v1144[13] = v1145;
    int * v1147 = v1096->reg_ready;
    int v1148 = v1096->timer;
    v1147[14] = v1148;
    int * v1150 = v1096->reg_ready;
    int v1151 = v1096->timer;
    v1150[15] = v1151;
    int * v1153 = v1096->reg_ready;
    int v1154 = v1096->timer;
    v1153[16] = v1154;
    int * v1156 = v1096->reg_ready;
    int v1157 = v1096->timer;
    v1156[17] = v1157;
    int * v1159 = v1096->reg_ready;
    int v1160 = v1096->timer;
    v1159[18] = v1160;
    int * v1162 = v1096->reg_ready;
    int v1163 = v1096->timer;
    v1162[19] = v1163;
    int * v1165 = v1096->reg_ready;
    int v1166 = v1096->timer;
    v1165[20] = v1166;
    int * v1168 = v1096->reg_ready;
    int v1169 = v1096->timer;
    v1168[21] = v1169;
    int * v1171 = v1096->reg_ready;
    int v1172 = v1096->timer;
    v1171[22] = v1172;
    int * v1174 = v1096->reg_ready;
    int v1175 = v1096->timer;
    v1174[23] = v1175;
    int * v1177 = v1096->reg_ready;
    int v1178 = v1096->timer;
    v1177[24] = v1178;
    int * v1180 = v1096->reg_ready;
    int v1181 = v1096->timer;
    v1180[25] = v1181;
    int * v1183 = v1096->reg_ready;
    int v1184 = v1096->timer;
    v1183[26] = v1184;
    int * v1186 = v1096->reg_ready;
    int v1187 = v1096->timer;
    v1186[27] = v1187;
    int * v1189 = v1096->reg_ready;
    int v1190 = v1096->timer;
    v1189[28] = v1190;
    int * v1192 = v1096->reg_ready;
    int v1193 = v1096->timer;
    v1192[29] = v1193;
    int * v1195 = v1096->reg_ready;
    int v1196 = v1096->timer;
    v1195[30] = v1196;
    int * v1198 = v1096->reg_ready;
    int v1199 = v1096->timer;
    v1198[31] = v1199;
    struct StateT * v1201 = slot_45(v1096);
    v1205 = v1201;
  } else {
    struct StateT * v1203 = slot_19(v1096);
    v1205 = v1203;
  }
  return v1205;
}

struct StateT * slot_33(struct StateT * v2514) {
  int * v2515 = v2514->saved_regs;
  int * v2516 = v2514->regs;
  int v2517 = v2516[13];
  v2515[13] = v2517;
  int v2519 = v2514->timer;
  int v2534 = v2519 + 1;
  v2514->timer = v2534;
  int * v2521 = v2514->reg_ready;
  int v2522 = v2521[13];
  int * v2523 = v2514->regs;
  int v2524 = v2523[13];
  int v2537 = (v2522 + ((v2519 - v2522) & (~((v2519 - v2522) >> 31)))) + 1;
  v2521[13] = v2537;
  int * v2526 = v2514->regs;
  int v2539 = v2524 + -1;
  v2526[13] = v2539;
  struct StateT * v2528 = slot_34(v2514);
  return v2528;
}

struct StateT * slot_36(struct StateT * v2776) {
  int v2777 = v2776->timer;
  int v2781 = v2777 + 1;
  v2776->timer = v2781;
  struct StateT * v2779 = slot_38(v2776);
  return v2779;
}

struct StateT * snippet(struct StateT * v0) {
  struct StateT * v1 = slot_0(v0);
  int v3642 = v1->timer;
  int * v3643 = v1->reg_ready;
  int v3644 = v3643[0];
  int v3775 = v3644 + ((v3642 - v3644) & (~((v3642 - v3644) >> 31)));
  v1->timer = v3775;
  int v3646 = v1->timer;
  int * v3647 = v1->reg_ready;
  int v3648 = v3647[1];
  int v3778 = v3648 + ((v3646 - v3648) & (~((v3646 - v3648) >> 31)));
  v1->timer = v3778;
  int v3650 = v1->timer;
  int * v3651 = v1->reg_ready;
  int v3652 = v3651[2];
  int v3781 = v3652 + ((v3650 - v3652) & (~((v3650 - v3652) >> 31)));
  v1->timer = v3781;
  int v3654 = v1->timer;
  int * v3655 = v1->reg_ready;
  int v3656 = v3655[3];
  int v3784 = v3656 + ((v3654 - v3656) & (~((v3654 - v3656) >> 31)));
  v1->timer = v3784;
  int v3658 = v1->timer;
  int * v3659 = v1->reg_ready;
  int v3660 = v3659[4];
  int v3787 = v3660 + ((v3658 - v3660) & (~((v3658 - v3660) >> 31)));
  v1->timer = v3787;
  int v3662 = v1->timer;
  int * v3663 = v1->reg_ready;
  int v3664 = v3663[5];
  int v3790 = v3664 + ((v3662 - v3664) & (~((v3662 - v3664) >> 31)));
  v1->timer = v3790;
  int v3666 = v1->timer;
  int * v3667 = v1->reg_ready;
  int v3668 = v3667[6];
  int v3793 = v3668 + ((v3666 - v3668) & (~((v3666 - v3668) >> 31)));
  v1->timer = v3793;
  int v3670 = v1->timer;
  int * v3671 = v1->reg_ready;
  int v3672 = v3671[7];
  int v3796 = v3672 + ((v3670 - v3672) & (~((v3670 - v3672) >> 31)));
  v1->timer = v3796;
  int v3674 = v1->timer;
  int * v3675 = v1->reg_ready;
  int v3676 = v3675[8];
  int v3799 = v3676 + ((v3674 - v3676) & (~((v3674 - v3676) >> 31)));
  v1->timer = v3799;
  int v3678 = v1->timer;
  int * v3679 = v1->reg_ready;
  int v3680 = v3679[9];
  int v3802 = v3680 + ((v3678 - v3680) & (~((v3678 - v3680) >> 31)));
  v1->timer = v3802;
  int v3682 = v1->timer;
  int * v3683 = v1->reg_ready;
  int v3684 = v3683[10];
  int v3805 = v3684 + ((v3682 - v3684) & (~((v3682 - v3684) >> 31)));
  v1->timer = v3805;
  int v3686 = v1->timer;
  int * v3687 = v1->reg_ready;
  int v3688 = v3687[11];
  int v3808 = v3688 + ((v3686 - v3688) & (~((v3686 - v3688) >> 31)));
  v1->timer = v3808;
  int v3690 = v1->timer;
  int * v3691 = v1->reg_ready;
  int v3692 = v3691[12];
  int v3811 = v3692 + ((v3690 - v3692) & (~((v3690 - v3692) >> 31)));
  v1->timer = v3811;
  int v3694 = v1->timer;
  int * v3695 = v1->reg_ready;
  int v3696 = v3695[13];
  int v3814 = v3696 + ((v3694 - v3696) & (~((v3694 - v3696) >> 31)));
  v1->timer = v3814;
  int v3698 = v1->timer;
  int * v3699 = v1->reg_ready;
  int v3700 = v3699[14];
  int v3817 = v3700 + ((v3698 - v3700) & (~((v3698 - v3700) >> 31)));
  v1->timer = v3817;
  int v3702 = v1->timer;
  int * v3703 = v1->reg_ready;
  int v3704 = v3703[15];
  int v3820 = v3704 + ((v3702 - v3704) & (~((v3702 - v3704) >> 31)));
  v1->timer = v3820;
  int v3706 = v1->timer;
  int * v3707 = v1->reg_ready;
  int v3708 = v3707[16];
  int v3823 = v3708 + ((v3706 - v3708) & (~((v3706 - v3708) >> 31)));
  v1->timer = v3823;
  int v3710 = v1->timer;
  int * v3711 = v1->reg_ready;
  int v3712 = v3711[17];
  int v3826 = v3712 + ((v3710 - v3712) & (~((v3710 - v3712) >> 31)));
  v1->timer = v3826;
  int v3714 = v1->timer;
  int * v3715 = v1->reg_ready;
  int v3716 = v3715[18];
  int v3829 = v3716 + ((v3714 - v3716) & (~((v3714 - v3716) >> 31)));
  v1->timer = v3829;
  int v3718 = v1->timer;
  int * v3719 = v1->reg_ready;
  int v3720 = v3719[19];
  int v3832 = v3720 + ((v3718 - v3720) & (~((v3718 - v3720) >> 31)));
  v1->timer = v3832;
  int v3722 = v1->timer;
  int * v3723 = v1->reg_ready;
  int v3724 = v3723[20];
  int v3835 = v3724 + ((v3722 - v3724) & (~((v3722 - v3724) >> 31)));
  v1->timer = v3835;
  int v3726 = v1->timer;
  int * v3727 = v1->reg_ready;
  int v3728 = v3727[21];
  int v3838 = v3728 + ((v3726 - v3728) & (~((v3726 - v3728) >> 31)));
  v1->timer = v3838;
  int v3730 = v1->timer;
  int * v3731 = v1->reg_ready;
  int v3732 = v3731[22];
  int v3841 = v3732 + ((v3730 - v3732) & (~((v3730 - v3732) >> 31)));
  v1->timer = v3841;
  int v3734 = v1->timer;
  int * v3735 = v1->reg_ready;
  int v3736 = v3735[23];
  int v3844 = v3736 + ((v3734 - v3736) & (~((v3734 - v3736) >> 31)));
  v1->timer = v3844;
  int v3738 = v1->timer;
  int * v3739 = v1->reg_ready;
  int v3740 = v3739[24];
  int v3847 = v3740 + ((v3738 - v3740) & (~((v3738 - v3740) >> 31)));
  v1->timer = v3847;
  int v3742 = v1->timer;
  int * v3743 = v1->reg_ready;
  int v3744 = v3743[25];
  int v3850 = v3744 + ((v3742 - v3744) & (~((v3742 - v3744) >> 31)));
  v1->timer = v3850;
  int v3746 = v1->timer;
  int * v3747 = v1->reg_ready;
  int v3748 = v3747[26];
  int v3853 = v3748 + ((v3746 - v3748) & (~((v3746 - v3748) >> 31)));
  v1->timer = v3853;
  int v3750 = v1->timer;
  int * v3751 = v1->reg_ready;
  int v3752 = v3751[27];
  int v3856 = v3752 + ((v3750 - v3752) & (~((v3750 - v3752) >> 31)));
  v1->timer = v3856;
  int v3754 = v1->timer;
  int * v3755 = v1->reg_ready;
  int v3756 = v3755[28];
  int v3859 = v3756 + ((v3754 - v3756) & (~((v3754 - v3756) >> 31)));
  v1->timer = v3859;
  int v3758 = v1->timer;
  int * v3759 = v1->reg_ready;
  int v3760 = v3759[29];
  int v3862 = v3760 + ((v3758 - v3760) & (~((v3758 - v3760) >> 31)));
  v1->timer = v3862;
  int v3762 = v1->timer;
  int * v3763 = v1->reg_ready;
  int v3764 = v3763[30];
  int v3865 = v3764 + ((v3762 - v3764) & (~((v3762 - v3764) >> 31)));
  v1->timer = v3865;
  int v3766 = v1->timer;
  int * v3767 = v1->reg_ready;
  int v3768 = v3767[31];
  int v3868 = v3768 + ((v3766 - v3768) & (~((v3766 - v3768) >> 31)));
  v1->timer = v3868;
  return v1;
}

struct StateT * slot_40(struct StateT * v3136) {
  int v3137 = v3136->timer;
  int v3150 = v3137 + 1;
  v3136->timer = v3150;
  int * v3139 = v3136->reg_ready;
  int v3140 = v3139[14];
  int * v3141 = v3136->regs;
  int v3142 = v3141[14];
  int v3143 = v3139[10];
  int v3144 = v3141[10];
  int v3155 = (v3143 + (((v3140 + ((v3137 - v3140) & (~((v3137 - v3140) >> 31)))) - v3143) & (~(((v3140 + ((v3137 - v3140) & (~((v3137 - v3140) >> 31)))) - v3143) >> 31)))) + 1;
  v3139[10] = v3155;
  int * v3146 = v3136->regs;
  int v3157 = v3142 + v3144;
  v3146[10] = v3157;
  struct StateT * v3148 = slot_42(v3136);
  return v3148;
}

struct StateT * slot_8(struct StateT * v530) {
  int * v531 = v530->saved_regs;
  int * v532 = v530->regs;
  int v533 = v532[10];
  v531[10] = v533;
  int v535 = v530->timer;
  int v550 = v535 + 1;
  v530->timer = v550;
  int * v537 = v530->reg_ready;
  int v538 = v537[10];
  int * v539 = v530->regs;
  int v540 = v539[10];
  int v553 = (v538 + ((v535 - v538) & (~((v535 - v538) >> 31)))) + 1;
  v537[10] = v553;
  int * v542 = v530->regs;
  int v555 = v540 << 2;
  v542[10] = v555;
  struct StateT * v544 = slot_9(v530);
  return v544;
}

struct StateT * slot_27(struct StateT * v2246) {
  int v2247 = v2246->timer;
  int v2260 = v2247 + 1;
  v2246->timer = v2260;
  int * v2249 = v2246->reg_ready;
  int v2250 = v2249[14];
  int * v2251 = v2246->regs;
  int v2252 = v2251[14];
  int v2253 = v2249[10];
  int v2254 = v2251[10];
  int v2265 = (v2253 + (((v2250 + ((v2247 - v2250) & (~((v2247 - v2250) >> 31)))) - v2253) & (~(((v2250 + ((v2247 - v2250) & (~((v2247 - v2250) >> 31)))) - v2253) >> 31)))) + 1;
  v2249[10] = v2265;
  int * v2256 = v2246->regs;
  int v2267 = v2252 + v2254;
  v2256[10] = v2267;
  struct StateT * v2258 = slot_29(v2246);
  return v2258;
}

struct StateT * slot_4(struct StateT * v256) {
  int * v257 = v256->saved_regs;
  int * v258 = v256->regs;
  int v259 = v258[12];
  v257[12] = v259;
  int v261 = v256->timer;
  int v273 = v261 + 1;
  v256->timer = v273;
  int * v263 = v256->reg_ready;
  v263[12] = v273;
  int * v265 = v256->regs;
  v265[12] = 0;
  struct StateT * v267 = slot_5(v256);
  return v267;
}

struct StateT * slot_9(struct StateT * v558) {
  int v559 = v558->timer;
  int v572 = v559 + 1;
  v558->timer = v572;
  int * v561 = v558->reg_ready;
  int v562 = v561[14];
  int * v563 = v558->regs;
  int v564 = v563[14];
  int v565 = v561[10];
  int v566 = v563[10];
  int v577 = (v565 + (((v562 + ((v559 - v562) & (~((v559 - v562) >> 31)))) - v565) & (~(((v562 + ((v559 - v562) & (~((v559 - v562) >> 31)))) - v565) >> 31)))) + 1;
  v561[10] = v577;
  int * v568 = v558->regs;
  int v579 = v564 + v566;
  v568[10] = v579;
  struct StateT * v570 = slot_10(v558);
  return v570;
}

struct StateT * slot_11(struct StateT * v789) {
  int v790 = v789->timer;
  int v803 = v790 + 1;
  v789->timer = v803;
  int * v792 = v789->reg_ready;
  int v793 = v792[12];
  int * v794 = v789->regs;
  int v795 = v794[12];
  int v796 = v792[10];
  int v797 = v794[10];
  int v808 = (v796 + (((v793 + ((v790 - v793) & (~((v790 - v793) >> 31)))) - v796) & (~(((v793 + ((v790 - v793) & (~((v790 - v793) >> 31)))) - v796) >> 31)))) + 1;
  v792[12] = v808;
  int * v799 = v789->regs;
  int v810 = v795 & v797;
  v799[12] = v810;
  struct StateT * v801 = slot_12(v789);
  return v801;
}



/*****************************************
End of C Generated Code
*******************************************/

void init(struct StateT *s) {
  for (int i=0; i<NUM_REGS; i++) {
    s->regs[i] = 0;
    s->saved_regs[i] = 0;
    s->reg_ready[i] = 0;
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

int main(int argc, char* argv[]) {
  struct StateT s1, s2;
  init(&s1);
  init(&s2);
  
  // public data, where the section headers put it
  s1.mem[0] = 8;
  s2.mem[0] = 8;
  int x = bounded(0, 15);
  s1.regs[10] = x;
  s2.regs[10] = x;
  // probe, the attacker's: the same draw in both states
  for (int i=0; i<16; i++) {
    int v = bounded(0, 20);
    s1.mem[1 + i] = v;
    s2.mem[1 + i] = v;
  }
  // temp, the attacker's: the same draw in both states
  for (int i=0; i<1; i++) {
    int v = bounded(0, 20);
    s1.mem[17 + i] = v;
    s2.mem[17 + i] = v;
  }
  // publicarray, the attacker's: the same draw in both states
  for (int i=0; i<8; i++) {
    int v = bounded(0, 20);
    s1.mem[18 + i] = v;
    s2.mem[18 + i] = v;
  }
  
  // secretarray, secret: a different draw in each state
  for (int i=0; i<8; i++) {
    s1.mem[26 + i] = secret(0, 20);
    s2.mem[26 + i] = secret(0, 20);
  }
  struct StateT *s1_ = snippet(&s1);
  struct StateT *s2_ = snippet(&s2);
  //@ assert untainted_timer: !\tainted(s1_->timer==s2_->timer);
  koika_assert(s1_->timer==s2_->timer, "timing leak");
  return 0;
}