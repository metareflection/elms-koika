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

struct StateT * slot_12(struct StateT * v1142);
struct StateT * slot_14(struct StateT * v1217);
struct StateT * slot_6(struct StateT * v565);
struct StateT * slot_16(struct StateT * v1249);
struct StateT * slot_5(struct StateT * v541);
struct StateT * slot_17(struct StateT * v1269);
struct StateT * slot_2(struct StateT * v501);
struct StateT * slot_7(struct StateT * v585);
struct StateT * slot_3(struct StateT * v513);
struct StateT * snippet(struct StateT * v0);
struct StateT * slot_10(struct StateT * v866);
struct StateT * slot_1(struct StateT * v251);
struct StateT * slot_8(struct StateT * v834);
struct StateT * slot_4(struct StateT * v533);
struct StateT * slot_13(struct StateT * v1169);
struct StateT * slot_15(struct StateT * v1233);
struct StateT * slot_18(struct StateT * v1654);
struct StateT * slot_9(struct StateT * v850);
struct StateT * slot_11(struct StateT * v893);
struct StateT * slot_0(struct StateT * v2);
struct StateT * slot_12(struct StateT * v1142) {
  int * v1143 = v1142->saved_regs;
  int * v1144 = v1142->regs;
  int v1145 = v1144[12];
  v1143[12] = v1145;
  int v1147 = v1142->timer;
  int v1161 = v1147 + 1;
  v1142->timer = v1161;
  int * v1149 = v1142->regs;
  int v1150 = v1149[12];
  int * v1151 = v1142->regs;
  int v1152 = v1151[11];
  int * v1153 = v1142->regs;
  int v1166 = v1150 + v1152;
  v1153[12] = v1166;
  struct StateT * v1155 = slot_13(v1142);
  return v1155;
}

struct StateT * slot_14(struct StateT * v1217) {
  int v1218 = v1217->timer;
  int v1226 = v1218 + 1;
  v1217->timer = v1226;
  int * v1220 = v1217->regs;
  int v1221 = v1220[10];
  int * v1222 = v1217->regs;
  int v1230 = v1221 & 7;
  v1222[10] = v1230;
  struct StateT * v1224 = slot_15(v1217);
  return v1224;
}

struct StateT * slot_6(struct StateT * v565) {
  int v566 = v565->timer;
  int v576 = v566 + 1;
  v565->timer = v576;
  int * v568 = v565->regs;
  int v569 = v568[11];
  int * v570 = v565->regs;
  int v571 = v570[14];
  int * v572 = v565->regs;
  int v582 = v569 + v571;
  v572[14] = v582;
  struct StateT * v574 = slot_7(v565);
  return v574;
}

struct StateT * slot_16(struct StateT * v1249) {
  int v1250 = v1249->timer;
  int v1260 = v1250 + 1;
  v1249->timer = v1260;
  int * v1252 = v1249->regs;
  int v1253 = v1252[13];
  int * v1254 = v1249->regs;
  int v1255 = v1254[10];
  int * v1256 = v1249->regs;
  int v1266 = v1253 + v1255;
  v1256[10] = v1266;
  struct StateT * v1258 = slot_17(v1249);
  return v1258;
}

struct StateT * slot_5(struct StateT * v541) {
  int * v542 = v541->saved_regs;
  int * v543 = v541->regs;
  int v544 = v543[14];
  v542[14] = v544;
  int v546 = v541->timer;
  int v558 = v546 + 1;
  v541->timer = v558;
  int * v548 = v541->regs;
  int v549 = v548[10];
  int * v550 = v541->regs;
  int v562 = v549 << 2;
  v550[14] = v562;
  struct StateT * v552 = slot_6(v541);
  return v552;
}

struct StateT * slot_17(struct StateT * v1269) {
  int v1270 = v1269->timer;
  int v1475 = v1270 + 1;
  v1269->timer = v1475;
  int * v1272 = v1269->regs;
  int v1273 = v1272[10];
  int * v1274 = v1269->regs;
  int v1275 = v1274[12];
  int * v1276 = v1269->cache_tags;
  int v1481 = (((int)((unsigned int)((int)((unsigned int)v1273 >> 2)) >> 1)) & 1) * 2;
  int v1277 = v1276[v1481];
  int * v1278 = v1269->cache_tags;
  int v1483 = ((((int)((unsigned int)((int)((unsigned int)v1273 >> 2)) >> 1)) & 1) * 2) + 1;
  int v1279 = v1278[v1483];
  int * v1280 = v1269->cache_tags;
  int v1485 = 4 + ((((int)((unsigned int)((int)((unsigned int)v1273 >> 2)) >> 1)) & 3) * 2);
  int v1281 = v1280[v1485];
  int * v1282 = v1269->cache_tags;
  int v1487 = (4 + ((((int)((unsigned int)((int)((unsigned int)v1273 >> 2)) >> 1)) & 3) * 2)) + 1;
  int v1283 = v1282[v1487];
  int v1284 = v1269->timer;
  int v1488 = v1284 + ((100 ^ (((~(((v1281 ^ ((int)((unsigned int)((int)((unsigned int)v1273 >> 2)) >> 1))) | (-(v1281 ^ ((int)((unsigned int)((int)((unsigned int)v1273 >> 2)) >> 1))))) >> 31)) | (~(((v1283 ^ ((int)((unsigned int)((int)((unsigned int)v1273 >> 2)) >> 1))) | (-(v1283 ^ ((int)((unsigned int)((int)((unsigned int)v1273 >> 2)) >> 1))))) >> 31))) & 104)) ^ (((~(((v1277 ^ ((int)((unsigned int)((int)((unsigned int)v1273 >> 2)) >> 1))) | (-(v1277 ^ ((int)((unsigned int)((int)((unsigned int)v1273 >> 2)) >> 1))))) >> 31)) | (~(((v1279 ^ ((int)((unsigned int)((int)((unsigned int)v1273 >> 2)) >> 1))) | (-(v1279 ^ ((int)((unsigned int)((int)((unsigned int)v1273 >> 2)) >> 1))))) >> 31))) & (1 ^ (100 ^ (((~(((v1281 ^ ((int)((unsigned int)((int)((unsigned int)v1273 >> 2)) >> 1))) | (-(v1281 ^ ((int)((unsigned int)((int)((unsigned int)v1273 >> 2)) >> 1))))) >> 31)) | (~(((v1283 ^ ((int)((unsigned int)((int)((unsigned int)v1273 >> 2)) >> 1))) | (-(v1283 ^ ((int)((unsigned int)((int)((unsigned int)v1273 >> 2)) >> 1))))) >> 31))) & 104)))));
  v1269->timer = v1488;
  bool v1489 = !(((~(((v1277 ^ ((int)((unsigned int)((int)((unsigned int)v1273 >> 2)) >> 1))) | (-(v1277 ^ ((int)((unsigned int)((int)((unsigned int)v1273 >> 2)) >> 1))))) >> 31)) | (~(((v1279 ^ ((int)((unsigned int)((int)((unsigned int)v1273 >> 2)) >> 1))) | (-(v1279 ^ ((int)((unsigned int)((int)((unsigned int)v1273 >> 2)) >> 1))))) >> 31))) == 0);
  int v1398;
  if (v1489) {
    int * v1286 = v1269->cache_age;
    int v1491 = ((((int)((unsigned int)((int)((unsigned int)v1273 >> 2)) >> 1)) & 1) * 2) + ((~(((v1279 ^ ((int)((unsigned int)((int)((unsigned int)v1273 >> 2)) >> 1))) | (-(v1279 ^ ((int)((unsigned int)((int)((unsigned int)v1273 >> 2)) >> 1))))) >> 31)) & 1);
    int v1287 = v1286[v1491];
    int * v1288 = v1269->cache_age;
    int v1289 = v1288[v1481];
    int * v1290 = v1269->cache_age;
    int v1494 = v1289 + ((int)((unsigned int)(v1289 - v1287) >> 31));
    v1290[v1481] = v1494;
    int * v1292 = v1269->cache_age;
    int v1293 = v1292[v1483];
    int * v1294 = v1269->cache_age;
    int v1497 = v1293 + ((int)((unsigned int)(v1293 - v1287) >> 31));
    v1294[v1483] = v1497;
    int * v1296 = v1269->cache_age;
    v1296[v1491] = 0;
    v1398 = v1491;
  } else {
    int * v1299 = v1269->cache_age;
    int v1501 = (((int)((unsigned int)((int)((unsigned int)v1273 >> 2)) >> 1)) & 1) * 2;
    int v1300 = v1299[v1501];
    int * v1301 = v1269->cache_tags;
    int v1302 = v1301[v1501];
    int * v1303 = v1269->cache_age;
    int v1304 = v1303[v1483];
    int * v1305 = v1269->cache_tags;
    int v1306 = v1305[v1483];
    bool v1505 = !(((~(((v1281 ^ ((int)((unsigned int)((int)((unsigned int)v1273 >> 2)) >> 1))) | (-(v1281 ^ ((int)((unsigned int)((int)((unsigned int)v1273 >> 2)) >> 1))))) >> 31)) | (~(((v1283 ^ ((int)((unsigned int)((int)((unsigned int)v1273 >> 2)) >> 1))) | (-(v1283 ^ ((int)((unsigned int)((int)((unsigned int)v1273 >> 2)) >> 1))))) >> 31))) == 0);
    int v1370;
    if (v1505) {
      int * v1307 = v1269->cache_age;
      int v1507 = (4 + ((((int)((unsigned int)((int)((unsigned int)v1273 >> 2)) >> 1)) & 3) * 2)) + ((~(((v1283 ^ ((int)((unsigned int)((int)((unsigned int)v1273 >> 2)) >> 1))) | (-(v1283 ^ ((int)((unsigned int)((int)((unsigned int)v1273 >> 2)) >> 1))))) >> 31)) & 1);
      int v1308 = v1307[v1507];
      int * v1309 = v1269->cache_age;
      int v1310 = v1309[v1485];
      int * v1311 = v1269->cache_age;
      int v1510 = v1310 + ((int)((unsigned int)(v1310 - v1308) >> 31));
      v1311[v1485] = v1510;
      int * v1313 = v1269->cache_age;
      int v1314 = v1313[v1487];
      int * v1315 = v1269->cache_age;
      int v1513 = v1314 + ((int)((unsigned int)(v1314 - v1308) >> 31));
      v1315[v1487] = v1513;
      int * v1317 = v1269->cache_age;
      v1317[v1507] = 0;
      v1370 = v1507;
    } else {
      int * v1320 = v1269->cache_age;
      int v1517 = 4 + ((((int)((unsigned int)((int)((unsigned int)v1273 >> 2)) >> 1)) & 3) * 2);
      int v1321 = v1320[v1517];
      int * v1322 = v1269->cache_tags;
      int v1323 = v1322[v1517];
      int * v1324 = v1269->cache_age;
      int v1325 = v1324[v1487];
      int * v1326 = v1269->cache_tags;
      int v1327 = v1326[v1487];
      int * v1328 = v1269->cache_dirty;
      int v1522 = (4 + ((((int)((unsigned int)((int)((unsigned int)v1273 >> 2)) >> 1)) & 3) * 2)) + ((((v1321 + ((~(((v1323 ^ -1) | (-(v1323 ^ -1))) >> 31)) & 2)) - (v1325 + ((~(((v1327 ^ -1) | (-(v1327 ^ -1))) >> 31)) & 2))) >> 31) & 1);
      int v1329 = v1328[v1522];
      bool v1523 = !(v1329 == 0);
      if (v1523) {
        int * v1330 = v1269->cache_tags;
        int v1331 = v1330[v1522];
        int * v1332 = v1269->cache_vals;
        int v1526 = ((4 + ((((int)((unsigned int)((int)((unsigned int)v1273 >> 2)) >> 1)) & 3) * 2)) + ((((v1321 + ((~(((v1323 ^ -1) | (-(v1323 ^ -1))) >> 31)) & 2)) - (v1325 + ((~(((v1327 ^ -1) | (-(v1327 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
        int v1333 = v1332[v1526];
        int * v1334 = v1269->cache_vals;
        int v1528 = (((4 + ((((int)((unsigned int)((int)((unsigned int)v1273 >> 2)) >> 1)) & 3) * 2)) + ((((v1321 + ((~(((v1323 ^ -1) | (-(v1323 ^ -1))) >> 31)) & 2)) - (v1325 + ((~(((v1327 ^ -1) | (-(v1327 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
        int v1335 = v1334[v1528];
        int * v1336 = v1269->mem;
        int v1530 = v1331 * 2;
        v1336[v1530] = v1333;
        int * v1338 = v1269->mem;
        int v1533 = (v1331 * 2) + 1;
        v1338[v1533] = v1335;
        ;
      } else {
        ;
      }
      int * v1343 = v1269->mem;
      int v1538 = ((int)((unsigned int)((int)((unsigned int)v1273 >> 2)) >> 1)) * 2;
      int v1344 = v1343[v1538];
      int * v1345 = v1269->mem;
      int v1540 = (((int)((unsigned int)((int)((unsigned int)v1273 >> 2)) >> 1)) * 2) + 1;
      int v1346 = v1345[v1540];
      int * v1347 = v1269->cache_vals;
      int v1542 = ((4 + ((((int)((unsigned int)((int)((unsigned int)v1273 >> 2)) >> 1)) & 3) * 2)) + ((((v1321 + ((~(((v1323 ^ -1) | (-(v1323 ^ -1))) >> 31)) & 2)) - (v1325 + ((~(((v1327 ^ -1) | (-(v1327 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
      v1347[v1542] = v1344;
      int * v1349 = v1269->cache_vals;
      int v1545 = (((4 + ((((int)((unsigned int)((int)((unsigned int)v1273 >> 2)) >> 1)) & 3) * 2)) + ((((v1321 + ((~(((v1323 ^ -1) | (-(v1323 ^ -1))) >> 31)) & 2)) - (v1325 + ((~(((v1327 ^ -1) | (-(v1327 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
      v1349[v1545] = v1346;
      int * v1351 = v1269->cache_tags;
      int v1548 = (int)((unsigned int)((int)((unsigned int)v1273 >> 2)) >> 1);
      v1351[v1522] = v1548;
      int * v1353 = v1269->cache_dirty;
      v1353[v1522] = 0;
      int * v1355 = v1269->cache_age;
      v1355[v1522] = 1;
      int * v1357 = v1269->cache_age;
      int v1358 = v1357[v1522];
      int * v1359 = v1269->cache_age;
      int v1360 = v1359[v1485];
      int * v1361 = v1269->cache_age;
      int v1556 = v1360 + ((int)((unsigned int)(v1360 - v1358) >> 31));
      v1361[v1485] = v1556;
      int * v1363 = v1269->cache_age;
      int v1364 = v1363[v1487];
      int * v1365 = v1269->cache_age;
      int v1559 = v1364 + ((int)((unsigned int)(v1364 - v1358) >> 31));
      v1365[v1487] = v1559;
      int * v1367 = v1269->cache_age;
      v1367[v1522] = 0;
      v1370 = v1522;
    }
    int * v1371 = v1269->cache_vals;
    int v1562 = v1370 * 2;
    int v1372 = v1371[v1562];
    int * v1373 = v1269->cache_vals;
    int v1564 = (v1370 * 2) + 1;
    int v1374 = v1373[v1564];
    int * v1375 = v1269->cache_vals;
    int v1566 = (((((int)((unsigned int)((int)((unsigned int)v1273 >> 2)) >> 1)) & 1) * 2) + ((((v1300 + ((~(((v1302 ^ -1) | (-(v1302 ^ -1))) >> 31)) & 2)) - (v1304 + ((~(((v1306 ^ -1) | (-(v1306 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
    v1375[v1566] = v1372;
    int * v1377 = v1269->cache_vals;
    int v1569 = ((((((int)((unsigned int)((int)((unsigned int)v1273 >> 2)) >> 1)) & 1) * 2) + ((((v1300 + ((~(((v1302 ^ -1) | (-(v1302 ^ -1))) >> 31)) & 2)) - (v1304 + ((~(((v1306 ^ -1) | (-(v1306 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
    v1377[v1569] = v1374;
    int * v1379 = v1269->cache_tags;
    int v1572 = ((((int)((unsigned int)((int)((unsigned int)v1273 >> 2)) >> 1)) & 1) * 2) + ((((v1300 + ((~(((v1302 ^ -1) | (-(v1302 ^ -1))) >> 31)) & 2)) - (v1304 + ((~(((v1306 ^ -1) | (-(v1306 ^ -1))) >> 31)) & 2))) >> 31) & 1);
    int v1573 = (int)((unsigned int)((int)((unsigned int)v1273 >> 2)) >> 1);
    v1379[v1572] = v1573;
    int * v1381 = v1269->cache_dirty;
    v1381[v1572] = 0;
    int * v1383 = v1269->cache_age;
    v1383[v1572] = 1;
    int * v1385 = v1269->cache_age;
    int v1386 = v1385[v1572];
    int * v1387 = v1269->cache_age;
    int v1388 = v1387[v1481];
    int * v1389 = v1269->cache_age;
    int v1581 = v1388 + ((int)((unsigned int)(v1388 - v1386) >> 31));
    v1389[v1481] = v1581;
    int * v1391 = v1269->cache_age;
    int v1392 = v1391[v1483];
    int * v1393 = v1269->cache_age;
    int v1584 = v1392 + ((int)((unsigned int)(v1392 - v1386) >> 31));
    v1393[v1483] = v1584;
    int * v1395 = v1269->cache_age;
    v1395[v1572] = 0;
    v1398 = v1572;
  }
  int * v1399 = v1269->cache_vals;
  int v1587 = (v1398 * 2) + (((int)((unsigned int)v1273 >> 2)) & 1);
  v1399[v1587] = v1275;
  int * v1401 = v1269->cache_tags;
  int v1402 = v1401[v1485];
  int * v1403 = v1269->cache_tags;
  int v1404 = v1403[v1487];
  bool v1591 = !(((~(((v1402 ^ ((int)((unsigned int)((int)((unsigned int)v1273 >> 2)) >> 1))) | (-(v1402 ^ ((int)((unsigned int)((int)((unsigned int)v1273 >> 2)) >> 1))))) >> 31)) | (~(((v1404 ^ ((int)((unsigned int)((int)((unsigned int)v1273 >> 2)) >> 1))) | (-(v1404 ^ ((int)((unsigned int)((int)((unsigned int)v1273 >> 2)) >> 1))))) >> 31))) == 0);
  int v1468;
  if (v1591) {
    int * v1405 = v1269->cache_age;
    int v1593 = (4 + ((((int)((unsigned int)((int)((unsigned int)v1273 >> 2)) >> 1)) & 3) * 2)) + ((~(((v1404 ^ ((int)((unsigned int)((int)((unsigned int)v1273 >> 2)) >> 1))) | (-(v1404 ^ ((int)((unsigned int)((int)((unsigned int)v1273 >> 2)) >> 1))))) >> 31)) & 1);
    int v1406 = v1405[v1593];
    int * v1407 = v1269->cache_age;
    int v1408 = v1407[v1485];
    int * v1409 = v1269->cache_age;
    int v1596 = v1408 + ((int)((unsigned int)(v1408 - v1406) >> 31));
    v1409[v1485] = v1596;
    int * v1411 = v1269->cache_age;
    int v1412 = v1411[v1487];
    int * v1413 = v1269->cache_age;
    int v1599 = v1412 + ((int)((unsigned int)(v1412 - v1406) >> 31));
    v1413[v1487] = v1599;
    int * v1415 = v1269->cache_age;
    v1415[v1593] = 0;
    v1468 = v1593;
  } else {
    int * v1418 = v1269->cache_age;
    int v1603 = 4 + ((((int)((unsigned int)((int)((unsigned int)v1273 >> 2)) >> 1)) & 3) * 2);
    int v1419 = v1418[v1603];
    int * v1420 = v1269->cache_tags;
    int v1421 = v1420[v1603];
    int * v1422 = v1269->cache_age;
    int v1423 = v1422[v1487];
    int * v1424 = v1269->cache_tags;
    int v1425 = v1424[v1487];
    int * v1426 = v1269->cache_dirty;
    int v1608 = (4 + ((((int)((unsigned int)((int)((unsigned int)v1273 >> 2)) >> 1)) & 3) * 2)) + ((((v1419 + ((~(((v1421 ^ -1) | (-(v1421 ^ -1))) >> 31)) & 2)) - (v1423 + ((~(((v1425 ^ -1) | (-(v1425 ^ -1))) >> 31)) & 2))) >> 31) & 1);
    int v1427 = v1426[v1608];
    bool v1609 = !(v1427 == 0);
    if (v1609) {
      int * v1428 = v1269->cache_tags;
      int v1429 = v1428[v1608];
      int * v1430 = v1269->cache_vals;
      int v1612 = ((4 + ((((int)((unsigned int)((int)((unsigned int)v1273 >> 2)) >> 1)) & 3) * 2)) + ((((v1419 + ((~(((v1421 ^ -1) | (-(v1421 ^ -1))) >> 31)) & 2)) - (v1423 + ((~(((v1425 ^ -1) | (-(v1425 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
      int v1431 = v1430[v1612];
      int * v1432 = v1269->cache_vals;
      int v1614 = (((4 + ((((int)((unsigned int)((int)((unsigned int)v1273 >> 2)) >> 1)) & 3) * 2)) + ((((v1419 + ((~(((v1421 ^ -1) | (-(v1421 ^ -1))) >> 31)) & 2)) - (v1423 + ((~(((v1425 ^ -1) | (-(v1425 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
      int v1433 = v1432[v1614];
      int * v1434 = v1269->mem;
      int v1616 = v1429 * 2;
      v1434[v1616] = v1431;
      int * v1436 = v1269->mem;
      int v1619 = (v1429 * 2) + 1;
      v1436[v1619] = v1433;
      ;
    } else {
      ;
    }
    int * v1441 = v1269->mem;
    int v1624 = ((int)((unsigned int)((int)((unsigned int)v1273 >> 2)) >> 1)) * 2;
    int v1442 = v1441[v1624];
    int * v1443 = v1269->mem;
    int v1626 = (((int)((unsigned int)((int)((unsigned int)v1273 >> 2)) >> 1)) * 2) + 1;
    int v1444 = v1443[v1626];
    int * v1445 = v1269->cache_vals;
    int v1628 = ((4 + ((((int)((unsigned int)((int)((unsigned int)v1273 >> 2)) >> 1)) & 3) * 2)) + ((((v1419 + ((~(((v1421 ^ -1) | (-(v1421 ^ -1))) >> 31)) & 2)) - (v1423 + ((~(((v1425 ^ -1) | (-(v1425 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
    v1445[v1628] = v1442;
    int * v1447 = v1269->cache_vals;
    int v1631 = (((4 + ((((int)((unsigned int)((int)((unsigned int)v1273 >> 2)) >> 1)) & 3) * 2)) + ((((v1419 + ((~(((v1421 ^ -1) | (-(v1421 ^ -1))) >> 31)) & 2)) - (v1423 + ((~(((v1425 ^ -1) | (-(v1425 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
    v1447[v1631] = v1444;
    int * v1449 = v1269->cache_tags;
    int v1634 = (int)((unsigned int)((int)((unsigned int)v1273 >> 2)) >> 1);
    v1449[v1608] = v1634;
    int * v1451 = v1269->cache_dirty;
    v1451[v1608] = 0;
    int * v1453 = v1269->cache_age;
    v1453[v1608] = 1;
    int * v1455 = v1269->cache_age;
    int v1456 = v1455[v1608];
    int * v1457 = v1269->cache_age;
    int v1458 = v1457[v1485];
    int * v1459 = v1269->cache_age;
    int v1642 = v1458 + ((int)((unsigned int)(v1458 - v1456) >> 31));
    v1459[v1485] = v1642;
    int * v1461 = v1269->cache_age;
    int v1462 = v1461[v1487];
    int * v1463 = v1269->cache_age;
    int v1645 = v1462 + ((int)((unsigned int)(v1462 - v1456) >> 31));
    v1463[v1487] = v1645;
    int * v1465 = v1269->cache_age;
    v1465[v1608] = 0;
    v1468 = v1608;
  }
  int * v1469 = v1269->cache_vals;
  int v1648 = (v1468 * 2) + (((int)((unsigned int)v1273 >> 2)) & 1);
  v1469[v1648] = v1275;
  int * v1471 = v1269->cache_dirty;
  v1471[v1468] = 1;
  struct StateT * v1473 = slot_18(v1269);
  return v1473;
}

struct StateT * slot_2(struct StateT * v501) {
  int v502 = v501->timer;
  int v508 = v502 + 1;
  v501->timer = v508;
  int * v504 = v501->regs;
  v504[15] = 15;
  struct StateT * v506 = slot_3(v501);
  return v506;
}

struct StateT * slot_7(struct StateT * v585) {
  int v586 = v585->timer;
  int v719 = v586 + 1;
  v585->timer = v719;
  int * v588 = v585->regs;
  int v589 = v588[14];
  int * v590 = v585->cache_tags;
  int v723 = (((int)((unsigned int)((int)((unsigned int)v589 >> 2)) >> 1)) & 1) * 2;
  int v591 = v590[v723];
  int * v592 = v585->cache_tags;
  int v725 = ((((int)((unsigned int)((int)((unsigned int)v589 >> 2)) >> 1)) & 1) * 2) + 1;
  int v593 = v592[v725];
  int * v594 = v585->cache_tags;
  int v727 = 4 + ((((int)((unsigned int)((int)((unsigned int)v589 >> 2)) >> 1)) & 3) * 2);
  int v595 = v594[v727];
  int * v596 = v585->cache_tags;
  int v729 = (4 + ((((int)((unsigned int)((int)((unsigned int)v589 >> 2)) >> 1)) & 3) * 2)) + 1;
  int v597 = v596[v729];
  int v598 = v585->timer;
  int v730 = v598 + ((100 ^ (((~(((v595 ^ ((int)((unsigned int)((int)((unsigned int)v589 >> 2)) >> 1))) | (-(v595 ^ ((int)((unsigned int)((int)((unsigned int)v589 >> 2)) >> 1))))) >> 31)) | (~(((v597 ^ ((int)((unsigned int)((int)((unsigned int)v589 >> 2)) >> 1))) | (-(v597 ^ ((int)((unsigned int)((int)((unsigned int)v589 >> 2)) >> 1))))) >> 31))) & 104)) ^ (((~(((v591 ^ ((int)((unsigned int)((int)((unsigned int)v589 >> 2)) >> 1))) | (-(v591 ^ ((int)((unsigned int)((int)((unsigned int)v589 >> 2)) >> 1))))) >> 31)) | (~(((v593 ^ ((int)((unsigned int)((int)((unsigned int)v589 >> 2)) >> 1))) | (-(v593 ^ ((int)((unsigned int)((int)((unsigned int)v589 >> 2)) >> 1))))) >> 31))) & (1 ^ (100 ^ (((~(((v595 ^ ((int)((unsigned int)((int)((unsigned int)v589 >> 2)) >> 1))) | (-(v595 ^ ((int)((unsigned int)((int)((unsigned int)v589 >> 2)) >> 1))))) >> 31)) | (~(((v597 ^ ((int)((unsigned int)((int)((unsigned int)v589 >> 2)) >> 1))) | (-(v597 ^ ((int)((unsigned int)((int)((unsigned int)v589 >> 2)) >> 1))))) >> 31))) & 104)))));
  v585->timer = v730;
  int * v600 = v585->cache_vals;
  bool v731 = !(((~(((v591 ^ ((int)((unsigned int)((int)((unsigned int)v589 >> 2)) >> 1))) | (-(v591 ^ ((int)((unsigned int)((int)((unsigned int)v589 >> 2)) >> 1))))) >> 31)) | (~(((v593 ^ ((int)((unsigned int)((int)((unsigned int)v589 >> 2)) >> 1))) | (-(v593 ^ ((int)((unsigned int)((int)((unsigned int)v589 >> 2)) >> 1))))) >> 31))) == 0);
  int v713;
  if (v731) {
    int * v601 = v585->cache_age;
    int v733 = ((((int)((unsigned int)((int)((unsigned int)v589 >> 2)) >> 1)) & 1) * 2) + ((~(((v593 ^ ((int)((unsigned int)((int)((unsigned int)v589 >> 2)) >> 1))) | (-(v593 ^ ((int)((unsigned int)((int)((unsigned int)v589 >> 2)) >> 1))))) >> 31)) & 1);
    int v602 = v601[v733];
    int * v603 = v585->cache_age;
    int v604 = v603[v723];
    int * v605 = v585->cache_age;
    int v736 = v604 + ((int)((unsigned int)(v604 - v602) >> 31));
    v605[v723] = v736;
    int * v607 = v585->cache_age;
    int v608 = v607[v725];
    int * v609 = v585->cache_age;
    int v739 = v608 + ((int)((unsigned int)(v608 - v602) >> 31));
    v609[v725] = v739;
    int * v611 = v585->cache_age;
    v611[v733] = 0;
    v713 = v733;
  } else {
    int * v614 = v585->cache_age;
    int v743 = (((int)((unsigned int)((int)((unsigned int)v589 >> 2)) >> 1)) & 1) * 2;
    int v615 = v614[v743];
    int * v616 = v585->cache_tags;
    int v617 = v616[v743];
    int * v618 = v585->cache_age;
    int v619 = v618[v725];
    int * v620 = v585->cache_tags;
    int v621 = v620[v725];
    bool v747 = !(((~(((v595 ^ ((int)((unsigned int)((int)((unsigned int)v589 >> 2)) >> 1))) | (-(v595 ^ ((int)((unsigned int)((int)((unsigned int)v589 >> 2)) >> 1))))) >> 31)) | (~(((v597 ^ ((int)((unsigned int)((int)((unsigned int)v589 >> 2)) >> 1))) | (-(v597 ^ ((int)((unsigned int)((int)((unsigned int)v589 >> 2)) >> 1))))) >> 31))) == 0);
    int v685;
    if (v747) {
      int * v622 = v585->cache_age;
      int v749 = (4 + ((((int)((unsigned int)((int)((unsigned int)v589 >> 2)) >> 1)) & 3) * 2)) + ((~(((v597 ^ ((int)((unsigned int)((int)((unsigned int)v589 >> 2)) >> 1))) | (-(v597 ^ ((int)((unsigned int)((int)((unsigned int)v589 >> 2)) >> 1))))) >> 31)) & 1);
      int v623 = v622[v749];
      int * v624 = v585->cache_age;
      int v625 = v624[v727];
      int * v626 = v585->cache_age;
      int v752 = v625 + ((int)((unsigned int)(v625 - v623) >> 31));
      v626[v727] = v752;
      int * v628 = v585->cache_age;
      int v629 = v628[v729];
      int * v630 = v585->cache_age;
      int v755 = v629 + ((int)((unsigned int)(v629 - v623) >> 31));
      v630[v729] = v755;
      int * v632 = v585->cache_age;
      v632[v749] = 0;
      v685 = v749;
    } else {
      int * v635 = v585->cache_age;
      int v759 = 4 + ((((int)((unsigned int)((int)((unsigned int)v589 >> 2)) >> 1)) & 3) * 2);
      int v636 = v635[v759];
      int * v637 = v585->cache_tags;
      int v638 = v637[v759];
      int * v639 = v585->cache_age;
      int v640 = v639[v729];
      int * v641 = v585->cache_tags;
      int v642 = v641[v729];
      int * v643 = v585->cache_dirty;
      int v764 = (4 + ((((int)((unsigned int)((int)((unsigned int)v589 >> 2)) >> 1)) & 3) * 2)) + ((((v636 + ((~(((v638 ^ -1) | (-(v638 ^ -1))) >> 31)) & 2)) - (v640 + ((~(((v642 ^ -1) | (-(v642 ^ -1))) >> 31)) & 2))) >> 31) & 1);
      int v644 = v643[v764];
      bool v765 = !(v644 == 0);
      if (v765) {
        int * v645 = v585->cache_tags;
        int v646 = v645[v764];
        int * v647 = v585->cache_vals;
        int v768 = ((4 + ((((int)((unsigned int)((int)((unsigned int)v589 >> 2)) >> 1)) & 3) * 2)) + ((((v636 + ((~(((v638 ^ -1) | (-(v638 ^ -1))) >> 31)) & 2)) - (v640 + ((~(((v642 ^ -1) | (-(v642 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
        int v648 = v647[v768];
        int * v649 = v585->cache_vals;
        int v770 = (((4 + ((((int)((unsigned int)((int)((unsigned int)v589 >> 2)) >> 1)) & 3) * 2)) + ((((v636 + ((~(((v638 ^ -1) | (-(v638 ^ -1))) >> 31)) & 2)) - (v640 + ((~(((v642 ^ -1) | (-(v642 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
        int v650 = v649[v770];
        int * v651 = v585->mem;
        int v772 = v646 * 2;
        v651[v772] = v648;
        int * v653 = v585->mem;
        int v775 = (v646 * 2) + 1;
        v653[v775] = v650;
        ;
      } else {
        ;
      }
      int * v658 = v585->mem;
      int v780 = ((int)((unsigned int)((int)((unsigned int)v589 >> 2)) >> 1)) * 2;
      int v659 = v658[v780];
      int * v660 = v585->mem;
      int v782 = (((int)((unsigned int)((int)((unsigned int)v589 >> 2)) >> 1)) * 2) + 1;
      int v661 = v660[v782];
      int * v662 = v585->cache_vals;
      int v784 = ((4 + ((((int)((unsigned int)((int)((unsigned int)v589 >> 2)) >> 1)) & 3) * 2)) + ((((v636 + ((~(((v638 ^ -1) | (-(v638 ^ -1))) >> 31)) & 2)) - (v640 + ((~(((v642 ^ -1) | (-(v642 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
      v662[v784] = v659;
      int * v664 = v585->cache_vals;
      int v787 = (((4 + ((((int)((unsigned int)((int)((unsigned int)v589 >> 2)) >> 1)) & 3) * 2)) + ((((v636 + ((~(((v638 ^ -1) | (-(v638 ^ -1))) >> 31)) & 2)) - (v640 + ((~(((v642 ^ -1) | (-(v642 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
      v664[v787] = v661;
      int * v666 = v585->cache_tags;
      int v790 = (int)((unsigned int)((int)((unsigned int)v589 >> 2)) >> 1);
      v666[v764] = v790;
      int * v668 = v585->cache_dirty;
      v668[v764] = 0;
      int * v670 = v585->cache_age;
      v670[v764] = 1;
      int * v672 = v585->cache_age;
      int v673 = v672[v764];
      int * v674 = v585->cache_age;
      int v675 = v674[v727];
      int * v676 = v585->cache_age;
      int v798 = v675 + ((int)((unsigned int)(v675 - v673) >> 31));
      v676[v727] = v798;
      int * v678 = v585->cache_age;
      int v679 = v678[v729];
      int * v680 = v585->cache_age;
      int v801 = v679 + ((int)((unsigned int)(v679 - v673) >> 31));
      v680[v729] = v801;
      int * v682 = v585->cache_age;
      v682[v764] = 0;
      v685 = v764;
    }
    int * v686 = v585->cache_vals;
    int v804 = v685 * 2;
    int v687 = v686[v804];
    int * v688 = v585->cache_vals;
    int v806 = (v685 * 2) + 1;
    int v689 = v688[v806];
    int * v690 = v585->cache_vals;
    int v808 = (((((int)((unsigned int)((int)((unsigned int)v589 >> 2)) >> 1)) & 1) * 2) + ((((v615 + ((~(((v617 ^ -1) | (-(v617 ^ -1))) >> 31)) & 2)) - (v619 + ((~(((v621 ^ -1) | (-(v621 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
    v690[v808] = v687;
    int * v692 = v585->cache_vals;
    int v811 = ((((((int)((unsigned int)((int)((unsigned int)v589 >> 2)) >> 1)) & 1) * 2) + ((((v615 + ((~(((v617 ^ -1) | (-(v617 ^ -1))) >> 31)) & 2)) - (v619 + ((~(((v621 ^ -1) | (-(v621 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
    v692[v811] = v689;
    int * v694 = v585->cache_tags;
    int v814 = ((((int)((unsigned int)((int)((unsigned int)v589 >> 2)) >> 1)) & 1) * 2) + ((((v615 + ((~(((v617 ^ -1) | (-(v617 ^ -1))) >> 31)) & 2)) - (v619 + ((~(((v621 ^ -1) | (-(v621 ^ -1))) >> 31)) & 2))) >> 31) & 1);
    int v815 = (int)((unsigned int)((int)((unsigned int)v589 >> 2)) >> 1);
    v694[v814] = v815;
    int * v696 = v585->cache_dirty;
    v696[v814] = 0;
    int * v698 = v585->cache_age;
    v698[v814] = 1;
    int * v700 = v585->cache_age;
    int v701 = v700[v814];
    int * v702 = v585->cache_age;
    int v703 = v702[v723];
    int * v704 = v585->cache_age;
    int v823 = v703 + ((int)((unsigned int)(v703 - v701) >> 31));
    v704[v723] = v823;
    int * v706 = v585->cache_age;
    int v707 = v706[v725];
    int * v708 = v585->cache_age;
    int v826 = v707 + ((int)((unsigned int)(v707 - v701) >> 31));
    v708[v725] = v826;
    int * v710 = v585->cache_age;
    v710[v814] = 0;
    v713 = v814;
  }
  int v829 = (v713 * 2) + (((int)((unsigned int)v589 >> 2)) & 1);
  int v714 = v600[v829];
  int * v715 = v585->regs;
  v715[14] = v714;
  struct StateT * v717 = slot_8(v585);
  return v717;
}

struct StateT * slot_3(struct StateT * v513) {
  int v514 = v513->timer;
  int v524 = v514 + 1;
  v513->timer = v524;
  int * v516 = v513->regs;
  int v517 = v516[12];
  int * v518 = v513->regs;
  int v519 = v518[14];
  int * v520 = v513->regs;
  int v530 = v517 ^ v519;
  v520[12] = v530;
  struct StateT * v522 = slot_4(v513);
  return v522;
}

struct StateT * snippet(struct StateT * v0) {
  struct StateT * v1 = slot_0(v0);
  return v1;
}

struct StateT * slot_10(struct StateT * v866) {
  int * v867 = v866->saved_regs;
  int * v868 = v866->regs;
  int v869 = v868[11];
  v867[11] = v869;
  int v871 = v866->timer;
  int v885 = v871 + 1;
  v866->timer = v885;
  int * v873 = v866->regs;
  int v874 = v873[11];
  int * v875 = v866->regs;
  int v876 = v875[14];
  int * v877 = v866->regs;
  int v890 = v874 + v876;
  v877[11] = v890;
  struct StateT * v879 = slot_11(v866);
  return v879;
}

struct StateT * slot_1(struct StateT * v251) {
  int v252 = v251->timer;
  int v385 = v252 + 1;
  v251->timer = v385;
  int * v254 = v251->regs;
  int v255 = v254[11];
  int * v256 = v251->cache_tags;
  int v389 = (((int)((unsigned int)((int)((unsigned int)(v255 + 12) >> 2)) >> 1)) & 1) * 2;
  int v257 = v256[v389];
  int * v258 = v251->cache_tags;
  int v391 = ((((int)((unsigned int)((int)((unsigned int)(v255 + 12) >> 2)) >> 1)) & 1) * 2) + 1;
  int v259 = v258[v391];
  int * v260 = v251->cache_tags;
  int v393 = 4 + ((((int)((unsigned int)((int)((unsigned int)(v255 + 12) >> 2)) >> 1)) & 3) * 2);
  int v261 = v260[v393];
  int * v262 = v251->cache_tags;
  int v395 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v255 + 12) >> 2)) >> 1)) & 3) * 2)) + 1;
  int v263 = v262[v395];
  int v264 = v251->timer;
  int v396 = v264 + ((100 ^ (((~(((v261 ^ ((int)((unsigned int)((int)((unsigned int)(v255 + 12) >> 2)) >> 1))) | (-(v261 ^ ((int)((unsigned int)((int)((unsigned int)(v255 + 12) >> 2)) >> 1))))) >> 31)) | (~(((v263 ^ ((int)((unsigned int)((int)((unsigned int)(v255 + 12) >> 2)) >> 1))) | (-(v263 ^ ((int)((unsigned int)((int)((unsigned int)(v255 + 12) >> 2)) >> 1))))) >> 31))) & 104)) ^ (((~(((v257 ^ ((int)((unsigned int)((int)((unsigned int)(v255 + 12) >> 2)) >> 1))) | (-(v257 ^ ((int)((unsigned int)((int)((unsigned int)(v255 + 12) >> 2)) >> 1))))) >> 31)) | (~(((v259 ^ ((int)((unsigned int)((int)((unsigned int)(v255 + 12) >> 2)) >> 1))) | (-(v259 ^ ((int)((unsigned int)((int)((unsigned int)(v255 + 12) >> 2)) >> 1))))) >> 31))) & (1 ^ (100 ^ (((~(((v261 ^ ((int)((unsigned int)((int)((unsigned int)(v255 + 12) >> 2)) >> 1))) | (-(v261 ^ ((int)((unsigned int)((int)((unsigned int)(v255 + 12) >> 2)) >> 1))))) >> 31)) | (~(((v263 ^ ((int)((unsigned int)((int)((unsigned int)(v255 + 12) >> 2)) >> 1))) | (-(v263 ^ ((int)((unsigned int)((int)((unsigned int)(v255 + 12) >> 2)) >> 1))))) >> 31))) & 104)))));
  v251->timer = v396;
  int * v266 = v251->cache_vals;
  bool v397 = !(((~(((v257 ^ ((int)((unsigned int)((int)((unsigned int)(v255 + 12) >> 2)) >> 1))) | (-(v257 ^ ((int)((unsigned int)((int)((unsigned int)(v255 + 12) >> 2)) >> 1))))) >> 31)) | (~(((v259 ^ ((int)((unsigned int)((int)((unsigned int)(v255 + 12) >> 2)) >> 1))) | (-(v259 ^ ((int)((unsigned int)((int)((unsigned int)(v255 + 12) >> 2)) >> 1))))) >> 31))) == 0);
  int v379;
  if (v397) {
    int * v267 = v251->cache_age;
    int v399 = ((((int)((unsigned int)((int)((unsigned int)(v255 + 12) >> 2)) >> 1)) & 1) * 2) + ((~(((v259 ^ ((int)((unsigned int)((int)((unsigned int)(v255 + 12) >> 2)) >> 1))) | (-(v259 ^ ((int)((unsigned int)((int)((unsigned int)(v255 + 12) >> 2)) >> 1))))) >> 31)) & 1);
    int v268 = v267[v399];
    int * v269 = v251->cache_age;
    int v270 = v269[v389];
    int * v271 = v251->cache_age;
    int v402 = v270 + ((int)((unsigned int)(v270 - v268) >> 31));
    v271[v389] = v402;
    int * v273 = v251->cache_age;
    int v274 = v273[v391];
    int * v275 = v251->cache_age;
    int v405 = v274 + ((int)((unsigned int)(v274 - v268) >> 31));
    v275[v391] = v405;
    int * v277 = v251->cache_age;
    v277[v399] = 0;
    v379 = v399;
  } else {
    int * v280 = v251->cache_age;
    int v409 = (((int)((unsigned int)((int)((unsigned int)(v255 + 12) >> 2)) >> 1)) & 1) * 2;
    int v281 = v280[v409];
    int * v282 = v251->cache_tags;
    int v283 = v282[v409];
    int * v284 = v251->cache_age;
    int v285 = v284[v391];
    int * v286 = v251->cache_tags;
    int v287 = v286[v391];
    bool v413 = !(((~(((v261 ^ ((int)((unsigned int)((int)((unsigned int)(v255 + 12) >> 2)) >> 1))) | (-(v261 ^ ((int)((unsigned int)((int)((unsigned int)(v255 + 12) >> 2)) >> 1))))) >> 31)) | (~(((v263 ^ ((int)((unsigned int)((int)((unsigned int)(v255 + 12) >> 2)) >> 1))) | (-(v263 ^ ((int)((unsigned int)((int)((unsigned int)(v255 + 12) >> 2)) >> 1))))) >> 31))) == 0);
    int v351;
    if (v413) {
      int * v288 = v251->cache_age;
      int v415 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v255 + 12) >> 2)) >> 1)) & 3) * 2)) + ((~(((v263 ^ ((int)((unsigned int)((int)((unsigned int)(v255 + 12) >> 2)) >> 1))) | (-(v263 ^ ((int)((unsigned int)((int)((unsigned int)(v255 + 12) >> 2)) >> 1))))) >> 31)) & 1);
      int v289 = v288[v415];
      int * v290 = v251->cache_age;
      int v291 = v290[v393];
      int * v292 = v251->cache_age;
      int v418 = v291 + ((int)((unsigned int)(v291 - v289) >> 31));
      v292[v393] = v418;
      int * v294 = v251->cache_age;
      int v295 = v294[v395];
      int * v296 = v251->cache_age;
      int v421 = v295 + ((int)((unsigned int)(v295 - v289) >> 31));
      v296[v395] = v421;
      int * v298 = v251->cache_age;
      v298[v415] = 0;
      v351 = v415;
    } else {
      int * v301 = v251->cache_age;
      int v425 = 4 + ((((int)((unsigned int)((int)((unsigned int)(v255 + 12) >> 2)) >> 1)) & 3) * 2);
      int v302 = v301[v425];
      int * v303 = v251->cache_tags;
      int v304 = v303[v425];
      int * v305 = v251->cache_age;
      int v306 = v305[v395];
      int * v307 = v251->cache_tags;
      int v308 = v307[v395];
      int * v309 = v251->cache_dirty;
      int v430 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v255 + 12) >> 2)) >> 1)) & 3) * 2)) + ((((v302 + ((~(((v304 ^ -1) | (-(v304 ^ -1))) >> 31)) & 2)) - (v306 + ((~(((v308 ^ -1) | (-(v308 ^ -1))) >> 31)) & 2))) >> 31) & 1);
      int v310 = v309[v430];
      bool v431 = !(v310 == 0);
      if (v431) {
        int * v311 = v251->cache_tags;
        int v312 = v311[v430];
        int * v313 = v251->cache_vals;
        int v434 = ((4 + ((((int)((unsigned int)((int)((unsigned int)(v255 + 12) >> 2)) >> 1)) & 3) * 2)) + ((((v302 + ((~(((v304 ^ -1) | (-(v304 ^ -1))) >> 31)) & 2)) - (v306 + ((~(((v308 ^ -1) | (-(v308 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
        int v314 = v313[v434];
        int * v315 = v251->cache_vals;
        int v436 = (((4 + ((((int)((unsigned int)((int)((unsigned int)(v255 + 12) >> 2)) >> 1)) & 3) * 2)) + ((((v302 + ((~(((v304 ^ -1) | (-(v304 ^ -1))) >> 31)) & 2)) - (v306 + ((~(((v308 ^ -1) | (-(v308 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
        int v316 = v315[v436];
        int * v317 = v251->mem;
        int v438 = v312 * 2;
        v317[v438] = v314;
        int * v319 = v251->mem;
        int v441 = (v312 * 2) + 1;
        v319[v441] = v316;
        ;
      } else {
        ;
      }
      int * v324 = v251->mem;
      int v446 = ((int)((unsigned int)((int)((unsigned int)(v255 + 12) >> 2)) >> 1)) * 2;
      int v325 = v324[v446];
      int * v326 = v251->mem;
      int v448 = (((int)((unsigned int)((int)((unsigned int)(v255 + 12) >> 2)) >> 1)) * 2) + 1;
      int v327 = v326[v448];
      int * v328 = v251->cache_vals;
      int v450 = ((4 + ((((int)((unsigned int)((int)((unsigned int)(v255 + 12) >> 2)) >> 1)) & 3) * 2)) + ((((v302 + ((~(((v304 ^ -1) | (-(v304 ^ -1))) >> 31)) & 2)) - (v306 + ((~(((v308 ^ -1) | (-(v308 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
      v328[v450] = v325;
      int * v330 = v251->cache_vals;
      int v453 = (((4 + ((((int)((unsigned int)((int)((unsigned int)(v255 + 12) >> 2)) >> 1)) & 3) * 2)) + ((((v302 + ((~(((v304 ^ -1) | (-(v304 ^ -1))) >> 31)) & 2)) - (v306 + ((~(((v308 ^ -1) | (-(v308 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
      v330[v453] = v327;
      int * v332 = v251->cache_tags;
      int v456 = (int)((unsigned int)((int)((unsigned int)(v255 + 12) >> 2)) >> 1);
      v332[v430] = v456;
      int * v334 = v251->cache_dirty;
      v334[v430] = 0;
      int * v336 = v251->cache_age;
      v336[v430] = 1;
      int * v338 = v251->cache_age;
      int v339 = v338[v430];
      int * v340 = v251->cache_age;
      int v341 = v340[v393];
      int * v342 = v251->cache_age;
      int v464 = v341 + ((int)((unsigned int)(v341 - v339) >> 31));
      v342[v393] = v464;
      int * v344 = v251->cache_age;
      int v345 = v344[v395];
      int * v346 = v251->cache_age;
      int v467 = v345 + ((int)((unsigned int)(v345 - v339) >> 31));
      v346[v395] = v467;
      int * v348 = v251->cache_age;
      v348[v430] = 0;
      v351 = v430;
    }
    int * v352 = v251->cache_vals;
    int v470 = v351 * 2;
    int v353 = v352[v470];
    int * v354 = v251->cache_vals;
    int v472 = (v351 * 2) + 1;
    int v355 = v354[v472];
    int * v356 = v251->cache_vals;
    int v474 = (((((int)((unsigned int)((int)((unsigned int)(v255 + 12) >> 2)) >> 1)) & 1) * 2) + ((((v281 + ((~(((v283 ^ -1) | (-(v283 ^ -1))) >> 31)) & 2)) - (v285 + ((~(((v287 ^ -1) | (-(v287 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
    v356[v474] = v353;
    int * v358 = v251->cache_vals;
    int v477 = ((((((int)((unsigned int)((int)((unsigned int)(v255 + 12) >> 2)) >> 1)) & 1) * 2) + ((((v281 + ((~(((v283 ^ -1) | (-(v283 ^ -1))) >> 31)) & 2)) - (v285 + ((~(((v287 ^ -1) | (-(v287 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
    v358[v477] = v355;
    int * v360 = v251->cache_tags;
    int v480 = ((((int)((unsigned int)((int)((unsigned int)(v255 + 12) >> 2)) >> 1)) & 1) * 2) + ((((v281 + ((~(((v283 ^ -1) | (-(v283 ^ -1))) >> 31)) & 2)) - (v285 + ((~(((v287 ^ -1) | (-(v287 ^ -1))) >> 31)) & 2))) >> 31) & 1);
    int v481 = (int)((unsigned int)((int)((unsigned int)(v255 + 12) >> 2)) >> 1);
    v360[v480] = v481;
    int * v362 = v251->cache_dirty;
    v362[v480] = 0;
    int * v364 = v251->cache_age;
    v364[v480] = 1;
    int * v366 = v251->cache_age;
    int v367 = v366[v480];
    int * v368 = v251->cache_age;
    int v369 = v368[v389];
    int * v370 = v251->cache_age;
    int v489 = v369 + ((int)((unsigned int)(v369 - v367) >> 31));
    v370[v389] = v489;
    int * v372 = v251->cache_age;
    int v373 = v372[v391];
    int * v374 = v251->cache_age;
    int v492 = v373 + ((int)((unsigned int)(v373 - v367) >> 31));
    v374[v391] = v492;
    int * v376 = v251->cache_age;
    v376[v480] = 0;
    v379 = v480;
  }
  int v495 = (v379 * 2) + (((int)((unsigned int)(v255 + 12) >> 2)) & 1);
  int v380 = v266[v495];
  int * v381 = v251->regs;
  v381[14] = v380;
  struct StateT * v383 = slot_2(v251);
  return v383;
}

struct StateT * slot_8(struct StateT * v834) {
  int v835 = v834->timer;
  int v843 = v835 + 1;
  v834->timer = v843;
  int * v837 = v834->regs;
  int v838 = v837[14];
  int * v839 = v834->regs;
  int v847 = v838 & 15;
  v839[14] = v847;
  struct StateT * v841 = slot_9(v834);
  return v841;
}

struct StateT * slot_4(struct StateT * v533) {
  int v534 = v533->timer;
  int v538 = v534 + 1;
  v533->timer = v538;
  struct StateT * v536 = slot_5(v533);
  return v536;
}

struct StateT * slot_13(struct StateT * v1169) {
  int * v1170 = v1169->regs;
  int v1171 = v1170[15];
  int * v1172 = v1169->regs;
  int v1173 = v1172[10];
  bool v1198 = (v1171 ^ -2147483648) < (v1173 ^ -2147483648);
  struct StateT * v1192;
  if (v1198) {
    int v1174 = v1169->timer;
    int v1199 = v1174 + 15;
    v1169->timer = v1199;
    int * v1176 = v1169->saved_regs;
    int v1177 = v1176[14];
    int * v1178 = v1169->regs;
    v1178[14] = v1177;
    int * v1180 = v1169->saved_regs;
    int v1181 = v1180[11];
    int * v1182 = v1169->regs;
    v1182[11] = v1181;
    int * v1184 = v1169->saved_regs;
    int v1185 = v1184[12];
    int * v1186 = v1169->regs;
    v1186[12] = v1185;
    struct StateT * v1188 = slot_14(v1169);
    v1192 = v1188;
  } else {
    struct StateT * v1190 = slot_14(v1169);
    v1192 = v1190;
  }
  return v1192;
}

struct StateT * slot_15(struct StateT * v1233) {
  int v1234 = v1233->timer;
  int v1242 = v1234 + 1;
  v1233->timer = v1242;
  int * v1236 = v1233->regs;
  int v1237 = v1236[10];
  int * v1238 = v1233->regs;
  int v1246 = v1237 << 2;
  v1238[10] = v1246;
  struct StateT * v1240 = slot_16(v1233);
  return v1240;
}

struct StateT * slot_18(struct StateT * v1654) {
  int v1655 = v1654->timer;
  int v1658 = v1655 + 1;
  v1654->timer = v1658;
  return v1654;
}

struct StateT * slot_9(struct StateT * v850) {
  int v851 = v850->timer;
  int v859 = v851 + 1;
  v850->timer = v859;
  int * v853 = v850->regs;
  int v854 = v853[14];
  int * v855 = v850->regs;
  int v863 = v854 << 2;
  v855[14] = v863;
  struct StateT * v857 = slot_10(v850);
  return v857;
}

struct StateT * slot_11(struct StateT * v893) {
  int v894 = v893->timer;
  int v1027 = v894 + 1;
  v893->timer = v1027;
  int * v896 = v893->regs;
  int v897 = v896[11];
  int * v898 = v893->cache_tags;
  int v1031 = (((int)((unsigned int)((int)((unsigned int)v897 >> 2)) >> 1)) & 1) * 2;
  int v899 = v898[v1031];
  int * v900 = v893->cache_tags;
  int v1033 = ((((int)((unsigned int)((int)((unsigned int)v897 >> 2)) >> 1)) & 1) * 2) + 1;
  int v901 = v900[v1033];
  int * v902 = v893->cache_tags;
  int v1035 = 4 + ((((int)((unsigned int)((int)((unsigned int)v897 >> 2)) >> 1)) & 3) * 2);
  int v903 = v902[v1035];
  int * v904 = v893->cache_tags;
  int v1037 = (4 + ((((int)((unsigned int)((int)((unsigned int)v897 >> 2)) >> 1)) & 3) * 2)) + 1;
  int v905 = v904[v1037];
  int v906 = v893->timer;
  int v1038 = v906 + ((100 ^ (((~(((v903 ^ ((int)((unsigned int)((int)((unsigned int)v897 >> 2)) >> 1))) | (-(v903 ^ ((int)((unsigned int)((int)((unsigned int)v897 >> 2)) >> 1))))) >> 31)) | (~(((v905 ^ ((int)((unsigned int)((int)((unsigned int)v897 >> 2)) >> 1))) | (-(v905 ^ ((int)((unsigned int)((int)((unsigned int)v897 >> 2)) >> 1))))) >> 31))) & 104)) ^ (((~(((v899 ^ ((int)((unsigned int)((int)((unsigned int)v897 >> 2)) >> 1))) | (-(v899 ^ ((int)((unsigned int)((int)((unsigned int)v897 >> 2)) >> 1))))) >> 31)) | (~(((v901 ^ ((int)((unsigned int)((int)((unsigned int)v897 >> 2)) >> 1))) | (-(v901 ^ ((int)((unsigned int)((int)((unsigned int)v897 >> 2)) >> 1))))) >> 31))) & (1 ^ (100 ^ (((~(((v903 ^ ((int)((unsigned int)((int)((unsigned int)v897 >> 2)) >> 1))) | (-(v903 ^ ((int)((unsigned int)((int)((unsigned int)v897 >> 2)) >> 1))))) >> 31)) | (~(((v905 ^ ((int)((unsigned int)((int)((unsigned int)v897 >> 2)) >> 1))) | (-(v905 ^ ((int)((unsigned int)((int)((unsigned int)v897 >> 2)) >> 1))))) >> 31))) & 104)))));
  v893->timer = v1038;
  int * v908 = v893->cache_vals;
  bool v1039 = !(((~(((v899 ^ ((int)((unsigned int)((int)((unsigned int)v897 >> 2)) >> 1))) | (-(v899 ^ ((int)((unsigned int)((int)((unsigned int)v897 >> 2)) >> 1))))) >> 31)) | (~(((v901 ^ ((int)((unsigned int)((int)((unsigned int)v897 >> 2)) >> 1))) | (-(v901 ^ ((int)((unsigned int)((int)((unsigned int)v897 >> 2)) >> 1))))) >> 31))) == 0);
  int v1021;
  if (v1039) {
    int * v909 = v893->cache_age;
    int v1041 = ((((int)((unsigned int)((int)((unsigned int)v897 >> 2)) >> 1)) & 1) * 2) + ((~(((v901 ^ ((int)((unsigned int)((int)((unsigned int)v897 >> 2)) >> 1))) | (-(v901 ^ ((int)((unsigned int)((int)((unsigned int)v897 >> 2)) >> 1))))) >> 31)) & 1);
    int v910 = v909[v1041];
    int * v911 = v893->cache_age;
    int v912 = v911[v1031];
    int * v913 = v893->cache_age;
    int v1044 = v912 + ((int)((unsigned int)(v912 - v910) >> 31));
    v913[v1031] = v1044;
    int * v915 = v893->cache_age;
    int v916 = v915[v1033];
    int * v917 = v893->cache_age;
    int v1047 = v916 + ((int)((unsigned int)(v916 - v910) >> 31));
    v917[v1033] = v1047;
    int * v919 = v893->cache_age;
    v919[v1041] = 0;
    v1021 = v1041;
  } else {
    int * v922 = v893->cache_age;
    int v1051 = (((int)((unsigned int)((int)((unsigned int)v897 >> 2)) >> 1)) & 1) * 2;
    int v923 = v922[v1051];
    int * v924 = v893->cache_tags;
    int v925 = v924[v1051];
    int * v926 = v893->cache_age;
    int v927 = v926[v1033];
    int * v928 = v893->cache_tags;
    int v929 = v928[v1033];
    bool v1055 = !(((~(((v903 ^ ((int)((unsigned int)((int)((unsigned int)v897 >> 2)) >> 1))) | (-(v903 ^ ((int)((unsigned int)((int)((unsigned int)v897 >> 2)) >> 1))))) >> 31)) | (~(((v905 ^ ((int)((unsigned int)((int)((unsigned int)v897 >> 2)) >> 1))) | (-(v905 ^ ((int)((unsigned int)((int)((unsigned int)v897 >> 2)) >> 1))))) >> 31))) == 0);
    int v993;
    if (v1055) {
      int * v930 = v893->cache_age;
      int v1057 = (4 + ((((int)((unsigned int)((int)((unsigned int)v897 >> 2)) >> 1)) & 3) * 2)) + ((~(((v905 ^ ((int)((unsigned int)((int)((unsigned int)v897 >> 2)) >> 1))) | (-(v905 ^ ((int)((unsigned int)((int)((unsigned int)v897 >> 2)) >> 1))))) >> 31)) & 1);
      int v931 = v930[v1057];
      int * v932 = v893->cache_age;
      int v933 = v932[v1035];
      int * v934 = v893->cache_age;
      int v1060 = v933 + ((int)((unsigned int)(v933 - v931) >> 31));
      v934[v1035] = v1060;
      int * v936 = v893->cache_age;
      int v937 = v936[v1037];
      int * v938 = v893->cache_age;
      int v1063 = v937 + ((int)((unsigned int)(v937 - v931) >> 31));
      v938[v1037] = v1063;
      int * v940 = v893->cache_age;
      v940[v1057] = 0;
      v993 = v1057;
    } else {
      int * v943 = v893->cache_age;
      int v1067 = 4 + ((((int)((unsigned int)((int)((unsigned int)v897 >> 2)) >> 1)) & 3) * 2);
      int v944 = v943[v1067];
      int * v945 = v893->cache_tags;
      int v946 = v945[v1067];
      int * v947 = v893->cache_age;
      int v948 = v947[v1037];
      int * v949 = v893->cache_tags;
      int v950 = v949[v1037];
      int * v951 = v893->cache_dirty;
      int v1072 = (4 + ((((int)((unsigned int)((int)((unsigned int)v897 >> 2)) >> 1)) & 3) * 2)) + ((((v944 + ((~(((v946 ^ -1) | (-(v946 ^ -1))) >> 31)) & 2)) - (v948 + ((~(((v950 ^ -1) | (-(v950 ^ -1))) >> 31)) & 2))) >> 31) & 1);
      int v952 = v951[v1072];
      bool v1073 = !(v952 == 0);
      if (v1073) {
        int * v953 = v893->cache_tags;
        int v954 = v953[v1072];
        int * v955 = v893->cache_vals;
        int v1076 = ((4 + ((((int)((unsigned int)((int)((unsigned int)v897 >> 2)) >> 1)) & 3) * 2)) + ((((v944 + ((~(((v946 ^ -1) | (-(v946 ^ -1))) >> 31)) & 2)) - (v948 + ((~(((v950 ^ -1) | (-(v950 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
        int v956 = v955[v1076];
        int * v957 = v893->cache_vals;
        int v1078 = (((4 + ((((int)((unsigned int)((int)((unsigned int)v897 >> 2)) >> 1)) & 3) * 2)) + ((((v944 + ((~(((v946 ^ -1) | (-(v946 ^ -1))) >> 31)) & 2)) - (v948 + ((~(((v950 ^ -1) | (-(v950 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
        int v958 = v957[v1078];
        int * v959 = v893->mem;
        int v1080 = v954 * 2;
        v959[v1080] = v956;
        int * v961 = v893->mem;
        int v1083 = (v954 * 2) + 1;
        v961[v1083] = v958;
        ;
      } else {
        ;
      }
      int * v966 = v893->mem;
      int v1088 = ((int)((unsigned int)((int)((unsigned int)v897 >> 2)) >> 1)) * 2;
      int v967 = v966[v1088];
      int * v968 = v893->mem;
      int v1090 = (((int)((unsigned int)((int)((unsigned int)v897 >> 2)) >> 1)) * 2) + 1;
      int v969 = v968[v1090];
      int * v970 = v893->cache_vals;
      int v1092 = ((4 + ((((int)((unsigned int)((int)((unsigned int)v897 >> 2)) >> 1)) & 3) * 2)) + ((((v944 + ((~(((v946 ^ -1) | (-(v946 ^ -1))) >> 31)) & 2)) - (v948 + ((~(((v950 ^ -1) | (-(v950 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
      v970[v1092] = v967;
      int * v972 = v893->cache_vals;
      int v1095 = (((4 + ((((int)((unsigned int)((int)((unsigned int)v897 >> 2)) >> 1)) & 3) * 2)) + ((((v944 + ((~(((v946 ^ -1) | (-(v946 ^ -1))) >> 31)) & 2)) - (v948 + ((~(((v950 ^ -1) | (-(v950 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
      v972[v1095] = v969;
      int * v974 = v893->cache_tags;
      int v1098 = (int)((unsigned int)((int)((unsigned int)v897 >> 2)) >> 1);
      v974[v1072] = v1098;
      int * v976 = v893->cache_dirty;
      v976[v1072] = 0;
      int * v978 = v893->cache_age;
      v978[v1072] = 1;
      int * v980 = v893->cache_age;
      int v981 = v980[v1072];
      int * v982 = v893->cache_age;
      int v983 = v982[v1035];
      int * v984 = v893->cache_age;
      int v1106 = v983 + ((int)((unsigned int)(v983 - v981) >> 31));
      v984[v1035] = v1106;
      int * v986 = v893->cache_age;
      int v987 = v986[v1037];
      int * v988 = v893->cache_age;
      int v1109 = v987 + ((int)((unsigned int)(v987 - v981) >> 31));
      v988[v1037] = v1109;
      int * v990 = v893->cache_age;
      v990[v1072] = 0;
      v993 = v1072;
    }
    int * v994 = v893->cache_vals;
    int v1112 = v993 * 2;
    int v995 = v994[v1112];
    int * v996 = v893->cache_vals;
    int v1114 = (v993 * 2) + 1;
    int v997 = v996[v1114];
    int * v998 = v893->cache_vals;
    int v1116 = (((((int)((unsigned int)((int)((unsigned int)v897 >> 2)) >> 1)) & 1) * 2) + ((((v923 + ((~(((v925 ^ -1) | (-(v925 ^ -1))) >> 31)) & 2)) - (v927 + ((~(((v929 ^ -1) | (-(v929 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
    v998[v1116] = v995;
    int * v1000 = v893->cache_vals;
    int v1119 = ((((((int)((unsigned int)((int)((unsigned int)v897 >> 2)) >> 1)) & 1) * 2) + ((((v923 + ((~(((v925 ^ -1) | (-(v925 ^ -1))) >> 31)) & 2)) - (v927 + ((~(((v929 ^ -1) | (-(v929 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
    v1000[v1119] = v997;
    int * v1002 = v893->cache_tags;
    int v1122 = ((((int)((unsigned int)((int)((unsigned int)v897 >> 2)) >> 1)) & 1) * 2) + ((((v923 + ((~(((v925 ^ -1) | (-(v925 ^ -1))) >> 31)) & 2)) - (v927 + ((~(((v929 ^ -1) | (-(v929 ^ -1))) >> 31)) & 2))) >> 31) & 1);
    int v1123 = (int)((unsigned int)((int)((unsigned int)v897 >> 2)) >> 1);
    v1002[v1122] = v1123;
    int * v1004 = v893->cache_dirty;
    v1004[v1122] = 0;
    int * v1006 = v893->cache_age;
    v1006[v1122] = 1;
    int * v1008 = v893->cache_age;
    int v1009 = v1008[v1122];
    int * v1010 = v893->cache_age;
    int v1011 = v1010[v1031];
    int * v1012 = v893->cache_age;
    int v1131 = v1011 + ((int)((unsigned int)(v1011 - v1009) >> 31));
    v1012[v1031] = v1131;
    int * v1014 = v893->cache_age;
    int v1015 = v1014[v1033];
    int * v1016 = v893->cache_age;
    int v1134 = v1015 + ((int)((unsigned int)(v1015 - v1009) >> 31));
    v1016[v1033] = v1134;
    int * v1018 = v893->cache_age;
    v1018[v1122] = 0;
    v1021 = v1122;
  }
  int v1137 = (v1021 * 2) + (((int)((unsigned int)v897 >> 2)) & 1);
  int v1022 = v908[v1137];
  int * v1023 = v893->regs;
  v1023[11] = v1022;
  struct StateT * v1025 = slot_12(v893);
  return v1025;
}

struct StateT * slot_0(struct StateT * v2) {
  int v3 = v2->timer;
  int v136 = v3 + 1;
  v2->timer = v136;
  int * v5 = v2->regs;
  int v6 = v5[12];
  int * v7 = v2->cache_tags;
  int v140 = (((int)((unsigned int)((int)((unsigned int)v6 >> 2)) >> 1)) & 1) * 2;
  int v8 = v7[v140];
  int * v9 = v2->cache_tags;
  int v142 = ((((int)((unsigned int)((int)((unsigned int)v6 >> 2)) >> 1)) & 1) * 2) + 1;
  int v10 = v9[v142];
  int * v11 = v2->cache_tags;
  int v144 = 4 + ((((int)((unsigned int)((int)((unsigned int)v6 >> 2)) >> 1)) & 3) * 2);
  int v12 = v11[v144];
  int * v13 = v2->cache_tags;
  int v146 = (4 + ((((int)((unsigned int)((int)((unsigned int)v6 >> 2)) >> 1)) & 3) * 2)) + 1;
  int v14 = v13[v146];
  int v15 = v2->timer;
  int v147 = v15 + ((100 ^ (((~(((v12 ^ ((int)((unsigned int)((int)((unsigned int)v6 >> 2)) >> 1))) | (-(v12 ^ ((int)((unsigned int)((int)((unsigned int)v6 >> 2)) >> 1))))) >> 31)) | (~(((v14 ^ ((int)((unsigned int)((int)((unsigned int)v6 >> 2)) >> 1))) | (-(v14 ^ ((int)((unsigned int)((int)((unsigned int)v6 >> 2)) >> 1))))) >> 31))) & 104)) ^ (((~(((v8 ^ ((int)((unsigned int)((int)((unsigned int)v6 >> 2)) >> 1))) | (-(v8 ^ ((int)((unsigned int)((int)((unsigned int)v6 >> 2)) >> 1))))) >> 31)) | (~(((v10 ^ ((int)((unsigned int)((int)((unsigned int)v6 >> 2)) >> 1))) | (-(v10 ^ ((int)((unsigned int)((int)((unsigned int)v6 >> 2)) >> 1))))) >> 31))) & (1 ^ (100 ^ (((~(((v12 ^ ((int)((unsigned int)((int)((unsigned int)v6 >> 2)) >> 1))) | (-(v12 ^ ((int)((unsigned int)((int)((unsigned int)v6 >> 2)) >> 1))))) >> 31)) | (~(((v14 ^ ((int)((unsigned int)((int)((unsigned int)v6 >> 2)) >> 1))) | (-(v14 ^ ((int)((unsigned int)((int)((unsigned int)v6 >> 2)) >> 1))))) >> 31))) & 104)))));
  v2->timer = v147;
  int * v17 = v2->cache_vals;
  bool v148 = !(((~(((v8 ^ ((int)((unsigned int)((int)((unsigned int)v6 >> 2)) >> 1))) | (-(v8 ^ ((int)((unsigned int)((int)((unsigned int)v6 >> 2)) >> 1))))) >> 31)) | (~(((v10 ^ ((int)((unsigned int)((int)((unsigned int)v6 >> 2)) >> 1))) | (-(v10 ^ ((int)((unsigned int)((int)((unsigned int)v6 >> 2)) >> 1))))) >> 31))) == 0);
  int v130;
  if (v148) {
    int * v18 = v2->cache_age;
    int v150 = ((((int)((unsigned int)((int)((unsigned int)v6 >> 2)) >> 1)) & 1) * 2) + ((~(((v10 ^ ((int)((unsigned int)((int)((unsigned int)v6 >> 2)) >> 1))) | (-(v10 ^ ((int)((unsigned int)((int)((unsigned int)v6 >> 2)) >> 1))))) >> 31)) & 1);
    int v19 = v18[v150];
    int * v20 = v2->cache_age;
    int v21 = v20[v140];
    int * v22 = v2->cache_age;
    int v153 = v21 + ((int)((unsigned int)(v21 - v19) >> 31));
    v22[v140] = v153;
    int * v24 = v2->cache_age;
    int v25 = v24[v142];
    int * v26 = v2->cache_age;
    int v156 = v25 + ((int)((unsigned int)(v25 - v19) >> 31));
    v26[v142] = v156;
    int * v28 = v2->cache_age;
    v28[v150] = 0;
    v130 = v150;
  } else {
    int * v31 = v2->cache_age;
    int v160 = (((int)((unsigned int)((int)((unsigned int)v6 >> 2)) >> 1)) & 1) * 2;
    int v32 = v31[v160];
    int * v33 = v2->cache_tags;
    int v34 = v33[v160];
    int * v35 = v2->cache_age;
    int v36 = v35[v142];
    int * v37 = v2->cache_tags;
    int v38 = v37[v142];
    bool v164 = !(((~(((v12 ^ ((int)((unsigned int)((int)((unsigned int)v6 >> 2)) >> 1))) | (-(v12 ^ ((int)((unsigned int)((int)((unsigned int)v6 >> 2)) >> 1))))) >> 31)) | (~(((v14 ^ ((int)((unsigned int)((int)((unsigned int)v6 >> 2)) >> 1))) | (-(v14 ^ ((int)((unsigned int)((int)((unsigned int)v6 >> 2)) >> 1))))) >> 31))) == 0);
    int v102;
    if (v164) {
      int * v39 = v2->cache_age;
      int v166 = (4 + ((((int)((unsigned int)((int)((unsigned int)v6 >> 2)) >> 1)) & 3) * 2)) + ((~(((v14 ^ ((int)((unsigned int)((int)((unsigned int)v6 >> 2)) >> 1))) | (-(v14 ^ ((int)((unsigned int)((int)((unsigned int)v6 >> 2)) >> 1))))) >> 31)) & 1);
      int v40 = v39[v166];
      int * v41 = v2->cache_age;
      int v42 = v41[v144];
      int * v43 = v2->cache_age;
      int v169 = v42 + ((int)((unsigned int)(v42 - v40) >> 31));
      v43[v144] = v169;
      int * v45 = v2->cache_age;
      int v46 = v45[v146];
      int * v47 = v2->cache_age;
      int v172 = v46 + ((int)((unsigned int)(v46 - v40) >> 31));
      v47[v146] = v172;
      int * v49 = v2->cache_age;
      v49[v166] = 0;
      v102 = v166;
    } else {
      int * v52 = v2->cache_age;
      int v176 = 4 + ((((int)((unsigned int)((int)((unsigned int)v6 >> 2)) >> 1)) & 3) * 2);
      int v53 = v52[v176];
      int * v54 = v2->cache_tags;
      int v55 = v54[v176];
      int * v56 = v2->cache_age;
      int v57 = v56[v146];
      int * v58 = v2->cache_tags;
      int v59 = v58[v146];
      int * v60 = v2->cache_dirty;
      int v181 = (4 + ((((int)((unsigned int)((int)((unsigned int)v6 >> 2)) >> 1)) & 3) * 2)) + ((((v53 + ((~(((v55 ^ -1) | (-(v55 ^ -1))) >> 31)) & 2)) - (v57 + ((~(((v59 ^ -1) | (-(v59 ^ -1))) >> 31)) & 2))) >> 31) & 1);
      int v61 = v60[v181];
      bool v182 = !(v61 == 0);
      if (v182) {
        int * v62 = v2->cache_tags;
        int v63 = v62[v181];
        int * v64 = v2->cache_vals;
        int v185 = ((4 + ((((int)((unsigned int)((int)((unsigned int)v6 >> 2)) >> 1)) & 3) * 2)) + ((((v53 + ((~(((v55 ^ -1) | (-(v55 ^ -1))) >> 31)) & 2)) - (v57 + ((~(((v59 ^ -1) | (-(v59 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
        int v65 = v64[v185];
        int * v66 = v2->cache_vals;
        int v187 = (((4 + ((((int)((unsigned int)((int)((unsigned int)v6 >> 2)) >> 1)) & 3) * 2)) + ((((v53 + ((~(((v55 ^ -1) | (-(v55 ^ -1))) >> 31)) & 2)) - (v57 + ((~(((v59 ^ -1) | (-(v59 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
        int v67 = v66[v187];
        int * v68 = v2->mem;
        int v189 = v63 * 2;
        v68[v189] = v65;
        int * v70 = v2->mem;
        int v192 = (v63 * 2) + 1;
        v70[v192] = v67;
        ;
      } else {
        ;
      }
      int * v75 = v2->mem;
      int v197 = ((int)((unsigned int)((int)((unsigned int)v6 >> 2)) >> 1)) * 2;
      int v76 = v75[v197];
      int * v77 = v2->mem;
      int v199 = (((int)((unsigned int)((int)((unsigned int)v6 >> 2)) >> 1)) * 2) + 1;
      int v78 = v77[v199];
      int * v79 = v2->cache_vals;
      int v201 = ((4 + ((((int)((unsigned int)((int)((unsigned int)v6 >> 2)) >> 1)) & 3) * 2)) + ((((v53 + ((~(((v55 ^ -1) | (-(v55 ^ -1))) >> 31)) & 2)) - (v57 + ((~(((v59 ^ -1) | (-(v59 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
      v79[v201] = v76;
      int * v81 = v2->cache_vals;
      int v204 = (((4 + ((((int)((unsigned int)((int)((unsigned int)v6 >> 2)) >> 1)) & 3) * 2)) + ((((v53 + ((~(((v55 ^ -1) | (-(v55 ^ -1))) >> 31)) & 2)) - (v57 + ((~(((v59 ^ -1) | (-(v59 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
      v81[v204] = v78;
      int * v83 = v2->cache_tags;
      int v207 = (int)((unsigned int)((int)((unsigned int)v6 >> 2)) >> 1);
      v83[v181] = v207;
      int * v85 = v2->cache_dirty;
      v85[v181] = 0;
      int * v87 = v2->cache_age;
      v87[v181] = 1;
      int * v89 = v2->cache_age;
      int v90 = v89[v181];
      int * v91 = v2->cache_age;
      int v92 = v91[v144];
      int * v93 = v2->cache_age;
      int v215 = v92 + ((int)((unsigned int)(v92 - v90) >> 31));
      v93[v144] = v215;
      int * v95 = v2->cache_age;
      int v96 = v95[v146];
      int * v97 = v2->cache_age;
      int v218 = v96 + ((int)((unsigned int)(v96 - v90) >> 31));
      v97[v146] = v218;
      int * v99 = v2->cache_age;
      v99[v181] = 0;
      v102 = v181;
    }
    int * v103 = v2->cache_vals;
    int v221 = v102 * 2;
    int v104 = v103[v221];
    int * v105 = v2->cache_vals;
    int v223 = (v102 * 2) + 1;
    int v106 = v105[v223];
    int * v107 = v2->cache_vals;
    int v225 = (((((int)((unsigned int)((int)((unsigned int)v6 >> 2)) >> 1)) & 1) * 2) + ((((v32 + ((~(((v34 ^ -1) | (-(v34 ^ -1))) >> 31)) & 2)) - (v36 + ((~(((v38 ^ -1) | (-(v38 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
    v107[v225] = v104;
    int * v109 = v2->cache_vals;
    int v228 = ((((((int)((unsigned int)((int)((unsigned int)v6 >> 2)) >> 1)) & 1) * 2) + ((((v32 + ((~(((v34 ^ -1) | (-(v34 ^ -1))) >> 31)) & 2)) - (v36 + ((~(((v38 ^ -1) | (-(v38 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
    v109[v228] = v106;
    int * v111 = v2->cache_tags;
    int v231 = ((((int)((unsigned int)((int)((unsigned int)v6 >> 2)) >> 1)) & 1) * 2) + ((((v32 + ((~(((v34 ^ -1) | (-(v34 ^ -1))) >> 31)) & 2)) - (v36 + ((~(((v38 ^ -1) | (-(v38 ^ -1))) >> 31)) & 2))) >> 31) & 1);
    int v232 = (int)((unsigned int)((int)((unsigned int)v6 >> 2)) >> 1);
    v111[v231] = v232;
    int * v113 = v2->cache_dirty;
    v113[v231] = 0;
    int * v115 = v2->cache_age;
    v115[v231] = 1;
    int * v117 = v2->cache_age;
    int v118 = v117[v231];
    int * v119 = v2->cache_age;
    int v120 = v119[v140];
    int * v121 = v2->cache_age;
    int v240 = v120 + ((int)((unsigned int)(v120 - v118) >> 31));
    v121[v140] = v240;
    int * v123 = v2->cache_age;
    int v124 = v123[v142];
    int * v125 = v2->cache_age;
    int v243 = v124 + ((int)((unsigned int)(v124 - v118) >> 31));
    v125[v142] = v243;
    int * v127 = v2->cache_age;
    v127[v231] = 0;
    v130 = v231;
  }
  int v246 = (v130 * 2) + (((int)((unsigned int)v6 >> 2)) & 1);
  int v131 = v17[v246];
  int * v132 = v2->regs;
  v132[12] = v131;
  struct StateT * v134 = slot_1(v2);
  return v134;
}



/*****************************************
End of C Generated Code
*******************************************/

void init(struct StateT *s) {
  for (int i=0; i<NUM_REGS; i++) {
    s->regs[i] = 0;
    s->saved_regs[i] = 0;
  }
  s->regs[2] = 4 * MEM_SIZE;
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
  
  // a10, public: one draw, written into both states
  int a10 = bounded(0, 23);
  s1.regs[10] = a10;
  s2.regs[10] = a10;
  // a11, 16 words read by the callee: the address is public
  s1.regs[11] = 0;
  s2.regs[11] = 0;
  // its contents, public: the same draw in both states
  for (int i=0; i<16; i++) {
    int v = bounded(0, 20);
    s1.mem[0 + i] = v;
    s2.mem[0 + i] = v;
  }
  // a12, 8 words read by the callee: the address is public
  s1.regs[12] = 64;
  s2.regs[12] = 64;
  // a13, 8 words written by the callee: the address is public
  s1.regs[13] = 96;
  s2.regs[13] = 96;
  
  // a12's contents, secret: a different draw in each state
  for (int i=0; i<8; i++) {
    s1.mem[16 + i] = bounded(0, 20);
    s2.mem[16 + i] = bounded(0, 20);
  }
  struct StateT *s1_ = snippet(&s1);
  struct StateT *s2_ = snippet(&s2);
  koika_assert(s1_->timer==s2_->timer, "timing leak");
  return 0;
}