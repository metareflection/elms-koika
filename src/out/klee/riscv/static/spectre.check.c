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

struct StateT * snippet(struct StateT * v0);
struct StateT * slot_1(struct StateT * v15);
struct StateT * slot_8(struct StateT * v607);
struct StateT * slot_6(struct StateT * v334);
struct StateT * slot_5(struct StateT * v77);
struct StateT * slot_4(struct StateT * v49);
struct StateT * slot_2(struct StateT * v28);
struct StateT * slot_7(struct StateT * v350);
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

struct StateT * slot_8(struct StateT * v607) {
  int * v608 = v607->regs;
  int v609 = v608[10];
  int * v610 = v607->regs;
  int v611 = v610[15];
  bool v634 = v609 >= v611;
  struct StateT * v628;
  if (v634) {
    int v612 = v607->timer;
    int v635 = v612 + 15;
    v607->timer = v635;
    int * v614 = v607->saved_regs;
    int v615 = v614[5];
    int * v616 = v607->regs;
    v616[5] = v615;
    int * v618 = v607->saved_regs;
    int v619 = v618[11];
    int * v620 = v607->regs;
    v620[11] = v619;
    int * v622 = v607->saved_regs;
    int v623 = v622[12];
    int * v624 = v607->regs;
    v624[12] = v623;
    v628 = v607;
  } else {
    v628 = v607;
  }
  return v628;
}

struct StateT * slot_6(struct StateT * v334) {
  int v335 = v334->timer;
  int v343 = v335 + 1;
  v334->timer = v343;
  int * v337 = v334->regs;
  int v338 = v337[11];
  int * v339 = v334->regs;
  int v347 = v338 << 2;
  v339[11] = v347;
  struct StateT * v341 = slot_7(v334);
  return v341;
}

struct StateT * slot_5(struct StateT * v77) {
  int * v78 = v77->saved_regs;
  int * v79 = v77->regs;
  int v80 = v79[11];
  v78[11] = v80;
  int v82 = v77->timer;
  int v219 = v82 + 1;
  v77->timer = v219;
  int * v84 = v77->regs;
  int v85 = v84[5];
  int * v86 = v77->cache_tags;
  int v223 = (((int)((unsigned int)((int)((unsigned int)v85 >> 2)) >> 1)) & 1) * 2;
  int v87 = v86[v223];
  int * v88 = v77->cache_tags;
  int v225 = ((((int)((unsigned int)((int)((unsigned int)v85 >> 2)) >> 1)) & 1) * 2) + 1;
  int v89 = v88[v225];
  int * v90 = v77->cache_tags;
  int v227 = 4 + ((((int)((unsigned int)((int)((unsigned int)v85 >> 2)) >> 1)) & 3) * 2);
  int v91 = v90[v227];
  int * v92 = v77->cache_tags;
  int v229 = (4 + ((((int)((unsigned int)((int)((unsigned int)v85 >> 2)) >> 1)) & 3) * 2)) + 1;
  int v93 = v92[v229];
  int v94 = v77->timer;
  int v230 = v94 + ((100 ^ (((~(((v91 ^ ((int)((unsigned int)((int)((unsigned int)v85 >> 2)) >> 1))) | (-(v91 ^ ((int)((unsigned int)((int)((unsigned int)v85 >> 2)) >> 1))))) >> 31)) | (~(((v93 ^ ((int)((unsigned int)((int)((unsigned int)v85 >> 2)) >> 1))) | (-(v93 ^ ((int)((unsigned int)((int)((unsigned int)v85 >> 2)) >> 1))))) >> 31))) & 104)) ^ (((~(((v87 ^ ((int)((unsigned int)((int)((unsigned int)v85 >> 2)) >> 1))) | (-(v87 ^ ((int)((unsigned int)((int)((unsigned int)v85 >> 2)) >> 1))))) >> 31)) | (~(((v89 ^ ((int)((unsigned int)((int)((unsigned int)v85 >> 2)) >> 1))) | (-(v89 ^ ((int)((unsigned int)((int)((unsigned int)v85 >> 2)) >> 1))))) >> 31))) & (1 ^ (100 ^ (((~(((v91 ^ ((int)((unsigned int)((int)((unsigned int)v85 >> 2)) >> 1))) | (-(v91 ^ ((int)((unsigned int)((int)((unsigned int)v85 >> 2)) >> 1))))) >> 31)) | (~(((v93 ^ ((int)((unsigned int)((int)((unsigned int)v85 >> 2)) >> 1))) | (-(v93 ^ ((int)((unsigned int)((int)((unsigned int)v85 >> 2)) >> 1))))) >> 31))) & 104)))));
  v77->timer = v230;
  int * v96 = v77->cache_vals;
  bool v231 = !(((~(((v87 ^ ((int)((unsigned int)((int)((unsigned int)v85 >> 2)) >> 1))) | (-(v87 ^ ((int)((unsigned int)((int)((unsigned int)v85 >> 2)) >> 1))))) >> 31)) | (~(((v89 ^ ((int)((unsigned int)((int)((unsigned int)v85 >> 2)) >> 1))) | (-(v89 ^ ((int)((unsigned int)((int)((unsigned int)v85 >> 2)) >> 1))))) >> 31))) == 0);
  int v209;
  if (v231) {
    int * v97 = v77->cache_age;
    int v233 = ((((int)((unsigned int)((int)((unsigned int)v85 >> 2)) >> 1)) & 1) * 2) + ((~(((v89 ^ ((int)((unsigned int)((int)((unsigned int)v85 >> 2)) >> 1))) | (-(v89 ^ ((int)((unsigned int)((int)((unsigned int)v85 >> 2)) >> 1))))) >> 31)) & 1);
    int v98 = v97[v233];
    int * v99 = v77->cache_age;
    int v100 = v99[v223];
    int * v101 = v77->cache_age;
    int v236 = v100 + ((int)((unsigned int)(v100 - v98) >> 31));
    v101[v223] = v236;
    int * v103 = v77->cache_age;
    int v104 = v103[v225];
    int * v105 = v77->cache_age;
    int v239 = v104 + ((int)((unsigned int)(v104 - v98) >> 31));
    v105[v225] = v239;
    int * v107 = v77->cache_age;
    v107[v233] = 0;
    v209 = v233;
  } else {
    int * v110 = v77->cache_age;
    int v243 = (((int)((unsigned int)((int)((unsigned int)v85 >> 2)) >> 1)) & 1) * 2;
    int v111 = v110[v243];
    int * v112 = v77->cache_tags;
    int v113 = v112[v243];
    int * v114 = v77->cache_age;
    int v115 = v114[v225];
    int * v116 = v77->cache_tags;
    int v117 = v116[v225];
    bool v247 = !(((~(((v91 ^ ((int)((unsigned int)((int)((unsigned int)v85 >> 2)) >> 1))) | (-(v91 ^ ((int)((unsigned int)((int)((unsigned int)v85 >> 2)) >> 1))))) >> 31)) | (~(((v93 ^ ((int)((unsigned int)((int)((unsigned int)v85 >> 2)) >> 1))) | (-(v93 ^ ((int)((unsigned int)((int)((unsigned int)v85 >> 2)) >> 1))))) >> 31))) == 0);
    int v181;
    if (v247) {
      int * v118 = v77->cache_age;
      int v249 = (4 + ((((int)((unsigned int)((int)((unsigned int)v85 >> 2)) >> 1)) & 3) * 2)) + ((~(((v93 ^ ((int)((unsigned int)((int)((unsigned int)v85 >> 2)) >> 1))) | (-(v93 ^ ((int)((unsigned int)((int)((unsigned int)v85 >> 2)) >> 1))))) >> 31)) & 1);
      int v119 = v118[v249];
      int * v120 = v77->cache_age;
      int v121 = v120[v227];
      int * v122 = v77->cache_age;
      int v252 = v121 + ((int)((unsigned int)(v121 - v119) >> 31));
      v122[v227] = v252;
      int * v124 = v77->cache_age;
      int v125 = v124[v229];
      int * v126 = v77->cache_age;
      int v255 = v125 + ((int)((unsigned int)(v125 - v119) >> 31));
      v126[v229] = v255;
      int * v128 = v77->cache_age;
      v128[v249] = 0;
      v181 = v249;
    } else {
      int * v131 = v77->cache_age;
      int v259 = 4 + ((((int)((unsigned int)((int)((unsigned int)v85 >> 2)) >> 1)) & 3) * 2);
      int v132 = v131[v259];
      int * v133 = v77->cache_tags;
      int v134 = v133[v259];
      int * v135 = v77->cache_age;
      int v136 = v135[v229];
      int * v137 = v77->cache_tags;
      int v138 = v137[v229];
      int * v139 = v77->cache_dirty;
      int v264 = (4 + ((((int)((unsigned int)((int)((unsigned int)v85 >> 2)) >> 1)) & 3) * 2)) + ((((v132 + ((~(((v134 ^ -1) | (-(v134 ^ -1))) >> 31)) & 2)) - (v136 + ((~(((v138 ^ -1) | (-(v138 ^ -1))) >> 31)) & 2))) >> 31) & 1);
      int v140 = v139[v264];
      bool v265 = !(v140 == 0);
      if (v265) {
        int * v141 = v77->cache_tags;
        int v142 = v141[v264];
        int * v143 = v77->cache_vals;
        int v268 = ((4 + ((((int)((unsigned int)((int)((unsigned int)v85 >> 2)) >> 1)) & 3) * 2)) + ((((v132 + ((~(((v134 ^ -1) | (-(v134 ^ -1))) >> 31)) & 2)) - (v136 + ((~(((v138 ^ -1) | (-(v138 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
        int v144 = v143[v268];
        int * v145 = v77->cache_vals;
        int v270 = (((4 + ((((int)((unsigned int)((int)((unsigned int)v85 >> 2)) >> 1)) & 3) * 2)) + ((((v132 + ((~(((v134 ^ -1) | (-(v134 ^ -1))) >> 31)) & 2)) - (v136 + ((~(((v138 ^ -1) | (-(v138 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
        int v146 = v145[v270];
        int * v147 = v77->mem;
        int v272 = v142 * 2;
        v147[v272] = v144;
        int * v149 = v77->mem;
        int v275 = (v142 * 2) + 1;
        v149[v275] = v146;
        ;
      } else {
        ;
      }
      int * v154 = v77->mem;
      int v280 = ((int)((unsigned int)((int)((unsigned int)v85 >> 2)) >> 1)) * 2;
      int v155 = v154[v280];
      int * v156 = v77->mem;
      int v282 = (((int)((unsigned int)((int)((unsigned int)v85 >> 2)) >> 1)) * 2) + 1;
      int v157 = v156[v282];
      int * v158 = v77->cache_vals;
      int v284 = ((4 + ((((int)((unsigned int)((int)((unsigned int)v85 >> 2)) >> 1)) & 3) * 2)) + ((((v132 + ((~(((v134 ^ -1) | (-(v134 ^ -1))) >> 31)) & 2)) - (v136 + ((~(((v138 ^ -1) | (-(v138 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
      v158[v284] = v155;
      int * v160 = v77->cache_vals;
      int v287 = (((4 + ((((int)((unsigned int)((int)((unsigned int)v85 >> 2)) >> 1)) & 3) * 2)) + ((((v132 + ((~(((v134 ^ -1) | (-(v134 ^ -1))) >> 31)) & 2)) - (v136 + ((~(((v138 ^ -1) | (-(v138 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
      v160[v287] = v157;
      int * v162 = v77->cache_tags;
      int v290 = (int)((unsigned int)((int)((unsigned int)v85 >> 2)) >> 1);
      v162[v264] = v290;
      int * v164 = v77->cache_dirty;
      v164[v264] = 0;
      int * v166 = v77->cache_age;
      v166[v264] = 1;
      int * v168 = v77->cache_age;
      int v169 = v168[v264];
      int * v170 = v77->cache_age;
      int v171 = v170[v227];
      int * v172 = v77->cache_age;
      int v298 = v171 + ((int)((unsigned int)(v171 - v169) >> 31));
      v172[v227] = v298;
      int * v174 = v77->cache_age;
      int v175 = v174[v229];
      int * v176 = v77->cache_age;
      int v301 = v175 + ((int)((unsigned int)(v175 - v169) >> 31));
      v176[v229] = v301;
      int * v178 = v77->cache_age;
      v178[v264] = 0;
      v181 = v264;
    }
    int * v182 = v77->cache_vals;
    int v304 = v181 * 2;
    int v183 = v182[v304];
    int * v184 = v77->cache_vals;
    int v306 = (v181 * 2) + 1;
    int v185 = v184[v306];
    int * v186 = v77->cache_vals;
    int v308 = (((((int)((unsigned int)((int)((unsigned int)v85 >> 2)) >> 1)) & 1) * 2) + ((((v111 + ((~(((v113 ^ -1) | (-(v113 ^ -1))) >> 31)) & 2)) - (v115 + ((~(((v117 ^ -1) | (-(v117 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
    v186[v308] = v183;
    int * v188 = v77->cache_vals;
    int v311 = ((((((int)((unsigned int)((int)((unsigned int)v85 >> 2)) >> 1)) & 1) * 2) + ((((v111 + ((~(((v113 ^ -1) | (-(v113 ^ -1))) >> 31)) & 2)) - (v115 + ((~(((v117 ^ -1) | (-(v117 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
    v188[v311] = v185;
    int * v190 = v77->cache_tags;
    int v314 = ((((int)((unsigned int)((int)((unsigned int)v85 >> 2)) >> 1)) & 1) * 2) + ((((v111 + ((~(((v113 ^ -1) | (-(v113 ^ -1))) >> 31)) & 2)) - (v115 + ((~(((v117 ^ -1) | (-(v117 ^ -1))) >> 31)) & 2))) >> 31) & 1);
    int v315 = (int)((unsigned int)((int)((unsigned int)v85 >> 2)) >> 1);
    v190[v314] = v315;
    int * v192 = v77->cache_dirty;
    v192[v314] = 0;
    int * v194 = v77->cache_age;
    v194[v314] = 1;
    int * v196 = v77->cache_age;
    int v197 = v196[v314];
    int * v198 = v77->cache_age;
    int v199 = v198[v223];
    int * v200 = v77->cache_age;
    int v323 = v199 + ((int)((unsigned int)(v199 - v197) >> 31));
    v200[v223] = v323;
    int * v202 = v77->cache_age;
    int v203 = v202[v225];
    int * v204 = v77->cache_age;
    int v326 = v203 + ((int)((unsigned int)(v203 - v197) >> 31));
    v204[v225] = v326;
    int * v206 = v77->cache_age;
    v206[v314] = 0;
    v209 = v314;
  }
  int v329 = (v209 * 2) + (((int)((unsigned int)v85 >> 2)) & 1);
  int v210 = v96[v329];
  int * v211 = v77->regs;
  v211[11] = v210;
  struct StateT * v213 = slot_6(v77);
  return v213;
}

struct StateT * slot_4(struct StateT * v49) {
  int * v50 = v49->saved_regs;
  int * v51 = v49->regs;
  int v52 = v51[5];
  v50[5] = v52;
  int v54 = v49->timer;
  int v68 = v54 + 1;
  v49->timer = v68;
  int * v56 = v49->regs;
  int v57 = v56[13];
  int * v58 = v49->regs;
  int v59 = v58[10];
  int * v60 = v49->regs;
  int v74 = v57 + v59;
  v60[5] = v74;
  struct StateT * v62 = slot_5(v49);
  return v62;
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

struct StateT * slot_7(struct StateT * v350) {
  int * v351 = v350->saved_regs;
  int * v352 = v350->regs;
  int v353 = v352[12];
  v351[12] = v353;
  int v355 = v350->timer;
  int v492 = v355 + 1;
  v350->timer = v492;
  int * v357 = v350->regs;
  int v358 = v357[11];
  int * v359 = v350->cache_tags;
  int v496 = (((int)((unsigned int)((int)((unsigned int)v358 >> 2)) >> 1)) & 1) * 2;
  int v360 = v359[v496];
  int * v361 = v350->cache_tags;
  int v498 = ((((int)((unsigned int)((int)((unsigned int)v358 >> 2)) >> 1)) & 1) * 2) + 1;
  int v362 = v361[v498];
  int * v363 = v350->cache_tags;
  int v500 = 4 + ((((int)((unsigned int)((int)((unsigned int)v358 >> 2)) >> 1)) & 3) * 2);
  int v364 = v363[v500];
  int * v365 = v350->cache_tags;
  int v502 = (4 + ((((int)((unsigned int)((int)((unsigned int)v358 >> 2)) >> 1)) & 3) * 2)) + 1;
  int v366 = v365[v502];
  int v367 = v350->timer;
  int v503 = v367 + ((100 ^ (((~(((v364 ^ ((int)((unsigned int)((int)((unsigned int)v358 >> 2)) >> 1))) | (-(v364 ^ ((int)((unsigned int)((int)((unsigned int)v358 >> 2)) >> 1))))) >> 31)) | (~(((v366 ^ ((int)((unsigned int)((int)((unsigned int)v358 >> 2)) >> 1))) | (-(v366 ^ ((int)((unsigned int)((int)((unsigned int)v358 >> 2)) >> 1))))) >> 31))) & 104)) ^ (((~(((v360 ^ ((int)((unsigned int)((int)((unsigned int)v358 >> 2)) >> 1))) | (-(v360 ^ ((int)((unsigned int)((int)((unsigned int)v358 >> 2)) >> 1))))) >> 31)) | (~(((v362 ^ ((int)((unsigned int)((int)((unsigned int)v358 >> 2)) >> 1))) | (-(v362 ^ ((int)((unsigned int)((int)((unsigned int)v358 >> 2)) >> 1))))) >> 31))) & (1 ^ (100 ^ (((~(((v364 ^ ((int)((unsigned int)((int)((unsigned int)v358 >> 2)) >> 1))) | (-(v364 ^ ((int)((unsigned int)((int)((unsigned int)v358 >> 2)) >> 1))))) >> 31)) | (~(((v366 ^ ((int)((unsigned int)((int)((unsigned int)v358 >> 2)) >> 1))) | (-(v366 ^ ((int)((unsigned int)((int)((unsigned int)v358 >> 2)) >> 1))))) >> 31))) & 104)))));
  v350->timer = v503;
  int * v369 = v350->cache_vals;
  bool v504 = !(((~(((v360 ^ ((int)((unsigned int)((int)((unsigned int)v358 >> 2)) >> 1))) | (-(v360 ^ ((int)((unsigned int)((int)((unsigned int)v358 >> 2)) >> 1))))) >> 31)) | (~(((v362 ^ ((int)((unsigned int)((int)((unsigned int)v358 >> 2)) >> 1))) | (-(v362 ^ ((int)((unsigned int)((int)((unsigned int)v358 >> 2)) >> 1))))) >> 31))) == 0);
  int v482;
  if (v504) {
    int * v370 = v350->cache_age;
    int v506 = ((((int)((unsigned int)((int)((unsigned int)v358 >> 2)) >> 1)) & 1) * 2) + ((~(((v362 ^ ((int)((unsigned int)((int)((unsigned int)v358 >> 2)) >> 1))) | (-(v362 ^ ((int)((unsigned int)((int)((unsigned int)v358 >> 2)) >> 1))))) >> 31)) & 1);
    int v371 = v370[v506];
    int * v372 = v350->cache_age;
    int v373 = v372[v496];
    int * v374 = v350->cache_age;
    int v509 = v373 + ((int)((unsigned int)(v373 - v371) >> 31));
    v374[v496] = v509;
    int * v376 = v350->cache_age;
    int v377 = v376[v498];
    int * v378 = v350->cache_age;
    int v512 = v377 + ((int)((unsigned int)(v377 - v371) >> 31));
    v378[v498] = v512;
    int * v380 = v350->cache_age;
    v380[v506] = 0;
    v482 = v506;
  } else {
    int * v383 = v350->cache_age;
    int v516 = (((int)((unsigned int)((int)((unsigned int)v358 >> 2)) >> 1)) & 1) * 2;
    int v384 = v383[v516];
    int * v385 = v350->cache_tags;
    int v386 = v385[v516];
    int * v387 = v350->cache_age;
    int v388 = v387[v498];
    int * v389 = v350->cache_tags;
    int v390 = v389[v498];
    bool v520 = !(((~(((v364 ^ ((int)((unsigned int)((int)((unsigned int)v358 >> 2)) >> 1))) | (-(v364 ^ ((int)((unsigned int)((int)((unsigned int)v358 >> 2)) >> 1))))) >> 31)) | (~(((v366 ^ ((int)((unsigned int)((int)((unsigned int)v358 >> 2)) >> 1))) | (-(v366 ^ ((int)((unsigned int)((int)((unsigned int)v358 >> 2)) >> 1))))) >> 31))) == 0);
    int v454;
    if (v520) {
      int * v391 = v350->cache_age;
      int v522 = (4 + ((((int)((unsigned int)((int)((unsigned int)v358 >> 2)) >> 1)) & 3) * 2)) + ((~(((v366 ^ ((int)((unsigned int)((int)((unsigned int)v358 >> 2)) >> 1))) | (-(v366 ^ ((int)((unsigned int)((int)((unsigned int)v358 >> 2)) >> 1))))) >> 31)) & 1);
      int v392 = v391[v522];
      int * v393 = v350->cache_age;
      int v394 = v393[v500];
      int * v395 = v350->cache_age;
      int v525 = v394 + ((int)((unsigned int)(v394 - v392) >> 31));
      v395[v500] = v525;
      int * v397 = v350->cache_age;
      int v398 = v397[v502];
      int * v399 = v350->cache_age;
      int v528 = v398 + ((int)((unsigned int)(v398 - v392) >> 31));
      v399[v502] = v528;
      int * v401 = v350->cache_age;
      v401[v522] = 0;
      v454 = v522;
    } else {
      int * v404 = v350->cache_age;
      int v532 = 4 + ((((int)((unsigned int)((int)((unsigned int)v358 >> 2)) >> 1)) & 3) * 2);
      int v405 = v404[v532];
      int * v406 = v350->cache_tags;
      int v407 = v406[v532];
      int * v408 = v350->cache_age;
      int v409 = v408[v502];
      int * v410 = v350->cache_tags;
      int v411 = v410[v502];
      int * v412 = v350->cache_dirty;
      int v537 = (4 + ((((int)((unsigned int)((int)((unsigned int)v358 >> 2)) >> 1)) & 3) * 2)) + ((((v405 + ((~(((v407 ^ -1) | (-(v407 ^ -1))) >> 31)) & 2)) - (v409 + ((~(((v411 ^ -1) | (-(v411 ^ -1))) >> 31)) & 2))) >> 31) & 1);
      int v413 = v412[v537];
      bool v538 = !(v413 == 0);
      if (v538) {
        int * v414 = v350->cache_tags;
        int v415 = v414[v537];
        int * v416 = v350->cache_vals;
        int v541 = ((4 + ((((int)((unsigned int)((int)((unsigned int)v358 >> 2)) >> 1)) & 3) * 2)) + ((((v405 + ((~(((v407 ^ -1) | (-(v407 ^ -1))) >> 31)) & 2)) - (v409 + ((~(((v411 ^ -1) | (-(v411 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
        int v417 = v416[v541];
        int * v418 = v350->cache_vals;
        int v543 = (((4 + ((((int)((unsigned int)((int)((unsigned int)v358 >> 2)) >> 1)) & 3) * 2)) + ((((v405 + ((~(((v407 ^ -1) | (-(v407 ^ -1))) >> 31)) & 2)) - (v409 + ((~(((v411 ^ -1) | (-(v411 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
        int v419 = v418[v543];
        int * v420 = v350->mem;
        int v545 = v415 * 2;
        v420[v545] = v417;
        int * v422 = v350->mem;
        int v548 = (v415 * 2) + 1;
        v422[v548] = v419;
        ;
      } else {
        ;
      }
      int * v427 = v350->mem;
      int v553 = ((int)((unsigned int)((int)((unsigned int)v358 >> 2)) >> 1)) * 2;
      int v428 = v427[v553];
      int * v429 = v350->mem;
      int v555 = (((int)((unsigned int)((int)((unsigned int)v358 >> 2)) >> 1)) * 2) + 1;
      int v430 = v429[v555];
      int * v431 = v350->cache_vals;
      int v557 = ((4 + ((((int)((unsigned int)((int)((unsigned int)v358 >> 2)) >> 1)) & 3) * 2)) + ((((v405 + ((~(((v407 ^ -1) | (-(v407 ^ -1))) >> 31)) & 2)) - (v409 + ((~(((v411 ^ -1) | (-(v411 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
      v431[v557] = v428;
      int * v433 = v350->cache_vals;
      int v560 = (((4 + ((((int)((unsigned int)((int)((unsigned int)v358 >> 2)) >> 1)) & 3) * 2)) + ((((v405 + ((~(((v407 ^ -1) | (-(v407 ^ -1))) >> 31)) & 2)) - (v409 + ((~(((v411 ^ -1) | (-(v411 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
      v433[v560] = v430;
      int * v435 = v350->cache_tags;
      int v563 = (int)((unsigned int)((int)((unsigned int)v358 >> 2)) >> 1);
      v435[v537] = v563;
      int * v437 = v350->cache_dirty;
      v437[v537] = 0;
      int * v439 = v350->cache_age;
      v439[v537] = 1;
      int * v441 = v350->cache_age;
      int v442 = v441[v537];
      int * v443 = v350->cache_age;
      int v444 = v443[v500];
      int * v445 = v350->cache_age;
      int v571 = v444 + ((int)((unsigned int)(v444 - v442) >> 31));
      v445[v500] = v571;
      int * v447 = v350->cache_age;
      int v448 = v447[v502];
      int * v449 = v350->cache_age;
      int v574 = v448 + ((int)((unsigned int)(v448 - v442) >> 31));
      v449[v502] = v574;
      int * v451 = v350->cache_age;
      v451[v537] = 0;
      v454 = v537;
    }
    int * v455 = v350->cache_vals;
    int v577 = v454 * 2;
    int v456 = v455[v577];
    int * v457 = v350->cache_vals;
    int v579 = (v454 * 2) + 1;
    int v458 = v457[v579];
    int * v459 = v350->cache_vals;
    int v581 = (((((int)((unsigned int)((int)((unsigned int)v358 >> 2)) >> 1)) & 1) * 2) + ((((v384 + ((~(((v386 ^ -1) | (-(v386 ^ -1))) >> 31)) & 2)) - (v388 + ((~(((v390 ^ -1) | (-(v390 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
    v459[v581] = v456;
    int * v461 = v350->cache_vals;
    int v584 = ((((((int)((unsigned int)((int)((unsigned int)v358 >> 2)) >> 1)) & 1) * 2) + ((((v384 + ((~(((v386 ^ -1) | (-(v386 ^ -1))) >> 31)) & 2)) - (v388 + ((~(((v390 ^ -1) | (-(v390 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
    v461[v584] = v458;
    int * v463 = v350->cache_tags;
    int v587 = ((((int)((unsigned int)((int)((unsigned int)v358 >> 2)) >> 1)) & 1) * 2) + ((((v384 + ((~(((v386 ^ -1) | (-(v386 ^ -1))) >> 31)) & 2)) - (v388 + ((~(((v390 ^ -1) | (-(v390 ^ -1))) >> 31)) & 2))) >> 31) & 1);
    int v588 = (int)((unsigned int)((int)((unsigned int)v358 >> 2)) >> 1);
    v463[v587] = v588;
    int * v465 = v350->cache_dirty;
    v465[v587] = 0;
    int * v467 = v350->cache_age;
    v467[v587] = 1;
    int * v469 = v350->cache_age;
    int v470 = v469[v587];
    int * v471 = v350->cache_age;
    int v472 = v471[v496];
    int * v473 = v350->cache_age;
    int v596 = v472 + ((int)((unsigned int)(v472 - v470) >> 31));
    v473[v496] = v596;
    int * v475 = v350->cache_age;
    int v476 = v475[v498];
    int * v477 = v350->cache_age;
    int v599 = v476 + ((int)((unsigned int)(v476 - v470) >> 31));
    v477[v498] = v599;
    int * v479 = v350->cache_age;
    v479[v587] = 0;
    v482 = v587;
  }
  int v602 = (v482 * 2) + (((int)((unsigned int)v358 >> 2)) & 1);
  int v483 = v369[v602];
  int * v484 = v350->regs;
  v484[12] = v483;
  struct StateT * v486 = slot_8(v350);
  return v486;
}

struct StateT * slot_3(struct StateT * v41) {
  int v42 = v41->timer;
  int v46 = v42 + 1;
  v41->timer = v46;
  struct StateT * v44 = slot_4(v41);
  return v44;
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