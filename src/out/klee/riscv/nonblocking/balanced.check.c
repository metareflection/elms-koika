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
struct StateT * slot_1(struct StateT * v20);
struct StateT * slot_6(struct StateT * v324);
struct StateT * slot_5(struct StateT * v366);
struct StateT * slot_4(struct StateT * v342);
struct StateT * slot_2(struct StateT * v275);
struct StateT * slot_7(struct StateT * v360);
struct StateT * slot_3(struct StateT * v293);
struct StateT * slot_0(struct StateT * v2);
struct StateT * snippet(struct StateT * v0) {
  struct StateT * v1 = slot_0(v0);
  int v372 = v1->timer;
  int * v373 = v1->reg_ready;
  int v374 = v373[0];
  int v505 = v374 + ((v372 - v374) & (~((v372 - v374) >> 31)));
  v1->timer = v505;
  int v376 = v1->timer;
  int * v377 = v1->reg_ready;
  int v378 = v377[1];
  int v508 = v378 + ((v376 - v378) & (~((v376 - v378) >> 31)));
  v1->timer = v508;
  int v380 = v1->timer;
  int * v381 = v1->reg_ready;
  int v382 = v381[2];
  int v511 = v382 + ((v380 - v382) & (~((v380 - v382) >> 31)));
  v1->timer = v511;
  int v384 = v1->timer;
  int * v385 = v1->reg_ready;
  int v386 = v385[3];
  int v514 = v386 + ((v384 - v386) & (~((v384 - v386) >> 31)));
  v1->timer = v514;
  int v388 = v1->timer;
  int * v389 = v1->reg_ready;
  int v390 = v389[4];
  int v517 = v390 + ((v388 - v390) & (~((v388 - v390) >> 31)));
  v1->timer = v517;
  int v392 = v1->timer;
  int * v393 = v1->reg_ready;
  int v394 = v393[5];
  int v520 = v394 + ((v392 - v394) & (~((v392 - v394) >> 31)));
  v1->timer = v520;
  int v396 = v1->timer;
  int * v397 = v1->reg_ready;
  int v398 = v397[6];
  int v523 = v398 + ((v396 - v398) & (~((v396 - v398) >> 31)));
  v1->timer = v523;
  int v400 = v1->timer;
  int * v401 = v1->reg_ready;
  int v402 = v401[7];
  int v526 = v402 + ((v400 - v402) & (~((v400 - v402) >> 31)));
  v1->timer = v526;
  int v404 = v1->timer;
  int * v405 = v1->reg_ready;
  int v406 = v405[8];
  int v529 = v406 + ((v404 - v406) & (~((v404 - v406) >> 31)));
  v1->timer = v529;
  int v408 = v1->timer;
  int * v409 = v1->reg_ready;
  int v410 = v409[9];
  int v532 = v410 + ((v408 - v410) & (~((v408 - v410) >> 31)));
  v1->timer = v532;
  int v412 = v1->timer;
  int * v413 = v1->reg_ready;
  int v414 = v413[10];
  int v535 = v414 + ((v412 - v414) & (~((v412 - v414) >> 31)));
  v1->timer = v535;
  int v416 = v1->timer;
  int * v417 = v1->reg_ready;
  int v418 = v417[11];
  int v538 = v418 + ((v416 - v418) & (~((v416 - v418) >> 31)));
  v1->timer = v538;
  int v420 = v1->timer;
  int * v421 = v1->reg_ready;
  int v422 = v421[12];
  int v541 = v422 + ((v420 - v422) & (~((v420 - v422) >> 31)));
  v1->timer = v541;
  int v424 = v1->timer;
  int * v425 = v1->reg_ready;
  int v426 = v425[13];
  int v544 = v426 + ((v424 - v426) & (~((v424 - v426) >> 31)));
  v1->timer = v544;
  int v428 = v1->timer;
  int * v429 = v1->reg_ready;
  int v430 = v429[14];
  int v547 = v430 + ((v428 - v430) & (~((v428 - v430) >> 31)));
  v1->timer = v547;
  int v432 = v1->timer;
  int * v433 = v1->reg_ready;
  int v434 = v433[15];
  int v550 = v434 + ((v432 - v434) & (~((v432 - v434) >> 31)));
  v1->timer = v550;
  int v436 = v1->timer;
  int * v437 = v1->reg_ready;
  int v438 = v437[16];
  int v553 = v438 + ((v436 - v438) & (~((v436 - v438) >> 31)));
  v1->timer = v553;
  int v440 = v1->timer;
  int * v441 = v1->reg_ready;
  int v442 = v441[17];
  int v556 = v442 + ((v440 - v442) & (~((v440 - v442) >> 31)));
  v1->timer = v556;
  int v444 = v1->timer;
  int * v445 = v1->reg_ready;
  int v446 = v445[18];
  int v559 = v446 + ((v444 - v446) & (~((v444 - v446) >> 31)));
  v1->timer = v559;
  int v448 = v1->timer;
  int * v449 = v1->reg_ready;
  int v450 = v449[19];
  int v562 = v450 + ((v448 - v450) & (~((v448 - v450) >> 31)));
  v1->timer = v562;
  int v452 = v1->timer;
  int * v453 = v1->reg_ready;
  int v454 = v453[20];
  int v565 = v454 + ((v452 - v454) & (~((v452 - v454) >> 31)));
  v1->timer = v565;
  int v456 = v1->timer;
  int * v457 = v1->reg_ready;
  int v458 = v457[21];
  int v568 = v458 + ((v456 - v458) & (~((v456 - v458) >> 31)));
  v1->timer = v568;
  int v460 = v1->timer;
  int * v461 = v1->reg_ready;
  int v462 = v461[22];
  int v571 = v462 + ((v460 - v462) & (~((v460 - v462) >> 31)));
  v1->timer = v571;
  int v464 = v1->timer;
  int * v465 = v1->reg_ready;
  int v466 = v465[23];
  int v574 = v466 + ((v464 - v466) & (~((v464 - v466) >> 31)));
  v1->timer = v574;
  int v468 = v1->timer;
  int * v469 = v1->reg_ready;
  int v470 = v469[24];
  int v577 = v470 + ((v468 - v470) & (~((v468 - v470) >> 31)));
  v1->timer = v577;
  int v472 = v1->timer;
  int * v473 = v1->reg_ready;
  int v474 = v473[25];
  int v580 = v474 + ((v472 - v474) & (~((v472 - v474) >> 31)));
  v1->timer = v580;
  int v476 = v1->timer;
  int * v477 = v1->reg_ready;
  int v478 = v477[26];
  int v583 = v478 + ((v476 - v478) & (~((v476 - v478) >> 31)));
  v1->timer = v583;
  int v480 = v1->timer;
  int * v481 = v1->reg_ready;
  int v482 = v481[27];
  int v586 = v482 + ((v480 - v482) & (~((v480 - v482) >> 31)));
  v1->timer = v586;
  int v484 = v1->timer;
  int * v485 = v1->reg_ready;
  int v486 = v485[28];
  int v589 = v486 + ((v484 - v486) & (~((v484 - v486) >> 31)));
  v1->timer = v589;
  int v488 = v1->timer;
  int * v489 = v1->reg_ready;
  int v490 = v489[29];
  int v592 = v490 + ((v488 - v490) & (~((v488 - v490) >> 31)));
  v1->timer = v592;
  int v492 = v1->timer;
  int * v493 = v1->reg_ready;
  int v494 = v493[30];
  int v595 = v494 + ((v492 - v494) & (~((v492 - v494) >> 31)));
  v1->timer = v595;
  int v496 = v1->timer;
  int * v497 = v1->reg_ready;
  int v498 = v497[31];
  int v598 = v498 + ((v496 - v498) & (~((v496 - v498) >> 31)));
  v1->timer = v598;
  return v1;
}

struct StateT * slot_1(struct StateT * v20) {
  int v21 = v20->timer;
  int v22 = v20->timer;
  int v157 = v22 + 1;
  v20->timer = v157;
  int * v24 = v20->reg_ready;
  int v25 = v24[12];
  int * v26 = v20->regs;
  int v27 = v26[12];
  int * v28 = v20->cache_tags;
  int v162 = (((int)((unsigned int)((int)((unsigned int)v27 >> 2)) >> 1)) & 1) * 2;
  int v29 = v28[v162];
  int * v30 = v20->cache_tags;
  int v164 = ((((int)((unsigned int)((int)((unsigned int)v27 >> 2)) >> 1)) & 1) * 2) + 1;
  int v31 = v30[v164];
  int * v32 = v20->cache_tags;
  int v166 = 4 + ((((int)((unsigned int)((int)((unsigned int)v27 >> 2)) >> 1)) & 3) * 2);
  int v33 = v32[v166];
  int * v34 = v20->cache_tags;
  int v168 = (4 + ((((int)((unsigned int)((int)((unsigned int)v27 >> 2)) >> 1)) & 3) * 2)) + 1;
  int v35 = v34[v168];
  int * v36 = v20->cache_vals;
  bool v169 = !(((~(((v29 ^ ((int)((unsigned int)((int)((unsigned int)v27 >> 2)) >> 1))) | (-(v29 ^ ((int)((unsigned int)((int)((unsigned int)v27 >> 2)) >> 1))))) >> 31)) | (~(((v31 ^ ((int)((unsigned int)((int)((unsigned int)v27 >> 2)) >> 1))) | (-(v31 ^ ((int)((unsigned int)((int)((unsigned int)v27 >> 2)) >> 1))))) >> 31))) == 0);
  int v149;
  if (v169) {
    int * v37 = v20->cache_age;
    int v171 = ((((int)((unsigned int)((int)((unsigned int)v27 >> 2)) >> 1)) & 1) * 2) + ((~(((v31 ^ ((int)((unsigned int)((int)((unsigned int)v27 >> 2)) >> 1))) | (-(v31 ^ ((int)((unsigned int)((int)((unsigned int)v27 >> 2)) >> 1))))) >> 31)) & 1);
    int v38 = v37[v171];
    int * v39 = v20->cache_age;
    int v40 = v39[v162];
    int * v41 = v20->cache_age;
    int v174 = v40 + ((int)((unsigned int)(v40 - v38) >> 31));
    v41[v162] = v174;
    int * v43 = v20->cache_age;
    int v44 = v43[v164];
    int * v45 = v20->cache_age;
    int v177 = v44 + ((int)((unsigned int)(v44 - v38) >> 31));
    v45[v164] = v177;
    int * v47 = v20->cache_age;
    v47[v171] = 0;
    v149 = v171;
  } else {
    int * v50 = v20->cache_age;
    int v181 = (((int)((unsigned int)((int)((unsigned int)v27 >> 2)) >> 1)) & 1) * 2;
    int v51 = v50[v181];
    int * v52 = v20->cache_tags;
    int v53 = v52[v181];
    int * v54 = v20->cache_age;
    int v55 = v54[v164];
    int * v56 = v20->cache_tags;
    int v57 = v56[v164];
    bool v185 = !(((~(((v33 ^ ((int)((unsigned int)((int)((unsigned int)v27 >> 2)) >> 1))) | (-(v33 ^ ((int)((unsigned int)((int)((unsigned int)v27 >> 2)) >> 1))))) >> 31)) | (~(((v35 ^ ((int)((unsigned int)((int)((unsigned int)v27 >> 2)) >> 1))) | (-(v35 ^ ((int)((unsigned int)((int)((unsigned int)v27 >> 2)) >> 1))))) >> 31))) == 0);
    int v121;
    if (v185) {
      int * v58 = v20->cache_age;
      int v187 = (4 + ((((int)((unsigned int)((int)((unsigned int)v27 >> 2)) >> 1)) & 3) * 2)) + ((~(((v35 ^ ((int)((unsigned int)((int)((unsigned int)v27 >> 2)) >> 1))) | (-(v35 ^ ((int)((unsigned int)((int)((unsigned int)v27 >> 2)) >> 1))))) >> 31)) & 1);
      int v59 = v58[v187];
      int * v60 = v20->cache_age;
      int v61 = v60[v166];
      int * v62 = v20->cache_age;
      int v190 = v61 + ((int)((unsigned int)(v61 - v59) >> 31));
      v62[v166] = v190;
      int * v64 = v20->cache_age;
      int v65 = v64[v168];
      int * v66 = v20->cache_age;
      int v193 = v65 + ((int)((unsigned int)(v65 - v59) >> 31));
      v66[v168] = v193;
      int * v68 = v20->cache_age;
      v68[v187] = 0;
      v121 = v187;
    } else {
      int * v71 = v20->cache_age;
      int v197 = 4 + ((((int)((unsigned int)((int)((unsigned int)v27 >> 2)) >> 1)) & 3) * 2);
      int v72 = v71[v197];
      int * v73 = v20->cache_tags;
      int v74 = v73[v197];
      int * v75 = v20->cache_age;
      int v76 = v75[v168];
      int * v77 = v20->cache_tags;
      int v78 = v77[v168];
      int * v79 = v20->cache_dirty;
      int v202 = (4 + ((((int)((unsigned int)((int)((unsigned int)v27 >> 2)) >> 1)) & 3) * 2)) + ((((v72 + ((~(((v74 ^ -1) | (-(v74 ^ -1))) >> 31)) & 2)) - (v76 + ((~(((v78 ^ -1) | (-(v78 ^ -1))) >> 31)) & 2))) >> 31) & 1);
      int v80 = v79[v202];
      bool v203 = !(v80 == 0);
      if (v203) {
        int * v81 = v20->cache_tags;
        int v82 = v81[v202];
        int * v83 = v20->cache_vals;
        int v206 = ((4 + ((((int)((unsigned int)((int)((unsigned int)v27 >> 2)) >> 1)) & 3) * 2)) + ((((v72 + ((~(((v74 ^ -1) | (-(v74 ^ -1))) >> 31)) & 2)) - (v76 + ((~(((v78 ^ -1) | (-(v78 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
        int v84 = v83[v206];
        int * v85 = v20->cache_vals;
        int v208 = (((4 + ((((int)((unsigned int)((int)((unsigned int)v27 >> 2)) >> 1)) & 3) * 2)) + ((((v72 + ((~(((v74 ^ -1) | (-(v74 ^ -1))) >> 31)) & 2)) - (v76 + ((~(((v78 ^ -1) | (-(v78 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
        int v86 = v85[v208];
        int * v87 = v20->mem;
        int v210 = v82 * 2;
        v87[v210] = v84;
        int * v89 = v20->mem;
        int v213 = (v82 * 2) + 1;
        v89[v213] = v86;
        ;
      } else {
        ;
      }
      int * v94 = v20->mem;
      int v218 = ((int)((unsigned int)((int)((unsigned int)v27 >> 2)) >> 1)) * 2;
      int v95 = v94[v218];
      int * v96 = v20->mem;
      int v220 = (((int)((unsigned int)((int)((unsigned int)v27 >> 2)) >> 1)) * 2) + 1;
      int v97 = v96[v220];
      int * v98 = v20->cache_vals;
      int v222 = ((4 + ((((int)((unsigned int)((int)((unsigned int)v27 >> 2)) >> 1)) & 3) * 2)) + ((((v72 + ((~(((v74 ^ -1) | (-(v74 ^ -1))) >> 31)) & 2)) - (v76 + ((~(((v78 ^ -1) | (-(v78 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
      v98[v222] = v95;
      int * v100 = v20->cache_vals;
      int v225 = (((4 + ((((int)((unsigned int)((int)((unsigned int)v27 >> 2)) >> 1)) & 3) * 2)) + ((((v72 + ((~(((v74 ^ -1) | (-(v74 ^ -1))) >> 31)) & 2)) - (v76 + ((~(((v78 ^ -1) | (-(v78 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
      v100[v225] = v97;
      int * v102 = v20->cache_tags;
      int v228 = (int)((unsigned int)((int)((unsigned int)v27 >> 2)) >> 1);
      v102[v202] = v228;
      int * v104 = v20->cache_dirty;
      v104[v202] = 0;
      int * v106 = v20->cache_age;
      v106[v202] = 1;
      int * v108 = v20->cache_age;
      int v109 = v108[v202];
      int * v110 = v20->cache_age;
      int v111 = v110[v166];
      int * v112 = v20->cache_age;
      int v236 = v111 + ((int)((unsigned int)(v111 - v109) >> 31));
      v112[v166] = v236;
      int * v114 = v20->cache_age;
      int v115 = v114[v168];
      int * v116 = v20->cache_age;
      int v239 = v115 + ((int)((unsigned int)(v115 - v109) >> 31));
      v116[v168] = v239;
      int * v118 = v20->cache_age;
      v118[v202] = 0;
      v121 = v202;
    }
    int * v122 = v20->cache_vals;
    int v242 = v121 * 2;
    int v123 = v122[v242];
    int * v124 = v20->cache_vals;
    int v244 = (v121 * 2) + 1;
    int v125 = v124[v244];
    int * v126 = v20->cache_vals;
    int v246 = (((((int)((unsigned int)((int)((unsigned int)v27 >> 2)) >> 1)) & 1) * 2) + ((((v51 + ((~(((v53 ^ -1) | (-(v53 ^ -1))) >> 31)) & 2)) - (v55 + ((~(((v57 ^ -1) | (-(v57 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
    v126[v246] = v123;
    int * v128 = v20->cache_vals;
    int v249 = ((((((int)((unsigned int)((int)((unsigned int)v27 >> 2)) >> 1)) & 1) * 2) + ((((v51 + ((~(((v53 ^ -1) | (-(v53 ^ -1))) >> 31)) & 2)) - (v55 + ((~(((v57 ^ -1) | (-(v57 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
    v128[v249] = v125;
    int * v130 = v20->cache_tags;
    int v252 = ((((int)((unsigned int)((int)((unsigned int)v27 >> 2)) >> 1)) & 1) * 2) + ((((v51 + ((~(((v53 ^ -1) | (-(v53 ^ -1))) >> 31)) & 2)) - (v55 + ((~(((v57 ^ -1) | (-(v57 ^ -1))) >> 31)) & 2))) >> 31) & 1);
    int v253 = (int)((unsigned int)((int)((unsigned int)v27 >> 2)) >> 1);
    v130[v252] = v253;
    int * v132 = v20->cache_dirty;
    v132[v252] = 0;
    int * v134 = v20->cache_age;
    v134[v252] = 1;
    int * v136 = v20->cache_age;
    int v137 = v136[v252];
    int * v138 = v20->cache_age;
    int v139 = v138[v162];
    int * v140 = v20->cache_age;
    int v261 = v139 + ((int)((unsigned int)(v139 - v137) >> 31));
    v140[v162] = v261;
    int * v142 = v20->cache_age;
    int v143 = v142[v164];
    int * v144 = v20->cache_age;
    int v264 = v143 + ((int)((unsigned int)(v143 - v137) >> 31));
    v144[v164] = v264;
    int * v146 = v20->cache_age;
    v146[v252] = 0;
    v149 = v252;
  }
  int v267 = (v149 * 2) + (((int)((unsigned int)v27 >> 2)) & 1);
  int v150 = v36[v267];
  int * v151 = v20->reg_ready;
  int v270 = ((v25 + ((v21 - v25) & (~((v21 - v25) >> 31)))) + 1) + ((100 ^ (((~(((v33 ^ ((int)((unsigned int)((int)((unsigned int)v27 >> 2)) >> 1))) | (-(v33 ^ ((int)((unsigned int)((int)((unsigned int)v27 >> 2)) >> 1))))) >> 31)) | (~(((v35 ^ ((int)((unsigned int)((int)((unsigned int)v27 >> 2)) >> 1))) | (-(v35 ^ ((int)((unsigned int)((int)((unsigned int)v27 >> 2)) >> 1))))) >> 31))) & 104)) ^ (((~(((v29 ^ ((int)((unsigned int)((int)((unsigned int)v27 >> 2)) >> 1))) | (-(v29 ^ ((int)((unsigned int)((int)((unsigned int)v27 >> 2)) >> 1))))) >> 31)) | (~(((v31 ^ ((int)((unsigned int)((int)((unsigned int)v27 >> 2)) >> 1))) | (-(v31 ^ ((int)((unsigned int)((int)((unsigned int)v27 >> 2)) >> 1))))) >> 31))) & (1 ^ (100 ^ (((~(((v33 ^ ((int)((unsigned int)((int)((unsigned int)v27 >> 2)) >> 1))) | (-(v33 ^ ((int)((unsigned int)((int)((unsigned int)v27 >> 2)) >> 1))))) >> 31)) | (~(((v35 ^ ((int)((unsigned int)((int)((unsigned int)v27 >> 2)) >> 1))) | (-(v35 ^ ((int)((unsigned int)((int)((unsigned int)v27 >> 2)) >> 1))))) >> 31))) & 104)))));
  v151[16] = v270;
  int * v153 = v20->regs;
  v153[16] = v150;
  struct StateT * v155 = slot_2(v20);
  return v155;
}

struct StateT * slot_6(struct StateT * v324) {
  int v325 = v324->timer;
  int v326 = v324->timer;
  int v334 = v326 + 1;
  v324->timer = v334;
  int * v328 = v324->reg_ready;
  int v337 = v325 + 1;
  v328[18] = v337;
  int * v330 = v324->regs;
  v330[18] = 2;
  struct StateT * v332 = slot_7(v324);
  return v332;
}

struct StateT * slot_5(struct StateT * v366) {
  int v367 = v366->timer;
  int v368 = v366->timer;
  int v371 = v368 + 1;
  v366->timer = v371;
  return v366;
}

struct StateT * slot_4(struct StateT * v342) {
  int v343 = v342->timer;
  int v344 = v342->timer;
  int v352 = v344 + 1;
  v342->timer = v352;
  int * v346 = v342->reg_ready;
  int v355 = v343 + 1;
  v346[18] = v355;
  int * v348 = v342->regs;
  v348[18] = 1;
  struct StateT * v350 = slot_5(v342);
  return v350;
}

struct StateT * slot_2(struct StateT * v275) {
  int v276 = v275->timer;
  int v277 = v275->timer;
  int v285 = v277 + 1;
  v275->timer = v285;
  int * v279 = v275->reg_ready;
  int v288 = v276 + 1;
  v279[17] = v288;
  int * v281 = v275->regs;
  v281[17] = 10;
  struct StateT * v283 = slot_3(v275);
  return v283;
}

struct StateT * slot_7(struct StateT * v360) {
  int v361 = v360->timer;
  int v362 = v360->timer;
  int v365 = v362 + 1;
  v360->timer = v365;
  return v360;
}

struct StateT * slot_3(struct StateT * v293) {
  int v294 = v293->timer;
  int v295 = v293->timer;
  int v311 = v295 + 1;
  v293->timer = v311;
  int * v297 = v293->reg_ready;
  int v298 = v297[16];
  int * v299 = v293->regs;
  int v300 = v299[16];
  int * v301 = v293->reg_ready;
  int v302 = v301[17];
  int * v303 = v293->regs;
  int v304 = v303[17];
  bool v318 = v300 < v304;
  struct StateT * v309;
  if (v318) {
    struct StateT * v305 = slot_6(v293);
    v309 = v305;
  } else {
    struct StateT * v307 = slot_4(v293);
    v309 = v307;
  }
  return v309;
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
  v8[12] = 80;
  struct StateT * v10 = slot_1(v2);
  return v10;
}



/*****************************************
End of C Generated Code
*******************************************/

void init(struct StateT *s) {
  for (int i=0; i<NUM_REGS; i++) {
    s->regs[i] = 0;
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