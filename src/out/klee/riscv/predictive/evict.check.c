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
struct StateT * slot_1(struct StateT * v194);
struct StateT * slot_6(struct StateT * v616);
struct StateT * slot_5(struct StateT * v425);
struct StateT * slot_4(struct StateT * v237);
struct StateT * slot_2(struct StateT * v209);
struct StateT * slot_7(struct StateT * v820);
struct StateT * slot_3(struct StateT * v223);
struct StateT * slot_0(struct StateT * v2);
struct StateT * snippet(struct StateT * v0) {
  struct StateT * v1 = slot_0(v0);
  return v1;
}

struct StateT * slot_1(struct StateT * v194) {
  int v195 = v194->timer;
  int v202 = v195 + 1;
  v194->timer = v202;
  int * v197 = v194->regs;
  int v198 = v197[5];
  int v206 = v198 & 1;
  v197[6] = v206;
  struct StateT * v200 = slot_2(v194);
  return v200;
}

struct StateT * slot_6(struct StateT * v616) {
  int v617 = v616->timer;
  int v727 = v617 + 1;
  v616->timer = v727;
  int * v619 = v616->regs;
  int v620 = v619[6];
  int * v621 = v616->cache_tags;
  int v731 = (((int)((unsigned int)((int)((unsigned int)v620 >> 2)) >> 1)) & 1) * 2;
  int v622 = v621[v731];
  int v732 = ((((int)((unsigned int)((int)((unsigned int)v620 >> 2)) >> 1)) & 1) * 2) + 1;
  int v623 = v621[v732];
  int v733 = 4 + ((((int)((unsigned int)((int)((unsigned int)v620 >> 2)) >> 1)) & 3) * 2);
  int v624 = v621[v733];
  int v734 = (4 + ((((int)((unsigned int)((int)((unsigned int)v620 >> 2)) >> 1)) & 3) * 2)) + 1;
  int v625 = v621[v734];
  int v626 = v616->timer;
  int v735 = v626 + ((100 ^ (((~(((v624 ^ ((int)((unsigned int)((int)((unsigned int)v620 >> 2)) >> 1))) | (-(v624 ^ ((int)((unsigned int)((int)((unsigned int)v620 >> 2)) >> 1))))) >> 31)) | (~(((v625 ^ ((int)((unsigned int)((int)((unsigned int)v620 >> 2)) >> 1))) | (-(v625 ^ ((int)((unsigned int)((int)((unsigned int)v620 >> 2)) >> 1))))) >> 31))) & 104)) ^ (((~(((v622 ^ ((int)((unsigned int)((int)((unsigned int)v620 >> 2)) >> 1))) | (-(v622 ^ ((int)((unsigned int)((int)((unsigned int)v620 >> 2)) >> 1))))) >> 31)) | (~(((v623 ^ ((int)((unsigned int)((int)((unsigned int)v620 >> 2)) >> 1))) | (-(v623 ^ ((int)((unsigned int)((int)((unsigned int)v620 >> 2)) >> 1))))) >> 31))) & (1 ^ (100 ^ (((~(((v624 ^ ((int)((unsigned int)((int)((unsigned int)v620 >> 2)) >> 1))) | (-(v624 ^ ((int)((unsigned int)((int)((unsigned int)v620 >> 2)) >> 1))))) >> 31)) | (~(((v625 ^ ((int)((unsigned int)((int)((unsigned int)v620 >> 2)) >> 1))) | (-(v625 ^ ((int)((unsigned int)((int)((unsigned int)v620 >> 2)) >> 1))))) >> 31))) & 104)))));
  v616->timer = v735;
  int * v628 = v616->cache_vals;
  bool v736 = !(((~(((v622 ^ ((int)((unsigned int)((int)((unsigned int)v620 >> 2)) >> 1))) | (-(v622 ^ ((int)((unsigned int)((int)((unsigned int)v620 >> 2)) >> 1))))) >> 31)) | (~(((v623 ^ ((int)((unsigned int)((int)((unsigned int)v620 >> 2)) >> 1))) | (-(v623 ^ ((int)((unsigned int)((int)((unsigned int)v620 >> 2)) >> 1))))) >> 31))) == 0);
  int v721;
  if (v736) {
    int * v629 = v616->cache_age;
    int v738 = ((((int)((unsigned int)((int)((unsigned int)v620 >> 2)) >> 1)) & 1) * 2) + ((~(((v623 ^ ((int)((unsigned int)((int)((unsigned int)v620 >> 2)) >> 1))) | (-(v623 ^ ((int)((unsigned int)((int)((unsigned int)v620 >> 2)) >> 1))))) >> 31)) & 1);
    int v630 = v629[v738];
    int v631 = v629[v731];
    int v739 = v631 + ((int)((unsigned int)(v631 - v630) >> 31));
    v629[v731] = v739;
    int * v633 = v616->cache_age;
    int v634 = v633[v732];
    int v741 = v634 + ((int)((unsigned int)(v634 - v630) >> 31));
    v633[v732] = v741;
    int * v636 = v616->cache_age;
    v636[v738] = 0;
    v721 = v738;
  } else {
    int * v639 = v616->cache_age;
    int v745 = (((int)((unsigned int)((int)((unsigned int)v620 >> 2)) >> 1)) & 1) * 2;
    int v640 = v639[v745];
    int * v641 = v616->cache_tags;
    int v642 = v641[v745];
    int v643 = v639[v732];
    int v644 = v641[v732];
    bool v747 = !(((~(((v624 ^ ((int)((unsigned int)((int)((unsigned int)v620 >> 2)) >> 1))) | (-(v624 ^ ((int)((unsigned int)((int)((unsigned int)v620 >> 2)) >> 1))))) >> 31)) | (~(((v625 ^ ((int)((unsigned int)((int)((unsigned int)v620 >> 2)) >> 1))) | (-(v625 ^ ((int)((unsigned int)((int)((unsigned int)v620 >> 2)) >> 1))))) >> 31))) == 0);
    int v698;
    if (v747) {
      int * v645 = v616->cache_age;
      int v749 = (4 + ((((int)((unsigned int)((int)((unsigned int)v620 >> 2)) >> 1)) & 3) * 2)) + ((~(((v625 ^ ((int)((unsigned int)((int)((unsigned int)v620 >> 2)) >> 1))) | (-(v625 ^ ((int)((unsigned int)((int)((unsigned int)v620 >> 2)) >> 1))))) >> 31)) & 1);
      int v646 = v645[v749];
      int v647 = v645[v733];
      int v750 = v647 + ((int)((unsigned int)(v647 - v646) >> 31));
      v645[v733] = v750;
      int * v649 = v616->cache_age;
      int v650 = v649[v734];
      int v752 = v650 + ((int)((unsigned int)(v650 - v646) >> 31));
      v649[v734] = v752;
      int * v652 = v616->cache_age;
      v652[v749] = 0;
      v698 = v749;
    } else {
      int * v655 = v616->cache_age;
      int v756 = 4 + ((((int)((unsigned int)((int)((unsigned int)v620 >> 2)) >> 1)) & 3) * 2);
      int v656 = v655[v756];
      int * v657 = v616->cache_tags;
      int v658 = v657[v756];
      int v659 = v655[v734];
      int v660 = v657[v734];
      int * v661 = v616->cache_dirty;
      int v759 = (4 + ((((int)((unsigned int)((int)((unsigned int)v620 >> 2)) >> 1)) & 3) * 2)) + ((((v656 + ((~(((v658 ^ -1) | (-(v658 ^ -1))) >> 31)) & 2)) - (v659 + ((~(((v660 ^ -1) | (-(v660 ^ -1))) >> 31)) & 2))) >> 31) & 1);
      int v662 = v661[v759];
      bool v760 = !(v662 == 0);
      if (v760) {
        int * v663 = v616->cache_tags;
        int v664 = v663[v759];
        int * v665 = v616->cache_vals;
        int v763 = ((4 + ((((int)((unsigned int)((int)((unsigned int)v620 >> 2)) >> 1)) & 3) * 2)) + ((((v656 + ((~(((v658 ^ -1) | (-(v658 ^ -1))) >> 31)) & 2)) - (v659 + ((~(((v660 ^ -1) | (-(v660 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
        int v666 = v665[v763];
        int v764 = (((4 + ((((int)((unsigned int)((int)((unsigned int)v620 >> 2)) >> 1)) & 3) * 2)) + ((((v656 + ((~(((v658 ^ -1) | (-(v658 ^ -1))) >> 31)) & 2)) - (v659 + ((~(((v660 ^ -1) | (-(v660 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
        int v667 = v665[v764];
        int * v668 = v616->mem;
        int v766 = v664 * 2;
        v668[v766] = v666;
        int * v670 = v616->mem;
        int v769 = (v664 * 2) + 1;
        v670[v769] = v667;
        ;
      } else {
        ;
      }
      int * v675 = v616->mem;
      int v774 = ((int)((unsigned int)((int)((unsigned int)v620 >> 2)) >> 1)) * 2;
      int v676 = v675[v774];
      int v775 = (((int)((unsigned int)((int)((unsigned int)v620 >> 2)) >> 1)) * 2) + 1;
      int v677 = v675[v775];
      int * v678 = v616->cache_vals;
      int v777 = ((4 + ((((int)((unsigned int)((int)((unsigned int)v620 >> 2)) >> 1)) & 3) * 2)) + ((((v656 + ((~(((v658 ^ -1) | (-(v658 ^ -1))) >> 31)) & 2)) - (v659 + ((~(((v660 ^ -1) | (-(v660 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
      v678[v777] = v676;
      int * v680 = v616->cache_vals;
      int v780 = (((4 + ((((int)((unsigned int)((int)((unsigned int)v620 >> 2)) >> 1)) & 3) * 2)) + ((((v656 + ((~(((v658 ^ -1) | (-(v658 ^ -1))) >> 31)) & 2)) - (v659 + ((~(((v660 ^ -1) | (-(v660 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
      v680[v780] = v677;
      int * v682 = v616->cache_tags;
      int v783 = (int)((unsigned int)((int)((unsigned int)v620 >> 2)) >> 1);
      v682[v759] = v783;
      int * v684 = v616->cache_dirty;
      v684[v759] = 0;
      int * v686 = v616->cache_age;
      v686[v759] = 1;
      int * v688 = v616->cache_age;
      int v689 = v688[v759];
      int v690 = v688[v733];
      int v789 = v690 + ((int)((unsigned int)(v690 - v689) >> 31));
      v688[v733] = v789;
      int * v692 = v616->cache_age;
      int v693 = v692[v734];
      int v791 = v693 + ((int)((unsigned int)(v693 - v689) >> 31));
      v692[v734] = v791;
      int * v695 = v616->cache_age;
      v695[v759] = 0;
      v698 = v759;
    }
    int * v699 = v616->cache_vals;
    int v794 = v698 * 2;
    int v700 = v699[v794];
    int v795 = (v698 * 2) + 1;
    int v701 = v699[v795];
    int v796 = (((((int)((unsigned int)((int)((unsigned int)v620 >> 2)) >> 1)) & 1) * 2) + ((((v640 + ((~(((v642 ^ -1) | (-(v642 ^ -1))) >> 31)) & 2)) - (v643 + ((~(((v644 ^ -1) | (-(v644 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
    v699[v796] = v700;
    int * v703 = v616->cache_vals;
    int v799 = ((((((int)((unsigned int)((int)((unsigned int)v620 >> 2)) >> 1)) & 1) * 2) + ((((v640 + ((~(((v642 ^ -1) | (-(v642 ^ -1))) >> 31)) & 2)) - (v643 + ((~(((v644 ^ -1) | (-(v644 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
    v703[v799] = v701;
    int * v705 = v616->cache_tags;
    int v802 = ((((int)((unsigned int)((int)((unsigned int)v620 >> 2)) >> 1)) & 1) * 2) + ((((v640 + ((~(((v642 ^ -1) | (-(v642 ^ -1))) >> 31)) & 2)) - (v643 + ((~(((v644 ^ -1) | (-(v644 ^ -1))) >> 31)) & 2))) >> 31) & 1);
    int v803 = (int)((unsigned int)((int)((unsigned int)v620 >> 2)) >> 1);
    v705[v802] = v803;
    int * v707 = v616->cache_dirty;
    v707[v802] = 0;
    int * v709 = v616->cache_age;
    v709[v802] = 1;
    int * v711 = v616->cache_age;
    int v712 = v711[v802];
    int v713 = v711[v731];
    int v809 = v713 + ((int)((unsigned int)(v713 - v712) >> 31));
    v711[v731] = v809;
    int * v715 = v616->cache_age;
    int v716 = v715[v732];
    int v811 = v716 + ((int)((unsigned int)(v716 - v712) >> 31));
    v715[v732] = v811;
    int * v718 = v616->cache_age;
    v718[v802] = 0;
    v721 = v802;
  }
  int v814 = (v721 * 2) + (((int)((unsigned int)v620 >> 2)) & 1);
  int v722 = v628[v814];
  int * v723 = v616->regs;
  v723[9] = v722;
  struct StateT * v725 = slot_7(v616);
  return v725;
}

struct StateT * slot_5(struct StateT * v425) {
  int v426 = v425->timer;
  int v534 = v426 + 1;
  v425->timer = v534;
  int * v428 = v425->cache_tags;
  int v429 = v428[0];
  int v430 = v428[1];
  int v431 = v428[8];
  int v432 = v428[9];
  int v433 = v425->timer;
  int v540 = v433 + ((100 ^ (((~(((v431 ^ 2) | (-(v431 ^ 2))) >> 31)) | (~(((v432 ^ 2) | (-(v432 ^ 2))) >> 31))) & 104)) ^ (((~(((v429 ^ 2) | (-(v429 ^ 2))) >> 31)) | (~(((v430 ^ 2) | (-(v430 ^ 2))) >> 31))) & (1 ^ (100 ^ (((~(((v431 ^ 2) | (-(v431 ^ 2))) >> 31)) | (~(((v432 ^ 2) | (-(v432 ^ 2))) >> 31))) & 104)))));
  v425->timer = v540;
  int * v435 = v425->cache_vals;
  bool v541 = !(((~(((v429 ^ 2) | (-(v429 ^ 2))) >> 31)) | (~(((v430 ^ 2) | (-(v430 ^ 2))) >> 31))) == 0);
  int v528;
  if (v541) {
    int * v436 = v425->cache_age;
    int v543 = (~(((v430 ^ 2) | (-(v430 ^ 2))) >> 31)) & 1;
    int v437 = v436[v543];
    int v438 = v436[0];
    int v544 = v438 + ((int)((unsigned int)(v438 - v437) >> 31));
    v436[0] = v544;
    int * v440 = v425->cache_age;
    int v441 = v440[1];
    int v546 = v441 + ((int)((unsigned int)(v441 - v437) >> 31));
    v440[1] = v546;
    int * v443 = v425->cache_age;
    v443[v543] = 0;
    v528 = v543;
  } else {
    int * v446 = v425->cache_age;
    int v447 = v446[0];
    int * v448 = v425->cache_tags;
    int v449 = v448[0];
    int v450 = v446[1];
    int v451 = v448[1];
    bool v550 = !(((~(((v431 ^ 2) | (-(v431 ^ 2))) >> 31)) | (~(((v432 ^ 2) | (-(v432 ^ 2))) >> 31))) == 0);
    int v505;
    if (v550) {
      int * v452 = v425->cache_age;
      int v552 = 8 + ((~(((v432 ^ 2) | (-(v432 ^ 2))) >> 31)) & 1);
      int v453 = v452[v552];
      int v454 = v452[8];
      int v553 = v454 + ((int)((unsigned int)(v454 - v453) >> 31));
      v452[8] = v553;
      int * v456 = v425->cache_age;
      int v457 = v456[9];
      int v555 = v457 + ((int)((unsigned int)(v457 - v453) >> 31));
      v456[9] = v555;
      int * v459 = v425->cache_age;
      v459[v552] = 0;
      v505 = v552;
    } else {
      int * v462 = v425->cache_age;
      int v463 = v462[8];
      int * v464 = v425->cache_tags;
      int v465 = v464[8];
      int v466 = v462[9];
      int v467 = v464[9];
      int * v468 = v425->cache_dirty;
      int v560 = 8 + ((((v463 + ((~(((v465 ^ -1) | (-(v465 ^ -1))) >> 31)) & 2)) - (v466 + ((~(((v467 ^ -1) | (-(v467 ^ -1))) >> 31)) & 2))) >> 31) & 1);
      int v469 = v468[v560];
      bool v561 = !(v469 == 0);
      if (v561) {
        int * v470 = v425->cache_tags;
        int v471 = v470[v560];
        int * v472 = v425->cache_vals;
        int v564 = (8 + ((((v463 + ((~(((v465 ^ -1) | (-(v465 ^ -1))) >> 31)) & 2)) - (v466 + ((~(((v467 ^ -1) | (-(v467 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
        int v473 = v472[v564];
        int v565 = ((8 + ((((v463 + ((~(((v465 ^ -1) | (-(v465 ^ -1))) >> 31)) & 2)) - (v466 + ((~(((v467 ^ -1) | (-(v467 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
        int v474 = v472[v565];
        int * v475 = v425->mem;
        int v567 = v471 * 2;
        v475[v567] = v473;
        int * v477 = v425->mem;
        int v570 = (v471 * 2) + 1;
        v477[v570] = v474;
        ;
      } else {
        ;
      }
      int * v482 = v425->mem;
      int v483 = v482[4];
      int v484 = v482[5];
      int * v485 = v425->cache_vals;
      int v578 = (8 + ((((v463 + ((~(((v465 ^ -1) | (-(v465 ^ -1))) >> 31)) & 2)) - (v466 + ((~(((v467 ^ -1) | (-(v467 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
      v485[v578] = v483;
      int * v487 = v425->cache_vals;
      int v581 = ((8 + ((((v463 + ((~(((v465 ^ -1) | (-(v465 ^ -1))) >> 31)) & 2)) - (v466 + ((~(((v467 ^ -1) | (-(v467 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
      v487[v581] = v484;
      int * v489 = v425->cache_tags;
      v489[v560] = 2;
      int * v491 = v425->cache_dirty;
      v491[v560] = 0;
      int * v493 = v425->cache_age;
      v493[v560] = 1;
      int * v495 = v425->cache_age;
      int v496 = v495[v560];
      int v497 = v495[8];
      int v588 = v497 + ((int)((unsigned int)(v497 - v496) >> 31));
      v495[8] = v588;
      int * v499 = v425->cache_age;
      int v500 = v499[9];
      int v590 = v500 + ((int)((unsigned int)(v500 - v496) >> 31));
      v499[9] = v590;
      int * v502 = v425->cache_age;
      v502[v560] = 0;
      v505 = v560;
    }
    int * v506 = v425->cache_vals;
    int v593 = v505 * 2;
    int v507 = v506[v593];
    int v594 = (v505 * 2) + 1;
    int v508 = v506[v594];
    int v595 = ((((v447 + ((~(((v449 ^ -1) | (-(v449 ^ -1))) >> 31)) & 2)) - (v450 + ((~(((v451 ^ -1) | (-(v451 ^ -1))) >> 31)) & 2))) >> 31) & 1) * 2;
    v506[v595] = v507;
    int * v510 = v425->cache_vals;
    int v598 = (((((v447 + ((~(((v449 ^ -1) | (-(v449 ^ -1))) >> 31)) & 2)) - (v450 + ((~(((v451 ^ -1) | (-(v451 ^ -1))) >> 31)) & 2))) >> 31) & 1) * 2) + 1;
    v510[v598] = v508;
    int * v512 = v425->cache_tags;
    int v601 = (((v447 + ((~(((v449 ^ -1) | (-(v449 ^ -1))) >> 31)) & 2)) - (v450 + ((~(((v451 ^ -1) | (-(v451 ^ -1))) >> 31)) & 2))) >> 31) & 1;
    v512[v601] = 2;
    int * v514 = v425->cache_dirty;
    v514[v601] = 0;
    int * v516 = v425->cache_age;
    v516[v601] = 1;
    int * v518 = v425->cache_age;
    int v519 = v518[v601];
    int v520 = v518[0];
    int v606 = v520 + ((int)((unsigned int)(v520 - v519) >> 31));
    v518[0] = v606;
    int * v522 = v425->cache_age;
    int v523 = v522[1];
    int v608 = v523 + ((int)((unsigned int)(v523 - v519) >> 31));
    v522[1] = v608;
    int * v525 = v425->cache_age;
    v525[v601] = 0;
    v528 = v601;
  }
  int v611 = v528 * 2;
  int v529 = v435[v611];
  int * v530 = v425->regs;
  v530[8] = v529;
  struct StateT * v532 = slot_6(v425);
  return v532;
}

struct StateT * slot_4(struct StateT * v237) {
  int v238 = v237->timer;
  int v346 = v238 + 1;
  v237->timer = v346;
  int * v240 = v237->cache_tags;
  int v241 = v240[0];
  int v242 = v240[1];
  int v243 = v240[4];
  int v244 = v240[5];
  int v245 = v237->timer;
  int v352 = v245 + ((100 ^ (((~((v243 | (-v243)) >> 31)) | (~((v244 | (-v244)) >> 31))) & 104)) ^ (((~((v241 | (-v241)) >> 31)) | (~((v242 | (-v242)) >> 31))) & (1 ^ (100 ^ (((~((v243 | (-v243)) >> 31)) | (~((v244 | (-v244)) >> 31))) & 104)))));
  v237->timer = v352;
  int * v247 = v237->cache_vals;
  bool v353 = !(((~((v241 | (-v241)) >> 31)) | (~((v242 | (-v242)) >> 31))) == 0);
  int v340;
  if (v353) {
    int * v248 = v237->cache_age;
    int v355 = (~((v242 | (-v242)) >> 31)) & 1;
    int v249 = v248[v355];
    int v250 = v248[0];
    int v356 = v250 + ((int)((unsigned int)(v250 - v249) >> 31));
    v248[0] = v356;
    int * v252 = v237->cache_age;
    int v253 = v252[1];
    int v358 = v253 + ((int)((unsigned int)(v253 - v249) >> 31));
    v252[1] = v358;
    int * v255 = v237->cache_age;
    v255[v355] = 0;
    v340 = v355;
  } else {
    int * v258 = v237->cache_age;
    int v259 = v258[0];
    int * v260 = v237->cache_tags;
    int v261 = v260[0];
    int v262 = v258[1];
    int v263 = v260[1];
    bool v362 = !(((~((v243 | (-v243)) >> 31)) | (~((v244 | (-v244)) >> 31))) == 0);
    int v317;
    if (v362) {
      int * v264 = v237->cache_age;
      int v364 = 4 + ((~((v244 | (-v244)) >> 31)) & 1);
      int v265 = v264[v364];
      int v266 = v264[4];
      int v365 = v266 + ((int)((unsigned int)(v266 - v265) >> 31));
      v264[4] = v365;
      int * v268 = v237->cache_age;
      int v269 = v268[5];
      int v367 = v269 + ((int)((unsigned int)(v269 - v265) >> 31));
      v268[5] = v367;
      int * v271 = v237->cache_age;
      v271[v364] = 0;
      v317 = v364;
    } else {
      int * v274 = v237->cache_age;
      int v275 = v274[4];
      int * v276 = v237->cache_tags;
      int v277 = v276[4];
      int v278 = v274[5];
      int v279 = v276[5];
      int * v280 = v237->cache_dirty;
      int v372 = 4 + ((((v275 + ((~(((v277 ^ -1) | (-(v277 ^ -1))) >> 31)) & 2)) - (v278 + ((~(((v279 ^ -1) | (-(v279 ^ -1))) >> 31)) & 2))) >> 31) & 1);
      int v281 = v280[v372];
      bool v373 = !(v281 == 0);
      if (v373) {
        int * v282 = v237->cache_tags;
        int v283 = v282[v372];
        int * v284 = v237->cache_vals;
        int v376 = (4 + ((((v275 + ((~(((v277 ^ -1) | (-(v277 ^ -1))) >> 31)) & 2)) - (v278 + ((~(((v279 ^ -1) | (-(v279 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
        int v285 = v284[v376];
        int v377 = ((4 + ((((v275 + ((~(((v277 ^ -1) | (-(v277 ^ -1))) >> 31)) & 2)) - (v278 + ((~(((v279 ^ -1) | (-(v279 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
        int v286 = v284[v377];
        int * v287 = v237->mem;
        int v379 = v283 * 2;
        v287[v379] = v285;
        int * v289 = v237->mem;
        int v382 = (v283 * 2) + 1;
        v289[v382] = v286;
        ;
      } else {
        ;
      }
      int * v294 = v237->mem;
      int v295 = v294[0];
      int v296 = v294[1];
      int * v297 = v237->cache_vals;
      int v388 = (4 + ((((v275 + ((~(((v277 ^ -1) | (-(v277 ^ -1))) >> 31)) & 2)) - (v278 + ((~(((v279 ^ -1) | (-(v279 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
      v297[v388] = v295;
      int * v299 = v237->cache_vals;
      int v391 = ((4 + ((((v275 + ((~(((v277 ^ -1) | (-(v277 ^ -1))) >> 31)) & 2)) - (v278 + ((~(((v279 ^ -1) | (-(v279 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
      v299[v391] = v296;
      int * v301 = v237->cache_tags;
      v301[v372] = 0;
      int * v303 = v237->cache_dirty;
      v303[v372] = 0;
      int * v305 = v237->cache_age;
      v305[v372] = 1;
      int * v307 = v237->cache_age;
      int v308 = v307[v372];
      int v309 = v307[4];
      int v397 = v309 + ((int)((unsigned int)(v309 - v308) >> 31));
      v307[4] = v397;
      int * v311 = v237->cache_age;
      int v312 = v311[5];
      int v399 = v312 + ((int)((unsigned int)(v312 - v308) >> 31));
      v311[5] = v399;
      int * v314 = v237->cache_age;
      v314[v372] = 0;
      v317 = v372;
    }
    int * v318 = v237->cache_vals;
    int v402 = v317 * 2;
    int v319 = v318[v402];
    int v403 = (v317 * 2) + 1;
    int v320 = v318[v403];
    int v404 = ((((v259 + ((~(((v261 ^ -1) | (-(v261 ^ -1))) >> 31)) & 2)) - (v262 + ((~(((v263 ^ -1) | (-(v263 ^ -1))) >> 31)) & 2))) >> 31) & 1) * 2;
    v318[v404] = v319;
    int * v322 = v237->cache_vals;
    int v407 = (((((v259 + ((~(((v261 ^ -1) | (-(v261 ^ -1))) >> 31)) & 2)) - (v262 + ((~(((v263 ^ -1) | (-(v263 ^ -1))) >> 31)) & 2))) >> 31) & 1) * 2) + 1;
    v322[v407] = v320;
    int * v324 = v237->cache_tags;
    int v410 = (((v259 + ((~(((v261 ^ -1) | (-(v261 ^ -1))) >> 31)) & 2)) - (v262 + ((~(((v263 ^ -1) | (-(v263 ^ -1))) >> 31)) & 2))) >> 31) & 1;
    v324[v410] = 0;
    int * v326 = v237->cache_dirty;
    v326[v410] = 0;
    int * v328 = v237->cache_age;
    v328[v410] = 1;
    int * v330 = v237->cache_age;
    int v331 = v330[v410];
    int v332 = v330[0];
    int v414 = v332 + ((int)((unsigned int)(v332 - v331) >> 31));
    v330[0] = v414;
    int * v334 = v237->cache_age;
    int v335 = v334[1];
    int v416 = v335 + ((int)((unsigned int)(v335 - v331) >> 31));
    v334[1] = v416;
    int * v337 = v237->cache_age;
    v337[v410] = 0;
    v340 = v410;
  }
  int v419 = v340 * 2;
  int v341 = v247[v419];
  int * v342 = v237->regs;
  v342[7] = v341;
  struct StateT * v344 = slot_5(v237);
  return v344;
}

struct StateT * slot_2(struct StateT * v209) {
  int v210 = v209->timer;
  int v217 = v210 + 1;
  v209->timer = v217;
  int * v212 = v209->regs;
  int v213 = v212[6];
  int v220 = v213 << 3;
  v212[6] = v220;
  struct StateT * v215 = slot_3(v209);
  return v215;
}

struct StateT * slot_7(struct StateT * v820) {
  int v821 = v820->timer;
  int v928 = v821 + 1;
  v820->timer = v928;
  int * v823 = v820->cache_tags;
  int v824 = v823[0];
  int v825 = v823[1];
  int v826 = v823[4];
  int v827 = v823[5];
  int v828 = v820->timer;
  int v934 = v828 + ((100 ^ (((~((v826 | (-v826)) >> 31)) | (~((v827 | (-v827)) >> 31))) & 104)) ^ (((~((v824 | (-v824)) >> 31)) | (~((v825 | (-v825)) >> 31))) & (1 ^ (100 ^ (((~((v826 | (-v826)) >> 31)) | (~((v827 | (-v827)) >> 31))) & 104)))));
  v820->timer = v934;
  int * v830 = v820->cache_vals;
  bool v935 = !(((~((v824 | (-v824)) >> 31)) | (~((v825 | (-v825)) >> 31))) == 0);
  int v923;
  if (v935) {
    int * v831 = v820->cache_age;
    int v937 = (~((v825 | (-v825)) >> 31)) & 1;
    int v832 = v831[v937];
    int v833 = v831[0];
    int v938 = v833 + ((int)((unsigned int)(v833 - v832) >> 31));
    v831[0] = v938;
    int * v835 = v820->cache_age;
    int v836 = v835[1];
    int v940 = v836 + ((int)((unsigned int)(v836 - v832) >> 31));
    v835[1] = v940;
    int * v838 = v820->cache_age;
    v838[v937] = 0;
    v923 = v937;
  } else {
    int * v841 = v820->cache_age;
    int v842 = v841[0];
    int * v843 = v820->cache_tags;
    int v844 = v843[0];
    int v845 = v841[1];
    int v846 = v843[1];
    bool v944 = !(((~((v826 | (-v826)) >> 31)) | (~((v827 | (-v827)) >> 31))) == 0);
    int v900;
    if (v944) {
      int * v847 = v820->cache_age;
      int v946 = 4 + ((~((v827 | (-v827)) >> 31)) & 1);
      int v848 = v847[v946];
      int v849 = v847[4];
      int v947 = v849 + ((int)((unsigned int)(v849 - v848) >> 31));
      v847[4] = v947;
      int * v851 = v820->cache_age;
      int v852 = v851[5];
      int v949 = v852 + ((int)((unsigned int)(v852 - v848) >> 31));
      v851[5] = v949;
      int * v854 = v820->cache_age;
      v854[v946] = 0;
      v900 = v946;
    } else {
      int * v857 = v820->cache_age;
      int v858 = v857[4];
      int * v859 = v820->cache_tags;
      int v860 = v859[4];
      int v861 = v857[5];
      int v862 = v859[5];
      int * v863 = v820->cache_dirty;
      int v954 = 4 + ((((v858 + ((~(((v860 ^ -1) | (-(v860 ^ -1))) >> 31)) & 2)) - (v861 + ((~(((v862 ^ -1) | (-(v862 ^ -1))) >> 31)) & 2))) >> 31) & 1);
      int v864 = v863[v954];
      bool v955 = !(v864 == 0);
      if (v955) {
        int * v865 = v820->cache_tags;
        int v866 = v865[v954];
        int * v867 = v820->cache_vals;
        int v958 = (4 + ((((v858 + ((~(((v860 ^ -1) | (-(v860 ^ -1))) >> 31)) & 2)) - (v861 + ((~(((v862 ^ -1) | (-(v862 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
        int v868 = v867[v958];
        int v959 = ((4 + ((((v858 + ((~(((v860 ^ -1) | (-(v860 ^ -1))) >> 31)) & 2)) - (v861 + ((~(((v862 ^ -1) | (-(v862 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
        int v869 = v867[v959];
        int * v870 = v820->mem;
        int v961 = v866 * 2;
        v870[v961] = v868;
        int * v872 = v820->mem;
        int v964 = (v866 * 2) + 1;
        v872[v964] = v869;
        ;
      } else {
        ;
      }
      int * v877 = v820->mem;
      int v878 = v877[0];
      int v879 = v877[1];
      int * v880 = v820->cache_vals;
      int v970 = (4 + ((((v858 + ((~(((v860 ^ -1) | (-(v860 ^ -1))) >> 31)) & 2)) - (v861 + ((~(((v862 ^ -1) | (-(v862 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
      v880[v970] = v878;
      int * v882 = v820->cache_vals;
      int v973 = ((4 + ((((v858 + ((~(((v860 ^ -1) | (-(v860 ^ -1))) >> 31)) & 2)) - (v861 + ((~(((v862 ^ -1) | (-(v862 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
      v882[v973] = v879;
      int * v884 = v820->cache_tags;
      v884[v954] = 0;
      int * v886 = v820->cache_dirty;
      v886[v954] = 0;
      int * v888 = v820->cache_age;
      v888[v954] = 1;
      int * v890 = v820->cache_age;
      int v891 = v890[v954];
      int v892 = v890[4];
      int v979 = v892 + ((int)((unsigned int)(v892 - v891) >> 31));
      v890[4] = v979;
      int * v894 = v820->cache_age;
      int v895 = v894[5];
      int v981 = v895 + ((int)((unsigned int)(v895 - v891) >> 31));
      v894[5] = v981;
      int * v897 = v820->cache_age;
      v897[v954] = 0;
      v900 = v954;
    }
    int * v901 = v820->cache_vals;
    int v984 = v900 * 2;
    int v902 = v901[v984];
    int v985 = (v900 * 2) + 1;
    int v903 = v901[v985];
    int v986 = ((((v842 + ((~(((v844 ^ -1) | (-(v844 ^ -1))) >> 31)) & 2)) - (v845 + ((~(((v846 ^ -1) | (-(v846 ^ -1))) >> 31)) & 2))) >> 31) & 1) * 2;
    v901[v986] = v902;
    int * v905 = v820->cache_vals;
    int v989 = (((((v842 + ((~(((v844 ^ -1) | (-(v844 ^ -1))) >> 31)) & 2)) - (v845 + ((~(((v846 ^ -1) | (-(v846 ^ -1))) >> 31)) & 2))) >> 31) & 1) * 2) + 1;
    v905[v989] = v903;
    int * v907 = v820->cache_tags;
    int v992 = (((v842 + ((~(((v844 ^ -1) | (-(v844 ^ -1))) >> 31)) & 2)) - (v845 + ((~(((v846 ^ -1) | (-(v846 ^ -1))) >> 31)) & 2))) >> 31) & 1;
    v907[v992] = 0;
    int * v909 = v820->cache_dirty;
    v909[v992] = 0;
    int * v911 = v820->cache_age;
    v911[v992] = 1;
    int * v913 = v820->cache_age;
    int v914 = v913[v992];
    int v915 = v913[0];
    int v996 = v915 + ((int)((unsigned int)(v915 - v914) >> 31));
    v913[0] = v996;
    int * v917 = v820->cache_age;
    int v918 = v917[1];
    int v998 = v918 + ((int)((unsigned int)(v918 - v914) >> 31));
    v917[1] = v998;
    int * v920 = v820->cache_age;
    v920[v992] = 0;
    v923 = v992;
  }
  int v1001 = v923 * 2;
  int v924 = v830[v1001];
  int * v925 = v820->regs;
  v925[11] = v924;
  return v820;
}

struct StateT * slot_3(struct StateT * v223) {
  int v224 = v223->timer;
  int v231 = v224 + 1;
  v223->timer = v231;
  int * v226 = v223->regs;
  int v227 = v226[6];
  int v234 = v227 + 32;
  v226[6] = v234;
  struct StateT * v229 = slot_4(v223);
  return v229;
}

struct StateT * slot_0(struct StateT * v2) {
  int v3 = v2->timer;
  int v111 = v3 + 1;
  v2->timer = v111;
  int * v5 = v2->cache_tags;
  int v6 = v5[0];
  int v7 = v5[1];
  int v8 = v5[8];
  int v9 = v5[9];
  int v10 = v2->timer;
  int v117 = v10 + ((100 ^ (((~(((v8 ^ 10) | (-(v8 ^ 10))) >> 31)) | (~(((v9 ^ 10) | (-(v9 ^ 10))) >> 31))) & 104)) ^ (((~(((v6 ^ 10) | (-(v6 ^ 10))) >> 31)) | (~(((v7 ^ 10) | (-(v7 ^ 10))) >> 31))) & (1 ^ (100 ^ (((~(((v8 ^ 10) | (-(v8 ^ 10))) >> 31)) | (~(((v9 ^ 10) | (-(v9 ^ 10))) >> 31))) & 104)))));
  v2->timer = v117;
  int * v12 = v2->cache_vals;
  bool v118 = !(((~(((v6 ^ 10) | (-(v6 ^ 10))) >> 31)) | (~(((v7 ^ 10) | (-(v7 ^ 10))) >> 31))) == 0);
  int v105;
  if (v118) {
    int * v13 = v2->cache_age;
    int v120 = (~(((v7 ^ 10) | (-(v7 ^ 10))) >> 31)) & 1;
    int v14 = v13[v120];
    int v15 = v13[0];
    int v121 = v15 + ((int)((unsigned int)(v15 - v14) >> 31));
    v13[0] = v121;
    int * v17 = v2->cache_age;
    int v18 = v17[1];
    int v123 = v18 + ((int)((unsigned int)(v18 - v14) >> 31));
    v17[1] = v123;
    int * v20 = v2->cache_age;
    v20[v120] = 0;
    v105 = v120;
  } else {
    int * v23 = v2->cache_age;
    int v24 = v23[0];
    int * v25 = v2->cache_tags;
    int v26 = v25[0];
    int v27 = v23[1];
    int v28 = v25[1];
    bool v127 = !(((~(((v8 ^ 10) | (-(v8 ^ 10))) >> 31)) | (~(((v9 ^ 10) | (-(v9 ^ 10))) >> 31))) == 0);
    int v82;
    if (v127) {
      int * v29 = v2->cache_age;
      int v129 = 8 + ((~(((v9 ^ 10) | (-(v9 ^ 10))) >> 31)) & 1);
      int v30 = v29[v129];
      int v31 = v29[8];
      int v130 = v31 + ((int)((unsigned int)(v31 - v30) >> 31));
      v29[8] = v130;
      int * v33 = v2->cache_age;
      int v34 = v33[9];
      int v132 = v34 + ((int)((unsigned int)(v34 - v30) >> 31));
      v33[9] = v132;
      int * v36 = v2->cache_age;
      v36[v129] = 0;
      v82 = v129;
    } else {
      int * v39 = v2->cache_age;
      int v40 = v39[8];
      int * v41 = v2->cache_tags;
      int v42 = v41[8];
      int v43 = v39[9];
      int v44 = v41[9];
      int * v45 = v2->cache_dirty;
      int v137 = 8 + ((((v40 + ((~(((v42 ^ -1) | (-(v42 ^ -1))) >> 31)) & 2)) - (v43 + ((~(((v44 ^ -1) | (-(v44 ^ -1))) >> 31)) & 2))) >> 31) & 1);
      int v46 = v45[v137];
      bool v138 = !(v46 == 0);
      if (v138) {
        int * v47 = v2->cache_tags;
        int v48 = v47[v137];
        int * v49 = v2->cache_vals;
        int v141 = (8 + ((((v40 + ((~(((v42 ^ -1) | (-(v42 ^ -1))) >> 31)) & 2)) - (v43 + ((~(((v44 ^ -1) | (-(v44 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
        int v50 = v49[v141];
        int v142 = ((8 + ((((v40 + ((~(((v42 ^ -1) | (-(v42 ^ -1))) >> 31)) & 2)) - (v43 + ((~(((v44 ^ -1) | (-(v44 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
        int v51 = v49[v142];
        int * v52 = v2->mem;
        int v144 = v48 * 2;
        v52[v144] = v50;
        int * v54 = v2->mem;
        int v147 = (v48 * 2) + 1;
        v54[v147] = v51;
        ;
      } else {
        ;
      }
      int * v59 = v2->mem;
      int v60 = v59[20];
      int v61 = v59[21];
      int * v62 = v2->cache_vals;
      int v155 = (8 + ((((v40 + ((~(((v42 ^ -1) | (-(v42 ^ -1))) >> 31)) & 2)) - (v43 + ((~(((v44 ^ -1) | (-(v44 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
      v62[v155] = v60;
      int * v64 = v2->cache_vals;
      int v158 = ((8 + ((((v40 + ((~(((v42 ^ -1) | (-(v42 ^ -1))) >> 31)) & 2)) - (v43 + ((~(((v44 ^ -1) | (-(v44 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
      v64[v158] = v61;
      int * v66 = v2->cache_tags;
      v66[v137] = 10;
      int * v68 = v2->cache_dirty;
      v68[v137] = 0;
      int * v70 = v2->cache_age;
      v70[v137] = 1;
      int * v72 = v2->cache_age;
      int v73 = v72[v137];
      int v74 = v72[8];
      int v165 = v74 + ((int)((unsigned int)(v74 - v73) >> 31));
      v72[8] = v165;
      int * v76 = v2->cache_age;
      int v77 = v76[9];
      int v167 = v77 + ((int)((unsigned int)(v77 - v73) >> 31));
      v76[9] = v167;
      int * v79 = v2->cache_age;
      v79[v137] = 0;
      v82 = v137;
    }
    int * v83 = v2->cache_vals;
    int v170 = v82 * 2;
    int v84 = v83[v170];
    int v171 = (v82 * 2) + 1;
    int v85 = v83[v171];
    int v172 = ((((v24 + ((~(((v26 ^ -1) | (-(v26 ^ -1))) >> 31)) & 2)) - (v27 + ((~(((v28 ^ -1) | (-(v28 ^ -1))) >> 31)) & 2))) >> 31) & 1) * 2;
    v83[v172] = v84;
    int * v87 = v2->cache_vals;
    int v175 = (((((v24 + ((~(((v26 ^ -1) | (-(v26 ^ -1))) >> 31)) & 2)) - (v27 + ((~(((v28 ^ -1) | (-(v28 ^ -1))) >> 31)) & 2))) >> 31) & 1) * 2) + 1;
    v87[v175] = v85;
    int * v89 = v2->cache_tags;
    int v178 = (((v24 + ((~(((v26 ^ -1) | (-(v26 ^ -1))) >> 31)) & 2)) - (v27 + ((~(((v28 ^ -1) | (-(v28 ^ -1))) >> 31)) & 2))) >> 31) & 1;
    v89[v178] = 10;
    int * v91 = v2->cache_dirty;
    v91[v178] = 0;
    int * v93 = v2->cache_age;
    v93[v178] = 1;
    int * v95 = v2->cache_age;
    int v96 = v95[v178];
    int v97 = v95[0];
    int v183 = v97 + ((int)((unsigned int)(v97 - v96) >> 31));
    v95[0] = v183;
    int * v99 = v2->cache_age;
    int v100 = v99[1];
    int v185 = v100 + ((int)((unsigned int)(v100 - v96) >> 31));
    v99[1] = v185;
    int * v102 = v2->cache_age;
    v102[v178] = 0;
    v105 = v178;
  }
  int v188 = v105 * 2;
  int v106 = v12[v188];
  int * v107 = v2->regs;
  v107[5] = v106;
  struct StateT * v109 = slot_1(v2);
  return v109;
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