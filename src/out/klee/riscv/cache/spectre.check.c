// verify: clean (KLEE should report no failing assertion) [budget 1200s]
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

struct StateT * snippet(struct StateT * v0);
struct StateT * slot_1(struct StateT * v15);
struct StateT * slot_6(struct StateT * v333);
struct StateT * slot_5(struct StateT * v83);
struct StateT * slot_4(struct StateT * v62);
struct StateT * slot_2(struct StateT * v28);
struct StateT * slot_7(struct StateT * v349);
struct StateT * slot_3(struct StateT * v41);
struct StateT * slot_0(struct StateT * v2);
struct StateT * snippet(struct StateT * v0) {
  struct StateT * v1 = slot_0(v0);
  return v1;
}

struct StateT * slot_1(struct StateT * v15) {
  int v16 = v15->timer;
  int v22 = v16 + 1;
  v15->timer = v22;
  int * v18 = v15->regs;
  v18[10] = 80;
  struct StateT * v20 = slot_2(v15);
  return v20;
}

struct StateT * slot_6(struct StateT * v333) {
  int v334 = v333->timer;
  int v342 = v334 + 1;
  v333->timer = v342;
  int * v336 = v333->regs;
  int v337 = v336[11];
  int * v338 = v333->regs;
  int v346 = v337 << 2;
  v338[11] = v346;
  struct StateT * v340 = slot_7(v333);
  return v340;
}

struct StateT * slot_5(struct StateT * v83) {
  int v84 = v83->timer;
  int v217 = v84 + 1;
  v83->timer = v217;
  int * v86 = v83->regs;
  int v87 = v86[5];
  int * v88 = v83->cache_tags;
  int v221 = (((int)((unsigned int)((int)((unsigned int)v87 >> 2)) >> 1)) & 1) * 2;
  int v89 = v88[v221];
  int * v90 = v83->cache_tags;
  int v223 = ((((int)((unsigned int)((int)((unsigned int)v87 >> 2)) >> 1)) & 1) * 2) + 1;
  int v91 = v90[v223];
  int * v92 = v83->cache_tags;
  int v225 = 4 + ((((int)((unsigned int)((int)((unsigned int)v87 >> 2)) >> 1)) & 3) * 2);
  int v93 = v92[v225];
  int * v94 = v83->cache_tags;
  int v227 = (4 + ((((int)((unsigned int)((int)((unsigned int)v87 >> 2)) >> 1)) & 3) * 2)) + 1;
  int v95 = v94[v227];
  int v96 = v83->timer;
  int v228 = v96 + ((100 ^ (((~(((v93 ^ ((int)((unsigned int)((int)((unsigned int)v87 >> 2)) >> 1))) | (-(v93 ^ ((int)((unsigned int)((int)((unsigned int)v87 >> 2)) >> 1))))) >> 31)) | (~(((v95 ^ ((int)((unsigned int)((int)((unsigned int)v87 >> 2)) >> 1))) | (-(v95 ^ ((int)((unsigned int)((int)((unsigned int)v87 >> 2)) >> 1))))) >> 31))) & 104)) ^ (((~(((v89 ^ ((int)((unsigned int)((int)((unsigned int)v87 >> 2)) >> 1))) | (-(v89 ^ ((int)((unsigned int)((int)((unsigned int)v87 >> 2)) >> 1))))) >> 31)) | (~(((v91 ^ ((int)((unsigned int)((int)((unsigned int)v87 >> 2)) >> 1))) | (-(v91 ^ ((int)((unsigned int)((int)((unsigned int)v87 >> 2)) >> 1))))) >> 31))) & (1 ^ (100 ^ (((~(((v93 ^ ((int)((unsigned int)((int)((unsigned int)v87 >> 2)) >> 1))) | (-(v93 ^ ((int)((unsigned int)((int)((unsigned int)v87 >> 2)) >> 1))))) >> 31)) | (~(((v95 ^ ((int)((unsigned int)((int)((unsigned int)v87 >> 2)) >> 1))) | (-(v95 ^ ((int)((unsigned int)((int)((unsigned int)v87 >> 2)) >> 1))))) >> 31))) & 104)))));
  v83->timer = v228;
  int * v98 = v83->cache_vals;
  bool v229 = !(((~(((v89 ^ ((int)((unsigned int)((int)((unsigned int)v87 >> 2)) >> 1))) | (-(v89 ^ ((int)((unsigned int)((int)((unsigned int)v87 >> 2)) >> 1))))) >> 31)) | (~(((v91 ^ ((int)((unsigned int)((int)((unsigned int)v87 >> 2)) >> 1))) | (-(v91 ^ ((int)((unsigned int)((int)((unsigned int)v87 >> 2)) >> 1))))) >> 31))) == 0);
  int v211;
  if (v229) {
    int * v99 = v83->cache_age;
    int v231 = ((((int)((unsigned int)((int)((unsigned int)v87 >> 2)) >> 1)) & 1) * 2) + ((~(((v91 ^ ((int)((unsigned int)((int)((unsigned int)v87 >> 2)) >> 1))) | (-(v91 ^ ((int)((unsigned int)((int)((unsigned int)v87 >> 2)) >> 1))))) >> 31)) & 1);
    int v100 = v99[v231];
    int * v101 = v83->cache_age;
    int v102 = v101[v221];
    int * v103 = v83->cache_age;
    int v234 = v102 + ((int)((unsigned int)(v102 - v100) >> 31));
    v103[v221] = v234;
    int * v105 = v83->cache_age;
    int v106 = v105[v223];
    int * v107 = v83->cache_age;
    int v237 = v106 + ((int)((unsigned int)(v106 - v100) >> 31));
    v107[v223] = v237;
    int * v109 = v83->cache_age;
    v109[v231] = 0;
    v211 = v231;
  } else {
    int * v112 = v83->cache_age;
    int v241 = (((int)((unsigned int)((int)((unsigned int)v87 >> 2)) >> 1)) & 1) * 2;
    int v113 = v112[v241];
    int * v114 = v83->cache_tags;
    int v115 = v114[v241];
    int * v116 = v83->cache_age;
    int v117 = v116[v223];
    int * v118 = v83->cache_tags;
    int v119 = v118[v223];
    bool v245 = !(((~(((v93 ^ ((int)((unsigned int)((int)((unsigned int)v87 >> 2)) >> 1))) | (-(v93 ^ ((int)((unsigned int)((int)((unsigned int)v87 >> 2)) >> 1))))) >> 31)) | (~(((v95 ^ ((int)((unsigned int)((int)((unsigned int)v87 >> 2)) >> 1))) | (-(v95 ^ ((int)((unsigned int)((int)((unsigned int)v87 >> 2)) >> 1))))) >> 31))) == 0);
    int v183;
    if (v245) {
      int * v120 = v83->cache_age;
      int v247 = (4 + ((((int)((unsigned int)((int)((unsigned int)v87 >> 2)) >> 1)) & 3) * 2)) + ((~(((v95 ^ ((int)((unsigned int)((int)((unsigned int)v87 >> 2)) >> 1))) | (-(v95 ^ ((int)((unsigned int)((int)((unsigned int)v87 >> 2)) >> 1))))) >> 31)) & 1);
      int v121 = v120[v247];
      int * v122 = v83->cache_age;
      int v123 = v122[v225];
      int * v124 = v83->cache_age;
      int v250 = v123 + ((int)((unsigned int)(v123 - v121) >> 31));
      v124[v225] = v250;
      int * v126 = v83->cache_age;
      int v127 = v126[v227];
      int * v128 = v83->cache_age;
      int v253 = v127 + ((int)((unsigned int)(v127 - v121) >> 31));
      v128[v227] = v253;
      int * v130 = v83->cache_age;
      v130[v247] = 0;
      v183 = v247;
    } else {
      int * v133 = v83->cache_age;
      int v257 = 4 + ((((int)((unsigned int)((int)((unsigned int)v87 >> 2)) >> 1)) & 3) * 2);
      int v134 = v133[v257];
      int * v135 = v83->cache_tags;
      int v136 = v135[v257];
      int * v137 = v83->cache_age;
      int v138 = v137[v227];
      int * v139 = v83->cache_tags;
      int v140 = v139[v227];
      int * v141 = v83->cache_dirty;
      int v262 = (4 + ((((int)((unsigned int)((int)((unsigned int)v87 >> 2)) >> 1)) & 3) * 2)) + ((((v134 + ((~(((v136 ^ -1) | (-(v136 ^ -1))) >> 31)) & 2)) - (v138 + ((~(((v140 ^ -1) | (-(v140 ^ -1))) >> 31)) & 2))) >> 31) & 1);
      int v142 = v141[v262];
      bool v263 = !(v142 == 0);
      if (v263) {
        int * v143 = v83->cache_tags;
        int v144 = v143[v262];
        int * v145 = v83->cache_vals;
        int v266 = ((4 + ((((int)((unsigned int)((int)((unsigned int)v87 >> 2)) >> 1)) & 3) * 2)) + ((((v134 + ((~(((v136 ^ -1) | (-(v136 ^ -1))) >> 31)) & 2)) - (v138 + ((~(((v140 ^ -1) | (-(v140 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
        int v146 = v145[v266];
        int * v147 = v83->cache_vals;
        int v268 = (((4 + ((((int)((unsigned int)((int)((unsigned int)v87 >> 2)) >> 1)) & 3) * 2)) + ((((v134 + ((~(((v136 ^ -1) | (-(v136 ^ -1))) >> 31)) & 2)) - (v138 + ((~(((v140 ^ -1) | (-(v140 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
        int v148 = v147[v268];
        int * v149 = v83->mem;
        int v270 = v144 * 2;
        v149[v270] = v146;
        int * v151 = v83->mem;
        int v273 = (v144 * 2) + 1;
        v151[v273] = v148;
        ;
      } else {
        ;
      }
      int * v156 = v83->mem;
      int v278 = ((int)((unsigned int)((int)((unsigned int)v87 >> 2)) >> 1)) * 2;
      int v157 = v156[v278];
      int * v158 = v83->mem;
      int v280 = (((int)((unsigned int)((int)((unsigned int)v87 >> 2)) >> 1)) * 2) + 1;
      int v159 = v158[v280];
      int * v160 = v83->cache_vals;
      int v282 = ((4 + ((((int)((unsigned int)((int)((unsigned int)v87 >> 2)) >> 1)) & 3) * 2)) + ((((v134 + ((~(((v136 ^ -1) | (-(v136 ^ -1))) >> 31)) & 2)) - (v138 + ((~(((v140 ^ -1) | (-(v140 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
      v160[v282] = v157;
      int * v162 = v83->cache_vals;
      int v285 = (((4 + ((((int)((unsigned int)((int)((unsigned int)v87 >> 2)) >> 1)) & 3) * 2)) + ((((v134 + ((~(((v136 ^ -1) | (-(v136 ^ -1))) >> 31)) & 2)) - (v138 + ((~(((v140 ^ -1) | (-(v140 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
      v162[v285] = v159;
      int * v164 = v83->cache_tags;
      int v288 = (int)((unsigned int)((int)((unsigned int)v87 >> 2)) >> 1);
      v164[v262] = v288;
      int * v166 = v83->cache_dirty;
      v166[v262] = 0;
      int * v168 = v83->cache_age;
      v168[v262] = 1;
      int * v170 = v83->cache_age;
      int v171 = v170[v262];
      int * v172 = v83->cache_age;
      int v173 = v172[v225];
      int * v174 = v83->cache_age;
      int v296 = v173 + ((int)((unsigned int)(v173 - v171) >> 31));
      v174[v225] = v296;
      int * v176 = v83->cache_age;
      int v177 = v176[v227];
      int * v178 = v83->cache_age;
      int v299 = v177 + ((int)((unsigned int)(v177 - v171) >> 31));
      v178[v227] = v299;
      int * v180 = v83->cache_age;
      v180[v262] = 0;
      v183 = v262;
    }
    int * v184 = v83->cache_vals;
    int v302 = v183 * 2;
    int v185 = v184[v302];
    int * v186 = v83->cache_vals;
    int v304 = (v183 * 2) + 1;
    int v187 = v186[v304];
    int * v188 = v83->cache_vals;
    int v306 = (((((int)((unsigned int)((int)((unsigned int)v87 >> 2)) >> 1)) & 1) * 2) + ((((v113 + ((~(((v115 ^ -1) | (-(v115 ^ -1))) >> 31)) & 2)) - (v117 + ((~(((v119 ^ -1) | (-(v119 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
    v188[v306] = v185;
    int * v190 = v83->cache_vals;
    int v309 = ((((((int)((unsigned int)((int)((unsigned int)v87 >> 2)) >> 1)) & 1) * 2) + ((((v113 + ((~(((v115 ^ -1) | (-(v115 ^ -1))) >> 31)) & 2)) - (v117 + ((~(((v119 ^ -1) | (-(v119 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
    v190[v309] = v187;
    int * v192 = v83->cache_tags;
    int v312 = ((((int)((unsigned int)((int)((unsigned int)v87 >> 2)) >> 1)) & 1) * 2) + ((((v113 + ((~(((v115 ^ -1) | (-(v115 ^ -1))) >> 31)) & 2)) - (v117 + ((~(((v119 ^ -1) | (-(v119 ^ -1))) >> 31)) & 2))) >> 31) & 1);
    int v313 = (int)((unsigned int)((int)((unsigned int)v87 >> 2)) >> 1);
    v192[v312] = v313;
    int * v194 = v83->cache_dirty;
    v194[v312] = 0;
    int * v196 = v83->cache_age;
    v196[v312] = 1;
    int * v198 = v83->cache_age;
    int v199 = v198[v312];
    int * v200 = v83->cache_age;
    int v201 = v200[v221];
    int * v202 = v83->cache_age;
    int v321 = v201 + ((int)((unsigned int)(v201 - v199) >> 31));
    v202[v221] = v321;
    int * v204 = v83->cache_age;
    int v205 = v204[v223];
    int * v206 = v83->cache_age;
    int v324 = v205 + ((int)((unsigned int)(v205 - v199) >> 31));
    v206[v223] = v324;
    int * v208 = v83->cache_age;
    v208[v312] = 0;
    v211 = v312;
  }
  int v327 = (v211 * 2) + (((int)((unsigned int)v87 >> 2)) & 1);
  int v212 = v98[v327];
  int * v213 = v83->regs;
  v213[11] = v212;
  struct StateT * v215 = slot_6(v83);
  return v215;
}

struct StateT * slot_4(struct StateT * v62) {
  int v63 = v62->timer;
  int v73 = v63 + 1;
  v62->timer = v73;
  int * v65 = v62->regs;
  int v66 = v65[13];
  int * v67 = v62->regs;
  int v68 = v67[10];
  int * v69 = v62->regs;
  int v80 = v66 + v68;
  v69[5] = v80;
  struct StateT * v71 = slot_5(v62);
  return v71;
}

struct StateT * slot_2(struct StateT * v28) {
  int v29 = v28->timer;
  int v35 = v29 + 1;
  v28->timer = v35;
  int * v31 = v28->regs;
  v31[15] = 80;
  struct StateT * v33 = slot_3(v28);
  return v33;
}

struct StateT * slot_7(struct StateT * v349) {
  int v350 = v349->timer;
  int v482 = v350 + 1;
  v349->timer = v482;
  int * v352 = v349->regs;
  int v353 = v352[11];
  int * v354 = v349->cache_tags;
  int v486 = (((int)((unsigned int)((int)((unsigned int)v353 >> 2)) >> 1)) & 1) * 2;
  int v355 = v354[v486];
  int * v356 = v349->cache_tags;
  int v488 = ((((int)((unsigned int)((int)((unsigned int)v353 >> 2)) >> 1)) & 1) * 2) + 1;
  int v357 = v356[v488];
  int * v358 = v349->cache_tags;
  int v490 = 4 + ((((int)((unsigned int)((int)((unsigned int)v353 >> 2)) >> 1)) & 3) * 2);
  int v359 = v358[v490];
  int * v360 = v349->cache_tags;
  int v492 = (4 + ((((int)((unsigned int)((int)((unsigned int)v353 >> 2)) >> 1)) & 3) * 2)) + 1;
  int v361 = v360[v492];
  int v362 = v349->timer;
  int v493 = v362 + ((100 ^ (((~(((v359 ^ ((int)((unsigned int)((int)((unsigned int)v353 >> 2)) >> 1))) | (-(v359 ^ ((int)((unsigned int)((int)((unsigned int)v353 >> 2)) >> 1))))) >> 31)) | (~(((v361 ^ ((int)((unsigned int)((int)((unsigned int)v353 >> 2)) >> 1))) | (-(v361 ^ ((int)((unsigned int)((int)((unsigned int)v353 >> 2)) >> 1))))) >> 31))) & 104)) ^ (((~(((v355 ^ ((int)((unsigned int)((int)((unsigned int)v353 >> 2)) >> 1))) | (-(v355 ^ ((int)((unsigned int)((int)((unsigned int)v353 >> 2)) >> 1))))) >> 31)) | (~(((v357 ^ ((int)((unsigned int)((int)((unsigned int)v353 >> 2)) >> 1))) | (-(v357 ^ ((int)((unsigned int)((int)((unsigned int)v353 >> 2)) >> 1))))) >> 31))) & (1 ^ (100 ^ (((~(((v359 ^ ((int)((unsigned int)((int)((unsigned int)v353 >> 2)) >> 1))) | (-(v359 ^ ((int)((unsigned int)((int)((unsigned int)v353 >> 2)) >> 1))))) >> 31)) | (~(((v361 ^ ((int)((unsigned int)((int)((unsigned int)v353 >> 2)) >> 1))) | (-(v361 ^ ((int)((unsigned int)((int)((unsigned int)v353 >> 2)) >> 1))))) >> 31))) & 104)))));
  v349->timer = v493;
  int * v364 = v349->cache_vals;
  bool v494 = !(((~(((v355 ^ ((int)((unsigned int)((int)((unsigned int)v353 >> 2)) >> 1))) | (-(v355 ^ ((int)((unsigned int)((int)((unsigned int)v353 >> 2)) >> 1))))) >> 31)) | (~(((v357 ^ ((int)((unsigned int)((int)((unsigned int)v353 >> 2)) >> 1))) | (-(v357 ^ ((int)((unsigned int)((int)((unsigned int)v353 >> 2)) >> 1))))) >> 31))) == 0);
  int v477;
  if (v494) {
    int * v365 = v349->cache_age;
    int v496 = ((((int)((unsigned int)((int)((unsigned int)v353 >> 2)) >> 1)) & 1) * 2) + ((~(((v357 ^ ((int)((unsigned int)((int)((unsigned int)v353 >> 2)) >> 1))) | (-(v357 ^ ((int)((unsigned int)((int)((unsigned int)v353 >> 2)) >> 1))))) >> 31)) & 1);
    int v366 = v365[v496];
    int * v367 = v349->cache_age;
    int v368 = v367[v486];
    int * v369 = v349->cache_age;
    int v499 = v368 + ((int)((unsigned int)(v368 - v366) >> 31));
    v369[v486] = v499;
    int * v371 = v349->cache_age;
    int v372 = v371[v488];
    int * v373 = v349->cache_age;
    int v502 = v372 + ((int)((unsigned int)(v372 - v366) >> 31));
    v373[v488] = v502;
    int * v375 = v349->cache_age;
    v375[v496] = 0;
    v477 = v496;
  } else {
    int * v378 = v349->cache_age;
    int v506 = (((int)((unsigned int)((int)((unsigned int)v353 >> 2)) >> 1)) & 1) * 2;
    int v379 = v378[v506];
    int * v380 = v349->cache_tags;
    int v381 = v380[v506];
    int * v382 = v349->cache_age;
    int v383 = v382[v488];
    int * v384 = v349->cache_tags;
    int v385 = v384[v488];
    bool v510 = !(((~(((v359 ^ ((int)((unsigned int)((int)((unsigned int)v353 >> 2)) >> 1))) | (-(v359 ^ ((int)((unsigned int)((int)((unsigned int)v353 >> 2)) >> 1))))) >> 31)) | (~(((v361 ^ ((int)((unsigned int)((int)((unsigned int)v353 >> 2)) >> 1))) | (-(v361 ^ ((int)((unsigned int)((int)((unsigned int)v353 >> 2)) >> 1))))) >> 31))) == 0);
    int v449;
    if (v510) {
      int * v386 = v349->cache_age;
      int v512 = (4 + ((((int)((unsigned int)((int)((unsigned int)v353 >> 2)) >> 1)) & 3) * 2)) + ((~(((v361 ^ ((int)((unsigned int)((int)((unsigned int)v353 >> 2)) >> 1))) | (-(v361 ^ ((int)((unsigned int)((int)((unsigned int)v353 >> 2)) >> 1))))) >> 31)) & 1);
      int v387 = v386[v512];
      int * v388 = v349->cache_age;
      int v389 = v388[v490];
      int * v390 = v349->cache_age;
      int v515 = v389 + ((int)((unsigned int)(v389 - v387) >> 31));
      v390[v490] = v515;
      int * v392 = v349->cache_age;
      int v393 = v392[v492];
      int * v394 = v349->cache_age;
      int v518 = v393 + ((int)((unsigned int)(v393 - v387) >> 31));
      v394[v492] = v518;
      int * v396 = v349->cache_age;
      v396[v512] = 0;
      v449 = v512;
    } else {
      int * v399 = v349->cache_age;
      int v522 = 4 + ((((int)((unsigned int)((int)((unsigned int)v353 >> 2)) >> 1)) & 3) * 2);
      int v400 = v399[v522];
      int * v401 = v349->cache_tags;
      int v402 = v401[v522];
      int * v403 = v349->cache_age;
      int v404 = v403[v492];
      int * v405 = v349->cache_tags;
      int v406 = v405[v492];
      int * v407 = v349->cache_dirty;
      int v527 = (4 + ((((int)((unsigned int)((int)((unsigned int)v353 >> 2)) >> 1)) & 3) * 2)) + ((((v400 + ((~(((v402 ^ -1) | (-(v402 ^ -1))) >> 31)) & 2)) - (v404 + ((~(((v406 ^ -1) | (-(v406 ^ -1))) >> 31)) & 2))) >> 31) & 1);
      int v408 = v407[v527];
      bool v528 = !(v408 == 0);
      if (v528) {
        int * v409 = v349->cache_tags;
        int v410 = v409[v527];
        int * v411 = v349->cache_vals;
        int v531 = ((4 + ((((int)((unsigned int)((int)((unsigned int)v353 >> 2)) >> 1)) & 3) * 2)) + ((((v400 + ((~(((v402 ^ -1) | (-(v402 ^ -1))) >> 31)) & 2)) - (v404 + ((~(((v406 ^ -1) | (-(v406 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
        int v412 = v411[v531];
        int * v413 = v349->cache_vals;
        int v533 = (((4 + ((((int)((unsigned int)((int)((unsigned int)v353 >> 2)) >> 1)) & 3) * 2)) + ((((v400 + ((~(((v402 ^ -1) | (-(v402 ^ -1))) >> 31)) & 2)) - (v404 + ((~(((v406 ^ -1) | (-(v406 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
        int v414 = v413[v533];
        int * v415 = v349->mem;
        int v535 = v410 * 2;
        v415[v535] = v412;
        int * v417 = v349->mem;
        int v538 = (v410 * 2) + 1;
        v417[v538] = v414;
        ;
      } else {
        ;
      }
      int * v422 = v349->mem;
      int v543 = ((int)((unsigned int)((int)((unsigned int)v353 >> 2)) >> 1)) * 2;
      int v423 = v422[v543];
      int * v424 = v349->mem;
      int v545 = (((int)((unsigned int)((int)((unsigned int)v353 >> 2)) >> 1)) * 2) + 1;
      int v425 = v424[v545];
      int * v426 = v349->cache_vals;
      int v547 = ((4 + ((((int)((unsigned int)((int)((unsigned int)v353 >> 2)) >> 1)) & 3) * 2)) + ((((v400 + ((~(((v402 ^ -1) | (-(v402 ^ -1))) >> 31)) & 2)) - (v404 + ((~(((v406 ^ -1) | (-(v406 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
      v426[v547] = v423;
      int * v428 = v349->cache_vals;
      int v550 = (((4 + ((((int)((unsigned int)((int)((unsigned int)v353 >> 2)) >> 1)) & 3) * 2)) + ((((v400 + ((~(((v402 ^ -1) | (-(v402 ^ -1))) >> 31)) & 2)) - (v404 + ((~(((v406 ^ -1) | (-(v406 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
      v428[v550] = v425;
      int * v430 = v349->cache_tags;
      int v553 = (int)((unsigned int)((int)((unsigned int)v353 >> 2)) >> 1);
      v430[v527] = v553;
      int * v432 = v349->cache_dirty;
      v432[v527] = 0;
      int * v434 = v349->cache_age;
      v434[v527] = 1;
      int * v436 = v349->cache_age;
      int v437 = v436[v527];
      int * v438 = v349->cache_age;
      int v439 = v438[v490];
      int * v440 = v349->cache_age;
      int v561 = v439 + ((int)((unsigned int)(v439 - v437) >> 31));
      v440[v490] = v561;
      int * v442 = v349->cache_age;
      int v443 = v442[v492];
      int * v444 = v349->cache_age;
      int v564 = v443 + ((int)((unsigned int)(v443 - v437) >> 31));
      v444[v492] = v564;
      int * v446 = v349->cache_age;
      v446[v527] = 0;
      v449 = v527;
    }
    int * v450 = v349->cache_vals;
    int v567 = v449 * 2;
    int v451 = v450[v567];
    int * v452 = v349->cache_vals;
    int v569 = (v449 * 2) + 1;
    int v453 = v452[v569];
    int * v454 = v349->cache_vals;
    int v571 = (((((int)((unsigned int)((int)((unsigned int)v353 >> 2)) >> 1)) & 1) * 2) + ((((v379 + ((~(((v381 ^ -1) | (-(v381 ^ -1))) >> 31)) & 2)) - (v383 + ((~(((v385 ^ -1) | (-(v385 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
    v454[v571] = v451;
    int * v456 = v349->cache_vals;
    int v574 = ((((((int)((unsigned int)((int)((unsigned int)v353 >> 2)) >> 1)) & 1) * 2) + ((((v379 + ((~(((v381 ^ -1) | (-(v381 ^ -1))) >> 31)) & 2)) - (v383 + ((~(((v385 ^ -1) | (-(v385 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
    v456[v574] = v453;
    int * v458 = v349->cache_tags;
    int v577 = ((((int)((unsigned int)((int)((unsigned int)v353 >> 2)) >> 1)) & 1) * 2) + ((((v379 + ((~(((v381 ^ -1) | (-(v381 ^ -1))) >> 31)) & 2)) - (v383 + ((~(((v385 ^ -1) | (-(v385 ^ -1))) >> 31)) & 2))) >> 31) & 1);
    int v578 = (int)((unsigned int)((int)((unsigned int)v353 >> 2)) >> 1);
    v458[v577] = v578;
    int * v460 = v349->cache_dirty;
    v460[v577] = 0;
    int * v462 = v349->cache_age;
    v462[v577] = 1;
    int * v464 = v349->cache_age;
    int v465 = v464[v577];
    int * v466 = v349->cache_age;
    int v467 = v466[v486];
    int * v468 = v349->cache_age;
    int v586 = v467 + ((int)((unsigned int)(v467 - v465) >> 31));
    v468[v486] = v586;
    int * v470 = v349->cache_age;
    int v471 = v470[v488];
    int * v472 = v349->cache_age;
    int v589 = v471 + ((int)((unsigned int)(v471 - v465) >> 31));
    v472[v488] = v589;
    int * v474 = v349->cache_age;
    v474[v577] = 0;
    v477 = v577;
  }
  int v592 = (v477 * 2) + (((int)((unsigned int)v353 >> 2)) & 1);
  int v478 = v364[v592];
  int * v479 = v349->regs;
  v479[12] = v478;
  return v349;
}

struct StateT * slot_3(struct StateT * v41) {
  int v42 = v41->timer;
  int v53 = v42 + 1;
  v41->timer = v53;
  int * v44 = v41->regs;
  int v45 = v44[10];
  int * v46 = v41->regs;
  int v47 = v46[15];
  bool v58 = v45 >= v47;
  struct StateT * v51;
  if (v58) {
    v51 = v41;
  } else {
    struct StateT * v49 = slot_4(v41);
    v51 = v49;
  }
  return v51;
}

struct StateT * slot_0(struct StateT * v2) {
  int v3 = v2->timer;
  int v9 = v3 + 1;
  v2->timer = v9;
  int * v5 = v2->regs;
  v5[13] = 0;
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
    s1.mem[SECRET_OFFSET+i] = bounded(0, 20);
    s2.mem[SECRET_OFFSET+i] = bounded(0, 20);
  }
  struct StateT *s1_ = snippet(&s1);
  struct StateT *s2_ = snippet(&s2);
  koika_assert(s1_->timer==s2_->timer, "timing leak");
  return 0;
}