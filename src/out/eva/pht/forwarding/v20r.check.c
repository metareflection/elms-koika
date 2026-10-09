// verify: leak (Eva should report untainted_timer: unknown) [unroll 65]
#define NUM_REGS 32
#define MEM_SIZE 64
#define SECRET_SIZE 10
#define SECRET_OFFSET 20
#define CACHE_ENTRIES 12
#define CACHE_WORDS 24

#ifdef EVA
#include "__fc_builtin.h"
/*@ assigns *p \from \nothing;
    taints *p; */
void koika_mark(int *p);
#define koika_assert(b, s) ((void)0)
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

struct StateT * slot_12(struct StateT * v561);
struct StateT * slot_6(struct StateT * v281);
struct StateT * slot_29(struct StateT * v2825);
struct StateT * slot_25(struct StateT * v1871);
struct StateT * slot_16(struct StateT * v998);
struct StateT * slot_23(struct StateT * v2622);
struct StateT * slot_5(struct StateT * v267);
struct StateT * slot_2(struct StateT * v218);
struct StateT * slot_7(struct StateT * v297);
struct StateT * slot_21(struct StateT * v1858);
struct StateT * slot_3(struct StateT * v226);
struct StateT * slot_10(struct StateT * v527);
struct StateT * slot_1(struct StateT * v15);
struct StateT * slot_19(struct StateT * v1071);
struct StateT * slot_13(struct StateT * v575);
struct StateT * slot_24(struct StateT * v2846);
struct StateT * slot_0(struct StateT * v2);
struct StateT * slot_14(struct StateT * v591);
struct StateT * slot_32(struct StateT * v3050);
struct StateT * slot_17(struct StateT * v1014);
struct StateT * slot_20(struct StateT * v1845);
struct StateT * snippet(struct StateT * v0);
struct StateT * slot_8(struct StateT * v500);
struct StateT * slot_4(struct StateT * v247);
struct StateT * slot_15(struct StateT * v794);
struct StateT * slot_9(struct StateT * v513);
struct StateT * slot_11(struct StateT * v547);
struct StateT * slot_12(struct StateT * v561) {
  int v562 = v561->timer;
  int v569 = v562 + 1;
  v561->timer = v569;
  int * v564 = v561->regs;
  int v565 = v564[10];
  int v572 = (int)((unsigned int)v565 >> 26);
  v564[10] = v572;
  struct StateT * v567 = slot_13(v561);
  return v567;
}

struct StateT * slot_6(struct StateT * v281) {
  int v282 = v281->timer;
  int v290 = v282 + 1;
  v281->timer = v290;
  int * v284 = v281->regs;
  int v285 = v284[11];
  int v286 = v284[10];
  int v294 = v285 + v286;
  v284[10] = v294;
  struct StateT * v288 = slot_7(v281);
  return v288;
}

struct StateT * slot_29(struct StateT * v2825) {
  int v2826 = v2825->timer;
  int v2829 = v2826 + 1;
  v2825->timer = v2829;
  return v2825;
}

struct StateT * slot_25(struct StateT * v1871) {
  int v1872 = v1871->timer;
  int v1880 = v1872 + 1;
  v1871->timer = v1880;
  int * v1874 = v1871->regs;
  int v1875 = v1874[12];
  int v1876 = v1874[10];
  int v1884 = v1875 & v1876;
  v1874[10] = v1884;
  struct StateT * v1878 = slot_32(v1871);
  return v1878;
}

struct StateT * slot_16(struct StateT * v998) {
  int v999 = v998->timer;
  int v1007 = v999 + 1;
  v998->timer = v1007;
  int * v1001 = v998->regs;
  int v1002 = v1001[11];
  int v1003 = v1001[10];
  int v1011 = v1002 & v1003;
  v1001[10] = v1011;
  struct StateT * v1005 = slot_17(v998);
  return v1005;
}

struct StateT * slot_23(struct StateT * v2622) {
  int v2623 = v2622->timer;
  int v2733 = v2623 + 1;
  v2622->timer = v2733;
  int * v2625 = v2622->regs;
  int v2626 = v2625[10];
  int * v2627 = v2622->cache_tags;
  int v2737 = (((int)((unsigned int)((int)((unsigned int)(v2626 + 4) >> 2)) >> 1)) & 1) * 2;
  int v2628 = v2627[v2737];
  int v2738 = ((((int)((unsigned int)((int)((unsigned int)(v2626 + 4) >> 2)) >> 1)) & 1) * 2) + 1;
  int v2629 = v2627[v2738];
  int v2739 = 4 + ((((int)((unsigned int)((int)((unsigned int)(v2626 + 4) >> 2)) >> 1)) & 3) * 2);
  int v2630 = v2627[v2739];
  int v2740 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v2626 + 4) >> 2)) >> 1)) & 3) * 2)) + 1;
  int v2631 = v2627[v2740];
  int v2632 = v2622->timer;
  int v2741 = v2632 + ((100 ^ (((~(((v2630 ^ ((int)((unsigned int)((int)((unsigned int)(v2626 + 4) >> 2)) >> 1))) | (-(v2630 ^ ((int)((unsigned int)((int)((unsigned int)(v2626 + 4) >> 2)) >> 1))))) >> 31)) | (~(((v2631 ^ ((int)((unsigned int)((int)((unsigned int)(v2626 + 4) >> 2)) >> 1))) | (-(v2631 ^ ((int)((unsigned int)((int)((unsigned int)(v2626 + 4) >> 2)) >> 1))))) >> 31))) & 104)) ^ (((~(((v2628 ^ ((int)((unsigned int)((int)((unsigned int)(v2626 + 4) >> 2)) >> 1))) | (-(v2628 ^ ((int)((unsigned int)((int)((unsigned int)(v2626 + 4) >> 2)) >> 1))))) >> 31)) | (~(((v2629 ^ ((int)((unsigned int)((int)((unsigned int)(v2626 + 4) >> 2)) >> 1))) | (-(v2629 ^ ((int)((unsigned int)((int)((unsigned int)(v2626 + 4) >> 2)) >> 1))))) >> 31))) & (1 ^ (100 ^ (((~(((v2630 ^ ((int)((unsigned int)((int)((unsigned int)(v2626 + 4) >> 2)) >> 1))) | (-(v2630 ^ ((int)((unsigned int)((int)((unsigned int)(v2626 + 4) >> 2)) >> 1))))) >> 31)) | (~(((v2631 ^ ((int)((unsigned int)((int)((unsigned int)(v2626 + 4) >> 2)) >> 1))) | (-(v2631 ^ ((int)((unsigned int)((int)((unsigned int)(v2626 + 4) >> 2)) >> 1))))) >> 31))) & 104)))));
  v2622->timer = v2741;
  int * v2634 = v2622->cache_vals;
  bool v2742 = !(((~(((v2628 ^ ((int)((unsigned int)((int)((unsigned int)(v2626 + 4) >> 2)) >> 1))) | (-(v2628 ^ ((int)((unsigned int)((int)((unsigned int)(v2626 + 4) >> 2)) >> 1))))) >> 31)) | (~(((v2629 ^ ((int)((unsigned int)((int)((unsigned int)(v2626 + 4) >> 2)) >> 1))) | (-(v2629 ^ ((int)((unsigned int)((int)((unsigned int)(v2626 + 4) >> 2)) >> 1))))) >> 31))) == 0);
  int v2727;
  if (v2742) {
    int * v2635 = v2622->cache_age;
    int v2744 = ((((int)((unsigned int)((int)((unsigned int)(v2626 + 4) >> 2)) >> 1)) & 1) * 2) + ((~(((v2629 ^ ((int)((unsigned int)((int)((unsigned int)(v2626 + 4) >> 2)) >> 1))) | (-(v2629 ^ ((int)((unsigned int)((int)((unsigned int)(v2626 + 4) >> 2)) >> 1))))) >> 31)) & 1);
    int v2636 = v2635[v2744];
    int v2637 = v2635[v2737];
    int v2745 = v2637 + ((int)((unsigned int)(v2637 - v2636) >> 31));
    v2635[v2737] = v2745;
    int * v2639 = v2622->cache_age;
    int v2640 = v2639[v2738];
    int v2747 = v2640 + ((int)((unsigned int)(v2640 - v2636) >> 31));
    v2639[v2738] = v2747;
    int * v2642 = v2622->cache_age;
    v2642[v2744] = 0;
    v2727 = v2744;
  } else {
    int * v2645 = v2622->cache_age;
    int v2751 = (((int)((unsigned int)((int)((unsigned int)(v2626 + 4) >> 2)) >> 1)) & 1) * 2;
    int v2646 = v2645[v2751];
    int * v2647 = v2622->cache_tags;
    int v2648 = v2647[v2751];
    int v2649 = v2645[v2738];
    int v2650 = v2647[v2738];
    bool v2753 = !(((~(((v2630 ^ ((int)((unsigned int)((int)((unsigned int)(v2626 + 4) >> 2)) >> 1))) | (-(v2630 ^ ((int)((unsigned int)((int)((unsigned int)(v2626 + 4) >> 2)) >> 1))))) >> 31)) | (~(((v2631 ^ ((int)((unsigned int)((int)((unsigned int)(v2626 + 4) >> 2)) >> 1))) | (-(v2631 ^ ((int)((unsigned int)((int)((unsigned int)(v2626 + 4) >> 2)) >> 1))))) >> 31))) == 0);
    int v2704;
    if (v2753) {
      int * v2651 = v2622->cache_age;
      int v2755 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v2626 + 4) >> 2)) >> 1)) & 3) * 2)) + ((~(((v2631 ^ ((int)((unsigned int)((int)((unsigned int)(v2626 + 4) >> 2)) >> 1))) | (-(v2631 ^ ((int)((unsigned int)((int)((unsigned int)(v2626 + 4) >> 2)) >> 1))))) >> 31)) & 1);
      int v2652 = v2651[v2755];
      int v2653 = v2651[v2739];
      int v2756 = v2653 + ((int)((unsigned int)(v2653 - v2652) >> 31));
      v2651[v2739] = v2756;
      int * v2655 = v2622->cache_age;
      int v2656 = v2655[v2740];
      int v2758 = v2656 + ((int)((unsigned int)(v2656 - v2652) >> 31));
      v2655[v2740] = v2758;
      int * v2658 = v2622->cache_age;
      v2658[v2755] = 0;
      v2704 = v2755;
    } else {
      int * v2661 = v2622->cache_age;
      int v2762 = 4 + ((((int)((unsigned int)((int)((unsigned int)(v2626 + 4) >> 2)) >> 1)) & 3) * 2);
      int v2662 = v2661[v2762];
      int * v2663 = v2622->cache_tags;
      int v2664 = v2663[v2762];
      int v2665 = v2661[v2740];
      int v2666 = v2663[v2740];
      int * v2667 = v2622->cache_dirty;
      int v2765 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v2626 + 4) >> 2)) >> 1)) & 3) * 2)) + ((((v2662 + ((~(((v2664 ^ -1) | (-(v2664 ^ -1))) >> 31)) & 2)) - (v2665 + ((~(((v2666 ^ -1) | (-(v2666 ^ -1))) >> 31)) & 2))) >> 31) & 1);
      int v2668 = v2667[v2765];
      bool v2766 = !(v2668 == 0);
      if (v2766) {
        int * v2669 = v2622->cache_tags;
        int v2670 = v2669[v2765];
        int * v2671 = v2622->cache_vals;
        int v2769 = ((4 + ((((int)((unsigned int)((int)((unsigned int)(v2626 + 4) >> 2)) >> 1)) & 3) * 2)) + ((((v2662 + ((~(((v2664 ^ -1) | (-(v2664 ^ -1))) >> 31)) & 2)) - (v2665 + ((~(((v2666 ^ -1) | (-(v2666 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
        int v2672 = v2671[v2769];
        int v2770 = (((4 + ((((int)((unsigned int)((int)((unsigned int)(v2626 + 4) >> 2)) >> 1)) & 3) * 2)) + ((((v2662 + ((~(((v2664 ^ -1) | (-(v2664 ^ -1))) >> 31)) & 2)) - (v2665 + ((~(((v2666 ^ -1) | (-(v2666 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
        int v2673 = v2671[v2770];
        int * v2674 = v2622->mem;
        int v2772 = v2670 * 2;
        v2674[v2772] = v2672;
        int * v2676 = v2622->mem;
        int v2775 = (v2670 * 2) + 1;
        v2676[v2775] = v2673;
        ;
      } else {
        ;
      }
      int * v2681 = v2622->mem;
      int v2780 = ((int)((unsigned int)((int)((unsigned int)(v2626 + 4) >> 2)) >> 1)) * 2;
      int v2682 = v2681[v2780];
      int v2781 = (((int)((unsigned int)((int)((unsigned int)(v2626 + 4) >> 2)) >> 1)) * 2) + 1;
      int v2683 = v2681[v2781];
      int * v2684 = v2622->cache_vals;
      int v2783 = ((4 + ((((int)((unsigned int)((int)((unsigned int)(v2626 + 4) >> 2)) >> 1)) & 3) * 2)) + ((((v2662 + ((~(((v2664 ^ -1) | (-(v2664 ^ -1))) >> 31)) & 2)) - (v2665 + ((~(((v2666 ^ -1) | (-(v2666 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
      v2684[v2783] = v2682;
      int * v2686 = v2622->cache_vals;
      int v2786 = (((4 + ((((int)((unsigned int)((int)((unsigned int)(v2626 + 4) >> 2)) >> 1)) & 3) * 2)) + ((((v2662 + ((~(((v2664 ^ -1) | (-(v2664 ^ -1))) >> 31)) & 2)) - (v2665 + ((~(((v2666 ^ -1) | (-(v2666 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
      v2686[v2786] = v2683;
      int * v2688 = v2622->cache_tags;
      int v2789 = (int)((unsigned int)((int)((unsigned int)(v2626 + 4) >> 2)) >> 1);
      v2688[v2765] = v2789;
      int * v2690 = v2622->cache_dirty;
      v2690[v2765] = 0;
      int * v2692 = v2622->cache_age;
      v2692[v2765] = 1;
      int * v2694 = v2622->cache_age;
      int v2695 = v2694[v2765];
      int v2696 = v2694[v2739];
      int v2795 = v2696 + ((int)((unsigned int)(v2696 - v2695) >> 31));
      v2694[v2739] = v2795;
      int * v2698 = v2622->cache_age;
      int v2699 = v2698[v2740];
      int v2797 = v2699 + ((int)((unsigned int)(v2699 - v2695) >> 31));
      v2698[v2740] = v2797;
      int * v2701 = v2622->cache_age;
      v2701[v2765] = 0;
      v2704 = v2765;
    }
    int * v2705 = v2622->cache_vals;
    int v2800 = v2704 * 2;
    int v2706 = v2705[v2800];
    int v2801 = (v2704 * 2) + 1;
    int v2707 = v2705[v2801];
    int v2802 = (((((int)((unsigned int)((int)((unsigned int)(v2626 + 4) >> 2)) >> 1)) & 1) * 2) + ((((v2646 + ((~(((v2648 ^ -1) | (-(v2648 ^ -1))) >> 31)) & 2)) - (v2649 + ((~(((v2650 ^ -1) | (-(v2650 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
    v2705[v2802] = v2706;
    int * v2709 = v2622->cache_vals;
    int v2805 = ((((((int)((unsigned int)((int)((unsigned int)(v2626 + 4) >> 2)) >> 1)) & 1) * 2) + ((((v2646 + ((~(((v2648 ^ -1) | (-(v2648 ^ -1))) >> 31)) & 2)) - (v2649 + ((~(((v2650 ^ -1) | (-(v2650 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
    v2709[v2805] = v2707;
    int * v2711 = v2622->cache_tags;
    int v2808 = ((((int)((unsigned int)((int)((unsigned int)(v2626 + 4) >> 2)) >> 1)) & 1) * 2) + ((((v2646 + ((~(((v2648 ^ -1) | (-(v2648 ^ -1))) >> 31)) & 2)) - (v2649 + ((~(((v2650 ^ -1) | (-(v2650 ^ -1))) >> 31)) & 2))) >> 31) & 1);
    int v2809 = (int)((unsigned int)((int)((unsigned int)(v2626 + 4) >> 2)) >> 1);
    v2711[v2808] = v2809;
    int * v2713 = v2622->cache_dirty;
    v2713[v2808] = 0;
    int * v2715 = v2622->cache_age;
    v2715[v2808] = 1;
    int * v2717 = v2622->cache_age;
    int v2718 = v2717[v2808];
    int v2719 = v2717[v2737];
    int v2815 = v2719 + ((int)((unsigned int)(v2719 - v2718) >> 31));
    v2717[v2737] = v2815;
    int * v2721 = v2622->cache_age;
    int v2722 = v2721[v2738];
    int v2817 = v2722 + ((int)((unsigned int)(v2722 - v2718) >> 31));
    v2721[v2738] = v2817;
    int * v2724 = v2622->cache_age;
    v2724[v2808] = 0;
    v2727 = v2808;
  }
  int v2820 = (v2727 * 2) + (((int)((unsigned int)(v2626 + 4) >> 2)) & 1);
  int v2728 = v2634[v2820];
  int * v2729 = v2622->regs;
  v2729[10] = v2728;
  struct StateT * v2731 = slot_24(v2622);
  return v2731;
}

struct StateT * slot_5(struct StateT * v267) {
  int v268 = v267->timer;
  int v275 = v268 + 1;
  v267->timer = v275;
  int * v270 = v267->regs;
  int v271 = v270[11];
  int v278 = v271 + 72;
  v270[11] = v278;
  struct StateT * v273 = slot_6(v267);
  return v273;
}

struct StateT * slot_2(struct StateT * v218) {
  int v219 = v218->timer;
  int v223 = v219 + 1;
  v218->timer = v223;
  struct StateT * v221 = slot_3(v218);
  return v221;
}

struct StateT * slot_7(struct StateT * v297) {
  int v298 = v297->timer;
  int v408 = v298 + 1;
  v297->timer = v408;
  int * v300 = v297->regs;
  int v301 = v300[10];
  int * v302 = v297->cache_tags;
  int v412 = (((int)((unsigned int)((int)((unsigned int)v301 >> 2)) >> 1)) & 1) * 2;
  int v303 = v302[v412];
  int v413 = ((((int)((unsigned int)((int)((unsigned int)v301 >> 2)) >> 1)) & 1) * 2) + 1;
  int v304 = v302[v413];
  int v414 = 4 + ((((int)((unsigned int)((int)((unsigned int)v301 >> 2)) >> 1)) & 3) * 2);
  int v305 = v302[v414];
  int v415 = (4 + ((((int)((unsigned int)((int)((unsigned int)v301 >> 2)) >> 1)) & 3) * 2)) + 1;
  int v306 = v302[v415];
  int v307 = v297->timer;
  int v416 = v307 + ((100 ^ (((~(((v305 ^ ((int)((unsigned int)((int)((unsigned int)v301 >> 2)) >> 1))) | (-(v305 ^ ((int)((unsigned int)((int)((unsigned int)v301 >> 2)) >> 1))))) >> 31)) | (~(((v306 ^ ((int)((unsigned int)((int)((unsigned int)v301 >> 2)) >> 1))) | (-(v306 ^ ((int)((unsigned int)((int)((unsigned int)v301 >> 2)) >> 1))))) >> 31))) & 104)) ^ (((~(((v303 ^ ((int)((unsigned int)((int)((unsigned int)v301 >> 2)) >> 1))) | (-(v303 ^ ((int)((unsigned int)((int)((unsigned int)v301 >> 2)) >> 1))))) >> 31)) | (~(((v304 ^ ((int)((unsigned int)((int)((unsigned int)v301 >> 2)) >> 1))) | (-(v304 ^ ((int)((unsigned int)((int)((unsigned int)v301 >> 2)) >> 1))))) >> 31))) & (1 ^ (100 ^ (((~(((v305 ^ ((int)((unsigned int)((int)((unsigned int)v301 >> 2)) >> 1))) | (-(v305 ^ ((int)((unsigned int)((int)((unsigned int)v301 >> 2)) >> 1))))) >> 31)) | (~(((v306 ^ ((int)((unsigned int)((int)((unsigned int)v301 >> 2)) >> 1))) | (-(v306 ^ ((int)((unsigned int)((int)((unsigned int)v301 >> 2)) >> 1))))) >> 31))) & 104)))));
  v297->timer = v416;
  int * v309 = v297->cache_vals;
  bool v417 = !(((~(((v303 ^ ((int)((unsigned int)((int)((unsigned int)v301 >> 2)) >> 1))) | (-(v303 ^ ((int)((unsigned int)((int)((unsigned int)v301 >> 2)) >> 1))))) >> 31)) | (~(((v304 ^ ((int)((unsigned int)((int)((unsigned int)v301 >> 2)) >> 1))) | (-(v304 ^ ((int)((unsigned int)((int)((unsigned int)v301 >> 2)) >> 1))))) >> 31))) == 0);
  int v402;
  if (v417) {
    int * v310 = v297->cache_age;
    int v419 = ((((int)((unsigned int)((int)((unsigned int)v301 >> 2)) >> 1)) & 1) * 2) + ((~(((v304 ^ ((int)((unsigned int)((int)((unsigned int)v301 >> 2)) >> 1))) | (-(v304 ^ ((int)((unsigned int)((int)((unsigned int)v301 >> 2)) >> 1))))) >> 31)) & 1);
    int v311 = v310[v419];
    int v312 = v310[v412];
    int v420 = v312 + ((int)((unsigned int)(v312 - v311) >> 31));
    v310[v412] = v420;
    int * v314 = v297->cache_age;
    int v315 = v314[v413];
    int v422 = v315 + ((int)((unsigned int)(v315 - v311) >> 31));
    v314[v413] = v422;
    int * v317 = v297->cache_age;
    v317[v419] = 0;
    v402 = v419;
  } else {
    int * v320 = v297->cache_age;
    int v426 = (((int)((unsigned int)((int)((unsigned int)v301 >> 2)) >> 1)) & 1) * 2;
    int v321 = v320[v426];
    int * v322 = v297->cache_tags;
    int v323 = v322[v426];
    int v324 = v320[v413];
    int v325 = v322[v413];
    bool v428 = !(((~(((v305 ^ ((int)((unsigned int)((int)((unsigned int)v301 >> 2)) >> 1))) | (-(v305 ^ ((int)((unsigned int)((int)((unsigned int)v301 >> 2)) >> 1))))) >> 31)) | (~(((v306 ^ ((int)((unsigned int)((int)((unsigned int)v301 >> 2)) >> 1))) | (-(v306 ^ ((int)((unsigned int)((int)((unsigned int)v301 >> 2)) >> 1))))) >> 31))) == 0);
    int v379;
    if (v428) {
      int * v326 = v297->cache_age;
      int v430 = (4 + ((((int)((unsigned int)((int)((unsigned int)v301 >> 2)) >> 1)) & 3) * 2)) + ((~(((v306 ^ ((int)((unsigned int)((int)((unsigned int)v301 >> 2)) >> 1))) | (-(v306 ^ ((int)((unsigned int)((int)((unsigned int)v301 >> 2)) >> 1))))) >> 31)) & 1);
      int v327 = v326[v430];
      int v328 = v326[v414];
      int v431 = v328 + ((int)((unsigned int)(v328 - v327) >> 31));
      v326[v414] = v431;
      int * v330 = v297->cache_age;
      int v331 = v330[v415];
      int v433 = v331 + ((int)((unsigned int)(v331 - v327) >> 31));
      v330[v415] = v433;
      int * v333 = v297->cache_age;
      v333[v430] = 0;
      v379 = v430;
    } else {
      int * v336 = v297->cache_age;
      int v437 = 4 + ((((int)((unsigned int)((int)((unsigned int)v301 >> 2)) >> 1)) & 3) * 2);
      int v337 = v336[v437];
      int * v338 = v297->cache_tags;
      int v339 = v338[v437];
      int v340 = v336[v415];
      int v341 = v338[v415];
      int * v342 = v297->cache_dirty;
      int v440 = (4 + ((((int)((unsigned int)((int)((unsigned int)v301 >> 2)) >> 1)) & 3) * 2)) + ((((v337 + ((~(((v339 ^ -1) | (-(v339 ^ -1))) >> 31)) & 2)) - (v340 + ((~(((v341 ^ -1) | (-(v341 ^ -1))) >> 31)) & 2))) >> 31) & 1);
      int v343 = v342[v440];
      bool v441 = !(v343 == 0);
      if (v441) {
        int * v344 = v297->cache_tags;
        int v345 = v344[v440];
        int * v346 = v297->cache_vals;
        int v444 = ((4 + ((((int)((unsigned int)((int)((unsigned int)v301 >> 2)) >> 1)) & 3) * 2)) + ((((v337 + ((~(((v339 ^ -1) | (-(v339 ^ -1))) >> 31)) & 2)) - (v340 + ((~(((v341 ^ -1) | (-(v341 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
        int v347 = v346[v444];
        int v445 = (((4 + ((((int)((unsigned int)((int)((unsigned int)v301 >> 2)) >> 1)) & 3) * 2)) + ((((v337 + ((~(((v339 ^ -1) | (-(v339 ^ -1))) >> 31)) & 2)) - (v340 + ((~(((v341 ^ -1) | (-(v341 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
        int v348 = v346[v445];
        int * v349 = v297->mem;
        int v447 = v345 * 2;
        v349[v447] = v347;
        int * v351 = v297->mem;
        int v450 = (v345 * 2) + 1;
        v351[v450] = v348;
        ;
      } else {
        ;
      }
      int * v356 = v297->mem;
      int v455 = ((int)((unsigned int)((int)((unsigned int)v301 >> 2)) >> 1)) * 2;
      int v357 = v356[v455];
      int v456 = (((int)((unsigned int)((int)((unsigned int)v301 >> 2)) >> 1)) * 2) + 1;
      int v358 = v356[v456];
      int * v359 = v297->cache_vals;
      int v458 = ((4 + ((((int)((unsigned int)((int)((unsigned int)v301 >> 2)) >> 1)) & 3) * 2)) + ((((v337 + ((~(((v339 ^ -1) | (-(v339 ^ -1))) >> 31)) & 2)) - (v340 + ((~(((v341 ^ -1) | (-(v341 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
      v359[v458] = v357;
      int * v361 = v297->cache_vals;
      int v461 = (((4 + ((((int)((unsigned int)((int)((unsigned int)v301 >> 2)) >> 1)) & 3) * 2)) + ((((v337 + ((~(((v339 ^ -1) | (-(v339 ^ -1))) >> 31)) & 2)) - (v340 + ((~(((v341 ^ -1) | (-(v341 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
      v361[v461] = v358;
      int * v363 = v297->cache_tags;
      int v464 = (int)((unsigned int)((int)((unsigned int)v301 >> 2)) >> 1);
      v363[v440] = v464;
      int * v365 = v297->cache_dirty;
      v365[v440] = 0;
      int * v367 = v297->cache_age;
      v367[v440] = 1;
      int * v369 = v297->cache_age;
      int v370 = v369[v440];
      int v371 = v369[v414];
      int v470 = v371 + ((int)((unsigned int)(v371 - v370) >> 31));
      v369[v414] = v470;
      int * v373 = v297->cache_age;
      int v374 = v373[v415];
      int v472 = v374 + ((int)((unsigned int)(v374 - v370) >> 31));
      v373[v415] = v472;
      int * v376 = v297->cache_age;
      v376[v440] = 0;
      v379 = v440;
    }
    int * v380 = v297->cache_vals;
    int v475 = v379 * 2;
    int v381 = v380[v475];
    int v476 = (v379 * 2) + 1;
    int v382 = v380[v476];
    int v477 = (((((int)((unsigned int)((int)((unsigned int)v301 >> 2)) >> 1)) & 1) * 2) + ((((v321 + ((~(((v323 ^ -1) | (-(v323 ^ -1))) >> 31)) & 2)) - (v324 + ((~(((v325 ^ -1) | (-(v325 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
    v380[v477] = v381;
    int * v384 = v297->cache_vals;
    int v480 = ((((((int)((unsigned int)((int)((unsigned int)v301 >> 2)) >> 1)) & 1) * 2) + ((((v321 + ((~(((v323 ^ -1) | (-(v323 ^ -1))) >> 31)) & 2)) - (v324 + ((~(((v325 ^ -1) | (-(v325 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
    v384[v480] = v382;
    int * v386 = v297->cache_tags;
    int v483 = ((((int)((unsigned int)((int)((unsigned int)v301 >> 2)) >> 1)) & 1) * 2) + ((((v321 + ((~(((v323 ^ -1) | (-(v323 ^ -1))) >> 31)) & 2)) - (v324 + ((~(((v325 ^ -1) | (-(v325 ^ -1))) >> 31)) & 2))) >> 31) & 1);
    int v484 = (int)((unsigned int)((int)((unsigned int)v301 >> 2)) >> 1);
    v386[v483] = v484;
    int * v388 = v297->cache_dirty;
    v388[v483] = 0;
    int * v390 = v297->cache_age;
    v390[v483] = 1;
    int * v392 = v297->cache_age;
    int v393 = v392[v483];
    int v394 = v392[v412];
    int v490 = v394 + ((int)((unsigned int)(v394 - v393) >> 31));
    v392[v412] = v490;
    int * v396 = v297->cache_age;
    int v397 = v396[v413];
    int v492 = v397 + ((int)((unsigned int)(v397 - v393) >> 31));
    v396[v413] = v492;
    int * v399 = v297->cache_age;
    v399[v483] = 0;
    v402 = v483;
  }
  int v495 = (v402 * 2) + (((int)((unsigned int)v301 >> 2)) & 1);
  int v403 = v309[v495];
  int * v404 = v297->regs;
  v404[10] = v403;
  struct StateT * v406 = slot_8(v297);
  return v406;
}

struct StateT * slot_21(struct StateT * v1858) {
  int v1859 = v1858->timer;
  int v1865 = v1859 + 1;
  v1858->timer = v1865;
  int * v1861 = v1858->regs;
  v1861[10] = 0;
  struct StateT * v1863 = slot_20(v1858);
  return v1863;
}

struct StateT * slot_3(struct StateT * v226) {
  int * v227 = v226->saved_regs;
  int * v228 = v226->regs;
  int v229 = v228[10];
  v227[10] = v229;
  int v231 = v226->timer;
  int v242 = v231 + 1;
  v226->timer = v242;
  int * v233 = v226->regs;
  int v234 = v233[10];
  int v244 = v234 << 2;
  v233[10] = v244;
  struct StateT * v236 = slot_4(v226);
  return v236;
}

struct StateT * slot_10(struct StateT * v527) {
  int * v528 = v527->saved_regs;
  int * v529 = v527->regs;
  int v530 = v529[12];
  v528[12] = v530;
  int v532 = v527->timer;
  int v542 = v532 + 1;
  v527->timer = v542;
  int * v534 = v527->regs;
  v534[12] = 0;
  struct StateT * v536 = slot_11(v527);
  return v536;
}

struct StateT * slot_1(struct StateT * v15) {
  int v16 = v15->timer;
  int v126 = v16 + 1;
  v15->timer = v126;
  int * v18 = v15->regs;
  int v19 = v18[11];
  int * v20 = v15->cache_tags;
  int v130 = (((int)((unsigned int)((int)((unsigned int)v19 >> 2)) >> 1)) & 1) * 2;
  int v21 = v20[v130];
  int v131 = ((((int)((unsigned int)((int)((unsigned int)v19 >> 2)) >> 1)) & 1) * 2) + 1;
  int v22 = v20[v131];
  int v132 = 4 + ((((int)((unsigned int)((int)((unsigned int)v19 >> 2)) >> 1)) & 3) * 2);
  int v23 = v20[v132];
  int v133 = (4 + ((((int)((unsigned int)((int)((unsigned int)v19 >> 2)) >> 1)) & 3) * 2)) + 1;
  int v24 = v20[v133];
  int v25 = v15->timer;
  int v134 = v25 + ((100 ^ (((~(((v23 ^ ((int)((unsigned int)((int)((unsigned int)v19 >> 2)) >> 1))) | (-(v23 ^ ((int)((unsigned int)((int)((unsigned int)v19 >> 2)) >> 1))))) >> 31)) | (~(((v24 ^ ((int)((unsigned int)((int)((unsigned int)v19 >> 2)) >> 1))) | (-(v24 ^ ((int)((unsigned int)((int)((unsigned int)v19 >> 2)) >> 1))))) >> 31))) & 104)) ^ (((~(((v21 ^ ((int)((unsigned int)((int)((unsigned int)v19 >> 2)) >> 1))) | (-(v21 ^ ((int)((unsigned int)((int)((unsigned int)v19 >> 2)) >> 1))))) >> 31)) | (~(((v22 ^ ((int)((unsigned int)((int)((unsigned int)v19 >> 2)) >> 1))) | (-(v22 ^ ((int)((unsigned int)((int)((unsigned int)v19 >> 2)) >> 1))))) >> 31))) & (1 ^ (100 ^ (((~(((v23 ^ ((int)((unsigned int)((int)((unsigned int)v19 >> 2)) >> 1))) | (-(v23 ^ ((int)((unsigned int)((int)((unsigned int)v19 >> 2)) >> 1))))) >> 31)) | (~(((v24 ^ ((int)((unsigned int)((int)((unsigned int)v19 >> 2)) >> 1))) | (-(v24 ^ ((int)((unsigned int)((int)((unsigned int)v19 >> 2)) >> 1))))) >> 31))) & 104)))));
  v15->timer = v134;
  int * v27 = v15->cache_vals;
  bool v135 = !(((~(((v21 ^ ((int)((unsigned int)((int)((unsigned int)v19 >> 2)) >> 1))) | (-(v21 ^ ((int)((unsigned int)((int)((unsigned int)v19 >> 2)) >> 1))))) >> 31)) | (~(((v22 ^ ((int)((unsigned int)((int)((unsigned int)v19 >> 2)) >> 1))) | (-(v22 ^ ((int)((unsigned int)((int)((unsigned int)v19 >> 2)) >> 1))))) >> 31))) == 0);
  int v120;
  if (v135) {
    int * v28 = v15->cache_age;
    int v137 = ((((int)((unsigned int)((int)((unsigned int)v19 >> 2)) >> 1)) & 1) * 2) + ((~(((v22 ^ ((int)((unsigned int)((int)((unsigned int)v19 >> 2)) >> 1))) | (-(v22 ^ ((int)((unsigned int)((int)((unsigned int)v19 >> 2)) >> 1))))) >> 31)) & 1);
    int v29 = v28[v137];
    int v30 = v28[v130];
    int v138 = v30 + ((int)((unsigned int)(v30 - v29) >> 31));
    v28[v130] = v138;
    int * v32 = v15->cache_age;
    int v33 = v32[v131];
    int v140 = v33 + ((int)((unsigned int)(v33 - v29) >> 31));
    v32[v131] = v140;
    int * v35 = v15->cache_age;
    v35[v137] = 0;
    v120 = v137;
  } else {
    int * v38 = v15->cache_age;
    int v144 = (((int)((unsigned int)((int)((unsigned int)v19 >> 2)) >> 1)) & 1) * 2;
    int v39 = v38[v144];
    int * v40 = v15->cache_tags;
    int v41 = v40[v144];
    int v42 = v38[v131];
    int v43 = v40[v131];
    bool v146 = !(((~(((v23 ^ ((int)((unsigned int)((int)((unsigned int)v19 >> 2)) >> 1))) | (-(v23 ^ ((int)((unsigned int)((int)((unsigned int)v19 >> 2)) >> 1))))) >> 31)) | (~(((v24 ^ ((int)((unsigned int)((int)((unsigned int)v19 >> 2)) >> 1))) | (-(v24 ^ ((int)((unsigned int)((int)((unsigned int)v19 >> 2)) >> 1))))) >> 31))) == 0);
    int v97;
    if (v146) {
      int * v44 = v15->cache_age;
      int v148 = (4 + ((((int)((unsigned int)((int)((unsigned int)v19 >> 2)) >> 1)) & 3) * 2)) + ((~(((v24 ^ ((int)((unsigned int)((int)((unsigned int)v19 >> 2)) >> 1))) | (-(v24 ^ ((int)((unsigned int)((int)((unsigned int)v19 >> 2)) >> 1))))) >> 31)) & 1);
      int v45 = v44[v148];
      int v46 = v44[v132];
      int v149 = v46 + ((int)((unsigned int)(v46 - v45) >> 31));
      v44[v132] = v149;
      int * v48 = v15->cache_age;
      int v49 = v48[v133];
      int v151 = v49 + ((int)((unsigned int)(v49 - v45) >> 31));
      v48[v133] = v151;
      int * v51 = v15->cache_age;
      v51[v148] = 0;
      v97 = v148;
    } else {
      int * v54 = v15->cache_age;
      int v155 = 4 + ((((int)((unsigned int)((int)((unsigned int)v19 >> 2)) >> 1)) & 3) * 2);
      int v55 = v54[v155];
      int * v56 = v15->cache_tags;
      int v57 = v56[v155];
      int v58 = v54[v133];
      int v59 = v56[v133];
      int * v60 = v15->cache_dirty;
      int v158 = (4 + ((((int)((unsigned int)((int)((unsigned int)v19 >> 2)) >> 1)) & 3) * 2)) + ((((v55 + ((~(((v57 ^ -1) | (-(v57 ^ -1))) >> 31)) & 2)) - (v58 + ((~(((v59 ^ -1) | (-(v59 ^ -1))) >> 31)) & 2))) >> 31) & 1);
      int v61 = v60[v158];
      bool v159 = !(v61 == 0);
      if (v159) {
        int * v62 = v15->cache_tags;
        int v63 = v62[v158];
        int * v64 = v15->cache_vals;
        int v162 = ((4 + ((((int)((unsigned int)((int)((unsigned int)v19 >> 2)) >> 1)) & 3) * 2)) + ((((v55 + ((~(((v57 ^ -1) | (-(v57 ^ -1))) >> 31)) & 2)) - (v58 + ((~(((v59 ^ -1) | (-(v59 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
        int v65 = v64[v162];
        int v163 = (((4 + ((((int)((unsigned int)((int)((unsigned int)v19 >> 2)) >> 1)) & 3) * 2)) + ((((v55 + ((~(((v57 ^ -1) | (-(v57 ^ -1))) >> 31)) & 2)) - (v58 + ((~(((v59 ^ -1) | (-(v59 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
        int v66 = v64[v163];
        int * v67 = v15->mem;
        int v165 = v63 * 2;
        v67[v165] = v65;
        int * v69 = v15->mem;
        int v168 = (v63 * 2) + 1;
        v69[v168] = v66;
        ;
      } else {
        ;
      }
      int * v74 = v15->mem;
      int v173 = ((int)((unsigned int)((int)((unsigned int)v19 >> 2)) >> 1)) * 2;
      int v75 = v74[v173];
      int v174 = (((int)((unsigned int)((int)((unsigned int)v19 >> 2)) >> 1)) * 2) + 1;
      int v76 = v74[v174];
      int * v77 = v15->cache_vals;
      int v176 = ((4 + ((((int)((unsigned int)((int)((unsigned int)v19 >> 2)) >> 1)) & 3) * 2)) + ((((v55 + ((~(((v57 ^ -1) | (-(v57 ^ -1))) >> 31)) & 2)) - (v58 + ((~(((v59 ^ -1) | (-(v59 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
      v77[v176] = v75;
      int * v79 = v15->cache_vals;
      int v179 = (((4 + ((((int)((unsigned int)((int)((unsigned int)v19 >> 2)) >> 1)) & 3) * 2)) + ((((v55 + ((~(((v57 ^ -1) | (-(v57 ^ -1))) >> 31)) & 2)) - (v58 + ((~(((v59 ^ -1) | (-(v59 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
      v79[v179] = v76;
      int * v81 = v15->cache_tags;
      int v182 = (int)((unsigned int)((int)((unsigned int)v19 >> 2)) >> 1);
      v81[v158] = v182;
      int * v83 = v15->cache_dirty;
      v83[v158] = 0;
      int * v85 = v15->cache_age;
      v85[v158] = 1;
      int * v87 = v15->cache_age;
      int v88 = v87[v158];
      int v89 = v87[v132];
      int v188 = v89 + ((int)((unsigned int)(v89 - v88) >> 31));
      v87[v132] = v188;
      int * v91 = v15->cache_age;
      int v92 = v91[v133];
      int v190 = v92 + ((int)((unsigned int)(v92 - v88) >> 31));
      v91[v133] = v190;
      int * v94 = v15->cache_age;
      v94[v158] = 0;
      v97 = v158;
    }
    int * v98 = v15->cache_vals;
    int v193 = v97 * 2;
    int v99 = v98[v193];
    int v194 = (v97 * 2) + 1;
    int v100 = v98[v194];
    int v195 = (((((int)((unsigned int)((int)((unsigned int)v19 >> 2)) >> 1)) & 1) * 2) + ((((v39 + ((~(((v41 ^ -1) | (-(v41 ^ -1))) >> 31)) & 2)) - (v42 + ((~(((v43 ^ -1) | (-(v43 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
    v98[v195] = v99;
    int * v102 = v15->cache_vals;
    int v198 = ((((((int)((unsigned int)((int)((unsigned int)v19 >> 2)) >> 1)) & 1) * 2) + ((((v39 + ((~(((v41 ^ -1) | (-(v41 ^ -1))) >> 31)) & 2)) - (v42 + ((~(((v43 ^ -1) | (-(v43 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
    v102[v198] = v100;
    int * v104 = v15->cache_tags;
    int v201 = ((((int)((unsigned int)((int)((unsigned int)v19 >> 2)) >> 1)) & 1) * 2) + ((((v39 + ((~(((v41 ^ -1) | (-(v41 ^ -1))) >> 31)) & 2)) - (v42 + ((~(((v43 ^ -1) | (-(v43 ^ -1))) >> 31)) & 2))) >> 31) & 1);
    int v202 = (int)((unsigned int)((int)((unsigned int)v19 >> 2)) >> 1);
    v104[v201] = v202;
    int * v106 = v15->cache_dirty;
    v106[v201] = 0;
    int * v108 = v15->cache_age;
    v108[v201] = 1;
    int * v110 = v15->cache_age;
    int v111 = v110[v201];
    int v112 = v110[v130];
    int v208 = v112 + ((int)((unsigned int)(v112 - v111) >> 31));
    v110[v130] = v208;
    int * v114 = v15->cache_age;
    int v115 = v114[v131];
    int v210 = v115 + ((int)((unsigned int)(v115 - v111) >> 31));
    v114[v131] = v210;
    int * v117 = v15->cache_age;
    v117[v201] = 0;
    v120 = v201;
  }
  int v213 = (v120 * 2) + (((int)((unsigned int)v19 >> 2)) & 1);
  int v121 = v27[v213];
  int * v122 = v15->regs;
  v122[11] = v121;
  struct StateT * v124 = slot_2(v15);
  return v124;
}

struct StateT * slot_19(struct StateT * v1071) {
  int v1072 = v1071->timer;
  int v1504 = v1072 + 1;
  v1071->timer = v1504;
  int * v1074 = v1071->regs;
  int v1075 = v1074[12];
  int v1076 = v1074[10];
  int * v1077 = v1071->saved_regs;
  v1077[10] = v1076;
  int v1079 = v1071->timer;
  int v1510 = v1079 + 1;
  v1071->timer = v1510;
  int * v1081 = v1071->regs;
  v1081[10] = 0;
  int * v1083 = v1071->saved_regs;
  int * v1084 = v1071->regs;
  int v1085 = v1084[11];
  v1083[11] = v1085;
  int v1087 = v1071->timer;
  int v1517 = v1087 + 1;
  v1071->timer = v1517;
  int * v1089 = v1071->regs;
  v1089[11] = 0;
  int v1091 = v1071->timer;
  int v1519 = v1091 + 1;
  v1071->timer = v1519;
  int * v1093 = v1071->regs;
  int v1094 = v1093[10];
  bool v1521 = (((int)((unsigned int)(v1075 + 68) >> 2)) & 3) == (((int)((unsigned int)(v1094 + 4) >> 2)) & 3);
  int v1201;
  if (v1521) {
    int v1095 = v1071->timer;
    int v1522 = v1095 + 1;
    v1071->timer = v1522;
    v1201 = v1076;
  } else {
    int * v1098 = v1071->cache_tags;
    int v1524 = (((int)((unsigned int)((int)((unsigned int)(v1094 + 4) >> 2)) >> 1)) & 1) * 2;
    int v1099 = v1098[v1524];
    int v1525 = ((((int)((unsigned int)((int)((unsigned int)(v1094 + 4) >> 2)) >> 1)) & 1) * 2) + 1;
    int v1100 = v1098[v1525];
    int v1526 = 4 + ((((int)((unsigned int)((int)((unsigned int)(v1094 + 4) >> 2)) >> 1)) & 3) * 2);
    int v1101 = v1098[v1526];
    int v1527 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v1094 + 4) >> 2)) >> 1)) & 3) * 2)) + 1;
    int v1102 = v1098[v1527];
    int v1103 = v1071->timer;
    int v1528 = v1103 + ((100 ^ (((~(((v1101 ^ ((int)((unsigned int)((int)((unsigned int)(v1094 + 4) >> 2)) >> 1))) | (-(v1101 ^ ((int)((unsigned int)((int)((unsigned int)(v1094 + 4) >> 2)) >> 1))))) >> 31)) | (~(((v1102 ^ ((int)((unsigned int)((int)((unsigned int)(v1094 + 4) >> 2)) >> 1))) | (-(v1102 ^ ((int)((unsigned int)((int)((unsigned int)(v1094 + 4) >> 2)) >> 1))))) >> 31))) & 104)) ^ (((~(((v1099 ^ ((int)((unsigned int)((int)((unsigned int)(v1094 + 4) >> 2)) >> 1))) | (-(v1099 ^ ((int)((unsigned int)((int)((unsigned int)(v1094 + 4) >> 2)) >> 1))))) >> 31)) | (~(((v1100 ^ ((int)((unsigned int)((int)((unsigned int)(v1094 + 4) >> 2)) >> 1))) | (-(v1100 ^ ((int)((unsigned int)((int)((unsigned int)(v1094 + 4) >> 2)) >> 1))))) >> 31))) & (1 ^ (100 ^ (((~(((v1101 ^ ((int)((unsigned int)((int)((unsigned int)(v1094 + 4) >> 2)) >> 1))) | (-(v1101 ^ ((int)((unsigned int)((int)((unsigned int)(v1094 + 4) >> 2)) >> 1))))) >> 31)) | (~(((v1102 ^ ((int)((unsigned int)((int)((unsigned int)(v1094 + 4) >> 2)) >> 1))) | (-(v1102 ^ ((int)((unsigned int)((int)((unsigned int)(v1094 + 4) >> 2)) >> 1))))) >> 31))) & 104)))));
    v1071->timer = v1528;
    int * v1105 = v1071->cache_vals;
    bool v1529 = !(((~(((v1099 ^ ((int)((unsigned int)((int)((unsigned int)(v1094 + 4) >> 2)) >> 1))) | (-(v1099 ^ ((int)((unsigned int)((int)((unsigned int)(v1094 + 4) >> 2)) >> 1))))) >> 31)) | (~(((v1100 ^ ((int)((unsigned int)((int)((unsigned int)(v1094 + 4) >> 2)) >> 1))) | (-(v1100 ^ ((int)((unsigned int)((int)((unsigned int)(v1094 + 4) >> 2)) >> 1))))) >> 31))) == 0);
    int v1198;
    if (v1529) {
      int * v1106 = v1071->cache_age;
      int v1531 = ((((int)((unsigned int)((int)((unsigned int)(v1094 + 4) >> 2)) >> 1)) & 1) * 2) + ((~(((v1100 ^ ((int)((unsigned int)((int)((unsigned int)(v1094 + 4) >> 2)) >> 1))) | (-(v1100 ^ ((int)((unsigned int)((int)((unsigned int)(v1094 + 4) >> 2)) >> 1))))) >> 31)) & 1);
      int v1107 = v1106[v1531];
      int v1108 = v1106[v1524];
      int v1532 = v1108 + ((int)((unsigned int)(v1108 - v1107) >> 31));
      v1106[v1524] = v1532;
      int * v1110 = v1071->cache_age;
      int v1111 = v1110[v1525];
      int v1534 = v1111 + ((int)((unsigned int)(v1111 - v1107) >> 31));
      v1110[v1525] = v1534;
      int * v1113 = v1071->cache_age;
      v1113[v1531] = 0;
      v1198 = v1531;
    } else {
      int * v1116 = v1071->cache_age;
      int v1537 = (((int)((unsigned int)((int)((unsigned int)(v1094 + 4) >> 2)) >> 1)) & 1) * 2;
      int v1117 = v1116[v1537];
      int * v1118 = v1071->cache_tags;
      int v1119 = v1118[v1537];
      int v1120 = v1116[v1525];
      int v1121 = v1118[v1525];
      bool v1539 = !(((~(((v1101 ^ ((int)((unsigned int)((int)((unsigned int)(v1094 + 4) >> 2)) >> 1))) | (-(v1101 ^ ((int)((unsigned int)((int)((unsigned int)(v1094 + 4) >> 2)) >> 1))))) >> 31)) | (~(((v1102 ^ ((int)((unsigned int)((int)((unsigned int)(v1094 + 4) >> 2)) >> 1))) | (-(v1102 ^ ((int)((unsigned int)((int)((unsigned int)(v1094 + 4) >> 2)) >> 1))))) >> 31))) == 0);
      int v1175;
      if (v1539) {
        int * v1122 = v1071->cache_age;
        int v1541 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v1094 + 4) >> 2)) >> 1)) & 3) * 2)) + ((~(((v1102 ^ ((int)((unsigned int)((int)((unsigned int)(v1094 + 4) >> 2)) >> 1))) | (-(v1102 ^ ((int)((unsigned int)((int)((unsigned int)(v1094 + 4) >> 2)) >> 1))))) >> 31)) & 1);
        int v1123 = v1122[v1541];
        int v1124 = v1122[v1526];
        int v1542 = v1124 + ((int)((unsigned int)(v1124 - v1123) >> 31));
        v1122[v1526] = v1542;
        int * v1126 = v1071->cache_age;
        int v1127 = v1126[v1527];
        int v1544 = v1127 + ((int)((unsigned int)(v1127 - v1123) >> 31));
        v1126[v1527] = v1544;
        int * v1129 = v1071->cache_age;
        v1129[v1541] = 0;
        v1175 = v1541;
      } else {
        int * v1132 = v1071->cache_age;
        int v1547 = 4 + ((((int)((unsigned int)((int)((unsigned int)(v1094 + 4) >> 2)) >> 1)) & 3) * 2);
        int v1133 = v1132[v1547];
        int * v1134 = v1071->cache_tags;
        int v1135 = v1134[v1547];
        int v1136 = v1132[v1527];
        int v1137 = v1134[v1527];
        int * v1138 = v1071->cache_dirty;
        int v1550 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v1094 + 4) >> 2)) >> 1)) & 3) * 2)) + ((((v1133 + ((~(((v1135 ^ -1) | (-(v1135 ^ -1))) >> 31)) & 2)) - (v1136 + ((~(((v1137 ^ -1) | (-(v1137 ^ -1))) >> 31)) & 2))) >> 31) & 1);
        int v1139 = v1138[v1550];
        bool v1551 = !(v1139 == 0);
        if (v1551) {
          int * v1140 = v1071->cache_tags;
          int v1141 = v1140[v1550];
          int * v1142 = v1071->cache_vals;
          int v1554 = ((4 + ((((int)((unsigned int)((int)((unsigned int)(v1094 + 4) >> 2)) >> 1)) & 3) * 2)) + ((((v1133 + ((~(((v1135 ^ -1) | (-(v1135 ^ -1))) >> 31)) & 2)) - (v1136 + ((~(((v1137 ^ -1) | (-(v1137 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
          int v1143 = v1142[v1554];
          int v1555 = (((4 + ((((int)((unsigned int)((int)((unsigned int)(v1094 + 4) >> 2)) >> 1)) & 3) * 2)) + ((((v1133 + ((~(((v1135 ^ -1) | (-(v1135 ^ -1))) >> 31)) & 2)) - (v1136 + ((~(((v1137 ^ -1) | (-(v1137 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
          int v1144 = v1142[v1555];
          int * v1145 = v1071->mem;
          int v1557 = v1141 * 2;
          v1145[v1557] = v1143;
          int * v1147 = v1071->mem;
          int v1560 = (v1141 * 2) + 1;
          v1147[v1560] = v1144;
          ;
        } else {
          ;
        }
        int * v1152 = v1071->mem;
        int v1565 = ((int)((unsigned int)((int)((unsigned int)(v1094 + 4) >> 2)) >> 1)) * 2;
        int v1153 = v1152[v1565];
        int v1566 = (((int)((unsigned int)((int)((unsigned int)(v1094 + 4) >> 2)) >> 1)) * 2) + 1;
        int v1154 = v1152[v1566];
        int * v1155 = v1071->cache_vals;
        int v1568 = ((4 + ((((int)((unsigned int)((int)((unsigned int)(v1094 + 4) >> 2)) >> 1)) & 3) * 2)) + ((((v1133 + ((~(((v1135 ^ -1) | (-(v1135 ^ -1))) >> 31)) & 2)) - (v1136 + ((~(((v1137 ^ -1) | (-(v1137 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
        v1155[v1568] = v1153;
        int * v1157 = v1071->cache_vals;
        int v1571 = (((4 + ((((int)((unsigned int)((int)((unsigned int)(v1094 + 4) >> 2)) >> 1)) & 3) * 2)) + ((((v1133 + ((~(((v1135 ^ -1) | (-(v1135 ^ -1))) >> 31)) & 2)) - (v1136 + ((~(((v1137 ^ -1) | (-(v1137 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
        v1157[v1571] = v1154;
        int * v1159 = v1071->cache_tags;
        int v1574 = (int)((unsigned int)((int)((unsigned int)(v1094 + 4) >> 2)) >> 1);
        v1159[v1550] = v1574;
        int * v1161 = v1071->cache_dirty;
        v1161[v1550] = 0;
        int * v1163 = v1071->cache_age;
        v1163[v1550] = 1;
        int * v1165 = v1071->cache_age;
        int v1166 = v1165[v1550];
        int v1167 = v1165[v1526];
        int v1579 = v1167 + ((int)((unsigned int)(v1167 - v1166) >> 31));
        v1165[v1526] = v1579;
        int * v1169 = v1071->cache_age;
        int v1170 = v1169[v1527];
        int v1581 = v1170 + ((int)((unsigned int)(v1170 - v1166) >> 31));
        v1169[v1527] = v1581;
        int * v1172 = v1071->cache_age;
        v1172[v1550] = 0;
        v1175 = v1550;
      }
      int * v1176 = v1071->cache_vals;
      int v1584 = v1175 * 2;
      int v1177 = v1176[v1584];
      int v1585 = (v1175 * 2) + 1;
      int v1178 = v1176[v1585];
      int v1586 = (((((int)((unsigned int)((int)((unsigned int)(v1094 + 4) >> 2)) >> 1)) & 1) * 2) + ((((v1117 + ((~(((v1119 ^ -1) | (-(v1119 ^ -1))) >> 31)) & 2)) - (v1120 + ((~(((v1121 ^ -1) | (-(v1121 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
      v1176[v1586] = v1177;
      int * v1180 = v1071->cache_vals;
      int v1589 = ((((((int)((unsigned int)((int)((unsigned int)(v1094 + 4) >> 2)) >> 1)) & 1) * 2) + ((((v1117 + ((~(((v1119 ^ -1) | (-(v1119 ^ -1))) >> 31)) & 2)) - (v1120 + ((~(((v1121 ^ -1) | (-(v1121 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
      v1180[v1589] = v1178;
      int * v1182 = v1071->cache_tags;
      int v1592 = ((((int)((unsigned int)((int)((unsigned int)(v1094 + 4) >> 2)) >> 1)) & 1) * 2) + ((((v1117 + ((~(((v1119 ^ -1) | (-(v1119 ^ -1))) >> 31)) & 2)) - (v1120 + ((~(((v1121 ^ -1) | (-(v1121 ^ -1))) >> 31)) & 2))) >> 31) & 1);
      int v1593 = (int)((unsigned int)((int)((unsigned int)(v1094 + 4) >> 2)) >> 1);
      v1182[v1592] = v1593;
      int * v1184 = v1071->cache_dirty;
      v1184[v1592] = 0;
      int * v1186 = v1071->cache_age;
      v1186[v1592] = 1;
      int * v1188 = v1071->cache_age;
      int v1189 = v1188[v1592];
      int v1190 = v1188[v1524];
      int v1598 = v1190 + ((int)((unsigned int)(v1190 - v1189) >> 31));
      v1188[v1524] = v1598;
      int * v1192 = v1071->cache_age;
      int v1193 = v1192[v1525];
      int v1600 = v1193 + ((int)((unsigned int)(v1193 - v1189) >> 31));
      v1192[v1525] = v1600;
      int * v1195 = v1071->cache_age;
      v1195[v1592] = 0;
      v1198 = v1592;
    }
    int v1603 = (v1198 * 2) + (((int)((unsigned int)(v1094 + 4) >> 2)) & 1);
    int v1199 = v1105[v1603];
    v1201 = v1199;
  }
  int * v1202 = v1071->regs;
  v1202[10] = v1201;
  int * v1204 = v1071->saved_regs;
  int * v1205 = v1071->regs;
  int v1206 = v1205[12];
  v1204[12] = v1206;
  int v1208 = v1071->timer;
  int v1610 = v1208 + 1;
  v1071->timer = v1610;
  int * v1210 = v1071->regs;
  int v1211 = v1210[11];
  bool v1612 = (((int)((unsigned int)(v1075 + 68) >> 2)) & 3) == (((int)((unsigned int)(v1211 + 68) >> 2)) & 3);
  int v1318;
  if (v1612) {
    int v1212 = v1071->timer;
    int v1613 = v1212 + 1;
    v1071->timer = v1613;
    v1318 = v1076;
  } else {
    int * v1215 = v1071->cache_tags;
    int v1615 = (((int)((unsigned int)((int)((unsigned int)(v1211 + 68) >> 2)) >> 1)) & 1) * 2;
    int v1216 = v1215[v1615];
    int v1616 = ((((int)((unsigned int)((int)((unsigned int)(v1211 + 68) >> 2)) >> 1)) & 1) * 2) + 1;
    int v1217 = v1215[v1616];
    int v1617 = 4 + ((((int)((unsigned int)((int)((unsigned int)(v1211 + 68) >> 2)) >> 1)) & 3) * 2);
    int v1218 = v1215[v1617];
    int v1618 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v1211 + 68) >> 2)) >> 1)) & 3) * 2)) + 1;
    int v1219 = v1215[v1618];
    int v1220 = v1071->timer;
    int v1619 = v1220 + ((100 ^ (((~(((v1218 ^ ((int)((unsigned int)((int)((unsigned int)(v1211 + 68) >> 2)) >> 1))) | (-(v1218 ^ ((int)((unsigned int)((int)((unsigned int)(v1211 + 68) >> 2)) >> 1))))) >> 31)) | (~(((v1219 ^ ((int)((unsigned int)((int)((unsigned int)(v1211 + 68) >> 2)) >> 1))) | (-(v1219 ^ ((int)((unsigned int)((int)((unsigned int)(v1211 + 68) >> 2)) >> 1))))) >> 31))) & 104)) ^ (((~(((v1216 ^ ((int)((unsigned int)((int)((unsigned int)(v1211 + 68) >> 2)) >> 1))) | (-(v1216 ^ ((int)((unsigned int)((int)((unsigned int)(v1211 + 68) >> 2)) >> 1))))) >> 31)) | (~(((v1217 ^ ((int)((unsigned int)((int)((unsigned int)(v1211 + 68) >> 2)) >> 1))) | (-(v1217 ^ ((int)((unsigned int)((int)((unsigned int)(v1211 + 68) >> 2)) >> 1))))) >> 31))) & (1 ^ (100 ^ (((~(((v1218 ^ ((int)((unsigned int)((int)((unsigned int)(v1211 + 68) >> 2)) >> 1))) | (-(v1218 ^ ((int)((unsigned int)((int)((unsigned int)(v1211 + 68) >> 2)) >> 1))))) >> 31)) | (~(((v1219 ^ ((int)((unsigned int)((int)((unsigned int)(v1211 + 68) >> 2)) >> 1))) | (-(v1219 ^ ((int)((unsigned int)((int)((unsigned int)(v1211 + 68) >> 2)) >> 1))))) >> 31))) & 104)))));
    v1071->timer = v1619;
    int * v1222 = v1071->cache_vals;
    bool v1620 = !(((~(((v1216 ^ ((int)((unsigned int)((int)((unsigned int)(v1211 + 68) >> 2)) >> 1))) | (-(v1216 ^ ((int)((unsigned int)((int)((unsigned int)(v1211 + 68) >> 2)) >> 1))))) >> 31)) | (~(((v1217 ^ ((int)((unsigned int)((int)((unsigned int)(v1211 + 68) >> 2)) >> 1))) | (-(v1217 ^ ((int)((unsigned int)((int)((unsigned int)(v1211 + 68) >> 2)) >> 1))))) >> 31))) == 0);
    int v1315;
    if (v1620) {
      int * v1223 = v1071->cache_age;
      int v1622 = ((((int)((unsigned int)((int)((unsigned int)(v1211 + 68) >> 2)) >> 1)) & 1) * 2) + ((~(((v1217 ^ ((int)((unsigned int)((int)((unsigned int)(v1211 + 68) >> 2)) >> 1))) | (-(v1217 ^ ((int)((unsigned int)((int)((unsigned int)(v1211 + 68) >> 2)) >> 1))))) >> 31)) & 1);
      int v1224 = v1223[v1622];
      int v1225 = v1223[v1615];
      int v1623 = v1225 + ((int)((unsigned int)(v1225 - v1224) >> 31));
      v1223[v1615] = v1623;
      int * v1227 = v1071->cache_age;
      int v1228 = v1227[v1616];
      int v1625 = v1228 + ((int)((unsigned int)(v1228 - v1224) >> 31));
      v1227[v1616] = v1625;
      int * v1230 = v1071->cache_age;
      v1230[v1622] = 0;
      v1315 = v1622;
    } else {
      int * v1233 = v1071->cache_age;
      int v1628 = (((int)((unsigned int)((int)((unsigned int)(v1211 + 68) >> 2)) >> 1)) & 1) * 2;
      int v1234 = v1233[v1628];
      int * v1235 = v1071->cache_tags;
      int v1236 = v1235[v1628];
      int v1237 = v1233[v1616];
      int v1238 = v1235[v1616];
      bool v1630 = !(((~(((v1218 ^ ((int)((unsigned int)((int)((unsigned int)(v1211 + 68) >> 2)) >> 1))) | (-(v1218 ^ ((int)((unsigned int)((int)((unsigned int)(v1211 + 68) >> 2)) >> 1))))) >> 31)) | (~(((v1219 ^ ((int)((unsigned int)((int)((unsigned int)(v1211 + 68) >> 2)) >> 1))) | (-(v1219 ^ ((int)((unsigned int)((int)((unsigned int)(v1211 + 68) >> 2)) >> 1))))) >> 31))) == 0);
      int v1292;
      if (v1630) {
        int * v1239 = v1071->cache_age;
        int v1632 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v1211 + 68) >> 2)) >> 1)) & 3) * 2)) + ((~(((v1219 ^ ((int)((unsigned int)((int)((unsigned int)(v1211 + 68) >> 2)) >> 1))) | (-(v1219 ^ ((int)((unsigned int)((int)((unsigned int)(v1211 + 68) >> 2)) >> 1))))) >> 31)) & 1);
        int v1240 = v1239[v1632];
        int v1241 = v1239[v1617];
        int v1633 = v1241 + ((int)((unsigned int)(v1241 - v1240) >> 31));
        v1239[v1617] = v1633;
        int * v1243 = v1071->cache_age;
        int v1244 = v1243[v1618];
        int v1635 = v1244 + ((int)((unsigned int)(v1244 - v1240) >> 31));
        v1243[v1618] = v1635;
        int * v1246 = v1071->cache_age;
        v1246[v1632] = 0;
        v1292 = v1632;
      } else {
        int * v1249 = v1071->cache_age;
        int v1638 = 4 + ((((int)((unsigned int)((int)((unsigned int)(v1211 + 68) >> 2)) >> 1)) & 3) * 2);
        int v1250 = v1249[v1638];
        int * v1251 = v1071->cache_tags;
        int v1252 = v1251[v1638];
        int v1253 = v1249[v1618];
        int v1254 = v1251[v1618];
        int * v1255 = v1071->cache_dirty;
        int v1641 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v1211 + 68) >> 2)) >> 1)) & 3) * 2)) + ((((v1250 + ((~(((v1252 ^ -1) | (-(v1252 ^ -1))) >> 31)) & 2)) - (v1253 + ((~(((v1254 ^ -1) | (-(v1254 ^ -1))) >> 31)) & 2))) >> 31) & 1);
        int v1256 = v1255[v1641];
        bool v1642 = !(v1256 == 0);
        if (v1642) {
          int * v1257 = v1071->cache_tags;
          int v1258 = v1257[v1641];
          int * v1259 = v1071->cache_vals;
          int v1645 = ((4 + ((((int)((unsigned int)((int)((unsigned int)(v1211 + 68) >> 2)) >> 1)) & 3) * 2)) + ((((v1250 + ((~(((v1252 ^ -1) | (-(v1252 ^ -1))) >> 31)) & 2)) - (v1253 + ((~(((v1254 ^ -1) | (-(v1254 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
          int v1260 = v1259[v1645];
          int v1646 = (((4 + ((((int)((unsigned int)((int)((unsigned int)(v1211 + 68) >> 2)) >> 1)) & 3) * 2)) + ((((v1250 + ((~(((v1252 ^ -1) | (-(v1252 ^ -1))) >> 31)) & 2)) - (v1253 + ((~(((v1254 ^ -1) | (-(v1254 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
          int v1261 = v1259[v1646];
          int * v1262 = v1071->mem;
          int v1648 = v1258 * 2;
          v1262[v1648] = v1260;
          int * v1264 = v1071->mem;
          int v1651 = (v1258 * 2) + 1;
          v1264[v1651] = v1261;
          ;
        } else {
          ;
        }
        int * v1269 = v1071->mem;
        int v1656 = ((int)((unsigned int)((int)((unsigned int)(v1211 + 68) >> 2)) >> 1)) * 2;
        int v1270 = v1269[v1656];
        int v1657 = (((int)((unsigned int)((int)((unsigned int)(v1211 + 68) >> 2)) >> 1)) * 2) + 1;
        int v1271 = v1269[v1657];
        int * v1272 = v1071->cache_vals;
        int v1659 = ((4 + ((((int)((unsigned int)((int)((unsigned int)(v1211 + 68) >> 2)) >> 1)) & 3) * 2)) + ((((v1250 + ((~(((v1252 ^ -1) | (-(v1252 ^ -1))) >> 31)) & 2)) - (v1253 + ((~(((v1254 ^ -1) | (-(v1254 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
        v1272[v1659] = v1270;
        int * v1274 = v1071->cache_vals;
        int v1662 = (((4 + ((((int)((unsigned int)((int)((unsigned int)(v1211 + 68) >> 2)) >> 1)) & 3) * 2)) + ((((v1250 + ((~(((v1252 ^ -1) | (-(v1252 ^ -1))) >> 31)) & 2)) - (v1253 + ((~(((v1254 ^ -1) | (-(v1254 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
        v1274[v1662] = v1271;
        int * v1276 = v1071->cache_tags;
        int v1665 = (int)((unsigned int)((int)((unsigned int)(v1211 + 68) >> 2)) >> 1);
        v1276[v1641] = v1665;
        int * v1278 = v1071->cache_dirty;
        v1278[v1641] = 0;
        int * v1280 = v1071->cache_age;
        v1280[v1641] = 1;
        int * v1282 = v1071->cache_age;
        int v1283 = v1282[v1641];
        int v1284 = v1282[v1617];
        int v1670 = v1284 + ((int)((unsigned int)(v1284 - v1283) >> 31));
        v1282[v1617] = v1670;
        int * v1286 = v1071->cache_age;
        int v1287 = v1286[v1618];
        int v1672 = v1287 + ((int)((unsigned int)(v1287 - v1283) >> 31));
        v1286[v1618] = v1672;
        int * v1289 = v1071->cache_age;
        v1289[v1641] = 0;
        v1292 = v1641;
      }
      int * v1293 = v1071->cache_vals;
      int v1675 = v1292 * 2;
      int v1294 = v1293[v1675];
      int v1676 = (v1292 * 2) + 1;
      int v1295 = v1293[v1676];
      int v1677 = (((((int)((unsigned int)((int)((unsigned int)(v1211 + 68) >> 2)) >> 1)) & 1) * 2) + ((((v1234 + ((~(((v1236 ^ -1) | (-(v1236 ^ -1))) >> 31)) & 2)) - (v1237 + ((~(((v1238 ^ -1) | (-(v1238 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
      v1293[v1677] = v1294;
      int * v1297 = v1071->cache_vals;
      int v1680 = ((((((int)((unsigned int)((int)((unsigned int)(v1211 + 68) >> 2)) >> 1)) & 1) * 2) + ((((v1234 + ((~(((v1236 ^ -1) | (-(v1236 ^ -1))) >> 31)) & 2)) - (v1237 + ((~(((v1238 ^ -1) | (-(v1238 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
      v1297[v1680] = v1295;
      int * v1299 = v1071->cache_tags;
      int v1683 = ((((int)((unsigned int)((int)((unsigned int)(v1211 + 68) >> 2)) >> 1)) & 1) * 2) + ((((v1234 + ((~(((v1236 ^ -1) | (-(v1236 ^ -1))) >> 31)) & 2)) - (v1237 + ((~(((v1238 ^ -1) | (-(v1238 ^ -1))) >> 31)) & 2))) >> 31) & 1);
      int v1684 = (int)((unsigned int)((int)((unsigned int)(v1211 + 68) >> 2)) >> 1);
      v1299[v1683] = v1684;
      int * v1301 = v1071->cache_dirty;
      v1301[v1683] = 0;
      int * v1303 = v1071->cache_age;
      v1303[v1683] = 1;
      int * v1305 = v1071->cache_age;
      int v1306 = v1305[v1683];
      int v1307 = v1305[v1615];
      int v1689 = v1307 + ((int)((unsigned int)(v1307 - v1306) >> 31));
      v1305[v1615] = v1689;
      int * v1309 = v1071->cache_age;
      int v1310 = v1309[v1616];
      int v1691 = v1310 + ((int)((unsigned int)(v1310 - v1306) >> 31));
      v1309[v1616] = v1691;
      int * v1312 = v1071->cache_age;
      v1312[v1683] = 0;
      v1315 = v1683;
    }
    int v1694 = (v1315 * 2) + (((int)((unsigned int)(v1211 + 68) >> 2)) & 1);
    int v1316 = v1222[v1694];
    v1318 = v1316;
  }
  int * v1319 = v1071->regs;
  v1319[12] = v1318;
  int * v1321 = v1071->cache_tags;
  int v1699 = (((int)((unsigned int)((int)((unsigned int)(v1075 + 68) >> 2)) >> 1)) & 1) * 2;
  int v1322 = v1321[v1699];
  int v1700 = ((((int)((unsigned int)((int)((unsigned int)(v1075 + 68) >> 2)) >> 1)) & 1) * 2) + 1;
  int v1323 = v1321[v1700];
  int v1701 = 4 + ((((int)((unsigned int)((int)((unsigned int)(v1075 + 68) >> 2)) >> 1)) & 3) * 2);
  int v1324 = v1321[v1701];
  int v1702 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v1075 + 68) >> 2)) >> 1)) & 3) * 2)) + 1;
  int v1325 = v1321[v1702];
  int v1326 = v1071->timer;
  int v1703 = v1326 + ((100 ^ (((~(((v1324 ^ ((int)((unsigned int)((int)((unsigned int)(v1075 + 68) >> 2)) >> 1))) | (-(v1324 ^ ((int)((unsigned int)((int)((unsigned int)(v1075 + 68) >> 2)) >> 1))))) >> 31)) | (~(((v1325 ^ ((int)((unsigned int)((int)((unsigned int)(v1075 + 68) >> 2)) >> 1))) | (-(v1325 ^ ((int)((unsigned int)((int)((unsigned int)(v1075 + 68) >> 2)) >> 1))))) >> 31))) & 104)) ^ (((~(((v1322 ^ ((int)((unsigned int)((int)((unsigned int)(v1075 + 68) >> 2)) >> 1))) | (-(v1322 ^ ((int)((unsigned int)((int)((unsigned int)(v1075 + 68) >> 2)) >> 1))))) >> 31)) | (~(((v1323 ^ ((int)((unsigned int)((int)((unsigned int)(v1075 + 68) >> 2)) >> 1))) | (-(v1323 ^ ((int)((unsigned int)((int)((unsigned int)(v1075 + 68) >> 2)) >> 1))))) >> 31))) & (1 ^ (100 ^ (((~(((v1324 ^ ((int)((unsigned int)((int)((unsigned int)(v1075 + 68) >> 2)) >> 1))) | (-(v1324 ^ ((int)((unsigned int)((int)((unsigned int)(v1075 + 68) >> 2)) >> 1))))) >> 31)) | (~(((v1325 ^ ((int)((unsigned int)((int)((unsigned int)(v1075 + 68) >> 2)) >> 1))) | (-(v1325 ^ ((int)((unsigned int)((int)((unsigned int)(v1075 + 68) >> 2)) >> 1))))) >> 31))) & 104)))));
  v1071->timer = v1703;
  bool v1704 = !(((~(((v1322 ^ ((int)((unsigned int)((int)((unsigned int)(v1075 + 68) >> 2)) >> 1))) | (-(v1322 ^ ((int)((unsigned int)((int)((unsigned int)(v1075 + 68) >> 2)) >> 1))))) >> 31)) | (~(((v1323 ^ ((int)((unsigned int)((int)((unsigned int)(v1075 + 68) >> 2)) >> 1))) | (-(v1323 ^ ((int)((unsigned int)((int)((unsigned int)(v1075 + 68) >> 2)) >> 1))))) >> 31))) == 0);
  int v1420;
  if (v1704) {
    int * v1328 = v1071->cache_age;
    int v1706 = ((((int)((unsigned int)((int)((unsigned int)(v1075 + 68) >> 2)) >> 1)) & 1) * 2) + ((~(((v1323 ^ ((int)((unsigned int)((int)((unsigned int)(v1075 + 68) >> 2)) >> 1))) | (-(v1323 ^ ((int)((unsigned int)((int)((unsigned int)(v1075 + 68) >> 2)) >> 1))))) >> 31)) & 1);
    int v1329 = v1328[v1706];
    int v1330 = v1328[v1699];
    int v1707 = v1330 + ((int)((unsigned int)(v1330 - v1329) >> 31));
    v1328[v1699] = v1707;
    int * v1332 = v1071->cache_age;
    int v1333 = v1332[v1700];
    int v1709 = v1333 + ((int)((unsigned int)(v1333 - v1329) >> 31));
    v1332[v1700] = v1709;
    int * v1335 = v1071->cache_age;
    v1335[v1706] = 0;
    v1420 = v1706;
  } else {
    int * v1338 = v1071->cache_age;
    int v1712 = (((int)((unsigned int)((int)((unsigned int)(v1075 + 68) >> 2)) >> 1)) & 1) * 2;
    int v1339 = v1338[v1712];
    int * v1340 = v1071->cache_tags;
    int v1341 = v1340[v1712];
    int v1342 = v1338[v1700];
    int v1343 = v1340[v1700];
    bool v1714 = !(((~(((v1324 ^ ((int)((unsigned int)((int)((unsigned int)(v1075 + 68) >> 2)) >> 1))) | (-(v1324 ^ ((int)((unsigned int)((int)((unsigned int)(v1075 + 68) >> 2)) >> 1))))) >> 31)) | (~(((v1325 ^ ((int)((unsigned int)((int)((unsigned int)(v1075 + 68) >> 2)) >> 1))) | (-(v1325 ^ ((int)((unsigned int)((int)((unsigned int)(v1075 + 68) >> 2)) >> 1))))) >> 31))) == 0);
    int v1397;
    if (v1714) {
      int * v1344 = v1071->cache_age;
      int v1716 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v1075 + 68) >> 2)) >> 1)) & 3) * 2)) + ((~(((v1325 ^ ((int)((unsigned int)((int)((unsigned int)(v1075 + 68) >> 2)) >> 1))) | (-(v1325 ^ ((int)((unsigned int)((int)((unsigned int)(v1075 + 68) >> 2)) >> 1))))) >> 31)) & 1);
      int v1345 = v1344[v1716];
      int v1346 = v1344[v1701];
      int v1717 = v1346 + ((int)((unsigned int)(v1346 - v1345) >> 31));
      v1344[v1701] = v1717;
      int * v1348 = v1071->cache_age;
      int v1349 = v1348[v1702];
      int v1719 = v1349 + ((int)((unsigned int)(v1349 - v1345) >> 31));
      v1348[v1702] = v1719;
      int * v1351 = v1071->cache_age;
      v1351[v1716] = 0;
      v1397 = v1716;
    } else {
      int * v1354 = v1071->cache_age;
      int v1722 = 4 + ((((int)((unsigned int)((int)((unsigned int)(v1075 + 68) >> 2)) >> 1)) & 3) * 2);
      int v1355 = v1354[v1722];
      int * v1356 = v1071->cache_tags;
      int v1357 = v1356[v1722];
      int v1358 = v1354[v1702];
      int v1359 = v1356[v1702];
      int * v1360 = v1071->cache_dirty;
      int v1725 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v1075 + 68) >> 2)) >> 1)) & 3) * 2)) + ((((v1355 + ((~(((v1357 ^ -1) | (-(v1357 ^ -1))) >> 31)) & 2)) - (v1358 + ((~(((v1359 ^ -1) | (-(v1359 ^ -1))) >> 31)) & 2))) >> 31) & 1);
      int v1361 = v1360[v1725];
      bool v1726 = !(v1361 == 0);
      if (v1726) {
        int * v1362 = v1071->cache_tags;
        int v1363 = v1362[v1725];
        int * v1364 = v1071->cache_vals;
        int v1729 = ((4 + ((((int)((unsigned int)((int)((unsigned int)(v1075 + 68) >> 2)) >> 1)) & 3) * 2)) + ((((v1355 + ((~(((v1357 ^ -1) | (-(v1357 ^ -1))) >> 31)) & 2)) - (v1358 + ((~(((v1359 ^ -1) | (-(v1359 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
        int v1365 = v1364[v1729];
        int v1730 = (((4 + ((((int)((unsigned int)((int)((unsigned int)(v1075 + 68) >> 2)) >> 1)) & 3) * 2)) + ((((v1355 + ((~(((v1357 ^ -1) | (-(v1357 ^ -1))) >> 31)) & 2)) - (v1358 + ((~(((v1359 ^ -1) | (-(v1359 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
        int v1366 = v1364[v1730];
        int * v1367 = v1071->mem;
        int v1732 = v1363 * 2;
        v1367[v1732] = v1365;
        int * v1369 = v1071->mem;
        int v1735 = (v1363 * 2) + 1;
        v1369[v1735] = v1366;
        ;
      } else {
        ;
      }
      int * v1374 = v1071->mem;
      int v1740 = ((int)((unsigned int)((int)((unsigned int)(v1075 + 68) >> 2)) >> 1)) * 2;
      int v1375 = v1374[v1740];
      int v1741 = (((int)((unsigned int)((int)((unsigned int)(v1075 + 68) >> 2)) >> 1)) * 2) + 1;
      int v1376 = v1374[v1741];
      int * v1377 = v1071->cache_vals;
      int v1743 = ((4 + ((((int)((unsigned int)((int)((unsigned int)(v1075 + 68) >> 2)) >> 1)) & 3) * 2)) + ((((v1355 + ((~(((v1357 ^ -1) | (-(v1357 ^ -1))) >> 31)) & 2)) - (v1358 + ((~(((v1359 ^ -1) | (-(v1359 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
      v1377[v1743] = v1375;
      int * v1379 = v1071->cache_vals;
      int v1746 = (((4 + ((((int)((unsigned int)((int)((unsigned int)(v1075 + 68) >> 2)) >> 1)) & 3) * 2)) + ((((v1355 + ((~(((v1357 ^ -1) | (-(v1357 ^ -1))) >> 31)) & 2)) - (v1358 + ((~(((v1359 ^ -1) | (-(v1359 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
      v1379[v1746] = v1376;
      int * v1381 = v1071->cache_tags;
      int v1749 = (int)((unsigned int)((int)((unsigned int)(v1075 + 68) >> 2)) >> 1);
      v1381[v1725] = v1749;
      int * v1383 = v1071->cache_dirty;
      v1383[v1725] = 0;
      int * v1385 = v1071->cache_age;
      v1385[v1725] = 1;
      int * v1387 = v1071->cache_age;
      int v1388 = v1387[v1725];
      int v1389 = v1387[v1701];
      int v1754 = v1389 + ((int)((unsigned int)(v1389 - v1388) >> 31));
      v1387[v1701] = v1754;
      int * v1391 = v1071->cache_age;
      int v1392 = v1391[v1702];
      int v1756 = v1392 + ((int)((unsigned int)(v1392 - v1388) >> 31));
      v1391[v1702] = v1756;
      int * v1394 = v1071->cache_age;
      v1394[v1725] = 0;
      v1397 = v1725;
    }
    int * v1398 = v1071->cache_vals;
    int v1759 = v1397 * 2;
    int v1399 = v1398[v1759];
    int v1760 = (v1397 * 2) + 1;
    int v1400 = v1398[v1760];
    int v1761 = (((((int)((unsigned int)((int)((unsigned int)(v1075 + 68) >> 2)) >> 1)) & 1) * 2) + ((((v1339 + ((~(((v1341 ^ -1) | (-(v1341 ^ -1))) >> 31)) & 2)) - (v1342 + ((~(((v1343 ^ -1) | (-(v1343 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
    v1398[v1761] = v1399;
    int * v1402 = v1071->cache_vals;
    int v1764 = ((((((int)((unsigned int)((int)((unsigned int)(v1075 + 68) >> 2)) >> 1)) & 1) * 2) + ((((v1339 + ((~(((v1341 ^ -1) | (-(v1341 ^ -1))) >> 31)) & 2)) - (v1342 + ((~(((v1343 ^ -1) | (-(v1343 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
    v1402[v1764] = v1400;
    int * v1404 = v1071->cache_tags;
    int v1767 = ((((int)((unsigned int)((int)((unsigned int)(v1075 + 68) >> 2)) >> 1)) & 1) * 2) + ((((v1339 + ((~(((v1341 ^ -1) | (-(v1341 ^ -1))) >> 31)) & 2)) - (v1342 + ((~(((v1343 ^ -1) | (-(v1343 ^ -1))) >> 31)) & 2))) >> 31) & 1);
    int v1768 = (int)((unsigned int)((int)((unsigned int)(v1075 + 68) >> 2)) >> 1);
    v1404[v1767] = v1768;
    int * v1406 = v1071->cache_dirty;
    v1406[v1767] = 0;
    int * v1408 = v1071->cache_age;
    v1408[v1767] = 1;
    int * v1410 = v1071->cache_age;
    int v1411 = v1410[v1767];
    int v1412 = v1410[v1699];
    int v1773 = v1412 + ((int)((unsigned int)(v1412 - v1411) >> 31));
    v1410[v1699] = v1773;
    int * v1414 = v1071->cache_age;
    int v1415 = v1414[v1700];
    int v1775 = v1415 + ((int)((unsigned int)(v1415 - v1411) >> 31));
    v1414[v1700] = v1775;
    int * v1417 = v1071->cache_age;
    v1417[v1767] = 0;
    v1420 = v1767;
  }
  int * v1421 = v1071->cache_vals;
  int v1778 = (v1420 * 2) + (((int)((unsigned int)(v1075 + 68) >> 2)) & 1);
  v1421[v1778] = v1076;
  int * v1423 = v1071->cache_tags;
  int v1424 = v1423[v1701];
  int v1425 = v1423[v1702];
  bool v1780 = !(((~(((v1424 ^ ((int)((unsigned int)((int)((unsigned int)(v1075 + 68) >> 2)) >> 1))) | (-(v1424 ^ ((int)((unsigned int)((int)((unsigned int)(v1075 + 68) >> 2)) >> 1))))) >> 31)) | (~(((v1425 ^ ((int)((unsigned int)((int)((unsigned int)(v1075 + 68) >> 2)) >> 1))) | (-(v1425 ^ ((int)((unsigned int)((int)((unsigned int)(v1075 + 68) >> 2)) >> 1))))) >> 31))) == 0);
  int v1479;
  if (v1780) {
    int * v1426 = v1071->cache_age;
    int v1782 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v1075 + 68) >> 2)) >> 1)) & 3) * 2)) + ((~(((v1425 ^ ((int)((unsigned int)((int)((unsigned int)(v1075 + 68) >> 2)) >> 1))) | (-(v1425 ^ ((int)((unsigned int)((int)((unsigned int)(v1075 + 68) >> 2)) >> 1))))) >> 31)) & 1);
    int v1427 = v1426[v1782];
    int v1428 = v1426[v1701];
    int v1783 = v1428 + ((int)((unsigned int)(v1428 - v1427) >> 31));
    v1426[v1701] = v1783;
    int * v1430 = v1071->cache_age;
    int v1431 = v1430[v1702];
    int v1785 = v1431 + ((int)((unsigned int)(v1431 - v1427) >> 31));
    v1430[v1702] = v1785;
    int * v1433 = v1071->cache_age;
    v1433[v1782] = 0;
    v1479 = v1782;
  } else {
    int * v1436 = v1071->cache_age;
    int v1788 = 4 + ((((int)((unsigned int)((int)((unsigned int)(v1075 + 68) >> 2)) >> 1)) & 3) * 2);
    int v1437 = v1436[v1788];
    int * v1438 = v1071->cache_tags;
    int v1439 = v1438[v1788];
    int v1440 = v1436[v1702];
    int v1441 = v1438[v1702];
    int * v1442 = v1071->cache_dirty;
    int v1791 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v1075 + 68) >> 2)) >> 1)) & 3) * 2)) + ((((v1437 + ((~(((v1439 ^ -1) | (-(v1439 ^ -1))) >> 31)) & 2)) - (v1440 + ((~(((v1441 ^ -1) | (-(v1441 ^ -1))) >> 31)) & 2))) >> 31) & 1);
    int v1443 = v1442[v1791];
    bool v1792 = !(v1443 == 0);
    if (v1792) {
      int * v1444 = v1071->cache_tags;
      int v1445 = v1444[v1791];
      int * v1446 = v1071->cache_vals;
      int v1795 = ((4 + ((((int)((unsigned int)((int)((unsigned int)(v1075 + 68) >> 2)) >> 1)) & 3) * 2)) + ((((v1437 + ((~(((v1439 ^ -1) | (-(v1439 ^ -1))) >> 31)) & 2)) - (v1440 + ((~(((v1441 ^ -1) | (-(v1441 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
      int v1447 = v1446[v1795];
      int v1796 = (((4 + ((((int)((unsigned int)((int)((unsigned int)(v1075 + 68) >> 2)) >> 1)) & 3) * 2)) + ((((v1437 + ((~(((v1439 ^ -1) | (-(v1439 ^ -1))) >> 31)) & 2)) - (v1440 + ((~(((v1441 ^ -1) | (-(v1441 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
      int v1448 = v1446[v1796];
      int * v1449 = v1071->mem;
      int v1798 = v1445 * 2;
      v1449[v1798] = v1447;
      int * v1451 = v1071->mem;
      int v1801 = (v1445 * 2) + 1;
      v1451[v1801] = v1448;
      ;
    } else {
      ;
    }
    int * v1456 = v1071->mem;
    int v1806 = ((int)((unsigned int)((int)((unsigned int)(v1075 + 68) >> 2)) >> 1)) * 2;
    int v1457 = v1456[v1806];
    int v1807 = (((int)((unsigned int)((int)((unsigned int)(v1075 + 68) >> 2)) >> 1)) * 2) + 1;
    int v1458 = v1456[v1807];
    int * v1459 = v1071->cache_vals;
    int v1809 = ((4 + ((((int)((unsigned int)((int)((unsigned int)(v1075 + 68) >> 2)) >> 1)) & 3) * 2)) + ((((v1437 + ((~(((v1439 ^ -1) | (-(v1439 ^ -1))) >> 31)) & 2)) - (v1440 + ((~(((v1441 ^ -1) | (-(v1441 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
    v1459[v1809] = v1457;
    int * v1461 = v1071->cache_vals;
    int v1812 = (((4 + ((((int)((unsigned int)((int)((unsigned int)(v1075 + 68) >> 2)) >> 1)) & 3) * 2)) + ((((v1437 + ((~(((v1439 ^ -1) | (-(v1439 ^ -1))) >> 31)) & 2)) - (v1440 + ((~(((v1441 ^ -1) | (-(v1441 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
    v1461[v1812] = v1458;
    int * v1463 = v1071->cache_tags;
    int v1815 = (int)((unsigned int)((int)((unsigned int)(v1075 + 68) >> 2)) >> 1);
    v1463[v1791] = v1815;
    int * v1465 = v1071->cache_dirty;
    v1465[v1791] = 0;
    int * v1467 = v1071->cache_age;
    v1467[v1791] = 1;
    int * v1469 = v1071->cache_age;
    int v1470 = v1469[v1791];
    int v1471 = v1469[v1701];
    int v1820 = v1471 + ((int)((unsigned int)(v1471 - v1470) >> 31));
    v1469[v1701] = v1820;
    int * v1473 = v1071->cache_age;
    int v1474 = v1473[v1702];
    int v1822 = v1474 + ((int)((unsigned int)(v1474 - v1470) >> 31));
    v1473[v1702] = v1822;
    int * v1476 = v1071->cache_age;
    v1476[v1791] = 0;
    v1479 = v1791;
  }
  int * v1480 = v1071->cache_vals;
  int v1825 = (v1479 * 2) + (((int)((unsigned int)(v1075 + 68) >> 2)) & 1);
  v1480[v1825] = v1076;
  int * v1482 = v1071->cache_dirty;
  v1482[v1479] = 1;
  bool v1829 = (((((int)((unsigned int)(v1094 + 4) >> 2)) & 3) == (((int)((unsigned int)(v1075 + 68) >> 2)) & 3)) & (!(((int)((unsigned int)(v1094 + 4) >> 2)) == ((int)((unsigned int)(v1075 + 68) >> 2))))) | (((((int)((unsigned int)(v1211 + 68) >> 2)) & 3) == (((int)((unsigned int)(v1075 + 68) >> 2)) & 3)) & (!(((int)((unsigned int)(v1211 + 68) >> 2)) == ((int)((unsigned int)(v1075 + 68) >> 2)))));
  struct StateT * v1502;
  if (v1829) {
    int v1484 = v1071->timer;
    int v1830 = v1484 + 15;
    v1071->timer = v1830;
    int * v1486 = v1071->saved_regs;
    int v1487 = v1486[10];
    int * v1488 = v1071->regs;
    v1488[10] = v1487;
    int * v1490 = v1071->saved_regs;
    int v1491 = v1490[11];
    int * v1492 = v1071->regs;
    v1492[11] = v1491;
    int * v1494 = v1071->saved_regs;
    int v1495 = v1494[12];
    int * v1496 = v1071->regs;
    v1496[12] = v1495;
    struct StateT * v1498 = slot_21(v1071);
    v1502 = v1498;
  } else {
    struct StateT * v1500 = slot_25(v1071);
    v1502 = v1500;
  }
  return v1502;
}

struct StateT * slot_13(struct StateT * v575) {
  int v576 = v575->timer;
  int v584 = v576 + 1;
  v575->timer = v584;
  int * v578 = v575->regs;
  int v579 = v578[11];
  int v580 = v578[10];
  int v588 = v579 + v580;
  v578[10] = v588;
  struct StateT * v582 = slot_14(v575);
  return v582;
}

struct StateT * slot_24(struct StateT * v2846) {
  int v2847 = v2846->timer;
  int v2957 = v2847 + 1;
  v2846->timer = v2957;
  int * v2849 = v2846->regs;
  int v2850 = v2849[11];
  int * v2851 = v2846->cache_tags;
  int v2961 = (((int)((unsigned int)((int)((unsigned int)(v2850 + 68) >> 2)) >> 1)) & 1) * 2;
  int v2852 = v2851[v2961];
  int v2962 = ((((int)((unsigned int)((int)((unsigned int)(v2850 + 68) >> 2)) >> 1)) & 1) * 2) + 1;
  int v2853 = v2851[v2962];
  int v2963 = 4 + ((((int)((unsigned int)((int)((unsigned int)(v2850 + 68) >> 2)) >> 1)) & 3) * 2);
  int v2854 = v2851[v2963];
  int v2964 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v2850 + 68) >> 2)) >> 1)) & 3) * 2)) + 1;
  int v2855 = v2851[v2964];
  int v2856 = v2846->timer;
  int v2965 = v2856 + ((100 ^ (((~(((v2854 ^ ((int)((unsigned int)((int)((unsigned int)(v2850 + 68) >> 2)) >> 1))) | (-(v2854 ^ ((int)((unsigned int)((int)((unsigned int)(v2850 + 68) >> 2)) >> 1))))) >> 31)) | (~(((v2855 ^ ((int)((unsigned int)((int)((unsigned int)(v2850 + 68) >> 2)) >> 1))) | (-(v2855 ^ ((int)((unsigned int)((int)((unsigned int)(v2850 + 68) >> 2)) >> 1))))) >> 31))) & 104)) ^ (((~(((v2852 ^ ((int)((unsigned int)((int)((unsigned int)(v2850 + 68) >> 2)) >> 1))) | (-(v2852 ^ ((int)((unsigned int)((int)((unsigned int)(v2850 + 68) >> 2)) >> 1))))) >> 31)) | (~(((v2853 ^ ((int)((unsigned int)((int)((unsigned int)(v2850 + 68) >> 2)) >> 1))) | (-(v2853 ^ ((int)((unsigned int)((int)((unsigned int)(v2850 + 68) >> 2)) >> 1))))) >> 31))) & (1 ^ (100 ^ (((~(((v2854 ^ ((int)((unsigned int)((int)((unsigned int)(v2850 + 68) >> 2)) >> 1))) | (-(v2854 ^ ((int)((unsigned int)((int)((unsigned int)(v2850 + 68) >> 2)) >> 1))))) >> 31)) | (~(((v2855 ^ ((int)((unsigned int)((int)((unsigned int)(v2850 + 68) >> 2)) >> 1))) | (-(v2855 ^ ((int)((unsigned int)((int)((unsigned int)(v2850 + 68) >> 2)) >> 1))))) >> 31))) & 104)))));
  v2846->timer = v2965;
  int * v2858 = v2846->cache_vals;
  bool v2966 = !(((~(((v2852 ^ ((int)((unsigned int)((int)((unsigned int)(v2850 + 68) >> 2)) >> 1))) | (-(v2852 ^ ((int)((unsigned int)((int)((unsigned int)(v2850 + 68) >> 2)) >> 1))))) >> 31)) | (~(((v2853 ^ ((int)((unsigned int)((int)((unsigned int)(v2850 + 68) >> 2)) >> 1))) | (-(v2853 ^ ((int)((unsigned int)((int)((unsigned int)(v2850 + 68) >> 2)) >> 1))))) >> 31))) == 0);
  int v2951;
  if (v2966) {
    int * v2859 = v2846->cache_age;
    int v2968 = ((((int)((unsigned int)((int)((unsigned int)(v2850 + 68) >> 2)) >> 1)) & 1) * 2) + ((~(((v2853 ^ ((int)((unsigned int)((int)((unsigned int)(v2850 + 68) >> 2)) >> 1))) | (-(v2853 ^ ((int)((unsigned int)((int)((unsigned int)(v2850 + 68) >> 2)) >> 1))))) >> 31)) & 1);
    int v2860 = v2859[v2968];
    int v2861 = v2859[v2961];
    int v2969 = v2861 + ((int)((unsigned int)(v2861 - v2860) >> 31));
    v2859[v2961] = v2969;
    int * v2863 = v2846->cache_age;
    int v2864 = v2863[v2962];
    int v2971 = v2864 + ((int)((unsigned int)(v2864 - v2860) >> 31));
    v2863[v2962] = v2971;
    int * v2866 = v2846->cache_age;
    v2866[v2968] = 0;
    v2951 = v2968;
  } else {
    int * v2869 = v2846->cache_age;
    int v2975 = (((int)((unsigned int)((int)((unsigned int)(v2850 + 68) >> 2)) >> 1)) & 1) * 2;
    int v2870 = v2869[v2975];
    int * v2871 = v2846->cache_tags;
    int v2872 = v2871[v2975];
    int v2873 = v2869[v2962];
    int v2874 = v2871[v2962];
    bool v2977 = !(((~(((v2854 ^ ((int)((unsigned int)((int)((unsigned int)(v2850 + 68) >> 2)) >> 1))) | (-(v2854 ^ ((int)((unsigned int)((int)((unsigned int)(v2850 + 68) >> 2)) >> 1))))) >> 31)) | (~(((v2855 ^ ((int)((unsigned int)((int)((unsigned int)(v2850 + 68) >> 2)) >> 1))) | (-(v2855 ^ ((int)((unsigned int)((int)((unsigned int)(v2850 + 68) >> 2)) >> 1))))) >> 31))) == 0);
    int v2928;
    if (v2977) {
      int * v2875 = v2846->cache_age;
      int v2979 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v2850 + 68) >> 2)) >> 1)) & 3) * 2)) + ((~(((v2855 ^ ((int)((unsigned int)((int)((unsigned int)(v2850 + 68) >> 2)) >> 1))) | (-(v2855 ^ ((int)((unsigned int)((int)((unsigned int)(v2850 + 68) >> 2)) >> 1))))) >> 31)) & 1);
      int v2876 = v2875[v2979];
      int v2877 = v2875[v2963];
      int v2980 = v2877 + ((int)((unsigned int)(v2877 - v2876) >> 31));
      v2875[v2963] = v2980;
      int * v2879 = v2846->cache_age;
      int v2880 = v2879[v2964];
      int v2982 = v2880 + ((int)((unsigned int)(v2880 - v2876) >> 31));
      v2879[v2964] = v2982;
      int * v2882 = v2846->cache_age;
      v2882[v2979] = 0;
      v2928 = v2979;
    } else {
      int * v2885 = v2846->cache_age;
      int v2986 = 4 + ((((int)((unsigned int)((int)((unsigned int)(v2850 + 68) >> 2)) >> 1)) & 3) * 2);
      int v2886 = v2885[v2986];
      int * v2887 = v2846->cache_tags;
      int v2888 = v2887[v2986];
      int v2889 = v2885[v2964];
      int v2890 = v2887[v2964];
      int * v2891 = v2846->cache_dirty;
      int v2989 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v2850 + 68) >> 2)) >> 1)) & 3) * 2)) + ((((v2886 + ((~(((v2888 ^ -1) | (-(v2888 ^ -1))) >> 31)) & 2)) - (v2889 + ((~(((v2890 ^ -1) | (-(v2890 ^ -1))) >> 31)) & 2))) >> 31) & 1);
      int v2892 = v2891[v2989];
      bool v2990 = !(v2892 == 0);
      if (v2990) {
        int * v2893 = v2846->cache_tags;
        int v2894 = v2893[v2989];
        int * v2895 = v2846->cache_vals;
        int v2993 = ((4 + ((((int)((unsigned int)((int)((unsigned int)(v2850 + 68) >> 2)) >> 1)) & 3) * 2)) + ((((v2886 + ((~(((v2888 ^ -1) | (-(v2888 ^ -1))) >> 31)) & 2)) - (v2889 + ((~(((v2890 ^ -1) | (-(v2890 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
        int v2896 = v2895[v2993];
        int v2994 = (((4 + ((((int)((unsigned int)((int)((unsigned int)(v2850 + 68) >> 2)) >> 1)) & 3) * 2)) + ((((v2886 + ((~(((v2888 ^ -1) | (-(v2888 ^ -1))) >> 31)) & 2)) - (v2889 + ((~(((v2890 ^ -1) | (-(v2890 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
        int v2897 = v2895[v2994];
        int * v2898 = v2846->mem;
        int v2996 = v2894 * 2;
        v2898[v2996] = v2896;
        int * v2900 = v2846->mem;
        int v2999 = (v2894 * 2) + 1;
        v2900[v2999] = v2897;
        ;
      } else {
        ;
      }
      int * v2905 = v2846->mem;
      int v3004 = ((int)((unsigned int)((int)((unsigned int)(v2850 + 68) >> 2)) >> 1)) * 2;
      int v2906 = v2905[v3004];
      int v3005 = (((int)((unsigned int)((int)((unsigned int)(v2850 + 68) >> 2)) >> 1)) * 2) + 1;
      int v2907 = v2905[v3005];
      int * v2908 = v2846->cache_vals;
      int v3007 = ((4 + ((((int)((unsigned int)((int)((unsigned int)(v2850 + 68) >> 2)) >> 1)) & 3) * 2)) + ((((v2886 + ((~(((v2888 ^ -1) | (-(v2888 ^ -1))) >> 31)) & 2)) - (v2889 + ((~(((v2890 ^ -1) | (-(v2890 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
      v2908[v3007] = v2906;
      int * v2910 = v2846->cache_vals;
      int v3010 = (((4 + ((((int)((unsigned int)((int)((unsigned int)(v2850 + 68) >> 2)) >> 1)) & 3) * 2)) + ((((v2886 + ((~(((v2888 ^ -1) | (-(v2888 ^ -1))) >> 31)) & 2)) - (v2889 + ((~(((v2890 ^ -1) | (-(v2890 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
      v2910[v3010] = v2907;
      int * v2912 = v2846->cache_tags;
      int v3013 = (int)((unsigned int)((int)((unsigned int)(v2850 + 68) >> 2)) >> 1);
      v2912[v2989] = v3013;
      int * v2914 = v2846->cache_dirty;
      v2914[v2989] = 0;
      int * v2916 = v2846->cache_age;
      v2916[v2989] = 1;
      int * v2918 = v2846->cache_age;
      int v2919 = v2918[v2989];
      int v2920 = v2918[v2963];
      int v3019 = v2920 + ((int)((unsigned int)(v2920 - v2919) >> 31));
      v2918[v2963] = v3019;
      int * v2922 = v2846->cache_age;
      int v2923 = v2922[v2964];
      int v3021 = v2923 + ((int)((unsigned int)(v2923 - v2919) >> 31));
      v2922[v2964] = v3021;
      int * v2925 = v2846->cache_age;
      v2925[v2989] = 0;
      v2928 = v2989;
    }
    int * v2929 = v2846->cache_vals;
    int v3024 = v2928 * 2;
    int v2930 = v2929[v3024];
    int v3025 = (v2928 * 2) + 1;
    int v2931 = v2929[v3025];
    int v3026 = (((((int)((unsigned int)((int)((unsigned int)(v2850 + 68) >> 2)) >> 1)) & 1) * 2) + ((((v2870 + ((~(((v2872 ^ -1) | (-(v2872 ^ -1))) >> 31)) & 2)) - (v2873 + ((~(((v2874 ^ -1) | (-(v2874 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
    v2929[v3026] = v2930;
    int * v2933 = v2846->cache_vals;
    int v3029 = ((((((int)((unsigned int)((int)((unsigned int)(v2850 + 68) >> 2)) >> 1)) & 1) * 2) + ((((v2870 + ((~(((v2872 ^ -1) | (-(v2872 ^ -1))) >> 31)) & 2)) - (v2873 + ((~(((v2874 ^ -1) | (-(v2874 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
    v2933[v3029] = v2931;
    int * v2935 = v2846->cache_tags;
    int v3032 = ((((int)((unsigned int)((int)((unsigned int)(v2850 + 68) >> 2)) >> 1)) & 1) * 2) + ((((v2870 + ((~(((v2872 ^ -1) | (-(v2872 ^ -1))) >> 31)) & 2)) - (v2873 + ((~(((v2874 ^ -1) | (-(v2874 ^ -1))) >> 31)) & 2))) >> 31) & 1);
    int v3033 = (int)((unsigned int)((int)((unsigned int)(v2850 + 68) >> 2)) >> 1);
    v2935[v3032] = v3033;
    int * v2937 = v2846->cache_dirty;
    v2937[v3032] = 0;
    int * v2939 = v2846->cache_age;
    v2939[v3032] = 1;
    int * v2941 = v2846->cache_age;
    int v2942 = v2941[v3032];
    int v2943 = v2941[v2961];
    int v3039 = v2943 + ((int)((unsigned int)(v2943 - v2942) >> 31));
    v2941[v2961] = v3039;
    int * v2945 = v2846->cache_age;
    int v2946 = v2945[v2962];
    int v3041 = v2946 + ((int)((unsigned int)(v2946 - v2942) >> 31));
    v2945[v2962] = v3041;
    int * v2948 = v2846->cache_age;
    v2948[v3032] = 0;
    v2951 = v3032;
  }
  int v3044 = (v2951 * 2) + (((int)((unsigned int)(v2850 + 68) >> 2)) & 1);
  int v2952 = v2858[v3044];
  int * v2953 = v2846->regs;
  v2953[12] = v2952;
  struct StateT * v2955 = slot_25(v2846);
  return v2955;
}

struct StateT * slot_0(struct StateT * v2) {
  int v3 = v2->timer;
  int v9 = v3 + 1;
  v2->timer = v9;
  int * v5 = v2->regs;
  v5[11] = 0;
  struct StateT * v7 = slot_1(v2);
  return v7;
}

struct StateT * slot_14(struct StateT * v591) {
  int v592 = v591->timer;
  int v702 = v592 + 1;
  v591->timer = v702;
  int * v594 = v591->regs;
  int v595 = v594[10];
  int * v596 = v591->cache_tags;
  int v706 = (((int)((unsigned int)((int)((unsigned int)v595 >> 2)) >> 1)) & 1) * 2;
  int v597 = v596[v706];
  int v707 = ((((int)((unsigned int)((int)((unsigned int)v595 >> 2)) >> 1)) & 1) * 2) + 1;
  int v598 = v596[v707];
  int v708 = 4 + ((((int)((unsigned int)((int)((unsigned int)v595 >> 2)) >> 1)) & 3) * 2);
  int v599 = v596[v708];
  int v709 = (4 + ((((int)((unsigned int)((int)((unsigned int)v595 >> 2)) >> 1)) & 3) * 2)) + 1;
  int v600 = v596[v709];
  int v601 = v591->timer;
  int v710 = v601 + ((100 ^ (((~(((v599 ^ ((int)((unsigned int)((int)((unsigned int)v595 >> 2)) >> 1))) | (-(v599 ^ ((int)((unsigned int)((int)((unsigned int)v595 >> 2)) >> 1))))) >> 31)) | (~(((v600 ^ ((int)((unsigned int)((int)((unsigned int)v595 >> 2)) >> 1))) | (-(v600 ^ ((int)((unsigned int)((int)((unsigned int)v595 >> 2)) >> 1))))) >> 31))) & 104)) ^ (((~(((v597 ^ ((int)((unsigned int)((int)((unsigned int)v595 >> 2)) >> 1))) | (-(v597 ^ ((int)((unsigned int)((int)((unsigned int)v595 >> 2)) >> 1))))) >> 31)) | (~(((v598 ^ ((int)((unsigned int)((int)((unsigned int)v595 >> 2)) >> 1))) | (-(v598 ^ ((int)((unsigned int)((int)((unsigned int)v595 >> 2)) >> 1))))) >> 31))) & (1 ^ (100 ^ (((~(((v599 ^ ((int)((unsigned int)((int)((unsigned int)v595 >> 2)) >> 1))) | (-(v599 ^ ((int)((unsigned int)((int)((unsigned int)v595 >> 2)) >> 1))))) >> 31)) | (~(((v600 ^ ((int)((unsigned int)((int)((unsigned int)v595 >> 2)) >> 1))) | (-(v600 ^ ((int)((unsigned int)((int)((unsigned int)v595 >> 2)) >> 1))))) >> 31))) & 104)))));
  v591->timer = v710;
  int * v603 = v591->cache_vals;
  bool v711 = !(((~(((v597 ^ ((int)((unsigned int)((int)((unsigned int)v595 >> 2)) >> 1))) | (-(v597 ^ ((int)((unsigned int)((int)((unsigned int)v595 >> 2)) >> 1))))) >> 31)) | (~(((v598 ^ ((int)((unsigned int)((int)((unsigned int)v595 >> 2)) >> 1))) | (-(v598 ^ ((int)((unsigned int)((int)((unsigned int)v595 >> 2)) >> 1))))) >> 31))) == 0);
  int v696;
  if (v711) {
    int * v604 = v591->cache_age;
    int v713 = ((((int)((unsigned int)((int)((unsigned int)v595 >> 2)) >> 1)) & 1) * 2) + ((~(((v598 ^ ((int)((unsigned int)((int)((unsigned int)v595 >> 2)) >> 1))) | (-(v598 ^ ((int)((unsigned int)((int)((unsigned int)v595 >> 2)) >> 1))))) >> 31)) & 1);
    int v605 = v604[v713];
    int v606 = v604[v706];
    int v714 = v606 + ((int)((unsigned int)(v606 - v605) >> 31));
    v604[v706] = v714;
    int * v608 = v591->cache_age;
    int v609 = v608[v707];
    int v716 = v609 + ((int)((unsigned int)(v609 - v605) >> 31));
    v608[v707] = v716;
    int * v611 = v591->cache_age;
    v611[v713] = 0;
    v696 = v713;
  } else {
    int * v614 = v591->cache_age;
    int v720 = (((int)((unsigned int)((int)((unsigned int)v595 >> 2)) >> 1)) & 1) * 2;
    int v615 = v614[v720];
    int * v616 = v591->cache_tags;
    int v617 = v616[v720];
    int v618 = v614[v707];
    int v619 = v616[v707];
    bool v722 = !(((~(((v599 ^ ((int)((unsigned int)((int)((unsigned int)v595 >> 2)) >> 1))) | (-(v599 ^ ((int)((unsigned int)((int)((unsigned int)v595 >> 2)) >> 1))))) >> 31)) | (~(((v600 ^ ((int)((unsigned int)((int)((unsigned int)v595 >> 2)) >> 1))) | (-(v600 ^ ((int)((unsigned int)((int)((unsigned int)v595 >> 2)) >> 1))))) >> 31))) == 0);
    int v673;
    if (v722) {
      int * v620 = v591->cache_age;
      int v724 = (4 + ((((int)((unsigned int)((int)((unsigned int)v595 >> 2)) >> 1)) & 3) * 2)) + ((~(((v600 ^ ((int)((unsigned int)((int)((unsigned int)v595 >> 2)) >> 1))) | (-(v600 ^ ((int)((unsigned int)((int)((unsigned int)v595 >> 2)) >> 1))))) >> 31)) & 1);
      int v621 = v620[v724];
      int v622 = v620[v708];
      int v725 = v622 + ((int)((unsigned int)(v622 - v621) >> 31));
      v620[v708] = v725;
      int * v624 = v591->cache_age;
      int v625 = v624[v709];
      int v727 = v625 + ((int)((unsigned int)(v625 - v621) >> 31));
      v624[v709] = v727;
      int * v627 = v591->cache_age;
      v627[v724] = 0;
      v673 = v724;
    } else {
      int * v630 = v591->cache_age;
      int v731 = 4 + ((((int)((unsigned int)((int)((unsigned int)v595 >> 2)) >> 1)) & 3) * 2);
      int v631 = v630[v731];
      int * v632 = v591->cache_tags;
      int v633 = v632[v731];
      int v634 = v630[v709];
      int v635 = v632[v709];
      int * v636 = v591->cache_dirty;
      int v734 = (4 + ((((int)((unsigned int)((int)((unsigned int)v595 >> 2)) >> 1)) & 3) * 2)) + ((((v631 + ((~(((v633 ^ -1) | (-(v633 ^ -1))) >> 31)) & 2)) - (v634 + ((~(((v635 ^ -1) | (-(v635 ^ -1))) >> 31)) & 2))) >> 31) & 1);
      int v637 = v636[v734];
      bool v735 = !(v637 == 0);
      if (v735) {
        int * v638 = v591->cache_tags;
        int v639 = v638[v734];
        int * v640 = v591->cache_vals;
        int v738 = ((4 + ((((int)((unsigned int)((int)((unsigned int)v595 >> 2)) >> 1)) & 3) * 2)) + ((((v631 + ((~(((v633 ^ -1) | (-(v633 ^ -1))) >> 31)) & 2)) - (v634 + ((~(((v635 ^ -1) | (-(v635 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
        int v641 = v640[v738];
        int v739 = (((4 + ((((int)((unsigned int)((int)((unsigned int)v595 >> 2)) >> 1)) & 3) * 2)) + ((((v631 + ((~(((v633 ^ -1) | (-(v633 ^ -1))) >> 31)) & 2)) - (v634 + ((~(((v635 ^ -1) | (-(v635 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
        int v642 = v640[v739];
        int * v643 = v591->mem;
        int v741 = v639 * 2;
        v643[v741] = v641;
        int * v645 = v591->mem;
        int v744 = (v639 * 2) + 1;
        v645[v744] = v642;
        ;
      } else {
        ;
      }
      int * v650 = v591->mem;
      int v749 = ((int)((unsigned int)((int)((unsigned int)v595 >> 2)) >> 1)) * 2;
      int v651 = v650[v749];
      int v750 = (((int)((unsigned int)((int)((unsigned int)v595 >> 2)) >> 1)) * 2) + 1;
      int v652 = v650[v750];
      int * v653 = v591->cache_vals;
      int v752 = ((4 + ((((int)((unsigned int)((int)((unsigned int)v595 >> 2)) >> 1)) & 3) * 2)) + ((((v631 + ((~(((v633 ^ -1) | (-(v633 ^ -1))) >> 31)) & 2)) - (v634 + ((~(((v635 ^ -1) | (-(v635 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
      v653[v752] = v651;
      int * v655 = v591->cache_vals;
      int v755 = (((4 + ((((int)((unsigned int)((int)((unsigned int)v595 >> 2)) >> 1)) & 3) * 2)) + ((((v631 + ((~(((v633 ^ -1) | (-(v633 ^ -1))) >> 31)) & 2)) - (v634 + ((~(((v635 ^ -1) | (-(v635 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
      v655[v755] = v652;
      int * v657 = v591->cache_tags;
      int v758 = (int)((unsigned int)((int)((unsigned int)v595 >> 2)) >> 1);
      v657[v734] = v758;
      int * v659 = v591->cache_dirty;
      v659[v734] = 0;
      int * v661 = v591->cache_age;
      v661[v734] = 1;
      int * v663 = v591->cache_age;
      int v664 = v663[v734];
      int v665 = v663[v708];
      int v764 = v665 + ((int)((unsigned int)(v665 - v664) >> 31));
      v663[v708] = v764;
      int * v667 = v591->cache_age;
      int v668 = v667[v709];
      int v766 = v668 + ((int)((unsigned int)(v668 - v664) >> 31));
      v667[v709] = v766;
      int * v670 = v591->cache_age;
      v670[v734] = 0;
      v673 = v734;
    }
    int * v674 = v591->cache_vals;
    int v769 = v673 * 2;
    int v675 = v674[v769];
    int v770 = (v673 * 2) + 1;
    int v676 = v674[v770];
    int v771 = (((((int)((unsigned int)((int)((unsigned int)v595 >> 2)) >> 1)) & 1) * 2) + ((((v615 + ((~(((v617 ^ -1) | (-(v617 ^ -1))) >> 31)) & 2)) - (v618 + ((~(((v619 ^ -1) | (-(v619 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
    v674[v771] = v675;
    int * v678 = v591->cache_vals;
    int v774 = ((((((int)((unsigned int)((int)((unsigned int)v595 >> 2)) >> 1)) & 1) * 2) + ((((v615 + ((~(((v617 ^ -1) | (-(v617 ^ -1))) >> 31)) & 2)) - (v618 + ((~(((v619 ^ -1) | (-(v619 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
    v678[v774] = v676;
    int * v680 = v591->cache_tags;
    int v777 = ((((int)((unsigned int)((int)((unsigned int)v595 >> 2)) >> 1)) & 1) * 2) + ((((v615 + ((~(((v617 ^ -1) | (-(v617 ^ -1))) >> 31)) & 2)) - (v618 + ((~(((v619 ^ -1) | (-(v619 ^ -1))) >> 31)) & 2))) >> 31) & 1);
    int v778 = (int)((unsigned int)((int)((unsigned int)v595 >> 2)) >> 1);
    v680[v777] = v778;
    int * v682 = v591->cache_dirty;
    v682[v777] = 0;
    int * v684 = v591->cache_age;
    v684[v777] = 1;
    int * v686 = v591->cache_age;
    int v687 = v686[v777];
    int v688 = v686[v706];
    int v784 = v688 + ((int)((unsigned int)(v688 - v687) >> 31));
    v686[v706] = v784;
    int * v690 = v591->cache_age;
    int v691 = v690[v707];
    int v786 = v691 + ((int)((unsigned int)(v691 - v687) >> 31));
    v690[v707] = v786;
    int * v693 = v591->cache_age;
    v693[v777] = 0;
    v696 = v777;
  }
  int v789 = (v696 * 2) + (((int)((unsigned int)v595 >> 2)) & 1);
  int v697 = v603[v789];
  int * v698 = v591->regs;
  v698[10] = v697;
  struct StateT * v700 = slot_15(v591);
  return v700;
}

struct StateT * slot_32(struct StateT * v3050) {
  int v3051 = v3050->timer;
  int v3221 = v3051 + 1;
  v3050->timer = v3221;
  int * v3053 = v3050->regs;
  int v3054 = v3053[11];
  int v3055 = v3053[10];
  int * v3056 = v3050->cache_tags;
  int v3226 = (((int)((unsigned int)((int)((unsigned int)(v3054 + 68) >> 2)) >> 1)) & 1) * 2;
  int v3057 = v3056[v3226];
  int v3227 = ((((int)((unsigned int)((int)((unsigned int)(v3054 + 68) >> 2)) >> 1)) & 1) * 2) + 1;
  int v3058 = v3056[v3227];
  int v3228 = 4 + ((((int)((unsigned int)((int)((unsigned int)(v3054 + 68) >> 2)) >> 1)) & 3) * 2);
  int v3059 = v3056[v3228];
  int v3229 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v3054 + 68) >> 2)) >> 1)) & 3) * 2)) + 1;
  int v3060 = v3056[v3229];
  int v3061 = v3050->timer;
  int v3230 = v3061 + ((100 ^ (((~(((v3059 ^ ((int)((unsigned int)((int)((unsigned int)(v3054 + 68) >> 2)) >> 1))) | (-(v3059 ^ ((int)((unsigned int)((int)((unsigned int)(v3054 + 68) >> 2)) >> 1))))) >> 31)) | (~(((v3060 ^ ((int)((unsigned int)((int)((unsigned int)(v3054 + 68) >> 2)) >> 1))) | (-(v3060 ^ ((int)((unsigned int)((int)((unsigned int)(v3054 + 68) >> 2)) >> 1))))) >> 31))) & 104)) ^ (((~(((v3057 ^ ((int)((unsigned int)((int)((unsigned int)(v3054 + 68) >> 2)) >> 1))) | (-(v3057 ^ ((int)((unsigned int)((int)((unsigned int)(v3054 + 68) >> 2)) >> 1))))) >> 31)) | (~(((v3058 ^ ((int)((unsigned int)((int)((unsigned int)(v3054 + 68) >> 2)) >> 1))) | (-(v3058 ^ ((int)((unsigned int)((int)((unsigned int)(v3054 + 68) >> 2)) >> 1))))) >> 31))) & (1 ^ (100 ^ (((~(((v3059 ^ ((int)((unsigned int)((int)((unsigned int)(v3054 + 68) >> 2)) >> 1))) | (-(v3059 ^ ((int)((unsigned int)((int)((unsigned int)(v3054 + 68) >> 2)) >> 1))))) >> 31)) | (~(((v3060 ^ ((int)((unsigned int)((int)((unsigned int)(v3054 + 68) >> 2)) >> 1))) | (-(v3060 ^ ((int)((unsigned int)((int)((unsigned int)(v3054 + 68) >> 2)) >> 1))))) >> 31))) & 104)))));
  v3050->timer = v3230;
  bool v3231 = !(((~(((v3057 ^ ((int)((unsigned int)((int)((unsigned int)(v3054 + 68) >> 2)) >> 1))) | (-(v3057 ^ ((int)((unsigned int)((int)((unsigned int)(v3054 + 68) >> 2)) >> 1))))) >> 31)) | (~(((v3058 ^ ((int)((unsigned int)((int)((unsigned int)(v3054 + 68) >> 2)) >> 1))) | (-(v3058 ^ ((int)((unsigned int)((int)((unsigned int)(v3054 + 68) >> 2)) >> 1))))) >> 31))) == 0);
  int v3155;
  if (v3231) {
    int * v3063 = v3050->cache_age;
    int v3233 = ((((int)((unsigned int)((int)((unsigned int)(v3054 + 68) >> 2)) >> 1)) & 1) * 2) + ((~(((v3058 ^ ((int)((unsigned int)((int)((unsigned int)(v3054 + 68) >> 2)) >> 1))) | (-(v3058 ^ ((int)((unsigned int)((int)((unsigned int)(v3054 + 68) >> 2)) >> 1))))) >> 31)) & 1);
    int v3064 = v3063[v3233];
    int v3065 = v3063[v3226];
    int v3234 = v3065 + ((int)((unsigned int)(v3065 - v3064) >> 31));
    v3063[v3226] = v3234;
    int * v3067 = v3050->cache_age;
    int v3068 = v3067[v3227];
    int v3236 = v3068 + ((int)((unsigned int)(v3068 - v3064) >> 31));
    v3067[v3227] = v3236;
    int * v3070 = v3050->cache_age;
    v3070[v3233] = 0;
    v3155 = v3233;
  } else {
    int * v3073 = v3050->cache_age;
    int v3240 = (((int)((unsigned int)((int)((unsigned int)(v3054 + 68) >> 2)) >> 1)) & 1) * 2;
    int v3074 = v3073[v3240];
    int * v3075 = v3050->cache_tags;
    int v3076 = v3075[v3240];
    int v3077 = v3073[v3227];
    int v3078 = v3075[v3227];
    bool v3242 = !(((~(((v3059 ^ ((int)((unsigned int)((int)((unsigned int)(v3054 + 68) >> 2)) >> 1))) | (-(v3059 ^ ((int)((unsigned int)((int)((unsigned int)(v3054 + 68) >> 2)) >> 1))))) >> 31)) | (~(((v3060 ^ ((int)((unsigned int)((int)((unsigned int)(v3054 + 68) >> 2)) >> 1))) | (-(v3060 ^ ((int)((unsigned int)((int)((unsigned int)(v3054 + 68) >> 2)) >> 1))))) >> 31))) == 0);
    int v3132;
    if (v3242) {
      int * v3079 = v3050->cache_age;
      int v3244 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v3054 + 68) >> 2)) >> 1)) & 3) * 2)) + ((~(((v3060 ^ ((int)((unsigned int)((int)((unsigned int)(v3054 + 68) >> 2)) >> 1))) | (-(v3060 ^ ((int)((unsigned int)((int)((unsigned int)(v3054 + 68) >> 2)) >> 1))))) >> 31)) & 1);
      int v3080 = v3079[v3244];
      int v3081 = v3079[v3228];
      int v3245 = v3081 + ((int)((unsigned int)(v3081 - v3080) >> 31));
      v3079[v3228] = v3245;
      int * v3083 = v3050->cache_age;
      int v3084 = v3083[v3229];
      int v3247 = v3084 + ((int)((unsigned int)(v3084 - v3080) >> 31));
      v3083[v3229] = v3247;
      int * v3086 = v3050->cache_age;
      v3086[v3244] = 0;
      v3132 = v3244;
    } else {
      int * v3089 = v3050->cache_age;
      int v3251 = 4 + ((((int)((unsigned int)((int)((unsigned int)(v3054 + 68) >> 2)) >> 1)) & 3) * 2);
      int v3090 = v3089[v3251];
      int * v3091 = v3050->cache_tags;
      int v3092 = v3091[v3251];
      int v3093 = v3089[v3229];
      int v3094 = v3091[v3229];
      int * v3095 = v3050->cache_dirty;
      int v3254 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v3054 + 68) >> 2)) >> 1)) & 3) * 2)) + ((((v3090 + ((~(((v3092 ^ -1) | (-(v3092 ^ -1))) >> 31)) & 2)) - (v3093 + ((~(((v3094 ^ -1) | (-(v3094 ^ -1))) >> 31)) & 2))) >> 31) & 1);
      int v3096 = v3095[v3254];
      bool v3255 = !(v3096 == 0);
      if (v3255) {
        int * v3097 = v3050->cache_tags;
        int v3098 = v3097[v3254];
        int * v3099 = v3050->cache_vals;
        int v3258 = ((4 + ((((int)((unsigned int)((int)((unsigned int)(v3054 + 68) >> 2)) >> 1)) & 3) * 2)) + ((((v3090 + ((~(((v3092 ^ -1) | (-(v3092 ^ -1))) >> 31)) & 2)) - (v3093 + ((~(((v3094 ^ -1) | (-(v3094 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
        int v3100 = v3099[v3258];
        int v3259 = (((4 + ((((int)((unsigned int)((int)((unsigned int)(v3054 + 68) >> 2)) >> 1)) & 3) * 2)) + ((((v3090 + ((~(((v3092 ^ -1) | (-(v3092 ^ -1))) >> 31)) & 2)) - (v3093 + ((~(((v3094 ^ -1) | (-(v3094 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
        int v3101 = v3099[v3259];
        int * v3102 = v3050->mem;
        int v3261 = v3098 * 2;
        v3102[v3261] = v3100;
        int * v3104 = v3050->mem;
        int v3264 = (v3098 * 2) + 1;
        v3104[v3264] = v3101;
        ;
      } else {
        ;
      }
      int * v3109 = v3050->mem;
      int v3269 = ((int)((unsigned int)((int)((unsigned int)(v3054 + 68) >> 2)) >> 1)) * 2;
      int v3110 = v3109[v3269];
      int v3270 = (((int)((unsigned int)((int)((unsigned int)(v3054 + 68) >> 2)) >> 1)) * 2) + 1;
      int v3111 = v3109[v3270];
      int * v3112 = v3050->cache_vals;
      int v3272 = ((4 + ((((int)((unsigned int)((int)((unsigned int)(v3054 + 68) >> 2)) >> 1)) & 3) * 2)) + ((((v3090 + ((~(((v3092 ^ -1) | (-(v3092 ^ -1))) >> 31)) & 2)) - (v3093 + ((~(((v3094 ^ -1) | (-(v3094 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
      v3112[v3272] = v3110;
      int * v3114 = v3050->cache_vals;
      int v3275 = (((4 + ((((int)((unsigned int)((int)((unsigned int)(v3054 + 68) >> 2)) >> 1)) & 3) * 2)) + ((((v3090 + ((~(((v3092 ^ -1) | (-(v3092 ^ -1))) >> 31)) & 2)) - (v3093 + ((~(((v3094 ^ -1) | (-(v3094 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
      v3114[v3275] = v3111;
      int * v3116 = v3050->cache_tags;
      int v3278 = (int)((unsigned int)((int)((unsigned int)(v3054 + 68) >> 2)) >> 1);
      v3116[v3254] = v3278;
      int * v3118 = v3050->cache_dirty;
      v3118[v3254] = 0;
      int * v3120 = v3050->cache_age;
      v3120[v3254] = 1;
      int * v3122 = v3050->cache_age;
      int v3123 = v3122[v3254];
      int v3124 = v3122[v3228];
      int v3284 = v3124 + ((int)((unsigned int)(v3124 - v3123) >> 31));
      v3122[v3228] = v3284;
      int * v3126 = v3050->cache_age;
      int v3127 = v3126[v3229];
      int v3286 = v3127 + ((int)((unsigned int)(v3127 - v3123) >> 31));
      v3126[v3229] = v3286;
      int * v3129 = v3050->cache_age;
      v3129[v3254] = 0;
      v3132 = v3254;
    }
    int * v3133 = v3050->cache_vals;
    int v3289 = v3132 * 2;
    int v3134 = v3133[v3289];
    int v3290 = (v3132 * 2) + 1;
    int v3135 = v3133[v3290];
    int v3291 = (((((int)((unsigned int)((int)((unsigned int)(v3054 + 68) >> 2)) >> 1)) & 1) * 2) + ((((v3074 + ((~(((v3076 ^ -1) | (-(v3076 ^ -1))) >> 31)) & 2)) - (v3077 + ((~(((v3078 ^ -1) | (-(v3078 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
    v3133[v3291] = v3134;
    int * v3137 = v3050->cache_vals;
    int v3294 = ((((((int)((unsigned int)((int)((unsigned int)(v3054 + 68) >> 2)) >> 1)) & 1) * 2) + ((((v3074 + ((~(((v3076 ^ -1) | (-(v3076 ^ -1))) >> 31)) & 2)) - (v3077 + ((~(((v3078 ^ -1) | (-(v3078 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
    v3137[v3294] = v3135;
    int * v3139 = v3050->cache_tags;
    int v3297 = ((((int)((unsigned int)((int)((unsigned int)(v3054 + 68) >> 2)) >> 1)) & 1) * 2) + ((((v3074 + ((~(((v3076 ^ -1) | (-(v3076 ^ -1))) >> 31)) & 2)) - (v3077 + ((~(((v3078 ^ -1) | (-(v3078 ^ -1))) >> 31)) & 2))) >> 31) & 1);
    int v3298 = (int)((unsigned int)((int)((unsigned int)(v3054 + 68) >> 2)) >> 1);
    v3139[v3297] = v3298;
    int * v3141 = v3050->cache_dirty;
    v3141[v3297] = 0;
    int * v3143 = v3050->cache_age;
    v3143[v3297] = 1;
    int * v3145 = v3050->cache_age;
    int v3146 = v3145[v3297];
    int v3147 = v3145[v3226];
    int v3304 = v3147 + ((int)((unsigned int)(v3147 - v3146) >> 31));
    v3145[v3226] = v3304;
    int * v3149 = v3050->cache_age;
    int v3150 = v3149[v3227];
    int v3306 = v3150 + ((int)((unsigned int)(v3150 - v3146) >> 31));
    v3149[v3227] = v3306;
    int * v3152 = v3050->cache_age;
    v3152[v3297] = 0;
    v3155 = v3297;
  }
  int * v3156 = v3050->cache_vals;
  int v3309 = (v3155 * 2) + (((int)((unsigned int)(v3054 + 68) >> 2)) & 1);
  v3156[v3309] = v3055;
  int * v3158 = v3050->cache_tags;
  int v3159 = v3158[v3228];
  int v3160 = v3158[v3229];
  bool v3312 = !(((~(((v3159 ^ ((int)((unsigned int)((int)((unsigned int)(v3054 + 68) >> 2)) >> 1))) | (-(v3159 ^ ((int)((unsigned int)((int)((unsigned int)(v3054 + 68) >> 2)) >> 1))))) >> 31)) | (~(((v3160 ^ ((int)((unsigned int)((int)((unsigned int)(v3054 + 68) >> 2)) >> 1))) | (-(v3160 ^ ((int)((unsigned int)((int)((unsigned int)(v3054 + 68) >> 2)) >> 1))))) >> 31))) == 0);
  int v3214;
  if (v3312) {
    int * v3161 = v3050->cache_age;
    int v3314 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v3054 + 68) >> 2)) >> 1)) & 3) * 2)) + ((~(((v3160 ^ ((int)((unsigned int)((int)((unsigned int)(v3054 + 68) >> 2)) >> 1))) | (-(v3160 ^ ((int)((unsigned int)((int)((unsigned int)(v3054 + 68) >> 2)) >> 1))))) >> 31)) & 1);
    int v3162 = v3161[v3314];
    int v3163 = v3161[v3228];
    int v3315 = v3163 + ((int)((unsigned int)(v3163 - v3162) >> 31));
    v3161[v3228] = v3315;
    int * v3165 = v3050->cache_age;
    int v3166 = v3165[v3229];
    int v3317 = v3166 + ((int)((unsigned int)(v3166 - v3162) >> 31));
    v3165[v3229] = v3317;
    int * v3168 = v3050->cache_age;
    v3168[v3314] = 0;
    v3214 = v3314;
  } else {
    int * v3171 = v3050->cache_age;
    int v3321 = 4 + ((((int)((unsigned int)((int)((unsigned int)(v3054 + 68) >> 2)) >> 1)) & 3) * 2);
    int v3172 = v3171[v3321];
    int * v3173 = v3050->cache_tags;
    int v3174 = v3173[v3321];
    int v3175 = v3171[v3229];
    int v3176 = v3173[v3229];
    int * v3177 = v3050->cache_dirty;
    int v3324 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v3054 + 68) >> 2)) >> 1)) & 3) * 2)) + ((((v3172 + ((~(((v3174 ^ -1) | (-(v3174 ^ -1))) >> 31)) & 2)) - (v3175 + ((~(((v3176 ^ -1) | (-(v3176 ^ -1))) >> 31)) & 2))) >> 31) & 1);
    int v3178 = v3177[v3324];
    bool v3325 = !(v3178 == 0);
    if (v3325) {
      int * v3179 = v3050->cache_tags;
      int v3180 = v3179[v3324];
      int * v3181 = v3050->cache_vals;
      int v3328 = ((4 + ((((int)((unsigned int)((int)((unsigned int)(v3054 + 68) >> 2)) >> 1)) & 3) * 2)) + ((((v3172 + ((~(((v3174 ^ -1) | (-(v3174 ^ -1))) >> 31)) & 2)) - (v3175 + ((~(((v3176 ^ -1) | (-(v3176 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
      int v3182 = v3181[v3328];
      int v3329 = (((4 + ((((int)((unsigned int)((int)((unsigned int)(v3054 + 68) >> 2)) >> 1)) & 3) * 2)) + ((((v3172 + ((~(((v3174 ^ -1) | (-(v3174 ^ -1))) >> 31)) & 2)) - (v3175 + ((~(((v3176 ^ -1) | (-(v3176 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
      int v3183 = v3181[v3329];
      int * v3184 = v3050->mem;
      int v3331 = v3180 * 2;
      v3184[v3331] = v3182;
      int * v3186 = v3050->mem;
      int v3334 = (v3180 * 2) + 1;
      v3186[v3334] = v3183;
      ;
    } else {
      ;
    }
    int * v3191 = v3050->mem;
    int v3339 = ((int)((unsigned int)((int)((unsigned int)(v3054 + 68) >> 2)) >> 1)) * 2;
    int v3192 = v3191[v3339];
    int v3340 = (((int)((unsigned int)((int)((unsigned int)(v3054 + 68) >> 2)) >> 1)) * 2) + 1;
    int v3193 = v3191[v3340];
    int * v3194 = v3050->cache_vals;
    int v3342 = ((4 + ((((int)((unsigned int)((int)((unsigned int)(v3054 + 68) >> 2)) >> 1)) & 3) * 2)) + ((((v3172 + ((~(((v3174 ^ -1) | (-(v3174 ^ -1))) >> 31)) & 2)) - (v3175 + ((~(((v3176 ^ -1) | (-(v3176 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
    v3194[v3342] = v3192;
    int * v3196 = v3050->cache_vals;
    int v3345 = (((4 + ((((int)((unsigned int)((int)((unsigned int)(v3054 + 68) >> 2)) >> 1)) & 3) * 2)) + ((((v3172 + ((~(((v3174 ^ -1) | (-(v3174 ^ -1))) >> 31)) & 2)) - (v3175 + ((~(((v3176 ^ -1) | (-(v3176 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
    v3196[v3345] = v3193;
    int * v3198 = v3050->cache_tags;
    int v3348 = (int)((unsigned int)((int)((unsigned int)(v3054 + 68) >> 2)) >> 1);
    v3198[v3324] = v3348;
    int * v3200 = v3050->cache_dirty;
    v3200[v3324] = 0;
    int * v3202 = v3050->cache_age;
    v3202[v3324] = 1;
    int * v3204 = v3050->cache_age;
    int v3205 = v3204[v3324];
    int v3206 = v3204[v3228];
    int v3354 = v3206 + ((int)((unsigned int)(v3206 - v3205) >> 31));
    v3204[v3228] = v3354;
    int * v3208 = v3050->cache_age;
    int v3209 = v3208[v3229];
    int v3356 = v3209 + ((int)((unsigned int)(v3209 - v3205) >> 31));
    v3208[v3229] = v3356;
    int * v3211 = v3050->cache_age;
    v3211[v3324] = 0;
    v3214 = v3324;
  }
  int * v3215 = v3050->cache_vals;
  int v3359 = (v3214 * 2) + (((int)((unsigned int)(v3054 + 68) >> 2)) & 1);
  v3215[v3359] = v3055;
  int * v3217 = v3050->cache_dirty;
  v3217[v3214] = 1;
  struct StateT * v3219 = slot_29(v3050);
  return v3219;
}

struct StateT * slot_17(struct StateT * v1014) {
  int * v1015 = v1014->saved_regs;
  int v1016 = v1015[10];
  int v1017 = v1015[11];
  bool v1041 = (v1016 ^ -2147483648) >= (v1017 ^ -2147483648);
  struct StateT * v1036;
  if (v1041) {
    int v1018 = v1014->timer;
    int v1042 = v1018 + 15;
    v1014->timer = v1042;
    int * v1020 = v1014->saved_regs;
    int v1021 = v1020[10];
    int * v1022 = v1014->regs;
    v1022[10] = v1021;
    int * v1024 = v1014->saved_regs;
    int v1025 = v1024[11];
    int * v1026 = v1014->regs;
    v1026[11] = v1025;
    int * v1028 = v1014->saved_regs;
    int v1029 = v1028[12];
    int * v1030 = v1014->regs;
    v1030[12] = v1029;
    struct StateT * v1032 = slot_21(v1014);
    v1036 = v1032;
  } else {
    struct StateT * v1034 = slot_19(v1014);
    v1036 = v1034;
  }
  return v1036;
}

struct StateT * slot_20(struct StateT * v1845) {
  int v1846 = v1845->timer;
  int v1852 = v1846 + 1;
  v1845->timer = v1852;
  int * v1848 = v1845->regs;
  v1848[11] = 0;
  struct StateT * v1850 = slot_23(v1845);
  return v1850;
}

struct StateT * snippet(struct StateT * v0) {
  struct StateT * v1 = slot_0(v0);
  return v1;
}

struct StateT * slot_8(struct StateT * v500) {
  int v501 = v500->timer;
  int v507 = v501 + 1;
  v500->timer = v507;
  int * v503 = v500->regs;
  v503[11] = 0;
  struct StateT * v505 = slot_9(v500);
  return v505;
}

struct StateT * slot_4(struct StateT * v247) {
  int * v248 = v247->saved_regs;
  int * v249 = v247->regs;
  int v250 = v249[11];
  v248[11] = v250;
  int v252 = v247->timer;
  int v262 = v252 + 1;
  v247->timer = v262;
  int * v254 = v247->regs;
  v254[11] = 0;
  struct StateT * v256 = slot_5(v247);
  return v256;
}

struct StateT * slot_15(struct StateT * v794) {
  int v795 = v794->timer;
  int v905 = v795 + 1;
  v794->timer = v905;
  int * v797 = v794->regs;
  int v798 = v797[12];
  int * v799 = v794->cache_tags;
  int v909 = (((int)((unsigned int)((int)((unsigned int)(v798 + 68) >> 2)) >> 1)) & 1) * 2;
  int v800 = v799[v909];
  int v910 = ((((int)((unsigned int)((int)((unsigned int)(v798 + 68) >> 2)) >> 1)) & 1) * 2) + 1;
  int v801 = v799[v910];
  int v911 = 4 + ((((int)((unsigned int)((int)((unsigned int)(v798 + 68) >> 2)) >> 1)) & 3) * 2);
  int v802 = v799[v911];
  int v912 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v798 + 68) >> 2)) >> 1)) & 3) * 2)) + 1;
  int v803 = v799[v912];
  int v804 = v794->timer;
  int v913 = v804 + ((100 ^ (((~(((v802 ^ ((int)((unsigned int)((int)((unsigned int)(v798 + 68) >> 2)) >> 1))) | (-(v802 ^ ((int)((unsigned int)((int)((unsigned int)(v798 + 68) >> 2)) >> 1))))) >> 31)) | (~(((v803 ^ ((int)((unsigned int)((int)((unsigned int)(v798 + 68) >> 2)) >> 1))) | (-(v803 ^ ((int)((unsigned int)((int)((unsigned int)(v798 + 68) >> 2)) >> 1))))) >> 31))) & 104)) ^ (((~(((v800 ^ ((int)((unsigned int)((int)((unsigned int)(v798 + 68) >> 2)) >> 1))) | (-(v800 ^ ((int)((unsigned int)((int)((unsigned int)(v798 + 68) >> 2)) >> 1))))) >> 31)) | (~(((v801 ^ ((int)((unsigned int)((int)((unsigned int)(v798 + 68) >> 2)) >> 1))) | (-(v801 ^ ((int)((unsigned int)((int)((unsigned int)(v798 + 68) >> 2)) >> 1))))) >> 31))) & (1 ^ (100 ^ (((~(((v802 ^ ((int)((unsigned int)((int)((unsigned int)(v798 + 68) >> 2)) >> 1))) | (-(v802 ^ ((int)((unsigned int)((int)((unsigned int)(v798 + 68) >> 2)) >> 1))))) >> 31)) | (~(((v803 ^ ((int)((unsigned int)((int)((unsigned int)(v798 + 68) >> 2)) >> 1))) | (-(v803 ^ ((int)((unsigned int)((int)((unsigned int)(v798 + 68) >> 2)) >> 1))))) >> 31))) & 104)))));
  v794->timer = v913;
  int * v806 = v794->cache_vals;
  bool v914 = !(((~(((v800 ^ ((int)((unsigned int)((int)((unsigned int)(v798 + 68) >> 2)) >> 1))) | (-(v800 ^ ((int)((unsigned int)((int)((unsigned int)(v798 + 68) >> 2)) >> 1))))) >> 31)) | (~(((v801 ^ ((int)((unsigned int)((int)((unsigned int)(v798 + 68) >> 2)) >> 1))) | (-(v801 ^ ((int)((unsigned int)((int)((unsigned int)(v798 + 68) >> 2)) >> 1))))) >> 31))) == 0);
  int v899;
  if (v914) {
    int * v807 = v794->cache_age;
    int v916 = ((((int)((unsigned int)((int)((unsigned int)(v798 + 68) >> 2)) >> 1)) & 1) * 2) + ((~(((v801 ^ ((int)((unsigned int)((int)((unsigned int)(v798 + 68) >> 2)) >> 1))) | (-(v801 ^ ((int)((unsigned int)((int)((unsigned int)(v798 + 68) >> 2)) >> 1))))) >> 31)) & 1);
    int v808 = v807[v916];
    int v809 = v807[v909];
    int v917 = v809 + ((int)((unsigned int)(v809 - v808) >> 31));
    v807[v909] = v917;
    int * v811 = v794->cache_age;
    int v812 = v811[v910];
    int v919 = v812 + ((int)((unsigned int)(v812 - v808) >> 31));
    v811[v910] = v919;
    int * v814 = v794->cache_age;
    v814[v916] = 0;
    v899 = v916;
  } else {
    int * v817 = v794->cache_age;
    int v923 = (((int)((unsigned int)((int)((unsigned int)(v798 + 68) >> 2)) >> 1)) & 1) * 2;
    int v818 = v817[v923];
    int * v819 = v794->cache_tags;
    int v820 = v819[v923];
    int v821 = v817[v910];
    int v822 = v819[v910];
    bool v925 = !(((~(((v802 ^ ((int)((unsigned int)((int)((unsigned int)(v798 + 68) >> 2)) >> 1))) | (-(v802 ^ ((int)((unsigned int)((int)((unsigned int)(v798 + 68) >> 2)) >> 1))))) >> 31)) | (~(((v803 ^ ((int)((unsigned int)((int)((unsigned int)(v798 + 68) >> 2)) >> 1))) | (-(v803 ^ ((int)((unsigned int)((int)((unsigned int)(v798 + 68) >> 2)) >> 1))))) >> 31))) == 0);
    int v876;
    if (v925) {
      int * v823 = v794->cache_age;
      int v927 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v798 + 68) >> 2)) >> 1)) & 3) * 2)) + ((~(((v803 ^ ((int)((unsigned int)((int)((unsigned int)(v798 + 68) >> 2)) >> 1))) | (-(v803 ^ ((int)((unsigned int)((int)((unsigned int)(v798 + 68) >> 2)) >> 1))))) >> 31)) & 1);
      int v824 = v823[v927];
      int v825 = v823[v911];
      int v928 = v825 + ((int)((unsigned int)(v825 - v824) >> 31));
      v823[v911] = v928;
      int * v827 = v794->cache_age;
      int v828 = v827[v912];
      int v930 = v828 + ((int)((unsigned int)(v828 - v824) >> 31));
      v827[v912] = v930;
      int * v830 = v794->cache_age;
      v830[v927] = 0;
      v876 = v927;
    } else {
      int * v833 = v794->cache_age;
      int v934 = 4 + ((((int)((unsigned int)((int)((unsigned int)(v798 + 68) >> 2)) >> 1)) & 3) * 2);
      int v834 = v833[v934];
      int * v835 = v794->cache_tags;
      int v836 = v835[v934];
      int v837 = v833[v912];
      int v838 = v835[v912];
      int * v839 = v794->cache_dirty;
      int v937 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v798 + 68) >> 2)) >> 1)) & 3) * 2)) + ((((v834 + ((~(((v836 ^ -1) | (-(v836 ^ -1))) >> 31)) & 2)) - (v837 + ((~(((v838 ^ -1) | (-(v838 ^ -1))) >> 31)) & 2))) >> 31) & 1);
      int v840 = v839[v937];
      bool v938 = !(v840 == 0);
      if (v938) {
        int * v841 = v794->cache_tags;
        int v842 = v841[v937];
        int * v843 = v794->cache_vals;
        int v941 = ((4 + ((((int)((unsigned int)((int)((unsigned int)(v798 + 68) >> 2)) >> 1)) & 3) * 2)) + ((((v834 + ((~(((v836 ^ -1) | (-(v836 ^ -1))) >> 31)) & 2)) - (v837 + ((~(((v838 ^ -1) | (-(v838 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
        int v844 = v843[v941];
        int v942 = (((4 + ((((int)((unsigned int)((int)((unsigned int)(v798 + 68) >> 2)) >> 1)) & 3) * 2)) + ((((v834 + ((~(((v836 ^ -1) | (-(v836 ^ -1))) >> 31)) & 2)) - (v837 + ((~(((v838 ^ -1) | (-(v838 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
        int v845 = v843[v942];
        int * v846 = v794->mem;
        int v944 = v842 * 2;
        v846[v944] = v844;
        int * v848 = v794->mem;
        int v947 = (v842 * 2) + 1;
        v848[v947] = v845;
        ;
      } else {
        ;
      }
      int * v853 = v794->mem;
      int v952 = ((int)((unsigned int)((int)((unsigned int)(v798 + 68) >> 2)) >> 1)) * 2;
      int v854 = v853[v952];
      int v953 = (((int)((unsigned int)((int)((unsigned int)(v798 + 68) >> 2)) >> 1)) * 2) + 1;
      int v855 = v853[v953];
      int * v856 = v794->cache_vals;
      int v955 = ((4 + ((((int)((unsigned int)((int)((unsigned int)(v798 + 68) >> 2)) >> 1)) & 3) * 2)) + ((((v834 + ((~(((v836 ^ -1) | (-(v836 ^ -1))) >> 31)) & 2)) - (v837 + ((~(((v838 ^ -1) | (-(v838 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
      v856[v955] = v854;
      int * v858 = v794->cache_vals;
      int v958 = (((4 + ((((int)((unsigned int)((int)((unsigned int)(v798 + 68) >> 2)) >> 1)) & 3) * 2)) + ((((v834 + ((~(((v836 ^ -1) | (-(v836 ^ -1))) >> 31)) & 2)) - (v837 + ((~(((v838 ^ -1) | (-(v838 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
      v858[v958] = v855;
      int * v860 = v794->cache_tags;
      int v961 = (int)((unsigned int)((int)((unsigned int)(v798 + 68) >> 2)) >> 1);
      v860[v937] = v961;
      int * v862 = v794->cache_dirty;
      v862[v937] = 0;
      int * v864 = v794->cache_age;
      v864[v937] = 1;
      int * v866 = v794->cache_age;
      int v867 = v866[v937];
      int v868 = v866[v911];
      int v967 = v868 + ((int)((unsigned int)(v868 - v867) >> 31));
      v866[v911] = v967;
      int * v870 = v794->cache_age;
      int v871 = v870[v912];
      int v969 = v871 + ((int)((unsigned int)(v871 - v867) >> 31));
      v870[v912] = v969;
      int * v873 = v794->cache_age;
      v873[v937] = 0;
      v876 = v937;
    }
    int * v877 = v794->cache_vals;
    int v972 = v876 * 2;
    int v878 = v877[v972];
    int v973 = (v876 * 2) + 1;
    int v879 = v877[v973];
    int v974 = (((((int)((unsigned int)((int)((unsigned int)(v798 + 68) >> 2)) >> 1)) & 1) * 2) + ((((v818 + ((~(((v820 ^ -1) | (-(v820 ^ -1))) >> 31)) & 2)) - (v821 + ((~(((v822 ^ -1) | (-(v822 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
    v877[v974] = v878;
    int * v881 = v794->cache_vals;
    int v977 = ((((((int)((unsigned int)((int)((unsigned int)(v798 + 68) >> 2)) >> 1)) & 1) * 2) + ((((v818 + ((~(((v820 ^ -1) | (-(v820 ^ -1))) >> 31)) & 2)) - (v821 + ((~(((v822 ^ -1) | (-(v822 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
    v881[v977] = v879;
    int * v883 = v794->cache_tags;
    int v980 = ((((int)((unsigned int)((int)((unsigned int)(v798 + 68) >> 2)) >> 1)) & 1) * 2) + ((((v818 + ((~(((v820 ^ -1) | (-(v820 ^ -1))) >> 31)) & 2)) - (v821 + ((~(((v822 ^ -1) | (-(v822 ^ -1))) >> 31)) & 2))) >> 31) & 1);
    int v981 = (int)((unsigned int)((int)((unsigned int)(v798 + 68) >> 2)) >> 1);
    v883[v980] = v981;
    int * v885 = v794->cache_dirty;
    v885[v980] = 0;
    int * v887 = v794->cache_age;
    v887[v980] = 1;
    int * v889 = v794->cache_age;
    int v890 = v889[v980];
    int v891 = v889[v909];
    int v987 = v891 + ((int)((unsigned int)(v891 - v890) >> 31));
    v889[v909] = v987;
    int * v893 = v794->cache_age;
    int v894 = v893[v910];
    int v989 = v894 + ((int)((unsigned int)(v894 - v890) >> 31));
    v893[v910] = v989;
    int * v896 = v794->cache_age;
    v896[v980] = 0;
    v899 = v980;
  }
  int v992 = (v899 * 2) + (((int)((unsigned int)(v798 + 68) >> 2)) & 1);
  int v900 = v806[v992];
  int * v901 = v794->regs;
  v901[11] = v900;
  struct StateT * v903 = slot_16(v794);
  return v903;
}

struct StateT * slot_9(struct StateT * v513) {
  int v514 = v513->timer;
  int v521 = v514 + 1;
  v513->timer = v521;
  int * v516 = v513->regs;
  int v517 = v516[11];
  int v524 = v517 + 4;
  v516[11] = v524;
  struct StateT * v519 = slot_10(v513);
  return v519;
}

struct StateT * slot_11(struct StateT * v547) {
  int v548 = v547->timer;
  int v555 = v548 + 1;
  v547->timer = v555;
  int * v550 = v547->regs;
  int v551 = v550[10];
  int v558 = v551 << 29;
  v550[10] = v558;
  struct StateT * v553 = slot_12(v547);
  return v553;
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