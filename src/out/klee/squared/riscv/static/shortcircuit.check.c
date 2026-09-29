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

struct StateT2 * slot_14(struct StateT2 * v1595);
struct StateT2 * slot_6(struct StateT2 * v239);
struct StateT2 * slot_16(struct StateT2 * v1699);
struct StateT2 * slot_5(struct StateT2 * v170);
struct StateT2 * slot_17(struct StateT2 * v1725);
struct StateT2 * slot_2(struct StateT2 * v74);
struct StateT2 * slot_7(struct StateT2 * v767);
struct StateT2 * slot_3(struct StateT2 * v110);
struct StateT2 * snippet(struct StateT2 * v0);
struct StateT2 * slot_10(struct StateT2 * v1477);
struct StateT2 * slot_1(struct StateT2 * v38);
struct StateT2 * slot_8(struct StateT2 * v836);
struct StateT2 * slot_4(struct StateT2 * v146);
struct StateT2 * slot_13(struct StateT2 * v1534);
struct StateT2 * slot_15(struct StateT2 * v1663);
struct StateT2 * slot_9(struct StateT2 * v1364);
struct StateT2 * slot_11(struct StateT2 * v1510);
struct StateT2 * slot_0(struct StateT2 * v2);
struct StateT2 * slot_14(struct StateT2 * v1595) {
  struct StateT * v1596 = v1595->a;
  int v1597 = v1596->timer;
  struct StateT * v1598 = v1595->b;
  int v1599 = v1598->timer;
  bool v1636 = v1597 == v1599;
  squared_assert(v1636);
  squared_assume(v1636);
  struct StateT * v1602 = v1595->a;
  int * v1603 = v1602->regs;
  int v1604 = v1603[10];
  int * v1605 = v1602->regs;
  int v1606 = v1605[11];
  struct StateT * v1607 = v1595->b;
  int * v1608 = v1607->regs;
  int v1609 = v1608[10];
  int * v1610 = v1607->regs;
  int v1611 = v1610[11];
  bool v1645 = (!(v1604 == v1606)) == (!(v1609 == v1611));
  squared_diverged(v1645);
  squared_assume(v1645);
  bool v1646 = !(v1604 == v1606);
  struct StateT2 * v1632;
  if (v1646) {
    struct StateT * v1614 = v1595->a;
    int v1615 = v1614->timer;
    int v1648 = v1615 + 15;
    v1614->timer = v1648;
    int * v1617 = v1614->saved_regs;
    int v1618 = v1617[14];
    int * v1619 = v1614->regs;
    v1619[14] = v1618;
    struct StateT * v1621 = v1595->b;
    int v1622 = v1621->timer;
    int v1654 = v1622 + 15;
    v1621->timer = v1654;
    int * v1624 = v1621->saved_regs;
    int v1625 = v1624[14];
    int * v1626 = v1621->regs;
    v1626[14] = v1625;
    struct StateT2 * v1628 = slot_15(v1595);
    v1632 = v1628;
  } else {
    struct StateT2 * v1630 = slot_16(v1595);
    v1632 = v1630;
  }
  return v1632;
}

struct StateT2 * slot_6(struct StateT2 * v239) {
  struct StateT * v240 = v239->a;
  int v241 = v240->timer;
  struct StateT * v242 = v239->b;
  int v243 = v242->timer;
  bool v526 = v241 == v243;
  squared_assert(v526);
  squared_assume(v526);
  struct StateT * v246 = v239->a;
  int * v247 = v246->saved_regs;
  int * v248 = v246->regs;
  int v249 = v248[10];
  v247[10] = v249;
  struct StateT * v251 = v239->b;
  int * v252 = v251->saved_regs;
  int * v253 = v251->regs;
  int v254 = v253[10];
  v252[10] = v254;
  struct StateT * v256 = v239->a;
  int v257 = v256->timer;
  int v537 = v257 + 1;
  v256->timer = v537;
  struct StateT * v259 = v239->b;
  int v260 = v259->timer;
  int v539 = v260 + 1;
  v259->timer = v539;
  struct StateT * v262 = v239->a;
  int * v263 = v262->regs;
  int v264 = v263[5];
  int * v265 = v262->cache_tags;
  int v544 = (((int)((unsigned int)((int)((unsigned int)v264 >> 2)) >> 1)) & 1) * 2;
  int v266 = v265[v544];
  int * v267 = v262->cache_tags;
  int v546 = ((((int)((unsigned int)((int)((unsigned int)v264 >> 2)) >> 1)) & 1) * 2) + 1;
  int v268 = v267[v546];
  int * v269 = v262->cache_tags;
  int v548 = 4 + ((((int)((unsigned int)((int)((unsigned int)v264 >> 2)) >> 1)) & 3) * 2);
  int v270 = v269[v548];
  int * v271 = v262->cache_tags;
  int v550 = (4 + ((((int)((unsigned int)((int)((unsigned int)v264 >> 2)) >> 1)) & 3) * 2)) + 1;
  int v272 = v271[v550];
  int v273 = v262->timer;
  int v551 = v273 + ((100 ^ (((~(((v270 ^ ((int)((unsigned int)((int)((unsigned int)v264 >> 2)) >> 1))) | (-(v270 ^ ((int)((unsigned int)((int)((unsigned int)v264 >> 2)) >> 1))))) >> 31)) | (~(((v272 ^ ((int)((unsigned int)((int)((unsigned int)v264 >> 2)) >> 1))) | (-(v272 ^ ((int)((unsigned int)((int)((unsigned int)v264 >> 2)) >> 1))))) >> 31))) & 104)) ^ (((~(((v266 ^ ((int)((unsigned int)((int)((unsigned int)v264 >> 2)) >> 1))) | (-(v266 ^ ((int)((unsigned int)((int)((unsigned int)v264 >> 2)) >> 1))))) >> 31)) | (~(((v268 ^ ((int)((unsigned int)((int)((unsigned int)v264 >> 2)) >> 1))) | (-(v268 ^ ((int)((unsigned int)((int)((unsigned int)v264 >> 2)) >> 1))))) >> 31))) & (1 ^ (100 ^ (((~(((v270 ^ ((int)((unsigned int)((int)((unsigned int)v264 >> 2)) >> 1))) | (-(v270 ^ ((int)((unsigned int)((int)((unsigned int)v264 >> 2)) >> 1))))) >> 31)) | (~(((v272 ^ ((int)((unsigned int)((int)((unsigned int)v264 >> 2)) >> 1))) | (-(v272 ^ ((int)((unsigned int)((int)((unsigned int)v264 >> 2)) >> 1))))) >> 31))) & 104)))));
  v262->timer = v551;
  int * v275 = v262->cache_vals;
  bool v552 = !(((~(((v266 ^ ((int)((unsigned int)((int)((unsigned int)v264 >> 2)) >> 1))) | (-(v266 ^ ((int)((unsigned int)((int)((unsigned int)v264 >> 2)) >> 1))))) >> 31)) | (~(((v268 ^ ((int)((unsigned int)((int)((unsigned int)v264 >> 2)) >> 1))) | (-(v268 ^ ((int)((unsigned int)((int)((unsigned int)v264 >> 2)) >> 1))))) >> 31))) == 0);
  int v388;
  if (v552) {
    int * v276 = v262->cache_age;
    int v554 = ((((int)((unsigned int)((int)((unsigned int)v264 >> 2)) >> 1)) & 1) * 2) + ((~(((v268 ^ ((int)((unsigned int)((int)((unsigned int)v264 >> 2)) >> 1))) | (-(v268 ^ ((int)((unsigned int)((int)((unsigned int)v264 >> 2)) >> 1))))) >> 31)) & 1);
    int v277 = v276[v554];
    int * v278 = v262->cache_age;
    int v279 = v278[v544];
    int * v280 = v262->cache_age;
    int v557 = v279 + ((int)((unsigned int)(v279 - v277) >> 31));
    v280[v544] = v557;
    int * v282 = v262->cache_age;
    int v283 = v282[v546];
    int * v284 = v262->cache_age;
    int v560 = v283 + ((int)((unsigned int)(v283 - v277) >> 31));
    v284[v546] = v560;
    int * v286 = v262->cache_age;
    v286[v554] = 0;
    v388 = v554;
  } else {
    int * v289 = v262->cache_age;
    int v564 = (((int)((unsigned int)((int)((unsigned int)v264 >> 2)) >> 1)) & 1) * 2;
    int v290 = v289[v564];
    int * v291 = v262->cache_tags;
    int v292 = v291[v564];
    int * v293 = v262->cache_age;
    int v294 = v293[v546];
    int * v295 = v262->cache_tags;
    int v296 = v295[v546];
    bool v568 = !(((~(((v270 ^ ((int)((unsigned int)((int)((unsigned int)v264 >> 2)) >> 1))) | (-(v270 ^ ((int)((unsigned int)((int)((unsigned int)v264 >> 2)) >> 1))))) >> 31)) | (~(((v272 ^ ((int)((unsigned int)((int)((unsigned int)v264 >> 2)) >> 1))) | (-(v272 ^ ((int)((unsigned int)((int)((unsigned int)v264 >> 2)) >> 1))))) >> 31))) == 0);
    int v360;
    if (v568) {
      int * v297 = v262->cache_age;
      int v570 = (4 + ((((int)((unsigned int)((int)((unsigned int)v264 >> 2)) >> 1)) & 3) * 2)) + ((~(((v272 ^ ((int)((unsigned int)((int)((unsigned int)v264 >> 2)) >> 1))) | (-(v272 ^ ((int)((unsigned int)((int)((unsigned int)v264 >> 2)) >> 1))))) >> 31)) & 1);
      int v298 = v297[v570];
      int * v299 = v262->cache_age;
      int v300 = v299[v548];
      int * v301 = v262->cache_age;
      int v573 = v300 + ((int)((unsigned int)(v300 - v298) >> 31));
      v301[v548] = v573;
      int * v303 = v262->cache_age;
      int v304 = v303[v550];
      int * v305 = v262->cache_age;
      int v576 = v304 + ((int)((unsigned int)(v304 - v298) >> 31));
      v305[v550] = v576;
      int * v307 = v262->cache_age;
      v307[v570] = 0;
      v360 = v570;
    } else {
      int * v310 = v262->cache_age;
      int v580 = 4 + ((((int)((unsigned int)((int)((unsigned int)v264 >> 2)) >> 1)) & 3) * 2);
      int v311 = v310[v580];
      int * v312 = v262->cache_tags;
      int v313 = v312[v580];
      int * v314 = v262->cache_age;
      int v315 = v314[v550];
      int * v316 = v262->cache_tags;
      int v317 = v316[v550];
      int * v318 = v262->cache_dirty;
      int v585 = (4 + ((((int)((unsigned int)((int)((unsigned int)v264 >> 2)) >> 1)) & 3) * 2)) + ((((v311 + ((~(((v313 ^ -1) | (-(v313 ^ -1))) >> 31)) & 2)) - (v315 + ((~(((v317 ^ -1) | (-(v317 ^ -1))) >> 31)) & 2))) >> 31) & 1);
      int v319 = v318[v585];
      bool v586 = !(v319 == 0);
      if (v586) {
        int * v320 = v262->cache_tags;
        int v321 = v320[v585];
        int * v322 = v262->cache_vals;
        int v589 = ((4 + ((((int)((unsigned int)((int)((unsigned int)v264 >> 2)) >> 1)) & 3) * 2)) + ((((v311 + ((~(((v313 ^ -1) | (-(v313 ^ -1))) >> 31)) & 2)) - (v315 + ((~(((v317 ^ -1) | (-(v317 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
        int v323 = v322[v589];
        int * v324 = v262->cache_vals;
        int v591 = (((4 + ((((int)((unsigned int)((int)((unsigned int)v264 >> 2)) >> 1)) & 3) * 2)) + ((((v311 + ((~(((v313 ^ -1) | (-(v313 ^ -1))) >> 31)) & 2)) - (v315 + ((~(((v317 ^ -1) | (-(v317 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
        int v325 = v324[v591];
        int * v326 = v262->mem;
        int v593 = v321 * 2;
        v326[v593] = v323;
        int * v328 = v262->mem;
        int v596 = (v321 * 2) + 1;
        v328[v596] = v325;
        ;
      } else {
        ;
      }
      int * v333 = v262->mem;
      int v601 = ((int)((unsigned int)((int)((unsigned int)v264 >> 2)) >> 1)) * 2;
      int v334 = v333[v601];
      int * v335 = v262->mem;
      int v603 = (((int)((unsigned int)((int)((unsigned int)v264 >> 2)) >> 1)) * 2) + 1;
      int v336 = v335[v603];
      int * v337 = v262->cache_vals;
      int v605 = ((4 + ((((int)((unsigned int)((int)((unsigned int)v264 >> 2)) >> 1)) & 3) * 2)) + ((((v311 + ((~(((v313 ^ -1) | (-(v313 ^ -1))) >> 31)) & 2)) - (v315 + ((~(((v317 ^ -1) | (-(v317 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
      v337[v605] = v334;
      int * v339 = v262->cache_vals;
      int v608 = (((4 + ((((int)((unsigned int)((int)((unsigned int)v264 >> 2)) >> 1)) & 3) * 2)) + ((((v311 + ((~(((v313 ^ -1) | (-(v313 ^ -1))) >> 31)) & 2)) - (v315 + ((~(((v317 ^ -1) | (-(v317 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
      v339[v608] = v336;
      int * v341 = v262->cache_tags;
      int v611 = (int)((unsigned int)((int)((unsigned int)v264 >> 2)) >> 1);
      v341[v585] = v611;
      int * v343 = v262->cache_dirty;
      v343[v585] = 0;
      int * v345 = v262->cache_age;
      v345[v585] = 1;
      int * v347 = v262->cache_age;
      int v348 = v347[v585];
      int * v349 = v262->cache_age;
      int v350 = v349[v548];
      int * v351 = v262->cache_age;
      int v619 = v350 + ((int)((unsigned int)(v350 - v348) >> 31));
      v351[v548] = v619;
      int * v353 = v262->cache_age;
      int v354 = v353[v550];
      int * v355 = v262->cache_age;
      int v622 = v354 + ((int)((unsigned int)(v354 - v348) >> 31));
      v355[v550] = v622;
      int * v357 = v262->cache_age;
      v357[v585] = 0;
      v360 = v585;
    }
    int * v361 = v262->cache_vals;
    int v625 = v360 * 2;
    int v362 = v361[v625];
    int * v363 = v262->cache_vals;
    int v627 = (v360 * 2) + 1;
    int v364 = v363[v627];
    int * v365 = v262->cache_vals;
    int v629 = (((((int)((unsigned int)((int)((unsigned int)v264 >> 2)) >> 1)) & 1) * 2) + ((((v290 + ((~(((v292 ^ -1) | (-(v292 ^ -1))) >> 31)) & 2)) - (v294 + ((~(((v296 ^ -1) | (-(v296 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
    v365[v629] = v362;
    int * v367 = v262->cache_vals;
    int v632 = ((((((int)((unsigned int)((int)((unsigned int)v264 >> 2)) >> 1)) & 1) * 2) + ((((v290 + ((~(((v292 ^ -1) | (-(v292 ^ -1))) >> 31)) & 2)) - (v294 + ((~(((v296 ^ -1) | (-(v296 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
    v367[v632] = v364;
    int * v369 = v262->cache_tags;
    int v635 = ((((int)((unsigned int)((int)((unsigned int)v264 >> 2)) >> 1)) & 1) * 2) + ((((v290 + ((~(((v292 ^ -1) | (-(v292 ^ -1))) >> 31)) & 2)) - (v294 + ((~(((v296 ^ -1) | (-(v296 ^ -1))) >> 31)) & 2))) >> 31) & 1);
    int v636 = (int)((unsigned int)((int)((unsigned int)v264 >> 2)) >> 1);
    v369[v635] = v636;
    int * v371 = v262->cache_dirty;
    v371[v635] = 0;
    int * v373 = v262->cache_age;
    v373[v635] = 1;
    int * v375 = v262->cache_age;
    int v376 = v375[v635];
    int * v377 = v262->cache_age;
    int v378 = v377[v544];
    int * v379 = v262->cache_age;
    int v644 = v378 + ((int)((unsigned int)(v378 - v376) >> 31));
    v379[v544] = v644;
    int * v381 = v262->cache_age;
    int v382 = v381[v546];
    int * v383 = v262->cache_age;
    int v647 = v382 + ((int)((unsigned int)(v382 - v376) >> 31));
    v383[v546] = v647;
    int * v385 = v262->cache_age;
    v385[v635] = 0;
    v388 = v635;
  }
  int v650 = (v388 * 2) + (((int)((unsigned int)v264 >> 2)) & 1);
  int v389 = v275[v650];
  int * v390 = v262->regs;
  v390[10] = v389;
  struct StateT * v392 = v239->b;
  int * v393 = v392->regs;
  int v394 = v393[5];
  int * v395 = v392->cache_tags;
  int v656 = (((int)((unsigned int)((int)((unsigned int)v394 >> 2)) >> 1)) & 1) * 2;
  int v396 = v395[v656];
  int * v397 = v392->cache_tags;
  int v658 = ((((int)((unsigned int)((int)((unsigned int)v394 >> 2)) >> 1)) & 1) * 2) + 1;
  int v398 = v397[v658];
  int * v399 = v392->cache_tags;
  int v660 = 4 + ((((int)((unsigned int)((int)((unsigned int)v394 >> 2)) >> 1)) & 3) * 2);
  int v400 = v399[v660];
  int * v401 = v392->cache_tags;
  int v662 = (4 + ((((int)((unsigned int)((int)((unsigned int)v394 >> 2)) >> 1)) & 3) * 2)) + 1;
  int v402 = v401[v662];
  int v403 = v392->timer;
  int v663 = v403 + ((100 ^ (((~(((v400 ^ ((int)((unsigned int)((int)((unsigned int)v394 >> 2)) >> 1))) | (-(v400 ^ ((int)((unsigned int)((int)((unsigned int)v394 >> 2)) >> 1))))) >> 31)) | (~(((v402 ^ ((int)((unsigned int)((int)((unsigned int)v394 >> 2)) >> 1))) | (-(v402 ^ ((int)((unsigned int)((int)((unsigned int)v394 >> 2)) >> 1))))) >> 31))) & 104)) ^ (((~(((v396 ^ ((int)((unsigned int)((int)((unsigned int)v394 >> 2)) >> 1))) | (-(v396 ^ ((int)((unsigned int)((int)((unsigned int)v394 >> 2)) >> 1))))) >> 31)) | (~(((v398 ^ ((int)((unsigned int)((int)((unsigned int)v394 >> 2)) >> 1))) | (-(v398 ^ ((int)((unsigned int)((int)((unsigned int)v394 >> 2)) >> 1))))) >> 31))) & (1 ^ (100 ^ (((~(((v400 ^ ((int)((unsigned int)((int)((unsigned int)v394 >> 2)) >> 1))) | (-(v400 ^ ((int)((unsigned int)((int)((unsigned int)v394 >> 2)) >> 1))))) >> 31)) | (~(((v402 ^ ((int)((unsigned int)((int)((unsigned int)v394 >> 2)) >> 1))) | (-(v402 ^ ((int)((unsigned int)((int)((unsigned int)v394 >> 2)) >> 1))))) >> 31))) & 104)))));
  v392->timer = v663;
  int * v405 = v392->cache_vals;
  bool v664 = !(((~(((v396 ^ ((int)((unsigned int)((int)((unsigned int)v394 >> 2)) >> 1))) | (-(v396 ^ ((int)((unsigned int)((int)((unsigned int)v394 >> 2)) >> 1))))) >> 31)) | (~(((v398 ^ ((int)((unsigned int)((int)((unsigned int)v394 >> 2)) >> 1))) | (-(v398 ^ ((int)((unsigned int)((int)((unsigned int)v394 >> 2)) >> 1))))) >> 31))) == 0);
  int v518;
  if (v664) {
    int * v406 = v392->cache_age;
    int v666 = ((((int)((unsigned int)((int)((unsigned int)v394 >> 2)) >> 1)) & 1) * 2) + ((~(((v398 ^ ((int)((unsigned int)((int)((unsigned int)v394 >> 2)) >> 1))) | (-(v398 ^ ((int)((unsigned int)((int)((unsigned int)v394 >> 2)) >> 1))))) >> 31)) & 1);
    int v407 = v406[v666];
    int * v408 = v392->cache_age;
    int v409 = v408[v656];
    int * v410 = v392->cache_age;
    int v669 = v409 + ((int)((unsigned int)(v409 - v407) >> 31));
    v410[v656] = v669;
    int * v412 = v392->cache_age;
    int v413 = v412[v658];
    int * v414 = v392->cache_age;
    int v672 = v413 + ((int)((unsigned int)(v413 - v407) >> 31));
    v414[v658] = v672;
    int * v416 = v392->cache_age;
    v416[v666] = 0;
    v518 = v666;
  } else {
    int * v419 = v392->cache_age;
    int v676 = (((int)((unsigned int)((int)((unsigned int)v394 >> 2)) >> 1)) & 1) * 2;
    int v420 = v419[v676];
    int * v421 = v392->cache_tags;
    int v422 = v421[v676];
    int * v423 = v392->cache_age;
    int v424 = v423[v658];
    int * v425 = v392->cache_tags;
    int v426 = v425[v658];
    bool v680 = !(((~(((v400 ^ ((int)((unsigned int)((int)((unsigned int)v394 >> 2)) >> 1))) | (-(v400 ^ ((int)((unsigned int)((int)((unsigned int)v394 >> 2)) >> 1))))) >> 31)) | (~(((v402 ^ ((int)((unsigned int)((int)((unsigned int)v394 >> 2)) >> 1))) | (-(v402 ^ ((int)((unsigned int)((int)((unsigned int)v394 >> 2)) >> 1))))) >> 31))) == 0);
    int v490;
    if (v680) {
      int * v427 = v392->cache_age;
      int v682 = (4 + ((((int)((unsigned int)((int)((unsigned int)v394 >> 2)) >> 1)) & 3) * 2)) + ((~(((v402 ^ ((int)((unsigned int)((int)((unsigned int)v394 >> 2)) >> 1))) | (-(v402 ^ ((int)((unsigned int)((int)((unsigned int)v394 >> 2)) >> 1))))) >> 31)) & 1);
      int v428 = v427[v682];
      int * v429 = v392->cache_age;
      int v430 = v429[v660];
      int * v431 = v392->cache_age;
      int v685 = v430 + ((int)((unsigned int)(v430 - v428) >> 31));
      v431[v660] = v685;
      int * v433 = v392->cache_age;
      int v434 = v433[v662];
      int * v435 = v392->cache_age;
      int v688 = v434 + ((int)((unsigned int)(v434 - v428) >> 31));
      v435[v662] = v688;
      int * v437 = v392->cache_age;
      v437[v682] = 0;
      v490 = v682;
    } else {
      int * v440 = v392->cache_age;
      int v692 = 4 + ((((int)((unsigned int)((int)((unsigned int)v394 >> 2)) >> 1)) & 3) * 2);
      int v441 = v440[v692];
      int * v442 = v392->cache_tags;
      int v443 = v442[v692];
      int * v444 = v392->cache_age;
      int v445 = v444[v662];
      int * v446 = v392->cache_tags;
      int v447 = v446[v662];
      int * v448 = v392->cache_dirty;
      int v697 = (4 + ((((int)((unsigned int)((int)((unsigned int)v394 >> 2)) >> 1)) & 3) * 2)) + ((((v441 + ((~(((v443 ^ -1) | (-(v443 ^ -1))) >> 31)) & 2)) - (v445 + ((~(((v447 ^ -1) | (-(v447 ^ -1))) >> 31)) & 2))) >> 31) & 1);
      int v449 = v448[v697];
      bool v698 = !(v449 == 0);
      if (v698) {
        int * v450 = v392->cache_tags;
        int v451 = v450[v697];
        int * v452 = v392->cache_vals;
        int v701 = ((4 + ((((int)((unsigned int)((int)((unsigned int)v394 >> 2)) >> 1)) & 3) * 2)) + ((((v441 + ((~(((v443 ^ -1) | (-(v443 ^ -1))) >> 31)) & 2)) - (v445 + ((~(((v447 ^ -1) | (-(v447 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
        int v453 = v452[v701];
        int * v454 = v392->cache_vals;
        int v703 = (((4 + ((((int)((unsigned int)((int)((unsigned int)v394 >> 2)) >> 1)) & 3) * 2)) + ((((v441 + ((~(((v443 ^ -1) | (-(v443 ^ -1))) >> 31)) & 2)) - (v445 + ((~(((v447 ^ -1) | (-(v447 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
        int v455 = v454[v703];
        int * v456 = v392->mem;
        int v705 = v451 * 2;
        v456[v705] = v453;
        int * v458 = v392->mem;
        int v708 = (v451 * 2) + 1;
        v458[v708] = v455;
        ;
      } else {
        ;
      }
      int * v463 = v392->mem;
      int v713 = ((int)((unsigned int)((int)((unsigned int)v394 >> 2)) >> 1)) * 2;
      int v464 = v463[v713];
      int * v465 = v392->mem;
      int v715 = (((int)((unsigned int)((int)((unsigned int)v394 >> 2)) >> 1)) * 2) + 1;
      int v466 = v465[v715];
      int * v467 = v392->cache_vals;
      int v717 = ((4 + ((((int)((unsigned int)((int)((unsigned int)v394 >> 2)) >> 1)) & 3) * 2)) + ((((v441 + ((~(((v443 ^ -1) | (-(v443 ^ -1))) >> 31)) & 2)) - (v445 + ((~(((v447 ^ -1) | (-(v447 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
      v467[v717] = v464;
      int * v469 = v392->cache_vals;
      int v720 = (((4 + ((((int)((unsigned int)((int)((unsigned int)v394 >> 2)) >> 1)) & 3) * 2)) + ((((v441 + ((~(((v443 ^ -1) | (-(v443 ^ -1))) >> 31)) & 2)) - (v445 + ((~(((v447 ^ -1) | (-(v447 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
      v469[v720] = v466;
      int * v471 = v392->cache_tags;
      int v723 = (int)((unsigned int)((int)((unsigned int)v394 >> 2)) >> 1);
      v471[v697] = v723;
      int * v473 = v392->cache_dirty;
      v473[v697] = 0;
      int * v475 = v392->cache_age;
      v475[v697] = 1;
      int * v477 = v392->cache_age;
      int v478 = v477[v697];
      int * v479 = v392->cache_age;
      int v480 = v479[v660];
      int * v481 = v392->cache_age;
      int v731 = v480 + ((int)((unsigned int)(v480 - v478) >> 31));
      v481[v660] = v731;
      int * v483 = v392->cache_age;
      int v484 = v483[v662];
      int * v485 = v392->cache_age;
      int v734 = v484 + ((int)((unsigned int)(v484 - v478) >> 31));
      v485[v662] = v734;
      int * v487 = v392->cache_age;
      v487[v697] = 0;
      v490 = v697;
    }
    int * v491 = v392->cache_vals;
    int v737 = v490 * 2;
    int v492 = v491[v737];
    int * v493 = v392->cache_vals;
    int v739 = (v490 * 2) + 1;
    int v494 = v493[v739];
    int * v495 = v392->cache_vals;
    int v741 = (((((int)((unsigned int)((int)((unsigned int)v394 >> 2)) >> 1)) & 1) * 2) + ((((v420 + ((~(((v422 ^ -1) | (-(v422 ^ -1))) >> 31)) & 2)) - (v424 + ((~(((v426 ^ -1) | (-(v426 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
    v495[v741] = v492;
    int * v497 = v392->cache_vals;
    int v744 = ((((((int)((unsigned int)((int)((unsigned int)v394 >> 2)) >> 1)) & 1) * 2) + ((((v420 + ((~(((v422 ^ -1) | (-(v422 ^ -1))) >> 31)) & 2)) - (v424 + ((~(((v426 ^ -1) | (-(v426 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
    v497[v744] = v494;
    int * v499 = v392->cache_tags;
    int v747 = ((((int)((unsigned int)((int)((unsigned int)v394 >> 2)) >> 1)) & 1) * 2) + ((((v420 + ((~(((v422 ^ -1) | (-(v422 ^ -1))) >> 31)) & 2)) - (v424 + ((~(((v426 ^ -1) | (-(v426 ^ -1))) >> 31)) & 2))) >> 31) & 1);
    int v748 = (int)((unsigned int)((int)((unsigned int)v394 >> 2)) >> 1);
    v499[v747] = v748;
    int * v501 = v392->cache_dirty;
    v501[v747] = 0;
    int * v503 = v392->cache_age;
    v503[v747] = 1;
    int * v505 = v392->cache_age;
    int v506 = v505[v747];
    int * v507 = v392->cache_age;
    int v508 = v507[v656];
    int * v509 = v392->cache_age;
    int v756 = v508 + ((int)((unsigned int)(v508 - v506) >> 31));
    v509[v656] = v756;
    int * v511 = v392->cache_age;
    int v512 = v511[v658];
    int * v513 = v392->cache_age;
    int v759 = v512 + ((int)((unsigned int)(v512 - v506) >> 31));
    v513[v658] = v759;
    int * v515 = v392->cache_age;
    v515[v747] = 0;
    v518 = v747;
  }
  int v762 = (v518 * 2) + (((int)((unsigned int)v394 >> 2)) & 1);
  int v519 = v405[v762];
  int * v520 = v392->regs;
  v520[10] = v519;
  struct StateT2 * v522 = slot_7(v239);
  return v522;
}

struct StateT2 * slot_16(struct StateT2 * v1699) {
  struct StateT * v1700 = v1699->a;
  int v1701 = v1700->timer;
  struct StateT * v1702 = v1699->b;
  int v1703 = v1702->timer;
  bool v1718 = v1701 == v1703;
  squared_assert(v1718);
  squared_assume(v1718);
  struct StateT * v1706 = v1699->a;
  int v1707 = v1706->timer;
  int v1720 = v1707 + 1;
  v1706->timer = v1720;
  struct StateT * v1709 = v1699->b;
  int v1710 = v1709->timer;
  int v1722 = v1710 + 1;
  v1709->timer = v1722;
  struct StateT * v1712 = v1699->a;
  struct StateT * v1713 = v1699->b;
  struct StateT2 * v1714 = slot_4(v1699);
  return v1714;
}

struct StateT2 * slot_5(struct StateT2 * v170) {
  struct StateT * v171 = v170->a;
  int v172 = v171->timer;
  struct StateT * v173 = v170->b;
  int v174 = v173->timer;
  bool v211 = v172 == v174;
  squared_assert(v211);
  squared_assume(v211);
  struct StateT * v177 = v170->a;
  int * v178 = v177->saved_regs;
  int * v179 = v177->regs;
  int v180 = v179[5];
  v178[5] = v180;
  struct StateT * v182 = v170->b;
  int * v183 = v182->saved_regs;
  int * v184 = v182->regs;
  int v185 = v184[5];
  v183[5] = v185;
  struct StateT * v187 = v170->a;
  int v188 = v187->timer;
  int v222 = v188 + 1;
  v187->timer = v222;
  struct StateT * v190 = v170->b;
  int v191 = v190->timer;
  int v224 = v191 + 1;
  v190->timer = v224;
  struct StateT * v193 = v170->a;
  int * v194 = v193->regs;
  int v195 = v194[12];
  int * v196 = v193->regs;
  int v197 = v196[14];
  int * v198 = v193->regs;
  int v231 = v195 + v197;
  v198[5] = v231;
  struct StateT * v200 = v170->b;
  int * v201 = v200->regs;
  int v202 = v201[12];
  int * v203 = v200->regs;
  int v204 = v203[14];
  int * v205 = v200->regs;
  int v236 = v202 + v204;
  v205[5] = v236;
  struct StateT2 * v207 = slot_6(v170);
  return v207;
}

struct StateT2 * slot_17(struct StateT2 * v1725) {
  struct StateT * v1726 = v1725->a;
  int v1727 = v1726->timer;
  struct StateT * v1728 = v1725->b;
  int v1729 = v1728->timer;
  bool v1743 = v1727 == v1729;
  squared_assert(v1743);
  squared_assume(v1743);
  struct StateT * v1732 = v1725->a;
  int v1733 = v1732->timer;
  int v1745 = v1733 + 1;
  v1732->timer = v1745;
  struct StateT * v1735 = v1725->b;
  int v1736 = v1735->timer;
  int v1747 = v1736 + 1;
  v1735->timer = v1747;
  struct StateT * v1738 = v1725->a;
  struct StateT * v1739 = v1725->b;
  return v1725;
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

struct StateT2 * slot_7(struct StateT2 * v767) {
  struct StateT * v768 = v767->a;
  int v769 = v768->timer;
  struct StateT * v770 = v767->b;
  int v771 = v770->timer;
  bool v808 = v769 == v771;
  squared_assert(v808);
  squared_assume(v808);
  struct StateT * v774 = v767->a;
  int * v775 = v774->saved_regs;
  int * v776 = v774->regs;
  int v777 = v776[6];
  v775[6] = v777;
  struct StateT * v779 = v767->b;
  int * v780 = v779->saved_regs;
  int * v781 = v779->regs;
  int v782 = v781[6];
  v780[6] = v782;
  struct StateT * v784 = v767->a;
  int v785 = v784->timer;
  int v819 = v785 + 1;
  v784->timer = v819;
  struct StateT * v787 = v767->b;
  int v788 = v787->timer;
  int v821 = v788 + 1;
  v787->timer = v821;
  struct StateT * v790 = v767->a;
  int * v791 = v790->regs;
  int v792 = v791[13];
  int * v793 = v790->regs;
  int v794 = v793[14];
  int * v795 = v790->regs;
  int v828 = v792 + v794;
  v795[6] = v828;
  struct StateT * v797 = v767->b;
  int * v798 = v797->regs;
  int v799 = v798[13];
  int * v800 = v797->regs;
  int v801 = v800[14];
  int * v802 = v797->regs;
  int v833 = v799 + v801;
  v802[6] = v833;
  struct StateT2 * v804 = slot_8(v767);
  return v804;
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

struct StateT2 * slot_10(struct StateT2 * v1477) {
  struct StateT * v1478 = v1477->a;
  int v1479 = v1478->timer;
  struct StateT * v1480 = v1477->b;
  int v1481 = v1480->timer;
  bool v1499 = v1479 == v1481;
  squared_assert(v1499);
  squared_assume(v1499);
  struct StateT * v1484 = v1477->a;
  int v1485 = v1484->timer;
  int v1501 = v1485 + 1;
  v1484->timer = v1501;
  struct StateT * v1487 = v1477->b;
  int v1488 = v1487->timer;
  int v1503 = v1488 + 1;
  v1487->timer = v1503;
  struct StateT * v1490 = v1477->a;
  int * v1491 = v1490->regs;
  v1491[10] = 1;
  struct StateT * v1493 = v1477->b;
  int * v1494 = v1493->regs;
  v1494[10] = 1;
  return v1477;
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

struct StateT2 * slot_8(struct StateT2 * v836) {
  struct StateT * v837 = v836->a;
  int v838 = v837->timer;
  struct StateT * v839 = v836->b;
  int v840 = v839->timer;
  bool v1123 = v838 == v840;
  squared_assert(v1123);
  squared_assume(v1123);
  struct StateT * v843 = v836->a;
  int * v844 = v843->saved_regs;
  int * v845 = v843->regs;
  int v846 = v845[11];
  v844[11] = v846;
  struct StateT * v848 = v836->b;
  int * v849 = v848->saved_regs;
  int * v850 = v848->regs;
  int v851 = v850[11];
  v849[11] = v851;
  struct StateT * v853 = v836->a;
  int v854 = v853->timer;
  int v1134 = v854 + 1;
  v853->timer = v1134;
  struct StateT * v856 = v836->b;
  int v857 = v856->timer;
  int v1136 = v857 + 1;
  v856->timer = v1136;
  struct StateT * v859 = v836->a;
  int * v860 = v859->regs;
  int v861 = v860[6];
  int * v862 = v859->cache_tags;
  int v1141 = (((int)((unsigned int)((int)((unsigned int)v861 >> 2)) >> 1)) & 1) * 2;
  int v863 = v862[v1141];
  int * v864 = v859->cache_tags;
  int v1143 = ((((int)((unsigned int)((int)((unsigned int)v861 >> 2)) >> 1)) & 1) * 2) + 1;
  int v865 = v864[v1143];
  int * v866 = v859->cache_tags;
  int v1145 = 4 + ((((int)((unsigned int)((int)((unsigned int)v861 >> 2)) >> 1)) & 3) * 2);
  int v867 = v866[v1145];
  int * v868 = v859->cache_tags;
  int v1147 = (4 + ((((int)((unsigned int)((int)((unsigned int)v861 >> 2)) >> 1)) & 3) * 2)) + 1;
  int v869 = v868[v1147];
  int v870 = v859->timer;
  int v1148 = v870 + ((100 ^ (((~(((v867 ^ ((int)((unsigned int)((int)((unsigned int)v861 >> 2)) >> 1))) | (-(v867 ^ ((int)((unsigned int)((int)((unsigned int)v861 >> 2)) >> 1))))) >> 31)) | (~(((v869 ^ ((int)((unsigned int)((int)((unsigned int)v861 >> 2)) >> 1))) | (-(v869 ^ ((int)((unsigned int)((int)((unsigned int)v861 >> 2)) >> 1))))) >> 31))) & 104)) ^ (((~(((v863 ^ ((int)((unsigned int)((int)((unsigned int)v861 >> 2)) >> 1))) | (-(v863 ^ ((int)((unsigned int)((int)((unsigned int)v861 >> 2)) >> 1))))) >> 31)) | (~(((v865 ^ ((int)((unsigned int)((int)((unsigned int)v861 >> 2)) >> 1))) | (-(v865 ^ ((int)((unsigned int)((int)((unsigned int)v861 >> 2)) >> 1))))) >> 31))) & (1 ^ (100 ^ (((~(((v867 ^ ((int)((unsigned int)((int)((unsigned int)v861 >> 2)) >> 1))) | (-(v867 ^ ((int)((unsigned int)((int)((unsigned int)v861 >> 2)) >> 1))))) >> 31)) | (~(((v869 ^ ((int)((unsigned int)((int)((unsigned int)v861 >> 2)) >> 1))) | (-(v869 ^ ((int)((unsigned int)((int)((unsigned int)v861 >> 2)) >> 1))))) >> 31))) & 104)))));
  v859->timer = v1148;
  int * v872 = v859->cache_vals;
  bool v1149 = !(((~(((v863 ^ ((int)((unsigned int)((int)((unsigned int)v861 >> 2)) >> 1))) | (-(v863 ^ ((int)((unsigned int)((int)((unsigned int)v861 >> 2)) >> 1))))) >> 31)) | (~(((v865 ^ ((int)((unsigned int)((int)((unsigned int)v861 >> 2)) >> 1))) | (-(v865 ^ ((int)((unsigned int)((int)((unsigned int)v861 >> 2)) >> 1))))) >> 31))) == 0);
  int v985;
  if (v1149) {
    int * v873 = v859->cache_age;
    int v1151 = ((((int)((unsigned int)((int)((unsigned int)v861 >> 2)) >> 1)) & 1) * 2) + ((~(((v865 ^ ((int)((unsigned int)((int)((unsigned int)v861 >> 2)) >> 1))) | (-(v865 ^ ((int)((unsigned int)((int)((unsigned int)v861 >> 2)) >> 1))))) >> 31)) & 1);
    int v874 = v873[v1151];
    int * v875 = v859->cache_age;
    int v876 = v875[v1141];
    int * v877 = v859->cache_age;
    int v1154 = v876 + ((int)((unsigned int)(v876 - v874) >> 31));
    v877[v1141] = v1154;
    int * v879 = v859->cache_age;
    int v880 = v879[v1143];
    int * v881 = v859->cache_age;
    int v1157 = v880 + ((int)((unsigned int)(v880 - v874) >> 31));
    v881[v1143] = v1157;
    int * v883 = v859->cache_age;
    v883[v1151] = 0;
    v985 = v1151;
  } else {
    int * v886 = v859->cache_age;
    int v1161 = (((int)((unsigned int)((int)((unsigned int)v861 >> 2)) >> 1)) & 1) * 2;
    int v887 = v886[v1161];
    int * v888 = v859->cache_tags;
    int v889 = v888[v1161];
    int * v890 = v859->cache_age;
    int v891 = v890[v1143];
    int * v892 = v859->cache_tags;
    int v893 = v892[v1143];
    bool v1165 = !(((~(((v867 ^ ((int)((unsigned int)((int)((unsigned int)v861 >> 2)) >> 1))) | (-(v867 ^ ((int)((unsigned int)((int)((unsigned int)v861 >> 2)) >> 1))))) >> 31)) | (~(((v869 ^ ((int)((unsigned int)((int)((unsigned int)v861 >> 2)) >> 1))) | (-(v869 ^ ((int)((unsigned int)((int)((unsigned int)v861 >> 2)) >> 1))))) >> 31))) == 0);
    int v957;
    if (v1165) {
      int * v894 = v859->cache_age;
      int v1167 = (4 + ((((int)((unsigned int)((int)((unsigned int)v861 >> 2)) >> 1)) & 3) * 2)) + ((~(((v869 ^ ((int)((unsigned int)((int)((unsigned int)v861 >> 2)) >> 1))) | (-(v869 ^ ((int)((unsigned int)((int)((unsigned int)v861 >> 2)) >> 1))))) >> 31)) & 1);
      int v895 = v894[v1167];
      int * v896 = v859->cache_age;
      int v897 = v896[v1145];
      int * v898 = v859->cache_age;
      int v1170 = v897 + ((int)((unsigned int)(v897 - v895) >> 31));
      v898[v1145] = v1170;
      int * v900 = v859->cache_age;
      int v901 = v900[v1147];
      int * v902 = v859->cache_age;
      int v1173 = v901 + ((int)((unsigned int)(v901 - v895) >> 31));
      v902[v1147] = v1173;
      int * v904 = v859->cache_age;
      v904[v1167] = 0;
      v957 = v1167;
    } else {
      int * v907 = v859->cache_age;
      int v1177 = 4 + ((((int)((unsigned int)((int)((unsigned int)v861 >> 2)) >> 1)) & 3) * 2);
      int v908 = v907[v1177];
      int * v909 = v859->cache_tags;
      int v910 = v909[v1177];
      int * v911 = v859->cache_age;
      int v912 = v911[v1147];
      int * v913 = v859->cache_tags;
      int v914 = v913[v1147];
      int * v915 = v859->cache_dirty;
      int v1182 = (4 + ((((int)((unsigned int)((int)((unsigned int)v861 >> 2)) >> 1)) & 3) * 2)) + ((((v908 + ((~(((v910 ^ -1) | (-(v910 ^ -1))) >> 31)) & 2)) - (v912 + ((~(((v914 ^ -1) | (-(v914 ^ -1))) >> 31)) & 2))) >> 31) & 1);
      int v916 = v915[v1182];
      bool v1183 = !(v916 == 0);
      if (v1183) {
        int * v917 = v859->cache_tags;
        int v918 = v917[v1182];
        int * v919 = v859->cache_vals;
        int v1186 = ((4 + ((((int)((unsigned int)((int)((unsigned int)v861 >> 2)) >> 1)) & 3) * 2)) + ((((v908 + ((~(((v910 ^ -1) | (-(v910 ^ -1))) >> 31)) & 2)) - (v912 + ((~(((v914 ^ -1) | (-(v914 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
        int v920 = v919[v1186];
        int * v921 = v859->cache_vals;
        int v1188 = (((4 + ((((int)((unsigned int)((int)((unsigned int)v861 >> 2)) >> 1)) & 3) * 2)) + ((((v908 + ((~(((v910 ^ -1) | (-(v910 ^ -1))) >> 31)) & 2)) - (v912 + ((~(((v914 ^ -1) | (-(v914 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
        int v922 = v921[v1188];
        int * v923 = v859->mem;
        int v1190 = v918 * 2;
        v923[v1190] = v920;
        int * v925 = v859->mem;
        int v1193 = (v918 * 2) + 1;
        v925[v1193] = v922;
        ;
      } else {
        ;
      }
      int * v930 = v859->mem;
      int v1198 = ((int)((unsigned int)((int)((unsigned int)v861 >> 2)) >> 1)) * 2;
      int v931 = v930[v1198];
      int * v932 = v859->mem;
      int v1200 = (((int)((unsigned int)((int)((unsigned int)v861 >> 2)) >> 1)) * 2) + 1;
      int v933 = v932[v1200];
      int * v934 = v859->cache_vals;
      int v1202 = ((4 + ((((int)((unsigned int)((int)((unsigned int)v861 >> 2)) >> 1)) & 3) * 2)) + ((((v908 + ((~(((v910 ^ -1) | (-(v910 ^ -1))) >> 31)) & 2)) - (v912 + ((~(((v914 ^ -1) | (-(v914 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
      v934[v1202] = v931;
      int * v936 = v859->cache_vals;
      int v1205 = (((4 + ((((int)((unsigned int)((int)((unsigned int)v861 >> 2)) >> 1)) & 3) * 2)) + ((((v908 + ((~(((v910 ^ -1) | (-(v910 ^ -1))) >> 31)) & 2)) - (v912 + ((~(((v914 ^ -1) | (-(v914 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
      v936[v1205] = v933;
      int * v938 = v859->cache_tags;
      int v1208 = (int)((unsigned int)((int)((unsigned int)v861 >> 2)) >> 1);
      v938[v1182] = v1208;
      int * v940 = v859->cache_dirty;
      v940[v1182] = 0;
      int * v942 = v859->cache_age;
      v942[v1182] = 1;
      int * v944 = v859->cache_age;
      int v945 = v944[v1182];
      int * v946 = v859->cache_age;
      int v947 = v946[v1145];
      int * v948 = v859->cache_age;
      int v1216 = v947 + ((int)((unsigned int)(v947 - v945) >> 31));
      v948[v1145] = v1216;
      int * v950 = v859->cache_age;
      int v951 = v950[v1147];
      int * v952 = v859->cache_age;
      int v1219 = v951 + ((int)((unsigned int)(v951 - v945) >> 31));
      v952[v1147] = v1219;
      int * v954 = v859->cache_age;
      v954[v1182] = 0;
      v957 = v1182;
    }
    int * v958 = v859->cache_vals;
    int v1222 = v957 * 2;
    int v959 = v958[v1222];
    int * v960 = v859->cache_vals;
    int v1224 = (v957 * 2) + 1;
    int v961 = v960[v1224];
    int * v962 = v859->cache_vals;
    int v1226 = (((((int)((unsigned int)((int)((unsigned int)v861 >> 2)) >> 1)) & 1) * 2) + ((((v887 + ((~(((v889 ^ -1) | (-(v889 ^ -1))) >> 31)) & 2)) - (v891 + ((~(((v893 ^ -1) | (-(v893 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
    v962[v1226] = v959;
    int * v964 = v859->cache_vals;
    int v1229 = ((((((int)((unsigned int)((int)((unsigned int)v861 >> 2)) >> 1)) & 1) * 2) + ((((v887 + ((~(((v889 ^ -1) | (-(v889 ^ -1))) >> 31)) & 2)) - (v891 + ((~(((v893 ^ -1) | (-(v893 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
    v964[v1229] = v961;
    int * v966 = v859->cache_tags;
    int v1232 = ((((int)((unsigned int)((int)((unsigned int)v861 >> 2)) >> 1)) & 1) * 2) + ((((v887 + ((~(((v889 ^ -1) | (-(v889 ^ -1))) >> 31)) & 2)) - (v891 + ((~(((v893 ^ -1) | (-(v893 ^ -1))) >> 31)) & 2))) >> 31) & 1);
    int v1233 = (int)((unsigned int)((int)((unsigned int)v861 >> 2)) >> 1);
    v966[v1232] = v1233;
    int * v968 = v859->cache_dirty;
    v968[v1232] = 0;
    int * v970 = v859->cache_age;
    v970[v1232] = 1;
    int * v972 = v859->cache_age;
    int v973 = v972[v1232];
    int * v974 = v859->cache_age;
    int v975 = v974[v1141];
    int * v976 = v859->cache_age;
    int v1241 = v975 + ((int)((unsigned int)(v975 - v973) >> 31));
    v976[v1141] = v1241;
    int * v978 = v859->cache_age;
    int v979 = v978[v1143];
    int * v980 = v859->cache_age;
    int v1244 = v979 + ((int)((unsigned int)(v979 - v973) >> 31));
    v980[v1143] = v1244;
    int * v982 = v859->cache_age;
    v982[v1232] = 0;
    v985 = v1232;
  }
  int v1247 = (v985 * 2) + (((int)((unsigned int)v861 >> 2)) & 1);
  int v986 = v872[v1247];
  int * v987 = v859->regs;
  v987[11] = v986;
  struct StateT * v989 = v836->b;
  int * v990 = v989->regs;
  int v991 = v990[6];
  int * v992 = v989->cache_tags;
  int v1253 = (((int)((unsigned int)((int)((unsigned int)v991 >> 2)) >> 1)) & 1) * 2;
  int v993 = v992[v1253];
  int * v994 = v989->cache_tags;
  int v1255 = ((((int)((unsigned int)((int)((unsigned int)v991 >> 2)) >> 1)) & 1) * 2) + 1;
  int v995 = v994[v1255];
  int * v996 = v989->cache_tags;
  int v1257 = 4 + ((((int)((unsigned int)((int)((unsigned int)v991 >> 2)) >> 1)) & 3) * 2);
  int v997 = v996[v1257];
  int * v998 = v989->cache_tags;
  int v1259 = (4 + ((((int)((unsigned int)((int)((unsigned int)v991 >> 2)) >> 1)) & 3) * 2)) + 1;
  int v999 = v998[v1259];
  int v1000 = v989->timer;
  int v1260 = v1000 + ((100 ^ (((~(((v997 ^ ((int)((unsigned int)((int)((unsigned int)v991 >> 2)) >> 1))) | (-(v997 ^ ((int)((unsigned int)((int)((unsigned int)v991 >> 2)) >> 1))))) >> 31)) | (~(((v999 ^ ((int)((unsigned int)((int)((unsigned int)v991 >> 2)) >> 1))) | (-(v999 ^ ((int)((unsigned int)((int)((unsigned int)v991 >> 2)) >> 1))))) >> 31))) & 104)) ^ (((~(((v993 ^ ((int)((unsigned int)((int)((unsigned int)v991 >> 2)) >> 1))) | (-(v993 ^ ((int)((unsigned int)((int)((unsigned int)v991 >> 2)) >> 1))))) >> 31)) | (~(((v995 ^ ((int)((unsigned int)((int)((unsigned int)v991 >> 2)) >> 1))) | (-(v995 ^ ((int)((unsigned int)((int)((unsigned int)v991 >> 2)) >> 1))))) >> 31))) & (1 ^ (100 ^ (((~(((v997 ^ ((int)((unsigned int)((int)((unsigned int)v991 >> 2)) >> 1))) | (-(v997 ^ ((int)((unsigned int)((int)((unsigned int)v991 >> 2)) >> 1))))) >> 31)) | (~(((v999 ^ ((int)((unsigned int)((int)((unsigned int)v991 >> 2)) >> 1))) | (-(v999 ^ ((int)((unsigned int)((int)((unsigned int)v991 >> 2)) >> 1))))) >> 31))) & 104)))));
  v989->timer = v1260;
  int * v1002 = v989->cache_vals;
  bool v1261 = !(((~(((v993 ^ ((int)((unsigned int)((int)((unsigned int)v991 >> 2)) >> 1))) | (-(v993 ^ ((int)((unsigned int)((int)((unsigned int)v991 >> 2)) >> 1))))) >> 31)) | (~(((v995 ^ ((int)((unsigned int)((int)((unsigned int)v991 >> 2)) >> 1))) | (-(v995 ^ ((int)((unsigned int)((int)((unsigned int)v991 >> 2)) >> 1))))) >> 31))) == 0);
  int v1115;
  if (v1261) {
    int * v1003 = v989->cache_age;
    int v1263 = ((((int)((unsigned int)((int)((unsigned int)v991 >> 2)) >> 1)) & 1) * 2) + ((~(((v995 ^ ((int)((unsigned int)((int)((unsigned int)v991 >> 2)) >> 1))) | (-(v995 ^ ((int)((unsigned int)((int)((unsigned int)v991 >> 2)) >> 1))))) >> 31)) & 1);
    int v1004 = v1003[v1263];
    int * v1005 = v989->cache_age;
    int v1006 = v1005[v1253];
    int * v1007 = v989->cache_age;
    int v1266 = v1006 + ((int)((unsigned int)(v1006 - v1004) >> 31));
    v1007[v1253] = v1266;
    int * v1009 = v989->cache_age;
    int v1010 = v1009[v1255];
    int * v1011 = v989->cache_age;
    int v1269 = v1010 + ((int)((unsigned int)(v1010 - v1004) >> 31));
    v1011[v1255] = v1269;
    int * v1013 = v989->cache_age;
    v1013[v1263] = 0;
    v1115 = v1263;
  } else {
    int * v1016 = v989->cache_age;
    int v1273 = (((int)((unsigned int)((int)((unsigned int)v991 >> 2)) >> 1)) & 1) * 2;
    int v1017 = v1016[v1273];
    int * v1018 = v989->cache_tags;
    int v1019 = v1018[v1273];
    int * v1020 = v989->cache_age;
    int v1021 = v1020[v1255];
    int * v1022 = v989->cache_tags;
    int v1023 = v1022[v1255];
    bool v1277 = !(((~(((v997 ^ ((int)((unsigned int)((int)((unsigned int)v991 >> 2)) >> 1))) | (-(v997 ^ ((int)((unsigned int)((int)((unsigned int)v991 >> 2)) >> 1))))) >> 31)) | (~(((v999 ^ ((int)((unsigned int)((int)((unsigned int)v991 >> 2)) >> 1))) | (-(v999 ^ ((int)((unsigned int)((int)((unsigned int)v991 >> 2)) >> 1))))) >> 31))) == 0);
    int v1087;
    if (v1277) {
      int * v1024 = v989->cache_age;
      int v1279 = (4 + ((((int)((unsigned int)((int)((unsigned int)v991 >> 2)) >> 1)) & 3) * 2)) + ((~(((v999 ^ ((int)((unsigned int)((int)((unsigned int)v991 >> 2)) >> 1))) | (-(v999 ^ ((int)((unsigned int)((int)((unsigned int)v991 >> 2)) >> 1))))) >> 31)) & 1);
      int v1025 = v1024[v1279];
      int * v1026 = v989->cache_age;
      int v1027 = v1026[v1257];
      int * v1028 = v989->cache_age;
      int v1282 = v1027 + ((int)((unsigned int)(v1027 - v1025) >> 31));
      v1028[v1257] = v1282;
      int * v1030 = v989->cache_age;
      int v1031 = v1030[v1259];
      int * v1032 = v989->cache_age;
      int v1285 = v1031 + ((int)((unsigned int)(v1031 - v1025) >> 31));
      v1032[v1259] = v1285;
      int * v1034 = v989->cache_age;
      v1034[v1279] = 0;
      v1087 = v1279;
    } else {
      int * v1037 = v989->cache_age;
      int v1289 = 4 + ((((int)((unsigned int)((int)((unsigned int)v991 >> 2)) >> 1)) & 3) * 2);
      int v1038 = v1037[v1289];
      int * v1039 = v989->cache_tags;
      int v1040 = v1039[v1289];
      int * v1041 = v989->cache_age;
      int v1042 = v1041[v1259];
      int * v1043 = v989->cache_tags;
      int v1044 = v1043[v1259];
      int * v1045 = v989->cache_dirty;
      int v1294 = (4 + ((((int)((unsigned int)((int)((unsigned int)v991 >> 2)) >> 1)) & 3) * 2)) + ((((v1038 + ((~(((v1040 ^ -1) | (-(v1040 ^ -1))) >> 31)) & 2)) - (v1042 + ((~(((v1044 ^ -1) | (-(v1044 ^ -1))) >> 31)) & 2))) >> 31) & 1);
      int v1046 = v1045[v1294];
      bool v1295 = !(v1046 == 0);
      if (v1295) {
        int * v1047 = v989->cache_tags;
        int v1048 = v1047[v1294];
        int * v1049 = v989->cache_vals;
        int v1298 = ((4 + ((((int)((unsigned int)((int)((unsigned int)v991 >> 2)) >> 1)) & 3) * 2)) + ((((v1038 + ((~(((v1040 ^ -1) | (-(v1040 ^ -1))) >> 31)) & 2)) - (v1042 + ((~(((v1044 ^ -1) | (-(v1044 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
        int v1050 = v1049[v1298];
        int * v1051 = v989->cache_vals;
        int v1300 = (((4 + ((((int)((unsigned int)((int)((unsigned int)v991 >> 2)) >> 1)) & 3) * 2)) + ((((v1038 + ((~(((v1040 ^ -1) | (-(v1040 ^ -1))) >> 31)) & 2)) - (v1042 + ((~(((v1044 ^ -1) | (-(v1044 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
        int v1052 = v1051[v1300];
        int * v1053 = v989->mem;
        int v1302 = v1048 * 2;
        v1053[v1302] = v1050;
        int * v1055 = v989->mem;
        int v1305 = (v1048 * 2) + 1;
        v1055[v1305] = v1052;
        ;
      } else {
        ;
      }
      int * v1060 = v989->mem;
      int v1310 = ((int)((unsigned int)((int)((unsigned int)v991 >> 2)) >> 1)) * 2;
      int v1061 = v1060[v1310];
      int * v1062 = v989->mem;
      int v1312 = (((int)((unsigned int)((int)((unsigned int)v991 >> 2)) >> 1)) * 2) + 1;
      int v1063 = v1062[v1312];
      int * v1064 = v989->cache_vals;
      int v1314 = ((4 + ((((int)((unsigned int)((int)((unsigned int)v991 >> 2)) >> 1)) & 3) * 2)) + ((((v1038 + ((~(((v1040 ^ -1) | (-(v1040 ^ -1))) >> 31)) & 2)) - (v1042 + ((~(((v1044 ^ -1) | (-(v1044 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
      v1064[v1314] = v1061;
      int * v1066 = v989->cache_vals;
      int v1317 = (((4 + ((((int)((unsigned int)((int)((unsigned int)v991 >> 2)) >> 1)) & 3) * 2)) + ((((v1038 + ((~(((v1040 ^ -1) | (-(v1040 ^ -1))) >> 31)) & 2)) - (v1042 + ((~(((v1044 ^ -1) | (-(v1044 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
      v1066[v1317] = v1063;
      int * v1068 = v989->cache_tags;
      int v1320 = (int)((unsigned int)((int)((unsigned int)v991 >> 2)) >> 1);
      v1068[v1294] = v1320;
      int * v1070 = v989->cache_dirty;
      v1070[v1294] = 0;
      int * v1072 = v989->cache_age;
      v1072[v1294] = 1;
      int * v1074 = v989->cache_age;
      int v1075 = v1074[v1294];
      int * v1076 = v989->cache_age;
      int v1077 = v1076[v1257];
      int * v1078 = v989->cache_age;
      int v1328 = v1077 + ((int)((unsigned int)(v1077 - v1075) >> 31));
      v1078[v1257] = v1328;
      int * v1080 = v989->cache_age;
      int v1081 = v1080[v1259];
      int * v1082 = v989->cache_age;
      int v1331 = v1081 + ((int)((unsigned int)(v1081 - v1075) >> 31));
      v1082[v1259] = v1331;
      int * v1084 = v989->cache_age;
      v1084[v1294] = 0;
      v1087 = v1294;
    }
    int * v1088 = v989->cache_vals;
    int v1334 = v1087 * 2;
    int v1089 = v1088[v1334];
    int * v1090 = v989->cache_vals;
    int v1336 = (v1087 * 2) + 1;
    int v1091 = v1090[v1336];
    int * v1092 = v989->cache_vals;
    int v1338 = (((((int)((unsigned int)((int)((unsigned int)v991 >> 2)) >> 1)) & 1) * 2) + ((((v1017 + ((~(((v1019 ^ -1) | (-(v1019 ^ -1))) >> 31)) & 2)) - (v1021 + ((~(((v1023 ^ -1) | (-(v1023 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
    v1092[v1338] = v1089;
    int * v1094 = v989->cache_vals;
    int v1341 = ((((((int)((unsigned int)((int)((unsigned int)v991 >> 2)) >> 1)) & 1) * 2) + ((((v1017 + ((~(((v1019 ^ -1) | (-(v1019 ^ -1))) >> 31)) & 2)) - (v1021 + ((~(((v1023 ^ -1) | (-(v1023 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
    v1094[v1341] = v1091;
    int * v1096 = v989->cache_tags;
    int v1344 = ((((int)((unsigned int)((int)((unsigned int)v991 >> 2)) >> 1)) & 1) * 2) + ((((v1017 + ((~(((v1019 ^ -1) | (-(v1019 ^ -1))) >> 31)) & 2)) - (v1021 + ((~(((v1023 ^ -1) | (-(v1023 ^ -1))) >> 31)) & 2))) >> 31) & 1);
    int v1345 = (int)((unsigned int)((int)((unsigned int)v991 >> 2)) >> 1);
    v1096[v1344] = v1345;
    int * v1098 = v989->cache_dirty;
    v1098[v1344] = 0;
    int * v1100 = v989->cache_age;
    v1100[v1344] = 1;
    int * v1102 = v989->cache_age;
    int v1103 = v1102[v1344];
    int * v1104 = v989->cache_age;
    int v1105 = v1104[v1253];
    int * v1106 = v989->cache_age;
    int v1353 = v1105 + ((int)((unsigned int)(v1105 - v1103) >> 31));
    v1106[v1253] = v1353;
    int * v1108 = v989->cache_age;
    int v1109 = v1108[v1255];
    int * v1110 = v989->cache_age;
    int v1356 = v1109 + ((int)((unsigned int)(v1109 - v1103) >> 31));
    v1110[v1255] = v1356;
    int * v1112 = v989->cache_age;
    v1112[v1344] = 0;
    v1115 = v1344;
  }
  int v1359 = (v1115 * 2) + (((int)((unsigned int)v991 >> 2)) & 1);
  int v1116 = v1002[v1359];
  int * v1117 = v989->regs;
  v1117[11] = v1116;
  struct StateT2 * v1119 = slot_9(v836);
  return v1119;
}

struct StateT2 * slot_4(struct StateT2 * v146) {
  struct StateT * v147 = v146->a;
  int v148 = v147->timer;
  struct StateT * v149 = v146->b;
  int v150 = v149->timer;
  bool v163 = v148 == v150;
  squared_assert(v163);
  squared_assume(v163);
  struct StateT * v153 = v146->a;
  int v154 = v153->timer;
  int v165 = v154 + 1;
  v153->timer = v165;
  struct StateT * v156 = v146->b;
  int v157 = v156->timer;
  int v167 = v157 + 1;
  v156->timer = v167;
  struct StateT2 * v159 = slot_5(v146);
  return v159;
}

struct StateT2 * slot_13(struct StateT2 * v1534) {
  struct StateT * v1535 = v1534->a;
  int v1536 = v1535->timer;
  struct StateT * v1537 = v1534->b;
  int v1538 = v1537->timer;
  bool v1571 = v1536 == v1538;
  squared_assert(v1571);
  squared_assume(v1571);
  struct StateT * v1541 = v1534->a;
  int * v1542 = v1541->saved_regs;
  int * v1543 = v1541->regs;
  int v1544 = v1543[14];
  v1542[14] = v1544;
  struct StateT * v1546 = v1534->b;
  int * v1547 = v1546->saved_regs;
  int * v1548 = v1546->regs;
  int v1549 = v1548[14];
  v1547[14] = v1549;
  struct StateT * v1551 = v1534->a;
  int v1552 = v1551->timer;
  int v1582 = v1552 + 1;
  v1551->timer = v1582;
  struct StateT * v1554 = v1534->b;
  int v1555 = v1554->timer;
  int v1584 = v1555 + 1;
  v1554->timer = v1584;
  struct StateT * v1557 = v1534->a;
  int * v1558 = v1557->regs;
  int v1559 = v1558[14];
  int * v1560 = v1557->regs;
  int v1588 = v1559 + 4;
  v1560[14] = v1588;
  struct StateT * v1562 = v1534->b;
  int * v1563 = v1562->regs;
  int v1564 = v1563[14];
  int * v1565 = v1562->regs;
  int v1592 = v1564 + 4;
  v1565[14] = v1592;
  struct StateT2 * v1567 = slot_14(v1534);
  return v1567;
}

struct StateT2 * slot_15(struct StateT2 * v1663) {
  struct StateT * v1664 = v1663->a;
  int v1665 = v1664->timer;
  struct StateT * v1666 = v1663->b;
  int v1667 = v1666->timer;
  bool v1686 = v1665 == v1667;
  squared_assert(v1686);
  squared_assume(v1686);
  struct StateT * v1670 = v1663->a;
  int v1671 = v1670->timer;
  int v1688 = v1671 + 1;
  v1670->timer = v1688;
  struct StateT * v1673 = v1663->b;
  int v1674 = v1673->timer;
  int v1690 = v1674 + 1;
  v1673->timer = v1690;
  struct StateT * v1676 = v1663->a;
  int * v1677 = v1676->regs;
  v1677[10] = 0;
  struct StateT * v1679 = v1663->b;
  int * v1680 = v1679->regs;
  v1680[10] = 0;
  struct StateT2 * v1682 = slot_17(v1663);
  return v1682;
}

struct StateT2 * slot_9(struct StateT2 * v1364) {
  struct StateT * v1365 = v1364->a;
  int v1366 = v1365->timer;
  struct StateT * v1367 = v1364->b;
  int v1368 = v1367->timer;
  bool v1429 = v1366 == v1368;
  squared_assert(v1429);
  squared_assume(v1429);
  struct StateT * v1371 = v1364->a;
  int * v1372 = v1371->regs;
  int v1373 = v1372[14];
  int * v1374 = v1371->regs;
  int v1375 = v1374[15];
  struct StateT * v1376 = v1364->b;
  int * v1377 = v1376->regs;
  int v1378 = v1377[14];
  int * v1379 = v1376->regs;
  int v1380 = v1379[15];
  bool v1438 = (v1373 >= v1375) == (v1378 >= v1380);
  squared_diverged(v1438);
  squared_assume(v1438);
  bool v1439 = v1373 >= v1375;
  struct StateT2 * v1425;
  if (v1439) {
    struct StateT * v1383 = v1364->a;
    int v1384 = v1383->timer;
    int v1441 = v1384 + 15;
    v1383->timer = v1441;
    int * v1386 = v1383->saved_regs;
    int v1387 = v1386[5];
    int * v1388 = v1383->regs;
    v1388[5] = v1387;
    int * v1390 = v1383->saved_regs;
    int v1391 = v1390[10];
    int * v1392 = v1383->regs;
    v1392[10] = v1391;
    int * v1394 = v1383->saved_regs;
    int v1395 = v1394[6];
    int * v1396 = v1383->regs;
    v1396[6] = v1395;
    int * v1398 = v1383->saved_regs;
    int v1399 = v1398[11];
    int * v1400 = v1383->regs;
    v1400[11] = v1399;
    struct StateT * v1402 = v1364->b;
    int v1403 = v1402->timer;
    int v1459 = v1403 + 15;
    v1402->timer = v1459;
    int * v1405 = v1402->saved_regs;
    int v1406 = v1405[5];
    int * v1407 = v1402->regs;
    v1407[5] = v1406;
    int * v1409 = v1402->saved_regs;
    int v1410 = v1409[10];
    int * v1411 = v1402->regs;
    v1411[10] = v1410;
    int * v1413 = v1402->saved_regs;
    int v1414 = v1413[6];
    int * v1415 = v1402->regs;
    v1415[6] = v1414;
    int * v1417 = v1402->saved_regs;
    int v1418 = v1417[11];
    int * v1419 = v1402->regs;
    v1419[11] = v1418;
    struct StateT2 * v1421 = slot_10(v1364);
    v1425 = v1421;
  } else {
    struct StateT2 * v1423 = slot_11(v1364);
    v1425 = v1423;
  }
  return v1425;
}

struct StateT2 * slot_11(struct StateT2 * v1510) {
  struct StateT * v1511 = v1510->a;
  int v1512 = v1511->timer;
  struct StateT * v1513 = v1510->b;
  int v1514 = v1513->timer;
  bool v1527 = v1512 == v1514;
  squared_assert(v1527);
  squared_assume(v1527);
  struct StateT * v1517 = v1510->a;
  int v1518 = v1517->timer;
  int v1529 = v1518 + 1;
  v1517->timer = v1529;
  struct StateT * v1520 = v1510->b;
  int v1521 = v1520->timer;
  int v1531 = v1521 + 1;
  v1520->timer = v1531;
  struct StateT2 * v1523 = slot_13(v1510);
  return v1523;
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
    s1.mem[SECRET_OFFSET+i] = secret(0, 20);
    s2.mem[SECRET_OFFSET+i] = secret(0, 20);
  }
  struct StateT2 p = { .a = &s1, .b = &s2 };
  struct StateT2 *p_ = snippet(&p);
  koika_assert(p_->a->timer==p_->b->timer, "timing leak");
  return 0;
}