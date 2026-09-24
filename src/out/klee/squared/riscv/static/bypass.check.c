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

struct StateT2 {
  struct StateT * a;
  struct StateT * b;
};

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

void squared_assert(bool);
void squared_assume(bool);

struct StateT2 * snippet(struct StateT2 * v0);
struct StateT2 * slot_1(struct StateT2 * v46);
struct StateT2 * slot_6(struct StateT2 * v1454);
struct StateT2 * slot_5(struct StateT2 * v1411);
struct StateT2 * slot_4(struct StateT2 * v901);
struct StateT2 * slot_2(struct StateT2 * v89);
struct StateT2 * slot_3(struct StateT2 * v125);
struct StateT2 * slot_0(struct StateT2 * v2);
struct StateT2 * snippet(struct StateT2 * v0) {
  struct StateT2 * v1 = slot_0(v0);
  return v1;
}

struct StateT2 * slot_1(struct StateT2 * v46) {
  struct StateT * v47 = v46->a;
  int v48 = v47->timer;
  struct StateT * v49 = v46->b;
  int v50 = v49->timer;
  bool v73 = v48 == v50;
  squared_assert(v73);
  squared_assume(v73);
  struct StateT * v53 = v46->a;
  int v54 = v53->timer;
  int v75 = v54 + 1;
  v53->timer = v75;
  struct StateT * v56 = v46->b;
  int v57 = v56->timer;
  int v77 = v57 + 1;
  v56->timer = v77;
  struct StateT * v59 = v46->a;
  int * v60 = v59->regs;
  int v61 = v60[6];
  int * v62 = v59->regs;
  int v82 = v61 + 80;
  v62[6] = v82;
  struct StateT * v64 = v46->b;
  int * v65 = v64->regs;
  int v66 = v65[6];
  int * v67 = v64->regs;
  int v86 = v66 + 80;
  v67[6] = v86;
  struct StateT2 * v69 = slot_2(v46);
  return v69;
}

struct StateT2 * slot_6(struct StateT2 * v1454) {
  struct StateT * v1455 = v1454->a;
  int v1456 = v1455->timer;
  struct StateT * v1457 = v1454->b;
  int v1458 = v1457->timer;
  bool v1730 = v1456 == v1458;
  squared_assert(v1730);
  squared_assume(v1730);
  struct StateT * v1461 = v1454->a;
  int v1462 = v1461->timer;
  int v1732 = v1462 + 1;
  v1461->timer = v1732;
  struct StateT * v1464 = v1454->b;
  int v1465 = v1464->timer;
  int v1734 = v1465 + 1;
  v1464->timer = v1734;
  struct StateT * v1467 = v1454->a;
  int * v1468 = v1467->regs;
  int v1469 = v1468[11];
  int * v1470 = v1467->cache_tags;
  int v1739 = (((int)((unsigned int)((int)((unsigned int)v1469 >> 2)) >> 1)) & 1) * 2;
  int v1471 = v1470[v1739];
  int * v1472 = v1467->cache_tags;
  int v1741 = ((((int)((unsigned int)((int)((unsigned int)v1469 >> 2)) >> 1)) & 1) * 2) + 1;
  int v1473 = v1472[v1741];
  int * v1474 = v1467->cache_tags;
  int v1743 = 4 + ((((int)((unsigned int)((int)((unsigned int)v1469 >> 2)) >> 1)) & 3) * 2);
  int v1475 = v1474[v1743];
  int * v1476 = v1467->cache_tags;
  int v1745 = (4 + ((((int)((unsigned int)((int)((unsigned int)v1469 >> 2)) >> 1)) & 3) * 2)) + 1;
  int v1477 = v1476[v1745];
  int v1478 = v1467->timer;
  int v1746 = v1478 + ((100 ^ (((~(((v1475 ^ ((int)((unsigned int)((int)((unsigned int)v1469 >> 2)) >> 1))) | (-(v1475 ^ ((int)((unsigned int)((int)((unsigned int)v1469 >> 2)) >> 1))))) >> 31)) | (~(((v1477 ^ ((int)((unsigned int)((int)((unsigned int)v1469 >> 2)) >> 1))) | (-(v1477 ^ ((int)((unsigned int)((int)((unsigned int)v1469 >> 2)) >> 1))))) >> 31))) & 104)) ^ (((~(((v1471 ^ ((int)((unsigned int)((int)((unsigned int)v1469 >> 2)) >> 1))) | (-(v1471 ^ ((int)((unsigned int)((int)((unsigned int)v1469 >> 2)) >> 1))))) >> 31)) | (~(((v1473 ^ ((int)((unsigned int)((int)((unsigned int)v1469 >> 2)) >> 1))) | (-(v1473 ^ ((int)((unsigned int)((int)((unsigned int)v1469 >> 2)) >> 1))))) >> 31))) & (1 ^ (100 ^ (((~(((v1475 ^ ((int)((unsigned int)((int)((unsigned int)v1469 >> 2)) >> 1))) | (-(v1475 ^ ((int)((unsigned int)((int)((unsigned int)v1469 >> 2)) >> 1))))) >> 31)) | (~(((v1477 ^ ((int)((unsigned int)((int)((unsigned int)v1469 >> 2)) >> 1))) | (-(v1477 ^ ((int)((unsigned int)((int)((unsigned int)v1469 >> 2)) >> 1))))) >> 31))) & 104)))));
  v1467->timer = v1746;
  int * v1480 = v1467->cache_vals;
  bool v1747 = !(((~(((v1471 ^ ((int)((unsigned int)((int)((unsigned int)v1469 >> 2)) >> 1))) | (-(v1471 ^ ((int)((unsigned int)((int)((unsigned int)v1469 >> 2)) >> 1))))) >> 31)) | (~(((v1473 ^ ((int)((unsigned int)((int)((unsigned int)v1469 >> 2)) >> 1))) | (-(v1473 ^ ((int)((unsigned int)((int)((unsigned int)v1469 >> 2)) >> 1))))) >> 31))) == 0);
  int v1593;
  if (v1747) {
    int * v1481 = v1467->cache_age;
    int v1749 = ((((int)((unsigned int)((int)((unsigned int)v1469 >> 2)) >> 1)) & 1) * 2) + ((~(((v1473 ^ ((int)((unsigned int)((int)((unsigned int)v1469 >> 2)) >> 1))) | (-(v1473 ^ ((int)((unsigned int)((int)((unsigned int)v1469 >> 2)) >> 1))))) >> 31)) & 1);
    int v1482 = v1481[v1749];
    int * v1483 = v1467->cache_age;
    int v1484 = v1483[v1739];
    int * v1485 = v1467->cache_age;
    int v1752 = v1484 + ((int)((unsigned int)(v1484 - v1482) >> 31));
    v1485[v1739] = v1752;
    int * v1487 = v1467->cache_age;
    int v1488 = v1487[v1741];
    int * v1489 = v1467->cache_age;
    int v1755 = v1488 + ((int)((unsigned int)(v1488 - v1482) >> 31));
    v1489[v1741] = v1755;
    int * v1491 = v1467->cache_age;
    v1491[v1749] = 0;
    v1593 = v1749;
  } else {
    int * v1494 = v1467->cache_age;
    int v1759 = (((int)((unsigned int)((int)((unsigned int)v1469 >> 2)) >> 1)) & 1) * 2;
    int v1495 = v1494[v1759];
    int * v1496 = v1467->cache_tags;
    int v1497 = v1496[v1759];
    int * v1498 = v1467->cache_age;
    int v1499 = v1498[v1741];
    int * v1500 = v1467->cache_tags;
    int v1501 = v1500[v1741];
    bool v1763 = !(((~(((v1475 ^ ((int)((unsigned int)((int)((unsigned int)v1469 >> 2)) >> 1))) | (-(v1475 ^ ((int)((unsigned int)((int)((unsigned int)v1469 >> 2)) >> 1))))) >> 31)) | (~(((v1477 ^ ((int)((unsigned int)((int)((unsigned int)v1469 >> 2)) >> 1))) | (-(v1477 ^ ((int)((unsigned int)((int)((unsigned int)v1469 >> 2)) >> 1))))) >> 31))) == 0);
    int v1565;
    if (v1763) {
      int * v1502 = v1467->cache_age;
      int v1765 = (4 + ((((int)((unsigned int)((int)((unsigned int)v1469 >> 2)) >> 1)) & 3) * 2)) + ((~(((v1477 ^ ((int)((unsigned int)((int)((unsigned int)v1469 >> 2)) >> 1))) | (-(v1477 ^ ((int)((unsigned int)((int)((unsigned int)v1469 >> 2)) >> 1))))) >> 31)) & 1);
      int v1503 = v1502[v1765];
      int * v1504 = v1467->cache_age;
      int v1505 = v1504[v1743];
      int * v1506 = v1467->cache_age;
      int v1768 = v1505 + ((int)((unsigned int)(v1505 - v1503) >> 31));
      v1506[v1743] = v1768;
      int * v1508 = v1467->cache_age;
      int v1509 = v1508[v1745];
      int * v1510 = v1467->cache_age;
      int v1771 = v1509 + ((int)((unsigned int)(v1509 - v1503) >> 31));
      v1510[v1745] = v1771;
      int * v1512 = v1467->cache_age;
      v1512[v1765] = 0;
      v1565 = v1765;
    } else {
      int * v1515 = v1467->cache_age;
      int v1775 = 4 + ((((int)((unsigned int)((int)((unsigned int)v1469 >> 2)) >> 1)) & 3) * 2);
      int v1516 = v1515[v1775];
      int * v1517 = v1467->cache_tags;
      int v1518 = v1517[v1775];
      int * v1519 = v1467->cache_age;
      int v1520 = v1519[v1745];
      int * v1521 = v1467->cache_tags;
      int v1522 = v1521[v1745];
      int * v1523 = v1467->cache_dirty;
      int v1780 = (4 + ((((int)((unsigned int)((int)((unsigned int)v1469 >> 2)) >> 1)) & 3) * 2)) + ((((v1516 + ((~(((v1518 ^ -1) | (-(v1518 ^ -1))) >> 31)) & 2)) - (v1520 + ((~(((v1522 ^ -1) | (-(v1522 ^ -1))) >> 31)) & 2))) >> 31) & 1);
      int v1524 = v1523[v1780];
      bool v1781 = !(v1524 == 0);
      if (v1781) {
        int * v1525 = v1467->cache_tags;
        int v1526 = v1525[v1780];
        int * v1527 = v1467->cache_vals;
        int v1784 = ((4 + ((((int)((unsigned int)((int)((unsigned int)v1469 >> 2)) >> 1)) & 3) * 2)) + ((((v1516 + ((~(((v1518 ^ -1) | (-(v1518 ^ -1))) >> 31)) & 2)) - (v1520 + ((~(((v1522 ^ -1) | (-(v1522 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
        int v1528 = v1527[v1784];
        int * v1529 = v1467->cache_vals;
        int v1786 = (((4 + ((((int)((unsigned int)((int)((unsigned int)v1469 >> 2)) >> 1)) & 3) * 2)) + ((((v1516 + ((~(((v1518 ^ -1) | (-(v1518 ^ -1))) >> 31)) & 2)) - (v1520 + ((~(((v1522 ^ -1) | (-(v1522 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
        int v1530 = v1529[v1786];
        int * v1531 = v1467->mem;
        int v1788 = v1526 * 2;
        v1531[v1788] = v1528;
        int * v1533 = v1467->mem;
        int v1791 = (v1526 * 2) + 1;
        v1533[v1791] = v1530;
        ;
      } else {
        ;
      }
      int * v1538 = v1467->mem;
      int v1796 = ((int)((unsigned int)((int)((unsigned int)v1469 >> 2)) >> 1)) * 2;
      int v1539 = v1538[v1796];
      int * v1540 = v1467->mem;
      int v1798 = (((int)((unsigned int)((int)((unsigned int)v1469 >> 2)) >> 1)) * 2) + 1;
      int v1541 = v1540[v1798];
      int * v1542 = v1467->cache_vals;
      int v1800 = ((4 + ((((int)((unsigned int)((int)((unsigned int)v1469 >> 2)) >> 1)) & 3) * 2)) + ((((v1516 + ((~(((v1518 ^ -1) | (-(v1518 ^ -1))) >> 31)) & 2)) - (v1520 + ((~(((v1522 ^ -1) | (-(v1522 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
      v1542[v1800] = v1539;
      int * v1544 = v1467->cache_vals;
      int v1803 = (((4 + ((((int)((unsigned int)((int)((unsigned int)v1469 >> 2)) >> 1)) & 3) * 2)) + ((((v1516 + ((~(((v1518 ^ -1) | (-(v1518 ^ -1))) >> 31)) & 2)) - (v1520 + ((~(((v1522 ^ -1) | (-(v1522 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
      v1544[v1803] = v1541;
      int * v1546 = v1467->cache_tags;
      int v1806 = (int)((unsigned int)((int)((unsigned int)v1469 >> 2)) >> 1);
      v1546[v1780] = v1806;
      int * v1548 = v1467->cache_dirty;
      v1548[v1780] = 0;
      int * v1550 = v1467->cache_age;
      v1550[v1780] = 1;
      int * v1552 = v1467->cache_age;
      int v1553 = v1552[v1780];
      int * v1554 = v1467->cache_age;
      int v1555 = v1554[v1743];
      int * v1556 = v1467->cache_age;
      int v1814 = v1555 + ((int)((unsigned int)(v1555 - v1553) >> 31));
      v1556[v1743] = v1814;
      int * v1558 = v1467->cache_age;
      int v1559 = v1558[v1745];
      int * v1560 = v1467->cache_age;
      int v1817 = v1559 + ((int)((unsigned int)(v1559 - v1553) >> 31));
      v1560[v1745] = v1817;
      int * v1562 = v1467->cache_age;
      v1562[v1780] = 0;
      v1565 = v1780;
    }
    int * v1566 = v1467->cache_vals;
    int v1820 = v1565 * 2;
    int v1567 = v1566[v1820];
    int * v1568 = v1467->cache_vals;
    int v1822 = (v1565 * 2) + 1;
    int v1569 = v1568[v1822];
    int * v1570 = v1467->cache_vals;
    int v1824 = (((((int)((unsigned int)((int)((unsigned int)v1469 >> 2)) >> 1)) & 1) * 2) + ((((v1495 + ((~(((v1497 ^ -1) | (-(v1497 ^ -1))) >> 31)) & 2)) - (v1499 + ((~(((v1501 ^ -1) | (-(v1501 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
    v1570[v1824] = v1567;
    int * v1572 = v1467->cache_vals;
    int v1827 = ((((((int)((unsigned int)((int)((unsigned int)v1469 >> 2)) >> 1)) & 1) * 2) + ((((v1495 + ((~(((v1497 ^ -1) | (-(v1497 ^ -1))) >> 31)) & 2)) - (v1499 + ((~(((v1501 ^ -1) | (-(v1501 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
    v1572[v1827] = v1569;
    int * v1574 = v1467->cache_tags;
    int v1830 = ((((int)((unsigned int)((int)((unsigned int)v1469 >> 2)) >> 1)) & 1) * 2) + ((((v1495 + ((~(((v1497 ^ -1) | (-(v1497 ^ -1))) >> 31)) & 2)) - (v1499 + ((~(((v1501 ^ -1) | (-(v1501 ^ -1))) >> 31)) & 2))) >> 31) & 1);
    int v1831 = (int)((unsigned int)((int)((unsigned int)v1469 >> 2)) >> 1);
    v1574[v1830] = v1831;
    int * v1576 = v1467->cache_dirty;
    v1576[v1830] = 0;
    int * v1578 = v1467->cache_age;
    v1578[v1830] = 1;
    int * v1580 = v1467->cache_age;
    int v1581 = v1580[v1830];
    int * v1582 = v1467->cache_age;
    int v1583 = v1582[v1739];
    int * v1584 = v1467->cache_age;
    int v1839 = v1583 + ((int)((unsigned int)(v1583 - v1581) >> 31));
    v1584[v1739] = v1839;
    int * v1586 = v1467->cache_age;
    int v1587 = v1586[v1741];
    int * v1588 = v1467->cache_age;
    int v1842 = v1587 + ((int)((unsigned int)(v1587 - v1581) >> 31));
    v1588[v1741] = v1842;
    int * v1590 = v1467->cache_age;
    v1590[v1830] = 0;
    v1593 = v1830;
  }
  int v1845 = (v1593 * 2) + (((int)((unsigned int)v1469 >> 2)) & 1);
  int v1594 = v1480[v1845];
  int * v1595 = v1467->regs;
  v1595[12] = v1594;
  struct StateT * v1597 = v1454->b;
  int * v1598 = v1597->regs;
  int v1599 = v1598[11];
  int * v1600 = v1597->cache_tags;
  int v1852 = (((int)((unsigned int)((int)((unsigned int)v1599 >> 2)) >> 1)) & 1) * 2;
  int v1601 = v1600[v1852];
  int * v1602 = v1597->cache_tags;
  int v1854 = ((((int)((unsigned int)((int)((unsigned int)v1599 >> 2)) >> 1)) & 1) * 2) + 1;
  int v1603 = v1602[v1854];
  int * v1604 = v1597->cache_tags;
  int v1856 = 4 + ((((int)((unsigned int)((int)((unsigned int)v1599 >> 2)) >> 1)) & 3) * 2);
  int v1605 = v1604[v1856];
  int * v1606 = v1597->cache_tags;
  int v1858 = (4 + ((((int)((unsigned int)((int)((unsigned int)v1599 >> 2)) >> 1)) & 3) * 2)) + 1;
  int v1607 = v1606[v1858];
  int v1608 = v1597->timer;
  int v1859 = v1608 + ((100 ^ (((~(((v1605 ^ ((int)((unsigned int)((int)((unsigned int)v1599 >> 2)) >> 1))) | (-(v1605 ^ ((int)((unsigned int)((int)((unsigned int)v1599 >> 2)) >> 1))))) >> 31)) | (~(((v1607 ^ ((int)((unsigned int)((int)((unsigned int)v1599 >> 2)) >> 1))) | (-(v1607 ^ ((int)((unsigned int)((int)((unsigned int)v1599 >> 2)) >> 1))))) >> 31))) & 104)) ^ (((~(((v1601 ^ ((int)((unsigned int)((int)((unsigned int)v1599 >> 2)) >> 1))) | (-(v1601 ^ ((int)((unsigned int)((int)((unsigned int)v1599 >> 2)) >> 1))))) >> 31)) | (~(((v1603 ^ ((int)((unsigned int)((int)((unsigned int)v1599 >> 2)) >> 1))) | (-(v1603 ^ ((int)((unsigned int)((int)((unsigned int)v1599 >> 2)) >> 1))))) >> 31))) & (1 ^ (100 ^ (((~(((v1605 ^ ((int)((unsigned int)((int)((unsigned int)v1599 >> 2)) >> 1))) | (-(v1605 ^ ((int)((unsigned int)((int)((unsigned int)v1599 >> 2)) >> 1))))) >> 31)) | (~(((v1607 ^ ((int)((unsigned int)((int)((unsigned int)v1599 >> 2)) >> 1))) | (-(v1607 ^ ((int)((unsigned int)((int)((unsigned int)v1599 >> 2)) >> 1))))) >> 31))) & 104)))));
  v1597->timer = v1859;
  int * v1610 = v1597->cache_vals;
  bool v1860 = !(((~(((v1601 ^ ((int)((unsigned int)((int)((unsigned int)v1599 >> 2)) >> 1))) | (-(v1601 ^ ((int)((unsigned int)((int)((unsigned int)v1599 >> 2)) >> 1))))) >> 31)) | (~(((v1603 ^ ((int)((unsigned int)((int)((unsigned int)v1599 >> 2)) >> 1))) | (-(v1603 ^ ((int)((unsigned int)((int)((unsigned int)v1599 >> 2)) >> 1))))) >> 31))) == 0);
  int v1723;
  if (v1860) {
    int * v1611 = v1597->cache_age;
    int v1862 = ((((int)((unsigned int)((int)((unsigned int)v1599 >> 2)) >> 1)) & 1) * 2) + ((~(((v1603 ^ ((int)((unsigned int)((int)((unsigned int)v1599 >> 2)) >> 1))) | (-(v1603 ^ ((int)((unsigned int)((int)((unsigned int)v1599 >> 2)) >> 1))))) >> 31)) & 1);
    int v1612 = v1611[v1862];
    int * v1613 = v1597->cache_age;
    int v1614 = v1613[v1852];
    int * v1615 = v1597->cache_age;
    int v1865 = v1614 + ((int)((unsigned int)(v1614 - v1612) >> 31));
    v1615[v1852] = v1865;
    int * v1617 = v1597->cache_age;
    int v1618 = v1617[v1854];
    int * v1619 = v1597->cache_age;
    int v1868 = v1618 + ((int)((unsigned int)(v1618 - v1612) >> 31));
    v1619[v1854] = v1868;
    int * v1621 = v1597->cache_age;
    v1621[v1862] = 0;
    v1723 = v1862;
  } else {
    int * v1624 = v1597->cache_age;
    int v1872 = (((int)((unsigned int)((int)((unsigned int)v1599 >> 2)) >> 1)) & 1) * 2;
    int v1625 = v1624[v1872];
    int * v1626 = v1597->cache_tags;
    int v1627 = v1626[v1872];
    int * v1628 = v1597->cache_age;
    int v1629 = v1628[v1854];
    int * v1630 = v1597->cache_tags;
    int v1631 = v1630[v1854];
    bool v1876 = !(((~(((v1605 ^ ((int)((unsigned int)((int)((unsigned int)v1599 >> 2)) >> 1))) | (-(v1605 ^ ((int)((unsigned int)((int)((unsigned int)v1599 >> 2)) >> 1))))) >> 31)) | (~(((v1607 ^ ((int)((unsigned int)((int)((unsigned int)v1599 >> 2)) >> 1))) | (-(v1607 ^ ((int)((unsigned int)((int)((unsigned int)v1599 >> 2)) >> 1))))) >> 31))) == 0);
    int v1695;
    if (v1876) {
      int * v1632 = v1597->cache_age;
      int v1878 = (4 + ((((int)((unsigned int)((int)((unsigned int)v1599 >> 2)) >> 1)) & 3) * 2)) + ((~(((v1607 ^ ((int)((unsigned int)((int)((unsigned int)v1599 >> 2)) >> 1))) | (-(v1607 ^ ((int)((unsigned int)((int)((unsigned int)v1599 >> 2)) >> 1))))) >> 31)) & 1);
      int v1633 = v1632[v1878];
      int * v1634 = v1597->cache_age;
      int v1635 = v1634[v1856];
      int * v1636 = v1597->cache_age;
      int v1881 = v1635 + ((int)((unsigned int)(v1635 - v1633) >> 31));
      v1636[v1856] = v1881;
      int * v1638 = v1597->cache_age;
      int v1639 = v1638[v1858];
      int * v1640 = v1597->cache_age;
      int v1884 = v1639 + ((int)((unsigned int)(v1639 - v1633) >> 31));
      v1640[v1858] = v1884;
      int * v1642 = v1597->cache_age;
      v1642[v1878] = 0;
      v1695 = v1878;
    } else {
      int * v1645 = v1597->cache_age;
      int v1888 = 4 + ((((int)((unsigned int)((int)((unsigned int)v1599 >> 2)) >> 1)) & 3) * 2);
      int v1646 = v1645[v1888];
      int * v1647 = v1597->cache_tags;
      int v1648 = v1647[v1888];
      int * v1649 = v1597->cache_age;
      int v1650 = v1649[v1858];
      int * v1651 = v1597->cache_tags;
      int v1652 = v1651[v1858];
      int * v1653 = v1597->cache_dirty;
      int v1893 = (4 + ((((int)((unsigned int)((int)((unsigned int)v1599 >> 2)) >> 1)) & 3) * 2)) + ((((v1646 + ((~(((v1648 ^ -1) | (-(v1648 ^ -1))) >> 31)) & 2)) - (v1650 + ((~(((v1652 ^ -1) | (-(v1652 ^ -1))) >> 31)) & 2))) >> 31) & 1);
      int v1654 = v1653[v1893];
      bool v1894 = !(v1654 == 0);
      if (v1894) {
        int * v1655 = v1597->cache_tags;
        int v1656 = v1655[v1893];
        int * v1657 = v1597->cache_vals;
        int v1897 = ((4 + ((((int)((unsigned int)((int)((unsigned int)v1599 >> 2)) >> 1)) & 3) * 2)) + ((((v1646 + ((~(((v1648 ^ -1) | (-(v1648 ^ -1))) >> 31)) & 2)) - (v1650 + ((~(((v1652 ^ -1) | (-(v1652 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
        int v1658 = v1657[v1897];
        int * v1659 = v1597->cache_vals;
        int v1899 = (((4 + ((((int)((unsigned int)((int)((unsigned int)v1599 >> 2)) >> 1)) & 3) * 2)) + ((((v1646 + ((~(((v1648 ^ -1) | (-(v1648 ^ -1))) >> 31)) & 2)) - (v1650 + ((~(((v1652 ^ -1) | (-(v1652 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
        int v1660 = v1659[v1899];
        int * v1661 = v1597->mem;
        int v1901 = v1656 * 2;
        v1661[v1901] = v1658;
        int * v1663 = v1597->mem;
        int v1904 = (v1656 * 2) + 1;
        v1663[v1904] = v1660;
        ;
      } else {
        ;
      }
      int * v1668 = v1597->mem;
      int v1909 = ((int)((unsigned int)((int)((unsigned int)v1599 >> 2)) >> 1)) * 2;
      int v1669 = v1668[v1909];
      int * v1670 = v1597->mem;
      int v1911 = (((int)((unsigned int)((int)((unsigned int)v1599 >> 2)) >> 1)) * 2) + 1;
      int v1671 = v1670[v1911];
      int * v1672 = v1597->cache_vals;
      int v1913 = ((4 + ((((int)((unsigned int)((int)((unsigned int)v1599 >> 2)) >> 1)) & 3) * 2)) + ((((v1646 + ((~(((v1648 ^ -1) | (-(v1648 ^ -1))) >> 31)) & 2)) - (v1650 + ((~(((v1652 ^ -1) | (-(v1652 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
      v1672[v1913] = v1669;
      int * v1674 = v1597->cache_vals;
      int v1916 = (((4 + ((((int)((unsigned int)((int)((unsigned int)v1599 >> 2)) >> 1)) & 3) * 2)) + ((((v1646 + ((~(((v1648 ^ -1) | (-(v1648 ^ -1))) >> 31)) & 2)) - (v1650 + ((~(((v1652 ^ -1) | (-(v1652 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
      v1674[v1916] = v1671;
      int * v1676 = v1597->cache_tags;
      int v1919 = (int)((unsigned int)((int)((unsigned int)v1599 >> 2)) >> 1);
      v1676[v1893] = v1919;
      int * v1678 = v1597->cache_dirty;
      v1678[v1893] = 0;
      int * v1680 = v1597->cache_age;
      v1680[v1893] = 1;
      int * v1682 = v1597->cache_age;
      int v1683 = v1682[v1893];
      int * v1684 = v1597->cache_age;
      int v1685 = v1684[v1856];
      int * v1686 = v1597->cache_age;
      int v1927 = v1685 + ((int)((unsigned int)(v1685 - v1683) >> 31));
      v1686[v1856] = v1927;
      int * v1688 = v1597->cache_age;
      int v1689 = v1688[v1858];
      int * v1690 = v1597->cache_age;
      int v1930 = v1689 + ((int)((unsigned int)(v1689 - v1683) >> 31));
      v1690[v1858] = v1930;
      int * v1692 = v1597->cache_age;
      v1692[v1893] = 0;
      v1695 = v1893;
    }
    int * v1696 = v1597->cache_vals;
    int v1933 = v1695 * 2;
    int v1697 = v1696[v1933];
    int * v1698 = v1597->cache_vals;
    int v1935 = (v1695 * 2) + 1;
    int v1699 = v1698[v1935];
    int * v1700 = v1597->cache_vals;
    int v1937 = (((((int)((unsigned int)((int)((unsigned int)v1599 >> 2)) >> 1)) & 1) * 2) + ((((v1625 + ((~(((v1627 ^ -1) | (-(v1627 ^ -1))) >> 31)) & 2)) - (v1629 + ((~(((v1631 ^ -1) | (-(v1631 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
    v1700[v1937] = v1697;
    int * v1702 = v1597->cache_vals;
    int v1940 = ((((((int)((unsigned int)((int)((unsigned int)v1599 >> 2)) >> 1)) & 1) * 2) + ((((v1625 + ((~(((v1627 ^ -1) | (-(v1627 ^ -1))) >> 31)) & 2)) - (v1629 + ((~(((v1631 ^ -1) | (-(v1631 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
    v1702[v1940] = v1699;
    int * v1704 = v1597->cache_tags;
    int v1943 = ((((int)((unsigned int)((int)((unsigned int)v1599 >> 2)) >> 1)) & 1) * 2) + ((((v1625 + ((~(((v1627 ^ -1) | (-(v1627 ^ -1))) >> 31)) & 2)) - (v1629 + ((~(((v1631 ^ -1) | (-(v1631 ^ -1))) >> 31)) & 2))) >> 31) & 1);
    int v1944 = (int)((unsigned int)((int)((unsigned int)v1599 >> 2)) >> 1);
    v1704[v1943] = v1944;
    int * v1706 = v1597->cache_dirty;
    v1706[v1943] = 0;
    int * v1708 = v1597->cache_age;
    v1708[v1943] = 1;
    int * v1710 = v1597->cache_age;
    int v1711 = v1710[v1943];
    int * v1712 = v1597->cache_age;
    int v1713 = v1712[v1852];
    int * v1714 = v1597->cache_age;
    int v1952 = v1713 + ((int)((unsigned int)(v1713 - v1711) >> 31));
    v1714[v1852] = v1952;
    int * v1716 = v1597->cache_age;
    int v1717 = v1716[v1854];
    int * v1718 = v1597->cache_age;
    int v1955 = v1717 + ((int)((unsigned int)(v1717 - v1711) >> 31));
    v1718[v1854] = v1955;
    int * v1720 = v1597->cache_age;
    v1720[v1943] = 0;
    v1723 = v1943;
  }
  int v1958 = (v1723 * 2) + (((int)((unsigned int)v1599 >> 2)) & 1);
  int v1724 = v1610[v1958];
  int * v1725 = v1597->regs;
  v1725[12] = v1724;
  return v1454;
}

struct StateT2 * slot_5(struct StateT2 * v1411) {
  struct StateT * v1412 = v1411->a;
  int v1413 = v1412->timer;
  struct StateT * v1414 = v1411->b;
  int v1415 = v1414->timer;
  bool v1438 = v1413 == v1415;
  squared_assert(v1438);
  squared_assume(v1438);
  struct StateT * v1418 = v1411->a;
  int v1419 = v1418->timer;
  int v1440 = v1419 + 1;
  v1418->timer = v1440;
  struct StateT * v1421 = v1411->b;
  int v1422 = v1421->timer;
  int v1442 = v1422 + 1;
  v1421->timer = v1442;
  struct StateT * v1424 = v1411->a;
  int * v1425 = v1424->regs;
  int v1426 = v1425[11];
  int * v1427 = v1424->regs;
  int v1447 = v1426 << 2;
  v1427[11] = v1447;
  struct StateT * v1429 = v1411->b;
  int * v1430 = v1429->regs;
  int v1431 = v1430[11];
  int * v1432 = v1429->regs;
  int v1451 = v1431 << 2;
  v1432[11] = v1451;
  struct StateT2 * v1434 = slot_6(v1411);
  return v1434;
}

struct StateT2 * slot_4(struct StateT2 * v901) {
  struct StateT * v902 = v901->a;
  int v903 = v902->timer;
  struct StateT * v904 = v901->b;
  int v905 = v904->timer;
  bool v1178 = v903 == v905;
  squared_assert(v1178);
  squared_assume(v1178);
  struct StateT * v908 = v901->a;
  int v909 = v908->timer;
  int v1180 = v909 + 1;
  v908->timer = v1180;
  struct StateT * v911 = v901->b;
  int v912 = v911->timer;
  int v1182 = v912 + 1;
  v911->timer = v1182;
  struct StateT * v914 = v901->a;
  int * v915 = v914->regs;
  int v916 = v915[6];
  int * v917 = v914->cache_tags;
  int v1187 = (((int)((unsigned int)((int)((unsigned int)v916 >> 2)) >> 1)) & 1) * 2;
  int v918 = v917[v1187];
  int * v919 = v914->cache_tags;
  int v1189 = ((((int)((unsigned int)((int)((unsigned int)v916 >> 2)) >> 1)) & 1) * 2) + 1;
  int v920 = v919[v1189];
  int * v921 = v914->cache_tags;
  int v1191 = 4 + ((((int)((unsigned int)((int)((unsigned int)v916 >> 2)) >> 1)) & 3) * 2);
  int v922 = v921[v1191];
  int * v923 = v914->cache_tags;
  int v1193 = (4 + ((((int)((unsigned int)((int)((unsigned int)v916 >> 2)) >> 1)) & 3) * 2)) + 1;
  int v924 = v923[v1193];
  int v925 = v914->timer;
  int v1194 = v925 + ((100 ^ (((~(((v922 ^ ((int)((unsigned int)((int)((unsigned int)v916 >> 2)) >> 1))) | (-(v922 ^ ((int)((unsigned int)((int)((unsigned int)v916 >> 2)) >> 1))))) >> 31)) | (~(((v924 ^ ((int)((unsigned int)((int)((unsigned int)v916 >> 2)) >> 1))) | (-(v924 ^ ((int)((unsigned int)((int)((unsigned int)v916 >> 2)) >> 1))))) >> 31))) & 104)) ^ (((~(((v918 ^ ((int)((unsigned int)((int)((unsigned int)v916 >> 2)) >> 1))) | (-(v918 ^ ((int)((unsigned int)((int)((unsigned int)v916 >> 2)) >> 1))))) >> 31)) | (~(((v920 ^ ((int)((unsigned int)((int)((unsigned int)v916 >> 2)) >> 1))) | (-(v920 ^ ((int)((unsigned int)((int)((unsigned int)v916 >> 2)) >> 1))))) >> 31))) & (1 ^ (100 ^ (((~(((v922 ^ ((int)((unsigned int)((int)((unsigned int)v916 >> 2)) >> 1))) | (-(v922 ^ ((int)((unsigned int)((int)((unsigned int)v916 >> 2)) >> 1))))) >> 31)) | (~(((v924 ^ ((int)((unsigned int)((int)((unsigned int)v916 >> 2)) >> 1))) | (-(v924 ^ ((int)((unsigned int)((int)((unsigned int)v916 >> 2)) >> 1))))) >> 31))) & 104)))));
  v914->timer = v1194;
  int * v927 = v914->cache_vals;
  bool v1195 = !(((~(((v918 ^ ((int)((unsigned int)((int)((unsigned int)v916 >> 2)) >> 1))) | (-(v918 ^ ((int)((unsigned int)((int)((unsigned int)v916 >> 2)) >> 1))))) >> 31)) | (~(((v920 ^ ((int)((unsigned int)((int)((unsigned int)v916 >> 2)) >> 1))) | (-(v920 ^ ((int)((unsigned int)((int)((unsigned int)v916 >> 2)) >> 1))))) >> 31))) == 0);
  int v1040;
  if (v1195) {
    int * v928 = v914->cache_age;
    int v1197 = ((((int)((unsigned int)((int)((unsigned int)v916 >> 2)) >> 1)) & 1) * 2) + ((~(((v920 ^ ((int)((unsigned int)((int)((unsigned int)v916 >> 2)) >> 1))) | (-(v920 ^ ((int)((unsigned int)((int)((unsigned int)v916 >> 2)) >> 1))))) >> 31)) & 1);
    int v929 = v928[v1197];
    int * v930 = v914->cache_age;
    int v931 = v930[v1187];
    int * v932 = v914->cache_age;
    int v1200 = v931 + ((int)((unsigned int)(v931 - v929) >> 31));
    v932[v1187] = v1200;
    int * v934 = v914->cache_age;
    int v935 = v934[v1189];
    int * v936 = v914->cache_age;
    int v1203 = v935 + ((int)((unsigned int)(v935 - v929) >> 31));
    v936[v1189] = v1203;
    int * v938 = v914->cache_age;
    v938[v1197] = 0;
    v1040 = v1197;
  } else {
    int * v941 = v914->cache_age;
    int v1207 = (((int)((unsigned int)((int)((unsigned int)v916 >> 2)) >> 1)) & 1) * 2;
    int v942 = v941[v1207];
    int * v943 = v914->cache_tags;
    int v944 = v943[v1207];
    int * v945 = v914->cache_age;
    int v946 = v945[v1189];
    int * v947 = v914->cache_tags;
    int v948 = v947[v1189];
    bool v1211 = !(((~(((v922 ^ ((int)((unsigned int)((int)((unsigned int)v916 >> 2)) >> 1))) | (-(v922 ^ ((int)((unsigned int)((int)((unsigned int)v916 >> 2)) >> 1))))) >> 31)) | (~(((v924 ^ ((int)((unsigned int)((int)((unsigned int)v916 >> 2)) >> 1))) | (-(v924 ^ ((int)((unsigned int)((int)((unsigned int)v916 >> 2)) >> 1))))) >> 31))) == 0);
    int v1012;
    if (v1211) {
      int * v949 = v914->cache_age;
      int v1213 = (4 + ((((int)((unsigned int)((int)((unsigned int)v916 >> 2)) >> 1)) & 3) * 2)) + ((~(((v924 ^ ((int)((unsigned int)((int)((unsigned int)v916 >> 2)) >> 1))) | (-(v924 ^ ((int)((unsigned int)((int)((unsigned int)v916 >> 2)) >> 1))))) >> 31)) & 1);
      int v950 = v949[v1213];
      int * v951 = v914->cache_age;
      int v952 = v951[v1191];
      int * v953 = v914->cache_age;
      int v1216 = v952 + ((int)((unsigned int)(v952 - v950) >> 31));
      v953[v1191] = v1216;
      int * v955 = v914->cache_age;
      int v956 = v955[v1193];
      int * v957 = v914->cache_age;
      int v1219 = v956 + ((int)((unsigned int)(v956 - v950) >> 31));
      v957[v1193] = v1219;
      int * v959 = v914->cache_age;
      v959[v1213] = 0;
      v1012 = v1213;
    } else {
      int * v962 = v914->cache_age;
      int v1223 = 4 + ((((int)((unsigned int)((int)((unsigned int)v916 >> 2)) >> 1)) & 3) * 2);
      int v963 = v962[v1223];
      int * v964 = v914->cache_tags;
      int v965 = v964[v1223];
      int * v966 = v914->cache_age;
      int v967 = v966[v1193];
      int * v968 = v914->cache_tags;
      int v969 = v968[v1193];
      int * v970 = v914->cache_dirty;
      int v1228 = (4 + ((((int)((unsigned int)((int)((unsigned int)v916 >> 2)) >> 1)) & 3) * 2)) + ((((v963 + ((~(((v965 ^ -1) | (-(v965 ^ -1))) >> 31)) & 2)) - (v967 + ((~(((v969 ^ -1) | (-(v969 ^ -1))) >> 31)) & 2))) >> 31) & 1);
      int v971 = v970[v1228];
      bool v1229 = !(v971 == 0);
      if (v1229) {
        int * v972 = v914->cache_tags;
        int v973 = v972[v1228];
        int * v974 = v914->cache_vals;
        int v1232 = ((4 + ((((int)((unsigned int)((int)((unsigned int)v916 >> 2)) >> 1)) & 3) * 2)) + ((((v963 + ((~(((v965 ^ -1) | (-(v965 ^ -1))) >> 31)) & 2)) - (v967 + ((~(((v969 ^ -1) | (-(v969 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
        int v975 = v974[v1232];
        int * v976 = v914->cache_vals;
        int v1234 = (((4 + ((((int)((unsigned int)((int)((unsigned int)v916 >> 2)) >> 1)) & 3) * 2)) + ((((v963 + ((~(((v965 ^ -1) | (-(v965 ^ -1))) >> 31)) & 2)) - (v967 + ((~(((v969 ^ -1) | (-(v969 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
        int v977 = v976[v1234];
        int * v978 = v914->mem;
        int v1236 = v973 * 2;
        v978[v1236] = v975;
        int * v980 = v914->mem;
        int v1239 = (v973 * 2) + 1;
        v980[v1239] = v977;
        ;
      } else {
        ;
      }
      int * v985 = v914->mem;
      int v1244 = ((int)((unsigned int)((int)((unsigned int)v916 >> 2)) >> 1)) * 2;
      int v986 = v985[v1244];
      int * v987 = v914->mem;
      int v1246 = (((int)((unsigned int)((int)((unsigned int)v916 >> 2)) >> 1)) * 2) + 1;
      int v988 = v987[v1246];
      int * v989 = v914->cache_vals;
      int v1248 = ((4 + ((((int)((unsigned int)((int)((unsigned int)v916 >> 2)) >> 1)) & 3) * 2)) + ((((v963 + ((~(((v965 ^ -1) | (-(v965 ^ -1))) >> 31)) & 2)) - (v967 + ((~(((v969 ^ -1) | (-(v969 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
      v989[v1248] = v986;
      int * v991 = v914->cache_vals;
      int v1251 = (((4 + ((((int)((unsigned int)((int)((unsigned int)v916 >> 2)) >> 1)) & 3) * 2)) + ((((v963 + ((~(((v965 ^ -1) | (-(v965 ^ -1))) >> 31)) & 2)) - (v967 + ((~(((v969 ^ -1) | (-(v969 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
      v991[v1251] = v988;
      int * v993 = v914->cache_tags;
      int v1254 = (int)((unsigned int)((int)((unsigned int)v916 >> 2)) >> 1);
      v993[v1228] = v1254;
      int * v995 = v914->cache_dirty;
      v995[v1228] = 0;
      int * v997 = v914->cache_age;
      v997[v1228] = 1;
      int * v999 = v914->cache_age;
      int v1000 = v999[v1228];
      int * v1001 = v914->cache_age;
      int v1002 = v1001[v1191];
      int * v1003 = v914->cache_age;
      int v1262 = v1002 + ((int)((unsigned int)(v1002 - v1000) >> 31));
      v1003[v1191] = v1262;
      int * v1005 = v914->cache_age;
      int v1006 = v1005[v1193];
      int * v1007 = v914->cache_age;
      int v1265 = v1006 + ((int)((unsigned int)(v1006 - v1000) >> 31));
      v1007[v1193] = v1265;
      int * v1009 = v914->cache_age;
      v1009[v1228] = 0;
      v1012 = v1228;
    }
    int * v1013 = v914->cache_vals;
    int v1268 = v1012 * 2;
    int v1014 = v1013[v1268];
    int * v1015 = v914->cache_vals;
    int v1270 = (v1012 * 2) + 1;
    int v1016 = v1015[v1270];
    int * v1017 = v914->cache_vals;
    int v1272 = (((((int)((unsigned int)((int)((unsigned int)v916 >> 2)) >> 1)) & 1) * 2) + ((((v942 + ((~(((v944 ^ -1) | (-(v944 ^ -1))) >> 31)) & 2)) - (v946 + ((~(((v948 ^ -1) | (-(v948 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
    v1017[v1272] = v1014;
    int * v1019 = v914->cache_vals;
    int v1275 = ((((((int)((unsigned int)((int)((unsigned int)v916 >> 2)) >> 1)) & 1) * 2) + ((((v942 + ((~(((v944 ^ -1) | (-(v944 ^ -1))) >> 31)) & 2)) - (v946 + ((~(((v948 ^ -1) | (-(v948 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
    v1019[v1275] = v1016;
    int * v1021 = v914->cache_tags;
    int v1278 = ((((int)((unsigned int)((int)((unsigned int)v916 >> 2)) >> 1)) & 1) * 2) + ((((v942 + ((~(((v944 ^ -1) | (-(v944 ^ -1))) >> 31)) & 2)) - (v946 + ((~(((v948 ^ -1) | (-(v948 ^ -1))) >> 31)) & 2))) >> 31) & 1);
    int v1279 = (int)((unsigned int)((int)((unsigned int)v916 >> 2)) >> 1);
    v1021[v1278] = v1279;
    int * v1023 = v914->cache_dirty;
    v1023[v1278] = 0;
    int * v1025 = v914->cache_age;
    v1025[v1278] = 1;
    int * v1027 = v914->cache_age;
    int v1028 = v1027[v1278];
    int * v1029 = v914->cache_age;
    int v1030 = v1029[v1187];
    int * v1031 = v914->cache_age;
    int v1287 = v1030 + ((int)((unsigned int)(v1030 - v1028) >> 31));
    v1031[v1187] = v1287;
    int * v1033 = v914->cache_age;
    int v1034 = v1033[v1189];
    int * v1035 = v914->cache_age;
    int v1290 = v1034 + ((int)((unsigned int)(v1034 - v1028) >> 31));
    v1035[v1189] = v1290;
    int * v1037 = v914->cache_age;
    v1037[v1278] = 0;
    v1040 = v1278;
  }
  int v1293 = (v1040 * 2) + (((int)((unsigned int)v916 >> 2)) & 1);
  int v1041 = v927[v1293];
  int * v1042 = v914->regs;
  v1042[11] = v1041;
  struct StateT * v1044 = v901->b;
  int * v1045 = v1044->regs;
  int v1046 = v1045[6];
  int * v1047 = v1044->cache_tags;
  int v1300 = (((int)((unsigned int)((int)((unsigned int)v1046 >> 2)) >> 1)) & 1) * 2;
  int v1048 = v1047[v1300];
  int * v1049 = v1044->cache_tags;
  int v1302 = ((((int)((unsigned int)((int)((unsigned int)v1046 >> 2)) >> 1)) & 1) * 2) + 1;
  int v1050 = v1049[v1302];
  int * v1051 = v1044->cache_tags;
  int v1304 = 4 + ((((int)((unsigned int)((int)((unsigned int)v1046 >> 2)) >> 1)) & 3) * 2);
  int v1052 = v1051[v1304];
  int * v1053 = v1044->cache_tags;
  int v1306 = (4 + ((((int)((unsigned int)((int)((unsigned int)v1046 >> 2)) >> 1)) & 3) * 2)) + 1;
  int v1054 = v1053[v1306];
  int v1055 = v1044->timer;
  int v1307 = v1055 + ((100 ^ (((~(((v1052 ^ ((int)((unsigned int)((int)((unsigned int)v1046 >> 2)) >> 1))) | (-(v1052 ^ ((int)((unsigned int)((int)((unsigned int)v1046 >> 2)) >> 1))))) >> 31)) | (~(((v1054 ^ ((int)((unsigned int)((int)((unsigned int)v1046 >> 2)) >> 1))) | (-(v1054 ^ ((int)((unsigned int)((int)((unsigned int)v1046 >> 2)) >> 1))))) >> 31))) & 104)) ^ (((~(((v1048 ^ ((int)((unsigned int)((int)((unsigned int)v1046 >> 2)) >> 1))) | (-(v1048 ^ ((int)((unsigned int)((int)((unsigned int)v1046 >> 2)) >> 1))))) >> 31)) | (~(((v1050 ^ ((int)((unsigned int)((int)((unsigned int)v1046 >> 2)) >> 1))) | (-(v1050 ^ ((int)((unsigned int)((int)((unsigned int)v1046 >> 2)) >> 1))))) >> 31))) & (1 ^ (100 ^ (((~(((v1052 ^ ((int)((unsigned int)((int)((unsigned int)v1046 >> 2)) >> 1))) | (-(v1052 ^ ((int)((unsigned int)((int)((unsigned int)v1046 >> 2)) >> 1))))) >> 31)) | (~(((v1054 ^ ((int)((unsigned int)((int)((unsigned int)v1046 >> 2)) >> 1))) | (-(v1054 ^ ((int)((unsigned int)((int)((unsigned int)v1046 >> 2)) >> 1))))) >> 31))) & 104)))));
  v1044->timer = v1307;
  int * v1057 = v1044->cache_vals;
  bool v1308 = !(((~(((v1048 ^ ((int)((unsigned int)((int)((unsigned int)v1046 >> 2)) >> 1))) | (-(v1048 ^ ((int)((unsigned int)((int)((unsigned int)v1046 >> 2)) >> 1))))) >> 31)) | (~(((v1050 ^ ((int)((unsigned int)((int)((unsigned int)v1046 >> 2)) >> 1))) | (-(v1050 ^ ((int)((unsigned int)((int)((unsigned int)v1046 >> 2)) >> 1))))) >> 31))) == 0);
  int v1170;
  if (v1308) {
    int * v1058 = v1044->cache_age;
    int v1310 = ((((int)((unsigned int)((int)((unsigned int)v1046 >> 2)) >> 1)) & 1) * 2) + ((~(((v1050 ^ ((int)((unsigned int)((int)((unsigned int)v1046 >> 2)) >> 1))) | (-(v1050 ^ ((int)((unsigned int)((int)((unsigned int)v1046 >> 2)) >> 1))))) >> 31)) & 1);
    int v1059 = v1058[v1310];
    int * v1060 = v1044->cache_age;
    int v1061 = v1060[v1300];
    int * v1062 = v1044->cache_age;
    int v1313 = v1061 + ((int)((unsigned int)(v1061 - v1059) >> 31));
    v1062[v1300] = v1313;
    int * v1064 = v1044->cache_age;
    int v1065 = v1064[v1302];
    int * v1066 = v1044->cache_age;
    int v1316 = v1065 + ((int)((unsigned int)(v1065 - v1059) >> 31));
    v1066[v1302] = v1316;
    int * v1068 = v1044->cache_age;
    v1068[v1310] = 0;
    v1170 = v1310;
  } else {
    int * v1071 = v1044->cache_age;
    int v1320 = (((int)((unsigned int)((int)((unsigned int)v1046 >> 2)) >> 1)) & 1) * 2;
    int v1072 = v1071[v1320];
    int * v1073 = v1044->cache_tags;
    int v1074 = v1073[v1320];
    int * v1075 = v1044->cache_age;
    int v1076 = v1075[v1302];
    int * v1077 = v1044->cache_tags;
    int v1078 = v1077[v1302];
    bool v1324 = !(((~(((v1052 ^ ((int)((unsigned int)((int)((unsigned int)v1046 >> 2)) >> 1))) | (-(v1052 ^ ((int)((unsigned int)((int)((unsigned int)v1046 >> 2)) >> 1))))) >> 31)) | (~(((v1054 ^ ((int)((unsigned int)((int)((unsigned int)v1046 >> 2)) >> 1))) | (-(v1054 ^ ((int)((unsigned int)((int)((unsigned int)v1046 >> 2)) >> 1))))) >> 31))) == 0);
    int v1142;
    if (v1324) {
      int * v1079 = v1044->cache_age;
      int v1326 = (4 + ((((int)((unsigned int)((int)((unsigned int)v1046 >> 2)) >> 1)) & 3) * 2)) + ((~(((v1054 ^ ((int)((unsigned int)((int)((unsigned int)v1046 >> 2)) >> 1))) | (-(v1054 ^ ((int)((unsigned int)((int)((unsigned int)v1046 >> 2)) >> 1))))) >> 31)) & 1);
      int v1080 = v1079[v1326];
      int * v1081 = v1044->cache_age;
      int v1082 = v1081[v1304];
      int * v1083 = v1044->cache_age;
      int v1329 = v1082 + ((int)((unsigned int)(v1082 - v1080) >> 31));
      v1083[v1304] = v1329;
      int * v1085 = v1044->cache_age;
      int v1086 = v1085[v1306];
      int * v1087 = v1044->cache_age;
      int v1332 = v1086 + ((int)((unsigned int)(v1086 - v1080) >> 31));
      v1087[v1306] = v1332;
      int * v1089 = v1044->cache_age;
      v1089[v1326] = 0;
      v1142 = v1326;
    } else {
      int * v1092 = v1044->cache_age;
      int v1336 = 4 + ((((int)((unsigned int)((int)((unsigned int)v1046 >> 2)) >> 1)) & 3) * 2);
      int v1093 = v1092[v1336];
      int * v1094 = v1044->cache_tags;
      int v1095 = v1094[v1336];
      int * v1096 = v1044->cache_age;
      int v1097 = v1096[v1306];
      int * v1098 = v1044->cache_tags;
      int v1099 = v1098[v1306];
      int * v1100 = v1044->cache_dirty;
      int v1341 = (4 + ((((int)((unsigned int)((int)((unsigned int)v1046 >> 2)) >> 1)) & 3) * 2)) + ((((v1093 + ((~(((v1095 ^ -1) | (-(v1095 ^ -1))) >> 31)) & 2)) - (v1097 + ((~(((v1099 ^ -1) | (-(v1099 ^ -1))) >> 31)) & 2))) >> 31) & 1);
      int v1101 = v1100[v1341];
      bool v1342 = !(v1101 == 0);
      if (v1342) {
        int * v1102 = v1044->cache_tags;
        int v1103 = v1102[v1341];
        int * v1104 = v1044->cache_vals;
        int v1345 = ((4 + ((((int)((unsigned int)((int)((unsigned int)v1046 >> 2)) >> 1)) & 3) * 2)) + ((((v1093 + ((~(((v1095 ^ -1) | (-(v1095 ^ -1))) >> 31)) & 2)) - (v1097 + ((~(((v1099 ^ -1) | (-(v1099 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
        int v1105 = v1104[v1345];
        int * v1106 = v1044->cache_vals;
        int v1347 = (((4 + ((((int)((unsigned int)((int)((unsigned int)v1046 >> 2)) >> 1)) & 3) * 2)) + ((((v1093 + ((~(((v1095 ^ -1) | (-(v1095 ^ -1))) >> 31)) & 2)) - (v1097 + ((~(((v1099 ^ -1) | (-(v1099 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
        int v1107 = v1106[v1347];
        int * v1108 = v1044->mem;
        int v1349 = v1103 * 2;
        v1108[v1349] = v1105;
        int * v1110 = v1044->mem;
        int v1352 = (v1103 * 2) + 1;
        v1110[v1352] = v1107;
        ;
      } else {
        ;
      }
      int * v1115 = v1044->mem;
      int v1357 = ((int)((unsigned int)((int)((unsigned int)v1046 >> 2)) >> 1)) * 2;
      int v1116 = v1115[v1357];
      int * v1117 = v1044->mem;
      int v1359 = (((int)((unsigned int)((int)((unsigned int)v1046 >> 2)) >> 1)) * 2) + 1;
      int v1118 = v1117[v1359];
      int * v1119 = v1044->cache_vals;
      int v1361 = ((4 + ((((int)((unsigned int)((int)((unsigned int)v1046 >> 2)) >> 1)) & 3) * 2)) + ((((v1093 + ((~(((v1095 ^ -1) | (-(v1095 ^ -1))) >> 31)) & 2)) - (v1097 + ((~(((v1099 ^ -1) | (-(v1099 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
      v1119[v1361] = v1116;
      int * v1121 = v1044->cache_vals;
      int v1364 = (((4 + ((((int)((unsigned int)((int)((unsigned int)v1046 >> 2)) >> 1)) & 3) * 2)) + ((((v1093 + ((~(((v1095 ^ -1) | (-(v1095 ^ -1))) >> 31)) & 2)) - (v1097 + ((~(((v1099 ^ -1) | (-(v1099 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
      v1121[v1364] = v1118;
      int * v1123 = v1044->cache_tags;
      int v1367 = (int)((unsigned int)((int)((unsigned int)v1046 >> 2)) >> 1);
      v1123[v1341] = v1367;
      int * v1125 = v1044->cache_dirty;
      v1125[v1341] = 0;
      int * v1127 = v1044->cache_age;
      v1127[v1341] = 1;
      int * v1129 = v1044->cache_age;
      int v1130 = v1129[v1341];
      int * v1131 = v1044->cache_age;
      int v1132 = v1131[v1304];
      int * v1133 = v1044->cache_age;
      int v1375 = v1132 + ((int)((unsigned int)(v1132 - v1130) >> 31));
      v1133[v1304] = v1375;
      int * v1135 = v1044->cache_age;
      int v1136 = v1135[v1306];
      int * v1137 = v1044->cache_age;
      int v1378 = v1136 + ((int)((unsigned int)(v1136 - v1130) >> 31));
      v1137[v1306] = v1378;
      int * v1139 = v1044->cache_age;
      v1139[v1341] = 0;
      v1142 = v1341;
    }
    int * v1143 = v1044->cache_vals;
    int v1381 = v1142 * 2;
    int v1144 = v1143[v1381];
    int * v1145 = v1044->cache_vals;
    int v1383 = (v1142 * 2) + 1;
    int v1146 = v1145[v1383];
    int * v1147 = v1044->cache_vals;
    int v1385 = (((((int)((unsigned int)((int)((unsigned int)v1046 >> 2)) >> 1)) & 1) * 2) + ((((v1072 + ((~(((v1074 ^ -1) | (-(v1074 ^ -1))) >> 31)) & 2)) - (v1076 + ((~(((v1078 ^ -1) | (-(v1078 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
    v1147[v1385] = v1144;
    int * v1149 = v1044->cache_vals;
    int v1388 = ((((((int)((unsigned int)((int)((unsigned int)v1046 >> 2)) >> 1)) & 1) * 2) + ((((v1072 + ((~(((v1074 ^ -1) | (-(v1074 ^ -1))) >> 31)) & 2)) - (v1076 + ((~(((v1078 ^ -1) | (-(v1078 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
    v1149[v1388] = v1146;
    int * v1151 = v1044->cache_tags;
    int v1391 = ((((int)((unsigned int)((int)((unsigned int)v1046 >> 2)) >> 1)) & 1) * 2) + ((((v1072 + ((~(((v1074 ^ -1) | (-(v1074 ^ -1))) >> 31)) & 2)) - (v1076 + ((~(((v1078 ^ -1) | (-(v1078 ^ -1))) >> 31)) & 2))) >> 31) & 1);
    int v1392 = (int)((unsigned int)((int)((unsigned int)v1046 >> 2)) >> 1);
    v1151[v1391] = v1392;
    int * v1153 = v1044->cache_dirty;
    v1153[v1391] = 0;
    int * v1155 = v1044->cache_age;
    v1155[v1391] = 1;
    int * v1157 = v1044->cache_age;
    int v1158 = v1157[v1391];
    int * v1159 = v1044->cache_age;
    int v1160 = v1159[v1300];
    int * v1161 = v1044->cache_age;
    int v1400 = v1160 + ((int)((unsigned int)(v1160 - v1158) >> 31));
    v1161[v1300] = v1400;
    int * v1163 = v1044->cache_age;
    int v1164 = v1163[v1302];
    int * v1165 = v1044->cache_age;
    int v1403 = v1164 + ((int)((unsigned int)(v1164 - v1158) >> 31));
    v1165[v1302] = v1403;
    int * v1167 = v1044->cache_age;
    v1167[v1391] = 0;
    v1170 = v1391;
  }
  int v1406 = (v1170 * 2) + (((int)((unsigned int)v1046 >> 2)) & 1);
  int v1171 = v1057[v1406];
  int * v1172 = v1044->regs;
  v1172[11] = v1171;
  struct StateT2 * v1174 = slot_5(v901);
  return v1174;
}

struct StateT2 * slot_2(struct StateT2 * v89) {
  struct StateT * v90 = v89->a;
  int v91 = v90->timer;
  struct StateT * v92 = v89->b;
  int v93 = v92->timer;
  bool v112 = v91 == v93;
  squared_assert(v112);
  squared_assume(v112);
  struct StateT * v96 = v89->a;
  int v97 = v96->timer;
  int v114 = v97 + 1;
  v96->timer = v114;
  struct StateT * v99 = v89->b;
  int v100 = v99->timer;
  int v116 = v100 + 1;
  v99->timer = v116;
  struct StateT * v102 = v89->a;
  int * v103 = v102->regs;
  v103[7] = 0;
  struct StateT * v105 = v89->b;
  int * v106 = v105->regs;
  v106[7] = 0;
  struct StateT2 * v108 = slot_3(v89);
  return v108;
}

struct StateT2 * slot_3(struct StateT2 * v125) {
  struct StateT * v126 = v125->a;
  int v127 = v126->timer;
  struct StateT * v128 = v125->b;
  int v129 = v128->timer;
  bool v546 = v127 == v129;
  squared_assert(v546);
  squared_assume(v546);
  struct StateT * v132 = v125->a;
  int v133 = v132->timer;
  int v548 = v133 + 1;
  v132->timer = v548;
  struct StateT * v135 = v125->b;
  int v136 = v135->timer;
  int v550 = v136 + 1;
  v135->timer = v550;
  struct StateT * v138 = v125->a;
  int * v139 = v138->regs;
  int v140 = v139[6];
  int * v141 = v138->regs;
  int v142 = v141[7];
  int * v143 = v138->cache_tags;
  int v557 = (((int)((unsigned int)((int)((unsigned int)v140 >> 2)) >> 1)) & 1) * 2;
  int v144 = v143[v557];
  int * v145 = v138->cache_tags;
  int v559 = ((((int)((unsigned int)((int)((unsigned int)v140 >> 2)) >> 1)) & 1) * 2) + 1;
  int v146 = v145[v559];
  int * v147 = v138->cache_tags;
  int v561 = 4 + ((((int)((unsigned int)((int)((unsigned int)v140 >> 2)) >> 1)) & 3) * 2);
  int v148 = v147[v561];
  int * v149 = v138->cache_tags;
  int v563 = (4 + ((((int)((unsigned int)((int)((unsigned int)v140 >> 2)) >> 1)) & 3) * 2)) + 1;
  int v150 = v149[v563];
  int v151 = v138->timer;
  int v564 = v151 + ((100 ^ (((~(((v148 ^ ((int)((unsigned int)((int)((unsigned int)v140 >> 2)) >> 1))) | (-(v148 ^ ((int)((unsigned int)((int)((unsigned int)v140 >> 2)) >> 1))))) >> 31)) | (~(((v150 ^ ((int)((unsigned int)((int)((unsigned int)v140 >> 2)) >> 1))) | (-(v150 ^ ((int)((unsigned int)((int)((unsigned int)v140 >> 2)) >> 1))))) >> 31))) & 104)) ^ (((~(((v144 ^ ((int)((unsigned int)((int)((unsigned int)v140 >> 2)) >> 1))) | (-(v144 ^ ((int)((unsigned int)((int)((unsigned int)v140 >> 2)) >> 1))))) >> 31)) | (~(((v146 ^ ((int)((unsigned int)((int)((unsigned int)v140 >> 2)) >> 1))) | (-(v146 ^ ((int)((unsigned int)((int)((unsigned int)v140 >> 2)) >> 1))))) >> 31))) & (1 ^ (100 ^ (((~(((v148 ^ ((int)((unsigned int)((int)((unsigned int)v140 >> 2)) >> 1))) | (-(v148 ^ ((int)((unsigned int)((int)((unsigned int)v140 >> 2)) >> 1))))) >> 31)) | (~(((v150 ^ ((int)((unsigned int)((int)((unsigned int)v140 >> 2)) >> 1))) | (-(v150 ^ ((int)((unsigned int)((int)((unsigned int)v140 >> 2)) >> 1))))) >> 31))) & 104)))));
  v138->timer = v564;
  bool v565 = !(((~(((v144 ^ ((int)((unsigned int)((int)((unsigned int)v140 >> 2)) >> 1))) | (-(v144 ^ ((int)((unsigned int)((int)((unsigned int)v140 >> 2)) >> 1))))) >> 31)) | (~(((v146 ^ ((int)((unsigned int)((int)((unsigned int)v140 >> 2)) >> 1))) | (-(v146 ^ ((int)((unsigned int)((int)((unsigned int)v140 >> 2)) >> 1))))) >> 31))) == 0);
  int v265;
  if (v565) {
    int * v153 = v138->cache_age;
    int v567 = ((((int)((unsigned int)((int)((unsigned int)v140 >> 2)) >> 1)) & 1) * 2) + ((~(((v146 ^ ((int)((unsigned int)((int)((unsigned int)v140 >> 2)) >> 1))) | (-(v146 ^ ((int)((unsigned int)((int)((unsigned int)v140 >> 2)) >> 1))))) >> 31)) & 1);
    int v154 = v153[v567];
    int * v155 = v138->cache_age;
    int v156 = v155[v557];
    int * v157 = v138->cache_age;
    int v570 = v156 + ((int)((unsigned int)(v156 - v154) >> 31));
    v157[v557] = v570;
    int * v159 = v138->cache_age;
    int v160 = v159[v559];
    int * v161 = v138->cache_age;
    int v573 = v160 + ((int)((unsigned int)(v160 - v154) >> 31));
    v161[v559] = v573;
    int * v163 = v138->cache_age;
    v163[v567] = 0;
    v265 = v567;
  } else {
    int * v166 = v138->cache_age;
    int v577 = (((int)((unsigned int)((int)((unsigned int)v140 >> 2)) >> 1)) & 1) * 2;
    int v167 = v166[v577];
    int * v168 = v138->cache_tags;
    int v169 = v168[v577];
    int * v170 = v138->cache_age;
    int v171 = v170[v559];
    int * v172 = v138->cache_tags;
    int v173 = v172[v559];
    bool v581 = !(((~(((v148 ^ ((int)((unsigned int)((int)((unsigned int)v140 >> 2)) >> 1))) | (-(v148 ^ ((int)((unsigned int)((int)((unsigned int)v140 >> 2)) >> 1))))) >> 31)) | (~(((v150 ^ ((int)((unsigned int)((int)((unsigned int)v140 >> 2)) >> 1))) | (-(v150 ^ ((int)((unsigned int)((int)((unsigned int)v140 >> 2)) >> 1))))) >> 31))) == 0);
    int v237;
    if (v581) {
      int * v174 = v138->cache_age;
      int v583 = (4 + ((((int)((unsigned int)((int)((unsigned int)v140 >> 2)) >> 1)) & 3) * 2)) + ((~(((v150 ^ ((int)((unsigned int)((int)((unsigned int)v140 >> 2)) >> 1))) | (-(v150 ^ ((int)((unsigned int)((int)((unsigned int)v140 >> 2)) >> 1))))) >> 31)) & 1);
      int v175 = v174[v583];
      int * v176 = v138->cache_age;
      int v177 = v176[v561];
      int * v178 = v138->cache_age;
      int v586 = v177 + ((int)((unsigned int)(v177 - v175) >> 31));
      v178[v561] = v586;
      int * v180 = v138->cache_age;
      int v181 = v180[v563];
      int * v182 = v138->cache_age;
      int v589 = v181 + ((int)((unsigned int)(v181 - v175) >> 31));
      v182[v563] = v589;
      int * v184 = v138->cache_age;
      v184[v583] = 0;
      v237 = v583;
    } else {
      int * v187 = v138->cache_age;
      int v593 = 4 + ((((int)((unsigned int)((int)((unsigned int)v140 >> 2)) >> 1)) & 3) * 2);
      int v188 = v187[v593];
      int * v189 = v138->cache_tags;
      int v190 = v189[v593];
      int * v191 = v138->cache_age;
      int v192 = v191[v563];
      int * v193 = v138->cache_tags;
      int v194 = v193[v563];
      int * v195 = v138->cache_dirty;
      int v598 = (4 + ((((int)((unsigned int)((int)((unsigned int)v140 >> 2)) >> 1)) & 3) * 2)) + ((((v188 + ((~(((v190 ^ -1) | (-(v190 ^ -1))) >> 31)) & 2)) - (v192 + ((~(((v194 ^ -1) | (-(v194 ^ -1))) >> 31)) & 2))) >> 31) & 1);
      int v196 = v195[v598];
      bool v599 = !(v196 == 0);
      if (v599) {
        int * v197 = v138->cache_tags;
        int v198 = v197[v598];
        int * v199 = v138->cache_vals;
        int v602 = ((4 + ((((int)((unsigned int)((int)((unsigned int)v140 >> 2)) >> 1)) & 3) * 2)) + ((((v188 + ((~(((v190 ^ -1) | (-(v190 ^ -1))) >> 31)) & 2)) - (v192 + ((~(((v194 ^ -1) | (-(v194 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
        int v200 = v199[v602];
        int * v201 = v138->cache_vals;
        int v604 = (((4 + ((((int)((unsigned int)((int)((unsigned int)v140 >> 2)) >> 1)) & 3) * 2)) + ((((v188 + ((~(((v190 ^ -1) | (-(v190 ^ -1))) >> 31)) & 2)) - (v192 + ((~(((v194 ^ -1) | (-(v194 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
        int v202 = v201[v604];
        int * v203 = v138->mem;
        int v606 = v198 * 2;
        v203[v606] = v200;
        int * v205 = v138->mem;
        int v609 = (v198 * 2) + 1;
        v205[v609] = v202;
        ;
      } else {
        ;
      }
      int * v210 = v138->mem;
      int v614 = ((int)((unsigned int)((int)((unsigned int)v140 >> 2)) >> 1)) * 2;
      int v211 = v210[v614];
      int * v212 = v138->mem;
      int v616 = (((int)((unsigned int)((int)((unsigned int)v140 >> 2)) >> 1)) * 2) + 1;
      int v213 = v212[v616];
      int * v214 = v138->cache_vals;
      int v618 = ((4 + ((((int)((unsigned int)((int)((unsigned int)v140 >> 2)) >> 1)) & 3) * 2)) + ((((v188 + ((~(((v190 ^ -1) | (-(v190 ^ -1))) >> 31)) & 2)) - (v192 + ((~(((v194 ^ -1) | (-(v194 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
      v214[v618] = v211;
      int * v216 = v138->cache_vals;
      int v621 = (((4 + ((((int)((unsigned int)((int)((unsigned int)v140 >> 2)) >> 1)) & 3) * 2)) + ((((v188 + ((~(((v190 ^ -1) | (-(v190 ^ -1))) >> 31)) & 2)) - (v192 + ((~(((v194 ^ -1) | (-(v194 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
      v216[v621] = v213;
      int * v218 = v138->cache_tags;
      int v624 = (int)((unsigned int)((int)((unsigned int)v140 >> 2)) >> 1);
      v218[v598] = v624;
      int * v220 = v138->cache_dirty;
      v220[v598] = 0;
      int * v222 = v138->cache_age;
      v222[v598] = 1;
      int * v224 = v138->cache_age;
      int v225 = v224[v598];
      int * v226 = v138->cache_age;
      int v227 = v226[v561];
      int * v228 = v138->cache_age;
      int v632 = v227 + ((int)((unsigned int)(v227 - v225) >> 31));
      v228[v561] = v632;
      int * v230 = v138->cache_age;
      int v231 = v230[v563];
      int * v232 = v138->cache_age;
      int v635 = v231 + ((int)((unsigned int)(v231 - v225) >> 31));
      v232[v563] = v635;
      int * v234 = v138->cache_age;
      v234[v598] = 0;
      v237 = v598;
    }
    int * v238 = v138->cache_vals;
    int v638 = v237 * 2;
    int v239 = v238[v638];
    int * v240 = v138->cache_vals;
    int v640 = (v237 * 2) + 1;
    int v241 = v240[v640];
    int * v242 = v138->cache_vals;
    int v642 = (((((int)((unsigned int)((int)((unsigned int)v140 >> 2)) >> 1)) & 1) * 2) + ((((v167 + ((~(((v169 ^ -1) | (-(v169 ^ -1))) >> 31)) & 2)) - (v171 + ((~(((v173 ^ -1) | (-(v173 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
    v242[v642] = v239;
    int * v244 = v138->cache_vals;
    int v645 = ((((((int)((unsigned int)((int)((unsigned int)v140 >> 2)) >> 1)) & 1) * 2) + ((((v167 + ((~(((v169 ^ -1) | (-(v169 ^ -1))) >> 31)) & 2)) - (v171 + ((~(((v173 ^ -1) | (-(v173 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
    v244[v645] = v241;
    int * v246 = v138->cache_tags;
    int v648 = ((((int)((unsigned int)((int)((unsigned int)v140 >> 2)) >> 1)) & 1) * 2) + ((((v167 + ((~(((v169 ^ -1) | (-(v169 ^ -1))) >> 31)) & 2)) - (v171 + ((~(((v173 ^ -1) | (-(v173 ^ -1))) >> 31)) & 2))) >> 31) & 1);
    int v649 = (int)((unsigned int)((int)((unsigned int)v140 >> 2)) >> 1);
    v246[v648] = v649;
    int * v248 = v138->cache_dirty;
    v248[v648] = 0;
    int * v250 = v138->cache_age;
    v250[v648] = 1;
    int * v252 = v138->cache_age;
    int v253 = v252[v648];
    int * v254 = v138->cache_age;
    int v255 = v254[v557];
    int * v256 = v138->cache_age;
    int v657 = v255 + ((int)((unsigned int)(v255 - v253) >> 31));
    v256[v557] = v657;
    int * v258 = v138->cache_age;
    int v259 = v258[v559];
    int * v260 = v138->cache_age;
    int v660 = v259 + ((int)((unsigned int)(v259 - v253) >> 31));
    v260[v559] = v660;
    int * v262 = v138->cache_age;
    v262[v648] = 0;
    v265 = v648;
  }
  int * v266 = v138->cache_vals;
  int v663 = (v265 * 2) + (((int)((unsigned int)v140 >> 2)) & 1);
  v266[v663] = v142;
  int * v268 = v138->cache_tags;
  int v269 = v268[v561];
  int * v270 = v138->cache_tags;
  int v271 = v270[v563];
  bool v667 = !(((~(((v269 ^ ((int)((unsigned int)((int)((unsigned int)v140 >> 2)) >> 1))) | (-(v269 ^ ((int)((unsigned int)((int)((unsigned int)v140 >> 2)) >> 1))))) >> 31)) | (~(((v271 ^ ((int)((unsigned int)((int)((unsigned int)v140 >> 2)) >> 1))) | (-(v271 ^ ((int)((unsigned int)((int)((unsigned int)v140 >> 2)) >> 1))))) >> 31))) == 0);
  int v335;
  if (v667) {
    int * v272 = v138->cache_age;
    int v669 = (4 + ((((int)((unsigned int)((int)((unsigned int)v140 >> 2)) >> 1)) & 3) * 2)) + ((~(((v271 ^ ((int)((unsigned int)((int)((unsigned int)v140 >> 2)) >> 1))) | (-(v271 ^ ((int)((unsigned int)((int)((unsigned int)v140 >> 2)) >> 1))))) >> 31)) & 1);
    int v273 = v272[v669];
    int * v274 = v138->cache_age;
    int v275 = v274[v561];
    int * v276 = v138->cache_age;
    int v672 = v275 + ((int)((unsigned int)(v275 - v273) >> 31));
    v276[v561] = v672;
    int * v278 = v138->cache_age;
    int v279 = v278[v563];
    int * v280 = v138->cache_age;
    int v675 = v279 + ((int)((unsigned int)(v279 - v273) >> 31));
    v280[v563] = v675;
    int * v282 = v138->cache_age;
    v282[v669] = 0;
    v335 = v669;
  } else {
    int * v285 = v138->cache_age;
    int v679 = 4 + ((((int)((unsigned int)((int)((unsigned int)v140 >> 2)) >> 1)) & 3) * 2);
    int v286 = v285[v679];
    int * v287 = v138->cache_tags;
    int v288 = v287[v679];
    int * v289 = v138->cache_age;
    int v290 = v289[v563];
    int * v291 = v138->cache_tags;
    int v292 = v291[v563];
    int * v293 = v138->cache_dirty;
    int v684 = (4 + ((((int)((unsigned int)((int)((unsigned int)v140 >> 2)) >> 1)) & 3) * 2)) + ((((v286 + ((~(((v288 ^ -1) | (-(v288 ^ -1))) >> 31)) & 2)) - (v290 + ((~(((v292 ^ -1) | (-(v292 ^ -1))) >> 31)) & 2))) >> 31) & 1);
    int v294 = v293[v684];
    bool v685 = !(v294 == 0);
    if (v685) {
      int * v295 = v138->cache_tags;
      int v296 = v295[v684];
      int * v297 = v138->cache_vals;
      int v688 = ((4 + ((((int)((unsigned int)((int)((unsigned int)v140 >> 2)) >> 1)) & 3) * 2)) + ((((v286 + ((~(((v288 ^ -1) | (-(v288 ^ -1))) >> 31)) & 2)) - (v290 + ((~(((v292 ^ -1) | (-(v292 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
      int v298 = v297[v688];
      int * v299 = v138->cache_vals;
      int v690 = (((4 + ((((int)((unsigned int)((int)((unsigned int)v140 >> 2)) >> 1)) & 3) * 2)) + ((((v286 + ((~(((v288 ^ -1) | (-(v288 ^ -1))) >> 31)) & 2)) - (v290 + ((~(((v292 ^ -1) | (-(v292 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
      int v300 = v299[v690];
      int * v301 = v138->mem;
      int v692 = v296 * 2;
      v301[v692] = v298;
      int * v303 = v138->mem;
      int v695 = (v296 * 2) + 1;
      v303[v695] = v300;
      ;
    } else {
      ;
    }
    int * v308 = v138->mem;
    int v700 = ((int)((unsigned int)((int)((unsigned int)v140 >> 2)) >> 1)) * 2;
    int v309 = v308[v700];
    int * v310 = v138->mem;
    int v702 = (((int)((unsigned int)((int)((unsigned int)v140 >> 2)) >> 1)) * 2) + 1;
    int v311 = v310[v702];
    int * v312 = v138->cache_vals;
    int v704 = ((4 + ((((int)((unsigned int)((int)((unsigned int)v140 >> 2)) >> 1)) & 3) * 2)) + ((((v286 + ((~(((v288 ^ -1) | (-(v288 ^ -1))) >> 31)) & 2)) - (v290 + ((~(((v292 ^ -1) | (-(v292 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
    v312[v704] = v309;
    int * v314 = v138->cache_vals;
    int v707 = (((4 + ((((int)((unsigned int)((int)((unsigned int)v140 >> 2)) >> 1)) & 3) * 2)) + ((((v286 + ((~(((v288 ^ -1) | (-(v288 ^ -1))) >> 31)) & 2)) - (v290 + ((~(((v292 ^ -1) | (-(v292 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
    v314[v707] = v311;
    int * v316 = v138->cache_tags;
    int v710 = (int)((unsigned int)((int)((unsigned int)v140 >> 2)) >> 1);
    v316[v684] = v710;
    int * v318 = v138->cache_dirty;
    v318[v684] = 0;
    int * v320 = v138->cache_age;
    v320[v684] = 1;
    int * v322 = v138->cache_age;
    int v323 = v322[v684];
    int * v324 = v138->cache_age;
    int v325 = v324[v561];
    int * v326 = v138->cache_age;
    int v718 = v325 + ((int)((unsigned int)(v325 - v323) >> 31));
    v326[v561] = v718;
    int * v328 = v138->cache_age;
    int v329 = v328[v563];
    int * v330 = v138->cache_age;
    int v721 = v329 + ((int)((unsigned int)(v329 - v323) >> 31));
    v330[v563] = v721;
    int * v332 = v138->cache_age;
    v332[v684] = 0;
    v335 = v684;
  }
  int * v336 = v138->cache_vals;
  int v724 = (v335 * 2) + (((int)((unsigned int)v140 >> 2)) & 1);
  v336[v724] = v142;
  int * v338 = v138->cache_dirty;
  v338[v335] = 1;
  struct StateT * v340 = v125->b;
  int * v341 = v340->regs;
  int v342 = v341[6];
  int * v343 = v340->regs;
  int v344 = v343[7];
  int * v345 = v340->cache_tags;
  int v732 = (((int)((unsigned int)((int)((unsigned int)v342 >> 2)) >> 1)) & 1) * 2;
  int v346 = v345[v732];
  int * v347 = v340->cache_tags;
  int v734 = ((((int)((unsigned int)((int)((unsigned int)v342 >> 2)) >> 1)) & 1) * 2) + 1;
  int v348 = v347[v734];
  int * v349 = v340->cache_tags;
  int v736 = 4 + ((((int)((unsigned int)((int)((unsigned int)v342 >> 2)) >> 1)) & 3) * 2);
  int v350 = v349[v736];
  int * v351 = v340->cache_tags;
  int v738 = (4 + ((((int)((unsigned int)((int)((unsigned int)v342 >> 2)) >> 1)) & 3) * 2)) + 1;
  int v352 = v351[v738];
  int v353 = v340->timer;
  int v739 = v353 + ((100 ^ (((~(((v350 ^ ((int)((unsigned int)((int)((unsigned int)v342 >> 2)) >> 1))) | (-(v350 ^ ((int)((unsigned int)((int)((unsigned int)v342 >> 2)) >> 1))))) >> 31)) | (~(((v352 ^ ((int)((unsigned int)((int)((unsigned int)v342 >> 2)) >> 1))) | (-(v352 ^ ((int)((unsigned int)((int)((unsigned int)v342 >> 2)) >> 1))))) >> 31))) & 104)) ^ (((~(((v346 ^ ((int)((unsigned int)((int)((unsigned int)v342 >> 2)) >> 1))) | (-(v346 ^ ((int)((unsigned int)((int)((unsigned int)v342 >> 2)) >> 1))))) >> 31)) | (~(((v348 ^ ((int)((unsigned int)((int)((unsigned int)v342 >> 2)) >> 1))) | (-(v348 ^ ((int)((unsigned int)((int)((unsigned int)v342 >> 2)) >> 1))))) >> 31))) & (1 ^ (100 ^ (((~(((v350 ^ ((int)((unsigned int)((int)((unsigned int)v342 >> 2)) >> 1))) | (-(v350 ^ ((int)((unsigned int)((int)((unsigned int)v342 >> 2)) >> 1))))) >> 31)) | (~(((v352 ^ ((int)((unsigned int)((int)((unsigned int)v342 >> 2)) >> 1))) | (-(v352 ^ ((int)((unsigned int)((int)((unsigned int)v342 >> 2)) >> 1))))) >> 31))) & 104)))));
  v340->timer = v739;
  bool v740 = !(((~(((v346 ^ ((int)((unsigned int)((int)((unsigned int)v342 >> 2)) >> 1))) | (-(v346 ^ ((int)((unsigned int)((int)((unsigned int)v342 >> 2)) >> 1))))) >> 31)) | (~(((v348 ^ ((int)((unsigned int)((int)((unsigned int)v342 >> 2)) >> 1))) | (-(v348 ^ ((int)((unsigned int)((int)((unsigned int)v342 >> 2)) >> 1))))) >> 31))) == 0);
  int v467;
  if (v740) {
    int * v355 = v340->cache_age;
    int v742 = ((((int)((unsigned int)((int)((unsigned int)v342 >> 2)) >> 1)) & 1) * 2) + ((~(((v348 ^ ((int)((unsigned int)((int)((unsigned int)v342 >> 2)) >> 1))) | (-(v348 ^ ((int)((unsigned int)((int)((unsigned int)v342 >> 2)) >> 1))))) >> 31)) & 1);
    int v356 = v355[v742];
    int * v357 = v340->cache_age;
    int v358 = v357[v732];
    int * v359 = v340->cache_age;
    int v745 = v358 + ((int)((unsigned int)(v358 - v356) >> 31));
    v359[v732] = v745;
    int * v361 = v340->cache_age;
    int v362 = v361[v734];
    int * v363 = v340->cache_age;
    int v748 = v362 + ((int)((unsigned int)(v362 - v356) >> 31));
    v363[v734] = v748;
    int * v365 = v340->cache_age;
    v365[v742] = 0;
    v467 = v742;
  } else {
    int * v368 = v340->cache_age;
    int v752 = (((int)((unsigned int)((int)((unsigned int)v342 >> 2)) >> 1)) & 1) * 2;
    int v369 = v368[v752];
    int * v370 = v340->cache_tags;
    int v371 = v370[v752];
    int * v372 = v340->cache_age;
    int v373 = v372[v734];
    int * v374 = v340->cache_tags;
    int v375 = v374[v734];
    bool v756 = !(((~(((v350 ^ ((int)((unsigned int)((int)((unsigned int)v342 >> 2)) >> 1))) | (-(v350 ^ ((int)((unsigned int)((int)((unsigned int)v342 >> 2)) >> 1))))) >> 31)) | (~(((v352 ^ ((int)((unsigned int)((int)((unsigned int)v342 >> 2)) >> 1))) | (-(v352 ^ ((int)((unsigned int)((int)((unsigned int)v342 >> 2)) >> 1))))) >> 31))) == 0);
    int v439;
    if (v756) {
      int * v376 = v340->cache_age;
      int v758 = (4 + ((((int)((unsigned int)((int)((unsigned int)v342 >> 2)) >> 1)) & 3) * 2)) + ((~(((v352 ^ ((int)((unsigned int)((int)((unsigned int)v342 >> 2)) >> 1))) | (-(v352 ^ ((int)((unsigned int)((int)((unsigned int)v342 >> 2)) >> 1))))) >> 31)) & 1);
      int v377 = v376[v758];
      int * v378 = v340->cache_age;
      int v379 = v378[v736];
      int * v380 = v340->cache_age;
      int v761 = v379 + ((int)((unsigned int)(v379 - v377) >> 31));
      v380[v736] = v761;
      int * v382 = v340->cache_age;
      int v383 = v382[v738];
      int * v384 = v340->cache_age;
      int v764 = v383 + ((int)((unsigned int)(v383 - v377) >> 31));
      v384[v738] = v764;
      int * v386 = v340->cache_age;
      v386[v758] = 0;
      v439 = v758;
    } else {
      int * v389 = v340->cache_age;
      int v768 = 4 + ((((int)((unsigned int)((int)((unsigned int)v342 >> 2)) >> 1)) & 3) * 2);
      int v390 = v389[v768];
      int * v391 = v340->cache_tags;
      int v392 = v391[v768];
      int * v393 = v340->cache_age;
      int v394 = v393[v738];
      int * v395 = v340->cache_tags;
      int v396 = v395[v738];
      int * v397 = v340->cache_dirty;
      int v773 = (4 + ((((int)((unsigned int)((int)((unsigned int)v342 >> 2)) >> 1)) & 3) * 2)) + ((((v390 + ((~(((v392 ^ -1) | (-(v392 ^ -1))) >> 31)) & 2)) - (v394 + ((~(((v396 ^ -1) | (-(v396 ^ -1))) >> 31)) & 2))) >> 31) & 1);
      int v398 = v397[v773];
      bool v774 = !(v398 == 0);
      if (v774) {
        int * v399 = v340->cache_tags;
        int v400 = v399[v773];
        int * v401 = v340->cache_vals;
        int v777 = ((4 + ((((int)((unsigned int)((int)((unsigned int)v342 >> 2)) >> 1)) & 3) * 2)) + ((((v390 + ((~(((v392 ^ -1) | (-(v392 ^ -1))) >> 31)) & 2)) - (v394 + ((~(((v396 ^ -1) | (-(v396 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
        int v402 = v401[v777];
        int * v403 = v340->cache_vals;
        int v779 = (((4 + ((((int)((unsigned int)((int)((unsigned int)v342 >> 2)) >> 1)) & 3) * 2)) + ((((v390 + ((~(((v392 ^ -1) | (-(v392 ^ -1))) >> 31)) & 2)) - (v394 + ((~(((v396 ^ -1) | (-(v396 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
        int v404 = v403[v779];
        int * v405 = v340->mem;
        int v781 = v400 * 2;
        v405[v781] = v402;
        int * v407 = v340->mem;
        int v784 = (v400 * 2) + 1;
        v407[v784] = v404;
        ;
      } else {
        ;
      }
      int * v412 = v340->mem;
      int v789 = ((int)((unsigned int)((int)((unsigned int)v342 >> 2)) >> 1)) * 2;
      int v413 = v412[v789];
      int * v414 = v340->mem;
      int v791 = (((int)((unsigned int)((int)((unsigned int)v342 >> 2)) >> 1)) * 2) + 1;
      int v415 = v414[v791];
      int * v416 = v340->cache_vals;
      int v793 = ((4 + ((((int)((unsigned int)((int)((unsigned int)v342 >> 2)) >> 1)) & 3) * 2)) + ((((v390 + ((~(((v392 ^ -1) | (-(v392 ^ -1))) >> 31)) & 2)) - (v394 + ((~(((v396 ^ -1) | (-(v396 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
      v416[v793] = v413;
      int * v418 = v340->cache_vals;
      int v796 = (((4 + ((((int)((unsigned int)((int)((unsigned int)v342 >> 2)) >> 1)) & 3) * 2)) + ((((v390 + ((~(((v392 ^ -1) | (-(v392 ^ -1))) >> 31)) & 2)) - (v394 + ((~(((v396 ^ -1) | (-(v396 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
      v418[v796] = v415;
      int * v420 = v340->cache_tags;
      int v799 = (int)((unsigned int)((int)((unsigned int)v342 >> 2)) >> 1);
      v420[v773] = v799;
      int * v422 = v340->cache_dirty;
      v422[v773] = 0;
      int * v424 = v340->cache_age;
      v424[v773] = 1;
      int * v426 = v340->cache_age;
      int v427 = v426[v773];
      int * v428 = v340->cache_age;
      int v429 = v428[v736];
      int * v430 = v340->cache_age;
      int v806 = v429 + ((int)((unsigned int)(v429 - v427) >> 31));
      v430[v736] = v806;
      int * v432 = v340->cache_age;
      int v433 = v432[v738];
      int * v434 = v340->cache_age;
      int v809 = v433 + ((int)((unsigned int)(v433 - v427) >> 31));
      v434[v738] = v809;
      int * v436 = v340->cache_age;
      v436[v773] = 0;
      v439 = v773;
    }
    int * v440 = v340->cache_vals;
    int v812 = v439 * 2;
    int v441 = v440[v812];
    int * v442 = v340->cache_vals;
    int v814 = (v439 * 2) + 1;
    int v443 = v442[v814];
    int * v444 = v340->cache_vals;
    int v816 = (((((int)((unsigned int)((int)((unsigned int)v342 >> 2)) >> 1)) & 1) * 2) + ((((v369 + ((~(((v371 ^ -1) | (-(v371 ^ -1))) >> 31)) & 2)) - (v373 + ((~(((v375 ^ -1) | (-(v375 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
    v444[v816] = v441;
    int * v446 = v340->cache_vals;
    int v819 = ((((((int)((unsigned int)((int)((unsigned int)v342 >> 2)) >> 1)) & 1) * 2) + ((((v369 + ((~(((v371 ^ -1) | (-(v371 ^ -1))) >> 31)) & 2)) - (v373 + ((~(((v375 ^ -1) | (-(v375 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
    v446[v819] = v443;
    int * v448 = v340->cache_tags;
    int v822 = ((((int)((unsigned int)((int)((unsigned int)v342 >> 2)) >> 1)) & 1) * 2) + ((((v369 + ((~(((v371 ^ -1) | (-(v371 ^ -1))) >> 31)) & 2)) - (v373 + ((~(((v375 ^ -1) | (-(v375 ^ -1))) >> 31)) & 2))) >> 31) & 1);
    int v823 = (int)((unsigned int)((int)((unsigned int)v342 >> 2)) >> 1);
    v448[v822] = v823;
    int * v450 = v340->cache_dirty;
    v450[v822] = 0;
    int * v452 = v340->cache_age;
    v452[v822] = 1;
    int * v454 = v340->cache_age;
    int v455 = v454[v822];
    int * v456 = v340->cache_age;
    int v457 = v456[v732];
    int * v458 = v340->cache_age;
    int v830 = v457 + ((int)((unsigned int)(v457 - v455) >> 31));
    v458[v732] = v830;
    int * v460 = v340->cache_age;
    int v461 = v460[v734];
    int * v462 = v340->cache_age;
    int v833 = v461 + ((int)((unsigned int)(v461 - v455) >> 31));
    v462[v734] = v833;
    int * v464 = v340->cache_age;
    v464[v822] = 0;
    v467 = v822;
  }
  int * v468 = v340->cache_vals;
  int v836 = (v467 * 2) + (((int)((unsigned int)v342 >> 2)) & 1);
  v468[v836] = v344;
  int * v470 = v340->cache_tags;
  int v471 = v470[v736];
  int * v472 = v340->cache_tags;
  int v473 = v472[v738];
  bool v840 = !(((~(((v471 ^ ((int)((unsigned int)((int)((unsigned int)v342 >> 2)) >> 1))) | (-(v471 ^ ((int)((unsigned int)((int)((unsigned int)v342 >> 2)) >> 1))))) >> 31)) | (~(((v473 ^ ((int)((unsigned int)((int)((unsigned int)v342 >> 2)) >> 1))) | (-(v473 ^ ((int)((unsigned int)((int)((unsigned int)v342 >> 2)) >> 1))))) >> 31))) == 0);
  int v537;
  if (v840) {
    int * v474 = v340->cache_age;
    int v842 = (4 + ((((int)((unsigned int)((int)((unsigned int)v342 >> 2)) >> 1)) & 3) * 2)) + ((~(((v473 ^ ((int)((unsigned int)((int)((unsigned int)v342 >> 2)) >> 1))) | (-(v473 ^ ((int)((unsigned int)((int)((unsigned int)v342 >> 2)) >> 1))))) >> 31)) & 1);
    int v475 = v474[v842];
    int * v476 = v340->cache_age;
    int v477 = v476[v736];
    int * v478 = v340->cache_age;
    int v845 = v477 + ((int)((unsigned int)(v477 - v475) >> 31));
    v478[v736] = v845;
    int * v480 = v340->cache_age;
    int v481 = v480[v738];
    int * v482 = v340->cache_age;
    int v848 = v481 + ((int)((unsigned int)(v481 - v475) >> 31));
    v482[v738] = v848;
    int * v484 = v340->cache_age;
    v484[v842] = 0;
    v537 = v842;
  } else {
    int * v487 = v340->cache_age;
    int v852 = 4 + ((((int)((unsigned int)((int)((unsigned int)v342 >> 2)) >> 1)) & 3) * 2);
    int v488 = v487[v852];
    int * v489 = v340->cache_tags;
    int v490 = v489[v852];
    int * v491 = v340->cache_age;
    int v492 = v491[v738];
    int * v493 = v340->cache_tags;
    int v494 = v493[v738];
    int * v495 = v340->cache_dirty;
    int v857 = (4 + ((((int)((unsigned int)((int)((unsigned int)v342 >> 2)) >> 1)) & 3) * 2)) + ((((v488 + ((~(((v490 ^ -1) | (-(v490 ^ -1))) >> 31)) & 2)) - (v492 + ((~(((v494 ^ -1) | (-(v494 ^ -1))) >> 31)) & 2))) >> 31) & 1);
    int v496 = v495[v857];
    bool v858 = !(v496 == 0);
    if (v858) {
      int * v497 = v340->cache_tags;
      int v498 = v497[v857];
      int * v499 = v340->cache_vals;
      int v861 = ((4 + ((((int)((unsigned int)((int)((unsigned int)v342 >> 2)) >> 1)) & 3) * 2)) + ((((v488 + ((~(((v490 ^ -1) | (-(v490 ^ -1))) >> 31)) & 2)) - (v492 + ((~(((v494 ^ -1) | (-(v494 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
      int v500 = v499[v861];
      int * v501 = v340->cache_vals;
      int v863 = (((4 + ((((int)((unsigned int)((int)((unsigned int)v342 >> 2)) >> 1)) & 3) * 2)) + ((((v488 + ((~(((v490 ^ -1) | (-(v490 ^ -1))) >> 31)) & 2)) - (v492 + ((~(((v494 ^ -1) | (-(v494 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
      int v502 = v501[v863];
      int * v503 = v340->mem;
      int v865 = v498 * 2;
      v503[v865] = v500;
      int * v505 = v340->mem;
      int v868 = (v498 * 2) + 1;
      v505[v868] = v502;
      ;
    } else {
      ;
    }
    int * v510 = v340->mem;
    int v873 = ((int)((unsigned int)((int)((unsigned int)v342 >> 2)) >> 1)) * 2;
    int v511 = v510[v873];
    int * v512 = v340->mem;
    int v875 = (((int)((unsigned int)((int)((unsigned int)v342 >> 2)) >> 1)) * 2) + 1;
    int v513 = v512[v875];
    int * v514 = v340->cache_vals;
    int v877 = ((4 + ((((int)((unsigned int)((int)((unsigned int)v342 >> 2)) >> 1)) & 3) * 2)) + ((((v488 + ((~(((v490 ^ -1) | (-(v490 ^ -1))) >> 31)) & 2)) - (v492 + ((~(((v494 ^ -1) | (-(v494 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
    v514[v877] = v511;
    int * v516 = v340->cache_vals;
    int v880 = (((4 + ((((int)((unsigned int)((int)((unsigned int)v342 >> 2)) >> 1)) & 3) * 2)) + ((((v488 + ((~(((v490 ^ -1) | (-(v490 ^ -1))) >> 31)) & 2)) - (v492 + ((~(((v494 ^ -1) | (-(v494 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
    v516[v880] = v513;
    int * v518 = v340->cache_tags;
    int v883 = (int)((unsigned int)((int)((unsigned int)v342 >> 2)) >> 1);
    v518[v857] = v883;
    int * v520 = v340->cache_dirty;
    v520[v857] = 0;
    int * v522 = v340->cache_age;
    v522[v857] = 1;
    int * v524 = v340->cache_age;
    int v525 = v524[v857];
    int * v526 = v340->cache_age;
    int v527 = v526[v736];
    int * v528 = v340->cache_age;
    int v890 = v527 + ((int)((unsigned int)(v527 - v525) >> 31));
    v528[v736] = v890;
    int * v530 = v340->cache_age;
    int v531 = v530[v738];
    int * v532 = v340->cache_age;
    int v893 = v531 + ((int)((unsigned int)(v531 - v525) >> 31));
    v532[v738] = v893;
    int * v534 = v340->cache_age;
    v534[v857] = 0;
    v537 = v857;
  }
  int * v538 = v340->cache_vals;
  int v896 = (v537 * 2) + (((int)((unsigned int)v342 >> 2)) & 1);
  v538[v896] = v344;
  int * v540 = v340->cache_dirty;
  v540[v537] = 1;
  struct StateT2 * v542 = slot_4(v125);
  return v542;
}

struct StateT2 * slot_0(struct StateT2 * v2) {
  struct StateT * v3 = v2->a;
  int v4 = v3->timer;
  struct StateT * v5 = v2->b;
  int v6 = v5->timer;
  bool v29 = v4 == v6;
  squared_assert(v29);
  squared_assume(v29);
  struct StateT * v9 = v2->a;
  int v10 = v9->timer;
  int v31 = v10 + 1;
  v9->timer = v31;
  struct StateT * v12 = v2->b;
  int v13 = v12->timer;
  int v33 = v13 + 1;
  v12->timer = v33;
  struct StateT * v15 = v2->a;
  int * v16 = v15->regs;
  int v17 = v16[10];
  int * v18 = v15->regs;
  int v39 = v17 & 28;
  v18[6] = v39;
  struct StateT * v20 = v2->b;
  int * v21 = v20->regs;
  int v22 = v21[10];
  int * v23 = v20->regs;
  int v43 = v22 & 28;
  v23[6] = v43;
  struct StateT2 * v25 = slot_1(v2);
  return v25;
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

void squared_assert(bool c) { koika_assert(c, "timer drift"); }
void squared_diverged(bool c) { koika_assert(c, "control flow diverged"); }
void squared_assume(bool c) { koika_assume(c); }

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
  struct StateT2 p = { .a = &s1, .b = &s2 };
  struct StateT2 *p_ = snippet(&p);
  koika_assert(p_->a->timer==p_->b->timer, "timing leak");
  return 0;
}