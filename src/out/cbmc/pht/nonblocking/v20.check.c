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

struct StateT * slot_12(struct StateT * v619);
struct StateT * slot_14(struct StateT * v664);
struct StateT * slot_6(struct StateT * v314);
struct StateT * slot_16(struct StateT * v1079);
struct StateT * slot_5(struct StateT * v293);
struct StateT * slot_17(struct StateT * v1103);
struct StateT * slot_2(struct StateT * v225);
struct StateT * slot_7(struct StateT * v338);
struct StateT * slot_3(struct StateT * v256);
struct StateT * snippet(struct StateT * v0);
struct StateT * slot_10(struct StateT * v582);
struct StateT * slot_1(struct StateT * v18);
struct StateT * slot_8(struct StateT * v545);
struct StateT * slot_4(struct StateT * v277);
struct StateT * slot_13(struct StateT * v640);
struct StateT * slot_15(struct StateT * v871);
struct StateT * slot_18(struct StateT * v251);
struct StateT * slot_9(struct StateT * v561);
struct StateT * slot_11(struct StateT * v598);
struct StateT * slot_0(struct StateT * v2);
struct StateT * slot_12(struct StateT * v619) {
  int v620 = v619->timer;
  int v631 = v620 + 1;
  v619->timer = v631;
  int * v622 = v619->reg_ready;
  int v623 = v622[10];
  int * v624 = v619->regs;
  int v625 = v624[10];
  int v635 = (v623 + ((v620 - v623) & (~((v620 - v623) >> 31)))) + 1;
  v622[10] = v635;
  int * v627 = v619->regs;
  int v637 = (int)((unsigned int)v625 >> 26);
  v627[10] = v637;
  struct StateT * v629 = slot_13(v619);
  return v629;
}

struct StateT * slot_14(struct StateT * v664) {
  int v665 = v664->timer;
  int v777 = v665 + 1;
  v664->timer = v777;
  int * v667 = v664->reg_ready;
  int v668 = v667[10];
  int * v669 = v664->regs;
  int v670 = v669[10];
  int * v671 = v664->cache_tags;
  int v782 = (((int)((unsigned int)((int)((unsigned int)v670 >> 2)) >> 1)) & 1) * 2;
  int v672 = v671[v782];
  int v783 = ((((int)((unsigned int)((int)((unsigned int)v670 >> 2)) >> 1)) & 1) * 2) + 1;
  int v673 = v671[v783];
  int v784 = 4 + ((((int)((unsigned int)((int)((unsigned int)v670 >> 2)) >> 1)) & 3) * 2);
  int v674 = v671[v784];
  int v785 = (4 + ((((int)((unsigned int)((int)((unsigned int)v670 >> 2)) >> 1)) & 3) * 2)) + 1;
  int v675 = v671[v785];
  int * v676 = v664->cache_vals;
  bool v786 = !(((~(((v672 ^ ((int)((unsigned int)((int)((unsigned int)v670 >> 2)) >> 1))) | (-(v672 ^ ((int)((unsigned int)((int)((unsigned int)v670 >> 2)) >> 1))))) >> 31)) | (~(((v673 ^ ((int)((unsigned int)((int)((unsigned int)v670 >> 2)) >> 1))) | (-(v673 ^ ((int)((unsigned int)((int)((unsigned int)v670 >> 2)) >> 1))))) >> 31))) == 0);
  int v769;
  if (v786) {
    int * v677 = v664->cache_age;
    int v788 = ((((int)((unsigned int)((int)((unsigned int)v670 >> 2)) >> 1)) & 1) * 2) + ((~(((v673 ^ ((int)((unsigned int)((int)((unsigned int)v670 >> 2)) >> 1))) | (-(v673 ^ ((int)((unsigned int)((int)((unsigned int)v670 >> 2)) >> 1))))) >> 31)) & 1);
    int v678 = v677[v788];
    int v679 = v677[v782];
    int v789 = v679 + ((int)((unsigned int)(v679 - v678) >> 31));
    v677[v782] = v789;
    int * v681 = v664->cache_age;
    int v682 = v681[v783];
    int v791 = v682 + ((int)((unsigned int)(v682 - v678) >> 31));
    v681[v783] = v791;
    int * v684 = v664->cache_age;
    v684[v788] = 0;
    v769 = v788;
  } else {
    int * v687 = v664->cache_age;
    int v795 = (((int)((unsigned int)((int)((unsigned int)v670 >> 2)) >> 1)) & 1) * 2;
    int v688 = v687[v795];
    int * v689 = v664->cache_tags;
    int v690 = v689[v795];
    int v691 = v687[v783];
    int v692 = v689[v783];
    bool v797 = !(((~(((v674 ^ ((int)((unsigned int)((int)((unsigned int)v670 >> 2)) >> 1))) | (-(v674 ^ ((int)((unsigned int)((int)((unsigned int)v670 >> 2)) >> 1))))) >> 31)) | (~(((v675 ^ ((int)((unsigned int)((int)((unsigned int)v670 >> 2)) >> 1))) | (-(v675 ^ ((int)((unsigned int)((int)((unsigned int)v670 >> 2)) >> 1))))) >> 31))) == 0);
    int v746;
    if (v797) {
      int * v693 = v664->cache_age;
      int v799 = (4 + ((((int)((unsigned int)((int)((unsigned int)v670 >> 2)) >> 1)) & 3) * 2)) + ((~(((v675 ^ ((int)((unsigned int)((int)((unsigned int)v670 >> 2)) >> 1))) | (-(v675 ^ ((int)((unsigned int)((int)((unsigned int)v670 >> 2)) >> 1))))) >> 31)) & 1);
      int v694 = v693[v799];
      int v695 = v693[v784];
      int v800 = v695 + ((int)((unsigned int)(v695 - v694) >> 31));
      v693[v784] = v800;
      int * v697 = v664->cache_age;
      int v698 = v697[v785];
      int v802 = v698 + ((int)((unsigned int)(v698 - v694) >> 31));
      v697[v785] = v802;
      int * v700 = v664->cache_age;
      v700[v799] = 0;
      v746 = v799;
    } else {
      int * v703 = v664->cache_age;
      int v806 = 4 + ((((int)((unsigned int)((int)((unsigned int)v670 >> 2)) >> 1)) & 3) * 2);
      int v704 = v703[v806];
      int * v705 = v664->cache_tags;
      int v706 = v705[v806];
      int v707 = v703[v785];
      int v708 = v705[v785];
      int * v709 = v664->cache_dirty;
      int v809 = (4 + ((((int)((unsigned int)((int)((unsigned int)v670 >> 2)) >> 1)) & 3) * 2)) + ((((v704 + ((~(((v706 ^ -1) | (-(v706 ^ -1))) >> 31)) & 2)) - (v707 + ((~(((v708 ^ -1) | (-(v708 ^ -1))) >> 31)) & 2))) >> 31) & 1);
      int v710 = v709[v809];
      bool v810 = !(v710 == 0);
      if (v810) {
        int * v711 = v664->cache_tags;
        int v712 = v711[v809];
        int * v713 = v664->cache_vals;
        int v813 = ((4 + ((((int)((unsigned int)((int)((unsigned int)v670 >> 2)) >> 1)) & 3) * 2)) + ((((v704 + ((~(((v706 ^ -1) | (-(v706 ^ -1))) >> 31)) & 2)) - (v707 + ((~(((v708 ^ -1) | (-(v708 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
        int v714 = v713[v813];
        int v814 = (((4 + ((((int)((unsigned int)((int)((unsigned int)v670 >> 2)) >> 1)) & 3) * 2)) + ((((v704 + ((~(((v706 ^ -1) | (-(v706 ^ -1))) >> 31)) & 2)) - (v707 + ((~(((v708 ^ -1) | (-(v708 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
        int v715 = v713[v814];
        int * v716 = v664->mem;
        int v816 = v712 * 2;
        v716[v816] = v714;
        int * v718 = v664->mem;
        int v819 = (v712 * 2) + 1;
        v718[v819] = v715;
        ;
      } else {
        ;
      }
      int * v723 = v664->mem;
      int v824 = ((int)((unsigned int)((int)((unsigned int)v670 >> 2)) >> 1)) * 2;
      int v724 = v723[v824];
      int v825 = (((int)((unsigned int)((int)((unsigned int)v670 >> 2)) >> 1)) * 2) + 1;
      int v725 = v723[v825];
      int * v726 = v664->cache_vals;
      int v827 = ((4 + ((((int)((unsigned int)((int)((unsigned int)v670 >> 2)) >> 1)) & 3) * 2)) + ((((v704 + ((~(((v706 ^ -1) | (-(v706 ^ -1))) >> 31)) & 2)) - (v707 + ((~(((v708 ^ -1) | (-(v708 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
      v726[v827] = v724;
      int * v728 = v664->cache_vals;
      int v830 = (((4 + ((((int)((unsigned int)((int)((unsigned int)v670 >> 2)) >> 1)) & 3) * 2)) + ((((v704 + ((~(((v706 ^ -1) | (-(v706 ^ -1))) >> 31)) & 2)) - (v707 + ((~(((v708 ^ -1) | (-(v708 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
      v728[v830] = v725;
      int * v730 = v664->cache_tags;
      int v833 = (int)((unsigned int)((int)((unsigned int)v670 >> 2)) >> 1);
      v730[v809] = v833;
      int * v732 = v664->cache_dirty;
      v732[v809] = 0;
      int * v734 = v664->cache_age;
      v734[v809] = 1;
      int * v736 = v664->cache_age;
      int v737 = v736[v809];
      int v738 = v736[v784];
      int v839 = v738 + ((int)((unsigned int)(v738 - v737) >> 31));
      v736[v784] = v839;
      int * v740 = v664->cache_age;
      int v741 = v740[v785];
      int v841 = v741 + ((int)((unsigned int)(v741 - v737) >> 31));
      v740[v785] = v841;
      int * v743 = v664->cache_age;
      v743[v809] = 0;
      v746 = v809;
    }
    int * v747 = v664->cache_vals;
    int v844 = v746 * 2;
    int v748 = v747[v844];
    int v845 = (v746 * 2) + 1;
    int v749 = v747[v845];
    int v846 = (((((int)((unsigned int)((int)((unsigned int)v670 >> 2)) >> 1)) & 1) * 2) + ((((v688 + ((~(((v690 ^ -1) | (-(v690 ^ -1))) >> 31)) & 2)) - (v691 + ((~(((v692 ^ -1) | (-(v692 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
    v747[v846] = v748;
    int * v751 = v664->cache_vals;
    int v849 = ((((((int)((unsigned int)((int)((unsigned int)v670 >> 2)) >> 1)) & 1) * 2) + ((((v688 + ((~(((v690 ^ -1) | (-(v690 ^ -1))) >> 31)) & 2)) - (v691 + ((~(((v692 ^ -1) | (-(v692 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
    v751[v849] = v749;
    int * v753 = v664->cache_tags;
    int v852 = ((((int)((unsigned int)((int)((unsigned int)v670 >> 2)) >> 1)) & 1) * 2) + ((((v688 + ((~(((v690 ^ -1) | (-(v690 ^ -1))) >> 31)) & 2)) - (v691 + ((~(((v692 ^ -1) | (-(v692 ^ -1))) >> 31)) & 2))) >> 31) & 1);
    int v853 = (int)((unsigned int)((int)((unsigned int)v670 >> 2)) >> 1);
    v753[v852] = v853;
    int * v755 = v664->cache_dirty;
    v755[v852] = 0;
    int * v757 = v664->cache_age;
    v757[v852] = 1;
    int * v759 = v664->cache_age;
    int v760 = v759[v852];
    int v761 = v759[v782];
    int v859 = v761 + ((int)((unsigned int)(v761 - v760) >> 31));
    v759[v782] = v859;
    int * v763 = v664->cache_age;
    int v764 = v763[v783];
    int v861 = v764 + ((int)((unsigned int)(v764 - v760) >> 31));
    v763[v783] = v861;
    int * v766 = v664->cache_age;
    v766[v852] = 0;
    v769 = v852;
  }
  int v864 = (v769 * 2) + (((int)((unsigned int)v670 >> 2)) & 1);
  int v770 = v676[v864];
  int * v771 = v664->reg_ready;
  int v866 = ((v668 + ((v665 - v668) & (~((v665 - v668) >> 31)))) + 1) + ((100 ^ (((~(((v674 ^ ((int)((unsigned int)((int)((unsigned int)v670 >> 2)) >> 1))) | (-(v674 ^ ((int)((unsigned int)((int)((unsigned int)v670 >> 2)) >> 1))))) >> 31)) | (~(((v675 ^ ((int)((unsigned int)((int)((unsigned int)v670 >> 2)) >> 1))) | (-(v675 ^ ((int)((unsigned int)((int)((unsigned int)v670 >> 2)) >> 1))))) >> 31))) & 104)) ^ (((~(((v672 ^ ((int)((unsigned int)((int)((unsigned int)v670 >> 2)) >> 1))) | (-(v672 ^ ((int)((unsigned int)((int)((unsigned int)v670 >> 2)) >> 1))))) >> 31)) | (~(((v673 ^ ((int)((unsigned int)((int)((unsigned int)v670 >> 2)) >> 1))) | (-(v673 ^ ((int)((unsigned int)((int)((unsigned int)v670 >> 2)) >> 1))))) >> 31))) & (1 ^ (100 ^ (((~(((v674 ^ ((int)((unsigned int)((int)((unsigned int)v670 >> 2)) >> 1))) | (-(v674 ^ ((int)((unsigned int)((int)((unsigned int)v670 >> 2)) >> 1))))) >> 31)) | (~(((v675 ^ ((int)((unsigned int)((int)((unsigned int)v670 >> 2)) >> 1))) | (-(v675 ^ ((int)((unsigned int)((int)((unsigned int)v670 >> 2)) >> 1))))) >> 31))) & 104)))));
  v771[10] = v866;
  int * v773 = v664->regs;
  v773[10] = v770;
  struct StateT * v775 = slot_15(v664);
  return v775;
}

struct StateT * slot_6(struct StateT * v314) {
  int v315 = v314->timer;
  int v328 = v315 + 1;
  v314->timer = v328;
  int * v317 = v314->reg_ready;
  int v318 = v317[11];
  int * v319 = v314->regs;
  int v320 = v319[11];
  int v321 = v317[10];
  int v322 = v319[10];
  int v333 = (v321 + (((v318 + ((v315 - v318) & (~((v315 - v318) >> 31)))) - v321) & (~(((v318 + ((v315 - v318) & (~((v315 - v318) >> 31)))) - v321) >> 31)))) + 1;
  v317[10] = v333;
  int * v324 = v314->regs;
  int v335 = v320 + v322;
  v324[10] = v335;
  struct StateT * v326 = slot_7(v314);
  return v326;
}

struct StateT * slot_16(struct StateT * v1079) {
  int v1080 = v1079->timer;
  int v1093 = v1080 + 1;
  v1079->timer = v1093;
  int * v1082 = v1079->reg_ready;
  int v1083 = v1082[11];
  int * v1084 = v1079->regs;
  int v1085 = v1084[11];
  int v1086 = v1082[10];
  int v1087 = v1084[10];
  int v1098 = (v1086 + (((v1083 + ((v1080 - v1083) & (~((v1080 - v1083) >> 31)))) - v1086) & (~(((v1083 + ((v1080 - v1083) & (~((v1080 - v1083) >> 31)))) - v1086) >> 31)))) + 1;
  v1082[10] = v1098;
  int * v1089 = v1079->regs;
  int v1100 = v1085 & v1087;
  v1089[10] = v1100;
  struct StateT * v1091 = slot_17(v1079);
  return v1091;
}

struct StateT * slot_5(struct StateT * v293) {
  int v294 = v293->timer;
  int v305 = v294 + 1;
  v293->timer = v305;
  int * v296 = v293->reg_ready;
  int v297 = v296[11];
  int * v298 = v293->regs;
  int v299 = v298[11];
  int v309 = (v297 + ((v294 - v297) & (~((v294 - v297) >> 31)))) + 1;
  v296[11] = v309;
  int * v301 = v293->regs;
  int v311 = v299 + 72;
  v301[11] = v311;
  struct StateT * v303 = slot_6(v293);
  return v303;
}

struct StateT * slot_17(struct StateT * v1103) {
  int v1104 = v1103->timer;
  int v1277 = v1104 + 1;
  v1103->timer = v1277;
  int * v1106 = v1103->reg_ready;
  int * v1108 = v1103->regs;
  int v1109 = v1108[12];
  int v1111 = v1108[10];
  int * v1112 = v1103->cache_tags;
  int v1283 = (((int)((unsigned int)((int)((unsigned int)(v1109 + 68) >> 2)) >> 1)) & 1) * 2;
  int v1113 = v1112[v1283];
  int v1284 = ((((int)((unsigned int)((int)((unsigned int)(v1109 + 68) >> 2)) >> 1)) & 1) * 2) + 1;
  int v1114 = v1112[v1284];
  int v1285 = 4 + ((((int)((unsigned int)((int)((unsigned int)(v1109 + 68) >> 2)) >> 1)) & 3) * 2);
  int v1115 = v1112[v1285];
  int v1286 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v1109 + 68) >> 2)) >> 1)) & 3) * 2)) + 1;
  int v1116 = v1112[v1286];
  int v1117 = v1103->timer;
  int v1287 = v1117 + ((100 ^ (((~(((v1115 ^ ((int)((unsigned int)((int)((unsigned int)(v1109 + 68) >> 2)) >> 1))) | (-(v1115 ^ ((int)((unsigned int)((int)((unsigned int)(v1109 + 68) >> 2)) >> 1))))) >> 31)) | (~(((v1116 ^ ((int)((unsigned int)((int)((unsigned int)(v1109 + 68) >> 2)) >> 1))) | (-(v1116 ^ ((int)((unsigned int)((int)((unsigned int)(v1109 + 68) >> 2)) >> 1))))) >> 31))) & 104)) ^ (((~(((v1113 ^ ((int)((unsigned int)((int)((unsigned int)(v1109 + 68) >> 2)) >> 1))) | (-(v1113 ^ ((int)((unsigned int)((int)((unsigned int)(v1109 + 68) >> 2)) >> 1))))) >> 31)) | (~(((v1114 ^ ((int)((unsigned int)((int)((unsigned int)(v1109 + 68) >> 2)) >> 1))) | (-(v1114 ^ ((int)((unsigned int)((int)((unsigned int)(v1109 + 68) >> 2)) >> 1))))) >> 31))) & (1 ^ (100 ^ (((~(((v1115 ^ ((int)((unsigned int)((int)((unsigned int)(v1109 + 68) >> 2)) >> 1))) | (-(v1115 ^ ((int)((unsigned int)((int)((unsigned int)(v1109 + 68) >> 2)) >> 1))))) >> 31)) | (~(((v1116 ^ ((int)((unsigned int)((int)((unsigned int)(v1109 + 68) >> 2)) >> 1))) | (-(v1116 ^ ((int)((unsigned int)((int)((unsigned int)(v1109 + 68) >> 2)) >> 1))))) >> 31))) & 104)))));
  v1103->timer = v1287;
  bool v1288 = !(((~(((v1113 ^ ((int)((unsigned int)((int)((unsigned int)(v1109 + 68) >> 2)) >> 1))) | (-(v1113 ^ ((int)((unsigned int)((int)((unsigned int)(v1109 + 68) >> 2)) >> 1))))) >> 31)) | (~(((v1114 ^ ((int)((unsigned int)((int)((unsigned int)(v1109 + 68) >> 2)) >> 1))) | (-(v1114 ^ ((int)((unsigned int)((int)((unsigned int)(v1109 + 68) >> 2)) >> 1))))) >> 31))) == 0);
  int v1211;
  if (v1288) {
    int * v1119 = v1103->cache_age;
    int v1290 = ((((int)((unsigned int)((int)((unsigned int)(v1109 + 68) >> 2)) >> 1)) & 1) * 2) + ((~(((v1114 ^ ((int)((unsigned int)((int)((unsigned int)(v1109 + 68) >> 2)) >> 1))) | (-(v1114 ^ ((int)((unsigned int)((int)((unsigned int)(v1109 + 68) >> 2)) >> 1))))) >> 31)) & 1);
    int v1120 = v1119[v1290];
    int v1121 = v1119[v1283];
    int v1291 = v1121 + ((int)((unsigned int)(v1121 - v1120) >> 31));
    v1119[v1283] = v1291;
    int * v1123 = v1103->cache_age;
    int v1124 = v1123[v1284];
    int v1293 = v1124 + ((int)((unsigned int)(v1124 - v1120) >> 31));
    v1123[v1284] = v1293;
    int * v1126 = v1103->cache_age;
    v1126[v1290] = 0;
    v1211 = v1290;
  } else {
    int * v1129 = v1103->cache_age;
    int v1297 = (((int)((unsigned int)((int)((unsigned int)(v1109 + 68) >> 2)) >> 1)) & 1) * 2;
    int v1130 = v1129[v1297];
    int * v1131 = v1103->cache_tags;
    int v1132 = v1131[v1297];
    int v1133 = v1129[v1284];
    int v1134 = v1131[v1284];
    bool v1299 = !(((~(((v1115 ^ ((int)((unsigned int)((int)((unsigned int)(v1109 + 68) >> 2)) >> 1))) | (-(v1115 ^ ((int)((unsigned int)((int)((unsigned int)(v1109 + 68) >> 2)) >> 1))))) >> 31)) | (~(((v1116 ^ ((int)((unsigned int)((int)((unsigned int)(v1109 + 68) >> 2)) >> 1))) | (-(v1116 ^ ((int)((unsigned int)((int)((unsigned int)(v1109 + 68) >> 2)) >> 1))))) >> 31))) == 0);
    int v1188;
    if (v1299) {
      int * v1135 = v1103->cache_age;
      int v1301 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v1109 + 68) >> 2)) >> 1)) & 3) * 2)) + ((~(((v1116 ^ ((int)((unsigned int)((int)((unsigned int)(v1109 + 68) >> 2)) >> 1))) | (-(v1116 ^ ((int)((unsigned int)((int)((unsigned int)(v1109 + 68) >> 2)) >> 1))))) >> 31)) & 1);
      int v1136 = v1135[v1301];
      int v1137 = v1135[v1285];
      int v1302 = v1137 + ((int)((unsigned int)(v1137 - v1136) >> 31));
      v1135[v1285] = v1302;
      int * v1139 = v1103->cache_age;
      int v1140 = v1139[v1286];
      int v1304 = v1140 + ((int)((unsigned int)(v1140 - v1136) >> 31));
      v1139[v1286] = v1304;
      int * v1142 = v1103->cache_age;
      v1142[v1301] = 0;
      v1188 = v1301;
    } else {
      int * v1145 = v1103->cache_age;
      int v1308 = 4 + ((((int)((unsigned int)((int)((unsigned int)(v1109 + 68) >> 2)) >> 1)) & 3) * 2);
      int v1146 = v1145[v1308];
      int * v1147 = v1103->cache_tags;
      int v1148 = v1147[v1308];
      int v1149 = v1145[v1286];
      int v1150 = v1147[v1286];
      int * v1151 = v1103->cache_dirty;
      int v1311 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v1109 + 68) >> 2)) >> 1)) & 3) * 2)) + ((((v1146 + ((~(((v1148 ^ -1) | (-(v1148 ^ -1))) >> 31)) & 2)) - (v1149 + ((~(((v1150 ^ -1) | (-(v1150 ^ -1))) >> 31)) & 2))) >> 31) & 1);
      int v1152 = v1151[v1311];
      bool v1312 = !(v1152 == 0);
      if (v1312) {
        int * v1153 = v1103->cache_tags;
        int v1154 = v1153[v1311];
        int * v1155 = v1103->cache_vals;
        int v1315 = ((4 + ((((int)((unsigned int)((int)((unsigned int)(v1109 + 68) >> 2)) >> 1)) & 3) * 2)) + ((((v1146 + ((~(((v1148 ^ -1) | (-(v1148 ^ -1))) >> 31)) & 2)) - (v1149 + ((~(((v1150 ^ -1) | (-(v1150 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
        int v1156 = v1155[v1315];
        int v1316 = (((4 + ((((int)((unsigned int)((int)((unsigned int)(v1109 + 68) >> 2)) >> 1)) & 3) * 2)) + ((((v1146 + ((~(((v1148 ^ -1) | (-(v1148 ^ -1))) >> 31)) & 2)) - (v1149 + ((~(((v1150 ^ -1) | (-(v1150 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
        int v1157 = v1155[v1316];
        int * v1158 = v1103->mem;
        int v1318 = v1154 * 2;
        v1158[v1318] = v1156;
        int * v1160 = v1103->mem;
        int v1321 = (v1154 * 2) + 1;
        v1160[v1321] = v1157;
        ;
      } else {
        ;
      }
      int * v1165 = v1103->mem;
      int v1326 = ((int)((unsigned int)((int)((unsigned int)(v1109 + 68) >> 2)) >> 1)) * 2;
      int v1166 = v1165[v1326];
      int v1327 = (((int)((unsigned int)((int)((unsigned int)(v1109 + 68) >> 2)) >> 1)) * 2) + 1;
      int v1167 = v1165[v1327];
      int * v1168 = v1103->cache_vals;
      int v1329 = ((4 + ((((int)((unsigned int)((int)((unsigned int)(v1109 + 68) >> 2)) >> 1)) & 3) * 2)) + ((((v1146 + ((~(((v1148 ^ -1) | (-(v1148 ^ -1))) >> 31)) & 2)) - (v1149 + ((~(((v1150 ^ -1) | (-(v1150 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
      v1168[v1329] = v1166;
      int * v1170 = v1103->cache_vals;
      int v1332 = (((4 + ((((int)((unsigned int)((int)((unsigned int)(v1109 + 68) >> 2)) >> 1)) & 3) * 2)) + ((((v1146 + ((~(((v1148 ^ -1) | (-(v1148 ^ -1))) >> 31)) & 2)) - (v1149 + ((~(((v1150 ^ -1) | (-(v1150 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
      v1170[v1332] = v1167;
      int * v1172 = v1103->cache_tags;
      int v1335 = (int)((unsigned int)((int)((unsigned int)(v1109 + 68) >> 2)) >> 1);
      v1172[v1311] = v1335;
      int * v1174 = v1103->cache_dirty;
      v1174[v1311] = 0;
      int * v1176 = v1103->cache_age;
      v1176[v1311] = 1;
      int * v1178 = v1103->cache_age;
      int v1179 = v1178[v1311];
      int v1180 = v1178[v1285];
      int v1341 = v1180 + ((int)((unsigned int)(v1180 - v1179) >> 31));
      v1178[v1285] = v1341;
      int * v1182 = v1103->cache_age;
      int v1183 = v1182[v1286];
      int v1343 = v1183 + ((int)((unsigned int)(v1183 - v1179) >> 31));
      v1182[v1286] = v1343;
      int * v1185 = v1103->cache_age;
      v1185[v1311] = 0;
      v1188 = v1311;
    }
    int * v1189 = v1103->cache_vals;
    int v1346 = v1188 * 2;
    int v1190 = v1189[v1346];
    int v1347 = (v1188 * 2) + 1;
    int v1191 = v1189[v1347];
    int v1348 = (((((int)((unsigned int)((int)((unsigned int)(v1109 + 68) >> 2)) >> 1)) & 1) * 2) + ((((v1130 + ((~(((v1132 ^ -1) | (-(v1132 ^ -1))) >> 31)) & 2)) - (v1133 + ((~(((v1134 ^ -1) | (-(v1134 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
    v1189[v1348] = v1190;
    int * v1193 = v1103->cache_vals;
    int v1351 = ((((((int)((unsigned int)((int)((unsigned int)(v1109 + 68) >> 2)) >> 1)) & 1) * 2) + ((((v1130 + ((~(((v1132 ^ -1) | (-(v1132 ^ -1))) >> 31)) & 2)) - (v1133 + ((~(((v1134 ^ -1) | (-(v1134 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
    v1193[v1351] = v1191;
    int * v1195 = v1103->cache_tags;
    int v1354 = ((((int)((unsigned int)((int)((unsigned int)(v1109 + 68) >> 2)) >> 1)) & 1) * 2) + ((((v1130 + ((~(((v1132 ^ -1) | (-(v1132 ^ -1))) >> 31)) & 2)) - (v1133 + ((~(((v1134 ^ -1) | (-(v1134 ^ -1))) >> 31)) & 2))) >> 31) & 1);
    int v1355 = (int)((unsigned int)((int)((unsigned int)(v1109 + 68) >> 2)) >> 1);
    v1195[v1354] = v1355;
    int * v1197 = v1103->cache_dirty;
    v1197[v1354] = 0;
    int * v1199 = v1103->cache_age;
    v1199[v1354] = 1;
    int * v1201 = v1103->cache_age;
    int v1202 = v1201[v1354];
    int v1203 = v1201[v1283];
    int v1361 = v1203 + ((int)((unsigned int)(v1203 - v1202) >> 31));
    v1201[v1283] = v1361;
    int * v1205 = v1103->cache_age;
    int v1206 = v1205[v1284];
    int v1363 = v1206 + ((int)((unsigned int)(v1206 - v1202) >> 31));
    v1205[v1284] = v1363;
    int * v1208 = v1103->cache_age;
    v1208[v1354] = 0;
    v1211 = v1354;
  }
  int * v1212 = v1103->cache_vals;
  int v1366 = (v1211 * 2) + (((int)((unsigned int)(v1109 + 68) >> 2)) & 1);
  v1212[v1366] = v1111;
  int * v1214 = v1103->cache_tags;
  int v1215 = v1214[v1285];
  int v1216 = v1214[v1286];
  bool v1369 = !(((~(((v1215 ^ ((int)((unsigned int)((int)((unsigned int)(v1109 + 68) >> 2)) >> 1))) | (-(v1215 ^ ((int)((unsigned int)((int)((unsigned int)(v1109 + 68) >> 2)) >> 1))))) >> 31)) | (~(((v1216 ^ ((int)((unsigned int)((int)((unsigned int)(v1109 + 68) >> 2)) >> 1))) | (-(v1216 ^ ((int)((unsigned int)((int)((unsigned int)(v1109 + 68) >> 2)) >> 1))))) >> 31))) == 0);
  int v1270;
  if (v1369) {
    int * v1217 = v1103->cache_age;
    int v1371 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v1109 + 68) >> 2)) >> 1)) & 3) * 2)) + ((~(((v1216 ^ ((int)((unsigned int)((int)((unsigned int)(v1109 + 68) >> 2)) >> 1))) | (-(v1216 ^ ((int)((unsigned int)((int)((unsigned int)(v1109 + 68) >> 2)) >> 1))))) >> 31)) & 1);
    int v1218 = v1217[v1371];
    int v1219 = v1217[v1285];
    int v1372 = v1219 + ((int)((unsigned int)(v1219 - v1218) >> 31));
    v1217[v1285] = v1372;
    int * v1221 = v1103->cache_age;
    int v1222 = v1221[v1286];
    int v1374 = v1222 + ((int)((unsigned int)(v1222 - v1218) >> 31));
    v1221[v1286] = v1374;
    int * v1224 = v1103->cache_age;
    v1224[v1371] = 0;
    v1270 = v1371;
  } else {
    int * v1227 = v1103->cache_age;
    int v1378 = 4 + ((((int)((unsigned int)((int)((unsigned int)(v1109 + 68) >> 2)) >> 1)) & 3) * 2);
    int v1228 = v1227[v1378];
    int * v1229 = v1103->cache_tags;
    int v1230 = v1229[v1378];
    int v1231 = v1227[v1286];
    int v1232 = v1229[v1286];
    int * v1233 = v1103->cache_dirty;
    int v1381 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v1109 + 68) >> 2)) >> 1)) & 3) * 2)) + ((((v1228 + ((~(((v1230 ^ -1) | (-(v1230 ^ -1))) >> 31)) & 2)) - (v1231 + ((~(((v1232 ^ -1) | (-(v1232 ^ -1))) >> 31)) & 2))) >> 31) & 1);
    int v1234 = v1233[v1381];
    bool v1382 = !(v1234 == 0);
    if (v1382) {
      int * v1235 = v1103->cache_tags;
      int v1236 = v1235[v1381];
      int * v1237 = v1103->cache_vals;
      int v1385 = ((4 + ((((int)((unsigned int)((int)((unsigned int)(v1109 + 68) >> 2)) >> 1)) & 3) * 2)) + ((((v1228 + ((~(((v1230 ^ -1) | (-(v1230 ^ -1))) >> 31)) & 2)) - (v1231 + ((~(((v1232 ^ -1) | (-(v1232 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
      int v1238 = v1237[v1385];
      int v1386 = (((4 + ((((int)((unsigned int)((int)((unsigned int)(v1109 + 68) >> 2)) >> 1)) & 3) * 2)) + ((((v1228 + ((~(((v1230 ^ -1) | (-(v1230 ^ -1))) >> 31)) & 2)) - (v1231 + ((~(((v1232 ^ -1) | (-(v1232 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
      int v1239 = v1237[v1386];
      int * v1240 = v1103->mem;
      int v1388 = v1236 * 2;
      v1240[v1388] = v1238;
      int * v1242 = v1103->mem;
      int v1391 = (v1236 * 2) + 1;
      v1242[v1391] = v1239;
      ;
    } else {
      ;
    }
    int * v1247 = v1103->mem;
    int v1396 = ((int)((unsigned int)((int)((unsigned int)(v1109 + 68) >> 2)) >> 1)) * 2;
    int v1248 = v1247[v1396];
    int v1397 = (((int)((unsigned int)((int)((unsigned int)(v1109 + 68) >> 2)) >> 1)) * 2) + 1;
    int v1249 = v1247[v1397];
    int * v1250 = v1103->cache_vals;
    int v1399 = ((4 + ((((int)((unsigned int)((int)((unsigned int)(v1109 + 68) >> 2)) >> 1)) & 3) * 2)) + ((((v1228 + ((~(((v1230 ^ -1) | (-(v1230 ^ -1))) >> 31)) & 2)) - (v1231 + ((~(((v1232 ^ -1) | (-(v1232 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
    v1250[v1399] = v1248;
    int * v1252 = v1103->cache_vals;
    int v1402 = (((4 + ((((int)((unsigned int)((int)((unsigned int)(v1109 + 68) >> 2)) >> 1)) & 3) * 2)) + ((((v1228 + ((~(((v1230 ^ -1) | (-(v1230 ^ -1))) >> 31)) & 2)) - (v1231 + ((~(((v1232 ^ -1) | (-(v1232 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
    v1252[v1402] = v1249;
    int * v1254 = v1103->cache_tags;
    int v1405 = (int)((unsigned int)((int)((unsigned int)(v1109 + 68) >> 2)) >> 1);
    v1254[v1381] = v1405;
    int * v1256 = v1103->cache_dirty;
    v1256[v1381] = 0;
    int * v1258 = v1103->cache_age;
    v1258[v1381] = 1;
    int * v1260 = v1103->cache_age;
    int v1261 = v1260[v1381];
    int v1262 = v1260[v1285];
    int v1411 = v1262 + ((int)((unsigned int)(v1262 - v1261) >> 31));
    v1260[v1285] = v1411;
    int * v1264 = v1103->cache_age;
    int v1265 = v1264[v1286];
    int v1413 = v1265 + ((int)((unsigned int)(v1265 - v1261) >> 31));
    v1264[v1286] = v1413;
    int * v1267 = v1103->cache_age;
    v1267[v1381] = 0;
    v1270 = v1381;
  }
  int * v1271 = v1103->cache_vals;
  int v1416 = (v1270 * 2) + (((int)((unsigned int)(v1109 + 68) >> 2)) & 1);
  v1271[v1416] = v1111;
  int * v1273 = v1103->cache_dirty;
  v1273[v1270] = 1;
  struct StateT * v1275 = slot_18(v1103);
  return v1275;
}

struct StateT * slot_2(struct StateT * v225) {
  int v226 = v225->timer;
  int v240 = v226 + 1;
  v225->timer = v240;
  int * v228 = v225->reg_ready;
  int * v230 = v225->regs;
  int v231 = v230[10];
  int v233 = v230[11];
  bool v245 = (v231 ^ -2147483648) >= (v233 ^ -2147483648);
  struct StateT * v238;
  if (v245) {
    struct StateT * v234 = slot_18(v225);
    v238 = v234;
  } else {
    struct StateT * v236 = slot_3(v225);
    v238 = v236;
  }
  return v238;
}

struct StateT * slot_7(struct StateT * v338) {
  int v339 = v338->timer;
  int v451 = v339 + 1;
  v338->timer = v451;
  int * v341 = v338->reg_ready;
  int v342 = v341[10];
  int * v343 = v338->regs;
  int v344 = v343[10];
  int * v345 = v338->cache_tags;
  int v456 = (((int)((unsigned int)((int)((unsigned int)v344 >> 2)) >> 1)) & 1) * 2;
  int v346 = v345[v456];
  int v457 = ((((int)((unsigned int)((int)((unsigned int)v344 >> 2)) >> 1)) & 1) * 2) + 1;
  int v347 = v345[v457];
  int v458 = 4 + ((((int)((unsigned int)((int)((unsigned int)v344 >> 2)) >> 1)) & 3) * 2);
  int v348 = v345[v458];
  int v459 = (4 + ((((int)((unsigned int)((int)((unsigned int)v344 >> 2)) >> 1)) & 3) * 2)) + 1;
  int v349 = v345[v459];
  int * v350 = v338->cache_vals;
  bool v460 = !(((~(((v346 ^ ((int)((unsigned int)((int)((unsigned int)v344 >> 2)) >> 1))) | (-(v346 ^ ((int)((unsigned int)((int)((unsigned int)v344 >> 2)) >> 1))))) >> 31)) | (~(((v347 ^ ((int)((unsigned int)((int)((unsigned int)v344 >> 2)) >> 1))) | (-(v347 ^ ((int)((unsigned int)((int)((unsigned int)v344 >> 2)) >> 1))))) >> 31))) == 0);
  int v443;
  if (v460) {
    int * v351 = v338->cache_age;
    int v462 = ((((int)((unsigned int)((int)((unsigned int)v344 >> 2)) >> 1)) & 1) * 2) + ((~(((v347 ^ ((int)((unsigned int)((int)((unsigned int)v344 >> 2)) >> 1))) | (-(v347 ^ ((int)((unsigned int)((int)((unsigned int)v344 >> 2)) >> 1))))) >> 31)) & 1);
    int v352 = v351[v462];
    int v353 = v351[v456];
    int v463 = v353 + ((int)((unsigned int)(v353 - v352) >> 31));
    v351[v456] = v463;
    int * v355 = v338->cache_age;
    int v356 = v355[v457];
    int v465 = v356 + ((int)((unsigned int)(v356 - v352) >> 31));
    v355[v457] = v465;
    int * v358 = v338->cache_age;
    v358[v462] = 0;
    v443 = v462;
  } else {
    int * v361 = v338->cache_age;
    int v469 = (((int)((unsigned int)((int)((unsigned int)v344 >> 2)) >> 1)) & 1) * 2;
    int v362 = v361[v469];
    int * v363 = v338->cache_tags;
    int v364 = v363[v469];
    int v365 = v361[v457];
    int v366 = v363[v457];
    bool v471 = !(((~(((v348 ^ ((int)((unsigned int)((int)((unsigned int)v344 >> 2)) >> 1))) | (-(v348 ^ ((int)((unsigned int)((int)((unsigned int)v344 >> 2)) >> 1))))) >> 31)) | (~(((v349 ^ ((int)((unsigned int)((int)((unsigned int)v344 >> 2)) >> 1))) | (-(v349 ^ ((int)((unsigned int)((int)((unsigned int)v344 >> 2)) >> 1))))) >> 31))) == 0);
    int v420;
    if (v471) {
      int * v367 = v338->cache_age;
      int v473 = (4 + ((((int)((unsigned int)((int)((unsigned int)v344 >> 2)) >> 1)) & 3) * 2)) + ((~(((v349 ^ ((int)((unsigned int)((int)((unsigned int)v344 >> 2)) >> 1))) | (-(v349 ^ ((int)((unsigned int)((int)((unsigned int)v344 >> 2)) >> 1))))) >> 31)) & 1);
      int v368 = v367[v473];
      int v369 = v367[v458];
      int v474 = v369 + ((int)((unsigned int)(v369 - v368) >> 31));
      v367[v458] = v474;
      int * v371 = v338->cache_age;
      int v372 = v371[v459];
      int v476 = v372 + ((int)((unsigned int)(v372 - v368) >> 31));
      v371[v459] = v476;
      int * v374 = v338->cache_age;
      v374[v473] = 0;
      v420 = v473;
    } else {
      int * v377 = v338->cache_age;
      int v480 = 4 + ((((int)((unsigned int)((int)((unsigned int)v344 >> 2)) >> 1)) & 3) * 2);
      int v378 = v377[v480];
      int * v379 = v338->cache_tags;
      int v380 = v379[v480];
      int v381 = v377[v459];
      int v382 = v379[v459];
      int * v383 = v338->cache_dirty;
      int v483 = (4 + ((((int)((unsigned int)((int)((unsigned int)v344 >> 2)) >> 1)) & 3) * 2)) + ((((v378 + ((~(((v380 ^ -1) | (-(v380 ^ -1))) >> 31)) & 2)) - (v381 + ((~(((v382 ^ -1) | (-(v382 ^ -1))) >> 31)) & 2))) >> 31) & 1);
      int v384 = v383[v483];
      bool v484 = !(v384 == 0);
      if (v484) {
        int * v385 = v338->cache_tags;
        int v386 = v385[v483];
        int * v387 = v338->cache_vals;
        int v487 = ((4 + ((((int)((unsigned int)((int)((unsigned int)v344 >> 2)) >> 1)) & 3) * 2)) + ((((v378 + ((~(((v380 ^ -1) | (-(v380 ^ -1))) >> 31)) & 2)) - (v381 + ((~(((v382 ^ -1) | (-(v382 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
        int v388 = v387[v487];
        int v488 = (((4 + ((((int)((unsigned int)((int)((unsigned int)v344 >> 2)) >> 1)) & 3) * 2)) + ((((v378 + ((~(((v380 ^ -1) | (-(v380 ^ -1))) >> 31)) & 2)) - (v381 + ((~(((v382 ^ -1) | (-(v382 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
        int v389 = v387[v488];
        int * v390 = v338->mem;
        int v490 = v386 * 2;
        v390[v490] = v388;
        int * v392 = v338->mem;
        int v493 = (v386 * 2) + 1;
        v392[v493] = v389;
        ;
      } else {
        ;
      }
      int * v397 = v338->mem;
      int v498 = ((int)((unsigned int)((int)((unsigned int)v344 >> 2)) >> 1)) * 2;
      int v398 = v397[v498];
      int v499 = (((int)((unsigned int)((int)((unsigned int)v344 >> 2)) >> 1)) * 2) + 1;
      int v399 = v397[v499];
      int * v400 = v338->cache_vals;
      int v501 = ((4 + ((((int)((unsigned int)((int)((unsigned int)v344 >> 2)) >> 1)) & 3) * 2)) + ((((v378 + ((~(((v380 ^ -1) | (-(v380 ^ -1))) >> 31)) & 2)) - (v381 + ((~(((v382 ^ -1) | (-(v382 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
      v400[v501] = v398;
      int * v402 = v338->cache_vals;
      int v504 = (((4 + ((((int)((unsigned int)((int)((unsigned int)v344 >> 2)) >> 1)) & 3) * 2)) + ((((v378 + ((~(((v380 ^ -1) | (-(v380 ^ -1))) >> 31)) & 2)) - (v381 + ((~(((v382 ^ -1) | (-(v382 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
      v402[v504] = v399;
      int * v404 = v338->cache_tags;
      int v507 = (int)((unsigned int)((int)((unsigned int)v344 >> 2)) >> 1);
      v404[v483] = v507;
      int * v406 = v338->cache_dirty;
      v406[v483] = 0;
      int * v408 = v338->cache_age;
      v408[v483] = 1;
      int * v410 = v338->cache_age;
      int v411 = v410[v483];
      int v412 = v410[v458];
      int v513 = v412 + ((int)((unsigned int)(v412 - v411) >> 31));
      v410[v458] = v513;
      int * v414 = v338->cache_age;
      int v415 = v414[v459];
      int v515 = v415 + ((int)((unsigned int)(v415 - v411) >> 31));
      v414[v459] = v515;
      int * v417 = v338->cache_age;
      v417[v483] = 0;
      v420 = v483;
    }
    int * v421 = v338->cache_vals;
    int v518 = v420 * 2;
    int v422 = v421[v518];
    int v519 = (v420 * 2) + 1;
    int v423 = v421[v519];
    int v520 = (((((int)((unsigned int)((int)((unsigned int)v344 >> 2)) >> 1)) & 1) * 2) + ((((v362 + ((~(((v364 ^ -1) | (-(v364 ^ -1))) >> 31)) & 2)) - (v365 + ((~(((v366 ^ -1) | (-(v366 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
    v421[v520] = v422;
    int * v425 = v338->cache_vals;
    int v523 = ((((((int)((unsigned int)((int)((unsigned int)v344 >> 2)) >> 1)) & 1) * 2) + ((((v362 + ((~(((v364 ^ -1) | (-(v364 ^ -1))) >> 31)) & 2)) - (v365 + ((~(((v366 ^ -1) | (-(v366 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
    v425[v523] = v423;
    int * v427 = v338->cache_tags;
    int v526 = ((((int)((unsigned int)((int)((unsigned int)v344 >> 2)) >> 1)) & 1) * 2) + ((((v362 + ((~(((v364 ^ -1) | (-(v364 ^ -1))) >> 31)) & 2)) - (v365 + ((~(((v366 ^ -1) | (-(v366 ^ -1))) >> 31)) & 2))) >> 31) & 1);
    int v527 = (int)((unsigned int)((int)((unsigned int)v344 >> 2)) >> 1);
    v427[v526] = v527;
    int * v429 = v338->cache_dirty;
    v429[v526] = 0;
    int * v431 = v338->cache_age;
    v431[v526] = 1;
    int * v433 = v338->cache_age;
    int v434 = v433[v526];
    int v435 = v433[v456];
    int v533 = v435 + ((int)((unsigned int)(v435 - v434) >> 31));
    v433[v456] = v533;
    int * v437 = v338->cache_age;
    int v438 = v437[v457];
    int v535 = v438 + ((int)((unsigned int)(v438 - v434) >> 31));
    v437[v457] = v535;
    int * v440 = v338->cache_age;
    v440[v526] = 0;
    v443 = v526;
  }
  int v538 = (v443 * 2) + (((int)((unsigned int)v344 >> 2)) & 1);
  int v444 = v350[v538];
  int * v445 = v338->reg_ready;
  int v540 = ((v342 + ((v339 - v342) & (~((v339 - v342) >> 31)))) + 1) + ((100 ^ (((~(((v348 ^ ((int)((unsigned int)((int)((unsigned int)v344 >> 2)) >> 1))) | (-(v348 ^ ((int)((unsigned int)((int)((unsigned int)v344 >> 2)) >> 1))))) >> 31)) | (~(((v349 ^ ((int)((unsigned int)((int)((unsigned int)v344 >> 2)) >> 1))) | (-(v349 ^ ((int)((unsigned int)((int)((unsigned int)v344 >> 2)) >> 1))))) >> 31))) & 104)) ^ (((~(((v346 ^ ((int)((unsigned int)((int)((unsigned int)v344 >> 2)) >> 1))) | (-(v346 ^ ((int)((unsigned int)((int)((unsigned int)v344 >> 2)) >> 1))))) >> 31)) | (~(((v347 ^ ((int)((unsigned int)((int)((unsigned int)v344 >> 2)) >> 1))) | (-(v347 ^ ((int)((unsigned int)((int)((unsigned int)v344 >> 2)) >> 1))))) >> 31))) & (1 ^ (100 ^ (((~(((v348 ^ ((int)((unsigned int)((int)((unsigned int)v344 >> 2)) >> 1))) | (-(v348 ^ ((int)((unsigned int)((int)((unsigned int)v344 >> 2)) >> 1))))) >> 31)) | (~(((v349 ^ ((int)((unsigned int)((int)((unsigned int)v344 >> 2)) >> 1))) | (-(v349 ^ ((int)((unsigned int)((int)((unsigned int)v344 >> 2)) >> 1))))) >> 31))) & 104)))));
  v445[10] = v540;
  int * v447 = v338->regs;
  v447[10] = v444;
  struct StateT * v449 = slot_8(v338);
  return v449;
}

struct StateT * slot_3(struct StateT * v256) {
  int v257 = v256->timer;
  int v268 = v257 + 1;
  v256->timer = v268;
  int * v259 = v256->reg_ready;
  int v260 = v259[10];
  int * v261 = v256->regs;
  int v262 = v261[10];
  int v272 = (v260 + ((v257 - v260) & (~((v257 - v260) >> 31)))) + 1;
  v259[10] = v272;
  int * v264 = v256->regs;
  int v274 = v262 << 2;
  v264[10] = v274;
  struct StateT * v266 = slot_4(v256);
  return v266;
}

struct StateT * snippet(struct StateT * v0) {
  struct StateT * v1 = slot_0(v0);
  int v1422 = v1->timer;
  int * v1423 = v1->reg_ready;
  int v1424 = v1423[0];
  int v1555 = v1424 + ((v1422 - v1424) & (~((v1422 - v1424) >> 31)));
  v1->timer = v1555;
  int v1426 = v1->timer;
  int * v1427 = v1->reg_ready;
  int v1428 = v1427[1];
  int v1558 = v1428 + ((v1426 - v1428) & (~((v1426 - v1428) >> 31)));
  v1->timer = v1558;
  int v1430 = v1->timer;
  int * v1431 = v1->reg_ready;
  int v1432 = v1431[2];
  int v1561 = v1432 + ((v1430 - v1432) & (~((v1430 - v1432) >> 31)));
  v1->timer = v1561;
  int v1434 = v1->timer;
  int * v1435 = v1->reg_ready;
  int v1436 = v1435[3];
  int v1564 = v1436 + ((v1434 - v1436) & (~((v1434 - v1436) >> 31)));
  v1->timer = v1564;
  int v1438 = v1->timer;
  int * v1439 = v1->reg_ready;
  int v1440 = v1439[4];
  int v1567 = v1440 + ((v1438 - v1440) & (~((v1438 - v1440) >> 31)));
  v1->timer = v1567;
  int v1442 = v1->timer;
  int * v1443 = v1->reg_ready;
  int v1444 = v1443[5];
  int v1570 = v1444 + ((v1442 - v1444) & (~((v1442 - v1444) >> 31)));
  v1->timer = v1570;
  int v1446 = v1->timer;
  int * v1447 = v1->reg_ready;
  int v1448 = v1447[6];
  int v1573 = v1448 + ((v1446 - v1448) & (~((v1446 - v1448) >> 31)));
  v1->timer = v1573;
  int v1450 = v1->timer;
  int * v1451 = v1->reg_ready;
  int v1452 = v1451[7];
  int v1576 = v1452 + ((v1450 - v1452) & (~((v1450 - v1452) >> 31)));
  v1->timer = v1576;
  int v1454 = v1->timer;
  int * v1455 = v1->reg_ready;
  int v1456 = v1455[8];
  int v1579 = v1456 + ((v1454 - v1456) & (~((v1454 - v1456) >> 31)));
  v1->timer = v1579;
  int v1458 = v1->timer;
  int * v1459 = v1->reg_ready;
  int v1460 = v1459[9];
  int v1582 = v1460 + ((v1458 - v1460) & (~((v1458 - v1460) >> 31)));
  v1->timer = v1582;
  int v1462 = v1->timer;
  int * v1463 = v1->reg_ready;
  int v1464 = v1463[10];
  int v1585 = v1464 + ((v1462 - v1464) & (~((v1462 - v1464) >> 31)));
  v1->timer = v1585;
  int v1466 = v1->timer;
  int * v1467 = v1->reg_ready;
  int v1468 = v1467[11];
  int v1588 = v1468 + ((v1466 - v1468) & (~((v1466 - v1468) >> 31)));
  v1->timer = v1588;
  int v1470 = v1->timer;
  int * v1471 = v1->reg_ready;
  int v1472 = v1471[12];
  int v1591 = v1472 + ((v1470 - v1472) & (~((v1470 - v1472) >> 31)));
  v1->timer = v1591;
  int v1474 = v1->timer;
  int * v1475 = v1->reg_ready;
  int v1476 = v1475[13];
  int v1594 = v1476 + ((v1474 - v1476) & (~((v1474 - v1476) >> 31)));
  v1->timer = v1594;
  int v1478 = v1->timer;
  int * v1479 = v1->reg_ready;
  int v1480 = v1479[14];
  int v1597 = v1480 + ((v1478 - v1480) & (~((v1478 - v1480) >> 31)));
  v1->timer = v1597;
  int v1482 = v1->timer;
  int * v1483 = v1->reg_ready;
  int v1484 = v1483[15];
  int v1600 = v1484 + ((v1482 - v1484) & (~((v1482 - v1484) >> 31)));
  v1->timer = v1600;
  int v1486 = v1->timer;
  int * v1487 = v1->reg_ready;
  int v1488 = v1487[16];
  int v1603 = v1488 + ((v1486 - v1488) & (~((v1486 - v1488) >> 31)));
  v1->timer = v1603;
  int v1490 = v1->timer;
  int * v1491 = v1->reg_ready;
  int v1492 = v1491[17];
  int v1606 = v1492 + ((v1490 - v1492) & (~((v1490 - v1492) >> 31)));
  v1->timer = v1606;
  int v1494 = v1->timer;
  int * v1495 = v1->reg_ready;
  int v1496 = v1495[18];
  int v1609 = v1496 + ((v1494 - v1496) & (~((v1494 - v1496) >> 31)));
  v1->timer = v1609;
  int v1498 = v1->timer;
  int * v1499 = v1->reg_ready;
  int v1500 = v1499[19];
  int v1612 = v1500 + ((v1498 - v1500) & (~((v1498 - v1500) >> 31)));
  v1->timer = v1612;
  int v1502 = v1->timer;
  int * v1503 = v1->reg_ready;
  int v1504 = v1503[20];
  int v1615 = v1504 + ((v1502 - v1504) & (~((v1502 - v1504) >> 31)));
  v1->timer = v1615;
  int v1506 = v1->timer;
  int * v1507 = v1->reg_ready;
  int v1508 = v1507[21];
  int v1618 = v1508 + ((v1506 - v1508) & (~((v1506 - v1508) >> 31)));
  v1->timer = v1618;
  int v1510 = v1->timer;
  int * v1511 = v1->reg_ready;
  int v1512 = v1511[22];
  int v1621 = v1512 + ((v1510 - v1512) & (~((v1510 - v1512) >> 31)));
  v1->timer = v1621;
  int v1514 = v1->timer;
  int * v1515 = v1->reg_ready;
  int v1516 = v1515[23];
  int v1624 = v1516 + ((v1514 - v1516) & (~((v1514 - v1516) >> 31)));
  v1->timer = v1624;
  int v1518 = v1->timer;
  int * v1519 = v1->reg_ready;
  int v1520 = v1519[24];
  int v1627 = v1520 + ((v1518 - v1520) & (~((v1518 - v1520) >> 31)));
  v1->timer = v1627;
  int v1522 = v1->timer;
  int * v1523 = v1->reg_ready;
  int v1524 = v1523[25];
  int v1630 = v1524 + ((v1522 - v1524) & (~((v1522 - v1524) >> 31)));
  v1->timer = v1630;
  int v1526 = v1->timer;
  int * v1527 = v1->reg_ready;
  int v1528 = v1527[26];
  int v1633 = v1528 + ((v1526 - v1528) & (~((v1526 - v1528) >> 31)));
  v1->timer = v1633;
  int v1530 = v1->timer;
  int * v1531 = v1->reg_ready;
  int v1532 = v1531[27];
  int v1636 = v1532 + ((v1530 - v1532) & (~((v1530 - v1532) >> 31)));
  v1->timer = v1636;
  int v1534 = v1->timer;
  int * v1535 = v1->reg_ready;
  int v1536 = v1535[28];
  int v1639 = v1536 + ((v1534 - v1536) & (~((v1534 - v1536) >> 31)));
  v1->timer = v1639;
  int v1538 = v1->timer;
  int * v1539 = v1->reg_ready;
  int v1540 = v1539[29];
  int v1642 = v1540 + ((v1538 - v1540) & (~((v1538 - v1540) >> 31)));
  v1->timer = v1642;
  int v1542 = v1->timer;
  int * v1543 = v1->reg_ready;
  int v1544 = v1543[30];
  int v1645 = v1544 + ((v1542 - v1544) & (~((v1542 - v1544) >> 31)));
  v1->timer = v1645;
  int v1546 = v1->timer;
  int * v1547 = v1->reg_ready;
  int v1548 = v1547[31];
  int v1648 = v1548 + ((v1546 - v1548) & (~((v1546 - v1548) >> 31)));
  v1->timer = v1648;
  return v1;
}

struct StateT * slot_10(struct StateT * v582) {
  int v583 = v582->timer;
  int v591 = v583 + 1;
  v582->timer = v591;
  int * v585 = v582->reg_ready;
  v585[12] = v591;
  int * v587 = v582->regs;
  v587[12] = 0;
  struct StateT * v589 = slot_11(v582);
  return v589;
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

struct StateT * slot_8(struct StateT * v545) {
  int v546 = v545->timer;
  int v554 = v546 + 1;
  v545->timer = v554;
  int * v548 = v545->reg_ready;
  v548[11] = v554;
  int * v550 = v545->regs;
  v550[11] = 0;
  struct StateT * v552 = slot_9(v545);
  return v552;
}

struct StateT * slot_4(struct StateT * v277) {
  int v278 = v277->timer;
  int v286 = v278 + 1;
  v277->timer = v286;
  int * v280 = v277->reg_ready;
  v280[11] = v286;
  int * v282 = v277->regs;
  v282[11] = 0;
  struct StateT * v284 = slot_5(v277);
  return v284;
}

struct StateT * slot_13(struct StateT * v640) {
  int v641 = v640->timer;
  int v654 = v641 + 1;
  v640->timer = v654;
  int * v643 = v640->reg_ready;
  int v644 = v643[11];
  int * v645 = v640->regs;
  int v646 = v645[11];
  int v647 = v643[10];
  int v648 = v645[10];
  int v659 = (v647 + (((v644 + ((v641 - v644) & (~((v641 - v644) >> 31)))) - v647) & (~(((v644 + ((v641 - v644) & (~((v641 - v644) >> 31)))) - v647) >> 31)))) + 1;
  v643[10] = v659;
  int * v650 = v640->regs;
  int v661 = v646 + v648;
  v650[10] = v661;
  struct StateT * v652 = slot_14(v640);
  return v652;
}

struct StateT * slot_15(struct StateT * v871) {
  int v872 = v871->timer;
  int v984 = v872 + 1;
  v871->timer = v984;
  int * v874 = v871->reg_ready;
  int v875 = v874[12];
  int * v876 = v871->regs;
  int v877 = v876[12];
  int * v878 = v871->cache_tags;
  int v989 = (((int)((unsigned int)((int)((unsigned int)(v877 + 68) >> 2)) >> 1)) & 1) * 2;
  int v879 = v878[v989];
  int v990 = ((((int)((unsigned int)((int)((unsigned int)(v877 + 68) >> 2)) >> 1)) & 1) * 2) + 1;
  int v880 = v878[v990];
  int v991 = 4 + ((((int)((unsigned int)((int)((unsigned int)(v877 + 68) >> 2)) >> 1)) & 3) * 2);
  int v881 = v878[v991];
  int v992 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v877 + 68) >> 2)) >> 1)) & 3) * 2)) + 1;
  int v882 = v878[v992];
  int * v883 = v871->cache_vals;
  bool v993 = !(((~(((v879 ^ ((int)((unsigned int)((int)((unsigned int)(v877 + 68) >> 2)) >> 1))) | (-(v879 ^ ((int)((unsigned int)((int)((unsigned int)(v877 + 68) >> 2)) >> 1))))) >> 31)) | (~(((v880 ^ ((int)((unsigned int)((int)((unsigned int)(v877 + 68) >> 2)) >> 1))) | (-(v880 ^ ((int)((unsigned int)((int)((unsigned int)(v877 + 68) >> 2)) >> 1))))) >> 31))) == 0);
  int v976;
  if (v993) {
    int * v884 = v871->cache_age;
    int v995 = ((((int)((unsigned int)((int)((unsigned int)(v877 + 68) >> 2)) >> 1)) & 1) * 2) + ((~(((v880 ^ ((int)((unsigned int)((int)((unsigned int)(v877 + 68) >> 2)) >> 1))) | (-(v880 ^ ((int)((unsigned int)((int)((unsigned int)(v877 + 68) >> 2)) >> 1))))) >> 31)) & 1);
    int v885 = v884[v995];
    int v886 = v884[v989];
    int v996 = v886 + ((int)((unsigned int)(v886 - v885) >> 31));
    v884[v989] = v996;
    int * v888 = v871->cache_age;
    int v889 = v888[v990];
    int v998 = v889 + ((int)((unsigned int)(v889 - v885) >> 31));
    v888[v990] = v998;
    int * v891 = v871->cache_age;
    v891[v995] = 0;
    v976 = v995;
  } else {
    int * v894 = v871->cache_age;
    int v1002 = (((int)((unsigned int)((int)((unsigned int)(v877 + 68) >> 2)) >> 1)) & 1) * 2;
    int v895 = v894[v1002];
    int * v896 = v871->cache_tags;
    int v897 = v896[v1002];
    int v898 = v894[v990];
    int v899 = v896[v990];
    bool v1004 = !(((~(((v881 ^ ((int)((unsigned int)((int)((unsigned int)(v877 + 68) >> 2)) >> 1))) | (-(v881 ^ ((int)((unsigned int)((int)((unsigned int)(v877 + 68) >> 2)) >> 1))))) >> 31)) | (~(((v882 ^ ((int)((unsigned int)((int)((unsigned int)(v877 + 68) >> 2)) >> 1))) | (-(v882 ^ ((int)((unsigned int)((int)((unsigned int)(v877 + 68) >> 2)) >> 1))))) >> 31))) == 0);
    int v953;
    if (v1004) {
      int * v900 = v871->cache_age;
      int v1006 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v877 + 68) >> 2)) >> 1)) & 3) * 2)) + ((~(((v882 ^ ((int)((unsigned int)((int)((unsigned int)(v877 + 68) >> 2)) >> 1))) | (-(v882 ^ ((int)((unsigned int)((int)((unsigned int)(v877 + 68) >> 2)) >> 1))))) >> 31)) & 1);
      int v901 = v900[v1006];
      int v902 = v900[v991];
      int v1007 = v902 + ((int)((unsigned int)(v902 - v901) >> 31));
      v900[v991] = v1007;
      int * v904 = v871->cache_age;
      int v905 = v904[v992];
      int v1009 = v905 + ((int)((unsigned int)(v905 - v901) >> 31));
      v904[v992] = v1009;
      int * v907 = v871->cache_age;
      v907[v1006] = 0;
      v953 = v1006;
    } else {
      int * v910 = v871->cache_age;
      int v1013 = 4 + ((((int)((unsigned int)((int)((unsigned int)(v877 + 68) >> 2)) >> 1)) & 3) * 2);
      int v911 = v910[v1013];
      int * v912 = v871->cache_tags;
      int v913 = v912[v1013];
      int v914 = v910[v992];
      int v915 = v912[v992];
      int * v916 = v871->cache_dirty;
      int v1016 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v877 + 68) >> 2)) >> 1)) & 3) * 2)) + ((((v911 + ((~(((v913 ^ -1) | (-(v913 ^ -1))) >> 31)) & 2)) - (v914 + ((~(((v915 ^ -1) | (-(v915 ^ -1))) >> 31)) & 2))) >> 31) & 1);
      int v917 = v916[v1016];
      bool v1017 = !(v917 == 0);
      if (v1017) {
        int * v918 = v871->cache_tags;
        int v919 = v918[v1016];
        int * v920 = v871->cache_vals;
        int v1020 = ((4 + ((((int)((unsigned int)((int)((unsigned int)(v877 + 68) >> 2)) >> 1)) & 3) * 2)) + ((((v911 + ((~(((v913 ^ -1) | (-(v913 ^ -1))) >> 31)) & 2)) - (v914 + ((~(((v915 ^ -1) | (-(v915 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
        int v921 = v920[v1020];
        int v1021 = (((4 + ((((int)((unsigned int)((int)((unsigned int)(v877 + 68) >> 2)) >> 1)) & 3) * 2)) + ((((v911 + ((~(((v913 ^ -1) | (-(v913 ^ -1))) >> 31)) & 2)) - (v914 + ((~(((v915 ^ -1) | (-(v915 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
        int v922 = v920[v1021];
        int * v923 = v871->mem;
        int v1023 = v919 * 2;
        v923[v1023] = v921;
        int * v925 = v871->mem;
        int v1026 = (v919 * 2) + 1;
        v925[v1026] = v922;
        ;
      } else {
        ;
      }
      int * v930 = v871->mem;
      int v1031 = ((int)((unsigned int)((int)((unsigned int)(v877 + 68) >> 2)) >> 1)) * 2;
      int v931 = v930[v1031];
      int v1032 = (((int)((unsigned int)((int)((unsigned int)(v877 + 68) >> 2)) >> 1)) * 2) + 1;
      int v932 = v930[v1032];
      int * v933 = v871->cache_vals;
      int v1034 = ((4 + ((((int)((unsigned int)((int)((unsigned int)(v877 + 68) >> 2)) >> 1)) & 3) * 2)) + ((((v911 + ((~(((v913 ^ -1) | (-(v913 ^ -1))) >> 31)) & 2)) - (v914 + ((~(((v915 ^ -1) | (-(v915 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
      v933[v1034] = v931;
      int * v935 = v871->cache_vals;
      int v1037 = (((4 + ((((int)((unsigned int)((int)((unsigned int)(v877 + 68) >> 2)) >> 1)) & 3) * 2)) + ((((v911 + ((~(((v913 ^ -1) | (-(v913 ^ -1))) >> 31)) & 2)) - (v914 + ((~(((v915 ^ -1) | (-(v915 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
      v935[v1037] = v932;
      int * v937 = v871->cache_tags;
      int v1040 = (int)((unsigned int)((int)((unsigned int)(v877 + 68) >> 2)) >> 1);
      v937[v1016] = v1040;
      int * v939 = v871->cache_dirty;
      v939[v1016] = 0;
      int * v941 = v871->cache_age;
      v941[v1016] = 1;
      int * v943 = v871->cache_age;
      int v944 = v943[v1016];
      int v945 = v943[v991];
      int v1046 = v945 + ((int)((unsigned int)(v945 - v944) >> 31));
      v943[v991] = v1046;
      int * v947 = v871->cache_age;
      int v948 = v947[v992];
      int v1048 = v948 + ((int)((unsigned int)(v948 - v944) >> 31));
      v947[v992] = v1048;
      int * v950 = v871->cache_age;
      v950[v1016] = 0;
      v953 = v1016;
    }
    int * v954 = v871->cache_vals;
    int v1051 = v953 * 2;
    int v955 = v954[v1051];
    int v1052 = (v953 * 2) + 1;
    int v956 = v954[v1052];
    int v1053 = (((((int)((unsigned int)((int)((unsigned int)(v877 + 68) >> 2)) >> 1)) & 1) * 2) + ((((v895 + ((~(((v897 ^ -1) | (-(v897 ^ -1))) >> 31)) & 2)) - (v898 + ((~(((v899 ^ -1) | (-(v899 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
    v954[v1053] = v955;
    int * v958 = v871->cache_vals;
    int v1056 = ((((((int)((unsigned int)((int)((unsigned int)(v877 + 68) >> 2)) >> 1)) & 1) * 2) + ((((v895 + ((~(((v897 ^ -1) | (-(v897 ^ -1))) >> 31)) & 2)) - (v898 + ((~(((v899 ^ -1) | (-(v899 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
    v958[v1056] = v956;
    int * v960 = v871->cache_tags;
    int v1059 = ((((int)((unsigned int)((int)((unsigned int)(v877 + 68) >> 2)) >> 1)) & 1) * 2) + ((((v895 + ((~(((v897 ^ -1) | (-(v897 ^ -1))) >> 31)) & 2)) - (v898 + ((~(((v899 ^ -1) | (-(v899 ^ -1))) >> 31)) & 2))) >> 31) & 1);
    int v1060 = (int)((unsigned int)((int)((unsigned int)(v877 + 68) >> 2)) >> 1);
    v960[v1059] = v1060;
    int * v962 = v871->cache_dirty;
    v962[v1059] = 0;
    int * v964 = v871->cache_age;
    v964[v1059] = 1;
    int * v966 = v871->cache_age;
    int v967 = v966[v1059];
    int v968 = v966[v989];
    int v1066 = v968 + ((int)((unsigned int)(v968 - v967) >> 31));
    v966[v989] = v1066;
    int * v970 = v871->cache_age;
    int v971 = v970[v990];
    int v1068 = v971 + ((int)((unsigned int)(v971 - v967) >> 31));
    v970[v990] = v1068;
    int * v973 = v871->cache_age;
    v973[v1059] = 0;
    v976 = v1059;
  }
  int v1071 = (v976 * 2) + (((int)((unsigned int)(v877 + 68) >> 2)) & 1);
  int v977 = v883[v1071];
  int * v978 = v871->reg_ready;
  int v1074 = ((v875 + ((v872 - v875) & (~((v872 - v875) >> 31)))) + 1) + ((100 ^ (((~(((v881 ^ ((int)((unsigned int)((int)((unsigned int)(v877 + 68) >> 2)) >> 1))) | (-(v881 ^ ((int)((unsigned int)((int)((unsigned int)(v877 + 68) >> 2)) >> 1))))) >> 31)) | (~(((v882 ^ ((int)((unsigned int)((int)((unsigned int)(v877 + 68) >> 2)) >> 1))) | (-(v882 ^ ((int)((unsigned int)((int)((unsigned int)(v877 + 68) >> 2)) >> 1))))) >> 31))) & 104)) ^ (((~(((v879 ^ ((int)((unsigned int)((int)((unsigned int)(v877 + 68) >> 2)) >> 1))) | (-(v879 ^ ((int)((unsigned int)((int)((unsigned int)(v877 + 68) >> 2)) >> 1))))) >> 31)) | (~(((v880 ^ ((int)((unsigned int)((int)((unsigned int)(v877 + 68) >> 2)) >> 1))) | (-(v880 ^ ((int)((unsigned int)((int)((unsigned int)(v877 + 68) >> 2)) >> 1))))) >> 31))) & (1 ^ (100 ^ (((~(((v881 ^ ((int)((unsigned int)((int)((unsigned int)(v877 + 68) >> 2)) >> 1))) | (-(v881 ^ ((int)((unsigned int)((int)((unsigned int)(v877 + 68) >> 2)) >> 1))))) >> 31)) | (~(((v882 ^ ((int)((unsigned int)((int)((unsigned int)(v877 + 68) >> 2)) >> 1))) | (-(v882 ^ ((int)((unsigned int)((int)((unsigned int)(v877 + 68) >> 2)) >> 1))))) >> 31))) & 104)))));
  v978[11] = v1074;
  int * v980 = v871->regs;
  v980[11] = v977;
  struct StateT * v982 = slot_16(v871);
  return v982;
}

struct StateT * slot_18(struct StateT * v251) {
  int v252 = v251->timer;
  int v255 = v252 + 1;
  v251->timer = v255;
  return v251;
}

struct StateT * slot_9(struct StateT * v561) {
  int v562 = v561->timer;
  int v573 = v562 + 1;
  v561->timer = v573;
  int * v564 = v561->reg_ready;
  int v565 = v564[11];
  int * v566 = v561->regs;
  int v567 = v566[11];
  int v577 = (v565 + ((v562 - v565) & (~((v562 - v565) >> 31)))) + 1;
  v564[11] = v577;
  int * v569 = v561->regs;
  int v579 = v567 + 4;
  v569[11] = v579;
  struct StateT * v571 = slot_10(v561);
  return v571;
}

struct StateT * slot_11(struct StateT * v598) {
  int v599 = v598->timer;
  int v610 = v599 + 1;
  v598->timer = v610;
  int * v601 = v598->reg_ready;
  int v602 = v601[10];
  int * v603 = v598->regs;
  int v604 = v603[10];
  int v614 = (v602 + ((v599 - v602) & (~((v599 - v602) >> 31)))) + 1;
  v601[10] = v614;
  int * v606 = v598->regs;
  int v616 = v604 << 29;
  v606[10] = v616;
  struct StateT * v608 = slot_12(v598);
  return v608;
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