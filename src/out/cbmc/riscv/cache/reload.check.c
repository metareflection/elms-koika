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

struct StateT * slot_6(struct StateT * v575);
struct StateT * slot_5(struct StateT * v325);
struct StateT * slot_2(struct StateT * v28);
struct StateT * slot_7(struct StateT * v591);
struct StateT * slot_3(struct StateT * v41);
struct StateT * snippet(struct StateT * v0);
struct StateT * slot_1(struct StateT * v15);
struct StateT * slot_8(struct StateT * v65);
struct StateT * slot_4(struct StateT * v73);
struct StateT * slot_9(struct StateT * v94);
struct StateT * slot_0(struct StateT * v2);
struct StateT * slot_6(struct StateT * v575) {
  int v576 = v575->timer;
  int v584 = v576 + 1;
  v575->timer = v584;
  int * v578 = v575->regs;
  int v579 = v578[11];
  int * v580 = v575->regs;
  int v588 = v579 << 2;
  v580[11] = v588;
  struct StateT * v582 = slot_7(v575);
  return v582;
}

struct StateT * slot_5(struct StateT * v325) {
  int v326 = v325->timer;
  int v459 = v326 + 1;
  v325->timer = v459;
  int * v328 = v325->regs;
  int v329 = v328[5];
  int * v330 = v325->cache_tags;
  int v463 = (((int)((unsigned int)((int)((unsigned int)v329 >> 2)) >> 1)) & 1) * 2;
  int v331 = v330[v463];
  int * v332 = v325->cache_tags;
  int v465 = ((((int)((unsigned int)((int)((unsigned int)v329 >> 2)) >> 1)) & 1) * 2) + 1;
  int v333 = v332[v465];
  int * v334 = v325->cache_tags;
  int v467 = 4 + ((((int)((unsigned int)((int)((unsigned int)v329 >> 2)) >> 1)) & 3) * 2);
  int v335 = v334[v467];
  int * v336 = v325->cache_tags;
  int v469 = (4 + ((((int)((unsigned int)((int)((unsigned int)v329 >> 2)) >> 1)) & 3) * 2)) + 1;
  int v337 = v336[v469];
  int v338 = v325->timer;
  int v470 = v338 + ((100 ^ (((~(((v335 ^ ((int)((unsigned int)((int)((unsigned int)v329 >> 2)) >> 1))) | (-(v335 ^ ((int)((unsigned int)((int)((unsigned int)v329 >> 2)) >> 1))))) >> 31)) | (~(((v337 ^ ((int)((unsigned int)((int)((unsigned int)v329 >> 2)) >> 1))) | (-(v337 ^ ((int)((unsigned int)((int)((unsigned int)v329 >> 2)) >> 1))))) >> 31))) & 104)) ^ (((~(((v331 ^ ((int)((unsigned int)((int)((unsigned int)v329 >> 2)) >> 1))) | (-(v331 ^ ((int)((unsigned int)((int)((unsigned int)v329 >> 2)) >> 1))))) >> 31)) | (~(((v333 ^ ((int)((unsigned int)((int)((unsigned int)v329 >> 2)) >> 1))) | (-(v333 ^ ((int)((unsigned int)((int)((unsigned int)v329 >> 2)) >> 1))))) >> 31))) & (1 ^ (100 ^ (((~(((v335 ^ ((int)((unsigned int)((int)((unsigned int)v329 >> 2)) >> 1))) | (-(v335 ^ ((int)((unsigned int)((int)((unsigned int)v329 >> 2)) >> 1))))) >> 31)) | (~(((v337 ^ ((int)((unsigned int)((int)((unsigned int)v329 >> 2)) >> 1))) | (-(v337 ^ ((int)((unsigned int)((int)((unsigned int)v329 >> 2)) >> 1))))) >> 31))) & 104)))));
  v325->timer = v470;
  int * v340 = v325->cache_vals;
  bool v471 = !(((~(((v331 ^ ((int)((unsigned int)((int)((unsigned int)v329 >> 2)) >> 1))) | (-(v331 ^ ((int)((unsigned int)((int)((unsigned int)v329 >> 2)) >> 1))))) >> 31)) | (~(((v333 ^ ((int)((unsigned int)((int)((unsigned int)v329 >> 2)) >> 1))) | (-(v333 ^ ((int)((unsigned int)((int)((unsigned int)v329 >> 2)) >> 1))))) >> 31))) == 0);
  int v453;
  if (v471) {
    int * v341 = v325->cache_age;
    int v473 = ((((int)((unsigned int)((int)((unsigned int)v329 >> 2)) >> 1)) & 1) * 2) + ((~(((v333 ^ ((int)((unsigned int)((int)((unsigned int)v329 >> 2)) >> 1))) | (-(v333 ^ ((int)((unsigned int)((int)((unsigned int)v329 >> 2)) >> 1))))) >> 31)) & 1);
    int v342 = v341[v473];
    int * v343 = v325->cache_age;
    int v344 = v343[v463];
    int * v345 = v325->cache_age;
    int v476 = v344 + ((int)((unsigned int)(v344 - v342) >> 31));
    v345[v463] = v476;
    int * v347 = v325->cache_age;
    int v348 = v347[v465];
    int * v349 = v325->cache_age;
    int v479 = v348 + ((int)((unsigned int)(v348 - v342) >> 31));
    v349[v465] = v479;
    int * v351 = v325->cache_age;
    v351[v473] = 0;
    v453 = v473;
  } else {
    int * v354 = v325->cache_age;
    int v483 = (((int)((unsigned int)((int)((unsigned int)v329 >> 2)) >> 1)) & 1) * 2;
    int v355 = v354[v483];
    int * v356 = v325->cache_tags;
    int v357 = v356[v483];
    int * v358 = v325->cache_age;
    int v359 = v358[v465];
    int * v360 = v325->cache_tags;
    int v361 = v360[v465];
    bool v487 = !(((~(((v335 ^ ((int)((unsigned int)((int)((unsigned int)v329 >> 2)) >> 1))) | (-(v335 ^ ((int)((unsigned int)((int)((unsigned int)v329 >> 2)) >> 1))))) >> 31)) | (~(((v337 ^ ((int)((unsigned int)((int)((unsigned int)v329 >> 2)) >> 1))) | (-(v337 ^ ((int)((unsigned int)((int)((unsigned int)v329 >> 2)) >> 1))))) >> 31))) == 0);
    int v425;
    if (v487) {
      int * v362 = v325->cache_age;
      int v489 = (4 + ((((int)((unsigned int)((int)((unsigned int)v329 >> 2)) >> 1)) & 3) * 2)) + ((~(((v337 ^ ((int)((unsigned int)((int)((unsigned int)v329 >> 2)) >> 1))) | (-(v337 ^ ((int)((unsigned int)((int)((unsigned int)v329 >> 2)) >> 1))))) >> 31)) & 1);
      int v363 = v362[v489];
      int * v364 = v325->cache_age;
      int v365 = v364[v467];
      int * v366 = v325->cache_age;
      int v492 = v365 + ((int)((unsigned int)(v365 - v363) >> 31));
      v366[v467] = v492;
      int * v368 = v325->cache_age;
      int v369 = v368[v469];
      int * v370 = v325->cache_age;
      int v495 = v369 + ((int)((unsigned int)(v369 - v363) >> 31));
      v370[v469] = v495;
      int * v372 = v325->cache_age;
      v372[v489] = 0;
      v425 = v489;
    } else {
      int * v375 = v325->cache_age;
      int v499 = 4 + ((((int)((unsigned int)((int)((unsigned int)v329 >> 2)) >> 1)) & 3) * 2);
      int v376 = v375[v499];
      int * v377 = v325->cache_tags;
      int v378 = v377[v499];
      int * v379 = v325->cache_age;
      int v380 = v379[v469];
      int * v381 = v325->cache_tags;
      int v382 = v381[v469];
      int * v383 = v325->cache_dirty;
      int v504 = (4 + ((((int)((unsigned int)((int)((unsigned int)v329 >> 2)) >> 1)) & 3) * 2)) + ((((v376 + ((~(((v378 ^ -1) | (-(v378 ^ -1))) >> 31)) & 2)) - (v380 + ((~(((v382 ^ -1) | (-(v382 ^ -1))) >> 31)) & 2))) >> 31) & 1);
      int v384 = v383[v504];
      bool v505 = !(v384 == 0);
      if (v505) {
        int * v385 = v325->cache_tags;
        int v386 = v385[v504];
        int * v387 = v325->cache_vals;
        int v508 = ((4 + ((((int)((unsigned int)((int)((unsigned int)v329 >> 2)) >> 1)) & 3) * 2)) + ((((v376 + ((~(((v378 ^ -1) | (-(v378 ^ -1))) >> 31)) & 2)) - (v380 + ((~(((v382 ^ -1) | (-(v382 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
        int v388 = v387[v508];
        int * v389 = v325->cache_vals;
        int v510 = (((4 + ((((int)((unsigned int)((int)((unsigned int)v329 >> 2)) >> 1)) & 3) * 2)) + ((((v376 + ((~(((v378 ^ -1) | (-(v378 ^ -1))) >> 31)) & 2)) - (v380 + ((~(((v382 ^ -1) | (-(v382 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
        int v390 = v389[v510];
        int * v391 = v325->mem;
        int v512 = v386 * 2;
        v391[v512] = v388;
        int * v393 = v325->mem;
        int v515 = (v386 * 2) + 1;
        v393[v515] = v390;
        ;
      } else {
        ;
      }
      int * v398 = v325->mem;
      int v520 = ((int)((unsigned int)((int)((unsigned int)v329 >> 2)) >> 1)) * 2;
      int v399 = v398[v520];
      int * v400 = v325->mem;
      int v522 = (((int)((unsigned int)((int)((unsigned int)v329 >> 2)) >> 1)) * 2) + 1;
      int v401 = v400[v522];
      int * v402 = v325->cache_vals;
      int v524 = ((4 + ((((int)((unsigned int)((int)((unsigned int)v329 >> 2)) >> 1)) & 3) * 2)) + ((((v376 + ((~(((v378 ^ -1) | (-(v378 ^ -1))) >> 31)) & 2)) - (v380 + ((~(((v382 ^ -1) | (-(v382 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
      v402[v524] = v399;
      int * v404 = v325->cache_vals;
      int v527 = (((4 + ((((int)((unsigned int)((int)((unsigned int)v329 >> 2)) >> 1)) & 3) * 2)) + ((((v376 + ((~(((v378 ^ -1) | (-(v378 ^ -1))) >> 31)) & 2)) - (v380 + ((~(((v382 ^ -1) | (-(v382 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
      v404[v527] = v401;
      int * v406 = v325->cache_tags;
      int v530 = (int)((unsigned int)((int)((unsigned int)v329 >> 2)) >> 1);
      v406[v504] = v530;
      int * v408 = v325->cache_dirty;
      v408[v504] = 0;
      int * v410 = v325->cache_age;
      v410[v504] = 1;
      int * v412 = v325->cache_age;
      int v413 = v412[v504];
      int * v414 = v325->cache_age;
      int v415 = v414[v467];
      int * v416 = v325->cache_age;
      int v538 = v415 + ((int)((unsigned int)(v415 - v413) >> 31));
      v416[v467] = v538;
      int * v418 = v325->cache_age;
      int v419 = v418[v469];
      int * v420 = v325->cache_age;
      int v541 = v419 + ((int)((unsigned int)(v419 - v413) >> 31));
      v420[v469] = v541;
      int * v422 = v325->cache_age;
      v422[v504] = 0;
      v425 = v504;
    }
    int * v426 = v325->cache_vals;
    int v544 = v425 * 2;
    int v427 = v426[v544];
    int * v428 = v325->cache_vals;
    int v546 = (v425 * 2) + 1;
    int v429 = v428[v546];
    int * v430 = v325->cache_vals;
    int v548 = (((((int)((unsigned int)((int)((unsigned int)v329 >> 2)) >> 1)) & 1) * 2) + ((((v355 + ((~(((v357 ^ -1) | (-(v357 ^ -1))) >> 31)) & 2)) - (v359 + ((~(((v361 ^ -1) | (-(v361 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
    v430[v548] = v427;
    int * v432 = v325->cache_vals;
    int v551 = ((((((int)((unsigned int)((int)((unsigned int)v329 >> 2)) >> 1)) & 1) * 2) + ((((v355 + ((~(((v357 ^ -1) | (-(v357 ^ -1))) >> 31)) & 2)) - (v359 + ((~(((v361 ^ -1) | (-(v361 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
    v432[v551] = v429;
    int * v434 = v325->cache_tags;
    int v554 = ((((int)((unsigned int)((int)((unsigned int)v329 >> 2)) >> 1)) & 1) * 2) + ((((v355 + ((~(((v357 ^ -1) | (-(v357 ^ -1))) >> 31)) & 2)) - (v359 + ((~(((v361 ^ -1) | (-(v361 ^ -1))) >> 31)) & 2))) >> 31) & 1);
    int v555 = (int)((unsigned int)((int)((unsigned int)v329 >> 2)) >> 1);
    v434[v554] = v555;
    int * v436 = v325->cache_dirty;
    v436[v554] = 0;
    int * v438 = v325->cache_age;
    v438[v554] = 1;
    int * v440 = v325->cache_age;
    int v441 = v440[v554];
    int * v442 = v325->cache_age;
    int v443 = v442[v463];
    int * v444 = v325->cache_age;
    int v563 = v443 + ((int)((unsigned int)(v443 - v441) >> 31));
    v444[v463] = v563;
    int * v446 = v325->cache_age;
    int v447 = v446[v465];
    int * v448 = v325->cache_age;
    int v566 = v447 + ((int)((unsigned int)(v447 - v441) >> 31));
    v448[v465] = v566;
    int * v450 = v325->cache_age;
    v450[v554] = 0;
    v453 = v554;
  }
  int v569 = (v453 * 2) + (((int)((unsigned int)v329 >> 2)) & 1);
  int v454 = v340[v569];
  int * v455 = v325->regs;
  v455[11] = v454;
  struct StateT * v457 = slot_6(v325);
  return v457;
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

struct StateT * slot_7(struct StateT * v591) {
  int v592 = v591->timer;
  int v725 = v592 + 1;
  v591->timer = v725;
  int * v594 = v591->regs;
  int v595 = v594[11];
  int * v596 = v591->cache_tags;
  int v729 = (((int)((unsigned int)((int)((unsigned int)v595 >> 2)) >> 1)) & 1) * 2;
  int v597 = v596[v729];
  int * v598 = v591->cache_tags;
  int v731 = ((((int)((unsigned int)((int)((unsigned int)v595 >> 2)) >> 1)) & 1) * 2) + 1;
  int v599 = v598[v731];
  int * v600 = v591->cache_tags;
  int v733 = 4 + ((((int)((unsigned int)((int)((unsigned int)v595 >> 2)) >> 1)) & 3) * 2);
  int v601 = v600[v733];
  int * v602 = v591->cache_tags;
  int v735 = (4 + ((((int)((unsigned int)((int)((unsigned int)v595 >> 2)) >> 1)) & 3) * 2)) + 1;
  int v603 = v602[v735];
  int v604 = v591->timer;
  int v736 = v604 + ((100 ^ (((~(((v601 ^ ((int)((unsigned int)((int)((unsigned int)v595 >> 2)) >> 1))) | (-(v601 ^ ((int)((unsigned int)((int)((unsigned int)v595 >> 2)) >> 1))))) >> 31)) | (~(((v603 ^ ((int)((unsigned int)((int)((unsigned int)v595 >> 2)) >> 1))) | (-(v603 ^ ((int)((unsigned int)((int)((unsigned int)v595 >> 2)) >> 1))))) >> 31))) & 104)) ^ (((~(((v597 ^ ((int)((unsigned int)((int)((unsigned int)v595 >> 2)) >> 1))) | (-(v597 ^ ((int)((unsigned int)((int)((unsigned int)v595 >> 2)) >> 1))))) >> 31)) | (~(((v599 ^ ((int)((unsigned int)((int)((unsigned int)v595 >> 2)) >> 1))) | (-(v599 ^ ((int)((unsigned int)((int)((unsigned int)v595 >> 2)) >> 1))))) >> 31))) & (1 ^ (100 ^ (((~(((v601 ^ ((int)((unsigned int)((int)((unsigned int)v595 >> 2)) >> 1))) | (-(v601 ^ ((int)((unsigned int)((int)((unsigned int)v595 >> 2)) >> 1))))) >> 31)) | (~(((v603 ^ ((int)((unsigned int)((int)((unsigned int)v595 >> 2)) >> 1))) | (-(v603 ^ ((int)((unsigned int)((int)((unsigned int)v595 >> 2)) >> 1))))) >> 31))) & 104)))));
  v591->timer = v736;
  int * v606 = v591->cache_vals;
  bool v737 = !(((~(((v597 ^ ((int)((unsigned int)((int)((unsigned int)v595 >> 2)) >> 1))) | (-(v597 ^ ((int)((unsigned int)((int)((unsigned int)v595 >> 2)) >> 1))))) >> 31)) | (~(((v599 ^ ((int)((unsigned int)((int)((unsigned int)v595 >> 2)) >> 1))) | (-(v599 ^ ((int)((unsigned int)((int)((unsigned int)v595 >> 2)) >> 1))))) >> 31))) == 0);
  int v719;
  if (v737) {
    int * v607 = v591->cache_age;
    int v739 = ((((int)((unsigned int)((int)((unsigned int)v595 >> 2)) >> 1)) & 1) * 2) + ((~(((v599 ^ ((int)((unsigned int)((int)((unsigned int)v595 >> 2)) >> 1))) | (-(v599 ^ ((int)((unsigned int)((int)((unsigned int)v595 >> 2)) >> 1))))) >> 31)) & 1);
    int v608 = v607[v739];
    int * v609 = v591->cache_age;
    int v610 = v609[v729];
    int * v611 = v591->cache_age;
    int v742 = v610 + ((int)((unsigned int)(v610 - v608) >> 31));
    v611[v729] = v742;
    int * v613 = v591->cache_age;
    int v614 = v613[v731];
    int * v615 = v591->cache_age;
    int v745 = v614 + ((int)((unsigned int)(v614 - v608) >> 31));
    v615[v731] = v745;
    int * v617 = v591->cache_age;
    v617[v739] = 0;
    v719 = v739;
  } else {
    int * v620 = v591->cache_age;
    int v749 = (((int)((unsigned int)((int)((unsigned int)v595 >> 2)) >> 1)) & 1) * 2;
    int v621 = v620[v749];
    int * v622 = v591->cache_tags;
    int v623 = v622[v749];
    int * v624 = v591->cache_age;
    int v625 = v624[v731];
    int * v626 = v591->cache_tags;
    int v627 = v626[v731];
    bool v753 = !(((~(((v601 ^ ((int)((unsigned int)((int)((unsigned int)v595 >> 2)) >> 1))) | (-(v601 ^ ((int)((unsigned int)((int)((unsigned int)v595 >> 2)) >> 1))))) >> 31)) | (~(((v603 ^ ((int)((unsigned int)((int)((unsigned int)v595 >> 2)) >> 1))) | (-(v603 ^ ((int)((unsigned int)((int)((unsigned int)v595 >> 2)) >> 1))))) >> 31))) == 0);
    int v691;
    if (v753) {
      int * v628 = v591->cache_age;
      int v755 = (4 + ((((int)((unsigned int)((int)((unsigned int)v595 >> 2)) >> 1)) & 3) * 2)) + ((~(((v603 ^ ((int)((unsigned int)((int)((unsigned int)v595 >> 2)) >> 1))) | (-(v603 ^ ((int)((unsigned int)((int)((unsigned int)v595 >> 2)) >> 1))))) >> 31)) & 1);
      int v629 = v628[v755];
      int * v630 = v591->cache_age;
      int v631 = v630[v733];
      int * v632 = v591->cache_age;
      int v758 = v631 + ((int)((unsigned int)(v631 - v629) >> 31));
      v632[v733] = v758;
      int * v634 = v591->cache_age;
      int v635 = v634[v735];
      int * v636 = v591->cache_age;
      int v761 = v635 + ((int)((unsigned int)(v635 - v629) >> 31));
      v636[v735] = v761;
      int * v638 = v591->cache_age;
      v638[v755] = 0;
      v691 = v755;
    } else {
      int * v641 = v591->cache_age;
      int v765 = 4 + ((((int)((unsigned int)((int)((unsigned int)v595 >> 2)) >> 1)) & 3) * 2);
      int v642 = v641[v765];
      int * v643 = v591->cache_tags;
      int v644 = v643[v765];
      int * v645 = v591->cache_age;
      int v646 = v645[v735];
      int * v647 = v591->cache_tags;
      int v648 = v647[v735];
      int * v649 = v591->cache_dirty;
      int v770 = (4 + ((((int)((unsigned int)((int)((unsigned int)v595 >> 2)) >> 1)) & 3) * 2)) + ((((v642 + ((~(((v644 ^ -1) | (-(v644 ^ -1))) >> 31)) & 2)) - (v646 + ((~(((v648 ^ -1) | (-(v648 ^ -1))) >> 31)) & 2))) >> 31) & 1);
      int v650 = v649[v770];
      bool v771 = !(v650 == 0);
      if (v771) {
        int * v651 = v591->cache_tags;
        int v652 = v651[v770];
        int * v653 = v591->cache_vals;
        int v774 = ((4 + ((((int)((unsigned int)((int)((unsigned int)v595 >> 2)) >> 1)) & 3) * 2)) + ((((v642 + ((~(((v644 ^ -1) | (-(v644 ^ -1))) >> 31)) & 2)) - (v646 + ((~(((v648 ^ -1) | (-(v648 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
        int v654 = v653[v774];
        int * v655 = v591->cache_vals;
        int v776 = (((4 + ((((int)((unsigned int)((int)((unsigned int)v595 >> 2)) >> 1)) & 3) * 2)) + ((((v642 + ((~(((v644 ^ -1) | (-(v644 ^ -1))) >> 31)) & 2)) - (v646 + ((~(((v648 ^ -1) | (-(v648 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
        int v656 = v655[v776];
        int * v657 = v591->mem;
        int v778 = v652 * 2;
        v657[v778] = v654;
        int * v659 = v591->mem;
        int v781 = (v652 * 2) + 1;
        v659[v781] = v656;
        ;
      } else {
        ;
      }
      int * v664 = v591->mem;
      int v786 = ((int)((unsigned int)((int)((unsigned int)v595 >> 2)) >> 1)) * 2;
      int v665 = v664[v786];
      int * v666 = v591->mem;
      int v788 = (((int)((unsigned int)((int)((unsigned int)v595 >> 2)) >> 1)) * 2) + 1;
      int v667 = v666[v788];
      int * v668 = v591->cache_vals;
      int v790 = ((4 + ((((int)((unsigned int)((int)((unsigned int)v595 >> 2)) >> 1)) & 3) * 2)) + ((((v642 + ((~(((v644 ^ -1) | (-(v644 ^ -1))) >> 31)) & 2)) - (v646 + ((~(((v648 ^ -1) | (-(v648 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
      v668[v790] = v665;
      int * v670 = v591->cache_vals;
      int v793 = (((4 + ((((int)((unsigned int)((int)((unsigned int)v595 >> 2)) >> 1)) & 3) * 2)) + ((((v642 + ((~(((v644 ^ -1) | (-(v644 ^ -1))) >> 31)) & 2)) - (v646 + ((~(((v648 ^ -1) | (-(v648 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
      v670[v793] = v667;
      int * v672 = v591->cache_tags;
      int v796 = (int)((unsigned int)((int)((unsigned int)v595 >> 2)) >> 1);
      v672[v770] = v796;
      int * v674 = v591->cache_dirty;
      v674[v770] = 0;
      int * v676 = v591->cache_age;
      v676[v770] = 1;
      int * v678 = v591->cache_age;
      int v679 = v678[v770];
      int * v680 = v591->cache_age;
      int v681 = v680[v733];
      int * v682 = v591->cache_age;
      int v804 = v681 + ((int)((unsigned int)(v681 - v679) >> 31));
      v682[v733] = v804;
      int * v684 = v591->cache_age;
      int v685 = v684[v735];
      int * v686 = v591->cache_age;
      int v807 = v685 + ((int)((unsigned int)(v685 - v679) >> 31));
      v686[v735] = v807;
      int * v688 = v591->cache_age;
      v688[v770] = 0;
      v691 = v770;
    }
    int * v692 = v591->cache_vals;
    int v810 = v691 * 2;
    int v693 = v692[v810];
    int * v694 = v591->cache_vals;
    int v812 = (v691 * 2) + 1;
    int v695 = v694[v812];
    int * v696 = v591->cache_vals;
    int v814 = (((((int)((unsigned int)((int)((unsigned int)v595 >> 2)) >> 1)) & 1) * 2) + ((((v621 + ((~(((v623 ^ -1) | (-(v623 ^ -1))) >> 31)) & 2)) - (v625 + ((~(((v627 ^ -1) | (-(v627 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
    v696[v814] = v693;
    int * v698 = v591->cache_vals;
    int v817 = ((((((int)((unsigned int)((int)((unsigned int)v595 >> 2)) >> 1)) & 1) * 2) + ((((v621 + ((~(((v623 ^ -1) | (-(v623 ^ -1))) >> 31)) & 2)) - (v625 + ((~(((v627 ^ -1) | (-(v627 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
    v698[v817] = v695;
    int * v700 = v591->cache_tags;
    int v820 = ((((int)((unsigned int)((int)((unsigned int)v595 >> 2)) >> 1)) & 1) * 2) + ((((v621 + ((~(((v623 ^ -1) | (-(v623 ^ -1))) >> 31)) & 2)) - (v625 + ((~(((v627 ^ -1) | (-(v627 ^ -1))) >> 31)) & 2))) >> 31) & 1);
    int v821 = (int)((unsigned int)((int)((unsigned int)v595 >> 2)) >> 1);
    v700[v820] = v821;
    int * v702 = v591->cache_dirty;
    v702[v820] = 0;
    int * v704 = v591->cache_age;
    v704[v820] = 1;
    int * v706 = v591->cache_age;
    int v707 = v706[v820];
    int * v708 = v591->cache_age;
    int v709 = v708[v729];
    int * v710 = v591->cache_age;
    int v829 = v709 + ((int)((unsigned int)(v709 - v707) >> 31));
    v710[v729] = v829;
    int * v712 = v591->cache_age;
    int v713 = v712[v731];
    int * v714 = v591->cache_age;
    int v832 = v713 + ((int)((unsigned int)(v713 - v707) >> 31));
    v714[v731] = v832;
    int * v716 = v591->cache_age;
    v716[v820] = 0;
    v719 = v820;
  }
  int v835 = (v719 * 2) + (((int)((unsigned int)v595 >> 2)) & 1);
  int v720 = v606[v835];
  int * v721 = v591->regs;
  v721[12] = v720;
  struct StateT * v723 = slot_8(v591);
  return v723;
}

struct StateT * slot_3(struct StateT * v41) {
  int v42 = v41->timer;
  int v54 = v42 + 1;
  v41->timer = v54;
  int * v44 = v41->regs;
  int v45 = v44[10];
  int * v46 = v41->regs;
  int v47 = v46[15];
  bool v59 = v45 >= v47;
  struct StateT * v52;
  if (v59) {
    struct StateT * v48 = slot_8(v41);
    v52 = v48;
  } else {
    struct StateT * v50 = slot_4(v41);
    v52 = v50;
  }
  return v52;
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

struct StateT * slot_8(struct StateT * v65) {
  int v66 = v65->timer;
  int v70 = v66 + 1;
  v65->timer = v70;
  struct StateT * v68 = slot_9(v65);
  return v68;
}

struct StateT * slot_4(struct StateT * v73) {
  int v74 = v73->timer;
  int v84 = v74 + 1;
  v73->timer = v84;
  int * v76 = v73->regs;
  int v77 = v76[13];
  int * v78 = v73->regs;
  int v79 = v78[10];
  int * v80 = v73->regs;
  int v91 = v77 + v79;
  v80[5] = v91;
  struct StateT * v82 = slot_5(v73);
  return v82;
}

struct StateT * slot_9(struct StateT * v94) {
  int v95 = v94->timer;
  int v225 = v95 + 1;
  v94->timer = v225;
  int * v97 = v94->cache_tags;
  int v98 = v97[0];
  int * v99 = v94->cache_tags;
  int v100 = v99[1];
  int * v101 = v94->cache_tags;
  int v102 = v101[4];
  int * v103 = v94->cache_tags;
  int v104 = v103[5];
  int v105 = v94->timer;
  int v234 = v105 + ((100 ^ (((~((v102 | (-v102)) >> 31)) | (~((v104 | (-v104)) >> 31))) & 104)) ^ (((~((v98 | (-v98)) >> 31)) | (~((v100 | (-v100)) >> 31))) & (1 ^ (100 ^ (((~((v102 | (-v102)) >> 31)) | (~((v104 | (-v104)) >> 31))) & 104)))));
  v94->timer = v234;
  int * v107 = v94->cache_vals;
  bool v235 = !(((~((v98 | (-v98)) >> 31)) | (~((v100 | (-v100)) >> 31))) == 0);
  int v220;
  if (v235) {
    int * v108 = v94->cache_age;
    int v237 = (~((v100 | (-v100)) >> 31)) & 1;
    int v109 = v108[v237];
    int * v110 = v94->cache_age;
    int v111 = v110[0];
    int * v112 = v94->cache_age;
    int v240 = v111 + ((int)((unsigned int)(v111 - v109) >> 31));
    v112[0] = v240;
    int * v114 = v94->cache_age;
    int v115 = v114[1];
    int * v116 = v94->cache_age;
    int v243 = v115 + ((int)((unsigned int)(v115 - v109) >> 31));
    v116[1] = v243;
    int * v118 = v94->cache_age;
    v118[v237] = 0;
    v220 = v237;
  } else {
    int * v121 = v94->cache_age;
    int v122 = v121[0];
    int * v123 = v94->cache_tags;
    int v124 = v123[0];
    int * v125 = v94->cache_age;
    int v126 = v125[1];
    int * v127 = v94->cache_tags;
    int v128 = v127[1];
    bool v249 = !(((~((v102 | (-v102)) >> 31)) | (~((v104 | (-v104)) >> 31))) == 0);
    int v192;
    if (v249) {
      int * v129 = v94->cache_age;
      int v251 = 4 + ((~((v104 | (-v104)) >> 31)) & 1);
      int v130 = v129[v251];
      int * v131 = v94->cache_age;
      int v132 = v131[4];
      int * v133 = v94->cache_age;
      int v254 = v132 + ((int)((unsigned int)(v132 - v130) >> 31));
      v133[4] = v254;
      int * v135 = v94->cache_age;
      int v136 = v135[5];
      int * v137 = v94->cache_age;
      int v257 = v136 + ((int)((unsigned int)(v136 - v130) >> 31));
      v137[5] = v257;
      int * v139 = v94->cache_age;
      v139[v251] = 0;
      v192 = v251;
    } else {
      int * v142 = v94->cache_age;
      int v143 = v142[4];
      int * v144 = v94->cache_tags;
      int v145 = v144[4];
      int * v146 = v94->cache_age;
      int v147 = v146[5];
      int * v148 = v94->cache_tags;
      int v149 = v148[5];
      int * v150 = v94->cache_dirty;
      int v264 = 4 + ((((v143 + ((~(((v145 ^ -1) | (-(v145 ^ -1))) >> 31)) & 2)) - (v147 + ((~(((v149 ^ -1) | (-(v149 ^ -1))) >> 31)) & 2))) >> 31) & 1);
      int v151 = v150[v264];
      bool v265 = !(v151 == 0);
      if (v265) {
        int * v152 = v94->cache_tags;
        int v153 = v152[v264];
        int * v154 = v94->cache_vals;
        int v268 = (4 + ((((v143 + ((~(((v145 ^ -1) | (-(v145 ^ -1))) >> 31)) & 2)) - (v147 + ((~(((v149 ^ -1) | (-(v149 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
        int v155 = v154[v268];
        int * v156 = v94->cache_vals;
        int v270 = ((4 + ((((v143 + ((~(((v145 ^ -1) | (-(v145 ^ -1))) >> 31)) & 2)) - (v147 + ((~(((v149 ^ -1) | (-(v149 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
        int v157 = v156[v270];
        int * v158 = v94->mem;
        int v272 = v153 * 2;
        v158[v272] = v155;
        int * v160 = v94->mem;
        int v275 = (v153 * 2) + 1;
        v160[v275] = v157;
        ;
      } else {
        ;
      }
      int * v165 = v94->mem;
      int v166 = v165[0];
      int * v167 = v94->mem;
      int v168 = v167[1];
      int * v169 = v94->cache_vals;
      int v282 = (4 + ((((v143 + ((~(((v145 ^ -1) | (-(v145 ^ -1))) >> 31)) & 2)) - (v147 + ((~(((v149 ^ -1) | (-(v149 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
      v169[v282] = v166;
      int * v171 = v94->cache_vals;
      int v285 = ((4 + ((((v143 + ((~(((v145 ^ -1) | (-(v145 ^ -1))) >> 31)) & 2)) - (v147 + ((~(((v149 ^ -1) | (-(v149 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
      v171[v285] = v168;
      int * v173 = v94->cache_tags;
      v173[v264] = 0;
      int * v175 = v94->cache_dirty;
      v175[v264] = 0;
      int * v177 = v94->cache_age;
      v177[v264] = 1;
      int * v179 = v94->cache_age;
      int v180 = v179[v264];
      int * v181 = v94->cache_age;
      int v182 = v181[4];
      int * v183 = v94->cache_age;
      int v293 = v182 + ((int)((unsigned int)(v182 - v180) >> 31));
      v183[4] = v293;
      int * v185 = v94->cache_age;
      int v186 = v185[5];
      int * v187 = v94->cache_age;
      int v296 = v186 + ((int)((unsigned int)(v186 - v180) >> 31));
      v187[5] = v296;
      int * v189 = v94->cache_age;
      v189[v264] = 0;
      v192 = v264;
    }
    int * v193 = v94->cache_vals;
    int v299 = v192 * 2;
    int v194 = v193[v299];
    int * v195 = v94->cache_vals;
    int v301 = (v192 * 2) + 1;
    int v196 = v195[v301];
    int * v197 = v94->cache_vals;
    int v303 = ((((v122 + ((~(((v124 ^ -1) | (-(v124 ^ -1))) >> 31)) & 2)) - (v126 + ((~(((v128 ^ -1) | (-(v128 ^ -1))) >> 31)) & 2))) >> 31) & 1) * 2;
    v197[v303] = v194;
    int * v199 = v94->cache_vals;
    int v306 = (((((v122 + ((~(((v124 ^ -1) | (-(v124 ^ -1))) >> 31)) & 2)) - (v126 + ((~(((v128 ^ -1) | (-(v128 ^ -1))) >> 31)) & 2))) >> 31) & 1) * 2) + 1;
    v199[v306] = v196;
    int * v201 = v94->cache_tags;
    int v309 = (((v122 + ((~(((v124 ^ -1) | (-(v124 ^ -1))) >> 31)) & 2)) - (v126 + ((~(((v128 ^ -1) | (-(v128 ^ -1))) >> 31)) & 2))) >> 31) & 1;
    v201[v309] = 0;
    int * v203 = v94->cache_dirty;
    v203[v309] = 0;
    int * v205 = v94->cache_age;
    v205[v309] = 1;
    int * v207 = v94->cache_age;
    int v208 = v207[v309];
    int * v209 = v94->cache_age;
    int v210 = v209[0];
    int * v211 = v94->cache_age;
    int v315 = v210 + ((int)((unsigned int)(v210 - v208) >> 31));
    v211[0] = v315;
    int * v213 = v94->cache_age;
    int v214 = v213[1];
    int * v215 = v94->cache_age;
    int v318 = v214 + ((int)((unsigned int)(v214 - v208) >> 31));
    v215[1] = v318;
    int * v217 = v94->cache_age;
    v217[v309] = 0;
    v220 = v309;
  }
  int v321 = v220 * 2;
  int v221 = v107[v321];
  int * v222 = v94->regs;
  v222[14] = v221;
  return v94;
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
    s1.mem[SECRET_OFFSET+i] = bounded(0, 20);
    s2.mem[SECRET_OFFSET+i] = bounded(0, 20);
  }
  struct StateT *s1_ = snippet(&s1);
  struct StateT *s2_ = snippet(&s2);
  koika_assert(s1_->timer==s2_->timer, "timing leak");
  return 0;
}