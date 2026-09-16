// verify: leak (KLEE should report a failing assertion) [budget 1200s]
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
#else
#define koika_assert(b, s) 0
#define koika_assume(b) 0
#define koika_draw(x) ((x) = 0)
#endif
int bounded(int low, int high) {
  int x;
  koika_draw(x);
  koika_assume(low <= x && x <= high);
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

struct StateT * snippet(struct StateT * v0);
struct StateT * slot_1(struct StateT * v19);
struct StateT * slot_6(struct StateT * v1242);
struct StateT * slot_5(struct StateT * v1226);
struct StateT * slot_4(struct StateT * v976);
struct StateT * slot_2(struct StateT * v35);
struct StateT * slot_3(struct StateT * v48);
struct StateT * slot_0(struct StateT * v2);
struct StateT * snippet(struct StateT * v0) {
  struct StateT * v1 = slot_0(v0);
  return v1;
}

struct StateT * slot_1(struct StateT * v19) {
  int v20 = v19->timer;
  int v28 = v20 + 1;
  v19->timer = v28;
  int * v22 = v19->regs;
  int v23 = v22[6];
  int * v24 = v19->regs;
  int v32 = v23 + 80;
  v24[6] = v32;
  struct StateT * v26 = slot_2(v19);
  return v26;
}

struct StateT * slot_6(struct StateT * v1242) {
  int v1243 = v1242->timer;
  int v1375 = v1243 + 1;
  v1242->timer = v1375;
  int * v1245 = v1242->regs;
  int v1246 = v1245[11];
  int * v1247 = v1242->cache_tags;
  int v1379 = (((int)((unsigned int)((int)((unsigned int)v1246 >> 2)) >> 1)) & 1) * 2;
  int v1248 = v1247[v1379];
  int * v1249 = v1242->cache_tags;
  int v1381 = ((((int)((unsigned int)((int)((unsigned int)v1246 >> 2)) >> 1)) & 1) * 2) + 1;
  int v1250 = v1249[v1381];
  int * v1251 = v1242->cache_tags;
  int v1383 = 4 + ((((int)((unsigned int)((int)((unsigned int)v1246 >> 2)) >> 1)) & 3) * 2);
  int v1252 = v1251[v1383];
  int * v1253 = v1242->cache_tags;
  int v1385 = (4 + ((((int)((unsigned int)((int)((unsigned int)v1246 >> 2)) >> 1)) & 3) * 2)) + 1;
  int v1254 = v1253[v1385];
  int v1255 = v1242->timer;
  int v1386 = v1255 + ((100 ^ (((~(((v1252 ^ ((int)((unsigned int)((int)((unsigned int)v1246 >> 2)) >> 1))) | (-(v1252 ^ ((int)((unsigned int)((int)((unsigned int)v1246 >> 2)) >> 1))))) >> 31)) | (~(((v1254 ^ ((int)((unsigned int)((int)((unsigned int)v1246 >> 2)) >> 1))) | (-(v1254 ^ ((int)((unsigned int)((int)((unsigned int)v1246 >> 2)) >> 1))))) >> 31))) & 104)) ^ (((~(((v1248 ^ ((int)((unsigned int)((int)((unsigned int)v1246 >> 2)) >> 1))) | (-(v1248 ^ ((int)((unsigned int)((int)((unsigned int)v1246 >> 2)) >> 1))))) >> 31)) | (~(((v1250 ^ ((int)((unsigned int)((int)((unsigned int)v1246 >> 2)) >> 1))) | (-(v1250 ^ ((int)((unsigned int)((int)((unsigned int)v1246 >> 2)) >> 1))))) >> 31))) & (1 ^ (100 ^ (((~(((v1252 ^ ((int)((unsigned int)((int)((unsigned int)v1246 >> 2)) >> 1))) | (-(v1252 ^ ((int)((unsigned int)((int)((unsigned int)v1246 >> 2)) >> 1))))) >> 31)) | (~(((v1254 ^ ((int)((unsigned int)((int)((unsigned int)v1246 >> 2)) >> 1))) | (-(v1254 ^ ((int)((unsigned int)((int)((unsigned int)v1246 >> 2)) >> 1))))) >> 31))) & 104)))));
  v1242->timer = v1386;
  int * v1257 = v1242->cache_vals;
  bool v1387 = !(((~(((v1248 ^ ((int)((unsigned int)((int)((unsigned int)v1246 >> 2)) >> 1))) | (-(v1248 ^ ((int)((unsigned int)((int)((unsigned int)v1246 >> 2)) >> 1))))) >> 31)) | (~(((v1250 ^ ((int)((unsigned int)((int)((unsigned int)v1246 >> 2)) >> 1))) | (-(v1250 ^ ((int)((unsigned int)((int)((unsigned int)v1246 >> 2)) >> 1))))) >> 31))) == 0);
  int v1370;
  if (v1387) {
    int * v1258 = v1242->cache_age;
    int v1389 = ((((int)((unsigned int)((int)((unsigned int)v1246 >> 2)) >> 1)) & 1) * 2) + ((~(((v1250 ^ ((int)((unsigned int)((int)((unsigned int)v1246 >> 2)) >> 1))) | (-(v1250 ^ ((int)((unsigned int)((int)((unsigned int)v1246 >> 2)) >> 1))))) >> 31)) & 1);
    int v1259 = v1258[v1389];
    int * v1260 = v1242->cache_age;
    int v1261 = v1260[v1379];
    int * v1262 = v1242->cache_age;
    int v1392 = v1261 + ((int)((unsigned int)(v1261 - v1259) >> 31));
    v1262[v1379] = v1392;
    int * v1264 = v1242->cache_age;
    int v1265 = v1264[v1381];
    int * v1266 = v1242->cache_age;
    int v1395 = v1265 + ((int)((unsigned int)(v1265 - v1259) >> 31));
    v1266[v1381] = v1395;
    int * v1268 = v1242->cache_age;
    v1268[v1389] = 0;
    v1370 = v1389;
  } else {
    int * v1271 = v1242->cache_age;
    int v1399 = (((int)((unsigned int)((int)((unsigned int)v1246 >> 2)) >> 1)) & 1) * 2;
    int v1272 = v1271[v1399];
    int * v1273 = v1242->cache_tags;
    int v1274 = v1273[v1399];
    int * v1275 = v1242->cache_age;
    int v1276 = v1275[v1381];
    int * v1277 = v1242->cache_tags;
    int v1278 = v1277[v1381];
    bool v1403 = !(((~(((v1252 ^ ((int)((unsigned int)((int)((unsigned int)v1246 >> 2)) >> 1))) | (-(v1252 ^ ((int)((unsigned int)((int)((unsigned int)v1246 >> 2)) >> 1))))) >> 31)) | (~(((v1254 ^ ((int)((unsigned int)((int)((unsigned int)v1246 >> 2)) >> 1))) | (-(v1254 ^ ((int)((unsigned int)((int)((unsigned int)v1246 >> 2)) >> 1))))) >> 31))) == 0);
    int v1342;
    if (v1403) {
      int * v1279 = v1242->cache_age;
      int v1405 = (4 + ((((int)((unsigned int)((int)((unsigned int)v1246 >> 2)) >> 1)) & 3) * 2)) + ((~(((v1254 ^ ((int)((unsigned int)((int)((unsigned int)v1246 >> 2)) >> 1))) | (-(v1254 ^ ((int)((unsigned int)((int)((unsigned int)v1246 >> 2)) >> 1))))) >> 31)) & 1);
      int v1280 = v1279[v1405];
      int * v1281 = v1242->cache_age;
      int v1282 = v1281[v1383];
      int * v1283 = v1242->cache_age;
      int v1408 = v1282 + ((int)((unsigned int)(v1282 - v1280) >> 31));
      v1283[v1383] = v1408;
      int * v1285 = v1242->cache_age;
      int v1286 = v1285[v1385];
      int * v1287 = v1242->cache_age;
      int v1411 = v1286 + ((int)((unsigned int)(v1286 - v1280) >> 31));
      v1287[v1385] = v1411;
      int * v1289 = v1242->cache_age;
      v1289[v1405] = 0;
      v1342 = v1405;
    } else {
      int * v1292 = v1242->cache_age;
      int v1415 = 4 + ((((int)((unsigned int)((int)((unsigned int)v1246 >> 2)) >> 1)) & 3) * 2);
      int v1293 = v1292[v1415];
      int * v1294 = v1242->cache_tags;
      int v1295 = v1294[v1415];
      int * v1296 = v1242->cache_age;
      int v1297 = v1296[v1385];
      int * v1298 = v1242->cache_tags;
      int v1299 = v1298[v1385];
      int * v1300 = v1242->cache_dirty;
      int v1420 = (4 + ((((int)((unsigned int)((int)((unsigned int)v1246 >> 2)) >> 1)) & 3) * 2)) + ((((v1293 + ((~(((v1295 ^ -1) | (-(v1295 ^ -1))) >> 31)) & 2)) - (v1297 + ((~(((v1299 ^ -1) | (-(v1299 ^ -1))) >> 31)) & 2))) >> 31) & 1);
      int v1301 = v1300[v1420];
      bool v1421 = !(v1301 == 0);
      if (v1421) {
        int * v1302 = v1242->cache_tags;
        int v1303 = v1302[v1420];
        int * v1304 = v1242->cache_vals;
        int v1424 = ((4 + ((((int)((unsigned int)((int)((unsigned int)v1246 >> 2)) >> 1)) & 3) * 2)) + ((((v1293 + ((~(((v1295 ^ -1) | (-(v1295 ^ -1))) >> 31)) & 2)) - (v1297 + ((~(((v1299 ^ -1) | (-(v1299 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
        int v1305 = v1304[v1424];
        int * v1306 = v1242->cache_vals;
        int v1426 = (((4 + ((((int)((unsigned int)((int)((unsigned int)v1246 >> 2)) >> 1)) & 3) * 2)) + ((((v1293 + ((~(((v1295 ^ -1) | (-(v1295 ^ -1))) >> 31)) & 2)) - (v1297 + ((~(((v1299 ^ -1) | (-(v1299 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
        int v1307 = v1306[v1426];
        int * v1308 = v1242->mem;
        int v1428 = v1303 * 2;
        v1308[v1428] = v1305;
        int * v1310 = v1242->mem;
        int v1431 = (v1303 * 2) + 1;
        v1310[v1431] = v1307;
        ;
      } else {
        ;
      }
      int * v1315 = v1242->mem;
      int v1436 = ((int)((unsigned int)((int)((unsigned int)v1246 >> 2)) >> 1)) * 2;
      int v1316 = v1315[v1436];
      int * v1317 = v1242->mem;
      int v1438 = (((int)((unsigned int)((int)((unsigned int)v1246 >> 2)) >> 1)) * 2) + 1;
      int v1318 = v1317[v1438];
      int * v1319 = v1242->cache_vals;
      int v1440 = ((4 + ((((int)((unsigned int)((int)((unsigned int)v1246 >> 2)) >> 1)) & 3) * 2)) + ((((v1293 + ((~(((v1295 ^ -1) | (-(v1295 ^ -1))) >> 31)) & 2)) - (v1297 + ((~(((v1299 ^ -1) | (-(v1299 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
      v1319[v1440] = v1316;
      int * v1321 = v1242->cache_vals;
      int v1443 = (((4 + ((((int)((unsigned int)((int)((unsigned int)v1246 >> 2)) >> 1)) & 3) * 2)) + ((((v1293 + ((~(((v1295 ^ -1) | (-(v1295 ^ -1))) >> 31)) & 2)) - (v1297 + ((~(((v1299 ^ -1) | (-(v1299 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
      v1321[v1443] = v1318;
      int * v1323 = v1242->cache_tags;
      int v1446 = (int)((unsigned int)((int)((unsigned int)v1246 >> 2)) >> 1);
      v1323[v1420] = v1446;
      int * v1325 = v1242->cache_dirty;
      v1325[v1420] = 0;
      int * v1327 = v1242->cache_age;
      v1327[v1420] = 1;
      int * v1329 = v1242->cache_age;
      int v1330 = v1329[v1420];
      int * v1331 = v1242->cache_age;
      int v1332 = v1331[v1383];
      int * v1333 = v1242->cache_age;
      int v1454 = v1332 + ((int)((unsigned int)(v1332 - v1330) >> 31));
      v1333[v1383] = v1454;
      int * v1335 = v1242->cache_age;
      int v1336 = v1335[v1385];
      int * v1337 = v1242->cache_age;
      int v1457 = v1336 + ((int)((unsigned int)(v1336 - v1330) >> 31));
      v1337[v1385] = v1457;
      int * v1339 = v1242->cache_age;
      v1339[v1420] = 0;
      v1342 = v1420;
    }
    int * v1343 = v1242->cache_vals;
    int v1460 = v1342 * 2;
    int v1344 = v1343[v1460];
    int * v1345 = v1242->cache_vals;
    int v1462 = (v1342 * 2) + 1;
    int v1346 = v1345[v1462];
    int * v1347 = v1242->cache_vals;
    int v1464 = (((((int)((unsigned int)((int)((unsigned int)v1246 >> 2)) >> 1)) & 1) * 2) + ((((v1272 + ((~(((v1274 ^ -1) | (-(v1274 ^ -1))) >> 31)) & 2)) - (v1276 + ((~(((v1278 ^ -1) | (-(v1278 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
    v1347[v1464] = v1344;
    int * v1349 = v1242->cache_vals;
    int v1467 = ((((((int)((unsigned int)((int)((unsigned int)v1246 >> 2)) >> 1)) & 1) * 2) + ((((v1272 + ((~(((v1274 ^ -1) | (-(v1274 ^ -1))) >> 31)) & 2)) - (v1276 + ((~(((v1278 ^ -1) | (-(v1278 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
    v1349[v1467] = v1346;
    int * v1351 = v1242->cache_tags;
    int v1470 = ((((int)((unsigned int)((int)((unsigned int)v1246 >> 2)) >> 1)) & 1) * 2) + ((((v1272 + ((~(((v1274 ^ -1) | (-(v1274 ^ -1))) >> 31)) & 2)) - (v1276 + ((~(((v1278 ^ -1) | (-(v1278 ^ -1))) >> 31)) & 2))) >> 31) & 1);
    int v1471 = (int)((unsigned int)((int)((unsigned int)v1246 >> 2)) >> 1);
    v1351[v1470] = v1471;
    int * v1353 = v1242->cache_dirty;
    v1353[v1470] = 0;
    int * v1355 = v1242->cache_age;
    v1355[v1470] = 1;
    int * v1357 = v1242->cache_age;
    int v1358 = v1357[v1470];
    int * v1359 = v1242->cache_age;
    int v1360 = v1359[v1379];
    int * v1361 = v1242->cache_age;
    int v1479 = v1360 + ((int)((unsigned int)(v1360 - v1358) >> 31));
    v1361[v1379] = v1479;
    int * v1363 = v1242->cache_age;
    int v1364 = v1363[v1381];
    int * v1365 = v1242->cache_age;
    int v1482 = v1364 + ((int)((unsigned int)(v1364 - v1358) >> 31));
    v1365[v1381] = v1482;
    int * v1367 = v1242->cache_age;
    v1367[v1470] = 0;
    v1370 = v1470;
  }
  int v1485 = (v1370 * 2) + (((int)((unsigned int)v1246 >> 2)) & 1);
  int v1371 = v1257[v1485];
  int * v1372 = v1242->regs;
  v1372[12] = v1371;
  return v1242;
}

struct StateT * slot_5(struct StateT * v1226) {
  int v1227 = v1226->timer;
  int v1235 = v1227 + 1;
  v1226->timer = v1235;
  int * v1229 = v1226->regs;
  int v1230 = v1229[11];
  int * v1231 = v1226->regs;
  int v1239 = v1230 << 2;
  v1231[11] = v1239;
  struct StateT * v1233 = slot_6(v1226);
  return v1233;
}

struct StateT * slot_4(struct StateT * v976) {
  int v977 = v976->timer;
  int v1110 = v977 + 1;
  v976->timer = v1110;
  int * v979 = v976->regs;
  int v980 = v979[6];
  int * v981 = v976->cache_tags;
  int v1114 = (((int)((unsigned int)((int)((unsigned int)v980 >> 2)) >> 1)) & 1) * 2;
  int v982 = v981[v1114];
  int * v983 = v976->cache_tags;
  int v1116 = ((((int)((unsigned int)((int)((unsigned int)v980 >> 2)) >> 1)) & 1) * 2) + 1;
  int v984 = v983[v1116];
  int * v985 = v976->cache_tags;
  int v1118 = 4 + ((((int)((unsigned int)((int)((unsigned int)v980 >> 2)) >> 1)) & 3) * 2);
  int v986 = v985[v1118];
  int * v987 = v976->cache_tags;
  int v1120 = (4 + ((((int)((unsigned int)((int)((unsigned int)v980 >> 2)) >> 1)) & 3) * 2)) + 1;
  int v988 = v987[v1120];
  int v989 = v976->timer;
  int v1121 = v989 + ((100 ^ (((~(((v986 ^ ((int)((unsigned int)((int)((unsigned int)v980 >> 2)) >> 1))) | (-(v986 ^ ((int)((unsigned int)((int)((unsigned int)v980 >> 2)) >> 1))))) >> 31)) | (~(((v988 ^ ((int)((unsigned int)((int)((unsigned int)v980 >> 2)) >> 1))) | (-(v988 ^ ((int)((unsigned int)((int)((unsigned int)v980 >> 2)) >> 1))))) >> 31))) & 104)) ^ (((~(((v982 ^ ((int)((unsigned int)((int)((unsigned int)v980 >> 2)) >> 1))) | (-(v982 ^ ((int)((unsigned int)((int)((unsigned int)v980 >> 2)) >> 1))))) >> 31)) | (~(((v984 ^ ((int)((unsigned int)((int)((unsigned int)v980 >> 2)) >> 1))) | (-(v984 ^ ((int)((unsigned int)((int)((unsigned int)v980 >> 2)) >> 1))))) >> 31))) & (1 ^ (100 ^ (((~(((v986 ^ ((int)((unsigned int)((int)((unsigned int)v980 >> 2)) >> 1))) | (-(v986 ^ ((int)((unsigned int)((int)((unsigned int)v980 >> 2)) >> 1))))) >> 31)) | (~(((v988 ^ ((int)((unsigned int)((int)((unsigned int)v980 >> 2)) >> 1))) | (-(v988 ^ ((int)((unsigned int)((int)((unsigned int)v980 >> 2)) >> 1))))) >> 31))) & 104)))));
  v976->timer = v1121;
  int * v991 = v976->cache_vals;
  bool v1122 = !(((~(((v982 ^ ((int)((unsigned int)((int)((unsigned int)v980 >> 2)) >> 1))) | (-(v982 ^ ((int)((unsigned int)((int)((unsigned int)v980 >> 2)) >> 1))))) >> 31)) | (~(((v984 ^ ((int)((unsigned int)((int)((unsigned int)v980 >> 2)) >> 1))) | (-(v984 ^ ((int)((unsigned int)((int)((unsigned int)v980 >> 2)) >> 1))))) >> 31))) == 0);
  int v1104;
  if (v1122) {
    int * v992 = v976->cache_age;
    int v1124 = ((((int)((unsigned int)((int)((unsigned int)v980 >> 2)) >> 1)) & 1) * 2) + ((~(((v984 ^ ((int)((unsigned int)((int)((unsigned int)v980 >> 2)) >> 1))) | (-(v984 ^ ((int)((unsigned int)((int)((unsigned int)v980 >> 2)) >> 1))))) >> 31)) & 1);
    int v993 = v992[v1124];
    int * v994 = v976->cache_age;
    int v995 = v994[v1114];
    int * v996 = v976->cache_age;
    int v1127 = v995 + ((int)((unsigned int)(v995 - v993) >> 31));
    v996[v1114] = v1127;
    int * v998 = v976->cache_age;
    int v999 = v998[v1116];
    int * v1000 = v976->cache_age;
    int v1130 = v999 + ((int)((unsigned int)(v999 - v993) >> 31));
    v1000[v1116] = v1130;
    int * v1002 = v976->cache_age;
    v1002[v1124] = 0;
    v1104 = v1124;
  } else {
    int * v1005 = v976->cache_age;
    int v1134 = (((int)((unsigned int)((int)((unsigned int)v980 >> 2)) >> 1)) & 1) * 2;
    int v1006 = v1005[v1134];
    int * v1007 = v976->cache_tags;
    int v1008 = v1007[v1134];
    int * v1009 = v976->cache_age;
    int v1010 = v1009[v1116];
    int * v1011 = v976->cache_tags;
    int v1012 = v1011[v1116];
    bool v1138 = !(((~(((v986 ^ ((int)((unsigned int)((int)((unsigned int)v980 >> 2)) >> 1))) | (-(v986 ^ ((int)((unsigned int)((int)((unsigned int)v980 >> 2)) >> 1))))) >> 31)) | (~(((v988 ^ ((int)((unsigned int)((int)((unsigned int)v980 >> 2)) >> 1))) | (-(v988 ^ ((int)((unsigned int)((int)((unsigned int)v980 >> 2)) >> 1))))) >> 31))) == 0);
    int v1076;
    if (v1138) {
      int * v1013 = v976->cache_age;
      int v1140 = (4 + ((((int)((unsigned int)((int)((unsigned int)v980 >> 2)) >> 1)) & 3) * 2)) + ((~(((v988 ^ ((int)((unsigned int)((int)((unsigned int)v980 >> 2)) >> 1))) | (-(v988 ^ ((int)((unsigned int)((int)((unsigned int)v980 >> 2)) >> 1))))) >> 31)) & 1);
      int v1014 = v1013[v1140];
      int * v1015 = v976->cache_age;
      int v1016 = v1015[v1118];
      int * v1017 = v976->cache_age;
      int v1143 = v1016 + ((int)((unsigned int)(v1016 - v1014) >> 31));
      v1017[v1118] = v1143;
      int * v1019 = v976->cache_age;
      int v1020 = v1019[v1120];
      int * v1021 = v976->cache_age;
      int v1146 = v1020 + ((int)((unsigned int)(v1020 - v1014) >> 31));
      v1021[v1120] = v1146;
      int * v1023 = v976->cache_age;
      v1023[v1140] = 0;
      v1076 = v1140;
    } else {
      int * v1026 = v976->cache_age;
      int v1150 = 4 + ((((int)((unsigned int)((int)((unsigned int)v980 >> 2)) >> 1)) & 3) * 2);
      int v1027 = v1026[v1150];
      int * v1028 = v976->cache_tags;
      int v1029 = v1028[v1150];
      int * v1030 = v976->cache_age;
      int v1031 = v1030[v1120];
      int * v1032 = v976->cache_tags;
      int v1033 = v1032[v1120];
      int * v1034 = v976->cache_dirty;
      int v1155 = (4 + ((((int)((unsigned int)((int)((unsigned int)v980 >> 2)) >> 1)) & 3) * 2)) + ((((v1027 + ((~(((v1029 ^ -1) | (-(v1029 ^ -1))) >> 31)) & 2)) - (v1031 + ((~(((v1033 ^ -1) | (-(v1033 ^ -1))) >> 31)) & 2))) >> 31) & 1);
      int v1035 = v1034[v1155];
      bool v1156 = !(v1035 == 0);
      if (v1156) {
        int * v1036 = v976->cache_tags;
        int v1037 = v1036[v1155];
        int * v1038 = v976->cache_vals;
        int v1159 = ((4 + ((((int)((unsigned int)((int)((unsigned int)v980 >> 2)) >> 1)) & 3) * 2)) + ((((v1027 + ((~(((v1029 ^ -1) | (-(v1029 ^ -1))) >> 31)) & 2)) - (v1031 + ((~(((v1033 ^ -1) | (-(v1033 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
        int v1039 = v1038[v1159];
        int * v1040 = v976->cache_vals;
        int v1161 = (((4 + ((((int)((unsigned int)((int)((unsigned int)v980 >> 2)) >> 1)) & 3) * 2)) + ((((v1027 + ((~(((v1029 ^ -1) | (-(v1029 ^ -1))) >> 31)) & 2)) - (v1031 + ((~(((v1033 ^ -1) | (-(v1033 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
        int v1041 = v1040[v1161];
        int * v1042 = v976->mem;
        int v1163 = v1037 * 2;
        v1042[v1163] = v1039;
        int * v1044 = v976->mem;
        int v1166 = (v1037 * 2) + 1;
        v1044[v1166] = v1041;
        ;
      } else {
        ;
      }
      int * v1049 = v976->mem;
      int v1171 = ((int)((unsigned int)((int)((unsigned int)v980 >> 2)) >> 1)) * 2;
      int v1050 = v1049[v1171];
      int * v1051 = v976->mem;
      int v1173 = (((int)((unsigned int)((int)((unsigned int)v980 >> 2)) >> 1)) * 2) + 1;
      int v1052 = v1051[v1173];
      int * v1053 = v976->cache_vals;
      int v1175 = ((4 + ((((int)((unsigned int)((int)((unsigned int)v980 >> 2)) >> 1)) & 3) * 2)) + ((((v1027 + ((~(((v1029 ^ -1) | (-(v1029 ^ -1))) >> 31)) & 2)) - (v1031 + ((~(((v1033 ^ -1) | (-(v1033 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
      v1053[v1175] = v1050;
      int * v1055 = v976->cache_vals;
      int v1178 = (((4 + ((((int)((unsigned int)((int)((unsigned int)v980 >> 2)) >> 1)) & 3) * 2)) + ((((v1027 + ((~(((v1029 ^ -1) | (-(v1029 ^ -1))) >> 31)) & 2)) - (v1031 + ((~(((v1033 ^ -1) | (-(v1033 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
      v1055[v1178] = v1052;
      int * v1057 = v976->cache_tags;
      int v1181 = (int)((unsigned int)((int)((unsigned int)v980 >> 2)) >> 1);
      v1057[v1155] = v1181;
      int * v1059 = v976->cache_dirty;
      v1059[v1155] = 0;
      int * v1061 = v976->cache_age;
      v1061[v1155] = 1;
      int * v1063 = v976->cache_age;
      int v1064 = v1063[v1155];
      int * v1065 = v976->cache_age;
      int v1066 = v1065[v1118];
      int * v1067 = v976->cache_age;
      int v1189 = v1066 + ((int)((unsigned int)(v1066 - v1064) >> 31));
      v1067[v1118] = v1189;
      int * v1069 = v976->cache_age;
      int v1070 = v1069[v1120];
      int * v1071 = v976->cache_age;
      int v1192 = v1070 + ((int)((unsigned int)(v1070 - v1064) >> 31));
      v1071[v1120] = v1192;
      int * v1073 = v976->cache_age;
      v1073[v1155] = 0;
      v1076 = v1155;
    }
    int * v1077 = v976->cache_vals;
    int v1195 = v1076 * 2;
    int v1078 = v1077[v1195];
    int * v1079 = v976->cache_vals;
    int v1197 = (v1076 * 2) + 1;
    int v1080 = v1079[v1197];
    int * v1081 = v976->cache_vals;
    int v1199 = (((((int)((unsigned int)((int)((unsigned int)v980 >> 2)) >> 1)) & 1) * 2) + ((((v1006 + ((~(((v1008 ^ -1) | (-(v1008 ^ -1))) >> 31)) & 2)) - (v1010 + ((~(((v1012 ^ -1) | (-(v1012 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
    v1081[v1199] = v1078;
    int * v1083 = v976->cache_vals;
    int v1202 = ((((((int)((unsigned int)((int)((unsigned int)v980 >> 2)) >> 1)) & 1) * 2) + ((((v1006 + ((~(((v1008 ^ -1) | (-(v1008 ^ -1))) >> 31)) & 2)) - (v1010 + ((~(((v1012 ^ -1) | (-(v1012 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
    v1083[v1202] = v1080;
    int * v1085 = v976->cache_tags;
    int v1205 = ((((int)((unsigned int)((int)((unsigned int)v980 >> 2)) >> 1)) & 1) * 2) + ((((v1006 + ((~(((v1008 ^ -1) | (-(v1008 ^ -1))) >> 31)) & 2)) - (v1010 + ((~(((v1012 ^ -1) | (-(v1012 ^ -1))) >> 31)) & 2))) >> 31) & 1);
    int v1206 = (int)((unsigned int)((int)((unsigned int)v980 >> 2)) >> 1);
    v1085[v1205] = v1206;
    int * v1087 = v976->cache_dirty;
    v1087[v1205] = 0;
    int * v1089 = v976->cache_age;
    v1089[v1205] = 1;
    int * v1091 = v976->cache_age;
    int v1092 = v1091[v1205];
    int * v1093 = v976->cache_age;
    int v1094 = v1093[v1114];
    int * v1095 = v976->cache_age;
    int v1214 = v1094 + ((int)((unsigned int)(v1094 - v1092) >> 31));
    v1095[v1114] = v1214;
    int * v1097 = v976->cache_age;
    int v1098 = v1097[v1116];
    int * v1099 = v976->cache_age;
    int v1217 = v1098 + ((int)((unsigned int)(v1098 - v1092) >> 31));
    v1099[v1116] = v1217;
    int * v1101 = v976->cache_age;
    v1101[v1205] = 0;
    v1104 = v1205;
  }
  int v1220 = (v1104 * 2) + (((int)((unsigned int)v980 >> 2)) & 1);
  int v1105 = v991[v1220];
  int * v1106 = v976->regs;
  v1106[11] = v1105;
  struct StateT * v1108 = slot_5(v976);
  return v1108;
}

struct StateT * slot_2(struct StateT * v35) {
  int v36 = v35->timer;
  int v42 = v36 + 1;
  v35->timer = v42;
  int * v38 = v35->regs;
  v38[7] = 0;
  struct StateT * v40 = slot_3(v35);
  return v40;
}

struct StateT * slot_3(struct StateT * v48) {
  int v49 = v48->timer;
  int v548 = v49 + 1;
  v48->timer = v548;
  int * v51 = v48->regs;
  int v52 = v51[6];
  int * v53 = v48->regs;
  int v54 = v53[7];
  int * v55 = v48->saved_regs;
  int * v56 = v48->regs;
  int v57 = v56[11];
  v55[11] = v57;
  int v59 = v48->timer;
  int v557 = v59 + 1;
  v48->timer = v557;
  int * v61 = v48->regs;
  int v62 = v61[6];
  int * v63 = v48->cache_tags;
  int v560 = (((int)((unsigned int)((int)((unsigned int)v62 >> 2)) >> 1)) & 1) * 2;
  int v64 = v63[v560];
  int * v65 = v48->cache_tags;
  int v562 = ((((int)((unsigned int)((int)((unsigned int)v62 >> 2)) >> 1)) & 1) * 2) + 1;
  int v66 = v65[v562];
  int * v67 = v48->cache_tags;
  int v564 = 4 + ((((int)((unsigned int)((int)((unsigned int)v62 >> 2)) >> 1)) & 3) * 2);
  int v68 = v67[v564];
  int * v69 = v48->cache_tags;
  int v566 = (4 + ((((int)((unsigned int)((int)((unsigned int)v62 >> 2)) >> 1)) & 3) * 2)) + 1;
  int v70 = v69[v566];
  int v71 = v48->timer;
  int v567 = v71 + ((100 ^ (((~(((v68 ^ ((int)((unsigned int)((int)((unsigned int)v62 >> 2)) >> 1))) | (-(v68 ^ ((int)((unsigned int)((int)((unsigned int)v62 >> 2)) >> 1))))) >> 31)) | (~(((v70 ^ ((int)((unsigned int)((int)((unsigned int)v62 >> 2)) >> 1))) | (-(v70 ^ ((int)((unsigned int)((int)((unsigned int)v62 >> 2)) >> 1))))) >> 31))) & 104)) ^ (((~(((v64 ^ ((int)((unsigned int)((int)((unsigned int)v62 >> 2)) >> 1))) | (-(v64 ^ ((int)((unsigned int)((int)((unsigned int)v62 >> 2)) >> 1))))) >> 31)) | (~(((v66 ^ ((int)((unsigned int)((int)((unsigned int)v62 >> 2)) >> 1))) | (-(v66 ^ ((int)((unsigned int)((int)((unsigned int)v62 >> 2)) >> 1))))) >> 31))) & (1 ^ (100 ^ (((~(((v68 ^ ((int)((unsigned int)((int)((unsigned int)v62 >> 2)) >> 1))) | (-(v68 ^ ((int)((unsigned int)((int)((unsigned int)v62 >> 2)) >> 1))))) >> 31)) | (~(((v70 ^ ((int)((unsigned int)((int)((unsigned int)v62 >> 2)) >> 1))) | (-(v70 ^ ((int)((unsigned int)((int)((unsigned int)v62 >> 2)) >> 1))))) >> 31))) & 104)))));
  v48->timer = v567;
  int * v73 = v48->cache_vals;
  bool v568 = !(((~(((v64 ^ ((int)((unsigned int)((int)((unsigned int)v62 >> 2)) >> 1))) | (-(v64 ^ ((int)((unsigned int)((int)((unsigned int)v62 >> 2)) >> 1))))) >> 31)) | (~(((v66 ^ ((int)((unsigned int)((int)((unsigned int)v62 >> 2)) >> 1))) | (-(v66 ^ ((int)((unsigned int)((int)((unsigned int)v62 >> 2)) >> 1))))) >> 31))) == 0);
  int v186;
  if (v568) {
    int * v74 = v48->cache_age;
    int v570 = ((((int)((unsigned int)((int)((unsigned int)v62 >> 2)) >> 1)) & 1) * 2) + ((~(((v66 ^ ((int)((unsigned int)((int)((unsigned int)v62 >> 2)) >> 1))) | (-(v66 ^ ((int)((unsigned int)((int)((unsigned int)v62 >> 2)) >> 1))))) >> 31)) & 1);
    int v75 = v74[v570];
    int * v76 = v48->cache_age;
    int v77 = v76[v560];
    int * v78 = v48->cache_age;
    int v573 = v77 + ((int)((unsigned int)(v77 - v75) >> 31));
    v78[v560] = v573;
    int * v80 = v48->cache_age;
    int v81 = v80[v562];
    int * v82 = v48->cache_age;
    int v576 = v81 + ((int)((unsigned int)(v81 - v75) >> 31));
    v82[v562] = v576;
    int * v84 = v48->cache_age;
    v84[v570] = 0;
    v186 = v570;
  } else {
    int * v87 = v48->cache_age;
    int v580 = (((int)((unsigned int)((int)((unsigned int)v62 >> 2)) >> 1)) & 1) * 2;
    int v88 = v87[v580];
    int * v89 = v48->cache_tags;
    int v90 = v89[v580];
    int * v91 = v48->cache_age;
    int v92 = v91[v562];
    int * v93 = v48->cache_tags;
    int v94 = v93[v562];
    bool v584 = !(((~(((v68 ^ ((int)((unsigned int)((int)((unsigned int)v62 >> 2)) >> 1))) | (-(v68 ^ ((int)((unsigned int)((int)((unsigned int)v62 >> 2)) >> 1))))) >> 31)) | (~(((v70 ^ ((int)((unsigned int)((int)((unsigned int)v62 >> 2)) >> 1))) | (-(v70 ^ ((int)((unsigned int)((int)((unsigned int)v62 >> 2)) >> 1))))) >> 31))) == 0);
    int v158;
    if (v584) {
      int * v95 = v48->cache_age;
      int v586 = (4 + ((((int)((unsigned int)((int)((unsigned int)v62 >> 2)) >> 1)) & 3) * 2)) + ((~(((v70 ^ ((int)((unsigned int)((int)((unsigned int)v62 >> 2)) >> 1))) | (-(v70 ^ ((int)((unsigned int)((int)((unsigned int)v62 >> 2)) >> 1))))) >> 31)) & 1);
      int v96 = v95[v586];
      int * v97 = v48->cache_age;
      int v98 = v97[v564];
      int * v99 = v48->cache_age;
      int v589 = v98 + ((int)((unsigned int)(v98 - v96) >> 31));
      v99[v564] = v589;
      int * v101 = v48->cache_age;
      int v102 = v101[v566];
      int * v103 = v48->cache_age;
      int v592 = v102 + ((int)((unsigned int)(v102 - v96) >> 31));
      v103[v566] = v592;
      int * v105 = v48->cache_age;
      v105[v586] = 0;
      v158 = v586;
    } else {
      int * v108 = v48->cache_age;
      int v596 = 4 + ((((int)((unsigned int)((int)((unsigned int)v62 >> 2)) >> 1)) & 3) * 2);
      int v109 = v108[v596];
      int * v110 = v48->cache_tags;
      int v111 = v110[v596];
      int * v112 = v48->cache_age;
      int v113 = v112[v566];
      int * v114 = v48->cache_tags;
      int v115 = v114[v566];
      int * v116 = v48->cache_dirty;
      int v601 = (4 + ((((int)((unsigned int)((int)((unsigned int)v62 >> 2)) >> 1)) & 3) * 2)) + ((((v109 + ((~(((v111 ^ -1) | (-(v111 ^ -1))) >> 31)) & 2)) - (v113 + ((~(((v115 ^ -1) | (-(v115 ^ -1))) >> 31)) & 2))) >> 31) & 1);
      int v117 = v116[v601];
      bool v602 = !(v117 == 0);
      if (v602) {
        int * v118 = v48->cache_tags;
        int v119 = v118[v601];
        int * v120 = v48->cache_vals;
        int v605 = ((4 + ((((int)((unsigned int)((int)((unsigned int)v62 >> 2)) >> 1)) & 3) * 2)) + ((((v109 + ((~(((v111 ^ -1) | (-(v111 ^ -1))) >> 31)) & 2)) - (v113 + ((~(((v115 ^ -1) | (-(v115 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
        int v121 = v120[v605];
        int * v122 = v48->cache_vals;
        int v607 = (((4 + ((((int)((unsigned int)((int)((unsigned int)v62 >> 2)) >> 1)) & 3) * 2)) + ((((v109 + ((~(((v111 ^ -1) | (-(v111 ^ -1))) >> 31)) & 2)) - (v113 + ((~(((v115 ^ -1) | (-(v115 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
        int v123 = v122[v607];
        int * v124 = v48->mem;
        int v609 = v119 * 2;
        v124[v609] = v121;
        int * v126 = v48->mem;
        int v612 = (v119 * 2) + 1;
        v126[v612] = v123;
        ;
      } else {
        ;
      }
      int * v131 = v48->mem;
      int v617 = ((int)((unsigned int)((int)((unsigned int)v62 >> 2)) >> 1)) * 2;
      int v132 = v131[v617];
      int * v133 = v48->mem;
      int v619 = (((int)((unsigned int)((int)((unsigned int)v62 >> 2)) >> 1)) * 2) + 1;
      int v134 = v133[v619];
      int * v135 = v48->cache_vals;
      int v621 = ((4 + ((((int)((unsigned int)((int)((unsigned int)v62 >> 2)) >> 1)) & 3) * 2)) + ((((v109 + ((~(((v111 ^ -1) | (-(v111 ^ -1))) >> 31)) & 2)) - (v113 + ((~(((v115 ^ -1) | (-(v115 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
      v135[v621] = v132;
      int * v137 = v48->cache_vals;
      int v624 = (((4 + ((((int)((unsigned int)((int)((unsigned int)v62 >> 2)) >> 1)) & 3) * 2)) + ((((v109 + ((~(((v111 ^ -1) | (-(v111 ^ -1))) >> 31)) & 2)) - (v113 + ((~(((v115 ^ -1) | (-(v115 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
      v137[v624] = v134;
      int * v139 = v48->cache_tags;
      int v627 = (int)((unsigned int)((int)((unsigned int)v62 >> 2)) >> 1);
      v139[v601] = v627;
      int * v141 = v48->cache_dirty;
      v141[v601] = 0;
      int * v143 = v48->cache_age;
      v143[v601] = 1;
      int * v145 = v48->cache_age;
      int v146 = v145[v601];
      int * v147 = v48->cache_age;
      int v148 = v147[v564];
      int * v149 = v48->cache_age;
      int v635 = v148 + ((int)((unsigned int)(v148 - v146) >> 31));
      v149[v564] = v635;
      int * v151 = v48->cache_age;
      int v152 = v151[v566];
      int * v153 = v48->cache_age;
      int v638 = v152 + ((int)((unsigned int)(v152 - v146) >> 31));
      v153[v566] = v638;
      int * v155 = v48->cache_age;
      v155[v601] = 0;
      v158 = v601;
    }
    int * v159 = v48->cache_vals;
    int v641 = v158 * 2;
    int v160 = v159[v641];
    int * v161 = v48->cache_vals;
    int v643 = (v158 * 2) + 1;
    int v162 = v161[v643];
    int * v163 = v48->cache_vals;
    int v645 = (((((int)((unsigned int)((int)((unsigned int)v62 >> 2)) >> 1)) & 1) * 2) + ((((v88 + ((~(((v90 ^ -1) | (-(v90 ^ -1))) >> 31)) & 2)) - (v92 + ((~(((v94 ^ -1) | (-(v94 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
    v163[v645] = v160;
    int * v165 = v48->cache_vals;
    int v648 = ((((((int)((unsigned int)((int)((unsigned int)v62 >> 2)) >> 1)) & 1) * 2) + ((((v88 + ((~(((v90 ^ -1) | (-(v90 ^ -1))) >> 31)) & 2)) - (v92 + ((~(((v94 ^ -1) | (-(v94 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
    v165[v648] = v162;
    int * v167 = v48->cache_tags;
    int v651 = ((((int)((unsigned int)((int)((unsigned int)v62 >> 2)) >> 1)) & 1) * 2) + ((((v88 + ((~(((v90 ^ -1) | (-(v90 ^ -1))) >> 31)) & 2)) - (v92 + ((~(((v94 ^ -1) | (-(v94 ^ -1))) >> 31)) & 2))) >> 31) & 1);
    int v652 = (int)((unsigned int)((int)((unsigned int)v62 >> 2)) >> 1);
    v167[v651] = v652;
    int * v169 = v48->cache_dirty;
    v169[v651] = 0;
    int * v171 = v48->cache_age;
    v171[v651] = 1;
    int * v173 = v48->cache_age;
    int v174 = v173[v651];
    int * v175 = v48->cache_age;
    int v176 = v175[v560];
    int * v177 = v48->cache_age;
    int v660 = v176 + ((int)((unsigned int)(v176 - v174) >> 31));
    v177[v560] = v660;
    int * v179 = v48->cache_age;
    int v180 = v179[v562];
    int * v181 = v48->cache_age;
    int v663 = v180 + ((int)((unsigned int)(v180 - v174) >> 31));
    v181[v562] = v663;
    int * v183 = v48->cache_age;
    v183[v651] = 0;
    v186 = v651;
  }
  int v666 = (v186 * 2) + (((int)((unsigned int)v62 >> 2)) & 1);
  int v187 = v73[v666];
  int * v188 = v48->regs;
  v188[11] = v187;
  int v190 = v48->timer;
  int v669 = v190 + 1;
  v48->timer = v669;
  int * v192 = v48->regs;
  int v193 = v192[11];
  int * v194 = v48->regs;
  int v672 = v193 << 2;
  v194[11] = v672;
  int * v196 = v48->saved_regs;
  int * v197 = v48->regs;
  int v198 = v197[12];
  v196[12] = v198;
  int v200 = v48->timer;
  int v677 = v200 + 1;
  v48->timer = v677;
  int * v202 = v48->regs;
  int v203 = v202[11];
  bool v679 = (((int)((unsigned int)v52 >> 2)) & 3) == (((int)((unsigned int)v203 >> 2)) & 3);
  int v333;
  if (v679) {
    int v204 = v48->timer;
    int v680 = v204 + 1;
    v48->timer = v680;
    v333 = v54;
  } else {
    int * v207 = v48->cache_tags;
    int v683 = (((int)((unsigned int)((int)((unsigned int)v203 >> 2)) >> 1)) & 1) * 2;
    int v208 = v207[v683];
    int * v209 = v48->cache_tags;
    int v685 = ((((int)((unsigned int)((int)((unsigned int)v203 >> 2)) >> 1)) & 1) * 2) + 1;
    int v210 = v209[v685];
    int * v211 = v48->cache_tags;
    int v687 = 4 + ((((int)((unsigned int)((int)((unsigned int)v203 >> 2)) >> 1)) & 3) * 2);
    int v212 = v211[v687];
    int * v213 = v48->cache_tags;
    int v689 = (4 + ((((int)((unsigned int)((int)((unsigned int)v203 >> 2)) >> 1)) & 3) * 2)) + 1;
    int v214 = v213[v689];
    int v215 = v48->timer;
    int v690 = v215 + ((100 ^ (((~(((v212 ^ ((int)((unsigned int)((int)((unsigned int)v203 >> 2)) >> 1))) | (-(v212 ^ ((int)((unsigned int)((int)((unsigned int)v203 >> 2)) >> 1))))) >> 31)) | (~(((v214 ^ ((int)((unsigned int)((int)((unsigned int)v203 >> 2)) >> 1))) | (-(v214 ^ ((int)((unsigned int)((int)((unsigned int)v203 >> 2)) >> 1))))) >> 31))) & 104)) ^ (((~(((v208 ^ ((int)((unsigned int)((int)((unsigned int)v203 >> 2)) >> 1))) | (-(v208 ^ ((int)((unsigned int)((int)((unsigned int)v203 >> 2)) >> 1))))) >> 31)) | (~(((v210 ^ ((int)((unsigned int)((int)((unsigned int)v203 >> 2)) >> 1))) | (-(v210 ^ ((int)((unsigned int)((int)((unsigned int)v203 >> 2)) >> 1))))) >> 31))) & (1 ^ (100 ^ (((~(((v212 ^ ((int)((unsigned int)((int)((unsigned int)v203 >> 2)) >> 1))) | (-(v212 ^ ((int)((unsigned int)((int)((unsigned int)v203 >> 2)) >> 1))))) >> 31)) | (~(((v214 ^ ((int)((unsigned int)((int)((unsigned int)v203 >> 2)) >> 1))) | (-(v214 ^ ((int)((unsigned int)((int)((unsigned int)v203 >> 2)) >> 1))))) >> 31))) & 104)))));
    v48->timer = v690;
    int * v217 = v48->cache_vals;
    bool v691 = !(((~(((v208 ^ ((int)((unsigned int)((int)((unsigned int)v203 >> 2)) >> 1))) | (-(v208 ^ ((int)((unsigned int)((int)((unsigned int)v203 >> 2)) >> 1))))) >> 31)) | (~(((v210 ^ ((int)((unsigned int)((int)((unsigned int)v203 >> 2)) >> 1))) | (-(v210 ^ ((int)((unsigned int)((int)((unsigned int)v203 >> 2)) >> 1))))) >> 31))) == 0);
    int v330;
    if (v691) {
      int * v218 = v48->cache_age;
      int v693 = ((((int)((unsigned int)((int)((unsigned int)v203 >> 2)) >> 1)) & 1) * 2) + ((~(((v210 ^ ((int)((unsigned int)((int)((unsigned int)v203 >> 2)) >> 1))) | (-(v210 ^ ((int)((unsigned int)((int)((unsigned int)v203 >> 2)) >> 1))))) >> 31)) & 1);
      int v219 = v218[v693];
      int * v220 = v48->cache_age;
      int v221 = v220[v683];
      int * v222 = v48->cache_age;
      int v696 = v221 + ((int)((unsigned int)(v221 - v219) >> 31));
      v222[v683] = v696;
      int * v224 = v48->cache_age;
      int v225 = v224[v685];
      int * v226 = v48->cache_age;
      int v699 = v225 + ((int)((unsigned int)(v225 - v219) >> 31));
      v226[v685] = v699;
      int * v228 = v48->cache_age;
      v228[v693] = 0;
      v330 = v693;
    } else {
      int * v231 = v48->cache_age;
      int v703 = (((int)((unsigned int)((int)((unsigned int)v203 >> 2)) >> 1)) & 1) * 2;
      int v232 = v231[v703];
      int * v233 = v48->cache_tags;
      int v234 = v233[v703];
      int * v235 = v48->cache_age;
      int v236 = v235[v685];
      int * v237 = v48->cache_tags;
      int v238 = v237[v685];
      bool v707 = !(((~(((v212 ^ ((int)((unsigned int)((int)((unsigned int)v203 >> 2)) >> 1))) | (-(v212 ^ ((int)((unsigned int)((int)((unsigned int)v203 >> 2)) >> 1))))) >> 31)) | (~(((v214 ^ ((int)((unsigned int)((int)((unsigned int)v203 >> 2)) >> 1))) | (-(v214 ^ ((int)((unsigned int)((int)((unsigned int)v203 >> 2)) >> 1))))) >> 31))) == 0);
      int v302;
      if (v707) {
        int * v239 = v48->cache_age;
        int v709 = (4 + ((((int)((unsigned int)((int)((unsigned int)v203 >> 2)) >> 1)) & 3) * 2)) + ((~(((v214 ^ ((int)((unsigned int)((int)((unsigned int)v203 >> 2)) >> 1))) | (-(v214 ^ ((int)((unsigned int)((int)((unsigned int)v203 >> 2)) >> 1))))) >> 31)) & 1);
        int v240 = v239[v709];
        int * v241 = v48->cache_age;
        int v242 = v241[v687];
        int * v243 = v48->cache_age;
        int v712 = v242 + ((int)((unsigned int)(v242 - v240) >> 31));
        v243[v687] = v712;
        int * v245 = v48->cache_age;
        int v246 = v245[v689];
        int * v247 = v48->cache_age;
        int v715 = v246 + ((int)((unsigned int)(v246 - v240) >> 31));
        v247[v689] = v715;
        int * v249 = v48->cache_age;
        v249[v709] = 0;
        v302 = v709;
      } else {
        int * v252 = v48->cache_age;
        int v719 = 4 + ((((int)((unsigned int)((int)((unsigned int)v203 >> 2)) >> 1)) & 3) * 2);
        int v253 = v252[v719];
        int * v254 = v48->cache_tags;
        int v255 = v254[v719];
        int * v256 = v48->cache_age;
        int v257 = v256[v689];
        int * v258 = v48->cache_tags;
        int v259 = v258[v689];
        int * v260 = v48->cache_dirty;
        int v724 = (4 + ((((int)((unsigned int)((int)((unsigned int)v203 >> 2)) >> 1)) & 3) * 2)) + ((((v253 + ((~(((v255 ^ -1) | (-(v255 ^ -1))) >> 31)) & 2)) - (v257 + ((~(((v259 ^ -1) | (-(v259 ^ -1))) >> 31)) & 2))) >> 31) & 1);
        int v261 = v260[v724];
        bool v725 = !(v261 == 0);
        if (v725) {
          int * v262 = v48->cache_tags;
          int v263 = v262[v724];
          int * v264 = v48->cache_vals;
          int v728 = ((4 + ((((int)((unsigned int)((int)((unsigned int)v203 >> 2)) >> 1)) & 3) * 2)) + ((((v253 + ((~(((v255 ^ -1) | (-(v255 ^ -1))) >> 31)) & 2)) - (v257 + ((~(((v259 ^ -1) | (-(v259 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
          int v265 = v264[v728];
          int * v266 = v48->cache_vals;
          int v730 = (((4 + ((((int)((unsigned int)((int)((unsigned int)v203 >> 2)) >> 1)) & 3) * 2)) + ((((v253 + ((~(((v255 ^ -1) | (-(v255 ^ -1))) >> 31)) & 2)) - (v257 + ((~(((v259 ^ -1) | (-(v259 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
          int v267 = v266[v730];
          int * v268 = v48->mem;
          int v732 = v263 * 2;
          v268[v732] = v265;
          int * v270 = v48->mem;
          int v735 = (v263 * 2) + 1;
          v270[v735] = v267;
          ;
        } else {
          ;
        }
        int * v275 = v48->mem;
        int v740 = ((int)((unsigned int)((int)((unsigned int)v203 >> 2)) >> 1)) * 2;
        int v276 = v275[v740];
        int * v277 = v48->mem;
        int v742 = (((int)((unsigned int)((int)((unsigned int)v203 >> 2)) >> 1)) * 2) + 1;
        int v278 = v277[v742];
        int * v279 = v48->cache_vals;
        int v744 = ((4 + ((((int)((unsigned int)((int)((unsigned int)v203 >> 2)) >> 1)) & 3) * 2)) + ((((v253 + ((~(((v255 ^ -1) | (-(v255 ^ -1))) >> 31)) & 2)) - (v257 + ((~(((v259 ^ -1) | (-(v259 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
        v279[v744] = v276;
        int * v281 = v48->cache_vals;
        int v747 = (((4 + ((((int)((unsigned int)((int)((unsigned int)v203 >> 2)) >> 1)) & 3) * 2)) + ((((v253 + ((~(((v255 ^ -1) | (-(v255 ^ -1))) >> 31)) & 2)) - (v257 + ((~(((v259 ^ -1) | (-(v259 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
        v281[v747] = v278;
        int * v283 = v48->cache_tags;
        int v750 = (int)((unsigned int)((int)((unsigned int)v203 >> 2)) >> 1);
        v283[v724] = v750;
        int * v285 = v48->cache_dirty;
        v285[v724] = 0;
        int * v287 = v48->cache_age;
        v287[v724] = 1;
        int * v289 = v48->cache_age;
        int v290 = v289[v724];
        int * v291 = v48->cache_age;
        int v292 = v291[v687];
        int * v293 = v48->cache_age;
        int v758 = v292 + ((int)((unsigned int)(v292 - v290) >> 31));
        v293[v687] = v758;
        int * v295 = v48->cache_age;
        int v296 = v295[v689];
        int * v297 = v48->cache_age;
        int v761 = v296 + ((int)((unsigned int)(v296 - v290) >> 31));
        v297[v689] = v761;
        int * v299 = v48->cache_age;
        v299[v724] = 0;
        v302 = v724;
      }
      int * v303 = v48->cache_vals;
      int v764 = v302 * 2;
      int v304 = v303[v764];
      int * v305 = v48->cache_vals;
      int v766 = (v302 * 2) + 1;
      int v306 = v305[v766];
      int * v307 = v48->cache_vals;
      int v768 = (((((int)((unsigned int)((int)((unsigned int)v203 >> 2)) >> 1)) & 1) * 2) + ((((v232 + ((~(((v234 ^ -1) | (-(v234 ^ -1))) >> 31)) & 2)) - (v236 + ((~(((v238 ^ -1) | (-(v238 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
      v307[v768] = v304;
      int * v309 = v48->cache_vals;
      int v771 = ((((((int)((unsigned int)((int)((unsigned int)v203 >> 2)) >> 1)) & 1) * 2) + ((((v232 + ((~(((v234 ^ -1) | (-(v234 ^ -1))) >> 31)) & 2)) - (v236 + ((~(((v238 ^ -1) | (-(v238 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
      v309[v771] = v306;
      int * v311 = v48->cache_tags;
      int v774 = ((((int)((unsigned int)((int)((unsigned int)v203 >> 2)) >> 1)) & 1) * 2) + ((((v232 + ((~(((v234 ^ -1) | (-(v234 ^ -1))) >> 31)) & 2)) - (v236 + ((~(((v238 ^ -1) | (-(v238 ^ -1))) >> 31)) & 2))) >> 31) & 1);
      int v775 = (int)((unsigned int)((int)((unsigned int)v203 >> 2)) >> 1);
      v311[v774] = v775;
      int * v313 = v48->cache_dirty;
      v313[v774] = 0;
      int * v315 = v48->cache_age;
      v315[v774] = 1;
      int * v317 = v48->cache_age;
      int v318 = v317[v774];
      int * v319 = v48->cache_age;
      int v320 = v319[v683];
      int * v321 = v48->cache_age;
      int v783 = v320 + ((int)((unsigned int)(v320 - v318) >> 31));
      v321[v683] = v783;
      int * v323 = v48->cache_age;
      int v324 = v323[v685];
      int * v325 = v48->cache_age;
      int v786 = v324 + ((int)((unsigned int)(v324 - v318) >> 31));
      v325[v685] = v786;
      int * v327 = v48->cache_age;
      v327[v774] = 0;
      v330 = v774;
    }
    int v789 = (v330 * 2) + (((int)((unsigned int)v203 >> 2)) & 1);
    int v331 = v217[v789];
    v333 = v331;
  }
  int * v334 = v48->regs;
  v334[12] = v333;
  int * v336 = v48->cache_tags;
  int v794 = (((int)((unsigned int)((int)((unsigned int)v52 >> 2)) >> 1)) & 1) * 2;
  int v337 = v336[v794];
  int * v338 = v48->cache_tags;
  int v796 = ((((int)((unsigned int)((int)((unsigned int)v52 >> 2)) >> 1)) & 1) * 2) + 1;
  int v339 = v338[v796];
  int * v340 = v48->cache_tags;
  int v798 = 4 + ((((int)((unsigned int)((int)((unsigned int)v52 >> 2)) >> 1)) & 3) * 2);
  int v341 = v340[v798];
  int * v342 = v48->cache_tags;
  int v800 = (4 + ((((int)((unsigned int)((int)((unsigned int)v52 >> 2)) >> 1)) & 3) * 2)) + 1;
  int v343 = v342[v800];
  int v344 = v48->timer;
  int v801 = v344 + ((100 ^ (((~(((v341 ^ ((int)((unsigned int)((int)((unsigned int)v52 >> 2)) >> 1))) | (-(v341 ^ ((int)((unsigned int)((int)((unsigned int)v52 >> 2)) >> 1))))) >> 31)) | (~(((v343 ^ ((int)((unsigned int)((int)((unsigned int)v52 >> 2)) >> 1))) | (-(v343 ^ ((int)((unsigned int)((int)((unsigned int)v52 >> 2)) >> 1))))) >> 31))) & 104)) ^ (((~(((v337 ^ ((int)((unsigned int)((int)((unsigned int)v52 >> 2)) >> 1))) | (-(v337 ^ ((int)((unsigned int)((int)((unsigned int)v52 >> 2)) >> 1))))) >> 31)) | (~(((v339 ^ ((int)((unsigned int)((int)((unsigned int)v52 >> 2)) >> 1))) | (-(v339 ^ ((int)((unsigned int)((int)((unsigned int)v52 >> 2)) >> 1))))) >> 31))) & (1 ^ (100 ^ (((~(((v341 ^ ((int)((unsigned int)((int)((unsigned int)v52 >> 2)) >> 1))) | (-(v341 ^ ((int)((unsigned int)((int)((unsigned int)v52 >> 2)) >> 1))))) >> 31)) | (~(((v343 ^ ((int)((unsigned int)((int)((unsigned int)v52 >> 2)) >> 1))) | (-(v343 ^ ((int)((unsigned int)((int)((unsigned int)v52 >> 2)) >> 1))))) >> 31))) & 104)))));
  v48->timer = v801;
  bool v802 = !(((~(((v337 ^ ((int)((unsigned int)((int)((unsigned int)v52 >> 2)) >> 1))) | (-(v337 ^ ((int)((unsigned int)((int)((unsigned int)v52 >> 2)) >> 1))))) >> 31)) | (~(((v339 ^ ((int)((unsigned int)((int)((unsigned int)v52 >> 2)) >> 1))) | (-(v339 ^ ((int)((unsigned int)((int)((unsigned int)v52 >> 2)) >> 1))))) >> 31))) == 0);
  int v458;
  if (v802) {
    int * v346 = v48->cache_age;
    int v804 = ((((int)((unsigned int)((int)((unsigned int)v52 >> 2)) >> 1)) & 1) * 2) + ((~(((v339 ^ ((int)((unsigned int)((int)((unsigned int)v52 >> 2)) >> 1))) | (-(v339 ^ ((int)((unsigned int)((int)((unsigned int)v52 >> 2)) >> 1))))) >> 31)) & 1);
    int v347 = v346[v804];
    int * v348 = v48->cache_age;
    int v349 = v348[v794];
    int * v350 = v48->cache_age;
    int v807 = v349 + ((int)((unsigned int)(v349 - v347) >> 31));
    v350[v794] = v807;
    int * v352 = v48->cache_age;
    int v353 = v352[v796];
    int * v354 = v48->cache_age;
    int v810 = v353 + ((int)((unsigned int)(v353 - v347) >> 31));
    v354[v796] = v810;
    int * v356 = v48->cache_age;
    v356[v804] = 0;
    v458 = v804;
  } else {
    int * v359 = v48->cache_age;
    int v814 = (((int)((unsigned int)((int)((unsigned int)v52 >> 2)) >> 1)) & 1) * 2;
    int v360 = v359[v814];
    int * v361 = v48->cache_tags;
    int v362 = v361[v814];
    int * v363 = v48->cache_age;
    int v364 = v363[v796];
    int * v365 = v48->cache_tags;
    int v366 = v365[v796];
    bool v818 = !(((~(((v341 ^ ((int)((unsigned int)((int)((unsigned int)v52 >> 2)) >> 1))) | (-(v341 ^ ((int)((unsigned int)((int)((unsigned int)v52 >> 2)) >> 1))))) >> 31)) | (~(((v343 ^ ((int)((unsigned int)((int)((unsigned int)v52 >> 2)) >> 1))) | (-(v343 ^ ((int)((unsigned int)((int)((unsigned int)v52 >> 2)) >> 1))))) >> 31))) == 0);
    int v430;
    if (v818) {
      int * v367 = v48->cache_age;
      int v820 = (4 + ((((int)((unsigned int)((int)((unsigned int)v52 >> 2)) >> 1)) & 3) * 2)) + ((~(((v343 ^ ((int)((unsigned int)((int)((unsigned int)v52 >> 2)) >> 1))) | (-(v343 ^ ((int)((unsigned int)((int)((unsigned int)v52 >> 2)) >> 1))))) >> 31)) & 1);
      int v368 = v367[v820];
      int * v369 = v48->cache_age;
      int v370 = v369[v798];
      int * v371 = v48->cache_age;
      int v823 = v370 + ((int)((unsigned int)(v370 - v368) >> 31));
      v371[v798] = v823;
      int * v373 = v48->cache_age;
      int v374 = v373[v800];
      int * v375 = v48->cache_age;
      int v826 = v374 + ((int)((unsigned int)(v374 - v368) >> 31));
      v375[v800] = v826;
      int * v377 = v48->cache_age;
      v377[v820] = 0;
      v430 = v820;
    } else {
      int * v380 = v48->cache_age;
      int v830 = 4 + ((((int)((unsigned int)((int)((unsigned int)v52 >> 2)) >> 1)) & 3) * 2);
      int v381 = v380[v830];
      int * v382 = v48->cache_tags;
      int v383 = v382[v830];
      int * v384 = v48->cache_age;
      int v385 = v384[v800];
      int * v386 = v48->cache_tags;
      int v387 = v386[v800];
      int * v388 = v48->cache_dirty;
      int v835 = (4 + ((((int)((unsigned int)((int)((unsigned int)v52 >> 2)) >> 1)) & 3) * 2)) + ((((v381 + ((~(((v383 ^ -1) | (-(v383 ^ -1))) >> 31)) & 2)) - (v385 + ((~(((v387 ^ -1) | (-(v387 ^ -1))) >> 31)) & 2))) >> 31) & 1);
      int v389 = v388[v835];
      bool v836 = !(v389 == 0);
      if (v836) {
        int * v390 = v48->cache_tags;
        int v391 = v390[v835];
        int * v392 = v48->cache_vals;
        int v839 = ((4 + ((((int)((unsigned int)((int)((unsigned int)v52 >> 2)) >> 1)) & 3) * 2)) + ((((v381 + ((~(((v383 ^ -1) | (-(v383 ^ -1))) >> 31)) & 2)) - (v385 + ((~(((v387 ^ -1) | (-(v387 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
        int v393 = v392[v839];
        int * v394 = v48->cache_vals;
        int v841 = (((4 + ((((int)((unsigned int)((int)((unsigned int)v52 >> 2)) >> 1)) & 3) * 2)) + ((((v381 + ((~(((v383 ^ -1) | (-(v383 ^ -1))) >> 31)) & 2)) - (v385 + ((~(((v387 ^ -1) | (-(v387 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
        int v395 = v394[v841];
        int * v396 = v48->mem;
        int v843 = v391 * 2;
        v396[v843] = v393;
        int * v398 = v48->mem;
        int v846 = (v391 * 2) + 1;
        v398[v846] = v395;
        ;
      } else {
        ;
      }
      int * v403 = v48->mem;
      int v851 = ((int)((unsigned int)((int)((unsigned int)v52 >> 2)) >> 1)) * 2;
      int v404 = v403[v851];
      int * v405 = v48->mem;
      int v853 = (((int)((unsigned int)((int)((unsigned int)v52 >> 2)) >> 1)) * 2) + 1;
      int v406 = v405[v853];
      int * v407 = v48->cache_vals;
      int v855 = ((4 + ((((int)((unsigned int)((int)((unsigned int)v52 >> 2)) >> 1)) & 3) * 2)) + ((((v381 + ((~(((v383 ^ -1) | (-(v383 ^ -1))) >> 31)) & 2)) - (v385 + ((~(((v387 ^ -1) | (-(v387 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
      v407[v855] = v404;
      int * v409 = v48->cache_vals;
      int v858 = (((4 + ((((int)((unsigned int)((int)((unsigned int)v52 >> 2)) >> 1)) & 3) * 2)) + ((((v381 + ((~(((v383 ^ -1) | (-(v383 ^ -1))) >> 31)) & 2)) - (v385 + ((~(((v387 ^ -1) | (-(v387 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
      v409[v858] = v406;
      int * v411 = v48->cache_tags;
      int v861 = (int)((unsigned int)((int)((unsigned int)v52 >> 2)) >> 1);
      v411[v835] = v861;
      int * v413 = v48->cache_dirty;
      v413[v835] = 0;
      int * v415 = v48->cache_age;
      v415[v835] = 1;
      int * v417 = v48->cache_age;
      int v418 = v417[v835];
      int * v419 = v48->cache_age;
      int v420 = v419[v798];
      int * v421 = v48->cache_age;
      int v869 = v420 + ((int)((unsigned int)(v420 - v418) >> 31));
      v421[v798] = v869;
      int * v423 = v48->cache_age;
      int v424 = v423[v800];
      int * v425 = v48->cache_age;
      int v872 = v424 + ((int)((unsigned int)(v424 - v418) >> 31));
      v425[v800] = v872;
      int * v427 = v48->cache_age;
      v427[v835] = 0;
      v430 = v835;
    }
    int * v431 = v48->cache_vals;
    int v875 = v430 * 2;
    int v432 = v431[v875];
    int * v433 = v48->cache_vals;
    int v877 = (v430 * 2) + 1;
    int v434 = v433[v877];
    int * v435 = v48->cache_vals;
    int v879 = (((((int)((unsigned int)((int)((unsigned int)v52 >> 2)) >> 1)) & 1) * 2) + ((((v360 + ((~(((v362 ^ -1) | (-(v362 ^ -1))) >> 31)) & 2)) - (v364 + ((~(((v366 ^ -1) | (-(v366 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
    v435[v879] = v432;
    int * v437 = v48->cache_vals;
    int v882 = ((((((int)((unsigned int)((int)((unsigned int)v52 >> 2)) >> 1)) & 1) * 2) + ((((v360 + ((~(((v362 ^ -1) | (-(v362 ^ -1))) >> 31)) & 2)) - (v364 + ((~(((v366 ^ -1) | (-(v366 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
    v437[v882] = v434;
    int * v439 = v48->cache_tags;
    int v885 = ((((int)((unsigned int)((int)((unsigned int)v52 >> 2)) >> 1)) & 1) * 2) + ((((v360 + ((~(((v362 ^ -1) | (-(v362 ^ -1))) >> 31)) & 2)) - (v364 + ((~(((v366 ^ -1) | (-(v366 ^ -1))) >> 31)) & 2))) >> 31) & 1);
    int v886 = (int)((unsigned int)((int)((unsigned int)v52 >> 2)) >> 1);
    v439[v885] = v886;
    int * v441 = v48->cache_dirty;
    v441[v885] = 0;
    int * v443 = v48->cache_age;
    v443[v885] = 1;
    int * v445 = v48->cache_age;
    int v446 = v445[v885];
    int * v447 = v48->cache_age;
    int v448 = v447[v794];
    int * v449 = v48->cache_age;
    int v894 = v448 + ((int)((unsigned int)(v448 - v446) >> 31));
    v449[v794] = v894;
    int * v451 = v48->cache_age;
    int v452 = v451[v796];
    int * v453 = v48->cache_age;
    int v897 = v452 + ((int)((unsigned int)(v452 - v446) >> 31));
    v453[v796] = v897;
    int * v455 = v48->cache_age;
    v455[v885] = 0;
    v458 = v885;
  }
  int * v459 = v48->cache_vals;
  int v900 = (v458 * 2) + (((int)((unsigned int)v52 >> 2)) & 1);
  v459[v900] = v54;
  int * v461 = v48->cache_tags;
  int v462 = v461[v798];
  int * v463 = v48->cache_tags;
  int v464 = v463[v800];
  bool v904 = !(((~(((v462 ^ ((int)((unsigned int)((int)((unsigned int)v52 >> 2)) >> 1))) | (-(v462 ^ ((int)((unsigned int)((int)((unsigned int)v52 >> 2)) >> 1))))) >> 31)) | (~(((v464 ^ ((int)((unsigned int)((int)((unsigned int)v52 >> 2)) >> 1))) | (-(v464 ^ ((int)((unsigned int)((int)((unsigned int)v52 >> 2)) >> 1))))) >> 31))) == 0);
  int v528;
  if (v904) {
    int * v465 = v48->cache_age;
    int v906 = (4 + ((((int)((unsigned int)((int)((unsigned int)v52 >> 2)) >> 1)) & 3) * 2)) + ((~(((v464 ^ ((int)((unsigned int)((int)((unsigned int)v52 >> 2)) >> 1))) | (-(v464 ^ ((int)((unsigned int)((int)((unsigned int)v52 >> 2)) >> 1))))) >> 31)) & 1);
    int v466 = v465[v906];
    int * v467 = v48->cache_age;
    int v468 = v467[v798];
    int * v469 = v48->cache_age;
    int v909 = v468 + ((int)((unsigned int)(v468 - v466) >> 31));
    v469[v798] = v909;
    int * v471 = v48->cache_age;
    int v472 = v471[v800];
    int * v473 = v48->cache_age;
    int v912 = v472 + ((int)((unsigned int)(v472 - v466) >> 31));
    v473[v800] = v912;
    int * v475 = v48->cache_age;
    v475[v906] = 0;
    v528 = v906;
  } else {
    int * v478 = v48->cache_age;
    int v916 = 4 + ((((int)((unsigned int)((int)((unsigned int)v52 >> 2)) >> 1)) & 3) * 2);
    int v479 = v478[v916];
    int * v480 = v48->cache_tags;
    int v481 = v480[v916];
    int * v482 = v48->cache_age;
    int v483 = v482[v800];
    int * v484 = v48->cache_tags;
    int v485 = v484[v800];
    int * v486 = v48->cache_dirty;
    int v921 = (4 + ((((int)((unsigned int)((int)((unsigned int)v52 >> 2)) >> 1)) & 3) * 2)) + ((((v479 + ((~(((v481 ^ -1) | (-(v481 ^ -1))) >> 31)) & 2)) - (v483 + ((~(((v485 ^ -1) | (-(v485 ^ -1))) >> 31)) & 2))) >> 31) & 1);
    int v487 = v486[v921];
    bool v922 = !(v487 == 0);
    if (v922) {
      int * v488 = v48->cache_tags;
      int v489 = v488[v921];
      int * v490 = v48->cache_vals;
      int v925 = ((4 + ((((int)((unsigned int)((int)((unsigned int)v52 >> 2)) >> 1)) & 3) * 2)) + ((((v479 + ((~(((v481 ^ -1) | (-(v481 ^ -1))) >> 31)) & 2)) - (v483 + ((~(((v485 ^ -1) | (-(v485 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
      int v491 = v490[v925];
      int * v492 = v48->cache_vals;
      int v927 = (((4 + ((((int)((unsigned int)((int)((unsigned int)v52 >> 2)) >> 1)) & 3) * 2)) + ((((v479 + ((~(((v481 ^ -1) | (-(v481 ^ -1))) >> 31)) & 2)) - (v483 + ((~(((v485 ^ -1) | (-(v485 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
      int v493 = v492[v927];
      int * v494 = v48->mem;
      int v929 = v489 * 2;
      v494[v929] = v491;
      int * v496 = v48->mem;
      int v932 = (v489 * 2) + 1;
      v496[v932] = v493;
      ;
    } else {
      ;
    }
    int * v501 = v48->mem;
    int v937 = ((int)((unsigned int)((int)((unsigned int)v52 >> 2)) >> 1)) * 2;
    int v502 = v501[v937];
    int * v503 = v48->mem;
    int v939 = (((int)((unsigned int)((int)((unsigned int)v52 >> 2)) >> 1)) * 2) + 1;
    int v504 = v503[v939];
    int * v505 = v48->cache_vals;
    int v941 = ((4 + ((((int)((unsigned int)((int)((unsigned int)v52 >> 2)) >> 1)) & 3) * 2)) + ((((v479 + ((~(((v481 ^ -1) | (-(v481 ^ -1))) >> 31)) & 2)) - (v483 + ((~(((v485 ^ -1) | (-(v485 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
    v505[v941] = v502;
    int * v507 = v48->cache_vals;
    int v944 = (((4 + ((((int)((unsigned int)((int)((unsigned int)v52 >> 2)) >> 1)) & 3) * 2)) + ((((v479 + ((~(((v481 ^ -1) | (-(v481 ^ -1))) >> 31)) & 2)) - (v483 + ((~(((v485 ^ -1) | (-(v485 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
    v507[v944] = v504;
    int * v509 = v48->cache_tags;
    int v947 = (int)((unsigned int)((int)((unsigned int)v52 >> 2)) >> 1);
    v509[v921] = v947;
    int * v511 = v48->cache_dirty;
    v511[v921] = 0;
    int * v513 = v48->cache_age;
    v513[v921] = 1;
    int * v515 = v48->cache_age;
    int v516 = v515[v921];
    int * v517 = v48->cache_age;
    int v518 = v517[v798];
    int * v519 = v48->cache_age;
    int v955 = v518 + ((int)((unsigned int)(v518 - v516) >> 31));
    v519[v798] = v955;
    int * v521 = v48->cache_age;
    int v522 = v521[v800];
    int * v523 = v48->cache_age;
    int v958 = v522 + ((int)((unsigned int)(v522 - v516) >> 31));
    v523[v800] = v958;
    int * v525 = v48->cache_age;
    v525[v921] = 0;
    v528 = v921;
  }
  int * v529 = v48->cache_vals;
  int v961 = (v528 * 2) + (((int)((unsigned int)v52 >> 2)) & 1);
  v529[v961] = v54;
  int * v531 = v48->cache_dirty;
  v531[v528] = 1;
  bool v965 = (((int)((unsigned int)v62 >> 2)) == ((int)((unsigned int)v52 >> 2))) | (((((int)((unsigned int)v203 >> 2)) & 3) == (((int)((unsigned int)v52 >> 2)) & 3)) & (!(((int)((unsigned int)v203 >> 2)) == ((int)((unsigned int)v52 >> 2)))));
  struct StateT * v546;
  if (v965) {
    int v533 = v48->timer;
    int v966 = v533 + 15;
    v48->timer = v966;
    int * v535 = v48->saved_regs;
    int v536 = v535[11];
    int * v537 = v48->regs;
    v537[11] = v536;
    int * v539 = v48->saved_regs;
    int v540 = v539[12];
    int * v541 = v48->regs;
    v541[12] = v540;
    struct StateT * v543 = slot_4(v48);
    v546 = v543;
  } else {
    v546 = v48;
  }
  return v546;
}

struct StateT * slot_0(struct StateT * v2) {
  int v3 = v2->timer;
  int v11 = v3 + 1;
  v2->timer = v11;
  int * v5 = v2->regs;
  int v6 = v5[10];
  int * v7 = v2->regs;
  int v16 = v6 & 28;
  v7[6] = v16;
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
    s1.mem[SECRET_OFFSET+i] = bounded(0, 20);
    s2.mem[SECRET_OFFSET+i] = bounded(0, 20);
  }
  struct StateT *s1_ = snippet(&s1);
  struct StateT *s2_ = snippet(&s2);
  koika_assert(s1_->timer==s2_->timer, "timing leak");
  return 0;
}