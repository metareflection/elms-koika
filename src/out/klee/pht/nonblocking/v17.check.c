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

struct StateT * slot_12(struct StateT * v619);
struct StateT * slot_14(struct StateT * v664);
struct StateT * slot_6(struct StateT * v307);
struct StateT * slot_16(struct StateT * v1079);
struct StateT * slot_5(struct StateT * v100);
struct StateT * slot_17(struct StateT * v1103);
struct StateT * slot_2(struct StateT * v39);
struct StateT * slot_7(struct StateT * v514);
struct StateT * slot_3(struct StateT * v60);
struct StateT * snippet(struct StateT * v0);
struct StateT * slot_10(struct StateT * v582);
struct StateT * slot_1(struct StateT * v23);
struct StateT * slot_8(struct StateT * v545);
struct StateT * slot_4(struct StateT * v84);
struct StateT * slot_13(struct StateT * v640);
struct StateT * slot_15(struct StateT * v871);
struct StateT * slot_18(struct StateT * v540);
struct StateT * slot_9(struct StateT * v566);
struct StateT * slot_11(struct StateT * v603);
struct StateT * slot_0(struct StateT * v2);
struct StateT * slot_12(struct StateT * v619) {
  int v620 = v619->timer;
  int v631 = v620 + 1;
  v619->timer = v631;
  int * v622 = v619->reg_ready;
  int v623 = v622[10];
  int * v624 = v619->regs;
  int v625 = v624[10];
  int v635 = (v623 + ((v620 - v623) & (~((v620 - v623) >> 31)))) + 1;
  v622[10] = v635;
  int * v627 = v619->regs;
  int v637 = (int)((unsigned int)v625 >> 26);
  v627[10] = v637;
  struct StateT * v629 = slot_13(v619);
  return v629;
}

struct StateT * slot_14(struct StateT * v664) {
  int v665 = v664->timer;
  int v777 = v665 + 1;
  v664->timer = v777;
  int * v667 = v664->reg_ready;
  int v668 = v667[10];
  int * v669 = v664->regs;
  int v670 = v669[10];
  int * v671 = v664->cache_tags;
  int v782 = (((int)((unsigned int)((int)((unsigned int)v670 >> 2)) >> 1)) & 1) * 2;
  int v672 = v671[v782];
  int v783 = ((((int)((unsigned int)((int)((unsigned int)v670 >> 2)) >> 1)) & 1) * 2) + 1;
  int v673 = v671[v783];
  int v784 = 4 + ((((int)((unsigned int)((int)((unsigned int)v670 >> 2)) >> 1)) & 3) * 2);
  int v674 = v671[v784];
  int v785 = (4 + ((((int)((unsigned int)((int)((unsigned int)v670 >> 2)) >> 1)) & 3) * 2)) + 1;
  int v675 = v671[v785];
  int * v676 = v664->cache_vals;
  bool v786 = !(((~(((v672 ^ ((int)((unsigned int)((int)((unsigned int)v670 >> 2)) >> 1))) | (-(v672 ^ ((int)((unsigned int)((int)((unsigned int)v670 >> 2)) >> 1))))) >> 31)) | (~(((v673 ^ ((int)((unsigned int)((int)((unsigned int)v670 >> 2)) >> 1))) | (-(v673 ^ ((int)((unsigned int)((int)((unsigned int)v670 >> 2)) >> 1))))) >> 31))) == 0);
  int v769;
  if (v786) {
    int * v677 = v664->cache_age;
    int v788 = ((((int)((unsigned int)((int)((unsigned int)v670 >> 2)) >> 1)) & 1) * 2) + ((~(((v673 ^ ((int)((unsigned int)((int)((unsigned int)v670 >> 2)) >> 1))) | (-(v673 ^ ((int)((unsigned int)((int)((unsigned int)v670 >> 2)) >> 1))))) >> 31)) & 1);
    int v678 = v677[v788];
    int v679 = v677[v782];
    int v789 = v679 + ((int)((unsigned int)(v679 - v678) >> 31));
    v677[v782] = v789;
    int * v681 = v664->cache_age;
    int v682 = v681[v783];
    int v791 = v682 + ((int)((unsigned int)(v682 - v678) >> 31));
    v681[v783] = v791;
    int * v684 = v664->cache_age;
    v684[v788] = 0;
    v769 = v788;
  } else {
    int * v687 = v664->cache_age;
    int v795 = (((int)((unsigned int)((int)((unsigned int)v670 >> 2)) >> 1)) & 1) * 2;
    int v688 = v687[v795];
    int * v689 = v664->cache_tags;
    int v690 = v689[v795];
    int v691 = v687[v783];
    int v692 = v689[v783];
    bool v797 = !(((~(((v674 ^ ((int)((unsigned int)((int)((unsigned int)v670 >> 2)) >> 1))) | (-(v674 ^ ((int)((unsigned int)((int)((unsigned int)v670 >> 2)) >> 1))))) >> 31)) | (~(((v675 ^ ((int)((unsigned int)((int)((unsigned int)v670 >> 2)) >> 1))) | (-(v675 ^ ((int)((unsigned int)((int)((unsigned int)v670 >> 2)) >> 1))))) >> 31))) == 0);
    int v746;
    if (v797) {
      int * v693 = v664->cache_age;
      int v799 = (4 + ((((int)((unsigned int)((int)((unsigned int)v670 >> 2)) >> 1)) & 3) * 2)) + ((~(((v675 ^ ((int)((unsigned int)((int)((unsigned int)v670 >> 2)) >> 1))) | (-(v675 ^ ((int)((unsigned int)((int)((unsigned int)v670 >> 2)) >> 1))))) >> 31)) & 1);
      int v694 = v693[v799];
      int v695 = v693[v784];
      int v800 = v695 + ((int)((unsigned int)(v695 - v694) >> 31));
      v693[v784] = v800;
      int * v697 = v664->cache_age;
      int v698 = v697[v785];
      int v802 = v698 + ((int)((unsigned int)(v698 - v694) >> 31));
      v697[v785] = v802;
      int * v700 = v664->cache_age;
      v700[v799] = 0;
      v746 = v799;
    } else {
      int * v703 = v664->cache_age;
      int v806 = 4 + ((((int)((unsigned int)((int)((unsigned int)v670 >> 2)) >> 1)) & 3) * 2);
      int v704 = v703[v806];
      int * v705 = v664->cache_tags;
      int v706 = v705[v806];
      int v707 = v703[v785];
      int v708 = v705[v785];
      int * v709 = v664->cache_dirty;
      int v809 = (4 + ((((int)((unsigned int)((int)((unsigned int)v670 >> 2)) >> 1)) & 3) * 2)) + ((((v704 + ((~(((v706 ^ -1) | (-(v706 ^ -1))) >> 31)) & 2)) - (v707 + ((~(((v708 ^ -1) | (-(v708 ^ -1))) >> 31)) & 2))) >> 31) & 1);
      int v710 = v709[v809];
      bool v810 = !(v710 == 0);
      if (v810) {
        int * v711 = v664->cache_tags;
        int v712 = v711[v809];
        int * v713 = v664->cache_vals;
        int v813 = ((4 + ((((int)((unsigned int)((int)((unsigned int)v670 >> 2)) >> 1)) & 3) * 2)) + ((((v704 + ((~(((v706 ^ -1) | (-(v706 ^ -1))) >> 31)) & 2)) - (v707 + ((~(((v708 ^ -1) | (-(v708 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
        int v714 = v713[v813];
        int v814 = (((4 + ((((int)((unsigned int)((int)((unsigned int)v670 >> 2)) >> 1)) & 3) * 2)) + ((((v704 + ((~(((v706 ^ -1) | (-(v706 ^ -1))) >> 31)) & 2)) - (v707 + ((~(((v708 ^ -1) | (-(v708 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
        int v715 = v713[v814];
        int * v716 = v664->mem;
        int v816 = v712 * 2;
        v716[v816] = v714;
        int * v718 = v664->mem;
        int v819 = (v712 * 2) + 1;
        v718[v819] = v715;
        ;
      } else {
        ;
      }
      int * v723 = v664->mem;
      int v824 = ((int)((unsigned int)((int)((unsigned int)v670 >> 2)) >> 1)) * 2;
      int v724 = v723[v824];
      int v825 = (((int)((unsigned int)((int)((unsigned int)v670 >> 2)) >> 1)) * 2) + 1;
      int v725 = v723[v825];
      int * v726 = v664->cache_vals;
      int v827 = ((4 + ((((int)((unsigned int)((int)((unsigned int)v670 >> 2)) >> 1)) & 3) * 2)) + ((((v704 + ((~(((v706 ^ -1) | (-(v706 ^ -1))) >> 31)) & 2)) - (v707 + ((~(((v708 ^ -1) | (-(v708 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
      v726[v827] = v724;
      int * v728 = v664->cache_vals;
      int v830 = (((4 + ((((int)((unsigned int)((int)((unsigned int)v670 >> 2)) >> 1)) & 3) * 2)) + ((((v704 + ((~(((v706 ^ -1) | (-(v706 ^ -1))) >> 31)) & 2)) - (v707 + ((~(((v708 ^ -1) | (-(v708 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
      v728[v830] = v725;
      int * v730 = v664->cache_tags;
      int v833 = (int)((unsigned int)((int)((unsigned int)v670 >> 2)) >> 1);
      v730[v809] = v833;
      int * v732 = v664->cache_dirty;
      v732[v809] = 0;
      int * v734 = v664->cache_age;
      v734[v809] = 1;
      int * v736 = v664->cache_age;
      int v737 = v736[v809];
      int v738 = v736[v784];
      int v839 = v738 + ((int)((unsigned int)(v738 - v737) >> 31));
      v736[v784] = v839;
      int * v740 = v664->cache_age;
      int v741 = v740[v785];
      int v841 = v741 + ((int)((unsigned int)(v741 - v737) >> 31));
      v740[v785] = v841;
      int * v743 = v664->cache_age;
      v743[v809] = 0;
      v746 = v809;
    }
    int * v747 = v664->cache_vals;
    int v844 = v746 * 2;
    int v748 = v747[v844];
    int v845 = (v746 * 2) + 1;
    int v749 = v747[v845];
    int v846 = (((((int)((unsigned int)((int)((unsigned int)v670 >> 2)) >> 1)) & 1) * 2) + ((((v688 + ((~(((v690 ^ -1) | (-(v690 ^ -1))) >> 31)) & 2)) - (v691 + ((~(((v692 ^ -1) | (-(v692 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
    v747[v846] = v748;
    int * v751 = v664->cache_vals;
    int v849 = ((((((int)((unsigned int)((int)((unsigned int)v670 >> 2)) >> 1)) & 1) * 2) + ((((v688 + ((~(((v690 ^ -1) | (-(v690 ^ -1))) >> 31)) & 2)) - (v691 + ((~(((v692 ^ -1) | (-(v692 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
    v751[v849] = v749;
    int * v753 = v664->cache_tags;
    int v852 = ((((int)((unsigned int)((int)((unsigned int)v670 >> 2)) >> 1)) & 1) * 2) + ((((v688 + ((~(((v690 ^ -1) | (-(v690 ^ -1))) >> 31)) & 2)) - (v691 + ((~(((v692 ^ -1) | (-(v692 ^ -1))) >> 31)) & 2))) >> 31) & 1);
    int v853 = (int)((unsigned int)((int)((unsigned int)v670 >> 2)) >> 1);
    v753[v852] = v853;
    int * v755 = v664->cache_dirty;
    v755[v852] = 0;
    int * v757 = v664->cache_age;
    v757[v852] = 1;
    int * v759 = v664->cache_age;
    int v760 = v759[v852];
    int v761 = v759[v782];
    int v859 = v761 + ((int)((unsigned int)(v761 - v760) >> 31));
    v759[v782] = v859;
    int * v763 = v664->cache_age;
    int v764 = v763[v783];
    int v861 = v764 + ((int)((unsigned int)(v764 - v760) >> 31));
    v763[v783] = v861;
    int * v766 = v664->cache_age;
    v766[v852] = 0;
    v769 = v852;
  }
  int v864 = (v769 * 2) + (((int)((unsigned int)v670 >> 2)) & 1);
  int v770 = v676[v864];
  int * v771 = v664->reg_ready;
  int v866 = ((v668 + ((v665 - v668) & (~((v665 - v668) >> 31)))) + 1) + ((100 ^ (((~(((v674 ^ ((int)((unsigned int)((int)((unsigned int)v670 >> 2)) >> 1))) | (-(v674 ^ ((int)((unsigned int)((int)((unsigned int)v670 >> 2)) >> 1))))) >> 31)) | (~(((v675 ^ ((int)((unsigned int)((int)((unsigned int)v670 >> 2)) >> 1))) | (-(v675 ^ ((int)((unsigned int)((int)((unsigned int)v670 >> 2)) >> 1))))) >> 31))) & 104)) ^ (((~(((v672 ^ ((int)((unsigned int)((int)((unsigned int)v670 >> 2)) >> 1))) | (-(v672 ^ ((int)((unsigned int)((int)((unsigned int)v670 >> 2)) >> 1))))) >> 31)) | (~(((v673 ^ ((int)((unsigned int)((int)((unsigned int)v670 >> 2)) >> 1))) | (-(v673 ^ ((int)((unsigned int)((int)((unsigned int)v670 >> 2)) >> 1))))) >> 31))) & (1 ^ (100 ^ (((~(((v674 ^ ((int)((unsigned int)((int)((unsigned int)v670 >> 2)) >> 1))) | (-(v674 ^ ((int)((unsigned int)((int)((unsigned int)v670 >> 2)) >> 1))))) >> 31)) | (~(((v675 ^ ((int)((unsigned int)((int)((unsigned int)v670 >> 2)) >> 1))) | (-(v675 ^ ((int)((unsigned int)((int)((unsigned int)v670 >> 2)) >> 1))))) >> 31))) & 104)))));
  v771[10] = v866;
  int * v773 = v664->regs;
  v773[10] = v770;
  struct StateT * v775 = slot_15(v664);
  return v775;
}

struct StateT * slot_6(struct StateT * v307) {
  int v308 = v307->timer;
  int v420 = v308 + 1;
  v307->timer = v420;
  int * v310 = v307->reg_ready;
  int v311 = v310[11];
  int * v312 = v307->regs;
  int v313 = v312[11];
  int * v314 = v307->cache_tags;
  int v425 = (((int)((unsigned int)((int)((unsigned int)v313 >> 2)) >> 1)) & 1) * 2;
  int v315 = v314[v425];
  int v426 = ((((int)((unsigned int)((int)((unsigned int)v313 >> 2)) >> 1)) & 1) * 2) + 1;
  int v316 = v314[v426];
  int v427 = 4 + ((((int)((unsigned int)((int)((unsigned int)v313 >> 2)) >> 1)) & 3) * 2);
  int v317 = v314[v427];
  int v428 = (4 + ((((int)((unsigned int)((int)((unsigned int)v313 >> 2)) >> 1)) & 3) * 2)) + 1;
  int v318 = v314[v428];
  int * v319 = v307->cache_vals;
  bool v429 = !(((~(((v315 ^ ((int)((unsigned int)((int)((unsigned int)v313 >> 2)) >> 1))) | (-(v315 ^ ((int)((unsigned int)((int)((unsigned int)v313 >> 2)) >> 1))))) >> 31)) | (~(((v316 ^ ((int)((unsigned int)((int)((unsigned int)v313 >> 2)) >> 1))) | (-(v316 ^ ((int)((unsigned int)((int)((unsigned int)v313 >> 2)) >> 1))))) >> 31))) == 0);
  int v412;
  if (v429) {
    int * v320 = v307->cache_age;
    int v431 = ((((int)((unsigned int)((int)((unsigned int)v313 >> 2)) >> 1)) & 1) * 2) + ((~(((v316 ^ ((int)((unsigned int)((int)((unsigned int)v313 >> 2)) >> 1))) | (-(v316 ^ ((int)((unsigned int)((int)((unsigned int)v313 >> 2)) >> 1))))) >> 31)) & 1);
    int v321 = v320[v431];
    int v322 = v320[v425];
    int v432 = v322 + ((int)((unsigned int)(v322 - v321) >> 31));
    v320[v425] = v432;
    int * v324 = v307->cache_age;
    int v325 = v324[v426];
    int v434 = v325 + ((int)((unsigned int)(v325 - v321) >> 31));
    v324[v426] = v434;
    int * v327 = v307->cache_age;
    v327[v431] = 0;
    v412 = v431;
  } else {
    int * v330 = v307->cache_age;
    int v438 = (((int)((unsigned int)((int)((unsigned int)v313 >> 2)) >> 1)) & 1) * 2;
    int v331 = v330[v438];
    int * v332 = v307->cache_tags;
    int v333 = v332[v438];
    int v334 = v330[v426];
    int v335 = v332[v426];
    bool v440 = !(((~(((v317 ^ ((int)((unsigned int)((int)((unsigned int)v313 >> 2)) >> 1))) | (-(v317 ^ ((int)((unsigned int)((int)((unsigned int)v313 >> 2)) >> 1))))) >> 31)) | (~(((v318 ^ ((int)((unsigned int)((int)((unsigned int)v313 >> 2)) >> 1))) | (-(v318 ^ ((int)((unsigned int)((int)((unsigned int)v313 >> 2)) >> 1))))) >> 31))) == 0);
    int v389;
    if (v440) {
      int * v336 = v307->cache_age;
      int v442 = (4 + ((((int)((unsigned int)((int)((unsigned int)v313 >> 2)) >> 1)) & 3) * 2)) + ((~(((v318 ^ ((int)((unsigned int)((int)((unsigned int)v313 >> 2)) >> 1))) | (-(v318 ^ ((int)((unsigned int)((int)((unsigned int)v313 >> 2)) >> 1))))) >> 31)) & 1);
      int v337 = v336[v442];
      int v338 = v336[v427];
      int v443 = v338 + ((int)((unsigned int)(v338 - v337) >> 31));
      v336[v427] = v443;
      int * v340 = v307->cache_age;
      int v341 = v340[v428];
      int v445 = v341 + ((int)((unsigned int)(v341 - v337) >> 31));
      v340[v428] = v445;
      int * v343 = v307->cache_age;
      v343[v442] = 0;
      v389 = v442;
    } else {
      int * v346 = v307->cache_age;
      int v449 = 4 + ((((int)((unsigned int)((int)((unsigned int)v313 >> 2)) >> 1)) & 3) * 2);
      int v347 = v346[v449];
      int * v348 = v307->cache_tags;
      int v349 = v348[v449];
      int v350 = v346[v428];
      int v351 = v348[v428];
      int * v352 = v307->cache_dirty;
      int v452 = (4 + ((((int)((unsigned int)((int)((unsigned int)v313 >> 2)) >> 1)) & 3) * 2)) + ((((v347 + ((~(((v349 ^ -1) | (-(v349 ^ -1))) >> 31)) & 2)) - (v350 + ((~(((v351 ^ -1) | (-(v351 ^ -1))) >> 31)) & 2))) >> 31) & 1);
      int v353 = v352[v452];
      bool v453 = !(v353 == 0);
      if (v453) {
        int * v354 = v307->cache_tags;
        int v355 = v354[v452];
        int * v356 = v307->cache_vals;
        int v456 = ((4 + ((((int)((unsigned int)((int)((unsigned int)v313 >> 2)) >> 1)) & 3) * 2)) + ((((v347 + ((~(((v349 ^ -1) | (-(v349 ^ -1))) >> 31)) & 2)) - (v350 + ((~(((v351 ^ -1) | (-(v351 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
        int v357 = v356[v456];
        int v457 = (((4 + ((((int)((unsigned int)((int)((unsigned int)v313 >> 2)) >> 1)) & 3) * 2)) + ((((v347 + ((~(((v349 ^ -1) | (-(v349 ^ -1))) >> 31)) & 2)) - (v350 + ((~(((v351 ^ -1) | (-(v351 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
        int v358 = v356[v457];
        int * v359 = v307->mem;
        int v459 = v355 * 2;
        v359[v459] = v357;
        int * v361 = v307->mem;
        int v462 = (v355 * 2) + 1;
        v361[v462] = v358;
        ;
      } else {
        ;
      }
      int * v366 = v307->mem;
      int v467 = ((int)((unsigned int)((int)((unsigned int)v313 >> 2)) >> 1)) * 2;
      int v367 = v366[v467];
      int v468 = (((int)((unsigned int)((int)((unsigned int)v313 >> 2)) >> 1)) * 2) + 1;
      int v368 = v366[v468];
      int * v369 = v307->cache_vals;
      int v470 = ((4 + ((((int)((unsigned int)((int)((unsigned int)v313 >> 2)) >> 1)) & 3) * 2)) + ((((v347 + ((~(((v349 ^ -1) | (-(v349 ^ -1))) >> 31)) & 2)) - (v350 + ((~(((v351 ^ -1) | (-(v351 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
      v369[v470] = v367;
      int * v371 = v307->cache_vals;
      int v473 = (((4 + ((((int)((unsigned int)((int)((unsigned int)v313 >> 2)) >> 1)) & 3) * 2)) + ((((v347 + ((~(((v349 ^ -1) | (-(v349 ^ -1))) >> 31)) & 2)) - (v350 + ((~(((v351 ^ -1) | (-(v351 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
      v371[v473] = v368;
      int * v373 = v307->cache_tags;
      int v476 = (int)((unsigned int)((int)((unsigned int)v313 >> 2)) >> 1);
      v373[v452] = v476;
      int * v375 = v307->cache_dirty;
      v375[v452] = 0;
      int * v377 = v307->cache_age;
      v377[v452] = 1;
      int * v379 = v307->cache_age;
      int v380 = v379[v452];
      int v381 = v379[v427];
      int v482 = v381 + ((int)((unsigned int)(v381 - v380) >> 31));
      v379[v427] = v482;
      int * v383 = v307->cache_age;
      int v384 = v383[v428];
      int v484 = v384 + ((int)((unsigned int)(v384 - v380) >> 31));
      v383[v428] = v484;
      int * v386 = v307->cache_age;
      v386[v452] = 0;
      v389 = v452;
    }
    int * v390 = v307->cache_vals;
    int v487 = v389 * 2;
    int v391 = v390[v487];
    int v488 = (v389 * 2) + 1;
    int v392 = v390[v488];
    int v489 = (((((int)((unsigned int)((int)((unsigned int)v313 >> 2)) >> 1)) & 1) * 2) + ((((v331 + ((~(((v333 ^ -1) | (-(v333 ^ -1))) >> 31)) & 2)) - (v334 + ((~(((v335 ^ -1) | (-(v335 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
    v390[v489] = v391;
    int * v394 = v307->cache_vals;
    int v492 = ((((((int)((unsigned int)((int)((unsigned int)v313 >> 2)) >> 1)) & 1) * 2) + ((((v331 + ((~(((v333 ^ -1) | (-(v333 ^ -1))) >> 31)) & 2)) - (v334 + ((~(((v335 ^ -1) | (-(v335 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
    v394[v492] = v392;
    int * v396 = v307->cache_tags;
    int v495 = ((((int)((unsigned int)((int)((unsigned int)v313 >> 2)) >> 1)) & 1) * 2) + ((((v331 + ((~(((v333 ^ -1) | (-(v333 ^ -1))) >> 31)) & 2)) - (v334 + ((~(((v335 ^ -1) | (-(v335 ^ -1))) >> 31)) & 2))) >> 31) & 1);
    int v496 = (int)((unsigned int)((int)((unsigned int)v313 >> 2)) >> 1);
    v396[v495] = v496;
    int * v398 = v307->cache_dirty;
    v398[v495] = 0;
    int * v400 = v307->cache_age;
    v400[v495] = 1;
    int * v402 = v307->cache_age;
    int v403 = v402[v495];
    int v404 = v402[v425];
    int v502 = v404 + ((int)((unsigned int)(v404 - v403) >> 31));
    v402[v425] = v502;
    int * v406 = v307->cache_age;
    int v407 = v406[v426];
    int v504 = v407 + ((int)((unsigned int)(v407 - v403) >> 31));
    v406[v426] = v504;
    int * v409 = v307->cache_age;
    v409[v495] = 0;
    v412 = v495;
  }
  int v507 = (v412 * 2) + (((int)((unsigned int)v313 >> 2)) & 1);
  int v413 = v319[v507];
  int * v414 = v307->reg_ready;
  int v509 = ((v311 + ((v308 - v311) & (~((v308 - v311) >> 31)))) + 1) + ((100 ^ (((~(((v317 ^ ((int)((unsigned int)((int)((unsigned int)v313 >> 2)) >> 1))) | (-(v317 ^ ((int)((unsigned int)((int)((unsigned int)v313 >> 2)) >> 1))))) >> 31)) | (~(((v318 ^ ((int)((unsigned int)((int)((unsigned int)v313 >> 2)) >> 1))) | (-(v318 ^ ((int)((unsigned int)((int)((unsigned int)v313 >> 2)) >> 1))))) >> 31))) & 104)) ^ (((~(((v315 ^ ((int)((unsigned int)((int)((unsigned int)v313 >> 2)) >> 1))) | (-(v315 ^ ((int)((unsigned int)((int)((unsigned int)v313 >> 2)) >> 1))))) >> 31)) | (~(((v316 ^ ((int)((unsigned int)((int)((unsigned int)v313 >> 2)) >> 1))) | (-(v316 ^ ((int)((unsigned int)((int)((unsigned int)v313 >> 2)) >> 1))))) >> 31))) & (1 ^ (100 ^ (((~(((v317 ^ ((int)((unsigned int)((int)((unsigned int)v313 >> 2)) >> 1))) | (-(v317 ^ ((int)((unsigned int)((int)((unsigned int)v313 >> 2)) >> 1))))) >> 31)) | (~(((v318 ^ ((int)((unsigned int)((int)((unsigned int)v313 >> 2)) >> 1))) | (-(v318 ^ ((int)((unsigned int)((int)((unsigned int)v313 >> 2)) >> 1))))) >> 31))) & 104)))));
  v414[11] = v509;
  int * v416 = v307->regs;
  v416[11] = v413;
  struct StateT * v418 = slot_7(v307);
  return v418;
}

struct StateT * slot_16(struct StateT * v1079) {
  int v1080 = v1079->timer;
  int v1093 = v1080 + 1;
  v1079->timer = v1093;
  int * v1082 = v1079->reg_ready;
  int v1083 = v1082[11];
  int * v1084 = v1079->regs;
  int v1085 = v1084[11];
  int v1086 = v1082[10];
  int v1087 = v1084[10];
  int v1098 = (v1086 + (((v1083 + ((v1080 - v1083) & (~((v1080 - v1083) >> 31)))) - v1086) & (~(((v1083 + ((v1080 - v1083) & (~((v1080 - v1083) >> 31)))) - v1086) >> 31)))) + 1;
  v1082[10] = v1098;
  int * v1089 = v1079->regs;
  int v1100 = v1085 & v1087;
  v1089[10] = v1100;
  struct StateT * v1091 = slot_17(v1079);
  return v1091;
}

struct StateT * slot_5(struct StateT * v100) {
  int v101 = v100->timer;
  int v213 = v101 + 1;
  v100->timer = v213;
  int * v103 = v100->reg_ready;
  int v104 = v103[10];
  int * v105 = v100->regs;
  int v106 = v105[10];
  int * v107 = v100->cache_tags;
  int v218 = (((int)((unsigned int)((int)((unsigned int)v106 >> 2)) >> 1)) & 1) * 2;
  int v108 = v107[v218];
  int v219 = ((((int)((unsigned int)((int)((unsigned int)v106 >> 2)) >> 1)) & 1) * 2) + 1;
  int v109 = v107[v219];
  int v220 = 4 + ((((int)((unsigned int)((int)((unsigned int)v106 >> 2)) >> 1)) & 3) * 2);
  int v110 = v107[v220];
  int v221 = (4 + ((((int)((unsigned int)((int)((unsigned int)v106 >> 2)) >> 1)) & 3) * 2)) + 1;
  int v111 = v107[v221];
  int * v112 = v100->cache_vals;
  bool v222 = !(((~(((v108 ^ ((int)((unsigned int)((int)((unsigned int)v106 >> 2)) >> 1))) | (-(v108 ^ ((int)((unsigned int)((int)((unsigned int)v106 >> 2)) >> 1))))) >> 31)) | (~(((v109 ^ ((int)((unsigned int)((int)((unsigned int)v106 >> 2)) >> 1))) | (-(v109 ^ ((int)((unsigned int)((int)((unsigned int)v106 >> 2)) >> 1))))) >> 31))) == 0);
  int v205;
  if (v222) {
    int * v113 = v100->cache_age;
    int v224 = ((((int)((unsigned int)((int)((unsigned int)v106 >> 2)) >> 1)) & 1) * 2) + ((~(((v109 ^ ((int)((unsigned int)((int)((unsigned int)v106 >> 2)) >> 1))) | (-(v109 ^ ((int)((unsigned int)((int)((unsigned int)v106 >> 2)) >> 1))))) >> 31)) & 1);
    int v114 = v113[v224];
    int v115 = v113[v218];
    int v225 = v115 + ((int)((unsigned int)(v115 - v114) >> 31));
    v113[v218] = v225;
    int * v117 = v100->cache_age;
    int v118 = v117[v219];
    int v227 = v118 + ((int)((unsigned int)(v118 - v114) >> 31));
    v117[v219] = v227;
    int * v120 = v100->cache_age;
    v120[v224] = 0;
    v205 = v224;
  } else {
    int * v123 = v100->cache_age;
    int v231 = (((int)((unsigned int)((int)((unsigned int)v106 >> 2)) >> 1)) & 1) * 2;
    int v124 = v123[v231];
    int * v125 = v100->cache_tags;
    int v126 = v125[v231];
    int v127 = v123[v219];
    int v128 = v125[v219];
    bool v233 = !(((~(((v110 ^ ((int)((unsigned int)((int)((unsigned int)v106 >> 2)) >> 1))) | (-(v110 ^ ((int)((unsigned int)((int)((unsigned int)v106 >> 2)) >> 1))))) >> 31)) | (~(((v111 ^ ((int)((unsigned int)((int)((unsigned int)v106 >> 2)) >> 1))) | (-(v111 ^ ((int)((unsigned int)((int)((unsigned int)v106 >> 2)) >> 1))))) >> 31))) == 0);
    int v182;
    if (v233) {
      int * v129 = v100->cache_age;
      int v235 = (4 + ((((int)((unsigned int)((int)((unsigned int)v106 >> 2)) >> 1)) & 3) * 2)) + ((~(((v111 ^ ((int)((unsigned int)((int)((unsigned int)v106 >> 2)) >> 1))) | (-(v111 ^ ((int)((unsigned int)((int)((unsigned int)v106 >> 2)) >> 1))))) >> 31)) & 1);
      int v130 = v129[v235];
      int v131 = v129[v220];
      int v236 = v131 + ((int)((unsigned int)(v131 - v130) >> 31));
      v129[v220] = v236;
      int * v133 = v100->cache_age;
      int v134 = v133[v221];
      int v238 = v134 + ((int)((unsigned int)(v134 - v130) >> 31));
      v133[v221] = v238;
      int * v136 = v100->cache_age;
      v136[v235] = 0;
      v182 = v235;
    } else {
      int * v139 = v100->cache_age;
      int v242 = 4 + ((((int)((unsigned int)((int)((unsigned int)v106 >> 2)) >> 1)) & 3) * 2);
      int v140 = v139[v242];
      int * v141 = v100->cache_tags;
      int v142 = v141[v242];
      int v143 = v139[v221];
      int v144 = v141[v221];
      int * v145 = v100->cache_dirty;
      int v245 = (4 + ((((int)((unsigned int)((int)((unsigned int)v106 >> 2)) >> 1)) & 3) * 2)) + ((((v140 + ((~(((v142 ^ -1) | (-(v142 ^ -1))) >> 31)) & 2)) - (v143 + ((~(((v144 ^ -1) | (-(v144 ^ -1))) >> 31)) & 2))) >> 31) & 1);
      int v146 = v145[v245];
      bool v246 = !(v146 == 0);
      if (v246) {
        int * v147 = v100->cache_tags;
        int v148 = v147[v245];
        int * v149 = v100->cache_vals;
        int v249 = ((4 + ((((int)((unsigned int)((int)((unsigned int)v106 >> 2)) >> 1)) & 3) * 2)) + ((((v140 + ((~(((v142 ^ -1) | (-(v142 ^ -1))) >> 31)) & 2)) - (v143 + ((~(((v144 ^ -1) | (-(v144 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
        int v150 = v149[v249];
        int v250 = (((4 + ((((int)((unsigned int)((int)((unsigned int)v106 >> 2)) >> 1)) & 3) * 2)) + ((((v140 + ((~(((v142 ^ -1) | (-(v142 ^ -1))) >> 31)) & 2)) - (v143 + ((~(((v144 ^ -1) | (-(v144 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
        int v151 = v149[v250];
        int * v152 = v100->mem;
        int v252 = v148 * 2;
        v152[v252] = v150;
        int * v154 = v100->mem;
        int v255 = (v148 * 2) + 1;
        v154[v255] = v151;
        ;
      } else {
        ;
      }
      int * v159 = v100->mem;
      int v260 = ((int)((unsigned int)((int)((unsigned int)v106 >> 2)) >> 1)) * 2;
      int v160 = v159[v260];
      int v261 = (((int)((unsigned int)((int)((unsigned int)v106 >> 2)) >> 1)) * 2) + 1;
      int v161 = v159[v261];
      int * v162 = v100->cache_vals;
      int v263 = ((4 + ((((int)((unsigned int)((int)((unsigned int)v106 >> 2)) >> 1)) & 3) * 2)) + ((((v140 + ((~(((v142 ^ -1) | (-(v142 ^ -1))) >> 31)) & 2)) - (v143 + ((~(((v144 ^ -1) | (-(v144 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
      v162[v263] = v160;
      int * v164 = v100->cache_vals;
      int v266 = (((4 + ((((int)((unsigned int)((int)((unsigned int)v106 >> 2)) >> 1)) & 3) * 2)) + ((((v140 + ((~(((v142 ^ -1) | (-(v142 ^ -1))) >> 31)) & 2)) - (v143 + ((~(((v144 ^ -1) | (-(v144 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
      v164[v266] = v161;
      int * v166 = v100->cache_tags;
      int v269 = (int)((unsigned int)((int)((unsigned int)v106 >> 2)) >> 1);
      v166[v245] = v269;
      int * v168 = v100->cache_dirty;
      v168[v245] = 0;
      int * v170 = v100->cache_age;
      v170[v245] = 1;
      int * v172 = v100->cache_age;
      int v173 = v172[v245];
      int v174 = v172[v220];
      int v275 = v174 + ((int)((unsigned int)(v174 - v173) >> 31));
      v172[v220] = v275;
      int * v176 = v100->cache_age;
      int v177 = v176[v221];
      int v277 = v177 + ((int)((unsigned int)(v177 - v173) >> 31));
      v176[v221] = v277;
      int * v179 = v100->cache_age;
      v179[v245] = 0;
      v182 = v245;
    }
    int * v183 = v100->cache_vals;
    int v280 = v182 * 2;
    int v184 = v183[v280];
    int v281 = (v182 * 2) + 1;
    int v185 = v183[v281];
    int v282 = (((((int)((unsigned int)((int)((unsigned int)v106 >> 2)) >> 1)) & 1) * 2) + ((((v124 + ((~(((v126 ^ -1) | (-(v126 ^ -1))) >> 31)) & 2)) - (v127 + ((~(((v128 ^ -1) | (-(v128 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
    v183[v282] = v184;
    int * v187 = v100->cache_vals;
    int v285 = ((((((int)((unsigned int)((int)((unsigned int)v106 >> 2)) >> 1)) & 1) * 2) + ((((v124 + ((~(((v126 ^ -1) | (-(v126 ^ -1))) >> 31)) & 2)) - (v127 + ((~(((v128 ^ -1) | (-(v128 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
    v187[v285] = v185;
    int * v189 = v100->cache_tags;
    int v288 = ((((int)((unsigned int)((int)((unsigned int)v106 >> 2)) >> 1)) & 1) * 2) + ((((v124 + ((~(((v126 ^ -1) | (-(v126 ^ -1))) >> 31)) & 2)) - (v127 + ((~(((v128 ^ -1) | (-(v128 ^ -1))) >> 31)) & 2))) >> 31) & 1);
    int v289 = (int)((unsigned int)((int)((unsigned int)v106 >> 2)) >> 1);
    v189[v288] = v289;
    int * v191 = v100->cache_dirty;
    v191[v288] = 0;
    int * v193 = v100->cache_age;
    v193[v288] = 1;
    int * v195 = v100->cache_age;
    int v196 = v195[v288];
    int v197 = v195[v218];
    int v295 = v197 + ((int)((unsigned int)(v197 - v196) >> 31));
    v195[v218] = v295;
    int * v199 = v100->cache_age;
    int v200 = v199[v219];
    int v297 = v200 + ((int)((unsigned int)(v200 - v196) >> 31));
    v199[v219] = v297;
    int * v202 = v100->cache_age;
    v202[v288] = 0;
    v205 = v288;
  }
  int v300 = (v205 * 2) + (((int)((unsigned int)v106 >> 2)) & 1);
  int v206 = v112[v300];
  int * v207 = v100->reg_ready;
  int v302 = ((v104 + ((v101 - v104) & (~((v101 - v104) >> 31)))) + 1) + ((100 ^ (((~(((v110 ^ ((int)((unsigned int)((int)((unsigned int)v106 >> 2)) >> 1))) | (-(v110 ^ ((int)((unsigned int)((int)((unsigned int)v106 >> 2)) >> 1))))) >> 31)) | (~(((v111 ^ ((int)((unsigned int)((int)((unsigned int)v106 >> 2)) >> 1))) | (-(v111 ^ ((int)((unsigned int)((int)((unsigned int)v106 >> 2)) >> 1))))) >> 31))) & 104)) ^ (((~(((v108 ^ ((int)((unsigned int)((int)((unsigned int)v106 >> 2)) >> 1))) | (-(v108 ^ ((int)((unsigned int)((int)((unsigned int)v106 >> 2)) >> 1))))) >> 31)) | (~(((v109 ^ ((int)((unsigned int)((int)((unsigned int)v106 >> 2)) >> 1))) | (-(v109 ^ ((int)((unsigned int)((int)((unsigned int)v106 >> 2)) >> 1))))) >> 31))) & (1 ^ (100 ^ (((~(((v110 ^ ((int)((unsigned int)((int)((unsigned int)v106 >> 2)) >> 1))) | (-(v110 ^ ((int)((unsigned int)((int)((unsigned int)v106 >> 2)) >> 1))))) >> 31)) | (~(((v111 ^ ((int)((unsigned int)((int)((unsigned int)v106 >> 2)) >> 1))) | (-(v111 ^ ((int)((unsigned int)((int)((unsigned int)v106 >> 2)) >> 1))))) >> 31))) & 104)))));
  v207[10] = v302;
  int * v209 = v100->regs;
  v209[10] = v206;
  struct StateT * v211 = slot_6(v100);
  return v211;
}

struct StateT * slot_17(struct StateT * v1103) {
  int v1104 = v1103->timer;
  int v1277 = v1104 + 1;
  v1103->timer = v1277;
  int * v1106 = v1103->reg_ready;
  int * v1108 = v1103->regs;
  int v1109 = v1108[12];
  int v1111 = v1108[10];
  int * v1112 = v1103->cache_tags;
  int v1283 = (((int)((unsigned int)((int)((unsigned int)(v1109 + 68) >> 2)) >> 1)) & 1) * 2;
  int v1113 = v1112[v1283];
  int v1284 = ((((int)((unsigned int)((int)((unsigned int)(v1109 + 68) >> 2)) >> 1)) & 1) * 2) + 1;
  int v1114 = v1112[v1284];
  int v1285 = 4 + ((((int)((unsigned int)((int)((unsigned int)(v1109 + 68) >> 2)) >> 1)) & 3) * 2);
  int v1115 = v1112[v1285];
  int v1286 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v1109 + 68) >> 2)) >> 1)) & 3) * 2)) + 1;
  int v1116 = v1112[v1286];
  int v1117 = v1103->timer;
  int v1287 = v1117 + ((100 ^ (((~(((v1115 ^ ((int)((unsigned int)((int)((unsigned int)(v1109 + 68) >> 2)) >> 1))) | (-(v1115 ^ ((int)((unsigned int)((int)((unsigned int)(v1109 + 68) >> 2)) >> 1))))) >> 31)) | (~(((v1116 ^ ((int)((unsigned int)((int)((unsigned int)(v1109 + 68) >> 2)) >> 1))) | (-(v1116 ^ ((int)((unsigned int)((int)((unsigned int)(v1109 + 68) >> 2)) >> 1))))) >> 31))) & 104)) ^ (((~(((v1113 ^ ((int)((unsigned int)((int)((unsigned int)(v1109 + 68) >> 2)) >> 1))) | (-(v1113 ^ ((int)((unsigned int)((int)((unsigned int)(v1109 + 68) >> 2)) >> 1))))) >> 31)) | (~(((v1114 ^ ((int)((unsigned int)((int)((unsigned int)(v1109 + 68) >> 2)) >> 1))) | (-(v1114 ^ ((int)((unsigned int)((int)((unsigned int)(v1109 + 68) >> 2)) >> 1))))) >> 31))) & (1 ^ (100 ^ (((~(((v1115 ^ ((int)((unsigned int)((int)((unsigned int)(v1109 + 68) >> 2)) >> 1))) | (-(v1115 ^ ((int)((unsigned int)((int)((unsigned int)(v1109 + 68) >> 2)) >> 1))))) >> 31)) | (~(((v1116 ^ ((int)((unsigned int)((int)((unsigned int)(v1109 + 68) >> 2)) >> 1))) | (-(v1116 ^ ((int)((unsigned int)((int)((unsigned int)(v1109 + 68) >> 2)) >> 1))))) >> 31))) & 104)))));
  v1103->timer = v1287;
  bool v1288 = !(((~(((v1113 ^ ((int)((unsigned int)((int)((unsigned int)(v1109 + 68) >> 2)) >> 1))) | (-(v1113 ^ ((int)((unsigned int)((int)((unsigned int)(v1109 + 68) >> 2)) >> 1))))) >> 31)) | (~(((v1114 ^ ((int)((unsigned int)((int)((unsigned int)(v1109 + 68) >> 2)) >> 1))) | (-(v1114 ^ ((int)((unsigned int)((int)((unsigned int)(v1109 + 68) >> 2)) >> 1))))) >> 31))) == 0);
  int v1211;
  if (v1288) {
    int * v1119 = v1103->cache_age;
    int v1290 = ((((int)((unsigned int)((int)((unsigned int)(v1109 + 68) >> 2)) >> 1)) & 1) * 2) + ((~(((v1114 ^ ((int)((unsigned int)((int)((unsigned int)(v1109 + 68) >> 2)) >> 1))) | (-(v1114 ^ ((int)((unsigned int)((int)((unsigned int)(v1109 + 68) >> 2)) >> 1))))) >> 31)) & 1);
    int v1120 = v1119[v1290];
    int v1121 = v1119[v1283];
    int v1291 = v1121 + ((int)((unsigned int)(v1121 - v1120) >> 31));
    v1119[v1283] = v1291;
    int * v1123 = v1103->cache_age;
    int v1124 = v1123[v1284];
    int v1293 = v1124 + ((int)((unsigned int)(v1124 - v1120) >> 31));
    v1123[v1284] = v1293;
    int * v1126 = v1103->cache_age;
    v1126[v1290] = 0;
    v1211 = v1290;
  } else {
    int * v1129 = v1103->cache_age;
    int v1297 = (((int)((unsigned int)((int)((unsigned int)(v1109 + 68) >> 2)) >> 1)) & 1) * 2;
    int v1130 = v1129[v1297];
    int * v1131 = v1103->cache_tags;
    int v1132 = v1131[v1297];
    int v1133 = v1129[v1284];
    int v1134 = v1131[v1284];
    bool v1299 = !(((~(((v1115 ^ ((int)((unsigned int)((int)((unsigned int)(v1109 + 68) >> 2)) >> 1))) | (-(v1115 ^ ((int)((unsigned int)((int)((unsigned int)(v1109 + 68) >> 2)) >> 1))))) >> 31)) | (~(((v1116 ^ ((int)((unsigned int)((int)((unsigned int)(v1109 + 68) >> 2)) >> 1))) | (-(v1116 ^ ((int)((unsigned int)((int)((unsigned int)(v1109 + 68) >> 2)) >> 1))))) >> 31))) == 0);
    int v1188;
    if (v1299) {
      int * v1135 = v1103->cache_age;
      int v1301 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v1109 + 68) >> 2)) >> 1)) & 3) * 2)) + ((~(((v1116 ^ ((int)((unsigned int)((int)((unsigned int)(v1109 + 68) >> 2)) >> 1))) | (-(v1116 ^ ((int)((unsigned int)((int)((unsigned int)(v1109 + 68) >> 2)) >> 1))))) >> 31)) & 1);
      int v1136 = v1135[v1301];
      int v1137 = v1135[v1285];
      int v1302 = v1137 + ((int)((unsigned int)(v1137 - v1136) >> 31));
      v1135[v1285] = v1302;
      int * v1139 = v1103->cache_age;
      int v1140 = v1139[v1286];
      int v1304 = v1140 + ((int)((unsigned int)(v1140 - v1136) >> 31));
      v1139[v1286] = v1304;
      int * v1142 = v1103->cache_age;
      v1142[v1301] = 0;
      v1188 = v1301;
    } else {
      int * v1145 = v1103->cache_age;
      int v1308 = 4 + ((((int)((unsigned int)((int)((unsigned int)(v1109 + 68) >> 2)) >> 1)) & 3) * 2);
      int v1146 = v1145[v1308];
      int * v1147 = v1103->cache_tags;
      int v1148 = v1147[v1308];
      int v1149 = v1145[v1286];
      int v1150 = v1147[v1286];
      int * v1151 = v1103->cache_dirty;
      int v1311 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v1109 + 68) >> 2)) >> 1)) & 3) * 2)) + ((((v1146 + ((~(((v1148 ^ -1) | (-(v1148 ^ -1))) >> 31)) & 2)) - (v1149 + ((~(((v1150 ^ -1) | (-(v1150 ^ -1))) >> 31)) & 2))) >> 31) & 1);
      int v1152 = v1151[v1311];
      bool v1312 = !(v1152 == 0);
      if (v1312) {
        int * v1153 = v1103->cache_tags;
        int v1154 = v1153[v1311];
        int * v1155 = v1103->cache_vals;
        int v1315 = ((4 + ((((int)((unsigned int)((int)((unsigned int)(v1109 + 68) >> 2)) >> 1)) & 3) * 2)) + ((((v1146 + ((~(((v1148 ^ -1) | (-(v1148 ^ -1))) >> 31)) & 2)) - (v1149 + ((~(((v1150 ^ -1) | (-(v1150 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
        int v1156 = v1155[v1315];
        int v1316 = (((4 + ((((int)((unsigned int)((int)((unsigned int)(v1109 + 68) >> 2)) >> 1)) & 3) * 2)) + ((((v1146 + ((~(((v1148 ^ -1) | (-(v1148 ^ -1))) >> 31)) & 2)) - (v1149 + ((~(((v1150 ^ -1) | (-(v1150 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
        int v1157 = v1155[v1316];
        int * v1158 = v1103->mem;
        int v1318 = v1154 * 2;
        v1158[v1318] = v1156;
        int * v1160 = v1103->mem;
        int v1321 = (v1154 * 2) + 1;
        v1160[v1321] = v1157;
        ;
      } else {
        ;
      }
      int * v1165 = v1103->mem;
      int v1326 = ((int)((unsigned int)((int)((unsigned int)(v1109 + 68) >> 2)) >> 1)) * 2;
      int v1166 = v1165[v1326];
      int v1327 = (((int)((unsigned int)((int)((unsigned int)(v1109 + 68) >> 2)) >> 1)) * 2) + 1;
      int v1167 = v1165[v1327];
      int * v1168 = v1103->cache_vals;
      int v1329 = ((4 + ((((int)((unsigned int)((int)((unsigned int)(v1109 + 68) >> 2)) >> 1)) & 3) * 2)) + ((((v1146 + ((~(((v1148 ^ -1) | (-(v1148 ^ -1))) >> 31)) & 2)) - (v1149 + ((~(((v1150 ^ -1) | (-(v1150 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
      v1168[v1329] = v1166;
      int * v1170 = v1103->cache_vals;
      int v1332 = (((4 + ((((int)((unsigned int)((int)((unsigned int)(v1109 + 68) >> 2)) >> 1)) & 3) * 2)) + ((((v1146 + ((~(((v1148 ^ -1) | (-(v1148 ^ -1))) >> 31)) & 2)) - (v1149 + ((~(((v1150 ^ -1) | (-(v1150 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
      v1170[v1332] = v1167;
      int * v1172 = v1103->cache_tags;
      int v1335 = (int)((unsigned int)((int)((unsigned int)(v1109 + 68) >> 2)) >> 1);
      v1172[v1311] = v1335;
      int * v1174 = v1103->cache_dirty;
      v1174[v1311] = 0;
      int * v1176 = v1103->cache_age;
      v1176[v1311] = 1;
      int * v1178 = v1103->cache_age;
      int v1179 = v1178[v1311];
      int v1180 = v1178[v1285];
      int v1341 = v1180 + ((int)((unsigned int)(v1180 - v1179) >> 31));
      v1178[v1285] = v1341;
      int * v1182 = v1103->cache_age;
      int v1183 = v1182[v1286];
      int v1343 = v1183 + ((int)((unsigned int)(v1183 - v1179) >> 31));
      v1182[v1286] = v1343;
      int * v1185 = v1103->cache_age;
      v1185[v1311] = 0;
      v1188 = v1311;
    }
    int * v1189 = v1103->cache_vals;
    int v1346 = v1188 * 2;
    int v1190 = v1189[v1346];
    int v1347 = (v1188 * 2) + 1;
    int v1191 = v1189[v1347];
    int v1348 = (((((int)((unsigned int)((int)((unsigned int)(v1109 + 68) >> 2)) >> 1)) & 1) * 2) + ((((v1130 + ((~(((v1132 ^ -1) | (-(v1132 ^ -1))) >> 31)) & 2)) - (v1133 + ((~(((v1134 ^ -1) | (-(v1134 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
    v1189[v1348] = v1190;
    int * v1193 = v1103->cache_vals;
    int v1351 = ((((((int)((unsigned int)((int)((unsigned int)(v1109 + 68) >> 2)) >> 1)) & 1) * 2) + ((((v1130 + ((~(((v1132 ^ -1) | (-(v1132 ^ -1))) >> 31)) & 2)) - (v1133 + ((~(((v1134 ^ -1) | (-(v1134 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
    v1193[v1351] = v1191;
    int * v1195 = v1103->cache_tags;
    int v1354 = ((((int)((unsigned int)((int)((unsigned int)(v1109 + 68) >> 2)) >> 1)) & 1) * 2) + ((((v1130 + ((~(((v1132 ^ -1) | (-(v1132 ^ -1))) >> 31)) & 2)) - (v1133 + ((~(((v1134 ^ -1) | (-(v1134 ^ -1))) >> 31)) & 2))) >> 31) & 1);
    int v1355 = (int)((unsigned int)((int)((unsigned int)(v1109 + 68) >> 2)) >> 1);
    v1195[v1354] = v1355;
    int * v1197 = v1103->cache_dirty;
    v1197[v1354] = 0;
    int * v1199 = v1103->cache_age;
    v1199[v1354] = 1;
    int * v1201 = v1103->cache_age;
    int v1202 = v1201[v1354];
    int v1203 = v1201[v1283];
    int v1361 = v1203 + ((int)((unsigned int)(v1203 - v1202) >> 31));
    v1201[v1283] = v1361;
    int * v1205 = v1103->cache_age;
    int v1206 = v1205[v1284];
    int v1363 = v1206 + ((int)((unsigned int)(v1206 - v1202) >> 31));
    v1205[v1284] = v1363;
    int * v1208 = v1103->cache_age;
    v1208[v1354] = 0;
    v1211 = v1354;
  }
  int * v1212 = v1103->cache_vals;
  int v1366 = (v1211 * 2) + (((int)((unsigned int)(v1109 + 68) >> 2)) & 1);
  v1212[v1366] = v1111;
  int * v1214 = v1103->cache_tags;
  int v1215 = v1214[v1285];
  int v1216 = v1214[v1286];
  bool v1369 = !(((~(((v1215 ^ ((int)((unsigned int)((int)((unsigned int)(v1109 + 68) >> 2)) >> 1))) | (-(v1215 ^ ((int)((unsigned int)((int)((unsigned int)(v1109 + 68) >> 2)) >> 1))))) >> 31)) | (~(((v1216 ^ ((int)((unsigned int)((int)((unsigned int)(v1109 + 68) >> 2)) >> 1))) | (-(v1216 ^ ((int)((unsigned int)((int)((unsigned int)(v1109 + 68) >> 2)) >> 1))))) >> 31))) == 0);
  int v1270;
  if (v1369) {
    int * v1217 = v1103->cache_age;
    int v1371 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v1109 + 68) >> 2)) >> 1)) & 3) * 2)) + ((~(((v1216 ^ ((int)((unsigned int)((int)((unsigned int)(v1109 + 68) >> 2)) >> 1))) | (-(v1216 ^ ((int)((unsigned int)((int)((unsigned int)(v1109 + 68) >> 2)) >> 1))))) >> 31)) & 1);
    int v1218 = v1217[v1371];
    int v1219 = v1217[v1285];
    int v1372 = v1219 + ((int)((unsigned int)(v1219 - v1218) >> 31));
    v1217[v1285] = v1372;
    int * v1221 = v1103->cache_age;
    int v1222 = v1221[v1286];
    int v1374 = v1222 + ((int)((unsigned int)(v1222 - v1218) >> 31));
    v1221[v1286] = v1374;
    int * v1224 = v1103->cache_age;
    v1224[v1371] = 0;
    v1270 = v1371;
  } else {
    int * v1227 = v1103->cache_age;
    int v1378 = 4 + ((((int)((unsigned int)((int)((unsigned int)(v1109 + 68) >> 2)) >> 1)) & 3) * 2);
    int v1228 = v1227[v1378];
    int * v1229 = v1103->cache_tags;
    int v1230 = v1229[v1378];
    int v1231 = v1227[v1286];
    int v1232 = v1229[v1286];
    int * v1233 = v1103->cache_dirty;
    int v1381 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v1109 + 68) >> 2)) >> 1)) & 3) * 2)) + ((((v1228 + ((~(((v1230 ^ -1) | (-(v1230 ^ -1))) >> 31)) & 2)) - (v1231 + ((~(((v1232 ^ -1) | (-(v1232 ^ -1))) >> 31)) & 2))) >> 31) & 1);
    int v1234 = v1233[v1381];
    bool v1382 = !(v1234 == 0);
    if (v1382) {
      int * v1235 = v1103->cache_tags;
      int v1236 = v1235[v1381];
      int * v1237 = v1103->cache_vals;
      int v1385 = ((4 + ((((int)((unsigned int)((int)((unsigned int)(v1109 + 68) >> 2)) >> 1)) & 3) * 2)) + ((((v1228 + ((~(((v1230 ^ -1) | (-(v1230 ^ -1))) >> 31)) & 2)) - (v1231 + ((~(((v1232 ^ -1) | (-(v1232 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
      int v1238 = v1237[v1385];
      int v1386 = (((4 + ((((int)((unsigned int)((int)((unsigned int)(v1109 + 68) >> 2)) >> 1)) & 3) * 2)) + ((((v1228 + ((~(((v1230 ^ -1) | (-(v1230 ^ -1))) >> 31)) & 2)) - (v1231 + ((~(((v1232 ^ -1) | (-(v1232 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
      int v1239 = v1237[v1386];
      int * v1240 = v1103->mem;
      int v1388 = v1236 * 2;
      v1240[v1388] = v1238;
      int * v1242 = v1103->mem;
      int v1391 = (v1236 * 2) + 1;
      v1242[v1391] = v1239;
      ;
    } else {
      ;
    }
    int * v1247 = v1103->mem;
    int v1396 = ((int)((unsigned int)((int)((unsigned int)(v1109 + 68) >> 2)) >> 1)) * 2;
    int v1248 = v1247[v1396];
    int v1397 = (((int)((unsigned int)((int)((unsigned int)(v1109 + 68) >> 2)) >> 1)) * 2) + 1;
    int v1249 = v1247[v1397];
    int * v1250 = v1103->cache_vals;
    int v1399 = ((4 + ((((int)((unsigned int)((int)((unsigned int)(v1109 + 68) >> 2)) >> 1)) & 3) * 2)) + ((((v1228 + ((~(((v1230 ^ -1) | (-(v1230 ^ -1))) >> 31)) & 2)) - (v1231 + ((~(((v1232 ^ -1) | (-(v1232 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
    v1250[v1399] = v1248;
    int * v1252 = v1103->cache_vals;
    int v1402 = (((4 + ((((int)((unsigned int)((int)((unsigned int)(v1109 + 68) >> 2)) >> 1)) & 3) * 2)) + ((((v1228 + ((~(((v1230 ^ -1) | (-(v1230 ^ -1))) >> 31)) & 2)) - (v1231 + ((~(((v1232 ^ -1) | (-(v1232 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
    v1252[v1402] = v1249;
    int * v1254 = v1103->cache_tags;
    int v1405 = (int)((unsigned int)((int)((unsigned int)(v1109 + 68) >> 2)) >> 1);
    v1254[v1381] = v1405;
    int * v1256 = v1103->cache_dirty;
    v1256[v1381] = 0;
    int * v1258 = v1103->cache_age;
    v1258[v1381] = 1;
    int * v1260 = v1103->cache_age;
    int v1261 = v1260[v1381];
    int v1262 = v1260[v1285];
    int v1411 = v1262 + ((int)((unsigned int)(v1262 - v1261) >> 31));
    v1260[v1285] = v1411;
    int * v1264 = v1103->cache_age;
    int v1265 = v1264[v1286];
    int v1413 = v1265 + ((int)((unsigned int)(v1265 - v1261) >> 31));
    v1264[v1286] = v1413;
    int * v1267 = v1103->cache_age;
    v1267[v1381] = 0;
    v1270 = v1381;
  }
  int * v1271 = v1103->cache_vals;
  int v1416 = (v1270 * 2) + (((int)((unsigned int)(v1109 + 68) >> 2)) & 1);
  v1271[v1416] = v1111;
  int * v1273 = v1103->cache_dirty;
  v1273[v1270] = 1;
  struct StateT * v1275 = slot_18(v1103);
  return v1275;
}

struct StateT * slot_2(struct StateT * v39) {
  int v40 = v39->timer;
  int v51 = v40 + 1;
  v39->timer = v51;
  int * v42 = v39->reg_ready;
  int v43 = v42[11];
  int * v44 = v39->regs;
  int v45 = v44[11];
  int v55 = (v43 + ((v40 - v43) & (~((v40 - v43) >> 31)))) + 1;
  v42[11] = v55;
  int * v47 = v39->regs;
  int v57 = v45 + 72;
  v47[11] = v57;
  struct StateT * v49 = slot_3(v39);
  return v49;
}

struct StateT * slot_7(struct StateT * v514) {
  int v515 = v514->timer;
  int v529 = v515 + 1;
  v514->timer = v529;
  int * v517 = v514->reg_ready;
  int * v519 = v514->regs;
  int v520 = v519[10];
  int v522 = v519[11];
  bool v534 = (v520 ^ -2147483648) >= (v522 ^ -2147483648);
  struct StateT * v527;
  if (v534) {
    struct StateT * v523 = slot_18(v514);
    v527 = v523;
  } else {
    struct StateT * v525 = slot_8(v514);
    v527 = v525;
  }
  return v527;
}

struct StateT * slot_3(struct StateT * v60) {
  int v61 = v60->timer;
  int v74 = v61 + 1;
  v60->timer = v74;
  int * v63 = v60->reg_ready;
  int v64 = v63[11];
  int * v65 = v60->regs;
  int v66 = v65[11];
  int v67 = v63[10];
  int v68 = v65[10];
  int v79 = (v67 + (((v64 + ((v61 - v64) & (~((v61 - v64) >> 31)))) - v67) & (~(((v64 + ((v61 - v64) & (~((v61 - v64) >> 31)))) - v67) >> 31)))) + 1;
  v63[10] = v79;
  int * v70 = v60->regs;
  int v81 = v66 + v68;
  v70[10] = v81;
  struct StateT * v72 = slot_4(v60);
  return v72;
}

struct StateT * snippet(struct StateT * v0) {
  struct StateT * v1 = slot_0(v0);
  int v1422 = v1->timer;
  int * v1423 = v1->reg_ready;
  int v1424 = v1423[0];
  int v1555 = v1424 + ((v1422 - v1424) & (~((v1422 - v1424) >> 31)));
  v1->timer = v1555;
  int v1426 = v1->timer;
  int * v1427 = v1->reg_ready;
  int v1428 = v1427[1];
  int v1558 = v1428 + ((v1426 - v1428) & (~((v1426 - v1428) >> 31)));
  v1->timer = v1558;
  int v1430 = v1->timer;
  int * v1431 = v1->reg_ready;
  int v1432 = v1431[2];
  int v1561 = v1432 + ((v1430 - v1432) & (~((v1430 - v1432) >> 31)));
  v1->timer = v1561;
  int v1434 = v1->timer;
  int * v1435 = v1->reg_ready;
  int v1436 = v1435[3];
  int v1564 = v1436 + ((v1434 - v1436) & (~((v1434 - v1436) >> 31)));
  v1->timer = v1564;
  int v1438 = v1->timer;
  int * v1439 = v1->reg_ready;
  int v1440 = v1439[4];
  int v1567 = v1440 + ((v1438 - v1440) & (~((v1438 - v1440) >> 31)));
  v1->timer = v1567;
  int v1442 = v1->timer;
  int * v1443 = v1->reg_ready;
  int v1444 = v1443[5];
  int v1570 = v1444 + ((v1442 - v1444) & (~((v1442 - v1444) >> 31)));
  v1->timer = v1570;
  int v1446 = v1->timer;
  int * v1447 = v1->reg_ready;
  int v1448 = v1447[6];
  int v1573 = v1448 + ((v1446 - v1448) & (~((v1446 - v1448) >> 31)));
  v1->timer = v1573;
  int v1450 = v1->timer;
  int * v1451 = v1->reg_ready;
  int v1452 = v1451[7];
  int v1576 = v1452 + ((v1450 - v1452) & (~((v1450 - v1452) >> 31)));
  v1->timer = v1576;
  int v1454 = v1->timer;
  int * v1455 = v1->reg_ready;
  int v1456 = v1455[8];
  int v1579 = v1456 + ((v1454 - v1456) & (~((v1454 - v1456) >> 31)));
  v1->timer = v1579;
  int v1458 = v1->timer;
  int * v1459 = v1->reg_ready;
  int v1460 = v1459[9];
  int v1582 = v1460 + ((v1458 - v1460) & (~((v1458 - v1460) >> 31)));
  v1->timer = v1582;
  int v1462 = v1->timer;
  int * v1463 = v1->reg_ready;
  int v1464 = v1463[10];
  int v1585 = v1464 + ((v1462 - v1464) & (~((v1462 - v1464) >> 31)));
  v1->timer = v1585;
  int v1466 = v1->timer;
  int * v1467 = v1->reg_ready;
  int v1468 = v1467[11];
  int v1588 = v1468 + ((v1466 - v1468) & (~((v1466 - v1468) >> 31)));
  v1->timer = v1588;
  int v1470 = v1->timer;
  int * v1471 = v1->reg_ready;
  int v1472 = v1471[12];
  int v1591 = v1472 + ((v1470 - v1472) & (~((v1470 - v1472) >> 31)));
  v1->timer = v1591;
  int v1474 = v1->timer;
  int * v1475 = v1->reg_ready;
  int v1476 = v1475[13];
  int v1594 = v1476 + ((v1474 - v1476) & (~((v1474 - v1476) >> 31)));
  v1->timer = v1594;
  int v1478 = v1->timer;
  int * v1479 = v1->reg_ready;
  int v1480 = v1479[14];
  int v1597 = v1480 + ((v1478 - v1480) & (~((v1478 - v1480) >> 31)));
  v1->timer = v1597;
  int v1482 = v1->timer;
  int * v1483 = v1->reg_ready;
  int v1484 = v1483[15];
  int v1600 = v1484 + ((v1482 - v1484) & (~((v1482 - v1484) >> 31)));
  v1->timer = v1600;
  int v1486 = v1->timer;
  int * v1487 = v1->reg_ready;
  int v1488 = v1487[16];
  int v1603 = v1488 + ((v1486 - v1488) & (~((v1486 - v1488) >> 31)));
  v1->timer = v1603;
  int v1490 = v1->timer;
  int * v1491 = v1->reg_ready;
  int v1492 = v1491[17];
  int v1606 = v1492 + ((v1490 - v1492) & (~((v1490 - v1492) >> 31)));
  v1->timer = v1606;
  int v1494 = v1->timer;
  int * v1495 = v1->reg_ready;
  int v1496 = v1495[18];
  int v1609 = v1496 + ((v1494 - v1496) & (~((v1494 - v1496) >> 31)));
  v1->timer = v1609;
  int v1498 = v1->timer;
  int * v1499 = v1->reg_ready;
  int v1500 = v1499[19];
  int v1612 = v1500 + ((v1498 - v1500) & (~((v1498 - v1500) >> 31)));
  v1->timer = v1612;
  int v1502 = v1->timer;
  int * v1503 = v1->reg_ready;
  int v1504 = v1503[20];
  int v1615 = v1504 + ((v1502 - v1504) & (~((v1502 - v1504) >> 31)));
  v1->timer = v1615;
  int v1506 = v1->timer;
  int * v1507 = v1->reg_ready;
  int v1508 = v1507[21];
  int v1618 = v1508 + ((v1506 - v1508) & (~((v1506 - v1508) >> 31)));
  v1->timer = v1618;
  int v1510 = v1->timer;
  int * v1511 = v1->reg_ready;
  int v1512 = v1511[22];
  int v1621 = v1512 + ((v1510 - v1512) & (~((v1510 - v1512) >> 31)));
  v1->timer = v1621;
  int v1514 = v1->timer;
  int * v1515 = v1->reg_ready;
  int v1516 = v1515[23];
  int v1624 = v1516 + ((v1514 - v1516) & (~((v1514 - v1516) >> 31)));
  v1->timer = v1624;
  int v1518 = v1->timer;
  int * v1519 = v1->reg_ready;
  int v1520 = v1519[24];
  int v1627 = v1520 + ((v1518 - v1520) & (~((v1518 - v1520) >> 31)));
  v1->timer = v1627;
  int v1522 = v1->timer;
  int * v1523 = v1->reg_ready;
  int v1524 = v1523[25];
  int v1630 = v1524 + ((v1522 - v1524) & (~((v1522 - v1524) >> 31)));
  v1->timer = v1630;
  int v1526 = v1->timer;
  int * v1527 = v1->reg_ready;
  int v1528 = v1527[26];
  int v1633 = v1528 + ((v1526 - v1528) & (~((v1526 - v1528) >> 31)));
  v1->timer = v1633;
  int v1530 = v1->timer;
  int * v1531 = v1->reg_ready;
  int v1532 = v1531[27];
  int v1636 = v1532 + ((v1530 - v1532) & (~((v1530 - v1532) >> 31)));
  v1->timer = v1636;
  int v1534 = v1->timer;
  int * v1535 = v1->reg_ready;
  int v1536 = v1535[28];
  int v1639 = v1536 + ((v1534 - v1536) & (~((v1534 - v1536) >> 31)));
  v1->timer = v1639;
  int v1538 = v1->timer;
  int * v1539 = v1->reg_ready;
  int v1540 = v1539[29];
  int v1642 = v1540 + ((v1538 - v1540) & (~((v1538 - v1540) >> 31)));
  v1->timer = v1642;
  int v1542 = v1->timer;
  int * v1543 = v1->reg_ready;
  int v1544 = v1543[30];
  int v1645 = v1544 + ((v1542 - v1544) & (~((v1542 - v1544) >> 31)));
  v1->timer = v1645;
  int v1546 = v1->timer;
  int * v1547 = v1->reg_ready;
  int v1548 = v1547[31];
  int v1648 = v1548 + ((v1546 - v1548) & (~((v1546 - v1548) >> 31)));
  v1->timer = v1648;
  return v1;
}

struct StateT * slot_10(struct StateT * v582) {
  int v583 = v582->timer;
  int v594 = v583 + 1;
  v582->timer = v594;
  int * v585 = v582->reg_ready;
  int v586 = v585[11];
  int * v587 = v582->regs;
  int v588 = v587[11];
  int v598 = (v586 + ((v583 - v586) & (~((v583 - v586) >> 31)))) + 1;
  v585[11] = v598;
  int * v590 = v582->regs;
  int v600 = v588 + 4;
  v590[11] = v600;
  struct StateT * v592 = slot_11(v582);
  return v592;
}

struct StateT * slot_1(struct StateT * v23) {
  int v24 = v23->timer;
  int v32 = v24 + 1;
  v23->timer = v32;
  int * v26 = v23->reg_ready;
  v26[11] = v32;
  int * v28 = v23->regs;
  v28[11] = 0;
  struct StateT * v30 = slot_2(v23);
  return v30;
}

struct StateT * slot_8(struct StateT * v545) {
  int v546 = v545->timer;
  int v557 = v546 + 1;
  v545->timer = v557;
  int * v548 = v545->reg_ready;
  int v549 = v548[10];
  int * v550 = v545->regs;
  int v551 = v550[10];
  int v561 = (v549 + ((v546 - v549) & (~((v546 - v549) >> 31)))) + 1;
  v548[10] = v561;
  int * v553 = v545->regs;
  int v563 = v551 << 29;
  v553[10] = v563;
  struct StateT * v555 = slot_9(v545);
  return v555;
}

struct StateT * slot_4(struct StateT * v84) {
  int v85 = v84->timer;
  int v93 = v85 + 1;
  v84->timer = v93;
  int * v87 = v84->reg_ready;
  v87[11] = v93;
  int * v89 = v84->regs;
  v89[11] = 0;
  struct StateT * v91 = slot_5(v84);
  return v91;
}

struct StateT * slot_13(struct StateT * v640) {
  int v641 = v640->timer;
  int v654 = v641 + 1;
  v640->timer = v654;
  int * v643 = v640->reg_ready;
  int v644 = v643[11];
  int * v645 = v640->regs;
  int v646 = v645[11];
  int v647 = v643[10];
  int v648 = v645[10];
  int v659 = (v647 + (((v644 + ((v641 - v644) & (~((v641 - v644) >> 31)))) - v647) & (~(((v644 + ((v641 - v644) & (~((v641 - v644) >> 31)))) - v647) >> 31)))) + 1;
  v643[10] = v659;
  int * v650 = v640->regs;
  int v661 = v646 + v648;
  v650[10] = v661;
  struct StateT * v652 = slot_14(v640);
  return v652;
}

struct StateT * slot_15(struct StateT * v871) {
  int v872 = v871->timer;
  int v984 = v872 + 1;
  v871->timer = v984;
  int * v874 = v871->reg_ready;
  int v875 = v874[12];
  int * v876 = v871->regs;
  int v877 = v876[12];
  int * v878 = v871->cache_tags;
  int v989 = (((int)((unsigned int)((int)((unsigned int)(v877 + 68) >> 2)) >> 1)) & 1) * 2;
  int v879 = v878[v989];
  int v990 = ((((int)((unsigned int)((int)((unsigned int)(v877 + 68) >> 2)) >> 1)) & 1) * 2) + 1;
  int v880 = v878[v990];
  int v991 = 4 + ((((int)((unsigned int)((int)((unsigned int)(v877 + 68) >> 2)) >> 1)) & 3) * 2);
  int v881 = v878[v991];
  int v992 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v877 + 68) >> 2)) >> 1)) & 3) * 2)) + 1;
  int v882 = v878[v992];
  int * v883 = v871->cache_vals;
  bool v993 = !(((~(((v879 ^ ((int)((unsigned int)((int)((unsigned int)(v877 + 68) >> 2)) >> 1))) | (-(v879 ^ ((int)((unsigned int)((int)((unsigned int)(v877 + 68) >> 2)) >> 1))))) >> 31)) | (~(((v880 ^ ((int)((unsigned int)((int)((unsigned int)(v877 + 68) >> 2)) >> 1))) | (-(v880 ^ ((int)((unsigned int)((int)((unsigned int)(v877 + 68) >> 2)) >> 1))))) >> 31))) == 0);
  int v976;
  if (v993) {
    int * v884 = v871->cache_age;
    int v995 = ((((int)((unsigned int)((int)((unsigned int)(v877 + 68) >> 2)) >> 1)) & 1) * 2) + ((~(((v880 ^ ((int)((unsigned int)((int)((unsigned int)(v877 + 68) >> 2)) >> 1))) | (-(v880 ^ ((int)((unsigned int)((int)((unsigned int)(v877 + 68) >> 2)) >> 1))))) >> 31)) & 1);
    int v885 = v884[v995];
    int v886 = v884[v989];
    int v996 = v886 + ((int)((unsigned int)(v886 - v885) >> 31));
    v884[v989] = v996;
    int * v888 = v871->cache_age;
    int v889 = v888[v990];
    int v998 = v889 + ((int)((unsigned int)(v889 - v885) >> 31));
    v888[v990] = v998;
    int * v891 = v871->cache_age;
    v891[v995] = 0;
    v976 = v995;
  } else {
    int * v894 = v871->cache_age;
    int v1002 = (((int)((unsigned int)((int)((unsigned int)(v877 + 68) >> 2)) >> 1)) & 1) * 2;
    int v895 = v894[v1002];
    int * v896 = v871->cache_tags;
    int v897 = v896[v1002];
    int v898 = v894[v990];
    int v899 = v896[v990];
    bool v1004 = !(((~(((v881 ^ ((int)((unsigned int)((int)((unsigned int)(v877 + 68) >> 2)) >> 1))) | (-(v881 ^ ((int)((unsigned int)((int)((unsigned int)(v877 + 68) >> 2)) >> 1))))) >> 31)) | (~(((v882 ^ ((int)((unsigned int)((int)((unsigned int)(v877 + 68) >> 2)) >> 1))) | (-(v882 ^ ((int)((unsigned int)((int)((unsigned int)(v877 + 68) >> 2)) >> 1))))) >> 31))) == 0);
    int v953;
    if (v1004) {
      int * v900 = v871->cache_age;
      int v1006 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v877 + 68) >> 2)) >> 1)) & 3) * 2)) + ((~(((v882 ^ ((int)((unsigned int)((int)((unsigned int)(v877 + 68) >> 2)) >> 1))) | (-(v882 ^ ((int)((unsigned int)((int)((unsigned int)(v877 + 68) >> 2)) >> 1))))) >> 31)) & 1);
      int v901 = v900[v1006];
      int v902 = v900[v991];
      int v1007 = v902 + ((int)((unsigned int)(v902 - v901) >> 31));
      v900[v991] = v1007;
      int * v904 = v871->cache_age;
      int v905 = v904[v992];
      int v1009 = v905 + ((int)((unsigned int)(v905 - v901) >> 31));
      v904[v992] = v1009;
      int * v907 = v871->cache_age;
      v907[v1006] = 0;
      v953 = v1006;
    } else {
      int * v910 = v871->cache_age;
      int v1013 = 4 + ((((int)((unsigned int)((int)((unsigned int)(v877 + 68) >> 2)) >> 1)) & 3) * 2);
      int v911 = v910[v1013];
      int * v912 = v871->cache_tags;
      int v913 = v912[v1013];
      int v914 = v910[v992];
      int v915 = v912[v992];
      int * v916 = v871->cache_dirty;
      int v1016 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v877 + 68) >> 2)) >> 1)) & 3) * 2)) + ((((v911 + ((~(((v913 ^ -1) | (-(v913 ^ -1))) >> 31)) & 2)) - (v914 + ((~(((v915 ^ -1) | (-(v915 ^ -1))) >> 31)) & 2))) >> 31) & 1);
      int v917 = v916[v1016];
      bool v1017 = !(v917 == 0);
      if (v1017) {
        int * v918 = v871->cache_tags;
        int v919 = v918[v1016];
        int * v920 = v871->cache_vals;
        int v1020 = ((4 + ((((int)((unsigned int)((int)((unsigned int)(v877 + 68) >> 2)) >> 1)) & 3) * 2)) + ((((v911 + ((~(((v913 ^ -1) | (-(v913 ^ -1))) >> 31)) & 2)) - (v914 + ((~(((v915 ^ -1) | (-(v915 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
        int v921 = v920[v1020];
        int v1021 = (((4 + ((((int)((unsigned int)((int)((unsigned int)(v877 + 68) >> 2)) >> 1)) & 3) * 2)) + ((((v911 + ((~(((v913 ^ -1) | (-(v913 ^ -1))) >> 31)) & 2)) - (v914 + ((~(((v915 ^ -1) | (-(v915 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
        int v922 = v920[v1021];
        int * v923 = v871->mem;
        int v1023 = v919 * 2;
        v923[v1023] = v921;
        int * v925 = v871->mem;
        int v1026 = (v919 * 2) + 1;
        v925[v1026] = v922;
        ;
      } else {
        ;
      }
      int * v930 = v871->mem;
      int v1031 = ((int)((unsigned int)((int)((unsigned int)(v877 + 68) >> 2)) >> 1)) * 2;
      int v931 = v930[v1031];
      int v1032 = (((int)((unsigned int)((int)((unsigned int)(v877 + 68) >> 2)) >> 1)) * 2) + 1;
      int v932 = v930[v1032];
      int * v933 = v871->cache_vals;
      int v1034 = ((4 + ((((int)((unsigned int)((int)((unsigned int)(v877 + 68) >> 2)) >> 1)) & 3) * 2)) + ((((v911 + ((~(((v913 ^ -1) | (-(v913 ^ -1))) >> 31)) & 2)) - (v914 + ((~(((v915 ^ -1) | (-(v915 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
      v933[v1034] = v931;
      int * v935 = v871->cache_vals;
      int v1037 = (((4 + ((((int)((unsigned int)((int)((unsigned int)(v877 + 68) >> 2)) >> 1)) & 3) * 2)) + ((((v911 + ((~(((v913 ^ -1) | (-(v913 ^ -1))) >> 31)) & 2)) - (v914 + ((~(((v915 ^ -1) | (-(v915 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
      v935[v1037] = v932;
      int * v937 = v871->cache_tags;
      int v1040 = (int)((unsigned int)((int)((unsigned int)(v877 + 68) >> 2)) >> 1);
      v937[v1016] = v1040;
      int * v939 = v871->cache_dirty;
      v939[v1016] = 0;
      int * v941 = v871->cache_age;
      v941[v1016] = 1;
      int * v943 = v871->cache_age;
      int v944 = v943[v1016];
      int v945 = v943[v991];
      int v1046 = v945 + ((int)((unsigned int)(v945 - v944) >> 31));
      v943[v991] = v1046;
      int * v947 = v871->cache_age;
      int v948 = v947[v992];
      int v1048 = v948 + ((int)((unsigned int)(v948 - v944) >> 31));
      v947[v992] = v1048;
      int * v950 = v871->cache_age;
      v950[v1016] = 0;
      v953 = v1016;
    }
    int * v954 = v871->cache_vals;
    int v1051 = v953 * 2;
    int v955 = v954[v1051];
    int v1052 = (v953 * 2) + 1;
    int v956 = v954[v1052];
    int v1053 = (((((int)((unsigned int)((int)((unsigned int)(v877 + 68) >> 2)) >> 1)) & 1) * 2) + ((((v895 + ((~(((v897 ^ -1) | (-(v897 ^ -1))) >> 31)) & 2)) - (v898 + ((~(((v899 ^ -1) | (-(v899 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
    v954[v1053] = v955;
    int * v958 = v871->cache_vals;
    int v1056 = ((((((int)((unsigned int)((int)((unsigned int)(v877 + 68) >> 2)) >> 1)) & 1) * 2) + ((((v895 + ((~(((v897 ^ -1) | (-(v897 ^ -1))) >> 31)) & 2)) - (v898 + ((~(((v899 ^ -1) | (-(v899 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
    v958[v1056] = v956;
    int * v960 = v871->cache_tags;
    int v1059 = ((((int)((unsigned int)((int)((unsigned int)(v877 + 68) >> 2)) >> 1)) & 1) * 2) + ((((v895 + ((~(((v897 ^ -1) | (-(v897 ^ -1))) >> 31)) & 2)) - (v898 + ((~(((v899 ^ -1) | (-(v899 ^ -1))) >> 31)) & 2))) >> 31) & 1);
    int v1060 = (int)((unsigned int)((int)((unsigned int)(v877 + 68) >> 2)) >> 1);
    v960[v1059] = v1060;
    int * v962 = v871->cache_dirty;
    v962[v1059] = 0;
    int * v964 = v871->cache_age;
    v964[v1059] = 1;
    int * v966 = v871->cache_age;
    int v967 = v966[v1059];
    int v968 = v966[v989];
    int v1066 = v968 + ((int)((unsigned int)(v968 - v967) >> 31));
    v966[v989] = v1066;
    int * v970 = v871->cache_age;
    int v971 = v970[v990];
    int v1068 = v971 + ((int)((unsigned int)(v971 - v967) >> 31));
    v970[v990] = v1068;
    int * v973 = v871->cache_age;
    v973[v1059] = 0;
    v976 = v1059;
  }
  int v1071 = (v976 * 2) + (((int)((unsigned int)(v877 + 68) >> 2)) & 1);
  int v977 = v883[v1071];
  int * v978 = v871->reg_ready;
  int v1074 = ((v875 + ((v872 - v875) & (~((v872 - v875) >> 31)))) + 1) + ((100 ^ (((~(((v881 ^ ((int)((unsigned int)((int)((unsigned int)(v877 + 68) >> 2)) >> 1))) | (-(v881 ^ ((int)((unsigned int)((int)((unsigned int)(v877 + 68) >> 2)) >> 1))))) >> 31)) | (~(((v882 ^ ((int)((unsigned int)((int)((unsigned int)(v877 + 68) >> 2)) >> 1))) | (-(v882 ^ ((int)((unsigned int)((int)((unsigned int)(v877 + 68) >> 2)) >> 1))))) >> 31))) & 104)) ^ (((~(((v879 ^ ((int)((unsigned int)((int)((unsigned int)(v877 + 68) >> 2)) >> 1))) | (-(v879 ^ ((int)((unsigned int)((int)((unsigned int)(v877 + 68) >> 2)) >> 1))))) >> 31)) | (~(((v880 ^ ((int)((unsigned int)((int)((unsigned int)(v877 + 68) >> 2)) >> 1))) | (-(v880 ^ ((int)((unsigned int)((int)((unsigned int)(v877 + 68) >> 2)) >> 1))))) >> 31))) & (1 ^ (100 ^ (((~(((v881 ^ ((int)((unsigned int)((int)((unsigned int)(v877 + 68) >> 2)) >> 1))) | (-(v881 ^ ((int)((unsigned int)((int)((unsigned int)(v877 + 68) >> 2)) >> 1))))) >> 31)) | (~(((v882 ^ ((int)((unsigned int)((int)((unsigned int)(v877 + 68) >> 2)) >> 1))) | (-(v882 ^ ((int)((unsigned int)((int)((unsigned int)(v877 + 68) >> 2)) >> 1))))) >> 31))) & 104)))));
  v978[11] = v1074;
  int * v980 = v871->regs;
  v980[11] = v977;
  struct StateT * v982 = slot_16(v871);
  return v982;
}

struct StateT * slot_18(struct StateT * v540) {
  int v541 = v540->timer;
  int v544 = v541 + 1;
  v540->timer = v544;
  return v540;
}

struct StateT * slot_9(struct StateT * v566) {
  int v567 = v566->timer;
  int v575 = v567 + 1;
  v566->timer = v575;
  int * v569 = v566->reg_ready;
  v569[11] = v575;
  int * v571 = v566->regs;
  v571[11] = 0;
  struct StateT * v573 = slot_10(v566);
  return v573;
}

struct StateT * slot_11(struct StateT * v603) {
  int v604 = v603->timer;
  int v612 = v604 + 1;
  v603->timer = v612;
  int * v606 = v603->reg_ready;
  v606[12] = v612;
  int * v608 = v603->regs;
  v608[12] = 0;
  struct StateT * v610 = slot_12(v603);
  return v610;
}

struct StateT * slot_0(struct StateT * v2) {
  int v3 = v2->timer;
  int v14 = v3 + 1;
  v2->timer = v14;
  int * v5 = v2->reg_ready;
  int v6 = v5[10];
  int * v7 = v2->regs;
  int v8 = v7[10];
  int v18 = (v6 + ((v3 - v6) & (~((v3 - v6) >> 31)))) + 1;
  v5[10] = v18;
  int * v10 = v2->regs;
  int v20 = v8 << 2;
  v10[10] = v20;
  struct StateT * v12 = slot_1(v2);
  return v12;
}



/*****************************************
End of C Generated Code
*******************************************/

void init(struct StateT *s) {
  for (int i=0; i<NUM_REGS; i++) {
    s->regs[i] = 0;
    s->saved_regs[i] = 0;
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
  
  // public data, where the section headers put it
  s1.mem[0] = 8;
  s2.mem[0] = 8;
  int x = bounded(0, 15);
  s1.regs[10] = x;
  s2.regs[10] = x;
  // probe, the attacker's: the same draw in both states
  for (int i=0; i<16; i++) {
    int v = bounded(0, 20);
    s1.mem[1 + i] = v;
    s2.mem[1 + i] = v;
  }
  // temp, the attacker's: the same draw in both states
  for (int i=0; i<1; i++) {
    int v = bounded(0, 20);
    s1.mem[17 + i] = v;
    s2.mem[17 + i] = v;
  }
  // publicarray, the attacker's: the same draw in both states
  for (int i=0; i<8; i++) {
    int v = bounded(0, 20);
    s1.mem[18 + i] = v;
    s2.mem[18 + i] = v;
  }
  
  // secretarray, secret: a different draw in each state
  for (int i=0; i<8; i++) {
    s1.mem[26 + i] = secret(0, 20);
    s2.mem[26 + i] = secret(0, 20);
  }
  struct StateT *s1_ = snippet(&s1);
  struct StateT *s2_ = snippet(&s2);
  //@ assert untainted_timer: !\tainted(s1_->timer==s2_->timer);
  koika_assert(s1_->timer==s2_->timer, "timing leak");
  return 0;
}