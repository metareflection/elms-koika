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
struct StateT * slot_8(struct StateT * v734);
struct StateT * slot_6(struct StateT * v468);
struct StateT * slot_5(struct StateT * v83);
struct StateT * slot_4(struct StateT * v70);
struct StateT * slot_2(struct StateT * v32);
struct StateT * slot_7(struct StateT * v718);
struct StateT * slot_3(struct StateT * v53);
struct StateT * slot_0(struct StateT * v2);
struct StateT * snippet(struct StateT * v0) {
  struct StateT * v1 = slot_0(v0);
  return v1;
}

struct StateT * slot_1(struct StateT * v19) {
  int v20 = v19->timer;
  int v26 = v20 + 1;
  v19->timer = v26;
  int * v22 = v19->regs;
  v22[9] = 32;
  struct StateT * v24 = slot_2(v19);
  return v24;
}

struct StateT * slot_8(struct StateT * v734) {
  int v735 = v734->timer;
  int v867 = v735 + 1;
  v734->timer = v867;
  int * v737 = v734->regs;
  int v738 = v737[11];
  int * v739 = v734->cache_tags;
  int v871 = (((int)((unsigned int)((int)((unsigned int)v738 >> 2)) >> 1)) & 1) * 2;
  int v740 = v739[v871];
  int * v741 = v734->cache_tags;
  int v873 = ((((int)((unsigned int)((int)((unsigned int)v738 >> 2)) >> 1)) & 1) * 2) + 1;
  int v742 = v741[v873];
  int * v743 = v734->cache_tags;
  int v875 = 4 + ((((int)((unsigned int)((int)((unsigned int)v738 >> 2)) >> 1)) & 3) * 2);
  int v744 = v743[v875];
  int * v745 = v734->cache_tags;
  int v877 = (4 + ((((int)((unsigned int)((int)((unsigned int)v738 >> 2)) >> 1)) & 3) * 2)) + 1;
  int v746 = v745[v877];
  int v747 = v734->timer;
  int v878 = v747 + ((100 ^ (((~(((v744 ^ ((int)((unsigned int)((int)((unsigned int)v738 >> 2)) >> 1))) | (-(v744 ^ ((int)((unsigned int)((int)((unsigned int)v738 >> 2)) >> 1))))) >> 31)) | (~(((v746 ^ ((int)((unsigned int)((int)((unsigned int)v738 >> 2)) >> 1))) | (-(v746 ^ ((int)((unsigned int)((int)((unsigned int)v738 >> 2)) >> 1))))) >> 31))) & 104)) ^ (((~(((v740 ^ ((int)((unsigned int)((int)((unsigned int)v738 >> 2)) >> 1))) | (-(v740 ^ ((int)((unsigned int)((int)((unsigned int)v738 >> 2)) >> 1))))) >> 31)) | (~(((v742 ^ ((int)((unsigned int)((int)((unsigned int)v738 >> 2)) >> 1))) | (-(v742 ^ ((int)((unsigned int)((int)((unsigned int)v738 >> 2)) >> 1))))) >> 31))) & (1 ^ (100 ^ (((~(((v744 ^ ((int)((unsigned int)((int)((unsigned int)v738 >> 2)) >> 1))) | (-(v744 ^ ((int)((unsigned int)((int)((unsigned int)v738 >> 2)) >> 1))))) >> 31)) | (~(((v746 ^ ((int)((unsigned int)((int)((unsigned int)v738 >> 2)) >> 1))) | (-(v746 ^ ((int)((unsigned int)((int)((unsigned int)v738 >> 2)) >> 1))))) >> 31))) & 104)))));
  v734->timer = v878;
  int * v749 = v734->cache_vals;
  bool v879 = !(((~(((v740 ^ ((int)((unsigned int)((int)((unsigned int)v738 >> 2)) >> 1))) | (-(v740 ^ ((int)((unsigned int)((int)((unsigned int)v738 >> 2)) >> 1))))) >> 31)) | (~(((v742 ^ ((int)((unsigned int)((int)((unsigned int)v738 >> 2)) >> 1))) | (-(v742 ^ ((int)((unsigned int)((int)((unsigned int)v738 >> 2)) >> 1))))) >> 31))) == 0);
  int v862;
  if (v879) {
    int * v750 = v734->cache_age;
    int v881 = ((((int)((unsigned int)((int)((unsigned int)v738 >> 2)) >> 1)) & 1) * 2) + ((~(((v742 ^ ((int)((unsigned int)((int)((unsigned int)v738 >> 2)) >> 1))) | (-(v742 ^ ((int)((unsigned int)((int)((unsigned int)v738 >> 2)) >> 1))))) >> 31)) & 1);
    int v751 = v750[v881];
    int * v752 = v734->cache_age;
    int v753 = v752[v871];
    int * v754 = v734->cache_age;
    int v884 = v753 + ((int)((unsigned int)(v753 - v751) >> 31));
    v754[v871] = v884;
    int * v756 = v734->cache_age;
    int v757 = v756[v873];
    int * v758 = v734->cache_age;
    int v887 = v757 + ((int)((unsigned int)(v757 - v751) >> 31));
    v758[v873] = v887;
    int * v760 = v734->cache_age;
    v760[v881] = 0;
    v862 = v881;
  } else {
    int * v763 = v734->cache_age;
    int v891 = (((int)((unsigned int)((int)((unsigned int)v738 >> 2)) >> 1)) & 1) * 2;
    int v764 = v763[v891];
    int * v765 = v734->cache_tags;
    int v766 = v765[v891];
    int * v767 = v734->cache_age;
    int v768 = v767[v873];
    int * v769 = v734->cache_tags;
    int v770 = v769[v873];
    bool v895 = !(((~(((v744 ^ ((int)((unsigned int)((int)((unsigned int)v738 >> 2)) >> 1))) | (-(v744 ^ ((int)((unsigned int)((int)((unsigned int)v738 >> 2)) >> 1))))) >> 31)) | (~(((v746 ^ ((int)((unsigned int)((int)((unsigned int)v738 >> 2)) >> 1))) | (-(v746 ^ ((int)((unsigned int)((int)((unsigned int)v738 >> 2)) >> 1))))) >> 31))) == 0);
    int v834;
    if (v895) {
      int * v771 = v734->cache_age;
      int v897 = (4 + ((((int)((unsigned int)((int)((unsigned int)v738 >> 2)) >> 1)) & 3) * 2)) + ((~(((v746 ^ ((int)((unsigned int)((int)((unsigned int)v738 >> 2)) >> 1))) | (-(v746 ^ ((int)((unsigned int)((int)((unsigned int)v738 >> 2)) >> 1))))) >> 31)) & 1);
      int v772 = v771[v897];
      int * v773 = v734->cache_age;
      int v774 = v773[v875];
      int * v775 = v734->cache_age;
      int v900 = v774 + ((int)((unsigned int)(v774 - v772) >> 31));
      v775[v875] = v900;
      int * v777 = v734->cache_age;
      int v778 = v777[v877];
      int * v779 = v734->cache_age;
      int v903 = v778 + ((int)((unsigned int)(v778 - v772) >> 31));
      v779[v877] = v903;
      int * v781 = v734->cache_age;
      v781[v897] = 0;
      v834 = v897;
    } else {
      int * v784 = v734->cache_age;
      int v907 = 4 + ((((int)((unsigned int)((int)((unsigned int)v738 >> 2)) >> 1)) & 3) * 2);
      int v785 = v784[v907];
      int * v786 = v734->cache_tags;
      int v787 = v786[v907];
      int * v788 = v734->cache_age;
      int v789 = v788[v877];
      int * v790 = v734->cache_tags;
      int v791 = v790[v877];
      int * v792 = v734->cache_dirty;
      int v912 = (4 + ((((int)((unsigned int)((int)((unsigned int)v738 >> 2)) >> 1)) & 3) * 2)) + ((((v785 + ((~(((v787 ^ -1) | (-(v787 ^ -1))) >> 31)) & 2)) - (v789 + ((~(((v791 ^ -1) | (-(v791 ^ -1))) >> 31)) & 2))) >> 31) & 1);
      int v793 = v792[v912];
      bool v913 = !(v793 == 0);
      if (v913) {
        int * v794 = v734->cache_tags;
        int v795 = v794[v912];
        int * v796 = v734->cache_vals;
        int v916 = ((4 + ((((int)((unsigned int)((int)((unsigned int)v738 >> 2)) >> 1)) & 3) * 2)) + ((((v785 + ((~(((v787 ^ -1) | (-(v787 ^ -1))) >> 31)) & 2)) - (v789 + ((~(((v791 ^ -1) | (-(v791 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
        int v797 = v796[v916];
        int * v798 = v734->cache_vals;
        int v918 = (((4 + ((((int)((unsigned int)((int)((unsigned int)v738 >> 2)) >> 1)) & 3) * 2)) + ((((v785 + ((~(((v787 ^ -1) | (-(v787 ^ -1))) >> 31)) & 2)) - (v789 + ((~(((v791 ^ -1) | (-(v791 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
        int v799 = v798[v918];
        int * v800 = v734->mem;
        int v920 = v795 * 2;
        v800[v920] = v797;
        int * v802 = v734->mem;
        int v923 = (v795 * 2) + 1;
        v802[v923] = v799;
        ;
      } else {
        ;
      }
      int * v807 = v734->mem;
      int v928 = ((int)((unsigned int)((int)((unsigned int)v738 >> 2)) >> 1)) * 2;
      int v808 = v807[v928];
      int * v809 = v734->mem;
      int v930 = (((int)((unsigned int)((int)((unsigned int)v738 >> 2)) >> 1)) * 2) + 1;
      int v810 = v809[v930];
      int * v811 = v734->cache_vals;
      int v932 = ((4 + ((((int)((unsigned int)((int)((unsigned int)v738 >> 2)) >> 1)) & 3) * 2)) + ((((v785 + ((~(((v787 ^ -1) | (-(v787 ^ -1))) >> 31)) & 2)) - (v789 + ((~(((v791 ^ -1) | (-(v791 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
      v811[v932] = v808;
      int * v813 = v734->cache_vals;
      int v935 = (((4 + ((((int)((unsigned int)((int)((unsigned int)v738 >> 2)) >> 1)) & 3) * 2)) + ((((v785 + ((~(((v787 ^ -1) | (-(v787 ^ -1))) >> 31)) & 2)) - (v789 + ((~(((v791 ^ -1) | (-(v791 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
      v813[v935] = v810;
      int * v815 = v734->cache_tags;
      int v938 = (int)((unsigned int)((int)((unsigned int)v738 >> 2)) >> 1);
      v815[v912] = v938;
      int * v817 = v734->cache_dirty;
      v817[v912] = 0;
      int * v819 = v734->cache_age;
      v819[v912] = 1;
      int * v821 = v734->cache_age;
      int v822 = v821[v912];
      int * v823 = v734->cache_age;
      int v824 = v823[v875];
      int * v825 = v734->cache_age;
      int v946 = v824 + ((int)((unsigned int)(v824 - v822) >> 31));
      v825[v875] = v946;
      int * v827 = v734->cache_age;
      int v828 = v827[v877];
      int * v829 = v734->cache_age;
      int v949 = v828 + ((int)((unsigned int)(v828 - v822) >> 31));
      v829[v877] = v949;
      int * v831 = v734->cache_age;
      v831[v912] = 0;
      v834 = v912;
    }
    int * v835 = v734->cache_vals;
    int v952 = v834 * 2;
    int v836 = v835[v952];
    int * v837 = v734->cache_vals;
    int v954 = (v834 * 2) + 1;
    int v838 = v837[v954];
    int * v839 = v734->cache_vals;
    int v956 = (((((int)((unsigned int)((int)((unsigned int)v738 >> 2)) >> 1)) & 1) * 2) + ((((v764 + ((~(((v766 ^ -1) | (-(v766 ^ -1))) >> 31)) & 2)) - (v768 + ((~(((v770 ^ -1) | (-(v770 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
    v839[v956] = v836;
    int * v841 = v734->cache_vals;
    int v959 = ((((((int)((unsigned int)((int)((unsigned int)v738 >> 2)) >> 1)) & 1) * 2) + ((((v764 + ((~(((v766 ^ -1) | (-(v766 ^ -1))) >> 31)) & 2)) - (v768 + ((~(((v770 ^ -1) | (-(v770 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
    v841[v959] = v838;
    int * v843 = v734->cache_tags;
    int v962 = ((((int)((unsigned int)((int)((unsigned int)v738 >> 2)) >> 1)) & 1) * 2) + ((((v764 + ((~(((v766 ^ -1) | (-(v766 ^ -1))) >> 31)) & 2)) - (v768 + ((~(((v770 ^ -1) | (-(v770 ^ -1))) >> 31)) & 2))) >> 31) & 1);
    int v963 = (int)((unsigned int)((int)((unsigned int)v738 >> 2)) >> 1);
    v843[v962] = v963;
    int * v845 = v734->cache_dirty;
    v845[v962] = 0;
    int * v847 = v734->cache_age;
    v847[v962] = 1;
    int * v849 = v734->cache_age;
    int v850 = v849[v962];
    int * v851 = v734->cache_age;
    int v852 = v851[v871];
    int * v853 = v734->cache_age;
    int v971 = v852 + ((int)((unsigned int)(v852 - v850) >> 31));
    v853[v871] = v971;
    int * v855 = v734->cache_age;
    int v856 = v855[v873];
    int * v857 = v734->cache_age;
    int v974 = v856 + ((int)((unsigned int)(v856 - v850) >> 31));
    v857[v873] = v974;
    int * v859 = v734->cache_age;
    v859[v962] = 0;
    v862 = v962;
  }
  int v977 = (v862 * 2) + (((int)((unsigned int)v738 >> 2)) & 1);
  int v863 = v749[v977];
  int * v864 = v734->regs;
  v864[12] = v863;
  return v734;
}

struct StateT * slot_6(struct StateT * v468) {
  int v469 = v468->timer;
  int v602 = v469 + 1;
  v468->timer = v602;
  int * v471 = v468->regs;
  int v472 = v471[6];
  int * v473 = v468->cache_tags;
  int v606 = (((int)((unsigned int)((int)((unsigned int)v472 >> 2)) >> 1)) & 1) * 2;
  int v474 = v473[v606];
  int * v475 = v468->cache_tags;
  int v608 = ((((int)((unsigned int)((int)((unsigned int)v472 >> 2)) >> 1)) & 1) * 2) + 1;
  int v476 = v475[v608];
  int * v477 = v468->cache_tags;
  int v610 = 4 + ((((int)((unsigned int)((int)((unsigned int)v472 >> 2)) >> 1)) & 3) * 2);
  int v478 = v477[v610];
  int * v479 = v468->cache_tags;
  int v612 = (4 + ((((int)((unsigned int)((int)((unsigned int)v472 >> 2)) >> 1)) & 3) * 2)) + 1;
  int v480 = v479[v612];
  int v481 = v468->timer;
  int v613 = v481 + ((100 ^ (((~(((v478 ^ ((int)((unsigned int)((int)((unsigned int)v472 >> 2)) >> 1))) | (-(v478 ^ ((int)((unsigned int)((int)((unsigned int)v472 >> 2)) >> 1))))) >> 31)) | (~(((v480 ^ ((int)((unsigned int)((int)((unsigned int)v472 >> 2)) >> 1))) | (-(v480 ^ ((int)((unsigned int)((int)((unsigned int)v472 >> 2)) >> 1))))) >> 31))) & 104)) ^ (((~(((v474 ^ ((int)((unsigned int)((int)((unsigned int)v472 >> 2)) >> 1))) | (-(v474 ^ ((int)((unsigned int)((int)((unsigned int)v472 >> 2)) >> 1))))) >> 31)) | (~(((v476 ^ ((int)((unsigned int)((int)((unsigned int)v472 >> 2)) >> 1))) | (-(v476 ^ ((int)((unsigned int)((int)((unsigned int)v472 >> 2)) >> 1))))) >> 31))) & (1 ^ (100 ^ (((~(((v478 ^ ((int)((unsigned int)((int)((unsigned int)v472 >> 2)) >> 1))) | (-(v478 ^ ((int)((unsigned int)((int)((unsigned int)v472 >> 2)) >> 1))))) >> 31)) | (~(((v480 ^ ((int)((unsigned int)((int)((unsigned int)v472 >> 2)) >> 1))) | (-(v480 ^ ((int)((unsigned int)((int)((unsigned int)v472 >> 2)) >> 1))))) >> 31))) & 104)))));
  v468->timer = v613;
  int * v483 = v468->cache_vals;
  bool v614 = !(((~(((v474 ^ ((int)((unsigned int)((int)((unsigned int)v472 >> 2)) >> 1))) | (-(v474 ^ ((int)((unsigned int)((int)((unsigned int)v472 >> 2)) >> 1))))) >> 31)) | (~(((v476 ^ ((int)((unsigned int)((int)((unsigned int)v472 >> 2)) >> 1))) | (-(v476 ^ ((int)((unsigned int)((int)((unsigned int)v472 >> 2)) >> 1))))) >> 31))) == 0);
  int v596;
  if (v614) {
    int * v484 = v468->cache_age;
    int v616 = ((((int)((unsigned int)((int)((unsigned int)v472 >> 2)) >> 1)) & 1) * 2) + ((~(((v476 ^ ((int)((unsigned int)((int)((unsigned int)v472 >> 2)) >> 1))) | (-(v476 ^ ((int)((unsigned int)((int)((unsigned int)v472 >> 2)) >> 1))))) >> 31)) & 1);
    int v485 = v484[v616];
    int * v486 = v468->cache_age;
    int v487 = v486[v606];
    int * v488 = v468->cache_age;
    int v619 = v487 + ((int)((unsigned int)(v487 - v485) >> 31));
    v488[v606] = v619;
    int * v490 = v468->cache_age;
    int v491 = v490[v608];
    int * v492 = v468->cache_age;
    int v622 = v491 + ((int)((unsigned int)(v491 - v485) >> 31));
    v492[v608] = v622;
    int * v494 = v468->cache_age;
    v494[v616] = 0;
    v596 = v616;
  } else {
    int * v497 = v468->cache_age;
    int v626 = (((int)((unsigned int)((int)((unsigned int)v472 >> 2)) >> 1)) & 1) * 2;
    int v498 = v497[v626];
    int * v499 = v468->cache_tags;
    int v500 = v499[v626];
    int * v501 = v468->cache_age;
    int v502 = v501[v608];
    int * v503 = v468->cache_tags;
    int v504 = v503[v608];
    bool v630 = !(((~(((v478 ^ ((int)((unsigned int)((int)((unsigned int)v472 >> 2)) >> 1))) | (-(v478 ^ ((int)((unsigned int)((int)((unsigned int)v472 >> 2)) >> 1))))) >> 31)) | (~(((v480 ^ ((int)((unsigned int)((int)((unsigned int)v472 >> 2)) >> 1))) | (-(v480 ^ ((int)((unsigned int)((int)((unsigned int)v472 >> 2)) >> 1))))) >> 31))) == 0);
    int v568;
    if (v630) {
      int * v505 = v468->cache_age;
      int v632 = (4 + ((((int)((unsigned int)((int)((unsigned int)v472 >> 2)) >> 1)) & 3) * 2)) + ((~(((v480 ^ ((int)((unsigned int)((int)((unsigned int)v472 >> 2)) >> 1))) | (-(v480 ^ ((int)((unsigned int)((int)((unsigned int)v472 >> 2)) >> 1))))) >> 31)) & 1);
      int v506 = v505[v632];
      int * v507 = v468->cache_age;
      int v508 = v507[v610];
      int * v509 = v468->cache_age;
      int v635 = v508 + ((int)((unsigned int)(v508 - v506) >> 31));
      v509[v610] = v635;
      int * v511 = v468->cache_age;
      int v512 = v511[v612];
      int * v513 = v468->cache_age;
      int v638 = v512 + ((int)((unsigned int)(v512 - v506) >> 31));
      v513[v612] = v638;
      int * v515 = v468->cache_age;
      v515[v632] = 0;
      v568 = v632;
    } else {
      int * v518 = v468->cache_age;
      int v642 = 4 + ((((int)((unsigned int)((int)((unsigned int)v472 >> 2)) >> 1)) & 3) * 2);
      int v519 = v518[v642];
      int * v520 = v468->cache_tags;
      int v521 = v520[v642];
      int * v522 = v468->cache_age;
      int v523 = v522[v612];
      int * v524 = v468->cache_tags;
      int v525 = v524[v612];
      int * v526 = v468->cache_dirty;
      int v647 = (4 + ((((int)((unsigned int)((int)((unsigned int)v472 >> 2)) >> 1)) & 3) * 2)) + ((((v519 + ((~(((v521 ^ -1) | (-(v521 ^ -1))) >> 31)) & 2)) - (v523 + ((~(((v525 ^ -1) | (-(v525 ^ -1))) >> 31)) & 2))) >> 31) & 1);
      int v527 = v526[v647];
      bool v648 = !(v527 == 0);
      if (v648) {
        int * v528 = v468->cache_tags;
        int v529 = v528[v647];
        int * v530 = v468->cache_vals;
        int v651 = ((4 + ((((int)((unsigned int)((int)((unsigned int)v472 >> 2)) >> 1)) & 3) * 2)) + ((((v519 + ((~(((v521 ^ -1) | (-(v521 ^ -1))) >> 31)) & 2)) - (v523 + ((~(((v525 ^ -1) | (-(v525 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
        int v531 = v530[v651];
        int * v532 = v468->cache_vals;
        int v653 = (((4 + ((((int)((unsigned int)((int)((unsigned int)v472 >> 2)) >> 1)) & 3) * 2)) + ((((v519 + ((~(((v521 ^ -1) | (-(v521 ^ -1))) >> 31)) & 2)) - (v523 + ((~(((v525 ^ -1) | (-(v525 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
        int v533 = v532[v653];
        int * v534 = v468->mem;
        int v655 = v529 * 2;
        v534[v655] = v531;
        int * v536 = v468->mem;
        int v658 = (v529 * 2) + 1;
        v536[v658] = v533;
        ;
      } else {
        ;
      }
      int * v541 = v468->mem;
      int v663 = ((int)((unsigned int)((int)((unsigned int)v472 >> 2)) >> 1)) * 2;
      int v542 = v541[v663];
      int * v543 = v468->mem;
      int v665 = (((int)((unsigned int)((int)((unsigned int)v472 >> 2)) >> 1)) * 2) + 1;
      int v544 = v543[v665];
      int * v545 = v468->cache_vals;
      int v667 = ((4 + ((((int)((unsigned int)((int)((unsigned int)v472 >> 2)) >> 1)) & 3) * 2)) + ((((v519 + ((~(((v521 ^ -1) | (-(v521 ^ -1))) >> 31)) & 2)) - (v523 + ((~(((v525 ^ -1) | (-(v525 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
      v545[v667] = v542;
      int * v547 = v468->cache_vals;
      int v670 = (((4 + ((((int)((unsigned int)((int)((unsigned int)v472 >> 2)) >> 1)) & 3) * 2)) + ((((v519 + ((~(((v521 ^ -1) | (-(v521 ^ -1))) >> 31)) & 2)) - (v523 + ((~(((v525 ^ -1) | (-(v525 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
      v547[v670] = v544;
      int * v549 = v468->cache_tags;
      int v673 = (int)((unsigned int)((int)((unsigned int)v472 >> 2)) >> 1);
      v549[v647] = v673;
      int * v551 = v468->cache_dirty;
      v551[v647] = 0;
      int * v553 = v468->cache_age;
      v553[v647] = 1;
      int * v555 = v468->cache_age;
      int v556 = v555[v647];
      int * v557 = v468->cache_age;
      int v558 = v557[v610];
      int * v559 = v468->cache_age;
      int v681 = v558 + ((int)((unsigned int)(v558 - v556) >> 31));
      v559[v610] = v681;
      int * v561 = v468->cache_age;
      int v562 = v561[v612];
      int * v563 = v468->cache_age;
      int v684 = v562 + ((int)((unsigned int)(v562 - v556) >> 31));
      v563[v612] = v684;
      int * v565 = v468->cache_age;
      v565[v647] = 0;
      v568 = v647;
    }
    int * v569 = v468->cache_vals;
    int v687 = v568 * 2;
    int v570 = v569[v687];
    int * v571 = v468->cache_vals;
    int v689 = (v568 * 2) + 1;
    int v572 = v571[v689];
    int * v573 = v468->cache_vals;
    int v691 = (((((int)((unsigned int)((int)((unsigned int)v472 >> 2)) >> 1)) & 1) * 2) + ((((v498 + ((~(((v500 ^ -1) | (-(v500 ^ -1))) >> 31)) & 2)) - (v502 + ((~(((v504 ^ -1) | (-(v504 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
    v573[v691] = v570;
    int * v575 = v468->cache_vals;
    int v694 = ((((((int)((unsigned int)((int)((unsigned int)v472 >> 2)) >> 1)) & 1) * 2) + ((((v498 + ((~(((v500 ^ -1) | (-(v500 ^ -1))) >> 31)) & 2)) - (v502 + ((~(((v504 ^ -1) | (-(v504 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
    v575[v694] = v572;
    int * v577 = v468->cache_tags;
    int v697 = ((((int)((unsigned int)((int)((unsigned int)v472 >> 2)) >> 1)) & 1) * 2) + ((((v498 + ((~(((v500 ^ -1) | (-(v500 ^ -1))) >> 31)) & 2)) - (v502 + ((~(((v504 ^ -1) | (-(v504 ^ -1))) >> 31)) & 2))) >> 31) & 1);
    int v698 = (int)((unsigned int)((int)((unsigned int)v472 >> 2)) >> 1);
    v577[v697] = v698;
    int * v579 = v468->cache_dirty;
    v579[v697] = 0;
    int * v581 = v468->cache_age;
    v581[v697] = 1;
    int * v583 = v468->cache_age;
    int v584 = v583[v697];
    int * v585 = v468->cache_age;
    int v586 = v585[v606];
    int * v587 = v468->cache_age;
    int v706 = v586 + ((int)((unsigned int)(v586 - v584) >> 31));
    v587[v606] = v706;
    int * v589 = v468->cache_age;
    int v590 = v589[v608];
    int * v591 = v468->cache_age;
    int v709 = v590 + ((int)((unsigned int)(v590 - v584) >> 31));
    v591[v608] = v709;
    int * v593 = v468->cache_age;
    v593[v697] = 0;
    v596 = v697;
  }
  int v712 = (v596 * 2) + (((int)((unsigned int)v472 >> 2)) & 1);
  int v597 = v483[v712];
  int * v598 = v468->regs;
  v598[11] = v597;
  struct StateT * v600 = slot_7(v468);
  return v600;
}

struct StateT * slot_5(struct StateT * v83) {
  int v84 = v83->timer;
  int v289 = v84 + 1;
  v83->timer = v289;
  int * v86 = v83->regs;
  int v87 = v86[6];
  int * v88 = v83->regs;
  int v89 = v88[7];
  int * v90 = v83->cache_tags;
  int v295 = (((int)((unsigned int)((int)((unsigned int)v87 >> 2)) >> 1)) & 1) * 2;
  int v91 = v90[v295];
  int * v92 = v83->cache_tags;
  int v297 = ((((int)((unsigned int)((int)((unsigned int)v87 >> 2)) >> 1)) & 1) * 2) + 1;
  int v93 = v92[v297];
  int * v94 = v83->cache_tags;
  int v299 = 4 + ((((int)((unsigned int)((int)((unsigned int)v87 >> 2)) >> 1)) & 3) * 2);
  int v95 = v94[v299];
  int * v96 = v83->cache_tags;
  int v301 = (4 + ((((int)((unsigned int)((int)((unsigned int)v87 >> 2)) >> 1)) & 3) * 2)) + 1;
  int v97 = v96[v301];
  int v98 = v83->timer;
  int v302 = v98 + ((100 ^ (((~(((v95 ^ ((int)((unsigned int)((int)((unsigned int)v87 >> 2)) >> 1))) | (-(v95 ^ ((int)((unsigned int)((int)((unsigned int)v87 >> 2)) >> 1))))) >> 31)) | (~(((v97 ^ ((int)((unsigned int)((int)((unsigned int)v87 >> 2)) >> 1))) | (-(v97 ^ ((int)((unsigned int)((int)((unsigned int)v87 >> 2)) >> 1))))) >> 31))) & 104)) ^ (((~(((v91 ^ ((int)((unsigned int)((int)((unsigned int)v87 >> 2)) >> 1))) | (-(v91 ^ ((int)((unsigned int)((int)((unsigned int)v87 >> 2)) >> 1))))) >> 31)) | (~(((v93 ^ ((int)((unsigned int)((int)((unsigned int)v87 >> 2)) >> 1))) | (-(v93 ^ ((int)((unsigned int)((int)((unsigned int)v87 >> 2)) >> 1))))) >> 31))) & (1 ^ (100 ^ (((~(((v95 ^ ((int)((unsigned int)((int)((unsigned int)v87 >> 2)) >> 1))) | (-(v95 ^ ((int)((unsigned int)((int)((unsigned int)v87 >> 2)) >> 1))))) >> 31)) | (~(((v97 ^ ((int)((unsigned int)((int)((unsigned int)v87 >> 2)) >> 1))) | (-(v97 ^ ((int)((unsigned int)((int)((unsigned int)v87 >> 2)) >> 1))))) >> 31))) & 104)))));
  v83->timer = v302;
  bool v303 = !(((~(((v91 ^ ((int)((unsigned int)((int)((unsigned int)v87 >> 2)) >> 1))) | (-(v91 ^ ((int)((unsigned int)((int)((unsigned int)v87 >> 2)) >> 1))))) >> 31)) | (~(((v93 ^ ((int)((unsigned int)((int)((unsigned int)v87 >> 2)) >> 1))) | (-(v93 ^ ((int)((unsigned int)((int)((unsigned int)v87 >> 2)) >> 1))))) >> 31))) == 0);
  int v212;
  if (v303) {
    int * v100 = v83->cache_age;
    int v305 = ((((int)((unsigned int)((int)((unsigned int)v87 >> 2)) >> 1)) & 1) * 2) + ((~(((v93 ^ ((int)((unsigned int)((int)((unsigned int)v87 >> 2)) >> 1))) | (-(v93 ^ ((int)((unsigned int)((int)((unsigned int)v87 >> 2)) >> 1))))) >> 31)) & 1);
    int v101 = v100[v305];
    int * v102 = v83->cache_age;
    int v103 = v102[v295];
    int * v104 = v83->cache_age;
    int v308 = v103 + ((int)((unsigned int)(v103 - v101) >> 31));
    v104[v295] = v308;
    int * v106 = v83->cache_age;
    int v107 = v106[v297];
    int * v108 = v83->cache_age;
    int v311 = v107 + ((int)((unsigned int)(v107 - v101) >> 31));
    v108[v297] = v311;
    int * v110 = v83->cache_age;
    v110[v305] = 0;
    v212 = v305;
  } else {
    int * v113 = v83->cache_age;
    int v315 = (((int)((unsigned int)((int)((unsigned int)v87 >> 2)) >> 1)) & 1) * 2;
    int v114 = v113[v315];
    int * v115 = v83->cache_tags;
    int v116 = v115[v315];
    int * v117 = v83->cache_age;
    int v118 = v117[v297];
    int * v119 = v83->cache_tags;
    int v120 = v119[v297];
    bool v319 = !(((~(((v95 ^ ((int)((unsigned int)((int)((unsigned int)v87 >> 2)) >> 1))) | (-(v95 ^ ((int)((unsigned int)((int)((unsigned int)v87 >> 2)) >> 1))))) >> 31)) | (~(((v97 ^ ((int)((unsigned int)((int)((unsigned int)v87 >> 2)) >> 1))) | (-(v97 ^ ((int)((unsigned int)((int)((unsigned int)v87 >> 2)) >> 1))))) >> 31))) == 0);
    int v184;
    if (v319) {
      int * v121 = v83->cache_age;
      int v321 = (4 + ((((int)((unsigned int)((int)((unsigned int)v87 >> 2)) >> 1)) & 3) * 2)) + ((~(((v97 ^ ((int)((unsigned int)((int)((unsigned int)v87 >> 2)) >> 1))) | (-(v97 ^ ((int)((unsigned int)((int)((unsigned int)v87 >> 2)) >> 1))))) >> 31)) & 1);
      int v122 = v121[v321];
      int * v123 = v83->cache_age;
      int v124 = v123[v299];
      int * v125 = v83->cache_age;
      int v324 = v124 + ((int)((unsigned int)(v124 - v122) >> 31));
      v125[v299] = v324;
      int * v127 = v83->cache_age;
      int v128 = v127[v301];
      int * v129 = v83->cache_age;
      int v327 = v128 + ((int)((unsigned int)(v128 - v122) >> 31));
      v129[v301] = v327;
      int * v131 = v83->cache_age;
      v131[v321] = 0;
      v184 = v321;
    } else {
      int * v134 = v83->cache_age;
      int v331 = 4 + ((((int)((unsigned int)((int)((unsigned int)v87 >> 2)) >> 1)) & 3) * 2);
      int v135 = v134[v331];
      int * v136 = v83->cache_tags;
      int v137 = v136[v331];
      int * v138 = v83->cache_age;
      int v139 = v138[v301];
      int * v140 = v83->cache_tags;
      int v141 = v140[v301];
      int * v142 = v83->cache_dirty;
      int v336 = (4 + ((((int)((unsigned int)((int)((unsigned int)v87 >> 2)) >> 1)) & 3) * 2)) + ((((v135 + ((~(((v137 ^ -1) | (-(v137 ^ -1))) >> 31)) & 2)) - (v139 + ((~(((v141 ^ -1) | (-(v141 ^ -1))) >> 31)) & 2))) >> 31) & 1);
      int v143 = v142[v336];
      bool v337 = !(v143 == 0);
      if (v337) {
        int * v144 = v83->cache_tags;
        int v145 = v144[v336];
        int * v146 = v83->cache_vals;
        int v340 = ((4 + ((((int)((unsigned int)((int)((unsigned int)v87 >> 2)) >> 1)) & 3) * 2)) + ((((v135 + ((~(((v137 ^ -1) | (-(v137 ^ -1))) >> 31)) & 2)) - (v139 + ((~(((v141 ^ -1) | (-(v141 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
        int v147 = v146[v340];
        int * v148 = v83->cache_vals;
        int v342 = (((4 + ((((int)((unsigned int)((int)((unsigned int)v87 >> 2)) >> 1)) & 3) * 2)) + ((((v135 + ((~(((v137 ^ -1) | (-(v137 ^ -1))) >> 31)) & 2)) - (v139 + ((~(((v141 ^ -1) | (-(v141 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
        int v149 = v148[v342];
        int * v150 = v83->mem;
        int v344 = v145 * 2;
        v150[v344] = v147;
        int * v152 = v83->mem;
        int v347 = (v145 * 2) + 1;
        v152[v347] = v149;
        ;
      } else {
        ;
      }
      int * v157 = v83->mem;
      int v352 = ((int)((unsigned int)((int)((unsigned int)v87 >> 2)) >> 1)) * 2;
      int v158 = v157[v352];
      int * v159 = v83->mem;
      int v354 = (((int)((unsigned int)((int)((unsigned int)v87 >> 2)) >> 1)) * 2) + 1;
      int v160 = v159[v354];
      int * v161 = v83->cache_vals;
      int v356 = ((4 + ((((int)((unsigned int)((int)((unsigned int)v87 >> 2)) >> 1)) & 3) * 2)) + ((((v135 + ((~(((v137 ^ -1) | (-(v137 ^ -1))) >> 31)) & 2)) - (v139 + ((~(((v141 ^ -1) | (-(v141 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
      v161[v356] = v158;
      int * v163 = v83->cache_vals;
      int v359 = (((4 + ((((int)((unsigned int)((int)((unsigned int)v87 >> 2)) >> 1)) & 3) * 2)) + ((((v135 + ((~(((v137 ^ -1) | (-(v137 ^ -1))) >> 31)) & 2)) - (v139 + ((~(((v141 ^ -1) | (-(v141 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
      v163[v359] = v160;
      int * v165 = v83->cache_tags;
      int v362 = (int)((unsigned int)((int)((unsigned int)v87 >> 2)) >> 1);
      v165[v336] = v362;
      int * v167 = v83->cache_dirty;
      v167[v336] = 0;
      int * v169 = v83->cache_age;
      v169[v336] = 1;
      int * v171 = v83->cache_age;
      int v172 = v171[v336];
      int * v173 = v83->cache_age;
      int v174 = v173[v299];
      int * v175 = v83->cache_age;
      int v370 = v174 + ((int)((unsigned int)(v174 - v172) >> 31));
      v175[v299] = v370;
      int * v177 = v83->cache_age;
      int v178 = v177[v301];
      int * v179 = v83->cache_age;
      int v373 = v178 + ((int)((unsigned int)(v178 - v172) >> 31));
      v179[v301] = v373;
      int * v181 = v83->cache_age;
      v181[v336] = 0;
      v184 = v336;
    }
    int * v185 = v83->cache_vals;
    int v376 = v184 * 2;
    int v186 = v185[v376];
    int * v187 = v83->cache_vals;
    int v378 = (v184 * 2) + 1;
    int v188 = v187[v378];
    int * v189 = v83->cache_vals;
    int v380 = (((((int)((unsigned int)((int)((unsigned int)v87 >> 2)) >> 1)) & 1) * 2) + ((((v114 + ((~(((v116 ^ -1) | (-(v116 ^ -1))) >> 31)) & 2)) - (v118 + ((~(((v120 ^ -1) | (-(v120 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
    v189[v380] = v186;
    int * v191 = v83->cache_vals;
    int v383 = ((((((int)((unsigned int)((int)((unsigned int)v87 >> 2)) >> 1)) & 1) * 2) + ((((v114 + ((~(((v116 ^ -1) | (-(v116 ^ -1))) >> 31)) & 2)) - (v118 + ((~(((v120 ^ -1) | (-(v120 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
    v191[v383] = v188;
    int * v193 = v83->cache_tags;
    int v386 = ((((int)((unsigned int)((int)((unsigned int)v87 >> 2)) >> 1)) & 1) * 2) + ((((v114 + ((~(((v116 ^ -1) | (-(v116 ^ -1))) >> 31)) & 2)) - (v118 + ((~(((v120 ^ -1) | (-(v120 ^ -1))) >> 31)) & 2))) >> 31) & 1);
    int v387 = (int)((unsigned int)((int)((unsigned int)v87 >> 2)) >> 1);
    v193[v386] = v387;
    int * v195 = v83->cache_dirty;
    v195[v386] = 0;
    int * v197 = v83->cache_age;
    v197[v386] = 1;
    int * v199 = v83->cache_age;
    int v200 = v199[v386];
    int * v201 = v83->cache_age;
    int v202 = v201[v295];
    int * v203 = v83->cache_age;
    int v395 = v202 + ((int)((unsigned int)(v202 - v200) >> 31));
    v203[v295] = v395;
    int * v205 = v83->cache_age;
    int v206 = v205[v297];
    int * v207 = v83->cache_age;
    int v398 = v206 + ((int)((unsigned int)(v206 - v200) >> 31));
    v207[v297] = v398;
    int * v209 = v83->cache_age;
    v209[v386] = 0;
    v212 = v386;
  }
  int * v213 = v83->cache_vals;
  int v401 = (v212 * 2) + (((int)((unsigned int)v87 >> 2)) & 1);
  v213[v401] = v89;
  int * v215 = v83->cache_tags;
  int v216 = v215[v299];
  int * v217 = v83->cache_tags;
  int v218 = v217[v301];
  bool v405 = !(((~(((v216 ^ ((int)((unsigned int)((int)((unsigned int)v87 >> 2)) >> 1))) | (-(v216 ^ ((int)((unsigned int)((int)((unsigned int)v87 >> 2)) >> 1))))) >> 31)) | (~(((v218 ^ ((int)((unsigned int)((int)((unsigned int)v87 >> 2)) >> 1))) | (-(v218 ^ ((int)((unsigned int)((int)((unsigned int)v87 >> 2)) >> 1))))) >> 31))) == 0);
  int v282;
  if (v405) {
    int * v219 = v83->cache_age;
    int v407 = (4 + ((((int)((unsigned int)((int)((unsigned int)v87 >> 2)) >> 1)) & 3) * 2)) + ((~(((v218 ^ ((int)((unsigned int)((int)((unsigned int)v87 >> 2)) >> 1))) | (-(v218 ^ ((int)((unsigned int)((int)((unsigned int)v87 >> 2)) >> 1))))) >> 31)) & 1);
    int v220 = v219[v407];
    int * v221 = v83->cache_age;
    int v222 = v221[v299];
    int * v223 = v83->cache_age;
    int v410 = v222 + ((int)((unsigned int)(v222 - v220) >> 31));
    v223[v299] = v410;
    int * v225 = v83->cache_age;
    int v226 = v225[v301];
    int * v227 = v83->cache_age;
    int v413 = v226 + ((int)((unsigned int)(v226 - v220) >> 31));
    v227[v301] = v413;
    int * v229 = v83->cache_age;
    v229[v407] = 0;
    v282 = v407;
  } else {
    int * v232 = v83->cache_age;
    int v417 = 4 + ((((int)((unsigned int)((int)((unsigned int)v87 >> 2)) >> 1)) & 3) * 2);
    int v233 = v232[v417];
    int * v234 = v83->cache_tags;
    int v235 = v234[v417];
    int * v236 = v83->cache_age;
    int v237 = v236[v301];
    int * v238 = v83->cache_tags;
    int v239 = v238[v301];
    int * v240 = v83->cache_dirty;
    int v422 = (4 + ((((int)((unsigned int)((int)((unsigned int)v87 >> 2)) >> 1)) & 3) * 2)) + ((((v233 + ((~(((v235 ^ -1) | (-(v235 ^ -1))) >> 31)) & 2)) - (v237 + ((~(((v239 ^ -1) | (-(v239 ^ -1))) >> 31)) & 2))) >> 31) & 1);
    int v241 = v240[v422];
    bool v423 = !(v241 == 0);
    if (v423) {
      int * v242 = v83->cache_tags;
      int v243 = v242[v422];
      int * v244 = v83->cache_vals;
      int v426 = ((4 + ((((int)((unsigned int)((int)((unsigned int)v87 >> 2)) >> 1)) & 3) * 2)) + ((((v233 + ((~(((v235 ^ -1) | (-(v235 ^ -1))) >> 31)) & 2)) - (v237 + ((~(((v239 ^ -1) | (-(v239 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
      int v245 = v244[v426];
      int * v246 = v83->cache_vals;
      int v428 = (((4 + ((((int)((unsigned int)((int)((unsigned int)v87 >> 2)) >> 1)) & 3) * 2)) + ((((v233 + ((~(((v235 ^ -1) | (-(v235 ^ -1))) >> 31)) & 2)) - (v237 + ((~(((v239 ^ -1) | (-(v239 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
      int v247 = v246[v428];
      int * v248 = v83->mem;
      int v430 = v243 * 2;
      v248[v430] = v245;
      int * v250 = v83->mem;
      int v433 = (v243 * 2) + 1;
      v250[v433] = v247;
      ;
    } else {
      ;
    }
    int * v255 = v83->mem;
    int v438 = ((int)((unsigned int)((int)((unsigned int)v87 >> 2)) >> 1)) * 2;
    int v256 = v255[v438];
    int * v257 = v83->mem;
    int v440 = (((int)((unsigned int)((int)((unsigned int)v87 >> 2)) >> 1)) * 2) + 1;
    int v258 = v257[v440];
    int * v259 = v83->cache_vals;
    int v442 = ((4 + ((((int)((unsigned int)((int)((unsigned int)v87 >> 2)) >> 1)) & 3) * 2)) + ((((v233 + ((~(((v235 ^ -1) | (-(v235 ^ -1))) >> 31)) & 2)) - (v237 + ((~(((v239 ^ -1) | (-(v239 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
    v259[v442] = v256;
    int * v261 = v83->cache_vals;
    int v445 = (((4 + ((((int)((unsigned int)((int)((unsigned int)v87 >> 2)) >> 1)) & 3) * 2)) + ((((v233 + ((~(((v235 ^ -1) | (-(v235 ^ -1))) >> 31)) & 2)) - (v237 + ((~(((v239 ^ -1) | (-(v239 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
    v261[v445] = v258;
    int * v263 = v83->cache_tags;
    int v448 = (int)((unsigned int)((int)((unsigned int)v87 >> 2)) >> 1);
    v263[v422] = v448;
    int * v265 = v83->cache_dirty;
    v265[v422] = 0;
    int * v267 = v83->cache_age;
    v267[v422] = 1;
    int * v269 = v83->cache_age;
    int v270 = v269[v422];
    int * v271 = v83->cache_age;
    int v272 = v271[v299];
    int * v273 = v83->cache_age;
    int v456 = v272 + ((int)((unsigned int)(v272 - v270) >> 31));
    v273[v299] = v456;
    int * v275 = v83->cache_age;
    int v276 = v275[v301];
    int * v277 = v83->cache_age;
    int v459 = v276 + ((int)((unsigned int)(v276 - v270) >> 31));
    v277[v301] = v459;
    int * v279 = v83->cache_age;
    v279[v422] = 0;
    v282 = v422;
  }
  int * v283 = v83->cache_vals;
  int v462 = (v282 * 2) + (((int)((unsigned int)v87 >> 2)) & 1);
  v283[v462] = v89;
  int * v285 = v83->cache_dirty;
  v285[v282] = 1;
  struct StateT * v287 = slot_6(v83);
  return v287;
}

struct StateT * slot_4(struct StateT * v70) {
  int v71 = v70->timer;
  int v77 = v71 + 1;
  v70->timer = v77;
  int * v73 = v70->regs;
  v73[7] = 0;
  struct StateT * v75 = slot_5(v70);
  return v75;
}

struct StateT * slot_2(struct StateT * v32) {
  int v33 = v32->timer;
  int v44 = v33 + 1;
  v32->timer = v44;
  int * v35 = v32->regs;
  int v36 = v35[5];
  int * v37 = v32->regs;
  int v38 = v37[9];
  bool v49 = v36 >= v38;
  struct StateT * v42;
  if (v49) {
    v42 = v32;
  } else {
    struct StateT * v40 = slot_3(v32);
    v42 = v40;
  }
  return v42;
}

struct StateT * slot_7(struct StateT * v718) {
  int v719 = v718->timer;
  int v727 = v719 + 1;
  v718->timer = v727;
  int * v721 = v718->regs;
  int v722 = v721[11];
  int * v723 = v718->regs;
  int v731 = v722 << 2;
  v723[11] = v731;
  struct StateT * v725 = slot_8(v718);
  return v725;
}

struct StateT * slot_3(struct StateT * v53) {
  int v54 = v53->timer;
  int v62 = v54 + 1;
  v53->timer = v62;
  int * v56 = v53->regs;
  int v57 = v56[5];
  int * v58 = v53->regs;
  int v67 = v57 + 80;
  v58[6] = v67;
  struct StateT * v60 = slot_4(v53);
  return v60;
}

struct StateT * slot_0(struct StateT * v2) {
  int v3 = v2->timer;
  int v11 = v3 + 1;
  v2->timer = v11;
  int * v5 = v2->regs;
  int v6 = v5[10];
  int * v7 = v2->regs;
  int v16 = v6 & 28;
  v7[5] = v16;
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
    s1.mem[SECRET_OFFSET+i] = secret(0, 20);
    s2.mem[SECRET_OFFSET+i] = secret(0, 20);
  }
  struct StateT *s1_ = snippet(&s1);
  struct StateT *s2_ = snippet(&s2);
  koika_assert(s1_->timer==s2_->timer, "timing leak");
  return 0;
}