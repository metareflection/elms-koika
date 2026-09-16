// verify: clean (CBMC should report VERIFICATION SUCCESSFUL) [unwind 65]
#define NUM_REGS 32
#define MEM_SIZE 64
#define SECRET_SIZE 10
#define SECRET_OFFSET 20
#define CACHE_ENTRIES 12
#define CACHE_WORDS 24

#ifdef CBMC
int nondet_uint();
#define koika_assert(b, s) __CPROVER_assert(b, s)
#define koika_assume(b) __CPROVER_assume(b)
#define koika_draw(x) ((x) = nondet_uint())
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

struct StateT * slot_6(struct StateT * v333);
struct StateT * slot_5(struct StateT * v83);
struct StateT * slot_2(struct StateT * v28);
struct StateT * slot_7(struct StateT * v718);
struct StateT * slot_3(struct StateT * v41);
struct StateT * snippet(struct StateT * v0);
struct StateT * slot_1(struct StateT * v15);
struct StateT * slot_8(struct StateT * v968);
struct StateT * slot_4(struct StateT * v62);
struct StateT * slot_9(struct StateT * v984);
struct StateT * slot_0(struct StateT * v2);
struct StateT * slot_6(struct StateT * v333) {
  int v334 = v333->timer;
  int v539 = v334 + 1;
  v333->timer = v539;
  int * v336 = v333->regs;
  int v337 = v336[6];
  int * v338 = v333->regs;
  int v339 = v338[5];
  int * v340 = v333->cache_tags;
  int v545 = (((int)((unsigned int)((int)((unsigned int)v337 >> 2)) >> 1)) & 1) * 2;
  int v341 = v340[v545];
  int * v342 = v333->cache_tags;
  int v547 = ((((int)((unsigned int)((int)((unsigned int)v337 >> 2)) >> 1)) & 1) * 2) + 1;
  int v343 = v342[v547];
  int * v344 = v333->cache_tags;
  int v549 = 4 + ((((int)((unsigned int)((int)((unsigned int)v337 >> 2)) >> 1)) & 3) * 2);
  int v345 = v344[v549];
  int * v346 = v333->cache_tags;
  int v551 = (4 + ((((int)((unsigned int)((int)((unsigned int)v337 >> 2)) >> 1)) & 3) * 2)) + 1;
  int v347 = v346[v551];
  int v348 = v333->timer;
  int v552 = v348 + ((100 ^ (((~(((v345 ^ ((int)((unsigned int)((int)((unsigned int)v337 >> 2)) >> 1))) | (-(v345 ^ ((int)((unsigned int)((int)((unsigned int)v337 >> 2)) >> 1))))) >> 31)) | (~(((v347 ^ ((int)((unsigned int)((int)((unsigned int)v337 >> 2)) >> 1))) | (-(v347 ^ ((int)((unsigned int)((int)((unsigned int)v337 >> 2)) >> 1))))) >> 31))) & 104)) ^ (((~(((v341 ^ ((int)((unsigned int)((int)((unsigned int)v337 >> 2)) >> 1))) | (-(v341 ^ ((int)((unsigned int)((int)((unsigned int)v337 >> 2)) >> 1))))) >> 31)) | (~(((v343 ^ ((int)((unsigned int)((int)((unsigned int)v337 >> 2)) >> 1))) | (-(v343 ^ ((int)((unsigned int)((int)((unsigned int)v337 >> 2)) >> 1))))) >> 31))) & (1 ^ (100 ^ (((~(((v345 ^ ((int)((unsigned int)((int)((unsigned int)v337 >> 2)) >> 1))) | (-(v345 ^ ((int)((unsigned int)((int)((unsigned int)v337 >> 2)) >> 1))))) >> 31)) | (~(((v347 ^ ((int)((unsigned int)((int)((unsigned int)v337 >> 2)) >> 1))) | (-(v347 ^ ((int)((unsigned int)((int)((unsigned int)v337 >> 2)) >> 1))))) >> 31))) & 104)))));
  v333->timer = v552;
  bool v553 = !(((~(((v341 ^ ((int)((unsigned int)((int)((unsigned int)v337 >> 2)) >> 1))) | (-(v341 ^ ((int)((unsigned int)((int)((unsigned int)v337 >> 2)) >> 1))))) >> 31)) | (~(((v343 ^ ((int)((unsigned int)((int)((unsigned int)v337 >> 2)) >> 1))) | (-(v343 ^ ((int)((unsigned int)((int)((unsigned int)v337 >> 2)) >> 1))))) >> 31))) == 0);
  int v462;
  if (v553) {
    int * v350 = v333->cache_age;
    int v555 = ((((int)((unsigned int)((int)((unsigned int)v337 >> 2)) >> 1)) & 1) * 2) + ((~(((v343 ^ ((int)((unsigned int)((int)((unsigned int)v337 >> 2)) >> 1))) | (-(v343 ^ ((int)((unsigned int)((int)((unsigned int)v337 >> 2)) >> 1))))) >> 31)) & 1);
    int v351 = v350[v555];
    int * v352 = v333->cache_age;
    int v353 = v352[v545];
    int * v354 = v333->cache_age;
    int v558 = v353 + ((int)((unsigned int)(v353 - v351) >> 31));
    v354[v545] = v558;
    int * v356 = v333->cache_age;
    int v357 = v356[v547];
    int * v358 = v333->cache_age;
    int v561 = v357 + ((int)((unsigned int)(v357 - v351) >> 31));
    v358[v547] = v561;
    int * v360 = v333->cache_age;
    v360[v555] = 0;
    v462 = v555;
  } else {
    int * v363 = v333->cache_age;
    int v565 = (((int)((unsigned int)((int)((unsigned int)v337 >> 2)) >> 1)) & 1) * 2;
    int v364 = v363[v565];
    int * v365 = v333->cache_tags;
    int v366 = v365[v565];
    int * v367 = v333->cache_age;
    int v368 = v367[v547];
    int * v369 = v333->cache_tags;
    int v370 = v369[v547];
    bool v569 = !(((~(((v345 ^ ((int)((unsigned int)((int)((unsigned int)v337 >> 2)) >> 1))) | (-(v345 ^ ((int)((unsigned int)((int)((unsigned int)v337 >> 2)) >> 1))))) >> 31)) | (~(((v347 ^ ((int)((unsigned int)((int)((unsigned int)v337 >> 2)) >> 1))) | (-(v347 ^ ((int)((unsigned int)((int)((unsigned int)v337 >> 2)) >> 1))))) >> 31))) == 0);
    int v434;
    if (v569) {
      int * v371 = v333->cache_age;
      int v571 = (4 + ((((int)((unsigned int)((int)((unsigned int)v337 >> 2)) >> 1)) & 3) * 2)) + ((~(((v347 ^ ((int)((unsigned int)((int)((unsigned int)v337 >> 2)) >> 1))) | (-(v347 ^ ((int)((unsigned int)((int)((unsigned int)v337 >> 2)) >> 1))))) >> 31)) & 1);
      int v372 = v371[v571];
      int * v373 = v333->cache_age;
      int v374 = v373[v549];
      int * v375 = v333->cache_age;
      int v574 = v374 + ((int)((unsigned int)(v374 - v372) >> 31));
      v375[v549] = v574;
      int * v377 = v333->cache_age;
      int v378 = v377[v551];
      int * v379 = v333->cache_age;
      int v577 = v378 + ((int)((unsigned int)(v378 - v372) >> 31));
      v379[v551] = v577;
      int * v381 = v333->cache_age;
      v381[v571] = 0;
      v434 = v571;
    } else {
      int * v384 = v333->cache_age;
      int v581 = 4 + ((((int)((unsigned int)((int)((unsigned int)v337 >> 2)) >> 1)) & 3) * 2);
      int v385 = v384[v581];
      int * v386 = v333->cache_tags;
      int v387 = v386[v581];
      int * v388 = v333->cache_age;
      int v389 = v388[v551];
      int * v390 = v333->cache_tags;
      int v391 = v390[v551];
      int * v392 = v333->cache_dirty;
      int v586 = (4 + ((((int)((unsigned int)((int)((unsigned int)v337 >> 2)) >> 1)) & 3) * 2)) + ((((v385 + ((~(((v387 ^ -1) | (-(v387 ^ -1))) >> 31)) & 2)) - (v389 + ((~(((v391 ^ -1) | (-(v391 ^ -1))) >> 31)) & 2))) >> 31) & 1);
      int v393 = v392[v586];
      bool v587 = !(v393 == 0);
      if (v587) {
        int * v394 = v333->cache_tags;
        int v395 = v394[v586];
        int * v396 = v333->cache_vals;
        int v590 = ((4 + ((((int)((unsigned int)((int)((unsigned int)v337 >> 2)) >> 1)) & 3) * 2)) + ((((v385 + ((~(((v387 ^ -1) | (-(v387 ^ -1))) >> 31)) & 2)) - (v389 + ((~(((v391 ^ -1) | (-(v391 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
        int v397 = v396[v590];
        int * v398 = v333->cache_vals;
        int v592 = (((4 + ((((int)((unsigned int)((int)((unsigned int)v337 >> 2)) >> 1)) & 3) * 2)) + ((((v385 + ((~(((v387 ^ -1) | (-(v387 ^ -1))) >> 31)) & 2)) - (v389 + ((~(((v391 ^ -1) | (-(v391 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
        int v399 = v398[v592];
        int * v400 = v333->mem;
        int v594 = v395 * 2;
        v400[v594] = v397;
        int * v402 = v333->mem;
        int v597 = (v395 * 2) + 1;
        v402[v597] = v399;
        ;
      } else {
        ;
      }
      int * v407 = v333->mem;
      int v602 = ((int)((unsigned int)((int)((unsigned int)v337 >> 2)) >> 1)) * 2;
      int v408 = v407[v602];
      int * v409 = v333->mem;
      int v604 = (((int)((unsigned int)((int)((unsigned int)v337 >> 2)) >> 1)) * 2) + 1;
      int v410 = v409[v604];
      int * v411 = v333->cache_vals;
      int v606 = ((4 + ((((int)((unsigned int)((int)((unsigned int)v337 >> 2)) >> 1)) & 3) * 2)) + ((((v385 + ((~(((v387 ^ -1) | (-(v387 ^ -1))) >> 31)) & 2)) - (v389 + ((~(((v391 ^ -1) | (-(v391 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
      v411[v606] = v408;
      int * v413 = v333->cache_vals;
      int v609 = (((4 + ((((int)((unsigned int)((int)((unsigned int)v337 >> 2)) >> 1)) & 3) * 2)) + ((((v385 + ((~(((v387 ^ -1) | (-(v387 ^ -1))) >> 31)) & 2)) - (v389 + ((~(((v391 ^ -1) | (-(v391 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
      v413[v609] = v410;
      int * v415 = v333->cache_tags;
      int v612 = (int)((unsigned int)((int)((unsigned int)v337 >> 2)) >> 1);
      v415[v586] = v612;
      int * v417 = v333->cache_dirty;
      v417[v586] = 0;
      int * v419 = v333->cache_age;
      v419[v586] = 1;
      int * v421 = v333->cache_age;
      int v422 = v421[v586];
      int * v423 = v333->cache_age;
      int v424 = v423[v549];
      int * v425 = v333->cache_age;
      int v620 = v424 + ((int)((unsigned int)(v424 - v422) >> 31));
      v425[v549] = v620;
      int * v427 = v333->cache_age;
      int v428 = v427[v551];
      int * v429 = v333->cache_age;
      int v623 = v428 + ((int)((unsigned int)(v428 - v422) >> 31));
      v429[v551] = v623;
      int * v431 = v333->cache_age;
      v431[v586] = 0;
      v434 = v586;
    }
    int * v435 = v333->cache_vals;
    int v626 = v434 * 2;
    int v436 = v435[v626];
    int * v437 = v333->cache_vals;
    int v628 = (v434 * 2) + 1;
    int v438 = v437[v628];
    int * v439 = v333->cache_vals;
    int v630 = (((((int)((unsigned int)((int)((unsigned int)v337 >> 2)) >> 1)) & 1) * 2) + ((((v364 + ((~(((v366 ^ -1) | (-(v366 ^ -1))) >> 31)) & 2)) - (v368 + ((~(((v370 ^ -1) | (-(v370 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
    v439[v630] = v436;
    int * v441 = v333->cache_vals;
    int v633 = ((((((int)((unsigned int)((int)((unsigned int)v337 >> 2)) >> 1)) & 1) * 2) + ((((v364 + ((~(((v366 ^ -1) | (-(v366 ^ -1))) >> 31)) & 2)) - (v368 + ((~(((v370 ^ -1) | (-(v370 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
    v441[v633] = v438;
    int * v443 = v333->cache_tags;
    int v636 = ((((int)((unsigned int)((int)((unsigned int)v337 >> 2)) >> 1)) & 1) * 2) + ((((v364 + ((~(((v366 ^ -1) | (-(v366 ^ -1))) >> 31)) & 2)) - (v368 + ((~(((v370 ^ -1) | (-(v370 ^ -1))) >> 31)) & 2))) >> 31) & 1);
    int v637 = (int)((unsigned int)((int)((unsigned int)v337 >> 2)) >> 1);
    v443[v636] = v637;
    int * v445 = v333->cache_dirty;
    v445[v636] = 0;
    int * v447 = v333->cache_age;
    v447[v636] = 1;
    int * v449 = v333->cache_age;
    int v450 = v449[v636];
    int * v451 = v333->cache_age;
    int v452 = v451[v545];
    int * v453 = v333->cache_age;
    int v645 = v452 + ((int)((unsigned int)(v452 - v450) >> 31));
    v453[v545] = v645;
    int * v455 = v333->cache_age;
    int v456 = v455[v547];
    int * v457 = v333->cache_age;
    int v648 = v456 + ((int)((unsigned int)(v456 - v450) >> 31));
    v457[v547] = v648;
    int * v459 = v333->cache_age;
    v459[v636] = 0;
    v462 = v636;
  }
  int * v463 = v333->cache_vals;
  int v651 = (v462 * 2) + (((int)((unsigned int)v337 >> 2)) & 1);
  v463[v651] = v339;
  int * v465 = v333->cache_tags;
  int v466 = v465[v549];
  int * v467 = v333->cache_tags;
  int v468 = v467[v551];
  bool v655 = !(((~(((v466 ^ ((int)((unsigned int)((int)((unsigned int)v337 >> 2)) >> 1))) | (-(v466 ^ ((int)((unsigned int)((int)((unsigned int)v337 >> 2)) >> 1))))) >> 31)) | (~(((v468 ^ ((int)((unsigned int)((int)((unsigned int)v337 >> 2)) >> 1))) | (-(v468 ^ ((int)((unsigned int)((int)((unsigned int)v337 >> 2)) >> 1))))) >> 31))) == 0);
  int v532;
  if (v655) {
    int * v469 = v333->cache_age;
    int v657 = (4 + ((((int)((unsigned int)((int)((unsigned int)v337 >> 2)) >> 1)) & 3) * 2)) + ((~(((v468 ^ ((int)((unsigned int)((int)((unsigned int)v337 >> 2)) >> 1))) | (-(v468 ^ ((int)((unsigned int)((int)((unsigned int)v337 >> 2)) >> 1))))) >> 31)) & 1);
    int v470 = v469[v657];
    int * v471 = v333->cache_age;
    int v472 = v471[v549];
    int * v473 = v333->cache_age;
    int v660 = v472 + ((int)((unsigned int)(v472 - v470) >> 31));
    v473[v549] = v660;
    int * v475 = v333->cache_age;
    int v476 = v475[v551];
    int * v477 = v333->cache_age;
    int v663 = v476 + ((int)((unsigned int)(v476 - v470) >> 31));
    v477[v551] = v663;
    int * v479 = v333->cache_age;
    v479[v657] = 0;
    v532 = v657;
  } else {
    int * v482 = v333->cache_age;
    int v667 = 4 + ((((int)((unsigned int)((int)((unsigned int)v337 >> 2)) >> 1)) & 3) * 2);
    int v483 = v482[v667];
    int * v484 = v333->cache_tags;
    int v485 = v484[v667];
    int * v486 = v333->cache_age;
    int v487 = v486[v551];
    int * v488 = v333->cache_tags;
    int v489 = v488[v551];
    int * v490 = v333->cache_dirty;
    int v672 = (4 + ((((int)((unsigned int)((int)((unsigned int)v337 >> 2)) >> 1)) & 3) * 2)) + ((((v483 + ((~(((v485 ^ -1) | (-(v485 ^ -1))) >> 31)) & 2)) - (v487 + ((~(((v489 ^ -1) | (-(v489 ^ -1))) >> 31)) & 2))) >> 31) & 1);
    int v491 = v490[v672];
    bool v673 = !(v491 == 0);
    if (v673) {
      int * v492 = v333->cache_tags;
      int v493 = v492[v672];
      int * v494 = v333->cache_vals;
      int v676 = ((4 + ((((int)((unsigned int)((int)((unsigned int)v337 >> 2)) >> 1)) & 3) * 2)) + ((((v483 + ((~(((v485 ^ -1) | (-(v485 ^ -1))) >> 31)) & 2)) - (v487 + ((~(((v489 ^ -1) | (-(v489 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
      int v495 = v494[v676];
      int * v496 = v333->cache_vals;
      int v678 = (((4 + ((((int)((unsigned int)((int)((unsigned int)v337 >> 2)) >> 1)) & 3) * 2)) + ((((v483 + ((~(((v485 ^ -1) | (-(v485 ^ -1))) >> 31)) & 2)) - (v487 + ((~(((v489 ^ -1) | (-(v489 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
      int v497 = v496[v678];
      int * v498 = v333->mem;
      int v680 = v493 * 2;
      v498[v680] = v495;
      int * v500 = v333->mem;
      int v683 = (v493 * 2) + 1;
      v500[v683] = v497;
      ;
    } else {
      ;
    }
    int * v505 = v333->mem;
    int v688 = ((int)((unsigned int)((int)((unsigned int)v337 >> 2)) >> 1)) * 2;
    int v506 = v505[v688];
    int * v507 = v333->mem;
    int v690 = (((int)((unsigned int)((int)((unsigned int)v337 >> 2)) >> 1)) * 2) + 1;
    int v508 = v507[v690];
    int * v509 = v333->cache_vals;
    int v692 = ((4 + ((((int)((unsigned int)((int)((unsigned int)v337 >> 2)) >> 1)) & 3) * 2)) + ((((v483 + ((~(((v485 ^ -1) | (-(v485 ^ -1))) >> 31)) & 2)) - (v487 + ((~(((v489 ^ -1) | (-(v489 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
    v509[v692] = v506;
    int * v511 = v333->cache_vals;
    int v695 = (((4 + ((((int)((unsigned int)((int)((unsigned int)v337 >> 2)) >> 1)) & 3) * 2)) + ((((v483 + ((~(((v485 ^ -1) | (-(v485 ^ -1))) >> 31)) & 2)) - (v487 + ((~(((v489 ^ -1) | (-(v489 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
    v511[v695] = v508;
    int * v513 = v333->cache_tags;
    int v698 = (int)((unsigned int)((int)((unsigned int)v337 >> 2)) >> 1);
    v513[v672] = v698;
    int * v515 = v333->cache_dirty;
    v515[v672] = 0;
    int * v517 = v333->cache_age;
    v517[v672] = 1;
    int * v519 = v333->cache_age;
    int v520 = v519[v672];
    int * v521 = v333->cache_age;
    int v522 = v521[v549];
    int * v523 = v333->cache_age;
    int v706 = v522 + ((int)((unsigned int)(v522 - v520) >> 31));
    v523[v549] = v706;
    int * v525 = v333->cache_age;
    int v526 = v525[v551];
    int * v527 = v333->cache_age;
    int v709 = v526 + ((int)((unsigned int)(v526 - v520) >> 31));
    v527[v551] = v709;
    int * v529 = v333->cache_age;
    v529[v672] = 0;
    v532 = v672;
  }
  int * v533 = v333->cache_vals;
  int v712 = (v532 * 2) + (((int)((unsigned int)v337 >> 2)) & 1);
  v533[v712] = v339;
  int * v535 = v333->cache_dirty;
  v535[v532] = 1;
  struct StateT * v537 = slot_7(v333);
  return v537;
}

struct StateT * slot_5(struct StateT * v83) {
  int v84 = v83->timer;
  int v217 = v84 + 1;
  v83->timer = v217;
  int * v86 = v83->regs;
  int v87 = v86[8];
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
  v213[5] = v212;
  struct StateT * v215 = slot_6(v83);
  return v215;
}

struct StateT * slot_2(struct StateT * v28) {
  int v29 = v28->timer;
  int v35 = v29 + 1;
  v28->timer = v35;
  int * v31 = v28->regs;
  v31[9] = 80;
  struct StateT * v33 = slot_3(v28);
  return v33;
}

struct StateT * slot_7(struct StateT * v718) {
  int v719 = v718->timer;
  int v852 = v719 + 1;
  v718->timer = v852;
  int * v721 = v718->regs;
  int v722 = v721[6];
  int * v723 = v718->cache_tags;
  int v856 = (((int)((unsigned int)((int)((unsigned int)v722 >> 2)) >> 1)) & 1) * 2;
  int v724 = v723[v856];
  int * v725 = v718->cache_tags;
  int v858 = ((((int)((unsigned int)((int)((unsigned int)v722 >> 2)) >> 1)) & 1) * 2) + 1;
  int v726 = v725[v858];
  int * v727 = v718->cache_tags;
  int v860 = 4 + ((((int)((unsigned int)((int)((unsigned int)v722 >> 2)) >> 1)) & 3) * 2);
  int v728 = v727[v860];
  int * v729 = v718->cache_tags;
  int v862 = (4 + ((((int)((unsigned int)((int)((unsigned int)v722 >> 2)) >> 1)) & 3) * 2)) + 1;
  int v730 = v729[v862];
  int v731 = v718->timer;
  int v863 = v731 + ((100 ^ (((~(((v728 ^ ((int)((unsigned int)((int)((unsigned int)v722 >> 2)) >> 1))) | (-(v728 ^ ((int)((unsigned int)((int)((unsigned int)v722 >> 2)) >> 1))))) >> 31)) | (~(((v730 ^ ((int)((unsigned int)((int)((unsigned int)v722 >> 2)) >> 1))) | (-(v730 ^ ((int)((unsigned int)((int)((unsigned int)v722 >> 2)) >> 1))))) >> 31))) & 104)) ^ (((~(((v724 ^ ((int)((unsigned int)((int)((unsigned int)v722 >> 2)) >> 1))) | (-(v724 ^ ((int)((unsigned int)((int)((unsigned int)v722 >> 2)) >> 1))))) >> 31)) | (~(((v726 ^ ((int)((unsigned int)((int)((unsigned int)v722 >> 2)) >> 1))) | (-(v726 ^ ((int)((unsigned int)((int)((unsigned int)v722 >> 2)) >> 1))))) >> 31))) & (1 ^ (100 ^ (((~(((v728 ^ ((int)((unsigned int)((int)((unsigned int)v722 >> 2)) >> 1))) | (-(v728 ^ ((int)((unsigned int)((int)((unsigned int)v722 >> 2)) >> 1))))) >> 31)) | (~(((v730 ^ ((int)((unsigned int)((int)((unsigned int)v722 >> 2)) >> 1))) | (-(v730 ^ ((int)((unsigned int)((int)((unsigned int)v722 >> 2)) >> 1))))) >> 31))) & 104)))));
  v718->timer = v863;
  int * v733 = v718->cache_vals;
  bool v864 = !(((~(((v724 ^ ((int)((unsigned int)((int)((unsigned int)v722 >> 2)) >> 1))) | (-(v724 ^ ((int)((unsigned int)((int)((unsigned int)v722 >> 2)) >> 1))))) >> 31)) | (~(((v726 ^ ((int)((unsigned int)((int)((unsigned int)v722 >> 2)) >> 1))) | (-(v726 ^ ((int)((unsigned int)((int)((unsigned int)v722 >> 2)) >> 1))))) >> 31))) == 0);
  int v846;
  if (v864) {
    int * v734 = v718->cache_age;
    int v866 = ((((int)((unsigned int)((int)((unsigned int)v722 >> 2)) >> 1)) & 1) * 2) + ((~(((v726 ^ ((int)((unsigned int)((int)((unsigned int)v722 >> 2)) >> 1))) | (-(v726 ^ ((int)((unsigned int)((int)((unsigned int)v722 >> 2)) >> 1))))) >> 31)) & 1);
    int v735 = v734[v866];
    int * v736 = v718->cache_age;
    int v737 = v736[v856];
    int * v738 = v718->cache_age;
    int v869 = v737 + ((int)((unsigned int)(v737 - v735) >> 31));
    v738[v856] = v869;
    int * v740 = v718->cache_age;
    int v741 = v740[v858];
    int * v742 = v718->cache_age;
    int v872 = v741 + ((int)((unsigned int)(v741 - v735) >> 31));
    v742[v858] = v872;
    int * v744 = v718->cache_age;
    v744[v866] = 0;
    v846 = v866;
  } else {
    int * v747 = v718->cache_age;
    int v876 = (((int)((unsigned int)((int)((unsigned int)v722 >> 2)) >> 1)) & 1) * 2;
    int v748 = v747[v876];
    int * v749 = v718->cache_tags;
    int v750 = v749[v876];
    int * v751 = v718->cache_age;
    int v752 = v751[v858];
    int * v753 = v718->cache_tags;
    int v754 = v753[v858];
    bool v880 = !(((~(((v728 ^ ((int)((unsigned int)((int)((unsigned int)v722 >> 2)) >> 1))) | (-(v728 ^ ((int)((unsigned int)((int)((unsigned int)v722 >> 2)) >> 1))))) >> 31)) | (~(((v730 ^ ((int)((unsigned int)((int)((unsigned int)v722 >> 2)) >> 1))) | (-(v730 ^ ((int)((unsigned int)((int)((unsigned int)v722 >> 2)) >> 1))))) >> 31))) == 0);
    int v818;
    if (v880) {
      int * v755 = v718->cache_age;
      int v882 = (4 + ((((int)((unsigned int)((int)((unsigned int)v722 >> 2)) >> 1)) & 3) * 2)) + ((~(((v730 ^ ((int)((unsigned int)((int)((unsigned int)v722 >> 2)) >> 1))) | (-(v730 ^ ((int)((unsigned int)((int)((unsigned int)v722 >> 2)) >> 1))))) >> 31)) & 1);
      int v756 = v755[v882];
      int * v757 = v718->cache_age;
      int v758 = v757[v860];
      int * v759 = v718->cache_age;
      int v885 = v758 + ((int)((unsigned int)(v758 - v756) >> 31));
      v759[v860] = v885;
      int * v761 = v718->cache_age;
      int v762 = v761[v862];
      int * v763 = v718->cache_age;
      int v888 = v762 + ((int)((unsigned int)(v762 - v756) >> 31));
      v763[v862] = v888;
      int * v765 = v718->cache_age;
      v765[v882] = 0;
      v818 = v882;
    } else {
      int * v768 = v718->cache_age;
      int v892 = 4 + ((((int)((unsigned int)((int)((unsigned int)v722 >> 2)) >> 1)) & 3) * 2);
      int v769 = v768[v892];
      int * v770 = v718->cache_tags;
      int v771 = v770[v892];
      int * v772 = v718->cache_age;
      int v773 = v772[v862];
      int * v774 = v718->cache_tags;
      int v775 = v774[v862];
      int * v776 = v718->cache_dirty;
      int v897 = (4 + ((((int)((unsigned int)((int)((unsigned int)v722 >> 2)) >> 1)) & 3) * 2)) + ((((v769 + ((~(((v771 ^ -1) | (-(v771 ^ -1))) >> 31)) & 2)) - (v773 + ((~(((v775 ^ -1) | (-(v775 ^ -1))) >> 31)) & 2))) >> 31) & 1);
      int v777 = v776[v897];
      bool v898 = !(v777 == 0);
      if (v898) {
        int * v778 = v718->cache_tags;
        int v779 = v778[v897];
        int * v780 = v718->cache_vals;
        int v901 = ((4 + ((((int)((unsigned int)((int)((unsigned int)v722 >> 2)) >> 1)) & 3) * 2)) + ((((v769 + ((~(((v771 ^ -1) | (-(v771 ^ -1))) >> 31)) & 2)) - (v773 + ((~(((v775 ^ -1) | (-(v775 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
        int v781 = v780[v901];
        int * v782 = v718->cache_vals;
        int v903 = (((4 + ((((int)((unsigned int)((int)((unsigned int)v722 >> 2)) >> 1)) & 3) * 2)) + ((((v769 + ((~(((v771 ^ -1) | (-(v771 ^ -1))) >> 31)) & 2)) - (v773 + ((~(((v775 ^ -1) | (-(v775 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
        int v783 = v782[v903];
        int * v784 = v718->mem;
        int v905 = v779 * 2;
        v784[v905] = v781;
        int * v786 = v718->mem;
        int v908 = (v779 * 2) + 1;
        v786[v908] = v783;
        ;
      } else {
        ;
      }
      int * v791 = v718->mem;
      int v913 = ((int)((unsigned int)((int)((unsigned int)v722 >> 2)) >> 1)) * 2;
      int v792 = v791[v913];
      int * v793 = v718->mem;
      int v915 = (((int)((unsigned int)((int)((unsigned int)v722 >> 2)) >> 1)) * 2) + 1;
      int v794 = v793[v915];
      int * v795 = v718->cache_vals;
      int v917 = ((4 + ((((int)((unsigned int)((int)((unsigned int)v722 >> 2)) >> 1)) & 3) * 2)) + ((((v769 + ((~(((v771 ^ -1) | (-(v771 ^ -1))) >> 31)) & 2)) - (v773 + ((~(((v775 ^ -1) | (-(v775 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
      v795[v917] = v792;
      int * v797 = v718->cache_vals;
      int v920 = (((4 + ((((int)((unsigned int)((int)((unsigned int)v722 >> 2)) >> 1)) & 3) * 2)) + ((((v769 + ((~(((v771 ^ -1) | (-(v771 ^ -1))) >> 31)) & 2)) - (v773 + ((~(((v775 ^ -1) | (-(v775 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
      v797[v920] = v794;
      int * v799 = v718->cache_tags;
      int v923 = (int)((unsigned int)((int)((unsigned int)v722 >> 2)) >> 1);
      v799[v897] = v923;
      int * v801 = v718->cache_dirty;
      v801[v897] = 0;
      int * v803 = v718->cache_age;
      v803[v897] = 1;
      int * v805 = v718->cache_age;
      int v806 = v805[v897];
      int * v807 = v718->cache_age;
      int v808 = v807[v860];
      int * v809 = v718->cache_age;
      int v931 = v808 + ((int)((unsigned int)(v808 - v806) >> 31));
      v809[v860] = v931;
      int * v811 = v718->cache_age;
      int v812 = v811[v862];
      int * v813 = v718->cache_age;
      int v934 = v812 + ((int)((unsigned int)(v812 - v806) >> 31));
      v813[v862] = v934;
      int * v815 = v718->cache_age;
      v815[v897] = 0;
      v818 = v897;
    }
    int * v819 = v718->cache_vals;
    int v937 = v818 * 2;
    int v820 = v819[v937];
    int * v821 = v718->cache_vals;
    int v939 = (v818 * 2) + 1;
    int v822 = v821[v939];
    int * v823 = v718->cache_vals;
    int v941 = (((((int)((unsigned int)((int)((unsigned int)v722 >> 2)) >> 1)) & 1) * 2) + ((((v748 + ((~(((v750 ^ -1) | (-(v750 ^ -1))) >> 31)) & 2)) - (v752 + ((~(((v754 ^ -1) | (-(v754 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
    v823[v941] = v820;
    int * v825 = v718->cache_vals;
    int v944 = ((((((int)((unsigned int)((int)((unsigned int)v722 >> 2)) >> 1)) & 1) * 2) + ((((v748 + ((~(((v750 ^ -1) | (-(v750 ^ -1))) >> 31)) & 2)) - (v752 + ((~(((v754 ^ -1) | (-(v754 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
    v825[v944] = v822;
    int * v827 = v718->cache_tags;
    int v947 = ((((int)((unsigned int)((int)((unsigned int)v722 >> 2)) >> 1)) & 1) * 2) + ((((v748 + ((~(((v750 ^ -1) | (-(v750 ^ -1))) >> 31)) & 2)) - (v752 + ((~(((v754 ^ -1) | (-(v754 ^ -1))) >> 31)) & 2))) >> 31) & 1);
    int v948 = (int)((unsigned int)((int)((unsigned int)v722 >> 2)) >> 1);
    v827[v947] = v948;
    int * v829 = v718->cache_dirty;
    v829[v947] = 0;
    int * v831 = v718->cache_age;
    v831[v947] = 1;
    int * v833 = v718->cache_age;
    int v834 = v833[v947];
    int * v835 = v718->cache_age;
    int v836 = v835[v856];
    int * v837 = v718->cache_age;
    int v956 = v836 + ((int)((unsigned int)(v836 - v834) >> 31));
    v837[v856] = v956;
    int * v839 = v718->cache_age;
    int v840 = v839[v858];
    int * v841 = v718->cache_age;
    int v959 = v840 + ((int)((unsigned int)(v840 - v834) >> 31));
    v841[v858] = v959;
    int * v843 = v718->cache_age;
    v843[v947] = 0;
    v846 = v947;
  }
  int v962 = (v846 * 2) + (((int)((unsigned int)v722 >> 2)) & 1);
  int v847 = v733[v962];
  int * v848 = v718->regs;
  v848[11] = v847;
  struct StateT * v850 = slot_8(v718);
  return v850;
}

struct StateT * slot_3(struct StateT * v41) {
  int v42 = v41->timer;
  int v53 = v42 + 1;
  v41->timer = v53;
  int * v44 = v41->regs;
  int v45 = v44[6];
  int * v46 = v41->regs;
  int v47 = v46[7];
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

struct StateT * snippet(struct StateT * v0) {
  struct StateT * v1 = slot_0(v0);
  return v1;
}

struct StateT * slot_1(struct StateT * v15) {
  int v16 = v15->timer;
  int v22 = v16 + 1;
  v15->timer = v22;
  int * v18 = v15->regs;
  v18[7] = 16;
  struct StateT * v20 = slot_2(v15);
  return v20;
}

struct StateT * slot_8(struct StateT * v968) {
  int v969 = v968->timer;
  int v977 = v969 + 1;
  v968->timer = v977;
  int * v971 = v968->regs;
  int v972 = v971[6];
  int * v973 = v968->regs;
  int v981 = v972 + 4;
  v973[6] = v981;
  struct StateT * v975 = slot_9(v968);
  return v975;
}

struct StateT * slot_4(struct StateT * v62) {
  int v63 = v62->timer;
  int v73 = v63 + 1;
  v62->timer = v73;
  int * v65 = v62->regs;
  int v66 = v65[9];
  int * v67 = v62->regs;
  int v68 = v67[6];
  int * v69 = v62->regs;
  int v80 = v66 + v68;
  v69[8] = v80;
  struct StateT * v71 = slot_5(v62);
  return v71;
}

struct StateT * slot_9(struct StateT * v984) {
  int v985 = v984->timer;
  int v989 = v985 + 1;
  v984->timer = v989;
  struct StateT * v987 = slot_3(v984);
  return v987;
}

struct StateT * slot_0(struct StateT * v2) {
  int v3 = v2->timer;
  int v9 = v3 + 1;
  v2->timer = v9;
  int * v5 = v2->regs;
  v5[6] = 0;
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