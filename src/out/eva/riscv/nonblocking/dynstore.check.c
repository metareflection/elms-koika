// verify: clean (Eva should report untainted: Valid) [unroll 65]
#define NUM_REGS 32
#define MEM_SIZE 64
#define SECRET_SIZE 10
#define SECRET_OFFSET 20
#define CACHE_ENTRIES 12
#define CACHE_WORDS 24

#ifdef EVA
#include "__fc_builtin.h"
/*@ requires untainted: !\tainted(b);
    assigns \nothing; */
void koika_check(int b);
/*@ assigns *p \from \nothing;
    taints *p; */
void koika_mark(int *p);
#define koika_assert(b, s) koika_check(b)
#define koika_assume(b) do { if (!(b)) Frama_C_abort(); } while (0)
#define koika_draw(x) ((x) = Frama_C_interval(-2147483647-1, 2147483647))
#define koika_secret(x) koika_mark(&(x))
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

struct StateT * slot_6(struct StateT * v306);
struct StateT * slot_5(struct StateT * v98);
struct StateT * slot_2(struct StateT * v34);
struct StateT * slot_7(struct StateT * v625);
struct StateT * slot_3(struct StateT * v50);
struct StateT * snippet(struct StateT * v0);
struct StateT * slot_1(struct StateT * v18);
struct StateT * slot_8(struct StateT * v833);
struct StateT * slot_4(struct StateT * v73);
struct StateT * slot_9(struct StateT * v854);
struct StateT * slot_0(struct StateT * v2);
struct StateT * slot_6(struct StateT * v306) {
  int v307 = v306->timer;
  int v480 = v307 + 1;
  v306->timer = v480;
  int * v309 = v306->reg_ready;
  int * v311 = v306->regs;
  int v312 = v311[6];
  int v314 = v311[5];
  int * v315 = v306->cache_tags;
  int v486 = (((int)((unsigned int)((int)((unsigned int)v312 >> 2)) >> 1)) & 1) * 2;
  int v316 = v315[v486];
  int v487 = ((((int)((unsigned int)((int)((unsigned int)v312 >> 2)) >> 1)) & 1) * 2) + 1;
  int v317 = v315[v487];
  int v488 = 4 + ((((int)((unsigned int)((int)((unsigned int)v312 >> 2)) >> 1)) & 3) * 2);
  int v318 = v315[v488];
  int v489 = (4 + ((((int)((unsigned int)((int)((unsigned int)v312 >> 2)) >> 1)) & 3) * 2)) + 1;
  int v319 = v315[v489];
  int v320 = v306->timer;
  int v490 = v320 + ((100 ^ (((~(((v318 ^ ((int)((unsigned int)((int)((unsigned int)v312 >> 2)) >> 1))) | (-(v318 ^ ((int)((unsigned int)((int)((unsigned int)v312 >> 2)) >> 1))))) >> 31)) | (~(((v319 ^ ((int)((unsigned int)((int)((unsigned int)v312 >> 2)) >> 1))) | (-(v319 ^ ((int)((unsigned int)((int)((unsigned int)v312 >> 2)) >> 1))))) >> 31))) & 104)) ^ (((~(((v316 ^ ((int)((unsigned int)((int)((unsigned int)v312 >> 2)) >> 1))) | (-(v316 ^ ((int)((unsigned int)((int)((unsigned int)v312 >> 2)) >> 1))))) >> 31)) | (~(((v317 ^ ((int)((unsigned int)((int)((unsigned int)v312 >> 2)) >> 1))) | (-(v317 ^ ((int)((unsigned int)((int)((unsigned int)v312 >> 2)) >> 1))))) >> 31))) & (1 ^ (100 ^ (((~(((v318 ^ ((int)((unsigned int)((int)((unsigned int)v312 >> 2)) >> 1))) | (-(v318 ^ ((int)((unsigned int)((int)((unsigned int)v312 >> 2)) >> 1))))) >> 31)) | (~(((v319 ^ ((int)((unsigned int)((int)((unsigned int)v312 >> 2)) >> 1))) | (-(v319 ^ ((int)((unsigned int)((int)((unsigned int)v312 >> 2)) >> 1))))) >> 31))) & 104)))));
  v306->timer = v490;
  bool v491 = !(((~(((v316 ^ ((int)((unsigned int)((int)((unsigned int)v312 >> 2)) >> 1))) | (-(v316 ^ ((int)((unsigned int)((int)((unsigned int)v312 >> 2)) >> 1))))) >> 31)) | (~(((v317 ^ ((int)((unsigned int)((int)((unsigned int)v312 >> 2)) >> 1))) | (-(v317 ^ ((int)((unsigned int)((int)((unsigned int)v312 >> 2)) >> 1))))) >> 31))) == 0);
  int v414;
  if (v491) {
    int * v322 = v306->cache_age;
    int v493 = ((((int)((unsigned int)((int)((unsigned int)v312 >> 2)) >> 1)) & 1) * 2) + ((~(((v317 ^ ((int)((unsigned int)((int)((unsigned int)v312 >> 2)) >> 1))) | (-(v317 ^ ((int)((unsigned int)((int)((unsigned int)v312 >> 2)) >> 1))))) >> 31)) & 1);
    int v323 = v322[v493];
    int v324 = v322[v486];
    int v494 = v324 + ((int)((unsigned int)(v324 - v323) >> 31));
    v322[v486] = v494;
    int * v326 = v306->cache_age;
    int v327 = v326[v487];
    int v496 = v327 + ((int)((unsigned int)(v327 - v323) >> 31));
    v326[v487] = v496;
    int * v329 = v306->cache_age;
    v329[v493] = 0;
    v414 = v493;
  } else {
    int * v332 = v306->cache_age;
    int v500 = (((int)((unsigned int)((int)((unsigned int)v312 >> 2)) >> 1)) & 1) * 2;
    int v333 = v332[v500];
    int * v334 = v306->cache_tags;
    int v335 = v334[v500];
    int v336 = v332[v487];
    int v337 = v334[v487];
    bool v502 = !(((~(((v318 ^ ((int)((unsigned int)((int)((unsigned int)v312 >> 2)) >> 1))) | (-(v318 ^ ((int)((unsigned int)((int)((unsigned int)v312 >> 2)) >> 1))))) >> 31)) | (~(((v319 ^ ((int)((unsigned int)((int)((unsigned int)v312 >> 2)) >> 1))) | (-(v319 ^ ((int)((unsigned int)((int)((unsigned int)v312 >> 2)) >> 1))))) >> 31))) == 0);
    int v391;
    if (v502) {
      int * v338 = v306->cache_age;
      int v504 = (4 + ((((int)((unsigned int)((int)((unsigned int)v312 >> 2)) >> 1)) & 3) * 2)) + ((~(((v319 ^ ((int)((unsigned int)((int)((unsigned int)v312 >> 2)) >> 1))) | (-(v319 ^ ((int)((unsigned int)((int)((unsigned int)v312 >> 2)) >> 1))))) >> 31)) & 1);
      int v339 = v338[v504];
      int v340 = v338[v488];
      int v505 = v340 + ((int)((unsigned int)(v340 - v339) >> 31));
      v338[v488] = v505;
      int * v342 = v306->cache_age;
      int v343 = v342[v489];
      int v507 = v343 + ((int)((unsigned int)(v343 - v339) >> 31));
      v342[v489] = v507;
      int * v345 = v306->cache_age;
      v345[v504] = 0;
      v391 = v504;
    } else {
      int * v348 = v306->cache_age;
      int v511 = 4 + ((((int)((unsigned int)((int)((unsigned int)v312 >> 2)) >> 1)) & 3) * 2);
      int v349 = v348[v511];
      int * v350 = v306->cache_tags;
      int v351 = v350[v511];
      int v352 = v348[v489];
      int v353 = v350[v489];
      int * v354 = v306->cache_dirty;
      int v514 = (4 + ((((int)((unsigned int)((int)((unsigned int)v312 >> 2)) >> 1)) & 3) * 2)) + ((((v349 + ((~(((v351 ^ -1) | (-(v351 ^ -1))) >> 31)) & 2)) - (v352 + ((~(((v353 ^ -1) | (-(v353 ^ -1))) >> 31)) & 2))) >> 31) & 1);
      int v355 = v354[v514];
      bool v515 = !(v355 == 0);
      if (v515) {
        int * v356 = v306->cache_tags;
        int v357 = v356[v514];
        int * v358 = v306->cache_vals;
        int v518 = ((4 + ((((int)((unsigned int)((int)((unsigned int)v312 >> 2)) >> 1)) & 3) * 2)) + ((((v349 + ((~(((v351 ^ -1) | (-(v351 ^ -1))) >> 31)) & 2)) - (v352 + ((~(((v353 ^ -1) | (-(v353 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
        int v359 = v358[v518];
        int v519 = (((4 + ((((int)((unsigned int)((int)((unsigned int)v312 >> 2)) >> 1)) & 3) * 2)) + ((((v349 + ((~(((v351 ^ -1) | (-(v351 ^ -1))) >> 31)) & 2)) - (v352 + ((~(((v353 ^ -1) | (-(v353 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
        int v360 = v358[v519];
        int * v361 = v306->mem;
        int v521 = v357 * 2;
        v361[v521] = v359;
        int * v363 = v306->mem;
        int v524 = (v357 * 2) + 1;
        v363[v524] = v360;
        ;
      } else {
        ;
      }
      int * v368 = v306->mem;
      int v529 = ((int)((unsigned int)((int)((unsigned int)v312 >> 2)) >> 1)) * 2;
      int v369 = v368[v529];
      int v530 = (((int)((unsigned int)((int)((unsigned int)v312 >> 2)) >> 1)) * 2) + 1;
      int v370 = v368[v530];
      int * v371 = v306->cache_vals;
      int v532 = ((4 + ((((int)((unsigned int)((int)((unsigned int)v312 >> 2)) >> 1)) & 3) * 2)) + ((((v349 + ((~(((v351 ^ -1) | (-(v351 ^ -1))) >> 31)) & 2)) - (v352 + ((~(((v353 ^ -1) | (-(v353 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
      v371[v532] = v369;
      int * v373 = v306->cache_vals;
      int v535 = (((4 + ((((int)((unsigned int)((int)((unsigned int)v312 >> 2)) >> 1)) & 3) * 2)) + ((((v349 + ((~(((v351 ^ -1) | (-(v351 ^ -1))) >> 31)) & 2)) - (v352 + ((~(((v353 ^ -1) | (-(v353 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
      v373[v535] = v370;
      int * v375 = v306->cache_tags;
      int v538 = (int)((unsigned int)((int)((unsigned int)v312 >> 2)) >> 1);
      v375[v514] = v538;
      int * v377 = v306->cache_dirty;
      v377[v514] = 0;
      int * v379 = v306->cache_age;
      v379[v514] = 1;
      int * v381 = v306->cache_age;
      int v382 = v381[v514];
      int v383 = v381[v488];
      int v544 = v383 + ((int)((unsigned int)(v383 - v382) >> 31));
      v381[v488] = v544;
      int * v385 = v306->cache_age;
      int v386 = v385[v489];
      int v546 = v386 + ((int)((unsigned int)(v386 - v382) >> 31));
      v385[v489] = v546;
      int * v388 = v306->cache_age;
      v388[v514] = 0;
      v391 = v514;
    }
    int * v392 = v306->cache_vals;
    int v549 = v391 * 2;
    int v393 = v392[v549];
    int v550 = (v391 * 2) + 1;
    int v394 = v392[v550];
    int v551 = (((((int)((unsigned int)((int)((unsigned int)v312 >> 2)) >> 1)) & 1) * 2) + ((((v333 + ((~(((v335 ^ -1) | (-(v335 ^ -1))) >> 31)) & 2)) - (v336 + ((~(((v337 ^ -1) | (-(v337 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
    v392[v551] = v393;
    int * v396 = v306->cache_vals;
    int v554 = ((((((int)((unsigned int)((int)((unsigned int)v312 >> 2)) >> 1)) & 1) * 2) + ((((v333 + ((~(((v335 ^ -1) | (-(v335 ^ -1))) >> 31)) & 2)) - (v336 + ((~(((v337 ^ -1) | (-(v337 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
    v396[v554] = v394;
    int * v398 = v306->cache_tags;
    int v557 = ((((int)((unsigned int)((int)((unsigned int)v312 >> 2)) >> 1)) & 1) * 2) + ((((v333 + ((~(((v335 ^ -1) | (-(v335 ^ -1))) >> 31)) & 2)) - (v336 + ((~(((v337 ^ -1) | (-(v337 ^ -1))) >> 31)) & 2))) >> 31) & 1);
    int v558 = (int)((unsigned int)((int)((unsigned int)v312 >> 2)) >> 1);
    v398[v557] = v558;
    int * v400 = v306->cache_dirty;
    v400[v557] = 0;
    int * v402 = v306->cache_age;
    v402[v557] = 1;
    int * v404 = v306->cache_age;
    int v405 = v404[v557];
    int v406 = v404[v486];
    int v564 = v406 + ((int)((unsigned int)(v406 - v405) >> 31));
    v404[v486] = v564;
    int * v408 = v306->cache_age;
    int v409 = v408[v487];
    int v566 = v409 + ((int)((unsigned int)(v409 - v405) >> 31));
    v408[v487] = v566;
    int * v411 = v306->cache_age;
    v411[v557] = 0;
    v414 = v557;
  }
  int * v415 = v306->cache_vals;
  int v569 = (v414 * 2) + (((int)((unsigned int)v312 >> 2)) & 1);
  v415[v569] = v314;
  int * v417 = v306->cache_tags;
  int v418 = v417[v488];
  int v419 = v417[v489];
  bool v572 = !(((~(((v418 ^ ((int)((unsigned int)((int)((unsigned int)v312 >> 2)) >> 1))) | (-(v418 ^ ((int)((unsigned int)((int)((unsigned int)v312 >> 2)) >> 1))))) >> 31)) | (~(((v419 ^ ((int)((unsigned int)((int)((unsigned int)v312 >> 2)) >> 1))) | (-(v419 ^ ((int)((unsigned int)((int)((unsigned int)v312 >> 2)) >> 1))))) >> 31))) == 0);
  int v473;
  if (v572) {
    int * v420 = v306->cache_age;
    int v574 = (4 + ((((int)((unsigned int)((int)((unsigned int)v312 >> 2)) >> 1)) & 3) * 2)) + ((~(((v419 ^ ((int)((unsigned int)((int)((unsigned int)v312 >> 2)) >> 1))) | (-(v419 ^ ((int)((unsigned int)((int)((unsigned int)v312 >> 2)) >> 1))))) >> 31)) & 1);
    int v421 = v420[v574];
    int v422 = v420[v488];
    int v575 = v422 + ((int)((unsigned int)(v422 - v421) >> 31));
    v420[v488] = v575;
    int * v424 = v306->cache_age;
    int v425 = v424[v489];
    int v577 = v425 + ((int)((unsigned int)(v425 - v421) >> 31));
    v424[v489] = v577;
    int * v427 = v306->cache_age;
    v427[v574] = 0;
    v473 = v574;
  } else {
    int * v430 = v306->cache_age;
    int v581 = 4 + ((((int)((unsigned int)((int)((unsigned int)v312 >> 2)) >> 1)) & 3) * 2);
    int v431 = v430[v581];
    int * v432 = v306->cache_tags;
    int v433 = v432[v581];
    int v434 = v430[v489];
    int v435 = v432[v489];
    int * v436 = v306->cache_dirty;
    int v584 = (4 + ((((int)((unsigned int)((int)((unsigned int)v312 >> 2)) >> 1)) & 3) * 2)) + ((((v431 + ((~(((v433 ^ -1) | (-(v433 ^ -1))) >> 31)) & 2)) - (v434 + ((~(((v435 ^ -1) | (-(v435 ^ -1))) >> 31)) & 2))) >> 31) & 1);
    int v437 = v436[v584];
    bool v585 = !(v437 == 0);
    if (v585) {
      int * v438 = v306->cache_tags;
      int v439 = v438[v584];
      int * v440 = v306->cache_vals;
      int v588 = ((4 + ((((int)((unsigned int)((int)((unsigned int)v312 >> 2)) >> 1)) & 3) * 2)) + ((((v431 + ((~(((v433 ^ -1) | (-(v433 ^ -1))) >> 31)) & 2)) - (v434 + ((~(((v435 ^ -1) | (-(v435 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
      int v441 = v440[v588];
      int v589 = (((4 + ((((int)((unsigned int)((int)((unsigned int)v312 >> 2)) >> 1)) & 3) * 2)) + ((((v431 + ((~(((v433 ^ -1) | (-(v433 ^ -1))) >> 31)) & 2)) - (v434 + ((~(((v435 ^ -1) | (-(v435 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
      int v442 = v440[v589];
      int * v443 = v306->mem;
      int v591 = v439 * 2;
      v443[v591] = v441;
      int * v445 = v306->mem;
      int v594 = (v439 * 2) + 1;
      v445[v594] = v442;
      ;
    } else {
      ;
    }
    int * v450 = v306->mem;
    int v599 = ((int)((unsigned int)((int)((unsigned int)v312 >> 2)) >> 1)) * 2;
    int v451 = v450[v599];
    int v600 = (((int)((unsigned int)((int)((unsigned int)v312 >> 2)) >> 1)) * 2) + 1;
    int v452 = v450[v600];
    int * v453 = v306->cache_vals;
    int v602 = ((4 + ((((int)((unsigned int)((int)((unsigned int)v312 >> 2)) >> 1)) & 3) * 2)) + ((((v431 + ((~(((v433 ^ -1) | (-(v433 ^ -1))) >> 31)) & 2)) - (v434 + ((~(((v435 ^ -1) | (-(v435 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
    v453[v602] = v451;
    int * v455 = v306->cache_vals;
    int v605 = (((4 + ((((int)((unsigned int)((int)((unsigned int)v312 >> 2)) >> 1)) & 3) * 2)) + ((((v431 + ((~(((v433 ^ -1) | (-(v433 ^ -1))) >> 31)) & 2)) - (v434 + ((~(((v435 ^ -1) | (-(v435 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
    v455[v605] = v452;
    int * v457 = v306->cache_tags;
    int v608 = (int)((unsigned int)((int)((unsigned int)v312 >> 2)) >> 1);
    v457[v584] = v608;
    int * v459 = v306->cache_dirty;
    v459[v584] = 0;
    int * v461 = v306->cache_age;
    v461[v584] = 1;
    int * v463 = v306->cache_age;
    int v464 = v463[v584];
    int v465 = v463[v488];
    int v614 = v465 + ((int)((unsigned int)(v465 - v464) >> 31));
    v463[v488] = v614;
    int * v467 = v306->cache_age;
    int v468 = v467[v489];
    int v616 = v468 + ((int)((unsigned int)(v468 - v464) >> 31));
    v467[v489] = v616;
    int * v470 = v306->cache_age;
    v470[v584] = 0;
    v473 = v584;
  }
  int * v474 = v306->cache_vals;
  int v619 = (v473 * 2) + (((int)((unsigned int)v312 >> 2)) & 1);
  v474[v619] = v314;
  int * v476 = v306->cache_dirty;
  v476[v473] = 1;
  struct StateT * v478 = slot_7(v306);
  return v478;
}

struct StateT * slot_5(struct StateT * v98) {
  int v99 = v98->timer;
  int v211 = v99 + 1;
  v98->timer = v211;
  int * v101 = v98->reg_ready;
  int v102 = v101[8];
  int * v103 = v98->regs;
  int v104 = v103[8];
  int * v105 = v98->cache_tags;
  int v216 = (((int)((unsigned int)((int)((unsigned int)v104 >> 2)) >> 1)) & 1) * 2;
  int v106 = v105[v216];
  int v217 = ((((int)((unsigned int)((int)((unsigned int)v104 >> 2)) >> 1)) & 1) * 2) + 1;
  int v107 = v105[v217];
  int v218 = 4 + ((((int)((unsigned int)((int)((unsigned int)v104 >> 2)) >> 1)) & 3) * 2);
  int v108 = v105[v218];
  int v219 = (4 + ((((int)((unsigned int)((int)((unsigned int)v104 >> 2)) >> 1)) & 3) * 2)) + 1;
  int v109 = v105[v219];
  int * v110 = v98->cache_vals;
  bool v220 = !(((~(((v106 ^ ((int)((unsigned int)((int)((unsigned int)v104 >> 2)) >> 1))) | (-(v106 ^ ((int)((unsigned int)((int)((unsigned int)v104 >> 2)) >> 1))))) >> 31)) | (~(((v107 ^ ((int)((unsigned int)((int)((unsigned int)v104 >> 2)) >> 1))) | (-(v107 ^ ((int)((unsigned int)((int)((unsigned int)v104 >> 2)) >> 1))))) >> 31))) == 0);
  int v203;
  if (v220) {
    int * v111 = v98->cache_age;
    int v222 = ((((int)((unsigned int)((int)((unsigned int)v104 >> 2)) >> 1)) & 1) * 2) + ((~(((v107 ^ ((int)((unsigned int)((int)((unsigned int)v104 >> 2)) >> 1))) | (-(v107 ^ ((int)((unsigned int)((int)((unsigned int)v104 >> 2)) >> 1))))) >> 31)) & 1);
    int v112 = v111[v222];
    int v113 = v111[v216];
    int v223 = v113 + ((int)((unsigned int)(v113 - v112) >> 31));
    v111[v216] = v223;
    int * v115 = v98->cache_age;
    int v116 = v115[v217];
    int v225 = v116 + ((int)((unsigned int)(v116 - v112) >> 31));
    v115[v217] = v225;
    int * v118 = v98->cache_age;
    v118[v222] = 0;
    v203 = v222;
  } else {
    int * v121 = v98->cache_age;
    int v229 = (((int)((unsigned int)((int)((unsigned int)v104 >> 2)) >> 1)) & 1) * 2;
    int v122 = v121[v229];
    int * v123 = v98->cache_tags;
    int v124 = v123[v229];
    int v125 = v121[v217];
    int v126 = v123[v217];
    bool v231 = !(((~(((v108 ^ ((int)((unsigned int)((int)((unsigned int)v104 >> 2)) >> 1))) | (-(v108 ^ ((int)((unsigned int)((int)((unsigned int)v104 >> 2)) >> 1))))) >> 31)) | (~(((v109 ^ ((int)((unsigned int)((int)((unsigned int)v104 >> 2)) >> 1))) | (-(v109 ^ ((int)((unsigned int)((int)((unsigned int)v104 >> 2)) >> 1))))) >> 31))) == 0);
    int v180;
    if (v231) {
      int * v127 = v98->cache_age;
      int v233 = (4 + ((((int)((unsigned int)((int)((unsigned int)v104 >> 2)) >> 1)) & 3) * 2)) + ((~(((v109 ^ ((int)((unsigned int)((int)((unsigned int)v104 >> 2)) >> 1))) | (-(v109 ^ ((int)((unsigned int)((int)((unsigned int)v104 >> 2)) >> 1))))) >> 31)) & 1);
      int v128 = v127[v233];
      int v129 = v127[v218];
      int v234 = v129 + ((int)((unsigned int)(v129 - v128) >> 31));
      v127[v218] = v234;
      int * v131 = v98->cache_age;
      int v132 = v131[v219];
      int v236 = v132 + ((int)((unsigned int)(v132 - v128) >> 31));
      v131[v219] = v236;
      int * v134 = v98->cache_age;
      v134[v233] = 0;
      v180 = v233;
    } else {
      int * v137 = v98->cache_age;
      int v240 = 4 + ((((int)((unsigned int)((int)((unsigned int)v104 >> 2)) >> 1)) & 3) * 2);
      int v138 = v137[v240];
      int * v139 = v98->cache_tags;
      int v140 = v139[v240];
      int v141 = v137[v219];
      int v142 = v139[v219];
      int * v143 = v98->cache_dirty;
      int v243 = (4 + ((((int)((unsigned int)((int)((unsigned int)v104 >> 2)) >> 1)) & 3) * 2)) + ((((v138 + ((~(((v140 ^ -1) | (-(v140 ^ -1))) >> 31)) & 2)) - (v141 + ((~(((v142 ^ -1) | (-(v142 ^ -1))) >> 31)) & 2))) >> 31) & 1);
      int v144 = v143[v243];
      bool v244 = !(v144 == 0);
      if (v244) {
        int * v145 = v98->cache_tags;
        int v146 = v145[v243];
        int * v147 = v98->cache_vals;
        int v247 = ((4 + ((((int)((unsigned int)((int)((unsigned int)v104 >> 2)) >> 1)) & 3) * 2)) + ((((v138 + ((~(((v140 ^ -1) | (-(v140 ^ -1))) >> 31)) & 2)) - (v141 + ((~(((v142 ^ -1) | (-(v142 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
        int v148 = v147[v247];
        int v248 = (((4 + ((((int)((unsigned int)((int)((unsigned int)v104 >> 2)) >> 1)) & 3) * 2)) + ((((v138 + ((~(((v140 ^ -1) | (-(v140 ^ -1))) >> 31)) & 2)) - (v141 + ((~(((v142 ^ -1) | (-(v142 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
        int v149 = v147[v248];
        int * v150 = v98->mem;
        int v250 = v146 * 2;
        v150[v250] = v148;
        int * v152 = v98->mem;
        int v253 = (v146 * 2) + 1;
        v152[v253] = v149;
        ;
      } else {
        ;
      }
      int * v157 = v98->mem;
      int v258 = ((int)((unsigned int)((int)((unsigned int)v104 >> 2)) >> 1)) * 2;
      int v158 = v157[v258];
      int v259 = (((int)((unsigned int)((int)((unsigned int)v104 >> 2)) >> 1)) * 2) + 1;
      int v159 = v157[v259];
      int * v160 = v98->cache_vals;
      int v261 = ((4 + ((((int)((unsigned int)((int)((unsigned int)v104 >> 2)) >> 1)) & 3) * 2)) + ((((v138 + ((~(((v140 ^ -1) | (-(v140 ^ -1))) >> 31)) & 2)) - (v141 + ((~(((v142 ^ -1) | (-(v142 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
      v160[v261] = v158;
      int * v162 = v98->cache_vals;
      int v264 = (((4 + ((((int)((unsigned int)((int)((unsigned int)v104 >> 2)) >> 1)) & 3) * 2)) + ((((v138 + ((~(((v140 ^ -1) | (-(v140 ^ -1))) >> 31)) & 2)) - (v141 + ((~(((v142 ^ -1) | (-(v142 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
      v162[v264] = v159;
      int * v164 = v98->cache_tags;
      int v267 = (int)((unsigned int)((int)((unsigned int)v104 >> 2)) >> 1);
      v164[v243] = v267;
      int * v166 = v98->cache_dirty;
      v166[v243] = 0;
      int * v168 = v98->cache_age;
      v168[v243] = 1;
      int * v170 = v98->cache_age;
      int v171 = v170[v243];
      int v172 = v170[v218];
      int v273 = v172 + ((int)((unsigned int)(v172 - v171) >> 31));
      v170[v218] = v273;
      int * v174 = v98->cache_age;
      int v175 = v174[v219];
      int v275 = v175 + ((int)((unsigned int)(v175 - v171) >> 31));
      v174[v219] = v275;
      int * v177 = v98->cache_age;
      v177[v243] = 0;
      v180 = v243;
    }
    int * v181 = v98->cache_vals;
    int v278 = v180 * 2;
    int v182 = v181[v278];
    int v279 = (v180 * 2) + 1;
    int v183 = v181[v279];
    int v280 = (((((int)((unsigned int)((int)((unsigned int)v104 >> 2)) >> 1)) & 1) * 2) + ((((v122 + ((~(((v124 ^ -1) | (-(v124 ^ -1))) >> 31)) & 2)) - (v125 + ((~(((v126 ^ -1) | (-(v126 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
    v181[v280] = v182;
    int * v185 = v98->cache_vals;
    int v283 = ((((((int)((unsigned int)((int)((unsigned int)v104 >> 2)) >> 1)) & 1) * 2) + ((((v122 + ((~(((v124 ^ -1) | (-(v124 ^ -1))) >> 31)) & 2)) - (v125 + ((~(((v126 ^ -1) | (-(v126 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
    v185[v283] = v183;
    int * v187 = v98->cache_tags;
    int v286 = ((((int)((unsigned int)((int)((unsigned int)v104 >> 2)) >> 1)) & 1) * 2) + ((((v122 + ((~(((v124 ^ -1) | (-(v124 ^ -1))) >> 31)) & 2)) - (v125 + ((~(((v126 ^ -1) | (-(v126 ^ -1))) >> 31)) & 2))) >> 31) & 1);
    int v287 = (int)((unsigned int)((int)((unsigned int)v104 >> 2)) >> 1);
    v187[v286] = v287;
    int * v189 = v98->cache_dirty;
    v189[v286] = 0;
    int * v191 = v98->cache_age;
    v191[v286] = 1;
    int * v193 = v98->cache_age;
    int v194 = v193[v286];
    int v195 = v193[v216];
    int v293 = v195 + ((int)((unsigned int)(v195 - v194) >> 31));
    v193[v216] = v293;
    int * v197 = v98->cache_age;
    int v198 = v197[v217];
    int v295 = v198 + ((int)((unsigned int)(v198 - v194) >> 31));
    v197[v217] = v295;
    int * v200 = v98->cache_age;
    v200[v286] = 0;
    v203 = v286;
  }
  int v298 = (v203 * 2) + (((int)((unsigned int)v104 >> 2)) & 1);
  int v204 = v110[v298];
  int * v205 = v98->reg_ready;
  int v301 = ((v102 + ((v99 - v102) & (~((v99 - v102) >> 31)))) + 1) + ((100 ^ (((~(((v108 ^ ((int)((unsigned int)((int)((unsigned int)v104 >> 2)) >> 1))) | (-(v108 ^ ((int)((unsigned int)((int)((unsigned int)v104 >> 2)) >> 1))))) >> 31)) | (~(((v109 ^ ((int)((unsigned int)((int)((unsigned int)v104 >> 2)) >> 1))) | (-(v109 ^ ((int)((unsigned int)((int)((unsigned int)v104 >> 2)) >> 1))))) >> 31))) & 104)) ^ (((~(((v106 ^ ((int)((unsigned int)((int)((unsigned int)v104 >> 2)) >> 1))) | (-(v106 ^ ((int)((unsigned int)((int)((unsigned int)v104 >> 2)) >> 1))))) >> 31)) | (~(((v107 ^ ((int)((unsigned int)((int)((unsigned int)v104 >> 2)) >> 1))) | (-(v107 ^ ((int)((unsigned int)((int)((unsigned int)v104 >> 2)) >> 1))))) >> 31))) & (1 ^ (100 ^ (((~(((v108 ^ ((int)((unsigned int)((int)((unsigned int)v104 >> 2)) >> 1))) | (-(v108 ^ ((int)((unsigned int)((int)((unsigned int)v104 >> 2)) >> 1))))) >> 31)) | (~(((v109 ^ ((int)((unsigned int)((int)((unsigned int)v104 >> 2)) >> 1))) | (-(v109 ^ ((int)((unsigned int)((int)((unsigned int)v104 >> 2)) >> 1))))) >> 31))) & 104)))));
  v205[5] = v301;
  int * v207 = v98->regs;
  v207[5] = v204;
  struct StateT * v209 = slot_6(v98);
  return v209;
}

struct StateT * slot_2(struct StateT * v34) {
  int v35 = v34->timer;
  int v43 = v35 + 1;
  v34->timer = v43;
  int * v37 = v34->reg_ready;
  v37[9] = v43;
  int * v39 = v34->regs;
  v39[9] = 80;
  struct StateT * v41 = slot_3(v34);
  return v41;
}

struct StateT * slot_7(struct StateT * v625) {
  int v626 = v625->timer;
  int v738 = v626 + 1;
  v625->timer = v738;
  int * v628 = v625->reg_ready;
  int v629 = v628[6];
  int * v630 = v625->regs;
  int v631 = v630[6];
  int * v632 = v625->cache_tags;
  int v743 = (((int)((unsigned int)((int)((unsigned int)v631 >> 2)) >> 1)) & 1) * 2;
  int v633 = v632[v743];
  int v744 = ((((int)((unsigned int)((int)((unsigned int)v631 >> 2)) >> 1)) & 1) * 2) + 1;
  int v634 = v632[v744];
  int v745 = 4 + ((((int)((unsigned int)((int)((unsigned int)v631 >> 2)) >> 1)) & 3) * 2);
  int v635 = v632[v745];
  int v746 = (4 + ((((int)((unsigned int)((int)((unsigned int)v631 >> 2)) >> 1)) & 3) * 2)) + 1;
  int v636 = v632[v746];
  int * v637 = v625->cache_vals;
  bool v747 = !(((~(((v633 ^ ((int)((unsigned int)((int)((unsigned int)v631 >> 2)) >> 1))) | (-(v633 ^ ((int)((unsigned int)((int)((unsigned int)v631 >> 2)) >> 1))))) >> 31)) | (~(((v634 ^ ((int)((unsigned int)((int)((unsigned int)v631 >> 2)) >> 1))) | (-(v634 ^ ((int)((unsigned int)((int)((unsigned int)v631 >> 2)) >> 1))))) >> 31))) == 0);
  int v730;
  if (v747) {
    int * v638 = v625->cache_age;
    int v749 = ((((int)((unsigned int)((int)((unsigned int)v631 >> 2)) >> 1)) & 1) * 2) + ((~(((v634 ^ ((int)((unsigned int)((int)((unsigned int)v631 >> 2)) >> 1))) | (-(v634 ^ ((int)((unsigned int)((int)((unsigned int)v631 >> 2)) >> 1))))) >> 31)) & 1);
    int v639 = v638[v749];
    int v640 = v638[v743];
    int v750 = v640 + ((int)((unsigned int)(v640 - v639) >> 31));
    v638[v743] = v750;
    int * v642 = v625->cache_age;
    int v643 = v642[v744];
    int v752 = v643 + ((int)((unsigned int)(v643 - v639) >> 31));
    v642[v744] = v752;
    int * v645 = v625->cache_age;
    v645[v749] = 0;
    v730 = v749;
  } else {
    int * v648 = v625->cache_age;
    int v756 = (((int)((unsigned int)((int)((unsigned int)v631 >> 2)) >> 1)) & 1) * 2;
    int v649 = v648[v756];
    int * v650 = v625->cache_tags;
    int v651 = v650[v756];
    int v652 = v648[v744];
    int v653 = v650[v744];
    bool v758 = !(((~(((v635 ^ ((int)((unsigned int)((int)((unsigned int)v631 >> 2)) >> 1))) | (-(v635 ^ ((int)((unsigned int)((int)((unsigned int)v631 >> 2)) >> 1))))) >> 31)) | (~(((v636 ^ ((int)((unsigned int)((int)((unsigned int)v631 >> 2)) >> 1))) | (-(v636 ^ ((int)((unsigned int)((int)((unsigned int)v631 >> 2)) >> 1))))) >> 31))) == 0);
    int v707;
    if (v758) {
      int * v654 = v625->cache_age;
      int v760 = (4 + ((((int)((unsigned int)((int)((unsigned int)v631 >> 2)) >> 1)) & 3) * 2)) + ((~(((v636 ^ ((int)((unsigned int)((int)((unsigned int)v631 >> 2)) >> 1))) | (-(v636 ^ ((int)((unsigned int)((int)((unsigned int)v631 >> 2)) >> 1))))) >> 31)) & 1);
      int v655 = v654[v760];
      int v656 = v654[v745];
      int v761 = v656 + ((int)((unsigned int)(v656 - v655) >> 31));
      v654[v745] = v761;
      int * v658 = v625->cache_age;
      int v659 = v658[v746];
      int v763 = v659 + ((int)((unsigned int)(v659 - v655) >> 31));
      v658[v746] = v763;
      int * v661 = v625->cache_age;
      v661[v760] = 0;
      v707 = v760;
    } else {
      int * v664 = v625->cache_age;
      int v767 = 4 + ((((int)((unsigned int)((int)((unsigned int)v631 >> 2)) >> 1)) & 3) * 2);
      int v665 = v664[v767];
      int * v666 = v625->cache_tags;
      int v667 = v666[v767];
      int v668 = v664[v746];
      int v669 = v666[v746];
      int * v670 = v625->cache_dirty;
      int v770 = (4 + ((((int)((unsigned int)((int)((unsigned int)v631 >> 2)) >> 1)) & 3) * 2)) + ((((v665 + ((~(((v667 ^ -1) | (-(v667 ^ -1))) >> 31)) & 2)) - (v668 + ((~(((v669 ^ -1) | (-(v669 ^ -1))) >> 31)) & 2))) >> 31) & 1);
      int v671 = v670[v770];
      bool v771 = !(v671 == 0);
      if (v771) {
        int * v672 = v625->cache_tags;
        int v673 = v672[v770];
        int * v674 = v625->cache_vals;
        int v774 = ((4 + ((((int)((unsigned int)((int)((unsigned int)v631 >> 2)) >> 1)) & 3) * 2)) + ((((v665 + ((~(((v667 ^ -1) | (-(v667 ^ -1))) >> 31)) & 2)) - (v668 + ((~(((v669 ^ -1) | (-(v669 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
        int v675 = v674[v774];
        int v775 = (((4 + ((((int)((unsigned int)((int)((unsigned int)v631 >> 2)) >> 1)) & 3) * 2)) + ((((v665 + ((~(((v667 ^ -1) | (-(v667 ^ -1))) >> 31)) & 2)) - (v668 + ((~(((v669 ^ -1) | (-(v669 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
        int v676 = v674[v775];
        int * v677 = v625->mem;
        int v777 = v673 * 2;
        v677[v777] = v675;
        int * v679 = v625->mem;
        int v780 = (v673 * 2) + 1;
        v679[v780] = v676;
        ;
      } else {
        ;
      }
      int * v684 = v625->mem;
      int v785 = ((int)((unsigned int)((int)((unsigned int)v631 >> 2)) >> 1)) * 2;
      int v685 = v684[v785];
      int v786 = (((int)((unsigned int)((int)((unsigned int)v631 >> 2)) >> 1)) * 2) + 1;
      int v686 = v684[v786];
      int * v687 = v625->cache_vals;
      int v788 = ((4 + ((((int)((unsigned int)((int)((unsigned int)v631 >> 2)) >> 1)) & 3) * 2)) + ((((v665 + ((~(((v667 ^ -1) | (-(v667 ^ -1))) >> 31)) & 2)) - (v668 + ((~(((v669 ^ -1) | (-(v669 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
      v687[v788] = v685;
      int * v689 = v625->cache_vals;
      int v791 = (((4 + ((((int)((unsigned int)((int)((unsigned int)v631 >> 2)) >> 1)) & 3) * 2)) + ((((v665 + ((~(((v667 ^ -1) | (-(v667 ^ -1))) >> 31)) & 2)) - (v668 + ((~(((v669 ^ -1) | (-(v669 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
      v689[v791] = v686;
      int * v691 = v625->cache_tags;
      int v794 = (int)((unsigned int)((int)((unsigned int)v631 >> 2)) >> 1);
      v691[v770] = v794;
      int * v693 = v625->cache_dirty;
      v693[v770] = 0;
      int * v695 = v625->cache_age;
      v695[v770] = 1;
      int * v697 = v625->cache_age;
      int v698 = v697[v770];
      int v699 = v697[v745];
      int v800 = v699 + ((int)((unsigned int)(v699 - v698) >> 31));
      v697[v745] = v800;
      int * v701 = v625->cache_age;
      int v702 = v701[v746];
      int v802 = v702 + ((int)((unsigned int)(v702 - v698) >> 31));
      v701[v746] = v802;
      int * v704 = v625->cache_age;
      v704[v770] = 0;
      v707 = v770;
    }
    int * v708 = v625->cache_vals;
    int v805 = v707 * 2;
    int v709 = v708[v805];
    int v806 = (v707 * 2) + 1;
    int v710 = v708[v806];
    int v807 = (((((int)((unsigned int)((int)((unsigned int)v631 >> 2)) >> 1)) & 1) * 2) + ((((v649 + ((~(((v651 ^ -1) | (-(v651 ^ -1))) >> 31)) & 2)) - (v652 + ((~(((v653 ^ -1) | (-(v653 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
    v708[v807] = v709;
    int * v712 = v625->cache_vals;
    int v810 = ((((((int)((unsigned int)((int)((unsigned int)v631 >> 2)) >> 1)) & 1) * 2) + ((((v649 + ((~(((v651 ^ -1) | (-(v651 ^ -1))) >> 31)) & 2)) - (v652 + ((~(((v653 ^ -1) | (-(v653 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
    v712[v810] = v710;
    int * v714 = v625->cache_tags;
    int v813 = ((((int)((unsigned int)((int)((unsigned int)v631 >> 2)) >> 1)) & 1) * 2) + ((((v649 + ((~(((v651 ^ -1) | (-(v651 ^ -1))) >> 31)) & 2)) - (v652 + ((~(((v653 ^ -1) | (-(v653 ^ -1))) >> 31)) & 2))) >> 31) & 1);
    int v814 = (int)((unsigned int)((int)((unsigned int)v631 >> 2)) >> 1);
    v714[v813] = v814;
    int * v716 = v625->cache_dirty;
    v716[v813] = 0;
    int * v718 = v625->cache_age;
    v718[v813] = 1;
    int * v720 = v625->cache_age;
    int v721 = v720[v813];
    int v722 = v720[v743];
    int v820 = v722 + ((int)((unsigned int)(v722 - v721) >> 31));
    v720[v743] = v820;
    int * v724 = v625->cache_age;
    int v725 = v724[v744];
    int v822 = v725 + ((int)((unsigned int)(v725 - v721) >> 31));
    v724[v744] = v822;
    int * v727 = v625->cache_age;
    v727[v813] = 0;
    v730 = v813;
  }
  int v825 = (v730 * 2) + (((int)((unsigned int)v631 >> 2)) & 1);
  int v731 = v637[v825];
  int * v732 = v625->reg_ready;
  int v828 = ((v629 + ((v626 - v629) & (~((v626 - v629) >> 31)))) + 1) + ((100 ^ (((~(((v635 ^ ((int)((unsigned int)((int)((unsigned int)v631 >> 2)) >> 1))) | (-(v635 ^ ((int)((unsigned int)((int)((unsigned int)v631 >> 2)) >> 1))))) >> 31)) | (~(((v636 ^ ((int)((unsigned int)((int)((unsigned int)v631 >> 2)) >> 1))) | (-(v636 ^ ((int)((unsigned int)((int)((unsigned int)v631 >> 2)) >> 1))))) >> 31))) & 104)) ^ (((~(((v633 ^ ((int)((unsigned int)((int)((unsigned int)v631 >> 2)) >> 1))) | (-(v633 ^ ((int)((unsigned int)((int)((unsigned int)v631 >> 2)) >> 1))))) >> 31)) | (~(((v634 ^ ((int)((unsigned int)((int)((unsigned int)v631 >> 2)) >> 1))) | (-(v634 ^ ((int)((unsigned int)((int)((unsigned int)v631 >> 2)) >> 1))))) >> 31))) & (1 ^ (100 ^ (((~(((v635 ^ ((int)((unsigned int)((int)((unsigned int)v631 >> 2)) >> 1))) | (-(v635 ^ ((int)((unsigned int)((int)((unsigned int)v631 >> 2)) >> 1))))) >> 31)) | (~(((v636 ^ ((int)((unsigned int)((int)((unsigned int)v631 >> 2)) >> 1))) | (-(v636 ^ ((int)((unsigned int)((int)((unsigned int)v631 >> 2)) >> 1))))) >> 31))) & 104)))));
  v732[11] = v828;
  int * v734 = v625->regs;
  v734[11] = v731;
  struct StateT * v736 = slot_8(v625);
  return v736;
}

struct StateT * slot_3(struct StateT * v50) {
  int v51 = v50->timer;
  int v64 = v51 + 1;
  v50->timer = v64;
  int * v53 = v50->reg_ready;
  int * v55 = v50->regs;
  int v56 = v55[6];
  int v58 = v55[7];
  bool v69 = v56 >= v58;
  struct StateT * v62;
  if (v69) {
    v62 = v50;
  } else {
    struct StateT * v60 = slot_4(v50);
    v62 = v60;
  }
  return v62;
}

struct StateT * snippet(struct StateT * v0) {
  struct StateT * v1 = slot_0(v0);
  int v862 = v1->timer;
  int * v863 = v1->reg_ready;
  int v864 = v863[0];
  int v995 = v864 + ((v862 - v864) & (~((v862 - v864) >> 31)));
  v1->timer = v995;
  int v866 = v1->timer;
  int * v867 = v1->reg_ready;
  int v868 = v867[1];
  int v998 = v868 + ((v866 - v868) & (~((v866 - v868) >> 31)));
  v1->timer = v998;
  int v870 = v1->timer;
  int * v871 = v1->reg_ready;
  int v872 = v871[2];
  int v1001 = v872 + ((v870 - v872) & (~((v870 - v872) >> 31)));
  v1->timer = v1001;
  int v874 = v1->timer;
  int * v875 = v1->reg_ready;
  int v876 = v875[3];
  int v1004 = v876 + ((v874 - v876) & (~((v874 - v876) >> 31)));
  v1->timer = v1004;
  int v878 = v1->timer;
  int * v879 = v1->reg_ready;
  int v880 = v879[4];
  int v1007 = v880 + ((v878 - v880) & (~((v878 - v880) >> 31)));
  v1->timer = v1007;
  int v882 = v1->timer;
  int * v883 = v1->reg_ready;
  int v884 = v883[5];
  int v1010 = v884 + ((v882 - v884) & (~((v882 - v884) >> 31)));
  v1->timer = v1010;
  int v886 = v1->timer;
  int * v887 = v1->reg_ready;
  int v888 = v887[6];
  int v1013 = v888 + ((v886 - v888) & (~((v886 - v888) >> 31)));
  v1->timer = v1013;
  int v890 = v1->timer;
  int * v891 = v1->reg_ready;
  int v892 = v891[7];
  int v1016 = v892 + ((v890 - v892) & (~((v890 - v892) >> 31)));
  v1->timer = v1016;
  int v894 = v1->timer;
  int * v895 = v1->reg_ready;
  int v896 = v895[8];
  int v1019 = v896 + ((v894 - v896) & (~((v894 - v896) >> 31)));
  v1->timer = v1019;
  int v898 = v1->timer;
  int * v899 = v1->reg_ready;
  int v900 = v899[9];
  int v1022 = v900 + ((v898 - v900) & (~((v898 - v900) >> 31)));
  v1->timer = v1022;
  int v902 = v1->timer;
  int * v903 = v1->reg_ready;
  int v904 = v903[10];
  int v1025 = v904 + ((v902 - v904) & (~((v902 - v904) >> 31)));
  v1->timer = v1025;
  int v906 = v1->timer;
  int * v907 = v1->reg_ready;
  int v908 = v907[11];
  int v1028 = v908 + ((v906 - v908) & (~((v906 - v908) >> 31)));
  v1->timer = v1028;
  int v910 = v1->timer;
  int * v911 = v1->reg_ready;
  int v912 = v911[12];
  int v1031 = v912 + ((v910 - v912) & (~((v910 - v912) >> 31)));
  v1->timer = v1031;
  int v914 = v1->timer;
  int * v915 = v1->reg_ready;
  int v916 = v915[13];
  int v1034 = v916 + ((v914 - v916) & (~((v914 - v916) >> 31)));
  v1->timer = v1034;
  int v918 = v1->timer;
  int * v919 = v1->reg_ready;
  int v920 = v919[14];
  int v1037 = v920 + ((v918 - v920) & (~((v918 - v920) >> 31)));
  v1->timer = v1037;
  int v922 = v1->timer;
  int * v923 = v1->reg_ready;
  int v924 = v923[15];
  int v1040 = v924 + ((v922 - v924) & (~((v922 - v924) >> 31)));
  v1->timer = v1040;
  int v926 = v1->timer;
  int * v927 = v1->reg_ready;
  int v928 = v927[16];
  int v1043 = v928 + ((v926 - v928) & (~((v926 - v928) >> 31)));
  v1->timer = v1043;
  int v930 = v1->timer;
  int * v931 = v1->reg_ready;
  int v932 = v931[17];
  int v1046 = v932 + ((v930 - v932) & (~((v930 - v932) >> 31)));
  v1->timer = v1046;
  int v934 = v1->timer;
  int * v935 = v1->reg_ready;
  int v936 = v935[18];
  int v1049 = v936 + ((v934 - v936) & (~((v934 - v936) >> 31)));
  v1->timer = v1049;
  int v938 = v1->timer;
  int * v939 = v1->reg_ready;
  int v940 = v939[19];
  int v1052 = v940 + ((v938 - v940) & (~((v938 - v940) >> 31)));
  v1->timer = v1052;
  int v942 = v1->timer;
  int * v943 = v1->reg_ready;
  int v944 = v943[20];
  int v1055 = v944 + ((v942 - v944) & (~((v942 - v944) >> 31)));
  v1->timer = v1055;
  int v946 = v1->timer;
  int * v947 = v1->reg_ready;
  int v948 = v947[21];
  int v1058 = v948 + ((v946 - v948) & (~((v946 - v948) >> 31)));
  v1->timer = v1058;
  int v950 = v1->timer;
  int * v951 = v1->reg_ready;
  int v952 = v951[22];
  int v1061 = v952 + ((v950 - v952) & (~((v950 - v952) >> 31)));
  v1->timer = v1061;
  int v954 = v1->timer;
  int * v955 = v1->reg_ready;
  int v956 = v955[23];
  int v1064 = v956 + ((v954 - v956) & (~((v954 - v956) >> 31)));
  v1->timer = v1064;
  int v958 = v1->timer;
  int * v959 = v1->reg_ready;
  int v960 = v959[24];
  int v1067 = v960 + ((v958 - v960) & (~((v958 - v960) >> 31)));
  v1->timer = v1067;
  int v962 = v1->timer;
  int * v963 = v1->reg_ready;
  int v964 = v963[25];
  int v1070 = v964 + ((v962 - v964) & (~((v962 - v964) >> 31)));
  v1->timer = v1070;
  int v966 = v1->timer;
  int * v967 = v1->reg_ready;
  int v968 = v967[26];
  int v1073 = v968 + ((v966 - v968) & (~((v966 - v968) >> 31)));
  v1->timer = v1073;
  int v970 = v1->timer;
  int * v971 = v1->reg_ready;
  int v972 = v971[27];
  int v1076 = v972 + ((v970 - v972) & (~((v970 - v972) >> 31)));
  v1->timer = v1076;
  int v974 = v1->timer;
  int * v975 = v1->reg_ready;
  int v976 = v975[28];
  int v1079 = v976 + ((v974 - v976) & (~((v974 - v976) >> 31)));
  v1->timer = v1079;
  int v978 = v1->timer;
  int * v979 = v1->reg_ready;
  int v980 = v979[29];
  int v1082 = v980 + ((v978 - v980) & (~((v978 - v980) >> 31)));
  v1->timer = v1082;
  int v982 = v1->timer;
  int * v983 = v1->reg_ready;
  int v984 = v983[30];
  int v1085 = v984 + ((v982 - v984) & (~((v982 - v984) >> 31)));
  v1->timer = v1085;
  int v986 = v1->timer;
  int * v987 = v1->reg_ready;
  int v988 = v987[31];
  int v1088 = v988 + ((v986 - v988) & (~((v986 - v988) >> 31)));
  v1->timer = v1088;
  return v1;
}

struct StateT * slot_1(struct StateT * v18) {
  int v19 = v18->timer;
  int v27 = v19 + 1;
  v18->timer = v27;
  int * v21 = v18->reg_ready;
  v21[7] = v27;
  int * v23 = v18->regs;
  v23[7] = 16;
  struct StateT * v25 = slot_2(v18);
  return v25;
}

struct StateT * slot_8(struct StateT * v833) {
  int v834 = v833->timer;
  int v845 = v834 + 1;
  v833->timer = v845;
  int * v836 = v833->reg_ready;
  int v837 = v836[6];
  int * v838 = v833->regs;
  int v839 = v838[6];
  int v849 = (v837 + ((v834 - v837) & (~((v834 - v837) >> 31)))) + 1;
  v836[6] = v849;
  int * v841 = v833->regs;
  int v851 = v839 + 4;
  v841[6] = v851;
  struct StateT * v843 = slot_9(v833);
  return v843;
}

struct StateT * slot_4(struct StateT * v73) {
  int v74 = v73->timer;
  int v87 = v74 + 1;
  v73->timer = v87;
  int * v76 = v73->reg_ready;
  int v77 = v76[9];
  int * v78 = v73->regs;
  int v79 = v78[9];
  int v80 = v76[6];
  int v81 = v78[6];
  int v93 = (v80 + (((v77 + ((v74 - v77) & (~((v74 - v77) >> 31)))) - v80) & (~(((v77 + ((v74 - v77) & (~((v74 - v77) >> 31)))) - v80) >> 31)))) + 1;
  v76[8] = v93;
  int * v83 = v73->regs;
  int v95 = v79 + v81;
  v83[8] = v95;
  struct StateT * v85 = slot_5(v73);
  return v85;
}

struct StateT * slot_9(struct StateT * v854) {
  int v855 = v854->timer;
  int v859 = v855 + 1;
  v854->timer = v859;
  struct StateT * v857 = slot_3(v854);
  return v857;
}

struct StateT * slot_0(struct StateT * v2) {
  int v3 = v2->timer;
  int v11 = v3 + 1;
  v2->timer = v11;
  int * v5 = v2->reg_ready;
  v5[6] = v11;
  int * v7 = v2->regs;
  v7[6] = 0;
  struct StateT * v9 = slot_1(v2);
  return v9;
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
    s1.mem[SECRET_OFFSET+i] = secret(0, 20);
    s2.mem[SECRET_OFFSET+i] = secret(0, 20);
  }
  struct StateT *s1_ = snippet(&s1);
  struct StateT *s2_ = snippet(&s2);
  koika_assert(s1_->timer==s2_->timer, "timing leak");
  return 0;
}