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
  int cache_tags[12];
  int cache_dirty[12];
  int cache_age[12];
  int cache_vals[24];
  int timer;
};

struct StateT * snippet(struct StateT * v0);
struct StateT * slot_1(struct StateT * v19);
struct StateT * slot_8(struct StateT * v1273);
struct StateT * slot_6(struct StateT * v1007);
struct StateT * slot_2(struct StateT * v32);
struct StateT * slot_7(struct StateT * v1257);
struct StateT * slot_0(struct StateT * v2);
struct StateT * snippet(struct StateT * v0) {
  struct StateT * v1 = slot_0(v0);
  return v1;
}

struct StateT * slot_1(struct StateT * v19) {
  int v20 = v19->timer;
  int v26 = v20 + 1;
  v19->timer = v26;
  int * v22 = v19->regs;
  v22[9] = 32;
  struct StateT * v24 = slot_2(v19);
  return v24;
}

struct StateT * slot_8(struct StateT * v1273) {
  int v1274 = v1273->timer;
  int v1406 = v1274 + 1;
  v1273->timer = v1406;
  int * v1276 = v1273->regs;
  int v1277 = v1276[11];
  int * v1278 = v1273->cache_tags;
  int v1410 = (((int)((unsigned int)((int)((unsigned int)v1277 >> 2)) >> 1)) & 1) * 2;
  int v1279 = v1278[v1410];
  int * v1280 = v1273->cache_tags;
  int v1412 = ((((int)((unsigned int)((int)((unsigned int)v1277 >> 2)) >> 1)) & 1) * 2) + 1;
  int v1281 = v1280[v1412];
  int * v1282 = v1273->cache_tags;
  int v1414 = 4 + ((((int)((unsigned int)((int)((unsigned int)v1277 >> 2)) >> 1)) & 3) * 2);
  int v1283 = v1282[v1414];
  int * v1284 = v1273->cache_tags;
  int v1416 = (4 + ((((int)((unsigned int)((int)((unsigned int)v1277 >> 2)) >> 1)) & 3) * 2)) + 1;
  int v1285 = v1284[v1416];
  int v1286 = v1273->timer;
  int v1417 = v1286 + ((100 ^ (((~(((v1283 ^ ((int)((unsigned int)((int)((unsigned int)v1277 >> 2)) >> 1))) | (-(v1283 ^ ((int)((unsigned int)((int)((unsigned int)v1277 >> 2)) >> 1))))) >> 31)) | (~(((v1285 ^ ((int)((unsigned int)((int)((unsigned int)v1277 >> 2)) >> 1))) | (-(v1285 ^ ((int)((unsigned int)((int)((unsigned int)v1277 >> 2)) >> 1))))) >> 31))) & 104)) ^ (((~(((v1279 ^ ((int)((unsigned int)((int)((unsigned int)v1277 >> 2)) >> 1))) | (-(v1279 ^ ((int)((unsigned int)((int)((unsigned int)v1277 >> 2)) >> 1))))) >> 31)) | (~(((v1281 ^ ((int)((unsigned int)((int)((unsigned int)v1277 >> 2)) >> 1))) | (-(v1281 ^ ((int)((unsigned int)((int)((unsigned int)v1277 >> 2)) >> 1))))) >> 31))) & (1 ^ (100 ^ (((~(((v1283 ^ ((int)((unsigned int)((int)((unsigned int)v1277 >> 2)) >> 1))) | (-(v1283 ^ ((int)((unsigned int)((int)((unsigned int)v1277 >> 2)) >> 1))))) >> 31)) | (~(((v1285 ^ ((int)((unsigned int)((int)((unsigned int)v1277 >> 2)) >> 1))) | (-(v1285 ^ ((int)((unsigned int)((int)((unsigned int)v1277 >> 2)) >> 1))))) >> 31))) & 104)))));
  v1273->timer = v1417;
  int * v1288 = v1273->cache_vals;
  bool v1418 = !(((~(((v1279 ^ ((int)((unsigned int)((int)((unsigned int)v1277 >> 2)) >> 1))) | (-(v1279 ^ ((int)((unsigned int)((int)((unsigned int)v1277 >> 2)) >> 1))))) >> 31)) | (~(((v1281 ^ ((int)((unsigned int)((int)((unsigned int)v1277 >> 2)) >> 1))) | (-(v1281 ^ ((int)((unsigned int)((int)((unsigned int)v1277 >> 2)) >> 1))))) >> 31))) == 0);
  int v1401;
  if (v1418) {
    int * v1289 = v1273->cache_age;
    int v1420 = ((((int)((unsigned int)((int)((unsigned int)v1277 >> 2)) >> 1)) & 1) * 2) + ((~(((v1281 ^ ((int)((unsigned int)((int)((unsigned int)v1277 >> 2)) >> 1))) | (-(v1281 ^ ((int)((unsigned int)((int)((unsigned int)v1277 >> 2)) >> 1))))) >> 31)) & 1);
    int v1290 = v1289[v1420];
    int * v1291 = v1273->cache_age;
    int v1292 = v1291[v1410];
    int * v1293 = v1273->cache_age;
    int v1423 = v1292 + ((int)((unsigned int)(v1292 - v1290) >> 31));
    v1293[v1410] = v1423;
    int * v1295 = v1273->cache_age;
    int v1296 = v1295[v1412];
    int * v1297 = v1273->cache_age;
    int v1426 = v1296 + ((int)((unsigned int)(v1296 - v1290) >> 31));
    v1297[v1412] = v1426;
    int * v1299 = v1273->cache_age;
    v1299[v1420] = 0;
    v1401 = v1420;
  } else {
    int * v1302 = v1273->cache_age;
    int v1430 = (((int)((unsigned int)((int)((unsigned int)v1277 >> 2)) >> 1)) & 1) * 2;
    int v1303 = v1302[v1430];
    int * v1304 = v1273->cache_tags;
    int v1305 = v1304[v1430];
    int * v1306 = v1273->cache_age;
    int v1307 = v1306[v1412];
    int * v1308 = v1273->cache_tags;
    int v1309 = v1308[v1412];
    bool v1434 = !(((~(((v1283 ^ ((int)((unsigned int)((int)((unsigned int)v1277 >> 2)) >> 1))) | (-(v1283 ^ ((int)((unsigned int)((int)((unsigned int)v1277 >> 2)) >> 1))))) >> 31)) | (~(((v1285 ^ ((int)((unsigned int)((int)((unsigned int)v1277 >> 2)) >> 1))) | (-(v1285 ^ ((int)((unsigned int)((int)((unsigned int)v1277 >> 2)) >> 1))))) >> 31))) == 0);
    int v1373;
    if (v1434) {
      int * v1310 = v1273->cache_age;
      int v1436 = (4 + ((((int)((unsigned int)((int)((unsigned int)v1277 >> 2)) >> 1)) & 3) * 2)) + ((~(((v1285 ^ ((int)((unsigned int)((int)((unsigned int)v1277 >> 2)) >> 1))) | (-(v1285 ^ ((int)((unsigned int)((int)((unsigned int)v1277 >> 2)) >> 1))))) >> 31)) & 1);
      int v1311 = v1310[v1436];
      int * v1312 = v1273->cache_age;
      int v1313 = v1312[v1414];
      int * v1314 = v1273->cache_age;
      int v1439 = v1313 + ((int)((unsigned int)(v1313 - v1311) >> 31));
      v1314[v1414] = v1439;
      int * v1316 = v1273->cache_age;
      int v1317 = v1316[v1416];
      int * v1318 = v1273->cache_age;
      int v1442 = v1317 + ((int)((unsigned int)(v1317 - v1311) >> 31));
      v1318[v1416] = v1442;
      int * v1320 = v1273->cache_age;
      v1320[v1436] = 0;
      v1373 = v1436;
    } else {
      int * v1323 = v1273->cache_age;
      int v1446 = 4 + ((((int)((unsigned int)((int)((unsigned int)v1277 >> 2)) >> 1)) & 3) * 2);
      int v1324 = v1323[v1446];
      int * v1325 = v1273->cache_tags;
      int v1326 = v1325[v1446];
      int * v1327 = v1273->cache_age;
      int v1328 = v1327[v1416];
      int * v1329 = v1273->cache_tags;
      int v1330 = v1329[v1416];
      int * v1331 = v1273->cache_dirty;
      int v1451 = (4 + ((((int)((unsigned int)((int)((unsigned int)v1277 >> 2)) >> 1)) & 3) * 2)) + ((((v1324 + ((~(((v1326 ^ -1) | (-(v1326 ^ -1))) >> 31)) & 2)) - (v1328 + ((~(((v1330 ^ -1) | (-(v1330 ^ -1))) >> 31)) & 2))) >> 31) & 1);
      int v1332 = v1331[v1451];
      bool v1452 = !(v1332 == 0);
      if (v1452) {
        int * v1333 = v1273->cache_tags;
        int v1334 = v1333[v1451];
        int * v1335 = v1273->cache_vals;
        int v1455 = ((4 + ((((int)((unsigned int)((int)((unsigned int)v1277 >> 2)) >> 1)) & 3) * 2)) + ((((v1324 + ((~(((v1326 ^ -1) | (-(v1326 ^ -1))) >> 31)) & 2)) - (v1328 + ((~(((v1330 ^ -1) | (-(v1330 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
        int v1336 = v1335[v1455];
        int * v1337 = v1273->cache_vals;
        int v1457 = (((4 + ((((int)((unsigned int)((int)((unsigned int)v1277 >> 2)) >> 1)) & 3) * 2)) + ((((v1324 + ((~(((v1326 ^ -1) | (-(v1326 ^ -1))) >> 31)) & 2)) - (v1328 + ((~(((v1330 ^ -1) | (-(v1330 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
        int v1338 = v1337[v1457];
        int * v1339 = v1273->mem;
        int v1459 = v1334 * 2;
        v1339[v1459] = v1336;
        int * v1341 = v1273->mem;
        int v1462 = (v1334 * 2) + 1;
        v1341[v1462] = v1338;
        ;
      } else {
        ;
      }
      int * v1346 = v1273->mem;
      int v1467 = ((int)((unsigned int)((int)((unsigned int)v1277 >> 2)) >> 1)) * 2;
      int v1347 = v1346[v1467];
      int * v1348 = v1273->mem;
      int v1469 = (((int)((unsigned int)((int)((unsigned int)v1277 >> 2)) >> 1)) * 2) + 1;
      int v1349 = v1348[v1469];
      int * v1350 = v1273->cache_vals;
      int v1471 = ((4 + ((((int)((unsigned int)((int)((unsigned int)v1277 >> 2)) >> 1)) & 3) * 2)) + ((((v1324 + ((~(((v1326 ^ -1) | (-(v1326 ^ -1))) >> 31)) & 2)) - (v1328 + ((~(((v1330 ^ -1) | (-(v1330 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
      v1350[v1471] = v1347;
      int * v1352 = v1273->cache_vals;
      int v1474 = (((4 + ((((int)((unsigned int)((int)((unsigned int)v1277 >> 2)) >> 1)) & 3) * 2)) + ((((v1324 + ((~(((v1326 ^ -1) | (-(v1326 ^ -1))) >> 31)) & 2)) - (v1328 + ((~(((v1330 ^ -1) | (-(v1330 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
      v1352[v1474] = v1349;
      int * v1354 = v1273->cache_tags;
      int v1477 = (int)((unsigned int)((int)((unsigned int)v1277 >> 2)) >> 1);
      v1354[v1451] = v1477;
      int * v1356 = v1273->cache_dirty;
      v1356[v1451] = 0;
      int * v1358 = v1273->cache_age;
      v1358[v1451] = 1;
      int * v1360 = v1273->cache_age;
      int v1361 = v1360[v1451];
      int * v1362 = v1273->cache_age;
      int v1363 = v1362[v1414];
      int * v1364 = v1273->cache_age;
      int v1485 = v1363 + ((int)((unsigned int)(v1363 - v1361) >> 31));
      v1364[v1414] = v1485;
      int * v1366 = v1273->cache_age;
      int v1367 = v1366[v1416];
      int * v1368 = v1273->cache_age;
      int v1488 = v1367 + ((int)((unsigned int)(v1367 - v1361) >> 31));
      v1368[v1416] = v1488;
      int * v1370 = v1273->cache_age;
      v1370[v1451] = 0;
      v1373 = v1451;
    }
    int * v1374 = v1273->cache_vals;
    int v1491 = v1373 * 2;
    int v1375 = v1374[v1491];
    int * v1376 = v1273->cache_vals;
    int v1493 = (v1373 * 2) + 1;
    int v1377 = v1376[v1493];
    int * v1378 = v1273->cache_vals;
    int v1495 = (((((int)((unsigned int)((int)((unsigned int)v1277 >> 2)) >> 1)) & 1) * 2) + ((((v1303 + ((~(((v1305 ^ -1) | (-(v1305 ^ -1))) >> 31)) & 2)) - (v1307 + ((~(((v1309 ^ -1) | (-(v1309 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
    v1378[v1495] = v1375;
    int * v1380 = v1273->cache_vals;
    int v1498 = ((((((int)((unsigned int)((int)((unsigned int)v1277 >> 2)) >> 1)) & 1) * 2) + ((((v1303 + ((~(((v1305 ^ -1) | (-(v1305 ^ -1))) >> 31)) & 2)) - (v1307 + ((~(((v1309 ^ -1) | (-(v1309 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
    v1380[v1498] = v1377;
    int * v1382 = v1273->cache_tags;
    int v1501 = ((((int)((unsigned int)((int)((unsigned int)v1277 >> 2)) >> 1)) & 1) * 2) + ((((v1303 + ((~(((v1305 ^ -1) | (-(v1305 ^ -1))) >> 31)) & 2)) - (v1307 + ((~(((v1309 ^ -1) | (-(v1309 ^ -1))) >> 31)) & 2))) >> 31) & 1);
    int v1502 = (int)((unsigned int)((int)((unsigned int)v1277 >> 2)) >> 1);
    v1382[v1501] = v1502;
    int * v1384 = v1273->cache_dirty;
    v1384[v1501] = 0;
    int * v1386 = v1273->cache_age;
    v1386[v1501] = 1;
    int * v1388 = v1273->cache_age;
    int v1389 = v1388[v1501];
    int * v1390 = v1273->cache_age;
    int v1391 = v1390[v1410];
    int * v1392 = v1273->cache_age;
    int v1510 = v1391 + ((int)((unsigned int)(v1391 - v1389) >> 31));
    v1392[v1410] = v1510;
    int * v1394 = v1273->cache_age;
    int v1395 = v1394[v1412];
    int * v1396 = v1273->cache_age;
    int v1513 = v1395 + ((int)((unsigned int)(v1395 - v1389) >> 31));
    v1396[v1412] = v1513;
    int * v1398 = v1273->cache_age;
    v1398[v1501] = 0;
    v1401 = v1501;
  }
  int v1516 = (v1401 * 2) + (((int)((unsigned int)v1277 >> 2)) & 1);
  int v1402 = v1288[v1516];
  int * v1403 = v1273->regs;
  v1403[12] = v1402;
  return v1273;
}

struct StateT * slot_6(struct StateT * v1007) {
  int v1008 = v1007->timer;
  int v1141 = v1008 + 1;
  v1007->timer = v1141;
  int * v1010 = v1007->regs;
  int v1011 = v1010[6];
  int * v1012 = v1007->cache_tags;
  int v1145 = (((int)((unsigned int)((int)((unsigned int)v1011 >> 2)) >> 1)) & 1) * 2;
  int v1013 = v1012[v1145];
  int * v1014 = v1007->cache_tags;
  int v1147 = ((((int)((unsigned int)((int)((unsigned int)v1011 >> 2)) >> 1)) & 1) * 2) + 1;
  int v1015 = v1014[v1147];
  int * v1016 = v1007->cache_tags;
  int v1149 = 4 + ((((int)((unsigned int)((int)((unsigned int)v1011 >> 2)) >> 1)) & 3) * 2);
  int v1017 = v1016[v1149];
  int * v1018 = v1007->cache_tags;
  int v1151 = (4 + ((((int)((unsigned int)((int)((unsigned int)v1011 >> 2)) >> 1)) & 3) * 2)) + 1;
  int v1019 = v1018[v1151];
  int v1020 = v1007->timer;
  int v1152 = v1020 + ((100 ^ (((~(((v1017 ^ ((int)((unsigned int)((int)((unsigned int)v1011 >> 2)) >> 1))) | (-(v1017 ^ ((int)((unsigned int)((int)((unsigned int)v1011 >> 2)) >> 1))))) >> 31)) | (~(((v1019 ^ ((int)((unsigned int)((int)((unsigned int)v1011 >> 2)) >> 1))) | (-(v1019 ^ ((int)((unsigned int)((int)((unsigned int)v1011 >> 2)) >> 1))))) >> 31))) & 104)) ^ (((~(((v1013 ^ ((int)((unsigned int)((int)((unsigned int)v1011 >> 2)) >> 1))) | (-(v1013 ^ ((int)((unsigned int)((int)((unsigned int)v1011 >> 2)) >> 1))))) >> 31)) | (~(((v1015 ^ ((int)((unsigned int)((int)((unsigned int)v1011 >> 2)) >> 1))) | (-(v1015 ^ ((int)((unsigned int)((int)((unsigned int)v1011 >> 2)) >> 1))))) >> 31))) & (1 ^ (100 ^ (((~(((v1017 ^ ((int)((unsigned int)((int)((unsigned int)v1011 >> 2)) >> 1))) | (-(v1017 ^ ((int)((unsigned int)((int)((unsigned int)v1011 >> 2)) >> 1))))) >> 31)) | (~(((v1019 ^ ((int)((unsigned int)((int)((unsigned int)v1011 >> 2)) >> 1))) | (-(v1019 ^ ((int)((unsigned int)((int)((unsigned int)v1011 >> 2)) >> 1))))) >> 31))) & 104)))));
  v1007->timer = v1152;
  int * v1022 = v1007->cache_vals;
  bool v1153 = !(((~(((v1013 ^ ((int)((unsigned int)((int)((unsigned int)v1011 >> 2)) >> 1))) | (-(v1013 ^ ((int)((unsigned int)((int)((unsigned int)v1011 >> 2)) >> 1))))) >> 31)) | (~(((v1015 ^ ((int)((unsigned int)((int)((unsigned int)v1011 >> 2)) >> 1))) | (-(v1015 ^ ((int)((unsigned int)((int)((unsigned int)v1011 >> 2)) >> 1))))) >> 31))) == 0);
  int v1135;
  if (v1153) {
    int * v1023 = v1007->cache_age;
    int v1155 = ((((int)((unsigned int)((int)((unsigned int)v1011 >> 2)) >> 1)) & 1) * 2) + ((~(((v1015 ^ ((int)((unsigned int)((int)((unsigned int)v1011 >> 2)) >> 1))) | (-(v1015 ^ ((int)((unsigned int)((int)((unsigned int)v1011 >> 2)) >> 1))))) >> 31)) & 1);
    int v1024 = v1023[v1155];
    int * v1025 = v1007->cache_age;
    int v1026 = v1025[v1145];
    int * v1027 = v1007->cache_age;
    int v1158 = v1026 + ((int)((unsigned int)(v1026 - v1024) >> 31));
    v1027[v1145] = v1158;
    int * v1029 = v1007->cache_age;
    int v1030 = v1029[v1147];
    int * v1031 = v1007->cache_age;
    int v1161 = v1030 + ((int)((unsigned int)(v1030 - v1024) >> 31));
    v1031[v1147] = v1161;
    int * v1033 = v1007->cache_age;
    v1033[v1155] = 0;
    v1135 = v1155;
  } else {
    int * v1036 = v1007->cache_age;
    int v1165 = (((int)((unsigned int)((int)((unsigned int)v1011 >> 2)) >> 1)) & 1) * 2;
    int v1037 = v1036[v1165];
    int * v1038 = v1007->cache_tags;
    int v1039 = v1038[v1165];
    int * v1040 = v1007->cache_age;
    int v1041 = v1040[v1147];
    int * v1042 = v1007->cache_tags;
    int v1043 = v1042[v1147];
    bool v1169 = !(((~(((v1017 ^ ((int)((unsigned int)((int)((unsigned int)v1011 >> 2)) >> 1))) | (-(v1017 ^ ((int)((unsigned int)((int)((unsigned int)v1011 >> 2)) >> 1))))) >> 31)) | (~(((v1019 ^ ((int)((unsigned int)((int)((unsigned int)v1011 >> 2)) >> 1))) | (-(v1019 ^ ((int)((unsigned int)((int)((unsigned int)v1011 >> 2)) >> 1))))) >> 31))) == 0);
    int v1107;
    if (v1169) {
      int * v1044 = v1007->cache_age;
      int v1171 = (4 + ((((int)((unsigned int)((int)((unsigned int)v1011 >> 2)) >> 1)) & 3) * 2)) + ((~(((v1019 ^ ((int)((unsigned int)((int)((unsigned int)v1011 >> 2)) >> 1))) | (-(v1019 ^ ((int)((unsigned int)((int)((unsigned int)v1011 >> 2)) >> 1))))) >> 31)) & 1);
      int v1045 = v1044[v1171];
      int * v1046 = v1007->cache_age;
      int v1047 = v1046[v1149];
      int * v1048 = v1007->cache_age;
      int v1174 = v1047 + ((int)((unsigned int)(v1047 - v1045) >> 31));
      v1048[v1149] = v1174;
      int * v1050 = v1007->cache_age;
      int v1051 = v1050[v1151];
      int * v1052 = v1007->cache_age;
      int v1177 = v1051 + ((int)((unsigned int)(v1051 - v1045) >> 31));
      v1052[v1151] = v1177;
      int * v1054 = v1007->cache_age;
      v1054[v1171] = 0;
      v1107 = v1171;
    } else {
      int * v1057 = v1007->cache_age;
      int v1181 = 4 + ((((int)((unsigned int)((int)((unsigned int)v1011 >> 2)) >> 1)) & 3) * 2);
      int v1058 = v1057[v1181];
      int * v1059 = v1007->cache_tags;
      int v1060 = v1059[v1181];
      int * v1061 = v1007->cache_age;
      int v1062 = v1061[v1151];
      int * v1063 = v1007->cache_tags;
      int v1064 = v1063[v1151];
      int * v1065 = v1007->cache_dirty;
      int v1186 = (4 + ((((int)((unsigned int)((int)((unsigned int)v1011 >> 2)) >> 1)) & 3) * 2)) + ((((v1058 + ((~(((v1060 ^ -1) | (-(v1060 ^ -1))) >> 31)) & 2)) - (v1062 + ((~(((v1064 ^ -1) | (-(v1064 ^ -1))) >> 31)) & 2))) >> 31) & 1);
      int v1066 = v1065[v1186];
      bool v1187 = !(v1066 == 0);
      if (v1187) {
        int * v1067 = v1007->cache_tags;
        int v1068 = v1067[v1186];
        int * v1069 = v1007->cache_vals;
        int v1190 = ((4 + ((((int)((unsigned int)((int)((unsigned int)v1011 >> 2)) >> 1)) & 3) * 2)) + ((((v1058 + ((~(((v1060 ^ -1) | (-(v1060 ^ -1))) >> 31)) & 2)) - (v1062 + ((~(((v1064 ^ -1) | (-(v1064 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
        int v1070 = v1069[v1190];
        int * v1071 = v1007->cache_vals;
        int v1192 = (((4 + ((((int)((unsigned int)((int)((unsigned int)v1011 >> 2)) >> 1)) & 3) * 2)) + ((((v1058 + ((~(((v1060 ^ -1) | (-(v1060 ^ -1))) >> 31)) & 2)) - (v1062 + ((~(((v1064 ^ -1) | (-(v1064 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
        int v1072 = v1071[v1192];
        int * v1073 = v1007->mem;
        int v1194 = v1068 * 2;
        v1073[v1194] = v1070;
        int * v1075 = v1007->mem;
        int v1197 = (v1068 * 2) + 1;
        v1075[v1197] = v1072;
        ;
      } else {
        ;
      }
      int * v1080 = v1007->mem;
      int v1202 = ((int)((unsigned int)((int)((unsigned int)v1011 >> 2)) >> 1)) * 2;
      int v1081 = v1080[v1202];
      int * v1082 = v1007->mem;
      int v1204 = (((int)((unsigned int)((int)((unsigned int)v1011 >> 2)) >> 1)) * 2) + 1;
      int v1083 = v1082[v1204];
      int * v1084 = v1007->cache_vals;
      int v1206 = ((4 + ((((int)((unsigned int)((int)((unsigned int)v1011 >> 2)) >> 1)) & 3) * 2)) + ((((v1058 + ((~(((v1060 ^ -1) | (-(v1060 ^ -1))) >> 31)) & 2)) - (v1062 + ((~(((v1064 ^ -1) | (-(v1064 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
      v1084[v1206] = v1081;
      int * v1086 = v1007->cache_vals;
      int v1209 = (((4 + ((((int)((unsigned int)((int)((unsigned int)v1011 >> 2)) >> 1)) & 3) * 2)) + ((((v1058 + ((~(((v1060 ^ -1) | (-(v1060 ^ -1))) >> 31)) & 2)) - (v1062 + ((~(((v1064 ^ -1) | (-(v1064 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
      v1086[v1209] = v1083;
      int * v1088 = v1007->cache_tags;
      int v1212 = (int)((unsigned int)((int)((unsigned int)v1011 >> 2)) >> 1);
      v1088[v1186] = v1212;
      int * v1090 = v1007->cache_dirty;
      v1090[v1186] = 0;
      int * v1092 = v1007->cache_age;
      v1092[v1186] = 1;
      int * v1094 = v1007->cache_age;
      int v1095 = v1094[v1186];
      int * v1096 = v1007->cache_age;
      int v1097 = v1096[v1149];
      int * v1098 = v1007->cache_age;
      int v1220 = v1097 + ((int)((unsigned int)(v1097 - v1095) >> 31));
      v1098[v1149] = v1220;
      int * v1100 = v1007->cache_age;
      int v1101 = v1100[v1151];
      int * v1102 = v1007->cache_age;
      int v1223 = v1101 + ((int)((unsigned int)(v1101 - v1095) >> 31));
      v1102[v1151] = v1223;
      int * v1104 = v1007->cache_age;
      v1104[v1186] = 0;
      v1107 = v1186;
    }
    int * v1108 = v1007->cache_vals;
    int v1226 = v1107 * 2;
    int v1109 = v1108[v1226];
    int * v1110 = v1007->cache_vals;
    int v1228 = (v1107 * 2) + 1;
    int v1111 = v1110[v1228];
    int * v1112 = v1007->cache_vals;
    int v1230 = (((((int)((unsigned int)((int)((unsigned int)v1011 >> 2)) >> 1)) & 1) * 2) + ((((v1037 + ((~(((v1039 ^ -1) | (-(v1039 ^ -1))) >> 31)) & 2)) - (v1041 + ((~(((v1043 ^ -1) | (-(v1043 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
    v1112[v1230] = v1109;
    int * v1114 = v1007->cache_vals;
    int v1233 = ((((((int)((unsigned int)((int)((unsigned int)v1011 >> 2)) >> 1)) & 1) * 2) + ((((v1037 + ((~(((v1039 ^ -1) | (-(v1039 ^ -1))) >> 31)) & 2)) - (v1041 + ((~(((v1043 ^ -1) | (-(v1043 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
    v1114[v1233] = v1111;
    int * v1116 = v1007->cache_tags;
    int v1236 = ((((int)((unsigned int)((int)((unsigned int)v1011 >> 2)) >> 1)) & 1) * 2) + ((((v1037 + ((~(((v1039 ^ -1) | (-(v1039 ^ -1))) >> 31)) & 2)) - (v1041 + ((~(((v1043 ^ -1) | (-(v1043 ^ -1))) >> 31)) & 2))) >> 31) & 1);
    int v1237 = (int)((unsigned int)((int)((unsigned int)v1011 >> 2)) >> 1);
    v1116[v1236] = v1237;
    int * v1118 = v1007->cache_dirty;
    v1118[v1236] = 0;
    int * v1120 = v1007->cache_age;
    v1120[v1236] = 1;
    int * v1122 = v1007->cache_age;
    int v1123 = v1122[v1236];
    int * v1124 = v1007->cache_age;
    int v1125 = v1124[v1145];
    int * v1126 = v1007->cache_age;
    int v1245 = v1125 + ((int)((unsigned int)(v1125 - v1123) >> 31));
    v1126[v1145] = v1245;
    int * v1128 = v1007->cache_age;
    int v1129 = v1128[v1147];
    int * v1130 = v1007->cache_age;
    int v1248 = v1129 + ((int)((unsigned int)(v1129 - v1123) >> 31));
    v1130[v1147] = v1248;
    int * v1132 = v1007->cache_age;
    v1132[v1236] = 0;
    v1135 = v1236;
  }
  int v1251 = (v1135 * 2) + (((int)((unsigned int)v1011 >> 2)) & 1);
  int v1136 = v1022[v1251];
  int * v1137 = v1007->regs;
  v1137[11] = v1136;
  struct StateT * v1139 = slot_7(v1007);
  return v1139;
}

struct StateT * slot_2(struct StateT * v32) {
  int * v33 = v32->saved_regs;
  int * v34 = v32->regs;
  int v35 = v34[6];
  v33[6] = v35;
  int v37 = v32->timer;
  int v571 = v37 + 1;
  v32->timer = v571;
  int * v39 = v32->regs;
  int v40 = v39[5];
  int * v41 = v32->regs;
  int v575 = v40 + 80;
  v41[6] = v575;
  int * v43 = v32->saved_regs;
  int * v44 = v32->regs;
  int v45 = v44[7];
  v43[7] = v45;
  int v47 = v32->timer;
  int v580 = v47 + 1;
  v32->timer = v580;
  int * v49 = v32->regs;
  v49[7] = 0;
  int * v51 = v32->regs;
  int v52 = v51[5];
  int * v53 = v32->regs;
  int v54 = v53[9];
  bool v586 = v52 >= v54;
  struct StateT * v565;
  if (v586) {
    int v55 = v32->timer;
    int v587 = v55 + 15;
    v32->timer = v587;
    int * v57 = v32->saved_regs;
    int v58 = v57[6];
    int * v59 = v32->regs;
    v59[6] = v58;
    int * v61 = v32->saved_regs;
    int v62 = v61[7];
    int * v63 = v32->regs;
    v63[7] = v62;
    v565 = v32;
  } else {
    int v66 = v32->timer;
    int v594 = v66 + 1;
    v32->timer = v594;
    int * v68 = v32->regs;
    int v69 = v68[6];
    int * v70 = v32->regs;
    int v71 = v70[7];
    int * v72 = v32->saved_regs;
    int * v73 = v32->regs;
    int v74 = v73[11];
    v72[11] = v74;
    int v76 = v32->timer;
    int v601 = v76 + 1;
    v32->timer = v601;
    int * v78 = v32->regs;
    int v79 = v78[6];
    int * v80 = v32->cache_tags;
    int v604 = (((int)((unsigned int)((int)((unsigned int)v79 >> 2)) >> 1)) & 1) * 2;
    int v81 = v80[v604];
    int * v82 = v32->cache_tags;
    int v606 = ((((int)((unsigned int)((int)((unsigned int)v79 >> 2)) >> 1)) & 1) * 2) + 1;
    int v83 = v82[v606];
    int * v84 = v32->cache_tags;
    int v608 = 4 + ((((int)((unsigned int)((int)((unsigned int)v79 >> 2)) >> 1)) & 3) * 2);
    int v85 = v84[v608];
    int * v86 = v32->cache_tags;
    int v610 = (4 + ((((int)((unsigned int)((int)((unsigned int)v79 >> 2)) >> 1)) & 3) * 2)) + 1;
    int v87 = v86[v610];
    int v88 = v32->timer;
    int v611 = v88 + ((100 ^ (((~(((v85 ^ ((int)((unsigned int)((int)((unsigned int)v79 >> 2)) >> 1))) | (-(v85 ^ ((int)((unsigned int)((int)((unsigned int)v79 >> 2)) >> 1))))) >> 31)) | (~(((v87 ^ ((int)((unsigned int)((int)((unsigned int)v79 >> 2)) >> 1))) | (-(v87 ^ ((int)((unsigned int)((int)((unsigned int)v79 >> 2)) >> 1))))) >> 31))) & 104)) ^ (((~(((v81 ^ ((int)((unsigned int)((int)((unsigned int)v79 >> 2)) >> 1))) | (-(v81 ^ ((int)((unsigned int)((int)((unsigned int)v79 >> 2)) >> 1))))) >> 31)) | (~(((v83 ^ ((int)((unsigned int)((int)((unsigned int)v79 >> 2)) >> 1))) | (-(v83 ^ ((int)((unsigned int)((int)((unsigned int)v79 >> 2)) >> 1))))) >> 31))) & (1 ^ (100 ^ (((~(((v85 ^ ((int)((unsigned int)((int)((unsigned int)v79 >> 2)) >> 1))) | (-(v85 ^ ((int)((unsigned int)((int)((unsigned int)v79 >> 2)) >> 1))))) >> 31)) | (~(((v87 ^ ((int)((unsigned int)((int)((unsigned int)v79 >> 2)) >> 1))) | (-(v87 ^ ((int)((unsigned int)((int)((unsigned int)v79 >> 2)) >> 1))))) >> 31))) & 104)))));
    v32->timer = v611;
    int * v90 = v32->cache_vals;
    bool v612 = !(((~(((v81 ^ ((int)((unsigned int)((int)((unsigned int)v79 >> 2)) >> 1))) | (-(v81 ^ ((int)((unsigned int)((int)((unsigned int)v79 >> 2)) >> 1))))) >> 31)) | (~(((v83 ^ ((int)((unsigned int)((int)((unsigned int)v79 >> 2)) >> 1))) | (-(v83 ^ ((int)((unsigned int)((int)((unsigned int)v79 >> 2)) >> 1))))) >> 31))) == 0);
    int v203;
    if (v612) {
      int * v91 = v32->cache_age;
      int v614 = ((((int)((unsigned int)((int)((unsigned int)v79 >> 2)) >> 1)) & 1) * 2) + ((~(((v83 ^ ((int)((unsigned int)((int)((unsigned int)v79 >> 2)) >> 1))) | (-(v83 ^ ((int)((unsigned int)((int)((unsigned int)v79 >> 2)) >> 1))))) >> 31)) & 1);
      int v92 = v91[v614];
      int * v93 = v32->cache_age;
      int v94 = v93[v604];
      int * v95 = v32->cache_age;
      int v617 = v94 + ((int)((unsigned int)(v94 - v92) >> 31));
      v95[v604] = v617;
      int * v97 = v32->cache_age;
      int v98 = v97[v606];
      int * v99 = v32->cache_age;
      int v620 = v98 + ((int)((unsigned int)(v98 - v92) >> 31));
      v99[v606] = v620;
      int * v101 = v32->cache_age;
      v101[v614] = 0;
      v203 = v614;
    } else {
      int * v104 = v32->cache_age;
      int v623 = (((int)((unsigned int)((int)((unsigned int)v79 >> 2)) >> 1)) & 1) * 2;
      int v105 = v104[v623];
      int * v106 = v32->cache_tags;
      int v107 = v106[v623];
      int * v108 = v32->cache_age;
      int v109 = v108[v606];
      int * v110 = v32->cache_tags;
      int v111 = v110[v606];
      bool v627 = !(((~(((v85 ^ ((int)((unsigned int)((int)((unsigned int)v79 >> 2)) >> 1))) | (-(v85 ^ ((int)((unsigned int)((int)((unsigned int)v79 >> 2)) >> 1))))) >> 31)) | (~(((v87 ^ ((int)((unsigned int)((int)((unsigned int)v79 >> 2)) >> 1))) | (-(v87 ^ ((int)((unsigned int)((int)((unsigned int)v79 >> 2)) >> 1))))) >> 31))) == 0);
      int v175;
      if (v627) {
        int * v112 = v32->cache_age;
        int v629 = (4 + ((((int)((unsigned int)((int)((unsigned int)v79 >> 2)) >> 1)) & 3) * 2)) + ((~(((v87 ^ ((int)((unsigned int)((int)((unsigned int)v79 >> 2)) >> 1))) | (-(v87 ^ ((int)((unsigned int)((int)((unsigned int)v79 >> 2)) >> 1))))) >> 31)) & 1);
        int v113 = v112[v629];
        int * v114 = v32->cache_age;
        int v115 = v114[v608];
        int * v116 = v32->cache_age;
        int v632 = v115 + ((int)((unsigned int)(v115 - v113) >> 31));
        v116[v608] = v632;
        int * v118 = v32->cache_age;
        int v119 = v118[v610];
        int * v120 = v32->cache_age;
        int v635 = v119 + ((int)((unsigned int)(v119 - v113) >> 31));
        v120[v610] = v635;
        int * v122 = v32->cache_age;
        v122[v629] = 0;
        v175 = v629;
      } else {
        int * v125 = v32->cache_age;
        int v638 = 4 + ((((int)((unsigned int)((int)((unsigned int)v79 >> 2)) >> 1)) & 3) * 2);
        int v126 = v125[v638];
        int * v127 = v32->cache_tags;
        int v128 = v127[v638];
        int * v129 = v32->cache_age;
        int v130 = v129[v610];
        int * v131 = v32->cache_tags;
        int v132 = v131[v610];
        int * v133 = v32->cache_dirty;
        int v643 = (4 + ((((int)((unsigned int)((int)((unsigned int)v79 >> 2)) >> 1)) & 3) * 2)) + ((((v126 + ((~(((v128 ^ -1) | (-(v128 ^ -1))) >> 31)) & 2)) - (v130 + ((~(((v132 ^ -1) | (-(v132 ^ -1))) >> 31)) & 2))) >> 31) & 1);
        int v134 = v133[v643];
        bool v644 = !(v134 == 0);
        if (v644) {
          int * v135 = v32->cache_tags;
          int v136 = v135[v643];
          int * v137 = v32->cache_vals;
          int v647 = ((4 + ((((int)((unsigned int)((int)((unsigned int)v79 >> 2)) >> 1)) & 3) * 2)) + ((((v126 + ((~(((v128 ^ -1) | (-(v128 ^ -1))) >> 31)) & 2)) - (v130 + ((~(((v132 ^ -1) | (-(v132 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
          int v138 = v137[v647];
          int * v139 = v32->cache_vals;
          int v649 = (((4 + ((((int)((unsigned int)((int)((unsigned int)v79 >> 2)) >> 1)) & 3) * 2)) + ((((v126 + ((~(((v128 ^ -1) | (-(v128 ^ -1))) >> 31)) & 2)) - (v130 + ((~(((v132 ^ -1) | (-(v132 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
          int v140 = v139[v649];
          int * v141 = v32->mem;
          int v651 = v136 * 2;
          v141[v651] = v138;
          int * v143 = v32->mem;
          int v654 = (v136 * 2) + 1;
          v143[v654] = v140;
          ;
        } else {
          ;
        }
        int * v148 = v32->mem;
        int v659 = ((int)((unsigned int)((int)((unsigned int)v79 >> 2)) >> 1)) * 2;
        int v149 = v148[v659];
        int * v150 = v32->mem;
        int v661 = (((int)((unsigned int)((int)((unsigned int)v79 >> 2)) >> 1)) * 2) + 1;
        int v151 = v150[v661];
        int * v152 = v32->cache_vals;
        int v663 = ((4 + ((((int)((unsigned int)((int)((unsigned int)v79 >> 2)) >> 1)) & 3) * 2)) + ((((v126 + ((~(((v128 ^ -1) | (-(v128 ^ -1))) >> 31)) & 2)) - (v130 + ((~(((v132 ^ -1) | (-(v132 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
        v152[v663] = v149;
        int * v154 = v32->cache_vals;
        int v666 = (((4 + ((((int)((unsigned int)((int)((unsigned int)v79 >> 2)) >> 1)) & 3) * 2)) + ((((v126 + ((~(((v128 ^ -1) | (-(v128 ^ -1))) >> 31)) & 2)) - (v130 + ((~(((v132 ^ -1) | (-(v132 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
        v154[v666] = v151;
        int * v156 = v32->cache_tags;
        int v669 = (int)((unsigned int)((int)((unsigned int)v79 >> 2)) >> 1);
        v156[v643] = v669;
        int * v158 = v32->cache_dirty;
        v158[v643] = 0;
        int * v160 = v32->cache_age;
        v160[v643] = 1;
        int * v162 = v32->cache_age;
        int v163 = v162[v643];
        int * v164 = v32->cache_age;
        int v165 = v164[v608];
        int * v166 = v32->cache_age;
        int v676 = v165 + ((int)((unsigned int)(v165 - v163) >> 31));
        v166[v608] = v676;
        int * v168 = v32->cache_age;
        int v169 = v168[v610];
        int * v170 = v32->cache_age;
        int v679 = v169 + ((int)((unsigned int)(v169 - v163) >> 31));
        v170[v610] = v679;
        int * v172 = v32->cache_age;
        v172[v643] = 0;
        v175 = v643;
      }
      int * v176 = v32->cache_vals;
      int v682 = v175 * 2;
      int v177 = v176[v682];
      int * v178 = v32->cache_vals;
      int v684 = (v175 * 2) + 1;
      int v179 = v178[v684];
      int * v180 = v32->cache_vals;
      int v686 = (((((int)((unsigned int)((int)((unsigned int)v79 >> 2)) >> 1)) & 1) * 2) + ((((v105 + ((~(((v107 ^ -1) | (-(v107 ^ -1))) >> 31)) & 2)) - (v109 + ((~(((v111 ^ -1) | (-(v111 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
      v180[v686] = v177;
      int * v182 = v32->cache_vals;
      int v689 = ((((((int)((unsigned int)((int)((unsigned int)v79 >> 2)) >> 1)) & 1) * 2) + ((((v105 + ((~(((v107 ^ -1) | (-(v107 ^ -1))) >> 31)) & 2)) - (v109 + ((~(((v111 ^ -1) | (-(v111 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
      v182[v689] = v179;
      int * v184 = v32->cache_tags;
      int v692 = ((((int)((unsigned int)((int)((unsigned int)v79 >> 2)) >> 1)) & 1) * 2) + ((((v105 + ((~(((v107 ^ -1) | (-(v107 ^ -1))) >> 31)) & 2)) - (v109 + ((~(((v111 ^ -1) | (-(v111 ^ -1))) >> 31)) & 2))) >> 31) & 1);
      int v693 = (int)((unsigned int)((int)((unsigned int)v79 >> 2)) >> 1);
      v184[v692] = v693;
      int * v186 = v32->cache_dirty;
      v186[v692] = 0;
      int * v188 = v32->cache_age;
      v188[v692] = 1;
      int * v190 = v32->cache_age;
      int v191 = v190[v692];
      int * v192 = v32->cache_age;
      int v193 = v192[v604];
      int * v194 = v32->cache_age;
      int v700 = v193 + ((int)((unsigned int)(v193 - v191) >> 31));
      v194[v604] = v700;
      int * v196 = v32->cache_age;
      int v197 = v196[v606];
      int * v198 = v32->cache_age;
      int v703 = v197 + ((int)((unsigned int)(v197 - v191) >> 31));
      v198[v606] = v703;
      int * v200 = v32->cache_age;
      v200[v692] = 0;
      v203 = v692;
    }
    int v706 = (v203 * 2) + (((int)((unsigned int)v79 >> 2)) & 1);
    int v204 = v90[v706];
    int * v205 = v32->regs;
    v205[11] = v204;
    int v207 = v32->timer;
    int v709 = v207 + 1;
    v32->timer = v709;
    int * v209 = v32->regs;
    int v210 = v209[11];
    int * v211 = v32->regs;
    int v712 = v210 << 2;
    v211[11] = v712;
    int * v213 = v32->saved_regs;
    int * v214 = v32->regs;
    int v215 = v214[12];
    v213[12] = v215;
    int v217 = v32->timer;
    int v717 = v217 + 1;
    v32->timer = v717;
    int * v219 = v32->regs;
    int v220 = v219[11];
    bool v719 = (((int)((unsigned int)v69 >> 2)) & 3) == (((int)((unsigned int)v220 >> 2)) & 3);
    int v350;
    if (v719) {
      int v221 = v32->timer;
      int v720 = v221 + 1;
      v32->timer = v720;
      v350 = v71;
    } else {
      int * v224 = v32->cache_tags;
      int v723 = (((int)((unsigned int)((int)((unsigned int)v220 >> 2)) >> 1)) & 1) * 2;
      int v225 = v224[v723];
      int * v226 = v32->cache_tags;
      int v725 = ((((int)((unsigned int)((int)((unsigned int)v220 >> 2)) >> 1)) & 1) * 2) + 1;
      int v227 = v226[v725];
      int * v228 = v32->cache_tags;
      int v727 = 4 + ((((int)((unsigned int)((int)((unsigned int)v220 >> 2)) >> 1)) & 3) * 2);
      int v229 = v228[v727];
      int * v230 = v32->cache_tags;
      int v729 = (4 + ((((int)((unsigned int)((int)((unsigned int)v220 >> 2)) >> 1)) & 3) * 2)) + 1;
      int v231 = v230[v729];
      int v232 = v32->timer;
      int v730 = v232 + ((100 ^ (((~(((v229 ^ ((int)((unsigned int)((int)((unsigned int)v220 >> 2)) >> 1))) | (-(v229 ^ ((int)((unsigned int)((int)((unsigned int)v220 >> 2)) >> 1))))) >> 31)) | (~(((v231 ^ ((int)((unsigned int)((int)((unsigned int)v220 >> 2)) >> 1))) | (-(v231 ^ ((int)((unsigned int)((int)((unsigned int)v220 >> 2)) >> 1))))) >> 31))) & 104)) ^ (((~(((v225 ^ ((int)((unsigned int)((int)((unsigned int)v220 >> 2)) >> 1))) | (-(v225 ^ ((int)((unsigned int)((int)((unsigned int)v220 >> 2)) >> 1))))) >> 31)) | (~(((v227 ^ ((int)((unsigned int)((int)((unsigned int)v220 >> 2)) >> 1))) | (-(v227 ^ ((int)((unsigned int)((int)((unsigned int)v220 >> 2)) >> 1))))) >> 31))) & (1 ^ (100 ^ (((~(((v229 ^ ((int)((unsigned int)((int)((unsigned int)v220 >> 2)) >> 1))) | (-(v229 ^ ((int)((unsigned int)((int)((unsigned int)v220 >> 2)) >> 1))))) >> 31)) | (~(((v231 ^ ((int)((unsigned int)((int)((unsigned int)v220 >> 2)) >> 1))) | (-(v231 ^ ((int)((unsigned int)((int)((unsigned int)v220 >> 2)) >> 1))))) >> 31))) & 104)))));
      v32->timer = v730;
      int * v234 = v32->cache_vals;
      bool v731 = !(((~(((v225 ^ ((int)((unsigned int)((int)((unsigned int)v220 >> 2)) >> 1))) | (-(v225 ^ ((int)((unsigned int)((int)((unsigned int)v220 >> 2)) >> 1))))) >> 31)) | (~(((v227 ^ ((int)((unsigned int)((int)((unsigned int)v220 >> 2)) >> 1))) | (-(v227 ^ ((int)((unsigned int)((int)((unsigned int)v220 >> 2)) >> 1))))) >> 31))) == 0);
      int v347;
      if (v731) {
        int * v235 = v32->cache_age;
        int v733 = ((((int)((unsigned int)((int)((unsigned int)v220 >> 2)) >> 1)) & 1) * 2) + ((~(((v227 ^ ((int)((unsigned int)((int)((unsigned int)v220 >> 2)) >> 1))) | (-(v227 ^ ((int)((unsigned int)((int)((unsigned int)v220 >> 2)) >> 1))))) >> 31)) & 1);
        int v236 = v235[v733];
        int * v237 = v32->cache_age;
        int v238 = v237[v723];
        int * v239 = v32->cache_age;
        int v736 = v238 + ((int)((unsigned int)(v238 - v236) >> 31));
        v239[v723] = v736;
        int * v241 = v32->cache_age;
        int v242 = v241[v725];
        int * v243 = v32->cache_age;
        int v739 = v242 + ((int)((unsigned int)(v242 - v236) >> 31));
        v243[v725] = v739;
        int * v245 = v32->cache_age;
        v245[v733] = 0;
        v347 = v733;
      } else {
        int * v248 = v32->cache_age;
        int v742 = (((int)((unsigned int)((int)((unsigned int)v220 >> 2)) >> 1)) & 1) * 2;
        int v249 = v248[v742];
        int * v250 = v32->cache_tags;
        int v251 = v250[v742];
        int * v252 = v32->cache_age;
        int v253 = v252[v725];
        int * v254 = v32->cache_tags;
        int v255 = v254[v725];
        bool v746 = !(((~(((v229 ^ ((int)((unsigned int)((int)((unsigned int)v220 >> 2)) >> 1))) | (-(v229 ^ ((int)((unsigned int)((int)((unsigned int)v220 >> 2)) >> 1))))) >> 31)) | (~(((v231 ^ ((int)((unsigned int)((int)((unsigned int)v220 >> 2)) >> 1))) | (-(v231 ^ ((int)((unsigned int)((int)((unsigned int)v220 >> 2)) >> 1))))) >> 31))) == 0);
        int v319;
        if (v746) {
          int * v256 = v32->cache_age;
          int v748 = (4 + ((((int)((unsigned int)((int)((unsigned int)v220 >> 2)) >> 1)) & 3) * 2)) + ((~(((v231 ^ ((int)((unsigned int)((int)((unsigned int)v220 >> 2)) >> 1))) | (-(v231 ^ ((int)((unsigned int)((int)((unsigned int)v220 >> 2)) >> 1))))) >> 31)) & 1);
          int v257 = v256[v748];
          int * v258 = v32->cache_age;
          int v259 = v258[v727];
          int * v260 = v32->cache_age;
          int v751 = v259 + ((int)((unsigned int)(v259 - v257) >> 31));
          v260[v727] = v751;
          int * v262 = v32->cache_age;
          int v263 = v262[v729];
          int * v264 = v32->cache_age;
          int v754 = v263 + ((int)((unsigned int)(v263 - v257) >> 31));
          v264[v729] = v754;
          int * v266 = v32->cache_age;
          v266[v748] = 0;
          v319 = v748;
        } else {
          int * v269 = v32->cache_age;
          int v757 = 4 + ((((int)((unsigned int)((int)((unsigned int)v220 >> 2)) >> 1)) & 3) * 2);
          int v270 = v269[v757];
          int * v271 = v32->cache_tags;
          int v272 = v271[v757];
          int * v273 = v32->cache_age;
          int v274 = v273[v729];
          int * v275 = v32->cache_tags;
          int v276 = v275[v729];
          int * v277 = v32->cache_dirty;
          int v762 = (4 + ((((int)((unsigned int)((int)((unsigned int)v220 >> 2)) >> 1)) & 3) * 2)) + ((((v270 + ((~(((v272 ^ -1) | (-(v272 ^ -1))) >> 31)) & 2)) - (v274 + ((~(((v276 ^ -1) | (-(v276 ^ -1))) >> 31)) & 2))) >> 31) & 1);
          int v278 = v277[v762];
          bool v763 = !(v278 == 0);
          if (v763) {
            int * v279 = v32->cache_tags;
            int v280 = v279[v762];
            int * v281 = v32->cache_vals;
            int v766 = ((4 + ((((int)((unsigned int)((int)((unsigned int)v220 >> 2)) >> 1)) & 3) * 2)) + ((((v270 + ((~(((v272 ^ -1) | (-(v272 ^ -1))) >> 31)) & 2)) - (v274 + ((~(((v276 ^ -1) | (-(v276 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
            int v282 = v281[v766];
            int * v283 = v32->cache_vals;
            int v768 = (((4 + ((((int)((unsigned int)((int)((unsigned int)v220 >> 2)) >> 1)) & 3) * 2)) + ((((v270 + ((~(((v272 ^ -1) | (-(v272 ^ -1))) >> 31)) & 2)) - (v274 + ((~(((v276 ^ -1) | (-(v276 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
            int v284 = v283[v768];
            int * v285 = v32->mem;
            int v770 = v280 * 2;
            v285[v770] = v282;
            int * v287 = v32->mem;
            int v773 = (v280 * 2) + 1;
            v287[v773] = v284;
            ;
          } else {
            ;
          }
          int * v292 = v32->mem;
          int v778 = ((int)((unsigned int)((int)((unsigned int)v220 >> 2)) >> 1)) * 2;
          int v293 = v292[v778];
          int * v294 = v32->mem;
          int v780 = (((int)((unsigned int)((int)((unsigned int)v220 >> 2)) >> 1)) * 2) + 1;
          int v295 = v294[v780];
          int * v296 = v32->cache_vals;
          int v782 = ((4 + ((((int)((unsigned int)((int)((unsigned int)v220 >> 2)) >> 1)) & 3) * 2)) + ((((v270 + ((~(((v272 ^ -1) | (-(v272 ^ -1))) >> 31)) & 2)) - (v274 + ((~(((v276 ^ -1) | (-(v276 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
          v296[v782] = v293;
          int * v298 = v32->cache_vals;
          int v785 = (((4 + ((((int)((unsigned int)((int)((unsigned int)v220 >> 2)) >> 1)) & 3) * 2)) + ((((v270 + ((~(((v272 ^ -1) | (-(v272 ^ -1))) >> 31)) & 2)) - (v274 + ((~(((v276 ^ -1) | (-(v276 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
          v298[v785] = v295;
          int * v300 = v32->cache_tags;
          int v788 = (int)((unsigned int)((int)((unsigned int)v220 >> 2)) >> 1);
          v300[v762] = v788;
          int * v302 = v32->cache_dirty;
          v302[v762] = 0;
          int * v304 = v32->cache_age;
          v304[v762] = 1;
          int * v306 = v32->cache_age;
          int v307 = v306[v762];
          int * v308 = v32->cache_age;
          int v309 = v308[v727];
          int * v310 = v32->cache_age;
          int v795 = v309 + ((int)((unsigned int)(v309 - v307) >> 31));
          v310[v727] = v795;
          int * v312 = v32->cache_age;
          int v313 = v312[v729];
          int * v314 = v32->cache_age;
          int v798 = v313 + ((int)((unsigned int)(v313 - v307) >> 31));
          v314[v729] = v798;
          int * v316 = v32->cache_age;
          v316[v762] = 0;
          v319 = v762;
        }
        int * v320 = v32->cache_vals;
        int v801 = v319 * 2;
        int v321 = v320[v801];
        int * v322 = v32->cache_vals;
        int v803 = (v319 * 2) + 1;
        int v323 = v322[v803];
        int * v324 = v32->cache_vals;
        int v805 = (((((int)((unsigned int)((int)((unsigned int)v220 >> 2)) >> 1)) & 1) * 2) + ((((v249 + ((~(((v251 ^ -1) | (-(v251 ^ -1))) >> 31)) & 2)) - (v253 + ((~(((v255 ^ -1) | (-(v255 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
        v324[v805] = v321;
        int * v326 = v32->cache_vals;
        int v808 = ((((((int)((unsigned int)((int)((unsigned int)v220 >> 2)) >> 1)) & 1) * 2) + ((((v249 + ((~(((v251 ^ -1) | (-(v251 ^ -1))) >> 31)) & 2)) - (v253 + ((~(((v255 ^ -1) | (-(v255 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
        v326[v808] = v323;
        int * v328 = v32->cache_tags;
        int v811 = ((((int)((unsigned int)((int)((unsigned int)v220 >> 2)) >> 1)) & 1) * 2) + ((((v249 + ((~(((v251 ^ -1) | (-(v251 ^ -1))) >> 31)) & 2)) - (v253 + ((~(((v255 ^ -1) | (-(v255 ^ -1))) >> 31)) & 2))) >> 31) & 1);
        int v812 = (int)((unsigned int)((int)((unsigned int)v220 >> 2)) >> 1);
        v328[v811] = v812;
        int * v330 = v32->cache_dirty;
        v330[v811] = 0;
        int * v332 = v32->cache_age;
        v332[v811] = 1;
        int * v334 = v32->cache_age;
        int v335 = v334[v811];
        int * v336 = v32->cache_age;
        int v337 = v336[v723];
        int * v338 = v32->cache_age;
        int v819 = v337 + ((int)((unsigned int)(v337 - v335) >> 31));
        v338[v723] = v819;
        int * v340 = v32->cache_age;
        int v341 = v340[v725];
        int * v342 = v32->cache_age;
        int v822 = v341 + ((int)((unsigned int)(v341 - v335) >> 31));
        v342[v725] = v822;
        int * v344 = v32->cache_age;
        v344[v811] = 0;
        v347 = v811;
      }
      int v825 = (v347 * 2) + (((int)((unsigned int)v220 >> 2)) & 1);
      int v348 = v234[v825];
      v350 = v348;
    }
    int * v351 = v32->regs;
    v351[12] = v350;
    int * v353 = v32->cache_tags;
    int v830 = (((int)((unsigned int)((int)((unsigned int)v69 >> 2)) >> 1)) & 1) * 2;
    int v354 = v353[v830];
    int * v355 = v32->cache_tags;
    int v832 = ((((int)((unsigned int)((int)((unsigned int)v69 >> 2)) >> 1)) & 1) * 2) + 1;
    int v356 = v355[v832];
    int * v357 = v32->cache_tags;
    int v834 = 4 + ((((int)((unsigned int)((int)((unsigned int)v69 >> 2)) >> 1)) & 3) * 2);
    int v358 = v357[v834];
    int * v359 = v32->cache_tags;
    int v836 = (4 + ((((int)((unsigned int)((int)((unsigned int)v69 >> 2)) >> 1)) & 3) * 2)) + 1;
    int v360 = v359[v836];
    int v361 = v32->timer;
    int v837 = v361 + ((100 ^ (((~(((v358 ^ ((int)((unsigned int)((int)((unsigned int)v69 >> 2)) >> 1))) | (-(v358 ^ ((int)((unsigned int)((int)((unsigned int)v69 >> 2)) >> 1))))) >> 31)) | (~(((v360 ^ ((int)((unsigned int)((int)((unsigned int)v69 >> 2)) >> 1))) | (-(v360 ^ ((int)((unsigned int)((int)((unsigned int)v69 >> 2)) >> 1))))) >> 31))) & 104)) ^ (((~(((v354 ^ ((int)((unsigned int)((int)((unsigned int)v69 >> 2)) >> 1))) | (-(v354 ^ ((int)((unsigned int)((int)((unsigned int)v69 >> 2)) >> 1))))) >> 31)) | (~(((v356 ^ ((int)((unsigned int)((int)((unsigned int)v69 >> 2)) >> 1))) | (-(v356 ^ ((int)((unsigned int)((int)((unsigned int)v69 >> 2)) >> 1))))) >> 31))) & (1 ^ (100 ^ (((~(((v358 ^ ((int)((unsigned int)((int)((unsigned int)v69 >> 2)) >> 1))) | (-(v358 ^ ((int)((unsigned int)((int)((unsigned int)v69 >> 2)) >> 1))))) >> 31)) | (~(((v360 ^ ((int)((unsigned int)((int)((unsigned int)v69 >> 2)) >> 1))) | (-(v360 ^ ((int)((unsigned int)((int)((unsigned int)v69 >> 2)) >> 1))))) >> 31))) & 104)))));
    v32->timer = v837;
    bool v838 = !(((~(((v354 ^ ((int)((unsigned int)((int)((unsigned int)v69 >> 2)) >> 1))) | (-(v354 ^ ((int)((unsigned int)((int)((unsigned int)v69 >> 2)) >> 1))))) >> 31)) | (~(((v356 ^ ((int)((unsigned int)((int)((unsigned int)v69 >> 2)) >> 1))) | (-(v356 ^ ((int)((unsigned int)((int)((unsigned int)v69 >> 2)) >> 1))))) >> 31))) == 0);
    int v475;
    if (v838) {
      int * v363 = v32->cache_age;
      int v840 = ((((int)((unsigned int)((int)((unsigned int)v69 >> 2)) >> 1)) & 1) * 2) + ((~(((v356 ^ ((int)((unsigned int)((int)((unsigned int)v69 >> 2)) >> 1))) | (-(v356 ^ ((int)((unsigned int)((int)((unsigned int)v69 >> 2)) >> 1))))) >> 31)) & 1);
      int v364 = v363[v840];
      int * v365 = v32->cache_age;
      int v366 = v365[v830];
      int * v367 = v32->cache_age;
      int v843 = v366 + ((int)((unsigned int)(v366 - v364) >> 31));
      v367[v830] = v843;
      int * v369 = v32->cache_age;
      int v370 = v369[v832];
      int * v371 = v32->cache_age;
      int v846 = v370 + ((int)((unsigned int)(v370 - v364) >> 31));
      v371[v832] = v846;
      int * v373 = v32->cache_age;
      v373[v840] = 0;
      v475 = v840;
    } else {
      int * v376 = v32->cache_age;
      int v849 = (((int)((unsigned int)((int)((unsigned int)v69 >> 2)) >> 1)) & 1) * 2;
      int v377 = v376[v849];
      int * v378 = v32->cache_tags;
      int v379 = v378[v849];
      int * v380 = v32->cache_age;
      int v381 = v380[v832];
      int * v382 = v32->cache_tags;
      int v383 = v382[v832];
      bool v853 = !(((~(((v358 ^ ((int)((unsigned int)((int)((unsigned int)v69 >> 2)) >> 1))) | (-(v358 ^ ((int)((unsigned int)((int)((unsigned int)v69 >> 2)) >> 1))))) >> 31)) | (~(((v360 ^ ((int)((unsigned int)((int)((unsigned int)v69 >> 2)) >> 1))) | (-(v360 ^ ((int)((unsigned int)((int)((unsigned int)v69 >> 2)) >> 1))))) >> 31))) == 0);
      int v447;
      if (v853) {
        int * v384 = v32->cache_age;
        int v855 = (4 + ((((int)((unsigned int)((int)((unsigned int)v69 >> 2)) >> 1)) & 3) * 2)) + ((~(((v360 ^ ((int)((unsigned int)((int)((unsigned int)v69 >> 2)) >> 1))) | (-(v360 ^ ((int)((unsigned int)((int)((unsigned int)v69 >> 2)) >> 1))))) >> 31)) & 1);
        int v385 = v384[v855];
        int * v386 = v32->cache_age;
        int v387 = v386[v834];
        int * v388 = v32->cache_age;
        int v858 = v387 + ((int)((unsigned int)(v387 - v385) >> 31));
        v388[v834] = v858;
        int * v390 = v32->cache_age;
        int v391 = v390[v836];
        int * v392 = v32->cache_age;
        int v861 = v391 + ((int)((unsigned int)(v391 - v385) >> 31));
        v392[v836] = v861;
        int * v394 = v32->cache_age;
        v394[v855] = 0;
        v447 = v855;
      } else {
        int * v397 = v32->cache_age;
        int v864 = 4 + ((((int)((unsigned int)((int)((unsigned int)v69 >> 2)) >> 1)) & 3) * 2);
        int v398 = v397[v864];
        int * v399 = v32->cache_tags;
        int v400 = v399[v864];
        int * v401 = v32->cache_age;
        int v402 = v401[v836];
        int * v403 = v32->cache_tags;
        int v404 = v403[v836];
        int * v405 = v32->cache_dirty;
        int v869 = (4 + ((((int)((unsigned int)((int)((unsigned int)v69 >> 2)) >> 1)) & 3) * 2)) + ((((v398 + ((~(((v400 ^ -1) | (-(v400 ^ -1))) >> 31)) & 2)) - (v402 + ((~(((v404 ^ -1) | (-(v404 ^ -1))) >> 31)) & 2))) >> 31) & 1);
        int v406 = v405[v869];
        bool v870 = !(v406 == 0);
        if (v870) {
          int * v407 = v32->cache_tags;
          int v408 = v407[v869];
          int * v409 = v32->cache_vals;
          int v873 = ((4 + ((((int)((unsigned int)((int)((unsigned int)v69 >> 2)) >> 1)) & 3) * 2)) + ((((v398 + ((~(((v400 ^ -1) | (-(v400 ^ -1))) >> 31)) & 2)) - (v402 + ((~(((v404 ^ -1) | (-(v404 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
          int v410 = v409[v873];
          int * v411 = v32->cache_vals;
          int v875 = (((4 + ((((int)((unsigned int)((int)((unsigned int)v69 >> 2)) >> 1)) & 3) * 2)) + ((((v398 + ((~(((v400 ^ -1) | (-(v400 ^ -1))) >> 31)) & 2)) - (v402 + ((~(((v404 ^ -1) | (-(v404 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
          int v412 = v411[v875];
          int * v413 = v32->mem;
          int v877 = v408 * 2;
          v413[v877] = v410;
          int * v415 = v32->mem;
          int v880 = (v408 * 2) + 1;
          v415[v880] = v412;
          ;
        } else {
          ;
        }
        int * v420 = v32->mem;
        int v885 = ((int)((unsigned int)((int)((unsigned int)v69 >> 2)) >> 1)) * 2;
        int v421 = v420[v885];
        int * v422 = v32->mem;
        int v887 = (((int)((unsigned int)((int)((unsigned int)v69 >> 2)) >> 1)) * 2) + 1;
        int v423 = v422[v887];
        int * v424 = v32->cache_vals;
        int v889 = ((4 + ((((int)((unsigned int)((int)((unsigned int)v69 >> 2)) >> 1)) & 3) * 2)) + ((((v398 + ((~(((v400 ^ -1) | (-(v400 ^ -1))) >> 31)) & 2)) - (v402 + ((~(((v404 ^ -1) | (-(v404 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
        v424[v889] = v421;
        int * v426 = v32->cache_vals;
        int v892 = (((4 + ((((int)((unsigned int)((int)((unsigned int)v69 >> 2)) >> 1)) & 3) * 2)) + ((((v398 + ((~(((v400 ^ -1) | (-(v400 ^ -1))) >> 31)) & 2)) - (v402 + ((~(((v404 ^ -1) | (-(v404 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
        v426[v892] = v423;
        int * v428 = v32->cache_tags;
        int v895 = (int)((unsigned int)((int)((unsigned int)v69 >> 2)) >> 1);
        v428[v869] = v895;
        int * v430 = v32->cache_dirty;
        v430[v869] = 0;
        int * v432 = v32->cache_age;
        v432[v869] = 1;
        int * v434 = v32->cache_age;
        int v435 = v434[v869];
        int * v436 = v32->cache_age;
        int v437 = v436[v834];
        int * v438 = v32->cache_age;
        int v902 = v437 + ((int)((unsigned int)(v437 - v435) >> 31));
        v438[v834] = v902;
        int * v440 = v32->cache_age;
        int v441 = v440[v836];
        int * v442 = v32->cache_age;
        int v905 = v441 + ((int)((unsigned int)(v441 - v435) >> 31));
        v442[v836] = v905;
        int * v444 = v32->cache_age;
        v444[v869] = 0;
        v447 = v869;
      }
      int * v448 = v32->cache_vals;
      int v908 = v447 * 2;
      int v449 = v448[v908];
      int * v450 = v32->cache_vals;
      int v910 = (v447 * 2) + 1;
      int v451 = v450[v910];
      int * v452 = v32->cache_vals;
      int v912 = (((((int)((unsigned int)((int)((unsigned int)v69 >> 2)) >> 1)) & 1) * 2) + ((((v377 + ((~(((v379 ^ -1) | (-(v379 ^ -1))) >> 31)) & 2)) - (v381 + ((~(((v383 ^ -1) | (-(v383 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
      v452[v912] = v449;
      int * v454 = v32->cache_vals;
      int v915 = ((((((int)((unsigned int)((int)((unsigned int)v69 >> 2)) >> 1)) & 1) * 2) + ((((v377 + ((~(((v379 ^ -1) | (-(v379 ^ -1))) >> 31)) & 2)) - (v381 + ((~(((v383 ^ -1) | (-(v383 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
      v454[v915] = v451;
      int * v456 = v32->cache_tags;
      int v918 = ((((int)((unsigned int)((int)((unsigned int)v69 >> 2)) >> 1)) & 1) * 2) + ((((v377 + ((~(((v379 ^ -1) | (-(v379 ^ -1))) >> 31)) & 2)) - (v381 + ((~(((v383 ^ -1) | (-(v383 ^ -1))) >> 31)) & 2))) >> 31) & 1);
      int v919 = (int)((unsigned int)((int)((unsigned int)v69 >> 2)) >> 1);
      v456[v918] = v919;
      int * v458 = v32->cache_dirty;
      v458[v918] = 0;
      int * v460 = v32->cache_age;
      v460[v918] = 1;
      int * v462 = v32->cache_age;
      int v463 = v462[v918];
      int * v464 = v32->cache_age;
      int v465 = v464[v830];
      int * v466 = v32->cache_age;
      int v926 = v465 + ((int)((unsigned int)(v465 - v463) >> 31));
      v466[v830] = v926;
      int * v468 = v32->cache_age;
      int v469 = v468[v832];
      int * v470 = v32->cache_age;
      int v929 = v469 + ((int)((unsigned int)(v469 - v463) >> 31));
      v470[v832] = v929;
      int * v472 = v32->cache_age;
      v472[v918] = 0;
      v475 = v918;
    }
    int * v476 = v32->cache_vals;
    int v932 = (v475 * 2) + (((int)((unsigned int)v69 >> 2)) & 1);
    v476[v932] = v71;
    int * v478 = v32->cache_tags;
    int v479 = v478[v834];
    int * v480 = v32->cache_tags;
    int v481 = v480[v836];
    bool v936 = !(((~(((v479 ^ ((int)((unsigned int)((int)((unsigned int)v69 >> 2)) >> 1))) | (-(v479 ^ ((int)((unsigned int)((int)((unsigned int)v69 >> 2)) >> 1))))) >> 31)) | (~(((v481 ^ ((int)((unsigned int)((int)((unsigned int)v69 >> 2)) >> 1))) | (-(v481 ^ ((int)((unsigned int)((int)((unsigned int)v69 >> 2)) >> 1))))) >> 31))) == 0);
    int v545;
    if (v936) {
      int * v482 = v32->cache_age;
      int v938 = (4 + ((((int)((unsigned int)((int)((unsigned int)v69 >> 2)) >> 1)) & 3) * 2)) + ((~(((v481 ^ ((int)((unsigned int)((int)((unsigned int)v69 >> 2)) >> 1))) | (-(v481 ^ ((int)((unsigned int)((int)((unsigned int)v69 >> 2)) >> 1))))) >> 31)) & 1);
      int v483 = v482[v938];
      int * v484 = v32->cache_age;
      int v485 = v484[v834];
      int * v486 = v32->cache_age;
      int v941 = v485 + ((int)((unsigned int)(v485 - v483) >> 31));
      v486[v834] = v941;
      int * v488 = v32->cache_age;
      int v489 = v488[v836];
      int * v490 = v32->cache_age;
      int v944 = v489 + ((int)((unsigned int)(v489 - v483) >> 31));
      v490[v836] = v944;
      int * v492 = v32->cache_age;
      v492[v938] = 0;
      v545 = v938;
    } else {
      int * v495 = v32->cache_age;
      int v947 = 4 + ((((int)((unsigned int)((int)((unsigned int)v69 >> 2)) >> 1)) & 3) * 2);
      int v496 = v495[v947];
      int * v497 = v32->cache_tags;
      int v498 = v497[v947];
      int * v499 = v32->cache_age;
      int v500 = v499[v836];
      int * v501 = v32->cache_tags;
      int v502 = v501[v836];
      int * v503 = v32->cache_dirty;
      int v952 = (4 + ((((int)((unsigned int)((int)((unsigned int)v69 >> 2)) >> 1)) & 3) * 2)) + ((((v496 + ((~(((v498 ^ -1) | (-(v498 ^ -1))) >> 31)) & 2)) - (v500 + ((~(((v502 ^ -1) | (-(v502 ^ -1))) >> 31)) & 2))) >> 31) & 1);
      int v504 = v503[v952];
      bool v953 = !(v504 == 0);
      if (v953) {
        int * v505 = v32->cache_tags;
        int v506 = v505[v952];
        int * v507 = v32->cache_vals;
        int v956 = ((4 + ((((int)((unsigned int)((int)((unsigned int)v69 >> 2)) >> 1)) & 3) * 2)) + ((((v496 + ((~(((v498 ^ -1) | (-(v498 ^ -1))) >> 31)) & 2)) - (v500 + ((~(((v502 ^ -1) | (-(v502 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
        int v508 = v507[v956];
        int * v509 = v32->cache_vals;
        int v958 = (((4 + ((((int)((unsigned int)((int)((unsigned int)v69 >> 2)) >> 1)) & 3) * 2)) + ((((v496 + ((~(((v498 ^ -1) | (-(v498 ^ -1))) >> 31)) & 2)) - (v500 + ((~(((v502 ^ -1) | (-(v502 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
        int v510 = v509[v958];
        int * v511 = v32->mem;
        int v960 = v506 * 2;
        v511[v960] = v508;
        int * v513 = v32->mem;
        int v963 = (v506 * 2) + 1;
        v513[v963] = v510;
        ;
      } else {
        ;
      }
      int * v518 = v32->mem;
      int v968 = ((int)((unsigned int)((int)((unsigned int)v69 >> 2)) >> 1)) * 2;
      int v519 = v518[v968];
      int * v520 = v32->mem;
      int v970 = (((int)((unsigned int)((int)((unsigned int)v69 >> 2)) >> 1)) * 2) + 1;
      int v521 = v520[v970];
      int * v522 = v32->cache_vals;
      int v972 = ((4 + ((((int)((unsigned int)((int)((unsigned int)v69 >> 2)) >> 1)) & 3) * 2)) + ((((v496 + ((~(((v498 ^ -1) | (-(v498 ^ -1))) >> 31)) & 2)) - (v500 + ((~(((v502 ^ -1) | (-(v502 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
      v522[v972] = v519;
      int * v524 = v32->cache_vals;
      int v975 = (((4 + ((((int)((unsigned int)((int)((unsigned int)v69 >> 2)) >> 1)) & 3) * 2)) + ((((v496 + ((~(((v498 ^ -1) | (-(v498 ^ -1))) >> 31)) & 2)) - (v500 + ((~(((v502 ^ -1) | (-(v502 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
      v524[v975] = v521;
      int * v526 = v32->cache_tags;
      int v978 = (int)((unsigned int)((int)((unsigned int)v69 >> 2)) >> 1);
      v526[v952] = v978;
      int * v528 = v32->cache_dirty;
      v528[v952] = 0;
      int * v530 = v32->cache_age;
      v530[v952] = 1;
      int * v532 = v32->cache_age;
      int v533 = v532[v952];
      int * v534 = v32->cache_age;
      int v535 = v534[v834];
      int * v536 = v32->cache_age;
      int v985 = v535 + ((int)((unsigned int)(v535 - v533) >> 31));
      v536[v834] = v985;
      int * v538 = v32->cache_age;
      int v539 = v538[v836];
      int * v540 = v32->cache_age;
      int v988 = v539 + ((int)((unsigned int)(v539 - v533) >> 31));
      v540[v836] = v988;
      int * v542 = v32->cache_age;
      v542[v952] = 0;
      v545 = v952;
    }
    int * v546 = v32->cache_vals;
    int v991 = (v545 * 2) + (((int)((unsigned int)v69 >> 2)) & 1);
    v546[v991] = v71;
    int * v548 = v32->cache_dirty;
    v548[v545] = 1;
    bool v995 = (((int)((unsigned int)v79 >> 2)) == ((int)((unsigned int)v69 >> 2))) | (((((int)((unsigned int)v220 >> 2)) & 3) == (((int)((unsigned int)v69 >> 2)) & 3)) & (!(((int)((unsigned int)v220 >> 2)) == ((int)((unsigned int)v69 >> 2)))));
    struct StateT * v563;
    if (v995) {
      int v550 = v32->timer;
      int v996 = v550 + 15;
      v32->timer = v996;
      int * v552 = v32->saved_regs;
      int v553 = v552[11];
      int * v554 = v32->regs;
      v554[11] = v553;
      int * v556 = v32->saved_regs;
      int v557 = v556[12];
      int * v558 = v32->regs;
      v558[12] = v557;
      struct StateT * v560 = slot_6(v32);
      v563 = v560;
    } else {
      v563 = v32;
    }
    v565 = v563;
  }
  return v565;
}

struct StateT * slot_7(struct StateT * v1257) {
  int v1258 = v1257->timer;
  int v1266 = v1258 + 1;
  v1257->timer = v1266;
  int * v1260 = v1257->regs;
  int v1261 = v1260[11];
  int * v1262 = v1257->regs;
  int v1270 = v1261 << 2;
  v1262[11] = v1270;
  struct StateT * v1264 = slot_8(v1257);
  return v1264;
}

struct StateT * slot_0(struct StateT * v2) {
  int v3 = v2->timer;
  int v11 = v3 + 1;
  v2->timer = v11;
  int * v5 = v2->regs;
  int v6 = v5[10];
  int * v7 = v2->regs;
  int v16 = v6 & 28;
  v7[5] = v16;
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