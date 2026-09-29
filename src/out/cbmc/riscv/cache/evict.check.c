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
struct StateT * slot_1(struct StateT * v240);
struct StateT * slot_6(struct StateT * v760);
struct StateT * slot_5(struct StateT * v523);
struct StateT * slot_4(struct StateT * v289);
struct StateT * slot_2(struct StateT * v257);
struct StateT * slot_7(struct StateT * v1010);
struct StateT * slot_3(struct StateT * v273);
struct StateT * slot_0(struct StateT * v2);
struct StateT * snippet(struct StateT * v0) {
  struct StateT * v1 = slot_0(v0);
  return v1;
}

struct StateT * slot_1(struct StateT * v240) {
  int v241 = v240->timer;
  int v249 = v241 + 1;
  v240->timer = v249;
  int * v243 = v240->regs;
  int v244 = v243[5];
  int * v245 = v240->regs;
  int v254 = v244 & 1;
  v245[6] = v254;
  struct StateT * v247 = slot_2(v240);
  return v247;
}

struct StateT * slot_6(struct StateT * v760) {
  int v761 = v760->timer;
  int v894 = v761 + 1;
  v760->timer = v894;
  int * v763 = v760->regs;
  int v764 = v763[6];
  int * v765 = v760->cache_tags;
  int v898 = (((int)((unsigned int)((int)((unsigned int)v764 >> 2)) >> 1)) & 1) * 2;
  int v766 = v765[v898];
  int * v767 = v760->cache_tags;
  int v900 = ((((int)((unsigned int)((int)((unsigned int)v764 >> 2)) >> 1)) & 1) * 2) + 1;
  int v768 = v767[v900];
  int * v769 = v760->cache_tags;
  int v902 = 4 + ((((int)((unsigned int)((int)((unsigned int)v764 >> 2)) >> 1)) & 3) * 2);
  int v770 = v769[v902];
  int * v771 = v760->cache_tags;
  int v904 = (4 + ((((int)((unsigned int)((int)((unsigned int)v764 >> 2)) >> 1)) & 3) * 2)) + 1;
  int v772 = v771[v904];
  int v773 = v760->timer;
  int v905 = v773 + ((100 ^ (((~(((v770 ^ ((int)((unsigned int)((int)((unsigned int)v764 >> 2)) >> 1))) | (-(v770 ^ ((int)((unsigned int)((int)((unsigned int)v764 >> 2)) >> 1))))) >> 31)) | (~(((v772 ^ ((int)((unsigned int)((int)((unsigned int)v764 >> 2)) >> 1))) | (-(v772 ^ ((int)((unsigned int)((int)((unsigned int)v764 >> 2)) >> 1))))) >> 31))) & 104)) ^ (((~(((v766 ^ ((int)((unsigned int)((int)((unsigned int)v764 >> 2)) >> 1))) | (-(v766 ^ ((int)((unsigned int)((int)((unsigned int)v764 >> 2)) >> 1))))) >> 31)) | (~(((v768 ^ ((int)((unsigned int)((int)((unsigned int)v764 >> 2)) >> 1))) | (-(v768 ^ ((int)((unsigned int)((int)((unsigned int)v764 >> 2)) >> 1))))) >> 31))) & (1 ^ (100 ^ (((~(((v770 ^ ((int)((unsigned int)((int)((unsigned int)v764 >> 2)) >> 1))) | (-(v770 ^ ((int)((unsigned int)((int)((unsigned int)v764 >> 2)) >> 1))))) >> 31)) | (~(((v772 ^ ((int)((unsigned int)((int)((unsigned int)v764 >> 2)) >> 1))) | (-(v772 ^ ((int)((unsigned int)((int)((unsigned int)v764 >> 2)) >> 1))))) >> 31))) & 104)))));
  v760->timer = v905;
  int * v775 = v760->cache_vals;
  bool v906 = !(((~(((v766 ^ ((int)((unsigned int)((int)((unsigned int)v764 >> 2)) >> 1))) | (-(v766 ^ ((int)((unsigned int)((int)((unsigned int)v764 >> 2)) >> 1))))) >> 31)) | (~(((v768 ^ ((int)((unsigned int)((int)((unsigned int)v764 >> 2)) >> 1))) | (-(v768 ^ ((int)((unsigned int)((int)((unsigned int)v764 >> 2)) >> 1))))) >> 31))) == 0);
  int v888;
  if (v906) {
    int * v776 = v760->cache_age;
    int v908 = ((((int)((unsigned int)((int)((unsigned int)v764 >> 2)) >> 1)) & 1) * 2) + ((~(((v768 ^ ((int)((unsigned int)((int)((unsigned int)v764 >> 2)) >> 1))) | (-(v768 ^ ((int)((unsigned int)((int)((unsigned int)v764 >> 2)) >> 1))))) >> 31)) & 1);
    int v777 = v776[v908];
    int * v778 = v760->cache_age;
    int v779 = v778[v898];
    int * v780 = v760->cache_age;
    int v911 = v779 + ((int)((unsigned int)(v779 - v777) >> 31));
    v780[v898] = v911;
    int * v782 = v760->cache_age;
    int v783 = v782[v900];
    int * v784 = v760->cache_age;
    int v914 = v783 + ((int)((unsigned int)(v783 - v777) >> 31));
    v784[v900] = v914;
    int * v786 = v760->cache_age;
    v786[v908] = 0;
    v888 = v908;
  } else {
    int * v789 = v760->cache_age;
    int v918 = (((int)((unsigned int)((int)((unsigned int)v764 >> 2)) >> 1)) & 1) * 2;
    int v790 = v789[v918];
    int * v791 = v760->cache_tags;
    int v792 = v791[v918];
    int * v793 = v760->cache_age;
    int v794 = v793[v900];
    int * v795 = v760->cache_tags;
    int v796 = v795[v900];
    bool v922 = !(((~(((v770 ^ ((int)((unsigned int)((int)((unsigned int)v764 >> 2)) >> 1))) | (-(v770 ^ ((int)((unsigned int)((int)((unsigned int)v764 >> 2)) >> 1))))) >> 31)) | (~(((v772 ^ ((int)((unsigned int)((int)((unsigned int)v764 >> 2)) >> 1))) | (-(v772 ^ ((int)((unsigned int)((int)((unsigned int)v764 >> 2)) >> 1))))) >> 31))) == 0);
    int v860;
    if (v922) {
      int * v797 = v760->cache_age;
      int v924 = (4 + ((((int)((unsigned int)((int)((unsigned int)v764 >> 2)) >> 1)) & 3) * 2)) + ((~(((v772 ^ ((int)((unsigned int)((int)((unsigned int)v764 >> 2)) >> 1))) | (-(v772 ^ ((int)((unsigned int)((int)((unsigned int)v764 >> 2)) >> 1))))) >> 31)) & 1);
      int v798 = v797[v924];
      int * v799 = v760->cache_age;
      int v800 = v799[v902];
      int * v801 = v760->cache_age;
      int v927 = v800 + ((int)((unsigned int)(v800 - v798) >> 31));
      v801[v902] = v927;
      int * v803 = v760->cache_age;
      int v804 = v803[v904];
      int * v805 = v760->cache_age;
      int v930 = v804 + ((int)((unsigned int)(v804 - v798) >> 31));
      v805[v904] = v930;
      int * v807 = v760->cache_age;
      v807[v924] = 0;
      v860 = v924;
    } else {
      int * v810 = v760->cache_age;
      int v934 = 4 + ((((int)((unsigned int)((int)((unsigned int)v764 >> 2)) >> 1)) & 3) * 2);
      int v811 = v810[v934];
      int * v812 = v760->cache_tags;
      int v813 = v812[v934];
      int * v814 = v760->cache_age;
      int v815 = v814[v904];
      int * v816 = v760->cache_tags;
      int v817 = v816[v904];
      int * v818 = v760->cache_dirty;
      int v939 = (4 + ((((int)((unsigned int)((int)((unsigned int)v764 >> 2)) >> 1)) & 3) * 2)) + ((((v811 + ((~(((v813 ^ -1) | (-(v813 ^ -1))) >> 31)) & 2)) - (v815 + ((~(((v817 ^ -1) | (-(v817 ^ -1))) >> 31)) & 2))) >> 31) & 1);
      int v819 = v818[v939];
      bool v940 = !(v819 == 0);
      if (v940) {
        int * v820 = v760->cache_tags;
        int v821 = v820[v939];
        int * v822 = v760->cache_vals;
        int v943 = ((4 + ((((int)((unsigned int)((int)((unsigned int)v764 >> 2)) >> 1)) & 3) * 2)) + ((((v811 + ((~(((v813 ^ -1) | (-(v813 ^ -1))) >> 31)) & 2)) - (v815 + ((~(((v817 ^ -1) | (-(v817 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
        int v823 = v822[v943];
        int * v824 = v760->cache_vals;
        int v945 = (((4 + ((((int)((unsigned int)((int)((unsigned int)v764 >> 2)) >> 1)) & 3) * 2)) + ((((v811 + ((~(((v813 ^ -1) | (-(v813 ^ -1))) >> 31)) & 2)) - (v815 + ((~(((v817 ^ -1) | (-(v817 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
        int v825 = v824[v945];
        int * v826 = v760->mem;
        int v947 = v821 * 2;
        v826[v947] = v823;
        int * v828 = v760->mem;
        int v950 = (v821 * 2) + 1;
        v828[v950] = v825;
        ;
      } else {
        ;
      }
      int * v833 = v760->mem;
      int v955 = ((int)((unsigned int)((int)((unsigned int)v764 >> 2)) >> 1)) * 2;
      int v834 = v833[v955];
      int * v835 = v760->mem;
      int v957 = (((int)((unsigned int)((int)((unsigned int)v764 >> 2)) >> 1)) * 2) + 1;
      int v836 = v835[v957];
      int * v837 = v760->cache_vals;
      int v959 = ((4 + ((((int)((unsigned int)((int)((unsigned int)v764 >> 2)) >> 1)) & 3) * 2)) + ((((v811 + ((~(((v813 ^ -1) | (-(v813 ^ -1))) >> 31)) & 2)) - (v815 + ((~(((v817 ^ -1) | (-(v817 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
      v837[v959] = v834;
      int * v839 = v760->cache_vals;
      int v962 = (((4 + ((((int)((unsigned int)((int)((unsigned int)v764 >> 2)) >> 1)) & 3) * 2)) + ((((v811 + ((~(((v813 ^ -1) | (-(v813 ^ -1))) >> 31)) & 2)) - (v815 + ((~(((v817 ^ -1) | (-(v817 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
      v839[v962] = v836;
      int * v841 = v760->cache_tags;
      int v965 = (int)((unsigned int)((int)((unsigned int)v764 >> 2)) >> 1);
      v841[v939] = v965;
      int * v843 = v760->cache_dirty;
      v843[v939] = 0;
      int * v845 = v760->cache_age;
      v845[v939] = 1;
      int * v847 = v760->cache_age;
      int v848 = v847[v939];
      int * v849 = v760->cache_age;
      int v850 = v849[v902];
      int * v851 = v760->cache_age;
      int v973 = v850 + ((int)((unsigned int)(v850 - v848) >> 31));
      v851[v902] = v973;
      int * v853 = v760->cache_age;
      int v854 = v853[v904];
      int * v855 = v760->cache_age;
      int v976 = v854 + ((int)((unsigned int)(v854 - v848) >> 31));
      v855[v904] = v976;
      int * v857 = v760->cache_age;
      v857[v939] = 0;
      v860 = v939;
    }
    int * v861 = v760->cache_vals;
    int v979 = v860 * 2;
    int v862 = v861[v979];
    int * v863 = v760->cache_vals;
    int v981 = (v860 * 2) + 1;
    int v864 = v863[v981];
    int * v865 = v760->cache_vals;
    int v983 = (((((int)((unsigned int)((int)((unsigned int)v764 >> 2)) >> 1)) & 1) * 2) + ((((v790 + ((~(((v792 ^ -1) | (-(v792 ^ -1))) >> 31)) & 2)) - (v794 + ((~(((v796 ^ -1) | (-(v796 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
    v865[v983] = v862;
    int * v867 = v760->cache_vals;
    int v986 = ((((((int)((unsigned int)((int)((unsigned int)v764 >> 2)) >> 1)) & 1) * 2) + ((((v790 + ((~(((v792 ^ -1) | (-(v792 ^ -1))) >> 31)) & 2)) - (v794 + ((~(((v796 ^ -1) | (-(v796 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
    v867[v986] = v864;
    int * v869 = v760->cache_tags;
    int v989 = ((((int)((unsigned int)((int)((unsigned int)v764 >> 2)) >> 1)) & 1) * 2) + ((((v790 + ((~(((v792 ^ -1) | (-(v792 ^ -1))) >> 31)) & 2)) - (v794 + ((~(((v796 ^ -1) | (-(v796 ^ -1))) >> 31)) & 2))) >> 31) & 1);
    int v990 = (int)((unsigned int)((int)((unsigned int)v764 >> 2)) >> 1);
    v869[v989] = v990;
    int * v871 = v760->cache_dirty;
    v871[v989] = 0;
    int * v873 = v760->cache_age;
    v873[v989] = 1;
    int * v875 = v760->cache_age;
    int v876 = v875[v989];
    int * v877 = v760->cache_age;
    int v878 = v877[v898];
    int * v879 = v760->cache_age;
    int v998 = v878 + ((int)((unsigned int)(v878 - v876) >> 31));
    v879[v898] = v998;
    int * v881 = v760->cache_age;
    int v882 = v881[v900];
    int * v883 = v760->cache_age;
    int v1001 = v882 + ((int)((unsigned int)(v882 - v876) >> 31));
    v883[v900] = v1001;
    int * v885 = v760->cache_age;
    v885[v989] = 0;
    v888 = v989;
  }
  int v1004 = (v888 * 2) + (((int)((unsigned int)v764 >> 2)) & 1);
  int v889 = v775[v1004];
  int * v890 = v760->regs;
  v890[9] = v889;
  struct StateT * v892 = slot_7(v760);
  return v892;
}

struct StateT * slot_5(struct StateT * v523) {
  int v524 = v523->timer;
  int v655 = v524 + 1;
  v523->timer = v655;
  int * v526 = v523->cache_tags;
  int v527 = v526[0];
  int * v528 = v523->cache_tags;
  int v529 = v528[1];
  int * v530 = v523->cache_tags;
  int v531 = v530[8];
  int * v532 = v523->cache_tags;
  int v533 = v532[9];
  int v534 = v523->timer;
  int v664 = v534 + ((100 ^ (((~(((v531 ^ 2) | (-(v531 ^ 2))) >> 31)) | (~(((v533 ^ 2) | (-(v533 ^ 2))) >> 31))) & 104)) ^ (((~(((v527 ^ 2) | (-(v527 ^ 2))) >> 31)) | (~(((v529 ^ 2) | (-(v529 ^ 2))) >> 31))) & (1 ^ (100 ^ (((~(((v531 ^ 2) | (-(v531 ^ 2))) >> 31)) | (~(((v533 ^ 2) | (-(v533 ^ 2))) >> 31))) & 104)))));
  v523->timer = v664;
  int * v536 = v523->cache_vals;
  bool v665 = !(((~(((v527 ^ 2) | (-(v527 ^ 2))) >> 31)) | (~(((v529 ^ 2) | (-(v529 ^ 2))) >> 31))) == 0);
  int v649;
  if (v665) {
    int * v537 = v523->cache_age;
    int v667 = (~(((v529 ^ 2) | (-(v529 ^ 2))) >> 31)) & 1;
    int v538 = v537[v667];
    int * v539 = v523->cache_age;
    int v540 = v539[0];
    int * v541 = v523->cache_age;
    int v670 = v540 + ((int)((unsigned int)(v540 - v538) >> 31));
    v541[0] = v670;
    int * v543 = v523->cache_age;
    int v544 = v543[1];
    int * v545 = v523->cache_age;
    int v673 = v544 + ((int)((unsigned int)(v544 - v538) >> 31));
    v545[1] = v673;
    int * v547 = v523->cache_age;
    v547[v667] = 0;
    v649 = v667;
  } else {
    int * v550 = v523->cache_age;
    int v551 = v550[0];
    int * v552 = v523->cache_tags;
    int v553 = v552[0];
    int * v554 = v523->cache_age;
    int v555 = v554[1];
    int * v556 = v523->cache_tags;
    int v557 = v556[1];
    bool v679 = !(((~(((v531 ^ 2) | (-(v531 ^ 2))) >> 31)) | (~(((v533 ^ 2) | (-(v533 ^ 2))) >> 31))) == 0);
    int v621;
    if (v679) {
      int * v558 = v523->cache_age;
      int v681 = 8 + ((~(((v533 ^ 2) | (-(v533 ^ 2))) >> 31)) & 1);
      int v559 = v558[v681];
      int * v560 = v523->cache_age;
      int v561 = v560[8];
      int * v562 = v523->cache_age;
      int v684 = v561 + ((int)((unsigned int)(v561 - v559) >> 31));
      v562[8] = v684;
      int * v564 = v523->cache_age;
      int v565 = v564[9];
      int * v566 = v523->cache_age;
      int v687 = v565 + ((int)((unsigned int)(v565 - v559) >> 31));
      v566[9] = v687;
      int * v568 = v523->cache_age;
      v568[v681] = 0;
      v621 = v681;
    } else {
      int * v571 = v523->cache_age;
      int v572 = v571[8];
      int * v573 = v523->cache_tags;
      int v574 = v573[8];
      int * v575 = v523->cache_age;
      int v576 = v575[9];
      int * v577 = v523->cache_tags;
      int v578 = v577[9];
      int * v579 = v523->cache_dirty;
      int v694 = 8 + ((((v572 + ((~(((v574 ^ -1) | (-(v574 ^ -1))) >> 31)) & 2)) - (v576 + ((~(((v578 ^ -1) | (-(v578 ^ -1))) >> 31)) & 2))) >> 31) & 1);
      int v580 = v579[v694];
      bool v695 = !(v580 == 0);
      if (v695) {
        int * v581 = v523->cache_tags;
        int v582 = v581[v694];
        int * v583 = v523->cache_vals;
        int v698 = (8 + ((((v572 + ((~(((v574 ^ -1) | (-(v574 ^ -1))) >> 31)) & 2)) - (v576 + ((~(((v578 ^ -1) | (-(v578 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
        int v584 = v583[v698];
        int * v585 = v523->cache_vals;
        int v700 = ((8 + ((((v572 + ((~(((v574 ^ -1) | (-(v574 ^ -1))) >> 31)) & 2)) - (v576 + ((~(((v578 ^ -1) | (-(v578 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
        int v586 = v585[v700];
        int * v587 = v523->mem;
        int v702 = v582 * 2;
        v587[v702] = v584;
        int * v589 = v523->mem;
        int v705 = (v582 * 2) + 1;
        v589[v705] = v586;
        ;
      } else {
        ;
      }
      int * v594 = v523->mem;
      int v595 = v594[4];
      int * v596 = v523->mem;
      int v597 = v596[5];
      int * v598 = v523->cache_vals;
      int v714 = (8 + ((((v572 + ((~(((v574 ^ -1) | (-(v574 ^ -1))) >> 31)) & 2)) - (v576 + ((~(((v578 ^ -1) | (-(v578 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
      v598[v714] = v595;
      int * v600 = v523->cache_vals;
      int v717 = ((8 + ((((v572 + ((~(((v574 ^ -1) | (-(v574 ^ -1))) >> 31)) & 2)) - (v576 + ((~(((v578 ^ -1) | (-(v578 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
      v600[v717] = v597;
      int * v602 = v523->cache_tags;
      v602[v694] = 2;
      int * v604 = v523->cache_dirty;
      v604[v694] = 0;
      int * v606 = v523->cache_age;
      v606[v694] = 1;
      int * v608 = v523->cache_age;
      int v609 = v608[v694];
      int * v610 = v523->cache_age;
      int v611 = v610[8];
      int * v612 = v523->cache_age;
      int v726 = v611 + ((int)((unsigned int)(v611 - v609) >> 31));
      v612[8] = v726;
      int * v614 = v523->cache_age;
      int v615 = v614[9];
      int * v616 = v523->cache_age;
      int v729 = v615 + ((int)((unsigned int)(v615 - v609) >> 31));
      v616[9] = v729;
      int * v618 = v523->cache_age;
      v618[v694] = 0;
      v621 = v694;
    }
    int * v622 = v523->cache_vals;
    int v732 = v621 * 2;
    int v623 = v622[v732];
    int * v624 = v523->cache_vals;
    int v734 = (v621 * 2) + 1;
    int v625 = v624[v734];
    int * v626 = v523->cache_vals;
    int v736 = ((((v551 + ((~(((v553 ^ -1) | (-(v553 ^ -1))) >> 31)) & 2)) - (v555 + ((~(((v557 ^ -1) | (-(v557 ^ -1))) >> 31)) & 2))) >> 31) & 1) * 2;
    v626[v736] = v623;
    int * v628 = v523->cache_vals;
    int v739 = (((((v551 + ((~(((v553 ^ -1) | (-(v553 ^ -1))) >> 31)) & 2)) - (v555 + ((~(((v557 ^ -1) | (-(v557 ^ -1))) >> 31)) & 2))) >> 31) & 1) * 2) + 1;
    v628[v739] = v625;
    int * v630 = v523->cache_tags;
    int v742 = (((v551 + ((~(((v553 ^ -1) | (-(v553 ^ -1))) >> 31)) & 2)) - (v555 + ((~(((v557 ^ -1) | (-(v557 ^ -1))) >> 31)) & 2))) >> 31) & 1;
    v630[v742] = 2;
    int * v632 = v523->cache_dirty;
    v632[v742] = 0;
    int * v634 = v523->cache_age;
    v634[v742] = 1;
    int * v636 = v523->cache_age;
    int v637 = v636[v742];
    int * v638 = v523->cache_age;
    int v639 = v638[0];
    int * v640 = v523->cache_age;
    int v749 = v639 + ((int)((unsigned int)(v639 - v637) >> 31));
    v640[0] = v749;
    int * v642 = v523->cache_age;
    int v643 = v642[1];
    int * v644 = v523->cache_age;
    int v752 = v643 + ((int)((unsigned int)(v643 - v637) >> 31));
    v644[1] = v752;
    int * v646 = v523->cache_age;
    v646[v742] = 0;
    v649 = v742;
  }
  int v755 = v649 * 2;
  int v650 = v536[v755];
  int * v651 = v523->regs;
  v651[8] = v650;
  struct StateT * v653 = slot_6(v523);
  return v653;
}

struct StateT * slot_4(struct StateT * v289) {
  int v290 = v289->timer;
  int v421 = v290 + 1;
  v289->timer = v421;
  int * v292 = v289->cache_tags;
  int v293 = v292[0];
  int * v294 = v289->cache_tags;
  int v295 = v294[1];
  int * v296 = v289->cache_tags;
  int v297 = v296[4];
  int * v298 = v289->cache_tags;
  int v299 = v298[5];
  int v300 = v289->timer;
  int v430 = v300 + ((100 ^ (((~((v297 | (-v297)) >> 31)) | (~((v299 | (-v299)) >> 31))) & 104)) ^ (((~((v293 | (-v293)) >> 31)) | (~((v295 | (-v295)) >> 31))) & (1 ^ (100 ^ (((~((v297 | (-v297)) >> 31)) | (~((v299 | (-v299)) >> 31))) & 104)))));
  v289->timer = v430;
  int * v302 = v289->cache_vals;
  bool v431 = !(((~((v293 | (-v293)) >> 31)) | (~((v295 | (-v295)) >> 31))) == 0);
  int v415;
  if (v431) {
    int * v303 = v289->cache_age;
    int v433 = (~((v295 | (-v295)) >> 31)) & 1;
    int v304 = v303[v433];
    int * v305 = v289->cache_age;
    int v306 = v305[0];
    int * v307 = v289->cache_age;
    int v436 = v306 + ((int)((unsigned int)(v306 - v304) >> 31));
    v307[0] = v436;
    int * v309 = v289->cache_age;
    int v310 = v309[1];
    int * v311 = v289->cache_age;
    int v439 = v310 + ((int)((unsigned int)(v310 - v304) >> 31));
    v311[1] = v439;
    int * v313 = v289->cache_age;
    v313[v433] = 0;
    v415 = v433;
  } else {
    int * v316 = v289->cache_age;
    int v317 = v316[0];
    int * v318 = v289->cache_tags;
    int v319 = v318[0];
    int * v320 = v289->cache_age;
    int v321 = v320[1];
    int * v322 = v289->cache_tags;
    int v323 = v322[1];
    bool v445 = !(((~((v297 | (-v297)) >> 31)) | (~((v299 | (-v299)) >> 31))) == 0);
    int v387;
    if (v445) {
      int * v324 = v289->cache_age;
      int v447 = 4 + ((~((v299 | (-v299)) >> 31)) & 1);
      int v325 = v324[v447];
      int * v326 = v289->cache_age;
      int v327 = v326[4];
      int * v328 = v289->cache_age;
      int v450 = v327 + ((int)((unsigned int)(v327 - v325) >> 31));
      v328[4] = v450;
      int * v330 = v289->cache_age;
      int v331 = v330[5];
      int * v332 = v289->cache_age;
      int v453 = v331 + ((int)((unsigned int)(v331 - v325) >> 31));
      v332[5] = v453;
      int * v334 = v289->cache_age;
      v334[v447] = 0;
      v387 = v447;
    } else {
      int * v337 = v289->cache_age;
      int v338 = v337[4];
      int * v339 = v289->cache_tags;
      int v340 = v339[4];
      int * v341 = v289->cache_age;
      int v342 = v341[5];
      int * v343 = v289->cache_tags;
      int v344 = v343[5];
      int * v345 = v289->cache_dirty;
      int v460 = 4 + ((((v338 + ((~(((v340 ^ -1) | (-(v340 ^ -1))) >> 31)) & 2)) - (v342 + ((~(((v344 ^ -1) | (-(v344 ^ -1))) >> 31)) & 2))) >> 31) & 1);
      int v346 = v345[v460];
      bool v461 = !(v346 == 0);
      if (v461) {
        int * v347 = v289->cache_tags;
        int v348 = v347[v460];
        int * v349 = v289->cache_vals;
        int v464 = (4 + ((((v338 + ((~(((v340 ^ -1) | (-(v340 ^ -1))) >> 31)) & 2)) - (v342 + ((~(((v344 ^ -1) | (-(v344 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
        int v350 = v349[v464];
        int * v351 = v289->cache_vals;
        int v466 = ((4 + ((((v338 + ((~(((v340 ^ -1) | (-(v340 ^ -1))) >> 31)) & 2)) - (v342 + ((~(((v344 ^ -1) | (-(v344 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
        int v352 = v351[v466];
        int * v353 = v289->mem;
        int v468 = v348 * 2;
        v353[v468] = v350;
        int * v355 = v289->mem;
        int v471 = (v348 * 2) + 1;
        v355[v471] = v352;
        ;
      } else {
        ;
      }
      int * v360 = v289->mem;
      int v361 = v360[0];
      int * v362 = v289->mem;
      int v363 = v362[1];
      int * v364 = v289->cache_vals;
      int v478 = (4 + ((((v338 + ((~(((v340 ^ -1) | (-(v340 ^ -1))) >> 31)) & 2)) - (v342 + ((~(((v344 ^ -1) | (-(v344 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
      v364[v478] = v361;
      int * v366 = v289->cache_vals;
      int v481 = ((4 + ((((v338 + ((~(((v340 ^ -1) | (-(v340 ^ -1))) >> 31)) & 2)) - (v342 + ((~(((v344 ^ -1) | (-(v344 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
      v366[v481] = v363;
      int * v368 = v289->cache_tags;
      v368[v460] = 0;
      int * v370 = v289->cache_dirty;
      v370[v460] = 0;
      int * v372 = v289->cache_age;
      v372[v460] = 1;
      int * v374 = v289->cache_age;
      int v375 = v374[v460];
      int * v376 = v289->cache_age;
      int v377 = v376[4];
      int * v378 = v289->cache_age;
      int v489 = v377 + ((int)((unsigned int)(v377 - v375) >> 31));
      v378[4] = v489;
      int * v380 = v289->cache_age;
      int v381 = v380[5];
      int * v382 = v289->cache_age;
      int v492 = v381 + ((int)((unsigned int)(v381 - v375) >> 31));
      v382[5] = v492;
      int * v384 = v289->cache_age;
      v384[v460] = 0;
      v387 = v460;
    }
    int * v388 = v289->cache_vals;
    int v495 = v387 * 2;
    int v389 = v388[v495];
    int * v390 = v289->cache_vals;
    int v497 = (v387 * 2) + 1;
    int v391 = v390[v497];
    int * v392 = v289->cache_vals;
    int v499 = ((((v317 + ((~(((v319 ^ -1) | (-(v319 ^ -1))) >> 31)) & 2)) - (v321 + ((~(((v323 ^ -1) | (-(v323 ^ -1))) >> 31)) & 2))) >> 31) & 1) * 2;
    v392[v499] = v389;
    int * v394 = v289->cache_vals;
    int v502 = (((((v317 + ((~(((v319 ^ -1) | (-(v319 ^ -1))) >> 31)) & 2)) - (v321 + ((~(((v323 ^ -1) | (-(v323 ^ -1))) >> 31)) & 2))) >> 31) & 1) * 2) + 1;
    v394[v502] = v391;
    int * v396 = v289->cache_tags;
    int v505 = (((v317 + ((~(((v319 ^ -1) | (-(v319 ^ -1))) >> 31)) & 2)) - (v321 + ((~(((v323 ^ -1) | (-(v323 ^ -1))) >> 31)) & 2))) >> 31) & 1;
    v396[v505] = 0;
    int * v398 = v289->cache_dirty;
    v398[v505] = 0;
    int * v400 = v289->cache_age;
    v400[v505] = 1;
    int * v402 = v289->cache_age;
    int v403 = v402[v505];
    int * v404 = v289->cache_age;
    int v405 = v404[0];
    int * v406 = v289->cache_age;
    int v511 = v405 + ((int)((unsigned int)(v405 - v403) >> 31));
    v406[0] = v511;
    int * v408 = v289->cache_age;
    int v409 = v408[1];
    int * v410 = v289->cache_age;
    int v514 = v409 + ((int)((unsigned int)(v409 - v403) >> 31));
    v410[1] = v514;
    int * v412 = v289->cache_age;
    v412[v505] = 0;
    v415 = v505;
  }
  int v517 = v415 * 2;
  int v416 = v302[v517];
  int * v417 = v289->regs;
  v417[7] = v416;
  struct StateT * v419 = slot_5(v289);
  return v419;
}

struct StateT * slot_2(struct StateT * v257) {
  int v258 = v257->timer;
  int v266 = v258 + 1;
  v257->timer = v266;
  int * v260 = v257->regs;
  int v261 = v260[6];
  int * v262 = v257->regs;
  int v270 = v261 << 3;
  v262[6] = v270;
  struct StateT * v264 = slot_3(v257);
  return v264;
}

struct StateT * slot_7(struct StateT * v1010) {
  int v1011 = v1010->timer;
  int v1141 = v1011 + 1;
  v1010->timer = v1141;
  int * v1013 = v1010->cache_tags;
  int v1014 = v1013[0];
  int * v1015 = v1010->cache_tags;
  int v1016 = v1015[1];
  int * v1017 = v1010->cache_tags;
  int v1018 = v1017[4];
  int * v1019 = v1010->cache_tags;
  int v1020 = v1019[5];
  int v1021 = v1010->timer;
  int v1150 = v1021 + ((100 ^ (((~((v1018 | (-v1018)) >> 31)) | (~((v1020 | (-v1020)) >> 31))) & 104)) ^ (((~((v1014 | (-v1014)) >> 31)) | (~((v1016 | (-v1016)) >> 31))) & (1 ^ (100 ^ (((~((v1018 | (-v1018)) >> 31)) | (~((v1020 | (-v1020)) >> 31))) & 104)))));
  v1010->timer = v1150;
  int * v1023 = v1010->cache_vals;
  bool v1151 = !(((~((v1014 | (-v1014)) >> 31)) | (~((v1016 | (-v1016)) >> 31))) == 0);
  int v1136;
  if (v1151) {
    int * v1024 = v1010->cache_age;
    int v1153 = (~((v1016 | (-v1016)) >> 31)) & 1;
    int v1025 = v1024[v1153];
    int * v1026 = v1010->cache_age;
    int v1027 = v1026[0];
    int * v1028 = v1010->cache_age;
    int v1156 = v1027 + ((int)((unsigned int)(v1027 - v1025) >> 31));
    v1028[0] = v1156;
    int * v1030 = v1010->cache_age;
    int v1031 = v1030[1];
    int * v1032 = v1010->cache_age;
    int v1159 = v1031 + ((int)((unsigned int)(v1031 - v1025) >> 31));
    v1032[1] = v1159;
    int * v1034 = v1010->cache_age;
    v1034[v1153] = 0;
    v1136 = v1153;
  } else {
    int * v1037 = v1010->cache_age;
    int v1038 = v1037[0];
    int * v1039 = v1010->cache_tags;
    int v1040 = v1039[0];
    int * v1041 = v1010->cache_age;
    int v1042 = v1041[1];
    int * v1043 = v1010->cache_tags;
    int v1044 = v1043[1];
    bool v1165 = !(((~((v1018 | (-v1018)) >> 31)) | (~((v1020 | (-v1020)) >> 31))) == 0);
    int v1108;
    if (v1165) {
      int * v1045 = v1010->cache_age;
      int v1167 = 4 + ((~((v1020 | (-v1020)) >> 31)) & 1);
      int v1046 = v1045[v1167];
      int * v1047 = v1010->cache_age;
      int v1048 = v1047[4];
      int * v1049 = v1010->cache_age;
      int v1170 = v1048 + ((int)((unsigned int)(v1048 - v1046) >> 31));
      v1049[4] = v1170;
      int * v1051 = v1010->cache_age;
      int v1052 = v1051[5];
      int * v1053 = v1010->cache_age;
      int v1173 = v1052 + ((int)((unsigned int)(v1052 - v1046) >> 31));
      v1053[5] = v1173;
      int * v1055 = v1010->cache_age;
      v1055[v1167] = 0;
      v1108 = v1167;
    } else {
      int * v1058 = v1010->cache_age;
      int v1059 = v1058[4];
      int * v1060 = v1010->cache_tags;
      int v1061 = v1060[4];
      int * v1062 = v1010->cache_age;
      int v1063 = v1062[5];
      int * v1064 = v1010->cache_tags;
      int v1065 = v1064[5];
      int * v1066 = v1010->cache_dirty;
      int v1180 = 4 + ((((v1059 + ((~(((v1061 ^ -1) | (-(v1061 ^ -1))) >> 31)) & 2)) - (v1063 + ((~(((v1065 ^ -1) | (-(v1065 ^ -1))) >> 31)) & 2))) >> 31) & 1);
      int v1067 = v1066[v1180];
      bool v1181 = !(v1067 == 0);
      if (v1181) {
        int * v1068 = v1010->cache_tags;
        int v1069 = v1068[v1180];
        int * v1070 = v1010->cache_vals;
        int v1184 = (4 + ((((v1059 + ((~(((v1061 ^ -1) | (-(v1061 ^ -1))) >> 31)) & 2)) - (v1063 + ((~(((v1065 ^ -1) | (-(v1065 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
        int v1071 = v1070[v1184];
        int * v1072 = v1010->cache_vals;
        int v1186 = ((4 + ((((v1059 + ((~(((v1061 ^ -1) | (-(v1061 ^ -1))) >> 31)) & 2)) - (v1063 + ((~(((v1065 ^ -1) | (-(v1065 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
        int v1073 = v1072[v1186];
        int * v1074 = v1010->mem;
        int v1188 = v1069 * 2;
        v1074[v1188] = v1071;
        int * v1076 = v1010->mem;
        int v1191 = (v1069 * 2) + 1;
        v1076[v1191] = v1073;
        ;
      } else {
        ;
      }
      int * v1081 = v1010->mem;
      int v1082 = v1081[0];
      int * v1083 = v1010->mem;
      int v1084 = v1083[1];
      int * v1085 = v1010->cache_vals;
      int v1198 = (4 + ((((v1059 + ((~(((v1061 ^ -1) | (-(v1061 ^ -1))) >> 31)) & 2)) - (v1063 + ((~(((v1065 ^ -1) | (-(v1065 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
      v1085[v1198] = v1082;
      int * v1087 = v1010->cache_vals;
      int v1201 = ((4 + ((((v1059 + ((~(((v1061 ^ -1) | (-(v1061 ^ -1))) >> 31)) & 2)) - (v1063 + ((~(((v1065 ^ -1) | (-(v1065 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
      v1087[v1201] = v1084;
      int * v1089 = v1010->cache_tags;
      v1089[v1180] = 0;
      int * v1091 = v1010->cache_dirty;
      v1091[v1180] = 0;
      int * v1093 = v1010->cache_age;
      v1093[v1180] = 1;
      int * v1095 = v1010->cache_age;
      int v1096 = v1095[v1180];
      int * v1097 = v1010->cache_age;
      int v1098 = v1097[4];
      int * v1099 = v1010->cache_age;
      int v1209 = v1098 + ((int)((unsigned int)(v1098 - v1096) >> 31));
      v1099[4] = v1209;
      int * v1101 = v1010->cache_age;
      int v1102 = v1101[5];
      int * v1103 = v1010->cache_age;
      int v1212 = v1102 + ((int)((unsigned int)(v1102 - v1096) >> 31));
      v1103[5] = v1212;
      int * v1105 = v1010->cache_age;
      v1105[v1180] = 0;
      v1108 = v1180;
    }
    int * v1109 = v1010->cache_vals;
    int v1215 = v1108 * 2;
    int v1110 = v1109[v1215];
    int * v1111 = v1010->cache_vals;
    int v1217 = (v1108 * 2) + 1;
    int v1112 = v1111[v1217];
    int * v1113 = v1010->cache_vals;
    int v1219 = ((((v1038 + ((~(((v1040 ^ -1) | (-(v1040 ^ -1))) >> 31)) & 2)) - (v1042 + ((~(((v1044 ^ -1) | (-(v1044 ^ -1))) >> 31)) & 2))) >> 31) & 1) * 2;
    v1113[v1219] = v1110;
    int * v1115 = v1010->cache_vals;
    int v1222 = (((((v1038 + ((~(((v1040 ^ -1) | (-(v1040 ^ -1))) >> 31)) & 2)) - (v1042 + ((~(((v1044 ^ -1) | (-(v1044 ^ -1))) >> 31)) & 2))) >> 31) & 1) * 2) + 1;
    v1115[v1222] = v1112;
    int * v1117 = v1010->cache_tags;
    int v1225 = (((v1038 + ((~(((v1040 ^ -1) | (-(v1040 ^ -1))) >> 31)) & 2)) - (v1042 + ((~(((v1044 ^ -1) | (-(v1044 ^ -1))) >> 31)) & 2))) >> 31) & 1;
    v1117[v1225] = 0;
    int * v1119 = v1010->cache_dirty;
    v1119[v1225] = 0;
    int * v1121 = v1010->cache_age;
    v1121[v1225] = 1;
    int * v1123 = v1010->cache_age;
    int v1124 = v1123[v1225];
    int * v1125 = v1010->cache_age;
    int v1126 = v1125[0];
    int * v1127 = v1010->cache_age;
    int v1231 = v1126 + ((int)((unsigned int)(v1126 - v1124) >> 31));
    v1127[0] = v1231;
    int * v1129 = v1010->cache_age;
    int v1130 = v1129[1];
    int * v1131 = v1010->cache_age;
    int v1234 = v1130 + ((int)((unsigned int)(v1130 - v1124) >> 31));
    v1131[1] = v1234;
    int * v1133 = v1010->cache_age;
    v1133[v1225] = 0;
    v1136 = v1225;
  }
  int v1237 = v1136 * 2;
  int v1137 = v1023[v1237];
  int * v1138 = v1010->regs;
  v1138[11] = v1137;
  return v1010;
}

struct StateT * slot_3(struct StateT * v273) {
  int v274 = v273->timer;
  int v282 = v274 + 1;
  v273->timer = v282;
  int * v276 = v273->regs;
  int v277 = v276[6];
  int * v278 = v273->regs;
  int v286 = v277 + 32;
  v278[6] = v286;
  struct StateT * v280 = slot_4(v273);
  return v280;
}

struct StateT * slot_0(struct StateT * v2) {
  int v3 = v2->timer;
  int v134 = v3 + 1;
  v2->timer = v134;
  int * v5 = v2->cache_tags;
  int v6 = v5[0];
  int * v7 = v2->cache_tags;
  int v8 = v7[1];
  int * v9 = v2->cache_tags;
  int v10 = v9[8];
  int * v11 = v2->cache_tags;
  int v12 = v11[9];
  int v13 = v2->timer;
  int v143 = v13 + ((100 ^ (((~(((v10 ^ 10) | (-(v10 ^ 10))) >> 31)) | (~(((v12 ^ 10) | (-(v12 ^ 10))) >> 31))) & 104)) ^ (((~(((v6 ^ 10) | (-(v6 ^ 10))) >> 31)) | (~(((v8 ^ 10) | (-(v8 ^ 10))) >> 31))) & (1 ^ (100 ^ (((~(((v10 ^ 10) | (-(v10 ^ 10))) >> 31)) | (~(((v12 ^ 10) | (-(v12 ^ 10))) >> 31))) & 104)))));
  v2->timer = v143;
  int * v15 = v2->cache_vals;
  bool v144 = !(((~(((v6 ^ 10) | (-(v6 ^ 10))) >> 31)) | (~(((v8 ^ 10) | (-(v8 ^ 10))) >> 31))) == 0);
  int v128;
  if (v144) {
    int * v16 = v2->cache_age;
    int v146 = (~(((v8 ^ 10) | (-(v8 ^ 10))) >> 31)) & 1;
    int v17 = v16[v146];
    int * v18 = v2->cache_age;
    int v19 = v18[0];
    int * v20 = v2->cache_age;
    int v149 = v19 + ((int)((unsigned int)(v19 - v17) >> 31));
    v20[0] = v149;
    int * v22 = v2->cache_age;
    int v23 = v22[1];
    int * v24 = v2->cache_age;
    int v152 = v23 + ((int)((unsigned int)(v23 - v17) >> 31));
    v24[1] = v152;
    int * v26 = v2->cache_age;
    v26[v146] = 0;
    v128 = v146;
  } else {
    int * v29 = v2->cache_age;
    int v30 = v29[0];
    int * v31 = v2->cache_tags;
    int v32 = v31[0];
    int * v33 = v2->cache_age;
    int v34 = v33[1];
    int * v35 = v2->cache_tags;
    int v36 = v35[1];
    bool v158 = !(((~(((v10 ^ 10) | (-(v10 ^ 10))) >> 31)) | (~(((v12 ^ 10) | (-(v12 ^ 10))) >> 31))) == 0);
    int v100;
    if (v158) {
      int * v37 = v2->cache_age;
      int v160 = 8 + ((~(((v12 ^ 10) | (-(v12 ^ 10))) >> 31)) & 1);
      int v38 = v37[v160];
      int * v39 = v2->cache_age;
      int v40 = v39[8];
      int * v41 = v2->cache_age;
      int v163 = v40 + ((int)((unsigned int)(v40 - v38) >> 31));
      v41[8] = v163;
      int * v43 = v2->cache_age;
      int v44 = v43[9];
      int * v45 = v2->cache_age;
      int v166 = v44 + ((int)((unsigned int)(v44 - v38) >> 31));
      v45[9] = v166;
      int * v47 = v2->cache_age;
      v47[v160] = 0;
      v100 = v160;
    } else {
      int * v50 = v2->cache_age;
      int v51 = v50[8];
      int * v52 = v2->cache_tags;
      int v53 = v52[8];
      int * v54 = v2->cache_age;
      int v55 = v54[9];
      int * v56 = v2->cache_tags;
      int v57 = v56[9];
      int * v58 = v2->cache_dirty;
      int v173 = 8 + ((((v51 + ((~(((v53 ^ -1) | (-(v53 ^ -1))) >> 31)) & 2)) - (v55 + ((~(((v57 ^ -1) | (-(v57 ^ -1))) >> 31)) & 2))) >> 31) & 1);
      int v59 = v58[v173];
      bool v174 = !(v59 == 0);
      if (v174) {
        int * v60 = v2->cache_tags;
        int v61 = v60[v173];
        int * v62 = v2->cache_vals;
        int v177 = (8 + ((((v51 + ((~(((v53 ^ -1) | (-(v53 ^ -1))) >> 31)) & 2)) - (v55 + ((~(((v57 ^ -1) | (-(v57 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
        int v63 = v62[v177];
        int * v64 = v2->cache_vals;
        int v179 = ((8 + ((((v51 + ((~(((v53 ^ -1) | (-(v53 ^ -1))) >> 31)) & 2)) - (v55 + ((~(((v57 ^ -1) | (-(v57 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
        int v65 = v64[v179];
        int * v66 = v2->mem;
        int v181 = v61 * 2;
        v66[v181] = v63;
        int * v68 = v2->mem;
        int v184 = (v61 * 2) + 1;
        v68[v184] = v65;
        ;
      } else {
        ;
      }
      int * v73 = v2->mem;
      int v74 = v73[20];
      int * v75 = v2->mem;
      int v76 = v75[21];
      int * v77 = v2->cache_vals;
      int v193 = (8 + ((((v51 + ((~(((v53 ^ -1) | (-(v53 ^ -1))) >> 31)) & 2)) - (v55 + ((~(((v57 ^ -1) | (-(v57 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
      v77[v193] = v74;
      int * v79 = v2->cache_vals;
      int v196 = ((8 + ((((v51 + ((~(((v53 ^ -1) | (-(v53 ^ -1))) >> 31)) & 2)) - (v55 + ((~(((v57 ^ -1) | (-(v57 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
      v79[v196] = v76;
      int * v81 = v2->cache_tags;
      v81[v173] = 10;
      int * v83 = v2->cache_dirty;
      v83[v173] = 0;
      int * v85 = v2->cache_age;
      v85[v173] = 1;
      int * v87 = v2->cache_age;
      int v88 = v87[v173];
      int * v89 = v2->cache_age;
      int v90 = v89[8];
      int * v91 = v2->cache_age;
      int v205 = v90 + ((int)((unsigned int)(v90 - v88) >> 31));
      v91[8] = v205;
      int * v93 = v2->cache_age;
      int v94 = v93[9];
      int * v95 = v2->cache_age;
      int v208 = v94 + ((int)((unsigned int)(v94 - v88) >> 31));
      v95[9] = v208;
      int * v97 = v2->cache_age;
      v97[v173] = 0;
      v100 = v173;
    }
    int * v101 = v2->cache_vals;
    int v211 = v100 * 2;
    int v102 = v101[v211];
    int * v103 = v2->cache_vals;
    int v213 = (v100 * 2) + 1;
    int v104 = v103[v213];
    int * v105 = v2->cache_vals;
    int v215 = ((((v30 + ((~(((v32 ^ -1) | (-(v32 ^ -1))) >> 31)) & 2)) - (v34 + ((~(((v36 ^ -1) | (-(v36 ^ -1))) >> 31)) & 2))) >> 31) & 1) * 2;
    v105[v215] = v102;
    int * v107 = v2->cache_vals;
    int v218 = (((((v30 + ((~(((v32 ^ -1) | (-(v32 ^ -1))) >> 31)) & 2)) - (v34 + ((~(((v36 ^ -1) | (-(v36 ^ -1))) >> 31)) & 2))) >> 31) & 1) * 2) + 1;
    v107[v218] = v104;
    int * v109 = v2->cache_tags;
    int v221 = (((v30 + ((~(((v32 ^ -1) | (-(v32 ^ -1))) >> 31)) & 2)) - (v34 + ((~(((v36 ^ -1) | (-(v36 ^ -1))) >> 31)) & 2))) >> 31) & 1;
    v109[v221] = 10;
    int * v111 = v2->cache_dirty;
    v111[v221] = 0;
    int * v113 = v2->cache_age;
    v113[v221] = 1;
    int * v115 = v2->cache_age;
    int v116 = v115[v221];
    int * v117 = v2->cache_age;
    int v118 = v117[0];
    int * v119 = v2->cache_age;
    int v228 = v118 + ((int)((unsigned int)(v118 - v116) >> 31));
    v119[0] = v228;
    int * v121 = v2->cache_age;
    int v122 = v121[1];
    int * v123 = v2->cache_age;
    int v231 = v122 + ((int)((unsigned int)(v122 - v116) >> 31));
    v123[1] = v231;
    int * v125 = v2->cache_age;
    v125[v221] = 0;
    v128 = v221;
  }
  int v234 = v128 * 2;
  int v129 = v15[v234];
  int * v130 = v2->regs;
  v130[5] = v129;
  struct StateT * v132 = slot_1(v2);
  return v132;
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