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

struct StateT * slot_12(struct StateT * v647);
struct StateT * slot_6(struct StateT * v90);
struct StateT * slot_25(struct StateT * v1417);
struct StateT * slot_23(struct StateT * v1358);
struct StateT * slot_5(struct StateT * v82);
struct StateT * slot_2(struct StateT * v34);
struct StateT * slot_7(struct StateT * v122);
struct StateT * slot_21(struct StateT * v1111);
struct StateT * slot_3(struct StateT * v50);
struct StateT * slot_10(struct StateT * v584);
struct StateT * slot_1(struct StateT * v18);
struct StateT * slot_0(struct StateT * v2);
struct StateT * slot_14(struct StateT * v789);
struct StateT * slot_20(struct StateT * v1079);
struct StateT * snippet(struct StateT * v0);
struct StateT * slot_4(struct StateT * v66);
struct StateT * slot_15(struct StateT * v816);
struct StateT * slot_12(struct StateT * v647) {
  int * v648 = v647->saved_regs;
  int * v649 = v647->regs;
  int v650 = v649[14];
  v648[14] = v650;
  int v652 = v647->timer;
  int v667 = v652 + 1;
  v647->timer = v667;
  int * v654 = v647->reg_ready;
  int v655 = v654[14];
  int * v656 = v647->regs;
  int v657 = v656[14];
  int v670 = (v655 + ((v652 - v655) & (~((v652 - v655) >> 31)))) + 1;
  v654[14] = v670;
  int * v659 = v647->regs;
  int v672 = v657 + 4;
  v659[14] = v672;
  struct StateT * v661 = slot_25(v647);
  return v661;
}

struct StateT * slot_6(struct StateT * v90) {
  int * v91 = v90->saved_regs;
  int * v92 = v90->regs;
  int v93 = v92[6];
  v91[6] = v93;
  int v95 = v90->timer;
  int v112 = v95 + 1;
  v90->timer = v112;
  int * v97 = v90->reg_ready;
  int v98 = v97[12];
  int * v99 = v90->regs;
  int v100 = v99[12];
  int v101 = v97[14];
  int v102 = v99[14];
  int v117 = (v101 + (((v98 + ((v95 - v98) & (~((v95 - v98) >> 31)))) - v101) & (~(((v98 + ((v95 - v98) & (~((v95 - v98) >> 31)))) - v101) >> 31)))) + 1;
  v97[6] = v117;
  int * v104 = v90->regs;
  int v119 = v100 + v102;
  v104[6] = v119;
  struct StateT * v106 = slot_7(v90);
  return v106;
}

struct StateT * slot_25(struct StateT * v1417) {
  int * v1418 = v1417->saved_regs;
  int v1419 = v1418[14];
  int * v1420 = v1417->regs;
  int v1421 = v1420[15];
  bool v1483 = v1419 >= v1421;
  struct StateT * v1477;
  if (v1483) {
    int v1422 = v1417->timer;
    int v1484 = v1422 + 15;
    v1417->timer = v1484;
    int * v1424 = v1417->saved_regs;
    int v1425 = v1424[6];
    int * v1426 = v1417->regs;
    v1426[6] = v1425;
    int * v1428 = v1417->saved_regs;
    int v1429 = v1428[7];
    int * v1430 = v1417->regs;
    v1430[7] = v1429;
    int * v1432 = v1417->saved_regs;
    int v1433 = v1432[8];
    int * v1434 = v1417->regs;
    v1434[8] = v1433;
    int * v1436 = v1417->saved_regs;
    int v1437 = v1436[9];
    int * v1438 = v1417->regs;
    v1438[9] = v1437;
    int * v1440 = v1417->saved_regs;
    int v1441 = v1440[16];
    int * v1442 = v1417->regs;
    v1442[16] = v1441;
    int * v1444 = v1417->saved_regs;
    int v1445 = v1444[5];
    int * v1446 = v1417->regs;
    v1446[5] = v1445;
    int * v1448 = v1417->saved_regs;
    int v1449 = v1448[14];
    int * v1450 = v1417->regs;
    v1450[14] = v1449;
    int * v1452 = v1417->reg_ready;
    int v1453 = v1417->timer;
    v1452[6] = v1453;
    int * v1455 = v1417->reg_ready;
    int v1456 = v1417->timer;
    v1455[7] = v1456;
    int * v1458 = v1417->reg_ready;
    int v1459 = v1417->timer;
    v1458[8] = v1459;
    int * v1461 = v1417->reg_ready;
    int v1462 = v1417->timer;
    v1461[9] = v1462;
    int * v1464 = v1417->reg_ready;
    int v1465 = v1417->timer;
    v1464[16] = v1465;
    int * v1467 = v1417->reg_ready;
    int v1468 = v1417->timer;
    v1467[5] = v1468;
    int * v1470 = v1417->reg_ready;
    int v1471 = v1417->timer;
    v1470[14] = v1471;
    struct StateT * v1473 = slot_14(v1417);
    v1477 = v1473;
  } else {
    struct StateT * v1475 = slot_15(v1417);
    v1477 = v1475;
  }
  return v1477;
}

struct StateT * slot_23(struct StateT * v1358) {
  int * v1359 = v1358->saved_regs;
  int * v1360 = v1358->regs;
  int v1361 = v1360[5];
  v1359[5] = v1361;
  int v1363 = v1358->timer;
  int v1380 = v1363 + 1;
  v1358->timer = v1380;
  int * v1365 = v1358->reg_ready;
  int v1366 = v1365[5];
  int * v1367 = v1358->regs;
  int v1368 = v1367[5];
  int v1369 = v1365[16];
  int v1370 = v1367[16];
  int v1384 = (v1369 + (((v1366 + ((v1363 - v1366) & (~((v1363 - v1366) >> 31)))) - v1369) & (~(((v1366 + ((v1363 - v1366) & (~((v1363 - v1366) >> 31)))) - v1369) >> 31)))) + 1;
  v1365[5] = v1384;
  int * v1372 = v1358->regs;
  int v1386 = v1368 | v1370;
  v1372[5] = v1386;
  struct StateT * v1374 = slot_12(v1358);
  return v1374;
}

struct StateT * slot_5(struct StateT * v82) {
  int v83 = v82->timer;
  int v87 = v83 + 1;
  v82->timer = v87;
  struct StateT * v85 = slot_6(v82);
  return v85;
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

struct StateT * slot_7(struct StateT * v122) {
  int * v123 = v122->saved_regs;
  int * v124 = v122->regs;
  int v125 = v124[7];
  v123[7] = v125;
  int v127 = v122->timer;
  int v243 = v127 + 1;
  v122->timer = v243;
  int * v129 = v122->reg_ready;
  int v130 = v129[6];
  int * v131 = v122->regs;
  int v132 = v131[6];
  int * v133 = v122->cache_tags;
  int v248 = (((int)((unsigned int)((int)((unsigned int)v132 >> 2)) >> 1)) & 1) * 2;
  int v134 = v133[v248];
  int v249 = ((((int)((unsigned int)((int)((unsigned int)v132 >> 2)) >> 1)) & 1) * 2) + 1;
  int v135 = v133[v249];
  int v250 = 4 + ((((int)((unsigned int)((int)((unsigned int)v132 >> 2)) >> 1)) & 3) * 2);
  int v136 = v133[v250];
  int v251 = (4 + ((((int)((unsigned int)((int)((unsigned int)v132 >> 2)) >> 1)) & 3) * 2)) + 1;
  int v137 = v133[v251];
  int * v138 = v122->cache_vals;
  bool v252 = !(((~(((v134 ^ ((int)((unsigned int)((int)((unsigned int)v132 >> 2)) >> 1))) | (-(v134 ^ ((int)((unsigned int)((int)((unsigned int)v132 >> 2)) >> 1))))) >> 31)) | (~(((v135 ^ ((int)((unsigned int)((int)((unsigned int)v132 >> 2)) >> 1))) | (-(v135 ^ ((int)((unsigned int)((int)((unsigned int)v132 >> 2)) >> 1))))) >> 31))) == 0);
  int v231;
  if (v252) {
    int * v139 = v122->cache_age;
    int v254 = ((((int)((unsigned int)((int)((unsigned int)v132 >> 2)) >> 1)) & 1) * 2) + ((~(((v135 ^ ((int)((unsigned int)((int)((unsigned int)v132 >> 2)) >> 1))) | (-(v135 ^ ((int)((unsigned int)((int)((unsigned int)v132 >> 2)) >> 1))))) >> 31)) & 1);
    int v140 = v139[v254];
    int v141 = v139[v248];
    int v255 = v141 + ((int)((unsigned int)(v141 - v140) >> 31));
    v139[v248] = v255;
    int * v143 = v122->cache_age;
    int v144 = v143[v249];
    int v257 = v144 + ((int)((unsigned int)(v144 - v140) >> 31));
    v143[v249] = v257;
    int * v146 = v122->cache_age;
    v146[v254] = 0;
    v231 = v254;
  } else {
    int * v149 = v122->cache_age;
    int v261 = (((int)((unsigned int)((int)((unsigned int)v132 >> 2)) >> 1)) & 1) * 2;
    int v150 = v149[v261];
    int * v151 = v122->cache_tags;
    int v152 = v151[v261];
    int v153 = v149[v249];
    int v154 = v151[v249];
    bool v263 = !(((~(((v136 ^ ((int)((unsigned int)((int)((unsigned int)v132 >> 2)) >> 1))) | (-(v136 ^ ((int)((unsigned int)((int)((unsigned int)v132 >> 2)) >> 1))))) >> 31)) | (~(((v137 ^ ((int)((unsigned int)((int)((unsigned int)v132 >> 2)) >> 1))) | (-(v137 ^ ((int)((unsigned int)((int)((unsigned int)v132 >> 2)) >> 1))))) >> 31))) == 0);
    int v208;
    if (v263) {
      int * v155 = v122->cache_age;
      int v265 = (4 + ((((int)((unsigned int)((int)((unsigned int)v132 >> 2)) >> 1)) & 3) * 2)) + ((~(((v137 ^ ((int)((unsigned int)((int)((unsigned int)v132 >> 2)) >> 1))) | (-(v137 ^ ((int)((unsigned int)((int)((unsigned int)v132 >> 2)) >> 1))))) >> 31)) & 1);
      int v156 = v155[v265];
      int v157 = v155[v250];
      int v266 = v157 + ((int)((unsigned int)(v157 - v156) >> 31));
      v155[v250] = v266;
      int * v159 = v122->cache_age;
      int v160 = v159[v251];
      int v268 = v160 + ((int)((unsigned int)(v160 - v156) >> 31));
      v159[v251] = v268;
      int * v162 = v122->cache_age;
      v162[v265] = 0;
      v208 = v265;
    } else {
      int * v165 = v122->cache_age;
      int v272 = 4 + ((((int)((unsigned int)((int)((unsigned int)v132 >> 2)) >> 1)) & 3) * 2);
      int v166 = v165[v272];
      int * v167 = v122->cache_tags;
      int v168 = v167[v272];
      int v169 = v165[v251];
      int v170 = v167[v251];
      int * v171 = v122->cache_dirty;
      int v275 = (4 + ((((int)((unsigned int)((int)((unsigned int)v132 >> 2)) >> 1)) & 3) * 2)) + ((((v166 + ((~(((v168 ^ -1) | (-(v168 ^ -1))) >> 31)) & 2)) - (v169 + ((~(((v170 ^ -1) | (-(v170 ^ -1))) >> 31)) & 2))) >> 31) & 1);
      int v172 = v171[v275];
      bool v276 = !(v172 == 0);
      if (v276) {
        int * v173 = v122->cache_tags;
        int v174 = v173[v275];
        int * v175 = v122->cache_vals;
        int v279 = ((4 + ((((int)((unsigned int)((int)((unsigned int)v132 >> 2)) >> 1)) & 3) * 2)) + ((((v166 + ((~(((v168 ^ -1) | (-(v168 ^ -1))) >> 31)) & 2)) - (v169 + ((~(((v170 ^ -1) | (-(v170 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
        int v176 = v175[v279];
        int v280 = (((4 + ((((int)((unsigned int)((int)((unsigned int)v132 >> 2)) >> 1)) & 3) * 2)) + ((((v166 + ((~(((v168 ^ -1) | (-(v168 ^ -1))) >> 31)) & 2)) - (v169 + ((~(((v170 ^ -1) | (-(v170 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
        int v177 = v175[v280];
        int * v178 = v122->mem;
        int v282 = v174 * 2;
        v178[v282] = v176;
        int * v180 = v122->mem;
        int v285 = (v174 * 2) + 1;
        v180[v285] = v177;
        ;
      } else {
        ;
      }
      int * v185 = v122->mem;
      int v290 = ((int)((unsigned int)((int)((unsigned int)v132 >> 2)) >> 1)) * 2;
      int v186 = v185[v290];
      int v291 = (((int)((unsigned int)((int)((unsigned int)v132 >> 2)) >> 1)) * 2) + 1;
      int v187 = v185[v291];
      int * v188 = v122->cache_vals;
      int v293 = ((4 + ((((int)((unsigned int)((int)((unsigned int)v132 >> 2)) >> 1)) & 3) * 2)) + ((((v166 + ((~(((v168 ^ -1) | (-(v168 ^ -1))) >> 31)) & 2)) - (v169 + ((~(((v170 ^ -1) | (-(v170 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
      v188[v293] = v186;
      int * v190 = v122->cache_vals;
      int v296 = (((4 + ((((int)((unsigned int)((int)((unsigned int)v132 >> 2)) >> 1)) & 3) * 2)) + ((((v166 + ((~(((v168 ^ -1) | (-(v168 ^ -1))) >> 31)) & 2)) - (v169 + ((~(((v170 ^ -1) | (-(v170 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
      v190[v296] = v187;
      int * v192 = v122->cache_tags;
      int v299 = (int)((unsigned int)((int)((unsigned int)v132 >> 2)) >> 1);
      v192[v275] = v299;
      int * v194 = v122->cache_dirty;
      v194[v275] = 0;
      int * v196 = v122->cache_age;
      v196[v275] = 1;
      int * v198 = v122->cache_age;
      int v199 = v198[v275];
      int v200 = v198[v250];
      int v305 = v200 + ((int)((unsigned int)(v200 - v199) >> 31));
      v198[v250] = v305;
      int * v202 = v122->cache_age;
      int v203 = v202[v251];
      int v307 = v203 + ((int)((unsigned int)(v203 - v199) >> 31));
      v202[v251] = v307;
      int * v205 = v122->cache_age;
      v205[v275] = 0;
      v208 = v275;
    }
    int * v209 = v122->cache_vals;
    int v310 = v208 * 2;
    int v210 = v209[v310];
    int v311 = (v208 * 2) + 1;
    int v211 = v209[v311];
    int v312 = (((((int)((unsigned int)((int)((unsigned int)v132 >> 2)) >> 1)) & 1) * 2) + ((((v150 + ((~(((v152 ^ -1) | (-(v152 ^ -1))) >> 31)) & 2)) - (v153 + ((~(((v154 ^ -1) | (-(v154 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
    v209[v312] = v210;
    int * v213 = v122->cache_vals;
    int v315 = ((((((int)((unsigned int)((int)((unsigned int)v132 >> 2)) >> 1)) & 1) * 2) + ((((v150 + ((~(((v152 ^ -1) | (-(v152 ^ -1))) >> 31)) & 2)) - (v153 + ((~(((v154 ^ -1) | (-(v154 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
    v213[v315] = v211;
    int * v215 = v122->cache_tags;
    int v318 = ((((int)((unsigned int)((int)((unsigned int)v132 >> 2)) >> 1)) & 1) * 2) + ((((v150 + ((~(((v152 ^ -1) | (-(v152 ^ -1))) >> 31)) & 2)) - (v153 + ((~(((v154 ^ -1) | (-(v154 ^ -1))) >> 31)) & 2))) >> 31) & 1);
    int v319 = (int)((unsigned int)((int)((unsigned int)v132 >> 2)) >> 1);
    v215[v318] = v319;
    int * v217 = v122->cache_dirty;
    v217[v318] = 0;
    int * v219 = v122->cache_age;
    v219[v318] = 1;
    int * v221 = v122->cache_age;
    int v222 = v221[v318];
    int v223 = v221[v248];
    int v325 = v223 + ((int)((unsigned int)(v223 - v222) >> 31));
    v221[v248] = v325;
    int * v225 = v122->cache_age;
    int v226 = v225[v249];
    int v327 = v226 + ((int)((unsigned int)(v226 - v222) >> 31));
    v225[v249] = v327;
    int * v228 = v122->cache_age;
    v228[v318] = 0;
    v231 = v318;
  }
  int v330 = (v231 * 2) + (((int)((unsigned int)v132 >> 2)) & 1);
  int v232 = v138[v330];
  int * v233 = v122->reg_ready;
  int v332 = ((v130 + ((v127 - v130) & (~((v127 - v130) >> 31)))) + 1) + ((100 ^ (((~(((v136 ^ ((int)((unsigned int)((int)((unsigned int)v132 >> 2)) >> 1))) | (-(v136 ^ ((int)((unsigned int)((int)((unsigned int)v132 >> 2)) >> 1))))) >> 31)) | (~(((v137 ^ ((int)((unsigned int)((int)((unsigned int)v132 >> 2)) >> 1))) | (-(v137 ^ ((int)((unsigned int)((int)((unsigned int)v132 >> 2)) >> 1))))) >> 31))) & 104)) ^ (((~(((v134 ^ ((int)((unsigned int)((int)((unsigned int)v132 >> 2)) >> 1))) | (-(v134 ^ ((int)((unsigned int)((int)((unsigned int)v132 >> 2)) >> 1))))) >> 31)) | (~(((v135 ^ ((int)((unsigned int)((int)((unsigned int)v132 >> 2)) >> 1))) | (-(v135 ^ ((int)((unsigned int)((int)((unsigned int)v132 >> 2)) >> 1))))) >> 31))) & (1 ^ (100 ^ (((~(((v136 ^ ((int)((unsigned int)((int)((unsigned int)v132 >> 2)) >> 1))) | (-(v136 ^ ((int)((unsigned int)((int)((unsigned int)v132 >> 2)) >> 1))))) >> 31)) | (~(((v137 ^ ((int)((unsigned int)((int)((unsigned int)v132 >> 2)) >> 1))) | (-(v137 ^ ((int)((unsigned int)((int)((unsigned int)v132 >> 2)) >> 1))))) >> 31))) & 104)))));
  v233[7] = v332;
  int * v235 = v122->regs;
  v235[7] = v232;
  struct StateT * v237 = slot_20(v122);
  return v237;
}

struct StateT * slot_21(struct StateT * v1111) {
  int * v1112 = v1111->saved_regs;
  int * v1113 = v1111->regs;
  int v1114 = v1113[9];
  v1112[9] = v1114;
  int v1116 = v1111->timer;
  int v1232 = v1116 + 1;
  v1111->timer = v1232;
  int * v1118 = v1111->reg_ready;
  int v1119 = v1118[8];
  int * v1120 = v1111->regs;
  int v1121 = v1120[8];
  int * v1122 = v1111->cache_tags;
  int v1237 = (((int)((unsigned int)((int)((unsigned int)v1121 >> 2)) >> 1)) & 1) * 2;
  int v1123 = v1122[v1237];
  int v1238 = ((((int)((unsigned int)((int)((unsigned int)v1121 >> 2)) >> 1)) & 1) * 2) + 1;
  int v1124 = v1122[v1238];
  int v1239 = 4 + ((((int)((unsigned int)((int)((unsigned int)v1121 >> 2)) >> 1)) & 3) * 2);
  int v1125 = v1122[v1239];
  int v1240 = (4 + ((((int)((unsigned int)((int)((unsigned int)v1121 >> 2)) >> 1)) & 3) * 2)) + 1;
  int v1126 = v1122[v1240];
  int * v1127 = v1111->cache_vals;
  bool v1241 = !(((~(((v1123 ^ ((int)((unsigned int)((int)((unsigned int)v1121 >> 2)) >> 1))) | (-(v1123 ^ ((int)((unsigned int)((int)((unsigned int)v1121 >> 2)) >> 1))))) >> 31)) | (~(((v1124 ^ ((int)((unsigned int)((int)((unsigned int)v1121 >> 2)) >> 1))) | (-(v1124 ^ ((int)((unsigned int)((int)((unsigned int)v1121 >> 2)) >> 1))))) >> 31))) == 0);
  int v1220;
  if (v1241) {
    int * v1128 = v1111->cache_age;
    int v1243 = ((((int)((unsigned int)((int)((unsigned int)v1121 >> 2)) >> 1)) & 1) * 2) + ((~(((v1124 ^ ((int)((unsigned int)((int)((unsigned int)v1121 >> 2)) >> 1))) | (-(v1124 ^ ((int)((unsigned int)((int)((unsigned int)v1121 >> 2)) >> 1))))) >> 31)) & 1);
    int v1129 = v1128[v1243];
    int v1130 = v1128[v1237];
    int v1244 = v1130 + ((int)((unsigned int)(v1130 - v1129) >> 31));
    v1128[v1237] = v1244;
    int * v1132 = v1111->cache_age;
    int v1133 = v1132[v1238];
    int v1246 = v1133 + ((int)((unsigned int)(v1133 - v1129) >> 31));
    v1132[v1238] = v1246;
    int * v1135 = v1111->cache_age;
    v1135[v1243] = 0;
    v1220 = v1243;
  } else {
    int * v1138 = v1111->cache_age;
    int v1250 = (((int)((unsigned int)((int)((unsigned int)v1121 >> 2)) >> 1)) & 1) * 2;
    int v1139 = v1138[v1250];
    int * v1140 = v1111->cache_tags;
    int v1141 = v1140[v1250];
    int v1142 = v1138[v1238];
    int v1143 = v1140[v1238];
    bool v1252 = !(((~(((v1125 ^ ((int)((unsigned int)((int)((unsigned int)v1121 >> 2)) >> 1))) | (-(v1125 ^ ((int)((unsigned int)((int)((unsigned int)v1121 >> 2)) >> 1))))) >> 31)) | (~(((v1126 ^ ((int)((unsigned int)((int)((unsigned int)v1121 >> 2)) >> 1))) | (-(v1126 ^ ((int)((unsigned int)((int)((unsigned int)v1121 >> 2)) >> 1))))) >> 31))) == 0);
    int v1197;
    if (v1252) {
      int * v1144 = v1111->cache_age;
      int v1254 = (4 + ((((int)((unsigned int)((int)((unsigned int)v1121 >> 2)) >> 1)) & 3) * 2)) + ((~(((v1126 ^ ((int)((unsigned int)((int)((unsigned int)v1121 >> 2)) >> 1))) | (-(v1126 ^ ((int)((unsigned int)((int)((unsigned int)v1121 >> 2)) >> 1))))) >> 31)) & 1);
      int v1145 = v1144[v1254];
      int v1146 = v1144[v1239];
      int v1255 = v1146 + ((int)((unsigned int)(v1146 - v1145) >> 31));
      v1144[v1239] = v1255;
      int * v1148 = v1111->cache_age;
      int v1149 = v1148[v1240];
      int v1257 = v1149 + ((int)((unsigned int)(v1149 - v1145) >> 31));
      v1148[v1240] = v1257;
      int * v1151 = v1111->cache_age;
      v1151[v1254] = 0;
      v1197 = v1254;
    } else {
      int * v1154 = v1111->cache_age;
      int v1261 = 4 + ((((int)((unsigned int)((int)((unsigned int)v1121 >> 2)) >> 1)) & 3) * 2);
      int v1155 = v1154[v1261];
      int * v1156 = v1111->cache_tags;
      int v1157 = v1156[v1261];
      int v1158 = v1154[v1240];
      int v1159 = v1156[v1240];
      int * v1160 = v1111->cache_dirty;
      int v1264 = (4 + ((((int)((unsigned int)((int)((unsigned int)v1121 >> 2)) >> 1)) & 3) * 2)) + ((((v1155 + ((~(((v1157 ^ -1) | (-(v1157 ^ -1))) >> 31)) & 2)) - (v1158 + ((~(((v1159 ^ -1) | (-(v1159 ^ -1))) >> 31)) & 2))) >> 31) & 1);
      int v1161 = v1160[v1264];
      bool v1265 = !(v1161 == 0);
      if (v1265) {
        int * v1162 = v1111->cache_tags;
        int v1163 = v1162[v1264];
        int * v1164 = v1111->cache_vals;
        int v1268 = ((4 + ((((int)((unsigned int)((int)((unsigned int)v1121 >> 2)) >> 1)) & 3) * 2)) + ((((v1155 + ((~(((v1157 ^ -1) | (-(v1157 ^ -1))) >> 31)) & 2)) - (v1158 + ((~(((v1159 ^ -1) | (-(v1159 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
        int v1165 = v1164[v1268];
        int v1269 = (((4 + ((((int)((unsigned int)((int)((unsigned int)v1121 >> 2)) >> 1)) & 3) * 2)) + ((((v1155 + ((~(((v1157 ^ -1) | (-(v1157 ^ -1))) >> 31)) & 2)) - (v1158 + ((~(((v1159 ^ -1) | (-(v1159 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
        int v1166 = v1164[v1269];
        int * v1167 = v1111->mem;
        int v1271 = v1163 * 2;
        v1167[v1271] = v1165;
        int * v1169 = v1111->mem;
        int v1274 = (v1163 * 2) + 1;
        v1169[v1274] = v1166;
        ;
      } else {
        ;
      }
      int * v1174 = v1111->mem;
      int v1279 = ((int)((unsigned int)((int)((unsigned int)v1121 >> 2)) >> 1)) * 2;
      int v1175 = v1174[v1279];
      int v1280 = (((int)((unsigned int)((int)((unsigned int)v1121 >> 2)) >> 1)) * 2) + 1;
      int v1176 = v1174[v1280];
      int * v1177 = v1111->cache_vals;
      int v1282 = ((4 + ((((int)((unsigned int)((int)((unsigned int)v1121 >> 2)) >> 1)) & 3) * 2)) + ((((v1155 + ((~(((v1157 ^ -1) | (-(v1157 ^ -1))) >> 31)) & 2)) - (v1158 + ((~(((v1159 ^ -1) | (-(v1159 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
      v1177[v1282] = v1175;
      int * v1179 = v1111->cache_vals;
      int v1285 = (((4 + ((((int)((unsigned int)((int)((unsigned int)v1121 >> 2)) >> 1)) & 3) * 2)) + ((((v1155 + ((~(((v1157 ^ -1) | (-(v1157 ^ -1))) >> 31)) & 2)) - (v1158 + ((~(((v1159 ^ -1) | (-(v1159 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
      v1179[v1285] = v1176;
      int * v1181 = v1111->cache_tags;
      int v1288 = (int)((unsigned int)((int)((unsigned int)v1121 >> 2)) >> 1);
      v1181[v1264] = v1288;
      int * v1183 = v1111->cache_dirty;
      v1183[v1264] = 0;
      int * v1185 = v1111->cache_age;
      v1185[v1264] = 1;
      int * v1187 = v1111->cache_age;
      int v1188 = v1187[v1264];
      int v1189 = v1187[v1239];
      int v1294 = v1189 + ((int)((unsigned int)(v1189 - v1188) >> 31));
      v1187[v1239] = v1294;
      int * v1191 = v1111->cache_age;
      int v1192 = v1191[v1240];
      int v1296 = v1192 + ((int)((unsigned int)(v1192 - v1188) >> 31));
      v1191[v1240] = v1296;
      int * v1194 = v1111->cache_age;
      v1194[v1264] = 0;
      v1197 = v1264;
    }
    int * v1198 = v1111->cache_vals;
    int v1299 = v1197 * 2;
    int v1199 = v1198[v1299];
    int v1300 = (v1197 * 2) + 1;
    int v1200 = v1198[v1300];
    int v1301 = (((((int)((unsigned int)((int)((unsigned int)v1121 >> 2)) >> 1)) & 1) * 2) + ((((v1139 + ((~(((v1141 ^ -1) | (-(v1141 ^ -1))) >> 31)) & 2)) - (v1142 + ((~(((v1143 ^ -1) | (-(v1143 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
    v1198[v1301] = v1199;
    int * v1202 = v1111->cache_vals;
    int v1304 = ((((((int)((unsigned int)((int)((unsigned int)v1121 >> 2)) >> 1)) & 1) * 2) + ((((v1139 + ((~(((v1141 ^ -1) | (-(v1141 ^ -1))) >> 31)) & 2)) - (v1142 + ((~(((v1143 ^ -1) | (-(v1143 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
    v1202[v1304] = v1200;
    int * v1204 = v1111->cache_tags;
    int v1307 = ((((int)((unsigned int)((int)((unsigned int)v1121 >> 2)) >> 1)) & 1) * 2) + ((((v1139 + ((~(((v1141 ^ -1) | (-(v1141 ^ -1))) >> 31)) & 2)) - (v1142 + ((~(((v1143 ^ -1) | (-(v1143 ^ -1))) >> 31)) & 2))) >> 31) & 1);
    int v1308 = (int)((unsigned int)((int)((unsigned int)v1121 >> 2)) >> 1);
    v1204[v1307] = v1308;
    int * v1206 = v1111->cache_dirty;
    v1206[v1307] = 0;
    int * v1208 = v1111->cache_age;
    v1208[v1307] = 1;
    int * v1210 = v1111->cache_age;
    int v1211 = v1210[v1307];
    int v1212 = v1210[v1237];
    int v1314 = v1212 + ((int)((unsigned int)(v1212 - v1211) >> 31));
    v1210[v1237] = v1314;
    int * v1214 = v1111->cache_age;
    int v1215 = v1214[v1238];
    int v1316 = v1215 + ((int)((unsigned int)(v1215 - v1211) >> 31));
    v1214[v1238] = v1316;
    int * v1217 = v1111->cache_age;
    v1217[v1307] = 0;
    v1220 = v1307;
  }
  int v1319 = (v1220 * 2) + (((int)((unsigned int)v1121 >> 2)) & 1);
  int v1221 = v1127[v1319];
  int * v1222 = v1111->reg_ready;
  int v1321 = ((v1119 + ((v1116 - v1119) & (~((v1116 - v1119) >> 31)))) + 1) + ((100 ^ (((~(((v1125 ^ ((int)((unsigned int)((int)((unsigned int)v1121 >> 2)) >> 1))) | (-(v1125 ^ ((int)((unsigned int)((int)((unsigned int)v1121 >> 2)) >> 1))))) >> 31)) | (~(((v1126 ^ ((int)((unsigned int)((int)((unsigned int)v1121 >> 2)) >> 1))) | (-(v1126 ^ ((int)((unsigned int)((int)((unsigned int)v1121 >> 2)) >> 1))))) >> 31))) & 104)) ^ (((~(((v1123 ^ ((int)((unsigned int)((int)((unsigned int)v1121 >> 2)) >> 1))) | (-(v1123 ^ ((int)((unsigned int)((int)((unsigned int)v1121 >> 2)) >> 1))))) >> 31)) | (~(((v1124 ^ ((int)((unsigned int)((int)((unsigned int)v1121 >> 2)) >> 1))) | (-(v1124 ^ ((int)((unsigned int)((int)((unsigned int)v1121 >> 2)) >> 1))))) >> 31))) & (1 ^ (100 ^ (((~(((v1125 ^ ((int)((unsigned int)((int)((unsigned int)v1121 >> 2)) >> 1))) | (-(v1125 ^ ((int)((unsigned int)((int)((unsigned int)v1121 >> 2)) >> 1))))) >> 31)) | (~(((v1126 ^ ((int)((unsigned int)((int)((unsigned int)v1121 >> 2)) >> 1))) | (-(v1126 ^ ((int)((unsigned int)((int)((unsigned int)v1121 >> 2)) >> 1))))) >> 31))) & 104)))));
  v1222[9] = v1321;
  int * v1224 = v1111->regs;
  v1224[9] = v1221;
  struct StateT * v1226 = slot_10(v1111);
  return v1226;
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

struct StateT * slot_10(struct StateT * v584) {
  int * v585 = v584->saved_regs;
  int * v586 = v584->regs;
  int v587 = v586[16];
  v585[16] = v587;
  int v589 = v584->timer;
  int v606 = v589 + 1;
  v584->timer = v606;
  int * v591 = v584->reg_ready;
  int v592 = v591[7];
  int * v593 = v584->regs;
  int v594 = v593[7];
  int v595 = v591[9];
  int v596 = v593[9];
  int v611 = (v595 + (((v592 + ((v589 - v592) & (~((v589 - v592) >> 31)))) - v595) & (~(((v592 + ((v589 - v592) & (~((v589 - v592) >> 31)))) - v595) >> 31)))) + 1;
  v591[16] = v611;
  int * v598 = v584->regs;
  int v613 = v594 ^ v596;
  v598[16] = v613;
  struct StateT * v600 = slot_23(v584);
  return v600;
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

struct StateT * slot_14(struct StateT * v789) {
  int v790 = v789->timer;
  int v804 = v790 + 1;
  v789->timer = v804;
  int * v792 = v789->reg_ready;
  int v793 = v792[5];
  int * v794 = v789->regs;
  int v795 = v794[5];
  bool v808 = (v795 ^ -2147483648) < -2147483647;
  int v798;
  if (v808) {
    v798 = 1;
  } else {
    v798 = 0;
  }
  int * v799 = v789->reg_ready;
  int v813 = (v793 + ((v790 - v793) & (~((v790 - v793) >> 31)))) + 1;
  v799[11] = v813;
  int * v801 = v789->regs;
  v801[11] = v798;
  return v789;
}

struct StateT * slot_20(struct StateT * v1079) {
  int * v1080 = v1079->saved_regs;
  int * v1081 = v1079->regs;
  int v1082 = v1081[8];
  v1080[8] = v1082;
  int v1084 = v1079->timer;
  int v1101 = v1084 + 1;
  v1079->timer = v1101;
  int * v1086 = v1079->reg_ready;
  int v1087 = v1086[13];
  int * v1088 = v1079->regs;
  int v1089 = v1088[13];
  int v1090 = v1086[14];
  int v1091 = v1088[14];
  int v1106 = (v1090 + (((v1087 + ((v1084 - v1087) & (~((v1084 - v1087) >> 31)))) - v1090) & (~(((v1087 + ((v1084 - v1087) & (~((v1084 - v1087) >> 31)))) - v1090) >> 31)))) + 1;
  v1086[8] = v1106;
  int * v1093 = v1079->regs;
  int v1108 = v1089 + v1091;
  v1093[8] = v1108;
  struct StateT * v1095 = slot_21(v1079);
  return v1095;
}

struct StateT * snippet(struct StateT * v0) {
  struct StateT * v1 = slot_0(v0);
  int v1531 = v1->timer;
  int * v1532 = v1->reg_ready;
  int v1533 = v1532[0];
  int v1664 = v1533 + ((v1531 - v1533) & (~((v1531 - v1533) >> 31)));
  v1->timer = v1664;
  int v1535 = v1->timer;
  int * v1536 = v1->reg_ready;
  int v1537 = v1536[1];
  int v1667 = v1537 + ((v1535 - v1537) & (~((v1535 - v1537) >> 31)));
  v1->timer = v1667;
  int v1539 = v1->timer;
  int * v1540 = v1->reg_ready;
  int v1541 = v1540[2];
  int v1670 = v1541 + ((v1539 - v1541) & (~((v1539 - v1541) >> 31)));
  v1->timer = v1670;
  int v1543 = v1->timer;
  int * v1544 = v1->reg_ready;
  int v1545 = v1544[3];
  int v1673 = v1545 + ((v1543 - v1545) & (~((v1543 - v1545) >> 31)));
  v1->timer = v1673;
  int v1547 = v1->timer;
  int * v1548 = v1->reg_ready;
  int v1549 = v1548[4];
  int v1676 = v1549 + ((v1547 - v1549) & (~((v1547 - v1549) >> 31)));
  v1->timer = v1676;
  int v1551 = v1->timer;
  int * v1552 = v1->reg_ready;
  int v1553 = v1552[5];
  int v1679 = v1553 + ((v1551 - v1553) & (~((v1551 - v1553) >> 31)));
  v1->timer = v1679;
  int v1555 = v1->timer;
  int * v1556 = v1->reg_ready;
  int v1557 = v1556[6];
  int v1682 = v1557 + ((v1555 - v1557) & (~((v1555 - v1557) >> 31)));
  v1->timer = v1682;
  int v1559 = v1->timer;
  int * v1560 = v1->reg_ready;
  int v1561 = v1560[7];
  int v1685 = v1561 + ((v1559 - v1561) & (~((v1559 - v1561) >> 31)));
  v1->timer = v1685;
  int v1563 = v1->timer;
  int * v1564 = v1->reg_ready;
  int v1565 = v1564[8];
  int v1688 = v1565 + ((v1563 - v1565) & (~((v1563 - v1565) >> 31)));
  v1->timer = v1688;
  int v1567 = v1->timer;
  int * v1568 = v1->reg_ready;
  int v1569 = v1568[9];
  int v1691 = v1569 + ((v1567 - v1569) & (~((v1567 - v1569) >> 31)));
  v1->timer = v1691;
  int v1571 = v1->timer;
  int * v1572 = v1->reg_ready;
  int v1573 = v1572[10];
  int v1694 = v1573 + ((v1571 - v1573) & (~((v1571 - v1573) >> 31)));
  v1->timer = v1694;
  int v1575 = v1->timer;
  int * v1576 = v1->reg_ready;
  int v1577 = v1576[11];
  int v1697 = v1577 + ((v1575 - v1577) & (~((v1575 - v1577) >> 31)));
  v1->timer = v1697;
  int v1579 = v1->timer;
  int * v1580 = v1->reg_ready;
  int v1581 = v1580[12];
  int v1700 = v1581 + ((v1579 - v1581) & (~((v1579 - v1581) >> 31)));
  v1->timer = v1700;
  int v1583 = v1->timer;
  int * v1584 = v1->reg_ready;
  int v1585 = v1584[13];
  int v1703 = v1585 + ((v1583 - v1585) & (~((v1583 - v1585) >> 31)));
  v1->timer = v1703;
  int v1587 = v1->timer;
  int * v1588 = v1->reg_ready;
  int v1589 = v1588[14];
  int v1706 = v1589 + ((v1587 - v1589) & (~((v1587 - v1589) >> 31)));
  v1->timer = v1706;
  int v1591 = v1->timer;
  int * v1592 = v1->reg_ready;
  int v1593 = v1592[15];
  int v1709 = v1593 + ((v1591 - v1593) & (~((v1591 - v1593) >> 31)));
  v1->timer = v1709;
  int v1595 = v1->timer;
  int * v1596 = v1->reg_ready;
  int v1597 = v1596[16];
  int v1712 = v1597 + ((v1595 - v1597) & (~((v1595 - v1597) >> 31)));
  v1->timer = v1712;
  int v1599 = v1->timer;
  int * v1600 = v1->reg_ready;
  int v1601 = v1600[17];
  int v1715 = v1601 + ((v1599 - v1601) & (~((v1599 - v1601) >> 31)));
  v1->timer = v1715;
  int v1603 = v1->timer;
  int * v1604 = v1->reg_ready;
  int v1605 = v1604[18];
  int v1718 = v1605 + ((v1603 - v1605) & (~((v1603 - v1605) >> 31)));
  v1->timer = v1718;
  int v1607 = v1->timer;
  int * v1608 = v1->reg_ready;
  int v1609 = v1608[19];
  int v1721 = v1609 + ((v1607 - v1609) & (~((v1607 - v1609) >> 31)));
  v1->timer = v1721;
  int v1611 = v1->timer;
  int * v1612 = v1->reg_ready;
  int v1613 = v1612[20];
  int v1724 = v1613 + ((v1611 - v1613) & (~((v1611 - v1613) >> 31)));
  v1->timer = v1724;
  int v1615 = v1->timer;
  int * v1616 = v1->reg_ready;
  int v1617 = v1616[21];
  int v1727 = v1617 + ((v1615 - v1617) & (~((v1615 - v1617) >> 31)));
  v1->timer = v1727;
  int v1619 = v1->timer;
  int * v1620 = v1->reg_ready;
  int v1621 = v1620[22];
  int v1730 = v1621 + ((v1619 - v1621) & (~((v1619 - v1621) >> 31)));
  v1->timer = v1730;
  int v1623 = v1->timer;
  int * v1624 = v1->reg_ready;
  int v1625 = v1624[23];
  int v1733 = v1625 + ((v1623 - v1625) & (~((v1623 - v1625) >> 31)));
  v1->timer = v1733;
  int v1627 = v1->timer;
  int * v1628 = v1->reg_ready;
  int v1629 = v1628[24];
  int v1736 = v1629 + ((v1627 - v1629) & (~((v1627 - v1629) >> 31)));
  v1->timer = v1736;
  int v1631 = v1->timer;
  int * v1632 = v1->reg_ready;
  int v1633 = v1632[25];
  int v1739 = v1633 + ((v1631 - v1633) & (~((v1631 - v1633) >> 31)));
  v1->timer = v1739;
  int v1635 = v1->timer;
  int * v1636 = v1->reg_ready;
  int v1637 = v1636[26];
  int v1742 = v1637 + ((v1635 - v1637) & (~((v1635 - v1637) >> 31)));
  v1->timer = v1742;
  int v1639 = v1->timer;
  int * v1640 = v1->reg_ready;
  int v1641 = v1640[27];
  int v1745 = v1641 + ((v1639 - v1641) & (~((v1639 - v1641) >> 31)));
  v1->timer = v1745;
  int v1643 = v1->timer;
  int * v1644 = v1->reg_ready;
  int v1645 = v1644[28];
  int v1748 = v1645 + ((v1643 - v1645) & (~((v1643 - v1645) >> 31)));
  v1->timer = v1748;
  int v1647 = v1->timer;
  int * v1648 = v1->reg_ready;
  int v1649 = v1648[29];
  int v1751 = v1649 + ((v1647 - v1649) & (~((v1647 - v1649) >> 31)));
  v1->timer = v1751;
  int v1651 = v1->timer;
  int * v1652 = v1->reg_ready;
  int v1653 = v1652[30];
  int v1754 = v1653 + ((v1651 - v1653) & (~((v1651 - v1653) >> 31)));
  v1->timer = v1754;
  int v1655 = v1->timer;
  int * v1656 = v1->reg_ready;
  int v1657 = v1656[31];
  int v1757 = v1657 + ((v1655 - v1657) & (~((v1655 - v1657) >> 31)));
  v1->timer = v1757;
  return v1;
}

struct StateT * slot_4(struct StateT * v66) {
  int v67 = v66->timer;
  int v75 = v67 + 1;
  v66->timer = v75;
  int * v69 = v66->reg_ready;
  v69[5] = v75;
  int * v71 = v66->regs;
  v71[5] = 0;
  struct StateT * v73 = slot_5(v66);
  return v73;
}

struct StateT * slot_15(struct StateT * v816) {
  int v817 = v816->timer;
  int v821 = v817 + 1;
  v816->timer = v821;
  struct StateT * v819 = slot_5(v816);
  return v819;
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