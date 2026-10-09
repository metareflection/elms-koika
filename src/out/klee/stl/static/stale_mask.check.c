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

struct StateT * snippet(struct StateT * v0);
struct StateT * slot_1(struct StateT * v15);
struct StateT * slot_6(struct StateT * v836);
struct StateT * slot_5(struct StateT * v819);
struct StateT * slot_4(struct StateT * v628);
struct StateT * slot_2(struct StateT * v315);
struct StateT * slot_7(struct StateT * v1040);
struct StateT * slot_3(struct StateT * v328);
struct StateT * slot_0(struct StateT * v2);
struct StateT * snippet(struct StateT * v0) {
  struct StateT * v1 = slot_0(v0);
  return v1;
}

struct StateT * slot_1(struct StateT * v15) {
  int v16 = v15->timer;
  int v185 = v16 + 1;
  v15->timer = v185;
  int * v18 = v15->regs;
  int v19 = v18[5];
  int * v20 = v15->cache_tags;
  int v21 = v20[0];
  int v22 = v20[1];
  int v23 = v20[8];
  int v24 = v20[9];
  int v25 = v15->timer;
  int v193 = v25 + ((100 ^ (((~(((v23 ^ 6) | (-(v23 ^ 6))) >> 31)) | (~(((v24 ^ 6) | (-(v24 ^ 6))) >> 31))) & 104)) ^ (((~(((v21 ^ 6) | (-(v21 ^ 6))) >> 31)) | (~(((v22 ^ 6) | (-(v22 ^ 6))) >> 31))) & (1 ^ (100 ^ (((~(((v23 ^ 6) | (-(v23 ^ 6))) >> 31)) | (~(((v24 ^ 6) | (-(v24 ^ 6))) >> 31))) & 104)))));
  v15->timer = v193;
  bool v194 = !(((~(((v21 ^ 6) | (-(v21 ^ 6))) >> 31)) | (~(((v22 ^ 6) | (-(v22 ^ 6))) >> 31))) == 0);
  int v119;
  if (v194) {
    int * v27 = v15->cache_age;
    int v196 = (~(((v22 ^ 6) | (-(v22 ^ 6))) >> 31)) & 1;
    int v28 = v27[v196];
    int v29 = v27[0];
    int v197 = v29 + ((int)((unsigned int)(v29 - v28) >> 31));
    v27[0] = v197;
    int * v31 = v15->cache_age;
    int v32 = v31[1];
    int v199 = v32 + ((int)((unsigned int)(v32 - v28) >> 31));
    v31[1] = v199;
    int * v34 = v15->cache_age;
    v34[v196] = 0;
    v119 = v196;
  } else {
    int * v37 = v15->cache_age;
    int v38 = v37[0];
    int * v39 = v15->cache_tags;
    int v40 = v39[0];
    int v41 = v37[1];
    int v42 = v39[1];
    bool v203 = !(((~(((v23 ^ 6) | (-(v23 ^ 6))) >> 31)) | (~(((v24 ^ 6) | (-(v24 ^ 6))) >> 31))) == 0);
    int v96;
    if (v203) {
      int * v43 = v15->cache_age;
      int v205 = 8 + ((~(((v24 ^ 6) | (-(v24 ^ 6))) >> 31)) & 1);
      int v44 = v43[v205];
      int v45 = v43[8];
      int v206 = v45 + ((int)((unsigned int)(v45 - v44) >> 31));
      v43[8] = v206;
      int * v47 = v15->cache_age;
      int v48 = v47[9];
      int v208 = v48 + ((int)((unsigned int)(v48 - v44) >> 31));
      v47[9] = v208;
      int * v50 = v15->cache_age;
      v50[v205] = 0;
      v96 = v205;
    } else {
      int * v53 = v15->cache_age;
      int v54 = v53[8];
      int * v55 = v15->cache_tags;
      int v56 = v55[8];
      int v57 = v53[9];
      int v58 = v55[9];
      int * v59 = v15->cache_dirty;
      int v213 = 8 + ((((v54 + ((~(((v56 ^ -1) | (-(v56 ^ -1))) >> 31)) & 2)) - (v57 + ((~(((v58 ^ -1) | (-(v58 ^ -1))) >> 31)) & 2))) >> 31) & 1);
      int v60 = v59[v213];
      bool v214 = !(v60 == 0);
      if (v214) {
        int * v61 = v15->cache_tags;
        int v62 = v61[v213];
        int * v63 = v15->cache_vals;
        int v217 = (8 + ((((v54 + ((~(((v56 ^ -1) | (-(v56 ^ -1))) >> 31)) & 2)) - (v57 + ((~(((v58 ^ -1) | (-(v58 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
        int v64 = v63[v217];
        int v218 = ((8 + ((((v54 + ((~(((v56 ^ -1) | (-(v56 ^ -1))) >> 31)) & 2)) - (v57 + ((~(((v58 ^ -1) | (-(v58 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
        int v65 = v63[v218];
        int * v66 = v15->mem;
        int v220 = v62 * 2;
        v66[v220] = v64;
        int * v68 = v15->mem;
        int v223 = (v62 * 2) + 1;
        v68[v223] = v65;
        ;
      } else {
        ;
      }
      int * v73 = v15->mem;
      int v74 = v73[12];
      int v75 = v73[13];
      int * v76 = v15->cache_vals;
      int v231 = (8 + ((((v54 + ((~(((v56 ^ -1) | (-(v56 ^ -1))) >> 31)) & 2)) - (v57 + ((~(((v58 ^ -1) | (-(v58 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
      v76[v231] = v74;
      int * v78 = v15->cache_vals;
      int v234 = ((8 + ((((v54 + ((~(((v56 ^ -1) | (-(v56 ^ -1))) >> 31)) & 2)) - (v57 + ((~(((v58 ^ -1) | (-(v58 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
      v78[v234] = v75;
      int * v80 = v15->cache_tags;
      v80[v213] = 6;
      int * v82 = v15->cache_dirty;
      v82[v213] = 0;
      int * v84 = v15->cache_age;
      v84[v213] = 1;
      int * v86 = v15->cache_age;
      int v87 = v86[v213];
      int v88 = v86[8];
      int v241 = v88 + ((int)((unsigned int)(v88 - v87) >> 31));
      v86[8] = v241;
      int * v90 = v15->cache_age;
      int v91 = v90[9];
      int v243 = v91 + ((int)((unsigned int)(v91 - v87) >> 31));
      v90[9] = v243;
      int * v93 = v15->cache_age;
      v93[v213] = 0;
      v96 = v213;
    }
    int * v97 = v15->cache_vals;
    int v246 = v96 * 2;
    int v98 = v97[v246];
    int v247 = (v96 * 2) + 1;
    int v99 = v97[v247];
    int v248 = ((((v38 + ((~(((v40 ^ -1) | (-(v40 ^ -1))) >> 31)) & 2)) - (v41 + ((~(((v42 ^ -1) | (-(v42 ^ -1))) >> 31)) & 2))) >> 31) & 1) * 2;
    v97[v248] = v98;
    int * v101 = v15->cache_vals;
    int v251 = (((((v38 + ((~(((v40 ^ -1) | (-(v40 ^ -1))) >> 31)) & 2)) - (v41 + ((~(((v42 ^ -1) | (-(v42 ^ -1))) >> 31)) & 2))) >> 31) & 1) * 2) + 1;
    v101[v251] = v99;
    int * v103 = v15->cache_tags;
    int v254 = (((v38 + ((~(((v40 ^ -1) | (-(v40 ^ -1))) >> 31)) & 2)) - (v41 + ((~(((v42 ^ -1) | (-(v42 ^ -1))) >> 31)) & 2))) >> 31) & 1;
    v103[v254] = 6;
    int * v105 = v15->cache_dirty;
    v105[v254] = 0;
    int * v107 = v15->cache_age;
    v107[v254] = 1;
    int * v109 = v15->cache_age;
    int v110 = v109[v254];
    int v111 = v109[0];
    int v259 = v111 + ((int)((unsigned int)(v111 - v110) >> 31));
    v109[0] = v259;
    int * v113 = v15->cache_age;
    int v114 = v113[1];
    int v261 = v114 + ((int)((unsigned int)(v114 - v110) >> 31));
    v113[1] = v261;
    int * v116 = v15->cache_age;
    v116[v254] = 0;
    v119 = v254;
  }
  int * v120 = v15->cache_vals;
  int v264 = (v119 * 2) + 1;
  v120[v264] = v19;
  int * v122 = v15->cache_tags;
  int v123 = v122[8];
  int v124 = v122[9];
  bool v267 = !(((~(((v123 ^ 6) | (-(v123 ^ 6))) >> 31)) | (~(((v124 ^ 6) | (-(v124 ^ 6))) >> 31))) == 0);
  int v178;
  if (v267) {
    int * v125 = v15->cache_age;
    int v269 = 8 + ((~(((v124 ^ 6) | (-(v124 ^ 6))) >> 31)) & 1);
    int v126 = v125[v269];
    int v127 = v125[8];
    int v270 = v127 + ((int)((unsigned int)(v127 - v126) >> 31));
    v125[8] = v270;
    int * v129 = v15->cache_age;
    int v130 = v129[9];
    int v272 = v130 + ((int)((unsigned int)(v130 - v126) >> 31));
    v129[9] = v272;
    int * v132 = v15->cache_age;
    v132[v269] = 0;
    v178 = v269;
  } else {
    int * v135 = v15->cache_age;
    int v136 = v135[8];
    int * v137 = v15->cache_tags;
    int v138 = v137[8];
    int v139 = v135[9];
    int v140 = v137[9];
    int * v141 = v15->cache_dirty;
    int v277 = 8 + ((((v136 + ((~(((v138 ^ -1) | (-(v138 ^ -1))) >> 31)) & 2)) - (v139 + ((~(((v140 ^ -1) | (-(v140 ^ -1))) >> 31)) & 2))) >> 31) & 1);
    int v142 = v141[v277];
    bool v278 = !(v142 == 0);
    if (v278) {
      int * v143 = v15->cache_tags;
      int v144 = v143[v277];
      int * v145 = v15->cache_vals;
      int v281 = (8 + ((((v136 + ((~(((v138 ^ -1) | (-(v138 ^ -1))) >> 31)) & 2)) - (v139 + ((~(((v140 ^ -1) | (-(v140 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
      int v146 = v145[v281];
      int v282 = ((8 + ((((v136 + ((~(((v138 ^ -1) | (-(v138 ^ -1))) >> 31)) & 2)) - (v139 + ((~(((v140 ^ -1) | (-(v140 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
      int v147 = v145[v282];
      int * v148 = v15->mem;
      int v284 = v144 * 2;
      v148[v284] = v146;
      int * v150 = v15->mem;
      int v287 = (v144 * 2) + 1;
      v150[v287] = v147;
      ;
    } else {
      ;
    }
    int * v155 = v15->mem;
    int v156 = v155[12];
    int v157 = v155[13];
    int * v158 = v15->cache_vals;
    int v295 = (8 + ((((v136 + ((~(((v138 ^ -1) | (-(v138 ^ -1))) >> 31)) & 2)) - (v139 + ((~(((v140 ^ -1) | (-(v140 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
    v158[v295] = v156;
    int * v160 = v15->cache_vals;
    int v298 = ((8 + ((((v136 + ((~(((v138 ^ -1) | (-(v138 ^ -1))) >> 31)) & 2)) - (v139 + ((~(((v140 ^ -1) | (-(v140 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
    v160[v298] = v157;
    int * v162 = v15->cache_tags;
    v162[v277] = 6;
    int * v164 = v15->cache_dirty;
    v164[v277] = 0;
    int * v166 = v15->cache_age;
    v166[v277] = 1;
    int * v168 = v15->cache_age;
    int v169 = v168[v277];
    int v170 = v168[8];
    int v305 = v170 + ((int)((unsigned int)(v170 - v169) >> 31));
    v168[8] = v305;
    int * v172 = v15->cache_age;
    int v173 = v172[9];
    int v307 = v173 + ((int)((unsigned int)(v173 - v169) >> 31));
    v172[9] = v307;
    int * v175 = v15->cache_age;
    v175[v277] = 0;
    v178 = v277;
  }
  int * v179 = v15->cache_vals;
  int v310 = (v178 * 2) + 1;
  v179[v310] = v19;
  int * v181 = v15->cache_dirty;
  v181[v178] = 1;
  struct StateT * v183 = slot_2(v15);
  return v183;
}

struct StateT * slot_6(struct StateT * v836) {
  int v837 = v836->timer;
  int v947 = v837 + 1;
  v836->timer = v947;
  int * v839 = v836->regs;
  int v840 = v839[9];
  int * v841 = v836->cache_tags;
  int v951 = (((int)((unsigned int)((int)((unsigned int)v840 >> 2)) >> 1)) & 1) * 2;
  int v842 = v841[v951];
  int v952 = ((((int)((unsigned int)((int)((unsigned int)v840 >> 2)) >> 1)) & 1) * 2) + 1;
  int v843 = v841[v952];
  int v953 = 4 + ((((int)((unsigned int)((int)((unsigned int)v840 >> 2)) >> 1)) & 3) * 2);
  int v844 = v841[v953];
  int v954 = (4 + ((((int)((unsigned int)((int)((unsigned int)v840 >> 2)) >> 1)) & 3) * 2)) + 1;
  int v845 = v841[v954];
  int v846 = v836->timer;
  int v955 = v846 + ((100 ^ (((~(((v844 ^ ((int)((unsigned int)((int)((unsigned int)v840 >> 2)) >> 1))) | (-(v844 ^ ((int)((unsigned int)((int)((unsigned int)v840 >> 2)) >> 1))))) >> 31)) | (~(((v845 ^ ((int)((unsigned int)((int)((unsigned int)v840 >> 2)) >> 1))) | (-(v845 ^ ((int)((unsigned int)((int)((unsigned int)v840 >> 2)) >> 1))))) >> 31))) & 104)) ^ (((~(((v842 ^ ((int)((unsigned int)((int)((unsigned int)v840 >> 2)) >> 1))) | (-(v842 ^ ((int)((unsigned int)((int)((unsigned int)v840 >> 2)) >> 1))))) >> 31)) | (~(((v843 ^ ((int)((unsigned int)((int)((unsigned int)v840 >> 2)) >> 1))) | (-(v843 ^ ((int)((unsigned int)((int)((unsigned int)v840 >> 2)) >> 1))))) >> 31))) & (1 ^ (100 ^ (((~(((v844 ^ ((int)((unsigned int)((int)((unsigned int)v840 >> 2)) >> 1))) | (-(v844 ^ ((int)((unsigned int)((int)((unsigned int)v840 >> 2)) >> 1))))) >> 31)) | (~(((v845 ^ ((int)((unsigned int)((int)((unsigned int)v840 >> 2)) >> 1))) | (-(v845 ^ ((int)((unsigned int)((int)((unsigned int)v840 >> 2)) >> 1))))) >> 31))) & 104)))));
  v836->timer = v955;
  int * v848 = v836->cache_vals;
  bool v956 = !(((~(((v842 ^ ((int)((unsigned int)((int)((unsigned int)v840 >> 2)) >> 1))) | (-(v842 ^ ((int)((unsigned int)((int)((unsigned int)v840 >> 2)) >> 1))))) >> 31)) | (~(((v843 ^ ((int)((unsigned int)((int)((unsigned int)v840 >> 2)) >> 1))) | (-(v843 ^ ((int)((unsigned int)((int)((unsigned int)v840 >> 2)) >> 1))))) >> 31))) == 0);
  int v941;
  if (v956) {
    int * v849 = v836->cache_age;
    int v958 = ((((int)((unsigned int)((int)((unsigned int)v840 >> 2)) >> 1)) & 1) * 2) + ((~(((v843 ^ ((int)((unsigned int)((int)((unsigned int)v840 >> 2)) >> 1))) | (-(v843 ^ ((int)((unsigned int)((int)((unsigned int)v840 >> 2)) >> 1))))) >> 31)) & 1);
    int v850 = v849[v958];
    int v851 = v849[v951];
    int v959 = v851 + ((int)((unsigned int)(v851 - v850) >> 31));
    v849[v951] = v959;
    int * v853 = v836->cache_age;
    int v854 = v853[v952];
    int v961 = v854 + ((int)((unsigned int)(v854 - v850) >> 31));
    v853[v952] = v961;
    int * v856 = v836->cache_age;
    v856[v958] = 0;
    v941 = v958;
  } else {
    int * v859 = v836->cache_age;
    int v965 = (((int)((unsigned int)((int)((unsigned int)v840 >> 2)) >> 1)) & 1) * 2;
    int v860 = v859[v965];
    int * v861 = v836->cache_tags;
    int v862 = v861[v965];
    int v863 = v859[v952];
    int v864 = v861[v952];
    bool v967 = !(((~(((v844 ^ ((int)((unsigned int)((int)((unsigned int)v840 >> 2)) >> 1))) | (-(v844 ^ ((int)((unsigned int)((int)((unsigned int)v840 >> 2)) >> 1))))) >> 31)) | (~(((v845 ^ ((int)((unsigned int)((int)((unsigned int)v840 >> 2)) >> 1))) | (-(v845 ^ ((int)((unsigned int)((int)((unsigned int)v840 >> 2)) >> 1))))) >> 31))) == 0);
    int v918;
    if (v967) {
      int * v865 = v836->cache_age;
      int v969 = (4 + ((((int)((unsigned int)((int)((unsigned int)v840 >> 2)) >> 1)) & 3) * 2)) + ((~(((v845 ^ ((int)((unsigned int)((int)((unsigned int)v840 >> 2)) >> 1))) | (-(v845 ^ ((int)((unsigned int)((int)((unsigned int)v840 >> 2)) >> 1))))) >> 31)) & 1);
      int v866 = v865[v969];
      int v867 = v865[v953];
      int v970 = v867 + ((int)((unsigned int)(v867 - v866) >> 31));
      v865[v953] = v970;
      int * v869 = v836->cache_age;
      int v870 = v869[v954];
      int v972 = v870 + ((int)((unsigned int)(v870 - v866) >> 31));
      v869[v954] = v972;
      int * v872 = v836->cache_age;
      v872[v969] = 0;
      v918 = v969;
    } else {
      int * v875 = v836->cache_age;
      int v976 = 4 + ((((int)((unsigned int)((int)((unsigned int)v840 >> 2)) >> 1)) & 3) * 2);
      int v876 = v875[v976];
      int * v877 = v836->cache_tags;
      int v878 = v877[v976];
      int v879 = v875[v954];
      int v880 = v877[v954];
      int * v881 = v836->cache_dirty;
      int v979 = (4 + ((((int)((unsigned int)((int)((unsigned int)v840 >> 2)) >> 1)) & 3) * 2)) + ((((v876 + ((~(((v878 ^ -1) | (-(v878 ^ -1))) >> 31)) & 2)) - (v879 + ((~(((v880 ^ -1) | (-(v880 ^ -1))) >> 31)) & 2))) >> 31) & 1);
      int v882 = v881[v979];
      bool v980 = !(v882 == 0);
      if (v980) {
        int * v883 = v836->cache_tags;
        int v884 = v883[v979];
        int * v885 = v836->cache_vals;
        int v983 = ((4 + ((((int)((unsigned int)((int)((unsigned int)v840 >> 2)) >> 1)) & 3) * 2)) + ((((v876 + ((~(((v878 ^ -1) | (-(v878 ^ -1))) >> 31)) & 2)) - (v879 + ((~(((v880 ^ -1) | (-(v880 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
        int v886 = v885[v983];
        int v984 = (((4 + ((((int)((unsigned int)((int)((unsigned int)v840 >> 2)) >> 1)) & 3) * 2)) + ((((v876 + ((~(((v878 ^ -1) | (-(v878 ^ -1))) >> 31)) & 2)) - (v879 + ((~(((v880 ^ -1) | (-(v880 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
        int v887 = v885[v984];
        int * v888 = v836->mem;
        int v986 = v884 * 2;
        v888[v986] = v886;
        int * v890 = v836->mem;
        int v989 = (v884 * 2) + 1;
        v890[v989] = v887;
        ;
      } else {
        ;
      }
      int * v895 = v836->mem;
      int v994 = ((int)((unsigned int)((int)((unsigned int)v840 >> 2)) >> 1)) * 2;
      int v896 = v895[v994];
      int v995 = (((int)((unsigned int)((int)((unsigned int)v840 >> 2)) >> 1)) * 2) + 1;
      int v897 = v895[v995];
      int * v898 = v836->cache_vals;
      int v997 = ((4 + ((((int)((unsigned int)((int)((unsigned int)v840 >> 2)) >> 1)) & 3) * 2)) + ((((v876 + ((~(((v878 ^ -1) | (-(v878 ^ -1))) >> 31)) & 2)) - (v879 + ((~(((v880 ^ -1) | (-(v880 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
      v898[v997] = v896;
      int * v900 = v836->cache_vals;
      int v1000 = (((4 + ((((int)((unsigned int)((int)((unsigned int)v840 >> 2)) >> 1)) & 3) * 2)) + ((((v876 + ((~(((v878 ^ -1) | (-(v878 ^ -1))) >> 31)) & 2)) - (v879 + ((~(((v880 ^ -1) | (-(v880 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
      v900[v1000] = v897;
      int * v902 = v836->cache_tags;
      int v1003 = (int)((unsigned int)((int)((unsigned int)v840 >> 2)) >> 1);
      v902[v979] = v1003;
      int * v904 = v836->cache_dirty;
      v904[v979] = 0;
      int * v906 = v836->cache_age;
      v906[v979] = 1;
      int * v908 = v836->cache_age;
      int v909 = v908[v979];
      int v910 = v908[v953];
      int v1009 = v910 + ((int)((unsigned int)(v910 - v909) >> 31));
      v908[v953] = v1009;
      int * v912 = v836->cache_age;
      int v913 = v912[v954];
      int v1011 = v913 + ((int)((unsigned int)(v913 - v909) >> 31));
      v912[v954] = v1011;
      int * v915 = v836->cache_age;
      v915[v979] = 0;
      v918 = v979;
    }
    int * v919 = v836->cache_vals;
    int v1014 = v918 * 2;
    int v920 = v919[v1014];
    int v1015 = (v918 * 2) + 1;
    int v921 = v919[v1015];
    int v1016 = (((((int)((unsigned int)((int)((unsigned int)v840 >> 2)) >> 1)) & 1) * 2) + ((((v860 + ((~(((v862 ^ -1) | (-(v862 ^ -1))) >> 31)) & 2)) - (v863 + ((~(((v864 ^ -1) | (-(v864 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
    v919[v1016] = v920;
    int * v923 = v836->cache_vals;
    int v1019 = ((((((int)((unsigned int)((int)((unsigned int)v840 >> 2)) >> 1)) & 1) * 2) + ((((v860 + ((~(((v862 ^ -1) | (-(v862 ^ -1))) >> 31)) & 2)) - (v863 + ((~(((v864 ^ -1) | (-(v864 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
    v923[v1019] = v921;
    int * v925 = v836->cache_tags;
    int v1022 = ((((int)((unsigned int)((int)((unsigned int)v840 >> 2)) >> 1)) & 1) * 2) + ((((v860 + ((~(((v862 ^ -1) | (-(v862 ^ -1))) >> 31)) & 2)) - (v863 + ((~(((v864 ^ -1) | (-(v864 ^ -1))) >> 31)) & 2))) >> 31) & 1);
    int v1023 = (int)((unsigned int)((int)((unsigned int)v840 >> 2)) >> 1);
    v925[v1022] = v1023;
    int * v927 = v836->cache_dirty;
    v927[v1022] = 0;
    int * v929 = v836->cache_age;
    v929[v1022] = 1;
    int * v931 = v836->cache_age;
    int v932 = v931[v1022];
    int v933 = v931[v951];
    int v1029 = v933 + ((int)((unsigned int)(v933 - v932) >> 31));
    v931[v951] = v1029;
    int * v935 = v836->cache_age;
    int v936 = v935[v952];
    int v1031 = v936 + ((int)((unsigned int)(v936 - v932) >> 31));
    v935[v952] = v1031;
    int * v938 = v836->cache_age;
    v938[v1022] = 0;
    v941 = v1022;
  }
  int v1034 = (v941 * 2) + (((int)((unsigned int)v840 >> 2)) & 1);
  int v942 = v848[v1034];
  int * v943 = v836->regs;
  v943[11] = v942;
  struct StateT * v945 = slot_7(v836);
  return v945;
}

struct StateT * slot_5(struct StateT * v819) {
  int v820 = v819->timer;
  int v828 = v820 + 1;
  v819->timer = v828;
  int * v822 = v819->regs;
  int v823 = v822[10];
  int v824 = v822[8];
  int v833 = v823 & v824;
  v822[9] = v833;
  struct StateT * v826 = slot_6(v819);
  return v826;
}

struct StateT * slot_4(struct StateT * v628) {
  int v629 = v628->timer;
  int v737 = v629 + 1;
  v628->timer = v737;
  int * v631 = v628->cache_tags;
  int v632 = v631[0];
  int v633 = v631[1];
  int v634 = v631[8];
  int v635 = v631[9];
  int v636 = v628->timer;
  int v743 = v636 + ((100 ^ (((~(((v634 ^ 6) | (-(v634 ^ 6))) >> 31)) | (~(((v635 ^ 6) | (-(v635 ^ 6))) >> 31))) & 104)) ^ (((~(((v632 ^ 6) | (-(v632 ^ 6))) >> 31)) | (~(((v633 ^ 6) | (-(v633 ^ 6))) >> 31))) & (1 ^ (100 ^ (((~(((v634 ^ 6) | (-(v634 ^ 6))) >> 31)) | (~(((v635 ^ 6) | (-(v635 ^ 6))) >> 31))) & 104)))));
  v628->timer = v743;
  int * v638 = v628->cache_vals;
  bool v744 = !(((~(((v632 ^ 6) | (-(v632 ^ 6))) >> 31)) | (~(((v633 ^ 6) | (-(v633 ^ 6))) >> 31))) == 0);
  int v731;
  if (v744) {
    int * v639 = v628->cache_age;
    int v746 = (~(((v633 ^ 6) | (-(v633 ^ 6))) >> 31)) & 1;
    int v640 = v639[v746];
    int v641 = v639[0];
    int v747 = v641 + ((int)((unsigned int)(v641 - v640) >> 31));
    v639[0] = v747;
    int * v643 = v628->cache_age;
    int v644 = v643[1];
    int v749 = v644 + ((int)((unsigned int)(v644 - v640) >> 31));
    v643[1] = v749;
    int * v646 = v628->cache_age;
    v646[v746] = 0;
    v731 = v746;
  } else {
    int * v649 = v628->cache_age;
    int v650 = v649[0];
    int * v651 = v628->cache_tags;
    int v652 = v651[0];
    int v653 = v649[1];
    int v654 = v651[1];
    bool v753 = !(((~(((v634 ^ 6) | (-(v634 ^ 6))) >> 31)) | (~(((v635 ^ 6) | (-(v635 ^ 6))) >> 31))) == 0);
    int v708;
    if (v753) {
      int * v655 = v628->cache_age;
      int v755 = 8 + ((~(((v635 ^ 6) | (-(v635 ^ 6))) >> 31)) & 1);
      int v656 = v655[v755];
      int v657 = v655[8];
      int v756 = v657 + ((int)((unsigned int)(v657 - v656) >> 31));
      v655[8] = v756;
      int * v659 = v628->cache_age;
      int v660 = v659[9];
      int v758 = v660 + ((int)((unsigned int)(v660 - v656) >> 31));
      v659[9] = v758;
      int * v662 = v628->cache_age;
      v662[v755] = 0;
      v708 = v755;
    } else {
      int * v665 = v628->cache_age;
      int v666 = v665[8];
      int * v667 = v628->cache_tags;
      int v668 = v667[8];
      int v669 = v665[9];
      int v670 = v667[9];
      int * v671 = v628->cache_dirty;
      int v763 = 8 + ((((v666 + ((~(((v668 ^ -1) | (-(v668 ^ -1))) >> 31)) & 2)) - (v669 + ((~(((v670 ^ -1) | (-(v670 ^ -1))) >> 31)) & 2))) >> 31) & 1);
      int v672 = v671[v763];
      bool v764 = !(v672 == 0);
      if (v764) {
        int * v673 = v628->cache_tags;
        int v674 = v673[v763];
        int * v675 = v628->cache_vals;
        int v767 = (8 + ((((v666 + ((~(((v668 ^ -1) | (-(v668 ^ -1))) >> 31)) & 2)) - (v669 + ((~(((v670 ^ -1) | (-(v670 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
        int v676 = v675[v767];
        int v768 = ((8 + ((((v666 + ((~(((v668 ^ -1) | (-(v668 ^ -1))) >> 31)) & 2)) - (v669 + ((~(((v670 ^ -1) | (-(v670 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
        int v677 = v675[v768];
        int * v678 = v628->mem;
        int v770 = v674 * 2;
        v678[v770] = v676;
        int * v680 = v628->mem;
        int v773 = (v674 * 2) + 1;
        v680[v773] = v677;
        ;
      } else {
        ;
      }
      int * v685 = v628->mem;
      int v686 = v685[12];
      int v687 = v685[13];
      int * v688 = v628->cache_vals;
      int v781 = (8 + ((((v666 + ((~(((v668 ^ -1) | (-(v668 ^ -1))) >> 31)) & 2)) - (v669 + ((~(((v670 ^ -1) | (-(v670 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
      v688[v781] = v686;
      int * v690 = v628->cache_vals;
      int v784 = ((8 + ((((v666 + ((~(((v668 ^ -1) | (-(v668 ^ -1))) >> 31)) & 2)) - (v669 + ((~(((v670 ^ -1) | (-(v670 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
      v690[v784] = v687;
      int * v692 = v628->cache_tags;
      v692[v763] = 6;
      int * v694 = v628->cache_dirty;
      v694[v763] = 0;
      int * v696 = v628->cache_age;
      v696[v763] = 1;
      int * v698 = v628->cache_age;
      int v699 = v698[v763];
      int v700 = v698[8];
      int v791 = v700 + ((int)((unsigned int)(v700 - v699) >> 31));
      v698[8] = v791;
      int * v702 = v628->cache_age;
      int v703 = v702[9];
      int v793 = v703 + ((int)((unsigned int)(v703 - v699) >> 31));
      v702[9] = v793;
      int * v705 = v628->cache_age;
      v705[v763] = 0;
      v708 = v763;
    }
    int * v709 = v628->cache_vals;
    int v796 = v708 * 2;
    int v710 = v709[v796];
    int v797 = (v708 * 2) + 1;
    int v711 = v709[v797];
    int v798 = ((((v650 + ((~(((v652 ^ -1) | (-(v652 ^ -1))) >> 31)) & 2)) - (v653 + ((~(((v654 ^ -1) | (-(v654 ^ -1))) >> 31)) & 2))) >> 31) & 1) * 2;
    v709[v798] = v710;
    int * v713 = v628->cache_vals;
    int v801 = (((((v650 + ((~(((v652 ^ -1) | (-(v652 ^ -1))) >> 31)) & 2)) - (v653 + ((~(((v654 ^ -1) | (-(v654 ^ -1))) >> 31)) & 2))) >> 31) & 1) * 2) + 1;
    v713[v801] = v711;
    int * v715 = v628->cache_tags;
    int v804 = (((v650 + ((~(((v652 ^ -1) | (-(v652 ^ -1))) >> 31)) & 2)) - (v653 + ((~(((v654 ^ -1) | (-(v654 ^ -1))) >> 31)) & 2))) >> 31) & 1;
    v715[v804] = 6;
    int * v717 = v628->cache_dirty;
    v717[v804] = 0;
    int * v719 = v628->cache_age;
    v719[v804] = 1;
    int * v721 = v628->cache_age;
    int v722 = v721[v804];
    int v723 = v721[0];
    int v809 = v723 + ((int)((unsigned int)(v723 - v722) >> 31));
    v721[0] = v809;
    int * v725 = v628->cache_age;
    int v726 = v725[1];
    int v811 = v726 + ((int)((unsigned int)(v726 - v722) >> 31));
    v725[1] = v811;
    int * v728 = v628->cache_age;
    v728[v804] = 0;
    v731 = v804;
  }
  int v814 = (v731 * 2) + 1;
  int v732 = v638[v814];
  int * v733 = v628->regs;
  v733[8] = v732;
  struct StateT * v735 = slot_5(v628);
  return v735;
}

struct StateT * slot_2(struct StateT * v315) {
  int v316 = v315->timer;
  int v322 = v316 + 1;
  v315->timer = v322;
  int * v318 = v315->regs;
  v318[7] = 28;
  struct StateT * v320 = slot_3(v315);
  return v320;
}

struct StateT * slot_7(struct StateT * v1040) {
  int v1041 = v1040->timer;
  int v1150 = v1041 + 1;
  v1040->timer = v1150;
  int * v1043 = v1040->regs;
  int v1044 = v1043[11];
  int * v1045 = v1040->cache_tags;
  int v1154 = (((int)((unsigned int)((int)((unsigned int)v1044 >> 2)) >> 1)) & 1) * 2;
  int v1046 = v1045[v1154];
  int v1155 = ((((int)((unsigned int)((int)((unsigned int)v1044 >> 2)) >> 1)) & 1) * 2) + 1;
  int v1047 = v1045[v1155];
  int v1156 = 4 + ((((int)((unsigned int)((int)((unsigned int)v1044 >> 2)) >> 1)) & 3) * 2);
  int v1048 = v1045[v1156];
  int v1157 = (4 + ((((int)((unsigned int)((int)((unsigned int)v1044 >> 2)) >> 1)) & 3) * 2)) + 1;
  int v1049 = v1045[v1157];
  int v1050 = v1040->timer;
  int v1158 = v1050 + ((100 ^ (((~(((v1048 ^ ((int)((unsigned int)((int)((unsigned int)v1044 >> 2)) >> 1))) | (-(v1048 ^ ((int)((unsigned int)((int)((unsigned int)v1044 >> 2)) >> 1))))) >> 31)) | (~(((v1049 ^ ((int)((unsigned int)((int)((unsigned int)v1044 >> 2)) >> 1))) | (-(v1049 ^ ((int)((unsigned int)((int)((unsigned int)v1044 >> 2)) >> 1))))) >> 31))) & 104)) ^ (((~(((v1046 ^ ((int)((unsigned int)((int)((unsigned int)v1044 >> 2)) >> 1))) | (-(v1046 ^ ((int)((unsigned int)((int)((unsigned int)v1044 >> 2)) >> 1))))) >> 31)) | (~(((v1047 ^ ((int)((unsigned int)((int)((unsigned int)v1044 >> 2)) >> 1))) | (-(v1047 ^ ((int)((unsigned int)((int)((unsigned int)v1044 >> 2)) >> 1))))) >> 31))) & (1 ^ (100 ^ (((~(((v1048 ^ ((int)((unsigned int)((int)((unsigned int)v1044 >> 2)) >> 1))) | (-(v1048 ^ ((int)((unsigned int)((int)((unsigned int)v1044 >> 2)) >> 1))))) >> 31)) | (~(((v1049 ^ ((int)((unsigned int)((int)((unsigned int)v1044 >> 2)) >> 1))) | (-(v1049 ^ ((int)((unsigned int)((int)((unsigned int)v1044 >> 2)) >> 1))))) >> 31))) & 104)))));
  v1040->timer = v1158;
  int * v1052 = v1040->cache_vals;
  bool v1159 = !(((~(((v1046 ^ ((int)((unsigned int)((int)((unsigned int)v1044 >> 2)) >> 1))) | (-(v1046 ^ ((int)((unsigned int)((int)((unsigned int)v1044 >> 2)) >> 1))))) >> 31)) | (~(((v1047 ^ ((int)((unsigned int)((int)((unsigned int)v1044 >> 2)) >> 1))) | (-(v1047 ^ ((int)((unsigned int)((int)((unsigned int)v1044 >> 2)) >> 1))))) >> 31))) == 0);
  int v1145;
  if (v1159) {
    int * v1053 = v1040->cache_age;
    int v1161 = ((((int)((unsigned int)((int)((unsigned int)v1044 >> 2)) >> 1)) & 1) * 2) + ((~(((v1047 ^ ((int)((unsigned int)((int)((unsigned int)v1044 >> 2)) >> 1))) | (-(v1047 ^ ((int)((unsigned int)((int)((unsigned int)v1044 >> 2)) >> 1))))) >> 31)) & 1);
    int v1054 = v1053[v1161];
    int v1055 = v1053[v1154];
    int v1162 = v1055 + ((int)((unsigned int)(v1055 - v1054) >> 31));
    v1053[v1154] = v1162;
    int * v1057 = v1040->cache_age;
    int v1058 = v1057[v1155];
    int v1164 = v1058 + ((int)((unsigned int)(v1058 - v1054) >> 31));
    v1057[v1155] = v1164;
    int * v1060 = v1040->cache_age;
    v1060[v1161] = 0;
    v1145 = v1161;
  } else {
    int * v1063 = v1040->cache_age;
    int v1168 = (((int)((unsigned int)((int)((unsigned int)v1044 >> 2)) >> 1)) & 1) * 2;
    int v1064 = v1063[v1168];
    int * v1065 = v1040->cache_tags;
    int v1066 = v1065[v1168];
    int v1067 = v1063[v1155];
    int v1068 = v1065[v1155];
    bool v1170 = !(((~(((v1048 ^ ((int)((unsigned int)((int)((unsigned int)v1044 >> 2)) >> 1))) | (-(v1048 ^ ((int)((unsigned int)((int)((unsigned int)v1044 >> 2)) >> 1))))) >> 31)) | (~(((v1049 ^ ((int)((unsigned int)((int)((unsigned int)v1044 >> 2)) >> 1))) | (-(v1049 ^ ((int)((unsigned int)((int)((unsigned int)v1044 >> 2)) >> 1))))) >> 31))) == 0);
    int v1122;
    if (v1170) {
      int * v1069 = v1040->cache_age;
      int v1172 = (4 + ((((int)((unsigned int)((int)((unsigned int)v1044 >> 2)) >> 1)) & 3) * 2)) + ((~(((v1049 ^ ((int)((unsigned int)((int)((unsigned int)v1044 >> 2)) >> 1))) | (-(v1049 ^ ((int)((unsigned int)((int)((unsigned int)v1044 >> 2)) >> 1))))) >> 31)) & 1);
      int v1070 = v1069[v1172];
      int v1071 = v1069[v1156];
      int v1173 = v1071 + ((int)((unsigned int)(v1071 - v1070) >> 31));
      v1069[v1156] = v1173;
      int * v1073 = v1040->cache_age;
      int v1074 = v1073[v1157];
      int v1175 = v1074 + ((int)((unsigned int)(v1074 - v1070) >> 31));
      v1073[v1157] = v1175;
      int * v1076 = v1040->cache_age;
      v1076[v1172] = 0;
      v1122 = v1172;
    } else {
      int * v1079 = v1040->cache_age;
      int v1179 = 4 + ((((int)((unsigned int)((int)((unsigned int)v1044 >> 2)) >> 1)) & 3) * 2);
      int v1080 = v1079[v1179];
      int * v1081 = v1040->cache_tags;
      int v1082 = v1081[v1179];
      int v1083 = v1079[v1157];
      int v1084 = v1081[v1157];
      int * v1085 = v1040->cache_dirty;
      int v1182 = (4 + ((((int)((unsigned int)((int)((unsigned int)v1044 >> 2)) >> 1)) & 3) * 2)) + ((((v1080 + ((~(((v1082 ^ -1) | (-(v1082 ^ -1))) >> 31)) & 2)) - (v1083 + ((~(((v1084 ^ -1) | (-(v1084 ^ -1))) >> 31)) & 2))) >> 31) & 1);
      int v1086 = v1085[v1182];
      bool v1183 = !(v1086 == 0);
      if (v1183) {
        int * v1087 = v1040->cache_tags;
        int v1088 = v1087[v1182];
        int * v1089 = v1040->cache_vals;
        int v1186 = ((4 + ((((int)((unsigned int)((int)((unsigned int)v1044 >> 2)) >> 1)) & 3) * 2)) + ((((v1080 + ((~(((v1082 ^ -1) | (-(v1082 ^ -1))) >> 31)) & 2)) - (v1083 + ((~(((v1084 ^ -1) | (-(v1084 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
        int v1090 = v1089[v1186];
        int v1187 = (((4 + ((((int)((unsigned int)((int)((unsigned int)v1044 >> 2)) >> 1)) & 3) * 2)) + ((((v1080 + ((~(((v1082 ^ -1) | (-(v1082 ^ -1))) >> 31)) & 2)) - (v1083 + ((~(((v1084 ^ -1) | (-(v1084 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
        int v1091 = v1089[v1187];
        int * v1092 = v1040->mem;
        int v1189 = v1088 * 2;
        v1092[v1189] = v1090;
        int * v1094 = v1040->mem;
        int v1192 = (v1088 * 2) + 1;
        v1094[v1192] = v1091;
        ;
      } else {
        ;
      }
      int * v1099 = v1040->mem;
      int v1197 = ((int)((unsigned int)((int)((unsigned int)v1044 >> 2)) >> 1)) * 2;
      int v1100 = v1099[v1197];
      int v1198 = (((int)((unsigned int)((int)((unsigned int)v1044 >> 2)) >> 1)) * 2) + 1;
      int v1101 = v1099[v1198];
      int * v1102 = v1040->cache_vals;
      int v1200 = ((4 + ((((int)((unsigned int)((int)((unsigned int)v1044 >> 2)) >> 1)) & 3) * 2)) + ((((v1080 + ((~(((v1082 ^ -1) | (-(v1082 ^ -1))) >> 31)) & 2)) - (v1083 + ((~(((v1084 ^ -1) | (-(v1084 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
      v1102[v1200] = v1100;
      int * v1104 = v1040->cache_vals;
      int v1203 = (((4 + ((((int)((unsigned int)((int)((unsigned int)v1044 >> 2)) >> 1)) & 3) * 2)) + ((((v1080 + ((~(((v1082 ^ -1) | (-(v1082 ^ -1))) >> 31)) & 2)) - (v1083 + ((~(((v1084 ^ -1) | (-(v1084 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
      v1104[v1203] = v1101;
      int * v1106 = v1040->cache_tags;
      int v1206 = (int)((unsigned int)((int)((unsigned int)v1044 >> 2)) >> 1);
      v1106[v1182] = v1206;
      int * v1108 = v1040->cache_dirty;
      v1108[v1182] = 0;
      int * v1110 = v1040->cache_age;
      v1110[v1182] = 1;
      int * v1112 = v1040->cache_age;
      int v1113 = v1112[v1182];
      int v1114 = v1112[v1156];
      int v1212 = v1114 + ((int)((unsigned int)(v1114 - v1113) >> 31));
      v1112[v1156] = v1212;
      int * v1116 = v1040->cache_age;
      int v1117 = v1116[v1157];
      int v1214 = v1117 + ((int)((unsigned int)(v1117 - v1113) >> 31));
      v1116[v1157] = v1214;
      int * v1119 = v1040->cache_age;
      v1119[v1182] = 0;
      v1122 = v1182;
    }
    int * v1123 = v1040->cache_vals;
    int v1217 = v1122 * 2;
    int v1124 = v1123[v1217];
    int v1218 = (v1122 * 2) + 1;
    int v1125 = v1123[v1218];
    int v1219 = (((((int)((unsigned int)((int)((unsigned int)v1044 >> 2)) >> 1)) & 1) * 2) + ((((v1064 + ((~(((v1066 ^ -1) | (-(v1066 ^ -1))) >> 31)) & 2)) - (v1067 + ((~(((v1068 ^ -1) | (-(v1068 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
    v1123[v1219] = v1124;
    int * v1127 = v1040->cache_vals;
    int v1222 = ((((((int)((unsigned int)((int)((unsigned int)v1044 >> 2)) >> 1)) & 1) * 2) + ((((v1064 + ((~(((v1066 ^ -1) | (-(v1066 ^ -1))) >> 31)) & 2)) - (v1067 + ((~(((v1068 ^ -1) | (-(v1068 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
    v1127[v1222] = v1125;
    int * v1129 = v1040->cache_tags;
    int v1225 = ((((int)((unsigned int)((int)((unsigned int)v1044 >> 2)) >> 1)) & 1) * 2) + ((((v1064 + ((~(((v1066 ^ -1) | (-(v1066 ^ -1))) >> 31)) & 2)) - (v1067 + ((~(((v1068 ^ -1) | (-(v1068 ^ -1))) >> 31)) & 2))) >> 31) & 1);
    int v1226 = (int)((unsigned int)((int)((unsigned int)v1044 >> 2)) >> 1);
    v1129[v1225] = v1226;
    int * v1131 = v1040->cache_dirty;
    v1131[v1225] = 0;
    int * v1133 = v1040->cache_age;
    v1133[v1225] = 1;
    int * v1135 = v1040->cache_age;
    int v1136 = v1135[v1225];
    int v1137 = v1135[v1154];
    int v1232 = v1137 + ((int)((unsigned int)(v1137 - v1136) >> 31));
    v1135[v1154] = v1232;
    int * v1139 = v1040->cache_age;
    int v1140 = v1139[v1155];
    int v1234 = v1140 + ((int)((unsigned int)(v1140 - v1136) >> 31));
    v1139[v1155] = v1234;
    int * v1142 = v1040->cache_age;
    v1142[v1225] = 0;
    v1145 = v1225;
  }
  int v1237 = (v1145 * 2) + (((int)((unsigned int)v1044 >> 2)) & 1);
  int v1146 = v1052[v1237];
  int * v1147 = v1040->regs;
  v1147[12] = v1146;
  return v1040;
}

struct StateT * slot_3(struct StateT * v328) {
  int v329 = v328->timer;
  int v498 = v329 + 1;
  v328->timer = v498;
  int * v331 = v328->regs;
  int v332 = v331[7];
  int * v333 = v328->cache_tags;
  int v334 = v333[0];
  int v335 = v333[1];
  int v336 = v333[8];
  int v337 = v333[9];
  int v338 = v328->timer;
  int v506 = v338 + ((100 ^ (((~(((v336 ^ 6) | (-(v336 ^ 6))) >> 31)) | (~(((v337 ^ 6) | (-(v337 ^ 6))) >> 31))) & 104)) ^ (((~(((v334 ^ 6) | (-(v334 ^ 6))) >> 31)) | (~(((v335 ^ 6) | (-(v335 ^ 6))) >> 31))) & (1 ^ (100 ^ (((~(((v336 ^ 6) | (-(v336 ^ 6))) >> 31)) | (~(((v337 ^ 6) | (-(v337 ^ 6))) >> 31))) & 104)))));
  v328->timer = v506;
  bool v507 = !(((~(((v334 ^ 6) | (-(v334 ^ 6))) >> 31)) | (~(((v335 ^ 6) | (-(v335 ^ 6))) >> 31))) == 0);
  int v432;
  if (v507) {
    int * v340 = v328->cache_age;
    int v509 = (~(((v335 ^ 6) | (-(v335 ^ 6))) >> 31)) & 1;
    int v341 = v340[v509];
    int v342 = v340[0];
    int v510 = v342 + ((int)((unsigned int)(v342 - v341) >> 31));
    v340[0] = v510;
    int * v344 = v328->cache_age;
    int v345 = v344[1];
    int v512 = v345 + ((int)((unsigned int)(v345 - v341) >> 31));
    v344[1] = v512;
    int * v347 = v328->cache_age;
    v347[v509] = 0;
    v432 = v509;
  } else {
    int * v350 = v328->cache_age;
    int v351 = v350[0];
    int * v352 = v328->cache_tags;
    int v353 = v352[0];
    int v354 = v350[1];
    int v355 = v352[1];
    bool v516 = !(((~(((v336 ^ 6) | (-(v336 ^ 6))) >> 31)) | (~(((v337 ^ 6) | (-(v337 ^ 6))) >> 31))) == 0);
    int v409;
    if (v516) {
      int * v356 = v328->cache_age;
      int v518 = 8 + ((~(((v337 ^ 6) | (-(v337 ^ 6))) >> 31)) & 1);
      int v357 = v356[v518];
      int v358 = v356[8];
      int v519 = v358 + ((int)((unsigned int)(v358 - v357) >> 31));
      v356[8] = v519;
      int * v360 = v328->cache_age;
      int v361 = v360[9];
      int v521 = v361 + ((int)((unsigned int)(v361 - v357) >> 31));
      v360[9] = v521;
      int * v363 = v328->cache_age;
      v363[v518] = 0;
      v409 = v518;
    } else {
      int * v366 = v328->cache_age;
      int v367 = v366[8];
      int * v368 = v328->cache_tags;
      int v369 = v368[8];
      int v370 = v366[9];
      int v371 = v368[9];
      int * v372 = v328->cache_dirty;
      int v526 = 8 + ((((v367 + ((~(((v369 ^ -1) | (-(v369 ^ -1))) >> 31)) & 2)) - (v370 + ((~(((v371 ^ -1) | (-(v371 ^ -1))) >> 31)) & 2))) >> 31) & 1);
      int v373 = v372[v526];
      bool v527 = !(v373 == 0);
      if (v527) {
        int * v374 = v328->cache_tags;
        int v375 = v374[v526];
        int * v376 = v328->cache_vals;
        int v530 = (8 + ((((v367 + ((~(((v369 ^ -1) | (-(v369 ^ -1))) >> 31)) & 2)) - (v370 + ((~(((v371 ^ -1) | (-(v371 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
        int v377 = v376[v530];
        int v531 = ((8 + ((((v367 + ((~(((v369 ^ -1) | (-(v369 ^ -1))) >> 31)) & 2)) - (v370 + ((~(((v371 ^ -1) | (-(v371 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
        int v378 = v376[v531];
        int * v379 = v328->mem;
        int v533 = v375 * 2;
        v379[v533] = v377;
        int * v381 = v328->mem;
        int v536 = (v375 * 2) + 1;
        v381[v536] = v378;
        ;
      } else {
        ;
      }
      int * v386 = v328->mem;
      int v387 = v386[12];
      int v388 = v386[13];
      int * v389 = v328->cache_vals;
      int v544 = (8 + ((((v367 + ((~(((v369 ^ -1) | (-(v369 ^ -1))) >> 31)) & 2)) - (v370 + ((~(((v371 ^ -1) | (-(v371 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
      v389[v544] = v387;
      int * v391 = v328->cache_vals;
      int v547 = ((8 + ((((v367 + ((~(((v369 ^ -1) | (-(v369 ^ -1))) >> 31)) & 2)) - (v370 + ((~(((v371 ^ -1) | (-(v371 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
      v391[v547] = v388;
      int * v393 = v328->cache_tags;
      v393[v526] = 6;
      int * v395 = v328->cache_dirty;
      v395[v526] = 0;
      int * v397 = v328->cache_age;
      v397[v526] = 1;
      int * v399 = v328->cache_age;
      int v400 = v399[v526];
      int v401 = v399[8];
      int v554 = v401 + ((int)((unsigned int)(v401 - v400) >> 31));
      v399[8] = v554;
      int * v403 = v328->cache_age;
      int v404 = v403[9];
      int v556 = v404 + ((int)((unsigned int)(v404 - v400) >> 31));
      v403[9] = v556;
      int * v406 = v328->cache_age;
      v406[v526] = 0;
      v409 = v526;
    }
    int * v410 = v328->cache_vals;
    int v559 = v409 * 2;
    int v411 = v410[v559];
    int v560 = (v409 * 2) + 1;
    int v412 = v410[v560];
    int v561 = ((((v351 + ((~(((v353 ^ -1) | (-(v353 ^ -1))) >> 31)) & 2)) - (v354 + ((~(((v355 ^ -1) | (-(v355 ^ -1))) >> 31)) & 2))) >> 31) & 1) * 2;
    v410[v561] = v411;
    int * v414 = v328->cache_vals;
    int v564 = (((((v351 + ((~(((v353 ^ -1) | (-(v353 ^ -1))) >> 31)) & 2)) - (v354 + ((~(((v355 ^ -1) | (-(v355 ^ -1))) >> 31)) & 2))) >> 31) & 1) * 2) + 1;
    v414[v564] = v412;
    int * v416 = v328->cache_tags;
    int v567 = (((v351 + ((~(((v353 ^ -1) | (-(v353 ^ -1))) >> 31)) & 2)) - (v354 + ((~(((v355 ^ -1) | (-(v355 ^ -1))) >> 31)) & 2))) >> 31) & 1;
    v416[v567] = 6;
    int * v418 = v328->cache_dirty;
    v418[v567] = 0;
    int * v420 = v328->cache_age;
    v420[v567] = 1;
    int * v422 = v328->cache_age;
    int v423 = v422[v567];
    int v424 = v422[0];
    int v572 = v424 + ((int)((unsigned int)(v424 - v423) >> 31));
    v422[0] = v572;
    int * v426 = v328->cache_age;
    int v427 = v426[1];
    int v574 = v427 + ((int)((unsigned int)(v427 - v423) >> 31));
    v426[1] = v574;
    int * v429 = v328->cache_age;
    v429[v567] = 0;
    v432 = v567;
  }
  int * v433 = v328->cache_vals;
  int v577 = (v432 * 2) + 1;
  v433[v577] = v332;
  int * v435 = v328->cache_tags;
  int v436 = v435[8];
  int v437 = v435[9];
  bool v580 = !(((~(((v436 ^ 6) | (-(v436 ^ 6))) >> 31)) | (~(((v437 ^ 6) | (-(v437 ^ 6))) >> 31))) == 0);
  int v491;
  if (v580) {
    int * v438 = v328->cache_age;
    int v582 = 8 + ((~(((v437 ^ 6) | (-(v437 ^ 6))) >> 31)) & 1);
    int v439 = v438[v582];
    int v440 = v438[8];
    int v583 = v440 + ((int)((unsigned int)(v440 - v439) >> 31));
    v438[8] = v583;
    int * v442 = v328->cache_age;
    int v443 = v442[9];
    int v585 = v443 + ((int)((unsigned int)(v443 - v439) >> 31));
    v442[9] = v585;
    int * v445 = v328->cache_age;
    v445[v582] = 0;
    v491 = v582;
  } else {
    int * v448 = v328->cache_age;
    int v449 = v448[8];
    int * v450 = v328->cache_tags;
    int v451 = v450[8];
    int v452 = v448[9];
    int v453 = v450[9];
    int * v454 = v328->cache_dirty;
    int v590 = 8 + ((((v449 + ((~(((v451 ^ -1) | (-(v451 ^ -1))) >> 31)) & 2)) - (v452 + ((~(((v453 ^ -1) | (-(v453 ^ -1))) >> 31)) & 2))) >> 31) & 1);
    int v455 = v454[v590];
    bool v591 = !(v455 == 0);
    if (v591) {
      int * v456 = v328->cache_tags;
      int v457 = v456[v590];
      int * v458 = v328->cache_vals;
      int v594 = (8 + ((((v449 + ((~(((v451 ^ -1) | (-(v451 ^ -1))) >> 31)) & 2)) - (v452 + ((~(((v453 ^ -1) | (-(v453 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
      int v459 = v458[v594];
      int v595 = ((8 + ((((v449 + ((~(((v451 ^ -1) | (-(v451 ^ -1))) >> 31)) & 2)) - (v452 + ((~(((v453 ^ -1) | (-(v453 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
      int v460 = v458[v595];
      int * v461 = v328->mem;
      int v597 = v457 * 2;
      v461[v597] = v459;
      int * v463 = v328->mem;
      int v600 = (v457 * 2) + 1;
      v463[v600] = v460;
      ;
    } else {
      ;
    }
    int * v468 = v328->mem;
    int v469 = v468[12];
    int v470 = v468[13];
    int * v471 = v328->cache_vals;
    int v608 = (8 + ((((v449 + ((~(((v451 ^ -1) | (-(v451 ^ -1))) >> 31)) & 2)) - (v452 + ((~(((v453 ^ -1) | (-(v453 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
    v471[v608] = v469;
    int * v473 = v328->cache_vals;
    int v611 = ((8 + ((((v449 + ((~(((v451 ^ -1) | (-(v451 ^ -1))) >> 31)) & 2)) - (v452 + ((~(((v453 ^ -1) | (-(v453 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
    v473[v611] = v470;
    int * v475 = v328->cache_tags;
    v475[v590] = 6;
    int * v477 = v328->cache_dirty;
    v477[v590] = 0;
    int * v479 = v328->cache_age;
    v479[v590] = 1;
    int * v481 = v328->cache_age;
    int v482 = v481[v590];
    int v483 = v481[8];
    int v618 = v483 + ((int)((unsigned int)(v483 - v482) >> 31));
    v481[8] = v618;
    int * v485 = v328->cache_age;
    int v486 = v485[9];
    int v620 = v486 + ((int)((unsigned int)(v486 - v482) >> 31));
    v485[9] = v620;
    int * v488 = v328->cache_age;
    v488[v590] = 0;
    v491 = v590;
  }
  int * v492 = v328->cache_vals;
  int v623 = (v491 * 2) + 1;
  v492[v623] = v332;
  int * v494 = v328->cache_dirty;
  v494[v491] = 1;
  struct StateT * v496 = slot_4(v328);
  return v496;
}

struct StateT * slot_0(struct StateT * v2) {
  int v3 = v2->timer;
  int v9 = v3 + 1;
  v2->timer = v9;
  int * v5 = v2->regs;
  v5[5] = -1;
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
  //@ assert untainted_timer: !\tainted(s1_->timer==s2_->timer);
  koika_assert(s1_->timer==s2_->timer, "timing leak");
  return 0;
}