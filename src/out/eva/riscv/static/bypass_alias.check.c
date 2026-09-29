// verify: clean (Eva should report untainted: Valid) [unroll 65]
#define NUM_REGS 32
#define MEM_SIZE 64
#define SECRET_SIZE 10
#define SECRET_OFFSET 20
#define CACHE_ENTRIES 12
#define CACHE_WORDS 24

#ifdef EVA
#include "__fc_builtin.h"
/*@ requires untainted: !\tainted(b);
    assigns \nothing; */
void koika_check(int b);
/*@ assigns *p \from \nothing;
    taints *p; */
void koika_mark(int *p);
#define koika_assert(b, s) koika_check(b)
#define koika_assume(b) do { if (!(b)) Frama_C_abort(); } while (0)
#define koika_draw(x) ((x) = Frama_C_interval(-2147483647-1, 2147483647))
#define koika_secret(x) koika_mark(&(x))
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
struct StateT * slot_1(struct StateT * v15);
struct StateT * slot_8(struct StateT * v791);
struct StateT * slot_6(struct StateT * v573);
struct StateT * slot_5(struct StateT * v560);
struct StateT * slot_4(struct StateT * v245);
struct StateT * slot_2(struct StateT * v219);
struct StateT * slot_7(struct StateT * v587);
struct StateT * slot_3(struct StateT * v232);
struct StateT * slot_0(struct StateT * v2);
struct StateT * snippet(struct StateT * v0) {
  struct StateT * v1 = slot_0(v0);
  return v1;
}

struct StateT * slot_1(struct StateT * v15) {
  int v16 = v15->timer;
  int v126 = v16 + 1;
  v15->timer = v126;
  int * v18 = v15->regs;
  int v19 = v18[6];
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
  v122[5] = v121;
  struct StateT * v124 = slot_2(v15);
  return v124;
}

struct StateT * slot_8(struct StateT * v791) {
  int v792 = v791->timer;
  int v901 = v792 + 1;
  v791->timer = v901;
  int * v794 = v791->regs;
  int v795 = v794[11];
  int * v796 = v791->cache_tags;
  int v905 = (((int)((unsigned int)((int)((unsigned int)v795 >> 2)) >> 1)) & 1) * 2;
  int v797 = v796[v905];
  int v906 = ((((int)((unsigned int)((int)((unsigned int)v795 >> 2)) >> 1)) & 1) * 2) + 1;
  int v798 = v796[v906];
  int v907 = 4 + ((((int)((unsigned int)((int)((unsigned int)v795 >> 2)) >> 1)) & 3) * 2);
  int v799 = v796[v907];
  int v908 = (4 + ((((int)((unsigned int)((int)((unsigned int)v795 >> 2)) >> 1)) & 3) * 2)) + 1;
  int v800 = v796[v908];
  int v801 = v791->timer;
  int v909 = v801 + ((100 ^ (((~(((v799 ^ ((int)((unsigned int)((int)((unsigned int)v795 >> 2)) >> 1))) | (-(v799 ^ ((int)((unsigned int)((int)((unsigned int)v795 >> 2)) >> 1))))) >> 31)) | (~(((v800 ^ ((int)((unsigned int)((int)((unsigned int)v795 >> 2)) >> 1))) | (-(v800 ^ ((int)((unsigned int)((int)((unsigned int)v795 >> 2)) >> 1))))) >> 31))) & 104)) ^ (((~(((v797 ^ ((int)((unsigned int)((int)((unsigned int)v795 >> 2)) >> 1))) | (-(v797 ^ ((int)((unsigned int)((int)((unsigned int)v795 >> 2)) >> 1))))) >> 31)) | (~(((v798 ^ ((int)((unsigned int)((int)((unsigned int)v795 >> 2)) >> 1))) | (-(v798 ^ ((int)((unsigned int)((int)((unsigned int)v795 >> 2)) >> 1))))) >> 31))) & (1 ^ (100 ^ (((~(((v799 ^ ((int)((unsigned int)((int)((unsigned int)v795 >> 2)) >> 1))) | (-(v799 ^ ((int)((unsigned int)((int)((unsigned int)v795 >> 2)) >> 1))))) >> 31)) | (~(((v800 ^ ((int)((unsigned int)((int)((unsigned int)v795 >> 2)) >> 1))) | (-(v800 ^ ((int)((unsigned int)((int)((unsigned int)v795 >> 2)) >> 1))))) >> 31))) & 104)))));
  v791->timer = v909;
  int * v803 = v791->cache_vals;
  bool v910 = !(((~(((v797 ^ ((int)((unsigned int)((int)((unsigned int)v795 >> 2)) >> 1))) | (-(v797 ^ ((int)((unsigned int)((int)((unsigned int)v795 >> 2)) >> 1))))) >> 31)) | (~(((v798 ^ ((int)((unsigned int)((int)((unsigned int)v795 >> 2)) >> 1))) | (-(v798 ^ ((int)((unsigned int)((int)((unsigned int)v795 >> 2)) >> 1))))) >> 31))) == 0);
  int v896;
  if (v910) {
    int * v804 = v791->cache_age;
    int v912 = ((((int)((unsigned int)((int)((unsigned int)v795 >> 2)) >> 1)) & 1) * 2) + ((~(((v798 ^ ((int)((unsigned int)((int)((unsigned int)v795 >> 2)) >> 1))) | (-(v798 ^ ((int)((unsigned int)((int)((unsigned int)v795 >> 2)) >> 1))))) >> 31)) & 1);
    int v805 = v804[v912];
    int v806 = v804[v905];
    int v913 = v806 + ((int)((unsigned int)(v806 - v805) >> 31));
    v804[v905] = v913;
    int * v808 = v791->cache_age;
    int v809 = v808[v906];
    int v915 = v809 + ((int)((unsigned int)(v809 - v805) >> 31));
    v808[v906] = v915;
    int * v811 = v791->cache_age;
    v811[v912] = 0;
    v896 = v912;
  } else {
    int * v814 = v791->cache_age;
    int v919 = (((int)((unsigned int)((int)((unsigned int)v795 >> 2)) >> 1)) & 1) * 2;
    int v815 = v814[v919];
    int * v816 = v791->cache_tags;
    int v817 = v816[v919];
    int v818 = v814[v906];
    int v819 = v816[v906];
    bool v921 = !(((~(((v799 ^ ((int)((unsigned int)((int)((unsigned int)v795 >> 2)) >> 1))) | (-(v799 ^ ((int)((unsigned int)((int)((unsigned int)v795 >> 2)) >> 1))))) >> 31)) | (~(((v800 ^ ((int)((unsigned int)((int)((unsigned int)v795 >> 2)) >> 1))) | (-(v800 ^ ((int)((unsigned int)((int)((unsigned int)v795 >> 2)) >> 1))))) >> 31))) == 0);
    int v873;
    if (v921) {
      int * v820 = v791->cache_age;
      int v923 = (4 + ((((int)((unsigned int)((int)((unsigned int)v795 >> 2)) >> 1)) & 3) * 2)) + ((~(((v800 ^ ((int)((unsigned int)((int)((unsigned int)v795 >> 2)) >> 1))) | (-(v800 ^ ((int)((unsigned int)((int)((unsigned int)v795 >> 2)) >> 1))))) >> 31)) & 1);
      int v821 = v820[v923];
      int v822 = v820[v907];
      int v924 = v822 + ((int)((unsigned int)(v822 - v821) >> 31));
      v820[v907] = v924;
      int * v824 = v791->cache_age;
      int v825 = v824[v908];
      int v926 = v825 + ((int)((unsigned int)(v825 - v821) >> 31));
      v824[v908] = v926;
      int * v827 = v791->cache_age;
      v827[v923] = 0;
      v873 = v923;
    } else {
      int * v830 = v791->cache_age;
      int v930 = 4 + ((((int)((unsigned int)((int)((unsigned int)v795 >> 2)) >> 1)) & 3) * 2);
      int v831 = v830[v930];
      int * v832 = v791->cache_tags;
      int v833 = v832[v930];
      int v834 = v830[v908];
      int v835 = v832[v908];
      int * v836 = v791->cache_dirty;
      int v933 = (4 + ((((int)((unsigned int)((int)((unsigned int)v795 >> 2)) >> 1)) & 3) * 2)) + ((((v831 + ((~(((v833 ^ -1) | (-(v833 ^ -1))) >> 31)) & 2)) - (v834 + ((~(((v835 ^ -1) | (-(v835 ^ -1))) >> 31)) & 2))) >> 31) & 1);
      int v837 = v836[v933];
      bool v934 = !(v837 == 0);
      if (v934) {
        int * v838 = v791->cache_tags;
        int v839 = v838[v933];
        int * v840 = v791->cache_vals;
        int v937 = ((4 + ((((int)((unsigned int)((int)((unsigned int)v795 >> 2)) >> 1)) & 3) * 2)) + ((((v831 + ((~(((v833 ^ -1) | (-(v833 ^ -1))) >> 31)) & 2)) - (v834 + ((~(((v835 ^ -1) | (-(v835 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
        int v841 = v840[v937];
        int v938 = (((4 + ((((int)((unsigned int)((int)((unsigned int)v795 >> 2)) >> 1)) & 3) * 2)) + ((((v831 + ((~(((v833 ^ -1) | (-(v833 ^ -1))) >> 31)) & 2)) - (v834 + ((~(((v835 ^ -1) | (-(v835 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
        int v842 = v840[v938];
        int * v843 = v791->mem;
        int v940 = v839 * 2;
        v843[v940] = v841;
        int * v845 = v791->mem;
        int v943 = (v839 * 2) + 1;
        v845[v943] = v842;
        ;
      } else {
        ;
      }
      int * v850 = v791->mem;
      int v948 = ((int)((unsigned int)((int)((unsigned int)v795 >> 2)) >> 1)) * 2;
      int v851 = v850[v948];
      int v949 = (((int)((unsigned int)((int)((unsigned int)v795 >> 2)) >> 1)) * 2) + 1;
      int v852 = v850[v949];
      int * v853 = v791->cache_vals;
      int v951 = ((4 + ((((int)((unsigned int)((int)((unsigned int)v795 >> 2)) >> 1)) & 3) * 2)) + ((((v831 + ((~(((v833 ^ -1) | (-(v833 ^ -1))) >> 31)) & 2)) - (v834 + ((~(((v835 ^ -1) | (-(v835 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
      v853[v951] = v851;
      int * v855 = v791->cache_vals;
      int v954 = (((4 + ((((int)((unsigned int)((int)((unsigned int)v795 >> 2)) >> 1)) & 3) * 2)) + ((((v831 + ((~(((v833 ^ -1) | (-(v833 ^ -1))) >> 31)) & 2)) - (v834 + ((~(((v835 ^ -1) | (-(v835 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
      v855[v954] = v852;
      int * v857 = v791->cache_tags;
      int v957 = (int)((unsigned int)((int)((unsigned int)v795 >> 2)) >> 1);
      v857[v933] = v957;
      int * v859 = v791->cache_dirty;
      v859[v933] = 0;
      int * v861 = v791->cache_age;
      v861[v933] = 1;
      int * v863 = v791->cache_age;
      int v864 = v863[v933];
      int v865 = v863[v907];
      int v963 = v865 + ((int)((unsigned int)(v865 - v864) >> 31));
      v863[v907] = v963;
      int * v867 = v791->cache_age;
      int v868 = v867[v908];
      int v965 = v868 + ((int)((unsigned int)(v868 - v864) >> 31));
      v867[v908] = v965;
      int * v870 = v791->cache_age;
      v870[v933] = 0;
      v873 = v933;
    }
    int * v874 = v791->cache_vals;
    int v968 = v873 * 2;
    int v875 = v874[v968];
    int v969 = (v873 * 2) + 1;
    int v876 = v874[v969];
    int v970 = (((((int)((unsigned int)((int)((unsigned int)v795 >> 2)) >> 1)) & 1) * 2) + ((((v815 + ((~(((v817 ^ -1) | (-(v817 ^ -1))) >> 31)) & 2)) - (v818 + ((~(((v819 ^ -1) | (-(v819 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
    v874[v970] = v875;
    int * v878 = v791->cache_vals;
    int v973 = ((((((int)((unsigned int)((int)((unsigned int)v795 >> 2)) >> 1)) & 1) * 2) + ((((v815 + ((~(((v817 ^ -1) | (-(v817 ^ -1))) >> 31)) & 2)) - (v818 + ((~(((v819 ^ -1) | (-(v819 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
    v878[v973] = v876;
    int * v880 = v791->cache_tags;
    int v976 = ((((int)((unsigned int)((int)((unsigned int)v795 >> 2)) >> 1)) & 1) * 2) + ((((v815 + ((~(((v817 ^ -1) | (-(v817 ^ -1))) >> 31)) & 2)) - (v818 + ((~(((v819 ^ -1) | (-(v819 ^ -1))) >> 31)) & 2))) >> 31) & 1);
    int v977 = (int)((unsigned int)((int)((unsigned int)v795 >> 2)) >> 1);
    v880[v976] = v977;
    int * v882 = v791->cache_dirty;
    v882[v976] = 0;
    int * v884 = v791->cache_age;
    v884[v976] = 1;
    int * v886 = v791->cache_age;
    int v887 = v886[v976];
    int v888 = v886[v905];
    int v983 = v888 + ((int)((unsigned int)(v888 - v887) >> 31));
    v886[v905] = v983;
    int * v890 = v791->cache_age;
    int v891 = v890[v906];
    int v985 = v891 + ((int)((unsigned int)(v891 - v887) >> 31));
    v890[v906] = v985;
    int * v893 = v791->cache_age;
    v893[v976] = 0;
    v896 = v976;
  }
  int v988 = (v896 * 2) + (((int)((unsigned int)v795 >> 2)) & 1);
  int v897 = v803[v988];
  int * v898 = v791->regs;
  v898[12] = v897;
  return v791;
}

struct StateT * slot_6(struct StateT * v573) {
  int v574 = v573->timer;
  int v581 = v574 + 1;
  v573->timer = v581;
  int * v576 = v573->regs;
  int v577 = v576[7];
  int v584 = v577 + 1;
  v576[7] = v584;
  struct StateT * v579 = slot_7(v573);
  return v579;
}

struct StateT * slot_5(struct StateT * v560) {
  int v561 = v560->timer;
  int v567 = v561 + 1;
  v560->timer = v567;
  int * v563 = v560->regs;
  v563[7] = 0;
  struct StateT * v565 = slot_6(v560);
  return v565;
}

struct StateT * slot_4(struct StateT * v245) {
  int v246 = v245->timer;
  int v416 = v246 + 1;
  v245->timer = v416;
  int * v248 = v245->regs;
  int v249 = v248[8];
  int v250 = v248[5];
  int * v251 = v245->cache_tags;
  int v421 = (((int)((unsigned int)((int)((unsigned int)v249 >> 2)) >> 1)) & 1) * 2;
  int v252 = v251[v421];
  int v422 = ((((int)((unsigned int)((int)((unsigned int)v249 >> 2)) >> 1)) & 1) * 2) + 1;
  int v253 = v251[v422];
  int v423 = 4 + ((((int)((unsigned int)((int)((unsigned int)v249 >> 2)) >> 1)) & 3) * 2);
  int v254 = v251[v423];
  int v424 = (4 + ((((int)((unsigned int)((int)((unsigned int)v249 >> 2)) >> 1)) & 3) * 2)) + 1;
  int v255 = v251[v424];
  int v256 = v245->timer;
  int v425 = v256 + ((100 ^ (((~(((v254 ^ ((int)((unsigned int)((int)((unsigned int)v249 >> 2)) >> 1))) | (-(v254 ^ ((int)((unsigned int)((int)((unsigned int)v249 >> 2)) >> 1))))) >> 31)) | (~(((v255 ^ ((int)((unsigned int)((int)((unsigned int)v249 >> 2)) >> 1))) | (-(v255 ^ ((int)((unsigned int)((int)((unsigned int)v249 >> 2)) >> 1))))) >> 31))) & 104)) ^ (((~(((v252 ^ ((int)((unsigned int)((int)((unsigned int)v249 >> 2)) >> 1))) | (-(v252 ^ ((int)((unsigned int)((int)((unsigned int)v249 >> 2)) >> 1))))) >> 31)) | (~(((v253 ^ ((int)((unsigned int)((int)((unsigned int)v249 >> 2)) >> 1))) | (-(v253 ^ ((int)((unsigned int)((int)((unsigned int)v249 >> 2)) >> 1))))) >> 31))) & (1 ^ (100 ^ (((~(((v254 ^ ((int)((unsigned int)((int)((unsigned int)v249 >> 2)) >> 1))) | (-(v254 ^ ((int)((unsigned int)((int)((unsigned int)v249 >> 2)) >> 1))))) >> 31)) | (~(((v255 ^ ((int)((unsigned int)((int)((unsigned int)v249 >> 2)) >> 1))) | (-(v255 ^ ((int)((unsigned int)((int)((unsigned int)v249 >> 2)) >> 1))))) >> 31))) & 104)))));
  v245->timer = v425;
  bool v426 = !(((~(((v252 ^ ((int)((unsigned int)((int)((unsigned int)v249 >> 2)) >> 1))) | (-(v252 ^ ((int)((unsigned int)((int)((unsigned int)v249 >> 2)) >> 1))))) >> 31)) | (~(((v253 ^ ((int)((unsigned int)((int)((unsigned int)v249 >> 2)) >> 1))) | (-(v253 ^ ((int)((unsigned int)((int)((unsigned int)v249 >> 2)) >> 1))))) >> 31))) == 0);
  int v350;
  if (v426) {
    int * v258 = v245->cache_age;
    int v428 = ((((int)((unsigned int)((int)((unsigned int)v249 >> 2)) >> 1)) & 1) * 2) + ((~(((v253 ^ ((int)((unsigned int)((int)((unsigned int)v249 >> 2)) >> 1))) | (-(v253 ^ ((int)((unsigned int)((int)((unsigned int)v249 >> 2)) >> 1))))) >> 31)) & 1);
    int v259 = v258[v428];
    int v260 = v258[v421];
    int v429 = v260 + ((int)((unsigned int)(v260 - v259) >> 31));
    v258[v421] = v429;
    int * v262 = v245->cache_age;
    int v263 = v262[v422];
    int v431 = v263 + ((int)((unsigned int)(v263 - v259) >> 31));
    v262[v422] = v431;
    int * v265 = v245->cache_age;
    v265[v428] = 0;
    v350 = v428;
  } else {
    int * v268 = v245->cache_age;
    int v435 = (((int)((unsigned int)((int)((unsigned int)v249 >> 2)) >> 1)) & 1) * 2;
    int v269 = v268[v435];
    int * v270 = v245->cache_tags;
    int v271 = v270[v435];
    int v272 = v268[v422];
    int v273 = v270[v422];
    bool v437 = !(((~(((v254 ^ ((int)((unsigned int)((int)((unsigned int)v249 >> 2)) >> 1))) | (-(v254 ^ ((int)((unsigned int)((int)((unsigned int)v249 >> 2)) >> 1))))) >> 31)) | (~(((v255 ^ ((int)((unsigned int)((int)((unsigned int)v249 >> 2)) >> 1))) | (-(v255 ^ ((int)((unsigned int)((int)((unsigned int)v249 >> 2)) >> 1))))) >> 31))) == 0);
    int v327;
    if (v437) {
      int * v274 = v245->cache_age;
      int v439 = (4 + ((((int)((unsigned int)((int)((unsigned int)v249 >> 2)) >> 1)) & 3) * 2)) + ((~(((v255 ^ ((int)((unsigned int)((int)((unsigned int)v249 >> 2)) >> 1))) | (-(v255 ^ ((int)((unsigned int)((int)((unsigned int)v249 >> 2)) >> 1))))) >> 31)) & 1);
      int v275 = v274[v439];
      int v276 = v274[v423];
      int v440 = v276 + ((int)((unsigned int)(v276 - v275) >> 31));
      v274[v423] = v440;
      int * v278 = v245->cache_age;
      int v279 = v278[v424];
      int v442 = v279 + ((int)((unsigned int)(v279 - v275) >> 31));
      v278[v424] = v442;
      int * v281 = v245->cache_age;
      v281[v439] = 0;
      v327 = v439;
    } else {
      int * v284 = v245->cache_age;
      int v446 = 4 + ((((int)((unsigned int)((int)((unsigned int)v249 >> 2)) >> 1)) & 3) * 2);
      int v285 = v284[v446];
      int * v286 = v245->cache_tags;
      int v287 = v286[v446];
      int v288 = v284[v424];
      int v289 = v286[v424];
      int * v290 = v245->cache_dirty;
      int v449 = (4 + ((((int)((unsigned int)((int)((unsigned int)v249 >> 2)) >> 1)) & 3) * 2)) + ((((v285 + ((~(((v287 ^ -1) | (-(v287 ^ -1))) >> 31)) & 2)) - (v288 + ((~(((v289 ^ -1) | (-(v289 ^ -1))) >> 31)) & 2))) >> 31) & 1);
      int v291 = v290[v449];
      bool v450 = !(v291 == 0);
      if (v450) {
        int * v292 = v245->cache_tags;
        int v293 = v292[v449];
        int * v294 = v245->cache_vals;
        int v453 = ((4 + ((((int)((unsigned int)((int)((unsigned int)v249 >> 2)) >> 1)) & 3) * 2)) + ((((v285 + ((~(((v287 ^ -1) | (-(v287 ^ -1))) >> 31)) & 2)) - (v288 + ((~(((v289 ^ -1) | (-(v289 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
        int v295 = v294[v453];
        int v454 = (((4 + ((((int)((unsigned int)((int)((unsigned int)v249 >> 2)) >> 1)) & 3) * 2)) + ((((v285 + ((~(((v287 ^ -1) | (-(v287 ^ -1))) >> 31)) & 2)) - (v288 + ((~(((v289 ^ -1) | (-(v289 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
        int v296 = v294[v454];
        int * v297 = v245->mem;
        int v456 = v293 * 2;
        v297[v456] = v295;
        int * v299 = v245->mem;
        int v459 = (v293 * 2) + 1;
        v299[v459] = v296;
        ;
      } else {
        ;
      }
      int * v304 = v245->mem;
      int v464 = ((int)((unsigned int)((int)((unsigned int)v249 >> 2)) >> 1)) * 2;
      int v305 = v304[v464];
      int v465 = (((int)((unsigned int)((int)((unsigned int)v249 >> 2)) >> 1)) * 2) + 1;
      int v306 = v304[v465];
      int * v307 = v245->cache_vals;
      int v467 = ((4 + ((((int)((unsigned int)((int)((unsigned int)v249 >> 2)) >> 1)) & 3) * 2)) + ((((v285 + ((~(((v287 ^ -1) | (-(v287 ^ -1))) >> 31)) & 2)) - (v288 + ((~(((v289 ^ -1) | (-(v289 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
      v307[v467] = v305;
      int * v309 = v245->cache_vals;
      int v470 = (((4 + ((((int)((unsigned int)((int)((unsigned int)v249 >> 2)) >> 1)) & 3) * 2)) + ((((v285 + ((~(((v287 ^ -1) | (-(v287 ^ -1))) >> 31)) & 2)) - (v288 + ((~(((v289 ^ -1) | (-(v289 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
      v309[v470] = v306;
      int * v311 = v245->cache_tags;
      int v473 = (int)((unsigned int)((int)((unsigned int)v249 >> 2)) >> 1);
      v311[v449] = v473;
      int * v313 = v245->cache_dirty;
      v313[v449] = 0;
      int * v315 = v245->cache_age;
      v315[v449] = 1;
      int * v317 = v245->cache_age;
      int v318 = v317[v449];
      int v319 = v317[v423];
      int v479 = v319 + ((int)((unsigned int)(v319 - v318) >> 31));
      v317[v423] = v479;
      int * v321 = v245->cache_age;
      int v322 = v321[v424];
      int v481 = v322 + ((int)((unsigned int)(v322 - v318) >> 31));
      v321[v424] = v481;
      int * v324 = v245->cache_age;
      v324[v449] = 0;
      v327 = v449;
    }
    int * v328 = v245->cache_vals;
    int v484 = v327 * 2;
    int v329 = v328[v484];
    int v485 = (v327 * 2) + 1;
    int v330 = v328[v485];
    int v486 = (((((int)((unsigned int)((int)((unsigned int)v249 >> 2)) >> 1)) & 1) * 2) + ((((v269 + ((~(((v271 ^ -1) | (-(v271 ^ -1))) >> 31)) & 2)) - (v272 + ((~(((v273 ^ -1) | (-(v273 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
    v328[v486] = v329;
    int * v332 = v245->cache_vals;
    int v489 = ((((((int)((unsigned int)((int)((unsigned int)v249 >> 2)) >> 1)) & 1) * 2) + ((((v269 + ((~(((v271 ^ -1) | (-(v271 ^ -1))) >> 31)) & 2)) - (v272 + ((~(((v273 ^ -1) | (-(v273 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
    v332[v489] = v330;
    int * v334 = v245->cache_tags;
    int v492 = ((((int)((unsigned int)((int)((unsigned int)v249 >> 2)) >> 1)) & 1) * 2) + ((((v269 + ((~(((v271 ^ -1) | (-(v271 ^ -1))) >> 31)) & 2)) - (v272 + ((~(((v273 ^ -1) | (-(v273 ^ -1))) >> 31)) & 2))) >> 31) & 1);
    int v493 = (int)((unsigned int)((int)((unsigned int)v249 >> 2)) >> 1);
    v334[v492] = v493;
    int * v336 = v245->cache_dirty;
    v336[v492] = 0;
    int * v338 = v245->cache_age;
    v338[v492] = 1;
    int * v340 = v245->cache_age;
    int v341 = v340[v492];
    int v342 = v340[v421];
    int v499 = v342 + ((int)((unsigned int)(v342 - v341) >> 31));
    v340[v421] = v499;
    int * v344 = v245->cache_age;
    int v345 = v344[v422];
    int v501 = v345 + ((int)((unsigned int)(v345 - v341) >> 31));
    v344[v422] = v501;
    int * v347 = v245->cache_age;
    v347[v492] = 0;
    v350 = v492;
  }
  int * v351 = v245->cache_vals;
  int v504 = (v350 * 2) + (((int)((unsigned int)v249 >> 2)) & 1);
  v351[v504] = v250;
  int * v353 = v245->cache_tags;
  int v354 = v353[v423];
  int v355 = v353[v424];
  bool v507 = !(((~(((v354 ^ ((int)((unsigned int)((int)((unsigned int)v249 >> 2)) >> 1))) | (-(v354 ^ ((int)((unsigned int)((int)((unsigned int)v249 >> 2)) >> 1))))) >> 31)) | (~(((v355 ^ ((int)((unsigned int)((int)((unsigned int)v249 >> 2)) >> 1))) | (-(v355 ^ ((int)((unsigned int)((int)((unsigned int)v249 >> 2)) >> 1))))) >> 31))) == 0);
  int v409;
  if (v507) {
    int * v356 = v245->cache_age;
    int v509 = (4 + ((((int)((unsigned int)((int)((unsigned int)v249 >> 2)) >> 1)) & 3) * 2)) + ((~(((v355 ^ ((int)((unsigned int)((int)((unsigned int)v249 >> 2)) >> 1))) | (-(v355 ^ ((int)((unsigned int)((int)((unsigned int)v249 >> 2)) >> 1))))) >> 31)) & 1);
    int v357 = v356[v509];
    int v358 = v356[v423];
    int v510 = v358 + ((int)((unsigned int)(v358 - v357) >> 31));
    v356[v423] = v510;
    int * v360 = v245->cache_age;
    int v361 = v360[v424];
    int v512 = v361 + ((int)((unsigned int)(v361 - v357) >> 31));
    v360[v424] = v512;
    int * v363 = v245->cache_age;
    v363[v509] = 0;
    v409 = v509;
  } else {
    int * v366 = v245->cache_age;
    int v516 = 4 + ((((int)((unsigned int)((int)((unsigned int)v249 >> 2)) >> 1)) & 3) * 2);
    int v367 = v366[v516];
    int * v368 = v245->cache_tags;
    int v369 = v368[v516];
    int v370 = v366[v424];
    int v371 = v368[v424];
    int * v372 = v245->cache_dirty;
    int v519 = (4 + ((((int)((unsigned int)((int)((unsigned int)v249 >> 2)) >> 1)) & 3) * 2)) + ((((v367 + ((~(((v369 ^ -1) | (-(v369 ^ -1))) >> 31)) & 2)) - (v370 + ((~(((v371 ^ -1) | (-(v371 ^ -1))) >> 31)) & 2))) >> 31) & 1);
    int v373 = v372[v519];
    bool v520 = !(v373 == 0);
    if (v520) {
      int * v374 = v245->cache_tags;
      int v375 = v374[v519];
      int * v376 = v245->cache_vals;
      int v523 = ((4 + ((((int)((unsigned int)((int)((unsigned int)v249 >> 2)) >> 1)) & 3) * 2)) + ((((v367 + ((~(((v369 ^ -1) | (-(v369 ^ -1))) >> 31)) & 2)) - (v370 + ((~(((v371 ^ -1) | (-(v371 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
      int v377 = v376[v523];
      int v524 = (((4 + ((((int)((unsigned int)((int)((unsigned int)v249 >> 2)) >> 1)) & 3) * 2)) + ((((v367 + ((~(((v369 ^ -1) | (-(v369 ^ -1))) >> 31)) & 2)) - (v370 + ((~(((v371 ^ -1) | (-(v371 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
      int v378 = v376[v524];
      int * v379 = v245->mem;
      int v526 = v375 * 2;
      v379[v526] = v377;
      int * v381 = v245->mem;
      int v529 = (v375 * 2) + 1;
      v381[v529] = v378;
      ;
    } else {
      ;
    }
    int * v386 = v245->mem;
    int v534 = ((int)((unsigned int)((int)((unsigned int)v249 >> 2)) >> 1)) * 2;
    int v387 = v386[v534];
    int v535 = (((int)((unsigned int)((int)((unsigned int)v249 >> 2)) >> 1)) * 2) + 1;
    int v388 = v386[v535];
    int * v389 = v245->cache_vals;
    int v537 = ((4 + ((((int)((unsigned int)((int)((unsigned int)v249 >> 2)) >> 1)) & 3) * 2)) + ((((v367 + ((~(((v369 ^ -1) | (-(v369 ^ -1))) >> 31)) & 2)) - (v370 + ((~(((v371 ^ -1) | (-(v371 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
    v389[v537] = v387;
    int * v391 = v245->cache_vals;
    int v540 = (((4 + ((((int)((unsigned int)((int)((unsigned int)v249 >> 2)) >> 1)) & 3) * 2)) + ((((v367 + ((~(((v369 ^ -1) | (-(v369 ^ -1))) >> 31)) & 2)) - (v370 + ((~(((v371 ^ -1) | (-(v371 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
    v391[v540] = v388;
    int * v393 = v245->cache_tags;
    int v543 = (int)((unsigned int)((int)((unsigned int)v249 >> 2)) >> 1);
    v393[v519] = v543;
    int * v395 = v245->cache_dirty;
    v395[v519] = 0;
    int * v397 = v245->cache_age;
    v397[v519] = 1;
    int * v399 = v245->cache_age;
    int v400 = v399[v519];
    int v401 = v399[v423];
    int v549 = v401 + ((int)((unsigned int)(v401 - v400) >> 31));
    v399[v423] = v549;
    int * v403 = v245->cache_age;
    int v404 = v403[v424];
    int v551 = v404 + ((int)((unsigned int)(v404 - v400) >> 31));
    v403[v424] = v551;
    int * v406 = v245->cache_age;
    v406[v519] = 0;
    v409 = v519;
  }
  int * v410 = v245->cache_vals;
  int v554 = (v409 * 2) + (((int)((unsigned int)v249 >> 2)) & 1);
  v410[v554] = v250;
  int * v412 = v245->cache_dirty;
  v412[v409] = 1;
  struct StateT * v414 = slot_5(v245);
  return v414;
}

struct StateT * slot_2(struct StateT * v219) {
  int v220 = v219->timer;
  int v226 = v220 + 1;
  v219->timer = v226;
  int * v222 = v219->regs;
  v222[8] = 96;
  struct StateT * v224 = slot_3(v219);
  return v224;
}

struct StateT * slot_7(struct StateT * v587) {
  int v588 = v587->timer;
  int v698 = v588 + 1;
  v587->timer = v698;
  int * v590 = v587->regs;
  int v591 = v590[9];
  int * v592 = v587->cache_tags;
  int v702 = (((int)((unsigned int)((int)((unsigned int)v591 >> 2)) >> 1)) & 1) * 2;
  int v593 = v592[v702];
  int v703 = ((((int)((unsigned int)((int)((unsigned int)v591 >> 2)) >> 1)) & 1) * 2) + 1;
  int v594 = v592[v703];
  int v704 = 4 + ((((int)((unsigned int)((int)((unsigned int)v591 >> 2)) >> 1)) & 3) * 2);
  int v595 = v592[v704];
  int v705 = (4 + ((((int)((unsigned int)((int)((unsigned int)v591 >> 2)) >> 1)) & 3) * 2)) + 1;
  int v596 = v592[v705];
  int v597 = v587->timer;
  int v706 = v597 + ((100 ^ (((~(((v595 ^ ((int)((unsigned int)((int)((unsigned int)v591 >> 2)) >> 1))) | (-(v595 ^ ((int)((unsigned int)((int)((unsigned int)v591 >> 2)) >> 1))))) >> 31)) | (~(((v596 ^ ((int)((unsigned int)((int)((unsigned int)v591 >> 2)) >> 1))) | (-(v596 ^ ((int)((unsigned int)((int)((unsigned int)v591 >> 2)) >> 1))))) >> 31))) & 104)) ^ (((~(((v593 ^ ((int)((unsigned int)((int)((unsigned int)v591 >> 2)) >> 1))) | (-(v593 ^ ((int)((unsigned int)((int)((unsigned int)v591 >> 2)) >> 1))))) >> 31)) | (~(((v594 ^ ((int)((unsigned int)((int)((unsigned int)v591 >> 2)) >> 1))) | (-(v594 ^ ((int)((unsigned int)((int)((unsigned int)v591 >> 2)) >> 1))))) >> 31))) & (1 ^ (100 ^ (((~(((v595 ^ ((int)((unsigned int)((int)((unsigned int)v591 >> 2)) >> 1))) | (-(v595 ^ ((int)((unsigned int)((int)((unsigned int)v591 >> 2)) >> 1))))) >> 31)) | (~(((v596 ^ ((int)((unsigned int)((int)((unsigned int)v591 >> 2)) >> 1))) | (-(v596 ^ ((int)((unsigned int)((int)((unsigned int)v591 >> 2)) >> 1))))) >> 31))) & 104)))));
  v587->timer = v706;
  int * v599 = v587->cache_vals;
  bool v707 = !(((~(((v593 ^ ((int)((unsigned int)((int)((unsigned int)v591 >> 2)) >> 1))) | (-(v593 ^ ((int)((unsigned int)((int)((unsigned int)v591 >> 2)) >> 1))))) >> 31)) | (~(((v594 ^ ((int)((unsigned int)((int)((unsigned int)v591 >> 2)) >> 1))) | (-(v594 ^ ((int)((unsigned int)((int)((unsigned int)v591 >> 2)) >> 1))))) >> 31))) == 0);
  int v692;
  if (v707) {
    int * v600 = v587->cache_age;
    int v709 = ((((int)((unsigned int)((int)((unsigned int)v591 >> 2)) >> 1)) & 1) * 2) + ((~(((v594 ^ ((int)((unsigned int)((int)((unsigned int)v591 >> 2)) >> 1))) | (-(v594 ^ ((int)((unsigned int)((int)((unsigned int)v591 >> 2)) >> 1))))) >> 31)) & 1);
    int v601 = v600[v709];
    int v602 = v600[v702];
    int v710 = v602 + ((int)((unsigned int)(v602 - v601) >> 31));
    v600[v702] = v710;
    int * v604 = v587->cache_age;
    int v605 = v604[v703];
    int v712 = v605 + ((int)((unsigned int)(v605 - v601) >> 31));
    v604[v703] = v712;
    int * v607 = v587->cache_age;
    v607[v709] = 0;
    v692 = v709;
  } else {
    int * v610 = v587->cache_age;
    int v716 = (((int)((unsigned int)((int)((unsigned int)v591 >> 2)) >> 1)) & 1) * 2;
    int v611 = v610[v716];
    int * v612 = v587->cache_tags;
    int v613 = v612[v716];
    int v614 = v610[v703];
    int v615 = v612[v703];
    bool v718 = !(((~(((v595 ^ ((int)((unsigned int)((int)((unsigned int)v591 >> 2)) >> 1))) | (-(v595 ^ ((int)((unsigned int)((int)((unsigned int)v591 >> 2)) >> 1))))) >> 31)) | (~(((v596 ^ ((int)((unsigned int)((int)((unsigned int)v591 >> 2)) >> 1))) | (-(v596 ^ ((int)((unsigned int)((int)((unsigned int)v591 >> 2)) >> 1))))) >> 31))) == 0);
    int v669;
    if (v718) {
      int * v616 = v587->cache_age;
      int v720 = (4 + ((((int)((unsigned int)((int)((unsigned int)v591 >> 2)) >> 1)) & 3) * 2)) + ((~(((v596 ^ ((int)((unsigned int)((int)((unsigned int)v591 >> 2)) >> 1))) | (-(v596 ^ ((int)((unsigned int)((int)((unsigned int)v591 >> 2)) >> 1))))) >> 31)) & 1);
      int v617 = v616[v720];
      int v618 = v616[v704];
      int v721 = v618 + ((int)((unsigned int)(v618 - v617) >> 31));
      v616[v704] = v721;
      int * v620 = v587->cache_age;
      int v621 = v620[v705];
      int v723 = v621 + ((int)((unsigned int)(v621 - v617) >> 31));
      v620[v705] = v723;
      int * v623 = v587->cache_age;
      v623[v720] = 0;
      v669 = v720;
    } else {
      int * v626 = v587->cache_age;
      int v727 = 4 + ((((int)((unsigned int)((int)((unsigned int)v591 >> 2)) >> 1)) & 3) * 2);
      int v627 = v626[v727];
      int * v628 = v587->cache_tags;
      int v629 = v628[v727];
      int v630 = v626[v705];
      int v631 = v628[v705];
      int * v632 = v587->cache_dirty;
      int v730 = (4 + ((((int)((unsigned int)((int)((unsigned int)v591 >> 2)) >> 1)) & 3) * 2)) + ((((v627 + ((~(((v629 ^ -1) | (-(v629 ^ -1))) >> 31)) & 2)) - (v630 + ((~(((v631 ^ -1) | (-(v631 ^ -1))) >> 31)) & 2))) >> 31) & 1);
      int v633 = v632[v730];
      bool v731 = !(v633 == 0);
      if (v731) {
        int * v634 = v587->cache_tags;
        int v635 = v634[v730];
        int * v636 = v587->cache_vals;
        int v734 = ((4 + ((((int)((unsigned int)((int)((unsigned int)v591 >> 2)) >> 1)) & 3) * 2)) + ((((v627 + ((~(((v629 ^ -1) | (-(v629 ^ -1))) >> 31)) & 2)) - (v630 + ((~(((v631 ^ -1) | (-(v631 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
        int v637 = v636[v734];
        int v735 = (((4 + ((((int)((unsigned int)((int)((unsigned int)v591 >> 2)) >> 1)) & 3) * 2)) + ((((v627 + ((~(((v629 ^ -1) | (-(v629 ^ -1))) >> 31)) & 2)) - (v630 + ((~(((v631 ^ -1) | (-(v631 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
        int v638 = v636[v735];
        int * v639 = v587->mem;
        int v737 = v635 * 2;
        v639[v737] = v637;
        int * v641 = v587->mem;
        int v740 = (v635 * 2) + 1;
        v641[v740] = v638;
        ;
      } else {
        ;
      }
      int * v646 = v587->mem;
      int v745 = ((int)((unsigned int)((int)((unsigned int)v591 >> 2)) >> 1)) * 2;
      int v647 = v646[v745];
      int v746 = (((int)((unsigned int)((int)((unsigned int)v591 >> 2)) >> 1)) * 2) + 1;
      int v648 = v646[v746];
      int * v649 = v587->cache_vals;
      int v748 = ((4 + ((((int)((unsigned int)((int)((unsigned int)v591 >> 2)) >> 1)) & 3) * 2)) + ((((v627 + ((~(((v629 ^ -1) | (-(v629 ^ -1))) >> 31)) & 2)) - (v630 + ((~(((v631 ^ -1) | (-(v631 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
      v649[v748] = v647;
      int * v651 = v587->cache_vals;
      int v751 = (((4 + ((((int)((unsigned int)((int)((unsigned int)v591 >> 2)) >> 1)) & 3) * 2)) + ((((v627 + ((~(((v629 ^ -1) | (-(v629 ^ -1))) >> 31)) & 2)) - (v630 + ((~(((v631 ^ -1) | (-(v631 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
      v651[v751] = v648;
      int * v653 = v587->cache_tags;
      int v754 = (int)((unsigned int)((int)((unsigned int)v591 >> 2)) >> 1);
      v653[v730] = v754;
      int * v655 = v587->cache_dirty;
      v655[v730] = 0;
      int * v657 = v587->cache_age;
      v657[v730] = 1;
      int * v659 = v587->cache_age;
      int v660 = v659[v730];
      int v661 = v659[v704];
      int v760 = v661 + ((int)((unsigned int)(v661 - v660) >> 31));
      v659[v704] = v760;
      int * v663 = v587->cache_age;
      int v664 = v663[v705];
      int v762 = v664 + ((int)((unsigned int)(v664 - v660) >> 31));
      v663[v705] = v762;
      int * v666 = v587->cache_age;
      v666[v730] = 0;
      v669 = v730;
    }
    int * v670 = v587->cache_vals;
    int v765 = v669 * 2;
    int v671 = v670[v765];
    int v766 = (v669 * 2) + 1;
    int v672 = v670[v766];
    int v767 = (((((int)((unsigned int)((int)((unsigned int)v591 >> 2)) >> 1)) & 1) * 2) + ((((v611 + ((~(((v613 ^ -1) | (-(v613 ^ -1))) >> 31)) & 2)) - (v614 + ((~(((v615 ^ -1) | (-(v615 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
    v670[v767] = v671;
    int * v674 = v587->cache_vals;
    int v770 = ((((((int)((unsigned int)((int)((unsigned int)v591 >> 2)) >> 1)) & 1) * 2) + ((((v611 + ((~(((v613 ^ -1) | (-(v613 ^ -1))) >> 31)) & 2)) - (v614 + ((~(((v615 ^ -1) | (-(v615 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
    v674[v770] = v672;
    int * v676 = v587->cache_tags;
    int v773 = ((((int)((unsigned int)((int)((unsigned int)v591 >> 2)) >> 1)) & 1) * 2) + ((((v611 + ((~(((v613 ^ -1) | (-(v613 ^ -1))) >> 31)) & 2)) - (v614 + ((~(((v615 ^ -1) | (-(v615 ^ -1))) >> 31)) & 2))) >> 31) & 1);
    int v774 = (int)((unsigned int)((int)((unsigned int)v591 >> 2)) >> 1);
    v676[v773] = v774;
    int * v678 = v587->cache_dirty;
    v678[v773] = 0;
    int * v680 = v587->cache_age;
    v680[v773] = 1;
    int * v682 = v587->cache_age;
    int v683 = v682[v773];
    int v684 = v682[v702];
    int v780 = v684 + ((int)((unsigned int)(v684 - v683) >> 31));
    v682[v702] = v780;
    int * v686 = v587->cache_age;
    int v687 = v686[v703];
    int v782 = v687 + ((int)((unsigned int)(v687 - v683) >> 31));
    v686[v703] = v782;
    int * v689 = v587->cache_age;
    v689[v773] = 0;
    v692 = v773;
  }
  int v785 = (v692 * 2) + (((int)((unsigned int)v591 >> 2)) & 1);
  int v693 = v599[v785];
  int * v694 = v587->regs;
  v694[11] = v693;
  struct StateT * v696 = slot_8(v587);
  return v696;
}

struct StateT * slot_3(struct StateT * v232) {
  int v233 = v232->timer;
  int v239 = v233 + 1;
  v232->timer = v239;
  int * v235 = v232->regs;
  v235[9] = 0;
  struct StateT * v237 = slot_4(v232);
  return v237;
}

struct StateT * slot_0(struct StateT * v2) {
  int v3 = v2->timer;
  int v9 = v3 + 1;
  v2->timer = v9;
  int * v5 = v2->regs;
  v5[6] = 80;
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
    s1.mem[SECRET_OFFSET+i] = secret(0, 20);
    s2.mem[SECRET_OFFSET+i] = secret(0, 20);
  }
  struct StateT *s1_ = snippet(&s1);
  struct StateT *s2_ = snippet(&s2);
  koika_assert(s1_->timer==s2_->timer, "timing leak");
  return 0;
}