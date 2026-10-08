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

struct StateT * slot_6(struct StateT * v282);
struct StateT * slot_25(struct StateT * v1098);
struct StateT * slot_16(struct StateT * v594);
struct StateT * slot_23(struct StateT * v878);
struct StateT * slot_5(struct StateT * v274);
struct StateT * slot_2(struct StateT * v30);
struct StateT * slot_7(struct StateT * v296);
struct StateT * slot_21(struct StateT * v659);
struct StateT * slot_3(struct StateT * v233);
struct StateT * slot_10(struct StateT * v526);
struct StateT * slot_1(struct StateT * v10);
struct StateT * slot_19(struct StateT * v637);
struct StateT * slot_13(struct StateT * v553);
struct StateT * slot_24(struct StateT * v1082);
struct StateT * slot_0(struct StateT * v2);
struct StateT * slot_14(struct StateT * v566);
struct StateT * slot_17(struct StateT * v607);
struct StateT * slot_20(struct StateT * v645);
struct StateT * snippet(struct StateT * v0);
struct StateT * slot_8(struct StateT * v318);
struct StateT * slot_4(struct StateT * v261);
struct StateT * slot_15(struct StateT * v580);
struct StateT * slot_18(struct StateT * v623);
struct StateT * slot_9(struct StateT * v521);
struct StateT * slot_22(struct StateT * v675);
struct StateT * slot_11(struct StateT * v540);
struct StateT * slot_6(struct StateT * v282) {
  int v283 = v282->timer;
  int v290 = v283 + 1;
  v282->timer = v290;
  int * v285 = v282->regs;
  int v286 = v285[10];
  int v293 = v286 + 72;
  v285[10] = v293;
  struct StateT * v288 = slot_8(v282);
  return v288;
}

struct StateT * slot_25(struct StateT * v1098) {
  int v1099 = v1098->timer;
  int v1269 = v1099 + 1;
  v1098->timer = v1269;
  int * v1101 = v1098->regs;
  int v1102 = v1101[12];
  int v1103 = v1101[10];
  int * v1104 = v1098->cache_tags;
  int v1274 = (((int)((unsigned int)((int)((unsigned int)(v1102 + 68) >> 2)) >> 1)) & 1) * 2;
  int v1105 = v1104[v1274];
  int v1275 = ((((int)((unsigned int)((int)((unsigned int)(v1102 + 68) >> 2)) >> 1)) & 1) * 2) + 1;
  int v1106 = v1104[v1275];
  int v1276 = 4 + ((((int)((unsigned int)((int)((unsigned int)(v1102 + 68) >> 2)) >> 1)) & 3) * 2);
  int v1107 = v1104[v1276];
  int v1277 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v1102 + 68) >> 2)) >> 1)) & 3) * 2)) + 1;
  int v1108 = v1104[v1277];
  int v1109 = v1098->timer;
  int v1278 = v1109 + ((100 ^ (((~(((v1107 ^ ((int)((unsigned int)((int)((unsigned int)(v1102 + 68) >> 2)) >> 1))) | (-(v1107 ^ ((int)((unsigned int)((int)((unsigned int)(v1102 + 68) >> 2)) >> 1))))) >> 31)) | (~(((v1108 ^ ((int)((unsigned int)((int)((unsigned int)(v1102 + 68) >> 2)) >> 1))) | (-(v1108 ^ ((int)((unsigned int)((int)((unsigned int)(v1102 + 68) >> 2)) >> 1))))) >> 31))) & 104)) ^ (((~(((v1105 ^ ((int)((unsigned int)((int)((unsigned int)(v1102 + 68) >> 2)) >> 1))) | (-(v1105 ^ ((int)((unsigned int)((int)((unsigned int)(v1102 + 68) >> 2)) >> 1))))) >> 31)) | (~(((v1106 ^ ((int)((unsigned int)((int)((unsigned int)(v1102 + 68) >> 2)) >> 1))) | (-(v1106 ^ ((int)((unsigned int)((int)((unsigned int)(v1102 + 68) >> 2)) >> 1))))) >> 31))) & (1 ^ (100 ^ (((~(((v1107 ^ ((int)((unsigned int)((int)((unsigned int)(v1102 + 68) >> 2)) >> 1))) | (-(v1107 ^ ((int)((unsigned int)((int)((unsigned int)(v1102 + 68) >> 2)) >> 1))))) >> 31)) | (~(((v1108 ^ ((int)((unsigned int)((int)((unsigned int)(v1102 + 68) >> 2)) >> 1))) | (-(v1108 ^ ((int)((unsigned int)((int)((unsigned int)(v1102 + 68) >> 2)) >> 1))))) >> 31))) & 104)))));
  v1098->timer = v1278;
  bool v1279 = !(((~(((v1105 ^ ((int)((unsigned int)((int)((unsigned int)(v1102 + 68) >> 2)) >> 1))) | (-(v1105 ^ ((int)((unsigned int)((int)((unsigned int)(v1102 + 68) >> 2)) >> 1))))) >> 31)) | (~(((v1106 ^ ((int)((unsigned int)((int)((unsigned int)(v1102 + 68) >> 2)) >> 1))) | (-(v1106 ^ ((int)((unsigned int)((int)((unsigned int)(v1102 + 68) >> 2)) >> 1))))) >> 31))) == 0);
  int v1203;
  if (v1279) {
    int * v1111 = v1098->cache_age;
    int v1281 = ((((int)((unsigned int)((int)((unsigned int)(v1102 + 68) >> 2)) >> 1)) & 1) * 2) + ((~(((v1106 ^ ((int)((unsigned int)((int)((unsigned int)(v1102 + 68) >> 2)) >> 1))) | (-(v1106 ^ ((int)((unsigned int)((int)((unsigned int)(v1102 + 68) >> 2)) >> 1))))) >> 31)) & 1);
    int v1112 = v1111[v1281];
    int v1113 = v1111[v1274];
    int v1282 = v1113 + ((int)((unsigned int)(v1113 - v1112) >> 31));
    v1111[v1274] = v1282;
    int * v1115 = v1098->cache_age;
    int v1116 = v1115[v1275];
    int v1284 = v1116 + ((int)((unsigned int)(v1116 - v1112) >> 31));
    v1115[v1275] = v1284;
    int * v1118 = v1098->cache_age;
    v1118[v1281] = 0;
    v1203 = v1281;
  } else {
    int * v1121 = v1098->cache_age;
    int v1288 = (((int)((unsigned int)((int)((unsigned int)(v1102 + 68) >> 2)) >> 1)) & 1) * 2;
    int v1122 = v1121[v1288];
    int * v1123 = v1098->cache_tags;
    int v1124 = v1123[v1288];
    int v1125 = v1121[v1275];
    int v1126 = v1123[v1275];
    bool v1290 = !(((~(((v1107 ^ ((int)((unsigned int)((int)((unsigned int)(v1102 + 68) >> 2)) >> 1))) | (-(v1107 ^ ((int)((unsigned int)((int)((unsigned int)(v1102 + 68) >> 2)) >> 1))))) >> 31)) | (~(((v1108 ^ ((int)((unsigned int)((int)((unsigned int)(v1102 + 68) >> 2)) >> 1))) | (-(v1108 ^ ((int)((unsigned int)((int)((unsigned int)(v1102 + 68) >> 2)) >> 1))))) >> 31))) == 0);
    int v1180;
    if (v1290) {
      int * v1127 = v1098->cache_age;
      int v1292 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v1102 + 68) >> 2)) >> 1)) & 3) * 2)) + ((~(((v1108 ^ ((int)((unsigned int)((int)((unsigned int)(v1102 + 68) >> 2)) >> 1))) | (-(v1108 ^ ((int)((unsigned int)((int)((unsigned int)(v1102 + 68) >> 2)) >> 1))))) >> 31)) & 1);
      int v1128 = v1127[v1292];
      int v1129 = v1127[v1276];
      int v1293 = v1129 + ((int)((unsigned int)(v1129 - v1128) >> 31));
      v1127[v1276] = v1293;
      int * v1131 = v1098->cache_age;
      int v1132 = v1131[v1277];
      int v1295 = v1132 + ((int)((unsigned int)(v1132 - v1128) >> 31));
      v1131[v1277] = v1295;
      int * v1134 = v1098->cache_age;
      v1134[v1292] = 0;
      v1180 = v1292;
    } else {
      int * v1137 = v1098->cache_age;
      int v1299 = 4 + ((((int)((unsigned int)((int)((unsigned int)(v1102 + 68) >> 2)) >> 1)) & 3) * 2);
      int v1138 = v1137[v1299];
      int * v1139 = v1098->cache_tags;
      int v1140 = v1139[v1299];
      int v1141 = v1137[v1277];
      int v1142 = v1139[v1277];
      int * v1143 = v1098->cache_dirty;
      int v1302 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v1102 + 68) >> 2)) >> 1)) & 3) * 2)) + ((((v1138 + ((~(((v1140 ^ -1) | (-(v1140 ^ -1))) >> 31)) & 2)) - (v1141 + ((~(((v1142 ^ -1) | (-(v1142 ^ -1))) >> 31)) & 2))) >> 31) & 1);
      int v1144 = v1143[v1302];
      bool v1303 = !(v1144 == 0);
      if (v1303) {
        int * v1145 = v1098->cache_tags;
        int v1146 = v1145[v1302];
        int * v1147 = v1098->cache_vals;
        int v1306 = ((4 + ((((int)((unsigned int)((int)((unsigned int)(v1102 + 68) >> 2)) >> 1)) & 3) * 2)) + ((((v1138 + ((~(((v1140 ^ -1) | (-(v1140 ^ -1))) >> 31)) & 2)) - (v1141 + ((~(((v1142 ^ -1) | (-(v1142 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
        int v1148 = v1147[v1306];
        int v1307 = (((4 + ((((int)((unsigned int)((int)((unsigned int)(v1102 + 68) >> 2)) >> 1)) & 3) * 2)) + ((((v1138 + ((~(((v1140 ^ -1) | (-(v1140 ^ -1))) >> 31)) & 2)) - (v1141 + ((~(((v1142 ^ -1) | (-(v1142 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
        int v1149 = v1147[v1307];
        int * v1150 = v1098->mem;
        int v1309 = v1146 * 2;
        v1150[v1309] = v1148;
        int * v1152 = v1098->mem;
        int v1312 = (v1146 * 2) + 1;
        v1152[v1312] = v1149;
        ;
      } else {
        ;
      }
      int * v1157 = v1098->mem;
      int v1317 = ((int)((unsigned int)((int)((unsigned int)(v1102 + 68) >> 2)) >> 1)) * 2;
      int v1158 = v1157[v1317];
      int v1318 = (((int)((unsigned int)((int)((unsigned int)(v1102 + 68) >> 2)) >> 1)) * 2) + 1;
      int v1159 = v1157[v1318];
      int * v1160 = v1098->cache_vals;
      int v1320 = ((4 + ((((int)((unsigned int)((int)((unsigned int)(v1102 + 68) >> 2)) >> 1)) & 3) * 2)) + ((((v1138 + ((~(((v1140 ^ -1) | (-(v1140 ^ -1))) >> 31)) & 2)) - (v1141 + ((~(((v1142 ^ -1) | (-(v1142 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
      v1160[v1320] = v1158;
      int * v1162 = v1098->cache_vals;
      int v1323 = (((4 + ((((int)((unsigned int)((int)((unsigned int)(v1102 + 68) >> 2)) >> 1)) & 3) * 2)) + ((((v1138 + ((~(((v1140 ^ -1) | (-(v1140 ^ -1))) >> 31)) & 2)) - (v1141 + ((~(((v1142 ^ -1) | (-(v1142 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
      v1162[v1323] = v1159;
      int * v1164 = v1098->cache_tags;
      int v1326 = (int)((unsigned int)((int)((unsigned int)(v1102 + 68) >> 2)) >> 1);
      v1164[v1302] = v1326;
      int * v1166 = v1098->cache_dirty;
      v1166[v1302] = 0;
      int * v1168 = v1098->cache_age;
      v1168[v1302] = 1;
      int * v1170 = v1098->cache_age;
      int v1171 = v1170[v1302];
      int v1172 = v1170[v1276];
      int v1332 = v1172 + ((int)((unsigned int)(v1172 - v1171) >> 31));
      v1170[v1276] = v1332;
      int * v1174 = v1098->cache_age;
      int v1175 = v1174[v1277];
      int v1334 = v1175 + ((int)((unsigned int)(v1175 - v1171) >> 31));
      v1174[v1277] = v1334;
      int * v1177 = v1098->cache_age;
      v1177[v1302] = 0;
      v1180 = v1302;
    }
    int * v1181 = v1098->cache_vals;
    int v1337 = v1180 * 2;
    int v1182 = v1181[v1337];
    int v1338 = (v1180 * 2) + 1;
    int v1183 = v1181[v1338];
    int v1339 = (((((int)((unsigned int)((int)((unsigned int)(v1102 + 68) >> 2)) >> 1)) & 1) * 2) + ((((v1122 + ((~(((v1124 ^ -1) | (-(v1124 ^ -1))) >> 31)) & 2)) - (v1125 + ((~(((v1126 ^ -1) | (-(v1126 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
    v1181[v1339] = v1182;
    int * v1185 = v1098->cache_vals;
    int v1342 = ((((((int)((unsigned int)((int)((unsigned int)(v1102 + 68) >> 2)) >> 1)) & 1) * 2) + ((((v1122 + ((~(((v1124 ^ -1) | (-(v1124 ^ -1))) >> 31)) & 2)) - (v1125 + ((~(((v1126 ^ -1) | (-(v1126 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
    v1185[v1342] = v1183;
    int * v1187 = v1098->cache_tags;
    int v1345 = ((((int)((unsigned int)((int)((unsigned int)(v1102 + 68) >> 2)) >> 1)) & 1) * 2) + ((((v1122 + ((~(((v1124 ^ -1) | (-(v1124 ^ -1))) >> 31)) & 2)) - (v1125 + ((~(((v1126 ^ -1) | (-(v1126 ^ -1))) >> 31)) & 2))) >> 31) & 1);
    int v1346 = (int)((unsigned int)((int)((unsigned int)(v1102 + 68) >> 2)) >> 1);
    v1187[v1345] = v1346;
    int * v1189 = v1098->cache_dirty;
    v1189[v1345] = 0;
    int * v1191 = v1098->cache_age;
    v1191[v1345] = 1;
    int * v1193 = v1098->cache_age;
    int v1194 = v1193[v1345];
    int v1195 = v1193[v1274];
    int v1352 = v1195 + ((int)((unsigned int)(v1195 - v1194) >> 31));
    v1193[v1274] = v1352;
    int * v1197 = v1098->cache_age;
    int v1198 = v1197[v1275];
    int v1354 = v1198 + ((int)((unsigned int)(v1198 - v1194) >> 31));
    v1197[v1275] = v1354;
    int * v1200 = v1098->cache_age;
    v1200[v1345] = 0;
    v1203 = v1345;
  }
  int * v1204 = v1098->cache_vals;
  int v1357 = (v1203 * 2) + (((int)((unsigned int)(v1102 + 68) >> 2)) & 1);
  v1204[v1357] = v1103;
  int * v1206 = v1098->cache_tags;
  int v1207 = v1206[v1276];
  int v1208 = v1206[v1277];
  bool v1360 = !(((~(((v1207 ^ ((int)((unsigned int)((int)((unsigned int)(v1102 + 68) >> 2)) >> 1))) | (-(v1207 ^ ((int)((unsigned int)((int)((unsigned int)(v1102 + 68) >> 2)) >> 1))))) >> 31)) | (~(((v1208 ^ ((int)((unsigned int)((int)((unsigned int)(v1102 + 68) >> 2)) >> 1))) | (-(v1208 ^ ((int)((unsigned int)((int)((unsigned int)(v1102 + 68) >> 2)) >> 1))))) >> 31))) == 0);
  int v1262;
  if (v1360) {
    int * v1209 = v1098->cache_age;
    int v1362 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v1102 + 68) >> 2)) >> 1)) & 3) * 2)) + ((~(((v1208 ^ ((int)((unsigned int)((int)((unsigned int)(v1102 + 68) >> 2)) >> 1))) | (-(v1208 ^ ((int)((unsigned int)((int)((unsigned int)(v1102 + 68) >> 2)) >> 1))))) >> 31)) & 1);
    int v1210 = v1209[v1362];
    int v1211 = v1209[v1276];
    int v1363 = v1211 + ((int)((unsigned int)(v1211 - v1210) >> 31));
    v1209[v1276] = v1363;
    int * v1213 = v1098->cache_age;
    int v1214 = v1213[v1277];
    int v1365 = v1214 + ((int)((unsigned int)(v1214 - v1210) >> 31));
    v1213[v1277] = v1365;
    int * v1216 = v1098->cache_age;
    v1216[v1362] = 0;
    v1262 = v1362;
  } else {
    int * v1219 = v1098->cache_age;
    int v1369 = 4 + ((((int)((unsigned int)((int)((unsigned int)(v1102 + 68) >> 2)) >> 1)) & 3) * 2);
    int v1220 = v1219[v1369];
    int * v1221 = v1098->cache_tags;
    int v1222 = v1221[v1369];
    int v1223 = v1219[v1277];
    int v1224 = v1221[v1277];
    int * v1225 = v1098->cache_dirty;
    int v1372 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v1102 + 68) >> 2)) >> 1)) & 3) * 2)) + ((((v1220 + ((~(((v1222 ^ -1) | (-(v1222 ^ -1))) >> 31)) & 2)) - (v1223 + ((~(((v1224 ^ -1) | (-(v1224 ^ -1))) >> 31)) & 2))) >> 31) & 1);
    int v1226 = v1225[v1372];
    bool v1373 = !(v1226 == 0);
    if (v1373) {
      int * v1227 = v1098->cache_tags;
      int v1228 = v1227[v1372];
      int * v1229 = v1098->cache_vals;
      int v1376 = ((4 + ((((int)((unsigned int)((int)((unsigned int)(v1102 + 68) >> 2)) >> 1)) & 3) * 2)) + ((((v1220 + ((~(((v1222 ^ -1) | (-(v1222 ^ -1))) >> 31)) & 2)) - (v1223 + ((~(((v1224 ^ -1) | (-(v1224 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
      int v1230 = v1229[v1376];
      int v1377 = (((4 + ((((int)((unsigned int)((int)((unsigned int)(v1102 + 68) >> 2)) >> 1)) & 3) * 2)) + ((((v1220 + ((~(((v1222 ^ -1) | (-(v1222 ^ -1))) >> 31)) & 2)) - (v1223 + ((~(((v1224 ^ -1) | (-(v1224 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
      int v1231 = v1229[v1377];
      int * v1232 = v1098->mem;
      int v1379 = v1228 * 2;
      v1232[v1379] = v1230;
      int * v1234 = v1098->mem;
      int v1382 = (v1228 * 2) + 1;
      v1234[v1382] = v1231;
      ;
    } else {
      ;
    }
    int * v1239 = v1098->mem;
    int v1387 = ((int)((unsigned int)((int)((unsigned int)(v1102 + 68) >> 2)) >> 1)) * 2;
    int v1240 = v1239[v1387];
    int v1388 = (((int)((unsigned int)((int)((unsigned int)(v1102 + 68) >> 2)) >> 1)) * 2) + 1;
    int v1241 = v1239[v1388];
    int * v1242 = v1098->cache_vals;
    int v1390 = ((4 + ((((int)((unsigned int)((int)((unsigned int)(v1102 + 68) >> 2)) >> 1)) & 3) * 2)) + ((((v1220 + ((~(((v1222 ^ -1) | (-(v1222 ^ -1))) >> 31)) & 2)) - (v1223 + ((~(((v1224 ^ -1) | (-(v1224 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
    v1242[v1390] = v1240;
    int * v1244 = v1098->cache_vals;
    int v1393 = (((4 + ((((int)((unsigned int)((int)((unsigned int)(v1102 + 68) >> 2)) >> 1)) & 3) * 2)) + ((((v1220 + ((~(((v1222 ^ -1) | (-(v1222 ^ -1))) >> 31)) & 2)) - (v1223 + ((~(((v1224 ^ -1) | (-(v1224 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
    v1244[v1393] = v1241;
    int * v1246 = v1098->cache_tags;
    int v1396 = (int)((unsigned int)((int)((unsigned int)(v1102 + 68) >> 2)) >> 1);
    v1246[v1372] = v1396;
    int * v1248 = v1098->cache_dirty;
    v1248[v1372] = 0;
    int * v1250 = v1098->cache_age;
    v1250[v1372] = 1;
    int * v1252 = v1098->cache_age;
    int v1253 = v1252[v1372];
    int v1254 = v1252[v1276];
    int v1402 = v1254 + ((int)((unsigned int)(v1254 - v1253) >> 31));
    v1252[v1276] = v1402;
    int * v1256 = v1098->cache_age;
    int v1257 = v1256[v1277];
    int v1404 = v1257 + ((int)((unsigned int)(v1257 - v1253) >> 31));
    v1256[v1277] = v1404;
    int * v1259 = v1098->cache_age;
    v1259[v1372] = 0;
    v1262 = v1372;
  }
  int * v1263 = v1098->cache_vals;
  int v1407 = (v1262 * 2) + (((int)((unsigned int)(v1102 + 68) >> 2)) & 1);
  v1263[v1407] = v1103;
  int * v1265 = v1098->cache_dirty;
  v1265[v1262] = 1;
  struct StateT * v1267 = slot_9(v1098);
  return v1267;
}

struct StateT * slot_16(struct StateT * v594) {
  int v595 = v594->timer;
  int v601 = v595 + 1;
  v594->timer = v601;
  int * v597 = v594->regs;
  v597[12] = 0;
  struct StateT * v599 = slot_18(v594);
  return v599;
}

struct StateT * slot_23(struct StateT * v878) {
  int v879 = v878->timer;
  int v989 = v879 + 1;
  v878->timer = v989;
  int * v881 = v878->regs;
  int v882 = v881[12];
  int * v883 = v878->cache_tags;
  int v993 = (((int)((unsigned int)((int)((unsigned int)(v882 + 68) >> 2)) >> 1)) & 1) * 2;
  int v884 = v883[v993];
  int v994 = ((((int)((unsigned int)((int)((unsigned int)(v882 + 68) >> 2)) >> 1)) & 1) * 2) + 1;
  int v885 = v883[v994];
  int v995 = 4 + ((((int)((unsigned int)((int)((unsigned int)(v882 + 68) >> 2)) >> 1)) & 3) * 2);
  int v886 = v883[v995];
  int v996 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v882 + 68) >> 2)) >> 1)) & 3) * 2)) + 1;
  int v887 = v883[v996];
  int v888 = v878->timer;
  int v997 = v888 + ((100 ^ (((~(((v886 ^ ((int)((unsigned int)((int)((unsigned int)(v882 + 68) >> 2)) >> 1))) | (-(v886 ^ ((int)((unsigned int)((int)((unsigned int)(v882 + 68) >> 2)) >> 1))))) >> 31)) | (~(((v887 ^ ((int)((unsigned int)((int)((unsigned int)(v882 + 68) >> 2)) >> 1))) | (-(v887 ^ ((int)((unsigned int)((int)((unsigned int)(v882 + 68) >> 2)) >> 1))))) >> 31))) & 104)) ^ (((~(((v884 ^ ((int)((unsigned int)((int)((unsigned int)(v882 + 68) >> 2)) >> 1))) | (-(v884 ^ ((int)((unsigned int)((int)((unsigned int)(v882 + 68) >> 2)) >> 1))))) >> 31)) | (~(((v885 ^ ((int)((unsigned int)((int)((unsigned int)(v882 + 68) >> 2)) >> 1))) | (-(v885 ^ ((int)((unsigned int)((int)((unsigned int)(v882 + 68) >> 2)) >> 1))))) >> 31))) & (1 ^ (100 ^ (((~(((v886 ^ ((int)((unsigned int)((int)((unsigned int)(v882 + 68) >> 2)) >> 1))) | (-(v886 ^ ((int)((unsigned int)((int)((unsigned int)(v882 + 68) >> 2)) >> 1))))) >> 31)) | (~(((v887 ^ ((int)((unsigned int)((int)((unsigned int)(v882 + 68) >> 2)) >> 1))) | (-(v887 ^ ((int)((unsigned int)((int)((unsigned int)(v882 + 68) >> 2)) >> 1))))) >> 31))) & 104)))));
  v878->timer = v997;
  int * v890 = v878->cache_vals;
  bool v998 = !(((~(((v884 ^ ((int)((unsigned int)((int)((unsigned int)(v882 + 68) >> 2)) >> 1))) | (-(v884 ^ ((int)((unsigned int)((int)((unsigned int)(v882 + 68) >> 2)) >> 1))))) >> 31)) | (~(((v885 ^ ((int)((unsigned int)((int)((unsigned int)(v882 + 68) >> 2)) >> 1))) | (-(v885 ^ ((int)((unsigned int)((int)((unsigned int)(v882 + 68) >> 2)) >> 1))))) >> 31))) == 0);
  int v983;
  if (v998) {
    int * v891 = v878->cache_age;
    int v1000 = ((((int)((unsigned int)((int)((unsigned int)(v882 + 68) >> 2)) >> 1)) & 1) * 2) + ((~(((v885 ^ ((int)((unsigned int)((int)((unsigned int)(v882 + 68) >> 2)) >> 1))) | (-(v885 ^ ((int)((unsigned int)((int)((unsigned int)(v882 + 68) >> 2)) >> 1))))) >> 31)) & 1);
    int v892 = v891[v1000];
    int v893 = v891[v993];
    int v1001 = v893 + ((int)((unsigned int)(v893 - v892) >> 31));
    v891[v993] = v1001;
    int * v895 = v878->cache_age;
    int v896 = v895[v994];
    int v1003 = v896 + ((int)((unsigned int)(v896 - v892) >> 31));
    v895[v994] = v1003;
    int * v898 = v878->cache_age;
    v898[v1000] = 0;
    v983 = v1000;
  } else {
    int * v901 = v878->cache_age;
    int v1007 = (((int)((unsigned int)((int)((unsigned int)(v882 + 68) >> 2)) >> 1)) & 1) * 2;
    int v902 = v901[v1007];
    int * v903 = v878->cache_tags;
    int v904 = v903[v1007];
    int v905 = v901[v994];
    int v906 = v903[v994];
    bool v1009 = !(((~(((v886 ^ ((int)((unsigned int)((int)((unsigned int)(v882 + 68) >> 2)) >> 1))) | (-(v886 ^ ((int)((unsigned int)((int)((unsigned int)(v882 + 68) >> 2)) >> 1))))) >> 31)) | (~(((v887 ^ ((int)((unsigned int)((int)((unsigned int)(v882 + 68) >> 2)) >> 1))) | (-(v887 ^ ((int)((unsigned int)((int)((unsigned int)(v882 + 68) >> 2)) >> 1))))) >> 31))) == 0);
    int v960;
    if (v1009) {
      int * v907 = v878->cache_age;
      int v1011 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v882 + 68) >> 2)) >> 1)) & 3) * 2)) + ((~(((v887 ^ ((int)((unsigned int)((int)((unsigned int)(v882 + 68) >> 2)) >> 1))) | (-(v887 ^ ((int)((unsigned int)((int)((unsigned int)(v882 + 68) >> 2)) >> 1))))) >> 31)) & 1);
      int v908 = v907[v1011];
      int v909 = v907[v995];
      int v1012 = v909 + ((int)((unsigned int)(v909 - v908) >> 31));
      v907[v995] = v1012;
      int * v911 = v878->cache_age;
      int v912 = v911[v996];
      int v1014 = v912 + ((int)((unsigned int)(v912 - v908) >> 31));
      v911[v996] = v1014;
      int * v914 = v878->cache_age;
      v914[v1011] = 0;
      v960 = v1011;
    } else {
      int * v917 = v878->cache_age;
      int v1018 = 4 + ((((int)((unsigned int)((int)((unsigned int)(v882 + 68) >> 2)) >> 1)) & 3) * 2);
      int v918 = v917[v1018];
      int * v919 = v878->cache_tags;
      int v920 = v919[v1018];
      int v921 = v917[v996];
      int v922 = v919[v996];
      int * v923 = v878->cache_dirty;
      int v1021 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v882 + 68) >> 2)) >> 1)) & 3) * 2)) + ((((v918 + ((~(((v920 ^ -1) | (-(v920 ^ -1))) >> 31)) & 2)) - (v921 + ((~(((v922 ^ -1) | (-(v922 ^ -1))) >> 31)) & 2))) >> 31) & 1);
      int v924 = v923[v1021];
      bool v1022 = !(v924 == 0);
      if (v1022) {
        int * v925 = v878->cache_tags;
        int v926 = v925[v1021];
        int * v927 = v878->cache_vals;
        int v1025 = ((4 + ((((int)((unsigned int)((int)((unsigned int)(v882 + 68) >> 2)) >> 1)) & 3) * 2)) + ((((v918 + ((~(((v920 ^ -1) | (-(v920 ^ -1))) >> 31)) & 2)) - (v921 + ((~(((v922 ^ -1) | (-(v922 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
        int v928 = v927[v1025];
        int v1026 = (((4 + ((((int)((unsigned int)((int)((unsigned int)(v882 + 68) >> 2)) >> 1)) & 3) * 2)) + ((((v918 + ((~(((v920 ^ -1) | (-(v920 ^ -1))) >> 31)) & 2)) - (v921 + ((~(((v922 ^ -1) | (-(v922 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
        int v929 = v927[v1026];
        int * v930 = v878->mem;
        int v1028 = v926 * 2;
        v930[v1028] = v928;
        int * v932 = v878->mem;
        int v1031 = (v926 * 2) + 1;
        v932[v1031] = v929;
        ;
      } else {
        ;
      }
      int * v937 = v878->mem;
      int v1036 = ((int)((unsigned int)((int)((unsigned int)(v882 + 68) >> 2)) >> 1)) * 2;
      int v938 = v937[v1036];
      int v1037 = (((int)((unsigned int)((int)((unsigned int)(v882 + 68) >> 2)) >> 1)) * 2) + 1;
      int v939 = v937[v1037];
      int * v940 = v878->cache_vals;
      int v1039 = ((4 + ((((int)((unsigned int)((int)((unsigned int)(v882 + 68) >> 2)) >> 1)) & 3) * 2)) + ((((v918 + ((~(((v920 ^ -1) | (-(v920 ^ -1))) >> 31)) & 2)) - (v921 + ((~(((v922 ^ -1) | (-(v922 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
      v940[v1039] = v938;
      int * v942 = v878->cache_vals;
      int v1042 = (((4 + ((((int)((unsigned int)((int)((unsigned int)(v882 + 68) >> 2)) >> 1)) & 3) * 2)) + ((((v918 + ((~(((v920 ^ -1) | (-(v920 ^ -1))) >> 31)) & 2)) - (v921 + ((~(((v922 ^ -1) | (-(v922 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
      v942[v1042] = v939;
      int * v944 = v878->cache_tags;
      int v1045 = (int)((unsigned int)((int)((unsigned int)(v882 + 68) >> 2)) >> 1);
      v944[v1021] = v1045;
      int * v946 = v878->cache_dirty;
      v946[v1021] = 0;
      int * v948 = v878->cache_age;
      v948[v1021] = 1;
      int * v950 = v878->cache_age;
      int v951 = v950[v1021];
      int v952 = v950[v995];
      int v1051 = v952 + ((int)((unsigned int)(v952 - v951) >> 31));
      v950[v995] = v1051;
      int * v954 = v878->cache_age;
      int v955 = v954[v996];
      int v1053 = v955 + ((int)((unsigned int)(v955 - v951) >> 31));
      v954[v996] = v1053;
      int * v957 = v878->cache_age;
      v957[v1021] = 0;
      v960 = v1021;
    }
    int * v961 = v878->cache_vals;
    int v1056 = v960 * 2;
    int v962 = v961[v1056];
    int v1057 = (v960 * 2) + 1;
    int v963 = v961[v1057];
    int v1058 = (((((int)((unsigned int)((int)((unsigned int)(v882 + 68) >> 2)) >> 1)) & 1) * 2) + ((((v902 + ((~(((v904 ^ -1) | (-(v904 ^ -1))) >> 31)) & 2)) - (v905 + ((~(((v906 ^ -1) | (-(v906 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
    v961[v1058] = v962;
    int * v965 = v878->cache_vals;
    int v1061 = ((((((int)((unsigned int)((int)((unsigned int)(v882 + 68) >> 2)) >> 1)) & 1) * 2) + ((((v902 + ((~(((v904 ^ -1) | (-(v904 ^ -1))) >> 31)) & 2)) - (v905 + ((~(((v906 ^ -1) | (-(v906 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
    v965[v1061] = v963;
    int * v967 = v878->cache_tags;
    int v1064 = ((((int)((unsigned int)((int)((unsigned int)(v882 + 68) >> 2)) >> 1)) & 1) * 2) + ((((v902 + ((~(((v904 ^ -1) | (-(v904 ^ -1))) >> 31)) & 2)) - (v905 + ((~(((v906 ^ -1) | (-(v906 ^ -1))) >> 31)) & 2))) >> 31) & 1);
    int v1065 = (int)((unsigned int)((int)((unsigned int)(v882 + 68) >> 2)) >> 1);
    v967[v1064] = v1065;
    int * v969 = v878->cache_dirty;
    v969[v1064] = 0;
    int * v971 = v878->cache_age;
    v971[v1064] = 1;
    int * v973 = v878->cache_age;
    int v974 = v973[v1064];
    int v975 = v973[v993];
    int v1071 = v975 + ((int)((unsigned int)(v975 - v974) >> 31));
    v973[v993] = v1071;
    int * v977 = v878->cache_age;
    int v978 = v977[v994];
    int v1073 = v978 + ((int)((unsigned int)(v978 - v974) >> 31));
    v977[v994] = v1073;
    int * v980 = v878->cache_age;
    v980[v1064] = 0;
    v983 = v1064;
  }
  int v1076 = (v983 * 2) + (((int)((unsigned int)(v882 + 68) >> 2)) & 1);
  int v984 = v890[v1076];
  int * v985 = v878->regs;
  v985[11] = v984;
  struct StateT * v987 = slot_24(v878);
  return v987;
}

struct StateT * slot_5(struct StateT * v274) {
  int v275 = v274->timer;
  int v279 = v275 + 1;
  v274->timer = v279;
  struct StateT * v277 = slot_7(v274);
  return v277;
}

struct StateT * slot_2(struct StateT * v30) {
  int v31 = v30->timer;
  int v141 = v31 + 1;
  v30->timer = v141;
  int * v33 = v30->regs;
  int v34 = v33[11];
  int * v35 = v30->cache_tags;
  int v145 = (((int)((unsigned int)((int)((unsigned int)v34 >> 2)) >> 1)) & 1) * 2;
  int v36 = v35[v145];
  int v146 = ((((int)((unsigned int)((int)((unsigned int)v34 >> 2)) >> 1)) & 1) * 2) + 1;
  int v37 = v35[v146];
  int v147 = 4 + ((((int)((unsigned int)((int)((unsigned int)v34 >> 2)) >> 1)) & 3) * 2);
  int v38 = v35[v147];
  int v148 = (4 + ((((int)((unsigned int)((int)((unsigned int)v34 >> 2)) >> 1)) & 3) * 2)) + 1;
  int v39 = v35[v148];
  int v40 = v30->timer;
  int v149 = v40 + ((100 ^ (((~(((v38 ^ ((int)((unsigned int)((int)((unsigned int)v34 >> 2)) >> 1))) | (-(v38 ^ ((int)((unsigned int)((int)((unsigned int)v34 >> 2)) >> 1))))) >> 31)) | (~(((v39 ^ ((int)((unsigned int)((int)((unsigned int)v34 >> 2)) >> 1))) | (-(v39 ^ ((int)((unsigned int)((int)((unsigned int)v34 >> 2)) >> 1))))) >> 31))) & 104)) ^ (((~(((v36 ^ ((int)((unsigned int)((int)((unsigned int)v34 >> 2)) >> 1))) | (-(v36 ^ ((int)((unsigned int)((int)((unsigned int)v34 >> 2)) >> 1))))) >> 31)) | (~(((v37 ^ ((int)((unsigned int)((int)((unsigned int)v34 >> 2)) >> 1))) | (-(v37 ^ ((int)((unsigned int)((int)((unsigned int)v34 >> 2)) >> 1))))) >> 31))) & (1 ^ (100 ^ (((~(((v38 ^ ((int)((unsigned int)((int)((unsigned int)v34 >> 2)) >> 1))) | (-(v38 ^ ((int)((unsigned int)((int)((unsigned int)v34 >> 2)) >> 1))))) >> 31)) | (~(((v39 ^ ((int)((unsigned int)((int)((unsigned int)v34 >> 2)) >> 1))) | (-(v39 ^ ((int)((unsigned int)((int)((unsigned int)v34 >> 2)) >> 1))))) >> 31))) & 104)))));
  v30->timer = v149;
  int * v42 = v30->cache_vals;
  bool v150 = !(((~(((v36 ^ ((int)((unsigned int)((int)((unsigned int)v34 >> 2)) >> 1))) | (-(v36 ^ ((int)((unsigned int)((int)((unsigned int)v34 >> 2)) >> 1))))) >> 31)) | (~(((v37 ^ ((int)((unsigned int)((int)((unsigned int)v34 >> 2)) >> 1))) | (-(v37 ^ ((int)((unsigned int)((int)((unsigned int)v34 >> 2)) >> 1))))) >> 31))) == 0);
  int v135;
  if (v150) {
    int * v43 = v30->cache_age;
    int v152 = ((((int)((unsigned int)((int)((unsigned int)v34 >> 2)) >> 1)) & 1) * 2) + ((~(((v37 ^ ((int)((unsigned int)((int)((unsigned int)v34 >> 2)) >> 1))) | (-(v37 ^ ((int)((unsigned int)((int)((unsigned int)v34 >> 2)) >> 1))))) >> 31)) & 1);
    int v44 = v43[v152];
    int v45 = v43[v145];
    int v153 = v45 + ((int)((unsigned int)(v45 - v44) >> 31));
    v43[v145] = v153;
    int * v47 = v30->cache_age;
    int v48 = v47[v146];
    int v155 = v48 + ((int)((unsigned int)(v48 - v44) >> 31));
    v47[v146] = v155;
    int * v50 = v30->cache_age;
    v50[v152] = 0;
    v135 = v152;
  } else {
    int * v53 = v30->cache_age;
    int v159 = (((int)((unsigned int)((int)((unsigned int)v34 >> 2)) >> 1)) & 1) * 2;
    int v54 = v53[v159];
    int * v55 = v30->cache_tags;
    int v56 = v55[v159];
    int v57 = v53[v146];
    int v58 = v55[v146];
    bool v161 = !(((~(((v38 ^ ((int)((unsigned int)((int)((unsigned int)v34 >> 2)) >> 1))) | (-(v38 ^ ((int)((unsigned int)((int)((unsigned int)v34 >> 2)) >> 1))))) >> 31)) | (~(((v39 ^ ((int)((unsigned int)((int)((unsigned int)v34 >> 2)) >> 1))) | (-(v39 ^ ((int)((unsigned int)((int)((unsigned int)v34 >> 2)) >> 1))))) >> 31))) == 0);
    int v112;
    if (v161) {
      int * v59 = v30->cache_age;
      int v163 = (4 + ((((int)((unsigned int)((int)((unsigned int)v34 >> 2)) >> 1)) & 3) * 2)) + ((~(((v39 ^ ((int)((unsigned int)((int)((unsigned int)v34 >> 2)) >> 1))) | (-(v39 ^ ((int)((unsigned int)((int)((unsigned int)v34 >> 2)) >> 1))))) >> 31)) & 1);
      int v60 = v59[v163];
      int v61 = v59[v147];
      int v164 = v61 + ((int)((unsigned int)(v61 - v60) >> 31));
      v59[v147] = v164;
      int * v63 = v30->cache_age;
      int v64 = v63[v148];
      int v166 = v64 + ((int)((unsigned int)(v64 - v60) >> 31));
      v63[v148] = v166;
      int * v66 = v30->cache_age;
      v66[v163] = 0;
      v112 = v163;
    } else {
      int * v69 = v30->cache_age;
      int v170 = 4 + ((((int)((unsigned int)((int)((unsigned int)v34 >> 2)) >> 1)) & 3) * 2);
      int v70 = v69[v170];
      int * v71 = v30->cache_tags;
      int v72 = v71[v170];
      int v73 = v69[v148];
      int v74 = v71[v148];
      int * v75 = v30->cache_dirty;
      int v173 = (4 + ((((int)((unsigned int)((int)((unsigned int)v34 >> 2)) >> 1)) & 3) * 2)) + ((((v70 + ((~(((v72 ^ -1) | (-(v72 ^ -1))) >> 31)) & 2)) - (v73 + ((~(((v74 ^ -1) | (-(v74 ^ -1))) >> 31)) & 2))) >> 31) & 1);
      int v76 = v75[v173];
      bool v174 = !(v76 == 0);
      if (v174) {
        int * v77 = v30->cache_tags;
        int v78 = v77[v173];
        int * v79 = v30->cache_vals;
        int v177 = ((4 + ((((int)((unsigned int)((int)((unsigned int)v34 >> 2)) >> 1)) & 3) * 2)) + ((((v70 + ((~(((v72 ^ -1) | (-(v72 ^ -1))) >> 31)) & 2)) - (v73 + ((~(((v74 ^ -1) | (-(v74 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
        int v80 = v79[v177];
        int v178 = (((4 + ((((int)((unsigned int)((int)((unsigned int)v34 >> 2)) >> 1)) & 3) * 2)) + ((((v70 + ((~(((v72 ^ -1) | (-(v72 ^ -1))) >> 31)) & 2)) - (v73 + ((~(((v74 ^ -1) | (-(v74 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
        int v81 = v79[v178];
        int * v82 = v30->mem;
        int v180 = v78 * 2;
        v82[v180] = v80;
        int * v84 = v30->mem;
        int v183 = (v78 * 2) + 1;
        v84[v183] = v81;
        ;
      } else {
        ;
      }
      int * v89 = v30->mem;
      int v188 = ((int)((unsigned int)((int)((unsigned int)v34 >> 2)) >> 1)) * 2;
      int v90 = v89[v188];
      int v189 = (((int)((unsigned int)((int)((unsigned int)v34 >> 2)) >> 1)) * 2) + 1;
      int v91 = v89[v189];
      int * v92 = v30->cache_vals;
      int v191 = ((4 + ((((int)((unsigned int)((int)((unsigned int)v34 >> 2)) >> 1)) & 3) * 2)) + ((((v70 + ((~(((v72 ^ -1) | (-(v72 ^ -1))) >> 31)) & 2)) - (v73 + ((~(((v74 ^ -1) | (-(v74 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
      v92[v191] = v90;
      int * v94 = v30->cache_vals;
      int v194 = (((4 + ((((int)((unsigned int)((int)((unsigned int)v34 >> 2)) >> 1)) & 3) * 2)) + ((((v70 + ((~(((v72 ^ -1) | (-(v72 ^ -1))) >> 31)) & 2)) - (v73 + ((~(((v74 ^ -1) | (-(v74 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
      v94[v194] = v91;
      int * v96 = v30->cache_tags;
      int v197 = (int)((unsigned int)((int)((unsigned int)v34 >> 2)) >> 1);
      v96[v173] = v197;
      int * v98 = v30->cache_dirty;
      v98[v173] = 0;
      int * v100 = v30->cache_age;
      v100[v173] = 1;
      int * v102 = v30->cache_age;
      int v103 = v102[v173];
      int v104 = v102[v147];
      int v203 = v104 + ((int)((unsigned int)(v104 - v103) >> 31));
      v102[v147] = v203;
      int * v106 = v30->cache_age;
      int v107 = v106[v148];
      int v205 = v107 + ((int)((unsigned int)(v107 - v103) >> 31));
      v106[v148] = v205;
      int * v109 = v30->cache_age;
      v109[v173] = 0;
      v112 = v173;
    }
    int * v113 = v30->cache_vals;
    int v208 = v112 * 2;
    int v114 = v113[v208];
    int v209 = (v112 * 2) + 1;
    int v115 = v113[v209];
    int v210 = (((((int)((unsigned int)((int)((unsigned int)v34 >> 2)) >> 1)) & 1) * 2) + ((((v54 + ((~(((v56 ^ -1) | (-(v56 ^ -1))) >> 31)) & 2)) - (v57 + ((~(((v58 ^ -1) | (-(v58 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
    v113[v210] = v114;
    int * v117 = v30->cache_vals;
    int v213 = ((((((int)((unsigned int)((int)((unsigned int)v34 >> 2)) >> 1)) & 1) * 2) + ((((v54 + ((~(((v56 ^ -1) | (-(v56 ^ -1))) >> 31)) & 2)) - (v57 + ((~(((v58 ^ -1) | (-(v58 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
    v117[v213] = v115;
    int * v119 = v30->cache_tags;
    int v216 = ((((int)((unsigned int)((int)((unsigned int)v34 >> 2)) >> 1)) & 1) * 2) + ((((v54 + ((~(((v56 ^ -1) | (-(v56 ^ -1))) >> 31)) & 2)) - (v57 + ((~(((v58 ^ -1) | (-(v58 ^ -1))) >> 31)) & 2))) >> 31) & 1);
    int v217 = (int)((unsigned int)((int)((unsigned int)v34 >> 2)) >> 1);
    v119[v216] = v217;
    int * v121 = v30->cache_dirty;
    v121[v216] = 0;
    int * v123 = v30->cache_age;
    v123[v216] = 1;
    int * v125 = v30->cache_age;
    int v126 = v125[v216];
    int v127 = v125[v145];
    int v223 = v127 + ((int)((unsigned int)(v127 - v126) >> 31));
    v125[v145] = v223;
    int * v129 = v30->cache_age;
    int v130 = v129[v146];
    int v225 = v130 + ((int)((unsigned int)(v130 - v126) >> 31));
    v129[v146] = v225;
    int * v132 = v30->cache_age;
    v132[v216] = 0;
    v135 = v216;
  }
  int v228 = (v135 * 2) + (((int)((unsigned int)v34 >> 2)) & 1);
  int v136 = v42[v228];
  int * v137 = v30->regs;
  v137[11] = v136;
  struct StateT * v139 = slot_3(v30);
  return v139;
}

struct StateT * slot_7(struct StateT * v296) {
  int * v297 = v296->regs;
  int v298 = v297[10];
  int v299 = v297[11];
  bool v311 = (v298 ^ -2147483648) >= (v299 ^ -2147483648);
  struct StateT * v306;
  if (v311) {
    int v300 = v296->timer;
    int v312 = v300 + 15;
    v296->timer = v312;
    struct StateT * v302 = slot_9(v296);
    v306 = v302;
  } else {
    struct StateT * v304 = slot_10(v296);
    v306 = v304;
  }
  return v306;
}

struct StateT * slot_21(struct StateT * v659) {
  int v660 = v659->timer;
  int v668 = v660 + 1;
  v659->timer = v668;
  int * v662 = v659->regs;
  int v663 = v662[11];
  int v664 = v662[10];
  int v672 = v663 + v664;
  v662[10] = v672;
  struct StateT * v666 = slot_22(v659);
  return v666;
}

struct StateT * slot_3(struct StateT * v233) {
  int * v234 = v233->regs;
  int v235 = v234[10];
  bool v250 = v235 == 0;
  struct StateT * v246;
  if (v250) {
    int v236 = v233->timer;
    int v251 = v236 + 15;
    v233->timer = v251;
    int * v238 = v233->saved_regs;
    int v239 = v238[11];
    int * v240 = v233->regs;
    v240[11] = v239;
    struct StateT * v242 = slot_4(v233);
    v246 = v242;
  } else {
    struct StateT * v244 = slot_5(v233);
    v246 = v244;
  }
  return v246;
}

struct StateT * slot_10(struct StateT * v526) {
  int v527 = v526->timer;
  int v534 = v527 + 1;
  v526->timer = v534;
  int * v529 = v526->regs;
  int v530 = v529[10];
  int v537 = v530 << 2;
  v529[10] = v537;
  struct StateT * v532 = slot_13(v526);
  return v532;
}

struct StateT * slot_1(struct StateT * v10) {
  int * v11 = v10->saved_regs;
  int * v12 = v10->regs;
  int v13 = v12[11];
  v11[11] = v13;
  int v15 = v10->timer;
  int v25 = v15 + 1;
  v10->timer = v25;
  int * v17 = v10->regs;
  v17[11] = 0;
  struct StateT * v19 = slot_2(v10);
  return v19;
}

struct StateT * slot_19(struct StateT * v637) {
  int v638 = v637->timer;
  int v642 = v638 + 1;
  v637->timer = v642;
  struct StateT * v640 = slot_8(v637);
  return v640;
}

struct StateT * slot_13(struct StateT * v553) {
  int v554 = v553->timer;
  int v560 = v554 + 1;
  v553->timer = v560;
  int * v556 = v553->regs;
  v556[11] = 0;
  struct StateT * v558 = slot_15(v553);
  return v558;
}

struct StateT * slot_24(struct StateT * v1082) {
  int v1083 = v1082->timer;
  int v1091 = v1083 + 1;
  v1082->timer = v1091;
  int * v1085 = v1082->regs;
  int v1086 = v1085[11];
  int v1087 = v1085[10];
  int v1095 = v1086 & v1087;
  v1085[10] = v1095;
  struct StateT * v1089 = slot_25(v1082);
  return v1089;
}

struct StateT * slot_0(struct StateT * v2) {
  int v3 = v2->timer;
  int v7 = v3 + 1;
  v2->timer = v7;
  struct StateT * v5 = slot_1(v2);
  return v5;
}

struct StateT * slot_14(struct StateT * v566) {
  int v567 = v566->timer;
  int v574 = v567 + 1;
  v566->timer = v574;
  int * v569 = v566->regs;
  int v570 = v569[11];
  int v577 = v570 + 4;
  v569[11] = v577;
  struct StateT * v572 = slot_16(v566);
  return v572;
}

struct StateT * slot_17(struct StateT * v607) {
  int v608 = v607->timer;
  int v616 = v608 + 1;
  v607->timer = v616;
  int * v610 = v607->regs;
  int v611 = v610[11];
  int v612 = v610[10];
  int v620 = v611 + v612;
  v610[10] = v620;
  struct StateT * v614 = slot_19(v607);
  return v614;
}

struct StateT * slot_20(struct StateT * v645) {
  int v646 = v645->timer;
  int v653 = v646 + 1;
  v645->timer = v653;
  int * v648 = v645->regs;
  int v649 = v648[10];
  int v656 = (int)((unsigned int)v649 >> 26);
  v648[10] = v656;
  struct StateT * v651 = slot_21(v645);
  return v651;
}

struct StateT * snippet(struct StateT * v0) {
  struct StateT * v1 = slot_0(v0);
  return v1;
}

struct StateT * slot_8(struct StateT * v318) {
  int v319 = v318->timer;
  int v429 = v319 + 1;
  v318->timer = v429;
  int * v321 = v318->regs;
  int v322 = v321[10];
  int * v323 = v318->cache_tags;
  int v433 = (((int)((unsigned int)((int)((unsigned int)v322 >> 2)) >> 1)) & 1) * 2;
  int v324 = v323[v433];
  int v434 = ((((int)((unsigned int)((int)((unsigned int)v322 >> 2)) >> 1)) & 1) * 2) + 1;
  int v325 = v323[v434];
  int v435 = 4 + ((((int)((unsigned int)((int)((unsigned int)v322 >> 2)) >> 1)) & 3) * 2);
  int v326 = v323[v435];
  int v436 = (4 + ((((int)((unsigned int)((int)((unsigned int)v322 >> 2)) >> 1)) & 3) * 2)) + 1;
  int v327 = v323[v436];
  int v328 = v318->timer;
  int v437 = v328 + ((100 ^ (((~(((v326 ^ ((int)((unsigned int)((int)((unsigned int)v322 >> 2)) >> 1))) | (-(v326 ^ ((int)((unsigned int)((int)((unsigned int)v322 >> 2)) >> 1))))) >> 31)) | (~(((v327 ^ ((int)((unsigned int)((int)((unsigned int)v322 >> 2)) >> 1))) | (-(v327 ^ ((int)((unsigned int)((int)((unsigned int)v322 >> 2)) >> 1))))) >> 31))) & 104)) ^ (((~(((v324 ^ ((int)((unsigned int)((int)((unsigned int)v322 >> 2)) >> 1))) | (-(v324 ^ ((int)((unsigned int)((int)((unsigned int)v322 >> 2)) >> 1))))) >> 31)) | (~(((v325 ^ ((int)((unsigned int)((int)((unsigned int)v322 >> 2)) >> 1))) | (-(v325 ^ ((int)((unsigned int)((int)((unsigned int)v322 >> 2)) >> 1))))) >> 31))) & (1 ^ (100 ^ (((~(((v326 ^ ((int)((unsigned int)((int)((unsigned int)v322 >> 2)) >> 1))) | (-(v326 ^ ((int)((unsigned int)((int)((unsigned int)v322 >> 2)) >> 1))))) >> 31)) | (~(((v327 ^ ((int)((unsigned int)((int)((unsigned int)v322 >> 2)) >> 1))) | (-(v327 ^ ((int)((unsigned int)((int)((unsigned int)v322 >> 2)) >> 1))))) >> 31))) & 104)))));
  v318->timer = v437;
  int * v330 = v318->cache_vals;
  bool v438 = !(((~(((v324 ^ ((int)((unsigned int)((int)((unsigned int)v322 >> 2)) >> 1))) | (-(v324 ^ ((int)((unsigned int)((int)((unsigned int)v322 >> 2)) >> 1))))) >> 31)) | (~(((v325 ^ ((int)((unsigned int)((int)((unsigned int)v322 >> 2)) >> 1))) | (-(v325 ^ ((int)((unsigned int)((int)((unsigned int)v322 >> 2)) >> 1))))) >> 31))) == 0);
  int v423;
  if (v438) {
    int * v331 = v318->cache_age;
    int v440 = ((((int)((unsigned int)((int)((unsigned int)v322 >> 2)) >> 1)) & 1) * 2) + ((~(((v325 ^ ((int)((unsigned int)((int)((unsigned int)v322 >> 2)) >> 1))) | (-(v325 ^ ((int)((unsigned int)((int)((unsigned int)v322 >> 2)) >> 1))))) >> 31)) & 1);
    int v332 = v331[v440];
    int v333 = v331[v433];
    int v441 = v333 + ((int)((unsigned int)(v333 - v332) >> 31));
    v331[v433] = v441;
    int * v335 = v318->cache_age;
    int v336 = v335[v434];
    int v443 = v336 + ((int)((unsigned int)(v336 - v332) >> 31));
    v335[v434] = v443;
    int * v338 = v318->cache_age;
    v338[v440] = 0;
    v423 = v440;
  } else {
    int * v341 = v318->cache_age;
    int v447 = (((int)((unsigned int)((int)((unsigned int)v322 >> 2)) >> 1)) & 1) * 2;
    int v342 = v341[v447];
    int * v343 = v318->cache_tags;
    int v344 = v343[v447];
    int v345 = v341[v434];
    int v346 = v343[v434];
    bool v449 = !(((~(((v326 ^ ((int)((unsigned int)((int)((unsigned int)v322 >> 2)) >> 1))) | (-(v326 ^ ((int)((unsigned int)((int)((unsigned int)v322 >> 2)) >> 1))))) >> 31)) | (~(((v327 ^ ((int)((unsigned int)((int)((unsigned int)v322 >> 2)) >> 1))) | (-(v327 ^ ((int)((unsigned int)((int)((unsigned int)v322 >> 2)) >> 1))))) >> 31))) == 0);
    int v400;
    if (v449) {
      int * v347 = v318->cache_age;
      int v451 = (4 + ((((int)((unsigned int)((int)((unsigned int)v322 >> 2)) >> 1)) & 3) * 2)) + ((~(((v327 ^ ((int)((unsigned int)((int)((unsigned int)v322 >> 2)) >> 1))) | (-(v327 ^ ((int)((unsigned int)((int)((unsigned int)v322 >> 2)) >> 1))))) >> 31)) & 1);
      int v348 = v347[v451];
      int v349 = v347[v435];
      int v452 = v349 + ((int)((unsigned int)(v349 - v348) >> 31));
      v347[v435] = v452;
      int * v351 = v318->cache_age;
      int v352 = v351[v436];
      int v454 = v352 + ((int)((unsigned int)(v352 - v348) >> 31));
      v351[v436] = v454;
      int * v354 = v318->cache_age;
      v354[v451] = 0;
      v400 = v451;
    } else {
      int * v357 = v318->cache_age;
      int v458 = 4 + ((((int)((unsigned int)((int)((unsigned int)v322 >> 2)) >> 1)) & 3) * 2);
      int v358 = v357[v458];
      int * v359 = v318->cache_tags;
      int v360 = v359[v458];
      int v361 = v357[v436];
      int v362 = v359[v436];
      int * v363 = v318->cache_dirty;
      int v461 = (4 + ((((int)((unsigned int)((int)((unsigned int)v322 >> 2)) >> 1)) & 3) * 2)) + ((((v358 + ((~(((v360 ^ -1) | (-(v360 ^ -1))) >> 31)) & 2)) - (v361 + ((~(((v362 ^ -1) | (-(v362 ^ -1))) >> 31)) & 2))) >> 31) & 1);
      int v364 = v363[v461];
      bool v462 = !(v364 == 0);
      if (v462) {
        int * v365 = v318->cache_tags;
        int v366 = v365[v461];
        int * v367 = v318->cache_vals;
        int v465 = ((4 + ((((int)((unsigned int)((int)((unsigned int)v322 >> 2)) >> 1)) & 3) * 2)) + ((((v358 + ((~(((v360 ^ -1) | (-(v360 ^ -1))) >> 31)) & 2)) - (v361 + ((~(((v362 ^ -1) | (-(v362 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
        int v368 = v367[v465];
        int v466 = (((4 + ((((int)((unsigned int)((int)((unsigned int)v322 >> 2)) >> 1)) & 3) * 2)) + ((((v358 + ((~(((v360 ^ -1) | (-(v360 ^ -1))) >> 31)) & 2)) - (v361 + ((~(((v362 ^ -1) | (-(v362 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
        int v369 = v367[v466];
        int * v370 = v318->mem;
        int v468 = v366 * 2;
        v370[v468] = v368;
        int * v372 = v318->mem;
        int v471 = (v366 * 2) + 1;
        v372[v471] = v369;
        ;
      } else {
        ;
      }
      int * v377 = v318->mem;
      int v476 = ((int)((unsigned int)((int)((unsigned int)v322 >> 2)) >> 1)) * 2;
      int v378 = v377[v476];
      int v477 = (((int)((unsigned int)((int)((unsigned int)v322 >> 2)) >> 1)) * 2) + 1;
      int v379 = v377[v477];
      int * v380 = v318->cache_vals;
      int v479 = ((4 + ((((int)((unsigned int)((int)((unsigned int)v322 >> 2)) >> 1)) & 3) * 2)) + ((((v358 + ((~(((v360 ^ -1) | (-(v360 ^ -1))) >> 31)) & 2)) - (v361 + ((~(((v362 ^ -1) | (-(v362 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
      v380[v479] = v378;
      int * v382 = v318->cache_vals;
      int v482 = (((4 + ((((int)((unsigned int)((int)((unsigned int)v322 >> 2)) >> 1)) & 3) * 2)) + ((((v358 + ((~(((v360 ^ -1) | (-(v360 ^ -1))) >> 31)) & 2)) - (v361 + ((~(((v362 ^ -1) | (-(v362 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
      v382[v482] = v379;
      int * v384 = v318->cache_tags;
      int v485 = (int)((unsigned int)((int)((unsigned int)v322 >> 2)) >> 1);
      v384[v461] = v485;
      int * v386 = v318->cache_dirty;
      v386[v461] = 0;
      int * v388 = v318->cache_age;
      v388[v461] = 1;
      int * v390 = v318->cache_age;
      int v391 = v390[v461];
      int v392 = v390[v435];
      int v491 = v392 + ((int)((unsigned int)(v392 - v391) >> 31));
      v390[v435] = v491;
      int * v394 = v318->cache_age;
      int v395 = v394[v436];
      int v493 = v395 + ((int)((unsigned int)(v395 - v391) >> 31));
      v394[v436] = v493;
      int * v397 = v318->cache_age;
      v397[v461] = 0;
      v400 = v461;
    }
    int * v401 = v318->cache_vals;
    int v496 = v400 * 2;
    int v402 = v401[v496];
    int v497 = (v400 * 2) + 1;
    int v403 = v401[v497];
    int v498 = (((((int)((unsigned int)((int)((unsigned int)v322 >> 2)) >> 1)) & 1) * 2) + ((((v342 + ((~(((v344 ^ -1) | (-(v344 ^ -1))) >> 31)) & 2)) - (v345 + ((~(((v346 ^ -1) | (-(v346 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
    v401[v498] = v402;
    int * v405 = v318->cache_vals;
    int v501 = ((((((int)((unsigned int)((int)((unsigned int)v322 >> 2)) >> 1)) & 1) * 2) + ((((v342 + ((~(((v344 ^ -1) | (-(v344 ^ -1))) >> 31)) & 2)) - (v345 + ((~(((v346 ^ -1) | (-(v346 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
    v405[v501] = v403;
    int * v407 = v318->cache_tags;
    int v504 = ((((int)((unsigned int)((int)((unsigned int)v322 >> 2)) >> 1)) & 1) * 2) + ((((v342 + ((~(((v344 ^ -1) | (-(v344 ^ -1))) >> 31)) & 2)) - (v345 + ((~(((v346 ^ -1) | (-(v346 ^ -1))) >> 31)) & 2))) >> 31) & 1);
    int v505 = (int)((unsigned int)((int)((unsigned int)v322 >> 2)) >> 1);
    v407[v504] = v505;
    int * v409 = v318->cache_dirty;
    v409[v504] = 0;
    int * v411 = v318->cache_age;
    v411[v504] = 1;
    int * v413 = v318->cache_age;
    int v414 = v413[v504];
    int v415 = v413[v433];
    int v511 = v415 + ((int)((unsigned int)(v415 - v414) >> 31));
    v413[v433] = v511;
    int * v417 = v318->cache_age;
    int v418 = v417[v434];
    int v513 = v418 + ((int)((unsigned int)(v418 - v414) >> 31));
    v417[v434] = v513;
    int * v420 = v318->cache_age;
    v420[v504] = 0;
    v423 = v504;
  }
  int v516 = (v423 * 2) + (((int)((unsigned int)v322 >> 2)) & 1);
  int v424 = v330[v516];
  int * v425 = v318->regs;
  v425[10] = v424;
  struct StateT * v427 = slot_11(v318);
  return v427;
}

struct StateT * slot_4(struct StateT * v261) {
  int v262 = v261->timer;
  int v268 = v262 + 1;
  v261->timer = v268;
  int * v264 = v261->regs;
  v264[10] = 0;
  struct StateT * v266 = slot_6(v261);
  return v266;
}

struct StateT * slot_15(struct StateT * v580) {
  int v581 = v580->timer;
  int v588 = v581 + 1;
  v580->timer = v588;
  int * v583 = v580->regs;
  int v584 = v583[11];
  int v591 = v584 + 72;
  v583[11] = v591;
  struct StateT * v586 = slot_17(v580);
  return v586;
}

struct StateT * slot_18(struct StateT * v623) {
  int v624 = v623->timer;
  int v631 = v624 + 1;
  v623->timer = v631;
  int * v626 = v623->regs;
  int v627 = v626[10];
  int v634 = v627 << 29;
  v626[10] = v634;
  struct StateT * v629 = slot_20(v623);
  return v629;
}

struct StateT * slot_9(struct StateT * v521) {
  int v522 = v521->timer;
  int v525 = v522 + 1;
  v521->timer = v525;
  return v521;
}

struct StateT * slot_22(struct StateT * v675) {
  int v676 = v675->timer;
  int v786 = v676 + 1;
  v675->timer = v786;
  int * v678 = v675->regs;
  int v679 = v678[10];
  int * v680 = v675->cache_tags;
  int v790 = (((int)((unsigned int)((int)((unsigned int)v679 >> 2)) >> 1)) & 1) * 2;
  int v681 = v680[v790];
  int v791 = ((((int)((unsigned int)((int)((unsigned int)v679 >> 2)) >> 1)) & 1) * 2) + 1;
  int v682 = v680[v791];
  int v792 = 4 + ((((int)((unsigned int)((int)((unsigned int)v679 >> 2)) >> 1)) & 3) * 2);
  int v683 = v680[v792];
  int v793 = (4 + ((((int)((unsigned int)((int)((unsigned int)v679 >> 2)) >> 1)) & 3) * 2)) + 1;
  int v684 = v680[v793];
  int v685 = v675->timer;
  int v794 = v685 + ((100 ^ (((~(((v683 ^ ((int)((unsigned int)((int)((unsigned int)v679 >> 2)) >> 1))) | (-(v683 ^ ((int)((unsigned int)((int)((unsigned int)v679 >> 2)) >> 1))))) >> 31)) | (~(((v684 ^ ((int)((unsigned int)((int)((unsigned int)v679 >> 2)) >> 1))) | (-(v684 ^ ((int)((unsigned int)((int)((unsigned int)v679 >> 2)) >> 1))))) >> 31))) & 104)) ^ (((~(((v681 ^ ((int)((unsigned int)((int)((unsigned int)v679 >> 2)) >> 1))) | (-(v681 ^ ((int)((unsigned int)((int)((unsigned int)v679 >> 2)) >> 1))))) >> 31)) | (~(((v682 ^ ((int)((unsigned int)((int)((unsigned int)v679 >> 2)) >> 1))) | (-(v682 ^ ((int)((unsigned int)((int)((unsigned int)v679 >> 2)) >> 1))))) >> 31))) & (1 ^ (100 ^ (((~(((v683 ^ ((int)((unsigned int)((int)((unsigned int)v679 >> 2)) >> 1))) | (-(v683 ^ ((int)((unsigned int)((int)((unsigned int)v679 >> 2)) >> 1))))) >> 31)) | (~(((v684 ^ ((int)((unsigned int)((int)((unsigned int)v679 >> 2)) >> 1))) | (-(v684 ^ ((int)((unsigned int)((int)((unsigned int)v679 >> 2)) >> 1))))) >> 31))) & 104)))));
  v675->timer = v794;
  int * v687 = v675->cache_vals;
  bool v795 = !(((~(((v681 ^ ((int)((unsigned int)((int)((unsigned int)v679 >> 2)) >> 1))) | (-(v681 ^ ((int)((unsigned int)((int)((unsigned int)v679 >> 2)) >> 1))))) >> 31)) | (~(((v682 ^ ((int)((unsigned int)((int)((unsigned int)v679 >> 2)) >> 1))) | (-(v682 ^ ((int)((unsigned int)((int)((unsigned int)v679 >> 2)) >> 1))))) >> 31))) == 0);
  int v780;
  if (v795) {
    int * v688 = v675->cache_age;
    int v797 = ((((int)((unsigned int)((int)((unsigned int)v679 >> 2)) >> 1)) & 1) * 2) + ((~(((v682 ^ ((int)((unsigned int)((int)((unsigned int)v679 >> 2)) >> 1))) | (-(v682 ^ ((int)((unsigned int)((int)((unsigned int)v679 >> 2)) >> 1))))) >> 31)) & 1);
    int v689 = v688[v797];
    int v690 = v688[v790];
    int v798 = v690 + ((int)((unsigned int)(v690 - v689) >> 31));
    v688[v790] = v798;
    int * v692 = v675->cache_age;
    int v693 = v692[v791];
    int v800 = v693 + ((int)((unsigned int)(v693 - v689) >> 31));
    v692[v791] = v800;
    int * v695 = v675->cache_age;
    v695[v797] = 0;
    v780 = v797;
  } else {
    int * v698 = v675->cache_age;
    int v804 = (((int)((unsigned int)((int)((unsigned int)v679 >> 2)) >> 1)) & 1) * 2;
    int v699 = v698[v804];
    int * v700 = v675->cache_tags;
    int v701 = v700[v804];
    int v702 = v698[v791];
    int v703 = v700[v791];
    bool v806 = !(((~(((v683 ^ ((int)((unsigned int)((int)((unsigned int)v679 >> 2)) >> 1))) | (-(v683 ^ ((int)((unsigned int)((int)((unsigned int)v679 >> 2)) >> 1))))) >> 31)) | (~(((v684 ^ ((int)((unsigned int)((int)((unsigned int)v679 >> 2)) >> 1))) | (-(v684 ^ ((int)((unsigned int)((int)((unsigned int)v679 >> 2)) >> 1))))) >> 31))) == 0);
    int v757;
    if (v806) {
      int * v704 = v675->cache_age;
      int v808 = (4 + ((((int)((unsigned int)((int)((unsigned int)v679 >> 2)) >> 1)) & 3) * 2)) + ((~(((v684 ^ ((int)((unsigned int)((int)((unsigned int)v679 >> 2)) >> 1))) | (-(v684 ^ ((int)((unsigned int)((int)((unsigned int)v679 >> 2)) >> 1))))) >> 31)) & 1);
      int v705 = v704[v808];
      int v706 = v704[v792];
      int v809 = v706 + ((int)((unsigned int)(v706 - v705) >> 31));
      v704[v792] = v809;
      int * v708 = v675->cache_age;
      int v709 = v708[v793];
      int v811 = v709 + ((int)((unsigned int)(v709 - v705) >> 31));
      v708[v793] = v811;
      int * v711 = v675->cache_age;
      v711[v808] = 0;
      v757 = v808;
    } else {
      int * v714 = v675->cache_age;
      int v815 = 4 + ((((int)((unsigned int)((int)((unsigned int)v679 >> 2)) >> 1)) & 3) * 2);
      int v715 = v714[v815];
      int * v716 = v675->cache_tags;
      int v717 = v716[v815];
      int v718 = v714[v793];
      int v719 = v716[v793];
      int * v720 = v675->cache_dirty;
      int v818 = (4 + ((((int)((unsigned int)((int)((unsigned int)v679 >> 2)) >> 1)) & 3) * 2)) + ((((v715 + ((~(((v717 ^ -1) | (-(v717 ^ -1))) >> 31)) & 2)) - (v718 + ((~(((v719 ^ -1) | (-(v719 ^ -1))) >> 31)) & 2))) >> 31) & 1);
      int v721 = v720[v818];
      bool v819 = !(v721 == 0);
      if (v819) {
        int * v722 = v675->cache_tags;
        int v723 = v722[v818];
        int * v724 = v675->cache_vals;
        int v822 = ((4 + ((((int)((unsigned int)((int)((unsigned int)v679 >> 2)) >> 1)) & 3) * 2)) + ((((v715 + ((~(((v717 ^ -1) | (-(v717 ^ -1))) >> 31)) & 2)) - (v718 + ((~(((v719 ^ -1) | (-(v719 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
        int v725 = v724[v822];
        int v823 = (((4 + ((((int)((unsigned int)((int)((unsigned int)v679 >> 2)) >> 1)) & 3) * 2)) + ((((v715 + ((~(((v717 ^ -1) | (-(v717 ^ -1))) >> 31)) & 2)) - (v718 + ((~(((v719 ^ -1) | (-(v719 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
        int v726 = v724[v823];
        int * v727 = v675->mem;
        int v825 = v723 * 2;
        v727[v825] = v725;
        int * v729 = v675->mem;
        int v828 = (v723 * 2) + 1;
        v729[v828] = v726;
        ;
      } else {
        ;
      }
      int * v734 = v675->mem;
      int v833 = ((int)((unsigned int)((int)((unsigned int)v679 >> 2)) >> 1)) * 2;
      int v735 = v734[v833];
      int v834 = (((int)((unsigned int)((int)((unsigned int)v679 >> 2)) >> 1)) * 2) + 1;
      int v736 = v734[v834];
      int * v737 = v675->cache_vals;
      int v836 = ((4 + ((((int)((unsigned int)((int)((unsigned int)v679 >> 2)) >> 1)) & 3) * 2)) + ((((v715 + ((~(((v717 ^ -1) | (-(v717 ^ -1))) >> 31)) & 2)) - (v718 + ((~(((v719 ^ -1) | (-(v719 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
      v737[v836] = v735;
      int * v739 = v675->cache_vals;
      int v839 = (((4 + ((((int)((unsigned int)((int)((unsigned int)v679 >> 2)) >> 1)) & 3) * 2)) + ((((v715 + ((~(((v717 ^ -1) | (-(v717 ^ -1))) >> 31)) & 2)) - (v718 + ((~(((v719 ^ -1) | (-(v719 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
      v739[v839] = v736;
      int * v741 = v675->cache_tags;
      int v842 = (int)((unsigned int)((int)((unsigned int)v679 >> 2)) >> 1);
      v741[v818] = v842;
      int * v743 = v675->cache_dirty;
      v743[v818] = 0;
      int * v745 = v675->cache_age;
      v745[v818] = 1;
      int * v747 = v675->cache_age;
      int v748 = v747[v818];
      int v749 = v747[v792];
      int v848 = v749 + ((int)((unsigned int)(v749 - v748) >> 31));
      v747[v792] = v848;
      int * v751 = v675->cache_age;
      int v752 = v751[v793];
      int v850 = v752 + ((int)((unsigned int)(v752 - v748) >> 31));
      v751[v793] = v850;
      int * v754 = v675->cache_age;
      v754[v818] = 0;
      v757 = v818;
    }
    int * v758 = v675->cache_vals;
    int v853 = v757 * 2;
    int v759 = v758[v853];
    int v854 = (v757 * 2) + 1;
    int v760 = v758[v854];
    int v855 = (((((int)((unsigned int)((int)((unsigned int)v679 >> 2)) >> 1)) & 1) * 2) + ((((v699 + ((~(((v701 ^ -1) | (-(v701 ^ -1))) >> 31)) & 2)) - (v702 + ((~(((v703 ^ -1) | (-(v703 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
    v758[v855] = v759;
    int * v762 = v675->cache_vals;
    int v858 = ((((((int)((unsigned int)((int)((unsigned int)v679 >> 2)) >> 1)) & 1) * 2) + ((((v699 + ((~(((v701 ^ -1) | (-(v701 ^ -1))) >> 31)) & 2)) - (v702 + ((~(((v703 ^ -1) | (-(v703 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
    v762[v858] = v760;
    int * v764 = v675->cache_tags;
    int v861 = ((((int)((unsigned int)((int)((unsigned int)v679 >> 2)) >> 1)) & 1) * 2) + ((((v699 + ((~(((v701 ^ -1) | (-(v701 ^ -1))) >> 31)) & 2)) - (v702 + ((~(((v703 ^ -1) | (-(v703 ^ -1))) >> 31)) & 2))) >> 31) & 1);
    int v862 = (int)((unsigned int)((int)((unsigned int)v679 >> 2)) >> 1);
    v764[v861] = v862;
    int * v766 = v675->cache_dirty;
    v766[v861] = 0;
    int * v768 = v675->cache_age;
    v768[v861] = 1;
    int * v770 = v675->cache_age;
    int v771 = v770[v861];
    int v772 = v770[v790];
    int v868 = v772 + ((int)((unsigned int)(v772 - v771) >> 31));
    v770[v790] = v868;
    int * v774 = v675->cache_age;
    int v775 = v774[v791];
    int v870 = v775 + ((int)((unsigned int)(v775 - v771) >> 31));
    v774[v791] = v870;
    int * v777 = v675->cache_age;
    v777[v861] = 0;
    v780 = v861;
  }
  int v873 = (v780 * 2) + (((int)((unsigned int)v679 >> 2)) & 1);
  int v781 = v687[v873];
  int * v782 = v675->regs;
  v782[10] = v781;
  struct StateT * v784 = slot_23(v675);
  return v784;
}

struct StateT * slot_11(struct StateT * v540) {
  int v541 = v540->timer;
  int v547 = v541 + 1;
  v540->timer = v547;
  int * v543 = v540->regs;
  v543[11] = 0;
  struct StateT * v545 = slot_14(v540);
  return v545;
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