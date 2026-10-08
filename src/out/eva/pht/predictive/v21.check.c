// verify: leak widened (the program is clean; Eva cannot prove it) [unroll 65]
#define NUM_REGS 32
#define MEM_SIZE 64
#define SECRET_SIZE 10
#define SECRET_OFFSET 20
#define CACHE_ENTRIES 12
#define CACHE_WORDS 24

#ifdef EVA
#include "__fc_builtin.h"
/*@ assigns *p \from \nothing;
    taints *p; */
void koika_mark(int *p);
#define koika_assert(b, s) ((void)0)
#define koika_assume(b) do { if (!(b)) Frama_C_abort(); } while (0)
#define koika_draw(x) ((x) = Frama_C_interval(-2147483647-1, 2147483647))
#define koika_secret(x) koika_mark(&(x))
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

struct StateT * slot_12(struct StateT * v759);
struct StateT * slot_34(struct StateT * v1865);
struct StateT * slot_43(struct StateT * v2473);
struct StateT * slot_6(struct StateT * v469);
struct StateT * slot_29(struct StateT * v1617);
struct StateT * slot_25(struct StateT * v1267);
struct StateT * slot_16(struct StateT * v827);
struct StateT * slot_23(struct StateT * v1236);
struct StateT * slot_5(struct StateT * v266);
struct StateT * slot_2(struct StateT * v218);
struct StateT * slot_7(struct StateT * v489);
struct StateT * slot_21(struct StateT * v1211);
struct StateT * slot_31(struct StateT * v1820);
struct StateT * slot_3(struct StateT * v226);
struct StateT * slot_45(struct StateT * v2535);
struct StateT * slot_26(struct StateT * v1281);
struct StateT * slot_10(struct StateT * v540);
struct StateT * slot_1(struct StateT * v15);
struct StateT * slot_19(struct StateT * v888);
struct StateT * slot_13(struct StateT * v814);
struct StateT * slot_38(struct StateT * v2228);
struct StateT * slot_0(struct StateT * v2);
struct StateT * slot_14(struct StateT * v819);
struct StateT * slot_42(struct StateT * v2270);
struct StateT * slot_44(struct StateT * v2496);
struct StateT * slot_32(struct StateT * v1836);
struct StateT * slot_17(struct StateT * v848);
struct StateT * slot_33(struct StateT * v1844);
struct StateT * slot_36(struct StateT * v1905);
struct StateT * snippet(struct StateT * v0);
struct StateT * slot_40(struct StateT * v2254);
struct StateT * slot_8(struct StateT * v503);
struct StateT * slot_27(struct StateT * v1596);
struct StateT * slot_4(struct StateT * v246);
struct StateT * slot_9(struct StateT * v524);
struct StateT * slot_11(struct StateT * v743);
struct StateT * slot_12(struct StateT * v759) {
  int * v760 = v759->saved_regs;
  int v761 = v760[10];
  int * v762 = v759->regs;
  int v763 = v762[11];
  bool v792 = (v761 ^ -2147483648) >= (v763 ^ -2147483648);
  struct StateT * v786;
  if (v792) {
    int v764 = v759->timer;
    int v793 = v764 + 15;
    v759->timer = v793;
    int * v766 = v759->saved_regs;
    int v767 = v766[13];
    int * v768 = v759->regs;
    v768[13] = v767;
    int * v770 = v759->saved_regs;
    int v771 = v770[12];
    int * v772 = v759->regs;
    v772[12] = v771;
    int * v774 = v759->saved_regs;
    int v775 = v774[14];
    int * v776 = v759->regs;
    v776[14] = v775;
    int * v778 = v759->saved_regs;
    int v779 = v778[10];
    int * v780 = v759->regs;
    v780[10] = v779;
    struct StateT * v782 = slot_13(v759);
    v786 = v782;
  } else {
    struct StateT * v784 = slot_14(v759);
    v786 = v784;
  }
  return v786;
}

struct StateT * slot_34(struct StateT * v1865) {
  int * v1866 = v1865->saved_regs;
  int v1867 = v1866[13];
  bool v1882 = !(v1867 == 0);
  struct StateT * v1878;
  if (v1882) {
    int v1868 = v1865->timer;
    int v1883 = v1868 + 15;
    v1865->timer = v1883;
    int * v1870 = v1865->saved_regs;
    int v1871 = v1870[13];
    int * v1872 = v1865->regs;
    v1872[13] = v1871;
    struct StateT * v1874 = slot_45(v1865);
    v1878 = v1874;
  } else {
    struct StateT * v1876 = slot_36(v1865);
    v1878 = v1876;
  }
  return v1878;
}

struct StateT * slot_43(struct StateT * v2473) {
  int * v2474 = v2473->saved_regs;
  int * v2475 = v2473->regs;
  int v2476 = v2475[12];
  v2474[12] = v2476;
  int v2478 = v2473->timer;
  int v2490 = v2478 + 1;
  v2473->timer = v2490;
  int * v2480 = v2473->regs;
  int v2481 = v2480[12];
  int v2482 = v2480[10];
  int v2493 = v2481 & v2482;
  v2480[12] = v2493;
  struct StateT * v2484 = slot_44(v2473);
  return v2484;
}

struct StateT * slot_6(struct StateT * v469) {
  int * v470 = v469->saved_regs;
  int * v471 = v469->regs;
  int v472 = v471[14];
  v470[14] = v472;
  int v474 = v469->timer;
  int v484 = v474 + 1;
  v469->timer = v484;
  int * v476 = v469->regs;
  v476[14] = 0;
  struct StateT * v478 = slot_7(v469);
  return v478;
}

struct StateT * slot_29(struct StateT * v1617) {
  int v1618 = v1617->timer;
  int v1728 = v1618 + 1;
  v1617->timer = v1728;
  int * v1620 = v1617->regs;
  int v1621 = v1620[10];
  int * v1622 = v1617->cache_tags;
  int v1732 = (((int)((unsigned int)((int)((unsigned int)v1621 >> 2)) >> 1)) & 1) * 2;
  int v1623 = v1622[v1732];
  int v1733 = ((((int)((unsigned int)((int)((unsigned int)v1621 >> 2)) >> 1)) & 1) * 2) + 1;
  int v1624 = v1622[v1733];
  int v1734 = 4 + ((((int)((unsigned int)((int)((unsigned int)v1621 >> 2)) >> 1)) & 3) * 2);
  int v1625 = v1622[v1734];
  int v1735 = (4 + ((((int)((unsigned int)((int)((unsigned int)v1621 >> 2)) >> 1)) & 3) * 2)) + 1;
  int v1626 = v1622[v1735];
  int v1627 = v1617->timer;
  int v1736 = v1627 + ((100 ^ (((~(((v1625 ^ ((int)((unsigned int)((int)((unsigned int)v1621 >> 2)) >> 1))) | (-(v1625 ^ ((int)((unsigned int)((int)((unsigned int)v1621 >> 2)) >> 1))))) >> 31)) | (~(((v1626 ^ ((int)((unsigned int)((int)((unsigned int)v1621 >> 2)) >> 1))) | (-(v1626 ^ ((int)((unsigned int)((int)((unsigned int)v1621 >> 2)) >> 1))))) >> 31))) & 104)) ^ (((~(((v1623 ^ ((int)((unsigned int)((int)((unsigned int)v1621 >> 2)) >> 1))) | (-(v1623 ^ ((int)((unsigned int)((int)((unsigned int)v1621 >> 2)) >> 1))))) >> 31)) | (~(((v1624 ^ ((int)((unsigned int)((int)((unsigned int)v1621 >> 2)) >> 1))) | (-(v1624 ^ ((int)((unsigned int)((int)((unsigned int)v1621 >> 2)) >> 1))))) >> 31))) & (1 ^ (100 ^ (((~(((v1625 ^ ((int)((unsigned int)((int)((unsigned int)v1621 >> 2)) >> 1))) | (-(v1625 ^ ((int)((unsigned int)((int)((unsigned int)v1621 >> 2)) >> 1))))) >> 31)) | (~(((v1626 ^ ((int)((unsigned int)((int)((unsigned int)v1621 >> 2)) >> 1))) | (-(v1626 ^ ((int)((unsigned int)((int)((unsigned int)v1621 >> 2)) >> 1))))) >> 31))) & 104)))));
  v1617->timer = v1736;
  int * v1629 = v1617->cache_vals;
  bool v1737 = !(((~(((v1623 ^ ((int)((unsigned int)((int)((unsigned int)v1621 >> 2)) >> 1))) | (-(v1623 ^ ((int)((unsigned int)((int)((unsigned int)v1621 >> 2)) >> 1))))) >> 31)) | (~(((v1624 ^ ((int)((unsigned int)((int)((unsigned int)v1621 >> 2)) >> 1))) | (-(v1624 ^ ((int)((unsigned int)((int)((unsigned int)v1621 >> 2)) >> 1))))) >> 31))) == 0);
  int v1722;
  if (v1737) {
    int * v1630 = v1617->cache_age;
    int v1739 = ((((int)((unsigned int)((int)((unsigned int)v1621 >> 2)) >> 1)) & 1) * 2) + ((~(((v1624 ^ ((int)((unsigned int)((int)((unsigned int)v1621 >> 2)) >> 1))) | (-(v1624 ^ ((int)((unsigned int)((int)((unsigned int)v1621 >> 2)) >> 1))))) >> 31)) & 1);
    int v1631 = v1630[v1739];
    int v1632 = v1630[v1732];
    int v1740 = v1632 + ((int)((unsigned int)(v1632 - v1631) >> 31));
    v1630[v1732] = v1740;
    int * v1634 = v1617->cache_age;
    int v1635 = v1634[v1733];
    int v1742 = v1635 + ((int)((unsigned int)(v1635 - v1631) >> 31));
    v1634[v1733] = v1742;
    int * v1637 = v1617->cache_age;
    v1637[v1739] = 0;
    v1722 = v1739;
  } else {
    int * v1640 = v1617->cache_age;
    int v1746 = (((int)((unsigned int)((int)((unsigned int)v1621 >> 2)) >> 1)) & 1) * 2;
    int v1641 = v1640[v1746];
    int * v1642 = v1617->cache_tags;
    int v1643 = v1642[v1746];
    int v1644 = v1640[v1733];
    int v1645 = v1642[v1733];
    bool v1748 = !(((~(((v1625 ^ ((int)((unsigned int)((int)((unsigned int)v1621 >> 2)) >> 1))) | (-(v1625 ^ ((int)((unsigned int)((int)((unsigned int)v1621 >> 2)) >> 1))))) >> 31)) | (~(((v1626 ^ ((int)((unsigned int)((int)((unsigned int)v1621 >> 2)) >> 1))) | (-(v1626 ^ ((int)((unsigned int)((int)((unsigned int)v1621 >> 2)) >> 1))))) >> 31))) == 0);
    int v1699;
    if (v1748) {
      int * v1646 = v1617->cache_age;
      int v1750 = (4 + ((((int)((unsigned int)((int)((unsigned int)v1621 >> 2)) >> 1)) & 3) * 2)) + ((~(((v1626 ^ ((int)((unsigned int)((int)((unsigned int)v1621 >> 2)) >> 1))) | (-(v1626 ^ ((int)((unsigned int)((int)((unsigned int)v1621 >> 2)) >> 1))))) >> 31)) & 1);
      int v1647 = v1646[v1750];
      int v1648 = v1646[v1734];
      int v1751 = v1648 + ((int)((unsigned int)(v1648 - v1647) >> 31));
      v1646[v1734] = v1751;
      int * v1650 = v1617->cache_age;
      int v1651 = v1650[v1735];
      int v1753 = v1651 + ((int)((unsigned int)(v1651 - v1647) >> 31));
      v1650[v1735] = v1753;
      int * v1653 = v1617->cache_age;
      v1653[v1750] = 0;
      v1699 = v1750;
    } else {
      int * v1656 = v1617->cache_age;
      int v1757 = 4 + ((((int)((unsigned int)((int)((unsigned int)v1621 >> 2)) >> 1)) & 3) * 2);
      int v1657 = v1656[v1757];
      int * v1658 = v1617->cache_tags;
      int v1659 = v1658[v1757];
      int v1660 = v1656[v1735];
      int v1661 = v1658[v1735];
      int * v1662 = v1617->cache_dirty;
      int v1760 = (4 + ((((int)((unsigned int)((int)((unsigned int)v1621 >> 2)) >> 1)) & 3) * 2)) + ((((v1657 + ((~(((v1659 ^ -1) | (-(v1659 ^ -1))) >> 31)) & 2)) - (v1660 + ((~(((v1661 ^ -1) | (-(v1661 ^ -1))) >> 31)) & 2))) >> 31) & 1);
      int v1663 = v1662[v1760];
      bool v1761 = !(v1663 == 0);
      if (v1761) {
        int * v1664 = v1617->cache_tags;
        int v1665 = v1664[v1760];
        int * v1666 = v1617->cache_vals;
        int v1764 = ((4 + ((((int)((unsigned int)((int)((unsigned int)v1621 >> 2)) >> 1)) & 3) * 2)) + ((((v1657 + ((~(((v1659 ^ -1) | (-(v1659 ^ -1))) >> 31)) & 2)) - (v1660 + ((~(((v1661 ^ -1) | (-(v1661 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
        int v1667 = v1666[v1764];
        int v1765 = (((4 + ((((int)((unsigned int)((int)((unsigned int)v1621 >> 2)) >> 1)) & 3) * 2)) + ((((v1657 + ((~(((v1659 ^ -1) | (-(v1659 ^ -1))) >> 31)) & 2)) - (v1660 + ((~(((v1661 ^ -1) | (-(v1661 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
        int v1668 = v1666[v1765];
        int * v1669 = v1617->mem;
        int v1767 = v1665 * 2;
        v1669[v1767] = v1667;
        int * v1671 = v1617->mem;
        int v1770 = (v1665 * 2) + 1;
        v1671[v1770] = v1668;
        ;
      } else {
        ;
      }
      int * v1676 = v1617->mem;
      int v1775 = ((int)((unsigned int)((int)((unsigned int)v1621 >> 2)) >> 1)) * 2;
      int v1677 = v1676[v1775];
      int v1776 = (((int)((unsigned int)((int)((unsigned int)v1621 >> 2)) >> 1)) * 2) + 1;
      int v1678 = v1676[v1776];
      int * v1679 = v1617->cache_vals;
      int v1778 = ((4 + ((((int)((unsigned int)((int)((unsigned int)v1621 >> 2)) >> 1)) & 3) * 2)) + ((((v1657 + ((~(((v1659 ^ -1) | (-(v1659 ^ -1))) >> 31)) & 2)) - (v1660 + ((~(((v1661 ^ -1) | (-(v1661 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
      v1679[v1778] = v1677;
      int * v1681 = v1617->cache_vals;
      int v1781 = (((4 + ((((int)((unsigned int)((int)((unsigned int)v1621 >> 2)) >> 1)) & 3) * 2)) + ((((v1657 + ((~(((v1659 ^ -1) | (-(v1659 ^ -1))) >> 31)) & 2)) - (v1660 + ((~(((v1661 ^ -1) | (-(v1661 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
      v1681[v1781] = v1678;
      int * v1683 = v1617->cache_tags;
      int v1784 = (int)((unsigned int)((int)((unsigned int)v1621 >> 2)) >> 1);
      v1683[v1760] = v1784;
      int * v1685 = v1617->cache_dirty;
      v1685[v1760] = 0;
      int * v1687 = v1617->cache_age;
      v1687[v1760] = 1;
      int * v1689 = v1617->cache_age;
      int v1690 = v1689[v1760];
      int v1691 = v1689[v1734];
      int v1790 = v1691 + ((int)((unsigned int)(v1691 - v1690) >> 31));
      v1689[v1734] = v1790;
      int * v1693 = v1617->cache_age;
      int v1694 = v1693[v1735];
      int v1792 = v1694 + ((int)((unsigned int)(v1694 - v1690) >> 31));
      v1693[v1735] = v1792;
      int * v1696 = v1617->cache_age;
      v1696[v1760] = 0;
      v1699 = v1760;
    }
    int * v1700 = v1617->cache_vals;
    int v1795 = v1699 * 2;
    int v1701 = v1700[v1795];
    int v1796 = (v1699 * 2) + 1;
    int v1702 = v1700[v1796];
    int v1797 = (((((int)((unsigned int)((int)((unsigned int)v1621 >> 2)) >> 1)) & 1) * 2) + ((((v1641 + ((~(((v1643 ^ -1) | (-(v1643 ^ -1))) >> 31)) & 2)) - (v1644 + ((~(((v1645 ^ -1) | (-(v1645 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
    v1700[v1797] = v1701;
    int * v1704 = v1617->cache_vals;
    int v1800 = ((((((int)((unsigned int)((int)((unsigned int)v1621 >> 2)) >> 1)) & 1) * 2) + ((((v1641 + ((~(((v1643 ^ -1) | (-(v1643 ^ -1))) >> 31)) & 2)) - (v1644 + ((~(((v1645 ^ -1) | (-(v1645 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
    v1704[v1800] = v1702;
    int * v1706 = v1617->cache_tags;
    int v1803 = ((((int)((unsigned int)((int)((unsigned int)v1621 >> 2)) >> 1)) & 1) * 2) + ((((v1641 + ((~(((v1643 ^ -1) | (-(v1643 ^ -1))) >> 31)) & 2)) - (v1644 + ((~(((v1645 ^ -1) | (-(v1645 ^ -1))) >> 31)) & 2))) >> 31) & 1);
    int v1804 = (int)((unsigned int)((int)((unsigned int)v1621 >> 2)) >> 1);
    v1706[v1803] = v1804;
    int * v1708 = v1617->cache_dirty;
    v1708[v1803] = 0;
    int * v1710 = v1617->cache_age;
    v1710[v1803] = 1;
    int * v1712 = v1617->cache_age;
    int v1713 = v1712[v1803];
    int v1714 = v1712[v1732];
    int v1810 = v1714 + ((int)((unsigned int)(v1714 - v1713) >> 31));
    v1712[v1732] = v1810;
    int * v1716 = v1617->cache_age;
    int v1717 = v1716[v1733];
    int v1812 = v1717 + ((int)((unsigned int)(v1717 - v1713) >> 31));
    v1716[v1733] = v1812;
    int * v1719 = v1617->cache_age;
    v1719[v1803] = 0;
    v1722 = v1803;
  }
  int v1815 = (v1722 * 2) + (((int)((unsigned int)v1621 >> 2)) & 1);
  int v1723 = v1629[v1815];
  int * v1724 = v1617->regs;
  v1724[10] = v1723;
  struct StateT * v1726 = slot_31(v1617);
  return v1726;
}

struct StateT * slot_25(struct StateT * v1267) {
  int v1268 = v1267->timer;
  int v1275 = v1268 + 1;
  v1267->timer = v1275;
  int * v1270 = v1267->regs;
  int v1271 = v1270[10];
  int v1278 = v1271 << 2;
  v1270[10] = v1278;
  struct StateT * v1273 = slot_27(v1267);
  return v1273;
}

struct StateT * slot_16(struct StateT * v827) {
  int * v828 = v827->saved_regs;
  int * v829 = v827->regs;
  int v830 = v829[13];
  v828[13] = v830;
  int v832 = v827->timer;
  int v843 = v832 + 1;
  v827->timer = v843;
  int * v834 = v827->regs;
  int v835 = v834[13];
  int v845 = v835 + -1;
  v834[13] = v845;
  struct StateT * v837 = slot_17(v827);
  return v837;
}

struct StateT * slot_23(struct StateT * v1236) {
  int * v1237 = v1236->saved_regs;
  int v1238 = v1237[10];
  int * v1239 = v1236->regs;
  int v1240 = v1239[11];
  bool v1257 = (v1238 ^ -2147483648) < (v1240 ^ -2147483648);
  struct StateT * v1251;
  if (v1257) {
    int v1241 = v1236->timer;
    int v1258 = v1241 + 15;
    v1236->timer = v1258;
    int * v1243 = v1236->saved_regs;
    int v1244 = v1243[10];
    int * v1245 = v1236->regs;
    v1245[10] = v1244;
    struct StateT * v1247 = slot_25(v1236);
    v1251 = v1247;
  } else {
    struct StateT * v1249 = slot_26(v1236);
    v1251 = v1249;
  }
  return v1251;
}

struct StateT * slot_5(struct StateT * v266) {
  int v267 = v266->timer;
  int v377 = v267 + 1;
  v266->timer = v377;
  int * v269 = v266->regs;
  int v270 = v269[12];
  int * v271 = v266->cache_tags;
  int v381 = (((int)((unsigned int)((int)((unsigned int)(v270 + 68) >> 2)) >> 1)) & 1) * 2;
  int v272 = v271[v381];
  int v382 = ((((int)((unsigned int)((int)((unsigned int)(v270 + 68) >> 2)) >> 1)) & 1) * 2) + 1;
  int v273 = v271[v382];
  int v383 = 4 + ((((int)((unsigned int)((int)((unsigned int)(v270 + 68) >> 2)) >> 1)) & 3) * 2);
  int v274 = v271[v383];
  int v384 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v270 + 68) >> 2)) >> 1)) & 3) * 2)) + 1;
  int v275 = v271[v384];
  int v276 = v266->timer;
  int v385 = v276 + ((100 ^ (((~(((v274 ^ ((int)((unsigned int)((int)((unsigned int)(v270 + 68) >> 2)) >> 1))) | (-(v274 ^ ((int)((unsigned int)((int)((unsigned int)(v270 + 68) >> 2)) >> 1))))) >> 31)) | (~(((v275 ^ ((int)((unsigned int)((int)((unsigned int)(v270 + 68) >> 2)) >> 1))) | (-(v275 ^ ((int)((unsigned int)((int)((unsigned int)(v270 + 68) >> 2)) >> 1))))) >> 31))) & 104)) ^ (((~(((v272 ^ ((int)((unsigned int)((int)((unsigned int)(v270 + 68) >> 2)) >> 1))) | (-(v272 ^ ((int)((unsigned int)((int)((unsigned int)(v270 + 68) >> 2)) >> 1))))) >> 31)) | (~(((v273 ^ ((int)((unsigned int)((int)((unsigned int)(v270 + 68) >> 2)) >> 1))) | (-(v273 ^ ((int)((unsigned int)((int)((unsigned int)(v270 + 68) >> 2)) >> 1))))) >> 31))) & (1 ^ (100 ^ (((~(((v274 ^ ((int)((unsigned int)((int)((unsigned int)(v270 + 68) >> 2)) >> 1))) | (-(v274 ^ ((int)((unsigned int)((int)((unsigned int)(v270 + 68) >> 2)) >> 1))))) >> 31)) | (~(((v275 ^ ((int)((unsigned int)((int)((unsigned int)(v270 + 68) >> 2)) >> 1))) | (-(v275 ^ ((int)((unsigned int)((int)((unsigned int)(v270 + 68) >> 2)) >> 1))))) >> 31))) & 104)))));
  v266->timer = v385;
  int * v278 = v266->cache_vals;
  bool v386 = !(((~(((v272 ^ ((int)((unsigned int)((int)((unsigned int)(v270 + 68) >> 2)) >> 1))) | (-(v272 ^ ((int)((unsigned int)((int)((unsigned int)(v270 + 68) >> 2)) >> 1))))) >> 31)) | (~(((v273 ^ ((int)((unsigned int)((int)((unsigned int)(v270 + 68) >> 2)) >> 1))) | (-(v273 ^ ((int)((unsigned int)((int)((unsigned int)(v270 + 68) >> 2)) >> 1))))) >> 31))) == 0);
  int v371;
  if (v386) {
    int * v279 = v266->cache_age;
    int v388 = ((((int)((unsigned int)((int)((unsigned int)(v270 + 68) >> 2)) >> 1)) & 1) * 2) + ((~(((v273 ^ ((int)((unsigned int)((int)((unsigned int)(v270 + 68) >> 2)) >> 1))) | (-(v273 ^ ((int)((unsigned int)((int)((unsigned int)(v270 + 68) >> 2)) >> 1))))) >> 31)) & 1);
    int v280 = v279[v388];
    int v281 = v279[v381];
    int v389 = v281 + ((int)((unsigned int)(v281 - v280) >> 31));
    v279[v381] = v389;
    int * v283 = v266->cache_age;
    int v284 = v283[v382];
    int v391 = v284 + ((int)((unsigned int)(v284 - v280) >> 31));
    v283[v382] = v391;
    int * v286 = v266->cache_age;
    v286[v388] = 0;
    v371 = v388;
  } else {
    int * v289 = v266->cache_age;
    int v395 = (((int)((unsigned int)((int)((unsigned int)(v270 + 68) >> 2)) >> 1)) & 1) * 2;
    int v290 = v289[v395];
    int * v291 = v266->cache_tags;
    int v292 = v291[v395];
    int v293 = v289[v382];
    int v294 = v291[v382];
    bool v397 = !(((~(((v274 ^ ((int)((unsigned int)((int)((unsigned int)(v270 + 68) >> 2)) >> 1))) | (-(v274 ^ ((int)((unsigned int)((int)((unsigned int)(v270 + 68) >> 2)) >> 1))))) >> 31)) | (~(((v275 ^ ((int)((unsigned int)((int)((unsigned int)(v270 + 68) >> 2)) >> 1))) | (-(v275 ^ ((int)((unsigned int)((int)((unsigned int)(v270 + 68) >> 2)) >> 1))))) >> 31))) == 0);
    int v348;
    if (v397) {
      int * v295 = v266->cache_age;
      int v399 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v270 + 68) >> 2)) >> 1)) & 3) * 2)) + ((~(((v275 ^ ((int)((unsigned int)((int)((unsigned int)(v270 + 68) >> 2)) >> 1))) | (-(v275 ^ ((int)((unsigned int)((int)((unsigned int)(v270 + 68) >> 2)) >> 1))))) >> 31)) & 1);
      int v296 = v295[v399];
      int v297 = v295[v383];
      int v400 = v297 + ((int)((unsigned int)(v297 - v296) >> 31));
      v295[v383] = v400;
      int * v299 = v266->cache_age;
      int v300 = v299[v384];
      int v402 = v300 + ((int)((unsigned int)(v300 - v296) >> 31));
      v299[v384] = v402;
      int * v302 = v266->cache_age;
      v302[v399] = 0;
      v348 = v399;
    } else {
      int * v305 = v266->cache_age;
      int v406 = 4 + ((((int)((unsigned int)((int)((unsigned int)(v270 + 68) >> 2)) >> 1)) & 3) * 2);
      int v306 = v305[v406];
      int * v307 = v266->cache_tags;
      int v308 = v307[v406];
      int v309 = v305[v384];
      int v310 = v307[v384];
      int * v311 = v266->cache_dirty;
      int v409 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v270 + 68) >> 2)) >> 1)) & 3) * 2)) + ((((v306 + ((~(((v308 ^ -1) | (-(v308 ^ -1))) >> 31)) & 2)) - (v309 + ((~(((v310 ^ -1) | (-(v310 ^ -1))) >> 31)) & 2))) >> 31) & 1);
      int v312 = v311[v409];
      bool v410 = !(v312 == 0);
      if (v410) {
        int * v313 = v266->cache_tags;
        int v314 = v313[v409];
        int * v315 = v266->cache_vals;
        int v413 = ((4 + ((((int)((unsigned int)((int)((unsigned int)(v270 + 68) >> 2)) >> 1)) & 3) * 2)) + ((((v306 + ((~(((v308 ^ -1) | (-(v308 ^ -1))) >> 31)) & 2)) - (v309 + ((~(((v310 ^ -1) | (-(v310 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
        int v316 = v315[v413];
        int v414 = (((4 + ((((int)((unsigned int)((int)((unsigned int)(v270 + 68) >> 2)) >> 1)) & 3) * 2)) + ((((v306 + ((~(((v308 ^ -1) | (-(v308 ^ -1))) >> 31)) & 2)) - (v309 + ((~(((v310 ^ -1) | (-(v310 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
        int v317 = v315[v414];
        int * v318 = v266->mem;
        int v416 = v314 * 2;
        v318[v416] = v316;
        int * v320 = v266->mem;
        int v419 = (v314 * 2) + 1;
        v320[v419] = v317;
        ;
      } else {
        ;
      }
      int * v325 = v266->mem;
      int v424 = ((int)((unsigned int)((int)((unsigned int)(v270 + 68) >> 2)) >> 1)) * 2;
      int v326 = v325[v424];
      int v425 = (((int)((unsigned int)((int)((unsigned int)(v270 + 68) >> 2)) >> 1)) * 2) + 1;
      int v327 = v325[v425];
      int * v328 = v266->cache_vals;
      int v427 = ((4 + ((((int)((unsigned int)((int)((unsigned int)(v270 + 68) >> 2)) >> 1)) & 3) * 2)) + ((((v306 + ((~(((v308 ^ -1) | (-(v308 ^ -1))) >> 31)) & 2)) - (v309 + ((~(((v310 ^ -1) | (-(v310 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
      v328[v427] = v326;
      int * v330 = v266->cache_vals;
      int v430 = (((4 + ((((int)((unsigned int)((int)((unsigned int)(v270 + 68) >> 2)) >> 1)) & 3) * 2)) + ((((v306 + ((~(((v308 ^ -1) | (-(v308 ^ -1))) >> 31)) & 2)) - (v309 + ((~(((v310 ^ -1) | (-(v310 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
      v330[v430] = v327;
      int * v332 = v266->cache_tags;
      int v433 = (int)((unsigned int)((int)((unsigned int)(v270 + 68) >> 2)) >> 1);
      v332[v409] = v433;
      int * v334 = v266->cache_dirty;
      v334[v409] = 0;
      int * v336 = v266->cache_age;
      v336[v409] = 1;
      int * v338 = v266->cache_age;
      int v339 = v338[v409];
      int v340 = v338[v383];
      int v439 = v340 + ((int)((unsigned int)(v340 - v339) >> 31));
      v338[v383] = v439;
      int * v342 = v266->cache_age;
      int v343 = v342[v384];
      int v441 = v343 + ((int)((unsigned int)(v343 - v339) >> 31));
      v342[v384] = v441;
      int * v345 = v266->cache_age;
      v345[v409] = 0;
      v348 = v409;
    }
    int * v349 = v266->cache_vals;
    int v444 = v348 * 2;
    int v350 = v349[v444];
    int v445 = (v348 * 2) + 1;
    int v351 = v349[v445];
    int v446 = (((((int)((unsigned int)((int)((unsigned int)(v270 + 68) >> 2)) >> 1)) & 1) * 2) + ((((v290 + ((~(((v292 ^ -1) | (-(v292 ^ -1))) >> 31)) & 2)) - (v293 + ((~(((v294 ^ -1) | (-(v294 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
    v349[v446] = v350;
    int * v353 = v266->cache_vals;
    int v449 = ((((((int)((unsigned int)((int)((unsigned int)(v270 + 68) >> 2)) >> 1)) & 1) * 2) + ((((v290 + ((~(((v292 ^ -1) | (-(v292 ^ -1))) >> 31)) & 2)) - (v293 + ((~(((v294 ^ -1) | (-(v294 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
    v353[v449] = v351;
    int * v355 = v266->cache_tags;
    int v452 = ((((int)((unsigned int)((int)((unsigned int)(v270 + 68) >> 2)) >> 1)) & 1) * 2) + ((((v290 + ((~(((v292 ^ -1) | (-(v292 ^ -1))) >> 31)) & 2)) - (v293 + ((~(((v294 ^ -1) | (-(v294 ^ -1))) >> 31)) & 2))) >> 31) & 1);
    int v453 = (int)((unsigned int)((int)((unsigned int)(v270 + 68) >> 2)) >> 1);
    v355[v452] = v453;
    int * v357 = v266->cache_dirty;
    v357[v452] = 0;
    int * v359 = v266->cache_age;
    v359[v452] = 1;
    int * v361 = v266->cache_age;
    int v362 = v361[v452];
    int v363 = v361[v381];
    int v459 = v363 + ((int)((unsigned int)(v363 - v362) >> 31));
    v361[v381] = v459;
    int * v365 = v266->cache_age;
    int v366 = v365[v382];
    int v461 = v366 + ((int)((unsigned int)(v366 - v362) >> 31));
    v365[v382] = v461;
    int * v368 = v266->cache_age;
    v368[v452] = 0;
    v371 = v452;
  }
  int v464 = (v371 * 2) + (((int)((unsigned int)(v270 + 68) >> 2)) & 1);
  int v372 = v278[v464];
  int * v373 = v266->regs;
  v373[12] = v372;
  struct StateT * v375 = slot_6(v266);
  return v375;
}

struct StateT * slot_2(struct StateT * v218) {
  int v219 = v218->timer;
  int v223 = v219 + 1;
  v218->timer = v223;
  struct StateT * v221 = slot_3(v218);
  return v221;
}

struct StateT * slot_7(struct StateT * v489) {
  int v490 = v489->timer;
  int v497 = v490 + 1;
  v489->timer = v497;
  int * v492 = v489->regs;
  int v493 = v492[14];
  int v500 = v493 + 72;
  v492[14] = v500;
  struct StateT * v495 = slot_8(v489);
  return v495;
}

struct StateT * slot_21(struct StateT * v1211) {
  int * v1212 = v1211->saved_regs;
  int * v1213 = v1211->regs;
  int v1214 = v1213[10];
  v1212[10] = v1214;
  int v1216 = v1211->timer;
  int v1226 = v1216 + 1;
  v1211->timer = v1226;
  int * v1218 = v1211->regs;
  v1218[10] = 0;
  struct StateT * v1220 = slot_23(v1211);
  return v1220;
}

struct StateT * slot_31(struct StateT * v1820) {
  int v1821 = v1820->timer;
  int v1829 = v1821 + 1;
  v1820->timer = v1829;
  int * v1823 = v1820->regs;
  int v1824 = v1823[12];
  int v1825 = v1823[10];
  int v1833 = v1824 & v1825;
  v1823[12] = v1833;
  struct StateT * v1827 = slot_32(v1820);
  return v1827;
}

struct StateT * slot_3(struct StateT * v226) {
  int * v227 = v226->saved_regs;
  int * v228 = v226->regs;
  int v229 = v228[13];
  v227[13] = v229;
  int v231 = v226->timer;
  int v241 = v231 + 1;
  v226->timer = v241;
  int * v233 = v226->regs;
  v233[13] = 0;
  struct StateT * v235 = slot_4(v226);
  return v235;
}

struct StateT * slot_45(struct StateT * v2535) {
  int v2536 = v2535->timer;
  int v2542 = v2536 + 1;
  v2535->timer = v2542;
  int * v2538 = v2535->regs;
  v2538[10] = 0;
  struct StateT * v2540 = slot_26(v2535);
  return v2540;
}

struct StateT * slot_26(struct StateT * v1281) {
  int v1282 = v1281->timer;
  int v1452 = v1282 + 1;
  v1281->timer = v1452;
  int * v1284 = v1281->regs;
  int v1285 = v1284[10];
  int v1286 = v1284[12];
  int * v1287 = v1281->cache_tags;
  int v1457 = (((int)((unsigned int)((int)((unsigned int)(v1285 + 68) >> 2)) >> 1)) & 1) * 2;
  int v1288 = v1287[v1457];
  int v1458 = ((((int)((unsigned int)((int)((unsigned int)(v1285 + 68) >> 2)) >> 1)) & 1) * 2) + 1;
  int v1289 = v1287[v1458];
  int v1459 = 4 + ((((int)((unsigned int)((int)((unsigned int)(v1285 + 68) >> 2)) >> 1)) & 3) * 2);
  int v1290 = v1287[v1459];
  int v1460 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v1285 + 68) >> 2)) >> 1)) & 3) * 2)) + 1;
  int v1291 = v1287[v1460];
  int v1292 = v1281->timer;
  int v1461 = v1292 + ((100 ^ (((~(((v1290 ^ ((int)((unsigned int)((int)((unsigned int)(v1285 + 68) >> 2)) >> 1))) | (-(v1290 ^ ((int)((unsigned int)((int)((unsigned int)(v1285 + 68) >> 2)) >> 1))))) >> 31)) | (~(((v1291 ^ ((int)((unsigned int)((int)((unsigned int)(v1285 + 68) >> 2)) >> 1))) | (-(v1291 ^ ((int)((unsigned int)((int)((unsigned int)(v1285 + 68) >> 2)) >> 1))))) >> 31))) & 104)) ^ (((~(((v1288 ^ ((int)((unsigned int)((int)((unsigned int)(v1285 + 68) >> 2)) >> 1))) | (-(v1288 ^ ((int)((unsigned int)((int)((unsigned int)(v1285 + 68) >> 2)) >> 1))))) >> 31)) | (~(((v1289 ^ ((int)((unsigned int)((int)((unsigned int)(v1285 + 68) >> 2)) >> 1))) | (-(v1289 ^ ((int)((unsigned int)((int)((unsigned int)(v1285 + 68) >> 2)) >> 1))))) >> 31))) & (1 ^ (100 ^ (((~(((v1290 ^ ((int)((unsigned int)((int)((unsigned int)(v1285 + 68) >> 2)) >> 1))) | (-(v1290 ^ ((int)((unsigned int)((int)((unsigned int)(v1285 + 68) >> 2)) >> 1))))) >> 31)) | (~(((v1291 ^ ((int)((unsigned int)((int)((unsigned int)(v1285 + 68) >> 2)) >> 1))) | (-(v1291 ^ ((int)((unsigned int)((int)((unsigned int)(v1285 + 68) >> 2)) >> 1))))) >> 31))) & 104)))));
  v1281->timer = v1461;
  bool v1462 = !(((~(((v1288 ^ ((int)((unsigned int)((int)((unsigned int)(v1285 + 68) >> 2)) >> 1))) | (-(v1288 ^ ((int)((unsigned int)((int)((unsigned int)(v1285 + 68) >> 2)) >> 1))))) >> 31)) | (~(((v1289 ^ ((int)((unsigned int)((int)((unsigned int)(v1285 + 68) >> 2)) >> 1))) | (-(v1289 ^ ((int)((unsigned int)((int)((unsigned int)(v1285 + 68) >> 2)) >> 1))))) >> 31))) == 0);
  int v1386;
  if (v1462) {
    int * v1294 = v1281->cache_age;
    int v1464 = ((((int)((unsigned int)((int)((unsigned int)(v1285 + 68) >> 2)) >> 1)) & 1) * 2) + ((~(((v1289 ^ ((int)((unsigned int)((int)((unsigned int)(v1285 + 68) >> 2)) >> 1))) | (-(v1289 ^ ((int)((unsigned int)((int)((unsigned int)(v1285 + 68) >> 2)) >> 1))))) >> 31)) & 1);
    int v1295 = v1294[v1464];
    int v1296 = v1294[v1457];
    int v1465 = v1296 + ((int)((unsigned int)(v1296 - v1295) >> 31));
    v1294[v1457] = v1465;
    int * v1298 = v1281->cache_age;
    int v1299 = v1298[v1458];
    int v1467 = v1299 + ((int)((unsigned int)(v1299 - v1295) >> 31));
    v1298[v1458] = v1467;
    int * v1301 = v1281->cache_age;
    v1301[v1464] = 0;
    v1386 = v1464;
  } else {
    int * v1304 = v1281->cache_age;
    int v1471 = (((int)((unsigned int)((int)((unsigned int)(v1285 + 68) >> 2)) >> 1)) & 1) * 2;
    int v1305 = v1304[v1471];
    int * v1306 = v1281->cache_tags;
    int v1307 = v1306[v1471];
    int v1308 = v1304[v1458];
    int v1309 = v1306[v1458];
    bool v1473 = !(((~(((v1290 ^ ((int)((unsigned int)((int)((unsigned int)(v1285 + 68) >> 2)) >> 1))) | (-(v1290 ^ ((int)((unsigned int)((int)((unsigned int)(v1285 + 68) >> 2)) >> 1))))) >> 31)) | (~(((v1291 ^ ((int)((unsigned int)((int)((unsigned int)(v1285 + 68) >> 2)) >> 1))) | (-(v1291 ^ ((int)((unsigned int)((int)((unsigned int)(v1285 + 68) >> 2)) >> 1))))) >> 31))) == 0);
    int v1363;
    if (v1473) {
      int * v1310 = v1281->cache_age;
      int v1475 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v1285 + 68) >> 2)) >> 1)) & 3) * 2)) + ((~(((v1291 ^ ((int)((unsigned int)((int)((unsigned int)(v1285 + 68) >> 2)) >> 1))) | (-(v1291 ^ ((int)((unsigned int)((int)((unsigned int)(v1285 + 68) >> 2)) >> 1))))) >> 31)) & 1);
      int v1311 = v1310[v1475];
      int v1312 = v1310[v1459];
      int v1476 = v1312 + ((int)((unsigned int)(v1312 - v1311) >> 31));
      v1310[v1459] = v1476;
      int * v1314 = v1281->cache_age;
      int v1315 = v1314[v1460];
      int v1478 = v1315 + ((int)((unsigned int)(v1315 - v1311) >> 31));
      v1314[v1460] = v1478;
      int * v1317 = v1281->cache_age;
      v1317[v1475] = 0;
      v1363 = v1475;
    } else {
      int * v1320 = v1281->cache_age;
      int v1482 = 4 + ((((int)((unsigned int)((int)((unsigned int)(v1285 + 68) >> 2)) >> 1)) & 3) * 2);
      int v1321 = v1320[v1482];
      int * v1322 = v1281->cache_tags;
      int v1323 = v1322[v1482];
      int v1324 = v1320[v1460];
      int v1325 = v1322[v1460];
      int * v1326 = v1281->cache_dirty;
      int v1485 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v1285 + 68) >> 2)) >> 1)) & 3) * 2)) + ((((v1321 + ((~(((v1323 ^ -1) | (-(v1323 ^ -1))) >> 31)) & 2)) - (v1324 + ((~(((v1325 ^ -1) | (-(v1325 ^ -1))) >> 31)) & 2))) >> 31) & 1);
      int v1327 = v1326[v1485];
      bool v1486 = !(v1327 == 0);
      if (v1486) {
        int * v1328 = v1281->cache_tags;
        int v1329 = v1328[v1485];
        int * v1330 = v1281->cache_vals;
        int v1489 = ((4 + ((((int)((unsigned int)((int)((unsigned int)(v1285 + 68) >> 2)) >> 1)) & 3) * 2)) + ((((v1321 + ((~(((v1323 ^ -1) | (-(v1323 ^ -1))) >> 31)) & 2)) - (v1324 + ((~(((v1325 ^ -1) | (-(v1325 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
        int v1331 = v1330[v1489];
        int v1490 = (((4 + ((((int)((unsigned int)((int)((unsigned int)(v1285 + 68) >> 2)) >> 1)) & 3) * 2)) + ((((v1321 + ((~(((v1323 ^ -1) | (-(v1323 ^ -1))) >> 31)) & 2)) - (v1324 + ((~(((v1325 ^ -1) | (-(v1325 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
        int v1332 = v1330[v1490];
        int * v1333 = v1281->mem;
        int v1492 = v1329 * 2;
        v1333[v1492] = v1331;
        int * v1335 = v1281->mem;
        int v1495 = (v1329 * 2) + 1;
        v1335[v1495] = v1332;
        ;
      } else {
        ;
      }
      int * v1340 = v1281->mem;
      int v1500 = ((int)((unsigned int)((int)((unsigned int)(v1285 + 68) >> 2)) >> 1)) * 2;
      int v1341 = v1340[v1500];
      int v1501 = (((int)((unsigned int)((int)((unsigned int)(v1285 + 68) >> 2)) >> 1)) * 2) + 1;
      int v1342 = v1340[v1501];
      int * v1343 = v1281->cache_vals;
      int v1503 = ((4 + ((((int)((unsigned int)((int)((unsigned int)(v1285 + 68) >> 2)) >> 1)) & 3) * 2)) + ((((v1321 + ((~(((v1323 ^ -1) | (-(v1323 ^ -1))) >> 31)) & 2)) - (v1324 + ((~(((v1325 ^ -1) | (-(v1325 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
      v1343[v1503] = v1341;
      int * v1345 = v1281->cache_vals;
      int v1506 = (((4 + ((((int)((unsigned int)((int)((unsigned int)(v1285 + 68) >> 2)) >> 1)) & 3) * 2)) + ((((v1321 + ((~(((v1323 ^ -1) | (-(v1323 ^ -1))) >> 31)) & 2)) - (v1324 + ((~(((v1325 ^ -1) | (-(v1325 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
      v1345[v1506] = v1342;
      int * v1347 = v1281->cache_tags;
      int v1509 = (int)((unsigned int)((int)((unsigned int)(v1285 + 68) >> 2)) >> 1);
      v1347[v1485] = v1509;
      int * v1349 = v1281->cache_dirty;
      v1349[v1485] = 0;
      int * v1351 = v1281->cache_age;
      v1351[v1485] = 1;
      int * v1353 = v1281->cache_age;
      int v1354 = v1353[v1485];
      int v1355 = v1353[v1459];
      int v1515 = v1355 + ((int)((unsigned int)(v1355 - v1354) >> 31));
      v1353[v1459] = v1515;
      int * v1357 = v1281->cache_age;
      int v1358 = v1357[v1460];
      int v1517 = v1358 + ((int)((unsigned int)(v1358 - v1354) >> 31));
      v1357[v1460] = v1517;
      int * v1360 = v1281->cache_age;
      v1360[v1485] = 0;
      v1363 = v1485;
    }
    int * v1364 = v1281->cache_vals;
    int v1520 = v1363 * 2;
    int v1365 = v1364[v1520];
    int v1521 = (v1363 * 2) + 1;
    int v1366 = v1364[v1521];
    int v1522 = (((((int)((unsigned int)((int)((unsigned int)(v1285 + 68) >> 2)) >> 1)) & 1) * 2) + ((((v1305 + ((~(((v1307 ^ -1) | (-(v1307 ^ -1))) >> 31)) & 2)) - (v1308 + ((~(((v1309 ^ -1) | (-(v1309 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
    v1364[v1522] = v1365;
    int * v1368 = v1281->cache_vals;
    int v1525 = ((((((int)((unsigned int)((int)((unsigned int)(v1285 + 68) >> 2)) >> 1)) & 1) * 2) + ((((v1305 + ((~(((v1307 ^ -1) | (-(v1307 ^ -1))) >> 31)) & 2)) - (v1308 + ((~(((v1309 ^ -1) | (-(v1309 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
    v1368[v1525] = v1366;
    int * v1370 = v1281->cache_tags;
    int v1528 = ((((int)((unsigned int)((int)((unsigned int)(v1285 + 68) >> 2)) >> 1)) & 1) * 2) + ((((v1305 + ((~(((v1307 ^ -1) | (-(v1307 ^ -1))) >> 31)) & 2)) - (v1308 + ((~(((v1309 ^ -1) | (-(v1309 ^ -1))) >> 31)) & 2))) >> 31) & 1);
    int v1529 = (int)((unsigned int)((int)((unsigned int)(v1285 + 68) >> 2)) >> 1);
    v1370[v1528] = v1529;
    int * v1372 = v1281->cache_dirty;
    v1372[v1528] = 0;
    int * v1374 = v1281->cache_age;
    v1374[v1528] = 1;
    int * v1376 = v1281->cache_age;
    int v1377 = v1376[v1528];
    int v1378 = v1376[v1457];
    int v1535 = v1378 + ((int)((unsigned int)(v1378 - v1377) >> 31));
    v1376[v1457] = v1535;
    int * v1380 = v1281->cache_age;
    int v1381 = v1380[v1458];
    int v1537 = v1381 + ((int)((unsigned int)(v1381 - v1377) >> 31));
    v1380[v1458] = v1537;
    int * v1383 = v1281->cache_age;
    v1383[v1528] = 0;
    v1386 = v1528;
  }
  int * v1387 = v1281->cache_vals;
  int v1540 = (v1386 * 2) + (((int)((unsigned int)(v1285 + 68) >> 2)) & 1);
  v1387[v1540] = v1286;
  int * v1389 = v1281->cache_tags;
  int v1390 = v1389[v1459];
  int v1391 = v1389[v1460];
  bool v1543 = !(((~(((v1390 ^ ((int)((unsigned int)((int)((unsigned int)(v1285 + 68) >> 2)) >> 1))) | (-(v1390 ^ ((int)((unsigned int)((int)((unsigned int)(v1285 + 68) >> 2)) >> 1))))) >> 31)) | (~(((v1391 ^ ((int)((unsigned int)((int)((unsigned int)(v1285 + 68) >> 2)) >> 1))) | (-(v1391 ^ ((int)((unsigned int)((int)((unsigned int)(v1285 + 68) >> 2)) >> 1))))) >> 31))) == 0);
  int v1445;
  if (v1543) {
    int * v1392 = v1281->cache_age;
    int v1545 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v1285 + 68) >> 2)) >> 1)) & 3) * 2)) + ((~(((v1391 ^ ((int)((unsigned int)((int)((unsigned int)(v1285 + 68) >> 2)) >> 1))) | (-(v1391 ^ ((int)((unsigned int)((int)((unsigned int)(v1285 + 68) >> 2)) >> 1))))) >> 31)) & 1);
    int v1393 = v1392[v1545];
    int v1394 = v1392[v1459];
    int v1546 = v1394 + ((int)((unsigned int)(v1394 - v1393) >> 31));
    v1392[v1459] = v1546;
    int * v1396 = v1281->cache_age;
    int v1397 = v1396[v1460];
    int v1548 = v1397 + ((int)((unsigned int)(v1397 - v1393) >> 31));
    v1396[v1460] = v1548;
    int * v1399 = v1281->cache_age;
    v1399[v1545] = 0;
    v1445 = v1545;
  } else {
    int * v1402 = v1281->cache_age;
    int v1552 = 4 + ((((int)((unsigned int)((int)((unsigned int)(v1285 + 68) >> 2)) >> 1)) & 3) * 2);
    int v1403 = v1402[v1552];
    int * v1404 = v1281->cache_tags;
    int v1405 = v1404[v1552];
    int v1406 = v1402[v1460];
    int v1407 = v1404[v1460];
    int * v1408 = v1281->cache_dirty;
    int v1555 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v1285 + 68) >> 2)) >> 1)) & 3) * 2)) + ((((v1403 + ((~(((v1405 ^ -1) | (-(v1405 ^ -1))) >> 31)) & 2)) - (v1406 + ((~(((v1407 ^ -1) | (-(v1407 ^ -1))) >> 31)) & 2))) >> 31) & 1);
    int v1409 = v1408[v1555];
    bool v1556 = !(v1409 == 0);
    if (v1556) {
      int * v1410 = v1281->cache_tags;
      int v1411 = v1410[v1555];
      int * v1412 = v1281->cache_vals;
      int v1559 = ((4 + ((((int)((unsigned int)((int)((unsigned int)(v1285 + 68) >> 2)) >> 1)) & 3) * 2)) + ((((v1403 + ((~(((v1405 ^ -1) | (-(v1405 ^ -1))) >> 31)) & 2)) - (v1406 + ((~(((v1407 ^ -1) | (-(v1407 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
      int v1413 = v1412[v1559];
      int v1560 = (((4 + ((((int)((unsigned int)((int)((unsigned int)(v1285 + 68) >> 2)) >> 1)) & 3) * 2)) + ((((v1403 + ((~(((v1405 ^ -1) | (-(v1405 ^ -1))) >> 31)) & 2)) - (v1406 + ((~(((v1407 ^ -1) | (-(v1407 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
      int v1414 = v1412[v1560];
      int * v1415 = v1281->mem;
      int v1562 = v1411 * 2;
      v1415[v1562] = v1413;
      int * v1417 = v1281->mem;
      int v1565 = (v1411 * 2) + 1;
      v1417[v1565] = v1414;
      ;
    } else {
      ;
    }
    int * v1422 = v1281->mem;
    int v1570 = ((int)((unsigned int)((int)((unsigned int)(v1285 + 68) >> 2)) >> 1)) * 2;
    int v1423 = v1422[v1570];
    int v1571 = (((int)((unsigned int)((int)((unsigned int)(v1285 + 68) >> 2)) >> 1)) * 2) + 1;
    int v1424 = v1422[v1571];
    int * v1425 = v1281->cache_vals;
    int v1573 = ((4 + ((((int)((unsigned int)((int)((unsigned int)(v1285 + 68) >> 2)) >> 1)) & 3) * 2)) + ((((v1403 + ((~(((v1405 ^ -1) | (-(v1405 ^ -1))) >> 31)) & 2)) - (v1406 + ((~(((v1407 ^ -1) | (-(v1407 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
    v1425[v1573] = v1423;
    int * v1427 = v1281->cache_vals;
    int v1576 = (((4 + ((((int)((unsigned int)((int)((unsigned int)(v1285 + 68) >> 2)) >> 1)) & 3) * 2)) + ((((v1403 + ((~(((v1405 ^ -1) | (-(v1405 ^ -1))) >> 31)) & 2)) - (v1406 + ((~(((v1407 ^ -1) | (-(v1407 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
    v1427[v1576] = v1424;
    int * v1429 = v1281->cache_tags;
    int v1579 = (int)((unsigned int)((int)((unsigned int)(v1285 + 68) >> 2)) >> 1);
    v1429[v1555] = v1579;
    int * v1431 = v1281->cache_dirty;
    v1431[v1555] = 0;
    int * v1433 = v1281->cache_age;
    v1433[v1555] = 1;
    int * v1435 = v1281->cache_age;
    int v1436 = v1435[v1555];
    int v1437 = v1435[v1459];
    int v1585 = v1437 + ((int)((unsigned int)(v1437 - v1436) >> 31));
    v1435[v1459] = v1585;
    int * v1439 = v1281->cache_age;
    int v1440 = v1439[v1460];
    int v1587 = v1440 + ((int)((unsigned int)(v1440 - v1436) >> 31));
    v1439[v1460] = v1587;
    int * v1442 = v1281->cache_age;
    v1442[v1555] = 0;
    v1445 = v1555;
  }
  int * v1446 = v1281->cache_vals;
  int v1590 = (v1445 * 2) + (((int)((unsigned int)(v1285 + 68) >> 2)) & 1);
  v1446[v1590] = v1286;
  int * v1448 = v1281->cache_dirty;
  v1448[v1445] = 1;
  struct StateT * v1450 = slot_13(v1281);
  return v1450;
}

struct StateT * slot_10(struct StateT * v540) {
  int v541 = v540->timer;
  int v651 = v541 + 1;
  v540->timer = v651;
  int * v543 = v540->regs;
  int v544 = v543[10];
  int * v545 = v540->cache_tags;
  int v655 = (((int)((unsigned int)((int)((unsigned int)v544 >> 2)) >> 1)) & 1) * 2;
  int v546 = v545[v655];
  int v656 = ((((int)((unsigned int)((int)((unsigned int)v544 >> 2)) >> 1)) & 1) * 2) + 1;
  int v547 = v545[v656];
  int v657 = 4 + ((((int)((unsigned int)((int)((unsigned int)v544 >> 2)) >> 1)) & 3) * 2);
  int v548 = v545[v657];
  int v658 = (4 + ((((int)((unsigned int)((int)((unsigned int)v544 >> 2)) >> 1)) & 3) * 2)) + 1;
  int v549 = v545[v658];
  int v550 = v540->timer;
  int v659 = v550 + ((100 ^ (((~(((v548 ^ ((int)((unsigned int)((int)((unsigned int)v544 >> 2)) >> 1))) | (-(v548 ^ ((int)((unsigned int)((int)((unsigned int)v544 >> 2)) >> 1))))) >> 31)) | (~(((v549 ^ ((int)((unsigned int)((int)((unsigned int)v544 >> 2)) >> 1))) | (-(v549 ^ ((int)((unsigned int)((int)((unsigned int)v544 >> 2)) >> 1))))) >> 31))) & 104)) ^ (((~(((v546 ^ ((int)((unsigned int)((int)((unsigned int)v544 >> 2)) >> 1))) | (-(v546 ^ ((int)((unsigned int)((int)((unsigned int)v544 >> 2)) >> 1))))) >> 31)) | (~(((v547 ^ ((int)((unsigned int)((int)((unsigned int)v544 >> 2)) >> 1))) | (-(v547 ^ ((int)((unsigned int)((int)((unsigned int)v544 >> 2)) >> 1))))) >> 31))) & (1 ^ (100 ^ (((~(((v548 ^ ((int)((unsigned int)((int)((unsigned int)v544 >> 2)) >> 1))) | (-(v548 ^ ((int)((unsigned int)((int)((unsigned int)v544 >> 2)) >> 1))))) >> 31)) | (~(((v549 ^ ((int)((unsigned int)((int)((unsigned int)v544 >> 2)) >> 1))) | (-(v549 ^ ((int)((unsigned int)((int)((unsigned int)v544 >> 2)) >> 1))))) >> 31))) & 104)))));
  v540->timer = v659;
  int * v552 = v540->cache_vals;
  bool v660 = !(((~(((v546 ^ ((int)((unsigned int)((int)((unsigned int)v544 >> 2)) >> 1))) | (-(v546 ^ ((int)((unsigned int)((int)((unsigned int)v544 >> 2)) >> 1))))) >> 31)) | (~(((v547 ^ ((int)((unsigned int)((int)((unsigned int)v544 >> 2)) >> 1))) | (-(v547 ^ ((int)((unsigned int)((int)((unsigned int)v544 >> 2)) >> 1))))) >> 31))) == 0);
  int v645;
  if (v660) {
    int * v553 = v540->cache_age;
    int v662 = ((((int)((unsigned int)((int)((unsigned int)v544 >> 2)) >> 1)) & 1) * 2) + ((~(((v547 ^ ((int)((unsigned int)((int)((unsigned int)v544 >> 2)) >> 1))) | (-(v547 ^ ((int)((unsigned int)((int)((unsigned int)v544 >> 2)) >> 1))))) >> 31)) & 1);
    int v554 = v553[v662];
    int v555 = v553[v655];
    int v663 = v555 + ((int)((unsigned int)(v555 - v554) >> 31));
    v553[v655] = v663;
    int * v557 = v540->cache_age;
    int v558 = v557[v656];
    int v665 = v558 + ((int)((unsigned int)(v558 - v554) >> 31));
    v557[v656] = v665;
    int * v560 = v540->cache_age;
    v560[v662] = 0;
    v645 = v662;
  } else {
    int * v563 = v540->cache_age;
    int v669 = (((int)((unsigned int)((int)((unsigned int)v544 >> 2)) >> 1)) & 1) * 2;
    int v564 = v563[v669];
    int * v565 = v540->cache_tags;
    int v566 = v565[v669];
    int v567 = v563[v656];
    int v568 = v565[v656];
    bool v671 = !(((~(((v548 ^ ((int)((unsigned int)((int)((unsigned int)v544 >> 2)) >> 1))) | (-(v548 ^ ((int)((unsigned int)((int)((unsigned int)v544 >> 2)) >> 1))))) >> 31)) | (~(((v549 ^ ((int)((unsigned int)((int)((unsigned int)v544 >> 2)) >> 1))) | (-(v549 ^ ((int)((unsigned int)((int)((unsigned int)v544 >> 2)) >> 1))))) >> 31))) == 0);
    int v622;
    if (v671) {
      int * v569 = v540->cache_age;
      int v673 = (4 + ((((int)((unsigned int)((int)((unsigned int)v544 >> 2)) >> 1)) & 3) * 2)) + ((~(((v549 ^ ((int)((unsigned int)((int)((unsigned int)v544 >> 2)) >> 1))) | (-(v549 ^ ((int)((unsigned int)((int)((unsigned int)v544 >> 2)) >> 1))))) >> 31)) & 1);
      int v570 = v569[v673];
      int v571 = v569[v657];
      int v674 = v571 + ((int)((unsigned int)(v571 - v570) >> 31));
      v569[v657] = v674;
      int * v573 = v540->cache_age;
      int v574 = v573[v658];
      int v676 = v574 + ((int)((unsigned int)(v574 - v570) >> 31));
      v573[v658] = v676;
      int * v576 = v540->cache_age;
      v576[v673] = 0;
      v622 = v673;
    } else {
      int * v579 = v540->cache_age;
      int v680 = 4 + ((((int)((unsigned int)((int)((unsigned int)v544 >> 2)) >> 1)) & 3) * 2);
      int v580 = v579[v680];
      int * v581 = v540->cache_tags;
      int v582 = v581[v680];
      int v583 = v579[v658];
      int v584 = v581[v658];
      int * v585 = v540->cache_dirty;
      int v683 = (4 + ((((int)((unsigned int)((int)((unsigned int)v544 >> 2)) >> 1)) & 3) * 2)) + ((((v580 + ((~(((v582 ^ -1) | (-(v582 ^ -1))) >> 31)) & 2)) - (v583 + ((~(((v584 ^ -1) | (-(v584 ^ -1))) >> 31)) & 2))) >> 31) & 1);
      int v586 = v585[v683];
      bool v684 = !(v586 == 0);
      if (v684) {
        int * v587 = v540->cache_tags;
        int v588 = v587[v683];
        int * v589 = v540->cache_vals;
        int v687 = ((4 + ((((int)((unsigned int)((int)((unsigned int)v544 >> 2)) >> 1)) & 3) * 2)) + ((((v580 + ((~(((v582 ^ -1) | (-(v582 ^ -1))) >> 31)) & 2)) - (v583 + ((~(((v584 ^ -1) | (-(v584 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
        int v590 = v589[v687];
        int v688 = (((4 + ((((int)((unsigned int)((int)((unsigned int)v544 >> 2)) >> 1)) & 3) * 2)) + ((((v580 + ((~(((v582 ^ -1) | (-(v582 ^ -1))) >> 31)) & 2)) - (v583 + ((~(((v584 ^ -1) | (-(v584 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
        int v591 = v589[v688];
        int * v592 = v540->mem;
        int v690 = v588 * 2;
        v592[v690] = v590;
        int * v594 = v540->mem;
        int v693 = (v588 * 2) + 1;
        v594[v693] = v591;
        ;
      } else {
        ;
      }
      int * v599 = v540->mem;
      int v698 = ((int)((unsigned int)((int)((unsigned int)v544 >> 2)) >> 1)) * 2;
      int v600 = v599[v698];
      int v699 = (((int)((unsigned int)((int)((unsigned int)v544 >> 2)) >> 1)) * 2) + 1;
      int v601 = v599[v699];
      int * v602 = v540->cache_vals;
      int v701 = ((4 + ((((int)((unsigned int)((int)((unsigned int)v544 >> 2)) >> 1)) & 3) * 2)) + ((((v580 + ((~(((v582 ^ -1) | (-(v582 ^ -1))) >> 31)) & 2)) - (v583 + ((~(((v584 ^ -1) | (-(v584 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
      v602[v701] = v600;
      int * v604 = v540->cache_vals;
      int v704 = (((4 + ((((int)((unsigned int)((int)((unsigned int)v544 >> 2)) >> 1)) & 3) * 2)) + ((((v580 + ((~(((v582 ^ -1) | (-(v582 ^ -1))) >> 31)) & 2)) - (v583 + ((~(((v584 ^ -1) | (-(v584 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
      v604[v704] = v601;
      int * v606 = v540->cache_tags;
      int v707 = (int)((unsigned int)((int)((unsigned int)v544 >> 2)) >> 1);
      v606[v683] = v707;
      int * v608 = v540->cache_dirty;
      v608[v683] = 0;
      int * v610 = v540->cache_age;
      v610[v683] = 1;
      int * v612 = v540->cache_age;
      int v613 = v612[v683];
      int v614 = v612[v657];
      int v713 = v614 + ((int)((unsigned int)(v614 - v613) >> 31));
      v612[v657] = v713;
      int * v616 = v540->cache_age;
      int v617 = v616[v658];
      int v715 = v617 + ((int)((unsigned int)(v617 - v613) >> 31));
      v616[v658] = v715;
      int * v619 = v540->cache_age;
      v619[v683] = 0;
      v622 = v683;
    }
    int * v623 = v540->cache_vals;
    int v718 = v622 * 2;
    int v624 = v623[v718];
    int v719 = (v622 * 2) + 1;
    int v625 = v623[v719];
    int v720 = (((((int)((unsigned int)((int)((unsigned int)v544 >> 2)) >> 1)) & 1) * 2) + ((((v564 + ((~(((v566 ^ -1) | (-(v566 ^ -1))) >> 31)) & 2)) - (v567 + ((~(((v568 ^ -1) | (-(v568 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
    v623[v720] = v624;
    int * v627 = v540->cache_vals;
    int v723 = ((((((int)((unsigned int)((int)((unsigned int)v544 >> 2)) >> 1)) & 1) * 2) + ((((v564 + ((~(((v566 ^ -1) | (-(v566 ^ -1))) >> 31)) & 2)) - (v567 + ((~(((v568 ^ -1) | (-(v568 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
    v627[v723] = v625;
    int * v629 = v540->cache_tags;
    int v726 = ((((int)((unsigned int)((int)((unsigned int)v544 >> 2)) >> 1)) & 1) * 2) + ((((v564 + ((~(((v566 ^ -1) | (-(v566 ^ -1))) >> 31)) & 2)) - (v567 + ((~(((v568 ^ -1) | (-(v568 ^ -1))) >> 31)) & 2))) >> 31) & 1);
    int v727 = (int)((unsigned int)((int)((unsigned int)v544 >> 2)) >> 1);
    v629[v726] = v727;
    int * v631 = v540->cache_dirty;
    v631[v726] = 0;
    int * v633 = v540->cache_age;
    v633[v726] = 1;
    int * v635 = v540->cache_age;
    int v636 = v635[v726];
    int v637 = v635[v655];
    int v733 = v637 + ((int)((unsigned int)(v637 - v636) >> 31));
    v635[v655] = v733;
    int * v639 = v540->cache_age;
    int v640 = v639[v656];
    int v735 = v640 + ((int)((unsigned int)(v640 - v636) >> 31));
    v639[v656] = v735;
    int * v642 = v540->cache_age;
    v642[v726] = 0;
    v645 = v726;
  }
  int v738 = (v645 * 2) + (((int)((unsigned int)v544 >> 2)) & 1);
  int v646 = v552[v738];
  int * v647 = v540->regs;
  v647[10] = v646;
  struct StateT * v649 = slot_11(v540);
  return v649;
}

struct StateT * slot_1(struct StateT * v15) {
  int v16 = v15->timer;
  int v126 = v16 + 1;
  v15->timer = v126;
  int * v18 = v15->regs;
  int v19 = v18[11];
  int * v20 = v15->cache_tags;
  int v130 = (((int)((unsigned int)((int)((unsigned int)v19 >> 2)) >> 1)) & 1) * 2;
  int v21 = v20[v130];
  int v131 = ((((int)((unsigned int)((int)((unsigned int)v19 >> 2)) >> 1)) & 1) * 2) + 1;
  int v22 = v20[v131];
  int v132 = 4 + ((((int)((unsigned int)((int)((unsigned int)v19 >> 2)) >> 1)) & 3) * 2);
  int v23 = v20[v132];
  int v133 = (4 + ((((int)((unsigned int)((int)((unsigned int)v19 >> 2)) >> 1)) & 3) * 2)) + 1;
  int v24 = v20[v133];
  int v25 = v15->timer;
  int v134 = v25 + ((100 ^ (((~(((v23 ^ ((int)((unsigned int)((int)((unsigned int)v19 >> 2)) >> 1))) | (-(v23 ^ ((int)((unsigned int)((int)((unsigned int)v19 >> 2)) >> 1))))) >> 31)) | (~(((v24 ^ ((int)((unsigned int)((int)((unsigned int)v19 >> 2)) >> 1))) | (-(v24 ^ ((int)((unsigned int)((int)((unsigned int)v19 >> 2)) >> 1))))) >> 31))) & 104)) ^ (((~(((v21 ^ ((int)((unsigned int)((int)((unsigned int)v19 >> 2)) >> 1))) | (-(v21 ^ ((int)((unsigned int)((int)((unsigned int)v19 >> 2)) >> 1))))) >> 31)) | (~(((v22 ^ ((int)((unsigned int)((int)((unsigned int)v19 >> 2)) >> 1))) | (-(v22 ^ ((int)((unsigned int)((int)((unsigned int)v19 >> 2)) >> 1))))) >> 31))) & (1 ^ (100 ^ (((~(((v23 ^ ((int)((unsigned int)((int)((unsigned int)v19 >> 2)) >> 1))) | (-(v23 ^ ((int)((unsigned int)((int)((unsigned int)v19 >> 2)) >> 1))))) >> 31)) | (~(((v24 ^ ((int)((unsigned int)((int)((unsigned int)v19 >> 2)) >> 1))) | (-(v24 ^ ((int)((unsigned int)((int)((unsigned int)v19 >> 2)) >> 1))))) >> 31))) & 104)))));
  v15->timer = v134;
  int * v27 = v15->cache_vals;
  bool v135 = !(((~(((v21 ^ ((int)((unsigned int)((int)((unsigned int)v19 >> 2)) >> 1))) | (-(v21 ^ ((int)((unsigned int)((int)((unsigned int)v19 >> 2)) >> 1))))) >> 31)) | (~(((v22 ^ ((int)((unsigned int)((int)((unsigned int)v19 >> 2)) >> 1))) | (-(v22 ^ ((int)((unsigned int)((int)((unsigned int)v19 >> 2)) >> 1))))) >> 31))) == 0);
  int v120;
  if (v135) {
    int * v28 = v15->cache_age;
    int v137 = ((((int)((unsigned int)((int)((unsigned int)v19 >> 2)) >> 1)) & 1) * 2) + ((~(((v22 ^ ((int)((unsigned int)((int)((unsigned int)v19 >> 2)) >> 1))) | (-(v22 ^ ((int)((unsigned int)((int)((unsigned int)v19 >> 2)) >> 1))))) >> 31)) & 1);
    int v29 = v28[v137];
    int v30 = v28[v130];
    int v138 = v30 + ((int)((unsigned int)(v30 - v29) >> 31));
    v28[v130] = v138;
    int * v32 = v15->cache_age;
    int v33 = v32[v131];
    int v140 = v33 + ((int)((unsigned int)(v33 - v29) >> 31));
    v32[v131] = v140;
    int * v35 = v15->cache_age;
    v35[v137] = 0;
    v120 = v137;
  } else {
    int * v38 = v15->cache_age;
    int v144 = (((int)((unsigned int)((int)((unsigned int)v19 >> 2)) >> 1)) & 1) * 2;
    int v39 = v38[v144];
    int * v40 = v15->cache_tags;
    int v41 = v40[v144];
    int v42 = v38[v131];
    int v43 = v40[v131];
    bool v146 = !(((~(((v23 ^ ((int)((unsigned int)((int)((unsigned int)v19 >> 2)) >> 1))) | (-(v23 ^ ((int)((unsigned int)((int)((unsigned int)v19 >> 2)) >> 1))))) >> 31)) | (~(((v24 ^ ((int)((unsigned int)((int)((unsigned int)v19 >> 2)) >> 1))) | (-(v24 ^ ((int)((unsigned int)((int)((unsigned int)v19 >> 2)) >> 1))))) >> 31))) == 0);
    int v97;
    if (v146) {
      int * v44 = v15->cache_age;
      int v148 = (4 + ((((int)((unsigned int)((int)((unsigned int)v19 >> 2)) >> 1)) & 3) * 2)) + ((~(((v24 ^ ((int)((unsigned int)((int)((unsigned int)v19 >> 2)) >> 1))) | (-(v24 ^ ((int)((unsigned int)((int)((unsigned int)v19 >> 2)) >> 1))))) >> 31)) & 1);
      int v45 = v44[v148];
      int v46 = v44[v132];
      int v149 = v46 + ((int)((unsigned int)(v46 - v45) >> 31));
      v44[v132] = v149;
      int * v48 = v15->cache_age;
      int v49 = v48[v133];
      int v151 = v49 + ((int)((unsigned int)(v49 - v45) >> 31));
      v48[v133] = v151;
      int * v51 = v15->cache_age;
      v51[v148] = 0;
      v97 = v148;
    } else {
      int * v54 = v15->cache_age;
      int v155 = 4 + ((((int)((unsigned int)((int)((unsigned int)v19 >> 2)) >> 1)) & 3) * 2);
      int v55 = v54[v155];
      int * v56 = v15->cache_tags;
      int v57 = v56[v155];
      int v58 = v54[v133];
      int v59 = v56[v133];
      int * v60 = v15->cache_dirty;
      int v158 = (4 + ((((int)((unsigned int)((int)((unsigned int)v19 >> 2)) >> 1)) & 3) * 2)) + ((((v55 + ((~(((v57 ^ -1) | (-(v57 ^ -1))) >> 31)) & 2)) - (v58 + ((~(((v59 ^ -1) | (-(v59 ^ -1))) >> 31)) & 2))) >> 31) & 1);
      int v61 = v60[v158];
      bool v159 = !(v61 == 0);
      if (v159) {
        int * v62 = v15->cache_tags;
        int v63 = v62[v158];
        int * v64 = v15->cache_vals;
        int v162 = ((4 + ((((int)((unsigned int)((int)((unsigned int)v19 >> 2)) >> 1)) & 3) * 2)) + ((((v55 + ((~(((v57 ^ -1) | (-(v57 ^ -1))) >> 31)) & 2)) - (v58 + ((~(((v59 ^ -1) | (-(v59 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
        int v65 = v64[v162];
        int v163 = (((4 + ((((int)((unsigned int)((int)((unsigned int)v19 >> 2)) >> 1)) & 3) * 2)) + ((((v55 + ((~(((v57 ^ -1) | (-(v57 ^ -1))) >> 31)) & 2)) - (v58 + ((~(((v59 ^ -1) | (-(v59 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
        int v66 = v64[v163];
        int * v67 = v15->mem;
        int v165 = v63 * 2;
        v67[v165] = v65;
        int * v69 = v15->mem;
        int v168 = (v63 * 2) + 1;
        v69[v168] = v66;
        ;
      } else {
        ;
      }
      int * v74 = v15->mem;
      int v173 = ((int)((unsigned int)((int)((unsigned int)v19 >> 2)) >> 1)) * 2;
      int v75 = v74[v173];
      int v174 = (((int)((unsigned int)((int)((unsigned int)v19 >> 2)) >> 1)) * 2) + 1;
      int v76 = v74[v174];
      int * v77 = v15->cache_vals;
      int v176 = ((4 + ((((int)((unsigned int)((int)((unsigned int)v19 >> 2)) >> 1)) & 3) * 2)) + ((((v55 + ((~(((v57 ^ -1) | (-(v57 ^ -1))) >> 31)) & 2)) - (v58 + ((~(((v59 ^ -1) | (-(v59 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
      v77[v176] = v75;
      int * v79 = v15->cache_vals;
      int v179 = (((4 + ((((int)((unsigned int)((int)((unsigned int)v19 >> 2)) >> 1)) & 3) * 2)) + ((((v55 + ((~(((v57 ^ -1) | (-(v57 ^ -1))) >> 31)) & 2)) - (v58 + ((~(((v59 ^ -1) | (-(v59 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
      v79[v179] = v76;
      int * v81 = v15->cache_tags;
      int v182 = (int)((unsigned int)((int)((unsigned int)v19 >> 2)) >> 1);
      v81[v158] = v182;
      int * v83 = v15->cache_dirty;
      v83[v158] = 0;
      int * v85 = v15->cache_age;
      v85[v158] = 1;
      int * v87 = v15->cache_age;
      int v88 = v87[v158];
      int v89 = v87[v132];
      int v188 = v89 + ((int)((unsigned int)(v89 - v88) >> 31));
      v87[v132] = v188;
      int * v91 = v15->cache_age;
      int v92 = v91[v133];
      int v190 = v92 + ((int)((unsigned int)(v92 - v88) >> 31));
      v91[v133] = v190;
      int * v94 = v15->cache_age;
      v94[v158] = 0;
      v97 = v158;
    }
    int * v98 = v15->cache_vals;
    int v193 = v97 * 2;
    int v99 = v98[v193];
    int v194 = (v97 * 2) + 1;
    int v100 = v98[v194];
    int v195 = (((((int)((unsigned int)((int)((unsigned int)v19 >> 2)) >> 1)) & 1) * 2) + ((((v39 + ((~(((v41 ^ -1) | (-(v41 ^ -1))) >> 31)) & 2)) - (v42 + ((~(((v43 ^ -1) | (-(v43 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
    v98[v195] = v99;
    int * v102 = v15->cache_vals;
    int v198 = ((((((int)((unsigned int)((int)((unsigned int)v19 >> 2)) >> 1)) & 1) * 2) + ((((v39 + ((~(((v41 ^ -1) | (-(v41 ^ -1))) >> 31)) & 2)) - (v42 + ((~(((v43 ^ -1) | (-(v43 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
    v102[v198] = v100;
    int * v104 = v15->cache_tags;
    int v201 = ((((int)((unsigned int)((int)((unsigned int)v19 >> 2)) >> 1)) & 1) * 2) + ((((v39 + ((~(((v41 ^ -1) | (-(v41 ^ -1))) >> 31)) & 2)) - (v42 + ((~(((v43 ^ -1) | (-(v43 ^ -1))) >> 31)) & 2))) >> 31) & 1);
    int v202 = (int)((unsigned int)((int)((unsigned int)v19 >> 2)) >> 1);
    v104[v201] = v202;
    int * v106 = v15->cache_dirty;
    v106[v201] = 0;
    int * v108 = v15->cache_age;
    v108[v201] = 1;
    int * v110 = v15->cache_age;
    int v111 = v110[v201];
    int v112 = v110[v130];
    int v208 = v112 + ((int)((unsigned int)(v112 - v111) >> 31));
    v110[v130] = v208;
    int * v114 = v15->cache_age;
    int v115 = v114[v131];
    int v210 = v115 + ((int)((unsigned int)(v115 - v111) >> 31));
    v114[v131] = v210;
    int * v117 = v15->cache_age;
    v117[v201] = 0;
    v120 = v201;
  }
  int v213 = (v120 * 2) + (((int)((unsigned int)v19 >> 2)) & 1);
  int v121 = v27[v213];
  int * v122 = v15->regs;
  v122[11] = v121;
  struct StateT * v124 = slot_2(v15);
  return v124;
}

struct StateT * slot_19(struct StateT * v888) {
  int v889 = v888->timer;
  int v893 = v889 + 1;
  v888->timer = v893;
  struct StateT * v891 = slot_21(v888);
  return v891;
}

struct StateT * slot_13(struct StateT * v814) {
  int v815 = v814->timer;
  int v818 = v815 + 1;
  v814->timer = v818;
  return v814;
}

struct StateT * slot_38(struct StateT * v2228) {
  int * v2229 = v2228->saved_regs;
  int * v2230 = v2228->regs;
  int v2231 = v2230[10];
  v2229[10] = v2231;
  int v2233 = v2228->timer;
  int v2244 = v2233 + 1;
  v2228->timer = v2244;
  int * v2235 = v2228->regs;
  int v2236 = v2235[10];
  int v2246 = v2236 << 2;
  v2235[10] = v2246;
  struct StateT * v2238 = slot_40(v2228);
  return v2238;
}

struct StateT * slot_0(struct StateT * v2) {
  int v3 = v2->timer;
  int v9 = v3 + 1;
  v2->timer = v9;
  int * v5 = v2->regs;
  v5[11] = 0;
  struct StateT * v7 = slot_1(v2);
  return v7;
}

struct StateT * slot_14(struct StateT * v819) {
  int v820 = v819->timer;
  int v824 = v820 + 1;
  v819->timer = v824;
  struct StateT * v822 = slot_16(v819);
  return v822;
}

struct StateT * slot_42(struct StateT * v2270) {
  int v2271 = v2270->timer;
  int v2381 = v2271 + 1;
  v2270->timer = v2381;
  int * v2273 = v2270->regs;
  int v2274 = v2273[10];
  int * v2275 = v2270->cache_tags;
  int v2385 = (((int)((unsigned int)((int)((unsigned int)v2274 >> 2)) >> 1)) & 1) * 2;
  int v2276 = v2275[v2385];
  int v2386 = ((((int)((unsigned int)((int)((unsigned int)v2274 >> 2)) >> 1)) & 1) * 2) + 1;
  int v2277 = v2275[v2386];
  int v2387 = 4 + ((((int)((unsigned int)((int)((unsigned int)v2274 >> 2)) >> 1)) & 3) * 2);
  int v2278 = v2275[v2387];
  int v2388 = (4 + ((((int)((unsigned int)((int)((unsigned int)v2274 >> 2)) >> 1)) & 3) * 2)) + 1;
  int v2279 = v2275[v2388];
  int v2280 = v2270->timer;
  int v2389 = v2280 + ((100 ^ (((~(((v2278 ^ ((int)((unsigned int)((int)((unsigned int)v2274 >> 2)) >> 1))) | (-(v2278 ^ ((int)((unsigned int)((int)((unsigned int)v2274 >> 2)) >> 1))))) >> 31)) | (~(((v2279 ^ ((int)((unsigned int)((int)((unsigned int)v2274 >> 2)) >> 1))) | (-(v2279 ^ ((int)((unsigned int)((int)((unsigned int)v2274 >> 2)) >> 1))))) >> 31))) & 104)) ^ (((~(((v2276 ^ ((int)((unsigned int)((int)((unsigned int)v2274 >> 2)) >> 1))) | (-(v2276 ^ ((int)((unsigned int)((int)((unsigned int)v2274 >> 2)) >> 1))))) >> 31)) | (~(((v2277 ^ ((int)((unsigned int)((int)((unsigned int)v2274 >> 2)) >> 1))) | (-(v2277 ^ ((int)((unsigned int)((int)((unsigned int)v2274 >> 2)) >> 1))))) >> 31))) & (1 ^ (100 ^ (((~(((v2278 ^ ((int)((unsigned int)((int)((unsigned int)v2274 >> 2)) >> 1))) | (-(v2278 ^ ((int)((unsigned int)((int)((unsigned int)v2274 >> 2)) >> 1))))) >> 31)) | (~(((v2279 ^ ((int)((unsigned int)((int)((unsigned int)v2274 >> 2)) >> 1))) | (-(v2279 ^ ((int)((unsigned int)((int)((unsigned int)v2274 >> 2)) >> 1))))) >> 31))) & 104)))));
  v2270->timer = v2389;
  int * v2282 = v2270->cache_vals;
  bool v2390 = !(((~(((v2276 ^ ((int)((unsigned int)((int)((unsigned int)v2274 >> 2)) >> 1))) | (-(v2276 ^ ((int)((unsigned int)((int)((unsigned int)v2274 >> 2)) >> 1))))) >> 31)) | (~(((v2277 ^ ((int)((unsigned int)((int)((unsigned int)v2274 >> 2)) >> 1))) | (-(v2277 ^ ((int)((unsigned int)((int)((unsigned int)v2274 >> 2)) >> 1))))) >> 31))) == 0);
  int v2375;
  if (v2390) {
    int * v2283 = v2270->cache_age;
    int v2392 = ((((int)((unsigned int)((int)((unsigned int)v2274 >> 2)) >> 1)) & 1) * 2) + ((~(((v2277 ^ ((int)((unsigned int)((int)((unsigned int)v2274 >> 2)) >> 1))) | (-(v2277 ^ ((int)((unsigned int)((int)((unsigned int)v2274 >> 2)) >> 1))))) >> 31)) & 1);
    int v2284 = v2283[v2392];
    int v2285 = v2283[v2385];
    int v2393 = v2285 + ((int)((unsigned int)(v2285 - v2284) >> 31));
    v2283[v2385] = v2393;
    int * v2287 = v2270->cache_age;
    int v2288 = v2287[v2386];
    int v2395 = v2288 + ((int)((unsigned int)(v2288 - v2284) >> 31));
    v2287[v2386] = v2395;
    int * v2290 = v2270->cache_age;
    v2290[v2392] = 0;
    v2375 = v2392;
  } else {
    int * v2293 = v2270->cache_age;
    int v2399 = (((int)((unsigned int)((int)((unsigned int)v2274 >> 2)) >> 1)) & 1) * 2;
    int v2294 = v2293[v2399];
    int * v2295 = v2270->cache_tags;
    int v2296 = v2295[v2399];
    int v2297 = v2293[v2386];
    int v2298 = v2295[v2386];
    bool v2401 = !(((~(((v2278 ^ ((int)((unsigned int)((int)((unsigned int)v2274 >> 2)) >> 1))) | (-(v2278 ^ ((int)((unsigned int)((int)((unsigned int)v2274 >> 2)) >> 1))))) >> 31)) | (~(((v2279 ^ ((int)((unsigned int)((int)((unsigned int)v2274 >> 2)) >> 1))) | (-(v2279 ^ ((int)((unsigned int)((int)((unsigned int)v2274 >> 2)) >> 1))))) >> 31))) == 0);
    int v2352;
    if (v2401) {
      int * v2299 = v2270->cache_age;
      int v2403 = (4 + ((((int)((unsigned int)((int)((unsigned int)v2274 >> 2)) >> 1)) & 3) * 2)) + ((~(((v2279 ^ ((int)((unsigned int)((int)((unsigned int)v2274 >> 2)) >> 1))) | (-(v2279 ^ ((int)((unsigned int)((int)((unsigned int)v2274 >> 2)) >> 1))))) >> 31)) & 1);
      int v2300 = v2299[v2403];
      int v2301 = v2299[v2387];
      int v2404 = v2301 + ((int)((unsigned int)(v2301 - v2300) >> 31));
      v2299[v2387] = v2404;
      int * v2303 = v2270->cache_age;
      int v2304 = v2303[v2388];
      int v2406 = v2304 + ((int)((unsigned int)(v2304 - v2300) >> 31));
      v2303[v2388] = v2406;
      int * v2306 = v2270->cache_age;
      v2306[v2403] = 0;
      v2352 = v2403;
    } else {
      int * v2309 = v2270->cache_age;
      int v2410 = 4 + ((((int)((unsigned int)((int)((unsigned int)v2274 >> 2)) >> 1)) & 3) * 2);
      int v2310 = v2309[v2410];
      int * v2311 = v2270->cache_tags;
      int v2312 = v2311[v2410];
      int v2313 = v2309[v2388];
      int v2314 = v2311[v2388];
      int * v2315 = v2270->cache_dirty;
      int v2413 = (4 + ((((int)((unsigned int)((int)((unsigned int)v2274 >> 2)) >> 1)) & 3) * 2)) + ((((v2310 + ((~(((v2312 ^ -1) | (-(v2312 ^ -1))) >> 31)) & 2)) - (v2313 + ((~(((v2314 ^ -1) | (-(v2314 ^ -1))) >> 31)) & 2))) >> 31) & 1);
      int v2316 = v2315[v2413];
      bool v2414 = !(v2316 == 0);
      if (v2414) {
        int * v2317 = v2270->cache_tags;
        int v2318 = v2317[v2413];
        int * v2319 = v2270->cache_vals;
        int v2417 = ((4 + ((((int)((unsigned int)((int)((unsigned int)v2274 >> 2)) >> 1)) & 3) * 2)) + ((((v2310 + ((~(((v2312 ^ -1) | (-(v2312 ^ -1))) >> 31)) & 2)) - (v2313 + ((~(((v2314 ^ -1) | (-(v2314 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
        int v2320 = v2319[v2417];
        int v2418 = (((4 + ((((int)((unsigned int)((int)((unsigned int)v2274 >> 2)) >> 1)) & 3) * 2)) + ((((v2310 + ((~(((v2312 ^ -1) | (-(v2312 ^ -1))) >> 31)) & 2)) - (v2313 + ((~(((v2314 ^ -1) | (-(v2314 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
        int v2321 = v2319[v2418];
        int * v2322 = v2270->mem;
        int v2420 = v2318 * 2;
        v2322[v2420] = v2320;
        int * v2324 = v2270->mem;
        int v2423 = (v2318 * 2) + 1;
        v2324[v2423] = v2321;
        ;
      } else {
        ;
      }
      int * v2329 = v2270->mem;
      int v2428 = ((int)((unsigned int)((int)((unsigned int)v2274 >> 2)) >> 1)) * 2;
      int v2330 = v2329[v2428];
      int v2429 = (((int)((unsigned int)((int)((unsigned int)v2274 >> 2)) >> 1)) * 2) + 1;
      int v2331 = v2329[v2429];
      int * v2332 = v2270->cache_vals;
      int v2431 = ((4 + ((((int)((unsigned int)((int)((unsigned int)v2274 >> 2)) >> 1)) & 3) * 2)) + ((((v2310 + ((~(((v2312 ^ -1) | (-(v2312 ^ -1))) >> 31)) & 2)) - (v2313 + ((~(((v2314 ^ -1) | (-(v2314 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
      v2332[v2431] = v2330;
      int * v2334 = v2270->cache_vals;
      int v2434 = (((4 + ((((int)((unsigned int)((int)((unsigned int)v2274 >> 2)) >> 1)) & 3) * 2)) + ((((v2310 + ((~(((v2312 ^ -1) | (-(v2312 ^ -1))) >> 31)) & 2)) - (v2313 + ((~(((v2314 ^ -1) | (-(v2314 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
      v2334[v2434] = v2331;
      int * v2336 = v2270->cache_tags;
      int v2437 = (int)((unsigned int)((int)((unsigned int)v2274 >> 2)) >> 1);
      v2336[v2413] = v2437;
      int * v2338 = v2270->cache_dirty;
      v2338[v2413] = 0;
      int * v2340 = v2270->cache_age;
      v2340[v2413] = 1;
      int * v2342 = v2270->cache_age;
      int v2343 = v2342[v2413];
      int v2344 = v2342[v2387];
      int v2443 = v2344 + ((int)((unsigned int)(v2344 - v2343) >> 31));
      v2342[v2387] = v2443;
      int * v2346 = v2270->cache_age;
      int v2347 = v2346[v2388];
      int v2445 = v2347 + ((int)((unsigned int)(v2347 - v2343) >> 31));
      v2346[v2388] = v2445;
      int * v2349 = v2270->cache_age;
      v2349[v2413] = 0;
      v2352 = v2413;
    }
    int * v2353 = v2270->cache_vals;
    int v2448 = v2352 * 2;
    int v2354 = v2353[v2448];
    int v2449 = (v2352 * 2) + 1;
    int v2355 = v2353[v2449];
    int v2450 = (((((int)((unsigned int)((int)((unsigned int)v2274 >> 2)) >> 1)) & 1) * 2) + ((((v2294 + ((~(((v2296 ^ -1) | (-(v2296 ^ -1))) >> 31)) & 2)) - (v2297 + ((~(((v2298 ^ -1) | (-(v2298 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
    v2353[v2450] = v2354;
    int * v2357 = v2270->cache_vals;
    int v2453 = ((((((int)((unsigned int)((int)((unsigned int)v2274 >> 2)) >> 1)) & 1) * 2) + ((((v2294 + ((~(((v2296 ^ -1) | (-(v2296 ^ -1))) >> 31)) & 2)) - (v2297 + ((~(((v2298 ^ -1) | (-(v2298 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
    v2357[v2453] = v2355;
    int * v2359 = v2270->cache_tags;
    int v2456 = ((((int)((unsigned int)((int)((unsigned int)v2274 >> 2)) >> 1)) & 1) * 2) + ((((v2294 + ((~(((v2296 ^ -1) | (-(v2296 ^ -1))) >> 31)) & 2)) - (v2297 + ((~(((v2298 ^ -1) | (-(v2298 ^ -1))) >> 31)) & 2))) >> 31) & 1);
    int v2457 = (int)((unsigned int)((int)((unsigned int)v2274 >> 2)) >> 1);
    v2359[v2456] = v2457;
    int * v2361 = v2270->cache_dirty;
    v2361[v2456] = 0;
    int * v2363 = v2270->cache_age;
    v2363[v2456] = 1;
    int * v2365 = v2270->cache_age;
    int v2366 = v2365[v2456];
    int v2367 = v2365[v2385];
    int v2463 = v2367 + ((int)((unsigned int)(v2367 - v2366) >> 31));
    v2365[v2385] = v2463;
    int * v2369 = v2270->cache_age;
    int v2370 = v2369[v2386];
    int v2465 = v2370 + ((int)((unsigned int)(v2370 - v2366) >> 31));
    v2369[v2386] = v2465;
    int * v2372 = v2270->cache_age;
    v2372[v2456] = 0;
    v2375 = v2456;
  }
  int v2468 = (v2375 * 2) + (((int)((unsigned int)v2274 >> 2)) & 1);
  int v2376 = v2282[v2468];
  int * v2377 = v2270->regs;
  v2377[10] = v2376;
  struct StateT * v2379 = slot_43(v2270);
  return v2379;
}

struct StateT * slot_44(struct StateT * v2496) {
  int * v2497 = v2496->saved_regs;
  int v2498 = v2497[10];
  int * v2499 = v2496->regs;
  int v2500 = v2499[11];
  bool v2521 = (v2498 ^ -2147483648) < (v2500 ^ -2147483648);
  struct StateT * v2515;
  if (v2521) {
    struct StateT * v2501 = slot_32(v2496);
    v2515 = v2501;
  } else {
    int v2503 = v2496->timer;
    int v2524 = v2503 + 15;
    v2496->timer = v2524;
    int * v2505 = v2496->saved_regs;
    int v2506 = v2505[10];
    int * v2507 = v2496->regs;
    v2507[10] = v2506;
    int * v2509 = v2496->saved_regs;
    int v2510 = v2509[12];
    int * v2511 = v2496->regs;
    v2511[12] = v2510;
    struct StateT * v2513 = slot_45(v2496);
    v2515 = v2513;
  }
  return v2515;
}

struct StateT * slot_32(struct StateT * v1836) {
  int v1837 = v1836->timer;
  int v1841 = v1837 + 1;
  v1836->timer = v1841;
  struct StateT * v1839 = slot_33(v1836);
  return v1839;
}

struct StateT * slot_17(struct StateT * v848) {
  int * v849 = v848->saved_regs;
  int v850 = v849[13];
  bool v865 = !(v850 == 0);
  struct StateT * v861;
  if (v865) {
    int v851 = v848->timer;
    int v866 = v851 + 15;
    v848->timer = v866;
    int * v853 = v848->saved_regs;
    int v854 = v853[13];
    int * v855 = v848->regs;
    v855[13] = v854;
    struct StateT * v857 = slot_45(v848);
    v861 = v857;
  } else {
    struct StateT * v859 = slot_19(v848);
    v861 = v859;
  }
  return v861;
}

struct StateT * slot_33(struct StateT * v1844) {
  int * v1845 = v1844->saved_regs;
  int * v1846 = v1844->regs;
  int v1847 = v1846[13];
  v1845[13] = v1847;
  int v1849 = v1844->timer;
  int v1860 = v1849 + 1;
  v1844->timer = v1860;
  int * v1851 = v1844->regs;
  int v1852 = v1851[13];
  int v1862 = v1852 + -1;
  v1851[13] = v1862;
  struct StateT * v1854 = slot_34(v1844);
  return v1854;
}

struct StateT * slot_36(struct StateT * v1905) {
  int v1906 = v1905->timer;
  int v1910 = v1906 + 1;
  v1905->timer = v1910;
  struct StateT * v1908 = slot_38(v1905);
  return v1908;
}

struct StateT * snippet(struct StateT * v0) {
  struct StateT * v1 = slot_0(v0);
  return v1;
}

struct StateT * slot_40(struct StateT * v2254) {
  int v2255 = v2254->timer;
  int v2263 = v2255 + 1;
  v2254->timer = v2263;
  int * v2257 = v2254->regs;
  int v2258 = v2257[14];
  int v2259 = v2257[10];
  int v2267 = v2258 + v2259;
  v2257[10] = v2267;
  struct StateT * v2261 = slot_42(v2254);
  return v2261;
}

struct StateT * slot_8(struct StateT * v503) {
  int * v504 = v503->saved_regs;
  int * v505 = v503->regs;
  int v506 = v505[10];
  v504[10] = v506;
  int v508 = v503->timer;
  int v519 = v508 + 1;
  v503->timer = v519;
  int * v510 = v503->regs;
  int v511 = v510[10];
  int v521 = v511 << 2;
  v510[10] = v521;
  struct StateT * v513 = slot_9(v503);
  return v513;
}

struct StateT * slot_27(struct StateT * v1596) {
  int v1597 = v1596->timer;
  int v1605 = v1597 + 1;
  v1596->timer = v1605;
  int * v1599 = v1596->regs;
  int v1600 = v1599[14];
  int v1601 = v1599[10];
  int v1609 = v1600 + v1601;
  v1599[10] = v1609;
  struct StateT * v1603 = slot_29(v1596);
  return v1603;
}

struct StateT * slot_4(struct StateT * v246) {
  int * v247 = v246->saved_regs;
  int * v248 = v246->regs;
  int v249 = v248[12];
  v247[12] = v249;
  int v251 = v246->timer;
  int v261 = v251 + 1;
  v246->timer = v261;
  int * v253 = v246->regs;
  v253[12] = 0;
  struct StateT * v255 = slot_5(v246);
  return v255;
}

struct StateT * slot_9(struct StateT * v524) {
  int v525 = v524->timer;
  int v533 = v525 + 1;
  v524->timer = v533;
  int * v527 = v524->regs;
  int v528 = v527[14];
  int v529 = v527[10];
  int v537 = v528 + v529;
  v527[10] = v537;
  struct StateT * v531 = slot_10(v524);
  return v531;
}

struct StateT * slot_11(struct StateT * v743) {
  int v744 = v743->timer;
  int v752 = v744 + 1;
  v743->timer = v752;
  int * v746 = v743->regs;
  int v747 = v746[12];
  int v748 = v746[10];
  int v756 = v747 & v748;
  v746[12] = v756;
  struct StateT * v750 = slot_12(v743);
  return v750;
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