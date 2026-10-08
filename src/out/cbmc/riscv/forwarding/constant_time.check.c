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

struct StateT * slot_12(struct StateT * v592);
struct StateT * slot_6(struct StateT * v75);
struct StateT * slot_25(struct StateT * v1266);
struct StateT * slot_23(struct StateT * v1222);
struct StateT * slot_5(struct StateT * v67);
struct StateT * slot_2(struct StateT * v28);
struct StateT * slot_7(struct StateT * v99);
struct StateT * slot_21(struct StateT * v987);
struct StateT * slot_3(struct StateT * v41);
struct StateT * slot_10(struct StateT * v545);
struct StateT * slot_1(struct StateT * v15);
struct StateT * slot_0(struct StateT * v2);
struct StateT * slot_14(struct StateT * v692);
struct StateT * slot_20(struct StateT * v963);
struct StateT * snippet(struct StateT * v0);
struct StateT * slot_4(struct StateT * v54);
struct StateT * slot_15(struct StateT * v712);
struct StateT * slot_12(struct StateT * v592) {
  int * v593 = v592->saved_regs;
  int * v594 = v592->regs;
  int v595 = v594[14];
  v593[14] = v595;
  int v597 = v592->timer;
  int v608 = v597 + 1;
  v592->timer = v608;
  int * v599 = v592->regs;
  int v600 = v599[14];
  int v610 = v600 + 4;
  v599[14] = v610;
  struct StateT * v602 = slot_25(v592);
  return v602;
}

struct StateT * slot_6(struct StateT * v75) {
  int * v76 = v75->saved_regs;
  int * v77 = v75->regs;
  int v78 = v77[6];
  v76[6] = v78;
  int v80 = v75->timer;
  int v92 = v80 + 1;
  v75->timer = v92;
  int * v82 = v75->regs;
  int v83 = v82[12];
  int v84 = v82[14];
  int v96 = v83 + v84;
  v82[6] = v96;
  struct StateT * v86 = slot_7(v75);
  return v86;
}

struct StateT * slot_25(struct StateT * v1266) {
  int * v1267 = v1266->saved_regs;
  int v1268 = v1267[14];
  int * v1269 = v1266->regs;
  int v1270 = v1269[15];
  bool v1311 = v1268 >= v1270;
  struct StateT * v1305;
  if (v1311) {
    int v1271 = v1266->timer;
    int v1312 = v1271 + 15;
    v1266->timer = v1312;
    int * v1273 = v1266->saved_regs;
    int v1274 = v1273[6];
    int * v1275 = v1266->regs;
    v1275[6] = v1274;
    int * v1277 = v1266->saved_regs;
    int v1278 = v1277[7];
    int * v1279 = v1266->regs;
    v1279[7] = v1278;
    int * v1281 = v1266->saved_regs;
    int v1282 = v1281[8];
    int * v1283 = v1266->regs;
    v1283[8] = v1282;
    int * v1285 = v1266->saved_regs;
    int v1286 = v1285[9];
    int * v1287 = v1266->regs;
    v1287[9] = v1286;
    int * v1289 = v1266->saved_regs;
    int v1290 = v1289[16];
    int * v1291 = v1266->regs;
    v1291[16] = v1290;
    int * v1293 = v1266->saved_regs;
    int v1294 = v1293[5];
    int * v1295 = v1266->regs;
    v1295[5] = v1294;
    int * v1297 = v1266->saved_regs;
    int v1298 = v1297[14];
    int * v1299 = v1266->regs;
    v1299[14] = v1298;
    struct StateT * v1301 = slot_14(v1266);
    v1305 = v1301;
  } else {
    struct StateT * v1303 = slot_15(v1266);
    v1305 = v1303;
  }
  return v1305;
}

struct StateT * slot_23(struct StateT * v1222) {
  int * v1223 = v1222->saved_regs;
  int * v1224 = v1222->regs;
  int v1225 = v1224[5];
  v1223[5] = v1225;
  int v1227 = v1222->timer;
  int v1239 = v1227 + 1;
  v1222->timer = v1239;
  int * v1229 = v1222->regs;
  int v1230 = v1229[5];
  int v1231 = v1229[16];
  int v1242 = v1230 | v1231;
  v1229[5] = v1242;
  struct StateT * v1233 = slot_12(v1222);
  return v1233;
}

struct StateT * slot_5(struct StateT * v67) {
  int v68 = v67->timer;
  int v72 = v68 + 1;
  v67->timer = v72;
  struct StateT * v70 = slot_6(v67);
  return v70;
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

struct StateT * slot_7(struct StateT * v99) {
  int * v100 = v99->saved_regs;
  int * v101 = v99->regs;
  int v102 = v101[7];
  v100[7] = v102;
  int v104 = v99->timer;
  int v218 = v104 + 1;
  v99->timer = v218;
  int * v106 = v99->regs;
  int v107 = v106[6];
  int * v108 = v99->cache_tags;
  int v222 = (((int)((unsigned int)((int)((unsigned int)v107 >> 2)) >> 1)) & 1) * 2;
  int v109 = v108[v222];
  int v223 = ((((int)((unsigned int)((int)((unsigned int)v107 >> 2)) >> 1)) & 1) * 2) + 1;
  int v110 = v108[v223];
  int v224 = 4 + ((((int)((unsigned int)((int)((unsigned int)v107 >> 2)) >> 1)) & 3) * 2);
  int v111 = v108[v224];
  int v225 = (4 + ((((int)((unsigned int)((int)((unsigned int)v107 >> 2)) >> 1)) & 3) * 2)) + 1;
  int v112 = v108[v225];
  int v113 = v99->timer;
  int v226 = v113 + ((100 ^ (((~(((v111 ^ ((int)((unsigned int)((int)((unsigned int)v107 >> 2)) >> 1))) | (-(v111 ^ ((int)((unsigned int)((int)((unsigned int)v107 >> 2)) >> 1))))) >> 31)) | (~(((v112 ^ ((int)((unsigned int)((int)((unsigned int)v107 >> 2)) >> 1))) | (-(v112 ^ ((int)((unsigned int)((int)((unsigned int)v107 >> 2)) >> 1))))) >> 31))) & 104)) ^ (((~(((v109 ^ ((int)((unsigned int)((int)((unsigned int)v107 >> 2)) >> 1))) | (-(v109 ^ ((int)((unsigned int)((int)((unsigned int)v107 >> 2)) >> 1))))) >> 31)) | (~(((v110 ^ ((int)((unsigned int)((int)((unsigned int)v107 >> 2)) >> 1))) | (-(v110 ^ ((int)((unsigned int)((int)((unsigned int)v107 >> 2)) >> 1))))) >> 31))) & (1 ^ (100 ^ (((~(((v111 ^ ((int)((unsigned int)((int)((unsigned int)v107 >> 2)) >> 1))) | (-(v111 ^ ((int)((unsigned int)((int)((unsigned int)v107 >> 2)) >> 1))))) >> 31)) | (~(((v112 ^ ((int)((unsigned int)((int)((unsigned int)v107 >> 2)) >> 1))) | (-(v112 ^ ((int)((unsigned int)((int)((unsigned int)v107 >> 2)) >> 1))))) >> 31))) & 104)))));
  v99->timer = v226;
  int * v115 = v99->cache_vals;
  bool v227 = !(((~(((v109 ^ ((int)((unsigned int)((int)((unsigned int)v107 >> 2)) >> 1))) | (-(v109 ^ ((int)((unsigned int)((int)((unsigned int)v107 >> 2)) >> 1))))) >> 31)) | (~(((v110 ^ ((int)((unsigned int)((int)((unsigned int)v107 >> 2)) >> 1))) | (-(v110 ^ ((int)((unsigned int)((int)((unsigned int)v107 >> 2)) >> 1))))) >> 31))) == 0);
  int v208;
  if (v227) {
    int * v116 = v99->cache_age;
    int v229 = ((((int)((unsigned int)((int)((unsigned int)v107 >> 2)) >> 1)) & 1) * 2) + ((~(((v110 ^ ((int)((unsigned int)((int)((unsigned int)v107 >> 2)) >> 1))) | (-(v110 ^ ((int)((unsigned int)((int)((unsigned int)v107 >> 2)) >> 1))))) >> 31)) & 1);
    int v117 = v116[v229];
    int v118 = v116[v222];
    int v230 = v118 + ((int)((unsigned int)(v118 - v117) >> 31));
    v116[v222] = v230;
    int * v120 = v99->cache_age;
    int v121 = v120[v223];
    int v232 = v121 + ((int)((unsigned int)(v121 - v117) >> 31));
    v120[v223] = v232;
    int * v123 = v99->cache_age;
    v123[v229] = 0;
    v208 = v229;
  } else {
    int * v126 = v99->cache_age;
    int v236 = (((int)((unsigned int)((int)((unsigned int)v107 >> 2)) >> 1)) & 1) * 2;
    int v127 = v126[v236];
    int * v128 = v99->cache_tags;
    int v129 = v128[v236];
    int v130 = v126[v223];
    int v131 = v128[v223];
    bool v238 = !(((~(((v111 ^ ((int)((unsigned int)((int)((unsigned int)v107 >> 2)) >> 1))) | (-(v111 ^ ((int)((unsigned int)((int)((unsigned int)v107 >> 2)) >> 1))))) >> 31)) | (~(((v112 ^ ((int)((unsigned int)((int)((unsigned int)v107 >> 2)) >> 1))) | (-(v112 ^ ((int)((unsigned int)((int)((unsigned int)v107 >> 2)) >> 1))))) >> 31))) == 0);
    int v185;
    if (v238) {
      int * v132 = v99->cache_age;
      int v240 = (4 + ((((int)((unsigned int)((int)((unsigned int)v107 >> 2)) >> 1)) & 3) * 2)) + ((~(((v112 ^ ((int)((unsigned int)((int)((unsigned int)v107 >> 2)) >> 1))) | (-(v112 ^ ((int)((unsigned int)((int)((unsigned int)v107 >> 2)) >> 1))))) >> 31)) & 1);
      int v133 = v132[v240];
      int v134 = v132[v224];
      int v241 = v134 + ((int)((unsigned int)(v134 - v133) >> 31));
      v132[v224] = v241;
      int * v136 = v99->cache_age;
      int v137 = v136[v225];
      int v243 = v137 + ((int)((unsigned int)(v137 - v133) >> 31));
      v136[v225] = v243;
      int * v139 = v99->cache_age;
      v139[v240] = 0;
      v185 = v240;
    } else {
      int * v142 = v99->cache_age;
      int v247 = 4 + ((((int)((unsigned int)((int)((unsigned int)v107 >> 2)) >> 1)) & 3) * 2);
      int v143 = v142[v247];
      int * v144 = v99->cache_tags;
      int v145 = v144[v247];
      int v146 = v142[v225];
      int v147 = v144[v225];
      int * v148 = v99->cache_dirty;
      int v250 = (4 + ((((int)((unsigned int)((int)((unsigned int)v107 >> 2)) >> 1)) & 3) * 2)) + ((((v143 + ((~(((v145 ^ -1) | (-(v145 ^ -1))) >> 31)) & 2)) - (v146 + ((~(((v147 ^ -1) | (-(v147 ^ -1))) >> 31)) & 2))) >> 31) & 1);
      int v149 = v148[v250];
      bool v251 = !(v149 == 0);
      if (v251) {
        int * v150 = v99->cache_tags;
        int v151 = v150[v250];
        int * v152 = v99->cache_vals;
        int v254 = ((4 + ((((int)((unsigned int)((int)((unsigned int)v107 >> 2)) >> 1)) & 3) * 2)) + ((((v143 + ((~(((v145 ^ -1) | (-(v145 ^ -1))) >> 31)) & 2)) - (v146 + ((~(((v147 ^ -1) | (-(v147 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
        int v153 = v152[v254];
        int v255 = (((4 + ((((int)((unsigned int)((int)((unsigned int)v107 >> 2)) >> 1)) & 3) * 2)) + ((((v143 + ((~(((v145 ^ -1) | (-(v145 ^ -1))) >> 31)) & 2)) - (v146 + ((~(((v147 ^ -1) | (-(v147 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
        int v154 = v152[v255];
        int * v155 = v99->mem;
        int v257 = v151 * 2;
        v155[v257] = v153;
        int * v157 = v99->mem;
        int v260 = (v151 * 2) + 1;
        v157[v260] = v154;
        ;
      } else {
        ;
      }
      int * v162 = v99->mem;
      int v265 = ((int)((unsigned int)((int)((unsigned int)v107 >> 2)) >> 1)) * 2;
      int v163 = v162[v265];
      int v266 = (((int)((unsigned int)((int)((unsigned int)v107 >> 2)) >> 1)) * 2) + 1;
      int v164 = v162[v266];
      int * v165 = v99->cache_vals;
      int v268 = ((4 + ((((int)((unsigned int)((int)((unsigned int)v107 >> 2)) >> 1)) & 3) * 2)) + ((((v143 + ((~(((v145 ^ -1) | (-(v145 ^ -1))) >> 31)) & 2)) - (v146 + ((~(((v147 ^ -1) | (-(v147 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
      v165[v268] = v163;
      int * v167 = v99->cache_vals;
      int v271 = (((4 + ((((int)((unsigned int)((int)((unsigned int)v107 >> 2)) >> 1)) & 3) * 2)) + ((((v143 + ((~(((v145 ^ -1) | (-(v145 ^ -1))) >> 31)) & 2)) - (v146 + ((~(((v147 ^ -1) | (-(v147 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
      v167[v271] = v164;
      int * v169 = v99->cache_tags;
      int v274 = (int)((unsigned int)((int)((unsigned int)v107 >> 2)) >> 1);
      v169[v250] = v274;
      int * v171 = v99->cache_dirty;
      v171[v250] = 0;
      int * v173 = v99->cache_age;
      v173[v250] = 1;
      int * v175 = v99->cache_age;
      int v176 = v175[v250];
      int v177 = v175[v224];
      int v280 = v177 + ((int)((unsigned int)(v177 - v176) >> 31));
      v175[v224] = v280;
      int * v179 = v99->cache_age;
      int v180 = v179[v225];
      int v282 = v180 + ((int)((unsigned int)(v180 - v176) >> 31));
      v179[v225] = v282;
      int * v182 = v99->cache_age;
      v182[v250] = 0;
      v185 = v250;
    }
    int * v186 = v99->cache_vals;
    int v285 = v185 * 2;
    int v187 = v186[v285];
    int v286 = (v185 * 2) + 1;
    int v188 = v186[v286];
    int v287 = (((((int)((unsigned int)((int)((unsigned int)v107 >> 2)) >> 1)) & 1) * 2) + ((((v127 + ((~(((v129 ^ -1) | (-(v129 ^ -1))) >> 31)) & 2)) - (v130 + ((~(((v131 ^ -1) | (-(v131 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
    v186[v287] = v187;
    int * v190 = v99->cache_vals;
    int v290 = ((((((int)((unsigned int)((int)((unsigned int)v107 >> 2)) >> 1)) & 1) * 2) + ((((v127 + ((~(((v129 ^ -1) | (-(v129 ^ -1))) >> 31)) & 2)) - (v130 + ((~(((v131 ^ -1) | (-(v131 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
    v190[v290] = v188;
    int * v192 = v99->cache_tags;
    int v293 = ((((int)((unsigned int)((int)((unsigned int)v107 >> 2)) >> 1)) & 1) * 2) + ((((v127 + ((~(((v129 ^ -1) | (-(v129 ^ -1))) >> 31)) & 2)) - (v130 + ((~(((v131 ^ -1) | (-(v131 ^ -1))) >> 31)) & 2))) >> 31) & 1);
    int v294 = (int)((unsigned int)((int)((unsigned int)v107 >> 2)) >> 1);
    v192[v293] = v294;
    int * v194 = v99->cache_dirty;
    v194[v293] = 0;
    int * v196 = v99->cache_age;
    v196[v293] = 1;
    int * v198 = v99->cache_age;
    int v199 = v198[v293];
    int v200 = v198[v222];
    int v300 = v200 + ((int)((unsigned int)(v200 - v199) >> 31));
    v198[v222] = v300;
    int * v202 = v99->cache_age;
    int v203 = v202[v223];
    int v302 = v203 + ((int)((unsigned int)(v203 - v199) >> 31));
    v202[v223] = v302;
    int * v205 = v99->cache_age;
    v205[v293] = 0;
    v208 = v293;
  }
  int v305 = (v208 * 2) + (((int)((unsigned int)v107 >> 2)) & 1);
  int v209 = v115[v305];
  int * v210 = v99->regs;
  v210[7] = v209;
  struct StateT * v212 = slot_20(v99);
  return v212;
}

struct StateT * slot_21(struct StateT * v987) {
  int * v988 = v987->saved_regs;
  int * v989 = v987->regs;
  int v990 = v989[9];
  v988[9] = v990;
  int v992 = v987->timer;
  int v1106 = v992 + 1;
  v987->timer = v1106;
  int * v994 = v987->regs;
  int v995 = v994[8];
  int * v996 = v987->cache_tags;
  int v1110 = (((int)((unsigned int)((int)((unsigned int)v995 >> 2)) >> 1)) & 1) * 2;
  int v997 = v996[v1110];
  int v1111 = ((((int)((unsigned int)((int)((unsigned int)v995 >> 2)) >> 1)) & 1) * 2) + 1;
  int v998 = v996[v1111];
  int v1112 = 4 + ((((int)((unsigned int)((int)((unsigned int)v995 >> 2)) >> 1)) & 3) * 2);
  int v999 = v996[v1112];
  int v1113 = (4 + ((((int)((unsigned int)((int)((unsigned int)v995 >> 2)) >> 1)) & 3) * 2)) + 1;
  int v1000 = v996[v1113];
  int v1001 = v987->timer;
  int v1114 = v1001 + ((100 ^ (((~(((v999 ^ ((int)((unsigned int)((int)((unsigned int)v995 >> 2)) >> 1))) | (-(v999 ^ ((int)((unsigned int)((int)((unsigned int)v995 >> 2)) >> 1))))) >> 31)) | (~(((v1000 ^ ((int)((unsigned int)((int)((unsigned int)v995 >> 2)) >> 1))) | (-(v1000 ^ ((int)((unsigned int)((int)((unsigned int)v995 >> 2)) >> 1))))) >> 31))) & 104)) ^ (((~(((v997 ^ ((int)((unsigned int)((int)((unsigned int)v995 >> 2)) >> 1))) | (-(v997 ^ ((int)((unsigned int)((int)((unsigned int)v995 >> 2)) >> 1))))) >> 31)) | (~(((v998 ^ ((int)((unsigned int)((int)((unsigned int)v995 >> 2)) >> 1))) | (-(v998 ^ ((int)((unsigned int)((int)((unsigned int)v995 >> 2)) >> 1))))) >> 31))) & (1 ^ (100 ^ (((~(((v999 ^ ((int)((unsigned int)((int)((unsigned int)v995 >> 2)) >> 1))) | (-(v999 ^ ((int)((unsigned int)((int)((unsigned int)v995 >> 2)) >> 1))))) >> 31)) | (~(((v1000 ^ ((int)((unsigned int)((int)((unsigned int)v995 >> 2)) >> 1))) | (-(v1000 ^ ((int)((unsigned int)((int)((unsigned int)v995 >> 2)) >> 1))))) >> 31))) & 104)))));
  v987->timer = v1114;
  int * v1003 = v987->cache_vals;
  bool v1115 = !(((~(((v997 ^ ((int)((unsigned int)((int)((unsigned int)v995 >> 2)) >> 1))) | (-(v997 ^ ((int)((unsigned int)((int)((unsigned int)v995 >> 2)) >> 1))))) >> 31)) | (~(((v998 ^ ((int)((unsigned int)((int)((unsigned int)v995 >> 2)) >> 1))) | (-(v998 ^ ((int)((unsigned int)((int)((unsigned int)v995 >> 2)) >> 1))))) >> 31))) == 0);
  int v1096;
  if (v1115) {
    int * v1004 = v987->cache_age;
    int v1117 = ((((int)((unsigned int)((int)((unsigned int)v995 >> 2)) >> 1)) & 1) * 2) + ((~(((v998 ^ ((int)((unsigned int)((int)((unsigned int)v995 >> 2)) >> 1))) | (-(v998 ^ ((int)((unsigned int)((int)((unsigned int)v995 >> 2)) >> 1))))) >> 31)) & 1);
    int v1005 = v1004[v1117];
    int v1006 = v1004[v1110];
    int v1118 = v1006 + ((int)((unsigned int)(v1006 - v1005) >> 31));
    v1004[v1110] = v1118;
    int * v1008 = v987->cache_age;
    int v1009 = v1008[v1111];
    int v1120 = v1009 + ((int)((unsigned int)(v1009 - v1005) >> 31));
    v1008[v1111] = v1120;
    int * v1011 = v987->cache_age;
    v1011[v1117] = 0;
    v1096 = v1117;
  } else {
    int * v1014 = v987->cache_age;
    int v1124 = (((int)((unsigned int)((int)((unsigned int)v995 >> 2)) >> 1)) & 1) * 2;
    int v1015 = v1014[v1124];
    int * v1016 = v987->cache_tags;
    int v1017 = v1016[v1124];
    int v1018 = v1014[v1111];
    int v1019 = v1016[v1111];
    bool v1126 = !(((~(((v999 ^ ((int)((unsigned int)((int)((unsigned int)v995 >> 2)) >> 1))) | (-(v999 ^ ((int)((unsigned int)((int)((unsigned int)v995 >> 2)) >> 1))))) >> 31)) | (~(((v1000 ^ ((int)((unsigned int)((int)((unsigned int)v995 >> 2)) >> 1))) | (-(v1000 ^ ((int)((unsigned int)((int)((unsigned int)v995 >> 2)) >> 1))))) >> 31))) == 0);
    int v1073;
    if (v1126) {
      int * v1020 = v987->cache_age;
      int v1128 = (4 + ((((int)((unsigned int)((int)((unsigned int)v995 >> 2)) >> 1)) & 3) * 2)) + ((~(((v1000 ^ ((int)((unsigned int)((int)((unsigned int)v995 >> 2)) >> 1))) | (-(v1000 ^ ((int)((unsigned int)((int)((unsigned int)v995 >> 2)) >> 1))))) >> 31)) & 1);
      int v1021 = v1020[v1128];
      int v1022 = v1020[v1112];
      int v1129 = v1022 + ((int)((unsigned int)(v1022 - v1021) >> 31));
      v1020[v1112] = v1129;
      int * v1024 = v987->cache_age;
      int v1025 = v1024[v1113];
      int v1131 = v1025 + ((int)((unsigned int)(v1025 - v1021) >> 31));
      v1024[v1113] = v1131;
      int * v1027 = v987->cache_age;
      v1027[v1128] = 0;
      v1073 = v1128;
    } else {
      int * v1030 = v987->cache_age;
      int v1135 = 4 + ((((int)((unsigned int)((int)((unsigned int)v995 >> 2)) >> 1)) & 3) * 2);
      int v1031 = v1030[v1135];
      int * v1032 = v987->cache_tags;
      int v1033 = v1032[v1135];
      int v1034 = v1030[v1113];
      int v1035 = v1032[v1113];
      int * v1036 = v987->cache_dirty;
      int v1138 = (4 + ((((int)((unsigned int)((int)((unsigned int)v995 >> 2)) >> 1)) & 3) * 2)) + ((((v1031 + ((~(((v1033 ^ -1) | (-(v1033 ^ -1))) >> 31)) & 2)) - (v1034 + ((~(((v1035 ^ -1) | (-(v1035 ^ -1))) >> 31)) & 2))) >> 31) & 1);
      int v1037 = v1036[v1138];
      bool v1139 = !(v1037 == 0);
      if (v1139) {
        int * v1038 = v987->cache_tags;
        int v1039 = v1038[v1138];
        int * v1040 = v987->cache_vals;
        int v1142 = ((4 + ((((int)((unsigned int)((int)((unsigned int)v995 >> 2)) >> 1)) & 3) * 2)) + ((((v1031 + ((~(((v1033 ^ -1) | (-(v1033 ^ -1))) >> 31)) & 2)) - (v1034 + ((~(((v1035 ^ -1) | (-(v1035 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
        int v1041 = v1040[v1142];
        int v1143 = (((4 + ((((int)((unsigned int)((int)((unsigned int)v995 >> 2)) >> 1)) & 3) * 2)) + ((((v1031 + ((~(((v1033 ^ -1) | (-(v1033 ^ -1))) >> 31)) & 2)) - (v1034 + ((~(((v1035 ^ -1) | (-(v1035 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
        int v1042 = v1040[v1143];
        int * v1043 = v987->mem;
        int v1145 = v1039 * 2;
        v1043[v1145] = v1041;
        int * v1045 = v987->mem;
        int v1148 = (v1039 * 2) + 1;
        v1045[v1148] = v1042;
        ;
      } else {
        ;
      }
      int * v1050 = v987->mem;
      int v1153 = ((int)((unsigned int)((int)((unsigned int)v995 >> 2)) >> 1)) * 2;
      int v1051 = v1050[v1153];
      int v1154 = (((int)((unsigned int)((int)((unsigned int)v995 >> 2)) >> 1)) * 2) + 1;
      int v1052 = v1050[v1154];
      int * v1053 = v987->cache_vals;
      int v1156 = ((4 + ((((int)((unsigned int)((int)((unsigned int)v995 >> 2)) >> 1)) & 3) * 2)) + ((((v1031 + ((~(((v1033 ^ -1) | (-(v1033 ^ -1))) >> 31)) & 2)) - (v1034 + ((~(((v1035 ^ -1) | (-(v1035 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
      v1053[v1156] = v1051;
      int * v1055 = v987->cache_vals;
      int v1159 = (((4 + ((((int)((unsigned int)((int)((unsigned int)v995 >> 2)) >> 1)) & 3) * 2)) + ((((v1031 + ((~(((v1033 ^ -1) | (-(v1033 ^ -1))) >> 31)) & 2)) - (v1034 + ((~(((v1035 ^ -1) | (-(v1035 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
      v1055[v1159] = v1052;
      int * v1057 = v987->cache_tags;
      int v1162 = (int)((unsigned int)((int)((unsigned int)v995 >> 2)) >> 1);
      v1057[v1138] = v1162;
      int * v1059 = v987->cache_dirty;
      v1059[v1138] = 0;
      int * v1061 = v987->cache_age;
      v1061[v1138] = 1;
      int * v1063 = v987->cache_age;
      int v1064 = v1063[v1138];
      int v1065 = v1063[v1112];
      int v1168 = v1065 + ((int)((unsigned int)(v1065 - v1064) >> 31));
      v1063[v1112] = v1168;
      int * v1067 = v987->cache_age;
      int v1068 = v1067[v1113];
      int v1170 = v1068 + ((int)((unsigned int)(v1068 - v1064) >> 31));
      v1067[v1113] = v1170;
      int * v1070 = v987->cache_age;
      v1070[v1138] = 0;
      v1073 = v1138;
    }
    int * v1074 = v987->cache_vals;
    int v1173 = v1073 * 2;
    int v1075 = v1074[v1173];
    int v1174 = (v1073 * 2) + 1;
    int v1076 = v1074[v1174];
    int v1175 = (((((int)((unsigned int)((int)((unsigned int)v995 >> 2)) >> 1)) & 1) * 2) + ((((v1015 + ((~(((v1017 ^ -1) | (-(v1017 ^ -1))) >> 31)) & 2)) - (v1018 + ((~(((v1019 ^ -1) | (-(v1019 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
    v1074[v1175] = v1075;
    int * v1078 = v987->cache_vals;
    int v1178 = ((((((int)((unsigned int)((int)((unsigned int)v995 >> 2)) >> 1)) & 1) * 2) + ((((v1015 + ((~(((v1017 ^ -1) | (-(v1017 ^ -1))) >> 31)) & 2)) - (v1018 + ((~(((v1019 ^ -1) | (-(v1019 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
    v1078[v1178] = v1076;
    int * v1080 = v987->cache_tags;
    int v1181 = ((((int)((unsigned int)((int)((unsigned int)v995 >> 2)) >> 1)) & 1) * 2) + ((((v1015 + ((~(((v1017 ^ -1) | (-(v1017 ^ -1))) >> 31)) & 2)) - (v1018 + ((~(((v1019 ^ -1) | (-(v1019 ^ -1))) >> 31)) & 2))) >> 31) & 1);
    int v1182 = (int)((unsigned int)((int)((unsigned int)v995 >> 2)) >> 1);
    v1080[v1181] = v1182;
    int * v1082 = v987->cache_dirty;
    v1082[v1181] = 0;
    int * v1084 = v987->cache_age;
    v1084[v1181] = 1;
    int * v1086 = v987->cache_age;
    int v1087 = v1086[v1181];
    int v1088 = v1086[v1110];
    int v1188 = v1088 + ((int)((unsigned int)(v1088 - v1087) >> 31));
    v1086[v1110] = v1188;
    int * v1090 = v987->cache_age;
    int v1091 = v1090[v1111];
    int v1190 = v1091 + ((int)((unsigned int)(v1091 - v1087) >> 31));
    v1090[v1111] = v1190;
    int * v1093 = v987->cache_age;
    v1093[v1181] = 0;
    v1096 = v1181;
  }
  int v1193 = (v1096 * 2) + (((int)((unsigned int)v995 >> 2)) & 1);
  int v1097 = v1003[v1193];
  int * v1098 = v987->regs;
  v1098[9] = v1097;
  struct StateT * v1100 = slot_10(v987);
  return v1100;
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

struct StateT * slot_10(struct StateT * v545) {
  int * v546 = v545->saved_regs;
  int * v547 = v545->regs;
  int v548 = v547[16];
  v546[16] = v548;
  int v550 = v545->timer;
  int v562 = v550 + 1;
  v545->timer = v562;
  int * v552 = v545->regs;
  int v553 = v552[7];
  int v554 = v552[9];
  int v566 = v553 ^ v554;
  v552[16] = v566;
  struct StateT * v556 = slot_23(v545);
  return v556;
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

struct StateT * slot_0(struct StateT * v2) {
  int v3 = v2->timer;
  int v9 = v3 + 1;
  v2->timer = v9;
  int * v5 = v2->regs;
  v5[12] = 0;
  struct StateT * v7 = slot_1(v2);
  return v7;
}

struct StateT * slot_14(struct StateT * v692) {
  int v693 = v692->timer;
  int v703 = v693 + 1;
  v692->timer = v703;
  int * v695 = v692->regs;
  int v696 = v695[5];
  bool v706 = (v696 ^ -2147483648) < -2147483647;
  int v699;
  if (v706) {
    v699 = 1;
  } else {
    v699 = 0;
  }
  int * v700 = v692->regs;
  v700[11] = v699;
  return v692;
}

struct StateT * slot_20(struct StateT * v963) {
  int * v964 = v963->saved_regs;
  int * v965 = v963->regs;
  int v966 = v965[8];
  v964[8] = v966;
  int v968 = v963->timer;
  int v980 = v968 + 1;
  v963->timer = v980;
  int * v970 = v963->regs;
  int v971 = v970[13];
  int v972 = v970[14];
  int v984 = v971 + v972;
  v970[8] = v984;
  struct StateT * v974 = slot_21(v963);
  return v974;
}

struct StateT * snippet(struct StateT * v0) {
  struct StateT * v1 = slot_0(v0);
  return v1;
}

struct StateT * slot_4(struct StateT * v54) {
  int v55 = v54->timer;
  int v61 = v55 + 1;
  v54->timer = v61;
  int * v57 = v54->regs;
  v57[5] = 0;
  struct StateT * v59 = slot_5(v54);
  return v59;
}

struct StateT * slot_15(struct StateT * v712) {
  int v713 = v712->timer;
  int v717 = v713 + 1;
  v712->timer = v717;
  struct StateT * v715 = slot_5(v712);
  return v715;
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