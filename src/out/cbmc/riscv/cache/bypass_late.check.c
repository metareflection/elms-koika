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
struct StateT * slot_1(struct StateT * v17);
struct StateT * slot_8(struct StateT * v610);
struct StateT * slot_6(struct StateT * v392);
struct StateT * slot_5(struct StateT * v77);
struct StateT * slot_4(struct StateT * v64);
struct StateT * slot_2(struct StateT * v30);
struct StateT * slot_7(struct StateT * v596);
struct StateT * slot_3(struct StateT * v49);
struct StateT * slot_0(struct StateT * v2);
struct StateT * snippet(struct StateT * v0) {
  struct StateT * v1 = slot_0(v0);
  return v1;
}

struct StateT * slot_1(struct StateT * v17) {
  int v18 = v17->timer;
  int v24 = v18 + 1;
  v17->timer = v24;
  int * v20 = v17->regs;
  v20[9] = 32;
  struct StateT * v22 = slot_2(v17);
  return v22;
}

struct StateT * slot_8(struct StateT * v610) {
  int v611 = v610->timer;
  int v720 = v611 + 1;
  v610->timer = v720;
  int * v613 = v610->regs;
  int v614 = v613[11];
  int * v615 = v610->cache_tags;
  int v724 = (((int)((unsigned int)((int)((unsigned int)v614 >> 2)) >> 1)) & 1) * 2;
  int v616 = v615[v724];
  int v725 = ((((int)((unsigned int)((int)((unsigned int)v614 >> 2)) >> 1)) & 1) * 2) + 1;
  int v617 = v615[v725];
  int v726 = 4 + ((((int)((unsigned int)((int)((unsigned int)v614 >> 2)) >> 1)) & 3) * 2);
  int v618 = v615[v726];
  int v727 = (4 + ((((int)((unsigned int)((int)((unsigned int)v614 >> 2)) >> 1)) & 3) * 2)) + 1;
  int v619 = v615[v727];
  int v620 = v610->timer;
  int v728 = v620 + ((100 ^ (((~(((v618 ^ ((int)((unsigned int)((int)((unsigned int)v614 >> 2)) >> 1))) | (-(v618 ^ ((int)((unsigned int)((int)((unsigned int)v614 >> 2)) >> 1))))) >> 31)) | (~(((v619 ^ ((int)((unsigned int)((int)((unsigned int)v614 >> 2)) >> 1))) | (-(v619 ^ ((int)((unsigned int)((int)((unsigned int)v614 >> 2)) >> 1))))) >> 31))) & 104)) ^ (((~(((v616 ^ ((int)((unsigned int)((int)((unsigned int)v614 >> 2)) >> 1))) | (-(v616 ^ ((int)((unsigned int)((int)((unsigned int)v614 >> 2)) >> 1))))) >> 31)) | (~(((v617 ^ ((int)((unsigned int)((int)((unsigned int)v614 >> 2)) >> 1))) | (-(v617 ^ ((int)((unsigned int)((int)((unsigned int)v614 >> 2)) >> 1))))) >> 31))) & (1 ^ (100 ^ (((~(((v618 ^ ((int)((unsigned int)((int)((unsigned int)v614 >> 2)) >> 1))) | (-(v618 ^ ((int)((unsigned int)((int)((unsigned int)v614 >> 2)) >> 1))))) >> 31)) | (~(((v619 ^ ((int)((unsigned int)((int)((unsigned int)v614 >> 2)) >> 1))) | (-(v619 ^ ((int)((unsigned int)((int)((unsigned int)v614 >> 2)) >> 1))))) >> 31))) & 104)))));
  v610->timer = v728;
  int * v622 = v610->cache_vals;
  bool v729 = !(((~(((v616 ^ ((int)((unsigned int)((int)((unsigned int)v614 >> 2)) >> 1))) | (-(v616 ^ ((int)((unsigned int)((int)((unsigned int)v614 >> 2)) >> 1))))) >> 31)) | (~(((v617 ^ ((int)((unsigned int)((int)((unsigned int)v614 >> 2)) >> 1))) | (-(v617 ^ ((int)((unsigned int)((int)((unsigned int)v614 >> 2)) >> 1))))) >> 31))) == 0);
  int v715;
  if (v729) {
    int * v623 = v610->cache_age;
    int v731 = ((((int)((unsigned int)((int)((unsigned int)v614 >> 2)) >> 1)) & 1) * 2) + ((~(((v617 ^ ((int)((unsigned int)((int)((unsigned int)v614 >> 2)) >> 1))) | (-(v617 ^ ((int)((unsigned int)((int)((unsigned int)v614 >> 2)) >> 1))))) >> 31)) & 1);
    int v624 = v623[v731];
    int v625 = v623[v724];
    int v732 = v625 + ((int)((unsigned int)(v625 - v624) >> 31));
    v623[v724] = v732;
    int * v627 = v610->cache_age;
    int v628 = v627[v725];
    int v734 = v628 + ((int)((unsigned int)(v628 - v624) >> 31));
    v627[v725] = v734;
    int * v630 = v610->cache_age;
    v630[v731] = 0;
    v715 = v731;
  } else {
    int * v633 = v610->cache_age;
    int v738 = (((int)((unsigned int)((int)((unsigned int)v614 >> 2)) >> 1)) & 1) * 2;
    int v634 = v633[v738];
    int * v635 = v610->cache_tags;
    int v636 = v635[v738];
    int v637 = v633[v725];
    int v638 = v635[v725];
    bool v740 = !(((~(((v618 ^ ((int)((unsigned int)((int)((unsigned int)v614 >> 2)) >> 1))) | (-(v618 ^ ((int)((unsigned int)((int)((unsigned int)v614 >> 2)) >> 1))))) >> 31)) | (~(((v619 ^ ((int)((unsigned int)((int)((unsigned int)v614 >> 2)) >> 1))) | (-(v619 ^ ((int)((unsigned int)((int)((unsigned int)v614 >> 2)) >> 1))))) >> 31))) == 0);
    int v692;
    if (v740) {
      int * v639 = v610->cache_age;
      int v742 = (4 + ((((int)((unsigned int)((int)((unsigned int)v614 >> 2)) >> 1)) & 3) * 2)) + ((~(((v619 ^ ((int)((unsigned int)((int)((unsigned int)v614 >> 2)) >> 1))) | (-(v619 ^ ((int)((unsigned int)((int)((unsigned int)v614 >> 2)) >> 1))))) >> 31)) & 1);
      int v640 = v639[v742];
      int v641 = v639[v726];
      int v743 = v641 + ((int)((unsigned int)(v641 - v640) >> 31));
      v639[v726] = v743;
      int * v643 = v610->cache_age;
      int v644 = v643[v727];
      int v745 = v644 + ((int)((unsigned int)(v644 - v640) >> 31));
      v643[v727] = v745;
      int * v646 = v610->cache_age;
      v646[v742] = 0;
      v692 = v742;
    } else {
      int * v649 = v610->cache_age;
      int v749 = 4 + ((((int)((unsigned int)((int)((unsigned int)v614 >> 2)) >> 1)) & 3) * 2);
      int v650 = v649[v749];
      int * v651 = v610->cache_tags;
      int v652 = v651[v749];
      int v653 = v649[v727];
      int v654 = v651[v727];
      int * v655 = v610->cache_dirty;
      int v752 = (4 + ((((int)((unsigned int)((int)((unsigned int)v614 >> 2)) >> 1)) & 3) * 2)) + ((((v650 + ((~(((v652 ^ -1) | (-(v652 ^ -1))) >> 31)) & 2)) - (v653 + ((~(((v654 ^ -1) | (-(v654 ^ -1))) >> 31)) & 2))) >> 31) & 1);
      int v656 = v655[v752];
      bool v753 = !(v656 == 0);
      if (v753) {
        int * v657 = v610->cache_tags;
        int v658 = v657[v752];
        int * v659 = v610->cache_vals;
        int v756 = ((4 + ((((int)((unsigned int)((int)((unsigned int)v614 >> 2)) >> 1)) & 3) * 2)) + ((((v650 + ((~(((v652 ^ -1) | (-(v652 ^ -1))) >> 31)) & 2)) - (v653 + ((~(((v654 ^ -1) | (-(v654 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
        int v660 = v659[v756];
        int v757 = (((4 + ((((int)((unsigned int)((int)((unsigned int)v614 >> 2)) >> 1)) & 3) * 2)) + ((((v650 + ((~(((v652 ^ -1) | (-(v652 ^ -1))) >> 31)) & 2)) - (v653 + ((~(((v654 ^ -1) | (-(v654 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
        int v661 = v659[v757];
        int * v662 = v610->mem;
        int v759 = v658 * 2;
        v662[v759] = v660;
        int * v664 = v610->mem;
        int v762 = (v658 * 2) + 1;
        v664[v762] = v661;
        ;
      } else {
        ;
      }
      int * v669 = v610->mem;
      int v767 = ((int)((unsigned int)((int)((unsigned int)v614 >> 2)) >> 1)) * 2;
      int v670 = v669[v767];
      int v768 = (((int)((unsigned int)((int)((unsigned int)v614 >> 2)) >> 1)) * 2) + 1;
      int v671 = v669[v768];
      int * v672 = v610->cache_vals;
      int v770 = ((4 + ((((int)((unsigned int)((int)((unsigned int)v614 >> 2)) >> 1)) & 3) * 2)) + ((((v650 + ((~(((v652 ^ -1) | (-(v652 ^ -1))) >> 31)) & 2)) - (v653 + ((~(((v654 ^ -1) | (-(v654 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
      v672[v770] = v670;
      int * v674 = v610->cache_vals;
      int v773 = (((4 + ((((int)((unsigned int)((int)((unsigned int)v614 >> 2)) >> 1)) & 3) * 2)) + ((((v650 + ((~(((v652 ^ -1) | (-(v652 ^ -1))) >> 31)) & 2)) - (v653 + ((~(((v654 ^ -1) | (-(v654 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
      v674[v773] = v671;
      int * v676 = v610->cache_tags;
      int v776 = (int)((unsigned int)((int)((unsigned int)v614 >> 2)) >> 1);
      v676[v752] = v776;
      int * v678 = v610->cache_dirty;
      v678[v752] = 0;
      int * v680 = v610->cache_age;
      v680[v752] = 1;
      int * v682 = v610->cache_age;
      int v683 = v682[v752];
      int v684 = v682[v726];
      int v782 = v684 + ((int)((unsigned int)(v684 - v683) >> 31));
      v682[v726] = v782;
      int * v686 = v610->cache_age;
      int v687 = v686[v727];
      int v784 = v687 + ((int)((unsigned int)(v687 - v683) >> 31));
      v686[v727] = v784;
      int * v689 = v610->cache_age;
      v689[v752] = 0;
      v692 = v752;
    }
    int * v693 = v610->cache_vals;
    int v787 = v692 * 2;
    int v694 = v693[v787];
    int v788 = (v692 * 2) + 1;
    int v695 = v693[v788];
    int v789 = (((((int)((unsigned int)((int)((unsigned int)v614 >> 2)) >> 1)) & 1) * 2) + ((((v634 + ((~(((v636 ^ -1) | (-(v636 ^ -1))) >> 31)) & 2)) - (v637 + ((~(((v638 ^ -1) | (-(v638 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
    v693[v789] = v694;
    int * v697 = v610->cache_vals;
    int v792 = ((((((int)((unsigned int)((int)((unsigned int)v614 >> 2)) >> 1)) & 1) * 2) + ((((v634 + ((~(((v636 ^ -1) | (-(v636 ^ -1))) >> 31)) & 2)) - (v637 + ((~(((v638 ^ -1) | (-(v638 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
    v697[v792] = v695;
    int * v699 = v610->cache_tags;
    int v795 = ((((int)((unsigned int)((int)((unsigned int)v614 >> 2)) >> 1)) & 1) * 2) + ((((v634 + ((~(((v636 ^ -1) | (-(v636 ^ -1))) >> 31)) & 2)) - (v637 + ((~(((v638 ^ -1) | (-(v638 ^ -1))) >> 31)) & 2))) >> 31) & 1);
    int v796 = (int)((unsigned int)((int)((unsigned int)v614 >> 2)) >> 1);
    v699[v795] = v796;
    int * v701 = v610->cache_dirty;
    v701[v795] = 0;
    int * v703 = v610->cache_age;
    v703[v795] = 1;
    int * v705 = v610->cache_age;
    int v706 = v705[v795];
    int v707 = v705[v724];
    int v802 = v707 + ((int)((unsigned int)(v707 - v706) >> 31));
    v705[v724] = v802;
    int * v709 = v610->cache_age;
    int v710 = v709[v725];
    int v804 = v710 + ((int)((unsigned int)(v710 - v706) >> 31));
    v709[v725] = v804;
    int * v712 = v610->cache_age;
    v712[v795] = 0;
    v715 = v795;
  }
  int v807 = (v715 * 2) + (((int)((unsigned int)v614 >> 2)) & 1);
  int v716 = v622[v807];
  int * v717 = v610->regs;
  v717[12] = v716;
  return v610;
}

struct StateT * slot_6(struct StateT * v392) {
  int v393 = v392->timer;
  int v503 = v393 + 1;
  v392->timer = v503;
  int * v395 = v392->regs;
  int v396 = v395[6];
  int * v397 = v392->cache_tags;
  int v507 = (((int)((unsigned int)((int)((unsigned int)v396 >> 2)) >> 1)) & 1) * 2;
  int v398 = v397[v507];
  int v508 = ((((int)((unsigned int)((int)((unsigned int)v396 >> 2)) >> 1)) & 1) * 2) + 1;
  int v399 = v397[v508];
  int v509 = 4 + ((((int)((unsigned int)((int)((unsigned int)v396 >> 2)) >> 1)) & 3) * 2);
  int v400 = v397[v509];
  int v510 = (4 + ((((int)((unsigned int)((int)((unsigned int)v396 >> 2)) >> 1)) & 3) * 2)) + 1;
  int v401 = v397[v510];
  int v402 = v392->timer;
  int v511 = v402 + ((100 ^ (((~(((v400 ^ ((int)((unsigned int)((int)((unsigned int)v396 >> 2)) >> 1))) | (-(v400 ^ ((int)((unsigned int)((int)((unsigned int)v396 >> 2)) >> 1))))) >> 31)) | (~(((v401 ^ ((int)((unsigned int)((int)((unsigned int)v396 >> 2)) >> 1))) | (-(v401 ^ ((int)((unsigned int)((int)((unsigned int)v396 >> 2)) >> 1))))) >> 31))) & 104)) ^ (((~(((v398 ^ ((int)((unsigned int)((int)((unsigned int)v396 >> 2)) >> 1))) | (-(v398 ^ ((int)((unsigned int)((int)((unsigned int)v396 >> 2)) >> 1))))) >> 31)) | (~(((v399 ^ ((int)((unsigned int)((int)((unsigned int)v396 >> 2)) >> 1))) | (-(v399 ^ ((int)((unsigned int)((int)((unsigned int)v396 >> 2)) >> 1))))) >> 31))) & (1 ^ (100 ^ (((~(((v400 ^ ((int)((unsigned int)((int)((unsigned int)v396 >> 2)) >> 1))) | (-(v400 ^ ((int)((unsigned int)((int)((unsigned int)v396 >> 2)) >> 1))))) >> 31)) | (~(((v401 ^ ((int)((unsigned int)((int)((unsigned int)v396 >> 2)) >> 1))) | (-(v401 ^ ((int)((unsigned int)((int)((unsigned int)v396 >> 2)) >> 1))))) >> 31))) & 104)))));
  v392->timer = v511;
  int * v404 = v392->cache_vals;
  bool v512 = !(((~(((v398 ^ ((int)((unsigned int)((int)((unsigned int)v396 >> 2)) >> 1))) | (-(v398 ^ ((int)((unsigned int)((int)((unsigned int)v396 >> 2)) >> 1))))) >> 31)) | (~(((v399 ^ ((int)((unsigned int)((int)((unsigned int)v396 >> 2)) >> 1))) | (-(v399 ^ ((int)((unsigned int)((int)((unsigned int)v396 >> 2)) >> 1))))) >> 31))) == 0);
  int v497;
  if (v512) {
    int * v405 = v392->cache_age;
    int v514 = ((((int)((unsigned int)((int)((unsigned int)v396 >> 2)) >> 1)) & 1) * 2) + ((~(((v399 ^ ((int)((unsigned int)((int)((unsigned int)v396 >> 2)) >> 1))) | (-(v399 ^ ((int)((unsigned int)((int)((unsigned int)v396 >> 2)) >> 1))))) >> 31)) & 1);
    int v406 = v405[v514];
    int v407 = v405[v507];
    int v515 = v407 + ((int)((unsigned int)(v407 - v406) >> 31));
    v405[v507] = v515;
    int * v409 = v392->cache_age;
    int v410 = v409[v508];
    int v517 = v410 + ((int)((unsigned int)(v410 - v406) >> 31));
    v409[v508] = v517;
    int * v412 = v392->cache_age;
    v412[v514] = 0;
    v497 = v514;
  } else {
    int * v415 = v392->cache_age;
    int v521 = (((int)((unsigned int)((int)((unsigned int)v396 >> 2)) >> 1)) & 1) * 2;
    int v416 = v415[v521];
    int * v417 = v392->cache_tags;
    int v418 = v417[v521];
    int v419 = v415[v508];
    int v420 = v417[v508];
    bool v523 = !(((~(((v400 ^ ((int)((unsigned int)((int)((unsigned int)v396 >> 2)) >> 1))) | (-(v400 ^ ((int)((unsigned int)((int)((unsigned int)v396 >> 2)) >> 1))))) >> 31)) | (~(((v401 ^ ((int)((unsigned int)((int)((unsigned int)v396 >> 2)) >> 1))) | (-(v401 ^ ((int)((unsigned int)((int)((unsigned int)v396 >> 2)) >> 1))))) >> 31))) == 0);
    int v474;
    if (v523) {
      int * v421 = v392->cache_age;
      int v525 = (4 + ((((int)((unsigned int)((int)((unsigned int)v396 >> 2)) >> 1)) & 3) * 2)) + ((~(((v401 ^ ((int)((unsigned int)((int)((unsigned int)v396 >> 2)) >> 1))) | (-(v401 ^ ((int)((unsigned int)((int)((unsigned int)v396 >> 2)) >> 1))))) >> 31)) & 1);
      int v422 = v421[v525];
      int v423 = v421[v509];
      int v526 = v423 + ((int)((unsigned int)(v423 - v422) >> 31));
      v421[v509] = v526;
      int * v425 = v392->cache_age;
      int v426 = v425[v510];
      int v528 = v426 + ((int)((unsigned int)(v426 - v422) >> 31));
      v425[v510] = v528;
      int * v428 = v392->cache_age;
      v428[v525] = 0;
      v474 = v525;
    } else {
      int * v431 = v392->cache_age;
      int v532 = 4 + ((((int)((unsigned int)((int)((unsigned int)v396 >> 2)) >> 1)) & 3) * 2);
      int v432 = v431[v532];
      int * v433 = v392->cache_tags;
      int v434 = v433[v532];
      int v435 = v431[v510];
      int v436 = v433[v510];
      int * v437 = v392->cache_dirty;
      int v535 = (4 + ((((int)((unsigned int)((int)((unsigned int)v396 >> 2)) >> 1)) & 3) * 2)) + ((((v432 + ((~(((v434 ^ -1) | (-(v434 ^ -1))) >> 31)) & 2)) - (v435 + ((~(((v436 ^ -1) | (-(v436 ^ -1))) >> 31)) & 2))) >> 31) & 1);
      int v438 = v437[v535];
      bool v536 = !(v438 == 0);
      if (v536) {
        int * v439 = v392->cache_tags;
        int v440 = v439[v535];
        int * v441 = v392->cache_vals;
        int v539 = ((4 + ((((int)((unsigned int)((int)((unsigned int)v396 >> 2)) >> 1)) & 3) * 2)) + ((((v432 + ((~(((v434 ^ -1) | (-(v434 ^ -1))) >> 31)) & 2)) - (v435 + ((~(((v436 ^ -1) | (-(v436 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
        int v442 = v441[v539];
        int v540 = (((4 + ((((int)((unsigned int)((int)((unsigned int)v396 >> 2)) >> 1)) & 3) * 2)) + ((((v432 + ((~(((v434 ^ -1) | (-(v434 ^ -1))) >> 31)) & 2)) - (v435 + ((~(((v436 ^ -1) | (-(v436 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
        int v443 = v441[v540];
        int * v444 = v392->mem;
        int v542 = v440 * 2;
        v444[v542] = v442;
        int * v446 = v392->mem;
        int v545 = (v440 * 2) + 1;
        v446[v545] = v443;
        ;
      } else {
        ;
      }
      int * v451 = v392->mem;
      int v550 = ((int)((unsigned int)((int)((unsigned int)v396 >> 2)) >> 1)) * 2;
      int v452 = v451[v550];
      int v551 = (((int)((unsigned int)((int)((unsigned int)v396 >> 2)) >> 1)) * 2) + 1;
      int v453 = v451[v551];
      int * v454 = v392->cache_vals;
      int v553 = ((4 + ((((int)((unsigned int)((int)((unsigned int)v396 >> 2)) >> 1)) & 3) * 2)) + ((((v432 + ((~(((v434 ^ -1) | (-(v434 ^ -1))) >> 31)) & 2)) - (v435 + ((~(((v436 ^ -1) | (-(v436 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
      v454[v553] = v452;
      int * v456 = v392->cache_vals;
      int v556 = (((4 + ((((int)((unsigned int)((int)((unsigned int)v396 >> 2)) >> 1)) & 3) * 2)) + ((((v432 + ((~(((v434 ^ -1) | (-(v434 ^ -1))) >> 31)) & 2)) - (v435 + ((~(((v436 ^ -1) | (-(v436 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
      v456[v556] = v453;
      int * v458 = v392->cache_tags;
      int v559 = (int)((unsigned int)((int)((unsigned int)v396 >> 2)) >> 1);
      v458[v535] = v559;
      int * v460 = v392->cache_dirty;
      v460[v535] = 0;
      int * v462 = v392->cache_age;
      v462[v535] = 1;
      int * v464 = v392->cache_age;
      int v465 = v464[v535];
      int v466 = v464[v509];
      int v565 = v466 + ((int)((unsigned int)(v466 - v465) >> 31));
      v464[v509] = v565;
      int * v468 = v392->cache_age;
      int v469 = v468[v510];
      int v567 = v469 + ((int)((unsigned int)(v469 - v465) >> 31));
      v468[v510] = v567;
      int * v471 = v392->cache_age;
      v471[v535] = 0;
      v474 = v535;
    }
    int * v475 = v392->cache_vals;
    int v570 = v474 * 2;
    int v476 = v475[v570];
    int v571 = (v474 * 2) + 1;
    int v477 = v475[v571];
    int v572 = (((((int)((unsigned int)((int)((unsigned int)v396 >> 2)) >> 1)) & 1) * 2) + ((((v416 + ((~(((v418 ^ -1) | (-(v418 ^ -1))) >> 31)) & 2)) - (v419 + ((~(((v420 ^ -1) | (-(v420 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
    v475[v572] = v476;
    int * v479 = v392->cache_vals;
    int v575 = ((((((int)((unsigned int)((int)((unsigned int)v396 >> 2)) >> 1)) & 1) * 2) + ((((v416 + ((~(((v418 ^ -1) | (-(v418 ^ -1))) >> 31)) & 2)) - (v419 + ((~(((v420 ^ -1) | (-(v420 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
    v479[v575] = v477;
    int * v481 = v392->cache_tags;
    int v578 = ((((int)((unsigned int)((int)((unsigned int)v396 >> 2)) >> 1)) & 1) * 2) + ((((v416 + ((~(((v418 ^ -1) | (-(v418 ^ -1))) >> 31)) & 2)) - (v419 + ((~(((v420 ^ -1) | (-(v420 ^ -1))) >> 31)) & 2))) >> 31) & 1);
    int v579 = (int)((unsigned int)((int)((unsigned int)v396 >> 2)) >> 1);
    v481[v578] = v579;
    int * v483 = v392->cache_dirty;
    v483[v578] = 0;
    int * v485 = v392->cache_age;
    v485[v578] = 1;
    int * v487 = v392->cache_age;
    int v488 = v487[v578];
    int v489 = v487[v507];
    int v585 = v489 + ((int)((unsigned int)(v489 - v488) >> 31));
    v487[v507] = v585;
    int * v491 = v392->cache_age;
    int v492 = v491[v508];
    int v587 = v492 + ((int)((unsigned int)(v492 - v488) >> 31));
    v491[v508] = v587;
    int * v494 = v392->cache_age;
    v494[v578] = 0;
    v497 = v578;
  }
  int v590 = (v497 * 2) + (((int)((unsigned int)v396 >> 2)) & 1);
  int v498 = v404[v590];
  int * v499 = v392->regs;
  v499[11] = v498;
  struct StateT * v501 = slot_7(v392);
  return v501;
}

struct StateT * slot_5(struct StateT * v77) {
  int v78 = v77->timer;
  int v248 = v78 + 1;
  v77->timer = v248;
  int * v80 = v77->regs;
  int v81 = v80[6];
  int v82 = v80[7];
  int * v83 = v77->cache_tags;
  int v253 = (((int)((unsigned int)((int)((unsigned int)v81 >> 2)) >> 1)) & 1) * 2;
  int v84 = v83[v253];
  int v254 = ((((int)((unsigned int)((int)((unsigned int)v81 >> 2)) >> 1)) & 1) * 2) + 1;
  int v85 = v83[v254];
  int v255 = 4 + ((((int)((unsigned int)((int)((unsigned int)v81 >> 2)) >> 1)) & 3) * 2);
  int v86 = v83[v255];
  int v256 = (4 + ((((int)((unsigned int)((int)((unsigned int)v81 >> 2)) >> 1)) & 3) * 2)) + 1;
  int v87 = v83[v256];
  int v88 = v77->timer;
  int v257 = v88 + ((100 ^ (((~(((v86 ^ ((int)((unsigned int)((int)((unsigned int)v81 >> 2)) >> 1))) | (-(v86 ^ ((int)((unsigned int)((int)((unsigned int)v81 >> 2)) >> 1))))) >> 31)) | (~(((v87 ^ ((int)((unsigned int)((int)((unsigned int)v81 >> 2)) >> 1))) | (-(v87 ^ ((int)((unsigned int)((int)((unsigned int)v81 >> 2)) >> 1))))) >> 31))) & 104)) ^ (((~(((v84 ^ ((int)((unsigned int)((int)((unsigned int)v81 >> 2)) >> 1))) | (-(v84 ^ ((int)((unsigned int)((int)((unsigned int)v81 >> 2)) >> 1))))) >> 31)) | (~(((v85 ^ ((int)((unsigned int)((int)((unsigned int)v81 >> 2)) >> 1))) | (-(v85 ^ ((int)((unsigned int)((int)((unsigned int)v81 >> 2)) >> 1))))) >> 31))) & (1 ^ (100 ^ (((~(((v86 ^ ((int)((unsigned int)((int)((unsigned int)v81 >> 2)) >> 1))) | (-(v86 ^ ((int)((unsigned int)((int)((unsigned int)v81 >> 2)) >> 1))))) >> 31)) | (~(((v87 ^ ((int)((unsigned int)((int)((unsigned int)v81 >> 2)) >> 1))) | (-(v87 ^ ((int)((unsigned int)((int)((unsigned int)v81 >> 2)) >> 1))))) >> 31))) & 104)))));
  v77->timer = v257;
  bool v258 = !(((~(((v84 ^ ((int)((unsigned int)((int)((unsigned int)v81 >> 2)) >> 1))) | (-(v84 ^ ((int)((unsigned int)((int)((unsigned int)v81 >> 2)) >> 1))))) >> 31)) | (~(((v85 ^ ((int)((unsigned int)((int)((unsigned int)v81 >> 2)) >> 1))) | (-(v85 ^ ((int)((unsigned int)((int)((unsigned int)v81 >> 2)) >> 1))))) >> 31))) == 0);
  int v182;
  if (v258) {
    int * v90 = v77->cache_age;
    int v260 = ((((int)((unsigned int)((int)((unsigned int)v81 >> 2)) >> 1)) & 1) * 2) + ((~(((v85 ^ ((int)((unsigned int)((int)((unsigned int)v81 >> 2)) >> 1))) | (-(v85 ^ ((int)((unsigned int)((int)((unsigned int)v81 >> 2)) >> 1))))) >> 31)) & 1);
    int v91 = v90[v260];
    int v92 = v90[v253];
    int v261 = v92 + ((int)((unsigned int)(v92 - v91) >> 31));
    v90[v253] = v261;
    int * v94 = v77->cache_age;
    int v95 = v94[v254];
    int v263 = v95 + ((int)((unsigned int)(v95 - v91) >> 31));
    v94[v254] = v263;
    int * v97 = v77->cache_age;
    v97[v260] = 0;
    v182 = v260;
  } else {
    int * v100 = v77->cache_age;
    int v267 = (((int)((unsigned int)((int)((unsigned int)v81 >> 2)) >> 1)) & 1) * 2;
    int v101 = v100[v267];
    int * v102 = v77->cache_tags;
    int v103 = v102[v267];
    int v104 = v100[v254];
    int v105 = v102[v254];
    bool v269 = !(((~(((v86 ^ ((int)((unsigned int)((int)((unsigned int)v81 >> 2)) >> 1))) | (-(v86 ^ ((int)((unsigned int)((int)((unsigned int)v81 >> 2)) >> 1))))) >> 31)) | (~(((v87 ^ ((int)((unsigned int)((int)((unsigned int)v81 >> 2)) >> 1))) | (-(v87 ^ ((int)((unsigned int)((int)((unsigned int)v81 >> 2)) >> 1))))) >> 31))) == 0);
    int v159;
    if (v269) {
      int * v106 = v77->cache_age;
      int v271 = (4 + ((((int)((unsigned int)((int)((unsigned int)v81 >> 2)) >> 1)) & 3) * 2)) + ((~(((v87 ^ ((int)((unsigned int)((int)((unsigned int)v81 >> 2)) >> 1))) | (-(v87 ^ ((int)((unsigned int)((int)((unsigned int)v81 >> 2)) >> 1))))) >> 31)) & 1);
      int v107 = v106[v271];
      int v108 = v106[v255];
      int v272 = v108 + ((int)((unsigned int)(v108 - v107) >> 31));
      v106[v255] = v272;
      int * v110 = v77->cache_age;
      int v111 = v110[v256];
      int v274 = v111 + ((int)((unsigned int)(v111 - v107) >> 31));
      v110[v256] = v274;
      int * v113 = v77->cache_age;
      v113[v271] = 0;
      v159 = v271;
    } else {
      int * v116 = v77->cache_age;
      int v278 = 4 + ((((int)((unsigned int)((int)((unsigned int)v81 >> 2)) >> 1)) & 3) * 2);
      int v117 = v116[v278];
      int * v118 = v77->cache_tags;
      int v119 = v118[v278];
      int v120 = v116[v256];
      int v121 = v118[v256];
      int * v122 = v77->cache_dirty;
      int v281 = (4 + ((((int)((unsigned int)((int)((unsigned int)v81 >> 2)) >> 1)) & 3) * 2)) + ((((v117 + ((~(((v119 ^ -1) | (-(v119 ^ -1))) >> 31)) & 2)) - (v120 + ((~(((v121 ^ -1) | (-(v121 ^ -1))) >> 31)) & 2))) >> 31) & 1);
      int v123 = v122[v281];
      bool v282 = !(v123 == 0);
      if (v282) {
        int * v124 = v77->cache_tags;
        int v125 = v124[v281];
        int * v126 = v77->cache_vals;
        int v285 = ((4 + ((((int)((unsigned int)((int)((unsigned int)v81 >> 2)) >> 1)) & 3) * 2)) + ((((v117 + ((~(((v119 ^ -1) | (-(v119 ^ -1))) >> 31)) & 2)) - (v120 + ((~(((v121 ^ -1) | (-(v121 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
        int v127 = v126[v285];
        int v286 = (((4 + ((((int)((unsigned int)((int)((unsigned int)v81 >> 2)) >> 1)) & 3) * 2)) + ((((v117 + ((~(((v119 ^ -1) | (-(v119 ^ -1))) >> 31)) & 2)) - (v120 + ((~(((v121 ^ -1) | (-(v121 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
        int v128 = v126[v286];
        int * v129 = v77->mem;
        int v288 = v125 * 2;
        v129[v288] = v127;
        int * v131 = v77->mem;
        int v291 = (v125 * 2) + 1;
        v131[v291] = v128;
        ;
      } else {
        ;
      }
      int * v136 = v77->mem;
      int v296 = ((int)((unsigned int)((int)((unsigned int)v81 >> 2)) >> 1)) * 2;
      int v137 = v136[v296];
      int v297 = (((int)((unsigned int)((int)((unsigned int)v81 >> 2)) >> 1)) * 2) + 1;
      int v138 = v136[v297];
      int * v139 = v77->cache_vals;
      int v299 = ((4 + ((((int)((unsigned int)((int)((unsigned int)v81 >> 2)) >> 1)) & 3) * 2)) + ((((v117 + ((~(((v119 ^ -1) | (-(v119 ^ -1))) >> 31)) & 2)) - (v120 + ((~(((v121 ^ -1) | (-(v121 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
      v139[v299] = v137;
      int * v141 = v77->cache_vals;
      int v302 = (((4 + ((((int)((unsigned int)((int)((unsigned int)v81 >> 2)) >> 1)) & 3) * 2)) + ((((v117 + ((~(((v119 ^ -1) | (-(v119 ^ -1))) >> 31)) & 2)) - (v120 + ((~(((v121 ^ -1) | (-(v121 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
      v141[v302] = v138;
      int * v143 = v77->cache_tags;
      int v305 = (int)((unsigned int)((int)((unsigned int)v81 >> 2)) >> 1);
      v143[v281] = v305;
      int * v145 = v77->cache_dirty;
      v145[v281] = 0;
      int * v147 = v77->cache_age;
      v147[v281] = 1;
      int * v149 = v77->cache_age;
      int v150 = v149[v281];
      int v151 = v149[v255];
      int v311 = v151 + ((int)((unsigned int)(v151 - v150) >> 31));
      v149[v255] = v311;
      int * v153 = v77->cache_age;
      int v154 = v153[v256];
      int v313 = v154 + ((int)((unsigned int)(v154 - v150) >> 31));
      v153[v256] = v313;
      int * v156 = v77->cache_age;
      v156[v281] = 0;
      v159 = v281;
    }
    int * v160 = v77->cache_vals;
    int v316 = v159 * 2;
    int v161 = v160[v316];
    int v317 = (v159 * 2) + 1;
    int v162 = v160[v317];
    int v318 = (((((int)((unsigned int)((int)((unsigned int)v81 >> 2)) >> 1)) & 1) * 2) + ((((v101 + ((~(((v103 ^ -1) | (-(v103 ^ -1))) >> 31)) & 2)) - (v104 + ((~(((v105 ^ -1) | (-(v105 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
    v160[v318] = v161;
    int * v164 = v77->cache_vals;
    int v321 = ((((((int)((unsigned int)((int)((unsigned int)v81 >> 2)) >> 1)) & 1) * 2) + ((((v101 + ((~(((v103 ^ -1) | (-(v103 ^ -1))) >> 31)) & 2)) - (v104 + ((~(((v105 ^ -1) | (-(v105 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
    v164[v321] = v162;
    int * v166 = v77->cache_tags;
    int v324 = ((((int)((unsigned int)((int)((unsigned int)v81 >> 2)) >> 1)) & 1) * 2) + ((((v101 + ((~(((v103 ^ -1) | (-(v103 ^ -1))) >> 31)) & 2)) - (v104 + ((~(((v105 ^ -1) | (-(v105 ^ -1))) >> 31)) & 2))) >> 31) & 1);
    int v325 = (int)((unsigned int)((int)((unsigned int)v81 >> 2)) >> 1);
    v166[v324] = v325;
    int * v168 = v77->cache_dirty;
    v168[v324] = 0;
    int * v170 = v77->cache_age;
    v170[v324] = 1;
    int * v172 = v77->cache_age;
    int v173 = v172[v324];
    int v174 = v172[v253];
    int v331 = v174 + ((int)((unsigned int)(v174 - v173) >> 31));
    v172[v253] = v331;
    int * v176 = v77->cache_age;
    int v177 = v176[v254];
    int v333 = v177 + ((int)((unsigned int)(v177 - v173) >> 31));
    v176[v254] = v333;
    int * v179 = v77->cache_age;
    v179[v324] = 0;
    v182 = v324;
  }
  int * v183 = v77->cache_vals;
  int v336 = (v182 * 2) + (((int)((unsigned int)v81 >> 2)) & 1);
  v183[v336] = v82;
  int * v185 = v77->cache_tags;
  int v186 = v185[v255];
  int v187 = v185[v256];
  bool v339 = !(((~(((v186 ^ ((int)((unsigned int)((int)((unsigned int)v81 >> 2)) >> 1))) | (-(v186 ^ ((int)((unsigned int)((int)((unsigned int)v81 >> 2)) >> 1))))) >> 31)) | (~(((v187 ^ ((int)((unsigned int)((int)((unsigned int)v81 >> 2)) >> 1))) | (-(v187 ^ ((int)((unsigned int)((int)((unsigned int)v81 >> 2)) >> 1))))) >> 31))) == 0);
  int v241;
  if (v339) {
    int * v188 = v77->cache_age;
    int v341 = (4 + ((((int)((unsigned int)((int)((unsigned int)v81 >> 2)) >> 1)) & 3) * 2)) + ((~(((v187 ^ ((int)((unsigned int)((int)((unsigned int)v81 >> 2)) >> 1))) | (-(v187 ^ ((int)((unsigned int)((int)((unsigned int)v81 >> 2)) >> 1))))) >> 31)) & 1);
    int v189 = v188[v341];
    int v190 = v188[v255];
    int v342 = v190 + ((int)((unsigned int)(v190 - v189) >> 31));
    v188[v255] = v342;
    int * v192 = v77->cache_age;
    int v193 = v192[v256];
    int v344 = v193 + ((int)((unsigned int)(v193 - v189) >> 31));
    v192[v256] = v344;
    int * v195 = v77->cache_age;
    v195[v341] = 0;
    v241 = v341;
  } else {
    int * v198 = v77->cache_age;
    int v348 = 4 + ((((int)((unsigned int)((int)((unsigned int)v81 >> 2)) >> 1)) & 3) * 2);
    int v199 = v198[v348];
    int * v200 = v77->cache_tags;
    int v201 = v200[v348];
    int v202 = v198[v256];
    int v203 = v200[v256];
    int * v204 = v77->cache_dirty;
    int v351 = (4 + ((((int)((unsigned int)((int)((unsigned int)v81 >> 2)) >> 1)) & 3) * 2)) + ((((v199 + ((~(((v201 ^ -1) | (-(v201 ^ -1))) >> 31)) & 2)) - (v202 + ((~(((v203 ^ -1) | (-(v203 ^ -1))) >> 31)) & 2))) >> 31) & 1);
    int v205 = v204[v351];
    bool v352 = !(v205 == 0);
    if (v352) {
      int * v206 = v77->cache_tags;
      int v207 = v206[v351];
      int * v208 = v77->cache_vals;
      int v355 = ((4 + ((((int)((unsigned int)((int)((unsigned int)v81 >> 2)) >> 1)) & 3) * 2)) + ((((v199 + ((~(((v201 ^ -1) | (-(v201 ^ -1))) >> 31)) & 2)) - (v202 + ((~(((v203 ^ -1) | (-(v203 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
      int v209 = v208[v355];
      int v356 = (((4 + ((((int)((unsigned int)((int)((unsigned int)v81 >> 2)) >> 1)) & 3) * 2)) + ((((v199 + ((~(((v201 ^ -1) | (-(v201 ^ -1))) >> 31)) & 2)) - (v202 + ((~(((v203 ^ -1) | (-(v203 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
      int v210 = v208[v356];
      int * v211 = v77->mem;
      int v358 = v207 * 2;
      v211[v358] = v209;
      int * v213 = v77->mem;
      int v361 = (v207 * 2) + 1;
      v213[v361] = v210;
      ;
    } else {
      ;
    }
    int * v218 = v77->mem;
    int v366 = ((int)((unsigned int)((int)((unsigned int)v81 >> 2)) >> 1)) * 2;
    int v219 = v218[v366];
    int v367 = (((int)((unsigned int)((int)((unsigned int)v81 >> 2)) >> 1)) * 2) + 1;
    int v220 = v218[v367];
    int * v221 = v77->cache_vals;
    int v369 = ((4 + ((((int)((unsigned int)((int)((unsigned int)v81 >> 2)) >> 1)) & 3) * 2)) + ((((v199 + ((~(((v201 ^ -1) | (-(v201 ^ -1))) >> 31)) & 2)) - (v202 + ((~(((v203 ^ -1) | (-(v203 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
    v221[v369] = v219;
    int * v223 = v77->cache_vals;
    int v372 = (((4 + ((((int)((unsigned int)((int)((unsigned int)v81 >> 2)) >> 1)) & 3) * 2)) + ((((v199 + ((~(((v201 ^ -1) | (-(v201 ^ -1))) >> 31)) & 2)) - (v202 + ((~(((v203 ^ -1) | (-(v203 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
    v223[v372] = v220;
    int * v225 = v77->cache_tags;
    int v375 = (int)((unsigned int)((int)((unsigned int)v81 >> 2)) >> 1);
    v225[v351] = v375;
    int * v227 = v77->cache_dirty;
    v227[v351] = 0;
    int * v229 = v77->cache_age;
    v229[v351] = 1;
    int * v231 = v77->cache_age;
    int v232 = v231[v351];
    int v233 = v231[v255];
    int v381 = v233 + ((int)((unsigned int)(v233 - v232) >> 31));
    v231[v255] = v381;
    int * v235 = v77->cache_age;
    int v236 = v235[v256];
    int v383 = v236 + ((int)((unsigned int)(v236 - v232) >> 31));
    v235[v256] = v383;
    int * v238 = v77->cache_age;
    v238[v351] = 0;
    v241 = v351;
  }
  int * v242 = v77->cache_vals;
  int v386 = (v241 * 2) + (((int)((unsigned int)v81 >> 2)) & 1);
  v242[v386] = v82;
  int * v244 = v77->cache_dirty;
  v244[v241] = 1;
  struct StateT * v246 = slot_6(v77);
  return v246;
}

struct StateT * slot_4(struct StateT * v64) {
  int v65 = v64->timer;
  int v71 = v65 + 1;
  v64->timer = v71;
  int * v67 = v64->regs;
  v67[7] = 0;
  struct StateT * v69 = slot_5(v64);
  return v69;
}

struct StateT * slot_2(struct StateT * v30) {
  int v31 = v30->timer;
  int v41 = v31 + 1;
  v30->timer = v41;
  int * v33 = v30->regs;
  int v34 = v33[5];
  int v35 = v33[9];
  bool v45 = v34 >= v35;
  struct StateT * v39;
  if (v45) {
    v39 = v30;
  } else {
    struct StateT * v37 = slot_3(v30);
    v39 = v37;
  }
  return v39;
}

struct StateT * slot_7(struct StateT * v596) {
  int v597 = v596->timer;
  int v604 = v597 + 1;
  v596->timer = v604;
  int * v599 = v596->regs;
  int v600 = v599[11];
  int v607 = v600 << 2;
  v599[11] = v607;
  struct StateT * v602 = slot_8(v596);
  return v602;
}

struct StateT * slot_3(struct StateT * v49) {
  int v50 = v49->timer;
  int v57 = v50 + 1;
  v49->timer = v57;
  int * v52 = v49->regs;
  int v53 = v52[5];
  int v61 = v53 + 80;
  v52[6] = v61;
  struct StateT * v55 = slot_4(v49);
  return v55;
}

struct StateT * slot_0(struct StateT * v2) {
  int v3 = v2->timer;
  int v10 = v3 + 1;
  v2->timer = v10;
  int * v5 = v2->regs;
  int v6 = v5[10];
  int v14 = v6 & 28;
  v5[5] = v14;
  struct StateT * v8 = slot_1(v2);
  return v8;
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