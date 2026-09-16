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
  int cache_tags[12];
  int cache_dirty[12];
  int cache_age[12];
  int cache_vals[24];
  int timer;
};

struct StateT * slot_14(struct StateT * v1170);
struct StateT * slot_16(struct StateT * v1206);
struct StateT * slot_17(struct StateT * v1591);
struct StateT * slot_2(struct StateT * v501);
struct StateT * slot_3(struct StateT * v513);
struct StateT * snippet(struct StateT * v0);
struct StateT * slot_1(struct StateT * v251);
struct StateT * slot_4(struct StateT * v533);
struct StateT * slot_13(struct StateT * v1154);
struct StateT * slot_15(struct StateT * v1186);
struct StateT * slot_0(struct StateT * v2);
struct StateT * slot_14(struct StateT * v1170) {
  int v1171 = v1170->timer;
  int v1179 = v1171 + 1;
  v1170->timer = v1179;
  int * v1173 = v1170->regs;
  int v1174 = v1173[10];
  int * v1175 = v1170->regs;
  int v1183 = v1174 << 2;
  v1175[10] = v1183;
  struct StateT * v1177 = slot_15(v1170);
  return v1177;
}

struct StateT * slot_16(struct StateT * v1206) {
  int v1207 = v1206->timer;
  int v1412 = v1207 + 1;
  v1206->timer = v1412;
  int * v1209 = v1206->regs;
  int v1210 = v1209[10];
  int * v1211 = v1206->regs;
  int v1212 = v1211[12];
  int * v1213 = v1206->cache_tags;
  int v1418 = (((int)((unsigned int)((int)((unsigned int)v1210 >> 2)) >> 1)) & 1) * 2;
  int v1214 = v1213[v1418];
  int * v1215 = v1206->cache_tags;
  int v1420 = ((((int)((unsigned int)((int)((unsigned int)v1210 >> 2)) >> 1)) & 1) * 2) + 1;
  int v1216 = v1215[v1420];
  int * v1217 = v1206->cache_tags;
  int v1422 = 4 + ((((int)((unsigned int)((int)((unsigned int)v1210 >> 2)) >> 1)) & 3) * 2);
  int v1218 = v1217[v1422];
  int * v1219 = v1206->cache_tags;
  int v1424 = (4 + ((((int)((unsigned int)((int)((unsigned int)v1210 >> 2)) >> 1)) & 3) * 2)) + 1;
  int v1220 = v1219[v1424];
  int v1221 = v1206->timer;
  int v1425 = v1221 + ((100 ^ (((~(((v1218 ^ ((int)((unsigned int)((int)((unsigned int)v1210 >> 2)) >> 1))) | (-(v1218 ^ ((int)((unsigned int)((int)((unsigned int)v1210 >> 2)) >> 1))))) >> 31)) | (~(((v1220 ^ ((int)((unsigned int)((int)((unsigned int)v1210 >> 2)) >> 1))) | (-(v1220 ^ ((int)((unsigned int)((int)((unsigned int)v1210 >> 2)) >> 1))))) >> 31))) & 104)) ^ (((~(((v1214 ^ ((int)((unsigned int)((int)((unsigned int)v1210 >> 2)) >> 1))) | (-(v1214 ^ ((int)((unsigned int)((int)((unsigned int)v1210 >> 2)) >> 1))))) >> 31)) | (~(((v1216 ^ ((int)((unsigned int)((int)((unsigned int)v1210 >> 2)) >> 1))) | (-(v1216 ^ ((int)((unsigned int)((int)((unsigned int)v1210 >> 2)) >> 1))))) >> 31))) & (1 ^ (100 ^ (((~(((v1218 ^ ((int)((unsigned int)((int)((unsigned int)v1210 >> 2)) >> 1))) | (-(v1218 ^ ((int)((unsigned int)((int)((unsigned int)v1210 >> 2)) >> 1))))) >> 31)) | (~(((v1220 ^ ((int)((unsigned int)((int)((unsigned int)v1210 >> 2)) >> 1))) | (-(v1220 ^ ((int)((unsigned int)((int)((unsigned int)v1210 >> 2)) >> 1))))) >> 31))) & 104)))));
  v1206->timer = v1425;
  bool v1426 = !(((~(((v1214 ^ ((int)((unsigned int)((int)((unsigned int)v1210 >> 2)) >> 1))) | (-(v1214 ^ ((int)((unsigned int)((int)((unsigned int)v1210 >> 2)) >> 1))))) >> 31)) | (~(((v1216 ^ ((int)((unsigned int)((int)((unsigned int)v1210 >> 2)) >> 1))) | (-(v1216 ^ ((int)((unsigned int)((int)((unsigned int)v1210 >> 2)) >> 1))))) >> 31))) == 0);
  int v1335;
  if (v1426) {
    int * v1223 = v1206->cache_age;
    int v1428 = ((((int)((unsigned int)((int)((unsigned int)v1210 >> 2)) >> 1)) & 1) * 2) + ((~(((v1216 ^ ((int)((unsigned int)((int)((unsigned int)v1210 >> 2)) >> 1))) | (-(v1216 ^ ((int)((unsigned int)((int)((unsigned int)v1210 >> 2)) >> 1))))) >> 31)) & 1);
    int v1224 = v1223[v1428];
    int * v1225 = v1206->cache_age;
    int v1226 = v1225[v1418];
    int * v1227 = v1206->cache_age;
    int v1431 = v1226 + ((int)((unsigned int)(v1226 - v1224) >> 31));
    v1227[v1418] = v1431;
    int * v1229 = v1206->cache_age;
    int v1230 = v1229[v1420];
    int * v1231 = v1206->cache_age;
    int v1434 = v1230 + ((int)((unsigned int)(v1230 - v1224) >> 31));
    v1231[v1420] = v1434;
    int * v1233 = v1206->cache_age;
    v1233[v1428] = 0;
    v1335 = v1428;
  } else {
    int * v1236 = v1206->cache_age;
    int v1438 = (((int)((unsigned int)((int)((unsigned int)v1210 >> 2)) >> 1)) & 1) * 2;
    int v1237 = v1236[v1438];
    int * v1238 = v1206->cache_tags;
    int v1239 = v1238[v1438];
    int * v1240 = v1206->cache_age;
    int v1241 = v1240[v1420];
    int * v1242 = v1206->cache_tags;
    int v1243 = v1242[v1420];
    bool v1442 = !(((~(((v1218 ^ ((int)((unsigned int)((int)((unsigned int)v1210 >> 2)) >> 1))) | (-(v1218 ^ ((int)((unsigned int)((int)((unsigned int)v1210 >> 2)) >> 1))))) >> 31)) | (~(((v1220 ^ ((int)((unsigned int)((int)((unsigned int)v1210 >> 2)) >> 1))) | (-(v1220 ^ ((int)((unsigned int)((int)((unsigned int)v1210 >> 2)) >> 1))))) >> 31))) == 0);
    int v1307;
    if (v1442) {
      int * v1244 = v1206->cache_age;
      int v1444 = (4 + ((((int)((unsigned int)((int)((unsigned int)v1210 >> 2)) >> 1)) & 3) * 2)) + ((~(((v1220 ^ ((int)((unsigned int)((int)((unsigned int)v1210 >> 2)) >> 1))) | (-(v1220 ^ ((int)((unsigned int)((int)((unsigned int)v1210 >> 2)) >> 1))))) >> 31)) & 1);
      int v1245 = v1244[v1444];
      int * v1246 = v1206->cache_age;
      int v1247 = v1246[v1422];
      int * v1248 = v1206->cache_age;
      int v1447 = v1247 + ((int)((unsigned int)(v1247 - v1245) >> 31));
      v1248[v1422] = v1447;
      int * v1250 = v1206->cache_age;
      int v1251 = v1250[v1424];
      int * v1252 = v1206->cache_age;
      int v1450 = v1251 + ((int)((unsigned int)(v1251 - v1245) >> 31));
      v1252[v1424] = v1450;
      int * v1254 = v1206->cache_age;
      v1254[v1444] = 0;
      v1307 = v1444;
    } else {
      int * v1257 = v1206->cache_age;
      int v1454 = 4 + ((((int)((unsigned int)((int)((unsigned int)v1210 >> 2)) >> 1)) & 3) * 2);
      int v1258 = v1257[v1454];
      int * v1259 = v1206->cache_tags;
      int v1260 = v1259[v1454];
      int * v1261 = v1206->cache_age;
      int v1262 = v1261[v1424];
      int * v1263 = v1206->cache_tags;
      int v1264 = v1263[v1424];
      int * v1265 = v1206->cache_dirty;
      int v1459 = (4 + ((((int)((unsigned int)((int)((unsigned int)v1210 >> 2)) >> 1)) & 3) * 2)) + ((((v1258 + ((~(((v1260 ^ -1) | (-(v1260 ^ -1))) >> 31)) & 2)) - (v1262 + ((~(((v1264 ^ -1) | (-(v1264 ^ -1))) >> 31)) & 2))) >> 31) & 1);
      int v1266 = v1265[v1459];
      bool v1460 = !(v1266 == 0);
      if (v1460) {
        int * v1267 = v1206->cache_tags;
        int v1268 = v1267[v1459];
        int * v1269 = v1206->cache_vals;
        int v1463 = ((4 + ((((int)((unsigned int)((int)((unsigned int)v1210 >> 2)) >> 1)) & 3) * 2)) + ((((v1258 + ((~(((v1260 ^ -1) | (-(v1260 ^ -1))) >> 31)) & 2)) - (v1262 + ((~(((v1264 ^ -1) | (-(v1264 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
        int v1270 = v1269[v1463];
        int * v1271 = v1206->cache_vals;
        int v1465 = (((4 + ((((int)((unsigned int)((int)((unsigned int)v1210 >> 2)) >> 1)) & 3) * 2)) + ((((v1258 + ((~(((v1260 ^ -1) | (-(v1260 ^ -1))) >> 31)) & 2)) - (v1262 + ((~(((v1264 ^ -1) | (-(v1264 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
        int v1272 = v1271[v1465];
        int * v1273 = v1206->mem;
        int v1467 = v1268 * 2;
        v1273[v1467] = v1270;
        int * v1275 = v1206->mem;
        int v1470 = (v1268 * 2) + 1;
        v1275[v1470] = v1272;
        ;
      } else {
        ;
      }
      int * v1280 = v1206->mem;
      int v1475 = ((int)((unsigned int)((int)((unsigned int)v1210 >> 2)) >> 1)) * 2;
      int v1281 = v1280[v1475];
      int * v1282 = v1206->mem;
      int v1477 = (((int)((unsigned int)((int)((unsigned int)v1210 >> 2)) >> 1)) * 2) + 1;
      int v1283 = v1282[v1477];
      int * v1284 = v1206->cache_vals;
      int v1479 = ((4 + ((((int)((unsigned int)((int)((unsigned int)v1210 >> 2)) >> 1)) & 3) * 2)) + ((((v1258 + ((~(((v1260 ^ -1) | (-(v1260 ^ -1))) >> 31)) & 2)) - (v1262 + ((~(((v1264 ^ -1) | (-(v1264 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
      v1284[v1479] = v1281;
      int * v1286 = v1206->cache_vals;
      int v1482 = (((4 + ((((int)((unsigned int)((int)((unsigned int)v1210 >> 2)) >> 1)) & 3) * 2)) + ((((v1258 + ((~(((v1260 ^ -1) | (-(v1260 ^ -1))) >> 31)) & 2)) - (v1262 + ((~(((v1264 ^ -1) | (-(v1264 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
      v1286[v1482] = v1283;
      int * v1288 = v1206->cache_tags;
      int v1485 = (int)((unsigned int)((int)((unsigned int)v1210 >> 2)) >> 1);
      v1288[v1459] = v1485;
      int * v1290 = v1206->cache_dirty;
      v1290[v1459] = 0;
      int * v1292 = v1206->cache_age;
      v1292[v1459] = 1;
      int * v1294 = v1206->cache_age;
      int v1295 = v1294[v1459];
      int * v1296 = v1206->cache_age;
      int v1297 = v1296[v1422];
      int * v1298 = v1206->cache_age;
      int v1493 = v1297 + ((int)((unsigned int)(v1297 - v1295) >> 31));
      v1298[v1422] = v1493;
      int * v1300 = v1206->cache_age;
      int v1301 = v1300[v1424];
      int * v1302 = v1206->cache_age;
      int v1496 = v1301 + ((int)((unsigned int)(v1301 - v1295) >> 31));
      v1302[v1424] = v1496;
      int * v1304 = v1206->cache_age;
      v1304[v1459] = 0;
      v1307 = v1459;
    }
    int * v1308 = v1206->cache_vals;
    int v1499 = v1307 * 2;
    int v1309 = v1308[v1499];
    int * v1310 = v1206->cache_vals;
    int v1501 = (v1307 * 2) + 1;
    int v1311 = v1310[v1501];
    int * v1312 = v1206->cache_vals;
    int v1503 = (((((int)((unsigned int)((int)((unsigned int)v1210 >> 2)) >> 1)) & 1) * 2) + ((((v1237 + ((~(((v1239 ^ -1) | (-(v1239 ^ -1))) >> 31)) & 2)) - (v1241 + ((~(((v1243 ^ -1) | (-(v1243 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
    v1312[v1503] = v1309;
    int * v1314 = v1206->cache_vals;
    int v1506 = ((((((int)((unsigned int)((int)((unsigned int)v1210 >> 2)) >> 1)) & 1) * 2) + ((((v1237 + ((~(((v1239 ^ -1) | (-(v1239 ^ -1))) >> 31)) & 2)) - (v1241 + ((~(((v1243 ^ -1) | (-(v1243 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
    v1314[v1506] = v1311;
    int * v1316 = v1206->cache_tags;
    int v1509 = ((((int)((unsigned int)((int)((unsigned int)v1210 >> 2)) >> 1)) & 1) * 2) + ((((v1237 + ((~(((v1239 ^ -1) | (-(v1239 ^ -1))) >> 31)) & 2)) - (v1241 + ((~(((v1243 ^ -1) | (-(v1243 ^ -1))) >> 31)) & 2))) >> 31) & 1);
    int v1510 = (int)((unsigned int)((int)((unsigned int)v1210 >> 2)) >> 1);
    v1316[v1509] = v1510;
    int * v1318 = v1206->cache_dirty;
    v1318[v1509] = 0;
    int * v1320 = v1206->cache_age;
    v1320[v1509] = 1;
    int * v1322 = v1206->cache_age;
    int v1323 = v1322[v1509];
    int * v1324 = v1206->cache_age;
    int v1325 = v1324[v1418];
    int * v1326 = v1206->cache_age;
    int v1518 = v1325 + ((int)((unsigned int)(v1325 - v1323) >> 31));
    v1326[v1418] = v1518;
    int * v1328 = v1206->cache_age;
    int v1329 = v1328[v1420];
    int * v1330 = v1206->cache_age;
    int v1521 = v1329 + ((int)((unsigned int)(v1329 - v1323) >> 31));
    v1330[v1420] = v1521;
    int * v1332 = v1206->cache_age;
    v1332[v1509] = 0;
    v1335 = v1509;
  }
  int * v1336 = v1206->cache_vals;
  int v1524 = (v1335 * 2) + (((int)((unsigned int)v1210 >> 2)) & 1);
  v1336[v1524] = v1212;
  int * v1338 = v1206->cache_tags;
  int v1339 = v1338[v1422];
  int * v1340 = v1206->cache_tags;
  int v1341 = v1340[v1424];
  bool v1528 = !(((~(((v1339 ^ ((int)((unsigned int)((int)((unsigned int)v1210 >> 2)) >> 1))) | (-(v1339 ^ ((int)((unsigned int)((int)((unsigned int)v1210 >> 2)) >> 1))))) >> 31)) | (~(((v1341 ^ ((int)((unsigned int)((int)((unsigned int)v1210 >> 2)) >> 1))) | (-(v1341 ^ ((int)((unsigned int)((int)((unsigned int)v1210 >> 2)) >> 1))))) >> 31))) == 0);
  int v1405;
  if (v1528) {
    int * v1342 = v1206->cache_age;
    int v1530 = (4 + ((((int)((unsigned int)((int)((unsigned int)v1210 >> 2)) >> 1)) & 3) * 2)) + ((~(((v1341 ^ ((int)((unsigned int)((int)((unsigned int)v1210 >> 2)) >> 1))) | (-(v1341 ^ ((int)((unsigned int)((int)((unsigned int)v1210 >> 2)) >> 1))))) >> 31)) & 1);
    int v1343 = v1342[v1530];
    int * v1344 = v1206->cache_age;
    int v1345 = v1344[v1422];
    int * v1346 = v1206->cache_age;
    int v1533 = v1345 + ((int)((unsigned int)(v1345 - v1343) >> 31));
    v1346[v1422] = v1533;
    int * v1348 = v1206->cache_age;
    int v1349 = v1348[v1424];
    int * v1350 = v1206->cache_age;
    int v1536 = v1349 + ((int)((unsigned int)(v1349 - v1343) >> 31));
    v1350[v1424] = v1536;
    int * v1352 = v1206->cache_age;
    v1352[v1530] = 0;
    v1405 = v1530;
  } else {
    int * v1355 = v1206->cache_age;
    int v1540 = 4 + ((((int)((unsigned int)((int)((unsigned int)v1210 >> 2)) >> 1)) & 3) * 2);
    int v1356 = v1355[v1540];
    int * v1357 = v1206->cache_tags;
    int v1358 = v1357[v1540];
    int * v1359 = v1206->cache_age;
    int v1360 = v1359[v1424];
    int * v1361 = v1206->cache_tags;
    int v1362 = v1361[v1424];
    int * v1363 = v1206->cache_dirty;
    int v1545 = (4 + ((((int)((unsigned int)((int)((unsigned int)v1210 >> 2)) >> 1)) & 3) * 2)) + ((((v1356 + ((~(((v1358 ^ -1) | (-(v1358 ^ -1))) >> 31)) & 2)) - (v1360 + ((~(((v1362 ^ -1) | (-(v1362 ^ -1))) >> 31)) & 2))) >> 31) & 1);
    int v1364 = v1363[v1545];
    bool v1546 = !(v1364 == 0);
    if (v1546) {
      int * v1365 = v1206->cache_tags;
      int v1366 = v1365[v1545];
      int * v1367 = v1206->cache_vals;
      int v1549 = ((4 + ((((int)((unsigned int)((int)((unsigned int)v1210 >> 2)) >> 1)) & 3) * 2)) + ((((v1356 + ((~(((v1358 ^ -1) | (-(v1358 ^ -1))) >> 31)) & 2)) - (v1360 + ((~(((v1362 ^ -1) | (-(v1362 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
      int v1368 = v1367[v1549];
      int * v1369 = v1206->cache_vals;
      int v1551 = (((4 + ((((int)((unsigned int)((int)((unsigned int)v1210 >> 2)) >> 1)) & 3) * 2)) + ((((v1356 + ((~(((v1358 ^ -1) | (-(v1358 ^ -1))) >> 31)) & 2)) - (v1360 + ((~(((v1362 ^ -1) | (-(v1362 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
      int v1370 = v1369[v1551];
      int * v1371 = v1206->mem;
      int v1553 = v1366 * 2;
      v1371[v1553] = v1368;
      int * v1373 = v1206->mem;
      int v1556 = (v1366 * 2) + 1;
      v1373[v1556] = v1370;
      ;
    } else {
      ;
    }
    int * v1378 = v1206->mem;
    int v1561 = ((int)((unsigned int)((int)((unsigned int)v1210 >> 2)) >> 1)) * 2;
    int v1379 = v1378[v1561];
    int * v1380 = v1206->mem;
    int v1563 = (((int)((unsigned int)((int)((unsigned int)v1210 >> 2)) >> 1)) * 2) + 1;
    int v1381 = v1380[v1563];
    int * v1382 = v1206->cache_vals;
    int v1565 = ((4 + ((((int)((unsigned int)((int)((unsigned int)v1210 >> 2)) >> 1)) & 3) * 2)) + ((((v1356 + ((~(((v1358 ^ -1) | (-(v1358 ^ -1))) >> 31)) & 2)) - (v1360 + ((~(((v1362 ^ -1) | (-(v1362 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
    v1382[v1565] = v1379;
    int * v1384 = v1206->cache_vals;
    int v1568 = (((4 + ((((int)((unsigned int)((int)((unsigned int)v1210 >> 2)) >> 1)) & 3) * 2)) + ((((v1356 + ((~(((v1358 ^ -1) | (-(v1358 ^ -1))) >> 31)) & 2)) - (v1360 + ((~(((v1362 ^ -1) | (-(v1362 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
    v1384[v1568] = v1381;
    int * v1386 = v1206->cache_tags;
    int v1571 = (int)((unsigned int)((int)((unsigned int)v1210 >> 2)) >> 1);
    v1386[v1545] = v1571;
    int * v1388 = v1206->cache_dirty;
    v1388[v1545] = 0;
    int * v1390 = v1206->cache_age;
    v1390[v1545] = 1;
    int * v1392 = v1206->cache_age;
    int v1393 = v1392[v1545];
    int * v1394 = v1206->cache_age;
    int v1395 = v1394[v1422];
    int * v1396 = v1206->cache_age;
    int v1579 = v1395 + ((int)((unsigned int)(v1395 - v1393) >> 31));
    v1396[v1422] = v1579;
    int * v1398 = v1206->cache_age;
    int v1399 = v1398[v1424];
    int * v1400 = v1206->cache_age;
    int v1582 = v1399 + ((int)((unsigned int)(v1399 - v1393) >> 31));
    v1400[v1424] = v1582;
    int * v1402 = v1206->cache_age;
    v1402[v1545] = 0;
    v1405 = v1545;
  }
  int * v1406 = v1206->cache_vals;
  int v1585 = (v1405 * 2) + (((int)((unsigned int)v1210 >> 2)) & 1);
  v1406[v1585] = v1212;
  int * v1408 = v1206->cache_dirty;
  v1408[v1405] = 1;
  struct StateT * v1410 = slot_17(v1206);
  return v1410;
}

struct StateT * slot_17(struct StateT * v1591) {
  int v1592 = v1591->timer;
  int v1595 = v1592 + 1;
  v1591->timer = v1595;
  return v1591;
}

struct StateT * slot_2(struct StateT * v501) {
  int v502 = v501->timer;
  int v508 = v502 + 1;
  v501->timer = v508;
  int * v504 = v501->regs;
  v504[15] = 15;
  struct StateT * v506 = slot_3(v501);
  return v506;
}

struct StateT * slot_3(struct StateT * v513) {
  int v514 = v513->timer;
  int v524 = v514 + 1;
  v513->timer = v524;
  int * v516 = v513->regs;
  int v517 = v516[12];
  int * v518 = v513->regs;
  int v519 = v518[14];
  int * v520 = v513->regs;
  int v530 = v517 ^ v519;
  v520[12] = v530;
  struct StateT * v522 = slot_4(v513);
  return v522;
}

struct StateT * snippet(struct StateT * v0) {
  struct StateT * v1 = slot_0(v0);
  return v1;
}

struct StateT * slot_1(struct StateT * v251) {
  int v252 = v251->timer;
  int v385 = v252 + 1;
  v251->timer = v385;
  int * v254 = v251->regs;
  int v255 = v254[11];
  int * v256 = v251->cache_tags;
  int v389 = (((int)((unsigned int)((int)((unsigned int)(v255 + 12) >> 2)) >> 1)) & 1) * 2;
  int v257 = v256[v389];
  int * v258 = v251->cache_tags;
  int v391 = ((((int)((unsigned int)((int)((unsigned int)(v255 + 12) >> 2)) >> 1)) & 1) * 2) + 1;
  int v259 = v258[v391];
  int * v260 = v251->cache_tags;
  int v393 = 4 + ((((int)((unsigned int)((int)((unsigned int)(v255 + 12) >> 2)) >> 1)) & 3) * 2);
  int v261 = v260[v393];
  int * v262 = v251->cache_tags;
  int v395 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v255 + 12) >> 2)) >> 1)) & 3) * 2)) + 1;
  int v263 = v262[v395];
  int v264 = v251->timer;
  int v396 = v264 + ((100 ^ (((~(((v261 ^ ((int)((unsigned int)((int)((unsigned int)(v255 + 12) >> 2)) >> 1))) | (-(v261 ^ ((int)((unsigned int)((int)((unsigned int)(v255 + 12) >> 2)) >> 1))))) >> 31)) | (~(((v263 ^ ((int)((unsigned int)((int)((unsigned int)(v255 + 12) >> 2)) >> 1))) | (-(v263 ^ ((int)((unsigned int)((int)((unsigned int)(v255 + 12) >> 2)) >> 1))))) >> 31))) & 104)) ^ (((~(((v257 ^ ((int)((unsigned int)((int)((unsigned int)(v255 + 12) >> 2)) >> 1))) | (-(v257 ^ ((int)((unsigned int)((int)((unsigned int)(v255 + 12) >> 2)) >> 1))))) >> 31)) | (~(((v259 ^ ((int)((unsigned int)((int)((unsigned int)(v255 + 12) >> 2)) >> 1))) | (-(v259 ^ ((int)((unsigned int)((int)((unsigned int)(v255 + 12) >> 2)) >> 1))))) >> 31))) & (1 ^ (100 ^ (((~(((v261 ^ ((int)((unsigned int)((int)((unsigned int)(v255 + 12) >> 2)) >> 1))) | (-(v261 ^ ((int)((unsigned int)((int)((unsigned int)(v255 + 12) >> 2)) >> 1))))) >> 31)) | (~(((v263 ^ ((int)((unsigned int)((int)((unsigned int)(v255 + 12) >> 2)) >> 1))) | (-(v263 ^ ((int)((unsigned int)((int)((unsigned int)(v255 + 12) >> 2)) >> 1))))) >> 31))) & 104)))));
  v251->timer = v396;
  int * v266 = v251->cache_vals;
  bool v397 = !(((~(((v257 ^ ((int)((unsigned int)((int)((unsigned int)(v255 + 12) >> 2)) >> 1))) | (-(v257 ^ ((int)((unsigned int)((int)((unsigned int)(v255 + 12) >> 2)) >> 1))))) >> 31)) | (~(((v259 ^ ((int)((unsigned int)((int)((unsigned int)(v255 + 12) >> 2)) >> 1))) | (-(v259 ^ ((int)((unsigned int)((int)((unsigned int)(v255 + 12) >> 2)) >> 1))))) >> 31))) == 0);
  int v379;
  if (v397) {
    int * v267 = v251->cache_age;
    int v399 = ((((int)((unsigned int)((int)((unsigned int)(v255 + 12) >> 2)) >> 1)) & 1) * 2) + ((~(((v259 ^ ((int)((unsigned int)((int)((unsigned int)(v255 + 12) >> 2)) >> 1))) | (-(v259 ^ ((int)((unsigned int)((int)((unsigned int)(v255 + 12) >> 2)) >> 1))))) >> 31)) & 1);
    int v268 = v267[v399];
    int * v269 = v251->cache_age;
    int v270 = v269[v389];
    int * v271 = v251->cache_age;
    int v402 = v270 + ((int)((unsigned int)(v270 - v268) >> 31));
    v271[v389] = v402;
    int * v273 = v251->cache_age;
    int v274 = v273[v391];
    int * v275 = v251->cache_age;
    int v405 = v274 + ((int)((unsigned int)(v274 - v268) >> 31));
    v275[v391] = v405;
    int * v277 = v251->cache_age;
    v277[v399] = 0;
    v379 = v399;
  } else {
    int * v280 = v251->cache_age;
    int v409 = (((int)((unsigned int)((int)((unsigned int)(v255 + 12) >> 2)) >> 1)) & 1) * 2;
    int v281 = v280[v409];
    int * v282 = v251->cache_tags;
    int v283 = v282[v409];
    int * v284 = v251->cache_age;
    int v285 = v284[v391];
    int * v286 = v251->cache_tags;
    int v287 = v286[v391];
    bool v413 = !(((~(((v261 ^ ((int)((unsigned int)((int)((unsigned int)(v255 + 12) >> 2)) >> 1))) | (-(v261 ^ ((int)((unsigned int)((int)((unsigned int)(v255 + 12) >> 2)) >> 1))))) >> 31)) | (~(((v263 ^ ((int)((unsigned int)((int)((unsigned int)(v255 + 12) >> 2)) >> 1))) | (-(v263 ^ ((int)((unsigned int)((int)((unsigned int)(v255 + 12) >> 2)) >> 1))))) >> 31))) == 0);
    int v351;
    if (v413) {
      int * v288 = v251->cache_age;
      int v415 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v255 + 12) >> 2)) >> 1)) & 3) * 2)) + ((~(((v263 ^ ((int)((unsigned int)((int)((unsigned int)(v255 + 12) >> 2)) >> 1))) | (-(v263 ^ ((int)((unsigned int)((int)((unsigned int)(v255 + 12) >> 2)) >> 1))))) >> 31)) & 1);
      int v289 = v288[v415];
      int * v290 = v251->cache_age;
      int v291 = v290[v393];
      int * v292 = v251->cache_age;
      int v418 = v291 + ((int)((unsigned int)(v291 - v289) >> 31));
      v292[v393] = v418;
      int * v294 = v251->cache_age;
      int v295 = v294[v395];
      int * v296 = v251->cache_age;
      int v421 = v295 + ((int)((unsigned int)(v295 - v289) >> 31));
      v296[v395] = v421;
      int * v298 = v251->cache_age;
      v298[v415] = 0;
      v351 = v415;
    } else {
      int * v301 = v251->cache_age;
      int v425 = 4 + ((((int)((unsigned int)((int)((unsigned int)(v255 + 12) >> 2)) >> 1)) & 3) * 2);
      int v302 = v301[v425];
      int * v303 = v251->cache_tags;
      int v304 = v303[v425];
      int * v305 = v251->cache_age;
      int v306 = v305[v395];
      int * v307 = v251->cache_tags;
      int v308 = v307[v395];
      int * v309 = v251->cache_dirty;
      int v430 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v255 + 12) >> 2)) >> 1)) & 3) * 2)) + ((((v302 + ((~(((v304 ^ -1) | (-(v304 ^ -1))) >> 31)) & 2)) - (v306 + ((~(((v308 ^ -1) | (-(v308 ^ -1))) >> 31)) & 2))) >> 31) & 1);
      int v310 = v309[v430];
      bool v431 = !(v310 == 0);
      if (v431) {
        int * v311 = v251->cache_tags;
        int v312 = v311[v430];
        int * v313 = v251->cache_vals;
        int v434 = ((4 + ((((int)((unsigned int)((int)((unsigned int)(v255 + 12) >> 2)) >> 1)) & 3) * 2)) + ((((v302 + ((~(((v304 ^ -1) | (-(v304 ^ -1))) >> 31)) & 2)) - (v306 + ((~(((v308 ^ -1) | (-(v308 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
        int v314 = v313[v434];
        int * v315 = v251->cache_vals;
        int v436 = (((4 + ((((int)((unsigned int)((int)((unsigned int)(v255 + 12) >> 2)) >> 1)) & 3) * 2)) + ((((v302 + ((~(((v304 ^ -1) | (-(v304 ^ -1))) >> 31)) & 2)) - (v306 + ((~(((v308 ^ -1) | (-(v308 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
        int v316 = v315[v436];
        int * v317 = v251->mem;
        int v438 = v312 * 2;
        v317[v438] = v314;
        int * v319 = v251->mem;
        int v441 = (v312 * 2) + 1;
        v319[v441] = v316;
        ;
      } else {
        ;
      }
      int * v324 = v251->mem;
      int v446 = ((int)((unsigned int)((int)((unsigned int)(v255 + 12) >> 2)) >> 1)) * 2;
      int v325 = v324[v446];
      int * v326 = v251->mem;
      int v448 = (((int)((unsigned int)((int)((unsigned int)(v255 + 12) >> 2)) >> 1)) * 2) + 1;
      int v327 = v326[v448];
      int * v328 = v251->cache_vals;
      int v450 = ((4 + ((((int)((unsigned int)((int)((unsigned int)(v255 + 12) >> 2)) >> 1)) & 3) * 2)) + ((((v302 + ((~(((v304 ^ -1) | (-(v304 ^ -1))) >> 31)) & 2)) - (v306 + ((~(((v308 ^ -1) | (-(v308 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
      v328[v450] = v325;
      int * v330 = v251->cache_vals;
      int v453 = (((4 + ((((int)((unsigned int)((int)((unsigned int)(v255 + 12) >> 2)) >> 1)) & 3) * 2)) + ((((v302 + ((~(((v304 ^ -1) | (-(v304 ^ -1))) >> 31)) & 2)) - (v306 + ((~(((v308 ^ -1) | (-(v308 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
      v330[v453] = v327;
      int * v332 = v251->cache_tags;
      int v456 = (int)((unsigned int)((int)((unsigned int)(v255 + 12) >> 2)) >> 1);
      v332[v430] = v456;
      int * v334 = v251->cache_dirty;
      v334[v430] = 0;
      int * v336 = v251->cache_age;
      v336[v430] = 1;
      int * v338 = v251->cache_age;
      int v339 = v338[v430];
      int * v340 = v251->cache_age;
      int v341 = v340[v393];
      int * v342 = v251->cache_age;
      int v464 = v341 + ((int)((unsigned int)(v341 - v339) >> 31));
      v342[v393] = v464;
      int * v344 = v251->cache_age;
      int v345 = v344[v395];
      int * v346 = v251->cache_age;
      int v467 = v345 + ((int)((unsigned int)(v345 - v339) >> 31));
      v346[v395] = v467;
      int * v348 = v251->cache_age;
      v348[v430] = 0;
      v351 = v430;
    }
    int * v352 = v251->cache_vals;
    int v470 = v351 * 2;
    int v353 = v352[v470];
    int * v354 = v251->cache_vals;
    int v472 = (v351 * 2) + 1;
    int v355 = v354[v472];
    int * v356 = v251->cache_vals;
    int v474 = (((((int)((unsigned int)((int)((unsigned int)(v255 + 12) >> 2)) >> 1)) & 1) * 2) + ((((v281 + ((~(((v283 ^ -1) | (-(v283 ^ -1))) >> 31)) & 2)) - (v285 + ((~(((v287 ^ -1) | (-(v287 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
    v356[v474] = v353;
    int * v358 = v251->cache_vals;
    int v477 = ((((((int)((unsigned int)((int)((unsigned int)(v255 + 12) >> 2)) >> 1)) & 1) * 2) + ((((v281 + ((~(((v283 ^ -1) | (-(v283 ^ -1))) >> 31)) & 2)) - (v285 + ((~(((v287 ^ -1) | (-(v287 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
    v358[v477] = v355;
    int * v360 = v251->cache_tags;
    int v480 = ((((int)((unsigned int)((int)((unsigned int)(v255 + 12) >> 2)) >> 1)) & 1) * 2) + ((((v281 + ((~(((v283 ^ -1) | (-(v283 ^ -1))) >> 31)) & 2)) - (v285 + ((~(((v287 ^ -1) | (-(v287 ^ -1))) >> 31)) & 2))) >> 31) & 1);
    int v481 = (int)((unsigned int)((int)((unsigned int)(v255 + 12) >> 2)) >> 1);
    v360[v480] = v481;
    int * v362 = v251->cache_dirty;
    v362[v480] = 0;
    int * v364 = v251->cache_age;
    v364[v480] = 1;
    int * v366 = v251->cache_age;
    int v367 = v366[v480];
    int * v368 = v251->cache_age;
    int v369 = v368[v389];
    int * v370 = v251->cache_age;
    int v489 = v369 + ((int)((unsigned int)(v369 - v367) >> 31));
    v370[v389] = v489;
    int * v372 = v251->cache_age;
    int v373 = v372[v391];
    int * v374 = v251->cache_age;
    int v492 = v373 + ((int)((unsigned int)(v373 - v367) >> 31));
    v374[v391] = v492;
    int * v376 = v251->cache_age;
    v376[v480] = 0;
    v379 = v480;
  }
  int v495 = (v379 * 2) + (((int)((unsigned int)(v255 + 12) >> 2)) & 1);
  int v380 = v266[v495];
  int * v381 = v251->regs;
  v381[14] = v380;
  struct StateT * v383 = slot_2(v251);
  return v383;
}

struct StateT * slot_4(struct StateT * v533) {
  int * v534 = v533->saved_regs;
  int * v535 = v533->regs;
  int v536 = v535[14];
  v534[14] = v536;
  int v538 = v533->timer;
  int v877 = v538 + 1;
  v533->timer = v877;
  int * v540 = v533->regs;
  int v541 = v540[10];
  int * v542 = v533->regs;
  int v881 = v541 << 2;
  v542[14] = v881;
  int v544 = v533->timer;
  int v882 = v544 + 1;
  v533->timer = v882;
  int * v546 = v533->regs;
  int v547 = v546[11];
  int * v548 = v533->regs;
  int v549 = v548[14];
  int * v550 = v533->regs;
  int v887 = v547 + v549;
  v550[14] = v887;
  int v552 = v533->timer;
  int v888 = v552 + 1;
  v533->timer = v888;
  int * v554 = v533->regs;
  int v555 = v554[14];
  int * v556 = v533->cache_tags;
  int v891 = (((int)((unsigned int)((int)((unsigned int)v555 >> 2)) >> 1)) & 1) * 2;
  int v557 = v556[v891];
  int * v558 = v533->cache_tags;
  int v893 = ((((int)((unsigned int)((int)((unsigned int)v555 >> 2)) >> 1)) & 1) * 2) + 1;
  int v559 = v558[v893];
  int * v560 = v533->cache_tags;
  int v895 = 4 + ((((int)((unsigned int)((int)((unsigned int)v555 >> 2)) >> 1)) & 3) * 2);
  int v561 = v560[v895];
  int * v562 = v533->cache_tags;
  int v897 = (4 + ((((int)((unsigned int)((int)((unsigned int)v555 >> 2)) >> 1)) & 3) * 2)) + 1;
  int v563 = v562[v897];
  int v564 = v533->timer;
  int v898 = v564 + ((100 ^ (((~(((v561 ^ ((int)((unsigned int)((int)((unsigned int)v555 >> 2)) >> 1))) | (-(v561 ^ ((int)((unsigned int)((int)((unsigned int)v555 >> 2)) >> 1))))) >> 31)) | (~(((v563 ^ ((int)((unsigned int)((int)((unsigned int)v555 >> 2)) >> 1))) | (-(v563 ^ ((int)((unsigned int)((int)((unsigned int)v555 >> 2)) >> 1))))) >> 31))) & 104)) ^ (((~(((v557 ^ ((int)((unsigned int)((int)((unsigned int)v555 >> 2)) >> 1))) | (-(v557 ^ ((int)((unsigned int)((int)((unsigned int)v555 >> 2)) >> 1))))) >> 31)) | (~(((v559 ^ ((int)((unsigned int)((int)((unsigned int)v555 >> 2)) >> 1))) | (-(v559 ^ ((int)((unsigned int)((int)((unsigned int)v555 >> 2)) >> 1))))) >> 31))) & (1 ^ (100 ^ (((~(((v561 ^ ((int)((unsigned int)((int)((unsigned int)v555 >> 2)) >> 1))) | (-(v561 ^ ((int)((unsigned int)((int)((unsigned int)v555 >> 2)) >> 1))))) >> 31)) | (~(((v563 ^ ((int)((unsigned int)((int)((unsigned int)v555 >> 2)) >> 1))) | (-(v563 ^ ((int)((unsigned int)((int)((unsigned int)v555 >> 2)) >> 1))))) >> 31))) & 104)))));
  v533->timer = v898;
  int * v566 = v533->cache_vals;
  bool v899 = !(((~(((v557 ^ ((int)((unsigned int)((int)((unsigned int)v555 >> 2)) >> 1))) | (-(v557 ^ ((int)((unsigned int)((int)((unsigned int)v555 >> 2)) >> 1))))) >> 31)) | (~(((v559 ^ ((int)((unsigned int)((int)((unsigned int)v555 >> 2)) >> 1))) | (-(v559 ^ ((int)((unsigned int)((int)((unsigned int)v555 >> 2)) >> 1))))) >> 31))) == 0);
  int v679;
  if (v899) {
    int * v567 = v533->cache_age;
    int v901 = ((((int)((unsigned int)((int)((unsigned int)v555 >> 2)) >> 1)) & 1) * 2) + ((~(((v559 ^ ((int)((unsigned int)((int)((unsigned int)v555 >> 2)) >> 1))) | (-(v559 ^ ((int)((unsigned int)((int)((unsigned int)v555 >> 2)) >> 1))))) >> 31)) & 1);
    int v568 = v567[v901];
    int * v569 = v533->cache_age;
    int v570 = v569[v891];
    int * v571 = v533->cache_age;
    int v904 = v570 + ((int)((unsigned int)(v570 - v568) >> 31));
    v571[v891] = v904;
    int * v573 = v533->cache_age;
    int v574 = v573[v893];
    int * v575 = v533->cache_age;
    int v907 = v574 + ((int)((unsigned int)(v574 - v568) >> 31));
    v575[v893] = v907;
    int * v577 = v533->cache_age;
    v577[v901] = 0;
    v679 = v901;
  } else {
    int * v580 = v533->cache_age;
    int v911 = (((int)((unsigned int)((int)((unsigned int)v555 >> 2)) >> 1)) & 1) * 2;
    int v581 = v580[v911];
    int * v582 = v533->cache_tags;
    int v583 = v582[v911];
    int * v584 = v533->cache_age;
    int v585 = v584[v893];
    int * v586 = v533->cache_tags;
    int v587 = v586[v893];
    bool v915 = !(((~(((v561 ^ ((int)((unsigned int)((int)((unsigned int)v555 >> 2)) >> 1))) | (-(v561 ^ ((int)((unsigned int)((int)((unsigned int)v555 >> 2)) >> 1))))) >> 31)) | (~(((v563 ^ ((int)((unsigned int)((int)((unsigned int)v555 >> 2)) >> 1))) | (-(v563 ^ ((int)((unsigned int)((int)((unsigned int)v555 >> 2)) >> 1))))) >> 31))) == 0);
    int v651;
    if (v915) {
      int * v588 = v533->cache_age;
      int v917 = (4 + ((((int)((unsigned int)((int)((unsigned int)v555 >> 2)) >> 1)) & 3) * 2)) + ((~(((v563 ^ ((int)((unsigned int)((int)((unsigned int)v555 >> 2)) >> 1))) | (-(v563 ^ ((int)((unsigned int)((int)((unsigned int)v555 >> 2)) >> 1))))) >> 31)) & 1);
      int v589 = v588[v917];
      int * v590 = v533->cache_age;
      int v591 = v590[v895];
      int * v592 = v533->cache_age;
      int v920 = v591 + ((int)((unsigned int)(v591 - v589) >> 31));
      v592[v895] = v920;
      int * v594 = v533->cache_age;
      int v595 = v594[v897];
      int * v596 = v533->cache_age;
      int v923 = v595 + ((int)((unsigned int)(v595 - v589) >> 31));
      v596[v897] = v923;
      int * v598 = v533->cache_age;
      v598[v917] = 0;
      v651 = v917;
    } else {
      int * v601 = v533->cache_age;
      int v927 = 4 + ((((int)((unsigned int)((int)((unsigned int)v555 >> 2)) >> 1)) & 3) * 2);
      int v602 = v601[v927];
      int * v603 = v533->cache_tags;
      int v604 = v603[v927];
      int * v605 = v533->cache_age;
      int v606 = v605[v897];
      int * v607 = v533->cache_tags;
      int v608 = v607[v897];
      int * v609 = v533->cache_dirty;
      int v932 = (4 + ((((int)((unsigned int)((int)((unsigned int)v555 >> 2)) >> 1)) & 3) * 2)) + ((((v602 + ((~(((v604 ^ -1) | (-(v604 ^ -1))) >> 31)) & 2)) - (v606 + ((~(((v608 ^ -1) | (-(v608 ^ -1))) >> 31)) & 2))) >> 31) & 1);
      int v610 = v609[v932];
      bool v933 = !(v610 == 0);
      if (v933) {
        int * v611 = v533->cache_tags;
        int v612 = v611[v932];
        int * v613 = v533->cache_vals;
        int v936 = ((4 + ((((int)((unsigned int)((int)((unsigned int)v555 >> 2)) >> 1)) & 3) * 2)) + ((((v602 + ((~(((v604 ^ -1) | (-(v604 ^ -1))) >> 31)) & 2)) - (v606 + ((~(((v608 ^ -1) | (-(v608 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
        int v614 = v613[v936];
        int * v615 = v533->cache_vals;
        int v938 = (((4 + ((((int)((unsigned int)((int)((unsigned int)v555 >> 2)) >> 1)) & 3) * 2)) + ((((v602 + ((~(((v604 ^ -1) | (-(v604 ^ -1))) >> 31)) & 2)) - (v606 + ((~(((v608 ^ -1) | (-(v608 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
        int v616 = v615[v938];
        int * v617 = v533->mem;
        int v940 = v612 * 2;
        v617[v940] = v614;
        int * v619 = v533->mem;
        int v943 = (v612 * 2) + 1;
        v619[v943] = v616;
        ;
      } else {
        ;
      }
      int * v624 = v533->mem;
      int v948 = ((int)((unsigned int)((int)((unsigned int)v555 >> 2)) >> 1)) * 2;
      int v625 = v624[v948];
      int * v626 = v533->mem;
      int v950 = (((int)((unsigned int)((int)((unsigned int)v555 >> 2)) >> 1)) * 2) + 1;
      int v627 = v626[v950];
      int * v628 = v533->cache_vals;
      int v952 = ((4 + ((((int)((unsigned int)((int)((unsigned int)v555 >> 2)) >> 1)) & 3) * 2)) + ((((v602 + ((~(((v604 ^ -1) | (-(v604 ^ -1))) >> 31)) & 2)) - (v606 + ((~(((v608 ^ -1) | (-(v608 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
      v628[v952] = v625;
      int * v630 = v533->cache_vals;
      int v955 = (((4 + ((((int)((unsigned int)((int)((unsigned int)v555 >> 2)) >> 1)) & 3) * 2)) + ((((v602 + ((~(((v604 ^ -1) | (-(v604 ^ -1))) >> 31)) & 2)) - (v606 + ((~(((v608 ^ -1) | (-(v608 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
      v630[v955] = v627;
      int * v632 = v533->cache_tags;
      int v958 = (int)((unsigned int)((int)((unsigned int)v555 >> 2)) >> 1);
      v632[v932] = v958;
      int * v634 = v533->cache_dirty;
      v634[v932] = 0;
      int * v636 = v533->cache_age;
      v636[v932] = 1;
      int * v638 = v533->cache_age;
      int v639 = v638[v932];
      int * v640 = v533->cache_age;
      int v641 = v640[v895];
      int * v642 = v533->cache_age;
      int v966 = v641 + ((int)((unsigned int)(v641 - v639) >> 31));
      v642[v895] = v966;
      int * v644 = v533->cache_age;
      int v645 = v644[v897];
      int * v646 = v533->cache_age;
      int v969 = v645 + ((int)((unsigned int)(v645 - v639) >> 31));
      v646[v897] = v969;
      int * v648 = v533->cache_age;
      v648[v932] = 0;
      v651 = v932;
    }
    int * v652 = v533->cache_vals;
    int v972 = v651 * 2;
    int v653 = v652[v972];
    int * v654 = v533->cache_vals;
    int v974 = (v651 * 2) + 1;
    int v655 = v654[v974];
    int * v656 = v533->cache_vals;
    int v976 = (((((int)((unsigned int)((int)((unsigned int)v555 >> 2)) >> 1)) & 1) * 2) + ((((v581 + ((~(((v583 ^ -1) | (-(v583 ^ -1))) >> 31)) & 2)) - (v585 + ((~(((v587 ^ -1) | (-(v587 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
    v656[v976] = v653;
    int * v658 = v533->cache_vals;
    int v979 = ((((((int)((unsigned int)((int)((unsigned int)v555 >> 2)) >> 1)) & 1) * 2) + ((((v581 + ((~(((v583 ^ -1) | (-(v583 ^ -1))) >> 31)) & 2)) - (v585 + ((~(((v587 ^ -1) | (-(v587 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
    v658[v979] = v655;
    int * v660 = v533->cache_tags;
    int v982 = ((((int)((unsigned int)((int)((unsigned int)v555 >> 2)) >> 1)) & 1) * 2) + ((((v581 + ((~(((v583 ^ -1) | (-(v583 ^ -1))) >> 31)) & 2)) - (v585 + ((~(((v587 ^ -1) | (-(v587 ^ -1))) >> 31)) & 2))) >> 31) & 1);
    int v983 = (int)((unsigned int)((int)((unsigned int)v555 >> 2)) >> 1);
    v660[v982] = v983;
    int * v662 = v533->cache_dirty;
    v662[v982] = 0;
    int * v664 = v533->cache_age;
    v664[v982] = 1;
    int * v666 = v533->cache_age;
    int v667 = v666[v982];
    int * v668 = v533->cache_age;
    int v669 = v668[v891];
    int * v670 = v533->cache_age;
    int v991 = v669 + ((int)((unsigned int)(v669 - v667) >> 31));
    v670[v891] = v991;
    int * v672 = v533->cache_age;
    int v673 = v672[v893];
    int * v674 = v533->cache_age;
    int v994 = v673 + ((int)((unsigned int)(v673 - v667) >> 31));
    v674[v893] = v994;
    int * v676 = v533->cache_age;
    v676[v982] = 0;
    v679 = v982;
  }
  int v997 = (v679 * 2) + (((int)((unsigned int)v555 >> 2)) & 1);
  int v680 = v566[v997];
  int * v681 = v533->regs;
  v681[14] = v680;
  int v683 = v533->timer;
  int v1000 = v683 + 1;
  v533->timer = v1000;
  int * v685 = v533->regs;
  int v686 = v685[14];
  int * v687 = v533->regs;
  int v1003 = v686 & 15;
  v687[14] = v1003;
  int v689 = v533->timer;
  int v1004 = v689 + 1;
  v533->timer = v1004;
  int * v691 = v533->regs;
  int v692 = v691[14];
  int * v693 = v533->regs;
  int v1007 = v692 << 2;
  v693[14] = v1007;
  int * v695 = v533->saved_regs;
  int * v696 = v533->regs;
  int v697 = v696[11];
  v695[11] = v697;
  int v699 = v533->timer;
  int v1011 = v699 + 1;
  v533->timer = v1011;
  int * v701 = v533->regs;
  int v702 = v701[11];
  int * v703 = v533->regs;
  int v704 = v703[14];
  int * v705 = v533->regs;
  int v1015 = v702 + v704;
  v705[11] = v1015;
  int v707 = v533->timer;
  int v1016 = v707 + 1;
  v533->timer = v1016;
  int * v709 = v533->regs;
  int v710 = v709[11];
  int * v711 = v533->cache_tags;
  int v1019 = (((int)((unsigned int)((int)((unsigned int)v710 >> 2)) >> 1)) & 1) * 2;
  int v712 = v711[v1019];
  int * v713 = v533->cache_tags;
  int v1021 = ((((int)((unsigned int)((int)((unsigned int)v710 >> 2)) >> 1)) & 1) * 2) + 1;
  int v714 = v713[v1021];
  int * v715 = v533->cache_tags;
  int v1023 = 4 + ((((int)((unsigned int)((int)((unsigned int)v710 >> 2)) >> 1)) & 3) * 2);
  int v716 = v715[v1023];
  int * v717 = v533->cache_tags;
  int v1025 = (4 + ((((int)((unsigned int)((int)((unsigned int)v710 >> 2)) >> 1)) & 3) * 2)) + 1;
  int v718 = v717[v1025];
  int v719 = v533->timer;
  int v1026 = v719 + ((100 ^ (((~(((v716 ^ ((int)((unsigned int)((int)((unsigned int)v710 >> 2)) >> 1))) | (-(v716 ^ ((int)((unsigned int)((int)((unsigned int)v710 >> 2)) >> 1))))) >> 31)) | (~(((v718 ^ ((int)((unsigned int)((int)((unsigned int)v710 >> 2)) >> 1))) | (-(v718 ^ ((int)((unsigned int)((int)((unsigned int)v710 >> 2)) >> 1))))) >> 31))) & 104)) ^ (((~(((v712 ^ ((int)((unsigned int)((int)((unsigned int)v710 >> 2)) >> 1))) | (-(v712 ^ ((int)((unsigned int)((int)((unsigned int)v710 >> 2)) >> 1))))) >> 31)) | (~(((v714 ^ ((int)((unsigned int)((int)((unsigned int)v710 >> 2)) >> 1))) | (-(v714 ^ ((int)((unsigned int)((int)((unsigned int)v710 >> 2)) >> 1))))) >> 31))) & (1 ^ (100 ^ (((~(((v716 ^ ((int)((unsigned int)((int)((unsigned int)v710 >> 2)) >> 1))) | (-(v716 ^ ((int)((unsigned int)((int)((unsigned int)v710 >> 2)) >> 1))))) >> 31)) | (~(((v718 ^ ((int)((unsigned int)((int)((unsigned int)v710 >> 2)) >> 1))) | (-(v718 ^ ((int)((unsigned int)((int)((unsigned int)v710 >> 2)) >> 1))))) >> 31))) & 104)))));
  v533->timer = v1026;
  int * v721 = v533->cache_vals;
  bool v1027 = !(((~(((v712 ^ ((int)((unsigned int)((int)((unsigned int)v710 >> 2)) >> 1))) | (-(v712 ^ ((int)((unsigned int)((int)((unsigned int)v710 >> 2)) >> 1))))) >> 31)) | (~(((v714 ^ ((int)((unsigned int)((int)((unsigned int)v710 >> 2)) >> 1))) | (-(v714 ^ ((int)((unsigned int)((int)((unsigned int)v710 >> 2)) >> 1))))) >> 31))) == 0);
  int v834;
  if (v1027) {
    int * v722 = v533->cache_age;
    int v1029 = ((((int)((unsigned int)((int)((unsigned int)v710 >> 2)) >> 1)) & 1) * 2) + ((~(((v714 ^ ((int)((unsigned int)((int)((unsigned int)v710 >> 2)) >> 1))) | (-(v714 ^ ((int)((unsigned int)((int)((unsigned int)v710 >> 2)) >> 1))))) >> 31)) & 1);
    int v723 = v722[v1029];
    int * v724 = v533->cache_age;
    int v725 = v724[v1019];
    int * v726 = v533->cache_age;
    int v1032 = v725 + ((int)((unsigned int)(v725 - v723) >> 31));
    v726[v1019] = v1032;
    int * v728 = v533->cache_age;
    int v729 = v728[v1021];
    int * v730 = v533->cache_age;
    int v1035 = v729 + ((int)((unsigned int)(v729 - v723) >> 31));
    v730[v1021] = v1035;
    int * v732 = v533->cache_age;
    v732[v1029] = 0;
    v834 = v1029;
  } else {
    int * v735 = v533->cache_age;
    int v1039 = (((int)((unsigned int)((int)((unsigned int)v710 >> 2)) >> 1)) & 1) * 2;
    int v736 = v735[v1039];
    int * v737 = v533->cache_tags;
    int v738 = v737[v1039];
    int * v739 = v533->cache_age;
    int v740 = v739[v1021];
    int * v741 = v533->cache_tags;
    int v742 = v741[v1021];
    bool v1043 = !(((~(((v716 ^ ((int)((unsigned int)((int)((unsigned int)v710 >> 2)) >> 1))) | (-(v716 ^ ((int)((unsigned int)((int)((unsigned int)v710 >> 2)) >> 1))))) >> 31)) | (~(((v718 ^ ((int)((unsigned int)((int)((unsigned int)v710 >> 2)) >> 1))) | (-(v718 ^ ((int)((unsigned int)((int)((unsigned int)v710 >> 2)) >> 1))))) >> 31))) == 0);
    int v806;
    if (v1043) {
      int * v743 = v533->cache_age;
      int v1045 = (4 + ((((int)((unsigned int)((int)((unsigned int)v710 >> 2)) >> 1)) & 3) * 2)) + ((~(((v718 ^ ((int)((unsigned int)((int)((unsigned int)v710 >> 2)) >> 1))) | (-(v718 ^ ((int)((unsigned int)((int)((unsigned int)v710 >> 2)) >> 1))))) >> 31)) & 1);
      int v744 = v743[v1045];
      int * v745 = v533->cache_age;
      int v746 = v745[v1023];
      int * v747 = v533->cache_age;
      int v1048 = v746 + ((int)((unsigned int)(v746 - v744) >> 31));
      v747[v1023] = v1048;
      int * v749 = v533->cache_age;
      int v750 = v749[v1025];
      int * v751 = v533->cache_age;
      int v1051 = v750 + ((int)((unsigned int)(v750 - v744) >> 31));
      v751[v1025] = v1051;
      int * v753 = v533->cache_age;
      v753[v1045] = 0;
      v806 = v1045;
    } else {
      int * v756 = v533->cache_age;
      int v1055 = 4 + ((((int)((unsigned int)((int)((unsigned int)v710 >> 2)) >> 1)) & 3) * 2);
      int v757 = v756[v1055];
      int * v758 = v533->cache_tags;
      int v759 = v758[v1055];
      int * v760 = v533->cache_age;
      int v761 = v760[v1025];
      int * v762 = v533->cache_tags;
      int v763 = v762[v1025];
      int * v764 = v533->cache_dirty;
      int v1060 = (4 + ((((int)((unsigned int)((int)((unsigned int)v710 >> 2)) >> 1)) & 3) * 2)) + ((((v757 + ((~(((v759 ^ -1) | (-(v759 ^ -1))) >> 31)) & 2)) - (v761 + ((~(((v763 ^ -1) | (-(v763 ^ -1))) >> 31)) & 2))) >> 31) & 1);
      int v765 = v764[v1060];
      bool v1061 = !(v765 == 0);
      if (v1061) {
        int * v766 = v533->cache_tags;
        int v767 = v766[v1060];
        int * v768 = v533->cache_vals;
        int v1064 = ((4 + ((((int)((unsigned int)((int)((unsigned int)v710 >> 2)) >> 1)) & 3) * 2)) + ((((v757 + ((~(((v759 ^ -1) | (-(v759 ^ -1))) >> 31)) & 2)) - (v761 + ((~(((v763 ^ -1) | (-(v763 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
        int v769 = v768[v1064];
        int * v770 = v533->cache_vals;
        int v1066 = (((4 + ((((int)((unsigned int)((int)((unsigned int)v710 >> 2)) >> 1)) & 3) * 2)) + ((((v757 + ((~(((v759 ^ -1) | (-(v759 ^ -1))) >> 31)) & 2)) - (v761 + ((~(((v763 ^ -1) | (-(v763 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
        int v771 = v770[v1066];
        int * v772 = v533->mem;
        int v1068 = v767 * 2;
        v772[v1068] = v769;
        int * v774 = v533->mem;
        int v1071 = (v767 * 2) + 1;
        v774[v1071] = v771;
        ;
      } else {
        ;
      }
      int * v779 = v533->mem;
      int v1076 = ((int)((unsigned int)((int)((unsigned int)v710 >> 2)) >> 1)) * 2;
      int v780 = v779[v1076];
      int * v781 = v533->mem;
      int v1078 = (((int)((unsigned int)((int)((unsigned int)v710 >> 2)) >> 1)) * 2) + 1;
      int v782 = v781[v1078];
      int * v783 = v533->cache_vals;
      int v1080 = ((4 + ((((int)((unsigned int)((int)((unsigned int)v710 >> 2)) >> 1)) & 3) * 2)) + ((((v757 + ((~(((v759 ^ -1) | (-(v759 ^ -1))) >> 31)) & 2)) - (v761 + ((~(((v763 ^ -1) | (-(v763 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
      v783[v1080] = v780;
      int * v785 = v533->cache_vals;
      int v1083 = (((4 + ((((int)((unsigned int)((int)((unsigned int)v710 >> 2)) >> 1)) & 3) * 2)) + ((((v757 + ((~(((v759 ^ -1) | (-(v759 ^ -1))) >> 31)) & 2)) - (v761 + ((~(((v763 ^ -1) | (-(v763 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
      v785[v1083] = v782;
      int * v787 = v533->cache_tags;
      int v1086 = (int)((unsigned int)((int)((unsigned int)v710 >> 2)) >> 1);
      v787[v1060] = v1086;
      int * v789 = v533->cache_dirty;
      v789[v1060] = 0;
      int * v791 = v533->cache_age;
      v791[v1060] = 1;
      int * v793 = v533->cache_age;
      int v794 = v793[v1060];
      int * v795 = v533->cache_age;
      int v796 = v795[v1023];
      int * v797 = v533->cache_age;
      int v1094 = v796 + ((int)((unsigned int)(v796 - v794) >> 31));
      v797[v1023] = v1094;
      int * v799 = v533->cache_age;
      int v800 = v799[v1025];
      int * v801 = v533->cache_age;
      int v1097 = v800 + ((int)((unsigned int)(v800 - v794) >> 31));
      v801[v1025] = v1097;
      int * v803 = v533->cache_age;
      v803[v1060] = 0;
      v806 = v1060;
    }
    int * v807 = v533->cache_vals;
    int v1100 = v806 * 2;
    int v808 = v807[v1100];
    int * v809 = v533->cache_vals;
    int v1102 = (v806 * 2) + 1;
    int v810 = v809[v1102];
    int * v811 = v533->cache_vals;
    int v1104 = (((((int)((unsigned int)((int)((unsigned int)v710 >> 2)) >> 1)) & 1) * 2) + ((((v736 + ((~(((v738 ^ -1) | (-(v738 ^ -1))) >> 31)) & 2)) - (v740 + ((~(((v742 ^ -1) | (-(v742 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
    v811[v1104] = v808;
    int * v813 = v533->cache_vals;
    int v1107 = ((((((int)((unsigned int)((int)((unsigned int)v710 >> 2)) >> 1)) & 1) * 2) + ((((v736 + ((~(((v738 ^ -1) | (-(v738 ^ -1))) >> 31)) & 2)) - (v740 + ((~(((v742 ^ -1) | (-(v742 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
    v813[v1107] = v810;
    int * v815 = v533->cache_tags;
    int v1110 = ((((int)((unsigned int)((int)((unsigned int)v710 >> 2)) >> 1)) & 1) * 2) + ((((v736 + ((~(((v738 ^ -1) | (-(v738 ^ -1))) >> 31)) & 2)) - (v740 + ((~(((v742 ^ -1) | (-(v742 ^ -1))) >> 31)) & 2))) >> 31) & 1);
    int v1111 = (int)((unsigned int)((int)((unsigned int)v710 >> 2)) >> 1);
    v815[v1110] = v1111;
    int * v817 = v533->cache_dirty;
    v817[v1110] = 0;
    int * v819 = v533->cache_age;
    v819[v1110] = 1;
    int * v821 = v533->cache_age;
    int v822 = v821[v1110];
    int * v823 = v533->cache_age;
    int v824 = v823[v1019];
    int * v825 = v533->cache_age;
    int v1119 = v824 + ((int)((unsigned int)(v824 - v822) >> 31));
    v825[v1019] = v1119;
    int * v827 = v533->cache_age;
    int v828 = v827[v1021];
    int * v829 = v533->cache_age;
    int v1122 = v828 + ((int)((unsigned int)(v828 - v822) >> 31));
    v829[v1021] = v1122;
    int * v831 = v533->cache_age;
    v831[v1110] = 0;
    v834 = v1110;
  }
  int v1125 = (v834 * 2) + (((int)((unsigned int)v710 >> 2)) & 1);
  int v835 = v721[v1125];
  int * v836 = v533->regs;
  v836[11] = v835;
  int * v838 = v533->saved_regs;
  int * v839 = v533->regs;
  int v840 = v839[12];
  v838[12] = v840;
  int v842 = v533->timer;
  int v1132 = v842 + 1;
  v533->timer = v1132;
  int * v844 = v533->regs;
  int v845 = v844[12];
  int * v846 = v533->regs;
  int v847 = v846[11];
  int * v848 = v533->regs;
  int v1136 = v845 + v847;
  v848[12] = v1136;
  int * v850 = v533->regs;
  int v851 = v850[15];
  int * v852 = v533->regs;
  int v853 = v852[10];
  bool v1140 = (v851 ^ -2147483648) < (v853 ^ -2147483648);
  if (v1140) {
    int v854 = v533->timer;
    int v1141 = v854 + 15;
    v533->timer = v1141;
    int * v856 = v533->saved_regs;
    int v857 = v856[14];
    int * v858 = v533->regs;
    v858[14] = v857;
    int * v860 = v533->saved_regs;
    int v861 = v860[11];
    int * v862 = v533->regs;
    v862[11] = v861;
    int * v864 = v533->saved_regs;
    int v865 = v864[12];
    int * v866 = v533->regs;
    v866[12] = v865;
    struct StateT * v868 = slot_13(v533);
    ;
  } else {
    ;
  }
  return v533;
}

struct StateT * slot_13(struct StateT * v1154) {
  int v1155 = v1154->timer;
  int v1163 = v1155 + 1;
  v1154->timer = v1163;
  int * v1157 = v1154->regs;
  int v1158 = v1157[10];
  int * v1159 = v1154->regs;
  int v1167 = v1158 & 7;
  v1159[10] = v1167;
  struct StateT * v1161 = slot_14(v1154);
  return v1161;
}

struct StateT * slot_15(struct StateT * v1186) {
  int v1187 = v1186->timer;
  int v1197 = v1187 + 1;
  v1186->timer = v1197;
  int * v1189 = v1186->regs;
  int v1190 = v1189[13];
  int * v1191 = v1186->regs;
  int v1192 = v1191[10];
  int * v1193 = v1186->regs;
  int v1203 = v1190 + v1192;
  v1193[10] = v1203;
  struct StateT * v1195 = slot_16(v1186);
  return v1195;
}

struct StateT * slot_0(struct StateT * v2) {
  int v3 = v2->timer;
  int v136 = v3 + 1;
  v2->timer = v136;
  int * v5 = v2->regs;
  int v6 = v5[12];
  int * v7 = v2->cache_tags;
  int v140 = (((int)((unsigned int)((int)((unsigned int)v6 >> 2)) >> 1)) & 1) * 2;
  int v8 = v7[v140];
  int * v9 = v2->cache_tags;
  int v142 = ((((int)((unsigned int)((int)((unsigned int)v6 >> 2)) >> 1)) & 1) * 2) + 1;
  int v10 = v9[v142];
  int * v11 = v2->cache_tags;
  int v144 = 4 + ((((int)((unsigned int)((int)((unsigned int)v6 >> 2)) >> 1)) & 3) * 2);
  int v12 = v11[v144];
  int * v13 = v2->cache_tags;
  int v146 = (4 + ((((int)((unsigned int)((int)((unsigned int)v6 >> 2)) >> 1)) & 3) * 2)) + 1;
  int v14 = v13[v146];
  int v15 = v2->timer;
  int v147 = v15 + ((100 ^ (((~(((v12 ^ ((int)((unsigned int)((int)((unsigned int)v6 >> 2)) >> 1))) | (-(v12 ^ ((int)((unsigned int)((int)((unsigned int)v6 >> 2)) >> 1))))) >> 31)) | (~(((v14 ^ ((int)((unsigned int)((int)((unsigned int)v6 >> 2)) >> 1))) | (-(v14 ^ ((int)((unsigned int)((int)((unsigned int)v6 >> 2)) >> 1))))) >> 31))) & 104)) ^ (((~(((v8 ^ ((int)((unsigned int)((int)((unsigned int)v6 >> 2)) >> 1))) | (-(v8 ^ ((int)((unsigned int)((int)((unsigned int)v6 >> 2)) >> 1))))) >> 31)) | (~(((v10 ^ ((int)((unsigned int)((int)((unsigned int)v6 >> 2)) >> 1))) | (-(v10 ^ ((int)((unsigned int)((int)((unsigned int)v6 >> 2)) >> 1))))) >> 31))) & (1 ^ (100 ^ (((~(((v12 ^ ((int)((unsigned int)((int)((unsigned int)v6 >> 2)) >> 1))) | (-(v12 ^ ((int)((unsigned int)((int)((unsigned int)v6 >> 2)) >> 1))))) >> 31)) | (~(((v14 ^ ((int)((unsigned int)((int)((unsigned int)v6 >> 2)) >> 1))) | (-(v14 ^ ((int)((unsigned int)((int)((unsigned int)v6 >> 2)) >> 1))))) >> 31))) & 104)))));
  v2->timer = v147;
  int * v17 = v2->cache_vals;
  bool v148 = !(((~(((v8 ^ ((int)((unsigned int)((int)((unsigned int)v6 >> 2)) >> 1))) | (-(v8 ^ ((int)((unsigned int)((int)((unsigned int)v6 >> 2)) >> 1))))) >> 31)) | (~(((v10 ^ ((int)((unsigned int)((int)((unsigned int)v6 >> 2)) >> 1))) | (-(v10 ^ ((int)((unsigned int)((int)((unsigned int)v6 >> 2)) >> 1))))) >> 31))) == 0);
  int v130;
  if (v148) {
    int * v18 = v2->cache_age;
    int v150 = ((((int)((unsigned int)((int)((unsigned int)v6 >> 2)) >> 1)) & 1) * 2) + ((~(((v10 ^ ((int)((unsigned int)((int)((unsigned int)v6 >> 2)) >> 1))) | (-(v10 ^ ((int)((unsigned int)((int)((unsigned int)v6 >> 2)) >> 1))))) >> 31)) & 1);
    int v19 = v18[v150];
    int * v20 = v2->cache_age;
    int v21 = v20[v140];
    int * v22 = v2->cache_age;
    int v153 = v21 + ((int)((unsigned int)(v21 - v19) >> 31));
    v22[v140] = v153;
    int * v24 = v2->cache_age;
    int v25 = v24[v142];
    int * v26 = v2->cache_age;
    int v156 = v25 + ((int)((unsigned int)(v25 - v19) >> 31));
    v26[v142] = v156;
    int * v28 = v2->cache_age;
    v28[v150] = 0;
    v130 = v150;
  } else {
    int * v31 = v2->cache_age;
    int v160 = (((int)((unsigned int)((int)((unsigned int)v6 >> 2)) >> 1)) & 1) * 2;
    int v32 = v31[v160];
    int * v33 = v2->cache_tags;
    int v34 = v33[v160];
    int * v35 = v2->cache_age;
    int v36 = v35[v142];
    int * v37 = v2->cache_tags;
    int v38 = v37[v142];
    bool v164 = !(((~(((v12 ^ ((int)((unsigned int)((int)((unsigned int)v6 >> 2)) >> 1))) | (-(v12 ^ ((int)((unsigned int)((int)((unsigned int)v6 >> 2)) >> 1))))) >> 31)) | (~(((v14 ^ ((int)((unsigned int)((int)((unsigned int)v6 >> 2)) >> 1))) | (-(v14 ^ ((int)((unsigned int)((int)((unsigned int)v6 >> 2)) >> 1))))) >> 31))) == 0);
    int v102;
    if (v164) {
      int * v39 = v2->cache_age;
      int v166 = (4 + ((((int)((unsigned int)((int)((unsigned int)v6 >> 2)) >> 1)) & 3) * 2)) + ((~(((v14 ^ ((int)((unsigned int)((int)((unsigned int)v6 >> 2)) >> 1))) | (-(v14 ^ ((int)((unsigned int)((int)((unsigned int)v6 >> 2)) >> 1))))) >> 31)) & 1);
      int v40 = v39[v166];
      int * v41 = v2->cache_age;
      int v42 = v41[v144];
      int * v43 = v2->cache_age;
      int v169 = v42 + ((int)((unsigned int)(v42 - v40) >> 31));
      v43[v144] = v169;
      int * v45 = v2->cache_age;
      int v46 = v45[v146];
      int * v47 = v2->cache_age;
      int v172 = v46 + ((int)((unsigned int)(v46 - v40) >> 31));
      v47[v146] = v172;
      int * v49 = v2->cache_age;
      v49[v166] = 0;
      v102 = v166;
    } else {
      int * v52 = v2->cache_age;
      int v176 = 4 + ((((int)((unsigned int)((int)((unsigned int)v6 >> 2)) >> 1)) & 3) * 2);
      int v53 = v52[v176];
      int * v54 = v2->cache_tags;
      int v55 = v54[v176];
      int * v56 = v2->cache_age;
      int v57 = v56[v146];
      int * v58 = v2->cache_tags;
      int v59 = v58[v146];
      int * v60 = v2->cache_dirty;
      int v181 = (4 + ((((int)((unsigned int)((int)((unsigned int)v6 >> 2)) >> 1)) & 3) * 2)) + ((((v53 + ((~(((v55 ^ -1) | (-(v55 ^ -1))) >> 31)) & 2)) - (v57 + ((~(((v59 ^ -1) | (-(v59 ^ -1))) >> 31)) & 2))) >> 31) & 1);
      int v61 = v60[v181];
      bool v182 = !(v61 == 0);
      if (v182) {
        int * v62 = v2->cache_tags;
        int v63 = v62[v181];
        int * v64 = v2->cache_vals;
        int v185 = ((4 + ((((int)((unsigned int)((int)((unsigned int)v6 >> 2)) >> 1)) & 3) * 2)) + ((((v53 + ((~(((v55 ^ -1) | (-(v55 ^ -1))) >> 31)) & 2)) - (v57 + ((~(((v59 ^ -1) | (-(v59 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
        int v65 = v64[v185];
        int * v66 = v2->cache_vals;
        int v187 = (((4 + ((((int)((unsigned int)((int)((unsigned int)v6 >> 2)) >> 1)) & 3) * 2)) + ((((v53 + ((~(((v55 ^ -1) | (-(v55 ^ -1))) >> 31)) & 2)) - (v57 + ((~(((v59 ^ -1) | (-(v59 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
        int v67 = v66[v187];
        int * v68 = v2->mem;
        int v189 = v63 * 2;
        v68[v189] = v65;
        int * v70 = v2->mem;
        int v192 = (v63 * 2) + 1;
        v70[v192] = v67;
        ;
      } else {
        ;
      }
      int * v75 = v2->mem;
      int v197 = ((int)((unsigned int)((int)((unsigned int)v6 >> 2)) >> 1)) * 2;
      int v76 = v75[v197];
      int * v77 = v2->mem;
      int v199 = (((int)((unsigned int)((int)((unsigned int)v6 >> 2)) >> 1)) * 2) + 1;
      int v78 = v77[v199];
      int * v79 = v2->cache_vals;
      int v201 = ((4 + ((((int)((unsigned int)((int)((unsigned int)v6 >> 2)) >> 1)) & 3) * 2)) + ((((v53 + ((~(((v55 ^ -1) | (-(v55 ^ -1))) >> 31)) & 2)) - (v57 + ((~(((v59 ^ -1) | (-(v59 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
      v79[v201] = v76;
      int * v81 = v2->cache_vals;
      int v204 = (((4 + ((((int)((unsigned int)((int)((unsigned int)v6 >> 2)) >> 1)) & 3) * 2)) + ((((v53 + ((~(((v55 ^ -1) | (-(v55 ^ -1))) >> 31)) & 2)) - (v57 + ((~(((v59 ^ -1) | (-(v59 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
      v81[v204] = v78;
      int * v83 = v2->cache_tags;
      int v207 = (int)((unsigned int)((int)((unsigned int)v6 >> 2)) >> 1);
      v83[v181] = v207;
      int * v85 = v2->cache_dirty;
      v85[v181] = 0;
      int * v87 = v2->cache_age;
      v87[v181] = 1;
      int * v89 = v2->cache_age;
      int v90 = v89[v181];
      int * v91 = v2->cache_age;
      int v92 = v91[v144];
      int * v93 = v2->cache_age;
      int v215 = v92 + ((int)((unsigned int)(v92 - v90) >> 31));
      v93[v144] = v215;
      int * v95 = v2->cache_age;
      int v96 = v95[v146];
      int * v97 = v2->cache_age;
      int v218 = v96 + ((int)((unsigned int)(v96 - v90) >> 31));
      v97[v146] = v218;
      int * v99 = v2->cache_age;
      v99[v181] = 0;
      v102 = v181;
    }
    int * v103 = v2->cache_vals;
    int v221 = v102 * 2;
    int v104 = v103[v221];
    int * v105 = v2->cache_vals;
    int v223 = (v102 * 2) + 1;
    int v106 = v105[v223];
    int * v107 = v2->cache_vals;
    int v225 = (((((int)((unsigned int)((int)((unsigned int)v6 >> 2)) >> 1)) & 1) * 2) + ((((v32 + ((~(((v34 ^ -1) | (-(v34 ^ -1))) >> 31)) & 2)) - (v36 + ((~(((v38 ^ -1) | (-(v38 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
    v107[v225] = v104;
    int * v109 = v2->cache_vals;
    int v228 = ((((((int)((unsigned int)((int)((unsigned int)v6 >> 2)) >> 1)) & 1) * 2) + ((((v32 + ((~(((v34 ^ -1) | (-(v34 ^ -1))) >> 31)) & 2)) - (v36 + ((~(((v38 ^ -1) | (-(v38 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
    v109[v228] = v106;
    int * v111 = v2->cache_tags;
    int v231 = ((((int)((unsigned int)((int)((unsigned int)v6 >> 2)) >> 1)) & 1) * 2) + ((((v32 + ((~(((v34 ^ -1) | (-(v34 ^ -1))) >> 31)) & 2)) - (v36 + ((~(((v38 ^ -1) | (-(v38 ^ -1))) >> 31)) & 2))) >> 31) & 1);
    int v232 = (int)((unsigned int)((int)((unsigned int)v6 >> 2)) >> 1);
    v111[v231] = v232;
    int * v113 = v2->cache_dirty;
    v113[v231] = 0;
    int * v115 = v2->cache_age;
    v115[v231] = 1;
    int * v117 = v2->cache_age;
    int v118 = v117[v231];
    int * v119 = v2->cache_age;
    int v120 = v119[v140];
    int * v121 = v2->cache_age;
    int v240 = v120 + ((int)((unsigned int)(v120 - v118) >> 31));
    v121[v140] = v240;
    int * v123 = v2->cache_age;
    int v124 = v123[v142];
    int * v125 = v2->cache_age;
    int v243 = v124 + ((int)((unsigned int)(v124 - v118) >> 31));
    v125[v142] = v243;
    int * v127 = v2->cache_age;
    v127[v231] = 0;
    v130 = v231;
  }
  int v246 = (v130 * 2) + (((int)((unsigned int)v6 >> 2)) & 1);
  int v131 = v17[v246];
  int * v132 = v2->regs;
  v132[12] = v131;
  struct StateT * v134 = slot_1(v2);
  return v134;
}



/*****************************************
End of C Generated Code
*******************************************/

void init(struct StateT *s) {
  for (int i=0; i<NUM_REGS; i++) {
    s->regs[i] = 0;
    s->saved_regs[i] = 0;
  }
  s->regs[2] = 4 * MEM_SIZE;
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
  
  // a10, public: one draw, written into both states
  int a10 = bounded(0, 23);
  s1.regs[10] = a10;
  s2.regs[10] = a10;
  // a11, 16 words read by the callee: the address is public
  s1.regs[11] = 0;
  s2.regs[11] = 0;
  // its contents, public: the same draw in both states
  for (int i=0; i<16; i++) {
    int v = bounded(0, 20);
    s1.mem[0 + i] = v;
    s2.mem[0 + i] = v;
  }
  // a12, 8 words read by the callee: the address is public
  s1.regs[12] = 64;
  s2.regs[12] = 64;
  // a13, 8 words written by the callee: the address is public
  s1.regs[13] = 96;
  s2.regs[13] = 96;
  
  // a12's contents, secret: a different draw in each state
  for (int i=0; i<8; i++) {
    s1.mem[16 + i] = bounded(0, 20);
    s2.mem[16 + i] = bounded(0, 20);
  }
  struct StateT *s1_ = snippet(&s1);
  struct StateT *s2_ = snippet(&s2);
  koika_assert(s1_->timer==s2_->timer, "timing leak");
  return 0;
}