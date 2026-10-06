// verify: clean (Eva should report untainted_timer: Valid) [unroll 65]
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
void squared_diverged(bool);

struct StateT2 * slot_12(struct StateT2 * v1826);
struct StateT2 * slot_14(struct StateT2 * v1911);
struct StateT2 * slot_6(struct StateT2 * v631);
struct StateT2 * slot_2(struct StateT2 * v74);
struct StateT2 * snippet(struct StateT2 * v0);
struct StateT2 * slot_10(struct StateT2 * v1761);
struct StateT2 * slot_1(struct StateT2 * v38);
struct StateT2 * slot_8(struct StateT2 * v707);
struct StateT2 * slot_4(struct StateT2 * v134);
struct StateT2 * slot_9(struct StateT2 * v1343);
struct StateT2 * slot_11(struct StateT2 * v1800);
struct StateT2 * slot_0(struct StateT2 * v2);
struct StateT2 * slot_12(struct StateT2 * v1826) {
  struct StateT * v1827 = v1826->a;
  int v1828 = v1827->timer;
  struct StateT * v1829 = v1826->b;
  int v1830 = v1829->timer;
  bool v1843 = v1828 == v1830;
  squared_assert(v1843);
  squared_assume(v1843);
  struct StateT * v1833 = v1826->a;
  int v1834 = v1833->timer;
  int v1845 = v1834 + 1;
  v1833->timer = v1845;
  struct StateT * v1836 = v1826->b;
  int v1837 = v1836->timer;
  int v1847 = v1837 + 1;
  v1836->timer = v1847;
  struct StateT2 * v1839 = slot_4(v1826);
  return v1839;
}

struct StateT2 * slot_14(struct StateT2 * v1911) {
  struct StateT * v1912 = v1911->a;
  int v1913 = v1912->timer;
  struct StateT * v1914 = v1911->b;
  int v1915 = v1914->timer;
  bool v2152 = v1913 == v1915;
  squared_assert(v2152);
  squared_assume(v2152);
  struct StateT * v1918 = v1911->a;
  int * v1919 = v1918->saved_regs;
  int * v1920 = v1918->regs;
  int v1921 = v1920[5];
  v1919[5] = v1921;
  struct StateT * v1923 = v1911->b;
  int * v1924 = v1923->saved_regs;
  int * v1925 = v1923->regs;
  int v1926 = v1925[5];
  v1924[5] = v1926;
  struct StateT * v1928 = v1911->a;
  int v1929 = v1928->timer;
  int v2163 = v1929 + 1;
  v1928->timer = v2163;
  struct StateT * v1931 = v1911->b;
  int v1932 = v1931->timer;
  int v2165 = v1932 + 1;
  v1931->timer = v2165;
  struct StateT * v1934 = v1911->a;
  int * v1935 = v1934->regs;
  int v1936 = v1935[8];
  int * v1937 = v1934->cache_tags;
  int v2170 = (((int)((unsigned int)((int)((unsigned int)v1936 >> 2)) >> 1)) & 1) * 2;
  int v1938 = v1937[v2170];
  int v2171 = ((((int)((unsigned int)((int)((unsigned int)v1936 >> 2)) >> 1)) & 1) * 2) + 1;
  int v1939 = v1937[v2171];
  int v2172 = 4 + ((((int)((unsigned int)((int)((unsigned int)v1936 >> 2)) >> 1)) & 3) * 2);
  int v1940 = v1937[v2172];
  int v2173 = (4 + ((((int)((unsigned int)((int)((unsigned int)v1936 >> 2)) >> 1)) & 3) * 2)) + 1;
  int v1941 = v1937[v2173];
  int v1942 = v1934->timer;
  int v2174 = v1942 + ((100 ^ (((~(((v1940 ^ ((int)((unsigned int)((int)((unsigned int)v1936 >> 2)) >> 1))) | (-(v1940 ^ ((int)((unsigned int)((int)((unsigned int)v1936 >> 2)) >> 1))))) >> 31)) | (~(((v1941 ^ ((int)((unsigned int)((int)((unsigned int)v1936 >> 2)) >> 1))) | (-(v1941 ^ ((int)((unsigned int)((int)((unsigned int)v1936 >> 2)) >> 1))))) >> 31))) & 104)) ^ (((~(((v1938 ^ ((int)((unsigned int)((int)((unsigned int)v1936 >> 2)) >> 1))) | (-(v1938 ^ ((int)((unsigned int)((int)((unsigned int)v1936 >> 2)) >> 1))))) >> 31)) | (~(((v1939 ^ ((int)((unsigned int)((int)((unsigned int)v1936 >> 2)) >> 1))) | (-(v1939 ^ ((int)((unsigned int)((int)((unsigned int)v1936 >> 2)) >> 1))))) >> 31))) & (1 ^ (100 ^ (((~(((v1940 ^ ((int)((unsigned int)((int)((unsigned int)v1936 >> 2)) >> 1))) | (-(v1940 ^ ((int)((unsigned int)((int)((unsigned int)v1936 >> 2)) >> 1))))) >> 31)) | (~(((v1941 ^ ((int)((unsigned int)((int)((unsigned int)v1936 >> 2)) >> 1))) | (-(v1941 ^ ((int)((unsigned int)((int)((unsigned int)v1936 >> 2)) >> 1))))) >> 31))) & 104)))));
  v1934->timer = v2174;
  int * v1944 = v1934->cache_vals;
  bool v2175 = !(((~(((v1938 ^ ((int)((unsigned int)((int)((unsigned int)v1936 >> 2)) >> 1))) | (-(v1938 ^ ((int)((unsigned int)((int)((unsigned int)v1936 >> 2)) >> 1))))) >> 31)) | (~(((v1939 ^ ((int)((unsigned int)((int)((unsigned int)v1936 >> 2)) >> 1))) | (-(v1939 ^ ((int)((unsigned int)((int)((unsigned int)v1936 >> 2)) >> 1))))) >> 31))) == 0);
  int v2037;
  if (v2175) {
    int * v1945 = v1934->cache_age;
    int v2177 = ((((int)((unsigned int)((int)((unsigned int)v1936 >> 2)) >> 1)) & 1) * 2) + ((~(((v1939 ^ ((int)((unsigned int)((int)((unsigned int)v1936 >> 2)) >> 1))) | (-(v1939 ^ ((int)((unsigned int)((int)((unsigned int)v1936 >> 2)) >> 1))))) >> 31)) & 1);
    int v1946 = v1945[v2177];
    int v1947 = v1945[v2170];
    int v2178 = v1947 + ((int)((unsigned int)(v1947 - v1946) >> 31));
    v1945[v2170] = v2178;
    int * v1949 = v1934->cache_age;
    int v1950 = v1949[v2171];
    int v2180 = v1950 + ((int)((unsigned int)(v1950 - v1946) >> 31));
    v1949[v2171] = v2180;
    int * v1952 = v1934->cache_age;
    v1952[v2177] = 0;
    v2037 = v2177;
  } else {
    int * v1955 = v1934->cache_age;
    int v2184 = (((int)((unsigned int)((int)((unsigned int)v1936 >> 2)) >> 1)) & 1) * 2;
    int v1956 = v1955[v2184];
    int * v1957 = v1934->cache_tags;
    int v1958 = v1957[v2184];
    int v1959 = v1955[v2171];
    int v1960 = v1957[v2171];
    bool v2186 = !(((~(((v1940 ^ ((int)((unsigned int)((int)((unsigned int)v1936 >> 2)) >> 1))) | (-(v1940 ^ ((int)((unsigned int)((int)((unsigned int)v1936 >> 2)) >> 1))))) >> 31)) | (~(((v1941 ^ ((int)((unsigned int)((int)((unsigned int)v1936 >> 2)) >> 1))) | (-(v1941 ^ ((int)((unsigned int)((int)((unsigned int)v1936 >> 2)) >> 1))))) >> 31))) == 0);
    int v2014;
    if (v2186) {
      int * v1961 = v1934->cache_age;
      int v2188 = (4 + ((((int)((unsigned int)((int)((unsigned int)v1936 >> 2)) >> 1)) & 3) * 2)) + ((~(((v1941 ^ ((int)((unsigned int)((int)((unsigned int)v1936 >> 2)) >> 1))) | (-(v1941 ^ ((int)((unsigned int)((int)((unsigned int)v1936 >> 2)) >> 1))))) >> 31)) & 1);
      int v1962 = v1961[v2188];
      int v1963 = v1961[v2172];
      int v2189 = v1963 + ((int)((unsigned int)(v1963 - v1962) >> 31));
      v1961[v2172] = v2189;
      int * v1965 = v1934->cache_age;
      int v1966 = v1965[v2173];
      int v2191 = v1966 + ((int)((unsigned int)(v1966 - v1962) >> 31));
      v1965[v2173] = v2191;
      int * v1968 = v1934->cache_age;
      v1968[v2188] = 0;
      v2014 = v2188;
    } else {
      int * v1971 = v1934->cache_age;
      int v2195 = 4 + ((((int)((unsigned int)((int)((unsigned int)v1936 >> 2)) >> 1)) & 3) * 2);
      int v1972 = v1971[v2195];
      int * v1973 = v1934->cache_tags;
      int v1974 = v1973[v2195];
      int v1975 = v1971[v2173];
      int v1976 = v1973[v2173];
      int * v1977 = v1934->cache_dirty;
      int v2198 = (4 + ((((int)((unsigned int)((int)((unsigned int)v1936 >> 2)) >> 1)) & 3) * 2)) + ((((v1972 + ((~(((v1974 ^ -1) | (-(v1974 ^ -1))) >> 31)) & 2)) - (v1975 + ((~(((v1976 ^ -1) | (-(v1976 ^ -1))) >> 31)) & 2))) >> 31) & 1);
      int v1978 = v1977[v2198];
      bool v2199 = !(v1978 == 0);
      if (v2199) {
        int * v1979 = v1934->cache_tags;
        int v1980 = v1979[v2198];
        int * v1981 = v1934->cache_vals;
        int v2202 = ((4 + ((((int)((unsigned int)((int)((unsigned int)v1936 >> 2)) >> 1)) & 3) * 2)) + ((((v1972 + ((~(((v1974 ^ -1) | (-(v1974 ^ -1))) >> 31)) & 2)) - (v1975 + ((~(((v1976 ^ -1) | (-(v1976 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
        int v1982 = v1981[v2202];
        int v2203 = (((4 + ((((int)((unsigned int)((int)((unsigned int)v1936 >> 2)) >> 1)) & 3) * 2)) + ((((v1972 + ((~(((v1974 ^ -1) | (-(v1974 ^ -1))) >> 31)) & 2)) - (v1975 + ((~(((v1976 ^ -1) | (-(v1976 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
        int v1983 = v1981[v2203];
        int * v1984 = v1934->mem;
        int v2205 = v1980 * 2;
        v1984[v2205] = v1982;
        int * v1986 = v1934->mem;
        int v2208 = (v1980 * 2) + 1;
        v1986[v2208] = v1983;
        ;
      } else {
        ;
      }
      int * v1991 = v1934->mem;
      int v2213 = ((int)((unsigned int)((int)((unsigned int)v1936 >> 2)) >> 1)) * 2;
      int v1992 = v1991[v2213];
      int v2214 = (((int)((unsigned int)((int)((unsigned int)v1936 >> 2)) >> 1)) * 2) + 1;
      int v1993 = v1991[v2214];
      int * v1994 = v1934->cache_vals;
      int v2216 = ((4 + ((((int)((unsigned int)((int)((unsigned int)v1936 >> 2)) >> 1)) & 3) * 2)) + ((((v1972 + ((~(((v1974 ^ -1) | (-(v1974 ^ -1))) >> 31)) & 2)) - (v1975 + ((~(((v1976 ^ -1) | (-(v1976 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
      v1994[v2216] = v1992;
      int * v1996 = v1934->cache_vals;
      int v2219 = (((4 + ((((int)((unsigned int)((int)((unsigned int)v1936 >> 2)) >> 1)) & 3) * 2)) + ((((v1972 + ((~(((v1974 ^ -1) | (-(v1974 ^ -1))) >> 31)) & 2)) - (v1975 + ((~(((v1976 ^ -1) | (-(v1976 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
      v1996[v2219] = v1993;
      int * v1998 = v1934->cache_tags;
      int v2222 = (int)((unsigned int)((int)((unsigned int)v1936 >> 2)) >> 1);
      v1998[v2198] = v2222;
      int * v2000 = v1934->cache_dirty;
      v2000[v2198] = 0;
      int * v2002 = v1934->cache_age;
      v2002[v2198] = 1;
      int * v2004 = v1934->cache_age;
      int v2005 = v2004[v2198];
      int v2006 = v2004[v2172];
      int v2228 = v2006 + ((int)((unsigned int)(v2006 - v2005) >> 31));
      v2004[v2172] = v2228;
      int * v2008 = v1934->cache_age;
      int v2009 = v2008[v2173];
      int v2230 = v2009 + ((int)((unsigned int)(v2009 - v2005) >> 31));
      v2008[v2173] = v2230;
      int * v2011 = v1934->cache_age;
      v2011[v2198] = 0;
      v2014 = v2198;
    }
    int * v2015 = v1934->cache_vals;
    int v2233 = v2014 * 2;
    int v2016 = v2015[v2233];
    int v2234 = (v2014 * 2) + 1;
    int v2017 = v2015[v2234];
    int v2235 = (((((int)((unsigned int)((int)((unsigned int)v1936 >> 2)) >> 1)) & 1) * 2) + ((((v1956 + ((~(((v1958 ^ -1) | (-(v1958 ^ -1))) >> 31)) & 2)) - (v1959 + ((~(((v1960 ^ -1) | (-(v1960 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
    v2015[v2235] = v2016;
    int * v2019 = v1934->cache_vals;
    int v2238 = ((((((int)((unsigned int)((int)((unsigned int)v1936 >> 2)) >> 1)) & 1) * 2) + ((((v1956 + ((~(((v1958 ^ -1) | (-(v1958 ^ -1))) >> 31)) & 2)) - (v1959 + ((~(((v1960 ^ -1) | (-(v1960 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
    v2019[v2238] = v2017;
    int * v2021 = v1934->cache_tags;
    int v2241 = ((((int)((unsigned int)((int)((unsigned int)v1936 >> 2)) >> 1)) & 1) * 2) + ((((v1956 + ((~(((v1958 ^ -1) | (-(v1958 ^ -1))) >> 31)) & 2)) - (v1959 + ((~(((v1960 ^ -1) | (-(v1960 ^ -1))) >> 31)) & 2))) >> 31) & 1);
    int v2242 = (int)((unsigned int)((int)((unsigned int)v1936 >> 2)) >> 1);
    v2021[v2241] = v2242;
    int * v2023 = v1934->cache_dirty;
    v2023[v2241] = 0;
    int * v2025 = v1934->cache_age;
    v2025[v2241] = 1;
    int * v2027 = v1934->cache_age;
    int v2028 = v2027[v2241];
    int v2029 = v2027[v2170];
    int v2248 = v2029 + ((int)((unsigned int)(v2029 - v2028) >> 31));
    v2027[v2170] = v2248;
    int * v2031 = v1934->cache_age;
    int v2032 = v2031[v2171];
    int v2250 = v2032 + ((int)((unsigned int)(v2032 - v2028) >> 31));
    v2031[v2171] = v2250;
    int * v2034 = v1934->cache_age;
    v2034[v2241] = 0;
    v2037 = v2241;
  }
  int v2253 = (v2037 * 2) + (((int)((unsigned int)v1936 >> 2)) & 1);
  int v2038 = v1944[v2253];
  int * v2039 = v1934->regs;
  v2039[5] = v2038;
  struct StateT * v2041 = v1911->b;
  int * v2042 = v2041->regs;
  int v2043 = v2042[8];
  int * v2044 = v2041->cache_tags;
  int v2259 = (((int)((unsigned int)((int)((unsigned int)v2043 >> 2)) >> 1)) & 1) * 2;
  int v2045 = v2044[v2259];
  int v2260 = ((((int)((unsigned int)((int)((unsigned int)v2043 >> 2)) >> 1)) & 1) * 2) + 1;
  int v2046 = v2044[v2260];
  int v2261 = 4 + ((((int)((unsigned int)((int)((unsigned int)v2043 >> 2)) >> 1)) & 3) * 2);
  int v2047 = v2044[v2261];
  int v2262 = (4 + ((((int)((unsigned int)((int)((unsigned int)v2043 >> 2)) >> 1)) & 3) * 2)) + 1;
  int v2048 = v2044[v2262];
  int v2049 = v2041->timer;
  int v2263 = v2049 + ((100 ^ (((~(((v2047 ^ ((int)((unsigned int)((int)((unsigned int)v2043 >> 2)) >> 1))) | (-(v2047 ^ ((int)((unsigned int)((int)((unsigned int)v2043 >> 2)) >> 1))))) >> 31)) | (~(((v2048 ^ ((int)((unsigned int)((int)((unsigned int)v2043 >> 2)) >> 1))) | (-(v2048 ^ ((int)((unsigned int)((int)((unsigned int)v2043 >> 2)) >> 1))))) >> 31))) & 104)) ^ (((~(((v2045 ^ ((int)((unsigned int)((int)((unsigned int)v2043 >> 2)) >> 1))) | (-(v2045 ^ ((int)((unsigned int)((int)((unsigned int)v2043 >> 2)) >> 1))))) >> 31)) | (~(((v2046 ^ ((int)((unsigned int)((int)((unsigned int)v2043 >> 2)) >> 1))) | (-(v2046 ^ ((int)((unsigned int)((int)((unsigned int)v2043 >> 2)) >> 1))))) >> 31))) & (1 ^ (100 ^ (((~(((v2047 ^ ((int)((unsigned int)((int)((unsigned int)v2043 >> 2)) >> 1))) | (-(v2047 ^ ((int)((unsigned int)((int)((unsigned int)v2043 >> 2)) >> 1))))) >> 31)) | (~(((v2048 ^ ((int)((unsigned int)((int)((unsigned int)v2043 >> 2)) >> 1))) | (-(v2048 ^ ((int)((unsigned int)((int)((unsigned int)v2043 >> 2)) >> 1))))) >> 31))) & 104)))));
  v2041->timer = v2263;
  int * v2051 = v2041->cache_vals;
  bool v2264 = !(((~(((v2045 ^ ((int)((unsigned int)((int)((unsigned int)v2043 >> 2)) >> 1))) | (-(v2045 ^ ((int)((unsigned int)((int)((unsigned int)v2043 >> 2)) >> 1))))) >> 31)) | (~(((v2046 ^ ((int)((unsigned int)((int)((unsigned int)v2043 >> 2)) >> 1))) | (-(v2046 ^ ((int)((unsigned int)((int)((unsigned int)v2043 >> 2)) >> 1))))) >> 31))) == 0);
  int v2144;
  if (v2264) {
    int * v2052 = v2041->cache_age;
    int v2266 = ((((int)((unsigned int)((int)((unsigned int)v2043 >> 2)) >> 1)) & 1) * 2) + ((~(((v2046 ^ ((int)((unsigned int)((int)((unsigned int)v2043 >> 2)) >> 1))) | (-(v2046 ^ ((int)((unsigned int)((int)((unsigned int)v2043 >> 2)) >> 1))))) >> 31)) & 1);
    int v2053 = v2052[v2266];
    int v2054 = v2052[v2259];
    int v2267 = v2054 + ((int)((unsigned int)(v2054 - v2053) >> 31));
    v2052[v2259] = v2267;
    int * v2056 = v2041->cache_age;
    int v2057 = v2056[v2260];
    int v2269 = v2057 + ((int)((unsigned int)(v2057 - v2053) >> 31));
    v2056[v2260] = v2269;
    int * v2059 = v2041->cache_age;
    v2059[v2266] = 0;
    v2144 = v2266;
  } else {
    int * v2062 = v2041->cache_age;
    int v2273 = (((int)((unsigned int)((int)((unsigned int)v2043 >> 2)) >> 1)) & 1) * 2;
    int v2063 = v2062[v2273];
    int * v2064 = v2041->cache_tags;
    int v2065 = v2064[v2273];
    int v2066 = v2062[v2260];
    int v2067 = v2064[v2260];
    bool v2275 = !(((~(((v2047 ^ ((int)((unsigned int)((int)((unsigned int)v2043 >> 2)) >> 1))) | (-(v2047 ^ ((int)((unsigned int)((int)((unsigned int)v2043 >> 2)) >> 1))))) >> 31)) | (~(((v2048 ^ ((int)((unsigned int)((int)((unsigned int)v2043 >> 2)) >> 1))) | (-(v2048 ^ ((int)((unsigned int)((int)((unsigned int)v2043 >> 2)) >> 1))))) >> 31))) == 0);
    int v2121;
    if (v2275) {
      int * v2068 = v2041->cache_age;
      int v2277 = (4 + ((((int)((unsigned int)((int)((unsigned int)v2043 >> 2)) >> 1)) & 3) * 2)) + ((~(((v2048 ^ ((int)((unsigned int)((int)((unsigned int)v2043 >> 2)) >> 1))) | (-(v2048 ^ ((int)((unsigned int)((int)((unsigned int)v2043 >> 2)) >> 1))))) >> 31)) & 1);
      int v2069 = v2068[v2277];
      int v2070 = v2068[v2261];
      int v2278 = v2070 + ((int)((unsigned int)(v2070 - v2069) >> 31));
      v2068[v2261] = v2278;
      int * v2072 = v2041->cache_age;
      int v2073 = v2072[v2262];
      int v2280 = v2073 + ((int)((unsigned int)(v2073 - v2069) >> 31));
      v2072[v2262] = v2280;
      int * v2075 = v2041->cache_age;
      v2075[v2277] = 0;
      v2121 = v2277;
    } else {
      int * v2078 = v2041->cache_age;
      int v2284 = 4 + ((((int)((unsigned int)((int)((unsigned int)v2043 >> 2)) >> 1)) & 3) * 2);
      int v2079 = v2078[v2284];
      int * v2080 = v2041->cache_tags;
      int v2081 = v2080[v2284];
      int v2082 = v2078[v2262];
      int v2083 = v2080[v2262];
      int * v2084 = v2041->cache_dirty;
      int v2287 = (4 + ((((int)((unsigned int)((int)((unsigned int)v2043 >> 2)) >> 1)) & 3) * 2)) + ((((v2079 + ((~(((v2081 ^ -1) | (-(v2081 ^ -1))) >> 31)) & 2)) - (v2082 + ((~(((v2083 ^ -1) | (-(v2083 ^ -1))) >> 31)) & 2))) >> 31) & 1);
      int v2085 = v2084[v2287];
      bool v2288 = !(v2085 == 0);
      if (v2288) {
        int * v2086 = v2041->cache_tags;
        int v2087 = v2086[v2287];
        int * v2088 = v2041->cache_vals;
        int v2291 = ((4 + ((((int)((unsigned int)((int)((unsigned int)v2043 >> 2)) >> 1)) & 3) * 2)) + ((((v2079 + ((~(((v2081 ^ -1) | (-(v2081 ^ -1))) >> 31)) & 2)) - (v2082 + ((~(((v2083 ^ -1) | (-(v2083 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
        int v2089 = v2088[v2291];
        int v2292 = (((4 + ((((int)((unsigned int)((int)((unsigned int)v2043 >> 2)) >> 1)) & 3) * 2)) + ((((v2079 + ((~(((v2081 ^ -1) | (-(v2081 ^ -1))) >> 31)) & 2)) - (v2082 + ((~(((v2083 ^ -1) | (-(v2083 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
        int v2090 = v2088[v2292];
        int * v2091 = v2041->mem;
        int v2294 = v2087 * 2;
        v2091[v2294] = v2089;
        int * v2093 = v2041->mem;
        int v2297 = (v2087 * 2) + 1;
        v2093[v2297] = v2090;
        ;
      } else {
        ;
      }
      int * v2098 = v2041->mem;
      int v2302 = ((int)((unsigned int)((int)((unsigned int)v2043 >> 2)) >> 1)) * 2;
      int v2099 = v2098[v2302];
      int v2303 = (((int)((unsigned int)((int)((unsigned int)v2043 >> 2)) >> 1)) * 2) + 1;
      int v2100 = v2098[v2303];
      int * v2101 = v2041->cache_vals;
      int v2305 = ((4 + ((((int)((unsigned int)((int)((unsigned int)v2043 >> 2)) >> 1)) & 3) * 2)) + ((((v2079 + ((~(((v2081 ^ -1) | (-(v2081 ^ -1))) >> 31)) & 2)) - (v2082 + ((~(((v2083 ^ -1) | (-(v2083 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
      v2101[v2305] = v2099;
      int * v2103 = v2041->cache_vals;
      int v2308 = (((4 + ((((int)((unsigned int)((int)((unsigned int)v2043 >> 2)) >> 1)) & 3) * 2)) + ((((v2079 + ((~(((v2081 ^ -1) | (-(v2081 ^ -1))) >> 31)) & 2)) - (v2082 + ((~(((v2083 ^ -1) | (-(v2083 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
      v2103[v2308] = v2100;
      int * v2105 = v2041->cache_tags;
      int v2311 = (int)((unsigned int)((int)((unsigned int)v2043 >> 2)) >> 1);
      v2105[v2287] = v2311;
      int * v2107 = v2041->cache_dirty;
      v2107[v2287] = 0;
      int * v2109 = v2041->cache_age;
      v2109[v2287] = 1;
      int * v2111 = v2041->cache_age;
      int v2112 = v2111[v2287];
      int v2113 = v2111[v2261];
      int v2317 = v2113 + ((int)((unsigned int)(v2113 - v2112) >> 31));
      v2111[v2261] = v2317;
      int * v2115 = v2041->cache_age;
      int v2116 = v2115[v2262];
      int v2319 = v2116 + ((int)((unsigned int)(v2116 - v2112) >> 31));
      v2115[v2262] = v2319;
      int * v2118 = v2041->cache_age;
      v2118[v2287] = 0;
      v2121 = v2287;
    }
    int * v2122 = v2041->cache_vals;
    int v2322 = v2121 * 2;
    int v2123 = v2122[v2322];
    int v2323 = (v2121 * 2) + 1;
    int v2124 = v2122[v2323];
    int v2324 = (((((int)((unsigned int)((int)((unsigned int)v2043 >> 2)) >> 1)) & 1) * 2) + ((((v2063 + ((~(((v2065 ^ -1) | (-(v2065 ^ -1))) >> 31)) & 2)) - (v2066 + ((~(((v2067 ^ -1) | (-(v2067 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
    v2122[v2324] = v2123;
    int * v2126 = v2041->cache_vals;
    int v2327 = ((((((int)((unsigned int)((int)((unsigned int)v2043 >> 2)) >> 1)) & 1) * 2) + ((((v2063 + ((~(((v2065 ^ -1) | (-(v2065 ^ -1))) >> 31)) & 2)) - (v2066 + ((~(((v2067 ^ -1) | (-(v2067 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
    v2126[v2327] = v2124;
    int * v2128 = v2041->cache_tags;
    int v2330 = ((((int)((unsigned int)((int)((unsigned int)v2043 >> 2)) >> 1)) & 1) * 2) + ((((v2063 + ((~(((v2065 ^ -1) | (-(v2065 ^ -1))) >> 31)) & 2)) - (v2066 + ((~(((v2067 ^ -1) | (-(v2067 ^ -1))) >> 31)) & 2))) >> 31) & 1);
    int v2331 = (int)((unsigned int)((int)((unsigned int)v2043 >> 2)) >> 1);
    v2128[v2330] = v2331;
    int * v2130 = v2041->cache_dirty;
    v2130[v2330] = 0;
    int * v2132 = v2041->cache_age;
    v2132[v2330] = 1;
    int * v2134 = v2041->cache_age;
    int v2135 = v2134[v2330];
    int v2136 = v2134[v2259];
    int v2337 = v2136 + ((int)((unsigned int)(v2136 - v2135) >> 31));
    v2134[v2259] = v2337;
    int * v2138 = v2041->cache_age;
    int v2139 = v2138[v2260];
    int v2339 = v2139 + ((int)((unsigned int)(v2139 - v2135) >> 31));
    v2138[v2260] = v2339;
    int * v2141 = v2041->cache_age;
    v2141[v2330] = 0;
    v2144 = v2330;
  }
  int v2342 = (v2144 * 2) + (((int)((unsigned int)v2043 >> 2)) & 1);
  int v2145 = v2051[v2342];
  int * v2146 = v2041->regs;
  v2146[5] = v2145;
  struct StateT2 * v2148 = slot_6(v1911);
  return v2148;
}

struct StateT2 * slot_6(struct StateT2 * v631) {
  struct StateT * v632 = v631->a;
  int v633 = v632->timer;
  struct StateT * v634 = v631->b;
  int v635 = v634->timer;
  bool v677 = v633 == v635;
  squared_assert(v677);
  squared_assume(v677);
  struct StateT * v638 = v631->a;
  int * v639 = v638->regs;
  int v640 = v639[6];
  int v641 = v639[7];
  struct StateT * v642 = v631->b;
  int * v643 = v642->regs;
  int v644 = v643[6];
  int v645 = v643[7];
  bool v684 = (v640 >= v641) == (v644 >= v645);
  squared_diverged(v684);
  squared_assume(v684);
  bool v685 = v640 >= v641;
  struct StateT2 * v673;
  if (v685) {
    struct StateT * v648 = v631->a;
    int v649 = v648->timer;
    int v687 = v649 + 15;
    v648->timer = v687;
    int * v651 = v648->saved_regs;
    int v652 = v651[8];
    int * v653 = v648->regs;
    v653[8] = v652;
    int * v655 = v648->saved_regs;
    int v656 = v655[5];
    int * v657 = v648->regs;
    v657[5] = v656;
    struct StateT * v659 = v631->b;
    int v660 = v659->timer;
    int v697 = v660 + 15;
    v659->timer = v697;
    int * v662 = v659->saved_regs;
    int v663 = v662[8];
    int * v664 = v659->regs;
    v664[8] = v663;
    int * v666 = v659->saved_regs;
    int v667 = v666[5];
    int * v668 = v659->regs;
    v668[5] = v667;
    v673 = v631;
  } else {
    struct StateT2 * v671 = slot_8(v631);
    v673 = v671;
  }
  return v673;
}

struct StateT2 * slot_2(struct StateT2 * v74) {
  struct StateT * v75 = v74->a;
  int v76 = v75->timer;
  struct StateT * v77 = v74->b;
  int v78 = v77->timer;
  bool v97 = v76 == v78;
  squared_assert(v97);
  squared_assume(v97);
  struct StateT * v81 = v74->a;
  int v82 = v81->timer;
  int v99 = v82 + 1;
  v81->timer = v99;
  struct StateT * v84 = v74->b;
  int v85 = v84->timer;
  int v101 = v85 + 1;
  v84->timer = v101;
  struct StateT * v87 = v74->a;
  int * v88 = v87->regs;
  v88[9] = 80;
  struct StateT * v90 = v74->b;
  int * v91 = v90->regs;
  v91[9] = 80;
  struct StateT2 * v93 = slot_12(v74);
  return v93;
}

struct StateT2 * snippet(struct StateT2 * v0) {
  struct StateT2 * v1 = slot_0(v0);
  return v1;
}

struct StateT2 * slot_10(struct StateT2 * v1761) {
  struct StateT * v1762 = v1761->a;
  int v1763 = v1762->timer;
  struct StateT * v1764 = v1761->b;
  int v1765 = v1764->timer;
  bool v1786 = v1763 == v1765;
  squared_assert(v1786);
  squared_assume(v1786);
  struct StateT * v1768 = v1761->a;
  int v1769 = v1768->timer;
  int v1788 = v1769 + 1;
  v1768->timer = v1788;
  struct StateT * v1771 = v1761->b;
  int v1772 = v1771->timer;
  int v1790 = v1772 + 1;
  v1771->timer = v1790;
  struct StateT * v1774 = v1761->a;
  int * v1775 = v1774->regs;
  int v1776 = v1775[6];
  int v1794 = v1776 + 4;
  v1775[6] = v1794;
  struct StateT * v1778 = v1761->b;
  int * v1779 = v1778->regs;
  int v1780 = v1779[6];
  int v1797 = v1780 + 4;
  v1779[6] = v1797;
  struct StateT2 * v1782 = slot_11(v1761);
  return v1782;
}

struct StateT2 * slot_1(struct StateT2 * v38) {
  struct StateT * v39 = v38->a;
  int v40 = v39->timer;
  struct StateT * v41 = v38->b;
  int v42 = v41->timer;
  bool v61 = v40 == v42;
  squared_assert(v61);
  squared_assume(v61);
  struct StateT * v45 = v38->a;
  int v46 = v45->timer;
  int v63 = v46 + 1;
  v45->timer = v63;
  struct StateT * v48 = v38->b;
  int v49 = v48->timer;
  int v65 = v49 + 1;
  v48->timer = v65;
  struct StateT * v51 = v38->a;
  int * v52 = v51->regs;
  v52[7] = 16;
  struct StateT * v54 = v38->b;
  int * v55 = v54->regs;
  v55[7] = 16;
  struct StateT2 * v57 = slot_2(v38);
  return v57;
}

struct StateT2 * slot_8(struct StateT2 * v707) {
  struct StateT * v708 = v707->a;
  int v709 = v708->timer;
  struct StateT * v710 = v707->b;
  int v711 = v710->timer;
  bool v1058 = v709 == v711;
  squared_assert(v1058);
  squared_assume(v1058);
  struct StateT * v714 = v707->a;
  int v715 = v714->timer;
  int v1060 = v715 + 1;
  v714->timer = v1060;
  struct StateT * v717 = v707->b;
  int v718 = v717->timer;
  int v1062 = v718 + 1;
  v717->timer = v1062;
  struct StateT * v720 = v707->a;
  int * v721 = v720->regs;
  int v722 = v721[6];
  int v723 = v721[5];
  int * v724 = v720->cache_tags;
  int v1068 = (((int)((unsigned int)((int)((unsigned int)v722 >> 2)) >> 1)) & 1) * 2;
  int v725 = v724[v1068];
  int v1069 = ((((int)((unsigned int)((int)((unsigned int)v722 >> 2)) >> 1)) & 1) * 2) + 1;
  int v726 = v724[v1069];
  int v1070 = 4 + ((((int)((unsigned int)((int)((unsigned int)v722 >> 2)) >> 1)) & 3) * 2);
  int v727 = v724[v1070];
  int v1071 = (4 + ((((int)((unsigned int)((int)((unsigned int)v722 >> 2)) >> 1)) & 3) * 2)) + 1;
  int v728 = v724[v1071];
  int v729 = v720->timer;
  int v1072 = v729 + ((100 ^ (((~(((v727 ^ ((int)((unsigned int)((int)((unsigned int)v722 >> 2)) >> 1))) | (-(v727 ^ ((int)((unsigned int)((int)((unsigned int)v722 >> 2)) >> 1))))) >> 31)) | (~(((v728 ^ ((int)((unsigned int)((int)((unsigned int)v722 >> 2)) >> 1))) | (-(v728 ^ ((int)((unsigned int)((int)((unsigned int)v722 >> 2)) >> 1))))) >> 31))) & 104)) ^ (((~(((v725 ^ ((int)((unsigned int)((int)((unsigned int)v722 >> 2)) >> 1))) | (-(v725 ^ ((int)((unsigned int)((int)((unsigned int)v722 >> 2)) >> 1))))) >> 31)) | (~(((v726 ^ ((int)((unsigned int)((int)((unsigned int)v722 >> 2)) >> 1))) | (-(v726 ^ ((int)((unsigned int)((int)((unsigned int)v722 >> 2)) >> 1))))) >> 31))) & (1 ^ (100 ^ (((~(((v727 ^ ((int)((unsigned int)((int)((unsigned int)v722 >> 2)) >> 1))) | (-(v727 ^ ((int)((unsigned int)((int)((unsigned int)v722 >> 2)) >> 1))))) >> 31)) | (~(((v728 ^ ((int)((unsigned int)((int)((unsigned int)v722 >> 2)) >> 1))) | (-(v728 ^ ((int)((unsigned int)((int)((unsigned int)v722 >> 2)) >> 1))))) >> 31))) & 104)))));
  v720->timer = v1072;
  bool v1073 = !(((~(((v725 ^ ((int)((unsigned int)((int)((unsigned int)v722 >> 2)) >> 1))) | (-(v725 ^ ((int)((unsigned int)((int)((unsigned int)v722 >> 2)) >> 1))))) >> 31)) | (~(((v726 ^ ((int)((unsigned int)((int)((unsigned int)v722 >> 2)) >> 1))) | (-(v726 ^ ((int)((unsigned int)((int)((unsigned int)v722 >> 2)) >> 1))))) >> 31))) == 0);
  int v823;
  if (v1073) {
    int * v731 = v720->cache_age;
    int v1075 = ((((int)((unsigned int)((int)((unsigned int)v722 >> 2)) >> 1)) & 1) * 2) + ((~(((v726 ^ ((int)((unsigned int)((int)((unsigned int)v722 >> 2)) >> 1))) | (-(v726 ^ ((int)((unsigned int)((int)((unsigned int)v722 >> 2)) >> 1))))) >> 31)) & 1);
    int v732 = v731[v1075];
    int v733 = v731[v1068];
    int v1076 = v733 + ((int)((unsigned int)(v733 - v732) >> 31));
    v731[v1068] = v1076;
    int * v735 = v720->cache_age;
    int v736 = v735[v1069];
    int v1078 = v736 + ((int)((unsigned int)(v736 - v732) >> 31));
    v735[v1069] = v1078;
    int * v738 = v720->cache_age;
    v738[v1075] = 0;
    v823 = v1075;
  } else {
    int * v741 = v720->cache_age;
    int v1082 = (((int)((unsigned int)((int)((unsigned int)v722 >> 2)) >> 1)) & 1) * 2;
    int v742 = v741[v1082];
    int * v743 = v720->cache_tags;
    int v744 = v743[v1082];
    int v745 = v741[v1069];
    int v746 = v743[v1069];
    bool v1084 = !(((~(((v727 ^ ((int)((unsigned int)((int)((unsigned int)v722 >> 2)) >> 1))) | (-(v727 ^ ((int)((unsigned int)((int)((unsigned int)v722 >> 2)) >> 1))))) >> 31)) | (~(((v728 ^ ((int)((unsigned int)((int)((unsigned int)v722 >> 2)) >> 1))) | (-(v728 ^ ((int)((unsigned int)((int)((unsigned int)v722 >> 2)) >> 1))))) >> 31))) == 0);
    int v800;
    if (v1084) {
      int * v747 = v720->cache_age;
      int v1086 = (4 + ((((int)((unsigned int)((int)((unsigned int)v722 >> 2)) >> 1)) & 3) * 2)) + ((~(((v728 ^ ((int)((unsigned int)((int)((unsigned int)v722 >> 2)) >> 1))) | (-(v728 ^ ((int)((unsigned int)((int)((unsigned int)v722 >> 2)) >> 1))))) >> 31)) & 1);
      int v748 = v747[v1086];
      int v749 = v747[v1070];
      int v1087 = v749 + ((int)((unsigned int)(v749 - v748) >> 31));
      v747[v1070] = v1087;
      int * v751 = v720->cache_age;
      int v752 = v751[v1071];
      int v1089 = v752 + ((int)((unsigned int)(v752 - v748) >> 31));
      v751[v1071] = v1089;
      int * v754 = v720->cache_age;
      v754[v1086] = 0;
      v800 = v1086;
    } else {
      int * v757 = v720->cache_age;
      int v1093 = 4 + ((((int)((unsigned int)((int)((unsigned int)v722 >> 2)) >> 1)) & 3) * 2);
      int v758 = v757[v1093];
      int * v759 = v720->cache_tags;
      int v760 = v759[v1093];
      int v761 = v757[v1071];
      int v762 = v759[v1071];
      int * v763 = v720->cache_dirty;
      int v1096 = (4 + ((((int)((unsigned int)((int)((unsigned int)v722 >> 2)) >> 1)) & 3) * 2)) + ((((v758 + ((~(((v760 ^ -1) | (-(v760 ^ -1))) >> 31)) & 2)) - (v761 + ((~(((v762 ^ -1) | (-(v762 ^ -1))) >> 31)) & 2))) >> 31) & 1);
      int v764 = v763[v1096];
      bool v1097 = !(v764 == 0);
      if (v1097) {
        int * v765 = v720->cache_tags;
        int v766 = v765[v1096];
        int * v767 = v720->cache_vals;
        int v1100 = ((4 + ((((int)((unsigned int)((int)((unsigned int)v722 >> 2)) >> 1)) & 3) * 2)) + ((((v758 + ((~(((v760 ^ -1) | (-(v760 ^ -1))) >> 31)) & 2)) - (v761 + ((~(((v762 ^ -1) | (-(v762 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
        int v768 = v767[v1100];
        int v1101 = (((4 + ((((int)((unsigned int)((int)((unsigned int)v722 >> 2)) >> 1)) & 3) * 2)) + ((((v758 + ((~(((v760 ^ -1) | (-(v760 ^ -1))) >> 31)) & 2)) - (v761 + ((~(((v762 ^ -1) | (-(v762 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
        int v769 = v767[v1101];
        int * v770 = v720->mem;
        int v1103 = v766 * 2;
        v770[v1103] = v768;
        int * v772 = v720->mem;
        int v1106 = (v766 * 2) + 1;
        v772[v1106] = v769;
        ;
      } else {
        ;
      }
      int * v777 = v720->mem;
      int v1111 = ((int)((unsigned int)((int)((unsigned int)v722 >> 2)) >> 1)) * 2;
      int v778 = v777[v1111];
      int v1112 = (((int)((unsigned int)((int)((unsigned int)v722 >> 2)) >> 1)) * 2) + 1;
      int v779 = v777[v1112];
      int * v780 = v720->cache_vals;
      int v1114 = ((4 + ((((int)((unsigned int)((int)((unsigned int)v722 >> 2)) >> 1)) & 3) * 2)) + ((((v758 + ((~(((v760 ^ -1) | (-(v760 ^ -1))) >> 31)) & 2)) - (v761 + ((~(((v762 ^ -1) | (-(v762 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
      v780[v1114] = v778;
      int * v782 = v720->cache_vals;
      int v1117 = (((4 + ((((int)((unsigned int)((int)((unsigned int)v722 >> 2)) >> 1)) & 3) * 2)) + ((((v758 + ((~(((v760 ^ -1) | (-(v760 ^ -1))) >> 31)) & 2)) - (v761 + ((~(((v762 ^ -1) | (-(v762 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
      v782[v1117] = v779;
      int * v784 = v720->cache_tags;
      int v1120 = (int)((unsigned int)((int)((unsigned int)v722 >> 2)) >> 1);
      v784[v1096] = v1120;
      int * v786 = v720->cache_dirty;
      v786[v1096] = 0;
      int * v788 = v720->cache_age;
      v788[v1096] = 1;
      int * v790 = v720->cache_age;
      int v791 = v790[v1096];
      int v792 = v790[v1070];
      int v1126 = v792 + ((int)((unsigned int)(v792 - v791) >> 31));
      v790[v1070] = v1126;
      int * v794 = v720->cache_age;
      int v795 = v794[v1071];
      int v1128 = v795 + ((int)((unsigned int)(v795 - v791) >> 31));
      v794[v1071] = v1128;
      int * v797 = v720->cache_age;
      v797[v1096] = 0;
      v800 = v1096;
    }
    int * v801 = v720->cache_vals;
    int v1131 = v800 * 2;
    int v802 = v801[v1131];
    int v1132 = (v800 * 2) + 1;
    int v803 = v801[v1132];
    int v1133 = (((((int)((unsigned int)((int)((unsigned int)v722 >> 2)) >> 1)) & 1) * 2) + ((((v742 + ((~(((v744 ^ -1) | (-(v744 ^ -1))) >> 31)) & 2)) - (v745 + ((~(((v746 ^ -1) | (-(v746 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
    v801[v1133] = v802;
    int * v805 = v720->cache_vals;
    int v1136 = ((((((int)((unsigned int)((int)((unsigned int)v722 >> 2)) >> 1)) & 1) * 2) + ((((v742 + ((~(((v744 ^ -1) | (-(v744 ^ -1))) >> 31)) & 2)) - (v745 + ((~(((v746 ^ -1) | (-(v746 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
    v805[v1136] = v803;
    int * v807 = v720->cache_tags;
    int v1139 = ((((int)((unsigned int)((int)((unsigned int)v722 >> 2)) >> 1)) & 1) * 2) + ((((v742 + ((~(((v744 ^ -1) | (-(v744 ^ -1))) >> 31)) & 2)) - (v745 + ((~(((v746 ^ -1) | (-(v746 ^ -1))) >> 31)) & 2))) >> 31) & 1);
    int v1140 = (int)((unsigned int)((int)((unsigned int)v722 >> 2)) >> 1);
    v807[v1139] = v1140;
    int * v809 = v720->cache_dirty;
    v809[v1139] = 0;
    int * v811 = v720->cache_age;
    v811[v1139] = 1;
    int * v813 = v720->cache_age;
    int v814 = v813[v1139];
    int v815 = v813[v1068];
    int v1146 = v815 + ((int)((unsigned int)(v815 - v814) >> 31));
    v813[v1068] = v1146;
    int * v817 = v720->cache_age;
    int v818 = v817[v1069];
    int v1148 = v818 + ((int)((unsigned int)(v818 - v814) >> 31));
    v817[v1069] = v1148;
    int * v820 = v720->cache_age;
    v820[v1139] = 0;
    v823 = v1139;
  }
  int * v824 = v720->cache_vals;
  int v1151 = (v823 * 2) + (((int)((unsigned int)v722 >> 2)) & 1);
  v824[v1151] = v723;
  int * v826 = v720->cache_tags;
  int v827 = v826[v1070];
  int v828 = v826[v1071];
  bool v1154 = !(((~(((v827 ^ ((int)((unsigned int)((int)((unsigned int)v722 >> 2)) >> 1))) | (-(v827 ^ ((int)((unsigned int)((int)((unsigned int)v722 >> 2)) >> 1))))) >> 31)) | (~(((v828 ^ ((int)((unsigned int)((int)((unsigned int)v722 >> 2)) >> 1))) | (-(v828 ^ ((int)((unsigned int)((int)((unsigned int)v722 >> 2)) >> 1))))) >> 31))) == 0);
  int v882;
  if (v1154) {
    int * v829 = v720->cache_age;
    int v1156 = (4 + ((((int)((unsigned int)((int)((unsigned int)v722 >> 2)) >> 1)) & 3) * 2)) + ((~(((v828 ^ ((int)((unsigned int)((int)((unsigned int)v722 >> 2)) >> 1))) | (-(v828 ^ ((int)((unsigned int)((int)((unsigned int)v722 >> 2)) >> 1))))) >> 31)) & 1);
    int v830 = v829[v1156];
    int v831 = v829[v1070];
    int v1157 = v831 + ((int)((unsigned int)(v831 - v830) >> 31));
    v829[v1070] = v1157;
    int * v833 = v720->cache_age;
    int v834 = v833[v1071];
    int v1159 = v834 + ((int)((unsigned int)(v834 - v830) >> 31));
    v833[v1071] = v1159;
    int * v836 = v720->cache_age;
    v836[v1156] = 0;
    v882 = v1156;
  } else {
    int * v839 = v720->cache_age;
    int v1163 = 4 + ((((int)((unsigned int)((int)((unsigned int)v722 >> 2)) >> 1)) & 3) * 2);
    int v840 = v839[v1163];
    int * v841 = v720->cache_tags;
    int v842 = v841[v1163];
    int v843 = v839[v1071];
    int v844 = v841[v1071];
    int * v845 = v720->cache_dirty;
    int v1166 = (4 + ((((int)((unsigned int)((int)((unsigned int)v722 >> 2)) >> 1)) & 3) * 2)) + ((((v840 + ((~(((v842 ^ -1) | (-(v842 ^ -1))) >> 31)) & 2)) - (v843 + ((~(((v844 ^ -1) | (-(v844 ^ -1))) >> 31)) & 2))) >> 31) & 1);
    int v846 = v845[v1166];
    bool v1167 = !(v846 == 0);
    if (v1167) {
      int * v847 = v720->cache_tags;
      int v848 = v847[v1166];
      int * v849 = v720->cache_vals;
      int v1170 = ((4 + ((((int)((unsigned int)((int)((unsigned int)v722 >> 2)) >> 1)) & 3) * 2)) + ((((v840 + ((~(((v842 ^ -1) | (-(v842 ^ -1))) >> 31)) & 2)) - (v843 + ((~(((v844 ^ -1) | (-(v844 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
      int v850 = v849[v1170];
      int v1171 = (((4 + ((((int)((unsigned int)((int)((unsigned int)v722 >> 2)) >> 1)) & 3) * 2)) + ((((v840 + ((~(((v842 ^ -1) | (-(v842 ^ -1))) >> 31)) & 2)) - (v843 + ((~(((v844 ^ -1) | (-(v844 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
      int v851 = v849[v1171];
      int * v852 = v720->mem;
      int v1173 = v848 * 2;
      v852[v1173] = v850;
      int * v854 = v720->mem;
      int v1176 = (v848 * 2) + 1;
      v854[v1176] = v851;
      ;
    } else {
      ;
    }
    int * v859 = v720->mem;
    int v1181 = ((int)((unsigned int)((int)((unsigned int)v722 >> 2)) >> 1)) * 2;
    int v860 = v859[v1181];
    int v1182 = (((int)((unsigned int)((int)((unsigned int)v722 >> 2)) >> 1)) * 2) + 1;
    int v861 = v859[v1182];
    int * v862 = v720->cache_vals;
    int v1184 = ((4 + ((((int)((unsigned int)((int)((unsigned int)v722 >> 2)) >> 1)) & 3) * 2)) + ((((v840 + ((~(((v842 ^ -1) | (-(v842 ^ -1))) >> 31)) & 2)) - (v843 + ((~(((v844 ^ -1) | (-(v844 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
    v862[v1184] = v860;
    int * v864 = v720->cache_vals;
    int v1187 = (((4 + ((((int)((unsigned int)((int)((unsigned int)v722 >> 2)) >> 1)) & 3) * 2)) + ((((v840 + ((~(((v842 ^ -1) | (-(v842 ^ -1))) >> 31)) & 2)) - (v843 + ((~(((v844 ^ -1) | (-(v844 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
    v864[v1187] = v861;
    int * v866 = v720->cache_tags;
    int v1190 = (int)((unsigned int)((int)((unsigned int)v722 >> 2)) >> 1);
    v866[v1166] = v1190;
    int * v868 = v720->cache_dirty;
    v868[v1166] = 0;
    int * v870 = v720->cache_age;
    v870[v1166] = 1;
    int * v872 = v720->cache_age;
    int v873 = v872[v1166];
    int v874 = v872[v1070];
    int v1196 = v874 + ((int)((unsigned int)(v874 - v873) >> 31));
    v872[v1070] = v1196;
    int * v876 = v720->cache_age;
    int v877 = v876[v1071];
    int v1198 = v877 + ((int)((unsigned int)(v877 - v873) >> 31));
    v876[v1071] = v1198;
    int * v879 = v720->cache_age;
    v879[v1166] = 0;
    v882 = v1166;
  }
  int * v883 = v720->cache_vals;
  int v1201 = (v882 * 2) + (((int)((unsigned int)v722 >> 2)) & 1);
  v883[v1201] = v723;
  int * v885 = v720->cache_dirty;
  v885[v882] = 1;
  struct StateT * v887 = v707->b;
  int * v888 = v887->regs;
  int v889 = v888[6];
  int v890 = v888[5];
  int * v891 = v887->cache_tags;
  int v1208 = (((int)((unsigned int)((int)((unsigned int)v889 >> 2)) >> 1)) & 1) * 2;
  int v892 = v891[v1208];
  int v1209 = ((((int)((unsigned int)((int)((unsigned int)v889 >> 2)) >> 1)) & 1) * 2) + 1;
  int v893 = v891[v1209];
  int v1210 = 4 + ((((int)((unsigned int)((int)((unsigned int)v889 >> 2)) >> 1)) & 3) * 2);
  int v894 = v891[v1210];
  int v1211 = (4 + ((((int)((unsigned int)((int)((unsigned int)v889 >> 2)) >> 1)) & 3) * 2)) + 1;
  int v895 = v891[v1211];
  int v896 = v887->timer;
  int v1212 = v896 + ((100 ^ (((~(((v894 ^ ((int)((unsigned int)((int)((unsigned int)v889 >> 2)) >> 1))) | (-(v894 ^ ((int)((unsigned int)((int)((unsigned int)v889 >> 2)) >> 1))))) >> 31)) | (~(((v895 ^ ((int)((unsigned int)((int)((unsigned int)v889 >> 2)) >> 1))) | (-(v895 ^ ((int)((unsigned int)((int)((unsigned int)v889 >> 2)) >> 1))))) >> 31))) & 104)) ^ (((~(((v892 ^ ((int)((unsigned int)((int)((unsigned int)v889 >> 2)) >> 1))) | (-(v892 ^ ((int)((unsigned int)((int)((unsigned int)v889 >> 2)) >> 1))))) >> 31)) | (~(((v893 ^ ((int)((unsigned int)((int)((unsigned int)v889 >> 2)) >> 1))) | (-(v893 ^ ((int)((unsigned int)((int)((unsigned int)v889 >> 2)) >> 1))))) >> 31))) & (1 ^ (100 ^ (((~(((v894 ^ ((int)((unsigned int)((int)((unsigned int)v889 >> 2)) >> 1))) | (-(v894 ^ ((int)((unsigned int)((int)((unsigned int)v889 >> 2)) >> 1))))) >> 31)) | (~(((v895 ^ ((int)((unsigned int)((int)((unsigned int)v889 >> 2)) >> 1))) | (-(v895 ^ ((int)((unsigned int)((int)((unsigned int)v889 >> 2)) >> 1))))) >> 31))) & 104)))));
  v887->timer = v1212;
  bool v1213 = !(((~(((v892 ^ ((int)((unsigned int)((int)((unsigned int)v889 >> 2)) >> 1))) | (-(v892 ^ ((int)((unsigned int)((int)((unsigned int)v889 >> 2)) >> 1))))) >> 31)) | (~(((v893 ^ ((int)((unsigned int)((int)((unsigned int)v889 >> 2)) >> 1))) | (-(v893 ^ ((int)((unsigned int)((int)((unsigned int)v889 >> 2)) >> 1))))) >> 31))) == 0);
  int v990;
  if (v1213) {
    int * v898 = v887->cache_age;
    int v1215 = ((((int)((unsigned int)((int)((unsigned int)v889 >> 2)) >> 1)) & 1) * 2) + ((~(((v893 ^ ((int)((unsigned int)((int)((unsigned int)v889 >> 2)) >> 1))) | (-(v893 ^ ((int)((unsigned int)((int)((unsigned int)v889 >> 2)) >> 1))))) >> 31)) & 1);
    int v899 = v898[v1215];
    int v900 = v898[v1208];
    int v1216 = v900 + ((int)((unsigned int)(v900 - v899) >> 31));
    v898[v1208] = v1216;
    int * v902 = v887->cache_age;
    int v903 = v902[v1209];
    int v1218 = v903 + ((int)((unsigned int)(v903 - v899) >> 31));
    v902[v1209] = v1218;
    int * v905 = v887->cache_age;
    v905[v1215] = 0;
    v990 = v1215;
  } else {
    int * v908 = v887->cache_age;
    int v1222 = (((int)((unsigned int)((int)((unsigned int)v889 >> 2)) >> 1)) & 1) * 2;
    int v909 = v908[v1222];
    int * v910 = v887->cache_tags;
    int v911 = v910[v1222];
    int v912 = v908[v1209];
    int v913 = v910[v1209];
    bool v1224 = !(((~(((v894 ^ ((int)((unsigned int)((int)((unsigned int)v889 >> 2)) >> 1))) | (-(v894 ^ ((int)((unsigned int)((int)((unsigned int)v889 >> 2)) >> 1))))) >> 31)) | (~(((v895 ^ ((int)((unsigned int)((int)((unsigned int)v889 >> 2)) >> 1))) | (-(v895 ^ ((int)((unsigned int)((int)((unsigned int)v889 >> 2)) >> 1))))) >> 31))) == 0);
    int v967;
    if (v1224) {
      int * v914 = v887->cache_age;
      int v1226 = (4 + ((((int)((unsigned int)((int)((unsigned int)v889 >> 2)) >> 1)) & 3) * 2)) + ((~(((v895 ^ ((int)((unsigned int)((int)((unsigned int)v889 >> 2)) >> 1))) | (-(v895 ^ ((int)((unsigned int)((int)((unsigned int)v889 >> 2)) >> 1))))) >> 31)) & 1);
      int v915 = v914[v1226];
      int v916 = v914[v1210];
      int v1227 = v916 + ((int)((unsigned int)(v916 - v915) >> 31));
      v914[v1210] = v1227;
      int * v918 = v887->cache_age;
      int v919 = v918[v1211];
      int v1229 = v919 + ((int)((unsigned int)(v919 - v915) >> 31));
      v918[v1211] = v1229;
      int * v921 = v887->cache_age;
      v921[v1226] = 0;
      v967 = v1226;
    } else {
      int * v924 = v887->cache_age;
      int v1233 = 4 + ((((int)((unsigned int)((int)((unsigned int)v889 >> 2)) >> 1)) & 3) * 2);
      int v925 = v924[v1233];
      int * v926 = v887->cache_tags;
      int v927 = v926[v1233];
      int v928 = v924[v1211];
      int v929 = v926[v1211];
      int * v930 = v887->cache_dirty;
      int v1236 = (4 + ((((int)((unsigned int)((int)((unsigned int)v889 >> 2)) >> 1)) & 3) * 2)) + ((((v925 + ((~(((v927 ^ -1) | (-(v927 ^ -1))) >> 31)) & 2)) - (v928 + ((~(((v929 ^ -1) | (-(v929 ^ -1))) >> 31)) & 2))) >> 31) & 1);
      int v931 = v930[v1236];
      bool v1237 = !(v931 == 0);
      if (v1237) {
        int * v932 = v887->cache_tags;
        int v933 = v932[v1236];
        int * v934 = v887->cache_vals;
        int v1240 = ((4 + ((((int)((unsigned int)((int)((unsigned int)v889 >> 2)) >> 1)) & 3) * 2)) + ((((v925 + ((~(((v927 ^ -1) | (-(v927 ^ -1))) >> 31)) & 2)) - (v928 + ((~(((v929 ^ -1) | (-(v929 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
        int v935 = v934[v1240];
        int v1241 = (((4 + ((((int)((unsigned int)((int)((unsigned int)v889 >> 2)) >> 1)) & 3) * 2)) + ((((v925 + ((~(((v927 ^ -1) | (-(v927 ^ -1))) >> 31)) & 2)) - (v928 + ((~(((v929 ^ -1) | (-(v929 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
        int v936 = v934[v1241];
        int * v937 = v887->mem;
        int v1243 = v933 * 2;
        v937[v1243] = v935;
        int * v939 = v887->mem;
        int v1246 = (v933 * 2) + 1;
        v939[v1246] = v936;
        ;
      } else {
        ;
      }
      int * v944 = v887->mem;
      int v1251 = ((int)((unsigned int)((int)((unsigned int)v889 >> 2)) >> 1)) * 2;
      int v945 = v944[v1251];
      int v1252 = (((int)((unsigned int)((int)((unsigned int)v889 >> 2)) >> 1)) * 2) + 1;
      int v946 = v944[v1252];
      int * v947 = v887->cache_vals;
      int v1254 = ((4 + ((((int)((unsigned int)((int)((unsigned int)v889 >> 2)) >> 1)) & 3) * 2)) + ((((v925 + ((~(((v927 ^ -1) | (-(v927 ^ -1))) >> 31)) & 2)) - (v928 + ((~(((v929 ^ -1) | (-(v929 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
      v947[v1254] = v945;
      int * v949 = v887->cache_vals;
      int v1257 = (((4 + ((((int)((unsigned int)((int)((unsigned int)v889 >> 2)) >> 1)) & 3) * 2)) + ((((v925 + ((~(((v927 ^ -1) | (-(v927 ^ -1))) >> 31)) & 2)) - (v928 + ((~(((v929 ^ -1) | (-(v929 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
      v949[v1257] = v946;
      int * v951 = v887->cache_tags;
      int v1260 = (int)((unsigned int)((int)((unsigned int)v889 >> 2)) >> 1);
      v951[v1236] = v1260;
      int * v953 = v887->cache_dirty;
      v953[v1236] = 0;
      int * v955 = v887->cache_age;
      v955[v1236] = 1;
      int * v957 = v887->cache_age;
      int v958 = v957[v1236];
      int v959 = v957[v1210];
      int v1265 = v959 + ((int)((unsigned int)(v959 - v958) >> 31));
      v957[v1210] = v1265;
      int * v961 = v887->cache_age;
      int v962 = v961[v1211];
      int v1267 = v962 + ((int)((unsigned int)(v962 - v958) >> 31));
      v961[v1211] = v1267;
      int * v964 = v887->cache_age;
      v964[v1236] = 0;
      v967 = v1236;
    }
    int * v968 = v887->cache_vals;
    int v1270 = v967 * 2;
    int v969 = v968[v1270];
    int v1271 = (v967 * 2) + 1;
    int v970 = v968[v1271];
    int v1272 = (((((int)((unsigned int)((int)((unsigned int)v889 >> 2)) >> 1)) & 1) * 2) + ((((v909 + ((~(((v911 ^ -1) | (-(v911 ^ -1))) >> 31)) & 2)) - (v912 + ((~(((v913 ^ -1) | (-(v913 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
    v968[v1272] = v969;
    int * v972 = v887->cache_vals;
    int v1275 = ((((((int)((unsigned int)((int)((unsigned int)v889 >> 2)) >> 1)) & 1) * 2) + ((((v909 + ((~(((v911 ^ -1) | (-(v911 ^ -1))) >> 31)) & 2)) - (v912 + ((~(((v913 ^ -1) | (-(v913 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
    v972[v1275] = v970;
    int * v974 = v887->cache_tags;
    int v1278 = ((((int)((unsigned int)((int)((unsigned int)v889 >> 2)) >> 1)) & 1) * 2) + ((((v909 + ((~(((v911 ^ -1) | (-(v911 ^ -1))) >> 31)) & 2)) - (v912 + ((~(((v913 ^ -1) | (-(v913 ^ -1))) >> 31)) & 2))) >> 31) & 1);
    int v1279 = (int)((unsigned int)((int)((unsigned int)v889 >> 2)) >> 1);
    v974[v1278] = v1279;
    int * v976 = v887->cache_dirty;
    v976[v1278] = 0;
    int * v978 = v887->cache_age;
    v978[v1278] = 1;
    int * v980 = v887->cache_age;
    int v981 = v980[v1278];
    int v982 = v980[v1208];
    int v1284 = v982 + ((int)((unsigned int)(v982 - v981) >> 31));
    v980[v1208] = v1284;
    int * v984 = v887->cache_age;
    int v985 = v984[v1209];
    int v1286 = v985 + ((int)((unsigned int)(v985 - v981) >> 31));
    v984[v1209] = v1286;
    int * v987 = v887->cache_age;
    v987[v1278] = 0;
    v990 = v1278;
  }
  int * v991 = v887->cache_vals;
  int v1289 = (v990 * 2) + (((int)((unsigned int)v889 >> 2)) & 1);
  v991[v1289] = v890;
  int * v993 = v887->cache_tags;
  int v994 = v993[v1210];
  int v995 = v993[v1211];
  bool v1292 = !(((~(((v994 ^ ((int)((unsigned int)((int)((unsigned int)v889 >> 2)) >> 1))) | (-(v994 ^ ((int)((unsigned int)((int)((unsigned int)v889 >> 2)) >> 1))))) >> 31)) | (~(((v995 ^ ((int)((unsigned int)((int)((unsigned int)v889 >> 2)) >> 1))) | (-(v995 ^ ((int)((unsigned int)((int)((unsigned int)v889 >> 2)) >> 1))))) >> 31))) == 0);
  int v1049;
  if (v1292) {
    int * v996 = v887->cache_age;
    int v1294 = (4 + ((((int)((unsigned int)((int)((unsigned int)v889 >> 2)) >> 1)) & 3) * 2)) + ((~(((v995 ^ ((int)((unsigned int)((int)((unsigned int)v889 >> 2)) >> 1))) | (-(v995 ^ ((int)((unsigned int)((int)((unsigned int)v889 >> 2)) >> 1))))) >> 31)) & 1);
    int v997 = v996[v1294];
    int v998 = v996[v1210];
    int v1295 = v998 + ((int)((unsigned int)(v998 - v997) >> 31));
    v996[v1210] = v1295;
    int * v1000 = v887->cache_age;
    int v1001 = v1000[v1211];
    int v1297 = v1001 + ((int)((unsigned int)(v1001 - v997) >> 31));
    v1000[v1211] = v1297;
    int * v1003 = v887->cache_age;
    v1003[v1294] = 0;
    v1049 = v1294;
  } else {
    int * v1006 = v887->cache_age;
    int v1301 = 4 + ((((int)((unsigned int)((int)((unsigned int)v889 >> 2)) >> 1)) & 3) * 2);
    int v1007 = v1006[v1301];
    int * v1008 = v887->cache_tags;
    int v1009 = v1008[v1301];
    int v1010 = v1006[v1211];
    int v1011 = v1008[v1211];
    int * v1012 = v887->cache_dirty;
    int v1304 = (4 + ((((int)((unsigned int)((int)((unsigned int)v889 >> 2)) >> 1)) & 3) * 2)) + ((((v1007 + ((~(((v1009 ^ -1) | (-(v1009 ^ -1))) >> 31)) & 2)) - (v1010 + ((~(((v1011 ^ -1) | (-(v1011 ^ -1))) >> 31)) & 2))) >> 31) & 1);
    int v1013 = v1012[v1304];
    bool v1305 = !(v1013 == 0);
    if (v1305) {
      int * v1014 = v887->cache_tags;
      int v1015 = v1014[v1304];
      int * v1016 = v887->cache_vals;
      int v1308 = ((4 + ((((int)((unsigned int)((int)((unsigned int)v889 >> 2)) >> 1)) & 3) * 2)) + ((((v1007 + ((~(((v1009 ^ -1) | (-(v1009 ^ -1))) >> 31)) & 2)) - (v1010 + ((~(((v1011 ^ -1) | (-(v1011 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
      int v1017 = v1016[v1308];
      int v1309 = (((4 + ((((int)((unsigned int)((int)((unsigned int)v889 >> 2)) >> 1)) & 3) * 2)) + ((((v1007 + ((~(((v1009 ^ -1) | (-(v1009 ^ -1))) >> 31)) & 2)) - (v1010 + ((~(((v1011 ^ -1) | (-(v1011 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
      int v1018 = v1016[v1309];
      int * v1019 = v887->mem;
      int v1311 = v1015 * 2;
      v1019[v1311] = v1017;
      int * v1021 = v887->mem;
      int v1314 = (v1015 * 2) + 1;
      v1021[v1314] = v1018;
      ;
    } else {
      ;
    }
    int * v1026 = v887->mem;
    int v1319 = ((int)((unsigned int)((int)((unsigned int)v889 >> 2)) >> 1)) * 2;
    int v1027 = v1026[v1319];
    int v1320 = (((int)((unsigned int)((int)((unsigned int)v889 >> 2)) >> 1)) * 2) + 1;
    int v1028 = v1026[v1320];
    int * v1029 = v887->cache_vals;
    int v1322 = ((4 + ((((int)((unsigned int)((int)((unsigned int)v889 >> 2)) >> 1)) & 3) * 2)) + ((((v1007 + ((~(((v1009 ^ -1) | (-(v1009 ^ -1))) >> 31)) & 2)) - (v1010 + ((~(((v1011 ^ -1) | (-(v1011 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
    v1029[v1322] = v1027;
    int * v1031 = v887->cache_vals;
    int v1325 = (((4 + ((((int)((unsigned int)((int)((unsigned int)v889 >> 2)) >> 1)) & 3) * 2)) + ((((v1007 + ((~(((v1009 ^ -1) | (-(v1009 ^ -1))) >> 31)) & 2)) - (v1010 + ((~(((v1011 ^ -1) | (-(v1011 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
    v1031[v1325] = v1028;
    int * v1033 = v887->cache_tags;
    int v1328 = (int)((unsigned int)((int)((unsigned int)v889 >> 2)) >> 1);
    v1033[v1304] = v1328;
    int * v1035 = v887->cache_dirty;
    v1035[v1304] = 0;
    int * v1037 = v887->cache_age;
    v1037[v1304] = 1;
    int * v1039 = v887->cache_age;
    int v1040 = v1039[v1304];
    int v1041 = v1039[v1210];
    int v1333 = v1041 + ((int)((unsigned int)(v1041 - v1040) >> 31));
    v1039[v1210] = v1333;
    int * v1043 = v887->cache_age;
    int v1044 = v1043[v1211];
    int v1335 = v1044 + ((int)((unsigned int)(v1044 - v1040) >> 31));
    v1043[v1211] = v1335;
    int * v1046 = v887->cache_age;
    v1046[v1304] = 0;
    v1049 = v1304;
  }
  int * v1050 = v887->cache_vals;
  int v1338 = (v1049 * 2) + (((int)((unsigned int)v889 >> 2)) & 1);
  v1050[v1338] = v890;
  int * v1052 = v887->cache_dirty;
  v1052[v1049] = 1;
  struct StateT2 * v1054 = slot_9(v707);
  return v1054;
}

struct StateT2 * slot_4(struct StateT2 * v134) {
  struct StateT * v135 = v134->a;
  int v136 = v135->timer;
  struct StateT * v137 = v134->b;
  int v138 = v137->timer;
  bool v171 = v136 == v138;
  squared_assert(v171);
  squared_assume(v171);
  struct StateT * v141 = v134->a;
  int * v142 = v141->saved_regs;
  int * v143 = v141->regs;
  int v144 = v143[8];
  v142[8] = v144;
  struct StateT * v146 = v134->b;
  int * v147 = v146->saved_regs;
  int * v148 = v146->regs;
  int v149 = v148[8];
  v147[8] = v149;
  struct StateT * v151 = v134->a;
  int v152 = v151->timer;
  int v182 = v152 + 1;
  v151->timer = v182;
  struct StateT * v154 = v134->b;
  int v155 = v154->timer;
  int v184 = v155 + 1;
  v154->timer = v184;
  struct StateT * v157 = v134->a;
  int * v158 = v157->regs;
  int v159 = v158[9];
  int v160 = v158[6];
  int v189 = v159 + v160;
  v158[8] = v189;
  struct StateT * v162 = v134->b;
  int * v163 = v162->regs;
  int v164 = v163[9];
  int v165 = v163[6];
  int v192 = v164 + v165;
  v163[8] = v192;
  struct StateT2 * v167 = slot_14(v134);
  return v167;
}

struct StateT2 * slot_9(struct StateT2 * v1343) {
  struct StateT * v1344 = v1343->a;
  int v1345 = v1344->timer;
  struct StateT * v1346 = v1343->b;
  int v1347 = v1346->timer;
  bool v1574 = v1345 == v1347;
  squared_assert(v1574);
  squared_assume(v1574);
  struct StateT * v1350 = v1343->a;
  int v1351 = v1350->timer;
  int v1576 = v1351 + 1;
  v1350->timer = v1576;
  struct StateT * v1353 = v1343->b;
  int v1354 = v1353->timer;
  int v1578 = v1354 + 1;
  v1353->timer = v1578;
  struct StateT * v1356 = v1343->a;
  int * v1357 = v1356->regs;
  int v1358 = v1357[6];
  int * v1359 = v1356->cache_tags;
  int v1583 = (((int)((unsigned int)((int)((unsigned int)v1358 >> 2)) >> 1)) & 1) * 2;
  int v1360 = v1359[v1583];
  int v1584 = ((((int)((unsigned int)((int)((unsigned int)v1358 >> 2)) >> 1)) & 1) * 2) + 1;
  int v1361 = v1359[v1584];
  int v1585 = 4 + ((((int)((unsigned int)((int)((unsigned int)v1358 >> 2)) >> 1)) & 3) * 2);
  int v1362 = v1359[v1585];
  int v1586 = (4 + ((((int)((unsigned int)((int)((unsigned int)v1358 >> 2)) >> 1)) & 3) * 2)) + 1;
  int v1363 = v1359[v1586];
  int v1364 = v1356->timer;
  int v1587 = v1364 + ((100 ^ (((~(((v1362 ^ ((int)((unsigned int)((int)((unsigned int)v1358 >> 2)) >> 1))) | (-(v1362 ^ ((int)((unsigned int)((int)((unsigned int)v1358 >> 2)) >> 1))))) >> 31)) | (~(((v1363 ^ ((int)((unsigned int)((int)((unsigned int)v1358 >> 2)) >> 1))) | (-(v1363 ^ ((int)((unsigned int)((int)((unsigned int)v1358 >> 2)) >> 1))))) >> 31))) & 104)) ^ (((~(((v1360 ^ ((int)((unsigned int)((int)((unsigned int)v1358 >> 2)) >> 1))) | (-(v1360 ^ ((int)((unsigned int)((int)((unsigned int)v1358 >> 2)) >> 1))))) >> 31)) | (~(((v1361 ^ ((int)((unsigned int)((int)((unsigned int)v1358 >> 2)) >> 1))) | (-(v1361 ^ ((int)((unsigned int)((int)((unsigned int)v1358 >> 2)) >> 1))))) >> 31))) & (1 ^ (100 ^ (((~(((v1362 ^ ((int)((unsigned int)((int)((unsigned int)v1358 >> 2)) >> 1))) | (-(v1362 ^ ((int)((unsigned int)((int)((unsigned int)v1358 >> 2)) >> 1))))) >> 31)) | (~(((v1363 ^ ((int)((unsigned int)((int)((unsigned int)v1358 >> 2)) >> 1))) | (-(v1363 ^ ((int)((unsigned int)((int)((unsigned int)v1358 >> 2)) >> 1))))) >> 31))) & 104)))));
  v1356->timer = v1587;
  int * v1366 = v1356->cache_vals;
  bool v1588 = !(((~(((v1360 ^ ((int)((unsigned int)((int)((unsigned int)v1358 >> 2)) >> 1))) | (-(v1360 ^ ((int)((unsigned int)((int)((unsigned int)v1358 >> 2)) >> 1))))) >> 31)) | (~(((v1361 ^ ((int)((unsigned int)((int)((unsigned int)v1358 >> 2)) >> 1))) | (-(v1361 ^ ((int)((unsigned int)((int)((unsigned int)v1358 >> 2)) >> 1))))) >> 31))) == 0);
  int v1459;
  if (v1588) {
    int * v1367 = v1356->cache_age;
    int v1590 = ((((int)((unsigned int)((int)((unsigned int)v1358 >> 2)) >> 1)) & 1) * 2) + ((~(((v1361 ^ ((int)((unsigned int)((int)((unsigned int)v1358 >> 2)) >> 1))) | (-(v1361 ^ ((int)((unsigned int)((int)((unsigned int)v1358 >> 2)) >> 1))))) >> 31)) & 1);
    int v1368 = v1367[v1590];
    int v1369 = v1367[v1583];
    int v1591 = v1369 + ((int)((unsigned int)(v1369 - v1368) >> 31));
    v1367[v1583] = v1591;
    int * v1371 = v1356->cache_age;
    int v1372 = v1371[v1584];
    int v1593 = v1372 + ((int)((unsigned int)(v1372 - v1368) >> 31));
    v1371[v1584] = v1593;
    int * v1374 = v1356->cache_age;
    v1374[v1590] = 0;
    v1459 = v1590;
  } else {
    int * v1377 = v1356->cache_age;
    int v1597 = (((int)((unsigned int)((int)((unsigned int)v1358 >> 2)) >> 1)) & 1) * 2;
    int v1378 = v1377[v1597];
    int * v1379 = v1356->cache_tags;
    int v1380 = v1379[v1597];
    int v1381 = v1377[v1584];
    int v1382 = v1379[v1584];
    bool v1599 = !(((~(((v1362 ^ ((int)((unsigned int)((int)((unsigned int)v1358 >> 2)) >> 1))) | (-(v1362 ^ ((int)((unsigned int)((int)((unsigned int)v1358 >> 2)) >> 1))))) >> 31)) | (~(((v1363 ^ ((int)((unsigned int)((int)((unsigned int)v1358 >> 2)) >> 1))) | (-(v1363 ^ ((int)((unsigned int)((int)((unsigned int)v1358 >> 2)) >> 1))))) >> 31))) == 0);
    int v1436;
    if (v1599) {
      int * v1383 = v1356->cache_age;
      int v1601 = (4 + ((((int)((unsigned int)((int)((unsigned int)v1358 >> 2)) >> 1)) & 3) * 2)) + ((~(((v1363 ^ ((int)((unsigned int)((int)((unsigned int)v1358 >> 2)) >> 1))) | (-(v1363 ^ ((int)((unsigned int)((int)((unsigned int)v1358 >> 2)) >> 1))))) >> 31)) & 1);
      int v1384 = v1383[v1601];
      int v1385 = v1383[v1585];
      int v1602 = v1385 + ((int)((unsigned int)(v1385 - v1384) >> 31));
      v1383[v1585] = v1602;
      int * v1387 = v1356->cache_age;
      int v1388 = v1387[v1586];
      int v1604 = v1388 + ((int)((unsigned int)(v1388 - v1384) >> 31));
      v1387[v1586] = v1604;
      int * v1390 = v1356->cache_age;
      v1390[v1601] = 0;
      v1436 = v1601;
    } else {
      int * v1393 = v1356->cache_age;
      int v1608 = 4 + ((((int)((unsigned int)((int)((unsigned int)v1358 >> 2)) >> 1)) & 3) * 2);
      int v1394 = v1393[v1608];
      int * v1395 = v1356->cache_tags;
      int v1396 = v1395[v1608];
      int v1397 = v1393[v1586];
      int v1398 = v1395[v1586];
      int * v1399 = v1356->cache_dirty;
      int v1611 = (4 + ((((int)((unsigned int)((int)((unsigned int)v1358 >> 2)) >> 1)) & 3) * 2)) + ((((v1394 + ((~(((v1396 ^ -1) | (-(v1396 ^ -1))) >> 31)) & 2)) - (v1397 + ((~(((v1398 ^ -1) | (-(v1398 ^ -1))) >> 31)) & 2))) >> 31) & 1);
      int v1400 = v1399[v1611];
      bool v1612 = !(v1400 == 0);
      if (v1612) {
        int * v1401 = v1356->cache_tags;
        int v1402 = v1401[v1611];
        int * v1403 = v1356->cache_vals;
        int v1615 = ((4 + ((((int)((unsigned int)((int)((unsigned int)v1358 >> 2)) >> 1)) & 3) * 2)) + ((((v1394 + ((~(((v1396 ^ -1) | (-(v1396 ^ -1))) >> 31)) & 2)) - (v1397 + ((~(((v1398 ^ -1) | (-(v1398 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
        int v1404 = v1403[v1615];
        int v1616 = (((4 + ((((int)((unsigned int)((int)((unsigned int)v1358 >> 2)) >> 1)) & 3) * 2)) + ((((v1394 + ((~(((v1396 ^ -1) | (-(v1396 ^ -1))) >> 31)) & 2)) - (v1397 + ((~(((v1398 ^ -1) | (-(v1398 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
        int v1405 = v1403[v1616];
        int * v1406 = v1356->mem;
        int v1618 = v1402 * 2;
        v1406[v1618] = v1404;
        int * v1408 = v1356->mem;
        int v1621 = (v1402 * 2) + 1;
        v1408[v1621] = v1405;
        ;
      } else {
        ;
      }
      int * v1413 = v1356->mem;
      int v1626 = ((int)((unsigned int)((int)((unsigned int)v1358 >> 2)) >> 1)) * 2;
      int v1414 = v1413[v1626];
      int v1627 = (((int)((unsigned int)((int)((unsigned int)v1358 >> 2)) >> 1)) * 2) + 1;
      int v1415 = v1413[v1627];
      int * v1416 = v1356->cache_vals;
      int v1629 = ((4 + ((((int)((unsigned int)((int)((unsigned int)v1358 >> 2)) >> 1)) & 3) * 2)) + ((((v1394 + ((~(((v1396 ^ -1) | (-(v1396 ^ -1))) >> 31)) & 2)) - (v1397 + ((~(((v1398 ^ -1) | (-(v1398 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
      v1416[v1629] = v1414;
      int * v1418 = v1356->cache_vals;
      int v1632 = (((4 + ((((int)((unsigned int)((int)((unsigned int)v1358 >> 2)) >> 1)) & 3) * 2)) + ((((v1394 + ((~(((v1396 ^ -1) | (-(v1396 ^ -1))) >> 31)) & 2)) - (v1397 + ((~(((v1398 ^ -1) | (-(v1398 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
      v1418[v1632] = v1415;
      int * v1420 = v1356->cache_tags;
      int v1635 = (int)((unsigned int)((int)((unsigned int)v1358 >> 2)) >> 1);
      v1420[v1611] = v1635;
      int * v1422 = v1356->cache_dirty;
      v1422[v1611] = 0;
      int * v1424 = v1356->cache_age;
      v1424[v1611] = 1;
      int * v1426 = v1356->cache_age;
      int v1427 = v1426[v1611];
      int v1428 = v1426[v1585];
      int v1641 = v1428 + ((int)((unsigned int)(v1428 - v1427) >> 31));
      v1426[v1585] = v1641;
      int * v1430 = v1356->cache_age;
      int v1431 = v1430[v1586];
      int v1643 = v1431 + ((int)((unsigned int)(v1431 - v1427) >> 31));
      v1430[v1586] = v1643;
      int * v1433 = v1356->cache_age;
      v1433[v1611] = 0;
      v1436 = v1611;
    }
    int * v1437 = v1356->cache_vals;
    int v1646 = v1436 * 2;
    int v1438 = v1437[v1646];
    int v1647 = (v1436 * 2) + 1;
    int v1439 = v1437[v1647];
    int v1648 = (((((int)((unsigned int)((int)((unsigned int)v1358 >> 2)) >> 1)) & 1) * 2) + ((((v1378 + ((~(((v1380 ^ -1) | (-(v1380 ^ -1))) >> 31)) & 2)) - (v1381 + ((~(((v1382 ^ -1) | (-(v1382 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
    v1437[v1648] = v1438;
    int * v1441 = v1356->cache_vals;
    int v1651 = ((((((int)((unsigned int)((int)((unsigned int)v1358 >> 2)) >> 1)) & 1) * 2) + ((((v1378 + ((~(((v1380 ^ -1) | (-(v1380 ^ -1))) >> 31)) & 2)) - (v1381 + ((~(((v1382 ^ -1) | (-(v1382 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
    v1441[v1651] = v1439;
    int * v1443 = v1356->cache_tags;
    int v1654 = ((((int)((unsigned int)((int)((unsigned int)v1358 >> 2)) >> 1)) & 1) * 2) + ((((v1378 + ((~(((v1380 ^ -1) | (-(v1380 ^ -1))) >> 31)) & 2)) - (v1381 + ((~(((v1382 ^ -1) | (-(v1382 ^ -1))) >> 31)) & 2))) >> 31) & 1);
    int v1655 = (int)((unsigned int)((int)((unsigned int)v1358 >> 2)) >> 1);
    v1443[v1654] = v1655;
    int * v1445 = v1356->cache_dirty;
    v1445[v1654] = 0;
    int * v1447 = v1356->cache_age;
    v1447[v1654] = 1;
    int * v1449 = v1356->cache_age;
    int v1450 = v1449[v1654];
    int v1451 = v1449[v1583];
    int v1661 = v1451 + ((int)((unsigned int)(v1451 - v1450) >> 31));
    v1449[v1583] = v1661;
    int * v1453 = v1356->cache_age;
    int v1454 = v1453[v1584];
    int v1663 = v1454 + ((int)((unsigned int)(v1454 - v1450) >> 31));
    v1453[v1584] = v1663;
    int * v1456 = v1356->cache_age;
    v1456[v1654] = 0;
    v1459 = v1654;
  }
  int v1666 = (v1459 * 2) + (((int)((unsigned int)v1358 >> 2)) & 1);
  int v1460 = v1366[v1666];
  int * v1461 = v1356->regs;
  v1461[11] = v1460;
  struct StateT * v1463 = v1343->b;
  int * v1464 = v1463->regs;
  int v1465 = v1464[6];
  int * v1466 = v1463->cache_tags;
  int v1673 = (((int)((unsigned int)((int)((unsigned int)v1465 >> 2)) >> 1)) & 1) * 2;
  int v1467 = v1466[v1673];
  int v1674 = ((((int)((unsigned int)((int)((unsigned int)v1465 >> 2)) >> 1)) & 1) * 2) + 1;
  int v1468 = v1466[v1674];
  int v1675 = 4 + ((((int)((unsigned int)((int)((unsigned int)v1465 >> 2)) >> 1)) & 3) * 2);
  int v1469 = v1466[v1675];
  int v1676 = (4 + ((((int)((unsigned int)((int)((unsigned int)v1465 >> 2)) >> 1)) & 3) * 2)) + 1;
  int v1470 = v1466[v1676];
  int v1471 = v1463->timer;
  int v1677 = v1471 + ((100 ^ (((~(((v1469 ^ ((int)((unsigned int)((int)((unsigned int)v1465 >> 2)) >> 1))) | (-(v1469 ^ ((int)((unsigned int)((int)((unsigned int)v1465 >> 2)) >> 1))))) >> 31)) | (~(((v1470 ^ ((int)((unsigned int)((int)((unsigned int)v1465 >> 2)) >> 1))) | (-(v1470 ^ ((int)((unsigned int)((int)((unsigned int)v1465 >> 2)) >> 1))))) >> 31))) & 104)) ^ (((~(((v1467 ^ ((int)((unsigned int)((int)((unsigned int)v1465 >> 2)) >> 1))) | (-(v1467 ^ ((int)((unsigned int)((int)((unsigned int)v1465 >> 2)) >> 1))))) >> 31)) | (~(((v1468 ^ ((int)((unsigned int)((int)((unsigned int)v1465 >> 2)) >> 1))) | (-(v1468 ^ ((int)((unsigned int)((int)((unsigned int)v1465 >> 2)) >> 1))))) >> 31))) & (1 ^ (100 ^ (((~(((v1469 ^ ((int)((unsigned int)((int)((unsigned int)v1465 >> 2)) >> 1))) | (-(v1469 ^ ((int)((unsigned int)((int)((unsigned int)v1465 >> 2)) >> 1))))) >> 31)) | (~(((v1470 ^ ((int)((unsigned int)((int)((unsigned int)v1465 >> 2)) >> 1))) | (-(v1470 ^ ((int)((unsigned int)((int)((unsigned int)v1465 >> 2)) >> 1))))) >> 31))) & 104)))));
  v1463->timer = v1677;
  int * v1473 = v1463->cache_vals;
  bool v1678 = !(((~(((v1467 ^ ((int)((unsigned int)((int)((unsigned int)v1465 >> 2)) >> 1))) | (-(v1467 ^ ((int)((unsigned int)((int)((unsigned int)v1465 >> 2)) >> 1))))) >> 31)) | (~(((v1468 ^ ((int)((unsigned int)((int)((unsigned int)v1465 >> 2)) >> 1))) | (-(v1468 ^ ((int)((unsigned int)((int)((unsigned int)v1465 >> 2)) >> 1))))) >> 31))) == 0);
  int v1566;
  if (v1678) {
    int * v1474 = v1463->cache_age;
    int v1680 = ((((int)((unsigned int)((int)((unsigned int)v1465 >> 2)) >> 1)) & 1) * 2) + ((~(((v1468 ^ ((int)((unsigned int)((int)((unsigned int)v1465 >> 2)) >> 1))) | (-(v1468 ^ ((int)((unsigned int)((int)((unsigned int)v1465 >> 2)) >> 1))))) >> 31)) & 1);
    int v1475 = v1474[v1680];
    int v1476 = v1474[v1673];
    int v1681 = v1476 + ((int)((unsigned int)(v1476 - v1475) >> 31));
    v1474[v1673] = v1681;
    int * v1478 = v1463->cache_age;
    int v1479 = v1478[v1674];
    int v1683 = v1479 + ((int)((unsigned int)(v1479 - v1475) >> 31));
    v1478[v1674] = v1683;
    int * v1481 = v1463->cache_age;
    v1481[v1680] = 0;
    v1566 = v1680;
  } else {
    int * v1484 = v1463->cache_age;
    int v1687 = (((int)((unsigned int)((int)((unsigned int)v1465 >> 2)) >> 1)) & 1) * 2;
    int v1485 = v1484[v1687];
    int * v1486 = v1463->cache_tags;
    int v1487 = v1486[v1687];
    int v1488 = v1484[v1674];
    int v1489 = v1486[v1674];
    bool v1689 = !(((~(((v1469 ^ ((int)((unsigned int)((int)((unsigned int)v1465 >> 2)) >> 1))) | (-(v1469 ^ ((int)((unsigned int)((int)((unsigned int)v1465 >> 2)) >> 1))))) >> 31)) | (~(((v1470 ^ ((int)((unsigned int)((int)((unsigned int)v1465 >> 2)) >> 1))) | (-(v1470 ^ ((int)((unsigned int)((int)((unsigned int)v1465 >> 2)) >> 1))))) >> 31))) == 0);
    int v1543;
    if (v1689) {
      int * v1490 = v1463->cache_age;
      int v1691 = (4 + ((((int)((unsigned int)((int)((unsigned int)v1465 >> 2)) >> 1)) & 3) * 2)) + ((~(((v1470 ^ ((int)((unsigned int)((int)((unsigned int)v1465 >> 2)) >> 1))) | (-(v1470 ^ ((int)((unsigned int)((int)((unsigned int)v1465 >> 2)) >> 1))))) >> 31)) & 1);
      int v1491 = v1490[v1691];
      int v1492 = v1490[v1675];
      int v1692 = v1492 + ((int)((unsigned int)(v1492 - v1491) >> 31));
      v1490[v1675] = v1692;
      int * v1494 = v1463->cache_age;
      int v1495 = v1494[v1676];
      int v1694 = v1495 + ((int)((unsigned int)(v1495 - v1491) >> 31));
      v1494[v1676] = v1694;
      int * v1497 = v1463->cache_age;
      v1497[v1691] = 0;
      v1543 = v1691;
    } else {
      int * v1500 = v1463->cache_age;
      int v1698 = 4 + ((((int)((unsigned int)((int)((unsigned int)v1465 >> 2)) >> 1)) & 3) * 2);
      int v1501 = v1500[v1698];
      int * v1502 = v1463->cache_tags;
      int v1503 = v1502[v1698];
      int v1504 = v1500[v1676];
      int v1505 = v1502[v1676];
      int * v1506 = v1463->cache_dirty;
      int v1701 = (4 + ((((int)((unsigned int)((int)((unsigned int)v1465 >> 2)) >> 1)) & 3) * 2)) + ((((v1501 + ((~(((v1503 ^ -1) | (-(v1503 ^ -1))) >> 31)) & 2)) - (v1504 + ((~(((v1505 ^ -1) | (-(v1505 ^ -1))) >> 31)) & 2))) >> 31) & 1);
      int v1507 = v1506[v1701];
      bool v1702 = !(v1507 == 0);
      if (v1702) {
        int * v1508 = v1463->cache_tags;
        int v1509 = v1508[v1701];
        int * v1510 = v1463->cache_vals;
        int v1705 = ((4 + ((((int)((unsigned int)((int)((unsigned int)v1465 >> 2)) >> 1)) & 3) * 2)) + ((((v1501 + ((~(((v1503 ^ -1) | (-(v1503 ^ -1))) >> 31)) & 2)) - (v1504 + ((~(((v1505 ^ -1) | (-(v1505 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
        int v1511 = v1510[v1705];
        int v1706 = (((4 + ((((int)((unsigned int)((int)((unsigned int)v1465 >> 2)) >> 1)) & 3) * 2)) + ((((v1501 + ((~(((v1503 ^ -1) | (-(v1503 ^ -1))) >> 31)) & 2)) - (v1504 + ((~(((v1505 ^ -1) | (-(v1505 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
        int v1512 = v1510[v1706];
        int * v1513 = v1463->mem;
        int v1708 = v1509 * 2;
        v1513[v1708] = v1511;
        int * v1515 = v1463->mem;
        int v1711 = (v1509 * 2) + 1;
        v1515[v1711] = v1512;
        ;
      } else {
        ;
      }
      int * v1520 = v1463->mem;
      int v1716 = ((int)((unsigned int)((int)((unsigned int)v1465 >> 2)) >> 1)) * 2;
      int v1521 = v1520[v1716];
      int v1717 = (((int)((unsigned int)((int)((unsigned int)v1465 >> 2)) >> 1)) * 2) + 1;
      int v1522 = v1520[v1717];
      int * v1523 = v1463->cache_vals;
      int v1719 = ((4 + ((((int)((unsigned int)((int)((unsigned int)v1465 >> 2)) >> 1)) & 3) * 2)) + ((((v1501 + ((~(((v1503 ^ -1) | (-(v1503 ^ -1))) >> 31)) & 2)) - (v1504 + ((~(((v1505 ^ -1) | (-(v1505 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
      v1523[v1719] = v1521;
      int * v1525 = v1463->cache_vals;
      int v1722 = (((4 + ((((int)((unsigned int)((int)((unsigned int)v1465 >> 2)) >> 1)) & 3) * 2)) + ((((v1501 + ((~(((v1503 ^ -1) | (-(v1503 ^ -1))) >> 31)) & 2)) - (v1504 + ((~(((v1505 ^ -1) | (-(v1505 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
      v1525[v1722] = v1522;
      int * v1527 = v1463->cache_tags;
      int v1725 = (int)((unsigned int)((int)((unsigned int)v1465 >> 2)) >> 1);
      v1527[v1701] = v1725;
      int * v1529 = v1463->cache_dirty;
      v1529[v1701] = 0;
      int * v1531 = v1463->cache_age;
      v1531[v1701] = 1;
      int * v1533 = v1463->cache_age;
      int v1534 = v1533[v1701];
      int v1535 = v1533[v1675];
      int v1731 = v1535 + ((int)((unsigned int)(v1535 - v1534) >> 31));
      v1533[v1675] = v1731;
      int * v1537 = v1463->cache_age;
      int v1538 = v1537[v1676];
      int v1733 = v1538 + ((int)((unsigned int)(v1538 - v1534) >> 31));
      v1537[v1676] = v1733;
      int * v1540 = v1463->cache_age;
      v1540[v1701] = 0;
      v1543 = v1701;
    }
    int * v1544 = v1463->cache_vals;
    int v1736 = v1543 * 2;
    int v1545 = v1544[v1736];
    int v1737 = (v1543 * 2) + 1;
    int v1546 = v1544[v1737];
    int v1738 = (((((int)((unsigned int)((int)((unsigned int)v1465 >> 2)) >> 1)) & 1) * 2) + ((((v1485 + ((~(((v1487 ^ -1) | (-(v1487 ^ -1))) >> 31)) & 2)) - (v1488 + ((~(((v1489 ^ -1) | (-(v1489 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
    v1544[v1738] = v1545;
    int * v1548 = v1463->cache_vals;
    int v1741 = ((((((int)((unsigned int)((int)((unsigned int)v1465 >> 2)) >> 1)) & 1) * 2) + ((((v1485 + ((~(((v1487 ^ -1) | (-(v1487 ^ -1))) >> 31)) & 2)) - (v1488 + ((~(((v1489 ^ -1) | (-(v1489 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
    v1548[v1741] = v1546;
    int * v1550 = v1463->cache_tags;
    int v1744 = ((((int)((unsigned int)((int)((unsigned int)v1465 >> 2)) >> 1)) & 1) * 2) + ((((v1485 + ((~(((v1487 ^ -1) | (-(v1487 ^ -1))) >> 31)) & 2)) - (v1488 + ((~(((v1489 ^ -1) | (-(v1489 ^ -1))) >> 31)) & 2))) >> 31) & 1);
    int v1745 = (int)((unsigned int)((int)((unsigned int)v1465 >> 2)) >> 1);
    v1550[v1744] = v1745;
    int * v1552 = v1463->cache_dirty;
    v1552[v1744] = 0;
    int * v1554 = v1463->cache_age;
    v1554[v1744] = 1;
    int * v1556 = v1463->cache_age;
    int v1557 = v1556[v1744];
    int v1558 = v1556[v1673];
    int v1751 = v1558 + ((int)((unsigned int)(v1558 - v1557) >> 31));
    v1556[v1673] = v1751;
    int * v1560 = v1463->cache_age;
    int v1561 = v1560[v1674];
    int v1753 = v1561 + ((int)((unsigned int)(v1561 - v1557) >> 31));
    v1560[v1674] = v1753;
    int * v1563 = v1463->cache_age;
    v1563[v1744] = 0;
    v1566 = v1744;
  }
  int v1756 = (v1566 * 2) + (((int)((unsigned int)v1465 >> 2)) & 1);
  int v1567 = v1473[v1756];
  int * v1568 = v1463->regs;
  v1568[11] = v1567;
  struct StateT2 * v1570 = slot_10(v1343);
  return v1570;
}

struct StateT2 * slot_11(struct StateT2 * v1800) {
  struct StateT * v1801 = v1800->a;
  int v1802 = v1801->timer;
  struct StateT * v1803 = v1800->b;
  int v1804 = v1803->timer;
  bool v1819 = v1802 == v1804;
  squared_assert(v1819);
  squared_assume(v1819);
  struct StateT * v1807 = v1800->a;
  int v1808 = v1807->timer;
  int v1821 = v1808 + 1;
  v1807->timer = v1821;
  struct StateT * v1810 = v1800->b;
  int v1811 = v1810->timer;
  int v1823 = v1811 + 1;
  v1810->timer = v1823;
  struct StateT2 * v1815 = slot_12(v1800);
  return v1815;
}

struct StateT2 * slot_0(struct StateT2 * v2) {
  struct StateT * v3 = v2->a;
  int v4 = v3->timer;
  struct StateT * v5 = v2->b;
  int v6 = v5->timer;
  bool v25 = v4 == v6;
  squared_assert(v25);
  squared_assume(v25);
  struct StateT * v9 = v2->a;
  int v10 = v9->timer;
  int v27 = v10 + 1;
  v9->timer = v27;
  struct StateT * v12 = v2->b;
  int v13 = v12->timer;
  int v29 = v13 + 1;
  v12->timer = v29;
  struct StateT * v15 = v2->a;
  int * v16 = v15->regs;
  v16[6] = 0;
  struct StateT * v18 = v2->b;
  int * v19 = v18->regs;
  v19[6] = 0;
  struct StateT2 * v21 = slot_1(v2);
  return v21;
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
    s1.mem[SECRET_OFFSET+i] = secret(0, 20);
    s2.mem[SECRET_OFFSET+i] = secret(0, 20);
  }
  struct StateT2 p = { .a = &s1, .b = &s2 };
  struct StateT2 *p_ = snippet(&p);
  //@ assert untainted_timer: !\tainted(p_->a->timer==p_->b->timer);
  koika_assert(p_->a->timer==p_->b->timer, "timing leak");
  return 0;
}