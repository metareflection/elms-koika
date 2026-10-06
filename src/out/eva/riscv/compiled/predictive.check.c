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

struct StateT * slot_34(struct StateT * v1304);
struct StateT * slot_6(struct StateT * v92);
struct StateT * slot_29(struct StateT * v1211);
struct StateT * slot_16(struct StateT * v656);
struct StateT * slot_23(struct StateT * v952);
struct StateT * slot_5(struct StateT * v72);
struct StateT * slot_2(struct StateT * v30);
struct StateT * slot_7(struct StateT * v106);
struct StateT * slot_31(struct StateT * v1278);
struct StateT * slot_3(struct StateT * v38);
struct StateT * slot_26(struct StateT * v1161);
struct StateT * slot_1(struct StateT * v17);
struct StateT * slot_13(struct StateT * v593);
struct StateT * slot_24(struct StateT * v957);
struct StateT * slot_0(struct StateT * v2);
struct StateT * slot_14(struct StateT * v614);
struct StateT * slot_28(struct StateT * v1190);
struct StateT * slot_32(struct StateT * v1291);
struct StateT * slot_20(struct StateT * v728);
struct StateT * slot_36(struct StateT * v1515);
struct StateT * slot_37(struct StateT * v1726);
struct StateT * snippet(struct StateT * v0);
struct StateT * slot_8(struct StateT * v317);
struct StateT * slot_27(struct StateT * v1169);
struct StateT * slot_30(struct StateT * v1232);
struct StateT * slot_4(struct StateT * v58);
struct StateT * slot_15(struct StateT * v635);
struct StateT * slot_18(struct StateT * v715);
struct StateT * slot_9(struct StateT * v528);
struct StateT * slot_22(struct StateT * v748);
struct StateT * slot_11(struct StateT * v585);
struct StateT * slot_34(struct StateT * v1304) {
  int * v1305 = v1304->saved_regs;
  int * v1306 = v1304->regs;
  int v1307 = v1306[14];
  v1305[14] = v1307;
  int v1309 = v1304->timer;
  int v1423 = v1309 + 1;
  v1304->timer = v1423;
  int * v1311 = v1304->regs;
  int v1312 = v1311[12];
  int * v1313 = v1304->cache_tags;
  int v1427 = (((int)((unsigned int)((int)((unsigned int)v1312 >> 2)) >> 1)) & 1) * 2;
  int v1314 = v1313[v1427];
  int v1428 = ((((int)((unsigned int)((int)((unsigned int)v1312 >> 2)) >> 1)) & 1) * 2) + 1;
  int v1315 = v1313[v1428];
  int v1429 = 4 + ((((int)((unsigned int)((int)((unsigned int)v1312 >> 2)) >> 1)) & 3) * 2);
  int v1316 = v1313[v1429];
  int v1430 = (4 + ((((int)((unsigned int)((int)((unsigned int)v1312 >> 2)) >> 1)) & 3) * 2)) + 1;
  int v1317 = v1313[v1430];
  int v1318 = v1304->timer;
  int v1431 = v1318 + ((100 ^ (((~(((v1316 ^ ((int)((unsigned int)((int)((unsigned int)v1312 >> 2)) >> 1))) | (-(v1316 ^ ((int)((unsigned int)((int)((unsigned int)v1312 >> 2)) >> 1))))) >> 31)) | (~(((v1317 ^ ((int)((unsigned int)((int)((unsigned int)v1312 >> 2)) >> 1))) | (-(v1317 ^ ((int)((unsigned int)((int)((unsigned int)v1312 >> 2)) >> 1))))) >> 31))) & 104)) ^ (((~(((v1314 ^ ((int)((unsigned int)((int)((unsigned int)v1312 >> 2)) >> 1))) | (-(v1314 ^ ((int)((unsigned int)((int)((unsigned int)v1312 >> 2)) >> 1))))) >> 31)) | (~(((v1315 ^ ((int)((unsigned int)((int)((unsigned int)v1312 >> 2)) >> 1))) | (-(v1315 ^ ((int)((unsigned int)((int)((unsigned int)v1312 >> 2)) >> 1))))) >> 31))) & (1 ^ (100 ^ (((~(((v1316 ^ ((int)((unsigned int)((int)((unsigned int)v1312 >> 2)) >> 1))) | (-(v1316 ^ ((int)((unsigned int)((int)((unsigned int)v1312 >> 2)) >> 1))))) >> 31)) | (~(((v1317 ^ ((int)((unsigned int)((int)((unsigned int)v1312 >> 2)) >> 1))) | (-(v1317 ^ ((int)((unsigned int)((int)((unsigned int)v1312 >> 2)) >> 1))))) >> 31))) & 104)))));
  v1304->timer = v1431;
  int * v1320 = v1304->cache_vals;
  bool v1432 = !(((~(((v1314 ^ ((int)((unsigned int)((int)((unsigned int)v1312 >> 2)) >> 1))) | (-(v1314 ^ ((int)((unsigned int)((int)((unsigned int)v1312 >> 2)) >> 1))))) >> 31)) | (~(((v1315 ^ ((int)((unsigned int)((int)((unsigned int)v1312 >> 2)) >> 1))) | (-(v1315 ^ ((int)((unsigned int)((int)((unsigned int)v1312 >> 2)) >> 1))))) >> 31))) == 0);
  int v1413;
  if (v1432) {
    int * v1321 = v1304->cache_age;
    int v1434 = ((((int)((unsigned int)((int)((unsigned int)v1312 >> 2)) >> 1)) & 1) * 2) + ((~(((v1315 ^ ((int)((unsigned int)((int)((unsigned int)v1312 >> 2)) >> 1))) | (-(v1315 ^ ((int)((unsigned int)((int)((unsigned int)v1312 >> 2)) >> 1))))) >> 31)) & 1);
    int v1322 = v1321[v1434];
    int v1323 = v1321[v1427];
    int v1435 = v1323 + ((int)((unsigned int)(v1323 - v1322) >> 31));
    v1321[v1427] = v1435;
    int * v1325 = v1304->cache_age;
    int v1326 = v1325[v1428];
    int v1437 = v1326 + ((int)((unsigned int)(v1326 - v1322) >> 31));
    v1325[v1428] = v1437;
    int * v1328 = v1304->cache_age;
    v1328[v1434] = 0;
    v1413 = v1434;
  } else {
    int * v1331 = v1304->cache_age;
    int v1441 = (((int)((unsigned int)((int)((unsigned int)v1312 >> 2)) >> 1)) & 1) * 2;
    int v1332 = v1331[v1441];
    int * v1333 = v1304->cache_tags;
    int v1334 = v1333[v1441];
    int v1335 = v1331[v1428];
    int v1336 = v1333[v1428];
    bool v1443 = !(((~(((v1316 ^ ((int)((unsigned int)((int)((unsigned int)v1312 >> 2)) >> 1))) | (-(v1316 ^ ((int)((unsigned int)((int)((unsigned int)v1312 >> 2)) >> 1))))) >> 31)) | (~(((v1317 ^ ((int)((unsigned int)((int)((unsigned int)v1312 >> 2)) >> 1))) | (-(v1317 ^ ((int)((unsigned int)((int)((unsigned int)v1312 >> 2)) >> 1))))) >> 31))) == 0);
    int v1390;
    if (v1443) {
      int * v1337 = v1304->cache_age;
      int v1445 = (4 + ((((int)((unsigned int)((int)((unsigned int)v1312 >> 2)) >> 1)) & 3) * 2)) + ((~(((v1317 ^ ((int)((unsigned int)((int)((unsigned int)v1312 >> 2)) >> 1))) | (-(v1317 ^ ((int)((unsigned int)((int)((unsigned int)v1312 >> 2)) >> 1))))) >> 31)) & 1);
      int v1338 = v1337[v1445];
      int v1339 = v1337[v1429];
      int v1446 = v1339 + ((int)((unsigned int)(v1339 - v1338) >> 31));
      v1337[v1429] = v1446;
      int * v1341 = v1304->cache_age;
      int v1342 = v1341[v1430];
      int v1448 = v1342 + ((int)((unsigned int)(v1342 - v1338) >> 31));
      v1341[v1430] = v1448;
      int * v1344 = v1304->cache_age;
      v1344[v1445] = 0;
      v1390 = v1445;
    } else {
      int * v1347 = v1304->cache_age;
      int v1452 = 4 + ((((int)((unsigned int)((int)((unsigned int)v1312 >> 2)) >> 1)) & 3) * 2);
      int v1348 = v1347[v1452];
      int * v1349 = v1304->cache_tags;
      int v1350 = v1349[v1452];
      int v1351 = v1347[v1430];
      int v1352 = v1349[v1430];
      int * v1353 = v1304->cache_dirty;
      int v1455 = (4 + ((((int)((unsigned int)((int)((unsigned int)v1312 >> 2)) >> 1)) & 3) * 2)) + ((((v1348 + ((~(((v1350 ^ -1) | (-(v1350 ^ -1))) >> 31)) & 2)) - (v1351 + ((~(((v1352 ^ -1) | (-(v1352 ^ -1))) >> 31)) & 2))) >> 31) & 1);
      int v1354 = v1353[v1455];
      bool v1456 = !(v1354 == 0);
      if (v1456) {
        int * v1355 = v1304->cache_tags;
        int v1356 = v1355[v1455];
        int * v1357 = v1304->cache_vals;
        int v1459 = ((4 + ((((int)((unsigned int)((int)((unsigned int)v1312 >> 2)) >> 1)) & 3) * 2)) + ((((v1348 + ((~(((v1350 ^ -1) | (-(v1350 ^ -1))) >> 31)) & 2)) - (v1351 + ((~(((v1352 ^ -1) | (-(v1352 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
        int v1358 = v1357[v1459];
        int v1460 = (((4 + ((((int)((unsigned int)((int)((unsigned int)v1312 >> 2)) >> 1)) & 3) * 2)) + ((((v1348 + ((~(((v1350 ^ -1) | (-(v1350 ^ -1))) >> 31)) & 2)) - (v1351 + ((~(((v1352 ^ -1) | (-(v1352 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
        int v1359 = v1357[v1460];
        int * v1360 = v1304->mem;
        int v1462 = v1356 * 2;
        v1360[v1462] = v1358;
        int * v1362 = v1304->mem;
        int v1465 = (v1356 * 2) + 1;
        v1362[v1465] = v1359;
        ;
      } else {
        ;
      }
      int * v1367 = v1304->mem;
      int v1470 = ((int)((unsigned int)((int)((unsigned int)v1312 >> 2)) >> 1)) * 2;
      int v1368 = v1367[v1470];
      int v1471 = (((int)((unsigned int)((int)((unsigned int)v1312 >> 2)) >> 1)) * 2) + 1;
      int v1369 = v1367[v1471];
      int * v1370 = v1304->cache_vals;
      int v1473 = ((4 + ((((int)((unsigned int)((int)((unsigned int)v1312 >> 2)) >> 1)) & 3) * 2)) + ((((v1348 + ((~(((v1350 ^ -1) | (-(v1350 ^ -1))) >> 31)) & 2)) - (v1351 + ((~(((v1352 ^ -1) | (-(v1352 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
      v1370[v1473] = v1368;
      int * v1372 = v1304->cache_vals;
      int v1476 = (((4 + ((((int)((unsigned int)((int)((unsigned int)v1312 >> 2)) >> 1)) & 3) * 2)) + ((((v1348 + ((~(((v1350 ^ -1) | (-(v1350 ^ -1))) >> 31)) & 2)) - (v1351 + ((~(((v1352 ^ -1) | (-(v1352 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
      v1372[v1476] = v1369;
      int * v1374 = v1304->cache_tags;
      int v1479 = (int)((unsigned int)((int)((unsigned int)v1312 >> 2)) >> 1);
      v1374[v1455] = v1479;
      int * v1376 = v1304->cache_dirty;
      v1376[v1455] = 0;
      int * v1378 = v1304->cache_age;
      v1378[v1455] = 1;
      int * v1380 = v1304->cache_age;
      int v1381 = v1380[v1455];
      int v1382 = v1380[v1429];
      int v1485 = v1382 + ((int)((unsigned int)(v1382 - v1381) >> 31));
      v1380[v1429] = v1485;
      int * v1384 = v1304->cache_age;
      int v1385 = v1384[v1430];
      int v1487 = v1385 + ((int)((unsigned int)(v1385 - v1381) >> 31));
      v1384[v1430] = v1487;
      int * v1387 = v1304->cache_age;
      v1387[v1455] = 0;
      v1390 = v1455;
    }
    int * v1391 = v1304->cache_vals;
    int v1490 = v1390 * 2;
    int v1392 = v1391[v1490];
    int v1491 = (v1390 * 2) + 1;
    int v1393 = v1391[v1491];
    int v1492 = (((((int)((unsigned int)((int)((unsigned int)v1312 >> 2)) >> 1)) & 1) * 2) + ((((v1332 + ((~(((v1334 ^ -1) | (-(v1334 ^ -1))) >> 31)) & 2)) - (v1335 + ((~(((v1336 ^ -1) | (-(v1336 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
    v1391[v1492] = v1392;
    int * v1395 = v1304->cache_vals;
    int v1495 = ((((((int)((unsigned int)((int)((unsigned int)v1312 >> 2)) >> 1)) & 1) * 2) + ((((v1332 + ((~(((v1334 ^ -1) | (-(v1334 ^ -1))) >> 31)) & 2)) - (v1335 + ((~(((v1336 ^ -1) | (-(v1336 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
    v1395[v1495] = v1393;
    int * v1397 = v1304->cache_tags;
    int v1498 = ((((int)((unsigned int)((int)((unsigned int)v1312 >> 2)) >> 1)) & 1) * 2) + ((((v1332 + ((~(((v1334 ^ -1) | (-(v1334 ^ -1))) >> 31)) & 2)) - (v1335 + ((~(((v1336 ^ -1) | (-(v1336 ^ -1))) >> 31)) & 2))) >> 31) & 1);
    int v1499 = (int)((unsigned int)((int)((unsigned int)v1312 >> 2)) >> 1);
    v1397[v1498] = v1499;
    int * v1399 = v1304->cache_dirty;
    v1399[v1498] = 0;
    int * v1401 = v1304->cache_age;
    v1401[v1498] = 1;
    int * v1403 = v1304->cache_age;
    int v1404 = v1403[v1498];
    int v1405 = v1403[v1427];
    int v1505 = v1405 + ((int)((unsigned int)(v1405 - v1404) >> 31));
    v1403[v1427] = v1505;
    int * v1407 = v1304->cache_age;
    int v1408 = v1407[v1428];
    int v1507 = v1408 + ((int)((unsigned int)(v1408 - v1404) >> 31));
    v1407[v1428] = v1507;
    int * v1410 = v1304->cache_age;
    v1410[v1498] = 0;
    v1413 = v1498;
  }
  int v1510 = (v1413 * 2) + (((int)((unsigned int)v1312 >> 2)) & 1);
  int v1414 = v1320[v1510];
  int * v1415 = v1304->regs;
  v1415[14] = v1414;
  struct StateT * v1417 = slot_36(v1304);
  return v1417;
}

struct StateT * slot_6(struct StateT * v92) {
  int v93 = v92->timer;
  int v100 = v93 + 1;
  v92->timer = v100;
  int * v95 = v92->regs;
  int v96 = v95[13];
  v95[13] = v96;
  struct StateT * v98 = slot_7(v92);
  return v98;
}

struct StateT * slot_29(struct StateT * v1211) {
  int * v1212 = v1211->saved_regs;
  int * v1213 = v1211->regs;
  int v1214 = v1213[13];
  v1212[13] = v1214;
  int v1216 = v1211->timer;
  int v1227 = v1216 + 1;
  v1211->timer = v1227;
  int * v1218 = v1211->regs;
  int v1219 = v1218[13];
  int v1229 = v1219 + 4;
  v1218[13] = v1229;
  struct StateT * v1221 = slot_30(v1211);
  return v1221;
}

struct StateT * slot_16(struct StateT * v656) {
  int * v657 = v656->regs;
  int v658 = v657[14];
  int v659 = v657[15];
  bool v683 = !(v658 == v659);
  struct StateT * v678;
  if (v683) {
    int v660 = v656->timer;
    int v684 = v660 + 15;
    v656->timer = v684;
    int * v662 = v656->saved_regs;
    int v663 = v662[11];
    int * v664 = v656->regs;
    v664[11] = v663;
    int * v666 = v656->saved_regs;
    int v667 = v666[12];
    int * v668 = v656->regs;
    v668[12] = v667;
    int * v670 = v656->saved_regs;
    int v671 = v670[13];
    int * v672 = v656->regs;
    v672[13] = v671;
    struct StateT * v674 = slot_31(v656);
    v678 = v674;
  } else {
    struct StateT * v676 = slot_18(v656);
    v678 = v676;
  }
  return v678;
}

struct StateT * slot_23(struct StateT * v952) {
  int v953 = v952->timer;
  int v956 = v953 + 1;
  v952->timer = v956;
  return v952;
}

struct StateT * slot_5(struct StateT * v72) {
  int * v73 = v72->saved_regs;
  int * v74 = v72->regs;
  int v75 = v74[13];
  v73[13] = v75;
  int v77 = v72->timer;
  int v87 = v77 + 1;
  v72->timer = v87;
  int * v79 = v72->regs;
  v79[13] = 0;
  struct StateT * v81 = slot_6(v72);
  return v81;
}

struct StateT * slot_2(struct StateT * v30) {
  int v31 = v30->timer;
  int v35 = v31 + 1;
  v30->timer = v35;
  struct StateT * v33 = slot_3(v30);
  return v33;
}

struct StateT * slot_7(struct StateT * v106) {
  int * v107 = v106->saved_regs;
  int * v108 = v106->regs;
  int v109 = v108[14];
  v107[14] = v109;
  int v111 = v106->timer;
  int v225 = v111 + 1;
  v106->timer = v225;
  int * v113 = v106->regs;
  int v114 = v113[12];
  int * v115 = v106->cache_tags;
  int v229 = (((int)((unsigned int)((int)((unsigned int)v114 >> 2)) >> 1)) & 1) * 2;
  int v116 = v115[v229];
  int v230 = ((((int)((unsigned int)((int)((unsigned int)v114 >> 2)) >> 1)) & 1) * 2) + 1;
  int v117 = v115[v230];
  int v231 = 4 + ((((int)((unsigned int)((int)((unsigned int)v114 >> 2)) >> 1)) & 3) * 2);
  int v118 = v115[v231];
  int v232 = (4 + ((((int)((unsigned int)((int)((unsigned int)v114 >> 2)) >> 1)) & 3) * 2)) + 1;
  int v119 = v115[v232];
  int v120 = v106->timer;
  int v233 = v120 + ((100 ^ (((~(((v118 ^ ((int)((unsigned int)((int)((unsigned int)v114 >> 2)) >> 1))) | (-(v118 ^ ((int)((unsigned int)((int)((unsigned int)v114 >> 2)) >> 1))))) >> 31)) | (~(((v119 ^ ((int)((unsigned int)((int)((unsigned int)v114 >> 2)) >> 1))) | (-(v119 ^ ((int)((unsigned int)((int)((unsigned int)v114 >> 2)) >> 1))))) >> 31))) & 104)) ^ (((~(((v116 ^ ((int)((unsigned int)((int)((unsigned int)v114 >> 2)) >> 1))) | (-(v116 ^ ((int)((unsigned int)((int)((unsigned int)v114 >> 2)) >> 1))))) >> 31)) | (~(((v117 ^ ((int)((unsigned int)((int)((unsigned int)v114 >> 2)) >> 1))) | (-(v117 ^ ((int)((unsigned int)((int)((unsigned int)v114 >> 2)) >> 1))))) >> 31))) & (1 ^ (100 ^ (((~(((v118 ^ ((int)((unsigned int)((int)((unsigned int)v114 >> 2)) >> 1))) | (-(v118 ^ ((int)((unsigned int)((int)((unsigned int)v114 >> 2)) >> 1))))) >> 31)) | (~(((v119 ^ ((int)((unsigned int)((int)((unsigned int)v114 >> 2)) >> 1))) | (-(v119 ^ ((int)((unsigned int)((int)((unsigned int)v114 >> 2)) >> 1))))) >> 31))) & 104)))));
  v106->timer = v233;
  int * v122 = v106->cache_vals;
  bool v234 = !(((~(((v116 ^ ((int)((unsigned int)((int)((unsigned int)v114 >> 2)) >> 1))) | (-(v116 ^ ((int)((unsigned int)((int)((unsigned int)v114 >> 2)) >> 1))))) >> 31)) | (~(((v117 ^ ((int)((unsigned int)((int)((unsigned int)v114 >> 2)) >> 1))) | (-(v117 ^ ((int)((unsigned int)((int)((unsigned int)v114 >> 2)) >> 1))))) >> 31))) == 0);
  int v215;
  if (v234) {
    int * v123 = v106->cache_age;
    int v236 = ((((int)((unsigned int)((int)((unsigned int)v114 >> 2)) >> 1)) & 1) * 2) + ((~(((v117 ^ ((int)((unsigned int)((int)((unsigned int)v114 >> 2)) >> 1))) | (-(v117 ^ ((int)((unsigned int)((int)((unsigned int)v114 >> 2)) >> 1))))) >> 31)) & 1);
    int v124 = v123[v236];
    int v125 = v123[v229];
    int v237 = v125 + ((int)((unsigned int)(v125 - v124) >> 31));
    v123[v229] = v237;
    int * v127 = v106->cache_age;
    int v128 = v127[v230];
    int v239 = v128 + ((int)((unsigned int)(v128 - v124) >> 31));
    v127[v230] = v239;
    int * v130 = v106->cache_age;
    v130[v236] = 0;
    v215 = v236;
  } else {
    int * v133 = v106->cache_age;
    int v243 = (((int)((unsigned int)((int)((unsigned int)v114 >> 2)) >> 1)) & 1) * 2;
    int v134 = v133[v243];
    int * v135 = v106->cache_tags;
    int v136 = v135[v243];
    int v137 = v133[v230];
    int v138 = v135[v230];
    bool v245 = !(((~(((v118 ^ ((int)((unsigned int)((int)((unsigned int)v114 >> 2)) >> 1))) | (-(v118 ^ ((int)((unsigned int)((int)((unsigned int)v114 >> 2)) >> 1))))) >> 31)) | (~(((v119 ^ ((int)((unsigned int)((int)((unsigned int)v114 >> 2)) >> 1))) | (-(v119 ^ ((int)((unsigned int)((int)((unsigned int)v114 >> 2)) >> 1))))) >> 31))) == 0);
    int v192;
    if (v245) {
      int * v139 = v106->cache_age;
      int v247 = (4 + ((((int)((unsigned int)((int)((unsigned int)v114 >> 2)) >> 1)) & 3) * 2)) + ((~(((v119 ^ ((int)((unsigned int)((int)((unsigned int)v114 >> 2)) >> 1))) | (-(v119 ^ ((int)((unsigned int)((int)((unsigned int)v114 >> 2)) >> 1))))) >> 31)) & 1);
      int v140 = v139[v247];
      int v141 = v139[v231];
      int v248 = v141 + ((int)((unsigned int)(v141 - v140) >> 31));
      v139[v231] = v248;
      int * v143 = v106->cache_age;
      int v144 = v143[v232];
      int v250 = v144 + ((int)((unsigned int)(v144 - v140) >> 31));
      v143[v232] = v250;
      int * v146 = v106->cache_age;
      v146[v247] = 0;
      v192 = v247;
    } else {
      int * v149 = v106->cache_age;
      int v254 = 4 + ((((int)((unsigned int)((int)((unsigned int)v114 >> 2)) >> 1)) & 3) * 2);
      int v150 = v149[v254];
      int * v151 = v106->cache_tags;
      int v152 = v151[v254];
      int v153 = v149[v232];
      int v154 = v151[v232];
      int * v155 = v106->cache_dirty;
      int v257 = (4 + ((((int)((unsigned int)((int)((unsigned int)v114 >> 2)) >> 1)) & 3) * 2)) + ((((v150 + ((~(((v152 ^ -1) | (-(v152 ^ -1))) >> 31)) & 2)) - (v153 + ((~(((v154 ^ -1) | (-(v154 ^ -1))) >> 31)) & 2))) >> 31) & 1);
      int v156 = v155[v257];
      bool v258 = !(v156 == 0);
      if (v258) {
        int * v157 = v106->cache_tags;
        int v158 = v157[v257];
        int * v159 = v106->cache_vals;
        int v261 = ((4 + ((((int)((unsigned int)((int)((unsigned int)v114 >> 2)) >> 1)) & 3) * 2)) + ((((v150 + ((~(((v152 ^ -1) | (-(v152 ^ -1))) >> 31)) & 2)) - (v153 + ((~(((v154 ^ -1) | (-(v154 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
        int v160 = v159[v261];
        int v262 = (((4 + ((((int)((unsigned int)((int)((unsigned int)v114 >> 2)) >> 1)) & 3) * 2)) + ((((v150 + ((~(((v152 ^ -1) | (-(v152 ^ -1))) >> 31)) & 2)) - (v153 + ((~(((v154 ^ -1) | (-(v154 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
        int v161 = v159[v262];
        int * v162 = v106->mem;
        int v264 = v158 * 2;
        v162[v264] = v160;
        int * v164 = v106->mem;
        int v267 = (v158 * 2) + 1;
        v164[v267] = v161;
        ;
      } else {
        ;
      }
      int * v169 = v106->mem;
      int v272 = ((int)((unsigned int)((int)((unsigned int)v114 >> 2)) >> 1)) * 2;
      int v170 = v169[v272];
      int v273 = (((int)((unsigned int)((int)((unsigned int)v114 >> 2)) >> 1)) * 2) + 1;
      int v171 = v169[v273];
      int * v172 = v106->cache_vals;
      int v275 = ((4 + ((((int)((unsigned int)((int)((unsigned int)v114 >> 2)) >> 1)) & 3) * 2)) + ((((v150 + ((~(((v152 ^ -1) | (-(v152 ^ -1))) >> 31)) & 2)) - (v153 + ((~(((v154 ^ -1) | (-(v154 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
      v172[v275] = v170;
      int * v174 = v106->cache_vals;
      int v278 = (((4 + ((((int)((unsigned int)((int)((unsigned int)v114 >> 2)) >> 1)) & 3) * 2)) + ((((v150 + ((~(((v152 ^ -1) | (-(v152 ^ -1))) >> 31)) & 2)) - (v153 + ((~(((v154 ^ -1) | (-(v154 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
      v174[v278] = v171;
      int * v176 = v106->cache_tags;
      int v281 = (int)((unsigned int)((int)((unsigned int)v114 >> 2)) >> 1);
      v176[v257] = v281;
      int * v178 = v106->cache_dirty;
      v178[v257] = 0;
      int * v180 = v106->cache_age;
      v180[v257] = 1;
      int * v182 = v106->cache_age;
      int v183 = v182[v257];
      int v184 = v182[v231];
      int v287 = v184 + ((int)((unsigned int)(v184 - v183) >> 31));
      v182[v231] = v287;
      int * v186 = v106->cache_age;
      int v187 = v186[v232];
      int v289 = v187 + ((int)((unsigned int)(v187 - v183) >> 31));
      v186[v232] = v289;
      int * v189 = v106->cache_age;
      v189[v257] = 0;
      v192 = v257;
    }
    int * v193 = v106->cache_vals;
    int v292 = v192 * 2;
    int v194 = v193[v292];
    int v293 = (v192 * 2) + 1;
    int v195 = v193[v293];
    int v294 = (((((int)((unsigned int)((int)((unsigned int)v114 >> 2)) >> 1)) & 1) * 2) + ((((v134 + ((~(((v136 ^ -1) | (-(v136 ^ -1))) >> 31)) & 2)) - (v137 + ((~(((v138 ^ -1) | (-(v138 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
    v193[v294] = v194;
    int * v197 = v106->cache_vals;
    int v297 = ((((((int)((unsigned int)((int)((unsigned int)v114 >> 2)) >> 1)) & 1) * 2) + ((((v134 + ((~(((v136 ^ -1) | (-(v136 ^ -1))) >> 31)) & 2)) - (v137 + ((~(((v138 ^ -1) | (-(v138 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
    v197[v297] = v195;
    int * v199 = v106->cache_tags;
    int v300 = ((((int)((unsigned int)((int)((unsigned int)v114 >> 2)) >> 1)) & 1) * 2) + ((((v134 + ((~(((v136 ^ -1) | (-(v136 ^ -1))) >> 31)) & 2)) - (v137 + ((~(((v138 ^ -1) | (-(v138 ^ -1))) >> 31)) & 2))) >> 31) & 1);
    int v301 = (int)((unsigned int)((int)((unsigned int)v114 >> 2)) >> 1);
    v199[v300] = v301;
    int * v201 = v106->cache_dirty;
    v201[v300] = 0;
    int * v203 = v106->cache_age;
    v203[v300] = 1;
    int * v205 = v106->cache_age;
    int v206 = v205[v300];
    int v207 = v205[v229];
    int v307 = v207 + ((int)((unsigned int)(v207 - v206) >> 31));
    v205[v229] = v307;
    int * v209 = v106->cache_age;
    int v210 = v209[v230];
    int v309 = v210 + ((int)((unsigned int)(v210 - v206) >> 31));
    v209[v230] = v309;
    int * v212 = v106->cache_age;
    v212[v300] = 0;
    v215 = v300;
  }
  int v312 = (v215 * 2) + (((int)((unsigned int)v114 >> 2)) & 1);
  int v216 = v122[v312];
  int * v217 = v106->regs;
  v217[14] = v216;
  struct StateT * v219 = slot_8(v106);
  return v219;
}

struct StateT * slot_31(struct StateT * v1278) {
  int v1279 = v1278->timer;
  int v1285 = v1279 + 1;
  v1278->timer = v1285;
  int * v1281 = v1278->regs;
  v1281[10] = 0;
  struct StateT * v1283 = slot_23(v1278);
  return v1283;
}

struct StateT * slot_3(struct StateT * v38) {
  int * v39 = v38->saved_regs;
  int * v40 = v38->regs;
  int v41 = v40[12];
  v39[12] = v41;
  int v43 = v38->timer;
  int v53 = v43 + 1;
  v38->timer = v53;
  int * v45 = v38->regs;
  v45[12] = 0;
  struct StateT * v47 = slot_4(v38);
  return v47;
}

struct StateT * slot_26(struct StateT * v1161) {
  int v1162 = v1161->timer;
  int v1166 = v1162 + 1;
  v1161->timer = v1166;
  struct StateT * v1164 = slot_27(v1161);
  return v1164;
}

struct StateT * slot_1(struct StateT * v17) {
  int v18 = v17->timer;
  int v24 = v18 + 1;
  v17->timer = v24;
  int * v20 = v17->regs;
  v20[10] = 1;
  struct StateT * v22 = slot_2(v17);
  return v22;
}

struct StateT * slot_13(struct StateT * v593) {
  int * v594 = v593->saved_regs;
  int * v595 = v593->regs;
  int v596 = v595[11];
  v594[11] = v596;
  int v598 = v593->timer;
  int v609 = v598 + 1;
  v593->timer = v609;
  int * v600 = v593->regs;
  int v601 = v600[11];
  int v611 = v601 + -1;
  v600[11] = v611;
  struct StateT * v603 = slot_14(v593);
  return v603;
}

struct StateT * slot_24(struct StateT * v957) {
  int v958 = v957->timer;
  int v1068 = v958 + 1;
  v957->timer = v1068;
  int * v960 = v957->regs;
  int v961 = v960[13];
  int * v962 = v957->cache_tags;
  int v1072 = (((int)((unsigned int)((int)((unsigned int)v961 >> 2)) >> 1)) & 1) * 2;
  int v963 = v962[v1072];
  int v1073 = ((((int)((unsigned int)((int)((unsigned int)v961 >> 2)) >> 1)) & 1) * 2) + 1;
  int v964 = v962[v1073];
  int v1074 = 4 + ((((int)((unsigned int)((int)((unsigned int)v961 >> 2)) >> 1)) & 3) * 2);
  int v965 = v962[v1074];
  int v1075 = (4 + ((((int)((unsigned int)((int)((unsigned int)v961 >> 2)) >> 1)) & 3) * 2)) + 1;
  int v966 = v962[v1075];
  int v967 = v957->timer;
  int v1076 = v967 + ((100 ^ (((~(((v965 ^ ((int)((unsigned int)((int)((unsigned int)v961 >> 2)) >> 1))) | (-(v965 ^ ((int)((unsigned int)((int)((unsigned int)v961 >> 2)) >> 1))))) >> 31)) | (~(((v966 ^ ((int)((unsigned int)((int)((unsigned int)v961 >> 2)) >> 1))) | (-(v966 ^ ((int)((unsigned int)((int)((unsigned int)v961 >> 2)) >> 1))))) >> 31))) & 104)) ^ (((~(((v963 ^ ((int)((unsigned int)((int)((unsigned int)v961 >> 2)) >> 1))) | (-(v963 ^ ((int)((unsigned int)((int)((unsigned int)v961 >> 2)) >> 1))))) >> 31)) | (~(((v964 ^ ((int)((unsigned int)((int)((unsigned int)v961 >> 2)) >> 1))) | (-(v964 ^ ((int)((unsigned int)((int)((unsigned int)v961 >> 2)) >> 1))))) >> 31))) & (1 ^ (100 ^ (((~(((v965 ^ ((int)((unsigned int)((int)((unsigned int)v961 >> 2)) >> 1))) | (-(v965 ^ ((int)((unsigned int)((int)((unsigned int)v961 >> 2)) >> 1))))) >> 31)) | (~(((v966 ^ ((int)((unsigned int)((int)((unsigned int)v961 >> 2)) >> 1))) | (-(v966 ^ ((int)((unsigned int)((int)((unsigned int)v961 >> 2)) >> 1))))) >> 31))) & 104)))));
  v957->timer = v1076;
  int * v969 = v957->cache_vals;
  bool v1077 = !(((~(((v963 ^ ((int)((unsigned int)((int)((unsigned int)v961 >> 2)) >> 1))) | (-(v963 ^ ((int)((unsigned int)((int)((unsigned int)v961 >> 2)) >> 1))))) >> 31)) | (~(((v964 ^ ((int)((unsigned int)((int)((unsigned int)v961 >> 2)) >> 1))) | (-(v964 ^ ((int)((unsigned int)((int)((unsigned int)v961 >> 2)) >> 1))))) >> 31))) == 0);
  int v1062;
  if (v1077) {
    int * v970 = v957->cache_age;
    int v1079 = ((((int)((unsigned int)((int)((unsigned int)v961 >> 2)) >> 1)) & 1) * 2) + ((~(((v964 ^ ((int)((unsigned int)((int)((unsigned int)v961 >> 2)) >> 1))) | (-(v964 ^ ((int)((unsigned int)((int)((unsigned int)v961 >> 2)) >> 1))))) >> 31)) & 1);
    int v971 = v970[v1079];
    int v972 = v970[v1072];
    int v1080 = v972 + ((int)((unsigned int)(v972 - v971) >> 31));
    v970[v1072] = v1080;
    int * v974 = v957->cache_age;
    int v975 = v974[v1073];
    int v1082 = v975 + ((int)((unsigned int)(v975 - v971) >> 31));
    v974[v1073] = v1082;
    int * v977 = v957->cache_age;
    v977[v1079] = 0;
    v1062 = v1079;
  } else {
    int * v980 = v957->cache_age;
    int v1086 = (((int)((unsigned int)((int)((unsigned int)v961 >> 2)) >> 1)) & 1) * 2;
    int v981 = v980[v1086];
    int * v982 = v957->cache_tags;
    int v983 = v982[v1086];
    int v984 = v980[v1073];
    int v985 = v982[v1073];
    bool v1088 = !(((~(((v965 ^ ((int)((unsigned int)((int)((unsigned int)v961 >> 2)) >> 1))) | (-(v965 ^ ((int)((unsigned int)((int)((unsigned int)v961 >> 2)) >> 1))))) >> 31)) | (~(((v966 ^ ((int)((unsigned int)((int)((unsigned int)v961 >> 2)) >> 1))) | (-(v966 ^ ((int)((unsigned int)((int)((unsigned int)v961 >> 2)) >> 1))))) >> 31))) == 0);
    int v1039;
    if (v1088) {
      int * v986 = v957->cache_age;
      int v1090 = (4 + ((((int)((unsigned int)((int)((unsigned int)v961 >> 2)) >> 1)) & 3) * 2)) + ((~(((v966 ^ ((int)((unsigned int)((int)((unsigned int)v961 >> 2)) >> 1))) | (-(v966 ^ ((int)((unsigned int)((int)((unsigned int)v961 >> 2)) >> 1))))) >> 31)) & 1);
      int v987 = v986[v1090];
      int v988 = v986[v1074];
      int v1091 = v988 + ((int)((unsigned int)(v988 - v987) >> 31));
      v986[v1074] = v1091;
      int * v990 = v957->cache_age;
      int v991 = v990[v1075];
      int v1093 = v991 + ((int)((unsigned int)(v991 - v987) >> 31));
      v990[v1075] = v1093;
      int * v993 = v957->cache_age;
      v993[v1090] = 0;
      v1039 = v1090;
    } else {
      int * v996 = v957->cache_age;
      int v1097 = 4 + ((((int)((unsigned int)((int)((unsigned int)v961 >> 2)) >> 1)) & 3) * 2);
      int v997 = v996[v1097];
      int * v998 = v957->cache_tags;
      int v999 = v998[v1097];
      int v1000 = v996[v1075];
      int v1001 = v998[v1075];
      int * v1002 = v957->cache_dirty;
      int v1100 = (4 + ((((int)((unsigned int)((int)((unsigned int)v961 >> 2)) >> 1)) & 3) * 2)) + ((((v997 + ((~(((v999 ^ -1) | (-(v999 ^ -1))) >> 31)) & 2)) - (v1000 + ((~(((v1001 ^ -1) | (-(v1001 ^ -1))) >> 31)) & 2))) >> 31) & 1);
      int v1003 = v1002[v1100];
      bool v1101 = !(v1003 == 0);
      if (v1101) {
        int * v1004 = v957->cache_tags;
        int v1005 = v1004[v1100];
        int * v1006 = v957->cache_vals;
        int v1104 = ((4 + ((((int)((unsigned int)((int)((unsigned int)v961 >> 2)) >> 1)) & 3) * 2)) + ((((v997 + ((~(((v999 ^ -1) | (-(v999 ^ -1))) >> 31)) & 2)) - (v1000 + ((~(((v1001 ^ -1) | (-(v1001 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
        int v1007 = v1006[v1104];
        int v1105 = (((4 + ((((int)((unsigned int)((int)((unsigned int)v961 >> 2)) >> 1)) & 3) * 2)) + ((((v997 + ((~(((v999 ^ -1) | (-(v999 ^ -1))) >> 31)) & 2)) - (v1000 + ((~(((v1001 ^ -1) | (-(v1001 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
        int v1008 = v1006[v1105];
        int * v1009 = v957->mem;
        int v1107 = v1005 * 2;
        v1009[v1107] = v1007;
        int * v1011 = v957->mem;
        int v1110 = (v1005 * 2) + 1;
        v1011[v1110] = v1008;
        ;
      } else {
        ;
      }
      int * v1016 = v957->mem;
      int v1115 = ((int)((unsigned int)((int)((unsigned int)v961 >> 2)) >> 1)) * 2;
      int v1017 = v1016[v1115];
      int v1116 = (((int)((unsigned int)((int)((unsigned int)v961 >> 2)) >> 1)) * 2) + 1;
      int v1018 = v1016[v1116];
      int * v1019 = v957->cache_vals;
      int v1118 = ((4 + ((((int)((unsigned int)((int)((unsigned int)v961 >> 2)) >> 1)) & 3) * 2)) + ((((v997 + ((~(((v999 ^ -1) | (-(v999 ^ -1))) >> 31)) & 2)) - (v1000 + ((~(((v1001 ^ -1) | (-(v1001 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
      v1019[v1118] = v1017;
      int * v1021 = v957->cache_vals;
      int v1121 = (((4 + ((((int)((unsigned int)((int)((unsigned int)v961 >> 2)) >> 1)) & 3) * 2)) + ((((v997 + ((~(((v999 ^ -1) | (-(v999 ^ -1))) >> 31)) & 2)) - (v1000 + ((~(((v1001 ^ -1) | (-(v1001 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
      v1021[v1121] = v1018;
      int * v1023 = v957->cache_tags;
      int v1124 = (int)((unsigned int)((int)((unsigned int)v961 >> 2)) >> 1);
      v1023[v1100] = v1124;
      int * v1025 = v957->cache_dirty;
      v1025[v1100] = 0;
      int * v1027 = v957->cache_age;
      v1027[v1100] = 1;
      int * v1029 = v957->cache_age;
      int v1030 = v1029[v1100];
      int v1031 = v1029[v1074];
      int v1130 = v1031 + ((int)((unsigned int)(v1031 - v1030) >> 31));
      v1029[v1074] = v1130;
      int * v1033 = v957->cache_age;
      int v1034 = v1033[v1075];
      int v1132 = v1034 + ((int)((unsigned int)(v1034 - v1030) >> 31));
      v1033[v1075] = v1132;
      int * v1036 = v957->cache_age;
      v1036[v1100] = 0;
      v1039 = v1100;
    }
    int * v1040 = v957->cache_vals;
    int v1135 = v1039 * 2;
    int v1041 = v1040[v1135];
    int v1136 = (v1039 * 2) + 1;
    int v1042 = v1040[v1136];
    int v1137 = (((((int)((unsigned int)((int)((unsigned int)v961 >> 2)) >> 1)) & 1) * 2) + ((((v981 + ((~(((v983 ^ -1) | (-(v983 ^ -1))) >> 31)) & 2)) - (v984 + ((~(((v985 ^ -1) | (-(v985 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
    v1040[v1137] = v1041;
    int * v1044 = v957->cache_vals;
    int v1140 = ((((((int)((unsigned int)((int)((unsigned int)v961 >> 2)) >> 1)) & 1) * 2) + ((((v981 + ((~(((v983 ^ -1) | (-(v983 ^ -1))) >> 31)) & 2)) - (v984 + ((~(((v985 ^ -1) | (-(v985 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
    v1044[v1140] = v1042;
    int * v1046 = v957->cache_tags;
    int v1143 = ((((int)((unsigned int)((int)((unsigned int)v961 >> 2)) >> 1)) & 1) * 2) + ((((v981 + ((~(((v983 ^ -1) | (-(v983 ^ -1))) >> 31)) & 2)) - (v984 + ((~(((v985 ^ -1) | (-(v985 ^ -1))) >> 31)) & 2))) >> 31) & 1);
    int v1144 = (int)((unsigned int)((int)((unsigned int)v961 >> 2)) >> 1);
    v1046[v1143] = v1144;
    int * v1048 = v957->cache_dirty;
    v1048[v1143] = 0;
    int * v1050 = v957->cache_age;
    v1050[v1143] = 1;
    int * v1052 = v957->cache_age;
    int v1053 = v1052[v1143];
    int v1054 = v1052[v1072];
    int v1150 = v1054 + ((int)((unsigned int)(v1054 - v1053) >> 31));
    v1052[v1072] = v1150;
    int * v1056 = v957->cache_age;
    int v1057 = v1056[v1073];
    int v1152 = v1057 + ((int)((unsigned int)(v1057 - v1053) >> 31));
    v1056[v1073] = v1152;
    int * v1059 = v957->cache_age;
    v1059[v1143] = 0;
    v1062 = v1143;
  }
  int v1155 = (v1062 * 2) + (((int)((unsigned int)v961 >> 2)) & 1);
  int v1063 = v969[v1155];
  int * v1064 = v957->regs;
  v1064[15] = v1063;
  struct StateT * v1066 = slot_26(v957);
  return v1066;
}

struct StateT * slot_0(struct StateT * v2) {
  int v3 = v2->timer;
  int v10 = v3 + 1;
  v2->timer = v10;
  int * v5 = v2->regs;
  int v6 = v5[10];
  v5[11] = v6;
  struct StateT * v8 = slot_1(v2);
  return v8;
}

struct StateT * slot_14(struct StateT * v614) {
  int * v615 = v614->saved_regs;
  int * v616 = v614->regs;
  int v617 = v616[12];
  v615[12] = v617;
  int v619 = v614->timer;
  int v630 = v619 + 1;
  v614->timer = v630;
  int * v621 = v614->regs;
  int v622 = v621[12];
  int v632 = v622 + 4;
  v621[12] = v632;
  struct StateT * v624 = slot_15(v614);
  return v624;
}

struct StateT * slot_28(struct StateT * v1190) {
  int * v1191 = v1190->saved_regs;
  int * v1192 = v1190->regs;
  int v1193 = v1192[12];
  v1191[12] = v1193;
  int v1195 = v1190->timer;
  int v1206 = v1195 + 1;
  v1190->timer = v1206;
  int * v1197 = v1190->regs;
  int v1198 = v1197[12];
  int v1208 = v1198 + 4;
  v1197[12] = v1208;
  struct StateT * v1200 = slot_29(v1190);
  return v1200;
}

struct StateT * slot_32(struct StateT * v1291) {
  int v1292 = v1291->timer;
  int v1296 = v1292 + 1;
  v1291->timer = v1296;
  struct StateT * v1294 = slot_34(v1291);
  return v1294;
}

struct StateT * slot_20(struct StateT * v728) {
  int * v729 = v728->regs;
  int v730 = v729[11];
  bool v741 = !(v730 == 0);
  struct StateT * v737;
  if (v741) {
    int v731 = v728->timer;
    int v742 = v731 + 15;
    v728->timer = v742;
    struct StateT * v733 = slot_22(v728);
    v737 = v733;
  } else {
    struct StateT * v735 = slot_23(v728);
    v737 = v735;
  }
  return v737;
}

struct StateT * slot_36(struct StateT * v1515) {
  int * v1516 = v1515->saved_regs;
  int * v1517 = v1515->regs;
  int v1518 = v1517[15];
  v1516[15] = v1518;
  int v1520 = v1515->timer;
  int v1634 = v1520 + 1;
  v1515->timer = v1634;
  int * v1522 = v1515->regs;
  int v1523 = v1522[13];
  int * v1524 = v1515->cache_tags;
  int v1638 = (((int)((unsigned int)((int)((unsigned int)v1523 >> 2)) >> 1)) & 1) * 2;
  int v1525 = v1524[v1638];
  int v1639 = ((((int)((unsigned int)((int)((unsigned int)v1523 >> 2)) >> 1)) & 1) * 2) + 1;
  int v1526 = v1524[v1639];
  int v1640 = 4 + ((((int)((unsigned int)((int)((unsigned int)v1523 >> 2)) >> 1)) & 3) * 2);
  int v1527 = v1524[v1640];
  int v1641 = (4 + ((((int)((unsigned int)((int)((unsigned int)v1523 >> 2)) >> 1)) & 3) * 2)) + 1;
  int v1528 = v1524[v1641];
  int v1529 = v1515->timer;
  int v1642 = v1529 + ((100 ^ (((~(((v1527 ^ ((int)((unsigned int)((int)((unsigned int)v1523 >> 2)) >> 1))) | (-(v1527 ^ ((int)((unsigned int)((int)((unsigned int)v1523 >> 2)) >> 1))))) >> 31)) | (~(((v1528 ^ ((int)((unsigned int)((int)((unsigned int)v1523 >> 2)) >> 1))) | (-(v1528 ^ ((int)((unsigned int)((int)((unsigned int)v1523 >> 2)) >> 1))))) >> 31))) & 104)) ^ (((~(((v1525 ^ ((int)((unsigned int)((int)((unsigned int)v1523 >> 2)) >> 1))) | (-(v1525 ^ ((int)((unsigned int)((int)((unsigned int)v1523 >> 2)) >> 1))))) >> 31)) | (~(((v1526 ^ ((int)((unsigned int)((int)((unsigned int)v1523 >> 2)) >> 1))) | (-(v1526 ^ ((int)((unsigned int)((int)((unsigned int)v1523 >> 2)) >> 1))))) >> 31))) & (1 ^ (100 ^ (((~(((v1527 ^ ((int)((unsigned int)((int)((unsigned int)v1523 >> 2)) >> 1))) | (-(v1527 ^ ((int)((unsigned int)((int)((unsigned int)v1523 >> 2)) >> 1))))) >> 31)) | (~(((v1528 ^ ((int)((unsigned int)((int)((unsigned int)v1523 >> 2)) >> 1))) | (-(v1528 ^ ((int)((unsigned int)((int)((unsigned int)v1523 >> 2)) >> 1))))) >> 31))) & 104)))));
  v1515->timer = v1642;
  int * v1531 = v1515->cache_vals;
  bool v1643 = !(((~(((v1525 ^ ((int)((unsigned int)((int)((unsigned int)v1523 >> 2)) >> 1))) | (-(v1525 ^ ((int)((unsigned int)((int)((unsigned int)v1523 >> 2)) >> 1))))) >> 31)) | (~(((v1526 ^ ((int)((unsigned int)((int)((unsigned int)v1523 >> 2)) >> 1))) | (-(v1526 ^ ((int)((unsigned int)((int)((unsigned int)v1523 >> 2)) >> 1))))) >> 31))) == 0);
  int v1624;
  if (v1643) {
    int * v1532 = v1515->cache_age;
    int v1645 = ((((int)((unsigned int)((int)((unsigned int)v1523 >> 2)) >> 1)) & 1) * 2) + ((~(((v1526 ^ ((int)((unsigned int)((int)((unsigned int)v1523 >> 2)) >> 1))) | (-(v1526 ^ ((int)((unsigned int)((int)((unsigned int)v1523 >> 2)) >> 1))))) >> 31)) & 1);
    int v1533 = v1532[v1645];
    int v1534 = v1532[v1638];
    int v1646 = v1534 + ((int)((unsigned int)(v1534 - v1533) >> 31));
    v1532[v1638] = v1646;
    int * v1536 = v1515->cache_age;
    int v1537 = v1536[v1639];
    int v1648 = v1537 + ((int)((unsigned int)(v1537 - v1533) >> 31));
    v1536[v1639] = v1648;
    int * v1539 = v1515->cache_age;
    v1539[v1645] = 0;
    v1624 = v1645;
  } else {
    int * v1542 = v1515->cache_age;
    int v1652 = (((int)((unsigned int)((int)((unsigned int)v1523 >> 2)) >> 1)) & 1) * 2;
    int v1543 = v1542[v1652];
    int * v1544 = v1515->cache_tags;
    int v1545 = v1544[v1652];
    int v1546 = v1542[v1639];
    int v1547 = v1544[v1639];
    bool v1654 = !(((~(((v1527 ^ ((int)((unsigned int)((int)((unsigned int)v1523 >> 2)) >> 1))) | (-(v1527 ^ ((int)((unsigned int)((int)((unsigned int)v1523 >> 2)) >> 1))))) >> 31)) | (~(((v1528 ^ ((int)((unsigned int)((int)((unsigned int)v1523 >> 2)) >> 1))) | (-(v1528 ^ ((int)((unsigned int)((int)((unsigned int)v1523 >> 2)) >> 1))))) >> 31))) == 0);
    int v1601;
    if (v1654) {
      int * v1548 = v1515->cache_age;
      int v1656 = (4 + ((((int)((unsigned int)((int)((unsigned int)v1523 >> 2)) >> 1)) & 3) * 2)) + ((~(((v1528 ^ ((int)((unsigned int)((int)((unsigned int)v1523 >> 2)) >> 1))) | (-(v1528 ^ ((int)((unsigned int)((int)((unsigned int)v1523 >> 2)) >> 1))))) >> 31)) & 1);
      int v1549 = v1548[v1656];
      int v1550 = v1548[v1640];
      int v1657 = v1550 + ((int)((unsigned int)(v1550 - v1549) >> 31));
      v1548[v1640] = v1657;
      int * v1552 = v1515->cache_age;
      int v1553 = v1552[v1641];
      int v1659 = v1553 + ((int)((unsigned int)(v1553 - v1549) >> 31));
      v1552[v1641] = v1659;
      int * v1555 = v1515->cache_age;
      v1555[v1656] = 0;
      v1601 = v1656;
    } else {
      int * v1558 = v1515->cache_age;
      int v1663 = 4 + ((((int)((unsigned int)((int)((unsigned int)v1523 >> 2)) >> 1)) & 3) * 2);
      int v1559 = v1558[v1663];
      int * v1560 = v1515->cache_tags;
      int v1561 = v1560[v1663];
      int v1562 = v1558[v1641];
      int v1563 = v1560[v1641];
      int * v1564 = v1515->cache_dirty;
      int v1666 = (4 + ((((int)((unsigned int)((int)((unsigned int)v1523 >> 2)) >> 1)) & 3) * 2)) + ((((v1559 + ((~(((v1561 ^ -1) | (-(v1561 ^ -1))) >> 31)) & 2)) - (v1562 + ((~(((v1563 ^ -1) | (-(v1563 ^ -1))) >> 31)) & 2))) >> 31) & 1);
      int v1565 = v1564[v1666];
      bool v1667 = !(v1565 == 0);
      if (v1667) {
        int * v1566 = v1515->cache_tags;
        int v1567 = v1566[v1666];
        int * v1568 = v1515->cache_vals;
        int v1670 = ((4 + ((((int)((unsigned int)((int)((unsigned int)v1523 >> 2)) >> 1)) & 3) * 2)) + ((((v1559 + ((~(((v1561 ^ -1) | (-(v1561 ^ -1))) >> 31)) & 2)) - (v1562 + ((~(((v1563 ^ -1) | (-(v1563 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
        int v1569 = v1568[v1670];
        int v1671 = (((4 + ((((int)((unsigned int)((int)((unsigned int)v1523 >> 2)) >> 1)) & 3) * 2)) + ((((v1559 + ((~(((v1561 ^ -1) | (-(v1561 ^ -1))) >> 31)) & 2)) - (v1562 + ((~(((v1563 ^ -1) | (-(v1563 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
        int v1570 = v1568[v1671];
        int * v1571 = v1515->mem;
        int v1673 = v1567 * 2;
        v1571[v1673] = v1569;
        int * v1573 = v1515->mem;
        int v1676 = (v1567 * 2) + 1;
        v1573[v1676] = v1570;
        ;
      } else {
        ;
      }
      int * v1578 = v1515->mem;
      int v1681 = ((int)((unsigned int)((int)((unsigned int)v1523 >> 2)) >> 1)) * 2;
      int v1579 = v1578[v1681];
      int v1682 = (((int)((unsigned int)((int)((unsigned int)v1523 >> 2)) >> 1)) * 2) + 1;
      int v1580 = v1578[v1682];
      int * v1581 = v1515->cache_vals;
      int v1684 = ((4 + ((((int)((unsigned int)((int)((unsigned int)v1523 >> 2)) >> 1)) & 3) * 2)) + ((((v1559 + ((~(((v1561 ^ -1) | (-(v1561 ^ -1))) >> 31)) & 2)) - (v1562 + ((~(((v1563 ^ -1) | (-(v1563 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
      v1581[v1684] = v1579;
      int * v1583 = v1515->cache_vals;
      int v1687 = (((4 + ((((int)((unsigned int)((int)((unsigned int)v1523 >> 2)) >> 1)) & 3) * 2)) + ((((v1559 + ((~(((v1561 ^ -1) | (-(v1561 ^ -1))) >> 31)) & 2)) - (v1562 + ((~(((v1563 ^ -1) | (-(v1563 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
      v1583[v1687] = v1580;
      int * v1585 = v1515->cache_tags;
      int v1690 = (int)((unsigned int)((int)((unsigned int)v1523 >> 2)) >> 1);
      v1585[v1666] = v1690;
      int * v1587 = v1515->cache_dirty;
      v1587[v1666] = 0;
      int * v1589 = v1515->cache_age;
      v1589[v1666] = 1;
      int * v1591 = v1515->cache_age;
      int v1592 = v1591[v1666];
      int v1593 = v1591[v1640];
      int v1696 = v1593 + ((int)((unsigned int)(v1593 - v1592) >> 31));
      v1591[v1640] = v1696;
      int * v1595 = v1515->cache_age;
      int v1596 = v1595[v1641];
      int v1698 = v1596 + ((int)((unsigned int)(v1596 - v1592) >> 31));
      v1595[v1641] = v1698;
      int * v1598 = v1515->cache_age;
      v1598[v1666] = 0;
      v1601 = v1666;
    }
    int * v1602 = v1515->cache_vals;
    int v1701 = v1601 * 2;
    int v1603 = v1602[v1701];
    int v1702 = (v1601 * 2) + 1;
    int v1604 = v1602[v1702];
    int v1703 = (((((int)((unsigned int)((int)((unsigned int)v1523 >> 2)) >> 1)) & 1) * 2) + ((((v1543 + ((~(((v1545 ^ -1) | (-(v1545 ^ -1))) >> 31)) & 2)) - (v1546 + ((~(((v1547 ^ -1) | (-(v1547 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
    v1602[v1703] = v1603;
    int * v1606 = v1515->cache_vals;
    int v1706 = ((((((int)((unsigned int)((int)((unsigned int)v1523 >> 2)) >> 1)) & 1) * 2) + ((((v1543 + ((~(((v1545 ^ -1) | (-(v1545 ^ -1))) >> 31)) & 2)) - (v1546 + ((~(((v1547 ^ -1) | (-(v1547 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
    v1606[v1706] = v1604;
    int * v1608 = v1515->cache_tags;
    int v1709 = ((((int)((unsigned int)((int)((unsigned int)v1523 >> 2)) >> 1)) & 1) * 2) + ((((v1543 + ((~(((v1545 ^ -1) | (-(v1545 ^ -1))) >> 31)) & 2)) - (v1546 + ((~(((v1547 ^ -1) | (-(v1547 ^ -1))) >> 31)) & 2))) >> 31) & 1);
    int v1710 = (int)((unsigned int)((int)((unsigned int)v1523 >> 2)) >> 1);
    v1608[v1709] = v1710;
    int * v1610 = v1515->cache_dirty;
    v1610[v1709] = 0;
    int * v1612 = v1515->cache_age;
    v1612[v1709] = 1;
    int * v1614 = v1515->cache_age;
    int v1615 = v1614[v1709];
    int v1616 = v1614[v1638];
    int v1716 = v1616 + ((int)((unsigned int)(v1616 - v1615) >> 31));
    v1614[v1638] = v1716;
    int * v1618 = v1515->cache_age;
    int v1619 = v1618[v1639];
    int v1718 = v1619 + ((int)((unsigned int)(v1619 - v1615) >> 31));
    v1618[v1639] = v1718;
    int * v1621 = v1515->cache_age;
    v1621[v1709] = 0;
    v1624 = v1709;
  }
  int v1721 = (v1624 * 2) + (((int)((unsigned int)v1523 >> 2)) & 1);
  int v1625 = v1531[v1721];
  int * v1626 = v1515->regs;
  v1626[15] = v1625;
  struct StateT * v1628 = slot_37(v1515);
  return v1628;
}

struct StateT * slot_37(struct StateT * v1726) {
  int * v1727 = v1726->regs;
  int v1728 = v1727[11];
  bool v1747 = !(v1728 == 0);
  struct StateT * v1743;
  if (v1747) {
    struct StateT * v1729 = slot_26(v1726);
    v1743 = v1729;
  } else {
    int v1731 = v1726->timer;
    int v1750 = v1731 + 15;
    v1726->timer = v1750;
    int * v1733 = v1726->saved_regs;
    int v1734 = v1733[14];
    int * v1735 = v1726->regs;
    v1735[14] = v1734;
    int * v1737 = v1726->saved_regs;
    int v1738 = v1737[15];
    int * v1739 = v1726->regs;
    v1739[15] = v1738;
    struct StateT * v1741 = slot_23(v1726);
    v1743 = v1741;
  }
  return v1743;
}

struct StateT * snippet(struct StateT * v0) {
  struct StateT * v1 = slot_0(v0);
  return v1;
}

struct StateT * slot_8(struct StateT * v317) {
  int * v318 = v317->saved_regs;
  int * v319 = v317->regs;
  int v320 = v319[15];
  v318[15] = v320;
  int v322 = v317->timer;
  int v436 = v322 + 1;
  v317->timer = v436;
  int * v324 = v317->regs;
  int v325 = v324[13];
  int * v326 = v317->cache_tags;
  int v440 = (((int)((unsigned int)((int)((unsigned int)v325 >> 2)) >> 1)) & 1) * 2;
  int v327 = v326[v440];
  int v441 = ((((int)((unsigned int)((int)((unsigned int)v325 >> 2)) >> 1)) & 1) * 2) + 1;
  int v328 = v326[v441];
  int v442 = 4 + ((((int)((unsigned int)((int)((unsigned int)v325 >> 2)) >> 1)) & 3) * 2);
  int v329 = v326[v442];
  int v443 = (4 + ((((int)((unsigned int)((int)((unsigned int)v325 >> 2)) >> 1)) & 3) * 2)) + 1;
  int v330 = v326[v443];
  int v331 = v317->timer;
  int v444 = v331 + ((100 ^ (((~(((v329 ^ ((int)((unsigned int)((int)((unsigned int)v325 >> 2)) >> 1))) | (-(v329 ^ ((int)((unsigned int)((int)((unsigned int)v325 >> 2)) >> 1))))) >> 31)) | (~(((v330 ^ ((int)((unsigned int)((int)((unsigned int)v325 >> 2)) >> 1))) | (-(v330 ^ ((int)((unsigned int)((int)((unsigned int)v325 >> 2)) >> 1))))) >> 31))) & 104)) ^ (((~(((v327 ^ ((int)((unsigned int)((int)((unsigned int)v325 >> 2)) >> 1))) | (-(v327 ^ ((int)((unsigned int)((int)((unsigned int)v325 >> 2)) >> 1))))) >> 31)) | (~(((v328 ^ ((int)((unsigned int)((int)((unsigned int)v325 >> 2)) >> 1))) | (-(v328 ^ ((int)((unsigned int)((int)((unsigned int)v325 >> 2)) >> 1))))) >> 31))) & (1 ^ (100 ^ (((~(((v329 ^ ((int)((unsigned int)((int)((unsigned int)v325 >> 2)) >> 1))) | (-(v329 ^ ((int)((unsigned int)((int)((unsigned int)v325 >> 2)) >> 1))))) >> 31)) | (~(((v330 ^ ((int)((unsigned int)((int)((unsigned int)v325 >> 2)) >> 1))) | (-(v330 ^ ((int)((unsigned int)((int)((unsigned int)v325 >> 2)) >> 1))))) >> 31))) & 104)))));
  v317->timer = v444;
  int * v333 = v317->cache_vals;
  bool v445 = !(((~(((v327 ^ ((int)((unsigned int)((int)((unsigned int)v325 >> 2)) >> 1))) | (-(v327 ^ ((int)((unsigned int)((int)((unsigned int)v325 >> 2)) >> 1))))) >> 31)) | (~(((v328 ^ ((int)((unsigned int)((int)((unsigned int)v325 >> 2)) >> 1))) | (-(v328 ^ ((int)((unsigned int)((int)((unsigned int)v325 >> 2)) >> 1))))) >> 31))) == 0);
  int v426;
  if (v445) {
    int * v334 = v317->cache_age;
    int v447 = ((((int)((unsigned int)((int)((unsigned int)v325 >> 2)) >> 1)) & 1) * 2) + ((~(((v328 ^ ((int)((unsigned int)((int)((unsigned int)v325 >> 2)) >> 1))) | (-(v328 ^ ((int)((unsigned int)((int)((unsigned int)v325 >> 2)) >> 1))))) >> 31)) & 1);
    int v335 = v334[v447];
    int v336 = v334[v440];
    int v448 = v336 + ((int)((unsigned int)(v336 - v335) >> 31));
    v334[v440] = v448;
    int * v338 = v317->cache_age;
    int v339 = v338[v441];
    int v450 = v339 + ((int)((unsigned int)(v339 - v335) >> 31));
    v338[v441] = v450;
    int * v341 = v317->cache_age;
    v341[v447] = 0;
    v426 = v447;
  } else {
    int * v344 = v317->cache_age;
    int v454 = (((int)((unsigned int)((int)((unsigned int)v325 >> 2)) >> 1)) & 1) * 2;
    int v345 = v344[v454];
    int * v346 = v317->cache_tags;
    int v347 = v346[v454];
    int v348 = v344[v441];
    int v349 = v346[v441];
    bool v456 = !(((~(((v329 ^ ((int)((unsigned int)((int)((unsigned int)v325 >> 2)) >> 1))) | (-(v329 ^ ((int)((unsigned int)((int)((unsigned int)v325 >> 2)) >> 1))))) >> 31)) | (~(((v330 ^ ((int)((unsigned int)((int)((unsigned int)v325 >> 2)) >> 1))) | (-(v330 ^ ((int)((unsigned int)((int)((unsigned int)v325 >> 2)) >> 1))))) >> 31))) == 0);
    int v403;
    if (v456) {
      int * v350 = v317->cache_age;
      int v458 = (4 + ((((int)((unsigned int)((int)((unsigned int)v325 >> 2)) >> 1)) & 3) * 2)) + ((~(((v330 ^ ((int)((unsigned int)((int)((unsigned int)v325 >> 2)) >> 1))) | (-(v330 ^ ((int)((unsigned int)((int)((unsigned int)v325 >> 2)) >> 1))))) >> 31)) & 1);
      int v351 = v350[v458];
      int v352 = v350[v442];
      int v459 = v352 + ((int)((unsigned int)(v352 - v351) >> 31));
      v350[v442] = v459;
      int * v354 = v317->cache_age;
      int v355 = v354[v443];
      int v461 = v355 + ((int)((unsigned int)(v355 - v351) >> 31));
      v354[v443] = v461;
      int * v357 = v317->cache_age;
      v357[v458] = 0;
      v403 = v458;
    } else {
      int * v360 = v317->cache_age;
      int v465 = 4 + ((((int)((unsigned int)((int)((unsigned int)v325 >> 2)) >> 1)) & 3) * 2);
      int v361 = v360[v465];
      int * v362 = v317->cache_tags;
      int v363 = v362[v465];
      int v364 = v360[v443];
      int v365 = v362[v443];
      int * v366 = v317->cache_dirty;
      int v468 = (4 + ((((int)((unsigned int)((int)((unsigned int)v325 >> 2)) >> 1)) & 3) * 2)) + ((((v361 + ((~(((v363 ^ -1) | (-(v363 ^ -1))) >> 31)) & 2)) - (v364 + ((~(((v365 ^ -1) | (-(v365 ^ -1))) >> 31)) & 2))) >> 31) & 1);
      int v367 = v366[v468];
      bool v469 = !(v367 == 0);
      if (v469) {
        int * v368 = v317->cache_tags;
        int v369 = v368[v468];
        int * v370 = v317->cache_vals;
        int v472 = ((4 + ((((int)((unsigned int)((int)((unsigned int)v325 >> 2)) >> 1)) & 3) * 2)) + ((((v361 + ((~(((v363 ^ -1) | (-(v363 ^ -1))) >> 31)) & 2)) - (v364 + ((~(((v365 ^ -1) | (-(v365 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
        int v371 = v370[v472];
        int v473 = (((4 + ((((int)((unsigned int)((int)((unsigned int)v325 >> 2)) >> 1)) & 3) * 2)) + ((((v361 + ((~(((v363 ^ -1) | (-(v363 ^ -1))) >> 31)) & 2)) - (v364 + ((~(((v365 ^ -1) | (-(v365 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
        int v372 = v370[v473];
        int * v373 = v317->mem;
        int v475 = v369 * 2;
        v373[v475] = v371;
        int * v375 = v317->mem;
        int v478 = (v369 * 2) + 1;
        v375[v478] = v372;
        ;
      } else {
        ;
      }
      int * v380 = v317->mem;
      int v483 = ((int)((unsigned int)((int)((unsigned int)v325 >> 2)) >> 1)) * 2;
      int v381 = v380[v483];
      int v484 = (((int)((unsigned int)((int)((unsigned int)v325 >> 2)) >> 1)) * 2) + 1;
      int v382 = v380[v484];
      int * v383 = v317->cache_vals;
      int v486 = ((4 + ((((int)((unsigned int)((int)((unsigned int)v325 >> 2)) >> 1)) & 3) * 2)) + ((((v361 + ((~(((v363 ^ -1) | (-(v363 ^ -1))) >> 31)) & 2)) - (v364 + ((~(((v365 ^ -1) | (-(v365 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
      v383[v486] = v381;
      int * v385 = v317->cache_vals;
      int v489 = (((4 + ((((int)((unsigned int)((int)((unsigned int)v325 >> 2)) >> 1)) & 3) * 2)) + ((((v361 + ((~(((v363 ^ -1) | (-(v363 ^ -1))) >> 31)) & 2)) - (v364 + ((~(((v365 ^ -1) | (-(v365 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
      v385[v489] = v382;
      int * v387 = v317->cache_tags;
      int v492 = (int)((unsigned int)((int)((unsigned int)v325 >> 2)) >> 1);
      v387[v468] = v492;
      int * v389 = v317->cache_dirty;
      v389[v468] = 0;
      int * v391 = v317->cache_age;
      v391[v468] = 1;
      int * v393 = v317->cache_age;
      int v394 = v393[v468];
      int v395 = v393[v442];
      int v498 = v395 + ((int)((unsigned int)(v395 - v394) >> 31));
      v393[v442] = v498;
      int * v397 = v317->cache_age;
      int v398 = v397[v443];
      int v500 = v398 + ((int)((unsigned int)(v398 - v394) >> 31));
      v397[v443] = v500;
      int * v400 = v317->cache_age;
      v400[v468] = 0;
      v403 = v468;
    }
    int * v404 = v317->cache_vals;
    int v503 = v403 * 2;
    int v405 = v404[v503];
    int v504 = (v403 * 2) + 1;
    int v406 = v404[v504];
    int v505 = (((((int)((unsigned int)((int)((unsigned int)v325 >> 2)) >> 1)) & 1) * 2) + ((((v345 + ((~(((v347 ^ -1) | (-(v347 ^ -1))) >> 31)) & 2)) - (v348 + ((~(((v349 ^ -1) | (-(v349 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
    v404[v505] = v405;
    int * v408 = v317->cache_vals;
    int v508 = ((((((int)((unsigned int)((int)((unsigned int)v325 >> 2)) >> 1)) & 1) * 2) + ((((v345 + ((~(((v347 ^ -1) | (-(v347 ^ -1))) >> 31)) & 2)) - (v348 + ((~(((v349 ^ -1) | (-(v349 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
    v408[v508] = v406;
    int * v410 = v317->cache_tags;
    int v511 = ((((int)((unsigned int)((int)((unsigned int)v325 >> 2)) >> 1)) & 1) * 2) + ((((v345 + ((~(((v347 ^ -1) | (-(v347 ^ -1))) >> 31)) & 2)) - (v348 + ((~(((v349 ^ -1) | (-(v349 ^ -1))) >> 31)) & 2))) >> 31) & 1);
    int v512 = (int)((unsigned int)((int)((unsigned int)v325 >> 2)) >> 1);
    v410[v511] = v512;
    int * v412 = v317->cache_dirty;
    v412[v511] = 0;
    int * v414 = v317->cache_age;
    v414[v511] = 1;
    int * v416 = v317->cache_age;
    int v417 = v416[v511];
    int v418 = v416[v440];
    int v518 = v418 + ((int)((unsigned int)(v418 - v417) >> 31));
    v416[v440] = v518;
    int * v420 = v317->cache_age;
    int v421 = v420[v441];
    int v520 = v421 + ((int)((unsigned int)(v421 - v417) >> 31));
    v420[v441] = v520;
    int * v423 = v317->cache_age;
    v423[v511] = 0;
    v426 = v511;
  }
  int v523 = (v426 * 2) + (((int)((unsigned int)v325 >> 2)) & 1);
  int v427 = v333[v523];
  int * v428 = v317->regs;
  v428[15] = v427;
  struct StateT * v430 = slot_9(v317);
  return v430;
}

struct StateT * slot_27(struct StateT * v1169) {
  int * v1170 = v1169->saved_regs;
  int * v1171 = v1169->regs;
  int v1172 = v1171[11];
  v1170[11] = v1172;
  int v1174 = v1169->timer;
  int v1185 = v1174 + 1;
  v1169->timer = v1185;
  int * v1176 = v1169->regs;
  int v1177 = v1176[11];
  int v1187 = v1177 + -1;
  v1176[11] = v1187;
  struct StateT * v1179 = slot_28(v1169);
  return v1179;
}

struct StateT * slot_30(struct StateT * v1232) {
  int * v1233 = v1232->regs;
  int v1234 = v1233[14];
  int v1235 = v1233[15];
  bool v1259 = !(v1234 == v1235);
  struct StateT * v1254;
  if (v1259) {
    int v1236 = v1232->timer;
    int v1260 = v1236 + 15;
    v1232->timer = v1260;
    int * v1238 = v1232->saved_regs;
    int v1239 = v1238[11];
    int * v1240 = v1232->regs;
    v1240[11] = v1239;
    int * v1242 = v1232->saved_regs;
    int v1243 = v1242[12];
    int * v1244 = v1232->regs;
    v1244[12] = v1243;
    int * v1246 = v1232->saved_regs;
    int v1247 = v1246[13];
    int * v1248 = v1232->regs;
    v1248[13] = v1247;
    struct StateT * v1250 = slot_31(v1232);
    v1254 = v1250;
  } else {
    struct StateT * v1252 = slot_32(v1232);
    v1254 = v1252;
  }
  return v1254;
}

struct StateT * slot_4(struct StateT * v58) {
  int v59 = v58->timer;
  int v66 = v59 + 1;
  v58->timer = v66;
  int * v61 = v58->regs;
  int v62 = v61[12];
  int v69 = v62 + 16;
  v61[12] = v69;
  struct StateT * v64 = slot_5(v58);
  return v64;
}

struct StateT * slot_15(struct StateT * v635) {
  int * v636 = v635->saved_regs;
  int * v637 = v635->regs;
  int v638 = v637[13];
  v636[13] = v638;
  int v640 = v635->timer;
  int v651 = v640 + 1;
  v635->timer = v651;
  int * v642 = v635->regs;
  int v643 = v642[13];
  int v653 = v643 + 4;
  v642[13] = v653;
  struct StateT * v645 = slot_16(v635);
  return v645;
}

struct StateT * slot_18(struct StateT * v715) {
  int v716 = v715->timer;
  int v720 = v716 + 1;
  v715->timer = v720;
  struct StateT * v718 = slot_20(v715);
  return v718;
}

struct StateT * slot_9(struct StateT * v528) {
  int * v529 = v528->regs;
  int v530 = v529[11];
  bool v557 = 0 >= v530;
  struct StateT * v553;
  if (v557) {
    int v531 = v528->timer;
    int v558 = v531 + 15;
    v528->timer = v558;
    int * v533 = v528->saved_regs;
    int v534 = v533[12];
    int * v535 = v528->regs;
    v535[12] = v534;
    int * v537 = v528->saved_regs;
    int v538 = v537[13];
    int * v539 = v528->regs;
    v539[13] = v538;
    int * v541 = v528->saved_regs;
    int v542 = v541[14];
    int * v543 = v528->regs;
    v543[14] = v542;
    int * v545 = v528->saved_regs;
    int v546 = v545[15];
    int * v547 = v528->regs;
    v547[15] = v546;
    struct StateT * v549 = slot_23(v528);
    v553 = v549;
  } else {
    struct StateT * v551 = slot_11(v528);
    v553 = v551;
  }
  return v553;
}

struct StateT * slot_22(struct StateT * v748) {
  int v749 = v748->timer;
  int v859 = v749 + 1;
  v748->timer = v859;
  int * v751 = v748->regs;
  int v752 = v751[12];
  int * v753 = v748->cache_tags;
  int v863 = (((int)((unsigned int)((int)((unsigned int)v752 >> 2)) >> 1)) & 1) * 2;
  int v754 = v753[v863];
  int v864 = ((((int)((unsigned int)((int)((unsigned int)v752 >> 2)) >> 1)) & 1) * 2) + 1;
  int v755 = v753[v864];
  int v865 = 4 + ((((int)((unsigned int)((int)((unsigned int)v752 >> 2)) >> 1)) & 3) * 2);
  int v756 = v753[v865];
  int v866 = (4 + ((((int)((unsigned int)((int)((unsigned int)v752 >> 2)) >> 1)) & 3) * 2)) + 1;
  int v757 = v753[v866];
  int v758 = v748->timer;
  int v867 = v758 + ((100 ^ (((~(((v756 ^ ((int)((unsigned int)((int)((unsigned int)v752 >> 2)) >> 1))) | (-(v756 ^ ((int)((unsigned int)((int)((unsigned int)v752 >> 2)) >> 1))))) >> 31)) | (~(((v757 ^ ((int)((unsigned int)((int)((unsigned int)v752 >> 2)) >> 1))) | (-(v757 ^ ((int)((unsigned int)((int)((unsigned int)v752 >> 2)) >> 1))))) >> 31))) & 104)) ^ (((~(((v754 ^ ((int)((unsigned int)((int)((unsigned int)v752 >> 2)) >> 1))) | (-(v754 ^ ((int)((unsigned int)((int)((unsigned int)v752 >> 2)) >> 1))))) >> 31)) | (~(((v755 ^ ((int)((unsigned int)((int)((unsigned int)v752 >> 2)) >> 1))) | (-(v755 ^ ((int)((unsigned int)((int)((unsigned int)v752 >> 2)) >> 1))))) >> 31))) & (1 ^ (100 ^ (((~(((v756 ^ ((int)((unsigned int)((int)((unsigned int)v752 >> 2)) >> 1))) | (-(v756 ^ ((int)((unsigned int)((int)((unsigned int)v752 >> 2)) >> 1))))) >> 31)) | (~(((v757 ^ ((int)((unsigned int)((int)((unsigned int)v752 >> 2)) >> 1))) | (-(v757 ^ ((int)((unsigned int)((int)((unsigned int)v752 >> 2)) >> 1))))) >> 31))) & 104)))));
  v748->timer = v867;
  int * v760 = v748->cache_vals;
  bool v868 = !(((~(((v754 ^ ((int)((unsigned int)((int)((unsigned int)v752 >> 2)) >> 1))) | (-(v754 ^ ((int)((unsigned int)((int)((unsigned int)v752 >> 2)) >> 1))))) >> 31)) | (~(((v755 ^ ((int)((unsigned int)((int)((unsigned int)v752 >> 2)) >> 1))) | (-(v755 ^ ((int)((unsigned int)((int)((unsigned int)v752 >> 2)) >> 1))))) >> 31))) == 0);
  int v853;
  if (v868) {
    int * v761 = v748->cache_age;
    int v870 = ((((int)((unsigned int)((int)((unsigned int)v752 >> 2)) >> 1)) & 1) * 2) + ((~(((v755 ^ ((int)((unsigned int)((int)((unsigned int)v752 >> 2)) >> 1))) | (-(v755 ^ ((int)((unsigned int)((int)((unsigned int)v752 >> 2)) >> 1))))) >> 31)) & 1);
    int v762 = v761[v870];
    int v763 = v761[v863];
    int v871 = v763 + ((int)((unsigned int)(v763 - v762) >> 31));
    v761[v863] = v871;
    int * v765 = v748->cache_age;
    int v766 = v765[v864];
    int v873 = v766 + ((int)((unsigned int)(v766 - v762) >> 31));
    v765[v864] = v873;
    int * v768 = v748->cache_age;
    v768[v870] = 0;
    v853 = v870;
  } else {
    int * v771 = v748->cache_age;
    int v877 = (((int)((unsigned int)((int)((unsigned int)v752 >> 2)) >> 1)) & 1) * 2;
    int v772 = v771[v877];
    int * v773 = v748->cache_tags;
    int v774 = v773[v877];
    int v775 = v771[v864];
    int v776 = v773[v864];
    bool v879 = !(((~(((v756 ^ ((int)((unsigned int)((int)((unsigned int)v752 >> 2)) >> 1))) | (-(v756 ^ ((int)((unsigned int)((int)((unsigned int)v752 >> 2)) >> 1))))) >> 31)) | (~(((v757 ^ ((int)((unsigned int)((int)((unsigned int)v752 >> 2)) >> 1))) | (-(v757 ^ ((int)((unsigned int)((int)((unsigned int)v752 >> 2)) >> 1))))) >> 31))) == 0);
    int v830;
    if (v879) {
      int * v777 = v748->cache_age;
      int v881 = (4 + ((((int)((unsigned int)((int)((unsigned int)v752 >> 2)) >> 1)) & 3) * 2)) + ((~(((v757 ^ ((int)((unsigned int)((int)((unsigned int)v752 >> 2)) >> 1))) | (-(v757 ^ ((int)((unsigned int)((int)((unsigned int)v752 >> 2)) >> 1))))) >> 31)) & 1);
      int v778 = v777[v881];
      int v779 = v777[v865];
      int v882 = v779 + ((int)((unsigned int)(v779 - v778) >> 31));
      v777[v865] = v882;
      int * v781 = v748->cache_age;
      int v782 = v781[v866];
      int v884 = v782 + ((int)((unsigned int)(v782 - v778) >> 31));
      v781[v866] = v884;
      int * v784 = v748->cache_age;
      v784[v881] = 0;
      v830 = v881;
    } else {
      int * v787 = v748->cache_age;
      int v888 = 4 + ((((int)((unsigned int)((int)((unsigned int)v752 >> 2)) >> 1)) & 3) * 2);
      int v788 = v787[v888];
      int * v789 = v748->cache_tags;
      int v790 = v789[v888];
      int v791 = v787[v866];
      int v792 = v789[v866];
      int * v793 = v748->cache_dirty;
      int v891 = (4 + ((((int)((unsigned int)((int)((unsigned int)v752 >> 2)) >> 1)) & 3) * 2)) + ((((v788 + ((~(((v790 ^ -1) | (-(v790 ^ -1))) >> 31)) & 2)) - (v791 + ((~(((v792 ^ -1) | (-(v792 ^ -1))) >> 31)) & 2))) >> 31) & 1);
      int v794 = v793[v891];
      bool v892 = !(v794 == 0);
      if (v892) {
        int * v795 = v748->cache_tags;
        int v796 = v795[v891];
        int * v797 = v748->cache_vals;
        int v895 = ((4 + ((((int)((unsigned int)((int)((unsigned int)v752 >> 2)) >> 1)) & 3) * 2)) + ((((v788 + ((~(((v790 ^ -1) | (-(v790 ^ -1))) >> 31)) & 2)) - (v791 + ((~(((v792 ^ -1) | (-(v792 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
        int v798 = v797[v895];
        int v896 = (((4 + ((((int)((unsigned int)((int)((unsigned int)v752 >> 2)) >> 1)) & 3) * 2)) + ((((v788 + ((~(((v790 ^ -1) | (-(v790 ^ -1))) >> 31)) & 2)) - (v791 + ((~(((v792 ^ -1) | (-(v792 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
        int v799 = v797[v896];
        int * v800 = v748->mem;
        int v898 = v796 * 2;
        v800[v898] = v798;
        int * v802 = v748->mem;
        int v901 = (v796 * 2) + 1;
        v802[v901] = v799;
        ;
      } else {
        ;
      }
      int * v807 = v748->mem;
      int v906 = ((int)((unsigned int)((int)((unsigned int)v752 >> 2)) >> 1)) * 2;
      int v808 = v807[v906];
      int v907 = (((int)((unsigned int)((int)((unsigned int)v752 >> 2)) >> 1)) * 2) + 1;
      int v809 = v807[v907];
      int * v810 = v748->cache_vals;
      int v909 = ((4 + ((((int)((unsigned int)((int)((unsigned int)v752 >> 2)) >> 1)) & 3) * 2)) + ((((v788 + ((~(((v790 ^ -1) | (-(v790 ^ -1))) >> 31)) & 2)) - (v791 + ((~(((v792 ^ -1) | (-(v792 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
      v810[v909] = v808;
      int * v812 = v748->cache_vals;
      int v912 = (((4 + ((((int)((unsigned int)((int)((unsigned int)v752 >> 2)) >> 1)) & 3) * 2)) + ((((v788 + ((~(((v790 ^ -1) | (-(v790 ^ -1))) >> 31)) & 2)) - (v791 + ((~(((v792 ^ -1) | (-(v792 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
      v812[v912] = v809;
      int * v814 = v748->cache_tags;
      int v915 = (int)((unsigned int)((int)((unsigned int)v752 >> 2)) >> 1);
      v814[v891] = v915;
      int * v816 = v748->cache_dirty;
      v816[v891] = 0;
      int * v818 = v748->cache_age;
      v818[v891] = 1;
      int * v820 = v748->cache_age;
      int v821 = v820[v891];
      int v822 = v820[v865];
      int v921 = v822 + ((int)((unsigned int)(v822 - v821) >> 31));
      v820[v865] = v921;
      int * v824 = v748->cache_age;
      int v825 = v824[v866];
      int v923 = v825 + ((int)((unsigned int)(v825 - v821) >> 31));
      v824[v866] = v923;
      int * v827 = v748->cache_age;
      v827[v891] = 0;
      v830 = v891;
    }
    int * v831 = v748->cache_vals;
    int v926 = v830 * 2;
    int v832 = v831[v926];
    int v927 = (v830 * 2) + 1;
    int v833 = v831[v927];
    int v928 = (((((int)((unsigned int)((int)((unsigned int)v752 >> 2)) >> 1)) & 1) * 2) + ((((v772 + ((~(((v774 ^ -1) | (-(v774 ^ -1))) >> 31)) & 2)) - (v775 + ((~(((v776 ^ -1) | (-(v776 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
    v831[v928] = v832;
    int * v835 = v748->cache_vals;
    int v931 = ((((((int)((unsigned int)((int)((unsigned int)v752 >> 2)) >> 1)) & 1) * 2) + ((((v772 + ((~(((v774 ^ -1) | (-(v774 ^ -1))) >> 31)) & 2)) - (v775 + ((~(((v776 ^ -1) | (-(v776 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
    v835[v931] = v833;
    int * v837 = v748->cache_tags;
    int v934 = ((((int)((unsigned int)((int)((unsigned int)v752 >> 2)) >> 1)) & 1) * 2) + ((((v772 + ((~(((v774 ^ -1) | (-(v774 ^ -1))) >> 31)) & 2)) - (v775 + ((~(((v776 ^ -1) | (-(v776 ^ -1))) >> 31)) & 2))) >> 31) & 1);
    int v935 = (int)((unsigned int)((int)((unsigned int)v752 >> 2)) >> 1);
    v837[v934] = v935;
    int * v839 = v748->cache_dirty;
    v839[v934] = 0;
    int * v841 = v748->cache_age;
    v841[v934] = 1;
    int * v843 = v748->cache_age;
    int v844 = v843[v934];
    int v845 = v843[v863];
    int v941 = v845 + ((int)((unsigned int)(v845 - v844) >> 31));
    v843[v863] = v941;
    int * v847 = v748->cache_age;
    int v848 = v847[v864];
    int v943 = v848 + ((int)((unsigned int)(v848 - v844) >> 31));
    v847[v864] = v943;
    int * v850 = v748->cache_age;
    v850[v934] = 0;
    v853 = v934;
  }
  int v946 = (v853 * 2) + (((int)((unsigned int)v752 >> 2)) & 1);
  int v854 = v760[v946];
  int * v855 = v748->regs;
  v855[14] = v854;
  struct StateT * v857 = slot_24(v748);
  return v857;
}

struct StateT * slot_11(struct StateT * v585) {
  int v586 = v585->timer;
  int v590 = v586 + 1;
  v585->timer = v590;
  struct StateT * v588 = slot_13(v585);
  return v588;
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
  
  int n = bounded(0, 4);
  s1.regs[10] = n;
  s2.regs[10] = n;
  // guess, the attacker's: the same draw in both states
  for (int i=0; i<4; i++) {
    int v = bounded(0, 20);
    s1.mem[4 + i] = v;
    s2.mem[4 + i] = v;
  }
  
  // secret, secret: a different draw in each state
  for (int i=0; i<4; i++) {
    s1.mem[0 + i] = secret(0, 20);
    s2.mem[0 + i] = secret(0, 20);
  }
  struct StateT *s1_ = snippet(&s1);
  struct StateT *s2_ = snippet(&s2);
  //@ assert untainted_timer: !\tainted(s1_->timer==s2_->timer);
  koika_assert(s1_->timer==s2_->timer, "timing leak");
  return 0;
}