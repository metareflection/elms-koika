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

struct StateT * slot_12(struct StateT * v567);
struct StateT * slot_6(struct StateT * v282);
struct StateT * slot_25(struct StateT * v1126);
struct StateT * slot_16(struct StateT * v646);
struct StateT * slot_23(struct StateT * v906);
struct StateT * slot_5(struct StateT * v274);
struct StateT * slot_2(struct StateT * v30);
struct StateT * slot_7(struct StateT * v296);
struct StateT * slot_21(struct StateT * v687);
struct StateT * slot_3(struct StateT * v233);
struct StateT * slot_10(struct StateT * v540);
struct StateT * slot_1(struct StateT * v10);
struct StateT * slot_19(struct StateT * v673);
struct StateT * slot_13(struct StateT * v581);
struct StateT * slot_24(struct StateT * v1110);
struct StateT * slot_0(struct StateT * v2);
struct StateT * slot_14(struct StateT * v597);
struct StateT * slot_17(struct StateT * v660);
struct StateT * snippet(struct StateT * v0);
struct StateT * slot_8(struct StateT * v317);
struct StateT * slot_4(struct StateT * v261);
struct StateT * slot_15(struct StateT * v610);
struct StateT * slot_18(struct StateT * v665);
struct StateT * slot_9(struct StateT * v520);
struct StateT * slot_22(struct StateT * v703);
struct StateT * slot_11(struct StateT * v553);
struct StateT * slot_12(struct StateT * v567) {
  int v568 = v567->timer;
  int v575 = v568 + 1;
  v567->timer = v575;
  int * v570 = v567->regs;
  int v571 = v570[11];
  int v578 = v571 + 4;
  v570[11] = v578;
  struct StateT * v573 = slot_14(v567);
  return v573;
}

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

struct StateT * slot_25(struct StateT * v1126) {
  int v1127 = v1126->timer;
  int v1297 = v1127 + 1;
  v1126->timer = v1297;
  int * v1129 = v1126->regs;
  int v1130 = v1129[12];
  int v1131 = v1129[10];
  int * v1132 = v1126->cache_tags;
  int v1302 = (((int)((unsigned int)((int)((unsigned int)(v1130 + 68) >> 2)) >> 1)) & 1) * 2;
  int v1133 = v1132[v1302];
  int v1303 = ((((int)((unsigned int)((int)((unsigned int)(v1130 + 68) >> 2)) >> 1)) & 1) * 2) + 1;
  int v1134 = v1132[v1303];
  int v1304 = 4 + ((((int)((unsigned int)((int)((unsigned int)(v1130 + 68) >> 2)) >> 1)) & 3) * 2);
  int v1135 = v1132[v1304];
  int v1305 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v1130 + 68) >> 2)) >> 1)) & 3) * 2)) + 1;
  int v1136 = v1132[v1305];
  int v1137 = v1126->timer;
  int v1306 = v1137 + ((100 ^ (((~(((v1135 ^ ((int)((unsigned int)((int)((unsigned int)(v1130 + 68) >> 2)) >> 1))) | (-(v1135 ^ ((int)((unsigned int)((int)((unsigned int)(v1130 + 68) >> 2)) >> 1))))) >> 31)) | (~(((v1136 ^ ((int)((unsigned int)((int)((unsigned int)(v1130 + 68) >> 2)) >> 1))) | (-(v1136 ^ ((int)((unsigned int)((int)((unsigned int)(v1130 + 68) >> 2)) >> 1))))) >> 31))) & 104)) ^ (((~(((v1133 ^ ((int)((unsigned int)((int)((unsigned int)(v1130 + 68) >> 2)) >> 1))) | (-(v1133 ^ ((int)((unsigned int)((int)((unsigned int)(v1130 + 68) >> 2)) >> 1))))) >> 31)) | (~(((v1134 ^ ((int)((unsigned int)((int)((unsigned int)(v1130 + 68) >> 2)) >> 1))) | (-(v1134 ^ ((int)((unsigned int)((int)((unsigned int)(v1130 + 68) >> 2)) >> 1))))) >> 31))) & (1 ^ (100 ^ (((~(((v1135 ^ ((int)((unsigned int)((int)((unsigned int)(v1130 + 68) >> 2)) >> 1))) | (-(v1135 ^ ((int)((unsigned int)((int)((unsigned int)(v1130 + 68) >> 2)) >> 1))))) >> 31)) | (~(((v1136 ^ ((int)((unsigned int)((int)((unsigned int)(v1130 + 68) >> 2)) >> 1))) | (-(v1136 ^ ((int)((unsigned int)((int)((unsigned int)(v1130 + 68) >> 2)) >> 1))))) >> 31))) & 104)))));
  v1126->timer = v1306;
  bool v1307 = !(((~(((v1133 ^ ((int)((unsigned int)((int)((unsigned int)(v1130 + 68) >> 2)) >> 1))) | (-(v1133 ^ ((int)((unsigned int)((int)((unsigned int)(v1130 + 68) >> 2)) >> 1))))) >> 31)) | (~(((v1134 ^ ((int)((unsigned int)((int)((unsigned int)(v1130 + 68) >> 2)) >> 1))) | (-(v1134 ^ ((int)((unsigned int)((int)((unsigned int)(v1130 + 68) >> 2)) >> 1))))) >> 31))) == 0);
  int v1231;
  if (v1307) {
    int * v1139 = v1126->cache_age;
    int v1309 = ((((int)((unsigned int)((int)((unsigned int)(v1130 + 68) >> 2)) >> 1)) & 1) * 2) + ((~(((v1134 ^ ((int)((unsigned int)((int)((unsigned int)(v1130 + 68) >> 2)) >> 1))) | (-(v1134 ^ ((int)((unsigned int)((int)((unsigned int)(v1130 + 68) >> 2)) >> 1))))) >> 31)) & 1);
    int v1140 = v1139[v1309];
    int v1141 = v1139[v1302];
    int v1310 = v1141 + ((int)((unsigned int)(v1141 - v1140) >> 31));
    v1139[v1302] = v1310;
    int * v1143 = v1126->cache_age;
    int v1144 = v1143[v1303];
    int v1312 = v1144 + ((int)((unsigned int)(v1144 - v1140) >> 31));
    v1143[v1303] = v1312;
    int * v1146 = v1126->cache_age;
    v1146[v1309] = 0;
    v1231 = v1309;
  } else {
    int * v1149 = v1126->cache_age;
    int v1316 = (((int)((unsigned int)((int)((unsigned int)(v1130 + 68) >> 2)) >> 1)) & 1) * 2;
    int v1150 = v1149[v1316];
    int * v1151 = v1126->cache_tags;
    int v1152 = v1151[v1316];
    int v1153 = v1149[v1303];
    int v1154 = v1151[v1303];
    bool v1318 = !(((~(((v1135 ^ ((int)((unsigned int)((int)((unsigned int)(v1130 + 68) >> 2)) >> 1))) | (-(v1135 ^ ((int)((unsigned int)((int)((unsigned int)(v1130 + 68) >> 2)) >> 1))))) >> 31)) | (~(((v1136 ^ ((int)((unsigned int)((int)((unsigned int)(v1130 + 68) >> 2)) >> 1))) | (-(v1136 ^ ((int)((unsigned int)((int)((unsigned int)(v1130 + 68) >> 2)) >> 1))))) >> 31))) == 0);
    int v1208;
    if (v1318) {
      int * v1155 = v1126->cache_age;
      int v1320 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v1130 + 68) >> 2)) >> 1)) & 3) * 2)) + ((~(((v1136 ^ ((int)((unsigned int)((int)((unsigned int)(v1130 + 68) >> 2)) >> 1))) | (-(v1136 ^ ((int)((unsigned int)((int)((unsigned int)(v1130 + 68) >> 2)) >> 1))))) >> 31)) & 1);
      int v1156 = v1155[v1320];
      int v1157 = v1155[v1304];
      int v1321 = v1157 + ((int)((unsigned int)(v1157 - v1156) >> 31));
      v1155[v1304] = v1321;
      int * v1159 = v1126->cache_age;
      int v1160 = v1159[v1305];
      int v1323 = v1160 + ((int)((unsigned int)(v1160 - v1156) >> 31));
      v1159[v1305] = v1323;
      int * v1162 = v1126->cache_age;
      v1162[v1320] = 0;
      v1208 = v1320;
    } else {
      int * v1165 = v1126->cache_age;
      int v1327 = 4 + ((((int)((unsigned int)((int)((unsigned int)(v1130 + 68) >> 2)) >> 1)) & 3) * 2);
      int v1166 = v1165[v1327];
      int * v1167 = v1126->cache_tags;
      int v1168 = v1167[v1327];
      int v1169 = v1165[v1305];
      int v1170 = v1167[v1305];
      int * v1171 = v1126->cache_dirty;
      int v1330 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v1130 + 68) >> 2)) >> 1)) & 3) * 2)) + ((((v1166 + ((~(((v1168 ^ -1) | (-(v1168 ^ -1))) >> 31)) & 2)) - (v1169 + ((~(((v1170 ^ -1) | (-(v1170 ^ -1))) >> 31)) & 2))) >> 31) & 1);
      int v1172 = v1171[v1330];
      bool v1331 = !(v1172 == 0);
      if (v1331) {
        int * v1173 = v1126->cache_tags;
        int v1174 = v1173[v1330];
        int * v1175 = v1126->cache_vals;
        int v1334 = ((4 + ((((int)((unsigned int)((int)((unsigned int)(v1130 + 68) >> 2)) >> 1)) & 3) * 2)) + ((((v1166 + ((~(((v1168 ^ -1) | (-(v1168 ^ -1))) >> 31)) & 2)) - (v1169 + ((~(((v1170 ^ -1) | (-(v1170 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
        int v1176 = v1175[v1334];
        int v1335 = (((4 + ((((int)((unsigned int)((int)((unsigned int)(v1130 + 68) >> 2)) >> 1)) & 3) * 2)) + ((((v1166 + ((~(((v1168 ^ -1) | (-(v1168 ^ -1))) >> 31)) & 2)) - (v1169 + ((~(((v1170 ^ -1) | (-(v1170 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
        int v1177 = v1175[v1335];
        int * v1178 = v1126->mem;
        int v1337 = v1174 * 2;
        v1178[v1337] = v1176;
        int * v1180 = v1126->mem;
        int v1340 = (v1174 * 2) + 1;
        v1180[v1340] = v1177;
        ;
      } else {
        ;
      }
      int * v1185 = v1126->mem;
      int v1345 = ((int)((unsigned int)((int)((unsigned int)(v1130 + 68) >> 2)) >> 1)) * 2;
      int v1186 = v1185[v1345];
      int v1346 = (((int)((unsigned int)((int)((unsigned int)(v1130 + 68) >> 2)) >> 1)) * 2) + 1;
      int v1187 = v1185[v1346];
      int * v1188 = v1126->cache_vals;
      int v1348 = ((4 + ((((int)((unsigned int)((int)((unsigned int)(v1130 + 68) >> 2)) >> 1)) & 3) * 2)) + ((((v1166 + ((~(((v1168 ^ -1) | (-(v1168 ^ -1))) >> 31)) & 2)) - (v1169 + ((~(((v1170 ^ -1) | (-(v1170 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
      v1188[v1348] = v1186;
      int * v1190 = v1126->cache_vals;
      int v1351 = (((4 + ((((int)((unsigned int)((int)((unsigned int)(v1130 + 68) >> 2)) >> 1)) & 3) * 2)) + ((((v1166 + ((~(((v1168 ^ -1) | (-(v1168 ^ -1))) >> 31)) & 2)) - (v1169 + ((~(((v1170 ^ -1) | (-(v1170 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
      v1190[v1351] = v1187;
      int * v1192 = v1126->cache_tags;
      int v1354 = (int)((unsigned int)((int)((unsigned int)(v1130 + 68) >> 2)) >> 1);
      v1192[v1330] = v1354;
      int * v1194 = v1126->cache_dirty;
      v1194[v1330] = 0;
      int * v1196 = v1126->cache_age;
      v1196[v1330] = 1;
      int * v1198 = v1126->cache_age;
      int v1199 = v1198[v1330];
      int v1200 = v1198[v1304];
      int v1360 = v1200 + ((int)((unsigned int)(v1200 - v1199) >> 31));
      v1198[v1304] = v1360;
      int * v1202 = v1126->cache_age;
      int v1203 = v1202[v1305];
      int v1362 = v1203 + ((int)((unsigned int)(v1203 - v1199) >> 31));
      v1202[v1305] = v1362;
      int * v1205 = v1126->cache_age;
      v1205[v1330] = 0;
      v1208 = v1330;
    }
    int * v1209 = v1126->cache_vals;
    int v1365 = v1208 * 2;
    int v1210 = v1209[v1365];
    int v1366 = (v1208 * 2) + 1;
    int v1211 = v1209[v1366];
    int v1367 = (((((int)((unsigned int)((int)((unsigned int)(v1130 + 68) >> 2)) >> 1)) & 1) * 2) + ((((v1150 + ((~(((v1152 ^ -1) | (-(v1152 ^ -1))) >> 31)) & 2)) - (v1153 + ((~(((v1154 ^ -1) | (-(v1154 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
    v1209[v1367] = v1210;
    int * v1213 = v1126->cache_vals;
    int v1370 = ((((((int)((unsigned int)((int)((unsigned int)(v1130 + 68) >> 2)) >> 1)) & 1) * 2) + ((((v1150 + ((~(((v1152 ^ -1) | (-(v1152 ^ -1))) >> 31)) & 2)) - (v1153 + ((~(((v1154 ^ -1) | (-(v1154 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
    v1213[v1370] = v1211;
    int * v1215 = v1126->cache_tags;
    int v1373 = ((((int)((unsigned int)((int)((unsigned int)(v1130 + 68) >> 2)) >> 1)) & 1) * 2) + ((((v1150 + ((~(((v1152 ^ -1) | (-(v1152 ^ -1))) >> 31)) & 2)) - (v1153 + ((~(((v1154 ^ -1) | (-(v1154 ^ -1))) >> 31)) & 2))) >> 31) & 1);
    int v1374 = (int)((unsigned int)((int)((unsigned int)(v1130 + 68) >> 2)) >> 1);
    v1215[v1373] = v1374;
    int * v1217 = v1126->cache_dirty;
    v1217[v1373] = 0;
    int * v1219 = v1126->cache_age;
    v1219[v1373] = 1;
    int * v1221 = v1126->cache_age;
    int v1222 = v1221[v1373];
    int v1223 = v1221[v1302];
    int v1380 = v1223 + ((int)((unsigned int)(v1223 - v1222) >> 31));
    v1221[v1302] = v1380;
    int * v1225 = v1126->cache_age;
    int v1226 = v1225[v1303];
    int v1382 = v1226 + ((int)((unsigned int)(v1226 - v1222) >> 31));
    v1225[v1303] = v1382;
    int * v1228 = v1126->cache_age;
    v1228[v1373] = 0;
    v1231 = v1373;
  }
  int * v1232 = v1126->cache_vals;
  int v1385 = (v1231 * 2) + (((int)((unsigned int)(v1130 + 68) >> 2)) & 1);
  v1232[v1385] = v1131;
  int * v1234 = v1126->cache_tags;
  int v1235 = v1234[v1304];
  int v1236 = v1234[v1305];
  bool v1388 = !(((~(((v1235 ^ ((int)((unsigned int)((int)((unsigned int)(v1130 + 68) >> 2)) >> 1))) | (-(v1235 ^ ((int)((unsigned int)((int)((unsigned int)(v1130 + 68) >> 2)) >> 1))))) >> 31)) | (~(((v1236 ^ ((int)((unsigned int)((int)((unsigned int)(v1130 + 68) >> 2)) >> 1))) | (-(v1236 ^ ((int)((unsigned int)((int)((unsigned int)(v1130 + 68) >> 2)) >> 1))))) >> 31))) == 0);
  int v1290;
  if (v1388) {
    int * v1237 = v1126->cache_age;
    int v1390 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v1130 + 68) >> 2)) >> 1)) & 3) * 2)) + ((~(((v1236 ^ ((int)((unsigned int)((int)((unsigned int)(v1130 + 68) >> 2)) >> 1))) | (-(v1236 ^ ((int)((unsigned int)((int)((unsigned int)(v1130 + 68) >> 2)) >> 1))))) >> 31)) & 1);
    int v1238 = v1237[v1390];
    int v1239 = v1237[v1304];
    int v1391 = v1239 + ((int)((unsigned int)(v1239 - v1238) >> 31));
    v1237[v1304] = v1391;
    int * v1241 = v1126->cache_age;
    int v1242 = v1241[v1305];
    int v1393 = v1242 + ((int)((unsigned int)(v1242 - v1238) >> 31));
    v1241[v1305] = v1393;
    int * v1244 = v1126->cache_age;
    v1244[v1390] = 0;
    v1290 = v1390;
  } else {
    int * v1247 = v1126->cache_age;
    int v1397 = 4 + ((((int)((unsigned int)((int)((unsigned int)(v1130 + 68) >> 2)) >> 1)) & 3) * 2);
    int v1248 = v1247[v1397];
    int * v1249 = v1126->cache_tags;
    int v1250 = v1249[v1397];
    int v1251 = v1247[v1305];
    int v1252 = v1249[v1305];
    int * v1253 = v1126->cache_dirty;
    int v1400 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v1130 + 68) >> 2)) >> 1)) & 3) * 2)) + ((((v1248 + ((~(((v1250 ^ -1) | (-(v1250 ^ -1))) >> 31)) & 2)) - (v1251 + ((~(((v1252 ^ -1) | (-(v1252 ^ -1))) >> 31)) & 2))) >> 31) & 1);
    int v1254 = v1253[v1400];
    bool v1401 = !(v1254 == 0);
    if (v1401) {
      int * v1255 = v1126->cache_tags;
      int v1256 = v1255[v1400];
      int * v1257 = v1126->cache_vals;
      int v1404 = ((4 + ((((int)((unsigned int)((int)((unsigned int)(v1130 + 68) >> 2)) >> 1)) & 3) * 2)) + ((((v1248 + ((~(((v1250 ^ -1) | (-(v1250 ^ -1))) >> 31)) & 2)) - (v1251 + ((~(((v1252 ^ -1) | (-(v1252 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
      int v1258 = v1257[v1404];
      int v1405 = (((4 + ((((int)((unsigned int)((int)((unsigned int)(v1130 + 68) >> 2)) >> 1)) & 3) * 2)) + ((((v1248 + ((~(((v1250 ^ -1) | (-(v1250 ^ -1))) >> 31)) & 2)) - (v1251 + ((~(((v1252 ^ -1) | (-(v1252 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
      int v1259 = v1257[v1405];
      int * v1260 = v1126->mem;
      int v1407 = v1256 * 2;
      v1260[v1407] = v1258;
      int * v1262 = v1126->mem;
      int v1410 = (v1256 * 2) + 1;
      v1262[v1410] = v1259;
      ;
    } else {
      ;
    }
    int * v1267 = v1126->mem;
    int v1415 = ((int)((unsigned int)((int)((unsigned int)(v1130 + 68) >> 2)) >> 1)) * 2;
    int v1268 = v1267[v1415];
    int v1416 = (((int)((unsigned int)((int)((unsigned int)(v1130 + 68) >> 2)) >> 1)) * 2) + 1;
    int v1269 = v1267[v1416];
    int * v1270 = v1126->cache_vals;
    int v1418 = ((4 + ((((int)((unsigned int)((int)((unsigned int)(v1130 + 68) >> 2)) >> 1)) & 3) * 2)) + ((((v1248 + ((~(((v1250 ^ -1) | (-(v1250 ^ -1))) >> 31)) & 2)) - (v1251 + ((~(((v1252 ^ -1) | (-(v1252 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
    v1270[v1418] = v1268;
    int * v1272 = v1126->cache_vals;
    int v1421 = (((4 + ((((int)((unsigned int)((int)((unsigned int)(v1130 + 68) >> 2)) >> 1)) & 3) * 2)) + ((((v1248 + ((~(((v1250 ^ -1) | (-(v1250 ^ -1))) >> 31)) & 2)) - (v1251 + ((~(((v1252 ^ -1) | (-(v1252 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
    v1272[v1421] = v1269;
    int * v1274 = v1126->cache_tags;
    int v1424 = (int)((unsigned int)((int)((unsigned int)(v1130 + 68) >> 2)) >> 1);
    v1274[v1400] = v1424;
    int * v1276 = v1126->cache_dirty;
    v1276[v1400] = 0;
    int * v1278 = v1126->cache_age;
    v1278[v1400] = 1;
    int * v1280 = v1126->cache_age;
    int v1281 = v1280[v1400];
    int v1282 = v1280[v1304];
    int v1430 = v1282 + ((int)((unsigned int)(v1282 - v1281) >> 31));
    v1280[v1304] = v1430;
    int * v1284 = v1126->cache_age;
    int v1285 = v1284[v1305];
    int v1432 = v1285 + ((int)((unsigned int)(v1285 - v1281) >> 31));
    v1284[v1305] = v1432;
    int * v1287 = v1126->cache_age;
    v1287[v1400] = 0;
    v1290 = v1400;
  }
  int * v1291 = v1126->cache_vals;
  int v1435 = (v1290 * 2) + (((int)((unsigned int)(v1130 + 68) >> 2)) & 1);
  v1291[v1435] = v1131;
  int * v1293 = v1126->cache_dirty;
  v1293[v1290] = 1;
  struct StateT * v1295 = slot_17(v1126);
  return v1295;
}

struct StateT * slot_16(struct StateT * v646) {
  int v647 = v646->timer;
  int v654 = v647 + 1;
  v646->timer = v654;
  int * v649 = v646->regs;
  int v650 = v649[10];
  int v657 = v650 << 29;
  v649[10] = v657;
  struct StateT * v652 = slot_19(v646);
  return v652;
}

struct StateT * slot_23(struct StateT * v906) {
  int v907 = v906->timer;
  int v1017 = v907 + 1;
  v906->timer = v1017;
  int * v909 = v906->regs;
  int v910 = v909[12];
  int * v911 = v906->cache_tags;
  int v1021 = (((int)((unsigned int)((int)((unsigned int)(v910 + 68) >> 2)) >> 1)) & 1) * 2;
  int v912 = v911[v1021];
  int v1022 = ((((int)((unsigned int)((int)((unsigned int)(v910 + 68) >> 2)) >> 1)) & 1) * 2) + 1;
  int v913 = v911[v1022];
  int v1023 = 4 + ((((int)((unsigned int)((int)((unsigned int)(v910 + 68) >> 2)) >> 1)) & 3) * 2);
  int v914 = v911[v1023];
  int v1024 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v910 + 68) >> 2)) >> 1)) & 3) * 2)) + 1;
  int v915 = v911[v1024];
  int v916 = v906->timer;
  int v1025 = v916 + ((100 ^ (((~(((v914 ^ ((int)((unsigned int)((int)((unsigned int)(v910 + 68) >> 2)) >> 1))) | (-(v914 ^ ((int)((unsigned int)((int)((unsigned int)(v910 + 68) >> 2)) >> 1))))) >> 31)) | (~(((v915 ^ ((int)((unsigned int)((int)((unsigned int)(v910 + 68) >> 2)) >> 1))) | (-(v915 ^ ((int)((unsigned int)((int)((unsigned int)(v910 + 68) >> 2)) >> 1))))) >> 31))) & 104)) ^ (((~(((v912 ^ ((int)((unsigned int)((int)((unsigned int)(v910 + 68) >> 2)) >> 1))) | (-(v912 ^ ((int)((unsigned int)((int)((unsigned int)(v910 + 68) >> 2)) >> 1))))) >> 31)) | (~(((v913 ^ ((int)((unsigned int)((int)((unsigned int)(v910 + 68) >> 2)) >> 1))) | (-(v913 ^ ((int)((unsigned int)((int)((unsigned int)(v910 + 68) >> 2)) >> 1))))) >> 31))) & (1 ^ (100 ^ (((~(((v914 ^ ((int)((unsigned int)((int)((unsigned int)(v910 + 68) >> 2)) >> 1))) | (-(v914 ^ ((int)((unsigned int)((int)((unsigned int)(v910 + 68) >> 2)) >> 1))))) >> 31)) | (~(((v915 ^ ((int)((unsigned int)((int)((unsigned int)(v910 + 68) >> 2)) >> 1))) | (-(v915 ^ ((int)((unsigned int)((int)((unsigned int)(v910 + 68) >> 2)) >> 1))))) >> 31))) & 104)))));
  v906->timer = v1025;
  int * v918 = v906->cache_vals;
  bool v1026 = !(((~(((v912 ^ ((int)((unsigned int)((int)((unsigned int)(v910 + 68) >> 2)) >> 1))) | (-(v912 ^ ((int)((unsigned int)((int)((unsigned int)(v910 + 68) >> 2)) >> 1))))) >> 31)) | (~(((v913 ^ ((int)((unsigned int)((int)((unsigned int)(v910 + 68) >> 2)) >> 1))) | (-(v913 ^ ((int)((unsigned int)((int)((unsigned int)(v910 + 68) >> 2)) >> 1))))) >> 31))) == 0);
  int v1011;
  if (v1026) {
    int * v919 = v906->cache_age;
    int v1028 = ((((int)((unsigned int)((int)((unsigned int)(v910 + 68) >> 2)) >> 1)) & 1) * 2) + ((~(((v913 ^ ((int)((unsigned int)((int)((unsigned int)(v910 + 68) >> 2)) >> 1))) | (-(v913 ^ ((int)((unsigned int)((int)((unsigned int)(v910 + 68) >> 2)) >> 1))))) >> 31)) & 1);
    int v920 = v919[v1028];
    int v921 = v919[v1021];
    int v1029 = v921 + ((int)((unsigned int)(v921 - v920) >> 31));
    v919[v1021] = v1029;
    int * v923 = v906->cache_age;
    int v924 = v923[v1022];
    int v1031 = v924 + ((int)((unsigned int)(v924 - v920) >> 31));
    v923[v1022] = v1031;
    int * v926 = v906->cache_age;
    v926[v1028] = 0;
    v1011 = v1028;
  } else {
    int * v929 = v906->cache_age;
    int v1035 = (((int)((unsigned int)((int)((unsigned int)(v910 + 68) >> 2)) >> 1)) & 1) * 2;
    int v930 = v929[v1035];
    int * v931 = v906->cache_tags;
    int v932 = v931[v1035];
    int v933 = v929[v1022];
    int v934 = v931[v1022];
    bool v1037 = !(((~(((v914 ^ ((int)((unsigned int)((int)((unsigned int)(v910 + 68) >> 2)) >> 1))) | (-(v914 ^ ((int)((unsigned int)((int)((unsigned int)(v910 + 68) >> 2)) >> 1))))) >> 31)) | (~(((v915 ^ ((int)((unsigned int)((int)((unsigned int)(v910 + 68) >> 2)) >> 1))) | (-(v915 ^ ((int)((unsigned int)((int)((unsigned int)(v910 + 68) >> 2)) >> 1))))) >> 31))) == 0);
    int v988;
    if (v1037) {
      int * v935 = v906->cache_age;
      int v1039 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v910 + 68) >> 2)) >> 1)) & 3) * 2)) + ((~(((v915 ^ ((int)((unsigned int)((int)((unsigned int)(v910 + 68) >> 2)) >> 1))) | (-(v915 ^ ((int)((unsigned int)((int)((unsigned int)(v910 + 68) >> 2)) >> 1))))) >> 31)) & 1);
      int v936 = v935[v1039];
      int v937 = v935[v1023];
      int v1040 = v937 + ((int)((unsigned int)(v937 - v936) >> 31));
      v935[v1023] = v1040;
      int * v939 = v906->cache_age;
      int v940 = v939[v1024];
      int v1042 = v940 + ((int)((unsigned int)(v940 - v936) >> 31));
      v939[v1024] = v1042;
      int * v942 = v906->cache_age;
      v942[v1039] = 0;
      v988 = v1039;
    } else {
      int * v945 = v906->cache_age;
      int v1046 = 4 + ((((int)((unsigned int)((int)((unsigned int)(v910 + 68) >> 2)) >> 1)) & 3) * 2);
      int v946 = v945[v1046];
      int * v947 = v906->cache_tags;
      int v948 = v947[v1046];
      int v949 = v945[v1024];
      int v950 = v947[v1024];
      int * v951 = v906->cache_dirty;
      int v1049 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v910 + 68) >> 2)) >> 1)) & 3) * 2)) + ((((v946 + ((~(((v948 ^ -1) | (-(v948 ^ -1))) >> 31)) & 2)) - (v949 + ((~(((v950 ^ -1) | (-(v950 ^ -1))) >> 31)) & 2))) >> 31) & 1);
      int v952 = v951[v1049];
      bool v1050 = !(v952 == 0);
      if (v1050) {
        int * v953 = v906->cache_tags;
        int v954 = v953[v1049];
        int * v955 = v906->cache_vals;
        int v1053 = ((4 + ((((int)((unsigned int)((int)((unsigned int)(v910 + 68) >> 2)) >> 1)) & 3) * 2)) + ((((v946 + ((~(((v948 ^ -1) | (-(v948 ^ -1))) >> 31)) & 2)) - (v949 + ((~(((v950 ^ -1) | (-(v950 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
        int v956 = v955[v1053];
        int v1054 = (((4 + ((((int)((unsigned int)((int)((unsigned int)(v910 + 68) >> 2)) >> 1)) & 3) * 2)) + ((((v946 + ((~(((v948 ^ -1) | (-(v948 ^ -1))) >> 31)) & 2)) - (v949 + ((~(((v950 ^ -1) | (-(v950 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
        int v957 = v955[v1054];
        int * v958 = v906->mem;
        int v1056 = v954 * 2;
        v958[v1056] = v956;
        int * v960 = v906->mem;
        int v1059 = (v954 * 2) + 1;
        v960[v1059] = v957;
        ;
      } else {
        ;
      }
      int * v965 = v906->mem;
      int v1064 = ((int)((unsigned int)((int)((unsigned int)(v910 + 68) >> 2)) >> 1)) * 2;
      int v966 = v965[v1064];
      int v1065 = (((int)((unsigned int)((int)((unsigned int)(v910 + 68) >> 2)) >> 1)) * 2) + 1;
      int v967 = v965[v1065];
      int * v968 = v906->cache_vals;
      int v1067 = ((4 + ((((int)((unsigned int)((int)((unsigned int)(v910 + 68) >> 2)) >> 1)) & 3) * 2)) + ((((v946 + ((~(((v948 ^ -1) | (-(v948 ^ -1))) >> 31)) & 2)) - (v949 + ((~(((v950 ^ -1) | (-(v950 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
      v968[v1067] = v966;
      int * v970 = v906->cache_vals;
      int v1070 = (((4 + ((((int)((unsigned int)((int)((unsigned int)(v910 + 68) >> 2)) >> 1)) & 3) * 2)) + ((((v946 + ((~(((v948 ^ -1) | (-(v948 ^ -1))) >> 31)) & 2)) - (v949 + ((~(((v950 ^ -1) | (-(v950 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
      v970[v1070] = v967;
      int * v972 = v906->cache_tags;
      int v1073 = (int)((unsigned int)((int)((unsigned int)(v910 + 68) >> 2)) >> 1);
      v972[v1049] = v1073;
      int * v974 = v906->cache_dirty;
      v974[v1049] = 0;
      int * v976 = v906->cache_age;
      v976[v1049] = 1;
      int * v978 = v906->cache_age;
      int v979 = v978[v1049];
      int v980 = v978[v1023];
      int v1079 = v980 + ((int)((unsigned int)(v980 - v979) >> 31));
      v978[v1023] = v1079;
      int * v982 = v906->cache_age;
      int v983 = v982[v1024];
      int v1081 = v983 + ((int)((unsigned int)(v983 - v979) >> 31));
      v982[v1024] = v1081;
      int * v985 = v906->cache_age;
      v985[v1049] = 0;
      v988 = v1049;
    }
    int * v989 = v906->cache_vals;
    int v1084 = v988 * 2;
    int v990 = v989[v1084];
    int v1085 = (v988 * 2) + 1;
    int v991 = v989[v1085];
    int v1086 = (((((int)((unsigned int)((int)((unsigned int)(v910 + 68) >> 2)) >> 1)) & 1) * 2) + ((((v930 + ((~(((v932 ^ -1) | (-(v932 ^ -1))) >> 31)) & 2)) - (v933 + ((~(((v934 ^ -1) | (-(v934 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
    v989[v1086] = v990;
    int * v993 = v906->cache_vals;
    int v1089 = ((((((int)((unsigned int)((int)((unsigned int)(v910 + 68) >> 2)) >> 1)) & 1) * 2) + ((((v930 + ((~(((v932 ^ -1) | (-(v932 ^ -1))) >> 31)) & 2)) - (v933 + ((~(((v934 ^ -1) | (-(v934 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
    v993[v1089] = v991;
    int * v995 = v906->cache_tags;
    int v1092 = ((((int)((unsigned int)((int)((unsigned int)(v910 + 68) >> 2)) >> 1)) & 1) * 2) + ((((v930 + ((~(((v932 ^ -1) | (-(v932 ^ -1))) >> 31)) & 2)) - (v933 + ((~(((v934 ^ -1) | (-(v934 ^ -1))) >> 31)) & 2))) >> 31) & 1);
    int v1093 = (int)((unsigned int)((int)((unsigned int)(v910 + 68) >> 2)) >> 1);
    v995[v1092] = v1093;
    int * v997 = v906->cache_dirty;
    v997[v1092] = 0;
    int * v999 = v906->cache_age;
    v999[v1092] = 1;
    int * v1001 = v906->cache_age;
    int v1002 = v1001[v1092];
    int v1003 = v1001[v1021];
    int v1099 = v1003 + ((int)((unsigned int)(v1003 - v1002) >> 31));
    v1001[v1021] = v1099;
    int * v1005 = v906->cache_age;
    int v1006 = v1005[v1022];
    int v1101 = v1006 + ((int)((unsigned int)(v1006 - v1002) >> 31));
    v1005[v1022] = v1101;
    int * v1008 = v906->cache_age;
    v1008[v1092] = 0;
    v1011 = v1092;
  }
  int v1104 = (v1011 * 2) + (((int)((unsigned int)(v910 + 68) >> 2)) & 1);
  int v1012 = v918[v1104];
  int * v1013 = v906->regs;
  v1013[11] = v1012;
  struct StateT * v1015 = slot_24(v906);
  return v1015;
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
  int * v297 = v296->saved_regs;
  int * v298 = v296->regs;
  int v299 = v298[10];
  v297[10] = v299;
  int v301 = v296->timer;
  int v312 = v301 + 1;
  v296->timer = v312;
  int * v303 = v296->regs;
  int v304 = v303[10];
  int v314 = v304 << 2;
  v303[10] = v314;
  struct StateT * v306 = slot_9(v296);
  return v306;
}

struct StateT * slot_21(struct StateT * v687) {
  int v688 = v687->timer;
  int v696 = v688 + 1;
  v687->timer = v696;
  int * v690 = v687->regs;
  int v691 = v690[11];
  int v692 = v690[10];
  int v700 = v691 + v692;
  v690[10] = v700;
  struct StateT * v694 = slot_22(v687);
  return v694;
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

struct StateT * slot_10(struct StateT * v540) {
  int v541 = v540->timer;
  int v547 = v541 + 1;
  v540->timer = v547;
  int * v543 = v540->regs;
  v543[11] = 0;
  struct StateT * v545 = slot_12(v540);
  return v545;
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

struct StateT * slot_19(struct StateT * v673) {
  int v674 = v673->timer;
  int v681 = v674 + 1;
  v673->timer = v681;
  int * v676 = v673->regs;
  int v677 = v676[10];
  int v684 = (int)((unsigned int)v677 >> 26);
  v676[10] = v684;
  struct StateT * v679 = slot_21(v673);
  return v679;
}

struct StateT * slot_13(struct StateT * v581) {
  int v582 = v581->timer;
  int v590 = v582 + 1;
  v581->timer = v590;
  int * v584 = v581->regs;
  int v585 = v584[11];
  int v586 = v584[10];
  int v594 = v585 + v586;
  v584[10] = v594;
  struct StateT * v588 = slot_15(v581);
  return v588;
}

struct StateT * slot_24(struct StateT * v1110) {
  int v1111 = v1110->timer;
  int v1119 = v1111 + 1;
  v1110->timer = v1119;
  int * v1113 = v1110->regs;
  int v1114 = v1113[11];
  int v1115 = v1113[10];
  int v1123 = v1114 & v1115;
  v1113[10] = v1123;
  struct StateT * v1117 = slot_25(v1110);
  return v1117;
}

struct StateT * slot_0(struct StateT * v2) {
  int v3 = v2->timer;
  int v7 = v3 + 1;
  v2->timer = v7;
  struct StateT * v5 = slot_1(v2);
  return v5;
}

struct StateT * slot_14(struct StateT * v597) {
  int v598 = v597->timer;
  int v604 = v598 + 1;
  v597->timer = v604;
  int * v600 = v597->regs;
  v600[12] = 0;
  struct StateT * v602 = slot_16(v597);
  return v602;
}

struct StateT * slot_17(struct StateT * v660) {
  int v661 = v660->timer;
  int v664 = v661 + 1;
  v660->timer = v664;
  return v660;
}

struct StateT * snippet(struct StateT * v0) {
  struct StateT * v1 = slot_0(v0);
  return v1;
}

struct StateT * slot_8(struct StateT * v317) {
  int v318 = v317->timer;
  int v428 = v318 + 1;
  v317->timer = v428;
  int * v320 = v317->regs;
  int v321 = v320[10];
  int * v322 = v317->cache_tags;
  int v432 = (((int)((unsigned int)((int)((unsigned int)v321 >> 2)) >> 1)) & 1) * 2;
  int v323 = v322[v432];
  int v433 = ((((int)((unsigned int)((int)((unsigned int)v321 >> 2)) >> 1)) & 1) * 2) + 1;
  int v324 = v322[v433];
  int v434 = 4 + ((((int)((unsigned int)((int)((unsigned int)v321 >> 2)) >> 1)) & 3) * 2);
  int v325 = v322[v434];
  int v435 = (4 + ((((int)((unsigned int)((int)((unsigned int)v321 >> 2)) >> 1)) & 3) * 2)) + 1;
  int v326 = v322[v435];
  int v327 = v317->timer;
  int v436 = v327 + ((100 ^ (((~(((v325 ^ ((int)((unsigned int)((int)((unsigned int)v321 >> 2)) >> 1))) | (-(v325 ^ ((int)((unsigned int)((int)((unsigned int)v321 >> 2)) >> 1))))) >> 31)) | (~(((v326 ^ ((int)((unsigned int)((int)((unsigned int)v321 >> 2)) >> 1))) | (-(v326 ^ ((int)((unsigned int)((int)((unsigned int)v321 >> 2)) >> 1))))) >> 31))) & 104)) ^ (((~(((v323 ^ ((int)((unsigned int)((int)((unsigned int)v321 >> 2)) >> 1))) | (-(v323 ^ ((int)((unsigned int)((int)((unsigned int)v321 >> 2)) >> 1))))) >> 31)) | (~(((v324 ^ ((int)((unsigned int)((int)((unsigned int)v321 >> 2)) >> 1))) | (-(v324 ^ ((int)((unsigned int)((int)((unsigned int)v321 >> 2)) >> 1))))) >> 31))) & (1 ^ (100 ^ (((~(((v325 ^ ((int)((unsigned int)((int)((unsigned int)v321 >> 2)) >> 1))) | (-(v325 ^ ((int)((unsigned int)((int)((unsigned int)v321 >> 2)) >> 1))))) >> 31)) | (~(((v326 ^ ((int)((unsigned int)((int)((unsigned int)v321 >> 2)) >> 1))) | (-(v326 ^ ((int)((unsigned int)((int)((unsigned int)v321 >> 2)) >> 1))))) >> 31))) & 104)))));
  v317->timer = v436;
  int * v329 = v317->cache_vals;
  bool v437 = !(((~(((v323 ^ ((int)((unsigned int)((int)((unsigned int)v321 >> 2)) >> 1))) | (-(v323 ^ ((int)((unsigned int)((int)((unsigned int)v321 >> 2)) >> 1))))) >> 31)) | (~(((v324 ^ ((int)((unsigned int)((int)((unsigned int)v321 >> 2)) >> 1))) | (-(v324 ^ ((int)((unsigned int)((int)((unsigned int)v321 >> 2)) >> 1))))) >> 31))) == 0);
  int v422;
  if (v437) {
    int * v330 = v317->cache_age;
    int v439 = ((((int)((unsigned int)((int)((unsigned int)v321 >> 2)) >> 1)) & 1) * 2) + ((~(((v324 ^ ((int)((unsigned int)((int)((unsigned int)v321 >> 2)) >> 1))) | (-(v324 ^ ((int)((unsigned int)((int)((unsigned int)v321 >> 2)) >> 1))))) >> 31)) & 1);
    int v331 = v330[v439];
    int v332 = v330[v432];
    int v440 = v332 + ((int)((unsigned int)(v332 - v331) >> 31));
    v330[v432] = v440;
    int * v334 = v317->cache_age;
    int v335 = v334[v433];
    int v442 = v335 + ((int)((unsigned int)(v335 - v331) >> 31));
    v334[v433] = v442;
    int * v337 = v317->cache_age;
    v337[v439] = 0;
    v422 = v439;
  } else {
    int * v340 = v317->cache_age;
    int v446 = (((int)((unsigned int)((int)((unsigned int)v321 >> 2)) >> 1)) & 1) * 2;
    int v341 = v340[v446];
    int * v342 = v317->cache_tags;
    int v343 = v342[v446];
    int v344 = v340[v433];
    int v345 = v342[v433];
    bool v448 = !(((~(((v325 ^ ((int)((unsigned int)((int)((unsigned int)v321 >> 2)) >> 1))) | (-(v325 ^ ((int)((unsigned int)((int)((unsigned int)v321 >> 2)) >> 1))))) >> 31)) | (~(((v326 ^ ((int)((unsigned int)((int)((unsigned int)v321 >> 2)) >> 1))) | (-(v326 ^ ((int)((unsigned int)((int)((unsigned int)v321 >> 2)) >> 1))))) >> 31))) == 0);
    int v399;
    if (v448) {
      int * v346 = v317->cache_age;
      int v450 = (4 + ((((int)((unsigned int)((int)((unsigned int)v321 >> 2)) >> 1)) & 3) * 2)) + ((~(((v326 ^ ((int)((unsigned int)((int)((unsigned int)v321 >> 2)) >> 1))) | (-(v326 ^ ((int)((unsigned int)((int)((unsigned int)v321 >> 2)) >> 1))))) >> 31)) & 1);
      int v347 = v346[v450];
      int v348 = v346[v434];
      int v451 = v348 + ((int)((unsigned int)(v348 - v347) >> 31));
      v346[v434] = v451;
      int * v350 = v317->cache_age;
      int v351 = v350[v435];
      int v453 = v351 + ((int)((unsigned int)(v351 - v347) >> 31));
      v350[v435] = v453;
      int * v353 = v317->cache_age;
      v353[v450] = 0;
      v399 = v450;
    } else {
      int * v356 = v317->cache_age;
      int v457 = 4 + ((((int)((unsigned int)((int)((unsigned int)v321 >> 2)) >> 1)) & 3) * 2);
      int v357 = v356[v457];
      int * v358 = v317->cache_tags;
      int v359 = v358[v457];
      int v360 = v356[v435];
      int v361 = v358[v435];
      int * v362 = v317->cache_dirty;
      int v460 = (4 + ((((int)((unsigned int)((int)((unsigned int)v321 >> 2)) >> 1)) & 3) * 2)) + ((((v357 + ((~(((v359 ^ -1) | (-(v359 ^ -1))) >> 31)) & 2)) - (v360 + ((~(((v361 ^ -1) | (-(v361 ^ -1))) >> 31)) & 2))) >> 31) & 1);
      int v363 = v362[v460];
      bool v461 = !(v363 == 0);
      if (v461) {
        int * v364 = v317->cache_tags;
        int v365 = v364[v460];
        int * v366 = v317->cache_vals;
        int v464 = ((4 + ((((int)((unsigned int)((int)((unsigned int)v321 >> 2)) >> 1)) & 3) * 2)) + ((((v357 + ((~(((v359 ^ -1) | (-(v359 ^ -1))) >> 31)) & 2)) - (v360 + ((~(((v361 ^ -1) | (-(v361 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
        int v367 = v366[v464];
        int v465 = (((4 + ((((int)((unsigned int)((int)((unsigned int)v321 >> 2)) >> 1)) & 3) * 2)) + ((((v357 + ((~(((v359 ^ -1) | (-(v359 ^ -1))) >> 31)) & 2)) - (v360 + ((~(((v361 ^ -1) | (-(v361 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
        int v368 = v366[v465];
        int * v369 = v317->mem;
        int v467 = v365 * 2;
        v369[v467] = v367;
        int * v371 = v317->mem;
        int v470 = (v365 * 2) + 1;
        v371[v470] = v368;
        ;
      } else {
        ;
      }
      int * v376 = v317->mem;
      int v475 = ((int)((unsigned int)((int)((unsigned int)v321 >> 2)) >> 1)) * 2;
      int v377 = v376[v475];
      int v476 = (((int)((unsigned int)((int)((unsigned int)v321 >> 2)) >> 1)) * 2) + 1;
      int v378 = v376[v476];
      int * v379 = v317->cache_vals;
      int v478 = ((4 + ((((int)((unsigned int)((int)((unsigned int)v321 >> 2)) >> 1)) & 3) * 2)) + ((((v357 + ((~(((v359 ^ -1) | (-(v359 ^ -1))) >> 31)) & 2)) - (v360 + ((~(((v361 ^ -1) | (-(v361 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
      v379[v478] = v377;
      int * v381 = v317->cache_vals;
      int v481 = (((4 + ((((int)((unsigned int)((int)((unsigned int)v321 >> 2)) >> 1)) & 3) * 2)) + ((((v357 + ((~(((v359 ^ -1) | (-(v359 ^ -1))) >> 31)) & 2)) - (v360 + ((~(((v361 ^ -1) | (-(v361 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
      v381[v481] = v378;
      int * v383 = v317->cache_tags;
      int v484 = (int)((unsigned int)((int)((unsigned int)v321 >> 2)) >> 1);
      v383[v460] = v484;
      int * v385 = v317->cache_dirty;
      v385[v460] = 0;
      int * v387 = v317->cache_age;
      v387[v460] = 1;
      int * v389 = v317->cache_age;
      int v390 = v389[v460];
      int v391 = v389[v434];
      int v490 = v391 + ((int)((unsigned int)(v391 - v390) >> 31));
      v389[v434] = v490;
      int * v393 = v317->cache_age;
      int v394 = v393[v435];
      int v492 = v394 + ((int)((unsigned int)(v394 - v390) >> 31));
      v393[v435] = v492;
      int * v396 = v317->cache_age;
      v396[v460] = 0;
      v399 = v460;
    }
    int * v400 = v317->cache_vals;
    int v495 = v399 * 2;
    int v401 = v400[v495];
    int v496 = (v399 * 2) + 1;
    int v402 = v400[v496];
    int v497 = (((((int)((unsigned int)((int)((unsigned int)v321 >> 2)) >> 1)) & 1) * 2) + ((((v341 + ((~(((v343 ^ -1) | (-(v343 ^ -1))) >> 31)) & 2)) - (v344 + ((~(((v345 ^ -1) | (-(v345 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
    v400[v497] = v401;
    int * v404 = v317->cache_vals;
    int v500 = ((((((int)((unsigned int)((int)((unsigned int)v321 >> 2)) >> 1)) & 1) * 2) + ((((v341 + ((~(((v343 ^ -1) | (-(v343 ^ -1))) >> 31)) & 2)) - (v344 + ((~(((v345 ^ -1) | (-(v345 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
    v404[v500] = v402;
    int * v406 = v317->cache_tags;
    int v503 = ((((int)((unsigned int)((int)((unsigned int)v321 >> 2)) >> 1)) & 1) * 2) + ((((v341 + ((~(((v343 ^ -1) | (-(v343 ^ -1))) >> 31)) & 2)) - (v344 + ((~(((v345 ^ -1) | (-(v345 ^ -1))) >> 31)) & 2))) >> 31) & 1);
    int v504 = (int)((unsigned int)((int)((unsigned int)v321 >> 2)) >> 1);
    v406[v503] = v504;
    int * v408 = v317->cache_dirty;
    v408[v503] = 0;
    int * v410 = v317->cache_age;
    v410[v503] = 1;
    int * v412 = v317->cache_age;
    int v413 = v412[v503];
    int v414 = v412[v432];
    int v510 = v414 + ((int)((unsigned int)(v414 - v413) >> 31));
    v412[v432] = v510;
    int * v416 = v317->cache_age;
    int v417 = v416[v433];
    int v512 = v417 + ((int)((unsigned int)(v417 - v413) >> 31));
    v416[v433] = v512;
    int * v419 = v317->cache_age;
    v419[v503] = 0;
    v422 = v503;
  }
  int v515 = (v422 * 2) + (((int)((unsigned int)v321 >> 2)) & 1);
  int v423 = v329[v515];
  int * v424 = v317->regs;
  v424[10] = v423;
  struct StateT * v426 = slot_10(v317);
  return v426;
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

struct StateT * slot_15(struct StateT * v610) {
  int * v611 = v610->saved_regs;
  int v612 = v611[10];
  int v613 = v611[11];
  bool v633 = (v612 ^ -2147483648) >= (v613 ^ -2147483648);
  struct StateT * v628;
  if (v633) {
    int v614 = v610->timer;
    int v634 = v614 + 15;
    v610->timer = v634;
    int * v616 = v610->saved_regs;
    int v617 = v616[10];
    int * v618 = v610->regs;
    v618[10] = v617;
    int * v620 = v610->saved_regs;
    int v621 = v620[11];
    int * v622 = v610->regs;
    v622[11] = v621;
    struct StateT * v624 = slot_17(v610);
    v628 = v624;
  } else {
    struct StateT * v626 = slot_18(v610);
    v628 = v626;
  }
  return v628;
}

struct StateT * slot_18(struct StateT * v665) {
  int v666 = v665->timer;
  int v670 = v666 + 1;
  v665->timer = v670;
  struct StateT * v668 = slot_8(v665);
  return v668;
}

struct StateT * slot_9(struct StateT * v520) {
  int * v521 = v520->saved_regs;
  int * v522 = v520->regs;
  int v523 = v522[11];
  v521[11] = v523;
  int v525 = v520->timer;
  int v535 = v525 + 1;
  v520->timer = v535;
  int * v527 = v520->regs;
  v527[11] = 0;
  struct StateT * v529 = slot_11(v520);
  return v529;
}

struct StateT * slot_22(struct StateT * v703) {
  int v704 = v703->timer;
  int v814 = v704 + 1;
  v703->timer = v814;
  int * v706 = v703->regs;
  int v707 = v706[10];
  int * v708 = v703->cache_tags;
  int v818 = (((int)((unsigned int)((int)((unsigned int)v707 >> 2)) >> 1)) & 1) * 2;
  int v709 = v708[v818];
  int v819 = ((((int)((unsigned int)((int)((unsigned int)v707 >> 2)) >> 1)) & 1) * 2) + 1;
  int v710 = v708[v819];
  int v820 = 4 + ((((int)((unsigned int)((int)((unsigned int)v707 >> 2)) >> 1)) & 3) * 2);
  int v711 = v708[v820];
  int v821 = (4 + ((((int)((unsigned int)((int)((unsigned int)v707 >> 2)) >> 1)) & 3) * 2)) + 1;
  int v712 = v708[v821];
  int v713 = v703->timer;
  int v822 = v713 + ((100 ^ (((~(((v711 ^ ((int)((unsigned int)((int)((unsigned int)v707 >> 2)) >> 1))) | (-(v711 ^ ((int)((unsigned int)((int)((unsigned int)v707 >> 2)) >> 1))))) >> 31)) | (~(((v712 ^ ((int)((unsigned int)((int)((unsigned int)v707 >> 2)) >> 1))) | (-(v712 ^ ((int)((unsigned int)((int)((unsigned int)v707 >> 2)) >> 1))))) >> 31))) & 104)) ^ (((~(((v709 ^ ((int)((unsigned int)((int)((unsigned int)v707 >> 2)) >> 1))) | (-(v709 ^ ((int)((unsigned int)((int)((unsigned int)v707 >> 2)) >> 1))))) >> 31)) | (~(((v710 ^ ((int)((unsigned int)((int)((unsigned int)v707 >> 2)) >> 1))) | (-(v710 ^ ((int)((unsigned int)((int)((unsigned int)v707 >> 2)) >> 1))))) >> 31))) & (1 ^ (100 ^ (((~(((v711 ^ ((int)((unsigned int)((int)((unsigned int)v707 >> 2)) >> 1))) | (-(v711 ^ ((int)((unsigned int)((int)((unsigned int)v707 >> 2)) >> 1))))) >> 31)) | (~(((v712 ^ ((int)((unsigned int)((int)((unsigned int)v707 >> 2)) >> 1))) | (-(v712 ^ ((int)((unsigned int)((int)((unsigned int)v707 >> 2)) >> 1))))) >> 31))) & 104)))));
  v703->timer = v822;
  int * v715 = v703->cache_vals;
  bool v823 = !(((~(((v709 ^ ((int)((unsigned int)((int)((unsigned int)v707 >> 2)) >> 1))) | (-(v709 ^ ((int)((unsigned int)((int)((unsigned int)v707 >> 2)) >> 1))))) >> 31)) | (~(((v710 ^ ((int)((unsigned int)((int)((unsigned int)v707 >> 2)) >> 1))) | (-(v710 ^ ((int)((unsigned int)((int)((unsigned int)v707 >> 2)) >> 1))))) >> 31))) == 0);
  int v808;
  if (v823) {
    int * v716 = v703->cache_age;
    int v825 = ((((int)((unsigned int)((int)((unsigned int)v707 >> 2)) >> 1)) & 1) * 2) + ((~(((v710 ^ ((int)((unsigned int)((int)((unsigned int)v707 >> 2)) >> 1))) | (-(v710 ^ ((int)((unsigned int)((int)((unsigned int)v707 >> 2)) >> 1))))) >> 31)) & 1);
    int v717 = v716[v825];
    int v718 = v716[v818];
    int v826 = v718 + ((int)((unsigned int)(v718 - v717) >> 31));
    v716[v818] = v826;
    int * v720 = v703->cache_age;
    int v721 = v720[v819];
    int v828 = v721 + ((int)((unsigned int)(v721 - v717) >> 31));
    v720[v819] = v828;
    int * v723 = v703->cache_age;
    v723[v825] = 0;
    v808 = v825;
  } else {
    int * v726 = v703->cache_age;
    int v832 = (((int)((unsigned int)((int)((unsigned int)v707 >> 2)) >> 1)) & 1) * 2;
    int v727 = v726[v832];
    int * v728 = v703->cache_tags;
    int v729 = v728[v832];
    int v730 = v726[v819];
    int v731 = v728[v819];
    bool v834 = !(((~(((v711 ^ ((int)((unsigned int)((int)((unsigned int)v707 >> 2)) >> 1))) | (-(v711 ^ ((int)((unsigned int)((int)((unsigned int)v707 >> 2)) >> 1))))) >> 31)) | (~(((v712 ^ ((int)((unsigned int)((int)((unsigned int)v707 >> 2)) >> 1))) | (-(v712 ^ ((int)((unsigned int)((int)((unsigned int)v707 >> 2)) >> 1))))) >> 31))) == 0);
    int v785;
    if (v834) {
      int * v732 = v703->cache_age;
      int v836 = (4 + ((((int)((unsigned int)((int)((unsigned int)v707 >> 2)) >> 1)) & 3) * 2)) + ((~(((v712 ^ ((int)((unsigned int)((int)((unsigned int)v707 >> 2)) >> 1))) | (-(v712 ^ ((int)((unsigned int)((int)((unsigned int)v707 >> 2)) >> 1))))) >> 31)) & 1);
      int v733 = v732[v836];
      int v734 = v732[v820];
      int v837 = v734 + ((int)((unsigned int)(v734 - v733) >> 31));
      v732[v820] = v837;
      int * v736 = v703->cache_age;
      int v737 = v736[v821];
      int v839 = v737 + ((int)((unsigned int)(v737 - v733) >> 31));
      v736[v821] = v839;
      int * v739 = v703->cache_age;
      v739[v836] = 0;
      v785 = v836;
    } else {
      int * v742 = v703->cache_age;
      int v843 = 4 + ((((int)((unsigned int)((int)((unsigned int)v707 >> 2)) >> 1)) & 3) * 2);
      int v743 = v742[v843];
      int * v744 = v703->cache_tags;
      int v745 = v744[v843];
      int v746 = v742[v821];
      int v747 = v744[v821];
      int * v748 = v703->cache_dirty;
      int v846 = (4 + ((((int)((unsigned int)((int)((unsigned int)v707 >> 2)) >> 1)) & 3) * 2)) + ((((v743 + ((~(((v745 ^ -1) | (-(v745 ^ -1))) >> 31)) & 2)) - (v746 + ((~(((v747 ^ -1) | (-(v747 ^ -1))) >> 31)) & 2))) >> 31) & 1);
      int v749 = v748[v846];
      bool v847 = !(v749 == 0);
      if (v847) {
        int * v750 = v703->cache_tags;
        int v751 = v750[v846];
        int * v752 = v703->cache_vals;
        int v850 = ((4 + ((((int)((unsigned int)((int)((unsigned int)v707 >> 2)) >> 1)) & 3) * 2)) + ((((v743 + ((~(((v745 ^ -1) | (-(v745 ^ -1))) >> 31)) & 2)) - (v746 + ((~(((v747 ^ -1) | (-(v747 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
        int v753 = v752[v850];
        int v851 = (((4 + ((((int)((unsigned int)((int)((unsigned int)v707 >> 2)) >> 1)) & 3) * 2)) + ((((v743 + ((~(((v745 ^ -1) | (-(v745 ^ -1))) >> 31)) & 2)) - (v746 + ((~(((v747 ^ -1) | (-(v747 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
        int v754 = v752[v851];
        int * v755 = v703->mem;
        int v853 = v751 * 2;
        v755[v853] = v753;
        int * v757 = v703->mem;
        int v856 = (v751 * 2) + 1;
        v757[v856] = v754;
        ;
      } else {
        ;
      }
      int * v762 = v703->mem;
      int v861 = ((int)((unsigned int)((int)((unsigned int)v707 >> 2)) >> 1)) * 2;
      int v763 = v762[v861];
      int v862 = (((int)((unsigned int)((int)((unsigned int)v707 >> 2)) >> 1)) * 2) + 1;
      int v764 = v762[v862];
      int * v765 = v703->cache_vals;
      int v864 = ((4 + ((((int)((unsigned int)((int)((unsigned int)v707 >> 2)) >> 1)) & 3) * 2)) + ((((v743 + ((~(((v745 ^ -1) | (-(v745 ^ -1))) >> 31)) & 2)) - (v746 + ((~(((v747 ^ -1) | (-(v747 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
      v765[v864] = v763;
      int * v767 = v703->cache_vals;
      int v867 = (((4 + ((((int)((unsigned int)((int)((unsigned int)v707 >> 2)) >> 1)) & 3) * 2)) + ((((v743 + ((~(((v745 ^ -1) | (-(v745 ^ -1))) >> 31)) & 2)) - (v746 + ((~(((v747 ^ -1) | (-(v747 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
      v767[v867] = v764;
      int * v769 = v703->cache_tags;
      int v870 = (int)((unsigned int)((int)((unsigned int)v707 >> 2)) >> 1);
      v769[v846] = v870;
      int * v771 = v703->cache_dirty;
      v771[v846] = 0;
      int * v773 = v703->cache_age;
      v773[v846] = 1;
      int * v775 = v703->cache_age;
      int v776 = v775[v846];
      int v777 = v775[v820];
      int v876 = v777 + ((int)((unsigned int)(v777 - v776) >> 31));
      v775[v820] = v876;
      int * v779 = v703->cache_age;
      int v780 = v779[v821];
      int v878 = v780 + ((int)((unsigned int)(v780 - v776) >> 31));
      v779[v821] = v878;
      int * v782 = v703->cache_age;
      v782[v846] = 0;
      v785 = v846;
    }
    int * v786 = v703->cache_vals;
    int v881 = v785 * 2;
    int v787 = v786[v881];
    int v882 = (v785 * 2) + 1;
    int v788 = v786[v882];
    int v883 = (((((int)((unsigned int)((int)((unsigned int)v707 >> 2)) >> 1)) & 1) * 2) + ((((v727 + ((~(((v729 ^ -1) | (-(v729 ^ -1))) >> 31)) & 2)) - (v730 + ((~(((v731 ^ -1) | (-(v731 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
    v786[v883] = v787;
    int * v790 = v703->cache_vals;
    int v886 = ((((((int)((unsigned int)((int)((unsigned int)v707 >> 2)) >> 1)) & 1) * 2) + ((((v727 + ((~(((v729 ^ -1) | (-(v729 ^ -1))) >> 31)) & 2)) - (v730 + ((~(((v731 ^ -1) | (-(v731 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
    v790[v886] = v788;
    int * v792 = v703->cache_tags;
    int v889 = ((((int)((unsigned int)((int)((unsigned int)v707 >> 2)) >> 1)) & 1) * 2) + ((((v727 + ((~(((v729 ^ -1) | (-(v729 ^ -1))) >> 31)) & 2)) - (v730 + ((~(((v731 ^ -1) | (-(v731 ^ -1))) >> 31)) & 2))) >> 31) & 1);
    int v890 = (int)((unsigned int)((int)((unsigned int)v707 >> 2)) >> 1);
    v792[v889] = v890;
    int * v794 = v703->cache_dirty;
    v794[v889] = 0;
    int * v796 = v703->cache_age;
    v796[v889] = 1;
    int * v798 = v703->cache_age;
    int v799 = v798[v889];
    int v800 = v798[v818];
    int v896 = v800 + ((int)((unsigned int)(v800 - v799) >> 31));
    v798[v818] = v896;
    int * v802 = v703->cache_age;
    int v803 = v802[v819];
    int v898 = v803 + ((int)((unsigned int)(v803 - v799) >> 31));
    v802[v819] = v898;
    int * v805 = v703->cache_age;
    v805[v889] = 0;
    v808 = v889;
  }
  int v901 = (v808 * 2) + (((int)((unsigned int)v707 >> 2)) & 1);
  int v809 = v715[v901];
  int * v810 = v703->regs;
  v810[10] = v809;
  struct StateT * v812 = slot_23(v703);
  return v812;
}

struct StateT * slot_11(struct StateT * v553) {
  int v554 = v553->timer;
  int v561 = v554 + 1;
  v553->timer = v561;
  int * v556 = v553->regs;
  int v557 = v556[11];
  int v564 = v557 + 72;
  v556[11] = v564;
  struct StateT * v559 = slot_13(v553);
  return v559;
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