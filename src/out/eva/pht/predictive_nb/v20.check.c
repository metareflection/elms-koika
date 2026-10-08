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
struct StateT * slot_21(struct StateT * v1658);
struct StateT * slot_3(struct StateT * v233);
struct StateT * snippet(struct StateT * v0);
struct StateT * slot_10(struct StateT * v573);
struct StateT * slot_1(struct StateT * v18);
struct StateT * slot_8(struct StateT * v536);
struct StateT * slot_19(struct StateT * v1339);
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
  bool v1224 = (v1103 ^ -2147483648) >= (v1104 ^ -2147483648);
  struct StateT * v1219;
  if (v1224) {
    int v1105 = v1101->timer;
    int v1225 = v1105 + 15;
    v1101->timer = v1225;
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
    v1119[0] = v1120;
    int * v1122 = v1101->reg_ready;
    int v1123 = v1101->timer;
    v1122[1] = v1123;
    int * v1125 = v1101->reg_ready;
    int v1126 = v1101->timer;
    v1125[2] = v1126;
    int * v1128 = v1101->reg_ready;
    int v1129 = v1101->timer;
    v1128[3] = v1129;
    int * v1131 = v1101->reg_ready;
    int v1132 = v1101->timer;
    v1131[4] = v1132;
    int * v1134 = v1101->reg_ready;
    int v1135 = v1101->timer;
    v1134[5] = v1135;
    int * v1137 = v1101->reg_ready;
    int v1138 = v1101->timer;
    v1137[6] = v1138;
    int * v1140 = v1101->reg_ready;
    int v1141 = v1101->timer;
    v1140[7] = v1141;
    int * v1143 = v1101->reg_ready;
    int v1144 = v1101->timer;
    v1143[8] = v1144;
    int * v1146 = v1101->reg_ready;
    int v1147 = v1101->timer;
    v1146[9] = v1147;
    int * v1149 = v1101->reg_ready;
    int v1150 = v1101->timer;
    v1149[10] = v1150;
    int * v1152 = v1101->reg_ready;
    int v1153 = v1101->timer;
    v1152[11] = v1153;
    int * v1155 = v1101->reg_ready;
    int v1156 = v1101->timer;
    v1155[12] = v1156;
    int * v1158 = v1101->reg_ready;
    int v1159 = v1101->timer;
    v1158[13] = v1159;
    int * v1161 = v1101->reg_ready;
    int v1162 = v1101->timer;
    v1161[14] = v1162;
    int * v1164 = v1101->reg_ready;
    int v1165 = v1101->timer;
    v1164[15] = v1165;
    int * v1167 = v1101->reg_ready;
    int v1168 = v1101->timer;
    v1167[16] = v1168;
    int * v1170 = v1101->reg_ready;
    int v1171 = v1101->timer;
    v1170[17] = v1171;
    int * v1173 = v1101->reg_ready;
    int v1174 = v1101->timer;
    v1173[18] = v1174;
    int * v1176 = v1101->reg_ready;
    int v1177 = v1101->timer;
    v1176[19] = v1177;
    int * v1179 = v1101->reg_ready;
    int v1180 = v1101->timer;
    v1179[20] = v1180;
    int * v1182 = v1101->reg_ready;
    int v1183 = v1101->timer;
    v1182[21] = v1183;
    int * v1185 = v1101->reg_ready;
    int v1186 = v1101->timer;
    v1185[22] = v1186;
    int * v1188 = v1101->reg_ready;
    int v1189 = v1101->timer;
    v1188[23] = v1189;
    int * v1191 = v1101->reg_ready;
    int v1192 = v1101->timer;
    v1191[24] = v1192;
    int * v1194 = v1101->reg_ready;
    int v1195 = v1101->timer;
    v1194[25] = v1195;
    int * v1197 = v1101->reg_ready;
    int v1198 = v1101->timer;
    v1197[26] = v1198;
    int * v1200 = v1101->reg_ready;
    int v1201 = v1101->timer;
    v1200[27] = v1201;
    int * v1203 = v1101->reg_ready;
    int v1204 = v1101->timer;
    v1203[28] = v1204;
    int * v1206 = v1101->reg_ready;
    int v1207 = v1101->timer;
    v1206[29] = v1207;
    int * v1209 = v1101->reg_ready;
    int v1210 = v1101->timer;
    v1209[30] = v1210;
    int * v1212 = v1101->reg_ready;
    int v1213 = v1101->timer;
    v1212[31] = v1213;
    struct StateT * v1215 = slot_21(v1101);
    v1219 = v1215;
  } else {
    struct StateT * v1217 = slot_19(v1101);
    v1219 = v1217;
  }
  return v1219;
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

struct StateT * slot_21(struct StateT * v1658) {
  int v1659 = v1658->timer;
  int v1662 = v1659 + 1;
  v1658->timer = v1662;
  return v1658;
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
  int v1663 = v1->timer;
  int * v1664 = v1->reg_ready;
  int v1665 = v1664[0];
  int v1796 = v1665 + ((v1663 - v1665) & (~((v1663 - v1665) >> 31)));
  v1->timer = v1796;
  int v1667 = v1->timer;
  int * v1668 = v1->reg_ready;
  int v1669 = v1668[1];
  int v1799 = v1669 + ((v1667 - v1669) & (~((v1667 - v1669) >> 31)));
  v1->timer = v1799;
  int v1671 = v1->timer;
  int * v1672 = v1->reg_ready;
  int v1673 = v1672[2];
  int v1802 = v1673 + ((v1671 - v1673) & (~((v1671 - v1673) >> 31)));
  v1->timer = v1802;
  int v1675 = v1->timer;
  int * v1676 = v1->reg_ready;
  int v1677 = v1676[3];
  int v1805 = v1677 + ((v1675 - v1677) & (~((v1675 - v1677) >> 31)));
  v1->timer = v1805;
  int v1679 = v1->timer;
  int * v1680 = v1->reg_ready;
  int v1681 = v1680[4];
  int v1808 = v1681 + ((v1679 - v1681) & (~((v1679 - v1681) >> 31)));
  v1->timer = v1808;
  int v1683 = v1->timer;
  int * v1684 = v1->reg_ready;
  int v1685 = v1684[5];
  int v1811 = v1685 + ((v1683 - v1685) & (~((v1683 - v1685) >> 31)));
  v1->timer = v1811;
  int v1687 = v1->timer;
  int * v1688 = v1->reg_ready;
  int v1689 = v1688[6];
  int v1814 = v1689 + ((v1687 - v1689) & (~((v1687 - v1689) >> 31)));
  v1->timer = v1814;
  int v1691 = v1->timer;
  int * v1692 = v1->reg_ready;
  int v1693 = v1692[7];
  int v1817 = v1693 + ((v1691 - v1693) & (~((v1691 - v1693) >> 31)));
  v1->timer = v1817;
  int v1695 = v1->timer;
  int * v1696 = v1->reg_ready;
  int v1697 = v1696[8];
  int v1820 = v1697 + ((v1695 - v1697) & (~((v1695 - v1697) >> 31)));
  v1->timer = v1820;
  int v1699 = v1->timer;
  int * v1700 = v1->reg_ready;
  int v1701 = v1700[9];
  int v1823 = v1701 + ((v1699 - v1701) & (~((v1699 - v1701) >> 31)));
  v1->timer = v1823;
  int v1703 = v1->timer;
  int * v1704 = v1->reg_ready;
  int v1705 = v1704[10];
  int v1826 = v1705 + ((v1703 - v1705) & (~((v1703 - v1705) >> 31)));
  v1->timer = v1826;
  int v1707 = v1->timer;
  int * v1708 = v1->reg_ready;
  int v1709 = v1708[11];
  int v1829 = v1709 + ((v1707 - v1709) & (~((v1707 - v1709) >> 31)));
  v1->timer = v1829;
  int v1711 = v1->timer;
  int * v1712 = v1->reg_ready;
  int v1713 = v1712[12];
  int v1832 = v1713 + ((v1711 - v1713) & (~((v1711 - v1713) >> 31)));
  v1->timer = v1832;
  int v1715 = v1->timer;
  int * v1716 = v1->reg_ready;
  int v1717 = v1716[13];
  int v1835 = v1717 + ((v1715 - v1717) & (~((v1715 - v1717) >> 31)));
  v1->timer = v1835;
  int v1719 = v1->timer;
  int * v1720 = v1->reg_ready;
  int v1721 = v1720[14];
  int v1838 = v1721 + ((v1719 - v1721) & (~((v1719 - v1721) >> 31)));
  v1->timer = v1838;
  int v1723 = v1->timer;
  int * v1724 = v1->reg_ready;
  int v1725 = v1724[15];
  int v1841 = v1725 + ((v1723 - v1725) & (~((v1723 - v1725) >> 31)));
  v1->timer = v1841;
  int v1727 = v1->timer;
  int * v1728 = v1->reg_ready;
  int v1729 = v1728[16];
  int v1844 = v1729 + ((v1727 - v1729) & (~((v1727 - v1729) >> 31)));
  v1->timer = v1844;
  int v1731 = v1->timer;
  int * v1732 = v1->reg_ready;
  int v1733 = v1732[17];
  int v1847 = v1733 + ((v1731 - v1733) & (~((v1731 - v1733) >> 31)));
  v1->timer = v1847;
  int v1735 = v1->timer;
  int * v1736 = v1->reg_ready;
  int v1737 = v1736[18];
  int v1850 = v1737 + ((v1735 - v1737) & (~((v1735 - v1737) >> 31)));
  v1->timer = v1850;
  int v1739 = v1->timer;
  int * v1740 = v1->reg_ready;
  int v1741 = v1740[19];
  int v1853 = v1741 + ((v1739 - v1741) & (~((v1739 - v1741) >> 31)));
  v1->timer = v1853;
  int v1743 = v1->timer;
  int * v1744 = v1->reg_ready;
  int v1745 = v1744[20];
  int v1856 = v1745 + ((v1743 - v1745) & (~((v1743 - v1745) >> 31)));
  v1->timer = v1856;
  int v1747 = v1->timer;
  int * v1748 = v1->reg_ready;
  int v1749 = v1748[21];
  int v1859 = v1749 + ((v1747 - v1749) & (~((v1747 - v1749) >> 31)));
  v1->timer = v1859;
  int v1751 = v1->timer;
  int * v1752 = v1->reg_ready;
  int v1753 = v1752[22];
  int v1862 = v1753 + ((v1751 - v1753) & (~((v1751 - v1753) >> 31)));
  v1->timer = v1862;
  int v1755 = v1->timer;
  int * v1756 = v1->reg_ready;
  int v1757 = v1756[23];
  int v1865 = v1757 + ((v1755 - v1757) & (~((v1755 - v1757) >> 31)));
  v1->timer = v1865;
  int v1759 = v1->timer;
  int * v1760 = v1->reg_ready;
  int v1761 = v1760[24];
  int v1868 = v1761 + ((v1759 - v1761) & (~((v1759 - v1761) >> 31)));
  v1->timer = v1868;
  int v1763 = v1->timer;
  int * v1764 = v1->reg_ready;
  int v1765 = v1764[25];
  int v1871 = v1765 + ((v1763 - v1765) & (~((v1763 - v1765) >> 31)));
  v1->timer = v1871;
  int v1767 = v1->timer;
  int * v1768 = v1->reg_ready;
  int v1769 = v1768[26];
  int v1874 = v1769 + ((v1767 - v1769) & (~((v1767 - v1769) >> 31)));
  v1->timer = v1874;
  int v1771 = v1->timer;
  int * v1772 = v1->reg_ready;
  int v1773 = v1772[27];
  int v1877 = v1773 + ((v1771 - v1773) & (~((v1771 - v1773) >> 31)));
  v1->timer = v1877;
  int v1775 = v1->timer;
  int * v1776 = v1->reg_ready;
  int v1777 = v1776[28];
  int v1880 = v1777 + ((v1775 - v1777) & (~((v1775 - v1777) >> 31)));
  v1->timer = v1880;
  int v1779 = v1->timer;
  int * v1780 = v1->reg_ready;
  int v1781 = v1780[29];
  int v1883 = v1781 + ((v1779 - v1781) & (~((v1779 - v1781) >> 31)));
  v1->timer = v1883;
  int v1783 = v1->timer;
  int * v1784 = v1->reg_ready;
  int v1785 = v1784[30];
  int v1886 = v1785 + ((v1783 - v1785) & (~((v1783 - v1785) >> 31)));
  v1->timer = v1886;
  int v1787 = v1->timer;
  int * v1788 = v1->reg_ready;
  int v1789 = v1788[31];
  int v1889 = v1789 + ((v1787 - v1789) & (~((v1787 - v1789) >> 31)));
  v1->timer = v1889;
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

struct StateT * slot_19(struct StateT * v1339) {
  int v1340 = v1339->timer;
  int v1513 = v1340 + 1;
  v1339->timer = v1513;
  int * v1342 = v1339->reg_ready;
  int * v1344 = v1339->regs;
  int v1345 = v1344[12];
  int v1347 = v1344[10];
  int * v1348 = v1339->cache_tags;
  int v1519 = (((int)((unsigned int)((int)((unsigned int)(v1345 + 68) >> 2)) >> 1)) & 1) * 2;
  int v1349 = v1348[v1519];
  int v1520 = ((((int)((unsigned int)((int)((unsigned int)(v1345 + 68) >> 2)) >> 1)) & 1) * 2) + 1;
  int v1350 = v1348[v1520];
  int v1521 = 4 + ((((int)((unsigned int)((int)((unsigned int)(v1345 + 68) >> 2)) >> 1)) & 3) * 2);
  int v1351 = v1348[v1521];
  int v1522 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v1345 + 68) >> 2)) >> 1)) & 3) * 2)) + 1;
  int v1352 = v1348[v1522];
  int v1353 = v1339->timer;
  int v1523 = v1353 + ((100 ^ (((~(((v1351 ^ ((int)((unsigned int)((int)((unsigned int)(v1345 + 68) >> 2)) >> 1))) | (-(v1351 ^ ((int)((unsigned int)((int)((unsigned int)(v1345 + 68) >> 2)) >> 1))))) >> 31)) | (~(((v1352 ^ ((int)((unsigned int)((int)((unsigned int)(v1345 + 68) >> 2)) >> 1))) | (-(v1352 ^ ((int)((unsigned int)((int)((unsigned int)(v1345 + 68) >> 2)) >> 1))))) >> 31))) & 104)) ^ (((~(((v1349 ^ ((int)((unsigned int)((int)((unsigned int)(v1345 + 68) >> 2)) >> 1))) | (-(v1349 ^ ((int)((unsigned int)((int)((unsigned int)(v1345 + 68) >> 2)) >> 1))))) >> 31)) | (~(((v1350 ^ ((int)((unsigned int)((int)((unsigned int)(v1345 + 68) >> 2)) >> 1))) | (-(v1350 ^ ((int)((unsigned int)((int)((unsigned int)(v1345 + 68) >> 2)) >> 1))))) >> 31))) & (1 ^ (100 ^ (((~(((v1351 ^ ((int)((unsigned int)((int)((unsigned int)(v1345 + 68) >> 2)) >> 1))) | (-(v1351 ^ ((int)((unsigned int)((int)((unsigned int)(v1345 + 68) >> 2)) >> 1))))) >> 31)) | (~(((v1352 ^ ((int)((unsigned int)((int)((unsigned int)(v1345 + 68) >> 2)) >> 1))) | (-(v1352 ^ ((int)((unsigned int)((int)((unsigned int)(v1345 + 68) >> 2)) >> 1))))) >> 31))) & 104)))));
  v1339->timer = v1523;
  bool v1524 = !(((~(((v1349 ^ ((int)((unsigned int)((int)((unsigned int)(v1345 + 68) >> 2)) >> 1))) | (-(v1349 ^ ((int)((unsigned int)((int)((unsigned int)(v1345 + 68) >> 2)) >> 1))))) >> 31)) | (~(((v1350 ^ ((int)((unsigned int)((int)((unsigned int)(v1345 + 68) >> 2)) >> 1))) | (-(v1350 ^ ((int)((unsigned int)((int)((unsigned int)(v1345 + 68) >> 2)) >> 1))))) >> 31))) == 0);
  int v1447;
  if (v1524) {
    int * v1355 = v1339->cache_age;
    int v1526 = ((((int)((unsigned int)((int)((unsigned int)(v1345 + 68) >> 2)) >> 1)) & 1) * 2) + ((~(((v1350 ^ ((int)((unsigned int)((int)((unsigned int)(v1345 + 68) >> 2)) >> 1))) | (-(v1350 ^ ((int)((unsigned int)((int)((unsigned int)(v1345 + 68) >> 2)) >> 1))))) >> 31)) & 1);
    int v1356 = v1355[v1526];
    int v1357 = v1355[v1519];
    int v1527 = v1357 + ((int)((unsigned int)(v1357 - v1356) >> 31));
    v1355[v1519] = v1527;
    int * v1359 = v1339->cache_age;
    int v1360 = v1359[v1520];
    int v1529 = v1360 + ((int)((unsigned int)(v1360 - v1356) >> 31));
    v1359[v1520] = v1529;
    int * v1362 = v1339->cache_age;
    v1362[v1526] = 0;
    v1447 = v1526;
  } else {
    int * v1365 = v1339->cache_age;
    int v1533 = (((int)((unsigned int)((int)((unsigned int)(v1345 + 68) >> 2)) >> 1)) & 1) * 2;
    int v1366 = v1365[v1533];
    int * v1367 = v1339->cache_tags;
    int v1368 = v1367[v1533];
    int v1369 = v1365[v1520];
    int v1370 = v1367[v1520];
    bool v1535 = !(((~(((v1351 ^ ((int)((unsigned int)((int)((unsigned int)(v1345 + 68) >> 2)) >> 1))) | (-(v1351 ^ ((int)((unsigned int)((int)((unsigned int)(v1345 + 68) >> 2)) >> 1))))) >> 31)) | (~(((v1352 ^ ((int)((unsigned int)((int)((unsigned int)(v1345 + 68) >> 2)) >> 1))) | (-(v1352 ^ ((int)((unsigned int)((int)((unsigned int)(v1345 + 68) >> 2)) >> 1))))) >> 31))) == 0);
    int v1424;
    if (v1535) {
      int * v1371 = v1339->cache_age;
      int v1537 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v1345 + 68) >> 2)) >> 1)) & 3) * 2)) + ((~(((v1352 ^ ((int)((unsigned int)((int)((unsigned int)(v1345 + 68) >> 2)) >> 1))) | (-(v1352 ^ ((int)((unsigned int)((int)((unsigned int)(v1345 + 68) >> 2)) >> 1))))) >> 31)) & 1);
      int v1372 = v1371[v1537];
      int v1373 = v1371[v1521];
      int v1538 = v1373 + ((int)((unsigned int)(v1373 - v1372) >> 31));
      v1371[v1521] = v1538;
      int * v1375 = v1339->cache_age;
      int v1376 = v1375[v1522];
      int v1540 = v1376 + ((int)((unsigned int)(v1376 - v1372) >> 31));
      v1375[v1522] = v1540;
      int * v1378 = v1339->cache_age;
      v1378[v1537] = 0;
      v1424 = v1537;
    } else {
      int * v1381 = v1339->cache_age;
      int v1544 = 4 + ((((int)((unsigned int)((int)((unsigned int)(v1345 + 68) >> 2)) >> 1)) & 3) * 2);
      int v1382 = v1381[v1544];
      int * v1383 = v1339->cache_tags;
      int v1384 = v1383[v1544];
      int v1385 = v1381[v1522];
      int v1386 = v1383[v1522];
      int * v1387 = v1339->cache_dirty;
      int v1547 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v1345 + 68) >> 2)) >> 1)) & 3) * 2)) + ((((v1382 + ((~(((v1384 ^ -1) | (-(v1384 ^ -1))) >> 31)) & 2)) - (v1385 + ((~(((v1386 ^ -1) | (-(v1386 ^ -1))) >> 31)) & 2))) >> 31) & 1);
      int v1388 = v1387[v1547];
      bool v1548 = !(v1388 == 0);
      if (v1548) {
        int * v1389 = v1339->cache_tags;
        int v1390 = v1389[v1547];
        int * v1391 = v1339->cache_vals;
        int v1551 = ((4 + ((((int)((unsigned int)((int)((unsigned int)(v1345 + 68) >> 2)) >> 1)) & 3) * 2)) + ((((v1382 + ((~(((v1384 ^ -1) | (-(v1384 ^ -1))) >> 31)) & 2)) - (v1385 + ((~(((v1386 ^ -1) | (-(v1386 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
        int v1392 = v1391[v1551];
        int v1552 = (((4 + ((((int)((unsigned int)((int)((unsigned int)(v1345 + 68) >> 2)) >> 1)) & 3) * 2)) + ((((v1382 + ((~(((v1384 ^ -1) | (-(v1384 ^ -1))) >> 31)) & 2)) - (v1385 + ((~(((v1386 ^ -1) | (-(v1386 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
        int v1393 = v1391[v1552];
        int * v1394 = v1339->mem;
        int v1554 = v1390 * 2;
        v1394[v1554] = v1392;
        int * v1396 = v1339->mem;
        int v1557 = (v1390 * 2) + 1;
        v1396[v1557] = v1393;
        ;
      } else {
        ;
      }
      int * v1401 = v1339->mem;
      int v1562 = ((int)((unsigned int)((int)((unsigned int)(v1345 + 68) >> 2)) >> 1)) * 2;
      int v1402 = v1401[v1562];
      int v1563 = (((int)((unsigned int)((int)((unsigned int)(v1345 + 68) >> 2)) >> 1)) * 2) + 1;
      int v1403 = v1401[v1563];
      int * v1404 = v1339->cache_vals;
      int v1565 = ((4 + ((((int)((unsigned int)((int)((unsigned int)(v1345 + 68) >> 2)) >> 1)) & 3) * 2)) + ((((v1382 + ((~(((v1384 ^ -1) | (-(v1384 ^ -1))) >> 31)) & 2)) - (v1385 + ((~(((v1386 ^ -1) | (-(v1386 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
      v1404[v1565] = v1402;
      int * v1406 = v1339->cache_vals;
      int v1568 = (((4 + ((((int)((unsigned int)((int)((unsigned int)(v1345 + 68) >> 2)) >> 1)) & 3) * 2)) + ((((v1382 + ((~(((v1384 ^ -1) | (-(v1384 ^ -1))) >> 31)) & 2)) - (v1385 + ((~(((v1386 ^ -1) | (-(v1386 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
      v1406[v1568] = v1403;
      int * v1408 = v1339->cache_tags;
      int v1571 = (int)((unsigned int)((int)((unsigned int)(v1345 + 68) >> 2)) >> 1);
      v1408[v1547] = v1571;
      int * v1410 = v1339->cache_dirty;
      v1410[v1547] = 0;
      int * v1412 = v1339->cache_age;
      v1412[v1547] = 1;
      int * v1414 = v1339->cache_age;
      int v1415 = v1414[v1547];
      int v1416 = v1414[v1521];
      int v1577 = v1416 + ((int)((unsigned int)(v1416 - v1415) >> 31));
      v1414[v1521] = v1577;
      int * v1418 = v1339->cache_age;
      int v1419 = v1418[v1522];
      int v1579 = v1419 + ((int)((unsigned int)(v1419 - v1415) >> 31));
      v1418[v1522] = v1579;
      int * v1421 = v1339->cache_age;
      v1421[v1547] = 0;
      v1424 = v1547;
    }
    int * v1425 = v1339->cache_vals;
    int v1582 = v1424 * 2;
    int v1426 = v1425[v1582];
    int v1583 = (v1424 * 2) + 1;
    int v1427 = v1425[v1583];
    int v1584 = (((((int)((unsigned int)((int)((unsigned int)(v1345 + 68) >> 2)) >> 1)) & 1) * 2) + ((((v1366 + ((~(((v1368 ^ -1) | (-(v1368 ^ -1))) >> 31)) & 2)) - (v1369 + ((~(((v1370 ^ -1) | (-(v1370 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
    v1425[v1584] = v1426;
    int * v1429 = v1339->cache_vals;
    int v1587 = ((((((int)((unsigned int)((int)((unsigned int)(v1345 + 68) >> 2)) >> 1)) & 1) * 2) + ((((v1366 + ((~(((v1368 ^ -1) | (-(v1368 ^ -1))) >> 31)) & 2)) - (v1369 + ((~(((v1370 ^ -1) | (-(v1370 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
    v1429[v1587] = v1427;
    int * v1431 = v1339->cache_tags;
    int v1590 = ((((int)((unsigned int)((int)((unsigned int)(v1345 + 68) >> 2)) >> 1)) & 1) * 2) + ((((v1366 + ((~(((v1368 ^ -1) | (-(v1368 ^ -1))) >> 31)) & 2)) - (v1369 + ((~(((v1370 ^ -1) | (-(v1370 ^ -1))) >> 31)) & 2))) >> 31) & 1);
    int v1591 = (int)((unsigned int)((int)((unsigned int)(v1345 + 68) >> 2)) >> 1);
    v1431[v1590] = v1591;
    int * v1433 = v1339->cache_dirty;
    v1433[v1590] = 0;
    int * v1435 = v1339->cache_age;
    v1435[v1590] = 1;
    int * v1437 = v1339->cache_age;
    int v1438 = v1437[v1590];
    int v1439 = v1437[v1519];
    int v1597 = v1439 + ((int)((unsigned int)(v1439 - v1438) >> 31));
    v1437[v1519] = v1597;
    int * v1441 = v1339->cache_age;
    int v1442 = v1441[v1520];
    int v1599 = v1442 + ((int)((unsigned int)(v1442 - v1438) >> 31));
    v1441[v1520] = v1599;
    int * v1444 = v1339->cache_age;
    v1444[v1590] = 0;
    v1447 = v1590;
  }
  int * v1448 = v1339->cache_vals;
  int v1602 = (v1447 * 2) + (((int)((unsigned int)(v1345 + 68) >> 2)) & 1);
  v1448[v1602] = v1347;
  int * v1450 = v1339->cache_tags;
  int v1451 = v1450[v1521];
  int v1452 = v1450[v1522];
  bool v1605 = !(((~(((v1451 ^ ((int)((unsigned int)((int)((unsigned int)(v1345 + 68) >> 2)) >> 1))) | (-(v1451 ^ ((int)((unsigned int)((int)((unsigned int)(v1345 + 68) >> 2)) >> 1))))) >> 31)) | (~(((v1452 ^ ((int)((unsigned int)((int)((unsigned int)(v1345 + 68) >> 2)) >> 1))) | (-(v1452 ^ ((int)((unsigned int)((int)((unsigned int)(v1345 + 68) >> 2)) >> 1))))) >> 31))) == 0);
  int v1506;
  if (v1605) {
    int * v1453 = v1339->cache_age;
    int v1607 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v1345 + 68) >> 2)) >> 1)) & 3) * 2)) + ((~(((v1452 ^ ((int)((unsigned int)((int)((unsigned int)(v1345 + 68) >> 2)) >> 1))) | (-(v1452 ^ ((int)((unsigned int)((int)((unsigned int)(v1345 + 68) >> 2)) >> 1))))) >> 31)) & 1);
    int v1454 = v1453[v1607];
    int v1455 = v1453[v1521];
    int v1608 = v1455 + ((int)((unsigned int)(v1455 - v1454) >> 31));
    v1453[v1521] = v1608;
    int * v1457 = v1339->cache_age;
    int v1458 = v1457[v1522];
    int v1610 = v1458 + ((int)((unsigned int)(v1458 - v1454) >> 31));
    v1457[v1522] = v1610;
    int * v1460 = v1339->cache_age;
    v1460[v1607] = 0;
    v1506 = v1607;
  } else {
    int * v1463 = v1339->cache_age;
    int v1614 = 4 + ((((int)((unsigned int)((int)((unsigned int)(v1345 + 68) >> 2)) >> 1)) & 3) * 2);
    int v1464 = v1463[v1614];
    int * v1465 = v1339->cache_tags;
    int v1466 = v1465[v1614];
    int v1467 = v1463[v1522];
    int v1468 = v1465[v1522];
    int * v1469 = v1339->cache_dirty;
    int v1617 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v1345 + 68) >> 2)) >> 1)) & 3) * 2)) + ((((v1464 + ((~(((v1466 ^ -1) | (-(v1466 ^ -1))) >> 31)) & 2)) - (v1467 + ((~(((v1468 ^ -1) | (-(v1468 ^ -1))) >> 31)) & 2))) >> 31) & 1);
    int v1470 = v1469[v1617];
    bool v1618 = !(v1470 == 0);
    if (v1618) {
      int * v1471 = v1339->cache_tags;
      int v1472 = v1471[v1617];
      int * v1473 = v1339->cache_vals;
      int v1621 = ((4 + ((((int)((unsigned int)((int)((unsigned int)(v1345 + 68) >> 2)) >> 1)) & 3) * 2)) + ((((v1464 + ((~(((v1466 ^ -1) | (-(v1466 ^ -1))) >> 31)) & 2)) - (v1467 + ((~(((v1468 ^ -1) | (-(v1468 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
      int v1474 = v1473[v1621];
      int v1622 = (((4 + ((((int)((unsigned int)((int)((unsigned int)(v1345 + 68) >> 2)) >> 1)) & 3) * 2)) + ((((v1464 + ((~(((v1466 ^ -1) | (-(v1466 ^ -1))) >> 31)) & 2)) - (v1467 + ((~(((v1468 ^ -1) | (-(v1468 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
      int v1475 = v1473[v1622];
      int * v1476 = v1339->mem;
      int v1624 = v1472 * 2;
      v1476[v1624] = v1474;
      int * v1478 = v1339->mem;
      int v1627 = (v1472 * 2) + 1;
      v1478[v1627] = v1475;
      ;
    } else {
      ;
    }
    int * v1483 = v1339->mem;
    int v1632 = ((int)((unsigned int)((int)((unsigned int)(v1345 + 68) >> 2)) >> 1)) * 2;
    int v1484 = v1483[v1632];
    int v1633 = (((int)((unsigned int)((int)((unsigned int)(v1345 + 68) >> 2)) >> 1)) * 2) + 1;
    int v1485 = v1483[v1633];
    int * v1486 = v1339->cache_vals;
    int v1635 = ((4 + ((((int)((unsigned int)((int)((unsigned int)(v1345 + 68) >> 2)) >> 1)) & 3) * 2)) + ((((v1464 + ((~(((v1466 ^ -1) | (-(v1466 ^ -1))) >> 31)) & 2)) - (v1467 + ((~(((v1468 ^ -1) | (-(v1468 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
    v1486[v1635] = v1484;
    int * v1488 = v1339->cache_vals;
    int v1638 = (((4 + ((((int)((unsigned int)((int)((unsigned int)(v1345 + 68) >> 2)) >> 1)) & 3) * 2)) + ((((v1464 + ((~(((v1466 ^ -1) | (-(v1466 ^ -1))) >> 31)) & 2)) - (v1467 + ((~(((v1468 ^ -1) | (-(v1468 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
    v1488[v1638] = v1485;
    int * v1490 = v1339->cache_tags;
    int v1641 = (int)((unsigned int)((int)((unsigned int)(v1345 + 68) >> 2)) >> 1);
    v1490[v1617] = v1641;
    int * v1492 = v1339->cache_dirty;
    v1492[v1617] = 0;
    int * v1494 = v1339->cache_age;
    v1494[v1617] = 1;
    int * v1496 = v1339->cache_age;
    int v1497 = v1496[v1617];
    int v1498 = v1496[v1521];
    int v1647 = v1498 + ((int)((unsigned int)(v1498 - v1497) >> 31));
    v1496[v1521] = v1647;
    int * v1500 = v1339->cache_age;
    int v1501 = v1500[v1522];
    int v1649 = v1501 + ((int)((unsigned int)(v1501 - v1497) >> 31));
    v1500[v1522] = v1649;
    int * v1503 = v1339->cache_age;
    v1503[v1617] = 0;
    v1506 = v1617;
  }
  int * v1507 = v1339->cache_vals;
  int v1652 = (v1506 * 2) + (((int)((unsigned int)(v1345 + 68) >> 2)) & 1);
  v1507[v1652] = v1347;
  int * v1509 = v1339->cache_dirty;
  v1509[v1506] = 1;
  struct StateT * v1511 = slot_21(v1339);
  return v1511;
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