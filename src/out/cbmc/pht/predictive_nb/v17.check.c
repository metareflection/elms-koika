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

struct StateT * slot_12(struct StateT * v617);
struct StateT * slot_14(struct StateT * v662);
struct StateT * slot_6(struct StateT * v307);
struct StateT * slot_16(struct StateT * v1077);
struct StateT * slot_5(struct StateT * v100);
struct StateT * slot_17(struct StateT * v1101);
struct StateT * slot_2(struct StateT * v39);
struct StateT * slot_7(struct StateT * v514);
struct StateT * slot_3(struct StateT * v60);
struct StateT * snippet(struct StateT * v0);
struct StateT * slot_10(struct StateT * v573);
struct StateT * slot_1(struct StateT * v23);
struct StateT * slot_8(struct StateT * v522);
struct StateT * slot_19(struct StateT * v1165);
struct StateT * slot_4(struct StateT * v84);
struct StateT * slot_13(struct StateT * v638);
struct StateT * slot_15(struct StateT * v869);
struct StateT * slot_18(struct StateT * v1160);
struct StateT * slot_9(struct StateT * v550);
struct StateT * slot_11(struct StateT * v594);
struct StateT * slot_0(struct StateT * v2);
struct StateT * slot_12(struct StateT * v617) {
  int v618 = v617->timer;
  int v629 = v618 + 1;
  v617->timer = v629;
  int * v620 = v617->reg_ready;
  int v621 = v620[10];
  int * v622 = v617->regs;
  int v623 = v622[10];
  int v633 = (v621 + ((v618 - v621) & (~((v618 - v621) >> 31)))) + 1;
  v620[10] = v633;
  int * v625 = v617->regs;
  int v635 = (int)((unsigned int)v623 >> 26);
  v625[10] = v635;
  struct StateT * v627 = slot_13(v617);
  return v627;
}

struct StateT * slot_14(struct StateT * v662) {
  int v663 = v662->timer;
  int v775 = v663 + 1;
  v662->timer = v775;
  int * v665 = v662->reg_ready;
  int v666 = v665[10];
  int * v667 = v662->regs;
  int v668 = v667[10];
  int * v669 = v662->cache_tags;
  int v780 = (((int)((unsigned int)((int)((unsigned int)v668 >> 2)) >> 1)) & 1) * 2;
  int v670 = v669[v780];
  int v781 = ((((int)((unsigned int)((int)((unsigned int)v668 >> 2)) >> 1)) & 1) * 2) + 1;
  int v671 = v669[v781];
  int v782 = 4 + ((((int)((unsigned int)((int)((unsigned int)v668 >> 2)) >> 1)) & 3) * 2);
  int v672 = v669[v782];
  int v783 = (4 + ((((int)((unsigned int)((int)((unsigned int)v668 >> 2)) >> 1)) & 3) * 2)) + 1;
  int v673 = v669[v783];
  int * v674 = v662->cache_vals;
  bool v784 = !(((~(((v670 ^ ((int)((unsigned int)((int)((unsigned int)v668 >> 2)) >> 1))) | (-(v670 ^ ((int)((unsigned int)((int)((unsigned int)v668 >> 2)) >> 1))))) >> 31)) | (~(((v671 ^ ((int)((unsigned int)((int)((unsigned int)v668 >> 2)) >> 1))) | (-(v671 ^ ((int)((unsigned int)((int)((unsigned int)v668 >> 2)) >> 1))))) >> 31))) == 0);
  int v767;
  if (v784) {
    int * v675 = v662->cache_age;
    int v786 = ((((int)((unsigned int)((int)((unsigned int)v668 >> 2)) >> 1)) & 1) * 2) + ((~(((v671 ^ ((int)((unsigned int)((int)((unsigned int)v668 >> 2)) >> 1))) | (-(v671 ^ ((int)((unsigned int)((int)((unsigned int)v668 >> 2)) >> 1))))) >> 31)) & 1);
    int v676 = v675[v786];
    int v677 = v675[v780];
    int v787 = v677 + ((int)((unsigned int)(v677 - v676) >> 31));
    v675[v780] = v787;
    int * v679 = v662->cache_age;
    int v680 = v679[v781];
    int v789 = v680 + ((int)((unsigned int)(v680 - v676) >> 31));
    v679[v781] = v789;
    int * v682 = v662->cache_age;
    v682[v786] = 0;
    v767 = v786;
  } else {
    int * v685 = v662->cache_age;
    int v793 = (((int)((unsigned int)((int)((unsigned int)v668 >> 2)) >> 1)) & 1) * 2;
    int v686 = v685[v793];
    int * v687 = v662->cache_tags;
    int v688 = v687[v793];
    int v689 = v685[v781];
    int v690 = v687[v781];
    bool v795 = !(((~(((v672 ^ ((int)((unsigned int)((int)((unsigned int)v668 >> 2)) >> 1))) | (-(v672 ^ ((int)((unsigned int)((int)((unsigned int)v668 >> 2)) >> 1))))) >> 31)) | (~(((v673 ^ ((int)((unsigned int)((int)((unsigned int)v668 >> 2)) >> 1))) | (-(v673 ^ ((int)((unsigned int)((int)((unsigned int)v668 >> 2)) >> 1))))) >> 31))) == 0);
    int v744;
    if (v795) {
      int * v691 = v662->cache_age;
      int v797 = (4 + ((((int)((unsigned int)((int)((unsigned int)v668 >> 2)) >> 1)) & 3) * 2)) + ((~(((v673 ^ ((int)((unsigned int)((int)((unsigned int)v668 >> 2)) >> 1))) | (-(v673 ^ ((int)((unsigned int)((int)((unsigned int)v668 >> 2)) >> 1))))) >> 31)) & 1);
      int v692 = v691[v797];
      int v693 = v691[v782];
      int v798 = v693 + ((int)((unsigned int)(v693 - v692) >> 31));
      v691[v782] = v798;
      int * v695 = v662->cache_age;
      int v696 = v695[v783];
      int v800 = v696 + ((int)((unsigned int)(v696 - v692) >> 31));
      v695[v783] = v800;
      int * v698 = v662->cache_age;
      v698[v797] = 0;
      v744 = v797;
    } else {
      int * v701 = v662->cache_age;
      int v804 = 4 + ((((int)((unsigned int)((int)((unsigned int)v668 >> 2)) >> 1)) & 3) * 2);
      int v702 = v701[v804];
      int * v703 = v662->cache_tags;
      int v704 = v703[v804];
      int v705 = v701[v783];
      int v706 = v703[v783];
      int * v707 = v662->cache_dirty;
      int v807 = (4 + ((((int)((unsigned int)((int)((unsigned int)v668 >> 2)) >> 1)) & 3) * 2)) + ((((v702 + ((~(((v704 ^ -1) | (-(v704 ^ -1))) >> 31)) & 2)) - (v705 + ((~(((v706 ^ -1) | (-(v706 ^ -1))) >> 31)) & 2))) >> 31) & 1);
      int v708 = v707[v807];
      bool v808 = !(v708 == 0);
      if (v808) {
        int * v709 = v662->cache_tags;
        int v710 = v709[v807];
        int * v711 = v662->cache_vals;
        int v811 = ((4 + ((((int)((unsigned int)((int)((unsigned int)v668 >> 2)) >> 1)) & 3) * 2)) + ((((v702 + ((~(((v704 ^ -1) | (-(v704 ^ -1))) >> 31)) & 2)) - (v705 + ((~(((v706 ^ -1) | (-(v706 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
        int v712 = v711[v811];
        int v812 = (((4 + ((((int)((unsigned int)((int)((unsigned int)v668 >> 2)) >> 1)) & 3) * 2)) + ((((v702 + ((~(((v704 ^ -1) | (-(v704 ^ -1))) >> 31)) & 2)) - (v705 + ((~(((v706 ^ -1) | (-(v706 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
        int v713 = v711[v812];
        int * v714 = v662->mem;
        int v814 = v710 * 2;
        v714[v814] = v712;
        int * v716 = v662->mem;
        int v817 = (v710 * 2) + 1;
        v716[v817] = v713;
        ;
      } else {
        ;
      }
      int * v721 = v662->mem;
      int v822 = ((int)((unsigned int)((int)((unsigned int)v668 >> 2)) >> 1)) * 2;
      int v722 = v721[v822];
      int v823 = (((int)((unsigned int)((int)((unsigned int)v668 >> 2)) >> 1)) * 2) + 1;
      int v723 = v721[v823];
      int * v724 = v662->cache_vals;
      int v825 = ((4 + ((((int)((unsigned int)((int)((unsigned int)v668 >> 2)) >> 1)) & 3) * 2)) + ((((v702 + ((~(((v704 ^ -1) | (-(v704 ^ -1))) >> 31)) & 2)) - (v705 + ((~(((v706 ^ -1) | (-(v706 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
      v724[v825] = v722;
      int * v726 = v662->cache_vals;
      int v828 = (((4 + ((((int)((unsigned int)((int)((unsigned int)v668 >> 2)) >> 1)) & 3) * 2)) + ((((v702 + ((~(((v704 ^ -1) | (-(v704 ^ -1))) >> 31)) & 2)) - (v705 + ((~(((v706 ^ -1) | (-(v706 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
      v726[v828] = v723;
      int * v728 = v662->cache_tags;
      int v831 = (int)((unsigned int)((int)((unsigned int)v668 >> 2)) >> 1);
      v728[v807] = v831;
      int * v730 = v662->cache_dirty;
      v730[v807] = 0;
      int * v732 = v662->cache_age;
      v732[v807] = 1;
      int * v734 = v662->cache_age;
      int v735 = v734[v807];
      int v736 = v734[v782];
      int v837 = v736 + ((int)((unsigned int)(v736 - v735) >> 31));
      v734[v782] = v837;
      int * v738 = v662->cache_age;
      int v739 = v738[v783];
      int v839 = v739 + ((int)((unsigned int)(v739 - v735) >> 31));
      v738[v783] = v839;
      int * v741 = v662->cache_age;
      v741[v807] = 0;
      v744 = v807;
    }
    int * v745 = v662->cache_vals;
    int v842 = v744 * 2;
    int v746 = v745[v842];
    int v843 = (v744 * 2) + 1;
    int v747 = v745[v843];
    int v844 = (((((int)((unsigned int)((int)((unsigned int)v668 >> 2)) >> 1)) & 1) * 2) + ((((v686 + ((~(((v688 ^ -1) | (-(v688 ^ -1))) >> 31)) & 2)) - (v689 + ((~(((v690 ^ -1) | (-(v690 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
    v745[v844] = v746;
    int * v749 = v662->cache_vals;
    int v847 = ((((((int)((unsigned int)((int)((unsigned int)v668 >> 2)) >> 1)) & 1) * 2) + ((((v686 + ((~(((v688 ^ -1) | (-(v688 ^ -1))) >> 31)) & 2)) - (v689 + ((~(((v690 ^ -1) | (-(v690 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
    v749[v847] = v747;
    int * v751 = v662->cache_tags;
    int v850 = ((((int)((unsigned int)((int)((unsigned int)v668 >> 2)) >> 1)) & 1) * 2) + ((((v686 + ((~(((v688 ^ -1) | (-(v688 ^ -1))) >> 31)) & 2)) - (v689 + ((~(((v690 ^ -1) | (-(v690 ^ -1))) >> 31)) & 2))) >> 31) & 1);
    int v851 = (int)((unsigned int)((int)((unsigned int)v668 >> 2)) >> 1);
    v751[v850] = v851;
    int * v753 = v662->cache_dirty;
    v753[v850] = 0;
    int * v755 = v662->cache_age;
    v755[v850] = 1;
    int * v757 = v662->cache_age;
    int v758 = v757[v850];
    int v759 = v757[v780];
    int v857 = v759 + ((int)((unsigned int)(v759 - v758) >> 31));
    v757[v780] = v857;
    int * v761 = v662->cache_age;
    int v762 = v761[v781];
    int v859 = v762 + ((int)((unsigned int)(v762 - v758) >> 31));
    v761[v781] = v859;
    int * v764 = v662->cache_age;
    v764[v850] = 0;
    v767 = v850;
  }
  int v862 = (v767 * 2) + (((int)((unsigned int)v668 >> 2)) & 1);
  int v768 = v674[v862];
  int * v769 = v662->reg_ready;
  int v864 = ((v666 + ((v663 - v666) & (~((v663 - v666) >> 31)))) + 1) + ((100 ^ (((~(((v672 ^ ((int)((unsigned int)((int)((unsigned int)v668 >> 2)) >> 1))) | (-(v672 ^ ((int)((unsigned int)((int)((unsigned int)v668 >> 2)) >> 1))))) >> 31)) | (~(((v673 ^ ((int)((unsigned int)((int)((unsigned int)v668 >> 2)) >> 1))) | (-(v673 ^ ((int)((unsigned int)((int)((unsigned int)v668 >> 2)) >> 1))))) >> 31))) & 104)) ^ (((~(((v670 ^ ((int)((unsigned int)((int)((unsigned int)v668 >> 2)) >> 1))) | (-(v670 ^ ((int)((unsigned int)((int)((unsigned int)v668 >> 2)) >> 1))))) >> 31)) | (~(((v671 ^ ((int)((unsigned int)((int)((unsigned int)v668 >> 2)) >> 1))) | (-(v671 ^ ((int)((unsigned int)((int)((unsigned int)v668 >> 2)) >> 1))))) >> 31))) & (1 ^ (100 ^ (((~(((v672 ^ ((int)((unsigned int)((int)((unsigned int)v668 >> 2)) >> 1))) | (-(v672 ^ ((int)((unsigned int)((int)((unsigned int)v668 >> 2)) >> 1))))) >> 31)) | (~(((v673 ^ ((int)((unsigned int)((int)((unsigned int)v668 >> 2)) >> 1))) | (-(v673 ^ ((int)((unsigned int)((int)((unsigned int)v668 >> 2)) >> 1))))) >> 31))) & 104)))));
  v769[10] = v864;
  int * v771 = v662->regs;
  v771[10] = v768;
  struct StateT * v773 = slot_15(v662);
  return v773;
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

struct StateT * slot_16(struct StateT * v1077) {
  int v1078 = v1077->timer;
  int v1091 = v1078 + 1;
  v1077->timer = v1091;
  int * v1080 = v1077->reg_ready;
  int v1081 = v1080[11];
  int * v1082 = v1077->regs;
  int v1083 = v1082[11];
  int v1084 = v1080[10];
  int v1085 = v1082[10];
  int v1096 = (v1084 + (((v1081 + ((v1078 - v1081) & (~((v1078 - v1081) >> 31)))) - v1084) & (~(((v1081 + ((v1078 - v1081) & (~((v1078 - v1081) >> 31)))) - v1084) >> 31)))) + 1;
  v1080[10] = v1096;
  int * v1087 = v1077->regs;
  int v1098 = v1083 & v1085;
  v1087[10] = v1098;
  struct StateT * v1089 = slot_17(v1077);
  return v1089;
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

struct StateT * slot_17(struct StateT * v1101) {
  int * v1102 = v1101->saved_regs;
  int v1103 = v1102[10];
  int v1104 = v1102[11];
  bool v1137 = (v1103 ^ -2147483648) >= (v1104 ^ -2147483648);
  struct StateT * v1132;
  if (v1137) {
    int v1105 = v1101->timer;
    int v1138 = v1105 + 15;
    v1101->timer = v1138;
    int * v1107 = v1101->saved_regs;
    int v1108 = v1107[10];
    int * v1109 = v1101->regs;
    v1109[10] = v1108;
    int * v1111 = v1101->saved_regs;
    int v1112 = v1111[11];
    int * v1113 = v1101->regs;
    v1113[11] = v1112;
    int * v1115 = v1101->saved_regs;
    int v1116 = v1115[12];
    int * v1117 = v1101->regs;
    v1117[12] = v1116;
    int * v1119 = v1101->reg_ready;
    int v1120 = v1101->timer;
    v1119[10] = v1120;
    int * v1122 = v1101->reg_ready;
    int v1123 = v1101->timer;
    v1122[11] = v1123;
    int * v1125 = v1101->reg_ready;
    int v1126 = v1101->timer;
    v1125[12] = v1126;
    struct StateT * v1128 = slot_18(v1101);
    v1132 = v1128;
  } else {
    struct StateT * v1130 = slot_19(v1101);
    v1132 = v1130;
  }
  return v1132;
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
  int v519 = v515 + 1;
  v514->timer = v519;
  struct StateT * v517 = slot_8(v514);
  return v517;
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
  int v1484 = v1->timer;
  int * v1485 = v1->reg_ready;
  int v1486 = v1485[0];
  int v1617 = v1486 + ((v1484 - v1486) & (~((v1484 - v1486) >> 31)));
  v1->timer = v1617;
  int v1488 = v1->timer;
  int * v1489 = v1->reg_ready;
  int v1490 = v1489[1];
  int v1620 = v1490 + ((v1488 - v1490) & (~((v1488 - v1490) >> 31)));
  v1->timer = v1620;
  int v1492 = v1->timer;
  int * v1493 = v1->reg_ready;
  int v1494 = v1493[2];
  int v1623 = v1494 + ((v1492 - v1494) & (~((v1492 - v1494) >> 31)));
  v1->timer = v1623;
  int v1496 = v1->timer;
  int * v1497 = v1->reg_ready;
  int v1498 = v1497[3];
  int v1626 = v1498 + ((v1496 - v1498) & (~((v1496 - v1498) >> 31)));
  v1->timer = v1626;
  int v1500 = v1->timer;
  int * v1501 = v1->reg_ready;
  int v1502 = v1501[4];
  int v1629 = v1502 + ((v1500 - v1502) & (~((v1500 - v1502) >> 31)));
  v1->timer = v1629;
  int v1504 = v1->timer;
  int * v1505 = v1->reg_ready;
  int v1506 = v1505[5];
  int v1632 = v1506 + ((v1504 - v1506) & (~((v1504 - v1506) >> 31)));
  v1->timer = v1632;
  int v1508 = v1->timer;
  int * v1509 = v1->reg_ready;
  int v1510 = v1509[6];
  int v1635 = v1510 + ((v1508 - v1510) & (~((v1508 - v1510) >> 31)));
  v1->timer = v1635;
  int v1512 = v1->timer;
  int * v1513 = v1->reg_ready;
  int v1514 = v1513[7];
  int v1638 = v1514 + ((v1512 - v1514) & (~((v1512 - v1514) >> 31)));
  v1->timer = v1638;
  int v1516 = v1->timer;
  int * v1517 = v1->reg_ready;
  int v1518 = v1517[8];
  int v1641 = v1518 + ((v1516 - v1518) & (~((v1516 - v1518) >> 31)));
  v1->timer = v1641;
  int v1520 = v1->timer;
  int * v1521 = v1->reg_ready;
  int v1522 = v1521[9];
  int v1644 = v1522 + ((v1520 - v1522) & (~((v1520 - v1522) >> 31)));
  v1->timer = v1644;
  int v1524 = v1->timer;
  int * v1525 = v1->reg_ready;
  int v1526 = v1525[10];
  int v1647 = v1526 + ((v1524 - v1526) & (~((v1524 - v1526) >> 31)));
  v1->timer = v1647;
  int v1528 = v1->timer;
  int * v1529 = v1->reg_ready;
  int v1530 = v1529[11];
  int v1650 = v1530 + ((v1528 - v1530) & (~((v1528 - v1530) >> 31)));
  v1->timer = v1650;
  int v1532 = v1->timer;
  int * v1533 = v1->reg_ready;
  int v1534 = v1533[12];
  int v1653 = v1534 + ((v1532 - v1534) & (~((v1532 - v1534) >> 31)));
  v1->timer = v1653;
  int v1536 = v1->timer;
  int * v1537 = v1->reg_ready;
  int v1538 = v1537[13];
  int v1656 = v1538 + ((v1536 - v1538) & (~((v1536 - v1538) >> 31)));
  v1->timer = v1656;
  int v1540 = v1->timer;
  int * v1541 = v1->reg_ready;
  int v1542 = v1541[14];
  int v1659 = v1542 + ((v1540 - v1542) & (~((v1540 - v1542) >> 31)));
  v1->timer = v1659;
  int v1544 = v1->timer;
  int * v1545 = v1->reg_ready;
  int v1546 = v1545[15];
  int v1662 = v1546 + ((v1544 - v1546) & (~((v1544 - v1546) >> 31)));
  v1->timer = v1662;
  int v1548 = v1->timer;
  int * v1549 = v1->reg_ready;
  int v1550 = v1549[16];
  int v1665 = v1550 + ((v1548 - v1550) & (~((v1548 - v1550) >> 31)));
  v1->timer = v1665;
  int v1552 = v1->timer;
  int * v1553 = v1->reg_ready;
  int v1554 = v1553[17];
  int v1668 = v1554 + ((v1552 - v1554) & (~((v1552 - v1554) >> 31)));
  v1->timer = v1668;
  int v1556 = v1->timer;
  int * v1557 = v1->reg_ready;
  int v1558 = v1557[18];
  int v1671 = v1558 + ((v1556 - v1558) & (~((v1556 - v1558) >> 31)));
  v1->timer = v1671;
  int v1560 = v1->timer;
  int * v1561 = v1->reg_ready;
  int v1562 = v1561[19];
  int v1674 = v1562 + ((v1560 - v1562) & (~((v1560 - v1562) >> 31)));
  v1->timer = v1674;
  int v1564 = v1->timer;
  int * v1565 = v1->reg_ready;
  int v1566 = v1565[20];
  int v1677 = v1566 + ((v1564 - v1566) & (~((v1564 - v1566) >> 31)));
  v1->timer = v1677;
  int v1568 = v1->timer;
  int * v1569 = v1->reg_ready;
  int v1570 = v1569[21];
  int v1680 = v1570 + ((v1568 - v1570) & (~((v1568 - v1570) >> 31)));
  v1->timer = v1680;
  int v1572 = v1->timer;
  int * v1573 = v1->reg_ready;
  int v1574 = v1573[22];
  int v1683 = v1574 + ((v1572 - v1574) & (~((v1572 - v1574) >> 31)));
  v1->timer = v1683;
  int v1576 = v1->timer;
  int * v1577 = v1->reg_ready;
  int v1578 = v1577[23];
  int v1686 = v1578 + ((v1576 - v1578) & (~((v1576 - v1578) >> 31)));
  v1->timer = v1686;
  int v1580 = v1->timer;
  int * v1581 = v1->reg_ready;
  int v1582 = v1581[24];
  int v1689 = v1582 + ((v1580 - v1582) & (~((v1580 - v1582) >> 31)));
  v1->timer = v1689;
  int v1584 = v1->timer;
  int * v1585 = v1->reg_ready;
  int v1586 = v1585[25];
  int v1692 = v1586 + ((v1584 - v1586) & (~((v1584 - v1586) >> 31)));
  v1->timer = v1692;
  int v1588 = v1->timer;
  int * v1589 = v1->reg_ready;
  int v1590 = v1589[26];
  int v1695 = v1590 + ((v1588 - v1590) & (~((v1588 - v1590) >> 31)));
  v1->timer = v1695;
  int v1592 = v1->timer;
  int * v1593 = v1->reg_ready;
  int v1594 = v1593[27];
  int v1698 = v1594 + ((v1592 - v1594) & (~((v1592 - v1594) >> 31)));
  v1->timer = v1698;
  int v1596 = v1->timer;
  int * v1597 = v1->reg_ready;
  int v1598 = v1597[28];
  int v1701 = v1598 + ((v1596 - v1598) & (~((v1596 - v1598) >> 31)));
  v1->timer = v1701;
  int v1600 = v1->timer;
  int * v1601 = v1->reg_ready;
  int v1602 = v1601[29];
  int v1704 = v1602 + ((v1600 - v1602) & (~((v1600 - v1602) >> 31)));
  v1->timer = v1704;
  int v1604 = v1->timer;
  int * v1605 = v1->reg_ready;
  int v1606 = v1605[30];
  int v1707 = v1606 + ((v1604 - v1606) & (~((v1604 - v1606) >> 31)));
  v1->timer = v1707;
  int v1608 = v1->timer;
  int * v1609 = v1->reg_ready;
  int v1610 = v1609[31];
  int v1710 = v1610 + ((v1608 - v1610) & (~((v1608 - v1610) >> 31)));
  v1->timer = v1710;
  return v1;
}

struct StateT * slot_10(struct StateT * v573) {
  int v574 = v573->timer;
  int v585 = v574 + 1;
  v573->timer = v585;
  int * v576 = v573->reg_ready;
  int v577 = v576[11];
  int * v578 = v573->regs;
  int v579 = v578[11];
  int v589 = (v577 + ((v574 - v577) & (~((v574 - v577) >> 31)))) + 1;
  v576[11] = v589;
  int * v581 = v573->regs;
  int v591 = v579 + 4;
  v581[11] = v591;
  struct StateT * v583 = slot_11(v573);
  return v583;
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

struct StateT * slot_8(struct StateT * v522) {
  int * v523 = v522->saved_regs;
  int * v524 = v522->regs;
  int v525 = v524[10];
  v523[10] = v525;
  int v527 = v522->timer;
  int v542 = v527 + 1;
  v522->timer = v542;
  int * v529 = v522->reg_ready;
  int v530 = v529[10];
  int * v531 = v522->regs;
  int v532 = v531[10];
  int v545 = (v530 + ((v527 - v530) & (~((v527 - v530) >> 31)))) + 1;
  v529[10] = v545;
  int * v534 = v522->regs;
  int v547 = v532 << 29;
  v534[10] = v547;
  struct StateT * v536 = slot_9(v522);
  return v536;
}

struct StateT * slot_19(struct StateT * v1165) {
  int v1166 = v1165->timer;
  int v1339 = v1166 + 1;
  v1165->timer = v1339;
  int * v1168 = v1165->reg_ready;
  int * v1170 = v1165->regs;
  int v1171 = v1170[12];
  int v1173 = v1170[10];
  int * v1174 = v1165->cache_tags;
  int v1345 = (((int)((unsigned int)((int)((unsigned int)(v1171 + 68) >> 2)) >> 1)) & 1) * 2;
  int v1175 = v1174[v1345];
  int v1346 = ((((int)((unsigned int)((int)((unsigned int)(v1171 + 68) >> 2)) >> 1)) & 1) * 2) + 1;
  int v1176 = v1174[v1346];
  int v1347 = 4 + ((((int)((unsigned int)((int)((unsigned int)(v1171 + 68) >> 2)) >> 1)) & 3) * 2);
  int v1177 = v1174[v1347];
  int v1348 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v1171 + 68) >> 2)) >> 1)) & 3) * 2)) + 1;
  int v1178 = v1174[v1348];
  int v1179 = v1165->timer;
  int v1349 = v1179 + ((100 ^ (((~(((v1177 ^ ((int)((unsigned int)((int)((unsigned int)(v1171 + 68) >> 2)) >> 1))) | (-(v1177 ^ ((int)((unsigned int)((int)((unsigned int)(v1171 + 68) >> 2)) >> 1))))) >> 31)) | (~(((v1178 ^ ((int)((unsigned int)((int)((unsigned int)(v1171 + 68) >> 2)) >> 1))) | (-(v1178 ^ ((int)((unsigned int)((int)((unsigned int)(v1171 + 68) >> 2)) >> 1))))) >> 31))) & 104)) ^ (((~(((v1175 ^ ((int)((unsigned int)((int)((unsigned int)(v1171 + 68) >> 2)) >> 1))) | (-(v1175 ^ ((int)((unsigned int)((int)((unsigned int)(v1171 + 68) >> 2)) >> 1))))) >> 31)) | (~(((v1176 ^ ((int)((unsigned int)((int)((unsigned int)(v1171 + 68) >> 2)) >> 1))) | (-(v1176 ^ ((int)((unsigned int)((int)((unsigned int)(v1171 + 68) >> 2)) >> 1))))) >> 31))) & (1 ^ (100 ^ (((~(((v1177 ^ ((int)((unsigned int)((int)((unsigned int)(v1171 + 68) >> 2)) >> 1))) | (-(v1177 ^ ((int)((unsigned int)((int)((unsigned int)(v1171 + 68) >> 2)) >> 1))))) >> 31)) | (~(((v1178 ^ ((int)((unsigned int)((int)((unsigned int)(v1171 + 68) >> 2)) >> 1))) | (-(v1178 ^ ((int)((unsigned int)((int)((unsigned int)(v1171 + 68) >> 2)) >> 1))))) >> 31))) & 104)))));
  v1165->timer = v1349;
  bool v1350 = !(((~(((v1175 ^ ((int)((unsigned int)((int)((unsigned int)(v1171 + 68) >> 2)) >> 1))) | (-(v1175 ^ ((int)((unsigned int)((int)((unsigned int)(v1171 + 68) >> 2)) >> 1))))) >> 31)) | (~(((v1176 ^ ((int)((unsigned int)((int)((unsigned int)(v1171 + 68) >> 2)) >> 1))) | (-(v1176 ^ ((int)((unsigned int)((int)((unsigned int)(v1171 + 68) >> 2)) >> 1))))) >> 31))) == 0);
  int v1273;
  if (v1350) {
    int * v1181 = v1165->cache_age;
    int v1352 = ((((int)((unsigned int)((int)((unsigned int)(v1171 + 68) >> 2)) >> 1)) & 1) * 2) + ((~(((v1176 ^ ((int)((unsigned int)((int)((unsigned int)(v1171 + 68) >> 2)) >> 1))) | (-(v1176 ^ ((int)((unsigned int)((int)((unsigned int)(v1171 + 68) >> 2)) >> 1))))) >> 31)) & 1);
    int v1182 = v1181[v1352];
    int v1183 = v1181[v1345];
    int v1353 = v1183 + ((int)((unsigned int)(v1183 - v1182) >> 31));
    v1181[v1345] = v1353;
    int * v1185 = v1165->cache_age;
    int v1186 = v1185[v1346];
    int v1355 = v1186 + ((int)((unsigned int)(v1186 - v1182) >> 31));
    v1185[v1346] = v1355;
    int * v1188 = v1165->cache_age;
    v1188[v1352] = 0;
    v1273 = v1352;
  } else {
    int * v1191 = v1165->cache_age;
    int v1359 = (((int)((unsigned int)((int)((unsigned int)(v1171 + 68) >> 2)) >> 1)) & 1) * 2;
    int v1192 = v1191[v1359];
    int * v1193 = v1165->cache_tags;
    int v1194 = v1193[v1359];
    int v1195 = v1191[v1346];
    int v1196 = v1193[v1346];
    bool v1361 = !(((~(((v1177 ^ ((int)((unsigned int)((int)((unsigned int)(v1171 + 68) >> 2)) >> 1))) | (-(v1177 ^ ((int)((unsigned int)((int)((unsigned int)(v1171 + 68) >> 2)) >> 1))))) >> 31)) | (~(((v1178 ^ ((int)((unsigned int)((int)((unsigned int)(v1171 + 68) >> 2)) >> 1))) | (-(v1178 ^ ((int)((unsigned int)((int)((unsigned int)(v1171 + 68) >> 2)) >> 1))))) >> 31))) == 0);
    int v1250;
    if (v1361) {
      int * v1197 = v1165->cache_age;
      int v1363 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v1171 + 68) >> 2)) >> 1)) & 3) * 2)) + ((~(((v1178 ^ ((int)((unsigned int)((int)((unsigned int)(v1171 + 68) >> 2)) >> 1))) | (-(v1178 ^ ((int)((unsigned int)((int)((unsigned int)(v1171 + 68) >> 2)) >> 1))))) >> 31)) & 1);
      int v1198 = v1197[v1363];
      int v1199 = v1197[v1347];
      int v1364 = v1199 + ((int)((unsigned int)(v1199 - v1198) >> 31));
      v1197[v1347] = v1364;
      int * v1201 = v1165->cache_age;
      int v1202 = v1201[v1348];
      int v1366 = v1202 + ((int)((unsigned int)(v1202 - v1198) >> 31));
      v1201[v1348] = v1366;
      int * v1204 = v1165->cache_age;
      v1204[v1363] = 0;
      v1250 = v1363;
    } else {
      int * v1207 = v1165->cache_age;
      int v1370 = 4 + ((((int)((unsigned int)((int)((unsigned int)(v1171 + 68) >> 2)) >> 1)) & 3) * 2);
      int v1208 = v1207[v1370];
      int * v1209 = v1165->cache_tags;
      int v1210 = v1209[v1370];
      int v1211 = v1207[v1348];
      int v1212 = v1209[v1348];
      int * v1213 = v1165->cache_dirty;
      int v1373 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v1171 + 68) >> 2)) >> 1)) & 3) * 2)) + ((((v1208 + ((~(((v1210 ^ -1) | (-(v1210 ^ -1))) >> 31)) & 2)) - (v1211 + ((~(((v1212 ^ -1) | (-(v1212 ^ -1))) >> 31)) & 2))) >> 31) & 1);
      int v1214 = v1213[v1373];
      bool v1374 = !(v1214 == 0);
      if (v1374) {
        int * v1215 = v1165->cache_tags;
        int v1216 = v1215[v1373];
        int * v1217 = v1165->cache_vals;
        int v1377 = ((4 + ((((int)((unsigned int)((int)((unsigned int)(v1171 + 68) >> 2)) >> 1)) & 3) * 2)) + ((((v1208 + ((~(((v1210 ^ -1) | (-(v1210 ^ -1))) >> 31)) & 2)) - (v1211 + ((~(((v1212 ^ -1) | (-(v1212 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
        int v1218 = v1217[v1377];
        int v1378 = (((4 + ((((int)((unsigned int)((int)((unsigned int)(v1171 + 68) >> 2)) >> 1)) & 3) * 2)) + ((((v1208 + ((~(((v1210 ^ -1) | (-(v1210 ^ -1))) >> 31)) & 2)) - (v1211 + ((~(((v1212 ^ -1) | (-(v1212 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
        int v1219 = v1217[v1378];
        int * v1220 = v1165->mem;
        int v1380 = v1216 * 2;
        v1220[v1380] = v1218;
        int * v1222 = v1165->mem;
        int v1383 = (v1216 * 2) + 1;
        v1222[v1383] = v1219;
        ;
      } else {
        ;
      }
      int * v1227 = v1165->mem;
      int v1388 = ((int)((unsigned int)((int)((unsigned int)(v1171 + 68) >> 2)) >> 1)) * 2;
      int v1228 = v1227[v1388];
      int v1389 = (((int)((unsigned int)((int)((unsigned int)(v1171 + 68) >> 2)) >> 1)) * 2) + 1;
      int v1229 = v1227[v1389];
      int * v1230 = v1165->cache_vals;
      int v1391 = ((4 + ((((int)((unsigned int)((int)((unsigned int)(v1171 + 68) >> 2)) >> 1)) & 3) * 2)) + ((((v1208 + ((~(((v1210 ^ -1) | (-(v1210 ^ -1))) >> 31)) & 2)) - (v1211 + ((~(((v1212 ^ -1) | (-(v1212 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
      v1230[v1391] = v1228;
      int * v1232 = v1165->cache_vals;
      int v1394 = (((4 + ((((int)((unsigned int)((int)((unsigned int)(v1171 + 68) >> 2)) >> 1)) & 3) * 2)) + ((((v1208 + ((~(((v1210 ^ -1) | (-(v1210 ^ -1))) >> 31)) & 2)) - (v1211 + ((~(((v1212 ^ -1) | (-(v1212 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
      v1232[v1394] = v1229;
      int * v1234 = v1165->cache_tags;
      int v1397 = (int)((unsigned int)((int)((unsigned int)(v1171 + 68) >> 2)) >> 1);
      v1234[v1373] = v1397;
      int * v1236 = v1165->cache_dirty;
      v1236[v1373] = 0;
      int * v1238 = v1165->cache_age;
      v1238[v1373] = 1;
      int * v1240 = v1165->cache_age;
      int v1241 = v1240[v1373];
      int v1242 = v1240[v1347];
      int v1403 = v1242 + ((int)((unsigned int)(v1242 - v1241) >> 31));
      v1240[v1347] = v1403;
      int * v1244 = v1165->cache_age;
      int v1245 = v1244[v1348];
      int v1405 = v1245 + ((int)((unsigned int)(v1245 - v1241) >> 31));
      v1244[v1348] = v1405;
      int * v1247 = v1165->cache_age;
      v1247[v1373] = 0;
      v1250 = v1373;
    }
    int * v1251 = v1165->cache_vals;
    int v1408 = v1250 * 2;
    int v1252 = v1251[v1408];
    int v1409 = (v1250 * 2) + 1;
    int v1253 = v1251[v1409];
    int v1410 = (((((int)((unsigned int)((int)((unsigned int)(v1171 + 68) >> 2)) >> 1)) & 1) * 2) + ((((v1192 + ((~(((v1194 ^ -1) | (-(v1194 ^ -1))) >> 31)) & 2)) - (v1195 + ((~(((v1196 ^ -1) | (-(v1196 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
    v1251[v1410] = v1252;
    int * v1255 = v1165->cache_vals;
    int v1413 = ((((((int)((unsigned int)((int)((unsigned int)(v1171 + 68) >> 2)) >> 1)) & 1) * 2) + ((((v1192 + ((~(((v1194 ^ -1) | (-(v1194 ^ -1))) >> 31)) & 2)) - (v1195 + ((~(((v1196 ^ -1) | (-(v1196 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
    v1255[v1413] = v1253;
    int * v1257 = v1165->cache_tags;
    int v1416 = ((((int)((unsigned int)((int)((unsigned int)(v1171 + 68) >> 2)) >> 1)) & 1) * 2) + ((((v1192 + ((~(((v1194 ^ -1) | (-(v1194 ^ -1))) >> 31)) & 2)) - (v1195 + ((~(((v1196 ^ -1) | (-(v1196 ^ -1))) >> 31)) & 2))) >> 31) & 1);
    int v1417 = (int)((unsigned int)((int)((unsigned int)(v1171 + 68) >> 2)) >> 1);
    v1257[v1416] = v1417;
    int * v1259 = v1165->cache_dirty;
    v1259[v1416] = 0;
    int * v1261 = v1165->cache_age;
    v1261[v1416] = 1;
    int * v1263 = v1165->cache_age;
    int v1264 = v1263[v1416];
    int v1265 = v1263[v1345];
    int v1423 = v1265 + ((int)((unsigned int)(v1265 - v1264) >> 31));
    v1263[v1345] = v1423;
    int * v1267 = v1165->cache_age;
    int v1268 = v1267[v1346];
    int v1425 = v1268 + ((int)((unsigned int)(v1268 - v1264) >> 31));
    v1267[v1346] = v1425;
    int * v1270 = v1165->cache_age;
    v1270[v1416] = 0;
    v1273 = v1416;
  }
  int * v1274 = v1165->cache_vals;
  int v1428 = (v1273 * 2) + (((int)((unsigned int)(v1171 + 68) >> 2)) & 1);
  v1274[v1428] = v1173;
  int * v1276 = v1165->cache_tags;
  int v1277 = v1276[v1347];
  int v1278 = v1276[v1348];
  bool v1431 = !(((~(((v1277 ^ ((int)((unsigned int)((int)((unsigned int)(v1171 + 68) >> 2)) >> 1))) | (-(v1277 ^ ((int)((unsigned int)((int)((unsigned int)(v1171 + 68) >> 2)) >> 1))))) >> 31)) | (~(((v1278 ^ ((int)((unsigned int)((int)((unsigned int)(v1171 + 68) >> 2)) >> 1))) | (-(v1278 ^ ((int)((unsigned int)((int)((unsigned int)(v1171 + 68) >> 2)) >> 1))))) >> 31))) == 0);
  int v1332;
  if (v1431) {
    int * v1279 = v1165->cache_age;
    int v1433 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v1171 + 68) >> 2)) >> 1)) & 3) * 2)) + ((~(((v1278 ^ ((int)((unsigned int)((int)((unsigned int)(v1171 + 68) >> 2)) >> 1))) | (-(v1278 ^ ((int)((unsigned int)((int)((unsigned int)(v1171 + 68) >> 2)) >> 1))))) >> 31)) & 1);
    int v1280 = v1279[v1433];
    int v1281 = v1279[v1347];
    int v1434 = v1281 + ((int)((unsigned int)(v1281 - v1280) >> 31));
    v1279[v1347] = v1434;
    int * v1283 = v1165->cache_age;
    int v1284 = v1283[v1348];
    int v1436 = v1284 + ((int)((unsigned int)(v1284 - v1280) >> 31));
    v1283[v1348] = v1436;
    int * v1286 = v1165->cache_age;
    v1286[v1433] = 0;
    v1332 = v1433;
  } else {
    int * v1289 = v1165->cache_age;
    int v1440 = 4 + ((((int)((unsigned int)((int)((unsigned int)(v1171 + 68) >> 2)) >> 1)) & 3) * 2);
    int v1290 = v1289[v1440];
    int * v1291 = v1165->cache_tags;
    int v1292 = v1291[v1440];
    int v1293 = v1289[v1348];
    int v1294 = v1291[v1348];
    int * v1295 = v1165->cache_dirty;
    int v1443 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v1171 + 68) >> 2)) >> 1)) & 3) * 2)) + ((((v1290 + ((~(((v1292 ^ -1) | (-(v1292 ^ -1))) >> 31)) & 2)) - (v1293 + ((~(((v1294 ^ -1) | (-(v1294 ^ -1))) >> 31)) & 2))) >> 31) & 1);
    int v1296 = v1295[v1443];
    bool v1444 = !(v1296 == 0);
    if (v1444) {
      int * v1297 = v1165->cache_tags;
      int v1298 = v1297[v1443];
      int * v1299 = v1165->cache_vals;
      int v1447 = ((4 + ((((int)((unsigned int)((int)((unsigned int)(v1171 + 68) >> 2)) >> 1)) & 3) * 2)) + ((((v1290 + ((~(((v1292 ^ -1) | (-(v1292 ^ -1))) >> 31)) & 2)) - (v1293 + ((~(((v1294 ^ -1) | (-(v1294 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
      int v1300 = v1299[v1447];
      int v1448 = (((4 + ((((int)((unsigned int)((int)((unsigned int)(v1171 + 68) >> 2)) >> 1)) & 3) * 2)) + ((((v1290 + ((~(((v1292 ^ -1) | (-(v1292 ^ -1))) >> 31)) & 2)) - (v1293 + ((~(((v1294 ^ -1) | (-(v1294 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
      int v1301 = v1299[v1448];
      int * v1302 = v1165->mem;
      int v1450 = v1298 * 2;
      v1302[v1450] = v1300;
      int * v1304 = v1165->mem;
      int v1453 = (v1298 * 2) + 1;
      v1304[v1453] = v1301;
      ;
    } else {
      ;
    }
    int * v1309 = v1165->mem;
    int v1458 = ((int)((unsigned int)((int)((unsigned int)(v1171 + 68) >> 2)) >> 1)) * 2;
    int v1310 = v1309[v1458];
    int v1459 = (((int)((unsigned int)((int)((unsigned int)(v1171 + 68) >> 2)) >> 1)) * 2) + 1;
    int v1311 = v1309[v1459];
    int * v1312 = v1165->cache_vals;
    int v1461 = ((4 + ((((int)((unsigned int)((int)((unsigned int)(v1171 + 68) >> 2)) >> 1)) & 3) * 2)) + ((((v1290 + ((~(((v1292 ^ -1) | (-(v1292 ^ -1))) >> 31)) & 2)) - (v1293 + ((~(((v1294 ^ -1) | (-(v1294 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
    v1312[v1461] = v1310;
    int * v1314 = v1165->cache_vals;
    int v1464 = (((4 + ((((int)((unsigned int)((int)((unsigned int)(v1171 + 68) >> 2)) >> 1)) & 3) * 2)) + ((((v1290 + ((~(((v1292 ^ -1) | (-(v1292 ^ -1))) >> 31)) & 2)) - (v1293 + ((~(((v1294 ^ -1) | (-(v1294 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
    v1314[v1464] = v1311;
    int * v1316 = v1165->cache_tags;
    int v1467 = (int)((unsigned int)((int)((unsigned int)(v1171 + 68) >> 2)) >> 1);
    v1316[v1443] = v1467;
    int * v1318 = v1165->cache_dirty;
    v1318[v1443] = 0;
    int * v1320 = v1165->cache_age;
    v1320[v1443] = 1;
    int * v1322 = v1165->cache_age;
    int v1323 = v1322[v1443];
    int v1324 = v1322[v1347];
    int v1473 = v1324 + ((int)((unsigned int)(v1324 - v1323) >> 31));
    v1322[v1347] = v1473;
    int * v1326 = v1165->cache_age;
    int v1327 = v1326[v1348];
    int v1475 = v1327 + ((int)((unsigned int)(v1327 - v1323) >> 31));
    v1326[v1348] = v1475;
    int * v1329 = v1165->cache_age;
    v1329[v1443] = 0;
    v1332 = v1443;
  }
  int * v1333 = v1165->cache_vals;
  int v1478 = (v1332 * 2) + (((int)((unsigned int)(v1171 + 68) >> 2)) & 1);
  v1333[v1478] = v1173;
  int * v1335 = v1165->cache_dirty;
  v1335[v1332] = 1;
  struct StateT * v1337 = slot_18(v1165);
  return v1337;
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

struct StateT * slot_13(struct StateT * v638) {
  int v639 = v638->timer;
  int v652 = v639 + 1;
  v638->timer = v652;
  int * v641 = v638->reg_ready;
  int v642 = v641[11];
  int * v643 = v638->regs;
  int v644 = v643[11];
  int v645 = v641[10];
  int v646 = v643[10];
  int v657 = (v645 + (((v642 + ((v639 - v642) & (~((v639 - v642) >> 31)))) - v645) & (~(((v642 + ((v639 - v642) & (~((v639 - v642) >> 31)))) - v645) >> 31)))) + 1;
  v641[10] = v657;
  int * v648 = v638->regs;
  int v659 = v644 + v646;
  v648[10] = v659;
  struct StateT * v650 = slot_14(v638);
  return v650;
}

struct StateT * slot_15(struct StateT * v869) {
  int v870 = v869->timer;
  int v982 = v870 + 1;
  v869->timer = v982;
  int * v872 = v869->reg_ready;
  int v873 = v872[12];
  int * v874 = v869->regs;
  int v875 = v874[12];
  int * v876 = v869->cache_tags;
  int v987 = (((int)((unsigned int)((int)((unsigned int)(v875 + 68) >> 2)) >> 1)) & 1) * 2;
  int v877 = v876[v987];
  int v988 = ((((int)((unsigned int)((int)((unsigned int)(v875 + 68) >> 2)) >> 1)) & 1) * 2) + 1;
  int v878 = v876[v988];
  int v989 = 4 + ((((int)((unsigned int)((int)((unsigned int)(v875 + 68) >> 2)) >> 1)) & 3) * 2);
  int v879 = v876[v989];
  int v990 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v875 + 68) >> 2)) >> 1)) & 3) * 2)) + 1;
  int v880 = v876[v990];
  int * v881 = v869->cache_vals;
  bool v991 = !(((~(((v877 ^ ((int)((unsigned int)((int)((unsigned int)(v875 + 68) >> 2)) >> 1))) | (-(v877 ^ ((int)((unsigned int)((int)((unsigned int)(v875 + 68) >> 2)) >> 1))))) >> 31)) | (~(((v878 ^ ((int)((unsigned int)((int)((unsigned int)(v875 + 68) >> 2)) >> 1))) | (-(v878 ^ ((int)((unsigned int)((int)((unsigned int)(v875 + 68) >> 2)) >> 1))))) >> 31))) == 0);
  int v974;
  if (v991) {
    int * v882 = v869->cache_age;
    int v993 = ((((int)((unsigned int)((int)((unsigned int)(v875 + 68) >> 2)) >> 1)) & 1) * 2) + ((~(((v878 ^ ((int)((unsigned int)((int)((unsigned int)(v875 + 68) >> 2)) >> 1))) | (-(v878 ^ ((int)((unsigned int)((int)((unsigned int)(v875 + 68) >> 2)) >> 1))))) >> 31)) & 1);
    int v883 = v882[v993];
    int v884 = v882[v987];
    int v994 = v884 + ((int)((unsigned int)(v884 - v883) >> 31));
    v882[v987] = v994;
    int * v886 = v869->cache_age;
    int v887 = v886[v988];
    int v996 = v887 + ((int)((unsigned int)(v887 - v883) >> 31));
    v886[v988] = v996;
    int * v889 = v869->cache_age;
    v889[v993] = 0;
    v974 = v993;
  } else {
    int * v892 = v869->cache_age;
    int v1000 = (((int)((unsigned int)((int)((unsigned int)(v875 + 68) >> 2)) >> 1)) & 1) * 2;
    int v893 = v892[v1000];
    int * v894 = v869->cache_tags;
    int v895 = v894[v1000];
    int v896 = v892[v988];
    int v897 = v894[v988];
    bool v1002 = !(((~(((v879 ^ ((int)((unsigned int)((int)((unsigned int)(v875 + 68) >> 2)) >> 1))) | (-(v879 ^ ((int)((unsigned int)((int)((unsigned int)(v875 + 68) >> 2)) >> 1))))) >> 31)) | (~(((v880 ^ ((int)((unsigned int)((int)((unsigned int)(v875 + 68) >> 2)) >> 1))) | (-(v880 ^ ((int)((unsigned int)((int)((unsigned int)(v875 + 68) >> 2)) >> 1))))) >> 31))) == 0);
    int v951;
    if (v1002) {
      int * v898 = v869->cache_age;
      int v1004 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v875 + 68) >> 2)) >> 1)) & 3) * 2)) + ((~(((v880 ^ ((int)((unsigned int)((int)((unsigned int)(v875 + 68) >> 2)) >> 1))) | (-(v880 ^ ((int)((unsigned int)((int)((unsigned int)(v875 + 68) >> 2)) >> 1))))) >> 31)) & 1);
      int v899 = v898[v1004];
      int v900 = v898[v989];
      int v1005 = v900 + ((int)((unsigned int)(v900 - v899) >> 31));
      v898[v989] = v1005;
      int * v902 = v869->cache_age;
      int v903 = v902[v990];
      int v1007 = v903 + ((int)((unsigned int)(v903 - v899) >> 31));
      v902[v990] = v1007;
      int * v905 = v869->cache_age;
      v905[v1004] = 0;
      v951 = v1004;
    } else {
      int * v908 = v869->cache_age;
      int v1011 = 4 + ((((int)((unsigned int)((int)((unsigned int)(v875 + 68) >> 2)) >> 1)) & 3) * 2);
      int v909 = v908[v1011];
      int * v910 = v869->cache_tags;
      int v911 = v910[v1011];
      int v912 = v908[v990];
      int v913 = v910[v990];
      int * v914 = v869->cache_dirty;
      int v1014 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v875 + 68) >> 2)) >> 1)) & 3) * 2)) + ((((v909 + ((~(((v911 ^ -1) | (-(v911 ^ -1))) >> 31)) & 2)) - (v912 + ((~(((v913 ^ -1) | (-(v913 ^ -1))) >> 31)) & 2))) >> 31) & 1);
      int v915 = v914[v1014];
      bool v1015 = !(v915 == 0);
      if (v1015) {
        int * v916 = v869->cache_tags;
        int v917 = v916[v1014];
        int * v918 = v869->cache_vals;
        int v1018 = ((4 + ((((int)((unsigned int)((int)((unsigned int)(v875 + 68) >> 2)) >> 1)) & 3) * 2)) + ((((v909 + ((~(((v911 ^ -1) | (-(v911 ^ -1))) >> 31)) & 2)) - (v912 + ((~(((v913 ^ -1) | (-(v913 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
        int v919 = v918[v1018];
        int v1019 = (((4 + ((((int)((unsigned int)((int)((unsigned int)(v875 + 68) >> 2)) >> 1)) & 3) * 2)) + ((((v909 + ((~(((v911 ^ -1) | (-(v911 ^ -1))) >> 31)) & 2)) - (v912 + ((~(((v913 ^ -1) | (-(v913 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
        int v920 = v918[v1019];
        int * v921 = v869->mem;
        int v1021 = v917 * 2;
        v921[v1021] = v919;
        int * v923 = v869->mem;
        int v1024 = (v917 * 2) + 1;
        v923[v1024] = v920;
        ;
      } else {
        ;
      }
      int * v928 = v869->mem;
      int v1029 = ((int)((unsigned int)((int)((unsigned int)(v875 + 68) >> 2)) >> 1)) * 2;
      int v929 = v928[v1029];
      int v1030 = (((int)((unsigned int)((int)((unsigned int)(v875 + 68) >> 2)) >> 1)) * 2) + 1;
      int v930 = v928[v1030];
      int * v931 = v869->cache_vals;
      int v1032 = ((4 + ((((int)((unsigned int)((int)((unsigned int)(v875 + 68) >> 2)) >> 1)) & 3) * 2)) + ((((v909 + ((~(((v911 ^ -1) | (-(v911 ^ -1))) >> 31)) & 2)) - (v912 + ((~(((v913 ^ -1) | (-(v913 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
      v931[v1032] = v929;
      int * v933 = v869->cache_vals;
      int v1035 = (((4 + ((((int)((unsigned int)((int)((unsigned int)(v875 + 68) >> 2)) >> 1)) & 3) * 2)) + ((((v909 + ((~(((v911 ^ -1) | (-(v911 ^ -1))) >> 31)) & 2)) - (v912 + ((~(((v913 ^ -1) | (-(v913 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
      v933[v1035] = v930;
      int * v935 = v869->cache_tags;
      int v1038 = (int)((unsigned int)((int)((unsigned int)(v875 + 68) >> 2)) >> 1);
      v935[v1014] = v1038;
      int * v937 = v869->cache_dirty;
      v937[v1014] = 0;
      int * v939 = v869->cache_age;
      v939[v1014] = 1;
      int * v941 = v869->cache_age;
      int v942 = v941[v1014];
      int v943 = v941[v989];
      int v1044 = v943 + ((int)((unsigned int)(v943 - v942) >> 31));
      v941[v989] = v1044;
      int * v945 = v869->cache_age;
      int v946 = v945[v990];
      int v1046 = v946 + ((int)((unsigned int)(v946 - v942) >> 31));
      v945[v990] = v1046;
      int * v948 = v869->cache_age;
      v948[v1014] = 0;
      v951 = v1014;
    }
    int * v952 = v869->cache_vals;
    int v1049 = v951 * 2;
    int v953 = v952[v1049];
    int v1050 = (v951 * 2) + 1;
    int v954 = v952[v1050];
    int v1051 = (((((int)((unsigned int)((int)((unsigned int)(v875 + 68) >> 2)) >> 1)) & 1) * 2) + ((((v893 + ((~(((v895 ^ -1) | (-(v895 ^ -1))) >> 31)) & 2)) - (v896 + ((~(((v897 ^ -1) | (-(v897 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
    v952[v1051] = v953;
    int * v956 = v869->cache_vals;
    int v1054 = ((((((int)((unsigned int)((int)((unsigned int)(v875 + 68) >> 2)) >> 1)) & 1) * 2) + ((((v893 + ((~(((v895 ^ -1) | (-(v895 ^ -1))) >> 31)) & 2)) - (v896 + ((~(((v897 ^ -1) | (-(v897 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
    v956[v1054] = v954;
    int * v958 = v869->cache_tags;
    int v1057 = ((((int)((unsigned int)((int)((unsigned int)(v875 + 68) >> 2)) >> 1)) & 1) * 2) + ((((v893 + ((~(((v895 ^ -1) | (-(v895 ^ -1))) >> 31)) & 2)) - (v896 + ((~(((v897 ^ -1) | (-(v897 ^ -1))) >> 31)) & 2))) >> 31) & 1);
    int v1058 = (int)((unsigned int)((int)((unsigned int)(v875 + 68) >> 2)) >> 1);
    v958[v1057] = v1058;
    int * v960 = v869->cache_dirty;
    v960[v1057] = 0;
    int * v962 = v869->cache_age;
    v962[v1057] = 1;
    int * v964 = v869->cache_age;
    int v965 = v964[v1057];
    int v966 = v964[v987];
    int v1064 = v966 + ((int)((unsigned int)(v966 - v965) >> 31));
    v964[v987] = v1064;
    int * v968 = v869->cache_age;
    int v969 = v968[v988];
    int v1066 = v969 + ((int)((unsigned int)(v969 - v965) >> 31));
    v968[v988] = v1066;
    int * v971 = v869->cache_age;
    v971[v1057] = 0;
    v974 = v1057;
  }
  int v1069 = (v974 * 2) + (((int)((unsigned int)(v875 + 68) >> 2)) & 1);
  int v975 = v881[v1069];
  int * v976 = v869->reg_ready;
  int v1072 = ((v873 + ((v870 - v873) & (~((v870 - v873) >> 31)))) + 1) + ((100 ^ (((~(((v879 ^ ((int)((unsigned int)((int)((unsigned int)(v875 + 68) >> 2)) >> 1))) | (-(v879 ^ ((int)((unsigned int)((int)((unsigned int)(v875 + 68) >> 2)) >> 1))))) >> 31)) | (~(((v880 ^ ((int)((unsigned int)((int)((unsigned int)(v875 + 68) >> 2)) >> 1))) | (-(v880 ^ ((int)((unsigned int)((int)((unsigned int)(v875 + 68) >> 2)) >> 1))))) >> 31))) & 104)) ^ (((~(((v877 ^ ((int)((unsigned int)((int)((unsigned int)(v875 + 68) >> 2)) >> 1))) | (-(v877 ^ ((int)((unsigned int)((int)((unsigned int)(v875 + 68) >> 2)) >> 1))))) >> 31)) | (~(((v878 ^ ((int)((unsigned int)((int)((unsigned int)(v875 + 68) >> 2)) >> 1))) | (-(v878 ^ ((int)((unsigned int)((int)((unsigned int)(v875 + 68) >> 2)) >> 1))))) >> 31))) & (1 ^ (100 ^ (((~(((v879 ^ ((int)((unsigned int)((int)((unsigned int)(v875 + 68) >> 2)) >> 1))) | (-(v879 ^ ((int)((unsigned int)((int)((unsigned int)(v875 + 68) >> 2)) >> 1))))) >> 31)) | (~(((v880 ^ ((int)((unsigned int)((int)((unsigned int)(v875 + 68) >> 2)) >> 1))) | (-(v880 ^ ((int)((unsigned int)((int)((unsigned int)(v875 + 68) >> 2)) >> 1))))) >> 31))) & 104)))));
  v976[11] = v1072;
  int * v978 = v869->regs;
  v978[11] = v975;
  struct StateT * v980 = slot_16(v869);
  return v980;
}

struct StateT * slot_18(struct StateT * v1160) {
  int v1161 = v1160->timer;
  int v1164 = v1161 + 1;
  v1160->timer = v1164;
  return v1160;
}

struct StateT * slot_9(struct StateT * v550) {
  int * v551 = v550->saved_regs;
  int * v552 = v550->regs;
  int v553 = v552[11];
  v551[11] = v553;
  int v555 = v550->timer;
  int v567 = v555 + 1;
  v550->timer = v567;
  int * v557 = v550->reg_ready;
  v557[11] = v567;
  int * v559 = v550->regs;
  v559[11] = 0;
  struct StateT * v561 = slot_10(v550);
  return v561;
}

struct StateT * slot_11(struct StateT * v594) {
  int * v595 = v594->saved_regs;
  int * v596 = v594->regs;
  int v597 = v596[12];
  v595[12] = v597;
  int v599 = v594->timer;
  int v611 = v599 + 1;
  v594->timer = v611;
  int * v601 = v594->reg_ready;
  v601[12] = v611;
  int * v603 = v594->regs;
  v603[12] = 0;
  struct StateT * v605 = slot_12(v594);
  return v605;
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