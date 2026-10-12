// verify: leak widened (the program is clean; Eva cannot prove it) [unroll 65]
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

struct StateT * slot_12(struct StateT * v549);
struct StateT * slot_14(struct StateT * v589);
struct StateT * slot_6(struct StateT * v281);
struct StateT * slot_16(struct StateT * v1003);
struct StateT * slot_5(struct StateT * v267);
struct StateT * slot_17(struct StateT * v1019);
struct StateT * slot_2(struct StateT * v218);
struct StateT * slot_7(struct StateT * v297);
struct StateT * slot_3(struct StateT * v226);
struct StateT * snippet(struct StateT * v0);
struct StateT * slot_10(struct StateT * v541);
struct StateT * slot_1(struct StateT * v15);
struct StateT * slot_8(struct StateT * v500);
struct StateT * slot_4(struct StateT * v247);
struct StateT * slot_13(struct StateT * v569);
struct StateT * slot_15(struct StateT * v792);
struct StateT * slot_18(struct StateT * v1063);
struct StateT * slot_9(struct StateT * v536);
struct StateT * slot_0(struct StateT * v2);
struct StateT * slot_12(struct StateT * v549) {
  int * v550 = v549->saved_regs;
  int * v551 = v549->regs;
  int v552 = v551[10];
  v550[10] = v552;
  int v554 = v549->timer;
  int v564 = v554 + 1;
  v549->timer = v564;
  int * v556 = v549->regs;
  v556[10] = 0;
  struct StateT * v558 = slot_13(v549);
  return v558;
}

struct StateT * slot_14(struct StateT * v589) {
  int v590 = v589->timer;
  int v700 = v590 + 1;
  v589->timer = v700;
  int * v592 = v589->regs;
  int v593 = v592[10];
  int * v594 = v589->cache_tags;
  int v704 = (((int)((unsigned int)((int)((unsigned int)(v593 + 4) >> 2)) >> 1)) & 1) * 2;
  int v595 = v594[v704];
  int v705 = ((((int)((unsigned int)((int)((unsigned int)(v593 + 4) >> 2)) >> 1)) & 1) * 2) + 1;
  int v596 = v594[v705];
  int v706 = 4 + ((((int)((unsigned int)((int)((unsigned int)(v593 + 4) >> 2)) >> 1)) & 3) * 2);
  int v597 = v594[v706];
  int v707 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v593 + 4) >> 2)) >> 1)) & 3) * 2)) + 1;
  int v598 = v594[v707];
  int v599 = v589->timer;
  int v708 = v599 + ((100 ^ (((~(((v597 ^ ((int)((unsigned int)((int)((unsigned int)(v593 + 4) >> 2)) >> 1))) | (-(v597 ^ ((int)((unsigned int)((int)((unsigned int)(v593 + 4) >> 2)) >> 1))))) >> 31)) | (~(((v598 ^ ((int)((unsigned int)((int)((unsigned int)(v593 + 4) >> 2)) >> 1))) | (-(v598 ^ ((int)((unsigned int)((int)((unsigned int)(v593 + 4) >> 2)) >> 1))))) >> 31))) & 104)) ^ (((~(((v595 ^ ((int)((unsigned int)((int)((unsigned int)(v593 + 4) >> 2)) >> 1))) | (-(v595 ^ ((int)((unsigned int)((int)((unsigned int)(v593 + 4) >> 2)) >> 1))))) >> 31)) | (~(((v596 ^ ((int)((unsigned int)((int)((unsigned int)(v593 + 4) >> 2)) >> 1))) | (-(v596 ^ ((int)((unsigned int)((int)((unsigned int)(v593 + 4) >> 2)) >> 1))))) >> 31))) & (1 ^ (100 ^ (((~(((v597 ^ ((int)((unsigned int)((int)((unsigned int)(v593 + 4) >> 2)) >> 1))) | (-(v597 ^ ((int)((unsigned int)((int)((unsigned int)(v593 + 4) >> 2)) >> 1))))) >> 31)) | (~(((v598 ^ ((int)((unsigned int)((int)((unsigned int)(v593 + 4) >> 2)) >> 1))) | (-(v598 ^ ((int)((unsigned int)((int)((unsigned int)(v593 + 4) >> 2)) >> 1))))) >> 31))) & 104)))));
  v589->timer = v708;
  int * v601 = v589->cache_vals;
  bool v709 = !(((~(((v595 ^ ((int)((unsigned int)((int)((unsigned int)(v593 + 4) >> 2)) >> 1))) | (-(v595 ^ ((int)((unsigned int)((int)((unsigned int)(v593 + 4) >> 2)) >> 1))))) >> 31)) | (~(((v596 ^ ((int)((unsigned int)((int)((unsigned int)(v593 + 4) >> 2)) >> 1))) | (-(v596 ^ ((int)((unsigned int)((int)((unsigned int)(v593 + 4) >> 2)) >> 1))))) >> 31))) == 0);
  int v694;
  if (v709) {
    int * v602 = v589->cache_age;
    int v711 = ((((int)((unsigned int)((int)((unsigned int)(v593 + 4) >> 2)) >> 1)) & 1) * 2) + ((~(((v596 ^ ((int)((unsigned int)((int)((unsigned int)(v593 + 4) >> 2)) >> 1))) | (-(v596 ^ ((int)((unsigned int)((int)((unsigned int)(v593 + 4) >> 2)) >> 1))))) >> 31)) & 1);
    int v603 = v602[v711];
    int v604 = v602[v704];
    int v712 = v604 + ((int)((unsigned int)(v604 - v603) >> 31));
    v602[v704] = v712;
    int * v606 = v589->cache_age;
    int v607 = v606[v705];
    int v714 = v607 + ((int)((unsigned int)(v607 - v603) >> 31));
    v606[v705] = v714;
    int * v609 = v589->cache_age;
    v609[v711] = 0;
    v694 = v711;
  } else {
    int * v612 = v589->cache_age;
    int v718 = (((int)((unsigned int)((int)((unsigned int)(v593 + 4) >> 2)) >> 1)) & 1) * 2;
    int v613 = v612[v718];
    int * v614 = v589->cache_tags;
    int v615 = v614[v718];
    int v616 = v612[v705];
    int v617 = v614[v705];
    bool v720 = !(((~(((v597 ^ ((int)((unsigned int)((int)((unsigned int)(v593 + 4) >> 2)) >> 1))) | (-(v597 ^ ((int)((unsigned int)((int)((unsigned int)(v593 + 4) >> 2)) >> 1))))) >> 31)) | (~(((v598 ^ ((int)((unsigned int)((int)((unsigned int)(v593 + 4) >> 2)) >> 1))) | (-(v598 ^ ((int)((unsigned int)((int)((unsigned int)(v593 + 4) >> 2)) >> 1))))) >> 31))) == 0);
    int v671;
    if (v720) {
      int * v618 = v589->cache_age;
      int v722 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v593 + 4) >> 2)) >> 1)) & 3) * 2)) + ((~(((v598 ^ ((int)((unsigned int)((int)((unsigned int)(v593 + 4) >> 2)) >> 1))) | (-(v598 ^ ((int)((unsigned int)((int)((unsigned int)(v593 + 4) >> 2)) >> 1))))) >> 31)) & 1);
      int v619 = v618[v722];
      int v620 = v618[v706];
      int v723 = v620 + ((int)((unsigned int)(v620 - v619) >> 31));
      v618[v706] = v723;
      int * v622 = v589->cache_age;
      int v623 = v622[v707];
      int v725 = v623 + ((int)((unsigned int)(v623 - v619) >> 31));
      v622[v707] = v725;
      int * v625 = v589->cache_age;
      v625[v722] = 0;
      v671 = v722;
    } else {
      int * v628 = v589->cache_age;
      int v729 = 4 + ((((int)((unsigned int)((int)((unsigned int)(v593 + 4) >> 2)) >> 1)) & 3) * 2);
      int v629 = v628[v729];
      int * v630 = v589->cache_tags;
      int v631 = v630[v729];
      int v632 = v628[v707];
      int v633 = v630[v707];
      int * v634 = v589->cache_dirty;
      int v732 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v593 + 4) >> 2)) >> 1)) & 3) * 2)) + ((((v629 + ((~(((v631 ^ -1) | (-(v631 ^ -1))) >> 31)) & 2)) - (v632 + ((~(((v633 ^ -1) | (-(v633 ^ -1))) >> 31)) & 2))) >> 31) & 1);
      int v635 = v634[v732];
      bool v733 = !(v635 == 0);
      if (v733) {
        int * v636 = v589->cache_tags;
        int v637 = v636[v732];
        int * v638 = v589->cache_vals;
        int v736 = ((4 + ((((int)((unsigned int)((int)((unsigned int)(v593 + 4) >> 2)) >> 1)) & 3) * 2)) + ((((v629 + ((~(((v631 ^ -1) | (-(v631 ^ -1))) >> 31)) & 2)) - (v632 + ((~(((v633 ^ -1) | (-(v633 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
        int v639 = v638[v736];
        int v737 = (((4 + ((((int)((unsigned int)((int)((unsigned int)(v593 + 4) >> 2)) >> 1)) & 3) * 2)) + ((((v629 + ((~(((v631 ^ -1) | (-(v631 ^ -1))) >> 31)) & 2)) - (v632 + ((~(((v633 ^ -1) | (-(v633 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
        int v640 = v638[v737];
        int * v641 = v589->mem;
        int v739 = v637 * 2;
        v641[v739] = v639;
        int * v643 = v589->mem;
        int v742 = (v637 * 2) + 1;
        v643[v742] = v640;
        ;
      } else {
        ;
      }
      int * v648 = v589->mem;
      int v747 = ((int)((unsigned int)((int)((unsigned int)(v593 + 4) >> 2)) >> 1)) * 2;
      int v649 = v648[v747];
      int v748 = (((int)((unsigned int)((int)((unsigned int)(v593 + 4) >> 2)) >> 1)) * 2) + 1;
      int v650 = v648[v748];
      int * v651 = v589->cache_vals;
      int v750 = ((4 + ((((int)((unsigned int)((int)((unsigned int)(v593 + 4) >> 2)) >> 1)) & 3) * 2)) + ((((v629 + ((~(((v631 ^ -1) | (-(v631 ^ -1))) >> 31)) & 2)) - (v632 + ((~(((v633 ^ -1) | (-(v633 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
      v651[v750] = v649;
      int * v653 = v589->cache_vals;
      int v753 = (((4 + ((((int)((unsigned int)((int)((unsigned int)(v593 + 4) >> 2)) >> 1)) & 3) * 2)) + ((((v629 + ((~(((v631 ^ -1) | (-(v631 ^ -1))) >> 31)) & 2)) - (v632 + ((~(((v633 ^ -1) | (-(v633 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
      v653[v753] = v650;
      int * v655 = v589->cache_tags;
      int v756 = (int)((unsigned int)((int)((unsigned int)(v593 + 4) >> 2)) >> 1);
      v655[v732] = v756;
      int * v657 = v589->cache_dirty;
      v657[v732] = 0;
      int * v659 = v589->cache_age;
      v659[v732] = 1;
      int * v661 = v589->cache_age;
      int v662 = v661[v732];
      int v663 = v661[v706];
      int v762 = v663 + ((int)((unsigned int)(v663 - v662) >> 31));
      v661[v706] = v762;
      int * v665 = v589->cache_age;
      int v666 = v665[v707];
      int v764 = v666 + ((int)((unsigned int)(v666 - v662) >> 31));
      v665[v707] = v764;
      int * v668 = v589->cache_age;
      v668[v732] = 0;
      v671 = v732;
    }
    int * v672 = v589->cache_vals;
    int v767 = v671 * 2;
    int v673 = v672[v767];
    int v768 = (v671 * 2) + 1;
    int v674 = v672[v768];
    int v769 = (((((int)((unsigned int)((int)((unsigned int)(v593 + 4) >> 2)) >> 1)) & 1) * 2) + ((((v613 + ((~(((v615 ^ -1) | (-(v615 ^ -1))) >> 31)) & 2)) - (v616 + ((~(((v617 ^ -1) | (-(v617 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
    v672[v769] = v673;
    int * v676 = v589->cache_vals;
    int v772 = ((((((int)((unsigned int)((int)((unsigned int)(v593 + 4) >> 2)) >> 1)) & 1) * 2) + ((((v613 + ((~(((v615 ^ -1) | (-(v615 ^ -1))) >> 31)) & 2)) - (v616 + ((~(((v617 ^ -1) | (-(v617 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
    v676[v772] = v674;
    int * v678 = v589->cache_tags;
    int v775 = ((((int)((unsigned int)((int)((unsigned int)(v593 + 4) >> 2)) >> 1)) & 1) * 2) + ((((v613 + ((~(((v615 ^ -1) | (-(v615 ^ -1))) >> 31)) & 2)) - (v616 + ((~(((v617 ^ -1) | (-(v617 ^ -1))) >> 31)) & 2))) >> 31) & 1);
    int v776 = (int)((unsigned int)((int)((unsigned int)(v593 + 4) >> 2)) >> 1);
    v678[v775] = v776;
    int * v680 = v589->cache_dirty;
    v680[v775] = 0;
    int * v682 = v589->cache_age;
    v682[v775] = 1;
    int * v684 = v589->cache_age;
    int v685 = v684[v775];
    int v686 = v684[v704];
    int v782 = v686 + ((int)((unsigned int)(v686 - v685) >> 31));
    v684[v704] = v782;
    int * v688 = v589->cache_age;
    int v689 = v688[v705];
    int v784 = v689 + ((int)((unsigned int)(v689 - v685) >> 31));
    v688[v705] = v784;
    int * v691 = v589->cache_age;
    v691[v775] = 0;
    v694 = v775;
  }
  int v787 = (v694 * 2) + (((int)((unsigned int)(v593 + 4) >> 2)) & 1);
  int v695 = v601[v787];
  int * v696 = v589->regs;
  v696[10] = v695;
  struct StateT * v698 = slot_15(v589);
  return v698;
}

struct StateT * slot_6(struct StateT * v281) {
  int v282 = v281->timer;
  int v290 = v282 + 1;
  v281->timer = v290;
  int * v284 = v281->regs;
  int v285 = v284[12];
  int v286 = v284[10];
  int v294 = v285 + v286;
  v284[10] = v294;
  struct StateT * v288 = slot_7(v281);
  return v288;
}

struct StateT * slot_16(struct StateT * v1003) {
  int v1004 = v1003->timer;
  int v1012 = v1004 + 1;
  v1003->timer = v1012;
  int * v1006 = v1003->regs;
  int v1007 = v1006[12];
  int v1008 = v1006[10];
  int v1016 = v1007 & v1008;
  v1006[10] = v1016;
  struct StateT * v1010 = slot_17(v1003);
  return v1010;
}

struct StateT * slot_5(struct StateT * v267) {
  int v268 = v267->timer;
  int v275 = v268 + 1;
  v267->timer = v275;
  int * v270 = v267->regs;
  int v271 = v270[12];
  int v278 = v271 + 72;
  v270[12] = v278;
  struct StateT * v273 = slot_6(v267);
  return v273;
}

struct StateT * slot_17(struct StateT * v1019) {
  int * v1020 = v1019->saved_regs;
  int v1021 = v1020[10];
  int v1022 = v1020[11];
  bool v1046 = !(v1021 == v1022);
  struct StateT * v1041;
  if (v1046) {
    int v1023 = v1019->timer;
    int v1047 = v1023 + 15;
    v1019->timer = v1047;
    int * v1025 = v1019->saved_regs;
    int v1026 = v1025[10];
    int * v1027 = v1019->regs;
    v1027[10] = v1026;
    int * v1029 = v1019->saved_regs;
    int v1030 = v1029[11];
    int * v1031 = v1019->regs;
    v1031[11] = v1030;
    int * v1033 = v1019->saved_regs;
    int v1034 = v1033[12];
    int * v1035 = v1019->regs;
    v1035[12] = v1034;
    struct StateT * v1037 = slot_9(v1019);
    v1041 = v1037;
  } else {
    struct StateT * v1039 = slot_18(v1019);
    v1041 = v1039;
  }
  return v1041;
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

struct StateT * snippet(struct StateT * v0) {
  struct StateT * v1 = slot_0(v0);
  return v1;
}

struct StateT * slot_10(struct StateT * v541) {
  int v542 = v541->timer;
  int v546 = v542 + 1;
  v541->timer = v546;
  struct StateT * v544 = slot_12(v541);
  return v544;
}

struct StateT * slot_1(struct StateT * v15) {
  int v16 = v15->timer;
  int v126 = v16 + 1;
  v15->timer = v126;
  int * v18 = v15->regs;
  int v19 = v18[12];
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
  v122[12] = v121;
  struct StateT * v124 = slot_2(v15);
  return v124;
}

struct StateT * slot_8(struct StateT * v500) {
  int * v501 = v500->saved_regs;
  int v502 = v501[10];
  int v503 = v501[12];
  bool v523 = (v502 ^ -2147483648) >= (v503 ^ -2147483648);
  struct StateT * v518;
  if (v523) {
    int v504 = v500->timer;
    int v524 = v504 + 15;
    v500->timer = v524;
    int * v506 = v500->saved_regs;
    int v507 = v506[10];
    int * v508 = v500->regs;
    v508[10] = v507;
    int * v510 = v500->saved_regs;
    int v511 = v510[12];
    int * v512 = v500->regs;
    v512[12] = v511;
    struct StateT * v514 = slot_9(v500);
    v518 = v514;
  } else {
    struct StateT * v516 = slot_10(v500);
    v518 = v516;
  }
  return v518;
}

struct StateT * slot_4(struct StateT * v247) {
  int * v248 = v247->saved_regs;
  int * v249 = v247->regs;
  int v250 = v249[12];
  v248[12] = v250;
  int v252 = v247->timer;
  int v262 = v252 + 1;
  v247->timer = v262;
  int * v254 = v247->regs;
  v254[12] = 0;
  struct StateT * v256 = slot_5(v247);
  return v256;
}

struct StateT * slot_13(struct StateT * v569) {
  int * v570 = v569->saved_regs;
  int * v571 = v569->regs;
  int v572 = v571[11];
  v570[11] = v572;
  int v574 = v569->timer;
  int v584 = v574 + 1;
  v569->timer = v584;
  int * v576 = v569->regs;
  v576[11] = 0;
  struct StateT * v578 = slot_14(v569);
  return v578;
}

struct StateT * slot_15(struct StateT * v792) {
  int * v793 = v792->saved_regs;
  int * v794 = v792->regs;
  int v795 = v794[12];
  v793[12] = v795;
  int v797 = v792->timer;
  int v911 = v797 + 1;
  v792->timer = v911;
  int * v799 = v792->regs;
  int v800 = v799[11];
  int * v801 = v792->cache_tags;
  int v915 = (((int)((unsigned int)((int)((unsigned int)(v800 + 68) >> 2)) >> 1)) & 1) * 2;
  int v802 = v801[v915];
  int v916 = ((((int)((unsigned int)((int)((unsigned int)(v800 + 68) >> 2)) >> 1)) & 1) * 2) + 1;
  int v803 = v801[v916];
  int v917 = 4 + ((((int)((unsigned int)((int)((unsigned int)(v800 + 68) >> 2)) >> 1)) & 3) * 2);
  int v804 = v801[v917];
  int v918 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v800 + 68) >> 2)) >> 1)) & 3) * 2)) + 1;
  int v805 = v801[v918];
  int v806 = v792->timer;
  int v919 = v806 + ((100 ^ (((~(((v804 ^ ((int)((unsigned int)((int)((unsigned int)(v800 + 68) >> 2)) >> 1))) | (-(v804 ^ ((int)((unsigned int)((int)((unsigned int)(v800 + 68) >> 2)) >> 1))))) >> 31)) | (~(((v805 ^ ((int)((unsigned int)((int)((unsigned int)(v800 + 68) >> 2)) >> 1))) | (-(v805 ^ ((int)((unsigned int)((int)((unsigned int)(v800 + 68) >> 2)) >> 1))))) >> 31))) & 104)) ^ (((~(((v802 ^ ((int)((unsigned int)((int)((unsigned int)(v800 + 68) >> 2)) >> 1))) | (-(v802 ^ ((int)((unsigned int)((int)((unsigned int)(v800 + 68) >> 2)) >> 1))))) >> 31)) | (~(((v803 ^ ((int)((unsigned int)((int)((unsigned int)(v800 + 68) >> 2)) >> 1))) | (-(v803 ^ ((int)((unsigned int)((int)((unsigned int)(v800 + 68) >> 2)) >> 1))))) >> 31))) & (1 ^ (100 ^ (((~(((v804 ^ ((int)((unsigned int)((int)((unsigned int)(v800 + 68) >> 2)) >> 1))) | (-(v804 ^ ((int)((unsigned int)((int)((unsigned int)(v800 + 68) >> 2)) >> 1))))) >> 31)) | (~(((v805 ^ ((int)((unsigned int)((int)((unsigned int)(v800 + 68) >> 2)) >> 1))) | (-(v805 ^ ((int)((unsigned int)((int)((unsigned int)(v800 + 68) >> 2)) >> 1))))) >> 31))) & 104)))));
  v792->timer = v919;
  int * v808 = v792->cache_vals;
  bool v920 = !(((~(((v802 ^ ((int)((unsigned int)((int)((unsigned int)(v800 + 68) >> 2)) >> 1))) | (-(v802 ^ ((int)((unsigned int)((int)((unsigned int)(v800 + 68) >> 2)) >> 1))))) >> 31)) | (~(((v803 ^ ((int)((unsigned int)((int)((unsigned int)(v800 + 68) >> 2)) >> 1))) | (-(v803 ^ ((int)((unsigned int)((int)((unsigned int)(v800 + 68) >> 2)) >> 1))))) >> 31))) == 0);
  int v901;
  if (v920) {
    int * v809 = v792->cache_age;
    int v922 = ((((int)((unsigned int)((int)((unsigned int)(v800 + 68) >> 2)) >> 1)) & 1) * 2) + ((~(((v803 ^ ((int)((unsigned int)((int)((unsigned int)(v800 + 68) >> 2)) >> 1))) | (-(v803 ^ ((int)((unsigned int)((int)((unsigned int)(v800 + 68) >> 2)) >> 1))))) >> 31)) & 1);
    int v810 = v809[v922];
    int v811 = v809[v915];
    int v923 = v811 + ((int)((unsigned int)(v811 - v810) >> 31));
    v809[v915] = v923;
    int * v813 = v792->cache_age;
    int v814 = v813[v916];
    int v925 = v814 + ((int)((unsigned int)(v814 - v810) >> 31));
    v813[v916] = v925;
    int * v816 = v792->cache_age;
    v816[v922] = 0;
    v901 = v922;
  } else {
    int * v819 = v792->cache_age;
    int v929 = (((int)((unsigned int)((int)((unsigned int)(v800 + 68) >> 2)) >> 1)) & 1) * 2;
    int v820 = v819[v929];
    int * v821 = v792->cache_tags;
    int v822 = v821[v929];
    int v823 = v819[v916];
    int v824 = v821[v916];
    bool v931 = !(((~(((v804 ^ ((int)((unsigned int)((int)((unsigned int)(v800 + 68) >> 2)) >> 1))) | (-(v804 ^ ((int)((unsigned int)((int)((unsigned int)(v800 + 68) >> 2)) >> 1))))) >> 31)) | (~(((v805 ^ ((int)((unsigned int)((int)((unsigned int)(v800 + 68) >> 2)) >> 1))) | (-(v805 ^ ((int)((unsigned int)((int)((unsigned int)(v800 + 68) >> 2)) >> 1))))) >> 31))) == 0);
    int v878;
    if (v931) {
      int * v825 = v792->cache_age;
      int v933 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v800 + 68) >> 2)) >> 1)) & 3) * 2)) + ((~(((v805 ^ ((int)((unsigned int)((int)((unsigned int)(v800 + 68) >> 2)) >> 1))) | (-(v805 ^ ((int)((unsigned int)((int)((unsigned int)(v800 + 68) >> 2)) >> 1))))) >> 31)) & 1);
      int v826 = v825[v933];
      int v827 = v825[v917];
      int v934 = v827 + ((int)((unsigned int)(v827 - v826) >> 31));
      v825[v917] = v934;
      int * v829 = v792->cache_age;
      int v830 = v829[v918];
      int v936 = v830 + ((int)((unsigned int)(v830 - v826) >> 31));
      v829[v918] = v936;
      int * v832 = v792->cache_age;
      v832[v933] = 0;
      v878 = v933;
    } else {
      int * v835 = v792->cache_age;
      int v940 = 4 + ((((int)((unsigned int)((int)((unsigned int)(v800 + 68) >> 2)) >> 1)) & 3) * 2);
      int v836 = v835[v940];
      int * v837 = v792->cache_tags;
      int v838 = v837[v940];
      int v839 = v835[v918];
      int v840 = v837[v918];
      int * v841 = v792->cache_dirty;
      int v943 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v800 + 68) >> 2)) >> 1)) & 3) * 2)) + ((((v836 + ((~(((v838 ^ -1) | (-(v838 ^ -1))) >> 31)) & 2)) - (v839 + ((~(((v840 ^ -1) | (-(v840 ^ -1))) >> 31)) & 2))) >> 31) & 1);
      int v842 = v841[v943];
      bool v944 = !(v842 == 0);
      if (v944) {
        int * v843 = v792->cache_tags;
        int v844 = v843[v943];
        int * v845 = v792->cache_vals;
        int v947 = ((4 + ((((int)((unsigned int)((int)((unsigned int)(v800 + 68) >> 2)) >> 1)) & 3) * 2)) + ((((v836 + ((~(((v838 ^ -1) | (-(v838 ^ -1))) >> 31)) & 2)) - (v839 + ((~(((v840 ^ -1) | (-(v840 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
        int v846 = v845[v947];
        int v948 = (((4 + ((((int)((unsigned int)((int)((unsigned int)(v800 + 68) >> 2)) >> 1)) & 3) * 2)) + ((((v836 + ((~(((v838 ^ -1) | (-(v838 ^ -1))) >> 31)) & 2)) - (v839 + ((~(((v840 ^ -1) | (-(v840 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
        int v847 = v845[v948];
        int * v848 = v792->mem;
        int v950 = v844 * 2;
        v848[v950] = v846;
        int * v850 = v792->mem;
        int v953 = (v844 * 2) + 1;
        v850[v953] = v847;
        ;
      } else {
        ;
      }
      int * v855 = v792->mem;
      int v958 = ((int)((unsigned int)((int)((unsigned int)(v800 + 68) >> 2)) >> 1)) * 2;
      int v856 = v855[v958];
      int v959 = (((int)((unsigned int)((int)((unsigned int)(v800 + 68) >> 2)) >> 1)) * 2) + 1;
      int v857 = v855[v959];
      int * v858 = v792->cache_vals;
      int v961 = ((4 + ((((int)((unsigned int)((int)((unsigned int)(v800 + 68) >> 2)) >> 1)) & 3) * 2)) + ((((v836 + ((~(((v838 ^ -1) | (-(v838 ^ -1))) >> 31)) & 2)) - (v839 + ((~(((v840 ^ -1) | (-(v840 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
      v858[v961] = v856;
      int * v860 = v792->cache_vals;
      int v964 = (((4 + ((((int)((unsigned int)((int)((unsigned int)(v800 + 68) >> 2)) >> 1)) & 3) * 2)) + ((((v836 + ((~(((v838 ^ -1) | (-(v838 ^ -1))) >> 31)) & 2)) - (v839 + ((~(((v840 ^ -1) | (-(v840 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
      v860[v964] = v857;
      int * v862 = v792->cache_tags;
      int v967 = (int)((unsigned int)((int)((unsigned int)(v800 + 68) >> 2)) >> 1);
      v862[v943] = v967;
      int * v864 = v792->cache_dirty;
      v864[v943] = 0;
      int * v866 = v792->cache_age;
      v866[v943] = 1;
      int * v868 = v792->cache_age;
      int v869 = v868[v943];
      int v870 = v868[v917];
      int v973 = v870 + ((int)((unsigned int)(v870 - v869) >> 31));
      v868[v917] = v973;
      int * v872 = v792->cache_age;
      int v873 = v872[v918];
      int v975 = v873 + ((int)((unsigned int)(v873 - v869) >> 31));
      v872[v918] = v975;
      int * v875 = v792->cache_age;
      v875[v943] = 0;
      v878 = v943;
    }
    int * v879 = v792->cache_vals;
    int v978 = v878 * 2;
    int v880 = v879[v978];
    int v979 = (v878 * 2) + 1;
    int v881 = v879[v979];
    int v980 = (((((int)((unsigned int)((int)((unsigned int)(v800 + 68) >> 2)) >> 1)) & 1) * 2) + ((((v820 + ((~(((v822 ^ -1) | (-(v822 ^ -1))) >> 31)) & 2)) - (v823 + ((~(((v824 ^ -1) | (-(v824 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
    v879[v980] = v880;
    int * v883 = v792->cache_vals;
    int v983 = ((((((int)((unsigned int)((int)((unsigned int)(v800 + 68) >> 2)) >> 1)) & 1) * 2) + ((((v820 + ((~(((v822 ^ -1) | (-(v822 ^ -1))) >> 31)) & 2)) - (v823 + ((~(((v824 ^ -1) | (-(v824 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
    v883[v983] = v881;
    int * v885 = v792->cache_tags;
    int v986 = ((((int)((unsigned int)((int)((unsigned int)(v800 + 68) >> 2)) >> 1)) & 1) * 2) + ((((v820 + ((~(((v822 ^ -1) | (-(v822 ^ -1))) >> 31)) & 2)) - (v823 + ((~(((v824 ^ -1) | (-(v824 ^ -1))) >> 31)) & 2))) >> 31) & 1);
    int v987 = (int)((unsigned int)((int)((unsigned int)(v800 + 68) >> 2)) >> 1);
    v885[v986] = v987;
    int * v887 = v792->cache_dirty;
    v887[v986] = 0;
    int * v889 = v792->cache_age;
    v889[v986] = 1;
    int * v891 = v792->cache_age;
    int v892 = v891[v986];
    int v893 = v891[v915];
    int v993 = v893 + ((int)((unsigned int)(v893 - v892) >> 31));
    v891[v915] = v993;
    int * v895 = v792->cache_age;
    int v896 = v895[v916];
    int v995 = v896 + ((int)((unsigned int)(v896 - v892) >> 31));
    v895[v916] = v995;
    int * v898 = v792->cache_age;
    v898[v986] = 0;
    v901 = v986;
  }
  int v998 = (v901 * 2) + (((int)((unsigned int)(v800 + 68) >> 2)) & 1);
  int v902 = v808[v998];
  int * v903 = v792->regs;
  v903[12] = v902;
  struct StateT * v905 = slot_16(v792);
  return v905;
}

struct StateT * slot_18(struct StateT * v1063) {
  int v1064 = v1063->timer;
  int v1234 = v1064 + 1;
  v1063->timer = v1234;
  int * v1066 = v1063->regs;
  int v1067 = v1066[11];
  int v1068 = v1066[10];
  int * v1069 = v1063->cache_tags;
  int v1239 = (((int)((unsigned int)((int)((unsigned int)(v1067 + 68) >> 2)) >> 1)) & 1) * 2;
  int v1070 = v1069[v1239];
  int v1240 = ((((int)((unsigned int)((int)((unsigned int)(v1067 + 68) >> 2)) >> 1)) & 1) * 2) + 1;
  int v1071 = v1069[v1240];
  int v1241 = 4 + ((((int)((unsigned int)((int)((unsigned int)(v1067 + 68) >> 2)) >> 1)) & 3) * 2);
  int v1072 = v1069[v1241];
  int v1242 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v1067 + 68) >> 2)) >> 1)) & 3) * 2)) + 1;
  int v1073 = v1069[v1242];
  int v1074 = v1063->timer;
  int v1243 = v1074 + ((100 ^ (((~(((v1072 ^ ((int)((unsigned int)((int)((unsigned int)(v1067 + 68) >> 2)) >> 1))) | (-(v1072 ^ ((int)((unsigned int)((int)((unsigned int)(v1067 + 68) >> 2)) >> 1))))) >> 31)) | (~(((v1073 ^ ((int)((unsigned int)((int)((unsigned int)(v1067 + 68) >> 2)) >> 1))) | (-(v1073 ^ ((int)((unsigned int)((int)((unsigned int)(v1067 + 68) >> 2)) >> 1))))) >> 31))) & 104)) ^ (((~(((v1070 ^ ((int)((unsigned int)((int)((unsigned int)(v1067 + 68) >> 2)) >> 1))) | (-(v1070 ^ ((int)((unsigned int)((int)((unsigned int)(v1067 + 68) >> 2)) >> 1))))) >> 31)) | (~(((v1071 ^ ((int)((unsigned int)((int)((unsigned int)(v1067 + 68) >> 2)) >> 1))) | (-(v1071 ^ ((int)((unsigned int)((int)((unsigned int)(v1067 + 68) >> 2)) >> 1))))) >> 31))) & (1 ^ (100 ^ (((~(((v1072 ^ ((int)((unsigned int)((int)((unsigned int)(v1067 + 68) >> 2)) >> 1))) | (-(v1072 ^ ((int)((unsigned int)((int)((unsigned int)(v1067 + 68) >> 2)) >> 1))))) >> 31)) | (~(((v1073 ^ ((int)((unsigned int)((int)((unsigned int)(v1067 + 68) >> 2)) >> 1))) | (-(v1073 ^ ((int)((unsigned int)((int)((unsigned int)(v1067 + 68) >> 2)) >> 1))))) >> 31))) & 104)))));
  v1063->timer = v1243;
  bool v1244 = !(((~(((v1070 ^ ((int)((unsigned int)((int)((unsigned int)(v1067 + 68) >> 2)) >> 1))) | (-(v1070 ^ ((int)((unsigned int)((int)((unsigned int)(v1067 + 68) >> 2)) >> 1))))) >> 31)) | (~(((v1071 ^ ((int)((unsigned int)((int)((unsigned int)(v1067 + 68) >> 2)) >> 1))) | (-(v1071 ^ ((int)((unsigned int)((int)((unsigned int)(v1067 + 68) >> 2)) >> 1))))) >> 31))) == 0);
  int v1168;
  if (v1244) {
    int * v1076 = v1063->cache_age;
    int v1246 = ((((int)((unsigned int)((int)((unsigned int)(v1067 + 68) >> 2)) >> 1)) & 1) * 2) + ((~(((v1071 ^ ((int)((unsigned int)((int)((unsigned int)(v1067 + 68) >> 2)) >> 1))) | (-(v1071 ^ ((int)((unsigned int)((int)((unsigned int)(v1067 + 68) >> 2)) >> 1))))) >> 31)) & 1);
    int v1077 = v1076[v1246];
    int v1078 = v1076[v1239];
    int v1247 = v1078 + ((int)((unsigned int)(v1078 - v1077) >> 31));
    v1076[v1239] = v1247;
    int * v1080 = v1063->cache_age;
    int v1081 = v1080[v1240];
    int v1249 = v1081 + ((int)((unsigned int)(v1081 - v1077) >> 31));
    v1080[v1240] = v1249;
    int * v1083 = v1063->cache_age;
    v1083[v1246] = 0;
    v1168 = v1246;
  } else {
    int * v1086 = v1063->cache_age;
    int v1253 = (((int)((unsigned int)((int)((unsigned int)(v1067 + 68) >> 2)) >> 1)) & 1) * 2;
    int v1087 = v1086[v1253];
    int * v1088 = v1063->cache_tags;
    int v1089 = v1088[v1253];
    int v1090 = v1086[v1240];
    int v1091 = v1088[v1240];
    bool v1255 = !(((~(((v1072 ^ ((int)((unsigned int)((int)((unsigned int)(v1067 + 68) >> 2)) >> 1))) | (-(v1072 ^ ((int)((unsigned int)((int)((unsigned int)(v1067 + 68) >> 2)) >> 1))))) >> 31)) | (~(((v1073 ^ ((int)((unsigned int)((int)((unsigned int)(v1067 + 68) >> 2)) >> 1))) | (-(v1073 ^ ((int)((unsigned int)((int)((unsigned int)(v1067 + 68) >> 2)) >> 1))))) >> 31))) == 0);
    int v1145;
    if (v1255) {
      int * v1092 = v1063->cache_age;
      int v1257 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v1067 + 68) >> 2)) >> 1)) & 3) * 2)) + ((~(((v1073 ^ ((int)((unsigned int)((int)((unsigned int)(v1067 + 68) >> 2)) >> 1))) | (-(v1073 ^ ((int)((unsigned int)((int)((unsigned int)(v1067 + 68) >> 2)) >> 1))))) >> 31)) & 1);
      int v1093 = v1092[v1257];
      int v1094 = v1092[v1241];
      int v1258 = v1094 + ((int)((unsigned int)(v1094 - v1093) >> 31));
      v1092[v1241] = v1258;
      int * v1096 = v1063->cache_age;
      int v1097 = v1096[v1242];
      int v1260 = v1097 + ((int)((unsigned int)(v1097 - v1093) >> 31));
      v1096[v1242] = v1260;
      int * v1099 = v1063->cache_age;
      v1099[v1257] = 0;
      v1145 = v1257;
    } else {
      int * v1102 = v1063->cache_age;
      int v1264 = 4 + ((((int)((unsigned int)((int)((unsigned int)(v1067 + 68) >> 2)) >> 1)) & 3) * 2);
      int v1103 = v1102[v1264];
      int * v1104 = v1063->cache_tags;
      int v1105 = v1104[v1264];
      int v1106 = v1102[v1242];
      int v1107 = v1104[v1242];
      int * v1108 = v1063->cache_dirty;
      int v1267 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v1067 + 68) >> 2)) >> 1)) & 3) * 2)) + ((((v1103 + ((~(((v1105 ^ -1) | (-(v1105 ^ -1))) >> 31)) & 2)) - (v1106 + ((~(((v1107 ^ -1) | (-(v1107 ^ -1))) >> 31)) & 2))) >> 31) & 1);
      int v1109 = v1108[v1267];
      bool v1268 = !(v1109 == 0);
      if (v1268) {
        int * v1110 = v1063->cache_tags;
        int v1111 = v1110[v1267];
        int * v1112 = v1063->cache_vals;
        int v1271 = ((4 + ((((int)((unsigned int)((int)((unsigned int)(v1067 + 68) >> 2)) >> 1)) & 3) * 2)) + ((((v1103 + ((~(((v1105 ^ -1) | (-(v1105 ^ -1))) >> 31)) & 2)) - (v1106 + ((~(((v1107 ^ -1) | (-(v1107 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
        int v1113 = v1112[v1271];
        int v1272 = (((4 + ((((int)((unsigned int)((int)((unsigned int)(v1067 + 68) >> 2)) >> 1)) & 3) * 2)) + ((((v1103 + ((~(((v1105 ^ -1) | (-(v1105 ^ -1))) >> 31)) & 2)) - (v1106 + ((~(((v1107 ^ -1) | (-(v1107 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
        int v1114 = v1112[v1272];
        int * v1115 = v1063->mem;
        int v1274 = v1111 * 2;
        v1115[v1274] = v1113;
        int * v1117 = v1063->mem;
        int v1277 = (v1111 * 2) + 1;
        v1117[v1277] = v1114;
        ;
      } else {
        ;
      }
      int * v1122 = v1063->mem;
      int v1282 = ((int)((unsigned int)((int)((unsigned int)(v1067 + 68) >> 2)) >> 1)) * 2;
      int v1123 = v1122[v1282];
      int v1283 = (((int)((unsigned int)((int)((unsigned int)(v1067 + 68) >> 2)) >> 1)) * 2) + 1;
      int v1124 = v1122[v1283];
      int * v1125 = v1063->cache_vals;
      int v1285 = ((4 + ((((int)((unsigned int)((int)((unsigned int)(v1067 + 68) >> 2)) >> 1)) & 3) * 2)) + ((((v1103 + ((~(((v1105 ^ -1) | (-(v1105 ^ -1))) >> 31)) & 2)) - (v1106 + ((~(((v1107 ^ -1) | (-(v1107 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
      v1125[v1285] = v1123;
      int * v1127 = v1063->cache_vals;
      int v1288 = (((4 + ((((int)((unsigned int)((int)((unsigned int)(v1067 + 68) >> 2)) >> 1)) & 3) * 2)) + ((((v1103 + ((~(((v1105 ^ -1) | (-(v1105 ^ -1))) >> 31)) & 2)) - (v1106 + ((~(((v1107 ^ -1) | (-(v1107 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
      v1127[v1288] = v1124;
      int * v1129 = v1063->cache_tags;
      int v1291 = (int)((unsigned int)((int)((unsigned int)(v1067 + 68) >> 2)) >> 1);
      v1129[v1267] = v1291;
      int * v1131 = v1063->cache_dirty;
      v1131[v1267] = 0;
      int * v1133 = v1063->cache_age;
      v1133[v1267] = 1;
      int * v1135 = v1063->cache_age;
      int v1136 = v1135[v1267];
      int v1137 = v1135[v1241];
      int v1297 = v1137 + ((int)((unsigned int)(v1137 - v1136) >> 31));
      v1135[v1241] = v1297;
      int * v1139 = v1063->cache_age;
      int v1140 = v1139[v1242];
      int v1299 = v1140 + ((int)((unsigned int)(v1140 - v1136) >> 31));
      v1139[v1242] = v1299;
      int * v1142 = v1063->cache_age;
      v1142[v1267] = 0;
      v1145 = v1267;
    }
    int * v1146 = v1063->cache_vals;
    int v1302 = v1145 * 2;
    int v1147 = v1146[v1302];
    int v1303 = (v1145 * 2) + 1;
    int v1148 = v1146[v1303];
    int v1304 = (((((int)((unsigned int)((int)((unsigned int)(v1067 + 68) >> 2)) >> 1)) & 1) * 2) + ((((v1087 + ((~(((v1089 ^ -1) | (-(v1089 ^ -1))) >> 31)) & 2)) - (v1090 + ((~(((v1091 ^ -1) | (-(v1091 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
    v1146[v1304] = v1147;
    int * v1150 = v1063->cache_vals;
    int v1307 = ((((((int)((unsigned int)((int)((unsigned int)(v1067 + 68) >> 2)) >> 1)) & 1) * 2) + ((((v1087 + ((~(((v1089 ^ -1) | (-(v1089 ^ -1))) >> 31)) & 2)) - (v1090 + ((~(((v1091 ^ -1) | (-(v1091 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
    v1150[v1307] = v1148;
    int * v1152 = v1063->cache_tags;
    int v1310 = ((((int)((unsigned int)((int)((unsigned int)(v1067 + 68) >> 2)) >> 1)) & 1) * 2) + ((((v1087 + ((~(((v1089 ^ -1) | (-(v1089 ^ -1))) >> 31)) & 2)) - (v1090 + ((~(((v1091 ^ -1) | (-(v1091 ^ -1))) >> 31)) & 2))) >> 31) & 1);
    int v1311 = (int)((unsigned int)((int)((unsigned int)(v1067 + 68) >> 2)) >> 1);
    v1152[v1310] = v1311;
    int * v1154 = v1063->cache_dirty;
    v1154[v1310] = 0;
    int * v1156 = v1063->cache_age;
    v1156[v1310] = 1;
    int * v1158 = v1063->cache_age;
    int v1159 = v1158[v1310];
    int v1160 = v1158[v1239];
    int v1317 = v1160 + ((int)((unsigned int)(v1160 - v1159) >> 31));
    v1158[v1239] = v1317;
    int * v1162 = v1063->cache_age;
    int v1163 = v1162[v1240];
    int v1319 = v1163 + ((int)((unsigned int)(v1163 - v1159) >> 31));
    v1162[v1240] = v1319;
    int * v1165 = v1063->cache_age;
    v1165[v1310] = 0;
    v1168 = v1310;
  }
  int * v1169 = v1063->cache_vals;
  int v1322 = (v1168 * 2) + (((int)((unsigned int)(v1067 + 68) >> 2)) & 1);
  v1169[v1322] = v1068;
  int * v1171 = v1063->cache_tags;
  int v1172 = v1171[v1241];
  int v1173 = v1171[v1242];
  bool v1325 = !(((~(((v1172 ^ ((int)((unsigned int)((int)((unsigned int)(v1067 + 68) >> 2)) >> 1))) | (-(v1172 ^ ((int)((unsigned int)((int)((unsigned int)(v1067 + 68) >> 2)) >> 1))))) >> 31)) | (~(((v1173 ^ ((int)((unsigned int)((int)((unsigned int)(v1067 + 68) >> 2)) >> 1))) | (-(v1173 ^ ((int)((unsigned int)((int)((unsigned int)(v1067 + 68) >> 2)) >> 1))))) >> 31))) == 0);
  int v1227;
  if (v1325) {
    int * v1174 = v1063->cache_age;
    int v1327 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v1067 + 68) >> 2)) >> 1)) & 3) * 2)) + ((~(((v1173 ^ ((int)((unsigned int)((int)((unsigned int)(v1067 + 68) >> 2)) >> 1))) | (-(v1173 ^ ((int)((unsigned int)((int)((unsigned int)(v1067 + 68) >> 2)) >> 1))))) >> 31)) & 1);
    int v1175 = v1174[v1327];
    int v1176 = v1174[v1241];
    int v1328 = v1176 + ((int)((unsigned int)(v1176 - v1175) >> 31));
    v1174[v1241] = v1328;
    int * v1178 = v1063->cache_age;
    int v1179 = v1178[v1242];
    int v1330 = v1179 + ((int)((unsigned int)(v1179 - v1175) >> 31));
    v1178[v1242] = v1330;
    int * v1181 = v1063->cache_age;
    v1181[v1327] = 0;
    v1227 = v1327;
  } else {
    int * v1184 = v1063->cache_age;
    int v1334 = 4 + ((((int)((unsigned int)((int)((unsigned int)(v1067 + 68) >> 2)) >> 1)) & 3) * 2);
    int v1185 = v1184[v1334];
    int * v1186 = v1063->cache_tags;
    int v1187 = v1186[v1334];
    int v1188 = v1184[v1242];
    int v1189 = v1186[v1242];
    int * v1190 = v1063->cache_dirty;
    int v1337 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v1067 + 68) >> 2)) >> 1)) & 3) * 2)) + ((((v1185 + ((~(((v1187 ^ -1) | (-(v1187 ^ -1))) >> 31)) & 2)) - (v1188 + ((~(((v1189 ^ -1) | (-(v1189 ^ -1))) >> 31)) & 2))) >> 31) & 1);
    int v1191 = v1190[v1337];
    bool v1338 = !(v1191 == 0);
    if (v1338) {
      int * v1192 = v1063->cache_tags;
      int v1193 = v1192[v1337];
      int * v1194 = v1063->cache_vals;
      int v1341 = ((4 + ((((int)((unsigned int)((int)((unsigned int)(v1067 + 68) >> 2)) >> 1)) & 3) * 2)) + ((((v1185 + ((~(((v1187 ^ -1) | (-(v1187 ^ -1))) >> 31)) & 2)) - (v1188 + ((~(((v1189 ^ -1) | (-(v1189 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
      int v1195 = v1194[v1341];
      int v1342 = (((4 + ((((int)((unsigned int)((int)((unsigned int)(v1067 + 68) >> 2)) >> 1)) & 3) * 2)) + ((((v1185 + ((~(((v1187 ^ -1) | (-(v1187 ^ -1))) >> 31)) & 2)) - (v1188 + ((~(((v1189 ^ -1) | (-(v1189 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
      int v1196 = v1194[v1342];
      int * v1197 = v1063->mem;
      int v1344 = v1193 * 2;
      v1197[v1344] = v1195;
      int * v1199 = v1063->mem;
      int v1347 = (v1193 * 2) + 1;
      v1199[v1347] = v1196;
      ;
    } else {
      ;
    }
    int * v1204 = v1063->mem;
    int v1352 = ((int)((unsigned int)((int)((unsigned int)(v1067 + 68) >> 2)) >> 1)) * 2;
    int v1205 = v1204[v1352];
    int v1353 = (((int)((unsigned int)((int)((unsigned int)(v1067 + 68) >> 2)) >> 1)) * 2) + 1;
    int v1206 = v1204[v1353];
    int * v1207 = v1063->cache_vals;
    int v1355 = ((4 + ((((int)((unsigned int)((int)((unsigned int)(v1067 + 68) >> 2)) >> 1)) & 3) * 2)) + ((((v1185 + ((~(((v1187 ^ -1) | (-(v1187 ^ -1))) >> 31)) & 2)) - (v1188 + ((~(((v1189 ^ -1) | (-(v1189 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
    v1207[v1355] = v1205;
    int * v1209 = v1063->cache_vals;
    int v1358 = (((4 + ((((int)((unsigned int)((int)((unsigned int)(v1067 + 68) >> 2)) >> 1)) & 3) * 2)) + ((((v1185 + ((~(((v1187 ^ -1) | (-(v1187 ^ -1))) >> 31)) & 2)) - (v1188 + ((~(((v1189 ^ -1) | (-(v1189 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
    v1209[v1358] = v1206;
    int * v1211 = v1063->cache_tags;
    int v1361 = (int)((unsigned int)((int)((unsigned int)(v1067 + 68) >> 2)) >> 1);
    v1211[v1337] = v1361;
    int * v1213 = v1063->cache_dirty;
    v1213[v1337] = 0;
    int * v1215 = v1063->cache_age;
    v1215[v1337] = 1;
    int * v1217 = v1063->cache_age;
    int v1218 = v1217[v1337];
    int v1219 = v1217[v1241];
    int v1367 = v1219 + ((int)((unsigned int)(v1219 - v1218) >> 31));
    v1217[v1241] = v1367;
    int * v1221 = v1063->cache_age;
    int v1222 = v1221[v1242];
    int v1369 = v1222 + ((int)((unsigned int)(v1222 - v1218) >> 31));
    v1221[v1242] = v1369;
    int * v1224 = v1063->cache_age;
    v1224[v1337] = 0;
    v1227 = v1337;
  }
  int * v1228 = v1063->cache_vals;
  int v1372 = (v1227 * 2) + (((int)((unsigned int)(v1067 + 68) >> 2)) & 1);
  v1228[v1372] = v1068;
  int * v1230 = v1063->cache_dirty;
  v1230[v1227] = 1;
  struct StateT * v1232 = slot_9(v1063);
  return v1232;
}

struct StateT * slot_9(struct StateT * v536) {
  int v537 = v536->timer;
  int v540 = v537 + 1;
  v536->timer = v540;
  return v536;
}

struct StateT * slot_0(struct StateT * v2) {
  int v3 = v2->timer;
  int v9 = v3 + 1;
  v2->timer = v9;
  int * v5 = v2->regs;
  v5[12] = 0;
  struct StateT * v7 = slot_1(v2);
  return v7;
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
  int k = bounded(0, 20);
  s1.regs[11] = k;
  s2.regs[11] = k;
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