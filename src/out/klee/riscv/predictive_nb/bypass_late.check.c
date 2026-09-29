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

struct StateT * slot_5(struct StateT * v111);
struct StateT * slot_2(struct StateT * v45);
struct StateT * slot_7(struct StateT * v336);
struct StateT * slot_3(struct StateT * v54);
struct StateT * snippet(struct StateT * v0);
struct StateT * slot_10(struct StateT * v1007);
struct StateT * slot_1(struct StateT * v27);
struct StateT * slot_8(struct StateT * v728);
struct StateT * slot_4(struct StateT * v86);
struct StateT * slot_9(struct StateT * v983);
struct StateT * slot_0(struct StateT * v2);
struct StateT * slot_5(struct StateT * v111) {
  int * v112 = v111->regs;
  int v113 = v112[5];
  int * v114 = v111->regs;
  int v115 = v114[9];
  bool v231 = v113 >= v115;
  struct StateT * v225;
  if (v231) {
    int v116 = v111->timer;
    int v232 = v116 + 15;
    v111->timer = v232;
    int * v118 = v111->saved_regs;
    int v119 = v118[6];
    int * v120 = v111->regs;
    v120[6] = v119;
    int * v122 = v111->saved_regs;
    int v123 = v122[7];
    int * v124 = v111->regs;
    v124[7] = v123;
    int * v126 = v111->reg_ready;
    int v127 = v111->timer;
    v126[0] = v127;
    int * v129 = v111->reg_ready;
    int v130 = v111->timer;
    v129[1] = v130;
    int * v132 = v111->reg_ready;
    int v133 = v111->timer;
    v132[2] = v133;
    int * v135 = v111->reg_ready;
    int v136 = v111->timer;
    v135[3] = v136;
    int * v138 = v111->reg_ready;
    int v139 = v111->timer;
    v138[4] = v139;
    int * v141 = v111->reg_ready;
    int v142 = v111->timer;
    v141[5] = v142;
    int * v144 = v111->reg_ready;
    int v145 = v111->timer;
    v144[6] = v145;
    int * v147 = v111->reg_ready;
    int v148 = v111->timer;
    v147[7] = v148;
    int * v150 = v111->reg_ready;
    int v151 = v111->timer;
    v150[8] = v151;
    int * v153 = v111->reg_ready;
    int v154 = v111->timer;
    v153[9] = v154;
    int * v156 = v111->reg_ready;
    int v157 = v111->timer;
    v156[10] = v157;
    int * v159 = v111->reg_ready;
    int v160 = v111->timer;
    v159[11] = v160;
    int * v162 = v111->reg_ready;
    int v163 = v111->timer;
    v162[12] = v163;
    int * v165 = v111->reg_ready;
    int v166 = v111->timer;
    v165[13] = v166;
    int * v168 = v111->reg_ready;
    int v169 = v111->timer;
    v168[14] = v169;
    int * v171 = v111->reg_ready;
    int v172 = v111->timer;
    v171[15] = v172;
    int * v174 = v111->reg_ready;
    int v175 = v111->timer;
    v174[16] = v175;
    int * v177 = v111->reg_ready;
    int v178 = v111->timer;
    v177[17] = v178;
    int * v180 = v111->reg_ready;
    int v181 = v111->timer;
    v180[18] = v181;
    int * v183 = v111->reg_ready;
    int v184 = v111->timer;
    v183[19] = v184;
    int * v186 = v111->reg_ready;
    int v187 = v111->timer;
    v186[20] = v187;
    int * v189 = v111->reg_ready;
    int v190 = v111->timer;
    v189[21] = v190;
    int * v192 = v111->reg_ready;
    int v193 = v111->timer;
    v192[22] = v193;
    int * v195 = v111->reg_ready;
    int v196 = v111->timer;
    v195[23] = v196;
    int * v198 = v111->reg_ready;
    int v199 = v111->timer;
    v198[24] = v199;
    int * v201 = v111->reg_ready;
    int v202 = v111->timer;
    v201[25] = v202;
    int * v204 = v111->reg_ready;
    int v205 = v111->timer;
    v204[26] = v205;
    int * v207 = v111->reg_ready;
    int v208 = v111->timer;
    v207[27] = v208;
    int * v210 = v111->reg_ready;
    int v211 = v111->timer;
    v210[28] = v211;
    int * v213 = v111->reg_ready;
    int v214 = v111->timer;
    v213[29] = v214;
    int * v216 = v111->reg_ready;
    int v217 = v111->timer;
    v216[30] = v217;
    int * v219 = v111->reg_ready;
    int v220 = v111->timer;
    v219[31] = v220;
    v225 = v111;
  } else {
    struct StateT * v223 = slot_7(v111);
    v225 = v223;
  }
  return v225;
}

struct StateT * slot_2(struct StateT * v45) {
  int v46 = v45->timer;
  int v47 = v45->timer;
  int v51 = v47 + 1;
  v45->timer = v51;
  struct StateT * v49 = slot_3(v45);
  return v49;
}

struct StateT * slot_7(struct StateT * v336) {
  int v337 = v336->timer;
  int v338 = v336->timer;
  int v547 = v338 + 1;
  v336->timer = v547;
  int * v340 = v336->reg_ready;
  int v341 = v340[6];
  int * v342 = v336->regs;
  int v343 = v342[6];
  int * v344 = v336->reg_ready;
  int v345 = v344[7];
  int * v346 = v336->regs;
  int v347 = v346[7];
  int * v348 = v336->cache_tags;
  int v555 = (((int)((unsigned int)((int)((unsigned int)v343 >> 2)) >> 1)) & 1) * 2;
  int v349 = v348[v555];
  int * v350 = v336->cache_tags;
  int v557 = ((((int)((unsigned int)((int)((unsigned int)v343 >> 2)) >> 1)) & 1) * 2) + 1;
  int v351 = v350[v557];
  int * v352 = v336->cache_tags;
  int v559 = 4 + ((((int)((unsigned int)((int)((unsigned int)v343 >> 2)) >> 1)) & 3) * 2);
  int v353 = v352[v559];
  int * v354 = v336->cache_tags;
  int v561 = (4 + ((((int)((unsigned int)((int)((unsigned int)v343 >> 2)) >> 1)) & 3) * 2)) + 1;
  int v355 = v354[v561];
  int v356 = v336->timer;
  int v562 = v356 + ((100 ^ (((~(((v353 ^ ((int)((unsigned int)((int)((unsigned int)v343 >> 2)) >> 1))) | (-(v353 ^ ((int)((unsigned int)((int)((unsigned int)v343 >> 2)) >> 1))))) >> 31)) | (~(((v355 ^ ((int)((unsigned int)((int)((unsigned int)v343 >> 2)) >> 1))) | (-(v355 ^ ((int)((unsigned int)((int)((unsigned int)v343 >> 2)) >> 1))))) >> 31))) & 104)) ^ (((~(((v349 ^ ((int)((unsigned int)((int)((unsigned int)v343 >> 2)) >> 1))) | (-(v349 ^ ((int)((unsigned int)((int)((unsigned int)v343 >> 2)) >> 1))))) >> 31)) | (~(((v351 ^ ((int)((unsigned int)((int)((unsigned int)v343 >> 2)) >> 1))) | (-(v351 ^ ((int)((unsigned int)((int)((unsigned int)v343 >> 2)) >> 1))))) >> 31))) & (1 ^ (100 ^ (((~(((v353 ^ ((int)((unsigned int)((int)((unsigned int)v343 >> 2)) >> 1))) | (-(v353 ^ ((int)((unsigned int)((int)((unsigned int)v343 >> 2)) >> 1))))) >> 31)) | (~(((v355 ^ ((int)((unsigned int)((int)((unsigned int)v343 >> 2)) >> 1))) | (-(v355 ^ ((int)((unsigned int)((int)((unsigned int)v343 >> 2)) >> 1))))) >> 31))) & 104)))));
  v336->timer = v562;
  bool v563 = !(((~(((v349 ^ ((int)((unsigned int)((int)((unsigned int)v343 >> 2)) >> 1))) | (-(v349 ^ ((int)((unsigned int)((int)((unsigned int)v343 >> 2)) >> 1))))) >> 31)) | (~(((v351 ^ ((int)((unsigned int)((int)((unsigned int)v343 >> 2)) >> 1))) | (-(v351 ^ ((int)((unsigned int)((int)((unsigned int)v343 >> 2)) >> 1))))) >> 31))) == 0);
  int v470;
  if (v563) {
    int * v358 = v336->cache_age;
    int v565 = ((((int)((unsigned int)((int)((unsigned int)v343 >> 2)) >> 1)) & 1) * 2) + ((~(((v351 ^ ((int)((unsigned int)((int)((unsigned int)v343 >> 2)) >> 1))) | (-(v351 ^ ((int)((unsigned int)((int)((unsigned int)v343 >> 2)) >> 1))))) >> 31)) & 1);
    int v359 = v358[v565];
    int * v360 = v336->cache_age;
    int v361 = v360[v555];
    int * v362 = v336->cache_age;
    int v568 = v361 + ((int)((unsigned int)(v361 - v359) >> 31));
    v362[v555] = v568;
    int * v364 = v336->cache_age;
    int v365 = v364[v557];
    int * v366 = v336->cache_age;
    int v571 = v365 + ((int)((unsigned int)(v365 - v359) >> 31));
    v366[v557] = v571;
    int * v368 = v336->cache_age;
    v368[v565] = 0;
    v470 = v565;
  } else {
    int * v371 = v336->cache_age;
    int v575 = (((int)((unsigned int)((int)((unsigned int)v343 >> 2)) >> 1)) & 1) * 2;
    int v372 = v371[v575];
    int * v373 = v336->cache_tags;
    int v374 = v373[v575];
    int * v375 = v336->cache_age;
    int v376 = v375[v557];
    int * v377 = v336->cache_tags;
    int v378 = v377[v557];
    bool v579 = !(((~(((v353 ^ ((int)((unsigned int)((int)((unsigned int)v343 >> 2)) >> 1))) | (-(v353 ^ ((int)((unsigned int)((int)((unsigned int)v343 >> 2)) >> 1))))) >> 31)) | (~(((v355 ^ ((int)((unsigned int)((int)((unsigned int)v343 >> 2)) >> 1))) | (-(v355 ^ ((int)((unsigned int)((int)((unsigned int)v343 >> 2)) >> 1))))) >> 31))) == 0);
    int v442;
    if (v579) {
      int * v379 = v336->cache_age;
      int v581 = (4 + ((((int)((unsigned int)((int)((unsigned int)v343 >> 2)) >> 1)) & 3) * 2)) + ((~(((v355 ^ ((int)((unsigned int)((int)((unsigned int)v343 >> 2)) >> 1))) | (-(v355 ^ ((int)((unsigned int)((int)((unsigned int)v343 >> 2)) >> 1))))) >> 31)) & 1);
      int v380 = v379[v581];
      int * v381 = v336->cache_age;
      int v382 = v381[v559];
      int * v383 = v336->cache_age;
      int v584 = v382 + ((int)((unsigned int)(v382 - v380) >> 31));
      v383[v559] = v584;
      int * v385 = v336->cache_age;
      int v386 = v385[v561];
      int * v387 = v336->cache_age;
      int v587 = v386 + ((int)((unsigned int)(v386 - v380) >> 31));
      v387[v561] = v587;
      int * v389 = v336->cache_age;
      v389[v581] = 0;
      v442 = v581;
    } else {
      int * v392 = v336->cache_age;
      int v591 = 4 + ((((int)((unsigned int)((int)((unsigned int)v343 >> 2)) >> 1)) & 3) * 2);
      int v393 = v392[v591];
      int * v394 = v336->cache_tags;
      int v395 = v394[v591];
      int * v396 = v336->cache_age;
      int v397 = v396[v561];
      int * v398 = v336->cache_tags;
      int v399 = v398[v561];
      int * v400 = v336->cache_dirty;
      int v596 = (4 + ((((int)((unsigned int)((int)((unsigned int)v343 >> 2)) >> 1)) & 3) * 2)) + ((((v393 + ((~(((v395 ^ -1) | (-(v395 ^ -1))) >> 31)) & 2)) - (v397 + ((~(((v399 ^ -1) | (-(v399 ^ -1))) >> 31)) & 2))) >> 31) & 1);
      int v401 = v400[v596];
      bool v597 = !(v401 == 0);
      if (v597) {
        int * v402 = v336->cache_tags;
        int v403 = v402[v596];
        int * v404 = v336->cache_vals;
        int v600 = ((4 + ((((int)((unsigned int)((int)((unsigned int)v343 >> 2)) >> 1)) & 3) * 2)) + ((((v393 + ((~(((v395 ^ -1) | (-(v395 ^ -1))) >> 31)) & 2)) - (v397 + ((~(((v399 ^ -1) | (-(v399 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
        int v405 = v404[v600];
        int * v406 = v336->cache_vals;
        int v602 = (((4 + ((((int)((unsigned int)((int)((unsigned int)v343 >> 2)) >> 1)) & 3) * 2)) + ((((v393 + ((~(((v395 ^ -1) | (-(v395 ^ -1))) >> 31)) & 2)) - (v397 + ((~(((v399 ^ -1) | (-(v399 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
        int v407 = v406[v602];
        int * v408 = v336->mem;
        int v604 = v403 * 2;
        v408[v604] = v405;
        int * v410 = v336->mem;
        int v607 = (v403 * 2) + 1;
        v410[v607] = v407;
        ;
      } else {
        ;
      }
      int * v415 = v336->mem;
      int v612 = ((int)((unsigned int)((int)((unsigned int)v343 >> 2)) >> 1)) * 2;
      int v416 = v415[v612];
      int * v417 = v336->mem;
      int v614 = (((int)((unsigned int)((int)((unsigned int)v343 >> 2)) >> 1)) * 2) + 1;
      int v418 = v417[v614];
      int * v419 = v336->cache_vals;
      int v616 = ((4 + ((((int)((unsigned int)((int)((unsigned int)v343 >> 2)) >> 1)) & 3) * 2)) + ((((v393 + ((~(((v395 ^ -1) | (-(v395 ^ -1))) >> 31)) & 2)) - (v397 + ((~(((v399 ^ -1) | (-(v399 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
      v419[v616] = v416;
      int * v421 = v336->cache_vals;
      int v619 = (((4 + ((((int)((unsigned int)((int)((unsigned int)v343 >> 2)) >> 1)) & 3) * 2)) + ((((v393 + ((~(((v395 ^ -1) | (-(v395 ^ -1))) >> 31)) & 2)) - (v397 + ((~(((v399 ^ -1) | (-(v399 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
      v421[v619] = v418;
      int * v423 = v336->cache_tags;
      int v622 = (int)((unsigned int)((int)((unsigned int)v343 >> 2)) >> 1);
      v423[v596] = v622;
      int * v425 = v336->cache_dirty;
      v425[v596] = 0;
      int * v427 = v336->cache_age;
      v427[v596] = 1;
      int * v429 = v336->cache_age;
      int v430 = v429[v596];
      int * v431 = v336->cache_age;
      int v432 = v431[v559];
      int * v433 = v336->cache_age;
      int v630 = v432 + ((int)((unsigned int)(v432 - v430) >> 31));
      v433[v559] = v630;
      int * v435 = v336->cache_age;
      int v436 = v435[v561];
      int * v437 = v336->cache_age;
      int v633 = v436 + ((int)((unsigned int)(v436 - v430) >> 31));
      v437[v561] = v633;
      int * v439 = v336->cache_age;
      v439[v596] = 0;
      v442 = v596;
    }
    int * v443 = v336->cache_vals;
    int v636 = v442 * 2;
    int v444 = v443[v636];
    int * v445 = v336->cache_vals;
    int v638 = (v442 * 2) + 1;
    int v446 = v445[v638];
    int * v447 = v336->cache_vals;
    int v640 = (((((int)((unsigned int)((int)((unsigned int)v343 >> 2)) >> 1)) & 1) * 2) + ((((v372 + ((~(((v374 ^ -1) | (-(v374 ^ -1))) >> 31)) & 2)) - (v376 + ((~(((v378 ^ -1) | (-(v378 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
    v447[v640] = v444;
    int * v449 = v336->cache_vals;
    int v643 = ((((((int)((unsigned int)((int)((unsigned int)v343 >> 2)) >> 1)) & 1) * 2) + ((((v372 + ((~(((v374 ^ -1) | (-(v374 ^ -1))) >> 31)) & 2)) - (v376 + ((~(((v378 ^ -1) | (-(v378 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
    v449[v643] = v446;
    int * v451 = v336->cache_tags;
    int v646 = ((((int)((unsigned int)((int)((unsigned int)v343 >> 2)) >> 1)) & 1) * 2) + ((((v372 + ((~(((v374 ^ -1) | (-(v374 ^ -1))) >> 31)) & 2)) - (v376 + ((~(((v378 ^ -1) | (-(v378 ^ -1))) >> 31)) & 2))) >> 31) & 1);
    int v647 = (int)((unsigned int)((int)((unsigned int)v343 >> 2)) >> 1);
    v451[v646] = v647;
    int * v453 = v336->cache_dirty;
    v453[v646] = 0;
    int * v455 = v336->cache_age;
    v455[v646] = 1;
    int * v457 = v336->cache_age;
    int v458 = v457[v646];
    int * v459 = v336->cache_age;
    int v460 = v459[v555];
    int * v461 = v336->cache_age;
    int v655 = v460 + ((int)((unsigned int)(v460 - v458) >> 31));
    v461[v555] = v655;
    int * v463 = v336->cache_age;
    int v464 = v463[v557];
    int * v465 = v336->cache_age;
    int v658 = v464 + ((int)((unsigned int)(v464 - v458) >> 31));
    v465[v557] = v658;
    int * v467 = v336->cache_age;
    v467[v646] = 0;
    v470 = v646;
  }
  int * v471 = v336->cache_vals;
  int v661 = (v470 * 2) + (((int)((unsigned int)v343 >> 2)) & 1);
  v471[v661] = v347;
  int * v473 = v336->cache_tags;
  int v474 = v473[v559];
  int * v475 = v336->cache_tags;
  int v476 = v475[v561];
  bool v665 = !(((~(((v474 ^ ((int)((unsigned int)((int)((unsigned int)v343 >> 2)) >> 1))) | (-(v474 ^ ((int)((unsigned int)((int)((unsigned int)v343 >> 2)) >> 1))))) >> 31)) | (~(((v476 ^ ((int)((unsigned int)((int)((unsigned int)v343 >> 2)) >> 1))) | (-(v476 ^ ((int)((unsigned int)((int)((unsigned int)v343 >> 2)) >> 1))))) >> 31))) == 0);
  int v540;
  if (v665) {
    int * v477 = v336->cache_age;
    int v667 = (4 + ((((int)((unsigned int)((int)((unsigned int)v343 >> 2)) >> 1)) & 3) * 2)) + ((~(((v476 ^ ((int)((unsigned int)((int)((unsigned int)v343 >> 2)) >> 1))) | (-(v476 ^ ((int)((unsigned int)((int)((unsigned int)v343 >> 2)) >> 1))))) >> 31)) & 1);
    int v478 = v477[v667];
    int * v479 = v336->cache_age;
    int v480 = v479[v559];
    int * v481 = v336->cache_age;
    int v670 = v480 + ((int)((unsigned int)(v480 - v478) >> 31));
    v481[v559] = v670;
    int * v483 = v336->cache_age;
    int v484 = v483[v561];
    int * v485 = v336->cache_age;
    int v673 = v484 + ((int)((unsigned int)(v484 - v478) >> 31));
    v485[v561] = v673;
    int * v487 = v336->cache_age;
    v487[v667] = 0;
    v540 = v667;
  } else {
    int * v490 = v336->cache_age;
    int v677 = 4 + ((((int)((unsigned int)((int)((unsigned int)v343 >> 2)) >> 1)) & 3) * 2);
    int v491 = v490[v677];
    int * v492 = v336->cache_tags;
    int v493 = v492[v677];
    int * v494 = v336->cache_age;
    int v495 = v494[v561];
    int * v496 = v336->cache_tags;
    int v497 = v496[v561];
    int * v498 = v336->cache_dirty;
    int v682 = (4 + ((((int)((unsigned int)((int)((unsigned int)v343 >> 2)) >> 1)) & 3) * 2)) + ((((v491 + ((~(((v493 ^ -1) | (-(v493 ^ -1))) >> 31)) & 2)) - (v495 + ((~(((v497 ^ -1) | (-(v497 ^ -1))) >> 31)) & 2))) >> 31) & 1);
    int v499 = v498[v682];
    bool v683 = !(v499 == 0);
    if (v683) {
      int * v500 = v336->cache_tags;
      int v501 = v500[v682];
      int * v502 = v336->cache_vals;
      int v686 = ((4 + ((((int)((unsigned int)((int)((unsigned int)v343 >> 2)) >> 1)) & 3) * 2)) + ((((v491 + ((~(((v493 ^ -1) | (-(v493 ^ -1))) >> 31)) & 2)) - (v495 + ((~(((v497 ^ -1) | (-(v497 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
      int v503 = v502[v686];
      int * v504 = v336->cache_vals;
      int v688 = (((4 + ((((int)((unsigned int)((int)((unsigned int)v343 >> 2)) >> 1)) & 3) * 2)) + ((((v491 + ((~(((v493 ^ -1) | (-(v493 ^ -1))) >> 31)) & 2)) - (v495 + ((~(((v497 ^ -1) | (-(v497 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
      int v505 = v504[v688];
      int * v506 = v336->mem;
      int v690 = v501 * 2;
      v506[v690] = v503;
      int * v508 = v336->mem;
      int v693 = (v501 * 2) + 1;
      v508[v693] = v505;
      ;
    } else {
      ;
    }
    int * v513 = v336->mem;
    int v698 = ((int)((unsigned int)((int)((unsigned int)v343 >> 2)) >> 1)) * 2;
    int v514 = v513[v698];
    int * v515 = v336->mem;
    int v700 = (((int)((unsigned int)((int)((unsigned int)v343 >> 2)) >> 1)) * 2) + 1;
    int v516 = v515[v700];
    int * v517 = v336->cache_vals;
    int v702 = ((4 + ((((int)((unsigned int)((int)((unsigned int)v343 >> 2)) >> 1)) & 3) * 2)) + ((((v491 + ((~(((v493 ^ -1) | (-(v493 ^ -1))) >> 31)) & 2)) - (v495 + ((~(((v497 ^ -1) | (-(v497 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
    v517[v702] = v514;
    int * v519 = v336->cache_vals;
    int v705 = (((4 + ((((int)((unsigned int)((int)((unsigned int)v343 >> 2)) >> 1)) & 3) * 2)) + ((((v491 + ((~(((v493 ^ -1) | (-(v493 ^ -1))) >> 31)) & 2)) - (v495 + ((~(((v497 ^ -1) | (-(v497 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
    v519[v705] = v516;
    int * v521 = v336->cache_tags;
    int v708 = (int)((unsigned int)((int)((unsigned int)v343 >> 2)) >> 1);
    v521[v682] = v708;
    int * v523 = v336->cache_dirty;
    v523[v682] = 0;
    int * v525 = v336->cache_age;
    v525[v682] = 1;
    int * v527 = v336->cache_age;
    int v528 = v527[v682];
    int * v529 = v336->cache_age;
    int v530 = v529[v559];
    int * v531 = v336->cache_age;
    int v716 = v530 + ((int)((unsigned int)(v530 - v528) >> 31));
    v531[v559] = v716;
    int * v533 = v336->cache_age;
    int v534 = v533[v561];
    int * v535 = v336->cache_age;
    int v719 = v534 + ((int)((unsigned int)(v534 - v528) >> 31));
    v535[v561] = v719;
    int * v537 = v336->cache_age;
    v537[v682] = 0;
    v540 = v682;
  }
  int * v541 = v336->cache_vals;
  int v722 = (v540 * 2) + (((int)((unsigned int)v343 >> 2)) & 1);
  v541[v722] = v347;
  int * v543 = v336->cache_dirty;
  v543[v540] = 1;
  struct StateT * v545 = slot_8(v336);
  return v545;
}

struct StateT * slot_3(struct StateT * v54) {
  int * v55 = v54->saved_regs;
  int * v56 = v54->regs;
  int v57 = v56[6];
  v55[6] = v57;
  int v59 = v54->timer;
  int v60 = v54->timer;
  int v76 = v60 + 1;
  v54->timer = v76;
  int * v62 = v54->reg_ready;
  int v63 = v62[5];
  int * v64 = v54->regs;
  int v65 = v64[5];
  int * v66 = v54->reg_ready;
  int v81 = (v63 + ((v59 - v63) & (~((v59 - v63) >> 31)))) + 1;
  v66[6] = v81;
  int * v68 = v54->regs;
  int v83 = v65 + 80;
  v68[6] = v83;
  struct StateT * v70 = slot_4(v54);
  return v70;
}

struct StateT * snippet(struct StateT * v0) {
  struct StateT * v1 = slot_0(v0);
  int v1259 = v1->timer;
  int * v1260 = v1->reg_ready;
  int v1261 = v1260[0];
  int v1392 = v1261 + ((v1259 - v1261) & (~((v1259 - v1261) >> 31)));
  v1->timer = v1392;
  int v1263 = v1->timer;
  int * v1264 = v1->reg_ready;
  int v1265 = v1264[1];
  int v1395 = v1265 + ((v1263 - v1265) & (~((v1263 - v1265) >> 31)));
  v1->timer = v1395;
  int v1267 = v1->timer;
  int * v1268 = v1->reg_ready;
  int v1269 = v1268[2];
  int v1398 = v1269 + ((v1267 - v1269) & (~((v1267 - v1269) >> 31)));
  v1->timer = v1398;
  int v1271 = v1->timer;
  int * v1272 = v1->reg_ready;
  int v1273 = v1272[3];
  int v1401 = v1273 + ((v1271 - v1273) & (~((v1271 - v1273) >> 31)));
  v1->timer = v1401;
  int v1275 = v1->timer;
  int * v1276 = v1->reg_ready;
  int v1277 = v1276[4];
  int v1404 = v1277 + ((v1275 - v1277) & (~((v1275 - v1277) >> 31)));
  v1->timer = v1404;
  int v1279 = v1->timer;
  int * v1280 = v1->reg_ready;
  int v1281 = v1280[5];
  int v1407 = v1281 + ((v1279 - v1281) & (~((v1279 - v1281) >> 31)));
  v1->timer = v1407;
  int v1283 = v1->timer;
  int * v1284 = v1->reg_ready;
  int v1285 = v1284[6];
  int v1410 = v1285 + ((v1283 - v1285) & (~((v1283 - v1285) >> 31)));
  v1->timer = v1410;
  int v1287 = v1->timer;
  int * v1288 = v1->reg_ready;
  int v1289 = v1288[7];
  int v1413 = v1289 + ((v1287 - v1289) & (~((v1287 - v1289) >> 31)));
  v1->timer = v1413;
  int v1291 = v1->timer;
  int * v1292 = v1->reg_ready;
  int v1293 = v1292[8];
  int v1416 = v1293 + ((v1291 - v1293) & (~((v1291 - v1293) >> 31)));
  v1->timer = v1416;
  int v1295 = v1->timer;
  int * v1296 = v1->reg_ready;
  int v1297 = v1296[9];
  int v1419 = v1297 + ((v1295 - v1297) & (~((v1295 - v1297) >> 31)));
  v1->timer = v1419;
  int v1299 = v1->timer;
  int * v1300 = v1->reg_ready;
  int v1301 = v1300[10];
  int v1422 = v1301 + ((v1299 - v1301) & (~((v1299 - v1301) >> 31)));
  v1->timer = v1422;
  int v1303 = v1->timer;
  int * v1304 = v1->reg_ready;
  int v1305 = v1304[11];
  int v1425 = v1305 + ((v1303 - v1305) & (~((v1303 - v1305) >> 31)));
  v1->timer = v1425;
  int v1307 = v1->timer;
  int * v1308 = v1->reg_ready;
  int v1309 = v1308[12];
  int v1428 = v1309 + ((v1307 - v1309) & (~((v1307 - v1309) >> 31)));
  v1->timer = v1428;
  int v1311 = v1->timer;
  int * v1312 = v1->reg_ready;
  int v1313 = v1312[13];
  int v1431 = v1313 + ((v1311 - v1313) & (~((v1311 - v1313) >> 31)));
  v1->timer = v1431;
  int v1315 = v1->timer;
  int * v1316 = v1->reg_ready;
  int v1317 = v1316[14];
  int v1434 = v1317 + ((v1315 - v1317) & (~((v1315 - v1317) >> 31)));
  v1->timer = v1434;
  int v1319 = v1->timer;
  int * v1320 = v1->reg_ready;
  int v1321 = v1320[15];
  int v1437 = v1321 + ((v1319 - v1321) & (~((v1319 - v1321) >> 31)));
  v1->timer = v1437;
  int v1323 = v1->timer;
  int * v1324 = v1->reg_ready;
  int v1325 = v1324[16];
  int v1440 = v1325 + ((v1323 - v1325) & (~((v1323 - v1325) >> 31)));
  v1->timer = v1440;
  int v1327 = v1->timer;
  int * v1328 = v1->reg_ready;
  int v1329 = v1328[17];
  int v1443 = v1329 + ((v1327 - v1329) & (~((v1327 - v1329) >> 31)));
  v1->timer = v1443;
  int v1331 = v1->timer;
  int * v1332 = v1->reg_ready;
  int v1333 = v1332[18];
  int v1446 = v1333 + ((v1331 - v1333) & (~((v1331 - v1333) >> 31)));
  v1->timer = v1446;
  int v1335 = v1->timer;
  int * v1336 = v1->reg_ready;
  int v1337 = v1336[19];
  int v1449 = v1337 + ((v1335 - v1337) & (~((v1335 - v1337) >> 31)));
  v1->timer = v1449;
  int v1339 = v1->timer;
  int * v1340 = v1->reg_ready;
  int v1341 = v1340[20];
  int v1452 = v1341 + ((v1339 - v1341) & (~((v1339 - v1341) >> 31)));
  v1->timer = v1452;
  int v1343 = v1->timer;
  int * v1344 = v1->reg_ready;
  int v1345 = v1344[21];
  int v1455 = v1345 + ((v1343 - v1345) & (~((v1343 - v1345) >> 31)));
  v1->timer = v1455;
  int v1347 = v1->timer;
  int * v1348 = v1->reg_ready;
  int v1349 = v1348[22];
  int v1458 = v1349 + ((v1347 - v1349) & (~((v1347 - v1349) >> 31)));
  v1->timer = v1458;
  int v1351 = v1->timer;
  int * v1352 = v1->reg_ready;
  int v1353 = v1352[23];
  int v1461 = v1353 + ((v1351 - v1353) & (~((v1351 - v1353) >> 31)));
  v1->timer = v1461;
  int v1355 = v1->timer;
  int * v1356 = v1->reg_ready;
  int v1357 = v1356[24];
  int v1464 = v1357 + ((v1355 - v1357) & (~((v1355 - v1357) >> 31)));
  v1->timer = v1464;
  int v1359 = v1->timer;
  int * v1360 = v1->reg_ready;
  int v1361 = v1360[25];
  int v1467 = v1361 + ((v1359 - v1361) & (~((v1359 - v1361) >> 31)));
  v1->timer = v1467;
  int v1363 = v1->timer;
  int * v1364 = v1->reg_ready;
  int v1365 = v1364[26];
  int v1470 = v1365 + ((v1363 - v1365) & (~((v1363 - v1365) >> 31)));
  v1->timer = v1470;
  int v1367 = v1->timer;
  int * v1368 = v1->reg_ready;
  int v1369 = v1368[27];
  int v1473 = v1369 + ((v1367 - v1369) & (~((v1367 - v1369) >> 31)));
  v1->timer = v1473;
  int v1371 = v1->timer;
  int * v1372 = v1->reg_ready;
  int v1373 = v1372[28];
  int v1476 = v1373 + ((v1371 - v1373) & (~((v1371 - v1373) >> 31)));
  v1->timer = v1476;
  int v1375 = v1->timer;
  int * v1376 = v1->reg_ready;
  int v1377 = v1376[29];
  int v1479 = v1377 + ((v1375 - v1377) & (~((v1375 - v1377) >> 31)));
  v1->timer = v1479;
  int v1379 = v1->timer;
  int * v1380 = v1->reg_ready;
  int v1381 = v1380[30];
  int v1482 = v1381 + ((v1379 - v1381) & (~((v1379 - v1381) >> 31)));
  v1->timer = v1482;
  int v1383 = v1->timer;
  int * v1384 = v1->reg_ready;
  int v1385 = v1384[31];
  int v1485 = v1385 + ((v1383 - v1385) & (~((v1383 - v1385) >> 31)));
  v1->timer = v1485;
  return v1;
}

struct StateT * slot_10(struct StateT * v1007) {
  int v1008 = v1007->timer;
  int v1009 = v1007->timer;
  int v1143 = v1009 + 1;
  v1007->timer = v1143;
  int * v1011 = v1007->reg_ready;
  int v1012 = v1011[11];
  int * v1013 = v1007->regs;
  int v1014 = v1013[11];
  int * v1015 = v1007->cache_tags;
  int v1148 = (((int)((unsigned int)((int)((unsigned int)v1014 >> 2)) >> 1)) & 1) * 2;
  int v1016 = v1015[v1148];
  int * v1017 = v1007->cache_tags;
  int v1150 = ((((int)((unsigned int)((int)((unsigned int)v1014 >> 2)) >> 1)) & 1) * 2) + 1;
  int v1018 = v1017[v1150];
  int * v1019 = v1007->cache_tags;
  int v1152 = 4 + ((((int)((unsigned int)((int)((unsigned int)v1014 >> 2)) >> 1)) & 3) * 2);
  int v1020 = v1019[v1152];
  int * v1021 = v1007->cache_tags;
  int v1154 = (4 + ((((int)((unsigned int)((int)((unsigned int)v1014 >> 2)) >> 1)) & 3) * 2)) + 1;
  int v1022 = v1021[v1154];
  int * v1023 = v1007->cache_vals;
  bool v1155 = !(((~(((v1016 ^ ((int)((unsigned int)((int)((unsigned int)v1014 >> 2)) >> 1))) | (-(v1016 ^ ((int)((unsigned int)((int)((unsigned int)v1014 >> 2)) >> 1))))) >> 31)) | (~(((v1018 ^ ((int)((unsigned int)((int)((unsigned int)v1014 >> 2)) >> 1))) | (-(v1018 ^ ((int)((unsigned int)((int)((unsigned int)v1014 >> 2)) >> 1))))) >> 31))) == 0);
  int v1136;
  if (v1155) {
    int * v1024 = v1007->cache_age;
    int v1157 = ((((int)((unsigned int)((int)((unsigned int)v1014 >> 2)) >> 1)) & 1) * 2) + ((~(((v1018 ^ ((int)((unsigned int)((int)((unsigned int)v1014 >> 2)) >> 1))) | (-(v1018 ^ ((int)((unsigned int)((int)((unsigned int)v1014 >> 2)) >> 1))))) >> 31)) & 1);
    int v1025 = v1024[v1157];
    int * v1026 = v1007->cache_age;
    int v1027 = v1026[v1148];
    int * v1028 = v1007->cache_age;
    int v1160 = v1027 + ((int)((unsigned int)(v1027 - v1025) >> 31));
    v1028[v1148] = v1160;
    int * v1030 = v1007->cache_age;
    int v1031 = v1030[v1150];
    int * v1032 = v1007->cache_age;
    int v1163 = v1031 + ((int)((unsigned int)(v1031 - v1025) >> 31));
    v1032[v1150] = v1163;
    int * v1034 = v1007->cache_age;
    v1034[v1157] = 0;
    v1136 = v1157;
  } else {
    int * v1037 = v1007->cache_age;
    int v1167 = (((int)((unsigned int)((int)((unsigned int)v1014 >> 2)) >> 1)) & 1) * 2;
    int v1038 = v1037[v1167];
    int * v1039 = v1007->cache_tags;
    int v1040 = v1039[v1167];
    int * v1041 = v1007->cache_age;
    int v1042 = v1041[v1150];
    int * v1043 = v1007->cache_tags;
    int v1044 = v1043[v1150];
    bool v1171 = !(((~(((v1020 ^ ((int)((unsigned int)((int)((unsigned int)v1014 >> 2)) >> 1))) | (-(v1020 ^ ((int)((unsigned int)((int)((unsigned int)v1014 >> 2)) >> 1))))) >> 31)) | (~(((v1022 ^ ((int)((unsigned int)((int)((unsigned int)v1014 >> 2)) >> 1))) | (-(v1022 ^ ((int)((unsigned int)((int)((unsigned int)v1014 >> 2)) >> 1))))) >> 31))) == 0);
    int v1108;
    if (v1171) {
      int * v1045 = v1007->cache_age;
      int v1173 = (4 + ((((int)((unsigned int)((int)((unsigned int)v1014 >> 2)) >> 1)) & 3) * 2)) + ((~(((v1022 ^ ((int)((unsigned int)((int)((unsigned int)v1014 >> 2)) >> 1))) | (-(v1022 ^ ((int)((unsigned int)((int)((unsigned int)v1014 >> 2)) >> 1))))) >> 31)) & 1);
      int v1046 = v1045[v1173];
      int * v1047 = v1007->cache_age;
      int v1048 = v1047[v1152];
      int * v1049 = v1007->cache_age;
      int v1176 = v1048 + ((int)((unsigned int)(v1048 - v1046) >> 31));
      v1049[v1152] = v1176;
      int * v1051 = v1007->cache_age;
      int v1052 = v1051[v1154];
      int * v1053 = v1007->cache_age;
      int v1179 = v1052 + ((int)((unsigned int)(v1052 - v1046) >> 31));
      v1053[v1154] = v1179;
      int * v1055 = v1007->cache_age;
      v1055[v1173] = 0;
      v1108 = v1173;
    } else {
      int * v1058 = v1007->cache_age;
      int v1183 = 4 + ((((int)((unsigned int)((int)((unsigned int)v1014 >> 2)) >> 1)) & 3) * 2);
      int v1059 = v1058[v1183];
      int * v1060 = v1007->cache_tags;
      int v1061 = v1060[v1183];
      int * v1062 = v1007->cache_age;
      int v1063 = v1062[v1154];
      int * v1064 = v1007->cache_tags;
      int v1065 = v1064[v1154];
      int * v1066 = v1007->cache_dirty;
      int v1188 = (4 + ((((int)((unsigned int)((int)((unsigned int)v1014 >> 2)) >> 1)) & 3) * 2)) + ((((v1059 + ((~(((v1061 ^ -1) | (-(v1061 ^ -1))) >> 31)) & 2)) - (v1063 + ((~(((v1065 ^ -1) | (-(v1065 ^ -1))) >> 31)) & 2))) >> 31) & 1);
      int v1067 = v1066[v1188];
      bool v1189 = !(v1067 == 0);
      if (v1189) {
        int * v1068 = v1007->cache_tags;
        int v1069 = v1068[v1188];
        int * v1070 = v1007->cache_vals;
        int v1192 = ((4 + ((((int)((unsigned int)((int)((unsigned int)v1014 >> 2)) >> 1)) & 3) * 2)) + ((((v1059 + ((~(((v1061 ^ -1) | (-(v1061 ^ -1))) >> 31)) & 2)) - (v1063 + ((~(((v1065 ^ -1) | (-(v1065 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
        int v1071 = v1070[v1192];
        int * v1072 = v1007->cache_vals;
        int v1194 = (((4 + ((((int)((unsigned int)((int)((unsigned int)v1014 >> 2)) >> 1)) & 3) * 2)) + ((((v1059 + ((~(((v1061 ^ -1) | (-(v1061 ^ -1))) >> 31)) & 2)) - (v1063 + ((~(((v1065 ^ -1) | (-(v1065 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
        int v1073 = v1072[v1194];
        int * v1074 = v1007->mem;
        int v1196 = v1069 * 2;
        v1074[v1196] = v1071;
        int * v1076 = v1007->mem;
        int v1199 = (v1069 * 2) + 1;
        v1076[v1199] = v1073;
        ;
      } else {
        ;
      }
      int * v1081 = v1007->mem;
      int v1204 = ((int)((unsigned int)((int)((unsigned int)v1014 >> 2)) >> 1)) * 2;
      int v1082 = v1081[v1204];
      int * v1083 = v1007->mem;
      int v1206 = (((int)((unsigned int)((int)((unsigned int)v1014 >> 2)) >> 1)) * 2) + 1;
      int v1084 = v1083[v1206];
      int * v1085 = v1007->cache_vals;
      int v1208 = ((4 + ((((int)((unsigned int)((int)((unsigned int)v1014 >> 2)) >> 1)) & 3) * 2)) + ((((v1059 + ((~(((v1061 ^ -1) | (-(v1061 ^ -1))) >> 31)) & 2)) - (v1063 + ((~(((v1065 ^ -1) | (-(v1065 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
      v1085[v1208] = v1082;
      int * v1087 = v1007->cache_vals;
      int v1211 = (((4 + ((((int)((unsigned int)((int)((unsigned int)v1014 >> 2)) >> 1)) & 3) * 2)) + ((((v1059 + ((~(((v1061 ^ -1) | (-(v1061 ^ -1))) >> 31)) & 2)) - (v1063 + ((~(((v1065 ^ -1) | (-(v1065 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
      v1087[v1211] = v1084;
      int * v1089 = v1007->cache_tags;
      int v1214 = (int)((unsigned int)((int)((unsigned int)v1014 >> 2)) >> 1);
      v1089[v1188] = v1214;
      int * v1091 = v1007->cache_dirty;
      v1091[v1188] = 0;
      int * v1093 = v1007->cache_age;
      v1093[v1188] = 1;
      int * v1095 = v1007->cache_age;
      int v1096 = v1095[v1188];
      int * v1097 = v1007->cache_age;
      int v1098 = v1097[v1152];
      int * v1099 = v1007->cache_age;
      int v1222 = v1098 + ((int)((unsigned int)(v1098 - v1096) >> 31));
      v1099[v1152] = v1222;
      int * v1101 = v1007->cache_age;
      int v1102 = v1101[v1154];
      int * v1103 = v1007->cache_age;
      int v1225 = v1102 + ((int)((unsigned int)(v1102 - v1096) >> 31));
      v1103[v1154] = v1225;
      int * v1105 = v1007->cache_age;
      v1105[v1188] = 0;
      v1108 = v1188;
    }
    int * v1109 = v1007->cache_vals;
    int v1228 = v1108 * 2;
    int v1110 = v1109[v1228];
    int * v1111 = v1007->cache_vals;
    int v1230 = (v1108 * 2) + 1;
    int v1112 = v1111[v1230];
    int * v1113 = v1007->cache_vals;
    int v1232 = (((((int)((unsigned int)((int)((unsigned int)v1014 >> 2)) >> 1)) & 1) * 2) + ((((v1038 + ((~(((v1040 ^ -1) | (-(v1040 ^ -1))) >> 31)) & 2)) - (v1042 + ((~(((v1044 ^ -1) | (-(v1044 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
    v1113[v1232] = v1110;
    int * v1115 = v1007->cache_vals;
    int v1235 = ((((((int)((unsigned int)((int)((unsigned int)v1014 >> 2)) >> 1)) & 1) * 2) + ((((v1038 + ((~(((v1040 ^ -1) | (-(v1040 ^ -1))) >> 31)) & 2)) - (v1042 + ((~(((v1044 ^ -1) | (-(v1044 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
    v1115[v1235] = v1112;
    int * v1117 = v1007->cache_tags;
    int v1238 = ((((int)((unsigned int)((int)((unsigned int)v1014 >> 2)) >> 1)) & 1) * 2) + ((((v1038 + ((~(((v1040 ^ -1) | (-(v1040 ^ -1))) >> 31)) & 2)) - (v1042 + ((~(((v1044 ^ -1) | (-(v1044 ^ -1))) >> 31)) & 2))) >> 31) & 1);
    int v1239 = (int)((unsigned int)((int)((unsigned int)v1014 >> 2)) >> 1);
    v1117[v1238] = v1239;
    int * v1119 = v1007->cache_dirty;
    v1119[v1238] = 0;
    int * v1121 = v1007->cache_age;
    v1121[v1238] = 1;
    int * v1123 = v1007->cache_age;
    int v1124 = v1123[v1238];
    int * v1125 = v1007->cache_age;
    int v1126 = v1125[v1148];
    int * v1127 = v1007->cache_age;
    int v1247 = v1126 + ((int)((unsigned int)(v1126 - v1124) >> 31));
    v1127[v1148] = v1247;
    int * v1129 = v1007->cache_age;
    int v1130 = v1129[v1150];
    int * v1131 = v1007->cache_age;
    int v1250 = v1130 + ((int)((unsigned int)(v1130 - v1124) >> 31));
    v1131[v1150] = v1250;
    int * v1133 = v1007->cache_age;
    v1133[v1238] = 0;
    v1136 = v1238;
  }
  int v1253 = (v1136 * 2) + (((int)((unsigned int)v1014 >> 2)) & 1);
  int v1137 = v1023[v1253];
  int * v1138 = v1007->reg_ready;
  int v1256 = ((v1012 + ((v1008 - v1012) & (~((v1008 - v1012) >> 31)))) + 1) + ((100 ^ (((~(((v1020 ^ ((int)((unsigned int)((int)((unsigned int)v1014 >> 2)) >> 1))) | (-(v1020 ^ ((int)((unsigned int)((int)((unsigned int)v1014 >> 2)) >> 1))))) >> 31)) | (~(((v1022 ^ ((int)((unsigned int)((int)((unsigned int)v1014 >> 2)) >> 1))) | (-(v1022 ^ ((int)((unsigned int)((int)((unsigned int)v1014 >> 2)) >> 1))))) >> 31))) & 104)) ^ (((~(((v1016 ^ ((int)((unsigned int)((int)((unsigned int)v1014 >> 2)) >> 1))) | (-(v1016 ^ ((int)((unsigned int)((int)((unsigned int)v1014 >> 2)) >> 1))))) >> 31)) | (~(((v1018 ^ ((int)((unsigned int)((int)((unsigned int)v1014 >> 2)) >> 1))) | (-(v1018 ^ ((int)((unsigned int)((int)((unsigned int)v1014 >> 2)) >> 1))))) >> 31))) & (1 ^ (100 ^ (((~(((v1020 ^ ((int)((unsigned int)((int)((unsigned int)v1014 >> 2)) >> 1))) | (-(v1020 ^ ((int)((unsigned int)((int)((unsigned int)v1014 >> 2)) >> 1))))) >> 31)) | (~(((v1022 ^ ((int)((unsigned int)((int)((unsigned int)v1014 >> 2)) >> 1))) | (-(v1022 ^ ((int)((unsigned int)((int)((unsigned int)v1014 >> 2)) >> 1))))) >> 31))) & 104)))));
  v1138[12] = v1256;
  int * v1140 = v1007->regs;
  v1140[12] = v1137;
  return v1007;
}

struct StateT * slot_1(struct StateT * v27) {
  int v28 = v27->timer;
  int v29 = v27->timer;
  int v37 = v29 + 1;
  v27->timer = v37;
  int * v31 = v27->reg_ready;
  int v40 = v28 + 1;
  v31[9] = v40;
  int * v33 = v27->regs;
  v33[9] = 32;
  struct StateT * v35 = slot_2(v27);
  return v35;
}

struct StateT * slot_8(struct StateT * v728) {
  int v729 = v728->timer;
  int v730 = v728->timer;
  int v865 = v730 + 1;
  v728->timer = v865;
  int * v732 = v728->reg_ready;
  int v733 = v732[6];
  int * v734 = v728->regs;
  int v735 = v734[6];
  int * v736 = v728->cache_tags;
  int v870 = (((int)((unsigned int)((int)((unsigned int)v735 >> 2)) >> 1)) & 1) * 2;
  int v737 = v736[v870];
  int * v738 = v728->cache_tags;
  int v872 = ((((int)((unsigned int)((int)((unsigned int)v735 >> 2)) >> 1)) & 1) * 2) + 1;
  int v739 = v738[v872];
  int * v740 = v728->cache_tags;
  int v874 = 4 + ((((int)((unsigned int)((int)((unsigned int)v735 >> 2)) >> 1)) & 3) * 2);
  int v741 = v740[v874];
  int * v742 = v728->cache_tags;
  int v876 = (4 + ((((int)((unsigned int)((int)((unsigned int)v735 >> 2)) >> 1)) & 3) * 2)) + 1;
  int v743 = v742[v876];
  int * v744 = v728->cache_vals;
  bool v877 = !(((~(((v737 ^ ((int)((unsigned int)((int)((unsigned int)v735 >> 2)) >> 1))) | (-(v737 ^ ((int)((unsigned int)((int)((unsigned int)v735 >> 2)) >> 1))))) >> 31)) | (~(((v739 ^ ((int)((unsigned int)((int)((unsigned int)v735 >> 2)) >> 1))) | (-(v739 ^ ((int)((unsigned int)((int)((unsigned int)v735 >> 2)) >> 1))))) >> 31))) == 0);
  int v857;
  if (v877) {
    int * v745 = v728->cache_age;
    int v879 = ((((int)((unsigned int)((int)((unsigned int)v735 >> 2)) >> 1)) & 1) * 2) + ((~(((v739 ^ ((int)((unsigned int)((int)((unsigned int)v735 >> 2)) >> 1))) | (-(v739 ^ ((int)((unsigned int)((int)((unsigned int)v735 >> 2)) >> 1))))) >> 31)) & 1);
    int v746 = v745[v879];
    int * v747 = v728->cache_age;
    int v748 = v747[v870];
    int * v749 = v728->cache_age;
    int v882 = v748 + ((int)((unsigned int)(v748 - v746) >> 31));
    v749[v870] = v882;
    int * v751 = v728->cache_age;
    int v752 = v751[v872];
    int * v753 = v728->cache_age;
    int v885 = v752 + ((int)((unsigned int)(v752 - v746) >> 31));
    v753[v872] = v885;
    int * v755 = v728->cache_age;
    v755[v879] = 0;
    v857 = v879;
  } else {
    int * v758 = v728->cache_age;
    int v889 = (((int)((unsigned int)((int)((unsigned int)v735 >> 2)) >> 1)) & 1) * 2;
    int v759 = v758[v889];
    int * v760 = v728->cache_tags;
    int v761 = v760[v889];
    int * v762 = v728->cache_age;
    int v763 = v762[v872];
    int * v764 = v728->cache_tags;
    int v765 = v764[v872];
    bool v893 = !(((~(((v741 ^ ((int)((unsigned int)((int)((unsigned int)v735 >> 2)) >> 1))) | (-(v741 ^ ((int)((unsigned int)((int)((unsigned int)v735 >> 2)) >> 1))))) >> 31)) | (~(((v743 ^ ((int)((unsigned int)((int)((unsigned int)v735 >> 2)) >> 1))) | (-(v743 ^ ((int)((unsigned int)((int)((unsigned int)v735 >> 2)) >> 1))))) >> 31))) == 0);
    int v829;
    if (v893) {
      int * v766 = v728->cache_age;
      int v895 = (4 + ((((int)((unsigned int)((int)((unsigned int)v735 >> 2)) >> 1)) & 3) * 2)) + ((~(((v743 ^ ((int)((unsigned int)((int)((unsigned int)v735 >> 2)) >> 1))) | (-(v743 ^ ((int)((unsigned int)((int)((unsigned int)v735 >> 2)) >> 1))))) >> 31)) & 1);
      int v767 = v766[v895];
      int * v768 = v728->cache_age;
      int v769 = v768[v874];
      int * v770 = v728->cache_age;
      int v898 = v769 + ((int)((unsigned int)(v769 - v767) >> 31));
      v770[v874] = v898;
      int * v772 = v728->cache_age;
      int v773 = v772[v876];
      int * v774 = v728->cache_age;
      int v901 = v773 + ((int)((unsigned int)(v773 - v767) >> 31));
      v774[v876] = v901;
      int * v776 = v728->cache_age;
      v776[v895] = 0;
      v829 = v895;
    } else {
      int * v779 = v728->cache_age;
      int v905 = 4 + ((((int)((unsigned int)((int)((unsigned int)v735 >> 2)) >> 1)) & 3) * 2);
      int v780 = v779[v905];
      int * v781 = v728->cache_tags;
      int v782 = v781[v905];
      int * v783 = v728->cache_age;
      int v784 = v783[v876];
      int * v785 = v728->cache_tags;
      int v786 = v785[v876];
      int * v787 = v728->cache_dirty;
      int v910 = (4 + ((((int)((unsigned int)((int)((unsigned int)v735 >> 2)) >> 1)) & 3) * 2)) + ((((v780 + ((~(((v782 ^ -1) | (-(v782 ^ -1))) >> 31)) & 2)) - (v784 + ((~(((v786 ^ -1) | (-(v786 ^ -1))) >> 31)) & 2))) >> 31) & 1);
      int v788 = v787[v910];
      bool v911 = !(v788 == 0);
      if (v911) {
        int * v789 = v728->cache_tags;
        int v790 = v789[v910];
        int * v791 = v728->cache_vals;
        int v914 = ((4 + ((((int)((unsigned int)((int)((unsigned int)v735 >> 2)) >> 1)) & 3) * 2)) + ((((v780 + ((~(((v782 ^ -1) | (-(v782 ^ -1))) >> 31)) & 2)) - (v784 + ((~(((v786 ^ -1) | (-(v786 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
        int v792 = v791[v914];
        int * v793 = v728->cache_vals;
        int v916 = (((4 + ((((int)((unsigned int)((int)((unsigned int)v735 >> 2)) >> 1)) & 3) * 2)) + ((((v780 + ((~(((v782 ^ -1) | (-(v782 ^ -1))) >> 31)) & 2)) - (v784 + ((~(((v786 ^ -1) | (-(v786 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
        int v794 = v793[v916];
        int * v795 = v728->mem;
        int v918 = v790 * 2;
        v795[v918] = v792;
        int * v797 = v728->mem;
        int v921 = (v790 * 2) + 1;
        v797[v921] = v794;
        ;
      } else {
        ;
      }
      int * v802 = v728->mem;
      int v926 = ((int)((unsigned int)((int)((unsigned int)v735 >> 2)) >> 1)) * 2;
      int v803 = v802[v926];
      int * v804 = v728->mem;
      int v928 = (((int)((unsigned int)((int)((unsigned int)v735 >> 2)) >> 1)) * 2) + 1;
      int v805 = v804[v928];
      int * v806 = v728->cache_vals;
      int v930 = ((4 + ((((int)((unsigned int)((int)((unsigned int)v735 >> 2)) >> 1)) & 3) * 2)) + ((((v780 + ((~(((v782 ^ -1) | (-(v782 ^ -1))) >> 31)) & 2)) - (v784 + ((~(((v786 ^ -1) | (-(v786 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
      v806[v930] = v803;
      int * v808 = v728->cache_vals;
      int v933 = (((4 + ((((int)((unsigned int)((int)((unsigned int)v735 >> 2)) >> 1)) & 3) * 2)) + ((((v780 + ((~(((v782 ^ -1) | (-(v782 ^ -1))) >> 31)) & 2)) - (v784 + ((~(((v786 ^ -1) | (-(v786 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
      v808[v933] = v805;
      int * v810 = v728->cache_tags;
      int v936 = (int)((unsigned int)((int)((unsigned int)v735 >> 2)) >> 1);
      v810[v910] = v936;
      int * v812 = v728->cache_dirty;
      v812[v910] = 0;
      int * v814 = v728->cache_age;
      v814[v910] = 1;
      int * v816 = v728->cache_age;
      int v817 = v816[v910];
      int * v818 = v728->cache_age;
      int v819 = v818[v874];
      int * v820 = v728->cache_age;
      int v944 = v819 + ((int)((unsigned int)(v819 - v817) >> 31));
      v820[v874] = v944;
      int * v822 = v728->cache_age;
      int v823 = v822[v876];
      int * v824 = v728->cache_age;
      int v947 = v823 + ((int)((unsigned int)(v823 - v817) >> 31));
      v824[v876] = v947;
      int * v826 = v728->cache_age;
      v826[v910] = 0;
      v829 = v910;
    }
    int * v830 = v728->cache_vals;
    int v950 = v829 * 2;
    int v831 = v830[v950];
    int * v832 = v728->cache_vals;
    int v952 = (v829 * 2) + 1;
    int v833 = v832[v952];
    int * v834 = v728->cache_vals;
    int v954 = (((((int)((unsigned int)((int)((unsigned int)v735 >> 2)) >> 1)) & 1) * 2) + ((((v759 + ((~(((v761 ^ -1) | (-(v761 ^ -1))) >> 31)) & 2)) - (v763 + ((~(((v765 ^ -1) | (-(v765 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
    v834[v954] = v831;
    int * v836 = v728->cache_vals;
    int v957 = ((((((int)((unsigned int)((int)((unsigned int)v735 >> 2)) >> 1)) & 1) * 2) + ((((v759 + ((~(((v761 ^ -1) | (-(v761 ^ -1))) >> 31)) & 2)) - (v763 + ((~(((v765 ^ -1) | (-(v765 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
    v836[v957] = v833;
    int * v838 = v728->cache_tags;
    int v960 = ((((int)((unsigned int)((int)((unsigned int)v735 >> 2)) >> 1)) & 1) * 2) + ((((v759 + ((~(((v761 ^ -1) | (-(v761 ^ -1))) >> 31)) & 2)) - (v763 + ((~(((v765 ^ -1) | (-(v765 ^ -1))) >> 31)) & 2))) >> 31) & 1);
    int v961 = (int)((unsigned int)((int)((unsigned int)v735 >> 2)) >> 1);
    v838[v960] = v961;
    int * v840 = v728->cache_dirty;
    v840[v960] = 0;
    int * v842 = v728->cache_age;
    v842[v960] = 1;
    int * v844 = v728->cache_age;
    int v845 = v844[v960];
    int * v846 = v728->cache_age;
    int v847 = v846[v870];
    int * v848 = v728->cache_age;
    int v969 = v847 + ((int)((unsigned int)(v847 - v845) >> 31));
    v848[v870] = v969;
    int * v850 = v728->cache_age;
    int v851 = v850[v872];
    int * v852 = v728->cache_age;
    int v972 = v851 + ((int)((unsigned int)(v851 - v845) >> 31));
    v852[v872] = v972;
    int * v854 = v728->cache_age;
    v854[v960] = 0;
    v857 = v960;
  }
  int v975 = (v857 * 2) + (((int)((unsigned int)v735 >> 2)) & 1);
  int v858 = v744[v975];
  int * v859 = v728->reg_ready;
  int v978 = ((v733 + ((v729 - v733) & (~((v729 - v733) >> 31)))) + 1) + ((100 ^ (((~(((v741 ^ ((int)((unsigned int)((int)((unsigned int)v735 >> 2)) >> 1))) | (-(v741 ^ ((int)((unsigned int)((int)((unsigned int)v735 >> 2)) >> 1))))) >> 31)) | (~(((v743 ^ ((int)((unsigned int)((int)((unsigned int)v735 >> 2)) >> 1))) | (-(v743 ^ ((int)((unsigned int)((int)((unsigned int)v735 >> 2)) >> 1))))) >> 31))) & 104)) ^ (((~(((v737 ^ ((int)((unsigned int)((int)((unsigned int)v735 >> 2)) >> 1))) | (-(v737 ^ ((int)((unsigned int)((int)((unsigned int)v735 >> 2)) >> 1))))) >> 31)) | (~(((v739 ^ ((int)((unsigned int)((int)((unsigned int)v735 >> 2)) >> 1))) | (-(v739 ^ ((int)((unsigned int)((int)((unsigned int)v735 >> 2)) >> 1))))) >> 31))) & (1 ^ (100 ^ (((~(((v741 ^ ((int)((unsigned int)((int)((unsigned int)v735 >> 2)) >> 1))) | (-(v741 ^ ((int)((unsigned int)((int)((unsigned int)v735 >> 2)) >> 1))))) >> 31)) | (~(((v743 ^ ((int)((unsigned int)((int)((unsigned int)v735 >> 2)) >> 1))) | (-(v743 ^ ((int)((unsigned int)((int)((unsigned int)v735 >> 2)) >> 1))))) >> 31))) & 104)))));
  v859[11] = v978;
  int * v861 = v728->regs;
  v861[11] = v858;
  struct StateT * v863 = slot_9(v728);
  return v863;
}

struct StateT * slot_4(struct StateT * v86) {
  int * v87 = v86->saved_regs;
  int * v88 = v86->regs;
  int v89 = v88[7];
  v87[7] = v89;
  int v91 = v86->timer;
  int v92 = v86->timer;
  int v104 = v92 + 1;
  v86->timer = v104;
  int * v94 = v86->reg_ready;
  int v106 = v91 + 1;
  v94[7] = v106;
  int * v96 = v86->regs;
  v96[7] = 0;
  struct StateT * v98 = slot_5(v86);
  return v98;
}

struct StateT * slot_9(struct StateT * v983) {
  int v984 = v983->timer;
  int v985 = v983->timer;
  int v997 = v985 + 1;
  v983->timer = v997;
  int * v987 = v983->reg_ready;
  int v988 = v987[11];
  int * v989 = v983->regs;
  int v990 = v989[11];
  int * v991 = v983->reg_ready;
  int v1002 = (v988 + ((v984 - v988) & (~((v984 - v988) >> 31)))) + 1;
  v991[11] = v1002;
  int * v993 = v983->regs;
  int v1004 = v990 << 2;
  v993[11] = v1004;
  struct StateT * v995 = slot_10(v983);
  return v995;
}

struct StateT * slot_0(struct StateT * v2) {
  int v3 = v2->timer;
  int v4 = v2->timer;
  int v16 = v4 + 1;
  v2->timer = v16;
  int * v6 = v2->reg_ready;
  int v7 = v6[10];
  int * v8 = v2->regs;
  int v9 = v8[10];
  int * v10 = v2->reg_ready;
  int v22 = (v7 + ((v3 - v7) & (~((v3 - v7) >> 31)))) + 1;
  v10[5] = v22;
  int * v12 = v2->regs;
  int v24 = v9 & 28;
  v12[5] = v24;
  struct StateT * v14 = slot_1(v2);
  return v14;
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
  koika_assert(s1_->timer==s2_->timer, "timing leak");
  return 0;
}