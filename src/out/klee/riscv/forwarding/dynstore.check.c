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

struct StateT * slot_12(struct StateT * v1323);
struct StateT * slot_14(struct StateT * v1359);
struct StateT * slot_6(struct StateT * v334);
struct StateT * slot_5(struct StateT * v77);
struct StateT * slot_2(struct StateT * v28);
struct StateT * slot_3(struct StateT * v41);
struct StateT * snippet(struct StateT * v0);
struct StateT * slot_10(struct StateT * v1307);
struct StateT * slot_1(struct StateT * v15);
struct StateT * slot_8(struct StateT * v371);
struct StateT * slot_4(struct StateT * v49);
struct StateT * slot_13(struct StateT * v1331);
struct StateT * slot_15(struct StateT * v1616);
struct StateT * slot_9(struct StateT * v1049);
struct StateT * slot_11(struct StateT * v1299);
struct StateT * slot_0(struct StateT * v2);
struct StateT * slot_12(struct StateT * v1323) {
  int v1324 = v1323->timer;
  int v1328 = v1324 + 1;
  v1323->timer = v1328;
  struct StateT * v1326 = slot_13(v1323);
  return v1326;
}

struct StateT * slot_14(struct StateT * v1359) {
  int * v1360 = v1359->saved_regs;
  int * v1361 = v1359->regs;
  int v1362 = v1361[5];
  v1360[5] = v1362;
  int v1364 = v1359->timer;
  int v1501 = v1364 + 1;
  v1359->timer = v1501;
  int * v1366 = v1359->regs;
  int v1367 = v1366[8];
  int * v1368 = v1359->cache_tags;
  int v1505 = (((int)((unsigned int)((int)((unsigned int)v1367 >> 2)) >> 1)) & 1) * 2;
  int v1369 = v1368[v1505];
  int * v1370 = v1359->cache_tags;
  int v1507 = ((((int)((unsigned int)((int)((unsigned int)v1367 >> 2)) >> 1)) & 1) * 2) + 1;
  int v1371 = v1370[v1507];
  int * v1372 = v1359->cache_tags;
  int v1509 = 4 + ((((int)((unsigned int)((int)((unsigned int)v1367 >> 2)) >> 1)) & 3) * 2);
  int v1373 = v1372[v1509];
  int * v1374 = v1359->cache_tags;
  int v1511 = (4 + ((((int)((unsigned int)((int)((unsigned int)v1367 >> 2)) >> 1)) & 3) * 2)) + 1;
  int v1375 = v1374[v1511];
  int v1376 = v1359->timer;
  int v1512 = v1376 + ((100 ^ (((~(((v1373 ^ ((int)((unsigned int)((int)((unsigned int)v1367 >> 2)) >> 1))) | (-(v1373 ^ ((int)((unsigned int)((int)((unsigned int)v1367 >> 2)) >> 1))))) >> 31)) | (~(((v1375 ^ ((int)((unsigned int)((int)((unsigned int)v1367 >> 2)) >> 1))) | (-(v1375 ^ ((int)((unsigned int)((int)((unsigned int)v1367 >> 2)) >> 1))))) >> 31))) & 104)) ^ (((~(((v1369 ^ ((int)((unsigned int)((int)((unsigned int)v1367 >> 2)) >> 1))) | (-(v1369 ^ ((int)((unsigned int)((int)((unsigned int)v1367 >> 2)) >> 1))))) >> 31)) | (~(((v1371 ^ ((int)((unsigned int)((int)((unsigned int)v1367 >> 2)) >> 1))) | (-(v1371 ^ ((int)((unsigned int)((int)((unsigned int)v1367 >> 2)) >> 1))))) >> 31))) & (1 ^ (100 ^ (((~(((v1373 ^ ((int)((unsigned int)((int)((unsigned int)v1367 >> 2)) >> 1))) | (-(v1373 ^ ((int)((unsigned int)((int)((unsigned int)v1367 >> 2)) >> 1))))) >> 31)) | (~(((v1375 ^ ((int)((unsigned int)((int)((unsigned int)v1367 >> 2)) >> 1))) | (-(v1375 ^ ((int)((unsigned int)((int)((unsigned int)v1367 >> 2)) >> 1))))) >> 31))) & 104)))));
  v1359->timer = v1512;
  int * v1378 = v1359->cache_vals;
  bool v1513 = !(((~(((v1369 ^ ((int)((unsigned int)((int)((unsigned int)v1367 >> 2)) >> 1))) | (-(v1369 ^ ((int)((unsigned int)((int)((unsigned int)v1367 >> 2)) >> 1))))) >> 31)) | (~(((v1371 ^ ((int)((unsigned int)((int)((unsigned int)v1367 >> 2)) >> 1))) | (-(v1371 ^ ((int)((unsigned int)((int)((unsigned int)v1367 >> 2)) >> 1))))) >> 31))) == 0);
  int v1491;
  if (v1513) {
    int * v1379 = v1359->cache_age;
    int v1515 = ((((int)((unsigned int)((int)((unsigned int)v1367 >> 2)) >> 1)) & 1) * 2) + ((~(((v1371 ^ ((int)((unsigned int)((int)((unsigned int)v1367 >> 2)) >> 1))) | (-(v1371 ^ ((int)((unsigned int)((int)((unsigned int)v1367 >> 2)) >> 1))))) >> 31)) & 1);
    int v1380 = v1379[v1515];
    int * v1381 = v1359->cache_age;
    int v1382 = v1381[v1505];
    int * v1383 = v1359->cache_age;
    int v1518 = v1382 + ((int)((unsigned int)(v1382 - v1380) >> 31));
    v1383[v1505] = v1518;
    int * v1385 = v1359->cache_age;
    int v1386 = v1385[v1507];
    int * v1387 = v1359->cache_age;
    int v1521 = v1386 + ((int)((unsigned int)(v1386 - v1380) >> 31));
    v1387[v1507] = v1521;
    int * v1389 = v1359->cache_age;
    v1389[v1515] = 0;
    v1491 = v1515;
  } else {
    int * v1392 = v1359->cache_age;
    int v1525 = (((int)((unsigned int)((int)((unsigned int)v1367 >> 2)) >> 1)) & 1) * 2;
    int v1393 = v1392[v1525];
    int * v1394 = v1359->cache_tags;
    int v1395 = v1394[v1525];
    int * v1396 = v1359->cache_age;
    int v1397 = v1396[v1507];
    int * v1398 = v1359->cache_tags;
    int v1399 = v1398[v1507];
    bool v1529 = !(((~(((v1373 ^ ((int)((unsigned int)((int)((unsigned int)v1367 >> 2)) >> 1))) | (-(v1373 ^ ((int)((unsigned int)((int)((unsigned int)v1367 >> 2)) >> 1))))) >> 31)) | (~(((v1375 ^ ((int)((unsigned int)((int)((unsigned int)v1367 >> 2)) >> 1))) | (-(v1375 ^ ((int)((unsigned int)((int)((unsigned int)v1367 >> 2)) >> 1))))) >> 31))) == 0);
    int v1463;
    if (v1529) {
      int * v1400 = v1359->cache_age;
      int v1531 = (4 + ((((int)((unsigned int)((int)((unsigned int)v1367 >> 2)) >> 1)) & 3) * 2)) + ((~(((v1375 ^ ((int)((unsigned int)((int)((unsigned int)v1367 >> 2)) >> 1))) | (-(v1375 ^ ((int)((unsigned int)((int)((unsigned int)v1367 >> 2)) >> 1))))) >> 31)) & 1);
      int v1401 = v1400[v1531];
      int * v1402 = v1359->cache_age;
      int v1403 = v1402[v1509];
      int * v1404 = v1359->cache_age;
      int v1534 = v1403 + ((int)((unsigned int)(v1403 - v1401) >> 31));
      v1404[v1509] = v1534;
      int * v1406 = v1359->cache_age;
      int v1407 = v1406[v1511];
      int * v1408 = v1359->cache_age;
      int v1537 = v1407 + ((int)((unsigned int)(v1407 - v1401) >> 31));
      v1408[v1511] = v1537;
      int * v1410 = v1359->cache_age;
      v1410[v1531] = 0;
      v1463 = v1531;
    } else {
      int * v1413 = v1359->cache_age;
      int v1541 = 4 + ((((int)((unsigned int)((int)((unsigned int)v1367 >> 2)) >> 1)) & 3) * 2);
      int v1414 = v1413[v1541];
      int * v1415 = v1359->cache_tags;
      int v1416 = v1415[v1541];
      int * v1417 = v1359->cache_age;
      int v1418 = v1417[v1511];
      int * v1419 = v1359->cache_tags;
      int v1420 = v1419[v1511];
      int * v1421 = v1359->cache_dirty;
      int v1546 = (4 + ((((int)((unsigned int)((int)((unsigned int)v1367 >> 2)) >> 1)) & 3) * 2)) + ((((v1414 + ((~(((v1416 ^ -1) | (-(v1416 ^ -1))) >> 31)) & 2)) - (v1418 + ((~(((v1420 ^ -1) | (-(v1420 ^ -1))) >> 31)) & 2))) >> 31) & 1);
      int v1422 = v1421[v1546];
      bool v1547 = !(v1422 == 0);
      if (v1547) {
        int * v1423 = v1359->cache_tags;
        int v1424 = v1423[v1546];
        int * v1425 = v1359->cache_vals;
        int v1550 = ((4 + ((((int)((unsigned int)((int)((unsigned int)v1367 >> 2)) >> 1)) & 3) * 2)) + ((((v1414 + ((~(((v1416 ^ -1) | (-(v1416 ^ -1))) >> 31)) & 2)) - (v1418 + ((~(((v1420 ^ -1) | (-(v1420 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
        int v1426 = v1425[v1550];
        int * v1427 = v1359->cache_vals;
        int v1552 = (((4 + ((((int)((unsigned int)((int)((unsigned int)v1367 >> 2)) >> 1)) & 3) * 2)) + ((((v1414 + ((~(((v1416 ^ -1) | (-(v1416 ^ -1))) >> 31)) & 2)) - (v1418 + ((~(((v1420 ^ -1) | (-(v1420 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
        int v1428 = v1427[v1552];
        int * v1429 = v1359->mem;
        int v1554 = v1424 * 2;
        v1429[v1554] = v1426;
        int * v1431 = v1359->mem;
        int v1557 = (v1424 * 2) + 1;
        v1431[v1557] = v1428;
        ;
      } else {
        ;
      }
      int * v1436 = v1359->mem;
      int v1562 = ((int)((unsigned int)((int)((unsigned int)v1367 >> 2)) >> 1)) * 2;
      int v1437 = v1436[v1562];
      int * v1438 = v1359->mem;
      int v1564 = (((int)((unsigned int)((int)((unsigned int)v1367 >> 2)) >> 1)) * 2) + 1;
      int v1439 = v1438[v1564];
      int * v1440 = v1359->cache_vals;
      int v1566 = ((4 + ((((int)((unsigned int)((int)((unsigned int)v1367 >> 2)) >> 1)) & 3) * 2)) + ((((v1414 + ((~(((v1416 ^ -1) | (-(v1416 ^ -1))) >> 31)) & 2)) - (v1418 + ((~(((v1420 ^ -1) | (-(v1420 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
      v1440[v1566] = v1437;
      int * v1442 = v1359->cache_vals;
      int v1569 = (((4 + ((((int)((unsigned int)((int)((unsigned int)v1367 >> 2)) >> 1)) & 3) * 2)) + ((((v1414 + ((~(((v1416 ^ -1) | (-(v1416 ^ -1))) >> 31)) & 2)) - (v1418 + ((~(((v1420 ^ -1) | (-(v1420 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
      v1442[v1569] = v1439;
      int * v1444 = v1359->cache_tags;
      int v1572 = (int)((unsigned int)((int)((unsigned int)v1367 >> 2)) >> 1);
      v1444[v1546] = v1572;
      int * v1446 = v1359->cache_dirty;
      v1446[v1546] = 0;
      int * v1448 = v1359->cache_age;
      v1448[v1546] = 1;
      int * v1450 = v1359->cache_age;
      int v1451 = v1450[v1546];
      int * v1452 = v1359->cache_age;
      int v1453 = v1452[v1509];
      int * v1454 = v1359->cache_age;
      int v1580 = v1453 + ((int)((unsigned int)(v1453 - v1451) >> 31));
      v1454[v1509] = v1580;
      int * v1456 = v1359->cache_age;
      int v1457 = v1456[v1511];
      int * v1458 = v1359->cache_age;
      int v1583 = v1457 + ((int)((unsigned int)(v1457 - v1451) >> 31));
      v1458[v1511] = v1583;
      int * v1460 = v1359->cache_age;
      v1460[v1546] = 0;
      v1463 = v1546;
    }
    int * v1464 = v1359->cache_vals;
    int v1586 = v1463 * 2;
    int v1465 = v1464[v1586];
    int * v1466 = v1359->cache_vals;
    int v1588 = (v1463 * 2) + 1;
    int v1467 = v1466[v1588];
    int * v1468 = v1359->cache_vals;
    int v1590 = (((((int)((unsigned int)((int)((unsigned int)v1367 >> 2)) >> 1)) & 1) * 2) + ((((v1393 + ((~(((v1395 ^ -1) | (-(v1395 ^ -1))) >> 31)) & 2)) - (v1397 + ((~(((v1399 ^ -1) | (-(v1399 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
    v1468[v1590] = v1465;
    int * v1470 = v1359->cache_vals;
    int v1593 = ((((((int)((unsigned int)((int)((unsigned int)v1367 >> 2)) >> 1)) & 1) * 2) + ((((v1393 + ((~(((v1395 ^ -1) | (-(v1395 ^ -1))) >> 31)) & 2)) - (v1397 + ((~(((v1399 ^ -1) | (-(v1399 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
    v1470[v1593] = v1467;
    int * v1472 = v1359->cache_tags;
    int v1596 = ((((int)((unsigned int)((int)((unsigned int)v1367 >> 2)) >> 1)) & 1) * 2) + ((((v1393 + ((~(((v1395 ^ -1) | (-(v1395 ^ -1))) >> 31)) & 2)) - (v1397 + ((~(((v1399 ^ -1) | (-(v1399 ^ -1))) >> 31)) & 2))) >> 31) & 1);
    int v1597 = (int)((unsigned int)((int)((unsigned int)v1367 >> 2)) >> 1);
    v1472[v1596] = v1597;
    int * v1474 = v1359->cache_dirty;
    v1474[v1596] = 0;
    int * v1476 = v1359->cache_age;
    v1476[v1596] = 1;
    int * v1478 = v1359->cache_age;
    int v1479 = v1478[v1596];
    int * v1480 = v1359->cache_age;
    int v1481 = v1480[v1505];
    int * v1482 = v1359->cache_age;
    int v1605 = v1481 + ((int)((unsigned int)(v1481 - v1479) >> 31));
    v1482[v1505] = v1605;
    int * v1484 = v1359->cache_age;
    int v1485 = v1484[v1507];
    int * v1486 = v1359->cache_age;
    int v1608 = v1485 + ((int)((unsigned int)(v1485 - v1479) >> 31));
    v1486[v1507] = v1608;
    int * v1488 = v1359->cache_age;
    v1488[v1596] = 0;
    v1491 = v1596;
  }
  int v1611 = (v1491 * 2) + (((int)((unsigned int)v1367 >> 2)) & 1);
  int v1492 = v1378[v1611];
  int * v1493 = v1359->regs;
  v1493[5] = v1492;
  struct StateT * v1495 = slot_15(v1359);
  return v1495;
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

struct StateT * slot_10(struct StateT * v1307) {
  int v1308 = v1307->timer;
  int v1316 = v1308 + 1;
  v1307->timer = v1316;
  int * v1310 = v1307->regs;
  int v1311 = v1310[6];
  int * v1312 = v1307->regs;
  int v1320 = v1311 + 4;
  v1312[6] = v1320;
  struct StateT * v1314 = slot_11(v1307);
  return v1314;
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
  int v736 = v372 + 1;
  v371->timer = v736;
  int * v374 = v371->regs;
  int v375 = v374[6];
  int * v376 = v371->regs;
  int v377 = v376[5];
  int * v378 = v371->saved_regs;
  int * v379 = v371->regs;
  int v380 = v379[11];
  v378[11] = v380;
  int v382 = v371->timer;
  int v745 = v382 + 1;
  v371->timer = v745;
  int * v384 = v371->regs;
  int v385 = v384[6];
  int * v386 = v371->cache_tags;
  int v748 = (((int)((unsigned int)((int)((unsigned int)v385 >> 2)) >> 1)) & 1) * 2;
  int v387 = v386[v748];
  int * v388 = v371->cache_tags;
  int v750 = ((((int)((unsigned int)((int)((unsigned int)v385 >> 2)) >> 1)) & 1) * 2) + 1;
  int v389 = v388[v750];
  int * v390 = v371->cache_tags;
  int v752 = 4 + ((((int)((unsigned int)((int)((unsigned int)v385 >> 2)) >> 1)) & 3) * 2);
  int v391 = v390[v752];
  int * v392 = v371->cache_tags;
  int v754 = (4 + ((((int)((unsigned int)((int)((unsigned int)v385 >> 2)) >> 1)) & 3) * 2)) + 1;
  int v393 = v392[v754];
  int v394 = v371->timer;
  int v755 = v394 + ((100 ^ (((~(((v391 ^ ((int)((unsigned int)((int)((unsigned int)v385 >> 2)) >> 1))) | (-(v391 ^ ((int)((unsigned int)((int)((unsigned int)v385 >> 2)) >> 1))))) >> 31)) | (~(((v393 ^ ((int)((unsigned int)((int)((unsigned int)v385 >> 2)) >> 1))) | (-(v393 ^ ((int)((unsigned int)((int)((unsigned int)v385 >> 2)) >> 1))))) >> 31))) & 104)) ^ (((~(((v387 ^ ((int)((unsigned int)((int)((unsigned int)v385 >> 2)) >> 1))) | (-(v387 ^ ((int)((unsigned int)((int)((unsigned int)v385 >> 2)) >> 1))))) >> 31)) | (~(((v389 ^ ((int)((unsigned int)((int)((unsigned int)v385 >> 2)) >> 1))) | (-(v389 ^ ((int)((unsigned int)((int)((unsigned int)v385 >> 2)) >> 1))))) >> 31))) & (1 ^ (100 ^ (((~(((v391 ^ ((int)((unsigned int)((int)((unsigned int)v385 >> 2)) >> 1))) | (-(v391 ^ ((int)((unsigned int)((int)((unsigned int)v385 >> 2)) >> 1))))) >> 31)) | (~(((v393 ^ ((int)((unsigned int)((int)((unsigned int)v385 >> 2)) >> 1))) | (-(v393 ^ ((int)((unsigned int)((int)((unsigned int)v385 >> 2)) >> 1))))) >> 31))) & 104)))));
  v371->timer = v755;
  int * v396 = v371->cache_vals;
  bool v756 = !(((~(((v387 ^ ((int)((unsigned int)((int)((unsigned int)v385 >> 2)) >> 1))) | (-(v387 ^ ((int)((unsigned int)((int)((unsigned int)v385 >> 2)) >> 1))))) >> 31)) | (~(((v389 ^ ((int)((unsigned int)((int)((unsigned int)v385 >> 2)) >> 1))) | (-(v389 ^ ((int)((unsigned int)((int)((unsigned int)v385 >> 2)) >> 1))))) >> 31))) == 0);
  int v509;
  if (v756) {
    int * v397 = v371->cache_age;
    int v758 = ((((int)((unsigned int)((int)((unsigned int)v385 >> 2)) >> 1)) & 1) * 2) + ((~(((v389 ^ ((int)((unsigned int)((int)((unsigned int)v385 >> 2)) >> 1))) | (-(v389 ^ ((int)((unsigned int)((int)((unsigned int)v385 >> 2)) >> 1))))) >> 31)) & 1);
    int v398 = v397[v758];
    int * v399 = v371->cache_age;
    int v400 = v399[v748];
    int * v401 = v371->cache_age;
    int v761 = v400 + ((int)((unsigned int)(v400 - v398) >> 31));
    v401[v748] = v761;
    int * v403 = v371->cache_age;
    int v404 = v403[v750];
    int * v405 = v371->cache_age;
    int v764 = v404 + ((int)((unsigned int)(v404 - v398) >> 31));
    v405[v750] = v764;
    int * v407 = v371->cache_age;
    v407[v758] = 0;
    v509 = v758;
  } else {
    int * v410 = v371->cache_age;
    int v768 = (((int)((unsigned int)((int)((unsigned int)v385 >> 2)) >> 1)) & 1) * 2;
    int v411 = v410[v768];
    int * v412 = v371->cache_tags;
    int v413 = v412[v768];
    int * v414 = v371->cache_age;
    int v415 = v414[v750];
    int * v416 = v371->cache_tags;
    int v417 = v416[v750];
    bool v772 = !(((~(((v391 ^ ((int)((unsigned int)((int)((unsigned int)v385 >> 2)) >> 1))) | (-(v391 ^ ((int)((unsigned int)((int)((unsigned int)v385 >> 2)) >> 1))))) >> 31)) | (~(((v393 ^ ((int)((unsigned int)((int)((unsigned int)v385 >> 2)) >> 1))) | (-(v393 ^ ((int)((unsigned int)((int)((unsigned int)v385 >> 2)) >> 1))))) >> 31))) == 0);
    int v481;
    if (v772) {
      int * v418 = v371->cache_age;
      int v774 = (4 + ((((int)((unsigned int)((int)((unsigned int)v385 >> 2)) >> 1)) & 3) * 2)) + ((~(((v393 ^ ((int)((unsigned int)((int)((unsigned int)v385 >> 2)) >> 1))) | (-(v393 ^ ((int)((unsigned int)((int)((unsigned int)v385 >> 2)) >> 1))))) >> 31)) & 1);
      int v419 = v418[v774];
      int * v420 = v371->cache_age;
      int v421 = v420[v752];
      int * v422 = v371->cache_age;
      int v777 = v421 + ((int)((unsigned int)(v421 - v419) >> 31));
      v422[v752] = v777;
      int * v424 = v371->cache_age;
      int v425 = v424[v754];
      int * v426 = v371->cache_age;
      int v780 = v425 + ((int)((unsigned int)(v425 - v419) >> 31));
      v426[v754] = v780;
      int * v428 = v371->cache_age;
      v428[v774] = 0;
      v481 = v774;
    } else {
      int * v431 = v371->cache_age;
      int v784 = 4 + ((((int)((unsigned int)((int)((unsigned int)v385 >> 2)) >> 1)) & 3) * 2);
      int v432 = v431[v784];
      int * v433 = v371->cache_tags;
      int v434 = v433[v784];
      int * v435 = v371->cache_age;
      int v436 = v435[v754];
      int * v437 = v371->cache_tags;
      int v438 = v437[v754];
      int * v439 = v371->cache_dirty;
      int v789 = (4 + ((((int)((unsigned int)((int)((unsigned int)v385 >> 2)) >> 1)) & 3) * 2)) + ((((v432 + ((~(((v434 ^ -1) | (-(v434 ^ -1))) >> 31)) & 2)) - (v436 + ((~(((v438 ^ -1) | (-(v438 ^ -1))) >> 31)) & 2))) >> 31) & 1);
      int v440 = v439[v789];
      bool v790 = !(v440 == 0);
      if (v790) {
        int * v441 = v371->cache_tags;
        int v442 = v441[v789];
        int * v443 = v371->cache_vals;
        int v793 = ((4 + ((((int)((unsigned int)((int)((unsigned int)v385 >> 2)) >> 1)) & 3) * 2)) + ((((v432 + ((~(((v434 ^ -1) | (-(v434 ^ -1))) >> 31)) & 2)) - (v436 + ((~(((v438 ^ -1) | (-(v438 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
        int v444 = v443[v793];
        int * v445 = v371->cache_vals;
        int v795 = (((4 + ((((int)((unsigned int)((int)((unsigned int)v385 >> 2)) >> 1)) & 3) * 2)) + ((((v432 + ((~(((v434 ^ -1) | (-(v434 ^ -1))) >> 31)) & 2)) - (v436 + ((~(((v438 ^ -1) | (-(v438 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
        int v446 = v445[v795];
        int * v447 = v371->mem;
        int v797 = v442 * 2;
        v447[v797] = v444;
        int * v449 = v371->mem;
        int v800 = (v442 * 2) + 1;
        v449[v800] = v446;
        ;
      } else {
        ;
      }
      int * v454 = v371->mem;
      int v805 = ((int)((unsigned int)((int)((unsigned int)v385 >> 2)) >> 1)) * 2;
      int v455 = v454[v805];
      int * v456 = v371->mem;
      int v807 = (((int)((unsigned int)((int)((unsigned int)v385 >> 2)) >> 1)) * 2) + 1;
      int v457 = v456[v807];
      int * v458 = v371->cache_vals;
      int v809 = ((4 + ((((int)((unsigned int)((int)((unsigned int)v385 >> 2)) >> 1)) & 3) * 2)) + ((((v432 + ((~(((v434 ^ -1) | (-(v434 ^ -1))) >> 31)) & 2)) - (v436 + ((~(((v438 ^ -1) | (-(v438 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
      v458[v809] = v455;
      int * v460 = v371->cache_vals;
      int v812 = (((4 + ((((int)((unsigned int)((int)((unsigned int)v385 >> 2)) >> 1)) & 3) * 2)) + ((((v432 + ((~(((v434 ^ -1) | (-(v434 ^ -1))) >> 31)) & 2)) - (v436 + ((~(((v438 ^ -1) | (-(v438 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
      v460[v812] = v457;
      int * v462 = v371->cache_tags;
      int v815 = (int)((unsigned int)((int)((unsigned int)v385 >> 2)) >> 1);
      v462[v789] = v815;
      int * v464 = v371->cache_dirty;
      v464[v789] = 0;
      int * v466 = v371->cache_age;
      v466[v789] = 1;
      int * v468 = v371->cache_age;
      int v469 = v468[v789];
      int * v470 = v371->cache_age;
      int v471 = v470[v752];
      int * v472 = v371->cache_age;
      int v823 = v471 + ((int)((unsigned int)(v471 - v469) >> 31));
      v472[v752] = v823;
      int * v474 = v371->cache_age;
      int v475 = v474[v754];
      int * v476 = v371->cache_age;
      int v826 = v475 + ((int)((unsigned int)(v475 - v469) >> 31));
      v476[v754] = v826;
      int * v478 = v371->cache_age;
      v478[v789] = 0;
      v481 = v789;
    }
    int * v482 = v371->cache_vals;
    int v829 = v481 * 2;
    int v483 = v482[v829];
    int * v484 = v371->cache_vals;
    int v831 = (v481 * 2) + 1;
    int v485 = v484[v831];
    int * v486 = v371->cache_vals;
    int v833 = (((((int)((unsigned int)((int)((unsigned int)v385 >> 2)) >> 1)) & 1) * 2) + ((((v411 + ((~(((v413 ^ -1) | (-(v413 ^ -1))) >> 31)) & 2)) - (v415 + ((~(((v417 ^ -1) | (-(v417 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
    v486[v833] = v483;
    int * v488 = v371->cache_vals;
    int v836 = ((((((int)((unsigned int)((int)((unsigned int)v385 >> 2)) >> 1)) & 1) * 2) + ((((v411 + ((~(((v413 ^ -1) | (-(v413 ^ -1))) >> 31)) & 2)) - (v415 + ((~(((v417 ^ -1) | (-(v417 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
    v488[v836] = v485;
    int * v490 = v371->cache_tags;
    int v839 = ((((int)((unsigned int)((int)((unsigned int)v385 >> 2)) >> 1)) & 1) * 2) + ((((v411 + ((~(((v413 ^ -1) | (-(v413 ^ -1))) >> 31)) & 2)) - (v415 + ((~(((v417 ^ -1) | (-(v417 ^ -1))) >> 31)) & 2))) >> 31) & 1);
    int v840 = (int)((unsigned int)((int)((unsigned int)v385 >> 2)) >> 1);
    v490[v839] = v840;
    int * v492 = v371->cache_dirty;
    v492[v839] = 0;
    int * v494 = v371->cache_age;
    v494[v839] = 1;
    int * v496 = v371->cache_age;
    int v497 = v496[v839];
    int * v498 = v371->cache_age;
    int v499 = v498[v748];
    int * v500 = v371->cache_age;
    int v848 = v499 + ((int)((unsigned int)(v499 - v497) >> 31));
    v500[v748] = v848;
    int * v502 = v371->cache_age;
    int v503 = v502[v750];
    int * v504 = v371->cache_age;
    int v851 = v503 + ((int)((unsigned int)(v503 - v497) >> 31));
    v504[v750] = v851;
    int * v506 = v371->cache_age;
    v506[v839] = 0;
    v509 = v839;
  }
  int v854 = (v509 * 2) + (((int)((unsigned int)v385 >> 2)) & 1);
  int v510 = v396[v854];
  int * v511 = v371->regs;
  v511[11] = v510;
  int * v513 = v371->saved_regs;
  int * v514 = v371->regs;
  int v515 = v514[6];
  v513[6] = v515;
  int v517 = v371->timer;
  int v860 = v517 + 1;
  v371->timer = v860;
  int * v519 = v371->regs;
  int v520 = v519[6];
  int * v521 = v371->regs;
  int v863 = v520 + 4;
  v521[6] = v863;
  int * v523 = v371->cache_tags;
  int v865 = (((int)((unsigned int)((int)((unsigned int)v375 >> 2)) >> 1)) & 1) * 2;
  int v524 = v523[v865];
  int * v525 = v371->cache_tags;
  int v867 = ((((int)((unsigned int)((int)((unsigned int)v375 >> 2)) >> 1)) & 1) * 2) + 1;
  int v526 = v525[v867];
  int * v527 = v371->cache_tags;
  int v869 = 4 + ((((int)((unsigned int)((int)((unsigned int)v375 >> 2)) >> 1)) & 3) * 2);
  int v528 = v527[v869];
  int * v529 = v371->cache_tags;
  int v871 = (4 + ((((int)((unsigned int)((int)((unsigned int)v375 >> 2)) >> 1)) & 3) * 2)) + 1;
  int v530 = v529[v871];
  int v531 = v371->timer;
  int v872 = v531 + ((100 ^ (((~(((v528 ^ ((int)((unsigned int)((int)((unsigned int)v375 >> 2)) >> 1))) | (-(v528 ^ ((int)((unsigned int)((int)((unsigned int)v375 >> 2)) >> 1))))) >> 31)) | (~(((v530 ^ ((int)((unsigned int)((int)((unsigned int)v375 >> 2)) >> 1))) | (-(v530 ^ ((int)((unsigned int)((int)((unsigned int)v375 >> 2)) >> 1))))) >> 31))) & 104)) ^ (((~(((v524 ^ ((int)((unsigned int)((int)((unsigned int)v375 >> 2)) >> 1))) | (-(v524 ^ ((int)((unsigned int)((int)((unsigned int)v375 >> 2)) >> 1))))) >> 31)) | (~(((v526 ^ ((int)((unsigned int)((int)((unsigned int)v375 >> 2)) >> 1))) | (-(v526 ^ ((int)((unsigned int)((int)((unsigned int)v375 >> 2)) >> 1))))) >> 31))) & (1 ^ (100 ^ (((~(((v528 ^ ((int)((unsigned int)((int)((unsigned int)v375 >> 2)) >> 1))) | (-(v528 ^ ((int)((unsigned int)((int)((unsigned int)v375 >> 2)) >> 1))))) >> 31)) | (~(((v530 ^ ((int)((unsigned int)((int)((unsigned int)v375 >> 2)) >> 1))) | (-(v530 ^ ((int)((unsigned int)((int)((unsigned int)v375 >> 2)) >> 1))))) >> 31))) & 104)))));
  v371->timer = v872;
  bool v873 = !(((~(((v524 ^ ((int)((unsigned int)((int)((unsigned int)v375 >> 2)) >> 1))) | (-(v524 ^ ((int)((unsigned int)((int)((unsigned int)v375 >> 2)) >> 1))))) >> 31)) | (~(((v526 ^ ((int)((unsigned int)((int)((unsigned int)v375 >> 2)) >> 1))) | (-(v526 ^ ((int)((unsigned int)((int)((unsigned int)v375 >> 2)) >> 1))))) >> 31))) == 0);
  int v645;
  if (v873) {
    int * v533 = v371->cache_age;
    int v875 = ((((int)((unsigned int)((int)((unsigned int)v375 >> 2)) >> 1)) & 1) * 2) + ((~(((v526 ^ ((int)((unsigned int)((int)((unsigned int)v375 >> 2)) >> 1))) | (-(v526 ^ ((int)((unsigned int)((int)((unsigned int)v375 >> 2)) >> 1))))) >> 31)) & 1);
    int v534 = v533[v875];
    int * v535 = v371->cache_age;
    int v536 = v535[v865];
    int * v537 = v371->cache_age;
    int v878 = v536 + ((int)((unsigned int)(v536 - v534) >> 31));
    v537[v865] = v878;
    int * v539 = v371->cache_age;
    int v540 = v539[v867];
    int * v541 = v371->cache_age;
    int v881 = v540 + ((int)((unsigned int)(v540 - v534) >> 31));
    v541[v867] = v881;
    int * v543 = v371->cache_age;
    v543[v875] = 0;
    v645 = v875;
  } else {
    int * v546 = v371->cache_age;
    int v885 = (((int)((unsigned int)((int)((unsigned int)v375 >> 2)) >> 1)) & 1) * 2;
    int v547 = v546[v885];
    int * v548 = v371->cache_tags;
    int v549 = v548[v885];
    int * v550 = v371->cache_age;
    int v551 = v550[v867];
    int * v552 = v371->cache_tags;
    int v553 = v552[v867];
    bool v889 = !(((~(((v528 ^ ((int)((unsigned int)((int)((unsigned int)v375 >> 2)) >> 1))) | (-(v528 ^ ((int)((unsigned int)((int)((unsigned int)v375 >> 2)) >> 1))))) >> 31)) | (~(((v530 ^ ((int)((unsigned int)((int)((unsigned int)v375 >> 2)) >> 1))) | (-(v530 ^ ((int)((unsigned int)((int)((unsigned int)v375 >> 2)) >> 1))))) >> 31))) == 0);
    int v617;
    if (v889) {
      int * v554 = v371->cache_age;
      int v891 = (4 + ((((int)((unsigned int)((int)((unsigned int)v375 >> 2)) >> 1)) & 3) * 2)) + ((~(((v530 ^ ((int)((unsigned int)((int)((unsigned int)v375 >> 2)) >> 1))) | (-(v530 ^ ((int)((unsigned int)((int)((unsigned int)v375 >> 2)) >> 1))))) >> 31)) & 1);
      int v555 = v554[v891];
      int * v556 = v371->cache_age;
      int v557 = v556[v869];
      int * v558 = v371->cache_age;
      int v894 = v557 + ((int)((unsigned int)(v557 - v555) >> 31));
      v558[v869] = v894;
      int * v560 = v371->cache_age;
      int v561 = v560[v871];
      int * v562 = v371->cache_age;
      int v897 = v561 + ((int)((unsigned int)(v561 - v555) >> 31));
      v562[v871] = v897;
      int * v564 = v371->cache_age;
      v564[v891] = 0;
      v617 = v891;
    } else {
      int * v567 = v371->cache_age;
      int v901 = 4 + ((((int)((unsigned int)((int)((unsigned int)v375 >> 2)) >> 1)) & 3) * 2);
      int v568 = v567[v901];
      int * v569 = v371->cache_tags;
      int v570 = v569[v901];
      int * v571 = v371->cache_age;
      int v572 = v571[v871];
      int * v573 = v371->cache_tags;
      int v574 = v573[v871];
      int * v575 = v371->cache_dirty;
      int v906 = (4 + ((((int)((unsigned int)((int)((unsigned int)v375 >> 2)) >> 1)) & 3) * 2)) + ((((v568 + ((~(((v570 ^ -1) | (-(v570 ^ -1))) >> 31)) & 2)) - (v572 + ((~(((v574 ^ -1) | (-(v574 ^ -1))) >> 31)) & 2))) >> 31) & 1);
      int v576 = v575[v906];
      bool v907 = !(v576 == 0);
      if (v907) {
        int * v577 = v371->cache_tags;
        int v578 = v577[v906];
        int * v579 = v371->cache_vals;
        int v910 = ((4 + ((((int)((unsigned int)((int)((unsigned int)v375 >> 2)) >> 1)) & 3) * 2)) + ((((v568 + ((~(((v570 ^ -1) | (-(v570 ^ -1))) >> 31)) & 2)) - (v572 + ((~(((v574 ^ -1) | (-(v574 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
        int v580 = v579[v910];
        int * v581 = v371->cache_vals;
        int v912 = (((4 + ((((int)((unsigned int)((int)((unsigned int)v375 >> 2)) >> 1)) & 3) * 2)) + ((((v568 + ((~(((v570 ^ -1) | (-(v570 ^ -1))) >> 31)) & 2)) - (v572 + ((~(((v574 ^ -1) | (-(v574 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
        int v582 = v581[v912];
        int * v583 = v371->mem;
        int v914 = v578 * 2;
        v583[v914] = v580;
        int * v585 = v371->mem;
        int v917 = (v578 * 2) + 1;
        v585[v917] = v582;
        ;
      } else {
        ;
      }
      int * v590 = v371->mem;
      int v922 = ((int)((unsigned int)((int)((unsigned int)v375 >> 2)) >> 1)) * 2;
      int v591 = v590[v922];
      int * v592 = v371->mem;
      int v924 = (((int)((unsigned int)((int)((unsigned int)v375 >> 2)) >> 1)) * 2) + 1;
      int v593 = v592[v924];
      int * v594 = v371->cache_vals;
      int v926 = ((4 + ((((int)((unsigned int)((int)((unsigned int)v375 >> 2)) >> 1)) & 3) * 2)) + ((((v568 + ((~(((v570 ^ -1) | (-(v570 ^ -1))) >> 31)) & 2)) - (v572 + ((~(((v574 ^ -1) | (-(v574 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
      v594[v926] = v591;
      int * v596 = v371->cache_vals;
      int v929 = (((4 + ((((int)((unsigned int)((int)((unsigned int)v375 >> 2)) >> 1)) & 3) * 2)) + ((((v568 + ((~(((v570 ^ -1) | (-(v570 ^ -1))) >> 31)) & 2)) - (v572 + ((~(((v574 ^ -1) | (-(v574 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
      v596[v929] = v593;
      int * v598 = v371->cache_tags;
      int v932 = (int)((unsigned int)((int)((unsigned int)v375 >> 2)) >> 1);
      v598[v906] = v932;
      int * v600 = v371->cache_dirty;
      v600[v906] = 0;
      int * v602 = v371->cache_age;
      v602[v906] = 1;
      int * v604 = v371->cache_age;
      int v605 = v604[v906];
      int * v606 = v371->cache_age;
      int v607 = v606[v869];
      int * v608 = v371->cache_age;
      int v940 = v607 + ((int)((unsigned int)(v607 - v605) >> 31));
      v608[v869] = v940;
      int * v610 = v371->cache_age;
      int v611 = v610[v871];
      int * v612 = v371->cache_age;
      int v943 = v611 + ((int)((unsigned int)(v611 - v605) >> 31));
      v612[v871] = v943;
      int * v614 = v371->cache_age;
      v614[v906] = 0;
      v617 = v906;
    }
    int * v618 = v371->cache_vals;
    int v946 = v617 * 2;
    int v619 = v618[v946];
    int * v620 = v371->cache_vals;
    int v948 = (v617 * 2) + 1;
    int v621 = v620[v948];
    int * v622 = v371->cache_vals;
    int v950 = (((((int)((unsigned int)((int)((unsigned int)v375 >> 2)) >> 1)) & 1) * 2) + ((((v547 + ((~(((v549 ^ -1) | (-(v549 ^ -1))) >> 31)) & 2)) - (v551 + ((~(((v553 ^ -1) | (-(v553 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
    v622[v950] = v619;
    int * v624 = v371->cache_vals;
    int v953 = ((((((int)((unsigned int)((int)((unsigned int)v375 >> 2)) >> 1)) & 1) * 2) + ((((v547 + ((~(((v549 ^ -1) | (-(v549 ^ -1))) >> 31)) & 2)) - (v551 + ((~(((v553 ^ -1) | (-(v553 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
    v624[v953] = v621;
    int * v626 = v371->cache_tags;
    int v956 = ((((int)((unsigned int)((int)((unsigned int)v375 >> 2)) >> 1)) & 1) * 2) + ((((v547 + ((~(((v549 ^ -1) | (-(v549 ^ -1))) >> 31)) & 2)) - (v551 + ((~(((v553 ^ -1) | (-(v553 ^ -1))) >> 31)) & 2))) >> 31) & 1);
    int v957 = (int)((unsigned int)((int)((unsigned int)v375 >> 2)) >> 1);
    v626[v956] = v957;
    int * v628 = v371->cache_dirty;
    v628[v956] = 0;
    int * v630 = v371->cache_age;
    v630[v956] = 1;
    int * v632 = v371->cache_age;
    int v633 = v632[v956];
    int * v634 = v371->cache_age;
    int v635 = v634[v865];
    int * v636 = v371->cache_age;
    int v965 = v635 + ((int)((unsigned int)(v635 - v633) >> 31));
    v636[v865] = v965;
    int * v638 = v371->cache_age;
    int v639 = v638[v867];
    int * v640 = v371->cache_age;
    int v968 = v639 + ((int)((unsigned int)(v639 - v633) >> 31));
    v640[v867] = v968;
    int * v642 = v371->cache_age;
    v642[v956] = 0;
    v645 = v956;
  }
  int * v646 = v371->cache_vals;
  int v971 = (v645 * 2) + (((int)((unsigned int)v375 >> 2)) & 1);
  v646[v971] = v377;
  int * v648 = v371->cache_tags;
  int v649 = v648[v869];
  int * v650 = v371->cache_tags;
  int v651 = v650[v871];
  bool v975 = !(((~(((v649 ^ ((int)((unsigned int)((int)((unsigned int)v375 >> 2)) >> 1))) | (-(v649 ^ ((int)((unsigned int)((int)((unsigned int)v375 >> 2)) >> 1))))) >> 31)) | (~(((v651 ^ ((int)((unsigned int)((int)((unsigned int)v375 >> 2)) >> 1))) | (-(v651 ^ ((int)((unsigned int)((int)((unsigned int)v375 >> 2)) >> 1))))) >> 31))) == 0);
  int v715;
  if (v975) {
    int * v652 = v371->cache_age;
    int v977 = (4 + ((((int)((unsigned int)((int)((unsigned int)v375 >> 2)) >> 1)) & 3) * 2)) + ((~(((v651 ^ ((int)((unsigned int)((int)((unsigned int)v375 >> 2)) >> 1))) | (-(v651 ^ ((int)((unsigned int)((int)((unsigned int)v375 >> 2)) >> 1))))) >> 31)) & 1);
    int v653 = v652[v977];
    int * v654 = v371->cache_age;
    int v655 = v654[v869];
    int * v656 = v371->cache_age;
    int v980 = v655 + ((int)((unsigned int)(v655 - v653) >> 31));
    v656[v869] = v980;
    int * v658 = v371->cache_age;
    int v659 = v658[v871];
    int * v660 = v371->cache_age;
    int v983 = v659 + ((int)((unsigned int)(v659 - v653) >> 31));
    v660[v871] = v983;
    int * v662 = v371->cache_age;
    v662[v977] = 0;
    v715 = v977;
  } else {
    int * v665 = v371->cache_age;
    int v987 = 4 + ((((int)((unsigned int)((int)((unsigned int)v375 >> 2)) >> 1)) & 3) * 2);
    int v666 = v665[v987];
    int * v667 = v371->cache_tags;
    int v668 = v667[v987];
    int * v669 = v371->cache_age;
    int v670 = v669[v871];
    int * v671 = v371->cache_tags;
    int v672 = v671[v871];
    int * v673 = v371->cache_dirty;
    int v992 = (4 + ((((int)((unsigned int)((int)((unsigned int)v375 >> 2)) >> 1)) & 3) * 2)) + ((((v666 + ((~(((v668 ^ -1) | (-(v668 ^ -1))) >> 31)) & 2)) - (v670 + ((~(((v672 ^ -1) | (-(v672 ^ -1))) >> 31)) & 2))) >> 31) & 1);
    int v674 = v673[v992];
    bool v993 = !(v674 == 0);
    if (v993) {
      int * v675 = v371->cache_tags;
      int v676 = v675[v992];
      int * v677 = v371->cache_vals;
      int v996 = ((4 + ((((int)((unsigned int)((int)((unsigned int)v375 >> 2)) >> 1)) & 3) * 2)) + ((((v666 + ((~(((v668 ^ -1) | (-(v668 ^ -1))) >> 31)) & 2)) - (v670 + ((~(((v672 ^ -1) | (-(v672 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
      int v678 = v677[v996];
      int * v679 = v371->cache_vals;
      int v998 = (((4 + ((((int)((unsigned int)((int)((unsigned int)v375 >> 2)) >> 1)) & 3) * 2)) + ((((v666 + ((~(((v668 ^ -1) | (-(v668 ^ -1))) >> 31)) & 2)) - (v670 + ((~(((v672 ^ -1) | (-(v672 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
      int v680 = v679[v998];
      int * v681 = v371->mem;
      int v1000 = v676 * 2;
      v681[v1000] = v678;
      int * v683 = v371->mem;
      int v1003 = (v676 * 2) + 1;
      v683[v1003] = v680;
      ;
    } else {
      ;
    }
    int * v688 = v371->mem;
    int v1008 = ((int)((unsigned int)((int)((unsigned int)v375 >> 2)) >> 1)) * 2;
    int v689 = v688[v1008];
    int * v690 = v371->mem;
    int v1010 = (((int)((unsigned int)((int)((unsigned int)v375 >> 2)) >> 1)) * 2) + 1;
    int v691 = v690[v1010];
    int * v692 = v371->cache_vals;
    int v1012 = ((4 + ((((int)((unsigned int)((int)((unsigned int)v375 >> 2)) >> 1)) & 3) * 2)) + ((((v666 + ((~(((v668 ^ -1) | (-(v668 ^ -1))) >> 31)) & 2)) - (v670 + ((~(((v672 ^ -1) | (-(v672 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
    v692[v1012] = v689;
    int * v694 = v371->cache_vals;
    int v1015 = (((4 + ((((int)((unsigned int)((int)((unsigned int)v375 >> 2)) >> 1)) & 3) * 2)) + ((((v666 + ((~(((v668 ^ -1) | (-(v668 ^ -1))) >> 31)) & 2)) - (v670 + ((~(((v672 ^ -1) | (-(v672 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
    v694[v1015] = v691;
    int * v696 = v371->cache_tags;
    int v1018 = (int)((unsigned int)((int)((unsigned int)v375 >> 2)) >> 1);
    v696[v992] = v1018;
    int * v698 = v371->cache_dirty;
    v698[v992] = 0;
    int * v700 = v371->cache_age;
    v700[v992] = 1;
    int * v702 = v371->cache_age;
    int v703 = v702[v992];
    int * v704 = v371->cache_age;
    int v705 = v704[v869];
    int * v706 = v371->cache_age;
    int v1026 = v705 + ((int)((unsigned int)(v705 - v703) >> 31));
    v706[v869] = v1026;
    int * v708 = v371->cache_age;
    int v709 = v708[v871];
    int * v710 = v371->cache_age;
    int v1029 = v709 + ((int)((unsigned int)(v709 - v703) >> 31));
    v710[v871] = v1029;
    int * v712 = v371->cache_age;
    v712[v992] = 0;
    v715 = v992;
  }
  int * v716 = v371->cache_vals;
  int v1032 = (v715 * 2) + (((int)((unsigned int)v375 >> 2)) & 1);
  v716[v1032] = v377;
  int * v718 = v371->cache_dirty;
  v718[v715] = 1;
  bool v1036 = ((int)((unsigned int)v385 >> 2)) == ((int)((unsigned int)v375 >> 2));
  struct StateT * v734;
  if (v1036) {
    int v720 = v371->timer;
    int v1037 = v720 + 15;
    v371->timer = v1037;
    int * v722 = v371->saved_regs;
    int v723 = v722[11];
    int * v724 = v371->regs;
    v724[11] = v723;
    int * v726 = v371->saved_regs;
    int v727 = v726[6];
    int * v728 = v371->regs;
    v728[6] = v727;
    struct StateT * v730 = slot_9(v371);
    v734 = v730;
  } else {
    struct StateT * v732 = slot_11(v371);
    v734 = v732;
  }
  return v734;
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

struct StateT * slot_13(struct StateT * v1331) {
  int * v1332 = v1331->saved_regs;
  int * v1333 = v1331->regs;
  int v1334 = v1333[8];
  v1332[8] = v1334;
  int v1336 = v1331->timer;
  int v1350 = v1336 + 1;
  v1331->timer = v1350;
  int * v1338 = v1331->regs;
  int v1339 = v1338[9];
  int * v1340 = v1331->regs;
  int v1341 = v1340[6];
  int * v1342 = v1331->regs;
  int v1356 = v1339 + v1341;
  v1342[8] = v1356;
  struct StateT * v1344 = slot_14(v1331);
  return v1344;
}

struct StateT * slot_15(struct StateT * v1616) {
  int * v1617 = v1616->regs;
  int v1618 = v1617[6];
  int * v1619 = v1616->regs;
  int v1620 = v1619[7];
  bool v1640 = v1618 >= v1620;
  struct StateT * v1634;
  if (v1640) {
    int v1621 = v1616->timer;
    int v1641 = v1621 + 15;
    v1616->timer = v1641;
    int * v1623 = v1616->saved_regs;
    int v1624 = v1623[8];
    int * v1625 = v1616->regs;
    v1625[8] = v1624;
    int * v1627 = v1616->saved_regs;
    int v1628 = v1627[5];
    int * v1629 = v1616->regs;
    v1629[5] = v1628;
    v1634 = v1616;
  } else {
    struct StateT * v1632 = slot_8(v1616);
    v1634 = v1632;
  }
  return v1634;
}

struct StateT * slot_9(struct StateT * v1049) {
  int v1050 = v1049->timer;
  int v1183 = v1050 + 1;
  v1049->timer = v1183;
  int * v1052 = v1049->regs;
  int v1053 = v1052[6];
  int * v1054 = v1049->cache_tags;
  int v1187 = (((int)((unsigned int)((int)((unsigned int)v1053 >> 2)) >> 1)) & 1) * 2;
  int v1055 = v1054[v1187];
  int * v1056 = v1049->cache_tags;
  int v1189 = ((((int)((unsigned int)((int)((unsigned int)v1053 >> 2)) >> 1)) & 1) * 2) + 1;
  int v1057 = v1056[v1189];
  int * v1058 = v1049->cache_tags;
  int v1191 = 4 + ((((int)((unsigned int)((int)((unsigned int)v1053 >> 2)) >> 1)) & 3) * 2);
  int v1059 = v1058[v1191];
  int * v1060 = v1049->cache_tags;
  int v1193 = (4 + ((((int)((unsigned int)((int)((unsigned int)v1053 >> 2)) >> 1)) & 3) * 2)) + 1;
  int v1061 = v1060[v1193];
  int v1062 = v1049->timer;
  int v1194 = v1062 + ((100 ^ (((~(((v1059 ^ ((int)((unsigned int)((int)((unsigned int)v1053 >> 2)) >> 1))) | (-(v1059 ^ ((int)((unsigned int)((int)((unsigned int)v1053 >> 2)) >> 1))))) >> 31)) | (~(((v1061 ^ ((int)((unsigned int)((int)((unsigned int)v1053 >> 2)) >> 1))) | (-(v1061 ^ ((int)((unsigned int)((int)((unsigned int)v1053 >> 2)) >> 1))))) >> 31))) & 104)) ^ (((~(((v1055 ^ ((int)((unsigned int)((int)((unsigned int)v1053 >> 2)) >> 1))) | (-(v1055 ^ ((int)((unsigned int)((int)((unsigned int)v1053 >> 2)) >> 1))))) >> 31)) | (~(((v1057 ^ ((int)((unsigned int)((int)((unsigned int)v1053 >> 2)) >> 1))) | (-(v1057 ^ ((int)((unsigned int)((int)((unsigned int)v1053 >> 2)) >> 1))))) >> 31))) & (1 ^ (100 ^ (((~(((v1059 ^ ((int)((unsigned int)((int)((unsigned int)v1053 >> 2)) >> 1))) | (-(v1059 ^ ((int)((unsigned int)((int)((unsigned int)v1053 >> 2)) >> 1))))) >> 31)) | (~(((v1061 ^ ((int)((unsigned int)((int)((unsigned int)v1053 >> 2)) >> 1))) | (-(v1061 ^ ((int)((unsigned int)((int)((unsigned int)v1053 >> 2)) >> 1))))) >> 31))) & 104)))));
  v1049->timer = v1194;
  int * v1064 = v1049->cache_vals;
  bool v1195 = !(((~(((v1055 ^ ((int)((unsigned int)((int)((unsigned int)v1053 >> 2)) >> 1))) | (-(v1055 ^ ((int)((unsigned int)((int)((unsigned int)v1053 >> 2)) >> 1))))) >> 31)) | (~(((v1057 ^ ((int)((unsigned int)((int)((unsigned int)v1053 >> 2)) >> 1))) | (-(v1057 ^ ((int)((unsigned int)((int)((unsigned int)v1053 >> 2)) >> 1))))) >> 31))) == 0);
  int v1177;
  if (v1195) {
    int * v1065 = v1049->cache_age;
    int v1197 = ((((int)((unsigned int)((int)((unsigned int)v1053 >> 2)) >> 1)) & 1) * 2) + ((~(((v1057 ^ ((int)((unsigned int)((int)((unsigned int)v1053 >> 2)) >> 1))) | (-(v1057 ^ ((int)((unsigned int)((int)((unsigned int)v1053 >> 2)) >> 1))))) >> 31)) & 1);
    int v1066 = v1065[v1197];
    int * v1067 = v1049->cache_age;
    int v1068 = v1067[v1187];
    int * v1069 = v1049->cache_age;
    int v1200 = v1068 + ((int)((unsigned int)(v1068 - v1066) >> 31));
    v1069[v1187] = v1200;
    int * v1071 = v1049->cache_age;
    int v1072 = v1071[v1189];
    int * v1073 = v1049->cache_age;
    int v1203 = v1072 + ((int)((unsigned int)(v1072 - v1066) >> 31));
    v1073[v1189] = v1203;
    int * v1075 = v1049->cache_age;
    v1075[v1197] = 0;
    v1177 = v1197;
  } else {
    int * v1078 = v1049->cache_age;
    int v1207 = (((int)((unsigned int)((int)((unsigned int)v1053 >> 2)) >> 1)) & 1) * 2;
    int v1079 = v1078[v1207];
    int * v1080 = v1049->cache_tags;
    int v1081 = v1080[v1207];
    int * v1082 = v1049->cache_age;
    int v1083 = v1082[v1189];
    int * v1084 = v1049->cache_tags;
    int v1085 = v1084[v1189];
    bool v1211 = !(((~(((v1059 ^ ((int)((unsigned int)((int)((unsigned int)v1053 >> 2)) >> 1))) | (-(v1059 ^ ((int)((unsigned int)((int)((unsigned int)v1053 >> 2)) >> 1))))) >> 31)) | (~(((v1061 ^ ((int)((unsigned int)((int)((unsigned int)v1053 >> 2)) >> 1))) | (-(v1061 ^ ((int)((unsigned int)((int)((unsigned int)v1053 >> 2)) >> 1))))) >> 31))) == 0);
    int v1149;
    if (v1211) {
      int * v1086 = v1049->cache_age;
      int v1213 = (4 + ((((int)((unsigned int)((int)((unsigned int)v1053 >> 2)) >> 1)) & 3) * 2)) + ((~(((v1061 ^ ((int)((unsigned int)((int)((unsigned int)v1053 >> 2)) >> 1))) | (-(v1061 ^ ((int)((unsigned int)((int)((unsigned int)v1053 >> 2)) >> 1))))) >> 31)) & 1);
      int v1087 = v1086[v1213];
      int * v1088 = v1049->cache_age;
      int v1089 = v1088[v1191];
      int * v1090 = v1049->cache_age;
      int v1216 = v1089 + ((int)((unsigned int)(v1089 - v1087) >> 31));
      v1090[v1191] = v1216;
      int * v1092 = v1049->cache_age;
      int v1093 = v1092[v1193];
      int * v1094 = v1049->cache_age;
      int v1219 = v1093 + ((int)((unsigned int)(v1093 - v1087) >> 31));
      v1094[v1193] = v1219;
      int * v1096 = v1049->cache_age;
      v1096[v1213] = 0;
      v1149 = v1213;
    } else {
      int * v1099 = v1049->cache_age;
      int v1223 = 4 + ((((int)((unsigned int)((int)((unsigned int)v1053 >> 2)) >> 1)) & 3) * 2);
      int v1100 = v1099[v1223];
      int * v1101 = v1049->cache_tags;
      int v1102 = v1101[v1223];
      int * v1103 = v1049->cache_age;
      int v1104 = v1103[v1193];
      int * v1105 = v1049->cache_tags;
      int v1106 = v1105[v1193];
      int * v1107 = v1049->cache_dirty;
      int v1228 = (4 + ((((int)((unsigned int)((int)((unsigned int)v1053 >> 2)) >> 1)) & 3) * 2)) + ((((v1100 + ((~(((v1102 ^ -1) | (-(v1102 ^ -1))) >> 31)) & 2)) - (v1104 + ((~(((v1106 ^ -1) | (-(v1106 ^ -1))) >> 31)) & 2))) >> 31) & 1);
      int v1108 = v1107[v1228];
      bool v1229 = !(v1108 == 0);
      if (v1229) {
        int * v1109 = v1049->cache_tags;
        int v1110 = v1109[v1228];
        int * v1111 = v1049->cache_vals;
        int v1232 = ((4 + ((((int)((unsigned int)((int)((unsigned int)v1053 >> 2)) >> 1)) & 3) * 2)) + ((((v1100 + ((~(((v1102 ^ -1) | (-(v1102 ^ -1))) >> 31)) & 2)) - (v1104 + ((~(((v1106 ^ -1) | (-(v1106 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
        int v1112 = v1111[v1232];
        int * v1113 = v1049->cache_vals;
        int v1234 = (((4 + ((((int)((unsigned int)((int)((unsigned int)v1053 >> 2)) >> 1)) & 3) * 2)) + ((((v1100 + ((~(((v1102 ^ -1) | (-(v1102 ^ -1))) >> 31)) & 2)) - (v1104 + ((~(((v1106 ^ -1) | (-(v1106 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
        int v1114 = v1113[v1234];
        int * v1115 = v1049->mem;
        int v1236 = v1110 * 2;
        v1115[v1236] = v1112;
        int * v1117 = v1049->mem;
        int v1239 = (v1110 * 2) + 1;
        v1117[v1239] = v1114;
        ;
      } else {
        ;
      }
      int * v1122 = v1049->mem;
      int v1244 = ((int)((unsigned int)((int)((unsigned int)v1053 >> 2)) >> 1)) * 2;
      int v1123 = v1122[v1244];
      int * v1124 = v1049->mem;
      int v1246 = (((int)((unsigned int)((int)((unsigned int)v1053 >> 2)) >> 1)) * 2) + 1;
      int v1125 = v1124[v1246];
      int * v1126 = v1049->cache_vals;
      int v1248 = ((4 + ((((int)((unsigned int)((int)((unsigned int)v1053 >> 2)) >> 1)) & 3) * 2)) + ((((v1100 + ((~(((v1102 ^ -1) | (-(v1102 ^ -1))) >> 31)) & 2)) - (v1104 + ((~(((v1106 ^ -1) | (-(v1106 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
      v1126[v1248] = v1123;
      int * v1128 = v1049->cache_vals;
      int v1251 = (((4 + ((((int)((unsigned int)((int)((unsigned int)v1053 >> 2)) >> 1)) & 3) * 2)) + ((((v1100 + ((~(((v1102 ^ -1) | (-(v1102 ^ -1))) >> 31)) & 2)) - (v1104 + ((~(((v1106 ^ -1) | (-(v1106 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
      v1128[v1251] = v1125;
      int * v1130 = v1049->cache_tags;
      int v1254 = (int)((unsigned int)((int)((unsigned int)v1053 >> 2)) >> 1);
      v1130[v1228] = v1254;
      int * v1132 = v1049->cache_dirty;
      v1132[v1228] = 0;
      int * v1134 = v1049->cache_age;
      v1134[v1228] = 1;
      int * v1136 = v1049->cache_age;
      int v1137 = v1136[v1228];
      int * v1138 = v1049->cache_age;
      int v1139 = v1138[v1191];
      int * v1140 = v1049->cache_age;
      int v1262 = v1139 + ((int)((unsigned int)(v1139 - v1137) >> 31));
      v1140[v1191] = v1262;
      int * v1142 = v1049->cache_age;
      int v1143 = v1142[v1193];
      int * v1144 = v1049->cache_age;
      int v1265 = v1143 + ((int)((unsigned int)(v1143 - v1137) >> 31));
      v1144[v1193] = v1265;
      int * v1146 = v1049->cache_age;
      v1146[v1228] = 0;
      v1149 = v1228;
    }
    int * v1150 = v1049->cache_vals;
    int v1268 = v1149 * 2;
    int v1151 = v1150[v1268];
    int * v1152 = v1049->cache_vals;
    int v1270 = (v1149 * 2) + 1;
    int v1153 = v1152[v1270];
    int * v1154 = v1049->cache_vals;
    int v1272 = (((((int)((unsigned int)((int)((unsigned int)v1053 >> 2)) >> 1)) & 1) * 2) + ((((v1079 + ((~(((v1081 ^ -1) | (-(v1081 ^ -1))) >> 31)) & 2)) - (v1083 + ((~(((v1085 ^ -1) | (-(v1085 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
    v1154[v1272] = v1151;
    int * v1156 = v1049->cache_vals;
    int v1275 = ((((((int)((unsigned int)((int)((unsigned int)v1053 >> 2)) >> 1)) & 1) * 2) + ((((v1079 + ((~(((v1081 ^ -1) | (-(v1081 ^ -1))) >> 31)) & 2)) - (v1083 + ((~(((v1085 ^ -1) | (-(v1085 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
    v1156[v1275] = v1153;
    int * v1158 = v1049->cache_tags;
    int v1278 = ((((int)((unsigned int)((int)((unsigned int)v1053 >> 2)) >> 1)) & 1) * 2) + ((((v1079 + ((~(((v1081 ^ -1) | (-(v1081 ^ -1))) >> 31)) & 2)) - (v1083 + ((~(((v1085 ^ -1) | (-(v1085 ^ -1))) >> 31)) & 2))) >> 31) & 1);
    int v1279 = (int)((unsigned int)((int)((unsigned int)v1053 >> 2)) >> 1);
    v1158[v1278] = v1279;
    int * v1160 = v1049->cache_dirty;
    v1160[v1278] = 0;
    int * v1162 = v1049->cache_age;
    v1162[v1278] = 1;
    int * v1164 = v1049->cache_age;
    int v1165 = v1164[v1278];
    int * v1166 = v1049->cache_age;
    int v1167 = v1166[v1187];
    int * v1168 = v1049->cache_age;
    int v1287 = v1167 + ((int)((unsigned int)(v1167 - v1165) >> 31));
    v1168[v1187] = v1287;
    int * v1170 = v1049->cache_age;
    int v1171 = v1170[v1189];
    int * v1172 = v1049->cache_age;
    int v1290 = v1171 + ((int)((unsigned int)(v1171 - v1165) >> 31));
    v1172[v1189] = v1290;
    int * v1174 = v1049->cache_age;
    v1174[v1278] = 0;
    v1177 = v1278;
  }
  int v1293 = (v1177 * 2) + (((int)((unsigned int)v1053 >> 2)) & 1);
  int v1178 = v1064[v1293];
  int * v1179 = v1049->regs;
  v1179[11] = v1178;
  struct StateT * v1181 = slot_10(v1049);
  return v1181;
}

struct StateT * slot_11(struct StateT * v1299) {
  int v1300 = v1299->timer;
  int v1304 = v1300 + 1;
  v1299->timer = v1304;
  struct StateT * v1302 = slot_12(v1299);
  return v1302;
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
    s1.mem[SECRET_OFFSET+i] = bounded(0, 20);
    s2.mem[SECRET_OFFSET+i] = bounded(0, 20);
  }
  struct StateT *s1_ = snippet(&s1);
  struct StateT *s2_ = snippet(&s2);
  koika_assert(s1_->timer==s2_->timer, "timing leak");
  return 0;
}