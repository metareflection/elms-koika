// verify: leak widened (the program is clean; Eva cannot prove it) [unroll 65]
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

struct StateT * snippet(struct StateT * v0);
struct StateT * slot_1(struct StateT * v195);
struct StateT * slot_6(struct StateT * v640);
struct StateT * slot_5(struct StateT * v448);
struct StateT * slot_4(struct StateT * v259);
struct StateT * slot_2(struct StateT * v217);
struct StateT * slot_7(struct StateT * v848);
struct StateT * slot_3(struct StateT * v238);
struct StateT * slot_0(struct StateT * v2);
struct StateT * snippet(struct StateT * v0) {
  struct StateT * v1 = slot_0(v0);
  int v1034 = v1->timer;
  int * v1035 = v1->reg_ready;
  int v1036 = v1035[0];
  int v1167 = v1036 + ((v1034 - v1036) & (~((v1034 - v1036) >> 31)));
  v1->timer = v1167;
  int v1038 = v1->timer;
  int * v1039 = v1->reg_ready;
  int v1040 = v1039[1];
  int v1170 = v1040 + ((v1038 - v1040) & (~((v1038 - v1040) >> 31)));
  v1->timer = v1170;
  int v1042 = v1->timer;
  int * v1043 = v1->reg_ready;
  int v1044 = v1043[2];
  int v1173 = v1044 + ((v1042 - v1044) & (~((v1042 - v1044) >> 31)));
  v1->timer = v1173;
  int v1046 = v1->timer;
  int * v1047 = v1->reg_ready;
  int v1048 = v1047[3];
  int v1176 = v1048 + ((v1046 - v1048) & (~((v1046 - v1048) >> 31)));
  v1->timer = v1176;
  int v1050 = v1->timer;
  int * v1051 = v1->reg_ready;
  int v1052 = v1051[4];
  int v1179 = v1052 + ((v1050 - v1052) & (~((v1050 - v1052) >> 31)));
  v1->timer = v1179;
  int v1054 = v1->timer;
  int * v1055 = v1->reg_ready;
  int v1056 = v1055[5];
  int v1182 = v1056 + ((v1054 - v1056) & (~((v1054 - v1056) >> 31)));
  v1->timer = v1182;
  int v1058 = v1->timer;
  int * v1059 = v1->reg_ready;
  int v1060 = v1059[6];
  int v1185 = v1060 + ((v1058 - v1060) & (~((v1058 - v1060) >> 31)));
  v1->timer = v1185;
  int v1062 = v1->timer;
  int * v1063 = v1->reg_ready;
  int v1064 = v1063[7];
  int v1188 = v1064 + ((v1062 - v1064) & (~((v1062 - v1064) >> 31)));
  v1->timer = v1188;
  int v1066 = v1->timer;
  int * v1067 = v1->reg_ready;
  int v1068 = v1067[8];
  int v1191 = v1068 + ((v1066 - v1068) & (~((v1066 - v1068) >> 31)));
  v1->timer = v1191;
  int v1070 = v1->timer;
  int * v1071 = v1->reg_ready;
  int v1072 = v1071[9];
  int v1194 = v1072 + ((v1070 - v1072) & (~((v1070 - v1072) >> 31)));
  v1->timer = v1194;
  int v1074 = v1->timer;
  int * v1075 = v1->reg_ready;
  int v1076 = v1075[10];
  int v1197 = v1076 + ((v1074 - v1076) & (~((v1074 - v1076) >> 31)));
  v1->timer = v1197;
  int v1078 = v1->timer;
  int * v1079 = v1->reg_ready;
  int v1080 = v1079[11];
  int v1200 = v1080 + ((v1078 - v1080) & (~((v1078 - v1080) >> 31)));
  v1->timer = v1200;
  int v1082 = v1->timer;
  int * v1083 = v1->reg_ready;
  int v1084 = v1083[12];
  int v1203 = v1084 + ((v1082 - v1084) & (~((v1082 - v1084) >> 31)));
  v1->timer = v1203;
  int v1086 = v1->timer;
  int * v1087 = v1->reg_ready;
  int v1088 = v1087[13];
  int v1206 = v1088 + ((v1086 - v1088) & (~((v1086 - v1088) >> 31)));
  v1->timer = v1206;
  int v1090 = v1->timer;
  int * v1091 = v1->reg_ready;
  int v1092 = v1091[14];
  int v1209 = v1092 + ((v1090 - v1092) & (~((v1090 - v1092) >> 31)));
  v1->timer = v1209;
  int v1094 = v1->timer;
  int * v1095 = v1->reg_ready;
  int v1096 = v1095[15];
  int v1212 = v1096 + ((v1094 - v1096) & (~((v1094 - v1096) >> 31)));
  v1->timer = v1212;
  int v1098 = v1->timer;
  int * v1099 = v1->reg_ready;
  int v1100 = v1099[16];
  int v1215 = v1100 + ((v1098 - v1100) & (~((v1098 - v1100) >> 31)));
  v1->timer = v1215;
  int v1102 = v1->timer;
  int * v1103 = v1->reg_ready;
  int v1104 = v1103[17];
  int v1218 = v1104 + ((v1102 - v1104) & (~((v1102 - v1104) >> 31)));
  v1->timer = v1218;
  int v1106 = v1->timer;
  int * v1107 = v1->reg_ready;
  int v1108 = v1107[18];
  int v1221 = v1108 + ((v1106 - v1108) & (~((v1106 - v1108) >> 31)));
  v1->timer = v1221;
  int v1110 = v1->timer;
  int * v1111 = v1->reg_ready;
  int v1112 = v1111[19];
  int v1224 = v1112 + ((v1110 - v1112) & (~((v1110 - v1112) >> 31)));
  v1->timer = v1224;
  int v1114 = v1->timer;
  int * v1115 = v1->reg_ready;
  int v1116 = v1115[20];
  int v1227 = v1116 + ((v1114 - v1116) & (~((v1114 - v1116) >> 31)));
  v1->timer = v1227;
  int v1118 = v1->timer;
  int * v1119 = v1->reg_ready;
  int v1120 = v1119[21];
  int v1230 = v1120 + ((v1118 - v1120) & (~((v1118 - v1120) >> 31)));
  v1->timer = v1230;
  int v1122 = v1->timer;
  int * v1123 = v1->reg_ready;
  int v1124 = v1123[22];
  int v1233 = v1124 + ((v1122 - v1124) & (~((v1122 - v1124) >> 31)));
  v1->timer = v1233;
  int v1126 = v1->timer;
  int * v1127 = v1->reg_ready;
  int v1128 = v1127[23];
  int v1236 = v1128 + ((v1126 - v1128) & (~((v1126 - v1128) >> 31)));
  v1->timer = v1236;
  int v1130 = v1->timer;
  int * v1131 = v1->reg_ready;
  int v1132 = v1131[24];
  int v1239 = v1132 + ((v1130 - v1132) & (~((v1130 - v1132) >> 31)));
  v1->timer = v1239;
  int v1134 = v1->timer;
  int * v1135 = v1->reg_ready;
  int v1136 = v1135[25];
  int v1242 = v1136 + ((v1134 - v1136) & (~((v1134 - v1136) >> 31)));
  v1->timer = v1242;
  int v1138 = v1->timer;
  int * v1139 = v1->reg_ready;
  int v1140 = v1139[26];
  int v1245 = v1140 + ((v1138 - v1140) & (~((v1138 - v1140) >> 31)));
  v1->timer = v1245;
  int v1142 = v1->timer;
  int * v1143 = v1->reg_ready;
  int v1144 = v1143[27];
  int v1248 = v1144 + ((v1142 - v1144) & (~((v1142 - v1144) >> 31)));
  v1->timer = v1248;
  int v1146 = v1->timer;
  int * v1147 = v1->reg_ready;
  int v1148 = v1147[28];
  int v1251 = v1148 + ((v1146 - v1148) & (~((v1146 - v1148) >> 31)));
  v1->timer = v1251;
  int v1150 = v1->timer;
  int * v1151 = v1->reg_ready;
  int v1152 = v1151[29];
  int v1254 = v1152 + ((v1150 - v1152) & (~((v1150 - v1152) >> 31)));
  v1->timer = v1254;
  int v1154 = v1->timer;
  int * v1155 = v1->reg_ready;
  int v1156 = v1155[30];
  int v1257 = v1156 + ((v1154 - v1156) & (~((v1154 - v1156) >> 31)));
  v1->timer = v1257;
  int v1158 = v1->timer;
  int * v1159 = v1->reg_ready;
  int v1160 = v1159[31];
  int v1260 = v1160 + ((v1158 - v1160) & (~((v1158 - v1160) >> 31)));
  v1->timer = v1260;
  return v1;
}

struct StateT * slot_1(struct StateT * v195) {
  int v196 = v195->timer;
  int v207 = v196 + 1;
  v195->timer = v207;
  int * v198 = v195->reg_ready;
  int v199 = v198[5];
  int * v200 = v195->regs;
  int v201 = v200[5];
  int v212 = (v199 + ((v196 - v199) & (~((v196 - v199) >> 31)))) + 1;
  v198[6] = v212;
  int * v203 = v195->regs;
  int v214 = v201 & 1;
  v203[6] = v214;
  struct StateT * v205 = slot_2(v195);
  return v205;
}

struct StateT * slot_6(struct StateT * v640) {
  int v641 = v640->timer;
  int v753 = v641 + 1;
  v640->timer = v753;
  int * v643 = v640->reg_ready;
  int v644 = v643[6];
  int * v645 = v640->regs;
  int v646 = v645[6];
  int * v647 = v640->cache_tags;
  int v758 = (((int)((unsigned int)((int)((unsigned int)v646 >> 2)) >> 1)) & 1) * 2;
  int v648 = v647[v758];
  int v759 = ((((int)((unsigned int)((int)((unsigned int)v646 >> 2)) >> 1)) & 1) * 2) + 1;
  int v649 = v647[v759];
  int v760 = 4 + ((((int)((unsigned int)((int)((unsigned int)v646 >> 2)) >> 1)) & 3) * 2);
  int v650 = v647[v760];
  int v761 = (4 + ((((int)((unsigned int)((int)((unsigned int)v646 >> 2)) >> 1)) & 3) * 2)) + 1;
  int v651 = v647[v761];
  int * v652 = v640->cache_vals;
  bool v762 = !(((~(((v648 ^ ((int)((unsigned int)((int)((unsigned int)v646 >> 2)) >> 1))) | (-(v648 ^ ((int)((unsigned int)((int)((unsigned int)v646 >> 2)) >> 1))))) >> 31)) | (~(((v649 ^ ((int)((unsigned int)((int)((unsigned int)v646 >> 2)) >> 1))) | (-(v649 ^ ((int)((unsigned int)((int)((unsigned int)v646 >> 2)) >> 1))))) >> 31))) == 0);
  int v745;
  if (v762) {
    int * v653 = v640->cache_age;
    int v764 = ((((int)((unsigned int)((int)((unsigned int)v646 >> 2)) >> 1)) & 1) * 2) + ((~(((v649 ^ ((int)((unsigned int)((int)((unsigned int)v646 >> 2)) >> 1))) | (-(v649 ^ ((int)((unsigned int)((int)((unsigned int)v646 >> 2)) >> 1))))) >> 31)) & 1);
    int v654 = v653[v764];
    int v655 = v653[v758];
    int v765 = v655 + ((int)((unsigned int)(v655 - v654) >> 31));
    v653[v758] = v765;
    int * v657 = v640->cache_age;
    int v658 = v657[v759];
    int v767 = v658 + ((int)((unsigned int)(v658 - v654) >> 31));
    v657[v759] = v767;
    int * v660 = v640->cache_age;
    v660[v764] = 0;
    v745 = v764;
  } else {
    int * v663 = v640->cache_age;
    int v771 = (((int)((unsigned int)((int)((unsigned int)v646 >> 2)) >> 1)) & 1) * 2;
    int v664 = v663[v771];
    int * v665 = v640->cache_tags;
    int v666 = v665[v771];
    int v667 = v663[v759];
    int v668 = v665[v759];
    bool v773 = !(((~(((v650 ^ ((int)((unsigned int)((int)((unsigned int)v646 >> 2)) >> 1))) | (-(v650 ^ ((int)((unsigned int)((int)((unsigned int)v646 >> 2)) >> 1))))) >> 31)) | (~(((v651 ^ ((int)((unsigned int)((int)((unsigned int)v646 >> 2)) >> 1))) | (-(v651 ^ ((int)((unsigned int)((int)((unsigned int)v646 >> 2)) >> 1))))) >> 31))) == 0);
    int v722;
    if (v773) {
      int * v669 = v640->cache_age;
      int v775 = (4 + ((((int)((unsigned int)((int)((unsigned int)v646 >> 2)) >> 1)) & 3) * 2)) + ((~(((v651 ^ ((int)((unsigned int)((int)((unsigned int)v646 >> 2)) >> 1))) | (-(v651 ^ ((int)((unsigned int)((int)((unsigned int)v646 >> 2)) >> 1))))) >> 31)) & 1);
      int v670 = v669[v775];
      int v671 = v669[v760];
      int v776 = v671 + ((int)((unsigned int)(v671 - v670) >> 31));
      v669[v760] = v776;
      int * v673 = v640->cache_age;
      int v674 = v673[v761];
      int v778 = v674 + ((int)((unsigned int)(v674 - v670) >> 31));
      v673[v761] = v778;
      int * v676 = v640->cache_age;
      v676[v775] = 0;
      v722 = v775;
    } else {
      int * v679 = v640->cache_age;
      int v782 = 4 + ((((int)((unsigned int)((int)((unsigned int)v646 >> 2)) >> 1)) & 3) * 2);
      int v680 = v679[v782];
      int * v681 = v640->cache_tags;
      int v682 = v681[v782];
      int v683 = v679[v761];
      int v684 = v681[v761];
      int * v685 = v640->cache_dirty;
      int v785 = (4 + ((((int)((unsigned int)((int)((unsigned int)v646 >> 2)) >> 1)) & 3) * 2)) + ((((v680 + ((~(((v682 ^ -1) | (-(v682 ^ -1))) >> 31)) & 2)) - (v683 + ((~(((v684 ^ -1) | (-(v684 ^ -1))) >> 31)) & 2))) >> 31) & 1);
      int v686 = v685[v785];
      bool v786 = !(v686 == 0);
      if (v786) {
        int * v687 = v640->cache_tags;
        int v688 = v687[v785];
        int * v689 = v640->cache_vals;
        int v789 = ((4 + ((((int)((unsigned int)((int)((unsigned int)v646 >> 2)) >> 1)) & 3) * 2)) + ((((v680 + ((~(((v682 ^ -1) | (-(v682 ^ -1))) >> 31)) & 2)) - (v683 + ((~(((v684 ^ -1) | (-(v684 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
        int v690 = v689[v789];
        int v790 = (((4 + ((((int)((unsigned int)((int)((unsigned int)v646 >> 2)) >> 1)) & 3) * 2)) + ((((v680 + ((~(((v682 ^ -1) | (-(v682 ^ -1))) >> 31)) & 2)) - (v683 + ((~(((v684 ^ -1) | (-(v684 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
        int v691 = v689[v790];
        int * v692 = v640->mem;
        int v792 = v688 * 2;
        v692[v792] = v690;
        int * v694 = v640->mem;
        int v795 = (v688 * 2) + 1;
        v694[v795] = v691;
        ;
      } else {
        ;
      }
      int * v699 = v640->mem;
      int v800 = ((int)((unsigned int)((int)((unsigned int)v646 >> 2)) >> 1)) * 2;
      int v700 = v699[v800];
      int v801 = (((int)((unsigned int)((int)((unsigned int)v646 >> 2)) >> 1)) * 2) + 1;
      int v701 = v699[v801];
      int * v702 = v640->cache_vals;
      int v803 = ((4 + ((((int)((unsigned int)((int)((unsigned int)v646 >> 2)) >> 1)) & 3) * 2)) + ((((v680 + ((~(((v682 ^ -1) | (-(v682 ^ -1))) >> 31)) & 2)) - (v683 + ((~(((v684 ^ -1) | (-(v684 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
      v702[v803] = v700;
      int * v704 = v640->cache_vals;
      int v806 = (((4 + ((((int)((unsigned int)((int)((unsigned int)v646 >> 2)) >> 1)) & 3) * 2)) + ((((v680 + ((~(((v682 ^ -1) | (-(v682 ^ -1))) >> 31)) & 2)) - (v683 + ((~(((v684 ^ -1) | (-(v684 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
      v704[v806] = v701;
      int * v706 = v640->cache_tags;
      int v809 = (int)((unsigned int)((int)((unsigned int)v646 >> 2)) >> 1);
      v706[v785] = v809;
      int * v708 = v640->cache_dirty;
      v708[v785] = 0;
      int * v710 = v640->cache_age;
      v710[v785] = 1;
      int * v712 = v640->cache_age;
      int v713 = v712[v785];
      int v714 = v712[v760];
      int v815 = v714 + ((int)((unsigned int)(v714 - v713) >> 31));
      v712[v760] = v815;
      int * v716 = v640->cache_age;
      int v717 = v716[v761];
      int v817 = v717 + ((int)((unsigned int)(v717 - v713) >> 31));
      v716[v761] = v817;
      int * v719 = v640->cache_age;
      v719[v785] = 0;
      v722 = v785;
    }
    int * v723 = v640->cache_vals;
    int v820 = v722 * 2;
    int v724 = v723[v820];
    int v821 = (v722 * 2) + 1;
    int v725 = v723[v821];
    int v822 = (((((int)((unsigned int)((int)((unsigned int)v646 >> 2)) >> 1)) & 1) * 2) + ((((v664 + ((~(((v666 ^ -1) | (-(v666 ^ -1))) >> 31)) & 2)) - (v667 + ((~(((v668 ^ -1) | (-(v668 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
    v723[v822] = v724;
    int * v727 = v640->cache_vals;
    int v825 = ((((((int)((unsigned int)((int)((unsigned int)v646 >> 2)) >> 1)) & 1) * 2) + ((((v664 + ((~(((v666 ^ -1) | (-(v666 ^ -1))) >> 31)) & 2)) - (v667 + ((~(((v668 ^ -1) | (-(v668 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
    v727[v825] = v725;
    int * v729 = v640->cache_tags;
    int v828 = ((((int)((unsigned int)((int)((unsigned int)v646 >> 2)) >> 1)) & 1) * 2) + ((((v664 + ((~(((v666 ^ -1) | (-(v666 ^ -1))) >> 31)) & 2)) - (v667 + ((~(((v668 ^ -1) | (-(v668 ^ -1))) >> 31)) & 2))) >> 31) & 1);
    int v829 = (int)((unsigned int)((int)((unsigned int)v646 >> 2)) >> 1);
    v729[v828] = v829;
    int * v731 = v640->cache_dirty;
    v731[v828] = 0;
    int * v733 = v640->cache_age;
    v733[v828] = 1;
    int * v735 = v640->cache_age;
    int v736 = v735[v828];
    int v737 = v735[v758];
    int v835 = v737 + ((int)((unsigned int)(v737 - v736) >> 31));
    v735[v758] = v835;
    int * v739 = v640->cache_age;
    int v740 = v739[v759];
    int v837 = v740 + ((int)((unsigned int)(v740 - v736) >> 31));
    v739[v759] = v837;
    int * v742 = v640->cache_age;
    v742[v828] = 0;
    v745 = v828;
  }
  int v840 = (v745 * 2) + (((int)((unsigned int)v646 >> 2)) & 1);
  int v746 = v652[v840];
  int * v747 = v640->reg_ready;
  int v843 = ((v644 + ((v641 - v644) & (~((v641 - v644) >> 31)))) + 1) + ((100 ^ (((~(((v650 ^ ((int)((unsigned int)((int)((unsigned int)v646 >> 2)) >> 1))) | (-(v650 ^ ((int)((unsigned int)((int)((unsigned int)v646 >> 2)) >> 1))))) >> 31)) | (~(((v651 ^ ((int)((unsigned int)((int)((unsigned int)v646 >> 2)) >> 1))) | (-(v651 ^ ((int)((unsigned int)((int)((unsigned int)v646 >> 2)) >> 1))))) >> 31))) & 104)) ^ (((~(((v648 ^ ((int)((unsigned int)((int)((unsigned int)v646 >> 2)) >> 1))) | (-(v648 ^ ((int)((unsigned int)((int)((unsigned int)v646 >> 2)) >> 1))))) >> 31)) | (~(((v649 ^ ((int)((unsigned int)((int)((unsigned int)v646 >> 2)) >> 1))) | (-(v649 ^ ((int)((unsigned int)((int)((unsigned int)v646 >> 2)) >> 1))))) >> 31))) & (1 ^ (100 ^ (((~(((v650 ^ ((int)((unsigned int)((int)((unsigned int)v646 >> 2)) >> 1))) | (-(v650 ^ ((int)((unsigned int)((int)((unsigned int)v646 >> 2)) >> 1))))) >> 31)) | (~(((v651 ^ ((int)((unsigned int)((int)((unsigned int)v646 >> 2)) >> 1))) | (-(v651 ^ ((int)((unsigned int)((int)((unsigned int)v646 >> 2)) >> 1))))) >> 31))) & 104)))));
  v747[9] = v843;
  int * v749 = v640->regs;
  v749[9] = v746;
  struct StateT * v751 = slot_7(v640);
  return v751;
}

struct StateT * slot_5(struct StateT * v448) {
  int v449 = v448->timer;
  int v557 = v449 + 1;
  v448->timer = v557;
  int * v451 = v448->cache_tags;
  int v452 = v451[0];
  int v453 = v451[1];
  int v454 = v451[8];
  int v455 = v451[9];
  int * v456 = v448->cache_vals;
  bool v563 = !(((~(((v452 ^ 2) | (-(v452 ^ 2))) >> 31)) | (~(((v453 ^ 2) | (-(v453 ^ 2))) >> 31))) == 0);
  int v549;
  if (v563) {
    int * v457 = v448->cache_age;
    int v565 = (~(((v453 ^ 2) | (-(v453 ^ 2))) >> 31)) & 1;
    int v458 = v457[v565];
    int v459 = v457[0];
    int v566 = v459 + ((int)((unsigned int)(v459 - v458) >> 31));
    v457[0] = v566;
    int * v461 = v448->cache_age;
    int v462 = v461[1];
    int v568 = v462 + ((int)((unsigned int)(v462 - v458) >> 31));
    v461[1] = v568;
    int * v464 = v448->cache_age;
    v464[v565] = 0;
    v549 = v565;
  } else {
    int * v467 = v448->cache_age;
    int v468 = v467[0];
    int * v469 = v448->cache_tags;
    int v470 = v469[0];
    int v471 = v467[1];
    int v472 = v469[1];
    bool v572 = !(((~(((v454 ^ 2) | (-(v454 ^ 2))) >> 31)) | (~(((v455 ^ 2) | (-(v455 ^ 2))) >> 31))) == 0);
    int v526;
    if (v572) {
      int * v473 = v448->cache_age;
      int v574 = 8 + ((~(((v455 ^ 2) | (-(v455 ^ 2))) >> 31)) & 1);
      int v474 = v473[v574];
      int v475 = v473[8];
      int v575 = v475 + ((int)((unsigned int)(v475 - v474) >> 31));
      v473[8] = v575;
      int * v477 = v448->cache_age;
      int v478 = v477[9];
      int v577 = v478 + ((int)((unsigned int)(v478 - v474) >> 31));
      v477[9] = v577;
      int * v480 = v448->cache_age;
      v480[v574] = 0;
      v526 = v574;
    } else {
      int * v483 = v448->cache_age;
      int v484 = v483[8];
      int * v485 = v448->cache_tags;
      int v486 = v485[8];
      int v487 = v483[9];
      int v488 = v485[9];
      int * v489 = v448->cache_dirty;
      int v582 = 8 + ((((v484 + ((~(((v486 ^ -1) | (-(v486 ^ -1))) >> 31)) & 2)) - (v487 + ((~(((v488 ^ -1) | (-(v488 ^ -1))) >> 31)) & 2))) >> 31) & 1);
      int v490 = v489[v582];
      bool v583 = !(v490 == 0);
      if (v583) {
        int * v491 = v448->cache_tags;
        int v492 = v491[v582];
        int * v493 = v448->cache_vals;
        int v586 = (8 + ((((v484 + ((~(((v486 ^ -1) | (-(v486 ^ -1))) >> 31)) & 2)) - (v487 + ((~(((v488 ^ -1) | (-(v488 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
        int v494 = v493[v586];
        int v587 = ((8 + ((((v484 + ((~(((v486 ^ -1) | (-(v486 ^ -1))) >> 31)) & 2)) - (v487 + ((~(((v488 ^ -1) | (-(v488 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
        int v495 = v493[v587];
        int * v496 = v448->mem;
        int v589 = v492 * 2;
        v496[v589] = v494;
        int * v498 = v448->mem;
        int v592 = (v492 * 2) + 1;
        v498[v592] = v495;
        ;
      } else {
        ;
      }
      int * v503 = v448->mem;
      int v504 = v503[4];
      int v505 = v503[5];
      int * v506 = v448->cache_vals;
      int v600 = (8 + ((((v484 + ((~(((v486 ^ -1) | (-(v486 ^ -1))) >> 31)) & 2)) - (v487 + ((~(((v488 ^ -1) | (-(v488 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
      v506[v600] = v504;
      int * v508 = v448->cache_vals;
      int v603 = ((8 + ((((v484 + ((~(((v486 ^ -1) | (-(v486 ^ -1))) >> 31)) & 2)) - (v487 + ((~(((v488 ^ -1) | (-(v488 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
      v508[v603] = v505;
      int * v510 = v448->cache_tags;
      v510[v582] = 2;
      int * v512 = v448->cache_dirty;
      v512[v582] = 0;
      int * v514 = v448->cache_age;
      v514[v582] = 1;
      int * v516 = v448->cache_age;
      int v517 = v516[v582];
      int v518 = v516[8];
      int v610 = v518 + ((int)((unsigned int)(v518 - v517) >> 31));
      v516[8] = v610;
      int * v520 = v448->cache_age;
      int v521 = v520[9];
      int v612 = v521 + ((int)((unsigned int)(v521 - v517) >> 31));
      v520[9] = v612;
      int * v523 = v448->cache_age;
      v523[v582] = 0;
      v526 = v582;
    }
    int * v527 = v448->cache_vals;
    int v615 = v526 * 2;
    int v528 = v527[v615];
    int v616 = (v526 * 2) + 1;
    int v529 = v527[v616];
    int v617 = ((((v468 + ((~(((v470 ^ -1) | (-(v470 ^ -1))) >> 31)) & 2)) - (v471 + ((~(((v472 ^ -1) | (-(v472 ^ -1))) >> 31)) & 2))) >> 31) & 1) * 2;
    v527[v617] = v528;
    int * v531 = v448->cache_vals;
    int v620 = (((((v468 + ((~(((v470 ^ -1) | (-(v470 ^ -1))) >> 31)) & 2)) - (v471 + ((~(((v472 ^ -1) | (-(v472 ^ -1))) >> 31)) & 2))) >> 31) & 1) * 2) + 1;
    v531[v620] = v529;
    int * v533 = v448->cache_tags;
    int v623 = (((v468 + ((~(((v470 ^ -1) | (-(v470 ^ -1))) >> 31)) & 2)) - (v471 + ((~(((v472 ^ -1) | (-(v472 ^ -1))) >> 31)) & 2))) >> 31) & 1;
    v533[v623] = 2;
    int * v535 = v448->cache_dirty;
    v535[v623] = 0;
    int * v537 = v448->cache_age;
    v537[v623] = 1;
    int * v539 = v448->cache_age;
    int v540 = v539[v623];
    int v541 = v539[0];
    int v628 = v541 + ((int)((unsigned int)(v541 - v540) >> 31));
    v539[0] = v628;
    int * v543 = v448->cache_age;
    int v544 = v543[1];
    int v630 = v544 + ((int)((unsigned int)(v544 - v540) >> 31));
    v543[1] = v630;
    int * v546 = v448->cache_age;
    v546[v623] = 0;
    v549 = v623;
  }
  int v633 = v549 * 2;
  int v550 = v456[v633];
  int * v551 = v448->reg_ready;
  int v635 = (v449 + 1) + ((100 ^ (((~(((v454 ^ 2) | (-(v454 ^ 2))) >> 31)) | (~(((v455 ^ 2) | (-(v455 ^ 2))) >> 31))) & 104)) ^ (((~(((v452 ^ 2) | (-(v452 ^ 2))) >> 31)) | (~(((v453 ^ 2) | (-(v453 ^ 2))) >> 31))) & (1 ^ (100 ^ (((~(((v454 ^ 2) | (-(v454 ^ 2))) >> 31)) | (~(((v455 ^ 2) | (-(v455 ^ 2))) >> 31))) & 104)))));
  v551[8] = v635;
  int * v553 = v448->regs;
  v553[8] = v550;
  struct StateT * v555 = slot_6(v448);
  return v555;
}

struct StateT * slot_4(struct StateT * v259) {
  int v260 = v259->timer;
  int v368 = v260 + 1;
  v259->timer = v368;
  int * v262 = v259->cache_tags;
  int v263 = v262[0];
  int v264 = v262[1];
  int v265 = v262[4];
  int v266 = v262[5];
  int * v267 = v259->cache_vals;
  bool v374 = !(((~((v263 | (-v263)) >> 31)) | (~((v264 | (-v264)) >> 31))) == 0);
  int v360;
  if (v374) {
    int * v268 = v259->cache_age;
    int v376 = (~((v264 | (-v264)) >> 31)) & 1;
    int v269 = v268[v376];
    int v270 = v268[0];
    int v377 = v270 + ((int)((unsigned int)(v270 - v269) >> 31));
    v268[0] = v377;
    int * v272 = v259->cache_age;
    int v273 = v272[1];
    int v379 = v273 + ((int)((unsigned int)(v273 - v269) >> 31));
    v272[1] = v379;
    int * v275 = v259->cache_age;
    v275[v376] = 0;
    v360 = v376;
  } else {
    int * v278 = v259->cache_age;
    int v279 = v278[0];
    int * v280 = v259->cache_tags;
    int v281 = v280[0];
    int v282 = v278[1];
    int v283 = v280[1];
    bool v383 = !(((~((v265 | (-v265)) >> 31)) | (~((v266 | (-v266)) >> 31))) == 0);
    int v337;
    if (v383) {
      int * v284 = v259->cache_age;
      int v385 = 4 + ((~((v266 | (-v266)) >> 31)) & 1);
      int v285 = v284[v385];
      int v286 = v284[4];
      int v386 = v286 + ((int)((unsigned int)(v286 - v285) >> 31));
      v284[4] = v386;
      int * v288 = v259->cache_age;
      int v289 = v288[5];
      int v388 = v289 + ((int)((unsigned int)(v289 - v285) >> 31));
      v288[5] = v388;
      int * v291 = v259->cache_age;
      v291[v385] = 0;
      v337 = v385;
    } else {
      int * v294 = v259->cache_age;
      int v295 = v294[4];
      int * v296 = v259->cache_tags;
      int v297 = v296[4];
      int v298 = v294[5];
      int v299 = v296[5];
      int * v300 = v259->cache_dirty;
      int v393 = 4 + ((((v295 + ((~(((v297 ^ -1) | (-(v297 ^ -1))) >> 31)) & 2)) - (v298 + ((~(((v299 ^ -1) | (-(v299 ^ -1))) >> 31)) & 2))) >> 31) & 1);
      int v301 = v300[v393];
      bool v394 = !(v301 == 0);
      if (v394) {
        int * v302 = v259->cache_tags;
        int v303 = v302[v393];
        int * v304 = v259->cache_vals;
        int v397 = (4 + ((((v295 + ((~(((v297 ^ -1) | (-(v297 ^ -1))) >> 31)) & 2)) - (v298 + ((~(((v299 ^ -1) | (-(v299 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
        int v305 = v304[v397];
        int v398 = ((4 + ((((v295 + ((~(((v297 ^ -1) | (-(v297 ^ -1))) >> 31)) & 2)) - (v298 + ((~(((v299 ^ -1) | (-(v299 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
        int v306 = v304[v398];
        int * v307 = v259->mem;
        int v400 = v303 * 2;
        v307[v400] = v305;
        int * v309 = v259->mem;
        int v403 = (v303 * 2) + 1;
        v309[v403] = v306;
        ;
      } else {
        ;
      }
      int * v314 = v259->mem;
      int v315 = v314[0];
      int v316 = v314[1];
      int * v317 = v259->cache_vals;
      int v409 = (4 + ((((v295 + ((~(((v297 ^ -1) | (-(v297 ^ -1))) >> 31)) & 2)) - (v298 + ((~(((v299 ^ -1) | (-(v299 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
      v317[v409] = v315;
      int * v319 = v259->cache_vals;
      int v412 = ((4 + ((((v295 + ((~(((v297 ^ -1) | (-(v297 ^ -1))) >> 31)) & 2)) - (v298 + ((~(((v299 ^ -1) | (-(v299 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
      v319[v412] = v316;
      int * v321 = v259->cache_tags;
      v321[v393] = 0;
      int * v323 = v259->cache_dirty;
      v323[v393] = 0;
      int * v325 = v259->cache_age;
      v325[v393] = 1;
      int * v327 = v259->cache_age;
      int v328 = v327[v393];
      int v329 = v327[4];
      int v418 = v329 + ((int)((unsigned int)(v329 - v328) >> 31));
      v327[4] = v418;
      int * v331 = v259->cache_age;
      int v332 = v331[5];
      int v420 = v332 + ((int)((unsigned int)(v332 - v328) >> 31));
      v331[5] = v420;
      int * v334 = v259->cache_age;
      v334[v393] = 0;
      v337 = v393;
    }
    int * v338 = v259->cache_vals;
    int v423 = v337 * 2;
    int v339 = v338[v423];
    int v424 = (v337 * 2) + 1;
    int v340 = v338[v424];
    int v425 = ((((v279 + ((~(((v281 ^ -1) | (-(v281 ^ -1))) >> 31)) & 2)) - (v282 + ((~(((v283 ^ -1) | (-(v283 ^ -1))) >> 31)) & 2))) >> 31) & 1) * 2;
    v338[v425] = v339;
    int * v342 = v259->cache_vals;
    int v428 = (((((v279 + ((~(((v281 ^ -1) | (-(v281 ^ -1))) >> 31)) & 2)) - (v282 + ((~(((v283 ^ -1) | (-(v283 ^ -1))) >> 31)) & 2))) >> 31) & 1) * 2) + 1;
    v342[v428] = v340;
    int * v344 = v259->cache_tags;
    int v431 = (((v279 + ((~(((v281 ^ -1) | (-(v281 ^ -1))) >> 31)) & 2)) - (v282 + ((~(((v283 ^ -1) | (-(v283 ^ -1))) >> 31)) & 2))) >> 31) & 1;
    v344[v431] = 0;
    int * v346 = v259->cache_dirty;
    v346[v431] = 0;
    int * v348 = v259->cache_age;
    v348[v431] = 1;
    int * v350 = v259->cache_age;
    int v351 = v350[v431];
    int v352 = v350[0];
    int v435 = v352 + ((int)((unsigned int)(v352 - v351) >> 31));
    v350[0] = v435;
    int * v354 = v259->cache_age;
    int v355 = v354[1];
    int v437 = v355 + ((int)((unsigned int)(v355 - v351) >> 31));
    v354[1] = v437;
    int * v357 = v259->cache_age;
    v357[v431] = 0;
    v360 = v431;
  }
  int v440 = v360 * 2;
  int v361 = v267[v440];
  int * v362 = v259->reg_ready;
  int v443 = (v260 + 1) + ((100 ^ (((~((v265 | (-v265)) >> 31)) | (~((v266 | (-v266)) >> 31))) & 104)) ^ (((~((v263 | (-v263)) >> 31)) | (~((v264 | (-v264)) >> 31))) & (1 ^ (100 ^ (((~((v265 | (-v265)) >> 31)) | (~((v266 | (-v266)) >> 31))) & 104)))));
  v362[7] = v443;
  int * v364 = v259->regs;
  v364[7] = v361;
  struct StateT * v366 = slot_5(v259);
  return v366;
}

struct StateT * slot_2(struct StateT * v217) {
  int v218 = v217->timer;
  int v229 = v218 + 1;
  v217->timer = v229;
  int * v220 = v217->reg_ready;
  int v221 = v220[6];
  int * v222 = v217->regs;
  int v223 = v222[6];
  int v233 = (v221 + ((v218 - v221) & (~((v218 - v221) >> 31)))) + 1;
  v220[6] = v233;
  int * v225 = v217->regs;
  int v235 = v223 << 3;
  v225[6] = v235;
  struct StateT * v227 = slot_3(v217);
  return v227;
}

struct StateT * slot_7(struct StateT * v848) {
  int v849 = v848->timer;
  int v956 = v849 + 1;
  v848->timer = v956;
  int * v851 = v848->cache_tags;
  int v852 = v851[0];
  int v853 = v851[1];
  int v854 = v851[4];
  int v855 = v851[5];
  int * v856 = v848->cache_vals;
  bool v962 = !(((~((v852 | (-v852)) >> 31)) | (~((v853 | (-v853)) >> 31))) == 0);
  int v949;
  if (v962) {
    int * v857 = v848->cache_age;
    int v964 = (~((v853 | (-v853)) >> 31)) & 1;
    int v858 = v857[v964];
    int v859 = v857[0];
    int v965 = v859 + ((int)((unsigned int)(v859 - v858) >> 31));
    v857[0] = v965;
    int * v861 = v848->cache_age;
    int v862 = v861[1];
    int v967 = v862 + ((int)((unsigned int)(v862 - v858) >> 31));
    v861[1] = v967;
    int * v864 = v848->cache_age;
    v864[v964] = 0;
    v949 = v964;
  } else {
    int * v867 = v848->cache_age;
    int v868 = v867[0];
    int * v869 = v848->cache_tags;
    int v870 = v869[0];
    int v871 = v867[1];
    int v872 = v869[1];
    bool v971 = !(((~((v854 | (-v854)) >> 31)) | (~((v855 | (-v855)) >> 31))) == 0);
    int v926;
    if (v971) {
      int * v873 = v848->cache_age;
      int v973 = 4 + ((~((v855 | (-v855)) >> 31)) & 1);
      int v874 = v873[v973];
      int v875 = v873[4];
      int v974 = v875 + ((int)((unsigned int)(v875 - v874) >> 31));
      v873[4] = v974;
      int * v877 = v848->cache_age;
      int v878 = v877[5];
      int v976 = v878 + ((int)((unsigned int)(v878 - v874) >> 31));
      v877[5] = v976;
      int * v880 = v848->cache_age;
      v880[v973] = 0;
      v926 = v973;
    } else {
      int * v883 = v848->cache_age;
      int v884 = v883[4];
      int * v885 = v848->cache_tags;
      int v886 = v885[4];
      int v887 = v883[5];
      int v888 = v885[5];
      int * v889 = v848->cache_dirty;
      int v981 = 4 + ((((v884 + ((~(((v886 ^ -1) | (-(v886 ^ -1))) >> 31)) & 2)) - (v887 + ((~(((v888 ^ -1) | (-(v888 ^ -1))) >> 31)) & 2))) >> 31) & 1);
      int v890 = v889[v981];
      bool v982 = !(v890 == 0);
      if (v982) {
        int * v891 = v848->cache_tags;
        int v892 = v891[v981];
        int * v893 = v848->cache_vals;
        int v985 = (4 + ((((v884 + ((~(((v886 ^ -1) | (-(v886 ^ -1))) >> 31)) & 2)) - (v887 + ((~(((v888 ^ -1) | (-(v888 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
        int v894 = v893[v985];
        int v986 = ((4 + ((((v884 + ((~(((v886 ^ -1) | (-(v886 ^ -1))) >> 31)) & 2)) - (v887 + ((~(((v888 ^ -1) | (-(v888 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
        int v895 = v893[v986];
        int * v896 = v848->mem;
        int v988 = v892 * 2;
        v896[v988] = v894;
        int * v898 = v848->mem;
        int v991 = (v892 * 2) + 1;
        v898[v991] = v895;
        ;
      } else {
        ;
      }
      int * v903 = v848->mem;
      int v904 = v903[0];
      int v905 = v903[1];
      int * v906 = v848->cache_vals;
      int v997 = (4 + ((((v884 + ((~(((v886 ^ -1) | (-(v886 ^ -1))) >> 31)) & 2)) - (v887 + ((~(((v888 ^ -1) | (-(v888 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
      v906[v997] = v904;
      int * v908 = v848->cache_vals;
      int v1000 = ((4 + ((((v884 + ((~(((v886 ^ -1) | (-(v886 ^ -1))) >> 31)) & 2)) - (v887 + ((~(((v888 ^ -1) | (-(v888 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
      v908[v1000] = v905;
      int * v910 = v848->cache_tags;
      v910[v981] = 0;
      int * v912 = v848->cache_dirty;
      v912[v981] = 0;
      int * v914 = v848->cache_age;
      v914[v981] = 1;
      int * v916 = v848->cache_age;
      int v917 = v916[v981];
      int v918 = v916[4];
      int v1006 = v918 + ((int)((unsigned int)(v918 - v917) >> 31));
      v916[4] = v1006;
      int * v920 = v848->cache_age;
      int v921 = v920[5];
      int v1008 = v921 + ((int)((unsigned int)(v921 - v917) >> 31));
      v920[5] = v1008;
      int * v923 = v848->cache_age;
      v923[v981] = 0;
      v926 = v981;
    }
    int * v927 = v848->cache_vals;
    int v1011 = v926 * 2;
    int v928 = v927[v1011];
    int v1012 = (v926 * 2) + 1;
    int v929 = v927[v1012];
    int v1013 = ((((v868 + ((~(((v870 ^ -1) | (-(v870 ^ -1))) >> 31)) & 2)) - (v871 + ((~(((v872 ^ -1) | (-(v872 ^ -1))) >> 31)) & 2))) >> 31) & 1) * 2;
    v927[v1013] = v928;
    int * v931 = v848->cache_vals;
    int v1016 = (((((v868 + ((~(((v870 ^ -1) | (-(v870 ^ -1))) >> 31)) & 2)) - (v871 + ((~(((v872 ^ -1) | (-(v872 ^ -1))) >> 31)) & 2))) >> 31) & 1) * 2) + 1;
    v931[v1016] = v929;
    int * v933 = v848->cache_tags;
    int v1019 = (((v868 + ((~(((v870 ^ -1) | (-(v870 ^ -1))) >> 31)) & 2)) - (v871 + ((~(((v872 ^ -1) | (-(v872 ^ -1))) >> 31)) & 2))) >> 31) & 1;
    v933[v1019] = 0;
    int * v935 = v848->cache_dirty;
    v935[v1019] = 0;
    int * v937 = v848->cache_age;
    v937[v1019] = 1;
    int * v939 = v848->cache_age;
    int v940 = v939[v1019];
    int v941 = v939[0];
    int v1023 = v941 + ((int)((unsigned int)(v941 - v940) >> 31));
    v939[0] = v1023;
    int * v943 = v848->cache_age;
    int v944 = v943[1];
    int v1025 = v944 + ((int)((unsigned int)(v944 - v940) >> 31));
    v943[1] = v1025;
    int * v946 = v848->cache_age;
    v946[v1019] = 0;
    v949 = v1019;
  }
  int v1028 = v949 * 2;
  int v950 = v856[v1028];
  int * v951 = v848->reg_ready;
  int v1031 = (v849 + 1) + ((100 ^ (((~((v854 | (-v854)) >> 31)) | (~((v855 | (-v855)) >> 31))) & 104)) ^ (((~((v852 | (-v852)) >> 31)) | (~((v853 | (-v853)) >> 31))) & (1 ^ (100 ^ (((~((v854 | (-v854)) >> 31)) | (~((v855 | (-v855)) >> 31))) & 104)))));
  v951[11] = v1031;
  int * v953 = v848->regs;
  v953[11] = v950;
  return v848;
}

struct StateT * slot_3(struct StateT * v238) {
  int v239 = v238->timer;
  int v250 = v239 + 1;
  v238->timer = v250;
  int * v241 = v238->reg_ready;
  int v242 = v241[6];
  int * v243 = v238->regs;
  int v244 = v243[6];
  int v254 = (v242 + ((v239 - v242) & (~((v239 - v242) >> 31)))) + 1;
  v241[6] = v254;
  int * v246 = v238->regs;
  int v256 = v244 + 32;
  v246[6] = v256;
  struct StateT * v248 = slot_4(v238);
  return v248;
}

struct StateT * slot_0(struct StateT * v2) {
  int v3 = v2->timer;
  int v111 = v3 + 1;
  v2->timer = v111;
  int * v5 = v2->cache_tags;
  int v6 = v5[0];
  int v7 = v5[1];
  int v8 = v5[8];
  int v9 = v5[9];
  int * v10 = v2->cache_vals;
  bool v117 = !(((~(((v6 ^ 10) | (-(v6 ^ 10))) >> 31)) | (~(((v7 ^ 10) | (-(v7 ^ 10))) >> 31))) == 0);
  int v103;
  if (v117) {
    int * v11 = v2->cache_age;
    int v119 = (~(((v7 ^ 10) | (-(v7 ^ 10))) >> 31)) & 1;
    int v12 = v11[v119];
    int v13 = v11[0];
    int v120 = v13 + ((int)((unsigned int)(v13 - v12) >> 31));
    v11[0] = v120;
    int * v15 = v2->cache_age;
    int v16 = v15[1];
    int v122 = v16 + ((int)((unsigned int)(v16 - v12) >> 31));
    v15[1] = v122;
    int * v18 = v2->cache_age;
    v18[v119] = 0;
    v103 = v119;
  } else {
    int * v21 = v2->cache_age;
    int v22 = v21[0];
    int * v23 = v2->cache_tags;
    int v24 = v23[0];
    int v25 = v21[1];
    int v26 = v23[1];
    bool v126 = !(((~(((v8 ^ 10) | (-(v8 ^ 10))) >> 31)) | (~(((v9 ^ 10) | (-(v9 ^ 10))) >> 31))) == 0);
    int v80;
    if (v126) {
      int * v27 = v2->cache_age;
      int v128 = 8 + ((~(((v9 ^ 10) | (-(v9 ^ 10))) >> 31)) & 1);
      int v28 = v27[v128];
      int v29 = v27[8];
      int v129 = v29 + ((int)((unsigned int)(v29 - v28) >> 31));
      v27[8] = v129;
      int * v31 = v2->cache_age;
      int v32 = v31[9];
      int v131 = v32 + ((int)((unsigned int)(v32 - v28) >> 31));
      v31[9] = v131;
      int * v34 = v2->cache_age;
      v34[v128] = 0;
      v80 = v128;
    } else {
      int * v37 = v2->cache_age;
      int v38 = v37[8];
      int * v39 = v2->cache_tags;
      int v40 = v39[8];
      int v41 = v37[9];
      int v42 = v39[9];
      int * v43 = v2->cache_dirty;
      int v136 = 8 + ((((v38 + ((~(((v40 ^ -1) | (-(v40 ^ -1))) >> 31)) & 2)) - (v41 + ((~(((v42 ^ -1) | (-(v42 ^ -1))) >> 31)) & 2))) >> 31) & 1);
      int v44 = v43[v136];
      bool v137 = !(v44 == 0);
      if (v137) {
        int * v45 = v2->cache_tags;
        int v46 = v45[v136];
        int * v47 = v2->cache_vals;
        int v140 = (8 + ((((v38 + ((~(((v40 ^ -1) | (-(v40 ^ -1))) >> 31)) & 2)) - (v41 + ((~(((v42 ^ -1) | (-(v42 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
        int v48 = v47[v140];
        int v141 = ((8 + ((((v38 + ((~(((v40 ^ -1) | (-(v40 ^ -1))) >> 31)) & 2)) - (v41 + ((~(((v42 ^ -1) | (-(v42 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
        int v49 = v47[v141];
        int * v50 = v2->mem;
        int v143 = v46 * 2;
        v50[v143] = v48;
        int * v52 = v2->mem;
        int v146 = (v46 * 2) + 1;
        v52[v146] = v49;
        ;
      } else {
        ;
      }
      int * v57 = v2->mem;
      int v58 = v57[20];
      int v59 = v57[21];
      int * v60 = v2->cache_vals;
      int v154 = (8 + ((((v38 + ((~(((v40 ^ -1) | (-(v40 ^ -1))) >> 31)) & 2)) - (v41 + ((~(((v42 ^ -1) | (-(v42 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
      v60[v154] = v58;
      int * v62 = v2->cache_vals;
      int v157 = ((8 + ((((v38 + ((~(((v40 ^ -1) | (-(v40 ^ -1))) >> 31)) & 2)) - (v41 + ((~(((v42 ^ -1) | (-(v42 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
      v62[v157] = v59;
      int * v64 = v2->cache_tags;
      v64[v136] = 10;
      int * v66 = v2->cache_dirty;
      v66[v136] = 0;
      int * v68 = v2->cache_age;
      v68[v136] = 1;
      int * v70 = v2->cache_age;
      int v71 = v70[v136];
      int v72 = v70[8];
      int v164 = v72 + ((int)((unsigned int)(v72 - v71) >> 31));
      v70[8] = v164;
      int * v74 = v2->cache_age;
      int v75 = v74[9];
      int v166 = v75 + ((int)((unsigned int)(v75 - v71) >> 31));
      v74[9] = v166;
      int * v77 = v2->cache_age;
      v77[v136] = 0;
      v80 = v136;
    }
    int * v81 = v2->cache_vals;
    int v169 = v80 * 2;
    int v82 = v81[v169];
    int v170 = (v80 * 2) + 1;
    int v83 = v81[v170];
    int v171 = ((((v22 + ((~(((v24 ^ -1) | (-(v24 ^ -1))) >> 31)) & 2)) - (v25 + ((~(((v26 ^ -1) | (-(v26 ^ -1))) >> 31)) & 2))) >> 31) & 1) * 2;
    v81[v171] = v82;
    int * v85 = v2->cache_vals;
    int v174 = (((((v22 + ((~(((v24 ^ -1) | (-(v24 ^ -1))) >> 31)) & 2)) - (v25 + ((~(((v26 ^ -1) | (-(v26 ^ -1))) >> 31)) & 2))) >> 31) & 1) * 2) + 1;
    v85[v174] = v83;
    int * v87 = v2->cache_tags;
    int v177 = (((v22 + ((~(((v24 ^ -1) | (-(v24 ^ -1))) >> 31)) & 2)) - (v25 + ((~(((v26 ^ -1) | (-(v26 ^ -1))) >> 31)) & 2))) >> 31) & 1;
    v87[v177] = 10;
    int * v89 = v2->cache_dirty;
    v89[v177] = 0;
    int * v91 = v2->cache_age;
    v91[v177] = 1;
    int * v93 = v2->cache_age;
    int v94 = v93[v177];
    int v95 = v93[0];
    int v182 = v95 + ((int)((unsigned int)(v95 - v94) >> 31));
    v93[0] = v182;
    int * v97 = v2->cache_age;
    int v98 = v97[1];
    int v184 = v98 + ((int)((unsigned int)(v98 - v94) >> 31));
    v97[1] = v184;
    int * v100 = v2->cache_age;
    v100[v177] = 0;
    v103 = v177;
  }
  int v187 = v103 * 2;
  int v104 = v10[v187];
  int * v105 = v2->reg_ready;
  int v190 = (v3 + 1) + ((100 ^ (((~(((v8 ^ 10) | (-(v8 ^ 10))) >> 31)) | (~(((v9 ^ 10) | (-(v9 ^ 10))) >> 31))) & 104)) ^ (((~(((v6 ^ 10) | (-(v6 ^ 10))) >> 31)) | (~(((v7 ^ 10) | (-(v7 ^ 10))) >> 31))) & (1 ^ (100 ^ (((~(((v8 ^ 10) | (-(v8 ^ 10))) >> 31)) | (~(((v9 ^ 10) | (-(v9 ^ 10))) >> 31))) & 104)))));
  v105[5] = v190;
  int * v107 = v2->regs;
  v107[5] = v104;
  struct StateT * v109 = slot_1(v2);
  return v109;
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
  
  int x = bounded(0, 80);
  s1.regs[10] = x;
  s2.regs[10] = x;
  
  // initialize secret
  for (int i=0; i<SECRET_SIZE; i++) {
    s1.mem[SECRET_OFFSET+i] = secret(0, 20);
    s2.mem[SECRET_OFFSET+i] = secret(0, 20);
  }
  struct StateT *s1_ = snippet(&s1);
  struct StateT *s2_ = snippet(&s2);
  koika_assert(s1_->timer==s2_->timer, "timing leak");
  return 0;
}