// verify: clean (KLEE should report no failing assertion) [budget 1200s]
#define NUM_REGS 32
#define MEM_SIZE 64
#define SECRET_SIZE 10
#define SECRET_OFFSET 20
#define CACHE_ENTRIES 12
#define CACHE_WORDS 24

#ifdef KLEE
#include <assert.h>
#include <klee/klee.h>
#define koika_assert(b, s) klee_assert(b)
#define koika_assume(b) klee_assume(b)
#define koika_draw(x) klee_make_symbolic(&(x), sizeof(x), #x)
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

struct StateT * slot_12(struct StateT * v559);
struct StateT * slot_14(struct StateT * v589);
struct StateT * slot_6(struct StateT * v286);
struct StateT * slot_16(struct StateT * v996);
struct StateT * slot_5(struct StateT * v272);
struct StateT * slot_17(struct StateT * v1012);
struct StateT * slot_2(struct StateT * v218);
struct StateT * slot_7(struct StateT * v302);
struct StateT * slot_3(struct StateT * v245);
struct StateT * snippet(struct StateT * v0);
struct StateT * slot_10(struct StateT * v532);
struct StateT * slot_1(struct StateT * v15);
struct StateT * slot_8(struct StateT * v505);
struct StateT * slot_4(struct StateT * v259);
struct StateT * slot_13(struct StateT * v573);
struct StateT * slot_15(struct StateT * v792);
struct StateT * slot_18(struct StateT * v240);
struct StateT * slot_9(struct StateT * v518);
struct StateT * slot_11(struct StateT * v545);
struct StateT * slot_0(struct StateT * v2);
struct StateT * slot_12(struct StateT * v559) {
  int v560 = v559->timer;
  int v567 = v560 + 1;
  v559->timer = v567;
  int * v562 = v559->regs;
  int v563 = v562[10];
  int v570 = (int)((unsigned int)v563 >> 26);
  v562[10] = v570;
  struct StateT * v565 = slot_13(v559);
  return v565;
}

struct StateT * slot_14(struct StateT * v589) {
  int v590 = v589->timer;
  int v700 = v590 + 1;
  v589->timer = v700;
  int * v592 = v589->regs;
  int v593 = v592[10];
  int * v594 = v589->cache_tags;
  int v704 = (((int)((unsigned int)((int)((unsigned int)v593 >> 2)) >> 1)) & 1) * 2;
  int v595 = v594[v704];
  int v705 = ((((int)((unsigned int)((int)((unsigned int)v593 >> 2)) >> 1)) & 1) * 2) + 1;
  int v596 = v594[v705];
  int v706 = 4 + ((((int)((unsigned int)((int)((unsigned int)v593 >> 2)) >> 1)) & 3) * 2);
  int v597 = v594[v706];
  int v707 = (4 + ((((int)((unsigned int)((int)((unsigned int)v593 >> 2)) >> 1)) & 3) * 2)) + 1;
  int v598 = v594[v707];
  int v599 = v589->timer;
  int v708 = v599 + ((100 ^ (((~(((v597 ^ ((int)((unsigned int)((int)((unsigned int)v593 >> 2)) >> 1))) | (-(v597 ^ ((int)((unsigned int)((int)((unsigned int)v593 >> 2)) >> 1))))) >> 31)) | (~(((v598 ^ ((int)((unsigned int)((int)((unsigned int)v593 >> 2)) >> 1))) | (-(v598 ^ ((int)((unsigned int)((int)((unsigned int)v593 >> 2)) >> 1))))) >> 31))) & 104)) ^ (((~(((v595 ^ ((int)((unsigned int)((int)((unsigned int)v593 >> 2)) >> 1))) | (-(v595 ^ ((int)((unsigned int)((int)((unsigned int)v593 >> 2)) >> 1))))) >> 31)) | (~(((v596 ^ ((int)((unsigned int)((int)((unsigned int)v593 >> 2)) >> 1))) | (-(v596 ^ ((int)((unsigned int)((int)((unsigned int)v593 >> 2)) >> 1))))) >> 31))) & (1 ^ (100 ^ (((~(((v597 ^ ((int)((unsigned int)((int)((unsigned int)v593 >> 2)) >> 1))) | (-(v597 ^ ((int)((unsigned int)((int)((unsigned int)v593 >> 2)) >> 1))))) >> 31)) | (~(((v598 ^ ((int)((unsigned int)((int)((unsigned int)v593 >> 2)) >> 1))) | (-(v598 ^ ((int)((unsigned int)((int)((unsigned int)v593 >> 2)) >> 1))))) >> 31))) & 104)))));
  v589->timer = v708;
  int * v601 = v589->cache_vals;
  bool v709 = !(((~(((v595 ^ ((int)((unsigned int)((int)((unsigned int)v593 >> 2)) >> 1))) | (-(v595 ^ ((int)((unsigned int)((int)((unsigned int)v593 >> 2)) >> 1))))) >> 31)) | (~(((v596 ^ ((int)((unsigned int)((int)((unsigned int)v593 >> 2)) >> 1))) | (-(v596 ^ ((int)((unsigned int)((int)((unsigned int)v593 >> 2)) >> 1))))) >> 31))) == 0);
  int v694;
  if (v709) {
    int * v602 = v589->cache_age;
    int v711 = ((((int)((unsigned int)((int)((unsigned int)v593 >> 2)) >> 1)) & 1) * 2) + ((~(((v596 ^ ((int)((unsigned int)((int)((unsigned int)v593 >> 2)) >> 1))) | (-(v596 ^ ((int)((unsigned int)((int)((unsigned int)v593 >> 2)) >> 1))))) >> 31)) & 1);
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
    int v718 = (((int)((unsigned int)((int)((unsigned int)v593 >> 2)) >> 1)) & 1) * 2;
    int v613 = v612[v718];
    int * v614 = v589->cache_tags;
    int v615 = v614[v718];
    int v616 = v612[v705];
    int v617 = v614[v705];
    bool v720 = !(((~(((v597 ^ ((int)((unsigned int)((int)((unsigned int)v593 >> 2)) >> 1))) | (-(v597 ^ ((int)((unsigned int)((int)((unsigned int)v593 >> 2)) >> 1))))) >> 31)) | (~(((v598 ^ ((int)((unsigned int)((int)((unsigned int)v593 >> 2)) >> 1))) | (-(v598 ^ ((int)((unsigned int)((int)((unsigned int)v593 >> 2)) >> 1))))) >> 31))) == 0);
    int v671;
    if (v720) {
      int * v618 = v589->cache_age;
      int v722 = (4 + ((((int)((unsigned int)((int)((unsigned int)v593 >> 2)) >> 1)) & 3) * 2)) + ((~(((v598 ^ ((int)((unsigned int)((int)((unsigned int)v593 >> 2)) >> 1))) | (-(v598 ^ ((int)((unsigned int)((int)((unsigned int)v593 >> 2)) >> 1))))) >> 31)) & 1);
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
      int v729 = 4 + ((((int)((unsigned int)((int)((unsigned int)v593 >> 2)) >> 1)) & 3) * 2);
      int v629 = v628[v729];
      int * v630 = v589->cache_tags;
      int v631 = v630[v729];
      int v632 = v628[v707];
      int v633 = v630[v707];
      int * v634 = v589->cache_dirty;
      int v732 = (4 + ((((int)((unsigned int)((int)((unsigned int)v593 >> 2)) >> 1)) & 3) * 2)) + ((((v629 + ((~(((v631 ^ -1) | (-(v631 ^ -1))) >> 31)) & 2)) - (v632 + ((~(((v633 ^ -1) | (-(v633 ^ -1))) >> 31)) & 2))) >> 31) & 1);
      int v635 = v634[v732];
      bool v733 = !(v635 == 0);
      if (v733) {
        int * v636 = v589->cache_tags;
        int v637 = v636[v732];
        int * v638 = v589->cache_vals;
        int v736 = ((4 + ((((int)((unsigned int)((int)((unsigned int)v593 >> 2)) >> 1)) & 3) * 2)) + ((((v629 + ((~(((v631 ^ -1) | (-(v631 ^ -1))) >> 31)) & 2)) - (v632 + ((~(((v633 ^ -1) | (-(v633 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
        int v639 = v638[v736];
        int v737 = (((4 + ((((int)((unsigned int)((int)((unsigned int)v593 >> 2)) >> 1)) & 3) * 2)) + ((((v629 + ((~(((v631 ^ -1) | (-(v631 ^ -1))) >> 31)) & 2)) - (v632 + ((~(((v633 ^ -1) | (-(v633 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
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
      int v747 = ((int)((unsigned int)((int)((unsigned int)v593 >> 2)) >> 1)) * 2;
      int v649 = v648[v747];
      int v748 = (((int)((unsigned int)((int)((unsigned int)v593 >> 2)) >> 1)) * 2) + 1;
      int v650 = v648[v748];
      int * v651 = v589->cache_vals;
      int v750 = ((4 + ((((int)((unsigned int)((int)((unsigned int)v593 >> 2)) >> 1)) & 3) * 2)) + ((((v629 + ((~(((v631 ^ -1) | (-(v631 ^ -1))) >> 31)) & 2)) - (v632 + ((~(((v633 ^ -1) | (-(v633 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
      v651[v750] = v649;
      int * v653 = v589->cache_vals;
      int v753 = (((4 + ((((int)((unsigned int)((int)((unsigned int)v593 >> 2)) >> 1)) & 3) * 2)) + ((((v629 + ((~(((v631 ^ -1) | (-(v631 ^ -1))) >> 31)) & 2)) - (v632 + ((~(((v633 ^ -1) | (-(v633 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
      v653[v753] = v650;
      int * v655 = v589->cache_tags;
      int v756 = (int)((unsigned int)((int)((unsigned int)v593 >> 2)) >> 1);
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
    int v769 = (((((int)((unsigned int)((int)((unsigned int)v593 >> 2)) >> 1)) & 1) * 2) + ((((v613 + ((~(((v615 ^ -1) | (-(v615 ^ -1))) >> 31)) & 2)) - (v616 + ((~(((v617 ^ -1) | (-(v617 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
    v672[v769] = v673;
    int * v676 = v589->cache_vals;
    int v772 = ((((((int)((unsigned int)((int)((unsigned int)v593 >> 2)) >> 1)) & 1) * 2) + ((((v613 + ((~(((v615 ^ -1) | (-(v615 ^ -1))) >> 31)) & 2)) - (v616 + ((~(((v617 ^ -1) | (-(v617 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
    v676[v772] = v674;
    int * v678 = v589->cache_tags;
    int v775 = ((((int)((unsigned int)((int)((unsigned int)v593 >> 2)) >> 1)) & 1) * 2) + ((((v613 + ((~(((v615 ^ -1) | (-(v615 ^ -1))) >> 31)) & 2)) - (v616 + ((~(((v617 ^ -1) | (-(v617 ^ -1))) >> 31)) & 2))) >> 31) & 1);
    int v776 = (int)((unsigned int)((int)((unsigned int)v593 >> 2)) >> 1);
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
  int v787 = (v694 * 2) + (((int)((unsigned int)v593 >> 2)) & 1);
  int v695 = v601[v787];
  int * v696 = v589->regs;
  v696[10] = v695;
  struct StateT * v698 = slot_15(v589);
  return v698;
}

struct StateT * slot_6(struct StateT * v286) {
  int v287 = v286->timer;
  int v295 = v287 + 1;
  v286->timer = v295;
  int * v289 = v286->regs;
  int v290 = v289[11];
  int v291 = v289[10];
  int v299 = v290 + v291;
  v289[10] = v299;
  struct StateT * v293 = slot_7(v286);
  return v293;
}

struct StateT * slot_16(struct StateT * v996) {
  int v997 = v996->timer;
  int v1005 = v997 + 1;
  v996->timer = v1005;
  int * v999 = v996->regs;
  int v1000 = v999[11];
  int v1001 = v999[10];
  int v1009 = v1000 & v1001;
  v999[10] = v1009;
  struct StateT * v1003 = slot_17(v996);
  return v1003;
}

struct StateT * slot_5(struct StateT * v272) {
  int v273 = v272->timer;
  int v280 = v273 + 1;
  v272->timer = v280;
  int * v275 = v272->regs;
  int v276 = v275[11];
  int v283 = v276 + 72;
  v275[11] = v283;
  struct StateT * v278 = slot_6(v272);
  return v278;
}

struct StateT * slot_17(struct StateT * v1012) {
  int v1013 = v1012->timer;
  int v1183 = v1013 + 1;
  v1012->timer = v1183;
  int * v1015 = v1012->regs;
  int v1016 = v1015[12];
  int v1017 = v1015[10];
  int * v1018 = v1012->cache_tags;
  int v1188 = (((int)((unsigned int)((int)((unsigned int)(v1016 + 68) >> 2)) >> 1)) & 1) * 2;
  int v1019 = v1018[v1188];
  int v1189 = ((((int)((unsigned int)((int)((unsigned int)(v1016 + 68) >> 2)) >> 1)) & 1) * 2) + 1;
  int v1020 = v1018[v1189];
  int v1190 = 4 + ((((int)((unsigned int)((int)((unsigned int)(v1016 + 68) >> 2)) >> 1)) & 3) * 2);
  int v1021 = v1018[v1190];
  int v1191 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v1016 + 68) >> 2)) >> 1)) & 3) * 2)) + 1;
  int v1022 = v1018[v1191];
  int v1023 = v1012->timer;
  int v1192 = v1023 + ((100 ^ (((~(((v1021 ^ ((int)((unsigned int)((int)((unsigned int)(v1016 + 68) >> 2)) >> 1))) | (-(v1021 ^ ((int)((unsigned int)((int)((unsigned int)(v1016 + 68) >> 2)) >> 1))))) >> 31)) | (~(((v1022 ^ ((int)((unsigned int)((int)((unsigned int)(v1016 + 68) >> 2)) >> 1))) | (-(v1022 ^ ((int)((unsigned int)((int)((unsigned int)(v1016 + 68) >> 2)) >> 1))))) >> 31))) & 104)) ^ (((~(((v1019 ^ ((int)((unsigned int)((int)((unsigned int)(v1016 + 68) >> 2)) >> 1))) | (-(v1019 ^ ((int)((unsigned int)((int)((unsigned int)(v1016 + 68) >> 2)) >> 1))))) >> 31)) | (~(((v1020 ^ ((int)((unsigned int)((int)((unsigned int)(v1016 + 68) >> 2)) >> 1))) | (-(v1020 ^ ((int)((unsigned int)((int)((unsigned int)(v1016 + 68) >> 2)) >> 1))))) >> 31))) & (1 ^ (100 ^ (((~(((v1021 ^ ((int)((unsigned int)((int)((unsigned int)(v1016 + 68) >> 2)) >> 1))) | (-(v1021 ^ ((int)((unsigned int)((int)((unsigned int)(v1016 + 68) >> 2)) >> 1))))) >> 31)) | (~(((v1022 ^ ((int)((unsigned int)((int)((unsigned int)(v1016 + 68) >> 2)) >> 1))) | (-(v1022 ^ ((int)((unsigned int)((int)((unsigned int)(v1016 + 68) >> 2)) >> 1))))) >> 31))) & 104)))));
  v1012->timer = v1192;
  bool v1193 = !(((~(((v1019 ^ ((int)((unsigned int)((int)((unsigned int)(v1016 + 68) >> 2)) >> 1))) | (-(v1019 ^ ((int)((unsigned int)((int)((unsigned int)(v1016 + 68) >> 2)) >> 1))))) >> 31)) | (~(((v1020 ^ ((int)((unsigned int)((int)((unsigned int)(v1016 + 68) >> 2)) >> 1))) | (-(v1020 ^ ((int)((unsigned int)((int)((unsigned int)(v1016 + 68) >> 2)) >> 1))))) >> 31))) == 0);
  int v1117;
  if (v1193) {
    int * v1025 = v1012->cache_age;
    int v1195 = ((((int)((unsigned int)((int)((unsigned int)(v1016 + 68) >> 2)) >> 1)) & 1) * 2) + ((~(((v1020 ^ ((int)((unsigned int)((int)((unsigned int)(v1016 + 68) >> 2)) >> 1))) | (-(v1020 ^ ((int)((unsigned int)((int)((unsigned int)(v1016 + 68) >> 2)) >> 1))))) >> 31)) & 1);
    int v1026 = v1025[v1195];
    int v1027 = v1025[v1188];
    int v1196 = v1027 + ((int)((unsigned int)(v1027 - v1026) >> 31));
    v1025[v1188] = v1196;
    int * v1029 = v1012->cache_age;
    int v1030 = v1029[v1189];
    int v1198 = v1030 + ((int)((unsigned int)(v1030 - v1026) >> 31));
    v1029[v1189] = v1198;
    int * v1032 = v1012->cache_age;
    v1032[v1195] = 0;
    v1117 = v1195;
  } else {
    int * v1035 = v1012->cache_age;
    int v1202 = (((int)((unsigned int)((int)((unsigned int)(v1016 + 68) >> 2)) >> 1)) & 1) * 2;
    int v1036 = v1035[v1202];
    int * v1037 = v1012->cache_tags;
    int v1038 = v1037[v1202];
    int v1039 = v1035[v1189];
    int v1040 = v1037[v1189];
    bool v1204 = !(((~(((v1021 ^ ((int)((unsigned int)((int)((unsigned int)(v1016 + 68) >> 2)) >> 1))) | (-(v1021 ^ ((int)((unsigned int)((int)((unsigned int)(v1016 + 68) >> 2)) >> 1))))) >> 31)) | (~(((v1022 ^ ((int)((unsigned int)((int)((unsigned int)(v1016 + 68) >> 2)) >> 1))) | (-(v1022 ^ ((int)((unsigned int)((int)((unsigned int)(v1016 + 68) >> 2)) >> 1))))) >> 31))) == 0);
    int v1094;
    if (v1204) {
      int * v1041 = v1012->cache_age;
      int v1206 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v1016 + 68) >> 2)) >> 1)) & 3) * 2)) + ((~(((v1022 ^ ((int)((unsigned int)((int)((unsigned int)(v1016 + 68) >> 2)) >> 1))) | (-(v1022 ^ ((int)((unsigned int)((int)((unsigned int)(v1016 + 68) >> 2)) >> 1))))) >> 31)) & 1);
      int v1042 = v1041[v1206];
      int v1043 = v1041[v1190];
      int v1207 = v1043 + ((int)((unsigned int)(v1043 - v1042) >> 31));
      v1041[v1190] = v1207;
      int * v1045 = v1012->cache_age;
      int v1046 = v1045[v1191];
      int v1209 = v1046 + ((int)((unsigned int)(v1046 - v1042) >> 31));
      v1045[v1191] = v1209;
      int * v1048 = v1012->cache_age;
      v1048[v1206] = 0;
      v1094 = v1206;
    } else {
      int * v1051 = v1012->cache_age;
      int v1213 = 4 + ((((int)((unsigned int)((int)((unsigned int)(v1016 + 68) >> 2)) >> 1)) & 3) * 2);
      int v1052 = v1051[v1213];
      int * v1053 = v1012->cache_tags;
      int v1054 = v1053[v1213];
      int v1055 = v1051[v1191];
      int v1056 = v1053[v1191];
      int * v1057 = v1012->cache_dirty;
      int v1216 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v1016 + 68) >> 2)) >> 1)) & 3) * 2)) + ((((v1052 + ((~(((v1054 ^ -1) | (-(v1054 ^ -1))) >> 31)) & 2)) - (v1055 + ((~(((v1056 ^ -1) | (-(v1056 ^ -1))) >> 31)) & 2))) >> 31) & 1);
      int v1058 = v1057[v1216];
      bool v1217 = !(v1058 == 0);
      if (v1217) {
        int * v1059 = v1012->cache_tags;
        int v1060 = v1059[v1216];
        int * v1061 = v1012->cache_vals;
        int v1220 = ((4 + ((((int)((unsigned int)((int)((unsigned int)(v1016 + 68) >> 2)) >> 1)) & 3) * 2)) + ((((v1052 + ((~(((v1054 ^ -1) | (-(v1054 ^ -1))) >> 31)) & 2)) - (v1055 + ((~(((v1056 ^ -1) | (-(v1056 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
        int v1062 = v1061[v1220];
        int v1221 = (((4 + ((((int)((unsigned int)((int)((unsigned int)(v1016 + 68) >> 2)) >> 1)) & 3) * 2)) + ((((v1052 + ((~(((v1054 ^ -1) | (-(v1054 ^ -1))) >> 31)) & 2)) - (v1055 + ((~(((v1056 ^ -1) | (-(v1056 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
        int v1063 = v1061[v1221];
        int * v1064 = v1012->mem;
        int v1223 = v1060 * 2;
        v1064[v1223] = v1062;
        int * v1066 = v1012->mem;
        int v1226 = (v1060 * 2) + 1;
        v1066[v1226] = v1063;
        ;
      } else {
        ;
      }
      int * v1071 = v1012->mem;
      int v1231 = ((int)((unsigned int)((int)((unsigned int)(v1016 + 68) >> 2)) >> 1)) * 2;
      int v1072 = v1071[v1231];
      int v1232 = (((int)((unsigned int)((int)((unsigned int)(v1016 + 68) >> 2)) >> 1)) * 2) + 1;
      int v1073 = v1071[v1232];
      int * v1074 = v1012->cache_vals;
      int v1234 = ((4 + ((((int)((unsigned int)((int)((unsigned int)(v1016 + 68) >> 2)) >> 1)) & 3) * 2)) + ((((v1052 + ((~(((v1054 ^ -1) | (-(v1054 ^ -1))) >> 31)) & 2)) - (v1055 + ((~(((v1056 ^ -1) | (-(v1056 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
      v1074[v1234] = v1072;
      int * v1076 = v1012->cache_vals;
      int v1237 = (((4 + ((((int)((unsigned int)((int)((unsigned int)(v1016 + 68) >> 2)) >> 1)) & 3) * 2)) + ((((v1052 + ((~(((v1054 ^ -1) | (-(v1054 ^ -1))) >> 31)) & 2)) - (v1055 + ((~(((v1056 ^ -1) | (-(v1056 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
      v1076[v1237] = v1073;
      int * v1078 = v1012->cache_tags;
      int v1240 = (int)((unsigned int)((int)((unsigned int)(v1016 + 68) >> 2)) >> 1);
      v1078[v1216] = v1240;
      int * v1080 = v1012->cache_dirty;
      v1080[v1216] = 0;
      int * v1082 = v1012->cache_age;
      v1082[v1216] = 1;
      int * v1084 = v1012->cache_age;
      int v1085 = v1084[v1216];
      int v1086 = v1084[v1190];
      int v1246 = v1086 + ((int)((unsigned int)(v1086 - v1085) >> 31));
      v1084[v1190] = v1246;
      int * v1088 = v1012->cache_age;
      int v1089 = v1088[v1191];
      int v1248 = v1089 + ((int)((unsigned int)(v1089 - v1085) >> 31));
      v1088[v1191] = v1248;
      int * v1091 = v1012->cache_age;
      v1091[v1216] = 0;
      v1094 = v1216;
    }
    int * v1095 = v1012->cache_vals;
    int v1251 = v1094 * 2;
    int v1096 = v1095[v1251];
    int v1252 = (v1094 * 2) + 1;
    int v1097 = v1095[v1252];
    int v1253 = (((((int)((unsigned int)((int)((unsigned int)(v1016 + 68) >> 2)) >> 1)) & 1) * 2) + ((((v1036 + ((~(((v1038 ^ -1) | (-(v1038 ^ -1))) >> 31)) & 2)) - (v1039 + ((~(((v1040 ^ -1) | (-(v1040 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
    v1095[v1253] = v1096;
    int * v1099 = v1012->cache_vals;
    int v1256 = ((((((int)((unsigned int)((int)((unsigned int)(v1016 + 68) >> 2)) >> 1)) & 1) * 2) + ((((v1036 + ((~(((v1038 ^ -1) | (-(v1038 ^ -1))) >> 31)) & 2)) - (v1039 + ((~(((v1040 ^ -1) | (-(v1040 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
    v1099[v1256] = v1097;
    int * v1101 = v1012->cache_tags;
    int v1259 = ((((int)((unsigned int)((int)((unsigned int)(v1016 + 68) >> 2)) >> 1)) & 1) * 2) + ((((v1036 + ((~(((v1038 ^ -1) | (-(v1038 ^ -1))) >> 31)) & 2)) - (v1039 + ((~(((v1040 ^ -1) | (-(v1040 ^ -1))) >> 31)) & 2))) >> 31) & 1);
    int v1260 = (int)((unsigned int)((int)((unsigned int)(v1016 + 68) >> 2)) >> 1);
    v1101[v1259] = v1260;
    int * v1103 = v1012->cache_dirty;
    v1103[v1259] = 0;
    int * v1105 = v1012->cache_age;
    v1105[v1259] = 1;
    int * v1107 = v1012->cache_age;
    int v1108 = v1107[v1259];
    int v1109 = v1107[v1188];
    int v1266 = v1109 + ((int)((unsigned int)(v1109 - v1108) >> 31));
    v1107[v1188] = v1266;
    int * v1111 = v1012->cache_age;
    int v1112 = v1111[v1189];
    int v1268 = v1112 + ((int)((unsigned int)(v1112 - v1108) >> 31));
    v1111[v1189] = v1268;
    int * v1114 = v1012->cache_age;
    v1114[v1259] = 0;
    v1117 = v1259;
  }
  int * v1118 = v1012->cache_vals;
  int v1271 = (v1117 * 2) + (((int)((unsigned int)(v1016 + 68) >> 2)) & 1);
  v1118[v1271] = v1017;
  int * v1120 = v1012->cache_tags;
  int v1121 = v1120[v1190];
  int v1122 = v1120[v1191];
  bool v1274 = !(((~(((v1121 ^ ((int)((unsigned int)((int)((unsigned int)(v1016 + 68) >> 2)) >> 1))) | (-(v1121 ^ ((int)((unsigned int)((int)((unsigned int)(v1016 + 68) >> 2)) >> 1))))) >> 31)) | (~(((v1122 ^ ((int)((unsigned int)((int)((unsigned int)(v1016 + 68) >> 2)) >> 1))) | (-(v1122 ^ ((int)((unsigned int)((int)((unsigned int)(v1016 + 68) >> 2)) >> 1))))) >> 31))) == 0);
  int v1176;
  if (v1274) {
    int * v1123 = v1012->cache_age;
    int v1276 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v1016 + 68) >> 2)) >> 1)) & 3) * 2)) + ((~(((v1122 ^ ((int)((unsigned int)((int)((unsigned int)(v1016 + 68) >> 2)) >> 1))) | (-(v1122 ^ ((int)((unsigned int)((int)((unsigned int)(v1016 + 68) >> 2)) >> 1))))) >> 31)) & 1);
    int v1124 = v1123[v1276];
    int v1125 = v1123[v1190];
    int v1277 = v1125 + ((int)((unsigned int)(v1125 - v1124) >> 31));
    v1123[v1190] = v1277;
    int * v1127 = v1012->cache_age;
    int v1128 = v1127[v1191];
    int v1279 = v1128 + ((int)((unsigned int)(v1128 - v1124) >> 31));
    v1127[v1191] = v1279;
    int * v1130 = v1012->cache_age;
    v1130[v1276] = 0;
    v1176 = v1276;
  } else {
    int * v1133 = v1012->cache_age;
    int v1283 = 4 + ((((int)((unsigned int)((int)((unsigned int)(v1016 + 68) >> 2)) >> 1)) & 3) * 2);
    int v1134 = v1133[v1283];
    int * v1135 = v1012->cache_tags;
    int v1136 = v1135[v1283];
    int v1137 = v1133[v1191];
    int v1138 = v1135[v1191];
    int * v1139 = v1012->cache_dirty;
    int v1286 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v1016 + 68) >> 2)) >> 1)) & 3) * 2)) + ((((v1134 + ((~(((v1136 ^ -1) | (-(v1136 ^ -1))) >> 31)) & 2)) - (v1137 + ((~(((v1138 ^ -1) | (-(v1138 ^ -1))) >> 31)) & 2))) >> 31) & 1);
    int v1140 = v1139[v1286];
    bool v1287 = !(v1140 == 0);
    if (v1287) {
      int * v1141 = v1012->cache_tags;
      int v1142 = v1141[v1286];
      int * v1143 = v1012->cache_vals;
      int v1290 = ((4 + ((((int)((unsigned int)((int)((unsigned int)(v1016 + 68) >> 2)) >> 1)) & 3) * 2)) + ((((v1134 + ((~(((v1136 ^ -1) | (-(v1136 ^ -1))) >> 31)) & 2)) - (v1137 + ((~(((v1138 ^ -1) | (-(v1138 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
      int v1144 = v1143[v1290];
      int v1291 = (((4 + ((((int)((unsigned int)((int)((unsigned int)(v1016 + 68) >> 2)) >> 1)) & 3) * 2)) + ((((v1134 + ((~(((v1136 ^ -1) | (-(v1136 ^ -1))) >> 31)) & 2)) - (v1137 + ((~(((v1138 ^ -1) | (-(v1138 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
      int v1145 = v1143[v1291];
      int * v1146 = v1012->mem;
      int v1293 = v1142 * 2;
      v1146[v1293] = v1144;
      int * v1148 = v1012->mem;
      int v1296 = (v1142 * 2) + 1;
      v1148[v1296] = v1145;
      ;
    } else {
      ;
    }
    int * v1153 = v1012->mem;
    int v1301 = ((int)((unsigned int)((int)((unsigned int)(v1016 + 68) >> 2)) >> 1)) * 2;
    int v1154 = v1153[v1301];
    int v1302 = (((int)((unsigned int)((int)((unsigned int)(v1016 + 68) >> 2)) >> 1)) * 2) + 1;
    int v1155 = v1153[v1302];
    int * v1156 = v1012->cache_vals;
    int v1304 = ((4 + ((((int)((unsigned int)((int)((unsigned int)(v1016 + 68) >> 2)) >> 1)) & 3) * 2)) + ((((v1134 + ((~(((v1136 ^ -1) | (-(v1136 ^ -1))) >> 31)) & 2)) - (v1137 + ((~(((v1138 ^ -1) | (-(v1138 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
    v1156[v1304] = v1154;
    int * v1158 = v1012->cache_vals;
    int v1307 = (((4 + ((((int)((unsigned int)((int)((unsigned int)(v1016 + 68) >> 2)) >> 1)) & 3) * 2)) + ((((v1134 + ((~(((v1136 ^ -1) | (-(v1136 ^ -1))) >> 31)) & 2)) - (v1137 + ((~(((v1138 ^ -1) | (-(v1138 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
    v1158[v1307] = v1155;
    int * v1160 = v1012->cache_tags;
    int v1310 = (int)((unsigned int)((int)((unsigned int)(v1016 + 68) >> 2)) >> 1);
    v1160[v1286] = v1310;
    int * v1162 = v1012->cache_dirty;
    v1162[v1286] = 0;
    int * v1164 = v1012->cache_age;
    v1164[v1286] = 1;
    int * v1166 = v1012->cache_age;
    int v1167 = v1166[v1286];
    int v1168 = v1166[v1190];
    int v1316 = v1168 + ((int)((unsigned int)(v1168 - v1167) >> 31));
    v1166[v1190] = v1316;
    int * v1170 = v1012->cache_age;
    int v1171 = v1170[v1191];
    int v1318 = v1171 + ((int)((unsigned int)(v1171 - v1167) >> 31));
    v1170[v1191] = v1318;
    int * v1173 = v1012->cache_age;
    v1173[v1286] = 0;
    v1176 = v1286;
  }
  int * v1177 = v1012->cache_vals;
  int v1321 = (v1176 * 2) + (((int)((unsigned int)(v1016 + 68) >> 2)) & 1);
  v1177[v1321] = v1017;
  int * v1179 = v1012->cache_dirty;
  v1179[v1176] = 1;
  struct StateT * v1181 = slot_18(v1012);
  return v1181;
}

struct StateT * slot_2(struct StateT * v218) {
  int v219 = v218->timer;
  int v230 = v219 + 1;
  v218->timer = v230;
  int * v221 = v218->regs;
  int v222 = v221[10];
  int v223 = v221[11];
  bool v234 = (v222 ^ -2147483648) >= (v223 ^ -2147483648);
  struct StateT * v228;
  if (v234) {
    struct StateT * v224 = slot_18(v218);
    v228 = v224;
  } else {
    struct StateT * v226 = slot_3(v218);
    v228 = v226;
  }
  return v228;
}

struct StateT * slot_7(struct StateT * v302) {
  int v303 = v302->timer;
  int v413 = v303 + 1;
  v302->timer = v413;
  int * v305 = v302->regs;
  int v306 = v305[10];
  int * v307 = v302->cache_tags;
  int v417 = (((int)((unsigned int)((int)((unsigned int)v306 >> 2)) >> 1)) & 1) * 2;
  int v308 = v307[v417];
  int v418 = ((((int)((unsigned int)((int)((unsigned int)v306 >> 2)) >> 1)) & 1) * 2) + 1;
  int v309 = v307[v418];
  int v419 = 4 + ((((int)((unsigned int)((int)((unsigned int)v306 >> 2)) >> 1)) & 3) * 2);
  int v310 = v307[v419];
  int v420 = (4 + ((((int)((unsigned int)((int)((unsigned int)v306 >> 2)) >> 1)) & 3) * 2)) + 1;
  int v311 = v307[v420];
  int v312 = v302->timer;
  int v421 = v312 + ((100 ^ (((~(((v310 ^ ((int)((unsigned int)((int)((unsigned int)v306 >> 2)) >> 1))) | (-(v310 ^ ((int)((unsigned int)((int)((unsigned int)v306 >> 2)) >> 1))))) >> 31)) | (~(((v311 ^ ((int)((unsigned int)((int)((unsigned int)v306 >> 2)) >> 1))) | (-(v311 ^ ((int)((unsigned int)((int)((unsigned int)v306 >> 2)) >> 1))))) >> 31))) & 104)) ^ (((~(((v308 ^ ((int)((unsigned int)((int)((unsigned int)v306 >> 2)) >> 1))) | (-(v308 ^ ((int)((unsigned int)((int)((unsigned int)v306 >> 2)) >> 1))))) >> 31)) | (~(((v309 ^ ((int)((unsigned int)((int)((unsigned int)v306 >> 2)) >> 1))) | (-(v309 ^ ((int)((unsigned int)((int)((unsigned int)v306 >> 2)) >> 1))))) >> 31))) & (1 ^ (100 ^ (((~(((v310 ^ ((int)((unsigned int)((int)((unsigned int)v306 >> 2)) >> 1))) | (-(v310 ^ ((int)((unsigned int)((int)((unsigned int)v306 >> 2)) >> 1))))) >> 31)) | (~(((v311 ^ ((int)((unsigned int)((int)((unsigned int)v306 >> 2)) >> 1))) | (-(v311 ^ ((int)((unsigned int)((int)((unsigned int)v306 >> 2)) >> 1))))) >> 31))) & 104)))));
  v302->timer = v421;
  int * v314 = v302->cache_vals;
  bool v422 = !(((~(((v308 ^ ((int)((unsigned int)((int)((unsigned int)v306 >> 2)) >> 1))) | (-(v308 ^ ((int)((unsigned int)((int)((unsigned int)v306 >> 2)) >> 1))))) >> 31)) | (~(((v309 ^ ((int)((unsigned int)((int)((unsigned int)v306 >> 2)) >> 1))) | (-(v309 ^ ((int)((unsigned int)((int)((unsigned int)v306 >> 2)) >> 1))))) >> 31))) == 0);
  int v407;
  if (v422) {
    int * v315 = v302->cache_age;
    int v424 = ((((int)((unsigned int)((int)((unsigned int)v306 >> 2)) >> 1)) & 1) * 2) + ((~(((v309 ^ ((int)((unsigned int)((int)((unsigned int)v306 >> 2)) >> 1))) | (-(v309 ^ ((int)((unsigned int)((int)((unsigned int)v306 >> 2)) >> 1))))) >> 31)) & 1);
    int v316 = v315[v424];
    int v317 = v315[v417];
    int v425 = v317 + ((int)((unsigned int)(v317 - v316) >> 31));
    v315[v417] = v425;
    int * v319 = v302->cache_age;
    int v320 = v319[v418];
    int v427 = v320 + ((int)((unsigned int)(v320 - v316) >> 31));
    v319[v418] = v427;
    int * v322 = v302->cache_age;
    v322[v424] = 0;
    v407 = v424;
  } else {
    int * v325 = v302->cache_age;
    int v431 = (((int)((unsigned int)((int)((unsigned int)v306 >> 2)) >> 1)) & 1) * 2;
    int v326 = v325[v431];
    int * v327 = v302->cache_tags;
    int v328 = v327[v431];
    int v329 = v325[v418];
    int v330 = v327[v418];
    bool v433 = !(((~(((v310 ^ ((int)((unsigned int)((int)((unsigned int)v306 >> 2)) >> 1))) | (-(v310 ^ ((int)((unsigned int)((int)((unsigned int)v306 >> 2)) >> 1))))) >> 31)) | (~(((v311 ^ ((int)((unsigned int)((int)((unsigned int)v306 >> 2)) >> 1))) | (-(v311 ^ ((int)((unsigned int)((int)((unsigned int)v306 >> 2)) >> 1))))) >> 31))) == 0);
    int v384;
    if (v433) {
      int * v331 = v302->cache_age;
      int v435 = (4 + ((((int)((unsigned int)((int)((unsigned int)v306 >> 2)) >> 1)) & 3) * 2)) + ((~(((v311 ^ ((int)((unsigned int)((int)((unsigned int)v306 >> 2)) >> 1))) | (-(v311 ^ ((int)((unsigned int)((int)((unsigned int)v306 >> 2)) >> 1))))) >> 31)) & 1);
      int v332 = v331[v435];
      int v333 = v331[v419];
      int v436 = v333 + ((int)((unsigned int)(v333 - v332) >> 31));
      v331[v419] = v436;
      int * v335 = v302->cache_age;
      int v336 = v335[v420];
      int v438 = v336 + ((int)((unsigned int)(v336 - v332) >> 31));
      v335[v420] = v438;
      int * v338 = v302->cache_age;
      v338[v435] = 0;
      v384 = v435;
    } else {
      int * v341 = v302->cache_age;
      int v442 = 4 + ((((int)((unsigned int)((int)((unsigned int)v306 >> 2)) >> 1)) & 3) * 2);
      int v342 = v341[v442];
      int * v343 = v302->cache_tags;
      int v344 = v343[v442];
      int v345 = v341[v420];
      int v346 = v343[v420];
      int * v347 = v302->cache_dirty;
      int v445 = (4 + ((((int)((unsigned int)((int)((unsigned int)v306 >> 2)) >> 1)) & 3) * 2)) + ((((v342 + ((~(((v344 ^ -1) | (-(v344 ^ -1))) >> 31)) & 2)) - (v345 + ((~(((v346 ^ -1) | (-(v346 ^ -1))) >> 31)) & 2))) >> 31) & 1);
      int v348 = v347[v445];
      bool v446 = !(v348 == 0);
      if (v446) {
        int * v349 = v302->cache_tags;
        int v350 = v349[v445];
        int * v351 = v302->cache_vals;
        int v449 = ((4 + ((((int)((unsigned int)((int)((unsigned int)v306 >> 2)) >> 1)) & 3) * 2)) + ((((v342 + ((~(((v344 ^ -1) | (-(v344 ^ -1))) >> 31)) & 2)) - (v345 + ((~(((v346 ^ -1) | (-(v346 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
        int v352 = v351[v449];
        int v450 = (((4 + ((((int)((unsigned int)((int)((unsigned int)v306 >> 2)) >> 1)) & 3) * 2)) + ((((v342 + ((~(((v344 ^ -1) | (-(v344 ^ -1))) >> 31)) & 2)) - (v345 + ((~(((v346 ^ -1) | (-(v346 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
        int v353 = v351[v450];
        int * v354 = v302->mem;
        int v452 = v350 * 2;
        v354[v452] = v352;
        int * v356 = v302->mem;
        int v455 = (v350 * 2) + 1;
        v356[v455] = v353;
        ;
      } else {
        ;
      }
      int * v361 = v302->mem;
      int v460 = ((int)((unsigned int)((int)((unsigned int)v306 >> 2)) >> 1)) * 2;
      int v362 = v361[v460];
      int v461 = (((int)((unsigned int)((int)((unsigned int)v306 >> 2)) >> 1)) * 2) + 1;
      int v363 = v361[v461];
      int * v364 = v302->cache_vals;
      int v463 = ((4 + ((((int)((unsigned int)((int)((unsigned int)v306 >> 2)) >> 1)) & 3) * 2)) + ((((v342 + ((~(((v344 ^ -1) | (-(v344 ^ -1))) >> 31)) & 2)) - (v345 + ((~(((v346 ^ -1) | (-(v346 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
      v364[v463] = v362;
      int * v366 = v302->cache_vals;
      int v466 = (((4 + ((((int)((unsigned int)((int)((unsigned int)v306 >> 2)) >> 1)) & 3) * 2)) + ((((v342 + ((~(((v344 ^ -1) | (-(v344 ^ -1))) >> 31)) & 2)) - (v345 + ((~(((v346 ^ -1) | (-(v346 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
      v366[v466] = v363;
      int * v368 = v302->cache_tags;
      int v469 = (int)((unsigned int)((int)((unsigned int)v306 >> 2)) >> 1);
      v368[v445] = v469;
      int * v370 = v302->cache_dirty;
      v370[v445] = 0;
      int * v372 = v302->cache_age;
      v372[v445] = 1;
      int * v374 = v302->cache_age;
      int v375 = v374[v445];
      int v376 = v374[v419];
      int v475 = v376 + ((int)((unsigned int)(v376 - v375) >> 31));
      v374[v419] = v475;
      int * v378 = v302->cache_age;
      int v379 = v378[v420];
      int v477 = v379 + ((int)((unsigned int)(v379 - v375) >> 31));
      v378[v420] = v477;
      int * v381 = v302->cache_age;
      v381[v445] = 0;
      v384 = v445;
    }
    int * v385 = v302->cache_vals;
    int v480 = v384 * 2;
    int v386 = v385[v480];
    int v481 = (v384 * 2) + 1;
    int v387 = v385[v481];
    int v482 = (((((int)((unsigned int)((int)((unsigned int)v306 >> 2)) >> 1)) & 1) * 2) + ((((v326 + ((~(((v328 ^ -1) | (-(v328 ^ -1))) >> 31)) & 2)) - (v329 + ((~(((v330 ^ -1) | (-(v330 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
    v385[v482] = v386;
    int * v389 = v302->cache_vals;
    int v485 = ((((((int)((unsigned int)((int)((unsigned int)v306 >> 2)) >> 1)) & 1) * 2) + ((((v326 + ((~(((v328 ^ -1) | (-(v328 ^ -1))) >> 31)) & 2)) - (v329 + ((~(((v330 ^ -1) | (-(v330 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
    v389[v485] = v387;
    int * v391 = v302->cache_tags;
    int v488 = ((((int)((unsigned int)((int)((unsigned int)v306 >> 2)) >> 1)) & 1) * 2) + ((((v326 + ((~(((v328 ^ -1) | (-(v328 ^ -1))) >> 31)) & 2)) - (v329 + ((~(((v330 ^ -1) | (-(v330 ^ -1))) >> 31)) & 2))) >> 31) & 1);
    int v489 = (int)((unsigned int)((int)((unsigned int)v306 >> 2)) >> 1);
    v391[v488] = v489;
    int * v393 = v302->cache_dirty;
    v393[v488] = 0;
    int * v395 = v302->cache_age;
    v395[v488] = 1;
    int * v397 = v302->cache_age;
    int v398 = v397[v488];
    int v399 = v397[v417];
    int v495 = v399 + ((int)((unsigned int)(v399 - v398) >> 31));
    v397[v417] = v495;
    int * v401 = v302->cache_age;
    int v402 = v401[v418];
    int v497 = v402 + ((int)((unsigned int)(v402 - v398) >> 31));
    v401[v418] = v497;
    int * v404 = v302->cache_age;
    v404[v488] = 0;
    v407 = v488;
  }
  int v500 = (v407 * 2) + (((int)((unsigned int)v306 >> 2)) & 1);
  int v408 = v314[v500];
  int * v409 = v302->regs;
  v409[10] = v408;
  struct StateT * v411 = slot_8(v302);
  return v411;
}

struct StateT * slot_3(struct StateT * v245) {
  int v246 = v245->timer;
  int v253 = v246 + 1;
  v245->timer = v253;
  int * v248 = v245->regs;
  int v249 = v248[10];
  int v256 = v249 << 2;
  v248[10] = v256;
  struct StateT * v251 = slot_4(v245);
  return v251;
}

struct StateT * snippet(struct StateT * v0) {
  struct StateT * v1 = slot_0(v0);
  return v1;
}

struct StateT * slot_10(struct StateT * v532) {
  int v533 = v532->timer;
  int v539 = v533 + 1;
  v532->timer = v539;
  int * v535 = v532->regs;
  v535[12] = 0;
  struct StateT * v537 = slot_11(v532);
  return v537;
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

struct StateT * slot_8(struct StateT * v505) {
  int v506 = v505->timer;
  int v512 = v506 + 1;
  v505->timer = v512;
  int * v508 = v505->regs;
  v508[11] = 0;
  struct StateT * v510 = slot_9(v505);
  return v510;
}

struct StateT * slot_4(struct StateT * v259) {
  int v260 = v259->timer;
  int v266 = v260 + 1;
  v259->timer = v266;
  int * v262 = v259->regs;
  v262[11] = 0;
  struct StateT * v264 = slot_5(v259);
  return v264;
}

struct StateT * slot_13(struct StateT * v573) {
  int v574 = v573->timer;
  int v582 = v574 + 1;
  v573->timer = v582;
  int * v576 = v573->regs;
  int v577 = v576[11];
  int v578 = v576[10];
  int v586 = v577 + v578;
  v576[10] = v586;
  struct StateT * v580 = slot_14(v573);
  return v580;
}

struct StateT * slot_15(struct StateT * v792) {
  int v793 = v792->timer;
  int v903 = v793 + 1;
  v792->timer = v903;
  int * v795 = v792->regs;
  int v796 = v795[12];
  int * v797 = v792->cache_tags;
  int v907 = (((int)((unsigned int)((int)((unsigned int)(v796 + 68) >> 2)) >> 1)) & 1) * 2;
  int v798 = v797[v907];
  int v908 = ((((int)((unsigned int)((int)((unsigned int)(v796 + 68) >> 2)) >> 1)) & 1) * 2) + 1;
  int v799 = v797[v908];
  int v909 = 4 + ((((int)((unsigned int)((int)((unsigned int)(v796 + 68) >> 2)) >> 1)) & 3) * 2);
  int v800 = v797[v909];
  int v910 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v796 + 68) >> 2)) >> 1)) & 3) * 2)) + 1;
  int v801 = v797[v910];
  int v802 = v792->timer;
  int v911 = v802 + ((100 ^ (((~(((v800 ^ ((int)((unsigned int)((int)((unsigned int)(v796 + 68) >> 2)) >> 1))) | (-(v800 ^ ((int)((unsigned int)((int)((unsigned int)(v796 + 68) >> 2)) >> 1))))) >> 31)) | (~(((v801 ^ ((int)((unsigned int)((int)((unsigned int)(v796 + 68) >> 2)) >> 1))) | (-(v801 ^ ((int)((unsigned int)((int)((unsigned int)(v796 + 68) >> 2)) >> 1))))) >> 31))) & 104)) ^ (((~(((v798 ^ ((int)((unsigned int)((int)((unsigned int)(v796 + 68) >> 2)) >> 1))) | (-(v798 ^ ((int)((unsigned int)((int)((unsigned int)(v796 + 68) >> 2)) >> 1))))) >> 31)) | (~(((v799 ^ ((int)((unsigned int)((int)((unsigned int)(v796 + 68) >> 2)) >> 1))) | (-(v799 ^ ((int)((unsigned int)((int)((unsigned int)(v796 + 68) >> 2)) >> 1))))) >> 31))) & (1 ^ (100 ^ (((~(((v800 ^ ((int)((unsigned int)((int)((unsigned int)(v796 + 68) >> 2)) >> 1))) | (-(v800 ^ ((int)((unsigned int)((int)((unsigned int)(v796 + 68) >> 2)) >> 1))))) >> 31)) | (~(((v801 ^ ((int)((unsigned int)((int)((unsigned int)(v796 + 68) >> 2)) >> 1))) | (-(v801 ^ ((int)((unsigned int)((int)((unsigned int)(v796 + 68) >> 2)) >> 1))))) >> 31))) & 104)))));
  v792->timer = v911;
  int * v804 = v792->cache_vals;
  bool v912 = !(((~(((v798 ^ ((int)((unsigned int)((int)((unsigned int)(v796 + 68) >> 2)) >> 1))) | (-(v798 ^ ((int)((unsigned int)((int)((unsigned int)(v796 + 68) >> 2)) >> 1))))) >> 31)) | (~(((v799 ^ ((int)((unsigned int)((int)((unsigned int)(v796 + 68) >> 2)) >> 1))) | (-(v799 ^ ((int)((unsigned int)((int)((unsigned int)(v796 + 68) >> 2)) >> 1))))) >> 31))) == 0);
  int v897;
  if (v912) {
    int * v805 = v792->cache_age;
    int v914 = ((((int)((unsigned int)((int)((unsigned int)(v796 + 68) >> 2)) >> 1)) & 1) * 2) + ((~(((v799 ^ ((int)((unsigned int)((int)((unsigned int)(v796 + 68) >> 2)) >> 1))) | (-(v799 ^ ((int)((unsigned int)((int)((unsigned int)(v796 + 68) >> 2)) >> 1))))) >> 31)) & 1);
    int v806 = v805[v914];
    int v807 = v805[v907];
    int v915 = v807 + ((int)((unsigned int)(v807 - v806) >> 31));
    v805[v907] = v915;
    int * v809 = v792->cache_age;
    int v810 = v809[v908];
    int v917 = v810 + ((int)((unsigned int)(v810 - v806) >> 31));
    v809[v908] = v917;
    int * v812 = v792->cache_age;
    v812[v914] = 0;
    v897 = v914;
  } else {
    int * v815 = v792->cache_age;
    int v921 = (((int)((unsigned int)((int)((unsigned int)(v796 + 68) >> 2)) >> 1)) & 1) * 2;
    int v816 = v815[v921];
    int * v817 = v792->cache_tags;
    int v818 = v817[v921];
    int v819 = v815[v908];
    int v820 = v817[v908];
    bool v923 = !(((~(((v800 ^ ((int)((unsigned int)((int)((unsigned int)(v796 + 68) >> 2)) >> 1))) | (-(v800 ^ ((int)((unsigned int)((int)((unsigned int)(v796 + 68) >> 2)) >> 1))))) >> 31)) | (~(((v801 ^ ((int)((unsigned int)((int)((unsigned int)(v796 + 68) >> 2)) >> 1))) | (-(v801 ^ ((int)((unsigned int)((int)((unsigned int)(v796 + 68) >> 2)) >> 1))))) >> 31))) == 0);
    int v874;
    if (v923) {
      int * v821 = v792->cache_age;
      int v925 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v796 + 68) >> 2)) >> 1)) & 3) * 2)) + ((~(((v801 ^ ((int)((unsigned int)((int)((unsigned int)(v796 + 68) >> 2)) >> 1))) | (-(v801 ^ ((int)((unsigned int)((int)((unsigned int)(v796 + 68) >> 2)) >> 1))))) >> 31)) & 1);
      int v822 = v821[v925];
      int v823 = v821[v909];
      int v926 = v823 + ((int)((unsigned int)(v823 - v822) >> 31));
      v821[v909] = v926;
      int * v825 = v792->cache_age;
      int v826 = v825[v910];
      int v928 = v826 + ((int)((unsigned int)(v826 - v822) >> 31));
      v825[v910] = v928;
      int * v828 = v792->cache_age;
      v828[v925] = 0;
      v874 = v925;
    } else {
      int * v831 = v792->cache_age;
      int v932 = 4 + ((((int)((unsigned int)((int)((unsigned int)(v796 + 68) >> 2)) >> 1)) & 3) * 2);
      int v832 = v831[v932];
      int * v833 = v792->cache_tags;
      int v834 = v833[v932];
      int v835 = v831[v910];
      int v836 = v833[v910];
      int * v837 = v792->cache_dirty;
      int v935 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v796 + 68) >> 2)) >> 1)) & 3) * 2)) + ((((v832 + ((~(((v834 ^ -1) | (-(v834 ^ -1))) >> 31)) & 2)) - (v835 + ((~(((v836 ^ -1) | (-(v836 ^ -1))) >> 31)) & 2))) >> 31) & 1);
      int v838 = v837[v935];
      bool v936 = !(v838 == 0);
      if (v936) {
        int * v839 = v792->cache_tags;
        int v840 = v839[v935];
        int * v841 = v792->cache_vals;
        int v939 = ((4 + ((((int)((unsigned int)((int)((unsigned int)(v796 + 68) >> 2)) >> 1)) & 3) * 2)) + ((((v832 + ((~(((v834 ^ -1) | (-(v834 ^ -1))) >> 31)) & 2)) - (v835 + ((~(((v836 ^ -1) | (-(v836 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
        int v842 = v841[v939];
        int v940 = (((4 + ((((int)((unsigned int)((int)((unsigned int)(v796 + 68) >> 2)) >> 1)) & 3) * 2)) + ((((v832 + ((~(((v834 ^ -1) | (-(v834 ^ -1))) >> 31)) & 2)) - (v835 + ((~(((v836 ^ -1) | (-(v836 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
        int v843 = v841[v940];
        int * v844 = v792->mem;
        int v942 = v840 * 2;
        v844[v942] = v842;
        int * v846 = v792->mem;
        int v945 = (v840 * 2) + 1;
        v846[v945] = v843;
        ;
      } else {
        ;
      }
      int * v851 = v792->mem;
      int v950 = ((int)((unsigned int)((int)((unsigned int)(v796 + 68) >> 2)) >> 1)) * 2;
      int v852 = v851[v950];
      int v951 = (((int)((unsigned int)((int)((unsigned int)(v796 + 68) >> 2)) >> 1)) * 2) + 1;
      int v853 = v851[v951];
      int * v854 = v792->cache_vals;
      int v953 = ((4 + ((((int)((unsigned int)((int)((unsigned int)(v796 + 68) >> 2)) >> 1)) & 3) * 2)) + ((((v832 + ((~(((v834 ^ -1) | (-(v834 ^ -1))) >> 31)) & 2)) - (v835 + ((~(((v836 ^ -1) | (-(v836 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
      v854[v953] = v852;
      int * v856 = v792->cache_vals;
      int v956 = (((4 + ((((int)((unsigned int)((int)((unsigned int)(v796 + 68) >> 2)) >> 1)) & 3) * 2)) + ((((v832 + ((~(((v834 ^ -1) | (-(v834 ^ -1))) >> 31)) & 2)) - (v835 + ((~(((v836 ^ -1) | (-(v836 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
      v856[v956] = v853;
      int * v858 = v792->cache_tags;
      int v959 = (int)((unsigned int)((int)((unsigned int)(v796 + 68) >> 2)) >> 1);
      v858[v935] = v959;
      int * v860 = v792->cache_dirty;
      v860[v935] = 0;
      int * v862 = v792->cache_age;
      v862[v935] = 1;
      int * v864 = v792->cache_age;
      int v865 = v864[v935];
      int v866 = v864[v909];
      int v965 = v866 + ((int)((unsigned int)(v866 - v865) >> 31));
      v864[v909] = v965;
      int * v868 = v792->cache_age;
      int v869 = v868[v910];
      int v967 = v869 + ((int)((unsigned int)(v869 - v865) >> 31));
      v868[v910] = v967;
      int * v871 = v792->cache_age;
      v871[v935] = 0;
      v874 = v935;
    }
    int * v875 = v792->cache_vals;
    int v970 = v874 * 2;
    int v876 = v875[v970];
    int v971 = (v874 * 2) + 1;
    int v877 = v875[v971];
    int v972 = (((((int)((unsigned int)((int)((unsigned int)(v796 + 68) >> 2)) >> 1)) & 1) * 2) + ((((v816 + ((~(((v818 ^ -1) | (-(v818 ^ -1))) >> 31)) & 2)) - (v819 + ((~(((v820 ^ -1) | (-(v820 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
    v875[v972] = v876;
    int * v879 = v792->cache_vals;
    int v975 = ((((((int)((unsigned int)((int)((unsigned int)(v796 + 68) >> 2)) >> 1)) & 1) * 2) + ((((v816 + ((~(((v818 ^ -1) | (-(v818 ^ -1))) >> 31)) & 2)) - (v819 + ((~(((v820 ^ -1) | (-(v820 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
    v879[v975] = v877;
    int * v881 = v792->cache_tags;
    int v978 = ((((int)((unsigned int)((int)((unsigned int)(v796 + 68) >> 2)) >> 1)) & 1) * 2) + ((((v816 + ((~(((v818 ^ -1) | (-(v818 ^ -1))) >> 31)) & 2)) - (v819 + ((~(((v820 ^ -1) | (-(v820 ^ -1))) >> 31)) & 2))) >> 31) & 1);
    int v979 = (int)((unsigned int)((int)((unsigned int)(v796 + 68) >> 2)) >> 1);
    v881[v978] = v979;
    int * v883 = v792->cache_dirty;
    v883[v978] = 0;
    int * v885 = v792->cache_age;
    v885[v978] = 1;
    int * v887 = v792->cache_age;
    int v888 = v887[v978];
    int v889 = v887[v907];
    int v985 = v889 + ((int)((unsigned int)(v889 - v888) >> 31));
    v887[v907] = v985;
    int * v891 = v792->cache_age;
    int v892 = v891[v908];
    int v987 = v892 + ((int)((unsigned int)(v892 - v888) >> 31));
    v891[v908] = v987;
    int * v894 = v792->cache_age;
    v894[v978] = 0;
    v897 = v978;
  }
  int v990 = (v897 * 2) + (((int)((unsigned int)(v796 + 68) >> 2)) & 1);
  int v898 = v804[v990];
  int * v899 = v792->regs;
  v899[11] = v898;
  struct StateT * v901 = slot_16(v792);
  return v901;
}

struct StateT * slot_18(struct StateT * v240) {
  int v241 = v240->timer;
  int v244 = v241 + 1;
  v240->timer = v244;
  return v240;
}

struct StateT * slot_9(struct StateT * v518) {
  int v519 = v518->timer;
  int v526 = v519 + 1;
  v518->timer = v526;
  int * v521 = v518->regs;
  int v522 = v521[11];
  int v529 = v522 + 4;
  v521[11] = v529;
  struct StateT * v524 = slot_10(v518);
  return v524;
}

struct StateT * slot_11(struct StateT * v545) {
  int v546 = v545->timer;
  int v553 = v546 + 1;
  v545->timer = v553;
  int * v548 = v545->regs;
  int v549 = v548[10];
  int v556 = v549 << 29;
  v548[10] = v556;
  struct StateT * v551 = slot_12(v545);
  return v551;
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