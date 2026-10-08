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

struct StateT * slot_12(struct StateT * v526);
struct StateT * slot_14(struct StateT * v553);
struct StateT * slot_16(struct StateT * v581);
struct StateT * slot_5(struct StateT * v253);
struct StateT * slot_17(struct StateT * v597);
struct StateT * slot_20(struct StateT * v1020);
struct StateT * slot_2(struct StateT * v218);
struct StateT * slot_7(struct StateT * v267);
struct StateT * slot_3(struct StateT * v226);
struct StateT * snippet(struct StateT * v0);
struct StateT * slot_10(struct StateT * v310);
struct StateT * slot_1(struct StateT * v15);
struct StateT * slot_8(struct StateT * v280);
struct StateT * slot_19(struct StateT * v1004);
struct StateT * slot_4(struct StateT * v248);
struct StateT * slot_13(struct StateT * v540);
struct StateT * slot_15(struct StateT * v567);
struct StateT * slot_18(struct StateT * v800);
struct StateT * slot_9(struct StateT * v294);
struct StateT * slot_11(struct StateT * v513);
struct StateT * slot_0(struct StateT * v2);
struct StateT * slot_12(struct StateT * v526) {
  int v527 = v526->timer;
  int v534 = v527 + 1;
  v526->timer = v534;
  int * v529 = v526->regs;
  int v530 = v529[11];
  int v537 = v530 + 4;
  v529[11] = v537;
  struct StateT * v532 = slot_13(v526);
  return v532;
}

struct StateT * slot_14(struct StateT * v553) {
  int v554 = v553->timer;
  int v561 = v554 + 1;
  v553->timer = v561;
  int * v556 = v553->regs;
  int v557 = v556[10];
  int v564 = v557 << 29;
  v556[10] = v564;
  struct StateT * v559 = slot_15(v553);
  return v559;
}

struct StateT * slot_16(struct StateT * v581) {
  int v582 = v581->timer;
  int v590 = v582 + 1;
  v581->timer = v590;
  int * v584 = v581->regs;
  int v585 = v584[11];
  int v586 = v584[10];
  int v594 = v585 + v586;
  v584[10] = v594;
  struct StateT * v588 = slot_17(v581);
  return v588;
}

struct StateT * slot_5(struct StateT * v253) {
  int v254 = v253->timer;
  int v261 = v254 + 1;
  v253->timer = v261;
  int * v256 = v253->regs;
  int v257 = v256[10];
  int v264 = v257 << 2;
  v256[10] = v264;
  struct StateT * v259 = slot_7(v253);
  return v259;
}

struct StateT * slot_17(struct StateT * v597) {
  int v598 = v597->timer;
  int v708 = v598 + 1;
  v597->timer = v708;
  int * v600 = v597->regs;
  int v601 = v600[10];
  int * v602 = v597->cache_tags;
  int v712 = (((int)((unsigned int)((int)((unsigned int)v601 >> 2)) >> 1)) & 1) * 2;
  int v603 = v602[v712];
  int v713 = ((((int)((unsigned int)((int)((unsigned int)v601 >> 2)) >> 1)) & 1) * 2) + 1;
  int v604 = v602[v713];
  int v714 = 4 + ((((int)((unsigned int)((int)((unsigned int)v601 >> 2)) >> 1)) & 3) * 2);
  int v605 = v602[v714];
  int v715 = (4 + ((((int)((unsigned int)((int)((unsigned int)v601 >> 2)) >> 1)) & 3) * 2)) + 1;
  int v606 = v602[v715];
  int v607 = v597->timer;
  int v716 = v607 + ((100 ^ (((~(((v605 ^ ((int)((unsigned int)((int)((unsigned int)v601 >> 2)) >> 1))) | (-(v605 ^ ((int)((unsigned int)((int)((unsigned int)v601 >> 2)) >> 1))))) >> 31)) | (~(((v606 ^ ((int)((unsigned int)((int)((unsigned int)v601 >> 2)) >> 1))) | (-(v606 ^ ((int)((unsigned int)((int)((unsigned int)v601 >> 2)) >> 1))))) >> 31))) & 104)) ^ (((~(((v603 ^ ((int)((unsigned int)((int)((unsigned int)v601 >> 2)) >> 1))) | (-(v603 ^ ((int)((unsigned int)((int)((unsigned int)v601 >> 2)) >> 1))))) >> 31)) | (~(((v604 ^ ((int)((unsigned int)((int)((unsigned int)v601 >> 2)) >> 1))) | (-(v604 ^ ((int)((unsigned int)((int)((unsigned int)v601 >> 2)) >> 1))))) >> 31))) & (1 ^ (100 ^ (((~(((v605 ^ ((int)((unsigned int)((int)((unsigned int)v601 >> 2)) >> 1))) | (-(v605 ^ ((int)((unsigned int)((int)((unsigned int)v601 >> 2)) >> 1))))) >> 31)) | (~(((v606 ^ ((int)((unsigned int)((int)((unsigned int)v601 >> 2)) >> 1))) | (-(v606 ^ ((int)((unsigned int)((int)((unsigned int)v601 >> 2)) >> 1))))) >> 31))) & 104)))));
  v597->timer = v716;
  int * v609 = v597->cache_vals;
  bool v717 = !(((~(((v603 ^ ((int)((unsigned int)((int)((unsigned int)v601 >> 2)) >> 1))) | (-(v603 ^ ((int)((unsigned int)((int)((unsigned int)v601 >> 2)) >> 1))))) >> 31)) | (~(((v604 ^ ((int)((unsigned int)((int)((unsigned int)v601 >> 2)) >> 1))) | (-(v604 ^ ((int)((unsigned int)((int)((unsigned int)v601 >> 2)) >> 1))))) >> 31))) == 0);
  int v702;
  if (v717) {
    int * v610 = v597->cache_age;
    int v719 = ((((int)((unsigned int)((int)((unsigned int)v601 >> 2)) >> 1)) & 1) * 2) + ((~(((v604 ^ ((int)((unsigned int)((int)((unsigned int)v601 >> 2)) >> 1))) | (-(v604 ^ ((int)((unsigned int)((int)((unsigned int)v601 >> 2)) >> 1))))) >> 31)) & 1);
    int v611 = v610[v719];
    int v612 = v610[v712];
    int v720 = v612 + ((int)((unsigned int)(v612 - v611) >> 31));
    v610[v712] = v720;
    int * v614 = v597->cache_age;
    int v615 = v614[v713];
    int v722 = v615 + ((int)((unsigned int)(v615 - v611) >> 31));
    v614[v713] = v722;
    int * v617 = v597->cache_age;
    v617[v719] = 0;
    v702 = v719;
  } else {
    int * v620 = v597->cache_age;
    int v726 = (((int)((unsigned int)((int)((unsigned int)v601 >> 2)) >> 1)) & 1) * 2;
    int v621 = v620[v726];
    int * v622 = v597->cache_tags;
    int v623 = v622[v726];
    int v624 = v620[v713];
    int v625 = v622[v713];
    bool v728 = !(((~(((v605 ^ ((int)((unsigned int)((int)((unsigned int)v601 >> 2)) >> 1))) | (-(v605 ^ ((int)((unsigned int)((int)((unsigned int)v601 >> 2)) >> 1))))) >> 31)) | (~(((v606 ^ ((int)((unsigned int)((int)((unsigned int)v601 >> 2)) >> 1))) | (-(v606 ^ ((int)((unsigned int)((int)((unsigned int)v601 >> 2)) >> 1))))) >> 31))) == 0);
    int v679;
    if (v728) {
      int * v626 = v597->cache_age;
      int v730 = (4 + ((((int)((unsigned int)((int)((unsigned int)v601 >> 2)) >> 1)) & 3) * 2)) + ((~(((v606 ^ ((int)((unsigned int)((int)((unsigned int)v601 >> 2)) >> 1))) | (-(v606 ^ ((int)((unsigned int)((int)((unsigned int)v601 >> 2)) >> 1))))) >> 31)) & 1);
      int v627 = v626[v730];
      int v628 = v626[v714];
      int v731 = v628 + ((int)((unsigned int)(v628 - v627) >> 31));
      v626[v714] = v731;
      int * v630 = v597->cache_age;
      int v631 = v630[v715];
      int v733 = v631 + ((int)((unsigned int)(v631 - v627) >> 31));
      v630[v715] = v733;
      int * v633 = v597->cache_age;
      v633[v730] = 0;
      v679 = v730;
    } else {
      int * v636 = v597->cache_age;
      int v737 = 4 + ((((int)((unsigned int)((int)((unsigned int)v601 >> 2)) >> 1)) & 3) * 2);
      int v637 = v636[v737];
      int * v638 = v597->cache_tags;
      int v639 = v638[v737];
      int v640 = v636[v715];
      int v641 = v638[v715];
      int * v642 = v597->cache_dirty;
      int v740 = (4 + ((((int)((unsigned int)((int)((unsigned int)v601 >> 2)) >> 1)) & 3) * 2)) + ((((v637 + ((~(((v639 ^ -1) | (-(v639 ^ -1))) >> 31)) & 2)) - (v640 + ((~(((v641 ^ -1) | (-(v641 ^ -1))) >> 31)) & 2))) >> 31) & 1);
      int v643 = v642[v740];
      bool v741 = !(v643 == 0);
      if (v741) {
        int * v644 = v597->cache_tags;
        int v645 = v644[v740];
        int * v646 = v597->cache_vals;
        int v744 = ((4 + ((((int)((unsigned int)((int)((unsigned int)v601 >> 2)) >> 1)) & 3) * 2)) + ((((v637 + ((~(((v639 ^ -1) | (-(v639 ^ -1))) >> 31)) & 2)) - (v640 + ((~(((v641 ^ -1) | (-(v641 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
        int v647 = v646[v744];
        int v745 = (((4 + ((((int)((unsigned int)((int)((unsigned int)v601 >> 2)) >> 1)) & 3) * 2)) + ((((v637 + ((~(((v639 ^ -1) | (-(v639 ^ -1))) >> 31)) & 2)) - (v640 + ((~(((v641 ^ -1) | (-(v641 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
        int v648 = v646[v745];
        int * v649 = v597->mem;
        int v747 = v645 * 2;
        v649[v747] = v647;
        int * v651 = v597->mem;
        int v750 = (v645 * 2) + 1;
        v651[v750] = v648;
        ;
      } else {
        ;
      }
      int * v656 = v597->mem;
      int v755 = ((int)((unsigned int)((int)((unsigned int)v601 >> 2)) >> 1)) * 2;
      int v657 = v656[v755];
      int v756 = (((int)((unsigned int)((int)((unsigned int)v601 >> 2)) >> 1)) * 2) + 1;
      int v658 = v656[v756];
      int * v659 = v597->cache_vals;
      int v758 = ((4 + ((((int)((unsigned int)((int)((unsigned int)v601 >> 2)) >> 1)) & 3) * 2)) + ((((v637 + ((~(((v639 ^ -1) | (-(v639 ^ -1))) >> 31)) & 2)) - (v640 + ((~(((v641 ^ -1) | (-(v641 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
      v659[v758] = v657;
      int * v661 = v597->cache_vals;
      int v761 = (((4 + ((((int)((unsigned int)((int)((unsigned int)v601 >> 2)) >> 1)) & 3) * 2)) + ((((v637 + ((~(((v639 ^ -1) | (-(v639 ^ -1))) >> 31)) & 2)) - (v640 + ((~(((v641 ^ -1) | (-(v641 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
      v661[v761] = v658;
      int * v663 = v597->cache_tags;
      int v764 = (int)((unsigned int)((int)((unsigned int)v601 >> 2)) >> 1);
      v663[v740] = v764;
      int * v665 = v597->cache_dirty;
      v665[v740] = 0;
      int * v667 = v597->cache_age;
      v667[v740] = 1;
      int * v669 = v597->cache_age;
      int v670 = v669[v740];
      int v671 = v669[v714];
      int v770 = v671 + ((int)((unsigned int)(v671 - v670) >> 31));
      v669[v714] = v770;
      int * v673 = v597->cache_age;
      int v674 = v673[v715];
      int v772 = v674 + ((int)((unsigned int)(v674 - v670) >> 31));
      v673[v715] = v772;
      int * v676 = v597->cache_age;
      v676[v740] = 0;
      v679 = v740;
    }
    int * v680 = v597->cache_vals;
    int v775 = v679 * 2;
    int v681 = v680[v775];
    int v776 = (v679 * 2) + 1;
    int v682 = v680[v776];
    int v777 = (((((int)((unsigned int)((int)((unsigned int)v601 >> 2)) >> 1)) & 1) * 2) + ((((v621 + ((~(((v623 ^ -1) | (-(v623 ^ -1))) >> 31)) & 2)) - (v624 + ((~(((v625 ^ -1) | (-(v625 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
    v680[v777] = v681;
    int * v684 = v597->cache_vals;
    int v780 = ((((((int)((unsigned int)((int)((unsigned int)v601 >> 2)) >> 1)) & 1) * 2) + ((((v621 + ((~(((v623 ^ -1) | (-(v623 ^ -1))) >> 31)) & 2)) - (v624 + ((~(((v625 ^ -1) | (-(v625 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
    v684[v780] = v682;
    int * v686 = v597->cache_tags;
    int v783 = ((((int)((unsigned int)((int)((unsigned int)v601 >> 2)) >> 1)) & 1) * 2) + ((((v621 + ((~(((v623 ^ -1) | (-(v623 ^ -1))) >> 31)) & 2)) - (v624 + ((~(((v625 ^ -1) | (-(v625 ^ -1))) >> 31)) & 2))) >> 31) & 1);
    int v784 = (int)((unsigned int)((int)((unsigned int)v601 >> 2)) >> 1);
    v686[v783] = v784;
    int * v688 = v597->cache_dirty;
    v688[v783] = 0;
    int * v690 = v597->cache_age;
    v690[v783] = 1;
    int * v692 = v597->cache_age;
    int v693 = v692[v783];
    int v694 = v692[v712];
    int v790 = v694 + ((int)((unsigned int)(v694 - v693) >> 31));
    v692[v712] = v790;
    int * v696 = v597->cache_age;
    int v697 = v696[v713];
    int v792 = v697 + ((int)((unsigned int)(v697 - v693) >> 31));
    v696[v713] = v792;
    int * v699 = v597->cache_age;
    v699[v783] = 0;
    v702 = v783;
  }
  int v795 = (v702 * 2) + (((int)((unsigned int)v601 >> 2)) & 1);
  int v703 = v609[v795];
  int * v704 = v597->regs;
  v704[10] = v703;
  struct StateT * v706 = slot_18(v597);
  return v706;
}

struct StateT * slot_20(struct StateT * v1020) {
  int v1021 = v1020->timer;
  int v1191 = v1021 + 1;
  v1020->timer = v1191;
  int * v1023 = v1020->regs;
  int v1024 = v1023[12];
  int v1025 = v1023[10];
  int * v1026 = v1020->cache_tags;
  int v1196 = (((int)((unsigned int)((int)((unsigned int)(v1024 + 68) >> 2)) >> 1)) & 1) * 2;
  int v1027 = v1026[v1196];
  int v1197 = ((((int)((unsigned int)((int)((unsigned int)(v1024 + 68) >> 2)) >> 1)) & 1) * 2) + 1;
  int v1028 = v1026[v1197];
  int v1198 = 4 + ((((int)((unsigned int)((int)((unsigned int)(v1024 + 68) >> 2)) >> 1)) & 3) * 2);
  int v1029 = v1026[v1198];
  int v1199 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v1024 + 68) >> 2)) >> 1)) & 3) * 2)) + 1;
  int v1030 = v1026[v1199];
  int v1031 = v1020->timer;
  int v1200 = v1031 + ((100 ^ (((~(((v1029 ^ ((int)((unsigned int)((int)((unsigned int)(v1024 + 68) >> 2)) >> 1))) | (-(v1029 ^ ((int)((unsigned int)((int)((unsigned int)(v1024 + 68) >> 2)) >> 1))))) >> 31)) | (~(((v1030 ^ ((int)((unsigned int)((int)((unsigned int)(v1024 + 68) >> 2)) >> 1))) | (-(v1030 ^ ((int)((unsigned int)((int)((unsigned int)(v1024 + 68) >> 2)) >> 1))))) >> 31))) & 104)) ^ (((~(((v1027 ^ ((int)((unsigned int)((int)((unsigned int)(v1024 + 68) >> 2)) >> 1))) | (-(v1027 ^ ((int)((unsigned int)((int)((unsigned int)(v1024 + 68) >> 2)) >> 1))))) >> 31)) | (~(((v1028 ^ ((int)((unsigned int)((int)((unsigned int)(v1024 + 68) >> 2)) >> 1))) | (-(v1028 ^ ((int)((unsigned int)((int)((unsigned int)(v1024 + 68) >> 2)) >> 1))))) >> 31))) & (1 ^ (100 ^ (((~(((v1029 ^ ((int)((unsigned int)((int)((unsigned int)(v1024 + 68) >> 2)) >> 1))) | (-(v1029 ^ ((int)((unsigned int)((int)((unsigned int)(v1024 + 68) >> 2)) >> 1))))) >> 31)) | (~(((v1030 ^ ((int)((unsigned int)((int)((unsigned int)(v1024 + 68) >> 2)) >> 1))) | (-(v1030 ^ ((int)((unsigned int)((int)((unsigned int)(v1024 + 68) >> 2)) >> 1))))) >> 31))) & 104)))));
  v1020->timer = v1200;
  bool v1201 = !(((~(((v1027 ^ ((int)((unsigned int)((int)((unsigned int)(v1024 + 68) >> 2)) >> 1))) | (-(v1027 ^ ((int)((unsigned int)((int)((unsigned int)(v1024 + 68) >> 2)) >> 1))))) >> 31)) | (~(((v1028 ^ ((int)((unsigned int)((int)((unsigned int)(v1024 + 68) >> 2)) >> 1))) | (-(v1028 ^ ((int)((unsigned int)((int)((unsigned int)(v1024 + 68) >> 2)) >> 1))))) >> 31))) == 0);
  int v1125;
  if (v1201) {
    int * v1033 = v1020->cache_age;
    int v1203 = ((((int)((unsigned int)((int)((unsigned int)(v1024 + 68) >> 2)) >> 1)) & 1) * 2) + ((~(((v1028 ^ ((int)((unsigned int)((int)((unsigned int)(v1024 + 68) >> 2)) >> 1))) | (-(v1028 ^ ((int)((unsigned int)((int)((unsigned int)(v1024 + 68) >> 2)) >> 1))))) >> 31)) & 1);
    int v1034 = v1033[v1203];
    int v1035 = v1033[v1196];
    int v1204 = v1035 + ((int)((unsigned int)(v1035 - v1034) >> 31));
    v1033[v1196] = v1204;
    int * v1037 = v1020->cache_age;
    int v1038 = v1037[v1197];
    int v1206 = v1038 + ((int)((unsigned int)(v1038 - v1034) >> 31));
    v1037[v1197] = v1206;
    int * v1040 = v1020->cache_age;
    v1040[v1203] = 0;
    v1125 = v1203;
  } else {
    int * v1043 = v1020->cache_age;
    int v1210 = (((int)((unsigned int)((int)((unsigned int)(v1024 + 68) >> 2)) >> 1)) & 1) * 2;
    int v1044 = v1043[v1210];
    int * v1045 = v1020->cache_tags;
    int v1046 = v1045[v1210];
    int v1047 = v1043[v1197];
    int v1048 = v1045[v1197];
    bool v1212 = !(((~(((v1029 ^ ((int)((unsigned int)((int)((unsigned int)(v1024 + 68) >> 2)) >> 1))) | (-(v1029 ^ ((int)((unsigned int)((int)((unsigned int)(v1024 + 68) >> 2)) >> 1))))) >> 31)) | (~(((v1030 ^ ((int)((unsigned int)((int)((unsigned int)(v1024 + 68) >> 2)) >> 1))) | (-(v1030 ^ ((int)((unsigned int)((int)((unsigned int)(v1024 + 68) >> 2)) >> 1))))) >> 31))) == 0);
    int v1102;
    if (v1212) {
      int * v1049 = v1020->cache_age;
      int v1214 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v1024 + 68) >> 2)) >> 1)) & 3) * 2)) + ((~(((v1030 ^ ((int)((unsigned int)((int)((unsigned int)(v1024 + 68) >> 2)) >> 1))) | (-(v1030 ^ ((int)((unsigned int)((int)((unsigned int)(v1024 + 68) >> 2)) >> 1))))) >> 31)) & 1);
      int v1050 = v1049[v1214];
      int v1051 = v1049[v1198];
      int v1215 = v1051 + ((int)((unsigned int)(v1051 - v1050) >> 31));
      v1049[v1198] = v1215;
      int * v1053 = v1020->cache_age;
      int v1054 = v1053[v1199];
      int v1217 = v1054 + ((int)((unsigned int)(v1054 - v1050) >> 31));
      v1053[v1199] = v1217;
      int * v1056 = v1020->cache_age;
      v1056[v1214] = 0;
      v1102 = v1214;
    } else {
      int * v1059 = v1020->cache_age;
      int v1221 = 4 + ((((int)((unsigned int)((int)((unsigned int)(v1024 + 68) >> 2)) >> 1)) & 3) * 2);
      int v1060 = v1059[v1221];
      int * v1061 = v1020->cache_tags;
      int v1062 = v1061[v1221];
      int v1063 = v1059[v1199];
      int v1064 = v1061[v1199];
      int * v1065 = v1020->cache_dirty;
      int v1224 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v1024 + 68) >> 2)) >> 1)) & 3) * 2)) + ((((v1060 + ((~(((v1062 ^ -1) | (-(v1062 ^ -1))) >> 31)) & 2)) - (v1063 + ((~(((v1064 ^ -1) | (-(v1064 ^ -1))) >> 31)) & 2))) >> 31) & 1);
      int v1066 = v1065[v1224];
      bool v1225 = !(v1066 == 0);
      if (v1225) {
        int * v1067 = v1020->cache_tags;
        int v1068 = v1067[v1224];
        int * v1069 = v1020->cache_vals;
        int v1228 = ((4 + ((((int)((unsigned int)((int)((unsigned int)(v1024 + 68) >> 2)) >> 1)) & 3) * 2)) + ((((v1060 + ((~(((v1062 ^ -1) | (-(v1062 ^ -1))) >> 31)) & 2)) - (v1063 + ((~(((v1064 ^ -1) | (-(v1064 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
        int v1070 = v1069[v1228];
        int v1229 = (((4 + ((((int)((unsigned int)((int)((unsigned int)(v1024 + 68) >> 2)) >> 1)) & 3) * 2)) + ((((v1060 + ((~(((v1062 ^ -1) | (-(v1062 ^ -1))) >> 31)) & 2)) - (v1063 + ((~(((v1064 ^ -1) | (-(v1064 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
        int v1071 = v1069[v1229];
        int * v1072 = v1020->mem;
        int v1231 = v1068 * 2;
        v1072[v1231] = v1070;
        int * v1074 = v1020->mem;
        int v1234 = (v1068 * 2) + 1;
        v1074[v1234] = v1071;
        ;
      } else {
        ;
      }
      int * v1079 = v1020->mem;
      int v1239 = ((int)((unsigned int)((int)((unsigned int)(v1024 + 68) >> 2)) >> 1)) * 2;
      int v1080 = v1079[v1239];
      int v1240 = (((int)((unsigned int)((int)((unsigned int)(v1024 + 68) >> 2)) >> 1)) * 2) + 1;
      int v1081 = v1079[v1240];
      int * v1082 = v1020->cache_vals;
      int v1242 = ((4 + ((((int)((unsigned int)((int)((unsigned int)(v1024 + 68) >> 2)) >> 1)) & 3) * 2)) + ((((v1060 + ((~(((v1062 ^ -1) | (-(v1062 ^ -1))) >> 31)) & 2)) - (v1063 + ((~(((v1064 ^ -1) | (-(v1064 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
      v1082[v1242] = v1080;
      int * v1084 = v1020->cache_vals;
      int v1245 = (((4 + ((((int)((unsigned int)((int)((unsigned int)(v1024 + 68) >> 2)) >> 1)) & 3) * 2)) + ((((v1060 + ((~(((v1062 ^ -1) | (-(v1062 ^ -1))) >> 31)) & 2)) - (v1063 + ((~(((v1064 ^ -1) | (-(v1064 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
      v1084[v1245] = v1081;
      int * v1086 = v1020->cache_tags;
      int v1248 = (int)((unsigned int)((int)((unsigned int)(v1024 + 68) >> 2)) >> 1);
      v1086[v1224] = v1248;
      int * v1088 = v1020->cache_dirty;
      v1088[v1224] = 0;
      int * v1090 = v1020->cache_age;
      v1090[v1224] = 1;
      int * v1092 = v1020->cache_age;
      int v1093 = v1092[v1224];
      int v1094 = v1092[v1198];
      int v1254 = v1094 + ((int)((unsigned int)(v1094 - v1093) >> 31));
      v1092[v1198] = v1254;
      int * v1096 = v1020->cache_age;
      int v1097 = v1096[v1199];
      int v1256 = v1097 + ((int)((unsigned int)(v1097 - v1093) >> 31));
      v1096[v1199] = v1256;
      int * v1099 = v1020->cache_age;
      v1099[v1224] = 0;
      v1102 = v1224;
    }
    int * v1103 = v1020->cache_vals;
    int v1259 = v1102 * 2;
    int v1104 = v1103[v1259];
    int v1260 = (v1102 * 2) + 1;
    int v1105 = v1103[v1260];
    int v1261 = (((((int)((unsigned int)((int)((unsigned int)(v1024 + 68) >> 2)) >> 1)) & 1) * 2) + ((((v1044 + ((~(((v1046 ^ -1) | (-(v1046 ^ -1))) >> 31)) & 2)) - (v1047 + ((~(((v1048 ^ -1) | (-(v1048 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
    v1103[v1261] = v1104;
    int * v1107 = v1020->cache_vals;
    int v1264 = ((((((int)((unsigned int)((int)((unsigned int)(v1024 + 68) >> 2)) >> 1)) & 1) * 2) + ((((v1044 + ((~(((v1046 ^ -1) | (-(v1046 ^ -1))) >> 31)) & 2)) - (v1047 + ((~(((v1048 ^ -1) | (-(v1048 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
    v1107[v1264] = v1105;
    int * v1109 = v1020->cache_tags;
    int v1267 = ((((int)((unsigned int)((int)((unsigned int)(v1024 + 68) >> 2)) >> 1)) & 1) * 2) + ((((v1044 + ((~(((v1046 ^ -1) | (-(v1046 ^ -1))) >> 31)) & 2)) - (v1047 + ((~(((v1048 ^ -1) | (-(v1048 ^ -1))) >> 31)) & 2))) >> 31) & 1);
    int v1268 = (int)((unsigned int)((int)((unsigned int)(v1024 + 68) >> 2)) >> 1);
    v1109[v1267] = v1268;
    int * v1111 = v1020->cache_dirty;
    v1111[v1267] = 0;
    int * v1113 = v1020->cache_age;
    v1113[v1267] = 1;
    int * v1115 = v1020->cache_age;
    int v1116 = v1115[v1267];
    int v1117 = v1115[v1196];
    int v1274 = v1117 + ((int)((unsigned int)(v1117 - v1116) >> 31));
    v1115[v1196] = v1274;
    int * v1119 = v1020->cache_age;
    int v1120 = v1119[v1197];
    int v1276 = v1120 + ((int)((unsigned int)(v1120 - v1116) >> 31));
    v1119[v1197] = v1276;
    int * v1122 = v1020->cache_age;
    v1122[v1267] = 0;
    v1125 = v1267;
  }
  int * v1126 = v1020->cache_vals;
  int v1279 = (v1125 * 2) + (((int)((unsigned int)(v1024 + 68) >> 2)) & 1);
  v1126[v1279] = v1025;
  int * v1128 = v1020->cache_tags;
  int v1129 = v1128[v1198];
  int v1130 = v1128[v1199];
  bool v1282 = !(((~(((v1129 ^ ((int)((unsigned int)((int)((unsigned int)(v1024 + 68) >> 2)) >> 1))) | (-(v1129 ^ ((int)((unsigned int)((int)((unsigned int)(v1024 + 68) >> 2)) >> 1))))) >> 31)) | (~(((v1130 ^ ((int)((unsigned int)((int)((unsigned int)(v1024 + 68) >> 2)) >> 1))) | (-(v1130 ^ ((int)((unsigned int)((int)((unsigned int)(v1024 + 68) >> 2)) >> 1))))) >> 31))) == 0);
  int v1184;
  if (v1282) {
    int * v1131 = v1020->cache_age;
    int v1284 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v1024 + 68) >> 2)) >> 1)) & 3) * 2)) + ((~(((v1130 ^ ((int)((unsigned int)((int)((unsigned int)(v1024 + 68) >> 2)) >> 1))) | (-(v1130 ^ ((int)((unsigned int)((int)((unsigned int)(v1024 + 68) >> 2)) >> 1))))) >> 31)) & 1);
    int v1132 = v1131[v1284];
    int v1133 = v1131[v1198];
    int v1285 = v1133 + ((int)((unsigned int)(v1133 - v1132) >> 31));
    v1131[v1198] = v1285;
    int * v1135 = v1020->cache_age;
    int v1136 = v1135[v1199];
    int v1287 = v1136 + ((int)((unsigned int)(v1136 - v1132) >> 31));
    v1135[v1199] = v1287;
    int * v1138 = v1020->cache_age;
    v1138[v1284] = 0;
    v1184 = v1284;
  } else {
    int * v1141 = v1020->cache_age;
    int v1291 = 4 + ((((int)((unsigned int)((int)((unsigned int)(v1024 + 68) >> 2)) >> 1)) & 3) * 2);
    int v1142 = v1141[v1291];
    int * v1143 = v1020->cache_tags;
    int v1144 = v1143[v1291];
    int v1145 = v1141[v1199];
    int v1146 = v1143[v1199];
    int * v1147 = v1020->cache_dirty;
    int v1294 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v1024 + 68) >> 2)) >> 1)) & 3) * 2)) + ((((v1142 + ((~(((v1144 ^ -1) | (-(v1144 ^ -1))) >> 31)) & 2)) - (v1145 + ((~(((v1146 ^ -1) | (-(v1146 ^ -1))) >> 31)) & 2))) >> 31) & 1);
    int v1148 = v1147[v1294];
    bool v1295 = !(v1148 == 0);
    if (v1295) {
      int * v1149 = v1020->cache_tags;
      int v1150 = v1149[v1294];
      int * v1151 = v1020->cache_vals;
      int v1298 = ((4 + ((((int)((unsigned int)((int)((unsigned int)(v1024 + 68) >> 2)) >> 1)) & 3) * 2)) + ((((v1142 + ((~(((v1144 ^ -1) | (-(v1144 ^ -1))) >> 31)) & 2)) - (v1145 + ((~(((v1146 ^ -1) | (-(v1146 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
      int v1152 = v1151[v1298];
      int v1299 = (((4 + ((((int)((unsigned int)((int)((unsigned int)(v1024 + 68) >> 2)) >> 1)) & 3) * 2)) + ((((v1142 + ((~(((v1144 ^ -1) | (-(v1144 ^ -1))) >> 31)) & 2)) - (v1145 + ((~(((v1146 ^ -1) | (-(v1146 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
      int v1153 = v1151[v1299];
      int * v1154 = v1020->mem;
      int v1301 = v1150 * 2;
      v1154[v1301] = v1152;
      int * v1156 = v1020->mem;
      int v1304 = (v1150 * 2) + 1;
      v1156[v1304] = v1153;
      ;
    } else {
      ;
    }
    int * v1161 = v1020->mem;
    int v1309 = ((int)((unsigned int)((int)((unsigned int)(v1024 + 68) >> 2)) >> 1)) * 2;
    int v1162 = v1161[v1309];
    int v1310 = (((int)((unsigned int)((int)((unsigned int)(v1024 + 68) >> 2)) >> 1)) * 2) + 1;
    int v1163 = v1161[v1310];
    int * v1164 = v1020->cache_vals;
    int v1312 = ((4 + ((((int)((unsigned int)((int)((unsigned int)(v1024 + 68) >> 2)) >> 1)) & 3) * 2)) + ((((v1142 + ((~(((v1144 ^ -1) | (-(v1144 ^ -1))) >> 31)) & 2)) - (v1145 + ((~(((v1146 ^ -1) | (-(v1146 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
    v1164[v1312] = v1162;
    int * v1166 = v1020->cache_vals;
    int v1315 = (((4 + ((((int)((unsigned int)((int)((unsigned int)(v1024 + 68) >> 2)) >> 1)) & 3) * 2)) + ((((v1142 + ((~(((v1144 ^ -1) | (-(v1144 ^ -1))) >> 31)) & 2)) - (v1145 + ((~(((v1146 ^ -1) | (-(v1146 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
    v1166[v1315] = v1163;
    int * v1168 = v1020->cache_tags;
    int v1318 = (int)((unsigned int)((int)((unsigned int)(v1024 + 68) >> 2)) >> 1);
    v1168[v1294] = v1318;
    int * v1170 = v1020->cache_dirty;
    v1170[v1294] = 0;
    int * v1172 = v1020->cache_age;
    v1172[v1294] = 1;
    int * v1174 = v1020->cache_age;
    int v1175 = v1174[v1294];
    int v1176 = v1174[v1198];
    int v1324 = v1176 + ((int)((unsigned int)(v1176 - v1175) >> 31));
    v1174[v1198] = v1324;
    int * v1178 = v1020->cache_age;
    int v1179 = v1178[v1199];
    int v1326 = v1179 + ((int)((unsigned int)(v1179 - v1175) >> 31));
    v1178[v1199] = v1326;
    int * v1181 = v1020->cache_age;
    v1181[v1294] = 0;
    v1184 = v1294;
  }
  int * v1185 = v1020->cache_vals;
  int v1329 = (v1184 * 2) + (((int)((unsigned int)(v1024 + 68) >> 2)) & 1);
  v1185[v1329] = v1025;
  int * v1187 = v1020->cache_dirty;
  v1187[v1184] = 1;
  struct StateT * v1189 = slot_4(v1020);
  return v1189;
}

struct StateT * slot_2(struct StateT * v218) {
  int v219 = v218->timer;
  int v223 = v219 + 1;
  v218->timer = v223;
  struct StateT * v221 = slot_3(v218);
  return v221;
}

struct StateT * slot_7(struct StateT * v267) {
  int v268 = v267->timer;
  int v274 = v268 + 1;
  v267->timer = v274;
  int * v270 = v267->regs;
  v270[11] = 0;
  struct StateT * v272 = slot_8(v267);
  return v272;
}

struct StateT * slot_3(struct StateT * v226) {
  int * v227 = v226->regs;
  int v228 = v227[10];
  int v229 = v227[11];
  bool v241 = (v228 ^ -2147483648) >= (v229 ^ -2147483648);
  struct StateT * v236;
  if (v241) {
    int v230 = v226->timer;
    int v242 = v230 + 15;
    v226->timer = v242;
    struct StateT * v232 = slot_4(v226);
    v236 = v232;
  } else {
    struct StateT * v234 = slot_5(v226);
    v236 = v234;
  }
  return v236;
}

struct StateT * snippet(struct StateT * v0) {
  struct StateT * v1 = slot_0(v0);
  return v1;
}

struct StateT * slot_10(struct StateT * v310) {
  int v311 = v310->timer;
  int v421 = v311 + 1;
  v310->timer = v421;
  int * v313 = v310->regs;
  int v314 = v313[10];
  int * v315 = v310->cache_tags;
  int v425 = (((int)((unsigned int)((int)((unsigned int)v314 >> 2)) >> 1)) & 1) * 2;
  int v316 = v315[v425];
  int v426 = ((((int)((unsigned int)((int)((unsigned int)v314 >> 2)) >> 1)) & 1) * 2) + 1;
  int v317 = v315[v426];
  int v427 = 4 + ((((int)((unsigned int)((int)((unsigned int)v314 >> 2)) >> 1)) & 3) * 2);
  int v318 = v315[v427];
  int v428 = (4 + ((((int)((unsigned int)((int)((unsigned int)v314 >> 2)) >> 1)) & 3) * 2)) + 1;
  int v319 = v315[v428];
  int v320 = v310->timer;
  int v429 = v320 + ((100 ^ (((~(((v318 ^ ((int)((unsigned int)((int)((unsigned int)v314 >> 2)) >> 1))) | (-(v318 ^ ((int)((unsigned int)((int)((unsigned int)v314 >> 2)) >> 1))))) >> 31)) | (~(((v319 ^ ((int)((unsigned int)((int)((unsigned int)v314 >> 2)) >> 1))) | (-(v319 ^ ((int)((unsigned int)((int)((unsigned int)v314 >> 2)) >> 1))))) >> 31))) & 104)) ^ (((~(((v316 ^ ((int)((unsigned int)((int)((unsigned int)v314 >> 2)) >> 1))) | (-(v316 ^ ((int)((unsigned int)((int)((unsigned int)v314 >> 2)) >> 1))))) >> 31)) | (~(((v317 ^ ((int)((unsigned int)((int)((unsigned int)v314 >> 2)) >> 1))) | (-(v317 ^ ((int)((unsigned int)((int)((unsigned int)v314 >> 2)) >> 1))))) >> 31))) & (1 ^ (100 ^ (((~(((v318 ^ ((int)((unsigned int)((int)((unsigned int)v314 >> 2)) >> 1))) | (-(v318 ^ ((int)((unsigned int)((int)((unsigned int)v314 >> 2)) >> 1))))) >> 31)) | (~(((v319 ^ ((int)((unsigned int)((int)((unsigned int)v314 >> 2)) >> 1))) | (-(v319 ^ ((int)((unsigned int)((int)((unsigned int)v314 >> 2)) >> 1))))) >> 31))) & 104)))));
  v310->timer = v429;
  int * v322 = v310->cache_vals;
  bool v430 = !(((~(((v316 ^ ((int)((unsigned int)((int)((unsigned int)v314 >> 2)) >> 1))) | (-(v316 ^ ((int)((unsigned int)((int)((unsigned int)v314 >> 2)) >> 1))))) >> 31)) | (~(((v317 ^ ((int)((unsigned int)((int)((unsigned int)v314 >> 2)) >> 1))) | (-(v317 ^ ((int)((unsigned int)((int)((unsigned int)v314 >> 2)) >> 1))))) >> 31))) == 0);
  int v415;
  if (v430) {
    int * v323 = v310->cache_age;
    int v432 = ((((int)((unsigned int)((int)((unsigned int)v314 >> 2)) >> 1)) & 1) * 2) + ((~(((v317 ^ ((int)((unsigned int)((int)((unsigned int)v314 >> 2)) >> 1))) | (-(v317 ^ ((int)((unsigned int)((int)((unsigned int)v314 >> 2)) >> 1))))) >> 31)) & 1);
    int v324 = v323[v432];
    int v325 = v323[v425];
    int v433 = v325 + ((int)((unsigned int)(v325 - v324) >> 31));
    v323[v425] = v433;
    int * v327 = v310->cache_age;
    int v328 = v327[v426];
    int v435 = v328 + ((int)((unsigned int)(v328 - v324) >> 31));
    v327[v426] = v435;
    int * v330 = v310->cache_age;
    v330[v432] = 0;
    v415 = v432;
  } else {
    int * v333 = v310->cache_age;
    int v439 = (((int)((unsigned int)((int)((unsigned int)v314 >> 2)) >> 1)) & 1) * 2;
    int v334 = v333[v439];
    int * v335 = v310->cache_tags;
    int v336 = v335[v439];
    int v337 = v333[v426];
    int v338 = v335[v426];
    bool v441 = !(((~(((v318 ^ ((int)((unsigned int)((int)((unsigned int)v314 >> 2)) >> 1))) | (-(v318 ^ ((int)((unsigned int)((int)((unsigned int)v314 >> 2)) >> 1))))) >> 31)) | (~(((v319 ^ ((int)((unsigned int)((int)((unsigned int)v314 >> 2)) >> 1))) | (-(v319 ^ ((int)((unsigned int)((int)((unsigned int)v314 >> 2)) >> 1))))) >> 31))) == 0);
    int v392;
    if (v441) {
      int * v339 = v310->cache_age;
      int v443 = (4 + ((((int)((unsigned int)((int)((unsigned int)v314 >> 2)) >> 1)) & 3) * 2)) + ((~(((v319 ^ ((int)((unsigned int)((int)((unsigned int)v314 >> 2)) >> 1))) | (-(v319 ^ ((int)((unsigned int)((int)((unsigned int)v314 >> 2)) >> 1))))) >> 31)) & 1);
      int v340 = v339[v443];
      int v341 = v339[v427];
      int v444 = v341 + ((int)((unsigned int)(v341 - v340) >> 31));
      v339[v427] = v444;
      int * v343 = v310->cache_age;
      int v344 = v343[v428];
      int v446 = v344 + ((int)((unsigned int)(v344 - v340) >> 31));
      v343[v428] = v446;
      int * v346 = v310->cache_age;
      v346[v443] = 0;
      v392 = v443;
    } else {
      int * v349 = v310->cache_age;
      int v450 = 4 + ((((int)((unsigned int)((int)((unsigned int)v314 >> 2)) >> 1)) & 3) * 2);
      int v350 = v349[v450];
      int * v351 = v310->cache_tags;
      int v352 = v351[v450];
      int v353 = v349[v428];
      int v354 = v351[v428];
      int * v355 = v310->cache_dirty;
      int v453 = (4 + ((((int)((unsigned int)((int)((unsigned int)v314 >> 2)) >> 1)) & 3) * 2)) + ((((v350 + ((~(((v352 ^ -1) | (-(v352 ^ -1))) >> 31)) & 2)) - (v353 + ((~(((v354 ^ -1) | (-(v354 ^ -1))) >> 31)) & 2))) >> 31) & 1);
      int v356 = v355[v453];
      bool v454 = !(v356 == 0);
      if (v454) {
        int * v357 = v310->cache_tags;
        int v358 = v357[v453];
        int * v359 = v310->cache_vals;
        int v457 = ((4 + ((((int)((unsigned int)((int)((unsigned int)v314 >> 2)) >> 1)) & 3) * 2)) + ((((v350 + ((~(((v352 ^ -1) | (-(v352 ^ -1))) >> 31)) & 2)) - (v353 + ((~(((v354 ^ -1) | (-(v354 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
        int v360 = v359[v457];
        int v458 = (((4 + ((((int)((unsigned int)((int)((unsigned int)v314 >> 2)) >> 1)) & 3) * 2)) + ((((v350 + ((~(((v352 ^ -1) | (-(v352 ^ -1))) >> 31)) & 2)) - (v353 + ((~(((v354 ^ -1) | (-(v354 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
        int v361 = v359[v458];
        int * v362 = v310->mem;
        int v460 = v358 * 2;
        v362[v460] = v360;
        int * v364 = v310->mem;
        int v463 = (v358 * 2) + 1;
        v364[v463] = v361;
        ;
      } else {
        ;
      }
      int * v369 = v310->mem;
      int v468 = ((int)((unsigned int)((int)((unsigned int)v314 >> 2)) >> 1)) * 2;
      int v370 = v369[v468];
      int v469 = (((int)((unsigned int)((int)((unsigned int)v314 >> 2)) >> 1)) * 2) + 1;
      int v371 = v369[v469];
      int * v372 = v310->cache_vals;
      int v471 = ((4 + ((((int)((unsigned int)((int)((unsigned int)v314 >> 2)) >> 1)) & 3) * 2)) + ((((v350 + ((~(((v352 ^ -1) | (-(v352 ^ -1))) >> 31)) & 2)) - (v353 + ((~(((v354 ^ -1) | (-(v354 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
      v372[v471] = v370;
      int * v374 = v310->cache_vals;
      int v474 = (((4 + ((((int)((unsigned int)((int)((unsigned int)v314 >> 2)) >> 1)) & 3) * 2)) + ((((v350 + ((~(((v352 ^ -1) | (-(v352 ^ -1))) >> 31)) & 2)) - (v353 + ((~(((v354 ^ -1) | (-(v354 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
      v374[v474] = v371;
      int * v376 = v310->cache_tags;
      int v477 = (int)((unsigned int)((int)((unsigned int)v314 >> 2)) >> 1);
      v376[v453] = v477;
      int * v378 = v310->cache_dirty;
      v378[v453] = 0;
      int * v380 = v310->cache_age;
      v380[v453] = 1;
      int * v382 = v310->cache_age;
      int v383 = v382[v453];
      int v384 = v382[v427];
      int v483 = v384 + ((int)((unsigned int)(v384 - v383) >> 31));
      v382[v427] = v483;
      int * v386 = v310->cache_age;
      int v387 = v386[v428];
      int v485 = v387 + ((int)((unsigned int)(v387 - v383) >> 31));
      v386[v428] = v485;
      int * v389 = v310->cache_age;
      v389[v453] = 0;
      v392 = v453;
    }
    int * v393 = v310->cache_vals;
    int v488 = v392 * 2;
    int v394 = v393[v488];
    int v489 = (v392 * 2) + 1;
    int v395 = v393[v489];
    int v490 = (((((int)((unsigned int)((int)((unsigned int)v314 >> 2)) >> 1)) & 1) * 2) + ((((v334 + ((~(((v336 ^ -1) | (-(v336 ^ -1))) >> 31)) & 2)) - (v337 + ((~(((v338 ^ -1) | (-(v338 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
    v393[v490] = v394;
    int * v397 = v310->cache_vals;
    int v493 = ((((((int)((unsigned int)((int)((unsigned int)v314 >> 2)) >> 1)) & 1) * 2) + ((((v334 + ((~(((v336 ^ -1) | (-(v336 ^ -1))) >> 31)) & 2)) - (v337 + ((~(((v338 ^ -1) | (-(v338 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
    v397[v493] = v395;
    int * v399 = v310->cache_tags;
    int v496 = ((((int)((unsigned int)((int)((unsigned int)v314 >> 2)) >> 1)) & 1) * 2) + ((((v334 + ((~(((v336 ^ -1) | (-(v336 ^ -1))) >> 31)) & 2)) - (v337 + ((~(((v338 ^ -1) | (-(v338 ^ -1))) >> 31)) & 2))) >> 31) & 1);
    int v497 = (int)((unsigned int)((int)((unsigned int)v314 >> 2)) >> 1);
    v399[v496] = v497;
    int * v401 = v310->cache_dirty;
    v401[v496] = 0;
    int * v403 = v310->cache_age;
    v403[v496] = 1;
    int * v405 = v310->cache_age;
    int v406 = v405[v496];
    int v407 = v405[v425];
    int v503 = v407 + ((int)((unsigned int)(v407 - v406) >> 31));
    v405[v425] = v503;
    int * v409 = v310->cache_age;
    int v410 = v409[v426];
    int v505 = v410 + ((int)((unsigned int)(v410 - v406) >> 31));
    v409[v426] = v505;
    int * v412 = v310->cache_age;
    v412[v496] = 0;
    v415 = v496;
  }
  int v508 = (v415 * 2) + (((int)((unsigned int)v314 >> 2)) & 1);
  int v416 = v322[v508];
  int * v417 = v310->regs;
  v417[10] = v416;
  struct StateT * v419 = slot_11(v310);
  return v419;
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

struct StateT * slot_8(struct StateT * v280) {
  int v281 = v280->timer;
  int v288 = v281 + 1;
  v280->timer = v288;
  int * v283 = v280->regs;
  int v284 = v283[11];
  int v291 = v284 + 72;
  v283[11] = v291;
  struct StateT * v286 = slot_9(v280);
  return v286;
}

struct StateT * slot_19(struct StateT * v1004) {
  int v1005 = v1004->timer;
  int v1013 = v1005 + 1;
  v1004->timer = v1013;
  int * v1007 = v1004->regs;
  int v1008 = v1007[11];
  int v1009 = v1007[10];
  int v1017 = v1008 & v1009;
  v1007[10] = v1017;
  struct StateT * v1011 = slot_20(v1004);
  return v1011;
}

struct StateT * slot_4(struct StateT * v248) {
  int v249 = v248->timer;
  int v252 = v249 + 1;
  v248->timer = v252;
  return v248;
}

struct StateT * slot_13(struct StateT * v540) {
  int v541 = v540->timer;
  int v547 = v541 + 1;
  v540->timer = v547;
  int * v543 = v540->regs;
  v543[12] = 0;
  struct StateT * v545 = slot_14(v540);
  return v545;
}

struct StateT * slot_15(struct StateT * v567) {
  int v568 = v567->timer;
  int v575 = v568 + 1;
  v567->timer = v575;
  int * v570 = v567->regs;
  int v571 = v570[10];
  int v578 = (int)((unsigned int)v571 >> 26);
  v570[10] = v578;
  struct StateT * v573 = slot_16(v567);
  return v573;
}

struct StateT * slot_18(struct StateT * v800) {
  int v801 = v800->timer;
  int v911 = v801 + 1;
  v800->timer = v911;
  int * v803 = v800->regs;
  int v804 = v803[12];
  int * v805 = v800->cache_tags;
  int v915 = (((int)((unsigned int)((int)((unsigned int)(v804 + 68) >> 2)) >> 1)) & 1) * 2;
  int v806 = v805[v915];
  int v916 = ((((int)((unsigned int)((int)((unsigned int)(v804 + 68) >> 2)) >> 1)) & 1) * 2) + 1;
  int v807 = v805[v916];
  int v917 = 4 + ((((int)((unsigned int)((int)((unsigned int)(v804 + 68) >> 2)) >> 1)) & 3) * 2);
  int v808 = v805[v917];
  int v918 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v804 + 68) >> 2)) >> 1)) & 3) * 2)) + 1;
  int v809 = v805[v918];
  int v810 = v800->timer;
  int v919 = v810 + ((100 ^ (((~(((v808 ^ ((int)((unsigned int)((int)((unsigned int)(v804 + 68) >> 2)) >> 1))) | (-(v808 ^ ((int)((unsigned int)((int)((unsigned int)(v804 + 68) >> 2)) >> 1))))) >> 31)) | (~(((v809 ^ ((int)((unsigned int)((int)((unsigned int)(v804 + 68) >> 2)) >> 1))) | (-(v809 ^ ((int)((unsigned int)((int)((unsigned int)(v804 + 68) >> 2)) >> 1))))) >> 31))) & 104)) ^ (((~(((v806 ^ ((int)((unsigned int)((int)((unsigned int)(v804 + 68) >> 2)) >> 1))) | (-(v806 ^ ((int)((unsigned int)((int)((unsigned int)(v804 + 68) >> 2)) >> 1))))) >> 31)) | (~(((v807 ^ ((int)((unsigned int)((int)((unsigned int)(v804 + 68) >> 2)) >> 1))) | (-(v807 ^ ((int)((unsigned int)((int)((unsigned int)(v804 + 68) >> 2)) >> 1))))) >> 31))) & (1 ^ (100 ^ (((~(((v808 ^ ((int)((unsigned int)((int)((unsigned int)(v804 + 68) >> 2)) >> 1))) | (-(v808 ^ ((int)((unsigned int)((int)((unsigned int)(v804 + 68) >> 2)) >> 1))))) >> 31)) | (~(((v809 ^ ((int)((unsigned int)((int)((unsigned int)(v804 + 68) >> 2)) >> 1))) | (-(v809 ^ ((int)((unsigned int)((int)((unsigned int)(v804 + 68) >> 2)) >> 1))))) >> 31))) & 104)))));
  v800->timer = v919;
  int * v812 = v800->cache_vals;
  bool v920 = !(((~(((v806 ^ ((int)((unsigned int)((int)((unsigned int)(v804 + 68) >> 2)) >> 1))) | (-(v806 ^ ((int)((unsigned int)((int)((unsigned int)(v804 + 68) >> 2)) >> 1))))) >> 31)) | (~(((v807 ^ ((int)((unsigned int)((int)((unsigned int)(v804 + 68) >> 2)) >> 1))) | (-(v807 ^ ((int)((unsigned int)((int)((unsigned int)(v804 + 68) >> 2)) >> 1))))) >> 31))) == 0);
  int v905;
  if (v920) {
    int * v813 = v800->cache_age;
    int v922 = ((((int)((unsigned int)((int)((unsigned int)(v804 + 68) >> 2)) >> 1)) & 1) * 2) + ((~(((v807 ^ ((int)((unsigned int)((int)((unsigned int)(v804 + 68) >> 2)) >> 1))) | (-(v807 ^ ((int)((unsigned int)((int)((unsigned int)(v804 + 68) >> 2)) >> 1))))) >> 31)) & 1);
    int v814 = v813[v922];
    int v815 = v813[v915];
    int v923 = v815 + ((int)((unsigned int)(v815 - v814) >> 31));
    v813[v915] = v923;
    int * v817 = v800->cache_age;
    int v818 = v817[v916];
    int v925 = v818 + ((int)((unsigned int)(v818 - v814) >> 31));
    v817[v916] = v925;
    int * v820 = v800->cache_age;
    v820[v922] = 0;
    v905 = v922;
  } else {
    int * v823 = v800->cache_age;
    int v929 = (((int)((unsigned int)((int)((unsigned int)(v804 + 68) >> 2)) >> 1)) & 1) * 2;
    int v824 = v823[v929];
    int * v825 = v800->cache_tags;
    int v826 = v825[v929];
    int v827 = v823[v916];
    int v828 = v825[v916];
    bool v931 = !(((~(((v808 ^ ((int)((unsigned int)((int)((unsigned int)(v804 + 68) >> 2)) >> 1))) | (-(v808 ^ ((int)((unsigned int)((int)((unsigned int)(v804 + 68) >> 2)) >> 1))))) >> 31)) | (~(((v809 ^ ((int)((unsigned int)((int)((unsigned int)(v804 + 68) >> 2)) >> 1))) | (-(v809 ^ ((int)((unsigned int)((int)((unsigned int)(v804 + 68) >> 2)) >> 1))))) >> 31))) == 0);
    int v882;
    if (v931) {
      int * v829 = v800->cache_age;
      int v933 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v804 + 68) >> 2)) >> 1)) & 3) * 2)) + ((~(((v809 ^ ((int)((unsigned int)((int)((unsigned int)(v804 + 68) >> 2)) >> 1))) | (-(v809 ^ ((int)((unsigned int)((int)((unsigned int)(v804 + 68) >> 2)) >> 1))))) >> 31)) & 1);
      int v830 = v829[v933];
      int v831 = v829[v917];
      int v934 = v831 + ((int)((unsigned int)(v831 - v830) >> 31));
      v829[v917] = v934;
      int * v833 = v800->cache_age;
      int v834 = v833[v918];
      int v936 = v834 + ((int)((unsigned int)(v834 - v830) >> 31));
      v833[v918] = v936;
      int * v836 = v800->cache_age;
      v836[v933] = 0;
      v882 = v933;
    } else {
      int * v839 = v800->cache_age;
      int v940 = 4 + ((((int)((unsigned int)((int)((unsigned int)(v804 + 68) >> 2)) >> 1)) & 3) * 2);
      int v840 = v839[v940];
      int * v841 = v800->cache_tags;
      int v842 = v841[v940];
      int v843 = v839[v918];
      int v844 = v841[v918];
      int * v845 = v800->cache_dirty;
      int v943 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v804 + 68) >> 2)) >> 1)) & 3) * 2)) + ((((v840 + ((~(((v842 ^ -1) | (-(v842 ^ -1))) >> 31)) & 2)) - (v843 + ((~(((v844 ^ -1) | (-(v844 ^ -1))) >> 31)) & 2))) >> 31) & 1);
      int v846 = v845[v943];
      bool v944 = !(v846 == 0);
      if (v944) {
        int * v847 = v800->cache_tags;
        int v848 = v847[v943];
        int * v849 = v800->cache_vals;
        int v947 = ((4 + ((((int)((unsigned int)((int)((unsigned int)(v804 + 68) >> 2)) >> 1)) & 3) * 2)) + ((((v840 + ((~(((v842 ^ -1) | (-(v842 ^ -1))) >> 31)) & 2)) - (v843 + ((~(((v844 ^ -1) | (-(v844 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
        int v850 = v849[v947];
        int v948 = (((4 + ((((int)((unsigned int)((int)((unsigned int)(v804 + 68) >> 2)) >> 1)) & 3) * 2)) + ((((v840 + ((~(((v842 ^ -1) | (-(v842 ^ -1))) >> 31)) & 2)) - (v843 + ((~(((v844 ^ -1) | (-(v844 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
        int v851 = v849[v948];
        int * v852 = v800->mem;
        int v950 = v848 * 2;
        v852[v950] = v850;
        int * v854 = v800->mem;
        int v953 = (v848 * 2) + 1;
        v854[v953] = v851;
        ;
      } else {
        ;
      }
      int * v859 = v800->mem;
      int v958 = ((int)((unsigned int)((int)((unsigned int)(v804 + 68) >> 2)) >> 1)) * 2;
      int v860 = v859[v958];
      int v959 = (((int)((unsigned int)((int)((unsigned int)(v804 + 68) >> 2)) >> 1)) * 2) + 1;
      int v861 = v859[v959];
      int * v862 = v800->cache_vals;
      int v961 = ((4 + ((((int)((unsigned int)((int)((unsigned int)(v804 + 68) >> 2)) >> 1)) & 3) * 2)) + ((((v840 + ((~(((v842 ^ -1) | (-(v842 ^ -1))) >> 31)) & 2)) - (v843 + ((~(((v844 ^ -1) | (-(v844 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
      v862[v961] = v860;
      int * v864 = v800->cache_vals;
      int v964 = (((4 + ((((int)((unsigned int)((int)((unsigned int)(v804 + 68) >> 2)) >> 1)) & 3) * 2)) + ((((v840 + ((~(((v842 ^ -1) | (-(v842 ^ -1))) >> 31)) & 2)) - (v843 + ((~(((v844 ^ -1) | (-(v844 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
      v864[v964] = v861;
      int * v866 = v800->cache_tags;
      int v967 = (int)((unsigned int)((int)((unsigned int)(v804 + 68) >> 2)) >> 1);
      v866[v943] = v967;
      int * v868 = v800->cache_dirty;
      v868[v943] = 0;
      int * v870 = v800->cache_age;
      v870[v943] = 1;
      int * v872 = v800->cache_age;
      int v873 = v872[v943];
      int v874 = v872[v917];
      int v973 = v874 + ((int)((unsigned int)(v874 - v873) >> 31));
      v872[v917] = v973;
      int * v876 = v800->cache_age;
      int v877 = v876[v918];
      int v975 = v877 + ((int)((unsigned int)(v877 - v873) >> 31));
      v876[v918] = v975;
      int * v879 = v800->cache_age;
      v879[v943] = 0;
      v882 = v943;
    }
    int * v883 = v800->cache_vals;
    int v978 = v882 * 2;
    int v884 = v883[v978];
    int v979 = (v882 * 2) + 1;
    int v885 = v883[v979];
    int v980 = (((((int)((unsigned int)((int)((unsigned int)(v804 + 68) >> 2)) >> 1)) & 1) * 2) + ((((v824 + ((~(((v826 ^ -1) | (-(v826 ^ -1))) >> 31)) & 2)) - (v827 + ((~(((v828 ^ -1) | (-(v828 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
    v883[v980] = v884;
    int * v887 = v800->cache_vals;
    int v983 = ((((((int)((unsigned int)((int)((unsigned int)(v804 + 68) >> 2)) >> 1)) & 1) * 2) + ((((v824 + ((~(((v826 ^ -1) | (-(v826 ^ -1))) >> 31)) & 2)) - (v827 + ((~(((v828 ^ -1) | (-(v828 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
    v887[v983] = v885;
    int * v889 = v800->cache_tags;
    int v986 = ((((int)((unsigned int)((int)((unsigned int)(v804 + 68) >> 2)) >> 1)) & 1) * 2) + ((((v824 + ((~(((v826 ^ -1) | (-(v826 ^ -1))) >> 31)) & 2)) - (v827 + ((~(((v828 ^ -1) | (-(v828 ^ -1))) >> 31)) & 2))) >> 31) & 1);
    int v987 = (int)((unsigned int)((int)((unsigned int)(v804 + 68) >> 2)) >> 1);
    v889[v986] = v987;
    int * v891 = v800->cache_dirty;
    v891[v986] = 0;
    int * v893 = v800->cache_age;
    v893[v986] = 1;
    int * v895 = v800->cache_age;
    int v896 = v895[v986];
    int v897 = v895[v915];
    int v993 = v897 + ((int)((unsigned int)(v897 - v896) >> 31));
    v895[v915] = v993;
    int * v899 = v800->cache_age;
    int v900 = v899[v916];
    int v995 = v900 + ((int)((unsigned int)(v900 - v896) >> 31));
    v899[v916] = v995;
    int * v902 = v800->cache_age;
    v902[v986] = 0;
    v905 = v986;
  }
  int v998 = (v905 * 2) + (((int)((unsigned int)(v804 + 68) >> 2)) & 1);
  int v906 = v812[v998];
  int * v907 = v800->regs;
  v907[11] = v906;
  struct StateT * v909 = slot_19(v800);
  return v909;
}

struct StateT * slot_9(struct StateT * v294) {
  int v295 = v294->timer;
  int v303 = v295 + 1;
  v294->timer = v303;
  int * v297 = v294->regs;
  int v298 = v297[11];
  int v299 = v297[10];
  int v307 = v298 + v299;
  v297[10] = v307;
  struct StateT * v301 = slot_10(v294);
  return v301;
}

struct StateT * slot_11(struct StateT * v513) {
  int v514 = v513->timer;
  int v520 = v514 + 1;
  v513->timer = v520;
  int * v516 = v513->regs;
  v516[11] = 0;
  struct StateT * v518 = slot_12(v513);
  return v518;
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