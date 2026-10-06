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

struct StateT * slot_12(struct StateT * v976);
struct StateT * slot_6(struct StateT * v305);
struct StateT * slot_5(struct StateT * v90);
struct StateT * slot_2(struct StateT * v34);
struct StateT * slot_7(struct StateT * v326);
struct StateT * slot_3(struct StateT * v50);
struct StateT * snippet(struct StateT * v0);
struct StateT * slot_10(struct StateT * v782);
struct StateT * slot_1(struct StateT * v18);
struct StateT * slot_8(struct StateT * v541);
struct StateT * slot_4(struct StateT * v58);
struct StateT * slot_0(struct StateT * v2);
struct StateT * slot_12(struct StateT * v976) {
  int v977 = v976->timer;
  int v1084 = v977 + 1;
  v976->timer = v1084;
  int * v979 = v976->cache_tags;
  int v980 = v979[0];
  int v981 = v979[1];
  int v982 = v979[4];
  int v983 = v979[5];
  int * v984 = v976->cache_vals;
  bool v1090 = !(((~((v980 | (-v980)) >> 31)) | (~((v981 | (-v981)) >> 31))) == 0);
  int v1077;
  if (v1090) {
    int * v985 = v976->cache_age;
    int v1092 = (~((v981 | (-v981)) >> 31)) & 1;
    int v986 = v985[v1092];
    int v987 = v985[0];
    int v1093 = v987 + ((int)((unsigned int)(v987 - v986) >> 31));
    v985[0] = v1093;
    int * v989 = v976->cache_age;
    int v990 = v989[1];
    int v1095 = v990 + ((int)((unsigned int)(v990 - v986) >> 31));
    v989[1] = v1095;
    int * v992 = v976->cache_age;
    v992[v1092] = 0;
    v1077 = v1092;
  } else {
    int * v995 = v976->cache_age;
    int v996 = v995[0];
    int * v997 = v976->cache_tags;
    int v998 = v997[0];
    int v999 = v995[1];
    int v1000 = v997[1];
    bool v1099 = !(((~((v982 | (-v982)) >> 31)) | (~((v983 | (-v983)) >> 31))) == 0);
    int v1054;
    if (v1099) {
      int * v1001 = v976->cache_age;
      int v1101 = 4 + ((~((v983 | (-v983)) >> 31)) & 1);
      int v1002 = v1001[v1101];
      int v1003 = v1001[4];
      int v1102 = v1003 + ((int)((unsigned int)(v1003 - v1002) >> 31));
      v1001[4] = v1102;
      int * v1005 = v976->cache_age;
      int v1006 = v1005[5];
      int v1104 = v1006 + ((int)((unsigned int)(v1006 - v1002) >> 31));
      v1005[5] = v1104;
      int * v1008 = v976->cache_age;
      v1008[v1101] = 0;
      v1054 = v1101;
    } else {
      int * v1011 = v976->cache_age;
      int v1012 = v1011[4];
      int * v1013 = v976->cache_tags;
      int v1014 = v1013[4];
      int v1015 = v1011[5];
      int v1016 = v1013[5];
      int * v1017 = v976->cache_dirty;
      int v1109 = 4 + ((((v1012 + ((~(((v1014 ^ -1) | (-(v1014 ^ -1))) >> 31)) & 2)) - (v1015 + ((~(((v1016 ^ -1) | (-(v1016 ^ -1))) >> 31)) & 2))) >> 31) & 1);
      int v1018 = v1017[v1109];
      bool v1110 = !(v1018 == 0);
      if (v1110) {
        int * v1019 = v976->cache_tags;
        int v1020 = v1019[v1109];
        int * v1021 = v976->cache_vals;
        int v1113 = (4 + ((((v1012 + ((~(((v1014 ^ -1) | (-(v1014 ^ -1))) >> 31)) & 2)) - (v1015 + ((~(((v1016 ^ -1) | (-(v1016 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
        int v1022 = v1021[v1113];
        int v1114 = ((4 + ((((v1012 + ((~(((v1014 ^ -1) | (-(v1014 ^ -1))) >> 31)) & 2)) - (v1015 + ((~(((v1016 ^ -1) | (-(v1016 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
        int v1023 = v1021[v1114];
        int * v1024 = v976->mem;
        int v1116 = v1020 * 2;
        v1024[v1116] = v1022;
        int * v1026 = v976->mem;
        int v1119 = (v1020 * 2) + 1;
        v1026[v1119] = v1023;
        ;
      } else {
        ;
      }
      int * v1031 = v976->mem;
      int v1032 = v1031[0];
      int v1033 = v1031[1];
      int * v1034 = v976->cache_vals;
      int v1125 = (4 + ((((v1012 + ((~(((v1014 ^ -1) | (-(v1014 ^ -1))) >> 31)) & 2)) - (v1015 + ((~(((v1016 ^ -1) | (-(v1016 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
      v1034[v1125] = v1032;
      int * v1036 = v976->cache_vals;
      int v1128 = ((4 + ((((v1012 + ((~(((v1014 ^ -1) | (-(v1014 ^ -1))) >> 31)) & 2)) - (v1015 + ((~(((v1016 ^ -1) | (-(v1016 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
      v1036[v1128] = v1033;
      int * v1038 = v976->cache_tags;
      v1038[v1109] = 0;
      int * v1040 = v976->cache_dirty;
      v1040[v1109] = 0;
      int * v1042 = v976->cache_age;
      v1042[v1109] = 1;
      int * v1044 = v976->cache_age;
      int v1045 = v1044[v1109];
      int v1046 = v1044[4];
      int v1134 = v1046 + ((int)((unsigned int)(v1046 - v1045) >> 31));
      v1044[4] = v1134;
      int * v1048 = v976->cache_age;
      int v1049 = v1048[5];
      int v1136 = v1049 + ((int)((unsigned int)(v1049 - v1045) >> 31));
      v1048[5] = v1136;
      int * v1051 = v976->cache_age;
      v1051[v1109] = 0;
      v1054 = v1109;
    }
    int * v1055 = v976->cache_vals;
    int v1139 = v1054 * 2;
    int v1056 = v1055[v1139];
    int v1140 = (v1054 * 2) + 1;
    int v1057 = v1055[v1140];
    int v1141 = ((((v996 + ((~(((v998 ^ -1) | (-(v998 ^ -1))) >> 31)) & 2)) - (v999 + ((~(((v1000 ^ -1) | (-(v1000 ^ -1))) >> 31)) & 2))) >> 31) & 1) * 2;
    v1055[v1141] = v1056;
    int * v1059 = v976->cache_vals;
    int v1144 = (((((v996 + ((~(((v998 ^ -1) | (-(v998 ^ -1))) >> 31)) & 2)) - (v999 + ((~(((v1000 ^ -1) | (-(v1000 ^ -1))) >> 31)) & 2))) >> 31) & 1) * 2) + 1;
    v1059[v1144] = v1057;
    int * v1061 = v976->cache_tags;
    int v1147 = (((v996 + ((~(((v998 ^ -1) | (-(v998 ^ -1))) >> 31)) & 2)) - (v999 + ((~(((v1000 ^ -1) | (-(v1000 ^ -1))) >> 31)) & 2))) >> 31) & 1;
    v1061[v1147] = 0;
    int * v1063 = v976->cache_dirty;
    v1063[v1147] = 0;
    int * v1065 = v976->cache_age;
    v1065[v1147] = 1;
    int * v1067 = v976->cache_age;
    int v1068 = v1067[v1147];
    int v1069 = v1067[0];
    int v1151 = v1069 + ((int)((unsigned int)(v1069 - v1068) >> 31));
    v1067[0] = v1151;
    int * v1071 = v976->cache_age;
    int v1072 = v1071[1];
    int v1153 = v1072 + ((int)((unsigned int)(v1072 - v1068) >> 31));
    v1071[1] = v1153;
    int * v1074 = v976->cache_age;
    v1074[v1147] = 0;
    v1077 = v1147;
  }
  int v1156 = v1077 * 2;
  int v1078 = v984[v1156];
  int * v1079 = v976->reg_ready;
  int v1159 = (v977 + 1) + ((100 ^ (((~((v982 | (-v982)) >> 31)) | (~((v983 | (-v983)) >> 31))) & 104)) ^ (((~((v980 | (-v980)) >> 31)) | (~((v981 | (-v981)) >> 31))) & (1 ^ (100 ^ (((~((v982 | (-v982)) >> 31)) | (~((v983 | (-v983)) >> 31))) & 104)))));
  v1079[14] = v1159;
  int * v1081 = v976->regs;
  v1081[14] = v1078;
  return v976;
}

struct StateT * slot_6(struct StateT * v305) {
  int v306 = v305->timer;
  int v317 = v306 + 1;
  v305->timer = v317;
  int * v308 = v305->reg_ready;
  int v309 = v308[11];
  int * v310 = v305->regs;
  int v311 = v310[11];
  int v321 = (v309 + ((v306 - v309) & (~((v306 - v309) >> 31)))) + 1;
  v308[11] = v321;
  int * v313 = v305->regs;
  int v323 = v311 << 2;
  v313[11] = v323;
  struct StateT * v315 = slot_7(v305);
  return v315;
}

struct StateT * slot_5(struct StateT * v90) {
  int * v91 = v90->saved_regs;
  int * v92 = v90->regs;
  int v93 = v92[11];
  v91[11] = v93;
  int v95 = v90->timer;
  int v211 = v95 + 1;
  v90->timer = v211;
  int * v97 = v90->reg_ready;
  int v98 = v97[5];
  int * v99 = v90->regs;
  int v100 = v99[5];
  int * v101 = v90->cache_tags;
  int v216 = (((int)((unsigned int)((int)((unsigned int)v100 >> 2)) >> 1)) & 1) * 2;
  int v102 = v101[v216];
  int v217 = ((((int)((unsigned int)((int)((unsigned int)v100 >> 2)) >> 1)) & 1) * 2) + 1;
  int v103 = v101[v217];
  int v218 = 4 + ((((int)((unsigned int)((int)((unsigned int)v100 >> 2)) >> 1)) & 3) * 2);
  int v104 = v101[v218];
  int v219 = (4 + ((((int)((unsigned int)((int)((unsigned int)v100 >> 2)) >> 1)) & 3) * 2)) + 1;
  int v105 = v101[v219];
  int * v106 = v90->cache_vals;
  bool v220 = !(((~(((v102 ^ ((int)((unsigned int)((int)((unsigned int)v100 >> 2)) >> 1))) | (-(v102 ^ ((int)((unsigned int)((int)((unsigned int)v100 >> 2)) >> 1))))) >> 31)) | (~(((v103 ^ ((int)((unsigned int)((int)((unsigned int)v100 >> 2)) >> 1))) | (-(v103 ^ ((int)((unsigned int)((int)((unsigned int)v100 >> 2)) >> 1))))) >> 31))) == 0);
  int v199;
  if (v220) {
    int * v107 = v90->cache_age;
    int v222 = ((((int)((unsigned int)((int)((unsigned int)v100 >> 2)) >> 1)) & 1) * 2) + ((~(((v103 ^ ((int)((unsigned int)((int)((unsigned int)v100 >> 2)) >> 1))) | (-(v103 ^ ((int)((unsigned int)((int)((unsigned int)v100 >> 2)) >> 1))))) >> 31)) & 1);
    int v108 = v107[v222];
    int v109 = v107[v216];
    int v223 = v109 + ((int)((unsigned int)(v109 - v108) >> 31));
    v107[v216] = v223;
    int * v111 = v90->cache_age;
    int v112 = v111[v217];
    int v225 = v112 + ((int)((unsigned int)(v112 - v108) >> 31));
    v111[v217] = v225;
    int * v114 = v90->cache_age;
    v114[v222] = 0;
    v199 = v222;
  } else {
    int * v117 = v90->cache_age;
    int v229 = (((int)((unsigned int)((int)((unsigned int)v100 >> 2)) >> 1)) & 1) * 2;
    int v118 = v117[v229];
    int * v119 = v90->cache_tags;
    int v120 = v119[v229];
    int v121 = v117[v217];
    int v122 = v119[v217];
    bool v231 = !(((~(((v104 ^ ((int)((unsigned int)((int)((unsigned int)v100 >> 2)) >> 1))) | (-(v104 ^ ((int)((unsigned int)((int)((unsigned int)v100 >> 2)) >> 1))))) >> 31)) | (~(((v105 ^ ((int)((unsigned int)((int)((unsigned int)v100 >> 2)) >> 1))) | (-(v105 ^ ((int)((unsigned int)((int)((unsigned int)v100 >> 2)) >> 1))))) >> 31))) == 0);
    int v176;
    if (v231) {
      int * v123 = v90->cache_age;
      int v233 = (4 + ((((int)((unsigned int)((int)((unsigned int)v100 >> 2)) >> 1)) & 3) * 2)) + ((~(((v105 ^ ((int)((unsigned int)((int)((unsigned int)v100 >> 2)) >> 1))) | (-(v105 ^ ((int)((unsigned int)((int)((unsigned int)v100 >> 2)) >> 1))))) >> 31)) & 1);
      int v124 = v123[v233];
      int v125 = v123[v218];
      int v234 = v125 + ((int)((unsigned int)(v125 - v124) >> 31));
      v123[v218] = v234;
      int * v127 = v90->cache_age;
      int v128 = v127[v219];
      int v236 = v128 + ((int)((unsigned int)(v128 - v124) >> 31));
      v127[v219] = v236;
      int * v130 = v90->cache_age;
      v130[v233] = 0;
      v176 = v233;
    } else {
      int * v133 = v90->cache_age;
      int v240 = 4 + ((((int)((unsigned int)((int)((unsigned int)v100 >> 2)) >> 1)) & 3) * 2);
      int v134 = v133[v240];
      int * v135 = v90->cache_tags;
      int v136 = v135[v240];
      int v137 = v133[v219];
      int v138 = v135[v219];
      int * v139 = v90->cache_dirty;
      int v243 = (4 + ((((int)((unsigned int)((int)((unsigned int)v100 >> 2)) >> 1)) & 3) * 2)) + ((((v134 + ((~(((v136 ^ -1) | (-(v136 ^ -1))) >> 31)) & 2)) - (v137 + ((~(((v138 ^ -1) | (-(v138 ^ -1))) >> 31)) & 2))) >> 31) & 1);
      int v140 = v139[v243];
      bool v244 = !(v140 == 0);
      if (v244) {
        int * v141 = v90->cache_tags;
        int v142 = v141[v243];
        int * v143 = v90->cache_vals;
        int v247 = ((4 + ((((int)((unsigned int)((int)((unsigned int)v100 >> 2)) >> 1)) & 3) * 2)) + ((((v134 + ((~(((v136 ^ -1) | (-(v136 ^ -1))) >> 31)) & 2)) - (v137 + ((~(((v138 ^ -1) | (-(v138 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
        int v144 = v143[v247];
        int v248 = (((4 + ((((int)((unsigned int)((int)((unsigned int)v100 >> 2)) >> 1)) & 3) * 2)) + ((((v134 + ((~(((v136 ^ -1) | (-(v136 ^ -1))) >> 31)) & 2)) - (v137 + ((~(((v138 ^ -1) | (-(v138 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
        int v145 = v143[v248];
        int * v146 = v90->mem;
        int v250 = v142 * 2;
        v146[v250] = v144;
        int * v148 = v90->mem;
        int v253 = (v142 * 2) + 1;
        v148[v253] = v145;
        ;
      } else {
        ;
      }
      int * v153 = v90->mem;
      int v258 = ((int)((unsigned int)((int)((unsigned int)v100 >> 2)) >> 1)) * 2;
      int v154 = v153[v258];
      int v259 = (((int)((unsigned int)((int)((unsigned int)v100 >> 2)) >> 1)) * 2) + 1;
      int v155 = v153[v259];
      int * v156 = v90->cache_vals;
      int v261 = ((4 + ((((int)((unsigned int)((int)((unsigned int)v100 >> 2)) >> 1)) & 3) * 2)) + ((((v134 + ((~(((v136 ^ -1) | (-(v136 ^ -1))) >> 31)) & 2)) - (v137 + ((~(((v138 ^ -1) | (-(v138 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
      v156[v261] = v154;
      int * v158 = v90->cache_vals;
      int v264 = (((4 + ((((int)((unsigned int)((int)((unsigned int)v100 >> 2)) >> 1)) & 3) * 2)) + ((((v134 + ((~(((v136 ^ -1) | (-(v136 ^ -1))) >> 31)) & 2)) - (v137 + ((~(((v138 ^ -1) | (-(v138 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
      v158[v264] = v155;
      int * v160 = v90->cache_tags;
      int v267 = (int)((unsigned int)((int)((unsigned int)v100 >> 2)) >> 1);
      v160[v243] = v267;
      int * v162 = v90->cache_dirty;
      v162[v243] = 0;
      int * v164 = v90->cache_age;
      v164[v243] = 1;
      int * v166 = v90->cache_age;
      int v167 = v166[v243];
      int v168 = v166[v218];
      int v273 = v168 + ((int)((unsigned int)(v168 - v167) >> 31));
      v166[v218] = v273;
      int * v170 = v90->cache_age;
      int v171 = v170[v219];
      int v275 = v171 + ((int)((unsigned int)(v171 - v167) >> 31));
      v170[v219] = v275;
      int * v173 = v90->cache_age;
      v173[v243] = 0;
      v176 = v243;
    }
    int * v177 = v90->cache_vals;
    int v278 = v176 * 2;
    int v178 = v177[v278];
    int v279 = (v176 * 2) + 1;
    int v179 = v177[v279];
    int v280 = (((((int)((unsigned int)((int)((unsigned int)v100 >> 2)) >> 1)) & 1) * 2) + ((((v118 + ((~(((v120 ^ -1) | (-(v120 ^ -1))) >> 31)) & 2)) - (v121 + ((~(((v122 ^ -1) | (-(v122 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
    v177[v280] = v178;
    int * v181 = v90->cache_vals;
    int v283 = ((((((int)((unsigned int)((int)((unsigned int)v100 >> 2)) >> 1)) & 1) * 2) + ((((v118 + ((~(((v120 ^ -1) | (-(v120 ^ -1))) >> 31)) & 2)) - (v121 + ((~(((v122 ^ -1) | (-(v122 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
    v181[v283] = v179;
    int * v183 = v90->cache_tags;
    int v286 = ((((int)((unsigned int)((int)((unsigned int)v100 >> 2)) >> 1)) & 1) * 2) + ((((v118 + ((~(((v120 ^ -1) | (-(v120 ^ -1))) >> 31)) & 2)) - (v121 + ((~(((v122 ^ -1) | (-(v122 ^ -1))) >> 31)) & 2))) >> 31) & 1);
    int v287 = (int)((unsigned int)((int)((unsigned int)v100 >> 2)) >> 1);
    v183[v286] = v287;
    int * v185 = v90->cache_dirty;
    v185[v286] = 0;
    int * v187 = v90->cache_age;
    v187[v286] = 1;
    int * v189 = v90->cache_age;
    int v190 = v189[v286];
    int v191 = v189[v216];
    int v293 = v191 + ((int)((unsigned int)(v191 - v190) >> 31));
    v189[v216] = v293;
    int * v193 = v90->cache_age;
    int v194 = v193[v217];
    int v295 = v194 + ((int)((unsigned int)(v194 - v190) >> 31));
    v193[v217] = v295;
    int * v196 = v90->cache_age;
    v196[v286] = 0;
    v199 = v286;
  }
  int v298 = (v199 * 2) + (((int)((unsigned int)v100 >> 2)) & 1);
  int v200 = v106[v298];
  int * v201 = v90->reg_ready;
  int v300 = ((v98 + ((v95 - v98) & (~((v95 - v98) >> 31)))) + 1) + ((100 ^ (((~(((v104 ^ ((int)((unsigned int)((int)((unsigned int)v100 >> 2)) >> 1))) | (-(v104 ^ ((int)((unsigned int)((int)((unsigned int)v100 >> 2)) >> 1))))) >> 31)) | (~(((v105 ^ ((int)((unsigned int)((int)((unsigned int)v100 >> 2)) >> 1))) | (-(v105 ^ ((int)((unsigned int)((int)((unsigned int)v100 >> 2)) >> 1))))) >> 31))) & 104)) ^ (((~(((v102 ^ ((int)((unsigned int)((int)((unsigned int)v100 >> 2)) >> 1))) | (-(v102 ^ ((int)((unsigned int)((int)((unsigned int)v100 >> 2)) >> 1))))) >> 31)) | (~(((v103 ^ ((int)((unsigned int)((int)((unsigned int)v100 >> 2)) >> 1))) | (-(v103 ^ ((int)((unsigned int)((int)((unsigned int)v100 >> 2)) >> 1))))) >> 31))) & (1 ^ (100 ^ (((~(((v104 ^ ((int)((unsigned int)((int)((unsigned int)v100 >> 2)) >> 1))) | (-(v104 ^ ((int)((unsigned int)((int)((unsigned int)v100 >> 2)) >> 1))))) >> 31)) | (~(((v105 ^ ((int)((unsigned int)((int)((unsigned int)v100 >> 2)) >> 1))) | (-(v105 ^ ((int)((unsigned int)((int)((unsigned int)v100 >> 2)) >> 1))))) >> 31))) & 104)))));
  v201[11] = v300;
  int * v203 = v90->regs;
  v203[11] = v200;
  struct StateT * v205 = slot_6(v90);
  return v205;
}

struct StateT * slot_2(struct StateT * v34) {
  int v35 = v34->timer;
  int v43 = v35 + 1;
  v34->timer = v43;
  int * v37 = v34->reg_ready;
  v37[15] = v43;
  int * v39 = v34->regs;
  v39[15] = 80;
  struct StateT * v41 = slot_3(v34);
  return v41;
}

struct StateT * slot_7(struct StateT * v326) {
  int * v327 = v326->saved_regs;
  int * v328 = v326->regs;
  int v329 = v328[12];
  v327[12] = v329;
  int v331 = v326->timer;
  int v447 = v331 + 1;
  v326->timer = v447;
  int * v333 = v326->reg_ready;
  int v334 = v333[11];
  int * v335 = v326->regs;
  int v336 = v335[11];
  int * v337 = v326->cache_tags;
  int v452 = (((int)((unsigned int)((int)((unsigned int)v336 >> 2)) >> 1)) & 1) * 2;
  int v338 = v337[v452];
  int v453 = ((((int)((unsigned int)((int)((unsigned int)v336 >> 2)) >> 1)) & 1) * 2) + 1;
  int v339 = v337[v453];
  int v454 = 4 + ((((int)((unsigned int)((int)((unsigned int)v336 >> 2)) >> 1)) & 3) * 2);
  int v340 = v337[v454];
  int v455 = (4 + ((((int)((unsigned int)((int)((unsigned int)v336 >> 2)) >> 1)) & 3) * 2)) + 1;
  int v341 = v337[v455];
  int * v342 = v326->cache_vals;
  bool v456 = !(((~(((v338 ^ ((int)((unsigned int)((int)((unsigned int)v336 >> 2)) >> 1))) | (-(v338 ^ ((int)((unsigned int)((int)((unsigned int)v336 >> 2)) >> 1))))) >> 31)) | (~(((v339 ^ ((int)((unsigned int)((int)((unsigned int)v336 >> 2)) >> 1))) | (-(v339 ^ ((int)((unsigned int)((int)((unsigned int)v336 >> 2)) >> 1))))) >> 31))) == 0);
  int v435;
  if (v456) {
    int * v343 = v326->cache_age;
    int v458 = ((((int)((unsigned int)((int)((unsigned int)v336 >> 2)) >> 1)) & 1) * 2) + ((~(((v339 ^ ((int)((unsigned int)((int)((unsigned int)v336 >> 2)) >> 1))) | (-(v339 ^ ((int)((unsigned int)((int)((unsigned int)v336 >> 2)) >> 1))))) >> 31)) & 1);
    int v344 = v343[v458];
    int v345 = v343[v452];
    int v459 = v345 + ((int)((unsigned int)(v345 - v344) >> 31));
    v343[v452] = v459;
    int * v347 = v326->cache_age;
    int v348 = v347[v453];
    int v461 = v348 + ((int)((unsigned int)(v348 - v344) >> 31));
    v347[v453] = v461;
    int * v350 = v326->cache_age;
    v350[v458] = 0;
    v435 = v458;
  } else {
    int * v353 = v326->cache_age;
    int v465 = (((int)((unsigned int)((int)((unsigned int)v336 >> 2)) >> 1)) & 1) * 2;
    int v354 = v353[v465];
    int * v355 = v326->cache_tags;
    int v356 = v355[v465];
    int v357 = v353[v453];
    int v358 = v355[v453];
    bool v467 = !(((~(((v340 ^ ((int)((unsigned int)((int)((unsigned int)v336 >> 2)) >> 1))) | (-(v340 ^ ((int)((unsigned int)((int)((unsigned int)v336 >> 2)) >> 1))))) >> 31)) | (~(((v341 ^ ((int)((unsigned int)((int)((unsigned int)v336 >> 2)) >> 1))) | (-(v341 ^ ((int)((unsigned int)((int)((unsigned int)v336 >> 2)) >> 1))))) >> 31))) == 0);
    int v412;
    if (v467) {
      int * v359 = v326->cache_age;
      int v469 = (4 + ((((int)((unsigned int)((int)((unsigned int)v336 >> 2)) >> 1)) & 3) * 2)) + ((~(((v341 ^ ((int)((unsigned int)((int)((unsigned int)v336 >> 2)) >> 1))) | (-(v341 ^ ((int)((unsigned int)((int)((unsigned int)v336 >> 2)) >> 1))))) >> 31)) & 1);
      int v360 = v359[v469];
      int v361 = v359[v454];
      int v470 = v361 + ((int)((unsigned int)(v361 - v360) >> 31));
      v359[v454] = v470;
      int * v363 = v326->cache_age;
      int v364 = v363[v455];
      int v472 = v364 + ((int)((unsigned int)(v364 - v360) >> 31));
      v363[v455] = v472;
      int * v366 = v326->cache_age;
      v366[v469] = 0;
      v412 = v469;
    } else {
      int * v369 = v326->cache_age;
      int v476 = 4 + ((((int)((unsigned int)((int)((unsigned int)v336 >> 2)) >> 1)) & 3) * 2);
      int v370 = v369[v476];
      int * v371 = v326->cache_tags;
      int v372 = v371[v476];
      int v373 = v369[v455];
      int v374 = v371[v455];
      int * v375 = v326->cache_dirty;
      int v479 = (4 + ((((int)((unsigned int)((int)((unsigned int)v336 >> 2)) >> 1)) & 3) * 2)) + ((((v370 + ((~(((v372 ^ -1) | (-(v372 ^ -1))) >> 31)) & 2)) - (v373 + ((~(((v374 ^ -1) | (-(v374 ^ -1))) >> 31)) & 2))) >> 31) & 1);
      int v376 = v375[v479];
      bool v480 = !(v376 == 0);
      if (v480) {
        int * v377 = v326->cache_tags;
        int v378 = v377[v479];
        int * v379 = v326->cache_vals;
        int v483 = ((4 + ((((int)((unsigned int)((int)((unsigned int)v336 >> 2)) >> 1)) & 3) * 2)) + ((((v370 + ((~(((v372 ^ -1) | (-(v372 ^ -1))) >> 31)) & 2)) - (v373 + ((~(((v374 ^ -1) | (-(v374 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
        int v380 = v379[v483];
        int v484 = (((4 + ((((int)((unsigned int)((int)((unsigned int)v336 >> 2)) >> 1)) & 3) * 2)) + ((((v370 + ((~(((v372 ^ -1) | (-(v372 ^ -1))) >> 31)) & 2)) - (v373 + ((~(((v374 ^ -1) | (-(v374 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
        int v381 = v379[v484];
        int * v382 = v326->mem;
        int v486 = v378 * 2;
        v382[v486] = v380;
        int * v384 = v326->mem;
        int v489 = (v378 * 2) + 1;
        v384[v489] = v381;
        ;
      } else {
        ;
      }
      int * v389 = v326->mem;
      int v494 = ((int)((unsigned int)((int)((unsigned int)v336 >> 2)) >> 1)) * 2;
      int v390 = v389[v494];
      int v495 = (((int)((unsigned int)((int)((unsigned int)v336 >> 2)) >> 1)) * 2) + 1;
      int v391 = v389[v495];
      int * v392 = v326->cache_vals;
      int v497 = ((4 + ((((int)((unsigned int)((int)((unsigned int)v336 >> 2)) >> 1)) & 3) * 2)) + ((((v370 + ((~(((v372 ^ -1) | (-(v372 ^ -1))) >> 31)) & 2)) - (v373 + ((~(((v374 ^ -1) | (-(v374 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
      v392[v497] = v390;
      int * v394 = v326->cache_vals;
      int v500 = (((4 + ((((int)((unsigned int)((int)((unsigned int)v336 >> 2)) >> 1)) & 3) * 2)) + ((((v370 + ((~(((v372 ^ -1) | (-(v372 ^ -1))) >> 31)) & 2)) - (v373 + ((~(((v374 ^ -1) | (-(v374 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
      v394[v500] = v391;
      int * v396 = v326->cache_tags;
      int v503 = (int)((unsigned int)((int)((unsigned int)v336 >> 2)) >> 1);
      v396[v479] = v503;
      int * v398 = v326->cache_dirty;
      v398[v479] = 0;
      int * v400 = v326->cache_age;
      v400[v479] = 1;
      int * v402 = v326->cache_age;
      int v403 = v402[v479];
      int v404 = v402[v454];
      int v509 = v404 + ((int)((unsigned int)(v404 - v403) >> 31));
      v402[v454] = v509;
      int * v406 = v326->cache_age;
      int v407 = v406[v455];
      int v511 = v407 + ((int)((unsigned int)(v407 - v403) >> 31));
      v406[v455] = v511;
      int * v409 = v326->cache_age;
      v409[v479] = 0;
      v412 = v479;
    }
    int * v413 = v326->cache_vals;
    int v514 = v412 * 2;
    int v414 = v413[v514];
    int v515 = (v412 * 2) + 1;
    int v415 = v413[v515];
    int v516 = (((((int)((unsigned int)((int)((unsigned int)v336 >> 2)) >> 1)) & 1) * 2) + ((((v354 + ((~(((v356 ^ -1) | (-(v356 ^ -1))) >> 31)) & 2)) - (v357 + ((~(((v358 ^ -1) | (-(v358 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
    v413[v516] = v414;
    int * v417 = v326->cache_vals;
    int v519 = ((((((int)((unsigned int)((int)((unsigned int)v336 >> 2)) >> 1)) & 1) * 2) + ((((v354 + ((~(((v356 ^ -1) | (-(v356 ^ -1))) >> 31)) & 2)) - (v357 + ((~(((v358 ^ -1) | (-(v358 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
    v417[v519] = v415;
    int * v419 = v326->cache_tags;
    int v522 = ((((int)((unsigned int)((int)((unsigned int)v336 >> 2)) >> 1)) & 1) * 2) + ((((v354 + ((~(((v356 ^ -1) | (-(v356 ^ -1))) >> 31)) & 2)) - (v357 + ((~(((v358 ^ -1) | (-(v358 ^ -1))) >> 31)) & 2))) >> 31) & 1);
    int v523 = (int)((unsigned int)((int)((unsigned int)v336 >> 2)) >> 1);
    v419[v522] = v523;
    int * v421 = v326->cache_dirty;
    v421[v522] = 0;
    int * v423 = v326->cache_age;
    v423[v522] = 1;
    int * v425 = v326->cache_age;
    int v426 = v425[v522];
    int v427 = v425[v452];
    int v529 = v427 + ((int)((unsigned int)(v427 - v426) >> 31));
    v425[v452] = v529;
    int * v429 = v326->cache_age;
    int v430 = v429[v453];
    int v531 = v430 + ((int)((unsigned int)(v430 - v426) >> 31));
    v429[v453] = v531;
    int * v432 = v326->cache_age;
    v432[v522] = 0;
    v435 = v522;
  }
  int v534 = (v435 * 2) + (((int)((unsigned int)v336 >> 2)) & 1);
  int v436 = v342[v534];
  int * v437 = v326->reg_ready;
  int v536 = ((v334 + ((v331 - v334) & (~((v331 - v334) >> 31)))) + 1) + ((100 ^ (((~(((v340 ^ ((int)((unsigned int)((int)((unsigned int)v336 >> 2)) >> 1))) | (-(v340 ^ ((int)((unsigned int)((int)((unsigned int)v336 >> 2)) >> 1))))) >> 31)) | (~(((v341 ^ ((int)((unsigned int)((int)((unsigned int)v336 >> 2)) >> 1))) | (-(v341 ^ ((int)((unsigned int)((int)((unsigned int)v336 >> 2)) >> 1))))) >> 31))) & 104)) ^ (((~(((v338 ^ ((int)((unsigned int)((int)((unsigned int)v336 >> 2)) >> 1))) | (-(v338 ^ ((int)((unsigned int)((int)((unsigned int)v336 >> 2)) >> 1))))) >> 31)) | (~(((v339 ^ ((int)((unsigned int)((int)((unsigned int)v336 >> 2)) >> 1))) | (-(v339 ^ ((int)((unsigned int)((int)((unsigned int)v336 >> 2)) >> 1))))) >> 31))) & (1 ^ (100 ^ (((~(((v340 ^ ((int)((unsigned int)((int)((unsigned int)v336 >> 2)) >> 1))) | (-(v340 ^ ((int)((unsigned int)((int)((unsigned int)v336 >> 2)) >> 1))))) >> 31)) | (~(((v341 ^ ((int)((unsigned int)((int)((unsigned int)v336 >> 2)) >> 1))) | (-(v341 ^ ((int)((unsigned int)((int)((unsigned int)v336 >> 2)) >> 1))))) >> 31))) & 104)))));
  v437[12] = v536;
  int * v439 = v326->regs;
  v439[12] = v436;
  struct StateT * v441 = slot_8(v326);
  return v441;
}

struct StateT * slot_3(struct StateT * v50) {
  int v51 = v50->timer;
  int v55 = v51 + 1;
  v50->timer = v55;
  struct StateT * v53 = slot_4(v50);
  return v53;
}

struct StateT * snippet(struct StateT * v0) {
  struct StateT * v1 = slot_0(v0);
  int v1162 = v1->timer;
  int * v1163 = v1->reg_ready;
  int v1164 = v1163[0];
  int v1295 = v1164 + ((v1162 - v1164) & (~((v1162 - v1164) >> 31)));
  v1->timer = v1295;
  int v1166 = v1->timer;
  int * v1167 = v1->reg_ready;
  int v1168 = v1167[1];
  int v1298 = v1168 + ((v1166 - v1168) & (~((v1166 - v1168) >> 31)));
  v1->timer = v1298;
  int v1170 = v1->timer;
  int * v1171 = v1->reg_ready;
  int v1172 = v1171[2];
  int v1301 = v1172 + ((v1170 - v1172) & (~((v1170 - v1172) >> 31)));
  v1->timer = v1301;
  int v1174 = v1->timer;
  int * v1175 = v1->reg_ready;
  int v1176 = v1175[3];
  int v1304 = v1176 + ((v1174 - v1176) & (~((v1174 - v1176) >> 31)));
  v1->timer = v1304;
  int v1178 = v1->timer;
  int * v1179 = v1->reg_ready;
  int v1180 = v1179[4];
  int v1307 = v1180 + ((v1178 - v1180) & (~((v1178 - v1180) >> 31)));
  v1->timer = v1307;
  int v1182 = v1->timer;
  int * v1183 = v1->reg_ready;
  int v1184 = v1183[5];
  int v1310 = v1184 + ((v1182 - v1184) & (~((v1182 - v1184) >> 31)));
  v1->timer = v1310;
  int v1186 = v1->timer;
  int * v1187 = v1->reg_ready;
  int v1188 = v1187[6];
  int v1313 = v1188 + ((v1186 - v1188) & (~((v1186 - v1188) >> 31)));
  v1->timer = v1313;
  int v1190 = v1->timer;
  int * v1191 = v1->reg_ready;
  int v1192 = v1191[7];
  int v1316 = v1192 + ((v1190 - v1192) & (~((v1190 - v1192) >> 31)));
  v1->timer = v1316;
  int v1194 = v1->timer;
  int * v1195 = v1->reg_ready;
  int v1196 = v1195[8];
  int v1319 = v1196 + ((v1194 - v1196) & (~((v1194 - v1196) >> 31)));
  v1->timer = v1319;
  int v1198 = v1->timer;
  int * v1199 = v1->reg_ready;
  int v1200 = v1199[9];
  int v1322 = v1200 + ((v1198 - v1200) & (~((v1198 - v1200) >> 31)));
  v1->timer = v1322;
  int v1202 = v1->timer;
  int * v1203 = v1->reg_ready;
  int v1204 = v1203[10];
  int v1325 = v1204 + ((v1202 - v1204) & (~((v1202 - v1204) >> 31)));
  v1->timer = v1325;
  int v1206 = v1->timer;
  int * v1207 = v1->reg_ready;
  int v1208 = v1207[11];
  int v1328 = v1208 + ((v1206 - v1208) & (~((v1206 - v1208) >> 31)));
  v1->timer = v1328;
  int v1210 = v1->timer;
  int * v1211 = v1->reg_ready;
  int v1212 = v1211[12];
  int v1331 = v1212 + ((v1210 - v1212) & (~((v1210 - v1212) >> 31)));
  v1->timer = v1331;
  int v1214 = v1->timer;
  int * v1215 = v1->reg_ready;
  int v1216 = v1215[13];
  int v1334 = v1216 + ((v1214 - v1216) & (~((v1214 - v1216) >> 31)));
  v1->timer = v1334;
  int v1218 = v1->timer;
  int * v1219 = v1->reg_ready;
  int v1220 = v1219[14];
  int v1337 = v1220 + ((v1218 - v1220) & (~((v1218 - v1220) >> 31)));
  v1->timer = v1337;
  int v1222 = v1->timer;
  int * v1223 = v1->reg_ready;
  int v1224 = v1223[15];
  int v1340 = v1224 + ((v1222 - v1224) & (~((v1222 - v1224) >> 31)));
  v1->timer = v1340;
  int v1226 = v1->timer;
  int * v1227 = v1->reg_ready;
  int v1228 = v1227[16];
  int v1343 = v1228 + ((v1226 - v1228) & (~((v1226 - v1228) >> 31)));
  v1->timer = v1343;
  int v1230 = v1->timer;
  int * v1231 = v1->reg_ready;
  int v1232 = v1231[17];
  int v1346 = v1232 + ((v1230 - v1232) & (~((v1230 - v1232) >> 31)));
  v1->timer = v1346;
  int v1234 = v1->timer;
  int * v1235 = v1->reg_ready;
  int v1236 = v1235[18];
  int v1349 = v1236 + ((v1234 - v1236) & (~((v1234 - v1236) >> 31)));
  v1->timer = v1349;
  int v1238 = v1->timer;
  int * v1239 = v1->reg_ready;
  int v1240 = v1239[19];
  int v1352 = v1240 + ((v1238 - v1240) & (~((v1238 - v1240) >> 31)));
  v1->timer = v1352;
  int v1242 = v1->timer;
  int * v1243 = v1->reg_ready;
  int v1244 = v1243[20];
  int v1355 = v1244 + ((v1242 - v1244) & (~((v1242 - v1244) >> 31)));
  v1->timer = v1355;
  int v1246 = v1->timer;
  int * v1247 = v1->reg_ready;
  int v1248 = v1247[21];
  int v1358 = v1248 + ((v1246 - v1248) & (~((v1246 - v1248) >> 31)));
  v1->timer = v1358;
  int v1250 = v1->timer;
  int * v1251 = v1->reg_ready;
  int v1252 = v1251[22];
  int v1361 = v1252 + ((v1250 - v1252) & (~((v1250 - v1252) >> 31)));
  v1->timer = v1361;
  int v1254 = v1->timer;
  int * v1255 = v1->reg_ready;
  int v1256 = v1255[23];
  int v1364 = v1256 + ((v1254 - v1256) & (~((v1254 - v1256) >> 31)));
  v1->timer = v1364;
  int v1258 = v1->timer;
  int * v1259 = v1->reg_ready;
  int v1260 = v1259[24];
  int v1367 = v1260 + ((v1258 - v1260) & (~((v1258 - v1260) >> 31)));
  v1->timer = v1367;
  int v1262 = v1->timer;
  int * v1263 = v1->reg_ready;
  int v1264 = v1263[25];
  int v1370 = v1264 + ((v1262 - v1264) & (~((v1262 - v1264) >> 31)));
  v1->timer = v1370;
  int v1266 = v1->timer;
  int * v1267 = v1->reg_ready;
  int v1268 = v1267[26];
  int v1373 = v1268 + ((v1266 - v1268) & (~((v1266 - v1268) >> 31)));
  v1->timer = v1373;
  int v1270 = v1->timer;
  int * v1271 = v1->reg_ready;
  int v1272 = v1271[27];
  int v1376 = v1272 + ((v1270 - v1272) & (~((v1270 - v1272) >> 31)));
  v1->timer = v1376;
  int v1274 = v1->timer;
  int * v1275 = v1->reg_ready;
  int v1276 = v1275[28];
  int v1379 = v1276 + ((v1274 - v1276) & (~((v1274 - v1276) >> 31)));
  v1->timer = v1379;
  int v1278 = v1->timer;
  int * v1279 = v1->reg_ready;
  int v1280 = v1279[29];
  int v1382 = v1280 + ((v1278 - v1280) & (~((v1278 - v1280) >> 31)));
  v1->timer = v1382;
  int v1282 = v1->timer;
  int * v1283 = v1->reg_ready;
  int v1284 = v1283[30];
  int v1385 = v1284 + ((v1282 - v1284) & (~((v1282 - v1284) >> 31)));
  v1->timer = v1385;
  int v1286 = v1->timer;
  int * v1287 = v1->reg_ready;
  int v1288 = v1287[31];
  int v1388 = v1288 + ((v1286 - v1288) & (~((v1286 - v1288) >> 31)));
  v1->timer = v1388;
  return v1;
}

struct StateT * slot_10(struct StateT * v782) {
  int v783 = v782->timer;
  int v787 = v783 + 1;
  v782->timer = v787;
  struct StateT * v785 = slot_12(v782);
  return v785;
}

struct StateT * slot_1(struct StateT * v18) {
  int v19 = v18->timer;
  int v27 = v19 + 1;
  v18->timer = v27;
  int * v21 = v18->reg_ready;
  v21[10] = v27;
  int * v23 = v18->regs;
  v23[10] = 80;
  struct StateT * v25 = slot_2(v18);
  return v25;
}

struct StateT * slot_8(struct StateT * v541) {
  int * v542 = v541->regs;
  int v543 = v542[10];
  int v544 = v542[15];
  bool v664 = v543 >= v544;
  struct StateT * v659;
  if (v664) {
    int v545 = v541->timer;
    int v665 = v545 + 15;
    v541->timer = v665;
    int * v547 = v541->saved_regs;
    int v548 = v547[5];
    int * v549 = v541->regs;
    v549[5] = v548;
    int * v551 = v541->saved_regs;
    int v552 = v551[11];
    int * v553 = v541->regs;
    v553[11] = v552;
    int * v555 = v541->saved_regs;
    int v556 = v555[12];
    int * v557 = v541->regs;
    v557[12] = v556;
    int * v559 = v541->reg_ready;
    int v560 = v541->timer;
    v559[0] = v560;
    int * v562 = v541->reg_ready;
    int v563 = v541->timer;
    v562[1] = v563;
    int * v565 = v541->reg_ready;
    int v566 = v541->timer;
    v565[2] = v566;
    int * v568 = v541->reg_ready;
    int v569 = v541->timer;
    v568[3] = v569;
    int * v571 = v541->reg_ready;
    int v572 = v541->timer;
    v571[4] = v572;
    int * v574 = v541->reg_ready;
    int v575 = v541->timer;
    v574[5] = v575;
    int * v577 = v541->reg_ready;
    int v578 = v541->timer;
    v577[6] = v578;
    int * v580 = v541->reg_ready;
    int v581 = v541->timer;
    v580[7] = v581;
    int * v583 = v541->reg_ready;
    int v584 = v541->timer;
    v583[8] = v584;
    int * v586 = v541->reg_ready;
    int v587 = v541->timer;
    v586[9] = v587;
    int * v589 = v541->reg_ready;
    int v590 = v541->timer;
    v589[10] = v590;
    int * v592 = v541->reg_ready;
    int v593 = v541->timer;
    v592[11] = v593;
    int * v595 = v541->reg_ready;
    int v596 = v541->timer;
    v595[12] = v596;
    int * v598 = v541->reg_ready;
    int v599 = v541->timer;
    v598[13] = v599;
    int * v601 = v541->reg_ready;
    int v602 = v541->timer;
    v601[14] = v602;
    int * v604 = v541->reg_ready;
    int v605 = v541->timer;
    v604[15] = v605;
    int * v607 = v541->reg_ready;
    int v608 = v541->timer;
    v607[16] = v608;
    int * v610 = v541->reg_ready;
    int v611 = v541->timer;
    v610[17] = v611;
    int * v613 = v541->reg_ready;
    int v614 = v541->timer;
    v613[18] = v614;
    int * v616 = v541->reg_ready;
    int v617 = v541->timer;
    v616[19] = v617;
    int * v619 = v541->reg_ready;
    int v620 = v541->timer;
    v619[20] = v620;
    int * v622 = v541->reg_ready;
    int v623 = v541->timer;
    v622[21] = v623;
    int * v625 = v541->reg_ready;
    int v626 = v541->timer;
    v625[22] = v626;
    int * v628 = v541->reg_ready;
    int v629 = v541->timer;
    v628[23] = v629;
    int * v631 = v541->reg_ready;
    int v632 = v541->timer;
    v631[24] = v632;
    int * v634 = v541->reg_ready;
    int v635 = v541->timer;
    v634[25] = v635;
    int * v637 = v541->reg_ready;
    int v638 = v541->timer;
    v637[26] = v638;
    int * v640 = v541->reg_ready;
    int v641 = v541->timer;
    v640[27] = v641;
    int * v643 = v541->reg_ready;
    int v644 = v541->timer;
    v643[28] = v644;
    int * v646 = v541->reg_ready;
    int v647 = v541->timer;
    v646[29] = v647;
    int * v649 = v541->reg_ready;
    int v650 = v541->timer;
    v649[30] = v650;
    int * v652 = v541->reg_ready;
    int v653 = v541->timer;
    v652[31] = v653;
    struct StateT * v655 = slot_10(v541);
    v659 = v655;
  } else {
    struct StateT * v657 = slot_10(v541);
    v659 = v657;
  }
  return v659;
}

struct StateT * slot_4(struct StateT * v58) {
  int * v59 = v58->saved_regs;
  int * v60 = v58->regs;
  int v61 = v60[5];
  v59[5] = v61;
  int v63 = v58->timer;
  int v80 = v63 + 1;
  v58->timer = v80;
  int * v65 = v58->reg_ready;
  int v66 = v65[13];
  int * v67 = v58->regs;
  int v68 = v67[13];
  int v69 = v65[10];
  int v70 = v67[10];
  int v85 = (v69 + (((v66 + ((v63 - v66) & (~((v63 - v66) >> 31)))) - v69) & (~(((v66 + ((v63 - v66) & (~((v63 - v66) >> 31)))) - v69) >> 31)))) + 1;
  v65[5] = v85;
  int * v72 = v58->regs;
  int v87 = v68 + v70;
  v72[5] = v87;
  struct StateT * v74 = slot_5(v58);
  return v74;
}

struct StateT * slot_0(struct StateT * v2) {
  int v3 = v2->timer;
  int v11 = v3 + 1;
  v2->timer = v11;
  int * v5 = v2->reg_ready;
  v5[13] = v11;
  int * v7 = v2->regs;
  v7[13] = 0;
  struct StateT * v9 = slot_1(v2);
  return v9;
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