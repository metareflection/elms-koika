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

struct StateT * slot_12(struct StateT * v760);
struct StateT * slot_14(struct StateT * v797);
struct StateT * slot_6(struct StateT * v307);
struct StateT * slot_16(struct StateT * v834);
struct StateT * slot_5(struct StateT * v100);
struct StateT * slot_17(struct StateT * v858);
struct StateT * slot_20(struct StateT * v1297);
struct StateT * slot_2(struct StateT * v39);
struct StateT * slot_7(struct StateT * v514);
struct StateT * slot_21(struct StateT * v1616);
struct StateT * slot_3(struct StateT * v60);
struct StateT * snippet(struct StateT * v0);
struct StateT * slot_10(struct StateT * v739);
struct StateT * slot_1(struct StateT * v23);
struct StateT * slot_8(struct StateT * v522);
struct StateT * slot_19(struct StateT * v1273);
struct StateT * slot_4(struct StateT * v84);
struct StateT * slot_13(struct StateT * v776);
struct StateT * slot_15(struct StateT * v813);
struct StateT * slot_18(struct StateT * v1065);
struct StateT * slot_0(struct StateT * v2);
struct StateT * slot_12(struct StateT * v760) {
  int v761 = v760->timer;
  int v769 = v761 + 1;
  v760->timer = v769;
  int * v763 = v760->reg_ready;
  v763[11] = v769;
  int * v765 = v760->regs;
  v765[11] = 0;
  struct StateT * v767 = slot_13(v760);
  return v767;
}

struct StateT * slot_14(struct StateT * v797) {
  int v798 = v797->timer;
  int v806 = v798 + 1;
  v797->timer = v806;
  int * v800 = v797->reg_ready;
  v800[12] = v806;
  int * v802 = v797->regs;
  v802[12] = 0;
  struct StateT * v804 = slot_15(v797);
  return v804;
}

struct StateT * slot_6(struct StateT * v307) {
  int v308 = v307->timer;
  int v420 = v308 + 1;
  v307->timer = v420;
  int * v310 = v307->reg_ready;
  int v311 = v310[11];
  int * v312 = v307->regs;
  int v313 = v312[11];
  int * v314 = v307->cache_tags;
  int v425 = (((int)((unsigned int)((int)((unsigned int)v313 >> 2)) >> 1)) & 1) * 2;
  int v315 = v314[v425];
  int v426 = ((((int)((unsigned int)((int)((unsigned int)v313 >> 2)) >> 1)) & 1) * 2) + 1;
  int v316 = v314[v426];
  int v427 = 4 + ((((int)((unsigned int)((int)((unsigned int)v313 >> 2)) >> 1)) & 3) * 2);
  int v317 = v314[v427];
  int v428 = (4 + ((((int)((unsigned int)((int)((unsigned int)v313 >> 2)) >> 1)) & 3) * 2)) + 1;
  int v318 = v314[v428];
  int * v319 = v307->cache_vals;
  bool v429 = !(((~(((v315 ^ ((int)((unsigned int)((int)((unsigned int)v313 >> 2)) >> 1))) | (-(v315 ^ ((int)((unsigned int)((int)((unsigned int)v313 >> 2)) >> 1))))) >> 31)) | (~(((v316 ^ ((int)((unsigned int)((int)((unsigned int)v313 >> 2)) >> 1))) | (-(v316 ^ ((int)((unsigned int)((int)((unsigned int)v313 >> 2)) >> 1))))) >> 31))) == 0);
  int v412;
  if (v429) {
    int * v320 = v307->cache_age;
    int v431 = ((((int)((unsigned int)((int)((unsigned int)v313 >> 2)) >> 1)) & 1) * 2) + ((~(((v316 ^ ((int)((unsigned int)((int)((unsigned int)v313 >> 2)) >> 1))) | (-(v316 ^ ((int)((unsigned int)((int)((unsigned int)v313 >> 2)) >> 1))))) >> 31)) & 1);
    int v321 = v320[v431];
    int v322 = v320[v425];
    int v432 = v322 + ((int)((unsigned int)(v322 - v321) >> 31));
    v320[v425] = v432;
    int * v324 = v307->cache_age;
    int v325 = v324[v426];
    int v434 = v325 + ((int)((unsigned int)(v325 - v321) >> 31));
    v324[v426] = v434;
    int * v327 = v307->cache_age;
    v327[v431] = 0;
    v412 = v431;
  } else {
    int * v330 = v307->cache_age;
    int v438 = (((int)((unsigned int)((int)((unsigned int)v313 >> 2)) >> 1)) & 1) * 2;
    int v331 = v330[v438];
    int * v332 = v307->cache_tags;
    int v333 = v332[v438];
    int v334 = v330[v426];
    int v335 = v332[v426];
    bool v440 = !(((~(((v317 ^ ((int)((unsigned int)((int)((unsigned int)v313 >> 2)) >> 1))) | (-(v317 ^ ((int)((unsigned int)((int)((unsigned int)v313 >> 2)) >> 1))))) >> 31)) | (~(((v318 ^ ((int)((unsigned int)((int)((unsigned int)v313 >> 2)) >> 1))) | (-(v318 ^ ((int)((unsigned int)((int)((unsigned int)v313 >> 2)) >> 1))))) >> 31))) == 0);
    int v389;
    if (v440) {
      int * v336 = v307->cache_age;
      int v442 = (4 + ((((int)((unsigned int)((int)((unsigned int)v313 >> 2)) >> 1)) & 3) * 2)) + ((~(((v318 ^ ((int)((unsigned int)((int)((unsigned int)v313 >> 2)) >> 1))) | (-(v318 ^ ((int)((unsigned int)((int)((unsigned int)v313 >> 2)) >> 1))))) >> 31)) & 1);
      int v337 = v336[v442];
      int v338 = v336[v427];
      int v443 = v338 + ((int)((unsigned int)(v338 - v337) >> 31));
      v336[v427] = v443;
      int * v340 = v307->cache_age;
      int v341 = v340[v428];
      int v445 = v341 + ((int)((unsigned int)(v341 - v337) >> 31));
      v340[v428] = v445;
      int * v343 = v307->cache_age;
      v343[v442] = 0;
      v389 = v442;
    } else {
      int * v346 = v307->cache_age;
      int v449 = 4 + ((((int)((unsigned int)((int)((unsigned int)v313 >> 2)) >> 1)) & 3) * 2);
      int v347 = v346[v449];
      int * v348 = v307->cache_tags;
      int v349 = v348[v449];
      int v350 = v346[v428];
      int v351 = v348[v428];
      int * v352 = v307->cache_dirty;
      int v452 = (4 + ((((int)((unsigned int)((int)((unsigned int)v313 >> 2)) >> 1)) & 3) * 2)) + ((((v347 + ((~(((v349 ^ -1) | (-(v349 ^ -1))) >> 31)) & 2)) - (v350 + ((~(((v351 ^ -1) | (-(v351 ^ -1))) >> 31)) & 2))) >> 31) & 1);
      int v353 = v352[v452];
      bool v453 = !(v353 == 0);
      if (v453) {
        int * v354 = v307->cache_tags;
        int v355 = v354[v452];
        int * v356 = v307->cache_vals;
        int v456 = ((4 + ((((int)((unsigned int)((int)((unsigned int)v313 >> 2)) >> 1)) & 3) * 2)) + ((((v347 + ((~(((v349 ^ -1) | (-(v349 ^ -1))) >> 31)) & 2)) - (v350 + ((~(((v351 ^ -1) | (-(v351 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
        int v357 = v356[v456];
        int v457 = (((4 + ((((int)((unsigned int)((int)((unsigned int)v313 >> 2)) >> 1)) & 3) * 2)) + ((((v347 + ((~(((v349 ^ -1) | (-(v349 ^ -1))) >> 31)) & 2)) - (v350 + ((~(((v351 ^ -1) | (-(v351 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
        int v358 = v356[v457];
        int * v359 = v307->mem;
        int v459 = v355 * 2;
        v359[v459] = v357;
        int * v361 = v307->mem;
        int v462 = (v355 * 2) + 1;
        v361[v462] = v358;
        ;
      } else {
        ;
      }
      int * v366 = v307->mem;
      int v467 = ((int)((unsigned int)((int)((unsigned int)v313 >> 2)) >> 1)) * 2;
      int v367 = v366[v467];
      int v468 = (((int)((unsigned int)((int)((unsigned int)v313 >> 2)) >> 1)) * 2) + 1;
      int v368 = v366[v468];
      int * v369 = v307->cache_vals;
      int v470 = ((4 + ((((int)((unsigned int)((int)((unsigned int)v313 >> 2)) >> 1)) & 3) * 2)) + ((((v347 + ((~(((v349 ^ -1) | (-(v349 ^ -1))) >> 31)) & 2)) - (v350 + ((~(((v351 ^ -1) | (-(v351 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
      v369[v470] = v367;
      int * v371 = v307->cache_vals;
      int v473 = (((4 + ((((int)((unsigned int)((int)((unsigned int)v313 >> 2)) >> 1)) & 3) * 2)) + ((((v347 + ((~(((v349 ^ -1) | (-(v349 ^ -1))) >> 31)) & 2)) - (v350 + ((~(((v351 ^ -1) | (-(v351 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
      v371[v473] = v368;
      int * v373 = v307->cache_tags;
      int v476 = (int)((unsigned int)((int)((unsigned int)v313 >> 2)) >> 1);
      v373[v452] = v476;
      int * v375 = v307->cache_dirty;
      v375[v452] = 0;
      int * v377 = v307->cache_age;
      v377[v452] = 1;
      int * v379 = v307->cache_age;
      int v380 = v379[v452];
      int v381 = v379[v427];
      int v482 = v381 + ((int)((unsigned int)(v381 - v380) >> 31));
      v379[v427] = v482;
      int * v383 = v307->cache_age;
      int v384 = v383[v428];
      int v484 = v384 + ((int)((unsigned int)(v384 - v380) >> 31));
      v383[v428] = v484;
      int * v386 = v307->cache_age;
      v386[v452] = 0;
      v389 = v452;
    }
    int * v390 = v307->cache_vals;
    int v487 = v389 * 2;
    int v391 = v390[v487];
    int v488 = (v389 * 2) + 1;
    int v392 = v390[v488];
    int v489 = (((((int)((unsigned int)((int)((unsigned int)v313 >> 2)) >> 1)) & 1) * 2) + ((((v331 + ((~(((v333 ^ -1) | (-(v333 ^ -1))) >> 31)) & 2)) - (v334 + ((~(((v335 ^ -1) | (-(v335 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
    v390[v489] = v391;
    int * v394 = v307->cache_vals;
    int v492 = ((((((int)((unsigned int)((int)((unsigned int)v313 >> 2)) >> 1)) & 1) * 2) + ((((v331 + ((~(((v333 ^ -1) | (-(v333 ^ -1))) >> 31)) & 2)) - (v334 + ((~(((v335 ^ -1) | (-(v335 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
    v394[v492] = v392;
    int * v396 = v307->cache_tags;
    int v495 = ((((int)((unsigned int)((int)((unsigned int)v313 >> 2)) >> 1)) & 1) * 2) + ((((v331 + ((~(((v333 ^ -1) | (-(v333 ^ -1))) >> 31)) & 2)) - (v334 + ((~(((v335 ^ -1) | (-(v335 ^ -1))) >> 31)) & 2))) >> 31) & 1);
    int v496 = (int)((unsigned int)((int)((unsigned int)v313 >> 2)) >> 1);
    v396[v495] = v496;
    int * v398 = v307->cache_dirty;
    v398[v495] = 0;
    int * v400 = v307->cache_age;
    v400[v495] = 1;
    int * v402 = v307->cache_age;
    int v403 = v402[v495];
    int v404 = v402[v425];
    int v502 = v404 + ((int)((unsigned int)(v404 - v403) >> 31));
    v402[v425] = v502;
    int * v406 = v307->cache_age;
    int v407 = v406[v426];
    int v504 = v407 + ((int)((unsigned int)(v407 - v403) >> 31));
    v406[v426] = v504;
    int * v409 = v307->cache_age;
    v409[v495] = 0;
    v412 = v495;
  }
  int v507 = (v412 * 2) + (((int)((unsigned int)v313 >> 2)) & 1);
  int v413 = v319[v507];
  int * v414 = v307->reg_ready;
  int v509 = ((v311 + ((v308 - v311) & (~((v308 - v311) >> 31)))) + 1) + ((100 ^ (((~(((v317 ^ ((int)((unsigned int)((int)((unsigned int)v313 >> 2)) >> 1))) | (-(v317 ^ ((int)((unsigned int)((int)((unsigned int)v313 >> 2)) >> 1))))) >> 31)) | (~(((v318 ^ ((int)((unsigned int)((int)((unsigned int)v313 >> 2)) >> 1))) | (-(v318 ^ ((int)((unsigned int)((int)((unsigned int)v313 >> 2)) >> 1))))) >> 31))) & 104)) ^ (((~(((v315 ^ ((int)((unsigned int)((int)((unsigned int)v313 >> 2)) >> 1))) | (-(v315 ^ ((int)((unsigned int)((int)((unsigned int)v313 >> 2)) >> 1))))) >> 31)) | (~(((v316 ^ ((int)((unsigned int)((int)((unsigned int)v313 >> 2)) >> 1))) | (-(v316 ^ ((int)((unsigned int)((int)((unsigned int)v313 >> 2)) >> 1))))) >> 31))) & (1 ^ (100 ^ (((~(((v317 ^ ((int)((unsigned int)((int)((unsigned int)v313 >> 2)) >> 1))) | (-(v317 ^ ((int)((unsigned int)((int)((unsigned int)v313 >> 2)) >> 1))))) >> 31)) | (~(((v318 ^ ((int)((unsigned int)((int)((unsigned int)v313 >> 2)) >> 1))) | (-(v318 ^ ((int)((unsigned int)((int)((unsigned int)v313 >> 2)) >> 1))))) >> 31))) & 104)))));
  v414[11] = v509;
  int * v416 = v307->regs;
  v416[11] = v413;
  struct StateT * v418 = slot_7(v307);
  return v418;
}

struct StateT * slot_16(struct StateT * v834) {
  int v835 = v834->timer;
  int v848 = v835 + 1;
  v834->timer = v848;
  int * v837 = v834->reg_ready;
  int v838 = v837[11];
  int * v839 = v834->regs;
  int v840 = v839[11];
  int v841 = v837[10];
  int v842 = v839[10];
  int v853 = (v841 + (((v838 + ((v835 - v838) & (~((v835 - v838) >> 31)))) - v841) & (~(((v838 + ((v835 - v838) & (~((v835 - v838) >> 31)))) - v841) >> 31)))) + 1;
  v837[10] = v853;
  int * v844 = v834->regs;
  int v855 = v840 + v842;
  v844[10] = v855;
  struct StateT * v846 = slot_17(v834);
  return v846;
}

struct StateT * slot_5(struct StateT * v100) {
  int v101 = v100->timer;
  int v213 = v101 + 1;
  v100->timer = v213;
  int * v103 = v100->reg_ready;
  int v104 = v103[10];
  int * v105 = v100->regs;
  int v106 = v105[10];
  int * v107 = v100->cache_tags;
  int v218 = (((int)((unsigned int)((int)((unsigned int)v106 >> 2)) >> 1)) & 1) * 2;
  int v108 = v107[v218];
  int v219 = ((((int)((unsigned int)((int)((unsigned int)v106 >> 2)) >> 1)) & 1) * 2) + 1;
  int v109 = v107[v219];
  int v220 = 4 + ((((int)((unsigned int)((int)((unsigned int)v106 >> 2)) >> 1)) & 3) * 2);
  int v110 = v107[v220];
  int v221 = (4 + ((((int)((unsigned int)((int)((unsigned int)v106 >> 2)) >> 1)) & 3) * 2)) + 1;
  int v111 = v107[v221];
  int * v112 = v100->cache_vals;
  bool v222 = !(((~(((v108 ^ ((int)((unsigned int)((int)((unsigned int)v106 >> 2)) >> 1))) | (-(v108 ^ ((int)((unsigned int)((int)((unsigned int)v106 >> 2)) >> 1))))) >> 31)) | (~(((v109 ^ ((int)((unsigned int)((int)((unsigned int)v106 >> 2)) >> 1))) | (-(v109 ^ ((int)((unsigned int)((int)((unsigned int)v106 >> 2)) >> 1))))) >> 31))) == 0);
  int v205;
  if (v222) {
    int * v113 = v100->cache_age;
    int v224 = ((((int)((unsigned int)((int)((unsigned int)v106 >> 2)) >> 1)) & 1) * 2) + ((~(((v109 ^ ((int)((unsigned int)((int)((unsigned int)v106 >> 2)) >> 1))) | (-(v109 ^ ((int)((unsigned int)((int)((unsigned int)v106 >> 2)) >> 1))))) >> 31)) & 1);
    int v114 = v113[v224];
    int v115 = v113[v218];
    int v225 = v115 + ((int)((unsigned int)(v115 - v114) >> 31));
    v113[v218] = v225;
    int * v117 = v100->cache_age;
    int v118 = v117[v219];
    int v227 = v118 + ((int)((unsigned int)(v118 - v114) >> 31));
    v117[v219] = v227;
    int * v120 = v100->cache_age;
    v120[v224] = 0;
    v205 = v224;
  } else {
    int * v123 = v100->cache_age;
    int v231 = (((int)((unsigned int)((int)((unsigned int)v106 >> 2)) >> 1)) & 1) * 2;
    int v124 = v123[v231];
    int * v125 = v100->cache_tags;
    int v126 = v125[v231];
    int v127 = v123[v219];
    int v128 = v125[v219];
    bool v233 = !(((~(((v110 ^ ((int)((unsigned int)((int)((unsigned int)v106 >> 2)) >> 1))) | (-(v110 ^ ((int)((unsigned int)((int)((unsigned int)v106 >> 2)) >> 1))))) >> 31)) | (~(((v111 ^ ((int)((unsigned int)((int)((unsigned int)v106 >> 2)) >> 1))) | (-(v111 ^ ((int)((unsigned int)((int)((unsigned int)v106 >> 2)) >> 1))))) >> 31))) == 0);
    int v182;
    if (v233) {
      int * v129 = v100->cache_age;
      int v235 = (4 + ((((int)((unsigned int)((int)((unsigned int)v106 >> 2)) >> 1)) & 3) * 2)) + ((~(((v111 ^ ((int)((unsigned int)((int)((unsigned int)v106 >> 2)) >> 1))) | (-(v111 ^ ((int)((unsigned int)((int)((unsigned int)v106 >> 2)) >> 1))))) >> 31)) & 1);
      int v130 = v129[v235];
      int v131 = v129[v220];
      int v236 = v131 + ((int)((unsigned int)(v131 - v130) >> 31));
      v129[v220] = v236;
      int * v133 = v100->cache_age;
      int v134 = v133[v221];
      int v238 = v134 + ((int)((unsigned int)(v134 - v130) >> 31));
      v133[v221] = v238;
      int * v136 = v100->cache_age;
      v136[v235] = 0;
      v182 = v235;
    } else {
      int * v139 = v100->cache_age;
      int v242 = 4 + ((((int)((unsigned int)((int)((unsigned int)v106 >> 2)) >> 1)) & 3) * 2);
      int v140 = v139[v242];
      int * v141 = v100->cache_tags;
      int v142 = v141[v242];
      int v143 = v139[v221];
      int v144 = v141[v221];
      int * v145 = v100->cache_dirty;
      int v245 = (4 + ((((int)((unsigned int)((int)((unsigned int)v106 >> 2)) >> 1)) & 3) * 2)) + ((((v140 + ((~(((v142 ^ -1) | (-(v142 ^ -1))) >> 31)) & 2)) - (v143 + ((~(((v144 ^ -1) | (-(v144 ^ -1))) >> 31)) & 2))) >> 31) & 1);
      int v146 = v145[v245];
      bool v246 = !(v146 == 0);
      if (v246) {
        int * v147 = v100->cache_tags;
        int v148 = v147[v245];
        int * v149 = v100->cache_vals;
        int v249 = ((4 + ((((int)((unsigned int)((int)((unsigned int)v106 >> 2)) >> 1)) & 3) * 2)) + ((((v140 + ((~(((v142 ^ -1) | (-(v142 ^ -1))) >> 31)) & 2)) - (v143 + ((~(((v144 ^ -1) | (-(v144 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
        int v150 = v149[v249];
        int v250 = (((4 + ((((int)((unsigned int)((int)((unsigned int)v106 >> 2)) >> 1)) & 3) * 2)) + ((((v140 + ((~(((v142 ^ -1) | (-(v142 ^ -1))) >> 31)) & 2)) - (v143 + ((~(((v144 ^ -1) | (-(v144 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
        int v151 = v149[v250];
        int * v152 = v100->mem;
        int v252 = v148 * 2;
        v152[v252] = v150;
        int * v154 = v100->mem;
        int v255 = (v148 * 2) + 1;
        v154[v255] = v151;
        ;
      } else {
        ;
      }
      int * v159 = v100->mem;
      int v260 = ((int)((unsigned int)((int)((unsigned int)v106 >> 2)) >> 1)) * 2;
      int v160 = v159[v260];
      int v261 = (((int)((unsigned int)((int)((unsigned int)v106 >> 2)) >> 1)) * 2) + 1;
      int v161 = v159[v261];
      int * v162 = v100->cache_vals;
      int v263 = ((4 + ((((int)((unsigned int)((int)((unsigned int)v106 >> 2)) >> 1)) & 3) * 2)) + ((((v140 + ((~(((v142 ^ -1) | (-(v142 ^ -1))) >> 31)) & 2)) - (v143 + ((~(((v144 ^ -1) | (-(v144 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
      v162[v263] = v160;
      int * v164 = v100->cache_vals;
      int v266 = (((4 + ((((int)((unsigned int)((int)((unsigned int)v106 >> 2)) >> 1)) & 3) * 2)) + ((((v140 + ((~(((v142 ^ -1) | (-(v142 ^ -1))) >> 31)) & 2)) - (v143 + ((~(((v144 ^ -1) | (-(v144 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
      v164[v266] = v161;
      int * v166 = v100->cache_tags;
      int v269 = (int)((unsigned int)((int)((unsigned int)v106 >> 2)) >> 1);
      v166[v245] = v269;
      int * v168 = v100->cache_dirty;
      v168[v245] = 0;
      int * v170 = v100->cache_age;
      v170[v245] = 1;
      int * v172 = v100->cache_age;
      int v173 = v172[v245];
      int v174 = v172[v220];
      int v275 = v174 + ((int)((unsigned int)(v174 - v173) >> 31));
      v172[v220] = v275;
      int * v176 = v100->cache_age;
      int v177 = v176[v221];
      int v277 = v177 + ((int)((unsigned int)(v177 - v173) >> 31));
      v176[v221] = v277;
      int * v179 = v100->cache_age;
      v179[v245] = 0;
      v182 = v245;
    }
    int * v183 = v100->cache_vals;
    int v280 = v182 * 2;
    int v184 = v183[v280];
    int v281 = (v182 * 2) + 1;
    int v185 = v183[v281];
    int v282 = (((((int)((unsigned int)((int)((unsigned int)v106 >> 2)) >> 1)) & 1) * 2) + ((((v124 + ((~(((v126 ^ -1) | (-(v126 ^ -1))) >> 31)) & 2)) - (v127 + ((~(((v128 ^ -1) | (-(v128 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
    v183[v282] = v184;
    int * v187 = v100->cache_vals;
    int v285 = ((((((int)((unsigned int)((int)((unsigned int)v106 >> 2)) >> 1)) & 1) * 2) + ((((v124 + ((~(((v126 ^ -1) | (-(v126 ^ -1))) >> 31)) & 2)) - (v127 + ((~(((v128 ^ -1) | (-(v128 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
    v187[v285] = v185;
    int * v189 = v100->cache_tags;
    int v288 = ((((int)((unsigned int)((int)((unsigned int)v106 >> 2)) >> 1)) & 1) * 2) + ((((v124 + ((~(((v126 ^ -1) | (-(v126 ^ -1))) >> 31)) & 2)) - (v127 + ((~(((v128 ^ -1) | (-(v128 ^ -1))) >> 31)) & 2))) >> 31) & 1);
    int v289 = (int)((unsigned int)((int)((unsigned int)v106 >> 2)) >> 1);
    v189[v288] = v289;
    int * v191 = v100->cache_dirty;
    v191[v288] = 0;
    int * v193 = v100->cache_age;
    v193[v288] = 1;
    int * v195 = v100->cache_age;
    int v196 = v195[v288];
    int v197 = v195[v218];
    int v295 = v197 + ((int)((unsigned int)(v197 - v196) >> 31));
    v195[v218] = v295;
    int * v199 = v100->cache_age;
    int v200 = v199[v219];
    int v297 = v200 + ((int)((unsigned int)(v200 - v196) >> 31));
    v199[v219] = v297;
    int * v202 = v100->cache_age;
    v202[v288] = 0;
    v205 = v288;
  }
  int v300 = (v205 * 2) + (((int)((unsigned int)v106 >> 2)) & 1);
  int v206 = v112[v300];
  int * v207 = v100->reg_ready;
  int v302 = ((v104 + ((v101 - v104) & (~((v101 - v104) >> 31)))) + 1) + ((100 ^ (((~(((v110 ^ ((int)((unsigned int)((int)((unsigned int)v106 >> 2)) >> 1))) | (-(v110 ^ ((int)((unsigned int)((int)((unsigned int)v106 >> 2)) >> 1))))) >> 31)) | (~(((v111 ^ ((int)((unsigned int)((int)((unsigned int)v106 >> 2)) >> 1))) | (-(v111 ^ ((int)((unsigned int)((int)((unsigned int)v106 >> 2)) >> 1))))) >> 31))) & 104)) ^ (((~(((v108 ^ ((int)((unsigned int)((int)((unsigned int)v106 >> 2)) >> 1))) | (-(v108 ^ ((int)((unsigned int)((int)((unsigned int)v106 >> 2)) >> 1))))) >> 31)) | (~(((v109 ^ ((int)((unsigned int)((int)((unsigned int)v106 >> 2)) >> 1))) | (-(v109 ^ ((int)((unsigned int)((int)((unsigned int)v106 >> 2)) >> 1))))) >> 31))) & (1 ^ (100 ^ (((~(((v110 ^ ((int)((unsigned int)((int)((unsigned int)v106 >> 2)) >> 1))) | (-(v110 ^ ((int)((unsigned int)((int)((unsigned int)v106 >> 2)) >> 1))))) >> 31)) | (~(((v111 ^ ((int)((unsigned int)((int)((unsigned int)v106 >> 2)) >> 1))) | (-(v111 ^ ((int)((unsigned int)((int)((unsigned int)v106 >> 2)) >> 1))))) >> 31))) & 104)))));
  v207[10] = v302;
  int * v209 = v100->regs;
  v209[10] = v206;
  struct StateT * v211 = slot_6(v100);
  return v211;
}

struct StateT * slot_17(struct StateT * v858) {
  int v859 = v858->timer;
  int v971 = v859 + 1;
  v858->timer = v971;
  int * v861 = v858->reg_ready;
  int v862 = v861[10];
  int * v863 = v858->regs;
  int v864 = v863[10];
  int * v865 = v858->cache_tags;
  int v976 = (((int)((unsigned int)((int)((unsigned int)v864 >> 2)) >> 1)) & 1) * 2;
  int v866 = v865[v976];
  int v977 = ((((int)((unsigned int)((int)((unsigned int)v864 >> 2)) >> 1)) & 1) * 2) + 1;
  int v867 = v865[v977];
  int v978 = 4 + ((((int)((unsigned int)((int)((unsigned int)v864 >> 2)) >> 1)) & 3) * 2);
  int v868 = v865[v978];
  int v979 = (4 + ((((int)((unsigned int)((int)((unsigned int)v864 >> 2)) >> 1)) & 3) * 2)) + 1;
  int v869 = v865[v979];
  int * v870 = v858->cache_vals;
  bool v980 = !(((~(((v866 ^ ((int)((unsigned int)((int)((unsigned int)v864 >> 2)) >> 1))) | (-(v866 ^ ((int)((unsigned int)((int)((unsigned int)v864 >> 2)) >> 1))))) >> 31)) | (~(((v867 ^ ((int)((unsigned int)((int)((unsigned int)v864 >> 2)) >> 1))) | (-(v867 ^ ((int)((unsigned int)((int)((unsigned int)v864 >> 2)) >> 1))))) >> 31))) == 0);
  int v963;
  if (v980) {
    int * v871 = v858->cache_age;
    int v982 = ((((int)((unsigned int)((int)((unsigned int)v864 >> 2)) >> 1)) & 1) * 2) + ((~(((v867 ^ ((int)((unsigned int)((int)((unsigned int)v864 >> 2)) >> 1))) | (-(v867 ^ ((int)((unsigned int)((int)((unsigned int)v864 >> 2)) >> 1))))) >> 31)) & 1);
    int v872 = v871[v982];
    int v873 = v871[v976];
    int v983 = v873 + ((int)((unsigned int)(v873 - v872) >> 31));
    v871[v976] = v983;
    int * v875 = v858->cache_age;
    int v876 = v875[v977];
    int v985 = v876 + ((int)((unsigned int)(v876 - v872) >> 31));
    v875[v977] = v985;
    int * v878 = v858->cache_age;
    v878[v982] = 0;
    v963 = v982;
  } else {
    int * v881 = v858->cache_age;
    int v989 = (((int)((unsigned int)((int)((unsigned int)v864 >> 2)) >> 1)) & 1) * 2;
    int v882 = v881[v989];
    int * v883 = v858->cache_tags;
    int v884 = v883[v989];
    int v885 = v881[v977];
    int v886 = v883[v977];
    bool v991 = !(((~(((v868 ^ ((int)((unsigned int)((int)((unsigned int)v864 >> 2)) >> 1))) | (-(v868 ^ ((int)((unsigned int)((int)((unsigned int)v864 >> 2)) >> 1))))) >> 31)) | (~(((v869 ^ ((int)((unsigned int)((int)((unsigned int)v864 >> 2)) >> 1))) | (-(v869 ^ ((int)((unsigned int)((int)((unsigned int)v864 >> 2)) >> 1))))) >> 31))) == 0);
    int v940;
    if (v991) {
      int * v887 = v858->cache_age;
      int v993 = (4 + ((((int)((unsigned int)((int)((unsigned int)v864 >> 2)) >> 1)) & 3) * 2)) + ((~(((v869 ^ ((int)((unsigned int)((int)((unsigned int)v864 >> 2)) >> 1))) | (-(v869 ^ ((int)((unsigned int)((int)((unsigned int)v864 >> 2)) >> 1))))) >> 31)) & 1);
      int v888 = v887[v993];
      int v889 = v887[v978];
      int v994 = v889 + ((int)((unsigned int)(v889 - v888) >> 31));
      v887[v978] = v994;
      int * v891 = v858->cache_age;
      int v892 = v891[v979];
      int v996 = v892 + ((int)((unsigned int)(v892 - v888) >> 31));
      v891[v979] = v996;
      int * v894 = v858->cache_age;
      v894[v993] = 0;
      v940 = v993;
    } else {
      int * v897 = v858->cache_age;
      int v1000 = 4 + ((((int)((unsigned int)((int)((unsigned int)v864 >> 2)) >> 1)) & 3) * 2);
      int v898 = v897[v1000];
      int * v899 = v858->cache_tags;
      int v900 = v899[v1000];
      int v901 = v897[v979];
      int v902 = v899[v979];
      int * v903 = v858->cache_dirty;
      int v1003 = (4 + ((((int)((unsigned int)((int)((unsigned int)v864 >> 2)) >> 1)) & 3) * 2)) + ((((v898 + ((~(((v900 ^ -1) | (-(v900 ^ -1))) >> 31)) & 2)) - (v901 + ((~(((v902 ^ -1) | (-(v902 ^ -1))) >> 31)) & 2))) >> 31) & 1);
      int v904 = v903[v1003];
      bool v1004 = !(v904 == 0);
      if (v1004) {
        int * v905 = v858->cache_tags;
        int v906 = v905[v1003];
        int * v907 = v858->cache_vals;
        int v1007 = ((4 + ((((int)((unsigned int)((int)((unsigned int)v864 >> 2)) >> 1)) & 3) * 2)) + ((((v898 + ((~(((v900 ^ -1) | (-(v900 ^ -1))) >> 31)) & 2)) - (v901 + ((~(((v902 ^ -1) | (-(v902 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
        int v908 = v907[v1007];
        int v1008 = (((4 + ((((int)((unsigned int)((int)((unsigned int)v864 >> 2)) >> 1)) & 3) * 2)) + ((((v898 + ((~(((v900 ^ -1) | (-(v900 ^ -1))) >> 31)) & 2)) - (v901 + ((~(((v902 ^ -1) | (-(v902 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
        int v909 = v907[v1008];
        int * v910 = v858->mem;
        int v1010 = v906 * 2;
        v910[v1010] = v908;
        int * v912 = v858->mem;
        int v1013 = (v906 * 2) + 1;
        v912[v1013] = v909;
        ;
      } else {
        ;
      }
      int * v917 = v858->mem;
      int v1018 = ((int)((unsigned int)((int)((unsigned int)v864 >> 2)) >> 1)) * 2;
      int v918 = v917[v1018];
      int v1019 = (((int)((unsigned int)((int)((unsigned int)v864 >> 2)) >> 1)) * 2) + 1;
      int v919 = v917[v1019];
      int * v920 = v858->cache_vals;
      int v1021 = ((4 + ((((int)((unsigned int)((int)((unsigned int)v864 >> 2)) >> 1)) & 3) * 2)) + ((((v898 + ((~(((v900 ^ -1) | (-(v900 ^ -1))) >> 31)) & 2)) - (v901 + ((~(((v902 ^ -1) | (-(v902 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
      v920[v1021] = v918;
      int * v922 = v858->cache_vals;
      int v1024 = (((4 + ((((int)((unsigned int)((int)((unsigned int)v864 >> 2)) >> 1)) & 3) * 2)) + ((((v898 + ((~(((v900 ^ -1) | (-(v900 ^ -1))) >> 31)) & 2)) - (v901 + ((~(((v902 ^ -1) | (-(v902 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
      v922[v1024] = v919;
      int * v924 = v858->cache_tags;
      int v1027 = (int)((unsigned int)((int)((unsigned int)v864 >> 2)) >> 1);
      v924[v1003] = v1027;
      int * v926 = v858->cache_dirty;
      v926[v1003] = 0;
      int * v928 = v858->cache_age;
      v928[v1003] = 1;
      int * v930 = v858->cache_age;
      int v931 = v930[v1003];
      int v932 = v930[v978];
      int v1033 = v932 + ((int)((unsigned int)(v932 - v931) >> 31));
      v930[v978] = v1033;
      int * v934 = v858->cache_age;
      int v935 = v934[v979];
      int v1035 = v935 + ((int)((unsigned int)(v935 - v931) >> 31));
      v934[v979] = v1035;
      int * v937 = v858->cache_age;
      v937[v1003] = 0;
      v940 = v1003;
    }
    int * v941 = v858->cache_vals;
    int v1038 = v940 * 2;
    int v942 = v941[v1038];
    int v1039 = (v940 * 2) + 1;
    int v943 = v941[v1039];
    int v1040 = (((((int)((unsigned int)((int)((unsigned int)v864 >> 2)) >> 1)) & 1) * 2) + ((((v882 + ((~(((v884 ^ -1) | (-(v884 ^ -1))) >> 31)) & 2)) - (v885 + ((~(((v886 ^ -1) | (-(v886 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
    v941[v1040] = v942;
    int * v945 = v858->cache_vals;
    int v1043 = ((((((int)((unsigned int)((int)((unsigned int)v864 >> 2)) >> 1)) & 1) * 2) + ((((v882 + ((~(((v884 ^ -1) | (-(v884 ^ -1))) >> 31)) & 2)) - (v885 + ((~(((v886 ^ -1) | (-(v886 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
    v945[v1043] = v943;
    int * v947 = v858->cache_tags;
    int v1046 = ((((int)((unsigned int)((int)((unsigned int)v864 >> 2)) >> 1)) & 1) * 2) + ((((v882 + ((~(((v884 ^ -1) | (-(v884 ^ -1))) >> 31)) & 2)) - (v885 + ((~(((v886 ^ -1) | (-(v886 ^ -1))) >> 31)) & 2))) >> 31) & 1);
    int v1047 = (int)((unsigned int)((int)((unsigned int)v864 >> 2)) >> 1);
    v947[v1046] = v1047;
    int * v949 = v858->cache_dirty;
    v949[v1046] = 0;
    int * v951 = v858->cache_age;
    v951[v1046] = 1;
    int * v953 = v858->cache_age;
    int v954 = v953[v1046];
    int v955 = v953[v976];
    int v1053 = v955 + ((int)((unsigned int)(v955 - v954) >> 31));
    v953[v976] = v1053;
    int * v957 = v858->cache_age;
    int v958 = v957[v977];
    int v1055 = v958 + ((int)((unsigned int)(v958 - v954) >> 31));
    v957[v977] = v1055;
    int * v960 = v858->cache_age;
    v960[v1046] = 0;
    v963 = v1046;
  }
  int v1058 = (v963 * 2) + (((int)((unsigned int)v864 >> 2)) & 1);
  int v964 = v870[v1058];
  int * v965 = v858->reg_ready;
  int v1060 = ((v862 + ((v859 - v862) & (~((v859 - v862) >> 31)))) + 1) + ((100 ^ (((~(((v868 ^ ((int)((unsigned int)((int)((unsigned int)v864 >> 2)) >> 1))) | (-(v868 ^ ((int)((unsigned int)((int)((unsigned int)v864 >> 2)) >> 1))))) >> 31)) | (~(((v869 ^ ((int)((unsigned int)((int)((unsigned int)v864 >> 2)) >> 1))) | (-(v869 ^ ((int)((unsigned int)((int)((unsigned int)v864 >> 2)) >> 1))))) >> 31))) & 104)) ^ (((~(((v866 ^ ((int)((unsigned int)((int)((unsigned int)v864 >> 2)) >> 1))) | (-(v866 ^ ((int)((unsigned int)((int)((unsigned int)v864 >> 2)) >> 1))))) >> 31)) | (~(((v867 ^ ((int)((unsigned int)((int)((unsigned int)v864 >> 2)) >> 1))) | (-(v867 ^ ((int)((unsigned int)((int)((unsigned int)v864 >> 2)) >> 1))))) >> 31))) & (1 ^ (100 ^ (((~(((v868 ^ ((int)((unsigned int)((int)((unsigned int)v864 >> 2)) >> 1))) | (-(v868 ^ ((int)((unsigned int)((int)((unsigned int)v864 >> 2)) >> 1))))) >> 31)) | (~(((v869 ^ ((int)((unsigned int)((int)((unsigned int)v864 >> 2)) >> 1))) | (-(v869 ^ ((int)((unsigned int)((int)((unsigned int)v864 >> 2)) >> 1))))) >> 31))) & 104)))));
  v965[10] = v1060;
  int * v967 = v858->regs;
  v967[10] = v964;
  struct StateT * v969 = slot_18(v858);
  return v969;
}

struct StateT * slot_20(struct StateT * v1297) {
  int v1298 = v1297->timer;
  int v1471 = v1298 + 1;
  v1297->timer = v1471;
  int * v1300 = v1297->reg_ready;
  int * v1302 = v1297->regs;
  int v1303 = v1302[12];
  int v1305 = v1302[10];
  int * v1306 = v1297->cache_tags;
  int v1477 = (((int)((unsigned int)((int)((unsigned int)(v1303 + 68) >> 2)) >> 1)) & 1) * 2;
  int v1307 = v1306[v1477];
  int v1478 = ((((int)((unsigned int)((int)((unsigned int)(v1303 + 68) >> 2)) >> 1)) & 1) * 2) + 1;
  int v1308 = v1306[v1478];
  int v1479 = 4 + ((((int)((unsigned int)((int)((unsigned int)(v1303 + 68) >> 2)) >> 1)) & 3) * 2);
  int v1309 = v1306[v1479];
  int v1480 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v1303 + 68) >> 2)) >> 1)) & 3) * 2)) + 1;
  int v1310 = v1306[v1480];
  int v1311 = v1297->timer;
  int v1481 = v1311 + ((100 ^ (((~(((v1309 ^ ((int)((unsigned int)((int)((unsigned int)(v1303 + 68) >> 2)) >> 1))) | (-(v1309 ^ ((int)((unsigned int)((int)((unsigned int)(v1303 + 68) >> 2)) >> 1))))) >> 31)) | (~(((v1310 ^ ((int)((unsigned int)((int)((unsigned int)(v1303 + 68) >> 2)) >> 1))) | (-(v1310 ^ ((int)((unsigned int)((int)((unsigned int)(v1303 + 68) >> 2)) >> 1))))) >> 31))) & 104)) ^ (((~(((v1307 ^ ((int)((unsigned int)((int)((unsigned int)(v1303 + 68) >> 2)) >> 1))) | (-(v1307 ^ ((int)((unsigned int)((int)((unsigned int)(v1303 + 68) >> 2)) >> 1))))) >> 31)) | (~(((v1308 ^ ((int)((unsigned int)((int)((unsigned int)(v1303 + 68) >> 2)) >> 1))) | (-(v1308 ^ ((int)((unsigned int)((int)((unsigned int)(v1303 + 68) >> 2)) >> 1))))) >> 31))) & (1 ^ (100 ^ (((~(((v1309 ^ ((int)((unsigned int)((int)((unsigned int)(v1303 + 68) >> 2)) >> 1))) | (-(v1309 ^ ((int)((unsigned int)((int)((unsigned int)(v1303 + 68) >> 2)) >> 1))))) >> 31)) | (~(((v1310 ^ ((int)((unsigned int)((int)((unsigned int)(v1303 + 68) >> 2)) >> 1))) | (-(v1310 ^ ((int)((unsigned int)((int)((unsigned int)(v1303 + 68) >> 2)) >> 1))))) >> 31))) & 104)))));
  v1297->timer = v1481;
  bool v1482 = !(((~(((v1307 ^ ((int)((unsigned int)((int)((unsigned int)(v1303 + 68) >> 2)) >> 1))) | (-(v1307 ^ ((int)((unsigned int)((int)((unsigned int)(v1303 + 68) >> 2)) >> 1))))) >> 31)) | (~(((v1308 ^ ((int)((unsigned int)((int)((unsigned int)(v1303 + 68) >> 2)) >> 1))) | (-(v1308 ^ ((int)((unsigned int)((int)((unsigned int)(v1303 + 68) >> 2)) >> 1))))) >> 31))) == 0);
  int v1405;
  if (v1482) {
    int * v1313 = v1297->cache_age;
    int v1484 = ((((int)((unsigned int)((int)((unsigned int)(v1303 + 68) >> 2)) >> 1)) & 1) * 2) + ((~(((v1308 ^ ((int)((unsigned int)((int)((unsigned int)(v1303 + 68) >> 2)) >> 1))) | (-(v1308 ^ ((int)((unsigned int)((int)((unsigned int)(v1303 + 68) >> 2)) >> 1))))) >> 31)) & 1);
    int v1314 = v1313[v1484];
    int v1315 = v1313[v1477];
    int v1485 = v1315 + ((int)((unsigned int)(v1315 - v1314) >> 31));
    v1313[v1477] = v1485;
    int * v1317 = v1297->cache_age;
    int v1318 = v1317[v1478];
    int v1487 = v1318 + ((int)((unsigned int)(v1318 - v1314) >> 31));
    v1317[v1478] = v1487;
    int * v1320 = v1297->cache_age;
    v1320[v1484] = 0;
    v1405 = v1484;
  } else {
    int * v1323 = v1297->cache_age;
    int v1491 = (((int)((unsigned int)((int)((unsigned int)(v1303 + 68) >> 2)) >> 1)) & 1) * 2;
    int v1324 = v1323[v1491];
    int * v1325 = v1297->cache_tags;
    int v1326 = v1325[v1491];
    int v1327 = v1323[v1478];
    int v1328 = v1325[v1478];
    bool v1493 = !(((~(((v1309 ^ ((int)((unsigned int)((int)((unsigned int)(v1303 + 68) >> 2)) >> 1))) | (-(v1309 ^ ((int)((unsigned int)((int)((unsigned int)(v1303 + 68) >> 2)) >> 1))))) >> 31)) | (~(((v1310 ^ ((int)((unsigned int)((int)((unsigned int)(v1303 + 68) >> 2)) >> 1))) | (-(v1310 ^ ((int)((unsigned int)((int)((unsigned int)(v1303 + 68) >> 2)) >> 1))))) >> 31))) == 0);
    int v1382;
    if (v1493) {
      int * v1329 = v1297->cache_age;
      int v1495 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v1303 + 68) >> 2)) >> 1)) & 3) * 2)) + ((~(((v1310 ^ ((int)((unsigned int)((int)((unsigned int)(v1303 + 68) >> 2)) >> 1))) | (-(v1310 ^ ((int)((unsigned int)((int)((unsigned int)(v1303 + 68) >> 2)) >> 1))))) >> 31)) & 1);
      int v1330 = v1329[v1495];
      int v1331 = v1329[v1479];
      int v1496 = v1331 + ((int)((unsigned int)(v1331 - v1330) >> 31));
      v1329[v1479] = v1496;
      int * v1333 = v1297->cache_age;
      int v1334 = v1333[v1480];
      int v1498 = v1334 + ((int)((unsigned int)(v1334 - v1330) >> 31));
      v1333[v1480] = v1498;
      int * v1336 = v1297->cache_age;
      v1336[v1495] = 0;
      v1382 = v1495;
    } else {
      int * v1339 = v1297->cache_age;
      int v1502 = 4 + ((((int)((unsigned int)((int)((unsigned int)(v1303 + 68) >> 2)) >> 1)) & 3) * 2);
      int v1340 = v1339[v1502];
      int * v1341 = v1297->cache_tags;
      int v1342 = v1341[v1502];
      int v1343 = v1339[v1480];
      int v1344 = v1341[v1480];
      int * v1345 = v1297->cache_dirty;
      int v1505 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v1303 + 68) >> 2)) >> 1)) & 3) * 2)) + ((((v1340 + ((~(((v1342 ^ -1) | (-(v1342 ^ -1))) >> 31)) & 2)) - (v1343 + ((~(((v1344 ^ -1) | (-(v1344 ^ -1))) >> 31)) & 2))) >> 31) & 1);
      int v1346 = v1345[v1505];
      bool v1506 = !(v1346 == 0);
      if (v1506) {
        int * v1347 = v1297->cache_tags;
        int v1348 = v1347[v1505];
        int * v1349 = v1297->cache_vals;
        int v1509 = ((4 + ((((int)((unsigned int)((int)((unsigned int)(v1303 + 68) >> 2)) >> 1)) & 3) * 2)) + ((((v1340 + ((~(((v1342 ^ -1) | (-(v1342 ^ -1))) >> 31)) & 2)) - (v1343 + ((~(((v1344 ^ -1) | (-(v1344 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
        int v1350 = v1349[v1509];
        int v1510 = (((4 + ((((int)((unsigned int)((int)((unsigned int)(v1303 + 68) >> 2)) >> 1)) & 3) * 2)) + ((((v1340 + ((~(((v1342 ^ -1) | (-(v1342 ^ -1))) >> 31)) & 2)) - (v1343 + ((~(((v1344 ^ -1) | (-(v1344 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
        int v1351 = v1349[v1510];
        int * v1352 = v1297->mem;
        int v1512 = v1348 * 2;
        v1352[v1512] = v1350;
        int * v1354 = v1297->mem;
        int v1515 = (v1348 * 2) + 1;
        v1354[v1515] = v1351;
        ;
      } else {
        ;
      }
      int * v1359 = v1297->mem;
      int v1520 = ((int)((unsigned int)((int)((unsigned int)(v1303 + 68) >> 2)) >> 1)) * 2;
      int v1360 = v1359[v1520];
      int v1521 = (((int)((unsigned int)((int)((unsigned int)(v1303 + 68) >> 2)) >> 1)) * 2) + 1;
      int v1361 = v1359[v1521];
      int * v1362 = v1297->cache_vals;
      int v1523 = ((4 + ((((int)((unsigned int)((int)((unsigned int)(v1303 + 68) >> 2)) >> 1)) & 3) * 2)) + ((((v1340 + ((~(((v1342 ^ -1) | (-(v1342 ^ -1))) >> 31)) & 2)) - (v1343 + ((~(((v1344 ^ -1) | (-(v1344 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
      v1362[v1523] = v1360;
      int * v1364 = v1297->cache_vals;
      int v1526 = (((4 + ((((int)((unsigned int)((int)((unsigned int)(v1303 + 68) >> 2)) >> 1)) & 3) * 2)) + ((((v1340 + ((~(((v1342 ^ -1) | (-(v1342 ^ -1))) >> 31)) & 2)) - (v1343 + ((~(((v1344 ^ -1) | (-(v1344 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
      v1364[v1526] = v1361;
      int * v1366 = v1297->cache_tags;
      int v1529 = (int)((unsigned int)((int)((unsigned int)(v1303 + 68) >> 2)) >> 1);
      v1366[v1505] = v1529;
      int * v1368 = v1297->cache_dirty;
      v1368[v1505] = 0;
      int * v1370 = v1297->cache_age;
      v1370[v1505] = 1;
      int * v1372 = v1297->cache_age;
      int v1373 = v1372[v1505];
      int v1374 = v1372[v1479];
      int v1535 = v1374 + ((int)((unsigned int)(v1374 - v1373) >> 31));
      v1372[v1479] = v1535;
      int * v1376 = v1297->cache_age;
      int v1377 = v1376[v1480];
      int v1537 = v1377 + ((int)((unsigned int)(v1377 - v1373) >> 31));
      v1376[v1480] = v1537;
      int * v1379 = v1297->cache_age;
      v1379[v1505] = 0;
      v1382 = v1505;
    }
    int * v1383 = v1297->cache_vals;
    int v1540 = v1382 * 2;
    int v1384 = v1383[v1540];
    int v1541 = (v1382 * 2) + 1;
    int v1385 = v1383[v1541];
    int v1542 = (((((int)((unsigned int)((int)((unsigned int)(v1303 + 68) >> 2)) >> 1)) & 1) * 2) + ((((v1324 + ((~(((v1326 ^ -1) | (-(v1326 ^ -1))) >> 31)) & 2)) - (v1327 + ((~(((v1328 ^ -1) | (-(v1328 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
    v1383[v1542] = v1384;
    int * v1387 = v1297->cache_vals;
    int v1545 = ((((((int)((unsigned int)((int)((unsigned int)(v1303 + 68) >> 2)) >> 1)) & 1) * 2) + ((((v1324 + ((~(((v1326 ^ -1) | (-(v1326 ^ -1))) >> 31)) & 2)) - (v1327 + ((~(((v1328 ^ -1) | (-(v1328 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
    v1387[v1545] = v1385;
    int * v1389 = v1297->cache_tags;
    int v1548 = ((((int)((unsigned int)((int)((unsigned int)(v1303 + 68) >> 2)) >> 1)) & 1) * 2) + ((((v1324 + ((~(((v1326 ^ -1) | (-(v1326 ^ -1))) >> 31)) & 2)) - (v1327 + ((~(((v1328 ^ -1) | (-(v1328 ^ -1))) >> 31)) & 2))) >> 31) & 1);
    int v1549 = (int)((unsigned int)((int)((unsigned int)(v1303 + 68) >> 2)) >> 1);
    v1389[v1548] = v1549;
    int * v1391 = v1297->cache_dirty;
    v1391[v1548] = 0;
    int * v1393 = v1297->cache_age;
    v1393[v1548] = 1;
    int * v1395 = v1297->cache_age;
    int v1396 = v1395[v1548];
    int v1397 = v1395[v1477];
    int v1555 = v1397 + ((int)((unsigned int)(v1397 - v1396) >> 31));
    v1395[v1477] = v1555;
    int * v1399 = v1297->cache_age;
    int v1400 = v1399[v1478];
    int v1557 = v1400 + ((int)((unsigned int)(v1400 - v1396) >> 31));
    v1399[v1478] = v1557;
    int * v1402 = v1297->cache_age;
    v1402[v1548] = 0;
    v1405 = v1548;
  }
  int * v1406 = v1297->cache_vals;
  int v1560 = (v1405 * 2) + (((int)((unsigned int)(v1303 + 68) >> 2)) & 1);
  v1406[v1560] = v1305;
  int * v1408 = v1297->cache_tags;
  int v1409 = v1408[v1479];
  int v1410 = v1408[v1480];
  bool v1563 = !(((~(((v1409 ^ ((int)((unsigned int)((int)((unsigned int)(v1303 + 68) >> 2)) >> 1))) | (-(v1409 ^ ((int)((unsigned int)((int)((unsigned int)(v1303 + 68) >> 2)) >> 1))))) >> 31)) | (~(((v1410 ^ ((int)((unsigned int)((int)((unsigned int)(v1303 + 68) >> 2)) >> 1))) | (-(v1410 ^ ((int)((unsigned int)((int)((unsigned int)(v1303 + 68) >> 2)) >> 1))))) >> 31))) == 0);
  int v1464;
  if (v1563) {
    int * v1411 = v1297->cache_age;
    int v1565 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v1303 + 68) >> 2)) >> 1)) & 3) * 2)) + ((~(((v1410 ^ ((int)((unsigned int)((int)((unsigned int)(v1303 + 68) >> 2)) >> 1))) | (-(v1410 ^ ((int)((unsigned int)((int)((unsigned int)(v1303 + 68) >> 2)) >> 1))))) >> 31)) & 1);
    int v1412 = v1411[v1565];
    int v1413 = v1411[v1479];
    int v1566 = v1413 + ((int)((unsigned int)(v1413 - v1412) >> 31));
    v1411[v1479] = v1566;
    int * v1415 = v1297->cache_age;
    int v1416 = v1415[v1480];
    int v1568 = v1416 + ((int)((unsigned int)(v1416 - v1412) >> 31));
    v1415[v1480] = v1568;
    int * v1418 = v1297->cache_age;
    v1418[v1565] = 0;
    v1464 = v1565;
  } else {
    int * v1421 = v1297->cache_age;
    int v1572 = 4 + ((((int)((unsigned int)((int)((unsigned int)(v1303 + 68) >> 2)) >> 1)) & 3) * 2);
    int v1422 = v1421[v1572];
    int * v1423 = v1297->cache_tags;
    int v1424 = v1423[v1572];
    int v1425 = v1421[v1480];
    int v1426 = v1423[v1480];
    int * v1427 = v1297->cache_dirty;
    int v1575 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v1303 + 68) >> 2)) >> 1)) & 3) * 2)) + ((((v1422 + ((~(((v1424 ^ -1) | (-(v1424 ^ -1))) >> 31)) & 2)) - (v1425 + ((~(((v1426 ^ -1) | (-(v1426 ^ -1))) >> 31)) & 2))) >> 31) & 1);
    int v1428 = v1427[v1575];
    bool v1576 = !(v1428 == 0);
    if (v1576) {
      int * v1429 = v1297->cache_tags;
      int v1430 = v1429[v1575];
      int * v1431 = v1297->cache_vals;
      int v1579 = ((4 + ((((int)((unsigned int)((int)((unsigned int)(v1303 + 68) >> 2)) >> 1)) & 3) * 2)) + ((((v1422 + ((~(((v1424 ^ -1) | (-(v1424 ^ -1))) >> 31)) & 2)) - (v1425 + ((~(((v1426 ^ -1) | (-(v1426 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
      int v1432 = v1431[v1579];
      int v1580 = (((4 + ((((int)((unsigned int)((int)((unsigned int)(v1303 + 68) >> 2)) >> 1)) & 3) * 2)) + ((((v1422 + ((~(((v1424 ^ -1) | (-(v1424 ^ -1))) >> 31)) & 2)) - (v1425 + ((~(((v1426 ^ -1) | (-(v1426 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
      int v1433 = v1431[v1580];
      int * v1434 = v1297->mem;
      int v1582 = v1430 * 2;
      v1434[v1582] = v1432;
      int * v1436 = v1297->mem;
      int v1585 = (v1430 * 2) + 1;
      v1436[v1585] = v1433;
      ;
    } else {
      ;
    }
    int * v1441 = v1297->mem;
    int v1590 = ((int)((unsigned int)((int)((unsigned int)(v1303 + 68) >> 2)) >> 1)) * 2;
    int v1442 = v1441[v1590];
    int v1591 = (((int)((unsigned int)((int)((unsigned int)(v1303 + 68) >> 2)) >> 1)) * 2) + 1;
    int v1443 = v1441[v1591];
    int * v1444 = v1297->cache_vals;
    int v1593 = ((4 + ((((int)((unsigned int)((int)((unsigned int)(v1303 + 68) >> 2)) >> 1)) & 3) * 2)) + ((((v1422 + ((~(((v1424 ^ -1) | (-(v1424 ^ -1))) >> 31)) & 2)) - (v1425 + ((~(((v1426 ^ -1) | (-(v1426 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
    v1444[v1593] = v1442;
    int * v1446 = v1297->cache_vals;
    int v1596 = (((4 + ((((int)((unsigned int)((int)((unsigned int)(v1303 + 68) >> 2)) >> 1)) & 3) * 2)) + ((((v1422 + ((~(((v1424 ^ -1) | (-(v1424 ^ -1))) >> 31)) & 2)) - (v1425 + ((~(((v1426 ^ -1) | (-(v1426 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
    v1446[v1596] = v1443;
    int * v1448 = v1297->cache_tags;
    int v1599 = (int)((unsigned int)((int)((unsigned int)(v1303 + 68) >> 2)) >> 1);
    v1448[v1575] = v1599;
    int * v1450 = v1297->cache_dirty;
    v1450[v1575] = 0;
    int * v1452 = v1297->cache_age;
    v1452[v1575] = 1;
    int * v1454 = v1297->cache_age;
    int v1455 = v1454[v1575];
    int v1456 = v1454[v1479];
    int v1605 = v1456 + ((int)((unsigned int)(v1456 - v1455) >> 31));
    v1454[v1479] = v1605;
    int * v1458 = v1297->cache_age;
    int v1459 = v1458[v1480];
    int v1607 = v1459 + ((int)((unsigned int)(v1459 - v1455) >> 31));
    v1458[v1480] = v1607;
    int * v1461 = v1297->cache_age;
    v1461[v1575] = 0;
    v1464 = v1575;
  }
  int * v1465 = v1297->cache_vals;
  int v1610 = (v1464 * 2) + (((int)((unsigned int)(v1303 + 68) >> 2)) & 1);
  v1465[v1610] = v1305;
  int * v1467 = v1297->cache_dirty;
  v1467[v1464] = 1;
  struct StateT * v1469 = slot_21(v1297);
  return v1469;
}

struct StateT * slot_2(struct StateT * v39) {
  int v40 = v39->timer;
  int v51 = v40 + 1;
  v39->timer = v51;
  int * v42 = v39->reg_ready;
  int v43 = v42[11];
  int * v44 = v39->regs;
  int v45 = v44[11];
  int v55 = (v43 + ((v40 - v43) & (~((v40 - v43) >> 31)))) + 1;
  v42[11] = v55;
  int * v47 = v39->regs;
  int v57 = v45 + 72;
  v47[11] = v57;
  struct StateT * v49 = slot_3(v39);
  return v49;
}

struct StateT * slot_7(struct StateT * v514) {
  int v515 = v514->timer;
  int v519 = v515 + 1;
  v514->timer = v519;
  struct StateT * v517 = slot_8(v514);
  return v517;
}

struct StateT * slot_21(struct StateT * v1616) {
  int v1617 = v1616->timer;
  int v1620 = v1617 + 1;
  v1616->timer = v1620;
  return v1616;
}

struct StateT * slot_3(struct StateT * v60) {
  int v61 = v60->timer;
  int v74 = v61 + 1;
  v60->timer = v74;
  int * v63 = v60->reg_ready;
  int v64 = v63[11];
  int * v65 = v60->regs;
  int v66 = v65[11];
  int v67 = v63[10];
  int v68 = v65[10];
  int v79 = (v67 + (((v64 + ((v61 - v64) & (~((v61 - v64) >> 31)))) - v67) & (~(((v64 + ((v61 - v64) & (~((v61 - v64) >> 31)))) - v67) >> 31)))) + 1;
  v63[10] = v79;
  int * v70 = v60->regs;
  int v81 = v66 + v68;
  v70[10] = v81;
  struct StateT * v72 = slot_4(v60);
  return v72;
}

struct StateT * snippet(struct StateT * v0) {
  struct StateT * v1 = slot_0(v0);
  int v1621 = v1->timer;
  int * v1622 = v1->reg_ready;
  int v1623 = v1622[0];
  int v1754 = v1623 + ((v1621 - v1623) & (~((v1621 - v1623) >> 31)));
  v1->timer = v1754;
  int v1625 = v1->timer;
  int * v1626 = v1->reg_ready;
  int v1627 = v1626[1];
  int v1757 = v1627 + ((v1625 - v1627) & (~((v1625 - v1627) >> 31)));
  v1->timer = v1757;
  int v1629 = v1->timer;
  int * v1630 = v1->reg_ready;
  int v1631 = v1630[2];
  int v1760 = v1631 + ((v1629 - v1631) & (~((v1629 - v1631) >> 31)));
  v1->timer = v1760;
  int v1633 = v1->timer;
  int * v1634 = v1->reg_ready;
  int v1635 = v1634[3];
  int v1763 = v1635 + ((v1633 - v1635) & (~((v1633 - v1635) >> 31)));
  v1->timer = v1763;
  int v1637 = v1->timer;
  int * v1638 = v1->reg_ready;
  int v1639 = v1638[4];
  int v1766 = v1639 + ((v1637 - v1639) & (~((v1637 - v1639) >> 31)));
  v1->timer = v1766;
  int v1641 = v1->timer;
  int * v1642 = v1->reg_ready;
  int v1643 = v1642[5];
  int v1769 = v1643 + ((v1641 - v1643) & (~((v1641 - v1643) >> 31)));
  v1->timer = v1769;
  int v1645 = v1->timer;
  int * v1646 = v1->reg_ready;
  int v1647 = v1646[6];
  int v1772 = v1647 + ((v1645 - v1647) & (~((v1645 - v1647) >> 31)));
  v1->timer = v1772;
  int v1649 = v1->timer;
  int * v1650 = v1->reg_ready;
  int v1651 = v1650[7];
  int v1775 = v1651 + ((v1649 - v1651) & (~((v1649 - v1651) >> 31)));
  v1->timer = v1775;
  int v1653 = v1->timer;
  int * v1654 = v1->reg_ready;
  int v1655 = v1654[8];
  int v1778 = v1655 + ((v1653 - v1655) & (~((v1653 - v1655) >> 31)));
  v1->timer = v1778;
  int v1657 = v1->timer;
  int * v1658 = v1->reg_ready;
  int v1659 = v1658[9];
  int v1781 = v1659 + ((v1657 - v1659) & (~((v1657 - v1659) >> 31)));
  v1->timer = v1781;
  int v1661 = v1->timer;
  int * v1662 = v1->reg_ready;
  int v1663 = v1662[10];
  int v1784 = v1663 + ((v1661 - v1663) & (~((v1661 - v1663) >> 31)));
  v1->timer = v1784;
  int v1665 = v1->timer;
  int * v1666 = v1->reg_ready;
  int v1667 = v1666[11];
  int v1787 = v1667 + ((v1665 - v1667) & (~((v1665 - v1667) >> 31)));
  v1->timer = v1787;
  int v1669 = v1->timer;
  int * v1670 = v1->reg_ready;
  int v1671 = v1670[12];
  int v1790 = v1671 + ((v1669 - v1671) & (~((v1669 - v1671) >> 31)));
  v1->timer = v1790;
  int v1673 = v1->timer;
  int * v1674 = v1->reg_ready;
  int v1675 = v1674[13];
  int v1793 = v1675 + ((v1673 - v1675) & (~((v1673 - v1675) >> 31)));
  v1->timer = v1793;
  int v1677 = v1->timer;
  int * v1678 = v1->reg_ready;
  int v1679 = v1678[14];
  int v1796 = v1679 + ((v1677 - v1679) & (~((v1677 - v1679) >> 31)));
  v1->timer = v1796;
  int v1681 = v1->timer;
  int * v1682 = v1->reg_ready;
  int v1683 = v1682[15];
  int v1799 = v1683 + ((v1681 - v1683) & (~((v1681 - v1683) >> 31)));
  v1->timer = v1799;
  int v1685 = v1->timer;
  int * v1686 = v1->reg_ready;
  int v1687 = v1686[16];
  int v1802 = v1687 + ((v1685 - v1687) & (~((v1685 - v1687) >> 31)));
  v1->timer = v1802;
  int v1689 = v1->timer;
  int * v1690 = v1->reg_ready;
  int v1691 = v1690[17];
  int v1805 = v1691 + ((v1689 - v1691) & (~((v1689 - v1691) >> 31)));
  v1->timer = v1805;
  int v1693 = v1->timer;
  int * v1694 = v1->reg_ready;
  int v1695 = v1694[18];
  int v1808 = v1695 + ((v1693 - v1695) & (~((v1693 - v1695) >> 31)));
  v1->timer = v1808;
  int v1697 = v1->timer;
  int * v1698 = v1->reg_ready;
  int v1699 = v1698[19];
  int v1811 = v1699 + ((v1697 - v1699) & (~((v1697 - v1699) >> 31)));
  v1->timer = v1811;
  int v1701 = v1->timer;
  int * v1702 = v1->reg_ready;
  int v1703 = v1702[20];
  int v1814 = v1703 + ((v1701 - v1703) & (~((v1701 - v1703) >> 31)));
  v1->timer = v1814;
  int v1705 = v1->timer;
  int * v1706 = v1->reg_ready;
  int v1707 = v1706[21];
  int v1817 = v1707 + ((v1705 - v1707) & (~((v1705 - v1707) >> 31)));
  v1->timer = v1817;
  int v1709 = v1->timer;
  int * v1710 = v1->reg_ready;
  int v1711 = v1710[22];
  int v1820 = v1711 + ((v1709 - v1711) & (~((v1709 - v1711) >> 31)));
  v1->timer = v1820;
  int v1713 = v1->timer;
  int * v1714 = v1->reg_ready;
  int v1715 = v1714[23];
  int v1823 = v1715 + ((v1713 - v1715) & (~((v1713 - v1715) >> 31)));
  v1->timer = v1823;
  int v1717 = v1->timer;
  int * v1718 = v1->reg_ready;
  int v1719 = v1718[24];
  int v1826 = v1719 + ((v1717 - v1719) & (~((v1717 - v1719) >> 31)));
  v1->timer = v1826;
  int v1721 = v1->timer;
  int * v1722 = v1->reg_ready;
  int v1723 = v1722[25];
  int v1829 = v1723 + ((v1721 - v1723) & (~((v1721 - v1723) >> 31)));
  v1->timer = v1829;
  int v1725 = v1->timer;
  int * v1726 = v1->reg_ready;
  int v1727 = v1726[26];
  int v1832 = v1727 + ((v1725 - v1727) & (~((v1725 - v1727) >> 31)));
  v1->timer = v1832;
  int v1729 = v1->timer;
  int * v1730 = v1->reg_ready;
  int v1731 = v1730[27];
  int v1835 = v1731 + ((v1729 - v1731) & (~((v1729 - v1731) >> 31)));
  v1->timer = v1835;
  int v1733 = v1->timer;
  int * v1734 = v1->reg_ready;
  int v1735 = v1734[28];
  int v1838 = v1735 + ((v1733 - v1735) & (~((v1733 - v1735) >> 31)));
  v1->timer = v1838;
  int v1737 = v1->timer;
  int * v1738 = v1->reg_ready;
  int v1739 = v1738[29];
  int v1841 = v1739 + ((v1737 - v1739) & (~((v1737 - v1739) >> 31)));
  v1->timer = v1841;
  int v1741 = v1->timer;
  int * v1742 = v1->reg_ready;
  int v1743 = v1742[30];
  int v1844 = v1743 + ((v1741 - v1743) & (~((v1741 - v1743) >> 31)));
  v1->timer = v1844;
  int v1745 = v1->timer;
  int * v1746 = v1->reg_ready;
  int v1747 = v1746[31];
  int v1847 = v1747 + ((v1745 - v1747) & (~((v1745 - v1747) >> 31)));
  v1->timer = v1847;
  return v1;
}

struct StateT * slot_10(struct StateT * v739) {
  int v740 = v739->timer;
  int v751 = v740 + 1;
  v739->timer = v751;
  int * v742 = v739->reg_ready;
  int v743 = v742[10];
  int * v744 = v739->regs;
  int v745 = v744[10];
  int v755 = (v743 + ((v740 - v743) & (~((v740 - v743) >> 31)))) + 1;
  v742[10] = v755;
  int * v747 = v739->regs;
  int v757 = v745 << 29;
  v747[10] = v757;
  struct StateT * v749 = slot_12(v739);
  return v749;
}

struct StateT * slot_1(struct StateT * v23) {
  int v24 = v23->timer;
  int v32 = v24 + 1;
  v23->timer = v32;
  int * v26 = v23->reg_ready;
  v26[11] = v32;
  int * v28 = v23->regs;
  v28[11] = 0;
  struct StateT * v30 = slot_2(v23);
  return v30;
}

struct StateT * slot_8(struct StateT * v522) {
  int * v523 = v522->regs;
  int v524 = v523[10];
  int v525 = v523[11];
  bool v633 = (v524 ^ -2147483648) >= (v525 ^ -2147483648);
  struct StateT * v628;
  if (v633) {
    int v526 = v522->timer;
    int v634 = v526 + 15;
    v522->timer = v634;
    int * v528 = v522->reg_ready;
    int v529 = v522->timer;
    v528[0] = v529;
    int * v531 = v522->reg_ready;
    int v532 = v522->timer;
    v531[1] = v532;
    int * v534 = v522->reg_ready;
    int v535 = v522->timer;
    v534[2] = v535;
    int * v537 = v522->reg_ready;
    int v538 = v522->timer;
    v537[3] = v538;
    int * v540 = v522->reg_ready;
    int v541 = v522->timer;
    v540[4] = v541;
    int * v543 = v522->reg_ready;
    int v544 = v522->timer;
    v543[5] = v544;
    int * v546 = v522->reg_ready;
    int v547 = v522->timer;
    v546[6] = v547;
    int * v549 = v522->reg_ready;
    int v550 = v522->timer;
    v549[7] = v550;
    int * v552 = v522->reg_ready;
    int v553 = v522->timer;
    v552[8] = v553;
    int * v555 = v522->reg_ready;
    int v556 = v522->timer;
    v555[9] = v556;
    int * v558 = v522->reg_ready;
    int v559 = v522->timer;
    v558[10] = v559;
    int * v561 = v522->reg_ready;
    int v562 = v522->timer;
    v561[11] = v562;
    int * v564 = v522->reg_ready;
    int v565 = v522->timer;
    v564[12] = v565;
    int * v567 = v522->reg_ready;
    int v568 = v522->timer;
    v567[13] = v568;
    int * v570 = v522->reg_ready;
    int v571 = v522->timer;
    v570[14] = v571;
    int * v573 = v522->reg_ready;
    int v574 = v522->timer;
    v573[15] = v574;
    int * v576 = v522->reg_ready;
    int v577 = v522->timer;
    v576[16] = v577;
    int * v579 = v522->reg_ready;
    int v580 = v522->timer;
    v579[17] = v580;
    int * v582 = v522->reg_ready;
    int v583 = v522->timer;
    v582[18] = v583;
    int * v585 = v522->reg_ready;
    int v586 = v522->timer;
    v585[19] = v586;
    int * v588 = v522->reg_ready;
    int v589 = v522->timer;
    v588[20] = v589;
    int * v591 = v522->reg_ready;
    int v592 = v522->timer;
    v591[21] = v592;
    int * v594 = v522->reg_ready;
    int v595 = v522->timer;
    v594[22] = v595;
    int * v597 = v522->reg_ready;
    int v598 = v522->timer;
    v597[23] = v598;
    int * v600 = v522->reg_ready;
    int v601 = v522->timer;
    v600[24] = v601;
    int * v603 = v522->reg_ready;
    int v604 = v522->timer;
    v603[25] = v604;
    int * v606 = v522->reg_ready;
    int v607 = v522->timer;
    v606[26] = v607;
    int * v609 = v522->reg_ready;
    int v610 = v522->timer;
    v609[27] = v610;
    int * v612 = v522->reg_ready;
    int v613 = v522->timer;
    v612[28] = v613;
    int * v615 = v522->reg_ready;
    int v616 = v522->timer;
    v615[29] = v616;
    int * v618 = v522->reg_ready;
    int v619 = v522->timer;
    v618[30] = v619;
    int * v621 = v522->reg_ready;
    int v622 = v522->timer;
    v621[31] = v622;
    struct StateT * v624 = slot_21(v522);
    v628 = v624;
  } else {
    struct StateT * v626 = slot_10(v522);
    v628 = v626;
  }
  return v628;
}

struct StateT * slot_19(struct StateT * v1273) {
  int v1274 = v1273->timer;
  int v1287 = v1274 + 1;
  v1273->timer = v1287;
  int * v1276 = v1273->reg_ready;
  int v1277 = v1276[11];
  int * v1278 = v1273->regs;
  int v1279 = v1278[11];
  int v1280 = v1276[10];
  int v1281 = v1278[10];
  int v1292 = (v1280 + (((v1277 + ((v1274 - v1277) & (~((v1274 - v1277) >> 31)))) - v1280) & (~(((v1277 + ((v1274 - v1277) & (~((v1274 - v1277) >> 31)))) - v1280) >> 31)))) + 1;
  v1276[10] = v1292;
  int * v1283 = v1273->regs;
  int v1294 = v1279 & v1281;
  v1283[10] = v1294;
  struct StateT * v1285 = slot_20(v1273);
  return v1285;
}

struct StateT * slot_4(struct StateT * v84) {
  int v85 = v84->timer;
  int v93 = v85 + 1;
  v84->timer = v93;
  int * v87 = v84->reg_ready;
  v87[11] = v93;
  int * v89 = v84->regs;
  v89[11] = 0;
  struct StateT * v91 = slot_5(v84);
  return v91;
}

struct StateT * slot_13(struct StateT * v776) {
  int v777 = v776->timer;
  int v788 = v777 + 1;
  v776->timer = v788;
  int * v779 = v776->reg_ready;
  int v780 = v779[11];
  int * v781 = v776->regs;
  int v782 = v781[11];
  int v792 = (v780 + ((v777 - v780) & (~((v777 - v780) >> 31)))) + 1;
  v779[11] = v792;
  int * v784 = v776->regs;
  int v794 = v782 + 4;
  v784[11] = v794;
  struct StateT * v786 = slot_14(v776);
  return v786;
}

struct StateT * slot_15(struct StateT * v813) {
  int v814 = v813->timer;
  int v825 = v814 + 1;
  v813->timer = v825;
  int * v816 = v813->reg_ready;
  int v817 = v816[10];
  int * v818 = v813->regs;
  int v819 = v818[10];
  int v829 = (v817 + ((v814 - v817) & (~((v814 - v817) >> 31)))) + 1;
  v816[10] = v829;
  int * v821 = v813->regs;
  int v831 = (int)((unsigned int)v819 >> 26);
  v821[10] = v831;
  struct StateT * v823 = slot_16(v813);
  return v823;
}

struct StateT * slot_18(struct StateT * v1065) {
  int v1066 = v1065->timer;
  int v1178 = v1066 + 1;
  v1065->timer = v1178;
  int * v1068 = v1065->reg_ready;
  int v1069 = v1068[12];
  int * v1070 = v1065->regs;
  int v1071 = v1070[12];
  int * v1072 = v1065->cache_tags;
  int v1183 = (((int)((unsigned int)((int)((unsigned int)(v1071 + 68) >> 2)) >> 1)) & 1) * 2;
  int v1073 = v1072[v1183];
  int v1184 = ((((int)((unsigned int)((int)((unsigned int)(v1071 + 68) >> 2)) >> 1)) & 1) * 2) + 1;
  int v1074 = v1072[v1184];
  int v1185 = 4 + ((((int)((unsigned int)((int)((unsigned int)(v1071 + 68) >> 2)) >> 1)) & 3) * 2);
  int v1075 = v1072[v1185];
  int v1186 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v1071 + 68) >> 2)) >> 1)) & 3) * 2)) + 1;
  int v1076 = v1072[v1186];
  int * v1077 = v1065->cache_vals;
  bool v1187 = !(((~(((v1073 ^ ((int)((unsigned int)((int)((unsigned int)(v1071 + 68) >> 2)) >> 1))) | (-(v1073 ^ ((int)((unsigned int)((int)((unsigned int)(v1071 + 68) >> 2)) >> 1))))) >> 31)) | (~(((v1074 ^ ((int)((unsigned int)((int)((unsigned int)(v1071 + 68) >> 2)) >> 1))) | (-(v1074 ^ ((int)((unsigned int)((int)((unsigned int)(v1071 + 68) >> 2)) >> 1))))) >> 31))) == 0);
  int v1170;
  if (v1187) {
    int * v1078 = v1065->cache_age;
    int v1189 = ((((int)((unsigned int)((int)((unsigned int)(v1071 + 68) >> 2)) >> 1)) & 1) * 2) + ((~(((v1074 ^ ((int)((unsigned int)((int)((unsigned int)(v1071 + 68) >> 2)) >> 1))) | (-(v1074 ^ ((int)((unsigned int)((int)((unsigned int)(v1071 + 68) >> 2)) >> 1))))) >> 31)) & 1);
    int v1079 = v1078[v1189];
    int v1080 = v1078[v1183];
    int v1190 = v1080 + ((int)((unsigned int)(v1080 - v1079) >> 31));
    v1078[v1183] = v1190;
    int * v1082 = v1065->cache_age;
    int v1083 = v1082[v1184];
    int v1192 = v1083 + ((int)((unsigned int)(v1083 - v1079) >> 31));
    v1082[v1184] = v1192;
    int * v1085 = v1065->cache_age;
    v1085[v1189] = 0;
    v1170 = v1189;
  } else {
    int * v1088 = v1065->cache_age;
    int v1196 = (((int)((unsigned int)((int)((unsigned int)(v1071 + 68) >> 2)) >> 1)) & 1) * 2;
    int v1089 = v1088[v1196];
    int * v1090 = v1065->cache_tags;
    int v1091 = v1090[v1196];
    int v1092 = v1088[v1184];
    int v1093 = v1090[v1184];
    bool v1198 = !(((~(((v1075 ^ ((int)((unsigned int)((int)((unsigned int)(v1071 + 68) >> 2)) >> 1))) | (-(v1075 ^ ((int)((unsigned int)((int)((unsigned int)(v1071 + 68) >> 2)) >> 1))))) >> 31)) | (~(((v1076 ^ ((int)((unsigned int)((int)((unsigned int)(v1071 + 68) >> 2)) >> 1))) | (-(v1076 ^ ((int)((unsigned int)((int)((unsigned int)(v1071 + 68) >> 2)) >> 1))))) >> 31))) == 0);
    int v1147;
    if (v1198) {
      int * v1094 = v1065->cache_age;
      int v1200 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v1071 + 68) >> 2)) >> 1)) & 3) * 2)) + ((~(((v1076 ^ ((int)((unsigned int)((int)((unsigned int)(v1071 + 68) >> 2)) >> 1))) | (-(v1076 ^ ((int)((unsigned int)((int)((unsigned int)(v1071 + 68) >> 2)) >> 1))))) >> 31)) & 1);
      int v1095 = v1094[v1200];
      int v1096 = v1094[v1185];
      int v1201 = v1096 + ((int)((unsigned int)(v1096 - v1095) >> 31));
      v1094[v1185] = v1201;
      int * v1098 = v1065->cache_age;
      int v1099 = v1098[v1186];
      int v1203 = v1099 + ((int)((unsigned int)(v1099 - v1095) >> 31));
      v1098[v1186] = v1203;
      int * v1101 = v1065->cache_age;
      v1101[v1200] = 0;
      v1147 = v1200;
    } else {
      int * v1104 = v1065->cache_age;
      int v1207 = 4 + ((((int)((unsigned int)((int)((unsigned int)(v1071 + 68) >> 2)) >> 1)) & 3) * 2);
      int v1105 = v1104[v1207];
      int * v1106 = v1065->cache_tags;
      int v1107 = v1106[v1207];
      int v1108 = v1104[v1186];
      int v1109 = v1106[v1186];
      int * v1110 = v1065->cache_dirty;
      int v1210 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v1071 + 68) >> 2)) >> 1)) & 3) * 2)) + ((((v1105 + ((~(((v1107 ^ -1) | (-(v1107 ^ -1))) >> 31)) & 2)) - (v1108 + ((~(((v1109 ^ -1) | (-(v1109 ^ -1))) >> 31)) & 2))) >> 31) & 1);
      int v1111 = v1110[v1210];
      bool v1211 = !(v1111 == 0);
      if (v1211) {
        int * v1112 = v1065->cache_tags;
        int v1113 = v1112[v1210];
        int * v1114 = v1065->cache_vals;
        int v1214 = ((4 + ((((int)((unsigned int)((int)((unsigned int)(v1071 + 68) >> 2)) >> 1)) & 3) * 2)) + ((((v1105 + ((~(((v1107 ^ -1) | (-(v1107 ^ -1))) >> 31)) & 2)) - (v1108 + ((~(((v1109 ^ -1) | (-(v1109 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
        int v1115 = v1114[v1214];
        int v1215 = (((4 + ((((int)((unsigned int)((int)((unsigned int)(v1071 + 68) >> 2)) >> 1)) & 3) * 2)) + ((((v1105 + ((~(((v1107 ^ -1) | (-(v1107 ^ -1))) >> 31)) & 2)) - (v1108 + ((~(((v1109 ^ -1) | (-(v1109 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
        int v1116 = v1114[v1215];
        int * v1117 = v1065->mem;
        int v1217 = v1113 * 2;
        v1117[v1217] = v1115;
        int * v1119 = v1065->mem;
        int v1220 = (v1113 * 2) + 1;
        v1119[v1220] = v1116;
        ;
      } else {
        ;
      }
      int * v1124 = v1065->mem;
      int v1225 = ((int)((unsigned int)((int)((unsigned int)(v1071 + 68) >> 2)) >> 1)) * 2;
      int v1125 = v1124[v1225];
      int v1226 = (((int)((unsigned int)((int)((unsigned int)(v1071 + 68) >> 2)) >> 1)) * 2) + 1;
      int v1126 = v1124[v1226];
      int * v1127 = v1065->cache_vals;
      int v1228 = ((4 + ((((int)((unsigned int)((int)((unsigned int)(v1071 + 68) >> 2)) >> 1)) & 3) * 2)) + ((((v1105 + ((~(((v1107 ^ -1) | (-(v1107 ^ -1))) >> 31)) & 2)) - (v1108 + ((~(((v1109 ^ -1) | (-(v1109 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
      v1127[v1228] = v1125;
      int * v1129 = v1065->cache_vals;
      int v1231 = (((4 + ((((int)((unsigned int)((int)((unsigned int)(v1071 + 68) >> 2)) >> 1)) & 3) * 2)) + ((((v1105 + ((~(((v1107 ^ -1) | (-(v1107 ^ -1))) >> 31)) & 2)) - (v1108 + ((~(((v1109 ^ -1) | (-(v1109 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
      v1129[v1231] = v1126;
      int * v1131 = v1065->cache_tags;
      int v1234 = (int)((unsigned int)((int)((unsigned int)(v1071 + 68) >> 2)) >> 1);
      v1131[v1210] = v1234;
      int * v1133 = v1065->cache_dirty;
      v1133[v1210] = 0;
      int * v1135 = v1065->cache_age;
      v1135[v1210] = 1;
      int * v1137 = v1065->cache_age;
      int v1138 = v1137[v1210];
      int v1139 = v1137[v1185];
      int v1240 = v1139 + ((int)((unsigned int)(v1139 - v1138) >> 31));
      v1137[v1185] = v1240;
      int * v1141 = v1065->cache_age;
      int v1142 = v1141[v1186];
      int v1242 = v1142 + ((int)((unsigned int)(v1142 - v1138) >> 31));
      v1141[v1186] = v1242;
      int * v1144 = v1065->cache_age;
      v1144[v1210] = 0;
      v1147 = v1210;
    }
    int * v1148 = v1065->cache_vals;
    int v1245 = v1147 * 2;
    int v1149 = v1148[v1245];
    int v1246 = (v1147 * 2) + 1;
    int v1150 = v1148[v1246];
    int v1247 = (((((int)((unsigned int)((int)((unsigned int)(v1071 + 68) >> 2)) >> 1)) & 1) * 2) + ((((v1089 + ((~(((v1091 ^ -1) | (-(v1091 ^ -1))) >> 31)) & 2)) - (v1092 + ((~(((v1093 ^ -1) | (-(v1093 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
    v1148[v1247] = v1149;
    int * v1152 = v1065->cache_vals;
    int v1250 = ((((((int)((unsigned int)((int)((unsigned int)(v1071 + 68) >> 2)) >> 1)) & 1) * 2) + ((((v1089 + ((~(((v1091 ^ -1) | (-(v1091 ^ -1))) >> 31)) & 2)) - (v1092 + ((~(((v1093 ^ -1) | (-(v1093 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
    v1152[v1250] = v1150;
    int * v1154 = v1065->cache_tags;
    int v1253 = ((((int)((unsigned int)((int)((unsigned int)(v1071 + 68) >> 2)) >> 1)) & 1) * 2) + ((((v1089 + ((~(((v1091 ^ -1) | (-(v1091 ^ -1))) >> 31)) & 2)) - (v1092 + ((~(((v1093 ^ -1) | (-(v1093 ^ -1))) >> 31)) & 2))) >> 31) & 1);
    int v1254 = (int)((unsigned int)((int)((unsigned int)(v1071 + 68) >> 2)) >> 1);
    v1154[v1253] = v1254;
    int * v1156 = v1065->cache_dirty;
    v1156[v1253] = 0;
    int * v1158 = v1065->cache_age;
    v1158[v1253] = 1;
    int * v1160 = v1065->cache_age;
    int v1161 = v1160[v1253];
    int v1162 = v1160[v1183];
    int v1260 = v1162 + ((int)((unsigned int)(v1162 - v1161) >> 31));
    v1160[v1183] = v1260;
    int * v1164 = v1065->cache_age;
    int v1165 = v1164[v1184];
    int v1262 = v1165 + ((int)((unsigned int)(v1165 - v1161) >> 31));
    v1164[v1184] = v1262;
    int * v1167 = v1065->cache_age;
    v1167[v1253] = 0;
    v1170 = v1253;
  }
  int v1265 = (v1170 * 2) + (((int)((unsigned int)(v1071 + 68) >> 2)) & 1);
  int v1171 = v1077[v1265];
  int * v1172 = v1065->reg_ready;
  int v1268 = ((v1069 + ((v1066 - v1069) & (~((v1066 - v1069) >> 31)))) + 1) + ((100 ^ (((~(((v1075 ^ ((int)((unsigned int)((int)((unsigned int)(v1071 + 68) >> 2)) >> 1))) | (-(v1075 ^ ((int)((unsigned int)((int)((unsigned int)(v1071 + 68) >> 2)) >> 1))))) >> 31)) | (~(((v1076 ^ ((int)((unsigned int)((int)((unsigned int)(v1071 + 68) >> 2)) >> 1))) | (-(v1076 ^ ((int)((unsigned int)((int)((unsigned int)(v1071 + 68) >> 2)) >> 1))))) >> 31))) & 104)) ^ (((~(((v1073 ^ ((int)((unsigned int)((int)((unsigned int)(v1071 + 68) >> 2)) >> 1))) | (-(v1073 ^ ((int)((unsigned int)((int)((unsigned int)(v1071 + 68) >> 2)) >> 1))))) >> 31)) | (~(((v1074 ^ ((int)((unsigned int)((int)((unsigned int)(v1071 + 68) >> 2)) >> 1))) | (-(v1074 ^ ((int)((unsigned int)((int)((unsigned int)(v1071 + 68) >> 2)) >> 1))))) >> 31))) & (1 ^ (100 ^ (((~(((v1075 ^ ((int)((unsigned int)((int)((unsigned int)(v1071 + 68) >> 2)) >> 1))) | (-(v1075 ^ ((int)((unsigned int)((int)((unsigned int)(v1071 + 68) >> 2)) >> 1))))) >> 31)) | (~(((v1076 ^ ((int)((unsigned int)((int)((unsigned int)(v1071 + 68) >> 2)) >> 1))) | (-(v1076 ^ ((int)((unsigned int)((int)((unsigned int)(v1071 + 68) >> 2)) >> 1))))) >> 31))) & 104)))));
  v1172[11] = v1268;
  int * v1174 = v1065->regs;
  v1174[11] = v1171;
  struct StateT * v1176 = slot_19(v1065);
  return v1176;
}

struct StateT * slot_0(struct StateT * v2) {
  int v3 = v2->timer;
  int v14 = v3 + 1;
  v2->timer = v14;
  int * v5 = v2->reg_ready;
  int v6 = v5[10];
  int * v7 = v2->regs;
  int v8 = v7[10];
  int v18 = (v6 + ((v3 - v6) & (~((v3 - v6) >> 31)))) + 1;
  v5[10] = v18;
  int * v10 = v2->regs;
  int v20 = v8 << 2;
  v10[10] = v20;
  struct StateT * v12 = slot_1(v2);
  return v12;
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