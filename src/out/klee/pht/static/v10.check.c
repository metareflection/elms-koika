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

struct StateT * slot_12(struct StateT * v521);
struct StateT * slot_14(struct StateT * v556);
struct StateT * slot_16(struct StateT * v772);
struct StateT * slot_5(struct StateT * v253);
struct StateT * slot_17(struct StateT * v976);
struct StateT * slot_2(struct StateT * v218);
struct StateT * slot_7(struct StateT * v267);
struct StateT * slot_3(struct StateT * v226);
struct StateT * snippet(struct StateT * v0);
struct StateT * slot_10(struct StateT * v310);
struct StateT * slot_1(struct StateT * v15);
struct StateT * slot_8(struct StateT * v280);
struct StateT * slot_4(struct StateT * v248);
struct StateT * slot_13(struct StateT * v543);
struct StateT * slot_15(struct StateT * v569);
struct StateT * slot_18(struct StateT * v992);
struct StateT * slot_9(struct StateT * v294);
struct StateT * slot_11(struct StateT * v513);
struct StateT * slot_0(struct StateT * v2);
struct StateT * slot_12(struct StateT * v521) {
  int * v522 = v521->regs;
  int v523 = v522[10];
  int v524 = v522[11];
  bool v536 = !(v523 == v524);
  struct StateT * v531;
  if (v536) {
    int v525 = v521->timer;
    int v537 = v525 + 15;
    v521->timer = v537;
    struct StateT * v527 = slot_4(v521);
    v531 = v527;
  } else {
    struct StateT * v529 = slot_13(v521);
    v531 = v529;
  }
  return v531;
}

struct StateT * slot_14(struct StateT * v556) {
  int v557 = v556->timer;
  int v563 = v557 + 1;
  v556->timer = v563;
  int * v559 = v556->regs;
  v559[11] = 0;
  struct StateT * v561 = slot_15(v556);
  return v561;
}

struct StateT * slot_16(struct StateT * v772) {
  int v773 = v772->timer;
  int v883 = v773 + 1;
  v772->timer = v883;
  int * v775 = v772->regs;
  int v776 = v775[11];
  int * v777 = v772->cache_tags;
  int v887 = (((int)((unsigned int)((int)((unsigned int)(v776 + 68) >> 2)) >> 1)) & 1) * 2;
  int v778 = v777[v887];
  int v888 = ((((int)((unsigned int)((int)((unsigned int)(v776 + 68) >> 2)) >> 1)) & 1) * 2) + 1;
  int v779 = v777[v888];
  int v889 = 4 + ((((int)((unsigned int)((int)((unsigned int)(v776 + 68) >> 2)) >> 1)) & 3) * 2);
  int v780 = v777[v889];
  int v890 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v776 + 68) >> 2)) >> 1)) & 3) * 2)) + 1;
  int v781 = v777[v890];
  int v782 = v772->timer;
  int v891 = v782 + ((100 ^ (((~(((v780 ^ ((int)((unsigned int)((int)((unsigned int)(v776 + 68) >> 2)) >> 1))) | (-(v780 ^ ((int)((unsigned int)((int)((unsigned int)(v776 + 68) >> 2)) >> 1))))) >> 31)) | (~(((v781 ^ ((int)((unsigned int)((int)((unsigned int)(v776 + 68) >> 2)) >> 1))) | (-(v781 ^ ((int)((unsigned int)((int)((unsigned int)(v776 + 68) >> 2)) >> 1))))) >> 31))) & 104)) ^ (((~(((v778 ^ ((int)((unsigned int)((int)((unsigned int)(v776 + 68) >> 2)) >> 1))) | (-(v778 ^ ((int)((unsigned int)((int)((unsigned int)(v776 + 68) >> 2)) >> 1))))) >> 31)) | (~(((v779 ^ ((int)((unsigned int)((int)((unsigned int)(v776 + 68) >> 2)) >> 1))) | (-(v779 ^ ((int)((unsigned int)((int)((unsigned int)(v776 + 68) >> 2)) >> 1))))) >> 31))) & (1 ^ (100 ^ (((~(((v780 ^ ((int)((unsigned int)((int)((unsigned int)(v776 + 68) >> 2)) >> 1))) | (-(v780 ^ ((int)((unsigned int)((int)((unsigned int)(v776 + 68) >> 2)) >> 1))))) >> 31)) | (~(((v781 ^ ((int)((unsigned int)((int)((unsigned int)(v776 + 68) >> 2)) >> 1))) | (-(v781 ^ ((int)((unsigned int)((int)((unsigned int)(v776 + 68) >> 2)) >> 1))))) >> 31))) & 104)))));
  v772->timer = v891;
  int * v784 = v772->cache_vals;
  bool v892 = !(((~(((v778 ^ ((int)((unsigned int)((int)((unsigned int)(v776 + 68) >> 2)) >> 1))) | (-(v778 ^ ((int)((unsigned int)((int)((unsigned int)(v776 + 68) >> 2)) >> 1))))) >> 31)) | (~(((v779 ^ ((int)((unsigned int)((int)((unsigned int)(v776 + 68) >> 2)) >> 1))) | (-(v779 ^ ((int)((unsigned int)((int)((unsigned int)(v776 + 68) >> 2)) >> 1))))) >> 31))) == 0);
  int v877;
  if (v892) {
    int * v785 = v772->cache_age;
    int v894 = ((((int)((unsigned int)((int)((unsigned int)(v776 + 68) >> 2)) >> 1)) & 1) * 2) + ((~(((v779 ^ ((int)((unsigned int)((int)((unsigned int)(v776 + 68) >> 2)) >> 1))) | (-(v779 ^ ((int)((unsigned int)((int)((unsigned int)(v776 + 68) >> 2)) >> 1))))) >> 31)) & 1);
    int v786 = v785[v894];
    int v787 = v785[v887];
    int v895 = v787 + ((int)((unsigned int)(v787 - v786) >> 31));
    v785[v887] = v895;
    int * v789 = v772->cache_age;
    int v790 = v789[v888];
    int v897 = v790 + ((int)((unsigned int)(v790 - v786) >> 31));
    v789[v888] = v897;
    int * v792 = v772->cache_age;
    v792[v894] = 0;
    v877 = v894;
  } else {
    int * v795 = v772->cache_age;
    int v901 = (((int)((unsigned int)((int)((unsigned int)(v776 + 68) >> 2)) >> 1)) & 1) * 2;
    int v796 = v795[v901];
    int * v797 = v772->cache_tags;
    int v798 = v797[v901];
    int v799 = v795[v888];
    int v800 = v797[v888];
    bool v903 = !(((~(((v780 ^ ((int)((unsigned int)((int)((unsigned int)(v776 + 68) >> 2)) >> 1))) | (-(v780 ^ ((int)((unsigned int)((int)((unsigned int)(v776 + 68) >> 2)) >> 1))))) >> 31)) | (~(((v781 ^ ((int)((unsigned int)((int)((unsigned int)(v776 + 68) >> 2)) >> 1))) | (-(v781 ^ ((int)((unsigned int)((int)((unsigned int)(v776 + 68) >> 2)) >> 1))))) >> 31))) == 0);
    int v854;
    if (v903) {
      int * v801 = v772->cache_age;
      int v905 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v776 + 68) >> 2)) >> 1)) & 3) * 2)) + ((~(((v781 ^ ((int)((unsigned int)((int)((unsigned int)(v776 + 68) >> 2)) >> 1))) | (-(v781 ^ ((int)((unsigned int)((int)((unsigned int)(v776 + 68) >> 2)) >> 1))))) >> 31)) & 1);
      int v802 = v801[v905];
      int v803 = v801[v889];
      int v906 = v803 + ((int)((unsigned int)(v803 - v802) >> 31));
      v801[v889] = v906;
      int * v805 = v772->cache_age;
      int v806 = v805[v890];
      int v908 = v806 + ((int)((unsigned int)(v806 - v802) >> 31));
      v805[v890] = v908;
      int * v808 = v772->cache_age;
      v808[v905] = 0;
      v854 = v905;
    } else {
      int * v811 = v772->cache_age;
      int v912 = 4 + ((((int)((unsigned int)((int)((unsigned int)(v776 + 68) >> 2)) >> 1)) & 3) * 2);
      int v812 = v811[v912];
      int * v813 = v772->cache_tags;
      int v814 = v813[v912];
      int v815 = v811[v890];
      int v816 = v813[v890];
      int * v817 = v772->cache_dirty;
      int v915 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v776 + 68) >> 2)) >> 1)) & 3) * 2)) + ((((v812 + ((~(((v814 ^ -1) | (-(v814 ^ -1))) >> 31)) & 2)) - (v815 + ((~(((v816 ^ -1) | (-(v816 ^ -1))) >> 31)) & 2))) >> 31) & 1);
      int v818 = v817[v915];
      bool v916 = !(v818 == 0);
      if (v916) {
        int * v819 = v772->cache_tags;
        int v820 = v819[v915];
        int * v821 = v772->cache_vals;
        int v919 = ((4 + ((((int)((unsigned int)((int)((unsigned int)(v776 + 68) >> 2)) >> 1)) & 3) * 2)) + ((((v812 + ((~(((v814 ^ -1) | (-(v814 ^ -1))) >> 31)) & 2)) - (v815 + ((~(((v816 ^ -1) | (-(v816 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
        int v822 = v821[v919];
        int v920 = (((4 + ((((int)((unsigned int)((int)((unsigned int)(v776 + 68) >> 2)) >> 1)) & 3) * 2)) + ((((v812 + ((~(((v814 ^ -1) | (-(v814 ^ -1))) >> 31)) & 2)) - (v815 + ((~(((v816 ^ -1) | (-(v816 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
        int v823 = v821[v920];
        int * v824 = v772->mem;
        int v922 = v820 * 2;
        v824[v922] = v822;
        int * v826 = v772->mem;
        int v925 = (v820 * 2) + 1;
        v826[v925] = v823;
        ;
      } else {
        ;
      }
      int * v831 = v772->mem;
      int v930 = ((int)((unsigned int)((int)((unsigned int)(v776 + 68) >> 2)) >> 1)) * 2;
      int v832 = v831[v930];
      int v931 = (((int)((unsigned int)((int)((unsigned int)(v776 + 68) >> 2)) >> 1)) * 2) + 1;
      int v833 = v831[v931];
      int * v834 = v772->cache_vals;
      int v933 = ((4 + ((((int)((unsigned int)((int)((unsigned int)(v776 + 68) >> 2)) >> 1)) & 3) * 2)) + ((((v812 + ((~(((v814 ^ -1) | (-(v814 ^ -1))) >> 31)) & 2)) - (v815 + ((~(((v816 ^ -1) | (-(v816 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
      v834[v933] = v832;
      int * v836 = v772->cache_vals;
      int v936 = (((4 + ((((int)((unsigned int)((int)((unsigned int)(v776 + 68) >> 2)) >> 1)) & 3) * 2)) + ((((v812 + ((~(((v814 ^ -1) | (-(v814 ^ -1))) >> 31)) & 2)) - (v815 + ((~(((v816 ^ -1) | (-(v816 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
      v836[v936] = v833;
      int * v838 = v772->cache_tags;
      int v939 = (int)((unsigned int)((int)((unsigned int)(v776 + 68) >> 2)) >> 1);
      v838[v915] = v939;
      int * v840 = v772->cache_dirty;
      v840[v915] = 0;
      int * v842 = v772->cache_age;
      v842[v915] = 1;
      int * v844 = v772->cache_age;
      int v845 = v844[v915];
      int v846 = v844[v889];
      int v945 = v846 + ((int)((unsigned int)(v846 - v845) >> 31));
      v844[v889] = v945;
      int * v848 = v772->cache_age;
      int v849 = v848[v890];
      int v947 = v849 + ((int)((unsigned int)(v849 - v845) >> 31));
      v848[v890] = v947;
      int * v851 = v772->cache_age;
      v851[v915] = 0;
      v854 = v915;
    }
    int * v855 = v772->cache_vals;
    int v950 = v854 * 2;
    int v856 = v855[v950];
    int v951 = (v854 * 2) + 1;
    int v857 = v855[v951];
    int v952 = (((((int)((unsigned int)((int)((unsigned int)(v776 + 68) >> 2)) >> 1)) & 1) * 2) + ((((v796 + ((~(((v798 ^ -1) | (-(v798 ^ -1))) >> 31)) & 2)) - (v799 + ((~(((v800 ^ -1) | (-(v800 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
    v855[v952] = v856;
    int * v859 = v772->cache_vals;
    int v955 = ((((((int)((unsigned int)((int)((unsigned int)(v776 + 68) >> 2)) >> 1)) & 1) * 2) + ((((v796 + ((~(((v798 ^ -1) | (-(v798 ^ -1))) >> 31)) & 2)) - (v799 + ((~(((v800 ^ -1) | (-(v800 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
    v859[v955] = v857;
    int * v861 = v772->cache_tags;
    int v958 = ((((int)((unsigned int)((int)((unsigned int)(v776 + 68) >> 2)) >> 1)) & 1) * 2) + ((((v796 + ((~(((v798 ^ -1) | (-(v798 ^ -1))) >> 31)) & 2)) - (v799 + ((~(((v800 ^ -1) | (-(v800 ^ -1))) >> 31)) & 2))) >> 31) & 1);
    int v959 = (int)((unsigned int)((int)((unsigned int)(v776 + 68) >> 2)) >> 1);
    v861[v958] = v959;
    int * v863 = v772->cache_dirty;
    v863[v958] = 0;
    int * v865 = v772->cache_age;
    v865[v958] = 1;
    int * v867 = v772->cache_age;
    int v868 = v867[v958];
    int v869 = v867[v887];
    int v965 = v869 + ((int)((unsigned int)(v869 - v868) >> 31));
    v867[v887] = v965;
    int * v871 = v772->cache_age;
    int v872 = v871[v888];
    int v967 = v872 + ((int)((unsigned int)(v872 - v868) >> 31));
    v871[v888] = v967;
    int * v874 = v772->cache_age;
    v874[v958] = 0;
    v877 = v958;
  }
  int v970 = (v877 * 2) + (((int)((unsigned int)(v776 + 68) >> 2)) & 1);
  int v878 = v784[v970];
  int * v879 = v772->regs;
  v879[12] = v878;
  struct StateT * v881 = slot_17(v772);
  return v881;
}

struct StateT * slot_5(struct StateT * v253) {
  int v254 = v253->timer;
  int v261 = v254 + 1;
  v253->timer = v261;
  int * v256 = v253->regs;
  int v257 = v256[10];
  int v264 = v257 << 2;
  v256[10] = v264;
  struct StateT * v259 = slot_7(v253);
  return v259;
}

struct StateT * slot_17(struct StateT * v976) {
  int v977 = v976->timer;
  int v985 = v977 + 1;
  v976->timer = v985;
  int * v979 = v976->regs;
  int v980 = v979[12];
  int v981 = v979[10];
  int v989 = v980 & v981;
  v979[10] = v989;
  struct StateT * v983 = slot_18(v976);
  return v983;
}

struct StateT * slot_2(struct StateT * v218) {
  int v219 = v218->timer;
  int v223 = v219 + 1;
  v218->timer = v223;
  struct StateT * v221 = slot_3(v218);
  return v221;
}

struct StateT * slot_7(struct StateT * v267) {
  int v268 = v267->timer;
  int v274 = v268 + 1;
  v267->timer = v274;
  int * v270 = v267->regs;
  v270[12] = 0;
  struct StateT * v272 = slot_8(v267);
  return v272;
}

struct StateT * slot_3(struct StateT * v226) {
  int * v227 = v226->regs;
  int v228 = v227[10];
  int v229 = v227[12];
  bool v241 = (v228 ^ -2147483648) >= (v229 ^ -2147483648);
  struct StateT * v236;
  if (v241) {
    int v230 = v226->timer;
    int v242 = v230 + 15;
    v226->timer = v242;
    struct StateT * v232 = slot_4(v226);
    v236 = v232;
  } else {
    struct StateT * v234 = slot_5(v226);
    v236 = v234;
  }
  return v236;
}

struct StateT * snippet(struct StateT * v0) {
  struct StateT * v1 = slot_0(v0);
  return v1;
}

struct StateT * slot_10(struct StateT * v310) {
  int v311 = v310->timer;
  int v421 = v311 + 1;
  v310->timer = v421;
  int * v313 = v310->regs;
  int v314 = v313[10];
  int * v315 = v310->cache_tags;
  int v425 = (((int)((unsigned int)((int)((unsigned int)v314 >> 2)) >> 1)) & 1) * 2;
  int v316 = v315[v425];
  int v426 = ((((int)((unsigned int)((int)((unsigned int)v314 >> 2)) >> 1)) & 1) * 2) + 1;
  int v317 = v315[v426];
  int v427 = 4 + ((((int)((unsigned int)((int)((unsigned int)v314 >> 2)) >> 1)) & 3) * 2);
  int v318 = v315[v427];
  int v428 = (4 + ((((int)((unsigned int)((int)((unsigned int)v314 >> 2)) >> 1)) & 3) * 2)) + 1;
  int v319 = v315[v428];
  int v320 = v310->timer;
  int v429 = v320 + ((100 ^ (((~(((v318 ^ ((int)((unsigned int)((int)((unsigned int)v314 >> 2)) >> 1))) | (-(v318 ^ ((int)((unsigned int)((int)((unsigned int)v314 >> 2)) >> 1))))) >> 31)) | (~(((v319 ^ ((int)((unsigned int)((int)((unsigned int)v314 >> 2)) >> 1))) | (-(v319 ^ ((int)((unsigned int)((int)((unsigned int)v314 >> 2)) >> 1))))) >> 31))) & 104)) ^ (((~(((v316 ^ ((int)((unsigned int)((int)((unsigned int)v314 >> 2)) >> 1))) | (-(v316 ^ ((int)((unsigned int)((int)((unsigned int)v314 >> 2)) >> 1))))) >> 31)) | (~(((v317 ^ ((int)((unsigned int)((int)((unsigned int)v314 >> 2)) >> 1))) | (-(v317 ^ ((int)((unsigned int)((int)((unsigned int)v314 >> 2)) >> 1))))) >> 31))) & (1 ^ (100 ^ (((~(((v318 ^ ((int)((unsigned int)((int)((unsigned int)v314 >> 2)) >> 1))) | (-(v318 ^ ((int)((unsigned int)((int)((unsigned int)v314 >> 2)) >> 1))))) >> 31)) | (~(((v319 ^ ((int)((unsigned int)((int)((unsigned int)v314 >> 2)) >> 1))) | (-(v319 ^ ((int)((unsigned int)((int)((unsigned int)v314 >> 2)) >> 1))))) >> 31))) & 104)))));
  v310->timer = v429;
  int * v322 = v310->cache_vals;
  bool v430 = !(((~(((v316 ^ ((int)((unsigned int)((int)((unsigned int)v314 >> 2)) >> 1))) | (-(v316 ^ ((int)((unsigned int)((int)((unsigned int)v314 >> 2)) >> 1))))) >> 31)) | (~(((v317 ^ ((int)((unsigned int)((int)((unsigned int)v314 >> 2)) >> 1))) | (-(v317 ^ ((int)((unsigned int)((int)((unsigned int)v314 >> 2)) >> 1))))) >> 31))) == 0);
  int v415;
  if (v430) {
    int * v323 = v310->cache_age;
    int v432 = ((((int)((unsigned int)((int)((unsigned int)v314 >> 2)) >> 1)) & 1) * 2) + ((~(((v317 ^ ((int)((unsigned int)((int)((unsigned int)v314 >> 2)) >> 1))) | (-(v317 ^ ((int)((unsigned int)((int)((unsigned int)v314 >> 2)) >> 1))))) >> 31)) & 1);
    int v324 = v323[v432];
    int v325 = v323[v425];
    int v433 = v325 + ((int)((unsigned int)(v325 - v324) >> 31));
    v323[v425] = v433;
    int * v327 = v310->cache_age;
    int v328 = v327[v426];
    int v435 = v328 + ((int)((unsigned int)(v328 - v324) >> 31));
    v327[v426] = v435;
    int * v330 = v310->cache_age;
    v330[v432] = 0;
    v415 = v432;
  } else {
    int * v333 = v310->cache_age;
    int v439 = (((int)((unsigned int)((int)((unsigned int)v314 >> 2)) >> 1)) & 1) * 2;
    int v334 = v333[v439];
    int * v335 = v310->cache_tags;
    int v336 = v335[v439];
    int v337 = v333[v426];
    int v338 = v335[v426];
    bool v441 = !(((~(((v318 ^ ((int)((unsigned int)((int)((unsigned int)v314 >> 2)) >> 1))) | (-(v318 ^ ((int)((unsigned int)((int)((unsigned int)v314 >> 2)) >> 1))))) >> 31)) | (~(((v319 ^ ((int)((unsigned int)((int)((unsigned int)v314 >> 2)) >> 1))) | (-(v319 ^ ((int)((unsigned int)((int)((unsigned int)v314 >> 2)) >> 1))))) >> 31))) == 0);
    int v392;
    if (v441) {
      int * v339 = v310->cache_age;
      int v443 = (4 + ((((int)((unsigned int)((int)((unsigned int)v314 >> 2)) >> 1)) & 3) * 2)) + ((~(((v319 ^ ((int)((unsigned int)((int)((unsigned int)v314 >> 2)) >> 1))) | (-(v319 ^ ((int)((unsigned int)((int)((unsigned int)v314 >> 2)) >> 1))))) >> 31)) & 1);
      int v340 = v339[v443];
      int v341 = v339[v427];
      int v444 = v341 + ((int)((unsigned int)(v341 - v340) >> 31));
      v339[v427] = v444;
      int * v343 = v310->cache_age;
      int v344 = v343[v428];
      int v446 = v344 + ((int)((unsigned int)(v344 - v340) >> 31));
      v343[v428] = v446;
      int * v346 = v310->cache_age;
      v346[v443] = 0;
      v392 = v443;
    } else {
      int * v349 = v310->cache_age;
      int v450 = 4 + ((((int)((unsigned int)((int)((unsigned int)v314 >> 2)) >> 1)) & 3) * 2);
      int v350 = v349[v450];
      int * v351 = v310->cache_tags;
      int v352 = v351[v450];
      int v353 = v349[v428];
      int v354 = v351[v428];
      int * v355 = v310->cache_dirty;
      int v453 = (4 + ((((int)((unsigned int)((int)((unsigned int)v314 >> 2)) >> 1)) & 3) * 2)) + ((((v350 + ((~(((v352 ^ -1) | (-(v352 ^ -1))) >> 31)) & 2)) - (v353 + ((~(((v354 ^ -1) | (-(v354 ^ -1))) >> 31)) & 2))) >> 31) & 1);
      int v356 = v355[v453];
      bool v454 = !(v356 == 0);
      if (v454) {
        int * v357 = v310->cache_tags;
        int v358 = v357[v453];
        int * v359 = v310->cache_vals;
        int v457 = ((4 + ((((int)((unsigned int)((int)((unsigned int)v314 >> 2)) >> 1)) & 3) * 2)) + ((((v350 + ((~(((v352 ^ -1) | (-(v352 ^ -1))) >> 31)) & 2)) - (v353 + ((~(((v354 ^ -1) | (-(v354 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
        int v360 = v359[v457];
        int v458 = (((4 + ((((int)((unsigned int)((int)((unsigned int)v314 >> 2)) >> 1)) & 3) * 2)) + ((((v350 + ((~(((v352 ^ -1) | (-(v352 ^ -1))) >> 31)) & 2)) - (v353 + ((~(((v354 ^ -1) | (-(v354 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
        int v361 = v359[v458];
        int * v362 = v310->mem;
        int v460 = v358 * 2;
        v362[v460] = v360;
        int * v364 = v310->mem;
        int v463 = (v358 * 2) + 1;
        v364[v463] = v361;
        ;
      } else {
        ;
      }
      int * v369 = v310->mem;
      int v468 = ((int)((unsigned int)((int)((unsigned int)v314 >> 2)) >> 1)) * 2;
      int v370 = v369[v468];
      int v469 = (((int)((unsigned int)((int)((unsigned int)v314 >> 2)) >> 1)) * 2) + 1;
      int v371 = v369[v469];
      int * v372 = v310->cache_vals;
      int v471 = ((4 + ((((int)((unsigned int)((int)((unsigned int)v314 >> 2)) >> 1)) & 3) * 2)) + ((((v350 + ((~(((v352 ^ -1) | (-(v352 ^ -1))) >> 31)) & 2)) - (v353 + ((~(((v354 ^ -1) | (-(v354 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
      v372[v471] = v370;
      int * v374 = v310->cache_vals;
      int v474 = (((4 + ((((int)((unsigned int)((int)((unsigned int)v314 >> 2)) >> 1)) & 3) * 2)) + ((((v350 + ((~(((v352 ^ -1) | (-(v352 ^ -1))) >> 31)) & 2)) - (v353 + ((~(((v354 ^ -1) | (-(v354 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
      v374[v474] = v371;
      int * v376 = v310->cache_tags;
      int v477 = (int)((unsigned int)((int)((unsigned int)v314 >> 2)) >> 1);
      v376[v453] = v477;
      int * v378 = v310->cache_dirty;
      v378[v453] = 0;
      int * v380 = v310->cache_age;
      v380[v453] = 1;
      int * v382 = v310->cache_age;
      int v383 = v382[v453];
      int v384 = v382[v427];
      int v483 = v384 + ((int)((unsigned int)(v384 - v383) >> 31));
      v382[v427] = v483;
      int * v386 = v310->cache_age;
      int v387 = v386[v428];
      int v485 = v387 + ((int)((unsigned int)(v387 - v383) >> 31));
      v386[v428] = v485;
      int * v389 = v310->cache_age;
      v389[v453] = 0;
      v392 = v453;
    }
    int * v393 = v310->cache_vals;
    int v488 = v392 * 2;
    int v394 = v393[v488];
    int v489 = (v392 * 2) + 1;
    int v395 = v393[v489];
    int v490 = (((((int)((unsigned int)((int)((unsigned int)v314 >> 2)) >> 1)) & 1) * 2) + ((((v334 + ((~(((v336 ^ -1) | (-(v336 ^ -1))) >> 31)) & 2)) - (v337 + ((~(((v338 ^ -1) | (-(v338 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
    v393[v490] = v394;
    int * v397 = v310->cache_vals;
    int v493 = ((((((int)((unsigned int)((int)((unsigned int)v314 >> 2)) >> 1)) & 1) * 2) + ((((v334 + ((~(((v336 ^ -1) | (-(v336 ^ -1))) >> 31)) & 2)) - (v337 + ((~(((v338 ^ -1) | (-(v338 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
    v397[v493] = v395;
    int * v399 = v310->cache_tags;
    int v496 = ((((int)((unsigned int)((int)((unsigned int)v314 >> 2)) >> 1)) & 1) * 2) + ((((v334 + ((~(((v336 ^ -1) | (-(v336 ^ -1))) >> 31)) & 2)) - (v337 + ((~(((v338 ^ -1) | (-(v338 ^ -1))) >> 31)) & 2))) >> 31) & 1);
    int v497 = (int)((unsigned int)((int)((unsigned int)v314 >> 2)) >> 1);
    v399[v496] = v497;
    int * v401 = v310->cache_dirty;
    v401[v496] = 0;
    int * v403 = v310->cache_age;
    v403[v496] = 1;
    int * v405 = v310->cache_age;
    int v406 = v405[v496];
    int v407 = v405[v425];
    int v503 = v407 + ((int)((unsigned int)(v407 - v406) >> 31));
    v405[v425] = v503;
    int * v409 = v310->cache_age;
    int v410 = v409[v426];
    int v505 = v410 + ((int)((unsigned int)(v410 - v406) >> 31));
    v409[v426] = v505;
    int * v412 = v310->cache_age;
    v412[v496] = 0;
    v415 = v496;
  }
  int v508 = (v415 * 2) + (((int)((unsigned int)v314 >> 2)) & 1);
  int v416 = v322[v508];
  int * v417 = v310->regs;
  v417[10] = v416;
  struct StateT * v419 = slot_11(v310);
  return v419;
}

struct StateT * slot_1(struct StateT * v15) {
  int v16 = v15->timer;
  int v126 = v16 + 1;
  v15->timer = v126;
  int * v18 = v15->regs;
  int v19 = v18[12];
  int * v20 = v15->cache_tags;
  int v130 = (((int)((unsigned int)((int)((unsigned int)v19 >> 2)) >> 1)) & 1) * 2;
  int v21 = v20[v130];
  int v131 = ((((int)((unsigned int)((int)((unsigned int)v19 >> 2)) >> 1)) & 1) * 2) + 1;
  int v22 = v20[v131];
  int v132 = 4 + ((((int)((unsigned int)((int)((unsigned int)v19 >> 2)) >> 1)) & 3) * 2);
  int v23 = v20[v132];
  int v133 = (4 + ((((int)((unsigned int)((int)((unsigned int)v19 >> 2)) >> 1)) & 3) * 2)) + 1;
  int v24 = v20[v133];
  int v25 = v15->timer;
  int v134 = v25 + ((100 ^ (((~(((v23 ^ ((int)((unsigned int)((int)((unsigned int)v19 >> 2)) >> 1))) | (-(v23 ^ ((int)((unsigned int)((int)((unsigned int)v19 >> 2)) >> 1))))) >> 31)) | (~(((v24 ^ ((int)((unsigned int)((int)((unsigned int)v19 >> 2)) >> 1))) | (-(v24 ^ ((int)((unsigned int)((int)((unsigned int)v19 >> 2)) >> 1))))) >> 31))) & 104)) ^ (((~(((v21 ^ ((int)((unsigned int)((int)((unsigned int)v19 >> 2)) >> 1))) | (-(v21 ^ ((int)((unsigned int)((int)((unsigned int)v19 >> 2)) >> 1))))) >> 31)) | (~(((v22 ^ ((int)((unsigned int)((int)((unsigned int)v19 >> 2)) >> 1))) | (-(v22 ^ ((int)((unsigned int)((int)((unsigned int)v19 >> 2)) >> 1))))) >> 31))) & (1 ^ (100 ^ (((~(((v23 ^ ((int)((unsigned int)((int)((unsigned int)v19 >> 2)) >> 1))) | (-(v23 ^ ((int)((unsigned int)((int)((unsigned int)v19 >> 2)) >> 1))))) >> 31)) | (~(((v24 ^ ((int)((unsigned int)((int)((unsigned int)v19 >> 2)) >> 1))) | (-(v24 ^ ((int)((unsigned int)((int)((unsigned int)v19 >> 2)) >> 1))))) >> 31))) & 104)))));
  v15->timer = v134;
  int * v27 = v15->cache_vals;
  bool v135 = !(((~(((v21 ^ ((int)((unsigned int)((int)((unsigned int)v19 >> 2)) >> 1))) | (-(v21 ^ ((int)((unsigned int)((int)((unsigned int)v19 >> 2)) >> 1))))) >> 31)) | (~(((v22 ^ ((int)((unsigned int)((int)((unsigned int)v19 >> 2)) >> 1))) | (-(v22 ^ ((int)((unsigned int)((int)((unsigned int)v19 >> 2)) >> 1))))) >> 31))) == 0);
  int v120;
  if (v135) {
    int * v28 = v15->cache_age;
    int v137 = ((((int)((unsigned int)((int)((unsigned int)v19 >> 2)) >> 1)) & 1) * 2) + ((~(((v22 ^ ((int)((unsigned int)((int)((unsigned int)v19 >> 2)) >> 1))) | (-(v22 ^ ((int)((unsigned int)((int)((unsigned int)v19 >> 2)) >> 1))))) >> 31)) & 1);
    int v29 = v28[v137];
    int v30 = v28[v130];
    int v138 = v30 + ((int)((unsigned int)(v30 - v29) >> 31));
    v28[v130] = v138;
    int * v32 = v15->cache_age;
    int v33 = v32[v131];
    int v140 = v33 + ((int)((unsigned int)(v33 - v29) >> 31));
    v32[v131] = v140;
    int * v35 = v15->cache_age;
    v35[v137] = 0;
    v120 = v137;
  } else {
    int * v38 = v15->cache_age;
    int v144 = (((int)((unsigned int)((int)((unsigned int)v19 >> 2)) >> 1)) & 1) * 2;
    int v39 = v38[v144];
    int * v40 = v15->cache_tags;
    int v41 = v40[v144];
    int v42 = v38[v131];
    int v43 = v40[v131];
    bool v146 = !(((~(((v23 ^ ((int)((unsigned int)((int)((unsigned int)v19 >> 2)) >> 1))) | (-(v23 ^ ((int)((unsigned int)((int)((unsigned int)v19 >> 2)) >> 1))))) >> 31)) | (~(((v24 ^ ((int)((unsigned int)((int)((unsigned int)v19 >> 2)) >> 1))) | (-(v24 ^ ((int)((unsigned int)((int)((unsigned int)v19 >> 2)) >> 1))))) >> 31))) == 0);
    int v97;
    if (v146) {
      int * v44 = v15->cache_age;
      int v148 = (4 + ((((int)((unsigned int)((int)((unsigned int)v19 >> 2)) >> 1)) & 3) * 2)) + ((~(((v24 ^ ((int)((unsigned int)((int)((unsigned int)v19 >> 2)) >> 1))) | (-(v24 ^ ((int)((unsigned int)((int)((unsigned int)v19 >> 2)) >> 1))))) >> 31)) & 1);
      int v45 = v44[v148];
      int v46 = v44[v132];
      int v149 = v46 + ((int)((unsigned int)(v46 - v45) >> 31));
      v44[v132] = v149;
      int * v48 = v15->cache_age;
      int v49 = v48[v133];
      int v151 = v49 + ((int)((unsigned int)(v49 - v45) >> 31));
      v48[v133] = v151;
      int * v51 = v15->cache_age;
      v51[v148] = 0;
      v97 = v148;
    } else {
      int * v54 = v15->cache_age;
      int v155 = 4 + ((((int)((unsigned int)((int)((unsigned int)v19 >> 2)) >> 1)) & 3) * 2);
      int v55 = v54[v155];
      int * v56 = v15->cache_tags;
      int v57 = v56[v155];
      int v58 = v54[v133];
      int v59 = v56[v133];
      int * v60 = v15->cache_dirty;
      int v158 = (4 + ((((int)((unsigned int)((int)((unsigned int)v19 >> 2)) >> 1)) & 3) * 2)) + ((((v55 + ((~(((v57 ^ -1) | (-(v57 ^ -1))) >> 31)) & 2)) - (v58 + ((~(((v59 ^ -1) | (-(v59 ^ -1))) >> 31)) & 2))) >> 31) & 1);
      int v61 = v60[v158];
      bool v159 = !(v61 == 0);
      if (v159) {
        int * v62 = v15->cache_tags;
        int v63 = v62[v158];
        int * v64 = v15->cache_vals;
        int v162 = ((4 + ((((int)((unsigned int)((int)((unsigned int)v19 >> 2)) >> 1)) & 3) * 2)) + ((((v55 + ((~(((v57 ^ -1) | (-(v57 ^ -1))) >> 31)) & 2)) - (v58 + ((~(((v59 ^ -1) | (-(v59 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
        int v65 = v64[v162];
        int v163 = (((4 + ((((int)((unsigned int)((int)((unsigned int)v19 >> 2)) >> 1)) & 3) * 2)) + ((((v55 + ((~(((v57 ^ -1) | (-(v57 ^ -1))) >> 31)) & 2)) - (v58 + ((~(((v59 ^ -1) | (-(v59 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
        int v66 = v64[v163];
        int * v67 = v15->mem;
        int v165 = v63 * 2;
        v67[v165] = v65;
        int * v69 = v15->mem;
        int v168 = (v63 * 2) + 1;
        v69[v168] = v66;
        ;
      } else {
        ;
      }
      int * v74 = v15->mem;
      int v173 = ((int)((unsigned int)((int)((unsigned int)v19 >> 2)) >> 1)) * 2;
      int v75 = v74[v173];
      int v174 = (((int)((unsigned int)((int)((unsigned int)v19 >> 2)) >> 1)) * 2) + 1;
      int v76 = v74[v174];
      int * v77 = v15->cache_vals;
      int v176 = ((4 + ((((int)((unsigned int)((int)((unsigned int)v19 >> 2)) >> 1)) & 3) * 2)) + ((((v55 + ((~(((v57 ^ -1) | (-(v57 ^ -1))) >> 31)) & 2)) - (v58 + ((~(((v59 ^ -1) | (-(v59 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
      v77[v176] = v75;
      int * v79 = v15->cache_vals;
      int v179 = (((4 + ((((int)((unsigned int)((int)((unsigned int)v19 >> 2)) >> 1)) & 3) * 2)) + ((((v55 + ((~(((v57 ^ -1) | (-(v57 ^ -1))) >> 31)) & 2)) - (v58 + ((~(((v59 ^ -1) | (-(v59 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
      v79[v179] = v76;
      int * v81 = v15->cache_tags;
      int v182 = (int)((unsigned int)((int)((unsigned int)v19 >> 2)) >> 1);
      v81[v158] = v182;
      int * v83 = v15->cache_dirty;
      v83[v158] = 0;
      int * v85 = v15->cache_age;
      v85[v158] = 1;
      int * v87 = v15->cache_age;
      int v88 = v87[v158];
      int v89 = v87[v132];
      int v188 = v89 + ((int)((unsigned int)(v89 - v88) >> 31));
      v87[v132] = v188;
      int * v91 = v15->cache_age;
      int v92 = v91[v133];
      int v190 = v92 + ((int)((unsigned int)(v92 - v88) >> 31));
      v91[v133] = v190;
      int * v94 = v15->cache_age;
      v94[v158] = 0;
      v97 = v158;
    }
    int * v98 = v15->cache_vals;
    int v193 = v97 * 2;
    int v99 = v98[v193];
    int v194 = (v97 * 2) + 1;
    int v100 = v98[v194];
    int v195 = (((((int)((unsigned int)((int)((unsigned int)v19 >> 2)) >> 1)) & 1) * 2) + ((((v39 + ((~(((v41 ^ -1) | (-(v41 ^ -1))) >> 31)) & 2)) - (v42 + ((~(((v43 ^ -1) | (-(v43 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
    v98[v195] = v99;
    int * v102 = v15->cache_vals;
    int v198 = ((((((int)((unsigned int)((int)((unsigned int)v19 >> 2)) >> 1)) & 1) * 2) + ((((v39 + ((~(((v41 ^ -1) | (-(v41 ^ -1))) >> 31)) & 2)) - (v42 + ((~(((v43 ^ -1) | (-(v43 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
    v102[v198] = v100;
    int * v104 = v15->cache_tags;
    int v201 = ((((int)((unsigned int)((int)((unsigned int)v19 >> 2)) >> 1)) & 1) * 2) + ((((v39 + ((~(((v41 ^ -1) | (-(v41 ^ -1))) >> 31)) & 2)) - (v42 + ((~(((v43 ^ -1) | (-(v43 ^ -1))) >> 31)) & 2))) >> 31) & 1);
    int v202 = (int)((unsigned int)((int)((unsigned int)v19 >> 2)) >> 1);
    v104[v201] = v202;
    int * v106 = v15->cache_dirty;
    v106[v201] = 0;
    int * v108 = v15->cache_age;
    v108[v201] = 1;
    int * v110 = v15->cache_age;
    int v111 = v110[v201];
    int v112 = v110[v130];
    int v208 = v112 + ((int)((unsigned int)(v112 - v111) >> 31));
    v110[v130] = v208;
    int * v114 = v15->cache_age;
    int v115 = v114[v131];
    int v210 = v115 + ((int)((unsigned int)(v115 - v111) >> 31));
    v114[v131] = v210;
    int * v117 = v15->cache_age;
    v117[v201] = 0;
    v120 = v201;
  }
  int v213 = (v120 * 2) + (((int)((unsigned int)v19 >> 2)) & 1);
  int v121 = v27[v213];
  int * v122 = v15->regs;
  v122[12] = v121;
  struct StateT * v124 = slot_2(v15);
  return v124;
}

struct StateT * slot_8(struct StateT * v280) {
  int v281 = v280->timer;
  int v288 = v281 + 1;
  v280->timer = v288;
  int * v283 = v280->regs;
  int v284 = v283[12];
  int v291 = v284 + 72;
  v283[12] = v291;
  struct StateT * v286 = slot_9(v280);
  return v286;
}

struct StateT * slot_4(struct StateT * v248) {
  int v249 = v248->timer;
  int v252 = v249 + 1;
  v248->timer = v252;
  return v248;
}

struct StateT * slot_13(struct StateT * v543) {
  int v544 = v543->timer;
  int v550 = v544 + 1;
  v543->timer = v550;
  int * v546 = v543->regs;
  v546[10] = 0;
  struct StateT * v548 = slot_14(v543);
  return v548;
}

struct StateT * slot_15(struct StateT * v569) {
  int v570 = v569->timer;
  int v680 = v570 + 1;
  v569->timer = v680;
  int * v572 = v569->regs;
  int v573 = v572[10];
  int * v574 = v569->cache_tags;
  int v684 = (((int)((unsigned int)((int)((unsigned int)(v573 + 4) >> 2)) >> 1)) & 1) * 2;
  int v575 = v574[v684];
  int v685 = ((((int)((unsigned int)((int)((unsigned int)(v573 + 4) >> 2)) >> 1)) & 1) * 2) + 1;
  int v576 = v574[v685];
  int v686 = 4 + ((((int)((unsigned int)((int)((unsigned int)(v573 + 4) >> 2)) >> 1)) & 3) * 2);
  int v577 = v574[v686];
  int v687 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v573 + 4) >> 2)) >> 1)) & 3) * 2)) + 1;
  int v578 = v574[v687];
  int v579 = v569->timer;
  int v688 = v579 + ((100 ^ (((~(((v577 ^ ((int)((unsigned int)((int)((unsigned int)(v573 + 4) >> 2)) >> 1))) | (-(v577 ^ ((int)((unsigned int)((int)((unsigned int)(v573 + 4) >> 2)) >> 1))))) >> 31)) | (~(((v578 ^ ((int)((unsigned int)((int)((unsigned int)(v573 + 4) >> 2)) >> 1))) | (-(v578 ^ ((int)((unsigned int)((int)((unsigned int)(v573 + 4) >> 2)) >> 1))))) >> 31))) & 104)) ^ (((~(((v575 ^ ((int)((unsigned int)((int)((unsigned int)(v573 + 4) >> 2)) >> 1))) | (-(v575 ^ ((int)((unsigned int)((int)((unsigned int)(v573 + 4) >> 2)) >> 1))))) >> 31)) | (~(((v576 ^ ((int)((unsigned int)((int)((unsigned int)(v573 + 4) >> 2)) >> 1))) | (-(v576 ^ ((int)((unsigned int)((int)((unsigned int)(v573 + 4) >> 2)) >> 1))))) >> 31))) & (1 ^ (100 ^ (((~(((v577 ^ ((int)((unsigned int)((int)((unsigned int)(v573 + 4) >> 2)) >> 1))) | (-(v577 ^ ((int)((unsigned int)((int)((unsigned int)(v573 + 4) >> 2)) >> 1))))) >> 31)) | (~(((v578 ^ ((int)((unsigned int)((int)((unsigned int)(v573 + 4) >> 2)) >> 1))) | (-(v578 ^ ((int)((unsigned int)((int)((unsigned int)(v573 + 4) >> 2)) >> 1))))) >> 31))) & 104)))));
  v569->timer = v688;
  int * v581 = v569->cache_vals;
  bool v689 = !(((~(((v575 ^ ((int)((unsigned int)((int)((unsigned int)(v573 + 4) >> 2)) >> 1))) | (-(v575 ^ ((int)((unsigned int)((int)((unsigned int)(v573 + 4) >> 2)) >> 1))))) >> 31)) | (~(((v576 ^ ((int)((unsigned int)((int)((unsigned int)(v573 + 4) >> 2)) >> 1))) | (-(v576 ^ ((int)((unsigned int)((int)((unsigned int)(v573 + 4) >> 2)) >> 1))))) >> 31))) == 0);
  int v674;
  if (v689) {
    int * v582 = v569->cache_age;
    int v691 = ((((int)((unsigned int)((int)((unsigned int)(v573 + 4) >> 2)) >> 1)) & 1) * 2) + ((~(((v576 ^ ((int)((unsigned int)((int)((unsigned int)(v573 + 4) >> 2)) >> 1))) | (-(v576 ^ ((int)((unsigned int)((int)((unsigned int)(v573 + 4) >> 2)) >> 1))))) >> 31)) & 1);
    int v583 = v582[v691];
    int v584 = v582[v684];
    int v692 = v584 + ((int)((unsigned int)(v584 - v583) >> 31));
    v582[v684] = v692;
    int * v586 = v569->cache_age;
    int v587 = v586[v685];
    int v694 = v587 + ((int)((unsigned int)(v587 - v583) >> 31));
    v586[v685] = v694;
    int * v589 = v569->cache_age;
    v589[v691] = 0;
    v674 = v691;
  } else {
    int * v592 = v569->cache_age;
    int v698 = (((int)((unsigned int)((int)((unsigned int)(v573 + 4) >> 2)) >> 1)) & 1) * 2;
    int v593 = v592[v698];
    int * v594 = v569->cache_tags;
    int v595 = v594[v698];
    int v596 = v592[v685];
    int v597 = v594[v685];
    bool v700 = !(((~(((v577 ^ ((int)((unsigned int)((int)((unsigned int)(v573 + 4) >> 2)) >> 1))) | (-(v577 ^ ((int)((unsigned int)((int)((unsigned int)(v573 + 4) >> 2)) >> 1))))) >> 31)) | (~(((v578 ^ ((int)((unsigned int)((int)((unsigned int)(v573 + 4) >> 2)) >> 1))) | (-(v578 ^ ((int)((unsigned int)((int)((unsigned int)(v573 + 4) >> 2)) >> 1))))) >> 31))) == 0);
    int v651;
    if (v700) {
      int * v598 = v569->cache_age;
      int v702 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v573 + 4) >> 2)) >> 1)) & 3) * 2)) + ((~(((v578 ^ ((int)((unsigned int)((int)((unsigned int)(v573 + 4) >> 2)) >> 1))) | (-(v578 ^ ((int)((unsigned int)((int)((unsigned int)(v573 + 4) >> 2)) >> 1))))) >> 31)) & 1);
      int v599 = v598[v702];
      int v600 = v598[v686];
      int v703 = v600 + ((int)((unsigned int)(v600 - v599) >> 31));
      v598[v686] = v703;
      int * v602 = v569->cache_age;
      int v603 = v602[v687];
      int v705 = v603 + ((int)((unsigned int)(v603 - v599) >> 31));
      v602[v687] = v705;
      int * v605 = v569->cache_age;
      v605[v702] = 0;
      v651 = v702;
    } else {
      int * v608 = v569->cache_age;
      int v709 = 4 + ((((int)((unsigned int)((int)((unsigned int)(v573 + 4) >> 2)) >> 1)) & 3) * 2);
      int v609 = v608[v709];
      int * v610 = v569->cache_tags;
      int v611 = v610[v709];
      int v612 = v608[v687];
      int v613 = v610[v687];
      int * v614 = v569->cache_dirty;
      int v712 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v573 + 4) >> 2)) >> 1)) & 3) * 2)) + ((((v609 + ((~(((v611 ^ -1) | (-(v611 ^ -1))) >> 31)) & 2)) - (v612 + ((~(((v613 ^ -1) | (-(v613 ^ -1))) >> 31)) & 2))) >> 31) & 1);
      int v615 = v614[v712];
      bool v713 = !(v615 == 0);
      if (v713) {
        int * v616 = v569->cache_tags;
        int v617 = v616[v712];
        int * v618 = v569->cache_vals;
        int v716 = ((4 + ((((int)((unsigned int)((int)((unsigned int)(v573 + 4) >> 2)) >> 1)) & 3) * 2)) + ((((v609 + ((~(((v611 ^ -1) | (-(v611 ^ -1))) >> 31)) & 2)) - (v612 + ((~(((v613 ^ -1) | (-(v613 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
        int v619 = v618[v716];
        int v717 = (((4 + ((((int)((unsigned int)((int)((unsigned int)(v573 + 4) >> 2)) >> 1)) & 3) * 2)) + ((((v609 + ((~(((v611 ^ -1) | (-(v611 ^ -1))) >> 31)) & 2)) - (v612 + ((~(((v613 ^ -1) | (-(v613 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
        int v620 = v618[v717];
        int * v621 = v569->mem;
        int v719 = v617 * 2;
        v621[v719] = v619;
        int * v623 = v569->mem;
        int v722 = (v617 * 2) + 1;
        v623[v722] = v620;
        ;
      } else {
        ;
      }
      int * v628 = v569->mem;
      int v727 = ((int)((unsigned int)((int)((unsigned int)(v573 + 4) >> 2)) >> 1)) * 2;
      int v629 = v628[v727];
      int v728 = (((int)((unsigned int)((int)((unsigned int)(v573 + 4) >> 2)) >> 1)) * 2) + 1;
      int v630 = v628[v728];
      int * v631 = v569->cache_vals;
      int v730 = ((4 + ((((int)((unsigned int)((int)((unsigned int)(v573 + 4) >> 2)) >> 1)) & 3) * 2)) + ((((v609 + ((~(((v611 ^ -1) | (-(v611 ^ -1))) >> 31)) & 2)) - (v612 + ((~(((v613 ^ -1) | (-(v613 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
      v631[v730] = v629;
      int * v633 = v569->cache_vals;
      int v733 = (((4 + ((((int)((unsigned int)((int)((unsigned int)(v573 + 4) >> 2)) >> 1)) & 3) * 2)) + ((((v609 + ((~(((v611 ^ -1) | (-(v611 ^ -1))) >> 31)) & 2)) - (v612 + ((~(((v613 ^ -1) | (-(v613 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
      v633[v733] = v630;
      int * v635 = v569->cache_tags;
      int v736 = (int)((unsigned int)((int)((unsigned int)(v573 + 4) >> 2)) >> 1);
      v635[v712] = v736;
      int * v637 = v569->cache_dirty;
      v637[v712] = 0;
      int * v639 = v569->cache_age;
      v639[v712] = 1;
      int * v641 = v569->cache_age;
      int v642 = v641[v712];
      int v643 = v641[v686];
      int v742 = v643 + ((int)((unsigned int)(v643 - v642) >> 31));
      v641[v686] = v742;
      int * v645 = v569->cache_age;
      int v646 = v645[v687];
      int v744 = v646 + ((int)((unsigned int)(v646 - v642) >> 31));
      v645[v687] = v744;
      int * v648 = v569->cache_age;
      v648[v712] = 0;
      v651 = v712;
    }
    int * v652 = v569->cache_vals;
    int v747 = v651 * 2;
    int v653 = v652[v747];
    int v748 = (v651 * 2) + 1;
    int v654 = v652[v748];
    int v749 = (((((int)((unsigned int)((int)((unsigned int)(v573 + 4) >> 2)) >> 1)) & 1) * 2) + ((((v593 + ((~(((v595 ^ -1) | (-(v595 ^ -1))) >> 31)) & 2)) - (v596 + ((~(((v597 ^ -1) | (-(v597 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
    v652[v749] = v653;
    int * v656 = v569->cache_vals;
    int v752 = ((((((int)((unsigned int)((int)((unsigned int)(v573 + 4) >> 2)) >> 1)) & 1) * 2) + ((((v593 + ((~(((v595 ^ -1) | (-(v595 ^ -1))) >> 31)) & 2)) - (v596 + ((~(((v597 ^ -1) | (-(v597 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
    v656[v752] = v654;
    int * v658 = v569->cache_tags;
    int v755 = ((((int)((unsigned int)((int)((unsigned int)(v573 + 4) >> 2)) >> 1)) & 1) * 2) + ((((v593 + ((~(((v595 ^ -1) | (-(v595 ^ -1))) >> 31)) & 2)) - (v596 + ((~(((v597 ^ -1) | (-(v597 ^ -1))) >> 31)) & 2))) >> 31) & 1);
    int v756 = (int)((unsigned int)((int)((unsigned int)(v573 + 4) >> 2)) >> 1);
    v658[v755] = v756;
    int * v660 = v569->cache_dirty;
    v660[v755] = 0;
    int * v662 = v569->cache_age;
    v662[v755] = 1;
    int * v664 = v569->cache_age;
    int v665 = v664[v755];
    int v666 = v664[v684];
    int v762 = v666 + ((int)((unsigned int)(v666 - v665) >> 31));
    v664[v684] = v762;
    int * v668 = v569->cache_age;
    int v669 = v668[v685];
    int v764 = v669 + ((int)((unsigned int)(v669 - v665) >> 31));
    v668[v685] = v764;
    int * v671 = v569->cache_age;
    v671[v755] = 0;
    v674 = v755;
  }
  int v767 = (v674 * 2) + (((int)((unsigned int)(v573 + 4) >> 2)) & 1);
  int v675 = v581[v767];
  int * v676 = v569->regs;
  v676[10] = v675;
  struct StateT * v678 = slot_16(v569);
  return v678;
}

struct StateT * slot_18(struct StateT * v992) {
  int v993 = v992->timer;
  int v1163 = v993 + 1;
  v992->timer = v1163;
  int * v995 = v992->regs;
  int v996 = v995[11];
  int v997 = v995[10];
  int * v998 = v992->cache_tags;
  int v1168 = (((int)((unsigned int)((int)((unsigned int)(v996 + 68) >> 2)) >> 1)) & 1) * 2;
  int v999 = v998[v1168];
  int v1169 = ((((int)((unsigned int)((int)((unsigned int)(v996 + 68) >> 2)) >> 1)) & 1) * 2) + 1;
  int v1000 = v998[v1169];
  int v1170 = 4 + ((((int)((unsigned int)((int)((unsigned int)(v996 + 68) >> 2)) >> 1)) & 3) * 2);
  int v1001 = v998[v1170];
  int v1171 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v996 + 68) >> 2)) >> 1)) & 3) * 2)) + 1;
  int v1002 = v998[v1171];
  int v1003 = v992->timer;
  int v1172 = v1003 + ((100 ^ (((~(((v1001 ^ ((int)((unsigned int)((int)((unsigned int)(v996 + 68) >> 2)) >> 1))) | (-(v1001 ^ ((int)((unsigned int)((int)((unsigned int)(v996 + 68) >> 2)) >> 1))))) >> 31)) | (~(((v1002 ^ ((int)((unsigned int)((int)((unsigned int)(v996 + 68) >> 2)) >> 1))) | (-(v1002 ^ ((int)((unsigned int)((int)((unsigned int)(v996 + 68) >> 2)) >> 1))))) >> 31))) & 104)) ^ (((~(((v999 ^ ((int)((unsigned int)((int)((unsigned int)(v996 + 68) >> 2)) >> 1))) | (-(v999 ^ ((int)((unsigned int)((int)((unsigned int)(v996 + 68) >> 2)) >> 1))))) >> 31)) | (~(((v1000 ^ ((int)((unsigned int)((int)((unsigned int)(v996 + 68) >> 2)) >> 1))) | (-(v1000 ^ ((int)((unsigned int)((int)((unsigned int)(v996 + 68) >> 2)) >> 1))))) >> 31))) & (1 ^ (100 ^ (((~(((v1001 ^ ((int)((unsigned int)((int)((unsigned int)(v996 + 68) >> 2)) >> 1))) | (-(v1001 ^ ((int)((unsigned int)((int)((unsigned int)(v996 + 68) >> 2)) >> 1))))) >> 31)) | (~(((v1002 ^ ((int)((unsigned int)((int)((unsigned int)(v996 + 68) >> 2)) >> 1))) | (-(v1002 ^ ((int)((unsigned int)((int)((unsigned int)(v996 + 68) >> 2)) >> 1))))) >> 31))) & 104)))));
  v992->timer = v1172;
  bool v1173 = !(((~(((v999 ^ ((int)((unsigned int)((int)((unsigned int)(v996 + 68) >> 2)) >> 1))) | (-(v999 ^ ((int)((unsigned int)((int)((unsigned int)(v996 + 68) >> 2)) >> 1))))) >> 31)) | (~(((v1000 ^ ((int)((unsigned int)((int)((unsigned int)(v996 + 68) >> 2)) >> 1))) | (-(v1000 ^ ((int)((unsigned int)((int)((unsigned int)(v996 + 68) >> 2)) >> 1))))) >> 31))) == 0);
  int v1097;
  if (v1173) {
    int * v1005 = v992->cache_age;
    int v1175 = ((((int)((unsigned int)((int)((unsigned int)(v996 + 68) >> 2)) >> 1)) & 1) * 2) + ((~(((v1000 ^ ((int)((unsigned int)((int)((unsigned int)(v996 + 68) >> 2)) >> 1))) | (-(v1000 ^ ((int)((unsigned int)((int)((unsigned int)(v996 + 68) >> 2)) >> 1))))) >> 31)) & 1);
    int v1006 = v1005[v1175];
    int v1007 = v1005[v1168];
    int v1176 = v1007 + ((int)((unsigned int)(v1007 - v1006) >> 31));
    v1005[v1168] = v1176;
    int * v1009 = v992->cache_age;
    int v1010 = v1009[v1169];
    int v1178 = v1010 + ((int)((unsigned int)(v1010 - v1006) >> 31));
    v1009[v1169] = v1178;
    int * v1012 = v992->cache_age;
    v1012[v1175] = 0;
    v1097 = v1175;
  } else {
    int * v1015 = v992->cache_age;
    int v1182 = (((int)((unsigned int)((int)((unsigned int)(v996 + 68) >> 2)) >> 1)) & 1) * 2;
    int v1016 = v1015[v1182];
    int * v1017 = v992->cache_tags;
    int v1018 = v1017[v1182];
    int v1019 = v1015[v1169];
    int v1020 = v1017[v1169];
    bool v1184 = !(((~(((v1001 ^ ((int)((unsigned int)((int)((unsigned int)(v996 + 68) >> 2)) >> 1))) | (-(v1001 ^ ((int)((unsigned int)((int)((unsigned int)(v996 + 68) >> 2)) >> 1))))) >> 31)) | (~(((v1002 ^ ((int)((unsigned int)((int)((unsigned int)(v996 + 68) >> 2)) >> 1))) | (-(v1002 ^ ((int)((unsigned int)((int)((unsigned int)(v996 + 68) >> 2)) >> 1))))) >> 31))) == 0);
    int v1074;
    if (v1184) {
      int * v1021 = v992->cache_age;
      int v1186 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v996 + 68) >> 2)) >> 1)) & 3) * 2)) + ((~(((v1002 ^ ((int)((unsigned int)((int)((unsigned int)(v996 + 68) >> 2)) >> 1))) | (-(v1002 ^ ((int)((unsigned int)((int)((unsigned int)(v996 + 68) >> 2)) >> 1))))) >> 31)) & 1);
      int v1022 = v1021[v1186];
      int v1023 = v1021[v1170];
      int v1187 = v1023 + ((int)((unsigned int)(v1023 - v1022) >> 31));
      v1021[v1170] = v1187;
      int * v1025 = v992->cache_age;
      int v1026 = v1025[v1171];
      int v1189 = v1026 + ((int)((unsigned int)(v1026 - v1022) >> 31));
      v1025[v1171] = v1189;
      int * v1028 = v992->cache_age;
      v1028[v1186] = 0;
      v1074 = v1186;
    } else {
      int * v1031 = v992->cache_age;
      int v1193 = 4 + ((((int)((unsigned int)((int)((unsigned int)(v996 + 68) >> 2)) >> 1)) & 3) * 2);
      int v1032 = v1031[v1193];
      int * v1033 = v992->cache_tags;
      int v1034 = v1033[v1193];
      int v1035 = v1031[v1171];
      int v1036 = v1033[v1171];
      int * v1037 = v992->cache_dirty;
      int v1196 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v996 + 68) >> 2)) >> 1)) & 3) * 2)) + ((((v1032 + ((~(((v1034 ^ -1) | (-(v1034 ^ -1))) >> 31)) & 2)) - (v1035 + ((~(((v1036 ^ -1) | (-(v1036 ^ -1))) >> 31)) & 2))) >> 31) & 1);
      int v1038 = v1037[v1196];
      bool v1197 = !(v1038 == 0);
      if (v1197) {
        int * v1039 = v992->cache_tags;
        int v1040 = v1039[v1196];
        int * v1041 = v992->cache_vals;
        int v1200 = ((4 + ((((int)((unsigned int)((int)((unsigned int)(v996 + 68) >> 2)) >> 1)) & 3) * 2)) + ((((v1032 + ((~(((v1034 ^ -1) | (-(v1034 ^ -1))) >> 31)) & 2)) - (v1035 + ((~(((v1036 ^ -1) | (-(v1036 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
        int v1042 = v1041[v1200];
        int v1201 = (((4 + ((((int)((unsigned int)((int)((unsigned int)(v996 + 68) >> 2)) >> 1)) & 3) * 2)) + ((((v1032 + ((~(((v1034 ^ -1) | (-(v1034 ^ -1))) >> 31)) & 2)) - (v1035 + ((~(((v1036 ^ -1) | (-(v1036 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
        int v1043 = v1041[v1201];
        int * v1044 = v992->mem;
        int v1203 = v1040 * 2;
        v1044[v1203] = v1042;
        int * v1046 = v992->mem;
        int v1206 = (v1040 * 2) + 1;
        v1046[v1206] = v1043;
        ;
      } else {
        ;
      }
      int * v1051 = v992->mem;
      int v1211 = ((int)((unsigned int)((int)((unsigned int)(v996 + 68) >> 2)) >> 1)) * 2;
      int v1052 = v1051[v1211];
      int v1212 = (((int)((unsigned int)((int)((unsigned int)(v996 + 68) >> 2)) >> 1)) * 2) + 1;
      int v1053 = v1051[v1212];
      int * v1054 = v992->cache_vals;
      int v1214 = ((4 + ((((int)((unsigned int)((int)((unsigned int)(v996 + 68) >> 2)) >> 1)) & 3) * 2)) + ((((v1032 + ((~(((v1034 ^ -1) | (-(v1034 ^ -1))) >> 31)) & 2)) - (v1035 + ((~(((v1036 ^ -1) | (-(v1036 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
      v1054[v1214] = v1052;
      int * v1056 = v992->cache_vals;
      int v1217 = (((4 + ((((int)((unsigned int)((int)((unsigned int)(v996 + 68) >> 2)) >> 1)) & 3) * 2)) + ((((v1032 + ((~(((v1034 ^ -1) | (-(v1034 ^ -1))) >> 31)) & 2)) - (v1035 + ((~(((v1036 ^ -1) | (-(v1036 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
      v1056[v1217] = v1053;
      int * v1058 = v992->cache_tags;
      int v1220 = (int)((unsigned int)((int)((unsigned int)(v996 + 68) >> 2)) >> 1);
      v1058[v1196] = v1220;
      int * v1060 = v992->cache_dirty;
      v1060[v1196] = 0;
      int * v1062 = v992->cache_age;
      v1062[v1196] = 1;
      int * v1064 = v992->cache_age;
      int v1065 = v1064[v1196];
      int v1066 = v1064[v1170];
      int v1226 = v1066 + ((int)((unsigned int)(v1066 - v1065) >> 31));
      v1064[v1170] = v1226;
      int * v1068 = v992->cache_age;
      int v1069 = v1068[v1171];
      int v1228 = v1069 + ((int)((unsigned int)(v1069 - v1065) >> 31));
      v1068[v1171] = v1228;
      int * v1071 = v992->cache_age;
      v1071[v1196] = 0;
      v1074 = v1196;
    }
    int * v1075 = v992->cache_vals;
    int v1231 = v1074 * 2;
    int v1076 = v1075[v1231];
    int v1232 = (v1074 * 2) + 1;
    int v1077 = v1075[v1232];
    int v1233 = (((((int)((unsigned int)((int)((unsigned int)(v996 + 68) >> 2)) >> 1)) & 1) * 2) + ((((v1016 + ((~(((v1018 ^ -1) | (-(v1018 ^ -1))) >> 31)) & 2)) - (v1019 + ((~(((v1020 ^ -1) | (-(v1020 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
    v1075[v1233] = v1076;
    int * v1079 = v992->cache_vals;
    int v1236 = ((((((int)((unsigned int)((int)((unsigned int)(v996 + 68) >> 2)) >> 1)) & 1) * 2) + ((((v1016 + ((~(((v1018 ^ -1) | (-(v1018 ^ -1))) >> 31)) & 2)) - (v1019 + ((~(((v1020 ^ -1) | (-(v1020 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
    v1079[v1236] = v1077;
    int * v1081 = v992->cache_tags;
    int v1239 = ((((int)((unsigned int)((int)((unsigned int)(v996 + 68) >> 2)) >> 1)) & 1) * 2) + ((((v1016 + ((~(((v1018 ^ -1) | (-(v1018 ^ -1))) >> 31)) & 2)) - (v1019 + ((~(((v1020 ^ -1) | (-(v1020 ^ -1))) >> 31)) & 2))) >> 31) & 1);
    int v1240 = (int)((unsigned int)((int)((unsigned int)(v996 + 68) >> 2)) >> 1);
    v1081[v1239] = v1240;
    int * v1083 = v992->cache_dirty;
    v1083[v1239] = 0;
    int * v1085 = v992->cache_age;
    v1085[v1239] = 1;
    int * v1087 = v992->cache_age;
    int v1088 = v1087[v1239];
    int v1089 = v1087[v1168];
    int v1246 = v1089 + ((int)((unsigned int)(v1089 - v1088) >> 31));
    v1087[v1168] = v1246;
    int * v1091 = v992->cache_age;
    int v1092 = v1091[v1169];
    int v1248 = v1092 + ((int)((unsigned int)(v1092 - v1088) >> 31));
    v1091[v1169] = v1248;
    int * v1094 = v992->cache_age;
    v1094[v1239] = 0;
    v1097 = v1239;
  }
  int * v1098 = v992->cache_vals;
  int v1251 = (v1097 * 2) + (((int)((unsigned int)(v996 + 68) >> 2)) & 1);
  v1098[v1251] = v997;
  int * v1100 = v992->cache_tags;
  int v1101 = v1100[v1170];
  int v1102 = v1100[v1171];
  bool v1254 = !(((~(((v1101 ^ ((int)((unsigned int)((int)((unsigned int)(v996 + 68) >> 2)) >> 1))) | (-(v1101 ^ ((int)((unsigned int)((int)((unsigned int)(v996 + 68) >> 2)) >> 1))))) >> 31)) | (~(((v1102 ^ ((int)((unsigned int)((int)((unsigned int)(v996 + 68) >> 2)) >> 1))) | (-(v1102 ^ ((int)((unsigned int)((int)((unsigned int)(v996 + 68) >> 2)) >> 1))))) >> 31))) == 0);
  int v1156;
  if (v1254) {
    int * v1103 = v992->cache_age;
    int v1256 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v996 + 68) >> 2)) >> 1)) & 3) * 2)) + ((~(((v1102 ^ ((int)((unsigned int)((int)((unsigned int)(v996 + 68) >> 2)) >> 1))) | (-(v1102 ^ ((int)((unsigned int)((int)((unsigned int)(v996 + 68) >> 2)) >> 1))))) >> 31)) & 1);
    int v1104 = v1103[v1256];
    int v1105 = v1103[v1170];
    int v1257 = v1105 + ((int)((unsigned int)(v1105 - v1104) >> 31));
    v1103[v1170] = v1257;
    int * v1107 = v992->cache_age;
    int v1108 = v1107[v1171];
    int v1259 = v1108 + ((int)((unsigned int)(v1108 - v1104) >> 31));
    v1107[v1171] = v1259;
    int * v1110 = v992->cache_age;
    v1110[v1256] = 0;
    v1156 = v1256;
  } else {
    int * v1113 = v992->cache_age;
    int v1263 = 4 + ((((int)((unsigned int)((int)((unsigned int)(v996 + 68) >> 2)) >> 1)) & 3) * 2);
    int v1114 = v1113[v1263];
    int * v1115 = v992->cache_tags;
    int v1116 = v1115[v1263];
    int v1117 = v1113[v1171];
    int v1118 = v1115[v1171];
    int * v1119 = v992->cache_dirty;
    int v1266 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v996 + 68) >> 2)) >> 1)) & 3) * 2)) + ((((v1114 + ((~(((v1116 ^ -1) | (-(v1116 ^ -1))) >> 31)) & 2)) - (v1117 + ((~(((v1118 ^ -1) | (-(v1118 ^ -1))) >> 31)) & 2))) >> 31) & 1);
    int v1120 = v1119[v1266];
    bool v1267 = !(v1120 == 0);
    if (v1267) {
      int * v1121 = v992->cache_tags;
      int v1122 = v1121[v1266];
      int * v1123 = v992->cache_vals;
      int v1270 = ((4 + ((((int)((unsigned int)((int)((unsigned int)(v996 + 68) >> 2)) >> 1)) & 3) * 2)) + ((((v1114 + ((~(((v1116 ^ -1) | (-(v1116 ^ -1))) >> 31)) & 2)) - (v1117 + ((~(((v1118 ^ -1) | (-(v1118 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
      int v1124 = v1123[v1270];
      int v1271 = (((4 + ((((int)((unsigned int)((int)((unsigned int)(v996 + 68) >> 2)) >> 1)) & 3) * 2)) + ((((v1114 + ((~(((v1116 ^ -1) | (-(v1116 ^ -1))) >> 31)) & 2)) - (v1117 + ((~(((v1118 ^ -1) | (-(v1118 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
      int v1125 = v1123[v1271];
      int * v1126 = v992->mem;
      int v1273 = v1122 * 2;
      v1126[v1273] = v1124;
      int * v1128 = v992->mem;
      int v1276 = (v1122 * 2) + 1;
      v1128[v1276] = v1125;
      ;
    } else {
      ;
    }
    int * v1133 = v992->mem;
    int v1281 = ((int)((unsigned int)((int)((unsigned int)(v996 + 68) >> 2)) >> 1)) * 2;
    int v1134 = v1133[v1281];
    int v1282 = (((int)((unsigned int)((int)((unsigned int)(v996 + 68) >> 2)) >> 1)) * 2) + 1;
    int v1135 = v1133[v1282];
    int * v1136 = v992->cache_vals;
    int v1284 = ((4 + ((((int)((unsigned int)((int)((unsigned int)(v996 + 68) >> 2)) >> 1)) & 3) * 2)) + ((((v1114 + ((~(((v1116 ^ -1) | (-(v1116 ^ -1))) >> 31)) & 2)) - (v1117 + ((~(((v1118 ^ -1) | (-(v1118 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
    v1136[v1284] = v1134;
    int * v1138 = v992->cache_vals;
    int v1287 = (((4 + ((((int)((unsigned int)((int)((unsigned int)(v996 + 68) >> 2)) >> 1)) & 3) * 2)) + ((((v1114 + ((~(((v1116 ^ -1) | (-(v1116 ^ -1))) >> 31)) & 2)) - (v1117 + ((~(((v1118 ^ -1) | (-(v1118 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
    v1138[v1287] = v1135;
    int * v1140 = v992->cache_tags;
    int v1290 = (int)((unsigned int)((int)((unsigned int)(v996 + 68) >> 2)) >> 1);
    v1140[v1266] = v1290;
    int * v1142 = v992->cache_dirty;
    v1142[v1266] = 0;
    int * v1144 = v992->cache_age;
    v1144[v1266] = 1;
    int * v1146 = v992->cache_age;
    int v1147 = v1146[v1266];
    int v1148 = v1146[v1170];
    int v1296 = v1148 + ((int)((unsigned int)(v1148 - v1147) >> 31));
    v1146[v1170] = v1296;
    int * v1150 = v992->cache_age;
    int v1151 = v1150[v1171];
    int v1298 = v1151 + ((int)((unsigned int)(v1151 - v1147) >> 31));
    v1150[v1171] = v1298;
    int * v1153 = v992->cache_age;
    v1153[v1266] = 0;
    v1156 = v1266;
  }
  int * v1157 = v992->cache_vals;
  int v1301 = (v1156 * 2) + (((int)((unsigned int)(v996 + 68) >> 2)) & 1);
  v1157[v1301] = v997;
  int * v1159 = v992->cache_dirty;
  v1159[v1156] = 1;
  struct StateT * v1161 = slot_4(v992);
  return v1161;
}

struct StateT * slot_9(struct StateT * v294) {
  int v295 = v294->timer;
  int v303 = v295 + 1;
  v294->timer = v303;
  int * v297 = v294->regs;
  int v298 = v297[12];
  int v299 = v297[10];
  int v307 = v298 + v299;
  v297[10] = v307;
  struct StateT * v301 = slot_10(v294);
  return v301;
}

struct StateT * slot_11(struct StateT * v513) {
  int v514 = v513->timer;
  int v518 = v514 + 1;
  v513->timer = v518;
  struct StateT * v516 = slot_12(v513);
  return v516;
}

struct StateT * slot_0(struct StateT * v2) {
  int v3 = v2->timer;
  int v9 = v3 + 1;
  v2->timer = v9;
  int * v5 = v2->regs;
  v5[12] = 0;
  struct StateT * v7 = slot_1(v2);
  return v7;
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
  int k = bounded(0, 20);
  s1.regs[11] = k;
  s2.regs[11] = k;
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