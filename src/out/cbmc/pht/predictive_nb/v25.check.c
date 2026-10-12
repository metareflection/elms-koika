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

struct StateT * slot_12(struct StateT * v613);
struct StateT * slot_6(struct StateT * v297);
struct StateT * slot_25(struct StateT * v1238);
struct StateT * slot_16(struct StateT * v720);
struct StateT * slot_23(struct StateT * v1006);
struct StateT * slot_5(struct StateT * v289);
struct StateT * slot_2(struct StateT * v33);
struct StateT * slot_7(struct StateT * v318);
struct StateT * slot_21(struct StateT * v775);
struct StateT * slot_3(struct StateT * v240);
struct StateT * slot_10(struct StateT * v576);
struct StateT * slot_1(struct StateT * v10);
struct StateT * slot_19(struct StateT * v754);
struct StateT * slot_13(struct StateT * v634);
struct StateT * slot_24(struct StateT * v1214);
struct StateT * slot_0(struct StateT * v2);
struct StateT * slot_14(struct StateT * v658);
struct StateT * slot_17(struct StateT * v741);
struct StateT * snippet(struct StateT * v0);
struct StateT * slot_8(struct StateT * v346);
struct StateT * slot_4(struct StateT * v273);
struct StateT * slot_15(struct StateT * v674);
struct StateT * slot_18(struct StateT * v746);
struct StateT * slot_9(struct StateT * v553);
struct StateT * slot_22(struct StateT * v799);
struct StateT * slot_11(struct StateT * v592);
struct StateT * slot_12(struct StateT * v613) {
  int v614 = v613->timer;
  int v625 = v614 + 1;
  v613->timer = v625;
  int * v616 = v613->reg_ready;
  int v617 = v616[11];
  int * v618 = v613->regs;
  int v619 = v618[11];
  int v629 = (v617 + ((v614 - v617) & (~((v614 - v617) >> 31)))) + 1;
  v616[11] = v629;
  int * v621 = v613->regs;
  int v631 = v619 + 4;
  v621[11] = v631;
  struct StateT * v623 = slot_14(v613);
  return v623;
}

struct StateT * slot_6(struct StateT * v297) {
  int v298 = v297->timer;
  int v309 = v298 + 1;
  v297->timer = v309;
  int * v300 = v297->reg_ready;
  int v301 = v300[10];
  int * v302 = v297->regs;
  int v303 = v302[10];
  int v313 = (v301 + ((v298 - v301) & (~((v298 - v301) >> 31)))) + 1;
  v300[10] = v313;
  int * v305 = v297->regs;
  int v315 = v303 + 72;
  v305[10] = v315;
  struct StateT * v307 = slot_8(v297);
  return v307;
}

struct StateT * slot_25(struct StateT * v1238) {
  int v1239 = v1238->timer;
  int v1412 = v1239 + 1;
  v1238->timer = v1412;
  int * v1241 = v1238->reg_ready;
  int * v1243 = v1238->regs;
  int v1244 = v1243[12];
  int v1246 = v1243[10];
  int * v1247 = v1238->cache_tags;
  int v1418 = (((int)((unsigned int)((int)((unsigned int)(v1244 + 68) >> 2)) >> 1)) & 1) * 2;
  int v1248 = v1247[v1418];
  int v1419 = ((((int)((unsigned int)((int)((unsigned int)(v1244 + 68) >> 2)) >> 1)) & 1) * 2) + 1;
  int v1249 = v1247[v1419];
  int v1420 = 4 + ((((int)((unsigned int)((int)((unsigned int)(v1244 + 68) >> 2)) >> 1)) & 3) * 2);
  int v1250 = v1247[v1420];
  int v1421 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v1244 + 68) >> 2)) >> 1)) & 3) * 2)) + 1;
  int v1251 = v1247[v1421];
  int v1252 = v1238->timer;
  int v1422 = v1252 + ((100 ^ (((~(((v1250 ^ ((int)((unsigned int)((int)((unsigned int)(v1244 + 68) >> 2)) >> 1))) | (-(v1250 ^ ((int)((unsigned int)((int)((unsigned int)(v1244 + 68) >> 2)) >> 1))))) >> 31)) | (~(((v1251 ^ ((int)((unsigned int)((int)((unsigned int)(v1244 + 68) >> 2)) >> 1))) | (-(v1251 ^ ((int)((unsigned int)((int)((unsigned int)(v1244 + 68) >> 2)) >> 1))))) >> 31))) & 104)) ^ (((~(((v1248 ^ ((int)((unsigned int)((int)((unsigned int)(v1244 + 68) >> 2)) >> 1))) | (-(v1248 ^ ((int)((unsigned int)((int)((unsigned int)(v1244 + 68) >> 2)) >> 1))))) >> 31)) | (~(((v1249 ^ ((int)((unsigned int)((int)((unsigned int)(v1244 + 68) >> 2)) >> 1))) | (-(v1249 ^ ((int)((unsigned int)((int)((unsigned int)(v1244 + 68) >> 2)) >> 1))))) >> 31))) & (1 ^ (100 ^ (((~(((v1250 ^ ((int)((unsigned int)((int)((unsigned int)(v1244 + 68) >> 2)) >> 1))) | (-(v1250 ^ ((int)((unsigned int)((int)((unsigned int)(v1244 + 68) >> 2)) >> 1))))) >> 31)) | (~(((v1251 ^ ((int)((unsigned int)((int)((unsigned int)(v1244 + 68) >> 2)) >> 1))) | (-(v1251 ^ ((int)((unsigned int)((int)((unsigned int)(v1244 + 68) >> 2)) >> 1))))) >> 31))) & 104)))));
  v1238->timer = v1422;
  bool v1423 = !(((~(((v1248 ^ ((int)((unsigned int)((int)((unsigned int)(v1244 + 68) >> 2)) >> 1))) | (-(v1248 ^ ((int)((unsigned int)((int)((unsigned int)(v1244 + 68) >> 2)) >> 1))))) >> 31)) | (~(((v1249 ^ ((int)((unsigned int)((int)((unsigned int)(v1244 + 68) >> 2)) >> 1))) | (-(v1249 ^ ((int)((unsigned int)((int)((unsigned int)(v1244 + 68) >> 2)) >> 1))))) >> 31))) == 0);
  int v1346;
  if (v1423) {
    int * v1254 = v1238->cache_age;
    int v1425 = ((((int)((unsigned int)((int)((unsigned int)(v1244 + 68) >> 2)) >> 1)) & 1) * 2) + ((~(((v1249 ^ ((int)((unsigned int)((int)((unsigned int)(v1244 + 68) >> 2)) >> 1))) | (-(v1249 ^ ((int)((unsigned int)((int)((unsigned int)(v1244 + 68) >> 2)) >> 1))))) >> 31)) & 1);
    int v1255 = v1254[v1425];
    int v1256 = v1254[v1418];
    int v1426 = v1256 + ((int)((unsigned int)(v1256 - v1255) >> 31));
    v1254[v1418] = v1426;
    int * v1258 = v1238->cache_age;
    int v1259 = v1258[v1419];
    int v1428 = v1259 + ((int)((unsigned int)(v1259 - v1255) >> 31));
    v1258[v1419] = v1428;
    int * v1261 = v1238->cache_age;
    v1261[v1425] = 0;
    v1346 = v1425;
  } else {
    int * v1264 = v1238->cache_age;
    int v1432 = (((int)((unsigned int)((int)((unsigned int)(v1244 + 68) >> 2)) >> 1)) & 1) * 2;
    int v1265 = v1264[v1432];
    int * v1266 = v1238->cache_tags;
    int v1267 = v1266[v1432];
    int v1268 = v1264[v1419];
    int v1269 = v1266[v1419];
    bool v1434 = !(((~(((v1250 ^ ((int)((unsigned int)((int)((unsigned int)(v1244 + 68) >> 2)) >> 1))) | (-(v1250 ^ ((int)((unsigned int)((int)((unsigned int)(v1244 + 68) >> 2)) >> 1))))) >> 31)) | (~(((v1251 ^ ((int)((unsigned int)((int)((unsigned int)(v1244 + 68) >> 2)) >> 1))) | (-(v1251 ^ ((int)((unsigned int)((int)((unsigned int)(v1244 + 68) >> 2)) >> 1))))) >> 31))) == 0);
    int v1323;
    if (v1434) {
      int * v1270 = v1238->cache_age;
      int v1436 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v1244 + 68) >> 2)) >> 1)) & 3) * 2)) + ((~(((v1251 ^ ((int)((unsigned int)((int)((unsigned int)(v1244 + 68) >> 2)) >> 1))) | (-(v1251 ^ ((int)((unsigned int)((int)((unsigned int)(v1244 + 68) >> 2)) >> 1))))) >> 31)) & 1);
      int v1271 = v1270[v1436];
      int v1272 = v1270[v1420];
      int v1437 = v1272 + ((int)((unsigned int)(v1272 - v1271) >> 31));
      v1270[v1420] = v1437;
      int * v1274 = v1238->cache_age;
      int v1275 = v1274[v1421];
      int v1439 = v1275 + ((int)((unsigned int)(v1275 - v1271) >> 31));
      v1274[v1421] = v1439;
      int * v1277 = v1238->cache_age;
      v1277[v1436] = 0;
      v1323 = v1436;
    } else {
      int * v1280 = v1238->cache_age;
      int v1443 = 4 + ((((int)((unsigned int)((int)((unsigned int)(v1244 + 68) >> 2)) >> 1)) & 3) * 2);
      int v1281 = v1280[v1443];
      int * v1282 = v1238->cache_tags;
      int v1283 = v1282[v1443];
      int v1284 = v1280[v1421];
      int v1285 = v1282[v1421];
      int * v1286 = v1238->cache_dirty;
      int v1446 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v1244 + 68) >> 2)) >> 1)) & 3) * 2)) + ((((v1281 + ((~(((v1283 ^ -1) | (-(v1283 ^ -1))) >> 31)) & 2)) - (v1284 + ((~(((v1285 ^ -1) | (-(v1285 ^ -1))) >> 31)) & 2))) >> 31) & 1);
      int v1287 = v1286[v1446];
      bool v1447 = !(v1287 == 0);
      if (v1447) {
        int * v1288 = v1238->cache_tags;
        int v1289 = v1288[v1446];
        int * v1290 = v1238->cache_vals;
        int v1450 = ((4 + ((((int)((unsigned int)((int)((unsigned int)(v1244 + 68) >> 2)) >> 1)) & 3) * 2)) + ((((v1281 + ((~(((v1283 ^ -1) | (-(v1283 ^ -1))) >> 31)) & 2)) - (v1284 + ((~(((v1285 ^ -1) | (-(v1285 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
        int v1291 = v1290[v1450];
        int v1451 = (((4 + ((((int)((unsigned int)((int)((unsigned int)(v1244 + 68) >> 2)) >> 1)) & 3) * 2)) + ((((v1281 + ((~(((v1283 ^ -1) | (-(v1283 ^ -1))) >> 31)) & 2)) - (v1284 + ((~(((v1285 ^ -1) | (-(v1285 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
        int v1292 = v1290[v1451];
        int * v1293 = v1238->mem;
        int v1453 = v1289 * 2;
        v1293[v1453] = v1291;
        int * v1295 = v1238->mem;
        int v1456 = (v1289 * 2) + 1;
        v1295[v1456] = v1292;
        ;
      } else {
        ;
      }
      int * v1300 = v1238->mem;
      int v1461 = ((int)((unsigned int)((int)((unsigned int)(v1244 + 68) >> 2)) >> 1)) * 2;
      int v1301 = v1300[v1461];
      int v1462 = (((int)((unsigned int)((int)((unsigned int)(v1244 + 68) >> 2)) >> 1)) * 2) + 1;
      int v1302 = v1300[v1462];
      int * v1303 = v1238->cache_vals;
      int v1464 = ((4 + ((((int)((unsigned int)((int)((unsigned int)(v1244 + 68) >> 2)) >> 1)) & 3) * 2)) + ((((v1281 + ((~(((v1283 ^ -1) | (-(v1283 ^ -1))) >> 31)) & 2)) - (v1284 + ((~(((v1285 ^ -1) | (-(v1285 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
      v1303[v1464] = v1301;
      int * v1305 = v1238->cache_vals;
      int v1467 = (((4 + ((((int)((unsigned int)((int)((unsigned int)(v1244 + 68) >> 2)) >> 1)) & 3) * 2)) + ((((v1281 + ((~(((v1283 ^ -1) | (-(v1283 ^ -1))) >> 31)) & 2)) - (v1284 + ((~(((v1285 ^ -1) | (-(v1285 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
      v1305[v1467] = v1302;
      int * v1307 = v1238->cache_tags;
      int v1470 = (int)((unsigned int)((int)((unsigned int)(v1244 + 68) >> 2)) >> 1);
      v1307[v1446] = v1470;
      int * v1309 = v1238->cache_dirty;
      v1309[v1446] = 0;
      int * v1311 = v1238->cache_age;
      v1311[v1446] = 1;
      int * v1313 = v1238->cache_age;
      int v1314 = v1313[v1446];
      int v1315 = v1313[v1420];
      int v1476 = v1315 + ((int)((unsigned int)(v1315 - v1314) >> 31));
      v1313[v1420] = v1476;
      int * v1317 = v1238->cache_age;
      int v1318 = v1317[v1421];
      int v1478 = v1318 + ((int)((unsigned int)(v1318 - v1314) >> 31));
      v1317[v1421] = v1478;
      int * v1320 = v1238->cache_age;
      v1320[v1446] = 0;
      v1323 = v1446;
    }
    int * v1324 = v1238->cache_vals;
    int v1481 = v1323 * 2;
    int v1325 = v1324[v1481];
    int v1482 = (v1323 * 2) + 1;
    int v1326 = v1324[v1482];
    int v1483 = (((((int)((unsigned int)((int)((unsigned int)(v1244 + 68) >> 2)) >> 1)) & 1) * 2) + ((((v1265 + ((~(((v1267 ^ -1) | (-(v1267 ^ -1))) >> 31)) & 2)) - (v1268 + ((~(((v1269 ^ -1) | (-(v1269 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
    v1324[v1483] = v1325;
    int * v1328 = v1238->cache_vals;
    int v1486 = ((((((int)((unsigned int)((int)((unsigned int)(v1244 + 68) >> 2)) >> 1)) & 1) * 2) + ((((v1265 + ((~(((v1267 ^ -1) | (-(v1267 ^ -1))) >> 31)) & 2)) - (v1268 + ((~(((v1269 ^ -1) | (-(v1269 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
    v1328[v1486] = v1326;
    int * v1330 = v1238->cache_tags;
    int v1489 = ((((int)((unsigned int)((int)((unsigned int)(v1244 + 68) >> 2)) >> 1)) & 1) * 2) + ((((v1265 + ((~(((v1267 ^ -1) | (-(v1267 ^ -1))) >> 31)) & 2)) - (v1268 + ((~(((v1269 ^ -1) | (-(v1269 ^ -1))) >> 31)) & 2))) >> 31) & 1);
    int v1490 = (int)((unsigned int)((int)((unsigned int)(v1244 + 68) >> 2)) >> 1);
    v1330[v1489] = v1490;
    int * v1332 = v1238->cache_dirty;
    v1332[v1489] = 0;
    int * v1334 = v1238->cache_age;
    v1334[v1489] = 1;
    int * v1336 = v1238->cache_age;
    int v1337 = v1336[v1489];
    int v1338 = v1336[v1418];
    int v1496 = v1338 + ((int)((unsigned int)(v1338 - v1337) >> 31));
    v1336[v1418] = v1496;
    int * v1340 = v1238->cache_age;
    int v1341 = v1340[v1419];
    int v1498 = v1341 + ((int)((unsigned int)(v1341 - v1337) >> 31));
    v1340[v1419] = v1498;
    int * v1343 = v1238->cache_age;
    v1343[v1489] = 0;
    v1346 = v1489;
  }
  int * v1347 = v1238->cache_vals;
  int v1501 = (v1346 * 2) + (((int)((unsigned int)(v1244 + 68) >> 2)) & 1);
  v1347[v1501] = v1246;
  int * v1349 = v1238->cache_tags;
  int v1350 = v1349[v1420];
  int v1351 = v1349[v1421];
  bool v1504 = !(((~(((v1350 ^ ((int)((unsigned int)((int)((unsigned int)(v1244 + 68) >> 2)) >> 1))) | (-(v1350 ^ ((int)((unsigned int)((int)((unsigned int)(v1244 + 68) >> 2)) >> 1))))) >> 31)) | (~(((v1351 ^ ((int)((unsigned int)((int)((unsigned int)(v1244 + 68) >> 2)) >> 1))) | (-(v1351 ^ ((int)((unsigned int)((int)((unsigned int)(v1244 + 68) >> 2)) >> 1))))) >> 31))) == 0);
  int v1405;
  if (v1504) {
    int * v1352 = v1238->cache_age;
    int v1506 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v1244 + 68) >> 2)) >> 1)) & 3) * 2)) + ((~(((v1351 ^ ((int)((unsigned int)((int)((unsigned int)(v1244 + 68) >> 2)) >> 1))) | (-(v1351 ^ ((int)((unsigned int)((int)((unsigned int)(v1244 + 68) >> 2)) >> 1))))) >> 31)) & 1);
    int v1353 = v1352[v1506];
    int v1354 = v1352[v1420];
    int v1507 = v1354 + ((int)((unsigned int)(v1354 - v1353) >> 31));
    v1352[v1420] = v1507;
    int * v1356 = v1238->cache_age;
    int v1357 = v1356[v1421];
    int v1509 = v1357 + ((int)((unsigned int)(v1357 - v1353) >> 31));
    v1356[v1421] = v1509;
    int * v1359 = v1238->cache_age;
    v1359[v1506] = 0;
    v1405 = v1506;
  } else {
    int * v1362 = v1238->cache_age;
    int v1513 = 4 + ((((int)((unsigned int)((int)((unsigned int)(v1244 + 68) >> 2)) >> 1)) & 3) * 2);
    int v1363 = v1362[v1513];
    int * v1364 = v1238->cache_tags;
    int v1365 = v1364[v1513];
    int v1366 = v1362[v1421];
    int v1367 = v1364[v1421];
    int * v1368 = v1238->cache_dirty;
    int v1516 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v1244 + 68) >> 2)) >> 1)) & 3) * 2)) + ((((v1363 + ((~(((v1365 ^ -1) | (-(v1365 ^ -1))) >> 31)) & 2)) - (v1366 + ((~(((v1367 ^ -1) | (-(v1367 ^ -1))) >> 31)) & 2))) >> 31) & 1);
    int v1369 = v1368[v1516];
    bool v1517 = !(v1369 == 0);
    if (v1517) {
      int * v1370 = v1238->cache_tags;
      int v1371 = v1370[v1516];
      int * v1372 = v1238->cache_vals;
      int v1520 = ((4 + ((((int)((unsigned int)((int)((unsigned int)(v1244 + 68) >> 2)) >> 1)) & 3) * 2)) + ((((v1363 + ((~(((v1365 ^ -1) | (-(v1365 ^ -1))) >> 31)) & 2)) - (v1366 + ((~(((v1367 ^ -1) | (-(v1367 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
      int v1373 = v1372[v1520];
      int v1521 = (((4 + ((((int)((unsigned int)((int)((unsigned int)(v1244 + 68) >> 2)) >> 1)) & 3) * 2)) + ((((v1363 + ((~(((v1365 ^ -1) | (-(v1365 ^ -1))) >> 31)) & 2)) - (v1366 + ((~(((v1367 ^ -1) | (-(v1367 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
      int v1374 = v1372[v1521];
      int * v1375 = v1238->mem;
      int v1523 = v1371 * 2;
      v1375[v1523] = v1373;
      int * v1377 = v1238->mem;
      int v1526 = (v1371 * 2) + 1;
      v1377[v1526] = v1374;
      ;
    } else {
      ;
    }
    int * v1382 = v1238->mem;
    int v1531 = ((int)((unsigned int)((int)((unsigned int)(v1244 + 68) >> 2)) >> 1)) * 2;
    int v1383 = v1382[v1531];
    int v1532 = (((int)((unsigned int)((int)((unsigned int)(v1244 + 68) >> 2)) >> 1)) * 2) + 1;
    int v1384 = v1382[v1532];
    int * v1385 = v1238->cache_vals;
    int v1534 = ((4 + ((((int)((unsigned int)((int)((unsigned int)(v1244 + 68) >> 2)) >> 1)) & 3) * 2)) + ((((v1363 + ((~(((v1365 ^ -1) | (-(v1365 ^ -1))) >> 31)) & 2)) - (v1366 + ((~(((v1367 ^ -1) | (-(v1367 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
    v1385[v1534] = v1383;
    int * v1387 = v1238->cache_vals;
    int v1537 = (((4 + ((((int)((unsigned int)((int)((unsigned int)(v1244 + 68) >> 2)) >> 1)) & 3) * 2)) + ((((v1363 + ((~(((v1365 ^ -1) | (-(v1365 ^ -1))) >> 31)) & 2)) - (v1366 + ((~(((v1367 ^ -1) | (-(v1367 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
    v1387[v1537] = v1384;
    int * v1389 = v1238->cache_tags;
    int v1540 = (int)((unsigned int)((int)((unsigned int)(v1244 + 68) >> 2)) >> 1);
    v1389[v1516] = v1540;
    int * v1391 = v1238->cache_dirty;
    v1391[v1516] = 0;
    int * v1393 = v1238->cache_age;
    v1393[v1516] = 1;
    int * v1395 = v1238->cache_age;
    int v1396 = v1395[v1516];
    int v1397 = v1395[v1420];
    int v1546 = v1397 + ((int)((unsigned int)(v1397 - v1396) >> 31));
    v1395[v1420] = v1546;
    int * v1399 = v1238->cache_age;
    int v1400 = v1399[v1421];
    int v1548 = v1400 + ((int)((unsigned int)(v1400 - v1396) >> 31));
    v1399[v1421] = v1548;
    int * v1402 = v1238->cache_age;
    v1402[v1516] = 0;
    v1405 = v1516;
  }
  int * v1406 = v1238->cache_vals;
  int v1551 = (v1405 * 2) + (((int)((unsigned int)(v1244 + 68) >> 2)) & 1);
  v1406[v1551] = v1246;
  int * v1408 = v1238->cache_dirty;
  v1408[v1405] = 1;
  struct StateT * v1410 = slot_17(v1238);
  return v1410;
}

struct StateT * slot_16(struct StateT * v720) {
  int v721 = v720->timer;
  int v732 = v721 + 1;
  v720->timer = v732;
  int * v723 = v720->reg_ready;
  int v724 = v723[10];
  int * v725 = v720->regs;
  int v726 = v725[10];
  int v736 = (v724 + ((v721 - v724) & (~((v721 - v724) >> 31)))) + 1;
  v723[10] = v736;
  int * v728 = v720->regs;
  int v738 = v726 << 29;
  v728[10] = v738;
  struct StateT * v730 = slot_19(v720);
  return v730;
}

struct StateT * slot_23(struct StateT * v1006) {
  int v1007 = v1006->timer;
  int v1119 = v1007 + 1;
  v1006->timer = v1119;
  int * v1009 = v1006->reg_ready;
  int v1010 = v1009[12];
  int * v1011 = v1006->regs;
  int v1012 = v1011[12];
  int * v1013 = v1006->cache_tags;
  int v1124 = (((int)((unsigned int)((int)((unsigned int)(v1012 + 68) >> 2)) >> 1)) & 1) * 2;
  int v1014 = v1013[v1124];
  int v1125 = ((((int)((unsigned int)((int)((unsigned int)(v1012 + 68) >> 2)) >> 1)) & 1) * 2) + 1;
  int v1015 = v1013[v1125];
  int v1126 = 4 + ((((int)((unsigned int)((int)((unsigned int)(v1012 + 68) >> 2)) >> 1)) & 3) * 2);
  int v1016 = v1013[v1126];
  int v1127 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v1012 + 68) >> 2)) >> 1)) & 3) * 2)) + 1;
  int v1017 = v1013[v1127];
  int * v1018 = v1006->cache_vals;
  bool v1128 = !(((~(((v1014 ^ ((int)((unsigned int)((int)((unsigned int)(v1012 + 68) >> 2)) >> 1))) | (-(v1014 ^ ((int)((unsigned int)((int)((unsigned int)(v1012 + 68) >> 2)) >> 1))))) >> 31)) | (~(((v1015 ^ ((int)((unsigned int)((int)((unsigned int)(v1012 + 68) >> 2)) >> 1))) | (-(v1015 ^ ((int)((unsigned int)((int)((unsigned int)(v1012 + 68) >> 2)) >> 1))))) >> 31))) == 0);
  int v1111;
  if (v1128) {
    int * v1019 = v1006->cache_age;
    int v1130 = ((((int)((unsigned int)((int)((unsigned int)(v1012 + 68) >> 2)) >> 1)) & 1) * 2) + ((~(((v1015 ^ ((int)((unsigned int)((int)((unsigned int)(v1012 + 68) >> 2)) >> 1))) | (-(v1015 ^ ((int)((unsigned int)((int)((unsigned int)(v1012 + 68) >> 2)) >> 1))))) >> 31)) & 1);
    int v1020 = v1019[v1130];
    int v1021 = v1019[v1124];
    int v1131 = v1021 + ((int)((unsigned int)(v1021 - v1020) >> 31));
    v1019[v1124] = v1131;
    int * v1023 = v1006->cache_age;
    int v1024 = v1023[v1125];
    int v1133 = v1024 + ((int)((unsigned int)(v1024 - v1020) >> 31));
    v1023[v1125] = v1133;
    int * v1026 = v1006->cache_age;
    v1026[v1130] = 0;
    v1111 = v1130;
  } else {
    int * v1029 = v1006->cache_age;
    int v1137 = (((int)((unsigned int)((int)((unsigned int)(v1012 + 68) >> 2)) >> 1)) & 1) * 2;
    int v1030 = v1029[v1137];
    int * v1031 = v1006->cache_tags;
    int v1032 = v1031[v1137];
    int v1033 = v1029[v1125];
    int v1034 = v1031[v1125];
    bool v1139 = !(((~(((v1016 ^ ((int)((unsigned int)((int)((unsigned int)(v1012 + 68) >> 2)) >> 1))) | (-(v1016 ^ ((int)((unsigned int)((int)((unsigned int)(v1012 + 68) >> 2)) >> 1))))) >> 31)) | (~(((v1017 ^ ((int)((unsigned int)((int)((unsigned int)(v1012 + 68) >> 2)) >> 1))) | (-(v1017 ^ ((int)((unsigned int)((int)((unsigned int)(v1012 + 68) >> 2)) >> 1))))) >> 31))) == 0);
    int v1088;
    if (v1139) {
      int * v1035 = v1006->cache_age;
      int v1141 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v1012 + 68) >> 2)) >> 1)) & 3) * 2)) + ((~(((v1017 ^ ((int)((unsigned int)((int)((unsigned int)(v1012 + 68) >> 2)) >> 1))) | (-(v1017 ^ ((int)((unsigned int)((int)((unsigned int)(v1012 + 68) >> 2)) >> 1))))) >> 31)) & 1);
      int v1036 = v1035[v1141];
      int v1037 = v1035[v1126];
      int v1142 = v1037 + ((int)((unsigned int)(v1037 - v1036) >> 31));
      v1035[v1126] = v1142;
      int * v1039 = v1006->cache_age;
      int v1040 = v1039[v1127];
      int v1144 = v1040 + ((int)((unsigned int)(v1040 - v1036) >> 31));
      v1039[v1127] = v1144;
      int * v1042 = v1006->cache_age;
      v1042[v1141] = 0;
      v1088 = v1141;
    } else {
      int * v1045 = v1006->cache_age;
      int v1148 = 4 + ((((int)((unsigned int)((int)((unsigned int)(v1012 + 68) >> 2)) >> 1)) & 3) * 2);
      int v1046 = v1045[v1148];
      int * v1047 = v1006->cache_tags;
      int v1048 = v1047[v1148];
      int v1049 = v1045[v1127];
      int v1050 = v1047[v1127];
      int * v1051 = v1006->cache_dirty;
      int v1151 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v1012 + 68) >> 2)) >> 1)) & 3) * 2)) + ((((v1046 + ((~(((v1048 ^ -1) | (-(v1048 ^ -1))) >> 31)) & 2)) - (v1049 + ((~(((v1050 ^ -1) | (-(v1050 ^ -1))) >> 31)) & 2))) >> 31) & 1);
      int v1052 = v1051[v1151];
      bool v1152 = !(v1052 == 0);
      if (v1152) {
        int * v1053 = v1006->cache_tags;
        int v1054 = v1053[v1151];
        int * v1055 = v1006->cache_vals;
        int v1155 = ((4 + ((((int)((unsigned int)((int)((unsigned int)(v1012 + 68) >> 2)) >> 1)) & 3) * 2)) + ((((v1046 + ((~(((v1048 ^ -1) | (-(v1048 ^ -1))) >> 31)) & 2)) - (v1049 + ((~(((v1050 ^ -1) | (-(v1050 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
        int v1056 = v1055[v1155];
        int v1156 = (((4 + ((((int)((unsigned int)((int)((unsigned int)(v1012 + 68) >> 2)) >> 1)) & 3) * 2)) + ((((v1046 + ((~(((v1048 ^ -1) | (-(v1048 ^ -1))) >> 31)) & 2)) - (v1049 + ((~(((v1050 ^ -1) | (-(v1050 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
        int v1057 = v1055[v1156];
        int * v1058 = v1006->mem;
        int v1158 = v1054 * 2;
        v1058[v1158] = v1056;
        int * v1060 = v1006->mem;
        int v1161 = (v1054 * 2) + 1;
        v1060[v1161] = v1057;
        ;
      } else {
        ;
      }
      int * v1065 = v1006->mem;
      int v1166 = ((int)((unsigned int)((int)((unsigned int)(v1012 + 68) >> 2)) >> 1)) * 2;
      int v1066 = v1065[v1166];
      int v1167 = (((int)((unsigned int)((int)((unsigned int)(v1012 + 68) >> 2)) >> 1)) * 2) + 1;
      int v1067 = v1065[v1167];
      int * v1068 = v1006->cache_vals;
      int v1169 = ((4 + ((((int)((unsigned int)((int)((unsigned int)(v1012 + 68) >> 2)) >> 1)) & 3) * 2)) + ((((v1046 + ((~(((v1048 ^ -1) | (-(v1048 ^ -1))) >> 31)) & 2)) - (v1049 + ((~(((v1050 ^ -1) | (-(v1050 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
      v1068[v1169] = v1066;
      int * v1070 = v1006->cache_vals;
      int v1172 = (((4 + ((((int)((unsigned int)((int)((unsigned int)(v1012 + 68) >> 2)) >> 1)) & 3) * 2)) + ((((v1046 + ((~(((v1048 ^ -1) | (-(v1048 ^ -1))) >> 31)) & 2)) - (v1049 + ((~(((v1050 ^ -1) | (-(v1050 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
      v1070[v1172] = v1067;
      int * v1072 = v1006->cache_tags;
      int v1175 = (int)((unsigned int)((int)((unsigned int)(v1012 + 68) >> 2)) >> 1);
      v1072[v1151] = v1175;
      int * v1074 = v1006->cache_dirty;
      v1074[v1151] = 0;
      int * v1076 = v1006->cache_age;
      v1076[v1151] = 1;
      int * v1078 = v1006->cache_age;
      int v1079 = v1078[v1151];
      int v1080 = v1078[v1126];
      int v1181 = v1080 + ((int)((unsigned int)(v1080 - v1079) >> 31));
      v1078[v1126] = v1181;
      int * v1082 = v1006->cache_age;
      int v1083 = v1082[v1127];
      int v1183 = v1083 + ((int)((unsigned int)(v1083 - v1079) >> 31));
      v1082[v1127] = v1183;
      int * v1085 = v1006->cache_age;
      v1085[v1151] = 0;
      v1088 = v1151;
    }
    int * v1089 = v1006->cache_vals;
    int v1186 = v1088 * 2;
    int v1090 = v1089[v1186];
    int v1187 = (v1088 * 2) + 1;
    int v1091 = v1089[v1187];
    int v1188 = (((((int)((unsigned int)((int)((unsigned int)(v1012 + 68) >> 2)) >> 1)) & 1) * 2) + ((((v1030 + ((~(((v1032 ^ -1) | (-(v1032 ^ -1))) >> 31)) & 2)) - (v1033 + ((~(((v1034 ^ -1) | (-(v1034 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
    v1089[v1188] = v1090;
    int * v1093 = v1006->cache_vals;
    int v1191 = ((((((int)((unsigned int)((int)((unsigned int)(v1012 + 68) >> 2)) >> 1)) & 1) * 2) + ((((v1030 + ((~(((v1032 ^ -1) | (-(v1032 ^ -1))) >> 31)) & 2)) - (v1033 + ((~(((v1034 ^ -1) | (-(v1034 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
    v1093[v1191] = v1091;
    int * v1095 = v1006->cache_tags;
    int v1194 = ((((int)((unsigned int)((int)((unsigned int)(v1012 + 68) >> 2)) >> 1)) & 1) * 2) + ((((v1030 + ((~(((v1032 ^ -1) | (-(v1032 ^ -1))) >> 31)) & 2)) - (v1033 + ((~(((v1034 ^ -1) | (-(v1034 ^ -1))) >> 31)) & 2))) >> 31) & 1);
    int v1195 = (int)((unsigned int)((int)((unsigned int)(v1012 + 68) >> 2)) >> 1);
    v1095[v1194] = v1195;
    int * v1097 = v1006->cache_dirty;
    v1097[v1194] = 0;
    int * v1099 = v1006->cache_age;
    v1099[v1194] = 1;
    int * v1101 = v1006->cache_age;
    int v1102 = v1101[v1194];
    int v1103 = v1101[v1124];
    int v1201 = v1103 + ((int)((unsigned int)(v1103 - v1102) >> 31));
    v1101[v1124] = v1201;
    int * v1105 = v1006->cache_age;
    int v1106 = v1105[v1125];
    int v1203 = v1106 + ((int)((unsigned int)(v1106 - v1102) >> 31));
    v1105[v1125] = v1203;
    int * v1108 = v1006->cache_age;
    v1108[v1194] = 0;
    v1111 = v1194;
  }
  int v1206 = (v1111 * 2) + (((int)((unsigned int)(v1012 + 68) >> 2)) & 1);
  int v1112 = v1018[v1206];
  int * v1113 = v1006->reg_ready;
  int v1209 = ((v1010 + ((v1007 - v1010) & (~((v1007 - v1010) >> 31)))) + 1) + ((100 ^ (((~(((v1016 ^ ((int)((unsigned int)((int)((unsigned int)(v1012 + 68) >> 2)) >> 1))) | (-(v1016 ^ ((int)((unsigned int)((int)((unsigned int)(v1012 + 68) >> 2)) >> 1))))) >> 31)) | (~(((v1017 ^ ((int)((unsigned int)((int)((unsigned int)(v1012 + 68) >> 2)) >> 1))) | (-(v1017 ^ ((int)((unsigned int)((int)((unsigned int)(v1012 + 68) >> 2)) >> 1))))) >> 31))) & 104)) ^ (((~(((v1014 ^ ((int)((unsigned int)((int)((unsigned int)(v1012 + 68) >> 2)) >> 1))) | (-(v1014 ^ ((int)((unsigned int)((int)((unsigned int)(v1012 + 68) >> 2)) >> 1))))) >> 31)) | (~(((v1015 ^ ((int)((unsigned int)((int)((unsigned int)(v1012 + 68) >> 2)) >> 1))) | (-(v1015 ^ ((int)((unsigned int)((int)((unsigned int)(v1012 + 68) >> 2)) >> 1))))) >> 31))) & (1 ^ (100 ^ (((~(((v1016 ^ ((int)((unsigned int)((int)((unsigned int)(v1012 + 68) >> 2)) >> 1))) | (-(v1016 ^ ((int)((unsigned int)((int)((unsigned int)(v1012 + 68) >> 2)) >> 1))))) >> 31)) | (~(((v1017 ^ ((int)((unsigned int)((int)((unsigned int)(v1012 + 68) >> 2)) >> 1))) | (-(v1017 ^ ((int)((unsigned int)((int)((unsigned int)(v1012 + 68) >> 2)) >> 1))))) >> 31))) & 104)))));
  v1113[11] = v1209;
  int * v1115 = v1006->regs;
  v1115[11] = v1112;
  struct StateT * v1117 = slot_24(v1006);
  return v1117;
}

struct StateT * slot_5(struct StateT * v289) {
  int v290 = v289->timer;
  int v294 = v290 + 1;
  v289->timer = v294;
  struct StateT * v292 = slot_7(v289);
  return v292;
}

struct StateT * slot_2(struct StateT * v33) {
  int v34 = v33->timer;
  int v146 = v34 + 1;
  v33->timer = v146;
  int * v36 = v33->reg_ready;
  int v37 = v36[11];
  int * v38 = v33->regs;
  int v39 = v38[11];
  int * v40 = v33->cache_tags;
  int v151 = (((int)((unsigned int)((int)((unsigned int)v39 >> 2)) >> 1)) & 1) * 2;
  int v41 = v40[v151];
  int v152 = ((((int)((unsigned int)((int)((unsigned int)v39 >> 2)) >> 1)) & 1) * 2) + 1;
  int v42 = v40[v152];
  int v153 = 4 + ((((int)((unsigned int)((int)((unsigned int)v39 >> 2)) >> 1)) & 3) * 2);
  int v43 = v40[v153];
  int v154 = (4 + ((((int)((unsigned int)((int)((unsigned int)v39 >> 2)) >> 1)) & 3) * 2)) + 1;
  int v44 = v40[v154];
  int * v45 = v33->cache_vals;
  bool v155 = !(((~(((v41 ^ ((int)((unsigned int)((int)((unsigned int)v39 >> 2)) >> 1))) | (-(v41 ^ ((int)((unsigned int)((int)((unsigned int)v39 >> 2)) >> 1))))) >> 31)) | (~(((v42 ^ ((int)((unsigned int)((int)((unsigned int)v39 >> 2)) >> 1))) | (-(v42 ^ ((int)((unsigned int)((int)((unsigned int)v39 >> 2)) >> 1))))) >> 31))) == 0);
  int v138;
  if (v155) {
    int * v46 = v33->cache_age;
    int v157 = ((((int)((unsigned int)((int)((unsigned int)v39 >> 2)) >> 1)) & 1) * 2) + ((~(((v42 ^ ((int)((unsigned int)((int)((unsigned int)v39 >> 2)) >> 1))) | (-(v42 ^ ((int)((unsigned int)((int)((unsigned int)v39 >> 2)) >> 1))))) >> 31)) & 1);
    int v47 = v46[v157];
    int v48 = v46[v151];
    int v158 = v48 + ((int)((unsigned int)(v48 - v47) >> 31));
    v46[v151] = v158;
    int * v50 = v33->cache_age;
    int v51 = v50[v152];
    int v160 = v51 + ((int)((unsigned int)(v51 - v47) >> 31));
    v50[v152] = v160;
    int * v53 = v33->cache_age;
    v53[v157] = 0;
    v138 = v157;
  } else {
    int * v56 = v33->cache_age;
    int v164 = (((int)((unsigned int)((int)((unsigned int)v39 >> 2)) >> 1)) & 1) * 2;
    int v57 = v56[v164];
    int * v58 = v33->cache_tags;
    int v59 = v58[v164];
    int v60 = v56[v152];
    int v61 = v58[v152];
    bool v166 = !(((~(((v43 ^ ((int)((unsigned int)((int)((unsigned int)v39 >> 2)) >> 1))) | (-(v43 ^ ((int)((unsigned int)((int)((unsigned int)v39 >> 2)) >> 1))))) >> 31)) | (~(((v44 ^ ((int)((unsigned int)((int)((unsigned int)v39 >> 2)) >> 1))) | (-(v44 ^ ((int)((unsigned int)((int)((unsigned int)v39 >> 2)) >> 1))))) >> 31))) == 0);
    int v115;
    if (v166) {
      int * v62 = v33->cache_age;
      int v168 = (4 + ((((int)((unsigned int)((int)((unsigned int)v39 >> 2)) >> 1)) & 3) * 2)) + ((~(((v44 ^ ((int)((unsigned int)((int)((unsigned int)v39 >> 2)) >> 1))) | (-(v44 ^ ((int)((unsigned int)((int)((unsigned int)v39 >> 2)) >> 1))))) >> 31)) & 1);
      int v63 = v62[v168];
      int v64 = v62[v153];
      int v169 = v64 + ((int)((unsigned int)(v64 - v63) >> 31));
      v62[v153] = v169;
      int * v66 = v33->cache_age;
      int v67 = v66[v154];
      int v171 = v67 + ((int)((unsigned int)(v67 - v63) >> 31));
      v66[v154] = v171;
      int * v69 = v33->cache_age;
      v69[v168] = 0;
      v115 = v168;
    } else {
      int * v72 = v33->cache_age;
      int v175 = 4 + ((((int)((unsigned int)((int)((unsigned int)v39 >> 2)) >> 1)) & 3) * 2);
      int v73 = v72[v175];
      int * v74 = v33->cache_tags;
      int v75 = v74[v175];
      int v76 = v72[v154];
      int v77 = v74[v154];
      int * v78 = v33->cache_dirty;
      int v178 = (4 + ((((int)((unsigned int)((int)((unsigned int)v39 >> 2)) >> 1)) & 3) * 2)) + ((((v73 + ((~(((v75 ^ -1) | (-(v75 ^ -1))) >> 31)) & 2)) - (v76 + ((~(((v77 ^ -1) | (-(v77 ^ -1))) >> 31)) & 2))) >> 31) & 1);
      int v79 = v78[v178];
      bool v179 = !(v79 == 0);
      if (v179) {
        int * v80 = v33->cache_tags;
        int v81 = v80[v178];
        int * v82 = v33->cache_vals;
        int v182 = ((4 + ((((int)((unsigned int)((int)((unsigned int)v39 >> 2)) >> 1)) & 3) * 2)) + ((((v73 + ((~(((v75 ^ -1) | (-(v75 ^ -1))) >> 31)) & 2)) - (v76 + ((~(((v77 ^ -1) | (-(v77 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
        int v83 = v82[v182];
        int v183 = (((4 + ((((int)((unsigned int)((int)((unsigned int)v39 >> 2)) >> 1)) & 3) * 2)) + ((((v73 + ((~(((v75 ^ -1) | (-(v75 ^ -1))) >> 31)) & 2)) - (v76 + ((~(((v77 ^ -1) | (-(v77 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
        int v84 = v82[v183];
        int * v85 = v33->mem;
        int v185 = v81 * 2;
        v85[v185] = v83;
        int * v87 = v33->mem;
        int v188 = (v81 * 2) + 1;
        v87[v188] = v84;
        ;
      } else {
        ;
      }
      int * v92 = v33->mem;
      int v193 = ((int)((unsigned int)((int)((unsigned int)v39 >> 2)) >> 1)) * 2;
      int v93 = v92[v193];
      int v194 = (((int)((unsigned int)((int)((unsigned int)v39 >> 2)) >> 1)) * 2) + 1;
      int v94 = v92[v194];
      int * v95 = v33->cache_vals;
      int v196 = ((4 + ((((int)((unsigned int)((int)((unsigned int)v39 >> 2)) >> 1)) & 3) * 2)) + ((((v73 + ((~(((v75 ^ -1) | (-(v75 ^ -1))) >> 31)) & 2)) - (v76 + ((~(((v77 ^ -1) | (-(v77 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
      v95[v196] = v93;
      int * v97 = v33->cache_vals;
      int v199 = (((4 + ((((int)((unsigned int)((int)((unsigned int)v39 >> 2)) >> 1)) & 3) * 2)) + ((((v73 + ((~(((v75 ^ -1) | (-(v75 ^ -1))) >> 31)) & 2)) - (v76 + ((~(((v77 ^ -1) | (-(v77 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
      v97[v199] = v94;
      int * v99 = v33->cache_tags;
      int v202 = (int)((unsigned int)((int)((unsigned int)v39 >> 2)) >> 1);
      v99[v178] = v202;
      int * v101 = v33->cache_dirty;
      v101[v178] = 0;
      int * v103 = v33->cache_age;
      v103[v178] = 1;
      int * v105 = v33->cache_age;
      int v106 = v105[v178];
      int v107 = v105[v153];
      int v208 = v107 + ((int)((unsigned int)(v107 - v106) >> 31));
      v105[v153] = v208;
      int * v109 = v33->cache_age;
      int v110 = v109[v154];
      int v210 = v110 + ((int)((unsigned int)(v110 - v106) >> 31));
      v109[v154] = v210;
      int * v112 = v33->cache_age;
      v112[v178] = 0;
      v115 = v178;
    }
    int * v116 = v33->cache_vals;
    int v213 = v115 * 2;
    int v117 = v116[v213];
    int v214 = (v115 * 2) + 1;
    int v118 = v116[v214];
    int v215 = (((((int)((unsigned int)((int)((unsigned int)v39 >> 2)) >> 1)) & 1) * 2) + ((((v57 + ((~(((v59 ^ -1) | (-(v59 ^ -1))) >> 31)) & 2)) - (v60 + ((~(((v61 ^ -1) | (-(v61 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
    v116[v215] = v117;
    int * v120 = v33->cache_vals;
    int v218 = ((((((int)((unsigned int)((int)((unsigned int)v39 >> 2)) >> 1)) & 1) * 2) + ((((v57 + ((~(((v59 ^ -1) | (-(v59 ^ -1))) >> 31)) & 2)) - (v60 + ((~(((v61 ^ -1) | (-(v61 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
    v120[v218] = v118;
    int * v122 = v33->cache_tags;
    int v221 = ((((int)((unsigned int)((int)((unsigned int)v39 >> 2)) >> 1)) & 1) * 2) + ((((v57 + ((~(((v59 ^ -1) | (-(v59 ^ -1))) >> 31)) & 2)) - (v60 + ((~(((v61 ^ -1) | (-(v61 ^ -1))) >> 31)) & 2))) >> 31) & 1);
    int v222 = (int)((unsigned int)((int)((unsigned int)v39 >> 2)) >> 1);
    v122[v221] = v222;
    int * v124 = v33->cache_dirty;
    v124[v221] = 0;
    int * v126 = v33->cache_age;
    v126[v221] = 1;
    int * v128 = v33->cache_age;
    int v129 = v128[v221];
    int v130 = v128[v151];
    int v228 = v130 + ((int)((unsigned int)(v130 - v129) >> 31));
    v128[v151] = v228;
    int * v132 = v33->cache_age;
    int v133 = v132[v152];
    int v230 = v133 + ((int)((unsigned int)(v133 - v129) >> 31));
    v132[v152] = v230;
    int * v135 = v33->cache_age;
    v135[v221] = 0;
    v138 = v221;
  }
  int v233 = (v138 * 2) + (((int)((unsigned int)v39 >> 2)) & 1);
  int v139 = v45[v233];
  int * v140 = v33->reg_ready;
  int v235 = ((v37 + ((v34 - v37) & (~((v34 - v37) >> 31)))) + 1) + ((100 ^ (((~(((v43 ^ ((int)((unsigned int)((int)((unsigned int)v39 >> 2)) >> 1))) | (-(v43 ^ ((int)((unsigned int)((int)((unsigned int)v39 >> 2)) >> 1))))) >> 31)) | (~(((v44 ^ ((int)((unsigned int)((int)((unsigned int)v39 >> 2)) >> 1))) | (-(v44 ^ ((int)((unsigned int)((int)((unsigned int)v39 >> 2)) >> 1))))) >> 31))) & 104)) ^ (((~(((v41 ^ ((int)((unsigned int)((int)((unsigned int)v39 >> 2)) >> 1))) | (-(v41 ^ ((int)((unsigned int)((int)((unsigned int)v39 >> 2)) >> 1))))) >> 31)) | (~(((v42 ^ ((int)((unsigned int)((int)((unsigned int)v39 >> 2)) >> 1))) | (-(v42 ^ ((int)((unsigned int)((int)((unsigned int)v39 >> 2)) >> 1))))) >> 31))) & (1 ^ (100 ^ (((~(((v43 ^ ((int)((unsigned int)((int)((unsigned int)v39 >> 2)) >> 1))) | (-(v43 ^ ((int)((unsigned int)((int)((unsigned int)v39 >> 2)) >> 1))))) >> 31)) | (~(((v44 ^ ((int)((unsigned int)((int)((unsigned int)v39 >> 2)) >> 1))) | (-(v44 ^ ((int)((unsigned int)((int)((unsigned int)v39 >> 2)) >> 1))))) >> 31))) & 104)))));
  v140[11] = v235;
  int * v142 = v33->regs;
  v142[11] = v139;
  struct StateT * v144 = slot_3(v33);
  return v144;
}

struct StateT * slot_7(struct StateT * v318) {
  int * v319 = v318->saved_regs;
  int * v320 = v318->regs;
  int v321 = v320[10];
  v319[10] = v321;
  int v323 = v318->timer;
  int v338 = v323 + 1;
  v318->timer = v338;
  int * v325 = v318->reg_ready;
  int v326 = v325[10];
  int * v327 = v318->regs;
  int v328 = v327[10];
  int v341 = (v326 + ((v323 - v326) & (~((v323 - v326) >> 31)))) + 1;
  v325[10] = v341;
  int * v330 = v318->regs;
  int v343 = v328 << 2;
  v330[10] = v343;
  struct StateT * v332 = slot_9(v318);
  return v332;
}

struct StateT * slot_21(struct StateT * v775) {
  int v776 = v775->timer;
  int v789 = v776 + 1;
  v775->timer = v789;
  int * v778 = v775->reg_ready;
  int v779 = v778[11];
  int * v780 = v775->regs;
  int v781 = v780[11];
  int v782 = v778[10];
  int v783 = v780[10];
  int v794 = (v782 + (((v779 + ((v776 - v779) & (~((v776 - v779) >> 31)))) - v782) & (~(((v779 + ((v776 - v779) & (~((v776 - v779) >> 31)))) - v782) >> 31)))) + 1;
  v778[10] = v794;
  int * v785 = v775->regs;
  int v796 = v781 + v783;
  v785[10] = v796;
  struct StateT * v787 = slot_22(v775);
  return v787;
}

struct StateT * slot_3(struct StateT * v240) {
  int * v241 = v240->regs;
  int v242 = v241[10];
  bool v260 = v242 == 0;
  struct StateT * v256;
  if (v260) {
    int v243 = v240->timer;
    int v261 = v243 + 15;
    v240->timer = v261;
    int * v245 = v240->saved_regs;
    int v246 = v245[11];
    int * v247 = v240->regs;
    v247[11] = v246;
    int * v249 = v240->reg_ready;
    int v250 = v240->timer;
    v249[11] = v250;
    struct StateT * v252 = slot_4(v240);
    v256 = v252;
  } else {
    struct StateT * v254 = slot_5(v240);
    v256 = v254;
  }
  return v256;
}

struct StateT * slot_10(struct StateT * v576) {
  int v577 = v576->timer;
  int v585 = v577 + 1;
  v576->timer = v585;
  int * v579 = v576->reg_ready;
  v579[11] = v585;
  int * v581 = v576->regs;
  v581[11] = 0;
  struct StateT * v583 = slot_12(v576);
  return v583;
}

struct StateT * slot_1(struct StateT * v10) {
  int * v11 = v10->saved_regs;
  int * v12 = v10->regs;
  int v13 = v12[11];
  v11[11] = v13;
  int v15 = v10->timer;
  int v27 = v15 + 1;
  v10->timer = v27;
  int * v17 = v10->reg_ready;
  v17[11] = v27;
  int * v19 = v10->regs;
  v19[11] = 0;
  struct StateT * v21 = slot_2(v10);
  return v21;
}

struct StateT * slot_19(struct StateT * v754) {
  int v755 = v754->timer;
  int v766 = v755 + 1;
  v754->timer = v766;
  int * v757 = v754->reg_ready;
  int v758 = v757[10];
  int * v759 = v754->regs;
  int v760 = v759[10];
  int v770 = (v758 + ((v755 - v758) & (~((v755 - v758) >> 31)))) + 1;
  v757[10] = v770;
  int * v762 = v754->regs;
  int v772 = (int)((unsigned int)v760 >> 26);
  v762[10] = v772;
  struct StateT * v764 = slot_21(v754);
  return v764;
}

struct StateT * slot_13(struct StateT * v634) {
  int v635 = v634->timer;
  int v648 = v635 + 1;
  v634->timer = v648;
  int * v637 = v634->reg_ready;
  int v638 = v637[11];
  int * v639 = v634->regs;
  int v640 = v639[11];
  int v641 = v637[10];
  int v642 = v639[10];
  int v653 = (v641 + (((v638 + ((v635 - v638) & (~((v635 - v638) >> 31)))) - v641) & (~(((v638 + ((v635 - v638) & (~((v635 - v638) >> 31)))) - v641) >> 31)))) + 1;
  v637[10] = v653;
  int * v644 = v634->regs;
  int v655 = v640 + v642;
  v644[10] = v655;
  struct StateT * v646 = slot_15(v634);
  return v646;
}

struct StateT * slot_24(struct StateT * v1214) {
  int v1215 = v1214->timer;
  int v1228 = v1215 + 1;
  v1214->timer = v1228;
  int * v1217 = v1214->reg_ready;
  int v1218 = v1217[11];
  int * v1219 = v1214->regs;
  int v1220 = v1219[11];
  int v1221 = v1217[10];
  int v1222 = v1219[10];
  int v1233 = (v1221 + (((v1218 + ((v1215 - v1218) & (~((v1215 - v1218) >> 31)))) - v1221) & (~(((v1218 + ((v1215 - v1218) & (~((v1215 - v1218) >> 31)))) - v1221) >> 31)))) + 1;
  v1217[10] = v1233;
  int * v1224 = v1214->regs;
  int v1235 = v1220 & v1222;
  v1224[10] = v1235;
  struct StateT * v1226 = slot_25(v1214);
  return v1226;
}

struct StateT * slot_0(struct StateT * v2) {
  int v3 = v2->timer;
  int v7 = v3 + 1;
  v2->timer = v7;
  struct StateT * v5 = slot_1(v2);
  return v5;
}

struct StateT * slot_14(struct StateT * v658) {
  int v659 = v658->timer;
  int v667 = v659 + 1;
  v658->timer = v667;
  int * v661 = v658->reg_ready;
  v661[12] = v667;
  int * v663 = v658->regs;
  v663[12] = 0;
  struct StateT * v665 = slot_16(v658);
  return v665;
}

struct StateT * slot_17(struct StateT * v741) {
  int v742 = v741->timer;
  int v745 = v742 + 1;
  v741->timer = v745;
  return v741;
}

struct StateT * snippet(struct StateT * v0) {
  struct StateT * v1 = slot_0(v0);
  int v1557 = v1->timer;
  int * v1558 = v1->reg_ready;
  int v1559 = v1558[0];
  int v1690 = v1559 + ((v1557 - v1559) & (~((v1557 - v1559) >> 31)));
  v1->timer = v1690;
  int v1561 = v1->timer;
  int * v1562 = v1->reg_ready;
  int v1563 = v1562[1];
  int v1693 = v1563 + ((v1561 - v1563) & (~((v1561 - v1563) >> 31)));
  v1->timer = v1693;
  int v1565 = v1->timer;
  int * v1566 = v1->reg_ready;
  int v1567 = v1566[2];
  int v1696 = v1567 + ((v1565 - v1567) & (~((v1565 - v1567) >> 31)));
  v1->timer = v1696;
  int v1569 = v1->timer;
  int * v1570 = v1->reg_ready;
  int v1571 = v1570[3];
  int v1699 = v1571 + ((v1569 - v1571) & (~((v1569 - v1571) >> 31)));
  v1->timer = v1699;
  int v1573 = v1->timer;
  int * v1574 = v1->reg_ready;
  int v1575 = v1574[4];
  int v1702 = v1575 + ((v1573 - v1575) & (~((v1573 - v1575) >> 31)));
  v1->timer = v1702;
  int v1577 = v1->timer;
  int * v1578 = v1->reg_ready;
  int v1579 = v1578[5];
  int v1705 = v1579 + ((v1577 - v1579) & (~((v1577 - v1579) >> 31)));
  v1->timer = v1705;
  int v1581 = v1->timer;
  int * v1582 = v1->reg_ready;
  int v1583 = v1582[6];
  int v1708 = v1583 + ((v1581 - v1583) & (~((v1581 - v1583) >> 31)));
  v1->timer = v1708;
  int v1585 = v1->timer;
  int * v1586 = v1->reg_ready;
  int v1587 = v1586[7];
  int v1711 = v1587 + ((v1585 - v1587) & (~((v1585 - v1587) >> 31)));
  v1->timer = v1711;
  int v1589 = v1->timer;
  int * v1590 = v1->reg_ready;
  int v1591 = v1590[8];
  int v1714 = v1591 + ((v1589 - v1591) & (~((v1589 - v1591) >> 31)));
  v1->timer = v1714;
  int v1593 = v1->timer;
  int * v1594 = v1->reg_ready;
  int v1595 = v1594[9];
  int v1717 = v1595 + ((v1593 - v1595) & (~((v1593 - v1595) >> 31)));
  v1->timer = v1717;
  int v1597 = v1->timer;
  int * v1598 = v1->reg_ready;
  int v1599 = v1598[10];
  int v1720 = v1599 + ((v1597 - v1599) & (~((v1597 - v1599) >> 31)));
  v1->timer = v1720;
  int v1601 = v1->timer;
  int * v1602 = v1->reg_ready;
  int v1603 = v1602[11];
  int v1723 = v1603 + ((v1601 - v1603) & (~((v1601 - v1603) >> 31)));
  v1->timer = v1723;
  int v1605 = v1->timer;
  int * v1606 = v1->reg_ready;
  int v1607 = v1606[12];
  int v1726 = v1607 + ((v1605 - v1607) & (~((v1605 - v1607) >> 31)));
  v1->timer = v1726;
  int v1609 = v1->timer;
  int * v1610 = v1->reg_ready;
  int v1611 = v1610[13];
  int v1729 = v1611 + ((v1609 - v1611) & (~((v1609 - v1611) >> 31)));
  v1->timer = v1729;
  int v1613 = v1->timer;
  int * v1614 = v1->reg_ready;
  int v1615 = v1614[14];
  int v1732 = v1615 + ((v1613 - v1615) & (~((v1613 - v1615) >> 31)));
  v1->timer = v1732;
  int v1617 = v1->timer;
  int * v1618 = v1->reg_ready;
  int v1619 = v1618[15];
  int v1735 = v1619 + ((v1617 - v1619) & (~((v1617 - v1619) >> 31)));
  v1->timer = v1735;
  int v1621 = v1->timer;
  int * v1622 = v1->reg_ready;
  int v1623 = v1622[16];
  int v1738 = v1623 + ((v1621 - v1623) & (~((v1621 - v1623) >> 31)));
  v1->timer = v1738;
  int v1625 = v1->timer;
  int * v1626 = v1->reg_ready;
  int v1627 = v1626[17];
  int v1741 = v1627 + ((v1625 - v1627) & (~((v1625 - v1627) >> 31)));
  v1->timer = v1741;
  int v1629 = v1->timer;
  int * v1630 = v1->reg_ready;
  int v1631 = v1630[18];
  int v1744 = v1631 + ((v1629 - v1631) & (~((v1629 - v1631) >> 31)));
  v1->timer = v1744;
  int v1633 = v1->timer;
  int * v1634 = v1->reg_ready;
  int v1635 = v1634[19];
  int v1747 = v1635 + ((v1633 - v1635) & (~((v1633 - v1635) >> 31)));
  v1->timer = v1747;
  int v1637 = v1->timer;
  int * v1638 = v1->reg_ready;
  int v1639 = v1638[20];
  int v1750 = v1639 + ((v1637 - v1639) & (~((v1637 - v1639) >> 31)));
  v1->timer = v1750;
  int v1641 = v1->timer;
  int * v1642 = v1->reg_ready;
  int v1643 = v1642[21];
  int v1753 = v1643 + ((v1641 - v1643) & (~((v1641 - v1643) >> 31)));
  v1->timer = v1753;
  int v1645 = v1->timer;
  int * v1646 = v1->reg_ready;
  int v1647 = v1646[22];
  int v1756 = v1647 + ((v1645 - v1647) & (~((v1645 - v1647) >> 31)));
  v1->timer = v1756;
  int v1649 = v1->timer;
  int * v1650 = v1->reg_ready;
  int v1651 = v1650[23];
  int v1759 = v1651 + ((v1649 - v1651) & (~((v1649 - v1651) >> 31)));
  v1->timer = v1759;
  int v1653 = v1->timer;
  int * v1654 = v1->reg_ready;
  int v1655 = v1654[24];
  int v1762 = v1655 + ((v1653 - v1655) & (~((v1653 - v1655) >> 31)));
  v1->timer = v1762;
  int v1657 = v1->timer;
  int * v1658 = v1->reg_ready;
  int v1659 = v1658[25];
  int v1765 = v1659 + ((v1657 - v1659) & (~((v1657 - v1659) >> 31)));
  v1->timer = v1765;
  int v1661 = v1->timer;
  int * v1662 = v1->reg_ready;
  int v1663 = v1662[26];
  int v1768 = v1663 + ((v1661 - v1663) & (~((v1661 - v1663) >> 31)));
  v1->timer = v1768;
  int v1665 = v1->timer;
  int * v1666 = v1->reg_ready;
  int v1667 = v1666[27];
  int v1771 = v1667 + ((v1665 - v1667) & (~((v1665 - v1667) >> 31)));
  v1->timer = v1771;
  int v1669 = v1->timer;
  int * v1670 = v1->reg_ready;
  int v1671 = v1670[28];
  int v1774 = v1671 + ((v1669 - v1671) & (~((v1669 - v1671) >> 31)));
  v1->timer = v1774;
  int v1673 = v1->timer;
  int * v1674 = v1->reg_ready;
  int v1675 = v1674[29];
  int v1777 = v1675 + ((v1673 - v1675) & (~((v1673 - v1675) >> 31)));
  v1->timer = v1777;
  int v1677 = v1->timer;
  int * v1678 = v1->reg_ready;
  int v1679 = v1678[30];
  int v1780 = v1679 + ((v1677 - v1679) & (~((v1677 - v1679) >> 31)));
  v1->timer = v1780;
  int v1681 = v1->timer;
  int * v1682 = v1->reg_ready;
  int v1683 = v1682[31];
  int v1783 = v1683 + ((v1681 - v1683) & (~((v1681 - v1683) >> 31)));
  v1->timer = v1783;
  return v1;
}

struct StateT * slot_8(struct StateT * v346) {
  int v347 = v346->timer;
  int v459 = v347 + 1;
  v346->timer = v459;
  int * v349 = v346->reg_ready;
  int v350 = v349[10];
  int * v351 = v346->regs;
  int v352 = v351[10];
  int * v353 = v346->cache_tags;
  int v464 = (((int)((unsigned int)((int)((unsigned int)v352 >> 2)) >> 1)) & 1) * 2;
  int v354 = v353[v464];
  int v465 = ((((int)((unsigned int)((int)((unsigned int)v352 >> 2)) >> 1)) & 1) * 2) + 1;
  int v355 = v353[v465];
  int v466 = 4 + ((((int)((unsigned int)((int)((unsigned int)v352 >> 2)) >> 1)) & 3) * 2);
  int v356 = v353[v466];
  int v467 = (4 + ((((int)((unsigned int)((int)((unsigned int)v352 >> 2)) >> 1)) & 3) * 2)) + 1;
  int v357 = v353[v467];
  int * v358 = v346->cache_vals;
  bool v468 = !(((~(((v354 ^ ((int)((unsigned int)((int)((unsigned int)v352 >> 2)) >> 1))) | (-(v354 ^ ((int)((unsigned int)((int)((unsigned int)v352 >> 2)) >> 1))))) >> 31)) | (~(((v355 ^ ((int)((unsigned int)((int)((unsigned int)v352 >> 2)) >> 1))) | (-(v355 ^ ((int)((unsigned int)((int)((unsigned int)v352 >> 2)) >> 1))))) >> 31))) == 0);
  int v451;
  if (v468) {
    int * v359 = v346->cache_age;
    int v470 = ((((int)((unsigned int)((int)((unsigned int)v352 >> 2)) >> 1)) & 1) * 2) + ((~(((v355 ^ ((int)((unsigned int)((int)((unsigned int)v352 >> 2)) >> 1))) | (-(v355 ^ ((int)((unsigned int)((int)((unsigned int)v352 >> 2)) >> 1))))) >> 31)) & 1);
    int v360 = v359[v470];
    int v361 = v359[v464];
    int v471 = v361 + ((int)((unsigned int)(v361 - v360) >> 31));
    v359[v464] = v471;
    int * v363 = v346->cache_age;
    int v364 = v363[v465];
    int v473 = v364 + ((int)((unsigned int)(v364 - v360) >> 31));
    v363[v465] = v473;
    int * v366 = v346->cache_age;
    v366[v470] = 0;
    v451 = v470;
  } else {
    int * v369 = v346->cache_age;
    int v477 = (((int)((unsigned int)((int)((unsigned int)v352 >> 2)) >> 1)) & 1) * 2;
    int v370 = v369[v477];
    int * v371 = v346->cache_tags;
    int v372 = v371[v477];
    int v373 = v369[v465];
    int v374 = v371[v465];
    bool v479 = !(((~(((v356 ^ ((int)((unsigned int)((int)((unsigned int)v352 >> 2)) >> 1))) | (-(v356 ^ ((int)((unsigned int)((int)((unsigned int)v352 >> 2)) >> 1))))) >> 31)) | (~(((v357 ^ ((int)((unsigned int)((int)((unsigned int)v352 >> 2)) >> 1))) | (-(v357 ^ ((int)((unsigned int)((int)((unsigned int)v352 >> 2)) >> 1))))) >> 31))) == 0);
    int v428;
    if (v479) {
      int * v375 = v346->cache_age;
      int v481 = (4 + ((((int)((unsigned int)((int)((unsigned int)v352 >> 2)) >> 1)) & 3) * 2)) + ((~(((v357 ^ ((int)((unsigned int)((int)((unsigned int)v352 >> 2)) >> 1))) | (-(v357 ^ ((int)((unsigned int)((int)((unsigned int)v352 >> 2)) >> 1))))) >> 31)) & 1);
      int v376 = v375[v481];
      int v377 = v375[v466];
      int v482 = v377 + ((int)((unsigned int)(v377 - v376) >> 31));
      v375[v466] = v482;
      int * v379 = v346->cache_age;
      int v380 = v379[v467];
      int v484 = v380 + ((int)((unsigned int)(v380 - v376) >> 31));
      v379[v467] = v484;
      int * v382 = v346->cache_age;
      v382[v481] = 0;
      v428 = v481;
    } else {
      int * v385 = v346->cache_age;
      int v488 = 4 + ((((int)((unsigned int)((int)((unsigned int)v352 >> 2)) >> 1)) & 3) * 2);
      int v386 = v385[v488];
      int * v387 = v346->cache_tags;
      int v388 = v387[v488];
      int v389 = v385[v467];
      int v390 = v387[v467];
      int * v391 = v346->cache_dirty;
      int v491 = (4 + ((((int)((unsigned int)((int)((unsigned int)v352 >> 2)) >> 1)) & 3) * 2)) + ((((v386 + ((~(((v388 ^ -1) | (-(v388 ^ -1))) >> 31)) & 2)) - (v389 + ((~(((v390 ^ -1) | (-(v390 ^ -1))) >> 31)) & 2))) >> 31) & 1);
      int v392 = v391[v491];
      bool v492 = !(v392 == 0);
      if (v492) {
        int * v393 = v346->cache_tags;
        int v394 = v393[v491];
        int * v395 = v346->cache_vals;
        int v495 = ((4 + ((((int)((unsigned int)((int)((unsigned int)v352 >> 2)) >> 1)) & 3) * 2)) + ((((v386 + ((~(((v388 ^ -1) | (-(v388 ^ -1))) >> 31)) & 2)) - (v389 + ((~(((v390 ^ -1) | (-(v390 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
        int v396 = v395[v495];
        int v496 = (((4 + ((((int)((unsigned int)((int)((unsigned int)v352 >> 2)) >> 1)) & 3) * 2)) + ((((v386 + ((~(((v388 ^ -1) | (-(v388 ^ -1))) >> 31)) & 2)) - (v389 + ((~(((v390 ^ -1) | (-(v390 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
        int v397 = v395[v496];
        int * v398 = v346->mem;
        int v498 = v394 * 2;
        v398[v498] = v396;
        int * v400 = v346->mem;
        int v501 = (v394 * 2) + 1;
        v400[v501] = v397;
        ;
      } else {
        ;
      }
      int * v405 = v346->mem;
      int v506 = ((int)((unsigned int)((int)((unsigned int)v352 >> 2)) >> 1)) * 2;
      int v406 = v405[v506];
      int v507 = (((int)((unsigned int)((int)((unsigned int)v352 >> 2)) >> 1)) * 2) + 1;
      int v407 = v405[v507];
      int * v408 = v346->cache_vals;
      int v509 = ((4 + ((((int)((unsigned int)((int)((unsigned int)v352 >> 2)) >> 1)) & 3) * 2)) + ((((v386 + ((~(((v388 ^ -1) | (-(v388 ^ -1))) >> 31)) & 2)) - (v389 + ((~(((v390 ^ -1) | (-(v390 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
      v408[v509] = v406;
      int * v410 = v346->cache_vals;
      int v512 = (((4 + ((((int)((unsigned int)((int)((unsigned int)v352 >> 2)) >> 1)) & 3) * 2)) + ((((v386 + ((~(((v388 ^ -1) | (-(v388 ^ -1))) >> 31)) & 2)) - (v389 + ((~(((v390 ^ -1) | (-(v390 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
      v410[v512] = v407;
      int * v412 = v346->cache_tags;
      int v515 = (int)((unsigned int)((int)((unsigned int)v352 >> 2)) >> 1);
      v412[v491] = v515;
      int * v414 = v346->cache_dirty;
      v414[v491] = 0;
      int * v416 = v346->cache_age;
      v416[v491] = 1;
      int * v418 = v346->cache_age;
      int v419 = v418[v491];
      int v420 = v418[v466];
      int v521 = v420 + ((int)((unsigned int)(v420 - v419) >> 31));
      v418[v466] = v521;
      int * v422 = v346->cache_age;
      int v423 = v422[v467];
      int v523 = v423 + ((int)((unsigned int)(v423 - v419) >> 31));
      v422[v467] = v523;
      int * v425 = v346->cache_age;
      v425[v491] = 0;
      v428 = v491;
    }
    int * v429 = v346->cache_vals;
    int v526 = v428 * 2;
    int v430 = v429[v526];
    int v527 = (v428 * 2) + 1;
    int v431 = v429[v527];
    int v528 = (((((int)((unsigned int)((int)((unsigned int)v352 >> 2)) >> 1)) & 1) * 2) + ((((v370 + ((~(((v372 ^ -1) | (-(v372 ^ -1))) >> 31)) & 2)) - (v373 + ((~(((v374 ^ -1) | (-(v374 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
    v429[v528] = v430;
    int * v433 = v346->cache_vals;
    int v531 = ((((((int)((unsigned int)((int)((unsigned int)v352 >> 2)) >> 1)) & 1) * 2) + ((((v370 + ((~(((v372 ^ -1) | (-(v372 ^ -1))) >> 31)) & 2)) - (v373 + ((~(((v374 ^ -1) | (-(v374 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
    v433[v531] = v431;
    int * v435 = v346->cache_tags;
    int v534 = ((((int)((unsigned int)((int)((unsigned int)v352 >> 2)) >> 1)) & 1) * 2) + ((((v370 + ((~(((v372 ^ -1) | (-(v372 ^ -1))) >> 31)) & 2)) - (v373 + ((~(((v374 ^ -1) | (-(v374 ^ -1))) >> 31)) & 2))) >> 31) & 1);
    int v535 = (int)((unsigned int)((int)((unsigned int)v352 >> 2)) >> 1);
    v435[v534] = v535;
    int * v437 = v346->cache_dirty;
    v437[v534] = 0;
    int * v439 = v346->cache_age;
    v439[v534] = 1;
    int * v441 = v346->cache_age;
    int v442 = v441[v534];
    int v443 = v441[v464];
    int v541 = v443 + ((int)((unsigned int)(v443 - v442) >> 31));
    v441[v464] = v541;
    int * v445 = v346->cache_age;
    int v446 = v445[v465];
    int v543 = v446 + ((int)((unsigned int)(v446 - v442) >> 31));
    v445[v465] = v543;
    int * v448 = v346->cache_age;
    v448[v534] = 0;
    v451 = v534;
  }
  int v546 = (v451 * 2) + (((int)((unsigned int)v352 >> 2)) & 1);
  int v452 = v358[v546];
  int * v453 = v346->reg_ready;
  int v548 = ((v350 + ((v347 - v350) & (~((v347 - v350) >> 31)))) + 1) + ((100 ^ (((~(((v356 ^ ((int)((unsigned int)((int)((unsigned int)v352 >> 2)) >> 1))) | (-(v356 ^ ((int)((unsigned int)((int)((unsigned int)v352 >> 2)) >> 1))))) >> 31)) | (~(((v357 ^ ((int)((unsigned int)((int)((unsigned int)v352 >> 2)) >> 1))) | (-(v357 ^ ((int)((unsigned int)((int)((unsigned int)v352 >> 2)) >> 1))))) >> 31))) & 104)) ^ (((~(((v354 ^ ((int)((unsigned int)((int)((unsigned int)v352 >> 2)) >> 1))) | (-(v354 ^ ((int)((unsigned int)((int)((unsigned int)v352 >> 2)) >> 1))))) >> 31)) | (~(((v355 ^ ((int)((unsigned int)((int)((unsigned int)v352 >> 2)) >> 1))) | (-(v355 ^ ((int)((unsigned int)((int)((unsigned int)v352 >> 2)) >> 1))))) >> 31))) & (1 ^ (100 ^ (((~(((v356 ^ ((int)((unsigned int)((int)((unsigned int)v352 >> 2)) >> 1))) | (-(v356 ^ ((int)((unsigned int)((int)((unsigned int)v352 >> 2)) >> 1))))) >> 31)) | (~(((v357 ^ ((int)((unsigned int)((int)((unsigned int)v352 >> 2)) >> 1))) | (-(v357 ^ ((int)((unsigned int)((int)((unsigned int)v352 >> 2)) >> 1))))) >> 31))) & 104)))));
  v453[10] = v548;
  int * v455 = v346->regs;
  v455[10] = v452;
  struct StateT * v457 = slot_10(v346);
  return v457;
}

struct StateT * slot_4(struct StateT * v273) {
  int v274 = v273->timer;
  int v282 = v274 + 1;
  v273->timer = v282;
  int * v276 = v273->reg_ready;
  v276[10] = v282;
  int * v278 = v273->regs;
  v278[10] = 0;
  struct StateT * v280 = slot_6(v273);
  return v280;
}

struct StateT * slot_15(struct StateT * v674) {
  int * v675 = v674->saved_regs;
  int v676 = v675[10];
  int v677 = v675[11];
  bool v703 = (v676 ^ -2147483648) >= (v677 ^ -2147483648);
  struct StateT * v698;
  if (v703) {
    int v678 = v674->timer;
    int v704 = v678 + 15;
    v674->timer = v704;
    int * v680 = v674->saved_regs;
    int v681 = v680[10];
    int * v682 = v674->regs;
    v682[10] = v681;
    int * v684 = v674->saved_regs;
    int v685 = v684[11];
    int * v686 = v674->regs;
    v686[11] = v685;
    int * v688 = v674->reg_ready;
    int v689 = v674->timer;
    v688[10] = v689;
    int * v691 = v674->reg_ready;
    int v692 = v674->timer;
    v691[11] = v692;
    struct StateT * v694 = slot_17(v674);
    v698 = v694;
  } else {
    struct StateT * v696 = slot_18(v674);
    v698 = v696;
  }
  return v698;
}

struct StateT * slot_18(struct StateT * v746) {
  int v747 = v746->timer;
  int v751 = v747 + 1;
  v746->timer = v751;
  struct StateT * v749 = slot_8(v746);
  return v749;
}

struct StateT * slot_9(struct StateT * v553) {
  int * v554 = v553->saved_regs;
  int * v555 = v553->regs;
  int v556 = v555[11];
  v554[11] = v556;
  int v558 = v553->timer;
  int v570 = v558 + 1;
  v553->timer = v570;
  int * v560 = v553->reg_ready;
  v560[11] = v570;
  int * v562 = v553->regs;
  v562[11] = 0;
  struct StateT * v564 = slot_11(v553);
  return v564;
}

struct StateT * slot_22(struct StateT * v799) {
  int v800 = v799->timer;
  int v912 = v800 + 1;
  v799->timer = v912;
  int * v802 = v799->reg_ready;
  int v803 = v802[10];
  int * v804 = v799->regs;
  int v805 = v804[10];
  int * v806 = v799->cache_tags;
  int v917 = (((int)((unsigned int)((int)((unsigned int)v805 >> 2)) >> 1)) & 1) * 2;
  int v807 = v806[v917];
  int v918 = ((((int)((unsigned int)((int)((unsigned int)v805 >> 2)) >> 1)) & 1) * 2) + 1;
  int v808 = v806[v918];
  int v919 = 4 + ((((int)((unsigned int)((int)((unsigned int)v805 >> 2)) >> 1)) & 3) * 2);
  int v809 = v806[v919];
  int v920 = (4 + ((((int)((unsigned int)((int)((unsigned int)v805 >> 2)) >> 1)) & 3) * 2)) + 1;
  int v810 = v806[v920];
  int * v811 = v799->cache_vals;
  bool v921 = !(((~(((v807 ^ ((int)((unsigned int)((int)((unsigned int)v805 >> 2)) >> 1))) | (-(v807 ^ ((int)((unsigned int)((int)((unsigned int)v805 >> 2)) >> 1))))) >> 31)) | (~(((v808 ^ ((int)((unsigned int)((int)((unsigned int)v805 >> 2)) >> 1))) | (-(v808 ^ ((int)((unsigned int)((int)((unsigned int)v805 >> 2)) >> 1))))) >> 31))) == 0);
  int v904;
  if (v921) {
    int * v812 = v799->cache_age;
    int v923 = ((((int)((unsigned int)((int)((unsigned int)v805 >> 2)) >> 1)) & 1) * 2) + ((~(((v808 ^ ((int)((unsigned int)((int)((unsigned int)v805 >> 2)) >> 1))) | (-(v808 ^ ((int)((unsigned int)((int)((unsigned int)v805 >> 2)) >> 1))))) >> 31)) & 1);
    int v813 = v812[v923];
    int v814 = v812[v917];
    int v924 = v814 + ((int)((unsigned int)(v814 - v813) >> 31));
    v812[v917] = v924;
    int * v816 = v799->cache_age;
    int v817 = v816[v918];
    int v926 = v817 + ((int)((unsigned int)(v817 - v813) >> 31));
    v816[v918] = v926;
    int * v819 = v799->cache_age;
    v819[v923] = 0;
    v904 = v923;
  } else {
    int * v822 = v799->cache_age;
    int v930 = (((int)((unsigned int)((int)((unsigned int)v805 >> 2)) >> 1)) & 1) * 2;
    int v823 = v822[v930];
    int * v824 = v799->cache_tags;
    int v825 = v824[v930];
    int v826 = v822[v918];
    int v827 = v824[v918];
    bool v932 = !(((~(((v809 ^ ((int)((unsigned int)((int)((unsigned int)v805 >> 2)) >> 1))) | (-(v809 ^ ((int)((unsigned int)((int)((unsigned int)v805 >> 2)) >> 1))))) >> 31)) | (~(((v810 ^ ((int)((unsigned int)((int)((unsigned int)v805 >> 2)) >> 1))) | (-(v810 ^ ((int)((unsigned int)((int)((unsigned int)v805 >> 2)) >> 1))))) >> 31))) == 0);
    int v881;
    if (v932) {
      int * v828 = v799->cache_age;
      int v934 = (4 + ((((int)((unsigned int)((int)((unsigned int)v805 >> 2)) >> 1)) & 3) * 2)) + ((~(((v810 ^ ((int)((unsigned int)((int)((unsigned int)v805 >> 2)) >> 1))) | (-(v810 ^ ((int)((unsigned int)((int)((unsigned int)v805 >> 2)) >> 1))))) >> 31)) & 1);
      int v829 = v828[v934];
      int v830 = v828[v919];
      int v935 = v830 + ((int)((unsigned int)(v830 - v829) >> 31));
      v828[v919] = v935;
      int * v832 = v799->cache_age;
      int v833 = v832[v920];
      int v937 = v833 + ((int)((unsigned int)(v833 - v829) >> 31));
      v832[v920] = v937;
      int * v835 = v799->cache_age;
      v835[v934] = 0;
      v881 = v934;
    } else {
      int * v838 = v799->cache_age;
      int v941 = 4 + ((((int)((unsigned int)((int)((unsigned int)v805 >> 2)) >> 1)) & 3) * 2);
      int v839 = v838[v941];
      int * v840 = v799->cache_tags;
      int v841 = v840[v941];
      int v842 = v838[v920];
      int v843 = v840[v920];
      int * v844 = v799->cache_dirty;
      int v944 = (4 + ((((int)((unsigned int)((int)((unsigned int)v805 >> 2)) >> 1)) & 3) * 2)) + ((((v839 + ((~(((v841 ^ -1) | (-(v841 ^ -1))) >> 31)) & 2)) - (v842 + ((~(((v843 ^ -1) | (-(v843 ^ -1))) >> 31)) & 2))) >> 31) & 1);
      int v845 = v844[v944];
      bool v945 = !(v845 == 0);
      if (v945) {
        int * v846 = v799->cache_tags;
        int v847 = v846[v944];
        int * v848 = v799->cache_vals;
        int v948 = ((4 + ((((int)((unsigned int)((int)((unsigned int)v805 >> 2)) >> 1)) & 3) * 2)) + ((((v839 + ((~(((v841 ^ -1) | (-(v841 ^ -1))) >> 31)) & 2)) - (v842 + ((~(((v843 ^ -1) | (-(v843 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
        int v849 = v848[v948];
        int v949 = (((4 + ((((int)((unsigned int)((int)((unsigned int)v805 >> 2)) >> 1)) & 3) * 2)) + ((((v839 + ((~(((v841 ^ -1) | (-(v841 ^ -1))) >> 31)) & 2)) - (v842 + ((~(((v843 ^ -1) | (-(v843 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
        int v850 = v848[v949];
        int * v851 = v799->mem;
        int v951 = v847 * 2;
        v851[v951] = v849;
        int * v853 = v799->mem;
        int v954 = (v847 * 2) + 1;
        v853[v954] = v850;
        ;
      } else {
        ;
      }
      int * v858 = v799->mem;
      int v959 = ((int)((unsigned int)((int)((unsigned int)v805 >> 2)) >> 1)) * 2;
      int v859 = v858[v959];
      int v960 = (((int)((unsigned int)((int)((unsigned int)v805 >> 2)) >> 1)) * 2) + 1;
      int v860 = v858[v960];
      int * v861 = v799->cache_vals;
      int v962 = ((4 + ((((int)((unsigned int)((int)((unsigned int)v805 >> 2)) >> 1)) & 3) * 2)) + ((((v839 + ((~(((v841 ^ -1) | (-(v841 ^ -1))) >> 31)) & 2)) - (v842 + ((~(((v843 ^ -1) | (-(v843 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
      v861[v962] = v859;
      int * v863 = v799->cache_vals;
      int v965 = (((4 + ((((int)((unsigned int)((int)((unsigned int)v805 >> 2)) >> 1)) & 3) * 2)) + ((((v839 + ((~(((v841 ^ -1) | (-(v841 ^ -1))) >> 31)) & 2)) - (v842 + ((~(((v843 ^ -1) | (-(v843 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
      v863[v965] = v860;
      int * v865 = v799->cache_tags;
      int v968 = (int)((unsigned int)((int)((unsigned int)v805 >> 2)) >> 1);
      v865[v944] = v968;
      int * v867 = v799->cache_dirty;
      v867[v944] = 0;
      int * v869 = v799->cache_age;
      v869[v944] = 1;
      int * v871 = v799->cache_age;
      int v872 = v871[v944];
      int v873 = v871[v919];
      int v974 = v873 + ((int)((unsigned int)(v873 - v872) >> 31));
      v871[v919] = v974;
      int * v875 = v799->cache_age;
      int v876 = v875[v920];
      int v976 = v876 + ((int)((unsigned int)(v876 - v872) >> 31));
      v875[v920] = v976;
      int * v878 = v799->cache_age;
      v878[v944] = 0;
      v881 = v944;
    }
    int * v882 = v799->cache_vals;
    int v979 = v881 * 2;
    int v883 = v882[v979];
    int v980 = (v881 * 2) + 1;
    int v884 = v882[v980];
    int v981 = (((((int)((unsigned int)((int)((unsigned int)v805 >> 2)) >> 1)) & 1) * 2) + ((((v823 + ((~(((v825 ^ -1) | (-(v825 ^ -1))) >> 31)) & 2)) - (v826 + ((~(((v827 ^ -1) | (-(v827 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
    v882[v981] = v883;
    int * v886 = v799->cache_vals;
    int v984 = ((((((int)((unsigned int)((int)((unsigned int)v805 >> 2)) >> 1)) & 1) * 2) + ((((v823 + ((~(((v825 ^ -1) | (-(v825 ^ -1))) >> 31)) & 2)) - (v826 + ((~(((v827 ^ -1) | (-(v827 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
    v886[v984] = v884;
    int * v888 = v799->cache_tags;
    int v987 = ((((int)((unsigned int)((int)((unsigned int)v805 >> 2)) >> 1)) & 1) * 2) + ((((v823 + ((~(((v825 ^ -1) | (-(v825 ^ -1))) >> 31)) & 2)) - (v826 + ((~(((v827 ^ -1) | (-(v827 ^ -1))) >> 31)) & 2))) >> 31) & 1);
    int v988 = (int)((unsigned int)((int)((unsigned int)v805 >> 2)) >> 1);
    v888[v987] = v988;
    int * v890 = v799->cache_dirty;
    v890[v987] = 0;
    int * v892 = v799->cache_age;
    v892[v987] = 1;
    int * v894 = v799->cache_age;
    int v895 = v894[v987];
    int v896 = v894[v917];
    int v994 = v896 + ((int)((unsigned int)(v896 - v895) >> 31));
    v894[v917] = v994;
    int * v898 = v799->cache_age;
    int v899 = v898[v918];
    int v996 = v899 + ((int)((unsigned int)(v899 - v895) >> 31));
    v898[v918] = v996;
    int * v901 = v799->cache_age;
    v901[v987] = 0;
    v904 = v987;
  }
  int v999 = (v904 * 2) + (((int)((unsigned int)v805 >> 2)) & 1);
  int v905 = v811[v999];
  int * v906 = v799->reg_ready;
  int v1001 = ((v803 + ((v800 - v803) & (~((v800 - v803) >> 31)))) + 1) + ((100 ^ (((~(((v809 ^ ((int)((unsigned int)((int)((unsigned int)v805 >> 2)) >> 1))) | (-(v809 ^ ((int)((unsigned int)((int)((unsigned int)v805 >> 2)) >> 1))))) >> 31)) | (~(((v810 ^ ((int)((unsigned int)((int)((unsigned int)v805 >> 2)) >> 1))) | (-(v810 ^ ((int)((unsigned int)((int)((unsigned int)v805 >> 2)) >> 1))))) >> 31))) & 104)) ^ (((~(((v807 ^ ((int)((unsigned int)((int)((unsigned int)v805 >> 2)) >> 1))) | (-(v807 ^ ((int)((unsigned int)((int)((unsigned int)v805 >> 2)) >> 1))))) >> 31)) | (~(((v808 ^ ((int)((unsigned int)((int)((unsigned int)v805 >> 2)) >> 1))) | (-(v808 ^ ((int)((unsigned int)((int)((unsigned int)v805 >> 2)) >> 1))))) >> 31))) & (1 ^ (100 ^ (((~(((v809 ^ ((int)((unsigned int)((int)((unsigned int)v805 >> 2)) >> 1))) | (-(v809 ^ ((int)((unsigned int)((int)((unsigned int)v805 >> 2)) >> 1))))) >> 31)) | (~(((v810 ^ ((int)((unsigned int)((int)((unsigned int)v805 >> 2)) >> 1))) | (-(v810 ^ ((int)((unsigned int)((int)((unsigned int)v805 >> 2)) >> 1))))) >> 31))) & 104)))));
  v906[10] = v1001;
  int * v908 = v799->regs;
  v908[10] = v905;
  struct StateT * v910 = slot_23(v799);
  return v910;
}

struct StateT * slot_11(struct StateT * v592) {
  int v593 = v592->timer;
  int v604 = v593 + 1;
  v592->timer = v604;
  int * v595 = v592->reg_ready;
  int v596 = v595[11];
  int * v597 = v592->regs;
  int v598 = v597[11];
  int v608 = (v596 + ((v593 - v596) & (~((v593 - v596) >> 31)))) + 1;
  v595[11] = v608;
  int * v600 = v592->regs;
  int v610 = v598 + 72;
  v600[11] = v610;
  struct StateT * v602 = slot_13(v592);
  return v602;
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
  
  // public data, where the section headers put it
  s1.mem[0] = 8;
  s2.mem[0] = 8;
  int x = bounded(0, 15);
  s1.regs[10] = x;
  s2.regs[10] = x;
  // probe, the attacker's: the same draw in both states
  for (int i=0; i<16; i++) {
    int v = bounded(0, 20);
    s1.mem[1 + i] = v;
    s2.mem[1 + i] = v;
  }
  // temp, the attacker's: the same draw in both states
  for (int i=0; i<1; i++) {
    int v = bounded(0, 20);
    s1.mem[17 + i] = v;
    s2.mem[17 + i] = v;
  }
  // publicarray, the attacker's: the same draw in both states
  for (int i=0; i<8; i++) {
    int v = bounded(0, 20);
    s1.mem[18 + i] = v;
    s2.mem[18 + i] = v;
  }
  
  // secretarray, secret: a different draw in each state
  for (int i=0; i<8; i++) {
    s1.mem[26 + i] = secret(0, 20);
    s2.mem[26 + i] = secret(0, 20);
  }
  struct StateT *s1_ = snippet(&s1);
  struct StateT *s2_ = snippet(&s2);
  //@ assert untainted_timer: !\tainted(s1_->timer==s2_->timer);
  koika_assert(s1_->timer==s2_->timer, "timing leak");
  return 0;
}