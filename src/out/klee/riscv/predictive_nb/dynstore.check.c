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

struct StateT * slot_12(struct StateT * v1271);
struct StateT * slot_14(struct StateT * v1319);
struct StateT * slot_6(struct StateT * v366);
struct StateT * slot_5(struct StateT * v104);
struct StateT * slot_2(struct StateT * v38);
struct StateT * slot_3(struct StateT * v56);
struct StateT * snippet(struct StateT * v0);
struct StateT * slot_10(struct StateT * v1238);
struct StateT * slot_1(struct StateT * v20);
struct StateT * slot_8(struct StateT * v591);
struct StateT * slot_4(struct StateT * v65);
struct StateT * slot_13(struct StateT * v1280);
struct StateT * slot_15(struct StateT * v1581);
struct StateT * slot_9(struct StateT * v983);
struct StateT * slot_11(struct StateT * v1262);
struct StateT * slot_0(struct StateT * v2);
struct StateT * slot_12(struct StateT * v1271) {
  int v1272 = v1271->timer;
  int v1273 = v1271->timer;
  int v1277 = v1273 + 1;
  v1271->timer = v1277;
  struct StateT * v1275 = slot_13(v1271);
  return v1275;
}

struct StateT * slot_14(struct StateT * v1319) {
  int * v1320 = v1319->saved_regs;
  int * v1321 = v1319->regs;
  int v1322 = v1321[5];
  v1320[5] = v1322;
  int v1324 = v1319->timer;
  int v1325 = v1319->timer;
  int v1464 = v1325 + 1;
  v1319->timer = v1464;
  int * v1327 = v1319->reg_ready;
  int v1328 = v1327[8];
  int * v1329 = v1319->regs;
  int v1330 = v1329[8];
  int * v1331 = v1319->cache_tags;
  int v1469 = (((int)((unsigned int)((int)((unsigned int)v1330 >> 2)) >> 1)) & 1) * 2;
  int v1332 = v1331[v1469];
  int * v1333 = v1319->cache_tags;
  int v1471 = ((((int)((unsigned int)((int)((unsigned int)v1330 >> 2)) >> 1)) & 1) * 2) + 1;
  int v1334 = v1333[v1471];
  int * v1335 = v1319->cache_tags;
  int v1473 = 4 + ((((int)((unsigned int)((int)((unsigned int)v1330 >> 2)) >> 1)) & 3) * 2);
  int v1336 = v1335[v1473];
  int * v1337 = v1319->cache_tags;
  int v1475 = (4 + ((((int)((unsigned int)((int)((unsigned int)v1330 >> 2)) >> 1)) & 3) * 2)) + 1;
  int v1338 = v1337[v1475];
  int * v1339 = v1319->cache_vals;
  bool v1476 = !(((~(((v1332 ^ ((int)((unsigned int)((int)((unsigned int)v1330 >> 2)) >> 1))) | (-(v1332 ^ ((int)((unsigned int)((int)((unsigned int)v1330 >> 2)) >> 1))))) >> 31)) | (~(((v1334 ^ ((int)((unsigned int)((int)((unsigned int)v1330 >> 2)) >> 1))) | (-(v1334 ^ ((int)((unsigned int)((int)((unsigned int)v1330 >> 2)) >> 1))))) >> 31))) == 0);
  int v1452;
  if (v1476) {
    int * v1340 = v1319->cache_age;
    int v1478 = ((((int)((unsigned int)((int)((unsigned int)v1330 >> 2)) >> 1)) & 1) * 2) + ((~(((v1334 ^ ((int)((unsigned int)((int)((unsigned int)v1330 >> 2)) >> 1))) | (-(v1334 ^ ((int)((unsigned int)((int)((unsigned int)v1330 >> 2)) >> 1))))) >> 31)) & 1);
    int v1341 = v1340[v1478];
    int * v1342 = v1319->cache_age;
    int v1343 = v1342[v1469];
    int * v1344 = v1319->cache_age;
    int v1481 = v1343 + ((int)((unsigned int)(v1343 - v1341) >> 31));
    v1344[v1469] = v1481;
    int * v1346 = v1319->cache_age;
    int v1347 = v1346[v1471];
    int * v1348 = v1319->cache_age;
    int v1484 = v1347 + ((int)((unsigned int)(v1347 - v1341) >> 31));
    v1348[v1471] = v1484;
    int * v1350 = v1319->cache_age;
    v1350[v1478] = 0;
    v1452 = v1478;
  } else {
    int * v1353 = v1319->cache_age;
    int v1488 = (((int)((unsigned int)((int)((unsigned int)v1330 >> 2)) >> 1)) & 1) * 2;
    int v1354 = v1353[v1488];
    int * v1355 = v1319->cache_tags;
    int v1356 = v1355[v1488];
    int * v1357 = v1319->cache_age;
    int v1358 = v1357[v1471];
    int * v1359 = v1319->cache_tags;
    int v1360 = v1359[v1471];
    bool v1492 = !(((~(((v1336 ^ ((int)((unsigned int)((int)((unsigned int)v1330 >> 2)) >> 1))) | (-(v1336 ^ ((int)((unsigned int)((int)((unsigned int)v1330 >> 2)) >> 1))))) >> 31)) | (~(((v1338 ^ ((int)((unsigned int)((int)((unsigned int)v1330 >> 2)) >> 1))) | (-(v1338 ^ ((int)((unsigned int)((int)((unsigned int)v1330 >> 2)) >> 1))))) >> 31))) == 0);
    int v1424;
    if (v1492) {
      int * v1361 = v1319->cache_age;
      int v1494 = (4 + ((((int)((unsigned int)((int)((unsigned int)v1330 >> 2)) >> 1)) & 3) * 2)) + ((~(((v1338 ^ ((int)((unsigned int)((int)((unsigned int)v1330 >> 2)) >> 1))) | (-(v1338 ^ ((int)((unsigned int)((int)((unsigned int)v1330 >> 2)) >> 1))))) >> 31)) & 1);
      int v1362 = v1361[v1494];
      int * v1363 = v1319->cache_age;
      int v1364 = v1363[v1473];
      int * v1365 = v1319->cache_age;
      int v1497 = v1364 + ((int)((unsigned int)(v1364 - v1362) >> 31));
      v1365[v1473] = v1497;
      int * v1367 = v1319->cache_age;
      int v1368 = v1367[v1475];
      int * v1369 = v1319->cache_age;
      int v1500 = v1368 + ((int)((unsigned int)(v1368 - v1362) >> 31));
      v1369[v1475] = v1500;
      int * v1371 = v1319->cache_age;
      v1371[v1494] = 0;
      v1424 = v1494;
    } else {
      int * v1374 = v1319->cache_age;
      int v1504 = 4 + ((((int)((unsigned int)((int)((unsigned int)v1330 >> 2)) >> 1)) & 3) * 2);
      int v1375 = v1374[v1504];
      int * v1376 = v1319->cache_tags;
      int v1377 = v1376[v1504];
      int * v1378 = v1319->cache_age;
      int v1379 = v1378[v1475];
      int * v1380 = v1319->cache_tags;
      int v1381 = v1380[v1475];
      int * v1382 = v1319->cache_dirty;
      int v1509 = (4 + ((((int)((unsigned int)((int)((unsigned int)v1330 >> 2)) >> 1)) & 3) * 2)) + ((((v1375 + ((~(((v1377 ^ -1) | (-(v1377 ^ -1))) >> 31)) & 2)) - (v1379 + ((~(((v1381 ^ -1) | (-(v1381 ^ -1))) >> 31)) & 2))) >> 31) & 1);
      int v1383 = v1382[v1509];
      bool v1510 = !(v1383 == 0);
      if (v1510) {
        int * v1384 = v1319->cache_tags;
        int v1385 = v1384[v1509];
        int * v1386 = v1319->cache_vals;
        int v1513 = ((4 + ((((int)((unsigned int)((int)((unsigned int)v1330 >> 2)) >> 1)) & 3) * 2)) + ((((v1375 + ((~(((v1377 ^ -1) | (-(v1377 ^ -1))) >> 31)) & 2)) - (v1379 + ((~(((v1381 ^ -1) | (-(v1381 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
        int v1387 = v1386[v1513];
        int * v1388 = v1319->cache_vals;
        int v1515 = (((4 + ((((int)((unsigned int)((int)((unsigned int)v1330 >> 2)) >> 1)) & 3) * 2)) + ((((v1375 + ((~(((v1377 ^ -1) | (-(v1377 ^ -1))) >> 31)) & 2)) - (v1379 + ((~(((v1381 ^ -1) | (-(v1381 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
        int v1389 = v1388[v1515];
        int * v1390 = v1319->mem;
        int v1517 = v1385 * 2;
        v1390[v1517] = v1387;
        int * v1392 = v1319->mem;
        int v1520 = (v1385 * 2) + 1;
        v1392[v1520] = v1389;
        ;
      } else {
        ;
      }
      int * v1397 = v1319->mem;
      int v1525 = ((int)((unsigned int)((int)((unsigned int)v1330 >> 2)) >> 1)) * 2;
      int v1398 = v1397[v1525];
      int * v1399 = v1319->mem;
      int v1527 = (((int)((unsigned int)((int)((unsigned int)v1330 >> 2)) >> 1)) * 2) + 1;
      int v1400 = v1399[v1527];
      int * v1401 = v1319->cache_vals;
      int v1529 = ((4 + ((((int)((unsigned int)((int)((unsigned int)v1330 >> 2)) >> 1)) & 3) * 2)) + ((((v1375 + ((~(((v1377 ^ -1) | (-(v1377 ^ -1))) >> 31)) & 2)) - (v1379 + ((~(((v1381 ^ -1) | (-(v1381 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
      v1401[v1529] = v1398;
      int * v1403 = v1319->cache_vals;
      int v1532 = (((4 + ((((int)((unsigned int)((int)((unsigned int)v1330 >> 2)) >> 1)) & 3) * 2)) + ((((v1375 + ((~(((v1377 ^ -1) | (-(v1377 ^ -1))) >> 31)) & 2)) - (v1379 + ((~(((v1381 ^ -1) | (-(v1381 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
      v1403[v1532] = v1400;
      int * v1405 = v1319->cache_tags;
      int v1535 = (int)((unsigned int)((int)((unsigned int)v1330 >> 2)) >> 1);
      v1405[v1509] = v1535;
      int * v1407 = v1319->cache_dirty;
      v1407[v1509] = 0;
      int * v1409 = v1319->cache_age;
      v1409[v1509] = 1;
      int * v1411 = v1319->cache_age;
      int v1412 = v1411[v1509];
      int * v1413 = v1319->cache_age;
      int v1414 = v1413[v1473];
      int * v1415 = v1319->cache_age;
      int v1543 = v1414 + ((int)((unsigned int)(v1414 - v1412) >> 31));
      v1415[v1473] = v1543;
      int * v1417 = v1319->cache_age;
      int v1418 = v1417[v1475];
      int * v1419 = v1319->cache_age;
      int v1546 = v1418 + ((int)((unsigned int)(v1418 - v1412) >> 31));
      v1419[v1475] = v1546;
      int * v1421 = v1319->cache_age;
      v1421[v1509] = 0;
      v1424 = v1509;
    }
    int * v1425 = v1319->cache_vals;
    int v1549 = v1424 * 2;
    int v1426 = v1425[v1549];
    int * v1427 = v1319->cache_vals;
    int v1551 = (v1424 * 2) + 1;
    int v1428 = v1427[v1551];
    int * v1429 = v1319->cache_vals;
    int v1553 = (((((int)((unsigned int)((int)((unsigned int)v1330 >> 2)) >> 1)) & 1) * 2) + ((((v1354 + ((~(((v1356 ^ -1) | (-(v1356 ^ -1))) >> 31)) & 2)) - (v1358 + ((~(((v1360 ^ -1) | (-(v1360 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
    v1429[v1553] = v1426;
    int * v1431 = v1319->cache_vals;
    int v1556 = ((((((int)((unsigned int)((int)((unsigned int)v1330 >> 2)) >> 1)) & 1) * 2) + ((((v1354 + ((~(((v1356 ^ -1) | (-(v1356 ^ -1))) >> 31)) & 2)) - (v1358 + ((~(((v1360 ^ -1) | (-(v1360 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
    v1431[v1556] = v1428;
    int * v1433 = v1319->cache_tags;
    int v1559 = ((((int)((unsigned int)((int)((unsigned int)v1330 >> 2)) >> 1)) & 1) * 2) + ((((v1354 + ((~(((v1356 ^ -1) | (-(v1356 ^ -1))) >> 31)) & 2)) - (v1358 + ((~(((v1360 ^ -1) | (-(v1360 ^ -1))) >> 31)) & 2))) >> 31) & 1);
    int v1560 = (int)((unsigned int)((int)((unsigned int)v1330 >> 2)) >> 1);
    v1433[v1559] = v1560;
    int * v1435 = v1319->cache_dirty;
    v1435[v1559] = 0;
    int * v1437 = v1319->cache_age;
    v1437[v1559] = 1;
    int * v1439 = v1319->cache_age;
    int v1440 = v1439[v1559];
    int * v1441 = v1319->cache_age;
    int v1442 = v1441[v1469];
    int * v1443 = v1319->cache_age;
    int v1568 = v1442 + ((int)((unsigned int)(v1442 - v1440) >> 31));
    v1443[v1469] = v1568;
    int * v1445 = v1319->cache_age;
    int v1446 = v1445[v1471];
    int * v1447 = v1319->cache_age;
    int v1571 = v1446 + ((int)((unsigned int)(v1446 - v1440) >> 31));
    v1447[v1471] = v1571;
    int * v1449 = v1319->cache_age;
    v1449[v1559] = 0;
    v1452 = v1559;
  }
  int v1574 = (v1452 * 2) + (((int)((unsigned int)v1330 >> 2)) & 1);
  int v1453 = v1339[v1574];
  int * v1454 = v1319->reg_ready;
  int v1576 = ((v1328 + ((v1324 - v1328) & (~((v1324 - v1328) >> 31)))) + 1) + ((100 ^ (((~(((v1336 ^ ((int)((unsigned int)((int)((unsigned int)v1330 >> 2)) >> 1))) | (-(v1336 ^ ((int)((unsigned int)((int)((unsigned int)v1330 >> 2)) >> 1))))) >> 31)) | (~(((v1338 ^ ((int)((unsigned int)((int)((unsigned int)v1330 >> 2)) >> 1))) | (-(v1338 ^ ((int)((unsigned int)((int)((unsigned int)v1330 >> 2)) >> 1))))) >> 31))) & 104)) ^ (((~(((v1332 ^ ((int)((unsigned int)((int)((unsigned int)v1330 >> 2)) >> 1))) | (-(v1332 ^ ((int)((unsigned int)((int)((unsigned int)v1330 >> 2)) >> 1))))) >> 31)) | (~(((v1334 ^ ((int)((unsigned int)((int)((unsigned int)v1330 >> 2)) >> 1))) | (-(v1334 ^ ((int)((unsigned int)((int)((unsigned int)v1330 >> 2)) >> 1))))) >> 31))) & (1 ^ (100 ^ (((~(((v1336 ^ ((int)((unsigned int)((int)((unsigned int)v1330 >> 2)) >> 1))) | (-(v1336 ^ ((int)((unsigned int)((int)((unsigned int)v1330 >> 2)) >> 1))))) >> 31)) | (~(((v1338 ^ ((int)((unsigned int)((int)((unsigned int)v1330 >> 2)) >> 1))) | (-(v1338 ^ ((int)((unsigned int)((int)((unsigned int)v1330 >> 2)) >> 1))))) >> 31))) & 104)))));
  v1454[5] = v1576;
  int * v1456 = v1319->regs;
  v1456[5] = v1453;
  struct StateT * v1458 = slot_15(v1319);
  return v1458;
}

struct StateT * slot_6(struct StateT * v366) {
  int * v367 = v366->regs;
  int v368 = v367[6];
  int * v369 = v366->regs;
  int v370 = v369[7];
  bool v486 = v368 >= v370;
  struct StateT * v480;
  if (v486) {
    int v371 = v366->timer;
    int v487 = v371 + 15;
    v366->timer = v487;
    int * v373 = v366->saved_regs;
    int v374 = v373[8];
    int * v375 = v366->regs;
    v375[8] = v374;
    int * v377 = v366->saved_regs;
    int v378 = v377[5];
    int * v379 = v366->regs;
    v379[5] = v378;
    int * v381 = v366->reg_ready;
    int v382 = v366->timer;
    v381[0] = v382;
    int * v384 = v366->reg_ready;
    int v385 = v366->timer;
    v384[1] = v385;
    int * v387 = v366->reg_ready;
    int v388 = v366->timer;
    v387[2] = v388;
    int * v390 = v366->reg_ready;
    int v391 = v366->timer;
    v390[3] = v391;
    int * v393 = v366->reg_ready;
    int v394 = v366->timer;
    v393[4] = v394;
    int * v396 = v366->reg_ready;
    int v397 = v366->timer;
    v396[5] = v397;
    int * v399 = v366->reg_ready;
    int v400 = v366->timer;
    v399[6] = v400;
    int * v402 = v366->reg_ready;
    int v403 = v366->timer;
    v402[7] = v403;
    int * v405 = v366->reg_ready;
    int v406 = v366->timer;
    v405[8] = v406;
    int * v408 = v366->reg_ready;
    int v409 = v366->timer;
    v408[9] = v409;
    int * v411 = v366->reg_ready;
    int v412 = v366->timer;
    v411[10] = v412;
    int * v414 = v366->reg_ready;
    int v415 = v366->timer;
    v414[11] = v415;
    int * v417 = v366->reg_ready;
    int v418 = v366->timer;
    v417[12] = v418;
    int * v420 = v366->reg_ready;
    int v421 = v366->timer;
    v420[13] = v421;
    int * v423 = v366->reg_ready;
    int v424 = v366->timer;
    v423[14] = v424;
    int * v426 = v366->reg_ready;
    int v427 = v366->timer;
    v426[15] = v427;
    int * v429 = v366->reg_ready;
    int v430 = v366->timer;
    v429[16] = v430;
    int * v432 = v366->reg_ready;
    int v433 = v366->timer;
    v432[17] = v433;
    int * v435 = v366->reg_ready;
    int v436 = v366->timer;
    v435[18] = v436;
    int * v438 = v366->reg_ready;
    int v439 = v366->timer;
    v438[19] = v439;
    int * v441 = v366->reg_ready;
    int v442 = v366->timer;
    v441[20] = v442;
    int * v444 = v366->reg_ready;
    int v445 = v366->timer;
    v444[21] = v445;
    int * v447 = v366->reg_ready;
    int v448 = v366->timer;
    v447[22] = v448;
    int * v450 = v366->reg_ready;
    int v451 = v366->timer;
    v450[23] = v451;
    int * v453 = v366->reg_ready;
    int v454 = v366->timer;
    v453[24] = v454;
    int * v456 = v366->reg_ready;
    int v457 = v366->timer;
    v456[25] = v457;
    int * v459 = v366->reg_ready;
    int v460 = v366->timer;
    v459[26] = v460;
    int * v462 = v366->reg_ready;
    int v463 = v366->timer;
    v462[27] = v463;
    int * v465 = v366->reg_ready;
    int v466 = v366->timer;
    v465[28] = v466;
    int * v468 = v366->reg_ready;
    int v469 = v366->timer;
    v468[29] = v469;
    int * v471 = v366->reg_ready;
    int v472 = v366->timer;
    v471[30] = v472;
    int * v474 = v366->reg_ready;
    int v475 = v366->timer;
    v474[31] = v475;
    v480 = v366;
  } else {
    struct StateT * v478 = slot_8(v366);
    v480 = v478;
  }
  return v480;
}

struct StateT * slot_5(struct StateT * v104) {
  int * v105 = v104->saved_regs;
  int * v106 = v104->regs;
  int v107 = v106[5];
  v105[5] = v107;
  int v109 = v104->timer;
  int v110 = v104->timer;
  int v249 = v110 + 1;
  v104->timer = v249;
  int * v112 = v104->reg_ready;
  int v113 = v112[8];
  int * v114 = v104->regs;
  int v115 = v114[8];
  int * v116 = v104->cache_tags;
  int v254 = (((int)((unsigned int)((int)((unsigned int)v115 >> 2)) >> 1)) & 1) * 2;
  int v117 = v116[v254];
  int * v118 = v104->cache_tags;
  int v256 = ((((int)((unsigned int)((int)((unsigned int)v115 >> 2)) >> 1)) & 1) * 2) + 1;
  int v119 = v118[v256];
  int * v120 = v104->cache_tags;
  int v258 = 4 + ((((int)((unsigned int)((int)((unsigned int)v115 >> 2)) >> 1)) & 3) * 2);
  int v121 = v120[v258];
  int * v122 = v104->cache_tags;
  int v260 = (4 + ((((int)((unsigned int)((int)((unsigned int)v115 >> 2)) >> 1)) & 3) * 2)) + 1;
  int v123 = v122[v260];
  int * v124 = v104->cache_vals;
  bool v261 = !(((~(((v117 ^ ((int)((unsigned int)((int)((unsigned int)v115 >> 2)) >> 1))) | (-(v117 ^ ((int)((unsigned int)((int)((unsigned int)v115 >> 2)) >> 1))))) >> 31)) | (~(((v119 ^ ((int)((unsigned int)((int)((unsigned int)v115 >> 2)) >> 1))) | (-(v119 ^ ((int)((unsigned int)((int)((unsigned int)v115 >> 2)) >> 1))))) >> 31))) == 0);
  int v237;
  if (v261) {
    int * v125 = v104->cache_age;
    int v263 = ((((int)((unsigned int)((int)((unsigned int)v115 >> 2)) >> 1)) & 1) * 2) + ((~(((v119 ^ ((int)((unsigned int)((int)((unsigned int)v115 >> 2)) >> 1))) | (-(v119 ^ ((int)((unsigned int)((int)((unsigned int)v115 >> 2)) >> 1))))) >> 31)) & 1);
    int v126 = v125[v263];
    int * v127 = v104->cache_age;
    int v128 = v127[v254];
    int * v129 = v104->cache_age;
    int v266 = v128 + ((int)((unsigned int)(v128 - v126) >> 31));
    v129[v254] = v266;
    int * v131 = v104->cache_age;
    int v132 = v131[v256];
    int * v133 = v104->cache_age;
    int v269 = v132 + ((int)((unsigned int)(v132 - v126) >> 31));
    v133[v256] = v269;
    int * v135 = v104->cache_age;
    v135[v263] = 0;
    v237 = v263;
  } else {
    int * v138 = v104->cache_age;
    int v273 = (((int)((unsigned int)((int)((unsigned int)v115 >> 2)) >> 1)) & 1) * 2;
    int v139 = v138[v273];
    int * v140 = v104->cache_tags;
    int v141 = v140[v273];
    int * v142 = v104->cache_age;
    int v143 = v142[v256];
    int * v144 = v104->cache_tags;
    int v145 = v144[v256];
    bool v277 = !(((~(((v121 ^ ((int)((unsigned int)((int)((unsigned int)v115 >> 2)) >> 1))) | (-(v121 ^ ((int)((unsigned int)((int)((unsigned int)v115 >> 2)) >> 1))))) >> 31)) | (~(((v123 ^ ((int)((unsigned int)((int)((unsigned int)v115 >> 2)) >> 1))) | (-(v123 ^ ((int)((unsigned int)((int)((unsigned int)v115 >> 2)) >> 1))))) >> 31))) == 0);
    int v209;
    if (v277) {
      int * v146 = v104->cache_age;
      int v279 = (4 + ((((int)((unsigned int)((int)((unsigned int)v115 >> 2)) >> 1)) & 3) * 2)) + ((~(((v123 ^ ((int)((unsigned int)((int)((unsigned int)v115 >> 2)) >> 1))) | (-(v123 ^ ((int)((unsigned int)((int)((unsigned int)v115 >> 2)) >> 1))))) >> 31)) & 1);
      int v147 = v146[v279];
      int * v148 = v104->cache_age;
      int v149 = v148[v258];
      int * v150 = v104->cache_age;
      int v282 = v149 + ((int)((unsigned int)(v149 - v147) >> 31));
      v150[v258] = v282;
      int * v152 = v104->cache_age;
      int v153 = v152[v260];
      int * v154 = v104->cache_age;
      int v285 = v153 + ((int)((unsigned int)(v153 - v147) >> 31));
      v154[v260] = v285;
      int * v156 = v104->cache_age;
      v156[v279] = 0;
      v209 = v279;
    } else {
      int * v159 = v104->cache_age;
      int v289 = 4 + ((((int)((unsigned int)((int)((unsigned int)v115 >> 2)) >> 1)) & 3) * 2);
      int v160 = v159[v289];
      int * v161 = v104->cache_tags;
      int v162 = v161[v289];
      int * v163 = v104->cache_age;
      int v164 = v163[v260];
      int * v165 = v104->cache_tags;
      int v166 = v165[v260];
      int * v167 = v104->cache_dirty;
      int v294 = (4 + ((((int)((unsigned int)((int)((unsigned int)v115 >> 2)) >> 1)) & 3) * 2)) + ((((v160 + ((~(((v162 ^ -1) | (-(v162 ^ -1))) >> 31)) & 2)) - (v164 + ((~(((v166 ^ -1) | (-(v166 ^ -1))) >> 31)) & 2))) >> 31) & 1);
      int v168 = v167[v294];
      bool v295 = !(v168 == 0);
      if (v295) {
        int * v169 = v104->cache_tags;
        int v170 = v169[v294];
        int * v171 = v104->cache_vals;
        int v298 = ((4 + ((((int)((unsigned int)((int)((unsigned int)v115 >> 2)) >> 1)) & 3) * 2)) + ((((v160 + ((~(((v162 ^ -1) | (-(v162 ^ -1))) >> 31)) & 2)) - (v164 + ((~(((v166 ^ -1) | (-(v166 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
        int v172 = v171[v298];
        int * v173 = v104->cache_vals;
        int v300 = (((4 + ((((int)((unsigned int)((int)((unsigned int)v115 >> 2)) >> 1)) & 3) * 2)) + ((((v160 + ((~(((v162 ^ -1) | (-(v162 ^ -1))) >> 31)) & 2)) - (v164 + ((~(((v166 ^ -1) | (-(v166 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
        int v174 = v173[v300];
        int * v175 = v104->mem;
        int v302 = v170 * 2;
        v175[v302] = v172;
        int * v177 = v104->mem;
        int v305 = (v170 * 2) + 1;
        v177[v305] = v174;
        ;
      } else {
        ;
      }
      int * v182 = v104->mem;
      int v310 = ((int)((unsigned int)((int)((unsigned int)v115 >> 2)) >> 1)) * 2;
      int v183 = v182[v310];
      int * v184 = v104->mem;
      int v312 = (((int)((unsigned int)((int)((unsigned int)v115 >> 2)) >> 1)) * 2) + 1;
      int v185 = v184[v312];
      int * v186 = v104->cache_vals;
      int v314 = ((4 + ((((int)((unsigned int)((int)((unsigned int)v115 >> 2)) >> 1)) & 3) * 2)) + ((((v160 + ((~(((v162 ^ -1) | (-(v162 ^ -1))) >> 31)) & 2)) - (v164 + ((~(((v166 ^ -1) | (-(v166 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
      v186[v314] = v183;
      int * v188 = v104->cache_vals;
      int v317 = (((4 + ((((int)((unsigned int)((int)((unsigned int)v115 >> 2)) >> 1)) & 3) * 2)) + ((((v160 + ((~(((v162 ^ -1) | (-(v162 ^ -1))) >> 31)) & 2)) - (v164 + ((~(((v166 ^ -1) | (-(v166 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
      v188[v317] = v185;
      int * v190 = v104->cache_tags;
      int v320 = (int)((unsigned int)((int)((unsigned int)v115 >> 2)) >> 1);
      v190[v294] = v320;
      int * v192 = v104->cache_dirty;
      v192[v294] = 0;
      int * v194 = v104->cache_age;
      v194[v294] = 1;
      int * v196 = v104->cache_age;
      int v197 = v196[v294];
      int * v198 = v104->cache_age;
      int v199 = v198[v258];
      int * v200 = v104->cache_age;
      int v328 = v199 + ((int)((unsigned int)(v199 - v197) >> 31));
      v200[v258] = v328;
      int * v202 = v104->cache_age;
      int v203 = v202[v260];
      int * v204 = v104->cache_age;
      int v331 = v203 + ((int)((unsigned int)(v203 - v197) >> 31));
      v204[v260] = v331;
      int * v206 = v104->cache_age;
      v206[v294] = 0;
      v209 = v294;
    }
    int * v210 = v104->cache_vals;
    int v334 = v209 * 2;
    int v211 = v210[v334];
    int * v212 = v104->cache_vals;
    int v336 = (v209 * 2) + 1;
    int v213 = v212[v336];
    int * v214 = v104->cache_vals;
    int v338 = (((((int)((unsigned int)((int)((unsigned int)v115 >> 2)) >> 1)) & 1) * 2) + ((((v139 + ((~(((v141 ^ -1) | (-(v141 ^ -1))) >> 31)) & 2)) - (v143 + ((~(((v145 ^ -1) | (-(v145 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
    v214[v338] = v211;
    int * v216 = v104->cache_vals;
    int v341 = ((((((int)((unsigned int)((int)((unsigned int)v115 >> 2)) >> 1)) & 1) * 2) + ((((v139 + ((~(((v141 ^ -1) | (-(v141 ^ -1))) >> 31)) & 2)) - (v143 + ((~(((v145 ^ -1) | (-(v145 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
    v216[v341] = v213;
    int * v218 = v104->cache_tags;
    int v344 = ((((int)((unsigned int)((int)((unsigned int)v115 >> 2)) >> 1)) & 1) * 2) + ((((v139 + ((~(((v141 ^ -1) | (-(v141 ^ -1))) >> 31)) & 2)) - (v143 + ((~(((v145 ^ -1) | (-(v145 ^ -1))) >> 31)) & 2))) >> 31) & 1);
    int v345 = (int)((unsigned int)((int)((unsigned int)v115 >> 2)) >> 1);
    v218[v344] = v345;
    int * v220 = v104->cache_dirty;
    v220[v344] = 0;
    int * v222 = v104->cache_age;
    v222[v344] = 1;
    int * v224 = v104->cache_age;
    int v225 = v224[v344];
    int * v226 = v104->cache_age;
    int v227 = v226[v254];
    int * v228 = v104->cache_age;
    int v353 = v227 + ((int)((unsigned int)(v227 - v225) >> 31));
    v228[v254] = v353;
    int * v230 = v104->cache_age;
    int v231 = v230[v256];
    int * v232 = v104->cache_age;
    int v356 = v231 + ((int)((unsigned int)(v231 - v225) >> 31));
    v232[v256] = v356;
    int * v234 = v104->cache_age;
    v234[v344] = 0;
    v237 = v344;
  }
  int v359 = (v237 * 2) + (((int)((unsigned int)v115 >> 2)) & 1);
  int v238 = v124[v359];
  int * v239 = v104->reg_ready;
  int v361 = ((v113 + ((v109 - v113) & (~((v109 - v113) >> 31)))) + 1) + ((100 ^ (((~(((v121 ^ ((int)((unsigned int)((int)((unsigned int)v115 >> 2)) >> 1))) | (-(v121 ^ ((int)((unsigned int)((int)((unsigned int)v115 >> 2)) >> 1))))) >> 31)) | (~(((v123 ^ ((int)((unsigned int)((int)((unsigned int)v115 >> 2)) >> 1))) | (-(v123 ^ ((int)((unsigned int)((int)((unsigned int)v115 >> 2)) >> 1))))) >> 31))) & 104)) ^ (((~(((v117 ^ ((int)((unsigned int)((int)((unsigned int)v115 >> 2)) >> 1))) | (-(v117 ^ ((int)((unsigned int)((int)((unsigned int)v115 >> 2)) >> 1))))) >> 31)) | (~(((v119 ^ ((int)((unsigned int)((int)((unsigned int)v115 >> 2)) >> 1))) | (-(v119 ^ ((int)((unsigned int)((int)((unsigned int)v115 >> 2)) >> 1))))) >> 31))) & (1 ^ (100 ^ (((~(((v121 ^ ((int)((unsigned int)((int)((unsigned int)v115 >> 2)) >> 1))) | (-(v121 ^ ((int)((unsigned int)((int)((unsigned int)v115 >> 2)) >> 1))))) >> 31)) | (~(((v123 ^ ((int)((unsigned int)((int)((unsigned int)v115 >> 2)) >> 1))) | (-(v123 ^ ((int)((unsigned int)((int)((unsigned int)v115 >> 2)) >> 1))))) >> 31))) & 104)))));
  v239[5] = v361;
  int * v241 = v104->regs;
  v241[5] = v238;
  struct StateT * v243 = slot_6(v104);
  return v243;
}

struct StateT * slot_2(struct StateT * v38) {
  int v39 = v38->timer;
  int v40 = v38->timer;
  int v48 = v40 + 1;
  v38->timer = v48;
  int * v42 = v38->reg_ready;
  int v51 = v39 + 1;
  v42[9] = v51;
  int * v44 = v38->regs;
  v44[9] = 80;
  struct StateT * v46 = slot_3(v38);
  return v46;
}

struct StateT * slot_3(struct StateT * v56) {
  int v57 = v56->timer;
  int v58 = v56->timer;
  int v62 = v58 + 1;
  v56->timer = v62;
  struct StateT * v60 = slot_4(v56);
  return v60;
}

struct StateT * snippet(struct StateT * v0) {
  struct StateT * v1 = slot_0(v0);
  int v1806 = v1->timer;
  int * v1807 = v1->reg_ready;
  int v1808 = v1807[0];
  int v1939 = v1808 + ((v1806 - v1808) & (~((v1806 - v1808) >> 31)));
  v1->timer = v1939;
  int v1810 = v1->timer;
  int * v1811 = v1->reg_ready;
  int v1812 = v1811[1];
  int v1942 = v1812 + ((v1810 - v1812) & (~((v1810 - v1812) >> 31)));
  v1->timer = v1942;
  int v1814 = v1->timer;
  int * v1815 = v1->reg_ready;
  int v1816 = v1815[2];
  int v1945 = v1816 + ((v1814 - v1816) & (~((v1814 - v1816) >> 31)));
  v1->timer = v1945;
  int v1818 = v1->timer;
  int * v1819 = v1->reg_ready;
  int v1820 = v1819[3];
  int v1948 = v1820 + ((v1818 - v1820) & (~((v1818 - v1820) >> 31)));
  v1->timer = v1948;
  int v1822 = v1->timer;
  int * v1823 = v1->reg_ready;
  int v1824 = v1823[4];
  int v1951 = v1824 + ((v1822 - v1824) & (~((v1822 - v1824) >> 31)));
  v1->timer = v1951;
  int v1826 = v1->timer;
  int * v1827 = v1->reg_ready;
  int v1828 = v1827[5];
  int v1954 = v1828 + ((v1826 - v1828) & (~((v1826 - v1828) >> 31)));
  v1->timer = v1954;
  int v1830 = v1->timer;
  int * v1831 = v1->reg_ready;
  int v1832 = v1831[6];
  int v1957 = v1832 + ((v1830 - v1832) & (~((v1830 - v1832) >> 31)));
  v1->timer = v1957;
  int v1834 = v1->timer;
  int * v1835 = v1->reg_ready;
  int v1836 = v1835[7];
  int v1960 = v1836 + ((v1834 - v1836) & (~((v1834 - v1836) >> 31)));
  v1->timer = v1960;
  int v1838 = v1->timer;
  int * v1839 = v1->reg_ready;
  int v1840 = v1839[8];
  int v1963 = v1840 + ((v1838 - v1840) & (~((v1838 - v1840) >> 31)));
  v1->timer = v1963;
  int v1842 = v1->timer;
  int * v1843 = v1->reg_ready;
  int v1844 = v1843[9];
  int v1966 = v1844 + ((v1842 - v1844) & (~((v1842 - v1844) >> 31)));
  v1->timer = v1966;
  int v1846 = v1->timer;
  int * v1847 = v1->reg_ready;
  int v1848 = v1847[10];
  int v1969 = v1848 + ((v1846 - v1848) & (~((v1846 - v1848) >> 31)));
  v1->timer = v1969;
  int v1850 = v1->timer;
  int * v1851 = v1->reg_ready;
  int v1852 = v1851[11];
  int v1972 = v1852 + ((v1850 - v1852) & (~((v1850 - v1852) >> 31)));
  v1->timer = v1972;
  int v1854 = v1->timer;
  int * v1855 = v1->reg_ready;
  int v1856 = v1855[12];
  int v1975 = v1856 + ((v1854 - v1856) & (~((v1854 - v1856) >> 31)));
  v1->timer = v1975;
  int v1858 = v1->timer;
  int * v1859 = v1->reg_ready;
  int v1860 = v1859[13];
  int v1978 = v1860 + ((v1858 - v1860) & (~((v1858 - v1860) >> 31)));
  v1->timer = v1978;
  int v1862 = v1->timer;
  int * v1863 = v1->reg_ready;
  int v1864 = v1863[14];
  int v1981 = v1864 + ((v1862 - v1864) & (~((v1862 - v1864) >> 31)));
  v1->timer = v1981;
  int v1866 = v1->timer;
  int * v1867 = v1->reg_ready;
  int v1868 = v1867[15];
  int v1984 = v1868 + ((v1866 - v1868) & (~((v1866 - v1868) >> 31)));
  v1->timer = v1984;
  int v1870 = v1->timer;
  int * v1871 = v1->reg_ready;
  int v1872 = v1871[16];
  int v1987 = v1872 + ((v1870 - v1872) & (~((v1870 - v1872) >> 31)));
  v1->timer = v1987;
  int v1874 = v1->timer;
  int * v1875 = v1->reg_ready;
  int v1876 = v1875[17];
  int v1990 = v1876 + ((v1874 - v1876) & (~((v1874 - v1876) >> 31)));
  v1->timer = v1990;
  int v1878 = v1->timer;
  int * v1879 = v1->reg_ready;
  int v1880 = v1879[18];
  int v1993 = v1880 + ((v1878 - v1880) & (~((v1878 - v1880) >> 31)));
  v1->timer = v1993;
  int v1882 = v1->timer;
  int * v1883 = v1->reg_ready;
  int v1884 = v1883[19];
  int v1996 = v1884 + ((v1882 - v1884) & (~((v1882 - v1884) >> 31)));
  v1->timer = v1996;
  int v1886 = v1->timer;
  int * v1887 = v1->reg_ready;
  int v1888 = v1887[20];
  int v1999 = v1888 + ((v1886 - v1888) & (~((v1886 - v1888) >> 31)));
  v1->timer = v1999;
  int v1890 = v1->timer;
  int * v1891 = v1->reg_ready;
  int v1892 = v1891[21];
  int v2002 = v1892 + ((v1890 - v1892) & (~((v1890 - v1892) >> 31)));
  v1->timer = v2002;
  int v1894 = v1->timer;
  int * v1895 = v1->reg_ready;
  int v1896 = v1895[22];
  int v2005 = v1896 + ((v1894 - v1896) & (~((v1894 - v1896) >> 31)));
  v1->timer = v2005;
  int v1898 = v1->timer;
  int * v1899 = v1->reg_ready;
  int v1900 = v1899[23];
  int v2008 = v1900 + ((v1898 - v1900) & (~((v1898 - v1900) >> 31)));
  v1->timer = v2008;
  int v1902 = v1->timer;
  int * v1903 = v1->reg_ready;
  int v1904 = v1903[24];
  int v2011 = v1904 + ((v1902 - v1904) & (~((v1902 - v1904) >> 31)));
  v1->timer = v2011;
  int v1906 = v1->timer;
  int * v1907 = v1->reg_ready;
  int v1908 = v1907[25];
  int v2014 = v1908 + ((v1906 - v1908) & (~((v1906 - v1908) >> 31)));
  v1->timer = v2014;
  int v1910 = v1->timer;
  int * v1911 = v1->reg_ready;
  int v1912 = v1911[26];
  int v2017 = v1912 + ((v1910 - v1912) & (~((v1910 - v1912) >> 31)));
  v1->timer = v2017;
  int v1914 = v1->timer;
  int * v1915 = v1->reg_ready;
  int v1916 = v1915[27];
  int v2020 = v1916 + ((v1914 - v1916) & (~((v1914 - v1916) >> 31)));
  v1->timer = v2020;
  int v1918 = v1->timer;
  int * v1919 = v1->reg_ready;
  int v1920 = v1919[28];
  int v2023 = v1920 + ((v1918 - v1920) & (~((v1918 - v1920) >> 31)));
  v1->timer = v2023;
  int v1922 = v1->timer;
  int * v1923 = v1->reg_ready;
  int v1924 = v1923[29];
  int v2026 = v1924 + ((v1922 - v1924) & (~((v1922 - v1924) >> 31)));
  v1->timer = v2026;
  int v1926 = v1->timer;
  int * v1927 = v1->reg_ready;
  int v1928 = v1927[30];
  int v2029 = v1928 + ((v1926 - v1928) & (~((v1926 - v1928) >> 31)));
  v1->timer = v2029;
  int v1930 = v1->timer;
  int * v1931 = v1->reg_ready;
  int v1932 = v1931[31];
  int v2032 = v1932 + ((v1930 - v1932) & (~((v1930 - v1932) >> 31)));
  v1->timer = v2032;
  return v1;
}

struct StateT * slot_10(struct StateT * v1238) {
  int v1239 = v1238->timer;
  int v1240 = v1238->timer;
  int v1252 = v1240 + 1;
  v1238->timer = v1252;
  int * v1242 = v1238->reg_ready;
  int v1243 = v1242[6];
  int * v1244 = v1238->regs;
  int v1245 = v1244[6];
  int * v1246 = v1238->reg_ready;
  int v1257 = (v1243 + ((v1239 - v1243) & (~((v1239 - v1243) >> 31)))) + 1;
  v1246[6] = v1257;
  int * v1248 = v1238->regs;
  int v1259 = v1245 + 4;
  v1248[6] = v1259;
  struct StateT * v1250 = slot_11(v1238);
  return v1250;
}

struct StateT * slot_1(struct StateT * v20) {
  int v21 = v20->timer;
  int v22 = v20->timer;
  int v30 = v22 + 1;
  v20->timer = v30;
  int * v24 = v20->reg_ready;
  int v33 = v21 + 1;
  v24[7] = v33;
  int * v26 = v20->regs;
  v26[7] = 16;
  struct StateT * v28 = slot_2(v20);
  return v28;
}

struct StateT * slot_8(struct StateT * v591) {
  int v592 = v591->timer;
  int v593 = v591->timer;
  int v802 = v593 + 1;
  v591->timer = v802;
  int * v595 = v591->reg_ready;
  int v596 = v595[6];
  int * v597 = v591->regs;
  int v598 = v597[6];
  int * v599 = v591->reg_ready;
  int v600 = v599[5];
  int * v601 = v591->regs;
  int v602 = v601[5];
  int * v603 = v591->cache_tags;
  int v810 = (((int)((unsigned int)((int)((unsigned int)v598 >> 2)) >> 1)) & 1) * 2;
  int v604 = v603[v810];
  int * v605 = v591->cache_tags;
  int v812 = ((((int)((unsigned int)((int)((unsigned int)v598 >> 2)) >> 1)) & 1) * 2) + 1;
  int v606 = v605[v812];
  int * v607 = v591->cache_tags;
  int v814 = 4 + ((((int)((unsigned int)((int)((unsigned int)v598 >> 2)) >> 1)) & 3) * 2);
  int v608 = v607[v814];
  int * v609 = v591->cache_tags;
  int v816 = (4 + ((((int)((unsigned int)((int)((unsigned int)v598 >> 2)) >> 1)) & 3) * 2)) + 1;
  int v610 = v609[v816];
  int v611 = v591->timer;
  int v817 = v611 + ((100 ^ (((~(((v608 ^ ((int)((unsigned int)((int)((unsigned int)v598 >> 2)) >> 1))) | (-(v608 ^ ((int)((unsigned int)((int)((unsigned int)v598 >> 2)) >> 1))))) >> 31)) | (~(((v610 ^ ((int)((unsigned int)((int)((unsigned int)v598 >> 2)) >> 1))) | (-(v610 ^ ((int)((unsigned int)((int)((unsigned int)v598 >> 2)) >> 1))))) >> 31))) & 104)) ^ (((~(((v604 ^ ((int)((unsigned int)((int)((unsigned int)v598 >> 2)) >> 1))) | (-(v604 ^ ((int)((unsigned int)((int)((unsigned int)v598 >> 2)) >> 1))))) >> 31)) | (~(((v606 ^ ((int)((unsigned int)((int)((unsigned int)v598 >> 2)) >> 1))) | (-(v606 ^ ((int)((unsigned int)((int)((unsigned int)v598 >> 2)) >> 1))))) >> 31))) & (1 ^ (100 ^ (((~(((v608 ^ ((int)((unsigned int)((int)((unsigned int)v598 >> 2)) >> 1))) | (-(v608 ^ ((int)((unsigned int)((int)((unsigned int)v598 >> 2)) >> 1))))) >> 31)) | (~(((v610 ^ ((int)((unsigned int)((int)((unsigned int)v598 >> 2)) >> 1))) | (-(v610 ^ ((int)((unsigned int)((int)((unsigned int)v598 >> 2)) >> 1))))) >> 31))) & 104)))));
  v591->timer = v817;
  bool v818 = !(((~(((v604 ^ ((int)((unsigned int)((int)((unsigned int)v598 >> 2)) >> 1))) | (-(v604 ^ ((int)((unsigned int)((int)((unsigned int)v598 >> 2)) >> 1))))) >> 31)) | (~(((v606 ^ ((int)((unsigned int)((int)((unsigned int)v598 >> 2)) >> 1))) | (-(v606 ^ ((int)((unsigned int)((int)((unsigned int)v598 >> 2)) >> 1))))) >> 31))) == 0);
  int v725;
  if (v818) {
    int * v613 = v591->cache_age;
    int v820 = ((((int)((unsigned int)((int)((unsigned int)v598 >> 2)) >> 1)) & 1) * 2) + ((~(((v606 ^ ((int)((unsigned int)((int)((unsigned int)v598 >> 2)) >> 1))) | (-(v606 ^ ((int)((unsigned int)((int)((unsigned int)v598 >> 2)) >> 1))))) >> 31)) & 1);
    int v614 = v613[v820];
    int * v615 = v591->cache_age;
    int v616 = v615[v810];
    int * v617 = v591->cache_age;
    int v823 = v616 + ((int)((unsigned int)(v616 - v614) >> 31));
    v617[v810] = v823;
    int * v619 = v591->cache_age;
    int v620 = v619[v812];
    int * v621 = v591->cache_age;
    int v826 = v620 + ((int)((unsigned int)(v620 - v614) >> 31));
    v621[v812] = v826;
    int * v623 = v591->cache_age;
    v623[v820] = 0;
    v725 = v820;
  } else {
    int * v626 = v591->cache_age;
    int v830 = (((int)((unsigned int)((int)((unsigned int)v598 >> 2)) >> 1)) & 1) * 2;
    int v627 = v626[v830];
    int * v628 = v591->cache_tags;
    int v629 = v628[v830];
    int * v630 = v591->cache_age;
    int v631 = v630[v812];
    int * v632 = v591->cache_tags;
    int v633 = v632[v812];
    bool v834 = !(((~(((v608 ^ ((int)((unsigned int)((int)((unsigned int)v598 >> 2)) >> 1))) | (-(v608 ^ ((int)((unsigned int)((int)((unsigned int)v598 >> 2)) >> 1))))) >> 31)) | (~(((v610 ^ ((int)((unsigned int)((int)((unsigned int)v598 >> 2)) >> 1))) | (-(v610 ^ ((int)((unsigned int)((int)((unsigned int)v598 >> 2)) >> 1))))) >> 31))) == 0);
    int v697;
    if (v834) {
      int * v634 = v591->cache_age;
      int v836 = (4 + ((((int)((unsigned int)((int)((unsigned int)v598 >> 2)) >> 1)) & 3) * 2)) + ((~(((v610 ^ ((int)((unsigned int)((int)((unsigned int)v598 >> 2)) >> 1))) | (-(v610 ^ ((int)((unsigned int)((int)((unsigned int)v598 >> 2)) >> 1))))) >> 31)) & 1);
      int v635 = v634[v836];
      int * v636 = v591->cache_age;
      int v637 = v636[v814];
      int * v638 = v591->cache_age;
      int v839 = v637 + ((int)((unsigned int)(v637 - v635) >> 31));
      v638[v814] = v839;
      int * v640 = v591->cache_age;
      int v641 = v640[v816];
      int * v642 = v591->cache_age;
      int v842 = v641 + ((int)((unsigned int)(v641 - v635) >> 31));
      v642[v816] = v842;
      int * v644 = v591->cache_age;
      v644[v836] = 0;
      v697 = v836;
    } else {
      int * v647 = v591->cache_age;
      int v846 = 4 + ((((int)((unsigned int)((int)((unsigned int)v598 >> 2)) >> 1)) & 3) * 2);
      int v648 = v647[v846];
      int * v649 = v591->cache_tags;
      int v650 = v649[v846];
      int * v651 = v591->cache_age;
      int v652 = v651[v816];
      int * v653 = v591->cache_tags;
      int v654 = v653[v816];
      int * v655 = v591->cache_dirty;
      int v851 = (4 + ((((int)((unsigned int)((int)((unsigned int)v598 >> 2)) >> 1)) & 3) * 2)) + ((((v648 + ((~(((v650 ^ -1) | (-(v650 ^ -1))) >> 31)) & 2)) - (v652 + ((~(((v654 ^ -1) | (-(v654 ^ -1))) >> 31)) & 2))) >> 31) & 1);
      int v656 = v655[v851];
      bool v852 = !(v656 == 0);
      if (v852) {
        int * v657 = v591->cache_tags;
        int v658 = v657[v851];
        int * v659 = v591->cache_vals;
        int v855 = ((4 + ((((int)((unsigned int)((int)((unsigned int)v598 >> 2)) >> 1)) & 3) * 2)) + ((((v648 + ((~(((v650 ^ -1) | (-(v650 ^ -1))) >> 31)) & 2)) - (v652 + ((~(((v654 ^ -1) | (-(v654 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
        int v660 = v659[v855];
        int * v661 = v591->cache_vals;
        int v857 = (((4 + ((((int)((unsigned int)((int)((unsigned int)v598 >> 2)) >> 1)) & 3) * 2)) + ((((v648 + ((~(((v650 ^ -1) | (-(v650 ^ -1))) >> 31)) & 2)) - (v652 + ((~(((v654 ^ -1) | (-(v654 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
        int v662 = v661[v857];
        int * v663 = v591->mem;
        int v859 = v658 * 2;
        v663[v859] = v660;
        int * v665 = v591->mem;
        int v862 = (v658 * 2) + 1;
        v665[v862] = v662;
        ;
      } else {
        ;
      }
      int * v670 = v591->mem;
      int v867 = ((int)((unsigned int)((int)((unsigned int)v598 >> 2)) >> 1)) * 2;
      int v671 = v670[v867];
      int * v672 = v591->mem;
      int v869 = (((int)((unsigned int)((int)((unsigned int)v598 >> 2)) >> 1)) * 2) + 1;
      int v673 = v672[v869];
      int * v674 = v591->cache_vals;
      int v871 = ((4 + ((((int)((unsigned int)((int)((unsigned int)v598 >> 2)) >> 1)) & 3) * 2)) + ((((v648 + ((~(((v650 ^ -1) | (-(v650 ^ -1))) >> 31)) & 2)) - (v652 + ((~(((v654 ^ -1) | (-(v654 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
      v674[v871] = v671;
      int * v676 = v591->cache_vals;
      int v874 = (((4 + ((((int)((unsigned int)((int)((unsigned int)v598 >> 2)) >> 1)) & 3) * 2)) + ((((v648 + ((~(((v650 ^ -1) | (-(v650 ^ -1))) >> 31)) & 2)) - (v652 + ((~(((v654 ^ -1) | (-(v654 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
      v676[v874] = v673;
      int * v678 = v591->cache_tags;
      int v877 = (int)((unsigned int)((int)((unsigned int)v598 >> 2)) >> 1);
      v678[v851] = v877;
      int * v680 = v591->cache_dirty;
      v680[v851] = 0;
      int * v682 = v591->cache_age;
      v682[v851] = 1;
      int * v684 = v591->cache_age;
      int v685 = v684[v851];
      int * v686 = v591->cache_age;
      int v687 = v686[v814];
      int * v688 = v591->cache_age;
      int v885 = v687 + ((int)((unsigned int)(v687 - v685) >> 31));
      v688[v814] = v885;
      int * v690 = v591->cache_age;
      int v691 = v690[v816];
      int * v692 = v591->cache_age;
      int v888 = v691 + ((int)((unsigned int)(v691 - v685) >> 31));
      v692[v816] = v888;
      int * v694 = v591->cache_age;
      v694[v851] = 0;
      v697 = v851;
    }
    int * v698 = v591->cache_vals;
    int v891 = v697 * 2;
    int v699 = v698[v891];
    int * v700 = v591->cache_vals;
    int v893 = (v697 * 2) + 1;
    int v701 = v700[v893];
    int * v702 = v591->cache_vals;
    int v895 = (((((int)((unsigned int)((int)((unsigned int)v598 >> 2)) >> 1)) & 1) * 2) + ((((v627 + ((~(((v629 ^ -1) | (-(v629 ^ -1))) >> 31)) & 2)) - (v631 + ((~(((v633 ^ -1) | (-(v633 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
    v702[v895] = v699;
    int * v704 = v591->cache_vals;
    int v898 = ((((((int)((unsigned int)((int)((unsigned int)v598 >> 2)) >> 1)) & 1) * 2) + ((((v627 + ((~(((v629 ^ -1) | (-(v629 ^ -1))) >> 31)) & 2)) - (v631 + ((~(((v633 ^ -1) | (-(v633 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
    v704[v898] = v701;
    int * v706 = v591->cache_tags;
    int v901 = ((((int)((unsigned int)((int)((unsigned int)v598 >> 2)) >> 1)) & 1) * 2) + ((((v627 + ((~(((v629 ^ -1) | (-(v629 ^ -1))) >> 31)) & 2)) - (v631 + ((~(((v633 ^ -1) | (-(v633 ^ -1))) >> 31)) & 2))) >> 31) & 1);
    int v902 = (int)((unsigned int)((int)((unsigned int)v598 >> 2)) >> 1);
    v706[v901] = v902;
    int * v708 = v591->cache_dirty;
    v708[v901] = 0;
    int * v710 = v591->cache_age;
    v710[v901] = 1;
    int * v712 = v591->cache_age;
    int v713 = v712[v901];
    int * v714 = v591->cache_age;
    int v715 = v714[v810];
    int * v716 = v591->cache_age;
    int v910 = v715 + ((int)((unsigned int)(v715 - v713) >> 31));
    v716[v810] = v910;
    int * v718 = v591->cache_age;
    int v719 = v718[v812];
    int * v720 = v591->cache_age;
    int v913 = v719 + ((int)((unsigned int)(v719 - v713) >> 31));
    v720[v812] = v913;
    int * v722 = v591->cache_age;
    v722[v901] = 0;
    v725 = v901;
  }
  int * v726 = v591->cache_vals;
  int v916 = (v725 * 2) + (((int)((unsigned int)v598 >> 2)) & 1);
  v726[v916] = v602;
  int * v728 = v591->cache_tags;
  int v729 = v728[v814];
  int * v730 = v591->cache_tags;
  int v731 = v730[v816];
  bool v920 = !(((~(((v729 ^ ((int)((unsigned int)((int)((unsigned int)v598 >> 2)) >> 1))) | (-(v729 ^ ((int)((unsigned int)((int)((unsigned int)v598 >> 2)) >> 1))))) >> 31)) | (~(((v731 ^ ((int)((unsigned int)((int)((unsigned int)v598 >> 2)) >> 1))) | (-(v731 ^ ((int)((unsigned int)((int)((unsigned int)v598 >> 2)) >> 1))))) >> 31))) == 0);
  int v795;
  if (v920) {
    int * v732 = v591->cache_age;
    int v922 = (4 + ((((int)((unsigned int)((int)((unsigned int)v598 >> 2)) >> 1)) & 3) * 2)) + ((~(((v731 ^ ((int)((unsigned int)((int)((unsigned int)v598 >> 2)) >> 1))) | (-(v731 ^ ((int)((unsigned int)((int)((unsigned int)v598 >> 2)) >> 1))))) >> 31)) & 1);
    int v733 = v732[v922];
    int * v734 = v591->cache_age;
    int v735 = v734[v814];
    int * v736 = v591->cache_age;
    int v925 = v735 + ((int)((unsigned int)(v735 - v733) >> 31));
    v736[v814] = v925;
    int * v738 = v591->cache_age;
    int v739 = v738[v816];
    int * v740 = v591->cache_age;
    int v928 = v739 + ((int)((unsigned int)(v739 - v733) >> 31));
    v740[v816] = v928;
    int * v742 = v591->cache_age;
    v742[v922] = 0;
    v795 = v922;
  } else {
    int * v745 = v591->cache_age;
    int v932 = 4 + ((((int)((unsigned int)((int)((unsigned int)v598 >> 2)) >> 1)) & 3) * 2);
    int v746 = v745[v932];
    int * v747 = v591->cache_tags;
    int v748 = v747[v932];
    int * v749 = v591->cache_age;
    int v750 = v749[v816];
    int * v751 = v591->cache_tags;
    int v752 = v751[v816];
    int * v753 = v591->cache_dirty;
    int v937 = (4 + ((((int)((unsigned int)((int)((unsigned int)v598 >> 2)) >> 1)) & 3) * 2)) + ((((v746 + ((~(((v748 ^ -1) | (-(v748 ^ -1))) >> 31)) & 2)) - (v750 + ((~(((v752 ^ -1) | (-(v752 ^ -1))) >> 31)) & 2))) >> 31) & 1);
    int v754 = v753[v937];
    bool v938 = !(v754 == 0);
    if (v938) {
      int * v755 = v591->cache_tags;
      int v756 = v755[v937];
      int * v757 = v591->cache_vals;
      int v941 = ((4 + ((((int)((unsigned int)((int)((unsigned int)v598 >> 2)) >> 1)) & 3) * 2)) + ((((v746 + ((~(((v748 ^ -1) | (-(v748 ^ -1))) >> 31)) & 2)) - (v750 + ((~(((v752 ^ -1) | (-(v752 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
      int v758 = v757[v941];
      int * v759 = v591->cache_vals;
      int v943 = (((4 + ((((int)((unsigned int)((int)((unsigned int)v598 >> 2)) >> 1)) & 3) * 2)) + ((((v746 + ((~(((v748 ^ -1) | (-(v748 ^ -1))) >> 31)) & 2)) - (v750 + ((~(((v752 ^ -1) | (-(v752 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
      int v760 = v759[v943];
      int * v761 = v591->mem;
      int v945 = v756 * 2;
      v761[v945] = v758;
      int * v763 = v591->mem;
      int v948 = (v756 * 2) + 1;
      v763[v948] = v760;
      ;
    } else {
      ;
    }
    int * v768 = v591->mem;
    int v953 = ((int)((unsigned int)((int)((unsigned int)v598 >> 2)) >> 1)) * 2;
    int v769 = v768[v953];
    int * v770 = v591->mem;
    int v955 = (((int)((unsigned int)((int)((unsigned int)v598 >> 2)) >> 1)) * 2) + 1;
    int v771 = v770[v955];
    int * v772 = v591->cache_vals;
    int v957 = ((4 + ((((int)((unsigned int)((int)((unsigned int)v598 >> 2)) >> 1)) & 3) * 2)) + ((((v746 + ((~(((v748 ^ -1) | (-(v748 ^ -1))) >> 31)) & 2)) - (v750 + ((~(((v752 ^ -1) | (-(v752 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
    v772[v957] = v769;
    int * v774 = v591->cache_vals;
    int v960 = (((4 + ((((int)((unsigned int)((int)((unsigned int)v598 >> 2)) >> 1)) & 3) * 2)) + ((((v746 + ((~(((v748 ^ -1) | (-(v748 ^ -1))) >> 31)) & 2)) - (v750 + ((~(((v752 ^ -1) | (-(v752 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
    v774[v960] = v771;
    int * v776 = v591->cache_tags;
    int v963 = (int)((unsigned int)((int)((unsigned int)v598 >> 2)) >> 1);
    v776[v937] = v963;
    int * v778 = v591->cache_dirty;
    v778[v937] = 0;
    int * v780 = v591->cache_age;
    v780[v937] = 1;
    int * v782 = v591->cache_age;
    int v783 = v782[v937];
    int * v784 = v591->cache_age;
    int v785 = v784[v814];
    int * v786 = v591->cache_age;
    int v971 = v785 + ((int)((unsigned int)(v785 - v783) >> 31));
    v786[v814] = v971;
    int * v788 = v591->cache_age;
    int v789 = v788[v816];
    int * v790 = v591->cache_age;
    int v974 = v789 + ((int)((unsigned int)(v789 - v783) >> 31));
    v790[v816] = v974;
    int * v792 = v591->cache_age;
    v792[v937] = 0;
    v795 = v937;
  }
  int * v796 = v591->cache_vals;
  int v977 = (v795 * 2) + (((int)((unsigned int)v598 >> 2)) & 1);
  v796[v977] = v602;
  int * v798 = v591->cache_dirty;
  v798[v795] = 1;
  struct StateT * v800 = slot_9(v591);
  return v800;
}

struct StateT * slot_4(struct StateT * v65) {
  int * v66 = v65->saved_regs;
  int * v67 = v65->regs;
  int v68 = v67[8];
  v66[8] = v68;
  int v70 = v65->timer;
  int v71 = v65->timer;
  int v91 = v71 + 1;
  v65->timer = v91;
  int * v73 = v65->reg_ready;
  int v74 = v73[9];
  int * v75 = v65->regs;
  int v76 = v75[9];
  int * v77 = v65->reg_ready;
  int v78 = v77[6];
  int * v79 = v65->regs;
  int v80 = v79[6];
  int * v81 = v65->reg_ready;
  int v99 = (v78 + (((v74 + ((v70 - v74) & (~((v70 - v74) >> 31)))) - v78) & (~(((v74 + ((v70 - v74) & (~((v70 - v74) >> 31)))) - v78) >> 31)))) + 1;
  v81[8] = v99;
  int * v83 = v65->regs;
  int v101 = v76 + v80;
  v83[8] = v101;
  struct StateT * v85 = slot_5(v65);
  return v85;
}

struct StateT * slot_13(struct StateT * v1280) {
  int * v1281 = v1280->saved_regs;
  int * v1282 = v1280->regs;
  int v1283 = v1282[8];
  v1281[8] = v1283;
  int v1285 = v1280->timer;
  int v1286 = v1280->timer;
  int v1306 = v1286 + 1;
  v1280->timer = v1306;
  int * v1288 = v1280->reg_ready;
  int v1289 = v1288[9];
  int * v1290 = v1280->regs;
  int v1291 = v1290[9];
  int * v1292 = v1280->reg_ready;
  int v1293 = v1292[6];
  int * v1294 = v1280->regs;
  int v1295 = v1294[6];
  int * v1296 = v1280->reg_ready;
  int v1314 = (v1293 + (((v1289 + ((v1285 - v1289) & (~((v1285 - v1289) >> 31)))) - v1293) & (~(((v1289 + ((v1285 - v1289) & (~((v1285 - v1289) >> 31)))) - v1293) >> 31)))) + 1;
  v1296[8] = v1314;
  int * v1298 = v1280->regs;
  int v1316 = v1291 + v1295;
  v1298[8] = v1316;
  struct StateT * v1300 = slot_14(v1280);
  return v1300;
}

struct StateT * slot_15(struct StateT * v1581) {
  int * v1582 = v1581->regs;
  int v1583 = v1582[6];
  int * v1584 = v1581->regs;
  int v1585 = v1584[7];
  bool v1701 = v1583 >= v1585;
  struct StateT * v1695;
  if (v1701) {
    int v1586 = v1581->timer;
    int v1702 = v1586 + 15;
    v1581->timer = v1702;
    int * v1588 = v1581->saved_regs;
    int v1589 = v1588[8];
    int * v1590 = v1581->regs;
    v1590[8] = v1589;
    int * v1592 = v1581->saved_regs;
    int v1593 = v1592[5];
    int * v1594 = v1581->regs;
    v1594[5] = v1593;
    int * v1596 = v1581->reg_ready;
    int v1597 = v1581->timer;
    v1596[0] = v1597;
    int * v1599 = v1581->reg_ready;
    int v1600 = v1581->timer;
    v1599[1] = v1600;
    int * v1602 = v1581->reg_ready;
    int v1603 = v1581->timer;
    v1602[2] = v1603;
    int * v1605 = v1581->reg_ready;
    int v1606 = v1581->timer;
    v1605[3] = v1606;
    int * v1608 = v1581->reg_ready;
    int v1609 = v1581->timer;
    v1608[4] = v1609;
    int * v1611 = v1581->reg_ready;
    int v1612 = v1581->timer;
    v1611[5] = v1612;
    int * v1614 = v1581->reg_ready;
    int v1615 = v1581->timer;
    v1614[6] = v1615;
    int * v1617 = v1581->reg_ready;
    int v1618 = v1581->timer;
    v1617[7] = v1618;
    int * v1620 = v1581->reg_ready;
    int v1621 = v1581->timer;
    v1620[8] = v1621;
    int * v1623 = v1581->reg_ready;
    int v1624 = v1581->timer;
    v1623[9] = v1624;
    int * v1626 = v1581->reg_ready;
    int v1627 = v1581->timer;
    v1626[10] = v1627;
    int * v1629 = v1581->reg_ready;
    int v1630 = v1581->timer;
    v1629[11] = v1630;
    int * v1632 = v1581->reg_ready;
    int v1633 = v1581->timer;
    v1632[12] = v1633;
    int * v1635 = v1581->reg_ready;
    int v1636 = v1581->timer;
    v1635[13] = v1636;
    int * v1638 = v1581->reg_ready;
    int v1639 = v1581->timer;
    v1638[14] = v1639;
    int * v1641 = v1581->reg_ready;
    int v1642 = v1581->timer;
    v1641[15] = v1642;
    int * v1644 = v1581->reg_ready;
    int v1645 = v1581->timer;
    v1644[16] = v1645;
    int * v1647 = v1581->reg_ready;
    int v1648 = v1581->timer;
    v1647[17] = v1648;
    int * v1650 = v1581->reg_ready;
    int v1651 = v1581->timer;
    v1650[18] = v1651;
    int * v1653 = v1581->reg_ready;
    int v1654 = v1581->timer;
    v1653[19] = v1654;
    int * v1656 = v1581->reg_ready;
    int v1657 = v1581->timer;
    v1656[20] = v1657;
    int * v1659 = v1581->reg_ready;
    int v1660 = v1581->timer;
    v1659[21] = v1660;
    int * v1662 = v1581->reg_ready;
    int v1663 = v1581->timer;
    v1662[22] = v1663;
    int * v1665 = v1581->reg_ready;
    int v1666 = v1581->timer;
    v1665[23] = v1666;
    int * v1668 = v1581->reg_ready;
    int v1669 = v1581->timer;
    v1668[24] = v1669;
    int * v1671 = v1581->reg_ready;
    int v1672 = v1581->timer;
    v1671[25] = v1672;
    int * v1674 = v1581->reg_ready;
    int v1675 = v1581->timer;
    v1674[26] = v1675;
    int * v1677 = v1581->reg_ready;
    int v1678 = v1581->timer;
    v1677[27] = v1678;
    int * v1680 = v1581->reg_ready;
    int v1681 = v1581->timer;
    v1680[28] = v1681;
    int * v1683 = v1581->reg_ready;
    int v1684 = v1581->timer;
    v1683[29] = v1684;
    int * v1686 = v1581->reg_ready;
    int v1687 = v1581->timer;
    v1686[30] = v1687;
    int * v1689 = v1581->reg_ready;
    int v1690 = v1581->timer;
    v1689[31] = v1690;
    v1695 = v1581;
  } else {
    struct StateT * v1693 = slot_8(v1581);
    v1695 = v1693;
  }
  return v1695;
}

struct StateT * slot_9(struct StateT * v983) {
  int v984 = v983->timer;
  int v985 = v983->timer;
  int v1120 = v985 + 1;
  v983->timer = v1120;
  int * v987 = v983->reg_ready;
  int v988 = v987[6];
  int * v989 = v983->regs;
  int v990 = v989[6];
  int * v991 = v983->cache_tags;
  int v1125 = (((int)((unsigned int)((int)((unsigned int)v990 >> 2)) >> 1)) & 1) * 2;
  int v992 = v991[v1125];
  int * v993 = v983->cache_tags;
  int v1127 = ((((int)((unsigned int)((int)((unsigned int)v990 >> 2)) >> 1)) & 1) * 2) + 1;
  int v994 = v993[v1127];
  int * v995 = v983->cache_tags;
  int v1129 = 4 + ((((int)((unsigned int)((int)((unsigned int)v990 >> 2)) >> 1)) & 3) * 2);
  int v996 = v995[v1129];
  int * v997 = v983->cache_tags;
  int v1131 = (4 + ((((int)((unsigned int)((int)((unsigned int)v990 >> 2)) >> 1)) & 3) * 2)) + 1;
  int v998 = v997[v1131];
  int * v999 = v983->cache_vals;
  bool v1132 = !(((~(((v992 ^ ((int)((unsigned int)((int)((unsigned int)v990 >> 2)) >> 1))) | (-(v992 ^ ((int)((unsigned int)((int)((unsigned int)v990 >> 2)) >> 1))))) >> 31)) | (~(((v994 ^ ((int)((unsigned int)((int)((unsigned int)v990 >> 2)) >> 1))) | (-(v994 ^ ((int)((unsigned int)((int)((unsigned int)v990 >> 2)) >> 1))))) >> 31))) == 0);
  int v1112;
  if (v1132) {
    int * v1000 = v983->cache_age;
    int v1134 = ((((int)((unsigned int)((int)((unsigned int)v990 >> 2)) >> 1)) & 1) * 2) + ((~(((v994 ^ ((int)((unsigned int)((int)((unsigned int)v990 >> 2)) >> 1))) | (-(v994 ^ ((int)((unsigned int)((int)((unsigned int)v990 >> 2)) >> 1))))) >> 31)) & 1);
    int v1001 = v1000[v1134];
    int * v1002 = v983->cache_age;
    int v1003 = v1002[v1125];
    int * v1004 = v983->cache_age;
    int v1137 = v1003 + ((int)((unsigned int)(v1003 - v1001) >> 31));
    v1004[v1125] = v1137;
    int * v1006 = v983->cache_age;
    int v1007 = v1006[v1127];
    int * v1008 = v983->cache_age;
    int v1140 = v1007 + ((int)((unsigned int)(v1007 - v1001) >> 31));
    v1008[v1127] = v1140;
    int * v1010 = v983->cache_age;
    v1010[v1134] = 0;
    v1112 = v1134;
  } else {
    int * v1013 = v983->cache_age;
    int v1144 = (((int)((unsigned int)((int)((unsigned int)v990 >> 2)) >> 1)) & 1) * 2;
    int v1014 = v1013[v1144];
    int * v1015 = v983->cache_tags;
    int v1016 = v1015[v1144];
    int * v1017 = v983->cache_age;
    int v1018 = v1017[v1127];
    int * v1019 = v983->cache_tags;
    int v1020 = v1019[v1127];
    bool v1148 = !(((~(((v996 ^ ((int)((unsigned int)((int)((unsigned int)v990 >> 2)) >> 1))) | (-(v996 ^ ((int)((unsigned int)((int)((unsigned int)v990 >> 2)) >> 1))))) >> 31)) | (~(((v998 ^ ((int)((unsigned int)((int)((unsigned int)v990 >> 2)) >> 1))) | (-(v998 ^ ((int)((unsigned int)((int)((unsigned int)v990 >> 2)) >> 1))))) >> 31))) == 0);
    int v1084;
    if (v1148) {
      int * v1021 = v983->cache_age;
      int v1150 = (4 + ((((int)((unsigned int)((int)((unsigned int)v990 >> 2)) >> 1)) & 3) * 2)) + ((~(((v998 ^ ((int)((unsigned int)((int)((unsigned int)v990 >> 2)) >> 1))) | (-(v998 ^ ((int)((unsigned int)((int)((unsigned int)v990 >> 2)) >> 1))))) >> 31)) & 1);
      int v1022 = v1021[v1150];
      int * v1023 = v983->cache_age;
      int v1024 = v1023[v1129];
      int * v1025 = v983->cache_age;
      int v1153 = v1024 + ((int)((unsigned int)(v1024 - v1022) >> 31));
      v1025[v1129] = v1153;
      int * v1027 = v983->cache_age;
      int v1028 = v1027[v1131];
      int * v1029 = v983->cache_age;
      int v1156 = v1028 + ((int)((unsigned int)(v1028 - v1022) >> 31));
      v1029[v1131] = v1156;
      int * v1031 = v983->cache_age;
      v1031[v1150] = 0;
      v1084 = v1150;
    } else {
      int * v1034 = v983->cache_age;
      int v1160 = 4 + ((((int)((unsigned int)((int)((unsigned int)v990 >> 2)) >> 1)) & 3) * 2);
      int v1035 = v1034[v1160];
      int * v1036 = v983->cache_tags;
      int v1037 = v1036[v1160];
      int * v1038 = v983->cache_age;
      int v1039 = v1038[v1131];
      int * v1040 = v983->cache_tags;
      int v1041 = v1040[v1131];
      int * v1042 = v983->cache_dirty;
      int v1165 = (4 + ((((int)((unsigned int)((int)((unsigned int)v990 >> 2)) >> 1)) & 3) * 2)) + ((((v1035 + ((~(((v1037 ^ -1) | (-(v1037 ^ -1))) >> 31)) & 2)) - (v1039 + ((~(((v1041 ^ -1) | (-(v1041 ^ -1))) >> 31)) & 2))) >> 31) & 1);
      int v1043 = v1042[v1165];
      bool v1166 = !(v1043 == 0);
      if (v1166) {
        int * v1044 = v983->cache_tags;
        int v1045 = v1044[v1165];
        int * v1046 = v983->cache_vals;
        int v1169 = ((4 + ((((int)((unsigned int)((int)((unsigned int)v990 >> 2)) >> 1)) & 3) * 2)) + ((((v1035 + ((~(((v1037 ^ -1) | (-(v1037 ^ -1))) >> 31)) & 2)) - (v1039 + ((~(((v1041 ^ -1) | (-(v1041 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
        int v1047 = v1046[v1169];
        int * v1048 = v983->cache_vals;
        int v1171 = (((4 + ((((int)((unsigned int)((int)((unsigned int)v990 >> 2)) >> 1)) & 3) * 2)) + ((((v1035 + ((~(((v1037 ^ -1) | (-(v1037 ^ -1))) >> 31)) & 2)) - (v1039 + ((~(((v1041 ^ -1) | (-(v1041 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
        int v1049 = v1048[v1171];
        int * v1050 = v983->mem;
        int v1173 = v1045 * 2;
        v1050[v1173] = v1047;
        int * v1052 = v983->mem;
        int v1176 = (v1045 * 2) + 1;
        v1052[v1176] = v1049;
        ;
      } else {
        ;
      }
      int * v1057 = v983->mem;
      int v1181 = ((int)((unsigned int)((int)((unsigned int)v990 >> 2)) >> 1)) * 2;
      int v1058 = v1057[v1181];
      int * v1059 = v983->mem;
      int v1183 = (((int)((unsigned int)((int)((unsigned int)v990 >> 2)) >> 1)) * 2) + 1;
      int v1060 = v1059[v1183];
      int * v1061 = v983->cache_vals;
      int v1185 = ((4 + ((((int)((unsigned int)((int)((unsigned int)v990 >> 2)) >> 1)) & 3) * 2)) + ((((v1035 + ((~(((v1037 ^ -1) | (-(v1037 ^ -1))) >> 31)) & 2)) - (v1039 + ((~(((v1041 ^ -1) | (-(v1041 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
      v1061[v1185] = v1058;
      int * v1063 = v983->cache_vals;
      int v1188 = (((4 + ((((int)((unsigned int)((int)((unsigned int)v990 >> 2)) >> 1)) & 3) * 2)) + ((((v1035 + ((~(((v1037 ^ -1) | (-(v1037 ^ -1))) >> 31)) & 2)) - (v1039 + ((~(((v1041 ^ -1) | (-(v1041 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
      v1063[v1188] = v1060;
      int * v1065 = v983->cache_tags;
      int v1191 = (int)((unsigned int)((int)((unsigned int)v990 >> 2)) >> 1);
      v1065[v1165] = v1191;
      int * v1067 = v983->cache_dirty;
      v1067[v1165] = 0;
      int * v1069 = v983->cache_age;
      v1069[v1165] = 1;
      int * v1071 = v983->cache_age;
      int v1072 = v1071[v1165];
      int * v1073 = v983->cache_age;
      int v1074 = v1073[v1129];
      int * v1075 = v983->cache_age;
      int v1199 = v1074 + ((int)((unsigned int)(v1074 - v1072) >> 31));
      v1075[v1129] = v1199;
      int * v1077 = v983->cache_age;
      int v1078 = v1077[v1131];
      int * v1079 = v983->cache_age;
      int v1202 = v1078 + ((int)((unsigned int)(v1078 - v1072) >> 31));
      v1079[v1131] = v1202;
      int * v1081 = v983->cache_age;
      v1081[v1165] = 0;
      v1084 = v1165;
    }
    int * v1085 = v983->cache_vals;
    int v1205 = v1084 * 2;
    int v1086 = v1085[v1205];
    int * v1087 = v983->cache_vals;
    int v1207 = (v1084 * 2) + 1;
    int v1088 = v1087[v1207];
    int * v1089 = v983->cache_vals;
    int v1209 = (((((int)((unsigned int)((int)((unsigned int)v990 >> 2)) >> 1)) & 1) * 2) + ((((v1014 + ((~(((v1016 ^ -1) | (-(v1016 ^ -1))) >> 31)) & 2)) - (v1018 + ((~(((v1020 ^ -1) | (-(v1020 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
    v1089[v1209] = v1086;
    int * v1091 = v983->cache_vals;
    int v1212 = ((((((int)((unsigned int)((int)((unsigned int)v990 >> 2)) >> 1)) & 1) * 2) + ((((v1014 + ((~(((v1016 ^ -1) | (-(v1016 ^ -1))) >> 31)) & 2)) - (v1018 + ((~(((v1020 ^ -1) | (-(v1020 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
    v1091[v1212] = v1088;
    int * v1093 = v983->cache_tags;
    int v1215 = ((((int)((unsigned int)((int)((unsigned int)v990 >> 2)) >> 1)) & 1) * 2) + ((((v1014 + ((~(((v1016 ^ -1) | (-(v1016 ^ -1))) >> 31)) & 2)) - (v1018 + ((~(((v1020 ^ -1) | (-(v1020 ^ -1))) >> 31)) & 2))) >> 31) & 1);
    int v1216 = (int)((unsigned int)((int)((unsigned int)v990 >> 2)) >> 1);
    v1093[v1215] = v1216;
    int * v1095 = v983->cache_dirty;
    v1095[v1215] = 0;
    int * v1097 = v983->cache_age;
    v1097[v1215] = 1;
    int * v1099 = v983->cache_age;
    int v1100 = v1099[v1215];
    int * v1101 = v983->cache_age;
    int v1102 = v1101[v1125];
    int * v1103 = v983->cache_age;
    int v1224 = v1102 + ((int)((unsigned int)(v1102 - v1100) >> 31));
    v1103[v1125] = v1224;
    int * v1105 = v983->cache_age;
    int v1106 = v1105[v1127];
    int * v1107 = v983->cache_age;
    int v1227 = v1106 + ((int)((unsigned int)(v1106 - v1100) >> 31));
    v1107[v1127] = v1227;
    int * v1109 = v983->cache_age;
    v1109[v1215] = 0;
    v1112 = v1215;
  }
  int v1230 = (v1112 * 2) + (((int)((unsigned int)v990 >> 2)) & 1);
  int v1113 = v999[v1230];
  int * v1114 = v983->reg_ready;
  int v1233 = ((v988 + ((v984 - v988) & (~((v984 - v988) >> 31)))) + 1) + ((100 ^ (((~(((v996 ^ ((int)((unsigned int)((int)((unsigned int)v990 >> 2)) >> 1))) | (-(v996 ^ ((int)((unsigned int)((int)((unsigned int)v990 >> 2)) >> 1))))) >> 31)) | (~(((v998 ^ ((int)((unsigned int)((int)((unsigned int)v990 >> 2)) >> 1))) | (-(v998 ^ ((int)((unsigned int)((int)((unsigned int)v990 >> 2)) >> 1))))) >> 31))) & 104)) ^ (((~(((v992 ^ ((int)((unsigned int)((int)((unsigned int)v990 >> 2)) >> 1))) | (-(v992 ^ ((int)((unsigned int)((int)((unsigned int)v990 >> 2)) >> 1))))) >> 31)) | (~(((v994 ^ ((int)((unsigned int)((int)((unsigned int)v990 >> 2)) >> 1))) | (-(v994 ^ ((int)((unsigned int)((int)((unsigned int)v990 >> 2)) >> 1))))) >> 31))) & (1 ^ (100 ^ (((~(((v996 ^ ((int)((unsigned int)((int)((unsigned int)v990 >> 2)) >> 1))) | (-(v996 ^ ((int)((unsigned int)((int)((unsigned int)v990 >> 2)) >> 1))))) >> 31)) | (~(((v998 ^ ((int)((unsigned int)((int)((unsigned int)v990 >> 2)) >> 1))) | (-(v998 ^ ((int)((unsigned int)((int)((unsigned int)v990 >> 2)) >> 1))))) >> 31))) & 104)))));
  v1114[11] = v1233;
  int * v1116 = v983->regs;
  v1116[11] = v1113;
  struct StateT * v1118 = slot_10(v983);
  return v1118;
}

struct StateT * slot_11(struct StateT * v1262) {
  int v1263 = v1262->timer;
  int v1264 = v1262->timer;
  int v1268 = v1264 + 1;
  v1262->timer = v1268;
  struct StateT * v1266 = slot_12(v1262);
  return v1266;
}

struct StateT * slot_0(struct StateT * v2) {
  int v3 = v2->timer;
  int v4 = v2->timer;
  int v12 = v4 + 1;
  v2->timer = v12;
  int * v6 = v2->reg_ready;
  int v15 = v3 + 1;
  v6[6] = v15;
  int * v8 = v2->regs;
  v8[6] = 0;
  struct StateT * v10 = slot_1(v2);
  return v10;
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