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

struct StateT * snippet(struct StateT * v0);
struct StateT * slot_1(struct StateT * v18);
struct StateT * slot_6(struct StateT * v857);
struct StateT * slot_5(struct StateT * v832);
struct StateT * slot_4(struct StateT * v640);
struct StateT * slot_2(struct StateT * v321);
struct StateT * slot_7(struct StateT * v1065);
struct StateT * slot_3(struct StateT * v337);
struct StateT * slot_0(struct StateT * v2);
struct StateT * snippet(struct StateT * v0) {
  struct StateT * v1 = slot_0(v0);
  int v1270 = v1->timer;
  int * v1271 = v1->reg_ready;
  int v1272 = v1271[0];
  int v1403 = v1272 + ((v1270 - v1272) & (~((v1270 - v1272) >> 31)));
  v1->timer = v1403;
  int v1274 = v1->timer;
  int * v1275 = v1->reg_ready;
  int v1276 = v1275[1];
  int v1406 = v1276 + ((v1274 - v1276) & (~((v1274 - v1276) >> 31)));
  v1->timer = v1406;
  int v1278 = v1->timer;
  int * v1279 = v1->reg_ready;
  int v1280 = v1279[2];
  int v1409 = v1280 + ((v1278 - v1280) & (~((v1278 - v1280) >> 31)));
  v1->timer = v1409;
  int v1282 = v1->timer;
  int * v1283 = v1->reg_ready;
  int v1284 = v1283[3];
  int v1412 = v1284 + ((v1282 - v1284) & (~((v1282 - v1284) >> 31)));
  v1->timer = v1412;
  int v1286 = v1->timer;
  int * v1287 = v1->reg_ready;
  int v1288 = v1287[4];
  int v1415 = v1288 + ((v1286 - v1288) & (~((v1286 - v1288) >> 31)));
  v1->timer = v1415;
  int v1290 = v1->timer;
  int * v1291 = v1->reg_ready;
  int v1292 = v1291[5];
  int v1418 = v1292 + ((v1290 - v1292) & (~((v1290 - v1292) >> 31)));
  v1->timer = v1418;
  int v1294 = v1->timer;
  int * v1295 = v1->reg_ready;
  int v1296 = v1295[6];
  int v1421 = v1296 + ((v1294 - v1296) & (~((v1294 - v1296) >> 31)));
  v1->timer = v1421;
  int v1298 = v1->timer;
  int * v1299 = v1->reg_ready;
  int v1300 = v1299[7];
  int v1424 = v1300 + ((v1298 - v1300) & (~((v1298 - v1300) >> 31)));
  v1->timer = v1424;
  int v1302 = v1->timer;
  int * v1303 = v1->reg_ready;
  int v1304 = v1303[8];
  int v1427 = v1304 + ((v1302 - v1304) & (~((v1302 - v1304) >> 31)));
  v1->timer = v1427;
  int v1306 = v1->timer;
  int * v1307 = v1->reg_ready;
  int v1308 = v1307[9];
  int v1430 = v1308 + ((v1306 - v1308) & (~((v1306 - v1308) >> 31)));
  v1->timer = v1430;
  int v1310 = v1->timer;
  int * v1311 = v1->reg_ready;
  int v1312 = v1311[10];
  int v1433 = v1312 + ((v1310 - v1312) & (~((v1310 - v1312) >> 31)));
  v1->timer = v1433;
  int v1314 = v1->timer;
  int * v1315 = v1->reg_ready;
  int v1316 = v1315[11];
  int v1436 = v1316 + ((v1314 - v1316) & (~((v1314 - v1316) >> 31)));
  v1->timer = v1436;
  int v1318 = v1->timer;
  int * v1319 = v1->reg_ready;
  int v1320 = v1319[12];
  int v1439 = v1320 + ((v1318 - v1320) & (~((v1318 - v1320) >> 31)));
  v1->timer = v1439;
  int v1322 = v1->timer;
  int * v1323 = v1->reg_ready;
  int v1324 = v1323[13];
  int v1442 = v1324 + ((v1322 - v1324) & (~((v1322 - v1324) >> 31)));
  v1->timer = v1442;
  int v1326 = v1->timer;
  int * v1327 = v1->reg_ready;
  int v1328 = v1327[14];
  int v1445 = v1328 + ((v1326 - v1328) & (~((v1326 - v1328) >> 31)));
  v1->timer = v1445;
  int v1330 = v1->timer;
  int * v1331 = v1->reg_ready;
  int v1332 = v1331[15];
  int v1448 = v1332 + ((v1330 - v1332) & (~((v1330 - v1332) >> 31)));
  v1->timer = v1448;
  int v1334 = v1->timer;
  int * v1335 = v1->reg_ready;
  int v1336 = v1335[16];
  int v1451 = v1336 + ((v1334 - v1336) & (~((v1334 - v1336) >> 31)));
  v1->timer = v1451;
  int v1338 = v1->timer;
  int * v1339 = v1->reg_ready;
  int v1340 = v1339[17];
  int v1454 = v1340 + ((v1338 - v1340) & (~((v1338 - v1340) >> 31)));
  v1->timer = v1454;
  int v1342 = v1->timer;
  int * v1343 = v1->reg_ready;
  int v1344 = v1343[18];
  int v1457 = v1344 + ((v1342 - v1344) & (~((v1342 - v1344) >> 31)));
  v1->timer = v1457;
  int v1346 = v1->timer;
  int * v1347 = v1->reg_ready;
  int v1348 = v1347[19];
  int v1460 = v1348 + ((v1346 - v1348) & (~((v1346 - v1348) >> 31)));
  v1->timer = v1460;
  int v1350 = v1->timer;
  int * v1351 = v1->reg_ready;
  int v1352 = v1351[20];
  int v1463 = v1352 + ((v1350 - v1352) & (~((v1350 - v1352) >> 31)));
  v1->timer = v1463;
  int v1354 = v1->timer;
  int * v1355 = v1->reg_ready;
  int v1356 = v1355[21];
  int v1466 = v1356 + ((v1354 - v1356) & (~((v1354 - v1356) >> 31)));
  v1->timer = v1466;
  int v1358 = v1->timer;
  int * v1359 = v1->reg_ready;
  int v1360 = v1359[22];
  int v1469 = v1360 + ((v1358 - v1360) & (~((v1358 - v1360) >> 31)));
  v1->timer = v1469;
  int v1362 = v1->timer;
  int * v1363 = v1->reg_ready;
  int v1364 = v1363[23];
  int v1472 = v1364 + ((v1362 - v1364) & (~((v1362 - v1364) >> 31)));
  v1->timer = v1472;
  int v1366 = v1->timer;
  int * v1367 = v1->reg_ready;
  int v1368 = v1367[24];
  int v1475 = v1368 + ((v1366 - v1368) & (~((v1366 - v1368) >> 31)));
  v1->timer = v1475;
  int v1370 = v1->timer;
  int * v1371 = v1->reg_ready;
  int v1372 = v1371[25];
  int v1478 = v1372 + ((v1370 - v1372) & (~((v1370 - v1372) >> 31)));
  v1->timer = v1478;
  int v1374 = v1->timer;
  int * v1375 = v1->reg_ready;
  int v1376 = v1375[26];
  int v1481 = v1376 + ((v1374 - v1376) & (~((v1374 - v1376) >> 31)));
  v1->timer = v1481;
  int v1378 = v1->timer;
  int * v1379 = v1->reg_ready;
  int v1380 = v1379[27];
  int v1484 = v1380 + ((v1378 - v1380) & (~((v1378 - v1380) >> 31)));
  v1->timer = v1484;
  int v1382 = v1->timer;
  int * v1383 = v1->reg_ready;
  int v1384 = v1383[28];
  int v1487 = v1384 + ((v1382 - v1384) & (~((v1382 - v1384) >> 31)));
  v1->timer = v1487;
  int v1386 = v1->timer;
  int * v1387 = v1->reg_ready;
  int v1388 = v1387[29];
  int v1490 = v1388 + ((v1386 - v1388) & (~((v1386 - v1388) >> 31)));
  v1->timer = v1490;
  int v1390 = v1->timer;
  int * v1391 = v1->reg_ready;
  int v1392 = v1391[30];
  int v1493 = v1392 + ((v1390 - v1392) & (~((v1390 - v1392) >> 31)));
  v1->timer = v1493;
  int v1394 = v1->timer;
  int * v1395 = v1->reg_ready;
  int v1396 = v1395[31];
  int v1496 = v1396 + ((v1394 - v1396) & (~((v1394 - v1396) >> 31)));
  v1->timer = v1496;
  return v1;
}

struct StateT * slot_1(struct StateT * v18) {
  int v19 = v18->timer;
  int v190 = v19 + 1;
  v18->timer = v190;
  int * v21 = v18->reg_ready;
  int * v23 = v18->regs;
  int v24 = v23[5];
  int * v25 = v18->cache_tags;
  int v26 = v25[0];
  int v27 = v25[1];
  int v28 = v25[8];
  int v29 = v25[9];
  int v30 = v18->timer;
  int v199 = v30 + ((100 ^ (((~(((v28 ^ 6) | (-(v28 ^ 6))) >> 31)) | (~(((v29 ^ 6) | (-(v29 ^ 6))) >> 31))) & 104)) ^ (((~(((v26 ^ 6) | (-(v26 ^ 6))) >> 31)) | (~(((v27 ^ 6) | (-(v27 ^ 6))) >> 31))) & (1 ^ (100 ^ (((~(((v28 ^ 6) | (-(v28 ^ 6))) >> 31)) | (~(((v29 ^ 6) | (-(v29 ^ 6))) >> 31))) & 104)))));
  v18->timer = v199;
  bool v200 = !(((~(((v26 ^ 6) | (-(v26 ^ 6))) >> 31)) | (~(((v27 ^ 6) | (-(v27 ^ 6))) >> 31))) == 0);
  int v124;
  if (v200) {
    int * v32 = v18->cache_age;
    int v202 = (~(((v27 ^ 6) | (-(v27 ^ 6))) >> 31)) & 1;
    int v33 = v32[v202];
    int v34 = v32[0];
    int v203 = v34 + ((int)((unsigned int)(v34 - v33) >> 31));
    v32[0] = v203;
    int * v36 = v18->cache_age;
    int v37 = v36[1];
    int v205 = v37 + ((int)((unsigned int)(v37 - v33) >> 31));
    v36[1] = v205;
    int * v39 = v18->cache_age;
    v39[v202] = 0;
    v124 = v202;
  } else {
    int * v42 = v18->cache_age;
    int v43 = v42[0];
    int * v44 = v18->cache_tags;
    int v45 = v44[0];
    int v46 = v42[1];
    int v47 = v44[1];
    bool v209 = !(((~(((v28 ^ 6) | (-(v28 ^ 6))) >> 31)) | (~(((v29 ^ 6) | (-(v29 ^ 6))) >> 31))) == 0);
    int v101;
    if (v209) {
      int * v48 = v18->cache_age;
      int v211 = 8 + ((~(((v29 ^ 6) | (-(v29 ^ 6))) >> 31)) & 1);
      int v49 = v48[v211];
      int v50 = v48[8];
      int v212 = v50 + ((int)((unsigned int)(v50 - v49) >> 31));
      v48[8] = v212;
      int * v52 = v18->cache_age;
      int v53 = v52[9];
      int v214 = v53 + ((int)((unsigned int)(v53 - v49) >> 31));
      v52[9] = v214;
      int * v55 = v18->cache_age;
      v55[v211] = 0;
      v101 = v211;
    } else {
      int * v58 = v18->cache_age;
      int v59 = v58[8];
      int * v60 = v18->cache_tags;
      int v61 = v60[8];
      int v62 = v58[9];
      int v63 = v60[9];
      int * v64 = v18->cache_dirty;
      int v219 = 8 + ((((v59 + ((~(((v61 ^ -1) | (-(v61 ^ -1))) >> 31)) & 2)) - (v62 + ((~(((v63 ^ -1) | (-(v63 ^ -1))) >> 31)) & 2))) >> 31) & 1);
      int v65 = v64[v219];
      bool v220 = !(v65 == 0);
      if (v220) {
        int * v66 = v18->cache_tags;
        int v67 = v66[v219];
        int * v68 = v18->cache_vals;
        int v223 = (8 + ((((v59 + ((~(((v61 ^ -1) | (-(v61 ^ -1))) >> 31)) & 2)) - (v62 + ((~(((v63 ^ -1) | (-(v63 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
        int v69 = v68[v223];
        int v224 = ((8 + ((((v59 + ((~(((v61 ^ -1) | (-(v61 ^ -1))) >> 31)) & 2)) - (v62 + ((~(((v63 ^ -1) | (-(v63 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
        int v70 = v68[v224];
        int * v71 = v18->mem;
        int v226 = v67 * 2;
        v71[v226] = v69;
        int * v73 = v18->mem;
        int v229 = (v67 * 2) + 1;
        v73[v229] = v70;
        ;
      } else {
        ;
      }
      int * v78 = v18->mem;
      int v79 = v78[12];
      int v80 = v78[13];
      int * v81 = v18->cache_vals;
      int v237 = (8 + ((((v59 + ((~(((v61 ^ -1) | (-(v61 ^ -1))) >> 31)) & 2)) - (v62 + ((~(((v63 ^ -1) | (-(v63 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
      v81[v237] = v79;
      int * v83 = v18->cache_vals;
      int v240 = ((8 + ((((v59 + ((~(((v61 ^ -1) | (-(v61 ^ -1))) >> 31)) & 2)) - (v62 + ((~(((v63 ^ -1) | (-(v63 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
      v83[v240] = v80;
      int * v85 = v18->cache_tags;
      v85[v219] = 6;
      int * v87 = v18->cache_dirty;
      v87[v219] = 0;
      int * v89 = v18->cache_age;
      v89[v219] = 1;
      int * v91 = v18->cache_age;
      int v92 = v91[v219];
      int v93 = v91[8];
      int v247 = v93 + ((int)((unsigned int)(v93 - v92) >> 31));
      v91[8] = v247;
      int * v95 = v18->cache_age;
      int v96 = v95[9];
      int v249 = v96 + ((int)((unsigned int)(v96 - v92) >> 31));
      v95[9] = v249;
      int * v98 = v18->cache_age;
      v98[v219] = 0;
      v101 = v219;
    }
    int * v102 = v18->cache_vals;
    int v252 = v101 * 2;
    int v103 = v102[v252];
    int v253 = (v101 * 2) + 1;
    int v104 = v102[v253];
    int v254 = ((((v43 + ((~(((v45 ^ -1) | (-(v45 ^ -1))) >> 31)) & 2)) - (v46 + ((~(((v47 ^ -1) | (-(v47 ^ -1))) >> 31)) & 2))) >> 31) & 1) * 2;
    v102[v254] = v103;
    int * v106 = v18->cache_vals;
    int v257 = (((((v43 + ((~(((v45 ^ -1) | (-(v45 ^ -1))) >> 31)) & 2)) - (v46 + ((~(((v47 ^ -1) | (-(v47 ^ -1))) >> 31)) & 2))) >> 31) & 1) * 2) + 1;
    v106[v257] = v104;
    int * v108 = v18->cache_tags;
    int v260 = (((v43 + ((~(((v45 ^ -1) | (-(v45 ^ -1))) >> 31)) & 2)) - (v46 + ((~(((v47 ^ -1) | (-(v47 ^ -1))) >> 31)) & 2))) >> 31) & 1;
    v108[v260] = 6;
    int * v110 = v18->cache_dirty;
    v110[v260] = 0;
    int * v112 = v18->cache_age;
    v112[v260] = 1;
    int * v114 = v18->cache_age;
    int v115 = v114[v260];
    int v116 = v114[0];
    int v265 = v116 + ((int)((unsigned int)(v116 - v115) >> 31));
    v114[0] = v265;
    int * v118 = v18->cache_age;
    int v119 = v118[1];
    int v267 = v119 + ((int)((unsigned int)(v119 - v115) >> 31));
    v118[1] = v267;
    int * v121 = v18->cache_age;
    v121[v260] = 0;
    v124 = v260;
  }
  int * v125 = v18->cache_vals;
  int v270 = (v124 * 2) + 1;
  v125[v270] = v24;
  int * v127 = v18->cache_tags;
  int v128 = v127[8];
  int v129 = v127[9];
  bool v273 = !(((~(((v128 ^ 6) | (-(v128 ^ 6))) >> 31)) | (~(((v129 ^ 6) | (-(v129 ^ 6))) >> 31))) == 0);
  int v183;
  if (v273) {
    int * v130 = v18->cache_age;
    int v275 = 8 + ((~(((v129 ^ 6) | (-(v129 ^ 6))) >> 31)) & 1);
    int v131 = v130[v275];
    int v132 = v130[8];
    int v276 = v132 + ((int)((unsigned int)(v132 - v131) >> 31));
    v130[8] = v276;
    int * v134 = v18->cache_age;
    int v135 = v134[9];
    int v278 = v135 + ((int)((unsigned int)(v135 - v131) >> 31));
    v134[9] = v278;
    int * v137 = v18->cache_age;
    v137[v275] = 0;
    v183 = v275;
  } else {
    int * v140 = v18->cache_age;
    int v141 = v140[8];
    int * v142 = v18->cache_tags;
    int v143 = v142[8];
    int v144 = v140[9];
    int v145 = v142[9];
    int * v146 = v18->cache_dirty;
    int v283 = 8 + ((((v141 + ((~(((v143 ^ -1) | (-(v143 ^ -1))) >> 31)) & 2)) - (v144 + ((~(((v145 ^ -1) | (-(v145 ^ -1))) >> 31)) & 2))) >> 31) & 1);
    int v147 = v146[v283];
    bool v284 = !(v147 == 0);
    if (v284) {
      int * v148 = v18->cache_tags;
      int v149 = v148[v283];
      int * v150 = v18->cache_vals;
      int v287 = (8 + ((((v141 + ((~(((v143 ^ -1) | (-(v143 ^ -1))) >> 31)) & 2)) - (v144 + ((~(((v145 ^ -1) | (-(v145 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
      int v151 = v150[v287];
      int v288 = ((8 + ((((v141 + ((~(((v143 ^ -1) | (-(v143 ^ -1))) >> 31)) & 2)) - (v144 + ((~(((v145 ^ -1) | (-(v145 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
      int v152 = v150[v288];
      int * v153 = v18->mem;
      int v290 = v149 * 2;
      v153[v290] = v151;
      int * v155 = v18->mem;
      int v293 = (v149 * 2) + 1;
      v155[v293] = v152;
      ;
    } else {
      ;
    }
    int * v160 = v18->mem;
    int v161 = v160[12];
    int v162 = v160[13];
    int * v163 = v18->cache_vals;
    int v301 = (8 + ((((v141 + ((~(((v143 ^ -1) | (-(v143 ^ -1))) >> 31)) & 2)) - (v144 + ((~(((v145 ^ -1) | (-(v145 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
    v163[v301] = v161;
    int * v165 = v18->cache_vals;
    int v304 = ((8 + ((((v141 + ((~(((v143 ^ -1) | (-(v143 ^ -1))) >> 31)) & 2)) - (v144 + ((~(((v145 ^ -1) | (-(v145 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
    v165[v304] = v162;
    int * v167 = v18->cache_tags;
    v167[v283] = 6;
    int * v169 = v18->cache_dirty;
    v169[v283] = 0;
    int * v171 = v18->cache_age;
    v171[v283] = 1;
    int * v173 = v18->cache_age;
    int v174 = v173[v283];
    int v175 = v173[8];
    int v311 = v175 + ((int)((unsigned int)(v175 - v174) >> 31));
    v173[8] = v311;
    int * v177 = v18->cache_age;
    int v178 = v177[9];
    int v313 = v178 + ((int)((unsigned int)(v178 - v174) >> 31));
    v177[9] = v313;
    int * v180 = v18->cache_age;
    v180[v283] = 0;
    v183 = v283;
  }
  int * v184 = v18->cache_vals;
  int v316 = (v183 * 2) + 1;
  v184[v316] = v24;
  int * v186 = v18->cache_dirty;
  v186[v183] = 1;
  struct StateT * v188 = slot_2(v18);
  return v188;
}

struct StateT * slot_6(struct StateT * v857) {
  int v858 = v857->timer;
  int v970 = v858 + 1;
  v857->timer = v970;
  int * v860 = v857->reg_ready;
  int v861 = v860[9];
  int * v862 = v857->regs;
  int v863 = v862[9];
  int * v864 = v857->cache_tags;
  int v975 = (((int)((unsigned int)((int)((unsigned int)v863 >> 2)) >> 1)) & 1) * 2;
  int v865 = v864[v975];
  int v976 = ((((int)((unsigned int)((int)((unsigned int)v863 >> 2)) >> 1)) & 1) * 2) + 1;
  int v866 = v864[v976];
  int v977 = 4 + ((((int)((unsigned int)((int)((unsigned int)v863 >> 2)) >> 1)) & 3) * 2);
  int v867 = v864[v977];
  int v978 = (4 + ((((int)((unsigned int)((int)((unsigned int)v863 >> 2)) >> 1)) & 3) * 2)) + 1;
  int v868 = v864[v978];
  int * v869 = v857->cache_vals;
  bool v979 = !(((~(((v865 ^ ((int)((unsigned int)((int)((unsigned int)v863 >> 2)) >> 1))) | (-(v865 ^ ((int)((unsigned int)((int)((unsigned int)v863 >> 2)) >> 1))))) >> 31)) | (~(((v866 ^ ((int)((unsigned int)((int)((unsigned int)v863 >> 2)) >> 1))) | (-(v866 ^ ((int)((unsigned int)((int)((unsigned int)v863 >> 2)) >> 1))))) >> 31))) == 0);
  int v962;
  if (v979) {
    int * v870 = v857->cache_age;
    int v981 = ((((int)((unsigned int)((int)((unsigned int)v863 >> 2)) >> 1)) & 1) * 2) + ((~(((v866 ^ ((int)((unsigned int)((int)((unsigned int)v863 >> 2)) >> 1))) | (-(v866 ^ ((int)((unsigned int)((int)((unsigned int)v863 >> 2)) >> 1))))) >> 31)) & 1);
    int v871 = v870[v981];
    int v872 = v870[v975];
    int v982 = v872 + ((int)((unsigned int)(v872 - v871) >> 31));
    v870[v975] = v982;
    int * v874 = v857->cache_age;
    int v875 = v874[v976];
    int v984 = v875 + ((int)((unsigned int)(v875 - v871) >> 31));
    v874[v976] = v984;
    int * v877 = v857->cache_age;
    v877[v981] = 0;
    v962 = v981;
  } else {
    int * v880 = v857->cache_age;
    int v988 = (((int)((unsigned int)((int)((unsigned int)v863 >> 2)) >> 1)) & 1) * 2;
    int v881 = v880[v988];
    int * v882 = v857->cache_tags;
    int v883 = v882[v988];
    int v884 = v880[v976];
    int v885 = v882[v976];
    bool v990 = !(((~(((v867 ^ ((int)((unsigned int)((int)((unsigned int)v863 >> 2)) >> 1))) | (-(v867 ^ ((int)((unsigned int)((int)((unsigned int)v863 >> 2)) >> 1))))) >> 31)) | (~(((v868 ^ ((int)((unsigned int)((int)((unsigned int)v863 >> 2)) >> 1))) | (-(v868 ^ ((int)((unsigned int)((int)((unsigned int)v863 >> 2)) >> 1))))) >> 31))) == 0);
    int v939;
    if (v990) {
      int * v886 = v857->cache_age;
      int v992 = (4 + ((((int)((unsigned int)((int)((unsigned int)v863 >> 2)) >> 1)) & 3) * 2)) + ((~(((v868 ^ ((int)((unsigned int)((int)((unsigned int)v863 >> 2)) >> 1))) | (-(v868 ^ ((int)((unsigned int)((int)((unsigned int)v863 >> 2)) >> 1))))) >> 31)) & 1);
      int v887 = v886[v992];
      int v888 = v886[v977];
      int v993 = v888 + ((int)((unsigned int)(v888 - v887) >> 31));
      v886[v977] = v993;
      int * v890 = v857->cache_age;
      int v891 = v890[v978];
      int v995 = v891 + ((int)((unsigned int)(v891 - v887) >> 31));
      v890[v978] = v995;
      int * v893 = v857->cache_age;
      v893[v992] = 0;
      v939 = v992;
    } else {
      int * v896 = v857->cache_age;
      int v999 = 4 + ((((int)((unsigned int)((int)((unsigned int)v863 >> 2)) >> 1)) & 3) * 2);
      int v897 = v896[v999];
      int * v898 = v857->cache_tags;
      int v899 = v898[v999];
      int v900 = v896[v978];
      int v901 = v898[v978];
      int * v902 = v857->cache_dirty;
      int v1002 = (4 + ((((int)((unsigned int)((int)((unsigned int)v863 >> 2)) >> 1)) & 3) * 2)) + ((((v897 + ((~(((v899 ^ -1) | (-(v899 ^ -1))) >> 31)) & 2)) - (v900 + ((~(((v901 ^ -1) | (-(v901 ^ -1))) >> 31)) & 2))) >> 31) & 1);
      int v903 = v902[v1002];
      bool v1003 = !(v903 == 0);
      if (v1003) {
        int * v904 = v857->cache_tags;
        int v905 = v904[v1002];
        int * v906 = v857->cache_vals;
        int v1006 = ((4 + ((((int)((unsigned int)((int)((unsigned int)v863 >> 2)) >> 1)) & 3) * 2)) + ((((v897 + ((~(((v899 ^ -1) | (-(v899 ^ -1))) >> 31)) & 2)) - (v900 + ((~(((v901 ^ -1) | (-(v901 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
        int v907 = v906[v1006];
        int v1007 = (((4 + ((((int)((unsigned int)((int)((unsigned int)v863 >> 2)) >> 1)) & 3) * 2)) + ((((v897 + ((~(((v899 ^ -1) | (-(v899 ^ -1))) >> 31)) & 2)) - (v900 + ((~(((v901 ^ -1) | (-(v901 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
        int v908 = v906[v1007];
        int * v909 = v857->mem;
        int v1009 = v905 * 2;
        v909[v1009] = v907;
        int * v911 = v857->mem;
        int v1012 = (v905 * 2) + 1;
        v911[v1012] = v908;
        ;
      } else {
        ;
      }
      int * v916 = v857->mem;
      int v1017 = ((int)((unsigned int)((int)((unsigned int)v863 >> 2)) >> 1)) * 2;
      int v917 = v916[v1017];
      int v1018 = (((int)((unsigned int)((int)((unsigned int)v863 >> 2)) >> 1)) * 2) + 1;
      int v918 = v916[v1018];
      int * v919 = v857->cache_vals;
      int v1020 = ((4 + ((((int)((unsigned int)((int)((unsigned int)v863 >> 2)) >> 1)) & 3) * 2)) + ((((v897 + ((~(((v899 ^ -1) | (-(v899 ^ -1))) >> 31)) & 2)) - (v900 + ((~(((v901 ^ -1) | (-(v901 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
      v919[v1020] = v917;
      int * v921 = v857->cache_vals;
      int v1023 = (((4 + ((((int)((unsigned int)((int)((unsigned int)v863 >> 2)) >> 1)) & 3) * 2)) + ((((v897 + ((~(((v899 ^ -1) | (-(v899 ^ -1))) >> 31)) & 2)) - (v900 + ((~(((v901 ^ -1) | (-(v901 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
      v921[v1023] = v918;
      int * v923 = v857->cache_tags;
      int v1026 = (int)((unsigned int)((int)((unsigned int)v863 >> 2)) >> 1);
      v923[v1002] = v1026;
      int * v925 = v857->cache_dirty;
      v925[v1002] = 0;
      int * v927 = v857->cache_age;
      v927[v1002] = 1;
      int * v929 = v857->cache_age;
      int v930 = v929[v1002];
      int v931 = v929[v977];
      int v1032 = v931 + ((int)((unsigned int)(v931 - v930) >> 31));
      v929[v977] = v1032;
      int * v933 = v857->cache_age;
      int v934 = v933[v978];
      int v1034 = v934 + ((int)((unsigned int)(v934 - v930) >> 31));
      v933[v978] = v1034;
      int * v936 = v857->cache_age;
      v936[v1002] = 0;
      v939 = v1002;
    }
    int * v940 = v857->cache_vals;
    int v1037 = v939 * 2;
    int v941 = v940[v1037];
    int v1038 = (v939 * 2) + 1;
    int v942 = v940[v1038];
    int v1039 = (((((int)((unsigned int)((int)((unsigned int)v863 >> 2)) >> 1)) & 1) * 2) + ((((v881 + ((~(((v883 ^ -1) | (-(v883 ^ -1))) >> 31)) & 2)) - (v884 + ((~(((v885 ^ -1) | (-(v885 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
    v940[v1039] = v941;
    int * v944 = v857->cache_vals;
    int v1042 = ((((((int)((unsigned int)((int)((unsigned int)v863 >> 2)) >> 1)) & 1) * 2) + ((((v881 + ((~(((v883 ^ -1) | (-(v883 ^ -1))) >> 31)) & 2)) - (v884 + ((~(((v885 ^ -1) | (-(v885 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
    v944[v1042] = v942;
    int * v946 = v857->cache_tags;
    int v1045 = ((((int)((unsigned int)((int)((unsigned int)v863 >> 2)) >> 1)) & 1) * 2) + ((((v881 + ((~(((v883 ^ -1) | (-(v883 ^ -1))) >> 31)) & 2)) - (v884 + ((~(((v885 ^ -1) | (-(v885 ^ -1))) >> 31)) & 2))) >> 31) & 1);
    int v1046 = (int)((unsigned int)((int)((unsigned int)v863 >> 2)) >> 1);
    v946[v1045] = v1046;
    int * v948 = v857->cache_dirty;
    v948[v1045] = 0;
    int * v950 = v857->cache_age;
    v950[v1045] = 1;
    int * v952 = v857->cache_age;
    int v953 = v952[v1045];
    int v954 = v952[v975];
    int v1052 = v954 + ((int)((unsigned int)(v954 - v953) >> 31));
    v952[v975] = v1052;
    int * v956 = v857->cache_age;
    int v957 = v956[v976];
    int v1054 = v957 + ((int)((unsigned int)(v957 - v953) >> 31));
    v956[v976] = v1054;
    int * v959 = v857->cache_age;
    v959[v1045] = 0;
    v962 = v1045;
  }
  int v1057 = (v962 * 2) + (((int)((unsigned int)v863 >> 2)) & 1);
  int v963 = v869[v1057];
  int * v964 = v857->reg_ready;
  int v1060 = ((v861 + ((v858 - v861) & (~((v858 - v861) >> 31)))) + 1) + ((100 ^ (((~(((v867 ^ ((int)((unsigned int)((int)((unsigned int)v863 >> 2)) >> 1))) | (-(v867 ^ ((int)((unsigned int)((int)((unsigned int)v863 >> 2)) >> 1))))) >> 31)) | (~(((v868 ^ ((int)((unsigned int)((int)((unsigned int)v863 >> 2)) >> 1))) | (-(v868 ^ ((int)((unsigned int)((int)((unsigned int)v863 >> 2)) >> 1))))) >> 31))) & 104)) ^ (((~(((v865 ^ ((int)((unsigned int)((int)((unsigned int)v863 >> 2)) >> 1))) | (-(v865 ^ ((int)((unsigned int)((int)((unsigned int)v863 >> 2)) >> 1))))) >> 31)) | (~(((v866 ^ ((int)((unsigned int)((int)((unsigned int)v863 >> 2)) >> 1))) | (-(v866 ^ ((int)((unsigned int)((int)((unsigned int)v863 >> 2)) >> 1))))) >> 31))) & (1 ^ (100 ^ (((~(((v867 ^ ((int)((unsigned int)((int)((unsigned int)v863 >> 2)) >> 1))) | (-(v867 ^ ((int)((unsigned int)((int)((unsigned int)v863 >> 2)) >> 1))))) >> 31)) | (~(((v868 ^ ((int)((unsigned int)((int)((unsigned int)v863 >> 2)) >> 1))) | (-(v868 ^ ((int)((unsigned int)((int)((unsigned int)v863 >> 2)) >> 1))))) >> 31))) & 104)))));
  v964[11] = v1060;
  int * v966 = v857->regs;
  v966[11] = v963;
  struct StateT * v968 = slot_7(v857);
  return v968;
}

struct StateT * slot_5(struct StateT * v832) {
  int v833 = v832->timer;
  int v846 = v833 + 1;
  v832->timer = v846;
  int * v835 = v832->reg_ready;
  int v836 = v835[10];
  int * v837 = v832->regs;
  int v838 = v837[10];
  int v839 = v835[8];
  int v840 = v837[8];
  int v852 = (v839 + (((v836 + ((v833 - v836) & (~((v833 - v836) >> 31)))) - v839) & (~(((v836 + ((v833 - v836) & (~((v833 - v836) >> 31)))) - v839) >> 31)))) + 1;
  v835[9] = v852;
  int * v842 = v832->regs;
  int v854 = v838 & v840;
  v842[9] = v854;
  struct StateT * v844 = slot_6(v832);
  return v844;
}

struct StateT * slot_4(struct StateT * v640) {
  int v641 = v640->timer;
  int v749 = v641 + 1;
  v640->timer = v749;
  int * v643 = v640->cache_tags;
  int v644 = v643[0];
  int v645 = v643[1];
  int v646 = v643[8];
  int v647 = v643[9];
  int * v648 = v640->cache_vals;
  bool v755 = !(((~(((v644 ^ 6) | (-(v644 ^ 6))) >> 31)) | (~(((v645 ^ 6) | (-(v645 ^ 6))) >> 31))) == 0);
  int v741;
  if (v755) {
    int * v649 = v640->cache_age;
    int v757 = (~(((v645 ^ 6) | (-(v645 ^ 6))) >> 31)) & 1;
    int v650 = v649[v757];
    int v651 = v649[0];
    int v758 = v651 + ((int)((unsigned int)(v651 - v650) >> 31));
    v649[0] = v758;
    int * v653 = v640->cache_age;
    int v654 = v653[1];
    int v760 = v654 + ((int)((unsigned int)(v654 - v650) >> 31));
    v653[1] = v760;
    int * v656 = v640->cache_age;
    v656[v757] = 0;
    v741 = v757;
  } else {
    int * v659 = v640->cache_age;
    int v660 = v659[0];
    int * v661 = v640->cache_tags;
    int v662 = v661[0];
    int v663 = v659[1];
    int v664 = v661[1];
    bool v764 = !(((~(((v646 ^ 6) | (-(v646 ^ 6))) >> 31)) | (~(((v647 ^ 6) | (-(v647 ^ 6))) >> 31))) == 0);
    int v718;
    if (v764) {
      int * v665 = v640->cache_age;
      int v766 = 8 + ((~(((v647 ^ 6) | (-(v647 ^ 6))) >> 31)) & 1);
      int v666 = v665[v766];
      int v667 = v665[8];
      int v767 = v667 + ((int)((unsigned int)(v667 - v666) >> 31));
      v665[8] = v767;
      int * v669 = v640->cache_age;
      int v670 = v669[9];
      int v769 = v670 + ((int)((unsigned int)(v670 - v666) >> 31));
      v669[9] = v769;
      int * v672 = v640->cache_age;
      v672[v766] = 0;
      v718 = v766;
    } else {
      int * v675 = v640->cache_age;
      int v676 = v675[8];
      int * v677 = v640->cache_tags;
      int v678 = v677[8];
      int v679 = v675[9];
      int v680 = v677[9];
      int * v681 = v640->cache_dirty;
      int v774 = 8 + ((((v676 + ((~(((v678 ^ -1) | (-(v678 ^ -1))) >> 31)) & 2)) - (v679 + ((~(((v680 ^ -1) | (-(v680 ^ -1))) >> 31)) & 2))) >> 31) & 1);
      int v682 = v681[v774];
      bool v775 = !(v682 == 0);
      if (v775) {
        int * v683 = v640->cache_tags;
        int v684 = v683[v774];
        int * v685 = v640->cache_vals;
        int v778 = (8 + ((((v676 + ((~(((v678 ^ -1) | (-(v678 ^ -1))) >> 31)) & 2)) - (v679 + ((~(((v680 ^ -1) | (-(v680 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
        int v686 = v685[v778];
        int v779 = ((8 + ((((v676 + ((~(((v678 ^ -1) | (-(v678 ^ -1))) >> 31)) & 2)) - (v679 + ((~(((v680 ^ -1) | (-(v680 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
        int v687 = v685[v779];
        int * v688 = v640->mem;
        int v781 = v684 * 2;
        v688[v781] = v686;
        int * v690 = v640->mem;
        int v784 = (v684 * 2) + 1;
        v690[v784] = v687;
        ;
      } else {
        ;
      }
      int * v695 = v640->mem;
      int v696 = v695[12];
      int v697 = v695[13];
      int * v698 = v640->cache_vals;
      int v792 = (8 + ((((v676 + ((~(((v678 ^ -1) | (-(v678 ^ -1))) >> 31)) & 2)) - (v679 + ((~(((v680 ^ -1) | (-(v680 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
      v698[v792] = v696;
      int * v700 = v640->cache_vals;
      int v795 = ((8 + ((((v676 + ((~(((v678 ^ -1) | (-(v678 ^ -1))) >> 31)) & 2)) - (v679 + ((~(((v680 ^ -1) | (-(v680 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
      v700[v795] = v697;
      int * v702 = v640->cache_tags;
      v702[v774] = 6;
      int * v704 = v640->cache_dirty;
      v704[v774] = 0;
      int * v706 = v640->cache_age;
      v706[v774] = 1;
      int * v708 = v640->cache_age;
      int v709 = v708[v774];
      int v710 = v708[8];
      int v802 = v710 + ((int)((unsigned int)(v710 - v709) >> 31));
      v708[8] = v802;
      int * v712 = v640->cache_age;
      int v713 = v712[9];
      int v804 = v713 + ((int)((unsigned int)(v713 - v709) >> 31));
      v712[9] = v804;
      int * v715 = v640->cache_age;
      v715[v774] = 0;
      v718 = v774;
    }
    int * v719 = v640->cache_vals;
    int v807 = v718 * 2;
    int v720 = v719[v807];
    int v808 = (v718 * 2) + 1;
    int v721 = v719[v808];
    int v809 = ((((v660 + ((~(((v662 ^ -1) | (-(v662 ^ -1))) >> 31)) & 2)) - (v663 + ((~(((v664 ^ -1) | (-(v664 ^ -1))) >> 31)) & 2))) >> 31) & 1) * 2;
    v719[v809] = v720;
    int * v723 = v640->cache_vals;
    int v812 = (((((v660 + ((~(((v662 ^ -1) | (-(v662 ^ -1))) >> 31)) & 2)) - (v663 + ((~(((v664 ^ -1) | (-(v664 ^ -1))) >> 31)) & 2))) >> 31) & 1) * 2) + 1;
    v723[v812] = v721;
    int * v725 = v640->cache_tags;
    int v815 = (((v660 + ((~(((v662 ^ -1) | (-(v662 ^ -1))) >> 31)) & 2)) - (v663 + ((~(((v664 ^ -1) | (-(v664 ^ -1))) >> 31)) & 2))) >> 31) & 1;
    v725[v815] = 6;
    int * v727 = v640->cache_dirty;
    v727[v815] = 0;
    int * v729 = v640->cache_age;
    v729[v815] = 1;
    int * v731 = v640->cache_age;
    int v732 = v731[v815];
    int v733 = v731[0];
    int v820 = v733 + ((int)((unsigned int)(v733 - v732) >> 31));
    v731[0] = v820;
    int * v735 = v640->cache_age;
    int v736 = v735[1];
    int v822 = v736 + ((int)((unsigned int)(v736 - v732) >> 31));
    v735[1] = v822;
    int * v738 = v640->cache_age;
    v738[v815] = 0;
    v741 = v815;
  }
  int v825 = (v741 * 2) + 1;
  int v742 = v648[v825];
  int * v743 = v640->reg_ready;
  int v827 = (v641 + 1) + ((100 ^ (((~(((v646 ^ 6) | (-(v646 ^ 6))) >> 31)) | (~(((v647 ^ 6) | (-(v647 ^ 6))) >> 31))) & 104)) ^ (((~(((v644 ^ 6) | (-(v644 ^ 6))) >> 31)) | (~(((v645 ^ 6) | (-(v645 ^ 6))) >> 31))) & (1 ^ (100 ^ (((~(((v646 ^ 6) | (-(v646 ^ 6))) >> 31)) | (~(((v647 ^ 6) | (-(v647 ^ 6))) >> 31))) & 104)))));
  v743[8] = v827;
  int * v745 = v640->regs;
  v745[8] = v742;
  struct StateT * v747 = slot_5(v640);
  return v747;
}

struct StateT * slot_2(struct StateT * v321) {
  int v322 = v321->timer;
  int v330 = v322 + 1;
  v321->timer = v330;
  int * v324 = v321->reg_ready;
  v324[7] = v330;
  int * v326 = v321->regs;
  v326[7] = 28;
  struct StateT * v328 = slot_3(v321);
  return v328;
}

struct StateT * slot_7(struct StateT * v1065) {
  int v1066 = v1065->timer;
  int v1177 = v1066 + 1;
  v1065->timer = v1177;
  int * v1068 = v1065->reg_ready;
  int v1069 = v1068[11];
  int * v1070 = v1065->regs;
  int v1071 = v1070[11];
  int * v1072 = v1065->cache_tags;
  int v1182 = (((int)((unsigned int)((int)((unsigned int)v1071 >> 2)) >> 1)) & 1) * 2;
  int v1073 = v1072[v1182];
  int v1183 = ((((int)((unsigned int)((int)((unsigned int)v1071 >> 2)) >> 1)) & 1) * 2) + 1;
  int v1074 = v1072[v1183];
  int v1184 = 4 + ((((int)((unsigned int)((int)((unsigned int)v1071 >> 2)) >> 1)) & 3) * 2);
  int v1075 = v1072[v1184];
  int v1185 = (4 + ((((int)((unsigned int)((int)((unsigned int)v1071 >> 2)) >> 1)) & 3) * 2)) + 1;
  int v1076 = v1072[v1185];
  int * v1077 = v1065->cache_vals;
  bool v1186 = !(((~(((v1073 ^ ((int)((unsigned int)((int)((unsigned int)v1071 >> 2)) >> 1))) | (-(v1073 ^ ((int)((unsigned int)((int)((unsigned int)v1071 >> 2)) >> 1))))) >> 31)) | (~(((v1074 ^ ((int)((unsigned int)((int)((unsigned int)v1071 >> 2)) >> 1))) | (-(v1074 ^ ((int)((unsigned int)((int)((unsigned int)v1071 >> 2)) >> 1))))) >> 31))) == 0);
  int v1170;
  if (v1186) {
    int * v1078 = v1065->cache_age;
    int v1188 = ((((int)((unsigned int)((int)((unsigned int)v1071 >> 2)) >> 1)) & 1) * 2) + ((~(((v1074 ^ ((int)((unsigned int)((int)((unsigned int)v1071 >> 2)) >> 1))) | (-(v1074 ^ ((int)((unsigned int)((int)((unsigned int)v1071 >> 2)) >> 1))))) >> 31)) & 1);
    int v1079 = v1078[v1188];
    int v1080 = v1078[v1182];
    int v1189 = v1080 + ((int)((unsigned int)(v1080 - v1079) >> 31));
    v1078[v1182] = v1189;
    int * v1082 = v1065->cache_age;
    int v1083 = v1082[v1183];
    int v1191 = v1083 + ((int)((unsigned int)(v1083 - v1079) >> 31));
    v1082[v1183] = v1191;
    int * v1085 = v1065->cache_age;
    v1085[v1188] = 0;
    v1170 = v1188;
  } else {
    int * v1088 = v1065->cache_age;
    int v1195 = (((int)((unsigned int)((int)((unsigned int)v1071 >> 2)) >> 1)) & 1) * 2;
    int v1089 = v1088[v1195];
    int * v1090 = v1065->cache_tags;
    int v1091 = v1090[v1195];
    int v1092 = v1088[v1183];
    int v1093 = v1090[v1183];
    bool v1197 = !(((~(((v1075 ^ ((int)((unsigned int)((int)((unsigned int)v1071 >> 2)) >> 1))) | (-(v1075 ^ ((int)((unsigned int)((int)((unsigned int)v1071 >> 2)) >> 1))))) >> 31)) | (~(((v1076 ^ ((int)((unsigned int)((int)((unsigned int)v1071 >> 2)) >> 1))) | (-(v1076 ^ ((int)((unsigned int)((int)((unsigned int)v1071 >> 2)) >> 1))))) >> 31))) == 0);
    int v1147;
    if (v1197) {
      int * v1094 = v1065->cache_age;
      int v1199 = (4 + ((((int)((unsigned int)((int)((unsigned int)v1071 >> 2)) >> 1)) & 3) * 2)) + ((~(((v1076 ^ ((int)((unsigned int)((int)((unsigned int)v1071 >> 2)) >> 1))) | (-(v1076 ^ ((int)((unsigned int)((int)((unsigned int)v1071 >> 2)) >> 1))))) >> 31)) & 1);
      int v1095 = v1094[v1199];
      int v1096 = v1094[v1184];
      int v1200 = v1096 + ((int)((unsigned int)(v1096 - v1095) >> 31));
      v1094[v1184] = v1200;
      int * v1098 = v1065->cache_age;
      int v1099 = v1098[v1185];
      int v1202 = v1099 + ((int)((unsigned int)(v1099 - v1095) >> 31));
      v1098[v1185] = v1202;
      int * v1101 = v1065->cache_age;
      v1101[v1199] = 0;
      v1147 = v1199;
    } else {
      int * v1104 = v1065->cache_age;
      int v1206 = 4 + ((((int)((unsigned int)((int)((unsigned int)v1071 >> 2)) >> 1)) & 3) * 2);
      int v1105 = v1104[v1206];
      int * v1106 = v1065->cache_tags;
      int v1107 = v1106[v1206];
      int v1108 = v1104[v1185];
      int v1109 = v1106[v1185];
      int * v1110 = v1065->cache_dirty;
      int v1209 = (4 + ((((int)((unsigned int)((int)((unsigned int)v1071 >> 2)) >> 1)) & 3) * 2)) + ((((v1105 + ((~(((v1107 ^ -1) | (-(v1107 ^ -1))) >> 31)) & 2)) - (v1108 + ((~(((v1109 ^ -1) | (-(v1109 ^ -1))) >> 31)) & 2))) >> 31) & 1);
      int v1111 = v1110[v1209];
      bool v1210 = !(v1111 == 0);
      if (v1210) {
        int * v1112 = v1065->cache_tags;
        int v1113 = v1112[v1209];
        int * v1114 = v1065->cache_vals;
        int v1213 = ((4 + ((((int)((unsigned int)((int)((unsigned int)v1071 >> 2)) >> 1)) & 3) * 2)) + ((((v1105 + ((~(((v1107 ^ -1) | (-(v1107 ^ -1))) >> 31)) & 2)) - (v1108 + ((~(((v1109 ^ -1) | (-(v1109 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
        int v1115 = v1114[v1213];
        int v1214 = (((4 + ((((int)((unsigned int)((int)((unsigned int)v1071 >> 2)) >> 1)) & 3) * 2)) + ((((v1105 + ((~(((v1107 ^ -1) | (-(v1107 ^ -1))) >> 31)) & 2)) - (v1108 + ((~(((v1109 ^ -1) | (-(v1109 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
        int v1116 = v1114[v1214];
        int * v1117 = v1065->mem;
        int v1216 = v1113 * 2;
        v1117[v1216] = v1115;
        int * v1119 = v1065->mem;
        int v1219 = (v1113 * 2) + 1;
        v1119[v1219] = v1116;
        ;
      } else {
        ;
      }
      int * v1124 = v1065->mem;
      int v1224 = ((int)((unsigned int)((int)((unsigned int)v1071 >> 2)) >> 1)) * 2;
      int v1125 = v1124[v1224];
      int v1225 = (((int)((unsigned int)((int)((unsigned int)v1071 >> 2)) >> 1)) * 2) + 1;
      int v1126 = v1124[v1225];
      int * v1127 = v1065->cache_vals;
      int v1227 = ((4 + ((((int)((unsigned int)((int)((unsigned int)v1071 >> 2)) >> 1)) & 3) * 2)) + ((((v1105 + ((~(((v1107 ^ -1) | (-(v1107 ^ -1))) >> 31)) & 2)) - (v1108 + ((~(((v1109 ^ -1) | (-(v1109 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
      v1127[v1227] = v1125;
      int * v1129 = v1065->cache_vals;
      int v1230 = (((4 + ((((int)((unsigned int)((int)((unsigned int)v1071 >> 2)) >> 1)) & 3) * 2)) + ((((v1105 + ((~(((v1107 ^ -1) | (-(v1107 ^ -1))) >> 31)) & 2)) - (v1108 + ((~(((v1109 ^ -1) | (-(v1109 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
      v1129[v1230] = v1126;
      int * v1131 = v1065->cache_tags;
      int v1233 = (int)((unsigned int)((int)((unsigned int)v1071 >> 2)) >> 1);
      v1131[v1209] = v1233;
      int * v1133 = v1065->cache_dirty;
      v1133[v1209] = 0;
      int * v1135 = v1065->cache_age;
      v1135[v1209] = 1;
      int * v1137 = v1065->cache_age;
      int v1138 = v1137[v1209];
      int v1139 = v1137[v1184];
      int v1239 = v1139 + ((int)((unsigned int)(v1139 - v1138) >> 31));
      v1137[v1184] = v1239;
      int * v1141 = v1065->cache_age;
      int v1142 = v1141[v1185];
      int v1241 = v1142 + ((int)((unsigned int)(v1142 - v1138) >> 31));
      v1141[v1185] = v1241;
      int * v1144 = v1065->cache_age;
      v1144[v1209] = 0;
      v1147 = v1209;
    }
    int * v1148 = v1065->cache_vals;
    int v1244 = v1147 * 2;
    int v1149 = v1148[v1244];
    int v1245 = (v1147 * 2) + 1;
    int v1150 = v1148[v1245];
    int v1246 = (((((int)((unsigned int)((int)((unsigned int)v1071 >> 2)) >> 1)) & 1) * 2) + ((((v1089 + ((~(((v1091 ^ -1) | (-(v1091 ^ -1))) >> 31)) & 2)) - (v1092 + ((~(((v1093 ^ -1) | (-(v1093 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
    v1148[v1246] = v1149;
    int * v1152 = v1065->cache_vals;
    int v1249 = ((((((int)((unsigned int)((int)((unsigned int)v1071 >> 2)) >> 1)) & 1) * 2) + ((((v1089 + ((~(((v1091 ^ -1) | (-(v1091 ^ -1))) >> 31)) & 2)) - (v1092 + ((~(((v1093 ^ -1) | (-(v1093 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
    v1152[v1249] = v1150;
    int * v1154 = v1065->cache_tags;
    int v1252 = ((((int)((unsigned int)((int)((unsigned int)v1071 >> 2)) >> 1)) & 1) * 2) + ((((v1089 + ((~(((v1091 ^ -1) | (-(v1091 ^ -1))) >> 31)) & 2)) - (v1092 + ((~(((v1093 ^ -1) | (-(v1093 ^ -1))) >> 31)) & 2))) >> 31) & 1);
    int v1253 = (int)((unsigned int)((int)((unsigned int)v1071 >> 2)) >> 1);
    v1154[v1252] = v1253;
    int * v1156 = v1065->cache_dirty;
    v1156[v1252] = 0;
    int * v1158 = v1065->cache_age;
    v1158[v1252] = 1;
    int * v1160 = v1065->cache_age;
    int v1161 = v1160[v1252];
    int v1162 = v1160[v1182];
    int v1259 = v1162 + ((int)((unsigned int)(v1162 - v1161) >> 31));
    v1160[v1182] = v1259;
    int * v1164 = v1065->cache_age;
    int v1165 = v1164[v1183];
    int v1261 = v1165 + ((int)((unsigned int)(v1165 - v1161) >> 31));
    v1164[v1183] = v1261;
    int * v1167 = v1065->cache_age;
    v1167[v1252] = 0;
    v1170 = v1252;
  }
  int v1264 = (v1170 * 2) + (((int)((unsigned int)v1071 >> 2)) & 1);
  int v1171 = v1077[v1264];
  int * v1172 = v1065->reg_ready;
  int v1267 = ((v1069 + ((v1066 - v1069) & (~((v1066 - v1069) >> 31)))) + 1) + ((100 ^ (((~(((v1075 ^ ((int)((unsigned int)((int)((unsigned int)v1071 >> 2)) >> 1))) | (-(v1075 ^ ((int)((unsigned int)((int)((unsigned int)v1071 >> 2)) >> 1))))) >> 31)) | (~(((v1076 ^ ((int)((unsigned int)((int)((unsigned int)v1071 >> 2)) >> 1))) | (-(v1076 ^ ((int)((unsigned int)((int)((unsigned int)v1071 >> 2)) >> 1))))) >> 31))) & 104)) ^ (((~(((v1073 ^ ((int)((unsigned int)((int)((unsigned int)v1071 >> 2)) >> 1))) | (-(v1073 ^ ((int)((unsigned int)((int)((unsigned int)v1071 >> 2)) >> 1))))) >> 31)) | (~(((v1074 ^ ((int)((unsigned int)((int)((unsigned int)v1071 >> 2)) >> 1))) | (-(v1074 ^ ((int)((unsigned int)((int)((unsigned int)v1071 >> 2)) >> 1))))) >> 31))) & (1 ^ (100 ^ (((~(((v1075 ^ ((int)((unsigned int)((int)((unsigned int)v1071 >> 2)) >> 1))) | (-(v1075 ^ ((int)((unsigned int)((int)((unsigned int)v1071 >> 2)) >> 1))))) >> 31)) | (~(((v1076 ^ ((int)((unsigned int)((int)((unsigned int)v1071 >> 2)) >> 1))) | (-(v1076 ^ ((int)((unsigned int)((int)((unsigned int)v1071 >> 2)) >> 1))))) >> 31))) & 104)))));
  v1172[12] = v1267;
  int * v1174 = v1065->regs;
  v1174[12] = v1171;
  return v1065;
}

struct StateT * slot_3(struct StateT * v337) {
  int v338 = v337->timer;
  int v509 = v338 + 1;
  v337->timer = v509;
  int * v340 = v337->reg_ready;
  int * v342 = v337->regs;
  int v343 = v342[7];
  int * v344 = v337->cache_tags;
  int v345 = v344[0];
  int v346 = v344[1];
  int v347 = v344[8];
  int v348 = v344[9];
  int v349 = v337->timer;
  int v518 = v349 + ((100 ^ (((~(((v347 ^ 6) | (-(v347 ^ 6))) >> 31)) | (~(((v348 ^ 6) | (-(v348 ^ 6))) >> 31))) & 104)) ^ (((~(((v345 ^ 6) | (-(v345 ^ 6))) >> 31)) | (~(((v346 ^ 6) | (-(v346 ^ 6))) >> 31))) & (1 ^ (100 ^ (((~(((v347 ^ 6) | (-(v347 ^ 6))) >> 31)) | (~(((v348 ^ 6) | (-(v348 ^ 6))) >> 31))) & 104)))));
  v337->timer = v518;
  bool v519 = !(((~(((v345 ^ 6) | (-(v345 ^ 6))) >> 31)) | (~(((v346 ^ 6) | (-(v346 ^ 6))) >> 31))) == 0);
  int v443;
  if (v519) {
    int * v351 = v337->cache_age;
    int v521 = (~(((v346 ^ 6) | (-(v346 ^ 6))) >> 31)) & 1;
    int v352 = v351[v521];
    int v353 = v351[0];
    int v522 = v353 + ((int)((unsigned int)(v353 - v352) >> 31));
    v351[0] = v522;
    int * v355 = v337->cache_age;
    int v356 = v355[1];
    int v524 = v356 + ((int)((unsigned int)(v356 - v352) >> 31));
    v355[1] = v524;
    int * v358 = v337->cache_age;
    v358[v521] = 0;
    v443 = v521;
  } else {
    int * v361 = v337->cache_age;
    int v362 = v361[0];
    int * v363 = v337->cache_tags;
    int v364 = v363[0];
    int v365 = v361[1];
    int v366 = v363[1];
    bool v528 = !(((~(((v347 ^ 6) | (-(v347 ^ 6))) >> 31)) | (~(((v348 ^ 6) | (-(v348 ^ 6))) >> 31))) == 0);
    int v420;
    if (v528) {
      int * v367 = v337->cache_age;
      int v530 = 8 + ((~(((v348 ^ 6) | (-(v348 ^ 6))) >> 31)) & 1);
      int v368 = v367[v530];
      int v369 = v367[8];
      int v531 = v369 + ((int)((unsigned int)(v369 - v368) >> 31));
      v367[8] = v531;
      int * v371 = v337->cache_age;
      int v372 = v371[9];
      int v533 = v372 + ((int)((unsigned int)(v372 - v368) >> 31));
      v371[9] = v533;
      int * v374 = v337->cache_age;
      v374[v530] = 0;
      v420 = v530;
    } else {
      int * v377 = v337->cache_age;
      int v378 = v377[8];
      int * v379 = v337->cache_tags;
      int v380 = v379[8];
      int v381 = v377[9];
      int v382 = v379[9];
      int * v383 = v337->cache_dirty;
      int v538 = 8 + ((((v378 + ((~(((v380 ^ -1) | (-(v380 ^ -1))) >> 31)) & 2)) - (v381 + ((~(((v382 ^ -1) | (-(v382 ^ -1))) >> 31)) & 2))) >> 31) & 1);
      int v384 = v383[v538];
      bool v539 = !(v384 == 0);
      if (v539) {
        int * v385 = v337->cache_tags;
        int v386 = v385[v538];
        int * v387 = v337->cache_vals;
        int v542 = (8 + ((((v378 + ((~(((v380 ^ -1) | (-(v380 ^ -1))) >> 31)) & 2)) - (v381 + ((~(((v382 ^ -1) | (-(v382 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
        int v388 = v387[v542];
        int v543 = ((8 + ((((v378 + ((~(((v380 ^ -1) | (-(v380 ^ -1))) >> 31)) & 2)) - (v381 + ((~(((v382 ^ -1) | (-(v382 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
        int v389 = v387[v543];
        int * v390 = v337->mem;
        int v545 = v386 * 2;
        v390[v545] = v388;
        int * v392 = v337->mem;
        int v548 = (v386 * 2) + 1;
        v392[v548] = v389;
        ;
      } else {
        ;
      }
      int * v397 = v337->mem;
      int v398 = v397[12];
      int v399 = v397[13];
      int * v400 = v337->cache_vals;
      int v556 = (8 + ((((v378 + ((~(((v380 ^ -1) | (-(v380 ^ -1))) >> 31)) & 2)) - (v381 + ((~(((v382 ^ -1) | (-(v382 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
      v400[v556] = v398;
      int * v402 = v337->cache_vals;
      int v559 = ((8 + ((((v378 + ((~(((v380 ^ -1) | (-(v380 ^ -1))) >> 31)) & 2)) - (v381 + ((~(((v382 ^ -1) | (-(v382 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
      v402[v559] = v399;
      int * v404 = v337->cache_tags;
      v404[v538] = 6;
      int * v406 = v337->cache_dirty;
      v406[v538] = 0;
      int * v408 = v337->cache_age;
      v408[v538] = 1;
      int * v410 = v337->cache_age;
      int v411 = v410[v538];
      int v412 = v410[8];
      int v566 = v412 + ((int)((unsigned int)(v412 - v411) >> 31));
      v410[8] = v566;
      int * v414 = v337->cache_age;
      int v415 = v414[9];
      int v568 = v415 + ((int)((unsigned int)(v415 - v411) >> 31));
      v414[9] = v568;
      int * v417 = v337->cache_age;
      v417[v538] = 0;
      v420 = v538;
    }
    int * v421 = v337->cache_vals;
    int v571 = v420 * 2;
    int v422 = v421[v571];
    int v572 = (v420 * 2) + 1;
    int v423 = v421[v572];
    int v573 = ((((v362 + ((~(((v364 ^ -1) | (-(v364 ^ -1))) >> 31)) & 2)) - (v365 + ((~(((v366 ^ -1) | (-(v366 ^ -1))) >> 31)) & 2))) >> 31) & 1) * 2;
    v421[v573] = v422;
    int * v425 = v337->cache_vals;
    int v576 = (((((v362 + ((~(((v364 ^ -1) | (-(v364 ^ -1))) >> 31)) & 2)) - (v365 + ((~(((v366 ^ -1) | (-(v366 ^ -1))) >> 31)) & 2))) >> 31) & 1) * 2) + 1;
    v425[v576] = v423;
    int * v427 = v337->cache_tags;
    int v579 = (((v362 + ((~(((v364 ^ -1) | (-(v364 ^ -1))) >> 31)) & 2)) - (v365 + ((~(((v366 ^ -1) | (-(v366 ^ -1))) >> 31)) & 2))) >> 31) & 1;
    v427[v579] = 6;
    int * v429 = v337->cache_dirty;
    v429[v579] = 0;
    int * v431 = v337->cache_age;
    v431[v579] = 1;
    int * v433 = v337->cache_age;
    int v434 = v433[v579];
    int v435 = v433[0];
    int v584 = v435 + ((int)((unsigned int)(v435 - v434) >> 31));
    v433[0] = v584;
    int * v437 = v337->cache_age;
    int v438 = v437[1];
    int v586 = v438 + ((int)((unsigned int)(v438 - v434) >> 31));
    v437[1] = v586;
    int * v440 = v337->cache_age;
    v440[v579] = 0;
    v443 = v579;
  }
  int * v444 = v337->cache_vals;
  int v589 = (v443 * 2) + 1;
  v444[v589] = v343;
  int * v446 = v337->cache_tags;
  int v447 = v446[8];
  int v448 = v446[9];
  bool v592 = !(((~(((v447 ^ 6) | (-(v447 ^ 6))) >> 31)) | (~(((v448 ^ 6) | (-(v448 ^ 6))) >> 31))) == 0);
  int v502;
  if (v592) {
    int * v449 = v337->cache_age;
    int v594 = 8 + ((~(((v448 ^ 6) | (-(v448 ^ 6))) >> 31)) & 1);
    int v450 = v449[v594];
    int v451 = v449[8];
    int v595 = v451 + ((int)((unsigned int)(v451 - v450) >> 31));
    v449[8] = v595;
    int * v453 = v337->cache_age;
    int v454 = v453[9];
    int v597 = v454 + ((int)((unsigned int)(v454 - v450) >> 31));
    v453[9] = v597;
    int * v456 = v337->cache_age;
    v456[v594] = 0;
    v502 = v594;
  } else {
    int * v459 = v337->cache_age;
    int v460 = v459[8];
    int * v461 = v337->cache_tags;
    int v462 = v461[8];
    int v463 = v459[9];
    int v464 = v461[9];
    int * v465 = v337->cache_dirty;
    int v602 = 8 + ((((v460 + ((~(((v462 ^ -1) | (-(v462 ^ -1))) >> 31)) & 2)) - (v463 + ((~(((v464 ^ -1) | (-(v464 ^ -1))) >> 31)) & 2))) >> 31) & 1);
    int v466 = v465[v602];
    bool v603 = !(v466 == 0);
    if (v603) {
      int * v467 = v337->cache_tags;
      int v468 = v467[v602];
      int * v469 = v337->cache_vals;
      int v606 = (8 + ((((v460 + ((~(((v462 ^ -1) | (-(v462 ^ -1))) >> 31)) & 2)) - (v463 + ((~(((v464 ^ -1) | (-(v464 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
      int v470 = v469[v606];
      int v607 = ((8 + ((((v460 + ((~(((v462 ^ -1) | (-(v462 ^ -1))) >> 31)) & 2)) - (v463 + ((~(((v464 ^ -1) | (-(v464 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
      int v471 = v469[v607];
      int * v472 = v337->mem;
      int v609 = v468 * 2;
      v472[v609] = v470;
      int * v474 = v337->mem;
      int v612 = (v468 * 2) + 1;
      v474[v612] = v471;
      ;
    } else {
      ;
    }
    int * v479 = v337->mem;
    int v480 = v479[12];
    int v481 = v479[13];
    int * v482 = v337->cache_vals;
    int v620 = (8 + ((((v460 + ((~(((v462 ^ -1) | (-(v462 ^ -1))) >> 31)) & 2)) - (v463 + ((~(((v464 ^ -1) | (-(v464 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
    v482[v620] = v480;
    int * v484 = v337->cache_vals;
    int v623 = ((8 + ((((v460 + ((~(((v462 ^ -1) | (-(v462 ^ -1))) >> 31)) & 2)) - (v463 + ((~(((v464 ^ -1) | (-(v464 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
    v484[v623] = v481;
    int * v486 = v337->cache_tags;
    v486[v602] = 6;
    int * v488 = v337->cache_dirty;
    v488[v602] = 0;
    int * v490 = v337->cache_age;
    v490[v602] = 1;
    int * v492 = v337->cache_age;
    int v493 = v492[v602];
    int v494 = v492[8];
    int v630 = v494 + ((int)((unsigned int)(v494 - v493) >> 31));
    v492[8] = v630;
    int * v496 = v337->cache_age;
    int v497 = v496[9];
    int v632 = v497 + ((int)((unsigned int)(v497 - v493) >> 31));
    v496[9] = v632;
    int * v499 = v337->cache_age;
    v499[v602] = 0;
    v502 = v602;
  }
  int * v503 = v337->cache_vals;
  int v635 = (v502 * 2) + 1;
  v503[v635] = v343;
  int * v505 = v337->cache_dirty;
  v505[v502] = 1;
  struct StateT * v507 = slot_4(v337);
  return v507;
}

struct StateT * slot_0(struct StateT * v2) {
  int v3 = v2->timer;
  int v11 = v3 + 1;
  v2->timer = v11;
  int * v5 = v2->reg_ready;
  v5[5] = v11;
  int * v7 = v2->regs;
  v7[5] = -1;
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
  //@ assert untainted_timer: !\tainted(s1_->timer==s2_->timer);
  koika_assert(s1_->timer==s2_->timer, "timing leak");
  return 0;
}