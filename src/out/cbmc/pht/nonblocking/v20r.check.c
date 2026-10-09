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

struct StateT * slot_12(struct StateT * v1409);
struct StateT * slot_6(struct StateT * v756);
struct StateT * slot_16(struct StateT * v1869);
struct StateT * slot_23(struct StateT * v1011);
struct StateT * slot_5(struct StateT * v527);
struct StateT * slot_2(struct StateT * v225);
struct StateT * slot_7(struct StateT * v804);
struct StateT * slot_21(struct StateT * v548);
struct StateT * slot_3(struct StateT * v267);
struct StateT * slot_10(struct StateT * v1372);
struct StateT * slot_1(struct StateT * v18);
struct StateT * slot_19(struct StateT * v288);
struct StateT * slot_13(struct StateT * v1430);
struct StateT * slot_24(struct StateT * v1346);
struct StateT * slot_0(struct StateT * v2);
struct StateT * slot_14(struct StateT * v1454);
struct StateT * slot_17(struct StateT * v1893);
struct StateT * slot_20(struct StateT * v320);
struct StateT * snippet(struct StateT * v0);
struct StateT * slot_8(struct StateT * v1330);
struct StateT * slot_4(struct StateT * v304);
struct StateT * slot_15(struct StateT * v1661);
struct StateT * slot_18(struct StateT * v251);
struct StateT * slot_9(struct StateT * v1351);
struct StateT * slot_22(struct StateT * v780);
struct StateT * slot_11(struct StateT * v1388);
struct StateT * slot_12(struct StateT * v1409) {
  int v1410 = v1409->timer;
  int v1421 = v1410 + 1;
  v1409->timer = v1421;
  int * v1412 = v1409->reg_ready;
  int v1413 = v1412[10];
  int * v1414 = v1409->regs;
  int v1415 = v1414[10];
  int v1425 = (v1413 + ((v1410 - v1413) & (~((v1410 - v1413) >> 31)))) + 1;
  v1412[10] = v1425;
  int * v1417 = v1409->regs;
  int v1427 = (int)((unsigned int)v1415 >> 26);
  v1417[10] = v1427;
  struct StateT * v1419 = slot_13(v1409);
  return v1419;
}

struct StateT * slot_6(struct StateT * v756) {
  int v757 = v756->timer;
  int v770 = v757 + 1;
  v756->timer = v770;
  int * v759 = v756->reg_ready;
  int v760 = v759[11];
  int * v761 = v756->regs;
  int v762 = v761[11];
  int v763 = v759[10];
  int v764 = v761[10];
  int v775 = (v763 + (((v760 + ((v757 - v760) & (~((v757 - v760) >> 31)))) - v763) & (~(((v760 + ((v757 - v760) & (~((v757 - v760) >> 31)))) - v763) >> 31)))) + 1;
  v759[10] = v775;
  int * v766 = v756->regs;
  int v777 = v762 + v764;
  v766[10] = v777;
  struct StateT * v768 = slot_7(v756);
  return v768;
}

struct StateT * slot_16(struct StateT * v1869) {
  int v1870 = v1869->timer;
  int v1883 = v1870 + 1;
  v1869->timer = v1883;
  int * v1872 = v1869->reg_ready;
  int v1873 = v1872[11];
  int * v1874 = v1869->regs;
  int v1875 = v1874[11];
  int v1876 = v1872[10];
  int v1877 = v1874[10];
  int v1888 = (v1876 + (((v1873 + ((v1870 - v1873) & (~((v1870 - v1873) >> 31)))) - v1876) & (~(((v1873 + ((v1870 - v1873) & (~((v1870 - v1873) >> 31)))) - v1876) >> 31)))) + 1;
  v1872[10] = v1888;
  int * v1879 = v1869->regs;
  int v1890 = v1875 & v1877;
  v1879[10] = v1890;
  struct StateT * v1881 = slot_17(v1869);
  return v1881;
}

struct StateT * slot_23(struct StateT * v1011) {
  int v1012 = v1011->timer;
  int v1185 = v1012 + 1;
  v1011->timer = v1185;
  int * v1014 = v1011->reg_ready;
  int * v1016 = v1011->regs;
  int v1017 = v1016[11];
  int v1019 = v1016[10];
  int * v1020 = v1011->cache_tags;
  int v1191 = (((int)((unsigned int)((int)((unsigned int)(v1017 + 68) >> 2)) >> 1)) & 1) * 2;
  int v1021 = v1020[v1191];
  int v1192 = ((((int)((unsigned int)((int)((unsigned int)(v1017 + 68) >> 2)) >> 1)) & 1) * 2) + 1;
  int v1022 = v1020[v1192];
  int v1193 = 4 + ((((int)((unsigned int)((int)((unsigned int)(v1017 + 68) >> 2)) >> 1)) & 3) * 2);
  int v1023 = v1020[v1193];
  int v1194 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v1017 + 68) >> 2)) >> 1)) & 3) * 2)) + 1;
  int v1024 = v1020[v1194];
  int v1025 = v1011->timer;
  int v1195 = v1025 + ((100 ^ (((~(((v1023 ^ ((int)((unsigned int)((int)((unsigned int)(v1017 + 68) >> 2)) >> 1))) | (-(v1023 ^ ((int)((unsigned int)((int)((unsigned int)(v1017 + 68) >> 2)) >> 1))))) >> 31)) | (~(((v1024 ^ ((int)((unsigned int)((int)((unsigned int)(v1017 + 68) >> 2)) >> 1))) | (-(v1024 ^ ((int)((unsigned int)((int)((unsigned int)(v1017 + 68) >> 2)) >> 1))))) >> 31))) & 104)) ^ (((~(((v1021 ^ ((int)((unsigned int)((int)((unsigned int)(v1017 + 68) >> 2)) >> 1))) | (-(v1021 ^ ((int)((unsigned int)((int)((unsigned int)(v1017 + 68) >> 2)) >> 1))))) >> 31)) | (~(((v1022 ^ ((int)((unsigned int)((int)((unsigned int)(v1017 + 68) >> 2)) >> 1))) | (-(v1022 ^ ((int)((unsigned int)((int)((unsigned int)(v1017 + 68) >> 2)) >> 1))))) >> 31))) & (1 ^ (100 ^ (((~(((v1023 ^ ((int)((unsigned int)((int)((unsigned int)(v1017 + 68) >> 2)) >> 1))) | (-(v1023 ^ ((int)((unsigned int)((int)((unsigned int)(v1017 + 68) >> 2)) >> 1))))) >> 31)) | (~(((v1024 ^ ((int)((unsigned int)((int)((unsigned int)(v1017 + 68) >> 2)) >> 1))) | (-(v1024 ^ ((int)((unsigned int)((int)((unsigned int)(v1017 + 68) >> 2)) >> 1))))) >> 31))) & 104)))));
  v1011->timer = v1195;
  bool v1196 = !(((~(((v1021 ^ ((int)((unsigned int)((int)((unsigned int)(v1017 + 68) >> 2)) >> 1))) | (-(v1021 ^ ((int)((unsigned int)((int)((unsigned int)(v1017 + 68) >> 2)) >> 1))))) >> 31)) | (~(((v1022 ^ ((int)((unsigned int)((int)((unsigned int)(v1017 + 68) >> 2)) >> 1))) | (-(v1022 ^ ((int)((unsigned int)((int)((unsigned int)(v1017 + 68) >> 2)) >> 1))))) >> 31))) == 0);
  int v1119;
  if (v1196) {
    int * v1027 = v1011->cache_age;
    int v1198 = ((((int)((unsigned int)((int)((unsigned int)(v1017 + 68) >> 2)) >> 1)) & 1) * 2) + ((~(((v1022 ^ ((int)((unsigned int)((int)((unsigned int)(v1017 + 68) >> 2)) >> 1))) | (-(v1022 ^ ((int)((unsigned int)((int)((unsigned int)(v1017 + 68) >> 2)) >> 1))))) >> 31)) & 1);
    int v1028 = v1027[v1198];
    int v1029 = v1027[v1191];
    int v1199 = v1029 + ((int)((unsigned int)(v1029 - v1028) >> 31));
    v1027[v1191] = v1199;
    int * v1031 = v1011->cache_age;
    int v1032 = v1031[v1192];
    int v1201 = v1032 + ((int)((unsigned int)(v1032 - v1028) >> 31));
    v1031[v1192] = v1201;
    int * v1034 = v1011->cache_age;
    v1034[v1198] = 0;
    v1119 = v1198;
  } else {
    int * v1037 = v1011->cache_age;
    int v1205 = (((int)((unsigned int)((int)((unsigned int)(v1017 + 68) >> 2)) >> 1)) & 1) * 2;
    int v1038 = v1037[v1205];
    int * v1039 = v1011->cache_tags;
    int v1040 = v1039[v1205];
    int v1041 = v1037[v1192];
    int v1042 = v1039[v1192];
    bool v1207 = !(((~(((v1023 ^ ((int)((unsigned int)((int)((unsigned int)(v1017 + 68) >> 2)) >> 1))) | (-(v1023 ^ ((int)((unsigned int)((int)((unsigned int)(v1017 + 68) >> 2)) >> 1))))) >> 31)) | (~(((v1024 ^ ((int)((unsigned int)((int)((unsigned int)(v1017 + 68) >> 2)) >> 1))) | (-(v1024 ^ ((int)((unsigned int)((int)((unsigned int)(v1017 + 68) >> 2)) >> 1))))) >> 31))) == 0);
    int v1096;
    if (v1207) {
      int * v1043 = v1011->cache_age;
      int v1209 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v1017 + 68) >> 2)) >> 1)) & 3) * 2)) + ((~(((v1024 ^ ((int)((unsigned int)((int)((unsigned int)(v1017 + 68) >> 2)) >> 1))) | (-(v1024 ^ ((int)((unsigned int)((int)((unsigned int)(v1017 + 68) >> 2)) >> 1))))) >> 31)) & 1);
      int v1044 = v1043[v1209];
      int v1045 = v1043[v1193];
      int v1210 = v1045 + ((int)((unsigned int)(v1045 - v1044) >> 31));
      v1043[v1193] = v1210;
      int * v1047 = v1011->cache_age;
      int v1048 = v1047[v1194];
      int v1212 = v1048 + ((int)((unsigned int)(v1048 - v1044) >> 31));
      v1047[v1194] = v1212;
      int * v1050 = v1011->cache_age;
      v1050[v1209] = 0;
      v1096 = v1209;
    } else {
      int * v1053 = v1011->cache_age;
      int v1216 = 4 + ((((int)((unsigned int)((int)((unsigned int)(v1017 + 68) >> 2)) >> 1)) & 3) * 2);
      int v1054 = v1053[v1216];
      int * v1055 = v1011->cache_tags;
      int v1056 = v1055[v1216];
      int v1057 = v1053[v1194];
      int v1058 = v1055[v1194];
      int * v1059 = v1011->cache_dirty;
      int v1219 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v1017 + 68) >> 2)) >> 1)) & 3) * 2)) + ((((v1054 + ((~(((v1056 ^ -1) | (-(v1056 ^ -1))) >> 31)) & 2)) - (v1057 + ((~(((v1058 ^ -1) | (-(v1058 ^ -1))) >> 31)) & 2))) >> 31) & 1);
      int v1060 = v1059[v1219];
      bool v1220 = !(v1060 == 0);
      if (v1220) {
        int * v1061 = v1011->cache_tags;
        int v1062 = v1061[v1219];
        int * v1063 = v1011->cache_vals;
        int v1223 = ((4 + ((((int)((unsigned int)((int)((unsigned int)(v1017 + 68) >> 2)) >> 1)) & 3) * 2)) + ((((v1054 + ((~(((v1056 ^ -1) | (-(v1056 ^ -1))) >> 31)) & 2)) - (v1057 + ((~(((v1058 ^ -1) | (-(v1058 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
        int v1064 = v1063[v1223];
        int v1224 = (((4 + ((((int)((unsigned int)((int)((unsigned int)(v1017 + 68) >> 2)) >> 1)) & 3) * 2)) + ((((v1054 + ((~(((v1056 ^ -1) | (-(v1056 ^ -1))) >> 31)) & 2)) - (v1057 + ((~(((v1058 ^ -1) | (-(v1058 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
        int v1065 = v1063[v1224];
        int * v1066 = v1011->mem;
        int v1226 = v1062 * 2;
        v1066[v1226] = v1064;
        int * v1068 = v1011->mem;
        int v1229 = (v1062 * 2) + 1;
        v1068[v1229] = v1065;
        ;
      } else {
        ;
      }
      int * v1073 = v1011->mem;
      int v1234 = ((int)((unsigned int)((int)((unsigned int)(v1017 + 68) >> 2)) >> 1)) * 2;
      int v1074 = v1073[v1234];
      int v1235 = (((int)((unsigned int)((int)((unsigned int)(v1017 + 68) >> 2)) >> 1)) * 2) + 1;
      int v1075 = v1073[v1235];
      int * v1076 = v1011->cache_vals;
      int v1237 = ((4 + ((((int)((unsigned int)((int)((unsigned int)(v1017 + 68) >> 2)) >> 1)) & 3) * 2)) + ((((v1054 + ((~(((v1056 ^ -1) | (-(v1056 ^ -1))) >> 31)) & 2)) - (v1057 + ((~(((v1058 ^ -1) | (-(v1058 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
      v1076[v1237] = v1074;
      int * v1078 = v1011->cache_vals;
      int v1240 = (((4 + ((((int)((unsigned int)((int)((unsigned int)(v1017 + 68) >> 2)) >> 1)) & 3) * 2)) + ((((v1054 + ((~(((v1056 ^ -1) | (-(v1056 ^ -1))) >> 31)) & 2)) - (v1057 + ((~(((v1058 ^ -1) | (-(v1058 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
      v1078[v1240] = v1075;
      int * v1080 = v1011->cache_tags;
      int v1243 = (int)((unsigned int)((int)((unsigned int)(v1017 + 68) >> 2)) >> 1);
      v1080[v1219] = v1243;
      int * v1082 = v1011->cache_dirty;
      v1082[v1219] = 0;
      int * v1084 = v1011->cache_age;
      v1084[v1219] = 1;
      int * v1086 = v1011->cache_age;
      int v1087 = v1086[v1219];
      int v1088 = v1086[v1193];
      int v1249 = v1088 + ((int)((unsigned int)(v1088 - v1087) >> 31));
      v1086[v1193] = v1249;
      int * v1090 = v1011->cache_age;
      int v1091 = v1090[v1194];
      int v1251 = v1091 + ((int)((unsigned int)(v1091 - v1087) >> 31));
      v1090[v1194] = v1251;
      int * v1093 = v1011->cache_age;
      v1093[v1219] = 0;
      v1096 = v1219;
    }
    int * v1097 = v1011->cache_vals;
    int v1254 = v1096 * 2;
    int v1098 = v1097[v1254];
    int v1255 = (v1096 * 2) + 1;
    int v1099 = v1097[v1255];
    int v1256 = (((((int)((unsigned int)((int)((unsigned int)(v1017 + 68) >> 2)) >> 1)) & 1) * 2) + ((((v1038 + ((~(((v1040 ^ -1) | (-(v1040 ^ -1))) >> 31)) & 2)) - (v1041 + ((~(((v1042 ^ -1) | (-(v1042 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
    v1097[v1256] = v1098;
    int * v1101 = v1011->cache_vals;
    int v1259 = ((((((int)((unsigned int)((int)((unsigned int)(v1017 + 68) >> 2)) >> 1)) & 1) * 2) + ((((v1038 + ((~(((v1040 ^ -1) | (-(v1040 ^ -1))) >> 31)) & 2)) - (v1041 + ((~(((v1042 ^ -1) | (-(v1042 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
    v1101[v1259] = v1099;
    int * v1103 = v1011->cache_tags;
    int v1262 = ((((int)((unsigned int)((int)((unsigned int)(v1017 + 68) >> 2)) >> 1)) & 1) * 2) + ((((v1038 + ((~(((v1040 ^ -1) | (-(v1040 ^ -1))) >> 31)) & 2)) - (v1041 + ((~(((v1042 ^ -1) | (-(v1042 ^ -1))) >> 31)) & 2))) >> 31) & 1);
    int v1263 = (int)((unsigned int)((int)((unsigned int)(v1017 + 68) >> 2)) >> 1);
    v1103[v1262] = v1263;
    int * v1105 = v1011->cache_dirty;
    v1105[v1262] = 0;
    int * v1107 = v1011->cache_age;
    v1107[v1262] = 1;
    int * v1109 = v1011->cache_age;
    int v1110 = v1109[v1262];
    int v1111 = v1109[v1191];
    int v1269 = v1111 + ((int)((unsigned int)(v1111 - v1110) >> 31));
    v1109[v1191] = v1269;
    int * v1113 = v1011->cache_age;
    int v1114 = v1113[v1192];
    int v1271 = v1114 + ((int)((unsigned int)(v1114 - v1110) >> 31));
    v1113[v1192] = v1271;
    int * v1116 = v1011->cache_age;
    v1116[v1262] = 0;
    v1119 = v1262;
  }
  int * v1120 = v1011->cache_vals;
  int v1274 = (v1119 * 2) + (((int)((unsigned int)(v1017 + 68) >> 2)) & 1);
  v1120[v1274] = v1019;
  int * v1122 = v1011->cache_tags;
  int v1123 = v1122[v1193];
  int v1124 = v1122[v1194];
  bool v1277 = !(((~(((v1123 ^ ((int)((unsigned int)((int)((unsigned int)(v1017 + 68) >> 2)) >> 1))) | (-(v1123 ^ ((int)((unsigned int)((int)((unsigned int)(v1017 + 68) >> 2)) >> 1))))) >> 31)) | (~(((v1124 ^ ((int)((unsigned int)((int)((unsigned int)(v1017 + 68) >> 2)) >> 1))) | (-(v1124 ^ ((int)((unsigned int)((int)((unsigned int)(v1017 + 68) >> 2)) >> 1))))) >> 31))) == 0);
  int v1178;
  if (v1277) {
    int * v1125 = v1011->cache_age;
    int v1279 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v1017 + 68) >> 2)) >> 1)) & 3) * 2)) + ((~(((v1124 ^ ((int)((unsigned int)((int)((unsigned int)(v1017 + 68) >> 2)) >> 1))) | (-(v1124 ^ ((int)((unsigned int)((int)((unsigned int)(v1017 + 68) >> 2)) >> 1))))) >> 31)) & 1);
    int v1126 = v1125[v1279];
    int v1127 = v1125[v1193];
    int v1280 = v1127 + ((int)((unsigned int)(v1127 - v1126) >> 31));
    v1125[v1193] = v1280;
    int * v1129 = v1011->cache_age;
    int v1130 = v1129[v1194];
    int v1282 = v1130 + ((int)((unsigned int)(v1130 - v1126) >> 31));
    v1129[v1194] = v1282;
    int * v1132 = v1011->cache_age;
    v1132[v1279] = 0;
    v1178 = v1279;
  } else {
    int * v1135 = v1011->cache_age;
    int v1286 = 4 + ((((int)((unsigned int)((int)((unsigned int)(v1017 + 68) >> 2)) >> 1)) & 3) * 2);
    int v1136 = v1135[v1286];
    int * v1137 = v1011->cache_tags;
    int v1138 = v1137[v1286];
    int v1139 = v1135[v1194];
    int v1140 = v1137[v1194];
    int * v1141 = v1011->cache_dirty;
    int v1289 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v1017 + 68) >> 2)) >> 1)) & 3) * 2)) + ((((v1136 + ((~(((v1138 ^ -1) | (-(v1138 ^ -1))) >> 31)) & 2)) - (v1139 + ((~(((v1140 ^ -1) | (-(v1140 ^ -1))) >> 31)) & 2))) >> 31) & 1);
    int v1142 = v1141[v1289];
    bool v1290 = !(v1142 == 0);
    if (v1290) {
      int * v1143 = v1011->cache_tags;
      int v1144 = v1143[v1289];
      int * v1145 = v1011->cache_vals;
      int v1293 = ((4 + ((((int)((unsigned int)((int)((unsigned int)(v1017 + 68) >> 2)) >> 1)) & 3) * 2)) + ((((v1136 + ((~(((v1138 ^ -1) | (-(v1138 ^ -1))) >> 31)) & 2)) - (v1139 + ((~(((v1140 ^ -1) | (-(v1140 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
      int v1146 = v1145[v1293];
      int v1294 = (((4 + ((((int)((unsigned int)((int)((unsigned int)(v1017 + 68) >> 2)) >> 1)) & 3) * 2)) + ((((v1136 + ((~(((v1138 ^ -1) | (-(v1138 ^ -1))) >> 31)) & 2)) - (v1139 + ((~(((v1140 ^ -1) | (-(v1140 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
      int v1147 = v1145[v1294];
      int * v1148 = v1011->mem;
      int v1296 = v1144 * 2;
      v1148[v1296] = v1146;
      int * v1150 = v1011->mem;
      int v1299 = (v1144 * 2) + 1;
      v1150[v1299] = v1147;
      ;
    } else {
      ;
    }
    int * v1155 = v1011->mem;
    int v1304 = ((int)((unsigned int)((int)((unsigned int)(v1017 + 68) >> 2)) >> 1)) * 2;
    int v1156 = v1155[v1304];
    int v1305 = (((int)((unsigned int)((int)((unsigned int)(v1017 + 68) >> 2)) >> 1)) * 2) + 1;
    int v1157 = v1155[v1305];
    int * v1158 = v1011->cache_vals;
    int v1307 = ((4 + ((((int)((unsigned int)((int)((unsigned int)(v1017 + 68) >> 2)) >> 1)) & 3) * 2)) + ((((v1136 + ((~(((v1138 ^ -1) | (-(v1138 ^ -1))) >> 31)) & 2)) - (v1139 + ((~(((v1140 ^ -1) | (-(v1140 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
    v1158[v1307] = v1156;
    int * v1160 = v1011->cache_vals;
    int v1310 = (((4 + ((((int)((unsigned int)((int)((unsigned int)(v1017 + 68) >> 2)) >> 1)) & 3) * 2)) + ((((v1136 + ((~(((v1138 ^ -1) | (-(v1138 ^ -1))) >> 31)) & 2)) - (v1139 + ((~(((v1140 ^ -1) | (-(v1140 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
    v1160[v1310] = v1157;
    int * v1162 = v1011->cache_tags;
    int v1313 = (int)((unsigned int)((int)((unsigned int)(v1017 + 68) >> 2)) >> 1);
    v1162[v1289] = v1313;
    int * v1164 = v1011->cache_dirty;
    v1164[v1289] = 0;
    int * v1166 = v1011->cache_age;
    v1166[v1289] = 1;
    int * v1168 = v1011->cache_age;
    int v1169 = v1168[v1289];
    int v1170 = v1168[v1193];
    int v1319 = v1170 + ((int)((unsigned int)(v1170 - v1169) >> 31));
    v1168[v1193] = v1319;
    int * v1172 = v1011->cache_age;
    int v1173 = v1172[v1194];
    int v1321 = v1173 + ((int)((unsigned int)(v1173 - v1169) >> 31));
    v1172[v1194] = v1321;
    int * v1175 = v1011->cache_age;
    v1175[v1289] = 0;
    v1178 = v1289;
  }
  int * v1179 = v1011->cache_vals;
  int v1324 = (v1178 * 2) + (((int)((unsigned int)(v1017 + 68) >> 2)) & 1);
  v1179[v1324] = v1019;
  int * v1181 = v1011->cache_dirty;
  v1181[v1178] = 1;
  struct StateT * v1183 = slot_24(v1011);
  return v1183;
}

struct StateT * slot_5(struct StateT * v527) {
  int v528 = v527->timer;
  int v539 = v528 + 1;
  v527->timer = v539;
  int * v530 = v527->reg_ready;
  int v531 = v530[11];
  int * v532 = v527->regs;
  int v533 = v532[11];
  int v543 = (v531 + ((v528 - v531) & (~((v528 - v531) >> 31)))) + 1;
  v530[11] = v543;
  int * v535 = v527->regs;
  int v545 = v533 + 72;
  v535[11] = v545;
  struct StateT * v537 = slot_6(v527);
  return v537;
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

struct StateT * slot_7(struct StateT * v804) {
  int v805 = v804->timer;
  int v917 = v805 + 1;
  v804->timer = v917;
  int * v807 = v804->reg_ready;
  int v808 = v807[10];
  int * v809 = v804->regs;
  int v810 = v809[10];
  int * v811 = v804->cache_tags;
  int v922 = (((int)((unsigned int)((int)((unsigned int)v810 >> 2)) >> 1)) & 1) * 2;
  int v812 = v811[v922];
  int v923 = ((((int)((unsigned int)((int)((unsigned int)v810 >> 2)) >> 1)) & 1) * 2) + 1;
  int v813 = v811[v923];
  int v924 = 4 + ((((int)((unsigned int)((int)((unsigned int)v810 >> 2)) >> 1)) & 3) * 2);
  int v814 = v811[v924];
  int v925 = (4 + ((((int)((unsigned int)((int)((unsigned int)v810 >> 2)) >> 1)) & 3) * 2)) + 1;
  int v815 = v811[v925];
  int * v816 = v804->cache_vals;
  bool v926 = !(((~(((v812 ^ ((int)((unsigned int)((int)((unsigned int)v810 >> 2)) >> 1))) | (-(v812 ^ ((int)((unsigned int)((int)((unsigned int)v810 >> 2)) >> 1))))) >> 31)) | (~(((v813 ^ ((int)((unsigned int)((int)((unsigned int)v810 >> 2)) >> 1))) | (-(v813 ^ ((int)((unsigned int)((int)((unsigned int)v810 >> 2)) >> 1))))) >> 31))) == 0);
  int v909;
  if (v926) {
    int * v817 = v804->cache_age;
    int v928 = ((((int)((unsigned int)((int)((unsigned int)v810 >> 2)) >> 1)) & 1) * 2) + ((~(((v813 ^ ((int)((unsigned int)((int)((unsigned int)v810 >> 2)) >> 1))) | (-(v813 ^ ((int)((unsigned int)((int)((unsigned int)v810 >> 2)) >> 1))))) >> 31)) & 1);
    int v818 = v817[v928];
    int v819 = v817[v922];
    int v929 = v819 + ((int)((unsigned int)(v819 - v818) >> 31));
    v817[v922] = v929;
    int * v821 = v804->cache_age;
    int v822 = v821[v923];
    int v931 = v822 + ((int)((unsigned int)(v822 - v818) >> 31));
    v821[v923] = v931;
    int * v824 = v804->cache_age;
    v824[v928] = 0;
    v909 = v928;
  } else {
    int * v827 = v804->cache_age;
    int v935 = (((int)((unsigned int)((int)((unsigned int)v810 >> 2)) >> 1)) & 1) * 2;
    int v828 = v827[v935];
    int * v829 = v804->cache_tags;
    int v830 = v829[v935];
    int v831 = v827[v923];
    int v832 = v829[v923];
    bool v937 = !(((~(((v814 ^ ((int)((unsigned int)((int)((unsigned int)v810 >> 2)) >> 1))) | (-(v814 ^ ((int)((unsigned int)((int)((unsigned int)v810 >> 2)) >> 1))))) >> 31)) | (~(((v815 ^ ((int)((unsigned int)((int)((unsigned int)v810 >> 2)) >> 1))) | (-(v815 ^ ((int)((unsigned int)((int)((unsigned int)v810 >> 2)) >> 1))))) >> 31))) == 0);
    int v886;
    if (v937) {
      int * v833 = v804->cache_age;
      int v939 = (4 + ((((int)((unsigned int)((int)((unsigned int)v810 >> 2)) >> 1)) & 3) * 2)) + ((~(((v815 ^ ((int)((unsigned int)((int)((unsigned int)v810 >> 2)) >> 1))) | (-(v815 ^ ((int)((unsigned int)((int)((unsigned int)v810 >> 2)) >> 1))))) >> 31)) & 1);
      int v834 = v833[v939];
      int v835 = v833[v924];
      int v940 = v835 + ((int)((unsigned int)(v835 - v834) >> 31));
      v833[v924] = v940;
      int * v837 = v804->cache_age;
      int v838 = v837[v925];
      int v942 = v838 + ((int)((unsigned int)(v838 - v834) >> 31));
      v837[v925] = v942;
      int * v840 = v804->cache_age;
      v840[v939] = 0;
      v886 = v939;
    } else {
      int * v843 = v804->cache_age;
      int v946 = 4 + ((((int)((unsigned int)((int)((unsigned int)v810 >> 2)) >> 1)) & 3) * 2);
      int v844 = v843[v946];
      int * v845 = v804->cache_tags;
      int v846 = v845[v946];
      int v847 = v843[v925];
      int v848 = v845[v925];
      int * v849 = v804->cache_dirty;
      int v949 = (4 + ((((int)((unsigned int)((int)((unsigned int)v810 >> 2)) >> 1)) & 3) * 2)) + ((((v844 + ((~(((v846 ^ -1) | (-(v846 ^ -1))) >> 31)) & 2)) - (v847 + ((~(((v848 ^ -1) | (-(v848 ^ -1))) >> 31)) & 2))) >> 31) & 1);
      int v850 = v849[v949];
      bool v950 = !(v850 == 0);
      if (v950) {
        int * v851 = v804->cache_tags;
        int v852 = v851[v949];
        int * v853 = v804->cache_vals;
        int v953 = ((4 + ((((int)((unsigned int)((int)((unsigned int)v810 >> 2)) >> 1)) & 3) * 2)) + ((((v844 + ((~(((v846 ^ -1) | (-(v846 ^ -1))) >> 31)) & 2)) - (v847 + ((~(((v848 ^ -1) | (-(v848 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
        int v854 = v853[v953];
        int v954 = (((4 + ((((int)((unsigned int)((int)((unsigned int)v810 >> 2)) >> 1)) & 3) * 2)) + ((((v844 + ((~(((v846 ^ -1) | (-(v846 ^ -1))) >> 31)) & 2)) - (v847 + ((~(((v848 ^ -1) | (-(v848 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
        int v855 = v853[v954];
        int * v856 = v804->mem;
        int v956 = v852 * 2;
        v856[v956] = v854;
        int * v858 = v804->mem;
        int v959 = (v852 * 2) + 1;
        v858[v959] = v855;
        ;
      } else {
        ;
      }
      int * v863 = v804->mem;
      int v964 = ((int)((unsigned int)((int)((unsigned int)v810 >> 2)) >> 1)) * 2;
      int v864 = v863[v964];
      int v965 = (((int)((unsigned int)((int)((unsigned int)v810 >> 2)) >> 1)) * 2) + 1;
      int v865 = v863[v965];
      int * v866 = v804->cache_vals;
      int v967 = ((4 + ((((int)((unsigned int)((int)((unsigned int)v810 >> 2)) >> 1)) & 3) * 2)) + ((((v844 + ((~(((v846 ^ -1) | (-(v846 ^ -1))) >> 31)) & 2)) - (v847 + ((~(((v848 ^ -1) | (-(v848 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
      v866[v967] = v864;
      int * v868 = v804->cache_vals;
      int v970 = (((4 + ((((int)((unsigned int)((int)((unsigned int)v810 >> 2)) >> 1)) & 3) * 2)) + ((((v844 + ((~(((v846 ^ -1) | (-(v846 ^ -1))) >> 31)) & 2)) - (v847 + ((~(((v848 ^ -1) | (-(v848 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
      v868[v970] = v865;
      int * v870 = v804->cache_tags;
      int v973 = (int)((unsigned int)((int)((unsigned int)v810 >> 2)) >> 1);
      v870[v949] = v973;
      int * v872 = v804->cache_dirty;
      v872[v949] = 0;
      int * v874 = v804->cache_age;
      v874[v949] = 1;
      int * v876 = v804->cache_age;
      int v877 = v876[v949];
      int v878 = v876[v924];
      int v979 = v878 + ((int)((unsigned int)(v878 - v877) >> 31));
      v876[v924] = v979;
      int * v880 = v804->cache_age;
      int v881 = v880[v925];
      int v981 = v881 + ((int)((unsigned int)(v881 - v877) >> 31));
      v880[v925] = v981;
      int * v883 = v804->cache_age;
      v883[v949] = 0;
      v886 = v949;
    }
    int * v887 = v804->cache_vals;
    int v984 = v886 * 2;
    int v888 = v887[v984];
    int v985 = (v886 * 2) + 1;
    int v889 = v887[v985];
    int v986 = (((((int)((unsigned int)((int)((unsigned int)v810 >> 2)) >> 1)) & 1) * 2) + ((((v828 + ((~(((v830 ^ -1) | (-(v830 ^ -1))) >> 31)) & 2)) - (v831 + ((~(((v832 ^ -1) | (-(v832 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
    v887[v986] = v888;
    int * v891 = v804->cache_vals;
    int v989 = ((((((int)((unsigned int)((int)((unsigned int)v810 >> 2)) >> 1)) & 1) * 2) + ((((v828 + ((~(((v830 ^ -1) | (-(v830 ^ -1))) >> 31)) & 2)) - (v831 + ((~(((v832 ^ -1) | (-(v832 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
    v891[v989] = v889;
    int * v893 = v804->cache_tags;
    int v992 = ((((int)((unsigned int)((int)((unsigned int)v810 >> 2)) >> 1)) & 1) * 2) + ((((v828 + ((~(((v830 ^ -1) | (-(v830 ^ -1))) >> 31)) & 2)) - (v831 + ((~(((v832 ^ -1) | (-(v832 ^ -1))) >> 31)) & 2))) >> 31) & 1);
    int v993 = (int)((unsigned int)((int)((unsigned int)v810 >> 2)) >> 1);
    v893[v992] = v993;
    int * v895 = v804->cache_dirty;
    v895[v992] = 0;
    int * v897 = v804->cache_age;
    v897[v992] = 1;
    int * v899 = v804->cache_age;
    int v900 = v899[v992];
    int v901 = v899[v922];
    int v999 = v901 + ((int)((unsigned int)(v901 - v900) >> 31));
    v899[v922] = v999;
    int * v903 = v804->cache_age;
    int v904 = v903[v923];
    int v1001 = v904 + ((int)((unsigned int)(v904 - v900) >> 31));
    v903[v923] = v1001;
    int * v906 = v804->cache_age;
    v906[v992] = 0;
    v909 = v992;
  }
  int v1004 = (v909 * 2) + (((int)((unsigned int)v810 >> 2)) & 1);
  int v910 = v816[v1004];
  int * v911 = v804->reg_ready;
  int v1006 = ((v808 + ((v805 - v808) & (~((v805 - v808) >> 31)))) + 1) + ((100 ^ (((~(((v814 ^ ((int)((unsigned int)((int)((unsigned int)v810 >> 2)) >> 1))) | (-(v814 ^ ((int)((unsigned int)((int)((unsigned int)v810 >> 2)) >> 1))))) >> 31)) | (~(((v815 ^ ((int)((unsigned int)((int)((unsigned int)v810 >> 2)) >> 1))) | (-(v815 ^ ((int)((unsigned int)((int)((unsigned int)v810 >> 2)) >> 1))))) >> 31))) & 104)) ^ (((~(((v812 ^ ((int)((unsigned int)((int)((unsigned int)v810 >> 2)) >> 1))) | (-(v812 ^ ((int)((unsigned int)((int)((unsigned int)v810 >> 2)) >> 1))))) >> 31)) | (~(((v813 ^ ((int)((unsigned int)((int)((unsigned int)v810 >> 2)) >> 1))) | (-(v813 ^ ((int)((unsigned int)((int)((unsigned int)v810 >> 2)) >> 1))))) >> 31))) & (1 ^ (100 ^ (((~(((v814 ^ ((int)((unsigned int)((int)((unsigned int)v810 >> 2)) >> 1))) | (-(v814 ^ ((int)((unsigned int)((int)((unsigned int)v810 >> 2)) >> 1))))) >> 31)) | (~(((v815 ^ ((int)((unsigned int)((int)((unsigned int)v810 >> 2)) >> 1))) | (-(v815 ^ ((int)((unsigned int)((int)((unsigned int)v810 >> 2)) >> 1))))) >> 31))) & 104)))));
  v911[10] = v1006;
  int * v913 = v804->regs;
  v913[10] = v910;
  struct StateT * v915 = slot_8(v804);
  return v915;
}

struct StateT * slot_21(struct StateT * v548) {
  int v549 = v548->timer;
  int v661 = v549 + 1;
  v548->timer = v661;
  int * v551 = v548->reg_ready;
  int v552 = v551[11];
  int * v553 = v548->regs;
  int v554 = v553[11];
  int * v555 = v548->cache_tags;
  int v666 = (((int)((unsigned int)((int)((unsigned int)(v554 + 68) >> 2)) >> 1)) & 1) * 2;
  int v556 = v555[v666];
  int v667 = ((((int)((unsigned int)((int)((unsigned int)(v554 + 68) >> 2)) >> 1)) & 1) * 2) + 1;
  int v557 = v555[v667];
  int v668 = 4 + ((((int)((unsigned int)((int)((unsigned int)(v554 + 68) >> 2)) >> 1)) & 3) * 2);
  int v558 = v555[v668];
  int v669 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v554 + 68) >> 2)) >> 1)) & 3) * 2)) + 1;
  int v559 = v555[v669];
  int * v560 = v548->cache_vals;
  bool v670 = !(((~(((v556 ^ ((int)((unsigned int)((int)((unsigned int)(v554 + 68) >> 2)) >> 1))) | (-(v556 ^ ((int)((unsigned int)((int)((unsigned int)(v554 + 68) >> 2)) >> 1))))) >> 31)) | (~(((v557 ^ ((int)((unsigned int)((int)((unsigned int)(v554 + 68) >> 2)) >> 1))) | (-(v557 ^ ((int)((unsigned int)((int)((unsigned int)(v554 + 68) >> 2)) >> 1))))) >> 31))) == 0);
  int v653;
  if (v670) {
    int * v561 = v548->cache_age;
    int v672 = ((((int)((unsigned int)((int)((unsigned int)(v554 + 68) >> 2)) >> 1)) & 1) * 2) + ((~(((v557 ^ ((int)((unsigned int)((int)((unsigned int)(v554 + 68) >> 2)) >> 1))) | (-(v557 ^ ((int)((unsigned int)((int)((unsigned int)(v554 + 68) >> 2)) >> 1))))) >> 31)) & 1);
    int v562 = v561[v672];
    int v563 = v561[v666];
    int v673 = v563 + ((int)((unsigned int)(v563 - v562) >> 31));
    v561[v666] = v673;
    int * v565 = v548->cache_age;
    int v566 = v565[v667];
    int v675 = v566 + ((int)((unsigned int)(v566 - v562) >> 31));
    v565[v667] = v675;
    int * v568 = v548->cache_age;
    v568[v672] = 0;
    v653 = v672;
  } else {
    int * v571 = v548->cache_age;
    int v679 = (((int)((unsigned int)((int)((unsigned int)(v554 + 68) >> 2)) >> 1)) & 1) * 2;
    int v572 = v571[v679];
    int * v573 = v548->cache_tags;
    int v574 = v573[v679];
    int v575 = v571[v667];
    int v576 = v573[v667];
    bool v681 = !(((~(((v558 ^ ((int)((unsigned int)((int)((unsigned int)(v554 + 68) >> 2)) >> 1))) | (-(v558 ^ ((int)((unsigned int)((int)((unsigned int)(v554 + 68) >> 2)) >> 1))))) >> 31)) | (~(((v559 ^ ((int)((unsigned int)((int)((unsigned int)(v554 + 68) >> 2)) >> 1))) | (-(v559 ^ ((int)((unsigned int)((int)((unsigned int)(v554 + 68) >> 2)) >> 1))))) >> 31))) == 0);
    int v630;
    if (v681) {
      int * v577 = v548->cache_age;
      int v683 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v554 + 68) >> 2)) >> 1)) & 3) * 2)) + ((~(((v559 ^ ((int)((unsigned int)((int)((unsigned int)(v554 + 68) >> 2)) >> 1))) | (-(v559 ^ ((int)((unsigned int)((int)((unsigned int)(v554 + 68) >> 2)) >> 1))))) >> 31)) & 1);
      int v578 = v577[v683];
      int v579 = v577[v668];
      int v684 = v579 + ((int)((unsigned int)(v579 - v578) >> 31));
      v577[v668] = v684;
      int * v581 = v548->cache_age;
      int v582 = v581[v669];
      int v686 = v582 + ((int)((unsigned int)(v582 - v578) >> 31));
      v581[v669] = v686;
      int * v584 = v548->cache_age;
      v584[v683] = 0;
      v630 = v683;
    } else {
      int * v587 = v548->cache_age;
      int v690 = 4 + ((((int)((unsigned int)((int)((unsigned int)(v554 + 68) >> 2)) >> 1)) & 3) * 2);
      int v588 = v587[v690];
      int * v589 = v548->cache_tags;
      int v590 = v589[v690];
      int v591 = v587[v669];
      int v592 = v589[v669];
      int * v593 = v548->cache_dirty;
      int v693 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v554 + 68) >> 2)) >> 1)) & 3) * 2)) + ((((v588 + ((~(((v590 ^ -1) | (-(v590 ^ -1))) >> 31)) & 2)) - (v591 + ((~(((v592 ^ -1) | (-(v592 ^ -1))) >> 31)) & 2))) >> 31) & 1);
      int v594 = v593[v693];
      bool v694 = !(v594 == 0);
      if (v694) {
        int * v595 = v548->cache_tags;
        int v596 = v595[v693];
        int * v597 = v548->cache_vals;
        int v697 = ((4 + ((((int)((unsigned int)((int)((unsigned int)(v554 + 68) >> 2)) >> 1)) & 3) * 2)) + ((((v588 + ((~(((v590 ^ -1) | (-(v590 ^ -1))) >> 31)) & 2)) - (v591 + ((~(((v592 ^ -1) | (-(v592 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
        int v598 = v597[v697];
        int v698 = (((4 + ((((int)((unsigned int)((int)((unsigned int)(v554 + 68) >> 2)) >> 1)) & 3) * 2)) + ((((v588 + ((~(((v590 ^ -1) | (-(v590 ^ -1))) >> 31)) & 2)) - (v591 + ((~(((v592 ^ -1) | (-(v592 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
        int v599 = v597[v698];
        int * v600 = v548->mem;
        int v700 = v596 * 2;
        v600[v700] = v598;
        int * v602 = v548->mem;
        int v703 = (v596 * 2) + 1;
        v602[v703] = v599;
        ;
      } else {
        ;
      }
      int * v607 = v548->mem;
      int v708 = ((int)((unsigned int)((int)((unsigned int)(v554 + 68) >> 2)) >> 1)) * 2;
      int v608 = v607[v708];
      int v709 = (((int)((unsigned int)((int)((unsigned int)(v554 + 68) >> 2)) >> 1)) * 2) + 1;
      int v609 = v607[v709];
      int * v610 = v548->cache_vals;
      int v711 = ((4 + ((((int)((unsigned int)((int)((unsigned int)(v554 + 68) >> 2)) >> 1)) & 3) * 2)) + ((((v588 + ((~(((v590 ^ -1) | (-(v590 ^ -1))) >> 31)) & 2)) - (v591 + ((~(((v592 ^ -1) | (-(v592 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
      v610[v711] = v608;
      int * v612 = v548->cache_vals;
      int v714 = (((4 + ((((int)((unsigned int)((int)((unsigned int)(v554 + 68) >> 2)) >> 1)) & 3) * 2)) + ((((v588 + ((~(((v590 ^ -1) | (-(v590 ^ -1))) >> 31)) & 2)) - (v591 + ((~(((v592 ^ -1) | (-(v592 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
      v612[v714] = v609;
      int * v614 = v548->cache_tags;
      int v717 = (int)((unsigned int)((int)((unsigned int)(v554 + 68) >> 2)) >> 1);
      v614[v693] = v717;
      int * v616 = v548->cache_dirty;
      v616[v693] = 0;
      int * v618 = v548->cache_age;
      v618[v693] = 1;
      int * v620 = v548->cache_age;
      int v621 = v620[v693];
      int v622 = v620[v668];
      int v723 = v622 + ((int)((unsigned int)(v622 - v621) >> 31));
      v620[v668] = v723;
      int * v624 = v548->cache_age;
      int v625 = v624[v669];
      int v725 = v625 + ((int)((unsigned int)(v625 - v621) >> 31));
      v624[v669] = v725;
      int * v627 = v548->cache_age;
      v627[v693] = 0;
      v630 = v693;
    }
    int * v631 = v548->cache_vals;
    int v728 = v630 * 2;
    int v632 = v631[v728];
    int v729 = (v630 * 2) + 1;
    int v633 = v631[v729];
    int v730 = (((((int)((unsigned int)((int)((unsigned int)(v554 + 68) >> 2)) >> 1)) & 1) * 2) + ((((v572 + ((~(((v574 ^ -1) | (-(v574 ^ -1))) >> 31)) & 2)) - (v575 + ((~(((v576 ^ -1) | (-(v576 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
    v631[v730] = v632;
    int * v635 = v548->cache_vals;
    int v733 = ((((((int)((unsigned int)((int)((unsigned int)(v554 + 68) >> 2)) >> 1)) & 1) * 2) + ((((v572 + ((~(((v574 ^ -1) | (-(v574 ^ -1))) >> 31)) & 2)) - (v575 + ((~(((v576 ^ -1) | (-(v576 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
    v635[v733] = v633;
    int * v637 = v548->cache_tags;
    int v736 = ((((int)((unsigned int)((int)((unsigned int)(v554 + 68) >> 2)) >> 1)) & 1) * 2) + ((((v572 + ((~(((v574 ^ -1) | (-(v574 ^ -1))) >> 31)) & 2)) - (v575 + ((~(((v576 ^ -1) | (-(v576 ^ -1))) >> 31)) & 2))) >> 31) & 1);
    int v737 = (int)((unsigned int)((int)((unsigned int)(v554 + 68) >> 2)) >> 1);
    v637[v736] = v737;
    int * v639 = v548->cache_dirty;
    v639[v736] = 0;
    int * v641 = v548->cache_age;
    v641[v736] = 1;
    int * v643 = v548->cache_age;
    int v644 = v643[v736];
    int v645 = v643[v666];
    int v743 = v645 + ((int)((unsigned int)(v645 - v644) >> 31));
    v643[v666] = v743;
    int * v647 = v548->cache_age;
    int v648 = v647[v667];
    int v745 = v648 + ((int)((unsigned int)(v648 - v644) >> 31));
    v647[v667] = v745;
    int * v650 = v548->cache_age;
    v650[v736] = 0;
    v653 = v736;
  }
  int v748 = (v653 * 2) + (((int)((unsigned int)(v554 + 68) >> 2)) & 1);
  int v654 = v560[v748];
  int * v655 = v548->reg_ready;
  int v751 = ((v552 + ((v549 - v552) & (~((v549 - v552) >> 31)))) + 1) + ((100 ^ (((~(((v558 ^ ((int)((unsigned int)((int)((unsigned int)(v554 + 68) >> 2)) >> 1))) | (-(v558 ^ ((int)((unsigned int)((int)((unsigned int)(v554 + 68) >> 2)) >> 1))))) >> 31)) | (~(((v559 ^ ((int)((unsigned int)((int)((unsigned int)(v554 + 68) >> 2)) >> 1))) | (-(v559 ^ ((int)((unsigned int)((int)((unsigned int)(v554 + 68) >> 2)) >> 1))))) >> 31))) & 104)) ^ (((~(((v556 ^ ((int)((unsigned int)((int)((unsigned int)(v554 + 68) >> 2)) >> 1))) | (-(v556 ^ ((int)((unsigned int)((int)((unsigned int)(v554 + 68) >> 2)) >> 1))))) >> 31)) | (~(((v557 ^ ((int)((unsigned int)((int)((unsigned int)(v554 + 68) >> 2)) >> 1))) | (-(v557 ^ ((int)((unsigned int)((int)((unsigned int)(v554 + 68) >> 2)) >> 1))))) >> 31))) & (1 ^ (100 ^ (((~(((v558 ^ ((int)((unsigned int)((int)((unsigned int)(v554 + 68) >> 2)) >> 1))) | (-(v558 ^ ((int)((unsigned int)((int)((unsigned int)(v554 + 68) >> 2)) >> 1))))) >> 31)) | (~(((v559 ^ ((int)((unsigned int)((int)((unsigned int)(v554 + 68) >> 2)) >> 1))) | (-(v559 ^ ((int)((unsigned int)((int)((unsigned int)(v554 + 68) >> 2)) >> 1))))) >> 31))) & 104)))));
  v655[12] = v751;
  int * v657 = v548->regs;
  v657[12] = v654;
  struct StateT * v659 = slot_22(v548);
  return v659;
}

struct StateT * slot_3(struct StateT * v267) {
  int v268 = v267->timer;
  int v279 = v268 + 1;
  v267->timer = v279;
  int * v270 = v267->reg_ready;
  int v271 = v270[10];
  int * v272 = v267->regs;
  int v273 = v272[10];
  int v283 = (v271 + ((v268 - v271) & (~((v268 - v271) >> 31)))) + 1;
  v270[10] = v283;
  int * v275 = v267->regs;
  int v285 = v273 << 2;
  v275[10] = v285;
  struct StateT * v277 = slot_4(v267);
  return v277;
}

struct StateT * slot_10(struct StateT * v1372) {
  int v1373 = v1372->timer;
  int v1381 = v1373 + 1;
  v1372->timer = v1381;
  int * v1375 = v1372->reg_ready;
  v1375[12] = v1381;
  int * v1377 = v1372->regs;
  v1377[12] = 0;
  struct StateT * v1379 = slot_11(v1372);
  return v1379;
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

struct StateT * slot_19(struct StateT * v288) {
  int v289 = v288->timer;
  int v297 = v289 + 1;
  v288->timer = v297;
  int * v291 = v288->reg_ready;
  v291[11] = v297;
  int * v293 = v288->regs;
  v293[11] = 0;
  struct StateT * v295 = slot_20(v288);
  return v295;
}

struct StateT * slot_13(struct StateT * v1430) {
  int v1431 = v1430->timer;
  int v1444 = v1431 + 1;
  v1430->timer = v1444;
  int * v1433 = v1430->reg_ready;
  int v1434 = v1433[11];
  int * v1435 = v1430->regs;
  int v1436 = v1435[11];
  int v1437 = v1433[10];
  int v1438 = v1435[10];
  int v1449 = (v1437 + (((v1434 + ((v1431 - v1434) & (~((v1431 - v1434) >> 31)))) - v1437) & (~(((v1434 + ((v1431 - v1434) & (~((v1431 - v1434) >> 31)))) - v1437) >> 31)))) + 1;
  v1433[10] = v1449;
  int * v1440 = v1430->regs;
  int v1451 = v1436 + v1438;
  v1440[10] = v1451;
  struct StateT * v1442 = slot_14(v1430);
  return v1442;
}

struct StateT * slot_24(struct StateT * v1346) {
  int v1347 = v1346->timer;
  int v1350 = v1347 + 1;
  v1346->timer = v1350;
  return v1346;
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

struct StateT * slot_14(struct StateT * v1454) {
  int v1455 = v1454->timer;
  int v1567 = v1455 + 1;
  v1454->timer = v1567;
  int * v1457 = v1454->reg_ready;
  int v1458 = v1457[10];
  int * v1459 = v1454->regs;
  int v1460 = v1459[10];
  int * v1461 = v1454->cache_tags;
  int v1572 = (((int)((unsigned int)((int)((unsigned int)v1460 >> 2)) >> 1)) & 1) * 2;
  int v1462 = v1461[v1572];
  int v1573 = ((((int)((unsigned int)((int)((unsigned int)v1460 >> 2)) >> 1)) & 1) * 2) + 1;
  int v1463 = v1461[v1573];
  int v1574 = 4 + ((((int)((unsigned int)((int)((unsigned int)v1460 >> 2)) >> 1)) & 3) * 2);
  int v1464 = v1461[v1574];
  int v1575 = (4 + ((((int)((unsigned int)((int)((unsigned int)v1460 >> 2)) >> 1)) & 3) * 2)) + 1;
  int v1465 = v1461[v1575];
  int * v1466 = v1454->cache_vals;
  bool v1576 = !(((~(((v1462 ^ ((int)((unsigned int)((int)((unsigned int)v1460 >> 2)) >> 1))) | (-(v1462 ^ ((int)((unsigned int)((int)((unsigned int)v1460 >> 2)) >> 1))))) >> 31)) | (~(((v1463 ^ ((int)((unsigned int)((int)((unsigned int)v1460 >> 2)) >> 1))) | (-(v1463 ^ ((int)((unsigned int)((int)((unsigned int)v1460 >> 2)) >> 1))))) >> 31))) == 0);
  int v1559;
  if (v1576) {
    int * v1467 = v1454->cache_age;
    int v1578 = ((((int)((unsigned int)((int)((unsigned int)v1460 >> 2)) >> 1)) & 1) * 2) + ((~(((v1463 ^ ((int)((unsigned int)((int)((unsigned int)v1460 >> 2)) >> 1))) | (-(v1463 ^ ((int)((unsigned int)((int)((unsigned int)v1460 >> 2)) >> 1))))) >> 31)) & 1);
    int v1468 = v1467[v1578];
    int v1469 = v1467[v1572];
    int v1579 = v1469 + ((int)((unsigned int)(v1469 - v1468) >> 31));
    v1467[v1572] = v1579;
    int * v1471 = v1454->cache_age;
    int v1472 = v1471[v1573];
    int v1581 = v1472 + ((int)((unsigned int)(v1472 - v1468) >> 31));
    v1471[v1573] = v1581;
    int * v1474 = v1454->cache_age;
    v1474[v1578] = 0;
    v1559 = v1578;
  } else {
    int * v1477 = v1454->cache_age;
    int v1585 = (((int)((unsigned int)((int)((unsigned int)v1460 >> 2)) >> 1)) & 1) * 2;
    int v1478 = v1477[v1585];
    int * v1479 = v1454->cache_tags;
    int v1480 = v1479[v1585];
    int v1481 = v1477[v1573];
    int v1482 = v1479[v1573];
    bool v1587 = !(((~(((v1464 ^ ((int)((unsigned int)((int)((unsigned int)v1460 >> 2)) >> 1))) | (-(v1464 ^ ((int)((unsigned int)((int)((unsigned int)v1460 >> 2)) >> 1))))) >> 31)) | (~(((v1465 ^ ((int)((unsigned int)((int)((unsigned int)v1460 >> 2)) >> 1))) | (-(v1465 ^ ((int)((unsigned int)((int)((unsigned int)v1460 >> 2)) >> 1))))) >> 31))) == 0);
    int v1536;
    if (v1587) {
      int * v1483 = v1454->cache_age;
      int v1589 = (4 + ((((int)((unsigned int)((int)((unsigned int)v1460 >> 2)) >> 1)) & 3) * 2)) + ((~(((v1465 ^ ((int)((unsigned int)((int)((unsigned int)v1460 >> 2)) >> 1))) | (-(v1465 ^ ((int)((unsigned int)((int)((unsigned int)v1460 >> 2)) >> 1))))) >> 31)) & 1);
      int v1484 = v1483[v1589];
      int v1485 = v1483[v1574];
      int v1590 = v1485 + ((int)((unsigned int)(v1485 - v1484) >> 31));
      v1483[v1574] = v1590;
      int * v1487 = v1454->cache_age;
      int v1488 = v1487[v1575];
      int v1592 = v1488 + ((int)((unsigned int)(v1488 - v1484) >> 31));
      v1487[v1575] = v1592;
      int * v1490 = v1454->cache_age;
      v1490[v1589] = 0;
      v1536 = v1589;
    } else {
      int * v1493 = v1454->cache_age;
      int v1596 = 4 + ((((int)((unsigned int)((int)((unsigned int)v1460 >> 2)) >> 1)) & 3) * 2);
      int v1494 = v1493[v1596];
      int * v1495 = v1454->cache_tags;
      int v1496 = v1495[v1596];
      int v1497 = v1493[v1575];
      int v1498 = v1495[v1575];
      int * v1499 = v1454->cache_dirty;
      int v1599 = (4 + ((((int)((unsigned int)((int)((unsigned int)v1460 >> 2)) >> 1)) & 3) * 2)) + ((((v1494 + ((~(((v1496 ^ -1) | (-(v1496 ^ -1))) >> 31)) & 2)) - (v1497 + ((~(((v1498 ^ -1) | (-(v1498 ^ -1))) >> 31)) & 2))) >> 31) & 1);
      int v1500 = v1499[v1599];
      bool v1600 = !(v1500 == 0);
      if (v1600) {
        int * v1501 = v1454->cache_tags;
        int v1502 = v1501[v1599];
        int * v1503 = v1454->cache_vals;
        int v1603 = ((4 + ((((int)((unsigned int)((int)((unsigned int)v1460 >> 2)) >> 1)) & 3) * 2)) + ((((v1494 + ((~(((v1496 ^ -1) | (-(v1496 ^ -1))) >> 31)) & 2)) - (v1497 + ((~(((v1498 ^ -1) | (-(v1498 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
        int v1504 = v1503[v1603];
        int v1604 = (((4 + ((((int)((unsigned int)((int)((unsigned int)v1460 >> 2)) >> 1)) & 3) * 2)) + ((((v1494 + ((~(((v1496 ^ -1) | (-(v1496 ^ -1))) >> 31)) & 2)) - (v1497 + ((~(((v1498 ^ -1) | (-(v1498 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
        int v1505 = v1503[v1604];
        int * v1506 = v1454->mem;
        int v1606 = v1502 * 2;
        v1506[v1606] = v1504;
        int * v1508 = v1454->mem;
        int v1609 = (v1502 * 2) + 1;
        v1508[v1609] = v1505;
        ;
      } else {
        ;
      }
      int * v1513 = v1454->mem;
      int v1614 = ((int)((unsigned int)((int)((unsigned int)v1460 >> 2)) >> 1)) * 2;
      int v1514 = v1513[v1614];
      int v1615 = (((int)((unsigned int)((int)((unsigned int)v1460 >> 2)) >> 1)) * 2) + 1;
      int v1515 = v1513[v1615];
      int * v1516 = v1454->cache_vals;
      int v1617 = ((4 + ((((int)((unsigned int)((int)((unsigned int)v1460 >> 2)) >> 1)) & 3) * 2)) + ((((v1494 + ((~(((v1496 ^ -1) | (-(v1496 ^ -1))) >> 31)) & 2)) - (v1497 + ((~(((v1498 ^ -1) | (-(v1498 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
      v1516[v1617] = v1514;
      int * v1518 = v1454->cache_vals;
      int v1620 = (((4 + ((((int)((unsigned int)((int)((unsigned int)v1460 >> 2)) >> 1)) & 3) * 2)) + ((((v1494 + ((~(((v1496 ^ -1) | (-(v1496 ^ -1))) >> 31)) & 2)) - (v1497 + ((~(((v1498 ^ -1) | (-(v1498 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
      v1518[v1620] = v1515;
      int * v1520 = v1454->cache_tags;
      int v1623 = (int)((unsigned int)((int)((unsigned int)v1460 >> 2)) >> 1);
      v1520[v1599] = v1623;
      int * v1522 = v1454->cache_dirty;
      v1522[v1599] = 0;
      int * v1524 = v1454->cache_age;
      v1524[v1599] = 1;
      int * v1526 = v1454->cache_age;
      int v1527 = v1526[v1599];
      int v1528 = v1526[v1574];
      int v1629 = v1528 + ((int)((unsigned int)(v1528 - v1527) >> 31));
      v1526[v1574] = v1629;
      int * v1530 = v1454->cache_age;
      int v1531 = v1530[v1575];
      int v1631 = v1531 + ((int)((unsigned int)(v1531 - v1527) >> 31));
      v1530[v1575] = v1631;
      int * v1533 = v1454->cache_age;
      v1533[v1599] = 0;
      v1536 = v1599;
    }
    int * v1537 = v1454->cache_vals;
    int v1634 = v1536 * 2;
    int v1538 = v1537[v1634];
    int v1635 = (v1536 * 2) + 1;
    int v1539 = v1537[v1635];
    int v1636 = (((((int)((unsigned int)((int)((unsigned int)v1460 >> 2)) >> 1)) & 1) * 2) + ((((v1478 + ((~(((v1480 ^ -1) | (-(v1480 ^ -1))) >> 31)) & 2)) - (v1481 + ((~(((v1482 ^ -1) | (-(v1482 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
    v1537[v1636] = v1538;
    int * v1541 = v1454->cache_vals;
    int v1639 = ((((((int)((unsigned int)((int)((unsigned int)v1460 >> 2)) >> 1)) & 1) * 2) + ((((v1478 + ((~(((v1480 ^ -1) | (-(v1480 ^ -1))) >> 31)) & 2)) - (v1481 + ((~(((v1482 ^ -1) | (-(v1482 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
    v1541[v1639] = v1539;
    int * v1543 = v1454->cache_tags;
    int v1642 = ((((int)((unsigned int)((int)((unsigned int)v1460 >> 2)) >> 1)) & 1) * 2) + ((((v1478 + ((~(((v1480 ^ -1) | (-(v1480 ^ -1))) >> 31)) & 2)) - (v1481 + ((~(((v1482 ^ -1) | (-(v1482 ^ -1))) >> 31)) & 2))) >> 31) & 1);
    int v1643 = (int)((unsigned int)((int)((unsigned int)v1460 >> 2)) >> 1);
    v1543[v1642] = v1643;
    int * v1545 = v1454->cache_dirty;
    v1545[v1642] = 0;
    int * v1547 = v1454->cache_age;
    v1547[v1642] = 1;
    int * v1549 = v1454->cache_age;
    int v1550 = v1549[v1642];
    int v1551 = v1549[v1572];
    int v1649 = v1551 + ((int)((unsigned int)(v1551 - v1550) >> 31));
    v1549[v1572] = v1649;
    int * v1553 = v1454->cache_age;
    int v1554 = v1553[v1573];
    int v1651 = v1554 + ((int)((unsigned int)(v1554 - v1550) >> 31));
    v1553[v1573] = v1651;
    int * v1556 = v1454->cache_age;
    v1556[v1642] = 0;
    v1559 = v1642;
  }
  int v1654 = (v1559 * 2) + (((int)((unsigned int)v1460 >> 2)) & 1);
  int v1560 = v1466[v1654];
  int * v1561 = v1454->reg_ready;
  int v1656 = ((v1458 + ((v1455 - v1458) & (~((v1455 - v1458) >> 31)))) + 1) + ((100 ^ (((~(((v1464 ^ ((int)((unsigned int)((int)((unsigned int)v1460 >> 2)) >> 1))) | (-(v1464 ^ ((int)((unsigned int)((int)((unsigned int)v1460 >> 2)) >> 1))))) >> 31)) | (~(((v1465 ^ ((int)((unsigned int)((int)((unsigned int)v1460 >> 2)) >> 1))) | (-(v1465 ^ ((int)((unsigned int)((int)((unsigned int)v1460 >> 2)) >> 1))))) >> 31))) & 104)) ^ (((~(((v1462 ^ ((int)((unsigned int)((int)((unsigned int)v1460 >> 2)) >> 1))) | (-(v1462 ^ ((int)((unsigned int)((int)((unsigned int)v1460 >> 2)) >> 1))))) >> 31)) | (~(((v1463 ^ ((int)((unsigned int)((int)((unsigned int)v1460 >> 2)) >> 1))) | (-(v1463 ^ ((int)((unsigned int)((int)((unsigned int)v1460 >> 2)) >> 1))))) >> 31))) & (1 ^ (100 ^ (((~(((v1464 ^ ((int)((unsigned int)((int)((unsigned int)v1460 >> 2)) >> 1))) | (-(v1464 ^ ((int)((unsigned int)((int)((unsigned int)v1460 >> 2)) >> 1))))) >> 31)) | (~(((v1465 ^ ((int)((unsigned int)((int)((unsigned int)v1460 >> 2)) >> 1))) | (-(v1465 ^ ((int)((unsigned int)((int)((unsigned int)v1460 >> 2)) >> 1))))) >> 31))) & 104)))));
  v1561[10] = v1656;
  int * v1563 = v1454->regs;
  v1563[10] = v1560;
  struct StateT * v1565 = slot_15(v1454);
  return v1565;
}

struct StateT * slot_17(struct StateT * v1893) {
  int v1894 = v1893->timer;
  int v2067 = v1894 + 1;
  v1893->timer = v2067;
  int * v1896 = v1893->reg_ready;
  int * v1898 = v1893->regs;
  int v1899 = v1898[12];
  int v1901 = v1898[10];
  int * v1902 = v1893->cache_tags;
  int v2073 = (((int)((unsigned int)((int)((unsigned int)(v1899 + 68) >> 2)) >> 1)) & 1) * 2;
  int v1903 = v1902[v2073];
  int v2074 = ((((int)((unsigned int)((int)((unsigned int)(v1899 + 68) >> 2)) >> 1)) & 1) * 2) + 1;
  int v1904 = v1902[v2074];
  int v2075 = 4 + ((((int)((unsigned int)((int)((unsigned int)(v1899 + 68) >> 2)) >> 1)) & 3) * 2);
  int v1905 = v1902[v2075];
  int v2076 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v1899 + 68) >> 2)) >> 1)) & 3) * 2)) + 1;
  int v1906 = v1902[v2076];
  int v1907 = v1893->timer;
  int v2077 = v1907 + ((100 ^ (((~(((v1905 ^ ((int)((unsigned int)((int)((unsigned int)(v1899 + 68) >> 2)) >> 1))) | (-(v1905 ^ ((int)((unsigned int)((int)((unsigned int)(v1899 + 68) >> 2)) >> 1))))) >> 31)) | (~(((v1906 ^ ((int)((unsigned int)((int)((unsigned int)(v1899 + 68) >> 2)) >> 1))) | (-(v1906 ^ ((int)((unsigned int)((int)((unsigned int)(v1899 + 68) >> 2)) >> 1))))) >> 31))) & 104)) ^ (((~(((v1903 ^ ((int)((unsigned int)((int)((unsigned int)(v1899 + 68) >> 2)) >> 1))) | (-(v1903 ^ ((int)((unsigned int)((int)((unsigned int)(v1899 + 68) >> 2)) >> 1))))) >> 31)) | (~(((v1904 ^ ((int)((unsigned int)((int)((unsigned int)(v1899 + 68) >> 2)) >> 1))) | (-(v1904 ^ ((int)((unsigned int)((int)((unsigned int)(v1899 + 68) >> 2)) >> 1))))) >> 31))) & (1 ^ (100 ^ (((~(((v1905 ^ ((int)((unsigned int)((int)((unsigned int)(v1899 + 68) >> 2)) >> 1))) | (-(v1905 ^ ((int)((unsigned int)((int)((unsigned int)(v1899 + 68) >> 2)) >> 1))))) >> 31)) | (~(((v1906 ^ ((int)((unsigned int)((int)((unsigned int)(v1899 + 68) >> 2)) >> 1))) | (-(v1906 ^ ((int)((unsigned int)((int)((unsigned int)(v1899 + 68) >> 2)) >> 1))))) >> 31))) & 104)))));
  v1893->timer = v2077;
  bool v2078 = !(((~(((v1903 ^ ((int)((unsigned int)((int)((unsigned int)(v1899 + 68) >> 2)) >> 1))) | (-(v1903 ^ ((int)((unsigned int)((int)((unsigned int)(v1899 + 68) >> 2)) >> 1))))) >> 31)) | (~(((v1904 ^ ((int)((unsigned int)((int)((unsigned int)(v1899 + 68) >> 2)) >> 1))) | (-(v1904 ^ ((int)((unsigned int)((int)((unsigned int)(v1899 + 68) >> 2)) >> 1))))) >> 31))) == 0);
  int v2001;
  if (v2078) {
    int * v1909 = v1893->cache_age;
    int v2080 = ((((int)((unsigned int)((int)((unsigned int)(v1899 + 68) >> 2)) >> 1)) & 1) * 2) + ((~(((v1904 ^ ((int)((unsigned int)((int)((unsigned int)(v1899 + 68) >> 2)) >> 1))) | (-(v1904 ^ ((int)((unsigned int)((int)((unsigned int)(v1899 + 68) >> 2)) >> 1))))) >> 31)) & 1);
    int v1910 = v1909[v2080];
    int v1911 = v1909[v2073];
    int v2081 = v1911 + ((int)((unsigned int)(v1911 - v1910) >> 31));
    v1909[v2073] = v2081;
    int * v1913 = v1893->cache_age;
    int v1914 = v1913[v2074];
    int v2083 = v1914 + ((int)((unsigned int)(v1914 - v1910) >> 31));
    v1913[v2074] = v2083;
    int * v1916 = v1893->cache_age;
    v1916[v2080] = 0;
    v2001 = v2080;
  } else {
    int * v1919 = v1893->cache_age;
    int v2087 = (((int)((unsigned int)((int)((unsigned int)(v1899 + 68) >> 2)) >> 1)) & 1) * 2;
    int v1920 = v1919[v2087];
    int * v1921 = v1893->cache_tags;
    int v1922 = v1921[v2087];
    int v1923 = v1919[v2074];
    int v1924 = v1921[v2074];
    bool v2089 = !(((~(((v1905 ^ ((int)((unsigned int)((int)((unsigned int)(v1899 + 68) >> 2)) >> 1))) | (-(v1905 ^ ((int)((unsigned int)((int)((unsigned int)(v1899 + 68) >> 2)) >> 1))))) >> 31)) | (~(((v1906 ^ ((int)((unsigned int)((int)((unsigned int)(v1899 + 68) >> 2)) >> 1))) | (-(v1906 ^ ((int)((unsigned int)((int)((unsigned int)(v1899 + 68) >> 2)) >> 1))))) >> 31))) == 0);
    int v1978;
    if (v2089) {
      int * v1925 = v1893->cache_age;
      int v2091 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v1899 + 68) >> 2)) >> 1)) & 3) * 2)) + ((~(((v1906 ^ ((int)((unsigned int)((int)((unsigned int)(v1899 + 68) >> 2)) >> 1))) | (-(v1906 ^ ((int)((unsigned int)((int)((unsigned int)(v1899 + 68) >> 2)) >> 1))))) >> 31)) & 1);
      int v1926 = v1925[v2091];
      int v1927 = v1925[v2075];
      int v2092 = v1927 + ((int)((unsigned int)(v1927 - v1926) >> 31));
      v1925[v2075] = v2092;
      int * v1929 = v1893->cache_age;
      int v1930 = v1929[v2076];
      int v2094 = v1930 + ((int)((unsigned int)(v1930 - v1926) >> 31));
      v1929[v2076] = v2094;
      int * v1932 = v1893->cache_age;
      v1932[v2091] = 0;
      v1978 = v2091;
    } else {
      int * v1935 = v1893->cache_age;
      int v2098 = 4 + ((((int)((unsigned int)((int)((unsigned int)(v1899 + 68) >> 2)) >> 1)) & 3) * 2);
      int v1936 = v1935[v2098];
      int * v1937 = v1893->cache_tags;
      int v1938 = v1937[v2098];
      int v1939 = v1935[v2076];
      int v1940 = v1937[v2076];
      int * v1941 = v1893->cache_dirty;
      int v2101 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v1899 + 68) >> 2)) >> 1)) & 3) * 2)) + ((((v1936 + ((~(((v1938 ^ -1) | (-(v1938 ^ -1))) >> 31)) & 2)) - (v1939 + ((~(((v1940 ^ -1) | (-(v1940 ^ -1))) >> 31)) & 2))) >> 31) & 1);
      int v1942 = v1941[v2101];
      bool v2102 = !(v1942 == 0);
      if (v2102) {
        int * v1943 = v1893->cache_tags;
        int v1944 = v1943[v2101];
        int * v1945 = v1893->cache_vals;
        int v2105 = ((4 + ((((int)((unsigned int)((int)((unsigned int)(v1899 + 68) >> 2)) >> 1)) & 3) * 2)) + ((((v1936 + ((~(((v1938 ^ -1) | (-(v1938 ^ -1))) >> 31)) & 2)) - (v1939 + ((~(((v1940 ^ -1) | (-(v1940 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
        int v1946 = v1945[v2105];
        int v2106 = (((4 + ((((int)((unsigned int)((int)((unsigned int)(v1899 + 68) >> 2)) >> 1)) & 3) * 2)) + ((((v1936 + ((~(((v1938 ^ -1) | (-(v1938 ^ -1))) >> 31)) & 2)) - (v1939 + ((~(((v1940 ^ -1) | (-(v1940 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
        int v1947 = v1945[v2106];
        int * v1948 = v1893->mem;
        int v2108 = v1944 * 2;
        v1948[v2108] = v1946;
        int * v1950 = v1893->mem;
        int v2111 = (v1944 * 2) + 1;
        v1950[v2111] = v1947;
        ;
      } else {
        ;
      }
      int * v1955 = v1893->mem;
      int v2116 = ((int)((unsigned int)((int)((unsigned int)(v1899 + 68) >> 2)) >> 1)) * 2;
      int v1956 = v1955[v2116];
      int v2117 = (((int)((unsigned int)((int)((unsigned int)(v1899 + 68) >> 2)) >> 1)) * 2) + 1;
      int v1957 = v1955[v2117];
      int * v1958 = v1893->cache_vals;
      int v2119 = ((4 + ((((int)((unsigned int)((int)((unsigned int)(v1899 + 68) >> 2)) >> 1)) & 3) * 2)) + ((((v1936 + ((~(((v1938 ^ -1) | (-(v1938 ^ -1))) >> 31)) & 2)) - (v1939 + ((~(((v1940 ^ -1) | (-(v1940 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
      v1958[v2119] = v1956;
      int * v1960 = v1893->cache_vals;
      int v2122 = (((4 + ((((int)((unsigned int)((int)((unsigned int)(v1899 + 68) >> 2)) >> 1)) & 3) * 2)) + ((((v1936 + ((~(((v1938 ^ -1) | (-(v1938 ^ -1))) >> 31)) & 2)) - (v1939 + ((~(((v1940 ^ -1) | (-(v1940 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
      v1960[v2122] = v1957;
      int * v1962 = v1893->cache_tags;
      int v2125 = (int)((unsigned int)((int)((unsigned int)(v1899 + 68) >> 2)) >> 1);
      v1962[v2101] = v2125;
      int * v1964 = v1893->cache_dirty;
      v1964[v2101] = 0;
      int * v1966 = v1893->cache_age;
      v1966[v2101] = 1;
      int * v1968 = v1893->cache_age;
      int v1969 = v1968[v2101];
      int v1970 = v1968[v2075];
      int v2131 = v1970 + ((int)((unsigned int)(v1970 - v1969) >> 31));
      v1968[v2075] = v2131;
      int * v1972 = v1893->cache_age;
      int v1973 = v1972[v2076];
      int v2133 = v1973 + ((int)((unsigned int)(v1973 - v1969) >> 31));
      v1972[v2076] = v2133;
      int * v1975 = v1893->cache_age;
      v1975[v2101] = 0;
      v1978 = v2101;
    }
    int * v1979 = v1893->cache_vals;
    int v2136 = v1978 * 2;
    int v1980 = v1979[v2136];
    int v2137 = (v1978 * 2) + 1;
    int v1981 = v1979[v2137];
    int v2138 = (((((int)((unsigned int)((int)((unsigned int)(v1899 + 68) >> 2)) >> 1)) & 1) * 2) + ((((v1920 + ((~(((v1922 ^ -1) | (-(v1922 ^ -1))) >> 31)) & 2)) - (v1923 + ((~(((v1924 ^ -1) | (-(v1924 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
    v1979[v2138] = v1980;
    int * v1983 = v1893->cache_vals;
    int v2141 = ((((((int)((unsigned int)((int)((unsigned int)(v1899 + 68) >> 2)) >> 1)) & 1) * 2) + ((((v1920 + ((~(((v1922 ^ -1) | (-(v1922 ^ -1))) >> 31)) & 2)) - (v1923 + ((~(((v1924 ^ -1) | (-(v1924 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
    v1983[v2141] = v1981;
    int * v1985 = v1893->cache_tags;
    int v2144 = ((((int)((unsigned int)((int)((unsigned int)(v1899 + 68) >> 2)) >> 1)) & 1) * 2) + ((((v1920 + ((~(((v1922 ^ -1) | (-(v1922 ^ -1))) >> 31)) & 2)) - (v1923 + ((~(((v1924 ^ -1) | (-(v1924 ^ -1))) >> 31)) & 2))) >> 31) & 1);
    int v2145 = (int)((unsigned int)((int)((unsigned int)(v1899 + 68) >> 2)) >> 1);
    v1985[v2144] = v2145;
    int * v1987 = v1893->cache_dirty;
    v1987[v2144] = 0;
    int * v1989 = v1893->cache_age;
    v1989[v2144] = 1;
    int * v1991 = v1893->cache_age;
    int v1992 = v1991[v2144];
    int v1993 = v1991[v2073];
    int v2151 = v1993 + ((int)((unsigned int)(v1993 - v1992) >> 31));
    v1991[v2073] = v2151;
    int * v1995 = v1893->cache_age;
    int v1996 = v1995[v2074];
    int v2153 = v1996 + ((int)((unsigned int)(v1996 - v1992) >> 31));
    v1995[v2074] = v2153;
    int * v1998 = v1893->cache_age;
    v1998[v2144] = 0;
    v2001 = v2144;
  }
  int * v2002 = v1893->cache_vals;
  int v2156 = (v2001 * 2) + (((int)((unsigned int)(v1899 + 68) >> 2)) & 1);
  v2002[v2156] = v1901;
  int * v2004 = v1893->cache_tags;
  int v2005 = v2004[v2075];
  int v2006 = v2004[v2076];
  bool v2159 = !(((~(((v2005 ^ ((int)((unsigned int)((int)((unsigned int)(v1899 + 68) >> 2)) >> 1))) | (-(v2005 ^ ((int)((unsigned int)((int)((unsigned int)(v1899 + 68) >> 2)) >> 1))))) >> 31)) | (~(((v2006 ^ ((int)((unsigned int)((int)((unsigned int)(v1899 + 68) >> 2)) >> 1))) | (-(v2006 ^ ((int)((unsigned int)((int)((unsigned int)(v1899 + 68) >> 2)) >> 1))))) >> 31))) == 0);
  int v2060;
  if (v2159) {
    int * v2007 = v1893->cache_age;
    int v2161 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v1899 + 68) >> 2)) >> 1)) & 3) * 2)) + ((~(((v2006 ^ ((int)((unsigned int)((int)((unsigned int)(v1899 + 68) >> 2)) >> 1))) | (-(v2006 ^ ((int)((unsigned int)((int)((unsigned int)(v1899 + 68) >> 2)) >> 1))))) >> 31)) & 1);
    int v2008 = v2007[v2161];
    int v2009 = v2007[v2075];
    int v2162 = v2009 + ((int)((unsigned int)(v2009 - v2008) >> 31));
    v2007[v2075] = v2162;
    int * v2011 = v1893->cache_age;
    int v2012 = v2011[v2076];
    int v2164 = v2012 + ((int)((unsigned int)(v2012 - v2008) >> 31));
    v2011[v2076] = v2164;
    int * v2014 = v1893->cache_age;
    v2014[v2161] = 0;
    v2060 = v2161;
  } else {
    int * v2017 = v1893->cache_age;
    int v2168 = 4 + ((((int)((unsigned int)((int)((unsigned int)(v1899 + 68) >> 2)) >> 1)) & 3) * 2);
    int v2018 = v2017[v2168];
    int * v2019 = v1893->cache_tags;
    int v2020 = v2019[v2168];
    int v2021 = v2017[v2076];
    int v2022 = v2019[v2076];
    int * v2023 = v1893->cache_dirty;
    int v2171 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v1899 + 68) >> 2)) >> 1)) & 3) * 2)) + ((((v2018 + ((~(((v2020 ^ -1) | (-(v2020 ^ -1))) >> 31)) & 2)) - (v2021 + ((~(((v2022 ^ -1) | (-(v2022 ^ -1))) >> 31)) & 2))) >> 31) & 1);
    int v2024 = v2023[v2171];
    bool v2172 = !(v2024 == 0);
    if (v2172) {
      int * v2025 = v1893->cache_tags;
      int v2026 = v2025[v2171];
      int * v2027 = v1893->cache_vals;
      int v2175 = ((4 + ((((int)((unsigned int)((int)((unsigned int)(v1899 + 68) >> 2)) >> 1)) & 3) * 2)) + ((((v2018 + ((~(((v2020 ^ -1) | (-(v2020 ^ -1))) >> 31)) & 2)) - (v2021 + ((~(((v2022 ^ -1) | (-(v2022 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
      int v2028 = v2027[v2175];
      int v2176 = (((4 + ((((int)((unsigned int)((int)((unsigned int)(v1899 + 68) >> 2)) >> 1)) & 3) * 2)) + ((((v2018 + ((~(((v2020 ^ -1) | (-(v2020 ^ -1))) >> 31)) & 2)) - (v2021 + ((~(((v2022 ^ -1) | (-(v2022 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
      int v2029 = v2027[v2176];
      int * v2030 = v1893->mem;
      int v2178 = v2026 * 2;
      v2030[v2178] = v2028;
      int * v2032 = v1893->mem;
      int v2181 = (v2026 * 2) + 1;
      v2032[v2181] = v2029;
      ;
    } else {
      ;
    }
    int * v2037 = v1893->mem;
    int v2186 = ((int)((unsigned int)((int)((unsigned int)(v1899 + 68) >> 2)) >> 1)) * 2;
    int v2038 = v2037[v2186];
    int v2187 = (((int)((unsigned int)((int)((unsigned int)(v1899 + 68) >> 2)) >> 1)) * 2) + 1;
    int v2039 = v2037[v2187];
    int * v2040 = v1893->cache_vals;
    int v2189 = ((4 + ((((int)((unsigned int)((int)((unsigned int)(v1899 + 68) >> 2)) >> 1)) & 3) * 2)) + ((((v2018 + ((~(((v2020 ^ -1) | (-(v2020 ^ -1))) >> 31)) & 2)) - (v2021 + ((~(((v2022 ^ -1) | (-(v2022 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
    v2040[v2189] = v2038;
    int * v2042 = v1893->cache_vals;
    int v2192 = (((4 + ((((int)((unsigned int)((int)((unsigned int)(v1899 + 68) >> 2)) >> 1)) & 3) * 2)) + ((((v2018 + ((~(((v2020 ^ -1) | (-(v2020 ^ -1))) >> 31)) & 2)) - (v2021 + ((~(((v2022 ^ -1) | (-(v2022 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
    v2042[v2192] = v2039;
    int * v2044 = v1893->cache_tags;
    int v2195 = (int)((unsigned int)((int)((unsigned int)(v1899 + 68) >> 2)) >> 1);
    v2044[v2171] = v2195;
    int * v2046 = v1893->cache_dirty;
    v2046[v2171] = 0;
    int * v2048 = v1893->cache_age;
    v2048[v2171] = 1;
    int * v2050 = v1893->cache_age;
    int v2051 = v2050[v2171];
    int v2052 = v2050[v2075];
    int v2201 = v2052 + ((int)((unsigned int)(v2052 - v2051) >> 31));
    v2050[v2075] = v2201;
    int * v2054 = v1893->cache_age;
    int v2055 = v2054[v2076];
    int v2203 = v2055 + ((int)((unsigned int)(v2055 - v2051) >> 31));
    v2054[v2076] = v2203;
    int * v2057 = v1893->cache_age;
    v2057[v2171] = 0;
    v2060 = v2171;
  }
  int * v2061 = v1893->cache_vals;
  int v2206 = (v2060 * 2) + (((int)((unsigned int)(v1899 + 68) >> 2)) & 1);
  v2061[v2206] = v1901;
  int * v2063 = v1893->cache_dirty;
  v2063[v2060] = 1;
  struct StateT * v2065 = slot_18(v1893);
  return v2065;
}

struct StateT * slot_20(struct StateT * v320) {
  int v321 = v320->timer;
  int v433 = v321 + 1;
  v320->timer = v433;
  int * v323 = v320->reg_ready;
  int v324 = v323[10];
  int * v325 = v320->regs;
  int v326 = v325[10];
  int * v327 = v320->cache_tags;
  int v438 = (((int)((unsigned int)((int)((unsigned int)(v326 + 4) >> 2)) >> 1)) & 1) * 2;
  int v328 = v327[v438];
  int v439 = ((((int)((unsigned int)((int)((unsigned int)(v326 + 4) >> 2)) >> 1)) & 1) * 2) + 1;
  int v329 = v327[v439];
  int v440 = 4 + ((((int)((unsigned int)((int)((unsigned int)(v326 + 4) >> 2)) >> 1)) & 3) * 2);
  int v330 = v327[v440];
  int v441 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v326 + 4) >> 2)) >> 1)) & 3) * 2)) + 1;
  int v331 = v327[v441];
  int * v332 = v320->cache_vals;
  bool v442 = !(((~(((v328 ^ ((int)((unsigned int)((int)((unsigned int)(v326 + 4) >> 2)) >> 1))) | (-(v328 ^ ((int)((unsigned int)((int)((unsigned int)(v326 + 4) >> 2)) >> 1))))) >> 31)) | (~(((v329 ^ ((int)((unsigned int)((int)((unsigned int)(v326 + 4) >> 2)) >> 1))) | (-(v329 ^ ((int)((unsigned int)((int)((unsigned int)(v326 + 4) >> 2)) >> 1))))) >> 31))) == 0);
  int v425;
  if (v442) {
    int * v333 = v320->cache_age;
    int v444 = ((((int)((unsigned int)((int)((unsigned int)(v326 + 4) >> 2)) >> 1)) & 1) * 2) + ((~(((v329 ^ ((int)((unsigned int)((int)((unsigned int)(v326 + 4) >> 2)) >> 1))) | (-(v329 ^ ((int)((unsigned int)((int)((unsigned int)(v326 + 4) >> 2)) >> 1))))) >> 31)) & 1);
    int v334 = v333[v444];
    int v335 = v333[v438];
    int v445 = v335 + ((int)((unsigned int)(v335 - v334) >> 31));
    v333[v438] = v445;
    int * v337 = v320->cache_age;
    int v338 = v337[v439];
    int v447 = v338 + ((int)((unsigned int)(v338 - v334) >> 31));
    v337[v439] = v447;
    int * v340 = v320->cache_age;
    v340[v444] = 0;
    v425 = v444;
  } else {
    int * v343 = v320->cache_age;
    int v451 = (((int)((unsigned int)((int)((unsigned int)(v326 + 4) >> 2)) >> 1)) & 1) * 2;
    int v344 = v343[v451];
    int * v345 = v320->cache_tags;
    int v346 = v345[v451];
    int v347 = v343[v439];
    int v348 = v345[v439];
    bool v453 = !(((~(((v330 ^ ((int)((unsigned int)((int)((unsigned int)(v326 + 4) >> 2)) >> 1))) | (-(v330 ^ ((int)((unsigned int)((int)((unsigned int)(v326 + 4) >> 2)) >> 1))))) >> 31)) | (~(((v331 ^ ((int)((unsigned int)((int)((unsigned int)(v326 + 4) >> 2)) >> 1))) | (-(v331 ^ ((int)((unsigned int)((int)((unsigned int)(v326 + 4) >> 2)) >> 1))))) >> 31))) == 0);
    int v402;
    if (v453) {
      int * v349 = v320->cache_age;
      int v455 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v326 + 4) >> 2)) >> 1)) & 3) * 2)) + ((~(((v331 ^ ((int)((unsigned int)((int)((unsigned int)(v326 + 4) >> 2)) >> 1))) | (-(v331 ^ ((int)((unsigned int)((int)((unsigned int)(v326 + 4) >> 2)) >> 1))))) >> 31)) & 1);
      int v350 = v349[v455];
      int v351 = v349[v440];
      int v456 = v351 + ((int)((unsigned int)(v351 - v350) >> 31));
      v349[v440] = v456;
      int * v353 = v320->cache_age;
      int v354 = v353[v441];
      int v458 = v354 + ((int)((unsigned int)(v354 - v350) >> 31));
      v353[v441] = v458;
      int * v356 = v320->cache_age;
      v356[v455] = 0;
      v402 = v455;
    } else {
      int * v359 = v320->cache_age;
      int v462 = 4 + ((((int)((unsigned int)((int)((unsigned int)(v326 + 4) >> 2)) >> 1)) & 3) * 2);
      int v360 = v359[v462];
      int * v361 = v320->cache_tags;
      int v362 = v361[v462];
      int v363 = v359[v441];
      int v364 = v361[v441];
      int * v365 = v320->cache_dirty;
      int v465 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v326 + 4) >> 2)) >> 1)) & 3) * 2)) + ((((v360 + ((~(((v362 ^ -1) | (-(v362 ^ -1))) >> 31)) & 2)) - (v363 + ((~(((v364 ^ -1) | (-(v364 ^ -1))) >> 31)) & 2))) >> 31) & 1);
      int v366 = v365[v465];
      bool v466 = !(v366 == 0);
      if (v466) {
        int * v367 = v320->cache_tags;
        int v368 = v367[v465];
        int * v369 = v320->cache_vals;
        int v469 = ((4 + ((((int)((unsigned int)((int)((unsigned int)(v326 + 4) >> 2)) >> 1)) & 3) * 2)) + ((((v360 + ((~(((v362 ^ -1) | (-(v362 ^ -1))) >> 31)) & 2)) - (v363 + ((~(((v364 ^ -1) | (-(v364 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
        int v370 = v369[v469];
        int v470 = (((4 + ((((int)((unsigned int)((int)((unsigned int)(v326 + 4) >> 2)) >> 1)) & 3) * 2)) + ((((v360 + ((~(((v362 ^ -1) | (-(v362 ^ -1))) >> 31)) & 2)) - (v363 + ((~(((v364 ^ -1) | (-(v364 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
        int v371 = v369[v470];
        int * v372 = v320->mem;
        int v472 = v368 * 2;
        v372[v472] = v370;
        int * v374 = v320->mem;
        int v475 = (v368 * 2) + 1;
        v374[v475] = v371;
        ;
      } else {
        ;
      }
      int * v379 = v320->mem;
      int v480 = ((int)((unsigned int)((int)((unsigned int)(v326 + 4) >> 2)) >> 1)) * 2;
      int v380 = v379[v480];
      int v481 = (((int)((unsigned int)((int)((unsigned int)(v326 + 4) >> 2)) >> 1)) * 2) + 1;
      int v381 = v379[v481];
      int * v382 = v320->cache_vals;
      int v483 = ((4 + ((((int)((unsigned int)((int)((unsigned int)(v326 + 4) >> 2)) >> 1)) & 3) * 2)) + ((((v360 + ((~(((v362 ^ -1) | (-(v362 ^ -1))) >> 31)) & 2)) - (v363 + ((~(((v364 ^ -1) | (-(v364 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
      v382[v483] = v380;
      int * v384 = v320->cache_vals;
      int v486 = (((4 + ((((int)((unsigned int)((int)((unsigned int)(v326 + 4) >> 2)) >> 1)) & 3) * 2)) + ((((v360 + ((~(((v362 ^ -1) | (-(v362 ^ -1))) >> 31)) & 2)) - (v363 + ((~(((v364 ^ -1) | (-(v364 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
      v384[v486] = v381;
      int * v386 = v320->cache_tags;
      int v489 = (int)((unsigned int)((int)((unsigned int)(v326 + 4) >> 2)) >> 1);
      v386[v465] = v489;
      int * v388 = v320->cache_dirty;
      v388[v465] = 0;
      int * v390 = v320->cache_age;
      v390[v465] = 1;
      int * v392 = v320->cache_age;
      int v393 = v392[v465];
      int v394 = v392[v440];
      int v495 = v394 + ((int)((unsigned int)(v394 - v393) >> 31));
      v392[v440] = v495;
      int * v396 = v320->cache_age;
      int v397 = v396[v441];
      int v497 = v397 + ((int)((unsigned int)(v397 - v393) >> 31));
      v396[v441] = v497;
      int * v399 = v320->cache_age;
      v399[v465] = 0;
      v402 = v465;
    }
    int * v403 = v320->cache_vals;
    int v500 = v402 * 2;
    int v404 = v403[v500];
    int v501 = (v402 * 2) + 1;
    int v405 = v403[v501];
    int v502 = (((((int)((unsigned int)((int)((unsigned int)(v326 + 4) >> 2)) >> 1)) & 1) * 2) + ((((v344 + ((~(((v346 ^ -1) | (-(v346 ^ -1))) >> 31)) & 2)) - (v347 + ((~(((v348 ^ -1) | (-(v348 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
    v403[v502] = v404;
    int * v407 = v320->cache_vals;
    int v505 = ((((((int)((unsigned int)((int)((unsigned int)(v326 + 4) >> 2)) >> 1)) & 1) * 2) + ((((v344 + ((~(((v346 ^ -1) | (-(v346 ^ -1))) >> 31)) & 2)) - (v347 + ((~(((v348 ^ -1) | (-(v348 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
    v407[v505] = v405;
    int * v409 = v320->cache_tags;
    int v508 = ((((int)((unsigned int)((int)((unsigned int)(v326 + 4) >> 2)) >> 1)) & 1) * 2) + ((((v344 + ((~(((v346 ^ -1) | (-(v346 ^ -1))) >> 31)) & 2)) - (v347 + ((~(((v348 ^ -1) | (-(v348 ^ -1))) >> 31)) & 2))) >> 31) & 1);
    int v509 = (int)((unsigned int)((int)((unsigned int)(v326 + 4) >> 2)) >> 1);
    v409[v508] = v509;
    int * v411 = v320->cache_dirty;
    v411[v508] = 0;
    int * v413 = v320->cache_age;
    v413[v508] = 1;
    int * v415 = v320->cache_age;
    int v416 = v415[v508];
    int v417 = v415[v438];
    int v515 = v417 + ((int)((unsigned int)(v417 - v416) >> 31));
    v415[v438] = v515;
    int * v419 = v320->cache_age;
    int v420 = v419[v439];
    int v517 = v420 + ((int)((unsigned int)(v420 - v416) >> 31));
    v419[v439] = v517;
    int * v422 = v320->cache_age;
    v422[v508] = 0;
    v425 = v508;
  }
  int v520 = (v425 * 2) + (((int)((unsigned int)(v326 + 4) >> 2)) & 1);
  int v426 = v332[v520];
  int * v427 = v320->reg_ready;
  int v522 = ((v324 + ((v321 - v324) & (~((v321 - v324) >> 31)))) + 1) + ((100 ^ (((~(((v330 ^ ((int)((unsigned int)((int)((unsigned int)(v326 + 4) >> 2)) >> 1))) | (-(v330 ^ ((int)((unsigned int)((int)((unsigned int)(v326 + 4) >> 2)) >> 1))))) >> 31)) | (~(((v331 ^ ((int)((unsigned int)((int)((unsigned int)(v326 + 4) >> 2)) >> 1))) | (-(v331 ^ ((int)((unsigned int)((int)((unsigned int)(v326 + 4) >> 2)) >> 1))))) >> 31))) & 104)) ^ (((~(((v328 ^ ((int)((unsigned int)((int)((unsigned int)(v326 + 4) >> 2)) >> 1))) | (-(v328 ^ ((int)((unsigned int)((int)((unsigned int)(v326 + 4) >> 2)) >> 1))))) >> 31)) | (~(((v329 ^ ((int)((unsigned int)((int)((unsigned int)(v326 + 4) >> 2)) >> 1))) | (-(v329 ^ ((int)((unsigned int)((int)((unsigned int)(v326 + 4) >> 2)) >> 1))))) >> 31))) & (1 ^ (100 ^ (((~(((v330 ^ ((int)((unsigned int)((int)((unsigned int)(v326 + 4) >> 2)) >> 1))) | (-(v330 ^ ((int)((unsigned int)((int)((unsigned int)(v326 + 4) >> 2)) >> 1))))) >> 31)) | (~(((v331 ^ ((int)((unsigned int)((int)((unsigned int)(v326 + 4) >> 2)) >> 1))) | (-(v331 ^ ((int)((unsigned int)((int)((unsigned int)(v326 + 4) >> 2)) >> 1))))) >> 31))) & 104)))));
  v427[10] = v522;
  int * v429 = v320->regs;
  v429[10] = v426;
  struct StateT * v431 = slot_21(v320);
  return v431;
}

struct StateT * snippet(struct StateT * v0) {
  struct StateT * v1 = slot_0(v0);
  int v2212 = v1->timer;
  int * v2213 = v1->reg_ready;
  int v2214 = v2213[0];
  int v2345 = v2214 + ((v2212 - v2214) & (~((v2212 - v2214) >> 31)));
  v1->timer = v2345;
  int v2216 = v1->timer;
  int * v2217 = v1->reg_ready;
  int v2218 = v2217[1];
  int v2348 = v2218 + ((v2216 - v2218) & (~((v2216 - v2218) >> 31)));
  v1->timer = v2348;
  int v2220 = v1->timer;
  int * v2221 = v1->reg_ready;
  int v2222 = v2221[2];
  int v2351 = v2222 + ((v2220 - v2222) & (~((v2220 - v2222) >> 31)));
  v1->timer = v2351;
  int v2224 = v1->timer;
  int * v2225 = v1->reg_ready;
  int v2226 = v2225[3];
  int v2354 = v2226 + ((v2224 - v2226) & (~((v2224 - v2226) >> 31)));
  v1->timer = v2354;
  int v2228 = v1->timer;
  int * v2229 = v1->reg_ready;
  int v2230 = v2229[4];
  int v2357 = v2230 + ((v2228 - v2230) & (~((v2228 - v2230) >> 31)));
  v1->timer = v2357;
  int v2232 = v1->timer;
  int * v2233 = v1->reg_ready;
  int v2234 = v2233[5];
  int v2360 = v2234 + ((v2232 - v2234) & (~((v2232 - v2234) >> 31)));
  v1->timer = v2360;
  int v2236 = v1->timer;
  int * v2237 = v1->reg_ready;
  int v2238 = v2237[6];
  int v2363 = v2238 + ((v2236 - v2238) & (~((v2236 - v2238) >> 31)));
  v1->timer = v2363;
  int v2240 = v1->timer;
  int * v2241 = v1->reg_ready;
  int v2242 = v2241[7];
  int v2366 = v2242 + ((v2240 - v2242) & (~((v2240 - v2242) >> 31)));
  v1->timer = v2366;
  int v2244 = v1->timer;
  int * v2245 = v1->reg_ready;
  int v2246 = v2245[8];
  int v2369 = v2246 + ((v2244 - v2246) & (~((v2244 - v2246) >> 31)));
  v1->timer = v2369;
  int v2248 = v1->timer;
  int * v2249 = v1->reg_ready;
  int v2250 = v2249[9];
  int v2372 = v2250 + ((v2248 - v2250) & (~((v2248 - v2250) >> 31)));
  v1->timer = v2372;
  int v2252 = v1->timer;
  int * v2253 = v1->reg_ready;
  int v2254 = v2253[10];
  int v2375 = v2254 + ((v2252 - v2254) & (~((v2252 - v2254) >> 31)));
  v1->timer = v2375;
  int v2256 = v1->timer;
  int * v2257 = v1->reg_ready;
  int v2258 = v2257[11];
  int v2378 = v2258 + ((v2256 - v2258) & (~((v2256 - v2258) >> 31)));
  v1->timer = v2378;
  int v2260 = v1->timer;
  int * v2261 = v1->reg_ready;
  int v2262 = v2261[12];
  int v2381 = v2262 + ((v2260 - v2262) & (~((v2260 - v2262) >> 31)));
  v1->timer = v2381;
  int v2264 = v1->timer;
  int * v2265 = v1->reg_ready;
  int v2266 = v2265[13];
  int v2384 = v2266 + ((v2264 - v2266) & (~((v2264 - v2266) >> 31)));
  v1->timer = v2384;
  int v2268 = v1->timer;
  int * v2269 = v1->reg_ready;
  int v2270 = v2269[14];
  int v2387 = v2270 + ((v2268 - v2270) & (~((v2268 - v2270) >> 31)));
  v1->timer = v2387;
  int v2272 = v1->timer;
  int * v2273 = v1->reg_ready;
  int v2274 = v2273[15];
  int v2390 = v2274 + ((v2272 - v2274) & (~((v2272 - v2274) >> 31)));
  v1->timer = v2390;
  int v2276 = v1->timer;
  int * v2277 = v1->reg_ready;
  int v2278 = v2277[16];
  int v2393 = v2278 + ((v2276 - v2278) & (~((v2276 - v2278) >> 31)));
  v1->timer = v2393;
  int v2280 = v1->timer;
  int * v2281 = v1->reg_ready;
  int v2282 = v2281[17];
  int v2396 = v2282 + ((v2280 - v2282) & (~((v2280 - v2282) >> 31)));
  v1->timer = v2396;
  int v2284 = v1->timer;
  int * v2285 = v1->reg_ready;
  int v2286 = v2285[18];
  int v2399 = v2286 + ((v2284 - v2286) & (~((v2284 - v2286) >> 31)));
  v1->timer = v2399;
  int v2288 = v1->timer;
  int * v2289 = v1->reg_ready;
  int v2290 = v2289[19];
  int v2402 = v2290 + ((v2288 - v2290) & (~((v2288 - v2290) >> 31)));
  v1->timer = v2402;
  int v2292 = v1->timer;
  int * v2293 = v1->reg_ready;
  int v2294 = v2293[20];
  int v2405 = v2294 + ((v2292 - v2294) & (~((v2292 - v2294) >> 31)));
  v1->timer = v2405;
  int v2296 = v1->timer;
  int * v2297 = v1->reg_ready;
  int v2298 = v2297[21];
  int v2408 = v2298 + ((v2296 - v2298) & (~((v2296 - v2298) >> 31)));
  v1->timer = v2408;
  int v2300 = v1->timer;
  int * v2301 = v1->reg_ready;
  int v2302 = v2301[22];
  int v2411 = v2302 + ((v2300 - v2302) & (~((v2300 - v2302) >> 31)));
  v1->timer = v2411;
  int v2304 = v1->timer;
  int * v2305 = v1->reg_ready;
  int v2306 = v2305[23];
  int v2414 = v2306 + ((v2304 - v2306) & (~((v2304 - v2306) >> 31)));
  v1->timer = v2414;
  int v2308 = v1->timer;
  int * v2309 = v1->reg_ready;
  int v2310 = v2309[24];
  int v2417 = v2310 + ((v2308 - v2310) & (~((v2308 - v2310) >> 31)));
  v1->timer = v2417;
  int v2312 = v1->timer;
  int * v2313 = v1->reg_ready;
  int v2314 = v2313[25];
  int v2420 = v2314 + ((v2312 - v2314) & (~((v2312 - v2314) >> 31)));
  v1->timer = v2420;
  int v2316 = v1->timer;
  int * v2317 = v1->reg_ready;
  int v2318 = v2317[26];
  int v2423 = v2318 + ((v2316 - v2318) & (~((v2316 - v2318) >> 31)));
  v1->timer = v2423;
  int v2320 = v1->timer;
  int * v2321 = v1->reg_ready;
  int v2322 = v2321[27];
  int v2426 = v2322 + ((v2320 - v2322) & (~((v2320 - v2322) >> 31)));
  v1->timer = v2426;
  int v2324 = v1->timer;
  int * v2325 = v1->reg_ready;
  int v2326 = v2325[28];
  int v2429 = v2326 + ((v2324 - v2326) & (~((v2324 - v2326) >> 31)));
  v1->timer = v2429;
  int v2328 = v1->timer;
  int * v2329 = v1->reg_ready;
  int v2330 = v2329[29];
  int v2432 = v2330 + ((v2328 - v2330) & (~((v2328 - v2330) >> 31)));
  v1->timer = v2432;
  int v2332 = v1->timer;
  int * v2333 = v1->reg_ready;
  int v2334 = v2333[30];
  int v2435 = v2334 + ((v2332 - v2334) & (~((v2332 - v2334) >> 31)));
  v1->timer = v2435;
  int v2336 = v1->timer;
  int * v2337 = v1->reg_ready;
  int v2338 = v2337[31];
  int v2438 = v2338 + ((v2336 - v2338) & (~((v2336 - v2338) >> 31)));
  v1->timer = v2438;
  return v1;
}

struct StateT * slot_8(struct StateT * v1330) {
  int v1331 = v1330->timer;
  int v1339 = v1331 + 1;
  v1330->timer = v1339;
  int * v1333 = v1330->reg_ready;
  v1333[11] = v1339;
  int * v1335 = v1330->regs;
  v1335[11] = 0;
  struct StateT * v1337 = slot_9(v1330);
  return v1337;
}

struct StateT * slot_4(struct StateT * v304) {
  int v305 = v304->timer;
  int v313 = v305 + 1;
  v304->timer = v313;
  int * v307 = v304->reg_ready;
  v307[11] = v313;
  int * v309 = v304->regs;
  v309[11] = 0;
  struct StateT * v311 = slot_5(v304);
  return v311;
}

struct StateT * slot_15(struct StateT * v1661) {
  int v1662 = v1661->timer;
  int v1774 = v1662 + 1;
  v1661->timer = v1774;
  int * v1664 = v1661->reg_ready;
  int v1665 = v1664[12];
  int * v1666 = v1661->regs;
  int v1667 = v1666[12];
  int * v1668 = v1661->cache_tags;
  int v1779 = (((int)((unsigned int)((int)((unsigned int)(v1667 + 68) >> 2)) >> 1)) & 1) * 2;
  int v1669 = v1668[v1779];
  int v1780 = ((((int)((unsigned int)((int)((unsigned int)(v1667 + 68) >> 2)) >> 1)) & 1) * 2) + 1;
  int v1670 = v1668[v1780];
  int v1781 = 4 + ((((int)((unsigned int)((int)((unsigned int)(v1667 + 68) >> 2)) >> 1)) & 3) * 2);
  int v1671 = v1668[v1781];
  int v1782 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v1667 + 68) >> 2)) >> 1)) & 3) * 2)) + 1;
  int v1672 = v1668[v1782];
  int * v1673 = v1661->cache_vals;
  bool v1783 = !(((~(((v1669 ^ ((int)((unsigned int)((int)((unsigned int)(v1667 + 68) >> 2)) >> 1))) | (-(v1669 ^ ((int)((unsigned int)((int)((unsigned int)(v1667 + 68) >> 2)) >> 1))))) >> 31)) | (~(((v1670 ^ ((int)((unsigned int)((int)((unsigned int)(v1667 + 68) >> 2)) >> 1))) | (-(v1670 ^ ((int)((unsigned int)((int)((unsigned int)(v1667 + 68) >> 2)) >> 1))))) >> 31))) == 0);
  int v1766;
  if (v1783) {
    int * v1674 = v1661->cache_age;
    int v1785 = ((((int)((unsigned int)((int)((unsigned int)(v1667 + 68) >> 2)) >> 1)) & 1) * 2) + ((~(((v1670 ^ ((int)((unsigned int)((int)((unsigned int)(v1667 + 68) >> 2)) >> 1))) | (-(v1670 ^ ((int)((unsigned int)((int)((unsigned int)(v1667 + 68) >> 2)) >> 1))))) >> 31)) & 1);
    int v1675 = v1674[v1785];
    int v1676 = v1674[v1779];
    int v1786 = v1676 + ((int)((unsigned int)(v1676 - v1675) >> 31));
    v1674[v1779] = v1786;
    int * v1678 = v1661->cache_age;
    int v1679 = v1678[v1780];
    int v1788 = v1679 + ((int)((unsigned int)(v1679 - v1675) >> 31));
    v1678[v1780] = v1788;
    int * v1681 = v1661->cache_age;
    v1681[v1785] = 0;
    v1766 = v1785;
  } else {
    int * v1684 = v1661->cache_age;
    int v1792 = (((int)((unsigned int)((int)((unsigned int)(v1667 + 68) >> 2)) >> 1)) & 1) * 2;
    int v1685 = v1684[v1792];
    int * v1686 = v1661->cache_tags;
    int v1687 = v1686[v1792];
    int v1688 = v1684[v1780];
    int v1689 = v1686[v1780];
    bool v1794 = !(((~(((v1671 ^ ((int)((unsigned int)((int)((unsigned int)(v1667 + 68) >> 2)) >> 1))) | (-(v1671 ^ ((int)((unsigned int)((int)((unsigned int)(v1667 + 68) >> 2)) >> 1))))) >> 31)) | (~(((v1672 ^ ((int)((unsigned int)((int)((unsigned int)(v1667 + 68) >> 2)) >> 1))) | (-(v1672 ^ ((int)((unsigned int)((int)((unsigned int)(v1667 + 68) >> 2)) >> 1))))) >> 31))) == 0);
    int v1743;
    if (v1794) {
      int * v1690 = v1661->cache_age;
      int v1796 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v1667 + 68) >> 2)) >> 1)) & 3) * 2)) + ((~(((v1672 ^ ((int)((unsigned int)((int)((unsigned int)(v1667 + 68) >> 2)) >> 1))) | (-(v1672 ^ ((int)((unsigned int)((int)((unsigned int)(v1667 + 68) >> 2)) >> 1))))) >> 31)) & 1);
      int v1691 = v1690[v1796];
      int v1692 = v1690[v1781];
      int v1797 = v1692 + ((int)((unsigned int)(v1692 - v1691) >> 31));
      v1690[v1781] = v1797;
      int * v1694 = v1661->cache_age;
      int v1695 = v1694[v1782];
      int v1799 = v1695 + ((int)((unsigned int)(v1695 - v1691) >> 31));
      v1694[v1782] = v1799;
      int * v1697 = v1661->cache_age;
      v1697[v1796] = 0;
      v1743 = v1796;
    } else {
      int * v1700 = v1661->cache_age;
      int v1803 = 4 + ((((int)((unsigned int)((int)((unsigned int)(v1667 + 68) >> 2)) >> 1)) & 3) * 2);
      int v1701 = v1700[v1803];
      int * v1702 = v1661->cache_tags;
      int v1703 = v1702[v1803];
      int v1704 = v1700[v1782];
      int v1705 = v1702[v1782];
      int * v1706 = v1661->cache_dirty;
      int v1806 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v1667 + 68) >> 2)) >> 1)) & 3) * 2)) + ((((v1701 + ((~(((v1703 ^ -1) | (-(v1703 ^ -1))) >> 31)) & 2)) - (v1704 + ((~(((v1705 ^ -1) | (-(v1705 ^ -1))) >> 31)) & 2))) >> 31) & 1);
      int v1707 = v1706[v1806];
      bool v1807 = !(v1707 == 0);
      if (v1807) {
        int * v1708 = v1661->cache_tags;
        int v1709 = v1708[v1806];
        int * v1710 = v1661->cache_vals;
        int v1810 = ((4 + ((((int)((unsigned int)((int)((unsigned int)(v1667 + 68) >> 2)) >> 1)) & 3) * 2)) + ((((v1701 + ((~(((v1703 ^ -1) | (-(v1703 ^ -1))) >> 31)) & 2)) - (v1704 + ((~(((v1705 ^ -1) | (-(v1705 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
        int v1711 = v1710[v1810];
        int v1811 = (((4 + ((((int)((unsigned int)((int)((unsigned int)(v1667 + 68) >> 2)) >> 1)) & 3) * 2)) + ((((v1701 + ((~(((v1703 ^ -1) | (-(v1703 ^ -1))) >> 31)) & 2)) - (v1704 + ((~(((v1705 ^ -1) | (-(v1705 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
        int v1712 = v1710[v1811];
        int * v1713 = v1661->mem;
        int v1813 = v1709 * 2;
        v1713[v1813] = v1711;
        int * v1715 = v1661->mem;
        int v1816 = (v1709 * 2) + 1;
        v1715[v1816] = v1712;
        ;
      } else {
        ;
      }
      int * v1720 = v1661->mem;
      int v1821 = ((int)((unsigned int)((int)((unsigned int)(v1667 + 68) >> 2)) >> 1)) * 2;
      int v1721 = v1720[v1821];
      int v1822 = (((int)((unsigned int)((int)((unsigned int)(v1667 + 68) >> 2)) >> 1)) * 2) + 1;
      int v1722 = v1720[v1822];
      int * v1723 = v1661->cache_vals;
      int v1824 = ((4 + ((((int)((unsigned int)((int)((unsigned int)(v1667 + 68) >> 2)) >> 1)) & 3) * 2)) + ((((v1701 + ((~(((v1703 ^ -1) | (-(v1703 ^ -1))) >> 31)) & 2)) - (v1704 + ((~(((v1705 ^ -1) | (-(v1705 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
      v1723[v1824] = v1721;
      int * v1725 = v1661->cache_vals;
      int v1827 = (((4 + ((((int)((unsigned int)((int)((unsigned int)(v1667 + 68) >> 2)) >> 1)) & 3) * 2)) + ((((v1701 + ((~(((v1703 ^ -1) | (-(v1703 ^ -1))) >> 31)) & 2)) - (v1704 + ((~(((v1705 ^ -1) | (-(v1705 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
      v1725[v1827] = v1722;
      int * v1727 = v1661->cache_tags;
      int v1830 = (int)((unsigned int)((int)((unsigned int)(v1667 + 68) >> 2)) >> 1);
      v1727[v1806] = v1830;
      int * v1729 = v1661->cache_dirty;
      v1729[v1806] = 0;
      int * v1731 = v1661->cache_age;
      v1731[v1806] = 1;
      int * v1733 = v1661->cache_age;
      int v1734 = v1733[v1806];
      int v1735 = v1733[v1781];
      int v1836 = v1735 + ((int)((unsigned int)(v1735 - v1734) >> 31));
      v1733[v1781] = v1836;
      int * v1737 = v1661->cache_age;
      int v1738 = v1737[v1782];
      int v1838 = v1738 + ((int)((unsigned int)(v1738 - v1734) >> 31));
      v1737[v1782] = v1838;
      int * v1740 = v1661->cache_age;
      v1740[v1806] = 0;
      v1743 = v1806;
    }
    int * v1744 = v1661->cache_vals;
    int v1841 = v1743 * 2;
    int v1745 = v1744[v1841];
    int v1842 = (v1743 * 2) + 1;
    int v1746 = v1744[v1842];
    int v1843 = (((((int)((unsigned int)((int)((unsigned int)(v1667 + 68) >> 2)) >> 1)) & 1) * 2) + ((((v1685 + ((~(((v1687 ^ -1) | (-(v1687 ^ -1))) >> 31)) & 2)) - (v1688 + ((~(((v1689 ^ -1) | (-(v1689 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
    v1744[v1843] = v1745;
    int * v1748 = v1661->cache_vals;
    int v1846 = ((((((int)((unsigned int)((int)((unsigned int)(v1667 + 68) >> 2)) >> 1)) & 1) * 2) + ((((v1685 + ((~(((v1687 ^ -1) | (-(v1687 ^ -1))) >> 31)) & 2)) - (v1688 + ((~(((v1689 ^ -1) | (-(v1689 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
    v1748[v1846] = v1746;
    int * v1750 = v1661->cache_tags;
    int v1849 = ((((int)((unsigned int)((int)((unsigned int)(v1667 + 68) >> 2)) >> 1)) & 1) * 2) + ((((v1685 + ((~(((v1687 ^ -1) | (-(v1687 ^ -1))) >> 31)) & 2)) - (v1688 + ((~(((v1689 ^ -1) | (-(v1689 ^ -1))) >> 31)) & 2))) >> 31) & 1);
    int v1850 = (int)((unsigned int)((int)((unsigned int)(v1667 + 68) >> 2)) >> 1);
    v1750[v1849] = v1850;
    int * v1752 = v1661->cache_dirty;
    v1752[v1849] = 0;
    int * v1754 = v1661->cache_age;
    v1754[v1849] = 1;
    int * v1756 = v1661->cache_age;
    int v1757 = v1756[v1849];
    int v1758 = v1756[v1779];
    int v1856 = v1758 + ((int)((unsigned int)(v1758 - v1757) >> 31));
    v1756[v1779] = v1856;
    int * v1760 = v1661->cache_age;
    int v1761 = v1760[v1780];
    int v1858 = v1761 + ((int)((unsigned int)(v1761 - v1757) >> 31));
    v1760[v1780] = v1858;
    int * v1763 = v1661->cache_age;
    v1763[v1849] = 0;
    v1766 = v1849;
  }
  int v1861 = (v1766 * 2) + (((int)((unsigned int)(v1667 + 68) >> 2)) & 1);
  int v1767 = v1673[v1861];
  int * v1768 = v1661->reg_ready;
  int v1864 = ((v1665 + ((v1662 - v1665) & (~((v1662 - v1665) >> 31)))) + 1) + ((100 ^ (((~(((v1671 ^ ((int)((unsigned int)((int)((unsigned int)(v1667 + 68) >> 2)) >> 1))) | (-(v1671 ^ ((int)((unsigned int)((int)((unsigned int)(v1667 + 68) >> 2)) >> 1))))) >> 31)) | (~(((v1672 ^ ((int)((unsigned int)((int)((unsigned int)(v1667 + 68) >> 2)) >> 1))) | (-(v1672 ^ ((int)((unsigned int)((int)((unsigned int)(v1667 + 68) >> 2)) >> 1))))) >> 31))) & 104)) ^ (((~(((v1669 ^ ((int)((unsigned int)((int)((unsigned int)(v1667 + 68) >> 2)) >> 1))) | (-(v1669 ^ ((int)((unsigned int)((int)((unsigned int)(v1667 + 68) >> 2)) >> 1))))) >> 31)) | (~(((v1670 ^ ((int)((unsigned int)((int)((unsigned int)(v1667 + 68) >> 2)) >> 1))) | (-(v1670 ^ ((int)((unsigned int)((int)((unsigned int)(v1667 + 68) >> 2)) >> 1))))) >> 31))) & (1 ^ (100 ^ (((~(((v1671 ^ ((int)((unsigned int)((int)((unsigned int)(v1667 + 68) >> 2)) >> 1))) | (-(v1671 ^ ((int)((unsigned int)((int)((unsigned int)(v1667 + 68) >> 2)) >> 1))))) >> 31)) | (~(((v1672 ^ ((int)((unsigned int)((int)((unsigned int)(v1667 + 68) >> 2)) >> 1))) | (-(v1672 ^ ((int)((unsigned int)((int)((unsigned int)(v1667 + 68) >> 2)) >> 1))))) >> 31))) & 104)))));
  v1768[11] = v1864;
  int * v1770 = v1661->regs;
  v1770[11] = v1767;
  struct StateT * v1772 = slot_16(v1661);
  return v1772;
}

struct StateT * slot_18(struct StateT * v251) {
  int v252 = v251->timer;
  int v260 = v252 + 1;
  v251->timer = v260;
  int * v254 = v251->reg_ready;
  v254[10] = v260;
  int * v256 = v251->regs;
  v256[10] = 0;
  struct StateT * v258 = slot_19(v251);
  return v258;
}

struct StateT * slot_9(struct StateT * v1351) {
  int v1352 = v1351->timer;
  int v1363 = v1352 + 1;
  v1351->timer = v1363;
  int * v1354 = v1351->reg_ready;
  int v1355 = v1354[11];
  int * v1356 = v1351->regs;
  int v1357 = v1356[11];
  int v1367 = (v1355 + ((v1352 - v1355) & (~((v1352 - v1355) >> 31)))) + 1;
  v1354[11] = v1367;
  int * v1359 = v1351->regs;
  int v1369 = v1357 + 4;
  v1359[11] = v1369;
  struct StateT * v1361 = slot_10(v1351);
  return v1361;
}

struct StateT * slot_22(struct StateT * v780) {
  int v781 = v780->timer;
  int v794 = v781 + 1;
  v780->timer = v794;
  int * v783 = v780->reg_ready;
  int v784 = v783[12];
  int * v785 = v780->regs;
  int v786 = v785[12];
  int v787 = v783[10];
  int v788 = v785[10];
  int v799 = (v787 + (((v784 + ((v781 - v784) & (~((v781 - v784) >> 31)))) - v787) & (~(((v784 + ((v781 - v784) & (~((v781 - v784) >> 31)))) - v787) >> 31)))) + 1;
  v783[10] = v799;
  int * v790 = v780->regs;
  int v801 = v786 & v788;
  v790[10] = v801;
  struct StateT * v792 = slot_23(v780);
  return v792;
}

struct StateT * slot_11(struct StateT * v1388) {
  int v1389 = v1388->timer;
  int v1400 = v1389 + 1;
  v1388->timer = v1400;
  int * v1391 = v1388->reg_ready;
  int v1392 = v1391[10];
  int * v1393 = v1388->regs;
  int v1394 = v1393[10];
  int v1404 = (v1392 + ((v1389 - v1392) & (~((v1389 - v1392) >> 31)))) + 1;
  v1391[10] = v1404;
  int * v1396 = v1388->regs;
  int v1406 = v1394 << 29;
  v1396[10] = v1406;
  struct StateT * v1398 = slot_12(v1388);
  return v1398;
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