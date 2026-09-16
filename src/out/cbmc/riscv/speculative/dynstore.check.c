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
  int cache_tags[12];
  int cache_dirty[12];
  int cache_age[12];
  int cache_vals[24];
  int timer;
};

struct StateT * snippet(struct StateT * v0);
struct StateT * slot_1(struct StateT * v15);
struct StateT * slot_8(struct StateT * v977);
struct StateT * slot_9(struct StateT * v993);
struct StateT * slot_2(struct StateT * v28);
struct StateT * slot_7(struct StateT * v727);
struct StateT * slot_3(struct StateT * v41);
struct StateT * slot_0(struct StateT * v2);
struct StateT * snippet(struct StateT * v0) {
  struct StateT * v1 = slot_0(v0);
  return v1;
}

struct StateT * slot_1(struct StateT * v15) {
  int v16 = v15->timer;
  int v22 = v16 + 1;
  v15->timer = v22;
  int * v18 = v15->regs;
  v18[7] = 16;
  struct StateT * v20 = slot_2(v15);
  return v20;
}

struct StateT * slot_8(struct StateT * v977) {
  int v978 = v977->timer;
  int v986 = v978 + 1;
  v977->timer = v986;
  int * v980 = v977->regs;
  int v981 = v980[6];
  int * v982 = v977->regs;
  int v990 = v981 + 4;
  v982[6] = v990;
  struct StateT * v984 = slot_9(v977);
  return v984;
}

struct StateT * slot_9(struct StateT * v993) {
  int v994 = v993->timer;
  int v998 = v994 + 1;
  v993->timer = v998;
  struct StateT * v996 = slot_3(v993);
  return v996;
}

struct StateT * slot_2(struct StateT * v28) {
  int v29 = v28->timer;
  int v35 = v29 + 1;
  v28->timer = v35;
  int * v31 = v28->regs;
  v31[9] = 80;
  struct StateT * v33 = slot_3(v28);
  return v33;
}

struct StateT * slot_7(struct StateT * v727) {
  int v728 = v727->timer;
  int v861 = v728 + 1;
  v727->timer = v861;
  int * v730 = v727->regs;
  int v731 = v730[6];
  int * v732 = v727->cache_tags;
  int v865 = (((int)((unsigned int)((int)((unsigned int)v731 >> 2)) >> 1)) & 1) * 2;
  int v733 = v732[v865];
  int * v734 = v727->cache_tags;
  int v867 = ((((int)((unsigned int)((int)((unsigned int)v731 >> 2)) >> 1)) & 1) * 2) + 1;
  int v735 = v734[v867];
  int * v736 = v727->cache_tags;
  int v869 = 4 + ((((int)((unsigned int)((int)((unsigned int)v731 >> 2)) >> 1)) & 3) * 2);
  int v737 = v736[v869];
  int * v738 = v727->cache_tags;
  int v871 = (4 + ((((int)((unsigned int)((int)((unsigned int)v731 >> 2)) >> 1)) & 3) * 2)) + 1;
  int v739 = v738[v871];
  int v740 = v727->timer;
  int v872 = v740 + ((100 ^ (((~(((v737 ^ ((int)((unsigned int)((int)((unsigned int)v731 >> 2)) >> 1))) | (-(v737 ^ ((int)((unsigned int)((int)((unsigned int)v731 >> 2)) >> 1))))) >> 31)) | (~(((v739 ^ ((int)((unsigned int)((int)((unsigned int)v731 >> 2)) >> 1))) | (-(v739 ^ ((int)((unsigned int)((int)((unsigned int)v731 >> 2)) >> 1))))) >> 31))) & 104)) ^ (((~(((v733 ^ ((int)((unsigned int)((int)((unsigned int)v731 >> 2)) >> 1))) | (-(v733 ^ ((int)((unsigned int)((int)((unsigned int)v731 >> 2)) >> 1))))) >> 31)) | (~(((v735 ^ ((int)((unsigned int)((int)((unsigned int)v731 >> 2)) >> 1))) | (-(v735 ^ ((int)((unsigned int)((int)((unsigned int)v731 >> 2)) >> 1))))) >> 31))) & (1 ^ (100 ^ (((~(((v737 ^ ((int)((unsigned int)((int)((unsigned int)v731 >> 2)) >> 1))) | (-(v737 ^ ((int)((unsigned int)((int)((unsigned int)v731 >> 2)) >> 1))))) >> 31)) | (~(((v739 ^ ((int)((unsigned int)((int)((unsigned int)v731 >> 2)) >> 1))) | (-(v739 ^ ((int)((unsigned int)((int)((unsigned int)v731 >> 2)) >> 1))))) >> 31))) & 104)))));
  v727->timer = v872;
  int * v742 = v727->cache_vals;
  bool v873 = !(((~(((v733 ^ ((int)((unsigned int)((int)((unsigned int)v731 >> 2)) >> 1))) | (-(v733 ^ ((int)((unsigned int)((int)((unsigned int)v731 >> 2)) >> 1))))) >> 31)) | (~(((v735 ^ ((int)((unsigned int)((int)((unsigned int)v731 >> 2)) >> 1))) | (-(v735 ^ ((int)((unsigned int)((int)((unsigned int)v731 >> 2)) >> 1))))) >> 31))) == 0);
  int v855;
  if (v873) {
    int * v743 = v727->cache_age;
    int v875 = ((((int)((unsigned int)((int)((unsigned int)v731 >> 2)) >> 1)) & 1) * 2) + ((~(((v735 ^ ((int)((unsigned int)((int)((unsigned int)v731 >> 2)) >> 1))) | (-(v735 ^ ((int)((unsigned int)((int)((unsigned int)v731 >> 2)) >> 1))))) >> 31)) & 1);
    int v744 = v743[v875];
    int * v745 = v727->cache_age;
    int v746 = v745[v865];
    int * v747 = v727->cache_age;
    int v878 = v746 + ((int)((unsigned int)(v746 - v744) >> 31));
    v747[v865] = v878;
    int * v749 = v727->cache_age;
    int v750 = v749[v867];
    int * v751 = v727->cache_age;
    int v881 = v750 + ((int)((unsigned int)(v750 - v744) >> 31));
    v751[v867] = v881;
    int * v753 = v727->cache_age;
    v753[v875] = 0;
    v855 = v875;
  } else {
    int * v756 = v727->cache_age;
    int v885 = (((int)((unsigned int)((int)((unsigned int)v731 >> 2)) >> 1)) & 1) * 2;
    int v757 = v756[v885];
    int * v758 = v727->cache_tags;
    int v759 = v758[v885];
    int * v760 = v727->cache_age;
    int v761 = v760[v867];
    int * v762 = v727->cache_tags;
    int v763 = v762[v867];
    bool v889 = !(((~(((v737 ^ ((int)((unsigned int)((int)((unsigned int)v731 >> 2)) >> 1))) | (-(v737 ^ ((int)((unsigned int)((int)((unsigned int)v731 >> 2)) >> 1))))) >> 31)) | (~(((v739 ^ ((int)((unsigned int)((int)((unsigned int)v731 >> 2)) >> 1))) | (-(v739 ^ ((int)((unsigned int)((int)((unsigned int)v731 >> 2)) >> 1))))) >> 31))) == 0);
    int v827;
    if (v889) {
      int * v764 = v727->cache_age;
      int v891 = (4 + ((((int)((unsigned int)((int)((unsigned int)v731 >> 2)) >> 1)) & 3) * 2)) + ((~(((v739 ^ ((int)((unsigned int)((int)((unsigned int)v731 >> 2)) >> 1))) | (-(v739 ^ ((int)((unsigned int)((int)((unsigned int)v731 >> 2)) >> 1))))) >> 31)) & 1);
      int v765 = v764[v891];
      int * v766 = v727->cache_age;
      int v767 = v766[v869];
      int * v768 = v727->cache_age;
      int v894 = v767 + ((int)((unsigned int)(v767 - v765) >> 31));
      v768[v869] = v894;
      int * v770 = v727->cache_age;
      int v771 = v770[v871];
      int * v772 = v727->cache_age;
      int v897 = v771 + ((int)((unsigned int)(v771 - v765) >> 31));
      v772[v871] = v897;
      int * v774 = v727->cache_age;
      v774[v891] = 0;
      v827 = v891;
    } else {
      int * v777 = v727->cache_age;
      int v901 = 4 + ((((int)((unsigned int)((int)((unsigned int)v731 >> 2)) >> 1)) & 3) * 2);
      int v778 = v777[v901];
      int * v779 = v727->cache_tags;
      int v780 = v779[v901];
      int * v781 = v727->cache_age;
      int v782 = v781[v871];
      int * v783 = v727->cache_tags;
      int v784 = v783[v871];
      int * v785 = v727->cache_dirty;
      int v906 = (4 + ((((int)((unsigned int)((int)((unsigned int)v731 >> 2)) >> 1)) & 3) * 2)) + ((((v778 + ((~(((v780 ^ -1) | (-(v780 ^ -1))) >> 31)) & 2)) - (v782 + ((~(((v784 ^ -1) | (-(v784 ^ -1))) >> 31)) & 2))) >> 31) & 1);
      int v786 = v785[v906];
      bool v907 = !(v786 == 0);
      if (v907) {
        int * v787 = v727->cache_tags;
        int v788 = v787[v906];
        int * v789 = v727->cache_vals;
        int v910 = ((4 + ((((int)((unsigned int)((int)((unsigned int)v731 >> 2)) >> 1)) & 3) * 2)) + ((((v778 + ((~(((v780 ^ -1) | (-(v780 ^ -1))) >> 31)) & 2)) - (v782 + ((~(((v784 ^ -1) | (-(v784 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
        int v790 = v789[v910];
        int * v791 = v727->cache_vals;
        int v912 = (((4 + ((((int)((unsigned int)((int)((unsigned int)v731 >> 2)) >> 1)) & 3) * 2)) + ((((v778 + ((~(((v780 ^ -1) | (-(v780 ^ -1))) >> 31)) & 2)) - (v782 + ((~(((v784 ^ -1) | (-(v784 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
        int v792 = v791[v912];
        int * v793 = v727->mem;
        int v914 = v788 * 2;
        v793[v914] = v790;
        int * v795 = v727->mem;
        int v917 = (v788 * 2) + 1;
        v795[v917] = v792;
        ;
      } else {
        ;
      }
      int * v800 = v727->mem;
      int v922 = ((int)((unsigned int)((int)((unsigned int)v731 >> 2)) >> 1)) * 2;
      int v801 = v800[v922];
      int * v802 = v727->mem;
      int v924 = (((int)((unsigned int)((int)((unsigned int)v731 >> 2)) >> 1)) * 2) + 1;
      int v803 = v802[v924];
      int * v804 = v727->cache_vals;
      int v926 = ((4 + ((((int)((unsigned int)((int)((unsigned int)v731 >> 2)) >> 1)) & 3) * 2)) + ((((v778 + ((~(((v780 ^ -1) | (-(v780 ^ -1))) >> 31)) & 2)) - (v782 + ((~(((v784 ^ -1) | (-(v784 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
      v804[v926] = v801;
      int * v806 = v727->cache_vals;
      int v929 = (((4 + ((((int)((unsigned int)((int)((unsigned int)v731 >> 2)) >> 1)) & 3) * 2)) + ((((v778 + ((~(((v780 ^ -1) | (-(v780 ^ -1))) >> 31)) & 2)) - (v782 + ((~(((v784 ^ -1) | (-(v784 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
      v806[v929] = v803;
      int * v808 = v727->cache_tags;
      int v932 = (int)((unsigned int)((int)((unsigned int)v731 >> 2)) >> 1);
      v808[v906] = v932;
      int * v810 = v727->cache_dirty;
      v810[v906] = 0;
      int * v812 = v727->cache_age;
      v812[v906] = 1;
      int * v814 = v727->cache_age;
      int v815 = v814[v906];
      int * v816 = v727->cache_age;
      int v817 = v816[v869];
      int * v818 = v727->cache_age;
      int v940 = v817 + ((int)((unsigned int)(v817 - v815) >> 31));
      v818[v869] = v940;
      int * v820 = v727->cache_age;
      int v821 = v820[v871];
      int * v822 = v727->cache_age;
      int v943 = v821 + ((int)((unsigned int)(v821 - v815) >> 31));
      v822[v871] = v943;
      int * v824 = v727->cache_age;
      v824[v906] = 0;
      v827 = v906;
    }
    int * v828 = v727->cache_vals;
    int v946 = v827 * 2;
    int v829 = v828[v946];
    int * v830 = v727->cache_vals;
    int v948 = (v827 * 2) + 1;
    int v831 = v830[v948];
    int * v832 = v727->cache_vals;
    int v950 = (((((int)((unsigned int)((int)((unsigned int)v731 >> 2)) >> 1)) & 1) * 2) + ((((v757 + ((~(((v759 ^ -1) | (-(v759 ^ -1))) >> 31)) & 2)) - (v761 + ((~(((v763 ^ -1) | (-(v763 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
    v832[v950] = v829;
    int * v834 = v727->cache_vals;
    int v953 = ((((((int)((unsigned int)((int)((unsigned int)v731 >> 2)) >> 1)) & 1) * 2) + ((((v757 + ((~(((v759 ^ -1) | (-(v759 ^ -1))) >> 31)) & 2)) - (v761 + ((~(((v763 ^ -1) | (-(v763 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
    v834[v953] = v831;
    int * v836 = v727->cache_tags;
    int v956 = ((((int)((unsigned int)((int)((unsigned int)v731 >> 2)) >> 1)) & 1) * 2) + ((((v757 + ((~(((v759 ^ -1) | (-(v759 ^ -1))) >> 31)) & 2)) - (v761 + ((~(((v763 ^ -1) | (-(v763 ^ -1))) >> 31)) & 2))) >> 31) & 1);
    int v957 = (int)((unsigned int)((int)((unsigned int)v731 >> 2)) >> 1);
    v836[v956] = v957;
    int * v838 = v727->cache_dirty;
    v838[v956] = 0;
    int * v840 = v727->cache_age;
    v840[v956] = 1;
    int * v842 = v727->cache_age;
    int v843 = v842[v956];
    int * v844 = v727->cache_age;
    int v845 = v844[v865];
    int * v846 = v727->cache_age;
    int v965 = v845 + ((int)((unsigned int)(v845 - v843) >> 31));
    v846[v865] = v965;
    int * v848 = v727->cache_age;
    int v849 = v848[v867];
    int * v850 = v727->cache_age;
    int v968 = v849 + ((int)((unsigned int)(v849 - v843) >> 31));
    v850[v867] = v968;
    int * v852 = v727->cache_age;
    v852[v956] = 0;
    v855 = v956;
  }
  int v971 = (v855 * 2) + (((int)((unsigned int)v731 >> 2)) & 1);
  int v856 = v742[v971];
  int * v857 = v727->regs;
  v857[11] = v856;
  struct StateT * v859 = slot_8(v727);
  return v859;
}

struct StateT * slot_3(struct StateT * v41) {
  int * v42 = v41->saved_regs;
  int * v43 = v41->regs;
  int v44 = v43[8];
  v42[8] = v44;
  int v46 = v41->timer;
  int v415 = v46 + 1;
  v41->timer = v415;
  int * v48 = v41->regs;
  int v49 = v48[9];
  int * v50 = v41->regs;
  int v51 = v50[6];
  int * v52 = v41->regs;
  int v421 = v49 + v51;
  v52[8] = v421;
  int * v54 = v41->saved_regs;
  int * v55 = v41->regs;
  int v56 = v55[5];
  v54[5] = v56;
  int v58 = v41->timer;
  int v426 = v58 + 1;
  v41->timer = v426;
  int * v60 = v41->regs;
  int v61 = v60[8];
  int * v62 = v41->cache_tags;
  int v429 = (((int)((unsigned int)((int)((unsigned int)v61 >> 2)) >> 1)) & 1) * 2;
  int v63 = v62[v429];
  int * v64 = v41->cache_tags;
  int v431 = ((((int)((unsigned int)((int)((unsigned int)v61 >> 2)) >> 1)) & 1) * 2) + 1;
  int v65 = v64[v431];
  int * v66 = v41->cache_tags;
  int v433 = 4 + ((((int)((unsigned int)((int)((unsigned int)v61 >> 2)) >> 1)) & 3) * 2);
  int v67 = v66[v433];
  int * v68 = v41->cache_tags;
  int v435 = (4 + ((((int)((unsigned int)((int)((unsigned int)v61 >> 2)) >> 1)) & 3) * 2)) + 1;
  int v69 = v68[v435];
  int v70 = v41->timer;
  int v436 = v70 + ((100 ^ (((~(((v67 ^ ((int)((unsigned int)((int)((unsigned int)v61 >> 2)) >> 1))) | (-(v67 ^ ((int)((unsigned int)((int)((unsigned int)v61 >> 2)) >> 1))))) >> 31)) | (~(((v69 ^ ((int)((unsigned int)((int)((unsigned int)v61 >> 2)) >> 1))) | (-(v69 ^ ((int)((unsigned int)((int)((unsigned int)v61 >> 2)) >> 1))))) >> 31))) & 104)) ^ (((~(((v63 ^ ((int)((unsigned int)((int)((unsigned int)v61 >> 2)) >> 1))) | (-(v63 ^ ((int)((unsigned int)((int)((unsigned int)v61 >> 2)) >> 1))))) >> 31)) | (~(((v65 ^ ((int)((unsigned int)((int)((unsigned int)v61 >> 2)) >> 1))) | (-(v65 ^ ((int)((unsigned int)((int)((unsigned int)v61 >> 2)) >> 1))))) >> 31))) & (1 ^ (100 ^ (((~(((v67 ^ ((int)((unsigned int)((int)((unsigned int)v61 >> 2)) >> 1))) | (-(v67 ^ ((int)((unsigned int)((int)((unsigned int)v61 >> 2)) >> 1))))) >> 31)) | (~(((v69 ^ ((int)((unsigned int)((int)((unsigned int)v61 >> 2)) >> 1))) | (-(v69 ^ ((int)((unsigned int)((int)((unsigned int)v61 >> 2)) >> 1))))) >> 31))) & 104)))));
  v41->timer = v436;
  int * v72 = v41->cache_vals;
  bool v437 = !(((~(((v63 ^ ((int)((unsigned int)((int)((unsigned int)v61 >> 2)) >> 1))) | (-(v63 ^ ((int)((unsigned int)((int)((unsigned int)v61 >> 2)) >> 1))))) >> 31)) | (~(((v65 ^ ((int)((unsigned int)((int)((unsigned int)v61 >> 2)) >> 1))) | (-(v65 ^ ((int)((unsigned int)((int)((unsigned int)v61 >> 2)) >> 1))))) >> 31))) == 0);
  int v185;
  if (v437) {
    int * v73 = v41->cache_age;
    int v439 = ((((int)((unsigned int)((int)((unsigned int)v61 >> 2)) >> 1)) & 1) * 2) + ((~(((v65 ^ ((int)((unsigned int)((int)((unsigned int)v61 >> 2)) >> 1))) | (-(v65 ^ ((int)((unsigned int)((int)((unsigned int)v61 >> 2)) >> 1))))) >> 31)) & 1);
    int v74 = v73[v439];
    int * v75 = v41->cache_age;
    int v76 = v75[v429];
    int * v77 = v41->cache_age;
    int v442 = v76 + ((int)((unsigned int)(v76 - v74) >> 31));
    v77[v429] = v442;
    int * v79 = v41->cache_age;
    int v80 = v79[v431];
    int * v81 = v41->cache_age;
    int v445 = v80 + ((int)((unsigned int)(v80 - v74) >> 31));
    v81[v431] = v445;
    int * v83 = v41->cache_age;
    v83[v439] = 0;
    v185 = v439;
  } else {
    int * v86 = v41->cache_age;
    int v449 = (((int)((unsigned int)((int)((unsigned int)v61 >> 2)) >> 1)) & 1) * 2;
    int v87 = v86[v449];
    int * v88 = v41->cache_tags;
    int v89 = v88[v449];
    int * v90 = v41->cache_age;
    int v91 = v90[v431];
    int * v92 = v41->cache_tags;
    int v93 = v92[v431];
    bool v453 = !(((~(((v67 ^ ((int)((unsigned int)((int)((unsigned int)v61 >> 2)) >> 1))) | (-(v67 ^ ((int)((unsigned int)((int)((unsigned int)v61 >> 2)) >> 1))))) >> 31)) | (~(((v69 ^ ((int)((unsigned int)((int)((unsigned int)v61 >> 2)) >> 1))) | (-(v69 ^ ((int)((unsigned int)((int)((unsigned int)v61 >> 2)) >> 1))))) >> 31))) == 0);
    int v157;
    if (v453) {
      int * v94 = v41->cache_age;
      int v455 = (4 + ((((int)((unsigned int)((int)((unsigned int)v61 >> 2)) >> 1)) & 3) * 2)) + ((~(((v69 ^ ((int)((unsigned int)((int)((unsigned int)v61 >> 2)) >> 1))) | (-(v69 ^ ((int)((unsigned int)((int)((unsigned int)v61 >> 2)) >> 1))))) >> 31)) & 1);
      int v95 = v94[v455];
      int * v96 = v41->cache_age;
      int v97 = v96[v433];
      int * v98 = v41->cache_age;
      int v458 = v97 + ((int)((unsigned int)(v97 - v95) >> 31));
      v98[v433] = v458;
      int * v100 = v41->cache_age;
      int v101 = v100[v435];
      int * v102 = v41->cache_age;
      int v461 = v101 + ((int)((unsigned int)(v101 - v95) >> 31));
      v102[v435] = v461;
      int * v104 = v41->cache_age;
      v104[v455] = 0;
      v157 = v455;
    } else {
      int * v107 = v41->cache_age;
      int v465 = 4 + ((((int)((unsigned int)((int)((unsigned int)v61 >> 2)) >> 1)) & 3) * 2);
      int v108 = v107[v465];
      int * v109 = v41->cache_tags;
      int v110 = v109[v465];
      int * v111 = v41->cache_age;
      int v112 = v111[v435];
      int * v113 = v41->cache_tags;
      int v114 = v113[v435];
      int * v115 = v41->cache_dirty;
      int v470 = (4 + ((((int)((unsigned int)((int)((unsigned int)v61 >> 2)) >> 1)) & 3) * 2)) + ((((v108 + ((~(((v110 ^ -1) | (-(v110 ^ -1))) >> 31)) & 2)) - (v112 + ((~(((v114 ^ -1) | (-(v114 ^ -1))) >> 31)) & 2))) >> 31) & 1);
      int v116 = v115[v470];
      bool v471 = !(v116 == 0);
      if (v471) {
        int * v117 = v41->cache_tags;
        int v118 = v117[v470];
        int * v119 = v41->cache_vals;
        int v474 = ((4 + ((((int)((unsigned int)((int)((unsigned int)v61 >> 2)) >> 1)) & 3) * 2)) + ((((v108 + ((~(((v110 ^ -1) | (-(v110 ^ -1))) >> 31)) & 2)) - (v112 + ((~(((v114 ^ -1) | (-(v114 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
        int v120 = v119[v474];
        int * v121 = v41->cache_vals;
        int v476 = (((4 + ((((int)((unsigned int)((int)((unsigned int)v61 >> 2)) >> 1)) & 3) * 2)) + ((((v108 + ((~(((v110 ^ -1) | (-(v110 ^ -1))) >> 31)) & 2)) - (v112 + ((~(((v114 ^ -1) | (-(v114 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
        int v122 = v121[v476];
        int * v123 = v41->mem;
        int v478 = v118 * 2;
        v123[v478] = v120;
        int * v125 = v41->mem;
        int v481 = (v118 * 2) + 1;
        v125[v481] = v122;
        ;
      } else {
        ;
      }
      int * v130 = v41->mem;
      int v486 = ((int)((unsigned int)((int)((unsigned int)v61 >> 2)) >> 1)) * 2;
      int v131 = v130[v486];
      int * v132 = v41->mem;
      int v488 = (((int)((unsigned int)((int)((unsigned int)v61 >> 2)) >> 1)) * 2) + 1;
      int v133 = v132[v488];
      int * v134 = v41->cache_vals;
      int v490 = ((4 + ((((int)((unsigned int)((int)((unsigned int)v61 >> 2)) >> 1)) & 3) * 2)) + ((((v108 + ((~(((v110 ^ -1) | (-(v110 ^ -1))) >> 31)) & 2)) - (v112 + ((~(((v114 ^ -1) | (-(v114 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
      v134[v490] = v131;
      int * v136 = v41->cache_vals;
      int v493 = (((4 + ((((int)((unsigned int)((int)((unsigned int)v61 >> 2)) >> 1)) & 3) * 2)) + ((((v108 + ((~(((v110 ^ -1) | (-(v110 ^ -1))) >> 31)) & 2)) - (v112 + ((~(((v114 ^ -1) | (-(v114 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
      v136[v493] = v133;
      int * v138 = v41->cache_tags;
      int v496 = (int)((unsigned int)((int)((unsigned int)v61 >> 2)) >> 1);
      v138[v470] = v496;
      int * v140 = v41->cache_dirty;
      v140[v470] = 0;
      int * v142 = v41->cache_age;
      v142[v470] = 1;
      int * v144 = v41->cache_age;
      int v145 = v144[v470];
      int * v146 = v41->cache_age;
      int v147 = v146[v433];
      int * v148 = v41->cache_age;
      int v504 = v147 + ((int)((unsigned int)(v147 - v145) >> 31));
      v148[v433] = v504;
      int * v150 = v41->cache_age;
      int v151 = v150[v435];
      int * v152 = v41->cache_age;
      int v507 = v151 + ((int)((unsigned int)(v151 - v145) >> 31));
      v152[v435] = v507;
      int * v154 = v41->cache_age;
      v154[v470] = 0;
      v157 = v470;
    }
    int * v158 = v41->cache_vals;
    int v510 = v157 * 2;
    int v159 = v158[v510];
    int * v160 = v41->cache_vals;
    int v512 = (v157 * 2) + 1;
    int v161 = v160[v512];
    int * v162 = v41->cache_vals;
    int v514 = (((((int)((unsigned int)((int)((unsigned int)v61 >> 2)) >> 1)) & 1) * 2) + ((((v87 + ((~(((v89 ^ -1) | (-(v89 ^ -1))) >> 31)) & 2)) - (v91 + ((~(((v93 ^ -1) | (-(v93 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
    v162[v514] = v159;
    int * v164 = v41->cache_vals;
    int v517 = ((((((int)((unsigned int)((int)((unsigned int)v61 >> 2)) >> 1)) & 1) * 2) + ((((v87 + ((~(((v89 ^ -1) | (-(v89 ^ -1))) >> 31)) & 2)) - (v91 + ((~(((v93 ^ -1) | (-(v93 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
    v164[v517] = v161;
    int * v166 = v41->cache_tags;
    int v520 = ((((int)((unsigned int)((int)((unsigned int)v61 >> 2)) >> 1)) & 1) * 2) + ((((v87 + ((~(((v89 ^ -1) | (-(v89 ^ -1))) >> 31)) & 2)) - (v91 + ((~(((v93 ^ -1) | (-(v93 ^ -1))) >> 31)) & 2))) >> 31) & 1);
    int v521 = (int)((unsigned int)((int)((unsigned int)v61 >> 2)) >> 1);
    v166[v520] = v521;
    int * v168 = v41->cache_dirty;
    v168[v520] = 0;
    int * v170 = v41->cache_age;
    v170[v520] = 1;
    int * v172 = v41->cache_age;
    int v173 = v172[v520];
    int * v174 = v41->cache_age;
    int v175 = v174[v429];
    int * v176 = v41->cache_age;
    int v529 = v175 + ((int)((unsigned int)(v175 - v173) >> 31));
    v176[v429] = v529;
    int * v178 = v41->cache_age;
    int v179 = v178[v431];
    int * v180 = v41->cache_age;
    int v532 = v179 + ((int)((unsigned int)(v179 - v173) >> 31));
    v180[v431] = v532;
    int * v182 = v41->cache_age;
    v182[v520] = 0;
    v185 = v520;
  }
  int v535 = (v185 * 2) + (((int)((unsigned int)v61 >> 2)) & 1);
  int v186 = v72[v535];
  int * v187 = v41->regs;
  v187[5] = v186;
  int * v189 = v41->regs;
  int v190 = v189[6];
  int * v191 = v41->regs;
  int v192 = v191[7];
  bool v541 = v190 >= v192;
  struct StateT * v409;
  if (v541) {
    int v193 = v41->timer;
    int v542 = v193 + 15;
    v41->timer = v542;
    int * v195 = v41->saved_regs;
    int v196 = v195[8];
    int * v197 = v41->regs;
    v197[8] = v196;
    int * v199 = v41->saved_regs;
    int v200 = v199[5];
    int * v201 = v41->regs;
    v201[5] = v200;
    v409 = v41;
  } else {
    int v204 = v41->timer;
    int v549 = v204 + 1;
    v41->timer = v549;
    int * v206 = v41->regs;
    int v207 = v206[6];
    int * v208 = v41->regs;
    int v209 = v208[5];
    int * v210 = v41->cache_tags;
    int v553 = (((int)((unsigned int)((int)((unsigned int)v207 >> 2)) >> 1)) & 1) * 2;
    int v211 = v210[v553];
    int * v212 = v41->cache_tags;
    int v555 = ((((int)((unsigned int)((int)((unsigned int)v207 >> 2)) >> 1)) & 1) * 2) + 1;
    int v213 = v212[v555];
    int * v214 = v41->cache_tags;
    int v557 = 4 + ((((int)((unsigned int)((int)((unsigned int)v207 >> 2)) >> 1)) & 3) * 2);
    int v215 = v214[v557];
    int * v216 = v41->cache_tags;
    int v559 = (4 + ((((int)((unsigned int)((int)((unsigned int)v207 >> 2)) >> 1)) & 3) * 2)) + 1;
    int v217 = v216[v559];
    int v218 = v41->timer;
    int v560 = v218 + ((100 ^ (((~(((v215 ^ ((int)((unsigned int)((int)((unsigned int)v207 >> 2)) >> 1))) | (-(v215 ^ ((int)((unsigned int)((int)((unsigned int)v207 >> 2)) >> 1))))) >> 31)) | (~(((v217 ^ ((int)((unsigned int)((int)((unsigned int)v207 >> 2)) >> 1))) | (-(v217 ^ ((int)((unsigned int)((int)((unsigned int)v207 >> 2)) >> 1))))) >> 31))) & 104)) ^ (((~(((v211 ^ ((int)((unsigned int)((int)((unsigned int)v207 >> 2)) >> 1))) | (-(v211 ^ ((int)((unsigned int)((int)((unsigned int)v207 >> 2)) >> 1))))) >> 31)) | (~(((v213 ^ ((int)((unsigned int)((int)((unsigned int)v207 >> 2)) >> 1))) | (-(v213 ^ ((int)((unsigned int)((int)((unsigned int)v207 >> 2)) >> 1))))) >> 31))) & (1 ^ (100 ^ (((~(((v215 ^ ((int)((unsigned int)((int)((unsigned int)v207 >> 2)) >> 1))) | (-(v215 ^ ((int)((unsigned int)((int)((unsigned int)v207 >> 2)) >> 1))))) >> 31)) | (~(((v217 ^ ((int)((unsigned int)((int)((unsigned int)v207 >> 2)) >> 1))) | (-(v217 ^ ((int)((unsigned int)((int)((unsigned int)v207 >> 2)) >> 1))))) >> 31))) & 104)))));
    v41->timer = v560;
    bool v561 = !(((~(((v211 ^ ((int)((unsigned int)((int)((unsigned int)v207 >> 2)) >> 1))) | (-(v211 ^ ((int)((unsigned int)((int)((unsigned int)v207 >> 2)) >> 1))))) >> 31)) | (~(((v213 ^ ((int)((unsigned int)((int)((unsigned int)v207 >> 2)) >> 1))) | (-(v213 ^ ((int)((unsigned int)((int)((unsigned int)v207 >> 2)) >> 1))))) >> 31))) == 0);
    int v332;
    if (v561) {
      int * v220 = v41->cache_age;
      int v563 = ((((int)((unsigned int)((int)((unsigned int)v207 >> 2)) >> 1)) & 1) * 2) + ((~(((v213 ^ ((int)((unsigned int)((int)((unsigned int)v207 >> 2)) >> 1))) | (-(v213 ^ ((int)((unsigned int)((int)((unsigned int)v207 >> 2)) >> 1))))) >> 31)) & 1);
      int v221 = v220[v563];
      int * v222 = v41->cache_age;
      int v223 = v222[v553];
      int * v224 = v41->cache_age;
      int v566 = v223 + ((int)((unsigned int)(v223 - v221) >> 31));
      v224[v553] = v566;
      int * v226 = v41->cache_age;
      int v227 = v226[v555];
      int * v228 = v41->cache_age;
      int v569 = v227 + ((int)((unsigned int)(v227 - v221) >> 31));
      v228[v555] = v569;
      int * v230 = v41->cache_age;
      v230[v563] = 0;
      v332 = v563;
    } else {
      int * v233 = v41->cache_age;
      int v573 = (((int)((unsigned int)((int)((unsigned int)v207 >> 2)) >> 1)) & 1) * 2;
      int v234 = v233[v573];
      int * v235 = v41->cache_tags;
      int v236 = v235[v573];
      int * v237 = v41->cache_age;
      int v238 = v237[v555];
      int * v239 = v41->cache_tags;
      int v240 = v239[v555];
      bool v577 = !(((~(((v215 ^ ((int)((unsigned int)((int)((unsigned int)v207 >> 2)) >> 1))) | (-(v215 ^ ((int)((unsigned int)((int)((unsigned int)v207 >> 2)) >> 1))))) >> 31)) | (~(((v217 ^ ((int)((unsigned int)((int)((unsigned int)v207 >> 2)) >> 1))) | (-(v217 ^ ((int)((unsigned int)((int)((unsigned int)v207 >> 2)) >> 1))))) >> 31))) == 0);
      int v304;
      if (v577) {
        int * v241 = v41->cache_age;
        int v579 = (4 + ((((int)((unsigned int)((int)((unsigned int)v207 >> 2)) >> 1)) & 3) * 2)) + ((~(((v217 ^ ((int)((unsigned int)((int)((unsigned int)v207 >> 2)) >> 1))) | (-(v217 ^ ((int)((unsigned int)((int)((unsigned int)v207 >> 2)) >> 1))))) >> 31)) & 1);
        int v242 = v241[v579];
        int * v243 = v41->cache_age;
        int v244 = v243[v557];
        int * v245 = v41->cache_age;
        int v582 = v244 + ((int)((unsigned int)(v244 - v242) >> 31));
        v245[v557] = v582;
        int * v247 = v41->cache_age;
        int v248 = v247[v559];
        int * v249 = v41->cache_age;
        int v585 = v248 + ((int)((unsigned int)(v248 - v242) >> 31));
        v249[v559] = v585;
        int * v251 = v41->cache_age;
        v251[v579] = 0;
        v304 = v579;
      } else {
        int * v254 = v41->cache_age;
        int v589 = 4 + ((((int)((unsigned int)((int)((unsigned int)v207 >> 2)) >> 1)) & 3) * 2);
        int v255 = v254[v589];
        int * v256 = v41->cache_tags;
        int v257 = v256[v589];
        int * v258 = v41->cache_age;
        int v259 = v258[v559];
        int * v260 = v41->cache_tags;
        int v261 = v260[v559];
        int * v262 = v41->cache_dirty;
        int v594 = (4 + ((((int)((unsigned int)((int)((unsigned int)v207 >> 2)) >> 1)) & 3) * 2)) + ((((v255 + ((~(((v257 ^ -1) | (-(v257 ^ -1))) >> 31)) & 2)) - (v259 + ((~(((v261 ^ -1) | (-(v261 ^ -1))) >> 31)) & 2))) >> 31) & 1);
        int v263 = v262[v594];
        bool v595 = !(v263 == 0);
        if (v595) {
          int * v264 = v41->cache_tags;
          int v265 = v264[v594];
          int * v266 = v41->cache_vals;
          int v598 = ((4 + ((((int)((unsigned int)((int)((unsigned int)v207 >> 2)) >> 1)) & 3) * 2)) + ((((v255 + ((~(((v257 ^ -1) | (-(v257 ^ -1))) >> 31)) & 2)) - (v259 + ((~(((v261 ^ -1) | (-(v261 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
          int v267 = v266[v598];
          int * v268 = v41->cache_vals;
          int v600 = (((4 + ((((int)((unsigned int)((int)((unsigned int)v207 >> 2)) >> 1)) & 3) * 2)) + ((((v255 + ((~(((v257 ^ -1) | (-(v257 ^ -1))) >> 31)) & 2)) - (v259 + ((~(((v261 ^ -1) | (-(v261 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
          int v269 = v268[v600];
          int * v270 = v41->mem;
          int v602 = v265 * 2;
          v270[v602] = v267;
          int * v272 = v41->mem;
          int v605 = (v265 * 2) + 1;
          v272[v605] = v269;
          ;
        } else {
          ;
        }
        int * v277 = v41->mem;
        int v610 = ((int)((unsigned int)((int)((unsigned int)v207 >> 2)) >> 1)) * 2;
        int v278 = v277[v610];
        int * v279 = v41->mem;
        int v612 = (((int)((unsigned int)((int)((unsigned int)v207 >> 2)) >> 1)) * 2) + 1;
        int v280 = v279[v612];
        int * v281 = v41->cache_vals;
        int v614 = ((4 + ((((int)((unsigned int)((int)((unsigned int)v207 >> 2)) >> 1)) & 3) * 2)) + ((((v255 + ((~(((v257 ^ -1) | (-(v257 ^ -1))) >> 31)) & 2)) - (v259 + ((~(((v261 ^ -1) | (-(v261 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
        v281[v614] = v278;
        int * v283 = v41->cache_vals;
        int v617 = (((4 + ((((int)((unsigned int)((int)((unsigned int)v207 >> 2)) >> 1)) & 3) * 2)) + ((((v255 + ((~(((v257 ^ -1) | (-(v257 ^ -1))) >> 31)) & 2)) - (v259 + ((~(((v261 ^ -1) | (-(v261 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
        v283[v617] = v280;
        int * v285 = v41->cache_tags;
        int v620 = (int)((unsigned int)((int)((unsigned int)v207 >> 2)) >> 1);
        v285[v594] = v620;
        int * v287 = v41->cache_dirty;
        v287[v594] = 0;
        int * v289 = v41->cache_age;
        v289[v594] = 1;
        int * v291 = v41->cache_age;
        int v292 = v291[v594];
        int * v293 = v41->cache_age;
        int v294 = v293[v557];
        int * v295 = v41->cache_age;
        int v628 = v294 + ((int)((unsigned int)(v294 - v292) >> 31));
        v295[v557] = v628;
        int * v297 = v41->cache_age;
        int v298 = v297[v559];
        int * v299 = v41->cache_age;
        int v631 = v298 + ((int)((unsigned int)(v298 - v292) >> 31));
        v299[v559] = v631;
        int * v301 = v41->cache_age;
        v301[v594] = 0;
        v304 = v594;
      }
      int * v305 = v41->cache_vals;
      int v634 = v304 * 2;
      int v306 = v305[v634];
      int * v307 = v41->cache_vals;
      int v636 = (v304 * 2) + 1;
      int v308 = v307[v636];
      int * v309 = v41->cache_vals;
      int v638 = (((((int)((unsigned int)((int)((unsigned int)v207 >> 2)) >> 1)) & 1) * 2) + ((((v234 + ((~(((v236 ^ -1) | (-(v236 ^ -1))) >> 31)) & 2)) - (v238 + ((~(((v240 ^ -1) | (-(v240 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
      v309[v638] = v306;
      int * v311 = v41->cache_vals;
      int v641 = ((((((int)((unsigned int)((int)((unsigned int)v207 >> 2)) >> 1)) & 1) * 2) + ((((v234 + ((~(((v236 ^ -1) | (-(v236 ^ -1))) >> 31)) & 2)) - (v238 + ((~(((v240 ^ -1) | (-(v240 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
      v311[v641] = v308;
      int * v313 = v41->cache_tags;
      int v644 = ((((int)((unsigned int)((int)((unsigned int)v207 >> 2)) >> 1)) & 1) * 2) + ((((v234 + ((~(((v236 ^ -1) | (-(v236 ^ -1))) >> 31)) & 2)) - (v238 + ((~(((v240 ^ -1) | (-(v240 ^ -1))) >> 31)) & 2))) >> 31) & 1);
      int v645 = (int)((unsigned int)((int)((unsigned int)v207 >> 2)) >> 1);
      v313[v644] = v645;
      int * v315 = v41->cache_dirty;
      v315[v644] = 0;
      int * v317 = v41->cache_age;
      v317[v644] = 1;
      int * v319 = v41->cache_age;
      int v320 = v319[v644];
      int * v321 = v41->cache_age;
      int v322 = v321[v553];
      int * v323 = v41->cache_age;
      int v653 = v322 + ((int)((unsigned int)(v322 - v320) >> 31));
      v323[v553] = v653;
      int * v325 = v41->cache_age;
      int v326 = v325[v555];
      int * v327 = v41->cache_age;
      int v656 = v326 + ((int)((unsigned int)(v326 - v320) >> 31));
      v327[v555] = v656;
      int * v329 = v41->cache_age;
      v329[v644] = 0;
      v332 = v644;
    }
    int * v333 = v41->cache_vals;
    int v659 = (v332 * 2) + (((int)((unsigned int)v207 >> 2)) & 1);
    v333[v659] = v209;
    int * v335 = v41->cache_tags;
    int v336 = v335[v557];
    int * v337 = v41->cache_tags;
    int v338 = v337[v559];
    bool v663 = !(((~(((v336 ^ ((int)((unsigned int)((int)((unsigned int)v207 >> 2)) >> 1))) | (-(v336 ^ ((int)((unsigned int)((int)((unsigned int)v207 >> 2)) >> 1))))) >> 31)) | (~(((v338 ^ ((int)((unsigned int)((int)((unsigned int)v207 >> 2)) >> 1))) | (-(v338 ^ ((int)((unsigned int)((int)((unsigned int)v207 >> 2)) >> 1))))) >> 31))) == 0);
    int v402;
    if (v663) {
      int * v339 = v41->cache_age;
      int v665 = (4 + ((((int)((unsigned int)((int)((unsigned int)v207 >> 2)) >> 1)) & 3) * 2)) + ((~(((v338 ^ ((int)((unsigned int)((int)((unsigned int)v207 >> 2)) >> 1))) | (-(v338 ^ ((int)((unsigned int)((int)((unsigned int)v207 >> 2)) >> 1))))) >> 31)) & 1);
      int v340 = v339[v665];
      int * v341 = v41->cache_age;
      int v342 = v341[v557];
      int * v343 = v41->cache_age;
      int v668 = v342 + ((int)((unsigned int)(v342 - v340) >> 31));
      v343[v557] = v668;
      int * v345 = v41->cache_age;
      int v346 = v345[v559];
      int * v347 = v41->cache_age;
      int v671 = v346 + ((int)((unsigned int)(v346 - v340) >> 31));
      v347[v559] = v671;
      int * v349 = v41->cache_age;
      v349[v665] = 0;
      v402 = v665;
    } else {
      int * v352 = v41->cache_age;
      int v675 = 4 + ((((int)((unsigned int)((int)((unsigned int)v207 >> 2)) >> 1)) & 3) * 2);
      int v353 = v352[v675];
      int * v354 = v41->cache_tags;
      int v355 = v354[v675];
      int * v356 = v41->cache_age;
      int v357 = v356[v559];
      int * v358 = v41->cache_tags;
      int v359 = v358[v559];
      int * v360 = v41->cache_dirty;
      int v680 = (4 + ((((int)((unsigned int)((int)((unsigned int)v207 >> 2)) >> 1)) & 3) * 2)) + ((((v353 + ((~(((v355 ^ -1) | (-(v355 ^ -1))) >> 31)) & 2)) - (v357 + ((~(((v359 ^ -1) | (-(v359 ^ -1))) >> 31)) & 2))) >> 31) & 1);
      int v361 = v360[v680];
      bool v681 = !(v361 == 0);
      if (v681) {
        int * v362 = v41->cache_tags;
        int v363 = v362[v680];
        int * v364 = v41->cache_vals;
        int v684 = ((4 + ((((int)((unsigned int)((int)((unsigned int)v207 >> 2)) >> 1)) & 3) * 2)) + ((((v353 + ((~(((v355 ^ -1) | (-(v355 ^ -1))) >> 31)) & 2)) - (v357 + ((~(((v359 ^ -1) | (-(v359 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
        int v365 = v364[v684];
        int * v366 = v41->cache_vals;
        int v686 = (((4 + ((((int)((unsigned int)((int)((unsigned int)v207 >> 2)) >> 1)) & 3) * 2)) + ((((v353 + ((~(((v355 ^ -1) | (-(v355 ^ -1))) >> 31)) & 2)) - (v357 + ((~(((v359 ^ -1) | (-(v359 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
        int v367 = v366[v686];
        int * v368 = v41->mem;
        int v688 = v363 * 2;
        v368[v688] = v365;
        int * v370 = v41->mem;
        int v691 = (v363 * 2) + 1;
        v370[v691] = v367;
        ;
      } else {
        ;
      }
      int * v375 = v41->mem;
      int v696 = ((int)((unsigned int)((int)((unsigned int)v207 >> 2)) >> 1)) * 2;
      int v376 = v375[v696];
      int * v377 = v41->mem;
      int v698 = (((int)((unsigned int)((int)((unsigned int)v207 >> 2)) >> 1)) * 2) + 1;
      int v378 = v377[v698];
      int * v379 = v41->cache_vals;
      int v700 = ((4 + ((((int)((unsigned int)((int)((unsigned int)v207 >> 2)) >> 1)) & 3) * 2)) + ((((v353 + ((~(((v355 ^ -1) | (-(v355 ^ -1))) >> 31)) & 2)) - (v357 + ((~(((v359 ^ -1) | (-(v359 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
      v379[v700] = v376;
      int * v381 = v41->cache_vals;
      int v703 = (((4 + ((((int)((unsigned int)((int)((unsigned int)v207 >> 2)) >> 1)) & 3) * 2)) + ((((v353 + ((~(((v355 ^ -1) | (-(v355 ^ -1))) >> 31)) & 2)) - (v357 + ((~(((v359 ^ -1) | (-(v359 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
      v381[v703] = v378;
      int * v383 = v41->cache_tags;
      int v706 = (int)((unsigned int)((int)((unsigned int)v207 >> 2)) >> 1);
      v383[v680] = v706;
      int * v385 = v41->cache_dirty;
      v385[v680] = 0;
      int * v387 = v41->cache_age;
      v387[v680] = 1;
      int * v389 = v41->cache_age;
      int v390 = v389[v680];
      int * v391 = v41->cache_age;
      int v392 = v391[v557];
      int * v393 = v41->cache_age;
      int v714 = v392 + ((int)((unsigned int)(v392 - v390) >> 31));
      v393[v557] = v714;
      int * v395 = v41->cache_age;
      int v396 = v395[v559];
      int * v397 = v41->cache_age;
      int v717 = v396 + ((int)((unsigned int)(v396 - v390) >> 31));
      v397[v559] = v717;
      int * v399 = v41->cache_age;
      v399[v680] = 0;
      v402 = v680;
    }
    int * v403 = v41->cache_vals;
    int v720 = (v402 * 2) + (((int)((unsigned int)v207 >> 2)) & 1);
    v403[v720] = v209;
    int * v405 = v41->cache_dirty;
    v405[v402] = 1;
    struct StateT * v407 = slot_7(v41);
    v409 = v407;
  }
  return v409;
}

struct StateT * slot_0(struct StateT * v2) {
  int v3 = v2->timer;
  int v9 = v3 + 1;
  v2->timer = v9;
  int * v5 = v2->regs;
  v5[6] = 0;
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