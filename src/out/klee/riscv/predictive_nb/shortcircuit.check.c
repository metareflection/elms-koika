// verify: leak (KLEE should report a failing assertion) [budget 1200s]
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

struct StateT * slot_6(struct StateT * v122);
struct StateT * slot_29(struct StateT * v2144);
struct StateT * slot_25(struct StateT * v2089);
struct StateT * slot_16(struct StateT * v1221);
struct StateT * slot_23(struct StateT * v1585);
struct StateT * slot_5(struct StateT * v83);
struct StateT * slot_2(struct StateT * v38);
struct StateT * slot_7(struct StateT * v384);
struct StateT * slot_21(struct StateT * v1284);
struct StateT * slot_3(struct StateT * v56);
struct StateT * slot_26(struct StateT * v2104);
struct StateT * slot_10(struct StateT * v927);
struct StateT * slot_1(struct StateT * v20);
struct StateT * slot_13(struct StateT * v951);
struct StateT * slot_24(struct StateT * v1847);
struct StateT * slot_0(struct StateT * v2);
struct StateT * slot_14(struct StateT * v982);
struct StateT * slot_28(struct StateT * v2113);
struct StateT * slot_17(struct StateT * v1230);
struct StateT * slot_20(struct StateT * v1245);
struct StateT * snippet(struct StateT * v0);
struct StateT * slot_8(struct StateT * v423);
struct StateT * slot_4(struct StateT * v74);
struct StateT * slot_15(struct StateT * v1203);
struct StateT * slot_18(struct StateT * v1236);
struct StateT * slot_9(struct StateT * v685);
struct StateT * slot_22(struct StateT * v1546);
struct StateT * slot_11(struct StateT * v942);
struct StateT * slot_6(struct StateT * v122) {
  int * v123 = v122->saved_regs;
  int * v124 = v122->regs;
  int v125 = v124[10];
  v123[10] = v125;
  int v127 = v122->timer;
  int v128 = v122->timer;
  int v267 = v128 + 1;
  v122->timer = v267;
  int * v130 = v122->reg_ready;
  int v131 = v130[5];
  int * v132 = v122->regs;
  int v133 = v132[5];
  int * v134 = v122->cache_tags;
  int v272 = (((int)((unsigned int)((int)((unsigned int)v133 >> 2)) >> 1)) & 1) * 2;
  int v135 = v134[v272];
  int * v136 = v122->cache_tags;
  int v274 = ((((int)((unsigned int)((int)((unsigned int)v133 >> 2)) >> 1)) & 1) * 2) + 1;
  int v137 = v136[v274];
  int * v138 = v122->cache_tags;
  int v276 = 4 + ((((int)((unsigned int)((int)((unsigned int)v133 >> 2)) >> 1)) & 3) * 2);
  int v139 = v138[v276];
  int * v140 = v122->cache_tags;
  int v278 = (4 + ((((int)((unsigned int)((int)((unsigned int)v133 >> 2)) >> 1)) & 3) * 2)) + 1;
  int v141 = v140[v278];
  int * v142 = v122->cache_vals;
  bool v279 = !(((~(((v135 ^ ((int)((unsigned int)((int)((unsigned int)v133 >> 2)) >> 1))) | (-(v135 ^ ((int)((unsigned int)((int)((unsigned int)v133 >> 2)) >> 1))))) >> 31)) | (~(((v137 ^ ((int)((unsigned int)((int)((unsigned int)v133 >> 2)) >> 1))) | (-(v137 ^ ((int)((unsigned int)((int)((unsigned int)v133 >> 2)) >> 1))))) >> 31))) == 0);
  int v255;
  if (v279) {
    int * v143 = v122->cache_age;
    int v281 = ((((int)((unsigned int)((int)((unsigned int)v133 >> 2)) >> 1)) & 1) * 2) + ((~(((v137 ^ ((int)((unsigned int)((int)((unsigned int)v133 >> 2)) >> 1))) | (-(v137 ^ ((int)((unsigned int)((int)((unsigned int)v133 >> 2)) >> 1))))) >> 31)) & 1);
    int v144 = v143[v281];
    int * v145 = v122->cache_age;
    int v146 = v145[v272];
    int * v147 = v122->cache_age;
    int v284 = v146 + ((int)((unsigned int)(v146 - v144) >> 31));
    v147[v272] = v284;
    int * v149 = v122->cache_age;
    int v150 = v149[v274];
    int * v151 = v122->cache_age;
    int v287 = v150 + ((int)((unsigned int)(v150 - v144) >> 31));
    v151[v274] = v287;
    int * v153 = v122->cache_age;
    v153[v281] = 0;
    v255 = v281;
  } else {
    int * v156 = v122->cache_age;
    int v291 = (((int)((unsigned int)((int)((unsigned int)v133 >> 2)) >> 1)) & 1) * 2;
    int v157 = v156[v291];
    int * v158 = v122->cache_tags;
    int v159 = v158[v291];
    int * v160 = v122->cache_age;
    int v161 = v160[v274];
    int * v162 = v122->cache_tags;
    int v163 = v162[v274];
    bool v295 = !(((~(((v139 ^ ((int)((unsigned int)((int)((unsigned int)v133 >> 2)) >> 1))) | (-(v139 ^ ((int)((unsigned int)((int)((unsigned int)v133 >> 2)) >> 1))))) >> 31)) | (~(((v141 ^ ((int)((unsigned int)((int)((unsigned int)v133 >> 2)) >> 1))) | (-(v141 ^ ((int)((unsigned int)((int)((unsigned int)v133 >> 2)) >> 1))))) >> 31))) == 0);
    int v227;
    if (v295) {
      int * v164 = v122->cache_age;
      int v297 = (4 + ((((int)((unsigned int)((int)((unsigned int)v133 >> 2)) >> 1)) & 3) * 2)) + ((~(((v141 ^ ((int)((unsigned int)((int)((unsigned int)v133 >> 2)) >> 1))) | (-(v141 ^ ((int)((unsigned int)((int)((unsigned int)v133 >> 2)) >> 1))))) >> 31)) & 1);
      int v165 = v164[v297];
      int * v166 = v122->cache_age;
      int v167 = v166[v276];
      int * v168 = v122->cache_age;
      int v300 = v167 + ((int)((unsigned int)(v167 - v165) >> 31));
      v168[v276] = v300;
      int * v170 = v122->cache_age;
      int v171 = v170[v278];
      int * v172 = v122->cache_age;
      int v303 = v171 + ((int)((unsigned int)(v171 - v165) >> 31));
      v172[v278] = v303;
      int * v174 = v122->cache_age;
      v174[v297] = 0;
      v227 = v297;
    } else {
      int * v177 = v122->cache_age;
      int v307 = 4 + ((((int)((unsigned int)((int)((unsigned int)v133 >> 2)) >> 1)) & 3) * 2);
      int v178 = v177[v307];
      int * v179 = v122->cache_tags;
      int v180 = v179[v307];
      int * v181 = v122->cache_age;
      int v182 = v181[v278];
      int * v183 = v122->cache_tags;
      int v184 = v183[v278];
      int * v185 = v122->cache_dirty;
      int v312 = (4 + ((((int)((unsigned int)((int)((unsigned int)v133 >> 2)) >> 1)) & 3) * 2)) + ((((v178 + ((~(((v180 ^ -1) | (-(v180 ^ -1))) >> 31)) & 2)) - (v182 + ((~(((v184 ^ -1) | (-(v184 ^ -1))) >> 31)) & 2))) >> 31) & 1);
      int v186 = v185[v312];
      bool v313 = !(v186 == 0);
      if (v313) {
        int * v187 = v122->cache_tags;
        int v188 = v187[v312];
        int * v189 = v122->cache_vals;
        int v316 = ((4 + ((((int)((unsigned int)((int)((unsigned int)v133 >> 2)) >> 1)) & 3) * 2)) + ((((v178 + ((~(((v180 ^ -1) | (-(v180 ^ -1))) >> 31)) & 2)) - (v182 + ((~(((v184 ^ -1) | (-(v184 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
        int v190 = v189[v316];
        int * v191 = v122->cache_vals;
        int v318 = (((4 + ((((int)((unsigned int)((int)((unsigned int)v133 >> 2)) >> 1)) & 3) * 2)) + ((((v178 + ((~(((v180 ^ -1) | (-(v180 ^ -1))) >> 31)) & 2)) - (v182 + ((~(((v184 ^ -1) | (-(v184 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
        int v192 = v191[v318];
        int * v193 = v122->mem;
        int v320 = v188 * 2;
        v193[v320] = v190;
        int * v195 = v122->mem;
        int v323 = (v188 * 2) + 1;
        v195[v323] = v192;
        ;
      } else {
        ;
      }
      int * v200 = v122->mem;
      int v328 = ((int)((unsigned int)((int)((unsigned int)v133 >> 2)) >> 1)) * 2;
      int v201 = v200[v328];
      int * v202 = v122->mem;
      int v330 = (((int)((unsigned int)((int)((unsigned int)v133 >> 2)) >> 1)) * 2) + 1;
      int v203 = v202[v330];
      int * v204 = v122->cache_vals;
      int v332 = ((4 + ((((int)((unsigned int)((int)((unsigned int)v133 >> 2)) >> 1)) & 3) * 2)) + ((((v178 + ((~(((v180 ^ -1) | (-(v180 ^ -1))) >> 31)) & 2)) - (v182 + ((~(((v184 ^ -1) | (-(v184 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
      v204[v332] = v201;
      int * v206 = v122->cache_vals;
      int v335 = (((4 + ((((int)((unsigned int)((int)((unsigned int)v133 >> 2)) >> 1)) & 3) * 2)) + ((((v178 + ((~(((v180 ^ -1) | (-(v180 ^ -1))) >> 31)) & 2)) - (v182 + ((~(((v184 ^ -1) | (-(v184 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
      v206[v335] = v203;
      int * v208 = v122->cache_tags;
      int v338 = (int)((unsigned int)((int)((unsigned int)v133 >> 2)) >> 1);
      v208[v312] = v338;
      int * v210 = v122->cache_dirty;
      v210[v312] = 0;
      int * v212 = v122->cache_age;
      v212[v312] = 1;
      int * v214 = v122->cache_age;
      int v215 = v214[v312];
      int * v216 = v122->cache_age;
      int v217 = v216[v276];
      int * v218 = v122->cache_age;
      int v346 = v217 + ((int)((unsigned int)(v217 - v215) >> 31));
      v218[v276] = v346;
      int * v220 = v122->cache_age;
      int v221 = v220[v278];
      int * v222 = v122->cache_age;
      int v349 = v221 + ((int)((unsigned int)(v221 - v215) >> 31));
      v222[v278] = v349;
      int * v224 = v122->cache_age;
      v224[v312] = 0;
      v227 = v312;
    }
    int * v228 = v122->cache_vals;
    int v352 = v227 * 2;
    int v229 = v228[v352];
    int * v230 = v122->cache_vals;
    int v354 = (v227 * 2) + 1;
    int v231 = v230[v354];
    int * v232 = v122->cache_vals;
    int v356 = (((((int)((unsigned int)((int)((unsigned int)v133 >> 2)) >> 1)) & 1) * 2) + ((((v157 + ((~(((v159 ^ -1) | (-(v159 ^ -1))) >> 31)) & 2)) - (v161 + ((~(((v163 ^ -1) | (-(v163 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
    v232[v356] = v229;
    int * v234 = v122->cache_vals;
    int v359 = ((((((int)((unsigned int)((int)((unsigned int)v133 >> 2)) >> 1)) & 1) * 2) + ((((v157 + ((~(((v159 ^ -1) | (-(v159 ^ -1))) >> 31)) & 2)) - (v161 + ((~(((v163 ^ -1) | (-(v163 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
    v234[v359] = v231;
    int * v236 = v122->cache_tags;
    int v362 = ((((int)((unsigned int)((int)((unsigned int)v133 >> 2)) >> 1)) & 1) * 2) + ((((v157 + ((~(((v159 ^ -1) | (-(v159 ^ -1))) >> 31)) & 2)) - (v161 + ((~(((v163 ^ -1) | (-(v163 ^ -1))) >> 31)) & 2))) >> 31) & 1);
    int v363 = (int)((unsigned int)((int)((unsigned int)v133 >> 2)) >> 1);
    v236[v362] = v363;
    int * v238 = v122->cache_dirty;
    v238[v362] = 0;
    int * v240 = v122->cache_age;
    v240[v362] = 1;
    int * v242 = v122->cache_age;
    int v243 = v242[v362];
    int * v244 = v122->cache_age;
    int v245 = v244[v272];
    int * v246 = v122->cache_age;
    int v371 = v245 + ((int)((unsigned int)(v245 - v243) >> 31));
    v246[v272] = v371;
    int * v248 = v122->cache_age;
    int v249 = v248[v274];
    int * v250 = v122->cache_age;
    int v374 = v249 + ((int)((unsigned int)(v249 - v243) >> 31));
    v250[v274] = v374;
    int * v252 = v122->cache_age;
    v252[v362] = 0;
    v255 = v362;
  }
  int v377 = (v255 * 2) + (((int)((unsigned int)v133 >> 2)) & 1);
  int v256 = v142[v377];
  int * v257 = v122->reg_ready;
  int v379 = ((v131 + ((v127 - v131) & (~((v127 - v131) >> 31)))) + 1) + ((100 ^ (((~(((v139 ^ ((int)((unsigned int)((int)((unsigned int)v133 >> 2)) >> 1))) | (-(v139 ^ ((int)((unsigned int)((int)((unsigned int)v133 >> 2)) >> 1))))) >> 31)) | (~(((v141 ^ ((int)((unsigned int)((int)((unsigned int)v133 >> 2)) >> 1))) | (-(v141 ^ ((int)((unsigned int)((int)((unsigned int)v133 >> 2)) >> 1))))) >> 31))) & 104)) ^ (((~(((v135 ^ ((int)((unsigned int)((int)((unsigned int)v133 >> 2)) >> 1))) | (-(v135 ^ ((int)((unsigned int)((int)((unsigned int)v133 >> 2)) >> 1))))) >> 31)) | (~(((v137 ^ ((int)((unsigned int)((int)((unsigned int)v133 >> 2)) >> 1))) | (-(v137 ^ ((int)((unsigned int)((int)((unsigned int)v133 >> 2)) >> 1))))) >> 31))) & (1 ^ (100 ^ (((~(((v139 ^ ((int)((unsigned int)((int)((unsigned int)v133 >> 2)) >> 1))) | (-(v139 ^ ((int)((unsigned int)((int)((unsigned int)v133 >> 2)) >> 1))))) >> 31)) | (~(((v141 ^ ((int)((unsigned int)((int)((unsigned int)v133 >> 2)) >> 1))) | (-(v141 ^ ((int)((unsigned int)((int)((unsigned int)v133 >> 2)) >> 1))))) >> 31))) & 104)))));
  v257[10] = v379;
  int * v259 = v122->regs;
  v259[10] = v256;
  struct StateT * v261 = slot_7(v122);
  return v261;
}

struct StateT * slot_29(struct StateT * v2144) {
  int * v2145 = v2144->regs;
  int v2146 = v2145[10];
  int * v2147 = v2144->regs;
  int v2148 = v2147[11];
  bool v2261 = !(v2146 == v2148);
  struct StateT * v2255;
  if (v2261) {
    int v2149 = v2144->timer;
    int v2262 = v2149 + 15;
    v2144->timer = v2262;
    int * v2151 = v2144->saved_regs;
    int v2152 = v2151[14];
    int * v2153 = v2144->regs;
    v2153[14] = v2152;
    int * v2155 = v2144->reg_ready;
    int v2156 = v2144->timer;
    v2155[0] = v2156;
    int * v2158 = v2144->reg_ready;
    int v2159 = v2144->timer;
    v2158[1] = v2159;
    int * v2161 = v2144->reg_ready;
    int v2162 = v2144->timer;
    v2161[2] = v2162;
    int * v2164 = v2144->reg_ready;
    int v2165 = v2144->timer;
    v2164[3] = v2165;
    int * v2167 = v2144->reg_ready;
    int v2168 = v2144->timer;
    v2167[4] = v2168;
    int * v2170 = v2144->reg_ready;
    int v2171 = v2144->timer;
    v2170[5] = v2171;
    int * v2173 = v2144->reg_ready;
    int v2174 = v2144->timer;
    v2173[6] = v2174;
    int * v2176 = v2144->reg_ready;
    int v2177 = v2144->timer;
    v2176[7] = v2177;
    int * v2179 = v2144->reg_ready;
    int v2180 = v2144->timer;
    v2179[8] = v2180;
    int * v2182 = v2144->reg_ready;
    int v2183 = v2144->timer;
    v2182[9] = v2183;
    int * v2185 = v2144->reg_ready;
    int v2186 = v2144->timer;
    v2185[10] = v2186;
    int * v2188 = v2144->reg_ready;
    int v2189 = v2144->timer;
    v2188[11] = v2189;
    int * v2191 = v2144->reg_ready;
    int v2192 = v2144->timer;
    v2191[12] = v2192;
    int * v2194 = v2144->reg_ready;
    int v2195 = v2144->timer;
    v2194[13] = v2195;
    int * v2197 = v2144->reg_ready;
    int v2198 = v2144->timer;
    v2197[14] = v2198;
    int * v2200 = v2144->reg_ready;
    int v2201 = v2144->timer;
    v2200[15] = v2201;
    int * v2203 = v2144->reg_ready;
    int v2204 = v2144->timer;
    v2203[16] = v2204;
    int * v2206 = v2144->reg_ready;
    int v2207 = v2144->timer;
    v2206[17] = v2207;
    int * v2209 = v2144->reg_ready;
    int v2210 = v2144->timer;
    v2209[18] = v2210;
    int * v2212 = v2144->reg_ready;
    int v2213 = v2144->timer;
    v2212[19] = v2213;
    int * v2215 = v2144->reg_ready;
    int v2216 = v2144->timer;
    v2215[20] = v2216;
    int * v2218 = v2144->reg_ready;
    int v2219 = v2144->timer;
    v2218[21] = v2219;
    int * v2221 = v2144->reg_ready;
    int v2222 = v2144->timer;
    v2221[22] = v2222;
    int * v2224 = v2144->reg_ready;
    int v2225 = v2144->timer;
    v2224[23] = v2225;
    int * v2227 = v2144->reg_ready;
    int v2228 = v2144->timer;
    v2227[24] = v2228;
    int * v2230 = v2144->reg_ready;
    int v2231 = v2144->timer;
    v2230[25] = v2231;
    int * v2233 = v2144->reg_ready;
    int v2234 = v2144->timer;
    v2233[26] = v2234;
    int * v2236 = v2144->reg_ready;
    int v2237 = v2144->timer;
    v2236[27] = v2237;
    int * v2239 = v2144->reg_ready;
    int v2240 = v2144->timer;
    v2239[28] = v2240;
    int * v2242 = v2144->reg_ready;
    int v2243 = v2144->timer;
    v2242[29] = v2243;
    int * v2245 = v2144->reg_ready;
    int v2246 = v2144->timer;
    v2245[30] = v2246;
    int * v2248 = v2144->reg_ready;
    int v2249 = v2144->timer;
    v2248[31] = v2249;
    struct StateT * v2251 = slot_15(v2144);
    v2255 = v2251;
  } else {
    struct StateT * v2253 = slot_16(v2144);
    v2255 = v2253;
  }
  return v2255;
}

struct StateT * slot_25(struct StateT * v2089) {
  int v2090 = v2089->timer;
  int v2091 = v2089->timer;
  int v2098 = v2091 + 1;
  v2089->timer = v2098;
  int * v2093 = v2089->reg_ready;
  int v2101 = v2090 + 1;
  v2093[10] = v2101;
  int * v2095 = v2089->regs;
  v2095[10] = 1;
  return v2089;
}

struct StateT * slot_16(struct StateT * v1221) {
  int v1222 = v1221->timer;
  int v1223 = v1221->timer;
  int v1227 = v1223 + 1;
  v1221->timer = v1227;
  struct StateT * v1225 = slot_18(v1221);
  return v1225;
}

struct StateT * slot_23(struct StateT * v1585) {
  int * v1586 = v1585->saved_regs;
  int * v1587 = v1585->regs;
  int v1588 = v1587[11];
  v1586[11] = v1588;
  int v1590 = v1585->timer;
  int v1591 = v1585->timer;
  int v1730 = v1591 + 1;
  v1585->timer = v1730;
  int * v1593 = v1585->reg_ready;
  int v1594 = v1593[6];
  int * v1595 = v1585->regs;
  int v1596 = v1595[6];
  int * v1597 = v1585->cache_tags;
  int v1735 = (((int)((unsigned int)((int)((unsigned int)v1596 >> 2)) >> 1)) & 1) * 2;
  int v1598 = v1597[v1735];
  int * v1599 = v1585->cache_tags;
  int v1737 = ((((int)((unsigned int)((int)((unsigned int)v1596 >> 2)) >> 1)) & 1) * 2) + 1;
  int v1600 = v1599[v1737];
  int * v1601 = v1585->cache_tags;
  int v1739 = 4 + ((((int)((unsigned int)((int)((unsigned int)v1596 >> 2)) >> 1)) & 3) * 2);
  int v1602 = v1601[v1739];
  int * v1603 = v1585->cache_tags;
  int v1741 = (4 + ((((int)((unsigned int)((int)((unsigned int)v1596 >> 2)) >> 1)) & 3) * 2)) + 1;
  int v1604 = v1603[v1741];
  int * v1605 = v1585->cache_vals;
  bool v1742 = !(((~(((v1598 ^ ((int)((unsigned int)((int)((unsigned int)v1596 >> 2)) >> 1))) | (-(v1598 ^ ((int)((unsigned int)((int)((unsigned int)v1596 >> 2)) >> 1))))) >> 31)) | (~(((v1600 ^ ((int)((unsigned int)((int)((unsigned int)v1596 >> 2)) >> 1))) | (-(v1600 ^ ((int)((unsigned int)((int)((unsigned int)v1596 >> 2)) >> 1))))) >> 31))) == 0);
  int v1718;
  if (v1742) {
    int * v1606 = v1585->cache_age;
    int v1744 = ((((int)((unsigned int)((int)((unsigned int)v1596 >> 2)) >> 1)) & 1) * 2) + ((~(((v1600 ^ ((int)((unsigned int)((int)((unsigned int)v1596 >> 2)) >> 1))) | (-(v1600 ^ ((int)((unsigned int)((int)((unsigned int)v1596 >> 2)) >> 1))))) >> 31)) & 1);
    int v1607 = v1606[v1744];
    int * v1608 = v1585->cache_age;
    int v1609 = v1608[v1735];
    int * v1610 = v1585->cache_age;
    int v1747 = v1609 + ((int)((unsigned int)(v1609 - v1607) >> 31));
    v1610[v1735] = v1747;
    int * v1612 = v1585->cache_age;
    int v1613 = v1612[v1737];
    int * v1614 = v1585->cache_age;
    int v1750 = v1613 + ((int)((unsigned int)(v1613 - v1607) >> 31));
    v1614[v1737] = v1750;
    int * v1616 = v1585->cache_age;
    v1616[v1744] = 0;
    v1718 = v1744;
  } else {
    int * v1619 = v1585->cache_age;
    int v1754 = (((int)((unsigned int)((int)((unsigned int)v1596 >> 2)) >> 1)) & 1) * 2;
    int v1620 = v1619[v1754];
    int * v1621 = v1585->cache_tags;
    int v1622 = v1621[v1754];
    int * v1623 = v1585->cache_age;
    int v1624 = v1623[v1737];
    int * v1625 = v1585->cache_tags;
    int v1626 = v1625[v1737];
    bool v1758 = !(((~(((v1602 ^ ((int)((unsigned int)((int)((unsigned int)v1596 >> 2)) >> 1))) | (-(v1602 ^ ((int)((unsigned int)((int)((unsigned int)v1596 >> 2)) >> 1))))) >> 31)) | (~(((v1604 ^ ((int)((unsigned int)((int)((unsigned int)v1596 >> 2)) >> 1))) | (-(v1604 ^ ((int)((unsigned int)((int)((unsigned int)v1596 >> 2)) >> 1))))) >> 31))) == 0);
    int v1690;
    if (v1758) {
      int * v1627 = v1585->cache_age;
      int v1760 = (4 + ((((int)((unsigned int)((int)((unsigned int)v1596 >> 2)) >> 1)) & 3) * 2)) + ((~(((v1604 ^ ((int)((unsigned int)((int)((unsigned int)v1596 >> 2)) >> 1))) | (-(v1604 ^ ((int)((unsigned int)((int)((unsigned int)v1596 >> 2)) >> 1))))) >> 31)) & 1);
      int v1628 = v1627[v1760];
      int * v1629 = v1585->cache_age;
      int v1630 = v1629[v1739];
      int * v1631 = v1585->cache_age;
      int v1763 = v1630 + ((int)((unsigned int)(v1630 - v1628) >> 31));
      v1631[v1739] = v1763;
      int * v1633 = v1585->cache_age;
      int v1634 = v1633[v1741];
      int * v1635 = v1585->cache_age;
      int v1766 = v1634 + ((int)((unsigned int)(v1634 - v1628) >> 31));
      v1635[v1741] = v1766;
      int * v1637 = v1585->cache_age;
      v1637[v1760] = 0;
      v1690 = v1760;
    } else {
      int * v1640 = v1585->cache_age;
      int v1770 = 4 + ((((int)((unsigned int)((int)((unsigned int)v1596 >> 2)) >> 1)) & 3) * 2);
      int v1641 = v1640[v1770];
      int * v1642 = v1585->cache_tags;
      int v1643 = v1642[v1770];
      int * v1644 = v1585->cache_age;
      int v1645 = v1644[v1741];
      int * v1646 = v1585->cache_tags;
      int v1647 = v1646[v1741];
      int * v1648 = v1585->cache_dirty;
      int v1775 = (4 + ((((int)((unsigned int)((int)((unsigned int)v1596 >> 2)) >> 1)) & 3) * 2)) + ((((v1641 + ((~(((v1643 ^ -1) | (-(v1643 ^ -1))) >> 31)) & 2)) - (v1645 + ((~(((v1647 ^ -1) | (-(v1647 ^ -1))) >> 31)) & 2))) >> 31) & 1);
      int v1649 = v1648[v1775];
      bool v1776 = !(v1649 == 0);
      if (v1776) {
        int * v1650 = v1585->cache_tags;
        int v1651 = v1650[v1775];
        int * v1652 = v1585->cache_vals;
        int v1779 = ((4 + ((((int)((unsigned int)((int)((unsigned int)v1596 >> 2)) >> 1)) & 3) * 2)) + ((((v1641 + ((~(((v1643 ^ -1) | (-(v1643 ^ -1))) >> 31)) & 2)) - (v1645 + ((~(((v1647 ^ -1) | (-(v1647 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
        int v1653 = v1652[v1779];
        int * v1654 = v1585->cache_vals;
        int v1781 = (((4 + ((((int)((unsigned int)((int)((unsigned int)v1596 >> 2)) >> 1)) & 3) * 2)) + ((((v1641 + ((~(((v1643 ^ -1) | (-(v1643 ^ -1))) >> 31)) & 2)) - (v1645 + ((~(((v1647 ^ -1) | (-(v1647 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
        int v1655 = v1654[v1781];
        int * v1656 = v1585->mem;
        int v1783 = v1651 * 2;
        v1656[v1783] = v1653;
        int * v1658 = v1585->mem;
        int v1786 = (v1651 * 2) + 1;
        v1658[v1786] = v1655;
        ;
      } else {
        ;
      }
      int * v1663 = v1585->mem;
      int v1791 = ((int)((unsigned int)((int)((unsigned int)v1596 >> 2)) >> 1)) * 2;
      int v1664 = v1663[v1791];
      int * v1665 = v1585->mem;
      int v1793 = (((int)((unsigned int)((int)((unsigned int)v1596 >> 2)) >> 1)) * 2) + 1;
      int v1666 = v1665[v1793];
      int * v1667 = v1585->cache_vals;
      int v1795 = ((4 + ((((int)((unsigned int)((int)((unsigned int)v1596 >> 2)) >> 1)) & 3) * 2)) + ((((v1641 + ((~(((v1643 ^ -1) | (-(v1643 ^ -1))) >> 31)) & 2)) - (v1645 + ((~(((v1647 ^ -1) | (-(v1647 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
      v1667[v1795] = v1664;
      int * v1669 = v1585->cache_vals;
      int v1798 = (((4 + ((((int)((unsigned int)((int)((unsigned int)v1596 >> 2)) >> 1)) & 3) * 2)) + ((((v1641 + ((~(((v1643 ^ -1) | (-(v1643 ^ -1))) >> 31)) & 2)) - (v1645 + ((~(((v1647 ^ -1) | (-(v1647 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
      v1669[v1798] = v1666;
      int * v1671 = v1585->cache_tags;
      int v1801 = (int)((unsigned int)((int)((unsigned int)v1596 >> 2)) >> 1);
      v1671[v1775] = v1801;
      int * v1673 = v1585->cache_dirty;
      v1673[v1775] = 0;
      int * v1675 = v1585->cache_age;
      v1675[v1775] = 1;
      int * v1677 = v1585->cache_age;
      int v1678 = v1677[v1775];
      int * v1679 = v1585->cache_age;
      int v1680 = v1679[v1739];
      int * v1681 = v1585->cache_age;
      int v1809 = v1680 + ((int)((unsigned int)(v1680 - v1678) >> 31));
      v1681[v1739] = v1809;
      int * v1683 = v1585->cache_age;
      int v1684 = v1683[v1741];
      int * v1685 = v1585->cache_age;
      int v1812 = v1684 + ((int)((unsigned int)(v1684 - v1678) >> 31));
      v1685[v1741] = v1812;
      int * v1687 = v1585->cache_age;
      v1687[v1775] = 0;
      v1690 = v1775;
    }
    int * v1691 = v1585->cache_vals;
    int v1815 = v1690 * 2;
    int v1692 = v1691[v1815];
    int * v1693 = v1585->cache_vals;
    int v1817 = (v1690 * 2) + 1;
    int v1694 = v1693[v1817];
    int * v1695 = v1585->cache_vals;
    int v1819 = (((((int)((unsigned int)((int)((unsigned int)v1596 >> 2)) >> 1)) & 1) * 2) + ((((v1620 + ((~(((v1622 ^ -1) | (-(v1622 ^ -1))) >> 31)) & 2)) - (v1624 + ((~(((v1626 ^ -1) | (-(v1626 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
    v1695[v1819] = v1692;
    int * v1697 = v1585->cache_vals;
    int v1822 = ((((((int)((unsigned int)((int)((unsigned int)v1596 >> 2)) >> 1)) & 1) * 2) + ((((v1620 + ((~(((v1622 ^ -1) | (-(v1622 ^ -1))) >> 31)) & 2)) - (v1624 + ((~(((v1626 ^ -1) | (-(v1626 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
    v1697[v1822] = v1694;
    int * v1699 = v1585->cache_tags;
    int v1825 = ((((int)((unsigned int)((int)((unsigned int)v1596 >> 2)) >> 1)) & 1) * 2) + ((((v1620 + ((~(((v1622 ^ -1) | (-(v1622 ^ -1))) >> 31)) & 2)) - (v1624 + ((~(((v1626 ^ -1) | (-(v1626 ^ -1))) >> 31)) & 2))) >> 31) & 1);
    int v1826 = (int)((unsigned int)((int)((unsigned int)v1596 >> 2)) >> 1);
    v1699[v1825] = v1826;
    int * v1701 = v1585->cache_dirty;
    v1701[v1825] = 0;
    int * v1703 = v1585->cache_age;
    v1703[v1825] = 1;
    int * v1705 = v1585->cache_age;
    int v1706 = v1705[v1825];
    int * v1707 = v1585->cache_age;
    int v1708 = v1707[v1735];
    int * v1709 = v1585->cache_age;
    int v1834 = v1708 + ((int)((unsigned int)(v1708 - v1706) >> 31));
    v1709[v1735] = v1834;
    int * v1711 = v1585->cache_age;
    int v1712 = v1711[v1737];
    int * v1713 = v1585->cache_age;
    int v1837 = v1712 + ((int)((unsigned int)(v1712 - v1706) >> 31));
    v1713[v1737] = v1837;
    int * v1715 = v1585->cache_age;
    v1715[v1825] = 0;
    v1718 = v1825;
  }
  int v1840 = (v1718 * 2) + (((int)((unsigned int)v1596 >> 2)) & 1);
  int v1719 = v1605[v1840];
  int * v1720 = v1585->reg_ready;
  int v1842 = ((v1594 + ((v1590 - v1594) & (~((v1590 - v1594) >> 31)))) + 1) + ((100 ^ (((~(((v1602 ^ ((int)((unsigned int)((int)((unsigned int)v1596 >> 2)) >> 1))) | (-(v1602 ^ ((int)((unsigned int)((int)((unsigned int)v1596 >> 2)) >> 1))))) >> 31)) | (~(((v1604 ^ ((int)((unsigned int)((int)((unsigned int)v1596 >> 2)) >> 1))) | (-(v1604 ^ ((int)((unsigned int)((int)((unsigned int)v1596 >> 2)) >> 1))))) >> 31))) & 104)) ^ (((~(((v1598 ^ ((int)((unsigned int)((int)((unsigned int)v1596 >> 2)) >> 1))) | (-(v1598 ^ ((int)((unsigned int)((int)((unsigned int)v1596 >> 2)) >> 1))))) >> 31)) | (~(((v1600 ^ ((int)((unsigned int)((int)((unsigned int)v1596 >> 2)) >> 1))) | (-(v1600 ^ ((int)((unsigned int)((int)((unsigned int)v1596 >> 2)) >> 1))))) >> 31))) & (1 ^ (100 ^ (((~(((v1602 ^ ((int)((unsigned int)((int)((unsigned int)v1596 >> 2)) >> 1))) | (-(v1602 ^ ((int)((unsigned int)((int)((unsigned int)v1596 >> 2)) >> 1))))) >> 31)) | (~(((v1604 ^ ((int)((unsigned int)((int)((unsigned int)v1596 >> 2)) >> 1))) | (-(v1604 ^ ((int)((unsigned int)((int)((unsigned int)v1596 >> 2)) >> 1))))) >> 31))) & 104)))));
  v1720[11] = v1842;
  int * v1722 = v1585->regs;
  v1722[11] = v1719;
  struct StateT * v1724 = slot_24(v1585);
  return v1724;
}

struct StateT * slot_5(struct StateT * v83) {
  int * v84 = v83->saved_regs;
  int * v85 = v83->regs;
  int v86 = v85[5];
  v84[5] = v86;
  int v88 = v83->timer;
  int v89 = v83->timer;
  int v109 = v89 + 1;
  v83->timer = v109;
  int * v91 = v83->reg_ready;
  int v92 = v91[12];
  int * v93 = v83->regs;
  int v94 = v93[12];
  int * v95 = v83->reg_ready;
  int v96 = v95[14];
  int * v97 = v83->regs;
  int v98 = v97[14];
  int * v99 = v83->reg_ready;
  int v117 = (v96 + (((v92 + ((v88 - v92) & (~((v88 - v92) >> 31)))) - v96) & (~(((v92 + ((v88 - v92) & (~((v88 - v92) >> 31)))) - v96) >> 31)))) + 1;
  v99[5] = v117;
  int * v101 = v83->regs;
  int v119 = v94 + v98;
  v101[5] = v119;
  struct StateT * v103 = slot_6(v83);
  return v103;
}

struct StateT * slot_2(struct StateT * v38) {
  int v39 = v38->timer;
  int v40 = v38->timer;
  int v48 = v40 + 1;
  v38->timer = v48;
  int * v42 = v38->reg_ready;
  int v51 = v39 + 1;
  v42[14] = v51;
  int * v44 = v38->regs;
  v44[14] = 0;
  struct StateT * v46 = slot_3(v38);
  return v46;
}

struct StateT * slot_7(struct StateT * v384) {
  int * v385 = v384->saved_regs;
  int * v386 = v384->regs;
  int v387 = v386[6];
  v385[6] = v387;
  int v389 = v384->timer;
  int v390 = v384->timer;
  int v410 = v390 + 1;
  v384->timer = v410;
  int * v392 = v384->reg_ready;
  int v393 = v392[13];
  int * v394 = v384->regs;
  int v395 = v394[13];
  int * v396 = v384->reg_ready;
  int v397 = v396[14];
  int * v398 = v384->regs;
  int v399 = v398[14];
  int * v400 = v384->reg_ready;
  int v418 = (v397 + (((v393 + ((v389 - v393) & (~((v389 - v393) >> 31)))) - v397) & (~(((v393 + ((v389 - v393) & (~((v389 - v393) >> 31)))) - v397) >> 31)))) + 1;
  v400[6] = v418;
  int * v402 = v384->regs;
  int v420 = v395 + v399;
  v402[6] = v420;
  struct StateT * v404 = slot_8(v384);
  return v404;
}

struct StateT * slot_21(struct StateT * v1284) {
  int * v1285 = v1284->saved_regs;
  int * v1286 = v1284->regs;
  int v1287 = v1286[10];
  v1285[10] = v1287;
  int v1289 = v1284->timer;
  int v1290 = v1284->timer;
  int v1429 = v1290 + 1;
  v1284->timer = v1429;
  int * v1292 = v1284->reg_ready;
  int v1293 = v1292[5];
  int * v1294 = v1284->regs;
  int v1295 = v1294[5];
  int * v1296 = v1284->cache_tags;
  int v1434 = (((int)((unsigned int)((int)((unsigned int)v1295 >> 2)) >> 1)) & 1) * 2;
  int v1297 = v1296[v1434];
  int * v1298 = v1284->cache_tags;
  int v1436 = ((((int)((unsigned int)((int)((unsigned int)v1295 >> 2)) >> 1)) & 1) * 2) + 1;
  int v1299 = v1298[v1436];
  int * v1300 = v1284->cache_tags;
  int v1438 = 4 + ((((int)((unsigned int)((int)((unsigned int)v1295 >> 2)) >> 1)) & 3) * 2);
  int v1301 = v1300[v1438];
  int * v1302 = v1284->cache_tags;
  int v1440 = (4 + ((((int)((unsigned int)((int)((unsigned int)v1295 >> 2)) >> 1)) & 3) * 2)) + 1;
  int v1303 = v1302[v1440];
  int * v1304 = v1284->cache_vals;
  bool v1441 = !(((~(((v1297 ^ ((int)((unsigned int)((int)((unsigned int)v1295 >> 2)) >> 1))) | (-(v1297 ^ ((int)((unsigned int)((int)((unsigned int)v1295 >> 2)) >> 1))))) >> 31)) | (~(((v1299 ^ ((int)((unsigned int)((int)((unsigned int)v1295 >> 2)) >> 1))) | (-(v1299 ^ ((int)((unsigned int)((int)((unsigned int)v1295 >> 2)) >> 1))))) >> 31))) == 0);
  int v1417;
  if (v1441) {
    int * v1305 = v1284->cache_age;
    int v1443 = ((((int)((unsigned int)((int)((unsigned int)v1295 >> 2)) >> 1)) & 1) * 2) + ((~(((v1299 ^ ((int)((unsigned int)((int)((unsigned int)v1295 >> 2)) >> 1))) | (-(v1299 ^ ((int)((unsigned int)((int)((unsigned int)v1295 >> 2)) >> 1))))) >> 31)) & 1);
    int v1306 = v1305[v1443];
    int * v1307 = v1284->cache_age;
    int v1308 = v1307[v1434];
    int * v1309 = v1284->cache_age;
    int v1446 = v1308 + ((int)((unsigned int)(v1308 - v1306) >> 31));
    v1309[v1434] = v1446;
    int * v1311 = v1284->cache_age;
    int v1312 = v1311[v1436];
    int * v1313 = v1284->cache_age;
    int v1449 = v1312 + ((int)((unsigned int)(v1312 - v1306) >> 31));
    v1313[v1436] = v1449;
    int * v1315 = v1284->cache_age;
    v1315[v1443] = 0;
    v1417 = v1443;
  } else {
    int * v1318 = v1284->cache_age;
    int v1453 = (((int)((unsigned int)((int)((unsigned int)v1295 >> 2)) >> 1)) & 1) * 2;
    int v1319 = v1318[v1453];
    int * v1320 = v1284->cache_tags;
    int v1321 = v1320[v1453];
    int * v1322 = v1284->cache_age;
    int v1323 = v1322[v1436];
    int * v1324 = v1284->cache_tags;
    int v1325 = v1324[v1436];
    bool v1457 = !(((~(((v1301 ^ ((int)((unsigned int)((int)((unsigned int)v1295 >> 2)) >> 1))) | (-(v1301 ^ ((int)((unsigned int)((int)((unsigned int)v1295 >> 2)) >> 1))))) >> 31)) | (~(((v1303 ^ ((int)((unsigned int)((int)((unsigned int)v1295 >> 2)) >> 1))) | (-(v1303 ^ ((int)((unsigned int)((int)((unsigned int)v1295 >> 2)) >> 1))))) >> 31))) == 0);
    int v1389;
    if (v1457) {
      int * v1326 = v1284->cache_age;
      int v1459 = (4 + ((((int)((unsigned int)((int)((unsigned int)v1295 >> 2)) >> 1)) & 3) * 2)) + ((~(((v1303 ^ ((int)((unsigned int)((int)((unsigned int)v1295 >> 2)) >> 1))) | (-(v1303 ^ ((int)((unsigned int)((int)((unsigned int)v1295 >> 2)) >> 1))))) >> 31)) & 1);
      int v1327 = v1326[v1459];
      int * v1328 = v1284->cache_age;
      int v1329 = v1328[v1438];
      int * v1330 = v1284->cache_age;
      int v1462 = v1329 + ((int)((unsigned int)(v1329 - v1327) >> 31));
      v1330[v1438] = v1462;
      int * v1332 = v1284->cache_age;
      int v1333 = v1332[v1440];
      int * v1334 = v1284->cache_age;
      int v1465 = v1333 + ((int)((unsigned int)(v1333 - v1327) >> 31));
      v1334[v1440] = v1465;
      int * v1336 = v1284->cache_age;
      v1336[v1459] = 0;
      v1389 = v1459;
    } else {
      int * v1339 = v1284->cache_age;
      int v1469 = 4 + ((((int)((unsigned int)((int)((unsigned int)v1295 >> 2)) >> 1)) & 3) * 2);
      int v1340 = v1339[v1469];
      int * v1341 = v1284->cache_tags;
      int v1342 = v1341[v1469];
      int * v1343 = v1284->cache_age;
      int v1344 = v1343[v1440];
      int * v1345 = v1284->cache_tags;
      int v1346 = v1345[v1440];
      int * v1347 = v1284->cache_dirty;
      int v1474 = (4 + ((((int)((unsigned int)((int)((unsigned int)v1295 >> 2)) >> 1)) & 3) * 2)) + ((((v1340 + ((~(((v1342 ^ -1) | (-(v1342 ^ -1))) >> 31)) & 2)) - (v1344 + ((~(((v1346 ^ -1) | (-(v1346 ^ -1))) >> 31)) & 2))) >> 31) & 1);
      int v1348 = v1347[v1474];
      bool v1475 = !(v1348 == 0);
      if (v1475) {
        int * v1349 = v1284->cache_tags;
        int v1350 = v1349[v1474];
        int * v1351 = v1284->cache_vals;
        int v1478 = ((4 + ((((int)((unsigned int)((int)((unsigned int)v1295 >> 2)) >> 1)) & 3) * 2)) + ((((v1340 + ((~(((v1342 ^ -1) | (-(v1342 ^ -1))) >> 31)) & 2)) - (v1344 + ((~(((v1346 ^ -1) | (-(v1346 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
        int v1352 = v1351[v1478];
        int * v1353 = v1284->cache_vals;
        int v1480 = (((4 + ((((int)((unsigned int)((int)((unsigned int)v1295 >> 2)) >> 1)) & 3) * 2)) + ((((v1340 + ((~(((v1342 ^ -1) | (-(v1342 ^ -1))) >> 31)) & 2)) - (v1344 + ((~(((v1346 ^ -1) | (-(v1346 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
        int v1354 = v1353[v1480];
        int * v1355 = v1284->mem;
        int v1482 = v1350 * 2;
        v1355[v1482] = v1352;
        int * v1357 = v1284->mem;
        int v1485 = (v1350 * 2) + 1;
        v1357[v1485] = v1354;
        ;
      } else {
        ;
      }
      int * v1362 = v1284->mem;
      int v1490 = ((int)((unsigned int)((int)((unsigned int)v1295 >> 2)) >> 1)) * 2;
      int v1363 = v1362[v1490];
      int * v1364 = v1284->mem;
      int v1492 = (((int)((unsigned int)((int)((unsigned int)v1295 >> 2)) >> 1)) * 2) + 1;
      int v1365 = v1364[v1492];
      int * v1366 = v1284->cache_vals;
      int v1494 = ((4 + ((((int)((unsigned int)((int)((unsigned int)v1295 >> 2)) >> 1)) & 3) * 2)) + ((((v1340 + ((~(((v1342 ^ -1) | (-(v1342 ^ -1))) >> 31)) & 2)) - (v1344 + ((~(((v1346 ^ -1) | (-(v1346 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
      v1366[v1494] = v1363;
      int * v1368 = v1284->cache_vals;
      int v1497 = (((4 + ((((int)((unsigned int)((int)((unsigned int)v1295 >> 2)) >> 1)) & 3) * 2)) + ((((v1340 + ((~(((v1342 ^ -1) | (-(v1342 ^ -1))) >> 31)) & 2)) - (v1344 + ((~(((v1346 ^ -1) | (-(v1346 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
      v1368[v1497] = v1365;
      int * v1370 = v1284->cache_tags;
      int v1500 = (int)((unsigned int)((int)((unsigned int)v1295 >> 2)) >> 1);
      v1370[v1474] = v1500;
      int * v1372 = v1284->cache_dirty;
      v1372[v1474] = 0;
      int * v1374 = v1284->cache_age;
      v1374[v1474] = 1;
      int * v1376 = v1284->cache_age;
      int v1377 = v1376[v1474];
      int * v1378 = v1284->cache_age;
      int v1379 = v1378[v1438];
      int * v1380 = v1284->cache_age;
      int v1508 = v1379 + ((int)((unsigned int)(v1379 - v1377) >> 31));
      v1380[v1438] = v1508;
      int * v1382 = v1284->cache_age;
      int v1383 = v1382[v1440];
      int * v1384 = v1284->cache_age;
      int v1511 = v1383 + ((int)((unsigned int)(v1383 - v1377) >> 31));
      v1384[v1440] = v1511;
      int * v1386 = v1284->cache_age;
      v1386[v1474] = 0;
      v1389 = v1474;
    }
    int * v1390 = v1284->cache_vals;
    int v1514 = v1389 * 2;
    int v1391 = v1390[v1514];
    int * v1392 = v1284->cache_vals;
    int v1516 = (v1389 * 2) + 1;
    int v1393 = v1392[v1516];
    int * v1394 = v1284->cache_vals;
    int v1518 = (((((int)((unsigned int)((int)((unsigned int)v1295 >> 2)) >> 1)) & 1) * 2) + ((((v1319 + ((~(((v1321 ^ -1) | (-(v1321 ^ -1))) >> 31)) & 2)) - (v1323 + ((~(((v1325 ^ -1) | (-(v1325 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
    v1394[v1518] = v1391;
    int * v1396 = v1284->cache_vals;
    int v1521 = ((((((int)((unsigned int)((int)((unsigned int)v1295 >> 2)) >> 1)) & 1) * 2) + ((((v1319 + ((~(((v1321 ^ -1) | (-(v1321 ^ -1))) >> 31)) & 2)) - (v1323 + ((~(((v1325 ^ -1) | (-(v1325 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
    v1396[v1521] = v1393;
    int * v1398 = v1284->cache_tags;
    int v1524 = ((((int)((unsigned int)((int)((unsigned int)v1295 >> 2)) >> 1)) & 1) * 2) + ((((v1319 + ((~(((v1321 ^ -1) | (-(v1321 ^ -1))) >> 31)) & 2)) - (v1323 + ((~(((v1325 ^ -1) | (-(v1325 ^ -1))) >> 31)) & 2))) >> 31) & 1);
    int v1525 = (int)((unsigned int)((int)((unsigned int)v1295 >> 2)) >> 1);
    v1398[v1524] = v1525;
    int * v1400 = v1284->cache_dirty;
    v1400[v1524] = 0;
    int * v1402 = v1284->cache_age;
    v1402[v1524] = 1;
    int * v1404 = v1284->cache_age;
    int v1405 = v1404[v1524];
    int * v1406 = v1284->cache_age;
    int v1407 = v1406[v1434];
    int * v1408 = v1284->cache_age;
    int v1533 = v1407 + ((int)((unsigned int)(v1407 - v1405) >> 31));
    v1408[v1434] = v1533;
    int * v1410 = v1284->cache_age;
    int v1411 = v1410[v1436];
    int * v1412 = v1284->cache_age;
    int v1536 = v1411 + ((int)((unsigned int)(v1411 - v1405) >> 31));
    v1412[v1436] = v1536;
    int * v1414 = v1284->cache_age;
    v1414[v1524] = 0;
    v1417 = v1524;
  }
  int v1539 = (v1417 * 2) + (((int)((unsigned int)v1295 >> 2)) & 1);
  int v1418 = v1304[v1539];
  int * v1419 = v1284->reg_ready;
  int v1541 = ((v1293 + ((v1289 - v1293) & (~((v1289 - v1293) >> 31)))) + 1) + ((100 ^ (((~(((v1301 ^ ((int)((unsigned int)((int)((unsigned int)v1295 >> 2)) >> 1))) | (-(v1301 ^ ((int)((unsigned int)((int)((unsigned int)v1295 >> 2)) >> 1))))) >> 31)) | (~(((v1303 ^ ((int)((unsigned int)((int)((unsigned int)v1295 >> 2)) >> 1))) | (-(v1303 ^ ((int)((unsigned int)((int)((unsigned int)v1295 >> 2)) >> 1))))) >> 31))) & 104)) ^ (((~(((v1297 ^ ((int)((unsigned int)((int)((unsigned int)v1295 >> 2)) >> 1))) | (-(v1297 ^ ((int)((unsigned int)((int)((unsigned int)v1295 >> 2)) >> 1))))) >> 31)) | (~(((v1299 ^ ((int)((unsigned int)((int)((unsigned int)v1295 >> 2)) >> 1))) | (-(v1299 ^ ((int)((unsigned int)((int)((unsigned int)v1295 >> 2)) >> 1))))) >> 31))) & (1 ^ (100 ^ (((~(((v1301 ^ ((int)((unsigned int)((int)((unsigned int)v1295 >> 2)) >> 1))) | (-(v1301 ^ ((int)((unsigned int)((int)((unsigned int)v1295 >> 2)) >> 1))))) >> 31)) | (~(((v1303 ^ ((int)((unsigned int)((int)((unsigned int)v1295 >> 2)) >> 1))) | (-(v1303 ^ ((int)((unsigned int)((int)((unsigned int)v1295 >> 2)) >> 1))))) >> 31))) & 104)))));
  v1419[10] = v1541;
  int * v1421 = v1284->regs;
  v1421[10] = v1418;
  struct StateT * v1423 = slot_22(v1284);
  return v1423;
}

struct StateT * slot_3(struct StateT * v56) {
  int v57 = v56->timer;
  int v58 = v56->timer;
  int v66 = v58 + 1;
  v56->timer = v66;
  int * v60 = v56->reg_ready;
  int v69 = v57 + 1;
  v60[15] = v69;
  int * v62 = v56->regs;
  v62[15] = 16;
  struct StateT * v64 = slot_4(v56);
  return v64;
}

struct StateT * slot_26(struct StateT * v2104) {
  int v2105 = v2104->timer;
  int v2106 = v2104->timer;
  int v2110 = v2106 + 1;
  v2104->timer = v2110;
  struct StateT * v2108 = slot_28(v2104);
  return v2108;
}

struct StateT * slot_10(struct StateT * v927) {
  int v928 = v927->timer;
  int v929 = v927->timer;
  int v936 = v929 + 1;
  v927->timer = v936;
  int * v931 = v927->reg_ready;
  int v939 = v928 + 1;
  v931[10] = v939;
  int * v933 = v927->regs;
  v933[10] = 1;
  return v927;
}

struct StateT * slot_1(struct StateT * v20) {
  int v21 = v20->timer;
  int v22 = v20->timer;
  int v30 = v22 + 1;
  v20->timer = v30;
  int * v24 = v20->reg_ready;
  int v33 = v21 + 1;
  v24[13] = v33;
  int * v26 = v20->regs;
  v26[13] = 80;
  struct StateT * v28 = slot_2(v20);
  return v28;
}

struct StateT * slot_13(struct StateT * v951) {
  int * v952 = v951->saved_regs;
  int * v953 = v951->regs;
  int v954 = v953[14];
  v952[14] = v954;
  int v956 = v951->timer;
  int v957 = v951->timer;
  int v973 = v957 + 1;
  v951->timer = v973;
  int * v959 = v951->reg_ready;
  int v960 = v959[14];
  int * v961 = v951->regs;
  int v962 = v961[14];
  int * v963 = v951->reg_ready;
  int v977 = (v960 + ((v956 - v960) & (~((v956 - v960) >> 31)))) + 1;
  v963[14] = v977;
  int * v965 = v951->regs;
  int v979 = v962 + 4;
  v965[14] = v979;
  struct StateT * v967 = slot_14(v951);
  return v967;
}

struct StateT * slot_24(struct StateT * v1847) {
  int * v1848 = v1847->regs;
  int v1849 = v1848[14];
  int * v1850 = v1847->regs;
  int v1851 = v1850[15];
  bool v1976 = v1849 >= v1851;
  struct StateT * v1970;
  if (v1976) {
    int v1852 = v1847->timer;
    int v1977 = v1852 + 15;
    v1847->timer = v1977;
    int * v1854 = v1847->saved_regs;
    int v1855 = v1854[5];
    int * v1856 = v1847->regs;
    v1856[5] = v1855;
    int * v1858 = v1847->saved_regs;
    int v1859 = v1858[10];
    int * v1860 = v1847->regs;
    v1860[10] = v1859;
    int * v1862 = v1847->saved_regs;
    int v1863 = v1862[6];
    int * v1864 = v1847->regs;
    v1864[6] = v1863;
    int * v1866 = v1847->saved_regs;
    int v1867 = v1866[11];
    int * v1868 = v1847->regs;
    v1868[11] = v1867;
    int * v1870 = v1847->reg_ready;
    int v1871 = v1847->timer;
    v1870[0] = v1871;
    int * v1873 = v1847->reg_ready;
    int v1874 = v1847->timer;
    v1873[1] = v1874;
    int * v1876 = v1847->reg_ready;
    int v1877 = v1847->timer;
    v1876[2] = v1877;
    int * v1879 = v1847->reg_ready;
    int v1880 = v1847->timer;
    v1879[3] = v1880;
    int * v1882 = v1847->reg_ready;
    int v1883 = v1847->timer;
    v1882[4] = v1883;
    int * v1885 = v1847->reg_ready;
    int v1886 = v1847->timer;
    v1885[5] = v1886;
    int * v1888 = v1847->reg_ready;
    int v1889 = v1847->timer;
    v1888[6] = v1889;
    int * v1891 = v1847->reg_ready;
    int v1892 = v1847->timer;
    v1891[7] = v1892;
    int * v1894 = v1847->reg_ready;
    int v1895 = v1847->timer;
    v1894[8] = v1895;
    int * v1897 = v1847->reg_ready;
    int v1898 = v1847->timer;
    v1897[9] = v1898;
    int * v1900 = v1847->reg_ready;
    int v1901 = v1847->timer;
    v1900[10] = v1901;
    int * v1903 = v1847->reg_ready;
    int v1904 = v1847->timer;
    v1903[11] = v1904;
    int * v1906 = v1847->reg_ready;
    int v1907 = v1847->timer;
    v1906[12] = v1907;
    int * v1909 = v1847->reg_ready;
    int v1910 = v1847->timer;
    v1909[13] = v1910;
    int * v1912 = v1847->reg_ready;
    int v1913 = v1847->timer;
    v1912[14] = v1913;
    int * v1915 = v1847->reg_ready;
    int v1916 = v1847->timer;
    v1915[15] = v1916;
    int * v1918 = v1847->reg_ready;
    int v1919 = v1847->timer;
    v1918[16] = v1919;
    int * v1921 = v1847->reg_ready;
    int v1922 = v1847->timer;
    v1921[17] = v1922;
    int * v1924 = v1847->reg_ready;
    int v1925 = v1847->timer;
    v1924[18] = v1925;
    int * v1927 = v1847->reg_ready;
    int v1928 = v1847->timer;
    v1927[19] = v1928;
    int * v1930 = v1847->reg_ready;
    int v1931 = v1847->timer;
    v1930[20] = v1931;
    int * v1933 = v1847->reg_ready;
    int v1934 = v1847->timer;
    v1933[21] = v1934;
    int * v1936 = v1847->reg_ready;
    int v1937 = v1847->timer;
    v1936[22] = v1937;
    int * v1939 = v1847->reg_ready;
    int v1940 = v1847->timer;
    v1939[23] = v1940;
    int * v1942 = v1847->reg_ready;
    int v1943 = v1847->timer;
    v1942[24] = v1943;
    int * v1945 = v1847->reg_ready;
    int v1946 = v1847->timer;
    v1945[25] = v1946;
    int * v1948 = v1847->reg_ready;
    int v1949 = v1847->timer;
    v1948[26] = v1949;
    int * v1951 = v1847->reg_ready;
    int v1952 = v1847->timer;
    v1951[27] = v1952;
    int * v1954 = v1847->reg_ready;
    int v1955 = v1847->timer;
    v1954[28] = v1955;
    int * v1957 = v1847->reg_ready;
    int v1958 = v1847->timer;
    v1957[29] = v1958;
    int * v1960 = v1847->reg_ready;
    int v1961 = v1847->timer;
    v1960[30] = v1961;
    int * v1963 = v1847->reg_ready;
    int v1964 = v1847->timer;
    v1963[31] = v1964;
    struct StateT * v1966 = slot_25(v1847);
    v1970 = v1966;
  } else {
    struct StateT * v1968 = slot_26(v1847);
    v1970 = v1968;
  }
  return v1970;
}

struct StateT * slot_0(struct StateT * v2) {
  int v3 = v2->timer;
  int v4 = v2->timer;
  int v12 = v4 + 1;
  v2->timer = v12;
  int * v6 = v2->reg_ready;
  int v15 = v3 + 1;
  v6[12] = v15;
  int * v8 = v2->regs;
  v8[12] = 0;
  struct StateT * v10 = slot_1(v2);
  return v10;
}

struct StateT * slot_14(struct StateT * v982) {
  int * v983 = v982->regs;
  int v984 = v983[10];
  int * v985 = v982->regs;
  int v986 = v985[11];
  bool v1099 = !(v984 == v986);
  struct StateT * v1093;
  if (v1099) {
    int v987 = v982->timer;
    int v1100 = v987 + 15;
    v982->timer = v1100;
    int * v989 = v982->saved_regs;
    int v990 = v989[14];
    int * v991 = v982->regs;
    v991[14] = v990;
    int * v993 = v982->reg_ready;
    int v994 = v982->timer;
    v993[0] = v994;
    int * v996 = v982->reg_ready;
    int v997 = v982->timer;
    v996[1] = v997;
    int * v999 = v982->reg_ready;
    int v1000 = v982->timer;
    v999[2] = v1000;
    int * v1002 = v982->reg_ready;
    int v1003 = v982->timer;
    v1002[3] = v1003;
    int * v1005 = v982->reg_ready;
    int v1006 = v982->timer;
    v1005[4] = v1006;
    int * v1008 = v982->reg_ready;
    int v1009 = v982->timer;
    v1008[5] = v1009;
    int * v1011 = v982->reg_ready;
    int v1012 = v982->timer;
    v1011[6] = v1012;
    int * v1014 = v982->reg_ready;
    int v1015 = v982->timer;
    v1014[7] = v1015;
    int * v1017 = v982->reg_ready;
    int v1018 = v982->timer;
    v1017[8] = v1018;
    int * v1020 = v982->reg_ready;
    int v1021 = v982->timer;
    v1020[9] = v1021;
    int * v1023 = v982->reg_ready;
    int v1024 = v982->timer;
    v1023[10] = v1024;
    int * v1026 = v982->reg_ready;
    int v1027 = v982->timer;
    v1026[11] = v1027;
    int * v1029 = v982->reg_ready;
    int v1030 = v982->timer;
    v1029[12] = v1030;
    int * v1032 = v982->reg_ready;
    int v1033 = v982->timer;
    v1032[13] = v1033;
    int * v1035 = v982->reg_ready;
    int v1036 = v982->timer;
    v1035[14] = v1036;
    int * v1038 = v982->reg_ready;
    int v1039 = v982->timer;
    v1038[15] = v1039;
    int * v1041 = v982->reg_ready;
    int v1042 = v982->timer;
    v1041[16] = v1042;
    int * v1044 = v982->reg_ready;
    int v1045 = v982->timer;
    v1044[17] = v1045;
    int * v1047 = v982->reg_ready;
    int v1048 = v982->timer;
    v1047[18] = v1048;
    int * v1050 = v982->reg_ready;
    int v1051 = v982->timer;
    v1050[19] = v1051;
    int * v1053 = v982->reg_ready;
    int v1054 = v982->timer;
    v1053[20] = v1054;
    int * v1056 = v982->reg_ready;
    int v1057 = v982->timer;
    v1056[21] = v1057;
    int * v1059 = v982->reg_ready;
    int v1060 = v982->timer;
    v1059[22] = v1060;
    int * v1062 = v982->reg_ready;
    int v1063 = v982->timer;
    v1062[23] = v1063;
    int * v1065 = v982->reg_ready;
    int v1066 = v982->timer;
    v1065[24] = v1066;
    int * v1068 = v982->reg_ready;
    int v1069 = v982->timer;
    v1068[25] = v1069;
    int * v1071 = v982->reg_ready;
    int v1072 = v982->timer;
    v1071[26] = v1072;
    int * v1074 = v982->reg_ready;
    int v1075 = v982->timer;
    v1074[27] = v1075;
    int * v1077 = v982->reg_ready;
    int v1078 = v982->timer;
    v1077[28] = v1078;
    int * v1080 = v982->reg_ready;
    int v1081 = v982->timer;
    v1080[29] = v1081;
    int * v1083 = v982->reg_ready;
    int v1084 = v982->timer;
    v1083[30] = v1084;
    int * v1086 = v982->reg_ready;
    int v1087 = v982->timer;
    v1086[31] = v1087;
    struct StateT * v1089 = slot_15(v982);
    v1093 = v1089;
  } else {
    struct StateT * v1091 = slot_16(v982);
    v1093 = v1091;
  }
  return v1093;
}

struct StateT * slot_28(struct StateT * v2113) {
  int * v2114 = v2113->saved_regs;
  int * v2115 = v2113->regs;
  int v2116 = v2115[14];
  v2114[14] = v2116;
  int v2118 = v2113->timer;
  int v2119 = v2113->timer;
  int v2135 = v2119 + 1;
  v2113->timer = v2135;
  int * v2121 = v2113->reg_ready;
  int v2122 = v2121[14];
  int * v2123 = v2113->regs;
  int v2124 = v2123[14];
  int * v2125 = v2113->reg_ready;
  int v2139 = (v2122 + ((v2118 - v2122) & (~((v2118 - v2122) >> 31)))) + 1;
  v2125[14] = v2139;
  int * v2127 = v2113->regs;
  int v2141 = v2124 + 4;
  v2127[14] = v2141;
  struct StateT * v2129 = slot_29(v2113);
  return v2129;
}

struct StateT * slot_17(struct StateT * v1230) {
  int v1231 = v1230->timer;
  int v1232 = v1230->timer;
  int v1235 = v1232 + 1;
  v1230->timer = v1235;
  return v1230;
}

struct StateT * slot_20(struct StateT * v1245) {
  int * v1246 = v1245->saved_regs;
  int * v1247 = v1245->regs;
  int v1248 = v1247[5];
  v1246[5] = v1248;
  int v1250 = v1245->timer;
  int v1251 = v1245->timer;
  int v1271 = v1251 + 1;
  v1245->timer = v1271;
  int * v1253 = v1245->reg_ready;
  int v1254 = v1253[12];
  int * v1255 = v1245->regs;
  int v1256 = v1255[12];
  int * v1257 = v1245->reg_ready;
  int v1258 = v1257[14];
  int * v1259 = v1245->regs;
  int v1260 = v1259[14];
  int * v1261 = v1245->reg_ready;
  int v1279 = (v1258 + (((v1254 + ((v1250 - v1254) & (~((v1250 - v1254) >> 31)))) - v1258) & (~(((v1254 + ((v1250 - v1254) & (~((v1250 - v1254) >> 31)))) - v1258) >> 31)))) + 1;
  v1261[5] = v1279;
  int * v1263 = v1245->regs;
  int v1281 = v1256 + v1260;
  v1263[5] = v1281;
  struct StateT * v1265 = slot_21(v1245);
  return v1265;
}

struct StateT * snippet(struct StateT * v0) {
  struct StateT * v1 = slot_0(v0);
  int v2365 = v1->timer;
  int * v2366 = v1->reg_ready;
  int v2367 = v2366[0];
  int v2498 = v2367 + ((v2365 - v2367) & (~((v2365 - v2367) >> 31)));
  v1->timer = v2498;
  int v2369 = v1->timer;
  int * v2370 = v1->reg_ready;
  int v2371 = v2370[1];
  int v2501 = v2371 + ((v2369 - v2371) & (~((v2369 - v2371) >> 31)));
  v1->timer = v2501;
  int v2373 = v1->timer;
  int * v2374 = v1->reg_ready;
  int v2375 = v2374[2];
  int v2504 = v2375 + ((v2373 - v2375) & (~((v2373 - v2375) >> 31)));
  v1->timer = v2504;
  int v2377 = v1->timer;
  int * v2378 = v1->reg_ready;
  int v2379 = v2378[3];
  int v2507 = v2379 + ((v2377 - v2379) & (~((v2377 - v2379) >> 31)));
  v1->timer = v2507;
  int v2381 = v1->timer;
  int * v2382 = v1->reg_ready;
  int v2383 = v2382[4];
  int v2510 = v2383 + ((v2381 - v2383) & (~((v2381 - v2383) >> 31)));
  v1->timer = v2510;
  int v2385 = v1->timer;
  int * v2386 = v1->reg_ready;
  int v2387 = v2386[5];
  int v2513 = v2387 + ((v2385 - v2387) & (~((v2385 - v2387) >> 31)));
  v1->timer = v2513;
  int v2389 = v1->timer;
  int * v2390 = v1->reg_ready;
  int v2391 = v2390[6];
  int v2516 = v2391 + ((v2389 - v2391) & (~((v2389 - v2391) >> 31)));
  v1->timer = v2516;
  int v2393 = v1->timer;
  int * v2394 = v1->reg_ready;
  int v2395 = v2394[7];
  int v2519 = v2395 + ((v2393 - v2395) & (~((v2393 - v2395) >> 31)));
  v1->timer = v2519;
  int v2397 = v1->timer;
  int * v2398 = v1->reg_ready;
  int v2399 = v2398[8];
  int v2522 = v2399 + ((v2397 - v2399) & (~((v2397 - v2399) >> 31)));
  v1->timer = v2522;
  int v2401 = v1->timer;
  int * v2402 = v1->reg_ready;
  int v2403 = v2402[9];
  int v2525 = v2403 + ((v2401 - v2403) & (~((v2401 - v2403) >> 31)));
  v1->timer = v2525;
  int v2405 = v1->timer;
  int * v2406 = v1->reg_ready;
  int v2407 = v2406[10];
  int v2528 = v2407 + ((v2405 - v2407) & (~((v2405 - v2407) >> 31)));
  v1->timer = v2528;
  int v2409 = v1->timer;
  int * v2410 = v1->reg_ready;
  int v2411 = v2410[11];
  int v2531 = v2411 + ((v2409 - v2411) & (~((v2409 - v2411) >> 31)));
  v1->timer = v2531;
  int v2413 = v1->timer;
  int * v2414 = v1->reg_ready;
  int v2415 = v2414[12];
  int v2534 = v2415 + ((v2413 - v2415) & (~((v2413 - v2415) >> 31)));
  v1->timer = v2534;
  int v2417 = v1->timer;
  int * v2418 = v1->reg_ready;
  int v2419 = v2418[13];
  int v2537 = v2419 + ((v2417 - v2419) & (~((v2417 - v2419) >> 31)));
  v1->timer = v2537;
  int v2421 = v1->timer;
  int * v2422 = v1->reg_ready;
  int v2423 = v2422[14];
  int v2540 = v2423 + ((v2421 - v2423) & (~((v2421 - v2423) >> 31)));
  v1->timer = v2540;
  int v2425 = v1->timer;
  int * v2426 = v1->reg_ready;
  int v2427 = v2426[15];
  int v2543 = v2427 + ((v2425 - v2427) & (~((v2425 - v2427) >> 31)));
  v1->timer = v2543;
  int v2429 = v1->timer;
  int * v2430 = v1->reg_ready;
  int v2431 = v2430[16];
  int v2546 = v2431 + ((v2429 - v2431) & (~((v2429 - v2431) >> 31)));
  v1->timer = v2546;
  int v2433 = v1->timer;
  int * v2434 = v1->reg_ready;
  int v2435 = v2434[17];
  int v2549 = v2435 + ((v2433 - v2435) & (~((v2433 - v2435) >> 31)));
  v1->timer = v2549;
  int v2437 = v1->timer;
  int * v2438 = v1->reg_ready;
  int v2439 = v2438[18];
  int v2552 = v2439 + ((v2437 - v2439) & (~((v2437 - v2439) >> 31)));
  v1->timer = v2552;
  int v2441 = v1->timer;
  int * v2442 = v1->reg_ready;
  int v2443 = v2442[19];
  int v2555 = v2443 + ((v2441 - v2443) & (~((v2441 - v2443) >> 31)));
  v1->timer = v2555;
  int v2445 = v1->timer;
  int * v2446 = v1->reg_ready;
  int v2447 = v2446[20];
  int v2558 = v2447 + ((v2445 - v2447) & (~((v2445 - v2447) >> 31)));
  v1->timer = v2558;
  int v2449 = v1->timer;
  int * v2450 = v1->reg_ready;
  int v2451 = v2450[21];
  int v2561 = v2451 + ((v2449 - v2451) & (~((v2449 - v2451) >> 31)));
  v1->timer = v2561;
  int v2453 = v1->timer;
  int * v2454 = v1->reg_ready;
  int v2455 = v2454[22];
  int v2564 = v2455 + ((v2453 - v2455) & (~((v2453 - v2455) >> 31)));
  v1->timer = v2564;
  int v2457 = v1->timer;
  int * v2458 = v1->reg_ready;
  int v2459 = v2458[23];
  int v2567 = v2459 + ((v2457 - v2459) & (~((v2457 - v2459) >> 31)));
  v1->timer = v2567;
  int v2461 = v1->timer;
  int * v2462 = v1->reg_ready;
  int v2463 = v2462[24];
  int v2570 = v2463 + ((v2461 - v2463) & (~((v2461 - v2463) >> 31)));
  v1->timer = v2570;
  int v2465 = v1->timer;
  int * v2466 = v1->reg_ready;
  int v2467 = v2466[25];
  int v2573 = v2467 + ((v2465 - v2467) & (~((v2465 - v2467) >> 31)));
  v1->timer = v2573;
  int v2469 = v1->timer;
  int * v2470 = v1->reg_ready;
  int v2471 = v2470[26];
  int v2576 = v2471 + ((v2469 - v2471) & (~((v2469 - v2471) >> 31)));
  v1->timer = v2576;
  int v2473 = v1->timer;
  int * v2474 = v1->reg_ready;
  int v2475 = v2474[27];
  int v2579 = v2475 + ((v2473 - v2475) & (~((v2473 - v2475) >> 31)));
  v1->timer = v2579;
  int v2477 = v1->timer;
  int * v2478 = v1->reg_ready;
  int v2479 = v2478[28];
  int v2582 = v2479 + ((v2477 - v2479) & (~((v2477 - v2479) >> 31)));
  v1->timer = v2582;
  int v2481 = v1->timer;
  int * v2482 = v1->reg_ready;
  int v2483 = v2482[29];
  int v2585 = v2483 + ((v2481 - v2483) & (~((v2481 - v2483) >> 31)));
  v1->timer = v2585;
  int v2485 = v1->timer;
  int * v2486 = v1->reg_ready;
  int v2487 = v2486[30];
  int v2588 = v2487 + ((v2485 - v2487) & (~((v2485 - v2487) >> 31)));
  v1->timer = v2588;
  int v2489 = v1->timer;
  int * v2490 = v1->reg_ready;
  int v2491 = v2490[31];
  int v2591 = v2491 + ((v2489 - v2491) & (~((v2489 - v2491) >> 31)));
  v1->timer = v2591;
  return v1;
}

struct StateT * slot_8(struct StateT * v423) {
  int * v424 = v423->saved_regs;
  int * v425 = v423->regs;
  int v426 = v425[11];
  v424[11] = v426;
  int v428 = v423->timer;
  int v429 = v423->timer;
  int v568 = v429 + 1;
  v423->timer = v568;
  int * v431 = v423->reg_ready;
  int v432 = v431[6];
  int * v433 = v423->regs;
  int v434 = v433[6];
  int * v435 = v423->cache_tags;
  int v573 = (((int)((unsigned int)((int)((unsigned int)v434 >> 2)) >> 1)) & 1) * 2;
  int v436 = v435[v573];
  int * v437 = v423->cache_tags;
  int v575 = ((((int)((unsigned int)((int)((unsigned int)v434 >> 2)) >> 1)) & 1) * 2) + 1;
  int v438 = v437[v575];
  int * v439 = v423->cache_tags;
  int v577 = 4 + ((((int)((unsigned int)((int)((unsigned int)v434 >> 2)) >> 1)) & 3) * 2);
  int v440 = v439[v577];
  int * v441 = v423->cache_tags;
  int v579 = (4 + ((((int)((unsigned int)((int)((unsigned int)v434 >> 2)) >> 1)) & 3) * 2)) + 1;
  int v442 = v441[v579];
  int * v443 = v423->cache_vals;
  bool v580 = !(((~(((v436 ^ ((int)((unsigned int)((int)((unsigned int)v434 >> 2)) >> 1))) | (-(v436 ^ ((int)((unsigned int)((int)((unsigned int)v434 >> 2)) >> 1))))) >> 31)) | (~(((v438 ^ ((int)((unsigned int)((int)((unsigned int)v434 >> 2)) >> 1))) | (-(v438 ^ ((int)((unsigned int)((int)((unsigned int)v434 >> 2)) >> 1))))) >> 31))) == 0);
  int v556;
  if (v580) {
    int * v444 = v423->cache_age;
    int v582 = ((((int)((unsigned int)((int)((unsigned int)v434 >> 2)) >> 1)) & 1) * 2) + ((~(((v438 ^ ((int)((unsigned int)((int)((unsigned int)v434 >> 2)) >> 1))) | (-(v438 ^ ((int)((unsigned int)((int)((unsigned int)v434 >> 2)) >> 1))))) >> 31)) & 1);
    int v445 = v444[v582];
    int * v446 = v423->cache_age;
    int v447 = v446[v573];
    int * v448 = v423->cache_age;
    int v585 = v447 + ((int)((unsigned int)(v447 - v445) >> 31));
    v448[v573] = v585;
    int * v450 = v423->cache_age;
    int v451 = v450[v575];
    int * v452 = v423->cache_age;
    int v588 = v451 + ((int)((unsigned int)(v451 - v445) >> 31));
    v452[v575] = v588;
    int * v454 = v423->cache_age;
    v454[v582] = 0;
    v556 = v582;
  } else {
    int * v457 = v423->cache_age;
    int v592 = (((int)((unsigned int)((int)((unsigned int)v434 >> 2)) >> 1)) & 1) * 2;
    int v458 = v457[v592];
    int * v459 = v423->cache_tags;
    int v460 = v459[v592];
    int * v461 = v423->cache_age;
    int v462 = v461[v575];
    int * v463 = v423->cache_tags;
    int v464 = v463[v575];
    bool v596 = !(((~(((v440 ^ ((int)((unsigned int)((int)((unsigned int)v434 >> 2)) >> 1))) | (-(v440 ^ ((int)((unsigned int)((int)((unsigned int)v434 >> 2)) >> 1))))) >> 31)) | (~(((v442 ^ ((int)((unsigned int)((int)((unsigned int)v434 >> 2)) >> 1))) | (-(v442 ^ ((int)((unsigned int)((int)((unsigned int)v434 >> 2)) >> 1))))) >> 31))) == 0);
    int v528;
    if (v596) {
      int * v465 = v423->cache_age;
      int v598 = (4 + ((((int)((unsigned int)((int)((unsigned int)v434 >> 2)) >> 1)) & 3) * 2)) + ((~(((v442 ^ ((int)((unsigned int)((int)((unsigned int)v434 >> 2)) >> 1))) | (-(v442 ^ ((int)((unsigned int)((int)((unsigned int)v434 >> 2)) >> 1))))) >> 31)) & 1);
      int v466 = v465[v598];
      int * v467 = v423->cache_age;
      int v468 = v467[v577];
      int * v469 = v423->cache_age;
      int v601 = v468 + ((int)((unsigned int)(v468 - v466) >> 31));
      v469[v577] = v601;
      int * v471 = v423->cache_age;
      int v472 = v471[v579];
      int * v473 = v423->cache_age;
      int v604 = v472 + ((int)((unsigned int)(v472 - v466) >> 31));
      v473[v579] = v604;
      int * v475 = v423->cache_age;
      v475[v598] = 0;
      v528 = v598;
    } else {
      int * v478 = v423->cache_age;
      int v608 = 4 + ((((int)((unsigned int)((int)((unsigned int)v434 >> 2)) >> 1)) & 3) * 2);
      int v479 = v478[v608];
      int * v480 = v423->cache_tags;
      int v481 = v480[v608];
      int * v482 = v423->cache_age;
      int v483 = v482[v579];
      int * v484 = v423->cache_tags;
      int v485 = v484[v579];
      int * v486 = v423->cache_dirty;
      int v613 = (4 + ((((int)((unsigned int)((int)((unsigned int)v434 >> 2)) >> 1)) & 3) * 2)) + ((((v479 + ((~(((v481 ^ -1) | (-(v481 ^ -1))) >> 31)) & 2)) - (v483 + ((~(((v485 ^ -1) | (-(v485 ^ -1))) >> 31)) & 2))) >> 31) & 1);
      int v487 = v486[v613];
      bool v614 = !(v487 == 0);
      if (v614) {
        int * v488 = v423->cache_tags;
        int v489 = v488[v613];
        int * v490 = v423->cache_vals;
        int v617 = ((4 + ((((int)((unsigned int)((int)((unsigned int)v434 >> 2)) >> 1)) & 3) * 2)) + ((((v479 + ((~(((v481 ^ -1) | (-(v481 ^ -1))) >> 31)) & 2)) - (v483 + ((~(((v485 ^ -1) | (-(v485 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
        int v491 = v490[v617];
        int * v492 = v423->cache_vals;
        int v619 = (((4 + ((((int)((unsigned int)((int)((unsigned int)v434 >> 2)) >> 1)) & 3) * 2)) + ((((v479 + ((~(((v481 ^ -1) | (-(v481 ^ -1))) >> 31)) & 2)) - (v483 + ((~(((v485 ^ -1) | (-(v485 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
        int v493 = v492[v619];
        int * v494 = v423->mem;
        int v621 = v489 * 2;
        v494[v621] = v491;
        int * v496 = v423->mem;
        int v624 = (v489 * 2) + 1;
        v496[v624] = v493;
        ;
      } else {
        ;
      }
      int * v501 = v423->mem;
      int v629 = ((int)((unsigned int)((int)((unsigned int)v434 >> 2)) >> 1)) * 2;
      int v502 = v501[v629];
      int * v503 = v423->mem;
      int v631 = (((int)((unsigned int)((int)((unsigned int)v434 >> 2)) >> 1)) * 2) + 1;
      int v504 = v503[v631];
      int * v505 = v423->cache_vals;
      int v633 = ((4 + ((((int)((unsigned int)((int)((unsigned int)v434 >> 2)) >> 1)) & 3) * 2)) + ((((v479 + ((~(((v481 ^ -1) | (-(v481 ^ -1))) >> 31)) & 2)) - (v483 + ((~(((v485 ^ -1) | (-(v485 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
      v505[v633] = v502;
      int * v507 = v423->cache_vals;
      int v636 = (((4 + ((((int)((unsigned int)((int)((unsigned int)v434 >> 2)) >> 1)) & 3) * 2)) + ((((v479 + ((~(((v481 ^ -1) | (-(v481 ^ -1))) >> 31)) & 2)) - (v483 + ((~(((v485 ^ -1) | (-(v485 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
      v507[v636] = v504;
      int * v509 = v423->cache_tags;
      int v639 = (int)((unsigned int)((int)((unsigned int)v434 >> 2)) >> 1);
      v509[v613] = v639;
      int * v511 = v423->cache_dirty;
      v511[v613] = 0;
      int * v513 = v423->cache_age;
      v513[v613] = 1;
      int * v515 = v423->cache_age;
      int v516 = v515[v613];
      int * v517 = v423->cache_age;
      int v518 = v517[v577];
      int * v519 = v423->cache_age;
      int v647 = v518 + ((int)((unsigned int)(v518 - v516) >> 31));
      v519[v577] = v647;
      int * v521 = v423->cache_age;
      int v522 = v521[v579];
      int * v523 = v423->cache_age;
      int v650 = v522 + ((int)((unsigned int)(v522 - v516) >> 31));
      v523[v579] = v650;
      int * v525 = v423->cache_age;
      v525[v613] = 0;
      v528 = v613;
    }
    int * v529 = v423->cache_vals;
    int v653 = v528 * 2;
    int v530 = v529[v653];
    int * v531 = v423->cache_vals;
    int v655 = (v528 * 2) + 1;
    int v532 = v531[v655];
    int * v533 = v423->cache_vals;
    int v657 = (((((int)((unsigned int)((int)((unsigned int)v434 >> 2)) >> 1)) & 1) * 2) + ((((v458 + ((~(((v460 ^ -1) | (-(v460 ^ -1))) >> 31)) & 2)) - (v462 + ((~(((v464 ^ -1) | (-(v464 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
    v533[v657] = v530;
    int * v535 = v423->cache_vals;
    int v660 = ((((((int)((unsigned int)((int)((unsigned int)v434 >> 2)) >> 1)) & 1) * 2) + ((((v458 + ((~(((v460 ^ -1) | (-(v460 ^ -1))) >> 31)) & 2)) - (v462 + ((~(((v464 ^ -1) | (-(v464 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
    v535[v660] = v532;
    int * v537 = v423->cache_tags;
    int v663 = ((((int)((unsigned int)((int)((unsigned int)v434 >> 2)) >> 1)) & 1) * 2) + ((((v458 + ((~(((v460 ^ -1) | (-(v460 ^ -1))) >> 31)) & 2)) - (v462 + ((~(((v464 ^ -1) | (-(v464 ^ -1))) >> 31)) & 2))) >> 31) & 1);
    int v664 = (int)((unsigned int)((int)((unsigned int)v434 >> 2)) >> 1);
    v537[v663] = v664;
    int * v539 = v423->cache_dirty;
    v539[v663] = 0;
    int * v541 = v423->cache_age;
    v541[v663] = 1;
    int * v543 = v423->cache_age;
    int v544 = v543[v663];
    int * v545 = v423->cache_age;
    int v546 = v545[v573];
    int * v547 = v423->cache_age;
    int v672 = v546 + ((int)((unsigned int)(v546 - v544) >> 31));
    v547[v573] = v672;
    int * v549 = v423->cache_age;
    int v550 = v549[v575];
    int * v551 = v423->cache_age;
    int v675 = v550 + ((int)((unsigned int)(v550 - v544) >> 31));
    v551[v575] = v675;
    int * v553 = v423->cache_age;
    v553[v663] = 0;
    v556 = v663;
  }
  int v678 = (v556 * 2) + (((int)((unsigned int)v434 >> 2)) & 1);
  int v557 = v443[v678];
  int * v558 = v423->reg_ready;
  int v680 = ((v432 + ((v428 - v432) & (~((v428 - v432) >> 31)))) + 1) + ((100 ^ (((~(((v440 ^ ((int)((unsigned int)((int)((unsigned int)v434 >> 2)) >> 1))) | (-(v440 ^ ((int)((unsigned int)((int)((unsigned int)v434 >> 2)) >> 1))))) >> 31)) | (~(((v442 ^ ((int)((unsigned int)((int)((unsigned int)v434 >> 2)) >> 1))) | (-(v442 ^ ((int)((unsigned int)((int)((unsigned int)v434 >> 2)) >> 1))))) >> 31))) & 104)) ^ (((~(((v436 ^ ((int)((unsigned int)((int)((unsigned int)v434 >> 2)) >> 1))) | (-(v436 ^ ((int)((unsigned int)((int)((unsigned int)v434 >> 2)) >> 1))))) >> 31)) | (~(((v438 ^ ((int)((unsigned int)((int)((unsigned int)v434 >> 2)) >> 1))) | (-(v438 ^ ((int)((unsigned int)((int)((unsigned int)v434 >> 2)) >> 1))))) >> 31))) & (1 ^ (100 ^ (((~(((v440 ^ ((int)((unsigned int)((int)((unsigned int)v434 >> 2)) >> 1))) | (-(v440 ^ ((int)((unsigned int)((int)((unsigned int)v434 >> 2)) >> 1))))) >> 31)) | (~(((v442 ^ ((int)((unsigned int)((int)((unsigned int)v434 >> 2)) >> 1))) | (-(v442 ^ ((int)((unsigned int)((int)((unsigned int)v434 >> 2)) >> 1))))) >> 31))) & 104)))));
  v558[11] = v680;
  int * v560 = v423->regs;
  v560[11] = v557;
  struct StateT * v562 = slot_9(v423);
  return v562;
}

struct StateT * slot_4(struct StateT * v74) {
  int v75 = v74->timer;
  int v76 = v74->timer;
  int v80 = v76 + 1;
  v74->timer = v80;
  struct StateT * v78 = slot_5(v74);
  return v78;
}

struct StateT * slot_15(struct StateT * v1203) {
  int v1204 = v1203->timer;
  int v1205 = v1203->timer;
  int v1213 = v1205 + 1;
  v1203->timer = v1213;
  int * v1207 = v1203->reg_ready;
  int v1216 = v1204 + 1;
  v1207[10] = v1216;
  int * v1209 = v1203->regs;
  v1209[10] = 0;
  struct StateT * v1211 = slot_17(v1203);
  return v1211;
}

struct StateT * slot_18(struct StateT * v1236) {
  int v1237 = v1236->timer;
  int v1238 = v1236->timer;
  int v1242 = v1238 + 1;
  v1236->timer = v1242;
  struct StateT * v1240 = slot_20(v1236);
  return v1240;
}

struct StateT * slot_9(struct StateT * v685) {
  int * v686 = v685->regs;
  int v687 = v686[14];
  int * v688 = v685->regs;
  int v689 = v688[15];
  bool v814 = v687 >= v689;
  struct StateT * v808;
  if (v814) {
    int v690 = v685->timer;
    int v815 = v690 + 15;
    v685->timer = v815;
    int * v692 = v685->saved_regs;
    int v693 = v692[5];
    int * v694 = v685->regs;
    v694[5] = v693;
    int * v696 = v685->saved_regs;
    int v697 = v696[10];
    int * v698 = v685->regs;
    v698[10] = v697;
    int * v700 = v685->saved_regs;
    int v701 = v700[6];
    int * v702 = v685->regs;
    v702[6] = v701;
    int * v704 = v685->saved_regs;
    int v705 = v704[11];
    int * v706 = v685->regs;
    v706[11] = v705;
    int * v708 = v685->reg_ready;
    int v709 = v685->timer;
    v708[0] = v709;
    int * v711 = v685->reg_ready;
    int v712 = v685->timer;
    v711[1] = v712;
    int * v714 = v685->reg_ready;
    int v715 = v685->timer;
    v714[2] = v715;
    int * v717 = v685->reg_ready;
    int v718 = v685->timer;
    v717[3] = v718;
    int * v720 = v685->reg_ready;
    int v721 = v685->timer;
    v720[4] = v721;
    int * v723 = v685->reg_ready;
    int v724 = v685->timer;
    v723[5] = v724;
    int * v726 = v685->reg_ready;
    int v727 = v685->timer;
    v726[6] = v727;
    int * v729 = v685->reg_ready;
    int v730 = v685->timer;
    v729[7] = v730;
    int * v732 = v685->reg_ready;
    int v733 = v685->timer;
    v732[8] = v733;
    int * v735 = v685->reg_ready;
    int v736 = v685->timer;
    v735[9] = v736;
    int * v738 = v685->reg_ready;
    int v739 = v685->timer;
    v738[10] = v739;
    int * v741 = v685->reg_ready;
    int v742 = v685->timer;
    v741[11] = v742;
    int * v744 = v685->reg_ready;
    int v745 = v685->timer;
    v744[12] = v745;
    int * v747 = v685->reg_ready;
    int v748 = v685->timer;
    v747[13] = v748;
    int * v750 = v685->reg_ready;
    int v751 = v685->timer;
    v750[14] = v751;
    int * v753 = v685->reg_ready;
    int v754 = v685->timer;
    v753[15] = v754;
    int * v756 = v685->reg_ready;
    int v757 = v685->timer;
    v756[16] = v757;
    int * v759 = v685->reg_ready;
    int v760 = v685->timer;
    v759[17] = v760;
    int * v762 = v685->reg_ready;
    int v763 = v685->timer;
    v762[18] = v763;
    int * v765 = v685->reg_ready;
    int v766 = v685->timer;
    v765[19] = v766;
    int * v768 = v685->reg_ready;
    int v769 = v685->timer;
    v768[20] = v769;
    int * v771 = v685->reg_ready;
    int v772 = v685->timer;
    v771[21] = v772;
    int * v774 = v685->reg_ready;
    int v775 = v685->timer;
    v774[22] = v775;
    int * v777 = v685->reg_ready;
    int v778 = v685->timer;
    v777[23] = v778;
    int * v780 = v685->reg_ready;
    int v781 = v685->timer;
    v780[24] = v781;
    int * v783 = v685->reg_ready;
    int v784 = v685->timer;
    v783[25] = v784;
    int * v786 = v685->reg_ready;
    int v787 = v685->timer;
    v786[26] = v787;
    int * v789 = v685->reg_ready;
    int v790 = v685->timer;
    v789[27] = v790;
    int * v792 = v685->reg_ready;
    int v793 = v685->timer;
    v792[28] = v793;
    int * v795 = v685->reg_ready;
    int v796 = v685->timer;
    v795[29] = v796;
    int * v798 = v685->reg_ready;
    int v799 = v685->timer;
    v798[30] = v799;
    int * v801 = v685->reg_ready;
    int v802 = v685->timer;
    v801[31] = v802;
    struct StateT * v804 = slot_10(v685);
    v808 = v804;
  } else {
    struct StateT * v806 = slot_11(v685);
    v808 = v806;
  }
  return v808;
}

struct StateT * slot_22(struct StateT * v1546) {
  int * v1547 = v1546->saved_regs;
  int * v1548 = v1546->regs;
  int v1549 = v1548[6];
  v1547[6] = v1549;
  int v1551 = v1546->timer;
  int v1552 = v1546->timer;
  int v1572 = v1552 + 1;
  v1546->timer = v1572;
  int * v1554 = v1546->reg_ready;
  int v1555 = v1554[13];
  int * v1556 = v1546->regs;
  int v1557 = v1556[13];
  int * v1558 = v1546->reg_ready;
  int v1559 = v1558[14];
  int * v1560 = v1546->regs;
  int v1561 = v1560[14];
  int * v1562 = v1546->reg_ready;
  int v1580 = (v1559 + (((v1555 + ((v1551 - v1555) & (~((v1551 - v1555) >> 31)))) - v1559) & (~(((v1555 + ((v1551 - v1555) & (~((v1551 - v1555) >> 31)))) - v1559) >> 31)))) + 1;
  v1562[6] = v1580;
  int * v1564 = v1546->regs;
  int v1582 = v1557 + v1561;
  v1564[6] = v1582;
  struct StateT * v1566 = slot_23(v1546);
  return v1566;
}

struct StateT * slot_11(struct StateT * v942) {
  int v943 = v942->timer;
  int v944 = v942->timer;
  int v948 = v944 + 1;
  v942->timer = v948;
  struct StateT * v946 = slot_13(v942);
  return v946;
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