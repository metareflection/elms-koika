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

struct StateT * slot_12(struct StateT * v902);
struct StateT * slot_6(struct StateT * v334);
struct StateT * slot_5(struct StateT * v77);
struct StateT * slot_2(struct StateT * v28);
struct StateT * slot_7(struct StateT * v350);
struct StateT * slot_3(struct StateT * v41);
struct StateT * snippet(struct StateT * v0);
struct StateT * slot_10(struct StateT * v663);
struct StateT * slot_1(struct StateT * v15);
struct StateT * slot_8(struct StateT * v607);
struct StateT * slot_4(struct StateT * v49);
struct StateT * slot_9(struct StateT * v655);
struct StateT * slot_11(struct StateT * v671);
struct StateT * slot_0(struct StateT * v2);
struct StateT * slot_12(struct StateT * v902) {
  int v903 = v902->timer;
  int v1033 = v903 + 1;
  v902->timer = v1033;
  int * v905 = v902->cache_tags;
  int v906 = v905[0];
  int * v907 = v902->cache_tags;
  int v908 = v907[1];
  int * v909 = v902->cache_tags;
  int v910 = v909[4];
  int * v911 = v902->cache_tags;
  int v912 = v911[5];
  int v913 = v902->timer;
  int v1042 = v913 + ((100 ^ (((~((v910 | (-v910)) >> 31)) | (~((v912 | (-v912)) >> 31))) & 104)) ^ (((~((v906 | (-v906)) >> 31)) | (~((v908 | (-v908)) >> 31))) & (1 ^ (100 ^ (((~((v910 | (-v910)) >> 31)) | (~((v912 | (-v912)) >> 31))) & 104)))));
  v902->timer = v1042;
  int * v915 = v902->cache_vals;
  bool v1043 = !(((~((v906 | (-v906)) >> 31)) | (~((v908 | (-v908)) >> 31))) == 0);
  int v1028;
  if (v1043) {
    int * v916 = v902->cache_age;
    int v1045 = (~((v908 | (-v908)) >> 31)) & 1;
    int v917 = v916[v1045];
    int * v918 = v902->cache_age;
    int v919 = v918[0];
    int * v920 = v902->cache_age;
    int v1048 = v919 + ((int)((unsigned int)(v919 - v917) >> 31));
    v920[0] = v1048;
    int * v922 = v902->cache_age;
    int v923 = v922[1];
    int * v924 = v902->cache_age;
    int v1051 = v923 + ((int)((unsigned int)(v923 - v917) >> 31));
    v924[1] = v1051;
    int * v926 = v902->cache_age;
    v926[v1045] = 0;
    v1028 = v1045;
  } else {
    int * v929 = v902->cache_age;
    int v930 = v929[0];
    int * v931 = v902->cache_tags;
    int v932 = v931[0];
    int * v933 = v902->cache_age;
    int v934 = v933[1];
    int * v935 = v902->cache_tags;
    int v936 = v935[1];
    bool v1057 = !(((~((v910 | (-v910)) >> 31)) | (~((v912 | (-v912)) >> 31))) == 0);
    int v1000;
    if (v1057) {
      int * v937 = v902->cache_age;
      int v1059 = 4 + ((~((v912 | (-v912)) >> 31)) & 1);
      int v938 = v937[v1059];
      int * v939 = v902->cache_age;
      int v940 = v939[4];
      int * v941 = v902->cache_age;
      int v1062 = v940 + ((int)((unsigned int)(v940 - v938) >> 31));
      v941[4] = v1062;
      int * v943 = v902->cache_age;
      int v944 = v943[5];
      int * v945 = v902->cache_age;
      int v1065 = v944 + ((int)((unsigned int)(v944 - v938) >> 31));
      v945[5] = v1065;
      int * v947 = v902->cache_age;
      v947[v1059] = 0;
      v1000 = v1059;
    } else {
      int * v950 = v902->cache_age;
      int v951 = v950[4];
      int * v952 = v902->cache_tags;
      int v953 = v952[4];
      int * v954 = v902->cache_age;
      int v955 = v954[5];
      int * v956 = v902->cache_tags;
      int v957 = v956[5];
      int * v958 = v902->cache_dirty;
      int v1072 = 4 + ((((v951 + ((~(((v953 ^ -1) | (-(v953 ^ -1))) >> 31)) & 2)) - (v955 + ((~(((v957 ^ -1) | (-(v957 ^ -1))) >> 31)) & 2))) >> 31) & 1);
      int v959 = v958[v1072];
      bool v1073 = !(v959 == 0);
      if (v1073) {
        int * v960 = v902->cache_tags;
        int v961 = v960[v1072];
        int * v962 = v902->cache_vals;
        int v1076 = (4 + ((((v951 + ((~(((v953 ^ -1) | (-(v953 ^ -1))) >> 31)) & 2)) - (v955 + ((~(((v957 ^ -1) | (-(v957 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
        int v963 = v962[v1076];
        int * v964 = v902->cache_vals;
        int v1078 = ((4 + ((((v951 + ((~(((v953 ^ -1) | (-(v953 ^ -1))) >> 31)) & 2)) - (v955 + ((~(((v957 ^ -1) | (-(v957 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
        int v965 = v964[v1078];
        int * v966 = v902->mem;
        int v1080 = v961 * 2;
        v966[v1080] = v963;
        int * v968 = v902->mem;
        int v1083 = (v961 * 2) + 1;
        v968[v1083] = v965;
        ;
      } else {
        ;
      }
      int * v973 = v902->mem;
      int v974 = v973[0];
      int * v975 = v902->mem;
      int v976 = v975[1];
      int * v977 = v902->cache_vals;
      int v1090 = (4 + ((((v951 + ((~(((v953 ^ -1) | (-(v953 ^ -1))) >> 31)) & 2)) - (v955 + ((~(((v957 ^ -1) | (-(v957 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
      v977[v1090] = v974;
      int * v979 = v902->cache_vals;
      int v1093 = ((4 + ((((v951 + ((~(((v953 ^ -1) | (-(v953 ^ -1))) >> 31)) & 2)) - (v955 + ((~(((v957 ^ -1) | (-(v957 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
      v979[v1093] = v976;
      int * v981 = v902->cache_tags;
      v981[v1072] = 0;
      int * v983 = v902->cache_dirty;
      v983[v1072] = 0;
      int * v985 = v902->cache_age;
      v985[v1072] = 1;
      int * v987 = v902->cache_age;
      int v988 = v987[v1072];
      int * v989 = v902->cache_age;
      int v990 = v989[4];
      int * v991 = v902->cache_age;
      int v1101 = v990 + ((int)((unsigned int)(v990 - v988) >> 31));
      v991[4] = v1101;
      int * v993 = v902->cache_age;
      int v994 = v993[5];
      int * v995 = v902->cache_age;
      int v1104 = v994 + ((int)((unsigned int)(v994 - v988) >> 31));
      v995[5] = v1104;
      int * v997 = v902->cache_age;
      v997[v1072] = 0;
      v1000 = v1072;
    }
    int * v1001 = v902->cache_vals;
    int v1107 = v1000 * 2;
    int v1002 = v1001[v1107];
    int * v1003 = v902->cache_vals;
    int v1109 = (v1000 * 2) + 1;
    int v1004 = v1003[v1109];
    int * v1005 = v902->cache_vals;
    int v1111 = ((((v930 + ((~(((v932 ^ -1) | (-(v932 ^ -1))) >> 31)) & 2)) - (v934 + ((~(((v936 ^ -1) | (-(v936 ^ -1))) >> 31)) & 2))) >> 31) & 1) * 2;
    v1005[v1111] = v1002;
    int * v1007 = v902->cache_vals;
    int v1114 = (((((v930 + ((~(((v932 ^ -1) | (-(v932 ^ -1))) >> 31)) & 2)) - (v934 + ((~(((v936 ^ -1) | (-(v936 ^ -1))) >> 31)) & 2))) >> 31) & 1) * 2) + 1;
    v1007[v1114] = v1004;
    int * v1009 = v902->cache_tags;
    int v1117 = (((v930 + ((~(((v932 ^ -1) | (-(v932 ^ -1))) >> 31)) & 2)) - (v934 + ((~(((v936 ^ -1) | (-(v936 ^ -1))) >> 31)) & 2))) >> 31) & 1;
    v1009[v1117] = 0;
    int * v1011 = v902->cache_dirty;
    v1011[v1117] = 0;
    int * v1013 = v902->cache_age;
    v1013[v1117] = 1;
    int * v1015 = v902->cache_age;
    int v1016 = v1015[v1117];
    int * v1017 = v902->cache_age;
    int v1018 = v1017[0];
    int * v1019 = v902->cache_age;
    int v1123 = v1018 + ((int)((unsigned int)(v1018 - v1016) >> 31));
    v1019[0] = v1123;
    int * v1021 = v902->cache_age;
    int v1022 = v1021[1];
    int * v1023 = v902->cache_age;
    int v1126 = v1022 + ((int)((unsigned int)(v1022 - v1016) >> 31));
    v1023[1] = v1126;
    int * v1025 = v902->cache_age;
    v1025[v1117] = 0;
    v1028 = v1117;
  }
  int v1129 = v1028 * 2;
  int v1029 = v915[v1129];
  int * v1030 = v902->regs;
  v1030[14] = v1029;
  return v902;
}

struct StateT * slot_6(struct StateT * v334) {
  int v335 = v334->timer;
  int v343 = v335 + 1;
  v334->timer = v343;
  int * v337 = v334->regs;
  int v338 = v337[11];
  int * v339 = v334->regs;
  int v347 = v338 << 2;
  v339[11] = v347;
  struct StateT * v341 = slot_7(v334);
  return v341;
}

struct StateT * slot_5(struct StateT * v77) {
  int * v78 = v77->saved_regs;
  int * v79 = v77->regs;
  int v80 = v79[11];
  v78[11] = v80;
  int v82 = v77->timer;
  int v219 = v82 + 1;
  v77->timer = v219;
  int * v84 = v77->regs;
  int v85 = v84[5];
  int * v86 = v77->cache_tags;
  int v223 = (((int)((unsigned int)((int)((unsigned int)v85 >> 2)) >> 1)) & 1) * 2;
  int v87 = v86[v223];
  int * v88 = v77->cache_tags;
  int v225 = ((((int)((unsigned int)((int)((unsigned int)v85 >> 2)) >> 1)) & 1) * 2) + 1;
  int v89 = v88[v225];
  int * v90 = v77->cache_tags;
  int v227 = 4 + ((((int)((unsigned int)((int)((unsigned int)v85 >> 2)) >> 1)) & 3) * 2);
  int v91 = v90[v227];
  int * v92 = v77->cache_tags;
  int v229 = (4 + ((((int)((unsigned int)((int)((unsigned int)v85 >> 2)) >> 1)) & 3) * 2)) + 1;
  int v93 = v92[v229];
  int v94 = v77->timer;
  int v230 = v94 + ((100 ^ (((~(((v91 ^ ((int)((unsigned int)((int)((unsigned int)v85 >> 2)) >> 1))) | (-(v91 ^ ((int)((unsigned int)((int)((unsigned int)v85 >> 2)) >> 1))))) >> 31)) | (~(((v93 ^ ((int)((unsigned int)((int)((unsigned int)v85 >> 2)) >> 1))) | (-(v93 ^ ((int)((unsigned int)((int)((unsigned int)v85 >> 2)) >> 1))))) >> 31))) & 104)) ^ (((~(((v87 ^ ((int)((unsigned int)((int)((unsigned int)v85 >> 2)) >> 1))) | (-(v87 ^ ((int)((unsigned int)((int)((unsigned int)v85 >> 2)) >> 1))))) >> 31)) | (~(((v89 ^ ((int)((unsigned int)((int)((unsigned int)v85 >> 2)) >> 1))) | (-(v89 ^ ((int)((unsigned int)((int)((unsigned int)v85 >> 2)) >> 1))))) >> 31))) & (1 ^ (100 ^ (((~(((v91 ^ ((int)((unsigned int)((int)((unsigned int)v85 >> 2)) >> 1))) | (-(v91 ^ ((int)((unsigned int)((int)((unsigned int)v85 >> 2)) >> 1))))) >> 31)) | (~(((v93 ^ ((int)((unsigned int)((int)((unsigned int)v85 >> 2)) >> 1))) | (-(v93 ^ ((int)((unsigned int)((int)((unsigned int)v85 >> 2)) >> 1))))) >> 31))) & 104)))));
  v77->timer = v230;
  int * v96 = v77->cache_vals;
  bool v231 = !(((~(((v87 ^ ((int)((unsigned int)((int)((unsigned int)v85 >> 2)) >> 1))) | (-(v87 ^ ((int)((unsigned int)((int)((unsigned int)v85 >> 2)) >> 1))))) >> 31)) | (~(((v89 ^ ((int)((unsigned int)((int)((unsigned int)v85 >> 2)) >> 1))) | (-(v89 ^ ((int)((unsigned int)((int)((unsigned int)v85 >> 2)) >> 1))))) >> 31))) == 0);
  int v209;
  if (v231) {
    int * v97 = v77->cache_age;
    int v233 = ((((int)((unsigned int)((int)((unsigned int)v85 >> 2)) >> 1)) & 1) * 2) + ((~(((v89 ^ ((int)((unsigned int)((int)((unsigned int)v85 >> 2)) >> 1))) | (-(v89 ^ ((int)((unsigned int)((int)((unsigned int)v85 >> 2)) >> 1))))) >> 31)) & 1);
    int v98 = v97[v233];
    int * v99 = v77->cache_age;
    int v100 = v99[v223];
    int * v101 = v77->cache_age;
    int v236 = v100 + ((int)((unsigned int)(v100 - v98) >> 31));
    v101[v223] = v236;
    int * v103 = v77->cache_age;
    int v104 = v103[v225];
    int * v105 = v77->cache_age;
    int v239 = v104 + ((int)((unsigned int)(v104 - v98) >> 31));
    v105[v225] = v239;
    int * v107 = v77->cache_age;
    v107[v233] = 0;
    v209 = v233;
  } else {
    int * v110 = v77->cache_age;
    int v243 = (((int)((unsigned int)((int)((unsigned int)v85 >> 2)) >> 1)) & 1) * 2;
    int v111 = v110[v243];
    int * v112 = v77->cache_tags;
    int v113 = v112[v243];
    int * v114 = v77->cache_age;
    int v115 = v114[v225];
    int * v116 = v77->cache_tags;
    int v117 = v116[v225];
    bool v247 = !(((~(((v91 ^ ((int)((unsigned int)((int)((unsigned int)v85 >> 2)) >> 1))) | (-(v91 ^ ((int)((unsigned int)((int)((unsigned int)v85 >> 2)) >> 1))))) >> 31)) | (~(((v93 ^ ((int)((unsigned int)((int)((unsigned int)v85 >> 2)) >> 1))) | (-(v93 ^ ((int)((unsigned int)((int)((unsigned int)v85 >> 2)) >> 1))))) >> 31))) == 0);
    int v181;
    if (v247) {
      int * v118 = v77->cache_age;
      int v249 = (4 + ((((int)((unsigned int)((int)((unsigned int)v85 >> 2)) >> 1)) & 3) * 2)) + ((~(((v93 ^ ((int)((unsigned int)((int)((unsigned int)v85 >> 2)) >> 1))) | (-(v93 ^ ((int)((unsigned int)((int)((unsigned int)v85 >> 2)) >> 1))))) >> 31)) & 1);
      int v119 = v118[v249];
      int * v120 = v77->cache_age;
      int v121 = v120[v227];
      int * v122 = v77->cache_age;
      int v252 = v121 + ((int)((unsigned int)(v121 - v119) >> 31));
      v122[v227] = v252;
      int * v124 = v77->cache_age;
      int v125 = v124[v229];
      int * v126 = v77->cache_age;
      int v255 = v125 + ((int)((unsigned int)(v125 - v119) >> 31));
      v126[v229] = v255;
      int * v128 = v77->cache_age;
      v128[v249] = 0;
      v181 = v249;
    } else {
      int * v131 = v77->cache_age;
      int v259 = 4 + ((((int)((unsigned int)((int)((unsigned int)v85 >> 2)) >> 1)) & 3) * 2);
      int v132 = v131[v259];
      int * v133 = v77->cache_tags;
      int v134 = v133[v259];
      int * v135 = v77->cache_age;
      int v136 = v135[v229];
      int * v137 = v77->cache_tags;
      int v138 = v137[v229];
      int * v139 = v77->cache_dirty;
      int v264 = (4 + ((((int)((unsigned int)((int)((unsigned int)v85 >> 2)) >> 1)) & 3) * 2)) + ((((v132 + ((~(((v134 ^ -1) | (-(v134 ^ -1))) >> 31)) & 2)) - (v136 + ((~(((v138 ^ -1) | (-(v138 ^ -1))) >> 31)) & 2))) >> 31) & 1);
      int v140 = v139[v264];
      bool v265 = !(v140 == 0);
      if (v265) {
        int * v141 = v77->cache_tags;
        int v142 = v141[v264];
        int * v143 = v77->cache_vals;
        int v268 = ((4 + ((((int)((unsigned int)((int)((unsigned int)v85 >> 2)) >> 1)) & 3) * 2)) + ((((v132 + ((~(((v134 ^ -1) | (-(v134 ^ -1))) >> 31)) & 2)) - (v136 + ((~(((v138 ^ -1) | (-(v138 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
        int v144 = v143[v268];
        int * v145 = v77->cache_vals;
        int v270 = (((4 + ((((int)((unsigned int)((int)((unsigned int)v85 >> 2)) >> 1)) & 3) * 2)) + ((((v132 + ((~(((v134 ^ -1) | (-(v134 ^ -1))) >> 31)) & 2)) - (v136 + ((~(((v138 ^ -1) | (-(v138 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
        int v146 = v145[v270];
        int * v147 = v77->mem;
        int v272 = v142 * 2;
        v147[v272] = v144;
        int * v149 = v77->mem;
        int v275 = (v142 * 2) + 1;
        v149[v275] = v146;
        ;
      } else {
        ;
      }
      int * v154 = v77->mem;
      int v280 = ((int)((unsigned int)((int)((unsigned int)v85 >> 2)) >> 1)) * 2;
      int v155 = v154[v280];
      int * v156 = v77->mem;
      int v282 = (((int)((unsigned int)((int)((unsigned int)v85 >> 2)) >> 1)) * 2) + 1;
      int v157 = v156[v282];
      int * v158 = v77->cache_vals;
      int v284 = ((4 + ((((int)((unsigned int)((int)((unsigned int)v85 >> 2)) >> 1)) & 3) * 2)) + ((((v132 + ((~(((v134 ^ -1) | (-(v134 ^ -1))) >> 31)) & 2)) - (v136 + ((~(((v138 ^ -1) | (-(v138 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
      v158[v284] = v155;
      int * v160 = v77->cache_vals;
      int v287 = (((4 + ((((int)((unsigned int)((int)((unsigned int)v85 >> 2)) >> 1)) & 3) * 2)) + ((((v132 + ((~(((v134 ^ -1) | (-(v134 ^ -1))) >> 31)) & 2)) - (v136 + ((~(((v138 ^ -1) | (-(v138 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
      v160[v287] = v157;
      int * v162 = v77->cache_tags;
      int v290 = (int)((unsigned int)((int)((unsigned int)v85 >> 2)) >> 1);
      v162[v264] = v290;
      int * v164 = v77->cache_dirty;
      v164[v264] = 0;
      int * v166 = v77->cache_age;
      v166[v264] = 1;
      int * v168 = v77->cache_age;
      int v169 = v168[v264];
      int * v170 = v77->cache_age;
      int v171 = v170[v227];
      int * v172 = v77->cache_age;
      int v298 = v171 + ((int)((unsigned int)(v171 - v169) >> 31));
      v172[v227] = v298;
      int * v174 = v77->cache_age;
      int v175 = v174[v229];
      int * v176 = v77->cache_age;
      int v301 = v175 + ((int)((unsigned int)(v175 - v169) >> 31));
      v176[v229] = v301;
      int * v178 = v77->cache_age;
      v178[v264] = 0;
      v181 = v264;
    }
    int * v182 = v77->cache_vals;
    int v304 = v181 * 2;
    int v183 = v182[v304];
    int * v184 = v77->cache_vals;
    int v306 = (v181 * 2) + 1;
    int v185 = v184[v306];
    int * v186 = v77->cache_vals;
    int v308 = (((((int)((unsigned int)((int)((unsigned int)v85 >> 2)) >> 1)) & 1) * 2) + ((((v111 + ((~(((v113 ^ -1) | (-(v113 ^ -1))) >> 31)) & 2)) - (v115 + ((~(((v117 ^ -1) | (-(v117 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
    v186[v308] = v183;
    int * v188 = v77->cache_vals;
    int v311 = ((((((int)((unsigned int)((int)((unsigned int)v85 >> 2)) >> 1)) & 1) * 2) + ((((v111 + ((~(((v113 ^ -1) | (-(v113 ^ -1))) >> 31)) & 2)) - (v115 + ((~(((v117 ^ -1) | (-(v117 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
    v188[v311] = v185;
    int * v190 = v77->cache_tags;
    int v314 = ((((int)((unsigned int)((int)((unsigned int)v85 >> 2)) >> 1)) & 1) * 2) + ((((v111 + ((~(((v113 ^ -1) | (-(v113 ^ -1))) >> 31)) & 2)) - (v115 + ((~(((v117 ^ -1) | (-(v117 ^ -1))) >> 31)) & 2))) >> 31) & 1);
    int v315 = (int)((unsigned int)((int)((unsigned int)v85 >> 2)) >> 1);
    v190[v314] = v315;
    int * v192 = v77->cache_dirty;
    v192[v314] = 0;
    int * v194 = v77->cache_age;
    v194[v314] = 1;
    int * v196 = v77->cache_age;
    int v197 = v196[v314];
    int * v198 = v77->cache_age;
    int v199 = v198[v223];
    int * v200 = v77->cache_age;
    int v323 = v199 + ((int)((unsigned int)(v199 - v197) >> 31));
    v200[v223] = v323;
    int * v202 = v77->cache_age;
    int v203 = v202[v225];
    int * v204 = v77->cache_age;
    int v326 = v203 + ((int)((unsigned int)(v203 - v197) >> 31));
    v204[v225] = v326;
    int * v206 = v77->cache_age;
    v206[v314] = 0;
    v209 = v314;
  }
  int v329 = (v209 * 2) + (((int)((unsigned int)v85 >> 2)) & 1);
  int v210 = v96[v329];
  int * v211 = v77->regs;
  v211[11] = v210;
  struct StateT * v213 = slot_6(v77);
  return v213;
}

struct StateT * slot_2(struct StateT * v28) {
  int v29 = v28->timer;
  int v35 = v29 + 1;
  v28->timer = v35;
  int * v31 = v28->regs;
  v31[15] = 80;
  struct StateT * v33 = slot_3(v28);
  return v33;
}

struct StateT * slot_7(struct StateT * v350) {
  int * v351 = v350->saved_regs;
  int * v352 = v350->regs;
  int v353 = v352[12];
  v351[12] = v353;
  int v355 = v350->timer;
  int v492 = v355 + 1;
  v350->timer = v492;
  int * v357 = v350->regs;
  int v358 = v357[11];
  int * v359 = v350->cache_tags;
  int v496 = (((int)((unsigned int)((int)((unsigned int)v358 >> 2)) >> 1)) & 1) * 2;
  int v360 = v359[v496];
  int * v361 = v350->cache_tags;
  int v498 = ((((int)((unsigned int)((int)((unsigned int)v358 >> 2)) >> 1)) & 1) * 2) + 1;
  int v362 = v361[v498];
  int * v363 = v350->cache_tags;
  int v500 = 4 + ((((int)((unsigned int)((int)((unsigned int)v358 >> 2)) >> 1)) & 3) * 2);
  int v364 = v363[v500];
  int * v365 = v350->cache_tags;
  int v502 = (4 + ((((int)((unsigned int)((int)((unsigned int)v358 >> 2)) >> 1)) & 3) * 2)) + 1;
  int v366 = v365[v502];
  int v367 = v350->timer;
  int v503 = v367 + ((100 ^ (((~(((v364 ^ ((int)((unsigned int)((int)((unsigned int)v358 >> 2)) >> 1))) | (-(v364 ^ ((int)((unsigned int)((int)((unsigned int)v358 >> 2)) >> 1))))) >> 31)) | (~(((v366 ^ ((int)((unsigned int)((int)((unsigned int)v358 >> 2)) >> 1))) | (-(v366 ^ ((int)((unsigned int)((int)((unsigned int)v358 >> 2)) >> 1))))) >> 31))) & 104)) ^ (((~(((v360 ^ ((int)((unsigned int)((int)((unsigned int)v358 >> 2)) >> 1))) | (-(v360 ^ ((int)((unsigned int)((int)((unsigned int)v358 >> 2)) >> 1))))) >> 31)) | (~(((v362 ^ ((int)((unsigned int)((int)((unsigned int)v358 >> 2)) >> 1))) | (-(v362 ^ ((int)((unsigned int)((int)((unsigned int)v358 >> 2)) >> 1))))) >> 31))) & (1 ^ (100 ^ (((~(((v364 ^ ((int)((unsigned int)((int)((unsigned int)v358 >> 2)) >> 1))) | (-(v364 ^ ((int)((unsigned int)((int)((unsigned int)v358 >> 2)) >> 1))))) >> 31)) | (~(((v366 ^ ((int)((unsigned int)((int)((unsigned int)v358 >> 2)) >> 1))) | (-(v366 ^ ((int)((unsigned int)((int)((unsigned int)v358 >> 2)) >> 1))))) >> 31))) & 104)))));
  v350->timer = v503;
  int * v369 = v350->cache_vals;
  bool v504 = !(((~(((v360 ^ ((int)((unsigned int)((int)((unsigned int)v358 >> 2)) >> 1))) | (-(v360 ^ ((int)((unsigned int)((int)((unsigned int)v358 >> 2)) >> 1))))) >> 31)) | (~(((v362 ^ ((int)((unsigned int)((int)((unsigned int)v358 >> 2)) >> 1))) | (-(v362 ^ ((int)((unsigned int)((int)((unsigned int)v358 >> 2)) >> 1))))) >> 31))) == 0);
  int v482;
  if (v504) {
    int * v370 = v350->cache_age;
    int v506 = ((((int)((unsigned int)((int)((unsigned int)v358 >> 2)) >> 1)) & 1) * 2) + ((~(((v362 ^ ((int)((unsigned int)((int)((unsigned int)v358 >> 2)) >> 1))) | (-(v362 ^ ((int)((unsigned int)((int)((unsigned int)v358 >> 2)) >> 1))))) >> 31)) & 1);
    int v371 = v370[v506];
    int * v372 = v350->cache_age;
    int v373 = v372[v496];
    int * v374 = v350->cache_age;
    int v509 = v373 + ((int)((unsigned int)(v373 - v371) >> 31));
    v374[v496] = v509;
    int * v376 = v350->cache_age;
    int v377 = v376[v498];
    int * v378 = v350->cache_age;
    int v512 = v377 + ((int)((unsigned int)(v377 - v371) >> 31));
    v378[v498] = v512;
    int * v380 = v350->cache_age;
    v380[v506] = 0;
    v482 = v506;
  } else {
    int * v383 = v350->cache_age;
    int v516 = (((int)((unsigned int)((int)((unsigned int)v358 >> 2)) >> 1)) & 1) * 2;
    int v384 = v383[v516];
    int * v385 = v350->cache_tags;
    int v386 = v385[v516];
    int * v387 = v350->cache_age;
    int v388 = v387[v498];
    int * v389 = v350->cache_tags;
    int v390 = v389[v498];
    bool v520 = !(((~(((v364 ^ ((int)((unsigned int)((int)((unsigned int)v358 >> 2)) >> 1))) | (-(v364 ^ ((int)((unsigned int)((int)((unsigned int)v358 >> 2)) >> 1))))) >> 31)) | (~(((v366 ^ ((int)((unsigned int)((int)((unsigned int)v358 >> 2)) >> 1))) | (-(v366 ^ ((int)((unsigned int)((int)((unsigned int)v358 >> 2)) >> 1))))) >> 31))) == 0);
    int v454;
    if (v520) {
      int * v391 = v350->cache_age;
      int v522 = (4 + ((((int)((unsigned int)((int)((unsigned int)v358 >> 2)) >> 1)) & 3) * 2)) + ((~(((v366 ^ ((int)((unsigned int)((int)((unsigned int)v358 >> 2)) >> 1))) | (-(v366 ^ ((int)((unsigned int)((int)((unsigned int)v358 >> 2)) >> 1))))) >> 31)) & 1);
      int v392 = v391[v522];
      int * v393 = v350->cache_age;
      int v394 = v393[v500];
      int * v395 = v350->cache_age;
      int v525 = v394 + ((int)((unsigned int)(v394 - v392) >> 31));
      v395[v500] = v525;
      int * v397 = v350->cache_age;
      int v398 = v397[v502];
      int * v399 = v350->cache_age;
      int v528 = v398 + ((int)((unsigned int)(v398 - v392) >> 31));
      v399[v502] = v528;
      int * v401 = v350->cache_age;
      v401[v522] = 0;
      v454 = v522;
    } else {
      int * v404 = v350->cache_age;
      int v532 = 4 + ((((int)((unsigned int)((int)((unsigned int)v358 >> 2)) >> 1)) & 3) * 2);
      int v405 = v404[v532];
      int * v406 = v350->cache_tags;
      int v407 = v406[v532];
      int * v408 = v350->cache_age;
      int v409 = v408[v502];
      int * v410 = v350->cache_tags;
      int v411 = v410[v502];
      int * v412 = v350->cache_dirty;
      int v537 = (4 + ((((int)((unsigned int)((int)((unsigned int)v358 >> 2)) >> 1)) & 3) * 2)) + ((((v405 + ((~(((v407 ^ -1) | (-(v407 ^ -1))) >> 31)) & 2)) - (v409 + ((~(((v411 ^ -1) | (-(v411 ^ -1))) >> 31)) & 2))) >> 31) & 1);
      int v413 = v412[v537];
      bool v538 = !(v413 == 0);
      if (v538) {
        int * v414 = v350->cache_tags;
        int v415 = v414[v537];
        int * v416 = v350->cache_vals;
        int v541 = ((4 + ((((int)((unsigned int)((int)((unsigned int)v358 >> 2)) >> 1)) & 3) * 2)) + ((((v405 + ((~(((v407 ^ -1) | (-(v407 ^ -1))) >> 31)) & 2)) - (v409 + ((~(((v411 ^ -1) | (-(v411 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
        int v417 = v416[v541];
        int * v418 = v350->cache_vals;
        int v543 = (((4 + ((((int)((unsigned int)((int)((unsigned int)v358 >> 2)) >> 1)) & 3) * 2)) + ((((v405 + ((~(((v407 ^ -1) | (-(v407 ^ -1))) >> 31)) & 2)) - (v409 + ((~(((v411 ^ -1) | (-(v411 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
        int v419 = v418[v543];
        int * v420 = v350->mem;
        int v545 = v415 * 2;
        v420[v545] = v417;
        int * v422 = v350->mem;
        int v548 = (v415 * 2) + 1;
        v422[v548] = v419;
        ;
      } else {
        ;
      }
      int * v427 = v350->mem;
      int v553 = ((int)((unsigned int)((int)((unsigned int)v358 >> 2)) >> 1)) * 2;
      int v428 = v427[v553];
      int * v429 = v350->mem;
      int v555 = (((int)((unsigned int)((int)((unsigned int)v358 >> 2)) >> 1)) * 2) + 1;
      int v430 = v429[v555];
      int * v431 = v350->cache_vals;
      int v557 = ((4 + ((((int)((unsigned int)((int)((unsigned int)v358 >> 2)) >> 1)) & 3) * 2)) + ((((v405 + ((~(((v407 ^ -1) | (-(v407 ^ -1))) >> 31)) & 2)) - (v409 + ((~(((v411 ^ -1) | (-(v411 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
      v431[v557] = v428;
      int * v433 = v350->cache_vals;
      int v560 = (((4 + ((((int)((unsigned int)((int)((unsigned int)v358 >> 2)) >> 1)) & 3) * 2)) + ((((v405 + ((~(((v407 ^ -1) | (-(v407 ^ -1))) >> 31)) & 2)) - (v409 + ((~(((v411 ^ -1) | (-(v411 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
      v433[v560] = v430;
      int * v435 = v350->cache_tags;
      int v563 = (int)((unsigned int)((int)((unsigned int)v358 >> 2)) >> 1);
      v435[v537] = v563;
      int * v437 = v350->cache_dirty;
      v437[v537] = 0;
      int * v439 = v350->cache_age;
      v439[v537] = 1;
      int * v441 = v350->cache_age;
      int v442 = v441[v537];
      int * v443 = v350->cache_age;
      int v444 = v443[v500];
      int * v445 = v350->cache_age;
      int v571 = v444 + ((int)((unsigned int)(v444 - v442) >> 31));
      v445[v500] = v571;
      int * v447 = v350->cache_age;
      int v448 = v447[v502];
      int * v449 = v350->cache_age;
      int v574 = v448 + ((int)((unsigned int)(v448 - v442) >> 31));
      v449[v502] = v574;
      int * v451 = v350->cache_age;
      v451[v537] = 0;
      v454 = v537;
    }
    int * v455 = v350->cache_vals;
    int v577 = v454 * 2;
    int v456 = v455[v577];
    int * v457 = v350->cache_vals;
    int v579 = (v454 * 2) + 1;
    int v458 = v457[v579];
    int * v459 = v350->cache_vals;
    int v581 = (((((int)((unsigned int)((int)((unsigned int)v358 >> 2)) >> 1)) & 1) * 2) + ((((v384 + ((~(((v386 ^ -1) | (-(v386 ^ -1))) >> 31)) & 2)) - (v388 + ((~(((v390 ^ -1) | (-(v390 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
    v459[v581] = v456;
    int * v461 = v350->cache_vals;
    int v584 = ((((((int)((unsigned int)((int)((unsigned int)v358 >> 2)) >> 1)) & 1) * 2) + ((((v384 + ((~(((v386 ^ -1) | (-(v386 ^ -1))) >> 31)) & 2)) - (v388 + ((~(((v390 ^ -1) | (-(v390 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
    v461[v584] = v458;
    int * v463 = v350->cache_tags;
    int v587 = ((((int)((unsigned int)((int)((unsigned int)v358 >> 2)) >> 1)) & 1) * 2) + ((((v384 + ((~(((v386 ^ -1) | (-(v386 ^ -1))) >> 31)) & 2)) - (v388 + ((~(((v390 ^ -1) | (-(v390 ^ -1))) >> 31)) & 2))) >> 31) & 1);
    int v588 = (int)((unsigned int)((int)((unsigned int)v358 >> 2)) >> 1);
    v463[v587] = v588;
    int * v465 = v350->cache_dirty;
    v465[v587] = 0;
    int * v467 = v350->cache_age;
    v467[v587] = 1;
    int * v469 = v350->cache_age;
    int v470 = v469[v587];
    int * v471 = v350->cache_age;
    int v472 = v471[v496];
    int * v473 = v350->cache_age;
    int v596 = v472 + ((int)((unsigned int)(v472 - v470) >> 31));
    v473[v496] = v596;
    int * v475 = v350->cache_age;
    int v476 = v475[v498];
    int * v477 = v350->cache_age;
    int v599 = v476 + ((int)((unsigned int)(v476 - v470) >> 31));
    v477[v498] = v599;
    int * v479 = v350->cache_age;
    v479[v587] = 0;
    v482 = v587;
  }
  int v602 = (v482 * 2) + (((int)((unsigned int)v358 >> 2)) & 1);
  int v483 = v369[v602];
  int * v484 = v350->regs;
  v484[12] = v483;
  struct StateT * v486 = slot_8(v350);
  return v486;
}

struct StateT * slot_3(struct StateT * v41) {
  int v42 = v41->timer;
  int v46 = v42 + 1;
  v41->timer = v46;
  struct StateT * v44 = slot_4(v41);
  return v44;
}

struct StateT * snippet(struct StateT * v0) {
  struct StateT * v1 = slot_0(v0);
  return v1;
}

struct StateT * slot_10(struct StateT * v663) {
  int v664 = v663->timer;
  int v668 = v664 + 1;
  v663->timer = v668;
  struct StateT * v666 = slot_12(v663);
  return v666;
}

struct StateT * slot_1(struct StateT * v15) {
  int v16 = v15->timer;
  int v22 = v16 + 1;
  v15->timer = v22;
  int * v18 = v15->regs;
  v18[10] = 80;
  struct StateT * v20 = slot_2(v15);
  return v20;
}

struct StateT * slot_8(struct StateT * v607) {
  int * v608 = v607->regs;
  int v609 = v608[10];
  int * v610 = v607->regs;
  int v611 = v610[15];
  bool v636 = v609 >= v611;
  struct StateT * v630;
  if (v636) {
    int v612 = v607->timer;
    int v637 = v612 + 15;
    v607->timer = v637;
    int * v614 = v607->saved_regs;
    int v615 = v614[5];
    int * v616 = v607->regs;
    v616[5] = v615;
    int * v618 = v607->saved_regs;
    int v619 = v618[11];
    int * v620 = v607->regs;
    v620[11] = v619;
    int * v622 = v607->saved_regs;
    int v623 = v622[12];
    int * v624 = v607->regs;
    v624[12] = v623;
    struct StateT * v626 = slot_9(v607);
    v630 = v626;
  } else {
    struct StateT * v628 = slot_10(v607);
    v630 = v628;
  }
  return v630;
}

struct StateT * slot_4(struct StateT * v49) {
  int * v50 = v49->saved_regs;
  int * v51 = v49->regs;
  int v52 = v51[5];
  v50[5] = v52;
  int v54 = v49->timer;
  int v68 = v54 + 1;
  v49->timer = v68;
  int * v56 = v49->regs;
  int v57 = v56[13];
  int * v58 = v49->regs;
  int v59 = v58[10];
  int * v60 = v49->regs;
  int v74 = v57 + v59;
  v60[5] = v74;
  struct StateT * v62 = slot_5(v49);
  return v62;
}

struct StateT * slot_9(struct StateT * v655) {
  int v656 = v655->timer;
  int v660 = v656 + 1;
  v655->timer = v660;
  struct StateT * v658 = slot_11(v655);
  return v658;
}

struct StateT * slot_11(struct StateT * v671) {
  int v672 = v671->timer;
  int v802 = v672 + 1;
  v671->timer = v802;
  int * v674 = v671->cache_tags;
  int v675 = v674[0];
  int * v676 = v671->cache_tags;
  int v677 = v676[1];
  int * v678 = v671->cache_tags;
  int v679 = v678[4];
  int * v680 = v671->cache_tags;
  int v681 = v680[5];
  int v682 = v671->timer;
  int v811 = v682 + ((100 ^ (((~((v679 | (-v679)) >> 31)) | (~((v681 | (-v681)) >> 31))) & 104)) ^ (((~((v675 | (-v675)) >> 31)) | (~((v677 | (-v677)) >> 31))) & (1 ^ (100 ^ (((~((v679 | (-v679)) >> 31)) | (~((v681 | (-v681)) >> 31))) & 104)))));
  v671->timer = v811;
  int * v684 = v671->cache_vals;
  bool v812 = !(((~((v675 | (-v675)) >> 31)) | (~((v677 | (-v677)) >> 31))) == 0);
  int v797;
  if (v812) {
    int * v685 = v671->cache_age;
    int v814 = (~((v677 | (-v677)) >> 31)) & 1;
    int v686 = v685[v814];
    int * v687 = v671->cache_age;
    int v688 = v687[0];
    int * v689 = v671->cache_age;
    int v817 = v688 + ((int)((unsigned int)(v688 - v686) >> 31));
    v689[0] = v817;
    int * v691 = v671->cache_age;
    int v692 = v691[1];
    int * v693 = v671->cache_age;
    int v820 = v692 + ((int)((unsigned int)(v692 - v686) >> 31));
    v693[1] = v820;
    int * v695 = v671->cache_age;
    v695[v814] = 0;
    v797 = v814;
  } else {
    int * v698 = v671->cache_age;
    int v699 = v698[0];
    int * v700 = v671->cache_tags;
    int v701 = v700[0];
    int * v702 = v671->cache_age;
    int v703 = v702[1];
    int * v704 = v671->cache_tags;
    int v705 = v704[1];
    bool v826 = !(((~((v679 | (-v679)) >> 31)) | (~((v681 | (-v681)) >> 31))) == 0);
    int v769;
    if (v826) {
      int * v706 = v671->cache_age;
      int v828 = 4 + ((~((v681 | (-v681)) >> 31)) & 1);
      int v707 = v706[v828];
      int * v708 = v671->cache_age;
      int v709 = v708[4];
      int * v710 = v671->cache_age;
      int v831 = v709 + ((int)((unsigned int)(v709 - v707) >> 31));
      v710[4] = v831;
      int * v712 = v671->cache_age;
      int v713 = v712[5];
      int * v714 = v671->cache_age;
      int v834 = v713 + ((int)((unsigned int)(v713 - v707) >> 31));
      v714[5] = v834;
      int * v716 = v671->cache_age;
      v716[v828] = 0;
      v769 = v828;
    } else {
      int * v719 = v671->cache_age;
      int v720 = v719[4];
      int * v721 = v671->cache_tags;
      int v722 = v721[4];
      int * v723 = v671->cache_age;
      int v724 = v723[5];
      int * v725 = v671->cache_tags;
      int v726 = v725[5];
      int * v727 = v671->cache_dirty;
      int v841 = 4 + ((((v720 + ((~(((v722 ^ -1) | (-(v722 ^ -1))) >> 31)) & 2)) - (v724 + ((~(((v726 ^ -1) | (-(v726 ^ -1))) >> 31)) & 2))) >> 31) & 1);
      int v728 = v727[v841];
      bool v842 = !(v728 == 0);
      if (v842) {
        int * v729 = v671->cache_tags;
        int v730 = v729[v841];
        int * v731 = v671->cache_vals;
        int v845 = (4 + ((((v720 + ((~(((v722 ^ -1) | (-(v722 ^ -1))) >> 31)) & 2)) - (v724 + ((~(((v726 ^ -1) | (-(v726 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
        int v732 = v731[v845];
        int * v733 = v671->cache_vals;
        int v847 = ((4 + ((((v720 + ((~(((v722 ^ -1) | (-(v722 ^ -1))) >> 31)) & 2)) - (v724 + ((~(((v726 ^ -1) | (-(v726 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
        int v734 = v733[v847];
        int * v735 = v671->mem;
        int v849 = v730 * 2;
        v735[v849] = v732;
        int * v737 = v671->mem;
        int v852 = (v730 * 2) + 1;
        v737[v852] = v734;
        ;
      } else {
        ;
      }
      int * v742 = v671->mem;
      int v743 = v742[0];
      int * v744 = v671->mem;
      int v745 = v744[1];
      int * v746 = v671->cache_vals;
      int v859 = (4 + ((((v720 + ((~(((v722 ^ -1) | (-(v722 ^ -1))) >> 31)) & 2)) - (v724 + ((~(((v726 ^ -1) | (-(v726 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
      v746[v859] = v743;
      int * v748 = v671->cache_vals;
      int v862 = ((4 + ((((v720 + ((~(((v722 ^ -1) | (-(v722 ^ -1))) >> 31)) & 2)) - (v724 + ((~(((v726 ^ -1) | (-(v726 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
      v748[v862] = v745;
      int * v750 = v671->cache_tags;
      v750[v841] = 0;
      int * v752 = v671->cache_dirty;
      v752[v841] = 0;
      int * v754 = v671->cache_age;
      v754[v841] = 1;
      int * v756 = v671->cache_age;
      int v757 = v756[v841];
      int * v758 = v671->cache_age;
      int v759 = v758[4];
      int * v760 = v671->cache_age;
      int v870 = v759 + ((int)((unsigned int)(v759 - v757) >> 31));
      v760[4] = v870;
      int * v762 = v671->cache_age;
      int v763 = v762[5];
      int * v764 = v671->cache_age;
      int v873 = v763 + ((int)((unsigned int)(v763 - v757) >> 31));
      v764[5] = v873;
      int * v766 = v671->cache_age;
      v766[v841] = 0;
      v769 = v841;
    }
    int * v770 = v671->cache_vals;
    int v876 = v769 * 2;
    int v771 = v770[v876];
    int * v772 = v671->cache_vals;
    int v878 = (v769 * 2) + 1;
    int v773 = v772[v878];
    int * v774 = v671->cache_vals;
    int v880 = ((((v699 + ((~(((v701 ^ -1) | (-(v701 ^ -1))) >> 31)) & 2)) - (v703 + ((~(((v705 ^ -1) | (-(v705 ^ -1))) >> 31)) & 2))) >> 31) & 1) * 2;
    v774[v880] = v771;
    int * v776 = v671->cache_vals;
    int v883 = (((((v699 + ((~(((v701 ^ -1) | (-(v701 ^ -1))) >> 31)) & 2)) - (v703 + ((~(((v705 ^ -1) | (-(v705 ^ -1))) >> 31)) & 2))) >> 31) & 1) * 2) + 1;
    v776[v883] = v773;
    int * v778 = v671->cache_tags;
    int v886 = (((v699 + ((~(((v701 ^ -1) | (-(v701 ^ -1))) >> 31)) & 2)) - (v703 + ((~(((v705 ^ -1) | (-(v705 ^ -1))) >> 31)) & 2))) >> 31) & 1;
    v778[v886] = 0;
    int * v780 = v671->cache_dirty;
    v780[v886] = 0;
    int * v782 = v671->cache_age;
    v782[v886] = 1;
    int * v784 = v671->cache_age;
    int v785 = v784[v886];
    int * v786 = v671->cache_age;
    int v787 = v786[0];
    int * v788 = v671->cache_age;
    int v892 = v787 + ((int)((unsigned int)(v787 - v785) >> 31));
    v788[0] = v892;
    int * v790 = v671->cache_age;
    int v791 = v790[1];
    int * v792 = v671->cache_age;
    int v895 = v791 + ((int)((unsigned int)(v791 - v785) >> 31));
    v792[1] = v895;
    int * v794 = v671->cache_age;
    v794[v886] = 0;
    v797 = v886;
  }
  int v898 = v797 * 2;
  int v798 = v684[v898];
  int * v799 = v671->regs;
  v799[14] = v798;
  return v671;
}

struct StateT * slot_0(struct StateT * v2) {
  int v3 = v2->timer;
  int v9 = v3 + 1;
  v2->timer = v9;
  int * v5 = v2->regs;
  v5[13] = 0;
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