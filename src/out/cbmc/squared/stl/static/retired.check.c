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

struct StateT2 {
  struct StateT * a;
  struct StateT * b;
};

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

void squared_assert(bool);
void squared_assume(bool);

struct StateT2 * snippet(struct StateT2 * v0);
struct StateT2 * slot_1(struct StateT2 * v42);
struct StateT2 * slot_8(struct StateT2 * v1227);
struct StateT2 * slot_6(struct StateT2 * v783);
struct StateT2 * slot_5(struct StateT2 * v757);
struct StateT2 * slot_4(struct StateT2 * v731);
struct StateT2 * slot_2(struct StateT2 * v81);
struct StateT2 * slot_7(struct StateT2 * v809);
struct StateT2 * slot_3(struct StateT2 * v705);
struct StateT2 * slot_0(struct StateT2 * v2);
struct StateT2 * snippet(struct StateT2 * v0) {
  struct StateT2 * v1 = slot_0(v0);
  return v1;
}

struct StateT2 * slot_1(struct StateT2 * v42) {
  struct StateT * v43 = v42->a;
  int v44 = v43->timer;
  struct StateT * v45 = v42->b;
  int v46 = v45->timer;
  bool v67 = v44 == v46;
  squared_assert(v67);
  squared_assume(v67);
  struct StateT * v49 = v42->a;
  int v50 = v49->timer;
  int v69 = v50 + 1;
  v49->timer = v69;
  struct StateT * v52 = v42->b;
  int v53 = v52->timer;
  int v71 = v53 + 1;
  v52->timer = v71;
  struct StateT * v55 = v42->a;
  int * v56 = v55->regs;
  int v57 = v56[6];
  int v75 = v57 + 80;
  v56[6] = v75;
  struct StateT * v59 = v42->b;
  int * v60 = v59->regs;
  int v61 = v60[6];
  int v78 = v61 + 80;
  v60[6] = v78;
  struct StateT2 * v63 = slot_2(v42);
  return v63;
}

struct StateT2 * slot_8(struct StateT2 * v1227) {
  struct StateT * v1228 = v1227->a;
  int v1229 = v1228->timer;
  struct StateT * v1230 = v1227->b;
  int v1231 = v1230->timer;
  bool v1457 = v1229 == v1231;
  squared_assert(v1457);
  squared_assume(v1457);
  struct StateT * v1234 = v1227->a;
  int v1235 = v1234->timer;
  int v1459 = v1235 + 1;
  v1234->timer = v1459;
  struct StateT * v1237 = v1227->b;
  int v1238 = v1237->timer;
  int v1461 = v1238 + 1;
  v1237->timer = v1461;
  struct StateT * v1240 = v1227->a;
  int * v1241 = v1240->regs;
  int v1242 = v1241[11];
  int * v1243 = v1240->cache_tags;
  int v1466 = (((int)((unsigned int)((int)((unsigned int)v1242 >> 2)) >> 1)) & 1) * 2;
  int v1244 = v1243[v1466];
  int v1467 = ((((int)((unsigned int)((int)((unsigned int)v1242 >> 2)) >> 1)) & 1) * 2) + 1;
  int v1245 = v1243[v1467];
  int v1468 = 4 + ((((int)((unsigned int)((int)((unsigned int)v1242 >> 2)) >> 1)) & 3) * 2);
  int v1246 = v1243[v1468];
  int v1469 = (4 + ((((int)((unsigned int)((int)((unsigned int)v1242 >> 2)) >> 1)) & 3) * 2)) + 1;
  int v1247 = v1243[v1469];
  int v1248 = v1240->timer;
  int v1470 = v1248 + ((100 ^ (((~(((v1246 ^ ((int)((unsigned int)((int)((unsigned int)v1242 >> 2)) >> 1))) | (-(v1246 ^ ((int)((unsigned int)((int)((unsigned int)v1242 >> 2)) >> 1))))) >> 31)) | (~(((v1247 ^ ((int)((unsigned int)((int)((unsigned int)v1242 >> 2)) >> 1))) | (-(v1247 ^ ((int)((unsigned int)((int)((unsigned int)v1242 >> 2)) >> 1))))) >> 31))) & 104)) ^ (((~(((v1244 ^ ((int)((unsigned int)((int)((unsigned int)v1242 >> 2)) >> 1))) | (-(v1244 ^ ((int)((unsigned int)((int)((unsigned int)v1242 >> 2)) >> 1))))) >> 31)) | (~(((v1245 ^ ((int)((unsigned int)((int)((unsigned int)v1242 >> 2)) >> 1))) | (-(v1245 ^ ((int)((unsigned int)((int)((unsigned int)v1242 >> 2)) >> 1))))) >> 31))) & (1 ^ (100 ^ (((~(((v1246 ^ ((int)((unsigned int)((int)((unsigned int)v1242 >> 2)) >> 1))) | (-(v1246 ^ ((int)((unsigned int)((int)((unsigned int)v1242 >> 2)) >> 1))))) >> 31)) | (~(((v1247 ^ ((int)((unsigned int)((int)((unsigned int)v1242 >> 2)) >> 1))) | (-(v1247 ^ ((int)((unsigned int)((int)((unsigned int)v1242 >> 2)) >> 1))))) >> 31))) & 104)))));
  v1240->timer = v1470;
  int * v1250 = v1240->cache_vals;
  bool v1471 = !(((~(((v1244 ^ ((int)((unsigned int)((int)((unsigned int)v1242 >> 2)) >> 1))) | (-(v1244 ^ ((int)((unsigned int)((int)((unsigned int)v1242 >> 2)) >> 1))))) >> 31)) | (~(((v1245 ^ ((int)((unsigned int)((int)((unsigned int)v1242 >> 2)) >> 1))) | (-(v1245 ^ ((int)((unsigned int)((int)((unsigned int)v1242 >> 2)) >> 1))))) >> 31))) == 0);
  int v1343;
  if (v1471) {
    int * v1251 = v1240->cache_age;
    int v1473 = ((((int)((unsigned int)((int)((unsigned int)v1242 >> 2)) >> 1)) & 1) * 2) + ((~(((v1245 ^ ((int)((unsigned int)((int)((unsigned int)v1242 >> 2)) >> 1))) | (-(v1245 ^ ((int)((unsigned int)((int)((unsigned int)v1242 >> 2)) >> 1))))) >> 31)) & 1);
    int v1252 = v1251[v1473];
    int v1253 = v1251[v1466];
    int v1474 = v1253 + ((int)((unsigned int)(v1253 - v1252) >> 31));
    v1251[v1466] = v1474;
    int * v1255 = v1240->cache_age;
    int v1256 = v1255[v1467];
    int v1476 = v1256 + ((int)((unsigned int)(v1256 - v1252) >> 31));
    v1255[v1467] = v1476;
    int * v1258 = v1240->cache_age;
    v1258[v1473] = 0;
    v1343 = v1473;
  } else {
    int * v1261 = v1240->cache_age;
    int v1480 = (((int)((unsigned int)((int)((unsigned int)v1242 >> 2)) >> 1)) & 1) * 2;
    int v1262 = v1261[v1480];
    int * v1263 = v1240->cache_tags;
    int v1264 = v1263[v1480];
    int v1265 = v1261[v1467];
    int v1266 = v1263[v1467];
    bool v1482 = !(((~(((v1246 ^ ((int)((unsigned int)((int)((unsigned int)v1242 >> 2)) >> 1))) | (-(v1246 ^ ((int)((unsigned int)((int)((unsigned int)v1242 >> 2)) >> 1))))) >> 31)) | (~(((v1247 ^ ((int)((unsigned int)((int)((unsigned int)v1242 >> 2)) >> 1))) | (-(v1247 ^ ((int)((unsigned int)((int)((unsigned int)v1242 >> 2)) >> 1))))) >> 31))) == 0);
    int v1320;
    if (v1482) {
      int * v1267 = v1240->cache_age;
      int v1484 = (4 + ((((int)((unsigned int)((int)((unsigned int)v1242 >> 2)) >> 1)) & 3) * 2)) + ((~(((v1247 ^ ((int)((unsigned int)((int)((unsigned int)v1242 >> 2)) >> 1))) | (-(v1247 ^ ((int)((unsigned int)((int)((unsigned int)v1242 >> 2)) >> 1))))) >> 31)) & 1);
      int v1268 = v1267[v1484];
      int v1269 = v1267[v1468];
      int v1485 = v1269 + ((int)((unsigned int)(v1269 - v1268) >> 31));
      v1267[v1468] = v1485;
      int * v1271 = v1240->cache_age;
      int v1272 = v1271[v1469];
      int v1487 = v1272 + ((int)((unsigned int)(v1272 - v1268) >> 31));
      v1271[v1469] = v1487;
      int * v1274 = v1240->cache_age;
      v1274[v1484] = 0;
      v1320 = v1484;
    } else {
      int * v1277 = v1240->cache_age;
      int v1491 = 4 + ((((int)((unsigned int)((int)((unsigned int)v1242 >> 2)) >> 1)) & 3) * 2);
      int v1278 = v1277[v1491];
      int * v1279 = v1240->cache_tags;
      int v1280 = v1279[v1491];
      int v1281 = v1277[v1469];
      int v1282 = v1279[v1469];
      int * v1283 = v1240->cache_dirty;
      int v1494 = (4 + ((((int)((unsigned int)((int)((unsigned int)v1242 >> 2)) >> 1)) & 3) * 2)) + ((((v1278 + ((~(((v1280 ^ -1) | (-(v1280 ^ -1))) >> 31)) & 2)) - (v1281 + ((~(((v1282 ^ -1) | (-(v1282 ^ -1))) >> 31)) & 2))) >> 31) & 1);
      int v1284 = v1283[v1494];
      bool v1495 = !(v1284 == 0);
      if (v1495) {
        int * v1285 = v1240->cache_tags;
        int v1286 = v1285[v1494];
        int * v1287 = v1240->cache_vals;
        int v1498 = ((4 + ((((int)((unsigned int)((int)((unsigned int)v1242 >> 2)) >> 1)) & 3) * 2)) + ((((v1278 + ((~(((v1280 ^ -1) | (-(v1280 ^ -1))) >> 31)) & 2)) - (v1281 + ((~(((v1282 ^ -1) | (-(v1282 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
        int v1288 = v1287[v1498];
        int v1499 = (((4 + ((((int)((unsigned int)((int)((unsigned int)v1242 >> 2)) >> 1)) & 3) * 2)) + ((((v1278 + ((~(((v1280 ^ -1) | (-(v1280 ^ -1))) >> 31)) & 2)) - (v1281 + ((~(((v1282 ^ -1) | (-(v1282 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
        int v1289 = v1287[v1499];
        int * v1290 = v1240->mem;
        int v1501 = v1286 * 2;
        v1290[v1501] = v1288;
        int * v1292 = v1240->mem;
        int v1504 = (v1286 * 2) + 1;
        v1292[v1504] = v1289;
        ;
      } else {
        ;
      }
      int * v1297 = v1240->mem;
      int v1509 = ((int)((unsigned int)((int)((unsigned int)v1242 >> 2)) >> 1)) * 2;
      int v1298 = v1297[v1509];
      int v1510 = (((int)((unsigned int)((int)((unsigned int)v1242 >> 2)) >> 1)) * 2) + 1;
      int v1299 = v1297[v1510];
      int * v1300 = v1240->cache_vals;
      int v1512 = ((4 + ((((int)((unsigned int)((int)((unsigned int)v1242 >> 2)) >> 1)) & 3) * 2)) + ((((v1278 + ((~(((v1280 ^ -1) | (-(v1280 ^ -1))) >> 31)) & 2)) - (v1281 + ((~(((v1282 ^ -1) | (-(v1282 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
      v1300[v1512] = v1298;
      int * v1302 = v1240->cache_vals;
      int v1515 = (((4 + ((((int)((unsigned int)((int)((unsigned int)v1242 >> 2)) >> 1)) & 3) * 2)) + ((((v1278 + ((~(((v1280 ^ -1) | (-(v1280 ^ -1))) >> 31)) & 2)) - (v1281 + ((~(((v1282 ^ -1) | (-(v1282 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
      v1302[v1515] = v1299;
      int * v1304 = v1240->cache_tags;
      int v1518 = (int)((unsigned int)((int)((unsigned int)v1242 >> 2)) >> 1);
      v1304[v1494] = v1518;
      int * v1306 = v1240->cache_dirty;
      v1306[v1494] = 0;
      int * v1308 = v1240->cache_age;
      v1308[v1494] = 1;
      int * v1310 = v1240->cache_age;
      int v1311 = v1310[v1494];
      int v1312 = v1310[v1468];
      int v1524 = v1312 + ((int)((unsigned int)(v1312 - v1311) >> 31));
      v1310[v1468] = v1524;
      int * v1314 = v1240->cache_age;
      int v1315 = v1314[v1469];
      int v1526 = v1315 + ((int)((unsigned int)(v1315 - v1311) >> 31));
      v1314[v1469] = v1526;
      int * v1317 = v1240->cache_age;
      v1317[v1494] = 0;
      v1320 = v1494;
    }
    int * v1321 = v1240->cache_vals;
    int v1529 = v1320 * 2;
    int v1322 = v1321[v1529];
    int v1530 = (v1320 * 2) + 1;
    int v1323 = v1321[v1530];
    int v1531 = (((((int)((unsigned int)((int)((unsigned int)v1242 >> 2)) >> 1)) & 1) * 2) + ((((v1262 + ((~(((v1264 ^ -1) | (-(v1264 ^ -1))) >> 31)) & 2)) - (v1265 + ((~(((v1266 ^ -1) | (-(v1266 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
    v1321[v1531] = v1322;
    int * v1325 = v1240->cache_vals;
    int v1534 = ((((((int)((unsigned int)((int)((unsigned int)v1242 >> 2)) >> 1)) & 1) * 2) + ((((v1262 + ((~(((v1264 ^ -1) | (-(v1264 ^ -1))) >> 31)) & 2)) - (v1265 + ((~(((v1266 ^ -1) | (-(v1266 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
    v1325[v1534] = v1323;
    int * v1327 = v1240->cache_tags;
    int v1537 = ((((int)((unsigned int)((int)((unsigned int)v1242 >> 2)) >> 1)) & 1) * 2) + ((((v1262 + ((~(((v1264 ^ -1) | (-(v1264 ^ -1))) >> 31)) & 2)) - (v1265 + ((~(((v1266 ^ -1) | (-(v1266 ^ -1))) >> 31)) & 2))) >> 31) & 1);
    int v1538 = (int)((unsigned int)((int)((unsigned int)v1242 >> 2)) >> 1);
    v1327[v1537] = v1538;
    int * v1329 = v1240->cache_dirty;
    v1329[v1537] = 0;
    int * v1331 = v1240->cache_age;
    v1331[v1537] = 1;
    int * v1333 = v1240->cache_age;
    int v1334 = v1333[v1537];
    int v1335 = v1333[v1466];
    int v1544 = v1335 + ((int)((unsigned int)(v1335 - v1334) >> 31));
    v1333[v1466] = v1544;
    int * v1337 = v1240->cache_age;
    int v1338 = v1337[v1467];
    int v1546 = v1338 + ((int)((unsigned int)(v1338 - v1334) >> 31));
    v1337[v1467] = v1546;
    int * v1340 = v1240->cache_age;
    v1340[v1537] = 0;
    v1343 = v1537;
  }
  int v1549 = (v1343 * 2) + (((int)((unsigned int)v1242 >> 2)) & 1);
  int v1344 = v1250[v1549];
  int * v1345 = v1240->regs;
  v1345[12] = v1344;
  struct StateT * v1347 = v1227->b;
  int * v1348 = v1347->regs;
  int v1349 = v1348[11];
  int * v1350 = v1347->cache_tags;
  int v1556 = (((int)((unsigned int)((int)((unsigned int)v1349 >> 2)) >> 1)) & 1) * 2;
  int v1351 = v1350[v1556];
  int v1557 = ((((int)((unsigned int)((int)((unsigned int)v1349 >> 2)) >> 1)) & 1) * 2) + 1;
  int v1352 = v1350[v1557];
  int v1558 = 4 + ((((int)((unsigned int)((int)((unsigned int)v1349 >> 2)) >> 1)) & 3) * 2);
  int v1353 = v1350[v1558];
  int v1559 = (4 + ((((int)((unsigned int)((int)((unsigned int)v1349 >> 2)) >> 1)) & 3) * 2)) + 1;
  int v1354 = v1350[v1559];
  int v1355 = v1347->timer;
  int v1560 = v1355 + ((100 ^ (((~(((v1353 ^ ((int)((unsigned int)((int)((unsigned int)v1349 >> 2)) >> 1))) | (-(v1353 ^ ((int)((unsigned int)((int)((unsigned int)v1349 >> 2)) >> 1))))) >> 31)) | (~(((v1354 ^ ((int)((unsigned int)((int)((unsigned int)v1349 >> 2)) >> 1))) | (-(v1354 ^ ((int)((unsigned int)((int)((unsigned int)v1349 >> 2)) >> 1))))) >> 31))) & 104)) ^ (((~(((v1351 ^ ((int)((unsigned int)((int)((unsigned int)v1349 >> 2)) >> 1))) | (-(v1351 ^ ((int)((unsigned int)((int)((unsigned int)v1349 >> 2)) >> 1))))) >> 31)) | (~(((v1352 ^ ((int)((unsigned int)((int)((unsigned int)v1349 >> 2)) >> 1))) | (-(v1352 ^ ((int)((unsigned int)((int)((unsigned int)v1349 >> 2)) >> 1))))) >> 31))) & (1 ^ (100 ^ (((~(((v1353 ^ ((int)((unsigned int)((int)((unsigned int)v1349 >> 2)) >> 1))) | (-(v1353 ^ ((int)((unsigned int)((int)((unsigned int)v1349 >> 2)) >> 1))))) >> 31)) | (~(((v1354 ^ ((int)((unsigned int)((int)((unsigned int)v1349 >> 2)) >> 1))) | (-(v1354 ^ ((int)((unsigned int)((int)((unsigned int)v1349 >> 2)) >> 1))))) >> 31))) & 104)))));
  v1347->timer = v1560;
  int * v1357 = v1347->cache_vals;
  bool v1561 = !(((~(((v1351 ^ ((int)((unsigned int)((int)((unsigned int)v1349 >> 2)) >> 1))) | (-(v1351 ^ ((int)((unsigned int)((int)((unsigned int)v1349 >> 2)) >> 1))))) >> 31)) | (~(((v1352 ^ ((int)((unsigned int)((int)((unsigned int)v1349 >> 2)) >> 1))) | (-(v1352 ^ ((int)((unsigned int)((int)((unsigned int)v1349 >> 2)) >> 1))))) >> 31))) == 0);
  int v1450;
  if (v1561) {
    int * v1358 = v1347->cache_age;
    int v1563 = ((((int)((unsigned int)((int)((unsigned int)v1349 >> 2)) >> 1)) & 1) * 2) + ((~(((v1352 ^ ((int)((unsigned int)((int)((unsigned int)v1349 >> 2)) >> 1))) | (-(v1352 ^ ((int)((unsigned int)((int)((unsigned int)v1349 >> 2)) >> 1))))) >> 31)) & 1);
    int v1359 = v1358[v1563];
    int v1360 = v1358[v1556];
    int v1564 = v1360 + ((int)((unsigned int)(v1360 - v1359) >> 31));
    v1358[v1556] = v1564;
    int * v1362 = v1347->cache_age;
    int v1363 = v1362[v1557];
    int v1566 = v1363 + ((int)((unsigned int)(v1363 - v1359) >> 31));
    v1362[v1557] = v1566;
    int * v1365 = v1347->cache_age;
    v1365[v1563] = 0;
    v1450 = v1563;
  } else {
    int * v1368 = v1347->cache_age;
    int v1570 = (((int)((unsigned int)((int)((unsigned int)v1349 >> 2)) >> 1)) & 1) * 2;
    int v1369 = v1368[v1570];
    int * v1370 = v1347->cache_tags;
    int v1371 = v1370[v1570];
    int v1372 = v1368[v1557];
    int v1373 = v1370[v1557];
    bool v1572 = !(((~(((v1353 ^ ((int)((unsigned int)((int)((unsigned int)v1349 >> 2)) >> 1))) | (-(v1353 ^ ((int)((unsigned int)((int)((unsigned int)v1349 >> 2)) >> 1))))) >> 31)) | (~(((v1354 ^ ((int)((unsigned int)((int)((unsigned int)v1349 >> 2)) >> 1))) | (-(v1354 ^ ((int)((unsigned int)((int)((unsigned int)v1349 >> 2)) >> 1))))) >> 31))) == 0);
    int v1427;
    if (v1572) {
      int * v1374 = v1347->cache_age;
      int v1574 = (4 + ((((int)((unsigned int)((int)((unsigned int)v1349 >> 2)) >> 1)) & 3) * 2)) + ((~(((v1354 ^ ((int)((unsigned int)((int)((unsigned int)v1349 >> 2)) >> 1))) | (-(v1354 ^ ((int)((unsigned int)((int)((unsigned int)v1349 >> 2)) >> 1))))) >> 31)) & 1);
      int v1375 = v1374[v1574];
      int v1376 = v1374[v1558];
      int v1575 = v1376 + ((int)((unsigned int)(v1376 - v1375) >> 31));
      v1374[v1558] = v1575;
      int * v1378 = v1347->cache_age;
      int v1379 = v1378[v1559];
      int v1577 = v1379 + ((int)((unsigned int)(v1379 - v1375) >> 31));
      v1378[v1559] = v1577;
      int * v1381 = v1347->cache_age;
      v1381[v1574] = 0;
      v1427 = v1574;
    } else {
      int * v1384 = v1347->cache_age;
      int v1581 = 4 + ((((int)((unsigned int)((int)((unsigned int)v1349 >> 2)) >> 1)) & 3) * 2);
      int v1385 = v1384[v1581];
      int * v1386 = v1347->cache_tags;
      int v1387 = v1386[v1581];
      int v1388 = v1384[v1559];
      int v1389 = v1386[v1559];
      int * v1390 = v1347->cache_dirty;
      int v1584 = (4 + ((((int)((unsigned int)((int)((unsigned int)v1349 >> 2)) >> 1)) & 3) * 2)) + ((((v1385 + ((~(((v1387 ^ -1) | (-(v1387 ^ -1))) >> 31)) & 2)) - (v1388 + ((~(((v1389 ^ -1) | (-(v1389 ^ -1))) >> 31)) & 2))) >> 31) & 1);
      int v1391 = v1390[v1584];
      bool v1585 = !(v1391 == 0);
      if (v1585) {
        int * v1392 = v1347->cache_tags;
        int v1393 = v1392[v1584];
        int * v1394 = v1347->cache_vals;
        int v1588 = ((4 + ((((int)((unsigned int)((int)((unsigned int)v1349 >> 2)) >> 1)) & 3) * 2)) + ((((v1385 + ((~(((v1387 ^ -1) | (-(v1387 ^ -1))) >> 31)) & 2)) - (v1388 + ((~(((v1389 ^ -1) | (-(v1389 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
        int v1395 = v1394[v1588];
        int v1589 = (((4 + ((((int)((unsigned int)((int)((unsigned int)v1349 >> 2)) >> 1)) & 3) * 2)) + ((((v1385 + ((~(((v1387 ^ -1) | (-(v1387 ^ -1))) >> 31)) & 2)) - (v1388 + ((~(((v1389 ^ -1) | (-(v1389 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
        int v1396 = v1394[v1589];
        int * v1397 = v1347->mem;
        int v1591 = v1393 * 2;
        v1397[v1591] = v1395;
        int * v1399 = v1347->mem;
        int v1594 = (v1393 * 2) + 1;
        v1399[v1594] = v1396;
        ;
      } else {
        ;
      }
      int * v1404 = v1347->mem;
      int v1599 = ((int)((unsigned int)((int)((unsigned int)v1349 >> 2)) >> 1)) * 2;
      int v1405 = v1404[v1599];
      int v1600 = (((int)((unsigned int)((int)((unsigned int)v1349 >> 2)) >> 1)) * 2) + 1;
      int v1406 = v1404[v1600];
      int * v1407 = v1347->cache_vals;
      int v1602 = ((4 + ((((int)((unsigned int)((int)((unsigned int)v1349 >> 2)) >> 1)) & 3) * 2)) + ((((v1385 + ((~(((v1387 ^ -1) | (-(v1387 ^ -1))) >> 31)) & 2)) - (v1388 + ((~(((v1389 ^ -1) | (-(v1389 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
      v1407[v1602] = v1405;
      int * v1409 = v1347->cache_vals;
      int v1605 = (((4 + ((((int)((unsigned int)((int)((unsigned int)v1349 >> 2)) >> 1)) & 3) * 2)) + ((((v1385 + ((~(((v1387 ^ -1) | (-(v1387 ^ -1))) >> 31)) & 2)) - (v1388 + ((~(((v1389 ^ -1) | (-(v1389 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
      v1409[v1605] = v1406;
      int * v1411 = v1347->cache_tags;
      int v1608 = (int)((unsigned int)((int)((unsigned int)v1349 >> 2)) >> 1);
      v1411[v1584] = v1608;
      int * v1413 = v1347->cache_dirty;
      v1413[v1584] = 0;
      int * v1415 = v1347->cache_age;
      v1415[v1584] = 1;
      int * v1417 = v1347->cache_age;
      int v1418 = v1417[v1584];
      int v1419 = v1417[v1558];
      int v1614 = v1419 + ((int)((unsigned int)(v1419 - v1418) >> 31));
      v1417[v1558] = v1614;
      int * v1421 = v1347->cache_age;
      int v1422 = v1421[v1559];
      int v1616 = v1422 + ((int)((unsigned int)(v1422 - v1418) >> 31));
      v1421[v1559] = v1616;
      int * v1424 = v1347->cache_age;
      v1424[v1584] = 0;
      v1427 = v1584;
    }
    int * v1428 = v1347->cache_vals;
    int v1619 = v1427 * 2;
    int v1429 = v1428[v1619];
    int v1620 = (v1427 * 2) + 1;
    int v1430 = v1428[v1620];
    int v1621 = (((((int)((unsigned int)((int)((unsigned int)v1349 >> 2)) >> 1)) & 1) * 2) + ((((v1369 + ((~(((v1371 ^ -1) | (-(v1371 ^ -1))) >> 31)) & 2)) - (v1372 + ((~(((v1373 ^ -1) | (-(v1373 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
    v1428[v1621] = v1429;
    int * v1432 = v1347->cache_vals;
    int v1624 = ((((((int)((unsigned int)((int)((unsigned int)v1349 >> 2)) >> 1)) & 1) * 2) + ((((v1369 + ((~(((v1371 ^ -1) | (-(v1371 ^ -1))) >> 31)) & 2)) - (v1372 + ((~(((v1373 ^ -1) | (-(v1373 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
    v1432[v1624] = v1430;
    int * v1434 = v1347->cache_tags;
    int v1627 = ((((int)((unsigned int)((int)((unsigned int)v1349 >> 2)) >> 1)) & 1) * 2) + ((((v1369 + ((~(((v1371 ^ -1) | (-(v1371 ^ -1))) >> 31)) & 2)) - (v1372 + ((~(((v1373 ^ -1) | (-(v1373 ^ -1))) >> 31)) & 2))) >> 31) & 1);
    int v1628 = (int)((unsigned int)((int)((unsigned int)v1349 >> 2)) >> 1);
    v1434[v1627] = v1628;
    int * v1436 = v1347->cache_dirty;
    v1436[v1627] = 0;
    int * v1438 = v1347->cache_age;
    v1438[v1627] = 1;
    int * v1440 = v1347->cache_age;
    int v1441 = v1440[v1627];
    int v1442 = v1440[v1556];
    int v1634 = v1442 + ((int)((unsigned int)(v1442 - v1441) >> 31));
    v1440[v1556] = v1634;
    int * v1444 = v1347->cache_age;
    int v1445 = v1444[v1557];
    int v1636 = v1445 + ((int)((unsigned int)(v1445 - v1441) >> 31));
    v1444[v1557] = v1636;
    int * v1447 = v1347->cache_age;
    v1447[v1627] = 0;
    v1450 = v1627;
  }
  int v1639 = (v1450 * 2) + (((int)((unsigned int)v1349 >> 2)) & 1);
  int v1451 = v1357[v1639];
  int * v1452 = v1347->regs;
  v1452[12] = v1451;
  return v1227;
}

struct StateT2 * slot_6(struct StateT2 * v783) {
  struct StateT * v784 = v783->a;
  int v785 = v784->timer;
  struct StateT * v786 = v783->b;
  int v787 = v786->timer;
  bool v802 = v785 == v787;
  squared_assert(v802);
  squared_assume(v802);
  struct StateT * v790 = v783->a;
  int v791 = v790->timer;
  int v804 = v791 + 1;
  v790->timer = v804;
  struct StateT * v793 = v783->b;
  int v794 = v793->timer;
  int v806 = v794 + 1;
  v793->timer = v806;
  struct StateT2 * v798 = slot_7(v783);
  return v798;
}

struct StateT2 * slot_5(struct StateT2 * v757) {
  struct StateT * v758 = v757->a;
  int v759 = v758->timer;
  struct StateT * v760 = v757->b;
  int v761 = v760->timer;
  bool v776 = v759 == v761;
  squared_assert(v776);
  squared_assume(v776);
  struct StateT * v764 = v757->a;
  int v765 = v764->timer;
  int v778 = v765 + 1;
  v764->timer = v778;
  struct StateT * v767 = v757->b;
  int v768 = v767->timer;
  int v780 = v768 + 1;
  v767->timer = v780;
  struct StateT2 * v772 = slot_6(v757);
  return v772;
}

struct StateT2 * slot_4(struct StateT2 * v731) {
  struct StateT * v732 = v731->a;
  int v733 = v732->timer;
  struct StateT * v734 = v731->b;
  int v735 = v734->timer;
  bool v750 = v733 == v735;
  squared_assert(v750);
  squared_assume(v750);
  struct StateT * v738 = v731->a;
  int v739 = v738->timer;
  int v752 = v739 + 1;
  v738->timer = v752;
  struct StateT * v741 = v731->b;
  int v742 = v741->timer;
  int v754 = v742 + 1;
  v741->timer = v754;
  struct StateT2 * v746 = slot_5(v731);
  return v746;
}

struct StateT2 * slot_2(struct StateT2 * v81) {
  struct StateT * v82 = v81->a;
  int v83 = v82->timer;
  struct StateT * v84 = v81->b;
  int v85 = v84->timer;
  bool v430 = v83 == v85;
  squared_assert(v430);
  squared_assume(v430);
  struct StateT * v88 = v81->a;
  int v89 = v88->timer;
  int v432 = v89 + 1;
  v88->timer = v432;
  struct StateT * v91 = v81->b;
  int v92 = v91->timer;
  int v434 = v92 + 1;
  v91->timer = v434;
  struct StateT * v94 = v81->a;
  int * v95 = v94->regs;
  int v96 = v95[6];
  int * v97 = v94->cache_tags;
  int v439 = (((int)((unsigned int)((int)((unsigned int)v96 >> 2)) >> 1)) & 1) * 2;
  int v98 = v97[v439];
  int v440 = ((((int)((unsigned int)((int)((unsigned int)v96 >> 2)) >> 1)) & 1) * 2) + 1;
  int v99 = v97[v440];
  int v441 = 4 + ((((int)((unsigned int)((int)((unsigned int)v96 >> 2)) >> 1)) & 3) * 2);
  int v100 = v97[v441];
  int v442 = (4 + ((((int)((unsigned int)((int)((unsigned int)v96 >> 2)) >> 1)) & 3) * 2)) + 1;
  int v101 = v97[v442];
  int v102 = v94->timer;
  int v443 = v102 + ((100 ^ (((~(((v100 ^ ((int)((unsigned int)((int)((unsigned int)v96 >> 2)) >> 1))) | (-(v100 ^ ((int)((unsigned int)((int)((unsigned int)v96 >> 2)) >> 1))))) >> 31)) | (~(((v101 ^ ((int)((unsigned int)((int)((unsigned int)v96 >> 2)) >> 1))) | (-(v101 ^ ((int)((unsigned int)((int)((unsigned int)v96 >> 2)) >> 1))))) >> 31))) & 104)) ^ (((~(((v98 ^ ((int)((unsigned int)((int)((unsigned int)v96 >> 2)) >> 1))) | (-(v98 ^ ((int)((unsigned int)((int)((unsigned int)v96 >> 2)) >> 1))))) >> 31)) | (~(((v99 ^ ((int)((unsigned int)((int)((unsigned int)v96 >> 2)) >> 1))) | (-(v99 ^ ((int)((unsigned int)((int)((unsigned int)v96 >> 2)) >> 1))))) >> 31))) & (1 ^ (100 ^ (((~(((v100 ^ ((int)((unsigned int)((int)((unsigned int)v96 >> 2)) >> 1))) | (-(v100 ^ ((int)((unsigned int)((int)((unsigned int)v96 >> 2)) >> 1))))) >> 31)) | (~(((v101 ^ ((int)((unsigned int)((int)((unsigned int)v96 >> 2)) >> 1))) | (-(v101 ^ ((int)((unsigned int)((int)((unsigned int)v96 >> 2)) >> 1))))) >> 31))) & 104)))));
  v94->timer = v443;
  bool v444 = !(((~(((v98 ^ ((int)((unsigned int)((int)((unsigned int)v96 >> 2)) >> 1))) | (-(v98 ^ ((int)((unsigned int)((int)((unsigned int)v96 >> 2)) >> 1))))) >> 31)) | (~(((v99 ^ ((int)((unsigned int)((int)((unsigned int)v96 >> 2)) >> 1))) | (-(v99 ^ ((int)((unsigned int)((int)((unsigned int)v96 >> 2)) >> 1))))) >> 31))) == 0);
  int v196;
  if (v444) {
    int * v104 = v94->cache_age;
    int v446 = ((((int)((unsigned int)((int)((unsigned int)v96 >> 2)) >> 1)) & 1) * 2) + ((~(((v99 ^ ((int)((unsigned int)((int)((unsigned int)v96 >> 2)) >> 1))) | (-(v99 ^ ((int)((unsigned int)((int)((unsigned int)v96 >> 2)) >> 1))))) >> 31)) & 1);
    int v105 = v104[v446];
    int v106 = v104[v439];
    int v447 = v106 + ((int)((unsigned int)(v106 - v105) >> 31));
    v104[v439] = v447;
    int * v108 = v94->cache_age;
    int v109 = v108[v440];
    int v449 = v109 + ((int)((unsigned int)(v109 - v105) >> 31));
    v108[v440] = v449;
    int * v111 = v94->cache_age;
    v111[v446] = 0;
    v196 = v446;
  } else {
    int * v114 = v94->cache_age;
    int v453 = (((int)((unsigned int)((int)((unsigned int)v96 >> 2)) >> 1)) & 1) * 2;
    int v115 = v114[v453];
    int * v116 = v94->cache_tags;
    int v117 = v116[v453];
    int v118 = v114[v440];
    int v119 = v116[v440];
    bool v455 = !(((~(((v100 ^ ((int)((unsigned int)((int)((unsigned int)v96 >> 2)) >> 1))) | (-(v100 ^ ((int)((unsigned int)((int)((unsigned int)v96 >> 2)) >> 1))))) >> 31)) | (~(((v101 ^ ((int)((unsigned int)((int)((unsigned int)v96 >> 2)) >> 1))) | (-(v101 ^ ((int)((unsigned int)((int)((unsigned int)v96 >> 2)) >> 1))))) >> 31))) == 0);
    int v173;
    if (v455) {
      int * v120 = v94->cache_age;
      int v457 = (4 + ((((int)((unsigned int)((int)((unsigned int)v96 >> 2)) >> 1)) & 3) * 2)) + ((~(((v101 ^ ((int)((unsigned int)((int)((unsigned int)v96 >> 2)) >> 1))) | (-(v101 ^ ((int)((unsigned int)((int)((unsigned int)v96 >> 2)) >> 1))))) >> 31)) & 1);
      int v121 = v120[v457];
      int v122 = v120[v441];
      int v458 = v122 + ((int)((unsigned int)(v122 - v121) >> 31));
      v120[v441] = v458;
      int * v124 = v94->cache_age;
      int v125 = v124[v442];
      int v460 = v125 + ((int)((unsigned int)(v125 - v121) >> 31));
      v124[v442] = v460;
      int * v127 = v94->cache_age;
      v127[v457] = 0;
      v173 = v457;
    } else {
      int * v130 = v94->cache_age;
      int v464 = 4 + ((((int)((unsigned int)((int)((unsigned int)v96 >> 2)) >> 1)) & 3) * 2);
      int v131 = v130[v464];
      int * v132 = v94->cache_tags;
      int v133 = v132[v464];
      int v134 = v130[v442];
      int v135 = v132[v442];
      int * v136 = v94->cache_dirty;
      int v467 = (4 + ((((int)((unsigned int)((int)((unsigned int)v96 >> 2)) >> 1)) & 3) * 2)) + ((((v131 + ((~(((v133 ^ -1) | (-(v133 ^ -1))) >> 31)) & 2)) - (v134 + ((~(((v135 ^ -1) | (-(v135 ^ -1))) >> 31)) & 2))) >> 31) & 1);
      int v137 = v136[v467];
      bool v468 = !(v137 == 0);
      if (v468) {
        int * v138 = v94->cache_tags;
        int v139 = v138[v467];
        int * v140 = v94->cache_vals;
        int v471 = ((4 + ((((int)((unsigned int)((int)((unsigned int)v96 >> 2)) >> 1)) & 3) * 2)) + ((((v131 + ((~(((v133 ^ -1) | (-(v133 ^ -1))) >> 31)) & 2)) - (v134 + ((~(((v135 ^ -1) | (-(v135 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
        int v141 = v140[v471];
        int v472 = (((4 + ((((int)((unsigned int)((int)((unsigned int)v96 >> 2)) >> 1)) & 3) * 2)) + ((((v131 + ((~(((v133 ^ -1) | (-(v133 ^ -1))) >> 31)) & 2)) - (v134 + ((~(((v135 ^ -1) | (-(v135 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
        int v142 = v140[v472];
        int * v143 = v94->mem;
        int v474 = v139 * 2;
        v143[v474] = v141;
        int * v145 = v94->mem;
        int v477 = (v139 * 2) + 1;
        v145[v477] = v142;
        ;
      } else {
        ;
      }
      int * v150 = v94->mem;
      int v482 = ((int)((unsigned int)((int)((unsigned int)v96 >> 2)) >> 1)) * 2;
      int v151 = v150[v482];
      int v483 = (((int)((unsigned int)((int)((unsigned int)v96 >> 2)) >> 1)) * 2) + 1;
      int v152 = v150[v483];
      int * v153 = v94->cache_vals;
      int v485 = ((4 + ((((int)((unsigned int)((int)((unsigned int)v96 >> 2)) >> 1)) & 3) * 2)) + ((((v131 + ((~(((v133 ^ -1) | (-(v133 ^ -1))) >> 31)) & 2)) - (v134 + ((~(((v135 ^ -1) | (-(v135 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
      v153[v485] = v151;
      int * v155 = v94->cache_vals;
      int v488 = (((4 + ((((int)((unsigned int)((int)((unsigned int)v96 >> 2)) >> 1)) & 3) * 2)) + ((((v131 + ((~(((v133 ^ -1) | (-(v133 ^ -1))) >> 31)) & 2)) - (v134 + ((~(((v135 ^ -1) | (-(v135 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
      v155[v488] = v152;
      int * v157 = v94->cache_tags;
      int v491 = (int)((unsigned int)((int)((unsigned int)v96 >> 2)) >> 1);
      v157[v467] = v491;
      int * v159 = v94->cache_dirty;
      v159[v467] = 0;
      int * v161 = v94->cache_age;
      v161[v467] = 1;
      int * v163 = v94->cache_age;
      int v164 = v163[v467];
      int v165 = v163[v441];
      int v497 = v165 + ((int)((unsigned int)(v165 - v164) >> 31));
      v163[v441] = v497;
      int * v167 = v94->cache_age;
      int v168 = v167[v442];
      int v499 = v168 + ((int)((unsigned int)(v168 - v164) >> 31));
      v167[v442] = v499;
      int * v170 = v94->cache_age;
      v170[v467] = 0;
      v173 = v467;
    }
    int * v174 = v94->cache_vals;
    int v502 = v173 * 2;
    int v175 = v174[v502];
    int v503 = (v173 * 2) + 1;
    int v176 = v174[v503];
    int v504 = (((((int)((unsigned int)((int)((unsigned int)v96 >> 2)) >> 1)) & 1) * 2) + ((((v115 + ((~(((v117 ^ -1) | (-(v117 ^ -1))) >> 31)) & 2)) - (v118 + ((~(((v119 ^ -1) | (-(v119 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
    v174[v504] = v175;
    int * v178 = v94->cache_vals;
    int v507 = ((((((int)((unsigned int)((int)((unsigned int)v96 >> 2)) >> 1)) & 1) * 2) + ((((v115 + ((~(((v117 ^ -1) | (-(v117 ^ -1))) >> 31)) & 2)) - (v118 + ((~(((v119 ^ -1) | (-(v119 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
    v178[v507] = v176;
    int * v180 = v94->cache_tags;
    int v510 = ((((int)((unsigned int)((int)((unsigned int)v96 >> 2)) >> 1)) & 1) * 2) + ((((v115 + ((~(((v117 ^ -1) | (-(v117 ^ -1))) >> 31)) & 2)) - (v118 + ((~(((v119 ^ -1) | (-(v119 ^ -1))) >> 31)) & 2))) >> 31) & 1);
    int v511 = (int)((unsigned int)((int)((unsigned int)v96 >> 2)) >> 1);
    v180[v510] = v511;
    int * v182 = v94->cache_dirty;
    v182[v510] = 0;
    int * v184 = v94->cache_age;
    v184[v510] = 1;
    int * v186 = v94->cache_age;
    int v187 = v186[v510];
    int v188 = v186[v439];
    int v517 = v188 + ((int)((unsigned int)(v188 - v187) >> 31));
    v186[v439] = v517;
    int * v190 = v94->cache_age;
    int v191 = v190[v440];
    int v519 = v191 + ((int)((unsigned int)(v191 - v187) >> 31));
    v190[v440] = v519;
    int * v193 = v94->cache_age;
    v193[v510] = 0;
    v196 = v510;
  }
  int * v197 = v94->cache_vals;
  int v522 = (v196 * 2) + (((int)((unsigned int)v96 >> 2)) & 1);
  v197[v522] = 0;
  int * v199 = v94->cache_tags;
  int v200 = v199[v441];
  int v201 = v199[v442];
  bool v525 = !(((~(((v200 ^ ((int)((unsigned int)((int)((unsigned int)v96 >> 2)) >> 1))) | (-(v200 ^ ((int)((unsigned int)((int)((unsigned int)v96 >> 2)) >> 1))))) >> 31)) | (~(((v201 ^ ((int)((unsigned int)((int)((unsigned int)v96 >> 2)) >> 1))) | (-(v201 ^ ((int)((unsigned int)((int)((unsigned int)v96 >> 2)) >> 1))))) >> 31))) == 0);
  int v255;
  if (v525) {
    int * v202 = v94->cache_age;
    int v527 = (4 + ((((int)((unsigned int)((int)((unsigned int)v96 >> 2)) >> 1)) & 3) * 2)) + ((~(((v201 ^ ((int)((unsigned int)((int)((unsigned int)v96 >> 2)) >> 1))) | (-(v201 ^ ((int)((unsigned int)((int)((unsigned int)v96 >> 2)) >> 1))))) >> 31)) & 1);
    int v203 = v202[v527];
    int v204 = v202[v441];
    int v528 = v204 + ((int)((unsigned int)(v204 - v203) >> 31));
    v202[v441] = v528;
    int * v206 = v94->cache_age;
    int v207 = v206[v442];
    int v530 = v207 + ((int)((unsigned int)(v207 - v203) >> 31));
    v206[v442] = v530;
    int * v209 = v94->cache_age;
    v209[v527] = 0;
    v255 = v527;
  } else {
    int * v212 = v94->cache_age;
    int v533 = 4 + ((((int)((unsigned int)((int)((unsigned int)v96 >> 2)) >> 1)) & 3) * 2);
    int v213 = v212[v533];
    int * v214 = v94->cache_tags;
    int v215 = v214[v533];
    int v216 = v212[v442];
    int v217 = v214[v442];
    int * v218 = v94->cache_dirty;
    int v536 = (4 + ((((int)((unsigned int)((int)((unsigned int)v96 >> 2)) >> 1)) & 3) * 2)) + ((((v213 + ((~(((v215 ^ -1) | (-(v215 ^ -1))) >> 31)) & 2)) - (v216 + ((~(((v217 ^ -1) | (-(v217 ^ -1))) >> 31)) & 2))) >> 31) & 1);
    int v219 = v218[v536];
    bool v537 = !(v219 == 0);
    if (v537) {
      int * v220 = v94->cache_tags;
      int v221 = v220[v536];
      int * v222 = v94->cache_vals;
      int v540 = ((4 + ((((int)((unsigned int)((int)((unsigned int)v96 >> 2)) >> 1)) & 3) * 2)) + ((((v213 + ((~(((v215 ^ -1) | (-(v215 ^ -1))) >> 31)) & 2)) - (v216 + ((~(((v217 ^ -1) | (-(v217 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
      int v223 = v222[v540];
      int v541 = (((4 + ((((int)((unsigned int)((int)((unsigned int)v96 >> 2)) >> 1)) & 3) * 2)) + ((((v213 + ((~(((v215 ^ -1) | (-(v215 ^ -1))) >> 31)) & 2)) - (v216 + ((~(((v217 ^ -1) | (-(v217 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
      int v224 = v222[v541];
      int * v225 = v94->mem;
      int v543 = v221 * 2;
      v225[v543] = v223;
      int * v227 = v94->mem;
      int v546 = (v221 * 2) + 1;
      v227[v546] = v224;
      ;
    } else {
      ;
    }
    int * v232 = v94->mem;
    int v551 = ((int)((unsigned int)((int)((unsigned int)v96 >> 2)) >> 1)) * 2;
    int v233 = v232[v551];
    int v552 = (((int)((unsigned int)((int)((unsigned int)v96 >> 2)) >> 1)) * 2) + 1;
    int v234 = v232[v552];
    int * v235 = v94->cache_vals;
    int v554 = ((4 + ((((int)((unsigned int)((int)((unsigned int)v96 >> 2)) >> 1)) & 3) * 2)) + ((((v213 + ((~(((v215 ^ -1) | (-(v215 ^ -1))) >> 31)) & 2)) - (v216 + ((~(((v217 ^ -1) | (-(v217 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
    v235[v554] = v233;
    int * v237 = v94->cache_vals;
    int v557 = (((4 + ((((int)((unsigned int)((int)((unsigned int)v96 >> 2)) >> 1)) & 3) * 2)) + ((((v213 + ((~(((v215 ^ -1) | (-(v215 ^ -1))) >> 31)) & 2)) - (v216 + ((~(((v217 ^ -1) | (-(v217 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
    v237[v557] = v234;
    int * v239 = v94->cache_tags;
    int v560 = (int)((unsigned int)((int)((unsigned int)v96 >> 2)) >> 1);
    v239[v536] = v560;
    int * v241 = v94->cache_dirty;
    v241[v536] = 0;
    int * v243 = v94->cache_age;
    v243[v536] = 1;
    int * v245 = v94->cache_age;
    int v246 = v245[v536];
    int v247 = v245[v441];
    int v565 = v247 + ((int)((unsigned int)(v247 - v246) >> 31));
    v245[v441] = v565;
    int * v249 = v94->cache_age;
    int v250 = v249[v442];
    int v567 = v250 + ((int)((unsigned int)(v250 - v246) >> 31));
    v249[v442] = v567;
    int * v252 = v94->cache_age;
    v252[v536] = 0;
    v255 = v536;
  }
  int * v256 = v94->cache_vals;
  int v570 = (v255 * 2) + (((int)((unsigned int)v96 >> 2)) & 1);
  v256[v570] = 0;
  int * v258 = v94->cache_dirty;
  v258[v255] = 1;
  struct StateT * v260 = v81->b;
  int * v261 = v260->regs;
  int v262 = v261[6];
  int * v263 = v260->cache_tags;
  int v577 = (((int)((unsigned int)((int)((unsigned int)v262 >> 2)) >> 1)) & 1) * 2;
  int v264 = v263[v577];
  int v578 = ((((int)((unsigned int)((int)((unsigned int)v262 >> 2)) >> 1)) & 1) * 2) + 1;
  int v265 = v263[v578];
  int v579 = 4 + ((((int)((unsigned int)((int)((unsigned int)v262 >> 2)) >> 1)) & 3) * 2);
  int v266 = v263[v579];
  int v580 = (4 + ((((int)((unsigned int)((int)((unsigned int)v262 >> 2)) >> 1)) & 3) * 2)) + 1;
  int v267 = v263[v580];
  int v268 = v260->timer;
  int v581 = v268 + ((100 ^ (((~(((v266 ^ ((int)((unsigned int)((int)((unsigned int)v262 >> 2)) >> 1))) | (-(v266 ^ ((int)((unsigned int)((int)((unsigned int)v262 >> 2)) >> 1))))) >> 31)) | (~(((v267 ^ ((int)((unsigned int)((int)((unsigned int)v262 >> 2)) >> 1))) | (-(v267 ^ ((int)((unsigned int)((int)((unsigned int)v262 >> 2)) >> 1))))) >> 31))) & 104)) ^ (((~(((v264 ^ ((int)((unsigned int)((int)((unsigned int)v262 >> 2)) >> 1))) | (-(v264 ^ ((int)((unsigned int)((int)((unsigned int)v262 >> 2)) >> 1))))) >> 31)) | (~(((v265 ^ ((int)((unsigned int)((int)((unsigned int)v262 >> 2)) >> 1))) | (-(v265 ^ ((int)((unsigned int)((int)((unsigned int)v262 >> 2)) >> 1))))) >> 31))) & (1 ^ (100 ^ (((~(((v266 ^ ((int)((unsigned int)((int)((unsigned int)v262 >> 2)) >> 1))) | (-(v266 ^ ((int)((unsigned int)((int)((unsigned int)v262 >> 2)) >> 1))))) >> 31)) | (~(((v267 ^ ((int)((unsigned int)((int)((unsigned int)v262 >> 2)) >> 1))) | (-(v267 ^ ((int)((unsigned int)((int)((unsigned int)v262 >> 2)) >> 1))))) >> 31))) & 104)))));
  v260->timer = v581;
  bool v582 = !(((~(((v264 ^ ((int)((unsigned int)((int)((unsigned int)v262 >> 2)) >> 1))) | (-(v264 ^ ((int)((unsigned int)((int)((unsigned int)v262 >> 2)) >> 1))))) >> 31)) | (~(((v265 ^ ((int)((unsigned int)((int)((unsigned int)v262 >> 2)) >> 1))) | (-(v265 ^ ((int)((unsigned int)((int)((unsigned int)v262 >> 2)) >> 1))))) >> 31))) == 0);
  int v362;
  if (v582) {
    int * v270 = v260->cache_age;
    int v584 = ((((int)((unsigned int)((int)((unsigned int)v262 >> 2)) >> 1)) & 1) * 2) + ((~(((v265 ^ ((int)((unsigned int)((int)((unsigned int)v262 >> 2)) >> 1))) | (-(v265 ^ ((int)((unsigned int)((int)((unsigned int)v262 >> 2)) >> 1))))) >> 31)) & 1);
    int v271 = v270[v584];
    int v272 = v270[v577];
    int v585 = v272 + ((int)((unsigned int)(v272 - v271) >> 31));
    v270[v577] = v585;
    int * v274 = v260->cache_age;
    int v275 = v274[v578];
    int v587 = v275 + ((int)((unsigned int)(v275 - v271) >> 31));
    v274[v578] = v587;
    int * v277 = v260->cache_age;
    v277[v584] = 0;
    v362 = v584;
  } else {
    int * v280 = v260->cache_age;
    int v590 = (((int)((unsigned int)((int)((unsigned int)v262 >> 2)) >> 1)) & 1) * 2;
    int v281 = v280[v590];
    int * v282 = v260->cache_tags;
    int v283 = v282[v590];
    int v284 = v280[v578];
    int v285 = v282[v578];
    bool v592 = !(((~(((v266 ^ ((int)((unsigned int)((int)((unsigned int)v262 >> 2)) >> 1))) | (-(v266 ^ ((int)((unsigned int)((int)((unsigned int)v262 >> 2)) >> 1))))) >> 31)) | (~(((v267 ^ ((int)((unsigned int)((int)((unsigned int)v262 >> 2)) >> 1))) | (-(v267 ^ ((int)((unsigned int)((int)((unsigned int)v262 >> 2)) >> 1))))) >> 31))) == 0);
    int v339;
    if (v592) {
      int * v286 = v260->cache_age;
      int v594 = (4 + ((((int)((unsigned int)((int)((unsigned int)v262 >> 2)) >> 1)) & 3) * 2)) + ((~(((v267 ^ ((int)((unsigned int)((int)((unsigned int)v262 >> 2)) >> 1))) | (-(v267 ^ ((int)((unsigned int)((int)((unsigned int)v262 >> 2)) >> 1))))) >> 31)) & 1);
      int v287 = v286[v594];
      int v288 = v286[v579];
      int v595 = v288 + ((int)((unsigned int)(v288 - v287) >> 31));
      v286[v579] = v595;
      int * v290 = v260->cache_age;
      int v291 = v290[v580];
      int v597 = v291 + ((int)((unsigned int)(v291 - v287) >> 31));
      v290[v580] = v597;
      int * v293 = v260->cache_age;
      v293[v594] = 0;
      v339 = v594;
    } else {
      int * v296 = v260->cache_age;
      int v600 = 4 + ((((int)((unsigned int)((int)((unsigned int)v262 >> 2)) >> 1)) & 3) * 2);
      int v297 = v296[v600];
      int * v298 = v260->cache_tags;
      int v299 = v298[v600];
      int v300 = v296[v580];
      int v301 = v298[v580];
      int * v302 = v260->cache_dirty;
      int v603 = (4 + ((((int)((unsigned int)((int)((unsigned int)v262 >> 2)) >> 1)) & 3) * 2)) + ((((v297 + ((~(((v299 ^ -1) | (-(v299 ^ -1))) >> 31)) & 2)) - (v300 + ((~(((v301 ^ -1) | (-(v301 ^ -1))) >> 31)) & 2))) >> 31) & 1);
      int v303 = v302[v603];
      bool v604 = !(v303 == 0);
      if (v604) {
        int * v304 = v260->cache_tags;
        int v305 = v304[v603];
        int * v306 = v260->cache_vals;
        int v607 = ((4 + ((((int)((unsigned int)((int)((unsigned int)v262 >> 2)) >> 1)) & 3) * 2)) + ((((v297 + ((~(((v299 ^ -1) | (-(v299 ^ -1))) >> 31)) & 2)) - (v300 + ((~(((v301 ^ -1) | (-(v301 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
        int v307 = v306[v607];
        int v608 = (((4 + ((((int)((unsigned int)((int)((unsigned int)v262 >> 2)) >> 1)) & 3) * 2)) + ((((v297 + ((~(((v299 ^ -1) | (-(v299 ^ -1))) >> 31)) & 2)) - (v300 + ((~(((v301 ^ -1) | (-(v301 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
        int v308 = v306[v608];
        int * v309 = v260->mem;
        int v610 = v305 * 2;
        v309[v610] = v307;
        int * v311 = v260->mem;
        int v613 = (v305 * 2) + 1;
        v311[v613] = v308;
        ;
      } else {
        ;
      }
      int * v316 = v260->mem;
      int v618 = ((int)((unsigned int)((int)((unsigned int)v262 >> 2)) >> 1)) * 2;
      int v317 = v316[v618];
      int v619 = (((int)((unsigned int)((int)((unsigned int)v262 >> 2)) >> 1)) * 2) + 1;
      int v318 = v316[v619];
      int * v319 = v260->cache_vals;
      int v621 = ((4 + ((((int)((unsigned int)((int)((unsigned int)v262 >> 2)) >> 1)) & 3) * 2)) + ((((v297 + ((~(((v299 ^ -1) | (-(v299 ^ -1))) >> 31)) & 2)) - (v300 + ((~(((v301 ^ -1) | (-(v301 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
      v319[v621] = v317;
      int * v321 = v260->cache_vals;
      int v624 = (((4 + ((((int)((unsigned int)((int)((unsigned int)v262 >> 2)) >> 1)) & 3) * 2)) + ((((v297 + ((~(((v299 ^ -1) | (-(v299 ^ -1))) >> 31)) & 2)) - (v300 + ((~(((v301 ^ -1) | (-(v301 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
      v321[v624] = v318;
      int * v323 = v260->cache_tags;
      int v627 = (int)((unsigned int)((int)((unsigned int)v262 >> 2)) >> 1);
      v323[v603] = v627;
      int * v325 = v260->cache_dirty;
      v325[v603] = 0;
      int * v327 = v260->cache_age;
      v327[v603] = 1;
      int * v329 = v260->cache_age;
      int v330 = v329[v603];
      int v331 = v329[v579];
      int v631 = v331 + ((int)((unsigned int)(v331 - v330) >> 31));
      v329[v579] = v631;
      int * v333 = v260->cache_age;
      int v334 = v333[v580];
      int v633 = v334 + ((int)((unsigned int)(v334 - v330) >> 31));
      v333[v580] = v633;
      int * v336 = v260->cache_age;
      v336[v603] = 0;
      v339 = v603;
    }
    int * v340 = v260->cache_vals;
    int v636 = v339 * 2;
    int v341 = v340[v636];
    int v637 = (v339 * 2) + 1;
    int v342 = v340[v637];
    int v638 = (((((int)((unsigned int)((int)((unsigned int)v262 >> 2)) >> 1)) & 1) * 2) + ((((v281 + ((~(((v283 ^ -1) | (-(v283 ^ -1))) >> 31)) & 2)) - (v284 + ((~(((v285 ^ -1) | (-(v285 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
    v340[v638] = v341;
    int * v344 = v260->cache_vals;
    int v641 = ((((((int)((unsigned int)((int)((unsigned int)v262 >> 2)) >> 1)) & 1) * 2) + ((((v281 + ((~(((v283 ^ -1) | (-(v283 ^ -1))) >> 31)) & 2)) - (v284 + ((~(((v285 ^ -1) | (-(v285 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
    v344[v641] = v342;
    int * v346 = v260->cache_tags;
    int v644 = ((((int)((unsigned int)((int)((unsigned int)v262 >> 2)) >> 1)) & 1) * 2) + ((((v281 + ((~(((v283 ^ -1) | (-(v283 ^ -1))) >> 31)) & 2)) - (v284 + ((~(((v285 ^ -1) | (-(v285 ^ -1))) >> 31)) & 2))) >> 31) & 1);
    int v645 = (int)((unsigned int)((int)((unsigned int)v262 >> 2)) >> 1);
    v346[v644] = v645;
    int * v348 = v260->cache_dirty;
    v348[v644] = 0;
    int * v350 = v260->cache_age;
    v350[v644] = 1;
    int * v352 = v260->cache_age;
    int v353 = v352[v644];
    int v354 = v352[v577];
    int v649 = v354 + ((int)((unsigned int)(v354 - v353) >> 31));
    v352[v577] = v649;
    int * v356 = v260->cache_age;
    int v357 = v356[v578];
    int v651 = v357 + ((int)((unsigned int)(v357 - v353) >> 31));
    v356[v578] = v651;
    int * v359 = v260->cache_age;
    v359[v644] = 0;
    v362 = v644;
  }
  int * v363 = v260->cache_vals;
  int v654 = (v362 * 2) + (((int)((unsigned int)v262 >> 2)) & 1);
  v363[v654] = 0;
  int * v365 = v260->cache_tags;
  int v366 = v365[v579];
  int v367 = v365[v580];
  bool v656 = !(((~(((v366 ^ ((int)((unsigned int)((int)((unsigned int)v262 >> 2)) >> 1))) | (-(v366 ^ ((int)((unsigned int)((int)((unsigned int)v262 >> 2)) >> 1))))) >> 31)) | (~(((v367 ^ ((int)((unsigned int)((int)((unsigned int)v262 >> 2)) >> 1))) | (-(v367 ^ ((int)((unsigned int)((int)((unsigned int)v262 >> 2)) >> 1))))) >> 31))) == 0);
  int v421;
  if (v656) {
    int * v368 = v260->cache_age;
    int v658 = (4 + ((((int)((unsigned int)((int)((unsigned int)v262 >> 2)) >> 1)) & 3) * 2)) + ((~(((v367 ^ ((int)((unsigned int)((int)((unsigned int)v262 >> 2)) >> 1))) | (-(v367 ^ ((int)((unsigned int)((int)((unsigned int)v262 >> 2)) >> 1))))) >> 31)) & 1);
    int v369 = v368[v658];
    int v370 = v368[v579];
    int v659 = v370 + ((int)((unsigned int)(v370 - v369) >> 31));
    v368[v579] = v659;
    int * v372 = v260->cache_age;
    int v373 = v372[v580];
    int v661 = v373 + ((int)((unsigned int)(v373 - v369) >> 31));
    v372[v580] = v661;
    int * v375 = v260->cache_age;
    v375[v658] = 0;
    v421 = v658;
  } else {
    int * v378 = v260->cache_age;
    int v664 = 4 + ((((int)((unsigned int)((int)((unsigned int)v262 >> 2)) >> 1)) & 3) * 2);
    int v379 = v378[v664];
    int * v380 = v260->cache_tags;
    int v381 = v380[v664];
    int v382 = v378[v580];
    int v383 = v380[v580];
    int * v384 = v260->cache_dirty;
    int v667 = (4 + ((((int)((unsigned int)((int)((unsigned int)v262 >> 2)) >> 1)) & 3) * 2)) + ((((v379 + ((~(((v381 ^ -1) | (-(v381 ^ -1))) >> 31)) & 2)) - (v382 + ((~(((v383 ^ -1) | (-(v383 ^ -1))) >> 31)) & 2))) >> 31) & 1);
    int v385 = v384[v667];
    bool v668 = !(v385 == 0);
    if (v668) {
      int * v386 = v260->cache_tags;
      int v387 = v386[v667];
      int * v388 = v260->cache_vals;
      int v671 = ((4 + ((((int)((unsigned int)((int)((unsigned int)v262 >> 2)) >> 1)) & 3) * 2)) + ((((v379 + ((~(((v381 ^ -1) | (-(v381 ^ -1))) >> 31)) & 2)) - (v382 + ((~(((v383 ^ -1) | (-(v383 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
      int v389 = v388[v671];
      int v672 = (((4 + ((((int)((unsigned int)((int)((unsigned int)v262 >> 2)) >> 1)) & 3) * 2)) + ((((v379 + ((~(((v381 ^ -1) | (-(v381 ^ -1))) >> 31)) & 2)) - (v382 + ((~(((v383 ^ -1) | (-(v383 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
      int v390 = v388[v672];
      int * v391 = v260->mem;
      int v674 = v387 * 2;
      v391[v674] = v389;
      int * v393 = v260->mem;
      int v677 = (v387 * 2) + 1;
      v393[v677] = v390;
      ;
    } else {
      ;
    }
    int * v398 = v260->mem;
    int v682 = ((int)((unsigned int)((int)((unsigned int)v262 >> 2)) >> 1)) * 2;
    int v399 = v398[v682];
    int v683 = (((int)((unsigned int)((int)((unsigned int)v262 >> 2)) >> 1)) * 2) + 1;
    int v400 = v398[v683];
    int * v401 = v260->cache_vals;
    int v685 = ((4 + ((((int)((unsigned int)((int)((unsigned int)v262 >> 2)) >> 1)) & 3) * 2)) + ((((v379 + ((~(((v381 ^ -1) | (-(v381 ^ -1))) >> 31)) & 2)) - (v382 + ((~(((v383 ^ -1) | (-(v383 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
    v401[v685] = v399;
    int * v403 = v260->cache_vals;
    int v688 = (((4 + ((((int)((unsigned int)((int)((unsigned int)v262 >> 2)) >> 1)) & 3) * 2)) + ((((v379 + ((~(((v381 ^ -1) | (-(v381 ^ -1))) >> 31)) & 2)) - (v382 + ((~(((v383 ^ -1) | (-(v383 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
    v403[v688] = v400;
    int * v405 = v260->cache_tags;
    int v691 = (int)((unsigned int)((int)((unsigned int)v262 >> 2)) >> 1);
    v405[v667] = v691;
    int * v407 = v260->cache_dirty;
    v407[v667] = 0;
    int * v409 = v260->cache_age;
    v409[v667] = 1;
    int * v411 = v260->cache_age;
    int v412 = v411[v667];
    int v413 = v411[v579];
    int v695 = v413 + ((int)((unsigned int)(v413 - v412) >> 31));
    v411[v579] = v695;
    int * v415 = v260->cache_age;
    int v416 = v415[v580];
    int v697 = v416 + ((int)((unsigned int)(v416 - v412) >> 31));
    v415[v580] = v697;
    int * v418 = v260->cache_age;
    v418[v667] = 0;
    v421 = v667;
  }
  int * v422 = v260->cache_vals;
  int v700 = (v421 * 2) + (((int)((unsigned int)v262 >> 2)) & 1);
  v422[v700] = 0;
  int * v424 = v260->cache_dirty;
  v424[v421] = 1;
  struct StateT2 * v426 = slot_3(v81);
  return v426;
}

struct StateT2 * slot_7(struct StateT2 * v809) {
  struct StateT * v810 = v809->a;
  int v811 = v810->timer;
  struct StateT * v812 = v809->b;
  int v813 = v812->timer;
  bool v1040 = v811 == v813;
  squared_assert(v1040);
  squared_assume(v1040);
  struct StateT * v816 = v809->a;
  int v817 = v816->timer;
  int v1042 = v817 + 1;
  v816->timer = v1042;
  struct StateT * v819 = v809->b;
  int v820 = v819->timer;
  int v1044 = v820 + 1;
  v819->timer = v1044;
  struct StateT * v822 = v809->a;
  int * v823 = v822->regs;
  int v824 = v823[6];
  int * v825 = v822->cache_tags;
  int v1049 = (((int)((unsigned int)((int)((unsigned int)v824 >> 2)) >> 1)) & 1) * 2;
  int v826 = v825[v1049];
  int v1050 = ((((int)((unsigned int)((int)((unsigned int)v824 >> 2)) >> 1)) & 1) * 2) + 1;
  int v827 = v825[v1050];
  int v1051 = 4 + ((((int)((unsigned int)((int)((unsigned int)v824 >> 2)) >> 1)) & 3) * 2);
  int v828 = v825[v1051];
  int v1052 = (4 + ((((int)((unsigned int)((int)((unsigned int)v824 >> 2)) >> 1)) & 3) * 2)) + 1;
  int v829 = v825[v1052];
  int v830 = v822->timer;
  int v1053 = v830 + ((100 ^ (((~(((v828 ^ ((int)((unsigned int)((int)((unsigned int)v824 >> 2)) >> 1))) | (-(v828 ^ ((int)((unsigned int)((int)((unsigned int)v824 >> 2)) >> 1))))) >> 31)) | (~(((v829 ^ ((int)((unsigned int)((int)((unsigned int)v824 >> 2)) >> 1))) | (-(v829 ^ ((int)((unsigned int)((int)((unsigned int)v824 >> 2)) >> 1))))) >> 31))) & 104)) ^ (((~(((v826 ^ ((int)((unsigned int)((int)((unsigned int)v824 >> 2)) >> 1))) | (-(v826 ^ ((int)((unsigned int)((int)((unsigned int)v824 >> 2)) >> 1))))) >> 31)) | (~(((v827 ^ ((int)((unsigned int)((int)((unsigned int)v824 >> 2)) >> 1))) | (-(v827 ^ ((int)((unsigned int)((int)((unsigned int)v824 >> 2)) >> 1))))) >> 31))) & (1 ^ (100 ^ (((~(((v828 ^ ((int)((unsigned int)((int)((unsigned int)v824 >> 2)) >> 1))) | (-(v828 ^ ((int)((unsigned int)((int)((unsigned int)v824 >> 2)) >> 1))))) >> 31)) | (~(((v829 ^ ((int)((unsigned int)((int)((unsigned int)v824 >> 2)) >> 1))) | (-(v829 ^ ((int)((unsigned int)((int)((unsigned int)v824 >> 2)) >> 1))))) >> 31))) & 104)))));
  v822->timer = v1053;
  int * v832 = v822->cache_vals;
  bool v1054 = !(((~(((v826 ^ ((int)((unsigned int)((int)((unsigned int)v824 >> 2)) >> 1))) | (-(v826 ^ ((int)((unsigned int)((int)((unsigned int)v824 >> 2)) >> 1))))) >> 31)) | (~(((v827 ^ ((int)((unsigned int)((int)((unsigned int)v824 >> 2)) >> 1))) | (-(v827 ^ ((int)((unsigned int)((int)((unsigned int)v824 >> 2)) >> 1))))) >> 31))) == 0);
  int v925;
  if (v1054) {
    int * v833 = v822->cache_age;
    int v1056 = ((((int)((unsigned int)((int)((unsigned int)v824 >> 2)) >> 1)) & 1) * 2) + ((~(((v827 ^ ((int)((unsigned int)((int)((unsigned int)v824 >> 2)) >> 1))) | (-(v827 ^ ((int)((unsigned int)((int)((unsigned int)v824 >> 2)) >> 1))))) >> 31)) & 1);
    int v834 = v833[v1056];
    int v835 = v833[v1049];
    int v1057 = v835 + ((int)((unsigned int)(v835 - v834) >> 31));
    v833[v1049] = v1057;
    int * v837 = v822->cache_age;
    int v838 = v837[v1050];
    int v1059 = v838 + ((int)((unsigned int)(v838 - v834) >> 31));
    v837[v1050] = v1059;
    int * v840 = v822->cache_age;
    v840[v1056] = 0;
    v925 = v1056;
  } else {
    int * v843 = v822->cache_age;
    int v1063 = (((int)((unsigned int)((int)((unsigned int)v824 >> 2)) >> 1)) & 1) * 2;
    int v844 = v843[v1063];
    int * v845 = v822->cache_tags;
    int v846 = v845[v1063];
    int v847 = v843[v1050];
    int v848 = v845[v1050];
    bool v1065 = !(((~(((v828 ^ ((int)((unsigned int)((int)((unsigned int)v824 >> 2)) >> 1))) | (-(v828 ^ ((int)((unsigned int)((int)((unsigned int)v824 >> 2)) >> 1))))) >> 31)) | (~(((v829 ^ ((int)((unsigned int)((int)((unsigned int)v824 >> 2)) >> 1))) | (-(v829 ^ ((int)((unsigned int)((int)((unsigned int)v824 >> 2)) >> 1))))) >> 31))) == 0);
    int v902;
    if (v1065) {
      int * v849 = v822->cache_age;
      int v1067 = (4 + ((((int)((unsigned int)((int)((unsigned int)v824 >> 2)) >> 1)) & 3) * 2)) + ((~(((v829 ^ ((int)((unsigned int)((int)((unsigned int)v824 >> 2)) >> 1))) | (-(v829 ^ ((int)((unsigned int)((int)((unsigned int)v824 >> 2)) >> 1))))) >> 31)) & 1);
      int v850 = v849[v1067];
      int v851 = v849[v1051];
      int v1068 = v851 + ((int)((unsigned int)(v851 - v850) >> 31));
      v849[v1051] = v1068;
      int * v853 = v822->cache_age;
      int v854 = v853[v1052];
      int v1070 = v854 + ((int)((unsigned int)(v854 - v850) >> 31));
      v853[v1052] = v1070;
      int * v856 = v822->cache_age;
      v856[v1067] = 0;
      v902 = v1067;
    } else {
      int * v859 = v822->cache_age;
      int v1074 = 4 + ((((int)((unsigned int)((int)((unsigned int)v824 >> 2)) >> 1)) & 3) * 2);
      int v860 = v859[v1074];
      int * v861 = v822->cache_tags;
      int v862 = v861[v1074];
      int v863 = v859[v1052];
      int v864 = v861[v1052];
      int * v865 = v822->cache_dirty;
      int v1077 = (4 + ((((int)((unsigned int)((int)((unsigned int)v824 >> 2)) >> 1)) & 3) * 2)) + ((((v860 + ((~(((v862 ^ -1) | (-(v862 ^ -1))) >> 31)) & 2)) - (v863 + ((~(((v864 ^ -1) | (-(v864 ^ -1))) >> 31)) & 2))) >> 31) & 1);
      int v866 = v865[v1077];
      bool v1078 = !(v866 == 0);
      if (v1078) {
        int * v867 = v822->cache_tags;
        int v868 = v867[v1077];
        int * v869 = v822->cache_vals;
        int v1081 = ((4 + ((((int)((unsigned int)((int)((unsigned int)v824 >> 2)) >> 1)) & 3) * 2)) + ((((v860 + ((~(((v862 ^ -1) | (-(v862 ^ -1))) >> 31)) & 2)) - (v863 + ((~(((v864 ^ -1) | (-(v864 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
        int v870 = v869[v1081];
        int v1082 = (((4 + ((((int)((unsigned int)((int)((unsigned int)v824 >> 2)) >> 1)) & 3) * 2)) + ((((v860 + ((~(((v862 ^ -1) | (-(v862 ^ -1))) >> 31)) & 2)) - (v863 + ((~(((v864 ^ -1) | (-(v864 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
        int v871 = v869[v1082];
        int * v872 = v822->mem;
        int v1084 = v868 * 2;
        v872[v1084] = v870;
        int * v874 = v822->mem;
        int v1087 = (v868 * 2) + 1;
        v874[v1087] = v871;
        ;
      } else {
        ;
      }
      int * v879 = v822->mem;
      int v1092 = ((int)((unsigned int)((int)((unsigned int)v824 >> 2)) >> 1)) * 2;
      int v880 = v879[v1092];
      int v1093 = (((int)((unsigned int)((int)((unsigned int)v824 >> 2)) >> 1)) * 2) + 1;
      int v881 = v879[v1093];
      int * v882 = v822->cache_vals;
      int v1095 = ((4 + ((((int)((unsigned int)((int)((unsigned int)v824 >> 2)) >> 1)) & 3) * 2)) + ((((v860 + ((~(((v862 ^ -1) | (-(v862 ^ -1))) >> 31)) & 2)) - (v863 + ((~(((v864 ^ -1) | (-(v864 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
      v882[v1095] = v880;
      int * v884 = v822->cache_vals;
      int v1098 = (((4 + ((((int)((unsigned int)((int)((unsigned int)v824 >> 2)) >> 1)) & 3) * 2)) + ((((v860 + ((~(((v862 ^ -1) | (-(v862 ^ -1))) >> 31)) & 2)) - (v863 + ((~(((v864 ^ -1) | (-(v864 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
      v884[v1098] = v881;
      int * v886 = v822->cache_tags;
      int v1101 = (int)((unsigned int)((int)((unsigned int)v824 >> 2)) >> 1);
      v886[v1077] = v1101;
      int * v888 = v822->cache_dirty;
      v888[v1077] = 0;
      int * v890 = v822->cache_age;
      v890[v1077] = 1;
      int * v892 = v822->cache_age;
      int v893 = v892[v1077];
      int v894 = v892[v1051];
      int v1107 = v894 + ((int)((unsigned int)(v894 - v893) >> 31));
      v892[v1051] = v1107;
      int * v896 = v822->cache_age;
      int v897 = v896[v1052];
      int v1109 = v897 + ((int)((unsigned int)(v897 - v893) >> 31));
      v896[v1052] = v1109;
      int * v899 = v822->cache_age;
      v899[v1077] = 0;
      v902 = v1077;
    }
    int * v903 = v822->cache_vals;
    int v1112 = v902 * 2;
    int v904 = v903[v1112];
    int v1113 = (v902 * 2) + 1;
    int v905 = v903[v1113];
    int v1114 = (((((int)((unsigned int)((int)((unsigned int)v824 >> 2)) >> 1)) & 1) * 2) + ((((v844 + ((~(((v846 ^ -1) | (-(v846 ^ -1))) >> 31)) & 2)) - (v847 + ((~(((v848 ^ -1) | (-(v848 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
    v903[v1114] = v904;
    int * v907 = v822->cache_vals;
    int v1117 = ((((((int)((unsigned int)((int)((unsigned int)v824 >> 2)) >> 1)) & 1) * 2) + ((((v844 + ((~(((v846 ^ -1) | (-(v846 ^ -1))) >> 31)) & 2)) - (v847 + ((~(((v848 ^ -1) | (-(v848 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
    v907[v1117] = v905;
    int * v909 = v822->cache_tags;
    int v1120 = ((((int)((unsigned int)((int)((unsigned int)v824 >> 2)) >> 1)) & 1) * 2) + ((((v844 + ((~(((v846 ^ -1) | (-(v846 ^ -1))) >> 31)) & 2)) - (v847 + ((~(((v848 ^ -1) | (-(v848 ^ -1))) >> 31)) & 2))) >> 31) & 1);
    int v1121 = (int)((unsigned int)((int)((unsigned int)v824 >> 2)) >> 1);
    v909[v1120] = v1121;
    int * v911 = v822->cache_dirty;
    v911[v1120] = 0;
    int * v913 = v822->cache_age;
    v913[v1120] = 1;
    int * v915 = v822->cache_age;
    int v916 = v915[v1120];
    int v917 = v915[v1049];
    int v1127 = v917 + ((int)((unsigned int)(v917 - v916) >> 31));
    v915[v1049] = v1127;
    int * v919 = v822->cache_age;
    int v920 = v919[v1050];
    int v1129 = v920 + ((int)((unsigned int)(v920 - v916) >> 31));
    v919[v1050] = v1129;
    int * v922 = v822->cache_age;
    v922[v1120] = 0;
    v925 = v1120;
  }
  int v1132 = (v925 * 2) + (((int)((unsigned int)v824 >> 2)) & 1);
  int v926 = v832[v1132];
  int * v927 = v822->regs;
  v927[11] = v926;
  struct StateT * v929 = v809->b;
  int * v930 = v929->regs;
  int v931 = v930[6];
  int * v932 = v929->cache_tags;
  int v1139 = (((int)((unsigned int)((int)((unsigned int)v931 >> 2)) >> 1)) & 1) * 2;
  int v933 = v932[v1139];
  int v1140 = ((((int)((unsigned int)((int)((unsigned int)v931 >> 2)) >> 1)) & 1) * 2) + 1;
  int v934 = v932[v1140];
  int v1141 = 4 + ((((int)((unsigned int)((int)((unsigned int)v931 >> 2)) >> 1)) & 3) * 2);
  int v935 = v932[v1141];
  int v1142 = (4 + ((((int)((unsigned int)((int)((unsigned int)v931 >> 2)) >> 1)) & 3) * 2)) + 1;
  int v936 = v932[v1142];
  int v937 = v929->timer;
  int v1143 = v937 + ((100 ^ (((~(((v935 ^ ((int)((unsigned int)((int)((unsigned int)v931 >> 2)) >> 1))) | (-(v935 ^ ((int)((unsigned int)((int)((unsigned int)v931 >> 2)) >> 1))))) >> 31)) | (~(((v936 ^ ((int)((unsigned int)((int)((unsigned int)v931 >> 2)) >> 1))) | (-(v936 ^ ((int)((unsigned int)((int)((unsigned int)v931 >> 2)) >> 1))))) >> 31))) & 104)) ^ (((~(((v933 ^ ((int)((unsigned int)((int)((unsigned int)v931 >> 2)) >> 1))) | (-(v933 ^ ((int)((unsigned int)((int)((unsigned int)v931 >> 2)) >> 1))))) >> 31)) | (~(((v934 ^ ((int)((unsigned int)((int)((unsigned int)v931 >> 2)) >> 1))) | (-(v934 ^ ((int)((unsigned int)((int)((unsigned int)v931 >> 2)) >> 1))))) >> 31))) & (1 ^ (100 ^ (((~(((v935 ^ ((int)((unsigned int)((int)((unsigned int)v931 >> 2)) >> 1))) | (-(v935 ^ ((int)((unsigned int)((int)((unsigned int)v931 >> 2)) >> 1))))) >> 31)) | (~(((v936 ^ ((int)((unsigned int)((int)((unsigned int)v931 >> 2)) >> 1))) | (-(v936 ^ ((int)((unsigned int)((int)((unsigned int)v931 >> 2)) >> 1))))) >> 31))) & 104)))));
  v929->timer = v1143;
  int * v939 = v929->cache_vals;
  bool v1144 = !(((~(((v933 ^ ((int)((unsigned int)((int)((unsigned int)v931 >> 2)) >> 1))) | (-(v933 ^ ((int)((unsigned int)((int)((unsigned int)v931 >> 2)) >> 1))))) >> 31)) | (~(((v934 ^ ((int)((unsigned int)((int)((unsigned int)v931 >> 2)) >> 1))) | (-(v934 ^ ((int)((unsigned int)((int)((unsigned int)v931 >> 2)) >> 1))))) >> 31))) == 0);
  int v1032;
  if (v1144) {
    int * v940 = v929->cache_age;
    int v1146 = ((((int)((unsigned int)((int)((unsigned int)v931 >> 2)) >> 1)) & 1) * 2) + ((~(((v934 ^ ((int)((unsigned int)((int)((unsigned int)v931 >> 2)) >> 1))) | (-(v934 ^ ((int)((unsigned int)((int)((unsigned int)v931 >> 2)) >> 1))))) >> 31)) & 1);
    int v941 = v940[v1146];
    int v942 = v940[v1139];
    int v1147 = v942 + ((int)((unsigned int)(v942 - v941) >> 31));
    v940[v1139] = v1147;
    int * v944 = v929->cache_age;
    int v945 = v944[v1140];
    int v1149 = v945 + ((int)((unsigned int)(v945 - v941) >> 31));
    v944[v1140] = v1149;
    int * v947 = v929->cache_age;
    v947[v1146] = 0;
    v1032 = v1146;
  } else {
    int * v950 = v929->cache_age;
    int v1153 = (((int)((unsigned int)((int)((unsigned int)v931 >> 2)) >> 1)) & 1) * 2;
    int v951 = v950[v1153];
    int * v952 = v929->cache_tags;
    int v953 = v952[v1153];
    int v954 = v950[v1140];
    int v955 = v952[v1140];
    bool v1155 = !(((~(((v935 ^ ((int)((unsigned int)((int)((unsigned int)v931 >> 2)) >> 1))) | (-(v935 ^ ((int)((unsigned int)((int)((unsigned int)v931 >> 2)) >> 1))))) >> 31)) | (~(((v936 ^ ((int)((unsigned int)((int)((unsigned int)v931 >> 2)) >> 1))) | (-(v936 ^ ((int)((unsigned int)((int)((unsigned int)v931 >> 2)) >> 1))))) >> 31))) == 0);
    int v1009;
    if (v1155) {
      int * v956 = v929->cache_age;
      int v1157 = (4 + ((((int)((unsigned int)((int)((unsigned int)v931 >> 2)) >> 1)) & 3) * 2)) + ((~(((v936 ^ ((int)((unsigned int)((int)((unsigned int)v931 >> 2)) >> 1))) | (-(v936 ^ ((int)((unsigned int)((int)((unsigned int)v931 >> 2)) >> 1))))) >> 31)) & 1);
      int v957 = v956[v1157];
      int v958 = v956[v1141];
      int v1158 = v958 + ((int)((unsigned int)(v958 - v957) >> 31));
      v956[v1141] = v1158;
      int * v960 = v929->cache_age;
      int v961 = v960[v1142];
      int v1160 = v961 + ((int)((unsigned int)(v961 - v957) >> 31));
      v960[v1142] = v1160;
      int * v963 = v929->cache_age;
      v963[v1157] = 0;
      v1009 = v1157;
    } else {
      int * v966 = v929->cache_age;
      int v1164 = 4 + ((((int)((unsigned int)((int)((unsigned int)v931 >> 2)) >> 1)) & 3) * 2);
      int v967 = v966[v1164];
      int * v968 = v929->cache_tags;
      int v969 = v968[v1164];
      int v970 = v966[v1142];
      int v971 = v968[v1142];
      int * v972 = v929->cache_dirty;
      int v1167 = (4 + ((((int)((unsigned int)((int)((unsigned int)v931 >> 2)) >> 1)) & 3) * 2)) + ((((v967 + ((~(((v969 ^ -1) | (-(v969 ^ -1))) >> 31)) & 2)) - (v970 + ((~(((v971 ^ -1) | (-(v971 ^ -1))) >> 31)) & 2))) >> 31) & 1);
      int v973 = v972[v1167];
      bool v1168 = !(v973 == 0);
      if (v1168) {
        int * v974 = v929->cache_tags;
        int v975 = v974[v1167];
        int * v976 = v929->cache_vals;
        int v1171 = ((4 + ((((int)((unsigned int)((int)((unsigned int)v931 >> 2)) >> 1)) & 3) * 2)) + ((((v967 + ((~(((v969 ^ -1) | (-(v969 ^ -1))) >> 31)) & 2)) - (v970 + ((~(((v971 ^ -1) | (-(v971 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
        int v977 = v976[v1171];
        int v1172 = (((4 + ((((int)((unsigned int)((int)((unsigned int)v931 >> 2)) >> 1)) & 3) * 2)) + ((((v967 + ((~(((v969 ^ -1) | (-(v969 ^ -1))) >> 31)) & 2)) - (v970 + ((~(((v971 ^ -1) | (-(v971 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
        int v978 = v976[v1172];
        int * v979 = v929->mem;
        int v1174 = v975 * 2;
        v979[v1174] = v977;
        int * v981 = v929->mem;
        int v1177 = (v975 * 2) + 1;
        v981[v1177] = v978;
        ;
      } else {
        ;
      }
      int * v986 = v929->mem;
      int v1182 = ((int)((unsigned int)((int)((unsigned int)v931 >> 2)) >> 1)) * 2;
      int v987 = v986[v1182];
      int v1183 = (((int)((unsigned int)((int)((unsigned int)v931 >> 2)) >> 1)) * 2) + 1;
      int v988 = v986[v1183];
      int * v989 = v929->cache_vals;
      int v1185 = ((4 + ((((int)((unsigned int)((int)((unsigned int)v931 >> 2)) >> 1)) & 3) * 2)) + ((((v967 + ((~(((v969 ^ -1) | (-(v969 ^ -1))) >> 31)) & 2)) - (v970 + ((~(((v971 ^ -1) | (-(v971 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
      v989[v1185] = v987;
      int * v991 = v929->cache_vals;
      int v1188 = (((4 + ((((int)((unsigned int)((int)((unsigned int)v931 >> 2)) >> 1)) & 3) * 2)) + ((((v967 + ((~(((v969 ^ -1) | (-(v969 ^ -1))) >> 31)) & 2)) - (v970 + ((~(((v971 ^ -1) | (-(v971 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
      v991[v1188] = v988;
      int * v993 = v929->cache_tags;
      int v1191 = (int)((unsigned int)((int)((unsigned int)v931 >> 2)) >> 1);
      v993[v1167] = v1191;
      int * v995 = v929->cache_dirty;
      v995[v1167] = 0;
      int * v997 = v929->cache_age;
      v997[v1167] = 1;
      int * v999 = v929->cache_age;
      int v1000 = v999[v1167];
      int v1001 = v999[v1141];
      int v1197 = v1001 + ((int)((unsigned int)(v1001 - v1000) >> 31));
      v999[v1141] = v1197;
      int * v1003 = v929->cache_age;
      int v1004 = v1003[v1142];
      int v1199 = v1004 + ((int)((unsigned int)(v1004 - v1000) >> 31));
      v1003[v1142] = v1199;
      int * v1006 = v929->cache_age;
      v1006[v1167] = 0;
      v1009 = v1167;
    }
    int * v1010 = v929->cache_vals;
    int v1202 = v1009 * 2;
    int v1011 = v1010[v1202];
    int v1203 = (v1009 * 2) + 1;
    int v1012 = v1010[v1203];
    int v1204 = (((((int)((unsigned int)((int)((unsigned int)v931 >> 2)) >> 1)) & 1) * 2) + ((((v951 + ((~(((v953 ^ -1) | (-(v953 ^ -1))) >> 31)) & 2)) - (v954 + ((~(((v955 ^ -1) | (-(v955 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
    v1010[v1204] = v1011;
    int * v1014 = v929->cache_vals;
    int v1207 = ((((((int)((unsigned int)((int)((unsigned int)v931 >> 2)) >> 1)) & 1) * 2) + ((((v951 + ((~(((v953 ^ -1) | (-(v953 ^ -1))) >> 31)) & 2)) - (v954 + ((~(((v955 ^ -1) | (-(v955 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
    v1014[v1207] = v1012;
    int * v1016 = v929->cache_tags;
    int v1210 = ((((int)((unsigned int)((int)((unsigned int)v931 >> 2)) >> 1)) & 1) * 2) + ((((v951 + ((~(((v953 ^ -1) | (-(v953 ^ -1))) >> 31)) & 2)) - (v954 + ((~(((v955 ^ -1) | (-(v955 ^ -1))) >> 31)) & 2))) >> 31) & 1);
    int v1211 = (int)((unsigned int)((int)((unsigned int)v931 >> 2)) >> 1);
    v1016[v1210] = v1211;
    int * v1018 = v929->cache_dirty;
    v1018[v1210] = 0;
    int * v1020 = v929->cache_age;
    v1020[v1210] = 1;
    int * v1022 = v929->cache_age;
    int v1023 = v1022[v1210];
    int v1024 = v1022[v1139];
    int v1217 = v1024 + ((int)((unsigned int)(v1024 - v1023) >> 31));
    v1022[v1139] = v1217;
    int * v1026 = v929->cache_age;
    int v1027 = v1026[v1140];
    int v1219 = v1027 + ((int)((unsigned int)(v1027 - v1023) >> 31));
    v1026[v1140] = v1219;
    int * v1029 = v929->cache_age;
    v1029[v1210] = 0;
    v1032 = v1210;
  }
  int v1222 = (v1032 * 2) + (((int)((unsigned int)v931 >> 2)) & 1);
  int v1033 = v939[v1222];
  int * v1034 = v929->regs;
  v1034[11] = v1033;
  struct StateT2 * v1036 = slot_8(v809);
  return v1036;
}

struct StateT2 * slot_3(struct StateT2 * v705) {
  struct StateT * v706 = v705->a;
  int v707 = v706->timer;
  struct StateT * v708 = v705->b;
  int v709 = v708->timer;
  bool v724 = v707 == v709;
  squared_assert(v724);
  squared_assume(v724);
  struct StateT * v712 = v705->a;
  int v713 = v712->timer;
  int v726 = v713 + 1;
  v712->timer = v726;
  struct StateT * v715 = v705->b;
  int v716 = v715->timer;
  int v728 = v716 + 1;
  v715->timer = v728;
  struct StateT2 * v720 = slot_4(v705);
  return v720;
}

struct StateT2 * slot_0(struct StateT2 * v2) {
  struct StateT * v3 = v2->a;
  int v4 = v3->timer;
  struct StateT * v5 = v2->b;
  int v6 = v5->timer;
  bool v27 = v4 == v6;
  squared_assert(v27);
  squared_assume(v27);
  struct StateT * v9 = v2->a;
  int v10 = v9->timer;
  int v29 = v10 + 1;
  v9->timer = v29;
  struct StateT * v12 = v2->b;
  int v13 = v12->timer;
  int v31 = v13 + 1;
  v12->timer = v31;
  struct StateT * v15 = v2->a;
  int * v16 = v15->regs;
  int v17 = v16[10];
  int v36 = v17 & 28;
  v16[6] = v36;
  struct StateT * v19 = v2->b;
  int * v20 = v19->regs;
  int v21 = v20[10];
  int v39 = v21 & 28;
  v20[6] = v39;
  struct StateT2 * v23 = slot_1(v2);
  return v23;
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

void squared_assert(bool c) { koika_assert(c, "timer drift"); }
void squared_diverged(bool c) { koika_assert(c, "control flow diverged"); }
void squared_assume(bool c) { koika_assume(c); }

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
  struct StateT2 p = { .a = &s1, .b = &s2 };
  struct StateT2 *p_ = snippet(&p);
  //@ assert untainted_timer: !\tainted(p_->a->timer==p_->b->timer);
  koika_assert(p_->a->timer==p_->b->timer, "timing leak");
  return 0;
}