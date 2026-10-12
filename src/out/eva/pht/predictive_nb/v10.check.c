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

struct StateT * slot_12(struct StateT * v595);
struct StateT * slot_14(struct StateT * v641);
struct StateT * slot_6(struct StateT * v305);
struct StateT * slot_16(struct StateT * v1063);
struct StateT * slot_5(struct StateT * v284);
struct StateT * slot_17(struct StateT * v1087);
struct StateT * slot_2(struct StateT * v225);
struct StateT * slot_7(struct StateT * v329);
struct StateT * slot_3(struct StateT * v233);
struct StateT * snippet(struct StateT * v0);
struct StateT * slot_10(struct StateT * v587);
struct StateT * slot_1(struct StateT * v18);
struct StateT * slot_8(struct StateT * v536);
struct StateT * slot_4(struct StateT * v261);
struct StateT * slot_13(struct StateT * v618);
struct StateT * slot_15(struct StateT * v848);
struct StateT * slot_18(struct StateT * v1146);
struct StateT * slot_9(struct StateT * v582);
struct StateT * slot_0(struct StateT * v2);
struct StateT * slot_12(struct StateT * v595) {
  int * v596 = v595->saved_regs;
  int * v597 = v595->regs;
  int v598 = v597[10];
  v596[10] = v598;
  int v600 = v595->timer;
  int v612 = v600 + 1;
  v595->timer = v612;
  int * v602 = v595->reg_ready;
  v602[10] = v612;
  int * v604 = v595->regs;
  v604[10] = 0;
  struct StateT * v606 = slot_13(v595);
  return v606;
}

struct StateT * slot_14(struct StateT * v641) {
  int v642 = v641->timer;
  int v754 = v642 + 1;
  v641->timer = v754;
  int * v644 = v641->reg_ready;
  int v645 = v644[10];
  int * v646 = v641->regs;
  int v647 = v646[10];
  int * v648 = v641->cache_tags;
  int v759 = (((int)((unsigned int)((int)((unsigned int)(v647 + 4) >> 2)) >> 1)) & 1) * 2;
  int v649 = v648[v759];
  int v760 = ((((int)((unsigned int)((int)((unsigned int)(v647 + 4) >> 2)) >> 1)) & 1) * 2) + 1;
  int v650 = v648[v760];
  int v761 = 4 + ((((int)((unsigned int)((int)((unsigned int)(v647 + 4) >> 2)) >> 1)) & 3) * 2);
  int v651 = v648[v761];
  int v762 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v647 + 4) >> 2)) >> 1)) & 3) * 2)) + 1;
  int v652 = v648[v762];
  int * v653 = v641->cache_vals;
  bool v763 = !(((~(((v649 ^ ((int)((unsigned int)((int)((unsigned int)(v647 + 4) >> 2)) >> 1))) | (-(v649 ^ ((int)((unsigned int)((int)((unsigned int)(v647 + 4) >> 2)) >> 1))))) >> 31)) | (~(((v650 ^ ((int)((unsigned int)((int)((unsigned int)(v647 + 4) >> 2)) >> 1))) | (-(v650 ^ ((int)((unsigned int)((int)((unsigned int)(v647 + 4) >> 2)) >> 1))))) >> 31))) == 0);
  int v746;
  if (v763) {
    int * v654 = v641->cache_age;
    int v765 = ((((int)((unsigned int)((int)((unsigned int)(v647 + 4) >> 2)) >> 1)) & 1) * 2) + ((~(((v650 ^ ((int)((unsigned int)((int)((unsigned int)(v647 + 4) >> 2)) >> 1))) | (-(v650 ^ ((int)((unsigned int)((int)((unsigned int)(v647 + 4) >> 2)) >> 1))))) >> 31)) & 1);
    int v655 = v654[v765];
    int v656 = v654[v759];
    int v766 = v656 + ((int)((unsigned int)(v656 - v655) >> 31));
    v654[v759] = v766;
    int * v658 = v641->cache_age;
    int v659 = v658[v760];
    int v768 = v659 + ((int)((unsigned int)(v659 - v655) >> 31));
    v658[v760] = v768;
    int * v661 = v641->cache_age;
    v661[v765] = 0;
    v746 = v765;
  } else {
    int * v664 = v641->cache_age;
    int v772 = (((int)((unsigned int)((int)((unsigned int)(v647 + 4) >> 2)) >> 1)) & 1) * 2;
    int v665 = v664[v772];
    int * v666 = v641->cache_tags;
    int v667 = v666[v772];
    int v668 = v664[v760];
    int v669 = v666[v760];
    bool v774 = !(((~(((v651 ^ ((int)((unsigned int)((int)((unsigned int)(v647 + 4) >> 2)) >> 1))) | (-(v651 ^ ((int)((unsigned int)((int)((unsigned int)(v647 + 4) >> 2)) >> 1))))) >> 31)) | (~(((v652 ^ ((int)((unsigned int)((int)((unsigned int)(v647 + 4) >> 2)) >> 1))) | (-(v652 ^ ((int)((unsigned int)((int)((unsigned int)(v647 + 4) >> 2)) >> 1))))) >> 31))) == 0);
    int v723;
    if (v774) {
      int * v670 = v641->cache_age;
      int v776 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v647 + 4) >> 2)) >> 1)) & 3) * 2)) + ((~(((v652 ^ ((int)((unsigned int)((int)((unsigned int)(v647 + 4) >> 2)) >> 1))) | (-(v652 ^ ((int)((unsigned int)((int)((unsigned int)(v647 + 4) >> 2)) >> 1))))) >> 31)) & 1);
      int v671 = v670[v776];
      int v672 = v670[v761];
      int v777 = v672 + ((int)((unsigned int)(v672 - v671) >> 31));
      v670[v761] = v777;
      int * v674 = v641->cache_age;
      int v675 = v674[v762];
      int v779 = v675 + ((int)((unsigned int)(v675 - v671) >> 31));
      v674[v762] = v779;
      int * v677 = v641->cache_age;
      v677[v776] = 0;
      v723 = v776;
    } else {
      int * v680 = v641->cache_age;
      int v783 = 4 + ((((int)((unsigned int)((int)((unsigned int)(v647 + 4) >> 2)) >> 1)) & 3) * 2);
      int v681 = v680[v783];
      int * v682 = v641->cache_tags;
      int v683 = v682[v783];
      int v684 = v680[v762];
      int v685 = v682[v762];
      int * v686 = v641->cache_dirty;
      int v786 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v647 + 4) >> 2)) >> 1)) & 3) * 2)) + ((((v681 + ((~(((v683 ^ -1) | (-(v683 ^ -1))) >> 31)) & 2)) - (v684 + ((~(((v685 ^ -1) | (-(v685 ^ -1))) >> 31)) & 2))) >> 31) & 1);
      int v687 = v686[v786];
      bool v787 = !(v687 == 0);
      if (v787) {
        int * v688 = v641->cache_tags;
        int v689 = v688[v786];
        int * v690 = v641->cache_vals;
        int v790 = ((4 + ((((int)((unsigned int)((int)((unsigned int)(v647 + 4) >> 2)) >> 1)) & 3) * 2)) + ((((v681 + ((~(((v683 ^ -1) | (-(v683 ^ -1))) >> 31)) & 2)) - (v684 + ((~(((v685 ^ -1) | (-(v685 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
        int v691 = v690[v790];
        int v791 = (((4 + ((((int)((unsigned int)((int)((unsigned int)(v647 + 4) >> 2)) >> 1)) & 3) * 2)) + ((((v681 + ((~(((v683 ^ -1) | (-(v683 ^ -1))) >> 31)) & 2)) - (v684 + ((~(((v685 ^ -1) | (-(v685 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
        int v692 = v690[v791];
        int * v693 = v641->mem;
        int v793 = v689 * 2;
        v693[v793] = v691;
        int * v695 = v641->mem;
        int v796 = (v689 * 2) + 1;
        v695[v796] = v692;
        ;
      } else {
        ;
      }
      int * v700 = v641->mem;
      int v801 = ((int)((unsigned int)((int)((unsigned int)(v647 + 4) >> 2)) >> 1)) * 2;
      int v701 = v700[v801];
      int v802 = (((int)((unsigned int)((int)((unsigned int)(v647 + 4) >> 2)) >> 1)) * 2) + 1;
      int v702 = v700[v802];
      int * v703 = v641->cache_vals;
      int v804 = ((4 + ((((int)((unsigned int)((int)((unsigned int)(v647 + 4) >> 2)) >> 1)) & 3) * 2)) + ((((v681 + ((~(((v683 ^ -1) | (-(v683 ^ -1))) >> 31)) & 2)) - (v684 + ((~(((v685 ^ -1) | (-(v685 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
      v703[v804] = v701;
      int * v705 = v641->cache_vals;
      int v807 = (((4 + ((((int)((unsigned int)((int)((unsigned int)(v647 + 4) >> 2)) >> 1)) & 3) * 2)) + ((((v681 + ((~(((v683 ^ -1) | (-(v683 ^ -1))) >> 31)) & 2)) - (v684 + ((~(((v685 ^ -1) | (-(v685 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
      v705[v807] = v702;
      int * v707 = v641->cache_tags;
      int v810 = (int)((unsigned int)((int)((unsigned int)(v647 + 4) >> 2)) >> 1);
      v707[v786] = v810;
      int * v709 = v641->cache_dirty;
      v709[v786] = 0;
      int * v711 = v641->cache_age;
      v711[v786] = 1;
      int * v713 = v641->cache_age;
      int v714 = v713[v786];
      int v715 = v713[v761];
      int v816 = v715 + ((int)((unsigned int)(v715 - v714) >> 31));
      v713[v761] = v816;
      int * v717 = v641->cache_age;
      int v718 = v717[v762];
      int v818 = v718 + ((int)((unsigned int)(v718 - v714) >> 31));
      v717[v762] = v818;
      int * v720 = v641->cache_age;
      v720[v786] = 0;
      v723 = v786;
    }
    int * v724 = v641->cache_vals;
    int v821 = v723 * 2;
    int v725 = v724[v821];
    int v822 = (v723 * 2) + 1;
    int v726 = v724[v822];
    int v823 = (((((int)((unsigned int)((int)((unsigned int)(v647 + 4) >> 2)) >> 1)) & 1) * 2) + ((((v665 + ((~(((v667 ^ -1) | (-(v667 ^ -1))) >> 31)) & 2)) - (v668 + ((~(((v669 ^ -1) | (-(v669 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
    v724[v823] = v725;
    int * v728 = v641->cache_vals;
    int v826 = ((((((int)((unsigned int)((int)((unsigned int)(v647 + 4) >> 2)) >> 1)) & 1) * 2) + ((((v665 + ((~(((v667 ^ -1) | (-(v667 ^ -1))) >> 31)) & 2)) - (v668 + ((~(((v669 ^ -1) | (-(v669 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
    v728[v826] = v726;
    int * v730 = v641->cache_tags;
    int v829 = ((((int)((unsigned int)((int)((unsigned int)(v647 + 4) >> 2)) >> 1)) & 1) * 2) + ((((v665 + ((~(((v667 ^ -1) | (-(v667 ^ -1))) >> 31)) & 2)) - (v668 + ((~(((v669 ^ -1) | (-(v669 ^ -1))) >> 31)) & 2))) >> 31) & 1);
    int v830 = (int)((unsigned int)((int)((unsigned int)(v647 + 4) >> 2)) >> 1);
    v730[v829] = v830;
    int * v732 = v641->cache_dirty;
    v732[v829] = 0;
    int * v734 = v641->cache_age;
    v734[v829] = 1;
    int * v736 = v641->cache_age;
    int v737 = v736[v829];
    int v738 = v736[v759];
    int v836 = v738 + ((int)((unsigned int)(v738 - v737) >> 31));
    v736[v759] = v836;
    int * v740 = v641->cache_age;
    int v741 = v740[v760];
    int v838 = v741 + ((int)((unsigned int)(v741 - v737) >> 31));
    v740[v760] = v838;
    int * v743 = v641->cache_age;
    v743[v829] = 0;
    v746 = v829;
  }
  int v841 = (v746 * 2) + (((int)((unsigned int)(v647 + 4) >> 2)) & 1);
  int v747 = v653[v841];
  int * v748 = v641->reg_ready;
  int v843 = ((v645 + ((v642 - v645) & (~((v642 - v645) >> 31)))) + 1) + ((100 ^ (((~(((v651 ^ ((int)((unsigned int)((int)((unsigned int)(v647 + 4) >> 2)) >> 1))) | (-(v651 ^ ((int)((unsigned int)((int)((unsigned int)(v647 + 4) >> 2)) >> 1))))) >> 31)) | (~(((v652 ^ ((int)((unsigned int)((int)((unsigned int)(v647 + 4) >> 2)) >> 1))) | (-(v652 ^ ((int)((unsigned int)((int)((unsigned int)(v647 + 4) >> 2)) >> 1))))) >> 31))) & 104)) ^ (((~(((v649 ^ ((int)((unsigned int)((int)((unsigned int)(v647 + 4) >> 2)) >> 1))) | (-(v649 ^ ((int)((unsigned int)((int)((unsigned int)(v647 + 4) >> 2)) >> 1))))) >> 31)) | (~(((v650 ^ ((int)((unsigned int)((int)((unsigned int)(v647 + 4) >> 2)) >> 1))) | (-(v650 ^ ((int)((unsigned int)((int)((unsigned int)(v647 + 4) >> 2)) >> 1))))) >> 31))) & (1 ^ (100 ^ (((~(((v651 ^ ((int)((unsigned int)((int)((unsigned int)(v647 + 4) >> 2)) >> 1))) | (-(v651 ^ ((int)((unsigned int)((int)((unsigned int)(v647 + 4) >> 2)) >> 1))))) >> 31)) | (~(((v652 ^ ((int)((unsigned int)((int)((unsigned int)(v647 + 4) >> 2)) >> 1))) | (-(v652 ^ ((int)((unsigned int)((int)((unsigned int)(v647 + 4) >> 2)) >> 1))))) >> 31))) & 104)))));
  v748[10] = v843;
  int * v750 = v641->regs;
  v750[10] = v747;
  struct StateT * v752 = slot_15(v641);
  return v752;
}

struct StateT * slot_6(struct StateT * v305) {
  int v306 = v305->timer;
  int v319 = v306 + 1;
  v305->timer = v319;
  int * v308 = v305->reg_ready;
  int v309 = v308[12];
  int * v310 = v305->regs;
  int v311 = v310[12];
  int v312 = v308[10];
  int v313 = v310[10];
  int v324 = (v312 + (((v309 + ((v306 - v309) & (~((v306 - v309) >> 31)))) - v312) & (~(((v309 + ((v306 - v309) & (~((v306 - v309) >> 31)))) - v312) >> 31)))) + 1;
  v308[10] = v324;
  int * v315 = v305->regs;
  int v326 = v311 + v313;
  v315[10] = v326;
  struct StateT * v317 = slot_7(v305);
  return v317;
}

struct StateT * slot_16(struct StateT * v1063) {
  int v1064 = v1063->timer;
  int v1077 = v1064 + 1;
  v1063->timer = v1077;
  int * v1066 = v1063->reg_ready;
  int v1067 = v1066[12];
  int * v1068 = v1063->regs;
  int v1069 = v1068[12];
  int v1070 = v1066[10];
  int v1071 = v1068[10];
  int v1082 = (v1070 + (((v1067 + ((v1064 - v1067) & (~((v1064 - v1067) >> 31)))) - v1070) & (~(((v1067 + ((v1064 - v1067) & (~((v1064 - v1067) >> 31)))) - v1070) >> 31)))) + 1;
  v1066[10] = v1082;
  int * v1073 = v1063->regs;
  int v1084 = v1069 & v1071;
  v1073[10] = v1084;
  struct StateT * v1075 = slot_17(v1063);
  return v1075;
}

struct StateT * slot_5(struct StateT * v284) {
  int v285 = v284->timer;
  int v296 = v285 + 1;
  v284->timer = v296;
  int * v287 = v284->reg_ready;
  int v288 = v287[12];
  int * v289 = v284->regs;
  int v290 = v289[12];
  int v300 = (v288 + ((v285 - v288) & (~((v285 - v288) >> 31)))) + 1;
  v287[12] = v300;
  int * v292 = v284->regs;
  int v302 = v290 + 72;
  v292[12] = v302;
  struct StateT * v294 = slot_6(v284);
  return v294;
}

struct StateT * slot_17(struct StateT * v1087) {
  int * v1088 = v1087->saved_regs;
  int v1089 = v1088[10];
  int v1090 = v1088[11];
  bool v1123 = !(v1089 == v1090);
  struct StateT * v1118;
  if (v1123) {
    int v1091 = v1087->timer;
    int v1124 = v1091 + 15;
    v1087->timer = v1124;
    int * v1093 = v1087->saved_regs;
    int v1094 = v1093[10];
    int * v1095 = v1087->regs;
    v1095[10] = v1094;
    int * v1097 = v1087->saved_regs;
    int v1098 = v1097[11];
    int * v1099 = v1087->regs;
    v1099[11] = v1098;
    int * v1101 = v1087->saved_regs;
    int v1102 = v1101[12];
    int * v1103 = v1087->regs;
    v1103[12] = v1102;
    int * v1105 = v1087->reg_ready;
    int v1106 = v1087->timer;
    v1105[10] = v1106;
    int * v1108 = v1087->reg_ready;
    int v1109 = v1087->timer;
    v1108[11] = v1109;
    int * v1111 = v1087->reg_ready;
    int v1112 = v1087->timer;
    v1111[12] = v1112;
    struct StateT * v1114 = slot_9(v1087);
    v1118 = v1114;
  } else {
    struct StateT * v1116 = slot_18(v1087);
    v1118 = v1116;
  }
  return v1118;
}

struct StateT * slot_2(struct StateT * v225) {
  int v226 = v225->timer;
  int v230 = v226 + 1;
  v225->timer = v230;
  struct StateT * v228 = slot_3(v225);
  return v228;
}

struct StateT * slot_7(struct StateT * v329) {
  int v330 = v329->timer;
  int v442 = v330 + 1;
  v329->timer = v442;
  int * v332 = v329->reg_ready;
  int v333 = v332[10];
  int * v334 = v329->regs;
  int v335 = v334[10];
  int * v336 = v329->cache_tags;
  int v447 = (((int)((unsigned int)((int)((unsigned int)v335 >> 2)) >> 1)) & 1) * 2;
  int v337 = v336[v447];
  int v448 = ((((int)((unsigned int)((int)((unsigned int)v335 >> 2)) >> 1)) & 1) * 2) + 1;
  int v338 = v336[v448];
  int v449 = 4 + ((((int)((unsigned int)((int)((unsigned int)v335 >> 2)) >> 1)) & 3) * 2);
  int v339 = v336[v449];
  int v450 = (4 + ((((int)((unsigned int)((int)((unsigned int)v335 >> 2)) >> 1)) & 3) * 2)) + 1;
  int v340 = v336[v450];
  int * v341 = v329->cache_vals;
  bool v451 = !(((~(((v337 ^ ((int)((unsigned int)((int)((unsigned int)v335 >> 2)) >> 1))) | (-(v337 ^ ((int)((unsigned int)((int)((unsigned int)v335 >> 2)) >> 1))))) >> 31)) | (~(((v338 ^ ((int)((unsigned int)((int)((unsigned int)v335 >> 2)) >> 1))) | (-(v338 ^ ((int)((unsigned int)((int)((unsigned int)v335 >> 2)) >> 1))))) >> 31))) == 0);
  int v434;
  if (v451) {
    int * v342 = v329->cache_age;
    int v453 = ((((int)((unsigned int)((int)((unsigned int)v335 >> 2)) >> 1)) & 1) * 2) + ((~(((v338 ^ ((int)((unsigned int)((int)((unsigned int)v335 >> 2)) >> 1))) | (-(v338 ^ ((int)((unsigned int)((int)((unsigned int)v335 >> 2)) >> 1))))) >> 31)) & 1);
    int v343 = v342[v453];
    int v344 = v342[v447];
    int v454 = v344 + ((int)((unsigned int)(v344 - v343) >> 31));
    v342[v447] = v454;
    int * v346 = v329->cache_age;
    int v347 = v346[v448];
    int v456 = v347 + ((int)((unsigned int)(v347 - v343) >> 31));
    v346[v448] = v456;
    int * v349 = v329->cache_age;
    v349[v453] = 0;
    v434 = v453;
  } else {
    int * v352 = v329->cache_age;
    int v460 = (((int)((unsigned int)((int)((unsigned int)v335 >> 2)) >> 1)) & 1) * 2;
    int v353 = v352[v460];
    int * v354 = v329->cache_tags;
    int v355 = v354[v460];
    int v356 = v352[v448];
    int v357 = v354[v448];
    bool v462 = !(((~(((v339 ^ ((int)((unsigned int)((int)((unsigned int)v335 >> 2)) >> 1))) | (-(v339 ^ ((int)((unsigned int)((int)((unsigned int)v335 >> 2)) >> 1))))) >> 31)) | (~(((v340 ^ ((int)((unsigned int)((int)((unsigned int)v335 >> 2)) >> 1))) | (-(v340 ^ ((int)((unsigned int)((int)((unsigned int)v335 >> 2)) >> 1))))) >> 31))) == 0);
    int v411;
    if (v462) {
      int * v358 = v329->cache_age;
      int v464 = (4 + ((((int)((unsigned int)((int)((unsigned int)v335 >> 2)) >> 1)) & 3) * 2)) + ((~(((v340 ^ ((int)((unsigned int)((int)((unsigned int)v335 >> 2)) >> 1))) | (-(v340 ^ ((int)((unsigned int)((int)((unsigned int)v335 >> 2)) >> 1))))) >> 31)) & 1);
      int v359 = v358[v464];
      int v360 = v358[v449];
      int v465 = v360 + ((int)((unsigned int)(v360 - v359) >> 31));
      v358[v449] = v465;
      int * v362 = v329->cache_age;
      int v363 = v362[v450];
      int v467 = v363 + ((int)((unsigned int)(v363 - v359) >> 31));
      v362[v450] = v467;
      int * v365 = v329->cache_age;
      v365[v464] = 0;
      v411 = v464;
    } else {
      int * v368 = v329->cache_age;
      int v471 = 4 + ((((int)((unsigned int)((int)((unsigned int)v335 >> 2)) >> 1)) & 3) * 2);
      int v369 = v368[v471];
      int * v370 = v329->cache_tags;
      int v371 = v370[v471];
      int v372 = v368[v450];
      int v373 = v370[v450];
      int * v374 = v329->cache_dirty;
      int v474 = (4 + ((((int)((unsigned int)((int)((unsigned int)v335 >> 2)) >> 1)) & 3) * 2)) + ((((v369 + ((~(((v371 ^ -1) | (-(v371 ^ -1))) >> 31)) & 2)) - (v372 + ((~(((v373 ^ -1) | (-(v373 ^ -1))) >> 31)) & 2))) >> 31) & 1);
      int v375 = v374[v474];
      bool v475 = !(v375 == 0);
      if (v475) {
        int * v376 = v329->cache_tags;
        int v377 = v376[v474];
        int * v378 = v329->cache_vals;
        int v478 = ((4 + ((((int)((unsigned int)((int)((unsigned int)v335 >> 2)) >> 1)) & 3) * 2)) + ((((v369 + ((~(((v371 ^ -1) | (-(v371 ^ -1))) >> 31)) & 2)) - (v372 + ((~(((v373 ^ -1) | (-(v373 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
        int v379 = v378[v478];
        int v479 = (((4 + ((((int)((unsigned int)((int)((unsigned int)v335 >> 2)) >> 1)) & 3) * 2)) + ((((v369 + ((~(((v371 ^ -1) | (-(v371 ^ -1))) >> 31)) & 2)) - (v372 + ((~(((v373 ^ -1) | (-(v373 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
        int v380 = v378[v479];
        int * v381 = v329->mem;
        int v481 = v377 * 2;
        v381[v481] = v379;
        int * v383 = v329->mem;
        int v484 = (v377 * 2) + 1;
        v383[v484] = v380;
        ;
      } else {
        ;
      }
      int * v388 = v329->mem;
      int v489 = ((int)((unsigned int)((int)((unsigned int)v335 >> 2)) >> 1)) * 2;
      int v389 = v388[v489];
      int v490 = (((int)((unsigned int)((int)((unsigned int)v335 >> 2)) >> 1)) * 2) + 1;
      int v390 = v388[v490];
      int * v391 = v329->cache_vals;
      int v492 = ((4 + ((((int)((unsigned int)((int)((unsigned int)v335 >> 2)) >> 1)) & 3) * 2)) + ((((v369 + ((~(((v371 ^ -1) | (-(v371 ^ -1))) >> 31)) & 2)) - (v372 + ((~(((v373 ^ -1) | (-(v373 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
      v391[v492] = v389;
      int * v393 = v329->cache_vals;
      int v495 = (((4 + ((((int)((unsigned int)((int)((unsigned int)v335 >> 2)) >> 1)) & 3) * 2)) + ((((v369 + ((~(((v371 ^ -1) | (-(v371 ^ -1))) >> 31)) & 2)) - (v372 + ((~(((v373 ^ -1) | (-(v373 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
      v393[v495] = v390;
      int * v395 = v329->cache_tags;
      int v498 = (int)((unsigned int)((int)((unsigned int)v335 >> 2)) >> 1);
      v395[v474] = v498;
      int * v397 = v329->cache_dirty;
      v397[v474] = 0;
      int * v399 = v329->cache_age;
      v399[v474] = 1;
      int * v401 = v329->cache_age;
      int v402 = v401[v474];
      int v403 = v401[v449];
      int v504 = v403 + ((int)((unsigned int)(v403 - v402) >> 31));
      v401[v449] = v504;
      int * v405 = v329->cache_age;
      int v406 = v405[v450];
      int v506 = v406 + ((int)((unsigned int)(v406 - v402) >> 31));
      v405[v450] = v506;
      int * v408 = v329->cache_age;
      v408[v474] = 0;
      v411 = v474;
    }
    int * v412 = v329->cache_vals;
    int v509 = v411 * 2;
    int v413 = v412[v509];
    int v510 = (v411 * 2) + 1;
    int v414 = v412[v510];
    int v511 = (((((int)((unsigned int)((int)((unsigned int)v335 >> 2)) >> 1)) & 1) * 2) + ((((v353 + ((~(((v355 ^ -1) | (-(v355 ^ -1))) >> 31)) & 2)) - (v356 + ((~(((v357 ^ -1) | (-(v357 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
    v412[v511] = v413;
    int * v416 = v329->cache_vals;
    int v514 = ((((((int)((unsigned int)((int)((unsigned int)v335 >> 2)) >> 1)) & 1) * 2) + ((((v353 + ((~(((v355 ^ -1) | (-(v355 ^ -1))) >> 31)) & 2)) - (v356 + ((~(((v357 ^ -1) | (-(v357 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
    v416[v514] = v414;
    int * v418 = v329->cache_tags;
    int v517 = ((((int)((unsigned int)((int)((unsigned int)v335 >> 2)) >> 1)) & 1) * 2) + ((((v353 + ((~(((v355 ^ -1) | (-(v355 ^ -1))) >> 31)) & 2)) - (v356 + ((~(((v357 ^ -1) | (-(v357 ^ -1))) >> 31)) & 2))) >> 31) & 1);
    int v518 = (int)((unsigned int)((int)((unsigned int)v335 >> 2)) >> 1);
    v418[v517] = v518;
    int * v420 = v329->cache_dirty;
    v420[v517] = 0;
    int * v422 = v329->cache_age;
    v422[v517] = 1;
    int * v424 = v329->cache_age;
    int v425 = v424[v517];
    int v426 = v424[v447];
    int v524 = v426 + ((int)((unsigned int)(v426 - v425) >> 31));
    v424[v447] = v524;
    int * v428 = v329->cache_age;
    int v429 = v428[v448];
    int v526 = v429 + ((int)((unsigned int)(v429 - v425) >> 31));
    v428[v448] = v526;
    int * v431 = v329->cache_age;
    v431[v517] = 0;
    v434 = v517;
  }
  int v529 = (v434 * 2) + (((int)((unsigned int)v335 >> 2)) & 1);
  int v435 = v341[v529];
  int * v436 = v329->reg_ready;
  int v531 = ((v333 + ((v330 - v333) & (~((v330 - v333) >> 31)))) + 1) + ((100 ^ (((~(((v339 ^ ((int)((unsigned int)((int)((unsigned int)v335 >> 2)) >> 1))) | (-(v339 ^ ((int)((unsigned int)((int)((unsigned int)v335 >> 2)) >> 1))))) >> 31)) | (~(((v340 ^ ((int)((unsigned int)((int)((unsigned int)v335 >> 2)) >> 1))) | (-(v340 ^ ((int)((unsigned int)((int)((unsigned int)v335 >> 2)) >> 1))))) >> 31))) & 104)) ^ (((~(((v337 ^ ((int)((unsigned int)((int)((unsigned int)v335 >> 2)) >> 1))) | (-(v337 ^ ((int)((unsigned int)((int)((unsigned int)v335 >> 2)) >> 1))))) >> 31)) | (~(((v338 ^ ((int)((unsigned int)((int)((unsigned int)v335 >> 2)) >> 1))) | (-(v338 ^ ((int)((unsigned int)((int)((unsigned int)v335 >> 2)) >> 1))))) >> 31))) & (1 ^ (100 ^ (((~(((v339 ^ ((int)((unsigned int)((int)((unsigned int)v335 >> 2)) >> 1))) | (-(v339 ^ ((int)((unsigned int)((int)((unsigned int)v335 >> 2)) >> 1))))) >> 31)) | (~(((v340 ^ ((int)((unsigned int)((int)((unsigned int)v335 >> 2)) >> 1))) | (-(v340 ^ ((int)((unsigned int)((int)((unsigned int)v335 >> 2)) >> 1))))) >> 31))) & 104)))));
  v436[10] = v531;
  int * v438 = v329->regs;
  v438[10] = v435;
  struct StateT * v440 = slot_8(v329);
  return v440;
}

struct StateT * slot_3(struct StateT * v233) {
  int * v234 = v233->saved_regs;
  int * v235 = v233->regs;
  int v236 = v235[10];
  v234[10] = v236;
  int v238 = v233->timer;
  int v253 = v238 + 1;
  v233->timer = v253;
  int * v240 = v233->reg_ready;
  int v241 = v240[10];
  int * v242 = v233->regs;
  int v243 = v242[10];
  int v256 = (v241 + ((v238 - v241) & (~((v238 - v241) >> 31)))) + 1;
  v240[10] = v256;
  int * v245 = v233->regs;
  int v258 = v243 << 2;
  v245[10] = v258;
  struct StateT * v247 = slot_4(v233);
  return v247;
}

struct StateT * snippet(struct StateT * v0) {
  struct StateT * v1 = slot_0(v0);
  int v1465 = v1->timer;
  int * v1466 = v1->reg_ready;
  int v1467 = v1466[0];
  int v1598 = v1467 + ((v1465 - v1467) & (~((v1465 - v1467) >> 31)));
  v1->timer = v1598;
  int v1469 = v1->timer;
  int * v1470 = v1->reg_ready;
  int v1471 = v1470[1];
  int v1601 = v1471 + ((v1469 - v1471) & (~((v1469 - v1471) >> 31)));
  v1->timer = v1601;
  int v1473 = v1->timer;
  int * v1474 = v1->reg_ready;
  int v1475 = v1474[2];
  int v1604 = v1475 + ((v1473 - v1475) & (~((v1473 - v1475) >> 31)));
  v1->timer = v1604;
  int v1477 = v1->timer;
  int * v1478 = v1->reg_ready;
  int v1479 = v1478[3];
  int v1607 = v1479 + ((v1477 - v1479) & (~((v1477 - v1479) >> 31)));
  v1->timer = v1607;
  int v1481 = v1->timer;
  int * v1482 = v1->reg_ready;
  int v1483 = v1482[4];
  int v1610 = v1483 + ((v1481 - v1483) & (~((v1481 - v1483) >> 31)));
  v1->timer = v1610;
  int v1485 = v1->timer;
  int * v1486 = v1->reg_ready;
  int v1487 = v1486[5];
  int v1613 = v1487 + ((v1485 - v1487) & (~((v1485 - v1487) >> 31)));
  v1->timer = v1613;
  int v1489 = v1->timer;
  int * v1490 = v1->reg_ready;
  int v1491 = v1490[6];
  int v1616 = v1491 + ((v1489 - v1491) & (~((v1489 - v1491) >> 31)));
  v1->timer = v1616;
  int v1493 = v1->timer;
  int * v1494 = v1->reg_ready;
  int v1495 = v1494[7];
  int v1619 = v1495 + ((v1493 - v1495) & (~((v1493 - v1495) >> 31)));
  v1->timer = v1619;
  int v1497 = v1->timer;
  int * v1498 = v1->reg_ready;
  int v1499 = v1498[8];
  int v1622 = v1499 + ((v1497 - v1499) & (~((v1497 - v1499) >> 31)));
  v1->timer = v1622;
  int v1501 = v1->timer;
  int * v1502 = v1->reg_ready;
  int v1503 = v1502[9];
  int v1625 = v1503 + ((v1501 - v1503) & (~((v1501 - v1503) >> 31)));
  v1->timer = v1625;
  int v1505 = v1->timer;
  int * v1506 = v1->reg_ready;
  int v1507 = v1506[10];
  int v1628 = v1507 + ((v1505 - v1507) & (~((v1505 - v1507) >> 31)));
  v1->timer = v1628;
  int v1509 = v1->timer;
  int * v1510 = v1->reg_ready;
  int v1511 = v1510[11];
  int v1631 = v1511 + ((v1509 - v1511) & (~((v1509 - v1511) >> 31)));
  v1->timer = v1631;
  int v1513 = v1->timer;
  int * v1514 = v1->reg_ready;
  int v1515 = v1514[12];
  int v1634 = v1515 + ((v1513 - v1515) & (~((v1513 - v1515) >> 31)));
  v1->timer = v1634;
  int v1517 = v1->timer;
  int * v1518 = v1->reg_ready;
  int v1519 = v1518[13];
  int v1637 = v1519 + ((v1517 - v1519) & (~((v1517 - v1519) >> 31)));
  v1->timer = v1637;
  int v1521 = v1->timer;
  int * v1522 = v1->reg_ready;
  int v1523 = v1522[14];
  int v1640 = v1523 + ((v1521 - v1523) & (~((v1521 - v1523) >> 31)));
  v1->timer = v1640;
  int v1525 = v1->timer;
  int * v1526 = v1->reg_ready;
  int v1527 = v1526[15];
  int v1643 = v1527 + ((v1525 - v1527) & (~((v1525 - v1527) >> 31)));
  v1->timer = v1643;
  int v1529 = v1->timer;
  int * v1530 = v1->reg_ready;
  int v1531 = v1530[16];
  int v1646 = v1531 + ((v1529 - v1531) & (~((v1529 - v1531) >> 31)));
  v1->timer = v1646;
  int v1533 = v1->timer;
  int * v1534 = v1->reg_ready;
  int v1535 = v1534[17];
  int v1649 = v1535 + ((v1533 - v1535) & (~((v1533 - v1535) >> 31)));
  v1->timer = v1649;
  int v1537 = v1->timer;
  int * v1538 = v1->reg_ready;
  int v1539 = v1538[18];
  int v1652 = v1539 + ((v1537 - v1539) & (~((v1537 - v1539) >> 31)));
  v1->timer = v1652;
  int v1541 = v1->timer;
  int * v1542 = v1->reg_ready;
  int v1543 = v1542[19];
  int v1655 = v1543 + ((v1541 - v1543) & (~((v1541 - v1543) >> 31)));
  v1->timer = v1655;
  int v1545 = v1->timer;
  int * v1546 = v1->reg_ready;
  int v1547 = v1546[20];
  int v1658 = v1547 + ((v1545 - v1547) & (~((v1545 - v1547) >> 31)));
  v1->timer = v1658;
  int v1549 = v1->timer;
  int * v1550 = v1->reg_ready;
  int v1551 = v1550[21];
  int v1661 = v1551 + ((v1549 - v1551) & (~((v1549 - v1551) >> 31)));
  v1->timer = v1661;
  int v1553 = v1->timer;
  int * v1554 = v1->reg_ready;
  int v1555 = v1554[22];
  int v1664 = v1555 + ((v1553 - v1555) & (~((v1553 - v1555) >> 31)));
  v1->timer = v1664;
  int v1557 = v1->timer;
  int * v1558 = v1->reg_ready;
  int v1559 = v1558[23];
  int v1667 = v1559 + ((v1557 - v1559) & (~((v1557 - v1559) >> 31)));
  v1->timer = v1667;
  int v1561 = v1->timer;
  int * v1562 = v1->reg_ready;
  int v1563 = v1562[24];
  int v1670 = v1563 + ((v1561 - v1563) & (~((v1561 - v1563) >> 31)));
  v1->timer = v1670;
  int v1565 = v1->timer;
  int * v1566 = v1->reg_ready;
  int v1567 = v1566[25];
  int v1673 = v1567 + ((v1565 - v1567) & (~((v1565 - v1567) >> 31)));
  v1->timer = v1673;
  int v1569 = v1->timer;
  int * v1570 = v1->reg_ready;
  int v1571 = v1570[26];
  int v1676 = v1571 + ((v1569 - v1571) & (~((v1569 - v1571) >> 31)));
  v1->timer = v1676;
  int v1573 = v1->timer;
  int * v1574 = v1->reg_ready;
  int v1575 = v1574[27];
  int v1679 = v1575 + ((v1573 - v1575) & (~((v1573 - v1575) >> 31)));
  v1->timer = v1679;
  int v1577 = v1->timer;
  int * v1578 = v1->reg_ready;
  int v1579 = v1578[28];
  int v1682 = v1579 + ((v1577 - v1579) & (~((v1577 - v1579) >> 31)));
  v1->timer = v1682;
  int v1581 = v1->timer;
  int * v1582 = v1->reg_ready;
  int v1583 = v1582[29];
  int v1685 = v1583 + ((v1581 - v1583) & (~((v1581 - v1583) >> 31)));
  v1->timer = v1685;
  int v1585 = v1->timer;
  int * v1586 = v1->reg_ready;
  int v1587 = v1586[30];
  int v1688 = v1587 + ((v1585 - v1587) & (~((v1585 - v1587) >> 31)));
  v1->timer = v1688;
  int v1589 = v1->timer;
  int * v1590 = v1->reg_ready;
  int v1591 = v1590[31];
  int v1691 = v1591 + ((v1589 - v1591) & (~((v1589 - v1591) >> 31)));
  v1->timer = v1691;
  return v1;
}

struct StateT * slot_10(struct StateT * v587) {
  int v588 = v587->timer;
  int v592 = v588 + 1;
  v587->timer = v592;
  struct StateT * v590 = slot_12(v587);
  return v590;
}

struct StateT * slot_1(struct StateT * v18) {
  int v19 = v18->timer;
  int v131 = v19 + 1;
  v18->timer = v131;
  int * v21 = v18->reg_ready;
  int v22 = v21[12];
  int * v23 = v18->regs;
  int v24 = v23[12];
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
  v125[12] = v220;
  int * v127 = v18->regs;
  v127[12] = v124;
  struct StateT * v129 = slot_2(v18);
  return v129;
}

struct StateT * slot_8(struct StateT * v536) {
  int * v537 = v536->saved_regs;
  int v538 = v537[10];
  int v539 = v537[12];
  bool v565 = (v538 ^ -2147483648) >= (v539 ^ -2147483648);
  struct StateT * v560;
  if (v565) {
    int v540 = v536->timer;
    int v566 = v540 + 15;
    v536->timer = v566;
    int * v542 = v536->saved_regs;
    int v543 = v542[10];
    int * v544 = v536->regs;
    v544[10] = v543;
    int * v546 = v536->saved_regs;
    int v547 = v546[12];
    int * v548 = v536->regs;
    v548[12] = v547;
    int * v550 = v536->reg_ready;
    int v551 = v536->timer;
    v550[10] = v551;
    int * v553 = v536->reg_ready;
    int v554 = v536->timer;
    v553[12] = v554;
    struct StateT * v556 = slot_9(v536);
    v560 = v556;
  } else {
    struct StateT * v558 = slot_10(v536);
    v560 = v558;
  }
  return v560;
}

struct StateT * slot_4(struct StateT * v261) {
  int * v262 = v261->saved_regs;
  int * v263 = v261->regs;
  int v264 = v263[12];
  v262[12] = v264;
  int v266 = v261->timer;
  int v278 = v266 + 1;
  v261->timer = v278;
  int * v268 = v261->reg_ready;
  v268[12] = v278;
  int * v270 = v261->regs;
  v270[12] = 0;
  struct StateT * v272 = slot_5(v261);
  return v272;
}

struct StateT * slot_13(struct StateT * v618) {
  int * v619 = v618->saved_regs;
  int * v620 = v618->regs;
  int v621 = v620[11];
  v619[11] = v621;
  int v623 = v618->timer;
  int v635 = v623 + 1;
  v618->timer = v635;
  int * v625 = v618->reg_ready;
  v625[11] = v635;
  int * v627 = v618->regs;
  v627[11] = 0;
  struct StateT * v629 = slot_14(v618);
  return v629;
}

struct StateT * slot_15(struct StateT * v848) {
  int * v849 = v848->saved_regs;
  int * v850 = v848->regs;
  int v851 = v850[12];
  v849[12] = v851;
  int v853 = v848->timer;
  int v969 = v853 + 1;
  v848->timer = v969;
  int * v855 = v848->reg_ready;
  int v856 = v855[11];
  int * v857 = v848->regs;
  int v858 = v857[11];
  int * v859 = v848->cache_tags;
  int v974 = (((int)((unsigned int)((int)((unsigned int)(v858 + 68) >> 2)) >> 1)) & 1) * 2;
  int v860 = v859[v974];
  int v975 = ((((int)((unsigned int)((int)((unsigned int)(v858 + 68) >> 2)) >> 1)) & 1) * 2) + 1;
  int v861 = v859[v975];
  int v976 = 4 + ((((int)((unsigned int)((int)((unsigned int)(v858 + 68) >> 2)) >> 1)) & 3) * 2);
  int v862 = v859[v976];
  int v977 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v858 + 68) >> 2)) >> 1)) & 3) * 2)) + 1;
  int v863 = v859[v977];
  int * v864 = v848->cache_vals;
  bool v978 = !(((~(((v860 ^ ((int)((unsigned int)((int)((unsigned int)(v858 + 68) >> 2)) >> 1))) | (-(v860 ^ ((int)((unsigned int)((int)((unsigned int)(v858 + 68) >> 2)) >> 1))))) >> 31)) | (~(((v861 ^ ((int)((unsigned int)((int)((unsigned int)(v858 + 68) >> 2)) >> 1))) | (-(v861 ^ ((int)((unsigned int)((int)((unsigned int)(v858 + 68) >> 2)) >> 1))))) >> 31))) == 0);
  int v957;
  if (v978) {
    int * v865 = v848->cache_age;
    int v980 = ((((int)((unsigned int)((int)((unsigned int)(v858 + 68) >> 2)) >> 1)) & 1) * 2) + ((~(((v861 ^ ((int)((unsigned int)((int)((unsigned int)(v858 + 68) >> 2)) >> 1))) | (-(v861 ^ ((int)((unsigned int)((int)((unsigned int)(v858 + 68) >> 2)) >> 1))))) >> 31)) & 1);
    int v866 = v865[v980];
    int v867 = v865[v974];
    int v981 = v867 + ((int)((unsigned int)(v867 - v866) >> 31));
    v865[v974] = v981;
    int * v869 = v848->cache_age;
    int v870 = v869[v975];
    int v983 = v870 + ((int)((unsigned int)(v870 - v866) >> 31));
    v869[v975] = v983;
    int * v872 = v848->cache_age;
    v872[v980] = 0;
    v957 = v980;
  } else {
    int * v875 = v848->cache_age;
    int v987 = (((int)((unsigned int)((int)((unsigned int)(v858 + 68) >> 2)) >> 1)) & 1) * 2;
    int v876 = v875[v987];
    int * v877 = v848->cache_tags;
    int v878 = v877[v987];
    int v879 = v875[v975];
    int v880 = v877[v975];
    bool v989 = !(((~(((v862 ^ ((int)((unsigned int)((int)((unsigned int)(v858 + 68) >> 2)) >> 1))) | (-(v862 ^ ((int)((unsigned int)((int)((unsigned int)(v858 + 68) >> 2)) >> 1))))) >> 31)) | (~(((v863 ^ ((int)((unsigned int)((int)((unsigned int)(v858 + 68) >> 2)) >> 1))) | (-(v863 ^ ((int)((unsigned int)((int)((unsigned int)(v858 + 68) >> 2)) >> 1))))) >> 31))) == 0);
    int v934;
    if (v989) {
      int * v881 = v848->cache_age;
      int v991 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v858 + 68) >> 2)) >> 1)) & 3) * 2)) + ((~(((v863 ^ ((int)((unsigned int)((int)((unsigned int)(v858 + 68) >> 2)) >> 1))) | (-(v863 ^ ((int)((unsigned int)((int)((unsigned int)(v858 + 68) >> 2)) >> 1))))) >> 31)) & 1);
      int v882 = v881[v991];
      int v883 = v881[v976];
      int v992 = v883 + ((int)((unsigned int)(v883 - v882) >> 31));
      v881[v976] = v992;
      int * v885 = v848->cache_age;
      int v886 = v885[v977];
      int v994 = v886 + ((int)((unsigned int)(v886 - v882) >> 31));
      v885[v977] = v994;
      int * v888 = v848->cache_age;
      v888[v991] = 0;
      v934 = v991;
    } else {
      int * v891 = v848->cache_age;
      int v998 = 4 + ((((int)((unsigned int)((int)((unsigned int)(v858 + 68) >> 2)) >> 1)) & 3) * 2);
      int v892 = v891[v998];
      int * v893 = v848->cache_tags;
      int v894 = v893[v998];
      int v895 = v891[v977];
      int v896 = v893[v977];
      int * v897 = v848->cache_dirty;
      int v1001 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v858 + 68) >> 2)) >> 1)) & 3) * 2)) + ((((v892 + ((~(((v894 ^ -1) | (-(v894 ^ -1))) >> 31)) & 2)) - (v895 + ((~(((v896 ^ -1) | (-(v896 ^ -1))) >> 31)) & 2))) >> 31) & 1);
      int v898 = v897[v1001];
      bool v1002 = !(v898 == 0);
      if (v1002) {
        int * v899 = v848->cache_tags;
        int v900 = v899[v1001];
        int * v901 = v848->cache_vals;
        int v1005 = ((4 + ((((int)((unsigned int)((int)((unsigned int)(v858 + 68) >> 2)) >> 1)) & 3) * 2)) + ((((v892 + ((~(((v894 ^ -1) | (-(v894 ^ -1))) >> 31)) & 2)) - (v895 + ((~(((v896 ^ -1) | (-(v896 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
        int v902 = v901[v1005];
        int v1006 = (((4 + ((((int)((unsigned int)((int)((unsigned int)(v858 + 68) >> 2)) >> 1)) & 3) * 2)) + ((((v892 + ((~(((v894 ^ -1) | (-(v894 ^ -1))) >> 31)) & 2)) - (v895 + ((~(((v896 ^ -1) | (-(v896 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
        int v903 = v901[v1006];
        int * v904 = v848->mem;
        int v1008 = v900 * 2;
        v904[v1008] = v902;
        int * v906 = v848->mem;
        int v1011 = (v900 * 2) + 1;
        v906[v1011] = v903;
        ;
      } else {
        ;
      }
      int * v911 = v848->mem;
      int v1016 = ((int)((unsigned int)((int)((unsigned int)(v858 + 68) >> 2)) >> 1)) * 2;
      int v912 = v911[v1016];
      int v1017 = (((int)((unsigned int)((int)((unsigned int)(v858 + 68) >> 2)) >> 1)) * 2) + 1;
      int v913 = v911[v1017];
      int * v914 = v848->cache_vals;
      int v1019 = ((4 + ((((int)((unsigned int)((int)((unsigned int)(v858 + 68) >> 2)) >> 1)) & 3) * 2)) + ((((v892 + ((~(((v894 ^ -1) | (-(v894 ^ -1))) >> 31)) & 2)) - (v895 + ((~(((v896 ^ -1) | (-(v896 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
      v914[v1019] = v912;
      int * v916 = v848->cache_vals;
      int v1022 = (((4 + ((((int)((unsigned int)((int)((unsigned int)(v858 + 68) >> 2)) >> 1)) & 3) * 2)) + ((((v892 + ((~(((v894 ^ -1) | (-(v894 ^ -1))) >> 31)) & 2)) - (v895 + ((~(((v896 ^ -1) | (-(v896 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
      v916[v1022] = v913;
      int * v918 = v848->cache_tags;
      int v1025 = (int)((unsigned int)((int)((unsigned int)(v858 + 68) >> 2)) >> 1);
      v918[v1001] = v1025;
      int * v920 = v848->cache_dirty;
      v920[v1001] = 0;
      int * v922 = v848->cache_age;
      v922[v1001] = 1;
      int * v924 = v848->cache_age;
      int v925 = v924[v1001];
      int v926 = v924[v976];
      int v1031 = v926 + ((int)((unsigned int)(v926 - v925) >> 31));
      v924[v976] = v1031;
      int * v928 = v848->cache_age;
      int v929 = v928[v977];
      int v1033 = v929 + ((int)((unsigned int)(v929 - v925) >> 31));
      v928[v977] = v1033;
      int * v931 = v848->cache_age;
      v931[v1001] = 0;
      v934 = v1001;
    }
    int * v935 = v848->cache_vals;
    int v1036 = v934 * 2;
    int v936 = v935[v1036];
    int v1037 = (v934 * 2) + 1;
    int v937 = v935[v1037];
    int v1038 = (((((int)((unsigned int)((int)((unsigned int)(v858 + 68) >> 2)) >> 1)) & 1) * 2) + ((((v876 + ((~(((v878 ^ -1) | (-(v878 ^ -1))) >> 31)) & 2)) - (v879 + ((~(((v880 ^ -1) | (-(v880 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
    v935[v1038] = v936;
    int * v939 = v848->cache_vals;
    int v1041 = ((((((int)((unsigned int)((int)((unsigned int)(v858 + 68) >> 2)) >> 1)) & 1) * 2) + ((((v876 + ((~(((v878 ^ -1) | (-(v878 ^ -1))) >> 31)) & 2)) - (v879 + ((~(((v880 ^ -1) | (-(v880 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
    v939[v1041] = v937;
    int * v941 = v848->cache_tags;
    int v1044 = ((((int)((unsigned int)((int)((unsigned int)(v858 + 68) >> 2)) >> 1)) & 1) * 2) + ((((v876 + ((~(((v878 ^ -1) | (-(v878 ^ -1))) >> 31)) & 2)) - (v879 + ((~(((v880 ^ -1) | (-(v880 ^ -1))) >> 31)) & 2))) >> 31) & 1);
    int v1045 = (int)((unsigned int)((int)((unsigned int)(v858 + 68) >> 2)) >> 1);
    v941[v1044] = v1045;
    int * v943 = v848->cache_dirty;
    v943[v1044] = 0;
    int * v945 = v848->cache_age;
    v945[v1044] = 1;
    int * v947 = v848->cache_age;
    int v948 = v947[v1044];
    int v949 = v947[v974];
    int v1051 = v949 + ((int)((unsigned int)(v949 - v948) >> 31));
    v947[v974] = v1051;
    int * v951 = v848->cache_age;
    int v952 = v951[v975];
    int v1053 = v952 + ((int)((unsigned int)(v952 - v948) >> 31));
    v951[v975] = v1053;
    int * v954 = v848->cache_age;
    v954[v1044] = 0;
    v957 = v1044;
  }
  int v1056 = (v957 * 2) + (((int)((unsigned int)(v858 + 68) >> 2)) & 1);
  int v958 = v864[v1056];
  int * v959 = v848->reg_ready;
  int v1058 = ((v856 + ((v853 - v856) & (~((v853 - v856) >> 31)))) + 1) + ((100 ^ (((~(((v862 ^ ((int)((unsigned int)((int)((unsigned int)(v858 + 68) >> 2)) >> 1))) | (-(v862 ^ ((int)((unsigned int)((int)((unsigned int)(v858 + 68) >> 2)) >> 1))))) >> 31)) | (~(((v863 ^ ((int)((unsigned int)((int)((unsigned int)(v858 + 68) >> 2)) >> 1))) | (-(v863 ^ ((int)((unsigned int)((int)((unsigned int)(v858 + 68) >> 2)) >> 1))))) >> 31))) & 104)) ^ (((~(((v860 ^ ((int)((unsigned int)((int)((unsigned int)(v858 + 68) >> 2)) >> 1))) | (-(v860 ^ ((int)((unsigned int)((int)((unsigned int)(v858 + 68) >> 2)) >> 1))))) >> 31)) | (~(((v861 ^ ((int)((unsigned int)((int)((unsigned int)(v858 + 68) >> 2)) >> 1))) | (-(v861 ^ ((int)((unsigned int)((int)((unsigned int)(v858 + 68) >> 2)) >> 1))))) >> 31))) & (1 ^ (100 ^ (((~(((v862 ^ ((int)((unsigned int)((int)((unsigned int)(v858 + 68) >> 2)) >> 1))) | (-(v862 ^ ((int)((unsigned int)((int)((unsigned int)(v858 + 68) >> 2)) >> 1))))) >> 31)) | (~(((v863 ^ ((int)((unsigned int)((int)((unsigned int)(v858 + 68) >> 2)) >> 1))) | (-(v863 ^ ((int)((unsigned int)((int)((unsigned int)(v858 + 68) >> 2)) >> 1))))) >> 31))) & 104)))));
  v959[12] = v1058;
  int * v961 = v848->regs;
  v961[12] = v958;
  struct StateT * v963 = slot_16(v848);
  return v963;
}

struct StateT * slot_18(struct StateT * v1146) {
  int v1147 = v1146->timer;
  int v1320 = v1147 + 1;
  v1146->timer = v1320;
  int * v1149 = v1146->reg_ready;
  int * v1151 = v1146->regs;
  int v1152 = v1151[11];
  int v1154 = v1151[10];
  int * v1155 = v1146->cache_tags;
  int v1326 = (((int)((unsigned int)((int)((unsigned int)(v1152 + 68) >> 2)) >> 1)) & 1) * 2;
  int v1156 = v1155[v1326];
  int v1327 = ((((int)((unsigned int)((int)((unsigned int)(v1152 + 68) >> 2)) >> 1)) & 1) * 2) + 1;
  int v1157 = v1155[v1327];
  int v1328 = 4 + ((((int)((unsigned int)((int)((unsigned int)(v1152 + 68) >> 2)) >> 1)) & 3) * 2);
  int v1158 = v1155[v1328];
  int v1329 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v1152 + 68) >> 2)) >> 1)) & 3) * 2)) + 1;
  int v1159 = v1155[v1329];
  int v1160 = v1146->timer;
  int v1330 = v1160 + ((100 ^ (((~(((v1158 ^ ((int)((unsigned int)((int)((unsigned int)(v1152 + 68) >> 2)) >> 1))) | (-(v1158 ^ ((int)((unsigned int)((int)((unsigned int)(v1152 + 68) >> 2)) >> 1))))) >> 31)) | (~(((v1159 ^ ((int)((unsigned int)((int)((unsigned int)(v1152 + 68) >> 2)) >> 1))) | (-(v1159 ^ ((int)((unsigned int)((int)((unsigned int)(v1152 + 68) >> 2)) >> 1))))) >> 31))) & 104)) ^ (((~(((v1156 ^ ((int)((unsigned int)((int)((unsigned int)(v1152 + 68) >> 2)) >> 1))) | (-(v1156 ^ ((int)((unsigned int)((int)((unsigned int)(v1152 + 68) >> 2)) >> 1))))) >> 31)) | (~(((v1157 ^ ((int)((unsigned int)((int)((unsigned int)(v1152 + 68) >> 2)) >> 1))) | (-(v1157 ^ ((int)((unsigned int)((int)((unsigned int)(v1152 + 68) >> 2)) >> 1))))) >> 31))) & (1 ^ (100 ^ (((~(((v1158 ^ ((int)((unsigned int)((int)((unsigned int)(v1152 + 68) >> 2)) >> 1))) | (-(v1158 ^ ((int)((unsigned int)((int)((unsigned int)(v1152 + 68) >> 2)) >> 1))))) >> 31)) | (~(((v1159 ^ ((int)((unsigned int)((int)((unsigned int)(v1152 + 68) >> 2)) >> 1))) | (-(v1159 ^ ((int)((unsigned int)((int)((unsigned int)(v1152 + 68) >> 2)) >> 1))))) >> 31))) & 104)))));
  v1146->timer = v1330;
  bool v1331 = !(((~(((v1156 ^ ((int)((unsigned int)((int)((unsigned int)(v1152 + 68) >> 2)) >> 1))) | (-(v1156 ^ ((int)((unsigned int)((int)((unsigned int)(v1152 + 68) >> 2)) >> 1))))) >> 31)) | (~(((v1157 ^ ((int)((unsigned int)((int)((unsigned int)(v1152 + 68) >> 2)) >> 1))) | (-(v1157 ^ ((int)((unsigned int)((int)((unsigned int)(v1152 + 68) >> 2)) >> 1))))) >> 31))) == 0);
  int v1254;
  if (v1331) {
    int * v1162 = v1146->cache_age;
    int v1333 = ((((int)((unsigned int)((int)((unsigned int)(v1152 + 68) >> 2)) >> 1)) & 1) * 2) + ((~(((v1157 ^ ((int)((unsigned int)((int)((unsigned int)(v1152 + 68) >> 2)) >> 1))) | (-(v1157 ^ ((int)((unsigned int)((int)((unsigned int)(v1152 + 68) >> 2)) >> 1))))) >> 31)) & 1);
    int v1163 = v1162[v1333];
    int v1164 = v1162[v1326];
    int v1334 = v1164 + ((int)((unsigned int)(v1164 - v1163) >> 31));
    v1162[v1326] = v1334;
    int * v1166 = v1146->cache_age;
    int v1167 = v1166[v1327];
    int v1336 = v1167 + ((int)((unsigned int)(v1167 - v1163) >> 31));
    v1166[v1327] = v1336;
    int * v1169 = v1146->cache_age;
    v1169[v1333] = 0;
    v1254 = v1333;
  } else {
    int * v1172 = v1146->cache_age;
    int v1340 = (((int)((unsigned int)((int)((unsigned int)(v1152 + 68) >> 2)) >> 1)) & 1) * 2;
    int v1173 = v1172[v1340];
    int * v1174 = v1146->cache_tags;
    int v1175 = v1174[v1340];
    int v1176 = v1172[v1327];
    int v1177 = v1174[v1327];
    bool v1342 = !(((~(((v1158 ^ ((int)((unsigned int)((int)((unsigned int)(v1152 + 68) >> 2)) >> 1))) | (-(v1158 ^ ((int)((unsigned int)((int)((unsigned int)(v1152 + 68) >> 2)) >> 1))))) >> 31)) | (~(((v1159 ^ ((int)((unsigned int)((int)((unsigned int)(v1152 + 68) >> 2)) >> 1))) | (-(v1159 ^ ((int)((unsigned int)((int)((unsigned int)(v1152 + 68) >> 2)) >> 1))))) >> 31))) == 0);
    int v1231;
    if (v1342) {
      int * v1178 = v1146->cache_age;
      int v1344 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v1152 + 68) >> 2)) >> 1)) & 3) * 2)) + ((~(((v1159 ^ ((int)((unsigned int)((int)((unsigned int)(v1152 + 68) >> 2)) >> 1))) | (-(v1159 ^ ((int)((unsigned int)((int)((unsigned int)(v1152 + 68) >> 2)) >> 1))))) >> 31)) & 1);
      int v1179 = v1178[v1344];
      int v1180 = v1178[v1328];
      int v1345 = v1180 + ((int)((unsigned int)(v1180 - v1179) >> 31));
      v1178[v1328] = v1345;
      int * v1182 = v1146->cache_age;
      int v1183 = v1182[v1329];
      int v1347 = v1183 + ((int)((unsigned int)(v1183 - v1179) >> 31));
      v1182[v1329] = v1347;
      int * v1185 = v1146->cache_age;
      v1185[v1344] = 0;
      v1231 = v1344;
    } else {
      int * v1188 = v1146->cache_age;
      int v1351 = 4 + ((((int)((unsigned int)((int)((unsigned int)(v1152 + 68) >> 2)) >> 1)) & 3) * 2);
      int v1189 = v1188[v1351];
      int * v1190 = v1146->cache_tags;
      int v1191 = v1190[v1351];
      int v1192 = v1188[v1329];
      int v1193 = v1190[v1329];
      int * v1194 = v1146->cache_dirty;
      int v1354 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v1152 + 68) >> 2)) >> 1)) & 3) * 2)) + ((((v1189 + ((~(((v1191 ^ -1) | (-(v1191 ^ -1))) >> 31)) & 2)) - (v1192 + ((~(((v1193 ^ -1) | (-(v1193 ^ -1))) >> 31)) & 2))) >> 31) & 1);
      int v1195 = v1194[v1354];
      bool v1355 = !(v1195 == 0);
      if (v1355) {
        int * v1196 = v1146->cache_tags;
        int v1197 = v1196[v1354];
        int * v1198 = v1146->cache_vals;
        int v1358 = ((4 + ((((int)((unsigned int)((int)((unsigned int)(v1152 + 68) >> 2)) >> 1)) & 3) * 2)) + ((((v1189 + ((~(((v1191 ^ -1) | (-(v1191 ^ -1))) >> 31)) & 2)) - (v1192 + ((~(((v1193 ^ -1) | (-(v1193 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
        int v1199 = v1198[v1358];
        int v1359 = (((4 + ((((int)((unsigned int)((int)((unsigned int)(v1152 + 68) >> 2)) >> 1)) & 3) * 2)) + ((((v1189 + ((~(((v1191 ^ -1) | (-(v1191 ^ -1))) >> 31)) & 2)) - (v1192 + ((~(((v1193 ^ -1) | (-(v1193 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
        int v1200 = v1198[v1359];
        int * v1201 = v1146->mem;
        int v1361 = v1197 * 2;
        v1201[v1361] = v1199;
        int * v1203 = v1146->mem;
        int v1364 = (v1197 * 2) + 1;
        v1203[v1364] = v1200;
        ;
      } else {
        ;
      }
      int * v1208 = v1146->mem;
      int v1369 = ((int)((unsigned int)((int)((unsigned int)(v1152 + 68) >> 2)) >> 1)) * 2;
      int v1209 = v1208[v1369];
      int v1370 = (((int)((unsigned int)((int)((unsigned int)(v1152 + 68) >> 2)) >> 1)) * 2) + 1;
      int v1210 = v1208[v1370];
      int * v1211 = v1146->cache_vals;
      int v1372 = ((4 + ((((int)((unsigned int)((int)((unsigned int)(v1152 + 68) >> 2)) >> 1)) & 3) * 2)) + ((((v1189 + ((~(((v1191 ^ -1) | (-(v1191 ^ -1))) >> 31)) & 2)) - (v1192 + ((~(((v1193 ^ -1) | (-(v1193 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
      v1211[v1372] = v1209;
      int * v1213 = v1146->cache_vals;
      int v1375 = (((4 + ((((int)((unsigned int)((int)((unsigned int)(v1152 + 68) >> 2)) >> 1)) & 3) * 2)) + ((((v1189 + ((~(((v1191 ^ -1) | (-(v1191 ^ -1))) >> 31)) & 2)) - (v1192 + ((~(((v1193 ^ -1) | (-(v1193 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
      v1213[v1375] = v1210;
      int * v1215 = v1146->cache_tags;
      int v1378 = (int)((unsigned int)((int)((unsigned int)(v1152 + 68) >> 2)) >> 1);
      v1215[v1354] = v1378;
      int * v1217 = v1146->cache_dirty;
      v1217[v1354] = 0;
      int * v1219 = v1146->cache_age;
      v1219[v1354] = 1;
      int * v1221 = v1146->cache_age;
      int v1222 = v1221[v1354];
      int v1223 = v1221[v1328];
      int v1384 = v1223 + ((int)((unsigned int)(v1223 - v1222) >> 31));
      v1221[v1328] = v1384;
      int * v1225 = v1146->cache_age;
      int v1226 = v1225[v1329];
      int v1386 = v1226 + ((int)((unsigned int)(v1226 - v1222) >> 31));
      v1225[v1329] = v1386;
      int * v1228 = v1146->cache_age;
      v1228[v1354] = 0;
      v1231 = v1354;
    }
    int * v1232 = v1146->cache_vals;
    int v1389 = v1231 * 2;
    int v1233 = v1232[v1389];
    int v1390 = (v1231 * 2) + 1;
    int v1234 = v1232[v1390];
    int v1391 = (((((int)((unsigned int)((int)((unsigned int)(v1152 + 68) >> 2)) >> 1)) & 1) * 2) + ((((v1173 + ((~(((v1175 ^ -1) | (-(v1175 ^ -1))) >> 31)) & 2)) - (v1176 + ((~(((v1177 ^ -1) | (-(v1177 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
    v1232[v1391] = v1233;
    int * v1236 = v1146->cache_vals;
    int v1394 = ((((((int)((unsigned int)((int)((unsigned int)(v1152 + 68) >> 2)) >> 1)) & 1) * 2) + ((((v1173 + ((~(((v1175 ^ -1) | (-(v1175 ^ -1))) >> 31)) & 2)) - (v1176 + ((~(((v1177 ^ -1) | (-(v1177 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
    v1236[v1394] = v1234;
    int * v1238 = v1146->cache_tags;
    int v1397 = ((((int)((unsigned int)((int)((unsigned int)(v1152 + 68) >> 2)) >> 1)) & 1) * 2) + ((((v1173 + ((~(((v1175 ^ -1) | (-(v1175 ^ -1))) >> 31)) & 2)) - (v1176 + ((~(((v1177 ^ -1) | (-(v1177 ^ -1))) >> 31)) & 2))) >> 31) & 1);
    int v1398 = (int)((unsigned int)((int)((unsigned int)(v1152 + 68) >> 2)) >> 1);
    v1238[v1397] = v1398;
    int * v1240 = v1146->cache_dirty;
    v1240[v1397] = 0;
    int * v1242 = v1146->cache_age;
    v1242[v1397] = 1;
    int * v1244 = v1146->cache_age;
    int v1245 = v1244[v1397];
    int v1246 = v1244[v1326];
    int v1404 = v1246 + ((int)((unsigned int)(v1246 - v1245) >> 31));
    v1244[v1326] = v1404;
    int * v1248 = v1146->cache_age;
    int v1249 = v1248[v1327];
    int v1406 = v1249 + ((int)((unsigned int)(v1249 - v1245) >> 31));
    v1248[v1327] = v1406;
    int * v1251 = v1146->cache_age;
    v1251[v1397] = 0;
    v1254 = v1397;
  }
  int * v1255 = v1146->cache_vals;
  int v1409 = (v1254 * 2) + (((int)((unsigned int)(v1152 + 68) >> 2)) & 1);
  v1255[v1409] = v1154;
  int * v1257 = v1146->cache_tags;
  int v1258 = v1257[v1328];
  int v1259 = v1257[v1329];
  bool v1412 = !(((~(((v1258 ^ ((int)((unsigned int)((int)((unsigned int)(v1152 + 68) >> 2)) >> 1))) | (-(v1258 ^ ((int)((unsigned int)((int)((unsigned int)(v1152 + 68) >> 2)) >> 1))))) >> 31)) | (~(((v1259 ^ ((int)((unsigned int)((int)((unsigned int)(v1152 + 68) >> 2)) >> 1))) | (-(v1259 ^ ((int)((unsigned int)((int)((unsigned int)(v1152 + 68) >> 2)) >> 1))))) >> 31))) == 0);
  int v1313;
  if (v1412) {
    int * v1260 = v1146->cache_age;
    int v1414 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v1152 + 68) >> 2)) >> 1)) & 3) * 2)) + ((~(((v1259 ^ ((int)((unsigned int)((int)((unsigned int)(v1152 + 68) >> 2)) >> 1))) | (-(v1259 ^ ((int)((unsigned int)((int)((unsigned int)(v1152 + 68) >> 2)) >> 1))))) >> 31)) & 1);
    int v1261 = v1260[v1414];
    int v1262 = v1260[v1328];
    int v1415 = v1262 + ((int)((unsigned int)(v1262 - v1261) >> 31));
    v1260[v1328] = v1415;
    int * v1264 = v1146->cache_age;
    int v1265 = v1264[v1329];
    int v1417 = v1265 + ((int)((unsigned int)(v1265 - v1261) >> 31));
    v1264[v1329] = v1417;
    int * v1267 = v1146->cache_age;
    v1267[v1414] = 0;
    v1313 = v1414;
  } else {
    int * v1270 = v1146->cache_age;
    int v1421 = 4 + ((((int)((unsigned int)((int)((unsigned int)(v1152 + 68) >> 2)) >> 1)) & 3) * 2);
    int v1271 = v1270[v1421];
    int * v1272 = v1146->cache_tags;
    int v1273 = v1272[v1421];
    int v1274 = v1270[v1329];
    int v1275 = v1272[v1329];
    int * v1276 = v1146->cache_dirty;
    int v1424 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v1152 + 68) >> 2)) >> 1)) & 3) * 2)) + ((((v1271 + ((~(((v1273 ^ -1) | (-(v1273 ^ -1))) >> 31)) & 2)) - (v1274 + ((~(((v1275 ^ -1) | (-(v1275 ^ -1))) >> 31)) & 2))) >> 31) & 1);
    int v1277 = v1276[v1424];
    bool v1425 = !(v1277 == 0);
    if (v1425) {
      int * v1278 = v1146->cache_tags;
      int v1279 = v1278[v1424];
      int * v1280 = v1146->cache_vals;
      int v1428 = ((4 + ((((int)((unsigned int)((int)((unsigned int)(v1152 + 68) >> 2)) >> 1)) & 3) * 2)) + ((((v1271 + ((~(((v1273 ^ -1) | (-(v1273 ^ -1))) >> 31)) & 2)) - (v1274 + ((~(((v1275 ^ -1) | (-(v1275 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
      int v1281 = v1280[v1428];
      int v1429 = (((4 + ((((int)((unsigned int)((int)((unsigned int)(v1152 + 68) >> 2)) >> 1)) & 3) * 2)) + ((((v1271 + ((~(((v1273 ^ -1) | (-(v1273 ^ -1))) >> 31)) & 2)) - (v1274 + ((~(((v1275 ^ -1) | (-(v1275 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
      int v1282 = v1280[v1429];
      int * v1283 = v1146->mem;
      int v1431 = v1279 * 2;
      v1283[v1431] = v1281;
      int * v1285 = v1146->mem;
      int v1434 = (v1279 * 2) + 1;
      v1285[v1434] = v1282;
      ;
    } else {
      ;
    }
    int * v1290 = v1146->mem;
    int v1439 = ((int)((unsigned int)((int)((unsigned int)(v1152 + 68) >> 2)) >> 1)) * 2;
    int v1291 = v1290[v1439];
    int v1440 = (((int)((unsigned int)((int)((unsigned int)(v1152 + 68) >> 2)) >> 1)) * 2) + 1;
    int v1292 = v1290[v1440];
    int * v1293 = v1146->cache_vals;
    int v1442 = ((4 + ((((int)((unsigned int)((int)((unsigned int)(v1152 + 68) >> 2)) >> 1)) & 3) * 2)) + ((((v1271 + ((~(((v1273 ^ -1) | (-(v1273 ^ -1))) >> 31)) & 2)) - (v1274 + ((~(((v1275 ^ -1) | (-(v1275 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
    v1293[v1442] = v1291;
    int * v1295 = v1146->cache_vals;
    int v1445 = (((4 + ((((int)((unsigned int)((int)((unsigned int)(v1152 + 68) >> 2)) >> 1)) & 3) * 2)) + ((((v1271 + ((~(((v1273 ^ -1) | (-(v1273 ^ -1))) >> 31)) & 2)) - (v1274 + ((~(((v1275 ^ -1) | (-(v1275 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
    v1295[v1445] = v1292;
    int * v1297 = v1146->cache_tags;
    int v1448 = (int)((unsigned int)((int)((unsigned int)(v1152 + 68) >> 2)) >> 1);
    v1297[v1424] = v1448;
    int * v1299 = v1146->cache_dirty;
    v1299[v1424] = 0;
    int * v1301 = v1146->cache_age;
    v1301[v1424] = 1;
    int * v1303 = v1146->cache_age;
    int v1304 = v1303[v1424];
    int v1305 = v1303[v1328];
    int v1454 = v1305 + ((int)((unsigned int)(v1305 - v1304) >> 31));
    v1303[v1328] = v1454;
    int * v1307 = v1146->cache_age;
    int v1308 = v1307[v1329];
    int v1456 = v1308 + ((int)((unsigned int)(v1308 - v1304) >> 31));
    v1307[v1329] = v1456;
    int * v1310 = v1146->cache_age;
    v1310[v1424] = 0;
    v1313 = v1424;
  }
  int * v1314 = v1146->cache_vals;
  int v1459 = (v1313 * 2) + (((int)((unsigned int)(v1152 + 68) >> 2)) & 1);
  v1314[v1459] = v1154;
  int * v1316 = v1146->cache_dirty;
  v1316[v1313] = 1;
  struct StateT * v1318 = slot_9(v1146);
  return v1318;
}

struct StateT * slot_9(struct StateT * v582) {
  int v583 = v582->timer;
  int v586 = v583 + 1;
  v582->timer = v586;
  return v582;
}

struct StateT * slot_0(struct StateT * v2) {
  int v3 = v2->timer;
  int v11 = v3 + 1;
  v2->timer = v11;
  int * v5 = v2->reg_ready;
  v5[12] = v11;
  int * v7 = v2->regs;
  v7[12] = 0;
  struct StateT * v9 = slot_1(v2);
  return v9;
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