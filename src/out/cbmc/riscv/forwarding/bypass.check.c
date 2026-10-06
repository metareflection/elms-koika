// verify: leak (CBMC should report VERIFICATION FAILED) [unwind 65]
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

struct StateT * snippet(struct StateT * v0);
struct StateT * slot_1(struct StateT * v17);
struct StateT * slot_6(struct StateT * v1024);
struct StateT * slot_5(struct StateT * v1010);
struct StateT * slot_4(struct StateT * v806);
struct StateT * slot_2(struct StateT * v31);
struct StateT * slot_3(struct StateT * v44);
struct StateT * slot_0(struct StateT * v2);
struct StateT * snippet(struct StateT * v0) {
  struct StateT * v1 = slot_0(v0);
  return v1;
}

struct StateT * slot_1(struct StateT * v17) {
  int v18 = v17->timer;
  int v25 = v18 + 1;
  v17->timer = v25;
  int * v20 = v17->regs;
  int v21 = v20[6];
  int v28 = v21 + 80;
  v20[6] = v28;
  struct StateT * v23 = slot_2(v17);
  return v23;
}

struct StateT * slot_6(struct StateT * v1024) {
  int v1025 = v1024->timer;
  int v1134 = v1025 + 1;
  v1024->timer = v1134;
  int * v1027 = v1024->regs;
  int v1028 = v1027[11];
  int * v1029 = v1024->cache_tags;
  int v1138 = (((int)((unsigned int)((int)((unsigned int)v1028 >> 2)) >> 1)) & 1) * 2;
  int v1030 = v1029[v1138];
  int v1139 = ((((int)((unsigned int)((int)((unsigned int)v1028 >> 2)) >> 1)) & 1) * 2) + 1;
  int v1031 = v1029[v1139];
  int v1140 = 4 + ((((int)((unsigned int)((int)((unsigned int)v1028 >> 2)) >> 1)) & 3) * 2);
  int v1032 = v1029[v1140];
  int v1141 = (4 + ((((int)((unsigned int)((int)((unsigned int)v1028 >> 2)) >> 1)) & 3) * 2)) + 1;
  int v1033 = v1029[v1141];
  int v1034 = v1024->timer;
  int v1142 = v1034 + ((100 ^ (((~(((v1032 ^ ((int)((unsigned int)((int)((unsigned int)v1028 >> 2)) >> 1))) | (-(v1032 ^ ((int)((unsigned int)((int)((unsigned int)v1028 >> 2)) >> 1))))) >> 31)) | (~(((v1033 ^ ((int)((unsigned int)((int)((unsigned int)v1028 >> 2)) >> 1))) | (-(v1033 ^ ((int)((unsigned int)((int)((unsigned int)v1028 >> 2)) >> 1))))) >> 31))) & 104)) ^ (((~(((v1030 ^ ((int)((unsigned int)((int)((unsigned int)v1028 >> 2)) >> 1))) | (-(v1030 ^ ((int)((unsigned int)((int)((unsigned int)v1028 >> 2)) >> 1))))) >> 31)) | (~(((v1031 ^ ((int)((unsigned int)((int)((unsigned int)v1028 >> 2)) >> 1))) | (-(v1031 ^ ((int)((unsigned int)((int)((unsigned int)v1028 >> 2)) >> 1))))) >> 31))) & (1 ^ (100 ^ (((~(((v1032 ^ ((int)((unsigned int)((int)((unsigned int)v1028 >> 2)) >> 1))) | (-(v1032 ^ ((int)((unsigned int)((int)((unsigned int)v1028 >> 2)) >> 1))))) >> 31)) | (~(((v1033 ^ ((int)((unsigned int)((int)((unsigned int)v1028 >> 2)) >> 1))) | (-(v1033 ^ ((int)((unsigned int)((int)((unsigned int)v1028 >> 2)) >> 1))))) >> 31))) & 104)))));
  v1024->timer = v1142;
  int * v1036 = v1024->cache_vals;
  bool v1143 = !(((~(((v1030 ^ ((int)((unsigned int)((int)((unsigned int)v1028 >> 2)) >> 1))) | (-(v1030 ^ ((int)((unsigned int)((int)((unsigned int)v1028 >> 2)) >> 1))))) >> 31)) | (~(((v1031 ^ ((int)((unsigned int)((int)((unsigned int)v1028 >> 2)) >> 1))) | (-(v1031 ^ ((int)((unsigned int)((int)((unsigned int)v1028 >> 2)) >> 1))))) >> 31))) == 0);
  int v1129;
  if (v1143) {
    int * v1037 = v1024->cache_age;
    int v1145 = ((((int)((unsigned int)((int)((unsigned int)v1028 >> 2)) >> 1)) & 1) * 2) + ((~(((v1031 ^ ((int)((unsigned int)((int)((unsigned int)v1028 >> 2)) >> 1))) | (-(v1031 ^ ((int)((unsigned int)((int)((unsigned int)v1028 >> 2)) >> 1))))) >> 31)) & 1);
    int v1038 = v1037[v1145];
    int v1039 = v1037[v1138];
    int v1146 = v1039 + ((int)((unsigned int)(v1039 - v1038) >> 31));
    v1037[v1138] = v1146;
    int * v1041 = v1024->cache_age;
    int v1042 = v1041[v1139];
    int v1148 = v1042 + ((int)((unsigned int)(v1042 - v1038) >> 31));
    v1041[v1139] = v1148;
    int * v1044 = v1024->cache_age;
    v1044[v1145] = 0;
    v1129 = v1145;
  } else {
    int * v1047 = v1024->cache_age;
    int v1152 = (((int)((unsigned int)((int)((unsigned int)v1028 >> 2)) >> 1)) & 1) * 2;
    int v1048 = v1047[v1152];
    int * v1049 = v1024->cache_tags;
    int v1050 = v1049[v1152];
    int v1051 = v1047[v1139];
    int v1052 = v1049[v1139];
    bool v1154 = !(((~(((v1032 ^ ((int)((unsigned int)((int)((unsigned int)v1028 >> 2)) >> 1))) | (-(v1032 ^ ((int)((unsigned int)((int)((unsigned int)v1028 >> 2)) >> 1))))) >> 31)) | (~(((v1033 ^ ((int)((unsigned int)((int)((unsigned int)v1028 >> 2)) >> 1))) | (-(v1033 ^ ((int)((unsigned int)((int)((unsigned int)v1028 >> 2)) >> 1))))) >> 31))) == 0);
    int v1106;
    if (v1154) {
      int * v1053 = v1024->cache_age;
      int v1156 = (4 + ((((int)((unsigned int)((int)((unsigned int)v1028 >> 2)) >> 1)) & 3) * 2)) + ((~(((v1033 ^ ((int)((unsigned int)((int)((unsigned int)v1028 >> 2)) >> 1))) | (-(v1033 ^ ((int)((unsigned int)((int)((unsigned int)v1028 >> 2)) >> 1))))) >> 31)) & 1);
      int v1054 = v1053[v1156];
      int v1055 = v1053[v1140];
      int v1157 = v1055 + ((int)((unsigned int)(v1055 - v1054) >> 31));
      v1053[v1140] = v1157;
      int * v1057 = v1024->cache_age;
      int v1058 = v1057[v1141];
      int v1159 = v1058 + ((int)((unsigned int)(v1058 - v1054) >> 31));
      v1057[v1141] = v1159;
      int * v1060 = v1024->cache_age;
      v1060[v1156] = 0;
      v1106 = v1156;
    } else {
      int * v1063 = v1024->cache_age;
      int v1163 = 4 + ((((int)((unsigned int)((int)((unsigned int)v1028 >> 2)) >> 1)) & 3) * 2);
      int v1064 = v1063[v1163];
      int * v1065 = v1024->cache_tags;
      int v1066 = v1065[v1163];
      int v1067 = v1063[v1141];
      int v1068 = v1065[v1141];
      int * v1069 = v1024->cache_dirty;
      int v1166 = (4 + ((((int)((unsigned int)((int)((unsigned int)v1028 >> 2)) >> 1)) & 3) * 2)) + ((((v1064 + ((~(((v1066 ^ -1) | (-(v1066 ^ -1))) >> 31)) & 2)) - (v1067 + ((~(((v1068 ^ -1) | (-(v1068 ^ -1))) >> 31)) & 2))) >> 31) & 1);
      int v1070 = v1069[v1166];
      bool v1167 = !(v1070 == 0);
      if (v1167) {
        int * v1071 = v1024->cache_tags;
        int v1072 = v1071[v1166];
        int * v1073 = v1024->cache_vals;
        int v1170 = ((4 + ((((int)((unsigned int)((int)((unsigned int)v1028 >> 2)) >> 1)) & 3) * 2)) + ((((v1064 + ((~(((v1066 ^ -1) | (-(v1066 ^ -1))) >> 31)) & 2)) - (v1067 + ((~(((v1068 ^ -1) | (-(v1068 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
        int v1074 = v1073[v1170];
        int v1171 = (((4 + ((((int)((unsigned int)((int)((unsigned int)v1028 >> 2)) >> 1)) & 3) * 2)) + ((((v1064 + ((~(((v1066 ^ -1) | (-(v1066 ^ -1))) >> 31)) & 2)) - (v1067 + ((~(((v1068 ^ -1) | (-(v1068 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
        int v1075 = v1073[v1171];
        int * v1076 = v1024->mem;
        int v1173 = v1072 * 2;
        v1076[v1173] = v1074;
        int * v1078 = v1024->mem;
        int v1176 = (v1072 * 2) + 1;
        v1078[v1176] = v1075;
        ;
      } else {
        ;
      }
      int * v1083 = v1024->mem;
      int v1181 = ((int)((unsigned int)((int)((unsigned int)v1028 >> 2)) >> 1)) * 2;
      int v1084 = v1083[v1181];
      int v1182 = (((int)((unsigned int)((int)((unsigned int)v1028 >> 2)) >> 1)) * 2) + 1;
      int v1085 = v1083[v1182];
      int * v1086 = v1024->cache_vals;
      int v1184 = ((4 + ((((int)((unsigned int)((int)((unsigned int)v1028 >> 2)) >> 1)) & 3) * 2)) + ((((v1064 + ((~(((v1066 ^ -1) | (-(v1066 ^ -1))) >> 31)) & 2)) - (v1067 + ((~(((v1068 ^ -1) | (-(v1068 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
      v1086[v1184] = v1084;
      int * v1088 = v1024->cache_vals;
      int v1187 = (((4 + ((((int)((unsigned int)((int)((unsigned int)v1028 >> 2)) >> 1)) & 3) * 2)) + ((((v1064 + ((~(((v1066 ^ -1) | (-(v1066 ^ -1))) >> 31)) & 2)) - (v1067 + ((~(((v1068 ^ -1) | (-(v1068 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
      v1088[v1187] = v1085;
      int * v1090 = v1024->cache_tags;
      int v1190 = (int)((unsigned int)((int)((unsigned int)v1028 >> 2)) >> 1);
      v1090[v1166] = v1190;
      int * v1092 = v1024->cache_dirty;
      v1092[v1166] = 0;
      int * v1094 = v1024->cache_age;
      v1094[v1166] = 1;
      int * v1096 = v1024->cache_age;
      int v1097 = v1096[v1166];
      int v1098 = v1096[v1140];
      int v1196 = v1098 + ((int)((unsigned int)(v1098 - v1097) >> 31));
      v1096[v1140] = v1196;
      int * v1100 = v1024->cache_age;
      int v1101 = v1100[v1141];
      int v1198 = v1101 + ((int)((unsigned int)(v1101 - v1097) >> 31));
      v1100[v1141] = v1198;
      int * v1103 = v1024->cache_age;
      v1103[v1166] = 0;
      v1106 = v1166;
    }
    int * v1107 = v1024->cache_vals;
    int v1201 = v1106 * 2;
    int v1108 = v1107[v1201];
    int v1202 = (v1106 * 2) + 1;
    int v1109 = v1107[v1202];
    int v1203 = (((((int)((unsigned int)((int)((unsigned int)v1028 >> 2)) >> 1)) & 1) * 2) + ((((v1048 + ((~(((v1050 ^ -1) | (-(v1050 ^ -1))) >> 31)) & 2)) - (v1051 + ((~(((v1052 ^ -1) | (-(v1052 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
    v1107[v1203] = v1108;
    int * v1111 = v1024->cache_vals;
    int v1206 = ((((((int)((unsigned int)((int)((unsigned int)v1028 >> 2)) >> 1)) & 1) * 2) + ((((v1048 + ((~(((v1050 ^ -1) | (-(v1050 ^ -1))) >> 31)) & 2)) - (v1051 + ((~(((v1052 ^ -1) | (-(v1052 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
    v1111[v1206] = v1109;
    int * v1113 = v1024->cache_tags;
    int v1209 = ((((int)((unsigned int)((int)((unsigned int)v1028 >> 2)) >> 1)) & 1) * 2) + ((((v1048 + ((~(((v1050 ^ -1) | (-(v1050 ^ -1))) >> 31)) & 2)) - (v1051 + ((~(((v1052 ^ -1) | (-(v1052 ^ -1))) >> 31)) & 2))) >> 31) & 1);
    int v1210 = (int)((unsigned int)((int)((unsigned int)v1028 >> 2)) >> 1);
    v1113[v1209] = v1210;
    int * v1115 = v1024->cache_dirty;
    v1115[v1209] = 0;
    int * v1117 = v1024->cache_age;
    v1117[v1209] = 1;
    int * v1119 = v1024->cache_age;
    int v1120 = v1119[v1209];
    int v1121 = v1119[v1138];
    int v1216 = v1121 + ((int)((unsigned int)(v1121 - v1120) >> 31));
    v1119[v1138] = v1216;
    int * v1123 = v1024->cache_age;
    int v1124 = v1123[v1139];
    int v1218 = v1124 + ((int)((unsigned int)(v1124 - v1120) >> 31));
    v1123[v1139] = v1218;
    int * v1126 = v1024->cache_age;
    v1126[v1209] = 0;
    v1129 = v1209;
  }
  int v1221 = (v1129 * 2) + (((int)((unsigned int)v1028 >> 2)) & 1);
  int v1130 = v1036[v1221];
  int * v1131 = v1024->regs;
  v1131[12] = v1130;
  return v1024;
}

struct StateT * slot_5(struct StateT * v1010) {
  int v1011 = v1010->timer;
  int v1018 = v1011 + 1;
  v1010->timer = v1018;
  int * v1013 = v1010->regs;
  int v1014 = v1013[11];
  int v1021 = v1014 << 2;
  v1013[11] = v1021;
  struct StateT * v1016 = slot_6(v1010);
  return v1016;
}

struct StateT * slot_4(struct StateT * v806) {
  int v807 = v806->timer;
  int v917 = v807 + 1;
  v806->timer = v917;
  int * v809 = v806->regs;
  int v810 = v809[6];
  int * v811 = v806->cache_tags;
  int v921 = (((int)((unsigned int)((int)((unsigned int)v810 >> 2)) >> 1)) & 1) * 2;
  int v812 = v811[v921];
  int v922 = ((((int)((unsigned int)((int)((unsigned int)v810 >> 2)) >> 1)) & 1) * 2) + 1;
  int v813 = v811[v922];
  int v923 = 4 + ((((int)((unsigned int)((int)((unsigned int)v810 >> 2)) >> 1)) & 3) * 2);
  int v814 = v811[v923];
  int v924 = (4 + ((((int)((unsigned int)((int)((unsigned int)v810 >> 2)) >> 1)) & 3) * 2)) + 1;
  int v815 = v811[v924];
  int v816 = v806->timer;
  int v925 = v816 + ((100 ^ (((~(((v814 ^ ((int)((unsigned int)((int)((unsigned int)v810 >> 2)) >> 1))) | (-(v814 ^ ((int)((unsigned int)((int)((unsigned int)v810 >> 2)) >> 1))))) >> 31)) | (~(((v815 ^ ((int)((unsigned int)((int)((unsigned int)v810 >> 2)) >> 1))) | (-(v815 ^ ((int)((unsigned int)((int)((unsigned int)v810 >> 2)) >> 1))))) >> 31))) & 104)) ^ (((~(((v812 ^ ((int)((unsigned int)((int)((unsigned int)v810 >> 2)) >> 1))) | (-(v812 ^ ((int)((unsigned int)((int)((unsigned int)v810 >> 2)) >> 1))))) >> 31)) | (~(((v813 ^ ((int)((unsigned int)((int)((unsigned int)v810 >> 2)) >> 1))) | (-(v813 ^ ((int)((unsigned int)((int)((unsigned int)v810 >> 2)) >> 1))))) >> 31))) & (1 ^ (100 ^ (((~(((v814 ^ ((int)((unsigned int)((int)((unsigned int)v810 >> 2)) >> 1))) | (-(v814 ^ ((int)((unsigned int)((int)((unsigned int)v810 >> 2)) >> 1))))) >> 31)) | (~(((v815 ^ ((int)((unsigned int)((int)((unsigned int)v810 >> 2)) >> 1))) | (-(v815 ^ ((int)((unsigned int)((int)((unsigned int)v810 >> 2)) >> 1))))) >> 31))) & 104)))));
  v806->timer = v925;
  int * v818 = v806->cache_vals;
  bool v926 = !(((~(((v812 ^ ((int)((unsigned int)((int)((unsigned int)v810 >> 2)) >> 1))) | (-(v812 ^ ((int)((unsigned int)((int)((unsigned int)v810 >> 2)) >> 1))))) >> 31)) | (~(((v813 ^ ((int)((unsigned int)((int)((unsigned int)v810 >> 2)) >> 1))) | (-(v813 ^ ((int)((unsigned int)((int)((unsigned int)v810 >> 2)) >> 1))))) >> 31))) == 0);
  int v911;
  if (v926) {
    int * v819 = v806->cache_age;
    int v928 = ((((int)((unsigned int)((int)((unsigned int)v810 >> 2)) >> 1)) & 1) * 2) + ((~(((v813 ^ ((int)((unsigned int)((int)((unsigned int)v810 >> 2)) >> 1))) | (-(v813 ^ ((int)((unsigned int)((int)((unsigned int)v810 >> 2)) >> 1))))) >> 31)) & 1);
    int v820 = v819[v928];
    int v821 = v819[v921];
    int v929 = v821 + ((int)((unsigned int)(v821 - v820) >> 31));
    v819[v921] = v929;
    int * v823 = v806->cache_age;
    int v824 = v823[v922];
    int v931 = v824 + ((int)((unsigned int)(v824 - v820) >> 31));
    v823[v922] = v931;
    int * v826 = v806->cache_age;
    v826[v928] = 0;
    v911 = v928;
  } else {
    int * v829 = v806->cache_age;
    int v935 = (((int)((unsigned int)((int)((unsigned int)v810 >> 2)) >> 1)) & 1) * 2;
    int v830 = v829[v935];
    int * v831 = v806->cache_tags;
    int v832 = v831[v935];
    int v833 = v829[v922];
    int v834 = v831[v922];
    bool v937 = !(((~(((v814 ^ ((int)((unsigned int)((int)((unsigned int)v810 >> 2)) >> 1))) | (-(v814 ^ ((int)((unsigned int)((int)((unsigned int)v810 >> 2)) >> 1))))) >> 31)) | (~(((v815 ^ ((int)((unsigned int)((int)((unsigned int)v810 >> 2)) >> 1))) | (-(v815 ^ ((int)((unsigned int)((int)((unsigned int)v810 >> 2)) >> 1))))) >> 31))) == 0);
    int v888;
    if (v937) {
      int * v835 = v806->cache_age;
      int v939 = (4 + ((((int)((unsigned int)((int)((unsigned int)v810 >> 2)) >> 1)) & 3) * 2)) + ((~(((v815 ^ ((int)((unsigned int)((int)((unsigned int)v810 >> 2)) >> 1))) | (-(v815 ^ ((int)((unsigned int)((int)((unsigned int)v810 >> 2)) >> 1))))) >> 31)) & 1);
      int v836 = v835[v939];
      int v837 = v835[v923];
      int v940 = v837 + ((int)((unsigned int)(v837 - v836) >> 31));
      v835[v923] = v940;
      int * v839 = v806->cache_age;
      int v840 = v839[v924];
      int v942 = v840 + ((int)((unsigned int)(v840 - v836) >> 31));
      v839[v924] = v942;
      int * v842 = v806->cache_age;
      v842[v939] = 0;
      v888 = v939;
    } else {
      int * v845 = v806->cache_age;
      int v946 = 4 + ((((int)((unsigned int)((int)((unsigned int)v810 >> 2)) >> 1)) & 3) * 2);
      int v846 = v845[v946];
      int * v847 = v806->cache_tags;
      int v848 = v847[v946];
      int v849 = v845[v924];
      int v850 = v847[v924];
      int * v851 = v806->cache_dirty;
      int v949 = (4 + ((((int)((unsigned int)((int)((unsigned int)v810 >> 2)) >> 1)) & 3) * 2)) + ((((v846 + ((~(((v848 ^ -1) | (-(v848 ^ -1))) >> 31)) & 2)) - (v849 + ((~(((v850 ^ -1) | (-(v850 ^ -1))) >> 31)) & 2))) >> 31) & 1);
      int v852 = v851[v949];
      bool v950 = !(v852 == 0);
      if (v950) {
        int * v853 = v806->cache_tags;
        int v854 = v853[v949];
        int * v855 = v806->cache_vals;
        int v953 = ((4 + ((((int)((unsigned int)((int)((unsigned int)v810 >> 2)) >> 1)) & 3) * 2)) + ((((v846 + ((~(((v848 ^ -1) | (-(v848 ^ -1))) >> 31)) & 2)) - (v849 + ((~(((v850 ^ -1) | (-(v850 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
        int v856 = v855[v953];
        int v954 = (((4 + ((((int)((unsigned int)((int)((unsigned int)v810 >> 2)) >> 1)) & 3) * 2)) + ((((v846 + ((~(((v848 ^ -1) | (-(v848 ^ -1))) >> 31)) & 2)) - (v849 + ((~(((v850 ^ -1) | (-(v850 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
        int v857 = v855[v954];
        int * v858 = v806->mem;
        int v956 = v854 * 2;
        v858[v956] = v856;
        int * v860 = v806->mem;
        int v959 = (v854 * 2) + 1;
        v860[v959] = v857;
        ;
      } else {
        ;
      }
      int * v865 = v806->mem;
      int v964 = ((int)((unsigned int)((int)((unsigned int)v810 >> 2)) >> 1)) * 2;
      int v866 = v865[v964];
      int v965 = (((int)((unsigned int)((int)((unsigned int)v810 >> 2)) >> 1)) * 2) + 1;
      int v867 = v865[v965];
      int * v868 = v806->cache_vals;
      int v967 = ((4 + ((((int)((unsigned int)((int)((unsigned int)v810 >> 2)) >> 1)) & 3) * 2)) + ((((v846 + ((~(((v848 ^ -1) | (-(v848 ^ -1))) >> 31)) & 2)) - (v849 + ((~(((v850 ^ -1) | (-(v850 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
      v868[v967] = v866;
      int * v870 = v806->cache_vals;
      int v970 = (((4 + ((((int)((unsigned int)((int)((unsigned int)v810 >> 2)) >> 1)) & 3) * 2)) + ((((v846 + ((~(((v848 ^ -1) | (-(v848 ^ -1))) >> 31)) & 2)) - (v849 + ((~(((v850 ^ -1) | (-(v850 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
      v870[v970] = v867;
      int * v872 = v806->cache_tags;
      int v973 = (int)((unsigned int)((int)((unsigned int)v810 >> 2)) >> 1);
      v872[v949] = v973;
      int * v874 = v806->cache_dirty;
      v874[v949] = 0;
      int * v876 = v806->cache_age;
      v876[v949] = 1;
      int * v878 = v806->cache_age;
      int v879 = v878[v949];
      int v880 = v878[v923];
      int v979 = v880 + ((int)((unsigned int)(v880 - v879) >> 31));
      v878[v923] = v979;
      int * v882 = v806->cache_age;
      int v883 = v882[v924];
      int v981 = v883 + ((int)((unsigned int)(v883 - v879) >> 31));
      v882[v924] = v981;
      int * v885 = v806->cache_age;
      v885[v949] = 0;
      v888 = v949;
    }
    int * v889 = v806->cache_vals;
    int v984 = v888 * 2;
    int v890 = v889[v984];
    int v985 = (v888 * 2) + 1;
    int v891 = v889[v985];
    int v986 = (((((int)((unsigned int)((int)((unsigned int)v810 >> 2)) >> 1)) & 1) * 2) + ((((v830 + ((~(((v832 ^ -1) | (-(v832 ^ -1))) >> 31)) & 2)) - (v833 + ((~(((v834 ^ -1) | (-(v834 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
    v889[v986] = v890;
    int * v893 = v806->cache_vals;
    int v989 = ((((((int)((unsigned int)((int)((unsigned int)v810 >> 2)) >> 1)) & 1) * 2) + ((((v830 + ((~(((v832 ^ -1) | (-(v832 ^ -1))) >> 31)) & 2)) - (v833 + ((~(((v834 ^ -1) | (-(v834 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
    v893[v989] = v891;
    int * v895 = v806->cache_tags;
    int v992 = ((((int)((unsigned int)((int)((unsigned int)v810 >> 2)) >> 1)) & 1) * 2) + ((((v830 + ((~(((v832 ^ -1) | (-(v832 ^ -1))) >> 31)) & 2)) - (v833 + ((~(((v834 ^ -1) | (-(v834 ^ -1))) >> 31)) & 2))) >> 31) & 1);
    int v993 = (int)((unsigned int)((int)((unsigned int)v810 >> 2)) >> 1);
    v895[v992] = v993;
    int * v897 = v806->cache_dirty;
    v897[v992] = 0;
    int * v899 = v806->cache_age;
    v899[v992] = 1;
    int * v901 = v806->cache_age;
    int v902 = v901[v992];
    int v903 = v901[v921];
    int v999 = v903 + ((int)((unsigned int)(v903 - v902) >> 31));
    v901[v921] = v999;
    int * v905 = v806->cache_age;
    int v906 = v905[v922];
    int v1001 = v906 + ((int)((unsigned int)(v906 - v902) >> 31));
    v905[v922] = v1001;
    int * v908 = v806->cache_age;
    v908[v992] = 0;
    v911 = v992;
  }
  int v1004 = (v911 * 2) + (((int)((unsigned int)v810 >> 2)) & 1);
  int v912 = v818[v1004];
  int * v913 = v806->regs;
  v913[11] = v912;
  struct StateT * v915 = slot_5(v806);
  return v915;
}

struct StateT * slot_2(struct StateT * v31) {
  int v32 = v31->timer;
  int v38 = v32 + 1;
  v31->timer = v38;
  int * v34 = v31->regs;
  v34[7] = 0;
  struct StateT * v36 = slot_3(v31);
  return v36;
}

struct StateT * slot_3(struct StateT * v44) {
  int v45 = v44->timer;
  int v461 = v45 + 1;
  v44->timer = v461;
  int * v47 = v44->regs;
  int v48 = v47[6];
  int v49 = v47[7];
  int * v50 = v44->saved_regs;
  int v51 = v47[11];
  v50[11] = v51;
  int v53 = v44->timer;
  int v468 = v53 + 1;
  v44->timer = v468;
  int * v55 = v44->regs;
  int v56 = v55[6];
  int * v57 = v44->cache_tags;
  int v471 = (((int)((unsigned int)((int)((unsigned int)v56 >> 2)) >> 1)) & 1) * 2;
  int v58 = v57[v471];
  int v472 = ((((int)((unsigned int)((int)((unsigned int)v56 >> 2)) >> 1)) & 1) * 2) + 1;
  int v59 = v57[v472];
  int v473 = 4 + ((((int)((unsigned int)((int)((unsigned int)v56 >> 2)) >> 1)) & 3) * 2);
  int v60 = v57[v473];
  int v474 = (4 + ((((int)((unsigned int)((int)((unsigned int)v56 >> 2)) >> 1)) & 3) * 2)) + 1;
  int v61 = v57[v474];
  int v62 = v44->timer;
  int v475 = v62 + ((100 ^ (((~(((v60 ^ ((int)((unsigned int)((int)((unsigned int)v56 >> 2)) >> 1))) | (-(v60 ^ ((int)((unsigned int)((int)((unsigned int)v56 >> 2)) >> 1))))) >> 31)) | (~(((v61 ^ ((int)((unsigned int)((int)((unsigned int)v56 >> 2)) >> 1))) | (-(v61 ^ ((int)((unsigned int)((int)((unsigned int)v56 >> 2)) >> 1))))) >> 31))) & 104)) ^ (((~(((v58 ^ ((int)((unsigned int)((int)((unsigned int)v56 >> 2)) >> 1))) | (-(v58 ^ ((int)((unsigned int)((int)((unsigned int)v56 >> 2)) >> 1))))) >> 31)) | (~(((v59 ^ ((int)((unsigned int)((int)((unsigned int)v56 >> 2)) >> 1))) | (-(v59 ^ ((int)((unsigned int)((int)((unsigned int)v56 >> 2)) >> 1))))) >> 31))) & (1 ^ (100 ^ (((~(((v60 ^ ((int)((unsigned int)((int)((unsigned int)v56 >> 2)) >> 1))) | (-(v60 ^ ((int)((unsigned int)((int)((unsigned int)v56 >> 2)) >> 1))))) >> 31)) | (~(((v61 ^ ((int)((unsigned int)((int)((unsigned int)v56 >> 2)) >> 1))) | (-(v61 ^ ((int)((unsigned int)((int)((unsigned int)v56 >> 2)) >> 1))))) >> 31))) & 104)))));
  v44->timer = v475;
  int * v64 = v44->cache_vals;
  bool v476 = !(((~(((v58 ^ ((int)((unsigned int)((int)((unsigned int)v56 >> 2)) >> 1))) | (-(v58 ^ ((int)((unsigned int)((int)((unsigned int)v56 >> 2)) >> 1))))) >> 31)) | (~(((v59 ^ ((int)((unsigned int)((int)((unsigned int)v56 >> 2)) >> 1))) | (-(v59 ^ ((int)((unsigned int)((int)((unsigned int)v56 >> 2)) >> 1))))) >> 31))) == 0);
  int v157;
  if (v476) {
    int * v65 = v44->cache_age;
    int v478 = ((((int)((unsigned int)((int)((unsigned int)v56 >> 2)) >> 1)) & 1) * 2) + ((~(((v59 ^ ((int)((unsigned int)((int)((unsigned int)v56 >> 2)) >> 1))) | (-(v59 ^ ((int)((unsigned int)((int)((unsigned int)v56 >> 2)) >> 1))))) >> 31)) & 1);
    int v66 = v65[v478];
    int v67 = v65[v471];
    int v479 = v67 + ((int)((unsigned int)(v67 - v66) >> 31));
    v65[v471] = v479;
    int * v69 = v44->cache_age;
    int v70 = v69[v472];
    int v481 = v70 + ((int)((unsigned int)(v70 - v66) >> 31));
    v69[v472] = v481;
    int * v72 = v44->cache_age;
    v72[v478] = 0;
    v157 = v478;
  } else {
    int * v75 = v44->cache_age;
    int v485 = (((int)((unsigned int)((int)((unsigned int)v56 >> 2)) >> 1)) & 1) * 2;
    int v76 = v75[v485];
    int * v77 = v44->cache_tags;
    int v78 = v77[v485];
    int v79 = v75[v472];
    int v80 = v77[v472];
    bool v487 = !(((~(((v60 ^ ((int)((unsigned int)((int)((unsigned int)v56 >> 2)) >> 1))) | (-(v60 ^ ((int)((unsigned int)((int)((unsigned int)v56 >> 2)) >> 1))))) >> 31)) | (~(((v61 ^ ((int)((unsigned int)((int)((unsigned int)v56 >> 2)) >> 1))) | (-(v61 ^ ((int)((unsigned int)((int)((unsigned int)v56 >> 2)) >> 1))))) >> 31))) == 0);
    int v134;
    if (v487) {
      int * v81 = v44->cache_age;
      int v489 = (4 + ((((int)((unsigned int)((int)((unsigned int)v56 >> 2)) >> 1)) & 3) * 2)) + ((~(((v61 ^ ((int)((unsigned int)((int)((unsigned int)v56 >> 2)) >> 1))) | (-(v61 ^ ((int)((unsigned int)((int)((unsigned int)v56 >> 2)) >> 1))))) >> 31)) & 1);
      int v82 = v81[v489];
      int v83 = v81[v473];
      int v490 = v83 + ((int)((unsigned int)(v83 - v82) >> 31));
      v81[v473] = v490;
      int * v85 = v44->cache_age;
      int v86 = v85[v474];
      int v492 = v86 + ((int)((unsigned int)(v86 - v82) >> 31));
      v85[v474] = v492;
      int * v88 = v44->cache_age;
      v88[v489] = 0;
      v134 = v489;
    } else {
      int * v91 = v44->cache_age;
      int v496 = 4 + ((((int)((unsigned int)((int)((unsigned int)v56 >> 2)) >> 1)) & 3) * 2);
      int v92 = v91[v496];
      int * v93 = v44->cache_tags;
      int v94 = v93[v496];
      int v95 = v91[v474];
      int v96 = v93[v474];
      int * v97 = v44->cache_dirty;
      int v499 = (4 + ((((int)((unsigned int)((int)((unsigned int)v56 >> 2)) >> 1)) & 3) * 2)) + ((((v92 + ((~(((v94 ^ -1) | (-(v94 ^ -1))) >> 31)) & 2)) - (v95 + ((~(((v96 ^ -1) | (-(v96 ^ -1))) >> 31)) & 2))) >> 31) & 1);
      int v98 = v97[v499];
      bool v500 = !(v98 == 0);
      if (v500) {
        int * v99 = v44->cache_tags;
        int v100 = v99[v499];
        int * v101 = v44->cache_vals;
        int v503 = ((4 + ((((int)((unsigned int)((int)((unsigned int)v56 >> 2)) >> 1)) & 3) * 2)) + ((((v92 + ((~(((v94 ^ -1) | (-(v94 ^ -1))) >> 31)) & 2)) - (v95 + ((~(((v96 ^ -1) | (-(v96 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
        int v102 = v101[v503];
        int v504 = (((4 + ((((int)((unsigned int)((int)((unsigned int)v56 >> 2)) >> 1)) & 3) * 2)) + ((((v92 + ((~(((v94 ^ -1) | (-(v94 ^ -1))) >> 31)) & 2)) - (v95 + ((~(((v96 ^ -1) | (-(v96 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
        int v103 = v101[v504];
        int * v104 = v44->mem;
        int v506 = v100 * 2;
        v104[v506] = v102;
        int * v106 = v44->mem;
        int v509 = (v100 * 2) + 1;
        v106[v509] = v103;
        ;
      } else {
        ;
      }
      int * v111 = v44->mem;
      int v514 = ((int)((unsigned int)((int)((unsigned int)v56 >> 2)) >> 1)) * 2;
      int v112 = v111[v514];
      int v515 = (((int)((unsigned int)((int)((unsigned int)v56 >> 2)) >> 1)) * 2) + 1;
      int v113 = v111[v515];
      int * v114 = v44->cache_vals;
      int v517 = ((4 + ((((int)((unsigned int)((int)((unsigned int)v56 >> 2)) >> 1)) & 3) * 2)) + ((((v92 + ((~(((v94 ^ -1) | (-(v94 ^ -1))) >> 31)) & 2)) - (v95 + ((~(((v96 ^ -1) | (-(v96 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
      v114[v517] = v112;
      int * v116 = v44->cache_vals;
      int v520 = (((4 + ((((int)((unsigned int)((int)((unsigned int)v56 >> 2)) >> 1)) & 3) * 2)) + ((((v92 + ((~(((v94 ^ -1) | (-(v94 ^ -1))) >> 31)) & 2)) - (v95 + ((~(((v96 ^ -1) | (-(v96 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
      v116[v520] = v113;
      int * v118 = v44->cache_tags;
      int v523 = (int)((unsigned int)((int)((unsigned int)v56 >> 2)) >> 1);
      v118[v499] = v523;
      int * v120 = v44->cache_dirty;
      v120[v499] = 0;
      int * v122 = v44->cache_age;
      v122[v499] = 1;
      int * v124 = v44->cache_age;
      int v125 = v124[v499];
      int v126 = v124[v473];
      int v529 = v126 + ((int)((unsigned int)(v126 - v125) >> 31));
      v124[v473] = v529;
      int * v128 = v44->cache_age;
      int v129 = v128[v474];
      int v531 = v129 + ((int)((unsigned int)(v129 - v125) >> 31));
      v128[v474] = v531;
      int * v131 = v44->cache_age;
      v131[v499] = 0;
      v134 = v499;
    }
    int * v135 = v44->cache_vals;
    int v534 = v134 * 2;
    int v136 = v135[v534];
    int v535 = (v134 * 2) + 1;
    int v137 = v135[v535];
    int v536 = (((((int)((unsigned int)((int)((unsigned int)v56 >> 2)) >> 1)) & 1) * 2) + ((((v76 + ((~(((v78 ^ -1) | (-(v78 ^ -1))) >> 31)) & 2)) - (v79 + ((~(((v80 ^ -1) | (-(v80 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
    v135[v536] = v136;
    int * v139 = v44->cache_vals;
    int v539 = ((((((int)((unsigned int)((int)((unsigned int)v56 >> 2)) >> 1)) & 1) * 2) + ((((v76 + ((~(((v78 ^ -1) | (-(v78 ^ -1))) >> 31)) & 2)) - (v79 + ((~(((v80 ^ -1) | (-(v80 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
    v139[v539] = v137;
    int * v141 = v44->cache_tags;
    int v542 = ((((int)((unsigned int)((int)((unsigned int)v56 >> 2)) >> 1)) & 1) * 2) + ((((v76 + ((~(((v78 ^ -1) | (-(v78 ^ -1))) >> 31)) & 2)) - (v79 + ((~(((v80 ^ -1) | (-(v80 ^ -1))) >> 31)) & 2))) >> 31) & 1);
    int v543 = (int)((unsigned int)((int)((unsigned int)v56 >> 2)) >> 1);
    v141[v542] = v543;
    int * v143 = v44->cache_dirty;
    v143[v542] = 0;
    int * v145 = v44->cache_age;
    v145[v542] = 1;
    int * v147 = v44->cache_age;
    int v148 = v147[v542];
    int v149 = v147[v471];
    int v549 = v149 + ((int)((unsigned int)(v149 - v148) >> 31));
    v147[v471] = v549;
    int * v151 = v44->cache_age;
    int v152 = v151[v472];
    int v551 = v152 + ((int)((unsigned int)(v152 - v148) >> 31));
    v151[v472] = v551;
    int * v154 = v44->cache_age;
    v154[v542] = 0;
    v157 = v542;
  }
  int v554 = (v157 * 2) + (((int)((unsigned int)v56 >> 2)) & 1);
  int v158 = v64[v554];
  int * v159 = v44->regs;
  v159[11] = v158;
  int v161 = v44->timer;
  int v557 = v161 + 1;
  v44->timer = v557;
  int * v163 = v44->regs;
  int v164 = v163[11];
  int v559 = v164 << 2;
  v163[11] = v559;
  int * v166 = v44->saved_regs;
  int * v167 = v44->regs;
  int v168 = v167[12];
  v166[12] = v168;
  int v170 = v44->timer;
  int v564 = v170 + 1;
  v44->timer = v564;
  int * v172 = v44->regs;
  int v173 = v172[11];
  bool v566 = (((int)((unsigned int)v48 >> 2)) & 3) == (((int)((unsigned int)v173 >> 2)) & 3);
  int v280;
  if (v566) {
    int v174 = v44->timer;
    int v567 = v174 + 1;
    v44->timer = v567;
    v280 = v49;
  } else {
    int * v177 = v44->cache_tags;
    int v570 = (((int)((unsigned int)((int)((unsigned int)v173 >> 2)) >> 1)) & 1) * 2;
    int v178 = v177[v570];
    int v571 = ((((int)((unsigned int)((int)((unsigned int)v173 >> 2)) >> 1)) & 1) * 2) + 1;
    int v179 = v177[v571];
    int v572 = 4 + ((((int)((unsigned int)((int)((unsigned int)v173 >> 2)) >> 1)) & 3) * 2);
    int v180 = v177[v572];
    int v573 = (4 + ((((int)((unsigned int)((int)((unsigned int)v173 >> 2)) >> 1)) & 3) * 2)) + 1;
    int v181 = v177[v573];
    int v182 = v44->timer;
    int v574 = v182 + ((100 ^ (((~(((v180 ^ ((int)((unsigned int)((int)((unsigned int)v173 >> 2)) >> 1))) | (-(v180 ^ ((int)((unsigned int)((int)((unsigned int)v173 >> 2)) >> 1))))) >> 31)) | (~(((v181 ^ ((int)((unsigned int)((int)((unsigned int)v173 >> 2)) >> 1))) | (-(v181 ^ ((int)((unsigned int)((int)((unsigned int)v173 >> 2)) >> 1))))) >> 31))) & 104)) ^ (((~(((v178 ^ ((int)((unsigned int)((int)((unsigned int)v173 >> 2)) >> 1))) | (-(v178 ^ ((int)((unsigned int)((int)((unsigned int)v173 >> 2)) >> 1))))) >> 31)) | (~(((v179 ^ ((int)((unsigned int)((int)((unsigned int)v173 >> 2)) >> 1))) | (-(v179 ^ ((int)((unsigned int)((int)((unsigned int)v173 >> 2)) >> 1))))) >> 31))) & (1 ^ (100 ^ (((~(((v180 ^ ((int)((unsigned int)((int)((unsigned int)v173 >> 2)) >> 1))) | (-(v180 ^ ((int)((unsigned int)((int)((unsigned int)v173 >> 2)) >> 1))))) >> 31)) | (~(((v181 ^ ((int)((unsigned int)((int)((unsigned int)v173 >> 2)) >> 1))) | (-(v181 ^ ((int)((unsigned int)((int)((unsigned int)v173 >> 2)) >> 1))))) >> 31))) & 104)))));
    v44->timer = v574;
    int * v184 = v44->cache_vals;
    bool v575 = !(((~(((v178 ^ ((int)((unsigned int)((int)((unsigned int)v173 >> 2)) >> 1))) | (-(v178 ^ ((int)((unsigned int)((int)((unsigned int)v173 >> 2)) >> 1))))) >> 31)) | (~(((v179 ^ ((int)((unsigned int)((int)((unsigned int)v173 >> 2)) >> 1))) | (-(v179 ^ ((int)((unsigned int)((int)((unsigned int)v173 >> 2)) >> 1))))) >> 31))) == 0);
    int v277;
    if (v575) {
      int * v185 = v44->cache_age;
      int v577 = ((((int)((unsigned int)((int)((unsigned int)v173 >> 2)) >> 1)) & 1) * 2) + ((~(((v179 ^ ((int)((unsigned int)((int)((unsigned int)v173 >> 2)) >> 1))) | (-(v179 ^ ((int)((unsigned int)((int)((unsigned int)v173 >> 2)) >> 1))))) >> 31)) & 1);
      int v186 = v185[v577];
      int v187 = v185[v570];
      int v578 = v187 + ((int)((unsigned int)(v187 - v186) >> 31));
      v185[v570] = v578;
      int * v189 = v44->cache_age;
      int v190 = v189[v571];
      int v580 = v190 + ((int)((unsigned int)(v190 - v186) >> 31));
      v189[v571] = v580;
      int * v192 = v44->cache_age;
      v192[v577] = 0;
      v277 = v577;
    } else {
      int * v195 = v44->cache_age;
      int v584 = (((int)((unsigned int)((int)((unsigned int)v173 >> 2)) >> 1)) & 1) * 2;
      int v196 = v195[v584];
      int * v197 = v44->cache_tags;
      int v198 = v197[v584];
      int v199 = v195[v571];
      int v200 = v197[v571];
      bool v586 = !(((~(((v180 ^ ((int)((unsigned int)((int)((unsigned int)v173 >> 2)) >> 1))) | (-(v180 ^ ((int)((unsigned int)((int)((unsigned int)v173 >> 2)) >> 1))))) >> 31)) | (~(((v181 ^ ((int)((unsigned int)((int)((unsigned int)v173 >> 2)) >> 1))) | (-(v181 ^ ((int)((unsigned int)((int)((unsigned int)v173 >> 2)) >> 1))))) >> 31))) == 0);
      int v254;
      if (v586) {
        int * v201 = v44->cache_age;
        int v588 = (4 + ((((int)((unsigned int)((int)((unsigned int)v173 >> 2)) >> 1)) & 3) * 2)) + ((~(((v181 ^ ((int)((unsigned int)((int)((unsigned int)v173 >> 2)) >> 1))) | (-(v181 ^ ((int)((unsigned int)((int)((unsigned int)v173 >> 2)) >> 1))))) >> 31)) & 1);
        int v202 = v201[v588];
        int v203 = v201[v572];
        int v589 = v203 + ((int)((unsigned int)(v203 - v202) >> 31));
        v201[v572] = v589;
        int * v205 = v44->cache_age;
        int v206 = v205[v573];
        int v591 = v206 + ((int)((unsigned int)(v206 - v202) >> 31));
        v205[v573] = v591;
        int * v208 = v44->cache_age;
        v208[v588] = 0;
        v254 = v588;
      } else {
        int * v211 = v44->cache_age;
        int v595 = 4 + ((((int)((unsigned int)((int)((unsigned int)v173 >> 2)) >> 1)) & 3) * 2);
        int v212 = v211[v595];
        int * v213 = v44->cache_tags;
        int v214 = v213[v595];
        int v215 = v211[v573];
        int v216 = v213[v573];
        int * v217 = v44->cache_dirty;
        int v598 = (4 + ((((int)((unsigned int)((int)((unsigned int)v173 >> 2)) >> 1)) & 3) * 2)) + ((((v212 + ((~(((v214 ^ -1) | (-(v214 ^ -1))) >> 31)) & 2)) - (v215 + ((~(((v216 ^ -1) | (-(v216 ^ -1))) >> 31)) & 2))) >> 31) & 1);
        int v218 = v217[v598];
        bool v599 = !(v218 == 0);
        if (v599) {
          int * v219 = v44->cache_tags;
          int v220 = v219[v598];
          int * v221 = v44->cache_vals;
          int v602 = ((4 + ((((int)((unsigned int)((int)((unsigned int)v173 >> 2)) >> 1)) & 3) * 2)) + ((((v212 + ((~(((v214 ^ -1) | (-(v214 ^ -1))) >> 31)) & 2)) - (v215 + ((~(((v216 ^ -1) | (-(v216 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
          int v222 = v221[v602];
          int v603 = (((4 + ((((int)((unsigned int)((int)((unsigned int)v173 >> 2)) >> 1)) & 3) * 2)) + ((((v212 + ((~(((v214 ^ -1) | (-(v214 ^ -1))) >> 31)) & 2)) - (v215 + ((~(((v216 ^ -1) | (-(v216 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
          int v223 = v221[v603];
          int * v224 = v44->mem;
          int v605 = v220 * 2;
          v224[v605] = v222;
          int * v226 = v44->mem;
          int v608 = (v220 * 2) + 1;
          v226[v608] = v223;
          ;
        } else {
          ;
        }
        int * v231 = v44->mem;
        int v613 = ((int)((unsigned int)((int)((unsigned int)v173 >> 2)) >> 1)) * 2;
        int v232 = v231[v613];
        int v614 = (((int)((unsigned int)((int)((unsigned int)v173 >> 2)) >> 1)) * 2) + 1;
        int v233 = v231[v614];
        int * v234 = v44->cache_vals;
        int v616 = ((4 + ((((int)((unsigned int)((int)((unsigned int)v173 >> 2)) >> 1)) & 3) * 2)) + ((((v212 + ((~(((v214 ^ -1) | (-(v214 ^ -1))) >> 31)) & 2)) - (v215 + ((~(((v216 ^ -1) | (-(v216 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
        v234[v616] = v232;
        int * v236 = v44->cache_vals;
        int v619 = (((4 + ((((int)((unsigned int)((int)((unsigned int)v173 >> 2)) >> 1)) & 3) * 2)) + ((((v212 + ((~(((v214 ^ -1) | (-(v214 ^ -1))) >> 31)) & 2)) - (v215 + ((~(((v216 ^ -1) | (-(v216 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
        v236[v619] = v233;
        int * v238 = v44->cache_tags;
        int v622 = (int)((unsigned int)((int)((unsigned int)v173 >> 2)) >> 1);
        v238[v598] = v622;
        int * v240 = v44->cache_dirty;
        v240[v598] = 0;
        int * v242 = v44->cache_age;
        v242[v598] = 1;
        int * v244 = v44->cache_age;
        int v245 = v244[v598];
        int v246 = v244[v572];
        int v628 = v246 + ((int)((unsigned int)(v246 - v245) >> 31));
        v244[v572] = v628;
        int * v248 = v44->cache_age;
        int v249 = v248[v573];
        int v630 = v249 + ((int)((unsigned int)(v249 - v245) >> 31));
        v248[v573] = v630;
        int * v251 = v44->cache_age;
        v251[v598] = 0;
        v254 = v598;
      }
      int * v255 = v44->cache_vals;
      int v633 = v254 * 2;
      int v256 = v255[v633];
      int v634 = (v254 * 2) + 1;
      int v257 = v255[v634];
      int v635 = (((((int)((unsigned int)((int)((unsigned int)v173 >> 2)) >> 1)) & 1) * 2) + ((((v196 + ((~(((v198 ^ -1) | (-(v198 ^ -1))) >> 31)) & 2)) - (v199 + ((~(((v200 ^ -1) | (-(v200 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
      v255[v635] = v256;
      int * v259 = v44->cache_vals;
      int v638 = ((((((int)((unsigned int)((int)((unsigned int)v173 >> 2)) >> 1)) & 1) * 2) + ((((v196 + ((~(((v198 ^ -1) | (-(v198 ^ -1))) >> 31)) & 2)) - (v199 + ((~(((v200 ^ -1) | (-(v200 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
      v259[v638] = v257;
      int * v261 = v44->cache_tags;
      int v641 = ((((int)((unsigned int)((int)((unsigned int)v173 >> 2)) >> 1)) & 1) * 2) + ((((v196 + ((~(((v198 ^ -1) | (-(v198 ^ -1))) >> 31)) & 2)) - (v199 + ((~(((v200 ^ -1) | (-(v200 ^ -1))) >> 31)) & 2))) >> 31) & 1);
      int v642 = (int)((unsigned int)((int)((unsigned int)v173 >> 2)) >> 1);
      v261[v641] = v642;
      int * v263 = v44->cache_dirty;
      v263[v641] = 0;
      int * v265 = v44->cache_age;
      v265[v641] = 1;
      int * v267 = v44->cache_age;
      int v268 = v267[v641];
      int v269 = v267[v570];
      int v648 = v269 + ((int)((unsigned int)(v269 - v268) >> 31));
      v267[v570] = v648;
      int * v271 = v44->cache_age;
      int v272 = v271[v571];
      int v650 = v272 + ((int)((unsigned int)(v272 - v268) >> 31));
      v271[v571] = v650;
      int * v274 = v44->cache_age;
      v274[v641] = 0;
      v277 = v641;
    }
    int v653 = (v277 * 2) + (((int)((unsigned int)v173 >> 2)) & 1);
    int v278 = v184[v653];
    v280 = v278;
  }
  int * v281 = v44->regs;
  v281[12] = v280;
  int * v283 = v44->cache_tags;
  int v658 = (((int)((unsigned int)((int)((unsigned int)v48 >> 2)) >> 1)) & 1) * 2;
  int v284 = v283[v658];
  int v659 = ((((int)((unsigned int)((int)((unsigned int)v48 >> 2)) >> 1)) & 1) * 2) + 1;
  int v285 = v283[v659];
  int v660 = 4 + ((((int)((unsigned int)((int)((unsigned int)v48 >> 2)) >> 1)) & 3) * 2);
  int v286 = v283[v660];
  int v661 = (4 + ((((int)((unsigned int)((int)((unsigned int)v48 >> 2)) >> 1)) & 3) * 2)) + 1;
  int v287 = v283[v661];
  int v288 = v44->timer;
  int v662 = v288 + ((100 ^ (((~(((v286 ^ ((int)((unsigned int)((int)((unsigned int)v48 >> 2)) >> 1))) | (-(v286 ^ ((int)((unsigned int)((int)((unsigned int)v48 >> 2)) >> 1))))) >> 31)) | (~(((v287 ^ ((int)((unsigned int)((int)((unsigned int)v48 >> 2)) >> 1))) | (-(v287 ^ ((int)((unsigned int)((int)((unsigned int)v48 >> 2)) >> 1))))) >> 31))) & 104)) ^ (((~(((v284 ^ ((int)((unsigned int)((int)((unsigned int)v48 >> 2)) >> 1))) | (-(v284 ^ ((int)((unsigned int)((int)((unsigned int)v48 >> 2)) >> 1))))) >> 31)) | (~(((v285 ^ ((int)((unsigned int)((int)((unsigned int)v48 >> 2)) >> 1))) | (-(v285 ^ ((int)((unsigned int)((int)((unsigned int)v48 >> 2)) >> 1))))) >> 31))) & (1 ^ (100 ^ (((~(((v286 ^ ((int)((unsigned int)((int)((unsigned int)v48 >> 2)) >> 1))) | (-(v286 ^ ((int)((unsigned int)((int)((unsigned int)v48 >> 2)) >> 1))))) >> 31)) | (~(((v287 ^ ((int)((unsigned int)((int)((unsigned int)v48 >> 2)) >> 1))) | (-(v287 ^ ((int)((unsigned int)((int)((unsigned int)v48 >> 2)) >> 1))))) >> 31))) & 104)))));
  v44->timer = v662;
  bool v663 = !(((~(((v284 ^ ((int)((unsigned int)((int)((unsigned int)v48 >> 2)) >> 1))) | (-(v284 ^ ((int)((unsigned int)((int)((unsigned int)v48 >> 2)) >> 1))))) >> 31)) | (~(((v285 ^ ((int)((unsigned int)((int)((unsigned int)v48 >> 2)) >> 1))) | (-(v285 ^ ((int)((unsigned int)((int)((unsigned int)v48 >> 2)) >> 1))))) >> 31))) == 0);
  int v382;
  if (v663) {
    int * v290 = v44->cache_age;
    int v665 = ((((int)((unsigned int)((int)((unsigned int)v48 >> 2)) >> 1)) & 1) * 2) + ((~(((v285 ^ ((int)((unsigned int)((int)((unsigned int)v48 >> 2)) >> 1))) | (-(v285 ^ ((int)((unsigned int)((int)((unsigned int)v48 >> 2)) >> 1))))) >> 31)) & 1);
    int v291 = v290[v665];
    int v292 = v290[v658];
    int v666 = v292 + ((int)((unsigned int)(v292 - v291) >> 31));
    v290[v658] = v666;
    int * v294 = v44->cache_age;
    int v295 = v294[v659];
    int v668 = v295 + ((int)((unsigned int)(v295 - v291) >> 31));
    v294[v659] = v668;
    int * v297 = v44->cache_age;
    v297[v665] = 0;
    v382 = v665;
  } else {
    int * v300 = v44->cache_age;
    int v672 = (((int)((unsigned int)((int)((unsigned int)v48 >> 2)) >> 1)) & 1) * 2;
    int v301 = v300[v672];
    int * v302 = v44->cache_tags;
    int v303 = v302[v672];
    int v304 = v300[v659];
    int v305 = v302[v659];
    bool v674 = !(((~(((v286 ^ ((int)((unsigned int)((int)((unsigned int)v48 >> 2)) >> 1))) | (-(v286 ^ ((int)((unsigned int)((int)((unsigned int)v48 >> 2)) >> 1))))) >> 31)) | (~(((v287 ^ ((int)((unsigned int)((int)((unsigned int)v48 >> 2)) >> 1))) | (-(v287 ^ ((int)((unsigned int)((int)((unsigned int)v48 >> 2)) >> 1))))) >> 31))) == 0);
    int v359;
    if (v674) {
      int * v306 = v44->cache_age;
      int v676 = (4 + ((((int)((unsigned int)((int)((unsigned int)v48 >> 2)) >> 1)) & 3) * 2)) + ((~(((v287 ^ ((int)((unsigned int)((int)((unsigned int)v48 >> 2)) >> 1))) | (-(v287 ^ ((int)((unsigned int)((int)((unsigned int)v48 >> 2)) >> 1))))) >> 31)) & 1);
      int v307 = v306[v676];
      int v308 = v306[v660];
      int v677 = v308 + ((int)((unsigned int)(v308 - v307) >> 31));
      v306[v660] = v677;
      int * v310 = v44->cache_age;
      int v311 = v310[v661];
      int v679 = v311 + ((int)((unsigned int)(v311 - v307) >> 31));
      v310[v661] = v679;
      int * v313 = v44->cache_age;
      v313[v676] = 0;
      v359 = v676;
    } else {
      int * v316 = v44->cache_age;
      int v683 = 4 + ((((int)((unsigned int)((int)((unsigned int)v48 >> 2)) >> 1)) & 3) * 2);
      int v317 = v316[v683];
      int * v318 = v44->cache_tags;
      int v319 = v318[v683];
      int v320 = v316[v661];
      int v321 = v318[v661];
      int * v322 = v44->cache_dirty;
      int v686 = (4 + ((((int)((unsigned int)((int)((unsigned int)v48 >> 2)) >> 1)) & 3) * 2)) + ((((v317 + ((~(((v319 ^ -1) | (-(v319 ^ -1))) >> 31)) & 2)) - (v320 + ((~(((v321 ^ -1) | (-(v321 ^ -1))) >> 31)) & 2))) >> 31) & 1);
      int v323 = v322[v686];
      bool v687 = !(v323 == 0);
      if (v687) {
        int * v324 = v44->cache_tags;
        int v325 = v324[v686];
        int * v326 = v44->cache_vals;
        int v690 = ((4 + ((((int)((unsigned int)((int)((unsigned int)v48 >> 2)) >> 1)) & 3) * 2)) + ((((v317 + ((~(((v319 ^ -1) | (-(v319 ^ -1))) >> 31)) & 2)) - (v320 + ((~(((v321 ^ -1) | (-(v321 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
        int v327 = v326[v690];
        int v691 = (((4 + ((((int)((unsigned int)((int)((unsigned int)v48 >> 2)) >> 1)) & 3) * 2)) + ((((v317 + ((~(((v319 ^ -1) | (-(v319 ^ -1))) >> 31)) & 2)) - (v320 + ((~(((v321 ^ -1) | (-(v321 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
        int v328 = v326[v691];
        int * v329 = v44->mem;
        int v693 = v325 * 2;
        v329[v693] = v327;
        int * v331 = v44->mem;
        int v696 = (v325 * 2) + 1;
        v331[v696] = v328;
        ;
      } else {
        ;
      }
      int * v336 = v44->mem;
      int v701 = ((int)((unsigned int)((int)((unsigned int)v48 >> 2)) >> 1)) * 2;
      int v337 = v336[v701];
      int v702 = (((int)((unsigned int)((int)((unsigned int)v48 >> 2)) >> 1)) * 2) + 1;
      int v338 = v336[v702];
      int * v339 = v44->cache_vals;
      int v704 = ((4 + ((((int)((unsigned int)((int)((unsigned int)v48 >> 2)) >> 1)) & 3) * 2)) + ((((v317 + ((~(((v319 ^ -1) | (-(v319 ^ -1))) >> 31)) & 2)) - (v320 + ((~(((v321 ^ -1) | (-(v321 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
      v339[v704] = v337;
      int * v341 = v44->cache_vals;
      int v707 = (((4 + ((((int)((unsigned int)((int)((unsigned int)v48 >> 2)) >> 1)) & 3) * 2)) + ((((v317 + ((~(((v319 ^ -1) | (-(v319 ^ -1))) >> 31)) & 2)) - (v320 + ((~(((v321 ^ -1) | (-(v321 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
      v341[v707] = v338;
      int * v343 = v44->cache_tags;
      int v710 = (int)((unsigned int)((int)((unsigned int)v48 >> 2)) >> 1);
      v343[v686] = v710;
      int * v345 = v44->cache_dirty;
      v345[v686] = 0;
      int * v347 = v44->cache_age;
      v347[v686] = 1;
      int * v349 = v44->cache_age;
      int v350 = v349[v686];
      int v351 = v349[v660];
      int v716 = v351 + ((int)((unsigned int)(v351 - v350) >> 31));
      v349[v660] = v716;
      int * v353 = v44->cache_age;
      int v354 = v353[v661];
      int v718 = v354 + ((int)((unsigned int)(v354 - v350) >> 31));
      v353[v661] = v718;
      int * v356 = v44->cache_age;
      v356[v686] = 0;
      v359 = v686;
    }
    int * v360 = v44->cache_vals;
    int v721 = v359 * 2;
    int v361 = v360[v721];
    int v722 = (v359 * 2) + 1;
    int v362 = v360[v722];
    int v723 = (((((int)((unsigned int)((int)((unsigned int)v48 >> 2)) >> 1)) & 1) * 2) + ((((v301 + ((~(((v303 ^ -1) | (-(v303 ^ -1))) >> 31)) & 2)) - (v304 + ((~(((v305 ^ -1) | (-(v305 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
    v360[v723] = v361;
    int * v364 = v44->cache_vals;
    int v726 = ((((((int)((unsigned int)((int)((unsigned int)v48 >> 2)) >> 1)) & 1) * 2) + ((((v301 + ((~(((v303 ^ -1) | (-(v303 ^ -1))) >> 31)) & 2)) - (v304 + ((~(((v305 ^ -1) | (-(v305 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
    v364[v726] = v362;
    int * v366 = v44->cache_tags;
    int v729 = ((((int)((unsigned int)((int)((unsigned int)v48 >> 2)) >> 1)) & 1) * 2) + ((((v301 + ((~(((v303 ^ -1) | (-(v303 ^ -1))) >> 31)) & 2)) - (v304 + ((~(((v305 ^ -1) | (-(v305 ^ -1))) >> 31)) & 2))) >> 31) & 1);
    int v730 = (int)((unsigned int)((int)((unsigned int)v48 >> 2)) >> 1);
    v366[v729] = v730;
    int * v368 = v44->cache_dirty;
    v368[v729] = 0;
    int * v370 = v44->cache_age;
    v370[v729] = 1;
    int * v372 = v44->cache_age;
    int v373 = v372[v729];
    int v374 = v372[v658];
    int v736 = v374 + ((int)((unsigned int)(v374 - v373) >> 31));
    v372[v658] = v736;
    int * v376 = v44->cache_age;
    int v377 = v376[v659];
    int v738 = v377 + ((int)((unsigned int)(v377 - v373) >> 31));
    v376[v659] = v738;
    int * v379 = v44->cache_age;
    v379[v729] = 0;
    v382 = v729;
  }
  int * v383 = v44->cache_vals;
  int v741 = (v382 * 2) + (((int)((unsigned int)v48 >> 2)) & 1);
  v383[v741] = v49;
  int * v385 = v44->cache_tags;
  int v386 = v385[v660];
  int v387 = v385[v661];
  bool v744 = !(((~(((v386 ^ ((int)((unsigned int)((int)((unsigned int)v48 >> 2)) >> 1))) | (-(v386 ^ ((int)((unsigned int)((int)((unsigned int)v48 >> 2)) >> 1))))) >> 31)) | (~(((v387 ^ ((int)((unsigned int)((int)((unsigned int)v48 >> 2)) >> 1))) | (-(v387 ^ ((int)((unsigned int)((int)((unsigned int)v48 >> 2)) >> 1))))) >> 31))) == 0);
  int v441;
  if (v744) {
    int * v388 = v44->cache_age;
    int v746 = (4 + ((((int)((unsigned int)((int)((unsigned int)v48 >> 2)) >> 1)) & 3) * 2)) + ((~(((v387 ^ ((int)((unsigned int)((int)((unsigned int)v48 >> 2)) >> 1))) | (-(v387 ^ ((int)((unsigned int)((int)((unsigned int)v48 >> 2)) >> 1))))) >> 31)) & 1);
    int v389 = v388[v746];
    int v390 = v388[v660];
    int v747 = v390 + ((int)((unsigned int)(v390 - v389) >> 31));
    v388[v660] = v747;
    int * v392 = v44->cache_age;
    int v393 = v392[v661];
    int v749 = v393 + ((int)((unsigned int)(v393 - v389) >> 31));
    v392[v661] = v749;
    int * v395 = v44->cache_age;
    v395[v746] = 0;
    v441 = v746;
  } else {
    int * v398 = v44->cache_age;
    int v753 = 4 + ((((int)((unsigned int)((int)((unsigned int)v48 >> 2)) >> 1)) & 3) * 2);
    int v399 = v398[v753];
    int * v400 = v44->cache_tags;
    int v401 = v400[v753];
    int v402 = v398[v661];
    int v403 = v400[v661];
    int * v404 = v44->cache_dirty;
    int v756 = (4 + ((((int)((unsigned int)((int)((unsigned int)v48 >> 2)) >> 1)) & 3) * 2)) + ((((v399 + ((~(((v401 ^ -1) | (-(v401 ^ -1))) >> 31)) & 2)) - (v402 + ((~(((v403 ^ -1) | (-(v403 ^ -1))) >> 31)) & 2))) >> 31) & 1);
    int v405 = v404[v756];
    bool v757 = !(v405 == 0);
    if (v757) {
      int * v406 = v44->cache_tags;
      int v407 = v406[v756];
      int * v408 = v44->cache_vals;
      int v760 = ((4 + ((((int)((unsigned int)((int)((unsigned int)v48 >> 2)) >> 1)) & 3) * 2)) + ((((v399 + ((~(((v401 ^ -1) | (-(v401 ^ -1))) >> 31)) & 2)) - (v402 + ((~(((v403 ^ -1) | (-(v403 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
      int v409 = v408[v760];
      int v761 = (((4 + ((((int)((unsigned int)((int)((unsigned int)v48 >> 2)) >> 1)) & 3) * 2)) + ((((v399 + ((~(((v401 ^ -1) | (-(v401 ^ -1))) >> 31)) & 2)) - (v402 + ((~(((v403 ^ -1) | (-(v403 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
      int v410 = v408[v761];
      int * v411 = v44->mem;
      int v763 = v407 * 2;
      v411[v763] = v409;
      int * v413 = v44->mem;
      int v766 = (v407 * 2) + 1;
      v413[v766] = v410;
      ;
    } else {
      ;
    }
    int * v418 = v44->mem;
    int v771 = ((int)((unsigned int)((int)((unsigned int)v48 >> 2)) >> 1)) * 2;
    int v419 = v418[v771];
    int v772 = (((int)((unsigned int)((int)((unsigned int)v48 >> 2)) >> 1)) * 2) + 1;
    int v420 = v418[v772];
    int * v421 = v44->cache_vals;
    int v774 = ((4 + ((((int)((unsigned int)((int)((unsigned int)v48 >> 2)) >> 1)) & 3) * 2)) + ((((v399 + ((~(((v401 ^ -1) | (-(v401 ^ -1))) >> 31)) & 2)) - (v402 + ((~(((v403 ^ -1) | (-(v403 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
    v421[v774] = v419;
    int * v423 = v44->cache_vals;
    int v777 = (((4 + ((((int)((unsigned int)((int)((unsigned int)v48 >> 2)) >> 1)) & 3) * 2)) + ((((v399 + ((~(((v401 ^ -1) | (-(v401 ^ -1))) >> 31)) & 2)) - (v402 + ((~(((v403 ^ -1) | (-(v403 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
    v423[v777] = v420;
    int * v425 = v44->cache_tags;
    int v780 = (int)((unsigned int)((int)((unsigned int)v48 >> 2)) >> 1);
    v425[v756] = v780;
    int * v427 = v44->cache_dirty;
    v427[v756] = 0;
    int * v429 = v44->cache_age;
    v429[v756] = 1;
    int * v431 = v44->cache_age;
    int v432 = v431[v756];
    int v433 = v431[v660];
    int v786 = v433 + ((int)((unsigned int)(v433 - v432) >> 31));
    v431[v660] = v786;
    int * v435 = v44->cache_age;
    int v436 = v435[v661];
    int v788 = v436 + ((int)((unsigned int)(v436 - v432) >> 31));
    v435[v661] = v788;
    int * v438 = v44->cache_age;
    v438[v756] = 0;
    v441 = v756;
  }
  int * v442 = v44->cache_vals;
  int v791 = (v441 * 2) + (((int)((unsigned int)v48 >> 2)) & 1);
  v442[v791] = v49;
  int * v444 = v44->cache_dirty;
  v444[v441] = 1;
  bool v795 = (((int)((unsigned int)v56 >> 2)) == ((int)((unsigned int)v48 >> 2))) | (((((int)((unsigned int)v173 >> 2)) & 3) == (((int)((unsigned int)v48 >> 2)) & 3)) & (!(((int)((unsigned int)v173 >> 2)) == ((int)((unsigned int)v48 >> 2)))));
  struct StateT * v459;
  if (v795) {
    int v446 = v44->timer;
    int v796 = v446 + 15;
    v44->timer = v796;
    int * v448 = v44->saved_regs;
    int v449 = v448[11];
    int * v450 = v44->regs;
    v450[11] = v449;
    int * v452 = v44->saved_regs;
    int v453 = v452[12];
    int * v454 = v44->regs;
    v454[12] = v453;
    struct StateT * v456 = slot_4(v44);
    v459 = v456;
  } else {
    v459 = v44;
  }
  return v459;
}

struct StateT * slot_0(struct StateT * v2) {
  int v3 = v2->timer;
  int v10 = v3 + 1;
  v2->timer = v10;
  int * v5 = v2->regs;
  int v6 = v5[10];
  int v14 = v6 & 28;
  v5[6] = v14;
  struct StateT * v8 = slot_1(v2);
  return v8;
}



/*****************************************
End of C Generated Code
*******************************************/

void init(struct StateT *s) {
  for (int i=0; i<NUM_REGS; i++) {
    s->regs[i] = 0;
    s->saved_regs[i] = 0;
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