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

struct StateT * slot_6(struct StateT * v106);
struct StateT * slot_25(struct StateT * v1339);
struct StateT * slot_16(struct StateT * v742);
struct StateT * slot_23(struct StateT * v1257);
struct StateT * slot_5(struct StateT * v74);
struct StateT * slot_2(struct StateT * v34);
struct StateT * slot_7(struct StateT * v321);
struct StateT * slot_3(struct StateT * v50);
struct StateT * slot_26(struct StateT * v1367);
struct StateT * slot_10(struct StateT * v642);
struct StateT * slot_1(struct StateT * v18);
struct StateT * slot_24(struct StateT * v1331);
struct StateT * slot_0(struct StateT * v2);
struct StateT * slot_17(struct StateT * v750);
struct StateT * snippet(struct StateT * v0);
struct StateT * slot_8(struct StateT * v353);
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

struct StateT * slot_25(struct StateT * v1339) {
  int * v1340 = v1339->saved_regs;
  int * v1341 = v1339->regs;
  int v1342 = v1341[14];
  v1340[14] = v1342;
  int v1344 = v1339->timer;
  int v1359 = v1344 + 1;
  v1339->timer = v1359;
  int * v1346 = v1339->reg_ready;
  int v1347 = v1346[14];
  int * v1348 = v1339->regs;
  int v1349 = v1348[14];
  int v1362 = (v1347 + ((v1344 - v1347) & (~((v1344 - v1347) >> 31)))) + 1;
  v1346[14] = v1362;
  int * v1351 = v1339->regs;
  int v1364 = v1349 + 4;
  v1351[14] = v1364;
  struct StateT * v1353 = slot_26(v1339);
  return v1353;
}

struct StateT * slot_16(struct StateT * v742) {
  int v743 = v742->timer;
  int v747 = v743 + 1;
  v742->timer = v747;
  struct StateT * v745 = slot_4(v742);
  return v745;
}

struct StateT * slot_23(struct StateT * v1257) {
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
    struct StateT * v1291 = slot_10(v1257);
    v1295 = v1291;
  } else {
    struct StateT * v1293 = slot_24(v1257);
    v1295 = v1293;
  }
  return v1295;
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
  struct StateT * v337 = slot_8(v321);
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

struct StateT * slot_26(struct StateT * v1367) {
  int * v1368 = v1367->regs;
  int v1369 = v1368[10];
  int v1370 = v1368[11];
  bool v1389 = !(v1369 == v1370);
  struct StateT * v1384;
  if (v1389) {
    int v1371 = v1367->timer;
    int v1390 = v1371 + 15;
    v1367->timer = v1390;
    int * v1373 = v1367->saved_regs;
    int v1374 = v1373[14];
    int * v1375 = v1367->regs;
    v1375[14] = v1374;
    int * v1377 = v1367->reg_ready;
    int v1378 = v1367->timer;
    v1377[14] = v1378;
    struct StateT * v1380 = slot_15(v1367);
    v1384 = v1380;
  } else {
    struct StateT * v1382 = slot_16(v1367);
    v1384 = v1382;
  }
  return v1384;
}

struct StateT * slot_10(struct StateT * v642) {
  int v643 = v642->timer;
  int v650 = v643 + 1;
  v642->timer = v650;
  int * v645 = v642->reg_ready;
  v645[10] = v650;
  int * v647 = v642->regs;
  v647[10] = 1;
  return v642;
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

struct StateT * slot_24(struct StateT * v1331) {
  int v1332 = v1331->timer;
  int v1336 = v1332 + 1;
  v1331->timer = v1336;
  struct StateT * v1334 = slot_25(v1331);
  return v1334;
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
  int v1402 = v1->timer;
  int * v1403 = v1->reg_ready;
  int v1404 = v1403[0];
  int v1535 = v1404 + ((v1402 - v1404) & (~((v1402 - v1404) >> 31)));
  v1->timer = v1535;
  int v1406 = v1->timer;
  int * v1407 = v1->reg_ready;
  int v1408 = v1407[1];
  int v1538 = v1408 + ((v1406 - v1408) & (~((v1406 - v1408) >> 31)));
  v1->timer = v1538;
  int v1410 = v1->timer;
  int * v1411 = v1->reg_ready;
  int v1412 = v1411[2];
  int v1541 = v1412 + ((v1410 - v1412) & (~((v1410 - v1412) >> 31)));
  v1->timer = v1541;
  int v1414 = v1->timer;
  int * v1415 = v1->reg_ready;
  int v1416 = v1415[3];
  int v1544 = v1416 + ((v1414 - v1416) & (~((v1414 - v1416) >> 31)));
  v1->timer = v1544;
  int v1418 = v1->timer;
  int * v1419 = v1->reg_ready;
  int v1420 = v1419[4];
  int v1547 = v1420 + ((v1418 - v1420) & (~((v1418 - v1420) >> 31)));
  v1->timer = v1547;
  int v1422 = v1->timer;
  int * v1423 = v1->reg_ready;
  int v1424 = v1423[5];
  int v1550 = v1424 + ((v1422 - v1424) & (~((v1422 - v1424) >> 31)));
  v1->timer = v1550;
  int v1426 = v1->timer;
  int * v1427 = v1->reg_ready;
  int v1428 = v1427[6];
  int v1553 = v1428 + ((v1426 - v1428) & (~((v1426 - v1428) >> 31)));
  v1->timer = v1553;
  int v1430 = v1->timer;
  int * v1431 = v1->reg_ready;
  int v1432 = v1431[7];
  int v1556 = v1432 + ((v1430 - v1432) & (~((v1430 - v1432) >> 31)));
  v1->timer = v1556;
  int v1434 = v1->timer;
  int * v1435 = v1->reg_ready;
  int v1436 = v1435[8];
  int v1559 = v1436 + ((v1434 - v1436) & (~((v1434 - v1436) >> 31)));
  v1->timer = v1559;
  int v1438 = v1->timer;
  int * v1439 = v1->reg_ready;
  int v1440 = v1439[9];
  int v1562 = v1440 + ((v1438 - v1440) & (~((v1438 - v1440) >> 31)));
  v1->timer = v1562;
  int v1442 = v1->timer;
  int * v1443 = v1->reg_ready;
  int v1444 = v1443[10];
  int v1565 = v1444 + ((v1442 - v1444) & (~((v1442 - v1444) >> 31)));
  v1->timer = v1565;
  int v1446 = v1->timer;
  int * v1447 = v1->reg_ready;
  int v1448 = v1447[11];
  int v1568 = v1448 + ((v1446 - v1448) & (~((v1446 - v1448) >> 31)));
  v1->timer = v1568;
  int v1450 = v1->timer;
  int * v1451 = v1->reg_ready;
  int v1452 = v1451[12];
  int v1571 = v1452 + ((v1450 - v1452) & (~((v1450 - v1452) >> 31)));
  v1->timer = v1571;
  int v1454 = v1->timer;
  int * v1455 = v1->reg_ready;
  int v1456 = v1455[13];
  int v1574 = v1456 + ((v1454 - v1456) & (~((v1454 - v1456) >> 31)));
  v1->timer = v1574;
  int v1458 = v1->timer;
  int * v1459 = v1->reg_ready;
  int v1460 = v1459[14];
  int v1577 = v1460 + ((v1458 - v1460) & (~((v1458 - v1460) >> 31)));
  v1->timer = v1577;
  int v1462 = v1->timer;
  int * v1463 = v1->reg_ready;
  int v1464 = v1463[15];
  int v1580 = v1464 + ((v1462 - v1464) & (~((v1462 - v1464) >> 31)));
  v1->timer = v1580;
  int v1466 = v1->timer;
  int * v1467 = v1->reg_ready;
  int v1468 = v1467[16];
  int v1583 = v1468 + ((v1466 - v1468) & (~((v1466 - v1468) >> 31)));
  v1->timer = v1583;
  int v1470 = v1->timer;
  int * v1471 = v1->reg_ready;
  int v1472 = v1471[17];
  int v1586 = v1472 + ((v1470 - v1472) & (~((v1470 - v1472) >> 31)));
  v1->timer = v1586;
  int v1474 = v1->timer;
  int * v1475 = v1->reg_ready;
  int v1476 = v1475[18];
  int v1589 = v1476 + ((v1474 - v1476) & (~((v1474 - v1476) >> 31)));
  v1->timer = v1589;
  int v1478 = v1->timer;
  int * v1479 = v1->reg_ready;
  int v1480 = v1479[19];
  int v1592 = v1480 + ((v1478 - v1480) & (~((v1478 - v1480) >> 31)));
  v1->timer = v1592;
  int v1482 = v1->timer;
  int * v1483 = v1->reg_ready;
  int v1484 = v1483[20];
  int v1595 = v1484 + ((v1482 - v1484) & (~((v1482 - v1484) >> 31)));
  v1->timer = v1595;
  int v1486 = v1->timer;
  int * v1487 = v1->reg_ready;
  int v1488 = v1487[21];
  int v1598 = v1488 + ((v1486 - v1488) & (~((v1486 - v1488) >> 31)));
  v1->timer = v1598;
  int v1490 = v1->timer;
  int * v1491 = v1->reg_ready;
  int v1492 = v1491[22];
  int v1601 = v1492 + ((v1490 - v1492) & (~((v1490 - v1492) >> 31)));
  v1->timer = v1601;
  int v1494 = v1->timer;
  int * v1495 = v1->reg_ready;
  int v1496 = v1495[23];
  int v1604 = v1496 + ((v1494 - v1496) & (~((v1494 - v1496) >> 31)));
  v1->timer = v1604;
  int v1498 = v1->timer;
  int * v1499 = v1->reg_ready;
  int v1500 = v1499[24];
  int v1607 = v1500 + ((v1498 - v1500) & (~((v1498 - v1500) >> 31)));
  v1->timer = v1607;
  int v1502 = v1->timer;
  int * v1503 = v1->reg_ready;
  int v1504 = v1503[25];
  int v1610 = v1504 + ((v1502 - v1504) & (~((v1502 - v1504) >> 31)));
  v1->timer = v1610;
  int v1506 = v1->timer;
  int * v1507 = v1->reg_ready;
  int v1508 = v1507[26];
  int v1613 = v1508 + ((v1506 - v1508) & (~((v1506 - v1508) >> 31)));
  v1->timer = v1613;
  int v1510 = v1->timer;
  int * v1511 = v1->reg_ready;
  int v1512 = v1511[27];
  int v1616 = v1512 + ((v1510 - v1512) & (~((v1510 - v1512) >> 31)));
  v1->timer = v1616;
  int v1514 = v1->timer;
  int * v1515 = v1->reg_ready;
  int v1516 = v1515[28];
  int v1619 = v1516 + ((v1514 - v1516) & (~((v1514 - v1516) >> 31)));
  v1->timer = v1619;
  int v1518 = v1->timer;
  int * v1519 = v1->reg_ready;
  int v1520 = v1519[29];
  int v1622 = v1520 + ((v1518 - v1520) & (~((v1518 - v1520) >> 31)));
  v1->timer = v1622;
  int v1522 = v1->timer;
  int * v1523 = v1->reg_ready;
  int v1524 = v1523[30];
  int v1625 = v1524 + ((v1522 - v1524) & (~((v1522 - v1524) >> 31)));
  v1->timer = v1625;
  int v1526 = v1->timer;
  int * v1527 = v1->reg_ready;
  int v1528 = v1527[31];
  int v1628 = v1528 + ((v1526 - v1528) & (~((v1526 - v1528) >> 31)));
  v1->timer = v1628;
  return v1;
}

struct StateT * slot_8(struct StateT * v353) {
  int * v354 = v353->saved_regs;
  int * v355 = v353->regs;
  int v356 = v355[11];
  v354[11] = v356;
  int v358 = v353->timer;
  int v474 = v358 + 1;
  v353->timer = v474;
  int * v360 = v353->reg_ready;
  int v361 = v360[6];
  int * v362 = v353->regs;
  int v363 = v362[6];
  int * v364 = v353->cache_tags;
  int v479 = (((int)((unsigned int)((int)((unsigned int)v363 >> 2)) >> 1)) & 1) * 2;
  int v365 = v364[v479];
  int v480 = ((((int)((unsigned int)((int)((unsigned int)v363 >> 2)) >> 1)) & 1) * 2) + 1;
  int v366 = v364[v480];
  int v481 = 4 + ((((int)((unsigned int)((int)((unsigned int)v363 >> 2)) >> 1)) & 3) * 2);
  int v367 = v364[v481];
  int v482 = (4 + ((((int)((unsigned int)((int)((unsigned int)v363 >> 2)) >> 1)) & 3) * 2)) + 1;
  int v368 = v364[v482];
  int * v369 = v353->cache_vals;
  bool v483 = !(((~(((v365 ^ ((int)((unsigned int)((int)((unsigned int)v363 >> 2)) >> 1))) | (-(v365 ^ ((int)((unsigned int)((int)((unsigned int)v363 >> 2)) >> 1))))) >> 31)) | (~(((v366 ^ ((int)((unsigned int)((int)((unsigned int)v363 >> 2)) >> 1))) | (-(v366 ^ ((int)((unsigned int)((int)((unsigned int)v363 >> 2)) >> 1))))) >> 31))) == 0);
  int v462;
  if (v483) {
    int * v370 = v353->cache_age;
    int v485 = ((((int)((unsigned int)((int)((unsigned int)v363 >> 2)) >> 1)) & 1) * 2) + ((~(((v366 ^ ((int)((unsigned int)((int)((unsigned int)v363 >> 2)) >> 1))) | (-(v366 ^ ((int)((unsigned int)((int)((unsigned int)v363 >> 2)) >> 1))))) >> 31)) & 1);
    int v371 = v370[v485];
    int v372 = v370[v479];
    int v486 = v372 + ((int)((unsigned int)(v372 - v371) >> 31));
    v370[v479] = v486;
    int * v374 = v353->cache_age;
    int v375 = v374[v480];
    int v488 = v375 + ((int)((unsigned int)(v375 - v371) >> 31));
    v374[v480] = v488;
    int * v377 = v353->cache_age;
    v377[v485] = 0;
    v462 = v485;
  } else {
    int * v380 = v353->cache_age;
    int v492 = (((int)((unsigned int)((int)((unsigned int)v363 >> 2)) >> 1)) & 1) * 2;
    int v381 = v380[v492];
    int * v382 = v353->cache_tags;
    int v383 = v382[v492];
    int v384 = v380[v480];
    int v385 = v382[v480];
    bool v494 = !(((~(((v367 ^ ((int)((unsigned int)((int)((unsigned int)v363 >> 2)) >> 1))) | (-(v367 ^ ((int)((unsigned int)((int)((unsigned int)v363 >> 2)) >> 1))))) >> 31)) | (~(((v368 ^ ((int)((unsigned int)((int)((unsigned int)v363 >> 2)) >> 1))) | (-(v368 ^ ((int)((unsigned int)((int)((unsigned int)v363 >> 2)) >> 1))))) >> 31))) == 0);
    int v439;
    if (v494) {
      int * v386 = v353->cache_age;
      int v496 = (4 + ((((int)((unsigned int)((int)((unsigned int)v363 >> 2)) >> 1)) & 3) * 2)) + ((~(((v368 ^ ((int)((unsigned int)((int)((unsigned int)v363 >> 2)) >> 1))) | (-(v368 ^ ((int)((unsigned int)((int)((unsigned int)v363 >> 2)) >> 1))))) >> 31)) & 1);
      int v387 = v386[v496];
      int v388 = v386[v481];
      int v497 = v388 + ((int)((unsigned int)(v388 - v387) >> 31));
      v386[v481] = v497;
      int * v390 = v353->cache_age;
      int v391 = v390[v482];
      int v499 = v391 + ((int)((unsigned int)(v391 - v387) >> 31));
      v390[v482] = v499;
      int * v393 = v353->cache_age;
      v393[v496] = 0;
      v439 = v496;
    } else {
      int * v396 = v353->cache_age;
      int v503 = 4 + ((((int)((unsigned int)((int)((unsigned int)v363 >> 2)) >> 1)) & 3) * 2);
      int v397 = v396[v503];
      int * v398 = v353->cache_tags;
      int v399 = v398[v503];
      int v400 = v396[v482];
      int v401 = v398[v482];
      int * v402 = v353->cache_dirty;
      int v506 = (4 + ((((int)((unsigned int)((int)((unsigned int)v363 >> 2)) >> 1)) & 3) * 2)) + ((((v397 + ((~(((v399 ^ -1) | (-(v399 ^ -1))) >> 31)) & 2)) - (v400 + ((~(((v401 ^ -1) | (-(v401 ^ -1))) >> 31)) & 2))) >> 31) & 1);
      int v403 = v402[v506];
      bool v507 = !(v403 == 0);
      if (v507) {
        int * v404 = v353->cache_tags;
        int v405 = v404[v506];
        int * v406 = v353->cache_vals;
        int v510 = ((4 + ((((int)((unsigned int)((int)((unsigned int)v363 >> 2)) >> 1)) & 3) * 2)) + ((((v397 + ((~(((v399 ^ -1) | (-(v399 ^ -1))) >> 31)) & 2)) - (v400 + ((~(((v401 ^ -1) | (-(v401 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
        int v407 = v406[v510];
        int v511 = (((4 + ((((int)((unsigned int)((int)((unsigned int)v363 >> 2)) >> 1)) & 3) * 2)) + ((((v397 + ((~(((v399 ^ -1) | (-(v399 ^ -1))) >> 31)) & 2)) - (v400 + ((~(((v401 ^ -1) | (-(v401 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
        int v408 = v406[v511];
        int * v409 = v353->mem;
        int v513 = v405 * 2;
        v409[v513] = v407;
        int * v411 = v353->mem;
        int v516 = (v405 * 2) + 1;
        v411[v516] = v408;
        ;
      } else {
        ;
      }
      int * v416 = v353->mem;
      int v521 = ((int)((unsigned int)((int)((unsigned int)v363 >> 2)) >> 1)) * 2;
      int v417 = v416[v521];
      int v522 = (((int)((unsigned int)((int)((unsigned int)v363 >> 2)) >> 1)) * 2) + 1;
      int v418 = v416[v522];
      int * v419 = v353->cache_vals;
      int v524 = ((4 + ((((int)((unsigned int)((int)((unsigned int)v363 >> 2)) >> 1)) & 3) * 2)) + ((((v397 + ((~(((v399 ^ -1) | (-(v399 ^ -1))) >> 31)) & 2)) - (v400 + ((~(((v401 ^ -1) | (-(v401 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
      v419[v524] = v417;
      int * v421 = v353->cache_vals;
      int v527 = (((4 + ((((int)((unsigned int)((int)((unsigned int)v363 >> 2)) >> 1)) & 3) * 2)) + ((((v397 + ((~(((v399 ^ -1) | (-(v399 ^ -1))) >> 31)) & 2)) - (v400 + ((~(((v401 ^ -1) | (-(v401 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
      v421[v527] = v418;
      int * v423 = v353->cache_tags;
      int v530 = (int)((unsigned int)((int)((unsigned int)v363 >> 2)) >> 1);
      v423[v506] = v530;
      int * v425 = v353->cache_dirty;
      v425[v506] = 0;
      int * v427 = v353->cache_age;
      v427[v506] = 1;
      int * v429 = v353->cache_age;
      int v430 = v429[v506];
      int v431 = v429[v481];
      int v536 = v431 + ((int)((unsigned int)(v431 - v430) >> 31));
      v429[v481] = v536;
      int * v433 = v353->cache_age;
      int v434 = v433[v482];
      int v538 = v434 + ((int)((unsigned int)(v434 - v430) >> 31));
      v433[v482] = v538;
      int * v436 = v353->cache_age;
      v436[v506] = 0;
      v439 = v506;
    }
    int * v440 = v353->cache_vals;
    int v541 = v439 * 2;
    int v441 = v440[v541];
    int v542 = (v439 * 2) + 1;
    int v442 = v440[v542];
    int v543 = (((((int)((unsigned int)((int)((unsigned int)v363 >> 2)) >> 1)) & 1) * 2) + ((((v381 + ((~(((v383 ^ -1) | (-(v383 ^ -1))) >> 31)) & 2)) - (v384 + ((~(((v385 ^ -1) | (-(v385 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
    v440[v543] = v441;
    int * v444 = v353->cache_vals;
    int v546 = ((((((int)((unsigned int)((int)((unsigned int)v363 >> 2)) >> 1)) & 1) * 2) + ((((v381 + ((~(((v383 ^ -1) | (-(v383 ^ -1))) >> 31)) & 2)) - (v384 + ((~(((v385 ^ -1) | (-(v385 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
    v444[v546] = v442;
    int * v446 = v353->cache_tags;
    int v549 = ((((int)((unsigned int)((int)((unsigned int)v363 >> 2)) >> 1)) & 1) * 2) + ((((v381 + ((~(((v383 ^ -1) | (-(v383 ^ -1))) >> 31)) & 2)) - (v384 + ((~(((v385 ^ -1) | (-(v385 ^ -1))) >> 31)) & 2))) >> 31) & 1);
    int v550 = (int)((unsigned int)((int)((unsigned int)v363 >> 2)) >> 1);
    v446[v549] = v550;
    int * v448 = v353->cache_dirty;
    v448[v549] = 0;
    int * v450 = v353->cache_age;
    v450[v549] = 1;
    int * v452 = v353->cache_age;
    int v453 = v452[v549];
    int v454 = v452[v479];
    int v556 = v454 + ((int)((unsigned int)(v454 - v453) >> 31));
    v452[v479] = v556;
    int * v456 = v353->cache_age;
    int v457 = v456[v480];
    int v558 = v457 + ((int)((unsigned int)(v457 - v453) >> 31));
    v456[v480] = v558;
    int * v459 = v353->cache_age;
    v459[v549] = 0;
    v462 = v549;
  }
  int v561 = (v462 * 2) + (((int)((unsigned int)v363 >> 2)) & 1);
  int v463 = v369[v561];
  int * v464 = v353->reg_ready;
  int v563 = ((v361 + ((v358 - v361) & (~((v358 - v361) >> 31)))) + 1) + ((100 ^ (((~(((v367 ^ ((int)((unsigned int)((int)((unsigned int)v363 >> 2)) >> 1))) | (-(v367 ^ ((int)((unsigned int)((int)((unsigned int)v363 >> 2)) >> 1))))) >> 31)) | (~(((v368 ^ ((int)((unsigned int)((int)((unsigned int)v363 >> 2)) >> 1))) | (-(v368 ^ ((int)((unsigned int)((int)((unsigned int)v363 >> 2)) >> 1))))) >> 31))) & 104)) ^ (((~(((v365 ^ ((int)((unsigned int)((int)((unsigned int)v363 >> 2)) >> 1))) | (-(v365 ^ ((int)((unsigned int)((int)((unsigned int)v363 >> 2)) >> 1))))) >> 31)) | (~(((v366 ^ ((int)((unsigned int)((int)((unsigned int)v363 >> 2)) >> 1))) | (-(v366 ^ ((int)((unsigned int)((int)((unsigned int)v363 >> 2)) >> 1))))) >> 31))) & (1 ^ (100 ^ (((~(((v367 ^ ((int)((unsigned int)((int)((unsigned int)v363 >> 2)) >> 1))) | (-(v367 ^ ((int)((unsigned int)((int)((unsigned int)v363 >> 2)) >> 1))))) >> 31)) | (~(((v368 ^ ((int)((unsigned int)((int)((unsigned int)v363 >> 2)) >> 1))) | (-(v368 ^ ((int)((unsigned int)((int)((unsigned int)v363 >> 2)) >> 1))))) >> 31))) & 104)))));
  v464[11] = v563;
  int * v466 = v353->regs;
  v466[11] = v463;
  struct StateT * v468 = slot_23(v353);
  return v468;
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