// verify: leak (CBMC should report VERIFICATION FAILED) [unwind 65]
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

struct StateT2 * slot_12(struct StateT2 * v1407);
struct StateT2 * slot_14(struct StateT2 * v199);
struct StateT2 * slot_6(struct StateT2 * v283);
struct StateT2 * slot_5(struct StateT2 * v232);
struct StateT2 * slot_2(struct StateT2 * v74);
struct StateT2 * slot_7(struct StateT2 * v793);
struct StateT2 * slot_3(struct StateT2 * v110);
struct StateT2 * snippet(struct StateT2 * v0);
struct StateT2 * slot_10(struct StateT2 * v1443);
struct StateT2 * slot_1(struct StateT2 * v38);
struct StateT2 * slot_8(struct StateT2 * v844);
struct StateT2 * slot_4(struct StateT2 * v146);
struct StateT2 * slot_13(struct StateT2 * v1486);
struct StateT2 * slot_9(struct StateT2 * v1354);
struct StateT2 * slot_11(struct StateT2 * v1509);
struct StateT2 * slot_0(struct StateT2 * v2);
struct StateT2 * slot_12(struct StateT2 * v1407) {
  struct StateT * v1408 = v1407->a;
  int v1409 = v1408->timer;
  struct StateT * v1410 = v1407->b;
  int v1411 = v1410->timer;
  bool v1430 = v1409 == v1411;
  squared_assert(v1430);
  squared_assume(v1430);
  struct StateT * v1414 = v1407->a;
  int v1415 = v1414->timer;
  int v1432 = v1415 + 1;
  v1414->timer = v1432;
  struct StateT * v1417 = v1407->b;
  int v1418 = v1417->timer;
  int v1434 = v1418 + 1;
  v1417->timer = v1434;
  struct StateT * v1420 = v1407->a;
  int * v1421 = v1420->regs;
  v1421[10] = 0;
  struct StateT * v1423 = v1407->b;
  int * v1424 = v1423->regs;
  v1424[10] = 0;
  struct StateT2 * v1426 = slot_13(v1407);
  return v1426;
}

struct StateT2 * slot_14(struct StateT2 * v199) {
  struct StateT * v200 = v199->a;
  int v201 = v200->timer;
  struct StateT * v202 = v199->b;
  int v203 = v202->timer;
  bool v221 = v201 == v203;
  squared_assert(v221);
  squared_assume(v221);
  struct StateT * v206 = v199->a;
  int v207 = v206->timer;
  int v223 = v207 + 1;
  v206->timer = v223;
  struct StateT * v209 = v199->b;
  int v210 = v209->timer;
  int v225 = v210 + 1;
  v209->timer = v225;
  struct StateT * v212 = v199->a;
  int * v213 = v212->regs;
  v213[10] = 1;
  struct StateT * v215 = v199->b;
  int * v216 = v215->regs;
  v216[10] = 1;
  return v199;
}

struct StateT2 * slot_6(struct StateT2 * v283) {
  struct StateT * v284 = v283->a;
  int v285 = v284->timer;
  struct StateT * v286 = v283->b;
  int v287 = v286->timer;
  bool v560 = v285 == v287;
  squared_assert(v560);
  squared_assume(v560);
  struct StateT * v290 = v283->a;
  int v291 = v290->timer;
  int v562 = v291 + 1;
  v290->timer = v562;
  struct StateT * v293 = v283->b;
  int v294 = v293->timer;
  int v564 = v294 + 1;
  v293->timer = v564;
  struct StateT * v296 = v283->a;
  int * v297 = v296->regs;
  int v298 = v297[5];
  int * v299 = v296->cache_tags;
  int v569 = (((int)((unsigned int)((int)((unsigned int)v298 >> 2)) >> 1)) & 1) * 2;
  int v300 = v299[v569];
  int * v301 = v296->cache_tags;
  int v571 = ((((int)((unsigned int)((int)((unsigned int)v298 >> 2)) >> 1)) & 1) * 2) + 1;
  int v302 = v301[v571];
  int * v303 = v296->cache_tags;
  int v573 = 4 + ((((int)((unsigned int)((int)((unsigned int)v298 >> 2)) >> 1)) & 3) * 2);
  int v304 = v303[v573];
  int * v305 = v296->cache_tags;
  int v575 = (4 + ((((int)((unsigned int)((int)((unsigned int)v298 >> 2)) >> 1)) & 3) * 2)) + 1;
  int v306 = v305[v575];
  int v307 = v296->timer;
  int v576 = v307 + ((100 ^ (((~(((v304 ^ ((int)((unsigned int)((int)((unsigned int)v298 >> 2)) >> 1))) | (-(v304 ^ ((int)((unsigned int)((int)((unsigned int)v298 >> 2)) >> 1))))) >> 31)) | (~(((v306 ^ ((int)((unsigned int)((int)((unsigned int)v298 >> 2)) >> 1))) | (-(v306 ^ ((int)((unsigned int)((int)((unsigned int)v298 >> 2)) >> 1))))) >> 31))) & 104)) ^ (((~(((v300 ^ ((int)((unsigned int)((int)((unsigned int)v298 >> 2)) >> 1))) | (-(v300 ^ ((int)((unsigned int)((int)((unsigned int)v298 >> 2)) >> 1))))) >> 31)) | (~(((v302 ^ ((int)((unsigned int)((int)((unsigned int)v298 >> 2)) >> 1))) | (-(v302 ^ ((int)((unsigned int)((int)((unsigned int)v298 >> 2)) >> 1))))) >> 31))) & (1 ^ (100 ^ (((~(((v304 ^ ((int)((unsigned int)((int)((unsigned int)v298 >> 2)) >> 1))) | (-(v304 ^ ((int)((unsigned int)((int)((unsigned int)v298 >> 2)) >> 1))))) >> 31)) | (~(((v306 ^ ((int)((unsigned int)((int)((unsigned int)v298 >> 2)) >> 1))) | (-(v306 ^ ((int)((unsigned int)((int)((unsigned int)v298 >> 2)) >> 1))))) >> 31))) & 104)))));
  v296->timer = v576;
  int * v309 = v296->cache_vals;
  bool v577 = !(((~(((v300 ^ ((int)((unsigned int)((int)((unsigned int)v298 >> 2)) >> 1))) | (-(v300 ^ ((int)((unsigned int)((int)((unsigned int)v298 >> 2)) >> 1))))) >> 31)) | (~(((v302 ^ ((int)((unsigned int)((int)((unsigned int)v298 >> 2)) >> 1))) | (-(v302 ^ ((int)((unsigned int)((int)((unsigned int)v298 >> 2)) >> 1))))) >> 31))) == 0);
  int v422;
  if (v577) {
    int * v310 = v296->cache_age;
    int v579 = ((((int)((unsigned int)((int)((unsigned int)v298 >> 2)) >> 1)) & 1) * 2) + ((~(((v302 ^ ((int)((unsigned int)((int)((unsigned int)v298 >> 2)) >> 1))) | (-(v302 ^ ((int)((unsigned int)((int)((unsigned int)v298 >> 2)) >> 1))))) >> 31)) & 1);
    int v311 = v310[v579];
    int * v312 = v296->cache_age;
    int v313 = v312[v569];
    int * v314 = v296->cache_age;
    int v582 = v313 + ((int)((unsigned int)(v313 - v311) >> 31));
    v314[v569] = v582;
    int * v316 = v296->cache_age;
    int v317 = v316[v571];
    int * v318 = v296->cache_age;
    int v585 = v317 + ((int)((unsigned int)(v317 - v311) >> 31));
    v318[v571] = v585;
    int * v320 = v296->cache_age;
    v320[v579] = 0;
    v422 = v579;
  } else {
    int * v323 = v296->cache_age;
    int v589 = (((int)((unsigned int)((int)((unsigned int)v298 >> 2)) >> 1)) & 1) * 2;
    int v324 = v323[v589];
    int * v325 = v296->cache_tags;
    int v326 = v325[v589];
    int * v327 = v296->cache_age;
    int v328 = v327[v571];
    int * v329 = v296->cache_tags;
    int v330 = v329[v571];
    bool v593 = !(((~(((v304 ^ ((int)((unsigned int)((int)((unsigned int)v298 >> 2)) >> 1))) | (-(v304 ^ ((int)((unsigned int)((int)((unsigned int)v298 >> 2)) >> 1))))) >> 31)) | (~(((v306 ^ ((int)((unsigned int)((int)((unsigned int)v298 >> 2)) >> 1))) | (-(v306 ^ ((int)((unsigned int)((int)((unsigned int)v298 >> 2)) >> 1))))) >> 31))) == 0);
    int v394;
    if (v593) {
      int * v331 = v296->cache_age;
      int v595 = (4 + ((((int)((unsigned int)((int)((unsigned int)v298 >> 2)) >> 1)) & 3) * 2)) + ((~(((v306 ^ ((int)((unsigned int)((int)((unsigned int)v298 >> 2)) >> 1))) | (-(v306 ^ ((int)((unsigned int)((int)((unsigned int)v298 >> 2)) >> 1))))) >> 31)) & 1);
      int v332 = v331[v595];
      int * v333 = v296->cache_age;
      int v334 = v333[v573];
      int * v335 = v296->cache_age;
      int v598 = v334 + ((int)((unsigned int)(v334 - v332) >> 31));
      v335[v573] = v598;
      int * v337 = v296->cache_age;
      int v338 = v337[v575];
      int * v339 = v296->cache_age;
      int v601 = v338 + ((int)((unsigned int)(v338 - v332) >> 31));
      v339[v575] = v601;
      int * v341 = v296->cache_age;
      v341[v595] = 0;
      v394 = v595;
    } else {
      int * v344 = v296->cache_age;
      int v605 = 4 + ((((int)((unsigned int)((int)((unsigned int)v298 >> 2)) >> 1)) & 3) * 2);
      int v345 = v344[v605];
      int * v346 = v296->cache_tags;
      int v347 = v346[v605];
      int * v348 = v296->cache_age;
      int v349 = v348[v575];
      int * v350 = v296->cache_tags;
      int v351 = v350[v575];
      int * v352 = v296->cache_dirty;
      int v610 = (4 + ((((int)((unsigned int)((int)((unsigned int)v298 >> 2)) >> 1)) & 3) * 2)) + ((((v345 + ((~(((v347 ^ -1) | (-(v347 ^ -1))) >> 31)) & 2)) - (v349 + ((~(((v351 ^ -1) | (-(v351 ^ -1))) >> 31)) & 2))) >> 31) & 1);
      int v353 = v352[v610];
      bool v611 = !(v353 == 0);
      if (v611) {
        int * v354 = v296->cache_tags;
        int v355 = v354[v610];
        int * v356 = v296->cache_vals;
        int v614 = ((4 + ((((int)((unsigned int)((int)((unsigned int)v298 >> 2)) >> 1)) & 3) * 2)) + ((((v345 + ((~(((v347 ^ -1) | (-(v347 ^ -1))) >> 31)) & 2)) - (v349 + ((~(((v351 ^ -1) | (-(v351 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
        int v357 = v356[v614];
        int * v358 = v296->cache_vals;
        int v616 = (((4 + ((((int)((unsigned int)((int)((unsigned int)v298 >> 2)) >> 1)) & 3) * 2)) + ((((v345 + ((~(((v347 ^ -1) | (-(v347 ^ -1))) >> 31)) & 2)) - (v349 + ((~(((v351 ^ -1) | (-(v351 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
        int v359 = v358[v616];
        int * v360 = v296->mem;
        int v618 = v355 * 2;
        v360[v618] = v357;
        int * v362 = v296->mem;
        int v621 = (v355 * 2) + 1;
        v362[v621] = v359;
        ;
      } else {
        ;
      }
      int * v367 = v296->mem;
      int v626 = ((int)((unsigned int)((int)((unsigned int)v298 >> 2)) >> 1)) * 2;
      int v368 = v367[v626];
      int * v369 = v296->mem;
      int v628 = (((int)((unsigned int)((int)((unsigned int)v298 >> 2)) >> 1)) * 2) + 1;
      int v370 = v369[v628];
      int * v371 = v296->cache_vals;
      int v630 = ((4 + ((((int)((unsigned int)((int)((unsigned int)v298 >> 2)) >> 1)) & 3) * 2)) + ((((v345 + ((~(((v347 ^ -1) | (-(v347 ^ -1))) >> 31)) & 2)) - (v349 + ((~(((v351 ^ -1) | (-(v351 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
      v371[v630] = v368;
      int * v373 = v296->cache_vals;
      int v633 = (((4 + ((((int)((unsigned int)((int)((unsigned int)v298 >> 2)) >> 1)) & 3) * 2)) + ((((v345 + ((~(((v347 ^ -1) | (-(v347 ^ -1))) >> 31)) & 2)) - (v349 + ((~(((v351 ^ -1) | (-(v351 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
      v373[v633] = v370;
      int * v375 = v296->cache_tags;
      int v636 = (int)((unsigned int)((int)((unsigned int)v298 >> 2)) >> 1);
      v375[v610] = v636;
      int * v377 = v296->cache_dirty;
      v377[v610] = 0;
      int * v379 = v296->cache_age;
      v379[v610] = 1;
      int * v381 = v296->cache_age;
      int v382 = v381[v610];
      int * v383 = v296->cache_age;
      int v384 = v383[v573];
      int * v385 = v296->cache_age;
      int v644 = v384 + ((int)((unsigned int)(v384 - v382) >> 31));
      v385[v573] = v644;
      int * v387 = v296->cache_age;
      int v388 = v387[v575];
      int * v389 = v296->cache_age;
      int v647 = v388 + ((int)((unsigned int)(v388 - v382) >> 31));
      v389[v575] = v647;
      int * v391 = v296->cache_age;
      v391[v610] = 0;
      v394 = v610;
    }
    int * v395 = v296->cache_vals;
    int v650 = v394 * 2;
    int v396 = v395[v650];
    int * v397 = v296->cache_vals;
    int v652 = (v394 * 2) + 1;
    int v398 = v397[v652];
    int * v399 = v296->cache_vals;
    int v654 = (((((int)((unsigned int)((int)((unsigned int)v298 >> 2)) >> 1)) & 1) * 2) + ((((v324 + ((~(((v326 ^ -1) | (-(v326 ^ -1))) >> 31)) & 2)) - (v328 + ((~(((v330 ^ -1) | (-(v330 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
    v399[v654] = v396;
    int * v401 = v296->cache_vals;
    int v657 = ((((((int)((unsigned int)((int)((unsigned int)v298 >> 2)) >> 1)) & 1) * 2) + ((((v324 + ((~(((v326 ^ -1) | (-(v326 ^ -1))) >> 31)) & 2)) - (v328 + ((~(((v330 ^ -1) | (-(v330 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
    v401[v657] = v398;
    int * v403 = v296->cache_tags;
    int v660 = ((((int)((unsigned int)((int)((unsigned int)v298 >> 2)) >> 1)) & 1) * 2) + ((((v324 + ((~(((v326 ^ -1) | (-(v326 ^ -1))) >> 31)) & 2)) - (v328 + ((~(((v330 ^ -1) | (-(v330 ^ -1))) >> 31)) & 2))) >> 31) & 1);
    int v661 = (int)((unsigned int)((int)((unsigned int)v298 >> 2)) >> 1);
    v403[v660] = v661;
    int * v405 = v296->cache_dirty;
    v405[v660] = 0;
    int * v407 = v296->cache_age;
    v407[v660] = 1;
    int * v409 = v296->cache_age;
    int v410 = v409[v660];
    int * v411 = v296->cache_age;
    int v412 = v411[v569];
    int * v413 = v296->cache_age;
    int v669 = v412 + ((int)((unsigned int)(v412 - v410) >> 31));
    v413[v569] = v669;
    int * v415 = v296->cache_age;
    int v416 = v415[v571];
    int * v417 = v296->cache_age;
    int v672 = v416 + ((int)((unsigned int)(v416 - v410) >> 31));
    v417[v571] = v672;
    int * v419 = v296->cache_age;
    v419[v660] = 0;
    v422 = v660;
  }
  int v675 = (v422 * 2) + (((int)((unsigned int)v298 >> 2)) & 1);
  int v423 = v309[v675];
  int * v424 = v296->regs;
  v424[10] = v423;
  struct StateT * v426 = v283->b;
  int * v427 = v426->regs;
  int v428 = v427[5];
  int * v429 = v426->cache_tags;
  int v682 = (((int)((unsigned int)((int)((unsigned int)v428 >> 2)) >> 1)) & 1) * 2;
  int v430 = v429[v682];
  int * v431 = v426->cache_tags;
  int v684 = ((((int)((unsigned int)((int)((unsigned int)v428 >> 2)) >> 1)) & 1) * 2) + 1;
  int v432 = v431[v684];
  int * v433 = v426->cache_tags;
  int v686 = 4 + ((((int)((unsigned int)((int)((unsigned int)v428 >> 2)) >> 1)) & 3) * 2);
  int v434 = v433[v686];
  int * v435 = v426->cache_tags;
  int v688 = (4 + ((((int)((unsigned int)((int)((unsigned int)v428 >> 2)) >> 1)) & 3) * 2)) + 1;
  int v436 = v435[v688];
  int v437 = v426->timer;
  int v689 = v437 + ((100 ^ (((~(((v434 ^ ((int)((unsigned int)((int)((unsigned int)v428 >> 2)) >> 1))) | (-(v434 ^ ((int)((unsigned int)((int)((unsigned int)v428 >> 2)) >> 1))))) >> 31)) | (~(((v436 ^ ((int)((unsigned int)((int)((unsigned int)v428 >> 2)) >> 1))) | (-(v436 ^ ((int)((unsigned int)((int)((unsigned int)v428 >> 2)) >> 1))))) >> 31))) & 104)) ^ (((~(((v430 ^ ((int)((unsigned int)((int)((unsigned int)v428 >> 2)) >> 1))) | (-(v430 ^ ((int)((unsigned int)((int)((unsigned int)v428 >> 2)) >> 1))))) >> 31)) | (~(((v432 ^ ((int)((unsigned int)((int)((unsigned int)v428 >> 2)) >> 1))) | (-(v432 ^ ((int)((unsigned int)((int)((unsigned int)v428 >> 2)) >> 1))))) >> 31))) & (1 ^ (100 ^ (((~(((v434 ^ ((int)((unsigned int)((int)((unsigned int)v428 >> 2)) >> 1))) | (-(v434 ^ ((int)((unsigned int)((int)((unsigned int)v428 >> 2)) >> 1))))) >> 31)) | (~(((v436 ^ ((int)((unsigned int)((int)((unsigned int)v428 >> 2)) >> 1))) | (-(v436 ^ ((int)((unsigned int)((int)((unsigned int)v428 >> 2)) >> 1))))) >> 31))) & 104)))));
  v426->timer = v689;
  int * v439 = v426->cache_vals;
  bool v690 = !(((~(((v430 ^ ((int)((unsigned int)((int)((unsigned int)v428 >> 2)) >> 1))) | (-(v430 ^ ((int)((unsigned int)((int)((unsigned int)v428 >> 2)) >> 1))))) >> 31)) | (~(((v432 ^ ((int)((unsigned int)((int)((unsigned int)v428 >> 2)) >> 1))) | (-(v432 ^ ((int)((unsigned int)((int)((unsigned int)v428 >> 2)) >> 1))))) >> 31))) == 0);
  int v552;
  if (v690) {
    int * v440 = v426->cache_age;
    int v692 = ((((int)((unsigned int)((int)((unsigned int)v428 >> 2)) >> 1)) & 1) * 2) + ((~(((v432 ^ ((int)((unsigned int)((int)((unsigned int)v428 >> 2)) >> 1))) | (-(v432 ^ ((int)((unsigned int)((int)((unsigned int)v428 >> 2)) >> 1))))) >> 31)) & 1);
    int v441 = v440[v692];
    int * v442 = v426->cache_age;
    int v443 = v442[v682];
    int * v444 = v426->cache_age;
    int v695 = v443 + ((int)((unsigned int)(v443 - v441) >> 31));
    v444[v682] = v695;
    int * v446 = v426->cache_age;
    int v447 = v446[v684];
    int * v448 = v426->cache_age;
    int v698 = v447 + ((int)((unsigned int)(v447 - v441) >> 31));
    v448[v684] = v698;
    int * v450 = v426->cache_age;
    v450[v692] = 0;
    v552 = v692;
  } else {
    int * v453 = v426->cache_age;
    int v702 = (((int)((unsigned int)((int)((unsigned int)v428 >> 2)) >> 1)) & 1) * 2;
    int v454 = v453[v702];
    int * v455 = v426->cache_tags;
    int v456 = v455[v702];
    int * v457 = v426->cache_age;
    int v458 = v457[v684];
    int * v459 = v426->cache_tags;
    int v460 = v459[v684];
    bool v706 = !(((~(((v434 ^ ((int)((unsigned int)((int)((unsigned int)v428 >> 2)) >> 1))) | (-(v434 ^ ((int)((unsigned int)((int)((unsigned int)v428 >> 2)) >> 1))))) >> 31)) | (~(((v436 ^ ((int)((unsigned int)((int)((unsigned int)v428 >> 2)) >> 1))) | (-(v436 ^ ((int)((unsigned int)((int)((unsigned int)v428 >> 2)) >> 1))))) >> 31))) == 0);
    int v524;
    if (v706) {
      int * v461 = v426->cache_age;
      int v708 = (4 + ((((int)((unsigned int)((int)((unsigned int)v428 >> 2)) >> 1)) & 3) * 2)) + ((~(((v436 ^ ((int)((unsigned int)((int)((unsigned int)v428 >> 2)) >> 1))) | (-(v436 ^ ((int)((unsigned int)((int)((unsigned int)v428 >> 2)) >> 1))))) >> 31)) & 1);
      int v462 = v461[v708];
      int * v463 = v426->cache_age;
      int v464 = v463[v686];
      int * v465 = v426->cache_age;
      int v711 = v464 + ((int)((unsigned int)(v464 - v462) >> 31));
      v465[v686] = v711;
      int * v467 = v426->cache_age;
      int v468 = v467[v688];
      int * v469 = v426->cache_age;
      int v714 = v468 + ((int)((unsigned int)(v468 - v462) >> 31));
      v469[v688] = v714;
      int * v471 = v426->cache_age;
      v471[v708] = 0;
      v524 = v708;
    } else {
      int * v474 = v426->cache_age;
      int v718 = 4 + ((((int)((unsigned int)((int)((unsigned int)v428 >> 2)) >> 1)) & 3) * 2);
      int v475 = v474[v718];
      int * v476 = v426->cache_tags;
      int v477 = v476[v718];
      int * v478 = v426->cache_age;
      int v479 = v478[v688];
      int * v480 = v426->cache_tags;
      int v481 = v480[v688];
      int * v482 = v426->cache_dirty;
      int v723 = (4 + ((((int)((unsigned int)((int)((unsigned int)v428 >> 2)) >> 1)) & 3) * 2)) + ((((v475 + ((~(((v477 ^ -1) | (-(v477 ^ -1))) >> 31)) & 2)) - (v479 + ((~(((v481 ^ -1) | (-(v481 ^ -1))) >> 31)) & 2))) >> 31) & 1);
      int v483 = v482[v723];
      bool v724 = !(v483 == 0);
      if (v724) {
        int * v484 = v426->cache_tags;
        int v485 = v484[v723];
        int * v486 = v426->cache_vals;
        int v727 = ((4 + ((((int)((unsigned int)((int)((unsigned int)v428 >> 2)) >> 1)) & 3) * 2)) + ((((v475 + ((~(((v477 ^ -1) | (-(v477 ^ -1))) >> 31)) & 2)) - (v479 + ((~(((v481 ^ -1) | (-(v481 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
        int v487 = v486[v727];
        int * v488 = v426->cache_vals;
        int v729 = (((4 + ((((int)((unsigned int)((int)((unsigned int)v428 >> 2)) >> 1)) & 3) * 2)) + ((((v475 + ((~(((v477 ^ -1) | (-(v477 ^ -1))) >> 31)) & 2)) - (v479 + ((~(((v481 ^ -1) | (-(v481 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
        int v489 = v488[v729];
        int * v490 = v426->mem;
        int v731 = v485 * 2;
        v490[v731] = v487;
        int * v492 = v426->mem;
        int v734 = (v485 * 2) + 1;
        v492[v734] = v489;
        ;
      } else {
        ;
      }
      int * v497 = v426->mem;
      int v739 = ((int)((unsigned int)((int)((unsigned int)v428 >> 2)) >> 1)) * 2;
      int v498 = v497[v739];
      int * v499 = v426->mem;
      int v741 = (((int)((unsigned int)((int)((unsigned int)v428 >> 2)) >> 1)) * 2) + 1;
      int v500 = v499[v741];
      int * v501 = v426->cache_vals;
      int v743 = ((4 + ((((int)((unsigned int)((int)((unsigned int)v428 >> 2)) >> 1)) & 3) * 2)) + ((((v475 + ((~(((v477 ^ -1) | (-(v477 ^ -1))) >> 31)) & 2)) - (v479 + ((~(((v481 ^ -1) | (-(v481 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
      v501[v743] = v498;
      int * v503 = v426->cache_vals;
      int v746 = (((4 + ((((int)((unsigned int)((int)((unsigned int)v428 >> 2)) >> 1)) & 3) * 2)) + ((((v475 + ((~(((v477 ^ -1) | (-(v477 ^ -1))) >> 31)) & 2)) - (v479 + ((~(((v481 ^ -1) | (-(v481 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
      v503[v746] = v500;
      int * v505 = v426->cache_tags;
      int v749 = (int)((unsigned int)((int)((unsigned int)v428 >> 2)) >> 1);
      v505[v723] = v749;
      int * v507 = v426->cache_dirty;
      v507[v723] = 0;
      int * v509 = v426->cache_age;
      v509[v723] = 1;
      int * v511 = v426->cache_age;
      int v512 = v511[v723];
      int * v513 = v426->cache_age;
      int v514 = v513[v686];
      int * v515 = v426->cache_age;
      int v757 = v514 + ((int)((unsigned int)(v514 - v512) >> 31));
      v515[v686] = v757;
      int * v517 = v426->cache_age;
      int v518 = v517[v688];
      int * v519 = v426->cache_age;
      int v760 = v518 + ((int)((unsigned int)(v518 - v512) >> 31));
      v519[v688] = v760;
      int * v521 = v426->cache_age;
      v521[v723] = 0;
      v524 = v723;
    }
    int * v525 = v426->cache_vals;
    int v763 = v524 * 2;
    int v526 = v525[v763];
    int * v527 = v426->cache_vals;
    int v765 = (v524 * 2) + 1;
    int v528 = v527[v765];
    int * v529 = v426->cache_vals;
    int v767 = (((((int)((unsigned int)((int)((unsigned int)v428 >> 2)) >> 1)) & 1) * 2) + ((((v454 + ((~(((v456 ^ -1) | (-(v456 ^ -1))) >> 31)) & 2)) - (v458 + ((~(((v460 ^ -1) | (-(v460 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
    v529[v767] = v526;
    int * v531 = v426->cache_vals;
    int v770 = ((((((int)((unsigned int)((int)((unsigned int)v428 >> 2)) >> 1)) & 1) * 2) + ((((v454 + ((~(((v456 ^ -1) | (-(v456 ^ -1))) >> 31)) & 2)) - (v458 + ((~(((v460 ^ -1) | (-(v460 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
    v531[v770] = v528;
    int * v533 = v426->cache_tags;
    int v773 = ((((int)((unsigned int)((int)((unsigned int)v428 >> 2)) >> 1)) & 1) * 2) + ((((v454 + ((~(((v456 ^ -1) | (-(v456 ^ -1))) >> 31)) & 2)) - (v458 + ((~(((v460 ^ -1) | (-(v460 ^ -1))) >> 31)) & 2))) >> 31) & 1);
    int v774 = (int)((unsigned int)((int)((unsigned int)v428 >> 2)) >> 1);
    v533[v773] = v774;
    int * v535 = v426->cache_dirty;
    v535[v773] = 0;
    int * v537 = v426->cache_age;
    v537[v773] = 1;
    int * v539 = v426->cache_age;
    int v540 = v539[v773];
    int * v541 = v426->cache_age;
    int v542 = v541[v682];
    int * v543 = v426->cache_age;
    int v782 = v542 + ((int)((unsigned int)(v542 - v540) >> 31));
    v543[v682] = v782;
    int * v545 = v426->cache_age;
    int v546 = v545[v684];
    int * v547 = v426->cache_age;
    int v785 = v546 + ((int)((unsigned int)(v546 - v540) >> 31));
    v547[v684] = v785;
    int * v549 = v426->cache_age;
    v549[v773] = 0;
    v552 = v773;
  }
  int v788 = (v552 * 2) + (((int)((unsigned int)v428 >> 2)) & 1);
  int v553 = v439[v788];
  int * v554 = v426->regs;
  v554[10] = v553;
  struct StateT2 * v556 = slot_7(v283);
  return v556;
}

struct StateT2 * slot_5(struct StateT2 * v232) {
  struct StateT * v233 = v232->a;
  int v234 = v233->timer;
  struct StateT * v235 = v232->b;
  int v236 = v235->timer;
  bool v263 = v234 == v236;
  squared_assert(v263);
  squared_assume(v263);
  struct StateT * v239 = v232->a;
  int v240 = v239->timer;
  int v265 = v240 + 1;
  v239->timer = v265;
  struct StateT * v242 = v232->b;
  int v243 = v242->timer;
  int v267 = v243 + 1;
  v242->timer = v267;
  struct StateT * v245 = v232->a;
  int * v246 = v245->regs;
  int v247 = v246[12];
  int * v248 = v245->regs;
  int v249 = v248[14];
  int * v250 = v245->regs;
  int v275 = v247 + v249;
  v250[5] = v275;
  struct StateT * v252 = v232->b;
  int * v253 = v252->regs;
  int v254 = v253[12];
  int * v255 = v252->regs;
  int v256 = v255[14];
  int * v257 = v252->regs;
  int v280 = v254 + v256;
  v257[5] = v280;
  struct StateT2 * v259 = slot_6(v232);
  return v259;
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

struct StateT2 * slot_7(struct StateT2 * v793) {
  struct StateT * v794 = v793->a;
  int v795 = v794->timer;
  struct StateT * v796 = v793->b;
  int v797 = v796->timer;
  bool v824 = v795 == v797;
  squared_assert(v824);
  squared_assume(v824);
  struct StateT * v800 = v793->a;
  int v801 = v800->timer;
  int v826 = v801 + 1;
  v800->timer = v826;
  struct StateT * v803 = v793->b;
  int v804 = v803->timer;
  int v828 = v804 + 1;
  v803->timer = v828;
  struct StateT * v806 = v793->a;
  int * v807 = v806->regs;
  int v808 = v807[13];
  int * v809 = v806->regs;
  int v810 = v809[14];
  int * v811 = v806->regs;
  int v836 = v808 + v810;
  v811[6] = v836;
  struct StateT * v813 = v793->b;
  int * v814 = v813->regs;
  int v815 = v814[13];
  int * v816 = v813->regs;
  int v817 = v816[14];
  int * v818 = v813->regs;
  int v841 = v815 + v817;
  v818[6] = v841;
  struct StateT2 * v820 = slot_8(v793);
  return v820;
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

struct StateT2 * slot_10(struct StateT2 * v1443) {
  struct StateT * v1444 = v1443->a;
  int v1445 = v1444->timer;
  struct StateT * v1446 = v1443->b;
  int v1447 = v1446->timer;
  bool v1470 = v1445 == v1447;
  squared_assert(v1470);
  squared_assume(v1470);
  struct StateT * v1450 = v1443->a;
  int v1451 = v1450->timer;
  int v1472 = v1451 + 1;
  v1450->timer = v1472;
  struct StateT * v1453 = v1443->b;
  int v1454 = v1453->timer;
  int v1474 = v1454 + 1;
  v1453->timer = v1474;
  struct StateT * v1456 = v1443->a;
  int * v1457 = v1456->regs;
  int v1458 = v1457[14];
  int * v1459 = v1456->regs;
  int v1479 = v1458 + 4;
  v1459[14] = v1479;
  struct StateT * v1461 = v1443->b;
  int * v1462 = v1461->regs;
  int v1463 = v1462[14];
  int * v1464 = v1461->regs;
  int v1483 = v1463 + 4;
  v1464[14] = v1483;
  struct StateT2 * v1466 = slot_11(v1443);
  return v1466;
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

struct StateT2 * slot_8(struct StateT2 * v844) {
  struct StateT * v845 = v844->a;
  int v846 = v845->timer;
  struct StateT * v847 = v844->b;
  int v848 = v847->timer;
  bool v1121 = v846 == v848;
  squared_assert(v1121);
  squared_assume(v1121);
  struct StateT * v851 = v844->a;
  int v852 = v851->timer;
  int v1123 = v852 + 1;
  v851->timer = v1123;
  struct StateT * v854 = v844->b;
  int v855 = v854->timer;
  int v1125 = v855 + 1;
  v854->timer = v1125;
  struct StateT * v857 = v844->a;
  int * v858 = v857->regs;
  int v859 = v858[6];
  int * v860 = v857->cache_tags;
  int v1130 = (((int)((unsigned int)((int)((unsigned int)v859 >> 2)) >> 1)) & 1) * 2;
  int v861 = v860[v1130];
  int * v862 = v857->cache_tags;
  int v1132 = ((((int)((unsigned int)((int)((unsigned int)v859 >> 2)) >> 1)) & 1) * 2) + 1;
  int v863 = v862[v1132];
  int * v864 = v857->cache_tags;
  int v1134 = 4 + ((((int)((unsigned int)((int)((unsigned int)v859 >> 2)) >> 1)) & 3) * 2);
  int v865 = v864[v1134];
  int * v866 = v857->cache_tags;
  int v1136 = (4 + ((((int)((unsigned int)((int)((unsigned int)v859 >> 2)) >> 1)) & 3) * 2)) + 1;
  int v867 = v866[v1136];
  int v868 = v857->timer;
  int v1137 = v868 + ((100 ^ (((~(((v865 ^ ((int)((unsigned int)((int)((unsigned int)v859 >> 2)) >> 1))) | (-(v865 ^ ((int)((unsigned int)((int)((unsigned int)v859 >> 2)) >> 1))))) >> 31)) | (~(((v867 ^ ((int)((unsigned int)((int)((unsigned int)v859 >> 2)) >> 1))) | (-(v867 ^ ((int)((unsigned int)((int)((unsigned int)v859 >> 2)) >> 1))))) >> 31))) & 104)) ^ (((~(((v861 ^ ((int)((unsigned int)((int)((unsigned int)v859 >> 2)) >> 1))) | (-(v861 ^ ((int)((unsigned int)((int)((unsigned int)v859 >> 2)) >> 1))))) >> 31)) | (~(((v863 ^ ((int)((unsigned int)((int)((unsigned int)v859 >> 2)) >> 1))) | (-(v863 ^ ((int)((unsigned int)((int)((unsigned int)v859 >> 2)) >> 1))))) >> 31))) & (1 ^ (100 ^ (((~(((v865 ^ ((int)((unsigned int)((int)((unsigned int)v859 >> 2)) >> 1))) | (-(v865 ^ ((int)((unsigned int)((int)((unsigned int)v859 >> 2)) >> 1))))) >> 31)) | (~(((v867 ^ ((int)((unsigned int)((int)((unsigned int)v859 >> 2)) >> 1))) | (-(v867 ^ ((int)((unsigned int)((int)((unsigned int)v859 >> 2)) >> 1))))) >> 31))) & 104)))));
  v857->timer = v1137;
  int * v870 = v857->cache_vals;
  bool v1138 = !(((~(((v861 ^ ((int)((unsigned int)((int)((unsigned int)v859 >> 2)) >> 1))) | (-(v861 ^ ((int)((unsigned int)((int)((unsigned int)v859 >> 2)) >> 1))))) >> 31)) | (~(((v863 ^ ((int)((unsigned int)((int)((unsigned int)v859 >> 2)) >> 1))) | (-(v863 ^ ((int)((unsigned int)((int)((unsigned int)v859 >> 2)) >> 1))))) >> 31))) == 0);
  int v983;
  if (v1138) {
    int * v871 = v857->cache_age;
    int v1140 = ((((int)((unsigned int)((int)((unsigned int)v859 >> 2)) >> 1)) & 1) * 2) + ((~(((v863 ^ ((int)((unsigned int)((int)((unsigned int)v859 >> 2)) >> 1))) | (-(v863 ^ ((int)((unsigned int)((int)((unsigned int)v859 >> 2)) >> 1))))) >> 31)) & 1);
    int v872 = v871[v1140];
    int * v873 = v857->cache_age;
    int v874 = v873[v1130];
    int * v875 = v857->cache_age;
    int v1143 = v874 + ((int)((unsigned int)(v874 - v872) >> 31));
    v875[v1130] = v1143;
    int * v877 = v857->cache_age;
    int v878 = v877[v1132];
    int * v879 = v857->cache_age;
    int v1146 = v878 + ((int)((unsigned int)(v878 - v872) >> 31));
    v879[v1132] = v1146;
    int * v881 = v857->cache_age;
    v881[v1140] = 0;
    v983 = v1140;
  } else {
    int * v884 = v857->cache_age;
    int v1150 = (((int)((unsigned int)((int)((unsigned int)v859 >> 2)) >> 1)) & 1) * 2;
    int v885 = v884[v1150];
    int * v886 = v857->cache_tags;
    int v887 = v886[v1150];
    int * v888 = v857->cache_age;
    int v889 = v888[v1132];
    int * v890 = v857->cache_tags;
    int v891 = v890[v1132];
    bool v1154 = !(((~(((v865 ^ ((int)((unsigned int)((int)((unsigned int)v859 >> 2)) >> 1))) | (-(v865 ^ ((int)((unsigned int)((int)((unsigned int)v859 >> 2)) >> 1))))) >> 31)) | (~(((v867 ^ ((int)((unsigned int)((int)((unsigned int)v859 >> 2)) >> 1))) | (-(v867 ^ ((int)((unsigned int)((int)((unsigned int)v859 >> 2)) >> 1))))) >> 31))) == 0);
    int v955;
    if (v1154) {
      int * v892 = v857->cache_age;
      int v1156 = (4 + ((((int)((unsigned int)((int)((unsigned int)v859 >> 2)) >> 1)) & 3) * 2)) + ((~(((v867 ^ ((int)((unsigned int)((int)((unsigned int)v859 >> 2)) >> 1))) | (-(v867 ^ ((int)((unsigned int)((int)((unsigned int)v859 >> 2)) >> 1))))) >> 31)) & 1);
      int v893 = v892[v1156];
      int * v894 = v857->cache_age;
      int v895 = v894[v1134];
      int * v896 = v857->cache_age;
      int v1159 = v895 + ((int)((unsigned int)(v895 - v893) >> 31));
      v896[v1134] = v1159;
      int * v898 = v857->cache_age;
      int v899 = v898[v1136];
      int * v900 = v857->cache_age;
      int v1162 = v899 + ((int)((unsigned int)(v899 - v893) >> 31));
      v900[v1136] = v1162;
      int * v902 = v857->cache_age;
      v902[v1156] = 0;
      v955 = v1156;
    } else {
      int * v905 = v857->cache_age;
      int v1166 = 4 + ((((int)((unsigned int)((int)((unsigned int)v859 >> 2)) >> 1)) & 3) * 2);
      int v906 = v905[v1166];
      int * v907 = v857->cache_tags;
      int v908 = v907[v1166];
      int * v909 = v857->cache_age;
      int v910 = v909[v1136];
      int * v911 = v857->cache_tags;
      int v912 = v911[v1136];
      int * v913 = v857->cache_dirty;
      int v1171 = (4 + ((((int)((unsigned int)((int)((unsigned int)v859 >> 2)) >> 1)) & 3) * 2)) + ((((v906 + ((~(((v908 ^ -1) | (-(v908 ^ -1))) >> 31)) & 2)) - (v910 + ((~(((v912 ^ -1) | (-(v912 ^ -1))) >> 31)) & 2))) >> 31) & 1);
      int v914 = v913[v1171];
      bool v1172 = !(v914 == 0);
      if (v1172) {
        int * v915 = v857->cache_tags;
        int v916 = v915[v1171];
        int * v917 = v857->cache_vals;
        int v1175 = ((4 + ((((int)((unsigned int)((int)((unsigned int)v859 >> 2)) >> 1)) & 3) * 2)) + ((((v906 + ((~(((v908 ^ -1) | (-(v908 ^ -1))) >> 31)) & 2)) - (v910 + ((~(((v912 ^ -1) | (-(v912 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
        int v918 = v917[v1175];
        int * v919 = v857->cache_vals;
        int v1177 = (((4 + ((((int)((unsigned int)((int)((unsigned int)v859 >> 2)) >> 1)) & 3) * 2)) + ((((v906 + ((~(((v908 ^ -1) | (-(v908 ^ -1))) >> 31)) & 2)) - (v910 + ((~(((v912 ^ -1) | (-(v912 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
        int v920 = v919[v1177];
        int * v921 = v857->mem;
        int v1179 = v916 * 2;
        v921[v1179] = v918;
        int * v923 = v857->mem;
        int v1182 = (v916 * 2) + 1;
        v923[v1182] = v920;
        ;
      } else {
        ;
      }
      int * v928 = v857->mem;
      int v1187 = ((int)((unsigned int)((int)((unsigned int)v859 >> 2)) >> 1)) * 2;
      int v929 = v928[v1187];
      int * v930 = v857->mem;
      int v1189 = (((int)((unsigned int)((int)((unsigned int)v859 >> 2)) >> 1)) * 2) + 1;
      int v931 = v930[v1189];
      int * v932 = v857->cache_vals;
      int v1191 = ((4 + ((((int)((unsigned int)((int)((unsigned int)v859 >> 2)) >> 1)) & 3) * 2)) + ((((v906 + ((~(((v908 ^ -1) | (-(v908 ^ -1))) >> 31)) & 2)) - (v910 + ((~(((v912 ^ -1) | (-(v912 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
      v932[v1191] = v929;
      int * v934 = v857->cache_vals;
      int v1194 = (((4 + ((((int)((unsigned int)((int)((unsigned int)v859 >> 2)) >> 1)) & 3) * 2)) + ((((v906 + ((~(((v908 ^ -1) | (-(v908 ^ -1))) >> 31)) & 2)) - (v910 + ((~(((v912 ^ -1) | (-(v912 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
      v934[v1194] = v931;
      int * v936 = v857->cache_tags;
      int v1197 = (int)((unsigned int)((int)((unsigned int)v859 >> 2)) >> 1);
      v936[v1171] = v1197;
      int * v938 = v857->cache_dirty;
      v938[v1171] = 0;
      int * v940 = v857->cache_age;
      v940[v1171] = 1;
      int * v942 = v857->cache_age;
      int v943 = v942[v1171];
      int * v944 = v857->cache_age;
      int v945 = v944[v1134];
      int * v946 = v857->cache_age;
      int v1205 = v945 + ((int)((unsigned int)(v945 - v943) >> 31));
      v946[v1134] = v1205;
      int * v948 = v857->cache_age;
      int v949 = v948[v1136];
      int * v950 = v857->cache_age;
      int v1208 = v949 + ((int)((unsigned int)(v949 - v943) >> 31));
      v950[v1136] = v1208;
      int * v952 = v857->cache_age;
      v952[v1171] = 0;
      v955 = v1171;
    }
    int * v956 = v857->cache_vals;
    int v1211 = v955 * 2;
    int v957 = v956[v1211];
    int * v958 = v857->cache_vals;
    int v1213 = (v955 * 2) + 1;
    int v959 = v958[v1213];
    int * v960 = v857->cache_vals;
    int v1215 = (((((int)((unsigned int)((int)((unsigned int)v859 >> 2)) >> 1)) & 1) * 2) + ((((v885 + ((~(((v887 ^ -1) | (-(v887 ^ -1))) >> 31)) & 2)) - (v889 + ((~(((v891 ^ -1) | (-(v891 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
    v960[v1215] = v957;
    int * v962 = v857->cache_vals;
    int v1218 = ((((((int)((unsigned int)((int)((unsigned int)v859 >> 2)) >> 1)) & 1) * 2) + ((((v885 + ((~(((v887 ^ -1) | (-(v887 ^ -1))) >> 31)) & 2)) - (v889 + ((~(((v891 ^ -1) | (-(v891 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
    v962[v1218] = v959;
    int * v964 = v857->cache_tags;
    int v1221 = ((((int)((unsigned int)((int)((unsigned int)v859 >> 2)) >> 1)) & 1) * 2) + ((((v885 + ((~(((v887 ^ -1) | (-(v887 ^ -1))) >> 31)) & 2)) - (v889 + ((~(((v891 ^ -1) | (-(v891 ^ -1))) >> 31)) & 2))) >> 31) & 1);
    int v1222 = (int)((unsigned int)((int)((unsigned int)v859 >> 2)) >> 1);
    v964[v1221] = v1222;
    int * v966 = v857->cache_dirty;
    v966[v1221] = 0;
    int * v968 = v857->cache_age;
    v968[v1221] = 1;
    int * v970 = v857->cache_age;
    int v971 = v970[v1221];
    int * v972 = v857->cache_age;
    int v973 = v972[v1130];
    int * v974 = v857->cache_age;
    int v1230 = v973 + ((int)((unsigned int)(v973 - v971) >> 31));
    v974[v1130] = v1230;
    int * v976 = v857->cache_age;
    int v977 = v976[v1132];
    int * v978 = v857->cache_age;
    int v1233 = v977 + ((int)((unsigned int)(v977 - v971) >> 31));
    v978[v1132] = v1233;
    int * v980 = v857->cache_age;
    v980[v1221] = 0;
    v983 = v1221;
  }
  int v1236 = (v983 * 2) + (((int)((unsigned int)v859 >> 2)) & 1);
  int v984 = v870[v1236];
  int * v985 = v857->regs;
  v985[11] = v984;
  struct StateT * v987 = v844->b;
  int * v988 = v987->regs;
  int v989 = v988[6];
  int * v990 = v987->cache_tags;
  int v1243 = (((int)((unsigned int)((int)((unsigned int)v989 >> 2)) >> 1)) & 1) * 2;
  int v991 = v990[v1243];
  int * v992 = v987->cache_tags;
  int v1245 = ((((int)((unsigned int)((int)((unsigned int)v989 >> 2)) >> 1)) & 1) * 2) + 1;
  int v993 = v992[v1245];
  int * v994 = v987->cache_tags;
  int v1247 = 4 + ((((int)((unsigned int)((int)((unsigned int)v989 >> 2)) >> 1)) & 3) * 2);
  int v995 = v994[v1247];
  int * v996 = v987->cache_tags;
  int v1249 = (4 + ((((int)((unsigned int)((int)((unsigned int)v989 >> 2)) >> 1)) & 3) * 2)) + 1;
  int v997 = v996[v1249];
  int v998 = v987->timer;
  int v1250 = v998 + ((100 ^ (((~(((v995 ^ ((int)((unsigned int)((int)((unsigned int)v989 >> 2)) >> 1))) | (-(v995 ^ ((int)((unsigned int)((int)((unsigned int)v989 >> 2)) >> 1))))) >> 31)) | (~(((v997 ^ ((int)((unsigned int)((int)((unsigned int)v989 >> 2)) >> 1))) | (-(v997 ^ ((int)((unsigned int)((int)((unsigned int)v989 >> 2)) >> 1))))) >> 31))) & 104)) ^ (((~(((v991 ^ ((int)((unsigned int)((int)((unsigned int)v989 >> 2)) >> 1))) | (-(v991 ^ ((int)((unsigned int)((int)((unsigned int)v989 >> 2)) >> 1))))) >> 31)) | (~(((v993 ^ ((int)((unsigned int)((int)((unsigned int)v989 >> 2)) >> 1))) | (-(v993 ^ ((int)((unsigned int)((int)((unsigned int)v989 >> 2)) >> 1))))) >> 31))) & (1 ^ (100 ^ (((~(((v995 ^ ((int)((unsigned int)((int)((unsigned int)v989 >> 2)) >> 1))) | (-(v995 ^ ((int)((unsigned int)((int)((unsigned int)v989 >> 2)) >> 1))))) >> 31)) | (~(((v997 ^ ((int)((unsigned int)((int)((unsigned int)v989 >> 2)) >> 1))) | (-(v997 ^ ((int)((unsigned int)((int)((unsigned int)v989 >> 2)) >> 1))))) >> 31))) & 104)))));
  v987->timer = v1250;
  int * v1000 = v987->cache_vals;
  bool v1251 = !(((~(((v991 ^ ((int)((unsigned int)((int)((unsigned int)v989 >> 2)) >> 1))) | (-(v991 ^ ((int)((unsigned int)((int)((unsigned int)v989 >> 2)) >> 1))))) >> 31)) | (~(((v993 ^ ((int)((unsigned int)((int)((unsigned int)v989 >> 2)) >> 1))) | (-(v993 ^ ((int)((unsigned int)((int)((unsigned int)v989 >> 2)) >> 1))))) >> 31))) == 0);
  int v1113;
  if (v1251) {
    int * v1001 = v987->cache_age;
    int v1253 = ((((int)((unsigned int)((int)((unsigned int)v989 >> 2)) >> 1)) & 1) * 2) + ((~(((v993 ^ ((int)((unsigned int)((int)((unsigned int)v989 >> 2)) >> 1))) | (-(v993 ^ ((int)((unsigned int)((int)((unsigned int)v989 >> 2)) >> 1))))) >> 31)) & 1);
    int v1002 = v1001[v1253];
    int * v1003 = v987->cache_age;
    int v1004 = v1003[v1243];
    int * v1005 = v987->cache_age;
    int v1256 = v1004 + ((int)((unsigned int)(v1004 - v1002) >> 31));
    v1005[v1243] = v1256;
    int * v1007 = v987->cache_age;
    int v1008 = v1007[v1245];
    int * v1009 = v987->cache_age;
    int v1259 = v1008 + ((int)((unsigned int)(v1008 - v1002) >> 31));
    v1009[v1245] = v1259;
    int * v1011 = v987->cache_age;
    v1011[v1253] = 0;
    v1113 = v1253;
  } else {
    int * v1014 = v987->cache_age;
    int v1263 = (((int)((unsigned int)((int)((unsigned int)v989 >> 2)) >> 1)) & 1) * 2;
    int v1015 = v1014[v1263];
    int * v1016 = v987->cache_tags;
    int v1017 = v1016[v1263];
    int * v1018 = v987->cache_age;
    int v1019 = v1018[v1245];
    int * v1020 = v987->cache_tags;
    int v1021 = v1020[v1245];
    bool v1267 = !(((~(((v995 ^ ((int)((unsigned int)((int)((unsigned int)v989 >> 2)) >> 1))) | (-(v995 ^ ((int)((unsigned int)((int)((unsigned int)v989 >> 2)) >> 1))))) >> 31)) | (~(((v997 ^ ((int)((unsigned int)((int)((unsigned int)v989 >> 2)) >> 1))) | (-(v997 ^ ((int)((unsigned int)((int)((unsigned int)v989 >> 2)) >> 1))))) >> 31))) == 0);
    int v1085;
    if (v1267) {
      int * v1022 = v987->cache_age;
      int v1269 = (4 + ((((int)((unsigned int)((int)((unsigned int)v989 >> 2)) >> 1)) & 3) * 2)) + ((~(((v997 ^ ((int)((unsigned int)((int)((unsigned int)v989 >> 2)) >> 1))) | (-(v997 ^ ((int)((unsigned int)((int)((unsigned int)v989 >> 2)) >> 1))))) >> 31)) & 1);
      int v1023 = v1022[v1269];
      int * v1024 = v987->cache_age;
      int v1025 = v1024[v1247];
      int * v1026 = v987->cache_age;
      int v1272 = v1025 + ((int)((unsigned int)(v1025 - v1023) >> 31));
      v1026[v1247] = v1272;
      int * v1028 = v987->cache_age;
      int v1029 = v1028[v1249];
      int * v1030 = v987->cache_age;
      int v1275 = v1029 + ((int)((unsigned int)(v1029 - v1023) >> 31));
      v1030[v1249] = v1275;
      int * v1032 = v987->cache_age;
      v1032[v1269] = 0;
      v1085 = v1269;
    } else {
      int * v1035 = v987->cache_age;
      int v1279 = 4 + ((((int)((unsigned int)((int)((unsigned int)v989 >> 2)) >> 1)) & 3) * 2);
      int v1036 = v1035[v1279];
      int * v1037 = v987->cache_tags;
      int v1038 = v1037[v1279];
      int * v1039 = v987->cache_age;
      int v1040 = v1039[v1249];
      int * v1041 = v987->cache_tags;
      int v1042 = v1041[v1249];
      int * v1043 = v987->cache_dirty;
      int v1284 = (4 + ((((int)((unsigned int)((int)((unsigned int)v989 >> 2)) >> 1)) & 3) * 2)) + ((((v1036 + ((~(((v1038 ^ -1) | (-(v1038 ^ -1))) >> 31)) & 2)) - (v1040 + ((~(((v1042 ^ -1) | (-(v1042 ^ -1))) >> 31)) & 2))) >> 31) & 1);
      int v1044 = v1043[v1284];
      bool v1285 = !(v1044 == 0);
      if (v1285) {
        int * v1045 = v987->cache_tags;
        int v1046 = v1045[v1284];
        int * v1047 = v987->cache_vals;
        int v1288 = ((4 + ((((int)((unsigned int)((int)((unsigned int)v989 >> 2)) >> 1)) & 3) * 2)) + ((((v1036 + ((~(((v1038 ^ -1) | (-(v1038 ^ -1))) >> 31)) & 2)) - (v1040 + ((~(((v1042 ^ -1) | (-(v1042 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
        int v1048 = v1047[v1288];
        int * v1049 = v987->cache_vals;
        int v1290 = (((4 + ((((int)((unsigned int)((int)((unsigned int)v989 >> 2)) >> 1)) & 3) * 2)) + ((((v1036 + ((~(((v1038 ^ -1) | (-(v1038 ^ -1))) >> 31)) & 2)) - (v1040 + ((~(((v1042 ^ -1) | (-(v1042 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
        int v1050 = v1049[v1290];
        int * v1051 = v987->mem;
        int v1292 = v1046 * 2;
        v1051[v1292] = v1048;
        int * v1053 = v987->mem;
        int v1295 = (v1046 * 2) + 1;
        v1053[v1295] = v1050;
        ;
      } else {
        ;
      }
      int * v1058 = v987->mem;
      int v1300 = ((int)((unsigned int)((int)((unsigned int)v989 >> 2)) >> 1)) * 2;
      int v1059 = v1058[v1300];
      int * v1060 = v987->mem;
      int v1302 = (((int)((unsigned int)((int)((unsigned int)v989 >> 2)) >> 1)) * 2) + 1;
      int v1061 = v1060[v1302];
      int * v1062 = v987->cache_vals;
      int v1304 = ((4 + ((((int)((unsigned int)((int)((unsigned int)v989 >> 2)) >> 1)) & 3) * 2)) + ((((v1036 + ((~(((v1038 ^ -1) | (-(v1038 ^ -1))) >> 31)) & 2)) - (v1040 + ((~(((v1042 ^ -1) | (-(v1042 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
      v1062[v1304] = v1059;
      int * v1064 = v987->cache_vals;
      int v1307 = (((4 + ((((int)((unsigned int)((int)((unsigned int)v989 >> 2)) >> 1)) & 3) * 2)) + ((((v1036 + ((~(((v1038 ^ -1) | (-(v1038 ^ -1))) >> 31)) & 2)) - (v1040 + ((~(((v1042 ^ -1) | (-(v1042 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
      v1064[v1307] = v1061;
      int * v1066 = v987->cache_tags;
      int v1310 = (int)((unsigned int)((int)((unsigned int)v989 >> 2)) >> 1);
      v1066[v1284] = v1310;
      int * v1068 = v987->cache_dirty;
      v1068[v1284] = 0;
      int * v1070 = v987->cache_age;
      v1070[v1284] = 1;
      int * v1072 = v987->cache_age;
      int v1073 = v1072[v1284];
      int * v1074 = v987->cache_age;
      int v1075 = v1074[v1247];
      int * v1076 = v987->cache_age;
      int v1318 = v1075 + ((int)((unsigned int)(v1075 - v1073) >> 31));
      v1076[v1247] = v1318;
      int * v1078 = v987->cache_age;
      int v1079 = v1078[v1249];
      int * v1080 = v987->cache_age;
      int v1321 = v1079 + ((int)((unsigned int)(v1079 - v1073) >> 31));
      v1080[v1249] = v1321;
      int * v1082 = v987->cache_age;
      v1082[v1284] = 0;
      v1085 = v1284;
    }
    int * v1086 = v987->cache_vals;
    int v1324 = v1085 * 2;
    int v1087 = v1086[v1324];
    int * v1088 = v987->cache_vals;
    int v1326 = (v1085 * 2) + 1;
    int v1089 = v1088[v1326];
    int * v1090 = v987->cache_vals;
    int v1328 = (((((int)((unsigned int)((int)((unsigned int)v989 >> 2)) >> 1)) & 1) * 2) + ((((v1015 + ((~(((v1017 ^ -1) | (-(v1017 ^ -1))) >> 31)) & 2)) - (v1019 + ((~(((v1021 ^ -1) | (-(v1021 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
    v1090[v1328] = v1087;
    int * v1092 = v987->cache_vals;
    int v1331 = ((((((int)((unsigned int)((int)((unsigned int)v989 >> 2)) >> 1)) & 1) * 2) + ((((v1015 + ((~(((v1017 ^ -1) | (-(v1017 ^ -1))) >> 31)) & 2)) - (v1019 + ((~(((v1021 ^ -1) | (-(v1021 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
    v1092[v1331] = v1089;
    int * v1094 = v987->cache_tags;
    int v1334 = ((((int)((unsigned int)((int)((unsigned int)v989 >> 2)) >> 1)) & 1) * 2) + ((((v1015 + ((~(((v1017 ^ -1) | (-(v1017 ^ -1))) >> 31)) & 2)) - (v1019 + ((~(((v1021 ^ -1) | (-(v1021 ^ -1))) >> 31)) & 2))) >> 31) & 1);
    int v1335 = (int)((unsigned int)((int)((unsigned int)v989 >> 2)) >> 1);
    v1094[v1334] = v1335;
    int * v1096 = v987->cache_dirty;
    v1096[v1334] = 0;
    int * v1098 = v987->cache_age;
    v1098[v1334] = 1;
    int * v1100 = v987->cache_age;
    int v1101 = v1100[v1334];
    int * v1102 = v987->cache_age;
    int v1103 = v1102[v1243];
    int * v1104 = v987->cache_age;
    int v1343 = v1103 + ((int)((unsigned int)(v1103 - v1101) >> 31));
    v1104[v1243] = v1343;
    int * v1106 = v987->cache_age;
    int v1107 = v1106[v1245];
    int * v1108 = v987->cache_age;
    int v1346 = v1107 + ((int)((unsigned int)(v1107 - v1101) >> 31));
    v1108[v1245] = v1346;
    int * v1110 = v987->cache_age;
    v1110[v1334] = 0;
    v1113 = v1334;
  }
  int v1349 = (v1113 * 2) + (((int)((unsigned int)v989 >> 2)) & 1);
  int v1114 = v1000[v1349];
  int * v1115 = v987->regs;
  v1115[11] = v1114;
  struct StateT2 * v1117 = slot_9(v844);
  return v1117;
}

struct StateT2 * slot_4(struct StateT2 * v146) {
  struct StateT * v147 = v146->a;
  int v148 = v147->timer;
  struct StateT * v149 = v146->b;
  int v150 = v149->timer;
  bool v179 = v148 == v150;
  squared_assert(v179);
  squared_assume(v179);
  struct StateT * v153 = v146->a;
  int v154 = v153->timer;
  int v181 = v154 + 1;
  v153->timer = v181;
  struct StateT * v156 = v146->b;
  int v157 = v156->timer;
  int v183 = v157 + 1;
  v156->timer = v183;
  struct StateT * v159 = v146->a;
  int * v160 = v159->regs;
  int v161 = v160[14];
  int * v162 = v159->regs;
  int v163 = v162[15];
  struct StateT * v164 = v146->b;
  int * v165 = v164->regs;
  int v166 = v165[14];
  int * v167 = v164->regs;
  int v168 = v167[15];
  bool v192 = (v161 >= v163) == (v166 >= v168);
  squared_diverged(v192);
  squared_assume(v192);
  bool v193 = v161 >= v163;
  struct StateT2 * v175;
  if (v193) {
    struct StateT2 * v171 = slot_14(v146);
    v175 = v171;
  } else {
    struct StateT2 * v173 = slot_5(v146);
    v175 = v173;
  }
  return v175;
}

struct StateT2 * slot_13(struct StateT2 * v1486) {
  struct StateT * v1487 = v1486->a;
  int v1488 = v1487->timer;
  struct StateT * v1489 = v1486->b;
  int v1490 = v1489->timer;
  bool v1504 = v1488 == v1490;
  squared_assert(v1504);
  squared_assume(v1504);
  struct StateT * v1493 = v1486->a;
  int v1494 = v1493->timer;
  int v1506 = v1494 + 1;
  v1493->timer = v1506;
  struct StateT * v1496 = v1486->b;
  int v1497 = v1496->timer;
  int v1508 = v1497 + 1;
  v1496->timer = v1508;
  struct StateT * v1499 = v1486->a;
  struct StateT * v1500 = v1486->b;
  return v1486;
}

struct StateT2 * slot_9(struct StateT2 * v1354) {
  struct StateT * v1355 = v1354->a;
  int v1356 = v1355->timer;
  struct StateT * v1357 = v1354->b;
  int v1358 = v1357->timer;
  bool v1387 = v1356 == v1358;
  squared_assert(v1387);
  squared_assume(v1387);
  struct StateT * v1361 = v1354->a;
  int v1362 = v1361->timer;
  int v1389 = v1362 + 1;
  v1361->timer = v1389;
  struct StateT * v1364 = v1354->b;
  int v1365 = v1364->timer;
  int v1391 = v1365 + 1;
  v1364->timer = v1391;
  struct StateT * v1367 = v1354->a;
  int * v1368 = v1367->regs;
  int v1369 = v1368[10];
  int * v1370 = v1367->regs;
  int v1371 = v1370[11];
  struct StateT * v1372 = v1354->b;
  int * v1373 = v1372->regs;
  int v1374 = v1373[10];
  int * v1375 = v1372->regs;
  int v1376 = v1375[11];
  bool v1400 = (!(v1369 == v1371)) == (!(v1374 == v1376));
  squared_diverged(v1400);
  squared_assume(v1400);
  bool v1401 = !(v1369 == v1371);
  struct StateT2 * v1383;
  if (v1401) {
    struct StateT2 * v1379 = slot_12(v1354);
    v1383 = v1379;
  } else {
    struct StateT2 * v1381 = slot_10(v1354);
    v1383 = v1381;
  }
  return v1383;
}

struct StateT2 * slot_11(struct StateT2 * v1509) {
  struct StateT * v1510 = v1509->a;
  int v1511 = v1510->timer;
  struct StateT * v1512 = v1509->b;
  int v1513 = v1512->timer;
  bool v1528 = v1511 == v1513;
  squared_assert(v1528);
  squared_assume(v1528);
  struct StateT * v1516 = v1509->a;
  int v1517 = v1516->timer;
  int v1530 = v1517 + 1;
  v1516->timer = v1530;
  struct StateT * v1519 = v1509->b;
  int v1520 = v1519->timer;
  int v1532 = v1520 + 1;
  v1519->timer = v1532;
  struct StateT * v1522 = v1509->a;
  struct StateT * v1523 = v1509->b;
  struct StateT2 * v1524 = slot_4(v1509);
  return v1524;
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