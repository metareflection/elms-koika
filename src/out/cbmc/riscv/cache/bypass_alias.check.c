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
struct StateT * slot_8(struct StateT * v955);
struct StateT * slot_6(struct StateT * v689);
struct StateT * slot_5(struct StateT * v676);
struct StateT * slot_4(struct StateT * v291);
struct StateT * slot_2(struct StateT * v265);
struct StateT * slot_7(struct StateT * v705);
struct StateT * slot_3(struct StateT * v278);
struct StateT * slot_0(struct StateT * v2);
struct StateT * snippet(struct StateT * v0) {
  struct StateT * v1 = slot_0(v0);
  return v1;
}

struct StateT * slot_1(struct StateT * v15) {
  int v16 = v15->timer;
  int v149 = v16 + 1;
  v15->timer = v149;
  int * v18 = v15->regs;
  int v19 = v18[6];
  int * v20 = v15->cache_tags;
  int v153 = (((int)((unsigned int)((int)((unsigned int)v19 >> 2)) >> 1)) & 1) * 2;
  int v21 = v20[v153];
  int * v22 = v15->cache_tags;
  int v155 = ((((int)((unsigned int)((int)((unsigned int)v19 >> 2)) >> 1)) & 1) * 2) + 1;
  int v23 = v22[v155];
  int * v24 = v15->cache_tags;
  int v157 = 4 + ((((int)((unsigned int)((int)((unsigned int)v19 >> 2)) >> 1)) & 3) * 2);
  int v25 = v24[v157];
  int * v26 = v15->cache_tags;
  int v159 = (4 + ((((int)((unsigned int)((int)((unsigned int)v19 >> 2)) >> 1)) & 3) * 2)) + 1;
  int v27 = v26[v159];
  int v28 = v15->timer;
  int v160 = v28 + ((100 ^ (((~(((v25 ^ ((int)((unsigned int)((int)((unsigned int)v19 >> 2)) >> 1))) | (-(v25 ^ ((int)((unsigned int)((int)((unsigned int)v19 >> 2)) >> 1))))) >> 31)) | (~(((v27 ^ ((int)((unsigned int)((int)((unsigned int)v19 >> 2)) >> 1))) | (-(v27 ^ ((int)((unsigned int)((int)((unsigned int)v19 >> 2)) >> 1))))) >> 31))) & 104)) ^ (((~(((v21 ^ ((int)((unsigned int)((int)((unsigned int)v19 >> 2)) >> 1))) | (-(v21 ^ ((int)((unsigned int)((int)((unsigned int)v19 >> 2)) >> 1))))) >> 31)) | (~(((v23 ^ ((int)((unsigned int)((int)((unsigned int)v19 >> 2)) >> 1))) | (-(v23 ^ ((int)((unsigned int)((int)((unsigned int)v19 >> 2)) >> 1))))) >> 31))) & (1 ^ (100 ^ (((~(((v25 ^ ((int)((unsigned int)((int)((unsigned int)v19 >> 2)) >> 1))) | (-(v25 ^ ((int)((unsigned int)((int)((unsigned int)v19 >> 2)) >> 1))))) >> 31)) | (~(((v27 ^ ((int)((unsigned int)((int)((unsigned int)v19 >> 2)) >> 1))) | (-(v27 ^ ((int)((unsigned int)((int)((unsigned int)v19 >> 2)) >> 1))))) >> 31))) & 104)))));
  v15->timer = v160;
  int * v30 = v15->cache_vals;
  bool v161 = !(((~(((v21 ^ ((int)((unsigned int)((int)((unsigned int)v19 >> 2)) >> 1))) | (-(v21 ^ ((int)((unsigned int)((int)((unsigned int)v19 >> 2)) >> 1))))) >> 31)) | (~(((v23 ^ ((int)((unsigned int)((int)((unsigned int)v19 >> 2)) >> 1))) | (-(v23 ^ ((int)((unsigned int)((int)((unsigned int)v19 >> 2)) >> 1))))) >> 31))) == 0);
  int v143;
  if (v161) {
    int * v31 = v15->cache_age;
    int v163 = ((((int)((unsigned int)((int)((unsigned int)v19 >> 2)) >> 1)) & 1) * 2) + ((~(((v23 ^ ((int)((unsigned int)((int)((unsigned int)v19 >> 2)) >> 1))) | (-(v23 ^ ((int)((unsigned int)((int)((unsigned int)v19 >> 2)) >> 1))))) >> 31)) & 1);
    int v32 = v31[v163];
    int * v33 = v15->cache_age;
    int v34 = v33[v153];
    int * v35 = v15->cache_age;
    int v166 = v34 + ((int)((unsigned int)(v34 - v32) >> 31));
    v35[v153] = v166;
    int * v37 = v15->cache_age;
    int v38 = v37[v155];
    int * v39 = v15->cache_age;
    int v169 = v38 + ((int)((unsigned int)(v38 - v32) >> 31));
    v39[v155] = v169;
    int * v41 = v15->cache_age;
    v41[v163] = 0;
    v143 = v163;
  } else {
    int * v44 = v15->cache_age;
    int v173 = (((int)((unsigned int)((int)((unsigned int)v19 >> 2)) >> 1)) & 1) * 2;
    int v45 = v44[v173];
    int * v46 = v15->cache_tags;
    int v47 = v46[v173];
    int * v48 = v15->cache_age;
    int v49 = v48[v155];
    int * v50 = v15->cache_tags;
    int v51 = v50[v155];
    bool v177 = !(((~(((v25 ^ ((int)((unsigned int)((int)((unsigned int)v19 >> 2)) >> 1))) | (-(v25 ^ ((int)((unsigned int)((int)((unsigned int)v19 >> 2)) >> 1))))) >> 31)) | (~(((v27 ^ ((int)((unsigned int)((int)((unsigned int)v19 >> 2)) >> 1))) | (-(v27 ^ ((int)((unsigned int)((int)((unsigned int)v19 >> 2)) >> 1))))) >> 31))) == 0);
    int v115;
    if (v177) {
      int * v52 = v15->cache_age;
      int v179 = (4 + ((((int)((unsigned int)((int)((unsigned int)v19 >> 2)) >> 1)) & 3) * 2)) + ((~(((v27 ^ ((int)((unsigned int)((int)((unsigned int)v19 >> 2)) >> 1))) | (-(v27 ^ ((int)((unsigned int)((int)((unsigned int)v19 >> 2)) >> 1))))) >> 31)) & 1);
      int v53 = v52[v179];
      int * v54 = v15->cache_age;
      int v55 = v54[v157];
      int * v56 = v15->cache_age;
      int v182 = v55 + ((int)((unsigned int)(v55 - v53) >> 31));
      v56[v157] = v182;
      int * v58 = v15->cache_age;
      int v59 = v58[v159];
      int * v60 = v15->cache_age;
      int v185 = v59 + ((int)((unsigned int)(v59 - v53) >> 31));
      v60[v159] = v185;
      int * v62 = v15->cache_age;
      v62[v179] = 0;
      v115 = v179;
    } else {
      int * v65 = v15->cache_age;
      int v189 = 4 + ((((int)((unsigned int)((int)((unsigned int)v19 >> 2)) >> 1)) & 3) * 2);
      int v66 = v65[v189];
      int * v67 = v15->cache_tags;
      int v68 = v67[v189];
      int * v69 = v15->cache_age;
      int v70 = v69[v159];
      int * v71 = v15->cache_tags;
      int v72 = v71[v159];
      int * v73 = v15->cache_dirty;
      int v194 = (4 + ((((int)((unsigned int)((int)((unsigned int)v19 >> 2)) >> 1)) & 3) * 2)) + ((((v66 + ((~(((v68 ^ -1) | (-(v68 ^ -1))) >> 31)) & 2)) - (v70 + ((~(((v72 ^ -1) | (-(v72 ^ -1))) >> 31)) & 2))) >> 31) & 1);
      int v74 = v73[v194];
      bool v195 = !(v74 == 0);
      if (v195) {
        int * v75 = v15->cache_tags;
        int v76 = v75[v194];
        int * v77 = v15->cache_vals;
        int v198 = ((4 + ((((int)((unsigned int)((int)((unsigned int)v19 >> 2)) >> 1)) & 3) * 2)) + ((((v66 + ((~(((v68 ^ -1) | (-(v68 ^ -1))) >> 31)) & 2)) - (v70 + ((~(((v72 ^ -1) | (-(v72 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
        int v78 = v77[v198];
        int * v79 = v15->cache_vals;
        int v200 = (((4 + ((((int)((unsigned int)((int)((unsigned int)v19 >> 2)) >> 1)) & 3) * 2)) + ((((v66 + ((~(((v68 ^ -1) | (-(v68 ^ -1))) >> 31)) & 2)) - (v70 + ((~(((v72 ^ -1) | (-(v72 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
        int v80 = v79[v200];
        int * v81 = v15->mem;
        int v202 = v76 * 2;
        v81[v202] = v78;
        int * v83 = v15->mem;
        int v205 = (v76 * 2) + 1;
        v83[v205] = v80;
        ;
      } else {
        ;
      }
      int * v88 = v15->mem;
      int v210 = ((int)((unsigned int)((int)((unsigned int)v19 >> 2)) >> 1)) * 2;
      int v89 = v88[v210];
      int * v90 = v15->mem;
      int v212 = (((int)((unsigned int)((int)((unsigned int)v19 >> 2)) >> 1)) * 2) + 1;
      int v91 = v90[v212];
      int * v92 = v15->cache_vals;
      int v214 = ((4 + ((((int)((unsigned int)((int)((unsigned int)v19 >> 2)) >> 1)) & 3) * 2)) + ((((v66 + ((~(((v68 ^ -1) | (-(v68 ^ -1))) >> 31)) & 2)) - (v70 + ((~(((v72 ^ -1) | (-(v72 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
      v92[v214] = v89;
      int * v94 = v15->cache_vals;
      int v217 = (((4 + ((((int)((unsigned int)((int)((unsigned int)v19 >> 2)) >> 1)) & 3) * 2)) + ((((v66 + ((~(((v68 ^ -1) | (-(v68 ^ -1))) >> 31)) & 2)) - (v70 + ((~(((v72 ^ -1) | (-(v72 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
      v94[v217] = v91;
      int * v96 = v15->cache_tags;
      int v220 = (int)((unsigned int)((int)((unsigned int)v19 >> 2)) >> 1);
      v96[v194] = v220;
      int * v98 = v15->cache_dirty;
      v98[v194] = 0;
      int * v100 = v15->cache_age;
      v100[v194] = 1;
      int * v102 = v15->cache_age;
      int v103 = v102[v194];
      int * v104 = v15->cache_age;
      int v105 = v104[v157];
      int * v106 = v15->cache_age;
      int v228 = v105 + ((int)((unsigned int)(v105 - v103) >> 31));
      v106[v157] = v228;
      int * v108 = v15->cache_age;
      int v109 = v108[v159];
      int * v110 = v15->cache_age;
      int v231 = v109 + ((int)((unsigned int)(v109 - v103) >> 31));
      v110[v159] = v231;
      int * v112 = v15->cache_age;
      v112[v194] = 0;
      v115 = v194;
    }
    int * v116 = v15->cache_vals;
    int v234 = v115 * 2;
    int v117 = v116[v234];
    int * v118 = v15->cache_vals;
    int v236 = (v115 * 2) + 1;
    int v119 = v118[v236];
    int * v120 = v15->cache_vals;
    int v238 = (((((int)((unsigned int)((int)((unsigned int)v19 >> 2)) >> 1)) & 1) * 2) + ((((v45 + ((~(((v47 ^ -1) | (-(v47 ^ -1))) >> 31)) & 2)) - (v49 + ((~(((v51 ^ -1) | (-(v51 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
    v120[v238] = v117;
    int * v122 = v15->cache_vals;
    int v241 = ((((((int)((unsigned int)((int)((unsigned int)v19 >> 2)) >> 1)) & 1) * 2) + ((((v45 + ((~(((v47 ^ -1) | (-(v47 ^ -1))) >> 31)) & 2)) - (v49 + ((~(((v51 ^ -1) | (-(v51 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
    v122[v241] = v119;
    int * v124 = v15->cache_tags;
    int v244 = ((((int)((unsigned int)((int)((unsigned int)v19 >> 2)) >> 1)) & 1) * 2) + ((((v45 + ((~(((v47 ^ -1) | (-(v47 ^ -1))) >> 31)) & 2)) - (v49 + ((~(((v51 ^ -1) | (-(v51 ^ -1))) >> 31)) & 2))) >> 31) & 1);
    int v245 = (int)((unsigned int)((int)((unsigned int)v19 >> 2)) >> 1);
    v124[v244] = v245;
    int * v126 = v15->cache_dirty;
    v126[v244] = 0;
    int * v128 = v15->cache_age;
    v128[v244] = 1;
    int * v130 = v15->cache_age;
    int v131 = v130[v244];
    int * v132 = v15->cache_age;
    int v133 = v132[v153];
    int * v134 = v15->cache_age;
    int v253 = v133 + ((int)((unsigned int)(v133 - v131) >> 31));
    v134[v153] = v253;
    int * v136 = v15->cache_age;
    int v137 = v136[v155];
    int * v138 = v15->cache_age;
    int v256 = v137 + ((int)((unsigned int)(v137 - v131) >> 31));
    v138[v155] = v256;
    int * v140 = v15->cache_age;
    v140[v244] = 0;
    v143 = v244;
  }
  int v259 = (v143 * 2) + (((int)((unsigned int)v19 >> 2)) & 1);
  int v144 = v30[v259];
  int * v145 = v15->regs;
  v145[5] = v144;
  struct StateT * v147 = slot_2(v15);
  return v147;
}

struct StateT * slot_8(struct StateT * v955) {
  int v956 = v955->timer;
  int v1088 = v956 + 1;
  v955->timer = v1088;
  int * v958 = v955->regs;
  int v959 = v958[11];
  int * v960 = v955->cache_tags;
  int v1092 = (((int)((unsigned int)((int)((unsigned int)v959 >> 2)) >> 1)) & 1) * 2;
  int v961 = v960[v1092];
  int * v962 = v955->cache_tags;
  int v1094 = ((((int)((unsigned int)((int)((unsigned int)v959 >> 2)) >> 1)) & 1) * 2) + 1;
  int v963 = v962[v1094];
  int * v964 = v955->cache_tags;
  int v1096 = 4 + ((((int)((unsigned int)((int)((unsigned int)v959 >> 2)) >> 1)) & 3) * 2);
  int v965 = v964[v1096];
  int * v966 = v955->cache_tags;
  int v1098 = (4 + ((((int)((unsigned int)((int)((unsigned int)v959 >> 2)) >> 1)) & 3) * 2)) + 1;
  int v967 = v966[v1098];
  int v968 = v955->timer;
  int v1099 = v968 + ((100 ^ (((~(((v965 ^ ((int)((unsigned int)((int)((unsigned int)v959 >> 2)) >> 1))) | (-(v965 ^ ((int)((unsigned int)((int)((unsigned int)v959 >> 2)) >> 1))))) >> 31)) | (~(((v967 ^ ((int)((unsigned int)((int)((unsigned int)v959 >> 2)) >> 1))) | (-(v967 ^ ((int)((unsigned int)((int)((unsigned int)v959 >> 2)) >> 1))))) >> 31))) & 104)) ^ (((~(((v961 ^ ((int)((unsigned int)((int)((unsigned int)v959 >> 2)) >> 1))) | (-(v961 ^ ((int)((unsigned int)((int)((unsigned int)v959 >> 2)) >> 1))))) >> 31)) | (~(((v963 ^ ((int)((unsigned int)((int)((unsigned int)v959 >> 2)) >> 1))) | (-(v963 ^ ((int)((unsigned int)((int)((unsigned int)v959 >> 2)) >> 1))))) >> 31))) & (1 ^ (100 ^ (((~(((v965 ^ ((int)((unsigned int)((int)((unsigned int)v959 >> 2)) >> 1))) | (-(v965 ^ ((int)((unsigned int)((int)((unsigned int)v959 >> 2)) >> 1))))) >> 31)) | (~(((v967 ^ ((int)((unsigned int)((int)((unsigned int)v959 >> 2)) >> 1))) | (-(v967 ^ ((int)((unsigned int)((int)((unsigned int)v959 >> 2)) >> 1))))) >> 31))) & 104)))));
  v955->timer = v1099;
  int * v970 = v955->cache_vals;
  bool v1100 = !(((~(((v961 ^ ((int)((unsigned int)((int)((unsigned int)v959 >> 2)) >> 1))) | (-(v961 ^ ((int)((unsigned int)((int)((unsigned int)v959 >> 2)) >> 1))))) >> 31)) | (~(((v963 ^ ((int)((unsigned int)((int)((unsigned int)v959 >> 2)) >> 1))) | (-(v963 ^ ((int)((unsigned int)((int)((unsigned int)v959 >> 2)) >> 1))))) >> 31))) == 0);
  int v1083;
  if (v1100) {
    int * v971 = v955->cache_age;
    int v1102 = ((((int)((unsigned int)((int)((unsigned int)v959 >> 2)) >> 1)) & 1) * 2) + ((~(((v963 ^ ((int)((unsigned int)((int)((unsigned int)v959 >> 2)) >> 1))) | (-(v963 ^ ((int)((unsigned int)((int)((unsigned int)v959 >> 2)) >> 1))))) >> 31)) & 1);
    int v972 = v971[v1102];
    int * v973 = v955->cache_age;
    int v974 = v973[v1092];
    int * v975 = v955->cache_age;
    int v1105 = v974 + ((int)((unsigned int)(v974 - v972) >> 31));
    v975[v1092] = v1105;
    int * v977 = v955->cache_age;
    int v978 = v977[v1094];
    int * v979 = v955->cache_age;
    int v1108 = v978 + ((int)((unsigned int)(v978 - v972) >> 31));
    v979[v1094] = v1108;
    int * v981 = v955->cache_age;
    v981[v1102] = 0;
    v1083 = v1102;
  } else {
    int * v984 = v955->cache_age;
    int v1112 = (((int)((unsigned int)((int)((unsigned int)v959 >> 2)) >> 1)) & 1) * 2;
    int v985 = v984[v1112];
    int * v986 = v955->cache_tags;
    int v987 = v986[v1112];
    int * v988 = v955->cache_age;
    int v989 = v988[v1094];
    int * v990 = v955->cache_tags;
    int v991 = v990[v1094];
    bool v1116 = !(((~(((v965 ^ ((int)((unsigned int)((int)((unsigned int)v959 >> 2)) >> 1))) | (-(v965 ^ ((int)((unsigned int)((int)((unsigned int)v959 >> 2)) >> 1))))) >> 31)) | (~(((v967 ^ ((int)((unsigned int)((int)((unsigned int)v959 >> 2)) >> 1))) | (-(v967 ^ ((int)((unsigned int)((int)((unsigned int)v959 >> 2)) >> 1))))) >> 31))) == 0);
    int v1055;
    if (v1116) {
      int * v992 = v955->cache_age;
      int v1118 = (4 + ((((int)((unsigned int)((int)((unsigned int)v959 >> 2)) >> 1)) & 3) * 2)) + ((~(((v967 ^ ((int)((unsigned int)((int)((unsigned int)v959 >> 2)) >> 1))) | (-(v967 ^ ((int)((unsigned int)((int)((unsigned int)v959 >> 2)) >> 1))))) >> 31)) & 1);
      int v993 = v992[v1118];
      int * v994 = v955->cache_age;
      int v995 = v994[v1096];
      int * v996 = v955->cache_age;
      int v1121 = v995 + ((int)((unsigned int)(v995 - v993) >> 31));
      v996[v1096] = v1121;
      int * v998 = v955->cache_age;
      int v999 = v998[v1098];
      int * v1000 = v955->cache_age;
      int v1124 = v999 + ((int)((unsigned int)(v999 - v993) >> 31));
      v1000[v1098] = v1124;
      int * v1002 = v955->cache_age;
      v1002[v1118] = 0;
      v1055 = v1118;
    } else {
      int * v1005 = v955->cache_age;
      int v1128 = 4 + ((((int)((unsigned int)((int)((unsigned int)v959 >> 2)) >> 1)) & 3) * 2);
      int v1006 = v1005[v1128];
      int * v1007 = v955->cache_tags;
      int v1008 = v1007[v1128];
      int * v1009 = v955->cache_age;
      int v1010 = v1009[v1098];
      int * v1011 = v955->cache_tags;
      int v1012 = v1011[v1098];
      int * v1013 = v955->cache_dirty;
      int v1133 = (4 + ((((int)((unsigned int)((int)((unsigned int)v959 >> 2)) >> 1)) & 3) * 2)) + ((((v1006 + ((~(((v1008 ^ -1) | (-(v1008 ^ -1))) >> 31)) & 2)) - (v1010 + ((~(((v1012 ^ -1) | (-(v1012 ^ -1))) >> 31)) & 2))) >> 31) & 1);
      int v1014 = v1013[v1133];
      bool v1134 = !(v1014 == 0);
      if (v1134) {
        int * v1015 = v955->cache_tags;
        int v1016 = v1015[v1133];
        int * v1017 = v955->cache_vals;
        int v1137 = ((4 + ((((int)((unsigned int)((int)((unsigned int)v959 >> 2)) >> 1)) & 3) * 2)) + ((((v1006 + ((~(((v1008 ^ -1) | (-(v1008 ^ -1))) >> 31)) & 2)) - (v1010 + ((~(((v1012 ^ -1) | (-(v1012 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
        int v1018 = v1017[v1137];
        int * v1019 = v955->cache_vals;
        int v1139 = (((4 + ((((int)((unsigned int)((int)((unsigned int)v959 >> 2)) >> 1)) & 3) * 2)) + ((((v1006 + ((~(((v1008 ^ -1) | (-(v1008 ^ -1))) >> 31)) & 2)) - (v1010 + ((~(((v1012 ^ -1) | (-(v1012 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
        int v1020 = v1019[v1139];
        int * v1021 = v955->mem;
        int v1141 = v1016 * 2;
        v1021[v1141] = v1018;
        int * v1023 = v955->mem;
        int v1144 = (v1016 * 2) + 1;
        v1023[v1144] = v1020;
        ;
      } else {
        ;
      }
      int * v1028 = v955->mem;
      int v1149 = ((int)((unsigned int)((int)((unsigned int)v959 >> 2)) >> 1)) * 2;
      int v1029 = v1028[v1149];
      int * v1030 = v955->mem;
      int v1151 = (((int)((unsigned int)((int)((unsigned int)v959 >> 2)) >> 1)) * 2) + 1;
      int v1031 = v1030[v1151];
      int * v1032 = v955->cache_vals;
      int v1153 = ((4 + ((((int)((unsigned int)((int)((unsigned int)v959 >> 2)) >> 1)) & 3) * 2)) + ((((v1006 + ((~(((v1008 ^ -1) | (-(v1008 ^ -1))) >> 31)) & 2)) - (v1010 + ((~(((v1012 ^ -1) | (-(v1012 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
      v1032[v1153] = v1029;
      int * v1034 = v955->cache_vals;
      int v1156 = (((4 + ((((int)((unsigned int)((int)((unsigned int)v959 >> 2)) >> 1)) & 3) * 2)) + ((((v1006 + ((~(((v1008 ^ -1) | (-(v1008 ^ -1))) >> 31)) & 2)) - (v1010 + ((~(((v1012 ^ -1) | (-(v1012 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
      v1034[v1156] = v1031;
      int * v1036 = v955->cache_tags;
      int v1159 = (int)((unsigned int)((int)((unsigned int)v959 >> 2)) >> 1);
      v1036[v1133] = v1159;
      int * v1038 = v955->cache_dirty;
      v1038[v1133] = 0;
      int * v1040 = v955->cache_age;
      v1040[v1133] = 1;
      int * v1042 = v955->cache_age;
      int v1043 = v1042[v1133];
      int * v1044 = v955->cache_age;
      int v1045 = v1044[v1096];
      int * v1046 = v955->cache_age;
      int v1167 = v1045 + ((int)((unsigned int)(v1045 - v1043) >> 31));
      v1046[v1096] = v1167;
      int * v1048 = v955->cache_age;
      int v1049 = v1048[v1098];
      int * v1050 = v955->cache_age;
      int v1170 = v1049 + ((int)((unsigned int)(v1049 - v1043) >> 31));
      v1050[v1098] = v1170;
      int * v1052 = v955->cache_age;
      v1052[v1133] = 0;
      v1055 = v1133;
    }
    int * v1056 = v955->cache_vals;
    int v1173 = v1055 * 2;
    int v1057 = v1056[v1173];
    int * v1058 = v955->cache_vals;
    int v1175 = (v1055 * 2) + 1;
    int v1059 = v1058[v1175];
    int * v1060 = v955->cache_vals;
    int v1177 = (((((int)((unsigned int)((int)((unsigned int)v959 >> 2)) >> 1)) & 1) * 2) + ((((v985 + ((~(((v987 ^ -1) | (-(v987 ^ -1))) >> 31)) & 2)) - (v989 + ((~(((v991 ^ -1) | (-(v991 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
    v1060[v1177] = v1057;
    int * v1062 = v955->cache_vals;
    int v1180 = ((((((int)((unsigned int)((int)((unsigned int)v959 >> 2)) >> 1)) & 1) * 2) + ((((v985 + ((~(((v987 ^ -1) | (-(v987 ^ -1))) >> 31)) & 2)) - (v989 + ((~(((v991 ^ -1) | (-(v991 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
    v1062[v1180] = v1059;
    int * v1064 = v955->cache_tags;
    int v1183 = ((((int)((unsigned int)((int)((unsigned int)v959 >> 2)) >> 1)) & 1) * 2) + ((((v985 + ((~(((v987 ^ -1) | (-(v987 ^ -1))) >> 31)) & 2)) - (v989 + ((~(((v991 ^ -1) | (-(v991 ^ -1))) >> 31)) & 2))) >> 31) & 1);
    int v1184 = (int)((unsigned int)((int)((unsigned int)v959 >> 2)) >> 1);
    v1064[v1183] = v1184;
    int * v1066 = v955->cache_dirty;
    v1066[v1183] = 0;
    int * v1068 = v955->cache_age;
    v1068[v1183] = 1;
    int * v1070 = v955->cache_age;
    int v1071 = v1070[v1183];
    int * v1072 = v955->cache_age;
    int v1073 = v1072[v1092];
    int * v1074 = v955->cache_age;
    int v1192 = v1073 + ((int)((unsigned int)(v1073 - v1071) >> 31));
    v1074[v1092] = v1192;
    int * v1076 = v955->cache_age;
    int v1077 = v1076[v1094];
    int * v1078 = v955->cache_age;
    int v1195 = v1077 + ((int)((unsigned int)(v1077 - v1071) >> 31));
    v1078[v1094] = v1195;
    int * v1080 = v955->cache_age;
    v1080[v1183] = 0;
    v1083 = v1183;
  }
  int v1198 = (v1083 * 2) + (((int)((unsigned int)v959 >> 2)) & 1);
  int v1084 = v970[v1198];
  int * v1085 = v955->regs;
  v1085[12] = v1084;
  return v955;
}

struct StateT * slot_6(struct StateT * v689) {
  int v690 = v689->timer;
  int v698 = v690 + 1;
  v689->timer = v698;
  int * v692 = v689->regs;
  int v693 = v692[7];
  int * v694 = v689->regs;
  int v702 = v693 + 1;
  v694[7] = v702;
  struct StateT * v696 = slot_7(v689);
  return v696;
}

struct StateT * slot_5(struct StateT * v676) {
  int v677 = v676->timer;
  int v683 = v677 + 1;
  v676->timer = v683;
  int * v679 = v676->regs;
  v679[7] = 0;
  struct StateT * v681 = slot_6(v676);
  return v681;
}

struct StateT * slot_4(struct StateT * v291) {
  int v292 = v291->timer;
  int v497 = v292 + 1;
  v291->timer = v497;
  int * v294 = v291->regs;
  int v295 = v294[8];
  int * v296 = v291->regs;
  int v297 = v296[5];
  int * v298 = v291->cache_tags;
  int v503 = (((int)((unsigned int)((int)((unsigned int)v295 >> 2)) >> 1)) & 1) * 2;
  int v299 = v298[v503];
  int * v300 = v291->cache_tags;
  int v505 = ((((int)((unsigned int)((int)((unsigned int)v295 >> 2)) >> 1)) & 1) * 2) + 1;
  int v301 = v300[v505];
  int * v302 = v291->cache_tags;
  int v507 = 4 + ((((int)((unsigned int)((int)((unsigned int)v295 >> 2)) >> 1)) & 3) * 2);
  int v303 = v302[v507];
  int * v304 = v291->cache_tags;
  int v509 = (4 + ((((int)((unsigned int)((int)((unsigned int)v295 >> 2)) >> 1)) & 3) * 2)) + 1;
  int v305 = v304[v509];
  int v306 = v291->timer;
  int v510 = v306 + ((100 ^ (((~(((v303 ^ ((int)((unsigned int)((int)((unsigned int)v295 >> 2)) >> 1))) | (-(v303 ^ ((int)((unsigned int)((int)((unsigned int)v295 >> 2)) >> 1))))) >> 31)) | (~(((v305 ^ ((int)((unsigned int)((int)((unsigned int)v295 >> 2)) >> 1))) | (-(v305 ^ ((int)((unsigned int)((int)((unsigned int)v295 >> 2)) >> 1))))) >> 31))) & 104)) ^ (((~(((v299 ^ ((int)((unsigned int)((int)((unsigned int)v295 >> 2)) >> 1))) | (-(v299 ^ ((int)((unsigned int)((int)((unsigned int)v295 >> 2)) >> 1))))) >> 31)) | (~(((v301 ^ ((int)((unsigned int)((int)((unsigned int)v295 >> 2)) >> 1))) | (-(v301 ^ ((int)((unsigned int)((int)((unsigned int)v295 >> 2)) >> 1))))) >> 31))) & (1 ^ (100 ^ (((~(((v303 ^ ((int)((unsigned int)((int)((unsigned int)v295 >> 2)) >> 1))) | (-(v303 ^ ((int)((unsigned int)((int)((unsigned int)v295 >> 2)) >> 1))))) >> 31)) | (~(((v305 ^ ((int)((unsigned int)((int)((unsigned int)v295 >> 2)) >> 1))) | (-(v305 ^ ((int)((unsigned int)((int)((unsigned int)v295 >> 2)) >> 1))))) >> 31))) & 104)))));
  v291->timer = v510;
  bool v511 = !(((~(((v299 ^ ((int)((unsigned int)((int)((unsigned int)v295 >> 2)) >> 1))) | (-(v299 ^ ((int)((unsigned int)((int)((unsigned int)v295 >> 2)) >> 1))))) >> 31)) | (~(((v301 ^ ((int)((unsigned int)((int)((unsigned int)v295 >> 2)) >> 1))) | (-(v301 ^ ((int)((unsigned int)((int)((unsigned int)v295 >> 2)) >> 1))))) >> 31))) == 0);
  int v420;
  if (v511) {
    int * v308 = v291->cache_age;
    int v513 = ((((int)((unsigned int)((int)((unsigned int)v295 >> 2)) >> 1)) & 1) * 2) + ((~(((v301 ^ ((int)((unsigned int)((int)((unsigned int)v295 >> 2)) >> 1))) | (-(v301 ^ ((int)((unsigned int)((int)((unsigned int)v295 >> 2)) >> 1))))) >> 31)) & 1);
    int v309 = v308[v513];
    int * v310 = v291->cache_age;
    int v311 = v310[v503];
    int * v312 = v291->cache_age;
    int v516 = v311 + ((int)((unsigned int)(v311 - v309) >> 31));
    v312[v503] = v516;
    int * v314 = v291->cache_age;
    int v315 = v314[v505];
    int * v316 = v291->cache_age;
    int v519 = v315 + ((int)((unsigned int)(v315 - v309) >> 31));
    v316[v505] = v519;
    int * v318 = v291->cache_age;
    v318[v513] = 0;
    v420 = v513;
  } else {
    int * v321 = v291->cache_age;
    int v523 = (((int)((unsigned int)((int)((unsigned int)v295 >> 2)) >> 1)) & 1) * 2;
    int v322 = v321[v523];
    int * v323 = v291->cache_tags;
    int v324 = v323[v523];
    int * v325 = v291->cache_age;
    int v326 = v325[v505];
    int * v327 = v291->cache_tags;
    int v328 = v327[v505];
    bool v527 = !(((~(((v303 ^ ((int)((unsigned int)((int)((unsigned int)v295 >> 2)) >> 1))) | (-(v303 ^ ((int)((unsigned int)((int)((unsigned int)v295 >> 2)) >> 1))))) >> 31)) | (~(((v305 ^ ((int)((unsigned int)((int)((unsigned int)v295 >> 2)) >> 1))) | (-(v305 ^ ((int)((unsigned int)((int)((unsigned int)v295 >> 2)) >> 1))))) >> 31))) == 0);
    int v392;
    if (v527) {
      int * v329 = v291->cache_age;
      int v529 = (4 + ((((int)((unsigned int)((int)((unsigned int)v295 >> 2)) >> 1)) & 3) * 2)) + ((~(((v305 ^ ((int)((unsigned int)((int)((unsigned int)v295 >> 2)) >> 1))) | (-(v305 ^ ((int)((unsigned int)((int)((unsigned int)v295 >> 2)) >> 1))))) >> 31)) & 1);
      int v330 = v329[v529];
      int * v331 = v291->cache_age;
      int v332 = v331[v507];
      int * v333 = v291->cache_age;
      int v532 = v332 + ((int)((unsigned int)(v332 - v330) >> 31));
      v333[v507] = v532;
      int * v335 = v291->cache_age;
      int v336 = v335[v509];
      int * v337 = v291->cache_age;
      int v535 = v336 + ((int)((unsigned int)(v336 - v330) >> 31));
      v337[v509] = v535;
      int * v339 = v291->cache_age;
      v339[v529] = 0;
      v392 = v529;
    } else {
      int * v342 = v291->cache_age;
      int v539 = 4 + ((((int)((unsigned int)((int)((unsigned int)v295 >> 2)) >> 1)) & 3) * 2);
      int v343 = v342[v539];
      int * v344 = v291->cache_tags;
      int v345 = v344[v539];
      int * v346 = v291->cache_age;
      int v347 = v346[v509];
      int * v348 = v291->cache_tags;
      int v349 = v348[v509];
      int * v350 = v291->cache_dirty;
      int v544 = (4 + ((((int)((unsigned int)((int)((unsigned int)v295 >> 2)) >> 1)) & 3) * 2)) + ((((v343 + ((~(((v345 ^ -1) | (-(v345 ^ -1))) >> 31)) & 2)) - (v347 + ((~(((v349 ^ -1) | (-(v349 ^ -1))) >> 31)) & 2))) >> 31) & 1);
      int v351 = v350[v544];
      bool v545 = !(v351 == 0);
      if (v545) {
        int * v352 = v291->cache_tags;
        int v353 = v352[v544];
        int * v354 = v291->cache_vals;
        int v548 = ((4 + ((((int)((unsigned int)((int)((unsigned int)v295 >> 2)) >> 1)) & 3) * 2)) + ((((v343 + ((~(((v345 ^ -1) | (-(v345 ^ -1))) >> 31)) & 2)) - (v347 + ((~(((v349 ^ -1) | (-(v349 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
        int v355 = v354[v548];
        int * v356 = v291->cache_vals;
        int v550 = (((4 + ((((int)((unsigned int)((int)((unsigned int)v295 >> 2)) >> 1)) & 3) * 2)) + ((((v343 + ((~(((v345 ^ -1) | (-(v345 ^ -1))) >> 31)) & 2)) - (v347 + ((~(((v349 ^ -1) | (-(v349 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
        int v357 = v356[v550];
        int * v358 = v291->mem;
        int v552 = v353 * 2;
        v358[v552] = v355;
        int * v360 = v291->mem;
        int v555 = (v353 * 2) + 1;
        v360[v555] = v357;
        ;
      } else {
        ;
      }
      int * v365 = v291->mem;
      int v560 = ((int)((unsigned int)((int)((unsigned int)v295 >> 2)) >> 1)) * 2;
      int v366 = v365[v560];
      int * v367 = v291->mem;
      int v562 = (((int)((unsigned int)((int)((unsigned int)v295 >> 2)) >> 1)) * 2) + 1;
      int v368 = v367[v562];
      int * v369 = v291->cache_vals;
      int v564 = ((4 + ((((int)((unsigned int)((int)((unsigned int)v295 >> 2)) >> 1)) & 3) * 2)) + ((((v343 + ((~(((v345 ^ -1) | (-(v345 ^ -1))) >> 31)) & 2)) - (v347 + ((~(((v349 ^ -1) | (-(v349 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
      v369[v564] = v366;
      int * v371 = v291->cache_vals;
      int v567 = (((4 + ((((int)((unsigned int)((int)((unsigned int)v295 >> 2)) >> 1)) & 3) * 2)) + ((((v343 + ((~(((v345 ^ -1) | (-(v345 ^ -1))) >> 31)) & 2)) - (v347 + ((~(((v349 ^ -1) | (-(v349 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
      v371[v567] = v368;
      int * v373 = v291->cache_tags;
      int v570 = (int)((unsigned int)((int)((unsigned int)v295 >> 2)) >> 1);
      v373[v544] = v570;
      int * v375 = v291->cache_dirty;
      v375[v544] = 0;
      int * v377 = v291->cache_age;
      v377[v544] = 1;
      int * v379 = v291->cache_age;
      int v380 = v379[v544];
      int * v381 = v291->cache_age;
      int v382 = v381[v507];
      int * v383 = v291->cache_age;
      int v578 = v382 + ((int)((unsigned int)(v382 - v380) >> 31));
      v383[v507] = v578;
      int * v385 = v291->cache_age;
      int v386 = v385[v509];
      int * v387 = v291->cache_age;
      int v581 = v386 + ((int)((unsigned int)(v386 - v380) >> 31));
      v387[v509] = v581;
      int * v389 = v291->cache_age;
      v389[v544] = 0;
      v392 = v544;
    }
    int * v393 = v291->cache_vals;
    int v584 = v392 * 2;
    int v394 = v393[v584];
    int * v395 = v291->cache_vals;
    int v586 = (v392 * 2) + 1;
    int v396 = v395[v586];
    int * v397 = v291->cache_vals;
    int v588 = (((((int)((unsigned int)((int)((unsigned int)v295 >> 2)) >> 1)) & 1) * 2) + ((((v322 + ((~(((v324 ^ -1) | (-(v324 ^ -1))) >> 31)) & 2)) - (v326 + ((~(((v328 ^ -1) | (-(v328 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
    v397[v588] = v394;
    int * v399 = v291->cache_vals;
    int v591 = ((((((int)((unsigned int)((int)((unsigned int)v295 >> 2)) >> 1)) & 1) * 2) + ((((v322 + ((~(((v324 ^ -1) | (-(v324 ^ -1))) >> 31)) & 2)) - (v326 + ((~(((v328 ^ -1) | (-(v328 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
    v399[v591] = v396;
    int * v401 = v291->cache_tags;
    int v594 = ((((int)((unsigned int)((int)((unsigned int)v295 >> 2)) >> 1)) & 1) * 2) + ((((v322 + ((~(((v324 ^ -1) | (-(v324 ^ -1))) >> 31)) & 2)) - (v326 + ((~(((v328 ^ -1) | (-(v328 ^ -1))) >> 31)) & 2))) >> 31) & 1);
    int v595 = (int)((unsigned int)((int)((unsigned int)v295 >> 2)) >> 1);
    v401[v594] = v595;
    int * v403 = v291->cache_dirty;
    v403[v594] = 0;
    int * v405 = v291->cache_age;
    v405[v594] = 1;
    int * v407 = v291->cache_age;
    int v408 = v407[v594];
    int * v409 = v291->cache_age;
    int v410 = v409[v503];
    int * v411 = v291->cache_age;
    int v603 = v410 + ((int)((unsigned int)(v410 - v408) >> 31));
    v411[v503] = v603;
    int * v413 = v291->cache_age;
    int v414 = v413[v505];
    int * v415 = v291->cache_age;
    int v606 = v414 + ((int)((unsigned int)(v414 - v408) >> 31));
    v415[v505] = v606;
    int * v417 = v291->cache_age;
    v417[v594] = 0;
    v420 = v594;
  }
  int * v421 = v291->cache_vals;
  int v609 = (v420 * 2) + (((int)((unsigned int)v295 >> 2)) & 1);
  v421[v609] = v297;
  int * v423 = v291->cache_tags;
  int v424 = v423[v507];
  int * v425 = v291->cache_tags;
  int v426 = v425[v509];
  bool v613 = !(((~(((v424 ^ ((int)((unsigned int)((int)((unsigned int)v295 >> 2)) >> 1))) | (-(v424 ^ ((int)((unsigned int)((int)((unsigned int)v295 >> 2)) >> 1))))) >> 31)) | (~(((v426 ^ ((int)((unsigned int)((int)((unsigned int)v295 >> 2)) >> 1))) | (-(v426 ^ ((int)((unsigned int)((int)((unsigned int)v295 >> 2)) >> 1))))) >> 31))) == 0);
  int v490;
  if (v613) {
    int * v427 = v291->cache_age;
    int v615 = (4 + ((((int)((unsigned int)((int)((unsigned int)v295 >> 2)) >> 1)) & 3) * 2)) + ((~(((v426 ^ ((int)((unsigned int)((int)((unsigned int)v295 >> 2)) >> 1))) | (-(v426 ^ ((int)((unsigned int)((int)((unsigned int)v295 >> 2)) >> 1))))) >> 31)) & 1);
    int v428 = v427[v615];
    int * v429 = v291->cache_age;
    int v430 = v429[v507];
    int * v431 = v291->cache_age;
    int v618 = v430 + ((int)((unsigned int)(v430 - v428) >> 31));
    v431[v507] = v618;
    int * v433 = v291->cache_age;
    int v434 = v433[v509];
    int * v435 = v291->cache_age;
    int v621 = v434 + ((int)((unsigned int)(v434 - v428) >> 31));
    v435[v509] = v621;
    int * v437 = v291->cache_age;
    v437[v615] = 0;
    v490 = v615;
  } else {
    int * v440 = v291->cache_age;
    int v625 = 4 + ((((int)((unsigned int)((int)((unsigned int)v295 >> 2)) >> 1)) & 3) * 2);
    int v441 = v440[v625];
    int * v442 = v291->cache_tags;
    int v443 = v442[v625];
    int * v444 = v291->cache_age;
    int v445 = v444[v509];
    int * v446 = v291->cache_tags;
    int v447 = v446[v509];
    int * v448 = v291->cache_dirty;
    int v630 = (4 + ((((int)((unsigned int)((int)((unsigned int)v295 >> 2)) >> 1)) & 3) * 2)) + ((((v441 + ((~(((v443 ^ -1) | (-(v443 ^ -1))) >> 31)) & 2)) - (v445 + ((~(((v447 ^ -1) | (-(v447 ^ -1))) >> 31)) & 2))) >> 31) & 1);
    int v449 = v448[v630];
    bool v631 = !(v449 == 0);
    if (v631) {
      int * v450 = v291->cache_tags;
      int v451 = v450[v630];
      int * v452 = v291->cache_vals;
      int v634 = ((4 + ((((int)((unsigned int)((int)((unsigned int)v295 >> 2)) >> 1)) & 3) * 2)) + ((((v441 + ((~(((v443 ^ -1) | (-(v443 ^ -1))) >> 31)) & 2)) - (v445 + ((~(((v447 ^ -1) | (-(v447 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
      int v453 = v452[v634];
      int * v454 = v291->cache_vals;
      int v636 = (((4 + ((((int)((unsigned int)((int)((unsigned int)v295 >> 2)) >> 1)) & 3) * 2)) + ((((v441 + ((~(((v443 ^ -1) | (-(v443 ^ -1))) >> 31)) & 2)) - (v445 + ((~(((v447 ^ -1) | (-(v447 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
      int v455 = v454[v636];
      int * v456 = v291->mem;
      int v638 = v451 * 2;
      v456[v638] = v453;
      int * v458 = v291->mem;
      int v641 = (v451 * 2) + 1;
      v458[v641] = v455;
      ;
    } else {
      ;
    }
    int * v463 = v291->mem;
    int v646 = ((int)((unsigned int)((int)((unsigned int)v295 >> 2)) >> 1)) * 2;
    int v464 = v463[v646];
    int * v465 = v291->mem;
    int v648 = (((int)((unsigned int)((int)((unsigned int)v295 >> 2)) >> 1)) * 2) + 1;
    int v466 = v465[v648];
    int * v467 = v291->cache_vals;
    int v650 = ((4 + ((((int)((unsigned int)((int)((unsigned int)v295 >> 2)) >> 1)) & 3) * 2)) + ((((v441 + ((~(((v443 ^ -1) | (-(v443 ^ -1))) >> 31)) & 2)) - (v445 + ((~(((v447 ^ -1) | (-(v447 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
    v467[v650] = v464;
    int * v469 = v291->cache_vals;
    int v653 = (((4 + ((((int)((unsigned int)((int)((unsigned int)v295 >> 2)) >> 1)) & 3) * 2)) + ((((v441 + ((~(((v443 ^ -1) | (-(v443 ^ -1))) >> 31)) & 2)) - (v445 + ((~(((v447 ^ -1) | (-(v447 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
    v469[v653] = v466;
    int * v471 = v291->cache_tags;
    int v656 = (int)((unsigned int)((int)((unsigned int)v295 >> 2)) >> 1);
    v471[v630] = v656;
    int * v473 = v291->cache_dirty;
    v473[v630] = 0;
    int * v475 = v291->cache_age;
    v475[v630] = 1;
    int * v477 = v291->cache_age;
    int v478 = v477[v630];
    int * v479 = v291->cache_age;
    int v480 = v479[v507];
    int * v481 = v291->cache_age;
    int v664 = v480 + ((int)((unsigned int)(v480 - v478) >> 31));
    v481[v507] = v664;
    int * v483 = v291->cache_age;
    int v484 = v483[v509];
    int * v485 = v291->cache_age;
    int v667 = v484 + ((int)((unsigned int)(v484 - v478) >> 31));
    v485[v509] = v667;
    int * v487 = v291->cache_age;
    v487[v630] = 0;
    v490 = v630;
  }
  int * v491 = v291->cache_vals;
  int v670 = (v490 * 2) + (((int)((unsigned int)v295 >> 2)) & 1);
  v491[v670] = v297;
  int * v493 = v291->cache_dirty;
  v493[v490] = 1;
  struct StateT * v495 = slot_5(v291);
  return v495;
}

struct StateT * slot_2(struct StateT * v265) {
  int v266 = v265->timer;
  int v272 = v266 + 1;
  v265->timer = v272;
  int * v268 = v265->regs;
  v268[8] = 96;
  struct StateT * v270 = slot_3(v265);
  return v270;
}

struct StateT * slot_7(struct StateT * v705) {
  int v706 = v705->timer;
  int v839 = v706 + 1;
  v705->timer = v839;
  int * v708 = v705->regs;
  int v709 = v708[9];
  int * v710 = v705->cache_tags;
  int v843 = (((int)((unsigned int)((int)((unsigned int)v709 >> 2)) >> 1)) & 1) * 2;
  int v711 = v710[v843];
  int * v712 = v705->cache_tags;
  int v845 = ((((int)((unsigned int)((int)((unsigned int)v709 >> 2)) >> 1)) & 1) * 2) + 1;
  int v713 = v712[v845];
  int * v714 = v705->cache_tags;
  int v847 = 4 + ((((int)((unsigned int)((int)((unsigned int)v709 >> 2)) >> 1)) & 3) * 2);
  int v715 = v714[v847];
  int * v716 = v705->cache_tags;
  int v849 = (4 + ((((int)((unsigned int)((int)((unsigned int)v709 >> 2)) >> 1)) & 3) * 2)) + 1;
  int v717 = v716[v849];
  int v718 = v705->timer;
  int v850 = v718 + ((100 ^ (((~(((v715 ^ ((int)((unsigned int)((int)((unsigned int)v709 >> 2)) >> 1))) | (-(v715 ^ ((int)((unsigned int)((int)((unsigned int)v709 >> 2)) >> 1))))) >> 31)) | (~(((v717 ^ ((int)((unsigned int)((int)((unsigned int)v709 >> 2)) >> 1))) | (-(v717 ^ ((int)((unsigned int)((int)((unsigned int)v709 >> 2)) >> 1))))) >> 31))) & 104)) ^ (((~(((v711 ^ ((int)((unsigned int)((int)((unsigned int)v709 >> 2)) >> 1))) | (-(v711 ^ ((int)((unsigned int)((int)((unsigned int)v709 >> 2)) >> 1))))) >> 31)) | (~(((v713 ^ ((int)((unsigned int)((int)((unsigned int)v709 >> 2)) >> 1))) | (-(v713 ^ ((int)((unsigned int)((int)((unsigned int)v709 >> 2)) >> 1))))) >> 31))) & (1 ^ (100 ^ (((~(((v715 ^ ((int)((unsigned int)((int)((unsigned int)v709 >> 2)) >> 1))) | (-(v715 ^ ((int)((unsigned int)((int)((unsigned int)v709 >> 2)) >> 1))))) >> 31)) | (~(((v717 ^ ((int)((unsigned int)((int)((unsigned int)v709 >> 2)) >> 1))) | (-(v717 ^ ((int)((unsigned int)((int)((unsigned int)v709 >> 2)) >> 1))))) >> 31))) & 104)))));
  v705->timer = v850;
  int * v720 = v705->cache_vals;
  bool v851 = !(((~(((v711 ^ ((int)((unsigned int)((int)((unsigned int)v709 >> 2)) >> 1))) | (-(v711 ^ ((int)((unsigned int)((int)((unsigned int)v709 >> 2)) >> 1))))) >> 31)) | (~(((v713 ^ ((int)((unsigned int)((int)((unsigned int)v709 >> 2)) >> 1))) | (-(v713 ^ ((int)((unsigned int)((int)((unsigned int)v709 >> 2)) >> 1))))) >> 31))) == 0);
  int v833;
  if (v851) {
    int * v721 = v705->cache_age;
    int v853 = ((((int)((unsigned int)((int)((unsigned int)v709 >> 2)) >> 1)) & 1) * 2) + ((~(((v713 ^ ((int)((unsigned int)((int)((unsigned int)v709 >> 2)) >> 1))) | (-(v713 ^ ((int)((unsigned int)((int)((unsigned int)v709 >> 2)) >> 1))))) >> 31)) & 1);
    int v722 = v721[v853];
    int * v723 = v705->cache_age;
    int v724 = v723[v843];
    int * v725 = v705->cache_age;
    int v856 = v724 + ((int)((unsigned int)(v724 - v722) >> 31));
    v725[v843] = v856;
    int * v727 = v705->cache_age;
    int v728 = v727[v845];
    int * v729 = v705->cache_age;
    int v859 = v728 + ((int)((unsigned int)(v728 - v722) >> 31));
    v729[v845] = v859;
    int * v731 = v705->cache_age;
    v731[v853] = 0;
    v833 = v853;
  } else {
    int * v734 = v705->cache_age;
    int v863 = (((int)((unsigned int)((int)((unsigned int)v709 >> 2)) >> 1)) & 1) * 2;
    int v735 = v734[v863];
    int * v736 = v705->cache_tags;
    int v737 = v736[v863];
    int * v738 = v705->cache_age;
    int v739 = v738[v845];
    int * v740 = v705->cache_tags;
    int v741 = v740[v845];
    bool v867 = !(((~(((v715 ^ ((int)((unsigned int)((int)((unsigned int)v709 >> 2)) >> 1))) | (-(v715 ^ ((int)((unsigned int)((int)((unsigned int)v709 >> 2)) >> 1))))) >> 31)) | (~(((v717 ^ ((int)((unsigned int)((int)((unsigned int)v709 >> 2)) >> 1))) | (-(v717 ^ ((int)((unsigned int)((int)((unsigned int)v709 >> 2)) >> 1))))) >> 31))) == 0);
    int v805;
    if (v867) {
      int * v742 = v705->cache_age;
      int v869 = (4 + ((((int)((unsigned int)((int)((unsigned int)v709 >> 2)) >> 1)) & 3) * 2)) + ((~(((v717 ^ ((int)((unsigned int)((int)((unsigned int)v709 >> 2)) >> 1))) | (-(v717 ^ ((int)((unsigned int)((int)((unsigned int)v709 >> 2)) >> 1))))) >> 31)) & 1);
      int v743 = v742[v869];
      int * v744 = v705->cache_age;
      int v745 = v744[v847];
      int * v746 = v705->cache_age;
      int v872 = v745 + ((int)((unsigned int)(v745 - v743) >> 31));
      v746[v847] = v872;
      int * v748 = v705->cache_age;
      int v749 = v748[v849];
      int * v750 = v705->cache_age;
      int v875 = v749 + ((int)((unsigned int)(v749 - v743) >> 31));
      v750[v849] = v875;
      int * v752 = v705->cache_age;
      v752[v869] = 0;
      v805 = v869;
    } else {
      int * v755 = v705->cache_age;
      int v879 = 4 + ((((int)((unsigned int)((int)((unsigned int)v709 >> 2)) >> 1)) & 3) * 2);
      int v756 = v755[v879];
      int * v757 = v705->cache_tags;
      int v758 = v757[v879];
      int * v759 = v705->cache_age;
      int v760 = v759[v849];
      int * v761 = v705->cache_tags;
      int v762 = v761[v849];
      int * v763 = v705->cache_dirty;
      int v884 = (4 + ((((int)((unsigned int)((int)((unsigned int)v709 >> 2)) >> 1)) & 3) * 2)) + ((((v756 + ((~(((v758 ^ -1) | (-(v758 ^ -1))) >> 31)) & 2)) - (v760 + ((~(((v762 ^ -1) | (-(v762 ^ -1))) >> 31)) & 2))) >> 31) & 1);
      int v764 = v763[v884];
      bool v885 = !(v764 == 0);
      if (v885) {
        int * v765 = v705->cache_tags;
        int v766 = v765[v884];
        int * v767 = v705->cache_vals;
        int v888 = ((4 + ((((int)((unsigned int)((int)((unsigned int)v709 >> 2)) >> 1)) & 3) * 2)) + ((((v756 + ((~(((v758 ^ -1) | (-(v758 ^ -1))) >> 31)) & 2)) - (v760 + ((~(((v762 ^ -1) | (-(v762 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
        int v768 = v767[v888];
        int * v769 = v705->cache_vals;
        int v890 = (((4 + ((((int)((unsigned int)((int)((unsigned int)v709 >> 2)) >> 1)) & 3) * 2)) + ((((v756 + ((~(((v758 ^ -1) | (-(v758 ^ -1))) >> 31)) & 2)) - (v760 + ((~(((v762 ^ -1) | (-(v762 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
        int v770 = v769[v890];
        int * v771 = v705->mem;
        int v892 = v766 * 2;
        v771[v892] = v768;
        int * v773 = v705->mem;
        int v895 = (v766 * 2) + 1;
        v773[v895] = v770;
        ;
      } else {
        ;
      }
      int * v778 = v705->mem;
      int v900 = ((int)((unsigned int)((int)((unsigned int)v709 >> 2)) >> 1)) * 2;
      int v779 = v778[v900];
      int * v780 = v705->mem;
      int v902 = (((int)((unsigned int)((int)((unsigned int)v709 >> 2)) >> 1)) * 2) + 1;
      int v781 = v780[v902];
      int * v782 = v705->cache_vals;
      int v904 = ((4 + ((((int)((unsigned int)((int)((unsigned int)v709 >> 2)) >> 1)) & 3) * 2)) + ((((v756 + ((~(((v758 ^ -1) | (-(v758 ^ -1))) >> 31)) & 2)) - (v760 + ((~(((v762 ^ -1) | (-(v762 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
      v782[v904] = v779;
      int * v784 = v705->cache_vals;
      int v907 = (((4 + ((((int)((unsigned int)((int)((unsigned int)v709 >> 2)) >> 1)) & 3) * 2)) + ((((v756 + ((~(((v758 ^ -1) | (-(v758 ^ -1))) >> 31)) & 2)) - (v760 + ((~(((v762 ^ -1) | (-(v762 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
      v784[v907] = v781;
      int * v786 = v705->cache_tags;
      int v910 = (int)((unsigned int)((int)((unsigned int)v709 >> 2)) >> 1);
      v786[v884] = v910;
      int * v788 = v705->cache_dirty;
      v788[v884] = 0;
      int * v790 = v705->cache_age;
      v790[v884] = 1;
      int * v792 = v705->cache_age;
      int v793 = v792[v884];
      int * v794 = v705->cache_age;
      int v795 = v794[v847];
      int * v796 = v705->cache_age;
      int v918 = v795 + ((int)((unsigned int)(v795 - v793) >> 31));
      v796[v847] = v918;
      int * v798 = v705->cache_age;
      int v799 = v798[v849];
      int * v800 = v705->cache_age;
      int v921 = v799 + ((int)((unsigned int)(v799 - v793) >> 31));
      v800[v849] = v921;
      int * v802 = v705->cache_age;
      v802[v884] = 0;
      v805 = v884;
    }
    int * v806 = v705->cache_vals;
    int v924 = v805 * 2;
    int v807 = v806[v924];
    int * v808 = v705->cache_vals;
    int v926 = (v805 * 2) + 1;
    int v809 = v808[v926];
    int * v810 = v705->cache_vals;
    int v928 = (((((int)((unsigned int)((int)((unsigned int)v709 >> 2)) >> 1)) & 1) * 2) + ((((v735 + ((~(((v737 ^ -1) | (-(v737 ^ -1))) >> 31)) & 2)) - (v739 + ((~(((v741 ^ -1) | (-(v741 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
    v810[v928] = v807;
    int * v812 = v705->cache_vals;
    int v931 = ((((((int)((unsigned int)((int)((unsigned int)v709 >> 2)) >> 1)) & 1) * 2) + ((((v735 + ((~(((v737 ^ -1) | (-(v737 ^ -1))) >> 31)) & 2)) - (v739 + ((~(((v741 ^ -1) | (-(v741 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
    v812[v931] = v809;
    int * v814 = v705->cache_tags;
    int v934 = ((((int)((unsigned int)((int)((unsigned int)v709 >> 2)) >> 1)) & 1) * 2) + ((((v735 + ((~(((v737 ^ -1) | (-(v737 ^ -1))) >> 31)) & 2)) - (v739 + ((~(((v741 ^ -1) | (-(v741 ^ -1))) >> 31)) & 2))) >> 31) & 1);
    int v935 = (int)((unsigned int)((int)((unsigned int)v709 >> 2)) >> 1);
    v814[v934] = v935;
    int * v816 = v705->cache_dirty;
    v816[v934] = 0;
    int * v818 = v705->cache_age;
    v818[v934] = 1;
    int * v820 = v705->cache_age;
    int v821 = v820[v934];
    int * v822 = v705->cache_age;
    int v823 = v822[v843];
    int * v824 = v705->cache_age;
    int v943 = v823 + ((int)((unsigned int)(v823 - v821) >> 31));
    v824[v843] = v943;
    int * v826 = v705->cache_age;
    int v827 = v826[v845];
    int * v828 = v705->cache_age;
    int v946 = v827 + ((int)((unsigned int)(v827 - v821) >> 31));
    v828[v845] = v946;
    int * v830 = v705->cache_age;
    v830[v934] = 0;
    v833 = v934;
  }
  int v949 = (v833 * 2) + (((int)((unsigned int)v709 >> 2)) & 1);
  int v834 = v720[v949];
  int * v835 = v705->regs;
  v835[11] = v834;
  struct StateT * v837 = slot_8(v705);
  return v837;
}

struct StateT * slot_3(struct StateT * v278) {
  int v279 = v278->timer;
  int v285 = v279 + 1;
  v278->timer = v285;
  int * v281 = v278->regs;
  v281[9] = 0;
  struct StateT * v283 = slot_4(v278);
  return v283;
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