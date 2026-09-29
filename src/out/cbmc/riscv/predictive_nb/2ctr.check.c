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
struct StateT * slot_1(struct StateT * v11);
struct StateT * slot_4(struct StateT * v559);
struct StateT * slot_2(struct StateT * v273);
struct StateT * slot_3(struct StateT * v297);
struct StateT * slot_0(struct StateT * v2);
struct StateT * snippet(struct StateT * v0) {
  struct StateT * v1 = slot_0(v0);
  int v778 = v1->timer;
  int * v779 = v1->reg_ready;
  int v780 = v779[0];
  int v911 = v780 + ((v778 - v780) & (~((v778 - v780) >> 31)));
  v1->timer = v911;
  int v782 = v1->timer;
  int * v783 = v1->reg_ready;
  int v784 = v783[1];
  int v914 = v784 + ((v782 - v784) & (~((v782 - v784) >> 31)));
  v1->timer = v914;
  int v786 = v1->timer;
  int * v787 = v1->reg_ready;
  int v788 = v787[2];
  int v917 = v788 + ((v786 - v788) & (~((v786 - v788) >> 31)));
  v1->timer = v917;
  int v790 = v1->timer;
  int * v791 = v1->reg_ready;
  int v792 = v791[3];
  int v920 = v792 + ((v790 - v792) & (~((v790 - v792) >> 31)));
  v1->timer = v920;
  int v794 = v1->timer;
  int * v795 = v1->reg_ready;
  int v796 = v795[4];
  int v923 = v796 + ((v794 - v796) & (~((v794 - v796) >> 31)));
  v1->timer = v923;
  int v798 = v1->timer;
  int * v799 = v1->reg_ready;
  int v800 = v799[5];
  int v926 = v800 + ((v798 - v800) & (~((v798 - v800) >> 31)));
  v1->timer = v926;
  int v802 = v1->timer;
  int * v803 = v1->reg_ready;
  int v804 = v803[6];
  int v929 = v804 + ((v802 - v804) & (~((v802 - v804) >> 31)));
  v1->timer = v929;
  int v806 = v1->timer;
  int * v807 = v1->reg_ready;
  int v808 = v807[7];
  int v932 = v808 + ((v806 - v808) & (~((v806 - v808) >> 31)));
  v1->timer = v932;
  int v810 = v1->timer;
  int * v811 = v1->reg_ready;
  int v812 = v811[8];
  int v935 = v812 + ((v810 - v812) & (~((v810 - v812) >> 31)));
  v1->timer = v935;
  int v814 = v1->timer;
  int * v815 = v1->reg_ready;
  int v816 = v815[9];
  int v938 = v816 + ((v814 - v816) & (~((v814 - v816) >> 31)));
  v1->timer = v938;
  int v818 = v1->timer;
  int * v819 = v1->reg_ready;
  int v820 = v819[10];
  int v941 = v820 + ((v818 - v820) & (~((v818 - v820) >> 31)));
  v1->timer = v941;
  int v822 = v1->timer;
  int * v823 = v1->reg_ready;
  int v824 = v823[11];
  int v944 = v824 + ((v822 - v824) & (~((v822 - v824) >> 31)));
  v1->timer = v944;
  int v826 = v1->timer;
  int * v827 = v1->reg_ready;
  int v828 = v827[12];
  int v947 = v828 + ((v826 - v828) & (~((v826 - v828) >> 31)));
  v1->timer = v947;
  int v830 = v1->timer;
  int * v831 = v1->reg_ready;
  int v832 = v831[13];
  int v950 = v832 + ((v830 - v832) & (~((v830 - v832) >> 31)));
  v1->timer = v950;
  int v834 = v1->timer;
  int * v835 = v1->reg_ready;
  int v836 = v835[14];
  int v953 = v836 + ((v834 - v836) & (~((v834 - v836) >> 31)));
  v1->timer = v953;
  int v838 = v1->timer;
  int * v839 = v1->reg_ready;
  int v840 = v839[15];
  int v956 = v840 + ((v838 - v840) & (~((v838 - v840) >> 31)));
  v1->timer = v956;
  int v842 = v1->timer;
  int * v843 = v1->reg_ready;
  int v844 = v843[16];
  int v959 = v844 + ((v842 - v844) & (~((v842 - v844) >> 31)));
  v1->timer = v959;
  int v846 = v1->timer;
  int * v847 = v1->reg_ready;
  int v848 = v847[17];
  int v962 = v848 + ((v846 - v848) & (~((v846 - v848) >> 31)));
  v1->timer = v962;
  int v850 = v1->timer;
  int * v851 = v1->reg_ready;
  int v852 = v851[18];
  int v965 = v852 + ((v850 - v852) & (~((v850 - v852) >> 31)));
  v1->timer = v965;
  int v854 = v1->timer;
  int * v855 = v1->reg_ready;
  int v856 = v855[19];
  int v968 = v856 + ((v854 - v856) & (~((v854 - v856) >> 31)));
  v1->timer = v968;
  int v858 = v1->timer;
  int * v859 = v1->reg_ready;
  int v860 = v859[20];
  int v971 = v860 + ((v858 - v860) & (~((v858 - v860) >> 31)));
  v1->timer = v971;
  int v862 = v1->timer;
  int * v863 = v1->reg_ready;
  int v864 = v863[21];
  int v974 = v864 + ((v862 - v864) & (~((v862 - v864) >> 31)));
  v1->timer = v974;
  int v866 = v1->timer;
  int * v867 = v1->reg_ready;
  int v868 = v867[22];
  int v977 = v868 + ((v866 - v868) & (~((v866 - v868) >> 31)));
  v1->timer = v977;
  int v870 = v1->timer;
  int * v871 = v1->reg_ready;
  int v872 = v871[23];
  int v980 = v872 + ((v870 - v872) & (~((v870 - v872) >> 31)));
  v1->timer = v980;
  int v874 = v1->timer;
  int * v875 = v1->reg_ready;
  int v876 = v875[24];
  int v983 = v876 + ((v874 - v876) & (~((v874 - v876) >> 31)));
  v1->timer = v983;
  int v878 = v1->timer;
  int * v879 = v1->reg_ready;
  int v880 = v879[25];
  int v986 = v880 + ((v878 - v880) & (~((v878 - v880) >> 31)));
  v1->timer = v986;
  int v882 = v1->timer;
  int * v883 = v1->reg_ready;
  int v884 = v883[26];
  int v989 = v884 + ((v882 - v884) & (~((v882 - v884) >> 31)));
  v1->timer = v989;
  int v886 = v1->timer;
  int * v887 = v1->reg_ready;
  int v888 = v887[27];
  int v992 = v888 + ((v886 - v888) & (~((v886 - v888) >> 31)));
  v1->timer = v992;
  int v890 = v1->timer;
  int * v891 = v1->reg_ready;
  int v892 = v891[28];
  int v995 = v892 + ((v890 - v892) & (~((v890 - v892) >> 31)));
  v1->timer = v995;
  int v894 = v1->timer;
  int * v895 = v1->reg_ready;
  int v896 = v895[29];
  int v998 = v896 + ((v894 - v896) & (~((v894 - v896) >> 31)));
  v1->timer = v998;
  int v898 = v1->timer;
  int * v899 = v1->reg_ready;
  int v900 = v899[30];
  int v1001 = v900 + ((v898 - v900) & (~((v898 - v900) >> 31)));
  v1->timer = v1001;
  int v902 = v1->timer;
  int * v903 = v1->reg_ready;
  int v904 = v903[31];
  int v1004 = v904 + ((v902 - v904) & (~((v902 - v904) >> 31)));
  v1->timer = v1004;
  return v1;
}

struct StateT * slot_1(struct StateT * v11) {
  int * v12 = v11->saved_regs;
  int * v13 = v11->regs;
  int v14 = v13[11];
  v12[11] = v14;
  int v16 = v11->timer;
  int v17 = v11->timer;
  int v156 = v17 + 1;
  v11->timer = v156;
  int * v19 = v11->reg_ready;
  int v20 = v19[10];
  int * v21 = v11->regs;
  int v22 = v21[10];
  int * v23 = v11->cache_tags;
  int v161 = (((int)((unsigned int)((int)((unsigned int)v22 >> 2)) >> 1)) & 1) * 2;
  int v24 = v23[v161];
  int * v25 = v11->cache_tags;
  int v163 = ((((int)((unsigned int)((int)((unsigned int)v22 >> 2)) >> 1)) & 1) * 2) + 1;
  int v26 = v25[v163];
  int * v27 = v11->cache_tags;
  int v165 = 4 + ((((int)((unsigned int)((int)((unsigned int)v22 >> 2)) >> 1)) & 3) * 2);
  int v28 = v27[v165];
  int * v29 = v11->cache_tags;
  int v167 = (4 + ((((int)((unsigned int)((int)((unsigned int)v22 >> 2)) >> 1)) & 3) * 2)) + 1;
  int v30 = v29[v167];
  int * v31 = v11->cache_vals;
  bool v168 = !(((~(((v24 ^ ((int)((unsigned int)((int)((unsigned int)v22 >> 2)) >> 1))) | (-(v24 ^ ((int)((unsigned int)((int)((unsigned int)v22 >> 2)) >> 1))))) >> 31)) | (~(((v26 ^ ((int)((unsigned int)((int)((unsigned int)v22 >> 2)) >> 1))) | (-(v26 ^ ((int)((unsigned int)((int)((unsigned int)v22 >> 2)) >> 1))))) >> 31))) == 0);
  int v144;
  if (v168) {
    int * v32 = v11->cache_age;
    int v170 = ((((int)((unsigned int)((int)((unsigned int)v22 >> 2)) >> 1)) & 1) * 2) + ((~(((v26 ^ ((int)((unsigned int)((int)((unsigned int)v22 >> 2)) >> 1))) | (-(v26 ^ ((int)((unsigned int)((int)((unsigned int)v22 >> 2)) >> 1))))) >> 31)) & 1);
    int v33 = v32[v170];
    int * v34 = v11->cache_age;
    int v35 = v34[v161];
    int * v36 = v11->cache_age;
    int v173 = v35 + ((int)((unsigned int)(v35 - v33) >> 31));
    v36[v161] = v173;
    int * v38 = v11->cache_age;
    int v39 = v38[v163];
    int * v40 = v11->cache_age;
    int v176 = v39 + ((int)((unsigned int)(v39 - v33) >> 31));
    v40[v163] = v176;
    int * v42 = v11->cache_age;
    v42[v170] = 0;
    v144 = v170;
  } else {
    int * v45 = v11->cache_age;
    int v180 = (((int)((unsigned int)((int)((unsigned int)v22 >> 2)) >> 1)) & 1) * 2;
    int v46 = v45[v180];
    int * v47 = v11->cache_tags;
    int v48 = v47[v180];
    int * v49 = v11->cache_age;
    int v50 = v49[v163];
    int * v51 = v11->cache_tags;
    int v52 = v51[v163];
    bool v184 = !(((~(((v28 ^ ((int)((unsigned int)((int)((unsigned int)v22 >> 2)) >> 1))) | (-(v28 ^ ((int)((unsigned int)((int)((unsigned int)v22 >> 2)) >> 1))))) >> 31)) | (~(((v30 ^ ((int)((unsigned int)((int)((unsigned int)v22 >> 2)) >> 1))) | (-(v30 ^ ((int)((unsigned int)((int)((unsigned int)v22 >> 2)) >> 1))))) >> 31))) == 0);
    int v116;
    if (v184) {
      int * v53 = v11->cache_age;
      int v186 = (4 + ((((int)((unsigned int)((int)((unsigned int)v22 >> 2)) >> 1)) & 3) * 2)) + ((~(((v30 ^ ((int)((unsigned int)((int)((unsigned int)v22 >> 2)) >> 1))) | (-(v30 ^ ((int)((unsigned int)((int)((unsigned int)v22 >> 2)) >> 1))))) >> 31)) & 1);
      int v54 = v53[v186];
      int * v55 = v11->cache_age;
      int v56 = v55[v165];
      int * v57 = v11->cache_age;
      int v189 = v56 + ((int)((unsigned int)(v56 - v54) >> 31));
      v57[v165] = v189;
      int * v59 = v11->cache_age;
      int v60 = v59[v167];
      int * v61 = v11->cache_age;
      int v192 = v60 + ((int)((unsigned int)(v60 - v54) >> 31));
      v61[v167] = v192;
      int * v63 = v11->cache_age;
      v63[v186] = 0;
      v116 = v186;
    } else {
      int * v66 = v11->cache_age;
      int v196 = 4 + ((((int)((unsigned int)((int)((unsigned int)v22 >> 2)) >> 1)) & 3) * 2);
      int v67 = v66[v196];
      int * v68 = v11->cache_tags;
      int v69 = v68[v196];
      int * v70 = v11->cache_age;
      int v71 = v70[v167];
      int * v72 = v11->cache_tags;
      int v73 = v72[v167];
      int * v74 = v11->cache_dirty;
      int v201 = (4 + ((((int)((unsigned int)((int)((unsigned int)v22 >> 2)) >> 1)) & 3) * 2)) + ((((v67 + ((~(((v69 ^ -1) | (-(v69 ^ -1))) >> 31)) & 2)) - (v71 + ((~(((v73 ^ -1) | (-(v73 ^ -1))) >> 31)) & 2))) >> 31) & 1);
      int v75 = v74[v201];
      bool v202 = !(v75 == 0);
      if (v202) {
        int * v76 = v11->cache_tags;
        int v77 = v76[v201];
        int * v78 = v11->cache_vals;
        int v205 = ((4 + ((((int)((unsigned int)((int)((unsigned int)v22 >> 2)) >> 1)) & 3) * 2)) + ((((v67 + ((~(((v69 ^ -1) | (-(v69 ^ -1))) >> 31)) & 2)) - (v71 + ((~(((v73 ^ -1) | (-(v73 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
        int v79 = v78[v205];
        int * v80 = v11->cache_vals;
        int v207 = (((4 + ((((int)((unsigned int)((int)((unsigned int)v22 >> 2)) >> 1)) & 3) * 2)) + ((((v67 + ((~(((v69 ^ -1) | (-(v69 ^ -1))) >> 31)) & 2)) - (v71 + ((~(((v73 ^ -1) | (-(v73 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
        int v81 = v80[v207];
        int * v82 = v11->mem;
        int v209 = v77 * 2;
        v82[v209] = v79;
        int * v84 = v11->mem;
        int v212 = (v77 * 2) + 1;
        v84[v212] = v81;
        ;
      } else {
        ;
      }
      int * v89 = v11->mem;
      int v217 = ((int)((unsigned int)((int)((unsigned int)v22 >> 2)) >> 1)) * 2;
      int v90 = v89[v217];
      int * v91 = v11->mem;
      int v219 = (((int)((unsigned int)((int)((unsigned int)v22 >> 2)) >> 1)) * 2) + 1;
      int v92 = v91[v219];
      int * v93 = v11->cache_vals;
      int v221 = ((4 + ((((int)((unsigned int)((int)((unsigned int)v22 >> 2)) >> 1)) & 3) * 2)) + ((((v67 + ((~(((v69 ^ -1) | (-(v69 ^ -1))) >> 31)) & 2)) - (v71 + ((~(((v73 ^ -1) | (-(v73 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
      v93[v221] = v90;
      int * v95 = v11->cache_vals;
      int v224 = (((4 + ((((int)((unsigned int)((int)((unsigned int)v22 >> 2)) >> 1)) & 3) * 2)) + ((((v67 + ((~(((v69 ^ -1) | (-(v69 ^ -1))) >> 31)) & 2)) - (v71 + ((~(((v73 ^ -1) | (-(v73 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
      v95[v224] = v92;
      int * v97 = v11->cache_tags;
      int v227 = (int)((unsigned int)((int)((unsigned int)v22 >> 2)) >> 1);
      v97[v201] = v227;
      int * v99 = v11->cache_dirty;
      v99[v201] = 0;
      int * v101 = v11->cache_age;
      v101[v201] = 1;
      int * v103 = v11->cache_age;
      int v104 = v103[v201];
      int * v105 = v11->cache_age;
      int v106 = v105[v165];
      int * v107 = v11->cache_age;
      int v235 = v106 + ((int)((unsigned int)(v106 - v104) >> 31));
      v107[v165] = v235;
      int * v109 = v11->cache_age;
      int v110 = v109[v167];
      int * v111 = v11->cache_age;
      int v238 = v110 + ((int)((unsigned int)(v110 - v104) >> 31));
      v111[v167] = v238;
      int * v113 = v11->cache_age;
      v113[v201] = 0;
      v116 = v201;
    }
    int * v117 = v11->cache_vals;
    int v241 = v116 * 2;
    int v118 = v117[v241];
    int * v119 = v11->cache_vals;
    int v243 = (v116 * 2) + 1;
    int v120 = v119[v243];
    int * v121 = v11->cache_vals;
    int v245 = (((((int)((unsigned int)((int)((unsigned int)v22 >> 2)) >> 1)) & 1) * 2) + ((((v46 + ((~(((v48 ^ -1) | (-(v48 ^ -1))) >> 31)) & 2)) - (v50 + ((~(((v52 ^ -1) | (-(v52 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
    v121[v245] = v118;
    int * v123 = v11->cache_vals;
    int v248 = ((((((int)((unsigned int)((int)((unsigned int)v22 >> 2)) >> 1)) & 1) * 2) + ((((v46 + ((~(((v48 ^ -1) | (-(v48 ^ -1))) >> 31)) & 2)) - (v50 + ((~(((v52 ^ -1) | (-(v52 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
    v123[v248] = v120;
    int * v125 = v11->cache_tags;
    int v251 = ((((int)((unsigned int)((int)((unsigned int)v22 >> 2)) >> 1)) & 1) * 2) + ((((v46 + ((~(((v48 ^ -1) | (-(v48 ^ -1))) >> 31)) & 2)) - (v50 + ((~(((v52 ^ -1) | (-(v52 ^ -1))) >> 31)) & 2))) >> 31) & 1);
    int v252 = (int)((unsigned int)((int)((unsigned int)v22 >> 2)) >> 1);
    v125[v251] = v252;
    int * v127 = v11->cache_dirty;
    v127[v251] = 0;
    int * v129 = v11->cache_age;
    v129[v251] = 1;
    int * v131 = v11->cache_age;
    int v132 = v131[v251];
    int * v133 = v11->cache_age;
    int v134 = v133[v161];
    int * v135 = v11->cache_age;
    int v260 = v134 + ((int)((unsigned int)(v134 - v132) >> 31));
    v135[v161] = v260;
    int * v137 = v11->cache_age;
    int v138 = v137[v163];
    int * v139 = v11->cache_age;
    int v263 = v138 + ((int)((unsigned int)(v138 - v132) >> 31));
    v139[v163] = v263;
    int * v141 = v11->cache_age;
    v141[v251] = 0;
    v144 = v251;
  }
  int v266 = (v144 * 2) + (((int)((unsigned int)v22 >> 2)) & 1);
  int v145 = v31[v266];
  int * v146 = v11->reg_ready;
  int v268 = ((v20 + ((v16 - v20) & (~((v16 - v20) >> 31)))) + 1) + ((100 ^ (((~(((v28 ^ ((int)((unsigned int)((int)((unsigned int)v22 >> 2)) >> 1))) | (-(v28 ^ ((int)((unsigned int)((int)((unsigned int)v22 >> 2)) >> 1))))) >> 31)) | (~(((v30 ^ ((int)((unsigned int)((int)((unsigned int)v22 >> 2)) >> 1))) | (-(v30 ^ ((int)((unsigned int)((int)((unsigned int)v22 >> 2)) >> 1))))) >> 31))) & 104)) ^ (((~(((v24 ^ ((int)((unsigned int)((int)((unsigned int)v22 >> 2)) >> 1))) | (-(v24 ^ ((int)((unsigned int)((int)((unsigned int)v22 >> 2)) >> 1))))) >> 31)) | (~(((v26 ^ ((int)((unsigned int)((int)((unsigned int)v22 >> 2)) >> 1))) | (-(v26 ^ ((int)((unsigned int)((int)((unsigned int)v22 >> 2)) >> 1))))) >> 31))) & (1 ^ (100 ^ (((~(((v28 ^ ((int)((unsigned int)((int)((unsigned int)v22 >> 2)) >> 1))) | (-(v28 ^ ((int)((unsigned int)((int)((unsigned int)v22 >> 2)) >> 1))))) >> 31)) | (~(((v30 ^ ((int)((unsigned int)((int)((unsigned int)v22 >> 2)) >> 1))) | (-(v30 ^ ((int)((unsigned int)((int)((unsigned int)v22 >> 2)) >> 1))))) >> 31))) & 104)))));
  v146[11] = v268;
  int * v148 = v11->regs;
  v148[11] = v145;
  struct StateT * v150 = slot_2(v11);
  return v150;
}

struct StateT * slot_4(struct StateT * v559) {
  int * v560 = v559->regs;
  int v561 = v560[10];
  bool v674 = v561 == 0;
  struct StateT * v670;
  if (v674) {
    int v562 = v559->timer;
    int v675 = v562 + 15;
    v559->timer = v675;
    int * v564 = v559->saved_regs;
    int v565 = v564[11];
    int * v566 = v559->regs;
    v566[11] = v565;
    int * v568 = v559->saved_regs;
    int v569 = v568[12];
    int * v570 = v559->regs;
    v570[12] = v569;
    int * v572 = v559->reg_ready;
    int v573 = v559->timer;
    v572[0] = v573;
    int * v575 = v559->reg_ready;
    int v576 = v559->timer;
    v575[1] = v576;
    int * v578 = v559->reg_ready;
    int v579 = v559->timer;
    v578[2] = v579;
    int * v581 = v559->reg_ready;
    int v582 = v559->timer;
    v581[3] = v582;
    int * v584 = v559->reg_ready;
    int v585 = v559->timer;
    v584[4] = v585;
    int * v587 = v559->reg_ready;
    int v588 = v559->timer;
    v587[5] = v588;
    int * v590 = v559->reg_ready;
    int v591 = v559->timer;
    v590[6] = v591;
    int * v593 = v559->reg_ready;
    int v594 = v559->timer;
    v593[7] = v594;
    int * v596 = v559->reg_ready;
    int v597 = v559->timer;
    v596[8] = v597;
    int * v599 = v559->reg_ready;
    int v600 = v559->timer;
    v599[9] = v600;
    int * v602 = v559->reg_ready;
    int v603 = v559->timer;
    v602[10] = v603;
    int * v605 = v559->reg_ready;
    int v606 = v559->timer;
    v605[11] = v606;
    int * v608 = v559->reg_ready;
    int v609 = v559->timer;
    v608[12] = v609;
    int * v611 = v559->reg_ready;
    int v612 = v559->timer;
    v611[13] = v612;
    int * v614 = v559->reg_ready;
    int v615 = v559->timer;
    v614[14] = v615;
    int * v617 = v559->reg_ready;
    int v618 = v559->timer;
    v617[15] = v618;
    int * v620 = v559->reg_ready;
    int v621 = v559->timer;
    v620[16] = v621;
    int * v623 = v559->reg_ready;
    int v624 = v559->timer;
    v623[17] = v624;
    int * v626 = v559->reg_ready;
    int v627 = v559->timer;
    v626[18] = v627;
    int * v629 = v559->reg_ready;
    int v630 = v559->timer;
    v629[19] = v630;
    int * v632 = v559->reg_ready;
    int v633 = v559->timer;
    v632[20] = v633;
    int * v635 = v559->reg_ready;
    int v636 = v559->timer;
    v635[21] = v636;
    int * v638 = v559->reg_ready;
    int v639 = v559->timer;
    v638[22] = v639;
    int * v641 = v559->reg_ready;
    int v642 = v559->timer;
    v641[23] = v642;
    int * v644 = v559->reg_ready;
    int v645 = v559->timer;
    v644[24] = v645;
    int * v647 = v559->reg_ready;
    int v648 = v559->timer;
    v647[25] = v648;
    int * v650 = v559->reg_ready;
    int v651 = v559->timer;
    v650[26] = v651;
    int * v653 = v559->reg_ready;
    int v654 = v559->timer;
    v653[27] = v654;
    int * v656 = v559->reg_ready;
    int v657 = v559->timer;
    v656[28] = v657;
    int * v659 = v559->reg_ready;
    int v660 = v559->timer;
    v659[29] = v660;
    int * v662 = v559->reg_ready;
    int v663 = v559->timer;
    v662[30] = v663;
    int * v665 = v559->reg_ready;
    int v666 = v559->timer;
    v665[31] = v666;
    v670 = v559;
  } else {
    v670 = v559;
  }
  return v670;
}

struct StateT * slot_2(struct StateT * v273) {
  int v274 = v273->timer;
  int v275 = v273->timer;
  int v287 = v275 + 1;
  v273->timer = v287;
  int * v277 = v273->reg_ready;
  int v278 = v277[11];
  int * v279 = v273->regs;
  int v280 = v279[11];
  int * v281 = v273->reg_ready;
  int v292 = (v278 + ((v274 - v278) & (~((v274 - v278) >> 31)))) + 1;
  v281[11] = v292;
  int * v283 = v273->regs;
  int v294 = v280 << 2;
  v283[11] = v294;
  struct StateT * v285 = slot_3(v273);
  return v285;
}

struct StateT * slot_3(struct StateT * v297) {
  int * v298 = v297->saved_regs;
  int * v299 = v297->regs;
  int v300 = v299[12];
  v298[12] = v300;
  int v302 = v297->timer;
  int v303 = v297->timer;
  int v442 = v303 + 1;
  v297->timer = v442;
  int * v305 = v297->reg_ready;
  int v306 = v305[11];
  int * v307 = v297->regs;
  int v308 = v307[11];
  int * v309 = v297->cache_tags;
  int v447 = (((int)((unsigned int)((int)((unsigned int)(v308 + 16) >> 2)) >> 1)) & 1) * 2;
  int v310 = v309[v447];
  int * v311 = v297->cache_tags;
  int v449 = ((((int)((unsigned int)((int)((unsigned int)(v308 + 16) >> 2)) >> 1)) & 1) * 2) + 1;
  int v312 = v311[v449];
  int * v313 = v297->cache_tags;
  int v451 = 4 + ((((int)((unsigned int)((int)((unsigned int)(v308 + 16) >> 2)) >> 1)) & 3) * 2);
  int v314 = v313[v451];
  int * v315 = v297->cache_tags;
  int v453 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v308 + 16) >> 2)) >> 1)) & 3) * 2)) + 1;
  int v316 = v315[v453];
  int * v317 = v297->cache_vals;
  bool v454 = !(((~(((v310 ^ ((int)((unsigned int)((int)((unsigned int)(v308 + 16) >> 2)) >> 1))) | (-(v310 ^ ((int)((unsigned int)((int)((unsigned int)(v308 + 16) >> 2)) >> 1))))) >> 31)) | (~(((v312 ^ ((int)((unsigned int)((int)((unsigned int)(v308 + 16) >> 2)) >> 1))) | (-(v312 ^ ((int)((unsigned int)((int)((unsigned int)(v308 + 16) >> 2)) >> 1))))) >> 31))) == 0);
  int v430;
  if (v454) {
    int * v318 = v297->cache_age;
    int v456 = ((((int)((unsigned int)((int)((unsigned int)(v308 + 16) >> 2)) >> 1)) & 1) * 2) + ((~(((v312 ^ ((int)((unsigned int)((int)((unsigned int)(v308 + 16) >> 2)) >> 1))) | (-(v312 ^ ((int)((unsigned int)((int)((unsigned int)(v308 + 16) >> 2)) >> 1))))) >> 31)) & 1);
    int v319 = v318[v456];
    int * v320 = v297->cache_age;
    int v321 = v320[v447];
    int * v322 = v297->cache_age;
    int v459 = v321 + ((int)((unsigned int)(v321 - v319) >> 31));
    v322[v447] = v459;
    int * v324 = v297->cache_age;
    int v325 = v324[v449];
    int * v326 = v297->cache_age;
    int v462 = v325 + ((int)((unsigned int)(v325 - v319) >> 31));
    v326[v449] = v462;
    int * v328 = v297->cache_age;
    v328[v456] = 0;
    v430 = v456;
  } else {
    int * v331 = v297->cache_age;
    int v466 = (((int)((unsigned int)((int)((unsigned int)(v308 + 16) >> 2)) >> 1)) & 1) * 2;
    int v332 = v331[v466];
    int * v333 = v297->cache_tags;
    int v334 = v333[v466];
    int * v335 = v297->cache_age;
    int v336 = v335[v449];
    int * v337 = v297->cache_tags;
    int v338 = v337[v449];
    bool v470 = !(((~(((v314 ^ ((int)((unsigned int)((int)((unsigned int)(v308 + 16) >> 2)) >> 1))) | (-(v314 ^ ((int)((unsigned int)((int)((unsigned int)(v308 + 16) >> 2)) >> 1))))) >> 31)) | (~(((v316 ^ ((int)((unsigned int)((int)((unsigned int)(v308 + 16) >> 2)) >> 1))) | (-(v316 ^ ((int)((unsigned int)((int)((unsigned int)(v308 + 16) >> 2)) >> 1))))) >> 31))) == 0);
    int v402;
    if (v470) {
      int * v339 = v297->cache_age;
      int v472 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v308 + 16) >> 2)) >> 1)) & 3) * 2)) + ((~(((v316 ^ ((int)((unsigned int)((int)((unsigned int)(v308 + 16) >> 2)) >> 1))) | (-(v316 ^ ((int)((unsigned int)((int)((unsigned int)(v308 + 16) >> 2)) >> 1))))) >> 31)) & 1);
      int v340 = v339[v472];
      int * v341 = v297->cache_age;
      int v342 = v341[v451];
      int * v343 = v297->cache_age;
      int v475 = v342 + ((int)((unsigned int)(v342 - v340) >> 31));
      v343[v451] = v475;
      int * v345 = v297->cache_age;
      int v346 = v345[v453];
      int * v347 = v297->cache_age;
      int v478 = v346 + ((int)((unsigned int)(v346 - v340) >> 31));
      v347[v453] = v478;
      int * v349 = v297->cache_age;
      v349[v472] = 0;
      v402 = v472;
    } else {
      int * v352 = v297->cache_age;
      int v482 = 4 + ((((int)((unsigned int)((int)((unsigned int)(v308 + 16) >> 2)) >> 1)) & 3) * 2);
      int v353 = v352[v482];
      int * v354 = v297->cache_tags;
      int v355 = v354[v482];
      int * v356 = v297->cache_age;
      int v357 = v356[v453];
      int * v358 = v297->cache_tags;
      int v359 = v358[v453];
      int * v360 = v297->cache_dirty;
      int v487 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v308 + 16) >> 2)) >> 1)) & 3) * 2)) + ((((v353 + ((~(((v355 ^ -1) | (-(v355 ^ -1))) >> 31)) & 2)) - (v357 + ((~(((v359 ^ -1) | (-(v359 ^ -1))) >> 31)) & 2))) >> 31) & 1);
      int v361 = v360[v487];
      bool v488 = !(v361 == 0);
      if (v488) {
        int * v362 = v297->cache_tags;
        int v363 = v362[v487];
        int * v364 = v297->cache_vals;
        int v491 = ((4 + ((((int)((unsigned int)((int)((unsigned int)(v308 + 16) >> 2)) >> 1)) & 3) * 2)) + ((((v353 + ((~(((v355 ^ -1) | (-(v355 ^ -1))) >> 31)) & 2)) - (v357 + ((~(((v359 ^ -1) | (-(v359 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
        int v365 = v364[v491];
        int * v366 = v297->cache_vals;
        int v493 = (((4 + ((((int)((unsigned int)((int)((unsigned int)(v308 + 16) >> 2)) >> 1)) & 3) * 2)) + ((((v353 + ((~(((v355 ^ -1) | (-(v355 ^ -1))) >> 31)) & 2)) - (v357 + ((~(((v359 ^ -1) | (-(v359 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
        int v367 = v366[v493];
        int * v368 = v297->mem;
        int v495 = v363 * 2;
        v368[v495] = v365;
        int * v370 = v297->mem;
        int v498 = (v363 * 2) + 1;
        v370[v498] = v367;
        ;
      } else {
        ;
      }
      int * v375 = v297->mem;
      int v503 = ((int)((unsigned int)((int)((unsigned int)(v308 + 16) >> 2)) >> 1)) * 2;
      int v376 = v375[v503];
      int * v377 = v297->mem;
      int v505 = (((int)((unsigned int)((int)((unsigned int)(v308 + 16) >> 2)) >> 1)) * 2) + 1;
      int v378 = v377[v505];
      int * v379 = v297->cache_vals;
      int v507 = ((4 + ((((int)((unsigned int)((int)((unsigned int)(v308 + 16) >> 2)) >> 1)) & 3) * 2)) + ((((v353 + ((~(((v355 ^ -1) | (-(v355 ^ -1))) >> 31)) & 2)) - (v357 + ((~(((v359 ^ -1) | (-(v359 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
      v379[v507] = v376;
      int * v381 = v297->cache_vals;
      int v510 = (((4 + ((((int)((unsigned int)((int)((unsigned int)(v308 + 16) >> 2)) >> 1)) & 3) * 2)) + ((((v353 + ((~(((v355 ^ -1) | (-(v355 ^ -1))) >> 31)) & 2)) - (v357 + ((~(((v359 ^ -1) | (-(v359 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
      v381[v510] = v378;
      int * v383 = v297->cache_tags;
      int v513 = (int)((unsigned int)((int)((unsigned int)(v308 + 16) >> 2)) >> 1);
      v383[v487] = v513;
      int * v385 = v297->cache_dirty;
      v385[v487] = 0;
      int * v387 = v297->cache_age;
      v387[v487] = 1;
      int * v389 = v297->cache_age;
      int v390 = v389[v487];
      int * v391 = v297->cache_age;
      int v392 = v391[v451];
      int * v393 = v297->cache_age;
      int v521 = v392 + ((int)((unsigned int)(v392 - v390) >> 31));
      v393[v451] = v521;
      int * v395 = v297->cache_age;
      int v396 = v395[v453];
      int * v397 = v297->cache_age;
      int v524 = v396 + ((int)((unsigned int)(v396 - v390) >> 31));
      v397[v453] = v524;
      int * v399 = v297->cache_age;
      v399[v487] = 0;
      v402 = v487;
    }
    int * v403 = v297->cache_vals;
    int v527 = v402 * 2;
    int v404 = v403[v527];
    int * v405 = v297->cache_vals;
    int v529 = (v402 * 2) + 1;
    int v406 = v405[v529];
    int * v407 = v297->cache_vals;
    int v531 = (((((int)((unsigned int)((int)((unsigned int)(v308 + 16) >> 2)) >> 1)) & 1) * 2) + ((((v332 + ((~(((v334 ^ -1) | (-(v334 ^ -1))) >> 31)) & 2)) - (v336 + ((~(((v338 ^ -1) | (-(v338 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
    v407[v531] = v404;
    int * v409 = v297->cache_vals;
    int v534 = ((((((int)((unsigned int)((int)((unsigned int)(v308 + 16) >> 2)) >> 1)) & 1) * 2) + ((((v332 + ((~(((v334 ^ -1) | (-(v334 ^ -1))) >> 31)) & 2)) - (v336 + ((~(((v338 ^ -1) | (-(v338 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
    v409[v534] = v406;
    int * v411 = v297->cache_tags;
    int v537 = ((((int)((unsigned int)((int)((unsigned int)(v308 + 16) >> 2)) >> 1)) & 1) * 2) + ((((v332 + ((~(((v334 ^ -1) | (-(v334 ^ -1))) >> 31)) & 2)) - (v336 + ((~(((v338 ^ -1) | (-(v338 ^ -1))) >> 31)) & 2))) >> 31) & 1);
    int v538 = (int)((unsigned int)((int)((unsigned int)(v308 + 16) >> 2)) >> 1);
    v411[v537] = v538;
    int * v413 = v297->cache_dirty;
    v413[v537] = 0;
    int * v415 = v297->cache_age;
    v415[v537] = 1;
    int * v417 = v297->cache_age;
    int v418 = v417[v537];
    int * v419 = v297->cache_age;
    int v420 = v419[v447];
    int * v421 = v297->cache_age;
    int v546 = v420 + ((int)((unsigned int)(v420 - v418) >> 31));
    v421[v447] = v546;
    int * v423 = v297->cache_age;
    int v424 = v423[v449];
    int * v425 = v297->cache_age;
    int v549 = v424 + ((int)((unsigned int)(v424 - v418) >> 31));
    v425[v449] = v549;
    int * v427 = v297->cache_age;
    v427[v537] = 0;
    v430 = v537;
  }
  int v552 = (v430 * 2) + (((int)((unsigned int)(v308 + 16) >> 2)) & 1);
  int v431 = v317[v552];
  int * v432 = v297->reg_ready;
  int v554 = ((v306 + ((v302 - v306) & (~((v302 - v306) >> 31)))) + 1) + ((100 ^ (((~(((v314 ^ ((int)((unsigned int)((int)((unsigned int)(v308 + 16) >> 2)) >> 1))) | (-(v314 ^ ((int)((unsigned int)((int)((unsigned int)(v308 + 16) >> 2)) >> 1))))) >> 31)) | (~(((v316 ^ ((int)((unsigned int)((int)((unsigned int)(v308 + 16) >> 2)) >> 1))) | (-(v316 ^ ((int)((unsigned int)((int)((unsigned int)(v308 + 16) >> 2)) >> 1))))) >> 31))) & 104)) ^ (((~(((v310 ^ ((int)((unsigned int)((int)((unsigned int)(v308 + 16) >> 2)) >> 1))) | (-(v310 ^ ((int)((unsigned int)((int)((unsigned int)(v308 + 16) >> 2)) >> 1))))) >> 31)) | (~(((v312 ^ ((int)((unsigned int)((int)((unsigned int)(v308 + 16) >> 2)) >> 1))) | (-(v312 ^ ((int)((unsigned int)((int)((unsigned int)(v308 + 16) >> 2)) >> 1))))) >> 31))) & (1 ^ (100 ^ (((~(((v314 ^ ((int)((unsigned int)((int)((unsigned int)(v308 + 16) >> 2)) >> 1))) | (-(v314 ^ ((int)((unsigned int)((int)((unsigned int)(v308 + 16) >> 2)) >> 1))))) >> 31)) | (~(((v316 ^ ((int)((unsigned int)((int)((unsigned int)(v308 + 16) >> 2)) >> 1))) | (-(v316 ^ ((int)((unsigned int)((int)((unsigned int)(v308 + 16) >> 2)) >> 1))))) >> 31))) & 104)))));
  v432[12] = v554;
  int * v434 = v297->regs;
  v434[12] = v431;
  struct StateT * v436 = slot_4(v297);
  return v436;
}

struct StateT * slot_0(struct StateT * v2) {
  int v3 = v2->timer;
  int v4 = v2->timer;
  int v8 = v4 + 1;
  v2->timer = v8;
  struct StateT * v6 = slot_1(v2);
  return v6;
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