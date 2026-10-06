// verify: leak (Eva should report untainted_timer: unknown) [unroll 65]
#define NUM_REGS 32
#define MEM_SIZE 64
#define SECRET_SIZE 10
#define SECRET_OFFSET 20
#define CACHE_ENTRIES 12
#define CACHE_WORDS 24

#ifdef EVA
#include "__fc_builtin.h"
/*@ assigns *p \from \nothing;
    taints *p; */
void koika_mark(int *p);
#define koika_assert(b, s) ((void)0)
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

struct StateT * slot_6(struct StateT * v86);
struct StateT * slot_29(struct StateT * v1252);
struct StateT * slot_25(struct StateT * v1213);
struct StateT * slot_16(struct StateT * v668);
struct StateT * slot_23(struct StateT * v948);
struct StateT * slot_5(struct StateT * v62);
struct StateT * slot_2(struct StateT * v28);
struct StateT * slot_7(struct StateT * v297);
struct StateT * slot_3(struct StateT * v41);
struct StateT * slot_26(struct StateT * v1223);
struct StateT * slot_1(struct StateT * v15);
struct StateT * slot_13(struct StateT * v604);
struct StateT * slot_24(struct StateT * v1159);
struct StateT * slot_0(struct StateT * v2);
struct StateT * slot_17(struct StateT * v676);
struct StateT * snippet(struct StateT * v0);
struct StateT * slot_4(struct StateT * v54);
struct StateT * slot_15(struct StateT * v655);
struct StateT * slot_6(struct StateT * v86) {
  int * v87 = v86->saved_regs;
  int * v88 = v86->regs;
  int v89 = v88[10];
  v87[10] = v89;
  int v91 = v86->timer;
  int v205 = v91 + 1;
  v86->timer = v205;
  int * v93 = v86->regs;
  int v94 = v93[5];
  int * v95 = v86->cache_tags;
  int v209 = (((int)((unsigned int)((int)((unsigned int)v94 >> 2)) >> 1)) & 1) * 2;
  int v96 = v95[v209];
  int v210 = ((((int)((unsigned int)((int)((unsigned int)v94 >> 2)) >> 1)) & 1) * 2) + 1;
  int v97 = v95[v210];
  int v211 = 4 + ((((int)((unsigned int)((int)((unsigned int)v94 >> 2)) >> 1)) & 3) * 2);
  int v98 = v95[v211];
  int v212 = (4 + ((((int)((unsigned int)((int)((unsigned int)v94 >> 2)) >> 1)) & 3) * 2)) + 1;
  int v99 = v95[v212];
  int v100 = v86->timer;
  int v213 = v100 + ((100 ^ (((~(((v98 ^ ((int)((unsigned int)((int)((unsigned int)v94 >> 2)) >> 1))) | (-(v98 ^ ((int)((unsigned int)((int)((unsigned int)v94 >> 2)) >> 1))))) >> 31)) | (~(((v99 ^ ((int)((unsigned int)((int)((unsigned int)v94 >> 2)) >> 1))) | (-(v99 ^ ((int)((unsigned int)((int)((unsigned int)v94 >> 2)) >> 1))))) >> 31))) & 104)) ^ (((~(((v96 ^ ((int)((unsigned int)((int)((unsigned int)v94 >> 2)) >> 1))) | (-(v96 ^ ((int)((unsigned int)((int)((unsigned int)v94 >> 2)) >> 1))))) >> 31)) | (~(((v97 ^ ((int)((unsigned int)((int)((unsigned int)v94 >> 2)) >> 1))) | (-(v97 ^ ((int)((unsigned int)((int)((unsigned int)v94 >> 2)) >> 1))))) >> 31))) & (1 ^ (100 ^ (((~(((v98 ^ ((int)((unsigned int)((int)((unsigned int)v94 >> 2)) >> 1))) | (-(v98 ^ ((int)((unsigned int)((int)((unsigned int)v94 >> 2)) >> 1))))) >> 31)) | (~(((v99 ^ ((int)((unsigned int)((int)((unsigned int)v94 >> 2)) >> 1))) | (-(v99 ^ ((int)((unsigned int)((int)((unsigned int)v94 >> 2)) >> 1))))) >> 31))) & 104)))));
  v86->timer = v213;
  int * v102 = v86->cache_vals;
  bool v214 = !(((~(((v96 ^ ((int)((unsigned int)((int)((unsigned int)v94 >> 2)) >> 1))) | (-(v96 ^ ((int)((unsigned int)((int)((unsigned int)v94 >> 2)) >> 1))))) >> 31)) | (~(((v97 ^ ((int)((unsigned int)((int)((unsigned int)v94 >> 2)) >> 1))) | (-(v97 ^ ((int)((unsigned int)((int)((unsigned int)v94 >> 2)) >> 1))))) >> 31))) == 0);
  int v195;
  if (v214) {
    int * v103 = v86->cache_age;
    int v216 = ((((int)((unsigned int)((int)((unsigned int)v94 >> 2)) >> 1)) & 1) * 2) + ((~(((v97 ^ ((int)((unsigned int)((int)((unsigned int)v94 >> 2)) >> 1))) | (-(v97 ^ ((int)((unsigned int)((int)((unsigned int)v94 >> 2)) >> 1))))) >> 31)) & 1);
    int v104 = v103[v216];
    int v105 = v103[v209];
    int v217 = v105 + ((int)((unsigned int)(v105 - v104) >> 31));
    v103[v209] = v217;
    int * v107 = v86->cache_age;
    int v108 = v107[v210];
    int v219 = v108 + ((int)((unsigned int)(v108 - v104) >> 31));
    v107[v210] = v219;
    int * v110 = v86->cache_age;
    v110[v216] = 0;
    v195 = v216;
  } else {
    int * v113 = v86->cache_age;
    int v223 = (((int)((unsigned int)((int)((unsigned int)v94 >> 2)) >> 1)) & 1) * 2;
    int v114 = v113[v223];
    int * v115 = v86->cache_tags;
    int v116 = v115[v223];
    int v117 = v113[v210];
    int v118 = v115[v210];
    bool v225 = !(((~(((v98 ^ ((int)((unsigned int)((int)((unsigned int)v94 >> 2)) >> 1))) | (-(v98 ^ ((int)((unsigned int)((int)((unsigned int)v94 >> 2)) >> 1))))) >> 31)) | (~(((v99 ^ ((int)((unsigned int)((int)((unsigned int)v94 >> 2)) >> 1))) | (-(v99 ^ ((int)((unsigned int)((int)((unsigned int)v94 >> 2)) >> 1))))) >> 31))) == 0);
    int v172;
    if (v225) {
      int * v119 = v86->cache_age;
      int v227 = (4 + ((((int)((unsigned int)((int)((unsigned int)v94 >> 2)) >> 1)) & 3) * 2)) + ((~(((v99 ^ ((int)((unsigned int)((int)((unsigned int)v94 >> 2)) >> 1))) | (-(v99 ^ ((int)((unsigned int)((int)((unsigned int)v94 >> 2)) >> 1))))) >> 31)) & 1);
      int v120 = v119[v227];
      int v121 = v119[v211];
      int v228 = v121 + ((int)((unsigned int)(v121 - v120) >> 31));
      v119[v211] = v228;
      int * v123 = v86->cache_age;
      int v124 = v123[v212];
      int v230 = v124 + ((int)((unsigned int)(v124 - v120) >> 31));
      v123[v212] = v230;
      int * v126 = v86->cache_age;
      v126[v227] = 0;
      v172 = v227;
    } else {
      int * v129 = v86->cache_age;
      int v234 = 4 + ((((int)((unsigned int)((int)((unsigned int)v94 >> 2)) >> 1)) & 3) * 2);
      int v130 = v129[v234];
      int * v131 = v86->cache_tags;
      int v132 = v131[v234];
      int v133 = v129[v212];
      int v134 = v131[v212];
      int * v135 = v86->cache_dirty;
      int v237 = (4 + ((((int)((unsigned int)((int)((unsigned int)v94 >> 2)) >> 1)) & 3) * 2)) + ((((v130 + ((~(((v132 ^ -1) | (-(v132 ^ -1))) >> 31)) & 2)) - (v133 + ((~(((v134 ^ -1) | (-(v134 ^ -1))) >> 31)) & 2))) >> 31) & 1);
      int v136 = v135[v237];
      bool v238 = !(v136 == 0);
      if (v238) {
        int * v137 = v86->cache_tags;
        int v138 = v137[v237];
        int * v139 = v86->cache_vals;
        int v241 = ((4 + ((((int)((unsigned int)((int)((unsigned int)v94 >> 2)) >> 1)) & 3) * 2)) + ((((v130 + ((~(((v132 ^ -1) | (-(v132 ^ -1))) >> 31)) & 2)) - (v133 + ((~(((v134 ^ -1) | (-(v134 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
        int v140 = v139[v241];
        int v242 = (((4 + ((((int)((unsigned int)((int)((unsigned int)v94 >> 2)) >> 1)) & 3) * 2)) + ((((v130 + ((~(((v132 ^ -1) | (-(v132 ^ -1))) >> 31)) & 2)) - (v133 + ((~(((v134 ^ -1) | (-(v134 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
        int v141 = v139[v242];
        int * v142 = v86->mem;
        int v244 = v138 * 2;
        v142[v244] = v140;
        int * v144 = v86->mem;
        int v247 = (v138 * 2) + 1;
        v144[v247] = v141;
        ;
      } else {
        ;
      }
      int * v149 = v86->mem;
      int v252 = ((int)((unsigned int)((int)((unsigned int)v94 >> 2)) >> 1)) * 2;
      int v150 = v149[v252];
      int v253 = (((int)((unsigned int)((int)((unsigned int)v94 >> 2)) >> 1)) * 2) + 1;
      int v151 = v149[v253];
      int * v152 = v86->cache_vals;
      int v255 = ((4 + ((((int)((unsigned int)((int)((unsigned int)v94 >> 2)) >> 1)) & 3) * 2)) + ((((v130 + ((~(((v132 ^ -1) | (-(v132 ^ -1))) >> 31)) & 2)) - (v133 + ((~(((v134 ^ -1) | (-(v134 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
      v152[v255] = v150;
      int * v154 = v86->cache_vals;
      int v258 = (((4 + ((((int)((unsigned int)((int)((unsigned int)v94 >> 2)) >> 1)) & 3) * 2)) + ((((v130 + ((~(((v132 ^ -1) | (-(v132 ^ -1))) >> 31)) & 2)) - (v133 + ((~(((v134 ^ -1) | (-(v134 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
      v154[v258] = v151;
      int * v156 = v86->cache_tags;
      int v261 = (int)((unsigned int)((int)((unsigned int)v94 >> 2)) >> 1);
      v156[v237] = v261;
      int * v158 = v86->cache_dirty;
      v158[v237] = 0;
      int * v160 = v86->cache_age;
      v160[v237] = 1;
      int * v162 = v86->cache_age;
      int v163 = v162[v237];
      int v164 = v162[v211];
      int v267 = v164 + ((int)((unsigned int)(v164 - v163) >> 31));
      v162[v211] = v267;
      int * v166 = v86->cache_age;
      int v167 = v166[v212];
      int v269 = v167 + ((int)((unsigned int)(v167 - v163) >> 31));
      v166[v212] = v269;
      int * v169 = v86->cache_age;
      v169[v237] = 0;
      v172 = v237;
    }
    int * v173 = v86->cache_vals;
    int v272 = v172 * 2;
    int v174 = v173[v272];
    int v273 = (v172 * 2) + 1;
    int v175 = v173[v273];
    int v274 = (((((int)((unsigned int)((int)((unsigned int)v94 >> 2)) >> 1)) & 1) * 2) + ((((v114 + ((~(((v116 ^ -1) | (-(v116 ^ -1))) >> 31)) & 2)) - (v117 + ((~(((v118 ^ -1) | (-(v118 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
    v173[v274] = v174;
    int * v177 = v86->cache_vals;
    int v277 = ((((((int)((unsigned int)((int)((unsigned int)v94 >> 2)) >> 1)) & 1) * 2) + ((((v114 + ((~(((v116 ^ -1) | (-(v116 ^ -1))) >> 31)) & 2)) - (v117 + ((~(((v118 ^ -1) | (-(v118 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
    v177[v277] = v175;
    int * v179 = v86->cache_tags;
    int v280 = ((((int)((unsigned int)((int)((unsigned int)v94 >> 2)) >> 1)) & 1) * 2) + ((((v114 + ((~(((v116 ^ -1) | (-(v116 ^ -1))) >> 31)) & 2)) - (v117 + ((~(((v118 ^ -1) | (-(v118 ^ -1))) >> 31)) & 2))) >> 31) & 1);
    int v281 = (int)((unsigned int)((int)((unsigned int)v94 >> 2)) >> 1);
    v179[v280] = v281;
    int * v181 = v86->cache_dirty;
    v181[v280] = 0;
    int * v183 = v86->cache_age;
    v183[v280] = 1;
    int * v185 = v86->cache_age;
    int v186 = v185[v280];
    int v187 = v185[v209];
    int v287 = v187 + ((int)((unsigned int)(v187 - v186) >> 31));
    v185[v209] = v287;
    int * v189 = v86->cache_age;
    int v190 = v189[v210];
    int v289 = v190 + ((int)((unsigned int)(v190 - v186) >> 31));
    v189[v210] = v289;
    int * v192 = v86->cache_age;
    v192[v280] = 0;
    v195 = v280;
  }
  int v292 = (v195 * 2) + (((int)((unsigned int)v94 >> 2)) & 1);
  int v196 = v102[v292];
  int * v197 = v86->regs;
  v197[10] = v196;
  struct StateT * v199 = slot_7(v86);
  return v199;
}

struct StateT * slot_29(struct StateT * v1252) {
  int * v1253 = v1252->regs;
  int v1254 = v1253[10];
  int v1255 = v1253[11];
  bool v1271 = !(v1254 == v1255);
  struct StateT * v1266;
  if (v1271) {
    int v1256 = v1252->timer;
    int v1272 = v1256 + 15;
    v1252->timer = v1272;
    int * v1258 = v1252->saved_regs;
    int v1259 = v1258[14];
    int * v1260 = v1252->regs;
    v1260[14] = v1259;
    struct StateT * v1262 = slot_15(v1252);
    v1266 = v1262;
  } else {
    struct StateT * v1264 = slot_16(v1252);
    v1266 = v1264;
  }
  return v1266;
}

struct StateT * slot_25(struct StateT * v1213) {
  int v1214 = v1213->timer;
  int v1219 = v1214 + 1;
  v1213->timer = v1219;
  int * v1216 = v1213->regs;
  v1216[10] = 1;
  return v1213;
}

struct StateT * slot_16(struct StateT * v668) {
  int v669 = v668->timer;
  int v673 = v669 + 1;
  v668->timer = v673;
  struct StateT * v671 = slot_4(v668);
  return v671;
}

struct StateT * slot_23(struct StateT * v948) {
  int * v949 = v948->saved_regs;
  int * v950 = v948->regs;
  int v951 = v950[11];
  v949[11] = v951;
  int v953 = v948->timer;
  int v1067 = v953 + 1;
  v948->timer = v1067;
  int * v955 = v948->regs;
  int v956 = v955[6];
  int * v957 = v948->cache_tags;
  int v1071 = (((int)((unsigned int)((int)((unsigned int)v956 >> 2)) >> 1)) & 1) * 2;
  int v958 = v957[v1071];
  int v1072 = ((((int)((unsigned int)((int)((unsigned int)v956 >> 2)) >> 1)) & 1) * 2) + 1;
  int v959 = v957[v1072];
  int v1073 = 4 + ((((int)((unsigned int)((int)((unsigned int)v956 >> 2)) >> 1)) & 3) * 2);
  int v960 = v957[v1073];
  int v1074 = (4 + ((((int)((unsigned int)((int)((unsigned int)v956 >> 2)) >> 1)) & 3) * 2)) + 1;
  int v961 = v957[v1074];
  int v962 = v948->timer;
  int v1075 = v962 + ((100 ^ (((~(((v960 ^ ((int)((unsigned int)((int)((unsigned int)v956 >> 2)) >> 1))) | (-(v960 ^ ((int)((unsigned int)((int)((unsigned int)v956 >> 2)) >> 1))))) >> 31)) | (~(((v961 ^ ((int)((unsigned int)((int)((unsigned int)v956 >> 2)) >> 1))) | (-(v961 ^ ((int)((unsigned int)((int)((unsigned int)v956 >> 2)) >> 1))))) >> 31))) & 104)) ^ (((~(((v958 ^ ((int)((unsigned int)((int)((unsigned int)v956 >> 2)) >> 1))) | (-(v958 ^ ((int)((unsigned int)((int)((unsigned int)v956 >> 2)) >> 1))))) >> 31)) | (~(((v959 ^ ((int)((unsigned int)((int)((unsigned int)v956 >> 2)) >> 1))) | (-(v959 ^ ((int)((unsigned int)((int)((unsigned int)v956 >> 2)) >> 1))))) >> 31))) & (1 ^ (100 ^ (((~(((v960 ^ ((int)((unsigned int)((int)((unsigned int)v956 >> 2)) >> 1))) | (-(v960 ^ ((int)((unsigned int)((int)((unsigned int)v956 >> 2)) >> 1))))) >> 31)) | (~(((v961 ^ ((int)((unsigned int)((int)((unsigned int)v956 >> 2)) >> 1))) | (-(v961 ^ ((int)((unsigned int)((int)((unsigned int)v956 >> 2)) >> 1))))) >> 31))) & 104)))));
  v948->timer = v1075;
  int * v964 = v948->cache_vals;
  bool v1076 = !(((~(((v958 ^ ((int)((unsigned int)((int)((unsigned int)v956 >> 2)) >> 1))) | (-(v958 ^ ((int)((unsigned int)((int)((unsigned int)v956 >> 2)) >> 1))))) >> 31)) | (~(((v959 ^ ((int)((unsigned int)((int)((unsigned int)v956 >> 2)) >> 1))) | (-(v959 ^ ((int)((unsigned int)((int)((unsigned int)v956 >> 2)) >> 1))))) >> 31))) == 0);
  int v1057;
  if (v1076) {
    int * v965 = v948->cache_age;
    int v1078 = ((((int)((unsigned int)((int)((unsigned int)v956 >> 2)) >> 1)) & 1) * 2) + ((~(((v959 ^ ((int)((unsigned int)((int)((unsigned int)v956 >> 2)) >> 1))) | (-(v959 ^ ((int)((unsigned int)((int)((unsigned int)v956 >> 2)) >> 1))))) >> 31)) & 1);
    int v966 = v965[v1078];
    int v967 = v965[v1071];
    int v1079 = v967 + ((int)((unsigned int)(v967 - v966) >> 31));
    v965[v1071] = v1079;
    int * v969 = v948->cache_age;
    int v970 = v969[v1072];
    int v1081 = v970 + ((int)((unsigned int)(v970 - v966) >> 31));
    v969[v1072] = v1081;
    int * v972 = v948->cache_age;
    v972[v1078] = 0;
    v1057 = v1078;
  } else {
    int * v975 = v948->cache_age;
    int v1085 = (((int)((unsigned int)((int)((unsigned int)v956 >> 2)) >> 1)) & 1) * 2;
    int v976 = v975[v1085];
    int * v977 = v948->cache_tags;
    int v978 = v977[v1085];
    int v979 = v975[v1072];
    int v980 = v977[v1072];
    bool v1087 = !(((~(((v960 ^ ((int)((unsigned int)((int)((unsigned int)v956 >> 2)) >> 1))) | (-(v960 ^ ((int)((unsigned int)((int)((unsigned int)v956 >> 2)) >> 1))))) >> 31)) | (~(((v961 ^ ((int)((unsigned int)((int)((unsigned int)v956 >> 2)) >> 1))) | (-(v961 ^ ((int)((unsigned int)((int)((unsigned int)v956 >> 2)) >> 1))))) >> 31))) == 0);
    int v1034;
    if (v1087) {
      int * v981 = v948->cache_age;
      int v1089 = (4 + ((((int)((unsigned int)((int)((unsigned int)v956 >> 2)) >> 1)) & 3) * 2)) + ((~(((v961 ^ ((int)((unsigned int)((int)((unsigned int)v956 >> 2)) >> 1))) | (-(v961 ^ ((int)((unsigned int)((int)((unsigned int)v956 >> 2)) >> 1))))) >> 31)) & 1);
      int v982 = v981[v1089];
      int v983 = v981[v1073];
      int v1090 = v983 + ((int)((unsigned int)(v983 - v982) >> 31));
      v981[v1073] = v1090;
      int * v985 = v948->cache_age;
      int v986 = v985[v1074];
      int v1092 = v986 + ((int)((unsigned int)(v986 - v982) >> 31));
      v985[v1074] = v1092;
      int * v988 = v948->cache_age;
      v988[v1089] = 0;
      v1034 = v1089;
    } else {
      int * v991 = v948->cache_age;
      int v1096 = 4 + ((((int)((unsigned int)((int)((unsigned int)v956 >> 2)) >> 1)) & 3) * 2);
      int v992 = v991[v1096];
      int * v993 = v948->cache_tags;
      int v994 = v993[v1096];
      int v995 = v991[v1074];
      int v996 = v993[v1074];
      int * v997 = v948->cache_dirty;
      int v1099 = (4 + ((((int)((unsigned int)((int)((unsigned int)v956 >> 2)) >> 1)) & 3) * 2)) + ((((v992 + ((~(((v994 ^ -1) | (-(v994 ^ -1))) >> 31)) & 2)) - (v995 + ((~(((v996 ^ -1) | (-(v996 ^ -1))) >> 31)) & 2))) >> 31) & 1);
      int v998 = v997[v1099];
      bool v1100 = !(v998 == 0);
      if (v1100) {
        int * v999 = v948->cache_tags;
        int v1000 = v999[v1099];
        int * v1001 = v948->cache_vals;
        int v1103 = ((4 + ((((int)((unsigned int)((int)((unsigned int)v956 >> 2)) >> 1)) & 3) * 2)) + ((((v992 + ((~(((v994 ^ -1) | (-(v994 ^ -1))) >> 31)) & 2)) - (v995 + ((~(((v996 ^ -1) | (-(v996 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
        int v1002 = v1001[v1103];
        int v1104 = (((4 + ((((int)((unsigned int)((int)((unsigned int)v956 >> 2)) >> 1)) & 3) * 2)) + ((((v992 + ((~(((v994 ^ -1) | (-(v994 ^ -1))) >> 31)) & 2)) - (v995 + ((~(((v996 ^ -1) | (-(v996 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
        int v1003 = v1001[v1104];
        int * v1004 = v948->mem;
        int v1106 = v1000 * 2;
        v1004[v1106] = v1002;
        int * v1006 = v948->mem;
        int v1109 = (v1000 * 2) + 1;
        v1006[v1109] = v1003;
        ;
      } else {
        ;
      }
      int * v1011 = v948->mem;
      int v1114 = ((int)((unsigned int)((int)((unsigned int)v956 >> 2)) >> 1)) * 2;
      int v1012 = v1011[v1114];
      int v1115 = (((int)((unsigned int)((int)((unsigned int)v956 >> 2)) >> 1)) * 2) + 1;
      int v1013 = v1011[v1115];
      int * v1014 = v948->cache_vals;
      int v1117 = ((4 + ((((int)((unsigned int)((int)((unsigned int)v956 >> 2)) >> 1)) & 3) * 2)) + ((((v992 + ((~(((v994 ^ -1) | (-(v994 ^ -1))) >> 31)) & 2)) - (v995 + ((~(((v996 ^ -1) | (-(v996 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
      v1014[v1117] = v1012;
      int * v1016 = v948->cache_vals;
      int v1120 = (((4 + ((((int)((unsigned int)((int)((unsigned int)v956 >> 2)) >> 1)) & 3) * 2)) + ((((v992 + ((~(((v994 ^ -1) | (-(v994 ^ -1))) >> 31)) & 2)) - (v995 + ((~(((v996 ^ -1) | (-(v996 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
      v1016[v1120] = v1013;
      int * v1018 = v948->cache_tags;
      int v1123 = (int)((unsigned int)((int)((unsigned int)v956 >> 2)) >> 1);
      v1018[v1099] = v1123;
      int * v1020 = v948->cache_dirty;
      v1020[v1099] = 0;
      int * v1022 = v948->cache_age;
      v1022[v1099] = 1;
      int * v1024 = v948->cache_age;
      int v1025 = v1024[v1099];
      int v1026 = v1024[v1073];
      int v1129 = v1026 + ((int)((unsigned int)(v1026 - v1025) >> 31));
      v1024[v1073] = v1129;
      int * v1028 = v948->cache_age;
      int v1029 = v1028[v1074];
      int v1131 = v1029 + ((int)((unsigned int)(v1029 - v1025) >> 31));
      v1028[v1074] = v1131;
      int * v1031 = v948->cache_age;
      v1031[v1099] = 0;
      v1034 = v1099;
    }
    int * v1035 = v948->cache_vals;
    int v1134 = v1034 * 2;
    int v1036 = v1035[v1134];
    int v1135 = (v1034 * 2) + 1;
    int v1037 = v1035[v1135];
    int v1136 = (((((int)((unsigned int)((int)((unsigned int)v956 >> 2)) >> 1)) & 1) * 2) + ((((v976 + ((~(((v978 ^ -1) | (-(v978 ^ -1))) >> 31)) & 2)) - (v979 + ((~(((v980 ^ -1) | (-(v980 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
    v1035[v1136] = v1036;
    int * v1039 = v948->cache_vals;
    int v1139 = ((((((int)((unsigned int)((int)((unsigned int)v956 >> 2)) >> 1)) & 1) * 2) + ((((v976 + ((~(((v978 ^ -1) | (-(v978 ^ -1))) >> 31)) & 2)) - (v979 + ((~(((v980 ^ -1) | (-(v980 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
    v1039[v1139] = v1037;
    int * v1041 = v948->cache_tags;
    int v1142 = ((((int)((unsigned int)((int)((unsigned int)v956 >> 2)) >> 1)) & 1) * 2) + ((((v976 + ((~(((v978 ^ -1) | (-(v978 ^ -1))) >> 31)) & 2)) - (v979 + ((~(((v980 ^ -1) | (-(v980 ^ -1))) >> 31)) & 2))) >> 31) & 1);
    int v1143 = (int)((unsigned int)((int)((unsigned int)v956 >> 2)) >> 1);
    v1041[v1142] = v1143;
    int * v1043 = v948->cache_dirty;
    v1043[v1142] = 0;
    int * v1045 = v948->cache_age;
    v1045[v1142] = 1;
    int * v1047 = v948->cache_age;
    int v1048 = v1047[v1142];
    int v1049 = v1047[v1071];
    int v1149 = v1049 + ((int)((unsigned int)(v1049 - v1048) >> 31));
    v1047[v1071] = v1149;
    int * v1051 = v948->cache_age;
    int v1052 = v1051[v1072];
    int v1151 = v1052 + ((int)((unsigned int)(v1052 - v1048) >> 31));
    v1051[v1072] = v1151;
    int * v1054 = v948->cache_age;
    v1054[v1142] = 0;
    v1057 = v1142;
  }
  int v1154 = (v1057 * 2) + (((int)((unsigned int)v956 >> 2)) & 1);
  int v1058 = v964[v1154];
  int * v1059 = v948->regs;
  v1059[11] = v1058;
  struct StateT * v1061 = slot_24(v948);
  return v1061;
}

struct StateT * slot_5(struct StateT * v62) {
  int * v63 = v62->saved_regs;
  int * v64 = v62->regs;
  int v65 = v64[5];
  v63[5] = v65;
  int v67 = v62->timer;
  int v79 = v67 + 1;
  v62->timer = v79;
  int * v69 = v62->regs;
  int v70 = v69[12];
  int v71 = v69[14];
  int v83 = v70 + v71;
  v69[5] = v83;
  struct StateT * v73 = slot_6(v62);
  return v73;
}

struct StateT * slot_2(struct StateT * v28) {
  int v29 = v28->timer;
  int v35 = v29 + 1;
  v28->timer = v35;
  int * v31 = v28->regs;
  v31[14] = 0;
  struct StateT * v33 = slot_3(v28);
  return v33;
}

struct StateT * slot_7(struct StateT * v297) {
  int * v298 = v297->saved_regs;
  int * v299 = v297->regs;
  int v300 = v299[6];
  v298[6] = v300;
  int v302 = v297->timer;
  int v314 = v302 + 1;
  v297->timer = v314;
  int * v304 = v297->regs;
  int v305 = v304[13];
  int v306 = v304[14];
  int v318 = v305 + v306;
  v304[6] = v318;
  struct StateT * v308 = slot_23(v297);
  return v308;
}

struct StateT * slot_3(struct StateT * v41) {
  int v42 = v41->timer;
  int v48 = v42 + 1;
  v41->timer = v48;
  int * v44 = v41->regs;
  v44[15] = 16;
  struct StateT * v46 = slot_4(v41);
  return v46;
}

struct StateT * slot_26(struct StateT * v1223) {
  int v1224 = v1223->timer;
  int v1228 = v1224 + 1;
  v1223->timer = v1228;
  struct StateT * v1226 = slot_13(v1223);
  return v1226;
}

struct StateT * slot_1(struct StateT * v15) {
  int v16 = v15->timer;
  int v22 = v16 + 1;
  v15->timer = v22;
  int * v18 = v15->regs;
  v18[13] = 80;
  struct StateT * v20 = slot_2(v15);
  return v20;
}

struct StateT * slot_13(struct StateT * v604) {
  int * v605 = v604->saved_regs;
  int * v606 = v604->regs;
  int v607 = v606[14];
  v605[14] = v607;
  int v609 = v604->timer;
  int v620 = v609 + 1;
  v604->timer = v620;
  int * v611 = v604->regs;
  int v612 = v611[14];
  int v622 = v612 + 4;
  v611[14] = v622;
  struct StateT * v614 = slot_29(v604);
  return v614;
}

struct StateT * slot_24(struct StateT * v1159) {
  int * v1160 = v1159->regs;
  int v1161 = v1160[14];
  int v1162 = v1160[15];
  bool v1190 = v1161 >= v1162;
  struct StateT * v1185;
  if (v1190) {
    int v1163 = v1159->timer;
    int v1191 = v1163 + 15;
    v1159->timer = v1191;
    int * v1165 = v1159->saved_regs;
    int v1166 = v1165[5];
    int * v1167 = v1159->regs;
    v1167[5] = v1166;
    int * v1169 = v1159->saved_regs;
    int v1170 = v1169[10];
    int * v1171 = v1159->regs;
    v1171[10] = v1170;
    int * v1173 = v1159->saved_regs;
    int v1174 = v1173[6];
    int * v1175 = v1159->regs;
    v1175[6] = v1174;
    int * v1177 = v1159->saved_regs;
    int v1178 = v1177[11];
    int * v1179 = v1159->regs;
    v1179[11] = v1178;
    struct StateT * v1181 = slot_25(v1159);
    v1185 = v1181;
  } else {
    struct StateT * v1183 = slot_26(v1159);
    v1185 = v1183;
  }
  return v1185;
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

struct StateT * slot_17(struct StateT * v676) {
  int v677 = v676->timer;
  int v680 = v677 + 1;
  v676->timer = v680;
  return v676;
}

struct StateT * snippet(struct StateT * v0) {
  struct StateT * v1 = slot_0(v0);
  return v1;
}

struct StateT * slot_4(struct StateT * v54) {
  int v55 = v54->timer;
  int v59 = v55 + 1;
  v54->timer = v59;
  struct StateT * v57 = slot_5(v54);
  return v57;
}

struct StateT * slot_15(struct StateT * v655) {
  int v656 = v655->timer;
  int v662 = v656 + 1;
  v655->timer = v662;
  int * v658 = v655->regs;
  v658[10] = 0;
  struct StateT * v660 = slot_17(v655);
  return v660;
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
  //@ assert untainted_timer: !\tainted(s1_->timer==s2_->timer);
  koika_assert(s1_->timer==s2_->timer, "timing leak");
  return 0;
}