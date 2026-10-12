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

struct StateT * slot_12(struct StateT * v813);
struct StateT * slot_34(struct StateT * v1974);
struct StateT * slot_6(struct StateT * v486);
struct StateT * slot_29(struct StateT * v1675);
struct StateT * slot_25(struct StateT * v1408);
struct StateT * slot_16(struct StateT * v901);
struct StateT * slot_23(struct StateT * v1363);
struct StateT * slot_5(struct StateT * v279);
struct StateT * slot_2(struct StateT * v225);
struct StateT * slot_7(struct StateT * v509);
struct StateT * slot_21(struct StateT * v1304);
struct StateT * slot_31(struct StateT * v1715);
struct StateT * slot_3(struct StateT * v233);
struct StateT * slot_26(struct StateT * v1615);
struct StateT * slot_10(struct StateT * v582);
struct StateT * slot_1(struct StateT * v18);
struct StateT * slot_19(struct StateT * v977);
struct StateT * slot_13(struct StateT * v888);
struct StateT * slot_24(struct StateT * v1384);
struct StateT * slot_0(struct StateT * v2);
struct StateT * slot_14(struct StateT * v893);
struct StateT * slot_28(struct StateT * v1647);
struct StateT * slot_32(struct StateT * v1743);
struct StateT * slot_17(struct StateT * v929);
struct StateT * slot_20(struct StateT * v985);
struct StateT * slot_33(struct StateT * v1767);
struct StateT * snippet(struct StateT * v0);
struct StateT * slot_8(struct StateT * v530);
struct StateT * slot_27(struct StateT * v1639);
struct StateT * slot_30(struct StateT * v1707);
struct StateT * slot_4(struct StateT * v256);
struct StateT * slot_18(struct StateT * v961);
struct StateT * slot_9(struct StateT * v558);
struct StateT * slot_22(struct StateT * v1327);
struct StateT * slot_11(struct StateT * v789);
struct StateT * slot_35(struct StateT * v2005);
struct StateT * slot_12(struct StateT * v813) {
  int * v814 = v813->saved_regs;
  int v815 = v814[10];
  int * v816 = v813->regs;
  int v817 = v816[11];
  bool v858 = (v815 ^ -2147483648) >= (v817 ^ -2147483648);
  struct StateT * v852;
  if (v858) {
    int v818 = v813->timer;
    int v859 = v818 + 15;
    v813->timer = v859;
    int * v820 = v813->saved_regs;
    int v821 = v820[13];
    int * v822 = v813->regs;
    v822[13] = v821;
    int * v824 = v813->saved_regs;
    int v825 = v824[12];
    int * v826 = v813->regs;
    v826[12] = v825;
    int * v828 = v813->saved_regs;
    int v829 = v828[14];
    int * v830 = v813->regs;
    v830[14] = v829;
    int * v832 = v813->saved_regs;
    int v833 = v832[10];
    int * v834 = v813->regs;
    v834[10] = v833;
    int * v836 = v813->reg_ready;
    int v837 = v813->timer;
    v836[13] = v837;
    int * v839 = v813->reg_ready;
    int v840 = v813->timer;
    v839[12] = v840;
    int * v842 = v813->reg_ready;
    int v843 = v813->timer;
    v842[14] = v843;
    int * v845 = v813->reg_ready;
    int v846 = v813->timer;
    v845[10] = v846;
    struct StateT * v848 = slot_13(v813);
    v852 = v848;
  } else {
    struct StateT * v850 = slot_14(v813);
    v852 = v850;
  }
  return v852;
}

struct StateT * slot_34(struct StateT * v1974) {
  int * v1975 = v1974->saved_regs;
  int * v1976 = v1974->regs;
  int v1977 = v1976[12];
  v1975[12] = v1977;
  int v1979 = v1974->timer;
  int v1996 = v1979 + 1;
  v1974->timer = v1996;
  int * v1981 = v1974->reg_ready;
  int v1982 = v1981[12];
  int * v1983 = v1974->regs;
  int v1984 = v1983[12];
  int v1985 = v1981[10];
  int v1986 = v1983[10];
  int v2000 = (v1985 + (((v1982 + ((v1979 - v1982) & (~((v1979 - v1982) >> 31)))) - v1985) & (~(((v1982 + ((v1979 - v1982) & (~((v1979 - v1982) >> 31)))) - v1985) >> 31)))) + 1;
  v1981[12] = v2000;
  int * v1988 = v1974->regs;
  int v2002 = v1984 & v1986;
  v1988[12] = v2002;
  struct StateT * v1990 = slot_35(v1974);
  return v1990;
}

struct StateT * slot_6(struct StateT * v486) {
  int * v487 = v486->saved_regs;
  int * v488 = v486->regs;
  int v489 = v488[14];
  v487[14] = v489;
  int v491 = v486->timer;
  int v503 = v491 + 1;
  v486->timer = v503;
  int * v493 = v486->reg_ready;
  v493[14] = v503;
  int * v495 = v486->regs;
  v495[14] = 0;
  struct StateT * v497 = slot_7(v486);
  return v497;
}

struct StateT * slot_29(struct StateT * v1675) {
  int * v1676 = v1675->saved_regs;
  int v1677 = v1676[13];
  bool v1695 = !(v1677 == 0);
  struct StateT * v1691;
  if (v1695) {
    int v1678 = v1675->timer;
    int v1696 = v1678 + 15;
    v1675->timer = v1696;
    int * v1680 = v1675->saved_regs;
    int v1681 = v1680[13];
    int * v1682 = v1675->regs;
    v1682[13] = v1681;
    int * v1684 = v1675->reg_ready;
    int v1685 = v1675->timer;
    v1684[13] = v1685;
    struct StateT * v1687 = slot_18(v1675);
    v1691 = v1687;
  } else {
    struct StateT * v1689 = slot_30(v1675);
    v1691 = v1689;
  }
  return v1691;
}

struct StateT * slot_25(struct StateT * v1408) {
  int v1409 = v1408->timer;
  int v1521 = v1409 + 1;
  v1408->timer = v1521;
  int * v1411 = v1408->reg_ready;
  int v1412 = v1411[10];
  int * v1413 = v1408->regs;
  int v1414 = v1413[10];
  int * v1415 = v1408->cache_tags;
  int v1526 = (((int)((unsigned int)((int)((unsigned int)v1414 >> 2)) >> 1)) & 1) * 2;
  int v1416 = v1415[v1526];
  int v1527 = ((((int)((unsigned int)((int)((unsigned int)v1414 >> 2)) >> 1)) & 1) * 2) + 1;
  int v1417 = v1415[v1527];
  int v1528 = 4 + ((((int)((unsigned int)((int)((unsigned int)v1414 >> 2)) >> 1)) & 3) * 2);
  int v1418 = v1415[v1528];
  int v1529 = (4 + ((((int)((unsigned int)((int)((unsigned int)v1414 >> 2)) >> 1)) & 3) * 2)) + 1;
  int v1419 = v1415[v1529];
  int * v1420 = v1408->cache_vals;
  bool v1530 = !(((~(((v1416 ^ ((int)((unsigned int)((int)((unsigned int)v1414 >> 2)) >> 1))) | (-(v1416 ^ ((int)((unsigned int)((int)((unsigned int)v1414 >> 2)) >> 1))))) >> 31)) | (~(((v1417 ^ ((int)((unsigned int)((int)((unsigned int)v1414 >> 2)) >> 1))) | (-(v1417 ^ ((int)((unsigned int)((int)((unsigned int)v1414 >> 2)) >> 1))))) >> 31))) == 0);
  int v1513;
  if (v1530) {
    int * v1421 = v1408->cache_age;
    int v1532 = ((((int)((unsigned int)((int)((unsigned int)v1414 >> 2)) >> 1)) & 1) * 2) + ((~(((v1417 ^ ((int)((unsigned int)((int)((unsigned int)v1414 >> 2)) >> 1))) | (-(v1417 ^ ((int)((unsigned int)((int)((unsigned int)v1414 >> 2)) >> 1))))) >> 31)) & 1);
    int v1422 = v1421[v1532];
    int v1423 = v1421[v1526];
    int v1533 = v1423 + ((int)((unsigned int)(v1423 - v1422) >> 31));
    v1421[v1526] = v1533;
    int * v1425 = v1408->cache_age;
    int v1426 = v1425[v1527];
    int v1535 = v1426 + ((int)((unsigned int)(v1426 - v1422) >> 31));
    v1425[v1527] = v1535;
    int * v1428 = v1408->cache_age;
    v1428[v1532] = 0;
    v1513 = v1532;
  } else {
    int * v1431 = v1408->cache_age;
    int v1539 = (((int)((unsigned int)((int)((unsigned int)v1414 >> 2)) >> 1)) & 1) * 2;
    int v1432 = v1431[v1539];
    int * v1433 = v1408->cache_tags;
    int v1434 = v1433[v1539];
    int v1435 = v1431[v1527];
    int v1436 = v1433[v1527];
    bool v1541 = !(((~(((v1418 ^ ((int)((unsigned int)((int)((unsigned int)v1414 >> 2)) >> 1))) | (-(v1418 ^ ((int)((unsigned int)((int)((unsigned int)v1414 >> 2)) >> 1))))) >> 31)) | (~(((v1419 ^ ((int)((unsigned int)((int)((unsigned int)v1414 >> 2)) >> 1))) | (-(v1419 ^ ((int)((unsigned int)((int)((unsigned int)v1414 >> 2)) >> 1))))) >> 31))) == 0);
    int v1490;
    if (v1541) {
      int * v1437 = v1408->cache_age;
      int v1543 = (4 + ((((int)((unsigned int)((int)((unsigned int)v1414 >> 2)) >> 1)) & 3) * 2)) + ((~(((v1419 ^ ((int)((unsigned int)((int)((unsigned int)v1414 >> 2)) >> 1))) | (-(v1419 ^ ((int)((unsigned int)((int)((unsigned int)v1414 >> 2)) >> 1))))) >> 31)) & 1);
      int v1438 = v1437[v1543];
      int v1439 = v1437[v1528];
      int v1544 = v1439 + ((int)((unsigned int)(v1439 - v1438) >> 31));
      v1437[v1528] = v1544;
      int * v1441 = v1408->cache_age;
      int v1442 = v1441[v1529];
      int v1546 = v1442 + ((int)((unsigned int)(v1442 - v1438) >> 31));
      v1441[v1529] = v1546;
      int * v1444 = v1408->cache_age;
      v1444[v1543] = 0;
      v1490 = v1543;
    } else {
      int * v1447 = v1408->cache_age;
      int v1550 = 4 + ((((int)((unsigned int)((int)((unsigned int)v1414 >> 2)) >> 1)) & 3) * 2);
      int v1448 = v1447[v1550];
      int * v1449 = v1408->cache_tags;
      int v1450 = v1449[v1550];
      int v1451 = v1447[v1529];
      int v1452 = v1449[v1529];
      int * v1453 = v1408->cache_dirty;
      int v1553 = (4 + ((((int)((unsigned int)((int)((unsigned int)v1414 >> 2)) >> 1)) & 3) * 2)) + ((((v1448 + ((~(((v1450 ^ -1) | (-(v1450 ^ -1))) >> 31)) & 2)) - (v1451 + ((~(((v1452 ^ -1) | (-(v1452 ^ -1))) >> 31)) & 2))) >> 31) & 1);
      int v1454 = v1453[v1553];
      bool v1554 = !(v1454 == 0);
      if (v1554) {
        int * v1455 = v1408->cache_tags;
        int v1456 = v1455[v1553];
        int * v1457 = v1408->cache_vals;
        int v1557 = ((4 + ((((int)((unsigned int)((int)((unsigned int)v1414 >> 2)) >> 1)) & 3) * 2)) + ((((v1448 + ((~(((v1450 ^ -1) | (-(v1450 ^ -1))) >> 31)) & 2)) - (v1451 + ((~(((v1452 ^ -1) | (-(v1452 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
        int v1458 = v1457[v1557];
        int v1558 = (((4 + ((((int)((unsigned int)((int)((unsigned int)v1414 >> 2)) >> 1)) & 3) * 2)) + ((((v1448 + ((~(((v1450 ^ -1) | (-(v1450 ^ -1))) >> 31)) & 2)) - (v1451 + ((~(((v1452 ^ -1) | (-(v1452 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
        int v1459 = v1457[v1558];
        int * v1460 = v1408->mem;
        int v1560 = v1456 * 2;
        v1460[v1560] = v1458;
        int * v1462 = v1408->mem;
        int v1563 = (v1456 * 2) + 1;
        v1462[v1563] = v1459;
        ;
      } else {
        ;
      }
      int * v1467 = v1408->mem;
      int v1568 = ((int)((unsigned int)((int)((unsigned int)v1414 >> 2)) >> 1)) * 2;
      int v1468 = v1467[v1568];
      int v1569 = (((int)((unsigned int)((int)((unsigned int)v1414 >> 2)) >> 1)) * 2) + 1;
      int v1469 = v1467[v1569];
      int * v1470 = v1408->cache_vals;
      int v1571 = ((4 + ((((int)((unsigned int)((int)((unsigned int)v1414 >> 2)) >> 1)) & 3) * 2)) + ((((v1448 + ((~(((v1450 ^ -1) | (-(v1450 ^ -1))) >> 31)) & 2)) - (v1451 + ((~(((v1452 ^ -1) | (-(v1452 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
      v1470[v1571] = v1468;
      int * v1472 = v1408->cache_vals;
      int v1574 = (((4 + ((((int)((unsigned int)((int)((unsigned int)v1414 >> 2)) >> 1)) & 3) * 2)) + ((((v1448 + ((~(((v1450 ^ -1) | (-(v1450 ^ -1))) >> 31)) & 2)) - (v1451 + ((~(((v1452 ^ -1) | (-(v1452 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
      v1472[v1574] = v1469;
      int * v1474 = v1408->cache_tags;
      int v1577 = (int)((unsigned int)((int)((unsigned int)v1414 >> 2)) >> 1);
      v1474[v1553] = v1577;
      int * v1476 = v1408->cache_dirty;
      v1476[v1553] = 0;
      int * v1478 = v1408->cache_age;
      v1478[v1553] = 1;
      int * v1480 = v1408->cache_age;
      int v1481 = v1480[v1553];
      int v1482 = v1480[v1528];
      int v1583 = v1482 + ((int)((unsigned int)(v1482 - v1481) >> 31));
      v1480[v1528] = v1583;
      int * v1484 = v1408->cache_age;
      int v1485 = v1484[v1529];
      int v1585 = v1485 + ((int)((unsigned int)(v1485 - v1481) >> 31));
      v1484[v1529] = v1585;
      int * v1487 = v1408->cache_age;
      v1487[v1553] = 0;
      v1490 = v1553;
    }
    int * v1491 = v1408->cache_vals;
    int v1588 = v1490 * 2;
    int v1492 = v1491[v1588];
    int v1589 = (v1490 * 2) + 1;
    int v1493 = v1491[v1589];
    int v1590 = (((((int)((unsigned int)((int)((unsigned int)v1414 >> 2)) >> 1)) & 1) * 2) + ((((v1432 + ((~(((v1434 ^ -1) | (-(v1434 ^ -1))) >> 31)) & 2)) - (v1435 + ((~(((v1436 ^ -1) | (-(v1436 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
    v1491[v1590] = v1492;
    int * v1495 = v1408->cache_vals;
    int v1593 = ((((((int)((unsigned int)((int)((unsigned int)v1414 >> 2)) >> 1)) & 1) * 2) + ((((v1432 + ((~(((v1434 ^ -1) | (-(v1434 ^ -1))) >> 31)) & 2)) - (v1435 + ((~(((v1436 ^ -1) | (-(v1436 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
    v1495[v1593] = v1493;
    int * v1497 = v1408->cache_tags;
    int v1596 = ((((int)((unsigned int)((int)((unsigned int)v1414 >> 2)) >> 1)) & 1) * 2) + ((((v1432 + ((~(((v1434 ^ -1) | (-(v1434 ^ -1))) >> 31)) & 2)) - (v1435 + ((~(((v1436 ^ -1) | (-(v1436 ^ -1))) >> 31)) & 2))) >> 31) & 1);
    int v1597 = (int)((unsigned int)((int)((unsigned int)v1414 >> 2)) >> 1);
    v1497[v1596] = v1597;
    int * v1499 = v1408->cache_dirty;
    v1499[v1596] = 0;
    int * v1501 = v1408->cache_age;
    v1501[v1596] = 1;
    int * v1503 = v1408->cache_age;
    int v1504 = v1503[v1596];
    int v1505 = v1503[v1526];
    int v1603 = v1505 + ((int)((unsigned int)(v1505 - v1504) >> 31));
    v1503[v1526] = v1603;
    int * v1507 = v1408->cache_age;
    int v1508 = v1507[v1527];
    int v1605 = v1508 + ((int)((unsigned int)(v1508 - v1504) >> 31));
    v1507[v1527] = v1605;
    int * v1510 = v1408->cache_age;
    v1510[v1596] = 0;
    v1513 = v1596;
  }
  int v1608 = (v1513 * 2) + (((int)((unsigned int)v1414 >> 2)) & 1);
  int v1514 = v1420[v1608];
  int * v1515 = v1408->reg_ready;
  int v1610 = ((v1412 + ((v1409 - v1412) & (~((v1409 - v1412) >> 31)))) + 1) + ((100 ^ (((~(((v1418 ^ ((int)((unsigned int)((int)((unsigned int)v1414 >> 2)) >> 1))) | (-(v1418 ^ ((int)((unsigned int)((int)((unsigned int)v1414 >> 2)) >> 1))))) >> 31)) | (~(((v1419 ^ ((int)((unsigned int)((int)((unsigned int)v1414 >> 2)) >> 1))) | (-(v1419 ^ ((int)((unsigned int)((int)((unsigned int)v1414 >> 2)) >> 1))))) >> 31))) & 104)) ^ (((~(((v1416 ^ ((int)((unsigned int)((int)((unsigned int)v1414 >> 2)) >> 1))) | (-(v1416 ^ ((int)((unsigned int)((int)((unsigned int)v1414 >> 2)) >> 1))))) >> 31)) | (~(((v1417 ^ ((int)((unsigned int)((int)((unsigned int)v1414 >> 2)) >> 1))) | (-(v1417 ^ ((int)((unsigned int)((int)((unsigned int)v1414 >> 2)) >> 1))))) >> 31))) & (1 ^ (100 ^ (((~(((v1418 ^ ((int)((unsigned int)((int)((unsigned int)v1414 >> 2)) >> 1))) | (-(v1418 ^ ((int)((unsigned int)((int)((unsigned int)v1414 >> 2)) >> 1))))) >> 31)) | (~(((v1419 ^ ((int)((unsigned int)((int)((unsigned int)v1414 >> 2)) >> 1))) | (-(v1419 ^ ((int)((unsigned int)((int)((unsigned int)v1414 >> 2)) >> 1))))) >> 31))) & 104)))));
  v1515[10] = v1610;
  int * v1517 = v1408->regs;
  v1517[10] = v1514;
  struct StateT * v1519 = slot_26(v1408);
  return v1519;
}

struct StateT * slot_16(struct StateT * v901) {
  int * v902 = v901->saved_regs;
  int * v903 = v901->regs;
  int v904 = v903[13];
  v902[13] = v904;
  int v906 = v901->timer;
  int v921 = v906 + 1;
  v901->timer = v921;
  int * v908 = v901->reg_ready;
  int v909 = v908[13];
  int * v910 = v901->regs;
  int v911 = v910[13];
  int v924 = (v909 + ((v906 - v909) & (~((v906 - v909) >> 31)))) + 1;
  v908[13] = v924;
  int * v913 = v901->regs;
  int v926 = v911 + -1;
  v913[13] = v926;
  struct StateT * v915 = slot_17(v901);
  return v915;
}

struct StateT * slot_23(struct StateT * v1363) {
  int v1364 = v1363->timer;
  int v1375 = v1364 + 1;
  v1363->timer = v1375;
  int * v1366 = v1363->reg_ready;
  int v1367 = v1366[10];
  int * v1368 = v1363->regs;
  int v1369 = v1368[10];
  int v1379 = (v1367 + ((v1364 - v1367) & (~((v1364 - v1367) >> 31)))) + 1;
  v1366[10] = v1379;
  int * v1371 = v1363->regs;
  int v1381 = v1369 << 2;
  v1371[10] = v1381;
  struct StateT * v1373 = slot_24(v1363);
  return v1373;
}

struct StateT * slot_5(struct StateT * v279) {
  int v280 = v279->timer;
  int v392 = v280 + 1;
  v279->timer = v392;
  int * v282 = v279->reg_ready;
  int v283 = v282[12];
  int * v284 = v279->regs;
  int v285 = v284[12];
  int * v286 = v279->cache_tags;
  int v397 = (((int)((unsigned int)((int)((unsigned int)(v285 + 68) >> 2)) >> 1)) & 1) * 2;
  int v287 = v286[v397];
  int v398 = ((((int)((unsigned int)((int)((unsigned int)(v285 + 68) >> 2)) >> 1)) & 1) * 2) + 1;
  int v288 = v286[v398];
  int v399 = 4 + ((((int)((unsigned int)((int)((unsigned int)(v285 + 68) >> 2)) >> 1)) & 3) * 2);
  int v289 = v286[v399];
  int v400 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v285 + 68) >> 2)) >> 1)) & 3) * 2)) + 1;
  int v290 = v286[v400];
  int * v291 = v279->cache_vals;
  bool v401 = !(((~(((v287 ^ ((int)((unsigned int)((int)((unsigned int)(v285 + 68) >> 2)) >> 1))) | (-(v287 ^ ((int)((unsigned int)((int)((unsigned int)(v285 + 68) >> 2)) >> 1))))) >> 31)) | (~(((v288 ^ ((int)((unsigned int)((int)((unsigned int)(v285 + 68) >> 2)) >> 1))) | (-(v288 ^ ((int)((unsigned int)((int)((unsigned int)(v285 + 68) >> 2)) >> 1))))) >> 31))) == 0);
  int v384;
  if (v401) {
    int * v292 = v279->cache_age;
    int v403 = ((((int)((unsigned int)((int)((unsigned int)(v285 + 68) >> 2)) >> 1)) & 1) * 2) + ((~(((v288 ^ ((int)((unsigned int)((int)((unsigned int)(v285 + 68) >> 2)) >> 1))) | (-(v288 ^ ((int)((unsigned int)((int)((unsigned int)(v285 + 68) >> 2)) >> 1))))) >> 31)) & 1);
    int v293 = v292[v403];
    int v294 = v292[v397];
    int v404 = v294 + ((int)((unsigned int)(v294 - v293) >> 31));
    v292[v397] = v404;
    int * v296 = v279->cache_age;
    int v297 = v296[v398];
    int v406 = v297 + ((int)((unsigned int)(v297 - v293) >> 31));
    v296[v398] = v406;
    int * v299 = v279->cache_age;
    v299[v403] = 0;
    v384 = v403;
  } else {
    int * v302 = v279->cache_age;
    int v410 = (((int)((unsigned int)((int)((unsigned int)(v285 + 68) >> 2)) >> 1)) & 1) * 2;
    int v303 = v302[v410];
    int * v304 = v279->cache_tags;
    int v305 = v304[v410];
    int v306 = v302[v398];
    int v307 = v304[v398];
    bool v412 = !(((~(((v289 ^ ((int)((unsigned int)((int)((unsigned int)(v285 + 68) >> 2)) >> 1))) | (-(v289 ^ ((int)((unsigned int)((int)((unsigned int)(v285 + 68) >> 2)) >> 1))))) >> 31)) | (~(((v290 ^ ((int)((unsigned int)((int)((unsigned int)(v285 + 68) >> 2)) >> 1))) | (-(v290 ^ ((int)((unsigned int)((int)((unsigned int)(v285 + 68) >> 2)) >> 1))))) >> 31))) == 0);
    int v361;
    if (v412) {
      int * v308 = v279->cache_age;
      int v414 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v285 + 68) >> 2)) >> 1)) & 3) * 2)) + ((~(((v290 ^ ((int)((unsigned int)((int)((unsigned int)(v285 + 68) >> 2)) >> 1))) | (-(v290 ^ ((int)((unsigned int)((int)((unsigned int)(v285 + 68) >> 2)) >> 1))))) >> 31)) & 1);
      int v309 = v308[v414];
      int v310 = v308[v399];
      int v415 = v310 + ((int)((unsigned int)(v310 - v309) >> 31));
      v308[v399] = v415;
      int * v312 = v279->cache_age;
      int v313 = v312[v400];
      int v417 = v313 + ((int)((unsigned int)(v313 - v309) >> 31));
      v312[v400] = v417;
      int * v315 = v279->cache_age;
      v315[v414] = 0;
      v361 = v414;
    } else {
      int * v318 = v279->cache_age;
      int v421 = 4 + ((((int)((unsigned int)((int)((unsigned int)(v285 + 68) >> 2)) >> 1)) & 3) * 2);
      int v319 = v318[v421];
      int * v320 = v279->cache_tags;
      int v321 = v320[v421];
      int v322 = v318[v400];
      int v323 = v320[v400];
      int * v324 = v279->cache_dirty;
      int v424 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v285 + 68) >> 2)) >> 1)) & 3) * 2)) + ((((v319 + ((~(((v321 ^ -1) | (-(v321 ^ -1))) >> 31)) & 2)) - (v322 + ((~(((v323 ^ -1) | (-(v323 ^ -1))) >> 31)) & 2))) >> 31) & 1);
      int v325 = v324[v424];
      bool v425 = !(v325 == 0);
      if (v425) {
        int * v326 = v279->cache_tags;
        int v327 = v326[v424];
        int * v328 = v279->cache_vals;
        int v428 = ((4 + ((((int)((unsigned int)((int)((unsigned int)(v285 + 68) >> 2)) >> 1)) & 3) * 2)) + ((((v319 + ((~(((v321 ^ -1) | (-(v321 ^ -1))) >> 31)) & 2)) - (v322 + ((~(((v323 ^ -1) | (-(v323 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
        int v329 = v328[v428];
        int v429 = (((4 + ((((int)((unsigned int)((int)((unsigned int)(v285 + 68) >> 2)) >> 1)) & 3) * 2)) + ((((v319 + ((~(((v321 ^ -1) | (-(v321 ^ -1))) >> 31)) & 2)) - (v322 + ((~(((v323 ^ -1) | (-(v323 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
        int v330 = v328[v429];
        int * v331 = v279->mem;
        int v431 = v327 * 2;
        v331[v431] = v329;
        int * v333 = v279->mem;
        int v434 = (v327 * 2) + 1;
        v333[v434] = v330;
        ;
      } else {
        ;
      }
      int * v338 = v279->mem;
      int v439 = ((int)((unsigned int)((int)((unsigned int)(v285 + 68) >> 2)) >> 1)) * 2;
      int v339 = v338[v439];
      int v440 = (((int)((unsigned int)((int)((unsigned int)(v285 + 68) >> 2)) >> 1)) * 2) + 1;
      int v340 = v338[v440];
      int * v341 = v279->cache_vals;
      int v442 = ((4 + ((((int)((unsigned int)((int)((unsigned int)(v285 + 68) >> 2)) >> 1)) & 3) * 2)) + ((((v319 + ((~(((v321 ^ -1) | (-(v321 ^ -1))) >> 31)) & 2)) - (v322 + ((~(((v323 ^ -1) | (-(v323 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
      v341[v442] = v339;
      int * v343 = v279->cache_vals;
      int v445 = (((4 + ((((int)((unsigned int)((int)((unsigned int)(v285 + 68) >> 2)) >> 1)) & 3) * 2)) + ((((v319 + ((~(((v321 ^ -1) | (-(v321 ^ -1))) >> 31)) & 2)) - (v322 + ((~(((v323 ^ -1) | (-(v323 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
      v343[v445] = v340;
      int * v345 = v279->cache_tags;
      int v448 = (int)((unsigned int)((int)((unsigned int)(v285 + 68) >> 2)) >> 1);
      v345[v424] = v448;
      int * v347 = v279->cache_dirty;
      v347[v424] = 0;
      int * v349 = v279->cache_age;
      v349[v424] = 1;
      int * v351 = v279->cache_age;
      int v352 = v351[v424];
      int v353 = v351[v399];
      int v454 = v353 + ((int)((unsigned int)(v353 - v352) >> 31));
      v351[v399] = v454;
      int * v355 = v279->cache_age;
      int v356 = v355[v400];
      int v456 = v356 + ((int)((unsigned int)(v356 - v352) >> 31));
      v355[v400] = v456;
      int * v358 = v279->cache_age;
      v358[v424] = 0;
      v361 = v424;
    }
    int * v362 = v279->cache_vals;
    int v459 = v361 * 2;
    int v363 = v362[v459];
    int v460 = (v361 * 2) + 1;
    int v364 = v362[v460];
    int v461 = (((((int)((unsigned int)((int)((unsigned int)(v285 + 68) >> 2)) >> 1)) & 1) * 2) + ((((v303 + ((~(((v305 ^ -1) | (-(v305 ^ -1))) >> 31)) & 2)) - (v306 + ((~(((v307 ^ -1) | (-(v307 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
    v362[v461] = v363;
    int * v366 = v279->cache_vals;
    int v464 = ((((((int)((unsigned int)((int)((unsigned int)(v285 + 68) >> 2)) >> 1)) & 1) * 2) + ((((v303 + ((~(((v305 ^ -1) | (-(v305 ^ -1))) >> 31)) & 2)) - (v306 + ((~(((v307 ^ -1) | (-(v307 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
    v366[v464] = v364;
    int * v368 = v279->cache_tags;
    int v467 = ((((int)((unsigned int)((int)((unsigned int)(v285 + 68) >> 2)) >> 1)) & 1) * 2) + ((((v303 + ((~(((v305 ^ -1) | (-(v305 ^ -1))) >> 31)) & 2)) - (v306 + ((~(((v307 ^ -1) | (-(v307 ^ -1))) >> 31)) & 2))) >> 31) & 1);
    int v468 = (int)((unsigned int)((int)((unsigned int)(v285 + 68) >> 2)) >> 1);
    v368[v467] = v468;
    int * v370 = v279->cache_dirty;
    v370[v467] = 0;
    int * v372 = v279->cache_age;
    v372[v467] = 1;
    int * v374 = v279->cache_age;
    int v375 = v374[v467];
    int v376 = v374[v397];
    int v474 = v376 + ((int)((unsigned int)(v376 - v375) >> 31));
    v374[v397] = v474;
    int * v378 = v279->cache_age;
    int v379 = v378[v398];
    int v476 = v379 + ((int)((unsigned int)(v379 - v375) >> 31));
    v378[v398] = v476;
    int * v381 = v279->cache_age;
    v381[v467] = 0;
    v384 = v467;
  }
  int v479 = (v384 * 2) + (((int)((unsigned int)(v285 + 68) >> 2)) & 1);
  int v385 = v291[v479];
  int * v386 = v279->reg_ready;
  int v481 = ((v283 + ((v280 - v283) & (~((v280 - v283) >> 31)))) + 1) + ((100 ^ (((~(((v289 ^ ((int)((unsigned int)((int)((unsigned int)(v285 + 68) >> 2)) >> 1))) | (-(v289 ^ ((int)((unsigned int)((int)((unsigned int)(v285 + 68) >> 2)) >> 1))))) >> 31)) | (~(((v290 ^ ((int)((unsigned int)((int)((unsigned int)(v285 + 68) >> 2)) >> 1))) | (-(v290 ^ ((int)((unsigned int)((int)((unsigned int)(v285 + 68) >> 2)) >> 1))))) >> 31))) & 104)) ^ (((~(((v287 ^ ((int)((unsigned int)((int)((unsigned int)(v285 + 68) >> 2)) >> 1))) | (-(v287 ^ ((int)((unsigned int)((int)((unsigned int)(v285 + 68) >> 2)) >> 1))))) >> 31)) | (~(((v288 ^ ((int)((unsigned int)((int)((unsigned int)(v285 + 68) >> 2)) >> 1))) | (-(v288 ^ ((int)((unsigned int)((int)((unsigned int)(v285 + 68) >> 2)) >> 1))))) >> 31))) & (1 ^ (100 ^ (((~(((v289 ^ ((int)((unsigned int)((int)((unsigned int)(v285 + 68) >> 2)) >> 1))) | (-(v289 ^ ((int)((unsigned int)((int)((unsigned int)(v285 + 68) >> 2)) >> 1))))) >> 31)) | (~(((v290 ^ ((int)((unsigned int)((int)((unsigned int)(v285 + 68) >> 2)) >> 1))) | (-(v290 ^ ((int)((unsigned int)((int)((unsigned int)(v285 + 68) >> 2)) >> 1))))) >> 31))) & 104)))));
  v386[12] = v481;
  int * v388 = v279->regs;
  v388[12] = v385;
  struct StateT * v390 = slot_6(v279);
  return v390;
}

struct StateT * slot_2(struct StateT * v225) {
  int v226 = v225->timer;
  int v230 = v226 + 1;
  v225->timer = v230;
  struct StateT * v228 = slot_3(v225);
  return v228;
}

struct StateT * slot_7(struct StateT * v509) {
  int v510 = v509->timer;
  int v521 = v510 + 1;
  v509->timer = v521;
  int * v512 = v509->reg_ready;
  int v513 = v512[14];
  int * v514 = v509->regs;
  int v515 = v514[14];
  int v525 = (v513 + ((v510 - v513) & (~((v510 - v513) >> 31)))) + 1;
  v512[14] = v525;
  int * v517 = v509->regs;
  int v527 = v515 + 72;
  v517[14] = v527;
  struct StateT * v519 = slot_8(v509);
  return v519;
}

struct StateT * slot_21(struct StateT * v1304) {
  int * v1305 = v1304->saved_regs;
  int * v1306 = v1304->regs;
  int v1307 = v1306[10];
  v1305[10] = v1307;
  int v1309 = v1304->timer;
  int v1321 = v1309 + 1;
  v1304->timer = v1321;
  int * v1311 = v1304->reg_ready;
  v1311[10] = v1321;
  int * v1313 = v1304->regs;
  v1313[10] = 0;
  struct StateT * v1315 = slot_22(v1304);
  return v1315;
}

struct StateT * slot_31(struct StateT * v1715) {
  int * v1716 = v1715->saved_regs;
  int * v1717 = v1715->regs;
  int v1718 = v1717[10];
  v1716[10] = v1718;
  int v1720 = v1715->timer;
  int v1735 = v1720 + 1;
  v1715->timer = v1735;
  int * v1722 = v1715->reg_ready;
  int v1723 = v1722[10];
  int * v1724 = v1715->regs;
  int v1725 = v1724[10];
  int v1738 = (v1723 + ((v1720 - v1723) & (~((v1720 - v1723) >> 31)))) + 1;
  v1722[10] = v1738;
  int * v1727 = v1715->regs;
  int v1740 = v1725 << 2;
  v1727[10] = v1740;
  struct StateT * v1729 = slot_32(v1715);
  return v1729;
}

struct StateT * slot_3(struct StateT * v233) {
  int * v234 = v233->saved_regs;
  int * v235 = v233->regs;
  int v236 = v235[13];
  v234[13] = v236;
  int v238 = v233->timer;
  int v250 = v238 + 1;
  v233->timer = v250;
  int * v240 = v233->reg_ready;
  v240[13] = v250;
  int * v242 = v233->regs;
  v242[13] = 0;
  struct StateT * v244 = slot_4(v233);
  return v244;
}

struct StateT * slot_26(struct StateT * v1615) {
  int v1616 = v1615->timer;
  int v1629 = v1616 + 1;
  v1615->timer = v1629;
  int * v1618 = v1615->reg_ready;
  int v1619 = v1618[12];
  int * v1620 = v1615->regs;
  int v1621 = v1620[12];
  int v1622 = v1618[10];
  int v1623 = v1620[10];
  int v1634 = (v1622 + (((v1619 + ((v1616 - v1619) & (~((v1616 - v1619) >> 31)))) - v1622) & (~(((v1619 + ((v1616 - v1619) & (~((v1616 - v1619) >> 31)))) - v1622) >> 31)))) + 1;
  v1618[12] = v1634;
  int * v1625 = v1615->regs;
  int v1636 = v1621 & v1623;
  v1625[12] = v1636;
  struct StateT * v1627 = slot_27(v1615);
  return v1627;
}

struct StateT * slot_10(struct StateT * v582) {
  int v583 = v582->timer;
  int v695 = v583 + 1;
  v582->timer = v695;
  int * v585 = v582->reg_ready;
  int v586 = v585[10];
  int * v587 = v582->regs;
  int v588 = v587[10];
  int * v589 = v582->cache_tags;
  int v700 = (((int)((unsigned int)((int)((unsigned int)v588 >> 2)) >> 1)) & 1) * 2;
  int v590 = v589[v700];
  int v701 = ((((int)((unsigned int)((int)((unsigned int)v588 >> 2)) >> 1)) & 1) * 2) + 1;
  int v591 = v589[v701];
  int v702 = 4 + ((((int)((unsigned int)((int)((unsigned int)v588 >> 2)) >> 1)) & 3) * 2);
  int v592 = v589[v702];
  int v703 = (4 + ((((int)((unsigned int)((int)((unsigned int)v588 >> 2)) >> 1)) & 3) * 2)) + 1;
  int v593 = v589[v703];
  int * v594 = v582->cache_vals;
  bool v704 = !(((~(((v590 ^ ((int)((unsigned int)((int)((unsigned int)v588 >> 2)) >> 1))) | (-(v590 ^ ((int)((unsigned int)((int)((unsigned int)v588 >> 2)) >> 1))))) >> 31)) | (~(((v591 ^ ((int)((unsigned int)((int)((unsigned int)v588 >> 2)) >> 1))) | (-(v591 ^ ((int)((unsigned int)((int)((unsigned int)v588 >> 2)) >> 1))))) >> 31))) == 0);
  int v687;
  if (v704) {
    int * v595 = v582->cache_age;
    int v706 = ((((int)((unsigned int)((int)((unsigned int)v588 >> 2)) >> 1)) & 1) * 2) + ((~(((v591 ^ ((int)((unsigned int)((int)((unsigned int)v588 >> 2)) >> 1))) | (-(v591 ^ ((int)((unsigned int)((int)((unsigned int)v588 >> 2)) >> 1))))) >> 31)) & 1);
    int v596 = v595[v706];
    int v597 = v595[v700];
    int v707 = v597 + ((int)((unsigned int)(v597 - v596) >> 31));
    v595[v700] = v707;
    int * v599 = v582->cache_age;
    int v600 = v599[v701];
    int v709 = v600 + ((int)((unsigned int)(v600 - v596) >> 31));
    v599[v701] = v709;
    int * v602 = v582->cache_age;
    v602[v706] = 0;
    v687 = v706;
  } else {
    int * v605 = v582->cache_age;
    int v713 = (((int)((unsigned int)((int)((unsigned int)v588 >> 2)) >> 1)) & 1) * 2;
    int v606 = v605[v713];
    int * v607 = v582->cache_tags;
    int v608 = v607[v713];
    int v609 = v605[v701];
    int v610 = v607[v701];
    bool v715 = !(((~(((v592 ^ ((int)((unsigned int)((int)((unsigned int)v588 >> 2)) >> 1))) | (-(v592 ^ ((int)((unsigned int)((int)((unsigned int)v588 >> 2)) >> 1))))) >> 31)) | (~(((v593 ^ ((int)((unsigned int)((int)((unsigned int)v588 >> 2)) >> 1))) | (-(v593 ^ ((int)((unsigned int)((int)((unsigned int)v588 >> 2)) >> 1))))) >> 31))) == 0);
    int v664;
    if (v715) {
      int * v611 = v582->cache_age;
      int v717 = (4 + ((((int)((unsigned int)((int)((unsigned int)v588 >> 2)) >> 1)) & 3) * 2)) + ((~(((v593 ^ ((int)((unsigned int)((int)((unsigned int)v588 >> 2)) >> 1))) | (-(v593 ^ ((int)((unsigned int)((int)((unsigned int)v588 >> 2)) >> 1))))) >> 31)) & 1);
      int v612 = v611[v717];
      int v613 = v611[v702];
      int v718 = v613 + ((int)((unsigned int)(v613 - v612) >> 31));
      v611[v702] = v718;
      int * v615 = v582->cache_age;
      int v616 = v615[v703];
      int v720 = v616 + ((int)((unsigned int)(v616 - v612) >> 31));
      v615[v703] = v720;
      int * v618 = v582->cache_age;
      v618[v717] = 0;
      v664 = v717;
    } else {
      int * v621 = v582->cache_age;
      int v724 = 4 + ((((int)((unsigned int)((int)((unsigned int)v588 >> 2)) >> 1)) & 3) * 2);
      int v622 = v621[v724];
      int * v623 = v582->cache_tags;
      int v624 = v623[v724];
      int v625 = v621[v703];
      int v626 = v623[v703];
      int * v627 = v582->cache_dirty;
      int v727 = (4 + ((((int)((unsigned int)((int)((unsigned int)v588 >> 2)) >> 1)) & 3) * 2)) + ((((v622 + ((~(((v624 ^ -1) | (-(v624 ^ -1))) >> 31)) & 2)) - (v625 + ((~(((v626 ^ -1) | (-(v626 ^ -1))) >> 31)) & 2))) >> 31) & 1);
      int v628 = v627[v727];
      bool v728 = !(v628 == 0);
      if (v728) {
        int * v629 = v582->cache_tags;
        int v630 = v629[v727];
        int * v631 = v582->cache_vals;
        int v731 = ((4 + ((((int)((unsigned int)((int)((unsigned int)v588 >> 2)) >> 1)) & 3) * 2)) + ((((v622 + ((~(((v624 ^ -1) | (-(v624 ^ -1))) >> 31)) & 2)) - (v625 + ((~(((v626 ^ -1) | (-(v626 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
        int v632 = v631[v731];
        int v732 = (((4 + ((((int)((unsigned int)((int)((unsigned int)v588 >> 2)) >> 1)) & 3) * 2)) + ((((v622 + ((~(((v624 ^ -1) | (-(v624 ^ -1))) >> 31)) & 2)) - (v625 + ((~(((v626 ^ -1) | (-(v626 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
        int v633 = v631[v732];
        int * v634 = v582->mem;
        int v734 = v630 * 2;
        v634[v734] = v632;
        int * v636 = v582->mem;
        int v737 = (v630 * 2) + 1;
        v636[v737] = v633;
        ;
      } else {
        ;
      }
      int * v641 = v582->mem;
      int v742 = ((int)((unsigned int)((int)((unsigned int)v588 >> 2)) >> 1)) * 2;
      int v642 = v641[v742];
      int v743 = (((int)((unsigned int)((int)((unsigned int)v588 >> 2)) >> 1)) * 2) + 1;
      int v643 = v641[v743];
      int * v644 = v582->cache_vals;
      int v745 = ((4 + ((((int)((unsigned int)((int)((unsigned int)v588 >> 2)) >> 1)) & 3) * 2)) + ((((v622 + ((~(((v624 ^ -1) | (-(v624 ^ -1))) >> 31)) & 2)) - (v625 + ((~(((v626 ^ -1) | (-(v626 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
      v644[v745] = v642;
      int * v646 = v582->cache_vals;
      int v748 = (((4 + ((((int)((unsigned int)((int)((unsigned int)v588 >> 2)) >> 1)) & 3) * 2)) + ((((v622 + ((~(((v624 ^ -1) | (-(v624 ^ -1))) >> 31)) & 2)) - (v625 + ((~(((v626 ^ -1) | (-(v626 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
      v646[v748] = v643;
      int * v648 = v582->cache_tags;
      int v751 = (int)((unsigned int)((int)((unsigned int)v588 >> 2)) >> 1);
      v648[v727] = v751;
      int * v650 = v582->cache_dirty;
      v650[v727] = 0;
      int * v652 = v582->cache_age;
      v652[v727] = 1;
      int * v654 = v582->cache_age;
      int v655 = v654[v727];
      int v656 = v654[v702];
      int v757 = v656 + ((int)((unsigned int)(v656 - v655) >> 31));
      v654[v702] = v757;
      int * v658 = v582->cache_age;
      int v659 = v658[v703];
      int v759 = v659 + ((int)((unsigned int)(v659 - v655) >> 31));
      v658[v703] = v759;
      int * v661 = v582->cache_age;
      v661[v727] = 0;
      v664 = v727;
    }
    int * v665 = v582->cache_vals;
    int v762 = v664 * 2;
    int v666 = v665[v762];
    int v763 = (v664 * 2) + 1;
    int v667 = v665[v763];
    int v764 = (((((int)((unsigned int)((int)((unsigned int)v588 >> 2)) >> 1)) & 1) * 2) + ((((v606 + ((~(((v608 ^ -1) | (-(v608 ^ -1))) >> 31)) & 2)) - (v609 + ((~(((v610 ^ -1) | (-(v610 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
    v665[v764] = v666;
    int * v669 = v582->cache_vals;
    int v767 = ((((((int)((unsigned int)((int)((unsigned int)v588 >> 2)) >> 1)) & 1) * 2) + ((((v606 + ((~(((v608 ^ -1) | (-(v608 ^ -1))) >> 31)) & 2)) - (v609 + ((~(((v610 ^ -1) | (-(v610 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
    v669[v767] = v667;
    int * v671 = v582->cache_tags;
    int v770 = ((((int)((unsigned int)((int)((unsigned int)v588 >> 2)) >> 1)) & 1) * 2) + ((((v606 + ((~(((v608 ^ -1) | (-(v608 ^ -1))) >> 31)) & 2)) - (v609 + ((~(((v610 ^ -1) | (-(v610 ^ -1))) >> 31)) & 2))) >> 31) & 1);
    int v771 = (int)((unsigned int)((int)((unsigned int)v588 >> 2)) >> 1);
    v671[v770] = v771;
    int * v673 = v582->cache_dirty;
    v673[v770] = 0;
    int * v675 = v582->cache_age;
    v675[v770] = 1;
    int * v677 = v582->cache_age;
    int v678 = v677[v770];
    int v679 = v677[v700];
    int v777 = v679 + ((int)((unsigned int)(v679 - v678) >> 31));
    v677[v700] = v777;
    int * v681 = v582->cache_age;
    int v682 = v681[v701];
    int v779 = v682 + ((int)((unsigned int)(v682 - v678) >> 31));
    v681[v701] = v779;
    int * v684 = v582->cache_age;
    v684[v770] = 0;
    v687 = v770;
  }
  int v782 = (v687 * 2) + (((int)((unsigned int)v588 >> 2)) & 1);
  int v688 = v594[v782];
  int * v689 = v582->reg_ready;
  int v784 = ((v586 + ((v583 - v586) & (~((v583 - v586) >> 31)))) + 1) + ((100 ^ (((~(((v592 ^ ((int)((unsigned int)((int)((unsigned int)v588 >> 2)) >> 1))) | (-(v592 ^ ((int)((unsigned int)((int)((unsigned int)v588 >> 2)) >> 1))))) >> 31)) | (~(((v593 ^ ((int)((unsigned int)((int)((unsigned int)v588 >> 2)) >> 1))) | (-(v593 ^ ((int)((unsigned int)((int)((unsigned int)v588 >> 2)) >> 1))))) >> 31))) & 104)) ^ (((~(((v590 ^ ((int)((unsigned int)((int)((unsigned int)v588 >> 2)) >> 1))) | (-(v590 ^ ((int)((unsigned int)((int)((unsigned int)v588 >> 2)) >> 1))))) >> 31)) | (~(((v591 ^ ((int)((unsigned int)((int)((unsigned int)v588 >> 2)) >> 1))) | (-(v591 ^ ((int)((unsigned int)((int)((unsigned int)v588 >> 2)) >> 1))))) >> 31))) & (1 ^ (100 ^ (((~(((v592 ^ ((int)((unsigned int)((int)((unsigned int)v588 >> 2)) >> 1))) | (-(v592 ^ ((int)((unsigned int)((int)((unsigned int)v588 >> 2)) >> 1))))) >> 31)) | (~(((v593 ^ ((int)((unsigned int)((int)((unsigned int)v588 >> 2)) >> 1))) | (-(v593 ^ ((int)((unsigned int)((int)((unsigned int)v588 >> 2)) >> 1))))) >> 31))) & 104)))));
  v689[10] = v784;
  int * v691 = v582->regs;
  v691[10] = v688;
  struct StateT * v693 = slot_11(v582);
  return v693;
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

struct StateT * slot_19(struct StateT * v977) {
  int v978 = v977->timer;
  int v982 = v978 + 1;
  v977->timer = v982;
  struct StateT * v980 = slot_21(v977);
  return v980;
}

struct StateT * slot_13(struct StateT * v888) {
  int v889 = v888->timer;
  int v892 = v889 + 1;
  v888->timer = v892;
  return v888;
}

struct StateT * slot_24(struct StateT * v1384) {
  int v1385 = v1384->timer;
  int v1398 = v1385 + 1;
  v1384->timer = v1398;
  int * v1387 = v1384->reg_ready;
  int v1388 = v1387[14];
  int * v1389 = v1384->regs;
  int v1390 = v1389[14];
  int v1391 = v1387[10];
  int v1392 = v1389[10];
  int v1403 = (v1391 + (((v1388 + ((v1385 - v1388) & (~((v1385 - v1388) >> 31)))) - v1391) & (~(((v1388 + ((v1385 - v1388) & (~((v1385 - v1388) >> 31)))) - v1391) >> 31)))) + 1;
  v1387[10] = v1403;
  int * v1394 = v1384->regs;
  int v1405 = v1390 + v1392;
  v1394[10] = v1405;
  struct StateT * v1396 = slot_25(v1384);
  return v1396;
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

struct StateT * slot_14(struct StateT * v893) {
  int v894 = v893->timer;
  int v898 = v894 + 1;
  v893->timer = v898;
  struct StateT * v896 = slot_16(v893);
  return v896;
}

struct StateT * slot_28(struct StateT * v1647) {
  int * v1648 = v1647->saved_regs;
  int * v1649 = v1647->regs;
  int v1650 = v1649[13];
  v1648[13] = v1650;
  int v1652 = v1647->timer;
  int v1667 = v1652 + 1;
  v1647->timer = v1667;
  int * v1654 = v1647->reg_ready;
  int v1655 = v1654[13];
  int * v1656 = v1647->regs;
  int v1657 = v1656[13];
  int v1670 = (v1655 + ((v1652 - v1655) & (~((v1652 - v1655) >> 31)))) + 1;
  v1654[13] = v1670;
  int * v1659 = v1647->regs;
  int v1672 = v1657 + -1;
  v1659[13] = v1672;
  struct StateT * v1661 = slot_29(v1647);
  return v1661;
}

struct StateT * slot_32(struct StateT * v1743) {
  int v1744 = v1743->timer;
  int v1757 = v1744 + 1;
  v1743->timer = v1757;
  int * v1746 = v1743->reg_ready;
  int v1747 = v1746[14];
  int * v1748 = v1743->regs;
  int v1749 = v1748[14];
  int v1750 = v1746[10];
  int v1751 = v1748[10];
  int v1762 = (v1750 + (((v1747 + ((v1744 - v1747) & (~((v1744 - v1747) >> 31)))) - v1750) & (~(((v1747 + ((v1744 - v1747) & (~((v1744 - v1747) >> 31)))) - v1750) >> 31)))) + 1;
  v1746[10] = v1762;
  int * v1753 = v1743->regs;
  int v1764 = v1749 + v1751;
  v1753[10] = v1764;
  struct StateT * v1755 = slot_33(v1743);
  return v1755;
}

struct StateT * slot_17(struct StateT * v929) {
  int * v930 = v929->saved_regs;
  int v931 = v930[13];
  bool v949 = !(v931 == 0);
  struct StateT * v945;
  if (v949) {
    int v932 = v929->timer;
    int v950 = v932 + 15;
    v929->timer = v950;
    int * v934 = v929->saved_regs;
    int v935 = v934[13];
    int * v936 = v929->regs;
    v936[13] = v935;
    int * v938 = v929->reg_ready;
    int v939 = v929->timer;
    v938[13] = v939;
    struct StateT * v941 = slot_18(v929);
    v945 = v941;
  } else {
    struct StateT * v943 = slot_19(v929);
    v945 = v943;
  }
  return v945;
}

struct StateT * slot_20(struct StateT * v985) {
  int v986 = v985->timer;
  int v1159 = v986 + 1;
  v985->timer = v1159;
  int * v988 = v985->reg_ready;
  int * v990 = v985->regs;
  int v991 = v990[10];
  int v993 = v990[12];
  int * v994 = v985->cache_tags;
  int v1165 = (((int)((unsigned int)((int)((unsigned int)(v991 + 68) >> 2)) >> 1)) & 1) * 2;
  int v995 = v994[v1165];
  int v1166 = ((((int)((unsigned int)((int)((unsigned int)(v991 + 68) >> 2)) >> 1)) & 1) * 2) + 1;
  int v996 = v994[v1166];
  int v1167 = 4 + ((((int)((unsigned int)((int)((unsigned int)(v991 + 68) >> 2)) >> 1)) & 3) * 2);
  int v997 = v994[v1167];
  int v1168 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v991 + 68) >> 2)) >> 1)) & 3) * 2)) + 1;
  int v998 = v994[v1168];
  int v999 = v985->timer;
  int v1169 = v999 + ((100 ^ (((~(((v997 ^ ((int)((unsigned int)((int)((unsigned int)(v991 + 68) >> 2)) >> 1))) | (-(v997 ^ ((int)((unsigned int)((int)((unsigned int)(v991 + 68) >> 2)) >> 1))))) >> 31)) | (~(((v998 ^ ((int)((unsigned int)((int)((unsigned int)(v991 + 68) >> 2)) >> 1))) | (-(v998 ^ ((int)((unsigned int)((int)((unsigned int)(v991 + 68) >> 2)) >> 1))))) >> 31))) & 104)) ^ (((~(((v995 ^ ((int)((unsigned int)((int)((unsigned int)(v991 + 68) >> 2)) >> 1))) | (-(v995 ^ ((int)((unsigned int)((int)((unsigned int)(v991 + 68) >> 2)) >> 1))))) >> 31)) | (~(((v996 ^ ((int)((unsigned int)((int)((unsigned int)(v991 + 68) >> 2)) >> 1))) | (-(v996 ^ ((int)((unsigned int)((int)((unsigned int)(v991 + 68) >> 2)) >> 1))))) >> 31))) & (1 ^ (100 ^ (((~(((v997 ^ ((int)((unsigned int)((int)((unsigned int)(v991 + 68) >> 2)) >> 1))) | (-(v997 ^ ((int)((unsigned int)((int)((unsigned int)(v991 + 68) >> 2)) >> 1))))) >> 31)) | (~(((v998 ^ ((int)((unsigned int)((int)((unsigned int)(v991 + 68) >> 2)) >> 1))) | (-(v998 ^ ((int)((unsigned int)((int)((unsigned int)(v991 + 68) >> 2)) >> 1))))) >> 31))) & 104)))));
  v985->timer = v1169;
  bool v1170 = !(((~(((v995 ^ ((int)((unsigned int)((int)((unsigned int)(v991 + 68) >> 2)) >> 1))) | (-(v995 ^ ((int)((unsigned int)((int)((unsigned int)(v991 + 68) >> 2)) >> 1))))) >> 31)) | (~(((v996 ^ ((int)((unsigned int)((int)((unsigned int)(v991 + 68) >> 2)) >> 1))) | (-(v996 ^ ((int)((unsigned int)((int)((unsigned int)(v991 + 68) >> 2)) >> 1))))) >> 31))) == 0);
  int v1093;
  if (v1170) {
    int * v1001 = v985->cache_age;
    int v1172 = ((((int)((unsigned int)((int)((unsigned int)(v991 + 68) >> 2)) >> 1)) & 1) * 2) + ((~(((v996 ^ ((int)((unsigned int)((int)((unsigned int)(v991 + 68) >> 2)) >> 1))) | (-(v996 ^ ((int)((unsigned int)((int)((unsigned int)(v991 + 68) >> 2)) >> 1))))) >> 31)) & 1);
    int v1002 = v1001[v1172];
    int v1003 = v1001[v1165];
    int v1173 = v1003 + ((int)((unsigned int)(v1003 - v1002) >> 31));
    v1001[v1165] = v1173;
    int * v1005 = v985->cache_age;
    int v1006 = v1005[v1166];
    int v1175 = v1006 + ((int)((unsigned int)(v1006 - v1002) >> 31));
    v1005[v1166] = v1175;
    int * v1008 = v985->cache_age;
    v1008[v1172] = 0;
    v1093 = v1172;
  } else {
    int * v1011 = v985->cache_age;
    int v1179 = (((int)((unsigned int)((int)((unsigned int)(v991 + 68) >> 2)) >> 1)) & 1) * 2;
    int v1012 = v1011[v1179];
    int * v1013 = v985->cache_tags;
    int v1014 = v1013[v1179];
    int v1015 = v1011[v1166];
    int v1016 = v1013[v1166];
    bool v1181 = !(((~(((v997 ^ ((int)((unsigned int)((int)((unsigned int)(v991 + 68) >> 2)) >> 1))) | (-(v997 ^ ((int)((unsigned int)((int)((unsigned int)(v991 + 68) >> 2)) >> 1))))) >> 31)) | (~(((v998 ^ ((int)((unsigned int)((int)((unsigned int)(v991 + 68) >> 2)) >> 1))) | (-(v998 ^ ((int)((unsigned int)((int)((unsigned int)(v991 + 68) >> 2)) >> 1))))) >> 31))) == 0);
    int v1070;
    if (v1181) {
      int * v1017 = v985->cache_age;
      int v1183 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v991 + 68) >> 2)) >> 1)) & 3) * 2)) + ((~(((v998 ^ ((int)((unsigned int)((int)((unsigned int)(v991 + 68) >> 2)) >> 1))) | (-(v998 ^ ((int)((unsigned int)((int)((unsigned int)(v991 + 68) >> 2)) >> 1))))) >> 31)) & 1);
      int v1018 = v1017[v1183];
      int v1019 = v1017[v1167];
      int v1184 = v1019 + ((int)((unsigned int)(v1019 - v1018) >> 31));
      v1017[v1167] = v1184;
      int * v1021 = v985->cache_age;
      int v1022 = v1021[v1168];
      int v1186 = v1022 + ((int)((unsigned int)(v1022 - v1018) >> 31));
      v1021[v1168] = v1186;
      int * v1024 = v985->cache_age;
      v1024[v1183] = 0;
      v1070 = v1183;
    } else {
      int * v1027 = v985->cache_age;
      int v1190 = 4 + ((((int)((unsigned int)((int)((unsigned int)(v991 + 68) >> 2)) >> 1)) & 3) * 2);
      int v1028 = v1027[v1190];
      int * v1029 = v985->cache_tags;
      int v1030 = v1029[v1190];
      int v1031 = v1027[v1168];
      int v1032 = v1029[v1168];
      int * v1033 = v985->cache_dirty;
      int v1193 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v991 + 68) >> 2)) >> 1)) & 3) * 2)) + ((((v1028 + ((~(((v1030 ^ -1) | (-(v1030 ^ -1))) >> 31)) & 2)) - (v1031 + ((~(((v1032 ^ -1) | (-(v1032 ^ -1))) >> 31)) & 2))) >> 31) & 1);
      int v1034 = v1033[v1193];
      bool v1194 = !(v1034 == 0);
      if (v1194) {
        int * v1035 = v985->cache_tags;
        int v1036 = v1035[v1193];
        int * v1037 = v985->cache_vals;
        int v1197 = ((4 + ((((int)((unsigned int)((int)((unsigned int)(v991 + 68) >> 2)) >> 1)) & 3) * 2)) + ((((v1028 + ((~(((v1030 ^ -1) | (-(v1030 ^ -1))) >> 31)) & 2)) - (v1031 + ((~(((v1032 ^ -1) | (-(v1032 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
        int v1038 = v1037[v1197];
        int v1198 = (((4 + ((((int)((unsigned int)((int)((unsigned int)(v991 + 68) >> 2)) >> 1)) & 3) * 2)) + ((((v1028 + ((~(((v1030 ^ -1) | (-(v1030 ^ -1))) >> 31)) & 2)) - (v1031 + ((~(((v1032 ^ -1) | (-(v1032 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
        int v1039 = v1037[v1198];
        int * v1040 = v985->mem;
        int v1200 = v1036 * 2;
        v1040[v1200] = v1038;
        int * v1042 = v985->mem;
        int v1203 = (v1036 * 2) + 1;
        v1042[v1203] = v1039;
        ;
      } else {
        ;
      }
      int * v1047 = v985->mem;
      int v1208 = ((int)((unsigned int)((int)((unsigned int)(v991 + 68) >> 2)) >> 1)) * 2;
      int v1048 = v1047[v1208];
      int v1209 = (((int)((unsigned int)((int)((unsigned int)(v991 + 68) >> 2)) >> 1)) * 2) + 1;
      int v1049 = v1047[v1209];
      int * v1050 = v985->cache_vals;
      int v1211 = ((4 + ((((int)((unsigned int)((int)((unsigned int)(v991 + 68) >> 2)) >> 1)) & 3) * 2)) + ((((v1028 + ((~(((v1030 ^ -1) | (-(v1030 ^ -1))) >> 31)) & 2)) - (v1031 + ((~(((v1032 ^ -1) | (-(v1032 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
      v1050[v1211] = v1048;
      int * v1052 = v985->cache_vals;
      int v1214 = (((4 + ((((int)((unsigned int)((int)((unsigned int)(v991 + 68) >> 2)) >> 1)) & 3) * 2)) + ((((v1028 + ((~(((v1030 ^ -1) | (-(v1030 ^ -1))) >> 31)) & 2)) - (v1031 + ((~(((v1032 ^ -1) | (-(v1032 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
      v1052[v1214] = v1049;
      int * v1054 = v985->cache_tags;
      int v1217 = (int)((unsigned int)((int)((unsigned int)(v991 + 68) >> 2)) >> 1);
      v1054[v1193] = v1217;
      int * v1056 = v985->cache_dirty;
      v1056[v1193] = 0;
      int * v1058 = v985->cache_age;
      v1058[v1193] = 1;
      int * v1060 = v985->cache_age;
      int v1061 = v1060[v1193];
      int v1062 = v1060[v1167];
      int v1223 = v1062 + ((int)((unsigned int)(v1062 - v1061) >> 31));
      v1060[v1167] = v1223;
      int * v1064 = v985->cache_age;
      int v1065 = v1064[v1168];
      int v1225 = v1065 + ((int)((unsigned int)(v1065 - v1061) >> 31));
      v1064[v1168] = v1225;
      int * v1067 = v985->cache_age;
      v1067[v1193] = 0;
      v1070 = v1193;
    }
    int * v1071 = v985->cache_vals;
    int v1228 = v1070 * 2;
    int v1072 = v1071[v1228];
    int v1229 = (v1070 * 2) + 1;
    int v1073 = v1071[v1229];
    int v1230 = (((((int)((unsigned int)((int)((unsigned int)(v991 + 68) >> 2)) >> 1)) & 1) * 2) + ((((v1012 + ((~(((v1014 ^ -1) | (-(v1014 ^ -1))) >> 31)) & 2)) - (v1015 + ((~(((v1016 ^ -1) | (-(v1016 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
    v1071[v1230] = v1072;
    int * v1075 = v985->cache_vals;
    int v1233 = ((((((int)((unsigned int)((int)((unsigned int)(v991 + 68) >> 2)) >> 1)) & 1) * 2) + ((((v1012 + ((~(((v1014 ^ -1) | (-(v1014 ^ -1))) >> 31)) & 2)) - (v1015 + ((~(((v1016 ^ -1) | (-(v1016 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
    v1075[v1233] = v1073;
    int * v1077 = v985->cache_tags;
    int v1236 = ((((int)((unsigned int)((int)((unsigned int)(v991 + 68) >> 2)) >> 1)) & 1) * 2) + ((((v1012 + ((~(((v1014 ^ -1) | (-(v1014 ^ -1))) >> 31)) & 2)) - (v1015 + ((~(((v1016 ^ -1) | (-(v1016 ^ -1))) >> 31)) & 2))) >> 31) & 1);
    int v1237 = (int)((unsigned int)((int)((unsigned int)(v991 + 68) >> 2)) >> 1);
    v1077[v1236] = v1237;
    int * v1079 = v985->cache_dirty;
    v1079[v1236] = 0;
    int * v1081 = v985->cache_age;
    v1081[v1236] = 1;
    int * v1083 = v985->cache_age;
    int v1084 = v1083[v1236];
    int v1085 = v1083[v1165];
    int v1243 = v1085 + ((int)((unsigned int)(v1085 - v1084) >> 31));
    v1083[v1165] = v1243;
    int * v1087 = v985->cache_age;
    int v1088 = v1087[v1166];
    int v1245 = v1088 + ((int)((unsigned int)(v1088 - v1084) >> 31));
    v1087[v1166] = v1245;
    int * v1090 = v985->cache_age;
    v1090[v1236] = 0;
    v1093 = v1236;
  }
  int * v1094 = v985->cache_vals;
  int v1248 = (v1093 * 2) + (((int)((unsigned int)(v991 + 68) >> 2)) & 1);
  v1094[v1248] = v993;
  int * v1096 = v985->cache_tags;
  int v1097 = v1096[v1167];
  int v1098 = v1096[v1168];
  bool v1251 = !(((~(((v1097 ^ ((int)((unsigned int)((int)((unsigned int)(v991 + 68) >> 2)) >> 1))) | (-(v1097 ^ ((int)((unsigned int)((int)((unsigned int)(v991 + 68) >> 2)) >> 1))))) >> 31)) | (~(((v1098 ^ ((int)((unsigned int)((int)((unsigned int)(v991 + 68) >> 2)) >> 1))) | (-(v1098 ^ ((int)((unsigned int)((int)((unsigned int)(v991 + 68) >> 2)) >> 1))))) >> 31))) == 0);
  int v1152;
  if (v1251) {
    int * v1099 = v985->cache_age;
    int v1253 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v991 + 68) >> 2)) >> 1)) & 3) * 2)) + ((~(((v1098 ^ ((int)((unsigned int)((int)((unsigned int)(v991 + 68) >> 2)) >> 1))) | (-(v1098 ^ ((int)((unsigned int)((int)((unsigned int)(v991 + 68) >> 2)) >> 1))))) >> 31)) & 1);
    int v1100 = v1099[v1253];
    int v1101 = v1099[v1167];
    int v1254 = v1101 + ((int)((unsigned int)(v1101 - v1100) >> 31));
    v1099[v1167] = v1254;
    int * v1103 = v985->cache_age;
    int v1104 = v1103[v1168];
    int v1256 = v1104 + ((int)((unsigned int)(v1104 - v1100) >> 31));
    v1103[v1168] = v1256;
    int * v1106 = v985->cache_age;
    v1106[v1253] = 0;
    v1152 = v1253;
  } else {
    int * v1109 = v985->cache_age;
    int v1260 = 4 + ((((int)((unsigned int)((int)((unsigned int)(v991 + 68) >> 2)) >> 1)) & 3) * 2);
    int v1110 = v1109[v1260];
    int * v1111 = v985->cache_tags;
    int v1112 = v1111[v1260];
    int v1113 = v1109[v1168];
    int v1114 = v1111[v1168];
    int * v1115 = v985->cache_dirty;
    int v1263 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v991 + 68) >> 2)) >> 1)) & 3) * 2)) + ((((v1110 + ((~(((v1112 ^ -1) | (-(v1112 ^ -1))) >> 31)) & 2)) - (v1113 + ((~(((v1114 ^ -1) | (-(v1114 ^ -1))) >> 31)) & 2))) >> 31) & 1);
    int v1116 = v1115[v1263];
    bool v1264 = !(v1116 == 0);
    if (v1264) {
      int * v1117 = v985->cache_tags;
      int v1118 = v1117[v1263];
      int * v1119 = v985->cache_vals;
      int v1267 = ((4 + ((((int)((unsigned int)((int)((unsigned int)(v991 + 68) >> 2)) >> 1)) & 3) * 2)) + ((((v1110 + ((~(((v1112 ^ -1) | (-(v1112 ^ -1))) >> 31)) & 2)) - (v1113 + ((~(((v1114 ^ -1) | (-(v1114 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
      int v1120 = v1119[v1267];
      int v1268 = (((4 + ((((int)((unsigned int)((int)((unsigned int)(v991 + 68) >> 2)) >> 1)) & 3) * 2)) + ((((v1110 + ((~(((v1112 ^ -1) | (-(v1112 ^ -1))) >> 31)) & 2)) - (v1113 + ((~(((v1114 ^ -1) | (-(v1114 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
      int v1121 = v1119[v1268];
      int * v1122 = v985->mem;
      int v1270 = v1118 * 2;
      v1122[v1270] = v1120;
      int * v1124 = v985->mem;
      int v1273 = (v1118 * 2) + 1;
      v1124[v1273] = v1121;
      ;
    } else {
      ;
    }
    int * v1129 = v985->mem;
    int v1278 = ((int)((unsigned int)((int)((unsigned int)(v991 + 68) >> 2)) >> 1)) * 2;
    int v1130 = v1129[v1278];
    int v1279 = (((int)((unsigned int)((int)((unsigned int)(v991 + 68) >> 2)) >> 1)) * 2) + 1;
    int v1131 = v1129[v1279];
    int * v1132 = v985->cache_vals;
    int v1281 = ((4 + ((((int)((unsigned int)((int)((unsigned int)(v991 + 68) >> 2)) >> 1)) & 3) * 2)) + ((((v1110 + ((~(((v1112 ^ -1) | (-(v1112 ^ -1))) >> 31)) & 2)) - (v1113 + ((~(((v1114 ^ -1) | (-(v1114 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
    v1132[v1281] = v1130;
    int * v1134 = v985->cache_vals;
    int v1284 = (((4 + ((((int)((unsigned int)((int)((unsigned int)(v991 + 68) >> 2)) >> 1)) & 3) * 2)) + ((((v1110 + ((~(((v1112 ^ -1) | (-(v1112 ^ -1))) >> 31)) & 2)) - (v1113 + ((~(((v1114 ^ -1) | (-(v1114 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
    v1134[v1284] = v1131;
    int * v1136 = v985->cache_tags;
    int v1287 = (int)((unsigned int)((int)((unsigned int)(v991 + 68) >> 2)) >> 1);
    v1136[v1263] = v1287;
    int * v1138 = v985->cache_dirty;
    v1138[v1263] = 0;
    int * v1140 = v985->cache_age;
    v1140[v1263] = 1;
    int * v1142 = v985->cache_age;
    int v1143 = v1142[v1263];
    int v1144 = v1142[v1167];
    int v1293 = v1144 + ((int)((unsigned int)(v1144 - v1143) >> 31));
    v1142[v1167] = v1293;
    int * v1146 = v985->cache_age;
    int v1147 = v1146[v1168];
    int v1295 = v1147 + ((int)((unsigned int)(v1147 - v1143) >> 31));
    v1146[v1168] = v1295;
    int * v1149 = v985->cache_age;
    v1149[v1263] = 0;
    v1152 = v1263;
  }
  int * v1153 = v985->cache_vals;
  int v1298 = (v1152 * 2) + (((int)((unsigned int)(v991 + 68) >> 2)) & 1);
  v1153[v1298] = v993;
  int * v1155 = v985->cache_dirty;
  v1155[v1152] = 1;
  struct StateT * v1157 = slot_13(v985);
  return v1157;
}

struct StateT * slot_33(struct StateT * v1767) {
  int v1768 = v1767->timer;
  int v1880 = v1768 + 1;
  v1767->timer = v1880;
  int * v1770 = v1767->reg_ready;
  int v1771 = v1770[10];
  int * v1772 = v1767->regs;
  int v1773 = v1772[10];
  int * v1774 = v1767->cache_tags;
  int v1885 = (((int)((unsigned int)((int)((unsigned int)v1773 >> 2)) >> 1)) & 1) * 2;
  int v1775 = v1774[v1885];
  int v1886 = ((((int)((unsigned int)((int)((unsigned int)v1773 >> 2)) >> 1)) & 1) * 2) + 1;
  int v1776 = v1774[v1886];
  int v1887 = 4 + ((((int)((unsigned int)((int)((unsigned int)v1773 >> 2)) >> 1)) & 3) * 2);
  int v1777 = v1774[v1887];
  int v1888 = (4 + ((((int)((unsigned int)((int)((unsigned int)v1773 >> 2)) >> 1)) & 3) * 2)) + 1;
  int v1778 = v1774[v1888];
  int * v1779 = v1767->cache_vals;
  bool v1889 = !(((~(((v1775 ^ ((int)((unsigned int)((int)((unsigned int)v1773 >> 2)) >> 1))) | (-(v1775 ^ ((int)((unsigned int)((int)((unsigned int)v1773 >> 2)) >> 1))))) >> 31)) | (~(((v1776 ^ ((int)((unsigned int)((int)((unsigned int)v1773 >> 2)) >> 1))) | (-(v1776 ^ ((int)((unsigned int)((int)((unsigned int)v1773 >> 2)) >> 1))))) >> 31))) == 0);
  int v1872;
  if (v1889) {
    int * v1780 = v1767->cache_age;
    int v1891 = ((((int)((unsigned int)((int)((unsigned int)v1773 >> 2)) >> 1)) & 1) * 2) + ((~(((v1776 ^ ((int)((unsigned int)((int)((unsigned int)v1773 >> 2)) >> 1))) | (-(v1776 ^ ((int)((unsigned int)((int)((unsigned int)v1773 >> 2)) >> 1))))) >> 31)) & 1);
    int v1781 = v1780[v1891];
    int v1782 = v1780[v1885];
    int v1892 = v1782 + ((int)((unsigned int)(v1782 - v1781) >> 31));
    v1780[v1885] = v1892;
    int * v1784 = v1767->cache_age;
    int v1785 = v1784[v1886];
    int v1894 = v1785 + ((int)((unsigned int)(v1785 - v1781) >> 31));
    v1784[v1886] = v1894;
    int * v1787 = v1767->cache_age;
    v1787[v1891] = 0;
    v1872 = v1891;
  } else {
    int * v1790 = v1767->cache_age;
    int v1898 = (((int)((unsigned int)((int)((unsigned int)v1773 >> 2)) >> 1)) & 1) * 2;
    int v1791 = v1790[v1898];
    int * v1792 = v1767->cache_tags;
    int v1793 = v1792[v1898];
    int v1794 = v1790[v1886];
    int v1795 = v1792[v1886];
    bool v1900 = !(((~(((v1777 ^ ((int)((unsigned int)((int)((unsigned int)v1773 >> 2)) >> 1))) | (-(v1777 ^ ((int)((unsigned int)((int)((unsigned int)v1773 >> 2)) >> 1))))) >> 31)) | (~(((v1778 ^ ((int)((unsigned int)((int)((unsigned int)v1773 >> 2)) >> 1))) | (-(v1778 ^ ((int)((unsigned int)((int)((unsigned int)v1773 >> 2)) >> 1))))) >> 31))) == 0);
    int v1849;
    if (v1900) {
      int * v1796 = v1767->cache_age;
      int v1902 = (4 + ((((int)((unsigned int)((int)((unsigned int)v1773 >> 2)) >> 1)) & 3) * 2)) + ((~(((v1778 ^ ((int)((unsigned int)((int)((unsigned int)v1773 >> 2)) >> 1))) | (-(v1778 ^ ((int)((unsigned int)((int)((unsigned int)v1773 >> 2)) >> 1))))) >> 31)) & 1);
      int v1797 = v1796[v1902];
      int v1798 = v1796[v1887];
      int v1903 = v1798 + ((int)((unsigned int)(v1798 - v1797) >> 31));
      v1796[v1887] = v1903;
      int * v1800 = v1767->cache_age;
      int v1801 = v1800[v1888];
      int v1905 = v1801 + ((int)((unsigned int)(v1801 - v1797) >> 31));
      v1800[v1888] = v1905;
      int * v1803 = v1767->cache_age;
      v1803[v1902] = 0;
      v1849 = v1902;
    } else {
      int * v1806 = v1767->cache_age;
      int v1909 = 4 + ((((int)((unsigned int)((int)((unsigned int)v1773 >> 2)) >> 1)) & 3) * 2);
      int v1807 = v1806[v1909];
      int * v1808 = v1767->cache_tags;
      int v1809 = v1808[v1909];
      int v1810 = v1806[v1888];
      int v1811 = v1808[v1888];
      int * v1812 = v1767->cache_dirty;
      int v1912 = (4 + ((((int)((unsigned int)((int)((unsigned int)v1773 >> 2)) >> 1)) & 3) * 2)) + ((((v1807 + ((~(((v1809 ^ -1) | (-(v1809 ^ -1))) >> 31)) & 2)) - (v1810 + ((~(((v1811 ^ -1) | (-(v1811 ^ -1))) >> 31)) & 2))) >> 31) & 1);
      int v1813 = v1812[v1912];
      bool v1913 = !(v1813 == 0);
      if (v1913) {
        int * v1814 = v1767->cache_tags;
        int v1815 = v1814[v1912];
        int * v1816 = v1767->cache_vals;
        int v1916 = ((4 + ((((int)((unsigned int)((int)((unsigned int)v1773 >> 2)) >> 1)) & 3) * 2)) + ((((v1807 + ((~(((v1809 ^ -1) | (-(v1809 ^ -1))) >> 31)) & 2)) - (v1810 + ((~(((v1811 ^ -1) | (-(v1811 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
        int v1817 = v1816[v1916];
        int v1917 = (((4 + ((((int)((unsigned int)((int)((unsigned int)v1773 >> 2)) >> 1)) & 3) * 2)) + ((((v1807 + ((~(((v1809 ^ -1) | (-(v1809 ^ -1))) >> 31)) & 2)) - (v1810 + ((~(((v1811 ^ -1) | (-(v1811 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
        int v1818 = v1816[v1917];
        int * v1819 = v1767->mem;
        int v1919 = v1815 * 2;
        v1819[v1919] = v1817;
        int * v1821 = v1767->mem;
        int v1922 = (v1815 * 2) + 1;
        v1821[v1922] = v1818;
        ;
      } else {
        ;
      }
      int * v1826 = v1767->mem;
      int v1927 = ((int)((unsigned int)((int)((unsigned int)v1773 >> 2)) >> 1)) * 2;
      int v1827 = v1826[v1927];
      int v1928 = (((int)((unsigned int)((int)((unsigned int)v1773 >> 2)) >> 1)) * 2) + 1;
      int v1828 = v1826[v1928];
      int * v1829 = v1767->cache_vals;
      int v1930 = ((4 + ((((int)((unsigned int)((int)((unsigned int)v1773 >> 2)) >> 1)) & 3) * 2)) + ((((v1807 + ((~(((v1809 ^ -1) | (-(v1809 ^ -1))) >> 31)) & 2)) - (v1810 + ((~(((v1811 ^ -1) | (-(v1811 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
      v1829[v1930] = v1827;
      int * v1831 = v1767->cache_vals;
      int v1933 = (((4 + ((((int)((unsigned int)((int)((unsigned int)v1773 >> 2)) >> 1)) & 3) * 2)) + ((((v1807 + ((~(((v1809 ^ -1) | (-(v1809 ^ -1))) >> 31)) & 2)) - (v1810 + ((~(((v1811 ^ -1) | (-(v1811 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
      v1831[v1933] = v1828;
      int * v1833 = v1767->cache_tags;
      int v1936 = (int)((unsigned int)((int)((unsigned int)v1773 >> 2)) >> 1);
      v1833[v1912] = v1936;
      int * v1835 = v1767->cache_dirty;
      v1835[v1912] = 0;
      int * v1837 = v1767->cache_age;
      v1837[v1912] = 1;
      int * v1839 = v1767->cache_age;
      int v1840 = v1839[v1912];
      int v1841 = v1839[v1887];
      int v1942 = v1841 + ((int)((unsigned int)(v1841 - v1840) >> 31));
      v1839[v1887] = v1942;
      int * v1843 = v1767->cache_age;
      int v1844 = v1843[v1888];
      int v1944 = v1844 + ((int)((unsigned int)(v1844 - v1840) >> 31));
      v1843[v1888] = v1944;
      int * v1846 = v1767->cache_age;
      v1846[v1912] = 0;
      v1849 = v1912;
    }
    int * v1850 = v1767->cache_vals;
    int v1947 = v1849 * 2;
    int v1851 = v1850[v1947];
    int v1948 = (v1849 * 2) + 1;
    int v1852 = v1850[v1948];
    int v1949 = (((((int)((unsigned int)((int)((unsigned int)v1773 >> 2)) >> 1)) & 1) * 2) + ((((v1791 + ((~(((v1793 ^ -1) | (-(v1793 ^ -1))) >> 31)) & 2)) - (v1794 + ((~(((v1795 ^ -1) | (-(v1795 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
    v1850[v1949] = v1851;
    int * v1854 = v1767->cache_vals;
    int v1952 = ((((((int)((unsigned int)((int)((unsigned int)v1773 >> 2)) >> 1)) & 1) * 2) + ((((v1791 + ((~(((v1793 ^ -1) | (-(v1793 ^ -1))) >> 31)) & 2)) - (v1794 + ((~(((v1795 ^ -1) | (-(v1795 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
    v1854[v1952] = v1852;
    int * v1856 = v1767->cache_tags;
    int v1955 = ((((int)((unsigned int)((int)((unsigned int)v1773 >> 2)) >> 1)) & 1) * 2) + ((((v1791 + ((~(((v1793 ^ -1) | (-(v1793 ^ -1))) >> 31)) & 2)) - (v1794 + ((~(((v1795 ^ -1) | (-(v1795 ^ -1))) >> 31)) & 2))) >> 31) & 1);
    int v1956 = (int)((unsigned int)((int)((unsigned int)v1773 >> 2)) >> 1);
    v1856[v1955] = v1956;
    int * v1858 = v1767->cache_dirty;
    v1858[v1955] = 0;
    int * v1860 = v1767->cache_age;
    v1860[v1955] = 1;
    int * v1862 = v1767->cache_age;
    int v1863 = v1862[v1955];
    int v1864 = v1862[v1885];
    int v1962 = v1864 + ((int)((unsigned int)(v1864 - v1863) >> 31));
    v1862[v1885] = v1962;
    int * v1866 = v1767->cache_age;
    int v1867 = v1866[v1886];
    int v1964 = v1867 + ((int)((unsigned int)(v1867 - v1863) >> 31));
    v1866[v1886] = v1964;
    int * v1869 = v1767->cache_age;
    v1869[v1955] = 0;
    v1872 = v1955;
  }
  int v1967 = (v1872 * 2) + (((int)((unsigned int)v1773 >> 2)) & 1);
  int v1873 = v1779[v1967];
  int * v1874 = v1767->reg_ready;
  int v1969 = ((v1771 + ((v1768 - v1771) & (~((v1768 - v1771) >> 31)))) + 1) + ((100 ^ (((~(((v1777 ^ ((int)((unsigned int)((int)((unsigned int)v1773 >> 2)) >> 1))) | (-(v1777 ^ ((int)((unsigned int)((int)((unsigned int)v1773 >> 2)) >> 1))))) >> 31)) | (~(((v1778 ^ ((int)((unsigned int)((int)((unsigned int)v1773 >> 2)) >> 1))) | (-(v1778 ^ ((int)((unsigned int)((int)((unsigned int)v1773 >> 2)) >> 1))))) >> 31))) & 104)) ^ (((~(((v1775 ^ ((int)((unsigned int)((int)((unsigned int)v1773 >> 2)) >> 1))) | (-(v1775 ^ ((int)((unsigned int)((int)((unsigned int)v1773 >> 2)) >> 1))))) >> 31)) | (~(((v1776 ^ ((int)((unsigned int)((int)((unsigned int)v1773 >> 2)) >> 1))) | (-(v1776 ^ ((int)((unsigned int)((int)((unsigned int)v1773 >> 2)) >> 1))))) >> 31))) & (1 ^ (100 ^ (((~(((v1777 ^ ((int)((unsigned int)((int)((unsigned int)v1773 >> 2)) >> 1))) | (-(v1777 ^ ((int)((unsigned int)((int)((unsigned int)v1773 >> 2)) >> 1))))) >> 31)) | (~(((v1778 ^ ((int)((unsigned int)((int)((unsigned int)v1773 >> 2)) >> 1))) | (-(v1778 ^ ((int)((unsigned int)((int)((unsigned int)v1773 >> 2)) >> 1))))) >> 31))) & 104)))));
  v1874[10] = v1969;
  int * v1876 = v1767->regs;
  v1876[10] = v1873;
  struct StateT * v1878 = slot_34(v1767);
  return v1878;
}

struct StateT * snippet(struct StateT * v0) {
  struct StateT * v1 = slot_0(v0);
  int v2054 = v1->timer;
  int * v2055 = v1->reg_ready;
  int v2056 = v2055[0];
  int v2187 = v2056 + ((v2054 - v2056) & (~((v2054 - v2056) >> 31)));
  v1->timer = v2187;
  int v2058 = v1->timer;
  int * v2059 = v1->reg_ready;
  int v2060 = v2059[1];
  int v2190 = v2060 + ((v2058 - v2060) & (~((v2058 - v2060) >> 31)));
  v1->timer = v2190;
  int v2062 = v1->timer;
  int * v2063 = v1->reg_ready;
  int v2064 = v2063[2];
  int v2193 = v2064 + ((v2062 - v2064) & (~((v2062 - v2064) >> 31)));
  v1->timer = v2193;
  int v2066 = v1->timer;
  int * v2067 = v1->reg_ready;
  int v2068 = v2067[3];
  int v2196 = v2068 + ((v2066 - v2068) & (~((v2066 - v2068) >> 31)));
  v1->timer = v2196;
  int v2070 = v1->timer;
  int * v2071 = v1->reg_ready;
  int v2072 = v2071[4];
  int v2199 = v2072 + ((v2070 - v2072) & (~((v2070 - v2072) >> 31)));
  v1->timer = v2199;
  int v2074 = v1->timer;
  int * v2075 = v1->reg_ready;
  int v2076 = v2075[5];
  int v2202 = v2076 + ((v2074 - v2076) & (~((v2074 - v2076) >> 31)));
  v1->timer = v2202;
  int v2078 = v1->timer;
  int * v2079 = v1->reg_ready;
  int v2080 = v2079[6];
  int v2205 = v2080 + ((v2078 - v2080) & (~((v2078 - v2080) >> 31)));
  v1->timer = v2205;
  int v2082 = v1->timer;
  int * v2083 = v1->reg_ready;
  int v2084 = v2083[7];
  int v2208 = v2084 + ((v2082 - v2084) & (~((v2082 - v2084) >> 31)));
  v1->timer = v2208;
  int v2086 = v1->timer;
  int * v2087 = v1->reg_ready;
  int v2088 = v2087[8];
  int v2211 = v2088 + ((v2086 - v2088) & (~((v2086 - v2088) >> 31)));
  v1->timer = v2211;
  int v2090 = v1->timer;
  int * v2091 = v1->reg_ready;
  int v2092 = v2091[9];
  int v2214 = v2092 + ((v2090 - v2092) & (~((v2090 - v2092) >> 31)));
  v1->timer = v2214;
  int v2094 = v1->timer;
  int * v2095 = v1->reg_ready;
  int v2096 = v2095[10];
  int v2217 = v2096 + ((v2094 - v2096) & (~((v2094 - v2096) >> 31)));
  v1->timer = v2217;
  int v2098 = v1->timer;
  int * v2099 = v1->reg_ready;
  int v2100 = v2099[11];
  int v2220 = v2100 + ((v2098 - v2100) & (~((v2098 - v2100) >> 31)));
  v1->timer = v2220;
  int v2102 = v1->timer;
  int * v2103 = v1->reg_ready;
  int v2104 = v2103[12];
  int v2223 = v2104 + ((v2102 - v2104) & (~((v2102 - v2104) >> 31)));
  v1->timer = v2223;
  int v2106 = v1->timer;
  int * v2107 = v1->reg_ready;
  int v2108 = v2107[13];
  int v2226 = v2108 + ((v2106 - v2108) & (~((v2106 - v2108) >> 31)));
  v1->timer = v2226;
  int v2110 = v1->timer;
  int * v2111 = v1->reg_ready;
  int v2112 = v2111[14];
  int v2229 = v2112 + ((v2110 - v2112) & (~((v2110 - v2112) >> 31)));
  v1->timer = v2229;
  int v2114 = v1->timer;
  int * v2115 = v1->reg_ready;
  int v2116 = v2115[15];
  int v2232 = v2116 + ((v2114 - v2116) & (~((v2114 - v2116) >> 31)));
  v1->timer = v2232;
  int v2118 = v1->timer;
  int * v2119 = v1->reg_ready;
  int v2120 = v2119[16];
  int v2235 = v2120 + ((v2118 - v2120) & (~((v2118 - v2120) >> 31)));
  v1->timer = v2235;
  int v2122 = v1->timer;
  int * v2123 = v1->reg_ready;
  int v2124 = v2123[17];
  int v2238 = v2124 + ((v2122 - v2124) & (~((v2122 - v2124) >> 31)));
  v1->timer = v2238;
  int v2126 = v1->timer;
  int * v2127 = v1->reg_ready;
  int v2128 = v2127[18];
  int v2241 = v2128 + ((v2126 - v2128) & (~((v2126 - v2128) >> 31)));
  v1->timer = v2241;
  int v2130 = v1->timer;
  int * v2131 = v1->reg_ready;
  int v2132 = v2131[19];
  int v2244 = v2132 + ((v2130 - v2132) & (~((v2130 - v2132) >> 31)));
  v1->timer = v2244;
  int v2134 = v1->timer;
  int * v2135 = v1->reg_ready;
  int v2136 = v2135[20];
  int v2247 = v2136 + ((v2134 - v2136) & (~((v2134 - v2136) >> 31)));
  v1->timer = v2247;
  int v2138 = v1->timer;
  int * v2139 = v1->reg_ready;
  int v2140 = v2139[21];
  int v2250 = v2140 + ((v2138 - v2140) & (~((v2138 - v2140) >> 31)));
  v1->timer = v2250;
  int v2142 = v1->timer;
  int * v2143 = v1->reg_ready;
  int v2144 = v2143[22];
  int v2253 = v2144 + ((v2142 - v2144) & (~((v2142 - v2144) >> 31)));
  v1->timer = v2253;
  int v2146 = v1->timer;
  int * v2147 = v1->reg_ready;
  int v2148 = v2147[23];
  int v2256 = v2148 + ((v2146 - v2148) & (~((v2146 - v2148) >> 31)));
  v1->timer = v2256;
  int v2150 = v1->timer;
  int * v2151 = v1->reg_ready;
  int v2152 = v2151[24];
  int v2259 = v2152 + ((v2150 - v2152) & (~((v2150 - v2152) >> 31)));
  v1->timer = v2259;
  int v2154 = v1->timer;
  int * v2155 = v1->reg_ready;
  int v2156 = v2155[25];
  int v2262 = v2156 + ((v2154 - v2156) & (~((v2154 - v2156) >> 31)));
  v1->timer = v2262;
  int v2158 = v1->timer;
  int * v2159 = v1->reg_ready;
  int v2160 = v2159[26];
  int v2265 = v2160 + ((v2158 - v2160) & (~((v2158 - v2160) >> 31)));
  v1->timer = v2265;
  int v2162 = v1->timer;
  int * v2163 = v1->reg_ready;
  int v2164 = v2163[27];
  int v2268 = v2164 + ((v2162 - v2164) & (~((v2162 - v2164) >> 31)));
  v1->timer = v2268;
  int v2166 = v1->timer;
  int * v2167 = v1->reg_ready;
  int v2168 = v2167[28];
  int v2271 = v2168 + ((v2166 - v2168) & (~((v2166 - v2168) >> 31)));
  v1->timer = v2271;
  int v2170 = v1->timer;
  int * v2171 = v1->reg_ready;
  int v2172 = v2171[29];
  int v2274 = v2172 + ((v2170 - v2172) & (~((v2170 - v2172) >> 31)));
  v1->timer = v2274;
  int v2174 = v1->timer;
  int * v2175 = v1->reg_ready;
  int v2176 = v2175[30];
  int v2277 = v2176 + ((v2174 - v2176) & (~((v2174 - v2176) >> 31)));
  v1->timer = v2277;
  int v2178 = v1->timer;
  int * v2179 = v1->reg_ready;
  int v2180 = v2179[31];
  int v2280 = v2180 + ((v2178 - v2180) & (~((v2178 - v2180) >> 31)));
  v1->timer = v2280;
  return v1;
}

struct StateT * slot_8(struct StateT * v530) {
  int * v531 = v530->saved_regs;
  int * v532 = v530->regs;
  int v533 = v532[10];
  v531[10] = v533;
  int v535 = v530->timer;
  int v550 = v535 + 1;
  v530->timer = v550;
  int * v537 = v530->reg_ready;
  int v538 = v537[10];
  int * v539 = v530->regs;
  int v540 = v539[10];
  int v553 = (v538 + ((v535 - v538) & (~((v535 - v538) >> 31)))) + 1;
  v537[10] = v553;
  int * v542 = v530->regs;
  int v555 = v540 << 2;
  v542[10] = v555;
  struct StateT * v544 = slot_9(v530);
  return v544;
}

struct StateT * slot_27(struct StateT * v1639) {
  int v1640 = v1639->timer;
  int v1644 = v1640 + 1;
  v1639->timer = v1644;
  struct StateT * v1642 = slot_28(v1639);
  return v1642;
}

struct StateT * slot_30(struct StateT * v1707) {
  int v1708 = v1707->timer;
  int v1712 = v1708 + 1;
  v1707->timer = v1712;
  struct StateT * v1710 = slot_31(v1707);
  return v1710;
}

struct StateT * slot_4(struct StateT * v256) {
  int * v257 = v256->saved_regs;
  int * v258 = v256->regs;
  int v259 = v258[12];
  v257[12] = v259;
  int v261 = v256->timer;
  int v273 = v261 + 1;
  v256->timer = v273;
  int * v263 = v256->reg_ready;
  v263[12] = v273;
  int * v265 = v256->regs;
  v265[12] = 0;
  struct StateT * v267 = slot_5(v256);
  return v267;
}

struct StateT * slot_18(struct StateT * v961) {
  int v962 = v961->timer;
  int v970 = v962 + 1;
  v961->timer = v970;
  int * v964 = v961->reg_ready;
  v964[10] = v970;
  int * v966 = v961->regs;
  v966[10] = 0;
  struct StateT * v968 = slot_20(v961);
  return v968;
}

struct StateT * slot_9(struct StateT * v558) {
  int v559 = v558->timer;
  int v572 = v559 + 1;
  v558->timer = v572;
  int * v561 = v558->reg_ready;
  int v562 = v561[14];
  int * v563 = v558->regs;
  int v564 = v563[14];
  int v565 = v561[10];
  int v566 = v563[10];
  int v577 = (v565 + (((v562 + ((v559 - v562) & (~((v559 - v562) >> 31)))) - v565) & (~(((v562 + ((v559 - v562) & (~((v559 - v562) >> 31)))) - v565) >> 31)))) + 1;
  v561[10] = v577;
  int * v568 = v558->regs;
  int v579 = v564 + v566;
  v568[10] = v579;
  struct StateT * v570 = slot_10(v558);
  return v570;
}

struct StateT * slot_22(struct StateT * v1327) {
  int * v1328 = v1327->saved_regs;
  int v1329 = v1328[10];
  int * v1330 = v1327->regs;
  int v1331 = v1330[11];
  bool v1351 = (v1329 ^ -2147483648) < (v1331 ^ -2147483648);
  struct StateT * v1345;
  if (v1351) {
    int v1332 = v1327->timer;
    int v1352 = v1332 + 15;
    v1327->timer = v1352;
    int * v1334 = v1327->saved_regs;
    int v1335 = v1334[10];
    int * v1336 = v1327->regs;
    v1336[10] = v1335;
    int * v1338 = v1327->reg_ready;
    int v1339 = v1327->timer;
    v1338[10] = v1339;
    struct StateT * v1341 = slot_23(v1327);
    v1345 = v1341;
  } else {
    struct StateT * v1343 = slot_20(v1327);
    v1345 = v1343;
  }
  return v1345;
}

struct StateT * slot_11(struct StateT * v789) {
  int v790 = v789->timer;
  int v803 = v790 + 1;
  v789->timer = v803;
  int * v792 = v789->reg_ready;
  int v793 = v792[12];
  int * v794 = v789->regs;
  int v795 = v794[12];
  int v796 = v792[10];
  int v797 = v794[10];
  int v808 = (v796 + (((v793 + ((v790 - v793) & (~((v790 - v793) >> 31)))) - v796) & (~(((v793 + ((v790 - v793) & (~((v790 - v793) >> 31)))) - v796) >> 31)))) + 1;
  v792[12] = v808;
  int * v799 = v789->regs;
  int v810 = v795 & v797;
  v799[12] = v810;
  struct StateT * v801 = slot_12(v789);
  return v801;
}

struct StateT * slot_35(struct StateT * v2005) {
  int * v2006 = v2005->saved_regs;
  int v2007 = v2006[10];
  int * v2008 = v2005->regs;
  int v2009 = v2008[11];
  bool v2036 = (v2007 ^ -2147483648) < (v2009 ^ -2147483648);
  struct StateT * v2030;
  if (v2036) {
    struct StateT * v2010 = slot_27(v2005);
    v2030 = v2010;
  } else {
    int v2012 = v2005->timer;
    int v2039 = v2012 + 15;
    v2005->timer = v2039;
    int * v2014 = v2005->saved_regs;
    int v2015 = v2014[10];
    int * v2016 = v2005->regs;
    v2016[10] = v2015;
    int * v2018 = v2005->saved_regs;
    int v2019 = v2018[12];
    int * v2020 = v2005->regs;
    v2020[12] = v2019;
    int * v2022 = v2005->reg_ready;
    int v2023 = v2005->timer;
    v2022[10] = v2023;
    int * v2025 = v2005->reg_ready;
    int v2026 = v2005->timer;
    v2025[12] = v2026;
    struct StateT * v2028 = slot_18(v2005);
    v2030 = v2028;
  }
  return v2030;
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