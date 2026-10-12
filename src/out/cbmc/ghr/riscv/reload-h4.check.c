// verify: leak (CBMC should report VERIFICATION FAILED) [unwind 129]
#define NUM_REGS 32
#define MEM_SIZE 64
#define SECRET_SIZE 10
#define SECRET_OFFSET 20
#define CACHE_ENTRIES 12
#define CACHE_WORDS 24
#define PHT_ENTRIES 128
#define HISTORY_BITS 4

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

struct StateG {
  int regs[32];
  int mem[64];
  int saved_regs[32];
  int reg_ready[32];
  int cache_tags[12];
  int cache_dirty[12];
  int cache_age[12];
  int cache_vals[24];
  int pht[128];
  int timer;
};

struct StateG * slot_14(struct StateG * v769);
struct StateG * slot_6(struct StateG * v116);
struct StateG * slot_16(struct StateG * v1184);
struct StateG * slot_5(struct StateG * v92);
struct StateG * slot_2(struct StateG * v28);
struct StateG * slot_7(struct StateG * v124);
struct StateG * slot_3(struct StateG * v41);
struct StateG * snippet(struct StateG * v0);
struct StateG * slot_10(struct StateG * v537);
struct StateG * slot_1(struct StateG * v15);
struct StateG * slot_8(struct StateG * v141);
struct StateG * slot_4(struct StateG * v61);
struct StateG * slot_13(struct StateG * v755);
struct StateG * slot_15(struct StateG * v980);
struct StateG * slot_18(struct StateG * v1247);
struct StateG * slot_11(struct StateG * v741);
struct StateG * slot_0(struct StateG * v2);
struct StateG * slot_14(struct StateG * v769) {
  int * v770 = v769->saved_regs;
  int * v771 = v769->regs;
  int v772 = v771[12];
  v770[12] = v772;
  int v774 = v769->timer;
  int v888 = v774 + 1;
  v769->timer = v888;
  int * v776 = v769->regs;
  int v777 = v776[11];
  int * v778 = v769->cache_tags;
  int v892 = (((int)((unsigned int)((int)((unsigned int)v777 >> 2)) >> 1)) & 1) * 2;
  int v779 = v778[v892];
  int v893 = ((((int)((unsigned int)((int)((unsigned int)v777 >> 2)) >> 1)) & 1) * 2) + 1;
  int v780 = v778[v893];
  int v894 = 4 + ((((int)((unsigned int)((int)((unsigned int)v777 >> 2)) >> 1)) & 3) * 2);
  int v781 = v778[v894];
  int v895 = (4 + ((((int)((unsigned int)((int)((unsigned int)v777 >> 2)) >> 1)) & 3) * 2)) + 1;
  int v782 = v778[v895];
  int v783 = v769->timer;
  int v896 = v783 + ((100 ^ (((~(((v781 ^ ((int)((unsigned int)((int)((unsigned int)v777 >> 2)) >> 1))) | (-(v781 ^ ((int)((unsigned int)((int)((unsigned int)v777 >> 2)) >> 1))))) >> 31)) | (~(((v782 ^ ((int)((unsigned int)((int)((unsigned int)v777 >> 2)) >> 1))) | (-(v782 ^ ((int)((unsigned int)((int)((unsigned int)v777 >> 2)) >> 1))))) >> 31))) & 104)) ^ (((~(((v779 ^ ((int)((unsigned int)((int)((unsigned int)v777 >> 2)) >> 1))) | (-(v779 ^ ((int)((unsigned int)((int)((unsigned int)v777 >> 2)) >> 1))))) >> 31)) | (~(((v780 ^ ((int)((unsigned int)((int)((unsigned int)v777 >> 2)) >> 1))) | (-(v780 ^ ((int)((unsigned int)((int)((unsigned int)v777 >> 2)) >> 1))))) >> 31))) & (1 ^ (100 ^ (((~(((v781 ^ ((int)((unsigned int)((int)((unsigned int)v777 >> 2)) >> 1))) | (-(v781 ^ ((int)((unsigned int)((int)((unsigned int)v777 >> 2)) >> 1))))) >> 31)) | (~(((v782 ^ ((int)((unsigned int)((int)((unsigned int)v777 >> 2)) >> 1))) | (-(v782 ^ ((int)((unsigned int)((int)((unsigned int)v777 >> 2)) >> 1))))) >> 31))) & 104)))));
  v769->timer = v896;
  int * v785 = v769->cache_vals;
  bool v897 = !(((~(((v779 ^ ((int)((unsigned int)((int)((unsigned int)v777 >> 2)) >> 1))) | (-(v779 ^ ((int)((unsigned int)((int)((unsigned int)v777 >> 2)) >> 1))))) >> 31)) | (~(((v780 ^ ((int)((unsigned int)((int)((unsigned int)v777 >> 2)) >> 1))) | (-(v780 ^ ((int)((unsigned int)((int)((unsigned int)v777 >> 2)) >> 1))))) >> 31))) == 0);
  int v878;
  if (v897) {
    int * v786 = v769->cache_age;
    int v899 = ((((int)((unsigned int)((int)((unsigned int)v777 >> 2)) >> 1)) & 1) * 2) + ((~(((v780 ^ ((int)((unsigned int)((int)((unsigned int)v777 >> 2)) >> 1))) | (-(v780 ^ ((int)((unsigned int)((int)((unsigned int)v777 >> 2)) >> 1))))) >> 31)) & 1);
    int v787 = v786[v899];
    int v788 = v786[v892];
    int v900 = v788 + ((int)((unsigned int)(v788 - v787) >> 31));
    v786[v892] = v900;
    int * v790 = v769->cache_age;
    int v791 = v790[v893];
    int v902 = v791 + ((int)((unsigned int)(v791 - v787) >> 31));
    v790[v893] = v902;
    int * v793 = v769->cache_age;
    v793[v899] = 0;
    v878 = v899;
  } else {
    int * v796 = v769->cache_age;
    int v906 = (((int)((unsigned int)((int)((unsigned int)v777 >> 2)) >> 1)) & 1) * 2;
    int v797 = v796[v906];
    int * v798 = v769->cache_tags;
    int v799 = v798[v906];
    int v800 = v796[v893];
    int v801 = v798[v893];
    bool v908 = !(((~(((v781 ^ ((int)((unsigned int)((int)((unsigned int)v777 >> 2)) >> 1))) | (-(v781 ^ ((int)((unsigned int)((int)((unsigned int)v777 >> 2)) >> 1))))) >> 31)) | (~(((v782 ^ ((int)((unsigned int)((int)((unsigned int)v777 >> 2)) >> 1))) | (-(v782 ^ ((int)((unsigned int)((int)((unsigned int)v777 >> 2)) >> 1))))) >> 31))) == 0);
    int v855;
    if (v908) {
      int * v802 = v769->cache_age;
      int v910 = (4 + ((((int)((unsigned int)((int)((unsigned int)v777 >> 2)) >> 1)) & 3) * 2)) + ((~(((v782 ^ ((int)((unsigned int)((int)((unsigned int)v777 >> 2)) >> 1))) | (-(v782 ^ ((int)((unsigned int)((int)((unsigned int)v777 >> 2)) >> 1))))) >> 31)) & 1);
      int v803 = v802[v910];
      int v804 = v802[v894];
      int v911 = v804 + ((int)((unsigned int)(v804 - v803) >> 31));
      v802[v894] = v911;
      int * v806 = v769->cache_age;
      int v807 = v806[v895];
      int v913 = v807 + ((int)((unsigned int)(v807 - v803) >> 31));
      v806[v895] = v913;
      int * v809 = v769->cache_age;
      v809[v910] = 0;
      v855 = v910;
    } else {
      int * v812 = v769->cache_age;
      int v917 = 4 + ((((int)((unsigned int)((int)((unsigned int)v777 >> 2)) >> 1)) & 3) * 2);
      int v813 = v812[v917];
      int * v814 = v769->cache_tags;
      int v815 = v814[v917];
      int v816 = v812[v895];
      int v817 = v814[v895];
      int * v818 = v769->cache_dirty;
      int v920 = (4 + ((((int)((unsigned int)((int)((unsigned int)v777 >> 2)) >> 1)) & 3) * 2)) + ((((v813 + ((~(((v815 ^ -1) | (-(v815 ^ -1))) >> 31)) & 2)) - (v816 + ((~(((v817 ^ -1) | (-(v817 ^ -1))) >> 31)) & 2))) >> 31) & 1);
      int v819 = v818[v920];
      bool v921 = !(v819 == 0);
      if (v921) {
        int * v820 = v769->cache_tags;
        int v821 = v820[v920];
        int * v822 = v769->cache_vals;
        int v924 = ((4 + ((((int)((unsigned int)((int)((unsigned int)v777 >> 2)) >> 1)) & 3) * 2)) + ((((v813 + ((~(((v815 ^ -1) | (-(v815 ^ -1))) >> 31)) & 2)) - (v816 + ((~(((v817 ^ -1) | (-(v817 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
        int v823 = v822[v924];
        int v925 = (((4 + ((((int)((unsigned int)((int)((unsigned int)v777 >> 2)) >> 1)) & 3) * 2)) + ((((v813 + ((~(((v815 ^ -1) | (-(v815 ^ -1))) >> 31)) & 2)) - (v816 + ((~(((v817 ^ -1) | (-(v817 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
        int v824 = v822[v925];
        int * v825 = v769->mem;
        int v927 = v821 * 2;
        v825[v927] = v823;
        int * v827 = v769->mem;
        int v930 = (v821 * 2) + 1;
        v827[v930] = v824;
        ;
      } else {
        ;
      }
      int * v832 = v769->mem;
      int v935 = ((int)((unsigned int)((int)((unsigned int)v777 >> 2)) >> 1)) * 2;
      int v833 = v832[v935];
      int v936 = (((int)((unsigned int)((int)((unsigned int)v777 >> 2)) >> 1)) * 2) + 1;
      int v834 = v832[v936];
      int * v835 = v769->cache_vals;
      int v938 = ((4 + ((((int)((unsigned int)((int)((unsigned int)v777 >> 2)) >> 1)) & 3) * 2)) + ((((v813 + ((~(((v815 ^ -1) | (-(v815 ^ -1))) >> 31)) & 2)) - (v816 + ((~(((v817 ^ -1) | (-(v817 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
      v835[v938] = v833;
      int * v837 = v769->cache_vals;
      int v941 = (((4 + ((((int)((unsigned int)((int)((unsigned int)v777 >> 2)) >> 1)) & 3) * 2)) + ((((v813 + ((~(((v815 ^ -1) | (-(v815 ^ -1))) >> 31)) & 2)) - (v816 + ((~(((v817 ^ -1) | (-(v817 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
      v837[v941] = v834;
      int * v839 = v769->cache_tags;
      int v944 = (int)((unsigned int)((int)((unsigned int)v777 >> 2)) >> 1);
      v839[v920] = v944;
      int * v841 = v769->cache_dirty;
      v841[v920] = 0;
      int * v843 = v769->cache_age;
      v843[v920] = 1;
      int * v845 = v769->cache_age;
      int v846 = v845[v920];
      int v847 = v845[v894];
      int v950 = v847 + ((int)((unsigned int)(v847 - v846) >> 31));
      v845[v894] = v950;
      int * v849 = v769->cache_age;
      int v850 = v849[v895];
      int v952 = v850 + ((int)((unsigned int)(v850 - v846) >> 31));
      v849[v895] = v952;
      int * v852 = v769->cache_age;
      v852[v920] = 0;
      v855 = v920;
    }
    int * v856 = v769->cache_vals;
    int v955 = v855 * 2;
    int v857 = v856[v955];
    int v956 = (v855 * 2) + 1;
    int v858 = v856[v956];
    int v957 = (((((int)((unsigned int)((int)((unsigned int)v777 >> 2)) >> 1)) & 1) * 2) + ((((v797 + ((~(((v799 ^ -1) | (-(v799 ^ -1))) >> 31)) & 2)) - (v800 + ((~(((v801 ^ -1) | (-(v801 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
    v856[v957] = v857;
    int * v860 = v769->cache_vals;
    int v960 = ((((((int)((unsigned int)((int)((unsigned int)v777 >> 2)) >> 1)) & 1) * 2) + ((((v797 + ((~(((v799 ^ -1) | (-(v799 ^ -1))) >> 31)) & 2)) - (v800 + ((~(((v801 ^ -1) | (-(v801 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
    v860[v960] = v858;
    int * v862 = v769->cache_tags;
    int v963 = ((((int)((unsigned int)((int)((unsigned int)v777 >> 2)) >> 1)) & 1) * 2) + ((((v797 + ((~(((v799 ^ -1) | (-(v799 ^ -1))) >> 31)) & 2)) - (v800 + ((~(((v801 ^ -1) | (-(v801 ^ -1))) >> 31)) & 2))) >> 31) & 1);
    int v964 = (int)((unsigned int)((int)((unsigned int)v777 >> 2)) >> 1);
    v862[v963] = v964;
    int * v864 = v769->cache_dirty;
    v864[v963] = 0;
    int * v866 = v769->cache_age;
    v866[v963] = 1;
    int * v868 = v769->cache_age;
    int v869 = v868[v963];
    int v870 = v868[v892];
    int v970 = v870 + ((int)((unsigned int)(v870 - v869) >> 31));
    v868[v892] = v970;
    int * v872 = v769->cache_age;
    int v873 = v872[v893];
    int v972 = v873 + ((int)((unsigned int)(v873 - v869) >> 31));
    v872[v893] = v972;
    int * v875 = v769->cache_age;
    v875[v963] = 0;
    v878 = v963;
  }
  int v975 = (v878 * 2) + (((int)((unsigned int)v777 >> 2)) & 1);
  int v879 = v785[v975];
  int * v880 = v769->regs;
  v880[12] = v879;
  struct StateG * v882 = slot_16(v769);
  return v882;
}

struct StateG * slot_6(struct StateG * v116) {
  int v117 = v116->timer;
  int v121 = v117 + 1;
  v116->timer = v121;
  struct StateG * v119 = slot_18(v116);
  return v119;
}

struct StateG * slot_16(struct StateG * v1184) {
  int * v1185 = v1184->regs;
  int v1186 = v1185[10];
  int v1187 = v1185[15];
  bool v1215 = v1186 >= v1187;
  struct StateG * v1210;
  if (v1215) {
    int * v1188 = v1184->pht;
    v1188[0] = 1;
    int v1190 = v1184->timer;
    int v1219 = v1190 + 15;
    v1184->timer = v1219;
    int * v1192 = v1184->saved_regs;
    int v1193 = v1192[5];
    int * v1194 = v1184->regs;
    v1194[5] = v1193;
    int * v1196 = v1184->saved_regs;
    int v1197 = v1196[11];
    int * v1198 = v1184->regs;
    v1198[11] = v1197;
    int * v1200 = v1184->saved_regs;
    int v1201 = v1200[12];
    int * v1202 = v1184->regs;
    v1202[12] = v1201;
    struct StateG * v1204 = slot_6(v1184);
    v1210 = v1204;
  } else {
    int * v1206 = v1184->pht;
    v1206[0] = 0;
    struct StateG * v1208 = slot_6(v1184);
    v1210 = v1208;
  }
  return v1210;
}

struct StateG * slot_5(struct StateG * v92) {
  int * v93 = v92->saved_regs;
  int * v94 = v92->regs;
  int v95 = v94[5];
  v93[5] = v95;
  int v97 = v92->timer;
  int v109 = v97 + 1;
  v92->timer = v109;
  int * v99 = v92->regs;
  int v100 = v99[13];
  int v101 = v99[10];
  int v113 = v100 + v101;
  v99[5] = v113;
  struct StateG * v103 = slot_8(v92);
  return v103;
}

struct StateG * slot_2(struct StateG * v28) {
  int v29 = v28->timer;
  int v35 = v29 + 1;
  v28->timer = v35;
  int * v31 = v28->regs;
  v31[15] = 80;
  struct StateG * v33 = slot_3(v28);
  return v33;
}

struct StateG * slot_7(struct StateG * v124) {
  int v125 = v124->timer;
  int v133 = v125 + 1;
  v124->timer = v133;
  int * v127 = v124->regs;
  int v128 = v127[13];
  int v129 = v127[10];
  int v138 = v128 + v129;
  v127[5] = v138;
  struct StateG * v131 = slot_10(v124);
  return v131;
}

struct StateG * slot_3(struct StateG * v41) {
  int v42 = v41->timer;
  int v52 = v42 + 1;
  v41->timer = v52;
  int * v44 = v41->pht;
  int v45 = v44[0];
  bool v55 = !(v45 == 0);
  struct StateG * v50;
  if (v55) {
    struct StateG * v46 = slot_4(v41);
    v50 = v46;
  } else {
    struct StateG * v48 = slot_5(v41);
    v50 = v48;
  }
  return v50;
}

struct StateG * snippet(struct StateG * v0) {
  struct StateG * v1 = slot_0(v0);
  return v1;
}

struct StateG * slot_10(struct StateG * v537) {
  int v538 = v537->timer;
  int v648 = v538 + 1;
  v537->timer = v648;
  int * v540 = v537->regs;
  int v541 = v540[5];
  int * v542 = v537->cache_tags;
  int v652 = (((int)((unsigned int)((int)((unsigned int)v541 >> 2)) >> 1)) & 1) * 2;
  int v543 = v542[v652];
  int v653 = ((((int)((unsigned int)((int)((unsigned int)v541 >> 2)) >> 1)) & 1) * 2) + 1;
  int v544 = v542[v653];
  int v654 = 4 + ((((int)((unsigned int)((int)((unsigned int)v541 >> 2)) >> 1)) & 3) * 2);
  int v545 = v542[v654];
  int v655 = (4 + ((((int)((unsigned int)((int)((unsigned int)v541 >> 2)) >> 1)) & 3) * 2)) + 1;
  int v546 = v542[v655];
  int v547 = v537->timer;
  int v656 = v547 + ((100 ^ (((~(((v545 ^ ((int)((unsigned int)((int)((unsigned int)v541 >> 2)) >> 1))) | (-(v545 ^ ((int)((unsigned int)((int)((unsigned int)v541 >> 2)) >> 1))))) >> 31)) | (~(((v546 ^ ((int)((unsigned int)((int)((unsigned int)v541 >> 2)) >> 1))) | (-(v546 ^ ((int)((unsigned int)((int)((unsigned int)v541 >> 2)) >> 1))))) >> 31))) & 104)) ^ (((~(((v543 ^ ((int)((unsigned int)((int)((unsigned int)v541 >> 2)) >> 1))) | (-(v543 ^ ((int)((unsigned int)((int)((unsigned int)v541 >> 2)) >> 1))))) >> 31)) | (~(((v544 ^ ((int)((unsigned int)((int)((unsigned int)v541 >> 2)) >> 1))) | (-(v544 ^ ((int)((unsigned int)((int)((unsigned int)v541 >> 2)) >> 1))))) >> 31))) & (1 ^ (100 ^ (((~(((v545 ^ ((int)((unsigned int)((int)((unsigned int)v541 >> 2)) >> 1))) | (-(v545 ^ ((int)((unsigned int)((int)((unsigned int)v541 >> 2)) >> 1))))) >> 31)) | (~(((v546 ^ ((int)((unsigned int)((int)((unsigned int)v541 >> 2)) >> 1))) | (-(v546 ^ ((int)((unsigned int)((int)((unsigned int)v541 >> 2)) >> 1))))) >> 31))) & 104)))));
  v537->timer = v656;
  int * v549 = v537->cache_vals;
  bool v657 = !(((~(((v543 ^ ((int)((unsigned int)((int)((unsigned int)v541 >> 2)) >> 1))) | (-(v543 ^ ((int)((unsigned int)((int)((unsigned int)v541 >> 2)) >> 1))))) >> 31)) | (~(((v544 ^ ((int)((unsigned int)((int)((unsigned int)v541 >> 2)) >> 1))) | (-(v544 ^ ((int)((unsigned int)((int)((unsigned int)v541 >> 2)) >> 1))))) >> 31))) == 0);
  int v642;
  if (v657) {
    int * v550 = v537->cache_age;
    int v659 = ((((int)((unsigned int)((int)((unsigned int)v541 >> 2)) >> 1)) & 1) * 2) + ((~(((v544 ^ ((int)((unsigned int)((int)((unsigned int)v541 >> 2)) >> 1))) | (-(v544 ^ ((int)((unsigned int)((int)((unsigned int)v541 >> 2)) >> 1))))) >> 31)) & 1);
    int v551 = v550[v659];
    int v552 = v550[v652];
    int v660 = v552 + ((int)((unsigned int)(v552 - v551) >> 31));
    v550[v652] = v660;
    int * v554 = v537->cache_age;
    int v555 = v554[v653];
    int v662 = v555 + ((int)((unsigned int)(v555 - v551) >> 31));
    v554[v653] = v662;
    int * v557 = v537->cache_age;
    v557[v659] = 0;
    v642 = v659;
  } else {
    int * v560 = v537->cache_age;
    int v666 = (((int)((unsigned int)((int)((unsigned int)v541 >> 2)) >> 1)) & 1) * 2;
    int v561 = v560[v666];
    int * v562 = v537->cache_tags;
    int v563 = v562[v666];
    int v564 = v560[v653];
    int v565 = v562[v653];
    bool v668 = !(((~(((v545 ^ ((int)((unsigned int)((int)((unsigned int)v541 >> 2)) >> 1))) | (-(v545 ^ ((int)((unsigned int)((int)((unsigned int)v541 >> 2)) >> 1))))) >> 31)) | (~(((v546 ^ ((int)((unsigned int)((int)((unsigned int)v541 >> 2)) >> 1))) | (-(v546 ^ ((int)((unsigned int)((int)((unsigned int)v541 >> 2)) >> 1))))) >> 31))) == 0);
    int v619;
    if (v668) {
      int * v566 = v537->cache_age;
      int v670 = (4 + ((((int)((unsigned int)((int)((unsigned int)v541 >> 2)) >> 1)) & 3) * 2)) + ((~(((v546 ^ ((int)((unsigned int)((int)((unsigned int)v541 >> 2)) >> 1))) | (-(v546 ^ ((int)((unsigned int)((int)((unsigned int)v541 >> 2)) >> 1))))) >> 31)) & 1);
      int v567 = v566[v670];
      int v568 = v566[v654];
      int v671 = v568 + ((int)((unsigned int)(v568 - v567) >> 31));
      v566[v654] = v671;
      int * v570 = v537->cache_age;
      int v571 = v570[v655];
      int v673 = v571 + ((int)((unsigned int)(v571 - v567) >> 31));
      v570[v655] = v673;
      int * v573 = v537->cache_age;
      v573[v670] = 0;
      v619 = v670;
    } else {
      int * v576 = v537->cache_age;
      int v677 = 4 + ((((int)((unsigned int)((int)((unsigned int)v541 >> 2)) >> 1)) & 3) * 2);
      int v577 = v576[v677];
      int * v578 = v537->cache_tags;
      int v579 = v578[v677];
      int v580 = v576[v655];
      int v581 = v578[v655];
      int * v582 = v537->cache_dirty;
      int v680 = (4 + ((((int)((unsigned int)((int)((unsigned int)v541 >> 2)) >> 1)) & 3) * 2)) + ((((v577 + ((~(((v579 ^ -1) | (-(v579 ^ -1))) >> 31)) & 2)) - (v580 + ((~(((v581 ^ -1) | (-(v581 ^ -1))) >> 31)) & 2))) >> 31) & 1);
      int v583 = v582[v680];
      bool v681 = !(v583 == 0);
      if (v681) {
        int * v584 = v537->cache_tags;
        int v585 = v584[v680];
        int * v586 = v537->cache_vals;
        int v684 = ((4 + ((((int)((unsigned int)((int)((unsigned int)v541 >> 2)) >> 1)) & 3) * 2)) + ((((v577 + ((~(((v579 ^ -1) | (-(v579 ^ -1))) >> 31)) & 2)) - (v580 + ((~(((v581 ^ -1) | (-(v581 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
        int v587 = v586[v684];
        int v685 = (((4 + ((((int)((unsigned int)((int)((unsigned int)v541 >> 2)) >> 1)) & 3) * 2)) + ((((v577 + ((~(((v579 ^ -1) | (-(v579 ^ -1))) >> 31)) & 2)) - (v580 + ((~(((v581 ^ -1) | (-(v581 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
        int v588 = v586[v685];
        int * v589 = v537->mem;
        int v687 = v585 * 2;
        v589[v687] = v587;
        int * v591 = v537->mem;
        int v690 = (v585 * 2) + 1;
        v591[v690] = v588;
        ;
      } else {
        ;
      }
      int * v596 = v537->mem;
      int v695 = ((int)((unsigned int)((int)((unsigned int)v541 >> 2)) >> 1)) * 2;
      int v597 = v596[v695];
      int v696 = (((int)((unsigned int)((int)((unsigned int)v541 >> 2)) >> 1)) * 2) + 1;
      int v598 = v596[v696];
      int * v599 = v537->cache_vals;
      int v698 = ((4 + ((((int)((unsigned int)((int)((unsigned int)v541 >> 2)) >> 1)) & 3) * 2)) + ((((v577 + ((~(((v579 ^ -1) | (-(v579 ^ -1))) >> 31)) & 2)) - (v580 + ((~(((v581 ^ -1) | (-(v581 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
      v599[v698] = v597;
      int * v601 = v537->cache_vals;
      int v701 = (((4 + ((((int)((unsigned int)((int)((unsigned int)v541 >> 2)) >> 1)) & 3) * 2)) + ((((v577 + ((~(((v579 ^ -1) | (-(v579 ^ -1))) >> 31)) & 2)) - (v580 + ((~(((v581 ^ -1) | (-(v581 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
      v601[v701] = v598;
      int * v603 = v537->cache_tags;
      int v704 = (int)((unsigned int)((int)((unsigned int)v541 >> 2)) >> 1);
      v603[v680] = v704;
      int * v605 = v537->cache_dirty;
      v605[v680] = 0;
      int * v607 = v537->cache_age;
      v607[v680] = 1;
      int * v609 = v537->cache_age;
      int v610 = v609[v680];
      int v611 = v609[v654];
      int v710 = v611 + ((int)((unsigned int)(v611 - v610) >> 31));
      v609[v654] = v710;
      int * v613 = v537->cache_age;
      int v614 = v613[v655];
      int v712 = v614 + ((int)((unsigned int)(v614 - v610) >> 31));
      v613[v655] = v712;
      int * v616 = v537->cache_age;
      v616[v680] = 0;
      v619 = v680;
    }
    int * v620 = v537->cache_vals;
    int v715 = v619 * 2;
    int v621 = v620[v715];
    int v716 = (v619 * 2) + 1;
    int v622 = v620[v716];
    int v717 = (((((int)((unsigned int)((int)((unsigned int)v541 >> 2)) >> 1)) & 1) * 2) + ((((v561 + ((~(((v563 ^ -1) | (-(v563 ^ -1))) >> 31)) & 2)) - (v564 + ((~(((v565 ^ -1) | (-(v565 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
    v620[v717] = v621;
    int * v624 = v537->cache_vals;
    int v720 = ((((((int)((unsigned int)((int)((unsigned int)v541 >> 2)) >> 1)) & 1) * 2) + ((((v561 + ((~(((v563 ^ -1) | (-(v563 ^ -1))) >> 31)) & 2)) - (v564 + ((~(((v565 ^ -1) | (-(v565 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
    v624[v720] = v622;
    int * v626 = v537->cache_tags;
    int v723 = ((((int)((unsigned int)((int)((unsigned int)v541 >> 2)) >> 1)) & 1) * 2) + ((((v561 + ((~(((v563 ^ -1) | (-(v563 ^ -1))) >> 31)) & 2)) - (v564 + ((~(((v565 ^ -1) | (-(v565 ^ -1))) >> 31)) & 2))) >> 31) & 1);
    int v724 = (int)((unsigned int)((int)((unsigned int)v541 >> 2)) >> 1);
    v626[v723] = v724;
    int * v628 = v537->cache_dirty;
    v628[v723] = 0;
    int * v630 = v537->cache_age;
    v630[v723] = 1;
    int * v632 = v537->cache_age;
    int v633 = v632[v723];
    int v634 = v632[v652];
    int v730 = v634 + ((int)((unsigned int)(v634 - v633) >> 31));
    v632[v652] = v730;
    int * v636 = v537->cache_age;
    int v637 = v636[v653];
    int v732 = v637 + ((int)((unsigned int)(v637 - v633) >> 31));
    v636[v653] = v732;
    int * v639 = v537->cache_age;
    v639[v723] = 0;
    v642 = v723;
  }
  int v735 = (v642 * 2) + (((int)((unsigned int)v541 >> 2)) & 1);
  int v643 = v549[v735];
  int * v644 = v537->regs;
  v644[11] = v643;
  struct StateG * v646 = slot_13(v537);
  return v646;
}

struct StateG * slot_1(struct StateG * v15) {
  int v16 = v15->timer;
  int v22 = v16 + 1;
  v15->timer = v22;
  int * v18 = v15->regs;
  v18[10] = 80;
  struct StateG * v20 = slot_2(v15);
  return v20;
}

struct StateG * slot_8(struct StateG * v141) {
  int * v142 = v141->saved_regs;
  int * v143 = v141->regs;
  int v144 = v143[11];
  v142[11] = v144;
  int v146 = v141->timer;
  int v260 = v146 + 1;
  v141->timer = v260;
  int * v148 = v141->regs;
  int v149 = v148[5];
  int * v150 = v141->cache_tags;
  int v264 = (((int)((unsigned int)((int)((unsigned int)v149 >> 2)) >> 1)) & 1) * 2;
  int v151 = v150[v264];
  int v265 = ((((int)((unsigned int)((int)((unsigned int)v149 >> 2)) >> 1)) & 1) * 2) + 1;
  int v152 = v150[v265];
  int v266 = 4 + ((((int)((unsigned int)((int)((unsigned int)v149 >> 2)) >> 1)) & 3) * 2);
  int v153 = v150[v266];
  int v267 = (4 + ((((int)((unsigned int)((int)((unsigned int)v149 >> 2)) >> 1)) & 3) * 2)) + 1;
  int v154 = v150[v267];
  int v155 = v141->timer;
  int v268 = v155 + ((100 ^ (((~(((v153 ^ ((int)((unsigned int)((int)((unsigned int)v149 >> 2)) >> 1))) | (-(v153 ^ ((int)((unsigned int)((int)((unsigned int)v149 >> 2)) >> 1))))) >> 31)) | (~(((v154 ^ ((int)((unsigned int)((int)((unsigned int)v149 >> 2)) >> 1))) | (-(v154 ^ ((int)((unsigned int)((int)((unsigned int)v149 >> 2)) >> 1))))) >> 31))) & 104)) ^ (((~(((v151 ^ ((int)((unsigned int)((int)((unsigned int)v149 >> 2)) >> 1))) | (-(v151 ^ ((int)((unsigned int)((int)((unsigned int)v149 >> 2)) >> 1))))) >> 31)) | (~(((v152 ^ ((int)((unsigned int)((int)((unsigned int)v149 >> 2)) >> 1))) | (-(v152 ^ ((int)((unsigned int)((int)((unsigned int)v149 >> 2)) >> 1))))) >> 31))) & (1 ^ (100 ^ (((~(((v153 ^ ((int)((unsigned int)((int)((unsigned int)v149 >> 2)) >> 1))) | (-(v153 ^ ((int)((unsigned int)((int)((unsigned int)v149 >> 2)) >> 1))))) >> 31)) | (~(((v154 ^ ((int)((unsigned int)((int)((unsigned int)v149 >> 2)) >> 1))) | (-(v154 ^ ((int)((unsigned int)((int)((unsigned int)v149 >> 2)) >> 1))))) >> 31))) & 104)))));
  v141->timer = v268;
  int * v157 = v141->cache_vals;
  bool v269 = !(((~(((v151 ^ ((int)((unsigned int)((int)((unsigned int)v149 >> 2)) >> 1))) | (-(v151 ^ ((int)((unsigned int)((int)((unsigned int)v149 >> 2)) >> 1))))) >> 31)) | (~(((v152 ^ ((int)((unsigned int)((int)((unsigned int)v149 >> 2)) >> 1))) | (-(v152 ^ ((int)((unsigned int)((int)((unsigned int)v149 >> 2)) >> 1))))) >> 31))) == 0);
  int v250;
  if (v269) {
    int * v158 = v141->cache_age;
    int v271 = ((((int)((unsigned int)((int)((unsigned int)v149 >> 2)) >> 1)) & 1) * 2) + ((~(((v152 ^ ((int)((unsigned int)((int)((unsigned int)v149 >> 2)) >> 1))) | (-(v152 ^ ((int)((unsigned int)((int)((unsigned int)v149 >> 2)) >> 1))))) >> 31)) & 1);
    int v159 = v158[v271];
    int v160 = v158[v264];
    int v272 = v160 + ((int)((unsigned int)(v160 - v159) >> 31));
    v158[v264] = v272;
    int * v162 = v141->cache_age;
    int v163 = v162[v265];
    int v274 = v163 + ((int)((unsigned int)(v163 - v159) >> 31));
    v162[v265] = v274;
    int * v165 = v141->cache_age;
    v165[v271] = 0;
    v250 = v271;
  } else {
    int * v168 = v141->cache_age;
    int v278 = (((int)((unsigned int)((int)((unsigned int)v149 >> 2)) >> 1)) & 1) * 2;
    int v169 = v168[v278];
    int * v170 = v141->cache_tags;
    int v171 = v170[v278];
    int v172 = v168[v265];
    int v173 = v170[v265];
    bool v280 = !(((~(((v153 ^ ((int)((unsigned int)((int)((unsigned int)v149 >> 2)) >> 1))) | (-(v153 ^ ((int)((unsigned int)((int)((unsigned int)v149 >> 2)) >> 1))))) >> 31)) | (~(((v154 ^ ((int)((unsigned int)((int)((unsigned int)v149 >> 2)) >> 1))) | (-(v154 ^ ((int)((unsigned int)((int)((unsigned int)v149 >> 2)) >> 1))))) >> 31))) == 0);
    int v227;
    if (v280) {
      int * v174 = v141->cache_age;
      int v282 = (4 + ((((int)((unsigned int)((int)((unsigned int)v149 >> 2)) >> 1)) & 3) * 2)) + ((~(((v154 ^ ((int)((unsigned int)((int)((unsigned int)v149 >> 2)) >> 1))) | (-(v154 ^ ((int)((unsigned int)((int)((unsigned int)v149 >> 2)) >> 1))))) >> 31)) & 1);
      int v175 = v174[v282];
      int v176 = v174[v266];
      int v283 = v176 + ((int)((unsigned int)(v176 - v175) >> 31));
      v174[v266] = v283;
      int * v178 = v141->cache_age;
      int v179 = v178[v267];
      int v285 = v179 + ((int)((unsigned int)(v179 - v175) >> 31));
      v178[v267] = v285;
      int * v181 = v141->cache_age;
      v181[v282] = 0;
      v227 = v282;
    } else {
      int * v184 = v141->cache_age;
      int v289 = 4 + ((((int)((unsigned int)((int)((unsigned int)v149 >> 2)) >> 1)) & 3) * 2);
      int v185 = v184[v289];
      int * v186 = v141->cache_tags;
      int v187 = v186[v289];
      int v188 = v184[v267];
      int v189 = v186[v267];
      int * v190 = v141->cache_dirty;
      int v292 = (4 + ((((int)((unsigned int)((int)((unsigned int)v149 >> 2)) >> 1)) & 3) * 2)) + ((((v185 + ((~(((v187 ^ -1) | (-(v187 ^ -1))) >> 31)) & 2)) - (v188 + ((~(((v189 ^ -1) | (-(v189 ^ -1))) >> 31)) & 2))) >> 31) & 1);
      int v191 = v190[v292];
      bool v293 = !(v191 == 0);
      if (v293) {
        int * v192 = v141->cache_tags;
        int v193 = v192[v292];
        int * v194 = v141->cache_vals;
        int v296 = ((4 + ((((int)((unsigned int)((int)((unsigned int)v149 >> 2)) >> 1)) & 3) * 2)) + ((((v185 + ((~(((v187 ^ -1) | (-(v187 ^ -1))) >> 31)) & 2)) - (v188 + ((~(((v189 ^ -1) | (-(v189 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
        int v195 = v194[v296];
        int v297 = (((4 + ((((int)((unsigned int)((int)((unsigned int)v149 >> 2)) >> 1)) & 3) * 2)) + ((((v185 + ((~(((v187 ^ -1) | (-(v187 ^ -1))) >> 31)) & 2)) - (v188 + ((~(((v189 ^ -1) | (-(v189 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
        int v196 = v194[v297];
        int * v197 = v141->mem;
        int v299 = v193 * 2;
        v197[v299] = v195;
        int * v199 = v141->mem;
        int v302 = (v193 * 2) + 1;
        v199[v302] = v196;
        ;
      } else {
        ;
      }
      int * v204 = v141->mem;
      int v307 = ((int)((unsigned int)((int)((unsigned int)v149 >> 2)) >> 1)) * 2;
      int v205 = v204[v307];
      int v308 = (((int)((unsigned int)((int)((unsigned int)v149 >> 2)) >> 1)) * 2) + 1;
      int v206 = v204[v308];
      int * v207 = v141->cache_vals;
      int v310 = ((4 + ((((int)((unsigned int)((int)((unsigned int)v149 >> 2)) >> 1)) & 3) * 2)) + ((((v185 + ((~(((v187 ^ -1) | (-(v187 ^ -1))) >> 31)) & 2)) - (v188 + ((~(((v189 ^ -1) | (-(v189 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
      v207[v310] = v205;
      int * v209 = v141->cache_vals;
      int v313 = (((4 + ((((int)((unsigned int)((int)((unsigned int)v149 >> 2)) >> 1)) & 3) * 2)) + ((((v185 + ((~(((v187 ^ -1) | (-(v187 ^ -1))) >> 31)) & 2)) - (v188 + ((~(((v189 ^ -1) | (-(v189 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
      v209[v313] = v206;
      int * v211 = v141->cache_tags;
      int v316 = (int)((unsigned int)((int)((unsigned int)v149 >> 2)) >> 1);
      v211[v292] = v316;
      int * v213 = v141->cache_dirty;
      v213[v292] = 0;
      int * v215 = v141->cache_age;
      v215[v292] = 1;
      int * v217 = v141->cache_age;
      int v218 = v217[v292];
      int v219 = v217[v266];
      int v322 = v219 + ((int)((unsigned int)(v219 - v218) >> 31));
      v217[v266] = v322;
      int * v221 = v141->cache_age;
      int v222 = v221[v267];
      int v324 = v222 + ((int)((unsigned int)(v222 - v218) >> 31));
      v221[v267] = v324;
      int * v224 = v141->cache_age;
      v224[v292] = 0;
      v227 = v292;
    }
    int * v228 = v141->cache_vals;
    int v327 = v227 * 2;
    int v229 = v228[v327];
    int v328 = (v227 * 2) + 1;
    int v230 = v228[v328];
    int v329 = (((((int)((unsigned int)((int)((unsigned int)v149 >> 2)) >> 1)) & 1) * 2) + ((((v169 + ((~(((v171 ^ -1) | (-(v171 ^ -1))) >> 31)) & 2)) - (v172 + ((~(((v173 ^ -1) | (-(v173 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
    v228[v329] = v229;
    int * v232 = v141->cache_vals;
    int v332 = ((((((int)((unsigned int)((int)((unsigned int)v149 >> 2)) >> 1)) & 1) * 2) + ((((v169 + ((~(((v171 ^ -1) | (-(v171 ^ -1))) >> 31)) & 2)) - (v172 + ((~(((v173 ^ -1) | (-(v173 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
    v232[v332] = v230;
    int * v234 = v141->cache_tags;
    int v335 = ((((int)((unsigned int)((int)((unsigned int)v149 >> 2)) >> 1)) & 1) * 2) + ((((v169 + ((~(((v171 ^ -1) | (-(v171 ^ -1))) >> 31)) & 2)) - (v172 + ((~(((v173 ^ -1) | (-(v173 ^ -1))) >> 31)) & 2))) >> 31) & 1);
    int v336 = (int)((unsigned int)((int)((unsigned int)v149 >> 2)) >> 1);
    v234[v335] = v336;
    int * v236 = v141->cache_dirty;
    v236[v335] = 0;
    int * v238 = v141->cache_age;
    v238[v335] = 1;
    int * v240 = v141->cache_age;
    int v241 = v240[v335];
    int v242 = v240[v264];
    int v342 = v242 + ((int)((unsigned int)(v242 - v241) >> 31));
    v240[v264] = v342;
    int * v244 = v141->cache_age;
    int v245 = v244[v265];
    int v344 = v245 + ((int)((unsigned int)(v245 - v241) >> 31));
    v244[v265] = v344;
    int * v247 = v141->cache_age;
    v247[v335] = 0;
    v250 = v335;
  }
  int v347 = (v250 * 2) + (((int)((unsigned int)v149 >> 2)) & 1);
  int v251 = v157[v347];
  int * v252 = v141->regs;
  v252[11] = v251;
  struct StateG * v254 = slot_11(v141);
  return v254;
}

struct StateG * slot_4(struct StateG * v61) {
  int * v62 = v61->regs;
  int v63 = v62[10];
  int v64 = v62[15];
  bool v80 = v63 >= v64;
  struct StateG * v75;
  if (v80) {
    int * v65 = v61->pht;
    v65[0] = 1;
    struct StateG * v67 = slot_6(v61);
    v75 = v67;
  } else {
    int * v69 = v61->pht;
    v69[0] = 0;
    int v71 = v61->timer;
    int v88 = v71 + 15;
    v61->timer = v88;
    struct StateG * v73 = slot_7(v61);
    v75 = v73;
  }
  return v75;
}

struct StateG * slot_13(struct StateG * v755) {
  int v756 = v755->timer;
  int v763 = v756 + 1;
  v755->timer = v763;
  int * v758 = v755->regs;
  int v759 = v758[11];
  int v766 = v759 << 2;
  v758[11] = v766;
  struct StateG * v761 = slot_15(v755);
  return v761;
}

struct StateG * slot_15(struct StateG * v980) {
  int v981 = v980->timer;
  int v1091 = v981 + 1;
  v980->timer = v1091;
  int * v983 = v980->regs;
  int v984 = v983[11];
  int * v985 = v980->cache_tags;
  int v1095 = (((int)((unsigned int)((int)((unsigned int)v984 >> 2)) >> 1)) & 1) * 2;
  int v986 = v985[v1095];
  int v1096 = ((((int)((unsigned int)((int)((unsigned int)v984 >> 2)) >> 1)) & 1) * 2) + 1;
  int v987 = v985[v1096];
  int v1097 = 4 + ((((int)((unsigned int)((int)((unsigned int)v984 >> 2)) >> 1)) & 3) * 2);
  int v988 = v985[v1097];
  int v1098 = (4 + ((((int)((unsigned int)((int)((unsigned int)v984 >> 2)) >> 1)) & 3) * 2)) + 1;
  int v989 = v985[v1098];
  int v990 = v980->timer;
  int v1099 = v990 + ((100 ^ (((~(((v988 ^ ((int)((unsigned int)((int)((unsigned int)v984 >> 2)) >> 1))) | (-(v988 ^ ((int)((unsigned int)((int)((unsigned int)v984 >> 2)) >> 1))))) >> 31)) | (~(((v989 ^ ((int)((unsigned int)((int)((unsigned int)v984 >> 2)) >> 1))) | (-(v989 ^ ((int)((unsigned int)((int)((unsigned int)v984 >> 2)) >> 1))))) >> 31))) & 104)) ^ (((~(((v986 ^ ((int)((unsigned int)((int)((unsigned int)v984 >> 2)) >> 1))) | (-(v986 ^ ((int)((unsigned int)((int)((unsigned int)v984 >> 2)) >> 1))))) >> 31)) | (~(((v987 ^ ((int)((unsigned int)((int)((unsigned int)v984 >> 2)) >> 1))) | (-(v987 ^ ((int)((unsigned int)((int)((unsigned int)v984 >> 2)) >> 1))))) >> 31))) & (1 ^ (100 ^ (((~(((v988 ^ ((int)((unsigned int)((int)((unsigned int)v984 >> 2)) >> 1))) | (-(v988 ^ ((int)((unsigned int)((int)((unsigned int)v984 >> 2)) >> 1))))) >> 31)) | (~(((v989 ^ ((int)((unsigned int)((int)((unsigned int)v984 >> 2)) >> 1))) | (-(v989 ^ ((int)((unsigned int)((int)((unsigned int)v984 >> 2)) >> 1))))) >> 31))) & 104)))));
  v980->timer = v1099;
  int * v992 = v980->cache_vals;
  bool v1100 = !(((~(((v986 ^ ((int)((unsigned int)((int)((unsigned int)v984 >> 2)) >> 1))) | (-(v986 ^ ((int)((unsigned int)((int)((unsigned int)v984 >> 2)) >> 1))))) >> 31)) | (~(((v987 ^ ((int)((unsigned int)((int)((unsigned int)v984 >> 2)) >> 1))) | (-(v987 ^ ((int)((unsigned int)((int)((unsigned int)v984 >> 2)) >> 1))))) >> 31))) == 0);
  int v1085;
  if (v1100) {
    int * v993 = v980->cache_age;
    int v1102 = ((((int)((unsigned int)((int)((unsigned int)v984 >> 2)) >> 1)) & 1) * 2) + ((~(((v987 ^ ((int)((unsigned int)((int)((unsigned int)v984 >> 2)) >> 1))) | (-(v987 ^ ((int)((unsigned int)((int)((unsigned int)v984 >> 2)) >> 1))))) >> 31)) & 1);
    int v994 = v993[v1102];
    int v995 = v993[v1095];
    int v1103 = v995 + ((int)((unsigned int)(v995 - v994) >> 31));
    v993[v1095] = v1103;
    int * v997 = v980->cache_age;
    int v998 = v997[v1096];
    int v1105 = v998 + ((int)((unsigned int)(v998 - v994) >> 31));
    v997[v1096] = v1105;
    int * v1000 = v980->cache_age;
    v1000[v1102] = 0;
    v1085 = v1102;
  } else {
    int * v1003 = v980->cache_age;
    int v1109 = (((int)((unsigned int)((int)((unsigned int)v984 >> 2)) >> 1)) & 1) * 2;
    int v1004 = v1003[v1109];
    int * v1005 = v980->cache_tags;
    int v1006 = v1005[v1109];
    int v1007 = v1003[v1096];
    int v1008 = v1005[v1096];
    bool v1111 = !(((~(((v988 ^ ((int)((unsigned int)((int)((unsigned int)v984 >> 2)) >> 1))) | (-(v988 ^ ((int)((unsigned int)((int)((unsigned int)v984 >> 2)) >> 1))))) >> 31)) | (~(((v989 ^ ((int)((unsigned int)((int)((unsigned int)v984 >> 2)) >> 1))) | (-(v989 ^ ((int)((unsigned int)((int)((unsigned int)v984 >> 2)) >> 1))))) >> 31))) == 0);
    int v1062;
    if (v1111) {
      int * v1009 = v980->cache_age;
      int v1113 = (4 + ((((int)((unsigned int)((int)((unsigned int)v984 >> 2)) >> 1)) & 3) * 2)) + ((~(((v989 ^ ((int)((unsigned int)((int)((unsigned int)v984 >> 2)) >> 1))) | (-(v989 ^ ((int)((unsigned int)((int)((unsigned int)v984 >> 2)) >> 1))))) >> 31)) & 1);
      int v1010 = v1009[v1113];
      int v1011 = v1009[v1097];
      int v1114 = v1011 + ((int)((unsigned int)(v1011 - v1010) >> 31));
      v1009[v1097] = v1114;
      int * v1013 = v980->cache_age;
      int v1014 = v1013[v1098];
      int v1116 = v1014 + ((int)((unsigned int)(v1014 - v1010) >> 31));
      v1013[v1098] = v1116;
      int * v1016 = v980->cache_age;
      v1016[v1113] = 0;
      v1062 = v1113;
    } else {
      int * v1019 = v980->cache_age;
      int v1120 = 4 + ((((int)((unsigned int)((int)((unsigned int)v984 >> 2)) >> 1)) & 3) * 2);
      int v1020 = v1019[v1120];
      int * v1021 = v980->cache_tags;
      int v1022 = v1021[v1120];
      int v1023 = v1019[v1098];
      int v1024 = v1021[v1098];
      int * v1025 = v980->cache_dirty;
      int v1123 = (4 + ((((int)((unsigned int)((int)((unsigned int)v984 >> 2)) >> 1)) & 3) * 2)) + ((((v1020 + ((~(((v1022 ^ -1) | (-(v1022 ^ -1))) >> 31)) & 2)) - (v1023 + ((~(((v1024 ^ -1) | (-(v1024 ^ -1))) >> 31)) & 2))) >> 31) & 1);
      int v1026 = v1025[v1123];
      bool v1124 = !(v1026 == 0);
      if (v1124) {
        int * v1027 = v980->cache_tags;
        int v1028 = v1027[v1123];
        int * v1029 = v980->cache_vals;
        int v1127 = ((4 + ((((int)((unsigned int)((int)((unsigned int)v984 >> 2)) >> 1)) & 3) * 2)) + ((((v1020 + ((~(((v1022 ^ -1) | (-(v1022 ^ -1))) >> 31)) & 2)) - (v1023 + ((~(((v1024 ^ -1) | (-(v1024 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
        int v1030 = v1029[v1127];
        int v1128 = (((4 + ((((int)((unsigned int)((int)((unsigned int)v984 >> 2)) >> 1)) & 3) * 2)) + ((((v1020 + ((~(((v1022 ^ -1) | (-(v1022 ^ -1))) >> 31)) & 2)) - (v1023 + ((~(((v1024 ^ -1) | (-(v1024 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
        int v1031 = v1029[v1128];
        int * v1032 = v980->mem;
        int v1130 = v1028 * 2;
        v1032[v1130] = v1030;
        int * v1034 = v980->mem;
        int v1133 = (v1028 * 2) + 1;
        v1034[v1133] = v1031;
        ;
      } else {
        ;
      }
      int * v1039 = v980->mem;
      int v1138 = ((int)((unsigned int)((int)((unsigned int)v984 >> 2)) >> 1)) * 2;
      int v1040 = v1039[v1138];
      int v1139 = (((int)((unsigned int)((int)((unsigned int)v984 >> 2)) >> 1)) * 2) + 1;
      int v1041 = v1039[v1139];
      int * v1042 = v980->cache_vals;
      int v1141 = ((4 + ((((int)((unsigned int)((int)((unsigned int)v984 >> 2)) >> 1)) & 3) * 2)) + ((((v1020 + ((~(((v1022 ^ -1) | (-(v1022 ^ -1))) >> 31)) & 2)) - (v1023 + ((~(((v1024 ^ -1) | (-(v1024 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
      v1042[v1141] = v1040;
      int * v1044 = v980->cache_vals;
      int v1144 = (((4 + ((((int)((unsigned int)((int)((unsigned int)v984 >> 2)) >> 1)) & 3) * 2)) + ((((v1020 + ((~(((v1022 ^ -1) | (-(v1022 ^ -1))) >> 31)) & 2)) - (v1023 + ((~(((v1024 ^ -1) | (-(v1024 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
      v1044[v1144] = v1041;
      int * v1046 = v980->cache_tags;
      int v1147 = (int)((unsigned int)((int)((unsigned int)v984 >> 2)) >> 1);
      v1046[v1123] = v1147;
      int * v1048 = v980->cache_dirty;
      v1048[v1123] = 0;
      int * v1050 = v980->cache_age;
      v1050[v1123] = 1;
      int * v1052 = v980->cache_age;
      int v1053 = v1052[v1123];
      int v1054 = v1052[v1097];
      int v1153 = v1054 + ((int)((unsigned int)(v1054 - v1053) >> 31));
      v1052[v1097] = v1153;
      int * v1056 = v980->cache_age;
      int v1057 = v1056[v1098];
      int v1155 = v1057 + ((int)((unsigned int)(v1057 - v1053) >> 31));
      v1056[v1098] = v1155;
      int * v1059 = v980->cache_age;
      v1059[v1123] = 0;
      v1062 = v1123;
    }
    int * v1063 = v980->cache_vals;
    int v1158 = v1062 * 2;
    int v1064 = v1063[v1158];
    int v1159 = (v1062 * 2) + 1;
    int v1065 = v1063[v1159];
    int v1160 = (((((int)((unsigned int)((int)((unsigned int)v984 >> 2)) >> 1)) & 1) * 2) + ((((v1004 + ((~(((v1006 ^ -1) | (-(v1006 ^ -1))) >> 31)) & 2)) - (v1007 + ((~(((v1008 ^ -1) | (-(v1008 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
    v1063[v1160] = v1064;
    int * v1067 = v980->cache_vals;
    int v1163 = ((((((int)((unsigned int)((int)((unsigned int)v984 >> 2)) >> 1)) & 1) * 2) + ((((v1004 + ((~(((v1006 ^ -1) | (-(v1006 ^ -1))) >> 31)) & 2)) - (v1007 + ((~(((v1008 ^ -1) | (-(v1008 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
    v1067[v1163] = v1065;
    int * v1069 = v980->cache_tags;
    int v1166 = ((((int)((unsigned int)((int)((unsigned int)v984 >> 2)) >> 1)) & 1) * 2) + ((((v1004 + ((~(((v1006 ^ -1) | (-(v1006 ^ -1))) >> 31)) & 2)) - (v1007 + ((~(((v1008 ^ -1) | (-(v1008 ^ -1))) >> 31)) & 2))) >> 31) & 1);
    int v1167 = (int)((unsigned int)((int)((unsigned int)v984 >> 2)) >> 1);
    v1069[v1166] = v1167;
    int * v1071 = v980->cache_dirty;
    v1071[v1166] = 0;
    int * v1073 = v980->cache_age;
    v1073[v1166] = 1;
    int * v1075 = v980->cache_age;
    int v1076 = v1075[v1166];
    int v1077 = v1075[v1095];
    int v1173 = v1077 + ((int)((unsigned int)(v1077 - v1076) >> 31));
    v1075[v1095] = v1173;
    int * v1079 = v980->cache_age;
    int v1080 = v1079[v1096];
    int v1175 = v1080 + ((int)((unsigned int)(v1080 - v1076) >> 31));
    v1079[v1096] = v1175;
    int * v1082 = v980->cache_age;
    v1082[v1166] = 0;
    v1085 = v1166;
  }
  int v1178 = (v1085 * 2) + (((int)((unsigned int)v984 >> 2)) & 1);
  int v1086 = v992[v1178];
  int * v1087 = v980->regs;
  v1087[12] = v1086;
  struct StateG * v1089 = slot_6(v980);
  return v1089;
}

struct StateG * slot_18(struct StateG * v1247) {
  int v1248 = v1247->timer;
  int v1355 = v1248 + 1;
  v1247->timer = v1355;
  int * v1250 = v1247->cache_tags;
  int v1251 = v1250[0];
  int v1252 = v1250[1];
  int v1253 = v1250[4];
  int v1254 = v1250[5];
  int v1255 = v1247->timer;
  int v1361 = v1255 + ((100 ^ (((~((v1253 | (-v1253)) >> 31)) | (~((v1254 | (-v1254)) >> 31))) & 104)) ^ (((~((v1251 | (-v1251)) >> 31)) | (~((v1252 | (-v1252)) >> 31))) & (1 ^ (100 ^ (((~((v1253 | (-v1253)) >> 31)) | (~((v1254 | (-v1254)) >> 31))) & 104)))));
  v1247->timer = v1361;
  int * v1257 = v1247->cache_vals;
  bool v1362 = !(((~((v1251 | (-v1251)) >> 31)) | (~((v1252 | (-v1252)) >> 31))) == 0);
  int v1350;
  if (v1362) {
    int * v1258 = v1247->cache_age;
    int v1364 = (~((v1252 | (-v1252)) >> 31)) & 1;
    int v1259 = v1258[v1364];
    int v1260 = v1258[0];
    int v1365 = v1260 + ((int)((unsigned int)(v1260 - v1259) >> 31));
    v1258[0] = v1365;
    int * v1262 = v1247->cache_age;
    int v1263 = v1262[1];
    int v1367 = v1263 + ((int)((unsigned int)(v1263 - v1259) >> 31));
    v1262[1] = v1367;
    int * v1265 = v1247->cache_age;
    v1265[v1364] = 0;
    v1350 = v1364;
  } else {
    int * v1268 = v1247->cache_age;
    int v1269 = v1268[0];
    int * v1270 = v1247->cache_tags;
    int v1271 = v1270[0];
    int v1272 = v1268[1];
    int v1273 = v1270[1];
    bool v1371 = !(((~((v1253 | (-v1253)) >> 31)) | (~((v1254 | (-v1254)) >> 31))) == 0);
    int v1327;
    if (v1371) {
      int * v1274 = v1247->cache_age;
      int v1373 = 4 + ((~((v1254 | (-v1254)) >> 31)) & 1);
      int v1275 = v1274[v1373];
      int v1276 = v1274[4];
      int v1374 = v1276 + ((int)((unsigned int)(v1276 - v1275) >> 31));
      v1274[4] = v1374;
      int * v1278 = v1247->cache_age;
      int v1279 = v1278[5];
      int v1376 = v1279 + ((int)((unsigned int)(v1279 - v1275) >> 31));
      v1278[5] = v1376;
      int * v1281 = v1247->cache_age;
      v1281[v1373] = 0;
      v1327 = v1373;
    } else {
      int * v1284 = v1247->cache_age;
      int v1285 = v1284[4];
      int * v1286 = v1247->cache_tags;
      int v1287 = v1286[4];
      int v1288 = v1284[5];
      int v1289 = v1286[5];
      int * v1290 = v1247->cache_dirty;
      int v1381 = 4 + ((((v1285 + ((~(((v1287 ^ -1) | (-(v1287 ^ -1))) >> 31)) & 2)) - (v1288 + ((~(((v1289 ^ -1) | (-(v1289 ^ -1))) >> 31)) & 2))) >> 31) & 1);
      int v1291 = v1290[v1381];
      bool v1382 = !(v1291 == 0);
      if (v1382) {
        int * v1292 = v1247->cache_tags;
        int v1293 = v1292[v1381];
        int * v1294 = v1247->cache_vals;
        int v1385 = (4 + ((((v1285 + ((~(((v1287 ^ -1) | (-(v1287 ^ -1))) >> 31)) & 2)) - (v1288 + ((~(((v1289 ^ -1) | (-(v1289 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
        int v1295 = v1294[v1385];
        int v1386 = ((4 + ((((v1285 + ((~(((v1287 ^ -1) | (-(v1287 ^ -1))) >> 31)) & 2)) - (v1288 + ((~(((v1289 ^ -1) | (-(v1289 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
        int v1296 = v1294[v1386];
        int * v1297 = v1247->mem;
        int v1388 = v1293 * 2;
        v1297[v1388] = v1295;
        int * v1299 = v1247->mem;
        int v1391 = (v1293 * 2) + 1;
        v1299[v1391] = v1296;
        ;
      } else {
        ;
      }
      int * v1304 = v1247->mem;
      int v1305 = v1304[0];
      int v1306 = v1304[1];
      int * v1307 = v1247->cache_vals;
      int v1397 = (4 + ((((v1285 + ((~(((v1287 ^ -1) | (-(v1287 ^ -1))) >> 31)) & 2)) - (v1288 + ((~(((v1289 ^ -1) | (-(v1289 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
      v1307[v1397] = v1305;
      int * v1309 = v1247->cache_vals;
      int v1400 = ((4 + ((((v1285 + ((~(((v1287 ^ -1) | (-(v1287 ^ -1))) >> 31)) & 2)) - (v1288 + ((~(((v1289 ^ -1) | (-(v1289 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
      v1309[v1400] = v1306;
      int * v1311 = v1247->cache_tags;
      v1311[v1381] = 0;
      int * v1313 = v1247->cache_dirty;
      v1313[v1381] = 0;
      int * v1315 = v1247->cache_age;
      v1315[v1381] = 1;
      int * v1317 = v1247->cache_age;
      int v1318 = v1317[v1381];
      int v1319 = v1317[4];
      int v1406 = v1319 + ((int)((unsigned int)(v1319 - v1318) >> 31));
      v1317[4] = v1406;
      int * v1321 = v1247->cache_age;
      int v1322 = v1321[5];
      int v1408 = v1322 + ((int)((unsigned int)(v1322 - v1318) >> 31));
      v1321[5] = v1408;
      int * v1324 = v1247->cache_age;
      v1324[v1381] = 0;
      v1327 = v1381;
    }
    int * v1328 = v1247->cache_vals;
    int v1411 = v1327 * 2;
    int v1329 = v1328[v1411];
    int v1412 = (v1327 * 2) + 1;
    int v1330 = v1328[v1412];
    int v1413 = ((((v1269 + ((~(((v1271 ^ -1) | (-(v1271 ^ -1))) >> 31)) & 2)) - (v1272 + ((~(((v1273 ^ -1) | (-(v1273 ^ -1))) >> 31)) & 2))) >> 31) & 1) * 2;
    v1328[v1413] = v1329;
    int * v1332 = v1247->cache_vals;
    int v1416 = (((((v1269 + ((~(((v1271 ^ -1) | (-(v1271 ^ -1))) >> 31)) & 2)) - (v1272 + ((~(((v1273 ^ -1) | (-(v1273 ^ -1))) >> 31)) & 2))) >> 31) & 1) * 2) + 1;
    v1332[v1416] = v1330;
    int * v1334 = v1247->cache_tags;
    int v1419 = (((v1269 + ((~(((v1271 ^ -1) | (-(v1271 ^ -1))) >> 31)) & 2)) - (v1272 + ((~(((v1273 ^ -1) | (-(v1273 ^ -1))) >> 31)) & 2))) >> 31) & 1;
    v1334[v1419] = 0;
    int * v1336 = v1247->cache_dirty;
    v1336[v1419] = 0;
    int * v1338 = v1247->cache_age;
    v1338[v1419] = 1;
    int * v1340 = v1247->cache_age;
    int v1341 = v1340[v1419];
    int v1342 = v1340[0];
    int v1423 = v1342 + ((int)((unsigned int)(v1342 - v1341) >> 31));
    v1340[0] = v1423;
    int * v1344 = v1247->cache_age;
    int v1345 = v1344[1];
    int v1425 = v1345 + ((int)((unsigned int)(v1345 - v1341) >> 31));
    v1344[1] = v1425;
    int * v1347 = v1247->cache_age;
    v1347[v1419] = 0;
    v1350 = v1419;
  }
  int v1428 = v1350 * 2;
  int v1351 = v1257[v1428];
  int * v1352 = v1247->regs;
  v1352[14] = v1351;
  return v1247;
}

struct StateG * slot_11(struct StateG * v741) {
  int v742 = v741->timer;
  int v749 = v742 + 1;
  v741->timer = v749;
  int * v744 = v741->regs;
  int v745 = v744[11];
  int v752 = v745 << 2;
  v744[11] = v752;
  struct StateG * v747 = slot_14(v741);
  return v747;
}

struct StateG * slot_0(struct StateG * v2) {
  int v3 = v2->timer;
  int v9 = v3 + 1;
  v2->timer = v9;
  int * v5 = v2->regs;
  v5[13] = 0;
  struct StateG * v7 = slot_1(v2);
  return v7;
}



/*****************************************
End of C Generated Code
*******************************************/

void init(struct StateG *s) {
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
  for (int i=0; i<PHT_ENTRIES; i++) {
    s->pht[i] = 0;
  }
}

int main(int argc, char* argv[]) {
  struct StateG s1, s2;
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
  struct StateG *s1_ = snippet(&s1);
  struct StateG *s2_ = snippet(&s2);
  //@ assert untainted_timer: !\tainted(s1_->timer==s2_->timer);
  koika_assert(s1_->timer==s2_->timer, "timing leak");
  return 0;
}