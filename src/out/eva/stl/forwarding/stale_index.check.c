// verify: leak (Eva should report untainted_timer: unknown) [unroll 65]
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

struct StateT * snippet(struct StateT * v0);
struct StateT * slot_1(struct StateT * v17);
struct StateT * slot_8(struct StateT * v2126);
struct StateT * slot_6(struct StateT * v1718);
struct StateT * slot_5(struct StateT * v1520);
struct StateT * slot_4(struct StateT * v353);
struct StateT * slot_2(struct StateT * v32);
struct StateT * slot_7(struct StateT * v1922);
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

struct StateT * slot_8(struct StateT * v2126) {
  int v2127 = v2126->timer;
  int v2236 = v2127 + 1;
  v2126->timer = v2236;
  int * v2129 = v2126->regs;
  int v2130 = v2129[11];
  int * v2131 = v2126->cache_tags;
  int v2240 = (((int)((unsigned int)((int)((unsigned int)v2130 >> 2)) >> 1)) & 1) * 2;
  int v2132 = v2131[v2240];
  int v2241 = ((((int)((unsigned int)((int)((unsigned int)v2130 >> 2)) >> 1)) & 1) * 2) + 1;
  int v2133 = v2131[v2241];
  int v2242 = 4 + ((((int)((unsigned int)((int)((unsigned int)v2130 >> 2)) >> 1)) & 3) * 2);
  int v2134 = v2131[v2242];
  int v2243 = (4 + ((((int)((unsigned int)((int)((unsigned int)v2130 >> 2)) >> 1)) & 3) * 2)) + 1;
  int v2135 = v2131[v2243];
  int v2136 = v2126->timer;
  int v2244 = v2136 + ((100 ^ (((~(((v2134 ^ ((int)((unsigned int)((int)((unsigned int)v2130 >> 2)) >> 1))) | (-(v2134 ^ ((int)((unsigned int)((int)((unsigned int)v2130 >> 2)) >> 1))))) >> 31)) | (~(((v2135 ^ ((int)((unsigned int)((int)((unsigned int)v2130 >> 2)) >> 1))) | (-(v2135 ^ ((int)((unsigned int)((int)((unsigned int)v2130 >> 2)) >> 1))))) >> 31))) & 104)) ^ (((~(((v2132 ^ ((int)((unsigned int)((int)((unsigned int)v2130 >> 2)) >> 1))) | (-(v2132 ^ ((int)((unsigned int)((int)((unsigned int)v2130 >> 2)) >> 1))))) >> 31)) | (~(((v2133 ^ ((int)((unsigned int)((int)((unsigned int)v2130 >> 2)) >> 1))) | (-(v2133 ^ ((int)((unsigned int)((int)((unsigned int)v2130 >> 2)) >> 1))))) >> 31))) & (1 ^ (100 ^ (((~(((v2134 ^ ((int)((unsigned int)((int)((unsigned int)v2130 >> 2)) >> 1))) | (-(v2134 ^ ((int)((unsigned int)((int)((unsigned int)v2130 >> 2)) >> 1))))) >> 31)) | (~(((v2135 ^ ((int)((unsigned int)((int)((unsigned int)v2130 >> 2)) >> 1))) | (-(v2135 ^ ((int)((unsigned int)((int)((unsigned int)v2130 >> 2)) >> 1))))) >> 31))) & 104)))));
  v2126->timer = v2244;
  int * v2138 = v2126->cache_vals;
  bool v2245 = !(((~(((v2132 ^ ((int)((unsigned int)((int)((unsigned int)v2130 >> 2)) >> 1))) | (-(v2132 ^ ((int)((unsigned int)((int)((unsigned int)v2130 >> 2)) >> 1))))) >> 31)) | (~(((v2133 ^ ((int)((unsigned int)((int)((unsigned int)v2130 >> 2)) >> 1))) | (-(v2133 ^ ((int)((unsigned int)((int)((unsigned int)v2130 >> 2)) >> 1))))) >> 31))) == 0);
  int v2231;
  if (v2245) {
    int * v2139 = v2126->cache_age;
    int v2247 = ((((int)((unsigned int)((int)((unsigned int)v2130 >> 2)) >> 1)) & 1) * 2) + ((~(((v2133 ^ ((int)((unsigned int)((int)((unsigned int)v2130 >> 2)) >> 1))) | (-(v2133 ^ ((int)((unsigned int)((int)((unsigned int)v2130 >> 2)) >> 1))))) >> 31)) & 1);
    int v2140 = v2139[v2247];
    int v2141 = v2139[v2240];
    int v2248 = v2141 + ((int)((unsigned int)(v2141 - v2140) >> 31));
    v2139[v2240] = v2248;
    int * v2143 = v2126->cache_age;
    int v2144 = v2143[v2241];
    int v2250 = v2144 + ((int)((unsigned int)(v2144 - v2140) >> 31));
    v2143[v2241] = v2250;
    int * v2146 = v2126->cache_age;
    v2146[v2247] = 0;
    v2231 = v2247;
  } else {
    int * v2149 = v2126->cache_age;
    int v2254 = (((int)((unsigned int)((int)((unsigned int)v2130 >> 2)) >> 1)) & 1) * 2;
    int v2150 = v2149[v2254];
    int * v2151 = v2126->cache_tags;
    int v2152 = v2151[v2254];
    int v2153 = v2149[v2241];
    int v2154 = v2151[v2241];
    bool v2256 = !(((~(((v2134 ^ ((int)((unsigned int)((int)((unsigned int)v2130 >> 2)) >> 1))) | (-(v2134 ^ ((int)((unsigned int)((int)((unsigned int)v2130 >> 2)) >> 1))))) >> 31)) | (~(((v2135 ^ ((int)((unsigned int)((int)((unsigned int)v2130 >> 2)) >> 1))) | (-(v2135 ^ ((int)((unsigned int)((int)((unsigned int)v2130 >> 2)) >> 1))))) >> 31))) == 0);
    int v2208;
    if (v2256) {
      int * v2155 = v2126->cache_age;
      int v2258 = (4 + ((((int)((unsigned int)((int)((unsigned int)v2130 >> 2)) >> 1)) & 3) * 2)) + ((~(((v2135 ^ ((int)((unsigned int)((int)((unsigned int)v2130 >> 2)) >> 1))) | (-(v2135 ^ ((int)((unsigned int)((int)((unsigned int)v2130 >> 2)) >> 1))))) >> 31)) & 1);
      int v2156 = v2155[v2258];
      int v2157 = v2155[v2242];
      int v2259 = v2157 + ((int)((unsigned int)(v2157 - v2156) >> 31));
      v2155[v2242] = v2259;
      int * v2159 = v2126->cache_age;
      int v2160 = v2159[v2243];
      int v2261 = v2160 + ((int)((unsigned int)(v2160 - v2156) >> 31));
      v2159[v2243] = v2261;
      int * v2162 = v2126->cache_age;
      v2162[v2258] = 0;
      v2208 = v2258;
    } else {
      int * v2165 = v2126->cache_age;
      int v2265 = 4 + ((((int)((unsigned int)((int)((unsigned int)v2130 >> 2)) >> 1)) & 3) * 2);
      int v2166 = v2165[v2265];
      int * v2167 = v2126->cache_tags;
      int v2168 = v2167[v2265];
      int v2169 = v2165[v2243];
      int v2170 = v2167[v2243];
      int * v2171 = v2126->cache_dirty;
      int v2268 = (4 + ((((int)((unsigned int)((int)((unsigned int)v2130 >> 2)) >> 1)) & 3) * 2)) + ((((v2166 + ((~(((v2168 ^ -1) | (-(v2168 ^ -1))) >> 31)) & 2)) - (v2169 + ((~(((v2170 ^ -1) | (-(v2170 ^ -1))) >> 31)) & 2))) >> 31) & 1);
      int v2172 = v2171[v2268];
      bool v2269 = !(v2172 == 0);
      if (v2269) {
        int * v2173 = v2126->cache_tags;
        int v2174 = v2173[v2268];
        int * v2175 = v2126->cache_vals;
        int v2272 = ((4 + ((((int)((unsigned int)((int)((unsigned int)v2130 >> 2)) >> 1)) & 3) * 2)) + ((((v2166 + ((~(((v2168 ^ -1) | (-(v2168 ^ -1))) >> 31)) & 2)) - (v2169 + ((~(((v2170 ^ -1) | (-(v2170 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
        int v2176 = v2175[v2272];
        int v2273 = (((4 + ((((int)((unsigned int)((int)((unsigned int)v2130 >> 2)) >> 1)) & 3) * 2)) + ((((v2166 + ((~(((v2168 ^ -1) | (-(v2168 ^ -1))) >> 31)) & 2)) - (v2169 + ((~(((v2170 ^ -1) | (-(v2170 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
        int v2177 = v2175[v2273];
        int * v2178 = v2126->mem;
        int v2275 = v2174 * 2;
        v2178[v2275] = v2176;
        int * v2180 = v2126->mem;
        int v2278 = (v2174 * 2) + 1;
        v2180[v2278] = v2177;
        ;
      } else {
        ;
      }
      int * v2185 = v2126->mem;
      int v2283 = ((int)((unsigned int)((int)((unsigned int)v2130 >> 2)) >> 1)) * 2;
      int v2186 = v2185[v2283];
      int v2284 = (((int)((unsigned int)((int)((unsigned int)v2130 >> 2)) >> 1)) * 2) + 1;
      int v2187 = v2185[v2284];
      int * v2188 = v2126->cache_vals;
      int v2286 = ((4 + ((((int)((unsigned int)((int)((unsigned int)v2130 >> 2)) >> 1)) & 3) * 2)) + ((((v2166 + ((~(((v2168 ^ -1) | (-(v2168 ^ -1))) >> 31)) & 2)) - (v2169 + ((~(((v2170 ^ -1) | (-(v2170 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
      v2188[v2286] = v2186;
      int * v2190 = v2126->cache_vals;
      int v2289 = (((4 + ((((int)((unsigned int)((int)((unsigned int)v2130 >> 2)) >> 1)) & 3) * 2)) + ((((v2166 + ((~(((v2168 ^ -1) | (-(v2168 ^ -1))) >> 31)) & 2)) - (v2169 + ((~(((v2170 ^ -1) | (-(v2170 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
      v2190[v2289] = v2187;
      int * v2192 = v2126->cache_tags;
      int v2292 = (int)((unsigned int)((int)((unsigned int)v2130 >> 2)) >> 1);
      v2192[v2268] = v2292;
      int * v2194 = v2126->cache_dirty;
      v2194[v2268] = 0;
      int * v2196 = v2126->cache_age;
      v2196[v2268] = 1;
      int * v2198 = v2126->cache_age;
      int v2199 = v2198[v2268];
      int v2200 = v2198[v2242];
      int v2298 = v2200 + ((int)((unsigned int)(v2200 - v2199) >> 31));
      v2198[v2242] = v2298;
      int * v2202 = v2126->cache_age;
      int v2203 = v2202[v2243];
      int v2300 = v2203 + ((int)((unsigned int)(v2203 - v2199) >> 31));
      v2202[v2243] = v2300;
      int * v2205 = v2126->cache_age;
      v2205[v2268] = 0;
      v2208 = v2268;
    }
    int * v2209 = v2126->cache_vals;
    int v2303 = v2208 * 2;
    int v2210 = v2209[v2303];
    int v2304 = (v2208 * 2) + 1;
    int v2211 = v2209[v2304];
    int v2305 = (((((int)((unsigned int)((int)((unsigned int)v2130 >> 2)) >> 1)) & 1) * 2) + ((((v2150 + ((~(((v2152 ^ -1) | (-(v2152 ^ -1))) >> 31)) & 2)) - (v2153 + ((~(((v2154 ^ -1) | (-(v2154 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
    v2209[v2305] = v2210;
    int * v2213 = v2126->cache_vals;
    int v2308 = ((((((int)((unsigned int)((int)((unsigned int)v2130 >> 2)) >> 1)) & 1) * 2) + ((((v2150 + ((~(((v2152 ^ -1) | (-(v2152 ^ -1))) >> 31)) & 2)) - (v2153 + ((~(((v2154 ^ -1) | (-(v2154 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
    v2213[v2308] = v2211;
    int * v2215 = v2126->cache_tags;
    int v2311 = ((((int)((unsigned int)((int)((unsigned int)v2130 >> 2)) >> 1)) & 1) * 2) + ((((v2150 + ((~(((v2152 ^ -1) | (-(v2152 ^ -1))) >> 31)) & 2)) - (v2153 + ((~(((v2154 ^ -1) | (-(v2154 ^ -1))) >> 31)) & 2))) >> 31) & 1);
    int v2312 = (int)((unsigned int)((int)((unsigned int)v2130 >> 2)) >> 1);
    v2215[v2311] = v2312;
    int * v2217 = v2126->cache_dirty;
    v2217[v2311] = 0;
    int * v2219 = v2126->cache_age;
    v2219[v2311] = 1;
    int * v2221 = v2126->cache_age;
    int v2222 = v2221[v2311];
    int v2223 = v2221[v2240];
    int v2318 = v2223 + ((int)((unsigned int)(v2223 - v2222) >> 31));
    v2221[v2240] = v2318;
    int * v2225 = v2126->cache_age;
    int v2226 = v2225[v2241];
    int v2320 = v2226 + ((int)((unsigned int)(v2226 - v2222) >> 31));
    v2225[v2241] = v2320;
    int * v2228 = v2126->cache_age;
    v2228[v2311] = 0;
    v2231 = v2311;
  }
  int v2323 = (v2231 * 2) + (((int)((unsigned int)v2130 >> 2)) & 1);
  int v2232 = v2138[v2323];
  int * v2233 = v2126->regs;
  v2233[12] = v2232;
  return v2126;
}

struct StateT * slot_6(struct StateT * v1718) {
  int v1719 = v1718->timer;
  int v1829 = v1719 + 1;
  v1718->timer = v1829;
  int * v1721 = v1718->regs;
  int v1722 = v1721[8];
  int * v1723 = v1718->cache_tags;
  int v1833 = (((int)((unsigned int)((int)((unsigned int)(v1722 + 40) >> 2)) >> 1)) & 1) * 2;
  int v1724 = v1723[v1833];
  int v1834 = ((((int)((unsigned int)((int)((unsigned int)(v1722 + 40) >> 2)) >> 1)) & 1) * 2) + 1;
  int v1725 = v1723[v1834];
  int v1835 = 4 + ((((int)((unsigned int)((int)((unsigned int)(v1722 + 40) >> 2)) >> 1)) & 3) * 2);
  int v1726 = v1723[v1835];
  int v1836 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v1722 + 40) >> 2)) >> 1)) & 3) * 2)) + 1;
  int v1727 = v1723[v1836];
  int v1728 = v1718->timer;
  int v1837 = v1728 + ((100 ^ (((~(((v1726 ^ ((int)((unsigned int)((int)((unsigned int)(v1722 + 40) >> 2)) >> 1))) | (-(v1726 ^ ((int)((unsigned int)((int)((unsigned int)(v1722 + 40) >> 2)) >> 1))))) >> 31)) | (~(((v1727 ^ ((int)((unsigned int)((int)((unsigned int)(v1722 + 40) >> 2)) >> 1))) | (-(v1727 ^ ((int)((unsigned int)((int)((unsigned int)(v1722 + 40) >> 2)) >> 1))))) >> 31))) & 104)) ^ (((~(((v1724 ^ ((int)((unsigned int)((int)((unsigned int)(v1722 + 40) >> 2)) >> 1))) | (-(v1724 ^ ((int)((unsigned int)((int)((unsigned int)(v1722 + 40) >> 2)) >> 1))))) >> 31)) | (~(((v1725 ^ ((int)((unsigned int)((int)((unsigned int)(v1722 + 40) >> 2)) >> 1))) | (-(v1725 ^ ((int)((unsigned int)((int)((unsigned int)(v1722 + 40) >> 2)) >> 1))))) >> 31))) & (1 ^ (100 ^ (((~(((v1726 ^ ((int)((unsigned int)((int)((unsigned int)(v1722 + 40) >> 2)) >> 1))) | (-(v1726 ^ ((int)((unsigned int)((int)((unsigned int)(v1722 + 40) >> 2)) >> 1))))) >> 31)) | (~(((v1727 ^ ((int)((unsigned int)((int)((unsigned int)(v1722 + 40) >> 2)) >> 1))) | (-(v1727 ^ ((int)((unsigned int)((int)((unsigned int)(v1722 + 40) >> 2)) >> 1))))) >> 31))) & 104)))));
  v1718->timer = v1837;
  int * v1730 = v1718->cache_vals;
  bool v1838 = !(((~(((v1724 ^ ((int)((unsigned int)((int)((unsigned int)(v1722 + 40) >> 2)) >> 1))) | (-(v1724 ^ ((int)((unsigned int)((int)((unsigned int)(v1722 + 40) >> 2)) >> 1))))) >> 31)) | (~(((v1725 ^ ((int)((unsigned int)((int)((unsigned int)(v1722 + 40) >> 2)) >> 1))) | (-(v1725 ^ ((int)((unsigned int)((int)((unsigned int)(v1722 + 40) >> 2)) >> 1))))) >> 31))) == 0);
  int v1823;
  if (v1838) {
    int * v1731 = v1718->cache_age;
    int v1840 = ((((int)((unsigned int)((int)((unsigned int)(v1722 + 40) >> 2)) >> 1)) & 1) * 2) + ((~(((v1725 ^ ((int)((unsigned int)((int)((unsigned int)(v1722 + 40) >> 2)) >> 1))) | (-(v1725 ^ ((int)((unsigned int)((int)((unsigned int)(v1722 + 40) >> 2)) >> 1))))) >> 31)) & 1);
    int v1732 = v1731[v1840];
    int v1733 = v1731[v1833];
    int v1841 = v1733 + ((int)((unsigned int)(v1733 - v1732) >> 31));
    v1731[v1833] = v1841;
    int * v1735 = v1718->cache_age;
    int v1736 = v1735[v1834];
    int v1843 = v1736 + ((int)((unsigned int)(v1736 - v1732) >> 31));
    v1735[v1834] = v1843;
    int * v1738 = v1718->cache_age;
    v1738[v1840] = 0;
    v1823 = v1840;
  } else {
    int * v1741 = v1718->cache_age;
    int v1847 = (((int)((unsigned int)((int)((unsigned int)(v1722 + 40) >> 2)) >> 1)) & 1) * 2;
    int v1742 = v1741[v1847];
    int * v1743 = v1718->cache_tags;
    int v1744 = v1743[v1847];
    int v1745 = v1741[v1834];
    int v1746 = v1743[v1834];
    bool v1849 = !(((~(((v1726 ^ ((int)((unsigned int)((int)((unsigned int)(v1722 + 40) >> 2)) >> 1))) | (-(v1726 ^ ((int)((unsigned int)((int)((unsigned int)(v1722 + 40) >> 2)) >> 1))))) >> 31)) | (~(((v1727 ^ ((int)((unsigned int)((int)((unsigned int)(v1722 + 40) >> 2)) >> 1))) | (-(v1727 ^ ((int)((unsigned int)((int)((unsigned int)(v1722 + 40) >> 2)) >> 1))))) >> 31))) == 0);
    int v1800;
    if (v1849) {
      int * v1747 = v1718->cache_age;
      int v1851 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v1722 + 40) >> 2)) >> 1)) & 3) * 2)) + ((~(((v1727 ^ ((int)((unsigned int)((int)((unsigned int)(v1722 + 40) >> 2)) >> 1))) | (-(v1727 ^ ((int)((unsigned int)((int)((unsigned int)(v1722 + 40) >> 2)) >> 1))))) >> 31)) & 1);
      int v1748 = v1747[v1851];
      int v1749 = v1747[v1835];
      int v1852 = v1749 + ((int)((unsigned int)(v1749 - v1748) >> 31));
      v1747[v1835] = v1852;
      int * v1751 = v1718->cache_age;
      int v1752 = v1751[v1836];
      int v1854 = v1752 + ((int)((unsigned int)(v1752 - v1748) >> 31));
      v1751[v1836] = v1854;
      int * v1754 = v1718->cache_age;
      v1754[v1851] = 0;
      v1800 = v1851;
    } else {
      int * v1757 = v1718->cache_age;
      int v1858 = 4 + ((((int)((unsigned int)((int)((unsigned int)(v1722 + 40) >> 2)) >> 1)) & 3) * 2);
      int v1758 = v1757[v1858];
      int * v1759 = v1718->cache_tags;
      int v1760 = v1759[v1858];
      int v1761 = v1757[v1836];
      int v1762 = v1759[v1836];
      int * v1763 = v1718->cache_dirty;
      int v1861 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v1722 + 40) >> 2)) >> 1)) & 3) * 2)) + ((((v1758 + ((~(((v1760 ^ -1) | (-(v1760 ^ -1))) >> 31)) & 2)) - (v1761 + ((~(((v1762 ^ -1) | (-(v1762 ^ -1))) >> 31)) & 2))) >> 31) & 1);
      int v1764 = v1763[v1861];
      bool v1862 = !(v1764 == 0);
      if (v1862) {
        int * v1765 = v1718->cache_tags;
        int v1766 = v1765[v1861];
        int * v1767 = v1718->cache_vals;
        int v1865 = ((4 + ((((int)((unsigned int)((int)((unsigned int)(v1722 + 40) >> 2)) >> 1)) & 3) * 2)) + ((((v1758 + ((~(((v1760 ^ -1) | (-(v1760 ^ -1))) >> 31)) & 2)) - (v1761 + ((~(((v1762 ^ -1) | (-(v1762 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
        int v1768 = v1767[v1865];
        int v1866 = (((4 + ((((int)((unsigned int)((int)((unsigned int)(v1722 + 40) >> 2)) >> 1)) & 3) * 2)) + ((((v1758 + ((~(((v1760 ^ -1) | (-(v1760 ^ -1))) >> 31)) & 2)) - (v1761 + ((~(((v1762 ^ -1) | (-(v1762 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
        int v1769 = v1767[v1866];
        int * v1770 = v1718->mem;
        int v1868 = v1766 * 2;
        v1770[v1868] = v1768;
        int * v1772 = v1718->mem;
        int v1871 = (v1766 * 2) + 1;
        v1772[v1871] = v1769;
        ;
      } else {
        ;
      }
      int * v1777 = v1718->mem;
      int v1876 = ((int)((unsigned int)((int)((unsigned int)(v1722 + 40) >> 2)) >> 1)) * 2;
      int v1778 = v1777[v1876];
      int v1877 = (((int)((unsigned int)((int)((unsigned int)(v1722 + 40) >> 2)) >> 1)) * 2) + 1;
      int v1779 = v1777[v1877];
      int * v1780 = v1718->cache_vals;
      int v1879 = ((4 + ((((int)((unsigned int)((int)((unsigned int)(v1722 + 40) >> 2)) >> 1)) & 3) * 2)) + ((((v1758 + ((~(((v1760 ^ -1) | (-(v1760 ^ -1))) >> 31)) & 2)) - (v1761 + ((~(((v1762 ^ -1) | (-(v1762 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
      v1780[v1879] = v1778;
      int * v1782 = v1718->cache_vals;
      int v1882 = (((4 + ((((int)((unsigned int)((int)((unsigned int)(v1722 + 40) >> 2)) >> 1)) & 3) * 2)) + ((((v1758 + ((~(((v1760 ^ -1) | (-(v1760 ^ -1))) >> 31)) & 2)) - (v1761 + ((~(((v1762 ^ -1) | (-(v1762 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
      v1782[v1882] = v1779;
      int * v1784 = v1718->cache_tags;
      int v1885 = (int)((unsigned int)((int)((unsigned int)(v1722 + 40) >> 2)) >> 1);
      v1784[v1861] = v1885;
      int * v1786 = v1718->cache_dirty;
      v1786[v1861] = 0;
      int * v1788 = v1718->cache_age;
      v1788[v1861] = 1;
      int * v1790 = v1718->cache_age;
      int v1791 = v1790[v1861];
      int v1792 = v1790[v1835];
      int v1891 = v1792 + ((int)((unsigned int)(v1792 - v1791) >> 31));
      v1790[v1835] = v1891;
      int * v1794 = v1718->cache_age;
      int v1795 = v1794[v1836];
      int v1893 = v1795 + ((int)((unsigned int)(v1795 - v1791) >> 31));
      v1794[v1836] = v1893;
      int * v1797 = v1718->cache_age;
      v1797[v1861] = 0;
      v1800 = v1861;
    }
    int * v1801 = v1718->cache_vals;
    int v1896 = v1800 * 2;
    int v1802 = v1801[v1896];
    int v1897 = (v1800 * 2) + 1;
    int v1803 = v1801[v1897];
    int v1898 = (((((int)((unsigned int)((int)((unsigned int)(v1722 + 40) >> 2)) >> 1)) & 1) * 2) + ((((v1742 + ((~(((v1744 ^ -1) | (-(v1744 ^ -1))) >> 31)) & 2)) - (v1745 + ((~(((v1746 ^ -1) | (-(v1746 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
    v1801[v1898] = v1802;
    int * v1805 = v1718->cache_vals;
    int v1901 = ((((((int)((unsigned int)((int)((unsigned int)(v1722 + 40) >> 2)) >> 1)) & 1) * 2) + ((((v1742 + ((~(((v1744 ^ -1) | (-(v1744 ^ -1))) >> 31)) & 2)) - (v1745 + ((~(((v1746 ^ -1) | (-(v1746 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
    v1805[v1901] = v1803;
    int * v1807 = v1718->cache_tags;
    int v1904 = ((((int)((unsigned int)((int)((unsigned int)(v1722 + 40) >> 2)) >> 1)) & 1) * 2) + ((((v1742 + ((~(((v1744 ^ -1) | (-(v1744 ^ -1))) >> 31)) & 2)) - (v1745 + ((~(((v1746 ^ -1) | (-(v1746 ^ -1))) >> 31)) & 2))) >> 31) & 1);
    int v1905 = (int)((unsigned int)((int)((unsigned int)(v1722 + 40) >> 2)) >> 1);
    v1807[v1904] = v1905;
    int * v1809 = v1718->cache_dirty;
    v1809[v1904] = 0;
    int * v1811 = v1718->cache_age;
    v1811[v1904] = 1;
    int * v1813 = v1718->cache_age;
    int v1814 = v1813[v1904];
    int v1815 = v1813[v1833];
    int v1911 = v1815 + ((int)((unsigned int)(v1815 - v1814) >> 31));
    v1813[v1833] = v1911;
    int * v1817 = v1718->cache_age;
    int v1818 = v1817[v1834];
    int v1913 = v1818 + ((int)((unsigned int)(v1818 - v1814) >> 31));
    v1817[v1834] = v1913;
    int * v1820 = v1718->cache_age;
    v1820[v1904] = 0;
    v1823 = v1904;
  }
  int v1916 = (v1823 * 2) + (((int)((unsigned int)(v1722 + 40) >> 2)) & 1);
  int v1824 = v1730[v1916];
  int * v1825 = v1718->regs;
  v1825[9] = v1824;
  struct StateT * v1827 = slot_7(v1718);
  return v1827;
}

struct StateT * slot_5(struct StateT * v1520) {
  int v1521 = v1520->timer;
  int v1629 = v1521 + 1;
  v1520->timer = v1629;
  int * v1523 = v1520->cache_tags;
  int v1524 = v1523[2];
  int v1525 = v1523[3];
  int v1526 = v1523[10];
  int v1527 = v1523[11];
  int v1528 = v1520->timer;
  int v1635 = v1528 + ((100 ^ (((~(((v1526 ^ 7) | (-(v1526 ^ 7))) >> 31)) | (~(((v1527 ^ 7) | (-(v1527 ^ 7))) >> 31))) & 104)) ^ (((~(((v1524 ^ 7) | (-(v1524 ^ 7))) >> 31)) | (~(((v1525 ^ 7) | (-(v1525 ^ 7))) >> 31))) & (1 ^ (100 ^ (((~(((v1526 ^ 7) | (-(v1526 ^ 7))) >> 31)) | (~(((v1527 ^ 7) | (-(v1527 ^ 7))) >> 31))) & 104)))));
  v1520->timer = v1635;
  int * v1530 = v1520->cache_vals;
  bool v1636 = !(((~(((v1524 ^ 7) | (-(v1524 ^ 7))) >> 31)) | (~(((v1525 ^ 7) | (-(v1525 ^ 7))) >> 31))) == 0);
  int v1623;
  if (v1636) {
    int * v1531 = v1520->cache_age;
    int v1638 = 2 + ((~(((v1525 ^ 7) | (-(v1525 ^ 7))) >> 31)) & 1);
    int v1532 = v1531[v1638];
    int v1533 = v1531[2];
    int v1639 = v1533 + ((int)((unsigned int)(v1533 - v1532) >> 31));
    v1531[2] = v1639;
    int * v1535 = v1520->cache_age;
    int v1536 = v1535[3];
    int v1641 = v1536 + ((int)((unsigned int)(v1536 - v1532) >> 31));
    v1535[3] = v1641;
    int * v1538 = v1520->cache_age;
    v1538[v1638] = 0;
    v1623 = v1638;
  } else {
    int * v1541 = v1520->cache_age;
    int v1542 = v1541[2];
    int * v1543 = v1520->cache_tags;
    int v1544 = v1543[2];
    int v1545 = v1541[3];
    int v1546 = v1543[3];
    bool v1646 = !(((~(((v1526 ^ 7) | (-(v1526 ^ 7))) >> 31)) | (~(((v1527 ^ 7) | (-(v1527 ^ 7))) >> 31))) == 0);
    int v1600;
    if (v1646) {
      int * v1547 = v1520->cache_age;
      int v1648 = 10 + ((~(((v1527 ^ 7) | (-(v1527 ^ 7))) >> 31)) & 1);
      int v1548 = v1547[v1648];
      int v1549 = v1547[10];
      int v1649 = v1549 + ((int)((unsigned int)(v1549 - v1548) >> 31));
      v1547[10] = v1649;
      int * v1551 = v1520->cache_age;
      int v1552 = v1551[11];
      int v1651 = v1552 + ((int)((unsigned int)(v1552 - v1548) >> 31));
      v1551[11] = v1651;
      int * v1554 = v1520->cache_age;
      v1554[v1648] = 0;
      v1600 = v1648;
    } else {
      int * v1557 = v1520->cache_age;
      int v1558 = v1557[10];
      int * v1559 = v1520->cache_tags;
      int v1560 = v1559[10];
      int v1561 = v1557[11];
      int v1562 = v1559[11];
      int * v1563 = v1520->cache_dirty;
      int v1657 = 10 + ((((v1558 + ((~(((v1560 ^ -1) | (-(v1560 ^ -1))) >> 31)) & 2)) - (v1561 + ((~(((v1562 ^ -1) | (-(v1562 ^ -1))) >> 31)) & 2))) >> 31) & 1);
      int v1564 = v1563[v1657];
      bool v1658 = !(v1564 == 0);
      if (v1658) {
        int * v1565 = v1520->cache_tags;
        int v1566 = v1565[v1657];
        int * v1567 = v1520->cache_vals;
        int v1661 = (10 + ((((v1558 + ((~(((v1560 ^ -1) | (-(v1560 ^ -1))) >> 31)) & 2)) - (v1561 + ((~(((v1562 ^ -1) | (-(v1562 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
        int v1568 = v1567[v1661];
        int v1662 = ((10 + ((((v1558 + ((~(((v1560 ^ -1) | (-(v1560 ^ -1))) >> 31)) & 2)) - (v1561 + ((~(((v1562 ^ -1) | (-(v1562 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
        int v1569 = v1567[v1662];
        int * v1570 = v1520->mem;
        int v1664 = v1566 * 2;
        v1570[v1664] = v1568;
        int * v1572 = v1520->mem;
        int v1667 = (v1566 * 2) + 1;
        v1572[v1667] = v1569;
        ;
      } else {
        ;
      }
      int * v1577 = v1520->mem;
      int v1578 = v1577[14];
      int v1579 = v1577[15];
      int * v1580 = v1520->cache_vals;
      int v1675 = (10 + ((((v1558 + ((~(((v1560 ^ -1) | (-(v1560 ^ -1))) >> 31)) & 2)) - (v1561 + ((~(((v1562 ^ -1) | (-(v1562 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
      v1580[v1675] = v1578;
      int * v1582 = v1520->cache_vals;
      int v1678 = ((10 + ((((v1558 + ((~(((v1560 ^ -1) | (-(v1560 ^ -1))) >> 31)) & 2)) - (v1561 + ((~(((v1562 ^ -1) | (-(v1562 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
      v1582[v1678] = v1579;
      int * v1584 = v1520->cache_tags;
      v1584[v1657] = 7;
      int * v1586 = v1520->cache_dirty;
      v1586[v1657] = 0;
      int * v1588 = v1520->cache_age;
      v1588[v1657] = 1;
      int * v1590 = v1520->cache_age;
      int v1591 = v1590[v1657];
      int v1592 = v1590[10];
      int v1687 = v1592 + ((int)((unsigned int)(v1592 - v1591) >> 31));
      v1590[10] = v1687;
      int * v1594 = v1520->cache_age;
      int v1595 = v1594[11];
      int v1689 = v1595 + ((int)((unsigned int)(v1595 - v1591) >> 31));
      v1594[11] = v1689;
      int * v1597 = v1520->cache_age;
      v1597[v1657] = 0;
      v1600 = v1657;
    }
    int * v1601 = v1520->cache_vals;
    int v1692 = v1600 * 2;
    int v1602 = v1601[v1692];
    int v1693 = (v1600 * 2) + 1;
    int v1603 = v1601[v1693];
    int v1694 = (2 + ((((v1542 + ((~(((v1544 ^ -1) | (-(v1544 ^ -1))) >> 31)) & 2)) - (v1545 + ((~(((v1546 ^ -1) | (-(v1546 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
    v1601[v1694] = v1602;
    int * v1605 = v1520->cache_vals;
    int v1697 = ((2 + ((((v1542 + ((~(((v1544 ^ -1) | (-(v1544 ^ -1))) >> 31)) & 2)) - (v1545 + ((~(((v1546 ^ -1) | (-(v1546 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
    v1605[v1697] = v1603;
    int * v1607 = v1520->cache_tags;
    int v1700 = 2 + ((((v1542 + ((~(((v1544 ^ -1) | (-(v1544 ^ -1))) >> 31)) & 2)) - (v1545 + ((~(((v1546 ^ -1) | (-(v1546 ^ -1))) >> 31)) & 2))) >> 31) & 1);
    v1607[v1700] = 7;
    int * v1609 = v1520->cache_dirty;
    v1609[v1700] = 0;
    int * v1611 = v1520->cache_age;
    v1611[v1700] = 1;
    int * v1613 = v1520->cache_age;
    int v1614 = v1613[v1700];
    int v1615 = v1613[2];
    int v1707 = v1615 + ((int)((unsigned int)(v1615 - v1614) >> 31));
    v1613[2] = v1707;
    int * v1617 = v1520->cache_age;
    int v1618 = v1617[3];
    int v1709 = v1618 + ((int)((unsigned int)(v1618 - v1614) >> 31));
    v1617[3] = v1709;
    int * v1620 = v1520->cache_age;
    v1620[v1700] = 0;
    v1623 = v1700;
  }
  int v1712 = v1623 * 2;
  int v1624 = v1530[v1712];
  int * v1625 = v1520->regs;
  v1625[8] = v1624;
  struct StateT * v1627 = slot_6(v1520);
  return v1627;
}

struct StateT * slot_4(struct StateT * v353) {
  int v354 = v353->timer;
  int v999 = v354 + 1;
  v353->timer = v999;
  int * v356 = v353->regs;
  int v357 = v356[7];
  int * v358 = v353->saved_regs;
  int v359 = v356[8];
  v358[8] = v359;
  int v361 = v353->timer;
  int v1005 = v361 + 1;
  v353->timer = v1005;
  int * v363 = v353->cache_tags;
  int v364 = v363[2];
  int v365 = v363[3];
  int v366 = v363[10];
  int v367 = v363[11];
  int v368 = v353->timer;
  int v1011 = v368 + ((100 ^ (((~(((v366 ^ 7) | (-(v366 ^ 7))) >> 31)) | (~(((v367 ^ 7) | (-(v367 ^ 7))) >> 31))) & 104)) ^ (((~(((v364 ^ 7) | (-(v364 ^ 7))) >> 31)) | (~(((v365 ^ 7) | (-(v365 ^ 7))) >> 31))) & (1 ^ (100 ^ (((~(((v366 ^ 7) | (-(v366 ^ 7))) >> 31)) | (~(((v367 ^ 7) | (-(v367 ^ 7))) >> 31))) & 104)))));
  v353->timer = v1011;
  int * v370 = v353->cache_vals;
  bool v1012 = !(((~(((v364 ^ 7) | (-(v364 ^ 7))) >> 31)) | (~(((v365 ^ 7) | (-(v365 ^ 7))) >> 31))) == 0);
  int v463;
  if (v1012) {
    int * v371 = v353->cache_age;
    int v1014 = 2 + ((~(((v365 ^ 7) | (-(v365 ^ 7))) >> 31)) & 1);
    int v372 = v371[v1014];
    int v373 = v371[2];
    int v1015 = v373 + ((int)((unsigned int)(v373 - v372) >> 31));
    v371[2] = v1015;
    int * v375 = v353->cache_age;
    int v376 = v375[3];
    int v1017 = v376 + ((int)((unsigned int)(v376 - v372) >> 31));
    v375[3] = v1017;
    int * v378 = v353->cache_age;
    v378[v1014] = 0;
    v463 = v1014;
  } else {
    int * v381 = v353->cache_age;
    int v382 = v381[2];
    int * v383 = v353->cache_tags;
    int v384 = v383[2];
    int v385 = v381[3];
    int v386 = v383[3];
    bool v1022 = !(((~(((v366 ^ 7) | (-(v366 ^ 7))) >> 31)) | (~(((v367 ^ 7) | (-(v367 ^ 7))) >> 31))) == 0);
    int v440;
    if (v1022) {
      int * v387 = v353->cache_age;
      int v1024 = 10 + ((~(((v367 ^ 7) | (-(v367 ^ 7))) >> 31)) & 1);
      int v388 = v387[v1024];
      int v389 = v387[10];
      int v1025 = v389 + ((int)((unsigned int)(v389 - v388) >> 31));
      v387[10] = v1025;
      int * v391 = v353->cache_age;
      int v392 = v391[11];
      int v1027 = v392 + ((int)((unsigned int)(v392 - v388) >> 31));
      v391[11] = v1027;
      int * v394 = v353->cache_age;
      v394[v1024] = 0;
      v440 = v1024;
    } else {
      int * v397 = v353->cache_age;
      int v398 = v397[10];
      int * v399 = v353->cache_tags;
      int v400 = v399[10];
      int v401 = v397[11];
      int v402 = v399[11];
      int * v403 = v353->cache_dirty;
      int v1033 = 10 + ((((v398 + ((~(((v400 ^ -1) | (-(v400 ^ -1))) >> 31)) & 2)) - (v401 + ((~(((v402 ^ -1) | (-(v402 ^ -1))) >> 31)) & 2))) >> 31) & 1);
      int v404 = v403[v1033];
      bool v1034 = !(v404 == 0);
      if (v1034) {
        int * v405 = v353->cache_tags;
        int v406 = v405[v1033];
        int * v407 = v353->cache_vals;
        int v1037 = (10 + ((((v398 + ((~(((v400 ^ -1) | (-(v400 ^ -1))) >> 31)) & 2)) - (v401 + ((~(((v402 ^ -1) | (-(v402 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
        int v408 = v407[v1037];
        int v1038 = ((10 + ((((v398 + ((~(((v400 ^ -1) | (-(v400 ^ -1))) >> 31)) & 2)) - (v401 + ((~(((v402 ^ -1) | (-(v402 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
        int v409 = v407[v1038];
        int * v410 = v353->mem;
        int v1040 = v406 * 2;
        v410[v1040] = v408;
        int * v412 = v353->mem;
        int v1043 = (v406 * 2) + 1;
        v412[v1043] = v409;
        ;
      } else {
        ;
      }
      int * v417 = v353->mem;
      int v418 = v417[14];
      int v419 = v417[15];
      int * v420 = v353->cache_vals;
      int v1051 = (10 + ((((v398 + ((~(((v400 ^ -1) | (-(v400 ^ -1))) >> 31)) & 2)) - (v401 + ((~(((v402 ^ -1) | (-(v402 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
      v420[v1051] = v418;
      int * v422 = v353->cache_vals;
      int v1054 = ((10 + ((((v398 + ((~(((v400 ^ -1) | (-(v400 ^ -1))) >> 31)) & 2)) - (v401 + ((~(((v402 ^ -1) | (-(v402 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
      v422[v1054] = v419;
      int * v424 = v353->cache_tags;
      v424[v1033] = 7;
      int * v426 = v353->cache_dirty;
      v426[v1033] = 0;
      int * v428 = v353->cache_age;
      v428[v1033] = 1;
      int * v430 = v353->cache_age;
      int v431 = v430[v1033];
      int v432 = v430[10];
      int v1062 = v432 + ((int)((unsigned int)(v432 - v431) >> 31));
      v430[10] = v1062;
      int * v434 = v353->cache_age;
      int v435 = v434[11];
      int v1064 = v435 + ((int)((unsigned int)(v435 - v431) >> 31));
      v434[11] = v1064;
      int * v437 = v353->cache_age;
      v437[v1033] = 0;
      v440 = v1033;
    }
    int * v441 = v353->cache_vals;
    int v1067 = v440 * 2;
    int v442 = v441[v1067];
    int v1068 = (v440 * 2) + 1;
    int v443 = v441[v1068];
    int v1069 = (2 + ((((v382 + ((~(((v384 ^ -1) | (-(v384 ^ -1))) >> 31)) & 2)) - (v385 + ((~(((v386 ^ -1) | (-(v386 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
    v441[v1069] = v442;
    int * v445 = v353->cache_vals;
    int v1072 = ((2 + ((((v382 + ((~(((v384 ^ -1) | (-(v384 ^ -1))) >> 31)) & 2)) - (v385 + ((~(((v386 ^ -1) | (-(v386 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
    v445[v1072] = v443;
    int * v447 = v353->cache_tags;
    int v1075 = 2 + ((((v382 + ((~(((v384 ^ -1) | (-(v384 ^ -1))) >> 31)) & 2)) - (v385 + ((~(((v386 ^ -1) | (-(v386 ^ -1))) >> 31)) & 2))) >> 31) & 1);
    v447[v1075] = 7;
    int * v449 = v353->cache_dirty;
    v449[v1075] = 0;
    int * v451 = v353->cache_age;
    v451[v1075] = 1;
    int * v453 = v353->cache_age;
    int v454 = v453[v1075];
    int v455 = v453[2];
    int v1081 = v455 + ((int)((unsigned int)(v455 - v454) >> 31));
    v453[2] = v1081;
    int * v457 = v353->cache_age;
    int v458 = v457[3];
    int v1083 = v458 + ((int)((unsigned int)(v458 - v454) >> 31));
    v457[3] = v1083;
    int * v460 = v353->cache_age;
    v460[v1075] = 0;
    v463 = v1075;
  }
  int v1086 = v463 * 2;
  int v464 = v370[v1086];
  int * v465 = v353->regs;
  v465[8] = v464;
  int * v467 = v353->saved_regs;
  int * v468 = v353->regs;
  int v469 = v468[9];
  v467[9] = v469;
  int v471 = v353->timer;
  int v1093 = v471 + 1;
  v353->timer = v1093;
  int * v473 = v353->regs;
  int v474 = v473[8];
  int * v475 = v353->cache_tags;
  int v1096 = (((int)((unsigned int)((int)((unsigned int)(v474 + 40) >> 2)) >> 1)) & 1) * 2;
  int v476 = v475[v1096];
  int v1097 = ((((int)((unsigned int)((int)((unsigned int)(v474 + 40) >> 2)) >> 1)) & 1) * 2) + 1;
  int v477 = v475[v1097];
  int v1098 = 4 + ((((int)((unsigned int)((int)((unsigned int)(v474 + 40) >> 2)) >> 1)) & 3) * 2);
  int v478 = v475[v1098];
  int v1099 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v474 + 40) >> 2)) >> 1)) & 3) * 2)) + 1;
  int v479 = v475[v1099];
  int v480 = v353->timer;
  int v1100 = v480 + ((100 ^ (((~(((v478 ^ ((int)((unsigned int)((int)((unsigned int)(v474 + 40) >> 2)) >> 1))) | (-(v478 ^ ((int)((unsigned int)((int)((unsigned int)(v474 + 40) >> 2)) >> 1))))) >> 31)) | (~(((v479 ^ ((int)((unsigned int)((int)((unsigned int)(v474 + 40) >> 2)) >> 1))) | (-(v479 ^ ((int)((unsigned int)((int)((unsigned int)(v474 + 40) >> 2)) >> 1))))) >> 31))) & 104)) ^ (((~(((v476 ^ ((int)((unsigned int)((int)((unsigned int)(v474 + 40) >> 2)) >> 1))) | (-(v476 ^ ((int)((unsigned int)((int)((unsigned int)(v474 + 40) >> 2)) >> 1))))) >> 31)) | (~(((v477 ^ ((int)((unsigned int)((int)((unsigned int)(v474 + 40) >> 2)) >> 1))) | (-(v477 ^ ((int)((unsigned int)((int)((unsigned int)(v474 + 40) >> 2)) >> 1))))) >> 31))) & (1 ^ (100 ^ (((~(((v478 ^ ((int)((unsigned int)((int)((unsigned int)(v474 + 40) >> 2)) >> 1))) | (-(v478 ^ ((int)((unsigned int)((int)((unsigned int)(v474 + 40) >> 2)) >> 1))))) >> 31)) | (~(((v479 ^ ((int)((unsigned int)((int)((unsigned int)(v474 + 40) >> 2)) >> 1))) | (-(v479 ^ ((int)((unsigned int)((int)((unsigned int)(v474 + 40) >> 2)) >> 1))))) >> 31))) & 104)))));
  v353->timer = v1100;
  int * v482 = v353->cache_vals;
  bool v1101 = !(((~(((v476 ^ ((int)((unsigned int)((int)((unsigned int)(v474 + 40) >> 2)) >> 1))) | (-(v476 ^ ((int)((unsigned int)((int)((unsigned int)(v474 + 40) >> 2)) >> 1))))) >> 31)) | (~(((v477 ^ ((int)((unsigned int)((int)((unsigned int)(v474 + 40) >> 2)) >> 1))) | (-(v477 ^ ((int)((unsigned int)((int)((unsigned int)(v474 + 40) >> 2)) >> 1))))) >> 31))) == 0);
  int v575;
  if (v1101) {
    int * v483 = v353->cache_age;
    int v1103 = ((((int)((unsigned int)((int)((unsigned int)(v474 + 40) >> 2)) >> 1)) & 1) * 2) + ((~(((v477 ^ ((int)((unsigned int)((int)((unsigned int)(v474 + 40) >> 2)) >> 1))) | (-(v477 ^ ((int)((unsigned int)((int)((unsigned int)(v474 + 40) >> 2)) >> 1))))) >> 31)) & 1);
    int v484 = v483[v1103];
    int v485 = v483[v1096];
    int v1104 = v485 + ((int)((unsigned int)(v485 - v484) >> 31));
    v483[v1096] = v1104;
    int * v487 = v353->cache_age;
    int v488 = v487[v1097];
    int v1106 = v488 + ((int)((unsigned int)(v488 - v484) >> 31));
    v487[v1097] = v1106;
    int * v490 = v353->cache_age;
    v490[v1103] = 0;
    v575 = v1103;
  } else {
    int * v493 = v353->cache_age;
    int v1110 = (((int)((unsigned int)((int)((unsigned int)(v474 + 40) >> 2)) >> 1)) & 1) * 2;
    int v494 = v493[v1110];
    int * v495 = v353->cache_tags;
    int v496 = v495[v1110];
    int v497 = v493[v1097];
    int v498 = v495[v1097];
    bool v1112 = !(((~(((v478 ^ ((int)((unsigned int)((int)((unsigned int)(v474 + 40) >> 2)) >> 1))) | (-(v478 ^ ((int)((unsigned int)((int)((unsigned int)(v474 + 40) >> 2)) >> 1))))) >> 31)) | (~(((v479 ^ ((int)((unsigned int)((int)((unsigned int)(v474 + 40) >> 2)) >> 1))) | (-(v479 ^ ((int)((unsigned int)((int)((unsigned int)(v474 + 40) >> 2)) >> 1))))) >> 31))) == 0);
    int v552;
    if (v1112) {
      int * v499 = v353->cache_age;
      int v1114 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v474 + 40) >> 2)) >> 1)) & 3) * 2)) + ((~(((v479 ^ ((int)((unsigned int)((int)((unsigned int)(v474 + 40) >> 2)) >> 1))) | (-(v479 ^ ((int)((unsigned int)((int)((unsigned int)(v474 + 40) >> 2)) >> 1))))) >> 31)) & 1);
      int v500 = v499[v1114];
      int v501 = v499[v1098];
      int v1115 = v501 + ((int)((unsigned int)(v501 - v500) >> 31));
      v499[v1098] = v1115;
      int * v503 = v353->cache_age;
      int v504 = v503[v1099];
      int v1117 = v504 + ((int)((unsigned int)(v504 - v500) >> 31));
      v503[v1099] = v1117;
      int * v506 = v353->cache_age;
      v506[v1114] = 0;
      v552 = v1114;
    } else {
      int * v509 = v353->cache_age;
      int v1121 = 4 + ((((int)((unsigned int)((int)((unsigned int)(v474 + 40) >> 2)) >> 1)) & 3) * 2);
      int v510 = v509[v1121];
      int * v511 = v353->cache_tags;
      int v512 = v511[v1121];
      int v513 = v509[v1099];
      int v514 = v511[v1099];
      int * v515 = v353->cache_dirty;
      int v1124 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v474 + 40) >> 2)) >> 1)) & 3) * 2)) + ((((v510 + ((~(((v512 ^ -1) | (-(v512 ^ -1))) >> 31)) & 2)) - (v513 + ((~(((v514 ^ -1) | (-(v514 ^ -1))) >> 31)) & 2))) >> 31) & 1);
      int v516 = v515[v1124];
      bool v1125 = !(v516 == 0);
      if (v1125) {
        int * v517 = v353->cache_tags;
        int v518 = v517[v1124];
        int * v519 = v353->cache_vals;
        int v1128 = ((4 + ((((int)((unsigned int)((int)((unsigned int)(v474 + 40) >> 2)) >> 1)) & 3) * 2)) + ((((v510 + ((~(((v512 ^ -1) | (-(v512 ^ -1))) >> 31)) & 2)) - (v513 + ((~(((v514 ^ -1) | (-(v514 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
        int v520 = v519[v1128];
        int v1129 = (((4 + ((((int)((unsigned int)((int)((unsigned int)(v474 + 40) >> 2)) >> 1)) & 3) * 2)) + ((((v510 + ((~(((v512 ^ -1) | (-(v512 ^ -1))) >> 31)) & 2)) - (v513 + ((~(((v514 ^ -1) | (-(v514 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
        int v521 = v519[v1129];
        int * v522 = v353->mem;
        int v1131 = v518 * 2;
        v522[v1131] = v520;
        int * v524 = v353->mem;
        int v1134 = (v518 * 2) + 1;
        v524[v1134] = v521;
        ;
      } else {
        ;
      }
      int * v529 = v353->mem;
      int v1139 = ((int)((unsigned int)((int)((unsigned int)(v474 + 40) >> 2)) >> 1)) * 2;
      int v530 = v529[v1139];
      int v1140 = (((int)((unsigned int)((int)((unsigned int)(v474 + 40) >> 2)) >> 1)) * 2) + 1;
      int v531 = v529[v1140];
      int * v532 = v353->cache_vals;
      int v1142 = ((4 + ((((int)((unsigned int)((int)((unsigned int)(v474 + 40) >> 2)) >> 1)) & 3) * 2)) + ((((v510 + ((~(((v512 ^ -1) | (-(v512 ^ -1))) >> 31)) & 2)) - (v513 + ((~(((v514 ^ -1) | (-(v514 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
      v532[v1142] = v530;
      int * v534 = v353->cache_vals;
      int v1145 = (((4 + ((((int)((unsigned int)((int)((unsigned int)(v474 + 40) >> 2)) >> 1)) & 3) * 2)) + ((((v510 + ((~(((v512 ^ -1) | (-(v512 ^ -1))) >> 31)) & 2)) - (v513 + ((~(((v514 ^ -1) | (-(v514 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
      v534[v1145] = v531;
      int * v536 = v353->cache_tags;
      int v1148 = (int)((unsigned int)((int)((unsigned int)(v474 + 40) >> 2)) >> 1);
      v536[v1124] = v1148;
      int * v538 = v353->cache_dirty;
      v538[v1124] = 0;
      int * v540 = v353->cache_age;
      v540[v1124] = 1;
      int * v542 = v353->cache_age;
      int v543 = v542[v1124];
      int v544 = v542[v1098];
      int v1154 = v544 + ((int)((unsigned int)(v544 - v543) >> 31));
      v542[v1098] = v1154;
      int * v546 = v353->cache_age;
      int v547 = v546[v1099];
      int v1156 = v547 + ((int)((unsigned int)(v547 - v543) >> 31));
      v546[v1099] = v1156;
      int * v549 = v353->cache_age;
      v549[v1124] = 0;
      v552 = v1124;
    }
    int * v553 = v353->cache_vals;
    int v1159 = v552 * 2;
    int v554 = v553[v1159];
    int v1160 = (v552 * 2) + 1;
    int v555 = v553[v1160];
    int v1161 = (((((int)((unsigned int)((int)((unsigned int)(v474 + 40) >> 2)) >> 1)) & 1) * 2) + ((((v494 + ((~(((v496 ^ -1) | (-(v496 ^ -1))) >> 31)) & 2)) - (v497 + ((~(((v498 ^ -1) | (-(v498 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
    v553[v1161] = v554;
    int * v557 = v353->cache_vals;
    int v1164 = ((((((int)((unsigned int)((int)((unsigned int)(v474 + 40) >> 2)) >> 1)) & 1) * 2) + ((((v494 + ((~(((v496 ^ -1) | (-(v496 ^ -1))) >> 31)) & 2)) - (v497 + ((~(((v498 ^ -1) | (-(v498 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
    v557[v1164] = v555;
    int * v559 = v353->cache_tags;
    int v1167 = ((((int)((unsigned int)((int)((unsigned int)(v474 + 40) >> 2)) >> 1)) & 1) * 2) + ((((v494 + ((~(((v496 ^ -1) | (-(v496 ^ -1))) >> 31)) & 2)) - (v497 + ((~(((v498 ^ -1) | (-(v498 ^ -1))) >> 31)) & 2))) >> 31) & 1);
    int v1168 = (int)((unsigned int)((int)((unsigned int)(v474 + 40) >> 2)) >> 1);
    v559[v1167] = v1168;
    int * v561 = v353->cache_dirty;
    v561[v1167] = 0;
    int * v563 = v353->cache_age;
    v563[v1167] = 1;
    int * v565 = v353->cache_age;
    int v566 = v565[v1167];
    int v567 = v565[v1096];
    int v1174 = v567 + ((int)((unsigned int)(v567 - v566) >> 31));
    v565[v1096] = v1174;
    int * v569 = v353->cache_age;
    int v570 = v569[v1097];
    int v1176 = v570 + ((int)((unsigned int)(v570 - v566) >> 31));
    v569[v1097] = v1176;
    int * v572 = v353->cache_age;
    v572[v1167] = 0;
    v575 = v1167;
  }
  int v1179 = (v575 * 2) + (((int)((unsigned int)(v474 + 40) >> 2)) & 1);
  int v576 = v482[v1179];
  int * v577 = v353->regs;
  v577[9] = v576;
  int * v579 = v353->saved_regs;
  int * v580 = v353->regs;
  int v581 = v580[11];
  v579[11] = v581;
  int v583 = v353->timer;
  int v1185 = v583 + 1;
  v353->timer = v1185;
  int * v585 = v353->regs;
  int v586 = v585[9];
  bool v1187 = 2 == (((int)((unsigned int)v586 >> 2)) & 3);
  int v693;
  if (v1187) {
    int v587 = v353->timer;
    int v1188 = v587 + 1;
    v353->timer = v1188;
    v693 = v357;
  } else {
    int * v590 = v353->cache_tags;
    int v1191 = (((int)((unsigned int)((int)((unsigned int)v586 >> 2)) >> 1)) & 1) * 2;
    int v591 = v590[v1191];
    int v1192 = ((((int)((unsigned int)((int)((unsigned int)v586 >> 2)) >> 1)) & 1) * 2) + 1;
    int v592 = v590[v1192];
    int v1193 = 4 + ((((int)((unsigned int)((int)((unsigned int)v586 >> 2)) >> 1)) & 3) * 2);
    int v593 = v590[v1193];
    int v1194 = (4 + ((((int)((unsigned int)((int)((unsigned int)v586 >> 2)) >> 1)) & 3) * 2)) + 1;
    int v594 = v590[v1194];
    int v595 = v353->timer;
    int v1195 = v595 + ((100 ^ (((~(((v593 ^ ((int)((unsigned int)((int)((unsigned int)v586 >> 2)) >> 1))) | (-(v593 ^ ((int)((unsigned int)((int)((unsigned int)v586 >> 2)) >> 1))))) >> 31)) | (~(((v594 ^ ((int)((unsigned int)((int)((unsigned int)v586 >> 2)) >> 1))) | (-(v594 ^ ((int)((unsigned int)((int)((unsigned int)v586 >> 2)) >> 1))))) >> 31))) & 104)) ^ (((~(((v591 ^ ((int)((unsigned int)((int)((unsigned int)v586 >> 2)) >> 1))) | (-(v591 ^ ((int)((unsigned int)((int)((unsigned int)v586 >> 2)) >> 1))))) >> 31)) | (~(((v592 ^ ((int)((unsigned int)((int)((unsigned int)v586 >> 2)) >> 1))) | (-(v592 ^ ((int)((unsigned int)((int)((unsigned int)v586 >> 2)) >> 1))))) >> 31))) & (1 ^ (100 ^ (((~(((v593 ^ ((int)((unsigned int)((int)((unsigned int)v586 >> 2)) >> 1))) | (-(v593 ^ ((int)((unsigned int)((int)((unsigned int)v586 >> 2)) >> 1))))) >> 31)) | (~(((v594 ^ ((int)((unsigned int)((int)((unsigned int)v586 >> 2)) >> 1))) | (-(v594 ^ ((int)((unsigned int)((int)((unsigned int)v586 >> 2)) >> 1))))) >> 31))) & 104)))));
    v353->timer = v1195;
    int * v597 = v353->cache_vals;
    bool v1196 = !(((~(((v591 ^ ((int)((unsigned int)((int)((unsigned int)v586 >> 2)) >> 1))) | (-(v591 ^ ((int)((unsigned int)((int)((unsigned int)v586 >> 2)) >> 1))))) >> 31)) | (~(((v592 ^ ((int)((unsigned int)((int)((unsigned int)v586 >> 2)) >> 1))) | (-(v592 ^ ((int)((unsigned int)((int)((unsigned int)v586 >> 2)) >> 1))))) >> 31))) == 0);
    int v690;
    if (v1196) {
      int * v598 = v353->cache_age;
      int v1198 = ((((int)((unsigned int)((int)((unsigned int)v586 >> 2)) >> 1)) & 1) * 2) + ((~(((v592 ^ ((int)((unsigned int)((int)((unsigned int)v586 >> 2)) >> 1))) | (-(v592 ^ ((int)((unsigned int)((int)((unsigned int)v586 >> 2)) >> 1))))) >> 31)) & 1);
      int v599 = v598[v1198];
      int v600 = v598[v1191];
      int v1199 = v600 + ((int)((unsigned int)(v600 - v599) >> 31));
      v598[v1191] = v1199;
      int * v602 = v353->cache_age;
      int v603 = v602[v1192];
      int v1201 = v603 + ((int)((unsigned int)(v603 - v599) >> 31));
      v602[v1192] = v1201;
      int * v605 = v353->cache_age;
      v605[v1198] = 0;
      v690 = v1198;
    } else {
      int * v608 = v353->cache_age;
      int v1205 = (((int)((unsigned int)((int)((unsigned int)v586 >> 2)) >> 1)) & 1) * 2;
      int v609 = v608[v1205];
      int * v610 = v353->cache_tags;
      int v611 = v610[v1205];
      int v612 = v608[v1192];
      int v613 = v610[v1192];
      bool v1207 = !(((~(((v593 ^ ((int)((unsigned int)((int)((unsigned int)v586 >> 2)) >> 1))) | (-(v593 ^ ((int)((unsigned int)((int)((unsigned int)v586 >> 2)) >> 1))))) >> 31)) | (~(((v594 ^ ((int)((unsigned int)((int)((unsigned int)v586 >> 2)) >> 1))) | (-(v594 ^ ((int)((unsigned int)((int)((unsigned int)v586 >> 2)) >> 1))))) >> 31))) == 0);
      int v667;
      if (v1207) {
        int * v614 = v353->cache_age;
        int v1209 = (4 + ((((int)((unsigned int)((int)((unsigned int)v586 >> 2)) >> 1)) & 3) * 2)) + ((~(((v594 ^ ((int)((unsigned int)((int)((unsigned int)v586 >> 2)) >> 1))) | (-(v594 ^ ((int)((unsigned int)((int)((unsigned int)v586 >> 2)) >> 1))))) >> 31)) & 1);
        int v615 = v614[v1209];
        int v616 = v614[v1193];
        int v1210 = v616 + ((int)((unsigned int)(v616 - v615) >> 31));
        v614[v1193] = v1210;
        int * v618 = v353->cache_age;
        int v619 = v618[v1194];
        int v1212 = v619 + ((int)((unsigned int)(v619 - v615) >> 31));
        v618[v1194] = v1212;
        int * v621 = v353->cache_age;
        v621[v1209] = 0;
        v667 = v1209;
      } else {
        int * v624 = v353->cache_age;
        int v1216 = 4 + ((((int)((unsigned int)((int)((unsigned int)v586 >> 2)) >> 1)) & 3) * 2);
        int v625 = v624[v1216];
        int * v626 = v353->cache_tags;
        int v627 = v626[v1216];
        int v628 = v624[v1194];
        int v629 = v626[v1194];
        int * v630 = v353->cache_dirty;
        int v1219 = (4 + ((((int)((unsigned int)((int)((unsigned int)v586 >> 2)) >> 1)) & 3) * 2)) + ((((v625 + ((~(((v627 ^ -1) | (-(v627 ^ -1))) >> 31)) & 2)) - (v628 + ((~(((v629 ^ -1) | (-(v629 ^ -1))) >> 31)) & 2))) >> 31) & 1);
        int v631 = v630[v1219];
        bool v1220 = !(v631 == 0);
        if (v1220) {
          int * v632 = v353->cache_tags;
          int v633 = v632[v1219];
          int * v634 = v353->cache_vals;
          int v1223 = ((4 + ((((int)((unsigned int)((int)((unsigned int)v586 >> 2)) >> 1)) & 3) * 2)) + ((((v625 + ((~(((v627 ^ -1) | (-(v627 ^ -1))) >> 31)) & 2)) - (v628 + ((~(((v629 ^ -1) | (-(v629 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
          int v635 = v634[v1223];
          int v1224 = (((4 + ((((int)((unsigned int)((int)((unsigned int)v586 >> 2)) >> 1)) & 3) * 2)) + ((((v625 + ((~(((v627 ^ -1) | (-(v627 ^ -1))) >> 31)) & 2)) - (v628 + ((~(((v629 ^ -1) | (-(v629 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
          int v636 = v634[v1224];
          int * v637 = v353->mem;
          int v1226 = v633 * 2;
          v637[v1226] = v635;
          int * v639 = v353->mem;
          int v1229 = (v633 * 2) + 1;
          v639[v1229] = v636;
          ;
        } else {
          ;
        }
        int * v644 = v353->mem;
        int v1234 = ((int)((unsigned int)((int)((unsigned int)v586 >> 2)) >> 1)) * 2;
        int v645 = v644[v1234];
        int v1235 = (((int)((unsigned int)((int)((unsigned int)v586 >> 2)) >> 1)) * 2) + 1;
        int v646 = v644[v1235];
        int * v647 = v353->cache_vals;
        int v1237 = ((4 + ((((int)((unsigned int)((int)((unsigned int)v586 >> 2)) >> 1)) & 3) * 2)) + ((((v625 + ((~(((v627 ^ -1) | (-(v627 ^ -1))) >> 31)) & 2)) - (v628 + ((~(((v629 ^ -1) | (-(v629 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
        v647[v1237] = v645;
        int * v649 = v353->cache_vals;
        int v1240 = (((4 + ((((int)((unsigned int)((int)((unsigned int)v586 >> 2)) >> 1)) & 3) * 2)) + ((((v625 + ((~(((v627 ^ -1) | (-(v627 ^ -1))) >> 31)) & 2)) - (v628 + ((~(((v629 ^ -1) | (-(v629 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
        v649[v1240] = v646;
        int * v651 = v353->cache_tags;
        int v1243 = (int)((unsigned int)((int)((unsigned int)v586 >> 2)) >> 1);
        v651[v1219] = v1243;
        int * v653 = v353->cache_dirty;
        v653[v1219] = 0;
        int * v655 = v353->cache_age;
        v655[v1219] = 1;
        int * v657 = v353->cache_age;
        int v658 = v657[v1219];
        int v659 = v657[v1193];
        int v1249 = v659 + ((int)((unsigned int)(v659 - v658) >> 31));
        v657[v1193] = v1249;
        int * v661 = v353->cache_age;
        int v662 = v661[v1194];
        int v1251 = v662 + ((int)((unsigned int)(v662 - v658) >> 31));
        v661[v1194] = v1251;
        int * v664 = v353->cache_age;
        v664[v1219] = 0;
        v667 = v1219;
      }
      int * v668 = v353->cache_vals;
      int v1254 = v667 * 2;
      int v669 = v668[v1254];
      int v1255 = (v667 * 2) + 1;
      int v670 = v668[v1255];
      int v1256 = (((((int)((unsigned int)((int)((unsigned int)v586 >> 2)) >> 1)) & 1) * 2) + ((((v609 + ((~(((v611 ^ -1) | (-(v611 ^ -1))) >> 31)) & 2)) - (v612 + ((~(((v613 ^ -1) | (-(v613 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
      v668[v1256] = v669;
      int * v672 = v353->cache_vals;
      int v1259 = ((((((int)((unsigned int)((int)((unsigned int)v586 >> 2)) >> 1)) & 1) * 2) + ((((v609 + ((~(((v611 ^ -1) | (-(v611 ^ -1))) >> 31)) & 2)) - (v612 + ((~(((v613 ^ -1) | (-(v613 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
      v672[v1259] = v670;
      int * v674 = v353->cache_tags;
      int v1262 = ((((int)((unsigned int)((int)((unsigned int)v586 >> 2)) >> 1)) & 1) * 2) + ((((v609 + ((~(((v611 ^ -1) | (-(v611 ^ -1))) >> 31)) & 2)) - (v612 + ((~(((v613 ^ -1) | (-(v613 ^ -1))) >> 31)) & 2))) >> 31) & 1);
      int v1263 = (int)((unsigned int)((int)((unsigned int)v586 >> 2)) >> 1);
      v674[v1262] = v1263;
      int * v676 = v353->cache_dirty;
      v676[v1262] = 0;
      int * v678 = v353->cache_age;
      v678[v1262] = 1;
      int * v680 = v353->cache_age;
      int v681 = v680[v1262];
      int v682 = v680[v1191];
      int v1269 = v682 + ((int)((unsigned int)(v682 - v681) >> 31));
      v680[v1191] = v1269;
      int * v684 = v353->cache_age;
      int v685 = v684[v1192];
      int v1271 = v685 + ((int)((unsigned int)(v685 - v681) >> 31));
      v684[v1192] = v1271;
      int * v687 = v353->cache_age;
      v687[v1262] = 0;
      v690 = v1262;
    }
    int v1274 = (v690 * 2) + (((int)((unsigned int)v586 >> 2)) & 1);
    int v691 = v597[v1274];
    v693 = v691;
  }
  int * v694 = v353->regs;
  v694[11] = v693;
  int * v696 = v353->saved_regs;
  int * v697 = v353->regs;
  int v698 = v697[12];
  v696[12] = v698;
  int v700 = v353->timer;
  int v1282 = v700 + 1;
  v353->timer = v1282;
  int * v702 = v353->regs;
  int v703 = v702[11];
  bool v1284 = 2 == (((int)((unsigned int)v703 >> 2)) & 3);
  int v810;
  if (v1284) {
    int v704 = v353->timer;
    int v1285 = v704 + 1;
    v353->timer = v1285;
    v810 = v357;
  } else {
    int * v707 = v353->cache_tags;
    int v1288 = (((int)((unsigned int)((int)((unsigned int)v703 >> 2)) >> 1)) & 1) * 2;
    int v708 = v707[v1288];
    int v1289 = ((((int)((unsigned int)((int)((unsigned int)v703 >> 2)) >> 1)) & 1) * 2) + 1;
    int v709 = v707[v1289];
    int v1290 = 4 + ((((int)((unsigned int)((int)((unsigned int)v703 >> 2)) >> 1)) & 3) * 2);
    int v710 = v707[v1290];
    int v1291 = (4 + ((((int)((unsigned int)((int)((unsigned int)v703 >> 2)) >> 1)) & 3) * 2)) + 1;
    int v711 = v707[v1291];
    int v712 = v353->timer;
    int v1292 = v712 + ((100 ^ (((~(((v710 ^ ((int)((unsigned int)((int)((unsigned int)v703 >> 2)) >> 1))) | (-(v710 ^ ((int)((unsigned int)((int)((unsigned int)v703 >> 2)) >> 1))))) >> 31)) | (~(((v711 ^ ((int)((unsigned int)((int)((unsigned int)v703 >> 2)) >> 1))) | (-(v711 ^ ((int)((unsigned int)((int)((unsigned int)v703 >> 2)) >> 1))))) >> 31))) & 104)) ^ (((~(((v708 ^ ((int)((unsigned int)((int)((unsigned int)v703 >> 2)) >> 1))) | (-(v708 ^ ((int)((unsigned int)((int)((unsigned int)v703 >> 2)) >> 1))))) >> 31)) | (~(((v709 ^ ((int)((unsigned int)((int)((unsigned int)v703 >> 2)) >> 1))) | (-(v709 ^ ((int)((unsigned int)((int)((unsigned int)v703 >> 2)) >> 1))))) >> 31))) & (1 ^ (100 ^ (((~(((v710 ^ ((int)((unsigned int)((int)((unsigned int)v703 >> 2)) >> 1))) | (-(v710 ^ ((int)((unsigned int)((int)((unsigned int)v703 >> 2)) >> 1))))) >> 31)) | (~(((v711 ^ ((int)((unsigned int)((int)((unsigned int)v703 >> 2)) >> 1))) | (-(v711 ^ ((int)((unsigned int)((int)((unsigned int)v703 >> 2)) >> 1))))) >> 31))) & 104)))));
    v353->timer = v1292;
    int * v714 = v353->cache_vals;
    bool v1293 = !(((~(((v708 ^ ((int)((unsigned int)((int)((unsigned int)v703 >> 2)) >> 1))) | (-(v708 ^ ((int)((unsigned int)((int)((unsigned int)v703 >> 2)) >> 1))))) >> 31)) | (~(((v709 ^ ((int)((unsigned int)((int)((unsigned int)v703 >> 2)) >> 1))) | (-(v709 ^ ((int)((unsigned int)((int)((unsigned int)v703 >> 2)) >> 1))))) >> 31))) == 0);
    int v807;
    if (v1293) {
      int * v715 = v353->cache_age;
      int v1295 = ((((int)((unsigned int)((int)((unsigned int)v703 >> 2)) >> 1)) & 1) * 2) + ((~(((v709 ^ ((int)((unsigned int)((int)((unsigned int)v703 >> 2)) >> 1))) | (-(v709 ^ ((int)((unsigned int)((int)((unsigned int)v703 >> 2)) >> 1))))) >> 31)) & 1);
      int v716 = v715[v1295];
      int v717 = v715[v1288];
      int v1296 = v717 + ((int)((unsigned int)(v717 - v716) >> 31));
      v715[v1288] = v1296;
      int * v719 = v353->cache_age;
      int v720 = v719[v1289];
      int v1298 = v720 + ((int)((unsigned int)(v720 - v716) >> 31));
      v719[v1289] = v1298;
      int * v722 = v353->cache_age;
      v722[v1295] = 0;
      v807 = v1295;
    } else {
      int * v725 = v353->cache_age;
      int v1302 = (((int)((unsigned int)((int)((unsigned int)v703 >> 2)) >> 1)) & 1) * 2;
      int v726 = v725[v1302];
      int * v727 = v353->cache_tags;
      int v728 = v727[v1302];
      int v729 = v725[v1289];
      int v730 = v727[v1289];
      bool v1304 = !(((~(((v710 ^ ((int)((unsigned int)((int)((unsigned int)v703 >> 2)) >> 1))) | (-(v710 ^ ((int)((unsigned int)((int)((unsigned int)v703 >> 2)) >> 1))))) >> 31)) | (~(((v711 ^ ((int)((unsigned int)((int)((unsigned int)v703 >> 2)) >> 1))) | (-(v711 ^ ((int)((unsigned int)((int)((unsigned int)v703 >> 2)) >> 1))))) >> 31))) == 0);
      int v784;
      if (v1304) {
        int * v731 = v353->cache_age;
        int v1306 = (4 + ((((int)((unsigned int)((int)((unsigned int)v703 >> 2)) >> 1)) & 3) * 2)) + ((~(((v711 ^ ((int)((unsigned int)((int)((unsigned int)v703 >> 2)) >> 1))) | (-(v711 ^ ((int)((unsigned int)((int)((unsigned int)v703 >> 2)) >> 1))))) >> 31)) & 1);
        int v732 = v731[v1306];
        int v733 = v731[v1290];
        int v1307 = v733 + ((int)((unsigned int)(v733 - v732) >> 31));
        v731[v1290] = v1307;
        int * v735 = v353->cache_age;
        int v736 = v735[v1291];
        int v1309 = v736 + ((int)((unsigned int)(v736 - v732) >> 31));
        v735[v1291] = v1309;
        int * v738 = v353->cache_age;
        v738[v1306] = 0;
        v784 = v1306;
      } else {
        int * v741 = v353->cache_age;
        int v1313 = 4 + ((((int)((unsigned int)((int)((unsigned int)v703 >> 2)) >> 1)) & 3) * 2);
        int v742 = v741[v1313];
        int * v743 = v353->cache_tags;
        int v744 = v743[v1313];
        int v745 = v741[v1291];
        int v746 = v743[v1291];
        int * v747 = v353->cache_dirty;
        int v1316 = (4 + ((((int)((unsigned int)((int)((unsigned int)v703 >> 2)) >> 1)) & 3) * 2)) + ((((v742 + ((~(((v744 ^ -1) | (-(v744 ^ -1))) >> 31)) & 2)) - (v745 + ((~(((v746 ^ -1) | (-(v746 ^ -1))) >> 31)) & 2))) >> 31) & 1);
        int v748 = v747[v1316];
        bool v1317 = !(v748 == 0);
        if (v1317) {
          int * v749 = v353->cache_tags;
          int v750 = v749[v1316];
          int * v751 = v353->cache_vals;
          int v1320 = ((4 + ((((int)((unsigned int)((int)((unsigned int)v703 >> 2)) >> 1)) & 3) * 2)) + ((((v742 + ((~(((v744 ^ -1) | (-(v744 ^ -1))) >> 31)) & 2)) - (v745 + ((~(((v746 ^ -1) | (-(v746 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
          int v752 = v751[v1320];
          int v1321 = (((4 + ((((int)((unsigned int)((int)((unsigned int)v703 >> 2)) >> 1)) & 3) * 2)) + ((((v742 + ((~(((v744 ^ -1) | (-(v744 ^ -1))) >> 31)) & 2)) - (v745 + ((~(((v746 ^ -1) | (-(v746 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
          int v753 = v751[v1321];
          int * v754 = v353->mem;
          int v1323 = v750 * 2;
          v754[v1323] = v752;
          int * v756 = v353->mem;
          int v1326 = (v750 * 2) + 1;
          v756[v1326] = v753;
          ;
        } else {
          ;
        }
        int * v761 = v353->mem;
        int v1331 = ((int)((unsigned int)((int)((unsigned int)v703 >> 2)) >> 1)) * 2;
        int v762 = v761[v1331];
        int v1332 = (((int)((unsigned int)((int)((unsigned int)v703 >> 2)) >> 1)) * 2) + 1;
        int v763 = v761[v1332];
        int * v764 = v353->cache_vals;
        int v1334 = ((4 + ((((int)((unsigned int)((int)((unsigned int)v703 >> 2)) >> 1)) & 3) * 2)) + ((((v742 + ((~(((v744 ^ -1) | (-(v744 ^ -1))) >> 31)) & 2)) - (v745 + ((~(((v746 ^ -1) | (-(v746 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
        v764[v1334] = v762;
        int * v766 = v353->cache_vals;
        int v1337 = (((4 + ((((int)((unsigned int)((int)((unsigned int)v703 >> 2)) >> 1)) & 3) * 2)) + ((((v742 + ((~(((v744 ^ -1) | (-(v744 ^ -1))) >> 31)) & 2)) - (v745 + ((~(((v746 ^ -1) | (-(v746 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
        v766[v1337] = v763;
        int * v768 = v353->cache_tags;
        int v1340 = (int)((unsigned int)((int)((unsigned int)v703 >> 2)) >> 1);
        v768[v1316] = v1340;
        int * v770 = v353->cache_dirty;
        v770[v1316] = 0;
        int * v772 = v353->cache_age;
        v772[v1316] = 1;
        int * v774 = v353->cache_age;
        int v775 = v774[v1316];
        int v776 = v774[v1290];
        int v1346 = v776 + ((int)((unsigned int)(v776 - v775) >> 31));
        v774[v1290] = v1346;
        int * v778 = v353->cache_age;
        int v779 = v778[v1291];
        int v1348 = v779 + ((int)((unsigned int)(v779 - v775) >> 31));
        v778[v1291] = v1348;
        int * v781 = v353->cache_age;
        v781[v1316] = 0;
        v784 = v1316;
      }
      int * v785 = v353->cache_vals;
      int v1351 = v784 * 2;
      int v786 = v785[v1351];
      int v1352 = (v784 * 2) + 1;
      int v787 = v785[v1352];
      int v1353 = (((((int)((unsigned int)((int)((unsigned int)v703 >> 2)) >> 1)) & 1) * 2) + ((((v726 + ((~(((v728 ^ -1) | (-(v728 ^ -1))) >> 31)) & 2)) - (v729 + ((~(((v730 ^ -1) | (-(v730 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
      v785[v1353] = v786;
      int * v789 = v353->cache_vals;
      int v1356 = ((((((int)((unsigned int)((int)((unsigned int)v703 >> 2)) >> 1)) & 1) * 2) + ((((v726 + ((~(((v728 ^ -1) | (-(v728 ^ -1))) >> 31)) & 2)) - (v729 + ((~(((v730 ^ -1) | (-(v730 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
      v789[v1356] = v787;
      int * v791 = v353->cache_tags;
      int v1359 = ((((int)((unsigned int)((int)((unsigned int)v703 >> 2)) >> 1)) & 1) * 2) + ((((v726 + ((~(((v728 ^ -1) | (-(v728 ^ -1))) >> 31)) & 2)) - (v729 + ((~(((v730 ^ -1) | (-(v730 ^ -1))) >> 31)) & 2))) >> 31) & 1);
      int v1360 = (int)((unsigned int)((int)((unsigned int)v703 >> 2)) >> 1);
      v791[v1359] = v1360;
      int * v793 = v353->cache_dirty;
      v793[v1359] = 0;
      int * v795 = v353->cache_age;
      v795[v1359] = 1;
      int * v797 = v353->cache_age;
      int v798 = v797[v1359];
      int v799 = v797[v1288];
      int v1366 = v799 + ((int)((unsigned int)(v799 - v798) >> 31));
      v797[v1288] = v1366;
      int * v801 = v353->cache_age;
      int v802 = v801[v1289];
      int v1368 = v802 + ((int)((unsigned int)(v802 - v798) >> 31));
      v801[v1289] = v1368;
      int * v804 = v353->cache_age;
      v804[v1359] = 0;
      v807 = v1359;
    }
    int v1371 = (v807 * 2) + (((int)((unsigned int)v703 >> 2)) & 1);
    int v808 = v714[v1371];
    v810 = v808;
  }
  int * v811 = v353->regs;
  v811[12] = v810;
  int * v813 = v353->cache_tags;
  int v814 = v813[2];
  int v815 = v813[3];
  int v816 = v813[10];
  int v817 = v813[11];
  int v818 = v353->timer;
  int v1376 = v818 + ((100 ^ (((~(((v816 ^ 7) | (-(v816 ^ 7))) >> 31)) | (~(((v817 ^ 7) | (-(v817 ^ 7))) >> 31))) & 104)) ^ (((~(((v814 ^ 7) | (-(v814 ^ 7))) >> 31)) | (~(((v815 ^ 7) | (-(v815 ^ 7))) >> 31))) & (1 ^ (100 ^ (((~(((v816 ^ 7) | (-(v816 ^ 7))) >> 31)) | (~(((v817 ^ 7) | (-(v817 ^ 7))) >> 31))) & 104)))));
  v353->timer = v1376;
  bool v1377 = !(((~(((v814 ^ 7) | (-(v814 ^ 7))) >> 31)) | (~(((v815 ^ 7) | (-(v815 ^ 7))) >> 31))) == 0);
  int v912;
  if (v1377) {
    int * v820 = v353->cache_age;
    int v1379 = 2 + ((~(((v815 ^ 7) | (-(v815 ^ 7))) >> 31)) & 1);
    int v821 = v820[v1379];
    int v822 = v820[2];
    int v1380 = v822 + ((int)((unsigned int)(v822 - v821) >> 31));
    v820[2] = v1380;
    int * v824 = v353->cache_age;
    int v825 = v824[3];
    int v1382 = v825 + ((int)((unsigned int)(v825 - v821) >> 31));
    v824[3] = v1382;
    int * v827 = v353->cache_age;
    v827[v1379] = 0;
    v912 = v1379;
  } else {
    int * v830 = v353->cache_age;
    int v831 = v830[2];
    int * v832 = v353->cache_tags;
    int v833 = v832[2];
    int v834 = v830[3];
    int v835 = v832[3];
    bool v1387 = !(((~(((v816 ^ 7) | (-(v816 ^ 7))) >> 31)) | (~(((v817 ^ 7) | (-(v817 ^ 7))) >> 31))) == 0);
    int v889;
    if (v1387) {
      int * v836 = v353->cache_age;
      int v1389 = 10 + ((~(((v817 ^ 7) | (-(v817 ^ 7))) >> 31)) & 1);
      int v837 = v836[v1389];
      int v838 = v836[10];
      int v1390 = v838 + ((int)((unsigned int)(v838 - v837) >> 31));
      v836[10] = v1390;
      int * v840 = v353->cache_age;
      int v841 = v840[11];
      int v1392 = v841 + ((int)((unsigned int)(v841 - v837) >> 31));
      v840[11] = v1392;
      int * v843 = v353->cache_age;
      v843[v1389] = 0;
      v889 = v1389;
    } else {
      int * v846 = v353->cache_age;
      int v847 = v846[10];
      int * v848 = v353->cache_tags;
      int v849 = v848[10];
      int v850 = v846[11];
      int v851 = v848[11];
      int * v852 = v353->cache_dirty;
      int v1398 = 10 + ((((v847 + ((~(((v849 ^ -1) | (-(v849 ^ -1))) >> 31)) & 2)) - (v850 + ((~(((v851 ^ -1) | (-(v851 ^ -1))) >> 31)) & 2))) >> 31) & 1);
      int v853 = v852[v1398];
      bool v1399 = !(v853 == 0);
      if (v1399) {
        int * v854 = v353->cache_tags;
        int v855 = v854[v1398];
        int * v856 = v353->cache_vals;
        int v1402 = (10 + ((((v847 + ((~(((v849 ^ -1) | (-(v849 ^ -1))) >> 31)) & 2)) - (v850 + ((~(((v851 ^ -1) | (-(v851 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
        int v857 = v856[v1402];
        int v1403 = ((10 + ((((v847 + ((~(((v849 ^ -1) | (-(v849 ^ -1))) >> 31)) & 2)) - (v850 + ((~(((v851 ^ -1) | (-(v851 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
        int v858 = v856[v1403];
        int * v859 = v353->mem;
        int v1405 = v855 * 2;
        v859[v1405] = v857;
        int * v861 = v353->mem;
        int v1408 = (v855 * 2) + 1;
        v861[v1408] = v858;
        ;
      } else {
        ;
      }
      int * v866 = v353->mem;
      int v867 = v866[14];
      int v868 = v866[15];
      int * v869 = v353->cache_vals;
      int v1416 = (10 + ((((v847 + ((~(((v849 ^ -1) | (-(v849 ^ -1))) >> 31)) & 2)) - (v850 + ((~(((v851 ^ -1) | (-(v851 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
      v869[v1416] = v867;
      int * v871 = v353->cache_vals;
      int v1419 = ((10 + ((((v847 + ((~(((v849 ^ -1) | (-(v849 ^ -1))) >> 31)) & 2)) - (v850 + ((~(((v851 ^ -1) | (-(v851 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
      v871[v1419] = v868;
      int * v873 = v353->cache_tags;
      v873[v1398] = 7;
      int * v875 = v353->cache_dirty;
      v875[v1398] = 0;
      int * v877 = v353->cache_age;
      v877[v1398] = 1;
      int * v879 = v353->cache_age;
      int v880 = v879[v1398];
      int v881 = v879[10];
      int v1427 = v881 + ((int)((unsigned int)(v881 - v880) >> 31));
      v879[10] = v1427;
      int * v883 = v353->cache_age;
      int v884 = v883[11];
      int v1429 = v884 + ((int)((unsigned int)(v884 - v880) >> 31));
      v883[11] = v1429;
      int * v886 = v353->cache_age;
      v886[v1398] = 0;
      v889 = v1398;
    }
    int * v890 = v353->cache_vals;
    int v1432 = v889 * 2;
    int v891 = v890[v1432];
    int v1433 = (v889 * 2) + 1;
    int v892 = v890[v1433];
    int v1434 = (2 + ((((v831 + ((~(((v833 ^ -1) | (-(v833 ^ -1))) >> 31)) & 2)) - (v834 + ((~(((v835 ^ -1) | (-(v835 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
    v890[v1434] = v891;
    int * v894 = v353->cache_vals;
    int v1437 = ((2 + ((((v831 + ((~(((v833 ^ -1) | (-(v833 ^ -1))) >> 31)) & 2)) - (v834 + ((~(((v835 ^ -1) | (-(v835 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
    v894[v1437] = v892;
    int * v896 = v353->cache_tags;
    int v1440 = 2 + ((((v831 + ((~(((v833 ^ -1) | (-(v833 ^ -1))) >> 31)) & 2)) - (v834 + ((~(((v835 ^ -1) | (-(v835 ^ -1))) >> 31)) & 2))) >> 31) & 1);
    v896[v1440] = 7;
    int * v898 = v353->cache_dirty;
    v898[v1440] = 0;
    int * v900 = v353->cache_age;
    v900[v1440] = 1;
    int * v902 = v353->cache_age;
    int v903 = v902[v1440];
    int v904 = v902[2];
    int v1446 = v904 + ((int)((unsigned int)(v904 - v903) >> 31));
    v902[2] = v1446;
    int * v906 = v353->cache_age;
    int v907 = v906[3];
    int v1448 = v907 + ((int)((unsigned int)(v907 - v903) >> 31));
    v906[3] = v1448;
    int * v909 = v353->cache_age;
    v909[v1440] = 0;
    v912 = v1440;
  }
  int * v913 = v353->cache_vals;
  int v1451 = v912 * 2;
  v913[v1451] = v357;
  int * v915 = v353->cache_tags;
  int v916 = v915[10];
  int v917 = v915[11];
  bool v1454 = !(((~(((v916 ^ 7) | (-(v916 ^ 7))) >> 31)) | (~(((v917 ^ 7) | (-(v917 ^ 7))) >> 31))) == 0);
  int v971;
  if (v1454) {
    int * v918 = v353->cache_age;
    int v1456 = 10 + ((~(((v917 ^ 7) | (-(v917 ^ 7))) >> 31)) & 1);
    int v919 = v918[v1456];
    int v920 = v918[10];
    int v1457 = v920 + ((int)((unsigned int)(v920 - v919) >> 31));
    v918[10] = v1457;
    int * v922 = v353->cache_age;
    int v923 = v922[11];
    int v1459 = v923 + ((int)((unsigned int)(v923 - v919) >> 31));
    v922[11] = v1459;
    int * v925 = v353->cache_age;
    v925[v1456] = 0;
    v971 = v1456;
  } else {
    int * v928 = v353->cache_age;
    int v929 = v928[10];
    int * v930 = v353->cache_tags;
    int v931 = v930[10];
    int v932 = v928[11];
    int v933 = v930[11];
    int * v934 = v353->cache_dirty;
    int v1465 = 10 + ((((v929 + ((~(((v931 ^ -1) | (-(v931 ^ -1))) >> 31)) & 2)) - (v932 + ((~(((v933 ^ -1) | (-(v933 ^ -1))) >> 31)) & 2))) >> 31) & 1);
    int v935 = v934[v1465];
    bool v1466 = !(v935 == 0);
    if (v1466) {
      int * v936 = v353->cache_tags;
      int v937 = v936[v1465];
      int * v938 = v353->cache_vals;
      int v1469 = (10 + ((((v929 + ((~(((v931 ^ -1) | (-(v931 ^ -1))) >> 31)) & 2)) - (v932 + ((~(((v933 ^ -1) | (-(v933 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
      int v939 = v938[v1469];
      int v1470 = ((10 + ((((v929 + ((~(((v931 ^ -1) | (-(v931 ^ -1))) >> 31)) & 2)) - (v932 + ((~(((v933 ^ -1) | (-(v933 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
      int v940 = v938[v1470];
      int * v941 = v353->mem;
      int v1472 = v937 * 2;
      v941[v1472] = v939;
      int * v943 = v353->mem;
      int v1475 = (v937 * 2) + 1;
      v943[v1475] = v940;
      ;
    } else {
      ;
    }
    int * v948 = v353->mem;
    int v949 = v948[14];
    int v950 = v948[15];
    int * v951 = v353->cache_vals;
    int v1483 = (10 + ((((v929 + ((~(((v931 ^ -1) | (-(v931 ^ -1))) >> 31)) & 2)) - (v932 + ((~(((v933 ^ -1) | (-(v933 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
    v951[v1483] = v949;
    int * v953 = v353->cache_vals;
    int v1486 = ((10 + ((((v929 + ((~(((v931 ^ -1) | (-(v931 ^ -1))) >> 31)) & 2)) - (v932 + ((~(((v933 ^ -1) | (-(v933 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
    v953[v1486] = v950;
    int * v955 = v353->cache_tags;
    v955[v1465] = 7;
    int * v957 = v353->cache_dirty;
    v957[v1465] = 0;
    int * v959 = v353->cache_age;
    v959[v1465] = 1;
    int * v961 = v353->cache_age;
    int v962 = v961[v1465];
    int v963 = v961[10];
    int v1494 = v963 + ((int)((unsigned int)(v963 - v962) >> 31));
    v961[10] = v1494;
    int * v965 = v353->cache_age;
    int v966 = v965[11];
    int v1496 = v966 + ((int)((unsigned int)(v966 - v962) >> 31));
    v965[11] = v1496;
    int * v968 = v353->cache_age;
    v968[v1465] = 0;
    v971 = v1465;
  }
  int * v972 = v353->cache_vals;
  int v1499 = v971 * 2;
  v972[v1499] = v357;
  int * v974 = v353->cache_dirty;
  v974[v971] = 1;
  struct StateT * v997;
  int v976 = v353->timer;
  int v1504 = v976 + 15;
  v353->timer = v1504;
  int * v978 = v353->saved_regs;
  int v979 = v978[8];
  int * v980 = v353->regs;
  v980[8] = v979;
  int * v982 = v353->saved_regs;
  int v983 = v982[9];
  int * v984 = v353->regs;
  v984[9] = v983;
  int * v986 = v353->saved_regs;
  int v987 = v986[11];
  int * v988 = v353->regs;
  v988[11] = v987;
  int * v990 = v353->saved_regs;
  int v991 = v990[12];
  int * v992 = v353->regs;
  v992[12] = v991;
  struct StateT * v994 = slot_5(v353);
  v997 = v994;
  return v997;
}

struct StateT * slot_2(struct StateT * v32) {
  int v33 = v32->timer;
  int v209 = v33 + 1;
  v32->timer = v209;
  int * v35 = v32->regs;
  int v36 = v35[6];
  int * v37 = v32->saved_regs;
  int v38 = v35[7];
  v37[7] = v38;
  int v40 = v32->timer;
  int v215 = v40 + 1;
  v32->timer = v215;
  int * v42 = v32->regs;
  v42[7] = 4;
  int * v44 = v32->cache_tags;
  int v45 = v44[2];
  int v46 = v44[3];
  int v47 = v44[6];
  int v48 = v44[7];
  int v49 = v32->timer;
  int v221 = v49 + ((100 ^ (((~(((v47 ^ 5) | (-(v47 ^ 5))) >> 31)) | (~(((v48 ^ 5) | (-(v48 ^ 5))) >> 31))) & 104)) ^ (((~(((v45 ^ 5) | (-(v45 ^ 5))) >> 31)) | (~(((v46 ^ 5) | (-(v46 ^ 5))) >> 31))) & (1 ^ (100 ^ (((~(((v47 ^ 5) | (-(v47 ^ 5))) >> 31)) | (~(((v48 ^ 5) | (-(v48 ^ 5))) >> 31))) & 104)))));
  v32->timer = v221;
  bool v222 = !(((~(((v45 ^ 5) | (-(v45 ^ 5))) >> 31)) | (~(((v46 ^ 5) | (-(v46 ^ 5))) >> 31))) == 0);
  int v143;
  if (v222) {
    int * v51 = v32->cache_age;
    int v224 = 2 + ((~(((v46 ^ 5) | (-(v46 ^ 5))) >> 31)) & 1);
    int v52 = v51[v224];
    int v53 = v51[2];
    int v225 = v53 + ((int)((unsigned int)(v53 - v52) >> 31));
    v51[2] = v225;
    int * v55 = v32->cache_age;
    int v56 = v55[3];
    int v227 = v56 + ((int)((unsigned int)(v56 - v52) >> 31));
    v55[3] = v227;
    int * v58 = v32->cache_age;
    v58[v224] = 0;
    v143 = v224;
  } else {
    int * v61 = v32->cache_age;
    int v62 = v61[2];
    int * v63 = v32->cache_tags;
    int v64 = v63[2];
    int v65 = v61[3];
    int v66 = v63[3];
    bool v232 = !(((~(((v47 ^ 5) | (-(v47 ^ 5))) >> 31)) | (~(((v48 ^ 5) | (-(v48 ^ 5))) >> 31))) == 0);
    int v120;
    if (v232) {
      int * v67 = v32->cache_age;
      int v234 = 6 + ((~(((v48 ^ 5) | (-(v48 ^ 5))) >> 31)) & 1);
      int v68 = v67[v234];
      int v69 = v67[6];
      int v235 = v69 + ((int)((unsigned int)(v69 - v68) >> 31));
      v67[6] = v235;
      int * v71 = v32->cache_age;
      int v72 = v71[7];
      int v237 = v72 + ((int)((unsigned int)(v72 - v68) >> 31));
      v71[7] = v237;
      int * v74 = v32->cache_age;
      v74[v234] = 0;
      v120 = v234;
    } else {
      int * v77 = v32->cache_age;
      int v78 = v77[6];
      int * v79 = v32->cache_tags;
      int v80 = v79[6];
      int v81 = v77[7];
      int v82 = v79[7];
      int * v83 = v32->cache_dirty;
      int v243 = 6 + ((((v78 + ((~(((v80 ^ -1) | (-(v80 ^ -1))) >> 31)) & 2)) - (v81 + ((~(((v82 ^ -1) | (-(v82 ^ -1))) >> 31)) & 2))) >> 31) & 1);
      int v84 = v83[v243];
      bool v244 = !(v84 == 0);
      if (v244) {
        int * v85 = v32->cache_tags;
        int v86 = v85[v243];
        int * v87 = v32->cache_vals;
        int v247 = (6 + ((((v78 + ((~(((v80 ^ -1) | (-(v80 ^ -1))) >> 31)) & 2)) - (v81 + ((~(((v82 ^ -1) | (-(v82 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
        int v88 = v87[v247];
        int v248 = ((6 + ((((v78 + ((~(((v80 ^ -1) | (-(v80 ^ -1))) >> 31)) & 2)) - (v81 + ((~(((v82 ^ -1) | (-(v82 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
        int v89 = v87[v248];
        int * v90 = v32->mem;
        int v250 = v86 * 2;
        v90[v250] = v88;
        int * v92 = v32->mem;
        int v253 = (v86 * 2) + 1;
        v92[v253] = v89;
        ;
      } else {
        ;
      }
      int * v97 = v32->mem;
      int v98 = v97[10];
      int v99 = v97[11];
      int * v100 = v32->cache_vals;
      int v261 = (6 + ((((v78 + ((~(((v80 ^ -1) | (-(v80 ^ -1))) >> 31)) & 2)) - (v81 + ((~(((v82 ^ -1) | (-(v82 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
      v100[v261] = v98;
      int * v102 = v32->cache_vals;
      int v264 = ((6 + ((((v78 + ((~(((v80 ^ -1) | (-(v80 ^ -1))) >> 31)) & 2)) - (v81 + ((~(((v82 ^ -1) | (-(v82 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
      v102[v264] = v99;
      int * v104 = v32->cache_tags;
      v104[v243] = 5;
      int * v106 = v32->cache_dirty;
      v106[v243] = 0;
      int * v108 = v32->cache_age;
      v108[v243] = 1;
      int * v110 = v32->cache_age;
      int v111 = v110[v243];
      int v112 = v110[6];
      int v273 = v112 + ((int)((unsigned int)(v112 - v111) >> 31));
      v110[6] = v273;
      int * v114 = v32->cache_age;
      int v115 = v114[7];
      int v275 = v115 + ((int)((unsigned int)(v115 - v111) >> 31));
      v114[7] = v275;
      int * v117 = v32->cache_age;
      v117[v243] = 0;
      v120 = v243;
    }
    int * v121 = v32->cache_vals;
    int v278 = v120 * 2;
    int v122 = v121[v278];
    int v279 = (v120 * 2) + 1;
    int v123 = v121[v279];
    int v280 = (2 + ((((v62 + ((~(((v64 ^ -1) | (-(v64 ^ -1))) >> 31)) & 2)) - (v65 + ((~(((v66 ^ -1) | (-(v66 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
    v121[v280] = v122;
    int * v125 = v32->cache_vals;
    int v283 = ((2 + ((((v62 + ((~(((v64 ^ -1) | (-(v64 ^ -1))) >> 31)) & 2)) - (v65 + ((~(((v66 ^ -1) | (-(v66 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
    v125[v283] = v123;
    int * v127 = v32->cache_tags;
    int v286 = 2 + ((((v62 + ((~(((v64 ^ -1) | (-(v64 ^ -1))) >> 31)) & 2)) - (v65 + ((~(((v66 ^ -1) | (-(v66 ^ -1))) >> 31)) & 2))) >> 31) & 1);
    v127[v286] = 5;
    int * v129 = v32->cache_dirty;
    v129[v286] = 0;
    int * v131 = v32->cache_age;
    v131[v286] = 1;
    int * v133 = v32->cache_age;
    int v134 = v133[v286];
    int v135 = v133[2];
    int v293 = v135 + ((int)((unsigned int)(v135 - v134) >> 31));
    v133[2] = v293;
    int * v137 = v32->cache_age;
    int v138 = v137[3];
    int v295 = v138 + ((int)((unsigned int)(v138 - v134) >> 31));
    v137[3] = v295;
    int * v140 = v32->cache_age;
    v140[v286] = 0;
    v143 = v286;
  }
  int * v144 = v32->cache_vals;
  int v298 = v143 * 2;
  v144[v298] = v36;
  int * v146 = v32->cache_tags;
  int v147 = v146[6];
  int v148 = v146[7];
  bool v301 = !(((~(((v147 ^ 5) | (-(v147 ^ 5))) >> 31)) | (~(((v148 ^ 5) | (-(v148 ^ 5))) >> 31))) == 0);
  int v202;
  if (v301) {
    int * v149 = v32->cache_age;
    int v303 = 6 + ((~(((v148 ^ 5) | (-(v148 ^ 5))) >> 31)) & 1);
    int v150 = v149[v303];
    int v151 = v149[6];
    int v304 = v151 + ((int)((unsigned int)(v151 - v150) >> 31));
    v149[6] = v304;
    int * v153 = v32->cache_age;
    int v154 = v153[7];
    int v306 = v154 + ((int)((unsigned int)(v154 - v150) >> 31));
    v153[7] = v306;
    int * v156 = v32->cache_age;
    v156[v303] = 0;
    v202 = v303;
  } else {
    int * v159 = v32->cache_age;
    int v160 = v159[6];
    int * v161 = v32->cache_tags;
    int v162 = v161[6];
    int v163 = v159[7];
    int v164 = v161[7];
    int * v165 = v32->cache_dirty;
    int v312 = 6 + ((((v160 + ((~(((v162 ^ -1) | (-(v162 ^ -1))) >> 31)) & 2)) - (v163 + ((~(((v164 ^ -1) | (-(v164 ^ -1))) >> 31)) & 2))) >> 31) & 1);
    int v166 = v165[v312];
    bool v313 = !(v166 == 0);
    if (v313) {
      int * v167 = v32->cache_tags;
      int v168 = v167[v312];
      int * v169 = v32->cache_vals;
      int v316 = (6 + ((((v160 + ((~(((v162 ^ -1) | (-(v162 ^ -1))) >> 31)) & 2)) - (v163 + ((~(((v164 ^ -1) | (-(v164 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
      int v170 = v169[v316];
      int v317 = ((6 + ((((v160 + ((~(((v162 ^ -1) | (-(v162 ^ -1))) >> 31)) & 2)) - (v163 + ((~(((v164 ^ -1) | (-(v164 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
      int v171 = v169[v317];
      int * v172 = v32->mem;
      int v319 = v168 * 2;
      v172[v319] = v170;
      int * v174 = v32->mem;
      int v322 = (v168 * 2) + 1;
      v174[v322] = v171;
      ;
    } else {
      ;
    }
    int * v179 = v32->mem;
    int v180 = v179[10];
    int v181 = v179[11];
    int * v182 = v32->cache_vals;
    int v330 = (6 + ((((v160 + ((~(((v162 ^ -1) | (-(v162 ^ -1))) >> 31)) & 2)) - (v163 + ((~(((v164 ^ -1) | (-(v164 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
    v182[v330] = v180;
    int * v184 = v32->cache_vals;
    int v333 = ((6 + ((((v160 + ((~(((v162 ^ -1) | (-(v162 ^ -1))) >> 31)) & 2)) - (v163 + ((~(((v164 ^ -1) | (-(v164 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
    v184[v333] = v181;
    int * v186 = v32->cache_tags;
    v186[v312] = 5;
    int * v188 = v32->cache_dirty;
    v188[v312] = 0;
    int * v190 = v32->cache_age;
    v190[v312] = 1;
    int * v192 = v32->cache_age;
    int v193 = v192[v312];
    int v194 = v192[6];
    int v342 = v194 + ((int)((unsigned int)(v194 - v193) >> 31));
    v192[6] = v342;
    int * v196 = v32->cache_age;
    int v197 = v196[7];
    int v344 = v197 + ((int)((unsigned int)(v197 - v193) >> 31));
    v196[7] = v344;
    int * v199 = v32->cache_age;
    v199[v312] = 0;
    v202 = v312;
  }
  int * v203 = v32->cache_vals;
  int v347 = v202 * 2;
  v203[v347] = v36;
  int * v205 = v32->cache_dirty;
  v205[v202] = 1;
  struct StateT * v207 = slot_4(v32);
  return v207;
}

struct StateT * slot_7(struct StateT * v1922) {
  int v1923 = v1922->timer;
  int v2033 = v1923 + 1;
  v1922->timer = v2033;
  int * v1925 = v1922->regs;
  int v1926 = v1925[9];
  int * v1927 = v1922->cache_tags;
  int v2037 = (((int)((unsigned int)((int)((unsigned int)v1926 >> 2)) >> 1)) & 1) * 2;
  int v1928 = v1927[v2037];
  int v2038 = ((((int)((unsigned int)((int)((unsigned int)v1926 >> 2)) >> 1)) & 1) * 2) + 1;
  int v1929 = v1927[v2038];
  int v2039 = 4 + ((((int)((unsigned int)((int)((unsigned int)v1926 >> 2)) >> 1)) & 3) * 2);
  int v1930 = v1927[v2039];
  int v2040 = (4 + ((((int)((unsigned int)((int)((unsigned int)v1926 >> 2)) >> 1)) & 3) * 2)) + 1;
  int v1931 = v1927[v2040];
  int v1932 = v1922->timer;
  int v2041 = v1932 + ((100 ^ (((~(((v1930 ^ ((int)((unsigned int)((int)((unsigned int)v1926 >> 2)) >> 1))) | (-(v1930 ^ ((int)((unsigned int)((int)((unsigned int)v1926 >> 2)) >> 1))))) >> 31)) | (~(((v1931 ^ ((int)((unsigned int)((int)((unsigned int)v1926 >> 2)) >> 1))) | (-(v1931 ^ ((int)((unsigned int)((int)((unsigned int)v1926 >> 2)) >> 1))))) >> 31))) & 104)) ^ (((~(((v1928 ^ ((int)((unsigned int)((int)((unsigned int)v1926 >> 2)) >> 1))) | (-(v1928 ^ ((int)((unsigned int)((int)((unsigned int)v1926 >> 2)) >> 1))))) >> 31)) | (~(((v1929 ^ ((int)((unsigned int)((int)((unsigned int)v1926 >> 2)) >> 1))) | (-(v1929 ^ ((int)((unsigned int)((int)((unsigned int)v1926 >> 2)) >> 1))))) >> 31))) & (1 ^ (100 ^ (((~(((v1930 ^ ((int)((unsigned int)((int)((unsigned int)v1926 >> 2)) >> 1))) | (-(v1930 ^ ((int)((unsigned int)((int)((unsigned int)v1926 >> 2)) >> 1))))) >> 31)) | (~(((v1931 ^ ((int)((unsigned int)((int)((unsigned int)v1926 >> 2)) >> 1))) | (-(v1931 ^ ((int)((unsigned int)((int)((unsigned int)v1926 >> 2)) >> 1))))) >> 31))) & 104)))));
  v1922->timer = v2041;
  int * v1934 = v1922->cache_vals;
  bool v2042 = !(((~(((v1928 ^ ((int)((unsigned int)((int)((unsigned int)v1926 >> 2)) >> 1))) | (-(v1928 ^ ((int)((unsigned int)((int)((unsigned int)v1926 >> 2)) >> 1))))) >> 31)) | (~(((v1929 ^ ((int)((unsigned int)((int)((unsigned int)v1926 >> 2)) >> 1))) | (-(v1929 ^ ((int)((unsigned int)((int)((unsigned int)v1926 >> 2)) >> 1))))) >> 31))) == 0);
  int v2027;
  if (v2042) {
    int * v1935 = v1922->cache_age;
    int v2044 = ((((int)((unsigned int)((int)((unsigned int)v1926 >> 2)) >> 1)) & 1) * 2) + ((~(((v1929 ^ ((int)((unsigned int)((int)((unsigned int)v1926 >> 2)) >> 1))) | (-(v1929 ^ ((int)((unsigned int)((int)((unsigned int)v1926 >> 2)) >> 1))))) >> 31)) & 1);
    int v1936 = v1935[v2044];
    int v1937 = v1935[v2037];
    int v2045 = v1937 + ((int)((unsigned int)(v1937 - v1936) >> 31));
    v1935[v2037] = v2045;
    int * v1939 = v1922->cache_age;
    int v1940 = v1939[v2038];
    int v2047 = v1940 + ((int)((unsigned int)(v1940 - v1936) >> 31));
    v1939[v2038] = v2047;
    int * v1942 = v1922->cache_age;
    v1942[v2044] = 0;
    v2027 = v2044;
  } else {
    int * v1945 = v1922->cache_age;
    int v2051 = (((int)((unsigned int)((int)((unsigned int)v1926 >> 2)) >> 1)) & 1) * 2;
    int v1946 = v1945[v2051];
    int * v1947 = v1922->cache_tags;
    int v1948 = v1947[v2051];
    int v1949 = v1945[v2038];
    int v1950 = v1947[v2038];
    bool v2053 = !(((~(((v1930 ^ ((int)((unsigned int)((int)((unsigned int)v1926 >> 2)) >> 1))) | (-(v1930 ^ ((int)((unsigned int)((int)((unsigned int)v1926 >> 2)) >> 1))))) >> 31)) | (~(((v1931 ^ ((int)((unsigned int)((int)((unsigned int)v1926 >> 2)) >> 1))) | (-(v1931 ^ ((int)((unsigned int)((int)((unsigned int)v1926 >> 2)) >> 1))))) >> 31))) == 0);
    int v2004;
    if (v2053) {
      int * v1951 = v1922->cache_age;
      int v2055 = (4 + ((((int)((unsigned int)((int)((unsigned int)v1926 >> 2)) >> 1)) & 3) * 2)) + ((~(((v1931 ^ ((int)((unsigned int)((int)((unsigned int)v1926 >> 2)) >> 1))) | (-(v1931 ^ ((int)((unsigned int)((int)((unsigned int)v1926 >> 2)) >> 1))))) >> 31)) & 1);
      int v1952 = v1951[v2055];
      int v1953 = v1951[v2039];
      int v2056 = v1953 + ((int)((unsigned int)(v1953 - v1952) >> 31));
      v1951[v2039] = v2056;
      int * v1955 = v1922->cache_age;
      int v1956 = v1955[v2040];
      int v2058 = v1956 + ((int)((unsigned int)(v1956 - v1952) >> 31));
      v1955[v2040] = v2058;
      int * v1958 = v1922->cache_age;
      v1958[v2055] = 0;
      v2004 = v2055;
    } else {
      int * v1961 = v1922->cache_age;
      int v2062 = 4 + ((((int)((unsigned int)((int)((unsigned int)v1926 >> 2)) >> 1)) & 3) * 2);
      int v1962 = v1961[v2062];
      int * v1963 = v1922->cache_tags;
      int v1964 = v1963[v2062];
      int v1965 = v1961[v2040];
      int v1966 = v1963[v2040];
      int * v1967 = v1922->cache_dirty;
      int v2065 = (4 + ((((int)((unsigned int)((int)((unsigned int)v1926 >> 2)) >> 1)) & 3) * 2)) + ((((v1962 + ((~(((v1964 ^ -1) | (-(v1964 ^ -1))) >> 31)) & 2)) - (v1965 + ((~(((v1966 ^ -1) | (-(v1966 ^ -1))) >> 31)) & 2))) >> 31) & 1);
      int v1968 = v1967[v2065];
      bool v2066 = !(v1968 == 0);
      if (v2066) {
        int * v1969 = v1922->cache_tags;
        int v1970 = v1969[v2065];
        int * v1971 = v1922->cache_vals;
        int v2069 = ((4 + ((((int)((unsigned int)((int)((unsigned int)v1926 >> 2)) >> 1)) & 3) * 2)) + ((((v1962 + ((~(((v1964 ^ -1) | (-(v1964 ^ -1))) >> 31)) & 2)) - (v1965 + ((~(((v1966 ^ -1) | (-(v1966 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
        int v1972 = v1971[v2069];
        int v2070 = (((4 + ((((int)((unsigned int)((int)((unsigned int)v1926 >> 2)) >> 1)) & 3) * 2)) + ((((v1962 + ((~(((v1964 ^ -1) | (-(v1964 ^ -1))) >> 31)) & 2)) - (v1965 + ((~(((v1966 ^ -1) | (-(v1966 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
        int v1973 = v1971[v2070];
        int * v1974 = v1922->mem;
        int v2072 = v1970 * 2;
        v1974[v2072] = v1972;
        int * v1976 = v1922->mem;
        int v2075 = (v1970 * 2) + 1;
        v1976[v2075] = v1973;
        ;
      } else {
        ;
      }
      int * v1981 = v1922->mem;
      int v2080 = ((int)((unsigned int)((int)((unsigned int)v1926 >> 2)) >> 1)) * 2;
      int v1982 = v1981[v2080];
      int v2081 = (((int)((unsigned int)((int)((unsigned int)v1926 >> 2)) >> 1)) * 2) + 1;
      int v1983 = v1981[v2081];
      int * v1984 = v1922->cache_vals;
      int v2083 = ((4 + ((((int)((unsigned int)((int)((unsigned int)v1926 >> 2)) >> 1)) & 3) * 2)) + ((((v1962 + ((~(((v1964 ^ -1) | (-(v1964 ^ -1))) >> 31)) & 2)) - (v1965 + ((~(((v1966 ^ -1) | (-(v1966 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
      v1984[v2083] = v1982;
      int * v1986 = v1922->cache_vals;
      int v2086 = (((4 + ((((int)((unsigned int)((int)((unsigned int)v1926 >> 2)) >> 1)) & 3) * 2)) + ((((v1962 + ((~(((v1964 ^ -1) | (-(v1964 ^ -1))) >> 31)) & 2)) - (v1965 + ((~(((v1966 ^ -1) | (-(v1966 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
      v1986[v2086] = v1983;
      int * v1988 = v1922->cache_tags;
      int v2089 = (int)((unsigned int)((int)((unsigned int)v1926 >> 2)) >> 1);
      v1988[v2065] = v2089;
      int * v1990 = v1922->cache_dirty;
      v1990[v2065] = 0;
      int * v1992 = v1922->cache_age;
      v1992[v2065] = 1;
      int * v1994 = v1922->cache_age;
      int v1995 = v1994[v2065];
      int v1996 = v1994[v2039];
      int v2095 = v1996 + ((int)((unsigned int)(v1996 - v1995) >> 31));
      v1994[v2039] = v2095;
      int * v1998 = v1922->cache_age;
      int v1999 = v1998[v2040];
      int v2097 = v1999 + ((int)((unsigned int)(v1999 - v1995) >> 31));
      v1998[v2040] = v2097;
      int * v2001 = v1922->cache_age;
      v2001[v2065] = 0;
      v2004 = v2065;
    }
    int * v2005 = v1922->cache_vals;
    int v2100 = v2004 * 2;
    int v2006 = v2005[v2100];
    int v2101 = (v2004 * 2) + 1;
    int v2007 = v2005[v2101];
    int v2102 = (((((int)((unsigned int)((int)((unsigned int)v1926 >> 2)) >> 1)) & 1) * 2) + ((((v1946 + ((~(((v1948 ^ -1) | (-(v1948 ^ -1))) >> 31)) & 2)) - (v1949 + ((~(((v1950 ^ -1) | (-(v1950 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
    v2005[v2102] = v2006;
    int * v2009 = v1922->cache_vals;
    int v2105 = ((((((int)((unsigned int)((int)((unsigned int)v1926 >> 2)) >> 1)) & 1) * 2) + ((((v1946 + ((~(((v1948 ^ -1) | (-(v1948 ^ -1))) >> 31)) & 2)) - (v1949 + ((~(((v1950 ^ -1) | (-(v1950 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
    v2009[v2105] = v2007;
    int * v2011 = v1922->cache_tags;
    int v2108 = ((((int)((unsigned int)((int)((unsigned int)v1926 >> 2)) >> 1)) & 1) * 2) + ((((v1946 + ((~(((v1948 ^ -1) | (-(v1948 ^ -1))) >> 31)) & 2)) - (v1949 + ((~(((v1950 ^ -1) | (-(v1950 ^ -1))) >> 31)) & 2))) >> 31) & 1);
    int v2109 = (int)((unsigned int)((int)((unsigned int)v1926 >> 2)) >> 1);
    v2011[v2108] = v2109;
    int * v2013 = v1922->cache_dirty;
    v2013[v2108] = 0;
    int * v2015 = v1922->cache_age;
    v2015[v2108] = 1;
    int * v2017 = v1922->cache_age;
    int v2018 = v2017[v2108];
    int v2019 = v2017[v2037];
    int v2115 = v2019 + ((int)((unsigned int)(v2019 - v2018) >> 31));
    v2017[v2037] = v2115;
    int * v2021 = v1922->cache_age;
    int v2022 = v2021[v2038];
    int v2117 = v2022 + ((int)((unsigned int)(v2022 - v2018) >> 31));
    v2021[v2038] = v2117;
    int * v2024 = v1922->cache_age;
    v2024[v2108] = 0;
    v2027 = v2108;
  }
  int v2120 = (v2027 * 2) + (((int)((unsigned int)v1926 >> 2)) & 1);
  int v2028 = v1934[v2120];
  int * v2029 = v1922->regs;
  v2029[11] = v2028;
  struct StateT * v2031 = slot_8(v1922);
  return v2031;
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