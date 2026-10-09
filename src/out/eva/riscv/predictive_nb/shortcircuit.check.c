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

struct StateT * slot_6(struct StateT * v106);
struct StateT * slot_29(struct StateT * v1380);
struct StateT * slot_25(struct StateT * v1331);
struct StateT * slot_16(struct StateT * v742);
struct StateT * slot_23(struct StateT * v1042);
struct StateT * slot_5(struct StateT * v74);
struct StateT * slot_2(struct StateT * v34);
struct StateT * slot_7(struct StateT * v321);
struct StateT * slot_3(struct StateT * v50);
struct StateT * slot_26(struct StateT * v1344);
struct StateT * slot_1(struct StateT * v18);
struct StateT * slot_13(struct StateT * v663);
struct StateT * slot_24(struct StateT * v1257);
struct StateT * slot_0(struct StateT * v2);
struct StateT * slot_17(struct StateT * v750);
struct StateT * snippet(struct StateT * v0);
struct StateT * slot_4(struct StateT * v66);
struct StateT * slot_15(struct StateT * v726);
struct StateT * slot_6(struct StateT * v106) {
  int * v107 = v106->saved_regs;
  int * v108 = v106->regs;
  int v109 = v108[10];
  v107[10] = v109;
  int v111 = v106->timer;
  int v227 = v111 + 1;
  v106->timer = v227;
  int * v113 = v106->reg_ready;
  int v114 = v113[5];
  int * v115 = v106->regs;
  int v116 = v115[5];
  int * v117 = v106->cache_tags;
  int v232 = (((int)((unsigned int)((int)((unsigned int)v116 >> 2)) >> 1)) & 1) * 2;
  int v118 = v117[v232];
  int v233 = ((((int)((unsigned int)((int)((unsigned int)v116 >> 2)) >> 1)) & 1) * 2) + 1;
  int v119 = v117[v233];
  int v234 = 4 + ((((int)((unsigned int)((int)((unsigned int)v116 >> 2)) >> 1)) & 3) * 2);
  int v120 = v117[v234];
  int v235 = (4 + ((((int)((unsigned int)((int)((unsigned int)v116 >> 2)) >> 1)) & 3) * 2)) + 1;
  int v121 = v117[v235];
  int * v122 = v106->cache_vals;
  bool v236 = !(((~(((v118 ^ ((int)((unsigned int)((int)((unsigned int)v116 >> 2)) >> 1))) | (-(v118 ^ ((int)((unsigned int)((int)((unsigned int)v116 >> 2)) >> 1))))) >> 31)) | (~(((v119 ^ ((int)((unsigned int)((int)((unsigned int)v116 >> 2)) >> 1))) | (-(v119 ^ ((int)((unsigned int)((int)((unsigned int)v116 >> 2)) >> 1))))) >> 31))) == 0);
  int v215;
  if (v236) {
    int * v123 = v106->cache_age;
    int v238 = ((((int)((unsigned int)((int)((unsigned int)v116 >> 2)) >> 1)) & 1) * 2) + ((~(((v119 ^ ((int)((unsigned int)((int)((unsigned int)v116 >> 2)) >> 1))) | (-(v119 ^ ((int)((unsigned int)((int)((unsigned int)v116 >> 2)) >> 1))))) >> 31)) & 1);
    int v124 = v123[v238];
    int v125 = v123[v232];
    int v239 = v125 + ((int)((unsigned int)(v125 - v124) >> 31));
    v123[v232] = v239;
    int * v127 = v106->cache_age;
    int v128 = v127[v233];
    int v241 = v128 + ((int)((unsigned int)(v128 - v124) >> 31));
    v127[v233] = v241;
    int * v130 = v106->cache_age;
    v130[v238] = 0;
    v215 = v238;
  } else {
    int * v133 = v106->cache_age;
    int v245 = (((int)((unsigned int)((int)((unsigned int)v116 >> 2)) >> 1)) & 1) * 2;
    int v134 = v133[v245];
    int * v135 = v106->cache_tags;
    int v136 = v135[v245];
    int v137 = v133[v233];
    int v138 = v135[v233];
    bool v247 = !(((~(((v120 ^ ((int)((unsigned int)((int)((unsigned int)v116 >> 2)) >> 1))) | (-(v120 ^ ((int)((unsigned int)((int)((unsigned int)v116 >> 2)) >> 1))))) >> 31)) | (~(((v121 ^ ((int)((unsigned int)((int)((unsigned int)v116 >> 2)) >> 1))) | (-(v121 ^ ((int)((unsigned int)((int)((unsigned int)v116 >> 2)) >> 1))))) >> 31))) == 0);
    int v192;
    if (v247) {
      int * v139 = v106->cache_age;
      int v249 = (4 + ((((int)((unsigned int)((int)((unsigned int)v116 >> 2)) >> 1)) & 3) * 2)) + ((~(((v121 ^ ((int)((unsigned int)((int)((unsigned int)v116 >> 2)) >> 1))) | (-(v121 ^ ((int)((unsigned int)((int)((unsigned int)v116 >> 2)) >> 1))))) >> 31)) & 1);
      int v140 = v139[v249];
      int v141 = v139[v234];
      int v250 = v141 + ((int)((unsigned int)(v141 - v140) >> 31));
      v139[v234] = v250;
      int * v143 = v106->cache_age;
      int v144 = v143[v235];
      int v252 = v144 + ((int)((unsigned int)(v144 - v140) >> 31));
      v143[v235] = v252;
      int * v146 = v106->cache_age;
      v146[v249] = 0;
      v192 = v249;
    } else {
      int * v149 = v106->cache_age;
      int v256 = 4 + ((((int)((unsigned int)((int)((unsigned int)v116 >> 2)) >> 1)) & 3) * 2);
      int v150 = v149[v256];
      int * v151 = v106->cache_tags;
      int v152 = v151[v256];
      int v153 = v149[v235];
      int v154 = v151[v235];
      int * v155 = v106->cache_dirty;
      int v259 = (4 + ((((int)((unsigned int)((int)((unsigned int)v116 >> 2)) >> 1)) & 3) * 2)) + ((((v150 + ((~(((v152 ^ -1) | (-(v152 ^ -1))) >> 31)) & 2)) - (v153 + ((~(((v154 ^ -1) | (-(v154 ^ -1))) >> 31)) & 2))) >> 31) & 1);
      int v156 = v155[v259];
      bool v260 = !(v156 == 0);
      if (v260) {
        int * v157 = v106->cache_tags;
        int v158 = v157[v259];
        int * v159 = v106->cache_vals;
        int v263 = ((4 + ((((int)((unsigned int)((int)((unsigned int)v116 >> 2)) >> 1)) & 3) * 2)) + ((((v150 + ((~(((v152 ^ -1) | (-(v152 ^ -1))) >> 31)) & 2)) - (v153 + ((~(((v154 ^ -1) | (-(v154 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
        int v160 = v159[v263];
        int v264 = (((4 + ((((int)((unsigned int)((int)((unsigned int)v116 >> 2)) >> 1)) & 3) * 2)) + ((((v150 + ((~(((v152 ^ -1) | (-(v152 ^ -1))) >> 31)) & 2)) - (v153 + ((~(((v154 ^ -1) | (-(v154 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
        int v161 = v159[v264];
        int * v162 = v106->mem;
        int v266 = v158 * 2;
        v162[v266] = v160;
        int * v164 = v106->mem;
        int v269 = (v158 * 2) + 1;
        v164[v269] = v161;
        ;
      } else {
        ;
      }
      int * v169 = v106->mem;
      int v274 = ((int)((unsigned int)((int)((unsigned int)v116 >> 2)) >> 1)) * 2;
      int v170 = v169[v274];
      int v275 = (((int)((unsigned int)((int)((unsigned int)v116 >> 2)) >> 1)) * 2) + 1;
      int v171 = v169[v275];
      int * v172 = v106->cache_vals;
      int v277 = ((4 + ((((int)((unsigned int)((int)((unsigned int)v116 >> 2)) >> 1)) & 3) * 2)) + ((((v150 + ((~(((v152 ^ -1) | (-(v152 ^ -1))) >> 31)) & 2)) - (v153 + ((~(((v154 ^ -1) | (-(v154 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
      v172[v277] = v170;
      int * v174 = v106->cache_vals;
      int v280 = (((4 + ((((int)((unsigned int)((int)((unsigned int)v116 >> 2)) >> 1)) & 3) * 2)) + ((((v150 + ((~(((v152 ^ -1) | (-(v152 ^ -1))) >> 31)) & 2)) - (v153 + ((~(((v154 ^ -1) | (-(v154 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
      v174[v280] = v171;
      int * v176 = v106->cache_tags;
      int v283 = (int)((unsigned int)((int)((unsigned int)v116 >> 2)) >> 1);
      v176[v259] = v283;
      int * v178 = v106->cache_dirty;
      v178[v259] = 0;
      int * v180 = v106->cache_age;
      v180[v259] = 1;
      int * v182 = v106->cache_age;
      int v183 = v182[v259];
      int v184 = v182[v234];
      int v289 = v184 + ((int)((unsigned int)(v184 - v183) >> 31));
      v182[v234] = v289;
      int * v186 = v106->cache_age;
      int v187 = v186[v235];
      int v291 = v187 + ((int)((unsigned int)(v187 - v183) >> 31));
      v186[v235] = v291;
      int * v189 = v106->cache_age;
      v189[v259] = 0;
      v192 = v259;
    }
    int * v193 = v106->cache_vals;
    int v294 = v192 * 2;
    int v194 = v193[v294];
    int v295 = (v192 * 2) + 1;
    int v195 = v193[v295];
    int v296 = (((((int)((unsigned int)((int)((unsigned int)v116 >> 2)) >> 1)) & 1) * 2) + ((((v134 + ((~(((v136 ^ -1) | (-(v136 ^ -1))) >> 31)) & 2)) - (v137 + ((~(((v138 ^ -1) | (-(v138 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
    v193[v296] = v194;
    int * v197 = v106->cache_vals;
    int v299 = ((((((int)((unsigned int)((int)((unsigned int)v116 >> 2)) >> 1)) & 1) * 2) + ((((v134 + ((~(((v136 ^ -1) | (-(v136 ^ -1))) >> 31)) & 2)) - (v137 + ((~(((v138 ^ -1) | (-(v138 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
    v197[v299] = v195;
    int * v199 = v106->cache_tags;
    int v302 = ((((int)((unsigned int)((int)((unsigned int)v116 >> 2)) >> 1)) & 1) * 2) + ((((v134 + ((~(((v136 ^ -1) | (-(v136 ^ -1))) >> 31)) & 2)) - (v137 + ((~(((v138 ^ -1) | (-(v138 ^ -1))) >> 31)) & 2))) >> 31) & 1);
    int v303 = (int)((unsigned int)((int)((unsigned int)v116 >> 2)) >> 1);
    v199[v302] = v303;
    int * v201 = v106->cache_dirty;
    v201[v302] = 0;
    int * v203 = v106->cache_age;
    v203[v302] = 1;
    int * v205 = v106->cache_age;
    int v206 = v205[v302];
    int v207 = v205[v232];
    int v309 = v207 + ((int)((unsigned int)(v207 - v206) >> 31));
    v205[v232] = v309;
    int * v209 = v106->cache_age;
    int v210 = v209[v233];
    int v311 = v210 + ((int)((unsigned int)(v210 - v206) >> 31));
    v209[v233] = v311;
    int * v212 = v106->cache_age;
    v212[v302] = 0;
    v215 = v302;
  }
  int v314 = (v215 * 2) + (((int)((unsigned int)v116 >> 2)) & 1);
  int v216 = v122[v314];
  int * v217 = v106->reg_ready;
  int v316 = ((v114 + ((v111 - v114) & (~((v111 - v114) >> 31)))) + 1) + ((100 ^ (((~(((v120 ^ ((int)((unsigned int)((int)((unsigned int)v116 >> 2)) >> 1))) | (-(v120 ^ ((int)((unsigned int)((int)((unsigned int)v116 >> 2)) >> 1))))) >> 31)) | (~(((v121 ^ ((int)((unsigned int)((int)((unsigned int)v116 >> 2)) >> 1))) | (-(v121 ^ ((int)((unsigned int)((int)((unsigned int)v116 >> 2)) >> 1))))) >> 31))) & 104)) ^ (((~(((v118 ^ ((int)((unsigned int)((int)((unsigned int)v116 >> 2)) >> 1))) | (-(v118 ^ ((int)((unsigned int)((int)((unsigned int)v116 >> 2)) >> 1))))) >> 31)) | (~(((v119 ^ ((int)((unsigned int)((int)((unsigned int)v116 >> 2)) >> 1))) | (-(v119 ^ ((int)((unsigned int)((int)((unsigned int)v116 >> 2)) >> 1))))) >> 31))) & (1 ^ (100 ^ (((~(((v120 ^ ((int)((unsigned int)((int)((unsigned int)v116 >> 2)) >> 1))) | (-(v120 ^ ((int)((unsigned int)((int)((unsigned int)v116 >> 2)) >> 1))))) >> 31)) | (~(((v121 ^ ((int)((unsigned int)((int)((unsigned int)v116 >> 2)) >> 1))) | (-(v121 ^ ((int)((unsigned int)((int)((unsigned int)v116 >> 2)) >> 1))))) >> 31))) & 104)))));
  v217[10] = v316;
  int * v219 = v106->regs;
  v219[10] = v216;
  struct StateT * v221 = slot_7(v106);
  return v221;
}

struct StateT * slot_29(struct StateT * v1380) {
  int * v1381 = v1380->regs;
  int v1382 = v1381[10];
  int v1383 = v1381[11];
  bool v1402 = !(v1382 == v1383);
  struct StateT * v1397;
  if (v1402) {
    int v1384 = v1380->timer;
    int v1403 = v1384 + 15;
    v1380->timer = v1403;
    int * v1386 = v1380->saved_regs;
    int v1387 = v1386[14];
    int * v1388 = v1380->regs;
    v1388[14] = v1387;
    int * v1390 = v1380->reg_ready;
    int v1391 = v1380->timer;
    v1390[14] = v1391;
    struct StateT * v1393 = slot_15(v1380);
    v1397 = v1393;
  } else {
    struct StateT * v1395 = slot_16(v1380);
    v1397 = v1395;
  }
  return v1397;
}

struct StateT * slot_25(struct StateT * v1331) {
  int v1332 = v1331->timer;
  int v1339 = v1332 + 1;
  v1331->timer = v1339;
  int * v1334 = v1331->reg_ready;
  v1334[10] = v1339;
  int * v1336 = v1331->regs;
  v1336[10] = 1;
  return v1331;
}

struct StateT * slot_16(struct StateT * v742) {
  int v743 = v742->timer;
  int v747 = v743 + 1;
  v742->timer = v747;
  struct StateT * v745 = slot_4(v742);
  return v745;
}

struct StateT * slot_23(struct StateT * v1042) {
  int * v1043 = v1042->saved_regs;
  int * v1044 = v1042->regs;
  int v1045 = v1044[11];
  v1043[11] = v1045;
  int v1047 = v1042->timer;
  int v1163 = v1047 + 1;
  v1042->timer = v1163;
  int * v1049 = v1042->reg_ready;
  int v1050 = v1049[6];
  int * v1051 = v1042->regs;
  int v1052 = v1051[6];
  int * v1053 = v1042->cache_tags;
  int v1168 = (((int)((unsigned int)((int)((unsigned int)v1052 >> 2)) >> 1)) & 1) * 2;
  int v1054 = v1053[v1168];
  int v1169 = ((((int)((unsigned int)((int)((unsigned int)v1052 >> 2)) >> 1)) & 1) * 2) + 1;
  int v1055 = v1053[v1169];
  int v1170 = 4 + ((((int)((unsigned int)((int)((unsigned int)v1052 >> 2)) >> 1)) & 3) * 2);
  int v1056 = v1053[v1170];
  int v1171 = (4 + ((((int)((unsigned int)((int)((unsigned int)v1052 >> 2)) >> 1)) & 3) * 2)) + 1;
  int v1057 = v1053[v1171];
  int * v1058 = v1042->cache_vals;
  bool v1172 = !(((~(((v1054 ^ ((int)((unsigned int)((int)((unsigned int)v1052 >> 2)) >> 1))) | (-(v1054 ^ ((int)((unsigned int)((int)((unsigned int)v1052 >> 2)) >> 1))))) >> 31)) | (~(((v1055 ^ ((int)((unsigned int)((int)((unsigned int)v1052 >> 2)) >> 1))) | (-(v1055 ^ ((int)((unsigned int)((int)((unsigned int)v1052 >> 2)) >> 1))))) >> 31))) == 0);
  int v1151;
  if (v1172) {
    int * v1059 = v1042->cache_age;
    int v1174 = ((((int)((unsigned int)((int)((unsigned int)v1052 >> 2)) >> 1)) & 1) * 2) + ((~(((v1055 ^ ((int)((unsigned int)((int)((unsigned int)v1052 >> 2)) >> 1))) | (-(v1055 ^ ((int)((unsigned int)((int)((unsigned int)v1052 >> 2)) >> 1))))) >> 31)) & 1);
    int v1060 = v1059[v1174];
    int v1061 = v1059[v1168];
    int v1175 = v1061 + ((int)((unsigned int)(v1061 - v1060) >> 31));
    v1059[v1168] = v1175;
    int * v1063 = v1042->cache_age;
    int v1064 = v1063[v1169];
    int v1177 = v1064 + ((int)((unsigned int)(v1064 - v1060) >> 31));
    v1063[v1169] = v1177;
    int * v1066 = v1042->cache_age;
    v1066[v1174] = 0;
    v1151 = v1174;
  } else {
    int * v1069 = v1042->cache_age;
    int v1181 = (((int)((unsigned int)((int)((unsigned int)v1052 >> 2)) >> 1)) & 1) * 2;
    int v1070 = v1069[v1181];
    int * v1071 = v1042->cache_tags;
    int v1072 = v1071[v1181];
    int v1073 = v1069[v1169];
    int v1074 = v1071[v1169];
    bool v1183 = !(((~(((v1056 ^ ((int)((unsigned int)((int)((unsigned int)v1052 >> 2)) >> 1))) | (-(v1056 ^ ((int)((unsigned int)((int)((unsigned int)v1052 >> 2)) >> 1))))) >> 31)) | (~(((v1057 ^ ((int)((unsigned int)((int)((unsigned int)v1052 >> 2)) >> 1))) | (-(v1057 ^ ((int)((unsigned int)((int)((unsigned int)v1052 >> 2)) >> 1))))) >> 31))) == 0);
    int v1128;
    if (v1183) {
      int * v1075 = v1042->cache_age;
      int v1185 = (4 + ((((int)((unsigned int)((int)((unsigned int)v1052 >> 2)) >> 1)) & 3) * 2)) + ((~(((v1057 ^ ((int)((unsigned int)((int)((unsigned int)v1052 >> 2)) >> 1))) | (-(v1057 ^ ((int)((unsigned int)((int)((unsigned int)v1052 >> 2)) >> 1))))) >> 31)) & 1);
      int v1076 = v1075[v1185];
      int v1077 = v1075[v1170];
      int v1186 = v1077 + ((int)((unsigned int)(v1077 - v1076) >> 31));
      v1075[v1170] = v1186;
      int * v1079 = v1042->cache_age;
      int v1080 = v1079[v1171];
      int v1188 = v1080 + ((int)((unsigned int)(v1080 - v1076) >> 31));
      v1079[v1171] = v1188;
      int * v1082 = v1042->cache_age;
      v1082[v1185] = 0;
      v1128 = v1185;
    } else {
      int * v1085 = v1042->cache_age;
      int v1192 = 4 + ((((int)((unsigned int)((int)((unsigned int)v1052 >> 2)) >> 1)) & 3) * 2);
      int v1086 = v1085[v1192];
      int * v1087 = v1042->cache_tags;
      int v1088 = v1087[v1192];
      int v1089 = v1085[v1171];
      int v1090 = v1087[v1171];
      int * v1091 = v1042->cache_dirty;
      int v1195 = (4 + ((((int)((unsigned int)((int)((unsigned int)v1052 >> 2)) >> 1)) & 3) * 2)) + ((((v1086 + ((~(((v1088 ^ -1) | (-(v1088 ^ -1))) >> 31)) & 2)) - (v1089 + ((~(((v1090 ^ -1) | (-(v1090 ^ -1))) >> 31)) & 2))) >> 31) & 1);
      int v1092 = v1091[v1195];
      bool v1196 = !(v1092 == 0);
      if (v1196) {
        int * v1093 = v1042->cache_tags;
        int v1094 = v1093[v1195];
        int * v1095 = v1042->cache_vals;
        int v1199 = ((4 + ((((int)((unsigned int)((int)((unsigned int)v1052 >> 2)) >> 1)) & 3) * 2)) + ((((v1086 + ((~(((v1088 ^ -1) | (-(v1088 ^ -1))) >> 31)) & 2)) - (v1089 + ((~(((v1090 ^ -1) | (-(v1090 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
        int v1096 = v1095[v1199];
        int v1200 = (((4 + ((((int)((unsigned int)((int)((unsigned int)v1052 >> 2)) >> 1)) & 3) * 2)) + ((((v1086 + ((~(((v1088 ^ -1) | (-(v1088 ^ -1))) >> 31)) & 2)) - (v1089 + ((~(((v1090 ^ -1) | (-(v1090 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
        int v1097 = v1095[v1200];
        int * v1098 = v1042->mem;
        int v1202 = v1094 * 2;
        v1098[v1202] = v1096;
        int * v1100 = v1042->mem;
        int v1205 = (v1094 * 2) + 1;
        v1100[v1205] = v1097;
        ;
      } else {
        ;
      }
      int * v1105 = v1042->mem;
      int v1210 = ((int)((unsigned int)((int)((unsigned int)v1052 >> 2)) >> 1)) * 2;
      int v1106 = v1105[v1210];
      int v1211 = (((int)((unsigned int)((int)((unsigned int)v1052 >> 2)) >> 1)) * 2) + 1;
      int v1107 = v1105[v1211];
      int * v1108 = v1042->cache_vals;
      int v1213 = ((4 + ((((int)((unsigned int)((int)((unsigned int)v1052 >> 2)) >> 1)) & 3) * 2)) + ((((v1086 + ((~(((v1088 ^ -1) | (-(v1088 ^ -1))) >> 31)) & 2)) - (v1089 + ((~(((v1090 ^ -1) | (-(v1090 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
      v1108[v1213] = v1106;
      int * v1110 = v1042->cache_vals;
      int v1216 = (((4 + ((((int)((unsigned int)((int)((unsigned int)v1052 >> 2)) >> 1)) & 3) * 2)) + ((((v1086 + ((~(((v1088 ^ -1) | (-(v1088 ^ -1))) >> 31)) & 2)) - (v1089 + ((~(((v1090 ^ -1) | (-(v1090 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
      v1110[v1216] = v1107;
      int * v1112 = v1042->cache_tags;
      int v1219 = (int)((unsigned int)((int)((unsigned int)v1052 >> 2)) >> 1);
      v1112[v1195] = v1219;
      int * v1114 = v1042->cache_dirty;
      v1114[v1195] = 0;
      int * v1116 = v1042->cache_age;
      v1116[v1195] = 1;
      int * v1118 = v1042->cache_age;
      int v1119 = v1118[v1195];
      int v1120 = v1118[v1170];
      int v1225 = v1120 + ((int)((unsigned int)(v1120 - v1119) >> 31));
      v1118[v1170] = v1225;
      int * v1122 = v1042->cache_age;
      int v1123 = v1122[v1171];
      int v1227 = v1123 + ((int)((unsigned int)(v1123 - v1119) >> 31));
      v1122[v1171] = v1227;
      int * v1125 = v1042->cache_age;
      v1125[v1195] = 0;
      v1128 = v1195;
    }
    int * v1129 = v1042->cache_vals;
    int v1230 = v1128 * 2;
    int v1130 = v1129[v1230];
    int v1231 = (v1128 * 2) + 1;
    int v1131 = v1129[v1231];
    int v1232 = (((((int)((unsigned int)((int)((unsigned int)v1052 >> 2)) >> 1)) & 1) * 2) + ((((v1070 + ((~(((v1072 ^ -1) | (-(v1072 ^ -1))) >> 31)) & 2)) - (v1073 + ((~(((v1074 ^ -1) | (-(v1074 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
    v1129[v1232] = v1130;
    int * v1133 = v1042->cache_vals;
    int v1235 = ((((((int)((unsigned int)((int)((unsigned int)v1052 >> 2)) >> 1)) & 1) * 2) + ((((v1070 + ((~(((v1072 ^ -1) | (-(v1072 ^ -1))) >> 31)) & 2)) - (v1073 + ((~(((v1074 ^ -1) | (-(v1074 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
    v1133[v1235] = v1131;
    int * v1135 = v1042->cache_tags;
    int v1238 = ((((int)((unsigned int)((int)((unsigned int)v1052 >> 2)) >> 1)) & 1) * 2) + ((((v1070 + ((~(((v1072 ^ -1) | (-(v1072 ^ -1))) >> 31)) & 2)) - (v1073 + ((~(((v1074 ^ -1) | (-(v1074 ^ -1))) >> 31)) & 2))) >> 31) & 1);
    int v1239 = (int)((unsigned int)((int)((unsigned int)v1052 >> 2)) >> 1);
    v1135[v1238] = v1239;
    int * v1137 = v1042->cache_dirty;
    v1137[v1238] = 0;
    int * v1139 = v1042->cache_age;
    v1139[v1238] = 1;
    int * v1141 = v1042->cache_age;
    int v1142 = v1141[v1238];
    int v1143 = v1141[v1168];
    int v1245 = v1143 + ((int)((unsigned int)(v1143 - v1142) >> 31));
    v1141[v1168] = v1245;
    int * v1145 = v1042->cache_age;
    int v1146 = v1145[v1169];
    int v1247 = v1146 + ((int)((unsigned int)(v1146 - v1142) >> 31));
    v1145[v1169] = v1247;
    int * v1148 = v1042->cache_age;
    v1148[v1238] = 0;
    v1151 = v1238;
  }
  int v1250 = (v1151 * 2) + (((int)((unsigned int)v1052 >> 2)) & 1);
  int v1152 = v1058[v1250];
  int * v1153 = v1042->reg_ready;
  int v1252 = ((v1050 + ((v1047 - v1050) & (~((v1047 - v1050) >> 31)))) + 1) + ((100 ^ (((~(((v1056 ^ ((int)((unsigned int)((int)((unsigned int)v1052 >> 2)) >> 1))) | (-(v1056 ^ ((int)((unsigned int)((int)((unsigned int)v1052 >> 2)) >> 1))))) >> 31)) | (~(((v1057 ^ ((int)((unsigned int)((int)((unsigned int)v1052 >> 2)) >> 1))) | (-(v1057 ^ ((int)((unsigned int)((int)((unsigned int)v1052 >> 2)) >> 1))))) >> 31))) & 104)) ^ (((~(((v1054 ^ ((int)((unsigned int)((int)((unsigned int)v1052 >> 2)) >> 1))) | (-(v1054 ^ ((int)((unsigned int)((int)((unsigned int)v1052 >> 2)) >> 1))))) >> 31)) | (~(((v1055 ^ ((int)((unsigned int)((int)((unsigned int)v1052 >> 2)) >> 1))) | (-(v1055 ^ ((int)((unsigned int)((int)((unsigned int)v1052 >> 2)) >> 1))))) >> 31))) & (1 ^ (100 ^ (((~(((v1056 ^ ((int)((unsigned int)((int)((unsigned int)v1052 >> 2)) >> 1))) | (-(v1056 ^ ((int)((unsigned int)((int)((unsigned int)v1052 >> 2)) >> 1))))) >> 31)) | (~(((v1057 ^ ((int)((unsigned int)((int)((unsigned int)v1052 >> 2)) >> 1))) | (-(v1057 ^ ((int)((unsigned int)((int)((unsigned int)v1052 >> 2)) >> 1))))) >> 31))) & 104)))));
  v1153[11] = v1252;
  int * v1155 = v1042->regs;
  v1155[11] = v1152;
  struct StateT * v1157 = slot_24(v1042);
  return v1157;
}

struct StateT * slot_5(struct StateT * v74) {
  int * v75 = v74->saved_regs;
  int * v76 = v74->regs;
  int v77 = v76[5];
  v75[5] = v77;
  int v79 = v74->timer;
  int v96 = v79 + 1;
  v74->timer = v96;
  int * v81 = v74->reg_ready;
  int v82 = v81[12];
  int * v83 = v74->regs;
  int v84 = v83[12];
  int v85 = v81[14];
  int v86 = v83[14];
  int v101 = (v85 + (((v82 + ((v79 - v82) & (~((v79 - v82) >> 31)))) - v85) & (~(((v82 + ((v79 - v82) & (~((v79 - v82) >> 31)))) - v85) >> 31)))) + 1;
  v81[5] = v101;
  int * v88 = v74->regs;
  int v103 = v84 + v86;
  v88[5] = v103;
  struct StateT * v90 = slot_6(v74);
  return v90;
}

struct StateT * slot_2(struct StateT * v34) {
  int v35 = v34->timer;
  int v43 = v35 + 1;
  v34->timer = v43;
  int * v37 = v34->reg_ready;
  v37[14] = v43;
  int * v39 = v34->regs;
  v39[14] = 0;
  struct StateT * v41 = slot_3(v34);
  return v41;
}

struct StateT * slot_7(struct StateT * v321) {
  int * v322 = v321->saved_regs;
  int * v323 = v321->regs;
  int v324 = v323[6];
  v322[6] = v324;
  int v326 = v321->timer;
  int v343 = v326 + 1;
  v321->timer = v343;
  int * v328 = v321->reg_ready;
  int v329 = v328[13];
  int * v330 = v321->regs;
  int v331 = v330[13];
  int v332 = v328[14];
  int v333 = v330[14];
  int v348 = (v332 + (((v329 + ((v326 - v329) & (~((v326 - v329) >> 31)))) - v332) & (~(((v329 + ((v326 - v329) & (~((v326 - v329) >> 31)))) - v332) >> 31)))) + 1;
  v328[6] = v348;
  int * v335 = v321->regs;
  int v350 = v331 + v333;
  v335[6] = v350;
  struct StateT * v337 = slot_23(v321);
  return v337;
}

struct StateT * slot_3(struct StateT * v50) {
  int v51 = v50->timer;
  int v59 = v51 + 1;
  v50->timer = v59;
  int * v53 = v50->reg_ready;
  v53[15] = v59;
  int * v55 = v50->regs;
  v55[15] = 16;
  struct StateT * v57 = slot_4(v50);
  return v57;
}

struct StateT * slot_26(struct StateT * v1344) {
  int v1345 = v1344->timer;
  int v1349 = v1345 + 1;
  v1344->timer = v1349;
  struct StateT * v1347 = slot_13(v1344);
  return v1347;
}

struct StateT * slot_1(struct StateT * v18) {
  int v19 = v18->timer;
  int v27 = v19 + 1;
  v18->timer = v27;
  int * v21 = v18->reg_ready;
  v21[13] = v27;
  int * v23 = v18->regs;
  v23[13] = 80;
  struct StateT * v25 = slot_2(v18);
  return v25;
}

struct StateT * slot_13(struct StateT * v663) {
  int * v664 = v663->saved_regs;
  int * v665 = v663->regs;
  int v666 = v665[14];
  v664[14] = v666;
  int v668 = v663->timer;
  int v683 = v668 + 1;
  v663->timer = v683;
  int * v670 = v663->reg_ready;
  int v671 = v670[14];
  int * v672 = v663->regs;
  int v673 = v672[14];
  int v686 = (v671 + ((v668 - v671) & (~((v668 - v671) >> 31)))) + 1;
  v670[14] = v686;
  int * v675 = v663->regs;
  int v688 = v673 + 4;
  v675[14] = v688;
  struct StateT * v677 = slot_29(v663);
  return v677;
}

struct StateT * slot_24(struct StateT * v1257) {
  int * v1258 = v1257->regs;
  int v1259 = v1258[14];
  int v1260 = v1258[15];
  bool v1300 = v1259 >= v1260;
  struct StateT * v1295;
  if (v1300) {
    int v1261 = v1257->timer;
    int v1301 = v1261 + 15;
    v1257->timer = v1301;
    int * v1263 = v1257->saved_regs;
    int v1264 = v1263[5];
    int * v1265 = v1257->regs;
    v1265[5] = v1264;
    int * v1267 = v1257->saved_regs;
    int v1268 = v1267[10];
    int * v1269 = v1257->regs;
    v1269[10] = v1268;
    int * v1271 = v1257->saved_regs;
    int v1272 = v1271[6];
    int * v1273 = v1257->regs;
    v1273[6] = v1272;
    int * v1275 = v1257->saved_regs;
    int v1276 = v1275[11];
    int * v1277 = v1257->regs;
    v1277[11] = v1276;
    int * v1279 = v1257->reg_ready;
    int v1280 = v1257->timer;
    v1279[5] = v1280;
    int * v1282 = v1257->reg_ready;
    int v1283 = v1257->timer;
    v1282[10] = v1283;
    int * v1285 = v1257->reg_ready;
    int v1286 = v1257->timer;
    v1285[6] = v1286;
    int * v1288 = v1257->reg_ready;
    int v1289 = v1257->timer;
    v1288[11] = v1289;
    struct StateT * v1291 = slot_25(v1257);
    v1295 = v1291;
  } else {
    struct StateT * v1293 = slot_26(v1257);
    v1295 = v1293;
  }
  return v1295;
}

struct StateT * slot_0(struct StateT * v2) {
  int v3 = v2->timer;
  int v11 = v3 + 1;
  v2->timer = v11;
  int * v5 = v2->reg_ready;
  v5[12] = v11;
  int * v7 = v2->regs;
  v7[12] = 0;
  struct StateT * v9 = slot_1(v2);
  return v9;
}

struct StateT * slot_17(struct StateT * v750) {
  int v751 = v750->timer;
  int v754 = v751 + 1;
  v750->timer = v754;
  return v750;
}

struct StateT * snippet(struct StateT * v0) {
  struct StateT * v1 = slot_0(v0);
  int v1415 = v1->timer;
  int * v1416 = v1->reg_ready;
  int v1417 = v1416[0];
  int v1548 = v1417 + ((v1415 - v1417) & (~((v1415 - v1417) >> 31)));
  v1->timer = v1548;
  int v1419 = v1->timer;
  int * v1420 = v1->reg_ready;
  int v1421 = v1420[1];
  int v1551 = v1421 + ((v1419 - v1421) & (~((v1419 - v1421) >> 31)));
  v1->timer = v1551;
  int v1423 = v1->timer;
  int * v1424 = v1->reg_ready;
  int v1425 = v1424[2];
  int v1554 = v1425 + ((v1423 - v1425) & (~((v1423 - v1425) >> 31)));
  v1->timer = v1554;
  int v1427 = v1->timer;
  int * v1428 = v1->reg_ready;
  int v1429 = v1428[3];
  int v1557 = v1429 + ((v1427 - v1429) & (~((v1427 - v1429) >> 31)));
  v1->timer = v1557;
  int v1431 = v1->timer;
  int * v1432 = v1->reg_ready;
  int v1433 = v1432[4];
  int v1560 = v1433 + ((v1431 - v1433) & (~((v1431 - v1433) >> 31)));
  v1->timer = v1560;
  int v1435 = v1->timer;
  int * v1436 = v1->reg_ready;
  int v1437 = v1436[5];
  int v1563 = v1437 + ((v1435 - v1437) & (~((v1435 - v1437) >> 31)));
  v1->timer = v1563;
  int v1439 = v1->timer;
  int * v1440 = v1->reg_ready;
  int v1441 = v1440[6];
  int v1566 = v1441 + ((v1439 - v1441) & (~((v1439 - v1441) >> 31)));
  v1->timer = v1566;
  int v1443 = v1->timer;
  int * v1444 = v1->reg_ready;
  int v1445 = v1444[7];
  int v1569 = v1445 + ((v1443 - v1445) & (~((v1443 - v1445) >> 31)));
  v1->timer = v1569;
  int v1447 = v1->timer;
  int * v1448 = v1->reg_ready;
  int v1449 = v1448[8];
  int v1572 = v1449 + ((v1447 - v1449) & (~((v1447 - v1449) >> 31)));
  v1->timer = v1572;
  int v1451 = v1->timer;
  int * v1452 = v1->reg_ready;
  int v1453 = v1452[9];
  int v1575 = v1453 + ((v1451 - v1453) & (~((v1451 - v1453) >> 31)));
  v1->timer = v1575;
  int v1455 = v1->timer;
  int * v1456 = v1->reg_ready;
  int v1457 = v1456[10];
  int v1578 = v1457 + ((v1455 - v1457) & (~((v1455 - v1457) >> 31)));
  v1->timer = v1578;
  int v1459 = v1->timer;
  int * v1460 = v1->reg_ready;
  int v1461 = v1460[11];
  int v1581 = v1461 + ((v1459 - v1461) & (~((v1459 - v1461) >> 31)));
  v1->timer = v1581;
  int v1463 = v1->timer;
  int * v1464 = v1->reg_ready;
  int v1465 = v1464[12];
  int v1584 = v1465 + ((v1463 - v1465) & (~((v1463 - v1465) >> 31)));
  v1->timer = v1584;
  int v1467 = v1->timer;
  int * v1468 = v1->reg_ready;
  int v1469 = v1468[13];
  int v1587 = v1469 + ((v1467 - v1469) & (~((v1467 - v1469) >> 31)));
  v1->timer = v1587;
  int v1471 = v1->timer;
  int * v1472 = v1->reg_ready;
  int v1473 = v1472[14];
  int v1590 = v1473 + ((v1471 - v1473) & (~((v1471 - v1473) >> 31)));
  v1->timer = v1590;
  int v1475 = v1->timer;
  int * v1476 = v1->reg_ready;
  int v1477 = v1476[15];
  int v1593 = v1477 + ((v1475 - v1477) & (~((v1475 - v1477) >> 31)));
  v1->timer = v1593;
  int v1479 = v1->timer;
  int * v1480 = v1->reg_ready;
  int v1481 = v1480[16];
  int v1596 = v1481 + ((v1479 - v1481) & (~((v1479 - v1481) >> 31)));
  v1->timer = v1596;
  int v1483 = v1->timer;
  int * v1484 = v1->reg_ready;
  int v1485 = v1484[17];
  int v1599 = v1485 + ((v1483 - v1485) & (~((v1483 - v1485) >> 31)));
  v1->timer = v1599;
  int v1487 = v1->timer;
  int * v1488 = v1->reg_ready;
  int v1489 = v1488[18];
  int v1602 = v1489 + ((v1487 - v1489) & (~((v1487 - v1489) >> 31)));
  v1->timer = v1602;
  int v1491 = v1->timer;
  int * v1492 = v1->reg_ready;
  int v1493 = v1492[19];
  int v1605 = v1493 + ((v1491 - v1493) & (~((v1491 - v1493) >> 31)));
  v1->timer = v1605;
  int v1495 = v1->timer;
  int * v1496 = v1->reg_ready;
  int v1497 = v1496[20];
  int v1608 = v1497 + ((v1495 - v1497) & (~((v1495 - v1497) >> 31)));
  v1->timer = v1608;
  int v1499 = v1->timer;
  int * v1500 = v1->reg_ready;
  int v1501 = v1500[21];
  int v1611 = v1501 + ((v1499 - v1501) & (~((v1499 - v1501) >> 31)));
  v1->timer = v1611;
  int v1503 = v1->timer;
  int * v1504 = v1->reg_ready;
  int v1505 = v1504[22];
  int v1614 = v1505 + ((v1503 - v1505) & (~((v1503 - v1505) >> 31)));
  v1->timer = v1614;
  int v1507 = v1->timer;
  int * v1508 = v1->reg_ready;
  int v1509 = v1508[23];
  int v1617 = v1509 + ((v1507 - v1509) & (~((v1507 - v1509) >> 31)));
  v1->timer = v1617;
  int v1511 = v1->timer;
  int * v1512 = v1->reg_ready;
  int v1513 = v1512[24];
  int v1620 = v1513 + ((v1511 - v1513) & (~((v1511 - v1513) >> 31)));
  v1->timer = v1620;
  int v1515 = v1->timer;
  int * v1516 = v1->reg_ready;
  int v1517 = v1516[25];
  int v1623 = v1517 + ((v1515 - v1517) & (~((v1515 - v1517) >> 31)));
  v1->timer = v1623;
  int v1519 = v1->timer;
  int * v1520 = v1->reg_ready;
  int v1521 = v1520[26];
  int v1626 = v1521 + ((v1519 - v1521) & (~((v1519 - v1521) >> 31)));
  v1->timer = v1626;
  int v1523 = v1->timer;
  int * v1524 = v1->reg_ready;
  int v1525 = v1524[27];
  int v1629 = v1525 + ((v1523 - v1525) & (~((v1523 - v1525) >> 31)));
  v1->timer = v1629;
  int v1527 = v1->timer;
  int * v1528 = v1->reg_ready;
  int v1529 = v1528[28];
  int v1632 = v1529 + ((v1527 - v1529) & (~((v1527 - v1529) >> 31)));
  v1->timer = v1632;
  int v1531 = v1->timer;
  int * v1532 = v1->reg_ready;
  int v1533 = v1532[29];
  int v1635 = v1533 + ((v1531 - v1533) & (~((v1531 - v1533) >> 31)));
  v1->timer = v1635;
  int v1535 = v1->timer;
  int * v1536 = v1->reg_ready;
  int v1537 = v1536[30];
  int v1638 = v1537 + ((v1535 - v1537) & (~((v1535 - v1537) >> 31)));
  v1->timer = v1638;
  int v1539 = v1->timer;
  int * v1540 = v1->reg_ready;
  int v1541 = v1540[31];
  int v1641 = v1541 + ((v1539 - v1541) & (~((v1539 - v1541) >> 31)));
  v1->timer = v1641;
  return v1;
}

struct StateT * slot_4(struct StateT * v66) {
  int v67 = v66->timer;
  int v71 = v67 + 1;
  v66->timer = v71;
  struct StateT * v69 = slot_5(v66);
  return v69;
}

struct StateT * slot_15(struct StateT * v726) {
  int v727 = v726->timer;
  int v735 = v727 + 1;
  v726->timer = v735;
  int * v729 = v726->reg_ready;
  v729[10] = v735;
  int * v731 = v726->regs;
  v731[10] = 0;
  struct StateT * v733 = slot_17(v726);
  return v733;
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