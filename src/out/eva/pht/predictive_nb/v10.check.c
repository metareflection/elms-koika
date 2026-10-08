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

struct StateT * slot_12(struct StateT * v747);
struct StateT * slot_14(struct StateT * v964);
struct StateT * slot_16(struct StateT * v980);
struct StateT * slot_5(struct StateT * v450);
struct StateT * slot_17(struct StateT * v996);
struct StateT * slot_20(struct StateT * v1435);
struct StateT * slot_2(struct StateT * v225);
struct StateT * slot_7(struct StateT * v471);
struct StateT * slot_21(struct StateT * v1754);
struct StateT * slot_3(struct StateT * v233);
struct StateT * snippet(struct StateT * v0);
struct StateT * slot_10(struct StateT * v532);
struct StateT * slot_1(struct StateT * v18);
struct StateT * slot_8(struct StateT * v487);
struct StateT * slot_19(struct StateT * v1411);
struct StateT * slot_18(struct StateT * v1203);
struct StateT * slot_9(struct StateT * v508);
struct StateT * slot_11(struct StateT * v739);
struct StateT * slot_0(struct StateT * v2);
struct StateT * slot_12(struct StateT * v747) {
  int * v748 = v747->regs;
  int v749 = v748[10];
  int v750 = v748[11];
  bool v858 = !(v749 == v750);
  struct StateT * v853;
  if (v858) {
    int v751 = v747->timer;
    int v859 = v751 + 15;
    v747->timer = v859;
    int * v753 = v747->reg_ready;
    int v754 = v747->timer;
    v753[0] = v754;
    int * v756 = v747->reg_ready;
    int v757 = v747->timer;
    v756[1] = v757;
    int * v759 = v747->reg_ready;
    int v760 = v747->timer;
    v759[2] = v760;
    int * v762 = v747->reg_ready;
    int v763 = v747->timer;
    v762[3] = v763;
    int * v765 = v747->reg_ready;
    int v766 = v747->timer;
    v765[4] = v766;
    int * v768 = v747->reg_ready;
    int v769 = v747->timer;
    v768[5] = v769;
    int * v771 = v747->reg_ready;
    int v772 = v747->timer;
    v771[6] = v772;
    int * v774 = v747->reg_ready;
    int v775 = v747->timer;
    v774[7] = v775;
    int * v777 = v747->reg_ready;
    int v778 = v747->timer;
    v777[8] = v778;
    int * v780 = v747->reg_ready;
    int v781 = v747->timer;
    v780[9] = v781;
    int * v783 = v747->reg_ready;
    int v784 = v747->timer;
    v783[10] = v784;
    int * v786 = v747->reg_ready;
    int v787 = v747->timer;
    v786[11] = v787;
    int * v789 = v747->reg_ready;
    int v790 = v747->timer;
    v789[12] = v790;
    int * v792 = v747->reg_ready;
    int v793 = v747->timer;
    v792[13] = v793;
    int * v795 = v747->reg_ready;
    int v796 = v747->timer;
    v795[14] = v796;
    int * v798 = v747->reg_ready;
    int v799 = v747->timer;
    v798[15] = v799;
    int * v801 = v747->reg_ready;
    int v802 = v747->timer;
    v801[16] = v802;
    int * v804 = v747->reg_ready;
    int v805 = v747->timer;
    v804[17] = v805;
    int * v807 = v747->reg_ready;
    int v808 = v747->timer;
    v807[18] = v808;
    int * v810 = v747->reg_ready;
    int v811 = v747->timer;
    v810[19] = v811;
    int * v813 = v747->reg_ready;
    int v814 = v747->timer;
    v813[20] = v814;
    int * v816 = v747->reg_ready;
    int v817 = v747->timer;
    v816[21] = v817;
    int * v819 = v747->reg_ready;
    int v820 = v747->timer;
    v819[22] = v820;
    int * v822 = v747->reg_ready;
    int v823 = v747->timer;
    v822[23] = v823;
    int * v825 = v747->reg_ready;
    int v826 = v747->timer;
    v825[24] = v826;
    int * v828 = v747->reg_ready;
    int v829 = v747->timer;
    v828[25] = v829;
    int * v831 = v747->reg_ready;
    int v832 = v747->timer;
    v831[26] = v832;
    int * v834 = v747->reg_ready;
    int v835 = v747->timer;
    v834[27] = v835;
    int * v837 = v747->reg_ready;
    int v838 = v747->timer;
    v837[28] = v838;
    int * v840 = v747->reg_ready;
    int v841 = v747->timer;
    v840[29] = v841;
    int * v843 = v747->reg_ready;
    int v844 = v747->timer;
    v843[30] = v844;
    int * v846 = v747->reg_ready;
    int v847 = v747->timer;
    v846[31] = v847;
    struct StateT * v849 = slot_21(v747);
    v853 = v849;
  } else {
    struct StateT * v851 = slot_14(v747);
    v853 = v851;
  }
  return v853;
}

struct StateT * slot_14(struct StateT * v964) {
  int v965 = v964->timer;
  int v973 = v965 + 1;
  v964->timer = v973;
  int * v967 = v964->reg_ready;
  v967[10] = v973;
  int * v969 = v964->regs;
  v969[10] = 0;
  struct StateT * v971 = slot_16(v964);
  return v971;
}

struct StateT * slot_16(struct StateT * v980) {
  int v981 = v980->timer;
  int v989 = v981 + 1;
  v980->timer = v989;
  int * v983 = v980->reg_ready;
  v983[11] = v989;
  int * v985 = v980->regs;
  v985[11] = 0;
  struct StateT * v987 = slot_17(v980);
  return v987;
}

struct StateT * slot_5(struct StateT * v450) {
  int v451 = v450->timer;
  int v462 = v451 + 1;
  v450->timer = v462;
  int * v453 = v450->reg_ready;
  int v454 = v453[10];
  int * v455 = v450->regs;
  int v456 = v455[10];
  int v466 = (v454 + ((v451 - v454) & (~((v451 - v454) >> 31)))) + 1;
  v453[10] = v466;
  int * v458 = v450->regs;
  int v468 = v456 << 2;
  v458[10] = v468;
  struct StateT * v460 = slot_7(v450);
  return v460;
}

struct StateT * slot_17(struct StateT * v996) {
  int v997 = v996->timer;
  int v1109 = v997 + 1;
  v996->timer = v1109;
  int * v999 = v996->reg_ready;
  int v1000 = v999[10];
  int * v1001 = v996->regs;
  int v1002 = v1001[10];
  int * v1003 = v996->cache_tags;
  int v1114 = (((int)((unsigned int)((int)((unsigned int)(v1002 + 4) >> 2)) >> 1)) & 1) * 2;
  int v1004 = v1003[v1114];
  int v1115 = ((((int)((unsigned int)((int)((unsigned int)(v1002 + 4) >> 2)) >> 1)) & 1) * 2) + 1;
  int v1005 = v1003[v1115];
  int v1116 = 4 + ((((int)((unsigned int)((int)((unsigned int)(v1002 + 4) >> 2)) >> 1)) & 3) * 2);
  int v1006 = v1003[v1116];
  int v1117 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v1002 + 4) >> 2)) >> 1)) & 3) * 2)) + 1;
  int v1007 = v1003[v1117];
  int * v1008 = v996->cache_vals;
  bool v1118 = !(((~(((v1004 ^ ((int)((unsigned int)((int)((unsigned int)(v1002 + 4) >> 2)) >> 1))) | (-(v1004 ^ ((int)((unsigned int)((int)((unsigned int)(v1002 + 4) >> 2)) >> 1))))) >> 31)) | (~(((v1005 ^ ((int)((unsigned int)((int)((unsigned int)(v1002 + 4) >> 2)) >> 1))) | (-(v1005 ^ ((int)((unsigned int)((int)((unsigned int)(v1002 + 4) >> 2)) >> 1))))) >> 31))) == 0);
  int v1101;
  if (v1118) {
    int * v1009 = v996->cache_age;
    int v1120 = ((((int)((unsigned int)((int)((unsigned int)(v1002 + 4) >> 2)) >> 1)) & 1) * 2) + ((~(((v1005 ^ ((int)((unsigned int)((int)((unsigned int)(v1002 + 4) >> 2)) >> 1))) | (-(v1005 ^ ((int)((unsigned int)((int)((unsigned int)(v1002 + 4) >> 2)) >> 1))))) >> 31)) & 1);
    int v1010 = v1009[v1120];
    int v1011 = v1009[v1114];
    int v1121 = v1011 + ((int)((unsigned int)(v1011 - v1010) >> 31));
    v1009[v1114] = v1121;
    int * v1013 = v996->cache_age;
    int v1014 = v1013[v1115];
    int v1123 = v1014 + ((int)((unsigned int)(v1014 - v1010) >> 31));
    v1013[v1115] = v1123;
    int * v1016 = v996->cache_age;
    v1016[v1120] = 0;
    v1101 = v1120;
  } else {
    int * v1019 = v996->cache_age;
    int v1127 = (((int)((unsigned int)((int)((unsigned int)(v1002 + 4) >> 2)) >> 1)) & 1) * 2;
    int v1020 = v1019[v1127];
    int * v1021 = v996->cache_tags;
    int v1022 = v1021[v1127];
    int v1023 = v1019[v1115];
    int v1024 = v1021[v1115];
    bool v1129 = !(((~(((v1006 ^ ((int)((unsigned int)((int)((unsigned int)(v1002 + 4) >> 2)) >> 1))) | (-(v1006 ^ ((int)((unsigned int)((int)((unsigned int)(v1002 + 4) >> 2)) >> 1))))) >> 31)) | (~(((v1007 ^ ((int)((unsigned int)((int)((unsigned int)(v1002 + 4) >> 2)) >> 1))) | (-(v1007 ^ ((int)((unsigned int)((int)((unsigned int)(v1002 + 4) >> 2)) >> 1))))) >> 31))) == 0);
    int v1078;
    if (v1129) {
      int * v1025 = v996->cache_age;
      int v1131 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v1002 + 4) >> 2)) >> 1)) & 3) * 2)) + ((~(((v1007 ^ ((int)((unsigned int)((int)((unsigned int)(v1002 + 4) >> 2)) >> 1))) | (-(v1007 ^ ((int)((unsigned int)((int)((unsigned int)(v1002 + 4) >> 2)) >> 1))))) >> 31)) & 1);
      int v1026 = v1025[v1131];
      int v1027 = v1025[v1116];
      int v1132 = v1027 + ((int)((unsigned int)(v1027 - v1026) >> 31));
      v1025[v1116] = v1132;
      int * v1029 = v996->cache_age;
      int v1030 = v1029[v1117];
      int v1134 = v1030 + ((int)((unsigned int)(v1030 - v1026) >> 31));
      v1029[v1117] = v1134;
      int * v1032 = v996->cache_age;
      v1032[v1131] = 0;
      v1078 = v1131;
    } else {
      int * v1035 = v996->cache_age;
      int v1138 = 4 + ((((int)((unsigned int)((int)((unsigned int)(v1002 + 4) >> 2)) >> 1)) & 3) * 2);
      int v1036 = v1035[v1138];
      int * v1037 = v996->cache_tags;
      int v1038 = v1037[v1138];
      int v1039 = v1035[v1117];
      int v1040 = v1037[v1117];
      int * v1041 = v996->cache_dirty;
      int v1141 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v1002 + 4) >> 2)) >> 1)) & 3) * 2)) + ((((v1036 + ((~(((v1038 ^ -1) | (-(v1038 ^ -1))) >> 31)) & 2)) - (v1039 + ((~(((v1040 ^ -1) | (-(v1040 ^ -1))) >> 31)) & 2))) >> 31) & 1);
      int v1042 = v1041[v1141];
      bool v1142 = !(v1042 == 0);
      if (v1142) {
        int * v1043 = v996->cache_tags;
        int v1044 = v1043[v1141];
        int * v1045 = v996->cache_vals;
        int v1145 = ((4 + ((((int)((unsigned int)((int)((unsigned int)(v1002 + 4) >> 2)) >> 1)) & 3) * 2)) + ((((v1036 + ((~(((v1038 ^ -1) | (-(v1038 ^ -1))) >> 31)) & 2)) - (v1039 + ((~(((v1040 ^ -1) | (-(v1040 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
        int v1046 = v1045[v1145];
        int v1146 = (((4 + ((((int)((unsigned int)((int)((unsigned int)(v1002 + 4) >> 2)) >> 1)) & 3) * 2)) + ((((v1036 + ((~(((v1038 ^ -1) | (-(v1038 ^ -1))) >> 31)) & 2)) - (v1039 + ((~(((v1040 ^ -1) | (-(v1040 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
        int v1047 = v1045[v1146];
        int * v1048 = v996->mem;
        int v1148 = v1044 * 2;
        v1048[v1148] = v1046;
        int * v1050 = v996->mem;
        int v1151 = (v1044 * 2) + 1;
        v1050[v1151] = v1047;
        ;
      } else {
        ;
      }
      int * v1055 = v996->mem;
      int v1156 = ((int)((unsigned int)((int)((unsigned int)(v1002 + 4) >> 2)) >> 1)) * 2;
      int v1056 = v1055[v1156];
      int v1157 = (((int)((unsigned int)((int)((unsigned int)(v1002 + 4) >> 2)) >> 1)) * 2) + 1;
      int v1057 = v1055[v1157];
      int * v1058 = v996->cache_vals;
      int v1159 = ((4 + ((((int)((unsigned int)((int)((unsigned int)(v1002 + 4) >> 2)) >> 1)) & 3) * 2)) + ((((v1036 + ((~(((v1038 ^ -1) | (-(v1038 ^ -1))) >> 31)) & 2)) - (v1039 + ((~(((v1040 ^ -1) | (-(v1040 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
      v1058[v1159] = v1056;
      int * v1060 = v996->cache_vals;
      int v1162 = (((4 + ((((int)((unsigned int)((int)((unsigned int)(v1002 + 4) >> 2)) >> 1)) & 3) * 2)) + ((((v1036 + ((~(((v1038 ^ -1) | (-(v1038 ^ -1))) >> 31)) & 2)) - (v1039 + ((~(((v1040 ^ -1) | (-(v1040 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
      v1060[v1162] = v1057;
      int * v1062 = v996->cache_tags;
      int v1165 = (int)((unsigned int)((int)((unsigned int)(v1002 + 4) >> 2)) >> 1);
      v1062[v1141] = v1165;
      int * v1064 = v996->cache_dirty;
      v1064[v1141] = 0;
      int * v1066 = v996->cache_age;
      v1066[v1141] = 1;
      int * v1068 = v996->cache_age;
      int v1069 = v1068[v1141];
      int v1070 = v1068[v1116];
      int v1171 = v1070 + ((int)((unsigned int)(v1070 - v1069) >> 31));
      v1068[v1116] = v1171;
      int * v1072 = v996->cache_age;
      int v1073 = v1072[v1117];
      int v1173 = v1073 + ((int)((unsigned int)(v1073 - v1069) >> 31));
      v1072[v1117] = v1173;
      int * v1075 = v996->cache_age;
      v1075[v1141] = 0;
      v1078 = v1141;
    }
    int * v1079 = v996->cache_vals;
    int v1176 = v1078 * 2;
    int v1080 = v1079[v1176];
    int v1177 = (v1078 * 2) + 1;
    int v1081 = v1079[v1177];
    int v1178 = (((((int)((unsigned int)((int)((unsigned int)(v1002 + 4) >> 2)) >> 1)) & 1) * 2) + ((((v1020 + ((~(((v1022 ^ -1) | (-(v1022 ^ -1))) >> 31)) & 2)) - (v1023 + ((~(((v1024 ^ -1) | (-(v1024 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
    v1079[v1178] = v1080;
    int * v1083 = v996->cache_vals;
    int v1181 = ((((((int)((unsigned int)((int)((unsigned int)(v1002 + 4) >> 2)) >> 1)) & 1) * 2) + ((((v1020 + ((~(((v1022 ^ -1) | (-(v1022 ^ -1))) >> 31)) & 2)) - (v1023 + ((~(((v1024 ^ -1) | (-(v1024 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
    v1083[v1181] = v1081;
    int * v1085 = v996->cache_tags;
    int v1184 = ((((int)((unsigned int)((int)((unsigned int)(v1002 + 4) >> 2)) >> 1)) & 1) * 2) + ((((v1020 + ((~(((v1022 ^ -1) | (-(v1022 ^ -1))) >> 31)) & 2)) - (v1023 + ((~(((v1024 ^ -1) | (-(v1024 ^ -1))) >> 31)) & 2))) >> 31) & 1);
    int v1185 = (int)((unsigned int)((int)((unsigned int)(v1002 + 4) >> 2)) >> 1);
    v1085[v1184] = v1185;
    int * v1087 = v996->cache_dirty;
    v1087[v1184] = 0;
    int * v1089 = v996->cache_age;
    v1089[v1184] = 1;
    int * v1091 = v996->cache_age;
    int v1092 = v1091[v1184];
    int v1093 = v1091[v1114];
    int v1191 = v1093 + ((int)((unsigned int)(v1093 - v1092) >> 31));
    v1091[v1114] = v1191;
    int * v1095 = v996->cache_age;
    int v1096 = v1095[v1115];
    int v1193 = v1096 + ((int)((unsigned int)(v1096 - v1092) >> 31));
    v1095[v1115] = v1193;
    int * v1098 = v996->cache_age;
    v1098[v1184] = 0;
    v1101 = v1184;
  }
  int v1196 = (v1101 * 2) + (((int)((unsigned int)(v1002 + 4) >> 2)) & 1);
  int v1102 = v1008[v1196];
  int * v1103 = v996->reg_ready;
  int v1198 = ((v1000 + ((v997 - v1000) & (~((v997 - v1000) >> 31)))) + 1) + ((100 ^ (((~(((v1006 ^ ((int)((unsigned int)((int)((unsigned int)(v1002 + 4) >> 2)) >> 1))) | (-(v1006 ^ ((int)((unsigned int)((int)((unsigned int)(v1002 + 4) >> 2)) >> 1))))) >> 31)) | (~(((v1007 ^ ((int)((unsigned int)((int)((unsigned int)(v1002 + 4) >> 2)) >> 1))) | (-(v1007 ^ ((int)((unsigned int)((int)((unsigned int)(v1002 + 4) >> 2)) >> 1))))) >> 31))) & 104)) ^ (((~(((v1004 ^ ((int)((unsigned int)((int)((unsigned int)(v1002 + 4) >> 2)) >> 1))) | (-(v1004 ^ ((int)((unsigned int)((int)((unsigned int)(v1002 + 4) >> 2)) >> 1))))) >> 31)) | (~(((v1005 ^ ((int)((unsigned int)((int)((unsigned int)(v1002 + 4) >> 2)) >> 1))) | (-(v1005 ^ ((int)((unsigned int)((int)((unsigned int)(v1002 + 4) >> 2)) >> 1))))) >> 31))) & (1 ^ (100 ^ (((~(((v1006 ^ ((int)((unsigned int)((int)((unsigned int)(v1002 + 4) >> 2)) >> 1))) | (-(v1006 ^ ((int)((unsigned int)((int)((unsigned int)(v1002 + 4) >> 2)) >> 1))))) >> 31)) | (~(((v1007 ^ ((int)((unsigned int)((int)((unsigned int)(v1002 + 4) >> 2)) >> 1))) | (-(v1007 ^ ((int)((unsigned int)((int)((unsigned int)(v1002 + 4) >> 2)) >> 1))))) >> 31))) & 104)))));
  v1103[10] = v1198;
  int * v1105 = v996->regs;
  v1105[10] = v1102;
  struct StateT * v1107 = slot_18(v996);
  return v1107;
}

struct StateT * slot_20(struct StateT * v1435) {
  int v1436 = v1435->timer;
  int v1609 = v1436 + 1;
  v1435->timer = v1609;
  int * v1438 = v1435->reg_ready;
  int * v1440 = v1435->regs;
  int v1441 = v1440[11];
  int v1443 = v1440[10];
  int * v1444 = v1435->cache_tags;
  int v1615 = (((int)((unsigned int)((int)((unsigned int)(v1441 + 68) >> 2)) >> 1)) & 1) * 2;
  int v1445 = v1444[v1615];
  int v1616 = ((((int)((unsigned int)((int)((unsigned int)(v1441 + 68) >> 2)) >> 1)) & 1) * 2) + 1;
  int v1446 = v1444[v1616];
  int v1617 = 4 + ((((int)((unsigned int)((int)((unsigned int)(v1441 + 68) >> 2)) >> 1)) & 3) * 2);
  int v1447 = v1444[v1617];
  int v1618 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v1441 + 68) >> 2)) >> 1)) & 3) * 2)) + 1;
  int v1448 = v1444[v1618];
  int v1449 = v1435->timer;
  int v1619 = v1449 + ((100 ^ (((~(((v1447 ^ ((int)((unsigned int)((int)((unsigned int)(v1441 + 68) >> 2)) >> 1))) | (-(v1447 ^ ((int)((unsigned int)((int)((unsigned int)(v1441 + 68) >> 2)) >> 1))))) >> 31)) | (~(((v1448 ^ ((int)((unsigned int)((int)((unsigned int)(v1441 + 68) >> 2)) >> 1))) | (-(v1448 ^ ((int)((unsigned int)((int)((unsigned int)(v1441 + 68) >> 2)) >> 1))))) >> 31))) & 104)) ^ (((~(((v1445 ^ ((int)((unsigned int)((int)((unsigned int)(v1441 + 68) >> 2)) >> 1))) | (-(v1445 ^ ((int)((unsigned int)((int)((unsigned int)(v1441 + 68) >> 2)) >> 1))))) >> 31)) | (~(((v1446 ^ ((int)((unsigned int)((int)((unsigned int)(v1441 + 68) >> 2)) >> 1))) | (-(v1446 ^ ((int)((unsigned int)((int)((unsigned int)(v1441 + 68) >> 2)) >> 1))))) >> 31))) & (1 ^ (100 ^ (((~(((v1447 ^ ((int)((unsigned int)((int)((unsigned int)(v1441 + 68) >> 2)) >> 1))) | (-(v1447 ^ ((int)((unsigned int)((int)((unsigned int)(v1441 + 68) >> 2)) >> 1))))) >> 31)) | (~(((v1448 ^ ((int)((unsigned int)((int)((unsigned int)(v1441 + 68) >> 2)) >> 1))) | (-(v1448 ^ ((int)((unsigned int)((int)((unsigned int)(v1441 + 68) >> 2)) >> 1))))) >> 31))) & 104)))));
  v1435->timer = v1619;
  bool v1620 = !(((~(((v1445 ^ ((int)((unsigned int)((int)((unsigned int)(v1441 + 68) >> 2)) >> 1))) | (-(v1445 ^ ((int)((unsigned int)((int)((unsigned int)(v1441 + 68) >> 2)) >> 1))))) >> 31)) | (~(((v1446 ^ ((int)((unsigned int)((int)((unsigned int)(v1441 + 68) >> 2)) >> 1))) | (-(v1446 ^ ((int)((unsigned int)((int)((unsigned int)(v1441 + 68) >> 2)) >> 1))))) >> 31))) == 0);
  int v1543;
  if (v1620) {
    int * v1451 = v1435->cache_age;
    int v1622 = ((((int)((unsigned int)((int)((unsigned int)(v1441 + 68) >> 2)) >> 1)) & 1) * 2) + ((~(((v1446 ^ ((int)((unsigned int)((int)((unsigned int)(v1441 + 68) >> 2)) >> 1))) | (-(v1446 ^ ((int)((unsigned int)((int)((unsigned int)(v1441 + 68) >> 2)) >> 1))))) >> 31)) & 1);
    int v1452 = v1451[v1622];
    int v1453 = v1451[v1615];
    int v1623 = v1453 + ((int)((unsigned int)(v1453 - v1452) >> 31));
    v1451[v1615] = v1623;
    int * v1455 = v1435->cache_age;
    int v1456 = v1455[v1616];
    int v1625 = v1456 + ((int)((unsigned int)(v1456 - v1452) >> 31));
    v1455[v1616] = v1625;
    int * v1458 = v1435->cache_age;
    v1458[v1622] = 0;
    v1543 = v1622;
  } else {
    int * v1461 = v1435->cache_age;
    int v1629 = (((int)((unsigned int)((int)((unsigned int)(v1441 + 68) >> 2)) >> 1)) & 1) * 2;
    int v1462 = v1461[v1629];
    int * v1463 = v1435->cache_tags;
    int v1464 = v1463[v1629];
    int v1465 = v1461[v1616];
    int v1466 = v1463[v1616];
    bool v1631 = !(((~(((v1447 ^ ((int)((unsigned int)((int)((unsigned int)(v1441 + 68) >> 2)) >> 1))) | (-(v1447 ^ ((int)((unsigned int)((int)((unsigned int)(v1441 + 68) >> 2)) >> 1))))) >> 31)) | (~(((v1448 ^ ((int)((unsigned int)((int)((unsigned int)(v1441 + 68) >> 2)) >> 1))) | (-(v1448 ^ ((int)((unsigned int)((int)((unsigned int)(v1441 + 68) >> 2)) >> 1))))) >> 31))) == 0);
    int v1520;
    if (v1631) {
      int * v1467 = v1435->cache_age;
      int v1633 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v1441 + 68) >> 2)) >> 1)) & 3) * 2)) + ((~(((v1448 ^ ((int)((unsigned int)((int)((unsigned int)(v1441 + 68) >> 2)) >> 1))) | (-(v1448 ^ ((int)((unsigned int)((int)((unsigned int)(v1441 + 68) >> 2)) >> 1))))) >> 31)) & 1);
      int v1468 = v1467[v1633];
      int v1469 = v1467[v1617];
      int v1634 = v1469 + ((int)((unsigned int)(v1469 - v1468) >> 31));
      v1467[v1617] = v1634;
      int * v1471 = v1435->cache_age;
      int v1472 = v1471[v1618];
      int v1636 = v1472 + ((int)((unsigned int)(v1472 - v1468) >> 31));
      v1471[v1618] = v1636;
      int * v1474 = v1435->cache_age;
      v1474[v1633] = 0;
      v1520 = v1633;
    } else {
      int * v1477 = v1435->cache_age;
      int v1640 = 4 + ((((int)((unsigned int)((int)((unsigned int)(v1441 + 68) >> 2)) >> 1)) & 3) * 2);
      int v1478 = v1477[v1640];
      int * v1479 = v1435->cache_tags;
      int v1480 = v1479[v1640];
      int v1481 = v1477[v1618];
      int v1482 = v1479[v1618];
      int * v1483 = v1435->cache_dirty;
      int v1643 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v1441 + 68) >> 2)) >> 1)) & 3) * 2)) + ((((v1478 + ((~(((v1480 ^ -1) | (-(v1480 ^ -1))) >> 31)) & 2)) - (v1481 + ((~(((v1482 ^ -1) | (-(v1482 ^ -1))) >> 31)) & 2))) >> 31) & 1);
      int v1484 = v1483[v1643];
      bool v1644 = !(v1484 == 0);
      if (v1644) {
        int * v1485 = v1435->cache_tags;
        int v1486 = v1485[v1643];
        int * v1487 = v1435->cache_vals;
        int v1647 = ((4 + ((((int)((unsigned int)((int)((unsigned int)(v1441 + 68) >> 2)) >> 1)) & 3) * 2)) + ((((v1478 + ((~(((v1480 ^ -1) | (-(v1480 ^ -1))) >> 31)) & 2)) - (v1481 + ((~(((v1482 ^ -1) | (-(v1482 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
        int v1488 = v1487[v1647];
        int v1648 = (((4 + ((((int)((unsigned int)((int)((unsigned int)(v1441 + 68) >> 2)) >> 1)) & 3) * 2)) + ((((v1478 + ((~(((v1480 ^ -1) | (-(v1480 ^ -1))) >> 31)) & 2)) - (v1481 + ((~(((v1482 ^ -1) | (-(v1482 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
        int v1489 = v1487[v1648];
        int * v1490 = v1435->mem;
        int v1650 = v1486 * 2;
        v1490[v1650] = v1488;
        int * v1492 = v1435->mem;
        int v1653 = (v1486 * 2) + 1;
        v1492[v1653] = v1489;
        ;
      } else {
        ;
      }
      int * v1497 = v1435->mem;
      int v1658 = ((int)((unsigned int)((int)((unsigned int)(v1441 + 68) >> 2)) >> 1)) * 2;
      int v1498 = v1497[v1658];
      int v1659 = (((int)((unsigned int)((int)((unsigned int)(v1441 + 68) >> 2)) >> 1)) * 2) + 1;
      int v1499 = v1497[v1659];
      int * v1500 = v1435->cache_vals;
      int v1661 = ((4 + ((((int)((unsigned int)((int)((unsigned int)(v1441 + 68) >> 2)) >> 1)) & 3) * 2)) + ((((v1478 + ((~(((v1480 ^ -1) | (-(v1480 ^ -1))) >> 31)) & 2)) - (v1481 + ((~(((v1482 ^ -1) | (-(v1482 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
      v1500[v1661] = v1498;
      int * v1502 = v1435->cache_vals;
      int v1664 = (((4 + ((((int)((unsigned int)((int)((unsigned int)(v1441 + 68) >> 2)) >> 1)) & 3) * 2)) + ((((v1478 + ((~(((v1480 ^ -1) | (-(v1480 ^ -1))) >> 31)) & 2)) - (v1481 + ((~(((v1482 ^ -1) | (-(v1482 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
      v1502[v1664] = v1499;
      int * v1504 = v1435->cache_tags;
      int v1667 = (int)((unsigned int)((int)((unsigned int)(v1441 + 68) >> 2)) >> 1);
      v1504[v1643] = v1667;
      int * v1506 = v1435->cache_dirty;
      v1506[v1643] = 0;
      int * v1508 = v1435->cache_age;
      v1508[v1643] = 1;
      int * v1510 = v1435->cache_age;
      int v1511 = v1510[v1643];
      int v1512 = v1510[v1617];
      int v1673 = v1512 + ((int)((unsigned int)(v1512 - v1511) >> 31));
      v1510[v1617] = v1673;
      int * v1514 = v1435->cache_age;
      int v1515 = v1514[v1618];
      int v1675 = v1515 + ((int)((unsigned int)(v1515 - v1511) >> 31));
      v1514[v1618] = v1675;
      int * v1517 = v1435->cache_age;
      v1517[v1643] = 0;
      v1520 = v1643;
    }
    int * v1521 = v1435->cache_vals;
    int v1678 = v1520 * 2;
    int v1522 = v1521[v1678];
    int v1679 = (v1520 * 2) + 1;
    int v1523 = v1521[v1679];
    int v1680 = (((((int)((unsigned int)((int)((unsigned int)(v1441 + 68) >> 2)) >> 1)) & 1) * 2) + ((((v1462 + ((~(((v1464 ^ -1) | (-(v1464 ^ -1))) >> 31)) & 2)) - (v1465 + ((~(((v1466 ^ -1) | (-(v1466 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
    v1521[v1680] = v1522;
    int * v1525 = v1435->cache_vals;
    int v1683 = ((((((int)((unsigned int)((int)((unsigned int)(v1441 + 68) >> 2)) >> 1)) & 1) * 2) + ((((v1462 + ((~(((v1464 ^ -1) | (-(v1464 ^ -1))) >> 31)) & 2)) - (v1465 + ((~(((v1466 ^ -1) | (-(v1466 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
    v1525[v1683] = v1523;
    int * v1527 = v1435->cache_tags;
    int v1686 = ((((int)((unsigned int)((int)((unsigned int)(v1441 + 68) >> 2)) >> 1)) & 1) * 2) + ((((v1462 + ((~(((v1464 ^ -1) | (-(v1464 ^ -1))) >> 31)) & 2)) - (v1465 + ((~(((v1466 ^ -1) | (-(v1466 ^ -1))) >> 31)) & 2))) >> 31) & 1);
    int v1687 = (int)((unsigned int)((int)((unsigned int)(v1441 + 68) >> 2)) >> 1);
    v1527[v1686] = v1687;
    int * v1529 = v1435->cache_dirty;
    v1529[v1686] = 0;
    int * v1531 = v1435->cache_age;
    v1531[v1686] = 1;
    int * v1533 = v1435->cache_age;
    int v1534 = v1533[v1686];
    int v1535 = v1533[v1615];
    int v1693 = v1535 + ((int)((unsigned int)(v1535 - v1534) >> 31));
    v1533[v1615] = v1693;
    int * v1537 = v1435->cache_age;
    int v1538 = v1537[v1616];
    int v1695 = v1538 + ((int)((unsigned int)(v1538 - v1534) >> 31));
    v1537[v1616] = v1695;
    int * v1540 = v1435->cache_age;
    v1540[v1686] = 0;
    v1543 = v1686;
  }
  int * v1544 = v1435->cache_vals;
  int v1698 = (v1543 * 2) + (((int)((unsigned int)(v1441 + 68) >> 2)) & 1);
  v1544[v1698] = v1443;
  int * v1546 = v1435->cache_tags;
  int v1547 = v1546[v1617];
  int v1548 = v1546[v1618];
  bool v1701 = !(((~(((v1547 ^ ((int)((unsigned int)((int)((unsigned int)(v1441 + 68) >> 2)) >> 1))) | (-(v1547 ^ ((int)((unsigned int)((int)((unsigned int)(v1441 + 68) >> 2)) >> 1))))) >> 31)) | (~(((v1548 ^ ((int)((unsigned int)((int)((unsigned int)(v1441 + 68) >> 2)) >> 1))) | (-(v1548 ^ ((int)((unsigned int)((int)((unsigned int)(v1441 + 68) >> 2)) >> 1))))) >> 31))) == 0);
  int v1602;
  if (v1701) {
    int * v1549 = v1435->cache_age;
    int v1703 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v1441 + 68) >> 2)) >> 1)) & 3) * 2)) + ((~(((v1548 ^ ((int)((unsigned int)((int)((unsigned int)(v1441 + 68) >> 2)) >> 1))) | (-(v1548 ^ ((int)((unsigned int)((int)((unsigned int)(v1441 + 68) >> 2)) >> 1))))) >> 31)) & 1);
    int v1550 = v1549[v1703];
    int v1551 = v1549[v1617];
    int v1704 = v1551 + ((int)((unsigned int)(v1551 - v1550) >> 31));
    v1549[v1617] = v1704;
    int * v1553 = v1435->cache_age;
    int v1554 = v1553[v1618];
    int v1706 = v1554 + ((int)((unsigned int)(v1554 - v1550) >> 31));
    v1553[v1618] = v1706;
    int * v1556 = v1435->cache_age;
    v1556[v1703] = 0;
    v1602 = v1703;
  } else {
    int * v1559 = v1435->cache_age;
    int v1710 = 4 + ((((int)((unsigned int)((int)((unsigned int)(v1441 + 68) >> 2)) >> 1)) & 3) * 2);
    int v1560 = v1559[v1710];
    int * v1561 = v1435->cache_tags;
    int v1562 = v1561[v1710];
    int v1563 = v1559[v1618];
    int v1564 = v1561[v1618];
    int * v1565 = v1435->cache_dirty;
    int v1713 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v1441 + 68) >> 2)) >> 1)) & 3) * 2)) + ((((v1560 + ((~(((v1562 ^ -1) | (-(v1562 ^ -1))) >> 31)) & 2)) - (v1563 + ((~(((v1564 ^ -1) | (-(v1564 ^ -1))) >> 31)) & 2))) >> 31) & 1);
    int v1566 = v1565[v1713];
    bool v1714 = !(v1566 == 0);
    if (v1714) {
      int * v1567 = v1435->cache_tags;
      int v1568 = v1567[v1713];
      int * v1569 = v1435->cache_vals;
      int v1717 = ((4 + ((((int)((unsigned int)((int)((unsigned int)(v1441 + 68) >> 2)) >> 1)) & 3) * 2)) + ((((v1560 + ((~(((v1562 ^ -1) | (-(v1562 ^ -1))) >> 31)) & 2)) - (v1563 + ((~(((v1564 ^ -1) | (-(v1564 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
      int v1570 = v1569[v1717];
      int v1718 = (((4 + ((((int)((unsigned int)((int)((unsigned int)(v1441 + 68) >> 2)) >> 1)) & 3) * 2)) + ((((v1560 + ((~(((v1562 ^ -1) | (-(v1562 ^ -1))) >> 31)) & 2)) - (v1563 + ((~(((v1564 ^ -1) | (-(v1564 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
      int v1571 = v1569[v1718];
      int * v1572 = v1435->mem;
      int v1720 = v1568 * 2;
      v1572[v1720] = v1570;
      int * v1574 = v1435->mem;
      int v1723 = (v1568 * 2) + 1;
      v1574[v1723] = v1571;
      ;
    } else {
      ;
    }
    int * v1579 = v1435->mem;
    int v1728 = ((int)((unsigned int)((int)((unsigned int)(v1441 + 68) >> 2)) >> 1)) * 2;
    int v1580 = v1579[v1728];
    int v1729 = (((int)((unsigned int)((int)((unsigned int)(v1441 + 68) >> 2)) >> 1)) * 2) + 1;
    int v1581 = v1579[v1729];
    int * v1582 = v1435->cache_vals;
    int v1731 = ((4 + ((((int)((unsigned int)((int)((unsigned int)(v1441 + 68) >> 2)) >> 1)) & 3) * 2)) + ((((v1560 + ((~(((v1562 ^ -1) | (-(v1562 ^ -1))) >> 31)) & 2)) - (v1563 + ((~(((v1564 ^ -1) | (-(v1564 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
    v1582[v1731] = v1580;
    int * v1584 = v1435->cache_vals;
    int v1734 = (((4 + ((((int)((unsigned int)((int)((unsigned int)(v1441 + 68) >> 2)) >> 1)) & 3) * 2)) + ((((v1560 + ((~(((v1562 ^ -1) | (-(v1562 ^ -1))) >> 31)) & 2)) - (v1563 + ((~(((v1564 ^ -1) | (-(v1564 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
    v1584[v1734] = v1581;
    int * v1586 = v1435->cache_tags;
    int v1737 = (int)((unsigned int)((int)((unsigned int)(v1441 + 68) >> 2)) >> 1);
    v1586[v1713] = v1737;
    int * v1588 = v1435->cache_dirty;
    v1588[v1713] = 0;
    int * v1590 = v1435->cache_age;
    v1590[v1713] = 1;
    int * v1592 = v1435->cache_age;
    int v1593 = v1592[v1713];
    int v1594 = v1592[v1617];
    int v1743 = v1594 + ((int)((unsigned int)(v1594 - v1593) >> 31));
    v1592[v1617] = v1743;
    int * v1596 = v1435->cache_age;
    int v1597 = v1596[v1618];
    int v1745 = v1597 + ((int)((unsigned int)(v1597 - v1593) >> 31));
    v1596[v1618] = v1745;
    int * v1599 = v1435->cache_age;
    v1599[v1713] = 0;
    v1602 = v1713;
  }
  int * v1603 = v1435->cache_vals;
  int v1748 = (v1602 * 2) + (((int)((unsigned int)(v1441 + 68) >> 2)) & 1);
  v1603[v1748] = v1443;
  int * v1605 = v1435->cache_dirty;
  v1605[v1602] = 1;
  struct StateT * v1607 = slot_21(v1435);
  return v1607;
}

struct StateT * slot_2(struct StateT * v225) {
  int v226 = v225->timer;
  int v230 = v226 + 1;
  v225->timer = v230;
  struct StateT * v228 = slot_3(v225);
  return v228;
}

struct StateT * slot_7(struct StateT * v471) {
  int v472 = v471->timer;
  int v480 = v472 + 1;
  v471->timer = v480;
  int * v474 = v471->reg_ready;
  v474[12] = v480;
  int * v476 = v471->regs;
  v476[12] = 0;
  struct StateT * v478 = slot_8(v471);
  return v478;
}

struct StateT * slot_21(struct StateT * v1754) {
  int v1755 = v1754->timer;
  int v1758 = v1755 + 1;
  v1754->timer = v1758;
  return v1754;
}

struct StateT * slot_3(struct StateT * v233) {
  int * v234 = v233->regs;
  int v235 = v234[10];
  int v236 = v234[12];
  bool v344 = (v235 ^ -2147483648) >= (v236 ^ -2147483648);
  struct StateT * v339;
  if (v344) {
    int v237 = v233->timer;
    int v345 = v237 + 15;
    v233->timer = v345;
    int * v239 = v233->reg_ready;
    int v240 = v233->timer;
    v239[0] = v240;
    int * v242 = v233->reg_ready;
    int v243 = v233->timer;
    v242[1] = v243;
    int * v245 = v233->reg_ready;
    int v246 = v233->timer;
    v245[2] = v246;
    int * v248 = v233->reg_ready;
    int v249 = v233->timer;
    v248[3] = v249;
    int * v251 = v233->reg_ready;
    int v252 = v233->timer;
    v251[4] = v252;
    int * v254 = v233->reg_ready;
    int v255 = v233->timer;
    v254[5] = v255;
    int * v257 = v233->reg_ready;
    int v258 = v233->timer;
    v257[6] = v258;
    int * v260 = v233->reg_ready;
    int v261 = v233->timer;
    v260[7] = v261;
    int * v263 = v233->reg_ready;
    int v264 = v233->timer;
    v263[8] = v264;
    int * v266 = v233->reg_ready;
    int v267 = v233->timer;
    v266[9] = v267;
    int * v269 = v233->reg_ready;
    int v270 = v233->timer;
    v269[10] = v270;
    int * v272 = v233->reg_ready;
    int v273 = v233->timer;
    v272[11] = v273;
    int * v275 = v233->reg_ready;
    int v276 = v233->timer;
    v275[12] = v276;
    int * v278 = v233->reg_ready;
    int v279 = v233->timer;
    v278[13] = v279;
    int * v281 = v233->reg_ready;
    int v282 = v233->timer;
    v281[14] = v282;
    int * v284 = v233->reg_ready;
    int v285 = v233->timer;
    v284[15] = v285;
    int * v287 = v233->reg_ready;
    int v288 = v233->timer;
    v287[16] = v288;
    int * v290 = v233->reg_ready;
    int v291 = v233->timer;
    v290[17] = v291;
    int * v293 = v233->reg_ready;
    int v294 = v233->timer;
    v293[18] = v294;
    int * v296 = v233->reg_ready;
    int v297 = v233->timer;
    v296[19] = v297;
    int * v299 = v233->reg_ready;
    int v300 = v233->timer;
    v299[20] = v300;
    int * v302 = v233->reg_ready;
    int v303 = v233->timer;
    v302[21] = v303;
    int * v305 = v233->reg_ready;
    int v306 = v233->timer;
    v305[22] = v306;
    int * v308 = v233->reg_ready;
    int v309 = v233->timer;
    v308[23] = v309;
    int * v311 = v233->reg_ready;
    int v312 = v233->timer;
    v311[24] = v312;
    int * v314 = v233->reg_ready;
    int v315 = v233->timer;
    v314[25] = v315;
    int * v317 = v233->reg_ready;
    int v318 = v233->timer;
    v317[26] = v318;
    int * v320 = v233->reg_ready;
    int v321 = v233->timer;
    v320[27] = v321;
    int * v323 = v233->reg_ready;
    int v324 = v233->timer;
    v323[28] = v324;
    int * v326 = v233->reg_ready;
    int v327 = v233->timer;
    v326[29] = v327;
    int * v329 = v233->reg_ready;
    int v330 = v233->timer;
    v329[30] = v330;
    int * v332 = v233->reg_ready;
    int v333 = v233->timer;
    v332[31] = v333;
    struct StateT * v335 = slot_21(v233);
    v339 = v335;
  } else {
    struct StateT * v337 = slot_5(v233);
    v339 = v337;
  }
  return v339;
}

struct StateT * snippet(struct StateT * v0) {
  struct StateT * v1 = slot_0(v0);
  int v1759 = v1->timer;
  int * v1760 = v1->reg_ready;
  int v1761 = v1760[0];
  int v1892 = v1761 + ((v1759 - v1761) & (~((v1759 - v1761) >> 31)));
  v1->timer = v1892;
  int v1763 = v1->timer;
  int * v1764 = v1->reg_ready;
  int v1765 = v1764[1];
  int v1895 = v1765 + ((v1763 - v1765) & (~((v1763 - v1765) >> 31)));
  v1->timer = v1895;
  int v1767 = v1->timer;
  int * v1768 = v1->reg_ready;
  int v1769 = v1768[2];
  int v1898 = v1769 + ((v1767 - v1769) & (~((v1767 - v1769) >> 31)));
  v1->timer = v1898;
  int v1771 = v1->timer;
  int * v1772 = v1->reg_ready;
  int v1773 = v1772[3];
  int v1901 = v1773 + ((v1771 - v1773) & (~((v1771 - v1773) >> 31)));
  v1->timer = v1901;
  int v1775 = v1->timer;
  int * v1776 = v1->reg_ready;
  int v1777 = v1776[4];
  int v1904 = v1777 + ((v1775 - v1777) & (~((v1775 - v1777) >> 31)));
  v1->timer = v1904;
  int v1779 = v1->timer;
  int * v1780 = v1->reg_ready;
  int v1781 = v1780[5];
  int v1907 = v1781 + ((v1779 - v1781) & (~((v1779 - v1781) >> 31)));
  v1->timer = v1907;
  int v1783 = v1->timer;
  int * v1784 = v1->reg_ready;
  int v1785 = v1784[6];
  int v1910 = v1785 + ((v1783 - v1785) & (~((v1783 - v1785) >> 31)));
  v1->timer = v1910;
  int v1787 = v1->timer;
  int * v1788 = v1->reg_ready;
  int v1789 = v1788[7];
  int v1913 = v1789 + ((v1787 - v1789) & (~((v1787 - v1789) >> 31)));
  v1->timer = v1913;
  int v1791 = v1->timer;
  int * v1792 = v1->reg_ready;
  int v1793 = v1792[8];
  int v1916 = v1793 + ((v1791 - v1793) & (~((v1791 - v1793) >> 31)));
  v1->timer = v1916;
  int v1795 = v1->timer;
  int * v1796 = v1->reg_ready;
  int v1797 = v1796[9];
  int v1919 = v1797 + ((v1795 - v1797) & (~((v1795 - v1797) >> 31)));
  v1->timer = v1919;
  int v1799 = v1->timer;
  int * v1800 = v1->reg_ready;
  int v1801 = v1800[10];
  int v1922 = v1801 + ((v1799 - v1801) & (~((v1799 - v1801) >> 31)));
  v1->timer = v1922;
  int v1803 = v1->timer;
  int * v1804 = v1->reg_ready;
  int v1805 = v1804[11];
  int v1925 = v1805 + ((v1803 - v1805) & (~((v1803 - v1805) >> 31)));
  v1->timer = v1925;
  int v1807 = v1->timer;
  int * v1808 = v1->reg_ready;
  int v1809 = v1808[12];
  int v1928 = v1809 + ((v1807 - v1809) & (~((v1807 - v1809) >> 31)));
  v1->timer = v1928;
  int v1811 = v1->timer;
  int * v1812 = v1->reg_ready;
  int v1813 = v1812[13];
  int v1931 = v1813 + ((v1811 - v1813) & (~((v1811 - v1813) >> 31)));
  v1->timer = v1931;
  int v1815 = v1->timer;
  int * v1816 = v1->reg_ready;
  int v1817 = v1816[14];
  int v1934 = v1817 + ((v1815 - v1817) & (~((v1815 - v1817) >> 31)));
  v1->timer = v1934;
  int v1819 = v1->timer;
  int * v1820 = v1->reg_ready;
  int v1821 = v1820[15];
  int v1937 = v1821 + ((v1819 - v1821) & (~((v1819 - v1821) >> 31)));
  v1->timer = v1937;
  int v1823 = v1->timer;
  int * v1824 = v1->reg_ready;
  int v1825 = v1824[16];
  int v1940 = v1825 + ((v1823 - v1825) & (~((v1823 - v1825) >> 31)));
  v1->timer = v1940;
  int v1827 = v1->timer;
  int * v1828 = v1->reg_ready;
  int v1829 = v1828[17];
  int v1943 = v1829 + ((v1827 - v1829) & (~((v1827 - v1829) >> 31)));
  v1->timer = v1943;
  int v1831 = v1->timer;
  int * v1832 = v1->reg_ready;
  int v1833 = v1832[18];
  int v1946 = v1833 + ((v1831 - v1833) & (~((v1831 - v1833) >> 31)));
  v1->timer = v1946;
  int v1835 = v1->timer;
  int * v1836 = v1->reg_ready;
  int v1837 = v1836[19];
  int v1949 = v1837 + ((v1835 - v1837) & (~((v1835 - v1837) >> 31)));
  v1->timer = v1949;
  int v1839 = v1->timer;
  int * v1840 = v1->reg_ready;
  int v1841 = v1840[20];
  int v1952 = v1841 + ((v1839 - v1841) & (~((v1839 - v1841) >> 31)));
  v1->timer = v1952;
  int v1843 = v1->timer;
  int * v1844 = v1->reg_ready;
  int v1845 = v1844[21];
  int v1955 = v1845 + ((v1843 - v1845) & (~((v1843 - v1845) >> 31)));
  v1->timer = v1955;
  int v1847 = v1->timer;
  int * v1848 = v1->reg_ready;
  int v1849 = v1848[22];
  int v1958 = v1849 + ((v1847 - v1849) & (~((v1847 - v1849) >> 31)));
  v1->timer = v1958;
  int v1851 = v1->timer;
  int * v1852 = v1->reg_ready;
  int v1853 = v1852[23];
  int v1961 = v1853 + ((v1851 - v1853) & (~((v1851 - v1853) >> 31)));
  v1->timer = v1961;
  int v1855 = v1->timer;
  int * v1856 = v1->reg_ready;
  int v1857 = v1856[24];
  int v1964 = v1857 + ((v1855 - v1857) & (~((v1855 - v1857) >> 31)));
  v1->timer = v1964;
  int v1859 = v1->timer;
  int * v1860 = v1->reg_ready;
  int v1861 = v1860[25];
  int v1967 = v1861 + ((v1859 - v1861) & (~((v1859 - v1861) >> 31)));
  v1->timer = v1967;
  int v1863 = v1->timer;
  int * v1864 = v1->reg_ready;
  int v1865 = v1864[26];
  int v1970 = v1865 + ((v1863 - v1865) & (~((v1863 - v1865) >> 31)));
  v1->timer = v1970;
  int v1867 = v1->timer;
  int * v1868 = v1->reg_ready;
  int v1869 = v1868[27];
  int v1973 = v1869 + ((v1867 - v1869) & (~((v1867 - v1869) >> 31)));
  v1->timer = v1973;
  int v1871 = v1->timer;
  int * v1872 = v1->reg_ready;
  int v1873 = v1872[28];
  int v1976 = v1873 + ((v1871 - v1873) & (~((v1871 - v1873) >> 31)));
  v1->timer = v1976;
  int v1875 = v1->timer;
  int * v1876 = v1->reg_ready;
  int v1877 = v1876[29];
  int v1979 = v1877 + ((v1875 - v1877) & (~((v1875 - v1877) >> 31)));
  v1->timer = v1979;
  int v1879 = v1->timer;
  int * v1880 = v1->reg_ready;
  int v1881 = v1880[30];
  int v1982 = v1881 + ((v1879 - v1881) & (~((v1879 - v1881) >> 31)));
  v1->timer = v1982;
  int v1883 = v1->timer;
  int * v1884 = v1->reg_ready;
  int v1885 = v1884[31];
  int v1985 = v1885 + ((v1883 - v1885) & (~((v1883 - v1885) >> 31)));
  v1->timer = v1985;
  return v1;
}

struct StateT * slot_10(struct StateT * v532) {
  int v533 = v532->timer;
  int v645 = v533 + 1;
  v532->timer = v645;
  int * v535 = v532->reg_ready;
  int v536 = v535[10];
  int * v537 = v532->regs;
  int v538 = v537[10];
  int * v539 = v532->cache_tags;
  int v650 = (((int)((unsigned int)((int)((unsigned int)v538 >> 2)) >> 1)) & 1) * 2;
  int v540 = v539[v650];
  int v651 = ((((int)((unsigned int)((int)((unsigned int)v538 >> 2)) >> 1)) & 1) * 2) + 1;
  int v541 = v539[v651];
  int v652 = 4 + ((((int)((unsigned int)((int)((unsigned int)v538 >> 2)) >> 1)) & 3) * 2);
  int v542 = v539[v652];
  int v653 = (4 + ((((int)((unsigned int)((int)((unsigned int)v538 >> 2)) >> 1)) & 3) * 2)) + 1;
  int v543 = v539[v653];
  int * v544 = v532->cache_vals;
  bool v654 = !(((~(((v540 ^ ((int)((unsigned int)((int)((unsigned int)v538 >> 2)) >> 1))) | (-(v540 ^ ((int)((unsigned int)((int)((unsigned int)v538 >> 2)) >> 1))))) >> 31)) | (~(((v541 ^ ((int)((unsigned int)((int)((unsigned int)v538 >> 2)) >> 1))) | (-(v541 ^ ((int)((unsigned int)((int)((unsigned int)v538 >> 2)) >> 1))))) >> 31))) == 0);
  int v637;
  if (v654) {
    int * v545 = v532->cache_age;
    int v656 = ((((int)((unsigned int)((int)((unsigned int)v538 >> 2)) >> 1)) & 1) * 2) + ((~(((v541 ^ ((int)((unsigned int)((int)((unsigned int)v538 >> 2)) >> 1))) | (-(v541 ^ ((int)((unsigned int)((int)((unsigned int)v538 >> 2)) >> 1))))) >> 31)) & 1);
    int v546 = v545[v656];
    int v547 = v545[v650];
    int v657 = v547 + ((int)((unsigned int)(v547 - v546) >> 31));
    v545[v650] = v657;
    int * v549 = v532->cache_age;
    int v550 = v549[v651];
    int v659 = v550 + ((int)((unsigned int)(v550 - v546) >> 31));
    v549[v651] = v659;
    int * v552 = v532->cache_age;
    v552[v656] = 0;
    v637 = v656;
  } else {
    int * v555 = v532->cache_age;
    int v663 = (((int)((unsigned int)((int)((unsigned int)v538 >> 2)) >> 1)) & 1) * 2;
    int v556 = v555[v663];
    int * v557 = v532->cache_tags;
    int v558 = v557[v663];
    int v559 = v555[v651];
    int v560 = v557[v651];
    bool v665 = !(((~(((v542 ^ ((int)((unsigned int)((int)((unsigned int)v538 >> 2)) >> 1))) | (-(v542 ^ ((int)((unsigned int)((int)((unsigned int)v538 >> 2)) >> 1))))) >> 31)) | (~(((v543 ^ ((int)((unsigned int)((int)((unsigned int)v538 >> 2)) >> 1))) | (-(v543 ^ ((int)((unsigned int)((int)((unsigned int)v538 >> 2)) >> 1))))) >> 31))) == 0);
    int v614;
    if (v665) {
      int * v561 = v532->cache_age;
      int v667 = (4 + ((((int)((unsigned int)((int)((unsigned int)v538 >> 2)) >> 1)) & 3) * 2)) + ((~(((v543 ^ ((int)((unsigned int)((int)((unsigned int)v538 >> 2)) >> 1))) | (-(v543 ^ ((int)((unsigned int)((int)((unsigned int)v538 >> 2)) >> 1))))) >> 31)) & 1);
      int v562 = v561[v667];
      int v563 = v561[v652];
      int v668 = v563 + ((int)((unsigned int)(v563 - v562) >> 31));
      v561[v652] = v668;
      int * v565 = v532->cache_age;
      int v566 = v565[v653];
      int v670 = v566 + ((int)((unsigned int)(v566 - v562) >> 31));
      v565[v653] = v670;
      int * v568 = v532->cache_age;
      v568[v667] = 0;
      v614 = v667;
    } else {
      int * v571 = v532->cache_age;
      int v674 = 4 + ((((int)((unsigned int)((int)((unsigned int)v538 >> 2)) >> 1)) & 3) * 2);
      int v572 = v571[v674];
      int * v573 = v532->cache_tags;
      int v574 = v573[v674];
      int v575 = v571[v653];
      int v576 = v573[v653];
      int * v577 = v532->cache_dirty;
      int v677 = (4 + ((((int)((unsigned int)((int)((unsigned int)v538 >> 2)) >> 1)) & 3) * 2)) + ((((v572 + ((~(((v574 ^ -1) | (-(v574 ^ -1))) >> 31)) & 2)) - (v575 + ((~(((v576 ^ -1) | (-(v576 ^ -1))) >> 31)) & 2))) >> 31) & 1);
      int v578 = v577[v677];
      bool v678 = !(v578 == 0);
      if (v678) {
        int * v579 = v532->cache_tags;
        int v580 = v579[v677];
        int * v581 = v532->cache_vals;
        int v681 = ((4 + ((((int)((unsigned int)((int)((unsigned int)v538 >> 2)) >> 1)) & 3) * 2)) + ((((v572 + ((~(((v574 ^ -1) | (-(v574 ^ -1))) >> 31)) & 2)) - (v575 + ((~(((v576 ^ -1) | (-(v576 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
        int v582 = v581[v681];
        int v682 = (((4 + ((((int)((unsigned int)((int)((unsigned int)v538 >> 2)) >> 1)) & 3) * 2)) + ((((v572 + ((~(((v574 ^ -1) | (-(v574 ^ -1))) >> 31)) & 2)) - (v575 + ((~(((v576 ^ -1) | (-(v576 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
        int v583 = v581[v682];
        int * v584 = v532->mem;
        int v684 = v580 * 2;
        v584[v684] = v582;
        int * v586 = v532->mem;
        int v687 = (v580 * 2) + 1;
        v586[v687] = v583;
        ;
      } else {
        ;
      }
      int * v591 = v532->mem;
      int v692 = ((int)((unsigned int)((int)((unsigned int)v538 >> 2)) >> 1)) * 2;
      int v592 = v591[v692];
      int v693 = (((int)((unsigned int)((int)((unsigned int)v538 >> 2)) >> 1)) * 2) + 1;
      int v593 = v591[v693];
      int * v594 = v532->cache_vals;
      int v695 = ((4 + ((((int)((unsigned int)((int)((unsigned int)v538 >> 2)) >> 1)) & 3) * 2)) + ((((v572 + ((~(((v574 ^ -1) | (-(v574 ^ -1))) >> 31)) & 2)) - (v575 + ((~(((v576 ^ -1) | (-(v576 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
      v594[v695] = v592;
      int * v596 = v532->cache_vals;
      int v698 = (((4 + ((((int)((unsigned int)((int)((unsigned int)v538 >> 2)) >> 1)) & 3) * 2)) + ((((v572 + ((~(((v574 ^ -1) | (-(v574 ^ -1))) >> 31)) & 2)) - (v575 + ((~(((v576 ^ -1) | (-(v576 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
      v596[v698] = v593;
      int * v598 = v532->cache_tags;
      int v701 = (int)((unsigned int)((int)((unsigned int)v538 >> 2)) >> 1);
      v598[v677] = v701;
      int * v600 = v532->cache_dirty;
      v600[v677] = 0;
      int * v602 = v532->cache_age;
      v602[v677] = 1;
      int * v604 = v532->cache_age;
      int v605 = v604[v677];
      int v606 = v604[v652];
      int v707 = v606 + ((int)((unsigned int)(v606 - v605) >> 31));
      v604[v652] = v707;
      int * v608 = v532->cache_age;
      int v609 = v608[v653];
      int v709 = v609 + ((int)((unsigned int)(v609 - v605) >> 31));
      v608[v653] = v709;
      int * v611 = v532->cache_age;
      v611[v677] = 0;
      v614 = v677;
    }
    int * v615 = v532->cache_vals;
    int v712 = v614 * 2;
    int v616 = v615[v712];
    int v713 = (v614 * 2) + 1;
    int v617 = v615[v713];
    int v714 = (((((int)((unsigned int)((int)((unsigned int)v538 >> 2)) >> 1)) & 1) * 2) + ((((v556 + ((~(((v558 ^ -1) | (-(v558 ^ -1))) >> 31)) & 2)) - (v559 + ((~(((v560 ^ -1) | (-(v560 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
    v615[v714] = v616;
    int * v619 = v532->cache_vals;
    int v717 = ((((((int)((unsigned int)((int)((unsigned int)v538 >> 2)) >> 1)) & 1) * 2) + ((((v556 + ((~(((v558 ^ -1) | (-(v558 ^ -1))) >> 31)) & 2)) - (v559 + ((~(((v560 ^ -1) | (-(v560 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
    v619[v717] = v617;
    int * v621 = v532->cache_tags;
    int v720 = ((((int)((unsigned int)((int)((unsigned int)v538 >> 2)) >> 1)) & 1) * 2) + ((((v556 + ((~(((v558 ^ -1) | (-(v558 ^ -1))) >> 31)) & 2)) - (v559 + ((~(((v560 ^ -1) | (-(v560 ^ -1))) >> 31)) & 2))) >> 31) & 1);
    int v721 = (int)((unsigned int)((int)((unsigned int)v538 >> 2)) >> 1);
    v621[v720] = v721;
    int * v623 = v532->cache_dirty;
    v623[v720] = 0;
    int * v625 = v532->cache_age;
    v625[v720] = 1;
    int * v627 = v532->cache_age;
    int v628 = v627[v720];
    int v629 = v627[v650];
    int v727 = v629 + ((int)((unsigned int)(v629 - v628) >> 31));
    v627[v650] = v727;
    int * v631 = v532->cache_age;
    int v632 = v631[v651];
    int v729 = v632 + ((int)((unsigned int)(v632 - v628) >> 31));
    v631[v651] = v729;
    int * v634 = v532->cache_age;
    v634[v720] = 0;
    v637 = v720;
  }
  int v732 = (v637 * 2) + (((int)((unsigned int)v538 >> 2)) & 1);
  int v638 = v544[v732];
  int * v639 = v532->reg_ready;
  int v734 = ((v536 + ((v533 - v536) & (~((v533 - v536) >> 31)))) + 1) + ((100 ^ (((~(((v542 ^ ((int)((unsigned int)((int)((unsigned int)v538 >> 2)) >> 1))) | (-(v542 ^ ((int)((unsigned int)((int)((unsigned int)v538 >> 2)) >> 1))))) >> 31)) | (~(((v543 ^ ((int)((unsigned int)((int)((unsigned int)v538 >> 2)) >> 1))) | (-(v543 ^ ((int)((unsigned int)((int)((unsigned int)v538 >> 2)) >> 1))))) >> 31))) & 104)) ^ (((~(((v540 ^ ((int)((unsigned int)((int)((unsigned int)v538 >> 2)) >> 1))) | (-(v540 ^ ((int)((unsigned int)((int)((unsigned int)v538 >> 2)) >> 1))))) >> 31)) | (~(((v541 ^ ((int)((unsigned int)((int)((unsigned int)v538 >> 2)) >> 1))) | (-(v541 ^ ((int)((unsigned int)((int)((unsigned int)v538 >> 2)) >> 1))))) >> 31))) & (1 ^ (100 ^ (((~(((v542 ^ ((int)((unsigned int)((int)((unsigned int)v538 >> 2)) >> 1))) | (-(v542 ^ ((int)((unsigned int)((int)((unsigned int)v538 >> 2)) >> 1))))) >> 31)) | (~(((v543 ^ ((int)((unsigned int)((int)((unsigned int)v538 >> 2)) >> 1))) | (-(v543 ^ ((int)((unsigned int)((int)((unsigned int)v538 >> 2)) >> 1))))) >> 31))) & 104)))));
  v639[10] = v734;
  int * v641 = v532->regs;
  v641[10] = v638;
  struct StateT * v643 = slot_11(v532);
  return v643;
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

struct StateT * slot_8(struct StateT * v487) {
  int v488 = v487->timer;
  int v499 = v488 + 1;
  v487->timer = v499;
  int * v490 = v487->reg_ready;
  int v491 = v490[12];
  int * v492 = v487->regs;
  int v493 = v492[12];
  int v503 = (v491 + ((v488 - v491) & (~((v488 - v491) >> 31)))) + 1;
  v490[12] = v503;
  int * v495 = v487->regs;
  int v505 = v493 + 72;
  v495[12] = v505;
  struct StateT * v497 = slot_9(v487);
  return v497;
}

struct StateT * slot_19(struct StateT * v1411) {
  int v1412 = v1411->timer;
  int v1425 = v1412 + 1;
  v1411->timer = v1425;
  int * v1414 = v1411->reg_ready;
  int v1415 = v1414[12];
  int * v1416 = v1411->regs;
  int v1417 = v1416[12];
  int v1418 = v1414[10];
  int v1419 = v1416[10];
  int v1430 = (v1418 + (((v1415 + ((v1412 - v1415) & (~((v1412 - v1415) >> 31)))) - v1418) & (~(((v1415 + ((v1412 - v1415) & (~((v1412 - v1415) >> 31)))) - v1418) >> 31)))) + 1;
  v1414[10] = v1430;
  int * v1421 = v1411->regs;
  int v1432 = v1417 & v1419;
  v1421[10] = v1432;
  struct StateT * v1423 = slot_20(v1411);
  return v1423;
}

struct StateT * slot_18(struct StateT * v1203) {
  int v1204 = v1203->timer;
  int v1316 = v1204 + 1;
  v1203->timer = v1316;
  int * v1206 = v1203->reg_ready;
  int v1207 = v1206[11];
  int * v1208 = v1203->regs;
  int v1209 = v1208[11];
  int * v1210 = v1203->cache_tags;
  int v1321 = (((int)((unsigned int)((int)((unsigned int)(v1209 + 68) >> 2)) >> 1)) & 1) * 2;
  int v1211 = v1210[v1321];
  int v1322 = ((((int)((unsigned int)((int)((unsigned int)(v1209 + 68) >> 2)) >> 1)) & 1) * 2) + 1;
  int v1212 = v1210[v1322];
  int v1323 = 4 + ((((int)((unsigned int)((int)((unsigned int)(v1209 + 68) >> 2)) >> 1)) & 3) * 2);
  int v1213 = v1210[v1323];
  int v1324 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v1209 + 68) >> 2)) >> 1)) & 3) * 2)) + 1;
  int v1214 = v1210[v1324];
  int * v1215 = v1203->cache_vals;
  bool v1325 = !(((~(((v1211 ^ ((int)((unsigned int)((int)((unsigned int)(v1209 + 68) >> 2)) >> 1))) | (-(v1211 ^ ((int)((unsigned int)((int)((unsigned int)(v1209 + 68) >> 2)) >> 1))))) >> 31)) | (~(((v1212 ^ ((int)((unsigned int)((int)((unsigned int)(v1209 + 68) >> 2)) >> 1))) | (-(v1212 ^ ((int)((unsigned int)((int)((unsigned int)(v1209 + 68) >> 2)) >> 1))))) >> 31))) == 0);
  int v1308;
  if (v1325) {
    int * v1216 = v1203->cache_age;
    int v1327 = ((((int)((unsigned int)((int)((unsigned int)(v1209 + 68) >> 2)) >> 1)) & 1) * 2) + ((~(((v1212 ^ ((int)((unsigned int)((int)((unsigned int)(v1209 + 68) >> 2)) >> 1))) | (-(v1212 ^ ((int)((unsigned int)((int)((unsigned int)(v1209 + 68) >> 2)) >> 1))))) >> 31)) & 1);
    int v1217 = v1216[v1327];
    int v1218 = v1216[v1321];
    int v1328 = v1218 + ((int)((unsigned int)(v1218 - v1217) >> 31));
    v1216[v1321] = v1328;
    int * v1220 = v1203->cache_age;
    int v1221 = v1220[v1322];
    int v1330 = v1221 + ((int)((unsigned int)(v1221 - v1217) >> 31));
    v1220[v1322] = v1330;
    int * v1223 = v1203->cache_age;
    v1223[v1327] = 0;
    v1308 = v1327;
  } else {
    int * v1226 = v1203->cache_age;
    int v1334 = (((int)((unsigned int)((int)((unsigned int)(v1209 + 68) >> 2)) >> 1)) & 1) * 2;
    int v1227 = v1226[v1334];
    int * v1228 = v1203->cache_tags;
    int v1229 = v1228[v1334];
    int v1230 = v1226[v1322];
    int v1231 = v1228[v1322];
    bool v1336 = !(((~(((v1213 ^ ((int)((unsigned int)((int)((unsigned int)(v1209 + 68) >> 2)) >> 1))) | (-(v1213 ^ ((int)((unsigned int)((int)((unsigned int)(v1209 + 68) >> 2)) >> 1))))) >> 31)) | (~(((v1214 ^ ((int)((unsigned int)((int)((unsigned int)(v1209 + 68) >> 2)) >> 1))) | (-(v1214 ^ ((int)((unsigned int)((int)((unsigned int)(v1209 + 68) >> 2)) >> 1))))) >> 31))) == 0);
    int v1285;
    if (v1336) {
      int * v1232 = v1203->cache_age;
      int v1338 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v1209 + 68) >> 2)) >> 1)) & 3) * 2)) + ((~(((v1214 ^ ((int)((unsigned int)((int)((unsigned int)(v1209 + 68) >> 2)) >> 1))) | (-(v1214 ^ ((int)((unsigned int)((int)((unsigned int)(v1209 + 68) >> 2)) >> 1))))) >> 31)) & 1);
      int v1233 = v1232[v1338];
      int v1234 = v1232[v1323];
      int v1339 = v1234 + ((int)((unsigned int)(v1234 - v1233) >> 31));
      v1232[v1323] = v1339;
      int * v1236 = v1203->cache_age;
      int v1237 = v1236[v1324];
      int v1341 = v1237 + ((int)((unsigned int)(v1237 - v1233) >> 31));
      v1236[v1324] = v1341;
      int * v1239 = v1203->cache_age;
      v1239[v1338] = 0;
      v1285 = v1338;
    } else {
      int * v1242 = v1203->cache_age;
      int v1345 = 4 + ((((int)((unsigned int)((int)((unsigned int)(v1209 + 68) >> 2)) >> 1)) & 3) * 2);
      int v1243 = v1242[v1345];
      int * v1244 = v1203->cache_tags;
      int v1245 = v1244[v1345];
      int v1246 = v1242[v1324];
      int v1247 = v1244[v1324];
      int * v1248 = v1203->cache_dirty;
      int v1348 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v1209 + 68) >> 2)) >> 1)) & 3) * 2)) + ((((v1243 + ((~(((v1245 ^ -1) | (-(v1245 ^ -1))) >> 31)) & 2)) - (v1246 + ((~(((v1247 ^ -1) | (-(v1247 ^ -1))) >> 31)) & 2))) >> 31) & 1);
      int v1249 = v1248[v1348];
      bool v1349 = !(v1249 == 0);
      if (v1349) {
        int * v1250 = v1203->cache_tags;
        int v1251 = v1250[v1348];
        int * v1252 = v1203->cache_vals;
        int v1352 = ((4 + ((((int)((unsigned int)((int)((unsigned int)(v1209 + 68) >> 2)) >> 1)) & 3) * 2)) + ((((v1243 + ((~(((v1245 ^ -1) | (-(v1245 ^ -1))) >> 31)) & 2)) - (v1246 + ((~(((v1247 ^ -1) | (-(v1247 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
        int v1253 = v1252[v1352];
        int v1353 = (((4 + ((((int)((unsigned int)((int)((unsigned int)(v1209 + 68) >> 2)) >> 1)) & 3) * 2)) + ((((v1243 + ((~(((v1245 ^ -1) | (-(v1245 ^ -1))) >> 31)) & 2)) - (v1246 + ((~(((v1247 ^ -1) | (-(v1247 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
        int v1254 = v1252[v1353];
        int * v1255 = v1203->mem;
        int v1355 = v1251 * 2;
        v1255[v1355] = v1253;
        int * v1257 = v1203->mem;
        int v1358 = (v1251 * 2) + 1;
        v1257[v1358] = v1254;
        ;
      } else {
        ;
      }
      int * v1262 = v1203->mem;
      int v1363 = ((int)((unsigned int)((int)((unsigned int)(v1209 + 68) >> 2)) >> 1)) * 2;
      int v1263 = v1262[v1363];
      int v1364 = (((int)((unsigned int)((int)((unsigned int)(v1209 + 68) >> 2)) >> 1)) * 2) + 1;
      int v1264 = v1262[v1364];
      int * v1265 = v1203->cache_vals;
      int v1366 = ((4 + ((((int)((unsigned int)((int)((unsigned int)(v1209 + 68) >> 2)) >> 1)) & 3) * 2)) + ((((v1243 + ((~(((v1245 ^ -1) | (-(v1245 ^ -1))) >> 31)) & 2)) - (v1246 + ((~(((v1247 ^ -1) | (-(v1247 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
      v1265[v1366] = v1263;
      int * v1267 = v1203->cache_vals;
      int v1369 = (((4 + ((((int)((unsigned int)((int)((unsigned int)(v1209 + 68) >> 2)) >> 1)) & 3) * 2)) + ((((v1243 + ((~(((v1245 ^ -1) | (-(v1245 ^ -1))) >> 31)) & 2)) - (v1246 + ((~(((v1247 ^ -1) | (-(v1247 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
      v1267[v1369] = v1264;
      int * v1269 = v1203->cache_tags;
      int v1372 = (int)((unsigned int)((int)((unsigned int)(v1209 + 68) >> 2)) >> 1);
      v1269[v1348] = v1372;
      int * v1271 = v1203->cache_dirty;
      v1271[v1348] = 0;
      int * v1273 = v1203->cache_age;
      v1273[v1348] = 1;
      int * v1275 = v1203->cache_age;
      int v1276 = v1275[v1348];
      int v1277 = v1275[v1323];
      int v1378 = v1277 + ((int)((unsigned int)(v1277 - v1276) >> 31));
      v1275[v1323] = v1378;
      int * v1279 = v1203->cache_age;
      int v1280 = v1279[v1324];
      int v1380 = v1280 + ((int)((unsigned int)(v1280 - v1276) >> 31));
      v1279[v1324] = v1380;
      int * v1282 = v1203->cache_age;
      v1282[v1348] = 0;
      v1285 = v1348;
    }
    int * v1286 = v1203->cache_vals;
    int v1383 = v1285 * 2;
    int v1287 = v1286[v1383];
    int v1384 = (v1285 * 2) + 1;
    int v1288 = v1286[v1384];
    int v1385 = (((((int)((unsigned int)((int)((unsigned int)(v1209 + 68) >> 2)) >> 1)) & 1) * 2) + ((((v1227 + ((~(((v1229 ^ -1) | (-(v1229 ^ -1))) >> 31)) & 2)) - (v1230 + ((~(((v1231 ^ -1) | (-(v1231 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
    v1286[v1385] = v1287;
    int * v1290 = v1203->cache_vals;
    int v1388 = ((((((int)((unsigned int)((int)((unsigned int)(v1209 + 68) >> 2)) >> 1)) & 1) * 2) + ((((v1227 + ((~(((v1229 ^ -1) | (-(v1229 ^ -1))) >> 31)) & 2)) - (v1230 + ((~(((v1231 ^ -1) | (-(v1231 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
    v1290[v1388] = v1288;
    int * v1292 = v1203->cache_tags;
    int v1391 = ((((int)((unsigned int)((int)((unsigned int)(v1209 + 68) >> 2)) >> 1)) & 1) * 2) + ((((v1227 + ((~(((v1229 ^ -1) | (-(v1229 ^ -1))) >> 31)) & 2)) - (v1230 + ((~(((v1231 ^ -1) | (-(v1231 ^ -1))) >> 31)) & 2))) >> 31) & 1);
    int v1392 = (int)((unsigned int)((int)((unsigned int)(v1209 + 68) >> 2)) >> 1);
    v1292[v1391] = v1392;
    int * v1294 = v1203->cache_dirty;
    v1294[v1391] = 0;
    int * v1296 = v1203->cache_age;
    v1296[v1391] = 1;
    int * v1298 = v1203->cache_age;
    int v1299 = v1298[v1391];
    int v1300 = v1298[v1321];
    int v1398 = v1300 + ((int)((unsigned int)(v1300 - v1299) >> 31));
    v1298[v1321] = v1398;
    int * v1302 = v1203->cache_age;
    int v1303 = v1302[v1322];
    int v1400 = v1303 + ((int)((unsigned int)(v1303 - v1299) >> 31));
    v1302[v1322] = v1400;
    int * v1305 = v1203->cache_age;
    v1305[v1391] = 0;
    v1308 = v1391;
  }
  int v1403 = (v1308 * 2) + (((int)((unsigned int)(v1209 + 68) >> 2)) & 1);
  int v1309 = v1215[v1403];
  int * v1310 = v1203->reg_ready;
  int v1406 = ((v1207 + ((v1204 - v1207) & (~((v1204 - v1207) >> 31)))) + 1) + ((100 ^ (((~(((v1213 ^ ((int)((unsigned int)((int)((unsigned int)(v1209 + 68) >> 2)) >> 1))) | (-(v1213 ^ ((int)((unsigned int)((int)((unsigned int)(v1209 + 68) >> 2)) >> 1))))) >> 31)) | (~(((v1214 ^ ((int)((unsigned int)((int)((unsigned int)(v1209 + 68) >> 2)) >> 1))) | (-(v1214 ^ ((int)((unsigned int)((int)((unsigned int)(v1209 + 68) >> 2)) >> 1))))) >> 31))) & 104)) ^ (((~(((v1211 ^ ((int)((unsigned int)((int)((unsigned int)(v1209 + 68) >> 2)) >> 1))) | (-(v1211 ^ ((int)((unsigned int)((int)((unsigned int)(v1209 + 68) >> 2)) >> 1))))) >> 31)) | (~(((v1212 ^ ((int)((unsigned int)((int)((unsigned int)(v1209 + 68) >> 2)) >> 1))) | (-(v1212 ^ ((int)((unsigned int)((int)((unsigned int)(v1209 + 68) >> 2)) >> 1))))) >> 31))) & (1 ^ (100 ^ (((~(((v1213 ^ ((int)((unsigned int)((int)((unsigned int)(v1209 + 68) >> 2)) >> 1))) | (-(v1213 ^ ((int)((unsigned int)((int)((unsigned int)(v1209 + 68) >> 2)) >> 1))))) >> 31)) | (~(((v1214 ^ ((int)((unsigned int)((int)((unsigned int)(v1209 + 68) >> 2)) >> 1))) | (-(v1214 ^ ((int)((unsigned int)((int)((unsigned int)(v1209 + 68) >> 2)) >> 1))))) >> 31))) & 104)))));
  v1310[12] = v1406;
  int * v1312 = v1203->regs;
  v1312[12] = v1309;
  struct StateT * v1314 = slot_19(v1203);
  return v1314;
}

struct StateT * slot_9(struct StateT * v508) {
  int v509 = v508->timer;
  int v522 = v509 + 1;
  v508->timer = v522;
  int * v511 = v508->reg_ready;
  int v512 = v511[12];
  int * v513 = v508->regs;
  int v514 = v513[12];
  int v515 = v511[10];
  int v516 = v513[10];
  int v527 = (v515 + (((v512 + ((v509 - v512) & (~((v509 - v512) >> 31)))) - v515) & (~(((v512 + ((v509 - v512) & (~((v509 - v512) >> 31)))) - v515) >> 31)))) + 1;
  v511[10] = v527;
  int * v518 = v508->regs;
  int v529 = v514 + v516;
  v518[10] = v529;
  struct StateT * v520 = slot_10(v508);
  return v520;
}

struct StateT * slot_11(struct StateT * v739) {
  int v740 = v739->timer;
  int v744 = v740 + 1;
  v739->timer = v744;
  struct StateT * v742 = slot_12(v739);
  return v742;
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