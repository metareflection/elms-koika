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

struct StateT * slot_12(struct StateT * v617);
struct StateT * slot_14(struct StateT * v662);
struct StateT * slot_6(struct StateT * v305);
struct StateT * slot_16(struct StateT * v1077);
struct StateT * slot_5(struct StateT * v284);
struct StateT * slot_17(struct StateT * v1101);
struct StateT * slot_2(struct StateT * v225);
struct StateT * slot_7(struct StateT * v329);
struct StateT * slot_21(struct StateT * v1484);
struct StateT * slot_3(struct StateT * v233);
struct StateT * snippet(struct StateT * v0);
struct StateT * slot_10(struct StateT * v573);
struct StateT * slot_1(struct StateT * v18);
struct StateT * slot_8(struct StateT * v536);
struct StateT * slot_19(struct StateT * v1165);
struct StateT * slot_4(struct StateT * v261);
struct StateT * slot_13(struct StateT * v638);
struct StateT * slot_15(struct StateT * v869);
struct StateT * slot_9(struct StateT * v552);
struct StateT * slot_11(struct StateT * v596);
struct StateT * slot_0(struct StateT * v2);
struct StateT * slot_12(struct StateT * v617) {
  int v618 = v617->timer;
  int v629 = v618 + 1;
  v617->timer = v629;
  int * v620 = v617->reg_ready;
  int v621 = v620[10];
  int * v622 = v617->regs;
  int v623 = v622[10];
  int v633 = (v621 + ((v618 - v621) & (~((v618 - v621) >> 31)))) + 1;
  v620[10] = v633;
  int * v625 = v617->regs;
  int v635 = (int)((unsigned int)v623 >> 26);
  v625[10] = v635;
  struct StateT * v627 = slot_13(v617);
  return v627;
}

struct StateT * slot_14(struct StateT * v662) {
  int v663 = v662->timer;
  int v775 = v663 + 1;
  v662->timer = v775;
  int * v665 = v662->reg_ready;
  int v666 = v665[10];
  int * v667 = v662->regs;
  int v668 = v667[10];
  int * v669 = v662->cache_tags;
  int v780 = (((int)((unsigned int)((int)((unsigned int)v668 >> 2)) >> 1)) & 1) * 2;
  int v670 = v669[v780];
  int v781 = ((((int)((unsigned int)((int)((unsigned int)v668 >> 2)) >> 1)) & 1) * 2) + 1;
  int v671 = v669[v781];
  int v782 = 4 + ((((int)((unsigned int)((int)((unsigned int)v668 >> 2)) >> 1)) & 3) * 2);
  int v672 = v669[v782];
  int v783 = (4 + ((((int)((unsigned int)((int)((unsigned int)v668 >> 2)) >> 1)) & 3) * 2)) + 1;
  int v673 = v669[v783];
  int * v674 = v662->cache_vals;
  bool v784 = !(((~(((v670 ^ ((int)((unsigned int)((int)((unsigned int)v668 >> 2)) >> 1))) | (-(v670 ^ ((int)((unsigned int)((int)((unsigned int)v668 >> 2)) >> 1))))) >> 31)) | (~(((v671 ^ ((int)((unsigned int)((int)((unsigned int)v668 >> 2)) >> 1))) | (-(v671 ^ ((int)((unsigned int)((int)((unsigned int)v668 >> 2)) >> 1))))) >> 31))) == 0);
  int v767;
  if (v784) {
    int * v675 = v662->cache_age;
    int v786 = ((((int)((unsigned int)((int)((unsigned int)v668 >> 2)) >> 1)) & 1) * 2) + ((~(((v671 ^ ((int)((unsigned int)((int)((unsigned int)v668 >> 2)) >> 1))) | (-(v671 ^ ((int)((unsigned int)((int)((unsigned int)v668 >> 2)) >> 1))))) >> 31)) & 1);
    int v676 = v675[v786];
    int v677 = v675[v780];
    int v787 = v677 + ((int)((unsigned int)(v677 - v676) >> 31));
    v675[v780] = v787;
    int * v679 = v662->cache_age;
    int v680 = v679[v781];
    int v789 = v680 + ((int)((unsigned int)(v680 - v676) >> 31));
    v679[v781] = v789;
    int * v682 = v662->cache_age;
    v682[v786] = 0;
    v767 = v786;
  } else {
    int * v685 = v662->cache_age;
    int v793 = (((int)((unsigned int)((int)((unsigned int)v668 >> 2)) >> 1)) & 1) * 2;
    int v686 = v685[v793];
    int * v687 = v662->cache_tags;
    int v688 = v687[v793];
    int v689 = v685[v781];
    int v690 = v687[v781];
    bool v795 = !(((~(((v672 ^ ((int)((unsigned int)((int)((unsigned int)v668 >> 2)) >> 1))) | (-(v672 ^ ((int)((unsigned int)((int)((unsigned int)v668 >> 2)) >> 1))))) >> 31)) | (~(((v673 ^ ((int)((unsigned int)((int)((unsigned int)v668 >> 2)) >> 1))) | (-(v673 ^ ((int)((unsigned int)((int)((unsigned int)v668 >> 2)) >> 1))))) >> 31))) == 0);
    int v744;
    if (v795) {
      int * v691 = v662->cache_age;
      int v797 = (4 + ((((int)((unsigned int)((int)((unsigned int)v668 >> 2)) >> 1)) & 3) * 2)) + ((~(((v673 ^ ((int)((unsigned int)((int)((unsigned int)v668 >> 2)) >> 1))) | (-(v673 ^ ((int)((unsigned int)((int)((unsigned int)v668 >> 2)) >> 1))))) >> 31)) & 1);
      int v692 = v691[v797];
      int v693 = v691[v782];
      int v798 = v693 + ((int)((unsigned int)(v693 - v692) >> 31));
      v691[v782] = v798;
      int * v695 = v662->cache_age;
      int v696 = v695[v783];
      int v800 = v696 + ((int)((unsigned int)(v696 - v692) >> 31));
      v695[v783] = v800;
      int * v698 = v662->cache_age;
      v698[v797] = 0;
      v744 = v797;
    } else {
      int * v701 = v662->cache_age;
      int v804 = 4 + ((((int)((unsigned int)((int)((unsigned int)v668 >> 2)) >> 1)) & 3) * 2);
      int v702 = v701[v804];
      int * v703 = v662->cache_tags;
      int v704 = v703[v804];
      int v705 = v701[v783];
      int v706 = v703[v783];
      int * v707 = v662->cache_dirty;
      int v807 = (4 + ((((int)((unsigned int)((int)((unsigned int)v668 >> 2)) >> 1)) & 3) * 2)) + ((((v702 + ((~(((v704 ^ -1) | (-(v704 ^ -1))) >> 31)) & 2)) - (v705 + ((~(((v706 ^ -1) | (-(v706 ^ -1))) >> 31)) & 2))) >> 31) & 1);
      int v708 = v707[v807];
      bool v808 = !(v708 == 0);
      if (v808) {
        int * v709 = v662->cache_tags;
        int v710 = v709[v807];
        int * v711 = v662->cache_vals;
        int v811 = ((4 + ((((int)((unsigned int)((int)((unsigned int)v668 >> 2)) >> 1)) & 3) * 2)) + ((((v702 + ((~(((v704 ^ -1) | (-(v704 ^ -1))) >> 31)) & 2)) - (v705 + ((~(((v706 ^ -1) | (-(v706 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
        int v712 = v711[v811];
        int v812 = (((4 + ((((int)((unsigned int)((int)((unsigned int)v668 >> 2)) >> 1)) & 3) * 2)) + ((((v702 + ((~(((v704 ^ -1) | (-(v704 ^ -1))) >> 31)) & 2)) - (v705 + ((~(((v706 ^ -1) | (-(v706 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
        int v713 = v711[v812];
        int * v714 = v662->mem;
        int v814 = v710 * 2;
        v714[v814] = v712;
        int * v716 = v662->mem;
        int v817 = (v710 * 2) + 1;
        v716[v817] = v713;
        ;
      } else {
        ;
      }
      int * v721 = v662->mem;
      int v822 = ((int)((unsigned int)((int)((unsigned int)v668 >> 2)) >> 1)) * 2;
      int v722 = v721[v822];
      int v823 = (((int)((unsigned int)((int)((unsigned int)v668 >> 2)) >> 1)) * 2) + 1;
      int v723 = v721[v823];
      int * v724 = v662->cache_vals;
      int v825 = ((4 + ((((int)((unsigned int)((int)((unsigned int)v668 >> 2)) >> 1)) & 3) * 2)) + ((((v702 + ((~(((v704 ^ -1) | (-(v704 ^ -1))) >> 31)) & 2)) - (v705 + ((~(((v706 ^ -1) | (-(v706 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
      v724[v825] = v722;
      int * v726 = v662->cache_vals;
      int v828 = (((4 + ((((int)((unsigned int)((int)((unsigned int)v668 >> 2)) >> 1)) & 3) * 2)) + ((((v702 + ((~(((v704 ^ -1) | (-(v704 ^ -1))) >> 31)) & 2)) - (v705 + ((~(((v706 ^ -1) | (-(v706 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
      v726[v828] = v723;
      int * v728 = v662->cache_tags;
      int v831 = (int)((unsigned int)((int)((unsigned int)v668 >> 2)) >> 1);
      v728[v807] = v831;
      int * v730 = v662->cache_dirty;
      v730[v807] = 0;
      int * v732 = v662->cache_age;
      v732[v807] = 1;
      int * v734 = v662->cache_age;
      int v735 = v734[v807];
      int v736 = v734[v782];
      int v837 = v736 + ((int)((unsigned int)(v736 - v735) >> 31));
      v734[v782] = v837;
      int * v738 = v662->cache_age;
      int v739 = v738[v783];
      int v839 = v739 + ((int)((unsigned int)(v739 - v735) >> 31));
      v738[v783] = v839;
      int * v741 = v662->cache_age;
      v741[v807] = 0;
      v744 = v807;
    }
    int * v745 = v662->cache_vals;
    int v842 = v744 * 2;
    int v746 = v745[v842];
    int v843 = (v744 * 2) + 1;
    int v747 = v745[v843];
    int v844 = (((((int)((unsigned int)((int)((unsigned int)v668 >> 2)) >> 1)) & 1) * 2) + ((((v686 + ((~(((v688 ^ -1) | (-(v688 ^ -1))) >> 31)) & 2)) - (v689 + ((~(((v690 ^ -1) | (-(v690 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
    v745[v844] = v746;
    int * v749 = v662->cache_vals;
    int v847 = ((((((int)((unsigned int)((int)((unsigned int)v668 >> 2)) >> 1)) & 1) * 2) + ((((v686 + ((~(((v688 ^ -1) | (-(v688 ^ -1))) >> 31)) & 2)) - (v689 + ((~(((v690 ^ -1) | (-(v690 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
    v749[v847] = v747;
    int * v751 = v662->cache_tags;
    int v850 = ((((int)((unsigned int)((int)((unsigned int)v668 >> 2)) >> 1)) & 1) * 2) + ((((v686 + ((~(((v688 ^ -1) | (-(v688 ^ -1))) >> 31)) & 2)) - (v689 + ((~(((v690 ^ -1) | (-(v690 ^ -1))) >> 31)) & 2))) >> 31) & 1);
    int v851 = (int)((unsigned int)((int)((unsigned int)v668 >> 2)) >> 1);
    v751[v850] = v851;
    int * v753 = v662->cache_dirty;
    v753[v850] = 0;
    int * v755 = v662->cache_age;
    v755[v850] = 1;
    int * v757 = v662->cache_age;
    int v758 = v757[v850];
    int v759 = v757[v780];
    int v857 = v759 + ((int)((unsigned int)(v759 - v758) >> 31));
    v757[v780] = v857;
    int * v761 = v662->cache_age;
    int v762 = v761[v781];
    int v859 = v762 + ((int)((unsigned int)(v762 - v758) >> 31));
    v761[v781] = v859;
    int * v764 = v662->cache_age;
    v764[v850] = 0;
    v767 = v850;
  }
  int v862 = (v767 * 2) + (((int)((unsigned int)v668 >> 2)) & 1);
  int v768 = v674[v862];
  int * v769 = v662->reg_ready;
  int v864 = ((v666 + ((v663 - v666) & (~((v663 - v666) >> 31)))) + 1) + ((100 ^ (((~(((v672 ^ ((int)((unsigned int)((int)((unsigned int)v668 >> 2)) >> 1))) | (-(v672 ^ ((int)((unsigned int)((int)((unsigned int)v668 >> 2)) >> 1))))) >> 31)) | (~(((v673 ^ ((int)((unsigned int)((int)((unsigned int)v668 >> 2)) >> 1))) | (-(v673 ^ ((int)((unsigned int)((int)((unsigned int)v668 >> 2)) >> 1))))) >> 31))) & 104)) ^ (((~(((v670 ^ ((int)((unsigned int)((int)((unsigned int)v668 >> 2)) >> 1))) | (-(v670 ^ ((int)((unsigned int)((int)((unsigned int)v668 >> 2)) >> 1))))) >> 31)) | (~(((v671 ^ ((int)((unsigned int)((int)((unsigned int)v668 >> 2)) >> 1))) | (-(v671 ^ ((int)((unsigned int)((int)((unsigned int)v668 >> 2)) >> 1))))) >> 31))) & (1 ^ (100 ^ (((~(((v672 ^ ((int)((unsigned int)((int)((unsigned int)v668 >> 2)) >> 1))) | (-(v672 ^ ((int)((unsigned int)((int)((unsigned int)v668 >> 2)) >> 1))))) >> 31)) | (~(((v673 ^ ((int)((unsigned int)((int)((unsigned int)v668 >> 2)) >> 1))) | (-(v673 ^ ((int)((unsigned int)((int)((unsigned int)v668 >> 2)) >> 1))))) >> 31))) & 104)))));
  v769[10] = v864;
  int * v771 = v662->regs;
  v771[10] = v768;
  struct StateT * v773 = slot_15(v662);
  return v773;
}

struct StateT * slot_6(struct StateT * v305) {
  int v306 = v305->timer;
  int v319 = v306 + 1;
  v305->timer = v319;
  int * v308 = v305->reg_ready;
  int v309 = v308[11];
  int * v310 = v305->regs;
  int v311 = v310[11];
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

struct StateT * slot_16(struct StateT * v1077) {
  int v1078 = v1077->timer;
  int v1091 = v1078 + 1;
  v1077->timer = v1091;
  int * v1080 = v1077->reg_ready;
  int v1081 = v1080[11];
  int * v1082 = v1077->regs;
  int v1083 = v1082[11];
  int v1084 = v1080[10];
  int v1085 = v1082[10];
  int v1096 = (v1084 + (((v1081 + ((v1078 - v1081) & (~((v1078 - v1081) >> 31)))) - v1084) & (~(((v1081 + ((v1078 - v1081) & (~((v1078 - v1081) >> 31)))) - v1084) >> 31)))) + 1;
  v1080[10] = v1096;
  int * v1087 = v1077->regs;
  int v1098 = v1083 & v1085;
  v1087[10] = v1098;
  struct StateT * v1089 = slot_17(v1077);
  return v1089;
}

struct StateT * slot_5(struct StateT * v284) {
  int v285 = v284->timer;
  int v296 = v285 + 1;
  v284->timer = v296;
  int * v287 = v284->reg_ready;
  int v288 = v287[11];
  int * v289 = v284->regs;
  int v290 = v289[11];
  int v300 = (v288 + ((v285 - v288) & (~((v285 - v288) >> 31)))) + 1;
  v287[11] = v300;
  int * v292 = v284->regs;
  int v302 = v290 + 72;
  v292[11] = v302;
  struct StateT * v294 = slot_6(v284);
  return v294;
}

struct StateT * slot_17(struct StateT * v1101) {
  int * v1102 = v1101->saved_regs;
  int v1103 = v1102[10];
  int v1104 = v1102[11];
  bool v1137 = (v1103 ^ -2147483648) >= (v1104 ^ -2147483648);
  struct StateT * v1132;
  if (v1137) {
    int v1105 = v1101->timer;
    int v1138 = v1105 + 15;
    v1101->timer = v1138;
    int * v1107 = v1101->saved_regs;
    int v1108 = v1107[10];
    int * v1109 = v1101->regs;
    v1109[10] = v1108;
    int * v1111 = v1101->saved_regs;
    int v1112 = v1111[11];
    int * v1113 = v1101->regs;
    v1113[11] = v1112;
    int * v1115 = v1101->saved_regs;
    int v1116 = v1115[12];
    int * v1117 = v1101->regs;
    v1117[12] = v1116;
    int * v1119 = v1101->reg_ready;
    int v1120 = v1101->timer;
    v1119[10] = v1120;
    int * v1122 = v1101->reg_ready;
    int v1123 = v1101->timer;
    v1122[11] = v1123;
    int * v1125 = v1101->reg_ready;
    int v1126 = v1101->timer;
    v1125[12] = v1126;
    struct StateT * v1128 = slot_21(v1101);
    v1132 = v1128;
  } else {
    struct StateT * v1130 = slot_19(v1101);
    v1132 = v1130;
  }
  return v1132;
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

struct StateT * slot_21(struct StateT * v1484) {
  int v1485 = v1484->timer;
  int v1488 = v1485 + 1;
  v1484->timer = v1488;
  return v1484;
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
  int v1489 = v1->timer;
  int * v1490 = v1->reg_ready;
  int v1491 = v1490[0];
  int v1622 = v1491 + ((v1489 - v1491) & (~((v1489 - v1491) >> 31)));
  v1->timer = v1622;
  int v1493 = v1->timer;
  int * v1494 = v1->reg_ready;
  int v1495 = v1494[1];
  int v1625 = v1495 + ((v1493 - v1495) & (~((v1493 - v1495) >> 31)));
  v1->timer = v1625;
  int v1497 = v1->timer;
  int * v1498 = v1->reg_ready;
  int v1499 = v1498[2];
  int v1628 = v1499 + ((v1497 - v1499) & (~((v1497 - v1499) >> 31)));
  v1->timer = v1628;
  int v1501 = v1->timer;
  int * v1502 = v1->reg_ready;
  int v1503 = v1502[3];
  int v1631 = v1503 + ((v1501 - v1503) & (~((v1501 - v1503) >> 31)));
  v1->timer = v1631;
  int v1505 = v1->timer;
  int * v1506 = v1->reg_ready;
  int v1507 = v1506[4];
  int v1634 = v1507 + ((v1505 - v1507) & (~((v1505 - v1507) >> 31)));
  v1->timer = v1634;
  int v1509 = v1->timer;
  int * v1510 = v1->reg_ready;
  int v1511 = v1510[5];
  int v1637 = v1511 + ((v1509 - v1511) & (~((v1509 - v1511) >> 31)));
  v1->timer = v1637;
  int v1513 = v1->timer;
  int * v1514 = v1->reg_ready;
  int v1515 = v1514[6];
  int v1640 = v1515 + ((v1513 - v1515) & (~((v1513 - v1515) >> 31)));
  v1->timer = v1640;
  int v1517 = v1->timer;
  int * v1518 = v1->reg_ready;
  int v1519 = v1518[7];
  int v1643 = v1519 + ((v1517 - v1519) & (~((v1517 - v1519) >> 31)));
  v1->timer = v1643;
  int v1521 = v1->timer;
  int * v1522 = v1->reg_ready;
  int v1523 = v1522[8];
  int v1646 = v1523 + ((v1521 - v1523) & (~((v1521 - v1523) >> 31)));
  v1->timer = v1646;
  int v1525 = v1->timer;
  int * v1526 = v1->reg_ready;
  int v1527 = v1526[9];
  int v1649 = v1527 + ((v1525 - v1527) & (~((v1525 - v1527) >> 31)));
  v1->timer = v1649;
  int v1529 = v1->timer;
  int * v1530 = v1->reg_ready;
  int v1531 = v1530[10];
  int v1652 = v1531 + ((v1529 - v1531) & (~((v1529 - v1531) >> 31)));
  v1->timer = v1652;
  int v1533 = v1->timer;
  int * v1534 = v1->reg_ready;
  int v1535 = v1534[11];
  int v1655 = v1535 + ((v1533 - v1535) & (~((v1533 - v1535) >> 31)));
  v1->timer = v1655;
  int v1537 = v1->timer;
  int * v1538 = v1->reg_ready;
  int v1539 = v1538[12];
  int v1658 = v1539 + ((v1537 - v1539) & (~((v1537 - v1539) >> 31)));
  v1->timer = v1658;
  int v1541 = v1->timer;
  int * v1542 = v1->reg_ready;
  int v1543 = v1542[13];
  int v1661 = v1543 + ((v1541 - v1543) & (~((v1541 - v1543) >> 31)));
  v1->timer = v1661;
  int v1545 = v1->timer;
  int * v1546 = v1->reg_ready;
  int v1547 = v1546[14];
  int v1664 = v1547 + ((v1545 - v1547) & (~((v1545 - v1547) >> 31)));
  v1->timer = v1664;
  int v1549 = v1->timer;
  int * v1550 = v1->reg_ready;
  int v1551 = v1550[15];
  int v1667 = v1551 + ((v1549 - v1551) & (~((v1549 - v1551) >> 31)));
  v1->timer = v1667;
  int v1553 = v1->timer;
  int * v1554 = v1->reg_ready;
  int v1555 = v1554[16];
  int v1670 = v1555 + ((v1553 - v1555) & (~((v1553 - v1555) >> 31)));
  v1->timer = v1670;
  int v1557 = v1->timer;
  int * v1558 = v1->reg_ready;
  int v1559 = v1558[17];
  int v1673 = v1559 + ((v1557 - v1559) & (~((v1557 - v1559) >> 31)));
  v1->timer = v1673;
  int v1561 = v1->timer;
  int * v1562 = v1->reg_ready;
  int v1563 = v1562[18];
  int v1676 = v1563 + ((v1561 - v1563) & (~((v1561 - v1563) >> 31)));
  v1->timer = v1676;
  int v1565 = v1->timer;
  int * v1566 = v1->reg_ready;
  int v1567 = v1566[19];
  int v1679 = v1567 + ((v1565 - v1567) & (~((v1565 - v1567) >> 31)));
  v1->timer = v1679;
  int v1569 = v1->timer;
  int * v1570 = v1->reg_ready;
  int v1571 = v1570[20];
  int v1682 = v1571 + ((v1569 - v1571) & (~((v1569 - v1571) >> 31)));
  v1->timer = v1682;
  int v1573 = v1->timer;
  int * v1574 = v1->reg_ready;
  int v1575 = v1574[21];
  int v1685 = v1575 + ((v1573 - v1575) & (~((v1573 - v1575) >> 31)));
  v1->timer = v1685;
  int v1577 = v1->timer;
  int * v1578 = v1->reg_ready;
  int v1579 = v1578[22];
  int v1688 = v1579 + ((v1577 - v1579) & (~((v1577 - v1579) >> 31)));
  v1->timer = v1688;
  int v1581 = v1->timer;
  int * v1582 = v1->reg_ready;
  int v1583 = v1582[23];
  int v1691 = v1583 + ((v1581 - v1583) & (~((v1581 - v1583) >> 31)));
  v1->timer = v1691;
  int v1585 = v1->timer;
  int * v1586 = v1->reg_ready;
  int v1587 = v1586[24];
  int v1694 = v1587 + ((v1585 - v1587) & (~((v1585 - v1587) >> 31)));
  v1->timer = v1694;
  int v1589 = v1->timer;
  int * v1590 = v1->reg_ready;
  int v1591 = v1590[25];
  int v1697 = v1591 + ((v1589 - v1591) & (~((v1589 - v1591) >> 31)));
  v1->timer = v1697;
  int v1593 = v1->timer;
  int * v1594 = v1->reg_ready;
  int v1595 = v1594[26];
  int v1700 = v1595 + ((v1593 - v1595) & (~((v1593 - v1595) >> 31)));
  v1->timer = v1700;
  int v1597 = v1->timer;
  int * v1598 = v1->reg_ready;
  int v1599 = v1598[27];
  int v1703 = v1599 + ((v1597 - v1599) & (~((v1597 - v1599) >> 31)));
  v1->timer = v1703;
  int v1601 = v1->timer;
  int * v1602 = v1->reg_ready;
  int v1603 = v1602[28];
  int v1706 = v1603 + ((v1601 - v1603) & (~((v1601 - v1603) >> 31)));
  v1->timer = v1706;
  int v1605 = v1->timer;
  int * v1606 = v1->reg_ready;
  int v1607 = v1606[29];
  int v1709 = v1607 + ((v1605 - v1607) & (~((v1605 - v1607) >> 31)));
  v1->timer = v1709;
  int v1609 = v1->timer;
  int * v1610 = v1->reg_ready;
  int v1611 = v1610[30];
  int v1712 = v1611 + ((v1609 - v1611) & (~((v1609 - v1611) >> 31)));
  v1->timer = v1712;
  int v1613 = v1->timer;
  int * v1614 = v1->reg_ready;
  int v1615 = v1614[31];
  int v1715 = v1615 + ((v1613 - v1615) & (~((v1613 - v1615) >> 31)));
  v1->timer = v1715;
  return v1;
}

struct StateT * slot_10(struct StateT * v573) {
  int * v574 = v573->saved_regs;
  int * v575 = v573->regs;
  int v576 = v575[12];
  v574[12] = v576;
  int v578 = v573->timer;
  int v590 = v578 + 1;
  v573->timer = v590;
  int * v580 = v573->reg_ready;
  v580[12] = v590;
  int * v582 = v573->regs;
  v582[12] = 0;
  struct StateT * v584 = slot_11(v573);
  return v584;
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

struct StateT * slot_8(struct StateT * v536) {
  int v537 = v536->timer;
  int v545 = v537 + 1;
  v536->timer = v545;
  int * v539 = v536->reg_ready;
  v539[11] = v545;
  int * v541 = v536->regs;
  v541[11] = 0;
  struct StateT * v543 = slot_9(v536);
  return v543;
}

struct StateT * slot_19(struct StateT * v1165) {
  int v1166 = v1165->timer;
  int v1339 = v1166 + 1;
  v1165->timer = v1339;
  int * v1168 = v1165->reg_ready;
  int * v1170 = v1165->regs;
  int v1171 = v1170[12];
  int v1173 = v1170[10];
  int * v1174 = v1165->cache_tags;
  int v1345 = (((int)((unsigned int)((int)((unsigned int)(v1171 + 68) >> 2)) >> 1)) & 1) * 2;
  int v1175 = v1174[v1345];
  int v1346 = ((((int)((unsigned int)((int)((unsigned int)(v1171 + 68) >> 2)) >> 1)) & 1) * 2) + 1;
  int v1176 = v1174[v1346];
  int v1347 = 4 + ((((int)((unsigned int)((int)((unsigned int)(v1171 + 68) >> 2)) >> 1)) & 3) * 2);
  int v1177 = v1174[v1347];
  int v1348 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v1171 + 68) >> 2)) >> 1)) & 3) * 2)) + 1;
  int v1178 = v1174[v1348];
  int v1179 = v1165->timer;
  int v1349 = v1179 + ((100 ^ (((~(((v1177 ^ ((int)((unsigned int)((int)((unsigned int)(v1171 + 68) >> 2)) >> 1))) | (-(v1177 ^ ((int)((unsigned int)((int)((unsigned int)(v1171 + 68) >> 2)) >> 1))))) >> 31)) | (~(((v1178 ^ ((int)((unsigned int)((int)((unsigned int)(v1171 + 68) >> 2)) >> 1))) | (-(v1178 ^ ((int)((unsigned int)((int)((unsigned int)(v1171 + 68) >> 2)) >> 1))))) >> 31))) & 104)) ^ (((~(((v1175 ^ ((int)((unsigned int)((int)((unsigned int)(v1171 + 68) >> 2)) >> 1))) | (-(v1175 ^ ((int)((unsigned int)((int)((unsigned int)(v1171 + 68) >> 2)) >> 1))))) >> 31)) | (~(((v1176 ^ ((int)((unsigned int)((int)((unsigned int)(v1171 + 68) >> 2)) >> 1))) | (-(v1176 ^ ((int)((unsigned int)((int)((unsigned int)(v1171 + 68) >> 2)) >> 1))))) >> 31))) & (1 ^ (100 ^ (((~(((v1177 ^ ((int)((unsigned int)((int)((unsigned int)(v1171 + 68) >> 2)) >> 1))) | (-(v1177 ^ ((int)((unsigned int)((int)((unsigned int)(v1171 + 68) >> 2)) >> 1))))) >> 31)) | (~(((v1178 ^ ((int)((unsigned int)((int)((unsigned int)(v1171 + 68) >> 2)) >> 1))) | (-(v1178 ^ ((int)((unsigned int)((int)((unsigned int)(v1171 + 68) >> 2)) >> 1))))) >> 31))) & 104)))));
  v1165->timer = v1349;
  bool v1350 = !(((~(((v1175 ^ ((int)((unsigned int)((int)((unsigned int)(v1171 + 68) >> 2)) >> 1))) | (-(v1175 ^ ((int)((unsigned int)((int)((unsigned int)(v1171 + 68) >> 2)) >> 1))))) >> 31)) | (~(((v1176 ^ ((int)((unsigned int)((int)((unsigned int)(v1171 + 68) >> 2)) >> 1))) | (-(v1176 ^ ((int)((unsigned int)((int)((unsigned int)(v1171 + 68) >> 2)) >> 1))))) >> 31))) == 0);
  int v1273;
  if (v1350) {
    int * v1181 = v1165->cache_age;
    int v1352 = ((((int)((unsigned int)((int)((unsigned int)(v1171 + 68) >> 2)) >> 1)) & 1) * 2) + ((~(((v1176 ^ ((int)((unsigned int)((int)((unsigned int)(v1171 + 68) >> 2)) >> 1))) | (-(v1176 ^ ((int)((unsigned int)((int)((unsigned int)(v1171 + 68) >> 2)) >> 1))))) >> 31)) & 1);
    int v1182 = v1181[v1352];
    int v1183 = v1181[v1345];
    int v1353 = v1183 + ((int)((unsigned int)(v1183 - v1182) >> 31));
    v1181[v1345] = v1353;
    int * v1185 = v1165->cache_age;
    int v1186 = v1185[v1346];
    int v1355 = v1186 + ((int)((unsigned int)(v1186 - v1182) >> 31));
    v1185[v1346] = v1355;
    int * v1188 = v1165->cache_age;
    v1188[v1352] = 0;
    v1273 = v1352;
  } else {
    int * v1191 = v1165->cache_age;
    int v1359 = (((int)((unsigned int)((int)((unsigned int)(v1171 + 68) >> 2)) >> 1)) & 1) * 2;
    int v1192 = v1191[v1359];
    int * v1193 = v1165->cache_tags;
    int v1194 = v1193[v1359];
    int v1195 = v1191[v1346];
    int v1196 = v1193[v1346];
    bool v1361 = !(((~(((v1177 ^ ((int)((unsigned int)((int)((unsigned int)(v1171 + 68) >> 2)) >> 1))) | (-(v1177 ^ ((int)((unsigned int)((int)((unsigned int)(v1171 + 68) >> 2)) >> 1))))) >> 31)) | (~(((v1178 ^ ((int)((unsigned int)((int)((unsigned int)(v1171 + 68) >> 2)) >> 1))) | (-(v1178 ^ ((int)((unsigned int)((int)((unsigned int)(v1171 + 68) >> 2)) >> 1))))) >> 31))) == 0);
    int v1250;
    if (v1361) {
      int * v1197 = v1165->cache_age;
      int v1363 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v1171 + 68) >> 2)) >> 1)) & 3) * 2)) + ((~(((v1178 ^ ((int)((unsigned int)((int)((unsigned int)(v1171 + 68) >> 2)) >> 1))) | (-(v1178 ^ ((int)((unsigned int)((int)((unsigned int)(v1171 + 68) >> 2)) >> 1))))) >> 31)) & 1);
      int v1198 = v1197[v1363];
      int v1199 = v1197[v1347];
      int v1364 = v1199 + ((int)((unsigned int)(v1199 - v1198) >> 31));
      v1197[v1347] = v1364;
      int * v1201 = v1165->cache_age;
      int v1202 = v1201[v1348];
      int v1366 = v1202 + ((int)((unsigned int)(v1202 - v1198) >> 31));
      v1201[v1348] = v1366;
      int * v1204 = v1165->cache_age;
      v1204[v1363] = 0;
      v1250 = v1363;
    } else {
      int * v1207 = v1165->cache_age;
      int v1370 = 4 + ((((int)((unsigned int)((int)((unsigned int)(v1171 + 68) >> 2)) >> 1)) & 3) * 2);
      int v1208 = v1207[v1370];
      int * v1209 = v1165->cache_tags;
      int v1210 = v1209[v1370];
      int v1211 = v1207[v1348];
      int v1212 = v1209[v1348];
      int * v1213 = v1165->cache_dirty;
      int v1373 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v1171 + 68) >> 2)) >> 1)) & 3) * 2)) + ((((v1208 + ((~(((v1210 ^ -1) | (-(v1210 ^ -1))) >> 31)) & 2)) - (v1211 + ((~(((v1212 ^ -1) | (-(v1212 ^ -1))) >> 31)) & 2))) >> 31) & 1);
      int v1214 = v1213[v1373];
      bool v1374 = !(v1214 == 0);
      if (v1374) {
        int * v1215 = v1165->cache_tags;
        int v1216 = v1215[v1373];
        int * v1217 = v1165->cache_vals;
        int v1377 = ((4 + ((((int)((unsigned int)((int)((unsigned int)(v1171 + 68) >> 2)) >> 1)) & 3) * 2)) + ((((v1208 + ((~(((v1210 ^ -1) | (-(v1210 ^ -1))) >> 31)) & 2)) - (v1211 + ((~(((v1212 ^ -1) | (-(v1212 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
        int v1218 = v1217[v1377];
        int v1378 = (((4 + ((((int)((unsigned int)((int)((unsigned int)(v1171 + 68) >> 2)) >> 1)) & 3) * 2)) + ((((v1208 + ((~(((v1210 ^ -1) | (-(v1210 ^ -1))) >> 31)) & 2)) - (v1211 + ((~(((v1212 ^ -1) | (-(v1212 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
        int v1219 = v1217[v1378];
        int * v1220 = v1165->mem;
        int v1380 = v1216 * 2;
        v1220[v1380] = v1218;
        int * v1222 = v1165->mem;
        int v1383 = (v1216 * 2) + 1;
        v1222[v1383] = v1219;
        ;
      } else {
        ;
      }
      int * v1227 = v1165->mem;
      int v1388 = ((int)((unsigned int)((int)((unsigned int)(v1171 + 68) >> 2)) >> 1)) * 2;
      int v1228 = v1227[v1388];
      int v1389 = (((int)((unsigned int)((int)((unsigned int)(v1171 + 68) >> 2)) >> 1)) * 2) + 1;
      int v1229 = v1227[v1389];
      int * v1230 = v1165->cache_vals;
      int v1391 = ((4 + ((((int)((unsigned int)((int)((unsigned int)(v1171 + 68) >> 2)) >> 1)) & 3) * 2)) + ((((v1208 + ((~(((v1210 ^ -1) | (-(v1210 ^ -1))) >> 31)) & 2)) - (v1211 + ((~(((v1212 ^ -1) | (-(v1212 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
      v1230[v1391] = v1228;
      int * v1232 = v1165->cache_vals;
      int v1394 = (((4 + ((((int)((unsigned int)((int)((unsigned int)(v1171 + 68) >> 2)) >> 1)) & 3) * 2)) + ((((v1208 + ((~(((v1210 ^ -1) | (-(v1210 ^ -1))) >> 31)) & 2)) - (v1211 + ((~(((v1212 ^ -1) | (-(v1212 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
      v1232[v1394] = v1229;
      int * v1234 = v1165->cache_tags;
      int v1397 = (int)((unsigned int)((int)((unsigned int)(v1171 + 68) >> 2)) >> 1);
      v1234[v1373] = v1397;
      int * v1236 = v1165->cache_dirty;
      v1236[v1373] = 0;
      int * v1238 = v1165->cache_age;
      v1238[v1373] = 1;
      int * v1240 = v1165->cache_age;
      int v1241 = v1240[v1373];
      int v1242 = v1240[v1347];
      int v1403 = v1242 + ((int)((unsigned int)(v1242 - v1241) >> 31));
      v1240[v1347] = v1403;
      int * v1244 = v1165->cache_age;
      int v1245 = v1244[v1348];
      int v1405 = v1245 + ((int)((unsigned int)(v1245 - v1241) >> 31));
      v1244[v1348] = v1405;
      int * v1247 = v1165->cache_age;
      v1247[v1373] = 0;
      v1250 = v1373;
    }
    int * v1251 = v1165->cache_vals;
    int v1408 = v1250 * 2;
    int v1252 = v1251[v1408];
    int v1409 = (v1250 * 2) + 1;
    int v1253 = v1251[v1409];
    int v1410 = (((((int)((unsigned int)((int)((unsigned int)(v1171 + 68) >> 2)) >> 1)) & 1) * 2) + ((((v1192 + ((~(((v1194 ^ -1) | (-(v1194 ^ -1))) >> 31)) & 2)) - (v1195 + ((~(((v1196 ^ -1) | (-(v1196 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
    v1251[v1410] = v1252;
    int * v1255 = v1165->cache_vals;
    int v1413 = ((((((int)((unsigned int)((int)((unsigned int)(v1171 + 68) >> 2)) >> 1)) & 1) * 2) + ((((v1192 + ((~(((v1194 ^ -1) | (-(v1194 ^ -1))) >> 31)) & 2)) - (v1195 + ((~(((v1196 ^ -1) | (-(v1196 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
    v1255[v1413] = v1253;
    int * v1257 = v1165->cache_tags;
    int v1416 = ((((int)((unsigned int)((int)((unsigned int)(v1171 + 68) >> 2)) >> 1)) & 1) * 2) + ((((v1192 + ((~(((v1194 ^ -1) | (-(v1194 ^ -1))) >> 31)) & 2)) - (v1195 + ((~(((v1196 ^ -1) | (-(v1196 ^ -1))) >> 31)) & 2))) >> 31) & 1);
    int v1417 = (int)((unsigned int)((int)((unsigned int)(v1171 + 68) >> 2)) >> 1);
    v1257[v1416] = v1417;
    int * v1259 = v1165->cache_dirty;
    v1259[v1416] = 0;
    int * v1261 = v1165->cache_age;
    v1261[v1416] = 1;
    int * v1263 = v1165->cache_age;
    int v1264 = v1263[v1416];
    int v1265 = v1263[v1345];
    int v1423 = v1265 + ((int)((unsigned int)(v1265 - v1264) >> 31));
    v1263[v1345] = v1423;
    int * v1267 = v1165->cache_age;
    int v1268 = v1267[v1346];
    int v1425 = v1268 + ((int)((unsigned int)(v1268 - v1264) >> 31));
    v1267[v1346] = v1425;
    int * v1270 = v1165->cache_age;
    v1270[v1416] = 0;
    v1273 = v1416;
  }
  int * v1274 = v1165->cache_vals;
  int v1428 = (v1273 * 2) + (((int)((unsigned int)(v1171 + 68) >> 2)) & 1);
  v1274[v1428] = v1173;
  int * v1276 = v1165->cache_tags;
  int v1277 = v1276[v1347];
  int v1278 = v1276[v1348];
  bool v1431 = !(((~(((v1277 ^ ((int)((unsigned int)((int)((unsigned int)(v1171 + 68) >> 2)) >> 1))) | (-(v1277 ^ ((int)((unsigned int)((int)((unsigned int)(v1171 + 68) >> 2)) >> 1))))) >> 31)) | (~(((v1278 ^ ((int)((unsigned int)((int)((unsigned int)(v1171 + 68) >> 2)) >> 1))) | (-(v1278 ^ ((int)((unsigned int)((int)((unsigned int)(v1171 + 68) >> 2)) >> 1))))) >> 31))) == 0);
  int v1332;
  if (v1431) {
    int * v1279 = v1165->cache_age;
    int v1433 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v1171 + 68) >> 2)) >> 1)) & 3) * 2)) + ((~(((v1278 ^ ((int)((unsigned int)((int)((unsigned int)(v1171 + 68) >> 2)) >> 1))) | (-(v1278 ^ ((int)((unsigned int)((int)((unsigned int)(v1171 + 68) >> 2)) >> 1))))) >> 31)) & 1);
    int v1280 = v1279[v1433];
    int v1281 = v1279[v1347];
    int v1434 = v1281 + ((int)((unsigned int)(v1281 - v1280) >> 31));
    v1279[v1347] = v1434;
    int * v1283 = v1165->cache_age;
    int v1284 = v1283[v1348];
    int v1436 = v1284 + ((int)((unsigned int)(v1284 - v1280) >> 31));
    v1283[v1348] = v1436;
    int * v1286 = v1165->cache_age;
    v1286[v1433] = 0;
    v1332 = v1433;
  } else {
    int * v1289 = v1165->cache_age;
    int v1440 = 4 + ((((int)((unsigned int)((int)((unsigned int)(v1171 + 68) >> 2)) >> 1)) & 3) * 2);
    int v1290 = v1289[v1440];
    int * v1291 = v1165->cache_tags;
    int v1292 = v1291[v1440];
    int v1293 = v1289[v1348];
    int v1294 = v1291[v1348];
    int * v1295 = v1165->cache_dirty;
    int v1443 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v1171 + 68) >> 2)) >> 1)) & 3) * 2)) + ((((v1290 + ((~(((v1292 ^ -1) | (-(v1292 ^ -1))) >> 31)) & 2)) - (v1293 + ((~(((v1294 ^ -1) | (-(v1294 ^ -1))) >> 31)) & 2))) >> 31) & 1);
    int v1296 = v1295[v1443];
    bool v1444 = !(v1296 == 0);
    if (v1444) {
      int * v1297 = v1165->cache_tags;
      int v1298 = v1297[v1443];
      int * v1299 = v1165->cache_vals;
      int v1447 = ((4 + ((((int)((unsigned int)((int)((unsigned int)(v1171 + 68) >> 2)) >> 1)) & 3) * 2)) + ((((v1290 + ((~(((v1292 ^ -1) | (-(v1292 ^ -1))) >> 31)) & 2)) - (v1293 + ((~(((v1294 ^ -1) | (-(v1294 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
      int v1300 = v1299[v1447];
      int v1448 = (((4 + ((((int)((unsigned int)((int)((unsigned int)(v1171 + 68) >> 2)) >> 1)) & 3) * 2)) + ((((v1290 + ((~(((v1292 ^ -1) | (-(v1292 ^ -1))) >> 31)) & 2)) - (v1293 + ((~(((v1294 ^ -1) | (-(v1294 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
      int v1301 = v1299[v1448];
      int * v1302 = v1165->mem;
      int v1450 = v1298 * 2;
      v1302[v1450] = v1300;
      int * v1304 = v1165->mem;
      int v1453 = (v1298 * 2) + 1;
      v1304[v1453] = v1301;
      ;
    } else {
      ;
    }
    int * v1309 = v1165->mem;
    int v1458 = ((int)((unsigned int)((int)((unsigned int)(v1171 + 68) >> 2)) >> 1)) * 2;
    int v1310 = v1309[v1458];
    int v1459 = (((int)((unsigned int)((int)((unsigned int)(v1171 + 68) >> 2)) >> 1)) * 2) + 1;
    int v1311 = v1309[v1459];
    int * v1312 = v1165->cache_vals;
    int v1461 = ((4 + ((((int)((unsigned int)((int)((unsigned int)(v1171 + 68) >> 2)) >> 1)) & 3) * 2)) + ((((v1290 + ((~(((v1292 ^ -1) | (-(v1292 ^ -1))) >> 31)) & 2)) - (v1293 + ((~(((v1294 ^ -1) | (-(v1294 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
    v1312[v1461] = v1310;
    int * v1314 = v1165->cache_vals;
    int v1464 = (((4 + ((((int)((unsigned int)((int)((unsigned int)(v1171 + 68) >> 2)) >> 1)) & 3) * 2)) + ((((v1290 + ((~(((v1292 ^ -1) | (-(v1292 ^ -1))) >> 31)) & 2)) - (v1293 + ((~(((v1294 ^ -1) | (-(v1294 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
    v1314[v1464] = v1311;
    int * v1316 = v1165->cache_tags;
    int v1467 = (int)((unsigned int)((int)((unsigned int)(v1171 + 68) >> 2)) >> 1);
    v1316[v1443] = v1467;
    int * v1318 = v1165->cache_dirty;
    v1318[v1443] = 0;
    int * v1320 = v1165->cache_age;
    v1320[v1443] = 1;
    int * v1322 = v1165->cache_age;
    int v1323 = v1322[v1443];
    int v1324 = v1322[v1347];
    int v1473 = v1324 + ((int)((unsigned int)(v1324 - v1323) >> 31));
    v1322[v1347] = v1473;
    int * v1326 = v1165->cache_age;
    int v1327 = v1326[v1348];
    int v1475 = v1327 + ((int)((unsigned int)(v1327 - v1323) >> 31));
    v1326[v1348] = v1475;
    int * v1329 = v1165->cache_age;
    v1329[v1443] = 0;
    v1332 = v1443;
  }
  int * v1333 = v1165->cache_vals;
  int v1478 = (v1332 * 2) + (((int)((unsigned int)(v1171 + 68) >> 2)) & 1);
  v1333[v1478] = v1173;
  int * v1335 = v1165->cache_dirty;
  v1335[v1332] = 1;
  struct StateT * v1337 = slot_21(v1165);
  return v1337;
}

struct StateT * slot_4(struct StateT * v261) {
  int * v262 = v261->saved_regs;
  int * v263 = v261->regs;
  int v264 = v263[11];
  v262[11] = v264;
  int v266 = v261->timer;
  int v278 = v266 + 1;
  v261->timer = v278;
  int * v268 = v261->reg_ready;
  v268[11] = v278;
  int * v270 = v261->regs;
  v270[11] = 0;
  struct StateT * v272 = slot_5(v261);
  return v272;
}

struct StateT * slot_13(struct StateT * v638) {
  int v639 = v638->timer;
  int v652 = v639 + 1;
  v638->timer = v652;
  int * v641 = v638->reg_ready;
  int v642 = v641[11];
  int * v643 = v638->regs;
  int v644 = v643[11];
  int v645 = v641[10];
  int v646 = v643[10];
  int v657 = (v645 + (((v642 + ((v639 - v642) & (~((v639 - v642) >> 31)))) - v645) & (~(((v642 + ((v639 - v642) & (~((v639 - v642) >> 31)))) - v645) >> 31)))) + 1;
  v641[10] = v657;
  int * v648 = v638->regs;
  int v659 = v644 + v646;
  v648[10] = v659;
  struct StateT * v650 = slot_14(v638);
  return v650;
}

struct StateT * slot_15(struct StateT * v869) {
  int v870 = v869->timer;
  int v982 = v870 + 1;
  v869->timer = v982;
  int * v872 = v869->reg_ready;
  int v873 = v872[12];
  int * v874 = v869->regs;
  int v875 = v874[12];
  int * v876 = v869->cache_tags;
  int v987 = (((int)((unsigned int)((int)((unsigned int)(v875 + 68) >> 2)) >> 1)) & 1) * 2;
  int v877 = v876[v987];
  int v988 = ((((int)((unsigned int)((int)((unsigned int)(v875 + 68) >> 2)) >> 1)) & 1) * 2) + 1;
  int v878 = v876[v988];
  int v989 = 4 + ((((int)((unsigned int)((int)((unsigned int)(v875 + 68) >> 2)) >> 1)) & 3) * 2);
  int v879 = v876[v989];
  int v990 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v875 + 68) >> 2)) >> 1)) & 3) * 2)) + 1;
  int v880 = v876[v990];
  int * v881 = v869->cache_vals;
  bool v991 = !(((~(((v877 ^ ((int)((unsigned int)((int)((unsigned int)(v875 + 68) >> 2)) >> 1))) | (-(v877 ^ ((int)((unsigned int)((int)((unsigned int)(v875 + 68) >> 2)) >> 1))))) >> 31)) | (~(((v878 ^ ((int)((unsigned int)((int)((unsigned int)(v875 + 68) >> 2)) >> 1))) | (-(v878 ^ ((int)((unsigned int)((int)((unsigned int)(v875 + 68) >> 2)) >> 1))))) >> 31))) == 0);
  int v974;
  if (v991) {
    int * v882 = v869->cache_age;
    int v993 = ((((int)((unsigned int)((int)((unsigned int)(v875 + 68) >> 2)) >> 1)) & 1) * 2) + ((~(((v878 ^ ((int)((unsigned int)((int)((unsigned int)(v875 + 68) >> 2)) >> 1))) | (-(v878 ^ ((int)((unsigned int)((int)((unsigned int)(v875 + 68) >> 2)) >> 1))))) >> 31)) & 1);
    int v883 = v882[v993];
    int v884 = v882[v987];
    int v994 = v884 + ((int)((unsigned int)(v884 - v883) >> 31));
    v882[v987] = v994;
    int * v886 = v869->cache_age;
    int v887 = v886[v988];
    int v996 = v887 + ((int)((unsigned int)(v887 - v883) >> 31));
    v886[v988] = v996;
    int * v889 = v869->cache_age;
    v889[v993] = 0;
    v974 = v993;
  } else {
    int * v892 = v869->cache_age;
    int v1000 = (((int)((unsigned int)((int)((unsigned int)(v875 + 68) >> 2)) >> 1)) & 1) * 2;
    int v893 = v892[v1000];
    int * v894 = v869->cache_tags;
    int v895 = v894[v1000];
    int v896 = v892[v988];
    int v897 = v894[v988];
    bool v1002 = !(((~(((v879 ^ ((int)((unsigned int)((int)((unsigned int)(v875 + 68) >> 2)) >> 1))) | (-(v879 ^ ((int)((unsigned int)((int)((unsigned int)(v875 + 68) >> 2)) >> 1))))) >> 31)) | (~(((v880 ^ ((int)((unsigned int)((int)((unsigned int)(v875 + 68) >> 2)) >> 1))) | (-(v880 ^ ((int)((unsigned int)((int)((unsigned int)(v875 + 68) >> 2)) >> 1))))) >> 31))) == 0);
    int v951;
    if (v1002) {
      int * v898 = v869->cache_age;
      int v1004 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v875 + 68) >> 2)) >> 1)) & 3) * 2)) + ((~(((v880 ^ ((int)((unsigned int)((int)((unsigned int)(v875 + 68) >> 2)) >> 1))) | (-(v880 ^ ((int)((unsigned int)((int)((unsigned int)(v875 + 68) >> 2)) >> 1))))) >> 31)) & 1);
      int v899 = v898[v1004];
      int v900 = v898[v989];
      int v1005 = v900 + ((int)((unsigned int)(v900 - v899) >> 31));
      v898[v989] = v1005;
      int * v902 = v869->cache_age;
      int v903 = v902[v990];
      int v1007 = v903 + ((int)((unsigned int)(v903 - v899) >> 31));
      v902[v990] = v1007;
      int * v905 = v869->cache_age;
      v905[v1004] = 0;
      v951 = v1004;
    } else {
      int * v908 = v869->cache_age;
      int v1011 = 4 + ((((int)((unsigned int)((int)((unsigned int)(v875 + 68) >> 2)) >> 1)) & 3) * 2);
      int v909 = v908[v1011];
      int * v910 = v869->cache_tags;
      int v911 = v910[v1011];
      int v912 = v908[v990];
      int v913 = v910[v990];
      int * v914 = v869->cache_dirty;
      int v1014 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v875 + 68) >> 2)) >> 1)) & 3) * 2)) + ((((v909 + ((~(((v911 ^ -1) | (-(v911 ^ -1))) >> 31)) & 2)) - (v912 + ((~(((v913 ^ -1) | (-(v913 ^ -1))) >> 31)) & 2))) >> 31) & 1);
      int v915 = v914[v1014];
      bool v1015 = !(v915 == 0);
      if (v1015) {
        int * v916 = v869->cache_tags;
        int v917 = v916[v1014];
        int * v918 = v869->cache_vals;
        int v1018 = ((4 + ((((int)((unsigned int)((int)((unsigned int)(v875 + 68) >> 2)) >> 1)) & 3) * 2)) + ((((v909 + ((~(((v911 ^ -1) | (-(v911 ^ -1))) >> 31)) & 2)) - (v912 + ((~(((v913 ^ -1) | (-(v913 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
        int v919 = v918[v1018];
        int v1019 = (((4 + ((((int)((unsigned int)((int)((unsigned int)(v875 + 68) >> 2)) >> 1)) & 3) * 2)) + ((((v909 + ((~(((v911 ^ -1) | (-(v911 ^ -1))) >> 31)) & 2)) - (v912 + ((~(((v913 ^ -1) | (-(v913 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
        int v920 = v918[v1019];
        int * v921 = v869->mem;
        int v1021 = v917 * 2;
        v921[v1021] = v919;
        int * v923 = v869->mem;
        int v1024 = (v917 * 2) + 1;
        v923[v1024] = v920;
        ;
      } else {
        ;
      }
      int * v928 = v869->mem;
      int v1029 = ((int)((unsigned int)((int)((unsigned int)(v875 + 68) >> 2)) >> 1)) * 2;
      int v929 = v928[v1029];
      int v1030 = (((int)((unsigned int)((int)((unsigned int)(v875 + 68) >> 2)) >> 1)) * 2) + 1;
      int v930 = v928[v1030];
      int * v931 = v869->cache_vals;
      int v1032 = ((4 + ((((int)((unsigned int)((int)((unsigned int)(v875 + 68) >> 2)) >> 1)) & 3) * 2)) + ((((v909 + ((~(((v911 ^ -1) | (-(v911 ^ -1))) >> 31)) & 2)) - (v912 + ((~(((v913 ^ -1) | (-(v913 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
      v931[v1032] = v929;
      int * v933 = v869->cache_vals;
      int v1035 = (((4 + ((((int)((unsigned int)((int)((unsigned int)(v875 + 68) >> 2)) >> 1)) & 3) * 2)) + ((((v909 + ((~(((v911 ^ -1) | (-(v911 ^ -1))) >> 31)) & 2)) - (v912 + ((~(((v913 ^ -1) | (-(v913 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
      v933[v1035] = v930;
      int * v935 = v869->cache_tags;
      int v1038 = (int)((unsigned int)((int)((unsigned int)(v875 + 68) >> 2)) >> 1);
      v935[v1014] = v1038;
      int * v937 = v869->cache_dirty;
      v937[v1014] = 0;
      int * v939 = v869->cache_age;
      v939[v1014] = 1;
      int * v941 = v869->cache_age;
      int v942 = v941[v1014];
      int v943 = v941[v989];
      int v1044 = v943 + ((int)((unsigned int)(v943 - v942) >> 31));
      v941[v989] = v1044;
      int * v945 = v869->cache_age;
      int v946 = v945[v990];
      int v1046 = v946 + ((int)((unsigned int)(v946 - v942) >> 31));
      v945[v990] = v1046;
      int * v948 = v869->cache_age;
      v948[v1014] = 0;
      v951 = v1014;
    }
    int * v952 = v869->cache_vals;
    int v1049 = v951 * 2;
    int v953 = v952[v1049];
    int v1050 = (v951 * 2) + 1;
    int v954 = v952[v1050];
    int v1051 = (((((int)((unsigned int)((int)((unsigned int)(v875 + 68) >> 2)) >> 1)) & 1) * 2) + ((((v893 + ((~(((v895 ^ -1) | (-(v895 ^ -1))) >> 31)) & 2)) - (v896 + ((~(((v897 ^ -1) | (-(v897 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
    v952[v1051] = v953;
    int * v956 = v869->cache_vals;
    int v1054 = ((((((int)((unsigned int)((int)((unsigned int)(v875 + 68) >> 2)) >> 1)) & 1) * 2) + ((((v893 + ((~(((v895 ^ -1) | (-(v895 ^ -1))) >> 31)) & 2)) - (v896 + ((~(((v897 ^ -1) | (-(v897 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
    v956[v1054] = v954;
    int * v958 = v869->cache_tags;
    int v1057 = ((((int)((unsigned int)((int)((unsigned int)(v875 + 68) >> 2)) >> 1)) & 1) * 2) + ((((v893 + ((~(((v895 ^ -1) | (-(v895 ^ -1))) >> 31)) & 2)) - (v896 + ((~(((v897 ^ -1) | (-(v897 ^ -1))) >> 31)) & 2))) >> 31) & 1);
    int v1058 = (int)((unsigned int)((int)((unsigned int)(v875 + 68) >> 2)) >> 1);
    v958[v1057] = v1058;
    int * v960 = v869->cache_dirty;
    v960[v1057] = 0;
    int * v962 = v869->cache_age;
    v962[v1057] = 1;
    int * v964 = v869->cache_age;
    int v965 = v964[v1057];
    int v966 = v964[v987];
    int v1064 = v966 + ((int)((unsigned int)(v966 - v965) >> 31));
    v964[v987] = v1064;
    int * v968 = v869->cache_age;
    int v969 = v968[v988];
    int v1066 = v969 + ((int)((unsigned int)(v969 - v965) >> 31));
    v968[v988] = v1066;
    int * v971 = v869->cache_age;
    v971[v1057] = 0;
    v974 = v1057;
  }
  int v1069 = (v974 * 2) + (((int)((unsigned int)(v875 + 68) >> 2)) & 1);
  int v975 = v881[v1069];
  int * v976 = v869->reg_ready;
  int v1072 = ((v873 + ((v870 - v873) & (~((v870 - v873) >> 31)))) + 1) + ((100 ^ (((~(((v879 ^ ((int)((unsigned int)((int)((unsigned int)(v875 + 68) >> 2)) >> 1))) | (-(v879 ^ ((int)((unsigned int)((int)((unsigned int)(v875 + 68) >> 2)) >> 1))))) >> 31)) | (~(((v880 ^ ((int)((unsigned int)((int)((unsigned int)(v875 + 68) >> 2)) >> 1))) | (-(v880 ^ ((int)((unsigned int)((int)((unsigned int)(v875 + 68) >> 2)) >> 1))))) >> 31))) & 104)) ^ (((~(((v877 ^ ((int)((unsigned int)((int)((unsigned int)(v875 + 68) >> 2)) >> 1))) | (-(v877 ^ ((int)((unsigned int)((int)((unsigned int)(v875 + 68) >> 2)) >> 1))))) >> 31)) | (~(((v878 ^ ((int)((unsigned int)((int)((unsigned int)(v875 + 68) >> 2)) >> 1))) | (-(v878 ^ ((int)((unsigned int)((int)((unsigned int)(v875 + 68) >> 2)) >> 1))))) >> 31))) & (1 ^ (100 ^ (((~(((v879 ^ ((int)((unsigned int)((int)((unsigned int)(v875 + 68) >> 2)) >> 1))) | (-(v879 ^ ((int)((unsigned int)((int)((unsigned int)(v875 + 68) >> 2)) >> 1))))) >> 31)) | (~(((v880 ^ ((int)((unsigned int)((int)((unsigned int)(v875 + 68) >> 2)) >> 1))) | (-(v880 ^ ((int)((unsigned int)((int)((unsigned int)(v875 + 68) >> 2)) >> 1))))) >> 31))) & 104)))));
  v976[11] = v1072;
  int * v978 = v869->regs;
  v978[11] = v975;
  struct StateT * v980 = slot_16(v869);
  return v980;
}

struct StateT * slot_9(struct StateT * v552) {
  int v553 = v552->timer;
  int v564 = v553 + 1;
  v552->timer = v564;
  int * v555 = v552->reg_ready;
  int v556 = v555[11];
  int * v557 = v552->regs;
  int v558 = v557[11];
  int v568 = (v556 + ((v553 - v556) & (~((v553 - v556) >> 31)))) + 1;
  v555[11] = v568;
  int * v560 = v552->regs;
  int v570 = v558 + 4;
  v560[11] = v570;
  struct StateT * v562 = slot_10(v552);
  return v562;
}

struct StateT * slot_11(struct StateT * v596) {
  int v597 = v596->timer;
  int v608 = v597 + 1;
  v596->timer = v608;
  int * v599 = v596->reg_ready;
  int v600 = v599[10];
  int * v601 = v596->regs;
  int v602 = v601[10];
  int v612 = (v600 + ((v597 - v600) & (~((v597 - v600) >> 31)))) + 1;
  v599[10] = v612;
  int * v604 = v596->regs;
  int v614 = v602 << 29;
  v604[10] = v614;
  struct StateT * v606 = slot_12(v596);
  return v606;
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