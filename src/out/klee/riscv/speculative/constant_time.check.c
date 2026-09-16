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
  int cache_tags[12];
  int cache_dirty[12];
  int cache_age[12];
  int cache_vals[24];
  int timer;
};

struct StateT * snippet(struct StateT * v0);
struct StateT * slot_14(struct StateT * v731);
struct StateT * slot_1(struct StateT * v15);
struct StateT * slot_5(struct StateT * v67);
struct StateT * slot_4(struct StateT * v54);
struct StateT * slot_13(struct StateT * v751);
struct StateT * slot_2(struct StateT * v28);
struct StateT * slot_3(struct StateT * v41);
struct StateT * slot_0(struct StateT * v2);
struct StateT * snippet(struct StateT * v0) {
  struct StateT * v1 = slot_0(v0);
  return v1;
}

struct StateT * slot_14(struct StateT * v731) {
  int v732 = v731->timer;
  int v742 = v732 + 1;
  v731->timer = v742;
  int * v734 = v731->regs;
  int v735 = v734[5];
  bool v745 = (v735 ^ -2147483648) < -2147483647;
  int v738;
  if (v745) {
    v738 = 1;
  } else {
    v738 = 0;
  }
  int * v739 = v731->regs;
  v739[11] = v738;
  return v731;
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

struct StateT * slot_5(struct StateT * v67) {
  int * v68 = v67->saved_regs;
  int * v69 = v67->regs;
  int v70 = v69[6];
  v68[6] = v70;
  int v72 = v67->timer;
  int v432 = v72 + 1;
  v67->timer = v432;
  int * v74 = v67->regs;
  int v75 = v74[12];
  int * v76 = v67->regs;
  int v77 = v76[14];
  int * v78 = v67->regs;
  int v438 = v75 + v77;
  v78[6] = v438;
  int * v80 = v67->saved_regs;
  int * v81 = v67->regs;
  int v82 = v81[7];
  v80[7] = v82;
  int v84 = v67->timer;
  int v443 = v84 + 1;
  v67->timer = v443;
  int * v86 = v67->regs;
  int v87 = v86[6];
  int * v88 = v67->cache_tags;
  int v446 = (((int)((unsigned int)((int)((unsigned int)v87 >> 2)) >> 1)) & 1) * 2;
  int v89 = v88[v446];
  int * v90 = v67->cache_tags;
  int v448 = ((((int)((unsigned int)((int)((unsigned int)v87 >> 2)) >> 1)) & 1) * 2) + 1;
  int v91 = v90[v448];
  int * v92 = v67->cache_tags;
  int v450 = 4 + ((((int)((unsigned int)((int)((unsigned int)v87 >> 2)) >> 1)) & 3) * 2);
  int v93 = v92[v450];
  int * v94 = v67->cache_tags;
  int v452 = (4 + ((((int)((unsigned int)((int)((unsigned int)v87 >> 2)) >> 1)) & 3) * 2)) + 1;
  int v95 = v94[v452];
  int v96 = v67->timer;
  int v453 = v96 + ((100 ^ (((~(((v93 ^ ((int)((unsigned int)((int)((unsigned int)v87 >> 2)) >> 1))) | (-(v93 ^ ((int)((unsigned int)((int)((unsigned int)v87 >> 2)) >> 1))))) >> 31)) | (~(((v95 ^ ((int)((unsigned int)((int)((unsigned int)v87 >> 2)) >> 1))) | (-(v95 ^ ((int)((unsigned int)((int)((unsigned int)v87 >> 2)) >> 1))))) >> 31))) & 104)) ^ (((~(((v89 ^ ((int)((unsigned int)((int)((unsigned int)v87 >> 2)) >> 1))) | (-(v89 ^ ((int)((unsigned int)((int)((unsigned int)v87 >> 2)) >> 1))))) >> 31)) | (~(((v91 ^ ((int)((unsigned int)((int)((unsigned int)v87 >> 2)) >> 1))) | (-(v91 ^ ((int)((unsigned int)((int)((unsigned int)v87 >> 2)) >> 1))))) >> 31))) & (1 ^ (100 ^ (((~(((v93 ^ ((int)((unsigned int)((int)((unsigned int)v87 >> 2)) >> 1))) | (-(v93 ^ ((int)((unsigned int)((int)((unsigned int)v87 >> 2)) >> 1))))) >> 31)) | (~(((v95 ^ ((int)((unsigned int)((int)((unsigned int)v87 >> 2)) >> 1))) | (-(v95 ^ ((int)((unsigned int)((int)((unsigned int)v87 >> 2)) >> 1))))) >> 31))) & 104)))));
  v67->timer = v453;
  int * v98 = v67->cache_vals;
  bool v454 = !(((~(((v89 ^ ((int)((unsigned int)((int)((unsigned int)v87 >> 2)) >> 1))) | (-(v89 ^ ((int)((unsigned int)((int)((unsigned int)v87 >> 2)) >> 1))))) >> 31)) | (~(((v91 ^ ((int)((unsigned int)((int)((unsigned int)v87 >> 2)) >> 1))) | (-(v91 ^ ((int)((unsigned int)((int)((unsigned int)v87 >> 2)) >> 1))))) >> 31))) == 0);
  int v211;
  if (v454) {
    int * v99 = v67->cache_age;
    int v456 = ((((int)((unsigned int)((int)((unsigned int)v87 >> 2)) >> 1)) & 1) * 2) + ((~(((v91 ^ ((int)((unsigned int)((int)((unsigned int)v87 >> 2)) >> 1))) | (-(v91 ^ ((int)((unsigned int)((int)((unsigned int)v87 >> 2)) >> 1))))) >> 31)) & 1);
    int v100 = v99[v456];
    int * v101 = v67->cache_age;
    int v102 = v101[v446];
    int * v103 = v67->cache_age;
    int v459 = v102 + ((int)((unsigned int)(v102 - v100) >> 31));
    v103[v446] = v459;
    int * v105 = v67->cache_age;
    int v106 = v105[v448];
    int * v107 = v67->cache_age;
    int v462 = v106 + ((int)((unsigned int)(v106 - v100) >> 31));
    v107[v448] = v462;
    int * v109 = v67->cache_age;
    v109[v456] = 0;
    v211 = v456;
  } else {
    int * v112 = v67->cache_age;
    int v466 = (((int)((unsigned int)((int)((unsigned int)v87 >> 2)) >> 1)) & 1) * 2;
    int v113 = v112[v466];
    int * v114 = v67->cache_tags;
    int v115 = v114[v466];
    int * v116 = v67->cache_age;
    int v117 = v116[v448];
    int * v118 = v67->cache_tags;
    int v119 = v118[v448];
    bool v470 = !(((~(((v93 ^ ((int)((unsigned int)((int)((unsigned int)v87 >> 2)) >> 1))) | (-(v93 ^ ((int)((unsigned int)((int)((unsigned int)v87 >> 2)) >> 1))))) >> 31)) | (~(((v95 ^ ((int)((unsigned int)((int)((unsigned int)v87 >> 2)) >> 1))) | (-(v95 ^ ((int)((unsigned int)((int)((unsigned int)v87 >> 2)) >> 1))))) >> 31))) == 0);
    int v183;
    if (v470) {
      int * v120 = v67->cache_age;
      int v472 = (4 + ((((int)((unsigned int)((int)((unsigned int)v87 >> 2)) >> 1)) & 3) * 2)) + ((~(((v95 ^ ((int)((unsigned int)((int)((unsigned int)v87 >> 2)) >> 1))) | (-(v95 ^ ((int)((unsigned int)((int)((unsigned int)v87 >> 2)) >> 1))))) >> 31)) & 1);
      int v121 = v120[v472];
      int * v122 = v67->cache_age;
      int v123 = v122[v450];
      int * v124 = v67->cache_age;
      int v475 = v123 + ((int)((unsigned int)(v123 - v121) >> 31));
      v124[v450] = v475;
      int * v126 = v67->cache_age;
      int v127 = v126[v452];
      int * v128 = v67->cache_age;
      int v478 = v127 + ((int)((unsigned int)(v127 - v121) >> 31));
      v128[v452] = v478;
      int * v130 = v67->cache_age;
      v130[v472] = 0;
      v183 = v472;
    } else {
      int * v133 = v67->cache_age;
      int v482 = 4 + ((((int)((unsigned int)((int)((unsigned int)v87 >> 2)) >> 1)) & 3) * 2);
      int v134 = v133[v482];
      int * v135 = v67->cache_tags;
      int v136 = v135[v482];
      int * v137 = v67->cache_age;
      int v138 = v137[v452];
      int * v139 = v67->cache_tags;
      int v140 = v139[v452];
      int * v141 = v67->cache_dirty;
      int v487 = (4 + ((((int)((unsigned int)((int)((unsigned int)v87 >> 2)) >> 1)) & 3) * 2)) + ((((v134 + ((~(((v136 ^ -1) | (-(v136 ^ -1))) >> 31)) & 2)) - (v138 + ((~(((v140 ^ -1) | (-(v140 ^ -1))) >> 31)) & 2))) >> 31) & 1);
      int v142 = v141[v487];
      bool v488 = !(v142 == 0);
      if (v488) {
        int * v143 = v67->cache_tags;
        int v144 = v143[v487];
        int * v145 = v67->cache_vals;
        int v491 = ((4 + ((((int)((unsigned int)((int)((unsigned int)v87 >> 2)) >> 1)) & 3) * 2)) + ((((v134 + ((~(((v136 ^ -1) | (-(v136 ^ -1))) >> 31)) & 2)) - (v138 + ((~(((v140 ^ -1) | (-(v140 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
        int v146 = v145[v491];
        int * v147 = v67->cache_vals;
        int v493 = (((4 + ((((int)((unsigned int)((int)((unsigned int)v87 >> 2)) >> 1)) & 3) * 2)) + ((((v134 + ((~(((v136 ^ -1) | (-(v136 ^ -1))) >> 31)) & 2)) - (v138 + ((~(((v140 ^ -1) | (-(v140 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
        int v148 = v147[v493];
        int * v149 = v67->mem;
        int v495 = v144 * 2;
        v149[v495] = v146;
        int * v151 = v67->mem;
        int v498 = (v144 * 2) + 1;
        v151[v498] = v148;
        ;
      } else {
        ;
      }
      int * v156 = v67->mem;
      int v503 = ((int)((unsigned int)((int)((unsigned int)v87 >> 2)) >> 1)) * 2;
      int v157 = v156[v503];
      int * v158 = v67->mem;
      int v505 = (((int)((unsigned int)((int)((unsigned int)v87 >> 2)) >> 1)) * 2) + 1;
      int v159 = v158[v505];
      int * v160 = v67->cache_vals;
      int v507 = ((4 + ((((int)((unsigned int)((int)((unsigned int)v87 >> 2)) >> 1)) & 3) * 2)) + ((((v134 + ((~(((v136 ^ -1) | (-(v136 ^ -1))) >> 31)) & 2)) - (v138 + ((~(((v140 ^ -1) | (-(v140 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
      v160[v507] = v157;
      int * v162 = v67->cache_vals;
      int v510 = (((4 + ((((int)((unsigned int)((int)((unsigned int)v87 >> 2)) >> 1)) & 3) * 2)) + ((((v134 + ((~(((v136 ^ -1) | (-(v136 ^ -1))) >> 31)) & 2)) - (v138 + ((~(((v140 ^ -1) | (-(v140 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
      v162[v510] = v159;
      int * v164 = v67->cache_tags;
      int v513 = (int)((unsigned int)((int)((unsigned int)v87 >> 2)) >> 1);
      v164[v487] = v513;
      int * v166 = v67->cache_dirty;
      v166[v487] = 0;
      int * v168 = v67->cache_age;
      v168[v487] = 1;
      int * v170 = v67->cache_age;
      int v171 = v170[v487];
      int * v172 = v67->cache_age;
      int v173 = v172[v450];
      int * v174 = v67->cache_age;
      int v521 = v173 + ((int)((unsigned int)(v173 - v171) >> 31));
      v174[v450] = v521;
      int * v176 = v67->cache_age;
      int v177 = v176[v452];
      int * v178 = v67->cache_age;
      int v524 = v177 + ((int)((unsigned int)(v177 - v171) >> 31));
      v178[v452] = v524;
      int * v180 = v67->cache_age;
      v180[v487] = 0;
      v183 = v487;
    }
    int * v184 = v67->cache_vals;
    int v527 = v183 * 2;
    int v185 = v184[v527];
    int * v186 = v67->cache_vals;
    int v529 = (v183 * 2) + 1;
    int v187 = v186[v529];
    int * v188 = v67->cache_vals;
    int v531 = (((((int)((unsigned int)((int)((unsigned int)v87 >> 2)) >> 1)) & 1) * 2) + ((((v113 + ((~(((v115 ^ -1) | (-(v115 ^ -1))) >> 31)) & 2)) - (v117 + ((~(((v119 ^ -1) | (-(v119 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
    v188[v531] = v185;
    int * v190 = v67->cache_vals;
    int v534 = ((((((int)((unsigned int)((int)((unsigned int)v87 >> 2)) >> 1)) & 1) * 2) + ((((v113 + ((~(((v115 ^ -1) | (-(v115 ^ -1))) >> 31)) & 2)) - (v117 + ((~(((v119 ^ -1) | (-(v119 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
    v190[v534] = v187;
    int * v192 = v67->cache_tags;
    int v537 = ((((int)((unsigned int)((int)((unsigned int)v87 >> 2)) >> 1)) & 1) * 2) + ((((v113 + ((~(((v115 ^ -1) | (-(v115 ^ -1))) >> 31)) & 2)) - (v117 + ((~(((v119 ^ -1) | (-(v119 ^ -1))) >> 31)) & 2))) >> 31) & 1);
    int v538 = (int)((unsigned int)((int)((unsigned int)v87 >> 2)) >> 1);
    v192[v537] = v538;
    int * v194 = v67->cache_dirty;
    v194[v537] = 0;
    int * v196 = v67->cache_age;
    v196[v537] = 1;
    int * v198 = v67->cache_age;
    int v199 = v198[v537];
    int * v200 = v67->cache_age;
    int v201 = v200[v446];
    int * v202 = v67->cache_age;
    int v546 = v201 + ((int)((unsigned int)(v201 - v199) >> 31));
    v202[v446] = v546;
    int * v204 = v67->cache_age;
    int v205 = v204[v448];
    int * v206 = v67->cache_age;
    int v549 = v205 + ((int)((unsigned int)(v205 - v199) >> 31));
    v206[v448] = v549;
    int * v208 = v67->cache_age;
    v208[v537] = 0;
    v211 = v537;
  }
  int v552 = (v211 * 2) + (((int)((unsigned int)v87 >> 2)) & 1);
  int v212 = v98[v552];
  int * v213 = v67->regs;
  v213[7] = v212;
  int * v215 = v67->saved_regs;
  int * v216 = v67->regs;
  int v217 = v216[8];
  v215[8] = v217;
  int v219 = v67->timer;
  int v559 = v219 + 1;
  v67->timer = v559;
  int * v221 = v67->regs;
  int v222 = v221[13];
  int * v223 = v67->regs;
  int v224 = v223[14];
  int * v225 = v67->regs;
  int v564 = v222 + v224;
  v225[8] = v564;
  int * v227 = v67->saved_regs;
  int * v228 = v67->regs;
  int v229 = v228[9];
  v227[9] = v229;
  int v231 = v67->timer;
  int v569 = v231 + 1;
  v67->timer = v569;
  int * v233 = v67->regs;
  int v234 = v233[8];
  int * v235 = v67->cache_tags;
  int v572 = (((int)((unsigned int)((int)((unsigned int)v234 >> 2)) >> 1)) & 1) * 2;
  int v236 = v235[v572];
  int * v237 = v67->cache_tags;
  int v574 = ((((int)((unsigned int)((int)((unsigned int)v234 >> 2)) >> 1)) & 1) * 2) + 1;
  int v238 = v237[v574];
  int * v239 = v67->cache_tags;
  int v576 = 4 + ((((int)((unsigned int)((int)((unsigned int)v234 >> 2)) >> 1)) & 3) * 2);
  int v240 = v239[v576];
  int * v241 = v67->cache_tags;
  int v578 = (4 + ((((int)((unsigned int)((int)((unsigned int)v234 >> 2)) >> 1)) & 3) * 2)) + 1;
  int v242 = v241[v578];
  int v243 = v67->timer;
  int v579 = v243 + ((100 ^ (((~(((v240 ^ ((int)((unsigned int)((int)((unsigned int)v234 >> 2)) >> 1))) | (-(v240 ^ ((int)((unsigned int)((int)((unsigned int)v234 >> 2)) >> 1))))) >> 31)) | (~(((v242 ^ ((int)((unsigned int)((int)((unsigned int)v234 >> 2)) >> 1))) | (-(v242 ^ ((int)((unsigned int)((int)((unsigned int)v234 >> 2)) >> 1))))) >> 31))) & 104)) ^ (((~(((v236 ^ ((int)((unsigned int)((int)((unsigned int)v234 >> 2)) >> 1))) | (-(v236 ^ ((int)((unsigned int)((int)((unsigned int)v234 >> 2)) >> 1))))) >> 31)) | (~(((v238 ^ ((int)((unsigned int)((int)((unsigned int)v234 >> 2)) >> 1))) | (-(v238 ^ ((int)((unsigned int)((int)((unsigned int)v234 >> 2)) >> 1))))) >> 31))) & (1 ^ (100 ^ (((~(((v240 ^ ((int)((unsigned int)((int)((unsigned int)v234 >> 2)) >> 1))) | (-(v240 ^ ((int)((unsigned int)((int)((unsigned int)v234 >> 2)) >> 1))))) >> 31)) | (~(((v242 ^ ((int)((unsigned int)((int)((unsigned int)v234 >> 2)) >> 1))) | (-(v242 ^ ((int)((unsigned int)((int)((unsigned int)v234 >> 2)) >> 1))))) >> 31))) & 104)))));
  v67->timer = v579;
  int * v245 = v67->cache_vals;
  bool v580 = !(((~(((v236 ^ ((int)((unsigned int)((int)((unsigned int)v234 >> 2)) >> 1))) | (-(v236 ^ ((int)((unsigned int)((int)((unsigned int)v234 >> 2)) >> 1))))) >> 31)) | (~(((v238 ^ ((int)((unsigned int)((int)((unsigned int)v234 >> 2)) >> 1))) | (-(v238 ^ ((int)((unsigned int)((int)((unsigned int)v234 >> 2)) >> 1))))) >> 31))) == 0);
  int v358;
  if (v580) {
    int * v246 = v67->cache_age;
    int v582 = ((((int)((unsigned int)((int)((unsigned int)v234 >> 2)) >> 1)) & 1) * 2) + ((~(((v238 ^ ((int)((unsigned int)((int)((unsigned int)v234 >> 2)) >> 1))) | (-(v238 ^ ((int)((unsigned int)((int)((unsigned int)v234 >> 2)) >> 1))))) >> 31)) & 1);
    int v247 = v246[v582];
    int * v248 = v67->cache_age;
    int v249 = v248[v572];
    int * v250 = v67->cache_age;
    int v585 = v249 + ((int)((unsigned int)(v249 - v247) >> 31));
    v250[v572] = v585;
    int * v252 = v67->cache_age;
    int v253 = v252[v574];
    int * v254 = v67->cache_age;
    int v588 = v253 + ((int)((unsigned int)(v253 - v247) >> 31));
    v254[v574] = v588;
    int * v256 = v67->cache_age;
    v256[v582] = 0;
    v358 = v582;
  } else {
    int * v259 = v67->cache_age;
    int v592 = (((int)((unsigned int)((int)((unsigned int)v234 >> 2)) >> 1)) & 1) * 2;
    int v260 = v259[v592];
    int * v261 = v67->cache_tags;
    int v262 = v261[v592];
    int * v263 = v67->cache_age;
    int v264 = v263[v574];
    int * v265 = v67->cache_tags;
    int v266 = v265[v574];
    bool v596 = !(((~(((v240 ^ ((int)((unsigned int)((int)((unsigned int)v234 >> 2)) >> 1))) | (-(v240 ^ ((int)((unsigned int)((int)((unsigned int)v234 >> 2)) >> 1))))) >> 31)) | (~(((v242 ^ ((int)((unsigned int)((int)((unsigned int)v234 >> 2)) >> 1))) | (-(v242 ^ ((int)((unsigned int)((int)((unsigned int)v234 >> 2)) >> 1))))) >> 31))) == 0);
    int v330;
    if (v596) {
      int * v267 = v67->cache_age;
      int v598 = (4 + ((((int)((unsigned int)((int)((unsigned int)v234 >> 2)) >> 1)) & 3) * 2)) + ((~(((v242 ^ ((int)((unsigned int)((int)((unsigned int)v234 >> 2)) >> 1))) | (-(v242 ^ ((int)((unsigned int)((int)((unsigned int)v234 >> 2)) >> 1))))) >> 31)) & 1);
      int v268 = v267[v598];
      int * v269 = v67->cache_age;
      int v270 = v269[v576];
      int * v271 = v67->cache_age;
      int v601 = v270 + ((int)((unsigned int)(v270 - v268) >> 31));
      v271[v576] = v601;
      int * v273 = v67->cache_age;
      int v274 = v273[v578];
      int * v275 = v67->cache_age;
      int v604 = v274 + ((int)((unsigned int)(v274 - v268) >> 31));
      v275[v578] = v604;
      int * v277 = v67->cache_age;
      v277[v598] = 0;
      v330 = v598;
    } else {
      int * v280 = v67->cache_age;
      int v608 = 4 + ((((int)((unsigned int)((int)((unsigned int)v234 >> 2)) >> 1)) & 3) * 2);
      int v281 = v280[v608];
      int * v282 = v67->cache_tags;
      int v283 = v282[v608];
      int * v284 = v67->cache_age;
      int v285 = v284[v578];
      int * v286 = v67->cache_tags;
      int v287 = v286[v578];
      int * v288 = v67->cache_dirty;
      int v613 = (4 + ((((int)((unsigned int)((int)((unsigned int)v234 >> 2)) >> 1)) & 3) * 2)) + ((((v281 + ((~(((v283 ^ -1) | (-(v283 ^ -1))) >> 31)) & 2)) - (v285 + ((~(((v287 ^ -1) | (-(v287 ^ -1))) >> 31)) & 2))) >> 31) & 1);
      int v289 = v288[v613];
      bool v614 = !(v289 == 0);
      if (v614) {
        int * v290 = v67->cache_tags;
        int v291 = v290[v613];
        int * v292 = v67->cache_vals;
        int v617 = ((4 + ((((int)((unsigned int)((int)((unsigned int)v234 >> 2)) >> 1)) & 3) * 2)) + ((((v281 + ((~(((v283 ^ -1) | (-(v283 ^ -1))) >> 31)) & 2)) - (v285 + ((~(((v287 ^ -1) | (-(v287 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
        int v293 = v292[v617];
        int * v294 = v67->cache_vals;
        int v619 = (((4 + ((((int)((unsigned int)((int)((unsigned int)v234 >> 2)) >> 1)) & 3) * 2)) + ((((v281 + ((~(((v283 ^ -1) | (-(v283 ^ -1))) >> 31)) & 2)) - (v285 + ((~(((v287 ^ -1) | (-(v287 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
        int v295 = v294[v619];
        int * v296 = v67->mem;
        int v621 = v291 * 2;
        v296[v621] = v293;
        int * v298 = v67->mem;
        int v624 = (v291 * 2) + 1;
        v298[v624] = v295;
        ;
      } else {
        ;
      }
      int * v303 = v67->mem;
      int v629 = ((int)((unsigned int)((int)((unsigned int)v234 >> 2)) >> 1)) * 2;
      int v304 = v303[v629];
      int * v305 = v67->mem;
      int v631 = (((int)((unsigned int)((int)((unsigned int)v234 >> 2)) >> 1)) * 2) + 1;
      int v306 = v305[v631];
      int * v307 = v67->cache_vals;
      int v633 = ((4 + ((((int)((unsigned int)((int)((unsigned int)v234 >> 2)) >> 1)) & 3) * 2)) + ((((v281 + ((~(((v283 ^ -1) | (-(v283 ^ -1))) >> 31)) & 2)) - (v285 + ((~(((v287 ^ -1) | (-(v287 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
      v307[v633] = v304;
      int * v309 = v67->cache_vals;
      int v636 = (((4 + ((((int)((unsigned int)((int)((unsigned int)v234 >> 2)) >> 1)) & 3) * 2)) + ((((v281 + ((~(((v283 ^ -1) | (-(v283 ^ -1))) >> 31)) & 2)) - (v285 + ((~(((v287 ^ -1) | (-(v287 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
      v309[v636] = v306;
      int * v311 = v67->cache_tags;
      int v639 = (int)((unsigned int)((int)((unsigned int)v234 >> 2)) >> 1);
      v311[v613] = v639;
      int * v313 = v67->cache_dirty;
      v313[v613] = 0;
      int * v315 = v67->cache_age;
      v315[v613] = 1;
      int * v317 = v67->cache_age;
      int v318 = v317[v613];
      int * v319 = v67->cache_age;
      int v320 = v319[v576];
      int * v321 = v67->cache_age;
      int v647 = v320 + ((int)((unsigned int)(v320 - v318) >> 31));
      v321[v576] = v647;
      int * v323 = v67->cache_age;
      int v324 = v323[v578];
      int * v325 = v67->cache_age;
      int v650 = v324 + ((int)((unsigned int)(v324 - v318) >> 31));
      v325[v578] = v650;
      int * v327 = v67->cache_age;
      v327[v613] = 0;
      v330 = v613;
    }
    int * v331 = v67->cache_vals;
    int v653 = v330 * 2;
    int v332 = v331[v653];
    int * v333 = v67->cache_vals;
    int v655 = (v330 * 2) + 1;
    int v334 = v333[v655];
    int * v335 = v67->cache_vals;
    int v657 = (((((int)((unsigned int)((int)((unsigned int)v234 >> 2)) >> 1)) & 1) * 2) + ((((v260 + ((~(((v262 ^ -1) | (-(v262 ^ -1))) >> 31)) & 2)) - (v264 + ((~(((v266 ^ -1) | (-(v266 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
    v335[v657] = v332;
    int * v337 = v67->cache_vals;
    int v660 = ((((((int)((unsigned int)((int)((unsigned int)v234 >> 2)) >> 1)) & 1) * 2) + ((((v260 + ((~(((v262 ^ -1) | (-(v262 ^ -1))) >> 31)) & 2)) - (v264 + ((~(((v266 ^ -1) | (-(v266 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
    v337[v660] = v334;
    int * v339 = v67->cache_tags;
    int v663 = ((((int)((unsigned int)((int)((unsigned int)v234 >> 2)) >> 1)) & 1) * 2) + ((((v260 + ((~(((v262 ^ -1) | (-(v262 ^ -1))) >> 31)) & 2)) - (v264 + ((~(((v266 ^ -1) | (-(v266 ^ -1))) >> 31)) & 2))) >> 31) & 1);
    int v664 = (int)((unsigned int)((int)((unsigned int)v234 >> 2)) >> 1);
    v339[v663] = v664;
    int * v341 = v67->cache_dirty;
    v341[v663] = 0;
    int * v343 = v67->cache_age;
    v343[v663] = 1;
    int * v345 = v67->cache_age;
    int v346 = v345[v663];
    int * v347 = v67->cache_age;
    int v348 = v347[v572];
    int * v349 = v67->cache_age;
    int v672 = v348 + ((int)((unsigned int)(v348 - v346) >> 31));
    v349[v572] = v672;
    int * v351 = v67->cache_age;
    int v352 = v351[v574];
    int * v353 = v67->cache_age;
    int v675 = v352 + ((int)((unsigned int)(v352 - v346) >> 31));
    v353[v574] = v675;
    int * v355 = v67->cache_age;
    v355[v663] = 0;
    v358 = v663;
  }
  int v678 = (v358 * 2) + (((int)((unsigned int)v234 >> 2)) & 1);
  int v359 = v245[v678];
  int * v360 = v67->regs;
  v360[9] = v359;
  int * v362 = v67->saved_regs;
  int * v363 = v67->regs;
  int v364 = v363[16];
  v362[16] = v364;
  int v366 = v67->timer;
  int v685 = v366 + 1;
  v67->timer = v685;
  int * v368 = v67->regs;
  int v369 = v368[7];
  int * v370 = v67->regs;
  int v371 = v370[9];
  int * v372 = v67->regs;
  int v689 = v369 ^ v371;
  v372[16] = v689;
  int * v374 = v67->saved_regs;
  int * v375 = v67->regs;
  int v376 = v375[5];
  v374[5] = v376;
  int v378 = v67->timer;
  int v694 = v378 + 1;
  v67->timer = v694;
  int * v380 = v67->regs;
  int v381 = v380[5];
  int * v382 = v67->regs;
  int v383 = v382[16];
  int * v384 = v67->regs;
  int v698 = v381 | v383;
  v384[5] = v698;
  int * v386 = v67->regs;
  int v387 = v386[14];
  int * v388 = v67->regs;
  int v389 = v388[15];
  bool v702 = v387 >= v389;
  struct StateT * v426;
  if (v702) {
    int v390 = v67->timer;
    int v703 = v390 + 15;
    v67->timer = v703;
    int * v392 = v67->saved_regs;
    int v393 = v392[6];
    int * v394 = v67->regs;
    v394[6] = v393;
    int * v396 = v67->saved_regs;
    int v397 = v396[7];
    int * v398 = v67->regs;
    v398[7] = v397;
    int * v400 = v67->saved_regs;
    int v401 = v400[8];
    int * v402 = v67->regs;
    v402[8] = v401;
    int * v404 = v67->saved_regs;
    int v405 = v404[9];
    int * v406 = v67->regs;
    v406[9] = v405;
    int * v408 = v67->saved_regs;
    int v409 = v408[16];
    int * v410 = v67->regs;
    v410[16] = v409;
    int * v412 = v67->saved_regs;
    int v413 = v412[5];
    int * v414 = v67->regs;
    v414[5] = v413;
    struct StateT * v416 = slot_14(v67);
    v426 = v416;
  } else {
    int v418 = v67->timer;
    int v724 = v418 + 1;
    v67->timer = v724;
    int * v420 = v67->regs;
    int v421 = v420[14];
    int * v422 = v67->regs;
    int v727 = v421 + 4;
    v422[14] = v727;
    struct StateT * v424 = slot_13(v67);
    v426 = v424;
  }
  return v426;
}

struct StateT * slot_4(struct StateT * v54) {
  int v55 = v54->timer;
  int v61 = v55 + 1;
  v54->timer = v61;
  int * v57 = v54->regs;
  v57[5] = 0;
  struct StateT * v59 = slot_5(v54);
  return v59;
}

struct StateT * slot_13(struct StateT * v751) {
  int v752 = v751->timer;
  int v756 = v752 + 1;
  v751->timer = v756;
  struct StateT * v754 = slot_5(v751);
  return v754;
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

struct StateT * slot_3(struct StateT * v41) {
  int v42 = v41->timer;
  int v48 = v42 + 1;
  v41->timer = v48;
  int * v44 = v41->regs;
  v44[15] = 16;
  struct StateT * v46 = slot_4(v41);
  return v46;
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