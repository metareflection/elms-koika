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

struct StateT * slot_12(struct StateT * v617);
struct StateT * slot_6(struct StateT * v305);
struct StateT * slot_29(struct StateT * v2890);
struct StateT * slot_25(struct StateT * v2132);
struct StateT * slot_16(struct StateT * v1077);
struct StateT * slot_23(struct StateT * v1908);
struct StateT * slot_5(struct StateT * v284);
struct StateT * slot_2(struct StateT * v225);
struct StateT * slot_7(struct StateT * v329);
struct StateT * slot_21(struct StateT * v1685);
struct StateT * slot_31(struct StateT * v2919);
struct StateT * slot_3(struct StateT * v233);
struct StateT * slot_10(struct StateT * v573);
struct StateT * slot_1(struct StateT * v18);
struct StateT * slot_19(struct StateT * v1350);
struct StateT * slot_13(struct StateT * v638);
struct StateT * slot_24(struct StateT * v1924);
struct StateT * slot_0(struct StateT * v2);
struct StateT * slot_14(struct StateT * v662);
struct StateT * slot_17(struct StateT * v1101);
struct StateT * slot_33(struct StateT * v3238);
struct StateT * snippet(struct StateT * v0);
struct StateT * slot_8(struct StateT * v536);
struct StateT * slot_4(struct StateT * v261);
struct StateT * slot_15(struct StateT * v869);
struct StateT * slot_9(struct StateT * v552);
struct StateT * slot_11(struct StateT * v596);
struct StateT * slot_12(struct StateT * v617) {
  int v618 = v617->timer;
  int v629 = v618 + 1;
  v617->timer = v629;
  int * v620 = v617->reg_ready;
  int v621 = v620[10];
  int * v622 = v617->regs;
  int v623 = v622[10];
  int v633 = (v621 + ((v618 - v621) & (~((v618 - v621) >> 31)))) + 1;
  v620[10] = v633;
  int * v625 = v617->regs;
  int v635 = (int)((unsigned int)v623 >> 26);
  v625[10] = v635;
  struct StateT * v627 = slot_13(v617);
  return v627;
}

struct StateT * slot_6(struct StateT * v305) {
  int v306 = v305->timer;
  int v319 = v306 + 1;
  v305->timer = v319;
  int * v308 = v305->reg_ready;
  int v309 = v308[11];
  int * v310 = v305->regs;
  int v311 = v310[11];
  int v312 = v308[10];
  int v313 = v310[10];
  int v324 = (v312 + (((v309 + ((v306 - v309) & (~((v306 - v309) >> 31)))) - v312) & (~(((v309 + ((v306 - v309) & (~((v306 - v309) >> 31)))) - v312) >> 31)))) + 1;
  v308[10] = v324;
  int * v315 = v305->regs;
  int v326 = v311 + v313;
  v315[10] = v326;
  struct StateT * v317 = slot_7(v305);
  return v317;
}

struct StateT * slot_29(struct StateT * v2890) {
  int v2891 = v2890->timer;
  int v2904 = v2891 + 1;
  v2890->timer = v2904;
  int * v2893 = v2890->reg_ready;
  int v2894 = v2893[12];
  int * v2895 = v2890->regs;
  int v2896 = v2895[12];
  int v2897 = v2893[10];
  int v2898 = v2895[10];
  int v2909 = (v2897 + (((v2894 + ((v2891 - v2894) & (~((v2891 - v2894) >> 31)))) - v2897) & (~(((v2894 + ((v2891 - v2894) & (~((v2891 - v2894) >> 31)))) - v2897) >> 31)))) + 1;
  v2893[10] = v2909;
  int * v2900 = v2890->regs;
  int v2911 = v2896 & v2898;
  v2900[10] = v2911;
  struct StateT * v2902 = slot_31(v2890);
  return v2902;
}

struct StateT * slot_25(struct StateT * v2132) {
  int v2133 = v2132->timer;
  int v2245 = v2133 + 1;
  v2132->timer = v2245;
  int * v2135 = v2132->reg_ready;
  int v2136 = v2135[10];
  int * v2137 = v2132->regs;
  int v2138 = v2137[10];
  int * v2139 = v2132->cache_tags;
  int v2250 = (((int)((unsigned int)((int)((unsigned int)(v2138 + 4) >> 2)) >> 1)) & 1) * 2;
  int v2140 = v2139[v2250];
  int v2251 = ((((int)((unsigned int)((int)((unsigned int)(v2138 + 4) >> 2)) >> 1)) & 1) * 2) + 1;
  int v2141 = v2139[v2251];
  int v2252 = 4 + ((((int)((unsigned int)((int)((unsigned int)(v2138 + 4) >> 2)) >> 1)) & 3) * 2);
  int v2142 = v2139[v2252];
  int v2253 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v2138 + 4) >> 2)) >> 1)) & 3) * 2)) + 1;
  int v2143 = v2139[v2253];
  int * v2144 = v2132->cache_vals;
  bool v2254 = !(((~(((v2140 ^ ((int)((unsigned int)((int)((unsigned int)(v2138 + 4) >> 2)) >> 1))) | (-(v2140 ^ ((int)((unsigned int)((int)((unsigned int)(v2138 + 4) >> 2)) >> 1))))) >> 31)) | (~(((v2141 ^ ((int)((unsigned int)((int)((unsigned int)(v2138 + 4) >> 2)) >> 1))) | (-(v2141 ^ ((int)((unsigned int)((int)((unsigned int)(v2138 + 4) >> 2)) >> 1))))) >> 31))) == 0);
  int v2237;
  if (v2254) {
    int * v2145 = v2132->cache_age;
    int v2256 = ((((int)((unsigned int)((int)((unsigned int)(v2138 + 4) >> 2)) >> 1)) & 1) * 2) + ((~(((v2141 ^ ((int)((unsigned int)((int)((unsigned int)(v2138 + 4) >> 2)) >> 1))) | (-(v2141 ^ ((int)((unsigned int)((int)((unsigned int)(v2138 + 4) >> 2)) >> 1))))) >> 31)) & 1);
    int v2146 = v2145[v2256];
    int v2147 = v2145[v2250];
    int v2257 = v2147 + ((int)((unsigned int)(v2147 - v2146) >> 31));
    v2145[v2250] = v2257;
    int * v2149 = v2132->cache_age;
    int v2150 = v2149[v2251];
    int v2259 = v2150 + ((int)((unsigned int)(v2150 - v2146) >> 31));
    v2149[v2251] = v2259;
    int * v2152 = v2132->cache_age;
    v2152[v2256] = 0;
    v2237 = v2256;
  } else {
    int * v2155 = v2132->cache_age;
    int v2263 = (((int)((unsigned int)((int)((unsigned int)(v2138 + 4) >> 2)) >> 1)) & 1) * 2;
    int v2156 = v2155[v2263];
    int * v2157 = v2132->cache_tags;
    int v2158 = v2157[v2263];
    int v2159 = v2155[v2251];
    int v2160 = v2157[v2251];
    bool v2265 = !(((~(((v2142 ^ ((int)((unsigned int)((int)((unsigned int)(v2138 + 4) >> 2)) >> 1))) | (-(v2142 ^ ((int)((unsigned int)((int)((unsigned int)(v2138 + 4) >> 2)) >> 1))))) >> 31)) | (~(((v2143 ^ ((int)((unsigned int)((int)((unsigned int)(v2138 + 4) >> 2)) >> 1))) | (-(v2143 ^ ((int)((unsigned int)((int)((unsigned int)(v2138 + 4) >> 2)) >> 1))))) >> 31))) == 0);
    int v2214;
    if (v2265) {
      int * v2161 = v2132->cache_age;
      int v2267 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v2138 + 4) >> 2)) >> 1)) & 3) * 2)) + ((~(((v2143 ^ ((int)((unsigned int)((int)((unsigned int)(v2138 + 4) >> 2)) >> 1))) | (-(v2143 ^ ((int)((unsigned int)((int)((unsigned int)(v2138 + 4) >> 2)) >> 1))))) >> 31)) & 1);
      int v2162 = v2161[v2267];
      int v2163 = v2161[v2252];
      int v2268 = v2163 + ((int)((unsigned int)(v2163 - v2162) >> 31));
      v2161[v2252] = v2268;
      int * v2165 = v2132->cache_age;
      int v2166 = v2165[v2253];
      int v2270 = v2166 + ((int)((unsigned int)(v2166 - v2162) >> 31));
      v2165[v2253] = v2270;
      int * v2168 = v2132->cache_age;
      v2168[v2267] = 0;
      v2214 = v2267;
    } else {
      int * v2171 = v2132->cache_age;
      int v2274 = 4 + ((((int)((unsigned int)((int)((unsigned int)(v2138 + 4) >> 2)) >> 1)) & 3) * 2);
      int v2172 = v2171[v2274];
      int * v2173 = v2132->cache_tags;
      int v2174 = v2173[v2274];
      int v2175 = v2171[v2253];
      int v2176 = v2173[v2253];
      int * v2177 = v2132->cache_dirty;
      int v2277 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v2138 + 4) >> 2)) >> 1)) & 3) * 2)) + ((((v2172 + ((~(((v2174 ^ -1) | (-(v2174 ^ -1))) >> 31)) & 2)) - (v2175 + ((~(((v2176 ^ -1) | (-(v2176 ^ -1))) >> 31)) & 2))) >> 31) & 1);
      int v2178 = v2177[v2277];
      bool v2278 = !(v2178 == 0);
      if (v2278) {
        int * v2179 = v2132->cache_tags;
        int v2180 = v2179[v2277];
        int * v2181 = v2132->cache_vals;
        int v2281 = ((4 + ((((int)((unsigned int)((int)((unsigned int)(v2138 + 4) >> 2)) >> 1)) & 3) * 2)) + ((((v2172 + ((~(((v2174 ^ -1) | (-(v2174 ^ -1))) >> 31)) & 2)) - (v2175 + ((~(((v2176 ^ -1) | (-(v2176 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
        int v2182 = v2181[v2281];
        int v2282 = (((4 + ((((int)((unsigned int)((int)((unsigned int)(v2138 + 4) >> 2)) >> 1)) & 3) * 2)) + ((((v2172 + ((~(((v2174 ^ -1) | (-(v2174 ^ -1))) >> 31)) & 2)) - (v2175 + ((~(((v2176 ^ -1) | (-(v2176 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
        int v2183 = v2181[v2282];
        int * v2184 = v2132->mem;
        int v2284 = v2180 * 2;
        v2184[v2284] = v2182;
        int * v2186 = v2132->mem;
        int v2287 = (v2180 * 2) + 1;
        v2186[v2287] = v2183;
        ;
      } else {
        ;
      }
      int * v2191 = v2132->mem;
      int v2292 = ((int)((unsigned int)((int)((unsigned int)(v2138 + 4) >> 2)) >> 1)) * 2;
      int v2192 = v2191[v2292];
      int v2293 = (((int)((unsigned int)((int)((unsigned int)(v2138 + 4) >> 2)) >> 1)) * 2) + 1;
      int v2193 = v2191[v2293];
      int * v2194 = v2132->cache_vals;
      int v2295 = ((4 + ((((int)((unsigned int)((int)((unsigned int)(v2138 + 4) >> 2)) >> 1)) & 3) * 2)) + ((((v2172 + ((~(((v2174 ^ -1) | (-(v2174 ^ -1))) >> 31)) & 2)) - (v2175 + ((~(((v2176 ^ -1) | (-(v2176 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
      v2194[v2295] = v2192;
      int * v2196 = v2132->cache_vals;
      int v2298 = (((4 + ((((int)((unsigned int)((int)((unsigned int)(v2138 + 4) >> 2)) >> 1)) & 3) * 2)) + ((((v2172 + ((~(((v2174 ^ -1) | (-(v2174 ^ -1))) >> 31)) & 2)) - (v2175 + ((~(((v2176 ^ -1) | (-(v2176 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
      v2196[v2298] = v2193;
      int * v2198 = v2132->cache_tags;
      int v2301 = (int)((unsigned int)((int)((unsigned int)(v2138 + 4) >> 2)) >> 1);
      v2198[v2277] = v2301;
      int * v2200 = v2132->cache_dirty;
      v2200[v2277] = 0;
      int * v2202 = v2132->cache_age;
      v2202[v2277] = 1;
      int * v2204 = v2132->cache_age;
      int v2205 = v2204[v2277];
      int v2206 = v2204[v2252];
      int v2307 = v2206 + ((int)((unsigned int)(v2206 - v2205) >> 31));
      v2204[v2252] = v2307;
      int * v2208 = v2132->cache_age;
      int v2209 = v2208[v2253];
      int v2309 = v2209 + ((int)((unsigned int)(v2209 - v2205) >> 31));
      v2208[v2253] = v2309;
      int * v2211 = v2132->cache_age;
      v2211[v2277] = 0;
      v2214 = v2277;
    }
    int * v2215 = v2132->cache_vals;
    int v2312 = v2214 * 2;
    int v2216 = v2215[v2312];
    int v2313 = (v2214 * 2) + 1;
    int v2217 = v2215[v2313];
    int v2314 = (((((int)((unsigned int)((int)((unsigned int)(v2138 + 4) >> 2)) >> 1)) & 1) * 2) + ((((v2156 + ((~(((v2158 ^ -1) | (-(v2158 ^ -1))) >> 31)) & 2)) - (v2159 + ((~(((v2160 ^ -1) | (-(v2160 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
    v2215[v2314] = v2216;
    int * v2219 = v2132->cache_vals;
    int v2317 = ((((((int)((unsigned int)((int)((unsigned int)(v2138 + 4) >> 2)) >> 1)) & 1) * 2) + ((((v2156 + ((~(((v2158 ^ -1) | (-(v2158 ^ -1))) >> 31)) & 2)) - (v2159 + ((~(((v2160 ^ -1) | (-(v2160 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
    v2219[v2317] = v2217;
    int * v2221 = v2132->cache_tags;
    int v2320 = ((((int)((unsigned int)((int)((unsigned int)(v2138 + 4) >> 2)) >> 1)) & 1) * 2) + ((((v2156 + ((~(((v2158 ^ -1) | (-(v2158 ^ -1))) >> 31)) & 2)) - (v2159 + ((~(((v2160 ^ -1) | (-(v2160 ^ -1))) >> 31)) & 2))) >> 31) & 1);
    int v2321 = (int)((unsigned int)((int)((unsigned int)(v2138 + 4) >> 2)) >> 1);
    v2221[v2320] = v2321;
    int * v2223 = v2132->cache_dirty;
    v2223[v2320] = 0;
    int * v2225 = v2132->cache_age;
    v2225[v2320] = 1;
    int * v2227 = v2132->cache_age;
    int v2228 = v2227[v2320];
    int v2229 = v2227[v2250];
    int v2327 = v2229 + ((int)((unsigned int)(v2229 - v2228) >> 31));
    v2227[v2250] = v2327;
    int * v2231 = v2132->cache_age;
    int v2232 = v2231[v2251];
    int v2329 = v2232 + ((int)((unsigned int)(v2232 - v2228) >> 31));
    v2231[v2251] = v2329;
    int * v2234 = v2132->cache_age;
    v2234[v2320] = 0;
    v2237 = v2320;
  }
  int v2332 = (v2237 * 2) + (((int)((unsigned int)(v2138 + 4) >> 2)) & 1);
  int v2238 = v2144[v2332];
  int * v2239 = v2132->reg_ready;
  int v2334 = ((v2136 + ((v2133 - v2136) & (~((v2133 - v2136) >> 31)))) + 1) + ((100 ^ (((~(((v2142 ^ ((int)((unsigned int)((int)((unsigned int)(v2138 + 4) >> 2)) >> 1))) | (-(v2142 ^ ((int)((unsigned int)((int)((unsigned int)(v2138 + 4) >> 2)) >> 1))))) >> 31)) | (~(((v2143 ^ ((int)((unsigned int)((int)((unsigned int)(v2138 + 4) >> 2)) >> 1))) | (-(v2143 ^ ((int)((unsigned int)((int)((unsigned int)(v2138 + 4) >> 2)) >> 1))))) >> 31))) & 104)) ^ (((~(((v2140 ^ ((int)((unsigned int)((int)((unsigned int)(v2138 + 4) >> 2)) >> 1))) | (-(v2140 ^ ((int)((unsigned int)((int)((unsigned int)(v2138 + 4) >> 2)) >> 1))))) >> 31)) | (~(((v2141 ^ ((int)((unsigned int)((int)((unsigned int)(v2138 + 4) >> 2)) >> 1))) | (-(v2141 ^ ((int)((unsigned int)((int)((unsigned int)(v2138 + 4) >> 2)) >> 1))))) >> 31))) & (1 ^ (100 ^ (((~(((v2142 ^ ((int)((unsigned int)((int)((unsigned int)(v2138 + 4) >> 2)) >> 1))) | (-(v2142 ^ ((int)((unsigned int)((int)((unsigned int)(v2138 + 4) >> 2)) >> 1))))) >> 31)) | (~(((v2143 ^ ((int)((unsigned int)((int)((unsigned int)(v2138 + 4) >> 2)) >> 1))) | (-(v2143 ^ ((int)((unsigned int)((int)((unsigned int)(v2138 + 4) >> 2)) >> 1))))) >> 31))) & 104)))));
  v2239[10] = v2334;
  int * v2241 = v2132->regs;
  v2241[10] = v2238;
  struct StateT * v2243 = slot_24(v2132);
  return v2243;
}

struct StateT * slot_16(struct StateT * v1077) {
  int v1078 = v1077->timer;
  int v1091 = v1078 + 1;
  v1077->timer = v1091;
  int * v1080 = v1077->reg_ready;
  int v1081 = v1080[11];
  int * v1082 = v1077->regs;
  int v1083 = v1082[11];
  int v1084 = v1080[10];
  int v1085 = v1082[10];
  int v1096 = (v1084 + (((v1081 + ((v1078 - v1081) & (~((v1078 - v1081) >> 31)))) - v1084) & (~(((v1081 + ((v1078 - v1081) & (~((v1078 - v1081) >> 31)))) - v1084) >> 31)))) + 1;
  v1080[10] = v1096;
  int * v1087 = v1077->regs;
  int v1098 = v1083 & v1085;
  v1087[10] = v1098;
  struct StateT * v1089 = slot_17(v1077);
  return v1089;
}

struct StateT * slot_23(struct StateT * v1908) {
  int v1909 = v1908->timer;
  int v1917 = v1909 + 1;
  v1908->timer = v1917;
  int * v1911 = v1908->reg_ready;
  v1911[11] = v1917;
  int * v1913 = v1908->regs;
  v1913[11] = 0;
  struct StateT * v1915 = slot_25(v1908);
  return v1915;
}

struct StateT * slot_5(struct StateT * v284) {
  int v285 = v284->timer;
  int v296 = v285 + 1;
  v284->timer = v296;
  int * v287 = v284->reg_ready;
  int v288 = v287[11];
  int * v289 = v284->regs;
  int v290 = v289[11];
  int v300 = (v288 + ((v285 - v288) & (~((v285 - v288) >> 31)))) + 1;
  v287[11] = v300;
  int * v292 = v284->regs;
  int v302 = v290 + 72;
  v292[11] = v302;
  struct StateT * v294 = slot_6(v284);
  return v294;
}

struct StateT * slot_2(struct StateT * v225) {
  int v226 = v225->timer;
  int v230 = v226 + 1;
  v225->timer = v230;
  struct StateT * v228 = slot_3(v225);
  return v228;
}

struct StateT * slot_7(struct StateT * v329) {
  int v330 = v329->timer;
  int v442 = v330 + 1;
  v329->timer = v442;
  int * v332 = v329->reg_ready;
  int v333 = v332[10];
  int * v334 = v329->regs;
  int v335 = v334[10];
  int * v336 = v329->cache_tags;
  int v447 = (((int)((unsigned int)((int)((unsigned int)v335 >> 2)) >> 1)) & 1) * 2;
  int v337 = v336[v447];
  int v448 = ((((int)((unsigned int)((int)((unsigned int)v335 >> 2)) >> 1)) & 1) * 2) + 1;
  int v338 = v336[v448];
  int v449 = 4 + ((((int)((unsigned int)((int)((unsigned int)v335 >> 2)) >> 1)) & 3) * 2);
  int v339 = v336[v449];
  int v450 = (4 + ((((int)((unsigned int)((int)((unsigned int)v335 >> 2)) >> 1)) & 3) * 2)) + 1;
  int v340 = v336[v450];
  int * v341 = v329->cache_vals;
  bool v451 = !(((~(((v337 ^ ((int)((unsigned int)((int)((unsigned int)v335 >> 2)) >> 1))) | (-(v337 ^ ((int)((unsigned int)((int)((unsigned int)v335 >> 2)) >> 1))))) >> 31)) | (~(((v338 ^ ((int)((unsigned int)((int)((unsigned int)v335 >> 2)) >> 1))) | (-(v338 ^ ((int)((unsigned int)((int)((unsigned int)v335 >> 2)) >> 1))))) >> 31))) == 0);
  int v434;
  if (v451) {
    int * v342 = v329->cache_age;
    int v453 = ((((int)((unsigned int)((int)((unsigned int)v335 >> 2)) >> 1)) & 1) * 2) + ((~(((v338 ^ ((int)((unsigned int)((int)((unsigned int)v335 >> 2)) >> 1))) | (-(v338 ^ ((int)((unsigned int)((int)((unsigned int)v335 >> 2)) >> 1))))) >> 31)) & 1);
    int v343 = v342[v453];
    int v344 = v342[v447];
    int v454 = v344 + ((int)((unsigned int)(v344 - v343) >> 31));
    v342[v447] = v454;
    int * v346 = v329->cache_age;
    int v347 = v346[v448];
    int v456 = v347 + ((int)((unsigned int)(v347 - v343) >> 31));
    v346[v448] = v456;
    int * v349 = v329->cache_age;
    v349[v453] = 0;
    v434 = v453;
  } else {
    int * v352 = v329->cache_age;
    int v460 = (((int)((unsigned int)((int)((unsigned int)v335 >> 2)) >> 1)) & 1) * 2;
    int v353 = v352[v460];
    int * v354 = v329->cache_tags;
    int v355 = v354[v460];
    int v356 = v352[v448];
    int v357 = v354[v448];
    bool v462 = !(((~(((v339 ^ ((int)((unsigned int)((int)((unsigned int)v335 >> 2)) >> 1))) | (-(v339 ^ ((int)((unsigned int)((int)((unsigned int)v335 >> 2)) >> 1))))) >> 31)) | (~(((v340 ^ ((int)((unsigned int)((int)((unsigned int)v335 >> 2)) >> 1))) | (-(v340 ^ ((int)((unsigned int)((int)((unsigned int)v335 >> 2)) >> 1))))) >> 31))) == 0);
    int v411;
    if (v462) {
      int * v358 = v329->cache_age;
      int v464 = (4 + ((((int)((unsigned int)((int)((unsigned int)v335 >> 2)) >> 1)) & 3) * 2)) + ((~(((v340 ^ ((int)((unsigned int)((int)((unsigned int)v335 >> 2)) >> 1))) | (-(v340 ^ ((int)((unsigned int)((int)((unsigned int)v335 >> 2)) >> 1))))) >> 31)) & 1);
      int v359 = v358[v464];
      int v360 = v358[v449];
      int v465 = v360 + ((int)((unsigned int)(v360 - v359) >> 31));
      v358[v449] = v465;
      int * v362 = v329->cache_age;
      int v363 = v362[v450];
      int v467 = v363 + ((int)((unsigned int)(v363 - v359) >> 31));
      v362[v450] = v467;
      int * v365 = v329->cache_age;
      v365[v464] = 0;
      v411 = v464;
    } else {
      int * v368 = v329->cache_age;
      int v471 = 4 + ((((int)((unsigned int)((int)((unsigned int)v335 >> 2)) >> 1)) & 3) * 2);
      int v369 = v368[v471];
      int * v370 = v329->cache_tags;
      int v371 = v370[v471];
      int v372 = v368[v450];
      int v373 = v370[v450];
      int * v374 = v329->cache_dirty;
      int v474 = (4 + ((((int)((unsigned int)((int)((unsigned int)v335 >> 2)) >> 1)) & 3) * 2)) + ((((v369 + ((~(((v371 ^ -1) | (-(v371 ^ -1))) >> 31)) & 2)) - (v372 + ((~(((v373 ^ -1) | (-(v373 ^ -1))) >> 31)) & 2))) >> 31) & 1);
      int v375 = v374[v474];
      bool v475 = !(v375 == 0);
      if (v475) {
        int * v376 = v329->cache_tags;
        int v377 = v376[v474];
        int * v378 = v329->cache_vals;
        int v478 = ((4 + ((((int)((unsigned int)((int)((unsigned int)v335 >> 2)) >> 1)) & 3) * 2)) + ((((v369 + ((~(((v371 ^ -1) | (-(v371 ^ -1))) >> 31)) & 2)) - (v372 + ((~(((v373 ^ -1) | (-(v373 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
        int v379 = v378[v478];
        int v479 = (((4 + ((((int)((unsigned int)((int)((unsigned int)v335 >> 2)) >> 1)) & 3) * 2)) + ((((v369 + ((~(((v371 ^ -1) | (-(v371 ^ -1))) >> 31)) & 2)) - (v372 + ((~(((v373 ^ -1) | (-(v373 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
        int v380 = v378[v479];
        int * v381 = v329->mem;
        int v481 = v377 * 2;
        v381[v481] = v379;
        int * v383 = v329->mem;
        int v484 = (v377 * 2) + 1;
        v383[v484] = v380;
        ;
      } else {
        ;
      }
      int * v388 = v329->mem;
      int v489 = ((int)((unsigned int)((int)((unsigned int)v335 >> 2)) >> 1)) * 2;
      int v389 = v388[v489];
      int v490 = (((int)((unsigned int)((int)((unsigned int)v335 >> 2)) >> 1)) * 2) + 1;
      int v390 = v388[v490];
      int * v391 = v329->cache_vals;
      int v492 = ((4 + ((((int)((unsigned int)((int)((unsigned int)v335 >> 2)) >> 1)) & 3) * 2)) + ((((v369 + ((~(((v371 ^ -1) | (-(v371 ^ -1))) >> 31)) & 2)) - (v372 + ((~(((v373 ^ -1) | (-(v373 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
      v391[v492] = v389;
      int * v393 = v329->cache_vals;
      int v495 = (((4 + ((((int)((unsigned int)((int)((unsigned int)v335 >> 2)) >> 1)) & 3) * 2)) + ((((v369 + ((~(((v371 ^ -1) | (-(v371 ^ -1))) >> 31)) & 2)) - (v372 + ((~(((v373 ^ -1) | (-(v373 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
      v393[v495] = v390;
      int * v395 = v329->cache_tags;
      int v498 = (int)((unsigned int)((int)((unsigned int)v335 >> 2)) >> 1);
      v395[v474] = v498;
      int * v397 = v329->cache_dirty;
      v397[v474] = 0;
      int * v399 = v329->cache_age;
      v399[v474] = 1;
      int * v401 = v329->cache_age;
      int v402 = v401[v474];
      int v403 = v401[v449];
      int v504 = v403 + ((int)((unsigned int)(v403 - v402) >> 31));
      v401[v449] = v504;
      int * v405 = v329->cache_age;
      int v406 = v405[v450];
      int v506 = v406 + ((int)((unsigned int)(v406 - v402) >> 31));
      v405[v450] = v506;
      int * v408 = v329->cache_age;
      v408[v474] = 0;
      v411 = v474;
    }
    int * v412 = v329->cache_vals;
    int v509 = v411 * 2;
    int v413 = v412[v509];
    int v510 = (v411 * 2) + 1;
    int v414 = v412[v510];
    int v511 = (((((int)((unsigned int)((int)((unsigned int)v335 >> 2)) >> 1)) & 1) * 2) + ((((v353 + ((~(((v355 ^ -1) | (-(v355 ^ -1))) >> 31)) & 2)) - (v356 + ((~(((v357 ^ -1) | (-(v357 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
    v412[v511] = v413;
    int * v416 = v329->cache_vals;
    int v514 = ((((((int)((unsigned int)((int)((unsigned int)v335 >> 2)) >> 1)) & 1) * 2) + ((((v353 + ((~(((v355 ^ -1) | (-(v355 ^ -1))) >> 31)) & 2)) - (v356 + ((~(((v357 ^ -1) | (-(v357 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
    v416[v514] = v414;
    int * v418 = v329->cache_tags;
    int v517 = ((((int)((unsigned int)((int)((unsigned int)v335 >> 2)) >> 1)) & 1) * 2) + ((((v353 + ((~(((v355 ^ -1) | (-(v355 ^ -1))) >> 31)) & 2)) - (v356 + ((~(((v357 ^ -1) | (-(v357 ^ -1))) >> 31)) & 2))) >> 31) & 1);
    int v518 = (int)((unsigned int)((int)((unsigned int)v335 >> 2)) >> 1);
    v418[v517] = v518;
    int * v420 = v329->cache_dirty;
    v420[v517] = 0;
    int * v422 = v329->cache_age;
    v422[v517] = 1;
    int * v424 = v329->cache_age;
    int v425 = v424[v517];
    int v426 = v424[v447];
    int v524 = v426 + ((int)((unsigned int)(v426 - v425) >> 31));
    v424[v447] = v524;
    int * v428 = v329->cache_age;
    int v429 = v428[v448];
    int v526 = v429 + ((int)((unsigned int)(v429 - v425) >> 31));
    v428[v448] = v526;
    int * v431 = v329->cache_age;
    v431[v517] = 0;
    v434 = v517;
  }
  int v529 = (v434 * 2) + (((int)((unsigned int)v335 >> 2)) & 1);
  int v435 = v341[v529];
  int * v436 = v329->reg_ready;
  int v531 = ((v333 + ((v330 - v333) & (~((v330 - v333) >> 31)))) + 1) + ((100 ^ (((~(((v339 ^ ((int)((unsigned int)((int)((unsigned int)v335 >> 2)) >> 1))) | (-(v339 ^ ((int)((unsigned int)((int)((unsigned int)v335 >> 2)) >> 1))))) >> 31)) | (~(((v340 ^ ((int)((unsigned int)((int)((unsigned int)v335 >> 2)) >> 1))) | (-(v340 ^ ((int)((unsigned int)((int)((unsigned int)v335 >> 2)) >> 1))))) >> 31))) & 104)) ^ (((~(((v337 ^ ((int)((unsigned int)((int)((unsigned int)v335 >> 2)) >> 1))) | (-(v337 ^ ((int)((unsigned int)((int)((unsigned int)v335 >> 2)) >> 1))))) >> 31)) | (~(((v338 ^ ((int)((unsigned int)((int)((unsigned int)v335 >> 2)) >> 1))) | (-(v338 ^ ((int)((unsigned int)((int)((unsigned int)v335 >> 2)) >> 1))))) >> 31))) & (1 ^ (100 ^ (((~(((v339 ^ ((int)((unsigned int)((int)((unsigned int)v335 >> 2)) >> 1))) | (-(v339 ^ ((int)((unsigned int)((int)((unsigned int)v335 >> 2)) >> 1))))) >> 31)) | (~(((v340 ^ ((int)((unsigned int)((int)((unsigned int)v335 >> 2)) >> 1))) | (-(v340 ^ ((int)((unsigned int)((int)((unsigned int)v335 >> 2)) >> 1))))) >> 31))) & 104)))));
  v436[10] = v531;
  int * v438 = v329->regs;
  v438[10] = v435;
  struct StateT * v440 = slot_8(v329);
  return v440;
}

struct StateT * slot_21(struct StateT * v1685) {
  int v1686 = v1685->timer;
  int v1694 = v1686 + 1;
  v1685->timer = v1694;
  int * v1688 = v1685->reg_ready;
  v1688[10] = v1694;
  int * v1690 = v1685->regs;
  v1690[10] = 0;
  struct StateT * v1692 = slot_23(v1685);
  return v1692;
}

struct StateT * slot_31(struct StateT * v2919) {
  int v2920 = v2919->timer;
  int v3093 = v2920 + 1;
  v2919->timer = v3093;
  int * v2922 = v2919->reg_ready;
  int * v2924 = v2919->regs;
  int v2925 = v2924[11];
  int v2927 = v2924[10];
  int * v2928 = v2919->cache_tags;
  int v3099 = (((int)((unsigned int)((int)((unsigned int)(v2925 + 68) >> 2)) >> 1)) & 1) * 2;
  int v2929 = v2928[v3099];
  int v3100 = ((((int)((unsigned int)((int)((unsigned int)(v2925 + 68) >> 2)) >> 1)) & 1) * 2) + 1;
  int v2930 = v2928[v3100];
  int v3101 = 4 + ((((int)((unsigned int)((int)((unsigned int)(v2925 + 68) >> 2)) >> 1)) & 3) * 2);
  int v2931 = v2928[v3101];
  int v3102 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v2925 + 68) >> 2)) >> 1)) & 3) * 2)) + 1;
  int v2932 = v2928[v3102];
  int v2933 = v2919->timer;
  int v3103 = v2933 + ((100 ^ (((~(((v2931 ^ ((int)((unsigned int)((int)((unsigned int)(v2925 + 68) >> 2)) >> 1))) | (-(v2931 ^ ((int)((unsigned int)((int)((unsigned int)(v2925 + 68) >> 2)) >> 1))))) >> 31)) | (~(((v2932 ^ ((int)((unsigned int)((int)((unsigned int)(v2925 + 68) >> 2)) >> 1))) | (-(v2932 ^ ((int)((unsigned int)((int)((unsigned int)(v2925 + 68) >> 2)) >> 1))))) >> 31))) & 104)) ^ (((~(((v2929 ^ ((int)((unsigned int)((int)((unsigned int)(v2925 + 68) >> 2)) >> 1))) | (-(v2929 ^ ((int)((unsigned int)((int)((unsigned int)(v2925 + 68) >> 2)) >> 1))))) >> 31)) | (~(((v2930 ^ ((int)((unsigned int)((int)((unsigned int)(v2925 + 68) >> 2)) >> 1))) | (-(v2930 ^ ((int)((unsigned int)((int)((unsigned int)(v2925 + 68) >> 2)) >> 1))))) >> 31))) & (1 ^ (100 ^ (((~(((v2931 ^ ((int)((unsigned int)((int)((unsigned int)(v2925 + 68) >> 2)) >> 1))) | (-(v2931 ^ ((int)((unsigned int)((int)((unsigned int)(v2925 + 68) >> 2)) >> 1))))) >> 31)) | (~(((v2932 ^ ((int)((unsigned int)((int)((unsigned int)(v2925 + 68) >> 2)) >> 1))) | (-(v2932 ^ ((int)((unsigned int)((int)((unsigned int)(v2925 + 68) >> 2)) >> 1))))) >> 31))) & 104)))));
  v2919->timer = v3103;
  bool v3104 = !(((~(((v2929 ^ ((int)((unsigned int)((int)((unsigned int)(v2925 + 68) >> 2)) >> 1))) | (-(v2929 ^ ((int)((unsigned int)((int)((unsigned int)(v2925 + 68) >> 2)) >> 1))))) >> 31)) | (~(((v2930 ^ ((int)((unsigned int)((int)((unsigned int)(v2925 + 68) >> 2)) >> 1))) | (-(v2930 ^ ((int)((unsigned int)((int)((unsigned int)(v2925 + 68) >> 2)) >> 1))))) >> 31))) == 0);
  int v3027;
  if (v3104) {
    int * v2935 = v2919->cache_age;
    int v3106 = ((((int)((unsigned int)((int)((unsigned int)(v2925 + 68) >> 2)) >> 1)) & 1) * 2) + ((~(((v2930 ^ ((int)((unsigned int)((int)((unsigned int)(v2925 + 68) >> 2)) >> 1))) | (-(v2930 ^ ((int)((unsigned int)((int)((unsigned int)(v2925 + 68) >> 2)) >> 1))))) >> 31)) & 1);
    int v2936 = v2935[v3106];
    int v2937 = v2935[v3099];
    int v3107 = v2937 + ((int)((unsigned int)(v2937 - v2936) >> 31));
    v2935[v3099] = v3107;
    int * v2939 = v2919->cache_age;
    int v2940 = v2939[v3100];
    int v3109 = v2940 + ((int)((unsigned int)(v2940 - v2936) >> 31));
    v2939[v3100] = v3109;
    int * v2942 = v2919->cache_age;
    v2942[v3106] = 0;
    v3027 = v3106;
  } else {
    int * v2945 = v2919->cache_age;
    int v3113 = (((int)((unsigned int)((int)((unsigned int)(v2925 + 68) >> 2)) >> 1)) & 1) * 2;
    int v2946 = v2945[v3113];
    int * v2947 = v2919->cache_tags;
    int v2948 = v2947[v3113];
    int v2949 = v2945[v3100];
    int v2950 = v2947[v3100];
    bool v3115 = !(((~(((v2931 ^ ((int)((unsigned int)((int)((unsigned int)(v2925 + 68) >> 2)) >> 1))) | (-(v2931 ^ ((int)((unsigned int)((int)((unsigned int)(v2925 + 68) >> 2)) >> 1))))) >> 31)) | (~(((v2932 ^ ((int)((unsigned int)((int)((unsigned int)(v2925 + 68) >> 2)) >> 1))) | (-(v2932 ^ ((int)((unsigned int)((int)((unsigned int)(v2925 + 68) >> 2)) >> 1))))) >> 31))) == 0);
    int v3004;
    if (v3115) {
      int * v2951 = v2919->cache_age;
      int v3117 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v2925 + 68) >> 2)) >> 1)) & 3) * 2)) + ((~(((v2932 ^ ((int)((unsigned int)((int)((unsigned int)(v2925 + 68) >> 2)) >> 1))) | (-(v2932 ^ ((int)((unsigned int)((int)((unsigned int)(v2925 + 68) >> 2)) >> 1))))) >> 31)) & 1);
      int v2952 = v2951[v3117];
      int v2953 = v2951[v3101];
      int v3118 = v2953 + ((int)((unsigned int)(v2953 - v2952) >> 31));
      v2951[v3101] = v3118;
      int * v2955 = v2919->cache_age;
      int v2956 = v2955[v3102];
      int v3120 = v2956 + ((int)((unsigned int)(v2956 - v2952) >> 31));
      v2955[v3102] = v3120;
      int * v2958 = v2919->cache_age;
      v2958[v3117] = 0;
      v3004 = v3117;
    } else {
      int * v2961 = v2919->cache_age;
      int v3124 = 4 + ((((int)((unsigned int)((int)((unsigned int)(v2925 + 68) >> 2)) >> 1)) & 3) * 2);
      int v2962 = v2961[v3124];
      int * v2963 = v2919->cache_tags;
      int v2964 = v2963[v3124];
      int v2965 = v2961[v3102];
      int v2966 = v2963[v3102];
      int * v2967 = v2919->cache_dirty;
      int v3127 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v2925 + 68) >> 2)) >> 1)) & 3) * 2)) + ((((v2962 + ((~(((v2964 ^ -1) | (-(v2964 ^ -1))) >> 31)) & 2)) - (v2965 + ((~(((v2966 ^ -1) | (-(v2966 ^ -1))) >> 31)) & 2))) >> 31) & 1);
      int v2968 = v2967[v3127];
      bool v3128 = !(v2968 == 0);
      if (v3128) {
        int * v2969 = v2919->cache_tags;
        int v2970 = v2969[v3127];
        int * v2971 = v2919->cache_vals;
        int v3131 = ((4 + ((((int)((unsigned int)((int)((unsigned int)(v2925 + 68) >> 2)) >> 1)) & 3) * 2)) + ((((v2962 + ((~(((v2964 ^ -1) | (-(v2964 ^ -1))) >> 31)) & 2)) - (v2965 + ((~(((v2966 ^ -1) | (-(v2966 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
        int v2972 = v2971[v3131];
        int v3132 = (((4 + ((((int)((unsigned int)((int)((unsigned int)(v2925 + 68) >> 2)) >> 1)) & 3) * 2)) + ((((v2962 + ((~(((v2964 ^ -1) | (-(v2964 ^ -1))) >> 31)) & 2)) - (v2965 + ((~(((v2966 ^ -1) | (-(v2966 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
        int v2973 = v2971[v3132];
        int * v2974 = v2919->mem;
        int v3134 = v2970 * 2;
        v2974[v3134] = v2972;
        int * v2976 = v2919->mem;
        int v3137 = (v2970 * 2) + 1;
        v2976[v3137] = v2973;
        ;
      } else {
        ;
      }
      int * v2981 = v2919->mem;
      int v3142 = ((int)((unsigned int)((int)((unsigned int)(v2925 + 68) >> 2)) >> 1)) * 2;
      int v2982 = v2981[v3142];
      int v3143 = (((int)((unsigned int)((int)((unsigned int)(v2925 + 68) >> 2)) >> 1)) * 2) + 1;
      int v2983 = v2981[v3143];
      int * v2984 = v2919->cache_vals;
      int v3145 = ((4 + ((((int)((unsigned int)((int)((unsigned int)(v2925 + 68) >> 2)) >> 1)) & 3) * 2)) + ((((v2962 + ((~(((v2964 ^ -1) | (-(v2964 ^ -1))) >> 31)) & 2)) - (v2965 + ((~(((v2966 ^ -1) | (-(v2966 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
      v2984[v3145] = v2982;
      int * v2986 = v2919->cache_vals;
      int v3148 = (((4 + ((((int)((unsigned int)((int)((unsigned int)(v2925 + 68) >> 2)) >> 1)) & 3) * 2)) + ((((v2962 + ((~(((v2964 ^ -1) | (-(v2964 ^ -1))) >> 31)) & 2)) - (v2965 + ((~(((v2966 ^ -1) | (-(v2966 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
      v2986[v3148] = v2983;
      int * v2988 = v2919->cache_tags;
      int v3151 = (int)((unsigned int)((int)((unsigned int)(v2925 + 68) >> 2)) >> 1);
      v2988[v3127] = v3151;
      int * v2990 = v2919->cache_dirty;
      v2990[v3127] = 0;
      int * v2992 = v2919->cache_age;
      v2992[v3127] = 1;
      int * v2994 = v2919->cache_age;
      int v2995 = v2994[v3127];
      int v2996 = v2994[v3101];
      int v3157 = v2996 + ((int)((unsigned int)(v2996 - v2995) >> 31));
      v2994[v3101] = v3157;
      int * v2998 = v2919->cache_age;
      int v2999 = v2998[v3102];
      int v3159 = v2999 + ((int)((unsigned int)(v2999 - v2995) >> 31));
      v2998[v3102] = v3159;
      int * v3001 = v2919->cache_age;
      v3001[v3127] = 0;
      v3004 = v3127;
    }
    int * v3005 = v2919->cache_vals;
    int v3162 = v3004 * 2;
    int v3006 = v3005[v3162];
    int v3163 = (v3004 * 2) + 1;
    int v3007 = v3005[v3163];
    int v3164 = (((((int)((unsigned int)((int)((unsigned int)(v2925 + 68) >> 2)) >> 1)) & 1) * 2) + ((((v2946 + ((~(((v2948 ^ -1) | (-(v2948 ^ -1))) >> 31)) & 2)) - (v2949 + ((~(((v2950 ^ -1) | (-(v2950 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
    v3005[v3164] = v3006;
    int * v3009 = v2919->cache_vals;
    int v3167 = ((((((int)((unsigned int)((int)((unsigned int)(v2925 + 68) >> 2)) >> 1)) & 1) * 2) + ((((v2946 + ((~(((v2948 ^ -1) | (-(v2948 ^ -1))) >> 31)) & 2)) - (v2949 + ((~(((v2950 ^ -1) | (-(v2950 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
    v3009[v3167] = v3007;
    int * v3011 = v2919->cache_tags;
    int v3170 = ((((int)((unsigned int)((int)((unsigned int)(v2925 + 68) >> 2)) >> 1)) & 1) * 2) + ((((v2946 + ((~(((v2948 ^ -1) | (-(v2948 ^ -1))) >> 31)) & 2)) - (v2949 + ((~(((v2950 ^ -1) | (-(v2950 ^ -1))) >> 31)) & 2))) >> 31) & 1);
    int v3171 = (int)((unsigned int)((int)((unsigned int)(v2925 + 68) >> 2)) >> 1);
    v3011[v3170] = v3171;
    int * v3013 = v2919->cache_dirty;
    v3013[v3170] = 0;
    int * v3015 = v2919->cache_age;
    v3015[v3170] = 1;
    int * v3017 = v2919->cache_age;
    int v3018 = v3017[v3170];
    int v3019 = v3017[v3099];
    int v3177 = v3019 + ((int)((unsigned int)(v3019 - v3018) >> 31));
    v3017[v3099] = v3177;
    int * v3021 = v2919->cache_age;
    int v3022 = v3021[v3100];
    int v3179 = v3022 + ((int)((unsigned int)(v3022 - v3018) >> 31));
    v3021[v3100] = v3179;
    int * v3024 = v2919->cache_age;
    v3024[v3170] = 0;
    v3027 = v3170;
  }
  int * v3028 = v2919->cache_vals;
  int v3182 = (v3027 * 2) + (((int)((unsigned int)(v2925 + 68) >> 2)) & 1);
  v3028[v3182] = v2927;
  int * v3030 = v2919->cache_tags;
  int v3031 = v3030[v3101];
  int v3032 = v3030[v3102];
  bool v3185 = !(((~(((v3031 ^ ((int)((unsigned int)((int)((unsigned int)(v2925 + 68) >> 2)) >> 1))) | (-(v3031 ^ ((int)((unsigned int)((int)((unsigned int)(v2925 + 68) >> 2)) >> 1))))) >> 31)) | (~(((v3032 ^ ((int)((unsigned int)((int)((unsigned int)(v2925 + 68) >> 2)) >> 1))) | (-(v3032 ^ ((int)((unsigned int)((int)((unsigned int)(v2925 + 68) >> 2)) >> 1))))) >> 31))) == 0);
  int v3086;
  if (v3185) {
    int * v3033 = v2919->cache_age;
    int v3187 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v2925 + 68) >> 2)) >> 1)) & 3) * 2)) + ((~(((v3032 ^ ((int)((unsigned int)((int)((unsigned int)(v2925 + 68) >> 2)) >> 1))) | (-(v3032 ^ ((int)((unsigned int)((int)((unsigned int)(v2925 + 68) >> 2)) >> 1))))) >> 31)) & 1);
    int v3034 = v3033[v3187];
    int v3035 = v3033[v3101];
    int v3188 = v3035 + ((int)((unsigned int)(v3035 - v3034) >> 31));
    v3033[v3101] = v3188;
    int * v3037 = v2919->cache_age;
    int v3038 = v3037[v3102];
    int v3190 = v3038 + ((int)((unsigned int)(v3038 - v3034) >> 31));
    v3037[v3102] = v3190;
    int * v3040 = v2919->cache_age;
    v3040[v3187] = 0;
    v3086 = v3187;
  } else {
    int * v3043 = v2919->cache_age;
    int v3194 = 4 + ((((int)((unsigned int)((int)((unsigned int)(v2925 + 68) >> 2)) >> 1)) & 3) * 2);
    int v3044 = v3043[v3194];
    int * v3045 = v2919->cache_tags;
    int v3046 = v3045[v3194];
    int v3047 = v3043[v3102];
    int v3048 = v3045[v3102];
    int * v3049 = v2919->cache_dirty;
    int v3197 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v2925 + 68) >> 2)) >> 1)) & 3) * 2)) + ((((v3044 + ((~(((v3046 ^ -1) | (-(v3046 ^ -1))) >> 31)) & 2)) - (v3047 + ((~(((v3048 ^ -1) | (-(v3048 ^ -1))) >> 31)) & 2))) >> 31) & 1);
    int v3050 = v3049[v3197];
    bool v3198 = !(v3050 == 0);
    if (v3198) {
      int * v3051 = v2919->cache_tags;
      int v3052 = v3051[v3197];
      int * v3053 = v2919->cache_vals;
      int v3201 = ((4 + ((((int)((unsigned int)((int)((unsigned int)(v2925 + 68) >> 2)) >> 1)) & 3) * 2)) + ((((v3044 + ((~(((v3046 ^ -1) | (-(v3046 ^ -1))) >> 31)) & 2)) - (v3047 + ((~(((v3048 ^ -1) | (-(v3048 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
      int v3054 = v3053[v3201];
      int v3202 = (((4 + ((((int)((unsigned int)((int)((unsigned int)(v2925 + 68) >> 2)) >> 1)) & 3) * 2)) + ((((v3044 + ((~(((v3046 ^ -1) | (-(v3046 ^ -1))) >> 31)) & 2)) - (v3047 + ((~(((v3048 ^ -1) | (-(v3048 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
      int v3055 = v3053[v3202];
      int * v3056 = v2919->mem;
      int v3204 = v3052 * 2;
      v3056[v3204] = v3054;
      int * v3058 = v2919->mem;
      int v3207 = (v3052 * 2) + 1;
      v3058[v3207] = v3055;
      ;
    } else {
      ;
    }
    int * v3063 = v2919->mem;
    int v3212 = ((int)((unsigned int)((int)((unsigned int)(v2925 + 68) >> 2)) >> 1)) * 2;
    int v3064 = v3063[v3212];
    int v3213 = (((int)((unsigned int)((int)((unsigned int)(v2925 + 68) >> 2)) >> 1)) * 2) + 1;
    int v3065 = v3063[v3213];
    int * v3066 = v2919->cache_vals;
    int v3215 = ((4 + ((((int)((unsigned int)((int)((unsigned int)(v2925 + 68) >> 2)) >> 1)) & 3) * 2)) + ((((v3044 + ((~(((v3046 ^ -1) | (-(v3046 ^ -1))) >> 31)) & 2)) - (v3047 + ((~(((v3048 ^ -1) | (-(v3048 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
    v3066[v3215] = v3064;
    int * v3068 = v2919->cache_vals;
    int v3218 = (((4 + ((((int)((unsigned int)((int)((unsigned int)(v2925 + 68) >> 2)) >> 1)) & 3) * 2)) + ((((v3044 + ((~(((v3046 ^ -1) | (-(v3046 ^ -1))) >> 31)) & 2)) - (v3047 + ((~(((v3048 ^ -1) | (-(v3048 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
    v3068[v3218] = v3065;
    int * v3070 = v2919->cache_tags;
    int v3221 = (int)((unsigned int)((int)((unsigned int)(v2925 + 68) >> 2)) >> 1);
    v3070[v3197] = v3221;
    int * v3072 = v2919->cache_dirty;
    v3072[v3197] = 0;
    int * v3074 = v2919->cache_age;
    v3074[v3197] = 1;
    int * v3076 = v2919->cache_age;
    int v3077 = v3076[v3197];
    int v3078 = v3076[v3101];
    int v3227 = v3078 + ((int)((unsigned int)(v3078 - v3077) >> 31));
    v3076[v3101] = v3227;
    int * v3080 = v2919->cache_age;
    int v3081 = v3080[v3102];
    int v3229 = v3081 + ((int)((unsigned int)(v3081 - v3077) >> 31));
    v3080[v3102] = v3229;
    int * v3083 = v2919->cache_age;
    v3083[v3197] = 0;
    v3086 = v3197;
  }
  int * v3087 = v2919->cache_vals;
  int v3232 = (v3086 * 2) + (((int)((unsigned int)(v2925 + 68) >> 2)) & 1);
  v3087[v3232] = v2927;
  int * v3089 = v2919->cache_dirty;
  v3089[v3086] = 1;
  struct StateT * v3091 = slot_33(v2919);
  return v3091;
}

struct StateT * slot_3(struct StateT * v233) {
  int * v234 = v233->saved_regs;
  int * v235 = v233->regs;
  int v236 = v235[10];
  v234[10] = v236;
  int v238 = v233->timer;
  int v253 = v238 + 1;
  v233->timer = v253;
  int * v240 = v233->reg_ready;
  int v241 = v240[10];
  int * v242 = v233->regs;
  int v243 = v242[10];
  int v256 = (v241 + ((v238 - v241) & (~((v238 - v241) >> 31)))) + 1;
  v240[10] = v256;
  int * v245 = v233->regs;
  int v258 = v243 << 2;
  v245[10] = v258;
  struct StateT * v247 = slot_4(v233);
  return v247;
}

struct StateT * slot_10(struct StateT * v573) {
  int * v574 = v573->saved_regs;
  int * v575 = v573->regs;
  int v576 = v575[12];
  v574[12] = v576;
  int v578 = v573->timer;
  int v590 = v578 + 1;
  v573->timer = v590;
  int * v580 = v573->reg_ready;
  v580[12] = v590;
  int * v582 = v573->regs;
  v582[12] = 0;
  struct StateT * v584 = slot_11(v573);
  return v584;
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

struct StateT * slot_19(struct StateT * v1350) {
  int v1351 = v1350->timer;
  int v1524 = v1351 + 1;
  v1350->timer = v1524;
  int * v1353 = v1350->reg_ready;
  int * v1355 = v1350->regs;
  int v1356 = v1355[12];
  int v1358 = v1355[10];
  int * v1359 = v1350->cache_tags;
  int v1530 = (((int)((unsigned int)((int)((unsigned int)(v1356 + 68) >> 2)) >> 1)) & 1) * 2;
  int v1360 = v1359[v1530];
  int v1531 = ((((int)((unsigned int)((int)((unsigned int)(v1356 + 68) >> 2)) >> 1)) & 1) * 2) + 1;
  int v1361 = v1359[v1531];
  int v1532 = 4 + ((((int)((unsigned int)((int)((unsigned int)(v1356 + 68) >> 2)) >> 1)) & 3) * 2);
  int v1362 = v1359[v1532];
  int v1533 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v1356 + 68) >> 2)) >> 1)) & 3) * 2)) + 1;
  int v1363 = v1359[v1533];
  int v1364 = v1350->timer;
  int v1534 = v1364 + ((100 ^ (((~(((v1362 ^ ((int)((unsigned int)((int)((unsigned int)(v1356 + 68) >> 2)) >> 1))) | (-(v1362 ^ ((int)((unsigned int)((int)((unsigned int)(v1356 + 68) >> 2)) >> 1))))) >> 31)) | (~(((v1363 ^ ((int)((unsigned int)((int)((unsigned int)(v1356 + 68) >> 2)) >> 1))) | (-(v1363 ^ ((int)((unsigned int)((int)((unsigned int)(v1356 + 68) >> 2)) >> 1))))) >> 31))) & 104)) ^ (((~(((v1360 ^ ((int)((unsigned int)((int)((unsigned int)(v1356 + 68) >> 2)) >> 1))) | (-(v1360 ^ ((int)((unsigned int)((int)((unsigned int)(v1356 + 68) >> 2)) >> 1))))) >> 31)) | (~(((v1361 ^ ((int)((unsigned int)((int)((unsigned int)(v1356 + 68) >> 2)) >> 1))) | (-(v1361 ^ ((int)((unsigned int)((int)((unsigned int)(v1356 + 68) >> 2)) >> 1))))) >> 31))) & (1 ^ (100 ^ (((~(((v1362 ^ ((int)((unsigned int)((int)((unsigned int)(v1356 + 68) >> 2)) >> 1))) | (-(v1362 ^ ((int)((unsigned int)((int)((unsigned int)(v1356 + 68) >> 2)) >> 1))))) >> 31)) | (~(((v1363 ^ ((int)((unsigned int)((int)((unsigned int)(v1356 + 68) >> 2)) >> 1))) | (-(v1363 ^ ((int)((unsigned int)((int)((unsigned int)(v1356 + 68) >> 2)) >> 1))))) >> 31))) & 104)))));
  v1350->timer = v1534;
  bool v1535 = !(((~(((v1360 ^ ((int)((unsigned int)((int)((unsigned int)(v1356 + 68) >> 2)) >> 1))) | (-(v1360 ^ ((int)((unsigned int)((int)((unsigned int)(v1356 + 68) >> 2)) >> 1))))) >> 31)) | (~(((v1361 ^ ((int)((unsigned int)((int)((unsigned int)(v1356 + 68) >> 2)) >> 1))) | (-(v1361 ^ ((int)((unsigned int)((int)((unsigned int)(v1356 + 68) >> 2)) >> 1))))) >> 31))) == 0);
  int v1458;
  if (v1535) {
    int * v1366 = v1350->cache_age;
    int v1537 = ((((int)((unsigned int)((int)((unsigned int)(v1356 + 68) >> 2)) >> 1)) & 1) * 2) + ((~(((v1361 ^ ((int)((unsigned int)((int)((unsigned int)(v1356 + 68) >> 2)) >> 1))) | (-(v1361 ^ ((int)((unsigned int)((int)((unsigned int)(v1356 + 68) >> 2)) >> 1))))) >> 31)) & 1);
    int v1367 = v1366[v1537];
    int v1368 = v1366[v1530];
    int v1538 = v1368 + ((int)((unsigned int)(v1368 - v1367) >> 31));
    v1366[v1530] = v1538;
    int * v1370 = v1350->cache_age;
    int v1371 = v1370[v1531];
    int v1540 = v1371 + ((int)((unsigned int)(v1371 - v1367) >> 31));
    v1370[v1531] = v1540;
    int * v1373 = v1350->cache_age;
    v1373[v1537] = 0;
    v1458 = v1537;
  } else {
    int * v1376 = v1350->cache_age;
    int v1544 = (((int)((unsigned int)((int)((unsigned int)(v1356 + 68) >> 2)) >> 1)) & 1) * 2;
    int v1377 = v1376[v1544];
    int * v1378 = v1350->cache_tags;
    int v1379 = v1378[v1544];
    int v1380 = v1376[v1531];
    int v1381 = v1378[v1531];
    bool v1546 = !(((~(((v1362 ^ ((int)((unsigned int)((int)((unsigned int)(v1356 + 68) >> 2)) >> 1))) | (-(v1362 ^ ((int)((unsigned int)((int)((unsigned int)(v1356 + 68) >> 2)) >> 1))))) >> 31)) | (~(((v1363 ^ ((int)((unsigned int)((int)((unsigned int)(v1356 + 68) >> 2)) >> 1))) | (-(v1363 ^ ((int)((unsigned int)((int)((unsigned int)(v1356 + 68) >> 2)) >> 1))))) >> 31))) == 0);
    int v1435;
    if (v1546) {
      int * v1382 = v1350->cache_age;
      int v1548 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v1356 + 68) >> 2)) >> 1)) & 3) * 2)) + ((~(((v1363 ^ ((int)((unsigned int)((int)((unsigned int)(v1356 + 68) >> 2)) >> 1))) | (-(v1363 ^ ((int)((unsigned int)((int)((unsigned int)(v1356 + 68) >> 2)) >> 1))))) >> 31)) & 1);
      int v1383 = v1382[v1548];
      int v1384 = v1382[v1532];
      int v1549 = v1384 + ((int)((unsigned int)(v1384 - v1383) >> 31));
      v1382[v1532] = v1549;
      int * v1386 = v1350->cache_age;
      int v1387 = v1386[v1533];
      int v1551 = v1387 + ((int)((unsigned int)(v1387 - v1383) >> 31));
      v1386[v1533] = v1551;
      int * v1389 = v1350->cache_age;
      v1389[v1548] = 0;
      v1435 = v1548;
    } else {
      int * v1392 = v1350->cache_age;
      int v1555 = 4 + ((((int)((unsigned int)((int)((unsigned int)(v1356 + 68) >> 2)) >> 1)) & 3) * 2);
      int v1393 = v1392[v1555];
      int * v1394 = v1350->cache_tags;
      int v1395 = v1394[v1555];
      int v1396 = v1392[v1533];
      int v1397 = v1394[v1533];
      int * v1398 = v1350->cache_dirty;
      int v1558 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v1356 + 68) >> 2)) >> 1)) & 3) * 2)) + ((((v1393 + ((~(((v1395 ^ -1) | (-(v1395 ^ -1))) >> 31)) & 2)) - (v1396 + ((~(((v1397 ^ -1) | (-(v1397 ^ -1))) >> 31)) & 2))) >> 31) & 1);
      int v1399 = v1398[v1558];
      bool v1559 = !(v1399 == 0);
      if (v1559) {
        int * v1400 = v1350->cache_tags;
        int v1401 = v1400[v1558];
        int * v1402 = v1350->cache_vals;
        int v1562 = ((4 + ((((int)((unsigned int)((int)((unsigned int)(v1356 + 68) >> 2)) >> 1)) & 3) * 2)) + ((((v1393 + ((~(((v1395 ^ -1) | (-(v1395 ^ -1))) >> 31)) & 2)) - (v1396 + ((~(((v1397 ^ -1) | (-(v1397 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
        int v1403 = v1402[v1562];
        int v1563 = (((4 + ((((int)((unsigned int)((int)((unsigned int)(v1356 + 68) >> 2)) >> 1)) & 3) * 2)) + ((((v1393 + ((~(((v1395 ^ -1) | (-(v1395 ^ -1))) >> 31)) & 2)) - (v1396 + ((~(((v1397 ^ -1) | (-(v1397 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
        int v1404 = v1402[v1563];
        int * v1405 = v1350->mem;
        int v1565 = v1401 * 2;
        v1405[v1565] = v1403;
        int * v1407 = v1350->mem;
        int v1568 = (v1401 * 2) + 1;
        v1407[v1568] = v1404;
        ;
      } else {
        ;
      }
      int * v1412 = v1350->mem;
      int v1573 = ((int)((unsigned int)((int)((unsigned int)(v1356 + 68) >> 2)) >> 1)) * 2;
      int v1413 = v1412[v1573];
      int v1574 = (((int)((unsigned int)((int)((unsigned int)(v1356 + 68) >> 2)) >> 1)) * 2) + 1;
      int v1414 = v1412[v1574];
      int * v1415 = v1350->cache_vals;
      int v1576 = ((4 + ((((int)((unsigned int)((int)((unsigned int)(v1356 + 68) >> 2)) >> 1)) & 3) * 2)) + ((((v1393 + ((~(((v1395 ^ -1) | (-(v1395 ^ -1))) >> 31)) & 2)) - (v1396 + ((~(((v1397 ^ -1) | (-(v1397 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
      v1415[v1576] = v1413;
      int * v1417 = v1350->cache_vals;
      int v1579 = (((4 + ((((int)((unsigned int)((int)((unsigned int)(v1356 + 68) >> 2)) >> 1)) & 3) * 2)) + ((((v1393 + ((~(((v1395 ^ -1) | (-(v1395 ^ -1))) >> 31)) & 2)) - (v1396 + ((~(((v1397 ^ -1) | (-(v1397 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
      v1417[v1579] = v1414;
      int * v1419 = v1350->cache_tags;
      int v1582 = (int)((unsigned int)((int)((unsigned int)(v1356 + 68) >> 2)) >> 1);
      v1419[v1558] = v1582;
      int * v1421 = v1350->cache_dirty;
      v1421[v1558] = 0;
      int * v1423 = v1350->cache_age;
      v1423[v1558] = 1;
      int * v1425 = v1350->cache_age;
      int v1426 = v1425[v1558];
      int v1427 = v1425[v1532];
      int v1588 = v1427 + ((int)((unsigned int)(v1427 - v1426) >> 31));
      v1425[v1532] = v1588;
      int * v1429 = v1350->cache_age;
      int v1430 = v1429[v1533];
      int v1590 = v1430 + ((int)((unsigned int)(v1430 - v1426) >> 31));
      v1429[v1533] = v1590;
      int * v1432 = v1350->cache_age;
      v1432[v1558] = 0;
      v1435 = v1558;
    }
    int * v1436 = v1350->cache_vals;
    int v1593 = v1435 * 2;
    int v1437 = v1436[v1593];
    int v1594 = (v1435 * 2) + 1;
    int v1438 = v1436[v1594];
    int v1595 = (((((int)((unsigned int)((int)((unsigned int)(v1356 + 68) >> 2)) >> 1)) & 1) * 2) + ((((v1377 + ((~(((v1379 ^ -1) | (-(v1379 ^ -1))) >> 31)) & 2)) - (v1380 + ((~(((v1381 ^ -1) | (-(v1381 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
    v1436[v1595] = v1437;
    int * v1440 = v1350->cache_vals;
    int v1598 = ((((((int)((unsigned int)((int)((unsigned int)(v1356 + 68) >> 2)) >> 1)) & 1) * 2) + ((((v1377 + ((~(((v1379 ^ -1) | (-(v1379 ^ -1))) >> 31)) & 2)) - (v1380 + ((~(((v1381 ^ -1) | (-(v1381 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
    v1440[v1598] = v1438;
    int * v1442 = v1350->cache_tags;
    int v1601 = ((((int)((unsigned int)((int)((unsigned int)(v1356 + 68) >> 2)) >> 1)) & 1) * 2) + ((((v1377 + ((~(((v1379 ^ -1) | (-(v1379 ^ -1))) >> 31)) & 2)) - (v1380 + ((~(((v1381 ^ -1) | (-(v1381 ^ -1))) >> 31)) & 2))) >> 31) & 1);
    int v1602 = (int)((unsigned int)((int)((unsigned int)(v1356 + 68) >> 2)) >> 1);
    v1442[v1601] = v1602;
    int * v1444 = v1350->cache_dirty;
    v1444[v1601] = 0;
    int * v1446 = v1350->cache_age;
    v1446[v1601] = 1;
    int * v1448 = v1350->cache_age;
    int v1449 = v1448[v1601];
    int v1450 = v1448[v1530];
    int v1608 = v1450 + ((int)((unsigned int)(v1450 - v1449) >> 31));
    v1448[v1530] = v1608;
    int * v1452 = v1350->cache_age;
    int v1453 = v1452[v1531];
    int v1610 = v1453 + ((int)((unsigned int)(v1453 - v1449) >> 31));
    v1452[v1531] = v1610;
    int * v1455 = v1350->cache_age;
    v1455[v1601] = 0;
    v1458 = v1601;
  }
  int * v1459 = v1350->cache_vals;
  int v1613 = (v1458 * 2) + (((int)((unsigned int)(v1356 + 68) >> 2)) & 1);
  v1459[v1613] = v1358;
  int * v1461 = v1350->cache_tags;
  int v1462 = v1461[v1532];
  int v1463 = v1461[v1533];
  bool v1616 = !(((~(((v1462 ^ ((int)((unsigned int)((int)((unsigned int)(v1356 + 68) >> 2)) >> 1))) | (-(v1462 ^ ((int)((unsigned int)((int)((unsigned int)(v1356 + 68) >> 2)) >> 1))))) >> 31)) | (~(((v1463 ^ ((int)((unsigned int)((int)((unsigned int)(v1356 + 68) >> 2)) >> 1))) | (-(v1463 ^ ((int)((unsigned int)((int)((unsigned int)(v1356 + 68) >> 2)) >> 1))))) >> 31))) == 0);
  int v1517;
  if (v1616) {
    int * v1464 = v1350->cache_age;
    int v1618 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v1356 + 68) >> 2)) >> 1)) & 3) * 2)) + ((~(((v1463 ^ ((int)((unsigned int)((int)((unsigned int)(v1356 + 68) >> 2)) >> 1))) | (-(v1463 ^ ((int)((unsigned int)((int)((unsigned int)(v1356 + 68) >> 2)) >> 1))))) >> 31)) & 1);
    int v1465 = v1464[v1618];
    int v1466 = v1464[v1532];
    int v1619 = v1466 + ((int)((unsigned int)(v1466 - v1465) >> 31));
    v1464[v1532] = v1619;
    int * v1468 = v1350->cache_age;
    int v1469 = v1468[v1533];
    int v1621 = v1469 + ((int)((unsigned int)(v1469 - v1465) >> 31));
    v1468[v1533] = v1621;
    int * v1471 = v1350->cache_age;
    v1471[v1618] = 0;
    v1517 = v1618;
  } else {
    int * v1474 = v1350->cache_age;
    int v1625 = 4 + ((((int)((unsigned int)((int)((unsigned int)(v1356 + 68) >> 2)) >> 1)) & 3) * 2);
    int v1475 = v1474[v1625];
    int * v1476 = v1350->cache_tags;
    int v1477 = v1476[v1625];
    int v1478 = v1474[v1533];
    int v1479 = v1476[v1533];
    int * v1480 = v1350->cache_dirty;
    int v1628 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v1356 + 68) >> 2)) >> 1)) & 3) * 2)) + ((((v1475 + ((~(((v1477 ^ -1) | (-(v1477 ^ -1))) >> 31)) & 2)) - (v1478 + ((~(((v1479 ^ -1) | (-(v1479 ^ -1))) >> 31)) & 2))) >> 31) & 1);
    int v1481 = v1480[v1628];
    bool v1629 = !(v1481 == 0);
    if (v1629) {
      int * v1482 = v1350->cache_tags;
      int v1483 = v1482[v1628];
      int * v1484 = v1350->cache_vals;
      int v1632 = ((4 + ((((int)((unsigned int)((int)((unsigned int)(v1356 + 68) >> 2)) >> 1)) & 3) * 2)) + ((((v1475 + ((~(((v1477 ^ -1) | (-(v1477 ^ -1))) >> 31)) & 2)) - (v1478 + ((~(((v1479 ^ -1) | (-(v1479 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
      int v1485 = v1484[v1632];
      int v1633 = (((4 + ((((int)((unsigned int)((int)((unsigned int)(v1356 + 68) >> 2)) >> 1)) & 3) * 2)) + ((((v1475 + ((~(((v1477 ^ -1) | (-(v1477 ^ -1))) >> 31)) & 2)) - (v1478 + ((~(((v1479 ^ -1) | (-(v1479 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
      int v1486 = v1484[v1633];
      int * v1487 = v1350->mem;
      int v1635 = v1483 * 2;
      v1487[v1635] = v1485;
      int * v1489 = v1350->mem;
      int v1638 = (v1483 * 2) + 1;
      v1489[v1638] = v1486;
      ;
    } else {
      ;
    }
    int * v1494 = v1350->mem;
    int v1643 = ((int)((unsigned int)((int)((unsigned int)(v1356 + 68) >> 2)) >> 1)) * 2;
    int v1495 = v1494[v1643];
    int v1644 = (((int)((unsigned int)((int)((unsigned int)(v1356 + 68) >> 2)) >> 1)) * 2) + 1;
    int v1496 = v1494[v1644];
    int * v1497 = v1350->cache_vals;
    int v1646 = ((4 + ((((int)((unsigned int)((int)((unsigned int)(v1356 + 68) >> 2)) >> 1)) & 3) * 2)) + ((((v1475 + ((~(((v1477 ^ -1) | (-(v1477 ^ -1))) >> 31)) & 2)) - (v1478 + ((~(((v1479 ^ -1) | (-(v1479 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
    v1497[v1646] = v1495;
    int * v1499 = v1350->cache_vals;
    int v1649 = (((4 + ((((int)((unsigned int)((int)((unsigned int)(v1356 + 68) >> 2)) >> 1)) & 3) * 2)) + ((((v1475 + ((~(((v1477 ^ -1) | (-(v1477 ^ -1))) >> 31)) & 2)) - (v1478 + ((~(((v1479 ^ -1) | (-(v1479 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
    v1499[v1649] = v1496;
    int * v1501 = v1350->cache_tags;
    int v1652 = (int)((unsigned int)((int)((unsigned int)(v1356 + 68) >> 2)) >> 1);
    v1501[v1628] = v1652;
    int * v1503 = v1350->cache_dirty;
    v1503[v1628] = 0;
    int * v1505 = v1350->cache_age;
    v1505[v1628] = 1;
    int * v1507 = v1350->cache_age;
    int v1508 = v1507[v1628];
    int v1509 = v1507[v1532];
    int v1658 = v1509 + ((int)((unsigned int)(v1509 - v1508) >> 31));
    v1507[v1532] = v1658;
    int * v1511 = v1350->cache_age;
    int v1512 = v1511[v1533];
    int v1660 = v1512 + ((int)((unsigned int)(v1512 - v1508) >> 31));
    v1511[v1533] = v1660;
    int * v1514 = v1350->cache_age;
    v1514[v1628] = 0;
    v1517 = v1628;
  }
  int * v1518 = v1350->cache_vals;
  int v1663 = (v1517 * 2) + (((int)((unsigned int)(v1356 + 68) >> 2)) & 1);
  v1518[v1663] = v1358;
  int * v1520 = v1350->cache_dirty;
  v1520[v1517] = 1;
  struct StateT * v1522 = slot_21(v1350);
  return v1522;
}

struct StateT * slot_13(struct StateT * v638) {
  int v639 = v638->timer;
  int v652 = v639 + 1;
  v638->timer = v652;
  int * v641 = v638->reg_ready;
  int v642 = v641[11];
  int * v643 = v638->regs;
  int v644 = v643[11];
  int v645 = v641[10];
  int v646 = v643[10];
  int v657 = (v645 + (((v642 + ((v639 - v642) & (~((v639 - v642) >> 31)))) - v645) & (~(((v642 + ((v639 - v642) & (~((v639 - v642) >> 31)))) - v645) >> 31)))) + 1;
  v641[10] = v657;
  int * v648 = v638->regs;
  int v659 = v644 + v646;
  v648[10] = v659;
  struct StateT * v650 = slot_14(v638);
  return v650;
}

struct StateT * slot_24(struct StateT * v1924) {
  int v1925 = v1924->timer;
  int v2037 = v1925 + 1;
  v1924->timer = v2037;
  int * v1927 = v1924->reg_ready;
  int v1928 = v1927[11];
  int * v1929 = v1924->regs;
  int v1930 = v1929[11];
  int * v1931 = v1924->cache_tags;
  int v2042 = (((int)((unsigned int)((int)((unsigned int)(v1930 + 68) >> 2)) >> 1)) & 1) * 2;
  int v1932 = v1931[v2042];
  int v2043 = ((((int)((unsigned int)((int)((unsigned int)(v1930 + 68) >> 2)) >> 1)) & 1) * 2) + 1;
  int v1933 = v1931[v2043];
  int v2044 = 4 + ((((int)((unsigned int)((int)((unsigned int)(v1930 + 68) >> 2)) >> 1)) & 3) * 2);
  int v1934 = v1931[v2044];
  int v2045 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v1930 + 68) >> 2)) >> 1)) & 3) * 2)) + 1;
  int v1935 = v1931[v2045];
  int * v1936 = v1924->cache_vals;
  bool v2046 = !(((~(((v1932 ^ ((int)((unsigned int)((int)((unsigned int)(v1930 + 68) >> 2)) >> 1))) | (-(v1932 ^ ((int)((unsigned int)((int)((unsigned int)(v1930 + 68) >> 2)) >> 1))))) >> 31)) | (~(((v1933 ^ ((int)((unsigned int)((int)((unsigned int)(v1930 + 68) >> 2)) >> 1))) | (-(v1933 ^ ((int)((unsigned int)((int)((unsigned int)(v1930 + 68) >> 2)) >> 1))))) >> 31))) == 0);
  int v2029;
  if (v2046) {
    int * v1937 = v1924->cache_age;
    int v2048 = ((((int)((unsigned int)((int)((unsigned int)(v1930 + 68) >> 2)) >> 1)) & 1) * 2) + ((~(((v1933 ^ ((int)((unsigned int)((int)((unsigned int)(v1930 + 68) >> 2)) >> 1))) | (-(v1933 ^ ((int)((unsigned int)((int)((unsigned int)(v1930 + 68) >> 2)) >> 1))))) >> 31)) & 1);
    int v1938 = v1937[v2048];
    int v1939 = v1937[v2042];
    int v2049 = v1939 + ((int)((unsigned int)(v1939 - v1938) >> 31));
    v1937[v2042] = v2049;
    int * v1941 = v1924->cache_age;
    int v1942 = v1941[v2043];
    int v2051 = v1942 + ((int)((unsigned int)(v1942 - v1938) >> 31));
    v1941[v2043] = v2051;
    int * v1944 = v1924->cache_age;
    v1944[v2048] = 0;
    v2029 = v2048;
  } else {
    int * v1947 = v1924->cache_age;
    int v2055 = (((int)((unsigned int)((int)((unsigned int)(v1930 + 68) >> 2)) >> 1)) & 1) * 2;
    int v1948 = v1947[v2055];
    int * v1949 = v1924->cache_tags;
    int v1950 = v1949[v2055];
    int v1951 = v1947[v2043];
    int v1952 = v1949[v2043];
    bool v2057 = !(((~(((v1934 ^ ((int)((unsigned int)((int)((unsigned int)(v1930 + 68) >> 2)) >> 1))) | (-(v1934 ^ ((int)((unsigned int)((int)((unsigned int)(v1930 + 68) >> 2)) >> 1))))) >> 31)) | (~(((v1935 ^ ((int)((unsigned int)((int)((unsigned int)(v1930 + 68) >> 2)) >> 1))) | (-(v1935 ^ ((int)((unsigned int)((int)((unsigned int)(v1930 + 68) >> 2)) >> 1))))) >> 31))) == 0);
    int v2006;
    if (v2057) {
      int * v1953 = v1924->cache_age;
      int v2059 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v1930 + 68) >> 2)) >> 1)) & 3) * 2)) + ((~(((v1935 ^ ((int)((unsigned int)((int)((unsigned int)(v1930 + 68) >> 2)) >> 1))) | (-(v1935 ^ ((int)((unsigned int)((int)((unsigned int)(v1930 + 68) >> 2)) >> 1))))) >> 31)) & 1);
      int v1954 = v1953[v2059];
      int v1955 = v1953[v2044];
      int v2060 = v1955 + ((int)((unsigned int)(v1955 - v1954) >> 31));
      v1953[v2044] = v2060;
      int * v1957 = v1924->cache_age;
      int v1958 = v1957[v2045];
      int v2062 = v1958 + ((int)((unsigned int)(v1958 - v1954) >> 31));
      v1957[v2045] = v2062;
      int * v1960 = v1924->cache_age;
      v1960[v2059] = 0;
      v2006 = v2059;
    } else {
      int * v1963 = v1924->cache_age;
      int v2066 = 4 + ((((int)((unsigned int)((int)((unsigned int)(v1930 + 68) >> 2)) >> 1)) & 3) * 2);
      int v1964 = v1963[v2066];
      int * v1965 = v1924->cache_tags;
      int v1966 = v1965[v2066];
      int v1967 = v1963[v2045];
      int v1968 = v1965[v2045];
      int * v1969 = v1924->cache_dirty;
      int v2069 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v1930 + 68) >> 2)) >> 1)) & 3) * 2)) + ((((v1964 + ((~(((v1966 ^ -1) | (-(v1966 ^ -1))) >> 31)) & 2)) - (v1967 + ((~(((v1968 ^ -1) | (-(v1968 ^ -1))) >> 31)) & 2))) >> 31) & 1);
      int v1970 = v1969[v2069];
      bool v2070 = !(v1970 == 0);
      if (v2070) {
        int * v1971 = v1924->cache_tags;
        int v1972 = v1971[v2069];
        int * v1973 = v1924->cache_vals;
        int v2073 = ((4 + ((((int)((unsigned int)((int)((unsigned int)(v1930 + 68) >> 2)) >> 1)) & 3) * 2)) + ((((v1964 + ((~(((v1966 ^ -1) | (-(v1966 ^ -1))) >> 31)) & 2)) - (v1967 + ((~(((v1968 ^ -1) | (-(v1968 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
        int v1974 = v1973[v2073];
        int v2074 = (((4 + ((((int)((unsigned int)((int)((unsigned int)(v1930 + 68) >> 2)) >> 1)) & 3) * 2)) + ((((v1964 + ((~(((v1966 ^ -1) | (-(v1966 ^ -1))) >> 31)) & 2)) - (v1967 + ((~(((v1968 ^ -1) | (-(v1968 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
        int v1975 = v1973[v2074];
        int * v1976 = v1924->mem;
        int v2076 = v1972 * 2;
        v1976[v2076] = v1974;
        int * v1978 = v1924->mem;
        int v2079 = (v1972 * 2) + 1;
        v1978[v2079] = v1975;
        ;
      } else {
        ;
      }
      int * v1983 = v1924->mem;
      int v2084 = ((int)((unsigned int)((int)((unsigned int)(v1930 + 68) >> 2)) >> 1)) * 2;
      int v1984 = v1983[v2084];
      int v2085 = (((int)((unsigned int)((int)((unsigned int)(v1930 + 68) >> 2)) >> 1)) * 2) + 1;
      int v1985 = v1983[v2085];
      int * v1986 = v1924->cache_vals;
      int v2087 = ((4 + ((((int)((unsigned int)((int)((unsigned int)(v1930 + 68) >> 2)) >> 1)) & 3) * 2)) + ((((v1964 + ((~(((v1966 ^ -1) | (-(v1966 ^ -1))) >> 31)) & 2)) - (v1967 + ((~(((v1968 ^ -1) | (-(v1968 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
      v1986[v2087] = v1984;
      int * v1988 = v1924->cache_vals;
      int v2090 = (((4 + ((((int)((unsigned int)((int)((unsigned int)(v1930 + 68) >> 2)) >> 1)) & 3) * 2)) + ((((v1964 + ((~(((v1966 ^ -1) | (-(v1966 ^ -1))) >> 31)) & 2)) - (v1967 + ((~(((v1968 ^ -1) | (-(v1968 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
      v1988[v2090] = v1985;
      int * v1990 = v1924->cache_tags;
      int v2093 = (int)((unsigned int)((int)((unsigned int)(v1930 + 68) >> 2)) >> 1);
      v1990[v2069] = v2093;
      int * v1992 = v1924->cache_dirty;
      v1992[v2069] = 0;
      int * v1994 = v1924->cache_age;
      v1994[v2069] = 1;
      int * v1996 = v1924->cache_age;
      int v1997 = v1996[v2069];
      int v1998 = v1996[v2044];
      int v2099 = v1998 + ((int)((unsigned int)(v1998 - v1997) >> 31));
      v1996[v2044] = v2099;
      int * v2000 = v1924->cache_age;
      int v2001 = v2000[v2045];
      int v2101 = v2001 + ((int)((unsigned int)(v2001 - v1997) >> 31));
      v2000[v2045] = v2101;
      int * v2003 = v1924->cache_age;
      v2003[v2069] = 0;
      v2006 = v2069;
    }
    int * v2007 = v1924->cache_vals;
    int v2104 = v2006 * 2;
    int v2008 = v2007[v2104];
    int v2105 = (v2006 * 2) + 1;
    int v2009 = v2007[v2105];
    int v2106 = (((((int)((unsigned int)((int)((unsigned int)(v1930 + 68) >> 2)) >> 1)) & 1) * 2) + ((((v1948 + ((~(((v1950 ^ -1) | (-(v1950 ^ -1))) >> 31)) & 2)) - (v1951 + ((~(((v1952 ^ -1) | (-(v1952 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
    v2007[v2106] = v2008;
    int * v2011 = v1924->cache_vals;
    int v2109 = ((((((int)((unsigned int)((int)((unsigned int)(v1930 + 68) >> 2)) >> 1)) & 1) * 2) + ((((v1948 + ((~(((v1950 ^ -1) | (-(v1950 ^ -1))) >> 31)) & 2)) - (v1951 + ((~(((v1952 ^ -1) | (-(v1952 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
    v2011[v2109] = v2009;
    int * v2013 = v1924->cache_tags;
    int v2112 = ((((int)((unsigned int)((int)((unsigned int)(v1930 + 68) >> 2)) >> 1)) & 1) * 2) + ((((v1948 + ((~(((v1950 ^ -1) | (-(v1950 ^ -1))) >> 31)) & 2)) - (v1951 + ((~(((v1952 ^ -1) | (-(v1952 ^ -1))) >> 31)) & 2))) >> 31) & 1);
    int v2113 = (int)((unsigned int)((int)((unsigned int)(v1930 + 68) >> 2)) >> 1);
    v2013[v2112] = v2113;
    int * v2015 = v1924->cache_dirty;
    v2015[v2112] = 0;
    int * v2017 = v1924->cache_age;
    v2017[v2112] = 1;
    int * v2019 = v1924->cache_age;
    int v2020 = v2019[v2112];
    int v2021 = v2019[v2042];
    int v2119 = v2021 + ((int)((unsigned int)(v2021 - v2020) >> 31));
    v2019[v2042] = v2119;
    int * v2023 = v1924->cache_age;
    int v2024 = v2023[v2043];
    int v2121 = v2024 + ((int)((unsigned int)(v2024 - v2020) >> 31));
    v2023[v2043] = v2121;
    int * v2026 = v1924->cache_age;
    v2026[v2112] = 0;
    v2029 = v2112;
  }
  int v2124 = (v2029 * 2) + (((int)((unsigned int)(v1930 + 68) >> 2)) & 1);
  int v2030 = v1936[v2124];
  int * v2031 = v1924->reg_ready;
  int v2127 = ((v1928 + ((v1925 - v1928) & (~((v1925 - v1928) >> 31)))) + 1) + ((100 ^ (((~(((v1934 ^ ((int)((unsigned int)((int)((unsigned int)(v1930 + 68) >> 2)) >> 1))) | (-(v1934 ^ ((int)((unsigned int)((int)((unsigned int)(v1930 + 68) >> 2)) >> 1))))) >> 31)) | (~(((v1935 ^ ((int)((unsigned int)((int)((unsigned int)(v1930 + 68) >> 2)) >> 1))) | (-(v1935 ^ ((int)((unsigned int)((int)((unsigned int)(v1930 + 68) >> 2)) >> 1))))) >> 31))) & 104)) ^ (((~(((v1932 ^ ((int)((unsigned int)((int)((unsigned int)(v1930 + 68) >> 2)) >> 1))) | (-(v1932 ^ ((int)((unsigned int)((int)((unsigned int)(v1930 + 68) >> 2)) >> 1))))) >> 31)) | (~(((v1933 ^ ((int)((unsigned int)((int)((unsigned int)(v1930 + 68) >> 2)) >> 1))) | (-(v1933 ^ ((int)((unsigned int)((int)((unsigned int)(v1930 + 68) >> 2)) >> 1))))) >> 31))) & (1 ^ (100 ^ (((~(((v1934 ^ ((int)((unsigned int)((int)((unsigned int)(v1930 + 68) >> 2)) >> 1))) | (-(v1934 ^ ((int)((unsigned int)((int)((unsigned int)(v1930 + 68) >> 2)) >> 1))))) >> 31)) | (~(((v1935 ^ ((int)((unsigned int)((int)((unsigned int)(v1930 + 68) >> 2)) >> 1))) | (-(v1935 ^ ((int)((unsigned int)((int)((unsigned int)(v1930 + 68) >> 2)) >> 1))))) >> 31))) & 104)))));
  v2031[12] = v2127;
  int * v2033 = v1924->regs;
  v2033[12] = v2030;
  struct StateT * v2035 = slot_29(v1924);
  return v2035;
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

struct StateT * slot_14(struct StateT * v662) {
  int v663 = v662->timer;
  int v775 = v663 + 1;
  v662->timer = v775;
  int * v665 = v662->reg_ready;
  int v666 = v665[10];
  int * v667 = v662->regs;
  int v668 = v667[10];
  int * v669 = v662->cache_tags;
  int v780 = (((int)((unsigned int)((int)((unsigned int)v668 >> 2)) >> 1)) & 1) * 2;
  int v670 = v669[v780];
  int v781 = ((((int)((unsigned int)((int)((unsigned int)v668 >> 2)) >> 1)) & 1) * 2) + 1;
  int v671 = v669[v781];
  int v782 = 4 + ((((int)((unsigned int)((int)((unsigned int)v668 >> 2)) >> 1)) & 3) * 2);
  int v672 = v669[v782];
  int v783 = (4 + ((((int)((unsigned int)((int)((unsigned int)v668 >> 2)) >> 1)) & 3) * 2)) + 1;
  int v673 = v669[v783];
  int * v674 = v662->cache_vals;
  bool v784 = !(((~(((v670 ^ ((int)((unsigned int)((int)((unsigned int)v668 >> 2)) >> 1))) | (-(v670 ^ ((int)((unsigned int)((int)((unsigned int)v668 >> 2)) >> 1))))) >> 31)) | (~(((v671 ^ ((int)((unsigned int)((int)((unsigned int)v668 >> 2)) >> 1))) | (-(v671 ^ ((int)((unsigned int)((int)((unsigned int)v668 >> 2)) >> 1))))) >> 31))) == 0);
  int v767;
  if (v784) {
    int * v675 = v662->cache_age;
    int v786 = ((((int)((unsigned int)((int)((unsigned int)v668 >> 2)) >> 1)) & 1) * 2) + ((~(((v671 ^ ((int)((unsigned int)((int)((unsigned int)v668 >> 2)) >> 1))) | (-(v671 ^ ((int)((unsigned int)((int)((unsigned int)v668 >> 2)) >> 1))))) >> 31)) & 1);
    int v676 = v675[v786];
    int v677 = v675[v780];
    int v787 = v677 + ((int)((unsigned int)(v677 - v676) >> 31));
    v675[v780] = v787;
    int * v679 = v662->cache_age;
    int v680 = v679[v781];
    int v789 = v680 + ((int)((unsigned int)(v680 - v676) >> 31));
    v679[v781] = v789;
    int * v682 = v662->cache_age;
    v682[v786] = 0;
    v767 = v786;
  } else {
    int * v685 = v662->cache_age;
    int v793 = (((int)((unsigned int)((int)((unsigned int)v668 >> 2)) >> 1)) & 1) * 2;
    int v686 = v685[v793];
    int * v687 = v662->cache_tags;
    int v688 = v687[v793];
    int v689 = v685[v781];
    int v690 = v687[v781];
    bool v795 = !(((~(((v672 ^ ((int)((unsigned int)((int)((unsigned int)v668 >> 2)) >> 1))) | (-(v672 ^ ((int)((unsigned int)((int)((unsigned int)v668 >> 2)) >> 1))))) >> 31)) | (~(((v673 ^ ((int)((unsigned int)((int)((unsigned int)v668 >> 2)) >> 1))) | (-(v673 ^ ((int)((unsigned int)((int)((unsigned int)v668 >> 2)) >> 1))))) >> 31))) == 0);
    int v744;
    if (v795) {
      int * v691 = v662->cache_age;
      int v797 = (4 + ((((int)((unsigned int)((int)((unsigned int)v668 >> 2)) >> 1)) & 3) * 2)) + ((~(((v673 ^ ((int)((unsigned int)((int)((unsigned int)v668 >> 2)) >> 1))) | (-(v673 ^ ((int)((unsigned int)((int)((unsigned int)v668 >> 2)) >> 1))))) >> 31)) & 1);
      int v692 = v691[v797];
      int v693 = v691[v782];
      int v798 = v693 + ((int)((unsigned int)(v693 - v692) >> 31));
      v691[v782] = v798;
      int * v695 = v662->cache_age;
      int v696 = v695[v783];
      int v800 = v696 + ((int)((unsigned int)(v696 - v692) >> 31));
      v695[v783] = v800;
      int * v698 = v662->cache_age;
      v698[v797] = 0;
      v744 = v797;
    } else {
      int * v701 = v662->cache_age;
      int v804 = 4 + ((((int)((unsigned int)((int)((unsigned int)v668 >> 2)) >> 1)) & 3) * 2);
      int v702 = v701[v804];
      int * v703 = v662->cache_tags;
      int v704 = v703[v804];
      int v705 = v701[v783];
      int v706 = v703[v783];
      int * v707 = v662->cache_dirty;
      int v807 = (4 + ((((int)((unsigned int)((int)((unsigned int)v668 >> 2)) >> 1)) & 3) * 2)) + ((((v702 + ((~(((v704 ^ -1) | (-(v704 ^ -1))) >> 31)) & 2)) - (v705 + ((~(((v706 ^ -1) | (-(v706 ^ -1))) >> 31)) & 2))) >> 31) & 1);
      int v708 = v707[v807];
      bool v808 = !(v708 == 0);
      if (v808) {
        int * v709 = v662->cache_tags;
        int v710 = v709[v807];
        int * v711 = v662->cache_vals;
        int v811 = ((4 + ((((int)((unsigned int)((int)((unsigned int)v668 >> 2)) >> 1)) & 3) * 2)) + ((((v702 + ((~(((v704 ^ -1) | (-(v704 ^ -1))) >> 31)) & 2)) - (v705 + ((~(((v706 ^ -1) | (-(v706 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
        int v712 = v711[v811];
        int v812 = (((4 + ((((int)((unsigned int)((int)((unsigned int)v668 >> 2)) >> 1)) & 3) * 2)) + ((((v702 + ((~(((v704 ^ -1) | (-(v704 ^ -1))) >> 31)) & 2)) - (v705 + ((~(((v706 ^ -1) | (-(v706 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
        int v713 = v711[v812];
        int * v714 = v662->mem;
        int v814 = v710 * 2;
        v714[v814] = v712;
        int * v716 = v662->mem;
        int v817 = (v710 * 2) + 1;
        v716[v817] = v713;
        ;
      } else {
        ;
      }
      int * v721 = v662->mem;
      int v822 = ((int)((unsigned int)((int)((unsigned int)v668 >> 2)) >> 1)) * 2;
      int v722 = v721[v822];
      int v823 = (((int)((unsigned int)((int)((unsigned int)v668 >> 2)) >> 1)) * 2) + 1;
      int v723 = v721[v823];
      int * v724 = v662->cache_vals;
      int v825 = ((4 + ((((int)((unsigned int)((int)((unsigned int)v668 >> 2)) >> 1)) & 3) * 2)) + ((((v702 + ((~(((v704 ^ -1) | (-(v704 ^ -1))) >> 31)) & 2)) - (v705 + ((~(((v706 ^ -1) | (-(v706 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
      v724[v825] = v722;
      int * v726 = v662->cache_vals;
      int v828 = (((4 + ((((int)((unsigned int)((int)((unsigned int)v668 >> 2)) >> 1)) & 3) * 2)) + ((((v702 + ((~(((v704 ^ -1) | (-(v704 ^ -1))) >> 31)) & 2)) - (v705 + ((~(((v706 ^ -1) | (-(v706 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
      v726[v828] = v723;
      int * v728 = v662->cache_tags;
      int v831 = (int)((unsigned int)((int)((unsigned int)v668 >> 2)) >> 1);
      v728[v807] = v831;
      int * v730 = v662->cache_dirty;
      v730[v807] = 0;
      int * v732 = v662->cache_age;
      v732[v807] = 1;
      int * v734 = v662->cache_age;
      int v735 = v734[v807];
      int v736 = v734[v782];
      int v837 = v736 + ((int)((unsigned int)(v736 - v735) >> 31));
      v734[v782] = v837;
      int * v738 = v662->cache_age;
      int v739 = v738[v783];
      int v839 = v739 + ((int)((unsigned int)(v739 - v735) >> 31));
      v738[v783] = v839;
      int * v741 = v662->cache_age;
      v741[v807] = 0;
      v744 = v807;
    }
    int * v745 = v662->cache_vals;
    int v842 = v744 * 2;
    int v746 = v745[v842];
    int v843 = (v744 * 2) + 1;
    int v747 = v745[v843];
    int v844 = (((((int)((unsigned int)((int)((unsigned int)v668 >> 2)) >> 1)) & 1) * 2) + ((((v686 + ((~(((v688 ^ -1) | (-(v688 ^ -1))) >> 31)) & 2)) - (v689 + ((~(((v690 ^ -1) | (-(v690 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
    v745[v844] = v746;
    int * v749 = v662->cache_vals;
    int v847 = ((((((int)((unsigned int)((int)((unsigned int)v668 >> 2)) >> 1)) & 1) * 2) + ((((v686 + ((~(((v688 ^ -1) | (-(v688 ^ -1))) >> 31)) & 2)) - (v689 + ((~(((v690 ^ -1) | (-(v690 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
    v749[v847] = v747;
    int * v751 = v662->cache_tags;
    int v850 = ((((int)((unsigned int)((int)((unsigned int)v668 >> 2)) >> 1)) & 1) * 2) + ((((v686 + ((~(((v688 ^ -1) | (-(v688 ^ -1))) >> 31)) & 2)) - (v689 + ((~(((v690 ^ -1) | (-(v690 ^ -1))) >> 31)) & 2))) >> 31) & 1);
    int v851 = (int)((unsigned int)((int)((unsigned int)v668 >> 2)) >> 1);
    v751[v850] = v851;
    int * v753 = v662->cache_dirty;
    v753[v850] = 0;
    int * v755 = v662->cache_age;
    v755[v850] = 1;
    int * v757 = v662->cache_age;
    int v758 = v757[v850];
    int v759 = v757[v780];
    int v857 = v759 + ((int)((unsigned int)(v759 - v758) >> 31));
    v757[v780] = v857;
    int * v761 = v662->cache_age;
    int v762 = v761[v781];
    int v859 = v762 + ((int)((unsigned int)(v762 - v758) >> 31));
    v761[v781] = v859;
    int * v764 = v662->cache_age;
    v764[v850] = 0;
    v767 = v850;
  }
  int v862 = (v767 * 2) + (((int)((unsigned int)v668 >> 2)) & 1);
  int v768 = v674[v862];
  int * v769 = v662->reg_ready;
  int v864 = ((v666 + ((v663 - v666) & (~((v663 - v666) >> 31)))) + 1) + ((100 ^ (((~(((v672 ^ ((int)((unsigned int)((int)((unsigned int)v668 >> 2)) >> 1))) | (-(v672 ^ ((int)((unsigned int)((int)((unsigned int)v668 >> 2)) >> 1))))) >> 31)) | (~(((v673 ^ ((int)((unsigned int)((int)((unsigned int)v668 >> 2)) >> 1))) | (-(v673 ^ ((int)((unsigned int)((int)((unsigned int)v668 >> 2)) >> 1))))) >> 31))) & 104)) ^ (((~(((v670 ^ ((int)((unsigned int)((int)((unsigned int)v668 >> 2)) >> 1))) | (-(v670 ^ ((int)((unsigned int)((int)((unsigned int)v668 >> 2)) >> 1))))) >> 31)) | (~(((v671 ^ ((int)((unsigned int)((int)((unsigned int)v668 >> 2)) >> 1))) | (-(v671 ^ ((int)((unsigned int)((int)((unsigned int)v668 >> 2)) >> 1))))) >> 31))) & (1 ^ (100 ^ (((~(((v672 ^ ((int)((unsigned int)((int)((unsigned int)v668 >> 2)) >> 1))) | (-(v672 ^ ((int)((unsigned int)((int)((unsigned int)v668 >> 2)) >> 1))))) >> 31)) | (~(((v673 ^ ((int)((unsigned int)((int)((unsigned int)v668 >> 2)) >> 1))) | (-(v673 ^ ((int)((unsigned int)((int)((unsigned int)v668 >> 2)) >> 1))))) >> 31))) & 104)))));
  v769[10] = v864;
  int * v771 = v662->regs;
  v771[10] = v768;
  struct StateT * v773 = slot_15(v662);
  return v773;
}

struct StateT * slot_17(struct StateT * v1101) {
  int * v1102 = v1101->saved_regs;
  int v1103 = v1102[10];
  int v1104 = v1102[11];
  bool v1224 = (v1103 ^ -2147483648) >= (v1104 ^ -2147483648);
  struct StateT * v1219;
  if (v1224) {
    int v1105 = v1101->timer;
    int v1225 = v1105 + 15;
    v1101->timer = v1225;
    int * v1107 = v1101->saved_regs;
    int v1108 = v1107[10];
    int * v1109 = v1101->regs;
    v1109[10] = v1108;
    int * v1111 = v1101->saved_regs;
    int v1112 = v1111[11];
    int * v1113 = v1101->regs;
    v1113[11] = v1112;
    int * v1115 = v1101->saved_regs;
    int v1116 = v1115[12];
    int * v1117 = v1101->regs;
    v1117[12] = v1116;
    int * v1119 = v1101->reg_ready;
    int v1120 = v1101->timer;
    v1119[0] = v1120;
    int * v1122 = v1101->reg_ready;
    int v1123 = v1101->timer;
    v1122[1] = v1123;
    int * v1125 = v1101->reg_ready;
    int v1126 = v1101->timer;
    v1125[2] = v1126;
    int * v1128 = v1101->reg_ready;
    int v1129 = v1101->timer;
    v1128[3] = v1129;
    int * v1131 = v1101->reg_ready;
    int v1132 = v1101->timer;
    v1131[4] = v1132;
    int * v1134 = v1101->reg_ready;
    int v1135 = v1101->timer;
    v1134[5] = v1135;
    int * v1137 = v1101->reg_ready;
    int v1138 = v1101->timer;
    v1137[6] = v1138;
    int * v1140 = v1101->reg_ready;
    int v1141 = v1101->timer;
    v1140[7] = v1141;
    int * v1143 = v1101->reg_ready;
    int v1144 = v1101->timer;
    v1143[8] = v1144;
    int * v1146 = v1101->reg_ready;
    int v1147 = v1101->timer;
    v1146[9] = v1147;
    int * v1149 = v1101->reg_ready;
    int v1150 = v1101->timer;
    v1149[10] = v1150;
    int * v1152 = v1101->reg_ready;
    int v1153 = v1101->timer;
    v1152[11] = v1153;
    int * v1155 = v1101->reg_ready;
    int v1156 = v1101->timer;
    v1155[12] = v1156;
    int * v1158 = v1101->reg_ready;
    int v1159 = v1101->timer;
    v1158[13] = v1159;
    int * v1161 = v1101->reg_ready;
    int v1162 = v1101->timer;
    v1161[14] = v1162;
    int * v1164 = v1101->reg_ready;
    int v1165 = v1101->timer;
    v1164[15] = v1165;
    int * v1167 = v1101->reg_ready;
    int v1168 = v1101->timer;
    v1167[16] = v1168;
    int * v1170 = v1101->reg_ready;
    int v1171 = v1101->timer;
    v1170[17] = v1171;
    int * v1173 = v1101->reg_ready;
    int v1174 = v1101->timer;
    v1173[18] = v1174;
    int * v1176 = v1101->reg_ready;
    int v1177 = v1101->timer;
    v1176[19] = v1177;
    int * v1179 = v1101->reg_ready;
    int v1180 = v1101->timer;
    v1179[20] = v1180;
    int * v1182 = v1101->reg_ready;
    int v1183 = v1101->timer;
    v1182[21] = v1183;
    int * v1185 = v1101->reg_ready;
    int v1186 = v1101->timer;
    v1185[22] = v1186;
    int * v1188 = v1101->reg_ready;
    int v1189 = v1101->timer;
    v1188[23] = v1189;
    int * v1191 = v1101->reg_ready;
    int v1192 = v1101->timer;
    v1191[24] = v1192;
    int * v1194 = v1101->reg_ready;
    int v1195 = v1101->timer;
    v1194[25] = v1195;
    int * v1197 = v1101->reg_ready;
    int v1198 = v1101->timer;
    v1197[26] = v1198;
    int * v1200 = v1101->reg_ready;
    int v1201 = v1101->timer;
    v1200[27] = v1201;
    int * v1203 = v1101->reg_ready;
    int v1204 = v1101->timer;
    v1203[28] = v1204;
    int * v1206 = v1101->reg_ready;
    int v1207 = v1101->timer;
    v1206[29] = v1207;
    int * v1209 = v1101->reg_ready;
    int v1210 = v1101->timer;
    v1209[30] = v1210;
    int * v1212 = v1101->reg_ready;
    int v1213 = v1101->timer;
    v1212[31] = v1213;
    struct StateT * v1215 = slot_21(v1101);
    v1219 = v1215;
  } else {
    struct StateT * v1217 = slot_19(v1101);
    v1219 = v1217;
  }
  return v1219;
}

struct StateT * slot_33(struct StateT * v3238) {
  int v3239 = v3238->timer;
  int v3242 = v3239 + 1;
  v3238->timer = v3242;
  return v3238;
}

struct StateT * snippet(struct StateT * v0) {
  struct StateT * v1 = slot_0(v0);
  int v3243 = v1->timer;
  int * v3244 = v1->reg_ready;
  int v3245 = v3244[0];
  int v3376 = v3245 + ((v3243 - v3245) & (~((v3243 - v3245) >> 31)));
  v1->timer = v3376;
  int v3247 = v1->timer;
  int * v3248 = v1->reg_ready;
  int v3249 = v3248[1];
  int v3379 = v3249 + ((v3247 - v3249) & (~((v3247 - v3249) >> 31)));
  v1->timer = v3379;
  int v3251 = v1->timer;
  int * v3252 = v1->reg_ready;
  int v3253 = v3252[2];
  int v3382 = v3253 + ((v3251 - v3253) & (~((v3251 - v3253) >> 31)));
  v1->timer = v3382;
  int v3255 = v1->timer;
  int * v3256 = v1->reg_ready;
  int v3257 = v3256[3];
  int v3385 = v3257 + ((v3255 - v3257) & (~((v3255 - v3257) >> 31)));
  v1->timer = v3385;
  int v3259 = v1->timer;
  int * v3260 = v1->reg_ready;
  int v3261 = v3260[4];
  int v3388 = v3261 + ((v3259 - v3261) & (~((v3259 - v3261) >> 31)));
  v1->timer = v3388;
  int v3263 = v1->timer;
  int * v3264 = v1->reg_ready;
  int v3265 = v3264[5];
  int v3391 = v3265 + ((v3263 - v3265) & (~((v3263 - v3265) >> 31)));
  v1->timer = v3391;
  int v3267 = v1->timer;
  int * v3268 = v1->reg_ready;
  int v3269 = v3268[6];
  int v3394 = v3269 + ((v3267 - v3269) & (~((v3267 - v3269) >> 31)));
  v1->timer = v3394;
  int v3271 = v1->timer;
  int * v3272 = v1->reg_ready;
  int v3273 = v3272[7];
  int v3397 = v3273 + ((v3271 - v3273) & (~((v3271 - v3273) >> 31)));
  v1->timer = v3397;
  int v3275 = v1->timer;
  int * v3276 = v1->reg_ready;
  int v3277 = v3276[8];
  int v3400 = v3277 + ((v3275 - v3277) & (~((v3275 - v3277) >> 31)));
  v1->timer = v3400;
  int v3279 = v1->timer;
  int * v3280 = v1->reg_ready;
  int v3281 = v3280[9];
  int v3403 = v3281 + ((v3279 - v3281) & (~((v3279 - v3281) >> 31)));
  v1->timer = v3403;
  int v3283 = v1->timer;
  int * v3284 = v1->reg_ready;
  int v3285 = v3284[10];
  int v3406 = v3285 + ((v3283 - v3285) & (~((v3283 - v3285) >> 31)));
  v1->timer = v3406;
  int v3287 = v1->timer;
  int * v3288 = v1->reg_ready;
  int v3289 = v3288[11];
  int v3409 = v3289 + ((v3287 - v3289) & (~((v3287 - v3289) >> 31)));
  v1->timer = v3409;
  int v3291 = v1->timer;
  int * v3292 = v1->reg_ready;
  int v3293 = v3292[12];
  int v3412 = v3293 + ((v3291 - v3293) & (~((v3291 - v3293) >> 31)));
  v1->timer = v3412;
  int v3295 = v1->timer;
  int * v3296 = v1->reg_ready;
  int v3297 = v3296[13];
  int v3415 = v3297 + ((v3295 - v3297) & (~((v3295 - v3297) >> 31)));
  v1->timer = v3415;
  int v3299 = v1->timer;
  int * v3300 = v1->reg_ready;
  int v3301 = v3300[14];
  int v3418 = v3301 + ((v3299 - v3301) & (~((v3299 - v3301) >> 31)));
  v1->timer = v3418;
  int v3303 = v1->timer;
  int * v3304 = v1->reg_ready;
  int v3305 = v3304[15];
  int v3421 = v3305 + ((v3303 - v3305) & (~((v3303 - v3305) >> 31)));
  v1->timer = v3421;
  int v3307 = v1->timer;
  int * v3308 = v1->reg_ready;
  int v3309 = v3308[16];
  int v3424 = v3309 + ((v3307 - v3309) & (~((v3307 - v3309) >> 31)));
  v1->timer = v3424;
  int v3311 = v1->timer;
  int * v3312 = v1->reg_ready;
  int v3313 = v3312[17];
  int v3427 = v3313 + ((v3311 - v3313) & (~((v3311 - v3313) >> 31)));
  v1->timer = v3427;
  int v3315 = v1->timer;
  int * v3316 = v1->reg_ready;
  int v3317 = v3316[18];
  int v3430 = v3317 + ((v3315 - v3317) & (~((v3315 - v3317) >> 31)));
  v1->timer = v3430;
  int v3319 = v1->timer;
  int * v3320 = v1->reg_ready;
  int v3321 = v3320[19];
  int v3433 = v3321 + ((v3319 - v3321) & (~((v3319 - v3321) >> 31)));
  v1->timer = v3433;
  int v3323 = v1->timer;
  int * v3324 = v1->reg_ready;
  int v3325 = v3324[20];
  int v3436 = v3325 + ((v3323 - v3325) & (~((v3323 - v3325) >> 31)));
  v1->timer = v3436;
  int v3327 = v1->timer;
  int * v3328 = v1->reg_ready;
  int v3329 = v3328[21];
  int v3439 = v3329 + ((v3327 - v3329) & (~((v3327 - v3329) >> 31)));
  v1->timer = v3439;
  int v3331 = v1->timer;
  int * v3332 = v1->reg_ready;
  int v3333 = v3332[22];
  int v3442 = v3333 + ((v3331 - v3333) & (~((v3331 - v3333) >> 31)));
  v1->timer = v3442;
  int v3335 = v1->timer;
  int * v3336 = v1->reg_ready;
  int v3337 = v3336[23];
  int v3445 = v3337 + ((v3335 - v3337) & (~((v3335 - v3337) >> 31)));
  v1->timer = v3445;
  int v3339 = v1->timer;
  int * v3340 = v1->reg_ready;
  int v3341 = v3340[24];
  int v3448 = v3341 + ((v3339 - v3341) & (~((v3339 - v3341) >> 31)));
  v1->timer = v3448;
  int v3343 = v1->timer;
  int * v3344 = v1->reg_ready;
  int v3345 = v3344[25];
  int v3451 = v3345 + ((v3343 - v3345) & (~((v3343 - v3345) >> 31)));
  v1->timer = v3451;
  int v3347 = v1->timer;
  int * v3348 = v1->reg_ready;
  int v3349 = v3348[26];
  int v3454 = v3349 + ((v3347 - v3349) & (~((v3347 - v3349) >> 31)));
  v1->timer = v3454;
  int v3351 = v1->timer;
  int * v3352 = v1->reg_ready;
  int v3353 = v3352[27];
  int v3457 = v3353 + ((v3351 - v3353) & (~((v3351 - v3353) >> 31)));
  v1->timer = v3457;
  int v3355 = v1->timer;
  int * v3356 = v1->reg_ready;
  int v3357 = v3356[28];
  int v3460 = v3357 + ((v3355 - v3357) & (~((v3355 - v3357) >> 31)));
  v1->timer = v3460;
  int v3359 = v1->timer;
  int * v3360 = v1->reg_ready;
  int v3361 = v3360[29];
  int v3463 = v3361 + ((v3359 - v3361) & (~((v3359 - v3361) >> 31)));
  v1->timer = v3463;
  int v3363 = v1->timer;
  int * v3364 = v1->reg_ready;
  int v3365 = v3364[30];
  int v3466 = v3365 + ((v3363 - v3365) & (~((v3363 - v3365) >> 31)));
  v1->timer = v3466;
  int v3367 = v1->timer;
  int * v3368 = v1->reg_ready;
  int v3369 = v3368[31];
  int v3469 = v3369 + ((v3367 - v3369) & (~((v3367 - v3369) >> 31)));
  v1->timer = v3469;
  return v1;
}

struct StateT * slot_8(struct StateT * v536) {
  int v537 = v536->timer;
  int v545 = v537 + 1;
  v536->timer = v545;
  int * v539 = v536->reg_ready;
  v539[11] = v545;
  int * v541 = v536->regs;
  v541[11] = 0;
  struct StateT * v543 = slot_9(v536);
  return v543;
}

struct StateT * slot_4(struct StateT * v261) {
  int * v262 = v261->saved_regs;
  int * v263 = v261->regs;
  int v264 = v263[11];
  v262[11] = v264;
  int v266 = v261->timer;
  int v278 = v266 + 1;
  v261->timer = v278;
  int * v268 = v261->reg_ready;
  v268[11] = v278;
  int * v270 = v261->regs;
  v270[11] = 0;
  struct StateT * v272 = slot_5(v261);
  return v272;
}

struct StateT * slot_15(struct StateT * v869) {
  int v870 = v869->timer;
  int v982 = v870 + 1;
  v869->timer = v982;
  int * v872 = v869->reg_ready;
  int v873 = v872[12];
  int * v874 = v869->regs;
  int v875 = v874[12];
  int * v876 = v869->cache_tags;
  int v987 = (((int)((unsigned int)((int)((unsigned int)(v875 + 68) >> 2)) >> 1)) & 1) * 2;
  int v877 = v876[v987];
  int v988 = ((((int)((unsigned int)((int)((unsigned int)(v875 + 68) >> 2)) >> 1)) & 1) * 2) + 1;
  int v878 = v876[v988];
  int v989 = 4 + ((((int)((unsigned int)((int)((unsigned int)(v875 + 68) >> 2)) >> 1)) & 3) * 2);
  int v879 = v876[v989];
  int v990 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v875 + 68) >> 2)) >> 1)) & 3) * 2)) + 1;
  int v880 = v876[v990];
  int * v881 = v869->cache_vals;
  bool v991 = !(((~(((v877 ^ ((int)((unsigned int)((int)((unsigned int)(v875 + 68) >> 2)) >> 1))) | (-(v877 ^ ((int)((unsigned int)((int)((unsigned int)(v875 + 68) >> 2)) >> 1))))) >> 31)) | (~(((v878 ^ ((int)((unsigned int)((int)((unsigned int)(v875 + 68) >> 2)) >> 1))) | (-(v878 ^ ((int)((unsigned int)((int)((unsigned int)(v875 + 68) >> 2)) >> 1))))) >> 31))) == 0);
  int v974;
  if (v991) {
    int * v882 = v869->cache_age;
    int v993 = ((((int)((unsigned int)((int)((unsigned int)(v875 + 68) >> 2)) >> 1)) & 1) * 2) + ((~(((v878 ^ ((int)((unsigned int)((int)((unsigned int)(v875 + 68) >> 2)) >> 1))) | (-(v878 ^ ((int)((unsigned int)((int)((unsigned int)(v875 + 68) >> 2)) >> 1))))) >> 31)) & 1);
    int v883 = v882[v993];
    int v884 = v882[v987];
    int v994 = v884 + ((int)((unsigned int)(v884 - v883) >> 31));
    v882[v987] = v994;
    int * v886 = v869->cache_age;
    int v887 = v886[v988];
    int v996 = v887 + ((int)((unsigned int)(v887 - v883) >> 31));
    v886[v988] = v996;
    int * v889 = v869->cache_age;
    v889[v993] = 0;
    v974 = v993;
  } else {
    int * v892 = v869->cache_age;
    int v1000 = (((int)((unsigned int)((int)((unsigned int)(v875 + 68) >> 2)) >> 1)) & 1) * 2;
    int v893 = v892[v1000];
    int * v894 = v869->cache_tags;
    int v895 = v894[v1000];
    int v896 = v892[v988];
    int v897 = v894[v988];
    bool v1002 = !(((~(((v879 ^ ((int)((unsigned int)((int)((unsigned int)(v875 + 68) >> 2)) >> 1))) | (-(v879 ^ ((int)((unsigned int)((int)((unsigned int)(v875 + 68) >> 2)) >> 1))))) >> 31)) | (~(((v880 ^ ((int)((unsigned int)((int)((unsigned int)(v875 + 68) >> 2)) >> 1))) | (-(v880 ^ ((int)((unsigned int)((int)((unsigned int)(v875 + 68) >> 2)) >> 1))))) >> 31))) == 0);
    int v951;
    if (v1002) {
      int * v898 = v869->cache_age;
      int v1004 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v875 + 68) >> 2)) >> 1)) & 3) * 2)) + ((~(((v880 ^ ((int)((unsigned int)((int)((unsigned int)(v875 + 68) >> 2)) >> 1))) | (-(v880 ^ ((int)((unsigned int)((int)((unsigned int)(v875 + 68) >> 2)) >> 1))))) >> 31)) & 1);
      int v899 = v898[v1004];
      int v900 = v898[v989];
      int v1005 = v900 + ((int)((unsigned int)(v900 - v899) >> 31));
      v898[v989] = v1005;
      int * v902 = v869->cache_age;
      int v903 = v902[v990];
      int v1007 = v903 + ((int)((unsigned int)(v903 - v899) >> 31));
      v902[v990] = v1007;
      int * v905 = v869->cache_age;
      v905[v1004] = 0;
      v951 = v1004;
    } else {
      int * v908 = v869->cache_age;
      int v1011 = 4 + ((((int)((unsigned int)((int)((unsigned int)(v875 + 68) >> 2)) >> 1)) & 3) * 2);
      int v909 = v908[v1011];
      int * v910 = v869->cache_tags;
      int v911 = v910[v1011];
      int v912 = v908[v990];
      int v913 = v910[v990];
      int * v914 = v869->cache_dirty;
      int v1014 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v875 + 68) >> 2)) >> 1)) & 3) * 2)) + ((((v909 + ((~(((v911 ^ -1) | (-(v911 ^ -1))) >> 31)) & 2)) - (v912 + ((~(((v913 ^ -1) | (-(v913 ^ -1))) >> 31)) & 2))) >> 31) & 1);
      int v915 = v914[v1014];
      bool v1015 = !(v915 == 0);
      if (v1015) {
        int * v916 = v869->cache_tags;
        int v917 = v916[v1014];
        int * v918 = v869->cache_vals;
        int v1018 = ((4 + ((((int)((unsigned int)((int)((unsigned int)(v875 + 68) >> 2)) >> 1)) & 3) * 2)) + ((((v909 + ((~(((v911 ^ -1) | (-(v911 ^ -1))) >> 31)) & 2)) - (v912 + ((~(((v913 ^ -1) | (-(v913 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
        int v919 = v918[v1018];
        int v1019 = (((4 + ((((int)((unsigned int)((int)((unsigned int)(v875 + 68) >> 2)) >> 1)) & 3) * 2)) + ((((v909 + ((~(((v911 ^ -1) | (-(v911 ^ -1))) >> 31)) & 2)) - (v912 + ((~(((v913 ^ -1) | (-(v913 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
        int v920 = v918[v1019];
        int * v921 = v869->mem;
        int v1021 = v917 * 2;
        v921[v1021] = v919;
        int * v923 = v869->mem;
        int v1024 = (v917 * 2) + 1;
        v923[v1024] = v920;
        ;
      } else {
        ;
      }
      int * v928 = v869->mem;
      int v1029 = ((int)((unsigned int)((int)((unsigned int)(v875 + 68) >> 2)) >> 1)) * 2;
      int v929 = v928[v1029];
      int v1030 = (((int)((unsigned int)((int)((unsigned int)(v875 + 68) >> 2)) >> 1)) * 2) + 1;
      int v930 = v928[v1030];
      int * v931 = v869->cache_vals;
      int v1032 = ((4 + ((((int)((unsigned int)((int)((unsigned int)(v875 + 68) >> 2)) >> 1)) & 3) * 2)) + ((((v909 + ((~(((v911 ^ -1) | (-(v911 ^ -1))) >> 31)) & 2)) - (v912 + ((~(((v913 ^ -1) | (-(v913 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
      v931[v1032] = v929;
      int * v933 = v869->cache_vals;
      int v1035 = (((4 + ((((int)((unsigned int)((int)((unsigned int)(v875 + 68) >> 2)) >> 1)) & 3) * 2)) + ((((v909 + ((~(((v911 ^ -1) | (-(v911 ^ -1))) >> 31)) & 2)) - (v912 + ((~(((v913 ^ -1) | (-(v913 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
      v933[v1035] = v930;
      int * v935 = v869->cache_tags;
      int v1038 = (int)((unsigned int)((int)((unsigned int)(v875 + 68) >> 2)) >> 1);
      v935[v1014] = v1038;
      int * v937 = v869->cache_dirty;
      v937[v1014] = 0;
      int * v939 = v869->cache_age;
      v939[v1014] = 1;
      int * v941 = v869->cache_age;
      int v942 = v941[v1014];
      int v943 = v941[v989];
      int v1044 = v943 + ((int)((unsigned int)(v943 - v942) >> 31));
      v941[v989] = v1044;
      int * v945 = v869->cache_age;
      int v946 = v945[v990];
      int v1046 = v946 + ((int)((unsigned int)(v946 - v942) >> 31));
      v945[v990] = v1046;
      int * v948 = v869->cache_age;
      v948[v1014] = 0;
      v951 = v1014;
    }
    int * v952 = v869->cache_vals;
    int v1049 = v951 * 2;
    int v953 = v952[v1049];
    int v1050 = (v951 * 2) + 1;
    int v954 = v952[v1050];
    int v1051 = (((((int)((unsigned int)((int)((unsigned int)(v875 + 68) >> 2)) >> 1)) & 1) * 2) + ((((v893 + ((~(((v895 ^ -1) | (-(v895 ^ -1))) >> 31)) & 2)) - (v896 + ((~(((v897 ^ -1) | (-(v897 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
    v952[v1051] = v953;
    int * v956 = v869->cache_vals;
    int v1054 = ((((((int)((unsigned int)((int)((unsigned int)(v875 + 68) >> 2)) >> 1)) & 1) * 2) + ((((v893 + ((~(((v895 ^ -1) | (-(v895 ^ -1))) >> 31)) & 2)) - (v896 + ((~(((v897 ^ -1) | (-(v897 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
    v956[v1054] = v954;
    int * v958 = v869->cache_tags;
    int v1057 = ((((int)((unsigned int)((int)((unsigned int)(v875 + 68) >> 2)) >> 1)) & 1) * 2) + ((((v893 + ((~(((v895 ^ -1) | (-(v895 ^ -1))) >> 31)) & 2)) - (v896 + ((~(((v897 ^ -1) | (-(v897 ^ -1))) >> 31)) & 2))) >> 31) & 1);
    int v1058 = (int)((unsigned int)((int)((unsigned int)(v875 + 68) >> 2)) >> 1);
    v958[v1057] = v1058;
    int * v960 = v869->cache_dirty;
    v960[v1057] = 0;
    int * v962 = v869->cache_age;
    v962[v1057] = 1;
    int * v964 = v869->cache_age;
    int v965 = v964[v1057];
    int v966 = v964[v987];
    int v1064 = v966 + ((int)((unsigned int)(v966 - v965) >> 31));
    v964[v987] = v1064;
    int * v968 = v869->cache_age;
    int v969 = v968[v988];
    int v1066 = v969 + ((int)((unsigned int)(v969 - v965) >> 31));
    v968[v988] = v1066;
    int * v971 = v869->cache_age;
    v971[v1057] = 0;
    v974 = v1057;
  }
  int v1069 = (v974 * 2) + (((int)((unsigned int)(v875 + 68) >> 2)) & 1);
  int v975 = v881[v1069];
  int * v976 = v869->reg_ready;
  int v1072 = ((v873 + ((v870 - v873) & (~((v870 - v873) >> 31)))) + 1) + ((100 ^ (((~(((v879 ^ ((int)((unsigned int)((int)((unsigned int)(v875 + 68) >> 2)) >> 1))) | (-(v879 ^ ((int)((unsigned int)((int)((unsigned int)(v875 + 68) >> 2)) >> 1))))) >> 31)) | (~(((v880 ^ ((int)((unsigned int)((int)((unsigned int)(v875 + 68) >> 2)) >> 1))) | (-(v880 ^ ((int)((unsigned int)((int)((unsigned int)(v875 + 68) >> 2)) >> 1))))) >> 31))) & 104)) ^ (((~(((v877 ^ ((int)((unsigned int)((int)((unsigned int)(v875 + 68) >> 2)) >> 1))) | (-(v877 ^ ((int)((unsigned int)((int)((unsigned int)(v875 + 68) >> 2)) >> 1))))) >> 31)) | (~(((v878 ^ ((int)((unsigned int)((int)((unsigned int)(v875 + 68) >> 2)) >> 1))) | (-(v878 ^ ((int)((unsigned int)((int)((unsigned int)(v875 + 68) >> 2)) >> 1))))) >> 31))) & (1 ^ (100 ^ (((~(((v879 ^ ((int)((unsigned int)((int)((unsigned int)(v875 + 68) >> 2)) >> 1))) | (-(v879 ^ ((int)((unsigned int)((int)((unsigned int)(v875 + 68) >> 2)) >> 1))))) >> 31)) | (~(((v880 ^ ((int)((unsigned int)((int)((unsigned int)(v875 + 68) >> 2)) >> 1))) | (-(v880 ^ ((int)((unsigned int)((int)((unsigned int)(v875 + 68) >> 2)) >> 1))))) >> 31))) & 104)))));
  v976[11] = v1072;
  int * v978 = v869->regs;
  v978[11] = v975;
  struct StateT * v980 = slot_16(v869);
  return v980;
}

struct StateT * slot_9(struct StateT * v552) {
  int v553 = v552->timer;
  int v564 = v553 + 1;
  v552->timer = v564;
  int * v555 = v552->reg_ready;
  int v556 = v555[11];
  int * v557 = v552->regs;
  int v558 = v557[11];
  int v568 = (v556 + ((v553 - v556) & (~((v553 - v556) >> 31)))) + 1;
  v555[11] = v568;
  int * v560 = v552->regs;
  int v570 = v558 + 4;
  v560[11] = v570;
  struct StateT * v562 = slot_10(v552);
  return v562;
}

struct StateT * slot_11(struct StateT * v596) {
  int v597 = v596->timer;
  int v608 = v597 + 1;
  v596->timer = v608;
  int * v599 = v596->reg_ready;
  int v600 = v599[10];
  int * v601 = v596->regs;
  int v602 = v601[10];
  int v612 = (v600 + ((v597 - v600) & (~((v597 - v600) >> 31)))) + 1;
  v599[10] = v612;
  int * v604 = v596->regs;
  int v614 = v602 << 29;
  v604[10] = v614;
  struct StateT * v606 = slot_12(v596);
  return v606;
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