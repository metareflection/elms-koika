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
  int reg_ready[32];
  int cache_tags[12];
  int cache_dirty[12];
  int cache_age[12];
  int cache_vals[24];
  int timer;
};

struct StateT * snippet(struct StateT * v0);
struct StateT * slot_1(struct StateT * v20);
struct StateT * slot_8(struct StateT * v1000);
struct StateT * slot_6(struct StateT * v721);
struct StateT * slot_5(struct StateT * v703);
struct StateT * slot_4(struct StateT * v311);
struct StateT * slot_2(struct StateT * v275);
struct StateT * slot_7(struct StateT * v745);
struct StateT * slot_3(struct StateT * v293);
struct StateT * slot_0(struct StateT * v2);
struct StateT * snippet(struct StateT * v0) {
  struct StateT * v1 = slot_0(v0);
  int v1252 = v1->timer;
  int * v1253 = v1->reg_ready;
  int v1254 = v1253[0];
  int v1385 = v1254 + ((v1252 - v1254) & (~((v1252 - v1254) >> 31)));
  v1->timer = v1385;
  int v1256 = v1->timer;
  int * v1257 = v1->reg_ready;
  int v1258 = v1257[1];
  int v1388 = v1258 + ((v1256 - v1258) & (~((v1256 - v1258) >> 31)));
  v1->timer = v1388;
  int v1260 = v1->timer;
  int * v1261 = v1->reg_ready;
  int v1262 = v1261[2];
  int v1391 = v1262 + ((v1260 - v1262) & (~((v1260 - v1262) >> 31)));
  v1->timer = v1391;
  int v1264 = v1->timer;
  int * v1265 = v1->reg_ready;
  int v1266 = v1265[3];
  int v1394 = v1266 + ((v1264 - v1266) & (~((v1264 - v1266) >> 31)));
  v1->timer = v1394;
  int v1268 = v1->timer;
  int * v1269 = v1->reg_ready;
  int v1270 = v1269[4];
  int v1397 = v1270 + ((v1268 - v1270) & (~((v1268 - v1270) >> 31)));
  v1->timer = v1397;
  int v1272 = v1->timer;
  int * v1273 = v1->reg_ready;
  int v1274 = v1273[5];
  int v1400 = v1274 + ((v1272 - v1274) & (~((v1272 - v1274) >> 31)));
  v1->timer = v1400;
  int v1276 = v1->timer;
  int * v1277 = v1->reg_ready;
  int v1278 = v1277[6];
  int v1403 = v1278 + ((v1276 - v1278) & (~((v1276 - v1278) >> 31)));
  v1->timer = v1403;
  int v1280 = v1->timer;
  int * v1281 = v1->reg_ready;
  int v1282 = v1281[7];
  int v1406 = v1282 + ((v1280 - v1282) & (~((v1280 - v1282) >> 31)));
  v1->timer = v1406;
  int v1284 = v1->timer;
  int * v1285 = v1->reg_ready;
  int v1286 = v1285[8];
  int v1409 = v1286 + ((v1284 - v1286) & (~((v1284 - v1286) >> 31)));
  v1->timer = v1409;
  int v1288 = v1->timer;
  int * v1289 = v1->reg_ready;
  int v1290 = v1289[9];
  int v1412 = v1290 + ((v1288 - v1290) & (~((v1288 - v1290) >> 31)));
  v1->timer = v1412;
  int v1292 = v1->timer;
  int * v1293 = v1->reg_ready;
  int v1294 = v1293[10];
  int v1415 = v1294 + ((v1292 - v1294) & (~((v1292 - v1294) >> 31)));
  v1->timer = v1415;
  int v1296 = v1->timer;
  int * v1297 = v1->reg_ready;
  int v1298 = v1297[11];
  int v1418 = v1298 + ((v1296 - v1298) & (~((v1296 - v1298) >> 31)));
  v1->timer = v1418;
  int v1300 = v1->timer;
  int * v1301 = v1->reg_ready;
  int v1302 = v1301[12];
  int v1421 = v1302 + ((v1300 - v1302) & (~((v1300 - v1302) >> 31)));
  v1->timer = v1421;
  int v1304 = v1->timer;
  int * v1305 = v1->reg_ready;
  int v1306 = v1305[13];
  int v1424 = v1306 + ((v1304 - v1306) & (~((v1304 - v1306) >> 31)));
  v1->timer = v1424;
  int v1308 = v1->timer;
  int * v1309 = v1->reg_ready;
  int v1310 = v1309[14];
  int v1427 = v1310 + ((v1308 - v1310) & (~((v1308 - v1310) >> 31)));
  v1->timer = v1427;
  int v1312 = v1->timer;
  int * v1313 = v1->reg_ready;
  int v1314 = v1313[15];
  int v1430 = v1314 + ((v1312 - v1314) & (~((v1312 - v1314) >> 31)));
  v1->timer = v1430;
  int v1316 = v1->timer;
  int * v1317 = v1->reg_ready;
  int v1318 = v1317[16];
  int v1433 = v1318 + ((v1316 - v1318) & (~((v1316 - v1318) >> 31)));
  v1->timer = v1433;
  int v1320 = v1->timer;
  int * v1321 = v1->reg_ready;
  int v1322 = v1321[17];
  int v1436 = v1322 + ((v1320 - v1322) & (~((v1320 - v1322) >> 31)));
  v1->timer = v1436;
  int v1324 = v1->timer;
  int * v1325 = v1->reg_ready;
  int v1326 = v1325[18];
  int v1439 = v1326 + ((v1324 - v1326) & (~((v1324 - v1326) >> 31)));
  v1->timer = v1439;
  int v1328 = v1->timer;
  int * v1329 = v1->reg_ready;
  int v1330 = v1329[19];
  int v1442 = v1330 + ((v1328 - v1330) & (~((v1328 - v1330) >> 31)));
  v1->timer = v1442;
  int v1332 = v1->timer;
  int * v1333 = v1->reg_ready;
  int v1334 = v1333[20];
  int v1445 = v1334 + ((v1332 - v1334) & (~((v1332 - v1334) >> 31)));
  v1->timer = v1445;
  int v1336 = v1->timer;
  int * v1337 = v1->reg_ready;
  int v1338 = v1337[21];
  int v1448 = v1338 + ((v1336 - v1338) & (~((v1336 - v1338) >> 31)));
  v1->timer = v1448;
  int v1340 = v1->timer;
  int * v1341 = v1->reg_ready;
  int v1342 = v1341[22];
  int v1451 = v1342 + ((v1340 - v1342) & (~((v1340 - v1342) >> 31)));
  v1->timer = v1451;
  int v1344 = v1->timer;
  int * v1345 = v1->reg_ready;
  int v1346 = v1345[23];
  int v1454 = v1346 + ((v1344 - v1346) & (~((v1344 - v1346) >> 31)));
  v1->timer = v1454;
  int v1348 = v1->timer;
  int * v1349 = v1->reg_ready;
  int v1350 = v1349[24];
  int v1457 = v1350 + ((v1348 - v1350) & (~((v1348 - v1350) >> 31)));
  v1->timer = v1457;
  int v1352 = v1->timer;
  int * v1353 = v1->reg_ready;
  int v1354 = v1353[25];
  int v1460 = v1354 + ((v1352 - v1354) & (~((v1352 - v1354) >> 31)));
  v1->timer = v1460;
  int v1356 = v1->timer;
  int * v1357 = v1->reg_ready;
  int v1358 = v1357[26];
  int v1463 = v1358 + ((v1356 - v1358) & (~((v1356 - v1358) >> 31)));
  v1->timer = v1463;
  int v1360 = v1->timer;
  int * v1361 = v1->reg_ready;
  int v1362 = v1361[27];
  int v1466 = v1362 + ((v1360 - v1362) & (~((v1360 - v1362) >> 31)));
  v1->timer = v1466;
  int v1364 = v1->timer;
  int * v1365 = v1->reg_ready;
  int v1366 = v1365[28];
  int v1469 = v1366 + ((v1364 - v1366) & (~((v1364 - v1366) >> 31)));
  v1->timer = v1469;
  int v1368 = v1->timer;
  int * v1369 = v1->reg_ready;
  int v1370 = v1369[29];
  int v1472 = v1370 + ((v1368 - v1370) & (~((v1368 - v1370) >> 31)));
  v1->timer = v1472;
  int v1372 = v1->timer;
  int * v1373 = v1->reg_ready;
  int v1374 = v1373[30];
  int v1475 = v1374 + ((v1372 - v1374) & (~((v1372 - v1374) >> 31)));
  v1->timer = v1475;
  int v1376 = v1->timer;
  int * v1377 = v1->reg_ready;
  int v1378 = v1377[31];
  int v1478 = v1378 + ((v1376 - v1378) & (~((v1376 - v1378) >> 31)));
  v1->timer = v1478;
  return v1;
}

struct StateT * slot_1(struct StateT * v20) {
  int v21 = v20->timer;
  int v22 = v20->timer;
  int v157 = v22 + 1;
  v20->timer = v157;
  int * v24 = v20->reg_ready;
  int v25 = v24[6];
  int * v26 = v20->regs;
  int v27 = v26[6];
  int * v28 = v20->cache_tags;
  int v162 = (((int)((unsigned int)((int)((unsigned int)v27 >> 2)) >> 1)) & 1) * 2;
  int v29 = v28[v162];
  int * v30 = v20->cache_tags;
  int v164 = ((((int)((unsigned int)((int)((unsigned int)v27 >> 2)) >> 1)) & 1) * 2) + 1;
  int v31 = v30[v164];
  int * v32 = v20->cache_tags;
  int v166 = 4 + ((((int)((unsigned int)((int)((unsigned int)v27 >> 2)) >> 1)) & 3) * 2);
  int v33 = v32[v166];
  int * v34 = v20->cache_tags;
  int v168 = (4 + ((((int)((unsigned int)((int)((unsigned int)v27 >> 2)) >> 1)) & 3) * 2)) + 1;
  int v35 = v34[v168];
  int * v36 = v20->cache_vals;
  bool v169 = !(((~(((v29 ^ ((int)((unsigned int)((int)((unsigned int)v27 >> 2)) >> 1))) | (-(v29 ^ ((int)((unsigned int)((int)((unsigned int)v27 >> 2)) >> 1))))) >> 31)) | (~(((v31 ^ ((int)((unsigned int)((int)((unsigned int)v27 >> 2)) >> 1))) | (-(v31 ^ ((int)((unsigned int)((int)((unsigned int)v27 >> 2)) >> 1))))) >> 31))) == 0);
  int v149;
  if (v169) {
    int * v37 = v20->cache_age;
    int v171 = ((((int)((unsigned int)((int)((unsigned int)v27 >> 2)) >> 1)) & 1) * 2) + ((~(((v31 ^ ((int)((unsigned int)((int)((unsigned int)v27 >> 2)) >> 1))) | (-(v31 ^ ((int)((unsigned int)((int)((unsigned int)v27 >> 2)) >> 1))))) >> 31)) & 1);
    int v38 = v37[v171];
    int * v39 = v20->cache_age;
    int v40 = v39[v162];
    int * v41 = v20->cache_age;
    int v174 = v40 + ((int)((unsigned int)(v40 - v38) >> 31));
    v41[v162] = v174;
    int * v43 = v20->cache_age;
    int v44 = v43[v164];
    int * v45 = v20->cache_age;
    int v177 = v44 + ((int)((unsigned int)(v44 - v38) >> 31));
    v45[v164] = v177;
    int * v47 = v20->cache_age;
    v47[v171] = 0;
    v149 = v171;
  } else {
    int * v50 = v20->cache_age;
    int v181 = (((int)((unsigned int)((int)((unsigned int)v27 >> 2)) >> 1)) & 1) * 2;
    int v51 = v50[v181];
    int * v52 = v20->cache_tags;
    int v53 = v52[v181];
    int * v54 = v20->cache_age;
    int v55 = v54[v164];
    int * v56 = v20->cache_tags;
    int v57 = v56[v164];
    bool v185 = !(((~(((v33 ^ ((int)((unsigned int)((int)((unsigned int)v27 >> 2)) >> 1))) | (-(v33 ^ ((int)((unsigned int)((int)((unsigned int)v27 >> 2)) >> 1))))) >> 31)) | (~(((v35 ^ ((int)((unsigned int)((int)((unsigned int)v27 >> 2)) >> 1))) | (-(v35 ^ ((int)((unsigned int)((int)((unsigned int)v27 >> 2)) >> 1))))) >> 31))) == 0);
    int v121;
    if (v185) {
      int * v58 = v20->cache_age;
      int v187 = (4 + ((((int)((unsigned int)((int)((unsigned int)v27 >> 2)) >> 1)) & 3) * 2)) + ((~(((v35 ^ ((int)((unsigned int)((int)((unsigned int)v27 >> 2)) >> 1))) | (-(v35 ^ ((int)((unsigned int)((int)((unsigned int)v27 >> 2)) >> 1))))) >> 31)) & 1);
      int v59 = v58[v187];
      int * v60 = v20->cache_age;
      int v61 = v60[v166];
      int * v62 = v20->cache_age;
      int v190 = v61 + ((int)((unsigned int)(v61 - v59) >> 31));
      v62[v166] = v190;
      int * v64 = v20->cache_age;
      int v65 = v64[v168];
      int * v66 = v20->cache_age;
      int v193 = v65 + ((int)((unsigned int)(v65 - v59) >> 31));
      v66[v168] = v193;
      int * v68 = v20->cache_age;
      v68[v187] = 0;
      v121 = v187;
    } else {
      int * v71 = v20->cache_age;
      int v197 = 4 + ((((int)((unsigned int)((int)((unsigned int)v27 >> 2)) >> 1)) & 3) * 2);
      int v72 = v71[v197];
      int * v73 = v20->cache_tags;
      int v74 = v73[v197];
      int * v75 = v20->cache_age;
      int v76 = v75[v168];
      int * v77 = v20->cache_tags;
      int v78 = v77[v168];
      int * v79 = v20->cache_dirty;
      int v202 = (4 + ((((int)((unsigned int)((int)((unsigned int)v27 >> 2)) >> 1)) & 3) * 2)) + ((((v72 + ((~(((v74 ^ -1) | (-(v74 ^ -1))) >> 31)) & 2)) - (v76 + ((~(((v78 ^ -1) | (-(v78 ^ -1))) >> 31)) & 2))) >> 31) & 1);
      int v80 = v79[v202];
      bool v203 = !(v80 == 0);
      if (v203) {
        int * v81 = v20->cache_tags;
        int v82 = v81[v202];
        int * v83 = v20->cache_vals;
        int v206 = ((4 + ((((int)((unsigned int)((int)((unsigned int)v27 >> 2)) >> 1)) & 3) * 2)) + ((((v72 + ((~(((v74 ^ -1) | (-(v74 ^ -1))) >> 31)) & 2)) - (v76 + ((~(((v78 ^ -1) | (-(v78 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
        int v84 = v83[v206];
        int * v85 = v20->cache_vals;
        int v208 = (((4 + ((((int)((unsigned int)((int)((unsigned int)v27 >> 2)) >> 1)) & 3) * 2)) + ((((v72 + ((~(((v74 ^ -1) | (-(v74 ^ -1))) >> 31)) & 2)) - (v76 + ((~(((v78 ^ -1) | (-(v78 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
        int v86 = v85[v208];
        int * v87 = v20->mem;
        int v210 = v82 * 2;
        v87[v210] = v84;
        int * v89 = v20->mem;
        int v213 = (v82 * 2) + 1;
        v89[v213] = v86;
        ;
      } else {
        ;
      }
      int * v94 = v20->mem;
      int v218 = ((int)((unsigned int)((int)((unsigned int)v27 >> 2)) >> 1)) * 2;
      int v95 = v94[v218];
      int * v96 = v20->mem;
      int v220 = (((int)((unsigned int)((int)((unsigned int)v27 >> 2)) >> 1)) * 2) + 1;
      int v97 = v96[v220];
      int * v98 = v20->cache_vals;
      int v222 = ((4 + ((((int)((unsigned int)((int)((unsigned int)v27 >> 2)) >> 1)) & 3) * 2)) + ((((v72 + ((~(((v74 ^ -1) | (-(v74 ^ -1))) >> 31)) & 2)) - (v76 + ((~(((v78 ^ -1) | (-(v78 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
      v98[v222] = v95;
      int * v100 = v20->cache_vals;
      int v225 = (((4 + ((((int)((unsigned int)((int)((unsigned int)v27 >> 2)) >> 1)) & 3) * 2)) + ((((v72 + ((~(((v74 ^ -1) | (-(v74 ^ -1))) >> 31)) & 2)) - (v76 + ((~(((v78 ^ -1) | (-(v78 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
      v100[v225] = v97;
      int * v102 = v20->cache_tags;
      int v228 = (int)((unsigned int)((int)((unsigned int)v27 >> 2)) >> 1);
      v102[v202] = v228;
      int * v104 = v20->cache_dirty;
      v104[v202] = 0;
      int * v106 = v20->cache_age;
      v106[v202] = 1;
      int * v108 = v20->cache_age;
      int v109 = v108[v202];
      int * v110 = v20->cache_age;
      int v111 = v110[v166];
      int * v112 = v20->cache_age;
      int v236 = v111 + ((int)((unsigned int)(v111 - v109) >> 31));
      v112[v166] = v236;
      int * v114 = v20->cache_age;
      int v115 = v114[v168];
      int * v116 = v20->cache_age;
      int v239 = v115 + ((int)((unsigned int)(v115 - v109) >> 31));
      v116[v168] = v239;
      int * v118 = v20->cache_age;
      v118[v202] = 0;
      v121 = v202;
    }
    int * v122 = v20->cache_vals;
    int v242 = v121 * 2;
    int v123 = v122[v242];
    int * v124 = v20->cache_vals;
    int v244 = (v121 * 2) + 1;
    int v125 = v124[v244];
    int * v126 = v20->cache_vals;
    int v246 = (((((int)((unsigned int)((int)((unsigned int)v27 >> 2)) >> 1)) & 1) * 2) + ((((v51 + ((~(((v53 ^ -1) | (-(v53 ^ -1))) >> 31)) & 2)) - (v55 + ((~(((v57 ^ -1) | (-(v57 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
    v126[v246] = v123;
    int * v128 = v20->cache_vals;
    int v249 = ((((((int)((unsigned int)((int)((unsigned int)v27 >> 2)) >> 1)) & 1) * 2) + ((((v51 + ((~(((v53 ^ -1) | (-(v53 ^ -1))) >> 31)) & 2)) - (v55 + ((~(((v57 ^ -1) | (-(v57 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
    v128[v249] = v125;
    int * v130 = v20->cache_tags;
    int v252 = ((((int)((unsigned int)((int)((unsigned int)v27 >> 2)) >> 1)) & 1) * 2) + ((((v51 + ((~(((v53 ^ -1) | (-(v53 ^ -1))) >> 31)) & 2)) - (v55 + ((~(((v57 ^ -1) | (-(v57 ^ -1))) >> 31)) & 2))) >> 31) & 1);
    int v253 = (int)((unsigned int)((int)((unsigned int)v27 >> 2)) >> 1);
    v130[v252] = v253;
    int * v132 = v20->cache_dirty;
    v132[v252] = 0;
    int * v134 = v20->cache_age;
    v134[v252] = 1;
    int * v136 = v20->cache_age;
    int v137 = v136[v252];
    int * v138 = v20->cache_age;
    int v139 = v138[v162];
    int * v140 = v20->cache_age;
    int v261 = v139 + ((int)((unsigned int)(v139 - v137) >> 31));
    v140[v162] = v261;
    int * v142 = v20->cache_age;
    int v143 = v142[v164];
    int * v144 = v20->cache_age;
    int v264 = v143 + ((int)((unsigned int)(v143 - v137) >> 31));
    v144[v164] = v264;
    int * v146 = v20->cache_age;
    v146[v252] = 0;
    v149 = v252;
  }
  int v267 = (v149 * 2) + (((int)((unsigned int)v27 >> 2)) & 1);
  int v150 = v36[v267];
  int * v151 = v20->reg_ready;
  int v270 = ((v25 + ((v21 - v25) & (~((v21 - v25) >> 31)))) + 1) + ((100 ^ (((~(((v33 ^ ((int)((unsigned int)((int)((unsigned int)v27 >> 2)) >> 1))) | (-(v33 ^ ((int)((unsigned int)((int)((unsigned int)v27 >> 2)) >> 1))))) >> 31)) | (~(((v35 ^ ((int)((unsigned int)((int)((unsigned int)v27 >> 2)) >> 1))) | (-(v35 ^ ((int)((unsigned int)((int)((unsigned int)v27 >> 2)) >> 1))))) >> 31))) & 104)) ^ (((~(((v29 ^ ((int)((unsigned int)((int)((unsigned int)v27 >> 2)) >> 1))) | (-(v29 ^ ((int)((unsigned int)((int)((unsigned int)v27 >> 2)) >> 1))))) >> 31)) | (~(((v31 ^ ((int)((unsigned int)((int)((unsigned int)v27 >> 2)) >> 1))) | (-(v31 ^ ((int)((unsigned int)((int)((unsigned int)v27 >> 2)) >> 1))))) >> 31))) & (1 ^ (100 ^ (((~(((v33 ^ ((int)((unsigned int)((int)((unsigned int)v27 >> 2)) >> 1))) | (-(v33 ^ ((int)((unsigned int)((int)((unsigned int)v27 >> 2)) >> 1))))) >> 31)) | (~(((v35 ^ ((int)((unsigned int)((int)((unsigned int)v27 >> 2)) >> 1))) | (-(v35 ^ ((int)((unsigned int)((int)((unsigned int)v27 >> 2)) >> 1))))) >> 31))) & 104)))));
  v151[5] = v270;
  int * v153 = v20->regs;
  v153[5] = v150;
  struct StateT * v155 = slot_2(v20);
  return v155;
}

struct StateT * slot_8(struct StateT * v1000) {
  int v1001 = v1000->timer;
  int v1002 = v1000->timer;
  int v1136 = v1002 + 1;
  v1000->timer = v1136;
  int * v1004 = v1000->reg_ready;
  int v1005 = v1004[11];
  int * v1006 = v1000->regs;
  int v1007 = v1006[11];
  int * v1008 = v1000->cache_tags;
  int v1141 = (((int)((unsigned int)((int)((unsigned int)v1007 >> 2)) >> 1)) & 1) * 2;
  int v1009 = v1008[v1141];
  int * v1010 = v1000->cache_tags;
  int v1143 = ((((int)((unsigned int)((int)((unsigned int)v1007 >> 2)) >> 1)) & 1) * 2) + 1;
  int v1011 = v1010[v1143];
  int * v1012 = v1000->cache_tags;
  int v1145 = 4 + ((((int)((unsigned int)((int)((unsigned int)v1007 >> 2)) >> 1)) & 3) * 2);
  int v1013 = v1012[v1145];
  int * v1014 = v1000->cache_tags;
  int v1147 = (4 + ((((int)((unsigned int)((int)((unsigned int)v1007 >> 2)) >> 1)) & 3) * 2)) + 1;
  int v1015 = v1014[v1147];
  int * v1016 = v1000->cache_vals;
  bool v1148 = !(((~(((v1009 ^ ((int)((unsigned int)((int)((unsigned int)v1007 >> 2)) >> 1))) | (-(v1009 ^ ((int)((unsigned int)((int)((unsigned int)v1007 >> 2)) >> 1))))) >> 31)) | (~(((v1011 ^ ((int)((unsigned int)((int)((unsigned int)v1007 >> 2)) >> 1))) | (-(v1011 ^ ((int)((unsigned int)((int)((unsigned int)v1007 >> 2)) >> 1))))) >> 31))) == 0);
  int v1129;
  if (v1148) {
    int * v1017 = v1000->cache_age;
    int v1150 = ((((int)((unsigned int)((int)((unsigned int)v1007 >> 2)) >> 1)) & 1) * 2) + ((~(((v1011 ^ ((int)((unsigned int)((int)((unsigned int)v1007 >> 2)) >> 1))) | (-(v1011 ^ ((int)((unsigned int)((int)((unsigned int)v1007 >> 2)) >> 1))))) >> 31)) & 1);
    int v1018 = v1017[v1150];
    int * v1019 = v1000->cache_age;
    int v1020 = v1019[v1141];
    int * v1021 = v1000->cache_age;
    int v1153 = v1020 + ((int)((unsigned int)(v1020 - v1018) >> 31));
    v1021[v1141] = v1153;
    int * v1023 = v1000->cache_age;
    int v1024 = v1023[v1143];
    int * v1025 = v1000->cache_age;
    int v1156 = v1024 + ((int)((unsigned int)(v1024 - v1018) >> 31));
    v1025[v1143] = v1156;
    int * v1027 = v1000->cache_age;
    v1027[v1150] = 0;
    v1129 = v1150;
  } else {
    int * v1030 = v1000->cache_age;
    int v1160 = (((int)((unsigned int)((int)((unsigned int)v1007 >> 2)) >> 1)) & 1) * 2;
    int v1031 = v1030[v1160];
    int * v1032 = v1000->cache_tags;
    int v1033 = v1032[v1160];
    int * v1034 = v1000->cache_age;
    int v1035 = v1034[v1143];
    int * v1036 = v1000->cache_tags;
    int v1037 = v1036[v1143];
    bool v1164 = !(((~(((v1013 ^ ((int)((unsigned int)((int)((unsigned int)v1007 >> 2)) >> 1))) | (-(v1013 ^ ((int)((unsigned int)((int)((unsigned int)v1007 >> 2)) >> 1))))) >> 31)) | (~(((v1015 ^ ((int)((unsigned int)((int)((unsigned int)v1007 >> 2)) >> 1))) | (-(v1015 ^ ((int)((unsigned int)((int)((unsigned int)v1007 >> 2)) >> 1))))) >> 31))) == 0);
    int v1101;
    if (v1164) {
      int * v1038 = v1000->cache_age;
      int v1166 = (4 + ((((int)((unsigned int)((int)((unsigned int)v1007 >> 2)) >> 1)) & 3) * 2)) + ((~(((v1015 ^ ((int)((unsigned int)((int)((unsigned int)v1007 >> 2)) >> 1))) | (-(v1015 ^ ((int)((unsigned int)((int)((unsigned int)v1007 >> 2)) >> 1))))) >> 31)) & 1);
      int v1039 = v1038[v1166];
      int * v1040 = v1000->cache_age;
      int v1041 = v1040[v1145];
      int * v1042 = v1000->cache_age;
      int v1169 = v1041 + ((int)((unsigned int)(v1041 - v1039) >> 31));
      v1042[v1145] = v1169;
      int * v1044 = v1000->cache_age;
      int v1045 = v1044[v1147];
      int * v1046 = v1000->cache_age;
      int v1172 = v1045 + ((int)((unsigned int)(v1045 - v1039) >> 31));
      v1046[v1147] = v1172;
      int * v1048 = v1000->cache_age;
      v1048[v1166] = 0;
      v1101 = v1166;
    } else {
      int * v1051 = v1000->cache_age;
      int v1176 = 4 + ((((int)((unsigned int)((int)((unsigned int)v1007 >> 2)) >> 1)) & 3) * 2);
      int v1052 = v1051[v1176];
      int * v1053 = v1000->cache_tags;
      int v1054 = v1053[v1176];
      int * v1055 = v1000->cache_age;
      int v1056 = v1055[v1147];
      int * v1057 = v1000->cache_tags;
      int v1058 = v1057[v1147];
      int * v1059 = v1000->cache_dirty;
      int v1181 = (4 + ((((int)((unsigned int)((int)((unsigned int)v1007 >> 2)) >> 1)) & 3) * 2)) + ((((v1052 + ((~(((v1054 ^ -1) | (-(v1054 ^ -1))) >> 31)) & 2)) - (v1056 + ((~(((v1058 ^ -1) | (-(v1058 ^ -1))) >> 31)) & 2))) >> 31) & 1);
      int v1060 = v1059[v1181];
      bool v1182 = !(v1060 == 0);
      if (v1182) {
        int * v1061 = v1000->cache_tags;
        int v1062 = v1061[v1181];
        int * v1063 = v1000->cache_vals;
        int v1185 = ((4 + ((((int)((unsigned int)((int)((unsigned int)v1007 >> 2)) >> 1)) & 3) * 2)) + ((((v1052 + ((~(((v1054 ^ -1) | (-(v1054 ^ -1))) >> 31)) & 2)) - (v1056 + ((~(((v1058 ^ -1) | (-(v1058 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
        int v1064 = v1063[v1185];
        int * v1065 = v1000->cache_vals;
        int v1187 = (((4 + ((((int)((unsigned int)((int)((unsigned int)v1007 >> 2)) >> 1)) & 3) * 2)) + ((((v1052 + ((~(((v1054 ^ -1) | (-(v1054 ^ -1))) >> 31)) & 2)) - (v1056 + ((~(((v1058 ^ -1) | (-(v1058 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
        int v1066 = v1065[v1187];
        int * v1067 = v1000->mem;
        int v1189 = v1062 * 2;
        v1067[v1189] = v1064;
        int * v1069 = v1000->mem;
        int v1192 = (v1062 * 2) + 1;
        v1069[v1192] = v1066;
        ;
      } else {
        ;
      }
      int * v1074 = v1000->mem;
      int v1197 = ((int)((unsigned int)((int)((unsigned int)v1007 >> 2)) >> 1)) * 2;
      int v1075 = v1074[v1197];
      int * v1076 = v1000->mem;
      int v1199 = (((int)((unsigned int)((int)((unsigned int)v1007 >> 2)) >> 1)) * 2) + 1;
      int v1077 = v1076[v1199];
      int * v1078 = v1000->cache_vals;
      int v1201 = ((4 + ((((int)((unsigned int)((int)((unsigned int)v1007 >> 2)) >> 1)) & 3) * 2)) + ((((v1052 + ((~(((v1054 ^ -1) | (-(v1054 ^ -1))) >> 31)) & 2)) - (v1056 + ((~(((v1058 ^ -1) | (-(v1058 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
      v1078[v1201] = v1075;
      int * v1080 = v1000->cache_vals;
      int v1204 = (((4 + ((((int)((unsigned int)((int)((unsigned int)v1007 >> 2)) >> 1)) & 3) * 2)) + ((((v1052 + ((~(((v1054 ^ -1) | (-(v1054 ^ -1))) >> 31)) & 2)) - (v1056 + ((~(((v1058 ^ -1) | (-(v1058 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
      v1080[v1204] = v1077;
      int * v1082 = v1000->cache_tags;
      int v1207 = (int)((unsigned int)((int)((unsigned int)v1007 >> 2)) >> 1);
      v1082[v1181] = v1207;
      int * v1084 = v1000->cache_dirty;
      v1084[v1181] = 0;
      int * v1086 = v1000->cache_age;
      v1086[v1181] = 1;
      int * v1088 = v1000->cache_age;
      int v1089 = v1088[v1181];
      int * v1090 = v1000->cache_age;
      int v1091 = v1090[v1145];
      int * v1092 = v1000->cache_age;
      int v1215 = v1091 + ((int)((unsigned int)(v1091 - v1089) >> 31));
      v1092[v1145] = v1215;
      int * v1094 = v1000->cache_age;
      int v1095 = v1094[v1147];
      int * v1096 = v1000->cache_age;
      int v1218 = v1095 + ((int)((unsigned int)(v1095 - v1089) >> 31));
      v1096[v1147] = v1218;
      int * v1098 = v1000->cache_age;
      v1098[v1181] = 0;
      v1101 = v1181;
    }
    int * v1102 = v1000->cache_vals;
    int v1221 = v1101 * 2;
    int v1103 = v1102[v1221];
    int * v1104 = v1000->cache_vals;
    int v1223 = (v1101 * 2) + 1;
    int v1105 = v1104[v1223];
    int * v1106 = v1000->cache_vals;
    int v1225 = (((((int)((unsigned int)((int)((unsigned int)v1007 >> 2)) >> 1)) & 1) * 2) + ((((v1031 + ((~(((v1033 ^ -1) | (-(v1033 ^ -1))) >> 31)) & 2)) - (v1035 + ((~(((v1037 ^ -1) | (-(v1037 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
    v1106[v1225] = v1103;
    int * v1108 = v1000->cache_vals;
    int v1228 = ((((((int)((unsigned int)((int)((unsigned int)v1007 >> 2)) >> 1)) & 1) * 2) + ((((v1031 + ((~(((v1033 ^ -1) | (-(v1033 ^ -1))) >> 31)) & 2)) - (v1035 + ((~(((v1037 ^ -1) | (-(v1037 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
    v1108[v1228] = v1105;
    int * v1110 = v1000->cache_tags;
    int v1231 = ((((int)((unsigned int)((int)((unsigned int)v1007 >> 2)) >> 1)) & 1) * 2) + ((((v1031 + ((~(((v1033 ^ -1) | (-(v1033 ^ -1))) >> 31)) & 2)) - (v1035 + ((~(((v1037 ^ -1) | (-(v1037 ^ -1))) >> 31)) & 2))) >> 31) & 1);
    int v1232 = (int)((unsigned int)((int)((unsigned int)v1007 >> 2)) >> 1);
    v1110[v1231] = v1232;
    int * v1112 = v1000->cache_dirty;
    v1112[v1231] = 0;
    int * v1114 = v1000->cache_age;
    v1114[v1231] = 1;
    int * v1116 = v1000->cache_age;
    int v1117 = v1116[v1231];
    int * v1118 = v1000->cache_age;
    int v1119 = v1118[v1141];
    int * v1120 = v1000->cache_age;
    int v1240 = v1119 + ((int)((unsigned int)(v1119 - v1117) >> 31));
    v1120[v1141] = v1240;
    int * v1122 = v1000->cache_age;
    int v1123 = v1122[v1143];
    int * v1124 = v1000->cache_age;
    int v1243 = v1123 + ((int)((unsigned int)(v1123 - v1117) >> 31));
    v1124[v1143] = v1243;
    int * v1126 = v1000->cache_age;
    v1126[v1231] = 0;
    v1129 = v1231;
  }
  int v1246 = (v1129 * 2) + (((int)((unsigned int)v1007 >> 2)) & 1);
  int v1130 = v1016[v1246];
  int * v1131 = v1000->reg_ready;
  int v1249 = ((v1005 + ((v1001 - v1005) & (~((v1001 - v1005) >> 31)))) + 1) + ((100 ^ (((~(((v1013 ^ ((int)((unsigned int)((int)((unsigned int)v1007 >> 2)) >> 1))) | (-(v1013 ^ ((int)((unsigned int)((int)((unsigned int)v1007 >> 2)) >> 1))))) >> 31)) | (~(((v1015 ^ ((int)((unsigned int)((int)((unsigned int)v1007 >> 2)) >> 1))) | (-(v1015 ^ ((int)((unsigned int)((int)((unsigned int)v1007 >> 2)) >> 1))))) >> 31))) & 104)) ^ (((~(((v1009 ^ ((int)((unsigned int)((int)((unsigned int)v1007 >> 2)) >> 1))) | (-(v1009 ^ ((int)((unsigned int)((int)((unsigned int)v1007 >> 2)) >> 1))))) >> 31)) | (~(((v1011 ^ ((int)((unsigned int)((int)((unsigned int)v1007 >> 2)) >> 1))) | (-(v1011 ^ ((int)((unsigned int)((int)((unsigned int)v1007 >> 2)) >> 1))))) >> 31))) & (1 ^ (100 ^ (((~(((v1013 ^ ((int)((unsigned int)((int)((unsigned int)v1007 >> 2)) >> 1))) | (-(v1013 ^ ((int)((unsigned int)((int)((unsigned int)v1007 >> 2)) >> 1))))) >> 31)) | (~(((v1015 ^ ((int)((unsigned int)((int)((unsigned int)v1007 >> 2)) >> 1))) | (-(v1015 ^ ((int)((unsigned int)((int)((unsigned int)v1007 >> 2)) >> 1))))) >> 31))) & 104)))));
  v1131[12] = v1249;
  int * v1133 = v1000->regs;
  v1133[12] = v1130;
  return v1000;
}

struct StateT * slot_6(struct StateT * v721) {
  int v722 = v721->timer;
  int v723 = v721->timer;
  int v735 = v723 + 1;
  v721->timer = v735;
  int * v725 = v721->reg_ready;
  int v726 = v725[7];
  int * v727 = v721->regs;
  int v728 = v727[7];
  int * v729 = v721->reg_ready;
  int v740 = (v726 + ((v722 - v726) & (~((v722 - v726) >> 31)))) + 1;
  v729[7] = v740;
  int * v731 = v721->regs;
  int v742 = v728 + 1;
  v731[7] = v742;
  struct StateT * v733 = slot_7(v721);
  return v733;
}

struct StateT * slot_5(struct StateT * v703) {
  int v704 = v703->timer;
  int v705 = v703->timer;
  int v713 = v705 + 1;
  v703->timer = v713;
  int * v707 = v703->reg_ready;
  int v716 = v704 + 1;
  v707[7] = v716;
  int * v709 = v703->regs;
  v709[7] = 0;
  struct StateT * v711 = slot_6(v703);
  return v711;
}

struct StateT * slot_4(struct StateT * v311) {
  int v312 = v311->timer;
  int v313 = v311->timer;
  int v522 = v313 + 1;
  v311->timer = v522;
  int * v315 = v311->reg_ready;
  int v316 = v315[8];
  int * v317 = v311->regs;
  int v318 = v317[8];
  int * v319 = v311->reg_ready;
  int v320 = v319[5];
  int * v321 = v311->regs;
  int v322 = v321[5];
  int * v323 = v311->cache_tags;
  int v530 = (((int)((unsigned int)((int)((unsigned int)v318 >> 2)) >> 1)) & 1) * 2;
  int v324 = v323[v530];
  int * v325 = v311->cache_tags;
  int v532 = ((((int)((unsigned int)((int)((unsigned int)v318 >> 2)) >> 1)) & 1) * 2) + 1;
  int v326 = v325[v532];
  int * v327 = v311->cache_tags;
  int v534 = 4 + ((((int)((unsigned int)((int)((unsigned int)v318 >> 2)) >> 1)) & 3) * 2);
  int v328 = v327[v534];
  int * v329 = v311->cache_tags;
  int v536 = (4 + ((((int)((unsigned int)((int)((unsigned int)v318 >> 2)) >> 1)) & 3) * 2)) + 1;
  int v330 = v329[v536];
  int v331 = v311->timer;
  int v537 = v331 + ((100 ^ (((~(((v328 ^ ((int)((unsigned int)((int)((unsigned int)v318 >> 2)) >> 1))) | (-(v328 ^ ((int)((unsigned int)((int)((unsigned int)v318 >> 2)) >> 1))))) >> 31)) | (~(((v330 ^ ((int)((unsigned int)((int)((unsigned int)v318 >> 2)) >> 1))) | (-(v330 ^ ((int)((unsigned int)((int)((unsigned int)v318 >> 2)) >> 1))))) >> 31))) & 104)) ^ (((~(((v324 ^ ((int)((unsigned int)((int)((unsigned int)v318 >> 2)) >> 1))) | (-(v324 ^ ((int)((unsigned int)((int)((unsigned int)v318 >> 2)) >> 1))))) >> 31)) | (~(((v326 ^ ((int)((unsigned int)((int)((unsigned int)v318 >> 2)) >> 1))) | (-(v326 ^ ((int)((unsigned int)((int)((unsigned int)v318 >> 2)) >> 1))))) >> 31))) & (1 ^ (100 ^ (((~(((v328 ^ ((int)((unsigned int)((int)((unsigned int)v318 >> 2)) >> 1))) | (-(v328 ^ ((int)((unsigned int)((int)((unsigned int)v318 >> 2)) >> 1))))) >> 31)) | (~(((v330 ^ ((int)((unsigned int)((int)((unsigned int)v318 >> 2)) >> 1))) | (-(v330 ^ ((int)((unsigned int)((int)((unsigned int)v318 >> 2)) >> 1))))) >> 31))) & 104)))));
  v311->timer = v537;
  bool v538 = !(((~(((v324 ^ ((int)((unsigned int)((int)((unsigned int)v318 >> 2)) >> 1))) | (-(v324 ^ ((int)((unsigned int)((int)((unsigned int)v318 >> 2)) >> 1))))) >> 31)) | (~(((v326 ^ ((int)((unsigned int)((int)((unsigned int)v318 >> 2)) >> 1))) | (-(v326 ^ ((int)((unsigned int)((int)((unsigned int)v318 >> 2)) >> 1))))) >> 31))) == 0);
  int v445;
  if (v538) {
    int * v333 = v311->cache_age;
    int v540 = ((((int)((unsigned int)((int)((unsigned int)v318 >> 2)) >> 1)) & 1) * 2) + ((~(((v326 ^ ((int)((unsigned int)((int)((unsigned int)v318 >> 2)) >> 1))) | (-(v326 ^ ((int)((unsigned int)((int)((unsigned int)v318 >> 2)) >> 1))))) >> 31)) & 1);
    int v334 = v333[v540];
    int * v335 = v311->cache_age;
    int v336 = v335[v530];
    int * v337 = v311->cache_age;
    int v543 = v336 + ((int)((unsigned int)(v336 - v334) >> 31));
    v337[v530] = v543;
    int * v339 = v311->cache_age;
    int v340 = v339[v532];
    int * v341 = v311->cache_age;
    int v546 = v340 + ((int)((unsigned int)(v340 - v334) >> 31));
    v341[v532] = v546;
    int * v343 = v311->cache_age;
    v343[v540] = 0;
    v445 = v540;
  } else {
    int * v346 = v311->cache_age;
    int v550 = (((int)((unsigned int)((int)((unsigned int)v318 >> 2)) >> 1)) & 1) * 2;
    int v347 = v346[v550];
    int * v348 = v311->cache_tags;
    int v349 = v348[v550];
    int * v350 = v311->cache_age;
    int v351 = v350[v532];
    int * v352 = v311->cache_tags;
    int v353 = v352[v532];
    bool v554 = !(((~(((v328 ^ ((int)((unsigned int)((int)((unsigned int)v318 >> 2)) >> 1))) | (-(v328 ^ ((int)((unsigned int)((int)((unsigned int)v318 >> 2)) >> 1))))) >> 31)) | (~(((v330 ^ ((int)((unsigned int)((int)((unsigned int)v318 >> 2)) >> 1))) | (-(v330 ^ ((int)((unsigned int)((int)((unsigned int)v318 >> 2)) >> 1))))) >> 31))) == 0);
    int v417;
    if (v554) {
      int * v354 = v311->cache_age;
      int v556 = (4 + ((((int)((unsigned int)((int)((unsigned int)v318 >> 2)) >> 1)) & 3) * 2)) + ((~(((v330 ^ ((int)((unsigned int)((int)((unsigned int)v318 >> 2)) >> 1))) | (-(v330 ^ ((int)((unsigned int)((int)((unsigned int)v318 >> 2)) >> 1))))) >> 31)) & 1);
      int v355 = v354[v556];
      int * v356 = v311->cache_age;
      int v357 = v356[v534];
      int * v358 = v311->cache_age;
      int v559 = v357 + ((int)((unsigned int)(v357 - v355) >> 31));
      v358[v534] = v559;
      int * v360 = v311->cache_age;
      int v361 = v360[v536];
      int * v362 = v311->cache_age;
      int v562 = v361 + ((int)((unsigned int)(v361 - v355) >> 31));
      v362[v536] = v562;
      int * v364 = v311->cache_age;
      v364[v556] = 0;
      v417 = v556;
    } else {
      int * v367 = v311->cache_age;
      int v566 = 4 + ((((int)((unsigned int)((int)((unsigned int)v318 >> 2)) >> 1)) & 3) * 2);
      int v368 = v367[v566];
      int * v369 = v311->cache_tags;
      int v370 = v369[v566];
      int * v371 = v311->cache_age;
      int v372 = v371[v536];
      int * v373 = v311->cache_tags;
      int v374 = v373[v536];
      int * v375 = v311->cache_dirty;
      int v571 = (4 + ((((int)((unsigned int)((int)((unsigned int)v318 >> 2)) >> 1)) & 3) * 2)) + ((((v368 + ((~(((v370 ^ -1) | (-(v370 ^ -1))) >> 31)) & 2)) - (v372 + ((~(((v374 ^ -1) | (-(v374 ^ -1))) >> 31)) & 2))) >> 31) & 1);
      int v376 = v375[v571];
      bool v572 = !(v376 == 0);
      if (v572) {
        int * v377 = v311->cache_tags;
        int v378 = v377[v571];
        int * v379 = v311->cache_vals;
        int v575 = ((4 + ((((int)((unsigned int)((int)((unsigned int)v318 >> 2)) >> 1)) & 3) * 2)) + ((((v368 + ((~(((v370 ^ -1) | (-(v370 ^ -1))) >> 31)) & 2)) - (v372 + ((~(((v374 ^ -1) | (-(v374 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
        int v380 = v379[v575];
        int * v381 = v311->cache_vals;
        int v577 = (((4 + ((((int)((unsigned int)((int)((unsigned int)v318 >> 2)) >> 1)) & 3) * 2)) + ((((v368 + ((~(((v370 ^ -1) | (-(v370 ^ -1))) >> 31)) & 2)) - (v372 + ((~(((v374 ^ -1) | (-(v374 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
        int v382 = v381[v577];
        int * v383 = v311->mem;
        int v579 = v378 * 2;
        v383[v579] = v380;
        int * v385 = v311->mem;
        int v582 = (v378 * 2) + 1;
        v385[v582] = v382;
        ;
      } else {
        ;
      }
      int * v390 = v311->mem;
      int v587 = ((int)((unsigned int)((int)((unsigned int)v318 >> 2)) >> 1)) * 2;
      int v391 = v390[v587];
      int * v392 = v311->mem;
      int v589 = (((int)((unsigned int)((int)((unsigned int)v318 >> 2)) >> 1)) * 2) + 1;
      int v393 = v392[v589];
      int * v394 = v311->cache_vals;
      int v591 = ((4 + ((((int)((unsigned int)((int)((unsigned int)v318 >> 2)) >> 1)) & 3) * 2)) + ((((v368 + ((~(((v370 ^ -1) | (-(v370 ^ -1))) >> 31)) & 2)) - (v372 + ((~(((v374 ^ -1) | (-(v374 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
      v394[v591] = v391;
      int * v396 = v311->cache_vals;
      int v594 = (((4 + ((((int)((unsigned int)((int)((unsigned int)v318 >> 2)) >> 1)) & 3) * 2)) + ((((v368 + ((~(((v370 ^ -1) | (-(v370 ^ -1))) >> 31)) & 2)) - (v372 + ((~(((v374 ^ -1) | (-(v374 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
      v396[v594] = v393;
      int * v398 = v311->cache_tags;
      int v597 = (int)((unsigned int)((int)((unsigned int)v318 >> 2)) >> 1);
      v398[v571] = v597;
      int * v400 = v311->cache_dirty;
      v400[v571] = 0;
      int * v402 = v311->cache_age;
      v402[v571] = 1;
      int * v404 = v311->cache_age;
      int v405 = v404[v571];
      int * v406 = v311->cache_age;
      int v407 = v406[v534];
      int * v408 = v311->cache_age;
      int v605 = v407 + ((int)((unsigned int)(v407 - v405) >> 31));
      v408[v534] = v605;
      int * v410 = v311->cache_age;
      int v411 = v410[v536];
      int * v412 = v311->cache_age;
      int v608 = v411 + ((int)((unsigned int)(v411 - v405) >> 31));
      v412[v536] = v608;
      int * v414 = v311->cache_age;
      v414[v571] = 0;
      v417 = v571;
    }
    int * v418 = v311->cache_vals;
    int v611 = v417 * 2;
    int v419 = v418[v611];
    int * v420 = v311->cache_vals;
    int v613 = (v417 * 2) + 1;
    int v421 = v420[v613];
    int * v422 = v311->cache_vals;
    int v615 = (((((int)((unsigned int)((int)((unsigned int)v318 >> 2)) >> 1)) & 1) * 2) + ((((v347 + ((~(((v349 ^ -1) | (-(v349 ^ -1))) >> 31)) & 2)) - (v351 + ((~(((v353 ^ -1) | (-(v353 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
    v422[v615] = v419;
    int * v424 = v311->cache_vals;
    int v618 = ((((((int)((unsigned int)((int)((unsigned int)v318 >> 2)) >> 1)) & 1) * 2) + ((((v347 + ((~(((v349 ^ -1) | (-(v349 ^ -1))) >> 31)) & 2)) - (v351 + ((~(((v353 ^ -1) | (-(v353 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
    v424[v618] = v421;
    int * v426 = v311->cache_tags;
    int v621 = ((((int)((unsigned int)((int)((unsigned int)v318 >> 2)) >> 1)) & 1) * 2) + ((((v347 + ((~(((v349 ^ -1) | (-(v349 ^ -1))) >> 31)) & 2)) - (v351 + ((~(((v353 ^ -1) | (-(v353 ^ -1))) >> 31)) & 2))) >> 31) & 1);
    int v622 = (int)((unsigned int)((int)((unsigned int)v318 >> 2)) >> 1);
    v426[v621] = v622;
    int * v428 = v311->cache_dirty;
    v428[v621] = 0;
    int * v430 = v311->cache_age;
    v430[v621] = 1;
    int * v432 = v311->cache_age;
    int v433 = v432[v621];
    int * v434 = v311->cache_age;
    int v435 = v434[v530];
    int * v436 = v311->cache_age;
    int v630 = v435 + ((int)((unsigned int)(v435 - v433) >> 31));
    v436[v530] = v630;
    int * v438 = v311->cache_age;
    int v439 = v438[v532];
    int * v440 = v311->cache_age;
    int v633 = v439 + ((int)((unsigned int)(v439 - v433) >> 31));
    v440[v532] = v633;
    int * v442 = v311->cache_age;
    v442[v621] = 0;
    v445 = v621;
  }
  int * v446 = v311->cache_vals;
  int v636 = (v445 * 2) + (((int)((unsigned int)v318 >> 2)) & 1);
  v446[v636] = v322;
  int * v448 = v311->cache_tags;
  int v449 = v448[v534];
  int * v450 = v311->cache_tags;
  int v451 = v450[v536];
  bool v640 = !(((~(((v449 ^ ((int)((unsigned int)((int)((unsigned int)v318 >> 2)) >> 1))) | (-(v449 ^ ((int)((unsigned int)((int)((unsigned int)v318 >> 2)) >> 1))))) >> 31)) | (~(((v451 ^ ((int)((unsigned int)((int)((unsigned int)v318 >> 2)) >> 1))) | (-(v451 ^ ((int)((unsigned int)((int)((unsigned int)v318 >> 2)) >> 1))))) >> 31))) == 0);
  int v515;
  if (v640) {
    int * v452 = v311->cache_age;
    int v642 = (4 + ((((int)((unsigned int)((int)((unsigned int)v318 >> 2)) >> 1)) & 3) * 2)) + ((~(((v451 ^ ((int)((unsigned int)((int)((unsigned int)v318 >> 2)) >> 1))) | (-(v451 ^ ((int)((unsigned int)((int)((unsigned int)v318 >> 2)) >> 1))))) >> 31)) & 1);
    int v453 = v452[v642];
    int * v454 = v311->cache_age;
    int v455 = v454[v534];
    int * v456 = v311->cache_age;
    int v645 = v455 + ((int)((unsigned int)(v455 - v453) >> 31));
    v456[v534] = v645;
    int * v458 = v311->cache_age;
    int v459 = v458[v536];
    int * v460 = v311->cache_age;
    int v648 = v459 + ((int)((unsigned int)(v459 - v453) >> 31));
    v460[v536] = v648;
    int * v462 = v311->cache_age;
    v462[v642] = 0;
    v515 = v642;
  } else {
    int * v465 = v311->cache_age;
    int v652 = 4 + ((((int)((unsigned int)((int)((unsigned int)v318 >> 2)) >> 1)) & 3) * 2);
    int v466 = v465[v652];
    int * v467 = v311->cache_tags;
    int v468 = v467[v652];
    int * v469 = v311->cache_age;
    int v470 = v469[v536];
    int * v471 = v311->cache_tags;
    int v472 = v471[v536];
    int * v473 = v311->cache_dirty;
    int v657 = (4 + ((((int)((unsigned int)((int)((unsigned int)v318 >> 2)) >> 1)) & 3) * 2)) + ((((v466 + ((~(((v468 ^ -1) | (-(v468 ^ -1))) >> 31)) & 2)) - (v470 + ((~(((v472 ^ -1) | (-(v472 ^ -1))) >> 31)) & 2))) >> 31) & 1);
    int v474 = v473[v657];
    bool v658 = !(v474 == 0);
    if (v658) {
      int * v475 = v311->cache_tags;
      int v476 = v475[v657];
      int * v477 = v311->cache_vals;
      int v661 = ((4 + ((((int)((unsigned int)((int)((unsigned int)v318 >> 2)) >> 1)) & 3) * 2)) + ((((v466 + ((~(((v468 ^ -1) | (-(v468 ^ -1))) >> 31)) & 2)) - (v470 + ((~(((v472 ^ -1) | (-(v472 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
      int v478 = v477[v661];
      int * v479 = v311->cache_vals;
      int v663 = (((4 + ((((int)((unsigned int)((int)((unsigned int)v318 >> 2)) >> 1)) & 3) * 2)) + ((((v466 + ((~(((v468 ^ -1) | (-(v468 ^ -1))) >> 31)) & 2)) - (v470 + ((~(((v472 ^ -1) | (-(v472 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
      int v480 = v479[v663];
      int * v481 = v311->mem;
      int v665 = v476 * 2;
      v481[v665] = v478;
      int * v483 = v311->mem;
      int v668 = (v476 * 2) + 1;
      v483[v668] = v480;
      ;
    } else {
      ;
    }
    int * v488 = v311->mem;
    int v673 = ((int)((unsigned int)((int)((unsigned int)v318 >> 2)) >> 1)) * 2;
    int v489 = v488[v673];
    int * v490 = v311->mem;
    int v675 = (((int)((unsigned int)((int)((unsigned int)v318 >> 2)) >> 1)) * 2) + 1;
    int v491 = v490[v675];
    int * v492 = v311->cache_vals;
    int v677 = ((4 + ((((int)((unsigned int)((int)((unsigned int)v318 >> 2)) >> 1)) & 3) * 2)) + ((((v466 + ((~(((v468 ^ -1) | (-(v468 ^ -1))) >> 31)) & 2)) - (v470 + ((~(((v472 ^ -1) | (-(v472 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
    v492[v677] = v489;
    int * v494 = v311->cache_vals;
    int v680 = (((4 + ((((int)((unsigned int)((int)((unsigned int)v318 >> 2)) >> 1)) & 3) * 2)) + ((((v466 + ((~(((v468 ^ -1) | (-(v468 ^ -1))) >> 31)) & 2)) - (v470 + ((~(((v472 ^ -1) | (-(v472 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
    v494[v680] = v491;
    int * v496 = v311->cache_tags;
    int v683 = (int)((unsigned int)((int)((unsigned int)v318 >> 2)) >> 1);
    v496[v657] = v683;
    int * v498 = v311->cache_dirty;
    v498[v657] = 0;
    int * v500 = v311->cache_age;
    v500[v657] = 1;
    int * v502 = v311->cache_age;
    int v503 = v502[v657];
    int * v504 = v311->cache_age;
    int v505 = v504[v534];
    int * v506 = v311->cache_age;
    int v691 = v505 + ((int)((unsigned int)(v505 - v503) >> 31));
    v506[v534] = v691;
    int * v508 = v311->cache_age;
    int v509 = v508[v536];
    int * v510 = v311->cache_age;
    int v694 = v509 + ((int)((unsigned int)(v509 - v503) >> 31));
    v510[v536] = v694;
    int * v512 = v311->cache_age;
    v512[v657] = 0;
    v515 = v657;
  }
  int * v516 = v311->cache_vals;
  int v697 = (v515 * 2) + (((int)((unsigned int)v318 >> 2)) & 1);
  v516[v697] = v322;
  int * v518 = v311->cache_dirty;
  v518[v515] = 1;
  struct StateT * v520 = slot_5(v311);
  return v520;
}

struct StateT * slot_2(struct StateT * v275) {
  int v276 = v275->timer;
  int v277 = v275->timer;
  int v285 = v277 + 1;
  v275->timer = v285;
  int * v279 = v275->reg_ready;
  int v288 = v276 + 1;
  v279[8] = v288;
  int * v281 = v275->regs;
  v281[8] = 96;
  struct StateT * v283 = slot_3(v275);
  return v283;
}

struct StateT * slot_7(struct StateT * v745) {
  int v746 = v745->timer;
  int v747 = v745->timer;
  int v882 = v747 + 1;
  v745->timer = v882;
  int * v749 = v745->reg_ready;
  int v750 = v749[9];
  int * v751 = v745->regs;
  int v752 = v751[9];
  int * v753 = v745->cache_tags;
  int v887 = (((int)((unsigned int)((int)((unsigned int)v752 >> 2)) >> 1)) & 1) * 2;
  int v754 = v753[v887];
  int * v755 = v745->cache_tags;
  int v889 = ((((int)((unsigned int)((int)((unsigned int)v752 >> 2)) >> 1)) & 1) * 2) + 1;
  int v756 = v755[v889];
  int * v757 = v745->cache_tags;
  int v891 = 4 + ((((int)((unsigned int)((int)((unsigned int)v752 >> 2)) >> 1)) & 3) * 2);
  int v758 = v757[v891];
  int * v759 = v745->cache_tags;
  int v893 = (4 + ((((int)((unsigned int)((int)((unsigned int)v752 >> 2)) >> 1)) & 3) * 2)) + 1;
  int v760 = v759[v893];
  int * v761 = v745->cache_vals;
  bool v894 = !(((~(((v754 ^ ((int)((unsigned int)((int)((unsigned int)v752 >> 2)) >> 1))) | (-(v754 ^ ((int)((unsigned int)((int)((unsigned int)v752 >> 2)) >> 1))))) >> 31)) | (~(((v756 ^ ((int)((unsigned int)((int)((unsigned int)v752 >> 2)) >> 1))) | (-(v756 ^ ((int)((unsigned int)((int)((unsigned int)v752 >> 2)) >> 1))))) >> 31))) == 0);
  int v874;
  if (v894) {
    int * v762 = v745->cache_age;
    int v896 = ((((int)((unsigned int)((int)((unsigned int)v752 >> 2)) >> 1)) & 1) * 2) + ((~(((v756 ^ ((int)((unsigned int)((int)((unsigned int)v752 >> 2)) >> 1))) | (-(v756 ^ ((int)((unsigned int)((int)((unsigned int)v752 >> 2)) >> 1))))) >> 31)) & 1);
    int v763 = v762[v896];
    int * v764 = v745->cache_age;
    int v765 = v764[v887];
    int * v766 = v745->cache_age;
    int v899 = v765 + ((int)((unsigned int)(v765 - v763) >> 31));
    v766[v887] = v899;
    int * v768 = v745->cache_age;
    int v769 = v768[v889];
    int * v770 = v745->cache_age;
    int v902 = v769 + ((int)((unsigned int)(v769 - v763) >> 31));
    v770[v889] = v902;
    int * v772 = v745->cache_age;
    v772[v896] = 0;
    v874 = v896;
  } else {
    int * v775 = v745->cache_age;
    int v906 = (((int)((unsigned int)((int)((unsigned int)v752 >> 2)) >> 1)) & 1) * 2;
    int v776 = v775[v906];
    int * v777 = v745->cache_tags;
    int v778 = v777[v906];
    int * v779 = v745->cache_age;
    int v780 = v779[v889];
    int * v781 = v745->cache_tags;
    int v782 = v781[v889];
    bool v910 = !(((~(((v758 ^ ((int)((unsigned int)((int)((unsigned int)v752 >> 2)) >> 1))) | (-(v758 ^ ((int)((unsigned int)((int)((unsigned int)v752 >> 2)) >> 1))))) >> 31)) | (~(((v760 ^ ((int)((unsigned int)((int)((unsigned int)v752 >> 2)) >> 1))) | (-(v760 ^ ((int)((unsigned int)((int)((unsigned int)v752 >> 2)) >> 1))))) >> 31))) == 0);
    int v846;
    if (v910) {
      int * v783 = v745->cache_age;
      int v912 = (4 + ((((int)((unsigned int)((int)((unsigned int)v752 >> 2)) >> 1)) & 3) * 2)) + ((~(((v760 ^ ((int)((unsigned int)((int)((unsigned int)v752 >> 2)) >> 1))) | (-(v760 ^ ((int)((unsigned int)((int)((unsigned int)v752 >> 2)) >> 1))))) >> 31)) & 1);
      int v784 = v783[v912];
      int * v785 = v745->cache_age;
      int v786 = v785[v891];
      int * v787 = v745->cache_age;
      int v915 = v786 + ((int)((unsigned int)(v786 - v784) >> 31));
      v787[v891] = v915;
      int * v789 = v745->cache_age;
      int v790 = v789[v893];
      int * v791 = v745->cache_age;
      int v918 = v790 + ((int)((unsigned int)(v790 - v784) >> 31));
      v791[v893] = v918;
      int * v793 = v745->cache_age;
      v793[v912] = 0;
      v846 = v912;
    } else {
      int * v796 = v745->cache_age;
      int v922 = 4 + ((((int)((unsigned int)((int)((unsigned int)v752 >> 2)) >> 1)) & 3) * 2);
      int v797 = v796[v922];
      int * v798 = v745->cache_tags;
      int v799 = v798[v922];
      int * v800 = v745->cache_age;
      int v801 = v800[v893];
      int * v802 = v745->cache_tags;
      int v803 = v802[v893];
      int * v804 = v745->cache_dirty;
      int v927 = (4 + ((((int)((unsigned int)((int)((unsigned int)v752 >> 2)) >> 1)) & 3) * 2)) + ((((v797 + ((~(((v799 ^ -1) | (-(v799 ^ -1))) >> 31)) & 2)) - (v801 + ((~(((v803 ^ -1) | (-(v803 ^ -1))) >> 31)) & 2))) >> 31) & 1);
      int v805 = v804[v927];
      bool v928 = !(v805 == 0);
      if (v928) {
        int * v806 = v745->cache_tags;
        int v807 = v806[v927];
        int * v808 = v745->cache_vals;
        int v931 = ((4 + ((((int)((unsigned int)((int)((unsigned int)v752 >> 2)) >> 1)) & 3) * 2)) + ((((v797 + ((~(((v799 ^ -1) | (-(v799 ^ -1))) >> 31)) & 2)) - (v801 + ((~(((v803 ^ -1) | (-(v803 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
        int v809 = v808[v931];
        int * v810 = v745->cache_vals;
        int v933 = (((4 + ((((int)((unsigned int)((int)((unsigned int)v752 >> 2)) >> 1)) & 3) * 2)) + ((((v797 + ((~(((v799 ^ -1) | (-(v799 ^ -1))) >> 31)) & 2)) - (v801 + ((~(((v803 ^ -1) | (-(v803 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
        int v811 = v810[v933];
        int * v812 = v745->mem;
        int v935 = v807 * 2;
        v812[v935] = v809;
        int * v814 = v745->mem;
        int v938 = (v807 * 2) + 1;
        v814[v938] = v811;
        ;
      } else {
        ;
      }
      int * v819 = v745->mem;
      int v943 = ((int)((unsigned int)((int)((unsigned int)v752 >> 2)) >> 1)) * 2;
      int v820 = v819[v943];
      int * v821 = v745->mem;
      int v945 = (((int)((unsigned int)((int)((unsigned int)v752 >> 2)) >> 1)) * 2) + 1;
      int v822 = v821[v945];
      int * v823 = v745->cache_vals;
      int v947 = ((4 + ((((int)((unsigned int)((int)((unsigned int)v752 >> 2)) >> 1)) & 3) * 2)) + ((((v797 + ((~(((v799 ^ -1) | (-(v799 ^ -1))) >> 31)) & 2)) - (v801 + ((~(((v803 ^ -1) | (-(v803 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
      v823[v947] = v820;
      int * v825 = v745->cache_vals;
      int v950 = (((4 + ((((int)((unsigned int)((int)((unsigned int)v752 >> 2)) >> 1)) & 3) * 2)) + ((((v797 + ((~(((v799 ^ -1) | (-(v799 ^ -1))) >> 31)) & 2)) - (v801 + ((~(((v803 ^ -1) | (-(v803 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
      v825[v950] = v822;
      int * v827 = v745->cache_tags;
      int v953 = (int)((unsigned int)((int)((unsigned int)v752 >> 2)) >> 1);
      v827[v927] = v953;
      int * v829 = v745->cache_dirty;
      v829[v927] = 0;
      int * v831 = v745->cache_age;
      v831[v927] = 1;
      int * v833 = v745->cache_age;
      int v834 = v833[v927];
      int * v835 = v745->cache_age;
      int v836 = v835[v891];
      int * v837 = v745->cache_age;
      int v961 = v836 + ((int)((unsigned int)(v836 - v834) >> 31));
      v837[v891] = v961;
      int * v839 = v745->cache_age;
      int v840 = v839[v893];
      int * v841 = v745->cache_age;
      int v964 = v840 + ((int)((unsigned int)(v840 - v834) >> 31));
      v841[v893] = v964;
      int * v843 = v745->cache_age;
      v843[v927] = 0;
      v846 = v927;
    }
    int * v847 = v745->cache_vals;
    int v967 = v846 * 2;
    int v848 = v847[v967];
    int * v849 = v745->cache_vals;
    int v969 = (v846 * 2) + 1;
    int v850 = v849[v969];
    int * v851 = v745->cache_vals;
    int v971 = (((((int)((unsigned int)((int)((unsigned int)v752 >> 2)) >> 1)) & 1) * 2) + ((((v776 + ((~(((v778 ^ -1) | (-(v778 ^ -1))) >> 31)) & 2)) - (v780 + ((~(((v782 ^ -1) | (-(v782 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
    v851[v971] = v848;
    int * v853 = v745->cache_vals;
    int v974 = ((((((int)((unsigned int)((int)((unsigned int)v752 >> 2)) >> 1)) & 1) * 2) + ((((v776 + ((~(((v778 ^ -1) | (-(v778 ^ -1))) >> 31)) & 2)) - (v780 + ((~(((v782 ^ -1) | (-(v782 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
    v853[v974] = v850;
    int * v855 = v745->cache_tags;
    int v977 = ((((int)((unsigned int)((int)((unsigned int)v752 >> 2)) >> 1)) & 1) * 2) + ((((v776 + ((~(((v778 ^ -1) | (-(v778 ^ -1))) >> 31)) & 2)) - (v780 + ((~(((v782 ^ -1) | (-(v782 ^ -1))) >> 31)) & 2))) >> 31) & 1);
    int v978 = (int)((unsigned int)((int)((unsigned int)v752 >> 2)) >> 1);
    v855[v977] = v978;
    int * v857 = v745->cache_dirty;
    v857[v977] = 0;
    int * v859 = v745->cache_age;
    v859[v977] = 1;
    int * v861 = v745->cache_age;
    int v862 = v861[v977];
    int * v863 = v745->cache_age;
    int v864 = v863[v887];
    int * v865 = v745->cache_age;
    int v986 = v864 + ((int)((unsigned int)(v864 - v862) >> 31));
    v865[v887] = v986;
    int * v867 = v745->cache_age;
    int v868 = v867[v889];
    int * v869 = v745->cache_age;
    int v989 = v868 + ((int)((unsigned int)(v868 - v862) >> 31));
    v869[v889] = v989;
    int * v871 = v745->cache_age;
    v871[v977] = 0;
    v874 = v977;
  }
  int v992 = (v874 * 2) + (((int)((unsigned int)v752 >> 2)) & 1);
  int v875 = v761[v992];
  int * v876 = v745->reg_ready;
  int v995 = ((v750 + ((v746 - v750) & (~((v746 - v750) >> 31)))) + 1) + ((100 ^ (((~(((v758 ^ ((int)((unsigned int)((int)((unsigned int)v752 >> 2)) >> 1))) | (-(v758 ^ ((int)((unsigned int)((int)((unsigned int)v752 >> 2)) >> 1))))) >> 31)) | (~(((v760 ^ ((int)((unsigned int)((int)((unsigned int)v752 >> 2)) >> 1))) | (-(v760 ^ ((int)((unsigned int)((int)((unsigned int)v752 >> 2)) >> 1))))) >> 31))) & 104)) ^ (((~(((v754 ^ ((int)((unsigned int)((int)((unsigned int)v752 >> 2)) >> 1))) | (-(v754 ^ ((int)((unsigned int)((int)((unsigned int)v752 >> 2)) >> 1))))) >> 31)) | (~(((v756 ^ ((int)((unsigned int)((int)((unsigned int)v752 >> 2)) >> 1))) | (-(v756 ^ ((int)((unsigned int)((int)((unsigned int)v752 >> 2)) >> 1))))) >> 31))) & (1 ^ (100 ^ (((~(((v758 ^ ((int)((unsigned int)((int)((unsigned int)v752 >> 2)) >> 1))) | (-(v758 ^ ((int)((unsigned int)((int)((unsigned int)v752 >> 2)) >> 1))))) >> 31)) | (~(((v760 ^ ((int)((unsigned int)((int)((unsigned int)v752 >> 2)) >> 1))) | (-(v760 ^ ((int)((unsigned int)((int)((unsigned int)v752 >> 2)) >> 1))))) >> 31))) & 104)))));
  v876[11] = v995;
  int * v878 = v745->regs;
  v878[11] = v875;
  struct StateT * v880 = slot_8(v745);
  return v880;
}

struct StateT * slot_3(struct StateT * v293) {
  int v294 = v293->timer;
  int v295 = v293->timer;
  int v303 = v295 + 1;
  v293->timer = v303;
  int * v297 = v293->reg_ready;
  int v306 = v294 + 1;
  v297[9] = v306;
  int * v299 = v293->regs;
  v299[9] = 0;
  struct StateT * v301 = slot_4(v293);
  return v301;
}

struct StateT * slot_0(struct StateT * v2) {
  int v3 = v2->timer;
  int v4 = v2->timer;
  int v12 = v4 + 1;
  v2->timer = v12;
  int * v6 = v2->reg_ready;
  int v15 = v3 + 1;
  v6[6] = v15;
  int * v8 = v2->regs;
  v8[6] = 80;
  struct StateT * v10 = slot_1(v2);
  return v10;
}



/*****************************************
End of C Generated Code
*******************************************/

void init(struct StateT *s) {
  for (int i=0; i<NUM_REGS; i++) {
    s->regs[i] = 0;
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
    s1.mem[SECRET_OFFSET+i] = bounded(0, 20);
    s2.mem[SECRET_OFFSET+i] = bounded(0, 20);
  }
  struct StateT *s1_ = snippet(&s1);
  struct StateT *s2_ = snippet(&s2);
  koika_assert(s1_->timer==s2_->timer, "timing leak");
  return 0;
}