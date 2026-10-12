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

struct StateT * slot_6(struct StateT * v305);
struct StateT * slot_5(struct StateT * v90);
struct StateT * slot_2(struct StateT * v34);
struct StateT * slot_7(struct StateT * v326);
struct StateT * slot_3(struct StateT * v50);
struct StateT * snippet(struct StateT * v0);
struct StateT * slot_10(struct StateT * v610);
struct StateT * slot_1(struct StateT * v18);
struct StateT * slot_8(struct StateT * v541);
struct StateT * slot_4(struct StateT * v58);
struct StateT * slot_9(struct StateT * v602);
struct StateT * slot_0(struct StateT * v2);
struct StateT * slot_6(struct StateT * v305) {
  int v306 = v305->timer;
  int v317 = v306 + 1;
  v305->timer = v317;
  int * v308 = v305->reg_ready;
  int v309 = v308[11];
  int * v310 = v305->regs;
  int v311 = v310[11];
  int v321 = (v309 + ((v306 - v309) & (~((v306 - v309) >> 31)))) + 1;
  v308[11] = v321;
  int * v313 = v305->regs;
  int v323 = v311 << 2;
  v313[11] = v323;
  struct StateT * v315 = slot_7(v305);
  return v315;
}

struct StateT * slot_5(struct StateT * v90) {
  int * v91 = v90->saved_regs;
  int * v92 = v90->regs;
  int v93 = v92[11];
  v91[11] = v93;
  int v95 = v90->timer;
  int v211 = v95 + 1;
  v90->timer = v211;
  int * v97 = v90->reg_ready;
  int v98 = v97[5];
  int * v99 = v90->regs;
  int v100 = v99[5];
  int * v101 = v90->cache_tags;
  int v216 = (((int)((unsigned int)((int)((unsigned int)v100 >> 2)) >> 1)) & 1) * 2;
  int v102 = v101[v216];
  int v217 = ((((int)((unsigned int)((int)((unsigned int)v100 >> 2)) >> 1)) & 1) * 2) + 1;
  int v103 = v101[v217];
  int v218 = 4 + ((((int)((unsigned int)((int)((unsigned int)v100 >> 2)) >> 1)) & 3) * 2);
  int v104 = v101[v218];
  int v219 = (4 + ((((int)((unsigned int)((int)((unsigned int)v100 >> 2)) >> 1)) & 3) * 2)) + 1;
  int v105 = v101[v219];
  int * v106 = v90->cache_vals;
  bool v220 = !(((~(((v102 ^ ((int)((unsigned int)((int)((unsigned int)v100 >> 2)) >> 1))) | (-(v102 ^ ((int)((unsigned int)((int)((unsigned int)v100 >> 2)) >> 1))))) >> 31)) | (~(((v103 ^ ((int)((unsigned int)((int)((unsigned int)v100 >> 2)) >> 1))) | (-(v103 ^ ((int)((unsigned int)((int)((unsigned int)v100 >> 2)) >> 1))))) >> 31))) == 0);
  int v199;
  if (v220) {
    int * v107 = v90->cache_age;
    int v222 = ((((int)((unsigned int)((int)((unsigned int)v100 >> 2)) >> 1)) & 1) * 2) + ((~(((v103 ^ ((int)((unsigned int)((int)((unsigned int)v100 >> 2)) >> 1))) | (-(v103 ^ ((int)((unsigned int)((int)((unsigned int)v100 >> 2)) >> 1))))) >> 31)) & 1);
    int v108 = v107[v222];
    int v109 = v107[v216];
    int v223 = v109 + ((int)((unsigned int)(v109 - v108) >> 31));
    v107[v216] = v223;
    int * v111 = v90->cache_age;
    int v112 = v111[v217];
    int v225 = v112 + ((int)((unsigned int)(v112 - v108) >> 31));
    v111[v217] = v225;
    int * v114 = v90->cache_age;
    v114[v222] = 0;
    v199 = v222;
  } else {
    int * v117 = v90->cache_age;
    int v229 = (((int)((unsigned int)((int)((unsigned int)v100 >> 2)) >> 1)) & 1) * 2;
    int v118 = v117[v229];
    int * v119 = v90->cache_tags;
    int v120 = v119[v229];
    int v121 = v117[v217];
    int v122 = v119[v217];
    bool v231 = !(((~(((v104 ^ ((int)((unsigned int)((int)((unsigned int)v100 >> 2)) >> 1))) | (-(v104 ^ ((int)((unsigned int)((int)((unsigned int)v100 >> 2)) >> 1))))) >> 31)) | (~(((v105 ^ ((int)((unsigned int)((int)((unsigned int)v100 >> 2)) >> 1))) | (-(v105 ^ ((int)((unsigned int)((int)((unsigned int)v100 >> 2)) >> 1))))) >> 31))) == 0);
    int v176;
    if (v231) {
      int * v123 = v90->cache_age;
      int v233 = (4 + ((((int)((unsigned int)((int)((unsigned int)v100 >> 2)) >> 1)) & 3) * 2)) + ((~(((v105 ^ ((int)((unsigned int)((int)((unsigned int)v100 >> 2)) >> 1))) | (-(v105 ^ ((int)((unsigned int)((int)((unsigned int)v100 >> 2)) >> 1))))) >> 31)) & 1);
      int v124 = v123[v233];
      int v125 = v123[v218];
      int v234 = v125 + ((int)((unsigned int)(v125 - v124) >> 31));
      v123[v218] = v234;
      int * v127 = v90->cache_age;
      int v128 = v127[v219];
      int v236 = v128 + ((int)((unsigned int)(v128 - v124) >> 31));
      v127[v219] = v236;
      int * v130 = v90->cache_age;
      v130[v233] = 0;
      v176 = v233;
    } else {
      int * v133 = v90->cache_age;
      int v240 = 4 + ((((int)((unsigned int)((int)((unsigned int)v100 >> 2)) >> 1)) & 3) * 2);
      int v134 = v133[v240];
      int * v135 = v90->cache_tags;
      int v136 = v135[v240];
      int v137 = v133[v219];
      int v138 = v135[v219];
      int * v139 = v90->cache_dirty;
      int v243 = (4 + ((((int)((unsigned int)((int)((unsigned int)v100 >> 2)) >> 1)) & 3) * 2)) + ((((v134 + ((~(((v136 ^ -1) | (-(v136 ^ -1))) >> 31)) & 2)) - (v137 + ((~(((v138 ^ -1) | (-(v138 ^ -1))) >> 31)) & 2))) >> 31) & 1);
      int v140 = v139[v243];
      bool v244 = !(v140 == 0);
      if (v244) {
        int * v141 = v90->cache_tags;
        int v142 = v141[v243];
        int * v143 = v90->cache_vals;
        int v247 = ((4 + ((((int)((unsigned int)((int)((unsigned int)v100 >> 2)) >> 1)) & 3) * 2)) + ((((v134 + ((~(((v136 ^ -1) | (-(v136 ^ -1))) >> 31)) & 2)) - (v137 + ((~(((v138 ^ -1) | (-(v138 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
        int v144 = v143[v247];
        int v248 = (((4 + ((((int)((unsigned int)((int)((unsigned int)v100 >> 2)) >> 1)) & 3) * 2)) + ((((v134 + ((~(((v136 ^ -1) | (-(v136 ^ -1))) >> 31)) & 2)) - (v137 + ((~(((v138 ^ -1) | (-(v138 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
        int v145 = v143[v248];
        int * v146 = v90->mem;
        int v250 = v142 * 2;
        v146[v250] = v144;
        int * v148 = v90->mem;
        int v253 = (v142 * 2) + 1;
        v148[v253] = v145;
        ;
      } else {
        ;
      }
      int * v153 = v90->mem;
      int v258 = ((int)((unsigned int)((int)((unsigned int)v100 >> 2)) >> 1)) * 2;
      int v154 = v153[v258];
      int v259 = (((int)((unsigned int)((int)((unsigned int)v100 >> 2)) >> 1)) * 2) + 1;
      int v155 = v153[v259];
      int * v156 = v90->cache_vals;
      int v261 = ((4 + ((((int)((unsigned int)((int)((unsigned int)v100 >> 2)) >> 1)) & 3) * 2)) + ((((v134 + ((~(((v136 ^ -1) | (-(v136 ^ -1))) >> 31)) & 2)) - (v137 + ((~(((v138 ^ -1) | (-(v138 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
      v156[v261] = v154;
      int * v158 = v90->cache_vals;
      int v264 = (((4 + ((((int)((unsigned int)((int)((unsigned int)v100 >> 2)) >> 1)) & 3) * 2)) + ((((v134 + ((~(((v136 ^ -1) | (-(v136 ^ -1))) >> 31)) & 2)) - (v137 + ((~(((v138 ^ -1) | (-(v138 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
      v158[v264] = v155;
      int * v160 = v90->cache_tags;
      int v267 = (int)((unsigned int)((int)((unsigned int)v100 >> 2)) >> 1);
      v160[v243] = v267;
      int * v162 = v90->cache_dirty;
      v162[v243] = 0;
      int * v164 = v90->cache_age;
      v164[v243] = 1;
      int * v166 = v90->cache_age;
      int v167 = v166[v243];
      int v168 = v166[v218];
      int v273 = v168 + ((int)((unsigned int)(v168 - v167) >> 31));
      v166[v218] = v273;
      int * v170 = v90->cache_age;
      int v171 = v170[v219];
      int v275 = v171 + ((int)((unsigned int)(v171 - v167) >> 31));
      v170[v219] = v275;
      int * v173 = v90->cache_age;
      v173[v243] = 0;
      v176 = v243;
    }
    int * v177 = v90->cache_vals;
    int v278 = v176 * 2;
    int v178 = v177[v278];
    int v279 = (v176 * 2) + 1;
    int v179 = v177[v279];
    int v280 = (((((int)((unsigned int)((int)((unsigned int)v100 >> 2)) >> 1)) & 1) * 2) + ((((v118 + ((~(((v120 ^ -1) | (-(v120 ^ -1))) >> 31)) & 2)) - (v121 + ((~(((v122 ^ -1) | (-(v122 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
    v177[v280] = v178;
    int * v181 = v90->cache_vals;
    int v283 = ((((((int)((unsigned int)((int)((unsigned int)v100 >> 2)) >> 1)) & 1) * 2) + ((((v118 + ((~(((v120 ^ -1) | (-(v120 ^ -1))) >> 31)) & 2)) - (v121 + ((~(((v122 ^ -1) | (-(v122 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
    v181[v283] = v179;
    int * v183 = v90->cache_tags;
    int v286 = ((((int)((unsigned int)((int)((unsigned int)v100 >> 2)) >> 1)) & 1) * 2) + ((((v118 + ((~(((v120 ^ -1) | (-(v120 ^ -1))) >> 31)) & 2)) - (v121 + ((~(((v122 ^ -1) | (-(v122 ^ -1))) >> 31)) & 2))) >> 31) & 1);
    int v287 = (int)((unsigned int)((int)((unsigned int)v100 >> 2)) >> 1);
    v183[v286] = v287;
    int * v185 = v90->cache_dirty;
    v185[v286] = 0;
    int * v187 = v90->cache_age;
    v187[v286] = 1;
    int * v189 = v90->cache_age;
    int v190 = v189[v286];
    int v191 = v189[v216];
    int v293 = v191 + ((int)((unsigned int)(v191 - v190) >> 31));
    v189[v216] = v293;
    int * v193 = v90->cache_age;
    int v194 = v193[v217];
    int v295 = v194 + ((int)((unsigned int)(v194 - v190) >> 31));
    v193[v217] = v295;
    int * v196 = v90->cache_age;
    v196[v286] = 0;
    v199 = v286;
  }
  int v298 = (v199 * 2) + (((int)((unsigned int)v100 >> 2)) & 1);
  int v200 = v106[v298];
  int * v201 = v90->reg_ready;
  int v300 = ((v98 + ((v95 - v98) & (~((v95 - v98) >> 31)))) + 1) + ((100 ^ (((~(((v104 ^ ((int)((unsigned int)((int)((unsigned int)v100 >> 2)) >> 1))) | (-(v104 ^ ((int)((unsigned int)((int)((unsigned int)v100 >> 2)) >> 1))))) >> 31)) | (~(((v105 ^ ((int)((unsigned int)((int)((unsigned int)v100 >> 2)) >> 1))) | (-(v105 ^ ((int)((unsigned int)((int)((unsigned int)v100 >> 2)) >> 1))))) >> 31))) & 104)) ^ (((~(((v102 ^ ((int)((unsigned int)((int)((unsigned int)v100 >> 2)) >> 1))) | (-(v102 ^ ((int)((unsigned int)((int)((unsigned int)v100 >> 2)) >> 1))))) >> 31)) | (~(((v103 ^ ((int)((unsigned int)((int)((unsigned int)v100 >> 2)) >> 1))) | (-(v103 ^ ((int)((unsigned int)((int)((unsigned int)v100 >> 2)) >> 1))))) >> 31))) & (1 ^ (100 ^ (((~(((v104 ^ ((int)((unsigned int)((int)((unsigned int)v100 >> 2)) >> 1))) | (-(v104 ^ ((int)((unsigned int)((int)((unsigned int)v100 >> 2)) >> 1))))) >> 31)) | (~(((v105 ^ ((int)((unsigned int)((int)((unsigned int)v100 >> 2)) >> 1))) | (-(v105 ^ ((int)((unsigned int)((int)((unsigned int)v100 >> 2)) >> 1))))) >> 31))) & 104)))));
  v201[11] = v300;
  int * v203 = v90->regs;
  v203[11] = v200;
  struct StateT * v205 = slot_6(v90);
  return v205;
}

struct StateT * slot_2(struct StateT * v34) {
  int v35 = v34->timer;
  int v43 = v35 + 1;
  v34->timer = v43;
  int * v37 = v34->reg_ready;
  v37[15] = v43;
  int * v39 = v34->regs;
  v39[15] = 80;
  struct StateT * v41 = slot_3(v34);
  return v41;
}

struct StateT * slot_7(struct StateT * v326) {
  int * v327 = v326->saved_regs;
  int * v328 = v326->regs;
  int v329 = v328[12];
  v327[12] = v329;
  int v331 = v326->timer;
  int v447 = v331 + 1;
  v326->timer = v447;
  int * v333 = v326->reg_ready;
  int v334 = v333[11];
  int * v335 = v326->regs;
  int v336 = v335[11];
  int * v337 = v326->cache_tags;
  int v452 = (((int)((unsigned int)((int)((unsigned int)v336 >> 2)) >> 1)) & 1) * 2;
  int v338 = v337[v452];
  int v453 = ((((int)((unsigned int)((int)((unsigned int)v336 >> 2)) >> 1)) & 1) * 2) + 1;
  int v339 = v337[v453];
  int v454 = 4 + ((((int)((unsigned int)((int)((unsigned int)v336 >> 2)) >> 1)) & 3) * 2);
  int v340 = v337[v454];
  int v455 = (4 + ((((int)((unsigned int)((int)((unsigned int)v336 >> 2)) >> 1)) & 3) * 2)) + 1;
  int v341 = v337[v455];
  int * v342 = v326->cache_vals;
  bool v456 = !(((~(((v338 ^ ((int)((unsigned int)((int)((unsigned int)v336 >> 2)) >> 1))) | (-(v338 ^ ((int)((unsigned int)((int)((unsigned int)v336 >> 2)) >> 1))))) >> 31)) | (~(((v339 ^ ((int)((unsigned int)((int)((unsigned int)v336 >> 2)) >> 1))) | (-(v339 ^ ((int)((unsigned int)((int)((unsigned int)v336 >> 2)) >> 1))))) >> 31))) == 0);
  int v435;
  if (v456) {
    int * v343 = v326->cache_age;
    int v458 = ((((int)((unsigned int)((int)((unsigned int)v336 >> 2)) >> 1)) & 1) * 2) + ((~(((v339 ^ ((int)((unsigned int)((int)((unsigned int)v336 >> 2)) >> 1))) | (-(v339 ^ ((int)((unsigned int)((int)((unsigned int)v336 >> 2)) >> 1))))) >> 31)) & 1);
    int v344 = v343[v458];
    int v345 = v343[v452];
    int v459 = v345 + ((int)((unsigned int)(v345 - v344) >> 31));
    v343[v452] = v459;
    int * v347 = v326->cache_age;
    int v348 = v347[v453];
    int v461 = v348 + ((int)((unsigned int)(v348 - v344) >> 31));
    v347[v453] = v461;
    int * v350 = v326->cache_age;
    v350[v458] = 0;
    v435 = v458;
  } else {
    int * v353 = v326->cache_age;
    int v465 = (((int)((unsigned int)((int)((unsigned int)v336 >> 2)) >> 1)) & 1) * 2;
    int v354 = v353[v465];
    int * v355 = v326->cache_tags;
    int v356 = v355[v465];
    int v357 = v353[v453];
    int v358 = v355[v453];
    bool v467 = !(((~(((v340 ^ ((int)((unsigned int)((int)((unsigned int)v336 >> 2)) >> 1))) | (-(v340 ^ ((int)((unsigned int)((int)((unsigned int)v336 >> 2)) >> 1))))) >> 31)) | (~(((v341 ^ ((int)((unsigned int)((int)((unsigned int)v336 >> 2)) >> 1))) | (-(v341 ^ ((int)((unsigned int)((int)((unsigned int)v336 >> 2)) >> 1))))) >> 31))) == 0);
    int v412;
    if (v467) {
      int * v359 = v326->cache_age;
      int v469 = (4 + ((((int)((unsigned int)((int)((unsigned int)v336 >> 2)) >> 1)) & 3) * 2)) + ((~(((v341 ^ ((int)((unsigned int)((int)((unsigned int)v336 >> 2)) >> 1))) | (-(v341 ^ ((int)((unsigned int)((int)((unsigned int)v336 >> 2)) >> 1))))) >> 31)) & 1);
      int v360 = v359[v469];
      int v361 = v359[v454];
      int v470 = v361 + ((int)((unsigned int)(v361 - v360) >> 31));
      v359[v454] = v470;
      int * v363 = v326->cache_age;
      int v364 = v363[v455];
      int v472 = v364 + ((int)((unsigned int)(v364 - v360) >> 31));
      v363[v455] = v472;
      int * v366 = v326->cache_age;
      v366[v469] = 0;
      v412 = v469;
    } else {
      int * v369 = v326->cache_age;
      int v476 = 4 + ((((int)((unsigned int)((int)((unsigned int)v336 >> 2)) >> 1)) & 3) * 2);
      int v370 = v369[v476];
      int * v371 = v326->cache_tags;
      int v372 = v371[v476];
      int v373 = v369[v455];
      int v374 = v371[v455];
      int * v375 = v326->cache_dirty;
      int v479 = (4 + ((((int)((unsigned int)((int)((unsigned int)v336 >> 2)) >> 1)) & 3) * 2)) + ((((v370 + ((~(((v372 ^ -1) | (-(v372 ^ -1))) >> 31)) & 2)) - (v373 + ((~(((v374 ^ -1) | (-(v374 ^ -1))) >> 31)) & 2))) >> 31) & 1);
      int v376 = v375[v479];
      bool v480 = !(v376 == 0);
      if (v480) {
        int * v377 = v326->cache_tags;
        int v378 = v377[v479];
        int * v379 = v326->cache_vals;
        int v483 = ((4 + ((((int)((unsigned int)((int)((unsigned int)v336 >> 2)) >> 1)) & 3) * 2)) + ((((v370 + ((~(((v372 ^ -1) | (-(v372 ^ -1))) >> 31)) & 2)) - (v373 + ((~(((v374 ^ -1) | (-(v374 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
        int v380 = v379[v483];
        int v484 = (((4 + ((((int)((unsigned int)((int)((unsigned int)v336 >> 2)) >> 1)) & 3) * 2)) + ((((v370 + ((~(((v372 ^ -1) | (-(v372 ^ -1))) >> 31)) & 2)) - (v373 + ((~(((v374 ^ -1) | (-(v374 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
        int v381 = v379[v484];
        int * v382 = v326->mem;
        int v486 = v378 * 2;
        v382[v486] = v380;
        int * v384 = v326->mem;
        int v489 = (v378 * 2) + 1;
        v384[v489] = v381;
        ;
      } else {
        ;
      }
      int * v389 = v326->mem;
      int v494 = ((int)((unsigned int)((int)((unsigned int)v336 >> 2)) >> 1)) * 2;
      int v390 = v389[v494];
      int v495 = (((int)((unsigned int)((int)((unsigned int)v336 >> 2)) >> 1)) * 2) + 1;
      int v391 = v389[v495];
      int * v392 = v326->cache_vals;
      int v497 = ((4 + ((((int)((unsigned int)((int)((unsigned int)v336 >> 2)) >> 1)) & 3) * 2)) + ((((v370 + ((~(((v372 ^ -1) | (-(v372 ^ -1))) >> 31)) & 2)) - (v373 + ((~(((v374 ^ -1) | (-(v374 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
      v392[v497] = v390;
      int * v394 = v326->cache_vals;
      int v500 = (((4 + ((((int)((unsigned int)((int)((unsigned int)v336 >> 2)) >> 1)) & 3) * 2)) + ((((v370 + ((~(((v372 ^ -1) | (-(v372 ^ -1))) >> 31)) & 2)) - (v373 + ((~(((v374 ^ -1) | (-(v374 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
      v394[v500] = v391;
      int * v396 = v326->cache_tags;
      int v503 = (int)((unsigned int)((int)((unsigned int)v336 >> 2)) >> 1);
      v396[v479] = v503;
      int * v398 = v326->cache_dirty;
      v398[v479] = 0;
      int * v400 = v326->cache_age;
      v400[v479] = 1;
      int * v402 = v326->cache_age;
      int v403 = v402[v479];
      int v404 = v402[v454];
      int v509 = v404 + ((int)((unsigned int)(v404 - v403) >> 31));
      v402[v454] = v509;
      int * v406 = v326->cache_age;
      int v407 = v406[v455];
      int v511 = v407 + ((int)((unsigned int)(v407 - v403) >> 31));
      v406[v455] = v511;
      int * v409 = v326->cache_age;
      v409[v479] = 0;
      v412 = v479;
    }
    int * v413 = v326->cache_vals;
    int v514 = v412 * 2;
    int v414 = v413[v514];
    int v515 = (v412 * 2) + 1;
    int v415 = v413[v515];
    int v516 = (((((int)((unsigned int)((int)((unsigned int)v336 >> 2)) >> 1)) & 1) * 2) + ((((v354 + ((~(((v356 ^ -1) | (-(v356 ^ -1))) >> 31)) & 2)) - (v357 + ((~(((v358 ^ -1) | (-(v358 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
    v413[v516] = v414;
    int * v417 = v326->cache_vals;
    int v519 = ((((((int)((unsigned int)((int)((unsigned int)v336 >> 2)) >> 1)) & 1) * 2) + ((((v354 + ((~(((v356 ^ -1) | (-(v356 ^ -1))) >> 31)) & 2)) - (v357 + ((~(((v358 ^ -1) | (-(v358 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
    v417[v519] = v415;
    int * v419 = v326->cache_tags;
    int v522 = ((((int)((unsigned int)((int)((unsigned int)v336 >> 2)) >> 1)) & 1) * 2) + ((((v354 + ((~(((v356 ^ -1) | (-(v356 ^ -1))) >> 31)) & 2)) - (v357 + ((~(((v358 ^ -1) | (-(v358 ^ -1))) >> 31)) & 2))) >> 31) & 1);
    int v523 = (int)((unsigned int)((int)((unsigned int)v336 >> 2)) >> 1);
    v419[v522] = v523;
    int * v421 = v326->cache_dirty;
    v421[v522] = 0;
    int * v423 = v326->cache_age;
    v423[v522] = 1;
    int * v425 = v326->cache_age;
    int v426 = v425[v522];
    int v427 = v425[v452];
    int v529 = v427 + ((int)((unsigned int)(v427 - v426) >> 31));
    v425[v452] = v529;
    int * v429 = v326->cache_age;
    int v430 = v429[v453];
    int v531 = v430 + ((int)((unsigned int)(v430 - v426) >> 31));
    v429[v453] = v531;
    int * v432 = v326->cache_age;
    v432[v522] = 0;
    v435 = v522;
  }
  int v534 = (v435 * 2) + (((int)((unsigned int)v336 >> 2)) & 1);
  int v436 = v342[v534];
  int * v437 = v326->reg_ready;
  int v536 = ((v334 + ((v331 - v334) & (~((v331 - v334) >> 31)))) + 1) + ((100 ^ (((~(((v340 ^ ((int)((unsigned int)((int)((unsigned int)v336 >> 2)) >> 1))) | (-(v340 ^ ((int)((unsigned int)((int)((unsigned int)v336 >> 2)) >> 1))))) >> 31)) | (~(((v341 ^ ((int)((unsigned int)((int)((unsigned int)v336 >> 2)) >> 1))) | (-(v341 ^ ((int)((unsigned int)((int)((unsigned int)v336 >> 2)) >> 1))))) >> 31))) & 104)) ^ (((~(((v338 ^ ((int)((unsigned int)((int)((unsigned int)v336 >> 2)) >> 1))) | (-(v338 ^ ((int)((unsigned int)((int)((unsigned int)v336 >> 2)) >> 1))))) >> 31)) | (~(((v339 ^ ((int)((unsigned int)((int)((unsigned int)v336 >> 2)) >> 1))) | (-(v339 ^ ((int)((unsigned int)((int)((unsigned int)v336 >> 2)) >> 1))))) >> 31))) & (1 ^ (100 ^ (((~(((v340 ^ ((int)((unsigned int)((int)((unsigned int)v336 >> 2)) >> 1))) | (-(v340 ^ ((int)((unsigned int)((int)((unsigned int)v336 >> 2)) >> 1))))) >> 31)) | (~(((v341 ^ ((int)((unsigned int)((int)((unsigned int)v336 >> 2)) >> 1))) | (-(v341 ^ ((int)((unsigned int)((int)((unsigned int)v336 >> 2)) >> 1))))) >> 31))) & 104)))));
  v437[12] = v536;
  int * v439 = v326->regs;
  v439[12] = v436;
  struct StateT * v441 = slot_8(v326);
  return v441;
}

struct StateT * slot_3(struct StateT * v50) {
  int v51 = v50->timer;
  int v55 = v51 + 1;
  v50->timer = v55;
  struct StateT * v53 = slot_4(v50);
  return v53;
}

struct StateT * snippet(struct StateT * v0) {
  struct StateT * v1 = slot_0(v0);
  int v796 = v1->timer;
  int * v797 = v1->reg_ready;
  int v798 = v797[0];
  int v929 = v798 + ((v796 - v798) & (~((v796 - v798) >> 31)));
  v1->timer = v929;
  int v800 = v1->timer;
  int * v801 = v1->reg_ready;
  int v802 = v801[1];
  int v932 = v802 + ((v800 - v802) & (~((v800 - v802) >> 31)));
  v1->timer = v932;
  int v804 = v1->timer;
  int * v805 = v1->reg_ready;
  int v806 = v805[2];
  int v935 = v806 + ((v804 - v806) & (~((v804 - v806) >> 31)));
  v1->timer = v935;
  int v808 = v1->timer;
  int * v809 = v1->reg_ready;
  int v810 = v809[3];
  int v938 = v810 + ((v808 - v810) & (~((v808 - v810) >> 31)));
  v1->timer = v938;
  int v812 = v1->timer;
  int * v813 = v1->reg_ready;
  int v814 = v813[4];
  int v941 = v814 + ((v812 - v814) & (~((v812 - v814) >> 31)));
  v1->timer = v941;
  int v816 = v1->timer;
  int * v817 = v1->reg_ready;
  int v818 = v817[5];
  int v944 = v818 + ((v816 - v818) & (~((v816 - v818) >> 31)));
  v1->timer = v944;
  int v820 = v1->timer;
  int * v821 = v1->reg_ready;
  int v822 = v821[6];
  int v947 = v822 + ((v820 - v822) & (~((v820 - v822) >> 31)));
  v1->timer = v947;
  int v824 = v1->timer;
  int * v825 = v1->reg_ready;
  int v826 = v825[7];
  int v950 = v826 + ((v824 - v826) & (~((v824 - v826) >> 31)));
  v1->timer = v950;
  int v828 = v1->timer;
  int * v829 = v1->reg_ready;
  int v830 = v829[8];
  int v953 = v830 + ((v828 - v830) & (~((v828 - v830) >> 31)));
  v1->timer = v953;
  int v832 = v1->timer;
  int * v833 = v1->reg_ready;
  int v834 = v833[9];
  int v956 = v834 + ((v832 - v834) & (~((v832 - v834) >> 31)));
  v1->timer = v956;
  int v836 = v1->timer;
  int * v837 = v1->reg_ready;
  int v838 = v837[10];
  int v959 = v838 + ((v836 - v838) & (~((v836 - v838) >> 31)));
  v1->timer = v959;
  int v840 = v1->timer;
  int * v841 = v1->reg_ready;
  int v842 = v841[11];
  int v962 = v842 + ((v840 - v842) & (~((v840 - v842) >> 31)));
  v1->timer = v962;
  int v844 = v1->timer;
  int * v845 = v1->reg_ready;
  int v846 = v845[12];
  int v965 = v846 + ((v844 - v846) & (~((v844 - v846) >> 31)));
  v1->timer = v965;
  int v848 = v1->timer;
  int * v849 = v1->reg_ready;
  int v850 = v849[13];
  int v968 = v850 + ((v848 - v850) & (~((v848 - v850) >> 31)));
  v1->timer = v968;
  int v852 = v1->timer;
  int * v853 = v1->reg_ready;
  int v854 = v853[14];
  int v971 = v854 + ((v852 - v854) & (~((v852 - v854) >> 31)));
  v1->timer = v971;
  int v856 = v1->timer;
  int * v857 = v1->reg_ready;
  int v858 = v857[15];
  int v974 = v858 + ((v856 - v858) & (~((v856 - v858) >> 31)));
  v1->timer = v974;
  int v860 = v1->timer;
  int * v861 = v1->reg_ready;
  int v862 = v861[16];
  int v977 = v862 + ((v860 - v862) & (~((v860 - v862) >> 31)));
  v1->timer = v977;
  int v864 = v1->timer;
  int * v865 = v1->reg_ready;
  int v866 = v865[17];
  int v980 = v866 + ((v864 - v866) & (~((v864 - v866) >> 31)));
  v1->timer = v980;
  int v868 = v1->timer;
  int * v869 = v1->reg_ready;
  int v870 = v869[18];
  int v983 = v870 + ((v868 - v870) & (~((v868 - v870) >> 31)));
  v1->timer = v983;
  int v872 = v1->timer;
  int * v873 = v1->reg_ready;
  int v874 = v873[19];
  int v986 = v874 + ((v872 - v874) & (~((v872 - v874) >> 31)));
  v1->timer = v986;
  int v876 = v1->timer;
  int * v877 = v1->reg_ready;
  int v878 = v877[20];
  int v989 = v878 + ((v876 - v878) & (~((v876 - v878) >> 31)));
  v1->timer = v989;
  int v880 = v1->timer;
  int * v881 = v1->reg_ready;
  int v882 = v881[21];
  int v992 = v882 + ((v880 - v882) & (~((v880 - v882) >> 31)));
  v1->timer = v992;
  int v884 = v1->timer;
  int * v885 = v1->reg_ready;
  int v886 = v885[22];
  int v995 = v886 + ((v884 - v886) & (~((v884 - v886) >> 31)));
  v1->timer = v995;
  int v888 = v1->timer;
  int * v889 = v1->reg_ready;
  int v890 = v889[23];
  int v998 = v890 + ((v888 - v890) & (~((v888 - v890) >> 31)));
  v1->timer = v998;
  int v892 = v1->timer;
  int * v893 = v1->reg_ready;
  int v894 = v893[24];
  int v1001 = v894 + ((v892 - v894) & (~((v892 - v894) >> 31)));
  v1->timer = v1001;
  int v896 = v1->timer;
  int * v897 = v1->reg_ready;
  int v898 = v897[25];
  int v1004 = v898 + ((v896 - v898) & (~((v896 - v898) >> 31)));
  v1->timer = v1004;
  int v900 = v1->timer;
  int * v901 = v1->reg_ready;
  int v902 = v901[26];
  int v1007 = v902 + ((v900 - v902) & (~((v900 - v902) >> 31)));
  v1->timer = v1007;
  int v904 = v1->timer;
  int * v905 = v1->reg_ready;
  int v906 = v905[27];
  int v1010 = v906 + ((v904 - v906) & (~((v904 - v906) >> 31)));
  v1->timer = v1010;
  int v908 = v1->timer;
  int * v909 = v1->reg_ready;
  int v910 = v909[28];
  int v1013 = v910 + ((v908 - v910) & (~((v908 - v910) >> 31)));
  v1->timer = v1013;
  int v912 = v1->timer;
  int * v913 = v1->reg_ready;
  int v914 = v913[29];
  int v1016 = v914 + ((v912 - v914) & (~((v912 - v914) >> 31)));
  v1->timer = v1016;
  int v916 = v1->timer;
  int * v917 = v1->reg_ready;
  int v918 = v917[30];
  int v1019 = v918 + ((v916 - v918) & (~((v916 - v918) >> 31)));
  v1->timer = v1019;
  int v920 = v1->timer;
  int * v921 = v1->reg_ready;
  int v922 = v921[31];
  int v1022 = v922 + ((v920 - v922) & (~((v920 - v922) >> 31)));
  v1->timer = v1022;
  return v1;
}

struct StateT * slot_10(struct StateT * v610) {
  int v611 = v610->timer;
  int v718 = v611 + 1;
  v610->timer = v718;
  int * v613 = v610->cache_tags;
  int v614 = v613[0];
  int v615 = v613[1];
  int v616 = v613[4];
  int v617 = v613[5];
  int * v618 = v610->cache_vals;
  bool v724 = !(((~((v614 | (-v614)) >> 31)) | (~((v615 | (-v615)) >> 31))) == 0);
  int v711;
  if (v724) {
    int * v619 = v610->cache_age;
    int v726 = (~((v615 | (-v615)) >> 31)) & 1;
    int v620 = v619[v726];
    int v621 = v619[0];
    int v727 = v621 + ((int)((unsigned int)(v621 - v620) >> 31));
    v619[0] = v727;
    int * v623 = v610->cache_age;
    int v624 = v623[1];
    int v729 = v624 + ((int)((unsigned int)(v624 - v620) >> 31));
    v623[1] = v729;
    int * v626 = v610->cache_age;
    v626[v726] = 0;
    v711 = v726;
  } else {
    int * v629 = v610->cache_age;
    int v630 = v629[0];
    int * v631 = v610->cache_tags;
    int v632 = v631[0];
    int v633 = v629[1];
    int v634 = v631[1];
    bool v733 = !(((~((v616 | (-v616)) >> 31)) | (~((v617 | (-v617)) >> 31))) == 0);
    int v688;
    if (v733) {
      int * v635 = v610->cache_age;
      int v735 = 4 + ((~((v617 | (-v617)) >> 31)) & 1);
      int v636 = v635[v735];
      int v637 = v635[4];
      int v736 = v637 + ((int)((unsigned int)(v637 - v636) >> 31));
      v635[4] = v736;
      int * v639 = v610->cache_age;
      int v640 = v639[5];
      int v738 = v640 + ((int)((unsigned int)(v640 - v636) >> 31));
      v639[5] = v738;
      int * v642 = v610->cache_age;
      v642[v735] = 0;
      v688 = v735;
    } else {
      int * v645 = v610->cache_age;
      int v646 = v645[4];
      int * v647 = v610->cache_tags;
      int v648 = v647[4];
      int v649 = v645[5];
      int v650 = v647[5];
      int * v651 = v610->cache_dirty;
      int v743 = 4 + ((((v646 + ((~(((v648 ^ -1) | (-(v648 ^ -1))) >> 31)) & 2)) - (v649 + ((~(((v650 ^ -1) | (-(v650 ^ -1))) >> 31)) & 2))) >> 31) & 1);
      int v652 = v651[v743];
      bool v744 = !(v652 == 0);
      if (v744) {
        int * v653 = v610->cache_tags;
        int v654 = v653[v743];
        int * v655 = v610->cache_vals;
        int v747 = (4 + ((((v646 + ((~(((v648 ^ -1) | (-(v648 ^ -1))) >> 31)) & 2)) - (v649 + ((~(((v650 ^ -1) | (-(v650 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
        int v656 = v655[v747];
        int v748 = ((4 + ((((v646 + ((~(((v648 ^ -1) | (-(v648 ^ -1))) >> 31)) & 2)) - (v649 + ((~(((v650 ^ -1) | (-(v650 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
        int v657 = v655[v748];
        int * v658 = v610->mem;
        int v750 = v654 * 2;
        v658[v750] = v656;
        int * v660 = v610->mem;
        int v753 = (v654 * 2) + 1;
        v660[v753] = v657;
        ;
      } else {
        ;
      }
      int * v665 = v610->mem;
      int v666 = v665[0];
      int v667 = v665[1];
      int * v668 = v610->cache_vals;
      int v759 = (4 + ((((v646 + ((~(((v648 ^ -1) | (-(v648 ^ -1))) >> 31)) & 2)) - (v649 + ((~(((v650 ^ -1) | (-(v650 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
      v668[v759] = v666;
      int * v670 = v610->cache_vals;
      int v762 = ((4 + ((((v646 + ((~(((v648 ^ -1) | (-(v648 ^ -1))) >> 31)) & 2)) - (v649 + ((~(((v650 ^ -1) | (-(v650 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
      v670[v762] = v667;
      int * v672 = v610->cache_tags;
      v672[v743] = 0;
      int * v674 = v610->cache_dirty;
      v674[v743] = 0;
      int * v676 = v610->cache_age;
      v676[v743] = 1;
      int * v678 = v610->cache_age;
      int v679 = v678[v743];
      int v680 = v678[4];
      int v768 = v680 + ((int)((unsigned int)(v680 - v679) >> 31));
      v678[4] = v768;
      int * v682 = v610->cache_age;
      int v683 = v682[5];
      int v770 = v683 + ((int)((unsigned int)(v683 - v679) >> 31));
      v682[5] = v770;
      int * v685 = v610->cache_age;
      v685[v743] = 0;
      v688 = v743;
    }
    int * v689 = v610->cache_vals;
    int v773 = v688 * 2;
    int v690 = v689[v773];
    int v774 = (v688 * 2) + 1;
    int v691 = v689[v774];
    int v775 = ((((v630 + ((~(((v632 ^ -1) | (-(v632 ^ -1))) >> 31)) & 2)) - (v633 + ((~(((v634 ^ -1) | (-(v634 ^ -1))) >> 31)) & 2))) >> 31) & 1) * 2;
    v689[v775] = v690;
    int * v693 = v610->cache_vals;
    int v778 = (((((v630 + ((~(((v632 ^ -1) | (-(v632 ^ -1))) >> 31)) & 2)) - (v633 + ((~(((v634 ^ -1) | (-(v634 ^ -1))) >> 31)) & 2))) >> 31) & 1) * 2) + 1;
    v693[v778] = v691;
    int * v695 = v610->cache_tags;
    int v781 = (((v630 + ((~(((v632 ^ -1) | (-(v632 ^ -1))) >> 31)) & 2)) - (v633 + ((~(((v634 ^ -1) | (-(v634 ^ -1))) >> 31)) & 2))) >> 31) & 1;
    v695[v781] = 0;
    int * v697 = v610->cache_dirty;
    v697[v781] = 0;
    int * v699 = v610->cache_age;
    v699[v781] = 1;
    int * v701 = v610->cache_age;
    int v702 = v701[v781];
    int v703 = v701[0];
    int v785 = v703 + ((int)((unsigned int)(v703 - v702) >> 31));
    v701[0] = v785;
    int * v705 = v610->cache_age;
    int v706 = v705[1];
    int v787 = v706 + ((int)((unsigned int)(v706 - v702) >> 31));
    v705[1] = v787;
    int * v708 = v610->cache_age;
    v708[v781] = 0;
    v711 = v781;
  }
  int v790 = v711 * 2;
  int v712 = v618[v790];
  int * v713 = v610->reg_ready;
  int v793 = (v611 + 1) + ((100 ^ (((~((v616 | (-v616)) >> 31)) | (~((v617 | (-v617)) >> 31))) & 104)) ^ (((~((v614 | (-v614)) >> 31)) | (~((v615 | (-v615)) >> 31))) & (1 ^ (100 ^ (((~((v616 | (-v616)) >> 31)) | (~((v617 | (-v617)) >> 31))) & 104)))));
  v713[14] = v793;
  int * v715 = v610->regs;
  v715[14] = v712;
  return v610;
}

struct StateT * slot_1(struct StateT * v18) {
  int v19 = v18->timer;
  int v27 = v19 + 1;
  v18->timer = v27;
  int * v21 = v18->reg_ready;
  v21[10] = v27;
  int * v23 = v18->regs;
  v23[10] = 80;
  struct StateT * v25 = slot_2(v18);
  return v25;
}

struct StateT * slot_8(struct StateT * v541) {
  int * v542 = v541->regs;
  int v543 = v542[10];
  int v544 = v542[15];
  bool v577 = v543 >= v544;
  struct StateT * v572;
  if (v577) {
    int v545 = v541->timer;
    int v578 = v545 + 15;
    v541->timer = v578;
    int * v547 = v541->saved_regs;
    int v548 = v547[5];
    int * v549 = v541->regs;
    v549[5] = v548;
    int * v551 = v541->saved_regs;
    int v552 = v551[11];
    int * v553 = v541->regs;
    v553[11] = v552;
    int * v555 = v541->saved_regs;
    int v556 = v555[12];
    int * v557 = v541->regs;
    v557[12] = v556;
    int * v559 = v541->reg_ready;
    int v560 = v541->timer;
    v559[5] = v560;
    int * v562 = v541->reg_ready;
    int v563 = v541->timer;
    v562[11] = v563;
    int * v565 = v541->reg_ready;
    int v566 = v541->timer;
    v565[12] = v566;
    struct StateT * v568 = slot_9(v541);
    v572 = v568;
  } else {
    struct StateT * v570 = slot_9(v541);
    v572 = v570;
  }
  return v572;
}

struct StateT * slot_4(struct StateT * v58) {
  int * v59 = v58->saved_regs;
  int * v60 = v58->regs;
  int v61 = v60[5];
  v59[5] = v61;
  int v63 = v58->timer;
  int v80 = v63 + 1;
  v58->timer = v80;
  int * v65 = v58->reg_ready;
  int v66 = v65[13];
  int * v67 = v58->regs;
  int v68 = v67[13];
  int v69 = v65[10];
  int v70 = v67[10];
  int v85 = (v69 + (((v66 + ((v63 - v66) & (~((v63 - v66) >> 31)))) - v69) & (~(((v66 + ((v63 - v66) & (~((v63 - v66) >> 31)))) - v69) >> 31)))) + 1;
  v65[5] = v85;
  int * v72 = v58->regs;
  int v87 = v68 + v70;
  v72[5] = v87;
  struct StateT * v74 = slot_5(v58);
  return v74;
}

struct StateT * slot_9(struct StateT * v602) {
  int v603 = v602->timer;
  int v607 = v603 + 1;
  v602->timer = v607;
  struct StateT * v605 = slot_10(v602);
  return v605;
}

struct StateT * slot_0(struct StateT * v2) {
  int v3 = v2->timer;
  int v11 = v3 + 1;
  v2->timer = v11;
  int * v5 = v2->reg_ready;
  v5[13] = v11;
  int * v7 = v2->regs;
  v7[13] = 0;
  struct StateT * v9 = slot_1(v2);
  return v9;
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