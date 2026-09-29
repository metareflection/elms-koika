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
#include <stdio.h>
#include <stdlib.h>

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

struct StateT * slot_12(struct StateT * v1030);
struct StateT * slot_14(struct StateT * v1066);
struct StateT * slot_6(struct StateT * v334);
struct StateT * slot_5(struct StateT * v77);
struct StateT * slot_2(struct StateT * v28);
struct StateT * slot_3(struct StateT * v41);
struct StateT * snippet(struct StateT * v0);
struct StateT * slot_10(struct StateT * v1006);
struct StateT * slot_1(struct StateT * v15);
struct StateT * slot_8(struct StateT * v371);
struct StateT * slot_4(struct StateT * v49);
struct StateT * slot_13(struct StateT * v1038);
struct StateT * slot_15(struct StateT * v1323);
struct StateT * slot_9(struct StateT * v756);
struct StateT * slot_11(struct StateT * v1022);
struct StateT * slot_0(struct StateT * v2);
struct StateT * slot_12(struct StateT * v1030) {
  int v1031 = v1030->timer;
  int v1035 = v1031 + 1;
  v1030->timer = v1035;
  struct StateT * v1033 = slot_13(v1030);
  return v1033;
}

struct StateT * slot_14(struct StateT * v1066) {
  int * v1067 = v1066->saved_regs;
  int * v1068 = v1066->regs;
  int v1069 = v1068[5];
  v1067[5] = v1069;
  int v1071 = v1066->timer;
  int v1208 = v1071 + 1;
  v1066->timer = v1208;
  int * v1073 = v1066->regs;
  int v1074 = v1073[8];
  int * v1075 = v1066->cache_tags;
  int v1212 = (((int)((unsigned int)((int)((unsigned int)v1074 >> 2)) >> 1)) & 1) * 2;
  int v1076 = v1075[v1212];
  int * v1077 = v1066->cache_tags;
  int v1214 = ((((int)((unsigned int)((int)((unsigned int)v1074 >> 2)) >> 1)) & 1) * 2) + 1;
  int v1078 = v1077[v1214];
  int * v1079 = v1066->cache_tags;
  int v1216 = 4 + ((((int)((unsigned int)((int)((unsigned int)v1074 >> 2)) >> 1)) & 3) * 2);
  int v1080 = v1079[v1216];
  int * v1081 = v1066->cache_tags;
  int v1218 = (4 + ((((int)((unsigned int)((int)((unsigned int)v1074 >> 2)) >> 1)) & 3) * 2)) + 1;
  int v1082 = v1081[v1218];
  int v1083 = v1066->timer;
  int v1219 = v1083 + ((100 ^ (((~(((v1080 ^ ((int)((unsigned int)((int)((unsigned int)v1074 >> 2)) >> 1))) | (-(v1080 ^ ((int)((unsigned int)((int)((unsigned int)v1074 >> 2)) >> 1))))) >> 31)) | (~(((v1082 ^ ((int)((unsigned int)((int)((unsigned int)v1074 >> 2)) >> 1))) | (-(v1082 ^ ((int)((unsigned int)((int)((unsigned int)v1074 >> 2)) >> 1))))) >> 31))) & 104)) ^ (((~(((v1076 ^ ((int)((unsigned int)((int)((unsigned int)v1074 >> 2)) >> 1))) | (-(v1076 ^ ((int)((unsigned int)((int)((unsigned int)v1074 >> 2)) >> 1))))) >> 31)) | (~(((v1078 ^ ((int)((unsigned int)((int)((unsigned int)v1074 >> 2)) >> 1))) | (-(v1078 ^ ((int)((unsigned int)((int)((unsigned int)v1074 >> 2)) >> 1))))) >> 31))) & (1 ^ (100 ^ (((~(((v1080 ^ ((int)((unsigned int)((int)((unsigned int)v1074 >> 2)) >> 1))) | (-(v1080 ^ ((int)((unsigned int)((int)((unsigned int)v1074 >> 2)) >> 1))))) >> 31)) | (~(((v1082 ^ ((int)((unsigned int)((int)((unsigned int)v1074 >> 2)) >> 1))) | (-(v1082 ^ ((int)((unsigned int)((int)((unsigned int)v1074 >> 2)) >> 1))))) >> 31))) & 104)))));
  v1066->timer = v1219;
  int * v1085 = v1066->cache_vals;
  bool v1220 = !(((~(((v1076 ^ ((int)((unsigned int)((int)((unsigned int)v1074 >> 2)) >> 1))) | (-(v1076 ^ ((int)((unsigned int)((int)((unsigned int)v1074 >> 2)) >> 1))))) >> 31)) | (~(((v1078 ^ ((int)((unsigned int)((int)((unsigned int)v1074 >> 2)) >> 1))) | (-(v1078 ^ ((int)((unsigned int)((int)((unsigned int)v1074 >> 2)) >> 1))))) >> 31))) == 0);
  int v1198;
  if (v1220) {
    int * v1086 = v1066->cache_age;
    int v1222 = ((((int)((unsigned int)((int)((unsigned int)v1074 >> 2)) >> 1)) & 1) * 2) + ((~(((v1078 ^ ((int)((unsigned int)((int)((unsigned int)v1074 >> 2)) >> 1))) | (-(v1078 ^ ((int)((unsigned int)((int)((unsigned int)v1074 >> 2)) >> 1))))) >> 31)) & 1);
    int v1087 = v1086[v1222];
    int * v1088 = v1066->cache_age;
    int v1089 = v1088[v1212];
    int * v1090 = v1066->cache_age;
    int v1225 = v1089 + ((int)((unsigned int)(v1089 - v1087) >> 31));
    v1090[v1212] = v1225;
    int * v1092 = v1066->cache_age;
    int v1093 = v1092[v1214];
    int * v1094 = v1066->cache_age;
    int v1228 = v1093 + ((int)((unsigned int)(v1093 - v1087) >> 31));
    v1094[v1214] = v1228;
    int * v1096 = v1066->cache_age;
    v1096[v1222] = 0;
    v1198 = v1222;
  } else {
    int * v1099 = v1066->cache_age;
    int v1232 = (((int)((unsigned int)((int)((unsigned int)v1074 >> 2)) >> 1)) & 1) * 2;
    int v1100 = v1099[v1232];
    int * v1101 = v1066->cache_tags;
    int v1102 = v1101[v1232];
    int * v1103 = v1066->cache_age;
    int v1104 = v1103[v1214];
    int * v1105 = v1066->cache_tags;
    int v1106 = v1105[v1214];
    bool v1236 = !(((~(((v1080 ^ ((int)((unsigned int)((int)((unsigned int)v1074 >> 2)) >> 1))) | (-(v1080 ^ ((int)((unsigned int)((int)((unsigned int)v1074 >> 2)) >> 1))))) >> 31)) | (~(((v1082 ^ ((int)((unsigned int)((int)((unsigned int)v1074 >> 2)) >> 1))) | (-(v1082 ^ ((int)((unsigned int)((int)((unsigned int)v1074 >> 2)) >> 1))))) >> 31))) == 0);
    int v1170;
    if (v1236) {
      int * v1107 = v1066->cache_age;
      int v1238 = (4 + ((((int)((unsigned int)((int)((unsigned int)v1074 >> 2)) >> 1)) & 3) * 2)) + ((~(((v1082 ^ ((int)((unsigned int)((int)((unsigned int)v1074 >> 2)) >> 1))) | (-(v1082 ^ ((int)((unsigned int)((int)((unsigned int)v1074 >> 2)) >> 1))))) >> 31)) & 1);
      int v1108 = v1107[v1238];
      int * v1109 = v1066->cache_age;
      int v1110 = v1109[v1216];
      int * v1111 = v1066->cache_age;
      int v1241 = v1110 + ((int)((unsigned int)(v1110 - v1108) >> 31));
      v1111[v1216] = v1241;
      int * v1113 = v1066->cache_age;
      int v1114 = v1113[v1218];
      int * v1115 = v1066->cache_age;
      int v1244 = v1114 + ((int)((unsigned int)(v1114 - v1108) >> 31));
      v1115[v1218] = v1244;
      int * v1117 = v1066->cache_age;
      v1117[v1238] = 0;
      v1170 = v1238;
    } else {
      int * v1120 = v1066->cache_age;
      int v1248 = 4 + ((((int)((unsigned int)((int)((unsigned int)v1074 >> 2)) >> 1)) & 3) * 2);
      int v1121 = v1120[v1248];
      int * v1122 = v1066->cache_tags;
      int v1123 = v1122[v1248];
      int * v1124 = v1066->cache_age;
      int v1125 = v1124[v1218];
      int * v1126 = v1066->cache_tags;
      int v1127 = v1126[v1218];
      int * v1128 = v1066->cache_dirty;
      int v1253 = (4 + ((((int)((unsigned int)((int)((unsigned int)v1074 >> 2)) >> 1)) & 3) * 2)) + ((((v1121 + ((~(((v1123 ^ -1) | (-(v1123 ^ -1))) >> 31)) & 2)) - (v1125 + ((~(((v1127 ^ -1) | (-(v1127 ^ -1))) >> 31)) & 2))) >> 31) & 1);
      int v1129 = v1128[v1253];
      bool v1254 = !(v1129 == 0);
      if (v1254) {
        int * v1130 = v1066->cache_tags;
        int v1131 = v1130[v1253];
        int * v1132 = v1066->cache_vals;
        int v1257 = ((4 + ((((int)((unsigned int)((int)((unsigned int)v1074 >> 2)) >> 1)) & 3) * 2)) + ((((v1121 + ((~(((v1123 ^ -1) | (-(v1123 ^ -1))) >> 31)) & 2)) - (v1125 + ((~(((v1127 ^ -1) | (-(v1127 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
        int v1133 = v1132[v1257];
        int * v1134 = v1066->cache_vals;
        int v1259 = (((4 + ((((int)((unsigned int)((int)((unsigned int)v1074 >> 2)) >> 1)) & 3) * 2)) + ((((v1121 + ((~(((v1123 ^ -1) | (-(v1123 ^ -1))) >> 31)) & 2)) - (v1125 + ((~(((v1127 ^ -1) | (-(v1127 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
        int v1135 = v1134[v1259];
        int * v1136 = v1066->mem;
        int v1261 = v1131 * 2;
        v1136[v1261] = v1133;
        int * v1138 = v1066->mem;
        int v1264 = (v1131 * 2) + 1;
        v1138[v1264] = v1135;
        ;
      } else {
        ;
      }
      int * v1143 = v1066->mem;
      int v1269 = ((int)((unsigned int)((int)((unsigned int)v1074 >> 2)) >> 1)) * 2;
      int v1144 = v1143[v1269];
      int * v1145 = v1066->mem;
      int v1271 = (((int)((unsigned int)((int)((unsigned int)v1074 >> 2)) >> 1)) * 2) + 1;
      int v1146 = v1145[v1271];
      int * v1147 = v1066->cache_vals;
      int v1273 = ((4 + ((((int)((unsigned int)((int)((unsigned int)v1074 >> 2)) >> 1)) & 3) * 2)) + ((((v1121 + ((~(((v1123 ^ -1) | (-(v1123 ^ -1))) >> 31)) & 2)) - (v1125 + ((~(((v1127 ^ -1) | (-(v1127 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
      v1147[v1273] = v1144;
      int * v1149 = v1066->cache_vals;
      int v1276 = (((4 + ((((int)((unsigned int)((int)((unsigned int)v1074 >> 2)) >> 1)) & 3) * 2)) + ((((v1121 + ((~(((v1123 ^ -1) | (-(v1123 ^ -1))) >> 31)) & 2)) - (v1125 + ((~(((v1127 ^ -1) | (-(v1127 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
      v1149[v1276] = v1146;
      int * v1151 = v1066->cache_tags;
      int v1279 = (int)((unsigned int)((int)((unsigned int)v1074 >> 2)) >> 1);
      v1151[v1253] = v1279;
      int * v1153 = v1066->cache_dirty;
      v1153[v1253] = 0;
      int * v1155 = v1066->cache_age;
      v1155[v1253] = 1;
      int * v1157 = v1066->cache_age;
      int v1158 = v1157[v1253];
      int * v1159 = v1066->cache_age;
      int v1160 = v1159[v1216];
      int * v1161 = v1066->cache_age;
      int v1287 = v1160 + ((int)((unsigned int)(v1160 - v1158) >> 31));
      v1161[v1216] = v1287;
      int * v1163 = v1066->cache_age;
      int v1164 = v1163[v1218];
      int * v1165 = v1066->cache_age;
      int v1290 = v1164 + ((int)((unsigned int)(v1164 - v1158) >> 31));
      v1165[v1218] = v1290;
      int * v1167 = v1066->cache_age;
      v1167[v1253] = 0;
      v1170 = v1253;
    }
    int * v1171 = v1066->cache_vals;
    int v1293 = v1170 * 2;
    int v1172 = v1171[v1293];
    int * v1173 = v1066->cache_vals;
    int v1295 = (v1170 * 2) + 1;
    int v1174 = v1173[v1295];
    int * v1175 = v1066->cache_vals;
    int v1297 = (((((int)((unsigned int)((int)((unsigned int)v1074 >> 2)) >> 1)) & 1) * 2) + ((((v1100 + ((~(((v1102 ^ -1) | (-(v1102 ^ -1))) >> 31)) & 2)) - (v1104 + ((~(((v1106 ^ -1) | (-(v1106 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
    v1175[v1297] = v1172;
    int * v1177 = v1066->cache_vals;
    int v1300 = ((((((int)((unsigned int)((int)((unsigned int)v1074 >> 2)) >> 1)) & 1) * 2) + ((((v1100 + ((~(((v1102 ^ -1) | (-(v1102 ^ -1))) >> 31)) & 2)) - (v1104 + ((~(((v1106 ^ -1) | (-(v1106 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
    v1177[v1300] = v1174;
    int * v1179 = v1066->cache_tags;
    int v1303 = ((((int)((unsigned int)((int)((unsigned int)v1074 >> 2)) >> 1)) & 1) * 2) + ((((v1100 + ((~(((v1102 ^ -1) | (-(v1102 ^ -1))) >> 31)) & 2)) - (v1104 + ((~(((v1106 ^ -1) | (-(v1106 ^ -1))) >> 31)) & 2))) >> 31) & 1);
    int v1304 = (int)((unsigned int)((int)((unsigned int)v1074 >> 2)) >> 1);
    v1179[v1303] = v1304;
    int * v1181 = v1066->cache_dirty;
    v1181[v1303] = 0;
    int * v1183 = v1066->cache_age;
    v1183[v1303] = 1;
    int * v1185 = v1066->cache_age;
    int v1186 = v1185[v1303];
    int * v1187 = v1066->cache_age;
    int v1188 = v1187[v1212];
    int * v1189 = v1066->cache_age;
    int v1312 = v1188 + ((int)((unsigned int)(v1188 - v1186) >> 31));
    v1189[v1212] = v1312;
    int * v1191 = v1066->cache_age;
    int v1192 = v1191[v1214];
    int * v1193 = v1066->cache_age;
    int v1315 = v1192 + ((int)((unsigned int)(v1192 - v1186) >> 31));
    v1193[v1214] = v1315;
    int * v1195 = v1066->cache_age;
    v1195[v1303] = 0;
    v1198 = v1303;
  }
  int v1318 = (v1198 * 2) + (((int)((unsigned int)v1074 >> 2)) & 1);
  int v1199 = v1085[v1318];
  int * v1200 = v1066->regs;
  v1200[5] = v1199;
  struct StateT * v1202 = slot_15(v1066);
  return v1202;
}

struct StateT * slot_6(struct StateT * v334) {
  int * v335 = v334->regs;
  int v336 = v335[6];
  int * v337 = v334->regs;
  int v338 = v337[7];
  bool v358 = v336 >= v338;
  struct StateT * v352;
  if (v358) {
    int v339 = v334->timer;
    int v359 = v339 + 15;
    v334->timer = v359;
    int * v341 = v334->saved_regs;
    int v342 = v341[8];
    int * v343 = v334->regs;
    v343[8] = v342;
    int * v345 = v334->saved_regs;
    int v346 = v345[5];
    int * v347 = v334->regs;
    v347[5] = v346;
    v352 = v334;
  } else {
    struct StateT * v350 = slot_8(v334);
    v352 = v350;
  }
  return v352;
}

struct StateT * slot_5(struct StateT * v77) {
  int * v78 = v77->saved_regs;
  int * v79 = v77->regs;
  int v80 = v79[5];
  v78[5] = v80;
  int v82 = v77->timer;
  int v219 = v82 + 1;
  v77->timer = v219;
  int * v84 = v77->regs;
  int v85 = v84[8];
  int * v86 = v77->cache_tags;
  int v223 = (((int)((unsigned int)((int)((unsigned int)v85 >> 2)) >> 1)) & 1) * 2;
  int v87 = v86[v223];
  int * v88 = v77->cache_tags;
  int v225 = ((((int)((unsigned int)((int)((unsigned int)v85 >> 2)) >> 1)) & 1) * 2) + 1;
  int v89 = v88[v225];
  int * v90 = v77->cache_tags;
  int v227 = 4 + ((((int)((unsigned int)((int)((unsigned int)v85 >> 2)) >> 1)) & 3) * 2);
  int v91 = v90[v227];
  int * v92 = v77->cache_tags;
  int v229 = (4 + ((((int)((unsigned int)((int)((unsigned int)v85 >> 2)) >> 1)) & 3) * 2)) + 1;
  int v93 = v92[v229];
  int v94 = v77->timer;
  int v230 = v94 + ((100 ^ (((~(((v91 ^ ((int)((unsigned int)((int)((unsigned int)v85 >> 2)) >> 1))) | (-(v91 ^ ((int)((unsigned int)((int)((unsigned int)v85 >> 2)) >> 1))))) >> 31)) | (~(((v93 ^ ((int)((unsigned int)((int)((unsigned int)v85 >> 2)) >> 1))) | (-(v93 ^ ((int)((unsigned int)((int)((unsigned int)v85 >> 2)) >> 1))))) >> 31))) & 104)) ^ (((~(((v87 ^ ((int)((unsigned int)((int)((unsigned int)v85 >> 2)) >> 1))) | (-(v87 ^ ((int)((unsigned int)((int)((unsigned int)v85 >> 2)) >> 1))))) >> 31)) | (~(((v89 ^ ((int)((unsigned int)((int)((unsigned int)v85 >> 2)) >> 1))) | (-(v89 ^ ((int)((unsigned int)((int)((unsigned int)v85 >> 2)) >> 1))))) >> 31))) & (1 ^ (100 ^ (((~(((v91 ^ ((int)((unsigned int)((int)((unsigned int)v85 >> 2)) >> 1))) | (-(v91 ^ ((int)((unsigned int)((int)((unsigned int)v85 >> 2)) >> 1))))) >> 31)) | (~(((v93 ^ ((int)((unsigned int)((int)((unsigned int)v85 >> 2)) >> 1))) | (-(v93 ^ ((int)((unsigned int)((int)((unsigned int)v85 >> 2)) >> 1))))) >> 31))) & 104)))));
  v77->timer = v230;
  int * v96 = v77->cache_vals;
  bool v231 = !(((~(((v87 ^ ((int)((unsigned int)((int)((unsigned int)v85 >> 2)) >> 1))) | (-(v87 ^ ((int)((unsigned int)((int)((unsigned int)v85 >> 2)) >> 1))))) >> 31)) | (~(((v89 ^ ((int)((unsigned int)((int)((unsigned int)v85 >> 2)) >> 1))) | (-(v89 ^ ((int)((unsigned int)((int)((unsigned int)v85 >> 2)) >> 1))))) >> 31))) == 0);
  int v209;
  if (v231) {
    int * v97 = v77->cache_age;
    int v233 = ((((int)((unsigned int)((int)((unsigned int)v85 >> 2)) >> 1)) & 1) * 2) + ((~(((v89 ^ ((int)((unsigned int)((int)((unsigned int)v85 >> 2)) >> 1))) | (-(v89 ^ ((int)((unsigned int)((int)((unsigned int)v85 >> 2)) >> 1))))) >> 31)) & 1);
    int v98 = v97[v233];
    int * v99 = v77->cache_age;
    int v100 = v99[v223];
    int * v101 = v77->cache_age;
    int v236 = v100 + ((int)((unsigned int)(v100 - v98) >> 31));
    v101[v223] = v236;
    int * v103 = v77->cache_age;
    int v104 = v103[v225];
    int * v105 = v77->cache_age;
    int v239 = v104 + ((int)((unsigned int)(v104 - v98) >> 31));
    v105[v225] = v239;
    int * v107 = v77->cache_age;
    v107[v233] = 0;
    v209 = v233;
  } else {
    int * v110 = v77->cache_age;
    int v243 = (((int)((unsigned int)((int)((unsigned int)v85 >> 2)) >> 1)) & 1) * 2;
    int v111 = v110[v243];
    int * v112 = v77->cache_tags;
    int v113 = v112[v243];
    int * v114 = v77->cache_age;
    int v115 = v114[v225];
    int * v116 = v77->cache_tags;
    int v117 = v116[v225];
    bool v247 = !(((~(((v91 ^ ((int)((unsigned int)((int)((unsigned int)v85 >> 2)) >> 1))) | (-(v91 ^ ((int)((unsigned int)((int)((unsigned int)v85 >> 2)) >> 1))))) >> 31)) | (~(((v93 ^ ((int)((unsigned int)((int)((unsigned int)v85 >> 2)) >> 1))) | (-(v93 ^ ((int)((unsigned int)((int)((unsigned int)v85 >> 2)) >> 1))))) >> 31))) == 0);
    int v181;
    if (v247) {
      int * v118 = v77->cache_age;
      int v249 = (4 + ((((int)((unsigned int)((int)((unsigned int)v85 >> 2)) >> 1)) & 3) * 2)) + ((~(((v93 ^ ((int)((unsigned int)((int)((unsigned int)v85 >> 2)) >> 1))) | (-(v93 ^ ((int)((unsigned int)((int)((unsigned int)v85 >> 2)) >> 1))))) >> 31)) & 1);
      int v119 = v118[v249];
      int * v120 = v77->cache_age;
      int v121 = v120[v227];
      int * v122 = v77->cache_age;
      int v252 = v121 + ((int)((unsigned int)(v121 - v119) >> 31));
      v122[v227] = v252;
      int * v124 = v77->cache_age;
      int v125 = v124[v229];
      int * v126 = v77->cache_age;
      int v255 = v125 + ((int)((unsigned int)(v125 - v119) >> 31));
      v126[v229] = v255;
      int * v128 = v77->cache_age;
      v128[v249] = 0;
      v181 = v249;
    } else {
      int * v131 = v77->cache_age;
      int v259 = 4 + ((((int)((unsigned int)((int)((unsigned int)v85 >> 2)) >> 1)) & 3) * 2);
      int v132 = v131[v259];
      int * v133 = v77->cache_tags;
      int v134 = v133[v259];
      int * v135 = v77->cache_age;
      int v136 = v135[v229];
      int * v137 = v77->cache_tags;
      int v138 = v137[v229];
      int * v139 = v77->cache_dirty;
      int v264 = (4 + ((((int)((unsigned int)((int)((unsigned int)v85 >> 2)) >> 1)) & 3) * 2)) + ((((v132 + ((~(((v134 ^ -1) | (-(v134 ^ -1))) >> 31)) & 2)) - (v136 + ((~(((v138 ^ -1) | (-(v138 ^ -1))) >> 31)) & 2))) >> 31) & 1);
      int v140 = v139[v264];
      bool v265 = !(v140 == 0);
      if (v265) {
        int * v141 = v77->cache_tags;
        int v142 = v141[v264];
        int * v143 = v77->cache_vals;
        int v268 = ((4 + ((((int)((unsigned int)((int)((unsigned int)v85 >> 2)) >> 1)) & 3) * 2)) + ((((v132 + ((~(((v134 ^ -1) | (-(v134 ^ -1))) >> 31)) & 2)) - (v136 + ((~(((v138 ^ -1) | (-(v138 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
        int v144 = v143[v268];
        int * v145 = v77->cache_vals;
        int v270 = (((4 + ((((int)((unsigned int)((int)((unsigned int)v85 >> 2)) >> 1)) & 3) * 2)) + ((((v132 + ((~(((v134 ^ -1) | (-(v134 ^ -1))) >> 31)) & 2)) - (v136 + ((~(((v138 ^ -1) | (-(v138 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
        int v146 = v145[v270];
        int * v147 = v77->mem;
        int v272 = v142 * 2;
        v147[v272] = v144;
        int * v149 = v77->mem;
        int v275 = (v142 * 2) + 1;
        v149[v275] = v146;
        ;
      } else {
        ;
      }
      int * v154 = v77->mem;
      int v280 = ((int)((unsigned int)((int)((unsigned int)v85 >> 2)) >> 1)) * 2;
      int v155 = v154[v280];
      int * v156 = v77->mem;
      int v282 = (((int)((unsigned int)((int)((unsigned int)v85 >> 2)) >> 1)) * 2) + 1;
      int v157 = v156[v282];
      int * v158 = v77->cache_vals;
      int v284 = ((4 + ((((int)((unsigned int)((int)((unsigned int)v85 >> 2)) >> 1)) & 3) * 2)) + ((((v132 + ((~(((v134 ^ -1) | (-(v134 ^ -1))) >> 31)) & 2)) - (v136 + ((~(((v138 ^ -1) | (-(v138 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
      v158[v284] = v155;
      int * v160 = v77->cache_vals;
      int v287 = (((4 + ((((int)((unsigned int)((int)((unsigned int)v85 >> 2)) >> 1)) & 3) * 2)) + ((((v132 + ((~(((v134 ^ -1) | (-(v134 ^ -1))) >> 31)) & 2)) - (v136 + ((~(((v138 ^ -1) | (-(v138 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
      v160[v287] = v157;
      int * v162 = v77->cache_tags;
      int v290 = (int)((unsigned int)((int)((unsigned int)v85 >> 2)) >> 1);
      v162[v264] = v290;
      int * v164 = v77->cache_dirty;
      v164[v264] = 0;
      int * v166 = v77->cache_age;
      v166[v264] = 1;
      int * v168 = v77->cache_age;
      int v169 = v168[v264];
      int * v170 = v77->cache_age;
      int v171 = v170[v227];
      int * v172 = v77->cache_age;
      int v298 = v171 + ((int)((unsigned int)(v171 - v169) >> 31));
      v172[v227] = v298;
      int * v174 = v77->cache_age;
      int v175 = v174[v229];
      int * v176 = v77->cache_age;
      int v301 = v175 + ((int)((unsigned int)(v175 - v169) >> 31));
      v176[v229] = v301;
      int * v178 = v77->cache_age;
      v178[v264] = 0;
      v181 = v264;
    }
    int * v182 = v77->cache_vals;
    int v304 = v181 * 2;
    int v183 = v182[v304];
    int * v184 = v77->cache_vals;
    int v306 = (v181 * 2) + 1;
    int v185 = v184[v306];
    int * v186 = v77->cache_vals;
    int v308 = (((((int)((unsigned int)((int)((unsigned int)v85 >> 2)) >> 1)) & 1) * 2) + ((((v111 + ((~(((v113 ^ -1) | (-(v113 ^ -1))) >> 31)) & 2)) - (v115 + ((~(((v117 ^ -1) | (-(v117 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
    v186[v308] = v183;
    int * v188 = v77->cache_vals;
    int v311 = ((((((int)((unsigned int)((int)((unsigned int)v85 >> 2)) >> 1)) & 1) * 2) + ((((v111 + ((~(((v113 ^ -1) | (-(v113 ^ -1))) >> 31)) & 2)) - (v115 + ((~(((v117 ^ -1) | (-(v117 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
    v188[v311] = v185;
    int * v190 = v77->cache_tags;
    int v314 = ((((int)((unsigned int)((int)((unsigned int)v85 >> 2)) >> 1)) & 1) * 2) + ((((v111 + ((~(((v113 ^ -1) | (-(v113 ^ -1))) >> 31)) & 2)) - (v115 + ((~(((v117 ^ -1) | (-(v117 ^ -1))) >> 31)) & 2))) >> 31) & 1);
    int v315 = (int)((unsigned int)((int)((unsigned int)v85 >> 2)) >> 1);
    v190[v314] = v315;
    int * v192 = v77->cache_dirty;
    v192[v314] = 0;
    int * v194 = v77->cache_age;
    v194[v314] = 1;
    int * v196 = v77->cache_age;
    int v197 = v196[v314];
    int * v198 = v77->cache_age;
    int v199 = v198[v223];
    int * v200 = v77->cache_age;
    int v323 = v199 + ((int)((unsigned int)(v199 - v197) >> 31));
    v200[v223] = v323;
    int * v202 = v77->cache_age;
    int v203 = v202[v225];
    int * v204 = v77->cache_age;
    int v326 = v203 + ((int)((unsigned int)(v203 - v197) >> 31));
    v204[v225] = v326;
    int * v206 = v77->cache_age;
    v206[v314] = 0;
    v209 = v314;
  }
  int v329 = (v209 * 2) + (((int)((unsigned int)v85 >> 2)) & 1);
  int v210 = v96[v329];
  int * v211 = v77->regs;
  v211[5] = v210;
  struct StateT * v213 = slot_6(v77);
  return v213;
}

struct StateT * slot_2(struct StateT * v28) {
  int v29 = v28->timer;
  int v35 = v29 + 1;
  v28->timer = v35;
  int * v31 = v28->regs;
  v31[9] = 80;
  struct StateT * v33 = slot_3(v28);
  return v33;
}

struct StateT * slot_3(struct StateT * v41) {
  int v42 = v41->timer;
  int v46 = v42 + 1;
  v41->timer = v46;
  struct StateT * v44 = slot_4(v41);
  return v44;
}

struct StateT * snippet(struct StateT * v0) {
  struct StateT * v1 = slot_0(v0);
  return v1;
}

struct StateT * slot_10(struct StateT * v1006) {
  int v1007 = v1006->timer;
  int v1015 = v1007 + 1;
  v1006->timer = v1015;
  int * v1009 = v1006->regs;
  int v1010 = v1009[6];
  int * v1011 = v1006->regs;
  int v1019 = v1010 + 4;
  v1011[6] = v1019;
  struct StateT * v1013 = slot_11(v1006);
  return v1013;
}

struct StateT * slot_1(struct StateT * v15) {
  int v16 = v15->timer;
  int v22 = v16 + 1;
  v15->timer = v22;
  int * v18 = v15->regs;
  v18[7] = 16;
  struct StateT * v20 = slot_2(v15);
  return v20;
}

struct StateT * slot_8(struct StateT * v371) {
  int v372 = v371->timer;
  int v577 = v372 + 1;
  v371->timer = v577;
  int * v374 = v371->regs;
  int v375 = v374[6];
  int * v376 = v371->regs;
  int v377 = v376[5];
  int * v378 = v371->cache_tags;
  int v583 = (((int)((unsigned int)((int)((unsigned int)v375 >> 2)) >> 1)) & 1) * 2;
  int v379 = v378[v583];
  int * v380 = v371->cache_tags;
  int v585 = ((((int)((unsigned int)((int)((unsigned int)v375 >> 2)) >> 1)) & 1) * 2) + 1;
  int v381 = v380[v585];
  int * v382 = v371->cache_tags;
  int v587 = 4 + ((((int)((unsigned int)((int)((unsigned int)v375 >> 2)) >> 1)) & 3) * 2);
  int v383 = v382[v587];
  int * v384 = v371->cache_tags;
  int v589 = (4 + ((((int)((unsigned int)((int)((unsigned int)v375 >> 2)) >> 1)) & 3) * 2)) + 1;
  int v385 = v384[v589];
  int v386 = v371->timer;
  int v590 = v386 + ((100 ^ (((~(((v383 ^ ((int)((unsigned int)((int)((unsigned int)v375 >> 2)) >> 1))) | (-(v383 ^ ((int)((unsigned int)((int)((unsigned int)v375 >> 2)) >> 1))))) >> 31)) | (~(((v385 ^ ((int)((unsigned int)((int)((unsigned int)v375 >> 2)) >> 1))) | (-(v385 ^ ((int)((unsigned int)((int)((unsigned int)v375 >> 2)) >> 1))))) >> 31))) & 104)) ^ (((~(((v379 ^ ((int)((unsigned int)((int)((unsigned int)v375 >> 2)) >> 1))) | (-(v379 ^ ((int)((unsigned int)((int)((unsigned int)v375 >> 2)) >> 1))))) >> 31)) | (~(((v381 ^ ((int)((unsigned int)((int)((unsigned int)v375 >> 2)) >> 1))) | (-(v381 ^ ((int)((unsigned int)((int)((unsigned int)v375 >> 2)) >> 1))))) >> 31))) & (1 ^ (100 ^ (((~(((v383 ^ ((int)((unsigned int)((int)((unsigned int)v375 >> 2)) >> 1))) | (-(v383 ^ ((int)((unsigned int)((int)((unsigned int)v375 >> 2)) >> 1))))) >> 31)) | (~(((v385 ^ ((int)((unsigned int)((int)((unsigned int)v375 >> 2)) >> 1))) | (-(v385 ^ ((int)((unsigned int)((int)((unsigned int)v375 >> 2)) >> 1))))) >> 31))) & 104)))));
  v371->timer = v590;
  bool v591 = !(((~(((v379 ^ ((int)((unsigned int)((int)((unsigned int)v375 >> 2)) >> 1))) | (-(v379 ^ ((int)((unsigned int)((int)((unsigned int)v375 >> 2)) >> 1))))) >> 31)) | (~(((v381 ^ ((int)((unsigned int)((int)((unsigned int)v375 >> 2)) >> 1))) | (-(v381 ^ ((int)((unsigned int)((int)((unsigned int)v375 >> 2)) >> 1))))) >> 31))) == 0);
  int v500;
  if (v591) {
    int * v388 = v371->cache_age;
    int v593 = ((((int)((unsigned int)((int)((unsigned int)v375 >> 2)) >> 1)) & 1) * 2) + ((~(((v381 ^ ((int)((unsigned int)((int)((unsigned int)v375 >> 2)) >> 1))) | (-(v381 ^ ((int)((unsigned int)((int)((unsigned int)v375 >> 2)) >> 1))))) >> 31)) & 1);
    int v389 = v388[v593];
    int * v390 = v371->cache_age;
    int v391 = v390[v583];
    int * v392 = v371->cache_age;
    int v596 = v391 + ((int)((unsigned int)(v391 - v389) >> 31));
    v392[v583] = v596;
    int * v394 = v371->cache_age;
    int v395 = v394[v585];
    int * v396 = v371->cache_age;
    int v599 = v395 + ((int)((unsigned int)(v395 - v389) >> 31));
    v396[v585] = v599;
    int * v398 = v371->cache_age;
    v398[v593] = 0;
    v500 = v593;
  } else {
    int * v401 = v371->cache_age;
    int v603 = (((int)((unsigned int)((int)((unsigned int)v375 >> 2)) >> 1)) & 1) * 2;
    int v402 = v401[v603];
    int * v403 = v371->cache_tags;
    int v404 = v403[v603];
    int * v405 = v371->cache_age;
    int v406 = v405[v585];
    int * v407 = v371->cache_tags;
    int v408 = v407[v585];
    bool v607 = !(((~(((v383 ^ ((int)((unsigned int)((int)((unsigned int)v375 >> 2)) >> 1))) | (-(v383 ^ ((int)((unsigned int)((int)((unsigned int)v375 >> 2)) >> 1))))) >> 31)) | (~(((v385 ^ ((int)((unsigned int)((int)((unsigned int)v375 >> 2)) >> 1))) | (-(v385 ^ ((int)((unsigned int)((int)((unsigned int)v375 >> 2)) >> 1))))) >> 31))) == 0);
    int v472;
    if (v607) {
      int * v409 = v371->cache_age;
      int v609 = (4 + ((((int)((unsigned int)((int)((unsigned int)v375 >> 2)) >> 1)) & 3) * 2)) + ((~(((v385 ^ ((int)((unsigned int)((int)((unsigned int)v375 >> 2)) >> 1))) | (-(v385 ^ ((int)((unsigned int)((int)((unsigned int)v375 >> 2)) >> 1))))) >> 31)) & 1);
      int v410 = v409[v609];
      int * v411 = v371->cache_age;
      int v412 = v411[v587];
      int * v413 = v371->cache_age;
      int v612 = v412 + ((int)((unsigned int)(v412 - v410) >> 31));
      v413[v587] = v612;
      int * v415 = v371->cache_age;
      int v416 = v415[v589];
      int * v417 = v371->cache_age;
      int v615 = v416 + ((int)((unsigned int)(v416 - v410) >> 31));
      v417[v589] = v615;
      int * v419 = v371->cache_age;
      v419[v609] = 0;
      v472 = v609;
    } else {
      int * v422 = v371->cache_age;
      int v619 = 4 + ((((int)((unsigned int)((int)((unsigned int)v375 >> 2)) >> 1)) & 3) * 2);
      int v423 = v422[v619];
      int * v424 = v371->cache_tags;
      int v425 = v424[v619];
      int * v426 = v371->cache_age;
      int v427 = v426[v589];
      int * v428 = v371->cache_tags;
      int v429 = v428[v589];
      int * v430 = v371->cache_dirty;
      int v624 = (4 + ((((int)((unsigned int)((int)((unsigned int)v375 >> 2)) >> 1)) & 3) * 2)) + ((((v423 + ((~(((v425 ^ -1) | (-(v425 ^ -1))) >> 31)) & 2)) - (v427 + ((~(((v429 ^ -1) | (-(v429 ^ -1))) >> 31)) & 2))) >> 31) & 1);
      int v431 = v430[v624];
      bool v625 = !(v431 == 0);
      if (v625) {
        int * v432 = v371->cache_tags;
        int v433 = v432[v624];
        int * v434 = v371->cache_vals;
        int v628 = ((4 + ((((int)((unsigned int)((int)((unsigned int)v375 >> 2)) >> 1)) & 3) * 2)) + ((((v423 + ((~(((v425 ^ -1) | (-(v425 ^ -1))) >> 31)) & 2)) - (v427 + ((~(((v429 ^ -1) | (-(v429 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
        int v435 = v434[v628];
        int * v436 = v371->cache_vals;
        int v630 = (((4 + ((((int)((unsigned int)((int)((unsigned int)v375 >> 2)) >> 1)) & 3) * 2)) + ((((v423 + ((~(((v425 ^ -1) | (-(v425 ^ -1))) >> 31)) & 2)) - (v427 + ((~(((v429 ^ -1) | (-(v429 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
        int v437 = v436[v630];
        int * v438 = v371->mem;
        int v632 = v433 * 2;
        v438[v632] = v435;
        int * v440 = v371->mem;
        int v635 = (v433 * 2) + 1;
        v440[v635] = v437;
        ;
      } else {
        ;
      }
      int * v445 = v371->mem;
      int v640 = ((int)((unsigned int)((int)((unsigned int)v375 >> 2)) >> 1)) * 2;
      int v446 = v445[v640];
      int * v447 = v371->mem;
      int v642 = (((int)((unsigned int)((int)((unsigned int)v375 >> 2)) >> 1)) * 2) + 1;
      int v448 = v447[v642];
      int * v449 = v371->cache_vals;
      int v644 = ((4 + ((((int)((unsigned int)((int)((unsigned int)v375 >> 2)) >> 1)) & 3) * 2)) + ((((v423 + ((~(((v425 ^ -1) | (-(v425 ^ -1))) >> 31)) & 2)) - (v427 + ((~(((v429 ^ -1) | (-(v429 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
      v449[v644] = v446;
      int * v451 = v371->cache_vals;
      int v647 = (((4 + ((((int)((unsigned int)((int)((unsigned int)v375 >> 2)) >> 1)) & 3) * 2)) + ((((v423 + ((~(((v425 ^ -1) | (-(v425 ^ -1))) >> 31)) & 2)) - (v427 + ((~(((v429 ^ -1) | (-(v429 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
      v451[v647] = v448;
      int * v453 = v371->cache_tags;
      int v650 = (int)((unsigned int)((int)((unsigned int)v375 >> 2)) >> 1);
      v453[v624] = v650;
      int * v455 = v371->cache_dirty;
      v455[v624] = 0;
      int * v457 = v371->cache_age;
      v457[v624] = 1;
      int * v459 = v371->cache_age;
      int v460 = v459[v624];
      int * v461 = v371->cache_age;
      int v462 = v461[v587];
      int * v463 = v371->cache_age;
      int v658 = v462 + ((int)((unsigned int)(v462 - v460) >> 31));
      v463[v587] = v658;
      int * v465 = v371->cache_age;
      int v466 = v465[v589];
      int * v467 = v371->cache_age;
      int v661 = v466 + ((int)((unsigned int)(v466 - v460) >> 31));
      v467[v589] = v661;
      int * v469 = v371->cache_age;
      v469[v624] = 0;
      v472 = v624;
    }
    int * v473 = v371->cache_vals;
    int v664 = v472 * 2;
    int v474 = v473[v664];
    int * v475 = v371->cache_vals;
    int v666 = (v472 * 2) + 1;
    int v476 = v475[v666];
    int * v477 = v371->cache_vals;
    int v668 = (((((int)((unsigned int)((int)((unsigned int)v375 >> 2)) >> 1)) & 1) * 2) + ((((v402 + ((~(((v404 ^ -1) | (-(v404 ^ -1))) >> 31)) & 2)) - (v406 + ((~(((v408 ^ -1) | (-(v408 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
    v477[v668] = v474;
    int * v479 = v371->cache_vals;
    int v671 = ((((((int)((unsigned int)((int)((unsigned int)v375 >> 2)) >> 1)) & 1) * 2) + ((((v402 + ((~(((v404 ^ -1) | (-(v404 ^ -1))) >> 31)) & 2)) - (v406 + ((~(((v408 ^ -1) | (-(v408 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
    v479[v671] = v476;
    int * v481 = v371->cache_tags;
    int v674 = ((((int)((unsigned int)((int)((unsigned int)v375 >> 2)) >> 1)) & 1) * 2) + ((((v402 + ((~(((v404 ^ -1) | (-(v404 ^ -1))) >> 31)) & 2)) - (v406 + ((~(((v408 ^ -1) | (-(v408 ^ -1))) >> 31)) & 2))) >> 31) & 1);
    int v675 = (int)((unsigned int)((int)((unsigned int)v375 >> 2)) >> 1);
    v481[v674] = v675;
    int * v483 = v371->cache_dirty;
    v483[v674] = 0;
    int * v485 = v371->cache_age;
    v485[v674] = 1;
    int * v487 = v371->cache_age;
    int v488 = v487[v674];
    int * v489 = v371->cache_age;
    int v490 = v489[v583];
    int * v491 = v371->cache_age;
    int v683 = v490 + ((int)((unsigned int)(v490 - v488) >> 31));
    v491[v583] = v683;
    int * v493 = v371->cache_age;
    int v494 = v493[v585];
    int * v495 = v371->cache_age;
    int v686 = v494 + ((int)((unsigned int)(v494 - v488) >> 31));
    v495[v585] = v686;
    int * v497 = v371->cache_age;
    v497[v674] = 0;
    v500 = v674;
  }
  int * v501 = v371->cache_vals;
  int v689 = (v500 * 2) + (((int)((unsigned int)v375 >> 2)) & 1);
  v501[v689] = v377;
  int * v503 = v371->cache_tags;
  int v504 = v503[v587];
  int * v505 = v371->cache_tags;
  int v506 = v505[v589];
  bool v693 = !(((~(((v504 ^ ((int)((unsigned int)((int)((unsigned int)v375 >> 2)) >> 1))) | (-(v504 ^ ((int)((unsigned int)((int)((unsigned int)v375 >> 2)) >> 1))))) >> 31)) | (~(((v506 ^ ((int)((unsigned int)((int)((unsigned int)v375 >> 2)) >> 1))) | (-(v506 ^ ((int)((unsigned int)((int)((unsigned int)v375 >> 2)) >> 1))))) >> 31))) == 0);
  int v570;
  if (v693) {
    int * v507 = v371->cache_age;
    int v695 = (4 + ((((int)((unsigned int)((int)((unsigned int)v375 >> 2)) >> 1)) & 3) * 2)) + ((~(((v506 ^ ((int)((unsigned int)((int)((unsigned int)v375 >> 2)) >> 1))) | (-(v506 ^ ((int)((unsigned int)((int)((unsigned int)v375 >> 2)) >> 1))))) >> 31)) & 1);
    int v508 = v507[v695];
    int * v509 = v371->cache_age;
    int v510 = v509[v587];
    int * v511 = v371->cache_age;
    int v698 = v510 + ((int)((unsigned int)(v510 - v508) >> 31));
    v511[v587] = v698;
    int * v513 = v371->cache_age;
    int v514 = v513[v589];
    int * v515 = v371->cache_age;
    int v701 = v514 + ((int)((unsigned int)(v514 - v508) >> 31));
    v515[v589] = v701;
    int * v517 = v371->cache_age;
    v517[v695] = 0;
    v570 = v695;
  } else {
    int * v520 = v371->cache_age;
    int v705 = 4 + ((((int)((unsigned int)((int)((unsigned int)v375 >> 2)) >> 1)) & 3) * 2);
    int v521 = v520[v705];
    int * v522 = v371->cache_tags;
    int v523 = v522[v705];
    int * v524 = v371->cache_age;
    int v525 = v524[v589];
    int * v526 = v371->cache_tags;
    int v527 = v526[v589];
    int * v528 = v371->cache_dirty;
    int v710 = (4 + ((((int)((unsigned int)((int)((unsigned int)v375 >> 2)) >> 1)) & 3) * 2)) + ((((v521 + ((~(((v523 ^ -1) | (-(v523 ^ -1))) >> 31)) & 2)) - (v525 + ((~(((v527 ^ -1) | (-(v527 ^ -1))) >> 31)) & 2))) >> 31) & 1);
    int v529 = v528[v710];
    bool v711 = !(v529 == 0);
    if (v711) {
      int * v530 = v371->cache_tags;
      int v531 = v530[v710];
      int * v532 = v371->cache_vals;
      int v714 = ((4 + ((((int)((unsigned int)((int)((unsigned int)v375 >> 2)) >> 1)) & 3) * 2)) + ((((v521 + ((~(((v523 ^ -1) | (-(v523 ^ -1))) >> 31)) & 2)) - (v525 + ((~(((v527 ^ -1) | (-(v527 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
      int v533 = v532[v714];
      int * v534 = v371->cache_vals;
      int v716 = (((4 + ((((int)((unsigned int)((int)((unsigned int)v375 >> 2)) >> 1)) & 3) * 2)) + ((((v521 + ((~(((v523 ^ -1) | (-(v523 ^ -1))) >> 31)) & 2)) - (v525 + ((~(((v527 ^ -1) | (-(v527 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
      int v535 = v534[v716];
      int * v536 = v371->mem;
      int v718 = v531 * 2;
      v536[v718] = v533;
      int * v538 = v371->mem;
      int v721 = (v531 * 2) + 1;
      v538[v721] = v535;
      ;
    } else {
      ;
    }
    int * v543 = v371->mem;
    int v726 = ((int)((unsigned int)((int)((unsigned int)v375 >> 2)) >> 1)) * 2;
    int v544 = v543[v726];
    int * v545 = v371->mem;
    int v728 = (((int)((unsigned int)((int)((unsigned int)v375 >> 2)) >> 1)) * 2) + 1;
    int v546 = v545[v728];
    int * v547 = v371->cache_vals;
    int v730 = ((4 + ((((int)((unsigned int)((int)((unsigned int)v375 >> 2)) >> 1)) & 3) * 2)) + ((((v521 + ((~(((v523 ^ -1) | (-(v523 ^ -1))) >> 31)) & 2)) - (v525 + ((~(((v527 ^ -1) | (-(v527 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
    v547[v730] = v544;
    int * v549 = v371->cache_vals;
    int v733 = (((4 + ((((int)((unsigned int)((int)((unsigned int)v375 >> 2)) >> 1)) & 3) * 2)) + ((((v521 + ((~(((v523 ^ -1) | (-(v523 ^ -1))) >> 31)) & 2)) - (v525 + ((~(((v527 ^ -1) | (-(v527 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
    v549[v733] = v546;
    int * v551 = v371->cache_tags;
    int v736 = (int)((unsigned int)((int)((unsigned int)v375 >> 2)) >> 1);
    v551[v710] = v736;
    int * v553 = v371->cache_dirty;
    v553[v710] = 0;
    int * v555 = v371->cache_age;
    v555[v710] = 1;
    int * v557 = v371->cache_age;
    int v558 = v557[v710];
    int * v559 = v371->cache_age;
    int v560 = v559[v587];
    int * v561 = v371->cache_age;
    int v744 = v560 + ((int)((unsigned int)(v560 - v558) >> 31));
    v561[v587] = v744;
    int * v563 = v371->cache_age;
    int v564 = v563[v589];
    int * v565 = v371->cache_age;
    int v747 = v564 + ((int)((unsigned int)(v564 - v558) >> 31));
    v565[v589] = v747;
    int * v567 = v371->cache_age;
    v567[v710] = 0;
    v570 = v710;
  }
  int * v571 = v371->cache_vals;
  int v750 = (v570 * 2) + (((int)((unsigned int)v375 >> 2)) & 1);
  v571[v750] = v377;
  int * v573 = v371->cache_dirty;
  v573[v570] = 1;
  struct StateT * v575 = slot_9(v371);
  return v575;
}

struct StateT * slot_4(struct StateT * v49) {
  int * v50 = v49->saved_regs;
  int * v51 = v49->regs;
  int v52 = v51[8];
  v50[8] = v52;
  int v54 = v49->timer;
  int v68 = v54 + 1;
  v49->timer = v68;
  int * v56 = v49->regs;
  int v57 = v56[9];
  int * v58 = v49->regs;
  int v59 = v58[6];
  int * v60 = v49->regs;
  int v74 = v57 + v59;
  v60[8] = v74;
  struct StateT * v62 = slot_5(v49);
  return v62;
}

struct StateT * slot_13(struct StateT * v1038) {
  int * v1039 = v1038->saved_regs;
  int * v1040 = v1038->regs;
  int v1041 = v1040[8];
  v1039[8] = v1041;
  int v1043 = v1038->timer;
  int v1057 = v1043 + 1;
  v1038->timer = v1057;
  int * v1045 = v1038->regs;
  int v1046 = v1045[9];
  int * v1047 = v1038->regs;
  int v1048 = v1047[6];
  int * v1049 = v1038->regs;
  int v1063 = v1046 + v1048;
  v1049[8] = v1063;
  struct StateT * v1051 = slot_14(v1038);
  return v1051;
}

struct StateT * slot_15(struct StateT * v1323) {
  int * v1324 = v1323->regs;
  int v1325 = v1324[6];
  int * v1326 = v1323->regs;
  int v1327 = v1326[7];
  bool v1347 = v1325 >= v1327;
  struct StateT * v1341;
  if (v1347) {
    int v1328 = v1323->timer;
    int v1348 = v1328 + 15;
    v1323->timer = v1348;
    int * v1330 = v1323->saved_regs;
    int v1331 = v1330[8];
    int * v1332 = v1323->regs;
    v1332[8] = v1331;
    int * v1334 = v1323->saved_regs;
    int v1335 = v1334[5];
    int * v1336 = v1323->regs;
    v1336[5] = v1335;
    v1341 = v1323;
  } else {
    struct StateT * v1339 = slot_8(v1323);
    v1341 = v1339;
  }
  return v1341;
}

struct StateT * slot_9(struct StateT * v756) {
  int v757 = v756->timer;
  int v890 = v757 + 1;
  v756->timer = v890;
  int * v759 = v756->regs;
  int v760 = v759[6];
  int * v761 = v756->cache_tags;
  int v894 = (((int)((unsigned int)((int)((unsigned int)v760 >> 2)) >> 1)) & 1) * 2;
  int v762 = v761[v894];
  int * v763 = v756->cache_tags;
  int v896 = ((((int)((unsigned int)((int)((unsigned int)v760 >> 2)) >> 1)) & 1) * 2) + 1;
  int v764 = v763[v896];
  int * v765 = v756->cache_tags;
  int v898 = 4 + ((((int)((unsigned int)((int)((unsigned int)v760 >> 2)) >> 1)) & 3) * 2);
  int v766 = v765[v898];
  int * v767 = v756->cache_tags;
  int v900 = (4 + ((((int)((unsigned int)((int)((unsigned int)v760 >> 2)) >> 1)) & 3) * 2)) + 1;
  int v768 = v767[v900];
  int v769 = v756->timer;
  int v901 = v769 + ((100 ^ (((~(((v766 ^ ((int)((unsigned int)((int)((unsigned int)v760 >> 2)) >> 1))) | (-(v766 ^ ((int)((unsigned int)((int)((unsigned int)v760 >> 2)) >> 1))))) >> 31)) | (~(((v768 ^ ((int)((unsigned int)((int)((unsigned int)v760 >> 2)) >> 1))) | (-(v768 ^ ((int)((unsigned int)((int)((unsigned int)v760 >> 2)) >> 1))))) >> 31))) & 104)) ^ (((~(((v762 ^ ((int)((unsigned int)((int)((unsigned int)v760 >> 2)) >> 1))) | (-(v762 ^ ((int)((unsigned int)((int)((unsigned int)v760 >> 2)) >> 1))))) >> 31)) | (~(((v764 ^ ((int)((unsigned int)((int)((unsigned int)v760 >> 2)) >> 1))) | (-(v764 ^ ((int)((unsigned int)((int)((unsigned int)v760 >> 2)) >> 1))))) >> 31))) & (1 ^ (100 ^ (((~(((v766 ^ ((int)((unsigned int)((int)((unsigned int)v760 >> 2)) >> 1))) | (-(v766 ^ ((int)((unsigned int)((int)((unsigned int)v760 >> 2)) >> 1))))) >> 31)) | (~(((v768 ^ ((int)((unsigned int)((int)((unsigned int)v760 >> 2)) >> 1))) | (-(v768 ^ ((int)((unsigned int)((int)((unsigned int)v760 >> 2)) >> 1))))) >> 31))) & 104)))));
  v756->timer = v901;
  int * v771 = v756->cache_vals;
  bool v902 = !(((~(((v762 ^ ((int)((unsigned int)((int)((unsigned int)v760 >> 2)) >> 1))) | (-(v762 ^ ((int)((unsigned int)((int)((unsigned int)v760 >> 2)) >> 1))))) >> 31)) | (~(((v764 ^ ((int)((unsigned int)((int)((unsigned int)v760 >> 2)) >> 1))) | (-(v764 ^ ((int)((unsigned int)((int)((unsigned int)v760 >> 2)) >> 1))))) >> 31))) == 0);
  int v884;
  if (v902) {
    int * v772 = v756->cache_age;
    int v904 = ((((int)((unsigned int)((int)((unsigned int)v760 >> 2)) >> 1)) & 1) * 2) + ((~(((v764 ^ ((int)((unsigned int)((int)((unsigned int)v760 >> 2)) >> 1))) | (-(v764 ^ ((int)((unsigned int)((int)((unsigned int)v760 >> 2)) >> 1))))) >> 31)) & 1);
    int v773 = v772[v904];
    int * v774 = v756->cache_age;
    int v775 = v774[v894];
    int * v776 = v756->cache_age;
    int v907 = v775 + ((int)((unsigned int)(v775 - v773) >> 31));
    v776[v894] = v907;
    int * v778 = v756->cache_age;
    int v779 = v778[v896];
    int * v780 = v756->cache_age;
    int v910 = v779 + ((int)((unsigned int)(v779 - v773) >> 31));
    v780[v896] = v910;
    int * v782 = v756->cache_age;
    v782[v904] = 0;
    v884 = v904;
  } else {
    int * v785 = v756->cache_age;
    int v914 = (((int)((unsigned int)((int)((unsigned int)v760 >> 2)) >> 1)) & 1) * 2;
    int v786 = v785[v914];
    int * v787 = v756->cache_tags;
    int v788 = v787[v914];
    int * v789 = v756->cache_age;
    int v790 = v789[v896];
    int * v791 = v756->cache_tags;
    int v792 = v791[v896];
    bool v918 = !(((~(((v766 ^ ((int)((unsigned int)((int)((unsigned int)v760 >> 2)) >> 1))) | (-(v766 ^ ((int)((unsigned int)((int)((unsigned int)v760 >> 2)) >> 1))))) >> 31)) | (~(((v768 ^ ((int)((unsigned int)((int)((unsigned int)v760 >> 2)) >> 1))) | (-(v768 ^ ((int)((unsigned int)((int)((unsigned int)v760 >> 2)) >> 1))))) >> 31))) == 0);
    int v856;
    if (v918) {
      int * v793 = v756->cache_age;
      int v920 = (4 + ((((int)((unsigned int)((int)((unsigned int)v760 >> 2)) >> 1)) & 3) * 2)) + ((~(((v768 ^ ((int)((unsigned int)((int)((unsigned int)v760 >> 2)) >> 1))) | (-(v768 ^ ((int)((unsigned int)((int)((unsigned int)v760 >> 2)) >> 1))))) >> 31)) & 1);
      int v794 = v793[v920];
      int * v795 = v756->cache_age;
      int v796 = v795[v898];
      int * v797 = v756->cache_age;
      int v923 = v796 + ((int)((unsigned int)(v796 - v794) >> 31));
      v797[v898] = v923;
      int * v799 = v756->cache_age;
      int v800 = v799[v900];
      int * v801 = v756->cache_age;
      int v926 = v800 + ((int)((unsigned int)(v800 - v794) >> 31));
      v801[v900] = v926;
      int * v803 = v756->cache_age;
      v803[v920] = 0;
      v856 = v920;
    } else {
      int * v806 = v756->cache_age;
      int v930 = 4 + ((((int)((unsigned int)((int)((unsigned int)v760 >> 2)) >> 1)) & 3) * 2);
      int v807 = v806[v930];
      int * v808 = v756->cache_tags;
      int v809 = v808[v930];
      int * v810 = v756->cache_age;
      int v811 = v810[v900];
      int * v812 = v756->cache_tags;
      int v813 = v812[v900];
      int * v814 = v756->cache_dirty;
      int v935 = (4 + ((((int)((unsigned int)((int)((unsigned int)v760 >> 2)) >> 1)) & 3) * 2)) + ((((v807 + ((~(((v809 ^ -1) | (-(v809 ^ -1))) >> 31)) & 2)) - (v811 + ((~(((v813 ^ -1) | (-(v813 ^ -1))) >> 31)) & 2))) >> 31) & 1);
      int v815 = v814[v935];
      bool v936 = !(v815 == 0);
      if (v936) {
        int * v816 = v756->cache_tags;
        int v817 = v816[v935];
        int * v818 = v756->cache_vals;
        int v939 = ((4 + ((((int)((unsigned int)((int)((unsigned int)v760 >> 2)) >> 1)) & 3) * 2)) + ((((v807 + ((~(((v809 ^ -1) | (-(v809 ^ -1))) >> 31)) & 2)) - (v811 + ((~(((v813 ^ -1) | (-(v813 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
        int v819 = v818[v939];
        int * v820 = v756->cache_vals;
        int v941 = (((4 + ((((int)((unsigned int)((int)((unsigned int)v760 >> 2)) >> 1)) & 3) * 2)) + ((((v807 + ((~(((v809 ^ -1) | (-(v809 ^ -1))) >> 31)) & 2)) - (v811 + ((~(((v813 ^ -1) | (-(v813 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
        int v821 = v820[v941];
        int * v822 = v756->mem;
        int v943 = v817 * 2;
        v822[v943] = v819;
        int * v824 = v756->mem;
        int v946 = (v817 * 2) + 1;
        v824[v946] = v821;
        ;
      } else {
        ;
      }
      int * v829 = v756->mem;
      int v951 = ((int)((unsigned int)((int)((unsigned int)v760 >> 2)) >> 1)) * 2;
      int v830 = v829[v951];
      int * v831 = v756->mem;
      int v953 = (((int)((unsigned int)((int)((unsigned int)v760 >> 2)) >> 1)) * 2) + 1;
      int v832 = v831[v953];
      int * v833 = v756->cache_vals;
      int v955 = ((4 + ((((int)((unsigned int)((int)((unsigned int)v760 >> 2)) >> 1)) & 3) * 2)) + ((((v807 + ((~(((v809 ^ -1) | (-(v809 ^ -1))) >> 31)) & 2)) - (v811 + ((~(((v813 ^ -1) | (-(v813 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
      v833[v955] = v830;
      int * v835 = v756->cache_vals;
      int v958 = (((4 + ((((int)((unsigned int)((int)((unsigned int)v760 >> 2)) >> 1)) & 3) * 2)) + ((((v807 + ((~(((v809 ^ -1) | (-(v809 ^ -1))) >> 31)) & 2)) - (v811 + ((~(((v813 ^ -1) | (-(v813 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
      v835[v958] = v832;
      int * v837 = v756->cache_tags;
      int v961 = (int)((unsigned int)((int)((unsigned int)v760 >> 2)) >> 1);
      v837[v935] = v961;
      int * v839 = v756->cache_dirty;
      v839[v935] = 0;
      int * v841 = v756->cache_age;
      v841[v935] = 1;
      int * v843 = v756->cache_age;
      int v844 = v843[v935];
      int * v845 = v756->cache_age;
      int v846 = v845[v898];
      int * v847 = v756->cache_age;
      int v969 = v846 + ((int)((unsigned int)(v846 - v844) >> 31));
      v847[v898] = v969;
      int * v849 = v756->cache_age;
      int v850 = v849[v900];
      int * v851 = v756->cache_age;
      int v972 = v850 + ((int)((unsigned int)(v850 - v844) >> 31));
      v851[v900] = v972;
      int * v853 = v756->cache_age;
      v853[v935] = 0;
      v856 = v935;
    }
    int * v857 = v756->cache_vals;
    int v975 = v856 * 2;
    int v858 = v857[v975];
    int * v859 = v756->cache_vals;
    int v977 = (v856 * 2) + 1;
    int v860 = v859[v977];
    int * v861 = v756->cache_vals;
    int v979 = (((((int)((unsigned int)((int)((unsigned int)v760 >> 2)) >> 1)) & 1) * 2) + ((((v786 + ((~(((v788 ^ -1) | (-(v788 ^ -1))) >> 31)) & 2)) - (v790 + ((~(((v792 ^ -1) | (-(v792 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
    v861[v979] = v858;
    int * v863 = v756->cache_vals;
    int v982 = ((((((int)((unsigned int)((int)((unsigned int)v760 >> 2)) >> 1)) & 1) * 2) + ((((v786 + ((~(((v788 ^ -1) | (-(v788 ^ -1))) >> 31)) & 2)) - (v790 + ((~(((v792 ^ -1) | (-(v792 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
    v863[v982] = v860;
    int * v865 = v756->cache_tags;
    int v985 = ((((int)((unsigned int)((int)((unsigned int)v760 >> 2)) >> 1)) & 1) * 2) + ((((v786 + ((~(((v788 ^ -1) | (-(v788 ^ -1))) >> 31)) & 2)) - (v790 + ((~(((v792 ^ -1) | (-(v792 ^ -1))) >> 31)) & 2))) >> 31) & 1);
    int v986 = (int)((unsigned int)((int)((unsigned int)v760 >> 2)) >> 1);
    v865[v985] = v986;
    int * v867 = v756->cache_dirty;
    v867[v985] = 0;
    int * v869 = v756->cache_age;
    v869[v985] = 1;
    int * v871 = v756->cache_age;
    int v872 = v871[v985];
    int * v873 = v756->cache_age;
    int v874 = v873[v894];
    int * v875 = v756->cache_age;
    int v994 = v874 + ((int)((unsigned int)(v874 - v872) >> 31));
    v875[v894] = v994;
    int * v877 = v756->cache_age;
    int v878 = v877[v896];
    int * v879 = v756->cache_age;
    int v997 = v878 + ((int)((unsigned int)(v878 - v872) >> 31));
    v879[v896] = v997;
    int * v881 = v756->cache_age;
    v881[v985] = 0;
    v884 = v985;
  }
  int v1000 = (v884 * 2) + (((int)((unsigned int)v760 >> 2)) & 1);
  int v885 = v771[v1000];
  int * v886 = v756->regs;
  v886[11] = v885;
  struct StateT * v888 = slot_10(v756);
  return v888;
}

struct StateT * slot_11(struct StateT * v1022) {
  int v1023 = v1022->timer;
  int v1027 = v1023 + 1;
  v1022->timer = v1027;
  struct StateT * v1025 = slot_12(v1022);
  return v1025;
}

struct StateT * slot_0(struct StateT * v2) {
  int v3 = v2->timer;
  int v9 = v3 + 1;
  v2->timer = v9;
  int * v5 = v2->regs;
  v5[6] = 0;
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