// verify: leak likely-timeout (KLEE probably does not finish this path space) [budget 1200s]
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

struct StateT * snippet(struct StateT * v0);
struct StateT * slot_1(struct StateT * v17);
struct StateT * slot_6(struct StateT * v1638);
struct StateT * slot_5(struct StateT * v1434);
struct StateT * slot_4(struct StateT * v1244);
struct StateT * slot_2(struct StateT * v32);
struct StateT * slot_3(struct StateT * v329);
struct StateT * slot_0(struct StateT * v2);
struct StateT * snippet(struct StateT * v0) {
  struct StateT * v1 = slot_0(v0);
  return v1;
}

struct StateT * slot_1(struct StateT * v17) {
  int v18 = v17->timer;
  int v25 = v18 + 1;
  v17->timer = v25;
  int * v20 = v17->regs;
  int v21 = v20[5];
  int v29 = v21 + 80;
  v20[6] = v29;
  struct StateT * v23 = slot_2(v17);
  return v23;
}

struct StateT * slot_6(struct StateT * v1638) {
  int v1639 = v1638->timer;
  int v1748 = v1639 + 1;
  v1638->timer = v1748;
  int * v1641 = v1638->regs;
  int v1642 = v1641[11];
  int * v1643 = v1638->cache_tags;
  int v1752 = (((int)((unsigned int)((int)((unsigned int)v1642 >> 2)) >> 1)) & 1) * 2;
  int v1644 = v1643[v1752];
  int v1753 = ((((int)((unsigned int)((int)((unsigned int)v1642 >> 2)) >> 1)) & 1) * 2) + 1;
  int v1645 = v1643[v1753];
  int v1754 = 4 + ((((int)((unsigned int)((int)((unsigned int)v1642 >> 2)) >> 1)) & 3) * 2);
  int v1646 = v1643[v1754];
  int v1755 = (4 + ((((int)((unsigned int)((int)((unsigned int)v1642 >> 2)) >> 1)) & 3) * 2)) + 1;
  int v1647 = v1643[v1755];
  int v1648 = v1638->timer;
  int v1756 = v1648 + ((100 ^ (((~(((v1646 ^ ((int)((unsigned int)((int)((unsigned int)v1642 >> 2)) >> 1))) | (-(v1646 ^ ((int)((unsigned int)((int)((unsigned int)v1642 >> 2)) >> 1))))) >> 31)) | (~(((v1647 ^ ((int)((unsigned int)((int)((unsigned int)v1642 >> 2)) >> 1))) | (-(v1647 ^ ((int)((unsigned int)((int)((unsigned int)v1642 >> 2)) >> 1))))) >> 31))) & 104)) ^ (((~(((v1644 ^ ((int)((unsigned int)((int)((unsigned int)v1642 >> 2)) >> 1))) | (-(v1644 ^ ((int)((unsigned int)((int)((unsigned int)v1642 >> 2)) >> 1))))) >> 31)) | (~(((v1645 ^ ((int)((unsigned int)((int)((unsigned int)v1642 >> 2)) >> 1))) | (-(v1645 ^ ((int)((unsigned int)((int)((unsigned int)v1642 >> 2)) >> 1))))) >> 31))) & (1 ^ (100 ^ (((~(((v1646 ^ ((int)((unsigned int)((int)((unsigned int)v1642 >> 2)) >> 1))) | (-(v1646 ^ ((int)((unsigned int)((int)((unsigned int)v1642 >> 2)) >> 1))))) >> 31)) | (~(((v1647 ^ ((int)((unsigned int)((int)((unsigned int)v1642 >> 2)) >> 1))) | (-(v1647 ^ ((int)((unsigned int)((int)((unsigned int)v1642 >> 2)) >> 1))))) >> 31))) & 104)))));
  v1638->timer = v1756;
  int * v1650 = v1638->cache_vals;
  bool v1757 = !(((~(((v1644 ^ ((int)((unsigned int)((int)((unsigned int)v1642 >> 2)) >> 1))) | (-(v1644 ^ ((int)((unsigned int)((int)((unsigned int)v1642 >> 2)) >> 1))))) >> 31)) | (~(((v1645 ^ ((int)((unsigned int)((int)((unsigned int)v1642 >> 2)) >> 1))) | (-(v1645 ^ ((int)((unsigned int)((int)((unsigned int)v1642 >> 2)) >> 1))))) >> 31))) == 0);
  int v1743;
  if (v1757) {
    int * v1651 = v1638->cache_age;
    int v1759 = ((((int)((unsigned int)((int)((unsigned int)v1642 >> 2)) >> 1)) & 1) * 2) + ((~(((v1645 ^ ((int)((unsigned int)((int)((unsigned int)v1642 >> 2)) >> 1))) | (-(v1645 ^ ((int)((unsigned int)((int)((unsigned int)v1642 >> 2)) >> 1))))) >> 31)) & 1);
    int v1652 = v1651[v1759];
    int v1653 = v1651[v1752];
    int v1760 = v1653 + ((int)((unsigned int)(v1653 - v1652) >> 31));
    v1651[v1752] = v1760;
    int * v1655 = v1638->cache_age;
    int v1656 = v1655[v1753];
    int v1762 = v1656 + ((int)((unsigned int)(v1656 - v1652) >> 31));
    v1655[v1753] = v1762;
    int * v1658 = v1638->cache_age;
    v1658[v1759] = 0;
    v1743 = v1759;
  } else {
    int * v1661 = v1638->cache_age;
    int v1766 = (((int)((unsigned int)((int)((unsigned int)v1642 >> 2)) >> 1)) & 1) * 2;
    int v1662 = v1661[v1766];
    int * v1663 = v1638->cache_tags;
    int v1664 = v1663[v1766];
    int v1665 = v1661[v1753];
    int v1666 = v1663[v1753];
    bool v1768 = !(((~(((v1646 ^ ((int)((unsigned int)((int)((unsigned int)v1642 >> 2)) >> 1))) | (-(v1646 ^ ((int)((unsigned int)((int)((unsigned int)v1642 >> 2)) >> 1))))) >> 31)) | (~(((v1647 ^ ((int)((unsigned int)((int)((unsigned int)v1642 >> 2)) >> 1))) | (-(v1647 ^ ((int)((unsigned int)((int)((unsigned int)v1642 >> 2)) >> 1))))) >> 31))) == 0);
    int v1720;
    if (v1768) {
      int * v1667 = v1638->cache_age;
      int v1770 = (4 + ((((int)((unsigned int)((int)((unsigned int)v1642 >> 2)) >> 1)) & 3) * 2)) + ((~(((v1647 ^ ((int)((unsigned int)((int)((unsigned int)v1642 >> 2)) >> 1))) | (-(v1647 ^ ((int)((unsigned int)((int)((unsigned int)v1642 >> 2)) >> 1))))) >> 31)) & 1);
      int v1668 = v1667[v1770];
      int v1669 = v1667[v1754];
      int v1771 = v1669 + ((int)((unsigned int)(v1669 - v1668) >> 31));
      v1667[v1754] = v1771;
      int * v1671 = v1638->cache_age;
      int v1672 = v1671[v1755];
      int v1773 = v1672 + ((int)((unsigned int)(v1672 - v1668) >> 31));
      v1671[v1755] = v1773;
      int * v1674 = v1638->cache_age;
      v1674[v1770] = 0;
      v1720 = v1770;
    } else {
      int * v1677 = v1638->cache_age;
      int v1777 = 4 + ((((int)((unsigned int)((int)((unsigned int)v1642 >> 2)) >> 1)) & 3) * 2);
      int v1678 = v1677[v1777];
      int * v1679 = v1638->cache_tags;
      int v1680 = v1679[v1777];
      int v1681 = v1677[v1755];
      int v1682 = v1679[v1755];
      int * v1683 = v1638->cache_dirty;
      int v1780 = (4 + ((((int)((unsigned int)((int)((unsigned int)v1642 >> 2)) >> 1)) & 3) * 2)) + ((((v1678 + ((~(((v1680 ^ -1) | (-(v1680 ^ -1))) >> 31)) & 2)) - (v1681 + ((~(((v1682 ^ -1) | (-(v1682 ^ -1))) >> 31)) & 2))) >> 31) & 1);
      int v1684 = v1683[v1780];
      bool v1781 = !(v1684 == 0);
      if (v1781) {
        int * v1685 = v1638->cache_tags;
        int v1686 = v1685[v1780];
        int * v1687 = v1638->cache_vals;
        int v1784 = ((4 + ((((int)((unsigned int)((int)((unsigned int)v1642 >> 2)) >> 1)) & 3) * 2)) + ((((v1678 + ((~(((v1680 ^ -1) | (-(v1680 ^ -1))) >> 31)) & 2)) - (v1681 + ((~(((v1682 ^ -1) | (-(v1682 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
        int v1688 = v1687[v1784];
        int v1785 = (((4 + ((((int)((unsigned int)((int)((unsigned int)v1642 >> 2)) >> 1)) & 3) * 2)) + ((((v1678 + ((~(((v1680 ^ -1) | (-(v1680 ^ -1))) >> 31)) & 2)) - (v1681 + ((~(((v1682 ^ -1) | (-(v1682 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
        int v1689 = v1687[v1785];
        int * v1690 = v1638->mem;
        int v1787 = v1686 * 2;
        v1690[v1787] = v1688;
        int * v1692 = v1638->mem;
        int v1790 = (v1686 * 2) + 1;
        v1692[v1790] = v1689;
        ;
      } else {
        ;
      }
      int * v1697 = v1638->mem;
      int v1795 = ((int)((unsigned int)((int)((unsigned int)v1642 >> 2)) >> 1)) * 2;
      int v1698 = v1697[v1795];
      int v1796 = (((int)((unsigned int)((int)((unsigned int)v1642 >> 2)) >> 1)) * 2) + 1;
      int v1699 = v1697[v1796];
      int * v1700 = v1638->cache_vals;
      int v1798 = ((4 + ((((int)((unsigned int)((int)((unsigned int)v1642 >> 2)) >> 1)) & 3) * 2)) + ((((v1678 + ((~(((v1680 ^ -1) | (-(v1680 ^ -1))) >> 31)) & 2)) - (v1681 + ((~(((v1682 ^ -1) | (-(v1682 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
      v1700[v1798] = v1698;
      int * v1702 = v1638->cache_vals;
      int v1801 = (((4 + ((((int)((unsigned int)((int)((unsigned int)v1642 >> 2)) >> 1)) & 3) * 2)) + ((((v1678 + ((~(((v1680 ^ -1) | (-(v1680 ^ -1))) >> 31)) & 2)) - (v1681 + ((~(((v1682 ^ -1) | (-(v1682 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
      v1702[v1801] = v1699;
      int * v1704 = v1638->cache_tags;
      int v1804 = (int)((unsigned int)((int)((unsigned int)v1642 >> 2)) >> 1);
      v1704[v1780] = v1804;
      int * v1706 = v1638->cache_dirty;
      v1706[v1780] = 0;
      int * v1708 = v1638->cache_age;
      v1708[v1780] = 1;
      int * v1710 = v1638->cache_age;
      int v1711 = v1710[v1780];
      int v1712 = v1710[v1754];
      int v1810 = v1712 + ((int)((unsigned int)(v1712 - v1711) >> 31));
      v1710[v1754] = v1810;
      int * v1714 = v1638->cache_age;
      int v1715 = v1714[v1755];
      int v1812 = v1715 + ((int)((unsigned int)(v1715 - v1711) >> 31));
      v1714[v1755] = v1812;
      int * v1717 = v1638->cache_age;
      v1717[v1780] = 0;
      v1720 = v1780;
    }
    int * v1721 = v1638->cache_vals;
    int v1815 = v1720 * 2;
    int v1722 = v1721[v1815];
    int v1816 = (v1720 * 2) + 1;
    int v1723 = v1721[v1816];
    int v1817 = (((((int)((unsigned int)((int)((unsigned int)v1642 >> 2)) >> 1)) & 1) * 2) + ((((v1662 + ((~(((v1664 ^ -1) | (-(v1664 ^ -1))) >> 31)) & 2)) - (v1665 + ((~(((v1666 ^ -1) | (-(v1666 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
    v1721[v1817] = v1722;
    int * v1725 = v1638->cache_vals;
    int v1820 = ((((((int)((unsigned int)((int)((unsigned int)v1642 >> 2)) >> 1)) & 1) * 2) + ((((v1662 + ((~(((v1664 ^ -1) | (-(v1664 ^ -1))) >> 31)) & 2)) - (v1665 + ((~(((v1666 ^ -1) | (-(v1666 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
    v1725[v1820] = v1723;
    int * v1727 = v1638->cache_tags;
    int v1823 = ((((int)((unsigned int)((int)((unsigned int)v1642 >> 2)) >> 1)) & 1) * 2) + ((((v1662 + ((~(((v1664 ^ -1) | (-(v1664 ^ -1))) >> 31)) & 2)) - (v1665 + ((~(((v1666 ^ -1) | (-(v1666 ^ -1))) >> 31)) & 2))) >> 31) & 1);
    int v1824 = (int)((unsigned int)((int)((unsigned int)v1642 >> 2)) >> 1);
    v1727[v1823] = v1824;
    int * v1729 = v1638->cache_dirty;
    v1729[v1823] = 0;
    int * v1731 = v1638->cache_age;
    v1731[v1823] = 1;
    int * v1733 = v1638->cache_age;
    int v1734 = v1733[v1823];
    int v1735 = v1733[v1752];
    int v1830 = v1735 + ((int)((unsigned int)(v1735 - v1734) >> 31));
    v1733[v1752] = v1830;
    int * v1737 = v1638->cache_age;
    int v1738 = v1737[v1753];
    int v1832 = v1738 + ((int)((unsigned int)(v1738 - v1734) >> 31));
    v1737[v1753] = v1832;
    int * v1740 = v1638->cache_age;
    v1740[v1823] = 0;
    v1743 = v1823;
  }
  int v1835 = (v1743 * 2) + (((int)((unsigned int)v1642 >> 2)) & 1);
  int v1744 = v1650[v1835];
  int * v1745 = v1638->regs;
  v1745[12] = v1744;
  return v1638;
}

struct StateT * slot_5(struct StateT * v1434) {
  int v1435 = v1434->timer;
  int v1545 = v1435 + 1;
  v1434->timer = v1545;
  int * v1437 = v1434->regs;
  int v1438 = v1437[8];
  int * v1439 = v1434->cache_tags;
  int v1549 = (((int)((unsigned int)((int)((unsigned int)v1438 >> 2)) >> 1)) & 1) * 2;
  int v1440 = v1439[v1549];
  int v1550 = ((((int)((unsigned int)((int)((unsigned int)v1438 >> 2)) >> 1)) & 1) * 2) + 1;
  int v1441 = v1439[v1550];
  int v1551 = 4 + ((((int)((unsigned int)((int)((unsigned int)v1438 >> 2)) >> 1)) & 3) * 2);
  int v1442 = v1439[v1551];
  int v1552 = (4 + ((((int)((unsigned int)((int)((unsigned int)v1438 >> 2)) >> 1)) & 3) * 2)) + 1;
  int v1443 = v1439[v1552];
  int v1444 = v1434->timer;
  int v1553 = v1444 + ((100 ^ (((~(((v1442 ^ ((int)((unsigned int)((int)((unsigned int)v1438 >> 2)) >> 1))) | (-(v1442 ^ ((int)((unsigned int)((int)((unsigned int)v1438 >> 2)) >> 1))))) >> 31)) | (~(((v1443 ^ ((int)((unsigned int)((int)((unsigned int)v1438 >> 2)) >> 1))) | (-(v1443 ^ ((int)((unsigned int)((int)((unsigned int)v1438 >> 2)) >> 1))))) >> 31))) & 104)) ^ (((~(((v1440 ^ ((int)((unsigned int)((int)((unsigned int)v1438 >> 2)) >> 1))) | (-(v1440 ^ ((int)((unsigned int)((int)((unsigned int)v1438 >> 2)) >> 1))))) >> 31)) | (~(((v1441 ^ ((int)((unsigned int)((int)((unsigned int)v1438 >> 2)) >> 1))) | (-(v1441 ^ ((int)((unsigned int)((int)((unsigned int)v1438 >> 2)) >> 1))))) >> 31))) & (1 ^ (100 ^ (((~(((v1442 ^ ((int)((unsigned int)((int)((unsigned int)v1438 >> 2)) >> 1))) | (-(v1442 ^ ((int)((unsigned int)((int)((unsigned int)v1438 >> 2)) >> 1))))) >> 31)) | (~(((v1443 ^ ((int)((unsigned int)((int)((unsigned int)v1438 >> 2)) >> 1))) | (-(v1443 ^ ((int)((unsigned int)((int)((unsigned int)v1438 >> 2)) >> 1))))) >> 31))) & 104)))));
  v1434->timer = v1553;
  int * v1446 = v1434->cache_vals;
  bool v1554 = !(((~(((v1440 ^ ((int)((unsigned int)((int)((unsigned int)v1438 >> 2)) >> 1))) | (-(v1440 ^ ((int)((unsigned int)((int)((unsigned int)v1438 >> 2)) >> 1))))) >> 31)) | (~(((v1441 ^ ((int)((unsigned int)((int)((unsigned int)v1438 >> 2)) >> 1))) | (-(v1441 ^ ((int)((unsigned int)((int)((unsigned int)v1438 >> 2)) >> 1))))) >> 31))) == 0);
  int v1539;
  if (v1554) {
    int * v1447 = v1434->cache_age;
    int v1556 = ((((int)((unsigned int)((int)((unsigned int)v1438 >> 2)) >> 1)) & 1) * 2) + ((~(((v1441 ^ ((int)((unsigned int)((int)((unsigned int)v1438 >> 2)) >> 1))) | (-(v1441 ^ ((int)((unsigned int)((int)((unsigned int)v1438 >> 2)) >> 1))))) >> 31)) & 1);
    int v1448 = v1447[v1556];
    int v1449 = v1447[v1549];
    int v1557 = v1449 + ((int)((unsigned int)(v1449 - v1448) >> 31));
    v1447[v1549] = v1557;
    int * v1451 = v1434->cache_age;
    int v1452 = v1451[v1550];
    int v1559 = v1452 + ((int)((unsigned int)(v1452 - v1448) >> 31));
    v1451[v1550] = v1559;
    int * v1454 = v1434->cache_age;
    v1454[v1556] = 0;
    v1539 = v1556;
  } else {
    int * v1457 = v1434->cache_age;
    int v1563 = (((int)((unsigned int)((int)((unsigned int)v1438 >> 2)) >> 1)) & 1) * 2;
    int v1458 = v1457[v1563];
    int * v1459 = v1434->cache_tags;
    int v1460 = v1459[v1563];
    int v1461 = v1457[v1550];
    int v1462 = v1459[v1550];
    bool v1565 = !(((~(((v1442 ^ ((int)((unsigned int)((int)((unsigned int)v1438 >> 2)) >> 1))) | (-(v1442 ^ ((int)((unsigned int)((int)((unsigned int)v1438 >> 2)) >> 1))))) >> 31)) | (~(((v1443 ^ ((int)((unsigned int)((int)((unsigned int)v1438 >> 2)) >> 1))) | (-(v1443 ^ ((int)((unsigned int)((int)((unsigned int)v1438 >> 2)) >> 1))))) >> 31))) == 0);
    int v1516;
    if (v1565) {
      int * v1463 = v1434->cache_age;
      int v1567 = (4 + ((((int)((unsigned int)((int)((unsigned int)v1438 >> 2)) >> 1)) & 3) * 2)) + ((~(((v1443 ^ ((int)((unsigned int)((int)((unsigned int)v1438 >> 2)) >> 1))) | (-(v1443 ^ ((int)((unsigned int)((int)((unsigned int)v1438 >> 2)) >> 1))))) >> 31)) & 1);
      int v1464 = v1463[v1567];
      int v1465 = v1463[v1551];
      int v1568 = v1465 + ((int)((unsigned int)(v1465 - v1464) >> 31));
      v1463[v1551] = v1568;
      int * v1467 = v1434->cache_age;
      int v1468 = v1467[v1552];
      int v1570 = v1468 + ((int)((unsigned int)(v1468 - v1464) >> 31));
      v1467[v1552] = v1570;
      int * v1470 = v1434->cache_age;
      v1470[v1567] = 0;
      v1516 = v1567;
    } else {
      int * v1473 = v1434->cache_age;
      int v1574 = 4 + ((((int)((unsigned int)((int)((unsigned int)v1438 >> 2)) >> 1)) & 3) * 2);
      int v1474 = v1473[v1574];
      int * v1475 = v1434->cache_tags;
      int v1476 = v1475[v1574];
      int v1477 = v1473[v1552];
      int v1478 = v1475[v1552];
      int * v1479 = v1434->cache_dirty;
      int v1577 = (4 + ((((int)((unsigned int)((int)((unsigned int)v1438 >> 2)) >> 1)) & 3) * 2)) + ((((v1474 + ((~(((v1476 ^ -1) | (-(v1476 ^ -1))) >> 31)) & 2)) - (v1477 + ((~(((v1478 ^ -1) | (-(v1478 ^ -1))) >> 31)) & 2))) >> 31) & 1);
      int v1480 = v1479[v1577];
      bool v1578 = !(v1480 == 0);
      if (v1578) {
        int * v1481 = v1434->cache_tags;
        int v1482 = v1481[v1577];
        int * v1483 = v1434->cache_vals;
        int v1581 = ((4 + ((((int)((unsigned int)((int)((unsigned int)v1438 >> 2)) >> 1)) & 3) * 2)) + ((((v1474 + ((~(((v1476 ^ -1) | (-(v1476 ^ -1))) >> 31)) & 2)) - (v1477 + ((~(((v1478 ^ -1) | (-(v1478 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
        int v1484 = v1483[v1581];
        int v1582 = (((4 + ((((int)((unsigned int)((int)((unsigned int)v1438 >> 2)) >> 1)) & 3) * 2)) + ((((v1474 + ((~(((v1476 ^ -1) | (-(v1476 ^ -1))) >> 31)) & 2)) - (v1477 + ((~(((v1478 ^ -1) | (-(v1478 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
        int v1485 = v1483[v1582];
        int * v1486 = v1434->mem;
        int v1584 = v1482 * 2;
        v1486[v1584] = v1484;
        int * v1488 = v1434->mem;
        int v1587 = (v1482 * 2) + 1;
        v1488[v1587] = v1485;
        ;
      } else {
        ;
      }
      int * v1493 = v1434->mem;
      int v1592 = ((int)((unsigned int)((int)((unsigned int)v1438 >> 2)) >> 1)) * 2;
      int v1494 = v1493[v1592];
      int v1593 = (((int)((unsigned int)((int)((unsigned int)v1438 >> 2)) >> 1)) * 2) + 1;
      int v1495 = v1493[v1593];
      int * v1496 = v1434->cache_vals;
      int v1595 = ((4 + ((((int)((unsigned int)((int)((unsigned int)v1438 >> 2)) >> 1)) & 3) * 2)) + ((((v1474 + ((~(((v1476 ^ -1) | (-(v1476 ^ -1))) >> 31)) & 2)) - (v1477 + ((~(((v1478 ^ -1) | (-(v1478 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
      v1496[v1595] = v1494;
      int * v1498 = v1434->cache_vals;
      int v1598 = (((4 + ((((int)((unsigned int)((int)((unsigned int)v1438 >> 2)) >> 1)) & 3) * 2)) + ((((v1474 + ((~(((v1476 ^ -1) | (-(v1476 ^ -1))) >> 31)) & 2)) - (v1477 + ((~(((v1478 ^ -1) | (-(v1478 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
      v1498[v1598] = v1495;
      int * v1500 = v1434->cache_tags;
      int v1601 = (int)((unsigned int)((int)((unsigned int)v1438 >> 2)) >> 1);
      v1500[v1577] = v1601;
      int * v1502 = v1434->cache_dirty;
      v1502[v1577] = 0;
      int * v1504 = v1434->cache_age;
      v1504[v1577] = 1;
      int * v1506 = v1434->cache_age;
      int v1507 = v1506[v1577];
      int v1508 = v1506[v1551];
      int v1607 = v1508 + ((int)((unsigned int)(v1508 - v1507) >> 31));
      v1506[v1551] = v1607;
      int * v1510 = v1434->cache_age;
      int v1511 = v1510[v1552];
      int v1609 = v1511 + ((int)((unsigned int)(v1511 - v1507) >> 31));
      v1510[v1552] = v1609;
      int * v1513 = v1434->cache_age;
      v1513[v1577] = 0;
      v1516 = v1577;
    }
    int * v1517 = v1434->cache_vals;
    int v1612 = v1516 * 2;
    int v1518 = v1517[v1612];
    int v1613 = (v1516 * 2) + 1;
    int v1519 = v1517[v1613];
    int v1614 = (((((int)((unsigned int)((int)((unsigned int)v1438 >> 2)) >> 1)) & 1) * 2) + ((((v1458 + ((~(((v1460 ^ -1) | (-(v1460 ^ -1))) >> 31)) & 2)) - (v1461 + ((~(((v1462 ^ -1) | (-(v1462 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
    v1517[v1614] = v1518;
    int * v1521 = v1434->cache_vals;
    int v1617 = ((((((int)((unsigned int)((int)((unsigned int)v1438 >> 2)) >> 1)) & 1) * 2) + ((((v1458 + ((~(((v1460 ^ -1) | (-(v1460 ^ -1))) >> 31)) & 2)) - (v1461 + ((~(((v1462 ^ -1) | (-(v1462 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
    v1521[v1617] = v1519;
    int * v1523 = v1434->cache_tags;
    int v1620 = ((((int)((unsigned int)((int)((unsigned int)v1438 >> 2)) >> 1)) & 1) * 2) + ((((v1458 + ((~(((v1460 ^ -1) | (-(v1460 ^ -1))) >> 31)) & 2)) - (v1461 + ((~(((v1462 ^ -1) | (-(v1462 ^ -1))) >> 31)) & 2))) >> 31) & 1);
    int v1621 = (int)((unsigned int)((int)((unsigned int)v1438 >> 2)) >> 1);
    v1523[v1620] = v1621;
    int * v1525 = v1434->cache_dirty;
    v1525[v1620] = 0;
    int * v1527 = v1434->cache_age;
    v1527[v1620] = 1;
    int * v1529 = v1434->cache_age;
    int v1530 = v1529[v1620];
    int v1531 = v1529[v1549];
    int v1627 = v1531 + ((int)((unsigned int)(v1531 - v1530) >> 31));
    v1529[v1549] = v1627;
    int * v1533 = v1434->cache_age;
    int v1534 = v1533[v1550];
    int v1629 = v1534 + ((int)((unsigned int)(v1534 - v1530) >> 31));
    v1533[v1550] = v1629;
    int * v1536 = v1434->cache_age;
    v1536[v1620] = 0;
    v1539 = v1620;
  }
  int v1632 = (v1539 * 2) + (((int)((unsigned int)v1438 >> 2)) & 1);
  int v1540 = v1446[v1632];
  int * v1541 = v1434->regs;
  v1541[11] = v1540;
  struct StateT * v1543 = slot_6(v1434);
  return v1543;
}

struct StateT * slot_4(struct StateT * v1244) {
  int v1245 = v1244->timer;
  int v1353 = v1245 + 1;
  v1244->timer = v1353;
  int * v1247 = v1244->cache_tags;
  int v1248 = v1247[0];
  int v1249 = v1247[1];
  int v1250 = v1247[4];
  int v1251 = v1247[5];
  int v1252 = v1244->timer;
  int v1359 = v1252 + ((100 ^ (((~(((v1250 ^ 4) | (-(v1250 ^ 4))) >> 31)) | (~(((v1251 ^ 4) | (-(v1251 ^ 4))) >> 31))) & 104)) ^ (((~(((v1248 ^ 4) | (-(v1248 ^ 4))) >> 31)) | (~(((v1249 ^ 4) | (-(v1249 ^ 4))) >> 31))) & (1 ^ (100 ^ (((~(((v1250 ^ 4) | (-(v1250 ^ 4))) >> 31)) | (~(((v1251 ^ 4) | (-(v1251 ^ 4))) >> 31))) & 104)))));
  v1244->timer = v1359;
  int * v1254 = v1244->cache_vals;
  bool v1360 = !(((~(((v1248 ^ 4) | (-(v1248 ^ 4))) >> 31)) | (~(((v1249 ^ 4) | (-(v1249 ^ 4))) >> 31))) == 0);
  int v1347;
  if (v1360) {
    int * v1255 = v1244->cache_age;
    int v1362 = (~(((v1249 ^ 4) | (-(v1249 ^ 4))) >> 31)) & 1;
    int v1256 = v1255[v1362];
    int v1257 = v1255[0];
    int v1363 = v1257 + ((int)((unsigned int)(v1257 - v1256) >> 31));
    v1255[0] = v1363;
    int * v1259 = v1244->cache_age;
    int v1260 = v1259[1];
    int v1365 = v1260 + ((int)((unsigned int)(v1260 - v1256) >> 31));
    v1259[1] = v1365;
    int * v1262 = v1244->cache_age;
    v1262[v1362] = 0;
    v1347 = v1362;
  } else {
    int * v1265 = v1244->cache_age;
    int v1266 = v1265[0];
    int * v1267 = v1244->cache_tags;
    int v1268 = v1267[0];
    int v1269 = v1265[1];
    int v1270 = v1267[1];
    bool v1369 = !(((~(((v1250 ^ 4) | (-(v1250 ^ 4))) >> 31)) | (~(((v1251 ^ 4) | (-(v1251 ^ 4))) >> 31))) == 0);
    int v1324;
    if (v1369) {
      int * v1271 = v1244->cache_age;
      int v1371 = 4 + ((~(((v1251 ^ 4) | (-(v1251 ^ 4))) >> 31)) & 1);
      int v1272 = v1271[v1371];
      int v1273 = v1271[4];
      int v1372 = v1273 + ((int)((unsigned int)(v1273 - v1272) >> 31));
      v1271[4] = v1372;
      int * v1275 = v1244->cache_age;
      int v1276 = v1275[5];
      int v1374 = v1276 + ((int)((unsigned int)(v1276 - v1272) >> 31));
      v1275[5] = v1374;
      int * v1278 = v1244->cache_age;
      v1278[v1371] = 0;
      v1324 = v1371;
    } else {
      int * v1281 = v1244->cache_age;
      int v1282 = v1281[4];
      int * v1283 = v1244->cache_tags;
      int v1284 = v1283[4];
      int v1285 = v1281[5];
      int v1286 = v1283[5];
      int * v1287 = v1244->cache_dirty;
      int v1379 = 4 + ((((v1282 + ((~(((v1284 ^ -1) | (-(v1284 ^ -1))) >> 31)) & 2)) - (v1285 + ((~(((v1286 ^ -1) | (-(v1286 ^ -1))) >> 31)) & 2))) >> 31) & 1);
      int v1288 = v1287[v1379];
      bool v1380 = !(v1288 == 0);
      if (v1380) {
        int * v1289 = v1244->cache_tags;
        int v1290 = v1289[v1379];
        int * v1291 = v1244->cache_vals;
        int v1383 = (4 + ((((v1282 + ((~(((v1284 ^ -1) | (-(v1284 ^ -1))) >> 31)) & 2)) - (v1285 + ((~(((v1286 ^ -1) | (-(v1286 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
        int v1292 = v1291[v1383];
        int v1384 = ((4 + ((((v1282 + ((~(((v1284 ^ -1) | (-(v1284 ^ -1))) >> 31)) & 2)) - (v1285 + ((~(((v1286 ^ -1) | (-(v1286 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
        int v1293 = v1291[v1384];
        int * v1294 = v1244->mem;
        int v1386 = v1290 * 2;
        v1294[v1386] = v1292;
        int * v1296 = v1244->mem;
        int v1389 = (v1290 * 2) + 1;
        v1296[v1389] = v1293;
        ;
      } else {
        ;
      }
      int * v1301 = v1244->mem;
      int v1302 = v1301[8];
      int v1303 = v1301[9];
      int * v1304 = v1244->cache_vals;
      int v1397 = (4 + ((((v1282 + ((~(((v1284 ^ -1) | (-(v1284 ^ -1))) >> 31)) & 2)) - (v1285 + ((~(((v1286 ^ -1) | (-(v1286 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
      v1304[v1397] = v1302;
      int * v1306 = v1244->cache_vals;
      int v1400 = ((4 + ((((v1282 + ((~(((v1284 ^ -1) | (-(v1284 ^ -1))) >> 31)) & 2)) - (v1285 + ((~(((v1286 ^ -1) | (-(v1286 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
      v1306[v1400] = v1303;
      int * v1308 = v1244->cache_tags;
      v1308[v1379] = 4;
      int * v1310 = v1244->cache_dirty;
      v1310[v1379] = 0;
      int * v1312 = v1244->cache_age;
      v1312[v1379] = 1;
      int * v1314 = v1244->cache_age;
      int v1315 = v1314[v1379];
      int v1316 = v1314[4];
      int v1406 = v1316 + ((int)((unsigned int)(v1316 - v1315) >> 31));
      v1314[4] = v1406;
      int * v1318 = v1244->cache_age;
      int v1319 = v1318[5];
      int v1408 = v1319 + ((int)((unsigned int)(v1319 - v1315) >> 31));
      v1318[5] = v1408;
      int * v1321 = v1244->cache_age;
      v1321[v1379] = 0;
      v1324 = v1379;
    }
    int * v1325 = v1244->cache_vals;
    int v1411 = v1324 * 2;
    int v1326 = v1325[v1411];
    int v1412 = (v1324 * 2) + 1;
    int v1327 = v1325[v1412];
    int v1413 = ((((v1266 + ((~(((v1268 ^ -1) | (-(v1268 ^ -1))) >> 31)) & 2)) - (v1269 + ((~(((v1270 ^ -1) | (-(v1270 ^ -1))) >> 31)) & 2))) >> 31) & 1) * 2;
    v1325[v1413] = v1326;
    int * v1329 = v1244->cache_vals;
    int v1416 = (((((v1266 + ((~(((v1268 ^ -1) | (-(v1268 ^ -1))) >> 31)) & 2)) - (v1269 + ((~(((v1270 ^ -1) | (-(v1270 ^ -1))) >> 31)) & 2))) >> 31) & 1) * 2) + 1;
    v1329[v1416] = v1327;
    int * v1331 = v1244->cache_tags;
    int v1419 = (((v1266 + ((~(((v1268 ^ -1) | (-(v1268 ^ -1))) >> 31)) & 2)) - (v1269 + ((~(((v1270 ^ -1) | (-(v1270 ^ -1))) >> 31)) & 2))) >> 31) & 1;
    v1331[v1419] = 4;
    int * v1333 = v1244->cache_dirty;
    v1333[v1419] = 0;
    int * v1335 = v1244->cache_age;
    v1335[v1419] = 1;
    int * v1337 = v1244->cache_age;
    int v1338 = v1337[v1419];
    int v1339 = v1337[0];
    int v1423 = v1339 + ((int)((unsigned int)(v1339 - v1338) >> 31));
    v1337[0] = v1423;
    int * v1341 = v1244->cache_age;
    int v1342 = v1341[1];
    int v1425 = v1342 + ((int)((unsigned int)(v1342 - v1338) >> 31));
    v1341[1] = v1425;
    int * v1344 = v1244->cache_age;
    v1344[v1419] = 0;
    v1347 = v1419;
  }
  int v1428 = (v1347 * 2) + 1;
  int v1348 = v1254[v1428];
  int * v1349 = v1244->regs;
  v1349[8] = v1348;
  struct StateT * v1351 = slot_5(v1244);
  return v1351;
}

struct StateT * slot_2(struct StateT * v32) {
  int v33 = v32->timer;
  int v202 = v33 + 1;
  v32->timer = v202;
  int * v35 = v32->regs;
  int v36 = v35[6];
  int * v37 = v32->cache_tags;
  int v38 = v37[0];
  int v39 = v37[1];
  int v40 = v37[4];
  int v41 = v37[5];
  int v42 = v32->timer;
  int v210 = v42 + ((100 ^ (((~(((v40 ^ 4) | (-(v40 ^ 4))) >> 31)) | (~(((v41 ^ 4) | (-(v41 ^ 4))) >> 31))) & 104)) ^ (((~(((v38 ^ 4) | (-(v38 ^ 4))) >> 31)) | (~(((v39 ^ 4) | (-(v39 ^ 4))) >> 31))) & (1 ^ (100 ^ (((~(((v40 ^ 4) | (-(v40 ^ 4))) >> 31)) | (~(((v41 ^ 4) | (-(v41 ^ 4))) >> 31))) & 104)))));
  v32->timer = v210;
  bool v211 = !(((~(((v38 ^ 4) | (-(v38 ^ 4))) >> 31)) | (~(((v39 ^ 4) | (-(v39 ^ 4))) >> 31))) == 0);
  int v136;
  if (v211) {
    int * v44 = v32->cache_age;
    int v213 = (~(((v39 ^ 4) | (-(v39 ^ 4))) >> 31)) & 1;
    int v45 = v44[v213];
    int v46 = v44[0];
    int v214 = v46 + ((int)((unsigned int)(v46 - v45) >> 31));
    v44[0] = v214;
    int * v48 = v32->cache_age;
    int v49 = v48[1];
    int v216 = v49 + ((int)((unsigned int)(v49 - v45) >> 31));
    v48[1] = v216;
    int * v51 = v32->cache_age;
    v51[v213] = 0;
    v136 = v213;
  } else {
    int * v54 = v32->cache_age;
    int v55 = v54[0];
    int * v56 = v32->cache_tags;
    int v57 = v56[0];
    int v58 = v54[1];
    int v59 = v56[1];
    bool v220 = !(((~(((v40 ^ 4) | (-(v40 ^ 4))) >> 31)) | (~(((v41 ^ 4) | (-(v41 ^ 4))) >> 31))) == 0);
    int v113;
    if (v220) {
      int * v60 = v32->cache_age;
      int v222 = 4 + ((~(((v41 ^ 4) | (-(v41 ^ 4))) >> 31)) & 1);
      int v61 = v60[v222];
      int v62 = v60[4];
      int v223 = v62 + ((int)((unsigned int)(v62 - v61) >> 31));
      v60[4] = v223;
      int * v64 = v32->cache_age;
      int v65 = v64[5];
      int v225 = v65 + ((int)((unsigned int)(v65 - v61) >> 31));
      v64[5] = v225;
      int * v67 = v32->cache_age;
      v67[v222] = 0;
      v113 = v222;
    } else {
      int * v70 = v32->cache_age;
      int v71 = v70[4];
      int * v72 = v32->cache_tags;
      int v73 = v72[4];
      int v74 = v70[5];
      int v75 = v72[5];
      int * v76 = v32->cache_dirty;
      int v230 = 4 + ((((v71 + ((~(((v73 ^ -1) | (-(v73 ^ -1))) >> 31)) & 2)) - (v74 + ((~(((v75 ^ -1) | (-(v75 ^ -1))) >> 31)) & 2))) >> 31) & 1);
      int v77 = v76[v230];
      bool v231 = !(v77 == 0);
      if (v231) {
        int * v78 = v32->cache_tags;
        int v79 = v78[v230];
        int * v80 = v32->cache_vals;
        int v234 = (4 + ((((v71 + ((~(((v73 ^ -1) | (-(v73 ^ -1))) >> 31)) & 2)) - (v74 + ((~(((v75 ^ -1) | (-(v75 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
        int v81 = v80[v234];
        int v235 = ((4 + ((((v71 + ((~(((v73 ^ -1) | (-(v73 ^ -1))) >> 31)) & 2)) - (v74 + ((~(((v75 ^ -1) | (-(v75 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
        int v82 = v80[v235];
        int * v83 = v32->mem;
        int v237 = v79 * 2;
        v83[v237] = v81;
        int * v85 = v32->mem;
        int v240 = (v79 * 2) + 1;
        v85[v240] = v82;
        ;
      } else {
        ;
      }
      int * v90 = v32->mem;
      int v91 = v90[8];
      int v92 = v90[9];
      int * v93 = v32->cache_vals;
      int v248 = (4 + ((((v71 + ((~(((v73 ^ -1) | (-(v73 ^ -1))) >> 31)) & 2)) - (v74 + ((~(((v75 ^ -1) | (-(v75 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
      v93[v248] = v91;
      int * v95 = v32->cache_vals;
      int v251 = ((4 + ((((v71 + ((~(((v73 ^ -1) | (-(v73 ^ -1))) >> 31)) & 2)) - (v74 + ((~(((v75 ^ -1) | (-(v75 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
      v95[v251] = v92;
      int * v97 = v32->cache_tags;
      v97[v230] = 4;
      int * v99 = v32->cache_dirty;
      v99[v230] = 0;
      int * v101 = v32->cache_age;
      v101[v230] = 1;
      int * v103 = v32->cache_age;
      int v104 = v103[v230];
      int v105 = v103[4];
      int v257 = v105 + ((int)((unsigned int)(v105 - v104) >> 31));
      v103[4] = v257;
      int * v107 = v32->cache_age;
      int v108 = v107[5];
      int v259 = v108 + ((int)((unsigned int)(v108 - v104) >> 31));
      v107[5] = v259;
      int * v110 = v32->cache_age;
      v110[v230] = 0;
      v113 = v230;
    }
    int * v114 = v32->cache_vals;
    int v262 = v113 * 2;
    int v115 = v114[v262];
    int v263 = (v113 * 2) + 1;
    int v116 = v114[v263];
    int v264 = ((((v55 + ((~(((v57 ^ -1) | (-(v57 ^ -1))) >> 31)) & 2)) - (v58 + ((~(((v59 ^ -1) | (-(v59 ^ -1))) >> 31)) & 2))) >> 31) & 1) * 2;
    v114[v264] = v115;
    int * v118 = v32->cache_vals;
    int v267 = (((((v55 + ((~(((v57 ^ -1) | (-(v57 ^ -1))) >> 31)) & 2)) - (v58 + ((~(((v59 ^ -1) | (-(v59 ^ -1))) >> 31)) & 2))) >> 31) & 1) * 2) + 1;
    v118[v267] = v116;
    int * v120 = v32->cache_tags;
    int v270 = (((v55 + ((~(((v57 ^ -1) | (-(v57 ^ -1))) >> 31)) & 2)) - (v58 + ((~(((v59 ^ -1) | (-(v59 ^ -1))) >> 31)) & 2))) >> 31) & 1;
    v120[v270] = 4;
    int * v122 = v32->cache_dirty;
    v122[v270] = 0;
    int * v124 = v32->cache_age;
    v124[v270] = 1;
    int * v126 = v32->cache_age;
    int v127 = v126[v270];
    int v128 = v126[0];
    int v274 = v128 + ((int)((unsigned int)(v128 - v127) >> 31));
    v126[0] = v274;
    int * v130 = v32->cache_age;
    int v131 = v130[1];
    int v276 = v131 + ((int)((unsigned int)(v131 - v127) >> 31));
    v130[1] = v276;
    int * v133 = v32->cache_age;
    v133[v270] = 0;
    v136 = v270;
  }
  int * v137 = v32->cache_vals;
  int v279 = (v136 * 2) + 1;
  v137[v279] = v36;
  int * v139 = v32->cache_tags;
  int v140 = v139[4];
  int v141 = v139[5];
  bool v282 = !(((~(((v140 ^ 4) | (-(v140 ^ 4))) >> 31)) | (~(((v141 ^ 4) | (-(v141 ^ 4))) >> 31))) == 0);
  int v195;
  if (v282) {
    int * v142 = v32->cache_age;
    int v284 = 4 + ((~(((v141 ^ 4) | (-(v141 ^ 4))) >> 31)) & 1);
    int v143 = v142[v284];
    int v144 = v142[4];
    int v285 = v144 + ((int)((unsigned int)(v144 - v143) >> 31));
    v142[4] = v285;
    int * v146 = v32->cache_age;
    int v147 = v146[5];
    int v287 = v147 + ((int)((unsigned int)(v147 - v143) >> 31));
    v146[5] = v287;
    int * v149 = v32->cache_age;
    v149[v284] = 0;
    v195 = v284;
  } else {
    int * v152 = v32->cache_age;
    int v153 = v152[4];
    int * v154 = v32->cache_tags;
    int v155 = v154[4];
    int v156 = v152[5];
    int v157 = v154[5];
    int * v158 = v32->cache_dirty;
    int v292 = 4 + ((((v153 + ((~(((v155 ^ -1) | (-(v155 ^ -1))) >> 31)) & 2)) - (v156 + ((~(((v157 ^ -1) | (-(v157 ^ -1))) >> 31)) & 2))) >> 31) & 1);
    int v159 = v158[v292];
    bool v293 = !(v159 == 0);
    if (v293) {
      int * v160 = v32->cache_tags;
      int v161 = v160[v292];
      int * v162 = v32->cache_vals;
      int v296 = (4 + ((((v153 + ((~(((v155 ^ -1) | (-(v155 ^ -1))) >> 31)) & 2)) - (v156 + ((~(((v157 ^ -1) | (-(v157 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
      int v163 = v162[v296];
      int v297 = ((4 + ((((v153 + ((~(((v155 ^ -1) | (-(v155 ^ -1))) >> 31)) & 2)) - (v156 + ((~(((v157 ^ -1) | (-(v157 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
      int v164 = v162[v297];
      int * v165 = v32->mem;
      int v299 = v161 * 2;
      v165[v299] = v163;
      int * v167 = v32->mem;
      int v302 = (v161 * 2) + 1;
      v167[v302] = v164;
      ;
    } else {
      ;
    }
    int * v172 = v32->mem;
    int v173 = v172[8];
    int v174 = v172[9];
    int * v175 = v32->cache_vals;
    int v310 = (4 + ((((v153 + ((~(((v155 ^ -1) | (-(v155 ^ -1))) >> 31)) & 2)) - (v156 + ((~(((v157 ^ -1) | (-(v157 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
    v175[v310] = v173;
    int * v177 = v32->cache_vals;
    int v313 = ((4 + ((((v153 + ((~(((v155 ^ -1) | (-(v155 ^ -1))) >> 31)) & 2)) - (v156 + ((~(((v157 ^ -1) | (-(v157 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
    v177[v313] = v174;
    int * v179 = v32->cache_tags;
    v179[v292] = 4;
    int * v181 = v32->cache_dirty;
    v181[v292] = 0;
    int * v183 = v32->cache_age;
    v183[v292] = 1;
    int * v185 = v32->cache_age;
    int v186 = v185[v292];
    int v187 = v185[4];
    int v319 = v187 + ((int)((unsigned int)(v187 - v186) >> 31));
    v185[4] = v319;
    int * v189 = v32->cache_age;
    int v190 = v189[5];
    int v321 = v190 + ((int)((unsigned int)(v190 - v186) >> 31));
    v189[5] = v321;
    int * v192 = v32->cache_age;
    v192[v292] = 0;
    v195 = v292;
  }
  int * v196 = v32->cache_vals;
  int v324 = (v195 * 2) + 1;
  v196[v324] = v36;
  int * v198 = v32->cache_dirty;
  v198[v195] = 1;
  struct StateT * v200 = slot_3(v32);
  return v200;
}

struct StateT * slot_3(struct StateT * v329) {
  int v330 = v329->timer;
  int v854 = v330 + 1;
  v329->timer = v854;
  int * v332 = v329->regs;
  int v333 = v332[5];
  int * v334 = v329->saved_regs;
  int v335 = v332[8];
  v334[8] = v335;
  int v337 = v329->timer;
  int v860 = v337 + 1;
  v329->timer = v860;
  int * v339 = v329->cache_tags;
  int v340 = v339[0];
  int v341 = v339[1];
  int v342 = v339[4];
  int v343 = v339[5];
  int v344 = v329->timer;
  int v865 = v344 + ((100 ^ (((~(((v342 ^ 4) | (-(v342 ^ 4))) >> 31)) | (~(((v343 ^ 4) | (-(v343 ^ 4))) >> 31))) & 104)) ^ (((~(((v340 ^ 4) | (-(v340 ^ 4))) >> 31)) | (~(((v341 ^ 4) | (-(v341 ^ 4))) >> 31))) & (1 ^ (100 ^ (((~(((v342 ^ 4) | (-(v342 ^ 4))) >> 31)) | (~(((v343 ^ 4) | (-(v343 ^ 4))) >> 31))) & 104)))));
  v329->timer = v865;
  int * v346 = v329->cache_vals;
  bool v866 = !(((~(((v340 ^ 4) | (-(v340 ^ 4))) >> 31)) | (~(((v341 ^ 4) | (-(v341 ^ 4))) >> 31))) == 0);
  int v439;
  if (v866) {
    int * v347 = v329->cache_age;
    int v868 = (~(((v341 ^ 4) | (-(v341 ^ 4))) >> 31)) & 1;
    int v348 = v347[v868];
    int v349 = v347[0];
    int v869 = v349 + ((int)((unsigned int)(v349 - v348) >> 31));
    v347[0] = v869;
    int * v351 = v329->cache_age;
    int v352 = v351[1];
    int v871 = v352 + ((int)((unsigned int)(v352 - v348) >> 31));
    v351[1] = v871;
    int * v354 = v329->cache_age;
    v354[v868] = 0;
    v439 = v868;
  } else {
    int * v357 = v329->cache_age;
    int v358 = v357[0];
    int * v359 = v329->cache_tags;
    int v360 = v359[0];
    int v361 = v357[1];
    int v362 = v359[1];
    bool v875 = !(((~(((v342 ^ 4) | (-(v342 ^ 4))) >> 31)) | (~(((v343 ^ 4) | (-(v343 ^ 4))) >> 31))) == 0);
    int v416;
    if (v875) {
      int * v363 = v329->cache_age;
      int v877 = 4 + ((~(((v343 ^ 4) | (-(v343 ^ 4))) >> 31)) & 1);
      int v364 = v363[v877];
      int v365 = v363[4];
      int v878 = v365 + ((int)((unsigned int)(v365 - v364) >> 31));
      v363[4] = v878;
      int * v367 = v329->cache_age;
      int v368 = v367[5];
      int v880 = v368 + ((int)((unsigned int)(v368 - v364) >> 31));
      v367[5] = v880;
      int * v370 = v329->cache_age;
      v370[v877] = 0;
      v416 = v877;
    } else {
      int * v373 = v329->cache_age;
      int v374 = v373[4];
      int * v375 = v329->cache_tags;
      int v376 = v375[4];
      int v377 = v373[5];
      int v378 = v375[5];
      int * v379 = v329->cache_dirty;
      int v885 = 4 + ((((v374 + ((~(((v376 ^ -1) | (-(v376 ^ -1))) >> 31)) & 2)) - (v377 + ((~(((v378 ^ -1) | (-(v378 ^ -1))) >> 31)) & 2))) >> 31) & 1);
      int v380 = v379[v885];
      bool v886 = !(v380 == 0);
      if (v886) {
        int * v381 = v329->cache_tags;
        int v382 = v381[v885];
        int * v383 = v329->cache_vals;
        int v889 = (4 + ((((v374 + ((~(((v376 ^ -1) | (-(v376 ^ -1))) >> 31)) & 2)) - (v377 + ((~(((v378 ^ -1) | (-(v378 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
        int v384 = v383[v889];
        int v890 = ((4 + ((((v374 + ((~(((v376 ^ -1) | (-(v376 ^ -1))) >> 31)) & 2)) - (v377 + ((~(((v378 ^ -1) | (-(v378 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
        int v385 = v383[v890];
        int * v386 = v329->mem;
        int v892 = v382 * 2;
        v386[v892] = v384;
        int * v388 = v329->mem;
        int v895 = (v382 * 2) + 1;
        v388[v895] = v385;
        ;
      } else {
        ;
      }
      int * v393 = v329->mem;
      int v394 = v393[8];
      int v395 = v393[9];
      int * v396 = v329->cache_vals;
      int v902 = (4 + ((((v374 + ((~(((v376 ^ -1) | (-(v376 ^ -1))) >> 31)) & 2)) - (v377 + ((~(((v378 ^ -1) | (-(v378 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
      v396[v902] = v394;
      int * v398 = v329->cache_vals;
      int v905 = ((4 + ((((v374 + ((~(((v376 ^ -1) | (-(v376 ^ -1))) >> 31)) & 2)) - (v377 + ((~(((v378 ^ -1) | (-(v378 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
      v398[v905] = v395;
      int * v400 = v329->cache_tags;
      v400[v885] = 4;
      int * v402 = v329->cache_dirty;
      v402[v885] = 0;
      int * v404 = v329->cache_age;
      v404[v885] = 1;
      int * v406 = v329->cache_age;
      int v407 = v406[v885];
      int v408 = v406[4];
      int v911 = v408 + ((int)((unsigned int)(v408 - v407) >> 31));
      v406[4] = v911;
      int * v410 = v329->cache_age;
      int v411 = v410[5];
      int v913 = v411 + ((int)((unsigned int)(v411 - v407) >> 31));
      v410[5] = v913;
      int * v413 = v329->cache_age;
      v413[v885] = 0;
      v416 = v885;
    }
    int * v417 = v329->cache_vals;
    int v916 = v416 * 2;
    int v418 = v417[v916];
    int v917 = (v416 * 2) + 1;
    int v419 = v417[v917];
    int v918 = ((((v358 + ((~(((v360 ^ -1) | (-(v360 ^ -1))) >> 31)) & 2)) - (v361 + ((~(((v362 ^ -1) | (-(v362 ^ -1))) >> 31)) & 2))) >> 31) & 1) * 2;
    v417[v918] = v418;
    int * v421 = v329->cache_vals;
    int v921 = (((((v358 + ((~(((v360 ^ -1) | (-(v360 ^ -1))) >> 31)) & 2)) - (v361 + ((~(((v362 ^ -1) | (-(v362 ^ -1))) >> 31)) & 2))) >> 31) & 1) * 2) + 1;
    v421[v921] = v419;
    int * v423 = v329->cache_tags;
    int v924 = (((v358 + ((~(((v360 ^ -1) | (-(v360 ^ -1))) >> 31)) & 2)) - (v361 + ((~(((v362 ^ -1) | (-(v362 ^ -1))) >> 31)) & 2))) >> 31) & 1;
    v423[v924] = 4;
    int * v425 = v329->cache_dirty;
    v425[v924] = 0;
    int * v427 = v329->cache_age;
    v427[v924] = 1;
    int * v429 = v329->cache_age;
    int v430 = v429[v924];
    int v431 = v429[0];
    int v928 = v431 + ((int)((unsigned int)(v431 - v430) >> 31));
    v429[0] = v928;
    int * v433 = v329->cache_age;
    int v434 = v433[1];
    int v930 = v434 + ((int)((unsigned int)(v434 - v430) >> 31));
    v433[1] = v930;
    int * v436 = v329->cache_age;
    v436[v924] = 0;
    v439 = v924;
  }
  int v933 = (v439 * 2) + 1;
  int v440 = v346[v933];
  int * v441 = v329->regs;
  v441[8] = v440;
  int * v443 = v329->saved_regs;
  int * v444 = v329->regs;
  int v445 = v444[11];
  v443[11] = v445;
  int v447 = v329->timer;
  int v940 = v447 + 1;
  v329->timer = v940;
  int * v449 = v329->regs;
  int v450 = v449[8];
  int * v451 = v329->cache_tags;
  int v943 = (((int)((unsigned int)((int)((unsigned int)v450 >> 2)) >> 1)) & 1) * 2;
  int v452 = v451[v943];
  int v944 = ((((int)((unsigned int)((int)((unsigned int)v450 >> 2)) >> 1)) & 1) * 2) + 1;
  int v453 = v451[v944];
  int v945 = 4 + ((((int)((unsigned int)((int)((unsigned int)v450 >> 2)) >> 1)) & 3) * 2);
  int v454 = v451[v945];
  int v946 = (4 + ((((int)((unsigned int)((int)((unsigned int)v450 >> 2)) >> 1)) & 3) * 2)) + 1;
  int v455 = v451[v946];
  int v456 = v329->timer;
  int v947 = v456 + ((100 ^ (((~(((v454 ^ ((int)((unsigned int)((int)((unsigned int)v450 >> 2)) >> 1))) | (-(v454 ^ ((int)((unsigned int)((int)((unsigned int)v450 >> 2)) >> 1))))) >> 31)) | (~(((v455 ^ ((int)((unsigned int)((int)((unsigned int)v450 >> 2)) >> 1))) | (-(v455 ^ ((int)((unsigned int)((int)((unsigned int)v450 >> 2)) >> 1))))) >> 31))) & 104)) ^ (((~(((v452 ^ ((int)((unsigned int)((int)((unsigned int)v450 >> 2)) >> 1))) | (-(v452 ^ ((int)((unsigned int)((int)((unsigned int)v450 >> 2)) >> 1))))) >> 31)) | (~(((v453 ^ ((int)((unsigned int)((int)((unsigned int)v450 >> 2)) >> 1))) | (-(v453 ^ ((int)((unsigned int)((int)((unsigned int)v450 >> 2)) >> 1))))) >> 31))) & (1 ^ (100 ^ (((~(((v454 ^ ((int)((unsigned int)((int)((unsigned int)v450 >> 2)) >> 1))) | (-(v454 ^ ((int)((unsigned int)((int)((unsigned int)v450 >> 2)) >> 1))))) >> 31)) | (~(((v455 ^ ((int)((unsigned int)((int)((unsigned int)v450 >> 2)) >> 1))) | (-(v455 ^ ((int)((unsigned int)((int)((unsigned int)v450 >> 2)) >> 1))))) >> 31))) & 104)))));
  v329->timer = v947;
  int * v458 = v329->cache_vals;
  bool v948 = !(((~(((v452 ^ ((int)((unsigned int)((int)((unsigned int)v450 >> 2)) >> 1))) | (-(v452 ^ ((int)((unsigned int)((int)((unsigned int)v450 >> 2)) >> 1))))) >> 31)) | (~(((v453 ^ ((int)((unsigned int)((int)((unsigned int)v450 >> 2)) >> 1))) | (-(v453 ^ ((int)((unsigned int)((int)((unsigned int)v450 >> 2)) >> 1))))) >> 31))) == 0);
  int v551;
  if (v948) {
    int * v459 = v329->cache_age;
    int v950 = ((((int)((unsigned int)((int)((unsigned int)v450 >> 2)) >> 1)) & 1) * 2) + ((~(((v453 ^ ((int)((unsigned int)((int)((unsigned int)v450 >> 2)) >> 1))) | (-(v453 ^ ((int)((unsigned int)((int)((unsigned int)v450 >> 2)) >> 1))))) >> 31)) & 1);
    int v460 = v459[v950];
    int v461 = v459[v943];
    int v951 = v461 + ((int)((unsigned int)(v461 - v460) >> 31));
    v459[v943] = v951;
    int * v463 = v329->cache_age;
    int v464 = v463[v944];
    int v953 = v464 + ((int)((unsigned int)(v464 - v460) >> 31));
    v463[v944] = v953;
    int * v466 = v329->cache_age;
    v466[v950] = 0;
    v551 = v950;
  } else {
    int * v469 = v329->cache_age;
    int v956 = (((int)((unsigned int)((int)((unsigned int)v450 >> 2)) >> 1)) & 1) * 2;
    int v470 = v469[v956];
    int * v471 = v329->cache_tags;
    int v472 = v471[v956];
    int v473 = v469[v944];
    int v474 = v471[v944];
    bool v958 = !(((~(((v454 ^ ((int)((unsigned int)((int)((unsigned int)v450 >> 2)) >> 1))) | (-(v454 ^ ((int)((unsigned int)((int)((unsigned int)v450 >> 2)) >> 1))))) >> 31)) | (~(((v455 ^ ((int)((unsigned int)((int)((unsigned int)v450 >> 2)) >> 1))) | (-(v455 ^ ((int)((unsigned int)((int)((unsigned int)v450 >> 2)) >> 1))))) >> 31))) == 0);
    int v528;
    if (v958) {
      int * v475 = v329->cache_age;
      int v960 = (4 + ((((int)((unsigned int)((int)((unsigned int)v450 >> 2)) >> 1)) & 3) * 2)) + ((~(((v455 ^ ((int)((unsigned int)((int)((unsigned int)v450 >> 2)) >> 1))) | (-(v455 ^ ((int)((unsigned int)((int)((unsigned int)v450 >> 2)) >> 1))))) >> 31)) & 1);
      int v476 = v475[v960];
      int v477 = v475[v945];
      int v961 = v477 + ((int)((unsigned int)(v477 - v476) >> 31));
      v475[v945] = v961;
      int * v479 = v329->cache_age;
      int v480 = v479[v946];
      int v963 = v480 + ((int)((unsigned int)(v480 - v476) >> 31));
      v479[v946] = v963;
      int * v482 = v329->cache_age;
      v482[v960] = 0;
      v528 = v960;
    } else {
      int * v485 = v329->cache_age;
      int v966 = 4 + ((((int)((unsigned int)((int)((unsigned int)v450 >> 2)) >> 1)) & 3) * 2);
      int v486 = v485[v966];
      int * v487 = v329->cache_tags;
      int v488 = v487[v966];
      int v489 = v485[v946];
      int v490 = v487[v946];
      int * v491 = v329->cache_dirty;
      int v969 = (4 + ((((int)((unsigned int)((int)((unsigned int)v450 >> 2)) >> 1)) & 3) * 2)) + ((((v486 + ((~(((v488 ^ -1) | (-(v488 ^ -1))) >> 31)) & 2)) - (v489 + ((~(((v490 ^ -1) | (-(v490 ^ -1))) >> 31)) & 2))) >> 31) & 1);
      int v492 = v491[v969];
      bool v970 = !(v492 == 0);
      if (v970) {
        int * v493 = v329->cache_tags;
        int v494 = v493[v969];
        int * v495 = v329->cache_vals;
        int v973 = ((4 + ((((int)((unsigned int)((int)((unsigned int)v450 >> 2)) >> 1)) & 3) * 2)) + ((((v486 + ((~(((v488 ^ -1) | (-(v488 ^ -1))) >> 31)) & 2)) - (v489 + ((~(((v490 ^ -1) | (-(v490 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
        int v496 = v495[v973];
        int v974 = (((4 + ((((int)((unsigned int)((int)((unsigned int)v450 >> 2)) >> 1)) & 3) * 2)) + ((((v486 + ((~(((v488 ^ -1) | (-(v488 ^ -1))) >> 31)) & 2)) - (v489 + ((~(((v490 ^ -1) | (-(v490 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
        int v497 = v495[v974];
        int * v498 = v329->mem;
        int v976 = v494 * 2;
        v498[v976] = v496;
        int * v500 = v329->mem;
        int v979 = (v494 * 2) + 1;
        v500[v979] = v497;
        ;
      } else {
        ;
      }
      int * v505 = v329->mem;
      int v984 = ((int)((unsigned int)((int)((unsigned int)v450 >> 2)) >> 1)) * 2;
      int v506 = v505[v984];
      int v985 = (((int)((unsigned int)((int)((unsigned int)v450 >> 2)) >> 1)) * 2) + 1;
      int v507 = v505[v985];
      int * v508 = v329->cache_vals;
      int v987 = ((4 + ((((int)((unsigned int)((int)((unsigned int)v450 >> 2)) >> 1)) & 3) * 2)) + ((((v486 + ((~(((v488 ^ -1) | (-(v488 ^ -1))) >> 31)) & 2)) - (v489 + ((~(((v490 ^ -1) | (-(v490 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
      v508[v987] = v506;
      int * v510 = v329->cache_vals;
      int v990 = (((4 + ((((int)((unsigned int)((int)((unsigned int)v450 >> 2)) >> 1)) & 3) * 2)) + ((((v486 + ((~(((v488 ^ -1) | (-(v488 ^ -1))) >> 31)) & 2)) - (v489 + ((~(((v490 ^ -1) | (-(v490 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
      v510[v990] = v507;
      int * v512 = v329->cache_tags;
      int v993 = (int)((unsigned int)((int)((unsigned int)v450 >> 2)) >> 1);
      v512[v969] = v993;
      int * v514 = v329->cache_dirty;
      v514[v969] = 0;
      int * v516 = v329->cache_age;
      v516[v969] = 1;
      int * v518 = v329->cache_age;
      int v519 = v518[v969];
      int v520 = v518[v945];
      int v997 = v520 + ((int)((unsigned int)(v520 - v519) >> 31));
      v518[v945] = v997;
      int * v522 = v329->cache_age;
      int v523 = v522[v946];
      int v999 = v523 + ((int)((unsigned int)(v523 - v519) >> 31));
      v522[v946] = v999;
      int * v525 = v329->cache_age;
      v525[v969] = 0;
      v528 = v969;
    }
    int * v529 = v329->cache_vals;
    int v1002 = v528 * 2;
    int v530 = v529[v1002];
    int v1003 = (v528 * 2) + 1;
    int v531 = v529[v1003];
    int v1004 = (((((int)((unsigned int)((int)((unsigned int)v450 >> 2)) >> 1)) & 1) * 2) + ((((v470 + ((~(((v472 ^ -1) | (-(v472 ^ -1))) >> 31)) & 2)) - (v473 + ((~(((v474 ^ -1) | (-(v474 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
    v529[v1004] = v530;
    int * v533 = v329->cache_vals;
    int v1007 = ((((((int)((unsigned int)((int)((unsigned int)v450 >> 2)) >> 1)) & 1) * 2) + ((((v470 + ((~(((v472 ^ -1) | (-(v472 ^ -1))) >> 31)) & 2)) - (v473 + ((~(((v474 ^ -1) | (-(v474 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
    v533[v1007] = v531;
    int * v535 = v329->cache_tags;
    int v1010 = ((((int)((unsigned int)((int)((unsigned int)v450 >> 2)) >> 1)) & 1) * 2) + ((((v470 + ((~(((v472 ^ -1) | (-(v472 ^ -1))) >> 31)) & 2)) - (v473 + ((~(((v474 ^ -1) | (-(v474 ^ -1))) >> 31)) & 2))) >> 31) & 1);
    int v1011 = (int)((unsigned int)((int)((unsigned int)v450 >> 2)) >> 1);
    v535[v1010] = v1011;
    int * v537 = v329->cache_dirty;
    v537[v1010] = 0;
    int * v539 = v329->cache_age;
    v539[v1010] = 1;
    int * v541 = v329->cache_age;
    int v542 = v541[v1010];
    int v543 = v541[v943];
    int v1015 = v543 + ((int)((unsigned int)(v543 - v542) >> 31));
    v541[v943] = v1015;
    int * v545 = v329->cache_age;
    int v546 = v545[v944];
    int v1017 = v546 + ((int)((unsigned int)(v546 - v542) >> 31));
    v545[v944] = v1017;
    int * v548 = v329->cache_age;
    v548[v1010] = 0;
    v551 = v1010;
  }
  int v1020 = (v551 * 2) + (((int)((unsigned int)v450 >> 2)) & 1);
  int v552 = v458[v1020];
  int * v553 = v329->regs;
  v553[11] = v552;
  int * v555 = v329->saved_regs;
  int * v556 = v329->regs;
  int v557 = v556[12];
  v555[12] = v557;
  int v559 = v329->timer;
  int v1027 = v559 + 1;
  v329->timer = v1027;
  int * v561 = v329->regs;
  int v562 = v561[11];
  bool v1029 = 1 == (((int)((unsigned int)v562 >> 2)) & 3);
  int v669;
  if (v1029) {
    int v563 = v329->timer;
    int v1030 = v563 + 1;
    v329->timer = v1030;
    v669 = v333;
  } else {
    int * v566 = v329->cache_tags;
    int v1033 = (((int)((unsigned int)((int)((unsigned int)v562 >> 2)) >> 1)) & 1) * 2;
    int v567 = v566[v1033];
    int v1034 = ((((int)((unsigned int)((int)((unsigned int)v562 >> 2)) >> 1)) & 1) * 2) + 1;
    int v568 = v566[v1034];
    int v1035 = 4 + ((((int)((unsigned int)((int)((unsigned int)v562 >> 2)) >> 1)) & 3) * 2);
    int v569 = v566[v1035];
    int v1036 = (4 + ((((int)((unsigned int)((int)((unsigned int)v562 >> 2)) >> 1)) & 3) * 2)) + 1;
    int v570 = v566[v1036];
    int v571 = v329->timer;
    int v1037 = v571 + ((100 ^ (((~(((v569 ^ ((int)((unsigned int)((int)((unsigned int)v562 >> 2)) >> 1))) | (-(v569 ^ ((int)((unsigned int)((int)((unsigned int)v562 >> 2)) >> 1))))) >> 31)) | (~(((v570 ^ ((int)((unsigned int)((int)((unsigned int)v562 >> 2)) >> 1))) | (-(v570 ^ ((int)((unsigned int)((int)((unsigned int)v562 >> 2)) >> 1))))) >> 31))) & 104)) ^ (((~(((v567 ^ ((int)((unsigned int)((int)((unsigned int)v562 >> 2)) >> 1))) | (-(v567 ^ ((int)((unsigned int)((int)((unsigned int)v562 >> 2)) >> 1))))) >> 31)) | (~(((v568 ^ ((int)((unsigned int)((int)((unsigned int)v562 >> 2)) >> 1))) | (-(v568 ^ ((int)((unsigned int)((int)((unsigned int)v562 >> 2)) >> 1))))) >> 31))) & (1 ^ (100 ^ (((~(((v569 ^ ((int)((unsigned int)((int)((unsigned int)v562 >> 2)) >> 1))) | (-(v569 ^ ((int)((unsigned int)((int)((unsigned int)v562 >> 2)) >> 1))))) >> 31)) | (~(((v570 ^ ((int)((unsigned int)((int)((unsigned int)v562 >> 2)) >> 1))) | (-(v570 ^ ((int)((unsigned int)((int)((unsigned int)v562 >> 2)) >> 1))))) >> 31))) & 104)))));
    v329->timer = v1037;
    int * v573 = v329->cache_vals;
    bool v1038 = !(((~(((v567 ^ ((int)((unsigned int)((int)((unsigned int)v562 >> 2)) >> 1))) | (-(v567 ^ ((int)((unsigned int)((int)((unsigned int)v562 >> 2)) >> 1))))) >> 31)) | (~(((v568 ^ ((int)((unsigned int)((int)((unsigned int)v562 >> 2)) >> 1))) | (-(v568 ^ ((int)((unsigned int)((int)((unsigned int)v562 >> 2)) >> 1))))) >> 31))) == 0);
    int v666;
    if (v1038) {
      int * v574 = v329->cache_age;
      int v1040 = ((((int)((unsigned int)((int)((unsigned int)v562 >> 2)) >> 1)) & 1) * 2) + ((~(((v568 ^ ((int)((unsigned int)((int)((unsigned int)v562 >> 2)) >> 1))) | (-(v568 ^ ((int)((unsigned int)((int)((unsigned int)v562 >> 2)) >> 1))))) >> 31)) & 1);
      int v575 = v574[v1040];
      int v576 = v574[v1033];
      int v1041 = v576 + ((int)((unsigned int)(v576 - v575) >> 31));
      v574[v1033] = v1041;
      int * v578 = v329->cache_age;
      int v579 = v578[v1034];
      int v1043 = v579 + ((int)((unsigned int)(v579 - v575) >> 31));
      v578[v1034] = v1043;
      int * v581 = v329->cache_age;
      v581[v1040] = 0;
      v666 = v1040;
    } else {
      int * v584 = v329->cache_age;
      int v1046 = (((int)((unsigned int)((int)((unsigned int)v562 >> 2)) >> 1)) & 1) * 2;
      int v585 = v584[v1046];
      int * v586 = v329->cache_tags;
      int v587 = v586[v1046];
      int v588 = v584[v1034];
      int v589 = v586[v1034];
      bool v1048 = !(((~(((v569 ^ ((int)((unsigned int)((int)((unsigned int)v562 >> 2)) >> 1))) | (-(v569 ^ ((int)((unsigned int)((int)((unsigned int)v562 >> 2)) >> 1))))) >> 31)) | (~(((v570 ^ ((int)((unsigned int)((int)((unsigned int)v562 >> 2)) >> 1))) | (-(v570 ^ ((int)((unsigned int)((int)((unsigned int)v562 >> 2)) >> 1))))) >> 31))) == 0);
      int v643;
      if (v1048) {
        int * v590 = v329->cache_age;
        int v1050 = (4 + ((((int)((unsigned int)((int)((unsigned int)v562 >> 2)) >> 1)) & 3) * 2)) + ((~(((v570 ^ ((int)((unsigned int)((int)((unsigned int)v562 >> 2)) >> 1))) | (-(v570 ^ ((int)((unsigned int)((int)((unsigned int)v562 >> 2)) >> 1))))) >> 31)) & 1);
        int v591 = v590[v1050];
        int v592 = v590[v1035];
        int v1051 = v592 + ((int)((unsigned int)(v592 - v591) >> 31));
        v590[v1035] = v1051;
        int * v594 = v329->cache_age;
        int v595 = v594[v1036];
        int v1053 = v595 + ((int)((unsigned int)(v595 - v591) >> 31));
        v594[v1036] = v1053;
        int * v597 = v329->cache_age;
        v597[v1050] = 0;
        v643 = v1050;
      } else {
        int * v600 = v329->cache_age;
        int v1056 = 4 + ((((int)((unsigned int)((int)((unsigned int)v562 >> 2)) >> 1)) & 3) * 2);
        int v601 = v600[v1056];
        int * v602 = v329->cache_tags;
        int v603 = v602[v1056];
        int v604 = v600[v1036];
        int v605 = v602[v1036];
        int * v606 = v329->cache_dirty;
        int v1059 = (4 + ((((int)((unsigned int)((int)((unsigned int)v562 >> 2)) >> 1)) & 3) * 2)) + ((((v601 + ((~(((v603 ^ -1) | (-(v603 ^ -1))) >> 31)) & 2)) - (v604 + ((~(((v605 ^ -1) | (-(v605 ^ -1))) >> 31)) & 2))) >> 31) & 1);
        int v607 = v606[v1059];
        bool v1060 = !(v607 == 0);
        if (v1060) {
          int * v608 = v329->cache_tags;
          int v609 = v608[v1059];
          int * v610 = v329->cache_vals;
          int v1063 = ((4 + ((((int)((unsigned int)((int)((unsigned int)v562 >> 2)) >> 1)) & 3) * 2)) + ((((v601 + ((~(((v603 ^ -1) | (-(v603 ^ -1))) >> 31)) & 2)) - (v604 + ((~(((v605 ^ -1) | (-(v605 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
          int v611 = v610[v1063];
          int v1064 = (((4 + ((((int)((unsigned int)((int)((unsigned int)v562 >> 2)) >> 1)) & 3) * 2)) + ((((v601 + ((~(((v603 ^ -1) | (-(v603 ^ -1))) >> 31)) & 2)) - (v604 + ((~(((v605 ^ -1) | (-(v605 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
          int v612 = v610[v1064];
          int * v613 = v329->mem;
          int v1066 = v609 * 2;
          v613[v1066] = v611;
          int * v615 = v329->mem;
          int v1069 = (v609 * 2) + 1;
          v615[v1069] = v612;
          ;
        } else {
          ;
        }
        int * v620 = v329->mem;
        int v1074 = ((int)((unsigned int)((int)((unsigned int)v562 >> 2)) >> 1)) * 2;
        int v621 = v620[v1074];
        int v1075 = (((int)((unsigned int)((int)((unsigned int)v562 >> 2)) >> 1)) * 2) + 1;
        int v622 = v620[v1075];
        int * v623 = v329->cache_vals;
        int v1077 = ((4 + ((((int)((unsigned int)((int)((unsigned int)v562 >> 2)) >> 1)) & 3) * 2)) + ((((v601 + ((~(((v603 ^ -1) | (-(v603 ^ -1))) >> 31)) & 2)) - (v604 + ((~(((v605 ^ -1) | (-(v605 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
        v623[v1077] = v621;
        int * v625 = v329->cache_vals;
        int v1080 = (((4 + ((((int)((unsigned int)((int)((unsigned int)v562 >> 2)) >> 1)) & 3) * 2)) + ((((v601 + ((~(((v603 ^ -1) | (-(v603 ^ -1))) >> 31)) & 2)) - (v604 + ((~(((v605 ^ -1) | (-(v605 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
        v625[v1080] = v622;
        int * v627 = v329->cache_tags;
        int v1083 = (int)((unsigned int)((int)((unsigned int)v562 >> 2)) >> 1);
        v627[v1059] = v1083;
        int * v629 = v329->cache_dirty;
        v629[v1059] = 0;
        int * v631 = v329->cache_age;
        v631[v1059] = 1;
        int * v633 = v329->cache_age;
        int v634 = v633[v1059];
        int v635 = v633[v1035];
        int v1087 = v635 + ((int)((unsigned int)(v635 - v634) >> 31));
        v633[v1035] = v1087;
        int * v637 = v329->cache_age;
        int v638 = v637[v1036];
        int v1089 = v638 + ((int)((unsigned int)(v638 - v634) >> 31));
        v637[v1036] = v1089;
        int * v640 = v329->cache_age;
        v640[v1059] = 0;
        v643 = v1059;
      }
      int * v644 = v329->cache_vals;
      int v1092 = v643 * 2;
      int v645 = v644[v1092];
      int v1093 = (v643 * 2) + 1;
      int v646 = v644[v1093];
      int v1094 = (((((int)((unsigned int)((int)((unsigned int)v562 >> 2)) >> 1)) & 1) * 2) + ((((v585 + ((~(((v587 ^ -1) | (-(v587 ^ -1))) >> 31)) & 2)) - (v588 + ((~(((v589 ^ -1) | (-(v589 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
      v644[v1094] = v645;
      int * v648 = v329->cache_vals;
      int v1097 = ((((((int)((unsigned int)((int)((unsigned int)v562 >> 2)) >> 1)) & 1) * 2) + ((((v585 + ((~(((v587 ^ -1) | (-(v587 ^ -1))) >> 31)) & 2)) - (v588 + ((~(((v589 ^ -1) | (-(v589 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
      v648[v1097] = v646;
      int * v650 = v329->cache_tags;
      int v1100 = ((((int)((unsigned int)((int)((unsigned int)v562 >> 2)) >> 1)) & 1) * 2) + ((((v585 + ((~(((v587 ^ -1) | (-(v587 ^ -1))) >> 31)) & 2)) - (v588 + ((~(((v589 ^ -1) | (-(v589 ^ -1))) >> 31)) & 2))) >> 31) & 1);
      int v1101 = (int)((unsigned int)((int)((unsigned int)v562 >> 2)) >> 1);
      v650[v1100] = v1101;
      int * v652 = v329->cache_dirty;
      v652[v1100] = 0;
      int * v654 = v329->cache_age;
      v654[v1100] = 1;
      int * v656 = v329->cache_age;
      int v657 = v656[v1100];
      int v658 = v656[v1033];
      int v1105 = v658 + ((int)((unsigned int)(v658 - v657) >> 31));
      v656[v1033] = v1105;
      int * v660 = v329->cache_age;
      int v661 = v660[v1034];
      int v1107 = v661 + ((int)((unsigned int)(v661 - v657) >> 31));
      v660[v1034] = v1107;
      int * v663 = v329->cache_age;
      v663[v1100] = 0;
      v666 = v1100;
    }
    int v1110 = (v666 * 2) + (((int)((unsigned int)v562 >> 2)) & 1);
    int v667 = v573[v1110];
    v669 = v667;
  }
  int * v670 = v329->regs;
  v670[12] = v669;
  int * v672 = v329->cache_tags;
  int v673 = v672[0];
  int v674 = v672[1];
  int v675 = v672[4];
  int v676 = v672[5];
  int v677 = v329->timer;
  int v1115 = v677 + ((100 ^ (((~(((v675 ^ 4) | (-(v675 ^ 4))) >> 31)) | (~(((v676 ^ 4) | (-(v676 ^ 4))) >> 31))) & 104)) ^ (((~(((v673 ^ 4) | (-(v673 ^ 4))) >> 31)) | (~(((v674 ^ 4) | (-(v674 ^ 4))) >> 31))) & (1 ^ (100 ^ (((~(((v675 ^ 4) | (-(v675 ^ 4))) >> 31)) | (~(((v676 ^ 4) | (-(v676 ^ 4))) >> 31))) & 104)))));
  v329->timer = v1115;
  bool v1116 = !(((~(((v673 ^ 4) | (-(v673 ^ 4))) >> 31)) | (~(((v674 ^ 4) | (-(v674 ^ 4))) >> 31))) == 0);
  int v771;
  if (v1116) {
    int * v679 = v329->cache_age;
    int v1118 = (~(((v674 ^ 4) | (-(v674 ^ 4))) >> 31)) & 1;
    int v680 = v679[v1118];
    int v681 = v679[0];
    int v1119 = v681 + ((int)((unsigned int)(v681 - v680) >> 31));
    v679[0] = v1119;
    int * v683 = v329->cache_age;
    int v684 = v683[1];
    int v1121 = v684 + ((int)((unsigned int)(v684 - v680) >> 31));
    v683[1] = v1121;
    int * v686 = v329->cache_age;
    v686[v1118] = 0;
    v771 = v1118;
  } else {
    int * v689 = v329->cache_age;
    int v690 = v689[0];
    int * v691 = v329->cache_tags;
    int v692 = v691[0];
    int v693 = v689[1];
    int v694 = v691[1];
    bool v1125 = !(((~(((v675 ^ 4) | (-(v675 ^ 4))) >> 31)) | (~(((v676 ^ 4) | (-(v676 ^ 4))) >> 31))) == 0);
    int v748;
    if (v1125) {
      int * v695 = v329->cache_age;
      int v1127 = 4 + ((~(((v676 ^ 4) | (-(v676 ^ 4))) >> 31)) & 1);
      int v696 = v695[v1127];
      int v697 = v695[4];
      int v1128 = v697 + ((int)((unsigned int)(v697 - v696) >> 31));
      v695[4] = v1128;
      int * v699 = v329->cache_age;
      int v700 = v699[5];
      int v1130 = v700 + ((int)((unsigned int)(v700 - v696) >> 31));
      v699[5] = v1130;
      int * v702 = v329->cache_age;
      v702[v1127] = 0;
      v748 = v1127;
    } else {
      int * v705 = v329->cache_age;
      int v706 = v705[4];
      int * v707 = v329->cache_tags;
      int v708 = v707[4];
      int v709 = v705[5];
      int v710 = v707[5];
      int * v711 = v329->cache_dirty;
      int v1135 = 4 + ((((v706 + ((~(((v708 ^ -1) | (-(v708 ^ -1))) >> 31)) & 2)) - (v709 + ((~(((v710 ^ -1) | (-(v710 ^ -1))) >> 31)) & 2))) >> 31) & 1);
      int v712 = v711[v1135];
      bool v1136 = !(v712 == 0);
      if (v1136) {
        int * v713 = v329->cache_tags;
        int v714 = v713[v1135];
        int * v715 = v329->cache_vals;
        int v1139 = (4 + ((((v706 + ((~(((v708 ^ -1) | (-(v708 ^ -1))) >> 31)) & 2)) - (v709 + ((~(((v710 ^ -1) | (-(v710 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
        int v716 = v715[v1139];
        int v1140 = ((4 + ((((v706 + ((~(((v708 ^ -1) | (-(v708 ^ -1))) >> 31)) & 2)) - (v709 + ((~(((v710 ^ -1) | (-(v710 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
        int v717 = v715[v1140];
        int * v718 = v329->mem;
        int v1142 = v714 * 2;
        v718[v1142] = v716;
        int * v720 = v329->mem;
        int v1145 = (v714 * 2) + 1;
        v720[v1145] = v717;
        ;
      } else {
        ;
      }
      int * v725 = v329->mem;
      int v726 = v725[8];
      int v727 = v725[9];
      int * v728 = v329->cache_vals;
      int v1152 = (4 + ((((v706 + ((~(((v708 ^ -1) | (-(v708 ^ -1))) >> 31)) & 2)) - (v709 + ((~(((v710 ^ -1) | (-(v710 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
      v728[v1152] = v726;
      int * v730 = v329->cache_vals;
      int v1155 = ((4 + ((((v706 + ((~(((v708 ^ -1) | (-(v708 ^ -1))) >> 31)) & 2)) - (v709 + ((~(((v710 ^ -1) | (-(v710 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
      v730[v1155] = v727;
      int * v732 = v329->cache_tags;
      v732[v1135] = 4;
      int * v734 = v329->cache_dirty;
      v734[v1135] = 0;
      int * v736 = v329->cache_age;
      v736[v1135] = 1;
      int * v738 = v329->cache_age;
      int v739 = v738[v1135];
      int v740 = v738[4];
      int v1161 = v740 + ((int)((unsigned int)(v740 - v739) >> 31));
      v738[4] = v1161;
      int * v742 = v329->cache_age;
      int v743 = v742[5];
      int v1163 = v743 + ((int)((unsigned int)(v743 - v739) >> 31));
      v742[5] = v1163;
      int * v745 = v329->cache_age;
      v745[v1135] = 0;
      v748 = v1135;
    }
    int * v749 = v329->cache_vals;
    int v1166 = v748 * 2;
    int v750 = v749[v1166];
    int v1167 = (v748 * 2) + 1;
    int v751 = v749[v1167];
    int v1168 = ((((v690 + ((~(((v692 ^ -1) | (-(v692 ^ -1))) >> 31)) & 2)) - (v693 + ((~(((v694 ^ -1) | (-(v694 ^ -1))) >> 31)) & 2))) >> 31) & 1) * 2;
    v749[v1168] = v750;
    int * v753 = v329->cache_vals;
    int v1171 = (((((v690 + ((~(((v692 ^ -1) | (-(v692 ^ -1))) >> 31)) & 2)) - (v693 + ((~(((v694 ^ -1) | (-(v694 ^ -1))) >> 31)) & 2))) >> 31) & 1) * 2) + 1;
    v753[v1171] = v751;
    int * v755 = v329->cache_tags;
    int v1174 = (((v690 + ((~(((v692 ^ -1) | (-(v692 ^ -1))) >> 31)) & 2)) - (v693 + ((~(((v694 ^ -1) | (-(v694 ^ -1))) >> 31)) & 2))) >> 31) & 1;
    v755[v1174] = 4;
    int * v757 = v329->cache_dirty;
    v757[v1174] = 0;
    int * v759 = v329->cache_age;
    v759[v1174] = 1;
    int * v761 = v329->cache_age;
    int v762 = v761[v1174];
    int v763 = v761[0];
    int v1178 = v763 + ((int)((unsigned int)(v763 - v762) >> 31));
    v761[0] = v1178;
    int * v765 = v329->cache_age;
    int v766 = v765[1];
    int v1180 = v766 + ((int)((unsigned int)(v766 - v762) >> 31));
    v765[1] = v1180;
    int * v768 = v329->cache_age;
    v768[v1174] = 0;
    v771 = v1174;
  }
  int * v772 = v329->cache_vals;
  int v1183 = (v771 * 2) + 1;
  v772[v1183] = v333;
  int * v774 = v329->cache_tags;
  int v775 = v774[4];
  int v776 = v774[5];
  bool v1186 = !(((~(((v775 ^ 4) | (-(v775 ^ 4))) >> 31)) | (~(((v776 ^ 4) | (-(v776 ^ 4))) >> 31))) == 0);
  int v830;
  if (v1186) {
    int * v777 = v329->cache_age;
    int v1188 = 4 + ((~(((v776 ^ 4) | (-(v776 ^ 4))) >> 31)) & 1);
    int v778 = v777[v1188];
    int v779 = v777[4];
    int v1189 = v779 + ((int)((unsigned int)(v779 - v778) >> 31));
    v777[4] = v1189;
    int * v781 = v329->cache_age;
    int v782 = v781[5];
    int v1191 = v782 + ((int)((unsigned int)(v782 - v778) >> 31));
    v781[5] = v1191;
    int * v784 = v329->cache_age;
    v784[v1188] = 0;
    v830 = v1188;
  } else {
    int * v787 = v329->cache_age;
    int v788 = v787[4];
    int * v789 = v329->cache_tags;
    int v790 = v789[4];
    int v791 = v787[5];
    int v792 = v789[5];
    int * v793 = v329->cache_dirty;
    int v1196 = 4 + ((((v788 + ((~(((v790 ^ -1) | (-(v790 ^ -1))) >> 31)) & 2)) - (v791 + ((~(((v792 ^ -1) | (-(v792 ^ -1))) >> 31)) & 2))) >> 31) & 1);
    int v794 = v793[v1196];
    bool v1197 = !(v794 == 0);
    if (v1197) {
      int * v795 = v329->cache_tags;
      int v796 = v795[v1196];
      int * v797 = v329->cache_vals;
      int v1200 = (4 + ((((v788 + ((~(((v790 ^ -1) | (-(v790 ^ -1))) >> 31)) & 2)) - (v791 + ((~(((v792 ^ -1) | (-(v792 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
      int v798 = v797[v1200];
      int v1201 = ((4 + ((((v788 + ((~(((v790 ^ -1) | (-(v790 ^ -1))) >> 31)) & 2)) - (v791 + ((~(((v792 ^ -1) | (-(v792 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
      int v799 = v797[v1201];
      int * v800 = v329->mem;
      int v1203 = v796 * 2;
      v800[v1203] = v798;
      int * v802 = v329->mem;
      int v1206 = (v796 * 2) + 1;
      v802[v1206] = v799;
      ;
    } else {
      ;
    }
    int * v807 = v329->mem;
    int v808 = v807[8];
    int v809 = v807[9];
    int * v810 = v329->cache_vals;
    int v1213 = (4 + ((((v788 + ((~(((v790 ^ -1) | (-(v790 ^ -1))) >> 31)) & 2)) - (v791 + ((~(((v792 ^ -1) | (-(v792 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
    v810[v1213] = v808;
    int * v812 = v329->cache_vals;
    int v1216 = ((4 + ((((v788 + ((~(((v790 ^ -1) | (-(v790 ^ -1))) >> 31)) & 2)) - (v791 + ((~(((v792 ^ -1) | (-(v792 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
    v812[v1216] = v809;
    int * v814 = v329->cache_tags;
    v814[v1196] = 4;
    int * v816 = v329->cache_dirty;
    v816[v1196] = 0;
    int * v818 = v329->cache_age;
    v818[v1196] = 1;
    int * v820 = v329->cache_age;
    int v821 = v820[v1196];
    int v822 = v820[4];
    int v1222 = v822 + ((int)((unsigned int)(v822 - v821) >> 31));
    v820[4] = v1222;
    int * v824 = v329->cache_age;
    int v825 = v824[5];
    int v1224 = v825 + ((int)((unsigned int)(v825 - v821) >> 31));
    v824[5] = v1224;
    int * v827 = v329->cache_age;
    v827[v1196] = 0;
    v830 = v1196;
  }
  int * v831 = v329->cache_vals;
  int v1227 = (v830 * 2) + 1;
  v831[v1227] = v333;
  int * v833 = v329->cache_dirty;
  v833[v830] = 1;
  struct StateT * v852;
  int v835 = v329->timer;
  int v1231 = v835 + 15;
  v329->timer = v1231;
  int * v837 = v329->saved_regs;
  int v838 = v837[8];
  int * v839 = v329->regs;
  v839[8] = v838;
  int * v841 = v329->saved_regs;
  int v842 = v841[11];
  int * v843 = v329->regs;
  v843[11] = v842;
  int * v845 = v329->saved_regs;
  int v846 = v845[12];
  int * v847 = v329->regs;
  v847[12] = v846;
  struct StateT * v849 = slot_4(v329);
  v852 = v849;
  return v852;
}

struct StateT * slot_0(struct StateT * v2) {
  int v3 = v2->timer;
  int v10 = v3 + 1;
  v2->timer = v10;
  int * v5 = v2->regs;
  int v6 = v5[10];
  int v14 = v6 & 28;
  v5[5] = v14;
  struct StateT * v8 = slot_1(v2);
  return v8;
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
    s1.mem[SECRET_OFFSET+i] = secret(0, 20);
    s2.mem[SECRET_OFFSET+i] = secret(0, 20);
  }
  struct StateT *s1_ = snippet(&s1);
  struct StateT *s2_ = snippet(&s2);
  //@ assert untainted_timer: !\tainted(s1_->timer==s2_->timer);
  koika_assert(s1_->timer==s2_->timer, "timing leak");
  return 0;
}