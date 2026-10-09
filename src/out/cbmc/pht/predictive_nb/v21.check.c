// verify: clean (CBMC should report VERIFICATION SUCCESSFUL) [unwind 65]
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
struct StateT * slot_34(struct StateT * v2004);
struct StateT * slot_43(struct StateT * v2643);
struct StateT * slot_6(struct StateT * v486);
struct StateT * slot_29(struct StateT * v1737);
struct StateT * slot_25(struct StateT * v1368);
struct StateT * slot_16(struct StateT * v901);
struct StateT * slot_23(struct StateT * v1332);
struct StateT * slot_5(struct StateT * v279);
struct StateT * slot_2(struct StateT * v225);
struct StateT * slot_7(struct StateT * v509);
struct StateT * slot_21(struct StateT * v1304);
struct StateT * slot_31(struct StateT * v1944);
struct StateT * slot_3(struct StateT * v233);
struct StateT * slot_45(struct StateT * v2723);
struct StateT * slot_26(struct StateT * v1389);
struct StateT * slot_10(struct StateT * v582);
struct StateT * slot_1(struct StateT * v18);
struct StateT * slot_19(struct StateT * v977);
struct StateT * slot_13(struct StateT * v888);
struct StateT * slot_38(struct StateT * v2379);
struct StateT * slot_0(struct StateT * v2);
struct StateT * slot_14(struct StateT * v893);
struct StateT * slot_42(struct StateT * v2436);
struct StateT * slot_44(struct StateT * v2674);
struct StateT * slot_32(struct StateT * v1968);
struct StateT * slot_17(struct StateT * v929);
struct StateT * slot_33(struct StateT * v1976);
struct StateT * slot_36(struct StateT * v2052);
struct StateT * snippet(struct StateT * v0);
struct StateT * slot_40(struct StateT * v2412);
struct StateT * slot_8(struct StateT * v530);
struct StateT * slot_27(struct StateT * v1708);
struct StateT * slot_4(struct StateT * v256);
struct StateT * slot_9(struct StateT * v558);
struct StateT * slot_11(struct StateT * v789);
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

struct StateT * slot_34(struct StateT * v2004) {
  int * v2005 = v2004->saved_regs;
  int v2006 = v2005[13];
  bool v2024 = !(v2006 == 0);
  struct StateT * v2020;
  if (v2024) {
    int v2007 = v2004->timer;
    int v2025 = v2007 + 15;
    v2004->timer = v2025;
    int * v2009 = v2004->saved_regs;
    int v2010 = v2009[13];
    int * v2011 = v2004->regs;
    v2011[13] = v2010;
    int * v2013 = v2004->reg_ready;
    int v2014 = v2004->timer;
    v2013[13] = v2014;
    struct StateT * v2016 = slot_45(v2004);
    v2020 = v2016;
  } else {
    struct StateT * v2018 = slot_36(v2004);
    v2020 = v2018;
  }
  return v2020;
}

struct StateT * slot_43(struct StateT * v2643) {
  int * v2644 = v2643->saved_regs;
  int * v2645 = v2643->regs;
  int v2646 = v2645[12];
  v2644[12] = v2646;
  int v2648 = v2643->timer;
  int v2665 = v2648 + 1;
  v2643->timer = v2665;
  int * v2650 = v2643->reg_ready;
  int v2651 = v2650[12];
  int * v2652 = v2643->regs;
  int v2653 = v2652[12];
  int v2654 = v2650[10];
  int v2655 = v2652[10];
  int v2669 = (v2654 + (((v2651 + ((v2648 - v2651) & (~((v2648 - v2651) >> 31)))) - v2654) & (~(((v2651 + ((v2648 - v2651) & (~((v2648 - v2651) >> 31)))) - v2654) >> 31)))) + 1;
  v2650[12] = v2669;
  int * v2657 = v2643->regs;
  int v2671 = v2653 & v2655;
  v2657[12] = v2671;
  struct StateT * v2659 = slot_44(v2643);
  return v2659;
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

struct StateT * slot_29(struct StateT * v1737) {
  int v1738 = v1737->timer;
  int v1850 = v1738 + 1;
  v1737->timer = v1850;
  int * v1740 = v1737->reg_ready;
  int v1741 = v1740[10];
  int * v1742 = v1737->regs;
  int v1743 = v1742[10];
  int * v1744 = v1737->cache_tags;
  int v1855 = (((int)((unsigned int)((int)((unsigned int)v1743 >> 2)) >> 1)) & 1) * 2;
  int v1745 = v1744[v1855];
  int v1856 = ((((int)((unsigned int)((int)((unsigned int)v1743 >> 2)) >> 1)) & 1) * 2) + 1;
  int v1746 = v1744[v1856];
  int v1857 = 4 + ((((int)((unsigned int)((int)((unsigned int)v1743 >> 2)) >> 1)) & 3) * 2);
  int v1747 = v1744[v1857];
  int v1858 = (4 + ((((int)((unsigned int)((int)((unsigned int)v1743 >> 2)) >> 1)) & 3) * 2)) + 1;
  int v1748 = v1744[v1858];
  int * v1749 = v1737->cache_vals;
  bool v1859 = !(((~(((v1745 ^ ((int)((unsigned int)((int)((unsigned int)v1743 >> 2)) >> 1))) | (-(v1745 ^ ((int)((unsigned int)((int)((unsigned int)v1743 >> 2)) >> 1))))) >> 31)) | (~(((v1746 ^ ((int)((unsigned int)((int)((unsigned int)v1743 >> 2)) >> 1))) | (-(v1746 ^ ((int)((unsigned int)((int)((unsigned int)v1743 >> 2)) >> 1))))) >> 31))) == 0);
  int v1842;
  if (v1859) {
    int * v1750 = v1737->cache_age;
    int v1861 = ((((int)((unsigned int)((int)((unsigned int)v1743 >> 2)) >> 1)) & 1) * 2) + ((~(((v1746 ^ ((int)((unsigned int)((int)((unsigned int)v1743 >> 2)) >> 1))) | (-(v1746 ^ ((int)((unsigned int)((int)((unsigned int)v1743 >> 2)) >> 1))))) >> 31)) & 1);
    int v1751 = v1750[v1861];
    int v1752 = v1750[v1855];
    int v1862 = v1752 + ((int)((unsigned int)(v1752 - v1751) >> 31));
    v1750[v1855] = v1862;
    int * v1754 = v1737->cache_age;
    int v1755 = v1754[v1856];
    int v1864 = v1755 + ((int)((unsigned int)(v1755 - v1751) >> 31));
    v1754[v1856] = v1864;
    int * v1757 = v1737->cache_age;
    v1757[v1861] = 0;
    v1842 = v1861;
  } else {
    int * v1760 = v1737->cache_age;
    int v1868 = (((int)((unsigned int)((int)((unsigned int)v1743 >> 2)) >> 1)) & 1) * 2;
    int v1761 = v1760[v1868];
    int * v1762 = v1737->cache_tags;
    int v1763 = v1762[v1868];
    int v1764 = v1760[v1856];
    int v1765 = v1762[v1856];
    bool v1870 = !(((~(((v1747 ^ ((int)((unsigned int)((int)((unsigned int)v1743 >> 2)) >> 1))) | (-(v1747 ^ ((int)((unsigned int)((int)((unsigned int)v1743 >> 2)) >> 1))))) >> 31)) | (~(((v1748 ^ ((int)((unsigned int)((int)((unsigned int)v1743 >> 2)) >> 1))) | (-(v1748 ^ ((int)((unsigned int)((int)((unsigned int)v1743 >> 2)) >> 1))))) >> 31))) == 0);
    int v1819;
    if (v1870) {
      int * v1766 = v1737->cache_age;
      int v1872 = (4 + ((((int)((unsigned int)((int)((unsigned int)v1743 >> 2)) >> 1)) & 3) * 2)) + ((~(((v1748 ^ ((int)((unsigned int)((int)((unsigned int)v1743 >> 2)) >> 1))) | (-(v1748 ^ ((int)((unsigned int)((int)((unsigned int)v1743 >> 2)) >> 1))))) >> 31)) & 1);
      int v1767 = v1766[v1872];
      int v1768 = v1766[v1857];
      int v1873 = v1768 + ((int)((unsigned int)(v1768 - v1767) >> 31));
      v1766[v1857] = v1873;
      int * v1770 = v1737->cache_age;
      int v1771 = v1770[v1858];
      int v1875 = v1771 + ((int)((unsigned int)(v1771 - v1767) >> 31));
      v1770[v1858] = v1875;
      int * v1773 = v1737->cache_age;
      v1773[v1872] = 0;
      v1819 = v1872;
    } else {
      int * v1776 = v1737->cache_age;
      int v1879 = 4 + ((((int)((unsigned int)((int)((unsigned int)v1743 >> 2)) >> 1)) & 3) * 2);
      int v1777 = v1776[v1879];
      int * v1778 = v1737->cache_tags;
      int v1779 = v1778[v1879];
      int v1780 = v1776[v1858];
      int v1781 = v1778[v1858];
      int * v1782 = v1737->cache_dirty;
      int v1882 = (4 + ((((int)((unsigned int)((int)((unsigned int)v1743 >> 2)) >> 1)) & 3) * 2)) + ((((v1777 + ((~(((v1779 ^ -1) | (-(v1779 ^ -1))) >> 31)) & 2)) - (v1780 + ((~(((v1781 ^ -1) | (-(v1781 ^ -1))) >> 31)) & 2))) >> 31) & 1);
      int v1783 = v1782[v1882];
      bool v1883 = !(v1783 == 0);
      if (v1883) {
        int * v1784 = v1737->cache_tags;
        int v1785 = v1784[v1882];
        int * v1786 = v1737->cache_vals;
        int v1886 = ((4 + ((((int)((unsigned int)((int)((unsigned int)v1743 >> 2)) >> 1)) & 3) * 2)) + ((((v1777 + ((~(((v1779 ^ -1) | (-(v1779 ^ -1))) >> 31)) & 2)) - (v1780 + ((~(((v1781 ^ -1) | (-(v1781 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
        int v1787 = v1786[v1886];
        int v1887 = (((4 + ((((int)((unsigned int)((int)((unsigned int)v1743 >> 2)) >> 1)) & 3) * 2)) + ((((v1777 + ((~(((v1779 ^ -1) | (-(v1779 ^ -1))) >> 31)) & 2)) - (v1780 + ((~(((v1781 ^ -1) | (-(v1781 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
        int v1788 = v1786[v1887];
        int * v1789 = v1737->mem;
        int v1889 = v1785 * 2;
        v1789[v1889] = v1787;
        int * v1791 = v1737->mem;
        int v1892 = (v1785 * 2) + 1;
        v1791[v1892] = v1788;
        ;
      } else {
        ;
      }
      int * v1796 = v1737->mem;
      int v1897 = ((int)((unsigned int)((int)((unsigned int)v1743 >> 2)) >> 1)) * 2;
      int v1797 = v1796[v1897];
      int v1898 = (((int)((unsigned int)((int)((unsigned int)v1743 >> 2)) >> 1)) * 2) + 1;
      int v1798 = v1796[v1898];
      int * v1799 = v1737->cache_vals;
      int v1900 = ((4 + ((((int)((unsigned int)((int)((unsigned int)v1743 >> 2)) >> 1)) & 3) * 2)) + ((((v1777 + ((~(((v1779 ^ -1) | (-(v1779 ^ -1))) >> 31)) & 2)) - (v1780 + ((~(((v1781 ^ -1) | (-(v1781 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
      v1799[v1900] = v1797;
      int * v1801 = v1737->cache_vals;
      int v1903 = (((4 + ((((int)((unsigned int)((int)((unsigned int)v1743 >> 2)) >> 1)) & 3) * 2)) + ((((v1777 + ((~(((v1779 ^ -1) | (-(v1779 ^ -1))) >> 31)) & 2)) - (v1780 + ((~(((v1781 ^ -1) | (-(v1781 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
      v1801[v1903] = v1798;
      int * v1803 = v1737->cache_tags;
      int v1906 = (int)((unsigned int)((int)((unsigned int)v1743 >> 2)) >> 1);
      v1803[v1882] = v1906;
      int * v1805 = v1737->cache_dirty;
      v1805[v1882] = 0;
      int * v1807 = v1737->cache_age;
      v1807[v1882] = 1;
      int * v1809 = v1737->cache_age;
      int v1810 = v1809[v1882];
      int v1811 = v1809[v1857];
      int v1912 = v1811 + ((int)((unsigned int)(v1811 - v1810) >> 31));
      v1809[v1857] = v1912;
      int * v1813 = v1737->cache_age;
      int v1814 = v1813[v1858];
      int v1914 = v1814 + ((int)((unsigned int)(v1814 - v1810) >> 31));
      v1813[v1858] = v1914;
      int * v1816 = v1737->cache_age;
      v1816[v1882] = 0;
      v1819 = v1882;
    }
    int * v1820 = v1737->cache_vals;
    int v1917 = v1819 * 2;
    int v1821 = v1820[v1917];
    int v1918 = (v1819 * 2) + 1;
    int v1822 = v1820[v1918];
    int v1919 = (((((int)((unsigned int)((int)((unsigned int)v1743 >> 2)) >> 1)) & 1) * 2) + ((((v1761 + ((~(((v1763 ^ -1) | (-(v1763 ^ -1))) >> 31)) & 2)) - (v1764 + ((~(((v1765 ^ -1) | (-(v1765 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
    v1820[v1919] = v1821;
    int * v1824 = v1737->cache_vals;
    int v1922 = ((((((int)((unsigned int)((int)((unsigned int)v1743 >> 2)) >> 1)) & 1) * 2) + ((((v1761 + ((~(((v1763 ^ -1) | (-(v1763 ^ -1))) >> 31)) & 2)) - (v1764 + ((~(((v1765 ^ -1) | (-(v1765 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
    v1824[v1922] = v1822;
    int * v1826 = v1737->cache_tags;
    int v1925 = ((((int)((unsigned int)((int)((unsigned int)v1743 >> 2)) >> 1)) & 1) * 2) + ((((v1761 + ((~(((v1763 ^ -1) | (-(v1763 ^ -1))) >> 31)) & 2)) - (v1764 + ((~(((v1765 ^ -1) | (-(v1765 ^ -1))) >> 31)) & 2))) >> 31) & 1);
    int v1926 = (int)((unsigned int)((int)((unsigned int)v1743 >> 2)) >> 1);
    v1826[v1925] = v1926;
    int * v1828 = v1737->cache_dirty;
    v1828[v1925] = 0;
    int * v1830 = v1737->cache_age;
    v1830[v1925] = 1;
    int * v1832 = v1737->cache_age;
    int v1833 = v1832[v1925];
    int v1834 = v1832[v1855];
    int v1932 = v1834 + ((int)((unsigned int)(v1834 - v1833) >> 31));
    v1832[v1855] = v1932;
    int * v1836 = v1737->cache_age;
    int v1837 = v1836[v1856];
    int v1934 = v1837 + ((int)((unsigned int)(v1837 - v1833) >> 31));
    v1836[v1856] = v1934;
    int * v1839 = v1737->cache_age;
    v1839[v1925] = 0;
    v1842 = v1925;
  }
  int v1937 = (v1842 * 2) + (((int)((unsigned int)v1743 >> 2)) & 1);
  int v1843 = v1749[v1937];
  int * v1844 = v1737->reg_ready;
  int v1939 = ((v1741 + ((v1738 - v1741) & (~((v1738 - v1741) >> 31)))) + 1) + ((100 ^ (((~(((v1747 ^ ((int)((unsigned int)((int)((unsigned int)v1743 >> 2)) >> 1))) | (-(v1747 ^ ((int)((unsigned int)((int)((unsigned int)v1743 >> 2)) >> 1))))) >> 31)) | (~(((v1748 ^ ((int)((unsigned int)((int)((unsigned int)v1743 >> 2)) >> 1))) | (-(v1748 ^ ((int)((unsigned int)((int)((unsigned int)v1743 >> 2)) >> 1))))) >> 31))) & 104)) ^ (((~(((v1745 ^ ((int)((unsigned int)((int)((unsigned int)v1743 >> 2)) >> 1))) | (-(v1745 ^ ((int)((unsigned int)((int)((unsigned int)v1743 >> 2)) >> 1))))) >> 31)) | (~(((v1746 ^ ((int)((unsigned int)((int)((unsigned int)v1743 >> 2)) >> 1))) | (-(v1746 ^ ((int)((unsigned int)((int)((unsigned int)v1743 >> 2)) >> 1))))) >> 31))) & (1 ^ (100 ^ (((~(((v1747 ^ ((int)((unsigned int)((int)((unsigned int)v1743 >> 2)) >> 1))) | (-(v1747 ^ ((int)((unsigned int)((int)((unsigned int)v1743 >> 2)) >> 1))))) >> 31)) | (~(((v1748 ^ ((int)((unsigned int)((int)((unsigned int)v1743 >> 2)) >> 1))) | (-(v1748 ^ ((int)((unsigned int)((int)((unsigned int)v1743 >> 2)) >> 1))))) >> 31))) & 104)))));
  v1844[10] = v1939;
  int * v1846 = v1737->regs;
  v1846[10] = v1843;
  struct StateT * v1848 = slot_31(v1737);
  return v1848;
}

struct StateT * slot_25(struct StateT * v1368) {
  int v1369 = v1368->timer;
  int v1380 = v1369 + 1;
  v1368->timer = v1380;
  int * v1371 = v1368->reg_ready;
  int v1372 = v1371[10];
  int * v1373 = v1368->regs;
  int v1374 = v1373[10];
  int v1384 = (v1372 + ((v1369 - v1372) & (~((v1369 - v1372) >> 31)))) + 1;
  v1371[10] = v1384;
  int * v1376 = v1368->regs;
  int v1386 = v1374 << 2;
  v1376[10] = v1386;
  struct StateT * v1378 = slot_27(v1368);
  return v1378;
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

struct StateT * slot_23(struct StateT * v1332) {
  int * v1333 = v1332->saved_regs;
  int v1334 = v1333[10];
  int * v1335 = v1332->regs;
  int v1336 = v1335[11];
  bool v1356 = (v1334 ^ -2147483648) < (v1336 ^ -2147483648);
  struct StateT * v1350;
  if (v1356) {
    int v1337 = v1332->timer;
    int v1357 = v1337 + 15;
    v1332->timer = v1357;
    int * v1339 = v1332->saved_regs;
    int v1340 = v1339[10];
    int * v1341 = v1332->regs;
    v1341[10] = v1340;
    int * v1343 = v1332->reg_ready;
    int v1344 = v1332->timer;
    v1343[10] = v1344;
    struct StateT * v1346 = slot_25(v1332);
    v1350 = v1346;
  } else {
    struct StateT * v1348 = slot_26(v1332);
    v1350 = v1348;
  }
  return v1350;
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
  struct StateT * v1315 = slot_23(v1304);
  return v1315;
}

struct StateT * slot_31(struct StateT * v1944) {
  int v1945 = v1944->timer;
  int v1958 = v1945 + 1;
  v1944->timer = v1958;
  int * v1947 = v1944->reg_ready;
  int v1948 = v1947[12];
  int * v1949 = v1944->regs;
  int v1950 = v1949[12];
  int v1951 = v1947[10];
  int v1952 = v1949[10];
  int v1963 = (v1951 + (((v1948 + ((v1945 - v1948) & (~((v1945 - v1948) >> 31)))) - v1951) & (~(((v1948 + ((v1945 - v1948) & (~((v1945 - v1948) >> 31)))) - v1951) >> 31)))) + 1;
  v1947[12] = v1963;
  int * v1954 = v1944->regs;
  int v1965 = v1950 & v1952;
  v1954[12] = v1965;
  struct StateT * v1956 = slot_32(v1944);
  return v1956;
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

struct StateT * slot_45(struct StateT * v2723) {
  int v2724 = v2723->timer;
  int v2732 = v2724 + 1;
  v2723->timer = v2732;
  int * v2726 = v2723->reg_ready;
  v2726[10] = v2732;
  int * v2728 = v2723->regs;
  v2728[10] = 0;
  struct StateT * v2730 = slot_26(v2723);
  return v2730;
}

struct StateT * slot_26(struct StateT * v1389) {
  int v1390 = v1389->timer;
  int v1563 = v1390 + 1;
  v1389->timer = v1563;
  int * v1392 = v1389->reg_ready;
  int * v1394 = v1389->regs;
  int v1395 = v1394[10];
  int v1397 = v1394[12];
  int * v1398 = v1389->cache_tags;
  int v1569 = (((int)((unsigned int)((int)((unsigned int)(v1395 + 68) >> 2)) >> 1)) & 1) * 2;
  int v1399 = v1398[v1569];
  int v1570 = ((((int)((unsigned int)((int)((unsigned int)(v1395 + 68) >> 2)) >> 1)) & 1) * 2) + 1;
  int v1400 = v1398[v1570];
  int v1571 = 4 + ((((int)((unsigned int)((int)((unsigned int)(v1395 + 68) >> 2)) >> 1)) & 3) * 2);
  int v1401 = v1398[v1571];
  int v1572 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v1395 + 68) >> 2)) >> 1)) & 3) * 2)) + 1;
  int v1402 = v1398[v1572];
  int v1403 = v1389->timer;
  int v1573 = v1403 + ((100 ^ (((~(((v1401 ^ ((int)((unsigned int)((int)((unsigned int)(v1395 + 68) >> 2)) >> 1))) | (-(v1401 ^ ((int)((unsigned int)((int)((unsigned int)(v1395 + 68) >> 2)) >> 1))))) >> 31)) | (~(((v1402 ^ ((int)((unsigned int)((int)((unsigned int)(v1395 + 68) >> 2)) >> 1))) | (-(v1402 ^ ((int)((unsigned int)((int)((unsigned int)(v1395 + 68) >> 2)) >> 1))))) >> 31))) & 104)) ^ (((~(((v1399 ^ ((int)((unsigned int)((int)((unsigned int)(v1395 + 68) >> 2)) >> 1))) | (-(v1399 ^ ((int)((unsigned int)((int)((unsigned int)(v1395 + 68) >> 2)) >> 1))))) >> 31)) | (~(((v1400 ^ ((int)((unsigned int)((int)((unsigned int)(v1395 + 68) >> 2)) >> 1))) | (-(v1400 ^ ((int)((unsigned int)((int)((unsigned int)(v1395 + 68) >> 2)) >> 1))))) >> 31))) & (1 ^ (100 ^ (((~(((v1401 ^ ((int)((unsigned int)((int)((unsigned int)(v1395 + 68) >> 2)) >> 1))) | (-(v1401 ^ ((int)((unsigned int)((int)((unsigned int)(v1395 + 68) >> 2)) >> 1))))) >> 31)) | (~(((v1402 ^ ((int)((unsigned int)((int)((unsigned int)(v1395 + 68) >> 2)) >> 1))) | (-(v1402 ^ ((int)((unsigned int)((int)((unsigned int)(v1395 + 68) >> 2)) >> 1))))) >> 31))) & 104)))));
  v1389->timer = v1573;
  bool v1574 = !(((~(((v1399 ^ ((int)((unsigned int)((int)((unsigned int)(v1395 + 68) >> 2)) >> 1))) | (-(v1399 ^ ((int)((unsigned int)((int)((unsigned int)(v1395 + 68) >> 2)) >> 1))))) >> 31)) | (~(((v1400 ^ ((int)((unsigned int)((int)((unsigned int)(v1395 + 68) >> 2)) >> 1))) | (-(v1400 ^ ((int)((unsigned int)((int)((unsigned int)(v1395 + 68) >> 2)) >> 1))))) >> 31))) == 0);
  int v1497;
  if (v1574) {
    int * v1405 = v1389->cache_age;
    int v1576 = ((((int)((unsigned int)((int)((unsigned int)(v1395 + 68) >> 2)) >> 1)) & 1) * 2) + ((~(((v1400 ^ ((int)((unsigned int)((int)((unsigned int)(v1395 + 68) >> 2)) >> 1))) | (-(v1400 ^ ((int)((unsigned int)((int)((unsigned int)(v1395 + 68) >> 2)) >> 1))))) >> 31)) & 1);
    int v1406 = v1405[v1576];
    int v1407 = v1405[v1569];
    int v1577 = v1407 + ((int)((unsigned int)(v1407 - v1406) >> 31));
    v1405[v1569] = v1577;
    int * v1409 = v1389->cache_age;
    int v1410 = v1409[v1570];
    int v1579 = v1410 + ((int)((unsigned int)(v1410 - v1406) >> 31));
    v1409[v1570] = v1579;
    int * v1412 = v1389->cache_age;
    v1412[v1576] = 0;
    v1497 = v1576;
  } else {
    int * v1415 = v1389->cache_age;
    int v1583 = (((int)((unsigned int)((int)((unsigned int)(v1395 + 68) >> 2)) >> 1)) & 1) * 2;
    int v1416 = v1415[v1583];
    int * v1417 = v1389->cache_tags;
    int v1418 = v1417[v1583];
    int v1419 = v1415[v1570];
    int v1420 = v1417[v1570];
    bool v1585 = !(((~(((v1401 ^ ((int)((unsigned int)((int)((unsigned int)(v1395 + 68) >> 2)) >> 1))) | (-(v1401 ^ ((int)((unsigned int)((int)((unsigned int)(v1395 + 68) >> 2)) >> 1))))) >> 31)) | (~(((v1402 ^ ((int)((unsigned int)((int)((unsigned int)(v1395 + 68) >> 2)) >> 1))) | (-(v1402 ^ ((int)((unsigned int)((int)((unsigned int)(v1395 + 68) >> 2)) >> 1))))) >> 31))) == 0);
    int v1474;
    if (v1585) {
      int * v1421 = v1389->cache_age;
      int v1587 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v1395 + 68) >> 2)) >> 1)) & 3) * 2)) + ((~(((v1402 ^ ((int)((unsigned int)((int)((unsigned int)(v1395 + 68) >> 2)) >> 1))) | (-(v1402 ^ ((int)((unsigned int)((int)((unsigned int)(v1395 + 68) >> 2)) >> 1))))) >> 31)) & 1);
      int v1422 = v1421[v1587];
      int v1423 = v1421[v1571];
      int v1588 = v1423 + ((int)((unsigned int)(v1423 - v1422) >> 31));
      v1421[v1571] = v1588;
      int * v1425 = v1389->cache_age;
      int v1426 = v1425[v1572];
      int v1590 = v1426 + ((int)((unsigned int)(v1426 - v1422) >> 31));
      v1425[v1572] = v1590;
      int * v1428 = v1389->cache_age;
      v1428[v1587] = 0;
      v1474 = v1587;
    } else {
      int * v1431 = v1389->cache_age;
      int v1594 = 4 + ((((int)((unsigned int)((int)((unsigned int)(v1395 + 68) >> 2)) >> 1)) & 3) * 2);
      int v1432 = v1431[v1594];
      int * v1433 = v1389->cache_tags;
      int v1434 = v1433[v1594];
      int v1435 = v1431[v1572];
      int v1436 = v1433[v1572];
      int * v1437 = v1389->cache_dirty;
      int v1597 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v1395 + 68) >> 2)) >> 1)) & 3) * 2)) + ((((v1432 + ((~(((v1434 ^ -1) | (-(v1434 ^ -1))) >> 31)) & 2)) - (v1435 + ((~(((v1436 ^ -1) | (-(v1436 ^ -1))) >> 31)) & 2))) >> 31) & 1);
      int v1438 = v1437[v1597];
      bool v1598 = !(v1438 == 0);
      if (v1598) {
        int * v1439 = v1389->cache_tags;
        int v1440 = v1439[v1597];
        int * v1441 = v1389->cache_vals;
        int v1601 = ((4 + ((((int)((unsigned int)((int)((unsigned int)(v1395 + 68) >> 2)) >> 1)) & 3) * 2)) + ((((v1432 + ((~(((v1434 ^ -1) | (-(v1434 ^ -1))) >> 31)) & 2)) - (v1435 + ((~(((v1436 ^ -1) | (-(v1436 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
        int v1442 = v1441[v1601];
        int v1602 = (((4 + ((((int)((unsigned int)((int)((unsigned int)(v1395 + 68) >> 2)) >> 1)) & 3) * 2)) + ((((v1432 + ((~(((v1434 ^ -1) | (-(v1434 ^ -1))) >> 31)) & 2)) - (v1435 + ((~(((v1436 ^ -1) | (-(v1436 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
        int v1443 = v1441[v1602];
        int * v1444 = v1389->mem;
        int v1604 = v1440 * 2;
        v1444[v1604] = v1442;
        int * v1446 = v1389->mem;
        int v1607 = (v1440 * 2) + 1;
        v1446[v1607] = v1443;
        ;
      } else {
        ;
      }
      int * v1451 = v1389->mem;
      int v1612 = ((int)((unsigned int)((int)((unsigned int)(v1395 + 68) >> 2)) >> 1)) * 2;
      int v1452 = v1451[v1612];
      int v1613 = (((int)((unsigned int)((int)((unsigned int)(v1395 + 68) >> 2)) >> 1)) * 2) + 1;
      int v1453 = v1451[v1613];
      int * v1454 = v1389->cache_vals;
      int v1615 = ((4 + ((((int)((unsigned int)((int)((unsigned int)(v1395 + 68) >> 2)) >> 1)) & 3) * 2)) + ((((v1432 + ((~(((v1434 ^ -1) | (-(v1434 ^ -1))) >> 31)) & 2)) - (v1435 + ((~(((v1436 ^ -1) | (-(v1436 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
      v1454[v1615] = v1452;
      int * v1456 = v1389->cache_vals;
      int v1618 = (((4 + ((((int)((unsigned int)((int)((unsigned int)(v1395 + 68) >> 2)) >> 1)) & 3) * 2)) + ((((v1432 + ((~(((v1434 ^ -1) | (-(v1434 ^ -1))) >> 31)) & 2)) - (v1435 + ((~(((v1436 ^ -1) | (-(v1436 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
      v1456[v1618] = v1453;
      int * v1458 = v1389->cache_tags;
      int v1621 = (int)((unsigned int)((int)((unsigned int)(v1395 + 68) >> 2)) >> 1);
      v1458[v1597] = v1621;
      int * v1460 = v1389->cache_dirty;
      v1460[v1597] = 0;
      int * v1462 = v1389->cache_age;
      v1462[v1597] = 1;
      int * v1464 = v1389->cache_age;
      int v1465 = v1464[v1597];
      int v1466 = v1464[v1571];
      int v1627 = v1466 + ((int)((unsigned int)(v1466 - v1465) >> 31));
      v1464[v1571] = v1627;
      int * v1468 = v1389->cache_age;
      int v1469 = v1468[v1572];
      int v1629 = v1469 + ((int)((unsigned int)(v1469 - v1465) >> 31));
      v1468[v1572] = v1629;
      int * v1471 = v1389->cache_age;
      v1471[v1597] = 0;
      v1474 = v1597;
    }
    int * v1475 = v1389->cache_vals;
    int v1632 = v1474 * 2;
    int v1476 = v1475[v1632];
    int v1633 = (v1474 * 2) + 1;
    int v1477 = v1475[v1633];
    int v1634 = (((((int)((unsigned int)((int)((unsigned int)(v1395 + 68) >> 2)) >> 1)) & 1) * 2) + ((((v1416 + ((~(((v1418 ^ -1) | (-(v1418 ^ -1))) >> 31)) & 2)) - (v1419 + ((~(((v1420 ^ -1) | (-(v1420 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
    v1475[v1634] = v1476;
    int * v1479 = v1389->cache_vals;
    int v1637 = ((((((int)((unsigned int)((int)((unsigned int)(v1395 + 68) >> 2)) >> 1)) & 1) * 2) + ((((v1416 + ((~(((v1418 ^ -1) | (-(v1418 ^ -1))) >> 31)) & 2)) - (v1419 + ((~(((v1420 ^ -1) | (-(v1420 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
    v1479[v1637] = v1477;
    int * v1481 = v1389->cache_tags;
    int v1640 = ((((int)((unsigned int)((int)((unsigned int)(v1395 + 68) >> 2)) >> 1)) & 1) * 2) + ((((v1416 + ((~(((v1418 ^ -1) | (-(v1418 ^ -1))) >> 31)) & 2)) - (v1419 + ((~(((v1420 ^ -1) | (-(v1420 ^ -1))) >> 31)) & 2))) >> 31) & 1);
    int v1641 = (int)((unsigned int)((int)((unsigned int)(v1395 + 68) >> 2)) >> 1);
    v1481[v1640] = v1641;
    int * v1483 = v1389->cache_dirty;
    v1483[v1640] = 0;
    int * v1485 = v1389->cache_age;
    v1485[v1640] = 1;
    int * v1487 = v1389->cache_age;
    int v1488 = v1487[v1640];
    int v1489 = v1487[v1569];
    int v1647 = v1489 + ((int)((unsigned int)(v1489 - v1488) >> 31));
    v1487[v1569] = v1647;
    int * v1491 = v1389->cache_age;
    int v1492 = v1491[v1570];
    int v1649 = v1492 + ((int)((unsigned int)(v1492 - v1488) >> 31));
    v1491[v1570] = v1649;
    int * v1494 = v1389->cache_age;
    v1494[v1640] = 0;
    v1497 = v1640;
  }
  int * v1498 = v1389->cache_vals;
  int v1652 = (v1497 * 2) + (((int)((unsigned int)(v1395 + 68) >> 2)) & 1);
  v1498[v1652] = v1397;
  int * v1500 = v1389->cache_tags;
  int v1501 = v1500[v1571];
  int v1502 = v1500[v1572];
  bool v1655 = !(((~(((v1501 ^ ((int)((unsigned int)((int)((unsigned int)(v1395 + 68) >> 2)) >> 1))) | (-(v1501 ^ ((int)((unsigned int)((int)((unsigned int)(v1395 + 68) >> 2)) >> 1))))) >> 31)) | (~(((v1502 ^ ((int)((unsigned int)((int)((unsigned int)(v1395 + 68) >> 2)) >> 1))) | (-(v1502 ^ ((int)((unsigned int)((int)((unsigned int)(v1395 + 68) >> 2)) >> 1))))) >> 31))) == 0);
  int v1556;
  if (v1655) {
    int * v1503 = v1389->cache_age;
    int v1657 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v1395 + 68) >> 2)) >> 1)) & 3) * 2)) + ((~(((v1502 ^ ((int)((unsigned int)((int)((unsigned int)(v1395 + 68) >> 2)) >> 1))) | (-(v1502 ^ ((int)((unsigned int)((int)((unsigned int)(v1395 + 68) >> 2)) >> 1))))) >> 31)) & 1);
    int v1504 = v1503[v1657];
    int v1505 = v1503[v1571];
    int v1658 = v1505 + ((int)((unsigned int)(v1505 - v1504) >> 31));
    v1503[v1571] = v1658;
    int * v1507 = v1389->cache_age;
    int v1508 = v1507[v1572];
    int v1660 = v1508 + ((int)((unsigned int)(v1508 - v1504) >> 31));
    v1507[v1572] = v1660;
    int * v1510 = v1389->cache_age;
    v1510[v1657] = 0;
    v1556 = v1657;
  } else {
    int * v1513 = v1389->cache_age;
    int v1664 = 4 + ((((int)((unsigned int)((int)((unsigned int)(v1395 + 68) >> 2)) >> 1)) & 3) * 2);
    int v1514 = v1513[v1664];
    int * v1515 = v1389->cache_tags;
    int v1516 = v1515[v1664];
    int v1517 = v1513[v1572];
    int v1518 = v1515[v1572];
    int * v1519 = v1389->cache_dirty;
    int v1667 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v1395 + 68) >> 2)) >> 1)) & 3) * 2)) + ((((v1514 + ((~(((v1516 ^ -1) | (-(v1516 ^ -1))) >> 31)) & 2)) - (v1517 + ((~(((v1518 ^ -1) | (-(v1518 ^ -1))) >> 31)) & 2))) >> 31) & 1);
    int v1520 = v1519[v1667];
    bool v1668 = !(v1520 == 0);
    if (v1668) {
      int * v1521 = v1389->cache_tags;
      int v1522 = v1521[v1667];
      int * v1523 = v1389->cache_vals;
      int v1671 = ((4 + ((((int)((unsigned int)((int)((unsigned int)(v1395 + 68) >> 2)) >> 1)) & 3) * 2)) + ((((v1514 + ((~(((v1516 ^ -1) | (-(v1516 ^ -1))) >> 31)) & 2)) - (v1517 + ((~(((v1518 ^ -1) | (-(v1518 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
      int v1524 = v1523[v1671];
      int v1672 = (((4 + ((((int)((unsigned int)((int)((unsigned int)(v1395 + 68) >> 2)) >> 1)) & 3) * 2)) + ((((v1514 + ((~(((v1516 ^ -1) | (-(v1516 ^ -1))) >> 31)) & 2)) - (v1517 + ((~(((v1518 ^ -1) | (-(v1518 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
      int v1525 = v1523[v1672];
      int * v1526 = v1389->mem;
      int v1674 = v1522 * 2;
      v1526[v1674] = v1524;
      int * v1528 = v1389->mem;
      int v1677 = (v1522 * 2) + 1;
      v1528[v1677] = v1525;
      ;
    } else {
      ;
    }
    int * v1533 = v1389->mem;
    int v1682 = ((int)((unsigned int)((int)((unsigned int)(v1395 + 68) >> 2)) >> 1)) * 2;
    int v1534 = v1533[v1682];
    int v1683 = (((int)((unsigned int)((int)((unsigned int)(v1395 + 68) >> 2)) >> 1)) * 2) + 1;
    int v1535 = v1533[v1683];
    int * v1536 = v1389->cache_vals;
    int v1685 = ((4 + ((((int)((unsigned int)((int)((unsigned int)(v1395 + 68) >> 2)) >> 1)) & 3) * 2)) + ((((v1514 + ((~(((v1516 ^ -1) | (-(v1516 ^ -1))) >> 31)) & 2)) - (v1517 + ((~(((v1518 ^ -1) | (-(v1518 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
    v1536[v1685] = v1534;
    int * v1538 = v1389->cache_vals;
    int v1688 = (((4 + ((((int)((unsigned int)((int)((unsigned int)(v1395 + 68) >> 2)) >> 1)) & 3) * 2)) + ((((v1514 + ((~(((v1516 ^ -1) | (-(v1516 ^ -1))) >> 31)) & 2)) - (v1517 + ((~(((v1518 ^ -1) | (-(v1518 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
    v1538[v1688] = v1535;
    int * v1540 = v1389->cache_tags;
    int v1691 = (int)((unsigned int)((int)((unsigned int)(v1395 + 68) >> 2)) >> 1);
    v1540[v1667] = v1691;
    int * v1542 = v1389->cache_dirty;
    v1542[v1667] = 0;
    int * v1544 = v1389->cache_age;
    v1544[v1667] = 1;
    int * v1546 = v1389->cache_age;
    int v1547 = v1546[v1667];
    int v1548 = v1546[v1571];
    int v1697 = v1548 + ((int)((unsigned int)(v1548 - v1547) >> 31));
    v1546[v1571] = v1697;
    int * v1550 = v1389->cache_age;
    int v1551 = v1550[v1572];
    int v1699 = v1551 + ((int)((unsigned int)(v1551 - v1547) >> 31));
    v1550[v1572] = v1699;
    int * v1553 = v1389->cache_age;
    v1553[v1667] = 0;
    v1556 = v1667;
  }
  int * v1557 = v1389->cache_vals;
  int v1702 = (v1556 * 2) + (((int)((unsigned int)(v1395 + 68) >> 2)) & 1);
  v1557[v1702] = v1397;
  int * v1559 = v1389->cache_dirty;
  v1559[v1556] = 1;
  struct StateT * v1561 = slot_13(v1389);
  return v1561;
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

struct StateT * slot_38(struct StateT * v2379) {
  int * v2380 = v2379->saved_regs;
  int * v2381 = v2379->regs;
  int v2382 = v2381[10];
  v2380[10] = v2382;
  int v2384 = v2379->timer;
  int v2399 = v2384 + 1;
  v2379->timer = v2399;
  int * v2386 = v2379->reg_ready;
  int v2387 = v2386[10];
  int * v2388 = v2379->regs;
  int v2389 = v2388[10];
  int v2402 = (v2387 + ((v2384 - v2387) & (~((v2384 - v2387) >> 31)))) + 1;
  v2386[10] = v2402;
  int * v2391 = v2379->regs;
  int v2404 = v2389 << 2;
  v2391[10] = v2404;
  struct StateT * v2393 = slot_40(v2379);
  return v2393;
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

struct StateT * slot_42(struct StateT * v2436) {
  int v2437 = v2436->timer;
  int v2549 = v2437 + 1;
  v2436->timer = v2549;
  int * v2439 = v2436->reg_ready;
  int v2440 = v2439[10];
  int * v2441 = v2436->regs;
  int v2442 = v2441[10];
  int * v2443 = v2436->cache_tags;
  int v2554 = (((int)((unsigned int)((int)((unsigned int)v2442 >> 2)) >> 1)) & 1) * 2;
  int v2444 = v2443[v2554];
  int v2555 = ((((int)((unsigned int)((int)((unsigned int)v2442 >> 2)) >> 1)) & 1) * 2) + 1;
  int v2445 = v2443[v2555];
  int v2556 = 4 + ((((int)((unsigned int)((int)((unsigned int)v2442 >> 2)) >> 1)) & 3) * 2);
  int v2446 = v2443[v2556];
  int v2557 = (4 + ((((int)((unsigned int)((int)((unsigned int)v2442 >> 2)) >> 1)) & 3) * 2)) + 1;
  int v2447 = v2443[v2557];
  int * v2448 = v2436->cache_vals;
  bool v2558 = !(((~(((v2444 ^ ((int)((unsigned int)((int)((unsigned int)v2442 >> 2)) >> 1))) | (-(v2444 ^ ((int)((unsigned int)((int)((unsigned int)v2442 >> 2)) >> 1))))) >> 31)) | (~(((v2445 ^ ((int)((unsigned int)((int)((unsigned int)v2442 >> 2)) >> 1))) | (-(v2445 ^ ((int)((unsigned int)((int)((unsigned int)v2442 >> 2)) >> 1))))) >> 31))) == 0);
  int v2541;
  if (v2558) {
    int * v2449 = v2436->cache_age;
    int v2560 = ((((int)((unsigned int)((int)((unsigned int)v2442 >> 2)) >> 1)) & 1) * 2) + ((~(((v2445 ^ ((int)((unsigned int)((int)((unsigned int)v2442 >> 2)) >> 1))) | (-(v2445 ^ ((int)((unsigned int)((int)((unsigned int)v2442 >> 2)) >> 1))))) >> 31)) & 1);
    int v2450 = v2449[v2560];
    int v2451 = v2449[v2554];
    int v2561 = v2451 + ((int)((unsigned int)(v2451 - v2450) >> 31));
    v2449[v2554] = v2561;
    int * v2453 = v2436->cache_age;
    int v2454 = v2453[v2555];
    int v2563 = v2454 + ((int)((unsigned int)(v2454 - v2450) >> 31));
    v2453[v2555] = v2563;
    int * v2456 = v2436->cache_age;
    v2456[v2560] = 0;
    v2541 = v2560;
  } else {
    int * v2459 = v2436->cache_age;
    int v2567 = (((int)((unsigned int)((int)((unsigned int)v2442 >> 2)) >> 1)) & 1) * 2;
    int v2460 = v2459[v2567];
    int * v2461 = v2436->cache_tags;
    int v2462 = v2461[v2567];
    int v2463 = v2459[v2555];
    int v2464 = v2461[v2555];
    bool v2569 = !(((~(((v2446 ^ ((int)((unsigned int)((int)((unsigned int)v2442 >> 2)) >> 1))) | (-(v2446 ^ ((int)((unsigned int)((int)((unsigned int)v2442 >> 2)) >> 1))))) >> 31)) | (~(((v2447 ^ ((int)((unsigned int)((int)((unsigned int)v2442 >> 2)) >> 1))) | (-(v2447 ^ ((int)((unsigned int)((int)((unsigned int)v2442 >> 2)) >> 1))))) >> 31))) == 0);
    int v2518;
    if (v2569) {
      int * v2465 = v2436->cache_age;
      int v2571 = (4 + ((((int)((unsigned int)((int)((unsigned int)v2442 >> 2)) >> 1)) & 3) * 2)) + ((~(((v2447 ^ ((int)((unsigned int)((int)((unsigned int)v2442 >> 2)) >> 1))) | (-(v2447 ^ ((int)((unsigned int)((int)((unsigned int)v2442 >> 2)) >> 1))))) >> 31)) & 1);
      int v2466 = v2465[v2571];
      int v2467 = v2465[v2556];
      int v2572 = v2467 + ((int)((unsigned int)(v2467 - v2466) >> 31));
      v2465[v2556] = v2572;
      int * v2469 = v2436->cache_age;
      int v2470 = v2469[v2557];
      int v2574 = v2470 + ((int)((unsigned int)(v2470 - v2466) >> 31));
      v2469[v2557] = v2574;
      int * v2472 = v2436->cache_age;
      v2472[v2571] = 0;
      v2518 = v2571;
    } else {
      int * v2475 = v2436->cache_age;
      int v2578 = 4 + ((((int)((unsigned int)((int)((unsigned int)v2442 >> 2)) >> 1)) & 3) * 2);
      int v2476 = v2475[v2578];
      int * v2477 = v2436->cache_tags;
      int v2478 = v2477[v2578];
      int v2479 = v2475[v2557];
      int v2480 = v2477[v2557];
      int * v2481 = v2436->cache_dirty;
      int v2581 = (4 + ((((int)((unsigned int)((int)((unsigned int)v2442 >> 2)) >> 1)) & 3) * 2)) + ((((v2476 + ((~(((v2478 ^ -1) | (-(v2478 ^ -1))) >> 31)) & 2)) - (v2479 + ((~(((v2480 ^ -1) | (-(v2480 ^ -1))) >> 31)) & 2))) >> 31) & 1);
      int v2482 = v2481[v2581];
      bool v2582 = !(v2482 == 0);
      if (v2582) {
        int * v2483 = v2436->cache_tags;
        int v2484 = v2483[v2581];
        int * v2485 = v2436->cache_vals;
        int v2585 = ((4 + ((((int)((unsigned int)((int)((unsigned int)v2442 >> 2)) >> 1)) & 3) * 2)) + ((((v2476 + ((~(((v2478 ^ -1) | (-(v2478 ^ -1))) >> 31)) & 2)) - (v2479 + ((~(((v2480 ^ -1) | (-(v2480 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
        int v2486 = v2485[v2585];
        int v2586 = (((4 + ((((int)((unsigned int)((int)((unsigned int)v2442 >> 2)) >> 1)) & 3) * 2)) + ((((v2476 + ((~(((v2478 ^ -1) | (-(v2478 ^ -1))) >> 31)) & 2)) - (v2479 + ((~(((v2480 ^ -1) | (-(v2480 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
        int v2487 = v2485[v2586];
        int * v2488 = v2436->mem;
        int v2588 = v2484 * 2;
        v2488[v2588] = v2486;
        int * v2490 = v2436->mem;
        int v2591 = (v2484 * 2) + 1;
        v2490[v2591] = v2487;
        ;
      } else {
        ;
      }
      int * v2495 = v2436->mem;
      int v2596 = ((int)((unsigned int)((int)((unsigned int)v2442 >> 2)) >> 1)) * 2;
      int v2496 = v2495[v2596];
      int v2597 = (((int)((unsigned int)((int)((unsigned int)v2442 >> 2)) >> 1)) * 2) + 1;
      int v2497 = v2495[v2597];
      int * v2498 = v2436->cache_vals;
      int v2599 = ((4 + ((((int)((unsigned int)((int)((unsigned int)v2442 >> 2)) >> 1)) & 3) * 2)) + ((((v2476 + ((~(((v2478 ^ -1) | (-(v2478 ^ -1))) >> 31)) & 2)) - (v2479 + ((~(((v2480 ^ -1) | (-(v2480 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
      v2498[v2599] = v2496;
      int * v2500 = v2436->cache_vals;
      int v2602 = (((4 + ((((int)((unsigned int)((int)((unsigned int)v2442 >> 2)) >> 1)) & 3) * 2)) + ((((v2476 + ((~(((v2478 ^ -1) | (-(v2478 ^ -1))) >> 31)) & 2)) - (v2479 + ((~(((v2480 ^ -1) | (-(v2480 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
      v2500[v2602] = v2497;
      int * v2502 = v2436->cache_tags;
      int v2605 = (int)((unsigned int)((int)((unsigned int)v2442 >> 2)) >> 1);
      v2502[v2581] = v2605;
      int * v2504 = v2436->cache_dirty;
      v2504[v2581] = 0;
      int * v2506 = v2436->cache_age;
      v2506[v2581] = 1;
      int * v2508 = v2436->cache_age;
      int v2509 = v2508[v2581];
      int v2510 = v2508[v2556];
      int v2611 = v2510 + ((int)((unsigned int)(v2510 - v2509) >> 31));
      v2508[v2556] = v2611;
      int * v2512 = v2436->cache_age;
      int v2513 = v2512[v2557];
      int v2613 = v2513 + ((int)((unsigned int)(v2513 - v2509) >> 31));
      v2512[v2557] = v2613;
      int * v2515 = v2436->cache_age;
      v2515[v2581] = 0;
      v2518 = v2581;
    }
    int * v2519 = v2436->cache_vals;
    int v2616 = v2518 * 2;
    int v2520 = v2519[v2616];
    int v2617 = (v2518 * 2) + 1;
    int v2521 = v2519[v2617];
    int v2618 = (((((int)((unsigned int)((int)((unsigned int)v2442 >> 2)) >> 1)) & 1) * 2) + ((((v2460 + ((~(((v2462 ^ -1) | (-(v2462 ^ -1))) >> 31)) & 2)) - (v2463 + ((~(((v2464 ^ -1) | (-(v2464 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
    v2519[v2618] = v2520;
    int * v2523 = v2436->cache_vals;
    int v2621 = ((((((int)((unsigned int)((int)((unsigned int)v2442 >> 2)) >> 1)) & 1) * 2) + ((((v2460 + ((~(((v2462 ^ -1) | (-(v2462 ^ -1))) >> 31)) & 2)) - (v2463 + ((~(((v2464 ^ -1) | (-(v2464 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
    v2523[v2621] = v2521;
    int * v2525 = v2436->cache_tags;
    int v2624 = ((((int)((unsigned int)((int)((unsigned int)v2442 >> 2)) >> 1)) & 1) * 2) + ((((v2460 + ((~(((v2462 ^ -1) | (-(v2462 ^ -1))) >> 31)) & 2)) - (v2463 + ((~(((v2464 ^ -1) | (-(v2464 ^ -1))) >> 31)) & 2))) >> 31) & 1);
    int v2625 = (int)((unsigned int)((int)((unsigned int)v2442 >> 2)) >> 1);
    v2525[v2624] = v2625;
    int * v2527 = v2436->cache_dirty;
    v2527[v2624] = 0;
    int * v2529 = v2436->cache_age;
    v2529[v2624] = 1;
    int * v2531 = v2436->cache_age;
    int v2532 = v2531[v2624];
    int v2533 = v2531[v2554];
    int v2631 = v2533 + ((int)((unsigned int)(v2533 - v2532) >> 31));
    v2531[v2554] = v2631;
    int * v2535 = v2436->cache_age;
    int v2536 = v2535[v2555];
    int v2633 = v2536 + ((int)((unsigned int)(v2536 - v2532) >> 31));
    v2535[v2555] = v2633;
    int * v2538 = v2436->cache_age;
    v2538[v2624] = 0;
    v2541 = v2624;
  }
  int v2636 = (v2541 * 2) + (((int)((unsigned int)v2442 >> 2)) & 1);
  int v2542 = v2448[v2636];
  int * v2543 = v2436->reg_ready;
  int v2638 = ((v2440 + ((v2437 - v2440) & (~((v2437 - v2440) >> 31)))) + 1) + ((100 ^ (((~(((v2446 ^ ((int)((unsigned int)((int)((unsigned int)v2442 >> 2)) >> 1))) | (-(v2446 ^ ((int)((unsigned int)((int)((unsigned int)v2442 >> 2)) >> 1))))) >> 31)) | (~(((v2447 ^ ((int)((unsigned int)((int)((unsigned int)v2442 >> 2)) >> 1))) | (-(v2447 ^ ((int)((unsigned int)((int)((unsigned int)v2442 >> 2)) >> 1))))) >> 31))) & 104)) ^ (((~(((v2444 ^ ((int)((unsigned int)((int)((unsigned int)v2442 >> 2)) >> 1))) | (-(v2444 ^ ((int)((unsigned int)((int)((unsigned int)v2442 >> 2)) >> 1))))) >> 31)) | (~(((v2445 ^ ((int)((unsigned int)((int)((unsigned int)v2442 >> 2)) >> 1))) | (-(v2445 ^ ((int)((unsigned int)((int)((unsigned int)v2442 >> 2)) >> 1))))) >> 31))) & (1 ^ (100 ^ (((~(((v2446 ^ ((int)((unsigned int)((int)((unsigned int)v2442 >> 2)) >> 1))) | (-(v2446 ^ ((int)((unsigned int)((int)((unsigned int)v2442 >> 2)) >> 1))))) >> 31)) | (~(((v2447 ^ ((int)((unsigned int)((int)((unsigned int)v2442 >> 2)) >> 1))) | (-(v2447 ^ ((int)((unsigned int)((int)((unsigned int)v2442 >> 2)) >> 1))))) >> 31))) & 104)))));
  v2543[10] = v2638;
  int * v2545 = v2436->regs;
  v2545[10] = v2542;
  struct StateT * v2547 = slot_43(v2436);
  return v2547;
}

struct StateT * slot_44(struct StateT * v2674) {
  int * v2675 = v2674->saved_regs;
  int v2676 = v2675[10];
  int * v2677 = v2674->regs;
  int v2678 = v2677[11];
  bool v2705 = (v2676 ^ -2147483648) < (v2678 ^ -2147483648);
  struct StateT * v2699;
  if (v2705) {
    struct StateT * v2679 = slot_32(v2674);
    v2699 = v2679;
  } else {
    int v2681 = v2674->timer;
    int v2708 = v2681 + 15;
    v2674->timer = v2708;
    int * v2683 = v2674->saved_regs;
    int v2684 = v2683[10];
    int * v2685 = v2674->regs;
    v2685[10] = v2684;
    int * v2687 = v2674->saved_regs;
    int v2688 = v2687[12];
    int * v2689 = v2674->regs;
    v2689[12] = v2688;
    int * v2691 = v2674->reg_ready;
    int v2692 = v2674->timer;
    v2691[10] = v2692;
    int * v2694 = v2674->reg_ready;
    int v2695 = v2674->timer;
    v2694[12] = v2695;
    struct StateT * v2697 = slot_45(v2674);
    v2699 = v2697;
  }
  return v2699;
}

struct StateT * slot_32(struct StateT * v1968) {
  int v1969 = v1968->timer;
  int v1973 = v1969 + 1;
  v1968->timer = v1973;
  struct StateT * v1971 = slot_33(v1968);
  return v1971;
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
    struct StateT * v941 = slot_45(v929);
    v945 = v941;
  } else {
    struct StateT * v943 = slot_19(v929);
    v945 = v943;
  }
  return v945;
}

struct StateT * slot_33(struct StateT * v1976) {
  int * v1977 = v1976->saved_regs;
  int * v1978 = v1976->regs;
  int v1979 = v1978[13];
  v1977[13] = v1979;
  int v1981 = v1976->timer;
  int v1996 = v1981 + 1;
  v1976->timer = v1996;
  int * v1983 = v1976->reg_ready;
  int v1984 = v1983[13];
  int * v1985 = v1976->regs;
  int v1986 = v1985[13];
  int v1999 = (v1984 + ((v1981 - v1984) & (~((v1981 - v1984) >> 31)))) + 1;
  v1983[13] = v1999;
  int * v1988 = v1976->regs;
  int v2001 = v1986 + -1;
  v1988[13] = v2001;
  struct StateT * v1990 = slot_34(v1976);
  return v1990;
}

struct StateT * slot_36(struct StateT * v2052) {
  int v2053 = v2052->timer;
  int v2057 = v2053 + 1;
  v2052->timer = v2057;
  struct StateT * v2055 = slot_38(v2052);
  return v2055;
}

struct StateT * snippet(struct StateT * v0) {
  struct StateT * v1 = slot_0(v0);
  int v2739 = v1->timer;
  int * v2740 = v1->reg_ready;
  int v2741 = v2740[0];
  int v2872 = v2741 + ((v2739 - v2741) & (~((v2739 - v2741) >> 31)));
  v1->timer = v2872;
  int v2743 = v1->timer;
  int * v2744 = v1->reg_ready;
  int v2745 = v2744[1];
  int v2875 = v2745 + ((v2743 - v2745) & (~((v2743 - v2745) >> 31)));
  v1->timer = v2875;
  int v2747 = v1->timer;
  int * v2748 = v1->reg_ready;
  int v2749 = v2748[2];
  int v2878 = v2749 + ((v2747 - v2749) & (~((v2747 - v2749) >> 31)));
  v1->timer = v2878;
  int v2751 = v1->timer;
  int * v2752 = v1->reg_ready;
  int v2753 = v2752[3];
  int v2881 = v2753 + ((v2751 - v2753) & (~((v2751 - v2753) >> 31)));
  v1->timer = v2881;
  int v2755 = v1->timer;
  int * v2756 = v1->reg_ready;
  int v2757 = v2756[4];
  int v2884 = v2757 + ((v2755 - v2757) & (~((v2755 - v2757) >> 31)));
  v1->timer = v2884;
  int v2759 = v1->timer;
  int * v2760 = v1->reg_ready;
  int v2761 = v2760[5];
  int v2887 = v2761 + ((v2759 - v2761) & (~((v2759 - v2761) >> 31)));
  v1->timer = v2887;
  int v2763 = v1->timer;
  int * v2764 = v1->reg_ready;
  int v2765 = v2764[6];
  int v2890 = v2765 + ((v2763 - v2765) & (~((v2763 - v2765) >> 31)));
  v1->timer = v2890;
  int v2767 = v1->timer;
  int * v2768 = v1->reg_ready;
  int v2769 = v2768[7];
  int v2893 = v2769 + ((v2767 - v2769) & (~((v2767 - v2769) >> 31)));
  v1->timer = v2893;
  int v2771 = v1->timer;
  int * v2772 = v1->reg_ready;
  int v2773 = v2772[8];
  int v2896 = v2773 + ((v2771 - v2773) & (~((v2771 - v2773) >> 31)));
  v1->timer = v2896;
  int v2775 = v1->timer;
  int * v2776 = v1->reg_ready;
  int v2777 = v2776[9];
  int v2899 = v2777 + ((v2775 - v2777) & (~((v2775 - v2777) >> 31)));
  v1->timer = v2899;
  int v2779 = v1->timer;
  int * v2780 = v1->reg_ready;
  int v2781 = v2780[10];
  int v2902 = v2781 + ((v2779 - v2781) & (~((v2779 - v2781) >> 31)));
  v1->timer = v2902;
  int v2783 = v1->timer;
  int * v2784 = v1->reg_ready;
  int v2785 = v2784[11];
  int v2905 = v2785 + ((v2783 - v2785) & (~((v2783 - v2785) >> 31)));
  v1->timer = v2905;
  int v2787 = v1->timer;
  int * v2788 = v1->reg_ready;
  int v2789 = v2788[12];
  int v2908 = v2789 + ((v2787 - v2789) & (~((v2787 - v2789) >> 31)));
  v1->timer = v2908;
  int v2791 = v1->timer;
  int * v2792 = v1->reg_ready;
  int v2793 = v2792[13];
  int v2911 = v2793 + ((v2791 - v2793) & (~((v2791 - v2793) >> 31)));
  v1->timer = v2911;
  int v2795 = v1->timer;
  int * v2796 = v1->reg_ready;
  int v2797 = v2796[14];
  int v2914 = v2797 + ((v2795 - v2797) & (~((v2795 - v2797) >> 31)));
  v1->timer = v2914;
  int v2799 = v1->timer;
  int * v2800 = v1->reg_ready;
  int v2801 = v2800[15];
  int v2917 = v2801 + ((v2799 - v2801) & (~((v2799 - v2801) >> 31)));
  v1->timer = v2917;
  int v2803 = v1->timer;
  int * v2804 = v1->reg_ready;
  int v2805 = v2804[16];
  int v2920 = v2805 + ((v2803 - v2805) & (~((v2803 - v2805) >> 31)));
  v1->timer = v2920;
  int v2807 = v1->timer;
  int * v2808 = v1->reg_ready;
  int v2809 = v2808[17];
  int v2923 = v2809 + ((v2807 - v2809) & (~((v2807 - v2809) >> 31)));
  v1->timer = v2923;
  int v2811 = v1->timer;
  int * v2812 = v1->reg_ready;
  int v2813 = v2812[18];
  int v2926 = v2813 + ((v2811 - v2813) & (~((v2811 - v2813) >> 31)));
  v1->timer = v2926;
  int v2815 = v1->timer;
  int * v2816 = v1->reg_ready;
  int v2817 = v2816[19];
  int v2929 = v2817 + ((v2815 - v2817) & (~((v2815 - v2817) >> 31)));
  v1->timer = v2929;
  int v2819 = v1->timer;
  int * v2820 = v1->reg_ready;
  int v2821 = v2820[20];
  int v2932 = v2821 + ((v2819 - v2821) & (~((v2819 - v2821) >> 31)));
  v1->timer = v2932;
  int v2823 = v1->timer;
  int * v2824 = v1->reg_ready;
  int v2825 = v2824[21];
  int v2935 = v2825 + ((v2823 - v2825) & (~((v2823 - v2825) >> 31)));
  v1->timer = v2935;
  int v2827 = v1->timer;
  int * v2828 = v1->reg_ready;
  int v2829 = v2828[22];
  int v2938 = v2829 + ((v2827 - v2829) & (~((v2827 - v2829) >> 31)));
  v1->timer = v2938;
  int v2831 = v1->timer;
  int * v2832 = v1->reg_ready;
  int v2833 = v2832[23];
  int v2941 = v2833 + ((v2831 - v2833) & (~((v2831 - v2833) >> 31)));
  v1->timer = v2941;
  int v2835 = v1->timer;
  int * v2836 = v1->reg_ready;
  int v2837 = v2836[24];
  int v2944 = v2837 + ((v2835 - v2837) & (~((v2835 - v2837) >> 31)));
  v1->timer = v2944;
  int v2839 = v1->timer;
  int * v2840 = v1->reg_ready;
  int v2841 = v2840[25];
  int v2947 = v2841 + ((v2839 - v2841) & (~((v2839 - v2841) >> 31)));
  v1->timer = v2947;
  int v2843 = v1->timer;
  int * v2844 = v1->reg_ready;
  int v2845 = v2844[26];
  int v2950 = v2845 + ((v2843 - v2845) & (~((v2843 - v2845) >> 31)));
  v1->timer = v2950;
  int v2847 = v1->timer;
  int * v2848 = v1->reg_ready;
  int v2849 = v2848[27];
  int v2953 = v2849 + ((v2847 - v2849) & (~((v2847 - v2849) >> 31)));
  v1->timer = v2953;
  int v2851 = v1->timer;
  int * v2852 = v1->reg_ready;
  int v2853 = v2852[28];
  int v2956 = v2853 + ((v2851 - v2853) & (~((v2851 - v2853) >> 31)));
  v1->timer = v2956;
  int v2855 = v1->timer;
  int * v2856 = v1->reg_ready;
  int v2857 = v2856[29];
  int v2959 = v2857 + ((v2855 - v2857) & (~((v2855 - v2857) >> 31)));
  v1->timer = v2959;
  int v2859 = v1->timer;
  int * v2860 = v1->reg_ready;
  int v2861 = v2860[30];
  int v2962 = v2861 + ((v2859 - v2861) & (~((v2859 - v2861) >> 31)));
  v1->timer = v2962;
  int v2863 = v1->timer;
  int * v2864 = v1->reg_ready;
  int v2865 = v2864[31];
  int v2965 = v2865 + ((v2863 - v2865) & (~((v2863 - v2865) >> 31)));
  v1->timer = v2965;
  return v1;
}

struct StateT * slot_40(struct StateT * v2412) {
  int v2413 = v2412->timer;
  int v2426 = v2413 + 1;
  v2412->timer = v2426;
  int * v2415 = v2412->reg_ready;
  int v2416 = v2415[14];
  int * v2417 = v2412->regs;
  int v2418 = v2417[14];
  int v2419 = v2415[10];
  int v2420 = v2417[10];
  int v2431 = (v2419 + (((v2416 + ((v2413 - v2416) & (~((v2413 - v2416) >> 31)))) - v2419) & (~(((v2416 + ((v2413 - v2416) & (~((v2413 - v2416) >> 31)))) - v2419) >> 31)))) + 1;
  v2415[10] = v2431;
  int * v2422 = v2412->regs;
  int v2433 = v2418 + v2420;
  v2422[10] = v2433;
  struct StateT * v2424 = slot_42(v2412);
  return v2424;
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

struct StateT * slot_27(struct StateT * v1708) {
  int v1709 = v1708->timer;
  int v1722 = v1709 + 1;
  v1708->timer = v1722;
  int * v1711 = v1708->reg_ready;
  int v1712 = v1711[14];
  int * v1713 = v1708->regs;
  int v1714 = v1713[14];
  int v1715 = v1711[10];
  int v1716 = v1713[10];
  int v1727 = (v1715 + (((v1712 + ((v1709 - v1712) & (~((v1709 - v1712) >> 31)))) - v1715) & (~(((v1712 + ((v1709 - v1712) & (~((v1709 - v1712) >> 31)))) - v1715) >> 31)))) + 1;
  v1711[10] = v1727;
  int * v1718 = v1708->regs;
  int v1729 = v1714 + v1716;
  v1718[10] = v1729;
  struct StateT * v1720 = slot_29(v1708);
  return v1720;
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