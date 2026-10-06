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

struct StateT * slot_6(struct StateT * v477);
struct StateT * slot_5(struct StateT * v273);
struct StateT * slot_2(struct StateT * v28);
struct StateT * slot_7(struct StateT * v491);
struct StateT * slot_3(struct StateT * v41);
struct StateT * snippet(struct StateT * v0);
struct StateT * slot_1(struct StateT * v15);
struct StateT * slot_8(struct StateT * v63);
struct StateT * slot_4(struct StateT * v71);
struct StateT * slot_9(struct StateT * v88);
struct StateT * slot_0(struct StateT * v2);
struct StateT * slot_6(struct StateT * v477) {
  int v478 = v477->timer;
  int v485 = v478 + 1;
  v477->timer = v485;
  int * v480 = v477->regs;
  int v481 = v480[11];
  int v488 = v481 << 2;
  v480[11] = v488;
  struct StateT * v483 = slot_7(v477);
  return v483;
}

struct StateT * slot_5(struct StateT * v273) {
  int v274 = v273->timer;
  int v384 = v274 + 1;
  v273->timer = v384;
  int * v276 = v273->regs;
  int v277 = v276[5];
  int * v278 = v273->cache_tags;
  int v388 = (((int)((unsigned int)((int)((unsigned int)v277 >> 2)) >> 1)) & 1) * 2;
  int v279 = v278[v388];
  int v389 = ((((int)((unsigned int)((int)((unsigned int)v277 >> 2)) >> 1)) & 1) * 2) + 1;
  int v280 = v278[v389];
  int v390 = 4 + ((((int)((unsigned int)((int)((unsigned int)v277 >> 2)) >> 1)) & 3) * 2);
  int v281 = v278[v390];
  int v391 = (4 + ((((int)((unsigned int)((int)((unsigned int)v277 >> 2)) >> 1)) & 3) * 2)) + 1;
  int v282 = v278[v391];
  int v283 = v273->timer;
  int v392 = v283 + ((100 ^ (((~(((v281 ^ ((int)((unsigned int)((int)((unsigned int)v277 >> 2)) >> 1))) | (-(v281 ^ ((int)((unsigned int)((int)((unsigned int)v277 >> 2)) >> 1))))) >> 31)) | (~(((v282 ^ ((int)((unsigned int)((int)((unsigned int)v277 >> 2)) >> 1))) | (-(v282 ^ ((int)((unsigned int)((int)((unsigned int)v277 >> 2)) >> 1))))) >> 31))) & 104)) ^ (((~(((v279 ^ ((int)((unsigned int)((int)((unsigned int)v277 >> 2)) >> 1))) | (-(v279 ^ ((int)((unsigned int)((int)((unsigned int)v277 >> 2)) >> 1))))) >> 31)) | (~(((v280 ^ ((int)((unsigned int)((int)((unsigned int)v277 >> 2)) >> 1))) | (-(v280 ^ ((int)((unsigned int)((int)((unsigned int)v277 >> 2)) >> 1))))) >> 31))) & (1 ^ (100 ^ (((~(((v281 ^ ((int)((unsigned int)((int)((unsigned int)v277 >> 2)) >> 1))) | (-(v281 ^ ((int)((unsigned int)((int)((unsigned int)v277 >> 2)) >> 1))))) >> 31)) | (~(((v282 ^ ((int)((unsigned int)((int)((unsigned int)v277 >> 2)) >> 1))) | (-(v282 ^ ((int)((unsigned int)((int)((unsigned int)v277 >> 2)) >> 1))))) >> 31))) & 104)))));
  v273->timer = v392;
  int * v285 = v273->cache_vals;
  bool v393 = !(((~(((v279 ^ ((int)((unsigned int)((int)((unsigned int)v277 >> 2)) >> 1))) | (-(v279 ^ ((int)((unsigned int)((int)((unsigned int)v277 >> 2)) >> 1))))) >> 31)) | (~(((v280 ^ ((int)((unsigned int)((int)((unsigned int)v277 >> 2)) >> 1))) | (-(v280 ^ ((int)((unsigned int)((int)((unsigned int)v277 >> 2)) >> 1))))) >> 31))) == 0);
  int v378;
  if (v393) {
    int * v286 = v273->cache_age;
    int v395 = ((((int)((unsigned int)((int)((unsigned int)v277 >> 2)) >> 1)) & 1) * 2) + ((~(((v280 ^ ((int)((unsigned int)((int)((unsigned int)v277 >> 2)) >> 1))) | (-(v280 ^ ((int)((unsigned int)((int)((unsigned int)v277 >> 2)) >> 1))))) >> 31)) & 1);
    int v287 = v286[v395];
    int v288 = v286[v388];
    int v396 = v288 + ((int)((unsigned int)(v288 - v287) >> 31));
    v286[v388] = v396;
    int * v290 = v273->cache_age;
    int v291 = v290[v389];
    int v398 = v291 + ((int)((unsigned int)(v291 - v287) >> 31));
    v290[v389] = v398;
    int * v293 = v273->cache_age;
    v293[v395] = 0;
    v378 = v395;
  } else {
    int * v296 = v273->cache_age;
    int v402 = (((int)((unsigned int)((int)((unsigned int)v277 >> 2)) >> 1)) & 1) * 2;
    int v297 = v296[v402];
    int * v298 = v273->cache_tags;
    int v299 = v298[v402];
    int v300 = v296[v389];
    int v301 = v298[v389];
    bool v404 = !(((~(((v281 ^ ((int)((unsigned int)((int)((unsigned int)v277 >> 2)) >> 1))) | (-(v281 ^ ((int)((unsigned int)((int)((unsigned int)v277 >> 2)) >> 1))))) >> 31)) | (~(((v282 ^ ((int)((unsigned int)((int)((unsigned int)v277 >> 2)) >> 1))) | (-(v282 ^ ((int)((unsigned int)((int)((unsigned int)v277 >> 2)) >> 1))))) >> 31))) == 0);
    int v355;
    if (v404) {
      int * v302 = v273->cache_age;
      int v406 = (4 + ((((int)((unsigned int)((int)((unsigned int)v277 >> 2)) >> 1)) & 3) * 2)) + ((~(((v282 ^ ((int)((unsigned int)((int)((unsigned int)v277 >> 2)) >> 1))) | (-(v282 ^ ((int)((unsigned int)((int)((unsigned int)v277 >> 2)) >> 1))))) >> 31)) & 1);
      int v303 = v302[v406];
      int v304 = v302[v390];
      int v407 = v304 + ((int)((unsigned int)(v304 - v303) >> 31));
      v302[v390] = v407;
      int * v306 = v273->cache_age;
      int v307 = v306[v391];
      int v409 = v307 + ((int)((unsigned int)(v307 - v303) >> 31));
      v306[v391] = v409;
      int * v309 = v273->cache_age;
      v309[v406] = 0;
      v355 = v406;
    } else {
      int * v312 = v273->cache_age;
      int v413 = 4 + ((((int)((unsigned int)((int)((unsigned int)v277 >> 2)) >> 1)) & 3) * 2);
      int v313 = v312[v413];
      int * v314 = v273->cache_tags;
      int v315 = v314[v413];
      int v316 = v312[v391];
      int v317 = v314[v391];
      int * v318 = v273->cache_dirty;
      int v416 = (4 + ((((int)((unsigned int)((int)((unsigned int)v277 >> 2)) >> 1)) & 3) * 2)) + ((((v313 + ((~(((v315 ^ -1) | (-(v315 ^ -1))) >> 31)) & 2)) - (v316 + ((~(((v317 ^ -1) | (-(v317 ^ -1))) >> 31)) & 2))) >> 31) & 1);
      int v319 = v318[v416];
      bool v417 = !(v319 == 0);
      if (v417) {
        int * v320 = v273->cache_tags;
        int v321 = v320[v416];
        int * v322 = v273->cache_vals;
        int v420 = ((4 + ((((int)((unsigned int)((int)((unsigned int)v277 >> 2)) >> 1)) & 3) * 2)) + ((((v313 + ((~(((v315 ^ -1) | (-(v315 ^ -1))) >> 31)) & 2)) - (v316 + ((~(((v317 ^ -1) | (-(v317 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
        int v323 = v322[v420];
        int v421 = (((4 + ((((int)((unsigned int)((int)((unsigned int)v277 >> 2)) >> 1)) & 3) * 2)) + ((((v313 + ((~(((v315 ^ -1) | (-(v315 ^ -1))) >> 31)) & 2)) - (v316 + ((~(((v317 ^ -1) | (-(v317 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
        int v324 = v322[v421];
        int * v325 = v273->mem;
        int v423 = v321 * 2;
        v325[v423] = v323;
        int * v327 = v273->mem;
        int v426 = (v321 * 2) + 1;
        v327[v426] = v324;
        ;
      } else {
        ;
      }
      int * v332 = v273->mem;
      int v431 = ((int)((unsigned int)((int)((unsigned int)v277 >> 2)) >> 1)) * 2;
      int v333 = v332[v431];
      int v432 = (((int)((unsigned int)((int)((unsigned int)v277 >> 2)) >> 1)) * 2) + 1;
      int v334 = v332[v432];
      int * v335 = v273->cache_vals;
      int v434 = ((4 + ((((int)((unsigned int)((int)((unsigned int)v277 >> 2)) >> 1)) & 3) * 2)) + ((((v313 + ((~(((v315 ^ -1) | (-(v315 ^ -1))) >> 31)) & 2)) - (v316 + ((~(((v317 ^ -1) | (-(v317 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
      v335[v434] = v333;
      int * v337 = v273->cache_vals;
      int v437 = (((4 + ((((int)((unsigned int)((int)((unsigned int)v277 >> 2)) >> 1)) & 3) * 2)) + ((((v313 + ((~(((v315 ^ -1) | (-(v315 ^ -1))) >> 31)) & 2)) - (v316 + ((~(((v317 ^ -1) | (-(v317 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
      v337[v437] = v334;
      int * v339 = v273->cache_tags;
      int v440 = (int)((unsigned int)((int)((unsigned int)v277 >> 2)) >> 1);
      v339[v416] = v440;
      int * v341 = v273->cache_dirty;
      v341[v416] = 0;
      int * v343 = v273->cache_age;
      v343[v416] = 1;
      int * v345 = v273->cache_age;
      int v346 = v345[v416];
      int v347 = v345[v390];
      int v446 = v347 + ((int)((unsigned int)(v347 - v346) >> 31));
      v345[v390] = v446;
      int * v349 = v273->cache_age;
      int v350 = v349[v391];
      int v448 = v350 + ((int)((unsigned int)(v350 - v346) >> 31));
      v349[v391] = v448;
      int * v352 = v273->cache_age;
      v352[v416] = 0;
      v355 = v416;
    }
    int * v356 = v273->cache_vals;
    int v451 = v355 * 2;
    int v357 = v356[v451];
    int v452 = (v355 * 2) + 1;
    int v358 = v356[v452];
    int v453 = (((((int)((unsigned int)((int)((unsigned int)v277 >> 2)) >> 1)) & 1) * 2) + ((((v297 + ((~(((v299 ^ -1) | (-(v299 ^ -1))) >> 31)) & 2)) - (v300 + ((~(((v301 ^ -1) | (-(v301 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
    v356[v453] = v357;
    int * v360 = v273->cache_vals;
    int v456 = ((((((int)((unsigned int)((int)((unsigned int)v277 >> 2)) >> 1)) & 1) * 2) + ((((v297 + ((~(((v299 ^ -1) | (-(v299 ^ -1))) >> 31)) & 2)) - (v300 + ((~(((v301 ^ -1) | (-(v301 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
    v360[v456] = v358;
    int * v362 = v273->cache_tags;
    int v459 = ((((int)((unsigned int)((int)((unsigned int)v277 >> 2)) >> 1)) & 1) * 2) + ((((v297 + ((~(((v299 ^ -1) | (-(v299 ^ -1))) >> 31)) & 2)) - (v300 + ((~(((v301 ^ -1) | (-(v301 ^ -1))) >> 31)) & 2))) >> 31) & 1);
    int v460 = (int)((unsigned int)((int)((unsigned int)v277 >> 2)) >> 1);
    v362[v459] = v460;
    int * v364 = v273->cache_dirty;
    v364[v459] = 0;
    int * v366 = v273->cache_age;
    v366[v459] = 1;
    int * v368 = v273->cache_age;
    int v369 = v368[v459];
    int v370 = v368[v388];
    int v466 = v370 + ((int)((unsigned int)(v370 - v369) >> 31));
    v368[v388] = v466;
    int * v372 = v273->cache_age;
    int v373 = v372[v389];
    int v468 = v373 + ((int)((unsigned int)(v373 - v369) >> 31));
    v372[v389] = v468;
    int * v375 = v273->cache_age;
    v375[v459] = 0;
    v378 = v459;
  }
  int v471 = (v378 * 2) + (((int)((unsigned int)v277 >> 2)) & 1);
  int v379 = v285[v471];
  int * v380 = v273->regs;
  v380[11] = v379;
  struct StateT * v382 = slot_6(v273);
  return v382;
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

struct StateT * slot_7(struct StateT * v491) {
  int v492 = v491->timer;
  int v602 = v492 + 1;
  v491->timer = v602;
  int * v494 = v491->regs;
  int v495 = v494[11];
  int * v496 = v491->cache_tags;
  int v606 = (((int)((unsigned int)((int)((unsigned int)v495 >> 2)) >> 1)) & 1) * 2;
  int v497 = v496[v606];
  int v607 = ((((int)((unsigned int)((int)((unsigned int)v495 >> 2)) >> 1)) & 1) * 2) + 1;
  int v498 = v496[v607];
  int v608 = 4 + ((((int)((unsigned int)((int)((unsigned int)v495 >> 2)) >> 1)) & 3) * 2);
  int v499 = v496[v608];
  int v609 = (4 + ((((int)((unsigned int)((int)((unsigned int)v495 >> 2)) >> 1)) & 3) * 2)) + 1;
  int v500 = v496[v609];
  int v501 = v491->timer;
  int v610 = v501 + ((100 ^ (((~(((v499 ^ ((int)((unsigned int)((int)((unsigned int)v495 >> 2)) >> 1))) | (-(v499 ^ ((int)((unsigned int)((int)((unsigned int)v495 >> 2)) >> 1))))) >> 31)) | (~(((v500 ^ ((int)((unsigned int)((int)((unsigned int)v495 >> 2)) >> 1))) | (-(v500 ^ ((int)((unsigned int)((int)((unsigned int)v495 >> 2)) >> 1))))) >> 31))) & 104)) ^ (((~(((v497 ^ ((int)((unsigned int)((int)((unsigned int)v495 >> 2)) >> 1))) | (-(v497 ^ ((int)((unsigned int)((int)((unsigned int)v495 >> 2)) >> 1))))) >> 31)) | (~(((v498 ^ ((int)((unsigned int)((int)((unsigned int)v495 >> 2)) >> 1))) | (-(v498 ^ ((int)((unsigned int)((int)((unsigned int)v495 >> 2)) >> 1))))) >> 31))) & (1 ^ (100 ^ (((~(((v499 ^ ((int)((unsigned int)((int)((unsigned int)v495 >> 2)) >> 1))) | (-(v499 ^ ((int)((unsigned int)((int)((unsigned int)v495 >> 2)) >> 1))))) >> 31)) | (~(((v500 ^ ((int)((unsigned int)((int)((unsigned int)v495 >> 2)) >> 1))) | (-(v500 ^ ((int)((unsigned int)((int)((unsigned int)v495 >> 2)) >> 1))))) >> 31))) & 104)))));
  v491->timer = v610;
  int * v503 = v491->cache_vals;
  bool v611 = !(((~(((v497 ^ ((int)((unsigned int)((int)((unsigned int)v495 >> 2)) >> 1))) | (-(v497 ^ ((int)((unsigned int)((int)((unsigned int)v495 >> 2)) >> 1))))) >> 31)) | (~(((v498 ^ ((int)((unsigned int)((int)((unsigned int)v495 >> 2)) >> 1))) | (-(v498 ^ ((int)((unsigned int)((int)((unsigned int)v495 >> 2)) >> 1))))) >> 31))) == 0);
  int v596;
  if (v611) {
    int * v504 = v491->cache_age;
    int v613 = ((((int)((unsigned int)((int)((unsigned int)v495 >> 2)) >> 1)) & 1) * 2) + ((~(((v498 ^ ((int)((unsigned int)((int)((unsigned int)v495 >> 2)) >> 1))) | (-(v498 ^ ((int)((unsigned int)((int)((unsigned int)v495 >> 2)) >> 1))))) >> 31)) & 1);
    int v505 = v504[v613];
    int v506 = v504[v606];
    int v614 = v506 + ((int)((unsigned int)(v506 - v505) >> 31));
    v504[v606] = v614;
    int * v508 = v491->cache_age;
    int v509 = v508[v607];
    int v616 = v509 + ((int)((unsigned int)(v509 - v505) >> 31));
    v508[v607] = v616;
    int * v511 = v491->cache_age;
    v511[v613] = 0;
    v596 = v613;
  } else {
    int * v514 = v491->cache_age;
    int v620 = (((int)((unsigned int)((int)((unsigned int)v495 >> 2)) >> 1)) & 1) * 2;
    int v515 = v514[v620];
    int * v516 = v491->cache_tags;
    int v517 = v516[v620];
    int v518 = v514[v607];
    int v519 = v516[v607];
    bool v622 = !(((~(((v499 ^ ((int)((unsigned int)((int)((unsigned int)v495 >> 2)) >> 1))) | (-(v499 ^ ((int)((unsigned int)((int)((unsigned int)v495 >> 2)) >> 1))))) >> 31)) | (~(((v500 ^ ((int)((unsigned int)((int)((unsigned int)v495 >> 2)) >> 1))) | (-(v500 ^ ((int)((unsigned int)((int)((unsigned int)v495 >> 2)) >> 1))))) >> 31))) == 0);
    int v573;
    if (v622) {
      int * v520 = v491->cache_age;
      int v624 = (4 + ((((int)((unsigned int)((int)((unsigned int)v495 >> 2)) >> 1)) & 3) * 2)) + ((~(((v500 ^ ((int)((unsigned int)((int)((unsigned int)v495 >> 2)) >> 1))) | (-(v500 ^ ((int)((unsigned int)((int)((unsigned int)v495 >> 2)) >> 1))))) >> 31)) & 1);
      int v521 = v520[v624];
      int v522 = v520[v608];
      int v625 = v522 + ((int)((unsigned int)(v522 - v521) >> 31));
      v520[v608] = v625;
      int * v524 = v491->cache_age;
      int v525 = v524[v609];
      int v627 = v525 + ((int)((unsigned int)(v525 - v521) >> 31));
      v524[v609] = v627;
      int * v527 = v491->cache_age;
      v527[v624] = 0;
      v573 = v624;
    } else {
      int * v530 = v491->cache_age;
      int v631 = 4 + ((((int)((unsigned int)((int)((unsigned int)v495 >> 2)) >> 1)) & 3) * 2);
      int v531 = v530[v631];
      int * v532 = v491->cache_tags;
      int v533 = v532[v631];
      int v534 = v530[v609];
      int v535 = v532[v609];
      int * v536 = v491->cache_dirty;
      int v634 = (4 + ((((int)((unsigned int)((int)((unsigned int)v495 >> 2)) >> 1)) & 3) * 2)) + ((((v531 + ((~(((v533 ^ -1) | (-(v533 ^ -1))) >> 31)) & 2)) - (v534 + ((~(((v535 ^ -1) | (-(v535 ^ -1))) >> 31)) & 2))) >> 31) & 1);
      int v537 = v536[v634];
      bool v635 = !(v537 == 0);
      if (v635) {
        int * v538 = v491->cache_tags;
        int v539 = v538[v634];
        int * v540 = v491->cache_vals;
        int v638 = ((4 + ((((int)((unsigned int)((int)((unsigned int)v495 >> 2)) >> 1)) & 3) * 2)) + ((((v531 + ((~(((v533 ^ -1) | (-(v533 ^ -1))) >> 31)) & 2)) - (v534 + ((~(((v535 ^ -1) | (-(v535 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
        int v541 = v540[v638];
        int v639 = (((4 + ((((int)((unsigned int)((int)((unsigned int)v495 >> 2)) >> 1)) & 3) * 2)) + ((((v531 + ((~(((v533 ^ -1) | (-(v533 ^ -1))) >> 31)) & 2)) - (v534 + ((~(((v535 ^ -1) | (-(v535 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
        int v542 = v540[v639];
        int * v543 = v491->mem;
        int v641 = v539 * 2;
        v543[v641] = v541;
        int * v545 = v491->mem;
        int v644 = (v539 * 2) + 1;
        v545[v644] = v542;
        ;
      } else {
        ;
      }
      int * v550 = v491->mem;
      int v649 = ((int)((unsigned int)((int)((unsigned int)v495 >> 2)) >> 1)) * 2;
      int v551 = v550[v649];
      int v650 = (((int)((unsigned int)((int)((unsigned int)v495 >> 2)) >> 1)) * 2) + 1;
      int v552 = v550[v650];
      int * v553 = v491->cache_vals;
      int v652 = ((4 + ((((int)((unsigned int)((int)((unsigned int)v495 >> 2)) >> 1)) & 3) * 2)) + ((((v531 + ((~(((v533 ^ -1) | (-(v533 ^ -1))) >> 31)) & 2)) - (v534 + ((~(((v535 ^ -1) | (-(v535 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
      v553[v652] = v551;
      int * v555 = v491->cache_vals;
      int v655 = (((4 + ((((int)((unsigned int)((int)((unsigned int)v495 >> 2)) >> 1)) & 3) * 2)) + ((((v531 + ((~(((v533 ^ -1) | (-(v533 ^ -1))) >> 31)) & 2)) - (v534 + ((~(((v535 ^ -1) | (-(v535 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
      v555[v655] = v552;
      int * v557 = v491->cache_tags;
      int v658 = (int)((unsigned int)((int)((unsigned int)v495 >> 2)) >> 1);
      v557[v634] = v658;
      int * v559 = v491->cache_dirty;
      v559[v634] = 0;
      int * v561 = v491->cache_age;
      v561[v634] = 1;
      int * v563 = v491->cache_age;
      int v564 = v563[v634];
      int v565 = v563[v608];
      int v664 = v565 + ((int)((unsigned int)(v565 - v564) >> 31));
      v563[v608] = v664;
      int * v567 = v491->cache_age;
      int v568 = v567[v609];
      int v666 = v568 + ((int)((unsigned int)(v568 - v564) >> 31));
      v567[v609] = v666;
      int * v570 = v491->cache_age;
      v570[v634] = 0;
      v573 = v634;
    }
    int * v574 = v491->cache_vals;
    int v669 = v573 * 2;
    int v575 = v574[v669];
    int v670 = (v573 * 2) + 1;
    int v576 = v574[v670];
    int v671 = (((((int)((unsigned int)((int)((unsigned int)v495 >> 2)) >> 1)) & 1) * 2) + ((((v515 + ((~(((v517 ^ -1) | (-(v517 ^ -1))) >> 31)) & 2)) - (v518 + ((~(((v519 ^ -1) | (-(v519 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
    v574[v671] = v575;
    int * v578 = v491->cache_vals;
    int v674 = ((((((int)((unsigned int)((int)((unsigned int)v495 >> 2)) >> 1)) & 1) * 2) + ((((v515 + ((~(((v517 ^ -1) | (-(v517 ^ -1))) >> 31)) & 2)) - (v518 + ((~(((v519 ^ -1) | (-(v519 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
    v578[v674] = v576;
    int * v580 = v491->cache_tags;
    int v677 = ((((int)((unsigned int)((int)((unsigned int)v495 >> 2)) >> 1)) & 1) * 2) + ((((v515 + ((~(((v517 ^ -1) | (-(v517 ^ -1))) >> 31)) & 2)) - (v518 + ((~(((v519 ^ -1) | (-(v519 ^ -1))) >> 31)) & 2))) >> 31) & 1);
    int v678 = (int)((unsigned int)((int)((unsigned int)v495 >> 2)) >> 1);
    v580[v677] = v678;
    int * v582 = v491->cache_dirty;
    v582[v677] = 0;
    int * v584 = v491->cache_age;
    v584[v677] = 1;
    int * v586 = v491->cache_age;
    int v587 = v586[v677];
    int v588 = v586[v606];
    int v684 = v588 + ((int)((unsigned int)(v588 - v587) >> 31));
    v586[v606] = v684;
    int * v590 = v491->cache_age;
    int v591 = v590[v607];
    int v686 = v591 + ((int)((unsigned int)(v591 - v587) >> 31));
    v590[v607] = v686;
    int * v593 = v491->cache_age;
    v593[v677] = 0;
    v596 = v677;
  }
  int v689 = (v596 * 2) + (((int)((unsigned int)v495 >> 2)) & 1);
  int v597 = v503[v689];
  int * v598 = v491->regs;
  v598[12] = v597;
  struct StateT * v600 = slot_8(v491);
  return v600;
}

struct StateT * slot_3(struct StateT * v41) {
  int v42 = v41->timer;
  int v53 = v42 + 1;
  v41->timer = v53;
  int * v44 = v41->regs;
  int v45 = v44[10];
  int v46 = v44[15];
  bool v57 = v45 >= v46;
  struct StateT * v51;
  if (v57) {
    struct StateT * v47 = slot_8(v41);
    v51 = v47;
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
  v18[10] = 80;
  struct StateT * v20 = slot_2(v15);
  return v20;
}

struct StateT * slot_8(struct StateT * v63) {
  int v64 = v63->timer;
  int v68 = v64 + 1;
  v63->timer = v68;
  struct StateT * v66 = slot_9(v63);
  return v66;
}

struct StateT * slot_4(struct StateT * v71) {
  int v72 = v71->timer;
  int v80 = v72 + 1;
  v71->timer = v80;
  int * v74 = v71->regs;
  int v75 = v74[13];
  int v76 = v74[10];
  int v85 = v75 + v76;
  v74[5] = v85;
  struct StateT * v78 = slot_5(v71);
  return v78;
}

struct StateT * slot_9(struct StateT * v88) {
  int v89 = v88->timer;
  int v196 = v89 + 1;
  v88->timer = v196;
  int * v91 = v88->cache_tags;
  int v92 = v91[0];
  int v93 = v91[1];
  int v94 = v91[4];
  int v95 = v91[5];
  int v96 = v88->timer;
  int v202 = v96 + ((100 ^ (((~((v94 | (-v94)) >> 31)) | (~((v95 | (-v95)) >> 31))) & 104)) ^ (((~((v92 | (-v92)) >> 31)) | (~((v93 | (-v93)) >> 31))) & (1 ^ (100 ^ (((~((v94 | (-v94)) >> 31)) | (~((v95 | (-v95)) >> 31))) & 104)))));
  v88->timer = v202;
  int * v98 = v88->cache_vals;
  bool v203 = !(((~((v92 | (-v92)) >> 31)) | (~((v93 | (-v93)) >> 31))) == 0);
  int v191;
  if (v203) {
    int * v99 = v88->cache_age;
    int v205 = (~((v93 | (-v93)) >> 31)) & 1;
    int v100 = v99[v205];
    int v101 = v99[0];
    int v206 = v101 + ((int)((unsigned int)(v101 - v100) >> 31));
    v99[0] = v206;
    int * v103 = v88->cache_age;
    int v104 = v103[1];
    int v208 = v104 + ((int)((unsigned int)(v104 - v100) >> 31));
    v103[1] = v208;
    int * v106 = v88->cache_age;
    v106[v205] = 0;
    v191 = v205;
  } else {
    int * v109 = v88->cache_age;
    int v110 = v109[0];
    int * v111 = v88->cache_tags;
    int v112 = v111[0];
    int v113 = v109[1];
    int v114 = v111[1];
    bool v212 = !(((~((v94 | (-v94)) >> 31)) | (~((v95 | (-v95)) >> 31))) == 0);
    int v168;
    if (v212) {
      int * v115 = v88->cache_age;
      int v214 = 4 + ((~((v95 | (-v95)) >> 31)) & 1);
      int v116 = v115[v214];
      int v117 = v115[4];
      int v215 = v117 + ((int)((unsigned int)(v117 - v116) >> 31));
      v115[4] = v215;
      int * v119 = v88->cache_age;
      int v120 = v119[5];
      int v217 = v120 + ((int)((unsigned int)(v120 - v116) >> 31));
      v119[5] = v217;
      int * v122 = v88->cache_age;
      v122[v214] = 0;
      v168 = v214;
    } else {
      int * v125 = v88->cache_age;
      int v126 = v125[4];
      int * v127 = v88->cache_tags;
      int v128 = v127[4];
      int v129 = v125[5];
      int v130 = v127[5];
      int * v131 = v88->cache_dirty;
      int v222 = 4 + ((((v126 + ((~(((v128 ^ -1) | (-(v128 ^ -1))) >> 31)) & 2)) - (v129 + ((~(((v130 ^ -1) | (-(v130 ^ -1))) >> 31)) & 2))) >> 31) & 1);
      int v132 = v131[v222];
      bool v223 = !(v132 == 0);
      if (v223) {
        int * v133 = v88->cache_tags;
        int v134 = v133[v222];
        int * v135 = v88->cache_vals;
        int v226 = (4 + ((((v126 + ((~(((v128 ^ -1) | (-(v128 ^ -1))) >> 31)) & 2)) - (v129 + ((~(((v130 ^ -1) | (-(v130 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
        int v136 = v135[v226];
        int v227 = ((4 + ((((v126 + ((~(((v128 ^ -1) | (-(v128 ^ -1))) >> 31)) & 2)) - (v129 + ((~(((v130 ^ -1) | (-(v130 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
        int v137 = v135[v227];
        int * v138 = v88->mem;
        int v229 = v134 * 2;
        v138[v229] = v136;
        int * v140 = v88->mem;
        int v232 = (v134 * 2) + 1;
        v140[v232] = v137;
        ;
      } else {
        ;
      }
      int * v145 = v88->mem;
      int v146 = v145[0];
      int v147 = v145[1];
      int * v148 = v88->cache_vals;
      int v238 = (4 + ((((v126 + ((~(((v128 ^ -1) | (-(v128 ^ -1))) >> 31)) & 2)) - (v129 + ((~(((v130 ^ -1) | (-(v130 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
      v148[v238] = v146;
      int * v150 = v88->cache_vals;
      int v241 = ((4 + ((((v126 + ((~(((v128 ^ -1) | (-(v128 ^ -1))) >> 31)) & 2)) - (v129 + ((~(((v130 ^ -1) | (-(v130 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
      v150[v241] = v147;
      int * v152 = v88->cache_tags;
      v152[v222] = 0;
      int * v154 = v88->cache_dirty;
      v154[v222] = 0;
      int * v156 = v88->cache_age;
      v156[v222] = 1;
      int * v158 = v88->cache_age;
      int v159 = v158[v222];
      int v160 = v158[4];
      int v247 = v160 + ((int)((unsigned int)(v160 - v159) >> 31));
      v158[4] = v247;
      int * v162 = v88->cache_age;
      int v163 = v162[5];
      int v249 = v163 + ((int)((unsigned int)(v163 - v159) >> 31));
      v162[5] = v249;
      int * v165 = v88->cache_age;
      v165[v222] = 0;
      v168 = v222;
    }
    int * v169 = v88->cache_vals;
    int v252 = v168 * 2;
    int v170 = v169[v252];
    int v253 = (v168 * 2) + 1;
    int v171 = v169[v253];
    int v254 = ((((v110 + ((~(((v112 ^ -1) | (-(v112 ^ -1))) >> 31)) & 2)) - (v113 + ((~(((v114 ^ -1) | (-(v114 ^ -1))) >> 31)) & 2))) >> 31) & 1) * 2;
    v169[v254] = v170;
    int * v173 = v88->cache_vals;
    int v257 = (((((v110 + ((~(((v112 ^ -1) | (-(v112 ^ -1))) >> 31)) & 2)) - (v113 + ((~(((v114 ^ -1) | (-(v114 ^ -1))) >> 31)) & 2))) >> 31) & 1) * 2) + 1;
    v173[v257] = v171;
    int * v175 = v88->cache_tags;
    int v260 = (((v110 + ((~(((v112 ^ -1) | (-(v112 ^ -1))) >> 31)) & 2)) - (v113 + ((~(((v114 ^ -1) | (-(v114 ^ -1))) >> 31)) & 2))) >> 31) & 1;
    v175[v260] = 0;
    int * v177 = v88->cache_dirty;
    v177[v260] = 0;
    int * v179 = v88->cache_age;
    v179[v260] = 1;
    int * v181 = v88->cache_age;
    int v182 = v181[v260];
    int v183 = v181[0];
    int v264 = v183 + ((int)((unsigned int)(v183 - v182) >> 31));
    v181[0] = v264;
    int * v185 = v88->cache_age;
    int v186 = v185[1];
    int v266 = v186 + ((int)((unsigned int)(v186 - v182) >> 31));
    v185[1] = v266;
    int * v188 = v88->cache_age;
    v188[v260] = 0;
    v191 = v260;
  }
  int v269 = v191 * 2;
  int v192 = v98[v269];
  int * v193 = v88->regs;
  v193[14] = v192;
  return v88;
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
    s1.mem[SECRET_OFFSET+i] = secret(0, 20);
    s2.mem[SECRET_OFFSET+i] = secret(0, 20);
  }
  struct StateT *s1_ = snippet(&s1);
  struct StateT *s2_ = snippet(&s2);
  //@ assert untainted_timer: !\tainted(s1_->timer==s2_->timer);
  koika_assert(s1_->timer==s2_->timer, "timing leak");
  return 0;
}