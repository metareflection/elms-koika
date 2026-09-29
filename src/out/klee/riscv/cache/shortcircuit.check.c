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

struct StateT * slot_12(struct StateT * v654);
struct StateT * slot_14(struct StateT * v78);
struct StateT * slot_6(struct StateT * v109);
struct StateT * slot_5(struct StateT * v88);
struct StateT * slot_2(struct StateT * v28);
struct StateT * slot_7(struct StateT * v359);
struct StateT * slot_3(struct StateT * v41);
struct StateT * snippet(struct StateT * v0);
struct StateT * slot_10(struct StateT * v667);
struct StateT * slot_1(struct StateT * v15);
struct StateT * slot_8(struct StateT * v380);
struct StateT * slot_4(struct StateT * v54);
struct StateT * slot_13(struct StateT * v683);
struct StateT * slot_9(struct StateT * v630);
struct StateT * slot_11(struct StateT * v688);
struct StateT * slot_0(struct StateT * v2);
struct StateT * slot_12(struct StateT * v654) {
  int v655 = v654->timer;
  int v661 = v655 + 1;
  v654->timer = v661;
  int * v657 = v654->regs;
  v657[10] = 0;
  struct StateT * v659 = slot_13(v654);
  return v659;
}

struct StateT * slot_14(struct StateT * v78) {
  int v79 = v78->timer;
  int v84 = v79 + 1;
  v78->timer = v84;
  int * v81 = v78->regs;
  v81[10] = 1;
  return v78;
}

struct StateT * slot_6(struct StateT * v109) {
  int v110 = v109->timer;
  int v243 = v110 + 1;
  v109->timer = v243;
  int * v112 = v109->regs;
  int v113 = v112[5];
  int * v114 = v109->cache_tags;
  int v247 = (((int)((unsigned int)((int)((unsigned int)v113 >> 2)) >> 1)) & 1) * 2;
  int v115 = v114[v247];
  int * v116 = v109->cache_tags;
  int v249 = ((((int)((unsigned int)((int)((unsigned int)v113 >> 2)) >> 1)) & 1) * 2) + 1;
  int v117 = v116[v249];
  int * v118 = v109->cache_tags;
  int v251 = 4 + ((((int)((unsigned int)((int)((unsigned int)v113 >> 2)) >> 1)) & 3) * 2);
  int v119 = v118[v251];
  int * v120 = v109->cache_tags;
  int v253 = (4 + ((((int)((unsigned int)((int)((unsigned int)v113 >> 2)) >> 1)) & 3) * 2)) + 1;
  int v121 = v120[v253];
  int v122 = v109->timer;
  int v254 = v122 + ((100 ^ (((~(((v119 ^ ((int)((unsigned int)((int)((unsigned int)v113 >> 2)) >> 1))) | (-(v119 ^ ((int)((unsigned int)((int)((unsigned int)v113 >> 2)) >> 1))))) >> 31)) | (~(((v121 ^ ((int)((unsigned int)((int)((unsigned int)v113 >> 2)) >> 1))) | (-(v121 ^ ((int)((unsigned int)((int)((unsigned int)v113 >> 2)) >> 1))))) >> 31))) & 104)) ^ (((~(((v115 ^ ((int)((unsigned int)((int)((unsigned int)v113 >> 2)) >> 1))) | (-(v115 ^ ((int)((unsigned int)((int)((unsigned int)v113 >> 2)) >> 1))))) >> 31)) | (~(((v117 ^ ((int)((unsigned int)((int)((unsigned int)v113 >> 2)) >> 1))) | (-(v117 ^ ((int)((unsigned int)((int)((unsigned int)v113 >> 2)) >> 1))))) >> 31))) & (1 ^ (100 ^ (((~(((v119 ^ ((int)((unsigned int)((int)((unsigned int)v113 >> 2)) >> 1))) | (-(v119 ^ ((int)((unsigned int)((int)((unsigned int)v113 >> 2)) >> 1))))) >> 31)) | (~(((v121 ^ ((int)((unsigned int)((int)((unsigned int)v113 >> 2)) >> 1))) | (-(v121 ^ ((int)((unsigned int)((int)((unsigned int)v113 >> 2)) >> 1))))) >> 31))) & 104)))));
  v109->timer = v254;
  int * v124 = v109->cache_vals;
  bool v255 = !(((~(((v115 ^ ((int)((unsigned int)((int)((unsigned int)v113 >> 2)) >> 1))) | (-(v115 ^ ((int)((unsigned int)((int)((unsigned int)v113 >> 2)) >> 1))))) >> 31)) | (~(((v117 ^ ((int)((unsigned int)((int)((unsigned int)v113 >> 2)) >> 1))) | (-(v117 ^ ((int)((unsigned int)((int)((unsigned int)v113 >> 2)) >> 1))))) >> 31))) == 0);
  int v237;
  if (v255) {
    int * v125 = v109->cache_age;
    int v257 = ((((int)((unsigned int)((int)((unsigned int)v113 >> 2)) >> 1)) & 1) * 2) + ((~(((v117 ^ ((int)((unsigned int)((int)((unsigned int)v113 >> 2)) >> 1))) | (-(v117 ^ ((int)((unsigned int)((int)((unsigned int)v113 >> 2)) >> 1))))) >> 31)) & 1);
    int v126 = v125[v257];
    int * v127 = v109->cache_age;
    int v128 = v127[v247];
    int * v129 = v109->cache_age;
    int v260 = v128 + ((int)((unsigned int)(v128 - v126) >> 31));
    v129[v247] = v260;
    int * v131 = v109->cache_age;
    int v132 = v131[v249];
    int * v133 = v109->cache_age;
    int v263 = v132 + ((int)((unsigned int)(v132 - v126) >> 31));
    v133[v249] = v263;
    int * v135 = v109->cache_age;
    v135[v257] = 0;
    v237 = v257;
  } else {
    int * v138 = v109->cache_age;
    int v267 = (((int)((unsigned int)((int)((unsigned int)v113 >> 2)) >> 1)) & 1) * 2;
    int v139 = v138[v267];
    int * v140 = v109->cache_tags;
    int v141 = v140[v267];
    int * v142 = v109->cache_age;
    int v143 = v142[v249];
    int * v144 = v109->cache_tags;
    int v145 = v144[v249];
    bool v271 = !(((~(((v119 ^ ((int)((unsigned int)((int)((unsigned int)v113 >> 2)) >> 1))) | (-(v119 ^ ((int)((unsigned int)((int)((unsigned int)v113 >> 2)) >> 1))))) >> 31)) | (~(((v121 ^ ((int)((unsigned int)((int)((unsigned int)v113 >> 2)) >> 1))) | (-(v121 ^ ((int)((unsigned int)((int)((unsigned int)v113 >> 2)) >> 1))))) >> 31))) == 0);
    int v209;
    if (v271) {
      int * v146 = v109->cache_age;
      int v273 = (4 + ((((int)((unsigned int)((int)((unsigned int)v113 >> 2)) >> 1)) & 3) * 2)) + ((~(((v121 ^ ((int)((unsigned int)((int)((unsigned int)v113 >> 2)) >> 1))) | (-(v121 ^ ((int)((unsigned int)((int)((unsigned int)v113 >> 2)) >> 1))))) >> 31)) & 1);
      int v147 = v146[v273];
      int * v148 = v109->cache_age;
      int v149 = v148[v251];
      int * v150 = v109->cache_age;
      int v276 = v149 + ((int)((unsigned int)(v149 - v147) >> 31));
      v150[v251] = v276;
      int * v152 = v109->cache_age;
      int v153 = v152[v253];
      int * v154 = v109->cache_age;
      int v279 = v153 + ((int)((unsigned int)(v153 - v147) >> 31));
      v154[v253] = v279;
      int * v156 = v109->cache_age;
      v156[v273] = 0;
      v209 = v273;
    } else {
      int * v159 = v109->cache_age;
      int v283 = 4 + ((((int)((unsigned int)((int)((unsigned int)v113 >> 2)) >> 1)) & 3) * 2);
      int v160 = v159[v283];
      int * v161 = v109->cache_tags;
      int v162 = v161[v283];
      int * v163 = v109->cache_age;
      int v164 = v163[v253];
      int * v165 = v109->cache_tags;
      int v166 = v165[v253];
      int * v167 = v109->cache_dirty;
      int v288 = (4 + ((((int)((unsigned int)((int)((unsigned int)v113 >> 2)) >> 1)) & 3) * 2)) + ((((v160 + ((~(((v162 ^ -1) | (-(v162 ^ -1))) >> 31)) & 2)) - (v164 + ((~(((v166 ^ -1) | (-(v166 ^ -1))) >> 31)) & 2))) >> 31) & 1);
      int v168 = v167[v288];
      bool v289 = !(v168 == 0);
      if (v289) {
        int * v169 = v109->cache_tags;
        int v170 = v169[v288];
        int * v171 = v109->cache_vals;
        int v292 = ((4 + ((((int)((unsigned int)((int)((unsigned int)v113 >> 2)) >> 1)) & 3) * 2)) + ((((v160 + ((~(((v162 ^ -1) | (-(v162 ^ -1))) >> 31)) & 2)) - (v164 + ((~(((v166 ^ -1) | (-(v166 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
        int v172 = v171[v292];
        int * v173 = v109->cache_vals;
        int v294 = (((4 + ((((int)((unsigned int)((int)((unsigned int)v113 >> 2)) >> 1)) & 3) * 2)) + ((((v160 + ((~(((v162 ^ -1) | (-(v162 ^ -1))) >> 31)) & 2)) - (v164 + ((~(((v166 ^ -1) | (-(v166 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
        int v174 = v173[v294];
        int * v175 = v109->mem;
        int v296 = v170 * 2;
        v175[v296] = v172;
        int * v177 = v109->mem;
        int v299 = (v170 * 2) + 1;
        v177[v299] = v174;
        ;
      } else {
        ;
      }
      int * v182 = v109->mem;
      int v304 = ((int)((unsigned int)((int)((unsigned int)v113 >> 2)) >> 1)) * 2;
      int v183 = v182[v304];
      int * v184 = v109->mem;
      int v306 = (((int)((unsigned int)((int)((unsigned int)v113 >> 2)) >> 1)) * 2) + 1;
      int v185 = v184[v306];
      int * v186 = v109->cache_vals;
      int v308 = ((4 + ((((int)((unsigned int)((int)((unsigned int)v113 >> 2)) >> 1)) & 3) * 2)) + ((((v160 + ((~(((v162 ^ -1) | (-(v162 ^ -1))) >> 31)) & 2)) - (v164 + ((~(((v166 ^ -1) | (-(v166 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
      v186[v308] = v183;
      int * v188 = v109->cache_vals;
      int v311 = (((4 + ((((int)((unsigned int)((int)((unsigned int)v113 >> 2)) >> 1)) & 3) * 2)) + ((((v160 + ((~(((v162 ^ -1) | (-(v162 ^ -1))) >> 31)) & 2)) - (v164 + ((~(((v166 ^ -1) | (-(v166 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
      v188[v311] = v185;
      int * v190 = v109->cache_tags;
      int v314 = (int)((unsigned int)((int)((unsigned int)v113 >> 2)) >> 1);
      v190[v288] = v314;
      int * v192 = v109->cache_dirty;
      v192[v288] = 0;
      int * v194 = v109->cache_age;
      v194[v288] = 1;
      int * v196 = v109->cache_age;
      int v197 = v196[v288];
      int * v198 = v109->cache_age;
      int v199 = v198[v251];
      int * v200 = v109->cache_age;
      int v322 = v199 + ((int)((unsigned int)(v199 - v197) >> 31));
      v200[v251] = v322;
      int * v202 = v109->cache_age;
      int v203 = v202[v253];
      int * v204 = v109->cache_age;
      int v325 = v203 + ((int)((unsigned int)(v203 - v197) >> 31));
      v204[v253] = v325;
      int * v206 = v109->cache_age;
      v206[v288] = 0;
      v209 = v288;
    }
    int * v210 = v109->cache_vals;
    int v328 = v209 * 2;
    int v211 = v210[v328];
    int * v212 = v109->cache_vals;
    int v330 = (v209 * 2) + 1;
    int v213 = v212[v330];
    int * v214 = v109->cache_vals;
    int v332 = (((((int)((unsigned int)((int)((unsigned int)v113 >> 2)) >> 1)) & 1) * 2) + ((((v139 + ((~(((v141 ^ -1) | (-(v141 ^ -1))) >> 31)) & 2)) - (v143 + ((~(((v145 ^ -1) | (-(v145 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
    v214[v332] = v211;
    int * v216 = v109->cache_vals;
    int v335 = ((((((int)((unsigned int)((int)((unsigned int)v113 >> 2)) >> 1)) & 1) * 2) + ((((v139 + ((~(((v141 ^ -1) | (-(v141 ^ -1))) >> 31)) & 2)) - (v143 + ((~(((v145 ^ -1) | (-(v145 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
    v216[v335] = v213;
    int * v218 = v109->cache_tags;
    int v338 = ((((int)((unsigned int)((int)((unsigned int)v113 >> 2)) >> 1)) & 1) * 2) + ((((v139 + ((~(((v141 ^ -1) | (-(v141 ^ -1))) >> 31)) & 2)) - (v143 + ((~(((v145 ^ -1) | (-(v145 ^ -1))) >> 31)) & 2))) >> 31) & 1);
    int v339 = (int)((unsigned int)((int)((unsigned int)v113 >> 2)) >> 1);
    v218[v338] = v339;
    int * v220 = v109->cache_dirty;
    v220[v338] = 0;
    int * v222 = v109->cache_age;
    v222[v338] = 1;
    int * v224 = v109->cache_age;
    int v225 = v224[v338];
    int * v226 = v109->cache_age;
    int v227 = v226[v247];
    int * v228 = v109->cache_age;
    int v347 = v227 + ((int)((unsigned int)(v227 - v225) >> 31));
    v228[v247] = v347;
    int * v230 = v109->cache_age;
    int v231 = v230[v249];
    int * v232 = v109->cache_age;
    int v350 = v231 + ((int)((unsigned int)(v231 - v225) >> 31));
    v232[v249] = v350;
    int * v234 = v109->cache_age;
    v234[v338] = 0;
    v237 = v338;
  }
  int v353 = (v237 * 2) + (((int)((unsigned int)v113 >> 2)) & 1);
  int v238 = v124[v353];
  int * v239 = v109->regs;
  v239[10] = v238;
  struct StateT * v241 = slot_7(v109);
  return v241;
}

struct StateT * slot_5(struct StateT * v88) {
  int v89 = v88->timer;
  int v99 = v89 + 1;
  v88->timer = v99;
  int * v91 = v88->regs;
  int v92 = v91[12];
  int * v93 = v88->regs;
  int v94 = v93[14];
  int * v95 = v88->regs;
  int v106 = v92 + v94;
  v95[5] = v106;
  struct StateT * v97 = slot_6(v88);
  return v97;
}

struct StateT * slot_2(struct StateT * v28) {
  int v29 = v28->timer;
  int v35 = v29 + 1;
  v28->timer = v35;
  int * v31 = v28->regs;
  v31[14] = 0;
  struct StateT * v33 = slot_3(v28);
  return v33;
}

struct StateT * slot_7(struct StateT * v359) {
  int v360 = v359->timer;
  int v370 = v360 + 1;
  v359->timer = v370;
  int * v362 = v359->regs;
  int v363 = v362[13];
  int * v364 = v359->regs;
  int v365 = v364[14];
  int * v366 = v359->regs;
  int v377 = v363 + v365;
  v366[6] = v377;
  struct StateT * v368 = slot_8(v359);
  return v368;
}

struct StateT * slot_3(struct StateT * v41) {
  int v42 = v41->timer;
  int v48 = v42 + 1;
  v41->timer = v48;
  int * v44 = v41->regs;
  v44[15] = 16;
  struct StateT * v46 = slot_4(v41);
  return v46;
}

struct StateT * snippet(struct StateT * v0) {
  struct StateT * v1 = slot_0(v0);
  return v1;
}

struct StateT * slot_10(struct StateT * v667) {
  int v668 = v667->timer;
  int v676 = v668 + 1;
  v667->timer = v676;
  int * v670 = v667->regs;
  int v671 = v670[14];
  int * v672 = v667->regs;
  int v680 = v671 + 4;
  v672[14] = v680;
  struct StateT * v674 = slot_11(v667);
  return v674;
}

struct StateT * slot_1(struct StateT * v15) {
  int v16 = v15->timer;
  int v22 = v16 + 1;
  v15->timer = v22;
  int * v18 = v15->regs;
  v18[13] = 80;
  struct StateT * v20 = slot_2(v15);
  return v20;
}

struct StateT * slot_8(struct StateT * v380) {
  int v381 = v380->timer;
  int v514 = v381 + 1;
  v380->timer = v514;
  int * v383 = v380->regs;
  int v384 = v383[6];
  int * v385 = v380->cache_tags;
  int v518 = (((int)((unsigned int)((int)((unsigned int)v384 >> 2)) >> 1)) & 1) * 2;
  int v386 = v385[v518];
  int * v387 = v380->cache_tags;
  int v520 = ((((int)((unsigned int)((int)((unsigned int)v384 >> 2)) >> 1)) & 1) * 2) + 1;
  int v388 = v387[v520];
  int * v389 = v380->cache_tags;
  int v522 = 4 + ((((int)((unsigned int)((int)((unsigned int)v384 >> 2)) >> 1)) & 3) * 2);
  int v390 = v389[v522];
  int * v391 = v380->cache_tags;
  int v524 = (4 + ((((int)((unsigned int)((int)((unsigned int)v384 >> 2)) >> 1)) & 3) * 2)) + 1;
  int v392 = v391[v524];
  int v393 = v380->timer;
  int v525 = v393 + ((100 ^ (((~(((v390 ^ ((int)((unsigned int)((int)((unsigned int)v384 >> 2)) >> 1))) | (-(v390 ^ ((int)((unsigned int)((int)((unsigned int)v384 >> 2)) >> 1))))) >> 31)) | (~(((v392 ^ ((int)((unsigned int)((int)((unsigned int)v384 >> 2)) >> 1))) | (-(v392 ^ ((int)((unsigned int)((int)((unsigned int)v384 >> 2)) >> 1))))) >> 31))) & 104)) ^ (((~(((v386 ^ ((int)((unsigned int)((int)((unsigned int)v384 >> 2)) >> 1))) | (-(v386 ^ ((int)((unsigned int)((int)((unsigned int)v384 >> 2)) >> 1))))) >> 31)) | (~(((v388 ^ ((int)((unsigned int)((int)((unsigned int)v384 >> 2)) >> 1))) | (-(v388 ^ ((int)((unsigned int)((int)((unsigned int)v384 >> 2)) >> 1))))) >> 31))) & (1 ^ (100 ^ (((~(((v390 ^ ((int)((unsigned int)((int)((unsigned int)v384 >> 2)) >> 1))) | (-(v390 ^ ((int)((unsigned int)((int)((unsigned int)v384 >> 2)) >> 1))))) >> 31)) | (~(((v392 ^ ((int)((unsigned int)((int)((unsigned int)v384 >> 2)) >> 1))) | (-(v392 ^ ((int)((unsigned int)((int)((unsigned int)v384 >> 2)) >> 1))))) >> 31))) & 104)))));
  v380->timer = v525;
  int * v395 = v380->cache_vals;
  bool v526 = !(((~(((v386 ^ ((int)((unsigned int)((int)((unsigned int)v384 >> 2)) >> 1))) | (-(v386 ^ ((int)((unsigned int)((int)((unsigned int)v384 >> 2)) >> 1))))) >> 31)) | (~(((v388 ^ ((int)((unsigned int)((int)((unsigned int)v384 >> 2)) >> 1))) | (-(v388 ^ ((int)((unsigned int)((int)((unsigned int)v384 >> 2)) >> 1))))) >> 31))) == 0);
  int v508;
  if (v526) {
    int * v396 = v380->cache_age;
    int v528 = ((((int)((unsigned int)((int)((unsigned int)v384 >> 2)) >> 1)) & 1) * 2) + ((~(((v388 ^ ((int)((unsigned int)((int)((unsigned int)v384 >> 2)) >> 1))) | (-(v388 ^ ((int)((unsigned int)((int)((unsigned int)v384 >> 2)) >> 1))))) >> 31)) & 1);
    int v397 = v396[v528];
    int * v398 = v380->cache_age;
    int v399 = v398[v518];
    int * v400 = v380->cache_age;
    int v531 = v399 + ((int)((unsigned int)(v399 - v397) >> 31));
    v400[v518] = v531;
    int * v402 = v380->cache_age;
    int v403 = v402[v520];
    int * v404 = v380->cache_age;
    int v534 = v403 + ((int)((unsigned int)(v403 - v397) >> 31));
    v404[v520] = v534;
    int * v406 = v380->cache_age;
    v406[v528] = 0;
    v508 = v528;
  } else {
    int * v409 = v380->cache_age;
    int v538 = (((int)((unsigned int)((int)((unsigned int)v384 >> 2)) >> 1)) & 1) * 2;
    int v410 = v409[v538];
    int * v411 = v380->cache_tags;
    int v412 = v411[v538];
    int * v413 = v380->cache_age;
    int v414 = v413[v520];
    int * v415 = v380->cache_tags;
    int v416 = v415[v520];
    bool v542 = !(((~(((v390 ^ ((int)((unsigned int)((int)((unsigned int)v384 >> 2)) >> 1))) | (-(v390 ^ ((int)((unsigned int)((int)((unsigned int)v384 >> 2)) >> 1))))) >> 31)) | (~(((v392 ^ ((int)((unsigned int)((int)((unsigned int)v384 >> 2)) >> 1))) | (-(v392 ^ ((int)((unsigned int)((int)((unsigned int)v384 >> 2)) >> 1))))) >> 31))) == 0);
    int v480;
    if (v542) {
      int * v417 = v380->cache_age;
      int v544 = (4 + ((((int)((unsigned int)((int)((unsigned int)v384 >> 2)) >> 1)) & 3) * 2)) + ((~(((v392 ^ ((int)((unsigned int)((int)((unsigned int)v384 >> 2)) >> 1))) | (-(v392 ^ ((int)((unsigned int)((int)((unsigned int)v384 >> 2)) >> 1))))) >> 31)) & 1);
      int v418 = v417[v544];
      int * v419 = v380->cache_age;
      int v420 = v419[v522];
      int * v421 = v380->cache_age;
      int v547 = v420 + ((int)((unsigned int)(v420 - v418) >> 31));
      v421[v522] = v547;
      int * v423 = v380->cache_age;
      int v424 = v423[v524];
      int * v425 = v380->cache_age;
      int v550 = v424 + ((int)((unsigned int)(v424 - v418) >> 31));
      v425[v524] = v550;
      int * v427 = v380->cache_age;
      v427[v544] = 0;
      v480 = v544;
    } else {
      int * v430 = v380->cache_age;
      int v554 = 4 + ((((int)((unsigned int)((int)((unsigned int)v384 >> 2)) >> 1)) & 3) * 2);
      int v431 = v430[v554];
      int * v432 = v380->cache_tags;
      int v433 = v432[v554];
      int * v434 = v380->cache_age;
      int v435 = v434[v524];
      int * v436 = v380->cache_tags;
      int v437 = v436[v524];
      int * v438 = v380->cache_dirty;
      int v559 = (4 + ((((int)((unsigned int)((int)((unsigned int)v384 >> 2)) >> 1)) & 3) * 2)) + ((((v431 + ((~(((v433 ^ -1) | (-(v433 ^ -1))) >> 31)) & 2)) - (v435 + ((~(((v437 ^ -1) | (-(v437 ^ -1))) >> 31)) & 2))) >> 31) & 1);
      int v439 = v438[v559];
      bool v560 = !(v439 == 0);
      if (v560) {
        int * v440 = v380->cache_tags;
        int v441 = v440[v559];
        int * v442 = v380->cache_vals;
        int v563 = ((4 + ((((int)((unsigned int)((int)((unsigned int)v384 >> 2)) >> 1)) & 3) * 2)) + ((((v431 + ((~(((v433 ^ -1) | (-(v433 ^ -1))) >> 31)) & 2)) - (v435 + ((~(((v437 ^ -1) | (-(v437 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
        int v443 = v442[v563];
        int * v444 = v380->cache_vals;
        int v565 = (((4 + ((((int)((unsigned int)((int)((unsigned int)v384 >> 2)) >> 1)) & 3) * 2)) + ((((v431 + ((~(((v433 ^ -1) | (-(v433 ^ -1))) >> 31)) & 2)) - (v435 + ((~(((v437 ^ -1) | (-(v437 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
        int v445 = v444[v565];
        int * v446 = v380->mem;
        int v567 = v441 * 2;
        v446[v567] = v443;
        int * v448 = v380->mem;
        int v570 = (v441 * 2) + 1;
        v448[v570] = v445;
        ;
      } else {
        ;
      }
      int * v453 = v380->mem;
      int v575 = ((int)((unsigned int)((int)((unsigned int)v384 >> 2)) >> 1)) * 2;
      int v454 = v453[v575];
      int * v455 = v380->mem;
      int v577 = (((int)((unsigned int)((int)((unsigned int)v384 >> 2)) >> 1)) * 2) + 1;
      int v456 = v455[v577];
      int * v457 = v380->cache_vals;
      int v579 = ((4 + ((((int)((unsigned int)((int)((unsigned int)v384 >> 2)) >> 1)) & 3) * 2)) + ((((v431 + ((~(((v433 ^ -1) | (-(v433 ^ -1))) >> 31)) & 2)) - (v435 + ((~(((v437 ^ -1) | (-(v437 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
      v457[v579] = v454;
      int * v459 = v380->cache_vals;
      int v582 = (((4 + ((((int)((unsigned int)((int)((unsigned int)v384 >> 2)) >> 1)) & 3) * 2)) + ((((v431 + ((~(((v433 ^ -1) | (-(v433 ^ -1))) >> 31)) & 2)) - (v435 + ((~(((v437 ^ -1) | (-(v437 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
      v459[v582] = v456;
      int * v461 = v380->cache_tags;
      int v585 = (int)((unsigned int)((int)((unsigned int)v384 >> 2)) >> 1);
      v461[v559] = v585;
      int * v463 = v380->cache_dirty;
      v463[v559] = 0;
      int * v465 = v380->cache_age;
      v465[v559] = 1;
      int * v467 = v380->cache_age;
      int v468 = v467[v559];
      int * v469 = v380->cache_age;
      int v470 = v469[v522];
      int * v471 = v380->cache_age;
      int v593 = v470 + ((int)((unsigned int)(v470 - v468) >> 31));
      v471[v522] = v593;
      int * v473 = v380->cache_age;
      int v474 = v473[v524];
      int * v475 = v380->cache_age;
      int v596 = v474 + ((int)((unsigned int)(v474 - v468) >> 31));
      v475[v524] = v596;
      int * v477 = v380->cache_age;
      v477[v559] = 0;
      v480 = v559;
    }
    int * v481 = v380->cache_vals;
    int v599 = v480 * 2;
    int v482 = v481[v599];
    int * v483 = v380->cache_vals;
    int v601 = (v480 * 2) + 1;
    int v484 = v483[v601];
    int * v485 = v380->cache_vals;
    int v603 = (((((int)((unsigned int)((int)((unsigned int)v384 >> 2)) >> 1)) & 1) * 2) + ((((v410 + ((~(((v412 ^ -1) | (-(v412 ^ -1))) >> 31)) & 2)) - (v414 + ((~(((v416 ^ -1) | (-(v416 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
    v485[v603] = v482;
    int * v487 = v380->cache_vals;
    int v606 = ((((((int)((unsigned int)((int)((unsigned int)v384 >> 2)) >> 1)) & 1) * 2) + ((((v410 + ((~(((v412 ^ -1) | (-(v412 ^ -1))) >> 31)) & 2)) - (v414 + ((~(((v416 ^ -1) | (-(v416 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
    v487[v606] = v484;
    int * v489 = v380->cache_tags;
    int v609 = ((((int)((unsigned int)((int)((unsigned int)v384 >> 2)) >> 1)) & 1) * 2) + ((((v410 + ((~(((v412 ^ -1) | (-(v412 ^ -1))) >> 31)) & 2)) - (v414 + ((~(((v416 ^ -1) | (-(v416 ^ -1))) >> 31)) & 2))) >> 31) & 1);
    int v610 = (int)((unsigned int)((int)((unsigned int)v384 >> 2)) >> 1);
    v489[v609] = v610;
    int * v491 = v380->cache_dirty;
    v491[v609] = 0;
    int * v493 = v380->cache_age;
    v493[v609] = 1;
    int * v495 = v380->cache_age;
    int v496 = v495[v609];
    int * v497 = v380->cache_age;
    int v498 = v497[v518];
    int * v499 = v380->cache_age;
    int v618 = v498 + ((int)((unsigned int)(v498 - v496) >> 31));
    v499[v518] = v618;
    int * v501 = v380->cache_age;
    int v502 = v501[v520];
    int * v503 = v380->cache_age;
    int v621 = v502 + ((int)((unsigned int)(v502 - v496) >> 31));
    v503[v520] = v621;
    int * v505 = v380->cache_age;
    v505[v609] = 0;
    v508 = v609;
  }
  int v624 = (v508 * 2) + (((int)((unsigned int)v384 >> 2)) & 1);
  int v509 = v395[v624];
  int * v510 = v380->regs;
  v510[11] = v509;
  struct StateT * v512 = slot_9(v380);
  return v512;
}

struct StateT * slot_4(struct StateT * v54) {
  int v55 = v54->timer;
  int v67 = v55 + 1;
  v54->timer = v67;
  int * v57 = v54->regs;
  int v58 = v57[14];
  int * v59 = v54->regs;
  int v60 = v59[15];
  bool v72 = v58 >= v60;
  struct StateT * v65;
  if (v72) {
    struct StateT * v61 = slot_14(v54);
    v65 = v61;
  } else {
    struct StateT * v63 = slot_5(v54);
    v65 = v63;
  }
  return v65;
}

struct StateT * slot_13(struct StateT * v683) {
  int v684 = v683->timer;
  int v687 = v684 + 1;
  v683->timer = v687;
  return v683;
}

struct StateT * slot_9(struct StateT * v630) {
  int v631 = v630->timer;
  int v643 = v631 + 1;
  v630->timer = v643;
  int * v633 = v630->regs;
  int v634 = v633[10];
  int * v635 = v630->regs;
  int v636 = v635[11];
  bool v648 = !(v634 == v636);
  struct StateT * v641;
  if (v648) {
    struct StateT * v637 = slot_12(v630);
    v641 = v637;
  } else {
    struct StateT * v639 = slot_10(v630);
    v641 = v639;
  }
  return v641;
}

struct StateT * slot_11(struct StateT * v688) {
  int v689 = v688->timer;
  int v693 = v689 + 1;
  v688->timer = v693;
  struct StateT * v691 = slot_4(v688);
  return v691;
}

struct StateT * slot_0(struct StateT * v2) {
  int v3 = v2->timer;
  int v9 = v3 + 1;
  v2->timer = v9;
  int * v5 = v2->regs;
  v5[12] = 0;
  struct StateT * v7 = slot_1(v2);
  return v7;
}



/*****************************************
End of C Generated Code
*******************************************/

void init(struct StateT *s) {
  for (int i=0; i<NUM_REGS; i++) {
    s->regs[i] = 0;
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
  koika_assert(s1_->timer==s2_->timer, "timing leak");
  return 0;
}