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

struct StateT2 * snippet(struct StateT2 * v0);
struct StateT2 * slot_1(struct StateT2 * v42);
struct StateT2 * slot_6(struct StateT2 * v2087);
struct StateT2 * slot_5(struct StateT2 * v1669);
struct StateT2 * slot_4(struct StateT2 * v1283);
struct StateT2 * slot_2(struct StateT2 * v82);
struct StateT2 * slot_3(struct StateT2 * v683);
struct StateT2 * slot_0(struct StateT2 * v2);
struct StateT2 * snippet(struct StateT2 * v0) {
  struct StateT2 * v1 = slot_0(v0);
  return v1;
}

struct StateT2 * slot_1(struct StateT2 * v42) {
  struct StateT * v43 = v42->a;
  int v44 = v43->timer;
  struct StateT * v45 = v42->b;
  int v46 = v45->timer;
  bool v67 = v44 == v46;
  squared_assert(v67);
  squared_assume(v67);
  struct StateT * v49 = v42->a;
  int v50 = v49->timer;
  int v69 = v50 + 1;
  v49->timer = v69;
  struct StateT * v52 = v42->b;
  int v53 = v52->timer;
  int v71 = v53 + 1;
  v52->timer = v71;
  struct StateT * v55 = v42->a;
  int * v56 = v55->regs;
  int v57 = v56[5];
  int v76 = v57 + 80;
  v56[6] = v76;
  struct StateT * v59 = v42->b;
  int * v60 = v59->regs;
  int v61 = v60[5];
  int v79 = v61 + 80;
  v60[6] = v79;
  struct StateT2 * v63 = slot_2(v42);
  return v63;
}

struct StateT2 * slot_6(struct StateT2 * v2087) {
  struct StateT * v2088 = v2087->a;
  int v2089 = v2088->timer;
  struct StateT * v2090 = v2087->b;
  int v2091 = v2090->timer;
  bool v2317 = v2089 == v2091;
  squared_assert(v2317);
  squared_assume(v2317);
  struct StateT * v2094 = v2087->a;
  int v2095 = v2094->timer;
  int v2319 = v2095 + 1;
  v2094->timer = v2319;
  struct StateT * v2097 = v2087->b;
  int v2098 = v2097->timer;
  int v2321 = v2098 + 1;
  v2097->timer = v2321;
  struct StateT * v2100 = v2087->a;
  int * v2101 = v2100->regs;
  int v2102 = v2101[11];
  int * v2103 = v2100->cache_tags;
  int v2326 = (((int)((unsigned int)((int)((unsigned int)v2102 >> 2)) >> 1)) & 1) * 2;
  int v2104 = v2103[v2326];
  int v2327 = ((((int)((unsigned int)((int)((unsigned int)v2102 >> 2)) >> 1)) & 1) * 2) + 1;
  int v2105 = v2103[v2327];
  int v2328 = 4 + ((((int)((unsigned int)((int)((unsigned int)v2102 >> 2)) >> 1)) & 3) * 2);
  int v2106 = v2103[v2328];
  int v2329 = (4 + ((((int)((unsigned int)((int)((unsigned int)v2102 >> 2)) >> 1)) & 3) * 2)) + 1;
  int v2107 = v2103[v2329];
  int v2108 = v2100->timer;
  int v2330 = v2108 + ((100 ^ (((~(((v2106 ^ ((int)((unsigned int)((int)((unsigned int)v2102 >> 2)) >> 1))) | (-(v2106 ^ ((int)((unsigned int)((int)((unsigned int)v2102 >> 2)) >> 1))))) >> 31)) | (~(((v2107 ^ ((int)((unsigned int)((int)((unsigned int)v2102 >> 2)) >> 1))) | (-(v2107 ^ ((int)((unsigned int)((int)((unsigned int)v2102 >> 2)) >> 1))))) >> 31))) & 104)) ^ (((~(((v2104 ^ ((int)((unsigned int)((int)((unsigned int)v2102 >> 2)) >> 1))) | (-(v2104 ^ ((int)((unsigned int)((int)((unsigned int)v2102 >> 2)) >> 1))))) >> 31)) | (~(((v2105 ^ ((int)((unsigned int)((int)((unsigned int)v2102 >> 2)) >> 1))) | (-(v2105 ^ ((int)((unsigned int)((int)((unsigned int)v2102 >> 2)) >> 1))))) >> 31))) & (1 ^ (100 ^ (((~(((v2106 ^ ((int)((unsigned int)((int)((unsigned int)v2102 >> 2)) >> 1))) | (-(v2106 ^ ((int)((unsigned int)((int)((unsigned int)v2102 >> 2)) >> 1))))) >> 31)) | (~(((v2107 ^ ((int)((unsigned int)((int)((unsigned int)v2102 >> 2)) >> 1))) | (-(v2107 ^ ((int)((unsigned int)((int)((unsigned int)v2102 >> 2)) >> 1))))) >> 31))) & 104)))));
  v2100->timer = v2330;
  int * v2110 = v2100->cache_vals;
  bool v2331 = !(((~(((v2104 ^ ((int)((unsigned int)((int)((unsigned int)v2102 >> 2)) >> 1))) | (-(v2104 ^ ((int)((unsigned int)((int)((unsigned int)v2102 >> 2)) >> 1))))) >> 31)) | (~(((v2105 ^ ((int)((unsigned int)((int)((unsigned int)v2102 >> 2)) >> 1))) | (-(v2105 ^ ((int)((unsigned int)((int)((unsigned int)v2102 >> 2)) >> 1))))) >> 31))) == 0);
  int v2203;
  if (v2331) {
    int * v2111 = v2100->cache_age;
    int v2333 = ((((int)((unsigned int)((int)((unsigned int)v2102 >> 2)) >> 1)) & 1) * 2) + ((~(((v2105 ^ ((int)((unsigned int)((int)((unsigned int)v2102 >> 2)) >> 1))) | (-(v2105 ^ ((int)((unsigned int)((int)((unsigned int)v2102 >> 2)) >> 1))))) >> 31)) & 1);
    int v2112 = v2111[v2333];
    int v2113 = v2111[v2326];
    int v2334 = v2113 + ((int)((unsigned int)(v2113 - v2112) >> 31));
    v2111[v2326] = v2334;
    int * v2115 = v2100->cache_age;
    int v2116 = v2115[v2327];
    int v2336 = v2116 + ((int)((unsigned int)(v2116 - v2112) >> 31));
    v2115[v2327] = v2336;
    int * v2118 = v2100->cache_age;
    v2118[v2333] = 0;
    v2203 = v2333;
  } else {
    int * v2121 = v2100->cache_age;
    int v2340 = (((int)((unsigned int)((int)((unsigned int)v2102 >> 2)) >> 1)) & 1) * 2;
    int v2122 = v2121[v2340];
    int * v2123 = v2100->cache_tags;
    int v2124 = v2123[v2340];
    int v2125 = v2121[v2327];
    int v2126 = v2123[v2327];
    bool v2342 = !(((~(((v2106 ^ ((int)((unsigned int)((int)((unsigned int)v2102 >> 2)) >> 1))) | (-(v2106 ^ ((int)((unsigned int)((int)((unsigned int)v2102 >> 2)) >> 1))))) >> 31)) | (~(((v2107 ^ ((int)((unsigned int)((int)((unsigned int)v2102 >> 2)) >> 1))) | (-(v2107 ^ ((int)((unsigned int)((int)((unsigned int)v2102 >> 2)) >> 1))))) >> 31))) == 0);
    int v2180;
    if (v2342) {
      int * v2127 = v2100->cache_age;
      int v2344 = (4 + ((((int)((unsigned int)((int)((unsigned int)v2102 >> 2)) >> 1)) & 3) * 2)) + ((~(((v2107 ^ ((int)((unsigned int)((int)((unsigned int)v2102 >> 2)) >> 1))) | (-(v2107 ^ ((int)((unsigned int)((int)((unsigned int)v2102 >> 2)) >> 1))))) >> 31)) & 1);
      int v2128 = v2127[v2344];
      int v2129 = v2127[v2328];
      int v2345 = v2129 + ((int)((unsigned int)(v2129 - v2128) >> 31));
      v2127[v2328] = v2345;
      int * v2131 = v2100->cache_age;
      int v2132 = v2131[v2329];
      int v2347 = v2132 + ((int)((unsigned int)(v2132 - v2128) >> 31));
      v2131[v2329] = v2347;
      int * v2134 = v2100->cache_age;
      v2134[v2344] = 0;
      v2180 = v2344;
    } else {
      int * v2137 = v2100->cache_age;
      int v2351 = 4 + ((((int)((unsigned int)((int)((unsigned int)v2102 >> 2)) >> 1)) & 3) * 2);
      int v2138 = v2137[v2351];
      int * v2139 = v2100->cache_tags;
      int v2140 = v2139[v2351];
      int v2141 = v2137[v2329];
      int v2142 = v2139[v2329];
      int * v2143 = v2100->cache_dirty;
      int v2354 = (4 + ((((int)((unsigned int)((int)((unsigned int)v2102 >> 2)) >> 1)) & 3) * 2)) + ((((v2138 + ((~(((v2140 ^ -1) | (-(v2140 ^ -1))) >> 31)) & 2)) - (v2141 + ((~(((v2142 ^ -1) | (-(v2142 ^ -1))) >> 31)) & 2))) >> 31) & 1);
      int v2144 = v2143[v2354];
      bool v2355 = !(v2144 == 0);
      if (v2355) {
        int * v2145 = v2100->cache_tags;
        int v2146 = v2145[v2354];
        int * v2147 = v2100->cache_vals;
        int v2358 = ((4 + ((((int)((unsigned int)((int)((unsigned int)v2102 >> 2)) >> 1)) & 3) * 2)) + ((((v2138 + ((~(((v2140 ^ -1) | (-(v2140 ^ -1))) >> 31)) & 2)) - (v2141 + ((~(((v2142 ^ -1) | (-(v2142 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
        int v2148 = v2147[v2358];
        int v2359 = (((4 + ((((int)((unsigned int)((int)((unsigned int)v2102 >> 2)) >> 1)) & 3) * 2)) + ((((v2138 + ((~(((v2140 ^ -1) | (-(v2140 ^ -1))) >> 31)) & 2)) - (v2141 + ((~(((v2142 ^ -1) | (-(v2142 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
        int v2149 = v2147[v2359];
        int * v2150 = v2100->mem;
        int v2361 = v2146 * 2;
        v2150[v2361] = v2148;
        int * v2152 = v2100->mem;
        int v2364 = (v2146 * 2) + 1;
        v2152[v2364] = v2149;
        ;
      } else {
        ;
      }
      int * v2157 = v2100->mem;
      int v2369 = ((int)((unsigned int)((int)((unsigned int)v2102 >> 2)) >> 1)) * 2;
      int v2158 = v2157[v2369];
      int v2370 = (((int)((unsigned int)((int)((unsigned int)v2102 >> 2)) >> 1)) * 2) + 1;
      int v2159 = v2157[v2370];
      int * v2160 = v2100->cache_vals;
      int v2372 = ((4 + ((((int)((unsigned int)((int)((unsigned int)v2102 >> 2)) >> 1)) & 3) * 2)) + ((((v2138 + ((~(((v2140 ^ -1) | (-(v2140 ^ -1))) >> 31)) & 2)) - (v2141 + ((~(((v2142 ^ -1) | (-(v2142 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
      v2160[v2372] = v2158;
      int * v2162 = v2100->cache_vals;
      int v2375 = (((4 + ((((int)((unsigned int)((int)((unsigned int)v2102 >> 2)) >> 1)) & 3) * 2)) + ((((v2138 + ((~(((v2140 ^ -1) | (-(v2140 ^ -1))) >> 31)) & 2)) - (v2141 + ((~(((v2142 ^ -1) | (-(v2142 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
      v2162[v2375] = v2159;
      int * v2164 = v2100->cache_tags;
      int v2378 = (int)((unsigned int)((int)((unsigned int)v2102 >> 2)) >> 1);
      v2164[v2354] = v2378;
      int * v2166 = v2100->cache_dirty;
      v2166[v2354] = 0;
      int * v2168 = v2100->cache_age;
      v2168[v2354] = 1;
      int * v2170 = v2100->cache_age;
      int v2171 = v2170[v2354];
      int v2172 = v2170[v2328];
      int v2384 = v2172 + ((int)((unsigned int)(v2172 - v2171) >> 31));
      v2170[v2328] = v2384;
      int * v2174 = v2100->cache_age;
      int v2175 = v2174[v2329];
      int v2386 = v2175 + ((int)((unsigned int)(v2175 - v2171) >> 31));
      v2174[v2329] = v2386;
      int * v2177 = v2100->cache_age;
      v2177[v2354] = 0;
      v2180 = v2354;
    }
    int * v2181 = v2100->cache_vals;
    int v2389 = v2180 * 2;
    int v2182 = v2181[v2389];
    int v2390 = (v2180 * 2) + 1;
    int v2183 = v2181[v2390];
    int v2391 = (((((int)((unsigned int)((int)((unsigned int)v2102 >> 2)) >> 1)) & 1) * 2) + ((((v2122 + ((~(((v2124 ^ -1) | (-(v2124 ^ -1))) >> 31)) & 2)) - (v2125 + ((~(((v2126 ^ -1) | (-(v2126 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
    v2181[v2391] = v2182;
    int * v2185 = v2100->cache_vals;
    int v2394 = ((((((int)((unsigned int)((int)((unsigned int)v2102 >> 2)) >> 1)) & 1) * 2) + ((((v2122 + ((~(((v2124 ^ -1) | (-(v2124 ^ -1))) >> 31)) & 2)) - (v2125 + ((~(((v2126 ^ -1) | (-(v2126 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
    v2185[v2394] = v2183;
    int * v2187 = v2100->cache_tags;
    int v2397 = ((((int)((unsigned int)((int)((unsigned int)v2102 >> 2)) >> 1)) & 1) * 2) + ((((v2122 + ((~(((v2124 ^ -1) | (-(v2124 ^ -1))) >> 31)) & 2)) - (v2125 + ((~(((v2126 ^ -1) | (-(v2126 ^ -1))) >> 31)) & 2))) >> 31) & 1);
    int v2398 = (int)((unsigned int)((int)((unsigned int)v2102 >> 2)) >> 1);
    v2187[v2397] = v2398;
    int * v2189 = v2100->cache_dirty;
    v2189[v2397] = 0;
    int * v2191 = v2100->cache_age;
    v2191[v2397] = 1;
    int * v2193 = v2100->cache_age;
    int v2194 = v2193[v2397];
    int v2195 = v2193[v2326];
    int v2404 = v2195 + ((int)((unsigned int)(v2195 - v2194) >> 31));
    v2193[v2326] = v2404;
    int * v2197 = v2100->cache_age;
    int v2198 = v2197[v2327];
    int v2406 = v2198 + ((int)((unsigned int)(v2198 - v2194) >> 31));
    v2197[v2327] = v2406;
    int * v2200 = v2100->cache_age;
    v2200[v2397] = 0;
    v2203 = v2397;
  }
  int v2409 = (v2203 * 2) + (((int)((unsigned int)v2102 >> 2)) & 1);
  int v2204 = v2110[v2409];
  int * v2205 = v2100->regs;
  v2205[12] = v2204;
  struct StateT * v2207 = v2087->b;
  int * v2208 = v2207->regs;
  int v2209 = v2208[11];
  int * v2210 = v2207->cache_tags;
  int v2416 = (((int)((unsigned int)((int)((unsigned int)v2209 >> 2)) >> 1)) & 1) * 2;
  int v2211 = v2210[v2416];
  int v2417 = ((((int)((unsigned int)((int)((unsigned int)v2209 >> 2)) >> 1)) & 1) * 2) + 1;
  int v2212 = v2210[v2417];
  int v2418 = 4 + ((((int)((unsigned int)((int)((unsigned int)v2209 >> 2)) >> 1)) & 3) * 2);
  int v2213 = v2210[v2418];
  int v2419 = (4 + ((((int)((unsigned int)((int)((unsigned int)v2209 >> 2)) >> 1)) & 3) * 2)) + 1;
  int v2214 = v2210[v2419];
  int v2215 = v2207->timer;
  int v2420 = v2215 + ((100 ^ (((~(((v2213 ^ ((int)((unsigned int)((int)((unsigned int)v2209 >> 2)) >> 1))) | (-(v2213 ^ ((int)((unsigned int)((int)((unsigned int)v2209 >> 2)) >> 1))))) >> 31)) | (~(((v2214 ^ ((int)((unsigned int)((int)((unsigned int)v2209 >> 2)) >> 1))) | (-(v2214 ^ ((int)((unsigned int)((int)((unsigned int)v2209 >> 2)) >> 1))))) >> 31))) & 104)) ^ (((~(((v2211 ^ ((int)((unsigned int)((int)((unsigned int)v2209 >> 2)) >> 1))) | (-(v2211 ^ ((int)((unsigned int)((int)((unsigned int)v2209 >> 2)) >> 1))))) >> 31)) | (~(((v2212 ^ ((int)((unsigned int)((int)((unsigned int)v2209 >> 2)) >> 1))) | (-(v2212 ^ ((int)((unsigned int)((int)((unsigned int)v2209 >> 2)) >> 1))))) >> 31))) & (1 ^ (100 ^ (((~(((v2213 ^ ((int)((unsigned int)((int)((unsigned int)v2209 >> 2)) >> 1))) | (-(v2213 ^ ((int)((unsigned int)((int)((unsigned int)v2209 >> 2)) >> 1))))) >> 31)) | (~(((v2214 ^ ((int)((unsigned int)((int)((unsigned int)v2209 >> 2)) >> 1))) | (-(v2214 ^ ((int)((unsigned int)((int)((unsigned int)v2209 >> 2)) >> 1))))) >> 31))) & 104)))));
  v2207->timer = v2420;
  int * v2217 = v2207->cache_vals;
  bool v2421 = !(((~(((v2211 ^ ((int)((unsigned int)((int)((unsigned int)v2209 >> 2)) >> 1))) | (-(v2211 ^ ((int)((unsigned int)((int)((unsigned int)v2209 >> 2)) >> 1))))) >> 31)) | (~(((v2212 ^ ((int)((unsigned int)((int)((unsigned int)v2209 >> 2)) >> 1))) | (-(v2212 ^ ((int)((unsigned int)((int)((unsigned int)v2209 >> 2)) >> 1))))) >> 31))) == 0);
  int v2310;
  if (v2421) {
    int * v2218 = v2207->cache_age;
    int v2423 = ((((int)((unsigned int)((int)((unsigned int)v2209 >> 2)) >> 1)) & 1) * 2) + ((~(((v2212 ^ ((int)((unsigned int)((int)((unsigned int)v2209 >> 2)) >> 1))) | (-(v2212 ^ ((int)((unsigned int)((int)((unsigned int)v2209 >> 2)) >> 1))))) >> 31)) & 1);
    int v2219 = v2218[v2423];
    int v2220 = v2218[v2416];
    int v2424 = v2220 + ((int)((unsigned int)(v2220 - v2219) >> 31));
    v2218[v2416] = v2424;
    int * v2222 = v2207->cache_age;
    int v2223 = v2222[v2417];
    int v2426 = v2223 + ((int)((unsigned int)(v2223 - v2219) >> 31));
    v2222[v2417] = v2426;
    int * v2225 = v2207->cache_age;
    v2225[v2423] = 0;
    v2310 = v2423;
  } else {
    int * v2228 = v2207->cache_age;
    int v2430 = (((int)((unsigned int)((int)((unsigned int)v2209 >> 2)) >> 1)) & 1) * 2;
    int v2229 = v2228[v2430];
    int * v2230 = v2207->cache_tags;
    int v2231 = v2230[v2430];
    int v2232 = v2228[v2417];
    int v2233 = v2230[v2417];
    bool v2432 = !(((~(((v2213 ^ ((int)((unsigned int)((int)((unsigned int)v2209 >> 2)) >> 1))) | (-(v2213 ^ ((int)((unsigned int)((int)((unsigned int)v2209 >> 2)) >> 1))))) >> 31)) | (~(((v2214 ^ ((int)((unsigned int)((int)((unsigned int)v2209 >> 2)) >> 1))) | (-(v2214 ^ ((int)((unsigned int)((int)((unsigned int)v2209 >> 2)) >> 1))))) >> 31))) == 0);
    int v2287;
    if (v2432) {
      int * v2234 = v2207->cache_age;
      int v2434 = (4 + ((((int)((unsigned int)((int)((unsigned int)v2209 >> 2)) >> 1)) & 3) * 2)) + ((~(((v2214 ^ ((int)((unsigned int)((int)((unsigned int)v2209 >> 2)) >> 1))) | (-(v2214 ^ ((int)((unsigned int)((int)((unsigned int)v2209 >> 2)) >> 1))))) >> 31)) & 1);
      int v2235 = v2234[v2434];
      int v2236 = v2234[v2418];
      int v2435 = v2236 + ((int)((unsigned int)(v2236 - v2235) >> 31));
      v2234[v2418] = v2435;
      int * v2238 = v2207->cache_age;
      int v2239 = v2238[v2419];
      int v2437 = v2239 + ((int)((unsigned int)(v2239 - v2235) >> 31));
      v2238[v2419] = v2437;
      int * v2241 = v2207->cache_age;
      v2241[v2434] = 0;
      v2287 = v2434;
    } else {
      int * v2244 = v2207->cache_age;
      int v2441 = 4 + ((((int)((unsigned int)((int)((unsigned int)v2209 >> 2)) >> 1)) & 3) * 2);
      int v2245 = v2244[v2441];
      int * v2246 = v2207->cache_tags;
      int v2247 = v2246[v2441];
      int v2248 = v2244[v2419];
      int v2249 = v2246[v2419];
      int * v2250 = v2207->cache_dirty;
      int v2444 = (4 + ((((int)((unsigned int)((int)((unsigned int)v2209 >> 2)) >> 1)) & 3) * 2)) + ((((v2245 + ((~(((v2247 ^ -1) | (-(v2247 ^ -1))) >> 31)) & 2)) - (v2248 + ((~(((v2249 ^ -1) | (-(v2249 ^ -1))) >> 31)) & 2))) >> 31) & 1);
      int v2251 = v2250[v2444];
      bool v2445 = !(v2251 == 0);
      if (v2445) {
        int * v2252 = v2207->cache_tags;
        int v2253 = v2252[v2444];
        int * v2254 = v2207->cache_vals;
        int v2448 = ((4 + ((((int)((unsigned int)((int)((unsigned int)v2209 >> 2)) >> 1)) & 3) * 2)) + ((((v2245 + ((~(((v2247 ^ -1) | (-(v2247 ^ -1))) >> 31)) & 2)) - (v2248 + ((~(((v2249 ^ -1) | (-(v2249 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
        int v2255 = v2254[v2448];
        int v2449 = (((4 + ((((int)((unsigned int)((int)((unsigned int)v2209 >> 2)) >> 1)) & 3) * 2)) + ((((v2245 + ((~(((v2247 ^ -1) | (-(v2247 ^ -1))) >> 31)) & 2)) - (v2248 + ((~(((v2249 ^ -1) | (-(v2249 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
        int v2256 = v2254[v2449];
        int * v2257 = v2207->mem;
        int v2451 = v2253 * 2;
        v2257[v2451] = v2255;
        int * v2259 = v2207->mem;
        int v2454 = (v2253 * 2) + 1;
        v2259[v2454] = v2256;
        ;
      } else {
        ;
      }
      int * v2264 = v2207->mem;
      int v2459 = ((int)((unsigned int)((int)((unsigned int)v2209 >> 2)) >> 1)) * 2;
      int v2265 = v2264[v2459];
      int v2460 = (((int)((unsigned int)((int)((unsigned int)v2209 >> 2)) >> 1)) * 2) + 1;
      int v2266 = v2264[v2460];
      int * v2267 = v2207->cache_vals;
      int v2462 = ((4 + ((((int)((unsigned int)((int)((unsigned int)v2209 >> 2)) >> 1)) & 3) * 2)) + ((((v2245 + ((~(((v2247 ^ -1) | (-(v2247 ^ -1))) >> 31)) & 2)) - (v2248 + ((~(((v2249 ^ -1) | (-(v2249 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
      v2267[v2462] = v2265;
      int * v2269 = v2207->cache_vals;
      int v2465 = (((4 + ((((int)((unsigned int)((int)((unsigned int)v2209 >> 2)) >> 1)) & 3) * 2)) + ((((v2245 + ((~(((v2247 ^ -1) | (-(v2247 ^ -1))) >> 31)) & 2)) - (v2248 + ((~(((v2249 ^ -1) | (-(v2249 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
      v2269[v2465] = v2266;
      int * v2271 = v2207->cache_tags;
      int v2468 = (int)((unsigned int)((int)((unsigned int)v2209 >> 2)) >> 1);
      v2271[v2444] = v2468;
      int * v2273 = v2207->cache_dirty;
      v2273[v2444] = 0;
      int * v2275 = v2207->cache_age;
      v2275[v2444] = 1;
      int * v2277 = v2207->cache_age;
      int v2278 = v2277[v2444];
      int v2279 = v2277[v2418];
      int v2474 = v2279 + ((int)((unsigned int)(v2279 - v2278) >> 31));
      v2277[v2418] = v2474;
      int * v2281 = v2207->cache_age;
      int v2282 = v2281[v2419];
      int v2476 = v2282 + ((int)((unsigned int)(v2282 - v2278) >> 31));
      v2281[v2419] = v2476;
      int * v2284 = v2207->cache_age;
      v2284[v2444] = 0;
      v2287 = v2444;
    }
    int * v2288 = v2207->cache_vals;
    int v2479 = v2287 * 2;
    int v2289 = v2288[v2479];
    int v2480 = (v2287 * 2) + 1;
    int v2290 = v2288[v2480];
    int v2481 = (((((int)((unsigned int)((int)((unsigned int)v2209 >> 2)) >> 1)) & 1) * 2) + ((((v2229 + ((~(((v2231 ^ -1) | (-(v2231 ^ -1))) >> 31)) & 2)) - (v2232 + ((~(((v2233 ^ -1) | (-(v2233 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
    v2288[v2481] = v2289;
    int * v2292 = v2207->cache_vals;
    int v2484 = ((((((int)((unsigned int)((int)((unsigned int)v2209 >> 2)) >> 1)) & 1) * 2) + ((((v2229 + ((~(((v2231 ^ -1) | (-(v2231 ^ -1))) >> 31)) & 2)) - (v2232 + ((~(((v2233 ^ -1) | (-(v2233 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
    v2292[v2484] = v2290;
    int * v2294 = v2207->cache_tags;
    int v2487 = ((((int)((unsigned int)((int)((unsigned int)v2209 >> 2)) >> 1)) & 1) * 2) + ((((v2229 + ((~(((v2231 ^ -1) | (-(v2231 ^ -1))) >> 31)) & 2)) - (v2232 + ((~(((v2233 ^ -1) | (-(v2233 ^ -1))) >> 31)) & 2))) >> 31) & 1);
    int v2488 = (int)((unsigned int)((int)((unsigned int)v2209 >> 2)) >> 1);
    v2294[v2487] = v2488;
    int * v2296 = v2207->cache_dirty;
    v2296[v2487] = 0;
    int * v2298 = v2207->cache_age;
    v2298[v2487] = 1;
    int * v2300 = v2207->cache_age;
    int v2301 = v2300[v2487];
    int v2302 = v2300[v2416];
    int v2494 = v2302 + ((int)((unsigned int)(v2302 - v2301) >> 31));
    v2300[v2416] = v2494;
    int * v2304 = v2207->cache_age;
    int v2305 = v2304[v2417];
    int v2496 = v2305 + ((int)((unsigned int)(v2305 - v2301) >> 31));
    v2304[v2417] = v2496;
    int * v2307 = v2207->cache_age;
    v2307[v2487] = 0;
    v2310 = v2487;
  }
  int v2499 = (v2310 * 2) + (((int)((unsigned int)v2209 >> 2)) & 1);
  int v2311 = v2217[v2499];
  int * v2312 = v2207->regs;
  v2312[12] = v2311;
  return v2087;
}

struct StateT2 * slot_5(struct StateT2 * v1669) {
  struct StateT * v1670 = v1669->a;
  int v1671 = v1670->timer;
  struct StateT * v1672 = v1669->b;
  int v1673 = v1672->timer;
  bool v1900 = v1671 == v1673;
  squared_assert(v1900);
  squared_assume(v1900);
  struct StateT * v1676 = v1669->a;
  int v1677 = v1676->timer;
  int v1902 = v1677 + 1;
  v1676->timer = v1902;
  struct StateT * v1679 = v1669->b;
  int v1680 = v1679->timer;
  int v1904 = v1680 + 1;
  v1679->timer = v1904;
  struct StateT * v1682 = v1669->a;
  int * v1683 = v1682->regs;
  int v1684 = v1683[8];
  int * v1685 = v1682->cache_tags;
  int v1909 = (((int)((unsigned int)((int)((unsigned int)v1684 >> 2)) >> 1)) & 1) * 2;
  int v1686 = v1685[v1909];
  int v1910 = ((((int)((unsigned int)((int)((unsigned int)v1684 >> 2)) >> 1)) & 1) * 2) + 1;
  int v1687 = v1685[v1910];
  int v1911 = 4 + ((((int)((unsigned int)((int)((unsigned int)v1684 >> 2)) >> 1)) & 3) * 2);
  int v1688 = v1685[v1911];
  int v1912 = (4 + ((((int)((unsigned int)((int)((unsigned int)v1684 >> 2)) >> 1)) & 3) * 2)) + 1;
  int v1689 = v1685[v1912];
  int v1690 = v1682->timer;
  int v1913 = v1690 + ((100 ^ (((~(((v1688 ^ ((int)((unsigned int)((int)((unsigned int)v1684 >> 2)) >> 1))) | (-(v1688 ^ ((int)((unsigned int)((int)((unsigned int)v1684 >> 2)) >> 1))))) >> 31)) | (~(((v1689 ^ ((int)((unsigned int)((int)((unsigned int)v1684 >> 2)) >> 1))) | (-(v1689 ^ ((int)((unsigned int)((int)((unsigned int)v1684 >> 2)) >> 1))))) >> 31))) & 104)) ^ (((~(((v1686 ^ ((int)((unsigned int)((int)((unsigned int)v1684 >> 2)) >> 1))) | (-(v1686 ^ ((int)((unsigned int)((int)((unsigned int)v1684 >> 2)) >> 1))))) >> 31)) | (~(((v1687 ^ ((int)((unsigned int)((int)((unsigned int)v1684 >> 2)) >> 1))) | (-(v1687 ^ ((int)((unsigned int)((int)((unsigned int)v1684 >> 2)) >> 1))))) >> 31))) & (1 ^ (100 ^ (((~(((v1688 ^ ((int)((unsigned int)((int)((unsigned int)v1684 >> 2)) >> 1))) | (-(v1688 ^ ((int)((unsigned int)((int)((unsigned int)v1684 >> 2)) >> 1))))) >> 31)) | (~(((v1689 ^ ((int)((unsigned int)((int)((unsigned int)v1684 >> 2)) >> 1))) | (-(v1689 ^ ((int)((unsigned int)((int)((unsigned int)v1684 >> 2)) >> 1))))) >> 31))) & 104)))));
  v1682->timer = v1913;
  int * v1692 = v1682->cache_vals;
  bool v1914 = !(((~(((v1686 ^ ((int)((unsigned int)((int)((unsigned int)v1684 >> 2)) >> 1))) | (-(v1686 ^ ((int)((unsigned int)((int)((unsigned int)v1684 >> 2)) >> 1))))) >> 31)) | (~(((v1687 ^ ((int)((unsigned int)((int)((unsigned int)v1684 >> 2)) >> 1))) | (-(v1687 ^ ((int)((unsigned int)((int)((unsigned int)v1684 >> 2)) >> 1))))) >> 31))) == 0);
  int v1785;
  if (v1914) {
    int * v1693 = v1682->cache_age;
    int v1916 = ((((int)((unsigned int)((int)((unsigned int)v1684 >> 2)) >> 1)) & 1) * 2) + ((~(((v1687 ^ ((int)((unsigned int)((int)((unsigned int)v1684 >> 2)) >> 1))) | (-(v1687 ^ ((int)((unsigned int)((int)((unsigned int)v1684 >> 2)) >> 1))))) >> 31)) & 1);
    int v1694 = v1693[v1916];
    int v1695 = v1693[v1909];
    int v1917 = v1695 + ((int)((unsigned int)(v1695 - v1694) >> 31));
    v1693[v1909] = v1917;
    int * v1697 = v1682->cache_age;
    int v1698 = v1697[v1910];
    int v1919 = v1698 + ((int)((unsigned int)(v1698 - v1694) >> 31));
    v1697[v1910] = v1919;
    int * v1700 = v1682->cache_age;
    v1700[v1916] = 0;
    v1785 = v1916;
  } else {
    int * v1703 = v1682->cache_age;
    int v1923 = (((int)((unsigned int)((int)((unsigned int)v1684 >> 2)) >> 1)) & 1) * 2;
    int v1704 = v1703[v1923];
    int * v1705 = v1682->cache_tags;
    int v1706 = v1705[v1923];
    int v1707 = v1703[v1910];
    int v1708 = v1705[v1910];
    bool v1925 = !(((~(((v1688 ^ ((int)((unsigned int)((int)((unsigned int)v1684 >> 2)) >> 1))) | (-(v1688 ^ ((int)((unsigned int)((int)((unsigned int)v1684 >> 2)) >> 1))))) >> 31)) | (~(((v1689 ^ ((int)((unsigned int)((int)((unsigned int)v1684 >> 2)) >> 1))) | (-(v1689 ^ ((int)((unsigned int)((int)((unsigned int)v1684 >> 2)) >> 1))))) >> 31))) == 0);
    int v1762;
    if (v1925) {
      int * v1709 = v1682->cache_age;
      int v1927 = (4 + ((((int)((unsigned int)((int)((unsigned int)v1684 >> 2)) >> 1)) & 3) * 2)) + ((~(((v1689 ^ ((int)((unsigned int)((int)((unsigned int)v1684 >> 2)) >> 1))) | (-(v1689 ^ ((int)((unsigned int)((int)((unsigned int)v1684 >> 2)) >> 1))))) >> 31)) & 1);
      int v1710 = v1709[v1927];
      int v1711 = v1709[v1911];
      int v1928 = v1711 + ((int)((unsigned int)(v1711 - v1710) >> 31));
      v1709[v1911] = v1928;
      int * v1713 = v1682->cache_age;
      int v1714 = v1713[v1912];
      int v1930 = v1714 + ((int)((unsigned int)(v1714 - v1710) >> 31));
      v1713[v1912] = v1930;
      int * v1716 = v1682->cache_age;
      v1716[v1927] = 0;
      v1762 = v1927;
    } else {
      int * v1719 = v1682->cache_age;
      int v1934 = 4 + ((((int)((unsigned int)((int)((unsigned int)v1684 >> 2)) >> 1)) & 3) * 2);
      int v1720 = v1719[v1934];
      int * v1721 = v1682->cache_tags;
      int v1722 = v1721[v1934];
      int v1723 = v1719[v1912];
      int v1724 = v1721[v1912];
      int * v1725 = v1682->cache_dirty;
      int v1937 = (4 + ((((int)((unsigned int)((int)((unsigned int)v1684 >> 2)) >> 1)) & 3) * 2)) + ((((v1720 + ((~(((v1722 ^ -1) | (-(v1722 ^ -1))) >> 31)) & 2)) - (v1723 + ((~(((v1724 ^ -1) | (-(v1724 ^ -1))) >> 31)) & 2))) >> 31) & 1);
      int v1726 = v1725[v1937];
      bool v1938 = !(v1726 == 0);
      if (v1938) {
        int * v1727 = v1682->cache_tags;
        int v1728 = v1727[v1937];
        int * v1729 = v1682->cache_vals;
        int v1941 = ((4 + ((((int)((unsigned int)((int)((unsigned int)v1684 >> 2)) >> 1)) & 3) * 2)) + ((((v1720 + ((~(((v1722 ^ -1) | (-(v1722 ^ -1))) >> 31)) & 2)) - (v1723 + ((~(((v1724 ^ -1) | (-(v1724 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
        int v1730 = v1729[v1941];
        int v1942 = (((4 + ((((int)((unsigned int)((int)((unsigned int)v1684 >> 2)) >> 1)) & 3) * 2)) + ((((v1720 + ((~(((v1722 ^ -1) | (-(v1722 ^ -1))) >> 31)) & 2)) - (v1723 + ((~(((v1724 ^ -1) | (-(v1724 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
        int v1731 = v1729[v1942];
        int * v1732 = v1682->mem;
        int v1944 = v1728 * 2;
        v1732[v1944] = v1730;
        int * v1734 = v1682->mem;
        int v1947 = (v1728 * 2) + 1;
        v1734[v1947] = v1731;
        ;
      } else {
        ;
      }
      int * v1739 = v1682->mem;
      int v1952 = ((int)((unsigned int)((int)((unsigned int)v1684 >> 2)) >> 1)) * 2;
      int v1740 = v1739[v1952];
      int v1953 = (((int)((unsigned int)((int)((unsigned int)v1684 >> 2)) >> 1)) * 2) + 1;
      int v1741 = v1739[v1953];
      int * v1742 = v1682->cache_vals;
      int v1955 = ((4 + ((((int)((unsigned int)((int)((unsigned int)v1684 >> 2)) >> 1)) & 3) * 2)) + ((((v1720 + ((~(((v1722 ^ -1) | (-(v1722 ^ -1))) >> 31)) & 2)) - (v1723 + ((~(((v1724 ^ -1) | (-(v1724 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
      v1742[v1955] = v1740;
      int * v1744 = v1682->cache_vals;
      int v1958 = (((4 + ((((int)((unsigned int)((int)((unsigned int)v1684 >> 2)) >> 1)) & 3) * 2)) + ((((v1720 + ((~(((v1722 ^ -1) | (-(v1722 ^ -1))) >> 31)) & 2)) - (v1723 + ((~(((v1724 ^ -1) | (-(v1724 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
      v1744[v1958] = v1741;
      int * v1746 = v1682->cache_tags;
      int v1961 = (int)((unsigned int)((int)((unsigned int)v1684 >> 2)) >> 1);
      v1746[v1937] = v1961;
      int * v1748 = v1682->cache_dirty;
      v1748[v1937] = 0;
      int * v1750 = v1682->cache_age;
      v1750[v1937] = 1;
      int * v1752 = v1682->cache_age;
      int v1753 = v1752[v1937];
      int v1754 = v1752[v1911];
      int v1967 = v1754 + ((int)((unsigned int)(v1754 - v1753) >> 31));
      v1752[v1911] = v1967;
      int * v1756 = v1682->cache_age;
      int v1757 = v1756[v1912];
      int v1969 = v1757 + ((int)((unsigned int)(v1757 - v1753) >> 31));
      v1756[v1912] = v1969;
      int * v1759 = v1682->cache_age;
      v1759[v1937] = 0;
      v1762 = v1937;
    }
    int * v1763 = v1682->cache_vals;
    int v1972 = v1762 * 2;
    int v1764 = v1763[v1972];
    int v1973 = (v1762 * 2) + 1;
    int v1765 = v1763[v1973];
    int v1974 = (((((int)((unsigned int)((int)((unsigned int)v1684 >> 2)) >> 1)) & 1) * 2) + ((((v1704 + ((~(((v1706 ^ -1) | (-(v1706 ^ -1))) >> 31)) & 2)) - (v1707 + ((~(((v1708 ^ -1) | (-(v1708 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
    v1763[v1974] = v1764;
    int * v1767 = v1682->cache_vals;
    int v1977 = ((((((int)((unsigned int)((int)((unsigned int)v1684 >> 2)) >> 1)) & 1) * 2) + ((((v1704 + ((~(((v1706 ^ -1) | (-(v1706 ^ -1))) >> 31)) & 2)) - (v1707 + ((~(((v1708 ^ -1) | (-(v1708 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
    v1767[v1977] = v1765;
    int * v1769 = v1682->cache_tags;
    int v1980 = ((((int)((unsigned int)((int)((unsigned int)v1684 >> 2)) >> 1)) & 1) * 2) + ((((v1704 + ((~(((v1706 ^ -1) | (-(v1706 ^ -1))) >> 31)) & 2)) - (v1707 + ((~(((v1708 ^ -1) | (-(v1708 ^ -1))) >> 31)) & 2))) >> 31) & 1);
    int v1981 = (int)((unsigned int)((int)((unsigned int)v1684 >> 2)) >> 1);
    v1769[v1980] = v1981;
    int * v1771 = v1682->cache_dirty;
    v1771[v1980] = 0;
    int * v1773 = v1682->cache_age;
    v1773[v1980] = 1;
    int * v1775 = v1682->cache_age;
    int v1776 = v1775[v1980];
    int v1777 = v1775[v1909];
    int v1987 = v1777 + ((int)((unsigned int)(v1777 - v1776) >> 31));
    v1775[v1909] = v1987;
    int * v1779 = v1682->cache_age;
    int v1780 = v1779[v1910];
    int v1989 = v1780 + ((int)((unsigned int)(v1780 - v1776) >> 31));
    v1779[v1910] = v1989;
    int * v1782 = v1682->cache_age;
    v1782[v1980] = 0;
    v1785 = v1980;
  }
  int v1992 = (v1785 * 2) + (((int)((unsigned int)v1684 >> 2)) & 1);
  int v1786 = v1692[v1992];
  int * v1787 = v1682->regs;
  v1787[11] = v1786;
  struct StateT * v1789 = v1669->b;
  int * v1790 = v1789->regs;
  int v1791 = v1790[8];
  int * v1792 = v1789->cache_tags;
  int v1999 = (((int)((unsigned int)((int)((unsigned int)v1791 >> 2)) >> 1)) & 1) * 2;
  int v1793 = v1792[v1999];
  int v2000 = ((((int)((unsigned int)((int)((unsigned int)v1791 >> 2)) >> 1)) & 1) * 2) + 1;
  int v1794 = v1792[v2000];
  int v2001 = 4 + ((((int)((unsigned int)((int)((unsigned int)v1791 >> 2)) >> 1)) & 3) * 2);
  int v1795 = v1792[v2001];
  int v2002 = (4 + ((((int)((unsigned int)((int)((unsigned int)v1791 >> 2)) >> 1)) & 3) * 2)) + 1;
  int v1796 = v1792[v2002];
  int v1797 = v1789->timer;
  int v2003 = v1797 + ((100 ^ (((~(((v1795 ^ ((int)((unsigned int)((int)((unsigned int)v1791 >> 2)) >> 1))) | (-(v1795 ^ ((int)((unsigned int)((int)((unsigned int)v1791 >> 2)) >> 1))))) >> 31)) | (~(((v1796 ^ ((int)((unsigned int)((int)((unsigned int)v1791 >> 2)) >> 1))) | (-(v1796 ^ ((int)((unsigned int)((int)((unsigned int)v1791 >> 2)) >> 1))))) >> 31))) & 104)) ^ (((~(((v1793 ^ ((int)((unsigned int)((int)((unsigned int)v1791 >> 2)) >> 1))) | (-(v1793 ^ ((int)((unsigned int)((int)((unsigned int)v1791 >> 2)) >> 1))))) >> 31)) | (~(((v1794 ^ ((int)((unsigned int)((int)((unsigned int)v1791 >> 2)) >> 1))) | (-(v1794 ^ ((int)((unsigned int)((int)((unsigned int)v1791 >> 2)) >> 1))))) >> 31))) & (1 ^ (100 ^ (((~(((v1795 ^ ((int)((unsigned int)((int)((unsigned int)v1791 >> 2)) >> 1))) | (-(v1795 ^ ((int)((unsigned int)((int)((unsigned int)v1791 >> 2)) >> 1))))) >> 31)) | (~(((v1796 ^ ((int)((unsigned int)((int)((unsigned int)v1791 >> 2)) >> 1))) | (-(v1796 ^ ((int)((unsigned int)((int)((unsigned int)v1791 >> 2)) >> 1))))) >> 31))) & 104)))));
  v1789->timer = v2003;
  int * v1799 = v1789->cache_vals;
  bool v2004 = !(((~(((v1793 ^ ((int)((unsigned int)((int)((unsigned int)v1791 >> 2)) >> 1))) | (-(v1793 ^ ((int)((unsigned int)((int)((unsigned int)v1791 >> 2)) >> 1))))) >> 31)) | (~(((v1794 ^ ((int)((unsigned int)((int)((unsigned int)v1791 >> 2)) >> 1))) | (-(v1794 ^ ((int)((unsigned int)((int)((unsigned int)v1791 >> 2)) >> 1))))) >> 31))) == 0);
  int v1892;
  if (v2004) {
    int * v1800 = v1789->cache_age;
    int v2006 = ((((int)((unsigned int)((int)((unsigned int)v1791 >> 2)) >> 1)) & 1) * 2) + ((~(((v1794 ^ ((int)((unsigned int)((int)((unsigned int)v1791 >> 2)) >> 1))) | (-(v1794 ^ ((int)((unsigned int)((int)((unsigned int)v1791 >> 2)) >> 1))))) >> 31)) & 1);
    int v1801 = v1800[v2006];
    int v1802 = v1800[v1999];
    int v2007 = v1802 + ((int)((unsigned int)(v1802 - v1801) >> 31));
    v1800[v1999] = v2007;
    int * v1804 = v1789->cache_age;
    int v1805 = v1804[v2000];
    int v2009 = v1805 + ((int)((unsigned int)(v1805 - v1801) >> 31));
    v1804[v2000] = v2009;
    int * v1807 = v1789->cache_age;
    v1807[v2006] = 0;
    v1892 = v2006;
  } else {
    int * v1810 = v1789->cache_age;
    int v2013 = (((int)((unsigned int)((int)((unsigned int)v1791 >> 2)) >> 1)) & 1) * 2;
    int v1811 = v1810[v2013];
    int * v1812 = v1789->cache_tags;
    int v1813 = v1812[v2013];
    int v1814 = v1810[v2000];
    int v1815 = v1812[v2000];
    bool v2015 = !(((~(((v1795 ^ ((int)((unsigned int)((int)((unsigned int)v1791 >> 2)) >> 1))) | (-(v1795 ^ ((int)((unsigned int)((int)((unsigned int)v1791 >> 2)) >> 1))))) >> 31)) | (~(((v1796 ^ ((int)((unsigned int)((int)((unsigned int)v1791 >> 2)) >> 1))) | (-(v1796 ^ ((int)((unsigned int)((int)((unsigned int)v1791 >> 2)) >> 1))))) >> 31))) == 0);
    int v1869;
    if (v2015) {
      int * v1816 = v1789->cache_age;
      int v2017 = (4 + ((((int)((unsigned int)((int)((unsigned int)v1791 >> 2)) >> 1)) & 3) * 2)) + ((~(((v1796 ^ ((int)((unsigned int)((int)((unsigned int)v1791 >> 2)) >> 1))) | (-(v1796 ^ ((int)((unsigned int)((int)((unsigned int)v1791 >> 2)) >> 1))))) >> 31)) & 1);
      int v1817 = v1816[v2017];
      int v1818 = v1816[v2001];
      int v2018 = v1818 + ((int)((unsigned int)(v1818 - v1817) >> 31));
      v1816[v2001] = v2018;
      int * v1820 = v1789->cache_age;
      int v1821 = v1820[v2002];
      int v2020 = v1821 + ((int)((unsigned int)(v1821 - v1817) >> 31));
      v1820[v2002] = v2020;
      int * v1823 = v1789->cache_age;
      v1823[v2017] = 0;
      v1869 = v2017;
    } else {
      int * v1826 = v1789->cache_age;
      int v2024 = 4 + ((((int)((unsigned int)((int)((unsigned int)v1791 >> 2)) >> 1)) & 3) * 2);
      int v1827 = v1826[v2024];
      int * v1828 = v1789->cache_tags;
      int v1829 = v1828[v2024];
      int v1830 = v1826[v2002];
      int v1831 = v1828[v2002];
      int * v1832 = v1789->cache_dirty;
      int v2027 = (4 + ((((int)((unsigned int)((int)((unsigned int)v1791 >> 2)) >> 1)) & 3) * 2)) + ((((v1827 + ((~(((v1829 ^ -1) | (-(v1829 ^ -1))) >> 31)) & 2)) - (v1830 + ((~(((v1831 ^ -1) | (-(v1831 ^ -1))) >> 31)) & 2))) >> 31) & 1);
      int v1833 = v1832[v2027];
      bool v2028 = !(v1833 == 0);
      if (v2028) {
        int * v1834 = v1789->cache_tags;
        int v1835 = v1834[v2027];
        int * v1836 = v1789->cache_vals;
        int v2031 = ((4 + ((((int)((unsigned int)((int)((unsigned int)v1791 >> 2)) >> 1)) & 3) * 2)) + ((((v1827 + ((~(((v1829 ^ -1) | (-(v1829 ^ -1))) >> 31)) & 2)) - (v1830 + ((~(((v1831 ^ -1) | (-(v1831 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
        int v1837 = v1836[v2031];
        int v2032 = (((4 + ((((int)((unsigned int)((int)((unsigned int)v1791 >> 2)) >> 1)) & 3) * 2)) + ((((v1827 + ((~(((v1829 ^ -1) | (-(v1829 ^ -1))) >> 31)) & 2)) - (v1830 + ((~(((v1831 ^ -1) | (-(v1831 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
        int v1838 = v1836[v2032];
        int * v1839 = v1789->mem;
        int v2034 = v1835 * 2;
        v1839[v2034] = v1837;
        int * v1841 = v1789->mem;
        int v2037 = (v1835 * 2) + 1;
        v1841[v2037] = v1838;
        ;
      } else {
        ;
      }
      int * v1846 = v1789->mem;
      int v2042 = ((int)((unsigned int)((int)((unsigned int)v1791 >> 2)) >> 1)) * 2;
      int v1847 = v1846[v2042];
      int v2043 = (((int)((unsigned int)((int)((unsigned int)v1791 >> 2)) >> 1)) * 2) + 1;
      int v1848 = v1846[v2043];
      int * v1849 = v1789->cache_vals;
      int v2045 = ((4 + ((((int)((unsigned int)((int)((unsigned int)v1791 >> 2)) >> 1)) & 3) * 2)) + ((((v1827 + ((~(((v1829 ^ -1) | (-(v1829 ^ -1))) >> 31)) & 2)) - (v1830 + ((~(((v1831 ^ -1) | (-(v1831 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
      v1849[v2045] = v1847;
      int * v1851 = v1789->cache_vals;
      int v2048 = (((4 + ((((int)((unsigned int)((int)((unsigned int)v1791 >> 2)) >> 1)) & 3) * 2)) + ((((v1827 + ((~(((v1829 ^ -1) | (-(v1829 ^ -1))) >> 31)) & 2)) - (v1830 + ((~(((v1831 ^ -1) | (-(v1831 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
      v1851[v2048] = v1848;
      int * v1853 = v1789->cache_tags;
      int v2051 = (int)((unsigned int)((int)((unsigned int)v1791 >> 2)) >> 1);
      v1853[v2027] = v2051;
      int * v1855 = v1789->cache_dirty;
      v1855[v2027] = 0;
      int * v1857 = v1789->cache_age;
      v1857[v2027] = 1;
      int * v1859 = v1789->cache_age;
      int v1860 = v1859[v2027];
      int v1861 = v1859[v2001];
      int v2057 = v1861 + ((int)((unsigned int)(v1861 - v1860) >> 31));
      v1859[v2001] = v2057;
      int * v1863 = v1789->cache_age;
      int v1864 = v1863[v2002];
      int v2059 = v1864 + ((int)((unsigned int)(v1864 - v1860) >> 31));
      v1863[v2002] = v2059;
      int * v1866 = v1789->cache_age;
      v1866[v2027] = 0;
      v1869 = v2027;
    }
    int * v1870 = v1789->cache_vals;
    int v2062 = v1869 * 2;
    int v1871 = v1870[v2062];
    int v2063 = (v1869 * 2) + 1;
    int v1872 = v1870[v2063];
    int v2064 = (((((int)((unsigned int)((int)((unsigned int)v1791 >> 2)) >> 1)) & 1) * 2) + ((((v1811 + ((~(((v1813 ^ -1) | (-(v1813 ^ -1))) >> 31)) & 2)) - (v1814 + ((~(((v1815 ^ -1) | (-(v1815 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
    v1870[v2064] = v1871;
    int * v1874 = v1789->cache_vals;
    int v2067 = ((((((int)((unsigned int)((int)((unsigned int)v1791 >> 2)) >> 1)) & 1) * 2) + ((((v1811 + ((~(((v1813 ^ -1) | (-(v1813 ^ -1))) >> 31)) & 2)) - (v1814 + ((~(((v1815 ^ -1) | (-(v1815 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
    v1874[v2067] = v1872;
    int * v1876 = v1789->cache_tags;
    int v2070 = ((((int)((unsigned int)((int)((unsigned int)v1791 >> 2)) >> 1)) & 1) * 2) + ((((v1811 + ((~(((v1813 ^ -1) | (-(v1813 ^ -1))) >> 31)) & 2)) - (v1814 + ((~(((v1815 ^ -1) | (-(v1815 ^ -1))) >> 31)) & 2))) >> 31) & 1);
    int v2071 = (int)((unsigned int)((int)((unsigned int)v1791 >> 2)) >> 1);
    v1876[v2070] = v2071;
    int * v1878 = v1789->cache_dirty;
    v1878[v2070] = 0;
    int * v1880 = v1789->cache_age;
    v1880[v2070] = 1;
    int * v1882 = v1789->cache_age;
    int v1883 = v1882[v2070];
    int v1884 = v1882[v1999];
    int v2077 = v1884 + ((int)((unsigned int)(v1884 - v1883) >> 31));
    v1882[v1999] = v2077;
    int * v1886 = v1789->cache_age;
    int v1887 = v1886[v2000];
    int v2079 = v1887 + ((int)((unsigned int)(v1887 - v1883) >> 31));
    v1886[v2000] = v2079;
    int * v1889 = v1789->cache_age;
    v1889[v2070] = 0;
    v1892 = v2070;
  }
  int v2082 = (v1892 * 2) + (((int)((unsigned int)v1791 >> 2)) & 1);
  int v1893 = v1799[v2082];
  int * v1894 = v1789->regs;
  v1894[11] = v1893;
  struct StateT2 * v1896 = slot_6(v1669);
  return v1896;
}

struct StateT2 * slot_4(struct StateT2 * v1283) {
  struct StateT * v1284 = v1283->a;
  int v1285 = v1284->timer;
  struct StateT * v1286 = v1283->b;
  int v1287 = v1286->timer;
  bool v1510 = v1285 == v1287;
  squared_assert(v1510);
  squared_assume(v1510);
  struct StateT * v1290 = v1283->a;
  int v1291 = v1290->timer;
  int v1512 = v1291 + 1;
  v1290->timer = v1512;
  struct StateT * v1293 = v1283->b;
  int v1294 = v1293->timer;
  int v1514 = v1294 + 1;
  v1293->timer = v1514;
  struct StateT * v1296 = v1283->a;
  int * v1297 = v1296->cache_tags;
  int v1298 = v1297[0];
  int v1299 = v1297[1];
  int v1300 = v1297[4];
  int v1301 = v1297[5];
  int v1302 = v1296->timer;
  int v1521 = v1302 + ((100 ^ (((~(((v1300 ^ 4) | (-(v1300 ^ 4))) >> 31)) | (~(((v1301 ^ 4) | (-(v1301 ^ 4))) >> 31))) & 104)) ^ (((~(((v1298 ^ 4) | (-(v1298 ^ 4))) >> 31)) | (~(((v1299 ^ 4) | (-(v1299 ^ 4))) >> 31))) & (1 ^ (100 ^ (((~(((v1300 ^ 4) | (-(v1300 ^ 4))) >> 31)) | (~(((v1301 ^ 4) | (-(v1301 ^ 4))) >> 31))) & 104)))));
  v1296->timer = v1521;
  int * v1304 = v1296->cache_vals;
  bool v1522 = !(((~(((v1298 ^ 4) | (-(v1298 ^ 4))) >> 31)) | (~(((v1299 ^ 4) | (-(v1299 ^ 4))) >> 31))) == 0);
  int v1397;
  if (v1522) {
    int * v1305 = v1296->cache_age;
    int v1524 = (~(((v1299 ^ 4) | (-(v1299 ^ 4))) >> 31)) & 1;
    int v1306 = v1305[v1524];
    int v1307 = v1305[0];
    int v1525 = v1307 + ((int)((unsigned int)(v1307 - v1306) >> 31));
    v1305[0] = v1525;
    int * v1309 = v1296->cache_age;
    int v1310 = v1309[1];
    int v1527 = v1310 + ((int)((unsigned int)(v1310 - v1306) >> 31));
    v1309[1] = v1527;
    int * v1312 = v1296->cache_age;
    v1312[v1524] = 0;
    v1397 = v1524;
  } else {
    int * v1315 = v1296->cache_age;
    int v1316 = v1315[0];
    int * v1317 = v1296->cache_tags;
    int v1318 = v1317[0];
    int v1319 = v1315[1];
    int v1320 = v1317[1];
    bool v1531 = !(((~(((v1300 ^ 4) | (-(v1300 ^ 4))) >> 31)) | (~(((v1301 ^ 4) | (-(v1301 ^ 4))) >> 31))) == 0);
    int v1374;
    if (v1531) {
      int * v1321 = v1296->cache_age;
      int v1533 = 4 + ((~(((v1301 ^ 4) | (-(v1301 ^ 4))) >> 31)) & 1);
      int v1322 = v1321[v1533];
      int v1323 = v1321[4];
      int v1534 = v1323 + ((int)((unsigned int)(v1323 - v1322) >> 31));
      v1321[4] = v1534;
      int * v1325 = v1296->cache_age;
      int v1326 = v1325[5];
      int v1536 = v1326 + ((int)((unsigned int)(v1326 - v1322) >> 31));
      v1325[5] = v1536;
      int * v1328 = v1296->cache_age;
      v1328[v1533] = 0;
      v1374 = v1533;
    } else {
      int * v1331 = v1296->cache_age;
      int v1332 = v1331[4];
      int * v1333 = v1296->cache_tags;
      int v1334 = v1333[4];
      int v1335 = v1331[5];
      int v1336 = v1333[5];
      int * v1337 = v1296->cache_dirty;
      int v1541 = 4 + ((((v1332 + ((~(((v1334 ^ -1) | (-(v1334 ^ -1))) >> 31)) & 2)) - (v1335 + ((~(((v1336 ^ -1) | (-(v1336 ^ -1))) >> 31)) & 2))) >> 31) & 1);
      int v1338 = v1337[v1541];
      bool v1542 = !(v1338 == 0);
      if (v1542) {
        int * v1339 = v1296->cache_tags;
        int v1340 = v1339[v1541];
        int * v1341 = v1296->cache_vals;
        int v1545 = (4 + ((((v1332 + ((~(((v1334 ^ -1) | (-(v1334 ^ -1))) >> 31)) & 2)) - (v1335 + ((~(((v1336 ^ -1) | (-(v1336 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
        int v1342 = v1341[v1545];
        int v1546 = ((4 + ((((v1332 + ((~(((v1334 ^ -1) | (-(v1334 ^ -1))) >> 31)) & 2)) - (v1335 + ((~(((v1336 ^ -1) | (-(v1336 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
        int v1343 = v1341[v1546];
        int * v1344 = v1296->mem;
        int v1548 = v1340 * 2;
        v1344[v1548] = v1342;
        int * v1346 = v1296->mem;
        int v1551 = (v1340 * 2) + 1;
        v1346[v1551] = v1343;
        ;
      } else {
        ;
      }
      int * v1351 = v1296->mem;
      int v1352 = v1351[8];
      int v1353 = v1351[9];
      int * v1354 = v1296->cache_vals;
      int v1559 = (4 + ((((v1332 + ((~(((v1334 ^ -1) | (-(v1334 ^ -1))) >> 31)) & 2)) - (v1335 + ((~(((v1336 ^ -1) | (-(v1336 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
      v1354[v1559] = v1352;
      int * v1356 = v1296->cache_vals;
      int v1562 = ((4 + ((((v1332 + ((~(((v1334 ^ -1) | (-(v1334 ^ -1))) >> 31)) & 2)) - (v1335 + ((~(((v1336 ^ -1) | (-(v1336 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
      v1356[v1562] = v1353;
      int * v1358 = v1296->cache_tags;
      v1358[v1541] = 4;
      int * v1360 = v1296->cache_dirty;
      v1360[v1541] = 0;
      int * v1362 = v1296->cache_age;
      v1362[v1541] = 1;
      int * v1364 = v1296->cache_age;
      int v1365 = v1364[v1541];
      int v1366 = v1364[4];
      int v1568 = v1366 + ((int)((unsigned int)(v1366 - v1365) >> 31));
      v1364[4] = v1568;
      int * v1368 = v1296->cache_age;
      int v1369 = v1368[5];
      int v1570 = v1369 + ((int)((unsigned int)(v1369 - v1365) >> 31));
      v1368[5] = v1570;
      int * v1371 = v1296->cache_age;
      v1371[v1541] = 0;
      v1374 = v1541;
    }
    int * v1375 = v1296->cache_vals;
    int v1573 = v1374 * 2;
    int v1376 = v1375[v1573];
    int v1574 = (v1374 * 2) + 1;
    int v1377 = v1375[v1574];
    int v1575 = ((((v1316 + ((~(((v1318 ^ -1) | (-(v1318 ^ -1))) >> 31)) & 2)) - (v1319 + ((~(((v1320 ^ -1) | (-(v1320 ^ -1))) >> 31)) & 2))) >> 31) & 1) * 2;
    v1375[v1575] = v1376;
    int * v1379 = v1296->cache_vals;
    int v1578 = (((((v1316 + ((~(((v1318 ^ -1) | (-(v1318 ^ -1))) >> 31)) & 2)) - (v1319 + ((~(((v1320 ^ -1) | (-(v1320 ^ -1))) >> 31)) & 2))) >> 31) & 1) * 2) + 1;
    v1379[v1578] = v1377;
    int * v1381 = v1296->cache_tags;
    int v1581 = (((v1316 + ((~(((v1318 ^ -1) | (-(v1318 ^ -1))) >> 31)) & 2)) - (v1319 + ((~(((v1320 ^ -1) | (-(v1320 ^ -1))) >> 31)) & 2))) >> 31) & 1;
    v1381[v1581] = 4;
    int * v1383 = v1296->cache_dirty;
    v1383[v1581] = 0;
    int * v1385 = v1296->cache_age;
    v1385[v1581] = 1;
    int * v1387 = v1296->cache_age;
    int v1388 = v1387[v1581];
    int v1389 = v1387[0];
    int v1585 = v1389 + ((int)((unsigned int)(v1389 - v1388) >> 31));
    v1387[0] = v1585;
    int * v1391 = v1296->cache_age;
    int v1392 = v1391[1];
    int v1587 = v1392 + ((int)((unsigned int)(v1392 - v1388) >> 31));
    v1391[1] = v1587;
    int * v1394 = v1296->cache_age;
    v1394[v1581] = 0;
    v1397 = v1581;
  }
  int v1590 = (v1397 * 2) + 1;
  int v1398 = v1304[v1590];
  int * v1399 = v1296->regs;
  v1399[8] = v1398;
  struct StateT * v1401 = v1283->b;
  int * v1402 = v1401->cache_tags;
  int v1403 = v1402[0];
  int v1404 = v1402[1];
  int v1405 = v1402[4];
  int v1406 = v1402[5];
  int v1407 = v1401->timer;
  int v1596 = v1407 + ((100 ^ (((~(((v1405 ^ 4) | (-(v1405 ^ 4))) >> 31)) | (~(((v1406 ^ 4) | (-(v1406 ^ 4))) >> 31))) & 104)) ^ (((~(((v1403 ^ 4) | (-(v1403 ^ 4))) >> 31)) | (~(((v1404 ^ 4) | (-(v1404 ^ 4))) >> 31))) & (1 ^ (100 ^ (((~(((v1405 ^ 4) | (-(v1405 ^ 4))) >> 31)) | (~(((v1406 ^ 4) | (-(v1406 ^ 4))) >> 31))) & 104)))));
  v1401->timer = v1596;
  int * v1409 = v1401->cache_vals;
  bool v1597 = !(((~(((v1403 ^ 4) | (-(v1403 ^ 4))) >> 31)) | (~(((v1404 ^ 4) | (-(v1404 ^ 4))) >> 31))) == 0);
  int v1502;
  if (v1597) {
    int * v1410 = v1401->cache_age;
    int v1599 = (~(((v1404 ^ 4) | (-(v1404 ^ 4))) >> 31)) & 1;
    int v1411 = v1410[v1599];
    int v1412 = v1410[0];
    int v1600 = v1412 + ((int)((unsigned int)(v1412 - v1411) >> 31));
    v1410[0] = v1600;
    int * v1414 = v1401->cache_age;
    int v1415 = v1414[1];
    int v1602 = v1415 + ((int)((unsigned int)(v1415 - v1411) >> 31));
    v1414[1] = v1602;
    int * v1417 = v1401->cache_age;
    v1417[v1599] = 0;
    v1502 = v1599;
  } else {
    int * v1420 = v1401->cache_age;
    int v1421 = v1420[0];
    int * v1422 = v1401->cache_tags;
    int v1423 = v1422[0];
    int v1424 = v1420[1];
    int v1425 = v1422[1];
    bool v1606 = !(((~(((v1405 ^ 4) | (-(v1405 ^ 4))) >> 31)) | (~(((v1406 ^ 4) | (-(v1406 ^ 4))) >> 31))) == 0);
    int v1479;
    if (v1606) {
      int * v1426 = v1401->cache_age;
      int v1608 = 4 + ((~(((v1406 ^ 4) | (-(v1406 ^ 4))) >> 31)) & 1);
      int v1427 = v1426[v1608];
      int v1428 = v1426[4];
      int v1609 = v1428 + ((int)((unsigned int)(v1428 - v1427) >> 31));
      v1426[4] = v1609;
      int * v1430 = v1401->cache_age;
      int v1431 = v1430[5];
      int v1611 = v1431 + ((int)((unsigned int)(v1431 - v1427) >> 31));
      v1430[5] = v1611;
      int * v1433 = v1401->cache_age;
      v1433[v1608] = 0;
      v1479 = v1608;
    } else {
      int * v1436 = v1401->cache_age;
      int v1437 = v1436[4];
      int * v1438 = v1401->cache_tags;
      int v1439 = v1438[4];
      int v1440 = v1436[5];
      int v1441 = v1438[5];
      int * v1442 = v1401->cache_dirty;
      int v1616 = 4 + ((((v1437 + ((~(((v1439 ^ -1) | (-(v1439 ^ -1))) >> 31)) & 2)) - (v1440 + ((~(((v1441 ^ -1) | (-(v1441 ^ -1))) >> 31)) & 2))) >> 31) & 1);
      int v1443 = v1442[v1616];
      bool v1617 = !(v1443 == 0);
      if (v1617) {
        int * v1444 = v1401->cache_tags;
        int v1445 = v1444[v1616];
        int * v1446 = v1401->cache_vals;
        int v1620 = (4 + ((((v1437 + ((~(((v1439 ^ -1) | (-(v1439 ^ -1))) >> 31)) & 2)) - (v1440 + ((~(((v1441 ^ -1) | (-(v1441 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
        int v1447 = v1446[v1620];
        int v1621 = ((4 + ((((v1437 + ((~(((v1439 ^ -1) | (-(v1439 ^ -1))) >> 31)) & 2)) - (v1440 + ((~(((v1441 ^ -1) | (-(v1441 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
        int v1448 = v1446[v1621];
        int * v1449 = v1401->mem;
        int v1623 = v1445 * 2;
        v1449[v1623] = v1447;
        int * v1451 = v1401->mem;
        int v1626 = (v1445 * 2) + 1;
        v1451[v1626] = v1448;
        ;
      } else {
        ;
      }
      int * v1456 = v1401->mem;
      int v1457 = v1456[8];
      int v1458 = v1456[9];
      int * v1459 = v1401->cache_vals;
      int v1633 = (4 + ((((v1437 + ((~(((v1439 ^ -1) | (-(v1439 ^ -1))) >> 31)) & 2)) - (v1440 + ((~(((v1441 ^ -1) | (-(v1441 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
      v1459[v1633] = v1457;
      int * v1461 = v1401->cache_vals;
      int v1636 = ((4 + ((((v1437 + ((~(((v1439 ^ -1) | (-(v1439 ^ -1))) >> 31)) & 2)) - (v1440 + ((~(((v1441 ^ -1) | (-(v1441 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
      v1461[v1636] = v1458;
      int * v1463 = v1401->cache_tags;
      v1463[v1616] = 4;
      int * v1465 = v1401->cache_dirty;
      v1465[v1616] = 0;
      int * v1467 = v1401->cache_age;
      v1467[v1616] = 1;
      int * v1469 = v1401->cache_age;
      int v1470 = v1469[v1616];
      int v1471 = v1469[4];
      int v1642 = v1471 + ((int)((unsigned int)(v1471 - v1470) >> 31));
      v1469[4] = v1642;
      int * v1473 = v1401->cache_age;
      int v1474 = v1473[5];
      int v1644 = v1474 + ((int)((unsigned int)(v1474 - v1470) >> 31));
      v1473[5] = v1644;
      int * v1476 = v1401->cache_age;
      v1476[v1616] = 0;
      v1479 = v1616;
    }
    int * v1480 = v1401->cache_vals;
    int v1647 = v1479 * 2;
    int v1481 = v1480[v1647];
    int v1648 = (v1479 * 2) + 1;
    int v1482 = v1480[v1648];
    int v1649 = ((((v1421 + ((~(((v1423 ^ -1) | (-(v1423 ^ -1))) >> 31)) & 2)) - (v1424 + ((~(((v1425 ^ -1) | (-(v1425 ^ -1))) >> 31)) & 2))) >> 31) & 1) * 2;
    v1480[v1649] = v1481;
    int * v1484 = v1401->cache_vals;
    int v1652 = (((((v1421 + ((~(((v1423 ^ -1) | (-(v1423 ^ -1))) >> 31)) & 2)) - (v1424 + ((~(((v1425 ^ -1) | (-(v1425 ^ -1))) >> 31)) & 2))) >> 31) & 1) * 2) + 1;
    v1484[v1652] = v1482;
    int * v1486 = v1401->cache_tags;
    int v1655 = (((v1421 + ((~(((v1423 ^ -1) | (-(v1423 ^ -1))) >> 31)) & 2)) - (v1424 + ((~(((v1425 ^ -1) | (-(v1425 ^ -1))) >> 31)) & 2))) >> 31) & 1;
    v1486[v1655] = 4;
    int * v1488 = v1401->cache_dirty;
    v1488[v1655] = 0;
    int * v1490 = v1401->cache_age;
    v1490[v1655] = 1;
    int * v1492 = v1401->cache_age;
    int v1493 = v1492[v1655];
    int v1494 = v1492[0];
    int v1659 = v1494 + ((int)((unsigned int)(v1494 - v1493) >> 31));
    v1492[0] = v1659;
    int * v1496 = v1401->cache_age;
    int v1497 = v1496[1];
    int v1661 = v1497 + ((int)((unsigned int)(v1497 - v1493) >> 31));
    v1496[1] = v1661;
    int * v1499 = v1401->cache_age;
    v1499[v1655] = 0;
    v1502 = v1655;
  }
  int v1664 = (v1502 * 2) + 1;
  int v1503 = v1409[v1664];
  int * v1504 = v1401->regs;
  v1504[8] = v1503;
  struct StateT2 * v1506 = slot_5(v1283);
  return v1506;
}

struct StateT2 * slot_2(struct StateT2 * v82) {
  struct StateT * v83 = v82->a;
  int v84 = v83->timer;
  struct StateT * v85 = v82->b;
  int v86 = v85->timer;
  bool v431 = v84 == v86;
  squared_assert(v431);
  squared_assume(v431);
  struct StateT * v89 = v82->a;
  int v90 = v89->timer;
  int v433 = v90 + 1;
  v89->timer = v433;
  struct StateT * v92 = v82->b;
  int v93 = v92->timer;
  int v435 = v93 + 1;
  v92->timer = v435;
  struct StateT * v95 = v82->a;
  int * v96 = v95->regs;
  int v97 = v96[6];
  int * v98 = v95->cache_tags;
  int v99 = v98[0];
  int v100 = v98[1];
  int v101 = v98[4];
  int v102 = v98[5];
  int v103 = v95->timer;
  int v444 = v103 + ((100 ^ (((~(((v101 ^ 4) | (-(v101 ^ 4))) >> 31)) | (~(((v102 ^ 4) | (-(v102 ^ 4))) >> 31))) & 104)) ^ (((~(((v99 ^ 4) | (-(v99 ^ 4))) >> 31)) | (~(((v100 ^ 4) | (-(v100 ^ 4))) >> 31))) & (1 ^ (100 ^ (((~(((v101 ^ 4) | (-(v101 ^ 4))) >> 31)) | (~(((v102 ^ 4) | (-(v102 ^ 4))) >> 31))) & 104)))));
  v95->timer = v444;
  bool v445 = !(((~(((v99 ^ 4) | (-(v99 ^ 4))) >> 31)) | (~(((v100 ^ 4) | (-(v100 ^ 4))) >> 31))) == 0);
  int v197;
  if (v445) {
    int * v105 = v95->cache_age;
    int v447 = (~(((v100 ^ 4) | (-(v100 ^ 4))) >> 31)) & 1;
    int v106 = v105[v447];
    int v107 = v105[0];
    int v448 = v107 + ((int)((unsigned int)(v107 - v106) >> 31));
    v105[0] = v448;
    int * v109 = v95->cache_age;
    int v110 = v109[1];
    int v450 = v110 + ((int)((unsigned int)(v110 - v106) >> 31));
    v109[1] = v450;
    int * v112 = v95->cache_age;
    v112[v447] = 0;
    v197 = v447;
  } else {
    int * v115 = v95->cache_age;
    int v116 = v115[0];
    int * v117 = v95->cache_tags;
    int v118 = v117[0];
    int v119 = v115[1];
    int v120 = v117[1];
    bool v454 = !(((~(((v101 ^ 4) | (-(v101 ^ 4))) >> 31)) | (~(((v102 ^ 4) | (-(v102 ^ 4))) >> 31))) == 0);
    int v174;
    if (v454) {
      int * v121 = v95->cache_age;
      int v456 = 4 + ((~(((v102 ^ 4) | (-(v102 ^ 4))) >> 31)) & 1);
      int v122 = v121[v456];
      int v123 = v121[4];
      int v457 = v123 + ((int)((unsigned int)(v123 - v122) >> 31));
      v121[4] = v457;
      int * v125 = v95->cache_age;
      int v126 = v125[5];
      int v459 = v126 + ((int)((unsigned int)(v126 - v122) >> 31));
      v125[5] = v459;
      int * v128 = v95->cache_age;
      v128[v456] = 0;
      v174 = v456;
    } else {
      int * v131 = v95->cache_age;
      int v132 = v131[4];
      int * v133 = v95->cache_tags;
      int v134 = v133[4];
      int v135 = v131[5];
      int v136 = v133[5];
      int * v137 = v95->cache_dirty;
      int v464 = 4 + ((((v132 + ((~(((v134 ^ -1) | (-(v134 ^ -1))) >> 31)) & 2)) - (v135 + ((~(((v136 ^ -1) | (-(v136 ^ -1))) >> 31)) & 2))) >> 31) & 1);
      int v138 = v137[v464];
      bool v465 = !(v138 == 0);
      if (v465) {
        int * v139 = v95->cache_tags;
        int v140 = v139[v464];
        int * v141 = v95->cache_vals;
        int v468 = (4 + ((((v132 + ((~(((v134 ^ -1) | (-(v134 ^ -1))) >> 31)) & 2)) - (v135 + ((~(((v136 ^ -1) | (-(v136 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
        int v142 = v141[v468];
        int v469 = ((4 + ((((v132 + ((~(((v134 ^ -1) | (-(v134 ^ -1))) >> 31)) & 2)) - (v135 + ((~(((v136 ^ -1) | (-(v136 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
        int v143 = v141[v469];
        int * v144 = v95->mem;
        int v471 = v140 * 2;
        v144[v471] = v142;
        int * v146 = v95->mem;
        int v474 = (v140 * 2) + 1;
        v146[v474] = v143;
        ;
      } else {
        ;
      }
      int * v151 = v95->mem;
      int v152 = v151[8];
      int v153 = v151[9];
      int * v154 = v95->cache_vals;
      int v482 = (4 + ((((v132 + ((~(((v134 ^ -1) | (-(v134 ^ -1))) >> 31)) & 2)) - (v135 + ((~(((v136 ^ -1) | (-(v136 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
      v154[v482] = v152;
      int * v156 = v95->cache_vals;
      int v485 = ((4 + ((((v132 + ((~(((v134 ^ -1) | (-(v134 ^ -1))) >> 31)) & 2)) - (v135 + ((~(((v136 ^ -1) | (-(v136 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
      v156[v485] = v153;
      int * v158 = v95->cache_tags;
      v158[v464] = 4;
      int * v160 = v95->cache_dirty;
      v160[v464] = 0;
      int * v162 = v95->cache_age;
      v162[v464] = 1;
      int * v164 = v95->cache_age;
      int v165 = v164[v464];
      int v166 = v164[4];
      int v491 = v166 + ((int)((unsigned int)(v166 - v165) >> 31));
      v164[4] = v491;
      int * v168 = v95->cache_age;
      int v169 = v168[5];
      int v493 = v169 + ((int)((unsigned int)(v169 - v165) >> 31));
      v168[5] = v493;
      int * v171 = v95->cache_age;
      v171[v464] = 0;
      v174 = v464;
    }
    int * v175 = v95->cache_vals;
    int v496 = v174 * 2;
    int v176 = v175[v496];
    int v497 = (v174 * 2) + 1;
    int v177 = v175[v497];
    int v498 = ((((v116 + ((~(((v118 ^ -1) | (-(v118 ^ -1))) >> 31)) & 2)) - (v119 + ((~(((v120 ^ -1) | (-(v120 ^ -1))) >> 31)) & 2))) >> 31) & 1) * 2;
    v175[v498] = v176;
    int * v179 = v95->cache_vals;
    int v501 = (((((v116 + ((~(((v118 ^ -1) | (-(v118 ^ -1))) >> 31)) & 2)) - (v119 + ((~(((v120 ^ -1) | (-(v120 ^ -1))) >> 31)) & 2))) >> 31) & 1) * 2) + 1;
    v179[v501] = v177;
    int * v181 = v95->cache_tags;
    int v504 = (((v116 + ((~(((v118 ^ -1) | (-(v118 ^ -1))) >> 31)) & 2)) - (v119 + ((~(((v120 ^ -1) | (-(v120 ^ -1))) >> 31)) & 2))) >> 31) & 1;
    v181[v504] = 4;
    int * v183 = v95->cache_dirty;
    v183[v504] = 0;
    int * v185 = v95->cache_age;
    v185[v504] = 1;
    int * v187 = v95->cache_age;
    int v188 = v187[v504];
    int v189 = v187[0];
    int v508 = v189 + ((int)((unsigned int)(v189 - v188) >> 31));
    v187[0] = v508;
    int * v191 = v95->cache_age;
    int v192 = v191[1];
    int v510 = v192 + ((int)((unsigned int)(v192 - v188) >> 31));
    v191[1] = v510;
    int * v194 = v95->cache_age;
    v194[v504] = 0;
    v197 = v504;
  }
  int * v198 = v95->cache_vals;
  int v513 = (v197 * 2) + 1;
  v198[v513] = v97;
  int * v200 = v95->cache_tags;
  int v201 = v200[4];
  int v202 = v200[5];
  bool v516 = !(((~(((v201 ^ 4) | (-(v201 ^ 4))) >> 31)) | (~(((v202 ^ 4) | (-(v202 ^ 4))) >> 31))) == 0);
  int v256;
  if (v516) {
    int * v203 = v95->cache_age;
    int v518 = 4 + ((~(((v202 ^ 4) | (-(v202 ^ 4))) >> 31)) & 1);
    int v204 = v203[v518];
    int v205 = v203[4];
    int v519 = v205 + ((int)((unsigned int)(v205 - v204) >> 31));
    v203[4] = v519;
    int * v207 = v95->cache_age;
    int v208 = v207[5];
    int v521 = v208 + ((int)((unsigned int)(v208 - v204) >> 31));
    v207[5] = v521;
    int * v210 = v95->cache_age;
    v210[v518] = 0;
    v256 = v518;
  } else {
    int * v213 = v95->cache_age;
    int v214 = v213[4];
    int * v215 = v95->cache_tags;
    int v216 = v215[4];
    int v217 = v213[5];
    int v218 = v215[5];
    int * v219 = v95->cache_dirty;
    int v526 = 4 + ((((v214 + ((~(((v216 ^ -1) | (-(v216 ^ -1))) >> 31)) & 2)) - (v217 + ((~(((v218 ^ -1) | (-(v218 ^ -1))) >> 31)) & 2))) >> 31) & 1);
    int v220 = v219[v526];
    bool v527 = !(v220 == 0);
    if (v527) {
      int * v221 = v95->cache_tags;
      int v222 = v221[v526];
      int * v223 = v95->cache_vals;
      int v530 = (4 + ((((v214 + ((~(((v216 ^ -1) | (-(v216 ^ -1))) >> 31)) & 2)) - (v217 + ((~(((v218 ^ -1) | (-(v218 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
      int v224 = v223[v530];
      int v531 = ((4 + ((((v214 + ((~(((v216 ^ -1) | (-(v216 ^ -1))) >> 31)) & 2)) - (v217 + ((~(((v218 ^ -1) | (-(v218 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
      int v225 = v223[v531];
      int * v226 = v95->mem;
      int v533 = v222 * 2;
      v226[v533] = v224;
      int * v228 = v95->mem;
      int v536 = (v222 * 2) + 1;
      v228[v536] = v225;
      ;
    } else {
      ;
    }
    int * v233 = v95->mem;
    int v234 = v233[8];
    int v235 = v233[9];
    int * v236 = v95->cache_vals;
    int v544 = (4 + ((((v214 + ((~(((v216 ^ -1) | (-(v216 ^ -1))) >> 31)) & 2)) - (v217 + ((~(((v218 ^ -1) | (-(v218 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
    v236[v544] = v234;
    int * v238 = v95->cache_vals;
    int v547 = ((4 + ((((v214 + ((~(((v216 ^ -1) | (-(v216 ^ -1))) >> 31)) & 2)) - (v217 + ((~(((v218 ^ -1) | (-(v218 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
    v238[v547] = v235;
    int * v240 = v95->cache_tags;
    v240[v526] = 4;
    int * v242 = v95->cache_dirty;
    v242[v526] = 0;
    int * v244 = v95->cache_age;
    v244[v526] = 1;
    int * v246 = v95->cache_age;
    int v247 = v246[v526];
    int v248 = v246[4];
    int v553 = v248 + ((int)((unsigned int)(v248 - v247) >> 31));
    v246[4] = v553;
    int * v250 = v95->cache_age;
    int v251 = v250[5];
    int v555 = v251 + ((int)((unsigned int)(v251 - v247) >> 31));
    v250[5] = v555;
    int * v253 = v95->cache_age;
    v253[v526] = 0;
    v256 = v526;
  }
  int * v257 = v95->cache_vals;
  int v558 = (v256 * 2) + 1;
  v257[v558] = v97;
  int * v259 = v95->cache_dirty;
  v259[v256] = 1;
  struct StateT * v261 = v82->b;
  int * v262 = v261->regs;
  int v263 = v262[6];
  int * v264 = v261->cache_tags;
  int v265 = v264[0];
  int v266 = v264[1];
  int v267 = v264[4];
  int v268 = v264[5];
  int v269 = v261->timer;
  int v564 = v269 + ((100 ^ (((~(((v267 ^ 4) | (-(v267 ^ 4))) >> 31)) | (~(((v268 ^ 4) | (-(v268 ^ 4))) >> 31))) & 104)) ^ (((~(((v265 ^ 4) | (-(v265 ^ 4))) >> 31)) | (~(((v266 ^ 4) | (-(v266 ^ 4))) >> 31))) & (1 ^ (100 ^ (((~(((v267 ^ 4) | (-(v267 ^ 4))) >> 31)) | (~(((v268 ^ 4) | (-(v268 ^ 4))) >> 31))) & 104)))));
  v261->timer = v564;
  bool v565 = !(((~(((v265 ^ 4) | (-(v265 ^ 4))) >> 31)) | (~(((v266 ^ 4) | (-(v266 ^ 4))) >> 31))) == 0);
  int v363;
  if (v565) {
    int * v271 = v261->cache_age;
    int v567 = (~(((v266 ^ 4) | (-(v266 ^ 4))) >> 31)) & 1;
    int v272 = v271[v567];
    int v273 = v271[0];
    int v568 = v273 + ((int)((unsigned int)(v273 - v272) >> 31));
    v271[0] = v568;
    int * v275 = v261->cache_age;
    int v276 = v275[1];
    int v570 = v276 + ((int)((unsigned int)(v276 - v272) >> 31));
    v275[1] = v570;
    int * v278 = v261->cache_age;
    v278[v567] = 0;
    v363 = v567;
  } else {
    int * v281 = v261->cache_age;
    int v282 = v281[0];
    int * v283 = v261->cache_tags;
    int v284 = v283[0];
    int v285 = v281[1];
    int v286 = v283[1];
    bool v574 = !(((~(((v267 ^ 4) | (-(v267 ^ 4))) >> 31)) | (~(((v268 ^ 4) | (-(v268 ^ 4))) >> 31))) == 0);
    int v340;
    if (v574) {
      int * v287 = v261->cache_age;
      int v576 = 4 + ((~(((v268 ^ 4) | (-(v268 ^ 4))) >> 31)) & 1);
      int v288 = v287[v576];
      int v289 = v287[4];
      int v577 = v289 + ((int)((unsigned int)(v289 - v288) >> 31));
      v287[4] = v577;
      int * v291 = v261->cache_age;
      int v292 = v291[5];
      int v579 = v292 + ((int)((unsigned int)(v292 - v288) >> 31));
      v291[5] = v579;
      int * v294 = v261->cache_age;
      v294[v576] = 0;
      v340 = v576;
    } else {
      int * v297 = v261->cache_age;
      int v298 = v297[4];
      int * v299 = v261->cache_tags;
      int v300 = v299[4];
      int v301 = v297[5];
      int v302 = v299[5];
      int * v303 = v261->cache_dirty;
      int v584 = 4 + ((((v298 + ((~(((v300 ^ -1) | (-(v300 ^ -1))) >> 31)) & 2)) - (v301 + ((~(((v302 ^ -1) | (-(v302 ^ -1))) >> 31)) & 2))) >> 31) & 1);
      int v304 = v303[v584];
      bool v585 = !(v304 == 0);
      if (v585) {
        int * v305 = v261->cache_tags;
        int v306 = v305[v584];
        int * v307 = v261->cache_vals;
        int v588 = (4 + ((((v298 + ((~(((v300 ^ -1) | (-(v300 ^ -1))) >> 31)) & 2)) - (v301 + ((~(((v302 ^ -1) | (-(v302 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
        int v308 = v307[v588];
        int v589 = ((4 + ((((v298 + ((~(((v300 ^ -1) | (-(v300 ^ -1))) >> 31)) & 2)) - (v301 + ((~(((v302 ^ -1) | (-(v302 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
        int v309 = v307[v589];
        int * v310 = v261->mem;
        int v591 = v306 * 2;
        v310[v591] = v308;
        int * v312 = v261->mem;
        int v594 = (v306 * 2) + 1;
        v312[v594] = v309;
        ;
      } else {
        ;
      }
      int * v317 = v261->mem;
      int v318 = v317[8];
      int v319 = v317[9];
      int * v320 = v261->cache_vals;
      int v602 = (4 + ((((v298 + ((~(((v300 ^ -1) | (-(v300 ^ -1))) >> 31)) & 2)) - (v301 + ((~(((v302 ^ -1) | (-(v302 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
      v320[v602] = v318;
      int * v322 = v261->cache_vals;
      int v605 = ((4 + ((((v298 + ((~(((v300 ^ -1) | (-(v300 ^ -1))) >> 31)) & 2)) - (v301 + ((~(((v302 ^ -1) | (-(v302 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
      v322[v605] = v319;
      int * v324 = v261->cache_tags;
      v324[v584] = 4;
      int * v326 = v261->cache_dirty;
      v326[v584] = 0;
      int * v328 = v261->cache_age;
      v328[v584] = 1;
      int * v330 = v261->cache_age;
      int v331 = v330[v584];
      int v332 = v330[4];
      int v611 = v332 + ((int)((unsigned int)(v332 - v331) >> 31));
      v330[4] = v611;
      int * v334 = v261->cache_age;
      int v335 = v334[5];
      int v613 = v335 + ((int)((unsigned int)(v335 - v331) >> 31));
      v334[5] = v613;
      int * v337 = v261->cache_age;
      v337[v584] = 0;
      v340 = v584;
    }
    int * v341 = v261->cache_vals;
    int v616 = v340 * 2;
    int v342 = v341[v616];
    int v617 = (v340 * 2) + 1;
    int v343 = v341[v617];
    int v618 = ((((v282 + ((~(((v284 ^ -1) | (-(v284 ^ -1))) >> 31)) & 2)) - (v285 + ((~(((v286 ^ -1) | (-(v286 ^ -1))) >> 31)) & 2))) >> 31) & 1) * 2;
    v341[v618] = v342;
    int * v345 = v261->cache_vals;
    int v621 = (((((v282 + ((~(((v284 ^ -1) | (-(v284 ^ -1))) >> 31)) & 2)) - (v285 + ((~(((v286 ^ -1) | (-(v286 ^ -1))) >> 31)) & 2))) >> 31) & 1) * 2) + 1;
    v345[v621] = v343;
    int * v347 = v261->cache_tags;
    int v624 = (((v282 + ((~(((v284 ^ -1) | (-(v284 ^ -1))) >> 31)) & 2)) - (v285 + ((~(((v286 ^ -1) | (-(v286 ^ -1))) >> 31)) & 2))) >> 31) & 1;
    v347[v624] = 4;
    int * v349 = v261->cache_dirty;
    v349[v624] = 0;
    int * v351 = v261->cache_age;
    v351[v624] = 1;
    int * v353 = v261->cache_age;
    int v354 = v353[v624];
    int v355 = v353[0];
    int v628 = v355 + ((int)((unsigned int)(v355 - v354) >> 31));
    v353[0] = v628;
    int * v357 = v261->cache_age;
    int v358 = v357[1];
    int v630 = v358 + ((int)((unsigned int)(v358 - v354) >> 31));
    v357[1] = v630;
    int * v360 = v261->cache_age;
    v360[v624] = 0;
    v363 = v624;
  }
  int * v364 = v261->cache_vals;
  int v633 = (v363 * 2) + 1;
  v364[v633] = v263;
  int * v366 = v261->cache_tags;
  int v367 = v366[4];
  int v368 = v366[5];
  bool v636 = !(((~(((v367 ^ 4) | (-(v367 ^ 4))) >> 31)) | (~(((v368 ^ 4) | (-(v368 ^ 4))) >> 31))) == 0);
  int v422;
  if (v636) {
    int * v369 = v261->cache_age;
    int v638 = 4 + ((~(((v368 ^ 4) | (-(v368 ^ 4))) >> 31)) & 1);
    int v370 = v369[v638];
    int v371 = v369[4];
    int v639 = v371 + ((int)((unsigned int)(v371 - v370) >> 31));
    v369[4] = v639;
    int * v373 = v261->cache_age;
    int v374 = v373[5];
    int v641 = v374 + ((int)((unsigned int)(v374 - v370) >> 31));
    v373[5] = v641;
    int * v376 = v261->cache_age;
    v376[v638] = 0;
    v422 = v638;
  } else {
    int * v379 = v261->cache_age;
    int v380 = v379[4];
    int * v381 = v261->cache_tags;
    int v382 = v381[4];
    int v383 = v379[5];
    int v384 = v381[5];
    int * v385 = v261->cache_dirty;
    int v646 = 4 + ((((v380 + ((~(((v382 ^ -1) | (-(v382 ^ -1))) >> 31)) & 2)) - (v383 + ((~(((v384 ^ -1) | (-(v384 ^ -1))) >> 31)) & 2))) >> 31) & 1);
    int v386 = v385[v646];
    bool v647 = !(v386 == 0);
    if (v647) {
      int * v387 = v261->cache_tags;
      int v388 = v387[v646];
      int * v389 = v261->cache_vals;
      int v650 = (4 + ((((v380 + ((~(((v382 ^ -1) | (-(v382 ^ -1))) >> 31)) & 2)) - (v383 + ((~(((v384 ^ -1) | (-(v384 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
      int v390 = v389[v650];
      int v651 = ((4 + ((((v380 + ((~(((v382 ^ -1) | (-(v382 ^ -1))) >> 31)) & 2)) - (v383 + ((~(((v384 ^ -1) | (-(v384 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
      int v391 = v389[v651];
      int * v392 = v261->mem;
      int v653 = v388 * 2;
      v392[v653] = v390;
      int * v394 = v261->mem;
      int v656 = (v388 * 2) + 1;
      v394[v656] = v391;
      ;
    } else {
      ;
    }
    int * v399 = v261->mem;
    int v400 = v399[8];
    int v401 = v399[9];
    int * v402 = v261->cache_vals;
    int v664 = (4 + ((((v380 + ((~(((v382 ^ -1) | (-(v382 ^ -1))) >> 31)) & 2)) - (v383 + ((~(((v384 ^ -1) | (-(v384 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
    v402[v664] = v400;
    int * v404 = v261->cache_vals;
    int v667 = ((4 + ((((v380 + ((~(((v382 ^ -1) | (-(v382 ^ -1))) >> 31)) & 2)) - (v383 + ((~(((v384 ^ -1) | (-(v384 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
    v404[v667] = v401;
    int * v406 = v261->cache_tags;
    v406[v646] = 4;
    int * v408 = v261->cache_dirty;
    v408[v646] = 0;
    int * v410 = v261->cache_age;
    v410[v646] = 1;
    int * v412 = v261->cache_age;
    int v413 = v412[v646];
    int v414 = v412[4];
    int v673 = v414 + ((int)((unsigned int)(v414 - v413) >> 31));
    v412[4] = v673;
    int * v416 = v261->cache_age;
    int v417 = v416[5];
    int v675 = v417 + ((int)((unsigned int)(v417 - v413) >> 31));
    v416[5] = v675;
    int * v419 = v261->cache_age;
    v419[v646] = 0;
    v422 = v646;
  }
  int * v423 = v261->cache_vals;
  int v678 = (v422 * 2) + 1;
  v423[v678] = v263;
  int * v425 = v261->cache_dirty;
  v425[v422] = 1;
  struct StateT2 * v427 = slot_3(v82);
  return v427;
}

struct StateT2 * slot_3(struct StateT2 * v683) {
  struct StateT * v684 = v683->a;
  int v685 = v684->timer;
  struct StateT * v686 = v683->b;
  int v687 = v686->timer;
  bool v1032 = v685 == v687;
  squared_assert(v1032);
  squared_assume(v1032);
  struct StateT * v690 = v683->a;
  int v691 = v690->timer;
  int v1034 = v691 + 1;
  v690->timer = v1034;
  struct StateT * v693 = v683->b;
  int v694 = v693->timer;
  int v1036 = v694 + 1;
  v693->timer = v1036;
  struct StateT * v696 = v683->a;
  int * v697 = v696->regs;
  int v698 = v697[5];
  int * v699 = v696->cache_tags;
  int v700 = v699[0];
  int v701 = v699[1];
  int v702 = v699[4];
  int v703 = v699[5];
  int v704 = v696->timer;
  int v1044 = v704 + ((100 ^ (((~(((v702 ^ 4) | (-(v702 ^ 4))) >> 31)) | (~(((v703 ^ 4) | (-(v703 ^ 4))) >> 31))) & 104)) ^ (((~(((v700 ^ 4) | (-(v700 ^ 4))) >> 31)) | (~(((v701 ^ 4) | (-(v701 ^ 4))) >> 31))) & (1 ^ (100 ^ (((~(((v702 ^ 4) | (-(v702 ^ 4))) >> 31)) | (~(((v703 ^ 4) | (-(v703 ^ 4))) >> 31))) & 104)))));
  v696->timer = v1044;
  bool v1045 = !(((~(((v700 ^ 4) | (-(v700 ^ 4))) >> 31)) | (~(((v701 ^ 4) | (-(v701 ^ 4))) >> 31))) == 0);
  int v798;
  if (v1045) {
    int * v706 = v696->cache_age;
    int v1047 = (~(((v701 ^ 4) | (-(v701 ^ 4))) >> 31)) & 1;
    int v707 = v706[v1047];
    int v708 = v706[0];
    int v1048 = v708 + ((int)((unsigned int)(v708 - v707) >> 31));
    v706[0] = v1048;
    int * v710 = v696->cache_age;
    int v711 = v710[1];
    int v1050 = v711 + ((int)((unsigned int)(v711 - v707) >> 31));
    v710[1] = v1050;
    int * v713 = v696->cache_age;
    v713[v1047] = 0;
    v798 = v1047;
  } else {
    int * v716 = v696->cache_age;
    int v717 = v716[0];
    int * v718 = v696->cache_tags;
    int v719 = v718[0];
    int v720 = v716[1];
    int v721 = v718[1];
    bool v1054 = !(((~(((v702 ^ 4) | (-(v702 ^ 4))) >> 31)) | (~(((v703 ^ 4) | (-(v703 ^ 4))) >> 31))) == 0);
    int v775;
    if (v1054) {
      int * v722 = v696->cache_age;
      int v1056 = 4 + ((~(((v703 ^ 4) | (-(v703 ^ 4))) >> 31)) & 1);
      int v723 = v722[v1056];
      int v724 = v722[4];
      int v1057 = v724 + ((int)((unsigned int)(v724 - v723) >> 31));
      v722[4] = v1057;
      int * v726 = v696->cache_age;
      int v727 = v726[5];
      int v1059 = v727 + ((int)((unsigned int)(v727 - v723) >> 31));
      v726[5] = v1059;
      int * v729 = v696->cache_age;
      v729[v1056] = 0;
      v775 = v1056;
    } else {
      int * v732 = v696->cache_age;
      int v733 = v732[4];
      int * v734 = v696->cache_tags;
      int v735 = v734[4];
      int v736 = v732[5];
      int v737 = v734[5];
      int * v738 = v696->cache_dirty;
      int v1064 = 4 + ((((v733 + ((~(((v735 ^ -1) | (-(v735 ^ -1))) >> 31)) & 2)) - (v736 + ((~(((v737 ^ -1) | (-(v737 ^ -1))) >> 31)) & 2))) >> 31) & 1);
      int v739 = v738[v1064];
      bool v1065 = !(v739 == 0);
      if (v1065) {
        int * v740 = v696->cache_tags;
        int v741 = v740[v1064];
        int * v742 = v696->cache_vals;
        int v1068 = (4 + ((((v733 + ((~(((v735 ^ -1) | (-(v735 ^ -1))) >> 31)) & 2)) - (v736 + ((~(((v737 ^ -1) | (-(v737 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
        int v743 = v742[v1068];
        int v1069 = ((4 + ((((v733 + ((~(((v735 ^ -1) | (-(v735 ^ -1))) >> 31)) & 2)) - (v736 + ((~(((v737 ^ -1) | (-(v737 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
        int v744 = v742[v1069];
        int * v745 = v696->mem;
        int v1071 = v741 * 2;
        v745[v1071] = v743;
        int * v747 = v696->mem;
        int v1074 = (v741 * 2) + 1;
        v747[v1074] = v744;
        ;
      } else {
        ;
      }
      int * v752 = v696->mem;
      int v753 = v752[8];
      int v754 = v752[9];
      int * v755 = v696->cache_vals;
      int v1082 = (4 + ((((v733 + ((~(((v735 ^ -1) | (-(v735 ^ -1))) >> 31)) & 2)) - (v736 + ((~(((v737 ^ -1) | (-(v737 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
      v755[v1082] = v753;
      int * v757 = v696->cache_vals;
      int v1085 = ((4 + ((((v733 + ((~(((v735 ^ -1) | (-(v735 ^ -1))) >> 31)) & 2)) - (v736 + ((~(((v737 ^ -1) | (-(v737 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
      v757[v1085] = v754;
      int * v759 = v696->cache_tags;
      v759[v1064] = 4;
      int * v761 = v696->cache_dirty;
      v761[v1064] = 0;
      int * v763 = v696->cache_age;
      v763[v1064] = 1;
      int * v765 = v696->cache_age;
      int v766 = v765[v1064];
      int v767 = v765[4];
      int v1091 = v767 + ((int)((unsigned int)(v767 - v766) >> 31));
      v765[4] = v1091;
      int * v769 = v696->cache_age;
      int v770 = v769[5];
      int v1093 = v770 + ((int)((unsigned int)(v770 - v766) >> 31));
      v769[5] = v1093;
      int * v772 = v696->cache_age;
      v772[v1064] = 0;
      v775 = v1064;
    }
    int * v776 = v696->cache_vals;
    int v1096 = v775 * 2;
    int v777 = v776[v1096];
    int v1097 = (v775 * 2) + 1;
    int v778 = v776[v1097];
    int v1098 = ((((v717 + ((~(((v719 ^ -1) | (-(v719 ^ -1))) >> 31)) & 2)) - (v720 + ((~(((v721 ^ -1) | (-(v721 ^ -1))) >> 31)) & 2))) >> 31) & 1) * 2;
    v776[v1098] = v777;
    int * v780 = v696->cache_vals;
    int v1101 = (((((v717 + ((~(((v719 ^ -1) | (-(v719 ^ -1))) >> 31)) & 2)) - (v720 + ((~(((v721 ^ -1) | (-(v721 ^ -1))) >> 31)) & 2))) >> 31) & 1) * 2) + 1;
    v780[v1101] = v778;
    int * v782 = v696->cache_tags;
    int v1104 = (((v717 + ((~(((v719 ^ -1) | (-(v719 ^ -1))) >> 31)) & 2)) - (v720 + ((~(((v721 ^ -1) | (-(v721 ^ -1))) >> 31)) & 2))) >> 31) & 1;
    v782[v1104] = 4;
    int * v784 = v696->cache_dirty;
    v784[v1104] = 0;
    int * v786 = v696->cache_age;
    v786[v1104] = 1;
    int * v788 = v696->cache_age;
    int v789 = v788[v1104];
    int v790 = v788[0];
    int v1108 = v790 + ((int)((unsigned int)(v790 - v789) >> 31));
    v788[0] = v1108;
    int * v792 = v696->cache_age;
    int v793 = v792[1];
    int v1110 = v793 + ((int)((unsigned int)(v793 - v789) >> 31));
    v792[1] = v1110;
    int * v795 = v696->cache_age;
    v795[v1104] = 0;
    v798 = v1104;
  }
  int * v799 = v696->cache_vals;
  int v1113 = (v798 * 2) + 1;
  v799[v1113] = v698;
  int * v801 = v696->cache_tags;
  int v802 = v801[4];
  int v803 = v801[5];
  bool v1116 = !(((~(((v802 ^ 4) | (-(v802 ^ 4))) >> 31)) | (~(((v803 ^ 4) | (-(v803 ^ 4))) >> 31))) == 0);
  int v857;
  if (v1116) {
    int * v804 = v696->cache_age;
    int v1118 = 4 + ((~(((v803 ^ 4) | (-(v803 ^ 4))) >> 31)) & 1);
    int v805 = v804[v1118];
    int v806 = v804[4];
    int v1119 = v806 + ((int)((unsigned int)(v806 - v805) >> 31));
    v804[4] = v1119;
    int * v808 = v696->cache_age;
    int v809 = v808[5];
    int v1121 = v809 + ((int)((unsigned int)(v809 - v805) >> 31));
    v808[5] = v1121;
    int * v811 = v696->cache_age;
    v811[v1118] = 0;
    v857 = v1118;
  } else {
    int * v814 = v696->cache_age;
    int v815 = v814[4];
    int * v816 = v696->cache_tags;
    int v817 = v816[4];
    int v818 = v814[5];
    int v819 = v816[5];
    int * v820 = v696->cache_dirty;
    int v1126 = 4 + ((((v815 + ((~(((v817 ^ -1) | (-(v817 ^ -1))) >> 31)) & 2)) - (v818 + ((~(((v819 ^ -1) | (-(v819 ^ -1))) >> 31)) & 2))) >> 31) & 1);
    int v821 = v820[v1126];
    bool v1127 = !(v821 == 0);
    if (v1127) {
      int * v822 = v696->cache_tags;
      int v823 = v822[v1126];
      int * v824 = v696->cache_vals;
      int v1130 = (4 + ((((v815 + ((~(((v817 ^ -1) | (-(v817 ^ -1))) >> 31)) & 2)) - (v818 + ((~(((v819 ^ -1) | (-(v819 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
      int v825 = v824[v1130];
      int v1131 = ((4 + ((((v815 + ((~(((v817 ^ -1) | (-(v817 ^ -1))) >> 31)) & 2)) - (v818 + ((~(((v819 ^ -1) | (-(v819 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
      int v826 = v824[v1131];
      int * v827 = v696->mem;
      int v1133 = v823 * 2;
      v827[v1133] = v825;
      int * v829 = v696->mem;
      int v1136 = (v823 * 2) + 1;
      v829[v1136] = v826;
      ;
    } else {
      ;
    }
    int * v834 = v696->mem;
    int v835 = v834[8];
    int v836 = v834[9];
    int * v837 = v696->cache_vals;
    int v1144 = (4 + ((((v815 + ((~(((v817 ^ -1) | (-(v817 ^ -1))) >> 31)) & 2)) - (v818 + ((~(((v819 ^ -1) | (-(v819 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
    v837[v1144] = v835;
    int * v839 = v696->cache_vals;
    int v1147 = ((4 + ((((v815 + ((~(((v817 ^ -1) | (-(v817 ^ -1))) >> 31)) & 2)) - (v818 + ((~(((v819 ^ -1) | (-(v819 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
    v839[v1147] = v836;
    int * v841 = v696->cache_tags;
    v841[v1126] = 4;
    int * v843 = v696->cache_dirty;
    v843[v1126] = 0;
    int * v845 = v696->cache_age;
    v845[v1126] = 1;
    int * v847 = v696->cache_age;
    int v848 = v847[v1126];
    int v849 = v847[4];
    int v1153 = v849 + ((int)((unsigned int)(v849 - v848) >> 31));
    v847[4] = v1153;
    int * v851 = v696->cache_age;
    int v852 = v851[5];
    int v1155 = v852 + ((int)((unsigned int)(v852 - v848) >> 31));
    v851[5] = v1155;
    int * v854 = v696->cache_age;
    v854[v1126] = 0;
    v857 = v1126;
  }
  int * v858 = v696->cache_vals;
  int v1158 = (v857 * 2) + 1;
  v858[v1158] = v698;
  int * v860 = v696->cache_dirty;
  v860[v857] = 1;
  struct StateT * v862 = v683->b;
  int * v863 = v862->regs;
  int v864 = v863[5];
  int * v865 = v862->cache_tags;
  int v866 = v865[0];
  int v867 = v865[1];
  int v868 = v865[4];
  int v869 = v865[5];
  int v870 = v862->timer;
  int v1164 = v870 + ((100 ^ (((~(((v868 ^ 4) | (-(v868 ^ 4))) >> 31)) | (~(((v869 ^ 4) | (-(v869 ^ 4))) >> 31))) & 104)) ^ (((~(((v866 ^ 4) | (-(v866 ^ 4))) >> 31)) | (~(((v867 ^ 4) | (-(v867 ^ 4))) >> 31))) & (1 ^ (100 ^ (((~(((v868 ^ 4) | (-(v868 ^ 4))) >> 31)) | (~(((v869 ^ 4) | (-(v869 ^ 4))) >> 31))) & 104)))));
  v862->timer = v1164;
  bool v1165 = !(((~(((v866 ^ 4) | (-(v866 ^ 4))) >> 31)) | (~(((v867 ^ 4) | (-(v867 ^ 4))) >> 31))) == 0);
  int v964;
  if (v1165) {
    int * v872 = v862->cache_age;
    int v1167 = (~(((v867 ^ 4) | (-(v867 ^ 4))) >> 31)) & 1;
    int v873 = v872[v1167];
    int v874 = v872[0];
    int v1168 = v874 + ((int)((unsigned int)(v874 - v873) >> 31));
    v872[0] = v1168;
    int * v876 = v862->cache_age;
    int v877 = v876[1];
    int v1170 = v877 + ((int)((unsigned int)(v877 - v873) >> 31));
    v876[1] = v1170;
    int * v879 = v862->cache_age;
    v879[v1167] = 0;
    v964 = v1167;
  } else {
    int * v882 = v862->cache_age;
    int v883 = v882[0];
    int * v884 = v862->cache_tags;
    int v885 = v884[0];
    int v886 = v882[1];
    int v887 = v884[1];
    bool v1174 = !(((~(((v868 ^ 4) | (-(v868 ^ 4))) >> 31)) | (~(((v869 ^ 4) | (-(v869 ^ 4))) >> 31))) == 0);
    int v941;
    if (v1174) {
      int * v888 = v862->cache_age;
      int v1176 = 4 + ((~(((v869 ^ 4) | (-(v869 ^ 4))) >> 31)) & 1);
      int v889 = v888[v1176];
      int v890 = v888[4];
      int v1177 = v890 + ((int)((unsigned int)(v890 - v889) >> 31));
      v888[4] = v1177;
      int * v892 = v862->cache_age;
      int v893 = v892[5];
      int v1179 = v893 + ((int)((unsigned int)(v893 - v889) >> 31));
      v892[5] = v1179;
      int * v895 = v862->cache_age;
      v895[v1176] = 0;
      v941 = v1176;
    } else {
      int * v898 = v862->cache_age;
      int v899 = v898[4];
      int * v900 = v862->cache_tags;
      int v901 = v900[4];
      int v902 = v898[5];
      int v903 = v900[5];
      int * v904 = v862->cache_dirty;
      int v1184 = 4 + ((((v899 + ((~(((v901 ^ -1) | (-(v901 ^ -1))) >> 31)) & 2)) - (v902 + ((~(((v903 ^ -1) | (-(v903 ^ -1))) >> 31)) & 2))) >> 31) & 1);
      int v905 = v904[v1184];
      bool v1185 = !(v905 == 0);
      if (v1185) {
        int * v906 = v862->cache_tags;
        int v907 = v906[v1184];
        int * v908 = v862->cache_vals;
        int v1188 = (4 + ((((v899 + ((~(((v901 ^ -1) | (-(v901 ^ -1))) >> 31)) & 2)) - (v902 + ((~(((v903 ^ -1) | (-(v903 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
        int v909 = v908[v1188];
        int v1189 = ((4 + ((((v899 + ((~(((v901 ^ -1) | (-(v901 ^ -1))) >> 31)) & 2)) - (v902 + ((~(((v903 ^ -1) | (-(v903 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
        int v910 = v908[v1189];
        int * v911 = v862->mem;
        int v1191 = v907 * 2;
        v911[v1191] = v909;
        int * v913 = v862->mem;
        int v1194 = (v907 * 2) + 1;
        v913[v1194] = v910;
        ;
      } else {
        ;
      }
      int * v918 = v862->mem;
      int v919 = v918[8];
      int v920 = v918[9];
      int * v921 = v862->cache_vals;
      int v1202 = (4 + ((((v899 + ((~(((v901 ^ -1) | (-(v901 ^ -1))) >> 31)) & 2)) - (v902 + ((~(((v903 ^ -1) | (-(v903 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
      v921[v1202] = v919;
      int * v923 = v862->cache_vals;
      int v1205 = ((4 + ((((v899 + ((~(((v901 ^ -1) | (-(v901 ^ -1))) >> 31)) & 2)) - (v902 + ((~(((v903 ^ -1) | (-(v903 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
      v923[v1205] = v920;
      int * v925 = v862->cache_tags;
      v925[v1184] = 4;
      int * v927 = v862->cache_dirty;
      v927[v1184] = 0;
      int * v929 = v862->cache_age;
      v929[v1184] = 1;
      int * v931 = v862->cache_age;
      int v932 = v931[v1184];
      int v933 = v931[4];
      int v1211 = v933 + ((int)((unsigned int)(v933 - v932) >> 31));
      v931[4] = v1211;
      int * v935 = v862->cache_age;
      int v936 = v935[5];
      int v1213 = v936 + ((int)((unsigned int)(v936 - v932) >> 31));
      v935[5] = v1213;
      int * v938 = v862->cache_age;
      v938[v1184] = 0;
      v941 = v1184;
    }
    int * v942 = v862->cache_vals;
    int v1216 = v941 * 2;
    int v943 = v942[v1216];
    int v1217 = (v941 * 2) + 1;
    int v944 = v942[v1217];
    int v1218 = ((((v883 + ((~(((v885 ^ -1) | (-(v885 ^ -1))) >> 31)) & 2)) - (v886 + ((~(((v887 ^ -1) | (-(v887 ^ -1))) >> 31)) & 2))) >> 31) & 1) * 2;
    v942[v1218] = v943;
    int * v946 = v862->cache_vals;
    int v1221 = (((((v883 + ((~(((v885 ^ -1) | (-(v885 ^ -1))) >> 31)) & 2)) - (v886 + ((~(((v887 ^ -1) | (-(v887 ^ -1))) >> 31)) & 2))) >> 31) & 1) * 2) + 1;
    v946[v1221] = v944;
    int * v948 = v862->cache_tags;
    int v1224 = (((v883 + ((~(((v885 ^ -1) | (-(v885 ^ -1))) >> 31)) & 2)) - (v886 + ((~(((v887 ^ -1) | (-(v887 ^ -1))) >> 31)) & 2))) >> 31) & 1;
    v948[v1224] = 4;
    int * v950 = v862->cache_dirty;
    v950[v1224] = 0;
    int * v952 = v862->cache_age;
    v952[v1224] = 1;
    int * v954 = v862->cache_age;
    int v955 = v954[v1224];
    int v956 = v954[0];
    int v1228 = v956 + ((int)((unsigned int)(v956 - v955) >> 31));
    v954[0] = v1228;
    int * v958 = v862->cache_age;
    int v959 = v958[1];
    int v1230 = v959 + ((int)((unsigned int)(v959 - v955) >> 31));
    v958[1] = v1230;
    int * v961 = v862->cache_age;
    v961[v1224] = 0;
    v964 = v1224;
  }
  int * v965 = v862->cache_vals;
  int v1233 = (v964 * 2) + 1;
  v965[v1233] = v864;
  int * v967 = v862->cache_tags;
  int v968 = v967[4];
  int v969 = v967[5];
  bool v1236 = !(((~(((v968 ^ 4) | (-(v968 ^ 4))) >> 31)) | (~(((v969 ^ 4) | (-(v969 ^ 4))) >> 31))) == 0);
  int v1023;
  if (v1236) {
    int * v970 = v862->cache_age;
    int v1238 = 4 + ((~(((v969 ^ 4) | (-(v969 ^ 4))) >> 31)) & 1);
    int v971 = v970[v1238];
    int v972 = v970[4];
    int v1239 = v972 + ((int)((unsigned int)(v972 - v971) >> 31));
    v970[4] = v1239;
    int * v974 = v862->cache_age;
    int v975 = v974[5];
    int v1241 = v975 + ((int)((unsigned int)(v975 - v971) >> 31));
    v974[5] = v1241;
    int * v977 = v862->cache_age;
    v977[v1238] = 0;
    v1023 = v1238;
  } else {
    int * v980 = v862->cache_age;
    int v981 = v980[4];
    int * v982 = v862->cache_tags;
    int v983 = v982[4];
    int v984 = v980[5];
    int v985 = v982[5];
    int * v986 = v862->cache_dirty;
    int v1246 = 4 + ((((v981 + ((~(((v983 ^ -1) | (-(v983 ^ -1))) >> 31)) & 2)) - (v984 + ((~(((v985 ^ -1) | (-(v985 ^ -1))) >> 31)) & 2))) >> 31) & 1);
    int v987 = v986[v1246];
    bool v1247 = !(v987 == 0);
    if (v1247) {
      int * v988 = v862->cache_tags;
      int v989 = v988[v1246];
      int * v990 = v862->cache_vals;
      int v1250 = (4 + ((((v981 + ((~(((v983 ^ -1) | (-(v983 ^ -1))) >> 31)) & 2)) - (v984 + ((~(((v985 ^ -1) | (-(v985 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
      int v991 = v990[v1250];
      int v1251 = ((4 + ((((v981 + ((~(((v983 ^ -1) | (-(v983 ^ -1))) >> 31)) & 2)) - (v984 + ((~(((v985 ^ -1) | (-(v985 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
      int v992 = v990[v1251];
      int * v993 = v862->mem;
      int v1253 = v989 * 2;
      v993[v1253] = v991;
      int * v995 = v862->mem;
      int v1256 = (v989 * 2) + 1;
      v995[v1256] = v992;
      ;
    } else {
      ;
    }
    int * v1000 = v862->mem;
    int v1001 = v1000[8];
    int v1002 = v1000[9];
    int * v1003 = v862->cache_vals;
    int v1264 = (4 + ((((v981 + ((~(((v983 ^ -1) | (-(v983 ^ -1))) >> 31)) & 2)) - (v984 + ((~(((v985 ^ -1) | (-(v985 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
    v1003[v1264] = v1001;
    int * v1005 = v862->cache_vals;
    int v1267 = ((4 + ((((v981 + ((~(((v983 ^ -1) | (-(v983 ^ -1))) >> 31)) & 2)) - (v984 + ((~(((v985 ^ -1) | (-(v985 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
    v1005[v1267] = v1002;
    int * v1007 = v862->cache_tags;
    v1007[v1246] = 4;
    int * v1009 = v862->cache_dirty;
    v1009[v1246] = 0;
    int * v1011 = v862->cache_age;
    v1011[v1246] = 1;
    int * v1013 = v862->cache_age;
    int v1014 = v1013[v1246];
    int v1015 = v1013[4];
    int v1273 = v1015 + ((int)((unsigned int)(v1015 - v1014) >> 31));
    v1013[4] = v1273;
    int * v1017 = v862->cache_age;
    int v1018 = v1017[5];
    int v1275 = v1018 + ((int)((unsigned int)(v1018 - v1014) >> 31));
    v1017[5] = v1275;
    int * v1020 = v862->cache_age;
    v1020[v1246] = 0;
    v1023 = v1246;
  }
  int * v1024 = v862->cache_vals;
  int v1278 = (v1023 * 2) + 1;
  v1024[v1278] = v864;
  int * v1026 = v862->cache_dirty;
  v1026[v1023] = 1;
  struct StateT2 * v1028 = slot_4(v683);
  return v1028;
}

struct StateT2 * slot_0(struct StateT2 * v2) {
  struct StateT * v3 = v2->a;
  int v4 = v3->timer;
  struct StateT * v5 = v2->b;
  int v6 = v5->timer;
  bool v27 = v4 == v6;
  squared_assert(v27);
  squared_assume(v27);
  struct StateT * v9 = v2->a;
  int v10 = v9->timer;
  int v29 = v10 + 1;
  v9->timer = v29;
  struct StateT * v12 = v2->b;
  int v13 = v12->timer;
  int v31 = v13 + 1;
  v12->timer = v31;
  struct StateT * v15 = v2->a;
  int * v16 = v15->regs;
  int v17 = v16[10];
  int v36 = v17 & 28;
  v16[5] = v36;
  struct StateT * v19 = v2->b;
  int * v20 = v19->regs;
  int v21 = v20[10];
  int v39 = v21 & 28;
  v20[5] = v39;
  struct StateT2 * v23 = slot_1(v2);
  return v23;
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