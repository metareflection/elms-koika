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

struct StateT * slot_6(struct StateT * v616);
struct StateT * slot_5(struct StateT * v361);
struct StateT * slot_2(struct StateT * v38);
struct StateT * slot_7(struct StateT * v640);
struct StateT * slot_3(struct StateT * v56);
struct StateT * snippet(struct StateT * v0);
struct StateT * slot_1(struct StateT * v20);
struct StateT * slot_8(struct StateT * v87);
struct StateT * slot_4(struct StateT * v96);
struct StateT * slot_9(struct StateT * v128);
struct StateT * slot_0(struct StateT * v2);
struct StateT * slot_6(struct StateT * v616) {
  int v617 = v616->timer;
  int v618 = v616->timer;
  int v630 = v618 + 1;
  v616->timer = v630;
  int * v620 = v616->reg_ready;
  int v621 = v620[11];
  int * v622 = v616->regs;
  int v623 = v622[11];
  int * v624 = v616->reg_ready;
  int v635 = (v621 + ((v617 - v621) & (~((v617 - v621) >> 31)))) + 1;
  v624[11] = v635;
  int * v626 = v616->regs;
  int v637 = v623 << 2;
  v626[11] = v637;
  struct StateT * v628 = slot_7(v616);
  return v628;
}

struct StateT * slot_5(struct StateT * v361) {
  int v362 = v361->timer;
  int v363 = v361->timer;
  int v498 = v363 + 1;
  v361->timer = v498;
  int * v365 = v361->reg_ready;
  int v366 = v365[5];
  int * v367 = v361->regs;
  int v368 = v367[5];
  int * v369 = v361->cache_tags;
  int v503 = (((int)((unsigned int)((int)((unsigned int)v368 >> 2)) >> 1)) & 1) * 2;
  int v370 = v369[v503];
  int * v371 = v361->cache_tags;
  int v505 = ((((int)((unsigned int)((int)((unsigned int)v368 >> 2)) >> 1)) & 1) * 2) + 1;
  int v372 = v371[v505];
  int * v373 = v361->cache_tags;
  int v507 = 4 + ((((int)((unsigned int)((int)((unsigned int)v368 >> 2)) >> 1)) & 3) * 2);
  int v374 = v373[v507];
  int * v375 = v361->cache_tags;
  int v509 = (4 + ((((int)((unsigned int)((int)((unsigned int)v368 >> 2)) >> 1)) & 3) * 2)) + 1;
  int v376 = v375[v509];
  int * v377 = v361->cache_vals;
  bool v510 = !(((~(((v370 ^ ((int)((unsigned int)((int)((unsigned int)v368 >> 2)) >> 1))) | (-(v370 ^ ((int)((unsigned int)((int)((unsigned int)v368 >> 2)) >> 1))))) >> 31)) | (~(((v372 ^ ((int)((unsigned int)((int)((unsigned int)v368 >> 2)) >> 1))) | (-(v372 ^ ((int)((unsigned int)((int)((unsigned int)v368 >> 2)) >> 1))))) >> 31))) == 0);
  int v490;
  if (v510) {
    int * v378 = v361->cache_age;
    int v512 = ((((int)((unsigned int)((int)((unsigned int)v368 >> 2)) >> 1)) & 1) * 2) + ((~(((v372 ^ ((int)((unsigned int)((int)((unsigned int)v368 >> 2)) >> 1))) | (-(v372 ^ ((int)((unsigned int)((int)((unsigned int)v368 >> 2)) >> 1))))) >> 31)) & 1);
    int v379 = v378[v512];
    int * v380 = v361->cache_age;
    int v381 = v380[v503];
    int * v382 = v361->cache_age;
    int v515 = v381 + ((int)((unsigned int)(v381 - v379) >> 31));
    v382[v503] = v515;
    int * v384 = v361->cache_age;
    int v385 = v384[v505];
    int * v386 = v361->cache_age;
    int v518 = v385 + ((int)((unsigned int)(v385 - v379) >> 31));
    v386[v505] = v518;
    int * v388 = v361->cache_age;
    v388[v512] = 0;
    v490 = v512;
  } else {
    int * v391 = v361->cache_age;
    int v522 = (((int)((unsigned int)((int)((unsigned int)v368 >> 2)) >> 1)) & 1) * 2;
    int v392 = v391[v522];
    int * v393 = v361->cache_tags;
    int v394 = v393[v522];
    int * v395 = v361->cache_age;
    int v396 = v395[v505];
    int * v397 = v361->cache_tags;
    int v398 = v397[v505];
    bool v526 = !(((~(((v374 ^ ((int)((unsigned int)((int)((unsigned int)v368 >> 2)) >> 1))) | (-(v374 ^ ((int)((unsigned int)((int)((unsigned int)v368 >> 2)) >> 1))))) >> 31)) | (~(((v376 ^ ((int)((unsigned int)((int)((unsigned int)v368 >> 2)) >> 1))) | (-(v376 ^ ((int)((unsigned int)((int)((unsigned int)v368 >> 2)) >> 1))))) >> 31))) == 0);
    int v462;
    if (v526) {
      int * v399 = v361->cache_age;
      int v528 = (4 + ((((int)((unsigned int)((int)((unsigned int)v368 >> 2)) >> 1)) & 3) * 2)) + ((~(((v376 ^ ((int)((unsigned int)((int)((unsigned int)v368 >> 2)) >> 1))) | (-(v376 ^ ((int)((unsigned int)((int)((unsigned int)v368 >> 2)) >> 1))))) >> 31)) & 1);
      int v400 = v399[v528];
      int * v401 = v361->cache_age;
      int v402 = v401[v507];
      int * v403 = v361->cache_age;
      int v531 = v402 + ((int)((unsigned int)(v402 - v400) >> 31));
      v403[v507] = v531;
      int * v405 = v361->cache_age;
      int v406 = v405[v509];
      int * v407 = v361->cache_age;
      int v534 = v406 + ((int)((unsigned int)(v406 - v400) >> 31));
      v407[v509] = v534;
      int * v409 = v361->cache_age;
      v409[v528] = 0;
      v462 = v528;
    } else {
      int * v412 = v361->cache_age;
      int v538 = 4 + ((((int)((unsigned int)((int)((unsigned int)v368 >> 2)) >> 1)) & 3) * 2);
      int v413 = v412[v538];
      int * v414 = v361->cache_tags;
      int v415 = v414[v538];
      int * v416 = v361->cache_age;
      int v417 = v416[v509];
      int * v418 = v361->cache_tags;
      int v419 = v418[v509];
      int * v420 = v361->cache_dirty;
      int v543 = (4 + ((((int)((unsigned int)((int)((unsigned int)v368 >> 2)) >> 1)) & 3) * 2)) + ((((v413 + ((~(((v415 ^ -1) | (-(v415 ^ -1))) >> 31)) & 2)) - (v417 + ((~(((v419 ^ -1) | (-(v419 ^ -1))) >> 31)) & 2))) >> 31) & 1);
      int v421 = v420[v543];
      bool v544 = !(v421 == 0);
      if (v544) {
        int * v422 = v361->cache_tags;
        int v423 = v422[v543];
        int * v424 = v361->cache_vals;
        int v547 = ((4 + ((((int)((unsigned int)((int)((unsigned int)v368 >> 2)) >> 1)) & 3) * 2)) + ((((v413 + ((~(((v415 ^ -1) | (-(v415 ^ -1))) >> 31)) & 2)) - (v417 + ((~(((v419 ^ -1) | (-(v419 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
        int v425 = v424[v547];
        int * v426 = v361->cache_vals;
        int v549 = (((4 + ((((int)((unsigned int)((int)((unsigned int)v368 >> 2)) >> 1)) & 3) * 2)) + ((((v413 + ((~(((v415 ^ -1) | (-(v415 ^ -1))) >> 31)) & 2)) - (v417 + ((~(((v419 ^ -1) | (-(v419 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
        int v427 = v426[v549];
        int * v428 = v361->mem;
        int v551 = v423 * 2;
        v428[v551] = v425;
        int * v430 = v361->mem;
        int v554 = (v423 * 2) + 1;
        v430[v554] = v427;
        ;
      } else {
        ;
      }
      int * v435 = v361->mem;
      int v559 = ((int)((unsigned int)((int)((unsigned int)v368 >> 2)) >> 1)) * 2;
      int v436 = v435[v559];
      int * v437 = v361->mem;
      int v561 = (((int)((unsigned int)((int)((unsigned int)v368 >> 2)) >> 1)) * 2) + 1;
      int v438 = v437[v561];
      int * v439 = v361->cache_vals;
      int v563 = ((4 + ((((int)((unsigned int)((int)((unsigned int)v368 >> 2)) >> 1)) & 3) * 2)) + ((((v413 + ((~(((v415 ^ -1) | (-(v415 ^ -1))) >> 31)) & 2)) - (v417 + ((~(((v419 ^ -1) | (-(v419 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
      v439[v563] = v436;
      int * v441 = v361->cache_vals;
      int v566 = (((4 + ((((int)((unsigned int)((int)((unsigned int)v368 >> 2)) >> 1)) & 3) * 2)) + ((((v413 + ((~(((v415 ^ -1) | (-(v415 ^ -1))) >> 31)) & 2)) - (v417 + ((~(((v419 ^ -1) | (-(v419 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
      v441[v566] = v438;
      int * v443 = v361->cache_tags;
      int v569 = (int)((unsigned int)((int)((unsigned int)v368 >> 2)) >> 1);
      v443[v543] = v569;
      int * v445 = v361->cache_dirty;
      v445[v543] = 0;
      int * v447 = v361->cache_age;
      v447[v543] = 1;
      int * v449 = v361->cache_age;
      int v450 = v449[v543];
      int * v451 = v361->cache_age;
      int v452 = v451[v507];
      int * v453 = v361->cache_age;
      int v577 = v452 + ((int)((unsigned int)(v452 - v450) >> 31));
      v453[v507] = v577;
      int * v455 = v361->cache_age;
      int v456 = v455[v509];
      int * v457 = v361->cache_age;
      int v580 = v456 + ((int)((unsigned int)(v456 - v450) >> 31));
      v457[v509] = v580;
      int * v459 = v361->cache_age;
      v459[v543] = 0;
      v462 = v543;
    }
    int * v463 = v361->cache_vals;
    int v583 = v462 * 2;
    int v464 = v463[v583];
    int * v465 = v361->cache_vals;
    int v585 = (v462 * 2) + 1;
    int v466 = v465[v585];
    int * v467 = v361->cache_vals;
    int v587 = (((((int)((unsigned int)((int)((unsigned int)v368 >> 2)) >> 1)) & 1) * 2) + ((((v392 + ((~(((v394 ^ -1) | (-(v394 ^ -1))) >> 31)) & 2)) - (v396 + ((~(((v398 ^ -1) | (-(v398 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
    v467[v587] = v464;
    int * v469 = v361->cache_vals;
    int v590 = ((((((int)((unsigned int)((int)((unsigned int)v368 >> 2)) >> 1)) & 1) * 2) + ((((v392 + ((~(((v394 ^ -1) | (-(v394 ^ -1))) >> 31)) & 2)) - (v396 + ((~(((v398 ^ -1) | (-(v398 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
    v469[v590] = v466;
    int * v471 = v361->cache_tags;
    int v593 = ((((int)((unsigned int)((int)((unsigned int)v368 >> 2)) >> 1)) & 1) * 2) + ((((v392 + ((~(((v394 ^ -1) | (-(v394 ^ -1))) >> 31)) & 2)) - (v396 + ((~(((v398 ^ -1) | (-(v398 ^ -1))) >> 31)) & 2))) >> 31) & 1);
    int v594 = (int)((unsigned int)((int)((unsigned int)v368 >> 2)) >> 1);
    v471[v593] = v594;
    int * v473 = v361->cache_dirty;
    v473[v593] = 0;
    int * v475 = v361->cache_age;
    v475[v593] = 1;
    int * v477 = v361->cache_age;
    int v478 = v477[v593];
    int * v479 = v361->cache_age;
    int v480 = v479[v503];
    int * v481 = v361->cache_age;
    int v602 = v480 + ((int)((unsigned int)(v480 - v478) >> 31));
    v481[v503] = v602;
    int * v483 = v361->cache_age;
    int v484 = v483[v505];
    int * v485 = v361->cache_age;
    int v605 = v484 + ((int)((unsigned int)(v484 - v478) >> 31));
    v485[v505] = v605;
    int * v487 = v361->cache_age;
    v487[v593] = 0;
    v490 = v593;
  }
  int v608 = (v490 * 2) + (((int)((unsigned int)v368 >> 2)) & 1);
  int v491 = v377[v608];
  int * v492 = v361->reg_ready;
  int v611 = ((v366 + ((v362 - v366) & (~((v362 - v366) >> 31)))) + 1) + ((100 ^ (((~(((v374 ^ ((int)((unsigned int)((int)((unsigned int)v368 >> 2)) >> 1))) | (-(v374 ^ ((int)((unsigned int)((int)((unsigned int)v368 >> 2)) >> 1))))) >> 31)) | (~(((v376 ^ ((int)((unsigned int)((int)((unsigned int)v368 >> 2)) >> 1))) | (-(v376 ^ ((int)((unsigned int)((int)((unsigned int)v368 >> 2)) >> 1))))) >> 31))) & 104)) ^ (((~(((v370 ^ ((int)((unsigned int)((int)((unsigned int)v368 >> 2)) >> 1))) | (-(v370 ^ ((int)((unsigned int)((int)((unsigned int)v368 >> 2)) >> 1))))) >> 31)) | (~(((v372 ^ ((int)((unsigned int)((int)((unsigned int)v368 >> 2)) >> 1))) | (-(v372 ^ ((int)((unsigned int)((int)((unsigned int)v368 >> 2)) >> 1))))) >> 31))) & (1 ^ (100 ^ (((~(((v374 ^ ((int)((unsigned int)((int)((unsigned int)v368 >> 2)) >> 1))) | (-(v374 ^ ((int)((unsigned int)((int)((unsigned int)v368 >> 2)) >> 1))))) >> 31)) | (~(((v376 ^ ((int)((unsigned int)((int)((unsigned int)v368 >> 2)) >> 1))) | (-(v376 ^ ((int)((unsigned int)((int)((unsigned int)v368 >> 2)) >> 1))))) >> 31))) & 104)))));
  v492[11] = v611;
  int * v494 = v361->regs;
  v494[11] = v491;
  struct StateT * v496 = slot_6(v361);
  return v496;
}

struct StateT * slot_2(struct StateT * v38) {
  int v39 = v38->timer;
  int v40 = v38->timer;
  int v48 = v40 + 1;
  v38->timer = v48;
  int * v42 = v38->reg_ready;
  int v51 = v39 + 1;
  v42[15] = v51;
  int * v44 = v38->regs;
  v44[15] = 80;
  struct StateT * v46 = slot_3(v38);
  return v46;
}

struct StateT * slot_7(struct StateT * v640) {
  int v641 = v640->timer;
  int v642 = v640->timer;
  int v777 = v642 + 1;
  v640->timer = v777;
  int * v644 = v640->reg_ready;
  int v645 = v644[11];
  int * v646 = v640->regs;
  int v647 = v646[11];
  int * v648 = v640->cache_tags;
  int v782 = (((int)((unsigned int)((int)((unsigned int)v647 >> 2)) >> 1)) & 1) * 2;
  int v649 = v648[v782];
  int * v650 = v640->cache_tags;
  int v784 = ((((int)((unsigned int)((int)((unsigned int)v647 >> 2)) >> 1)) & 1) * 2) + 1;
  int v651 = v650[v784];
  int * v652 = v640->cache_tags;
  int v786 = 4 + ((((int)((unsigned int)((int)((unsigned int)v647 >> 2)) >> 1)) & 3) * 2);
  int v653 = v652[v786];
  int * v654 = v640->cache_tags;
  int v788 = (4 + ((((int)((unsigned int)((int)((unsigned int)v647 >> 2)) >> 1)) & 3) * 2)) + 1;
  int v655 = v654[v788];
  int * v656 = v640->cache_vals;
  bool v789 = !(((~(((v649 ^ ((int)((unsigned int)((int)((unsigned int)v647 >> 2)) >> 1))) | (-(v649 ^ ((int)((unsigned int)((int)((unsigned int)v647 >> 2)) >> 1))))) >> 31)) | (~(((v651 ^ ((int)((unsigned int)((int)((unsigned int)v647 >> 2)) >> 1))) | (-(v651 ^ ((int)((unsigned int)((int)((unsigned int)v647 >> 2)) >> 1))))) >> 31))) == 0);
  int v769;
  if (v789) {
    int * v657 = v640->cache_age;
    int v791 = ((((int)((unsigned int)((int)((unsigned int)v647 >> 2)) >> 1)) & 1) * 2) + ((~(((v651 ^ ((int)((unsigned int)((int)((unsigned int)v647 >> 2)) >> 1))) | (-(v651 ^ ((int)((unsigned int)((int)((unsigned int)v647 >> 2)) >> 1))))) >> 31)) & 1);
    int v658 = v657[v791];
    int * v659 = v640->cache_age;
    int v660 = v659[v782];
    int * v661 = v640->cache_age;
    int v794 = v660 + ((int)((unsigned int)(v660 - v658) >> 31));
    v661[v782] = v794;
    int * v663 = v640->cache_age;
    int v664 = v663[v784];
    int * v665 = v640->cache_age;
    int v797 = v664 + ((int)((unsigned int)(v664 - v658) >> 31));
    v665[v784] = v797;
    int * v667 = v640->cache_age;
    v667[v791] = 0;
    v769 = v791;
  } else {
    int * v670 = v640->cache_age;
    int v801 = (((int)((unsigned int)((int)((unsigned int)v647 >> 2)) >> 1)) & 1) * 2;
    int v671 = v670[v801];
    int * v672 = v640->cache_tags;
    int v673 = v672[v801];
    int * v674 = v640->cache_age;
    int v675 = v674[v784];
    int * v676 = v640->cache_tags;
    int v677 = v676[v784];
    bool v805 = !(((~(((v653 ^ ((int)((unsigned int)((int)((unsigned int)v647 >> 2)) >> 1))) | (-(v653 ^ ((int)((unsigned int)((int)((unsigned int)v647 >> 2)) >> 1))))) >> 31)) | (~(((v655 ^ ((int)((unsigned int)((int)((unsigned int)v647 >> 2)) >> 1))) | (-(v655 ^ ((int)((unsigned int)((int)((unsigned int)v647 >> 2)) >> 1))))) >> 31))) == 0);
    int v741;
    if (v805) {
      int * v678 = v640->cache_age;
      int v807 = (4 + ((((int)((unsigned int)((int)((unsigned int)v647 >> 2)) >> 1)) & 3) * 2)) + ((~(((v655 ^ ((int)((unsigned int)((int)((unsigned int)v647 >> 2)) >> 1))) | (-(v655 ^ ((int)((unsigned int)((int)((unsigned int)v647 >> 2)) >> 1))))) >> 31)) & 1);
      int v679 = v678[v807];
      int * v680 = v640->cache_age;
      int v681 = v680[v786];
      int * v682 = v640->cache_age;
      int v810 = v681 + ((int)((unsigned int)(v681 - v679) >> 31));
      v682[v786] = v810;
      int * v684 = v640->cache_age;
      int v685 = v684[v788];
      int * v686 = v640->cache_age;
      int v813 = v685 + ((int)((unsigned int)(v685 - v679) >> 31));
      v686[v788] = v813;
      int * v688 = v640->cache_age;
      v688[v807] = 0;
      v741 = v807;
    } else {
      int * v691 = v640->cache_age;
      int v817 = 4 + ((((int)((unsigned int)((int)((unsigned int)v647 >> 2)) >> 1)) & 3) * 2);
      int v692 = v691[v817];
      int * v693 = v640->cache_tags;
      int v694 = v693[v817];
      int * v695 = v640->cache_age;
      int v696 = v695[v788];
      int * v697 = v640->cache_tags;
      int v698 = v697[v788];
      int * v699 = v640->cache_dirty;
      int v822 = (4 + ((((int)((unsigned int)((int)((unsigned int)v647 >> 2)) >> 1)) & 3) * 2)) + ((((v692 + ((~(((v694 ^ -1) | (-(v694 ^ -1))) >> 31)) & 2)) - (v696 + ((~(((v698 ^ -1) | (-(v698 ^ -1))) >> 31)) & 2))) >> 31) & 1);
      int v700 = v699[v822];
      bool v823 = !(v700 == 0);
      if (v823) {
        int * v701 = v640->cache_tags;
        int v702 = v701[v822];
        int * v703 = v640->cache_vals;
        int v826 = ((4 + ((((int)((unsigned int)((int)((unsigned int)v647 >> 2)) >> 1)) & 3) * 2)) + ((((v692 + ((~(((v694 ^ -1) | (-(v694 ^ -1))) >> 31)) & 2)) - (v696 + ((~(((v698 ^ -1) | (-(v698 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
        int v704 = v703[v826];
        int * v705 = v640->cache_vals;
        int v828 = (((4 + ((((int)((unsigned int)((int)((unsigned int)v647 >> 2)) >> 1)) & 3) * 2)) + ((((v692 + ((~(((v694 ^ -1) | (-(v694 ^ -1))) >> 31)) & 2)) - (v696 + ((~(((v698 ^ -1) | (-(v698 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
        int v706 = v705[v828];
        int * v707 = v640->mem;
        int v830 = v702 * 2;
        v707[v830] = v704;
        int * v709 = v640->mem;
        int v833 = (v702 * 2) + 1;
        v709[v833] = v706;
        ;
      } else {
        ;
      }
      int * v714 = v640->mem;
      int v838 = ((int)((unsigned int)((int)((unsigned int)v647 >> 2)) >> 1)) * 2;
      int v715 = v714[v838];
      int * v716 = v640->mem;
      int v840 = (((int)((unsigned int)((int)((unsigned int)v647 >> 2)) >> 1)) * 2) + 1;
      int v717 = v716[v840];
      int * v718 = v640->cache_vals;
      int v842 = ((4 + ((((int)((unsigned int)((int)((unsigned int)v647 >> 2)) >> 1)) & 3) * 2)) + ((((v692 + ((~(((v694 ^ -1) | (-(v694 ^ -1))) >> 31)) & 2)) - (v696 + ((~(((v698 ^ -1) | (-(v698 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
      v718[v842] = v715;
      int * v720 = v640->cache_vals;
      int v845 = (((4 + ((((int)((unsigned int)((int)((unsigned int)v647 >> 2)) >> 1)) & 3) * 2)) + ((((v692 + ((~(((v694 ^ -1) | (-(v694 ^ -1))) >> 31)) & 2)) - (v696 + ((~(((v698 ^ -1) | (-(v698 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
      v720[v845] = v717;
      int * v722 = v640->cache_tags;
      int v848 = (int)((unsigned int)((int)((unsigned int)v647 >> 2)) >> 1);
      v722[v822] = v848;
      int * v724 = v640->cache_dirty;
      v724[v822] = 0;
      int * v726 = v640->cache_age;
      v726[v822] = 1;
      int * v728 = v640->cache_age;
      int v729 = v728[v822];
      int * v730 = v640->cache_age;
      int v731 = v730[v786];
      int * v732 = v640->cache_age;
      int v856 = v731 + ((int)((unsigned int)(v731 - v729) >> 31));
      v732[v786] = v856;
      int * v734 = v640->cache_age;
      int v735 = v734[v788];
      int * v736 = v640->cache_age;
      int v859 = v735 + ((int)((unsigned int)(v735 - v729) >> 31));
      v736[v788] = v859;
      int * v738 = v640->cache_age;
      v738[v822] = 0;
      v741 = v822;
    }
    int * v742 = v640->cache_vals;
    int v862 = v741 * 2;
    int v743 = v742[v862];
    int * v744 = v640->cache_vals;
    int v864 = (v741 * 2) + 1;
    int v745 = v744[v864];
    int * v746 = v640->cache_vals;
    int v866 = (((((int)((unsigned int)((int)((unsigned int)v647 >> 2)) >> 1)) & 1) * 2) + ((((v671 + ((~(((v673 ^ -1) | (-(v673 ^ -1))) >> 31)) & 2)) - (v675 + ((~(((v677 ^ -1) | (-(v677 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
    v746[v866] = v743;
    int * v748 = v640->cache_vals;
    int v869 = ((((((int)((unsigned int)((int)((unsigned int)v647 >> 2)) >> 1)) & 1) * 2) + ((((v671 + ((~(((v673 ^ -1) | (-(v673 ^ -1))) >> 31)) & 2)) - (v675 + ((~(((v677 ^ -1) | (-(v677 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
    v748[v869] = v745;
    int * v750 = v640->cache_tags;
    int v872 = ((((int)((unsigned int)((int)((unsigned int)v647 >> 2)) >> 1)) & 1) * 2) + ((((v671 + ((~(((v673 ^ -1) | (-(v673 ^ -1))) >> 31)) & 2)) - (v675 + ((~(((v677 ^ -1) | (-(v677 ^ -1))) >> 31)) & 2))) >> 31) & 1);
    int v873 = (int)((unsigned int)((int)((unsigned int)v647 >> 2)) >> 1);
    v750[v872] = v873;
    int * v752 = v640->cache_dirty;
    v752[v872] = 0;
    int * v754 = v640->cache_age;
    v754[v872] = 1;
    int * v756 = v640->cache_age;
    int v757 = v756[v872];
    int * v758 = v640->cache_age;
    int v759 = v758[v782];
    int * v760 = v640->cache_age;
    int v881 = v759 + ((int)((unsigned int)(v759 - v757) >> 31));
    v760[v782] = v881;
    int * v762 = v640->cache_age;
    int v763 = v762[v784];
    int * v764 = v640->cache_age;
    int v884 = v763 + ((int)((unsigned int)(v763 - v757) >> 31));
    v764[v784] = v884;
    int * v766 = v640->cache_age;
    v766[v872] = 0;
    v769 = v872;
  }
  int v887 = (v769 * 2) + (((int)((unsigned int)v647 >> 2)) & 1);
  int v770 = v656[v887];
  int * v771 = v640->reg_ready;
  int v890 = ((v645 + ((v641 - v645) & (~((v641 - v645) >> 31)))) + 1) + ((100 ^ (((~(((v653 ^ ((int)((unsigned int)((int)((unsigned int)v647 >> 2)) >> 1))) | (-(v653 ^ ((int)((unsigned int)((int)((unsigned int)v647 >> 2)) >> 1))))) >> 31)) | (~(((v655 ^ ((int)((unsigned int)((int)((unsigned int)v647 >> 2)) >> 1))) | (-(v655 ^ ((int)((unsigned int)((int)((unsigned int)v647 >> 2)) >> 1))))) >> 31))) & 104)) ^ (((~(((v649 ^ ((int)((unsigned int)((int)((unsigned int)v647 >> 2)) >> 1))) | (-(v649 ^ ((int)((unsigned int)((int)((unsigned int)v647 >> 2)) >> 1))))) >> 31)) | (~(((v651 ^ ((int)((unsigned int)((int)((unsigned int)v647 >> 2)) >> 1))) | (-(v651 ^ ((int)((unsigned int)((int)((unsigned int)v647 >> 2)) >> 1))))) >> 31))) & (1 ^ (100 ^ (((~(((v653 ^ ((int)((unsigned int)((int)((unsigned int)v647 >> 2)) >> 1))) | (-(v653 ^ ((int)((unsigned int)((int)((unsigned int)v647 >> 2)) >> 1))))) >> 31)) | (~(((v655 ^ ((int)((unsigned int)((int)((unsigned int)v647 >> 2)) >> 1))) | (-(v655 ^ ((int)((unsigned int)((int)((unsigned int)v647 >> 2)) >> 1))))) >> 31))) & 104)))));
  v771[12] = v890;
  int * v773 = v640->regs;
  v773[12] = v770;
  struct StateT * v775 = slot_8(v640);
  return v775;
}

struct StateT * slot_3(struct StateT * v56) {
  int v57 = v56->timer;
  int v58 = v56->timer;
  int v74 = v58 + 1;
  v56->timer = v74;
  int * v60 = v56->reg_ready;
  int v61 = v60[10];
  int * v62 = v56->regs;
  int v63 = v62[10];
  int * v64 = v56->reg_ready;
  int v65 = v64[15];
  int * v66 = v56->regs;
  int v67 = v66[15];
  bool v81 = v63 >= v67;
  struct StateT * v72;
  if (v81) {
    struct StateT * v68 = slot_8(v56);
    v72 = v68;
  } else {
    struct StateT * v70 = slot_4(v56);
    v72 = v70;
  }
  return v72;
}

struct StateT * snippet(struct StateT * v0) {
  struct StateT * v1 = slot_0(v0);
  int v895 = v1->timer;
  int * v896 = v1->reg_ready;
  int v897 = v896[0];
  int v1028 = v897 + ((v895 - v897) & (~((v895 - v897) >> 31)));
  v1->timer = v1028;
  int v899 = v1->timer;
  int * v900 = v1->reg_ready;
  int v901 = v900[1];
  int v1031 = v901 + ((v899 - v901) & (~((v899 - v901) >> 31)));
  v1->timer = v1031;
  int v903 = v1->timer;
  int * v904 = v1->reg_ready;
  int v905 = v904[2];
  int v1034 = v905 + ((v903 - v905) & (~((v903 - v905) >> 31)));
  v1->timer = v1034;
  int v907 = v1->timer;
  int * v908 = v1->reg_ready;
  int v909 = v908[3];
  int v1037 = v909 + ((v907 - v909) & (~((v907 - v909) >> 31)));
  v1->timer = v1037;
  int v911 = v1->timer;
  int * v912 = v1->reg_ready;
  int v913 = v912[4];
  int v1040 = v913 + ((v911 - v913) & (~((v911 - v913) >> 31)));
  v1->timer = v1040;
  int v915 = v1->timer;
  int * v916 = v1->reg_ready;
  int v917 = v916[5];
  int v1043 = v917 + ((v915 - v917) & (~((v915 - v917) >> 31)));
  v1->timer = v1043;
  int v919 = v1->timer;
  int * v920 = v1->reg_ready;
  int v921 = v920[6];
  int v1046 = v921 + ((v919 - v921) & (~((v919 - v921) >> 31)));
  v1->timer = v1046;
  int v923 = v1->timer;
  int * v924 = v1->reg_ready;
  int v925 = v924[7];
  int v1049 = v925 + ((v923 - v925) & (~((v923 - v925) >> 31)));
  v1->timer = v1049;
  int v927 = v1->timer;
  int * v928 = v1->reg_ready;
  int v929 = v928[8];
  int v1052 = v929 + ((v927 - v929) & (~((v927 - v929) >> 31)));
  v1->timer = v1052;
  int v931 = v1->timer;
  int * v932 = v1->reg_ready;
  int v933 = v932[9];
  int v1055 = v933 + ((v931 - v933) & (~((v931 - v933) >> 31)));
  v1->timer = v1055;
  int v935 = v1->timer;
  int * v936 = v1->reg_ready;
  int v937 = v936[10];
  int v1058 = v937 + ((v935 - v937) & (~((v935 - v937) >> 31)));
  v1->timer = v1058;
  int v939 = v1->timer;
  int * v940 = v1->reg_ready;
  int v941 = v940[11];
  int v1061 = v941 + ((v939 - v941) & (~((v939 - v941) >> 31)));
  v1->timer = v1061;
  int v943 = v1->timer;
  int * v944 = v1->reg_ready;
  int v945 = v944[12];
  int v1064 = v945 + ((v943 - v945) & (~((v943 - v945) >> 31)));
  v1->timer = v1064;
  int v947 = v1->timer;
  int * v948 = v1->reg_ready;
  int v949 = v948[13];
  int v1067 = v949 + ((v947 - v949) & (~((v947 - v949) >> 31)));
  v1->timer = v1067;
  int v951 = v1->timer;
  int * v952 = v1->reg_ready;
  int v953 = v952[14];
  int v1070 = v953 + ((v951 - v953) & (~((v951 - v953) >> 31)));
  v1->timer = v1070;
  int v955 = v1->timer;
  int * v956 = v1->reg_ready;
  int v957 = v956[15];
  int v1073 = v957 + ((v955 - v957) & (~((v955 - v957) >> 31)));
  v1->timer = v1073;
  int v959 = v1->timer;
  int * v960 = v1->reg_ready;
  int v961 = v960[16];
  int v1076 = v961 + ((v959 - v961) & (~((v959 - v961) >> 31)));
  v1->timer = v1076;
  int v963 = v1->timer;
  int * v964 = v1->reg_ready;
  int v965 = v964[17];
  int v1079 = v965 + ((v963 - v965) & (~((v963 - v965) >> 31)));
  v1->timer = v1079;
  int v967 = v1->timer;
  int * v968 = v1->reg_ready;
  int v969 = v968[18];
  int v1082 = v969 + ((v967 - v969) & (~((v967 - v969) >> 31)));
  v1->timer = v1082;
  int v971 = v1->timer;
  int * v972 = v1->reg_ready;
  int v973 = v972[19];
  int v1085 = v973 + ((v971 - v973) & (~((v971 - v973) >> 31)));
  v1->timer = v1085;
  int v975 = v1->timer;
  int * v976 = v1->reg_ready;
  int v977 = v976[20];
  int v1088 = v977 + ((v975 - v977) & (~((v975 - v977) >> 31)));
  v1->timer = v1088;
  int v979 = v1->timer;
  int * v980 = v1->reg_ready;
  int v981 = v980[21];
  int v1091 = v981 + ((v979 - v981) & (~((v979 - v981) >> 31)));
  v1->timer = v1091;
  int v983 = v1->timer;
  int * v984 = v1->reg_ready;
  int v985 = v984[22];
  int v1094 = v985 + ((v983 - v985) & (~((v983 - v985) >> 31)));
  v1->timer = v1094;
  int v987 = v1->timer;
  int * v988 = v1->reg_ready;
  int v989 = v988[23];
  int v1097 = v989 + ((v987 - v989) & (~((v987 - v989) >> 31)));
  v1->timer = v1097;
  int v991 = v1->timer;
  int * v992 = v1->reg_ready;
  int v993 = v992[24];
  int v1100 = v993 + ((v991 - v993) & (~((v991 - v993) >> 31)));
  v1->timer = v1100;
  int v995 = v1->timer;
  int * v996 = v1->reg_ready;
  int v997 = v996[25];
  int v1103 = v997 + ((v995 - v997) & (~((v995 - v997) >> 31)));
  v1->timer = v1103;
  int v999 = v1->timer;
  int * v1000 = v1->reg_ready;
  int v1001 = v1000[26];
  int v1106 = v1001 + ((v999 - v1001) & (~((v999 - v1001) >> 31)));
  v1->timer = v1106;
  int v1003 = v1->timer;
  int * v1004 = v1->reg_ready;
  int v1005 = v1004[27];
  int v1109 = v1005 + ((v1003 - v1005) & (~((v1003 - v1005) >> 31)));
  v1->timer = v1109;
  int v1007 = v1->timer;
  int * v1008 = v1->reg_ready;
  int v1009 = v1008[28];
  int v1112 = v1009 + ((v1007 - v1009) & (~((v1007 - v1009) >> 31)));
  v1->timer = v1112;
  int v1011 = v1->timer;
  int * v1012 = v1->reg_ready;
  int v1013 = v1012[29];
  int v1115 = v1013 + ((v1011 - v1013) & (~((v1011 - v1013) >> 31)));
  v1->timer = v1115;
  int v1015 = v1->timer;
  int * v1016 = v1->reg_ready;
  int v1017 = v1016[30];
  int v1118 = v1017 + ((v1015 - v1017) & (~((v1015 - v1017) >> 31)));
  v1->timer = v1118;
  int v1019 = v1->timer;
  int * v1020 = v1->reg_ready;
  int v1021 = v1020[31];
  int v1121 = v1021 + ((v1019 - v1021) & (~((v1019 - v1021) >> 31)));
  v1->timer = v1121;
  return v1;
}

struct StateT * slot_1(struct StateT * v20) {
  int v21 = v20->timer;
  int v22 = v20->timer;
  int v30 = v22 + 1;
  v20->timer = v30;
  int * v24 = v20->reg_ready;
  int v33 = v21 + 1;
  v24[10] = v33;
  int * v26 = v20->regs;
  v26[10] = 80;
  struct StateT * v28 = slot_2(v20);
  return v28;
}

struct StateT * slot_8(struct StateT * v87) {
  int v88 = v87->timer;
  int v89 = v87->timer;
  int v93 = v89 + 1;
  v87->timer = v93;
  struct StateT * v91 = slot_9(v87);
  return v91;
}

struct StateT * slot_4(struct StateT * v96) {
  int v97 = v96->timer;
  int v98 = v96->timer;
  int v114 = v98 + 1;
  v96->timer = v114;
  int * v100 = v96->reg_ready;
  int v101 = v100[13];
  int * v102 = v96->regs;
  int v103 = v102[13];
  int * v104 = v96->reg_ready;
  int v105 = v104[10];
  int * v106 = v96->regs;
  int v107 = v106[10];
  int * v108 = v96->reg_ready;
  int v123 = (v105 + (((v101 + ((v97 - v101) & (~((v97 - v101) >> 31)))) - v105) & (~(((v101 + ((v97 - v101) & (~((v97 - v101) >> 31)))) - v105) >> 31)))) + 1;
  v108[5] = v123;
  int * v110 = v96->regs;
  int v125 = v103 + v107;
  v110[5] = v125;
  struct StateT * v112 = slot_5(v96);
  return v112;
}

struct StateT * slot_9(struct StateT * v128) {
  int v129 = v128->timer;
  int v130 = v128->timer;
  int v260 = v130 + 1;
  v128->timer = v260;
  int * v132 = v128->cache_tags;
  int v133 = v132[0];
  int * v134 = v128->cache_tags;
  int v135 = v134[1];
  int * v136 = v128->cache_tags;
  int v137 = v136[4];
  int * v138 = v128->cache_tags;
  int v139 = v138[5];
  int * v140 = v128->cache_vals;
  bool v269 = !(((~((v133 | (-v133)) >> 31)) | (~((v135 | (-v135)) >> 31))) == 0);
  int v253;
  if (v269) {
    int * v141 = v128->cache_age;
    int v271 = (~((v135 | (-v135)) >> 31)) & 1;
    int v142 = v141[v271];
    int * v143 = v128->cache_age;
    int v144 = v143[0];
    int * v145 = v128->cache_age;
    int v274 = v144 + ((int)((unsigned int)(v144 - v142) >> 31));
    v145[0] = v274;
    int * v147 = v128->cache_age;
    int v148 = v147[1];
    int * v149 = v128->cache_age;
    int v277 = v148 + ((int)((unsigned int)(v148 - v142) >> 31));
    v149[1] = v277;
    int * v151 = v128->cache_age;
    v151[v271] = 0;
    v253 = v271;
  } else {
    int * v154 = v128->cache_age;
    int v155 = v154[0];
    int * v156 = v128->cache_tags;
    int v157 = v156[0];
    int * v158 = v128->cache_age;
    int v159 = v158[1];
    int * v160 = v128->cache_tags;
    int v161 = v160[1];
    bool v283 = !(((~((v137 | (-v137)) >> 31)) | (~((v139 | (-v139)) >> 31))) == 0);
    int v225;
    if (v283) {
      int * v162 = v128->cache_age;
      int v285 = 4 + ((~((v139 | (-v139)) >> 31)) & 1);
      int v163 = v162[v285];
      int * v164 = v128->cache_age;
      int v165 = v164[4];
      int * v166 = v128->cache_age;
      int v288 = v165 + ((int)((unsigned int)(v165 - v163) >> 31));
      v166[4] = v288;
      int * v168 = v128->cache_age;
      int v169 = v168[5];
      int * v170 = v128->cache_age;
      int v291 = v169 + ((int)((unsigned int)(v169 - v163) >> 31));
      v170[5] = v291;
      int * v172 = v128->cache_age;
      v172[v285] = 0;
      v225 = v285;
    } else {
      int * v175 = v128->cache_age;
      int v176 = v175[4];
      int * v177 = v128->cache_tags;
      int v178 = v177[4];
      int * v179 = v128->cache_age;
      int v180 = v179[5];
      int * v181 = v128->cache_tags;
      int v182 = v181[5];
      int * v183 = v128->cache_dirty;
      int v298 = 4 + ((((v176 + ((~(((v178 ^ -1) | (-(v178 ^ -1))) >> 31)) & 2)) - (v180 + ((~(((v182 ^ -1) | (-(v182 ^ -1))) >> 31)) & 2))) >> 31) & 1);
      int v184 = v183[v298];
      bool v299 = !(v184 == 0);
      if (v299) {
        int * v185 = v128->cache_tags;
        int v186 = v185[v298];
        int * v187 = v128->cache_vals;
        int v302 = (4 + ((((v176 + ((~(((v178 ^ -1) | (-(v178 ^ -1))) >> 31)) & 2)) - (v180 + ((~(((v182 ^ -1) | (-(v182 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
        int v188 = v187[v302];
        int * v189 = v128->cache_vals;
        int v304 = ((4 + ((((v176 + ((~(((v178 ^ -1) | (-(v178 ^ -1))) >> 31)) & 2)) - (v180 + ((~(((v182 ^ -1) | (-(v182 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
        int v190 = v189[v304];
        int * v191 = v128->mem;
        int v306 = v186 * 2;
        v191[v306] = v188;
        int * v193 = v128->mem;
        int v309 = (v186 * 2) + 1;
        v193[v309] = v190;
        ;
      } else {
        ;
      }
      int * v198 = v128->mem;
      int v199 = v198[0];
      int * v200 = v128->mem;
      int v201 = v200[1];
      int * v202 = v128->cache_vals;
      int v316 = (4 + ((((v176 + ((~(((v178 ^ -1) | (-(v178 ^ -1))) >> 31)) & 2)) - (v180 + ((~(((v182 ^ -1) | (-(v182 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
      v202[v316] = v199;
      int * v204 = v128->cache_vals;
      int v319 = ((4 + ((((v176 + ((~(((v178 ^ -1) | (-(v178 ^ -1))) >> 31)) & 2)) - (v180 + ((~(((v182 ^ -1) | (-(v182 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
      v204[v319] = v201;
      int * v206 = v128->cache_tags;
      v206[v298] = 0;
      int * v208 = v128->cache_dirty;
      v208[v298] = 0;
      int * v210 = v128->cache_age;
      v210[v298] = 1;
      int * v212 = v128->cache_age;
      int v213 = v212[v298];
      int * v214 = v128->cache_age;
      int v215 = v214[4];
      int * v216 = v128->cache_age;
      int v327 = v215 + ((int)((unsigned int)(v215 - v213) >> 31));
      v216[4] = v327;
      int * v218 = v128->cache_age;
      int v219 = v218[5];
      int * v220 = v128->cache_age;
      int v330 = v219 + ((int)((unsigned int)(v219 - v213) >> 31));
      v220[5] = v330;
      int * v222 = v128->cache_age;
      v222[v298] = 0;
      v225 = v298;
    }
    int * v226 = v128->cache_vals;
    int v333 = v225 * 2;
    int v227 = v226[v333];
    int * v228 = v128->cache_vals;
    int v335 = (v225 * 2) + 1;
    int v229 = v228[v335];
    int * v230 = v128->cache_vals;
    int v337 = ((((v155 + ((~(((v157 ^ -1) | (-(v157 ^ -1))) >> 31)) & 2)) - (v159 + ((~(((v161 ^ -1) | (-(v161 ^ -1))) >> 31)) & 2))) >> 31) & 1) * 2;
    v230[v337] = v227;
    int * v232 = v128->cache_vals;
    int v340 = (((((v155 + ((~(((v157 ^ -1) | (-(v157 ^ -1))) >> 31)) & 2)) - (v159 + ((~(((v161 ^ -1) | (-(v161 ^ -1))) >> 31)) & 2))) >> 31) & 1) * 2) + 1;
    v232[v340] = v229;
    int * v234 = v128->cache_tags;
    int v343 = (((v155 + ((~(((v157 ^ -1) | (-(v157 ^ -1))) >> 31)) & 2)) - (v159 + ((~(((v161 ^ -1) | (-(v161 ^ -1))) >> 31)) & 2))) >> 31) & 1;
    v234[v343] = 0;
    int * v236 = v128->cache_dirty;
    v236[v343] = 0;
    int * v238 = v128->cache_age;
    v238[v343] = 1;
    int * v240 = v128->cache_age;
    int v241 = v240[v343];
    int * v242 = v128->cache_age;
    int v243 = v242[0];
    int * v244 = v128->cache_age;
    int v349 = v243 + ((int)((unsigned int)(v243 - v241) >> 31));
    v244[0] = v349;
    int * v246 = v128->cache_age;
    int v247 = v246[1];
    int * v248 = v128->cache_age;
    int v352 = v247 + ((int)((unsigned int)(v247 - v241) >> 31));
    v248[1] = v352;
    int * v250 = v128->cache_age;
    v250[v343] = 0;
    v253 = v343;
  }
  int v355 = v253 * 2;
  int v254 = v140[v355];
  int * v255 = v128->reg_ready;
  int v358 = (v129 + 1) + ((100 ^ (((~((v137 | (-v137)) >> 31)) | (~((v139 | (-v139)) >> 31))) & 104)) ^ (((~((v133 | (-v133)) >> 31)) | (~((v135 | (-v135)) >> 31))) & (1 ^ (100 ^ (((~((v137 | (-v137)) >> 31)) | (~((v139 | (-v139)) >> 31))) & 104)))));
  v255[14] = v358;
  int * v257 = v128->regs;
  v257[14] = v254;
  return v128;
}

struct StateT * slot_0(struct StateT * v2) {
  int v3 = v2->timer;
  int v4 = v2->timer;
  int v12 = v4 + 1;
  v2->timer = v12;
  int * v6 = v2->reg_ready;
  int v15 = v3 + 1;
  v6[13] = v15;
  int * v8 = v2->regs;
  v8[13] = 0;
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
    s1.mem[SECRET_OFFSET+i] = secret(0, 20);
    s2.mem[SECRET_OFFSET+i] = secret(0, 20);
  }
  struct StateT *s1_ = snippet(&s1);
  struct StateT *s2_ = snippet(&s2);
  koika_assert(s1_->timer==s2_->timer, "timing leak");
  return 0;
}