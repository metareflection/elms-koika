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

struct StateT * snippet(struct StateT * v0);
struct StateT * slot_1(struct StateT * v19);
struct StateT * slot_6(struct StateT * v699);
struct StateT * slot_5(struct StateT * v683);
struct StateT * slot_4(struct StateT * v433);
struct StateT * slot_2(struct StateT * v35);
struct StateT * slot_3(struct StateT * v48);
struct StateT * slot_0(struct StateT * v2);
struct StateT * snippet(struct StateT * v0) {
  struct StateT * v1 = slot_0(v0);
  return v1;
}

struct StateT * slot_1(struct StateT * v19) {
  int v20 = v19->timer;
  int v28 = v20 + 1;
  v19->timer = v28;
  int * v22 = v19->regs;
  int v23 = v22[6];
  int * v24 = v19->regs;
  int v32 = v23 + 80;
  v24[6] = v32;
  struct StateT * v26 = slot_2(v19);
  return v26;
}

struct StateT * slot_6(struct StateT * v699) {
  int v700 = v699->timer;
  int v832 = v700 + 1;
  v699->timer = v832;
  int * v702 = v699->regs;
  int v703 = v702[11];
  int * v704 = v699->cache_tags;
  int v836 = (((int)((unsigned int)((int)((unsigned int)v703 >> 2)) >> 1)) & 1) * 2;
  int v705 = v704[v836];
  int * v706 = v699->cache_tags;
  int v838 = ((((int)((unsigned int)((int)((unsigned int)v703 >> 2)) >> 1)) & 1) * 2) + 1;
  int v707 = v706[v838];
  int * v708 = v699->cache_tags;
  int v840 = 4 + ((((int)((unsigned int)((int)((unsigned int)v703 >> 2)) >> 1)) & 3) * 2);
  int v709 = v708[v840];
  int * v710 = v699->cache_tags;
  int v842 = (4 + ((((int)((unsigned int)((int)((unsigned int)v703 >> 2)) >> 1)) & 3) * 2)) + 1;
  int v711 = v710[v842];
  int v712 = v699->timer;
  int v843 = v712 + ((100 ^ (((~(((v709 ^ ((int)((unsigned int)((int)((unsigned int)v703 >> 2)) >> 1))) | (-(v709 ^ ((int)((unsigned int)((int)((unsigned int)v703 >> 2)) >> 1))))) >> 31)) | (~(((v711 ^ ((int)((unsigned int)((int)((unsigned int)v703 >> 2)) >> 1))) | (-(v711 ^ ((int)((unsigned int)((int)((unsigned int)v703 >> 2)) >> 1))))) >> 31))) & 104)) ^ (((~(((v705 ^ ((int)((unsigned int)((int)((unsigned int)v703 >> 2)) >> 1))) | (-(v705 ^ ((int)((unsigned int)((int)((unsigned int)v703 >> 2)) >> 1))))) >> 31)) | (~(((v707 ^ ((int)((unsigned int)((int)((unsigned int)v703 >> 2)) >> 1))) | (-(v707 ^ ((int)((unsigned int)((int)((unsigned int)v703 >> 2)) >> 1))))) >> 31))) & (1 ^ (100 ^ (((~(((v709 ^ ((int)((unsigned int)((int)((unsigned int)v703 >> 2)) >> 1))) | (-(v709 ^ ((int)((unsigned int)((int)((unsigned int)v703 >> 2)) >> 1))))) >> 31)) | (~(((v711 ^ ((int)((unsigned int)((int)((unsigned int)v703 >> 2)) >> 1))) | (-(v711 ^ ((int)((unsigned int)((int)((unsigned int)v703 >> 2)) >> 1))))) >> 31))) & 104)))));
  v699->timer = v843;
  int * v714 = v699->cache_vals;
  bool v844 = !(((~(((v705 ^ ((int)((unsigned int)((int)((unsigned int)v703 >> 2)) >> 1))) | (-(v705 ^ ((int)((unsigned int)((int)((unsigned int)v703 >> 2)) >> 1))))) >> 31)) | (~(((v707 ^ ((int)((unsigned int)((int)((unsigned int)v703 >> 2)) >> 1))) | (-(v707 ^ ((int)((unsigned int)((int)((unsigned int)v703 >> 2)) >> 1))))) >> 31))) == 0);
  int v827;
  if (v844) {
    int * v715 = v699->cache_age;
    int v846 = ((((int)((unsigned int)((int)((unsigned int)v703 >> 2)) >> 1)) & 1) * 2) + ((~(((v707 ^ ((int)((unsigned int)((int)((unsigned int)v703 >> 2)) >> 1))) | (-(v707 ^ ((int)((unsigned int)((int)((unsigned int)v703 >> 2)) >> 1))))) >> 31)) & 1);
    int v716 = v715[v846];
    int * v717 = v699->cache_age;
    int v718 = v717[v836];
    int * v719 = v699->cache_age;
    int v849 = v718 + ((int)((unsigned int)(v718 - v716) >> 31));
    v719[v836] = v849;
    int * v721 = v699->cache_age;
    int v722 = v721[v838];
    int * v723 = v699->cache_age;
    int v852 = v722 + ((int)((unsigned int)(v722 - v716) >> 31));
    v723[v838] = v852;
    int * v725 = v699->cache_age;
    v725[v846] = 0;
    v827 = v846;
  } else {
    int * v728 = v699->cache_age;
    int v856 = (((int)((unsigned int)((int)((unsigned int)v703 >> 2)) >> 1)) & 1) * 2;
    int v729 = v728[v856];
    int * v730 = v699->cache_tags;
    int v731 = v730[v856];
    int * v732 = v699->cache_age;
    int v733 = v732[v838];
    int * v734 = v699->cache_tags;
    int v735 = v734[v838];
    bool v860 = !(((~(((v709 ^ ((int)((unsigned int)((int)((unsigned int)v703 >> 2)) >> 1))) | (-(v709 ^ ((int)((unsigned int)((int)((unsigned int)v703 >> 2)) >> 1))))) >> 31)) | (~(((v711 ^ ((int)((unsigned int)((int)((unsigned int)v703 >> 2)) >> 1))) | (-(v711 ^ ((int)((unsigned int)((int)((unsigned int)v703 >> 2)) >> 1))))) >> 31))) == 0);
    int v799;
    if (v860) {
      int * v736 = v699->cache_age;
      int v862 = (4 + ((((int)((unsigned int)((int)((unsigned int)v703 >> 2)) >> 1)) & 3) * 2)) + ((~(((v711 ^ ((int)((unsigned int)((int)((unsigned int)v703 >> 2)) >> 1))) | (-(v711 ^ ((int)((unsigned int)((int)((unsigned int)v703 >> 2)) >> 1))))) >> 31)) & 1);
      int v737 = v736[v862];
      int * v738 = v699->cache_age;
      int v739 = v738[v840];
      int * v740 = v699->cache_age;
      int v865 = v739 + ((int)((unsigned int)(v739 - v737) >> 31));
      v740[v840] = v865;
      int * v742 = v699->cache_age;
      int v743 = v742[v842];
      int * v744 = v699->cache_age;
      int v868 = v743 + ((int)((unsigned int)(v743 - v737) >> 31));
      v744[v842] = v868;
      int * v746 = v699->cache_age;
      v746[v862] = 0;
      v799 = v862;
    } else {
      int * v749 = v699->cache_age;
      int v872 = 4 + ((((int)((unsigned int)((int)((unsigned int)v703 >> 2)) >> 1)) & 3) * 2);
      int v750 = v749[v872];
      int * v751 = v699->cache_tags;
      int v752 = v751[v872];
      int * v753 = v699->cache_age;
      int v754 = v753[v842];
      int * v755 = v699->cache_tags;
      int v756 = v755[v842];
      int * v757 = v699->cache_dirty;
      int v877 = (4 + ((((int)((unsigned int)((int)((unsigned int)v703 >> 2)) >> 1)) & 3) * 2)) + ((((v750 + ((~(((v752 ^ -1) | (-(v752 ^ -1))) >> 31)) & 2)) - (v754 + ((~(((v756 ^ -1) | (-(v756 ^ -1))) >> 31)) & 2))) >> 31) & 1);
      int v758 = v757[v877];
      bool v878 = !(v758 == 0);
      if (v878) {
        int * v759 = v699->cache_tags;
        int v760 = v759[v877];
        int * v761 = v699->cache_vals;
        int v881 = ((4 + ((((int)((unsigned int)((int)((unsigned int)v703 >> 2)) >> 1)) & 3) * 2)) + ((((v750 + ((~(((v752 ^ -1) | (-(v752 ^ -1))) >> 31)) & 2)) - (v754 + ((~(((v756 ^ -1) | (-(v756 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
        int v762 = v761[v881];
        int * v763 = v699->cache_vals;
        int v883 = (((4 + ((((int)((unsigned int)((int)((unsigned int)v703 >> 2)) >> 1)) & 3) * 2)) + ((((v750 + ((~(((v752 ^ -1) | (-(v752 ^ -1))) >> 31)) & 2)) - (v754 + ((~(((v756 ^ -1) | (-(v756 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
        int v764 = v763[v883];
        int * v765 = v699->mem;
        int v885 = v760 * 2;
        v765[v885] = v762;
        int * v767 = v699->mem;
        int v888 = (v760 * 2) + 1;
        v767[v888] = v764;
        ;
      } else {
        ;
      }
      int * v772 = v699->mem;
      int v893 = ((int)((unsigned int)((int)((unsigned int)v703 >> 2)) >> 1)) * 2;
      int v773 = v772[v893];
      int * v774 = v699->mem;
      int v895 = (((int)((unsigned int)((int)((unsigned int)v703 >> 2)) >> 1)) * 2) + 1;
      int v775 = v774[v895];
      int * v776 = v699->cache_vals;
      int v897 = ((4 + ((((int)((unsigned int)((int)((unsigned int)v703 >> 2)) >> 1)) & 3) * 2)) + ((((v750 + ((~(((v752 ^ -1) | (-(v752 ^ -1))) >> 31)) & 2)) - (v754 + ((~(((v756 ^ -1) | (-(v756 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
      v776[v897] = v773;
      int * v778 = v699->cache_vals;
      int v900 = (((4 + ((((int)((unsigned int)((int)((unsigned int)v703 >> 2)) >> 1)) & 3) * 2)) + ((((v750 + ((~(((v752 ^ -1) | (-(v752 ^ -1))) >> 31)) & 2)) - (v754 + ((~(((v756 ^ -1) | (-(v756 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
      v778[v900] = v775;
      int * v780 = v699->cache_tags;
      int v903 = (int)((unsigned int)((int)((unsigned int)v703 >> 2)) >> 1);
      v780[v877] = v903;
      int * v782 = v699->cache_dirty;
      v782[v877] = 0;
      int * v784 = v699->cache_age;
      v784[v877] = 1;
      int * v786 = v699->cache_age;
      int v787 = v786[v877];
      int * v788 = v699->cache_age;
      int v789 = v788[v840];
      int * v790 = v699->cache_age;
      int v911 = v789 + ((int)((unsigned int)(v789 - v787) >> 31));
      v790[v840] = v911;
      int * v792 = v699->cache_age;
      int v793 = v792[v842];
      int * v794 = v699->cache_age;
      int v914 = v793 + ((int)((unsigned int)(v793 - v787) >> 31));
      v794[v842] = v914;
      int * v796 = v699->cache_age;
      v796[v877] = 0;
      v799 = v877;
    }
    int * v800 = v699->cache_vals;
    int v917 = v799 * 2;
    int v801 = v800[v917];
    int * v802 = v699->cache_vals;
    int v919 = (v799 * 2) + 1;
    int v803 = v802[v919];
    int * v804 = v699->cache_vals;
    int v921 = (((((int)((unsigned int)((int)((unsigned int)v703 >> 2)) >> 1)) & 1) * 2) + ((((v729 + ((~(((v731 ^ -1) | (-(v731 ^ -1))) >> 31)) & 2)) - (v733 + ((~(((v735 ^ -1) | (-(v735 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
    v804[v921] = v801;
    int * v806 = v699->cache_vals;
    int v924 = ((((((int)((unsigned int)((int)((unsigned int)v703 >> 2)) >> 1)) & 1) * 2) + ((((v729 + ((~(((v731 ^ -1) | (-(v731 ^ -1))) >> 31)) & 2)) - (v733 + ((~(((v735 ^ -1) | (-(v735 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
    v806[v924] = v803;
    int * v808 = v699->cache_tags;
    int v927 = ((((int)((unsigned int)((int)((unsigned int)v703 >> 2)) >> 1)) & 1) * 2) + ((((v729 + ((~(((v731 ^ -1) | (-(v731 ^ -1))) >> 31)) & 2)) - (v733 + ((~(((v735 ^ -1) | (-(v735 ^ -1))) >> 31)) & 2))) >> 31) & 1);
    int v928 = (int)((unsigned int)((int)((unsigned int)v703 >> 2)) >> 1);
    v808[v927] = v928;
    int * v810 = v699->cache_dirty;
    v810[v927] = 0;
    int * v812 = v699->cache_age;
    v812[v927] = 1;
    int * v814 = v699->cache_age;
    int v815 = v814[v927];
    int * v816 = v699->cache_age;
    int v817 = v816[v836];
    int * v818 = v699->cache_age;
    int v936 = v817 + ((int)((unsigned int)(v817 - v815) >> 31));
    v818[v836] = v936;
    int * v820 = v699->cache_age;
    int v821 = v820[v838];
    int * v822 = v699->cache_age;
    int v939 = v821 + ((int)((unsigned int)(v821 - v815) >> 31));
    v822[v838] = v939;
    int * v824 = v699->cache_age;
    v824[v927] = 0;
    v827 = v927;
  }
  int v942 = (v827 * 2) + (((int)((unsigned int)v703 >> 2)) & 1);
  int v828 = v714[v942];
  int * v829 = v699->regs;
  v829[12] = v828;
  return v699;
}

struct StateT * slot_5(struct StateT * v683) {
  int v684 = v683->timer;
  int v692 = v684 + 1;
  v683->timer = v692;
  int * v686 = v683->regs;
  int v687 = v686[11];
  int * v688 = v683->regs;
  int v696 = v687 << 2;
  v688[11] = v696;
  struct StateT * v690 = slot_6(v683);
  return v690;
}

struct StateT * slot_4(struct StateT * v433) {
  int v434 = v433->timer;
  int v567 = v434 + 1;
  v433->timer = v567;
  int * v436 = v433->regs;
  int v437 = v436[6];
  int * v438 = v433->cache_tags;
  int v571 = (((int)((unsigned int)((int)((unsigned int)v437 >> 2)) >> 1)) & 1) * 2;
  int v439 = v438[v571];
  int * v440 = v433->cache_tags;
  int v573 = ((((int)((unsigned int)((int)((unsigned int)v437 >> 2)) >> 1)) & 1) * 2) + 1;
  int v441 = v440[v573];
  int * v442 = v433->cache_tags;
  int v575 = 4 + ((((int)((unsigned int)((int)((unsigned int)v437 >> 2)) >> 1)) & 3) * 2);
  int v443 = v442[v575];
  int * v444 = v433->cache_tags;
  int v577 = (4 + ((((int)((unsigned int)((int)((unsigned int)v437 >> 2)) >> 1)) & 3) * 2)) + 1;
  int v445 = v444[v577];
  int v446 = v433->timer;
  int v578 = v446 + ((100 ^ (((~(((v443 ^ ((int)((unsigned int)((int)((unsigned int)v437 >> 2)) >> 1))) | (-(v443 ^ ((int)((unsigned int)((int)((unsigned int)v437 >> 2)) >> 1))))) >> 31)) | (~(((v445 ^ ((int)((unsigned int)((int)((unsigned int)v437 >> 2)) >> 1))) | (-(v445 ^ ((int)((unsigned int)((int)((unsigned int)v437 >> 2)) >> 1))))) >> 31))) & 104)) ^ (((~(((v439 ^ ((int)((unsigned int)((int)((unsigned int)v437 >> 2)) >> 1))) | (-(v439 ^ ((int)((unsigned int)((int)((unsigned int)v437 >> 2)) >> 1))))) >> 31)) | (~(((v441 ^ ((int)((unsigned int)((int)((unsigned int)v437 >> 2)) >> 1))) | (-(v441 ^ ((int)((unsigned int)((int)((unsigned int)v437 >> 2)) >> 1))))) >> 31))) & (1 ^ (100 ^ (((~(((v443 ^ ((int)((unsigned int)((int)((unsigned int)v437 >> 2)) >> 1))) | (-(v443 ^ ((int)((unsigned int)((int)((unsigned int)v437 >> 2)) >> 1))))) >> 31)) | (~(((v445 ^ ((int)((unsigned int)((int)((unsigned int)v437 >> 2)) >> 1))) | (-(v445 ^ ((int)((unsigned int)((int)((unsigned int)v437 >> 2)) >> 1))))) >> 31))) & 104)))));
  v433->timer = v578;
  int * v448 = v433->cache_vals;
  bool v579 = !(((~(((v439 ^ ((int)((unsigned int)((int)((unsigned int)v437 >> 2)) >> 1))) | (-(v439 ^ ((int)((unsigned int)((int)((unsigned int)v437 >> 2)) >> 1))))) >> 31)) | (~(((v441 ^ ((int)((unsigned int)((int)((unsigned int)v437 >> 2)) >> 1))) | (-(v441 ^ ((int)((unsigned int)((int)((unsigned int)v437 >> 2)) >> 1))))) >> 31))) == 0);
  int v561;
  if (v579) {
    int * v449 = v433->cache_age;
    int v581 = ((((int)((unsigned int)((int)((unsigned int)v437 >> 2)) >> 1)) & 1) * 2) + ((~(((v441 ^ ((int)((unsigned int)((int)((unsigned int)v437 >> 2)) >> 1))) | (-(v441 ^ ((int)((unsigned int)((int)((unsigned int)v437 >> 2)) >> 1))))) >> 31)) & 1);
    int v450 = v449[v581];
    int * v451 = v433->cache_age;
    int v452 = v451[v571];
    int * v453 = v433->cache_age;
    int v584 = v452 + ((int)((unsigned int)(v452 - v450) >> 31));
    v453[v571] = v584;
    int * v455 = v433->cache_age;
    int v456 = v455[v573];
    int * v457 = v433->cache_age;
    int v587 = v456 + ((int)((unsigned int)(v456 - v450) >> 31));
    v457[v573] = v587;
    int * v459 = v433->cache_age;
    v459[v581] = 0;
    v561 = v581;
  } else {
    int * v462 = v433->cache_age;
    int v591 = (((int)((unsigned int)((int)((unsigned int)v437 >> 2)) >> 1)) & 1) * 2;
    int v463 = v462[v591];
    int * v464 = v433->cache_tags;
    int v465 = v464[v591];
    int * v466 = v433->cache_age;
    int v467 = v466[v573];
    int * v468 = v433->cache_tags;
    int v469 = v468[v573];
    bool v595 = !(((~(((v443 ^ ((int)((unsigned int)((int)((unsigned int)v437 >> 2)) >> 1))) | (-(v443 ^ ((int)((unsigned int)((int)((unsigned int)v437 >> 2)) >> 1))))) >> 31)) | (~(((v445 ^ ((int)((unsigned int)((int)((unsigned int)v437 >> 2)) >> 1))) | (-(v445 ^ ((int)((unsigned int)((int)((unsigned int)v437 >> 2)) >> 1))))) >> 31))) == 0);
    int v533;
    if (v595) {
      int * v470 = v433->cache_age;
      int v597 = (4 + ((((int)((unsigned int)((int)((unsigned int)v437 >> 2)) >> 1)) & 3) * 2)) + ((~(((v445 ^ ((int)((unsigned int)((int)((unsigned int)v437 >> 2)) >> 1))) | (-(v445 ^ ((int)((unsigned int)((int)((unsigned int)v437 >> 2)) >> 1))))) >> 31)) & 1);
      int v471 = v470[v597];
      int * v472 = v433->cache_age;
      int v473 = v472[v575];
      int * v474 = v433->cache_age;
      int v600 = v473 + ((int)((unsigned int)(v473 - v471) >> 31));
      v474[v575] = v600;
      int * v476 = v433->cache_age;
      int v477 = v476[v577];
      int * v478 = v433->cache_age;
      int v603 = v477 + ((int)((unsigned int)(v477 - v471) >> 31));
      v478[v577] = v603;
      int * v480 = v433->cache_age;
      v480[v597] = 0;
      v533 = v597;
    } else {
      int * v483 = v433->cache_age;
      int v607 = 4 + ((((int)((unsigned int)((int)((unsigned int)v437 >> 2)) >> 1)) & 3) * 2);
      int v484 = v483[v607];
      int * v485 = v433->cache_tags;
      int v486 = v485[v607];
      int * v487 = v433->cache_age;
      int v488 = v487[v577];
      int * v489 = v433->cache_tags;
      int v490 = v489[v577];
      int * v491 = v433->cache_dirty;
      int v612 = (4 + ((((int)((unsigned int)((int)((unsigned int)v437 >> 2)) >> 1)) & 3) * 2)) + ((((v484 + ((~(((v486 ^ -1) | (-(v486 ^ -1))) >> 31)) & 2)) - (v488 + ((~(((v490 ^ -1) | (-(v490 ^ -1))) >> 31)) & 2))) >> 31) & 1);
      int v492 = v491[v612];
      bool v613 = !(v492 == 0);
      if (v613) {
        int * v493 = v433->cache_tags;
        int v494 = v493[v612];
        int * v495 = v433->cache_vals;
        int v616 = ((4 + ((((int)((unsigned int)((int)((unsigned int)v437 >> 2)) >> 1)) & 3) * 2)) + ((((v484 + ((~(((v486 ^ -1) | (-(v486 ^ -1))) >> 31)) & 2)) - (v488 + ((~(((v490 ^ -1) | (-(v490 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
        int v496 = v495[v616];
        int * v497 = v433->cache_vals;
        int v618 = (((4 + ((((int)((unsigned int)((int)((unsigned int)v437 >> 2)) >> 1)) & 3) * 2)) + ((((v484 + ((~(((v486 ^ -1) | (-(v486 ^ -1))) >> 31)) & 2)) - (v488 + ((~(((v490 ^ -1) | (-(v490 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
        int v498 = v497[v618];
        int * v499 = v433->mem;
        int v620 = v494 * 2;
        v499[v620] = v496;
        int * v501 = v433->mem;
        int v623 = (v494 * 2) + 1;
        v501[v623] = v498;
        ;
      } else {
        ;
      }
      int * v506 = v433->mem;
      int v628 = ((int)((unsigned int)((int)((unsigned int)v437 >> 2)) >> 1)) * 2;
      int v507 = v506[v628];
      int * v508 = v433->mem;
      int v630 = (((int)((unsigned int)((int)((unsigned int)v437 >> 2)) >> 1)) * 2) + 1;
      int v509 = v508[v630];
      int * v510 = v433->cache_vals;
      int v632 = ((4 + ((((int)((unsigned int)((int)((unsigned int)v437 >> 2)) >> 1)) & 3) * 2)) + ((((v484 + ((~(((v486 ^ -1) | (-(v486 ^ -1))) >> 31)) & 2)) - (v488 + ((~(((v490 ^ -1) | (-(v490 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
      v510[v632] = v507;
      int * v512 = v433->cache_vals;
      int v635 = (((4 + ((((int)((unsigned int)((int)((unsigned int)v437 >> 2)) >> 1)) & 3) * 2)) + ((((v484 + ((~(((v486 ^ -1) | (-(v486 ^ -1))) >> 31)) & 2)) - (v488 + ((~(((v490 ^ -1) | (-(v490 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
      v512[v635] = v509;
      int * v514 = v433->cache_tags;
      int v638 = (int)((unsigned int)((int)((unsigned int)v437 >> 2)) >> 1);
      v514[v612] = v638;
      int * v516 = v433->cache_dirty;
      v516[v612] = 0;
      int * v518 = v433->cache_age;
      v518[v612] = 1;
      int * v520 = v433->cache_age;
      int v521 = v520[v612];
      int * v522 = v433->cache_age;
      int v523 = v522[v575];
      int * v524 = v433->cache_age;
      int v646 = v523 + ((int)((unsigned int)(v523 - v521) >> 31));
      v524[v575] = v646;
      int * v526 = v433->cache_age;
      int v527 = v526[v577];
      int * v528 = v433->cache_age;
      int v649 = v527 + ((int)((unsigned int)(v527 - v521) >> 31));
      v528[v577] = v649;
      int * v530 = v433->cache_age;
      v530[v612] = 0;
      v533 = v612;
    }
    int * v534 = v433->cache_vals;
    int v652 = v533 * 2;
    int v535 = v534[v652];
    int * v536 = v433->cache_vals;
    int v654 = (v533 * 2) + 1;
    int v537 = v536[v654];
    int * v538 = v433->cache_vals;
    int v656 = (((((int)((unsigned int)((int)((unsigned int)v437 >> 2)) >> 1)) & 1) * 2) + ((((v463 + ((~(((v465 ^ -1) | (-(v465 ^ -1))) >> 31)) & 2)) - (v467 + ((~(((v469 ^ -1) | (-(v469 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
    v538[v656] = v535;
    int * v540 = v433->cache_vals;
    int v659 = ((((((int)((unsigned int)((int)((unsigned int)v437 >> 2)) >> 1)) & 1) * 2) + ((((v463 + ((~(((v465 ^ -1) | (-(v465 ^ -1))) >> 31)) & 2)) - (v467 + ((~(((v469 ^ -1) | (-(v469 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
    v540[v659] = v537;
    int * v542 = v433->cache_tags;
    int v662 = ((((int)((unsigned int)((int)((unsigned int)v437 >> 2)) >> 1)) & 1) * 2) + ((((v463 + ((~(((v465 ^ -1) | (-(v465 ^ -1))) >> 31)) & 2)) - (v467 + ((~(((v469 ^ -1) | (-(v469 ^ -1))) >> 31)) & 2))) >> 31) & 1);
    int v663 = (int)((unsigned int)((int)((unsigned int)v437 >> 2)) >> 1);
    v542[v662] = v663;
    int * v544 = v433->cache_dirty;
    v544[v662] = 0;
    int * v546 = v433->cache_age;
    v546[v662] = 1;
    int * v548 = v433->cache_age;
    int v549 = v548[v662];
    int * v550 = v433->cache_age;
    int v551 = v550[v571];
    int * v552 = v433->cache_age;
    int v671 = v551 + ((int)((unsigned int)(v551 - v549) >> 31));
    v552[v571] = v671;
    int * v554 = v433->cache_age;
    int v555 = v554[v573];
    int * v556 = v433->cache_age;
    int v674 = v555 + ((int)((unsigned int)(v555 - v549) >> 31));
    v556[v573] = v674;
    int * v558 = v433->cache_age;
    v558[v662] = 0;
    v561 = v662;
  }
  int v677 = (v561 * 2) + (((int)((unsigned int)v437 >> 2)) & 1);
  int v562 = v448[v677];
  int * v563 = v433->regs;
  v563[11] = v562;
  struct StateT * v565 = slot_5(v433);
  return v565;
}

struct StateT * slot_2(struct StateT * v35) {
  int v36 = v35->timer;
  int v42 = v36 + 1;
  v35->timer = v42;
  int * v38 = v35->regs;
  v38[7] = 0;
  struct StateT * v40 = slot_3(v35);
  return v40;
}

struct StateT * slot_3(struct StateT * v48) {
  int v49 = v48->timer;
  int v254 = v49 + 1;
  v48->timer = v254;
  int * v51 = v48->regs;
  int v52 = v51[6];
  int * v53 = v48->regs;
  int v54 = v53[7];
  int * v55 = v48->cache_tags;
  int v260 = (((int)((unsigned int)((int)((unsigned int)v52 >> 2)) >> 1)) & 1) * 2;
  int v56 = v55[v260];
  int * v57 = v48->cache_tags;
  int v262 = ((((int)((unsigned int)((int)((unsigned int)v52 >> 2)) >> 1)) & 1) * 2) + 1;
  int v58 = v57[v262];
  int * v59 = v48->cache_tags;
  int v264 = 4 + ((((int)((unsigned int)((int)((unsigned int)v52 >> 2)) >> 1)) & 3) * 2);
  int v60 = v59[v264];
  int * v61 = v48->cache_tags;
  int v266 = (4 + ((((int)((unsigned int)((int)((unsigned int)v52 >> 2)) >> 1)) & 3) * 2)) + 1;
  int v62 = v61[v266];
  int v63 = v48->timer;
  int v267 = v63 + ((100 ^ (((~(((v60 ^ ((int)((unsigned int)((int)((unsigned int)v52 >> 2)) >> 1))) | (-(v60 ^ ((int)((unsigned int)((int)((unsigned int)v52 >> 2)) >> 1))))) >> 31)) | (~(((v62 ^ ((int)((unsigned int)((int)((unsigned int)v52 >> 2)) >> 1))) | (-(v62 ^ ((int)((unsigned int)((int)((unsigned int)v52 >> 2)) >> 1))))) >> 31))) & 104)) ^ (((~(((v56 ^ ((int)((unsigned int)((int)((unsigned int)v52 >> 2)) >> 1))) | (-(v56 ^ ((int)((unsigned int)((int)((unsigned int)v52 >> 2)) >> 1))))) >> 31)) | (~(((v58 ^ ((int)((unsigned int)((int)((unsigned int)v52 >> 2)) >> 1))) | (-(v58 ^ ((int)((unsigned int)((int)((unsigned int)v52 >> 2)) >> 1))))) >> 31))) & (1 ^ (100 ^ (((~(((v60 ^ ((int)((unsigned int)((int)((unsigned int)v52 >> 2)) >> 1))) | (-(v60 ^ ((int)((unsigned int)((int)((unsigned int)v52 >> 2)) >> 1))))) >> 31)) | (~(((v62 ^ ((int)((unsigned int)((int)((unsigned int)v52 >> 2)) >> 1))) | (-(v62 ^ ((int)((unsigned int)((int)((unsigned int)v52 >> 2)) >> 1))))) >> 31))) & 104)))));
  v48->timer = v267;
  bool v268 = !(((~(((v56 ^ ((int)((unsigned int)((int)((unsigned int)v52 >> 2)) >> 1))) | (-(v56 ^ ((int)((unsigned int)((int)((unsigned int)v52 >> 2)) >> 1))))) >> 31)) | (~(((v58 ^ ((int)((unsigned int)((int)((unsigned int)v52 >> 2)) >> 1))) | (-(v58 ^ ((int)((unsigned int)((int)((unsigned int)v52 >> 2)) >> 1))))) >> 31))) == 0);
  int v177;
  if (v268) {
    int * v65 = v48->cache_age;
    int v270 = ((((int)((unsigned int)((int)((unsigned int)v52 >> 2)) >> 1)) & 1) * 2) + ((~(((v58 ^ ((int)((unsigned int)((int)((unsigned int)v52 >> 2)) >> 1))) | (-(v58 ^ ((int)((unsigned int)((int)((unsigned int)v52 >> 2)) >> 1))))) >> 31)) & 1);
    int v66 = v65[v270];
    int * v67 = v48->cache_age;
    int v68 = v67[v260];
    int * v69 = v48->cache_age;
    int v273 = v68 + ((int)((unsigned int)(v68 - v66) >> 31));
    v69[v260] = v273;
    int * v71 = v48->cache_age;
    int v72 = v71[v262];
    int * v73 = v48->cache_age;
    int v276 = v72 + ((int)((unsigned int)(v72 - v66) >> 31));
    v73[v262] = v276;
    int * v75 = v48->cache_age;
    v75[v270] = 0;
    v177 = v270;
  } else {
    int * v78 = v48->cache_age;
    int v280 = (((int)((unsigned int)((int)((unsigned int)v52 >> 2)) >> 1)) & 1) * 2;
    int v79 = v78[v280];
    int * v80 = v48->cache_tags;
    int v81 = v80[v280];
    int * v82 = v48->cache_age;
    int v83 = v82[v262];
    int * v84 = v48->cache_tags;
    int v85 = v84[v262];
    bool v284 = !(((~(((v60 ^ ((int)((unsigned int)((int)((unsigned int)v52 >> 2)) >> 1))) | (-(v60 ^ ((int)((unsigned int)((int)((unsigned int)v52 >> 2)) >> 1))))) >> 31)) | (~(((v62 ^ ((int)((unsigned int)((int)((unsigned int)v52 >> 2)) >> 1))) | (-(v62 ^ ((int)((unsigned int)((int)((unsigned int)v52 >> 2)) >> 1))))) >> 31))) == 0);
    int v149;
    if (v284) {
      int * v86 = v48->cache_age;
      int v286 = (4 + ((((int)((unsigned int)((int)((unsigned int)v52 >> 2)) >> 1)) & 3) * 2)) + ((~(((v62 ^ ((int)((unsigned int)((int)((unsigned int)v52 >> 2)) >> 1))) | (-(v62 ^ ((int)((unsigned int)((int)((unsigned int)v52 >> 2)) >> 1))))) >> 31)) & 1);
      int v87 = v86[v286];
      int * v88 = v48->cache_age;
      int v89 = v88[v264];
      int * v90 = v48->cache_age;
      int v289 = v89 + ((int)((unsigned int)(v89 - v87) >> 31));
      v90[v264] = v289;
      int * v92 = v48->cache_age;
      int v93 = v92[v266];
      int * v94 = v48->cache_age;
      int v292 = v93 + ((int)((unsigned int)(v93 - v87) >> 31));
      v94[v266] = v292;
      int * v96 = v48->cache_age;
      v96[v286] = 0;
      v149 = v286;
    } else {
      int * v99 = v48->cache_age;
      int v296 = 4 + ((((int)((unsigned int)((int)((unsigned int)v52 >> 2)) >> 1)) & 3) * 2);
      int v100 = v99[v296];
      int * v101 = v48->cache_tags;
      int v102 = v101[v296];
      int * v103 = v48->cache_age;
      int v104 = v103[v266];
      int * v105 = v48->cache_tags;
      int v106 = v105[v266];
      int * v107 = v48->cache_dirty;
      int v301 = (4 + ((((int)((unsigned int)((int)((unsigned int)v52 >> 2)) >> 1)) & 3) * 2)) + ((((v100 + ((~(((v102 ^ -1) | (-(v102 ^ -1))) >> 31)) & 2)) - (v104 + ((~(((v106 ^ -1) | (-(v106 ^ -1))) >> 31)) & 2))) >> 31) & 1);
      int v108 = v107[v301];
      bool v302 = !(v108 == 0);
      if (v302) {
        int * v109 = v48->cache_tags;
        int v110 = v109[v301];
        int * v111 = v48->cache_vals;
        int v305 = ((4 + ((((int)((unsigned int)((int)((unsigned int)v52 >> 2)) >> 1)) & 3) * 2)) + ((((v100 + ((~(((v102 ^ -1) | (-(v102 ^ -1))) >> 31)) & 2)) - (v104 + ((~(((v106 ^ -1) | (-(v106 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
        int v112 = v111[v305];
        int * v113 = v48->cache_vals;
        int v307 = (((4 + ((((int)((unsigned int)((int)((unsigned int)v52 >> 2)) >> 1)) & 3) * 2)) + ((((v100 + ((~(((v102 ^ -1) | (-(v102 ^ -1))) >> 31)) & 2)) - (v104 + ((~(((v106 ^ -1) | (-(v106 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
        int v114 = v113[v307];
        int * v115 = v48->mem;
        int v309 = v110 * 2;
        v115[v309] = v112;
        int * v117 = v48->mem;
        int v312 = (v110 * 2) + 1;
        v117[v312] = v114;
        ;
      } else {
        ;
      }
      int * v122 = v48->mem;
      int v317 = ((int)((unsigned int)((int)((unsigned int)v52 >> 2)) >> 1)) * 2;
      int v123 = v122[v317];
      int * v124 = v48->mem;
      int v319 = (((int)((unsigned int)((int)((unsigned int)v52 >> 2)) >> 1)) * 2) + 1;
      int v125 = v124[v319];
      int * v126 = v48->cache_vals;
      int v321 = ((4 + ((((int)((unsigned int)((int)((unsigned int)v52 >> 2)) >> 1)) & 3) * 2)) + ((((v100 + ((~(((v102 ^ -1) | (-(v102 ^ -1))) >> 31)) & 2)) - (v104 + ((~(((v106 ^ -1) | (-(v106 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
      v126[v321] = v123;
      int * v128 = v48->cache_vals;
      int v324 = (((4 + ((((int)((unsigned int)((int)((unsigned int)v52 >> 2)) >> 1)) & 3) * 2)) + ((((v100 + ((~(((v102 ^ -1) | (-(v102 ^ -1))) >> 31)) & 2)) - (v104 + ((~(((v106 ^ -1) | (-(v106 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
      v128[v324] = v125;
      int * v130 = v48->cache_tags;
      int v327 = (int)((unsigned int)((int)((unsigned int)v52 >> 2)) >> 1);
      v130[v301] = v327;
      int * v132 = v48->cache_dirty;
      v132[v301] = 0;
      int * v134 = v48->cache_age;
      v134[v301] = 1;
      int * v136 = v48->cache_age;
      int v137 = v136[v301];
      int * v138 = v48->cache_age;
      int v139 = v138[v264];
      int * v140 = v48->cache_age;
      int v335 = v139 + ((int)((unsigned int)(v139 - v137) >> 31));
      v140[v264] = v335;
      int * v142 = v48->cache_age;
      int v143 = v142[v266];
      int * v144 = v48->cache_age;
      int v338 = v143 + ((int)((unsigned int)(v143 - v137) >> 31));
      v144[v266] = v338;
      int * v146 = v48->cache_age;
      v146[v301] = 0;
      v149 = v301;
    }
    int * v150 = v48->cache_vals;
    int v341 = v149 * 2;
    int v151 = v150[v341];
    int * v152 = v48->cache_vals;
    int v343 = (v149 * 2) + 1;
    int v153 = v152[v343];
    int * v154 = v48->cache_vals;
    int v345 = (((((int)((unsigned int)((int)((unsigned int)v52 >> 2)) >> 1)) & 1) * 2) + ((((v79 + ((~(((v81 ^ -1) | (-(v81 ^ -1))) >> 31)) & 2)) - (v83 + ((~(((v85 ^ -1) | (-(v85 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
    v154[v345] = v151;
    int * v156 = v48->cache_vals;
    int v348 = ((((((int)((unsigned int)((int)((unsigned int)v52 >> 2)) >> 1)) & 1) * 2) + ((((v79 + ((~(((v81 ^ -1) | (-(v81 ^ -1))) >> 31)) & 2)) - (v83 + ((~(((v85 ^ -1) | (-(v85 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
    v156[v348] = v153;
    int * v158 = v48->cache_tags;
    int v351 = ((((int)((unsigned int)((int)((unsigned int)v52 >> 2)) >> 1)) & 1) * 2) + ((((v79 + ((~(((v81 ^ -1) | (-(v81 ^ -1))) >> 31)) & 2)) - (v83 + ((~(((v85 ^ -1) | (-(v85 ^ -1))) >> 31)) & 2))) >> 31) & 1);
    int v352 = (int)((unsigned int)((int)((unsigned int)v52 >> 2)) >> 1);
    v158[v351] = v352;
    int * v160 = v48->cache_dirty;
    v160[v351] = 0;
    int * v162 = v48->cache_age;
    v162[v351] = 1;
    int * v164 = v48->cache_age;
    int v165 = v164[v351];
    int * v166 = v48->cache_age;
    int v167 = v166[v260];
    int * v168 = v48->cache_age;
    int v360 = v167 + ((int)((unsigned int)(v167 - v165) >> 31));
    v168[v260] = v360;
    int * v170 = v48->cache_age;
    int v171 = v170[v262];
    int * v172 = v48->cache_age;
    int v363 = v171 + ((int)((unsigned int)(v171 - v165) >> 31));
    v172[v262] = v363;
    int * v174 = v48->cache_age;
    v174[v351] = 0;
    v177 = v351;
  }
  int * v178 = v48->cache_vals;
  int v366 = (v177 * 2) + (((int)((unsigned int)v52 >> 2)) & 1);
  v178[v366] = v54;
  int * v180 = v48->cache_tags;
  int v181 = v180[v264];
  int * v182 = v48->cache_tags;
  int v183 = v182[v266];
  bool v370 = !(((~(((v181 ^ ((int)((unsigned int)((int)((unsigned int)v52 >> 2)) >> 1))) | (-(v181 ^ ((int)((unsigned int)((int)((unsigned int)v52 >> 2)) >> 1))))) >> 31)) | (~(((v183 ^ ((int)((unsigned int)((int)((unsigned int)v52 >> 2)) >> 1))) | (-(v183 ^ ((int)((unsigned int)((int)((unsigned int)v52 >> 2)) >> 1))))) >> 31))) == 0);
  int v247;
  if (v370) {
    int * v184 = v48->cache_age;
    int v372 = (4 + ((((int)((unsigned int)((int)((unsigned int)v52 >> 2)) >> 1)) & 3) * 2)) + ((~(((v183 ^ ((int)((unsigned int)((int)((unsigned int)v52 >> 2)) >> 1))) | (-(v183 ^ ((int)((unsigned int)((int)((unsigned int)v52 >> 2)) >> 1))))) >> 31)) & 1);
    int v185 = v184[v372];
    int * v186 = v48->cache_age;
    int v187 = v186[v264];
    int * v188 = v48->cache_age;
    int v375 = v187 + ((int)((unsigned int)(v187 - v185) >> 31));
    v188[v264] = v375;
    int * v190 = v48->cache_age;
    int v191 = v190[v266];
    int * v192 = v48->cache_age;
    int v378 = v191 + ((int)((unsigned int)(v191 - v185) >> 31));
    v192[v266] = v378;
    int * v194 = v48->cache_age;
    v194[v372] = 0;
    v247 = v372;
  } else {
    int * v197 = v48->cache_age;
    int v382 = 4 + ((((int)((unsigned int)((int)((unsigned int)v52 >> 2)) >> 1)) & 3) * 2);
    int v198 = v197[v382];
    int * v199 = v48->cache_tags;
    int v200 = v199[v382];
    int * v201 = v48->cache_age;
    int v202 = v201[v266];
    int * v203 = v48->cache_tags;
    int v204 = v203[v266];
    int * v205 = v48->cache_dirty;
    int v387 = (4 + ((((int)((unsigned int)((int)((unsigned int)v52 >> 2)) >> 1)) & 3) * 2)) + ((((v198 + ((~(((v200 ^ -1) | (-(v200 ^ -1))) >> 31)) & 2)) - (v202 + ((~(((v204 ^ -1) | (-(v204 ^ -1))) >> 31)) & 2))) >> 31) & 1);
    int v206 = v205[v387];
    bool v388 = !(v206 == 0);
    if (v388) {
      int * v207 = v48->cache_tags;
      int v208 = v207[v387];
      int * v209 = v48->cache_vals;
      int v391 = ((4 + ((((int)((unsigned int)((int)((unsigned int)v52 >> 2)) >> 1)) & 3) * 2)) + ((((v198 + ((~(((v200 ^ -1) | (-(v200 ^ -1))) >> 31)) & 2)) - (v202 + ((~(((v204 ^ -1) | (-(v204 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
      int v210 = v209[v391];
      int * v211 = v48->cache_vals;
      int v393 = (((4 + ((((int)((unsigned int)((int)((unsigned int)v52 >> 2)) >> 1)) & 3) * 2)) + ((((v198 + ((~(((v200 ^ -1) | (-(v200 ^ -1))) >> 31)) & 2)) - (v202 + ((~(((v204 ^ -1) | (-(v204 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
      int v212 = v211[v393];
      int * v213 = v48->mem;
      int v395 = v208 * 2;
      v213[v395] = v210;
      int * v215 = v48->mem;
      int v398 = (v208 * 2) + 1;
      v215[v398] = v212;
      ;
    } else {
      ;
    }
    int * v220 = v48->mem;
    int v403 = ((int)((unsigned int)((int)((unsigned int)v52 >> 2)) >> 1)) * 2;
    int v221 = v220[v403];
    int * v222 = v48->mem;
    int v405 = (((int)((unsigned int)((int)((unsigned int)v52 >> 2)) >> 1)) * 2) + 1;
    int v223 = v222[v405];
    int * v224 = v48->cache_vals;
    int v407 = ((4 + ((((int)((unsigned int)((int)((unsigned int)v52 >> 2)) >> 1)) & 3) * 2)) + ((((v198 + ((~(((v200 ^ -1) | (-(v200 ^ -1))) >> 31)) & 2)) - (v202 + ((~(((v204 ^ -1) | (-(v204 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
    v224[v407] = v221;
    int * v226 = v48->cache_vals;
    int v410 = (((4 + ((((int)((unsigned int)((int)((unsigned int)v52 >> 2)) >> 1)) & 3) * 2)) + ((((v198 + ((~(((v200 ^ -1) | (-(v200 ^ -1))) >> 31)) & 2)) - (v202 + ((~(((v204 ^ -1) | (-(v204 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
    v226[v410] = v223;
    int * v228 = v48->cache_tags;
    int v413 = (int)((unsigned int)((int)((unsigned int)v52 >> 2)) >> 1);
    v228[v387] = v413;
    int * v230 = v48->cache_dirty;
    v230[v387] = 0;
    int * v232 = v48->cache_age;
    v232[v387] = 1;
    int * v234 = v48->cache_age;
    int v235 = v234[v387];
    int * v236 = v48->cache_age;
    int v237 = v236[v264];
    int * v238 = v48->cache_age;
    int v421 = v237 + ((int)((unsigned int)(v237 - v235) >> 31));
    v238[v264] = v421;
    int * v240 = v48->cache_age;
    int v241 = v240[v266];
    int * v242 = v48->cache_age;
    int v424 = v241 + ((int)((unsigned int)(v241 - v235) >> 31));
    v242[v266] = v424;
    int * v244 = v48->cache_age;
    v244[v387] = 0;
    v247 = v387;
  }
  int * v248 = v48->cache_vals;
  int v427 = (v247 * 2) + (((int)((unsigned int)v52 >> 2)) & 1);
  v248[v427] = v54;
  int * v250 = v48->cache_dirty;
  v250[v247] = 1;
  struct StateT * v252 = slot_4(v48);
  return v252;
}

struct StateT * slot_0(struct StateT * v2) {
  int v3 = v2->timer;
  int v11 = v3 + 1;
  v2->timer = v11;
  int * v5 = v2->regs;
  int v6 = v5[10];
  int * v7 = v2->regs;
  int v16 = v6 & 28;
  v7[6] = v16;
  struct StateT * v9 = slot_1(v2);
  return v9;
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