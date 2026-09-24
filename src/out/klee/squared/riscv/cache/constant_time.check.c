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

struct StateT2 {
  struct StateT * a;
  struct StateT * b;
};

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

void squared_assert(bool);
void squared_assume(bool);
void squared_diverged(bool);

struct StateT2 * slot_12(struct StateT2 * v1511);
struct StateT2 * slot_14(struct StateT2 * v235);
struct StateT2 * slot_6(struct StateT2 * v288);
struct StateT2 * slot_5(struct StateT2 * v182);
struct StateT2 * slot_2(struct StateT2 * v74);
struct StateT2 * slot_7(struct StateT2 * v339);
struct StateT2 * slot_3(struct StateT2 * v110);
struct StateT2 * snippet(struct StateT2 * v0);
struct StateT2 * slot_10(struct StateT2 * v1410);
struct StateT2 * slot_1(struct StateT2 * v38);
struct StateT2 * slot_8(struct StateT2 * v849);
struct StateT2 * slot_4(struct StateT2 * v146);
struct StateT2 * slot_13(struct StateT2 * v1554);
struct StateT2 * slot_9(struct StateT2 * v900);
struct StateT2 * slot_11(struct StateT2 * v1461);
struct StateT2 * slot_0(struct StateT2 * v2);
struct StateT2 * slot_12(struct StateT2 * v1511) {
  struct StateT * v1512 = v1511->a;
  int v1513 = v1512->timer;
  struct StateT * v1514 = v1511->b;
  int v1515 = v1514->timer;
  bool v1538 = v1513 == v1515;
  squared_assert(v1538);
  squared_assume(v1538);
  struct StateT * v1518 = v1511->a;
  int v1519 = v1518->timer;
  int v1540 = v1519 + 1;
  v1518->timer = v1540;
  struct StateT * v1521 = v1511->b;
  int v1522 = v1521->timer;
  int v1542 = v1522 + 1;
  v1521->timer = v1542;
  struct StateT * v1524 = v1511->a;
  int * v1525 = v1524->regs;
  int v1526 = v1525[14];
  int * v1527 = v1524->regs;
  int v1547 = v1526 + 4;
  v1527[14] = v1547;
  struct StateT * v1529 = v1511->b;
  int * v1530 = v1529->regs;
  int v1531 = v1530[14];
  int * v1532 = v1529->regs;
  int v1551 = v1531 + 4;
  v1532[14] = v1551;
  struct StateT2 * v1534 = slot_13(v1511);
  return v1534;
}

struct StateT2 * slot_14(struct StateT2 * v235) {
  struct StateT * v236 = v235->a;
  int v237 = v236->timer;
  struct StateT * v238 = v235->b;
  int v239 = v238->timer;
  bool v267 = v237 == v239;
  squared_assert(v267);
  squared_assume(v267);
  struct StateT * v242 = v235->a;
  int v243 = v242->timer;
  int v269 = v243 + 1;
  v242->timer = v269;
  struct StateT * v245 = v235->b;
  int v246 = v245->timer;
  int v271 = v246 + 1;
  v245->timer = v271;
  struct StateT * v248 = v235->a;
  int * v249 = v248->regs;
  int v250 = v249[5];
  bool v275 = (v250 ^ -2147483648) < -2147483647;
  int v253;
  if (v275) {
    v253 = 1;
  } else {
    v253 = 0;
  }
  int * v254 = v248->regs;
  v254[11] = v253;
  struct StateT * v256 = v235->b;
  int * v257 = v256->regs;
  int v258 = v257[5];
  bool v283 = (v258 ^ -2147483648) < -2147483647;
  int v261;
  if (v283) {
    v261 = 1;
  } else {
    v261 = 0;
  }
  int * v262 = v256->regs;
  v262[11] = v261;
  return v235;
}

struct StateT2 * slot_6(struct StateT2 * v288) {
  struct StateT * v289 = v288->a;
  int v290 = v289->timer;
  struct StateT * v291 = v288->b;
  int v292 = v291->timer;
  bool v319 = v290 == v292;
  squared_assert(v319);
  squared_assume(v319);
  struct StateT * v295 = v288->a;
  int v296 = v295->timer;
  int v321 = v296 + 1;
  v295->timer = v321;
  struct StateT * v298 = v288->b;
  int v299 = v298->timer;
  int v323 = v299 + 1;
  v298->timer = v323;
  struct StateT * v301 = v288->a;
  int * v302 = v301->regs;
  int v303 = v302[12];
  int * v304 = v301->regs;
  int v305 = v304[14];
  int * v306 = v301->regs;
  int v331 = v303 + v305;
  v306[6] = v331;
  struct StateT * v308 = v288->b;
  int * v309 = v308->regs;
  int v310 = v309[12];
  int * v311 = v308->regs;
  int v312 = v311[14];
  int * v313 = v308->regs;
  int v336 = v310 + v312;
  v313[6] = v336;
  struct StateT2 * v315 = slot_7(v288);
  return v315;
}

struct StateT2 * slot_5(struct StateT2 * v182) {
  struct StateT * v183 = v182->a;
  int v184 = v183->timer;
  struct StateT * v185 = v182->b;
  int v186 = v185->timer;
  bool v215 = v184 == v186;
  squared_assert(v215);
  squared_assume(v215);
  struct StateT * v189 = v182->a;
  int v190 = v189->timer;
  int v217 = v190 + 1;
  v189->timer = v217;
  struct StateT * v192 = v182->b;
  int v193 = v192->timer;
  int v219 = v193 + 1;
  v192->timer = v219;
  struct StateT * v195 = v182->a;
  int * v196 = v195->regs;
  int v197 = v196[14];
  int * v198 = v195->regs;
  int v199 = v198[15];
  struct StateT * v200 = v182->b;
  int * v201 = v200->regs;
  int v202 = v201[14];
  int * v203 = v200->regs;
  int v204 = v203[15];
  bool v228 = (v197 >= v199) == (v202 >= v204);
  squared_diverged(v228);
  squared_assume(v228);
  bool v229 = v197 >= v199;
  struct StateT2 * v211;
  if (v229) {
    struct StateT2 * v207 = slot_14(v182);
    v211 = v207;
  } else {
    struct StateT2 * v209 = slot_6(v182);
    v211 = v209;
  }
  return v211;
}

struct StateT2 * slot_2(struct StateT2 * v74) {
  struct StateT * v75 = v74->a;
  int v76 = v75->timer;
  struct StateT * v77 = v74->b;
  int v78 = v77->timer;
  bool v97 = v76 == v78;
  squared_assert(v97);
  squared_assume(v97);
  struct StateT * v81 = v74->a;
  int v82 = v81->timer;
  int v99 = v82 + 1;
  v81->timer = v99;
  struct StateT * v84 = v74->b;
  int v85 = v84->timer;
  int v101 = v85 + 1;
  v84->timer = v101;
  struct StateT * v87 = v74->a;
  int * v88 = v87->regs;
  v88[14] = 0;
  struct StateT * v90 = v74->b;
  int * v91 = v90->regs;
  v91[14] = 0;
  struct StateT2 * v93 = slot_3(v74);
  return v93;
}

struct StateT2 * slot_7(struct StateT2 * v339) {
  struct StateT * v340 = v339->a;
  int v341 = v340->timer;
  struct StateT * v342 = v339->b;
  int v343 = v342->timer;
  bool v616 = v341 == v343;
  squared_assert(v616);
  squared_assume(v616);
  struct StateT * v346 = v339->a;
  int v347 = v346->timer;
  int v618 = v347 + 1;
  v346->timer = v618;
  struct StateT * v349 = v339->b;
  int v350 = v349->timer;
  int v620 = v350 + 1;
  v349->timer = v620;
  struct StateT * v352 = v339->a;
  int * v353 = v352->regs;
  int v354 = v353[6];
  int * v355 = v352->cache_tags;
  int v625 = (((int)((unsigned int)((int)((unsigned int)v354 >> 2)) >> 1)) & 1) * 2;
  int v356 = v355[v625];
  int * v357 = v352->cache_tags;
  int v627 = ((((int)((unsigned int)((int)((unsigned int)v354 >> 2)) >> 1)) & 1) * 2) + 1;
  int v358 = v357[v627];
  int * v359 = v352->cache_tags;
  int v629 = 4 + ((((int)((unsigned int)((int)((unsigned int)v354 >> 2)) >> 1)) & 3) * 2);
  int v360 = v359[v629];
  int * v361 = v352->cache_tags;
  int v631 = (4 + ((((int)((unsigned int)((int)((unsigned int)v354 >> 2)) >> 1)) & 3) * 2)) + 1;
  int v362 = v361[v631];
  int v363 = v352->timer;
  int v632 = v363 + ((100 ^ (((~(((v360 ^ ((int)((unsigned int)((int)((unsigned int)v354 >> 2)) >> 1))) | (-(v360 ^ ((int)((unsigned int)((int)((unsigned int)v354 >> 2)) >> 1))))) >> 31)) | (~(((v362 ^ ((int)((unsigned int)((int)((unsigned int)v354 >> 2)) >> 1))) | (-(v362 ^ ((int)((unsigned int)((int)((unsigned int)v354 >> 2)) >> 1))))) >> 31))) & 104)) ^ (((~(((v356 ^ ((int)((unsigned int)((int)((unsigned int)v354 >> 2)) >> 1))) | (-(v356 ^ ((int)((unsigned int)((int)((unsigned int)v354 >> 2)) >> 1))))) >> 31)) | (~(((v358 ^ ((int)((unsigned int)((int)((unsigned int)v354 >> 2)) >> 1))) | (-(v358 ^ ((int)((unsigned int)((int)((unsigned int)v354 >> 2)) >> 1))))) >> 31))) & (1 ^ (100 ^ (((~(((v360 ^ ((int)((unsigned int)((int)((unsigned int)v354 >> 2)) >> 1))) | (-(v360 ^ ((int)((unsigned int)((int)((unsigned int)v354 >> 2)) >> 1))))) >> 31)) | (~(((v362 ^ ((int)((unsigned int)((int)((unsigned int)v354 >> 2)) >> 1))) | (-(v362 ^ ((int)((unsigned int)((int)((unsigned int)v354 >> 2)) >> 1))))) >> 31))) & 104)))));
  v352->timer = v632;
  int * v365 = v352->cache_vals;
  bool v633 = !(((~(((v356 ^ ((int)((unsigned int)((int)((unsigned int)v354 >> 2)) >> 1))) | (-(v356 ^ ((int)((unsigned int)((int)((unsigned int)v354 >> 2)) >> 1))))) >> 31)) | (~(((v358 ^ ((int)((unsigned int)((int)((unsigned int)v354 >> 2)) >> 1))) | (-(v358 ^ ((int)((unsigned int)((int)((unsigned int)v354 >> 2)) >> 1))))) >> 31))) == 0);
  int v478;
  if (v633) {
    int * v366 = v352->cache_age;
    int v635 = ((((int)((unsigned int)((int)((unsigned int)v354 >> 2)) >> 1)) & 1) * 2) + ((~(((v358 ^ ((int)((unsigned int)((int)((unsigned int)v354 >> 2)) >> 1))) | (-(v358 ^ ((int)((unsigned int)((int)((unsigned int)v354 >> 2)) >> 1))))) >> 31)) & 1);
    int v367 = v366[v635];
    int * v368 = v352->cache_age;
    int v369 = v368[v625];
    int * v370 = v352->cache_age;
    int v638 = v369 + ((int)((unsigned int)(v369 - v367) >> 31));
    v370[v625] = v638;
    int * v372 = v352->cache_age;
    int v373 = v372[v627];
    int * v374 = v352->cache_age;
    int v641 = v373 + ((int)((unsigned int)(v373 - v367) >> 31));
    v374[v627] = v641;
    int * v376 = v352->cache_age;
    v376[v635] = 0;
    v478 = v635;
  } else {
    int * v379 = v352->cache_age;
    int v645 = (((int)((unsigned int)((int)((unsigned int)v354 >> 2)) >> 1)) & 1) * 2;
    int v380 = v379[v645];
    int * v381 = v352->cache_tags;
    int v382 = v381[v645];
    int * v383 = v352->cache_age;
    int v384 = v383[v627];
    int * v385 = v352->cache_tags;
    int v386 = v385[v627];
    bool v649 = !(((~(((v360 ^ ((int)((unsigned int)((int)((unsigned int)v354 >> 2)) >> 1))) | (-(v360 ^ ((int)((unsigned int)((int)((unsigned int)v354 >> 2)) >> 1))))) >> 31)) | (~(((v362 ^ ((int)((unsigned int)((int)((unsigned int)v354 >> 2)) >> 1))) | (-(v362 ^ ((int)((unsigned int)((int)((unsigned int)v354 >> 2)) >> 1))))) >> 31))) == 0);
    int v450;
    if (v649) {
      int * v387 = v352->cache_age;
      int v651 = (4 + ((((int)((unsigned int)((int)((unsigned int)v354 >> 2)) >> 1)) & 3) * 2)) + ((~(((v362 ^ ((int)((unsigned int)((int)((unsigned int)v354 >> 2)) >> 1))) | (-(v362 ^ ((int)((unsigned int)((int)((unsigned int)v354 >> 2)) >> 1))))) >> 31)) & 1);
      int v388 = v387[v651];
      int * v389 = v352->cache_age;
      int v390 = v389[v629];
      int * v391 = v352->cache_age;
      int v654 = v390 + ((int)((unsigned int)(v390 - v388) >> 31));
      v391[v629] = v654;
      int * v393 = v352->cache_age;
      int v394 = v393[v631];
      int * v395 = v352->cache_age;
      int v657 = v394 + ((int)((unsigned int)(v394 - v388) >> 31));
      v395[v631] = v657;
      int * v397 = v352->cache_age;
      v397[v651] = 0;
      v450 = v651;
    } else {
      int * v400 = v352->cache_age;
      int v661 = 4 + ((((int)((unsigned int)((int)((unsigned int)v354 >> 2)) >> 1)) & 3) * 2);
      int v401 = v400[v661];
      int * v402 = v352->cache_tags;
      int v403 = v402[v661];
      int * v404 = v352->cache_age;
      int v405 = v404[v631];
      int * v406 = v352->cache_tags;
      int v407 = v406[v631];
      int * v408 = v352->cache_dirty;
      int v666 = (4 + ((((int)((unsigned int)((int)((unsigned int)v354 >> 2)) >> 1)) & 3) * 2)) + ((((v401 + ((~(((v403 ^ -1) | (-(v403 ^ -1))) >> 31)) & 2)) - (v405 + ((~(((v407 ^ -1) | (-(v407 ^ -1))) >> 31)) & 2))) >> 31) & 1);
      int v409 = v408[v666];
      bool v667 = !(v409 == 0);
      if (v667) {
        int * v410 = v352->cache_tags;
        int v411 = v410[v666];
        int * v412 = v352->cache_vals;
        int v670 = ((4 + ((((int)((unsigned int)((int)((unsigned int)v354 >> 2)) >> 1)) & 3) * 2)) + ((((v401 + ((~(((v403 ^ -1) | (-(v403 ^ -1))) >> 31)) & 2)) - (v405 + ((~(((v407 ^ -1) | (-(v407 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
        int v413 = v412[v670];
        int * v414 = v352->cache_vals;
        int v672 = (((4 + ((((int)((unsigned int)((int)((unsigned int)v354 >> 2)) >> 1)) & 3) * 2)) + ((((v401 + ((~(((v403 ^ -1) | (-(v403 ^ -1))) >> 31)) & 2)) - (v405 + ((~(((v407 ^ -1) | (-(v407 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
        int v415 = v414[v672];
        int * v416 = v352->mem;
        int v674 = v411 * 2;
        v416[v674] = v413;
        int * v418 = v352->mem;
        int v677 = (v411 * 2) + 1;
        v418[v677] = v415;
        ;
      } else {
        ;
      }
      int * v423 = v352->mem;
      int v682 = ((int)((unsigned int)((int)((unsigned int)v354 >> 2)) >> 1)) * 2;
      int v424 = v423[v682];
      int * v425 = v352->mem;
      int v684 = (((int)((unsigned int)((int)((unsigned int)v354 >> 2)) >> 1)) * 2) + 1;
      int v426 = v425[v684];
      int * v427 = v352->cache_vals;
      int v686 = ((4 + ((((int)((unsigned int)((int)((unsigned int)v354 >> 2)) >> 1)) & 3) * 2)) + ((((v401 + ((~(((v403 ^ -1) | (-(v403 ^ -1))) >> 31)) & 2)) - (v405 + ((~(((v407 ^ -1) | (-(v407 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
      v427[v686] = v424;
      int * v429 = v352->cache_vals;
      int v689 = (((4 + ((((int)((unsigned int)((int)((unsigned int)v354 >> 2)) >> 1)) & 3) * 2)) + ((((v401 + ((~(((v403 ^ -1) | (-(v403 ^ -1))) >> 31)) & 2)) - (v405 + ((~(((v407 ^ -1) | (-(v407 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
      v429[v689] = v426;
      int * v431 = v352->cache_tags;
      int v692 = (int)((unsigned int)((int)((unsigned int)v354 >> 2)) >> 1);
      v431[v666] = v692;
      int * v433 = v352->cache_dirty;
      v433[v666] = 0;
      int * v435 = v352->cache_age;
      v435[v666] = 1;
      int * v437 = v352->cache_age;
      int v438 = v437[v666];
      int * v439 = v352->cache_age;
      int v440 = v439[v629];
      int * v441 = v352->cache_age;
      int v700 = v440 + ((int)((unsigned int)(v440 - v438) >> 31));
      v441[v629] = v700;
      int * v443 = v352->cache_age;
      int v444 = v443[v631];
      int * v445 = v352->cache_age;
      int v703 = v444 + ((int)((unsigned int)(v444 - v438) >> 31));
      v445[v631] = v703;
      int * v447 = v352->cache_age;
      v447[v666] = 0;
      v450 = v666;
    }
    int * v451 = v352->cache_vals;
    int v706 = v450 * 2;
    int v452 = v451[v706];
    int * v453 = v352->cache_vals;
    int v708 = (v450 * 2) + 1;
    int v454 = v453[v708];
    int * v455 = v352->cache_vals;
    int v710 = (((((int)((unsigned int)((int)((unsigned int)v354 >> 2)) >> 1)) & 1) * 2) + ((((v380 + ((~(((v382 ^ -1) | (-(v382 ^ -1))) >> 31)) & 2)) - (v384 + ((~(((v386 ^ -1) | (-(v386 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
    v455[v710] = v452;
    int * v457 = v352->cache_vals;
    int v713 = ((((((int)((unsigned int)((int)((unsigned int)v354 >> 2)) >> 1)) & 1) * 2) + ((((v380 + ((~(((v382 ^ -1) | (-(v382 ^ -1))) >> 31)) & 2)) - (v384 + ((~(((v386 ^ -1) | (-(v386 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
    v457[v713] = v454;
    int * v459 = v352->cache_tags;
    int v716 = ((((int)((unsigned int)((int)((unsigned int)v354 >> 2)) >> 1)) & 1) * 2) + ((((v380 + ((~(((v382 ^ -1) | (-(v382 ^ -1))) >> 31)) & 2)) - (v384 + ((~(((v386 ^ -1) | (-(v386 ^ -1))) >> 31)) & 2))) >> 31) & 1);
    int v717 = (int)((unsigned int)((int)((unsigned int)v354 >> 2)) >> 1);
    v459[v716] = v717;
    int * v461 = v352->cache_dirty;
    v461[v716] = 0;
    int * v463 = v352->cache_age;
    v463[v716] = 1;
    int * v465 = v352->cache_age;
    int v466 = v465[v716];
    int * v467 = v352->cache_age;
    int v468 = v467[v625];
    int * v469 = v352->cache_age;
    int v725 = v468 + ((int)((unsigned int)(v468 - v466) >> 31));
    v469[v625] = v725;
    int * v471 = v352->cache_age;
    int v472 = v471[v627];
    int * v473 = v352->cache_age;
    int v728 = v472 + ((int)((unsigned int)(v472 - v466) >> 31));
    v473[v627] = v728;
    int * v475 = v352->cache_age;
    v475[v716] = 0;
    v478 = v716;
  }
  int v731 = (v478 * 2) + (((int)((unsigned int)v354 >> 2)) & 1);
  int v479 = v365[v731];
  int * v480 = v352->regs;
  v480[7] = v479;
  struct StateT * v482 = v339->b;
  int * v483 = v482->regs;
  int v484 = v483[6];
  int * v485 = v482->cache_tags;
  int v738 = (((int)((unsigned int)((int)((unsigned int)v484 >> 2)) >> 1)) & 1) * 2;
  int v486 = v485[v738];
  int * v487 = v482->cache_tags;
  int v740 = ((((int)((unsigned int)((int)((unsigned int)v484 >> 2)) >> 1)) & 1) * 2) + 1;
  int v488 = v487[v740];
  int * v489 = v482->cache_tags;
  int v742 = 4 + ((((int)((unsigned int)((int)((unsigned int)v484 >> 2)) >> 1)) & 3) * 2);
  int v490 = v489[v742];
  int * v491 = v482->cache_tags;
  int v744 = (4 + ((((int)((unsigned int)((int)((unsigned int)v484 >> 2)) >> 1)) & 3) * 2)) + 1;
  int v492 = v491[v744];
  int v493 = v482->timer;
  int v745 = v493 + ((100 ^ (((~(((v490 ^ ((int)((unsigned int)((int)((unsigned int)v484 >> 2)) >> 1))) | (-(v490 ^ ((int)((unsigned int)((int)((unsigned int)v484 >> 2)) >> 1))))) >> 31)) | (~(((v492 ^ ((int)((unsigned int)((int)((unsigned int)v484 >> 2)) >> 1))) | (-(v492 ^ ((int)((unsigned int)((int)((unsigned int)v484 >> 2)) >> 1))))) >> 31))) & 104)) ^ (((~(((v486 ^ ((int)((unsigned int)((int)((unsigned int)v484 >> 2)) >> 1))) | (-(v486 ^ ((int)((unsigned int)((int)((unsigned int)v484 >> 2)) >> 1))))) >> 31)) | (~(((v488 ^ ((int)((unsigned int)((int)((unsigned int)v484 >> 2)) >> 1))) | (-(v488 ^ ((int)((unsigned int)((int)((unsigned int)v484 >> 2)) >> 1))))) >> 31))) & (1 ^ (100 ^ (((~(((v490 ^ ((int)((unsigned int)((int)((unsigned int)v484 >> 2)) >> 1))) | (-(v490 ^ ((int)((unsigned int)((int)((unsigned int)v484 >> 2)) >> 1))))) >> 31)) | (~(((v492 ^ ((int)((unsigned int)((int)((unsigned int)v484 >> 2)) >> 1))) | (-(v492 ^ ((int)((unsigned int)((int)((unsigned int)v484 >> 2)) >> 1))))) >> 31))) & 104)))));
  v482->timer = v745;
  int * v495 = v482->cache_vals;
  bool v746 = !(((~(((v486 ^ ((int)((unsigned int)((int)((unsigned int)v484 >> 2)) >> 1))) | (-(v486 ^ ((int)((unsigned int)((int)((unsigned int)v484 >> 2)) >> 1))))) >> 31)) | (~(((v488 ^ ((int)((unsigned int)((int)((unsigned int)v484 >> 2)) >> 1))) | (-(v488 ^ ((int)((unsigned int)((int)((unsigned int)v484 >> 2)) >> 1))))) >> 31))) == 0);
  int v608;
  if (v746) {
    int * v496 = v482->cache_age;
    int v748 = ((((int)((unsigned int)((int)((unsigned int)v484 >> 2)) >> 1)) & 1) * 2) + ((~(((v488 ^ ((int)((unsigned int)((int)((unsigned int)v484 >> 2)) >> 1))) | (-(v488 ^ ((int)((unsigned int)((int)((unsigned int)v484 >> 2)) >> 1))))) >> 31)) & 1);
    int v497 = v496[v748];
    int * v498 = v482->cache_age;
    int v499 = v498[v738];
    int * v500 = v482->cache_age;
    int v751 = v499 + ((int)((unsigned int)(v499 - v497) >> 31));
    v500[v738] = v751;
    int * v502 = v482->cache_age;
    int v503 = v502[v740];
    int * v504 = v482->cache_age;
    int v754 = v503 + ((int)((unsigned int)(v503 - v497) >> 31));
    v504[v740] = v754;
    int * v506 = v482->cache_age;
    v506[v748] = 0;
    v608 = v748;
  } else {
    int * v509 = v482->cache_age;
    int v758 = (((int)((unsigned int)((int)((unsigned int)v484 >> 2)) >> 1)) & 1) * 2;
    int v510 = v509[v758];
    int * v511 = v482->cache_tags;
    int v512 = v511[v758];
    int * v513 = v482->cache_age;
    int v514 = v513[v740];
    int * v515 = v482->cache_tags;
    int v516 = v515[v740];
    bool v762 = !(((~(((v490 ^ ((int)((unsigned int)((int)((unsigned int)v484 >> 2)) >> 1))) | (-(v490 ^ ((int)((unsigned int)((int)((unsigned int)v484 >> 2)) >> 1))))) >> 31)) | (~(((v492 ^ ((int)((unsigned int)((int)((unsigned int)v484 >> 2)) >> 1))) | (-(v492 ^ ((int)((unsigned int)((int)((unsigned int)v484 >> 2)) >> 1))))) >> 31))) == 0);
    int v580;
    if (v762) {
      int * v517 = v482->cache_age;
      int v764 = (4 + ((((int)((unsigned int)((int)((unsigned int)v484 >> 2)) >> 1)) & 3) * 2)) + ((~(((v492 ^ ((int)((unsigned int)((int)((unsigned int)v484 >> 2)) >> 1))) | (-(v492 ^ ((int)((unsigned int)((int)((unsigned int)v484 >> 2)) >> 1))))) >> 31)) & 1);
      int v518 = v517[v764];
      int * v519 = v482->cache_age;
      int v520 = v519[v742];
      int * v521 = v482->cache_age;
      int v767 = v520 + ((int)((unsigned int)(v520 - v518) >> 31));
      v521[v742] = v767;
      int * v523 = v482->cache_age;
      int v524 = v523[v744];
      int * v525 = v482->cache_age;
      int v770 = v524 + ((int)((unsigned int)(v524 - v518) >> 31));
      v525[v744] = v770;
      int * v527 = v482->cache_age;
      v527[v764] = 0;
      v580 = v764;
    } else {
      int * v530 = v482->cache_age;
      int v774 = 4 + ((((int)((unsigned int)((int)((unsigned int)v484 >> 2)) >> 1)) & 3) * 2);
      int v531 = v530[v774];
      int * v532 = v482->cache_tags;
      int v533 = v532[v774];
      int * v534 = v482->cache_age;
      int v535 = v534[v744];
      int * v536 = v482->cache_tags;
      int v537 = v536[v744];
      int * v538 = v482->cache_dirty;
      int v779 = (4 + ((((int)((unsigned int)((int)((unsigned int)v484 >> 2)) >> 1)) & 3) * 2)) + ((((v531 + ((~(((v533 ^ -1) | (-(v533 ^ -1))) >> 31)) & 2)) - (v535 + ((~(((v537 ^ -1) | (-(v537 ^ -1))) >> 31)) & 2))) >> 31) & 1);
      int v539 = v538[v779];
      bool v780 = !(v539 == 0);
      if (v780) {
        int * v540 = v482->cache_tags;
        int v541 = v540[v779];
        int * v542 = v482->cache_vals;
        int v783 = ((4 + ((((int)((unsigned int)((int)((unsigned int)v484 >> 2)) >> 1)) & 3) * 2)) + ((((v531 + ((~(((v533 ^ -1) | (-(v533 ^ -1))) >> 31)) & 2)) - (v535 + ((~(((v537 ^ -1) | (-(v537 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
        int v543 = v542[v783];
        int * v544 = v482->cache_vals;
        int v785 = (((4 + ((((int)((unsigned int)((int)((unsigned int)v484 >> 2)) >> 1)) & 3) * 2)) + ((((v531 + ((~(((v533 ^ -1) | (-(v533 ^ -1))) >> 31)) & 2)) - (v535 + ((~(((v537 ^ -1) | (-(v537 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
        int v545 = v544[v785];
        int * v546 = v482->mem;
        int v787 = v541 * 2;
        v546[v787] = v543;
        int * v548 = v482->mem;
        int v790 = (v541 * 2) + 1;
        v548[v790] = v545;
        ;
      } else {
        ;
      }
      int * v553 = v482->mem;
      int v795 = ((int)((unsigned int)((int)((unsigned int)v484 >> 2)) >> 1)) * 2;
      int v554 = v553[v795];
      int * v555 = v482->mem;
      int v797 = (((int)((unsigned int)((int)((unsigned int)v484 >> 2)) >> 1)) * 2) + 1;
      int v556 = v555[v797];
      int * v557 = v482->cache_vals;
      int v799 = ((4 + ((((int)((unsigned int)((int)((unsigned int)v484 >> 2)) >> 1)) & 3) * 2)) + ((((v531 + ((~(((v533 ^ -1) | (-(v533 ^ -1))) >> 31)) & 2)) - (v535 + ((~(((v537 ^ -1) | (-(v537 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
      v557[v799] = v554;
      int * v559 = v482->cache_vals;
      int v802 = (((4 + ((((int)((unsigned int)((int)((unsigned int)v484 >> 2)) >> 1)) & 3) * 2)) + ((((v531 + ((~(((v533 ^ -1) | (-(v533 ^ -1))) >> 31)) & 2)) - (v535 + ((~(((v537 ^ -1) | (-(v537 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
      v559[v802] = v556;
      int * v561 = v482->cache_tags;
      int v805 = (int)((unsigned int)((int)((unsigned int)v484 >> 2)) >> 1);
      v561[v779] = v805;
      int * v563 = v482->cache_dirty;
      v563[v779] = 0;
      int * v565 = v482->cache_age;
      v565[v779] = 1;
      int * v567 = v482->cache_age;
      int v568 = v567[v779];
      int * v569 = v482->cache_age;
      int v570 = v569[v742];
      int * v571 = v482->cache_age;
      int v813 = v570 + ((int)((unsigned int)(v570 - v568) >> 31));
      v571[v742] = v813;
      int * v573 = v482->cache_age;
      int v574 = v573[v744];
      int * v575 = v482->cache_age;
      int v816 = v574 + ((int)((unsigned int)(v574 - v568) >> 31));
      v575[v744] = v816;
      int * v577 = v482->cache_age;
      v577[v779] = 0;
      v580 = v779;
    }
    int * v581 = v482->cache_vals;
    int v819 = v580 * 2;
    int v582 = v581[v819];
    int * v583 = v482->cache_vals;
    int v821 = (v580 * 2) + 1;
    int v584 = v583[v821];
    int * v585 = v482->cache_vals;
    int v823 = (((((int)((unsigned int)((int)((unsigned int)v484 >> 2)) >> 1)) & 1) * 2) + ((((v510 + ((~(((v512 ^ -1) | (-(v512 ^ -1))) >> 31)) & 2)) - (v514 + ((~(((v516 ^ -1) | (-(v516 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
    v585[v823] = v582;
    int * v587 = v482->cache_vals;
    int v826 = ((((((int)((unsigned int)((int)((unsigned int)v484 >> 2)) >> 1)) & 1) * 2) + ((((v510 + ((~(((v512 ^ -1) | (-(v512 ^ -1))) >> 31)) & 2)) - (v514 + ((~(((v516 ^ -1) | (-(v516 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
    v587[v826] = v584;
    int * v589 = v482->cache_tags;
    int v829 = ((((int)((unsigned int)((int)((unsigned int)v484 >> 2)) >> 1)) & 1) * 2) + ((((v510 + ((~(((v512 ^ -1) | (-(v512 ^ -1))) >> 31)) & 2)) - (v514 + ((~(((v516 ^ -1) | (-(v516 ^ -1))) >> 31)) & 2))) >> 31) & 1);
    int v830 = (int)((unsigned int)((int)((unsigned int)v484 >> 2)) >> 1);
    v589[v829] = v830;
    int * v591 = v482->cache_dirty;
    v591[v829] = 0;
    int * v593 = v482->cache_age;
    v593[v829] = 1;
    int * v595 = v482->cache_age;
    int v596 = v595[v829];
    int * v597 = v482->cache_age;
    int v598 = v597[v738];
    int * v599 = v482->cache_age;
    int v838 = v598 + ((int)((unsigned int)(v598 - v596) >> 31));
    v599[v738] = v838;
    int * v601 = v482->cache_age;
    int v602 = v601[v740];
    int * v603 = v482->cache_age;
    int v841 = v602 + ((int)((unsigned int)(v602 - v596) >> 31));
    v603[v740] = v841;
    int * v605 = v482->cache_age;
    v605[v829] = 0;
    v608 = v829;
  }
  int v844 = (v608 * 2) + (((int)((unsigned int)v484 >> 2)) & 1);
  int v609 = v495[v844];
  int * v610 = v482->regs;
  v610[7] = v609;
  struct StateT2 * v612 = slot_8(v339);
  return v612;
}

struct StateT2 * slot_3(struct StateT2 * v110) {
  struct StateT * v111 = v110->a;
  int v112 = v111->timer;
  struct StateT * v113 = v110->b;
  int v114 = v113->timer;
  bool v133 = v112 == v114;
  squared_assert(v133);
  squared_assume(v133);
  struct StateT * v117 = v110->a;
  int v118 = v117->timer;
  int v135 = v118 + 1;
  v117->timer = v135;
  struct StateT * v120 = v110->b;
  int v121 = v120->timer;
  int v137 = v121 + 1;
  v120->timer = v137;
  struct StateT * v123 = v110->a;
  int * v124 = v123->regs;
  v124[15] = 16;
  struct StateT * v126 = v110->b;
  int * v127 = v126->regs;
  v127[15] = 16;
  struct StateT2 * v129 = slot_4(v110);
  return v129;
}

struct StateT2 * snippet(struct StateT2 * v0) {
  struct StateT2 * v1 = slot_0(v0);
  return v1;
}

struct StateT2 * slot_10(struct StateT2 * v1410) {
  struct StateT * v1411 = v1410->a;
  int v1412 = v1411->timer;
  struct StateT * v1413 = v1410->b;
  int v1414 = v1413->timer;
  bool v1441 = v1412 == v1414;
  squared_assert(v1441);
  squared_assume(v1441);
  struct StateT * v1417 = v1410->a;
  int v1418 = v1417->timer;
  int v1443 = v1418 + 1;
  v1417->timer = v1443;
  struct StateT * v1420 = v1410->b;
  int v1421 = v1420->timer;
  int v1445 = v1421 + 1;
  v1420->timer = v1445;
  struct StateT * v1423 = v1410->a;
  int * v1424 = v1423->regs;
  int v1425 = v1424[7];
  int * v1426 = v1423->regs;
  int v1427 = v1426[9];
  int * v1428 = v1423->regs;
  int v1453 = v1425 ^ v1427;
  v1428[16] = v1453;
  struct StateT * v1430 = v1410->b;
  int * v1431 = v1430->regs;
  int v1432 = v1431[7];
  int * v1433 = v1430->regs;
  int v1434 = v1433[9];
  int * v1435 = v1430->regs;
  int v1458 = v1432 ^ v1434;
  v1435[16] = v1458;
  struct StateT2 * v1437 = slot_11(v1410);
  return v1437;
}

struct StateT2 * slot_1(struct StateT2 * v38) {
  struct StateT * v39 = v38->a;
  int v40 = v39->timer;
  struct StateT * v41 = v38->b;
  int v42 = v41->timer;
  bool v61 = v40 == v42;
  squared_assert(v61);
  squared_assume(v61);
  struct StateT * v45 = v38->a;
  int v46 = v45->timer;
  int v63 = v46 + 1;
  v45->timer = v63;
  struct StateT * v48 = v38->b;
  int v49 = v48->timer;
  int v65 = v49 + 1;
  v48->timer = v65;
  struct StateT * v51 = v38->a;
  int * v52 = v51->regs;
  v52[13] = 80;
  struct StateT * v54 = v38->b;
  int * v55 = v54->regs;
  v55[13] = 80;
  struct StateT2 * v57 = slot_2(v38);
  return v57;
}

struct StateT2 * slot_8(struct StateT2 * v849) {
  struct StateT * v850 = v849->a;
  int v851 = v850->timer;
  struct StateT * v852 = v849->b;
  int v853 = v852->timer;
  bool v880 = v851 == v853;
  squared_assert(v880);
  squared_assume(v880);
  struct StateT * v856 = v849->a;
  int v857 = v856->timer;
  int v882 = v857 + 1;
  v856->timer = v882;
  struct StateT * v859 = v849->b;
  int v860 = v859->timer;
  int v884 = v860 + 1;
  v859->timer = v884;
  struct StateT * v862 = v849->a;
  int * v863 = v862->regs;
  int v864 = v863[13];
  int * v865 = v862->regs;
  int v866 = v865[14];
  int * v867 = v862->regs;
  int v892 = v864 + v866;
  v867[8] = v892;
  struct StateT * v869 = v849->b;
  int * v870 = v869->regs;
  int v871 = v870[13];
  int * v872 = v869->regs;
  int v873 = v872[14];
  int * v874 = v869->regs;
  int v897 = v871 + v873;
  v874[8] = v897;
  struct StateT2 * v876 = slot_9(v849);
  return v876;
}

struct StateT2 * slot_4(struct StateT2 * v146) {
  struct StateT * v147 = v146->a;
  int v148 = v147->timer;
  struct StateT * v149 = v146->b;
  int v150 = v149->timer;
  bool v169 = v148 == v150;
  squared_assert(v169);
  squared_assume(v169);
  struct StateT * v153 = v146->a;
  int v154 = v153->timer;
  int v171 = v154 + 1;
  v153->timer = v171;
  struct StateT * v156 = v146->b;
  int v157 = v156->timer;
  int v173 = v157 + 1;
  v156->timer = v173;
  struct StateT * v159 = v146->a;
  int * v160 = v159->regs;
  v160[5] = 0;
  struct StateT * v162 = v146->b;
  int * v163 = v162->regs;
  v163[5] = 0;
  struct StateT2 * v165 = slot_5(v146);
  return v165;
}

struct StateT2 * slot_13(struct StateT2 * v1554) {
  struct StateT * v1555 = v1554->a;
  int v1556 = v1555->timer;
  struct StateT * v1557 = v1554->b;
  int v1558 = v1557->timer;
  bool v1573 = v1556 == v1558;
  squared_assert(v1573);
  squared_assume(v1573);
  struct StateT * v1561 = v1554->a;
  int v1562 = v1561->timer;
  int v1575 = v1562 + 1;
  v1561->timer = v1575;
  struct StateT * v1564 = v1554->b;
  int v1565 = v1564->timer;
  int v1577 = v1565 + 1;
  v1564->timer = v1577;
  struct StateT * v1567 = v1554->a;
  struct StateT * v1568 = v1554->b;
  struct StateT2 * v1569 = slot_5(v1554);
  return v1569;
}

struct StateT2 * slot_9(struct StateT2 * v900) {
  struct StateT * v901 = v900->a;
  int v902 = v901->timer;
  struct StateT * v903 = v900->b;
  int v904 = v903->timer;
  bool v1177 = v902 == v904;
  squared_assert(v1177);
  squared_assume(v1177);
  struct StateT * v907 = v900->a;
  int v908 = v907->timer;
  int v1179 = v908 + 1;
  v907->timer = v1179;
  struct StateT * v910 = v900->b;
  int v911 = v910->timer;
  int v1181 = v911 + 1;
  v910->timer = v1181;
  struct StateT * v913 = v900->a;
  int * v914 = v913->regs;
  int v915 = v914[8];
  int * v916 = v913->cache_tags;
  int v1186 = (((int)((unsigned int)((int)((unsigned int)v915 >> 2)) >> 1)) & 1) * 2;
  int v917 = v916[v1186];
  int * v918 = v913->cache_tags;
  int v1188 = ((((int)((unsigned int)((int)((unsigned int)v915 >> 2)) >> 1)) & 1) * 2) + 1;
  int v919 = v918[v1188];
  int * v920 = v913->cache_tags;
  int v1190 = 4 + ((((int)((unsigned int)((int)((unsigned int)v915 >> 2)) >> 1)) & 3) * 2);
  int v921 = v920[v1190];
  int * v922 = v913->cache_tags;
  int v1192 = (4 + ((((int)((unsigned int)((int)((unsigned int)v915 >> 2)) >> 1)) & 3) * 2)) + 1;
  int v923 = v922[v1192];
  int v924 = v913->timer;
  int v1193 = v924 + ((100 ^ (((~(((v921 ^ ((int)((unsigned int)((int)((unsigned int)v915 >> 2)) >> 1))) | (-(v921 ^ ((int)((unsigned int)((int)((unsigned int)v915 >> 2)) >> 1))))) >> 31)) | (~(((v923 ^ ((int)((unsigned int)((int)((unsigned int)v915 >> 2)) >> 1))) | (-(v923 ^ ((int)((unsigned int)((int)((unsigned int)v915 >> 2)) >> 1))))) >> 31))) & 104)) ^ (((~(((v917 ^ ((int)((unsigned int)((int)((unsigned int)v915 >> 2)) >> 1))) | (-(v917 ^ ((int)((unsigned int)((int)((unsigned int)v915 >> 2)) >> 1))))) >> 31)) | (~(((v919 ^ ((int)((unsigned int)((int)((unsigned int)v915 >> 2)) >> 1))) | (-(v919 ^ ((int)((unsigned int)((int)((unsigned int)v915 >> 2)) >> 1))))) >> 31))) & (1 ^ (100 ^ (((~(((v921 ^ ((int)((unsigned int)((int)((unsigned int)v915 >> 2)) >> 1))) | (-(v921 ^ ((int)((unsigned int)((int)((unsigned int)v915 >> 2)) >> 1))))) >> 31)) | (~(((v923 ^ ((int)((unsigned int)((int)((unsigned int)v915 >> 2)) >> 1))) | (-(v923 ^ ((int)((unsigned int)((int)((unsigned int)v915 >> 2)) >> 1))))) >> 31))) & 104)))));
  v913->timer = v1193;
  int * v926 = v913->cache_vals;
  bool v1194 = !(((~(((v917 ^ ((int)((unsigned int)((int)((unsigned int)v915 >> 2)) >> 1))) | (-(v917 ^ ((int)((unsigned int)((int)((unsigned int)v915 >> 2)) >> 1))))) >> 31)) | (~(((v919 ^ ((int)((unsigned int)((int)((unsigned int)v915 >> 2)) >> 1))) | (-(v919 ^ ((int)((unsigned int)((int)((unsigned int)v915 >> 2)) >> 1))))) >> 31))) == 0);
  int v1039;
  if (v1194) {
    int * v927 = v913->cache_age;
    int v1196 = ((((int)((unsigned int)((int)((unsigned int)v915 >> 2)) >> 1)) & 1) * 2) + ((~(((v919 ^ ((int)((unsigned int)((int)((unsigned int)v915 >> 2)) >> 1))) | (-(v919 ^ ((int)((unsigned int)((int)((unsigned int)v915 >> 2)) >> 1))))) >> 31)) & 1);
    int v928 = v927[v1196];
    int * v929 = v913->cache_age;
    int v930 = v929[v1186];
    int * v931 = v913->cache_age;
    int v1199 = v930 + ((int)((unsigned int)(v930 - v928) >> 31));
    v931[v1186] = v1199;
    int * v933 = v913->cache_age;
    int v934 = v933[v1188];
    int * v935 = v913->cache_age;
    int v1202 = v934 + ((int)((unsigned int)(v934 - v928) >> 31));
    v935[v1188] = v1202;
    int * v937 = v913->cache_age;
    v937[v1196] = 0;
    v1039 = v1196;
  } else {
    int * v940 = v913->cache_age;
    int v1206 = (((int)((unsigned int)((int)((unsigned int)v915 >> 2)) >> 1)) & 1) * 2;
    int v941 = v940[v1206];
    int * v942 = v913->cache_tags;
    int v943 = v942[v1206];
    int * v944 = v913->cache_age;
    int v945 = v944[v1188];
    int * v946 = v913->cache_tags;
    int v947 = v946[v1188];
    bool v1210 = !(((~(((v921 ^ ((int)((unsigned int)((int)((unsigned int)v915 >> 2)) >> 1))) | (-(v921 ^ ((int)((unsigned int)((int)((unsigned int)v915 >> 2)) >> 1))))) >> 31)) | (~(((v923 ^ ((int)((unsigned int)((int)((unsigned int)v915 >> 2)) >> 1))) | (-(v923 ^ ((int)((unsigned int)((int)((unsigned int)v915 >> 2)) >> 1))))) >> 31))) == 0);
    int v1011;
    if (v1210) {
      int * v948 = v913->cache_age;
      int v1212 = (4 + ((((int)((unsigned int)((int)((unsigned int)v915 >> 2)) >> 1)) & 3) * 2)) + ((~(((v923 ^ ((int)((unsigned int)((int)((unsigned int)v915 >> 2)) >> 1))) | (-(v923 ^ ((int)((unsigned int)((int)((unsigned int)v915 >> 2)) >> 1))))) >> 31)) & 1);
      int v949 = v948[v1212];
      int * v950 = v913->cache_age;
      int v951 = v950[v1190];
      int * v952 = v913->cache_age;
      int v1215 = v951 + ((int)((unsigned int)(v951 - v949) >> 31));
      v952[v1190] = v1215;
      int * v954 = v913->cache_age;
      int v955 = v954[v1192];
      int * v956 = v913->cache_age;
      int v1218 = v955 + ((int)((unsigned int)(v955 - v949) >> 31));
      v956[v1192] = v1218;
      int * v958 = v913->cache_age;
      v958[v1212] = 0;
      v1011 = v1212;
    } else {
      int * v961 = v913->cache_age;
      int v1222 = 4 + ((((int)((unsigned int)((int)((unsigned int)v915 >> 2)) >> 1)) & 3) * 2);
      int v962 = v961[v1222];
      int * v963 = v913->cache_tags;
      int v964 = v963[v1222];
      int * v965 = v913->cache_age;
      int v966 = v965[v1192];
      int * v967 = v913->cache_tags;
      int v968 = v967[v1192];
      int * v969 = v913->cache_dirty;
      int v1227 = (4 + ((((int)((unsigned int)((int)((unsigned int)v915 >> 2)) >> 1)) & 3) * 2)) + ((((v962 + ((~(((v964 ^ -1) | (-(v964 ^ -1))) >> 31)) & 2)) - (v966 + ((~(((v968 ^ -1) | (-(v968 ^ -1))) >> 31)) & 2))) >> 31) & 1);
      int v970 = v969[v1227];
      bool v1228 = !(v970 == 0);
      if (v1228) {
        int * v971 = v913->cache_tags;
        int v972 = v971[v1227];
        int * v973 = v913->cache_vals;
        int v1231 = ((4 + ((((int)((unsigned int)((int)((unsigned int)v915 >> 2)) >> 1)) & 3) * 2)) + ((((v962 + ((~(((v964 ^ -1) | (-(v964 ^ -1))) >> 31)) & 2)) - (v966 + ((~(((v968 ^ -1) | (-(v968 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
        int v974 = v973[v1231];
        int * v975 = v913->cache_vals;
        int v1233 = (((4 + ((((int)((unsigned int)((int)((unsigned int)v915 >> 2)) >> 1)) & 3) * 2)) + ((((v962 + ((~(((v964 ^ -1) | (-(v964 ^ -1))) >> 31)) & 2)) - (v966 + ((~(((v968 ^ -1) | (-(v968 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
        int v976 = v975[v1233];
        int * v977 = v913->mem;
        int v1235 = v972 * 2;
        v977[v1235] = v974;
        int * v979 = v913->mem;
        int v1238 = (v972 * 2) + 1;
        v979[v1238] = v976;
        ;
      } else {
        ;
      }
      int * v984 = v913->mem;
      int v1243 = ((int)((unsigned int)((int)((unsigned int)v915 >> 2)) >> 1)) * 2;
      int v985 = v984[v1243];
      int * v986 = v913->mem;
      int v1245 = (((int)((unsigned int)((int)((unsigned int)v915 >> 2)) >> 1)) * 2) + 1;
      int v987 = v986[v1245];
      int * v988 = v913->cache_vals;
      int v1247 = ((4 + ((((int)((unsigned int)((int)((unsigned int)v915 >> 2)) >> 1)) & 3) * 2)) + ((((v962 + ((~(((v964 ^ -1) | (-(v964 ^ -1))) >> 31)) & 2)) - (v966 + ((~(((v968 ^ -1) | (-(v968 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
      v988[v1247] = v985;
      int * v990 = v913->cache_vals;
      int v1250 = (((4 + ((((int)((unsigned int)((int)((unsigned int)v915 >> 2)) >> 1)) & 3) * 2)) + ((((v962 + ((~(((v964 ^ -1) | (-(v964 ^ -1))) >> 31)) & 2)) - (v966 + ((~(((v968 ^ -1) | (-(v968 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
      v990[v1250] = v987;
      int * v992 = v913->cache_tags;
      int v1253 = (int)((unsigned int)((int)((unsigned int)v915 >> 2)) >> 1);
      v992[v1227] = v1253;
      int * v994 = v913->cache_dirty;
      v994[v1227] = 0;
      int * v996 = v913->cache_age;
      v996[v1227] = 1;
      int * v998 = v913->cache_age;
      int v999 = v998[v1227];
      int * v1000 = v913->cache_age;
      int v1001 = v1000[v1190];
      int * v1002 = v913->cache_age;
      int v1261 = v1001 + ((int)((unsigned int)(v1001 - v999) >> 31));
      v1002[v1190] = v1261;
      int * v1004 = v913->cache_age;
      int v1005 = v1004[v1192];
      int * v1006 = v913->cache_age;
      int v1264 = v1005 + ((int)((unsigned int)(v1005 - v999) >> 31));
      v1006[v1192] = v1264;
      int * v1008 = v913->cache_age;
      v1008[v1227] = 0;
      v1011 = v1227;
    }
    int * v1012 = v913->cache_vals;
    int v1267 = v1011 * 2;
    int v1013 = v1012[v1267];
    int * v1014 = v913->cache_vals;
    int v1269 = (v1011 * 2) + 1;
    int v1015 = v1014[v1269];
    int * v1016 = v913->cache_vals;
    int v1271 = (((((int)((unsigned int)((int)((unsigned int)v915 >> 2)) >> 1)) & 1) * 2) + ((((v941 + ((~(((v943 ^ -1) | (-(v943 ^ -1))) >> 31)) & 2)) - (v945 + ((~(((v947 ^ -1) | (-(v947 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
    v1016[v1271] = v1013;
    int * v1018 = v913->cache_vals;
    int v1274 = ((((((int)((unsigned int)((int)((unsigned int)v915 >> 2)) >> 1)) & 1) * 2) + ((((v941 + ((~(((v943 ^ -1) | (-(v943 ^ -1))) >> 31)) & 2)) - (v945 + ((~(((v947 ^ -1) | (-(v947 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
    v1018[v1274] = v1015;
    int * v1020 = v913->cache_tags;
    int v1277 = ((((int)((unsigned int)((int)((unsigned int)v915 >> 2)) >> 1)) & 1) * 2) + ((((v941 + ((~(((v943 ^ -1) | (-(v943 ^ -1))) >> 31)) & 2)) - (v945 + ((~(((v947 ^ -1) | (-(v947 ^ -1))) >> 31)) & 2))) >> 31) & 1);
    int v1278 = (int)((unsigned int)((int)((unsigned int)v915 >> 2)) >> 1);
    v1020[v1277] = v1278;
    int * v1022 = v913->cache_dirty;
    v1022[v1277] = 0;
    int * v1024 = v913->cache_age;
    v1024[v1277] = 1;
    int * v1026 = v913->cache_age;
    int v1027 = v1026[v1277];
    int * v1028 = v913->cache_age;
    int v1029 = v1028[v1186];
    int * v1030 = v913->cache_age;
    int v1286 = v1029 + ((int)((unsigned int)(v1029 - v1027) >> 31));
    v1030[v1186] = v1286;
    int * v1032 = v913->cache_age;
    int v1033 = v1032[v1188];
    int * v1034 = v913->cache_age;
    int v1289 = v1033 + ((int)((unsigned int)(v1033 - v1027) >> 31));
    v1034[v1188] = v1289;
    int * v1036 = v913->cache_age;
    v1036[v1277] = 0;
    v1039 = v1277;
  }
  int v1292 = (v1039 * 2) + (((int)((unsigned int)v915 >> 2)) & 1);
  int v1040 = v926[v1292];
  int * v1041 = v913->regs;
  v1041[9] = v1040;
  struct StateT * v1043 = v900->b;
  int * v1044 = v1043->regs;
  int v1045 = v1044[8];
  int * v1046 = v1043->cache_tags;
  int v1299 = (((int)((unsigned int)((int)((unsigned int)v1045 >> 2)) >> 1)) & 1) * 2;
  int v1047 = v1046[v1299];
  int * v1048 = v1043->cache_tags;
  int v1301 = ((((int)((unsigned int)((int)((unsigned int)v1045 >> 2)) >> 1)) & 1) * 2) + 1;
  int v1049 = v1048[v1301];
  int * v1050 = v1043->cache_tags;
  int v1303 = 4 + ((((int)((unsigned int)((int)((unsigned int)v1045 >> 2)) >> 1)) & 3) * 2);
  int v1051 = v1050[v1303];
  int * v1052 = v1043->cache_tags;
  int v1305 = (4 + ((((int)((unsigned int)((int)((unsigned int)v1045 >> 2)) >> 1)) & 3) * 2)) + 1;
  int v1053 = v1052[v1305];
  int v1054 = v1043->timer;
  int v1306 = v1054 + ((100 ^ (((~(((v1051 ^ ((int)((unsigned int)((int)((unsigned int)v1045 >> 2)) >> 1))) | (-(v1051 ^ ((int)((unsigned int)((int)((unsigned int)v1045 >> 2)) >> 1))))) >> 31)) | (~(((v1053 ^ ((int)((unsigned int)((int)((unsigned int)v1045 >> 2)) >> 1))) | (-(v1053 ^ ((int)((unsigned int)((int)((unsigned int)v1045 >> 2)) >> 1))))) >> 31))) & 104)) ^ (((~(((v1047 ^ ((int)((unsigned int)((int)((unsigned int)v1045 >> 2)) >> 1))) | (-(v1047 ^ ((int)((unsigned int)((int)((unsigned int)v1045 >> 2)) >> 1))))) >> 31)) | (~(((v1049 ^ ((int)((unsigned int)((int)((unsigned int)v1045 >> 2)) >> 1))) | (-(v1049 ^ ((int)((unsigned int)((int)((unsigned int)v1045 >> 2)) >> 1))))) >> 31))) & (1 ^ (100 ^ (((~(((v1051 ^ ((int)((unsigned int)((int)((unsigned int)v1045 >> 2)) >> 1))) | (-(v1051 ^ ((int)((unsigned int)((int)((unsigned int)v1045 >> 2)) >> 1))))) >> 31)) | (~(((v1053 ^ ((int)((unsigned int)((int)((unsigned int)v1045 >> 2)) >> 1))) | (-(v1053 ^ ((int)((unsigned int)((int)((unsigned int)v1045 >> 2)) >> 1))))) >> 31))) & 104)))));
  v1043->timer = v1306;
  int * v1056 = v1043->cache_vals;
  bool v1307 = !(((~(((v1047 ^ ((int)((unsigned int)((int)((unsigned int)v1045 >> 2)) >> 1))) | (-(v1047 ^ ((int)((unsigned int)((int)((unsigned int)v1045 >> 2)) >> 1))))) >> 31)) | (~(((v1049 ^ ((int)((unsigned int)((int)((unsigned int)v1045 >> 2)) >> 1))) | (-(v1049 ^ ((int)((unsigned int)((int)((unsigned int)v1045 >> 2)) >> 1))))) >> 31))) == 0);
  int v1169;
  if (v1307) {
    int * v1057 = v1043->cache_age;
    int v1309 = ((((int)((unsigned int)((int)((unsigned int)v1045 >> 2)) >> 1)) & 1) * 2) + ((~(((v1049 ^ ((int)((unsigned int)((int)((unsigned int)v1045 >> 2)) >> 1))) | (-(v1049 ^ ((int)((unsigned int)((int)((unsigned int)v1045 >> 2)) >> 1))))) >> 31)) & 1);
    int v1058 = v1057[v1309];
    int * v1059 = v1043->cache_age;
    int v1060 = v1059[v1299];
    int * v1061 = v1043->cache_age;
    int v1312 = v1060 + ((int)((unsigned int)(v1060 - v1058) >> 31));
    v1061[v1299] = v1312;
    int * v1063 = v1043->cache_age;
    int v1064 = v1063[v1301];
    int * v1065 = v1043->cache_age;
    int v1315 = v1064 + ((int)((unsigned int)(v1064 - v1058) >> 31));
    v1065[v1301] = v1315;
    int * v1067 = v1043->cache_age;
    v1067[v1309] = 0;
    v1169 = v1309;
  } else {
    int * v1070 = v1043->cache_age;
    int v1319 = (((int)((unsigned int)((int)((unsigned int)v1045 >> 2)) >> 1)) & 1) * 2;
    int v1071 = v1070[v1319];
    int * v1072 = v1043->cache_tags;
    int v1073 = v1072[v1319];
    int * v1074 = v1043->cache_age;
    int v1075 = v1074[v1301];
    int * v1076 = v1043->cache_tags;
    int v1077 = v1076[v1301];
    bool v1323 = !(((~(((v1051 ^ ((int)((unsigned int)((int)((unsigned int)v1045 >> 2)) >> 1))) | (-(v1051 ^ ((int)((unsigned int)((int)((unsigned int)v1045 >> 2)) >> 1))))) >> 31)) | (~(((v1053 ^ ((int)((unsigned int)((int)((unsigned int)v1045 >> 2)) >> 1))) | (-(v1053 ^ ((int)((unsigned int)((int)((unsigned int)v1045 >> 2)) >> 1))))) >> 31))) == 0);
    int v1141;
    if (v1323) {
      int * v1078 = v1043->cache_age;
      int v1325 = (4 + ((((int)((unsigned int)((int)((unsigned int)v1045 >> 2)) >> 1)) & 3) * 2)) + ((~(((v1053 ^ ((int)((unsigned int)((int)((unsigned int)v1045 >> 2)) >> 1))) | (-(v1053 ^ ((int)((unsigned int)((int)((unsigned int)v1045 >> 2)) >> 1))))) >> 31)) & 1);
      int v1079 = v1078[v1325];
      int * v1080 = v1043->cache_age;
      int v1081 = v1080[v1303];
      int * v1082 = v1043->cache_age;
      int v1328 = v1081 + ((int)((unsigned int)(v1081 - v1079) >> 31));
      v1082[v1303] = v1328;
      int * v1084 = v1043->cache_age;
      int v1085 = v1084[v1305];
      int * v1086 = v1043->cache_age;
      int v1331 = v1085 + ((int)((unsigned int)(v1085 - v1079) >> 31));
      v1086[v1305] = v1331;
      int * v1088 = v1043->cache_age;
      v1088[v1325] = 0;
      v1141 = v1325;
    } else {
      int * v1091 = v1043->cache_age;
      int v1335 = 4 + ((((int)((unsigned int)((int)((unsigned int)v1045 >> 2)) >> 1)) & 3) * 2);
      int v1092 = v1091[v1335];
      int * v1093 = v1043->cache_tags;
      int v1094 = v1093[v1335];
      int * v1095 = v1043->cache_age;
      int v1096 = v1095[v1305];
      int * v1097 = v1043->cache_tags;
      int v1098 = v1097[v1305];
      int * v1099 = v1043->cache_dirty;
      int v1340 = (4 + ((((int)((unsigned int)((int)((unsigned int)v1045 >> 2)) >> 1)) & 3) * 2)) + ((((v1092 + ((~(((v1094 ^ -1) | (-(v1094 ^ -1))) >> 31)) & 2)) - (v1096 + ((~(((v1098 ^ -1) | (-(v1098 ^ -1))) >> 31)) & 2))) >> 31) & 1);
      int v1100 = v1099[v1340];
      bool v1341 = !(v1100 == 0);
      if (v1341) {
        int * v1101 = v1043->cache_tags;
        int v1102 = v1101[v1340];
        int * v1103 = v1043->cache_vals;
        int v1344 = ((4 + ((((int)((unsigned int)((int)((unsigned int)v1045 >> 2)) >> 1)) & 3) * 2)) + ((((v1092 + ((~(((v1094 ^ -1) | (-(v1094 ^ -1))) >> 31)) & 2)) - (v1096 + ((~(((v1098 ^ -1) | (-(v1098 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
        int v1104 = v1103[v1344];
        int * v1105 = v1043->cache_vals;
        int v1346 = (((4 + ((((int)((unsigned int)((int)((unsigned int)v1045 >> 2)) >> 1)) & 3) * 2)) + ((((v1092 + ((~(((v1094 ^ -1) | (-(v1094 ^ -1))) >> 31)) & 2)) - (v1096 + ((~(((v1098 ^ -1) | (-(v1098 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
        int v1106 = v1105[v1346];
        int * v1107 = v1043->mem;
        int v1348 = v1102 * 2;
        v1107[v1348] = v1104;
        int * v1109 = v1043->mem;
        int v1351 = (v1102 * 2) + 1;
        v1109[v1351] = v1106;
        ;
      } else {
        ;
      }
      int * v1114 = v1043->mem;
      int v1356 = ((int)((unsigned int)((int)((unsigned int)v1045 >> 2)) >> 1)) * 2;
      int v1115 = v1114[v1356];
      int * v1116 = v1043->mem;
      int v1358 = (((int)((unsigned int)((int)((unsigned int)v1045 >> 2)) >> 1)) * 2) + 1;
      int v1117 = v1116[v1358];
      int * v1118 = v1043->cache_vals;
      int v1360 = ((4 + ((((int)((unsigned int)((int)((unsigned int)v1045 >> 2)) >> 1)) & 3) * 2)) + ((((v1092 + ((~(((v1094 ^ -1) | (-(v1094 ^ -1))) >> 31)) & 2)) - (v1096 + ((~(((v1098 ^ -1) | (-(v1098 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
      v1118[v1360] = v1115;
      int * v1120 = v1043->cache_vals;
      int v1363 = (((4 + ((((int)((unsigned int)((int)((unsigned int)v1045 >> 2)) >> 1)) & 3) * 2)) + ((((v1092 + ((~(((v1094 ^ -1) | (-(v1094 ^ -1))) >> 31)) & 2)) - (v1096 + ((~(((v1098 ^ -1) | (-(v1098 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
      v1120[v1363] = v1117;
      int * v1122 = v1043->cache_tags;
      int v1366 = (int)((unsigned int)((int)((unsigned int)v1045 >> 2)) >> 1);
      v1122[v1340] = v1366;
      int * v1124 = v1043->cache_dirty;
      v1124[v1340] = 0;
      int * v1126 = v1043->cache_age;
      v1126[v1340] = 1;
      int * v1128 = v1043->cache_age;
      int v1129 = v1128[v1340];
      int * v1130 = v1043->cache_age;
      int v1131 = v1130[v1303];
      int * v1132 = v1043->cache_age;
      int v1374 = v1131 + ((int)((unsigned int)(v1131 - v1129) >> 31));
      v1132[v1303] = v1374;
      int * v1134 = v1043->cache_age;
      int v1135 = v1134[v1305];
      int * v1136 = v1043->cache_age;
      int v1377 = v1135 + ((int)((unsigned int)(v1135 - v1129) >> 31));
      v1136[v1305] = v1377;
      int * v1138 = v1043->cache_age;
      v1138[v1340] = 0;
      v1141 = v1340;
    }
    int * v1142 = v1043->cache_vals;
    int v1380 = v1141 * 2;
    int v1143 = v1142[v1380];
    int * v1144 = v1043->cache_vals;
    int v1382 = (v1141 * 2) + 1;
    int v1145 = v1144[v1382];
    int * v1146 = v1043->cache_vals;
    int v1384 = (((((int)((unsigned int)((int)((unsigned int)v1045 >> 2)) >> 1)) & 1) * 2) + ((((v1071 + ((~(((v1073 ^ -1) | (-(v1073 ^ -1))) >> 31)) & 2)) - (v1075 + ((~(((v1077 ^ -1) | (-(v1077 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
    v1146[v1384] = v1143;
    int * v1148 = v1043->cache_vals;
    int v1387 = ((((((int)((unsigned int)((int)((unsigned int)v1045 >> 2)) >> 1)) & 1) * 2) + ((((v1071 + ((~(((v1073 ^ -1) | (-(v1073 ^ -1))) >> 31)) & 2)) - (v1075 + ((~(((v1077 ^ -1) | (-(v1077 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
    v1148[v1387] = v1145;
    int * v1150 = v1043->cache_tags;
    int v1390 = ((((int)((unsigned int)((int)((unsigned int)v1045 >> 2)) >> 1)) & 1) * 2) + ((((v1071 + ((~(((v1073 ^ -1) | (-(v1073 ^ -1))) >> 31)) & 2)) - (v1075 + ((~(((v1077 ^ -1) | (-(v1077 ^ -1))) >> 31)) & 2))) >> 31) & 1);
    int v1391 = (int)((unsigned int)((int)((unsigned int)v1045 >> 2)) >> 1);
    v1150[v1390] = v1391;
    int * v1152 = v1043->cache_dirty;
    v1152[v1390] = 0;
    int * v1154 = v1043->cache_age;
    v1154[v1390] = 1;
    int * v1156 = v1043->cache_age;
    int v1157 = v1156[v1390];
    int * v1158 = v1043->cache_age;
    int v1159 = v1158[v1299];
    int * v1160 = v1043->cache_age;
    int v1399 = v1159 + ((int)((unsigned int)(v1159 - v1157) >> 31));
    v1160[v1299] = v1399;
    int * v1162 = v1043->cache_age;
    int v1163 = v1162[v1301];
    int * v1164 = v1043->cache_age;
    int v1402 = v1163 + ((int)((unsigned int)(v1163 - v1157) >> 31));
    v1164[v1301] = v1402;
    int * v1166 = v1043->cache_age;
    v1166[v1390] = 0;
    v1169 = v1390;
  }
  int v1405 = (v1169 * 2) + (((int)((unsigned int)v1045 >> 2)) & 1);
  int v1170 = v1056[v1405];
  int * v1171 = v1043->regs;
  v1171[9] = v1170;
  struct StateT2 * v1173 = slot_10(v900);
  return v1173;
}

struct StateT2 * slot_11(struct StateT2 * v1461) {
  struct StateT * v1462 = v1461->a;
  int v1463 = v1462->timer;
  struct StateT * v1464 = v1461->b;
  int v1465 = v1464->timer;
  bool v1492 = v1463 == v1465;
  squared_assert(v1492);
  squared_assume(v1492);
  struct StateT * v1468 = v1461->a;
  int v1469 = v1468->timer;
  int v1494 = v1469 + 1;
  v1468->timer = v1494;
  struct StateT * v1471 = v1461->b;
  int v1472 = v1471->timer;
  int v1496 = v1472 + 1;
  v1471->timer = v1496;
  struct StateT * v1474 = v1461->a;
  int * v1475 = v1474->regs;
  int v1476 = v1475[5];
  int * v1477 = v1474->regs;
  int v1478 = v1477[16];
  int * v1479 = v1474->regs;
  int v1503 = v1476 | v1478;
  v1479[5] = v1503;
  struct StateT * v1481 = v1461->b;
  int * v1482 = v1481->regs;
  int v1483 = v1482[5];
  int * v1484 = v1481->regs;
  int v1485 = v1484[16];
  int * v1486 = v1481->regs;
  int v1508 = v1483 | v1485;
  v1486[5] = v1508;
  struct StateT2 * v1488 = slot_12(v1461);
  return v1488;
}

struct StateT2 * slot_0(struct StateT2 * v2) {
  struct StateT * v3 = v2->a;
  int v4 = v3->timer;
  struct StateT * v5 = v2->b;
  int v6 = v5->timer;
  bool v25 = v4 == v6;
  squared_assert(v25);
  squared_assume(v25);
  struct StateT * v9 = v2->a;
  int v10 = v9->timer;
  int v27 = v10 + 1;
  v9->timer = v27;
  struct StateT * v12 = v2->b;
  int v13 = v12->timer;
  int v29 = v13 + 1;
  v12->timer = v29;
  struct StateT * v15 = v2->a;
  int * v16 = v15->regs;
  v16[12] = 0;
  struct StateT * v18 = v2->b;
  int * v19 = v18->regs;
  v19[12] = 0;
  struct StateT2 * v21 = slot_1(v2);
  return v21;
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

void squared_assert(bool c) { koika_assert(c, "timer drift"); }
void squared_diverged(bool c) { koika_assert(c, "control flow diverged"); }
void squared_assume(bool c) { koika_assume(c); }

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
  struct StateT2 p = { .a = &s1, .b = &s2 };
  struct StateT2 *p_ = snippet(&p);
  koika_assert(p_->a->timer==p_->b->timer, "timing leak");
  return 0;
}