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
struct StateT2 * slot_1(struct StateT2 * v393);
struct StateT2 * slot_6(struct StateT2 * v1284);
struct StateT2 * slot_5(struct StateT2 * v894);
struct StateT2 * slot_4(struct StateT2 * v511);
struct StateT2 * slot_2(struct StateT2 * v433);
struct StateT2 * slot_7(struct StateT2 * v1702);
struct StateT2 * slot_3(struct StateT2 * v472);
struct StateT2 * slot_0(struct StateT2 * v2);
struct StateT2 * snippet(struct StateT2 * v0) {
  struct StateT2 * v1 = slot_0(v0);
  return v1;
}

struct StateT2 * slot_1(struct StateT2 * v393) {
  struct StateT * v394 = v393->a;
  int v395 = v394->timer;
  struct StateT * v396 = v393->b;
  int v397 = v396->timer;
  bool v418 = v395 == v397;
  squared_assert(v418);
  squared_assume(v418);
  struct StateT * v400 = v393->a;
  int v401 = v400->timer;
  int v420 = v401 + 1;
  v400->timer = v420;
  struct StateT * v403 = v393->b;
  int v404 = v403->timer;
  int v422 = v404 + 1;
  v403->timer = v422;
  struct StateT * v406 = v393->a;
  int * v407 = v406->regs;
  int v408 = v407[5];
  int v427 = v408 & 1;
  v407[6] = v427;
  struct StateT * v410 = v393->b;
  int * v411 = v410->regs;
  int v412 = v411[5];
  int v430 = v412 & 1;
  v411[6] = v430;
  struct StateT2 * v414 = slot_2(v393);
  return v414;
}

struct StateT2 * slot_6(struct StateT2 * v1284) {
  struct StateT * v1285 = v1284->a;
  int v1286 = v1285->timer;
  struct StateT * v1287 = v1284->b;
  int v1288 = v1287->timer;
  bool v1515 = v1286 == v1288;
  squared_assert(v1515);
  squared_assume(v1515);
  struct StateT * v1291 = v1284->a;
  int v1292 = v1291->timer;
  int v1517 = v1292 + 1;
  v1291->timer = v1517;
  struct StateT * v1294 = v1284->b;
  int v1295 = v1294->timer;
  int v1519 = v1295 + 1;
  v1294->timer = v1519;
  struct StateT * v1297 = v1284->a;
  int * v1298 = v1297->regs;
  int v1299 = v1298[6];
  int * v1300 = v1297->cache_tags;
  int v1524 = (((int)((unsigned int)((int)((unsigned int)v1299 >> 2)) >> 1)) & 1) * 2;
  int v1301 = v1300[v1524];
  int v1525 = ((((int)((unsigned int)((int)((unsigned int)v1299 >> 2)) >> 1)) & 1) * 2) + 1;
  int v1302 = v1300[v1525];
  int v1526 = 4 + ((((int)((unsigned int)((int)((unsigned int)v1299 >> 2)) >> 1)) & 3) * 2);
  int v1303 = v1300[v1526];
  int v1527 = (4 + ((((int)((unsigned int)((int)((unsigned int)v1299 >> 2)) >> 1)) & 3) * 2)) + 1;
  int v1304 = v1300[v1527];
  int v1305 = v1297->timer;
  int v1528 = v1305 + ((100 ^ (((~(((v1303 ^ ((int)((unsigned int)((int)((unsigned int)v1299 >> 2)) >> 1))) | (-(v1303 ^ ((int)((unsigned int)((int)((unsigned int)v1299 >> 2)) >> 1))))) >> 31)) | (~(((v1304 ^ ((int)((unsigned int)((int)((unsigned int)v1299 >> 2)) >> 1))) | (-(v1304 ^ ((int)((unsigned int)((int)((unsigned int)v1299 >> 2)) >> 1))))) >> 31))) & 104)) ^ (((~(((v1301 ^ ((int)((unsigned int)((int)((unsigned int)v1299 >> 2)) >> 1))) | (-(v1301 ^ ((int)((unsigned int)((int)((unsigned int)v1299 >> 2)) >> 1))))) >> 31)) | (~(((v1302 ^ ((int)((unsigned int)((int)((unsigned int)v1299 >> 2)) >> 1))) | (-(v1302 ^ ((int)((unsigned int)((int)((unsigned int)v1299 >> 2)) >> 1))))) >> 31))) & (1 ^ (100 ^ (((~(((v1303 ^ ((int)((unsigned int)((int)((unsigned int)v1299 >> 2)) >> 1))) | (-(v1303 ^ ((int)((unsigned int)((int)((unsigned int)v1299 >> 2)) >> 1))))) >> 31)) | (~(((v1304 ^ ((int)((unsigned int)((int)((unsigned int)v1299 >> 2)) >> 1))) | (-(v1304 ^ ((int)((unsigned int)((int)((unsigned int)v1299 >> 2)) >> 1))))) >> 31))) & 104)))));
  v1297->timer = v1528;
  int * v1307 = v1297->cache_vals;
  bool v1529 = !(((~(((v1301 ^ ((int)((unsigned int)((int)((unsigned int)v1299 >> 2)) >> 1))) | (-(v1301 ^ ((int)((unsigned int)((int)((unsigned int)v1299 >> 2)) >> 1))))) >> 31)) | (~(((v1302 ^ ((int)((unsigned int)((int)((unsigned int)v1299 >> 2)) >> 1))) | (-(v1302 ^ ((int)((unsigned int)((int)((unsigned int)v1299 >> 2)) >> 1))))) >> 31))) == 0);
  int v1400;
  if (v1529) {
    int * v1308 = v1297->cache_age;
    int v1531 = ((((int)((unsigned int)((int)((unsigned int)v1299 >> 2)) >> 1)) & 1) * 2) + ((~(((v1302 ^ ((int)((unsigned int)((int)((unsigned int)v1299 >> 2)) >> 1))) | (-(v1302 ^ ((int)((unsigned int)((int)((unsigned int)v1299 >> 2)) >> 1))))) >> 31)) & 1);
    int v1309 = v1308[v1531];
    int v1310 = v1308[v1524];
    int v1532 = v1310 + ((int)((unsigned int)(v1310 - v1309) >> 31));
    v1308[v1524] = v1532;
    int * v1312 = v1297->cache_age;
    int v1313 = v1312[v1525];
    int v1534 = v1313 + ((int)((unsigned int)(v1313 - v1309) >> 31));
    v1312[v1525] = v1534;
    int * v1315 = v1297->cache_age;
    v1315[v1531] = 0;
    v1400 = v1531;
  } else {
    int * v1318 = v1297->cache_age;
    int v1538 = (((int)((unsigned int)((int)((unsigned int)v1299 >> 2)) >> 1)) & 1) * 2;
    int v1319 = v1318[v1538];
    int * v1320 = v1297->cache_tags;
    int v1321 = v1320[v1538];
    int v1322 = v1318[v1525];
    int v1323 = v1320[v1525];
    bool v1540 = !(((~(((v1303 ^ ((int)((unsigned int)((int)((unsigned int)v1299 >> 2)) >> 1))) | (-(v1303 ^ ((int)((unsigned int)((int)((unsigned int)v1299 >> 2)) >> 1))))) >> 31)) | (~(((v1304 ^ ((int)((unsigned int)((int)((unsigned int)v1299 >> 2)) >> 1))) | (-(v1304 ^ ((int)((unsigned int)((int)((unsigned int)v1299 >> 2)) >> 1))))) >> 31))) == 0);
    int v1377;
    if (v1540) {
      int * v1324 = v1297->cache_age;
      int v1542 = (4 + ((((int)((unsigned int)((int)((unsigned int)v1299 >> 2)) >> 1)) & 3) * 2)) + ((~(((v1304 ^ ((int)((unsigned int)((int)((unsigned int)v1299 >> 2)) >> 1))) | (-(v1304 ^ ((int)((unsigned int)((int)((unsigned int)v1299 >> 2)) >> 1))))) >> 31)) & 1);
      int v1325 = v1324[v1542];
      int v1326 = v1324[v1526];
      int v1543 = v1326 + ((int)((unsigned int)(v1326 - v1325) >> 31));
      v1324[v1526] = v1543;
      int * v1328 = v1297->cache_age;
      int v1329 = v1328[v1527];
      int v1545 = v1329 + ((int)((unsigned int)(v1329 - v1325) >> 31));
      v1328[v1527] = v1545;
      int * v1331 = v1297->cache_age;
      v1331[v1542] = 0;
      v1377 = v1542;
    } else {
      int * v1334 = v1297->cache_age;
      int v1549 = 4 + ((((int)((unsigned int)((int)((unsigned int)v1299 >> 2)) >> 1)) & 3) * 2);
      int v1335 = v1334[v1549];
      int * v1336 = v1297->cache_tags;
      int v1337 = v1336[v1549];
      int v1338 = v1334[v1527];
      int v1339 = v1336[v1527];
      int * v1340 = v1297->cache_dirty;
      int v1552 = (4 + ((((int)((unsigned int)((int)((unsigned int)v1299 >> 2)) >> 1)) & 3) * 2)) + ((((v1335 + ((~(((v1337 ^ -1) | (-(v1337 ^ -1))) >> 31)) & 2)) - (v1338 + ((~(((v1339 ^ -1) | (-(v1339 ^ -1))) >> 31)) & 2))) >> 31) & 1);
      int v1341 = v1340[v1552];
      bool v1553 = !(v1341 == 0);
      if (v1553) {
        int * v1342 = v1297->cache_tags;
        int v1343 = v1342[v1552];
        int * v1344 = v1297->cache_vals;
        int v1556 = ((4 + ((((int)((unsigned int)((int)((unsigned int)v1299 >> 2)) >> 1)) & 3) * 2)) + ((((v1335 + ((~(((v1337 ^ -1) | (-(v1337 ^ -1))) >> 31)) & 2)) - (v1338 + ((~(((v1339 ^ -1) | (-(v1339 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
        int v1345 = v1344[v1556];
        int v1557 = (((4 + ((((int)((unsigned int)((int)((unsigned int)v1299 >> 2)) >> 1)) & 3) * 2)) + ((((v1335 + ((~(((v1337 ^ -1) | (-(v1337 ^ -1))) >> 31)) & 2)) - (v1338 + ((~(((v1339 ^ -1) | (-(v1339 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
        int v1346 = v1344[v1557];
        int * v1347 = v1297->mem;
        int v1559 = v1343 * 2;
        v1347[v1559] = v1345;
        int * v1349 = v1297->mem;
        int v1562 = (v1343 * 2) + 1;
        v1349[v1562] = v1346;
        ;
      } else {
        ;
      }
      int * v1354 = v1297->mem;
      int v1567 = ((int)((unsigned int)((int)((unsigned int)v1299 >> 2)) >> 1)) * 2;
      int v1355 = v1354[v1567];
      int v1568 = (((int)((unsigned int)((int)((unsigned int)v1299 >> 2)) >> 1)) * 2) + 1;
      int v1356 = v1354[v1568];
      int * v1357 = v1297->cache_vals;
      int v1570 = ((4 + ((((int)((unsigned int)((int)((unsigned int)v1299 >> 2)) >> 1)) & 3) * 2)) + ((((v1335 + ((~(((v1337 ^ -1) | (-(v1337 ^ -1))) >> 31)) & 2)) - (v1338 + ((~(((v1339 ^ -1) | (-(v1339 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
      v1357[v1570] = v1355;
      int * v1359 = v1297->cache_vals;
      int v1573 = (((4 + ((((int)((unsigned int)((int)((unsigned int)v1299 >> 2)) >> 1)) & 3) * 2)) + ((((v1335 + ((~(((v1337 ^ -1) | (-(v1337 ^ -1))) >> 31)) & 2)) - (v1338 + ((~(((v1339 ^ -1) | (-(v1339 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
      v1359[v1573] = v1356;
      int * v1361 = v1297->cache_tags;
      int v1576 = (int)((unsigned int)((int)((unsigned int)v1299 >> 2)) >> 1);
      v1361[v1552] = v1576;
      int * v1363 = v1297->cache_dirty;
      v1363[v1552] = 0;
      int * v1365 = v1297->cache_age;
      v1365[v1552] = 1;
      int * v1367 = v1297->cache_age;
      int v1368 = v1367[v1552];
      int v1369 = v1367[v1526];
      int v1582 = v1369 + ((int)((unsigned int)(v1369 - v1368) >> 31));
      v1367[v1526] = v1582;
      int * v1371 = v1297->cache_age;
      int v1372 = v1371[v1527];
      int v1584 = v1372 + ((int)((unsigned int)(v1372 - v1368) >> 31));
      v1371[v1527] = v1584;
      int * v1374 = v1297->cache_age;
      v1374[v1552] = 0;
      v1377 = v1552;
    }
    int * v1378 = v1297->cache_vals;
    int v1587 = v1377 * 2;
    int v1379 = v1378[v1587];
    int v1588 = (v1377 * 2) + 1;
    int v1380 = v1378[v1588];
    int v1589 = (((((int)((unsigned int)((int)((unsigned int)v1299 >> 2)) >> 1)) & 1) * 2) + ((((v1319 + ((~(((v1321 ^ -1) | (-(v1321 ^ -1))) >> 31)) & 2)) - (v1322 + ((~(((v1323 ^ -1) | (-(v1323 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
    v1378[v1589] = v1379;
    int * v1382 = v1297->cache_vals;
    int v1592 = ((((((int)((unsigned int)((int)((unsigned int)v1299 >> 2)) >> 1)) & 1) * 2) + ((((v1319 + ((~(((v1321 ^ -1) | (-(v1321 ^ -1))) >> 31)) & 2)) - (v1322 + ((~(((v1323 ^ -1) | (-(v1323 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
    v1382[v1592] = v1380;
    int * v1384 = v1297->cache_tags;
    int v1595 = ((((int)((unsigned int)((int)((unsigned int)v1299 >> 2)) >> 1)) & 1) * 2) + ((((v1319 + ((~(((v1321 ^ -1) | (-(v1321 ^ -1))) >> 31)) & 2)) - (v1322 + ((~(((v1323 ^ -1) | (-(v1323 ^ -1))) >> 31)) & 2))) >> 31) & 1);
    int v1596 = (int)((unsigned int)((int)((unsigned int)v1299 >> 2)) >> 1);
    v1384[v1595] = v1596;
    int * v1386 = v1297->cache_dirty;
    v1386[v1595] = 0;
    int * v1388 = v1297->cache_age;
    v1388[v1595] = 1;
    int * v1390 = v1297->cache_age;
    int v1391 = v1390[v1595];
    int v1392 = v1390[v1524];
    int v1602 = v1392 + ((int)((unsigned int)(v1392 - v1391) >> 31));
    v1390[v1524] = v1602;
    int * v1394 = v1297->cache_age;
    int v1395 = v1394[v1525];
    int v1604 = v1395 + ((int)((unsigned int)(v1395 - v1391) >> 31));
    v1394[v1525] = v1604;
    int * v1397 = v1297->cache_age;
    v1397[v1595] = 0;
    v1400 = v1595;
  }
  int v1607 = (v1400 * 2) + (((int)((unsigned int)v1299 >> 2)) & 1);
  int v1401 = v1307[v1607];
  int * v1402 = v1297->regs;
  v1402[9] = v1401;
  struct StateT * v1404 = v1284->b;
  int * v1405 = v1404->regs;
  int v1406 = v1405[6];
  int * v1407 = v1404->cache_tags;
  int v1614 = (((int)((unsigned int)((int)((unsigned int)v1406 >> 2)) >> 1)) & 1) * 2;
  int v1408 = v1407[v1614];
  int v1615 = ((((int)((unsigned int)((int)((unsigned int)v1406 >> 2)) >> 1)) & 1) * 2) + 1;
  int v1409 = v1407[v1615];
  int v1616 = 4 + ((((int)((unsigned int)((int)((unsigned int)v1406 >> 2)) >> 1)) & 3) * 2);
  int v1410 = v1407[v1616];
  int v1617 = (4 + ((((int)((unsigned int)((int)((unsigned int)v1406 >> 2)) >> 1)) & 3) * 2)) + 1;
  int v1411 = v1407[v1617];
  int v1412 = v1404->timer;
  int v1618 = v1412 + ((100 ^ (((~(((v1410 ^ ((int)((unsigned int)((int)((unsigned int)v1406 >> 2)) >> 1))) | (-(v1410 ^ ((int)((unsigned int)((int)((unsigned int)v1406 >> 2)) >> 1))))) >> 31)) | (~(((v1411 ^ ((int)((unsigned int)((int)((unsigned int)v1406 >> 2)) >> 1))) | (-(v1411 ^ ((int)((unsigned int)((int)((unsigned int)v1406 >> 2)) >> 1))))) >> 31))) & 104)) ^ (((~(((v1408 ^ ((int)((unsigned int)((int)((unsigned int)v1406 >> 2)) >> 1))) | (-(v1408 ^ ((int)((unsigned int)((int)((unsigned int)v1406 >> 2)) >> 1))))) >> 31)) | (~(((v1409 ^ ((int)((unsigned int)((int)((unsigned int)v1406 >> 2)) >> 1))) | (-(v1409 ^ ((int)((unsigned int)((int)((unsigned int)v1406 >> 2)) >> 1))))) >> 31))) & (1 ^ (100 ^ (((~(((v1410 ^ ((int)((unsigned int)((int)((unsigned int)v1406 >> 2)) >> 1))) | (-(v1410 ^ ((int)((unsigned int)((int)((unsigned int)v1406 >> 2)) >> 1))))) >> 31)) | (~(((v1411 ^ ((int)((unsigned int)((int)((unsigned int)v1406 >> 2)) >> 1))) | (-(v1411 ^ ((int)((unsigned int)((int)((unsigned int)v1406 >> 2)) >> 1))))) >> 31))) & 104)))));
  v1404->timer = v1618;
  int * v1414 = v1404->cache_vals;
  bool v1619 = !(((~(((v1408 ^ ((int)((unsigned int)((int)((unsigned int)v1406 >> 2)) >> 1))) | (-(v1408 ^ ((int)((unsigned int)((int)((unsigned int)v1406 >> 2)) >> 1))))) >> 31)) | (~(((v1409 ^ ((int)((unsigned int)((int)((unsigned int)v1406 >> 2)) >> 1))) | (-(v1409 ^ ((int)((unsigned int)((int)((unsigned int)v1406 >> 2)) >> 1))))) >> 31))) == 0);
  int v1507;
  if (v1619) {
    int * v1415 = v1404->cache_age;
    int v1621 = ((((int)((unsigned int)((int)((unsigned int)v1406 >> 2)) >> 1)) & 1) * 2) + ((~(((v1409 ^ ((int)((unsigned int)((int)((unsigned int)v1406 >> 2)) >> 1))) | (-(v1409 ^ ((int)((unsigned int)((int)((unsigned int)v1406 >> 2)) >> 1))))) >> 31)) & 1);
    int v1416 = v1415[v1621];
    int v1417 = v1415[v1614];
    int v1622 = v1417 + ((int)((unsigned int)(v1417 - v1416) >> 31));
    v1415[v1614] = v1622;
    int * v1419 = v1404->cache_age;
    int v1420 = v1419[v1615];
    int v1624 = v1420 + ((int)((unsigned int)(v1420 - v1416) >> 31));
    v1419[v1615] = v1624;
    int * v1422 = v1404->cache_age;
    v1422[v1621] = 0;
    v1507 = v1621;
  } else {
    int * v1425 = v1404->cache_age;
    int v1628 = (((int)((unsigned int)((int)((unsigned int)v1406 >> 2)) >> 1)) & 1) * 2;
    int v1426 = v1425[v1628];
    int * v1427 = v1404->cache_tags;
    int v1428 = v1427[v1628];
    int v1429 = v1425[v1615];
    int v1430 = v1427[v1615];
    bool v1630 = !(((~(((v1410 ^ ((int)((unsigned int)((int)((unsigned int)v1406 >> 2)) >> 1))) | (-(v1410 ^ ((int)((unsigned int)((int)((unsigned int)v1406 >> 2)) >> 1))))) >> 31)) | (~(((v1411 ^ ((int)((unsigned int)((int)((unsigned int)v1406 >> 2)) >> 1))) | (-(v1411 ^ ((int)((unsigned int)((int)((unsigned int)v1406 >> 2)) >> 1))))) >> 31))) == 0);
    int v1484;
    if (v1630) {
      int * v1431 = v1404->cache_age;
      int v1632 = (4 + ((((int)((unsigned int)((int)((unsigned int)v1406 >> 2)) >> 1)) & 3) * 2)) + ((~(((v1411 ^ ((int)((unsigned int)((int)((unsigned int)v1406 >> 2)) >> 1))) | (-(v1411 ^ ((int)((unsigned int)((int)((unsigned int)v1406 >> 2)) >> 1))))) >> 31)) & 1);
      int v1432 = v1431[v1632];
      int v1433 = v1431[v1616];
      int v1633 = v1433 + ((int)((unsigned int)(v1433 - v1432) >> 31));
      v1431[v1616] = v1633;
      int * v1435 = v1404->cache_age;
      int v1436 = v1435[v1617];
      int v1635 = v1436 + ((int)((unsigned int)(v1436 - v1432) >> 31));
      v1435[v1617] = v1635;
      int * v1438 = v1404->cache_age;
      v1438[v1632] = 0;
      v1484 = v1632;
    } else {
      int * v1441 = v1404->cache_age;
      int v1639 = 4 + ((((int)((unsigned int)((int)((unsigned int)v1406 >> 2)) >> 1)) & 3) * 2);
      int v1442 = v1441[v1639];
      int * v1443 = v1404->cache_tags;
      int v1444 = v1443[v1639];
      int v1445 = v1441[v1617];
      int v1446 = v1443[v1617];
      int * v1447 = v1404->cache_dirty;
      int v1642 = (4 + ((((int)((unsigned int)((int)((unsigned int)v1406 >> 2)) >> 1)) & 3) * 2)) + ((((v1442 + ((~(((v1444 ^ -1) | (-(v1444 ^ -1))) >> 31)) & 2)) - (v1445 + ((~(((v1446 ^ -1) | (-(v1446 ^ -1))) >> 31)) & 2))) >> 31) & 1);
      int v1448 = v1447[v1642];
      bool v1643 = !(v1448 == 0);
      if (v1643) {
        int * v1449 = v1404->cache_tags;
        int v1450 = v1449[v1642];
        int * v1451 = v1404->cache_vals;
        int v1646 = ((4 + ((((int)((unsigned int)((int)((unsigned int)v1406 >> 2)) >> 1)) & 3) * 2)) + ((((v1442 + ((~(((v1444 ^ -1) | (-(v1444 ^ -1))) >> 31)) & 2)) - (v1445 + ((~(((v1446 ^ -1) | (-(v1446 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
        int v1452 = v1451[v1646];
        int v1647 = (((4 + ((((int)((unsigned int)((int)((unsigned int)v1406 >> 2)) >> 1)) & 3) * 2)) + ((((v1442 + ((~(((v1444 ^ -1) | (-(v1444 ^ -1))) >> 31)) & 2)) - (v1445 + ((~(((v1446 ^ -1) | (-(v1446 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
        int v1453 = v1451[v1647];
        int * v1454 = v1404->mem;
        int v1649 = v1450 * 2;
        v1454[v1649] = v1452;
        int * v1456 = v1404->mem;
        int v1652 = (v1450 * 2) + 1;
        v1456[v1652] = v1453;
        ;
      } else {
        ;
      }
      int * v1461 = v1404->mem;
      int v1657 = ((int)((unsigned int)((int)((unsigned int)v1406 >> 2)) >> 1)) * 2;
      int v1462 = v1461[v1657];
      int v1658 = (((int)((unsigned int)((int)((unsigned int)v1406 >> 2)) >> 1)) * 2) + 1;
      int v1463 = v1461[v1658];
      int * v1464 = v1404->cache_vals;
      int v1660 = ((4 + ((((int)((unsigned int)((int)((unsigned int)v1406 >> 2)) >> 1)) & 3) * 2)) + ((((v1442 + ((~(((v1444 ^ -1) | (-(v1444 ^ -1))) >> 31)) & 2)) - (v1445 + ((~(((v1446 ^ -1) | (-(v1446 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
      v1464[v1660] = v1462;
      int * v1466 = v1404->cache_vals;
      int v1663 = (((4 + ((((int)((unsigned int)((int)((unsigned int)v1406 >> 2)) >> 1)) & 3) * 2)) + ((((v1442 + ((~(((v1444 ^ -1) | (-(v1444 ^ -1))) >> 31)) & 2)) - (v1445 + ((~(((v1446 ^ -1) | (-(v1446 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
      v1466[v1663] = v1463;
      int * v1468 = v1404->cache_tags;
      int v1666 = (int)((unsigned int)((int)((unsigned int)v1406 >> 2)) >> 1);
      v1468[v1642] = v1666;
      int * v1470 = v1404->cache_dirty;
      v1470[v1642] = 0;
      int * v1472 = v1404->cache_age;
      v1472[v1642] = 1;
      int * v1474 = v1404->cache_age;
      int v1475 = v1474[v1642];
      int v1476 = v1474[v1616];
      int v1672 = v1476 + ((int)((unsigned int)(v1476 - v1475) >> 31));
      v1474[v1616] = v1672;
      int * v1478 = v1404->cache_age;
      int v1479 = v1478[v1617];
      int v1674 = v1479 + ((int)((unsigned int)(v1479 - v1475) >> 31));
      v1478[v1617] = v1674;
      int * v1481 = v1404->cache_age;
      v1481[v1642] = 0;
      v1484 = v1642;
    }
    int * v1485 = v1404->cache_vals;
    int v1677 = v1484 * 2;
    int v1486 = v1485[v1677];
    int v1678 = (v1484 * 2) + 1;
    int v1487 = v1485[v1678];
    int v1679 = (((((int)((unsigned int)((int)((unsigned int)v1406 >> 2)) >> 1)) & 1) * 2) + ((((v1426 + ((~(((v1428 ^ -1) | (-(v1428 ^ -1))) >> 31)) & 2)) - (v1429 + ((~(((v1430 ^ -1) | (-(v1430 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
    v1485[v1679] = v1486;
    int * v1489 = v1404->cache_vals;
    int v1682 = ((((((int)((unsigned int)((int)((unsigned int)v1406 >> 2)) >> 1)) & 1) * 2) + ((((v1426 + ((~(((v1428 ^ -1) | (-(v1428 ^ -1))) >> 31)) & 2)) - (v1429 + ((~(((v1430 ^ -1) | (-(v1430 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
    v1489[v1682] = v1487;
    int * v1491 = v1404->cache_tags;
    int v1685 = ((((int)((unsigned int)((int)((unsigned int)v1406 >> 2)) >> 1)) & 1) * 2) + ((((v1426 + ((~(((v1428 ^ -1) | (-(v1428 ^ -1))) >> 31)) & 2)) - (v1429 + ((~(((v1430 ^ -1) | (-(v1430 ^ -1))) >> 31)) & 2))) >> 31) & 1);
    int v1686 = (int)((unsigned int)((int)((unsigned int)v1406 >> 2)) >> 1);
    v1491[v1685] = v1686;
    int * v1493 = v1404->cache_dirty;
    v1493[v1685] = 0;
    int * v1495 = v1404->cache_age;
    v1495[v1685] = 1;
    int * v1497 = v1404->cache_age;
    int v1498 = v1497[v1685];
    int v1499 = v1497[v1614];
    int v1692 = v1499 + ((int)((unsigned int)(v1499 - v1498) >> 31));
    v1497[v1614] = v1692;
    int * v1501 = v1404->cache_age;
    int v1502 = v1501[v1615];
    int v1694 = v1502 + ((int)((unsigned int)(v1502 - v1498) >> 31));
    v1501[v1615] = v1694;
    int * v1504 = v1404->cache_age;
    v1504[v1685] = 0;
    v1507 = v1685;
  }
  int v1697 = (v1507 * 2) + (((int)((unsigned int)v1406 >> 2)) & 1);
  int v1508 = v1414[v1697];
  int * v1509 = v1404->regs;
  v1509[9] = v1508;
  struct StateT2 * v1511 = slot_7(v1284);
  return v1511;
}

struct StateT2 * slot_5(struct StateT2 * v894) {
  struct StateT * v895 = v894->a;
  int v896 = v895->timer;
  struct StateT * v897 = v894->b;
  int v898 = v897->timer;
  bool v1121 = v896 == v898;
  squared_assert(v1121);
  squared_assume(v1121);
  struct StateT * v901 = v894->a;
  int v902 = v901->timer;
  int v1123 = v902 + 1;
  v901->timer = v1123;
  struct StateT * v904 = v894->b;
  int v905 = v904->timer;
  int v1125 = v905 + 1;
  v904->timer = v1125;
  struct StateT * v907 = v894->a;
  int * v908 = v907->cache_tags;
  int v909 = v908[0];
  int v910 = v908[1];
  int v911 = v908[8];
  int v912 = v908[9];
  int v913 = v907->timer;
  int v1132 = v913 + ((100 ^ (((~(((v911 ^ 2) | (-(v911 ^ 2))) >> 31)) | (~(((v912 ^ 2) | (-(v912 ^ 2))) >> 31))) & 104)) ^ (((~(((v909 ^ 2) | (-(v909 ^ 2))) >> 31)) | (~(((v910 ^ 2) | (-(v910 ^ 2))) >> 31))) & (1 ^ (100 ^ (((~(((v911 ^ 2) | (-(v911 ^ 2))) >> 31)) | (~(((v912 ^ 2) | (-(v912 ^ 2))) >> 31))) & 104)))));
  v907->timer = v1132;
  int * v915 = v907->cache_vals;
  bool v1133 = !(((~(((v909 ^ 2) | (-(v909 ^ 2))) >> 31)) | (~(((v910 ^ 2) | (-(v910 ^ 2))) >> 31))) == 0);
  int v1008;
  if (v1133) {
    int * v916 = v907->cache_age;
    int v1135 = (~(((v910 ^ 2) | (-(v910 ^ 2))) >> 31)) & 1;
    int v917 = v916[v1135];
    int v918 = v916[0];
    int v1136 = v918 + ((int)((unsigned int)(v918 - v917) >> 31));
    v916[0] = v1136;
    int * v920 = v907->cache_age;
    int v921 = v920[1];
    int v1138 = v921 + ((int)((unsigned int)(v921 - v917) >> 31));
    v920[1] = v1138;
    int * v923 = v907->cache_age;
    v923[v1135] = 0;
    v1008 = v1135;
  } else {
    int * v926 = v907->cache_age;
    int v927 = v926[0];
    int * v928 = v907->cache_tags;
    int v929 = v928[0];
    int v930 = v926[1];
    int v931 = v928[1];
    bool v1142 = !(((~(((v911 ^ 2) | (-(v911 ^ 2))) >> 31)) | (~(((v912 ^ 2) | (-(v912 ^ 2))) >> 31))) == 0);
    int v985;
    if (v1142) {
      int * v932 = v907->cache_age;
      int v1144 = 8 + ((~(((v912 ^ 2) | (-(v912 ^ 2))) >> 31)) & 1);
      int v933 = v932[v1144];
      int v934 = v932[8];
      int v1145 = v934 + ((int)((unsigned int)(v934 - v933) >> 31));
      v932[8] = v1145;
      int * v936 = v907->cache_age;
      int v937 = v936[9];
      int v1147 = v937 + ((int)((unsigned int)(v937 - v933) >> 31));
      v936[9] = v1147;
      int * v939 = v907->cache_age;
      v939[v1144] = 0;
      v985 = v1144;
    } else {
      int * v942 = v907->cache_age;
      int v943 = v942[8];
      int * v944 = v907->cache_tags;
      int v945 = v944[8];
      int v946 = v942[9];
      int v947 = v944[9];
      int * v948 = v907->cache_dirty;
      int v1152 = 8 + ((((v943 + ((~(((v945 ^ -1) | (-(v945 ^ -1))) >> 31)) & 2)) - (v946 + ((~(((v947 ^ -1) | (-(v947 ^ -1))) >> 31)) & 2))) >> 31) & 1);
      int v949 = v948[v1152];
      bool v1153 = !(v949 == 0);
      if (v1153) {
        int * v950 = v907->cache_tags;
        int v951 = v950[v1152];
        int * v952 = v907->cache_vals;
        int v1156 = (8 + ((((v943 + ((~(((v945 ^ -1) | (-(v945 ^ -1))) >> 31)) & 2)) - (v946 + ((~(((v947 ^ -1) | (-(v947 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
        int v953 = v952[v1156];
        int v1157 = ((8 + ((((v943 + ((~(((v945 ^ -1) | (-(v945 ^ -1))) >> 31)) & 2)) - (v946 + ((~(((v947 ^ -1) | (-(v947 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
        int v954 = v952[v1157];
        int * v955 = v907->mem;
        int v1159 = v951 * 2;
        v955[v1159] = v953;
        int * v957 = v907->mem;
        int v1162 = (v951 * 2) + 1;
        v957[v1162] = v954;
        ;
      } else {
        ;
      }
      int * v962 = v907->mem;
      int v963 = v962[4];
      int v964 = v962[5];
      int * v965 = v907->cache_vals;
      int v1170 = (8 + ((((v943 + ((~(((v945 ^ -1) | (-(v945 ^ -1))) >> 31)) & 2)) - (v946 + ((~(((v947 ^ -1) | (-(v947 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
      v965[v1170] = v963;
      int * v967 = v907->cache_vals;
      int v1173 = ((8 + ((((v943 + ((~(((v945 ^ -1) | (-(v945 ^ -1))) >> 31)) & 2)) - (v946 + ((~(((v947 ^ -1) | (-(v947 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
      v967[v1173] = v964;
      int * v969 = v907->cache_tags;
      v969[v1152] = 2;
      int * v971 = v907->cache_dirty;
      v971[v1152] = 0;
      int * v973 = v907->cache_age;
      v973[v1152] = 1;
      int * v975 = v907->cache_age;
      int v976 = v975[v1152];
      int v977 = v975[8];
      int v1180 = v977 + ((int)((unsigned int)(v977 - v976) >> 31));
      v975[8] = v1180;
      int * v979 = v907->cache_age;
      int v980 = v979[9];
      int v1182 = v980 + ((int)((unsigned int)(v980 - v976) >> 31));
      v979[9] = v1182;
      int * v982 = v907->cache_age;
      v982[v1152] = 0;
      v985 = v1152;
    }
    int * v986 = v907->cache_vals;
    int v1185 = v985 * 2;
    int v987 = v986[v1185];
    int v1186 = (v985 * 2) + 1;
    int v988 = v986[v1186];
    int v1187 = ((((v927 + ((~(((v929 ^ -1) | (-(v929 ^ -1))) >> 31)) & 2)) - (v930 + ((~(((v931 ^ -1) | (-(v931 ^ -1))) >> 31)) & 2))) >> 31) & 1) * 2;
    v986[v1187] = v987;
    int * v990 = v907->cache_vals;
    int v1190 = (((((v927 + ((~(((v929 ^ -1) | (-(v929 ^ -1))) >> 31)) & 2)) - (v930 + ((~(((v931 ^ -1) | (-(v931 ^ -1))) >> 31)) & 2))) >> 31) & 1) * 2) + 1;
    v990[v1190] = v988;
    int * v992 = v907->cache_tags;
    int v1193 = (((v927 + ((~(((v929 ^ -1) | (-(v929 ^ -1))) >> 31)) & 2)) - (v930 + ((~(((v931 ^ -1) | (-(v931 ^ -1))) >> 31)) & 2))) >> 31) & 1;
    v992[v1193] = 2;
    int * v994 = v907->cache_dirty;
    v994[v1193] = 0;
    int * v996 = v907->cache_age;
    v996[v1193] = 1;
    int * v998 = v907->cache_age;
    int v999 = v998[v1193];
    int v1000 = v998[0];
    int v1198 = v1000 + ((int)((unsigned int)(v1000 - v999) >> 31));
    v998[0] = v1198;
    int * v1002 = v907->cache_age;
    int v1003 = v1002[1];
    int v1200 = v1003 + ((int)((unsigned int)(v1003 - v999) >> 31));
    v1002[1] = v1200;
    int * v1005 = v907->cache_age;
    v1005[v1193] = 0;
    v1008 = v1193;
  }
  int v1203 = v1008 * 2;
  int v1009 = v915[v1203];
  int * v1010 = v907->regs;
  v1010[8] = v1009;
  struct StateT * v1012 = v894->b;
  int * v1013 = v1012->cache_tags;
  int v1014 = v1013[0];
  int v1015 = v1013[1];
  int v1016 = v1013[8];
  int v1017 = v1013[9];
  int v1018 = v1012->timer;
  int v1208 = v1018 + ((100 ^ (((~(((v1016 ^ 2) | (-(v1016 ^ 2))) >> 31)) | (~(((v1017 ^ 2) | (-(v1017 ^ 2))) >> 31))) & 104)) ^ (((~(((v1014 ^ 2) | (-(v1014 ^ 2))) >> 31)) | (~(((v1015 ^ 2) | (-(v1015 ^ 2))) >> 31))) & (1 ^ (100 ^ (((~(((v1016 ^ 2) | (-(v1016 ^ 2))) >> 31)) | (~(((v1017 ^ 2) | (-(v1017 ^ 2))) >> 31))) & 104)))));
  v1012->timer = v1208;
  int * v1020 = v1012->cache_vals;
  bool v1209 = !(((~(((v1014 ^ 2) | (-(v1014 ^ 2))) >> 31)) | (~(((v1015 ^ 2) | (-(v1015 ^ 2))) >> 31))) == 0);
  int v1113;
  if (v1209) {
    int * v1021 = v1012->cache_age;
    int v1211 = (~(((v1015 ^ 2) | (-(v1015 ^ 2))) >> 31)) & 1;
    int v1022 = v1021[v1211];
    int v1023 = v1021[0];
    int v1212 = v1023 + ((int)((unsigned int)(v1023 - v1022) >> 31));
    v1021[0] = v1212;
    int * v1025 = v1012->cache_age;
    int v1026 = v1025[1];
    int v1214 = v1026 + ((int)((unsigned int)(v1026 - v1022) >> 31));
    v1025[1] = v1214;
    int * v1028 = v1012->cache_age;
    v1028[v1211] = 0;
    v1113 = v1211;
  } else {
    int * v1031 = v1012->cache_age;
    int v1032 = v1031[0];
    int * v1033 = v1012->cache_tags;
    int v1034 = v1033[0];
    int v1035 = v1031[1];
    int v1036 = v1033[1];
    bool v1218 = !(((~(((v1016 ^ 2) | (-(v1016 ^ 2))) >> 31)) | (~(((v1017 ^ 2) | (-(v1017 ^ 2))) >> 31))) == 0);
    int v1090;
    if (v1218) {
      int * v1037 = v1012->cache_age;
      int v1220 = 8 + ((~(((v1017 ^ 2) | (-(v1017 ^ 2))) >> 31)) & 1);
      int v1038 = v1037[v1220];
      int v1039 = v1037[8];
      int v1221 = v1039 + ((int)((unsigned int)(v1039 - v1038) >> 31));
      v1037[8] = v1221;
      int * v1041 = v1012->cache_age;
      int v1042 = v1041[9];
      int v1223 = v1042 + ((int)((unsigned int)(v1042 - v1038) >> 31));
      v1041[9] = v1223;
      int * v1044 = v1012->cache_age;
      v1044[v1220] = 0;
      v1090 = v1220;
    } else {
      int * v1047 = v1012->cache_age;
      int v1048 = v1047[8];
      int * v1049 = v1012->cache_tags;
      int v1050 = v1049[8];
      int v1051 = v1047[9];
      int v1052 = v1049[9];
      int * v1053 = v1012->cache_dirty;
      int v1228 = 8 + ((((v1048 + ((~(((v1050 ^ -1) | (-(v1050 ^ -1))) >> 31)) & 2)) - (v1051 + ((~(((v1052 ^ -1) | (-(v1052 ^ -1))) >> 31)) & 2))) >> 31) & 1);
      int v1054 = v1053[v1228];
      bool v1229 = !(v1054 == 0);
      if (v1229) {
        int * v1055 = v1012->cache_tags;
        int v1056 = v1055[v1228];
        int * v1057 = v1012->cache_vals;
        int v1232 = (8 + ((((v1048 + ((~(((v1050 ^ -1) | (-(v1050 ^ -1))) >> 31)) & 2)) - (v1051 + ((~(((v1052 ^ -1) | (-(v1052 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
        int v1058 = v1057[v1232];
        int v1233 = ((8 + ((((v1048 + ((~(((v1050 ^ -1) | (-(v1050 ^ -1))) >> 31)) & 2)) - (v1051 + ((~(((v1052 ^ -1) | (-(v1052 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
        int v1059 = v1057[v1233];
        int * v1060 = v1012->mem;
        int v1235 = v1056 * 2;
        v1060[v1235] = v1058;
        int * v1062 = v1012->mem;
        int v1238 = (v1056 * 2) + 1;
        v1062[v1238] = v1059;
        ;
      } else {
        ;
      }
      int * v1067 = v1012->mem;
      int v1068 = v1067[4];
      int v1069 = v1067[5];
      int * v1070 = v1012->cache_vals;
      int v1246 = (8 + ((((v1048 + ((~(((v1050 ^ -1) | (-(v1050 ^ -1))) >> 31)) & 2)) - (v1051 + ((~(((v1052 ^ -1) | (-(v1052 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
      v1070[v1246] = v1068;
      int * v1072 = v1012->cache_vals;
      int v1249 = ((8 + ((((v1048 + ((~(((v1050 ^ -1) | (-(v1050 ^ -1))) >> 31)) & 2)) - (v1051 + ((~(((v1052 ^ -1) | (-(v1052 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
      v1072[v1249] = v1069;
      int * v1074 = v1012->cache_tags;
      v1074[v1228] = 2;
      int * v1076 = v1012->cache_dirty;
      v1076[v1228] = 0;
      int * v1078 = v1012->cache_age;
      v1078[v1228] = 1;
      int * v1080 = v1012->cache_age;
      int v1081 = v1080[v1228];
      int v1082 = v1080[8];
      int v1256 = v1082 + ((int)((unsigned int)(v1082 - v1081) >> 31));
      v1080[8] = v1256;
      int * v1084 = v1012->cache_age;
      int v1085 = v1084[9];
      int v1258 = v1085 + ((int)((unsigned int)(v1085 - v1081) >> 31));
      v1084[9] = v1258;
      int * v1087 = v1012->cache_age;
      v1087[v1228] = 0;
      v1090 = v1228;
    }
    int * v1091 = v1012->cache_vals;
    int v1261 = v1090 * 2;
    int v1092 = v1091[v1261];
    int v1262 = (v1090 * 2) + 1;
    int v1093 = v1091[v1262];
    int v1263 = ((((v1032 + ((~(((v1034 ^ -1) | (-(v1034 ^ -1))) >> 31)) & 2)) - (v1035 + ((~(((v1036 ^ -1) | (-(v1036 ^ -1))) >> 31)) & 2))) >> 31) & 1) * 2;
    v1091[v1263] = v1092;
    int * v1095 = v1012->cache_vals;
    int v1266 = (((((v1032 + ((~(((v1034 ^ -1) | (-(v1034 ^ -1))) >> 31)) & 2)) - (v1035 + ((~(((v1036 ^ -1) | (-(v1036 ^ -1))) >> 31)) & 2))) >> 31) & 1) * 2) + 1;
    v1095[v1266] = v1093;
    int * v1097 = v1012->cache_tags;
    int v1269 = (((v1032 + ((~(((v1034 ^ -1) | (-(v1034 ^ -1))) >> 31)) & 2)) - (v1035 + ((~(((v1036 ^ -1) | (-(v1036 ^ -1))) >> 31)) & 2))) >> 31) & 1;
    v1097[v1269] = 2;
    int * v1099 = v1012->cache_dirty;
    v1099[v1269] = 0;
    int * v1101 = v1012->cache_age;
    v1101[v1269] = 1;
    int * v1103 = v1012->cache_age;
    int v1104 = v1103[v1269];
    int v1105 = v1103[0];
    int v1274 = v1105 + ((int)((unsigned int)(v1105 - v1104) >> 31));
    v1103[0] = v1274;
    int * v1107 = v1012->cache_age;
    int v1108 = v1107[1];
    int v1276 = v1108 + ((int)((unsigned int)(v1108 - v1104) >> 31));
    v1107[1] = v1276;
    int * v1110 = v1012->cache_age;
    v1110[v1269] = 0;
    v1113 = v1269;
  }
  int v1279 = v1113 * 2;
  int v1114 = v1020[v1279];
  int * v1115 = v1012->regs;
  v1115[8] = v1114;
  struct StateT2 * v1117 = slot_6(v894);
  return v1117;
}

struct StateT2 * slot_4(struct StateT2 * v511) {
  struct StateT * v512 = v511->a;
  int v513 = v512->timer;
  struct StateT * v514 = v511->b;
  int v515 = v514->timer;
  bool v738 = v513 == v515;
  squared_assert(v738);
  squared_assume(v738);
  struct StateT * v518 = v511->a;
  int v519 = v518->timer;
  int v740 = v519 + 1;
  v518->timer = v740;
  struct StateT * v521 = v511->b;
  int v522 = v521->timer;
  int v742 = v522 + 1;
  v521->timer = v742;
  struct StateT * v524 = v511->a;
  int * v525 = v524->cache_tags;
  int v526 = v525[0];
  int v527 = v525[1];
  int v528 = v525[4];
  int v529 = v525[5];
  int v530 = v524->timer;
  int v749 = v530 + ((100 ^ (((~((v528 | (-v528)) >> 31)) | (~((v529 | (-v529)) >> 31))) & 104)) ^ (((~((v526 | (-v526)) >> 31)) | (~((v527 | (-v527)) >> 31))) & (1 ^ (100 ^ (((~((v528 | (-v528)) >> 31)) | (~((v529 | (-v529)) >> 31))) & 104)))));
  v524->timer = v749;
  int * v532 = v524->cache_vals;
  bool v750 = !(((~((v526 | (-v526)) >> 31)) | (~((v527 | (-v527)) >> 31))) == 0);
  int v625;
  if (v750) {
    int * v533 = v524->cache_age;
    int v752 = (~((v527 | (-v527)) >> 31)) & 1;
    int v534 = v533[v752];
    int v535 = v533[0];
    int v753 = v535 + ((int)((unsigned int)(v535 - v534) >> 31));
    v533[0] = v753;
    int * v537 = v524->cache_age;
    int v538 = v537[1];
    int v755 = v538 + ((int)((unsigned int)(v538 - v534) >> 31));
    v537[1] = v755;
    int * v540 = v524->cache_age;
    v540[v752] = 0;
    v625 = v752;
  } else {
    int * v543 = v524->cache_age;
    int v544 = v543[0];
    int * v545 = v524->cache_tags;
    int v546 = v545[0];
    int v547 = v543[1];
    int v548 = v545[1];
    bool v759 = !(((~((v528 | (-v528)) >> 31)) | (~((v529 | (-v529)) >> 31))) == 0);
    int v602;
    if (v759) {
      int * v549 = v524->cache_age;
      int v761 = 4 + ((~((v529 | (-v529)) >> 31)) & 1);
      int v550 = v549[v761];
      int v551 = v549[4];
      int v762 = v551 + ((int)((unsigned int)(v551 - v550) >> 31));
      v549[4] = v762;
      int * v553 = v524->cache_age;
      int v554 = v553[5];
      int v764 = v554 + ((int)((unsigned int)(v554 - v550) >> 31));
      v553[5] = v764;
      int * v556 = v524->cache_age;
      v556[v761] = 0;
      v602 = v761;
    } else {
      int * v559 = v524->cache_age;
      int v560 = v559[4];
      int * v561 = v524->cache_tags;
      int v562 = v561[4];
      int v563 = v559[5];
      int v564 = v561[5];
      int * v565 = v524->cache_dirty;
      int v769 = 4 + ((((v560 + ((~(((v562 ^ -1) | (-(v562 ^ -1))) >> 31)) & 2)) - (v563 + ((~(((v564 ^ -1) | (-(v564 ^ -1))) >> 31)) & 2))) >> 31) & 1);
      int v566 = v565[v769];
      bool v770 = !(v566 == 0);
      if (v770) {
        int * v567 = v524->cache_tags;
        int v568 = v567[v769];
        int * v569 = v524->cache_vals;
        int v773 = (4 + ((((v560 + ((~(((v562 ^ -1) | (-(v562 ^ -1))) >> 31)) & 2)) - (v563 + ((~(((v564 ^ -1) | (-(v564 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
        int v570 = v569[v773];
        int v774 = ((4 + ((((v560 + ((~(((v562 ^ -1) | (-(v562 ^ -1))) >> 31)) & 2)) - (v563 + ((~(((v564 ^ -1) | (-(v564 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
        int v571 = v569[v774];
        int * v572 = v524->mem;
        int v776 = v568 * 2;
        v572[v776] = v570;
        int * v574 = v524->mem;
        int v779 = (v568 * 2) + 1;
        v574[v779] = v571;
        ;
      } else {
        ;
      }
      int * v579 = v524->mem;
      int v580 = v579[0];
      int v581 = v579[1];
      int * v582 = v524->cache_vals;
      int v785 = (4 + ((((v560 + ((~(((v562 ^ -1) | (-(v562 ^ -1))) >> 31)) & 2)) - (v563 + ((~(((v564 ^ -1) | (-(v564 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
      v582[v785] = v580;
      int * v584 = v524->cache_vals;
      int v788 = ((4 + ((((v560 + ((~(((v562 ^ -1) | (-(v562 ^ -1))) >> 31)) & 2)) - (v563 + ((~(((v564 ^ -1) | (-(v564 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
      v584[v788] = v581;
      int * v586 = v524->cache_tags;
      v586[v769] = 0;
      int * v588 = v524->cache_dirty;
      v588[v769] = 0;
      int * v590 = v524->cache_age;
      v590[v769] = 1;
      int * v592 = v524->cache_age;
      int v593 = v592[v769];
      int v594 = v592[4];
      int v794 = v594 + ((int)((unsigned int)(v594 - v593) >> 31));
      v592[4] = v794;
      int * v596 = v524->cache_age;
      int v597 = v596[5];
      int v796 = v597 + ((int)((unsigned int)(v597 - v593) >> 31));
      v596[5] = v796;
      int * v599 = v524->cache_age;
      v599[v769] = 0;
      v602 = v769;
    }
    int * v603 = v524->cache_vals;
    int v799 = v602 * 2;
    int v604 = v603[v799];
    int v800 = (v602 * 2) + 1;
    int v605 = v603[v800];
    int v801 = ((((v544 + ((~(((v546 ^ -1) | (-(v546 ^ -1))) >> 31)) & 2)) - (v547 + ((~(((v548 ^ -1) | (-(v548 ^ -1))) >> 31)) & 2))) >> 31) & 1) * 2;
    v603[v801] = v604;
    int * v607 = v524->cache_vals;
    int v804 = (((((v544 + ((~(((v546 ^ -1) | (-(v546 ^ -1))) >> 31)) & 2)) - (v547 + ((~(((v548 ^ -1) | (-(v548 ^ -1))) >> 31)) & 2))) >> 31) & 1) * 2) + 1;
    v607[v804] = v605;
    int * v609 = v524->cache_tags;
    int v807 = (((v544 + ((~(((v546 ^ -1) | (-(v546 ^ -1))) >> 31)) & 2)) - (v547 + ((~(((v548 ^ -1) | (-(v548 ^ -1))) >> 31)) & 2))) >> 31) & 1;
    v609[v807] = 0;
    int * v611 = v524->cache_dirty;
    v611[v807] = 0;
    int * v613 = v524->cache_age;
    v613[v807] = 1;
    int * v615 = v524->cache_age;
    int v616 = v615[v807];
    int v617 = v615[0];
    int v811 = v617 + ((int)((unsigned int)(v617 - v616) >> 31));
    v615[0] = v811;
    int * v619 = v524->cache_age;
    int v620 = v619[1];
    int v813 = v620 + ((int)((unsigned int)(v620 - v616) >> 31));
    v619[1] = v813;
    int * v622 = v524->cache_age;
    v622[v807] = 0;
    v625 = v807;
  }
  int v816 = v625 * 2;
  int v626 = v532[v816];
  int * v627 = v524->regs;
  v627[7] = v626;
  struct StateT * v629 = v511->b;
  int * v630 = v629->cache_tags;
  int v631 = v630[0];
  int v632 = v630[1];
  int v633 = v630[4];
  int v634 = v630[5];
  int v635 = v629->timer;
  int v822 = v635 + ((100 ^ (((~((v633 | (-v633)) >> 31)) | (~((v634 | (-v634)) >> 31))) & 104)) ^ (((~((v631 | (-v631)) >> 31)) | (~((v632 | (-v632)) >> 31))) & (1 ^ (100 ^ (((~((v633 | (-v633)) >> 31)) | (~((v634 | (-v634)) >> 31))) & 104)))));
  v629->timer = v822;
  int * v637 = v629->cache_vals;
  bool v823 = !(((~((v631 | (-v631)) >> 31)) | (~((v632 | (-v632)) >> 31))) == 0);
  int v730;
  if (v823) {
    int * v638 = v629->cache_age;
    int v825 = (~((v632 | (-v632)) >> 31)) & 1;
    int v639 = v638[v825];
    int v640 = v638[0];
    int v826 = v640 + ((int)((unsigned int)(v640 - v639) >> 31));
    v638[0] = v826;
    int * v642 = v629->cache_age;
    int v643 = v642[1];
    int v828 = v643 + ((int)((unsigned int)(v643 - v639) >> 31));
    v642[1] = v828;
    int * v645 = v629->cache_age;
    v645[v825] = 0;
    v730 = v825;
  } else {
    int * v648 = v629->cache_age;
    int v649 = v648[0];
    int * v650 = v629->cache_tags;
    int v651 = v650[0];
    int v652 = v648[1];
    int v653 = v650[1];
    bool v832 = !(((~((v633 | (-v633)) >> 31)) | (~((v634 | (-v634)) >> 31))) == 0);
    int v707;
    if (v832) {
      int * v654 = v629->cache_age;
      int v834 = 4 + ((~((v634 | (-v634)) >> 31)) & 1);
      int v655 = v654[v834];
      int v656 = v654[4];
      int v835 = v656 + ((int)((unsigned int)(v656 - v655) >> 31));
      v654[4] = v835;
      int * v658 = v629->cache_age;
      int v659 = v658[5];
      int v837 = v659 + ((int)((unsigned int)(v659 - v655) >> 31));
      v658[5] = v837;
      int * v661 = v629->cache_age;
      v661[v834] = 0;
      v707 = v834;
    } else {
      int * v664 = v629->cache_age;
      int v665 = v664[4];
      int * v666 = v629->cache_tags;
      int v667 = v666[4];
      int v668 = v664[5];
      int v669 = v666[5];
      int * v670 = v629->cache_dirty;
      int v842 = 4 + ((((v665 + ((~(((v667 ^ -1) | (-(v667 ^ -1))) >> 31)) & 2)) - (v668 + ((~(((v669 ^ -1) | (-(v669 ^ -1))) >> 31)) & 2))) >> 31) & 1);
      int v671 = v670[v842];
      bool v843 = !(v671 == 0);
      if (v843) {
        int * v672 = v629->cache_tags;
        int v673 = v672[v842];
        int * v674 = v629->cache_vals;
        int v846 = (4 + ((((v665 + ((~(((v667 ^ -1) | (-(v667 ^ -1))) >> 31)) & 2)) - (v668 + ((~(((v669 ^ -1) | (-(v669 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
        int v675 = v674[v846];
        int v847 = ((4 + ((((v665 + ((~(((v667 ^ -1) | (-(v667 ^ -1))) >> 31)) & 2)) - (v668 + ((~(((v669 ^ -1) | (-(v669 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
        int v676 = v674[v847];
        int * v677 = v629->mem;
        int v849 = v673 * 2;
        v677[v849] = v675;
        int * v679 = v629->mem;
        int v852 = (v673 * 2) + 1;
        v679[v852] = v676;
        ;
      } else {
        ;
      }
      int * v684 = v629->mem;
      int v685 = v684[0];
      int v686 = v684[1];
      int * v687 = v629->cache_vals;
      int v858 = (4 + ((((v665 + ((~(((v667 ^ -1) | (-(v667 ^ -1))) >> 31)) & 2)) - (v668 + ((~(((v669 ^ -1) | (-(v669 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
      v687[v858] = v685;
      int * v689 = v629->cache_vals;
      int v861 = ((4 + ((((v665 + ((~(((v667 ^ -1) | (-(v667 ^ -1))) >> 31)) & 2)) - (v668 + ((~(((v669 ^ -1) | (-(v669 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
      v689[v861] = v686;
      int * v691 = v629->cache_tags;
      v691[v842] = 0;
      int * v693 = v629->cache_dirty;
      v693[v842] = 0;
      int * v695 = v629->cache_age;
      v695[v842] = 1;
      int * v697 = v629->cache_age;
      int v698 = v697[v842];
      int v699 = v697[4];
      int v867 = v699 + ((int)((unsigned int)(v699 - v698) >> 31));
      v697[4] = v867;
      int * v701 = v629->cache_age;
      int v702 = v701[5];
      int v869 = v702 + ((int)((unsigned int)(v702 - v698) >> 31));
      v701[5] = v869;
      int * v704 = v629->cache_age;
      v704[v842] = 0;
      v707 = v842;
    }
    int * v708 = v629->cache_vals;
    int v872 = v707 * 2;
    int v709 = v708[v872];
    int v873 = (v707 * 2) + 1;
    int v710 = v708[v873];
    int v874 = ((((v649 + ((~(((v651 ^ -1) | (-(v651 ^ -1))) >> 31)) & 2)) - (v652 + ((~(((v653 ^ -1) | (-(v653 ^ -1))) >> 31)) & 2))) >> 31) & 1) * 2;
    v708[v874] = v709;
    int * v712 = v629->cache_vals;
    int v877 = (((((v649 + ((~(((v651 ^ -1) | (-(v651 ^ -1))) >> 31)) & 2)) - (v652 + ((~(((v653 ^ -1) | (-(v653 ^ -1))) >> 31)) & 2))) >> 31) & 1) * 2) + 1;
    v712[v877] = v710;
    int * v714 = v629->cache_tags;
    int v880 = (((v649 + ((~(((v651 ^ -1) | (-(v651 ^ -1))) >> 31)) & 2)) - (v652 + ((~(((v653 ^ -1) | (-(v653 ^ -1))) >> 31)) & 2))) >> 31) & 1;
    v714[v880] = 0;
    int * v716 = v629->cache_dirty;
    v716[v880] = 0;
    int * v718 = v629->cache_age;
    v718[v880] = 1;
    int * v720 = v629->cache_age;
    int v721 = v720[v880];
    int v722 = v720[0];
    int v884 = v722 + ((int)((unsigned int)(v722 - v721) >> 31));
    v720[0] = v884;
    int * v724 = v629->cache_age;
    int v725 = v724[1];
    int v886 = v725 + ((int)((unsigned int)(v725 - v721) >> 31));
    v724[1] = v886;
    int * v727 = v629->cache_age;
    v727[v880] = 0;
    v730 = v880;
  }
  int v889 = v730 * 2;
  int v731 = v637[v889];
  int * v732 = v629->regs;
  v732[7] = v731;
  struct StateT2 * v734 = slot_5(v511);
  return v734;
}

struct StateT2 * slot_2(struct StateT2 * v433) {
  struct StateT * v434 = v433->a;
  int v435 = v434->timer;
  struct StateT * v436 = v433->b;
  int v437 = v436->timer;
  bool v458 = v435 == v437;
  squared_assert(v458);
  squared_assume(v458);
  struct StateT * v440 = v433->a;
  int v441 = v440->timer;
  int v460 = v441 + 1;
  v440->timer = v460;
  struct StateT * v443 = v433->b;
  int v444 = v443->timer;
  int v462 = v444 + 1;
  v443->timer = v462;
  struct StateT * v446 = v433->a;
  int * v447 = v446->regs;
  int v448 = v447[6];
  int v466 = v448 << 3;
  v447[6] = v466;
  struct StateT * v450 = v433->b;
  int * v451 = v450->regs;
  int v452 = v451[6];
  int v469 = v452 << 3;
  v451[6] = v469;
  struct StateT2 * v454 = slot_3(v433);
  return v454;
}

struct StateT2 * slot_7(struct StateT2 * v1702) {
  struct StateT * v1703 = v1702->a;
  int v1704 = v1703->timer;
  struct StateT * v1705 = v1702->b;
  int v1706 = v1705->timer;
  bool v1928 = v1704 == v1706;
  squared_assert(v1928);
  squared_assume(v1928);
  struct StateT * v1709 = v1702->a;
  int v1710 = v1709->timer;
  int v1930 = v1710 + 1;
  v1709->timer = v1930;
  struct StateT * v1712 = v1702->b;
  int v1713 = v1712->timer;
  int v1932 = v1713 + 1;
  v1712->timer = v1932;
  struct StateT * v1715 = v1702->a;
  int * v1716 = v1715->cache_tags;
  int v1717 = v1716[0];
  int v1718 = v1716[1];
  int v1719 = v1716[4];
  int v1720 = v1716[5];
  int v1721 = v1715->timer;
  int v1939 = v1721 + ((100 ^ (((~((v1719 | (-v1719)) >> 31)) | (~((v1720 | (-v1720)) >> 31))) & 104)) ^ (((~((v1717 | (-v1717)) >> 31)) | (~((v1718 | (-v1718)) >> 31))) & (1 ^ (100 ^ (((~((v1719 | (-v1719)) >> 31)) | (~((v1720 | (-v1720)) >> 31))) & 104)))));
  v1715->timer = v1939;
  int * v1723 = v1715->cache_vals;
  bool v1940 = !(((~((v1717 | (-v1717)) >> 31)) | (~((v1718 | (-v1718)) >> 31))) == 0);
  int v1816;
  if (v1940) {
    int * v1724 = v1715->cache_age;
    int v1942 = (~((v1718 | (-v1718)) >> 31)) & 1;
    int v1725 = v1724[v1942];
    int v1726 = v1724[0];
    int v1943 = v1726 + ((int)((unsigned int)(v1726 - v1725) >> 31));
    v1724[0] = v1943;
    int * v1728 = v1715->cache_age;
    int v1729 = v1728[1];
    int v1945 = v1729 + ((int)((unsigned int)(v1729 - v1725) >> 31));
    v1728[1] = v1945;
    int * v1731 = v1715->cache_age;
    v1731[v1942] = 0;
    v1816 = v1942;
  } else {
    int * v1734 = v1715->cache_age;
    int v1735 = v1734[0];
    int * v1736 = v1715->cache_tags;
    int v1737 = v1736[0];
    int v1738 = v1734[1];
    int v1739 = v1736[1];
    bool v1949 = !(((~((v1719 | (-v1719)) >> 31)) | (~((v1720 | (-v1720)) >> 31))) == 0);
    int v1793;
    if (v1949) {
      int * v1740 = v1715->cache_age;
      int v1951 = 4 + ((~((v1720 | (-v1720)) >> 31)) & 1);
      int v1741 = v1740[v1951];
      int v1742 = v1740[4];
      int v1952 = v1742 + ((int)((unsigned int)(v1742 - v1741) >> 31));
      v1740[4] = v1952;
      int * v1744 = v1715->cache_age;
      int v1745 = v1744[5];
      int v1954 = v1745 + ((int)((unsigned int)(v1745 - v1741) >> 31));
      v1744[5] = v1954;
      int * v1747 = v1715->cache_age;
      v1747[v1951] = 0;
      v1793 = v1951;
    } else {
      int * v1750 = v1715->cache_age;
      int v1751 = v1750[4];
      int * v1752 = v1715->cache_tags;
      int v1753 = v1752[4];
      int v1754 = v1750[5];
      int v1755 = v1752[5];
      int * v1756 = v1715->cache_dirty;
      int v1959 = 4 + ((((v1751 + ((~(((v1753 ^ -1) | (-(v1753 ^ -1))) >> 31)) & 2)) - (v1754 + ((~(((v1755 ^ -1) | (-(v1755 ^ -1))) >> 31)) & 2))) >> 31) & 1);
      int v1757 = v1756[v1959];
      bool v1960 = !(v1757 == 0);
      if (v1960) {
        int * v1758 = v1715->cache_tags;
        int v1759 = v1758[v1959];
        int * v1760 = v1715->cache_vals;
        int v1963 = (4 + ((((v1751 + ((~(((v1753 ^ -1) | (-(v1753 ^ -1))) >> 31)) & 2)) - (v1754 + ((~(((v1755 ^ -1) | (-(v1755 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
        int v1761 = v1760[v1963];
        int v1964 = ((4 + ((((v1751 + ((~(((v1753 ^ -1) | (-(v1753 ^ -1))) >> 31)) & 2)) - (v1754 + ((~(((v1755 ^ -1) | (-(v1755 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
        int v1762 = v1760[v1964];
        int * v1763 = v1715->mem;
        int v1966 = v1759 * 2;
        v1763[v1966] = v1761;
        int * v1765 = v1715->mem;
        int v1969 = (v1759 * 2) + 1;
        v1765[v1969] = v1762;
        ;
      } else {
        ;
      }
      int * v1770 = v1715->mem;
      int v1771 = v1770[0];
      int v1772 = v1770[1];
      int * v1773 = v1715->cache_vals;
      int v1975 = (4 + ((((v1751 + ((~(((v1753 ^ -1) | (-(v1753 ^ -1))) >> 31)) & 2)) - (v1754 + ((~(((v1755 ^ -1) | (-(v1755 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
      v1773[v1975] = v1771;
      int * v1775 = v1715->cache_vals;
      int v1978 = ((4 + ((((v1751 + ((~(((v1753 ^ -1) | (-(v1753 ^ -1))) >> 31)) & 2)) - (v1754 + ((~(((v1755 ^ -1) | (-(v1755 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
      v1775[v1978] = v1772;
      int * v1777 = v1715->cache_tags;
      v1777[v1959] = 0;
      int * v1779 = v1715->cache_dirty;
      v1779[v1959] = 0;
      int * v1781 = v1715->cache_age;
      v1781[v1959] = 1;
      int * v1783 = v1715->cache_age;
      int v1784 = v1783[v1959];
      int v1785 = v1783[4];
      int v1984 = v1785 + ((int)((unsigned int)(v1785 - v1784) >> 31));
      v1783[4] = v1984;
      int * v1787 = v1715->cache_age;
      int v1788 = v1787[5];
      int v1986 = v1788 + ((int)((unsigned int)(v1788 - v1784) >> 31));
      v1787[5] = v1986;
      int * v1790 = v1715->cache_age;
      v1790[v1959] = 0;
      v1793 = v1959;
    }
    int * v1794 = v1715->cache_vals;
    int v1989 = v1793 * 2;
    int v1795 = v1794[v1989];
    int v1990 = (v1793 * 2) + 1;
    int v1796 = v1794[v1990];
    int v1991 = ((((v1735 + ((~(((v1737 ^ -1) | (-(v1737 ^ -1))) >> 31)) & 2)) - (v1738 + ((~(((v1739 ^ -1) | (-(v1739 ^ -1))) >> 31)) & 2))) >> 31) & 1) * 2;
    v1794[v1991] = v1795;
    int * v1798 = v1715->cache_vals;
    int v1994 = (((((v1735 + ((~(((v1737 ^ -1) | (-(v1737 ^ -1))) >> 31)) & 2)) - (v1738 + ((~(((v1739 ^ -1) | (-(v1739 ^ -1))) >> 31)) & 2))) >> 31) & 1) * 2) + 1;
    v1798[v1994] = v1796;
    int * v1800 = v1715->cache_tags;
    int v1997 = (((v1735 + ((~(((v1737 ^ -1) | (-(v1737 ^ -1))) >> 31)) & 2)) - (v1738 + ((~(((v1739 ^ -1) | (-(v1739 ^ -1))) >> 31)) & 2))) >> 31) & 1;
    v1800[v1997] = 0;
    int * v1802 = v1715->cache_dirty;
    v1802[v1997] = 0;
    int * v1804 = v1715->cache_age;
    v1804[v1997] = 1;
    int * v1806 = v1715->cache_age;
    int v1807 = v1806[v1997];
    int v1808 = v1806[0];
    int v2001 = v1808 + ((int)((unsigned int)(v1808 - v1807) >> 31));
    v1806[0] = v2001;
    int * v1810 = v1715->cache_age;
    int v1811 = v1810[1];
    int v2003 = v1811 + ((int)((unsigned int)(v1811 - v1807) >> 31));
    v1810[1] = v2003;
    int * v1813 = v1715->cache_age;
    v1813[v1997] = 0;
    v1816 = v1997;
  }
  int v2006 = v1816 * 2;
  int v1817 = v1723[v2006];
  int * v1818 = v1715->regs;
  v1818[11] = v1817;
  struct StateT * v1820 = v1702->b;
  int * v1821 = v1820->cache_tags;
  int v1822 = v1821[0];
  int v1823 = v1821[1];
  int v1824 = v1821[4];
  int v1825 = v1821[5];
  int v1826 = v1820->timer;
  int v2012 = v1826 + ((100 ^ (((~((v1824 | (-v1824)) >> 31)) | (~((v1825 | (-v1825)) >> 31))) & 104)) ^ (((~((v1822 | (-v1822)) >> 31)) | (~((v1823 | (-v1823)) >> 31))) & (1 ^ (100 ^ (((~((v1824 | (-v1824)) >> 31)) | (~((v1825 | (-v1825)) >> 31))) & 104)))));
  v1820->timer = v2012;
  int * v1828 = v1820->cache_vals;
  bool v2013 = !(((~((v1822 | (-v1822)) >> 31)) | (~((v1823 | (-v1823)) >> 31))) == 0);
  int v1921;
  if (v2013) {
    int * v1829 = v1820->cache_age;
    int v2015 = (~((v1823 | (-v1823)) >> 31)) & 1;
    int v1830 = v1829[v2015];
    int v1831 = v1829[0];
    int v2016 = v1831 + ((int)((unsigned int)(v1831 - v1830) >> 31));
    v1829[0] = v2016;
    int * v1833 = v1820->cache_age;
    int v1834 = v1833[1];
    int v2018 = v1834 + ((int)((unsigned int)(v1834 - v1830) >> 31));
    v1833[1] = v2018;
    int * v1836 = v1820->cache_age;
    v1836[v2015] = 0;
    v1921 = v2015;
  } else {
    int * v1839 = v1820->cache_age;
    int v1840 = v1839[0];
    int * v1841 = v1820->cache_tags;
    int v1842 = v1841[0];
    int v1843 = v1839[1];
    int v1844 = v1841[1];
    bool v2022 = !(((~((v1824 | (-v1824)) >> 31)) | (~((v1825 | (-v1825)) >> 31))) == 0);
    int v1898;
    if (v2022) {
      int * v1845 = v1820->cache_age;
      int v2024 = 4 + ((~((v1825 | (-v1825)) >> 31)) & 1);
      int v1846 = v1845[v2024];
      int v1847 = v1845[4];
      int v2025 = v1847 + ((int)((unsigned int)(v1847 - v1846) >> 31));
      v1845[4] = v2025;
      int * v1849 = v1820->cache_age;
      int v1850 = v1849[5];
      int v2027 = v1850 + ((int)((unsigned int)(v1850 - v1846) >> 31));
      v1849[5] = v2027;
      int * v1852 = v1820->cache_age;
      v1852[v2024] = 0;
      v1898 = v2024;
    } else {
      int * v1855 = v1820->cache_age;
      int v1856 = v1855[4];
      int * v1857 = v1820->cache_tags;
      int v1858 = v1857[4];
      int v1859 = v1855[5];
      int v1860 = v1857[5];
      int * v1861 = v1820->cache_dirty;
      int v2032 = 4 + ((((v1856 + ((~(((v1858 ^ -1) | (-(v1858 ^ -1))) >> 31)) & 2)) - (v1859 + ((~(((v1860 ^ -1) | (-(v1860 ^ -1))) >> 31)) & 2))) >> 31) & 1);
      int v1862 = v1861[v2032];
      bool v2033 = !(v1862 == 0);
      if (v2033) {
        int * v1863 = v1820->cache_tags;
        int v1864 = v1863[v2032];
        int * v1865 = v1820->cache_vals;
        int v2036 = (4 + ((((v1856 + ((~(((v1858 ^ -1) | (-(v1858 ^ -1))) >> 31)) & 2)) - (v1859 + ((~(((v1860 ^ -1) | (-(v1860 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
        int v1866 = v1865[v2036];
        int v2037 = ((4 + ((((v1856 + ((~(((v1858 ^ -1) | (-(v1858 ^ -1))) >> 31)) & 2)) - (v1859 + ((~(((v1860 ^ -1) | (-(v1860 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
        int v1867 = v1865[v2037];
        int * v1868 = v1820->mem;
        int v2039 = v1864 * 2;
        v1868[v2039] = v1866;
        int * v1870 = v1820->mem;
        int v2042 = (v1864 * 2) + 1;
        v1870[v2042] = v1867;
        ;
      } else {
        ;
      }
      int * v1875 = v1820->mem;
      int v1876 = v1875[0];
      int v1877 = v1875[1];
      int * v1878 = v1820->cache_vals;
      int v2048 = (4 + ((((v1856 + ((~(((v1858 ^ -1) | (-(v1858 ^ -1))) >> 31)) & 2)) - (v1859 + ((~(((v1860 ^ -1) | (-(v1860 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
      v1878[v2048] = v1876;
      int * v1880 = v1820->cache_vals;
      int v2051 = ((4 + ((((v1856 + ((~(((v1858 ^ -1) | (-(v1858 ^ -1))) >> 31)) & 2)) - (v1859 + ((~(((v1860 ^ -1) | (-(v1860 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
      v1880[v2051] = v1877;
      int * v1882 = v1820->cache_tags;
      v1882[v2032] = 0;
      int * v1884 = v1820->cache_dirty;
      v1884[v2032] = 0;
      int * v1886 = v1820->cache_age;
      v1886[v2032] = 1;
      int * v1888 = v1820->cache_age;
      int v1889 = v1888[v2032];
      int v1890 = v1888[4];
      int v2057 = v1890 + ((int)((unsigned int)(v1890 - v1889) >> 31));
      v1888[4] = v2057;
      int * v1892 = v1820->cache_age;
      int v1893 = v1892[5];
      int v2059 = v1893 + ((int)((unsigned int)(v1893 - v1889) >> 31));
      v1892[5] = v2059;
      int * v1895 = v1820->cache_age;
      v1895[v2032] = 0;
      v1898 = v2032;
    }
    int * v1899 = v1820->cache_vals;
    int v2062 = v1898 * 2;
    int v1900 = v1899[v2062];
    int v2063 = (v1898 * 2) + 1;
    int v1901 = v1899[v2063];
    int v2064 = ((((v1840 + ((~(((v1842 ^ -1) | (-(v1842 ^ -1))) >> 31)) & 2)) - (v1843 + ((~(((v1844 ^ -1) | (-(v1844 ^ -1))) >> 31)) & 2))) >> 31) & 1) * 2;
    v1899[v2064] = v1900;
    int * v1903 = v1820->cache_vals;
    int v2067 = (((((v1840 + ((~(((v1842 ^ -1) | (-(v1842 ^ -1))) >> 31)) & 2)) - (v1843 + ((~(((v1844 ^ -1) | (-(v1844 ^ -1))) >> 31)) & 2))) >> 31) & 1) * 2) + 1;
    v1903[v2067] = v1901;
    int * v1905 = v1820->cache_tags;
    int v2070 = (((v1840 + ((~(((v1842 ^ -1) | (-(v1842 ^ -1))) >> 31)) & 2)) - (v1843 + ((~(((v1844 ^ -1) | (-(v1844 ^ -1))) >> 31)) & 2))) >> 31) & 1;
    v1905[v2070] = 0;
    int * v1907 = v1820->cache_dirty;
    v1907[v2070] = 0;
    int * v1909 = v1820->cache_age;
    v1909[v2070] = 1;
    int * v1911 = v1820->cache_age;
    int v1912 = v1911[v2070];
    int v1913 = v1911[0];
    int v2074 = v1913 + ((int)((unsigned int)(v1913 - v1912) >> 31));
    v1911[0] = v2074;
    int * v1915 = v1820->cache_age;
    int v1916 = v1915[1];
    int v2076 = v1916 + ((int)((unsigned int)(v1916 - v1912) >> 31));
    v1915[1] = v2076;
    int * v1918 = v1820->cache_age;
    v1918[v2070] = 0;
    v1921 = v2070;
  }
  int v2079 = v1921 * 2;
  int v1922 = v1828[v2079];
  int * v1923 = v1820->regs;
  v1923[11] = v1922;
  return v1702;
}

struct StateT2 * slot_3(struct StateT2 * v472) {
  struct StateT * v473 = v472->a;
  int v474 = v473->timer;
  struct StateT * v475 = v472->b;
  int v476 = v475->timer;
  bool v497 = v474 == v476;
  squared_assert(v497);
  squared_assume(v497);
  struct StateT * v479 = v472->a;
  int v480 = v479->timer;
  int v499 = v480 + 1;
  v479->timer = v499;
  struct StateT * v482 = v472->b;
  int v483 = v482->timer;
  int v501 = v483 + 1;
  v482->timer = v501;
  struct StateT * v485 = v472->a;
  int * v486 = v485->regs;
  int v487 = v486[6];
  int v505 = v487 + 32;
  v486[6] = v505;
  struct StateT * v489 = v472->b;
  int * v490 = v489->regs;
  int v491 = v490[6];
  int v508 = v491 + 32;
  v490[6] = v508;
  struct StateT2 * v493 = slot_4(v472);
  return v493;
}

struct StateT2 * slot_0(struct StateT2 * v2) {
  struct StateT * v3 = v2->a;
  int v4 = v3->timer;
  struct StateT * v5 = v2->b;
  int v6 = v5->timer;
  bool v229 = v4 == v6;
  squared_assert(v229);
  squared_assume(v229);
  struct StateT * v9 = v2->a;
  int v10 = v9->timer;
  int v231 = v10 + 1;
  v9->timer = v231;
  struct StateT * v12 = v2->b;
  int v13 = v12->timer;
  int v233 = v13 + 1;
  v12->timer = v233;
  struct StateT * v15 = v2->a;
  int * v16 = v15->cache_tags;
  int v17 = v16[0];
  int v18 = v16[1];
  int v19 = v16[8];
  int v20 = v16[9];
  int v21 = v15->timer;
  int v240 = v21 + ((100 ^ (((~(((v19 ^ 10) | (-(v19 ^ 10))) >> 31)) | (~(((v20 ^ 10) | (-(v20 ^ 10))) >> 31))) & 104)) ^ (((~(((v17 ^ 10) | (-(v17 ^ 10))) >> 31)) | (~(((v18 ^ 10) | (-(v18 ^ 10))) >> 31))) & (1 ^ (100 ^ (((~(((v19 ^ 10) | (-(v19 ^ 10))) >> 31)) | (~(((v20 ^ 10) | (-(v20 ^ 10))) >> 31))) & 104)))));
  v15->timer = v240;
  int * v23 = v15->cache_vals;
  bool v241 = !(((~(((v17 ^ 10) | (-(v17 ^ 10))) >> 31)) | (~(((v18 ^ 10) | (-(v18 ^ 10))) >> 31))) == 0);
  int v116;
  if (v241) {
    int * v24 = v15->cache_age;
    int v243 = (~(((v18 ^ 10) | (-(v18 ^ 10))) >> 31)) & 1;
    int v25 = v24[v243];
    int v26 = v24[0];
    int v244 = v26 + ((int)((unsigned int)(v26 - v25) >> 31));
    v24[0] = v244;
    int * v28 = v15->cache_age;
    int v29 = v28[1];
    int v246 = v29 + ((int)((unsigned int)(v29 - v25) >> 31));
    v28[1] = v246;
    int * v31 = v15->cache_age;
    v31[v243] = 0;
    v116 = v243;
  } else {
    int * v34 = v15->cache_age;
    int v35 = v34[0];
    int * v36 = v15->cache_tags;
    int v37 = v36[0];
    int v38 = v34[1];
    int v39 = v36[1];
    bool v250 = !(((~(((v19 ^ 10) | (-(v19 ^ 10))) >> 31)) | (~(((v20 ^ 10) | (-(v20 ^ 10))) >> 31))) == 0);
    int v93;
    if (v250) {
      int * v40 = v15->cache_age;
      int v252 = 8 + ((~(((v20 ^ 10) | (-(v20 ^ 10))) >> 31)) & 1);
      int v41 = v40[v252];
      int v42 = v40[8];
      int v253 = v42 + ((int)((unsigned int)(v42 - v41) >> 31));
      v40[8] = v253;
      int * v44 = v15->cache_age;
      int v45 = v44[9];
      int v255 = v45 + ((int)((unsigned int)(v45 - v41) >> 31));
      v44[9] = v255;
      int * v47 = v15->cache_age;
      v47[v252] = 0;
      v93 = v252;
    } else {
      int * v50 = v15->cache_age;
      int v51 = v50[8];
      int * v52 = v15->cache_tags;
      int v53 = v52[8];
      int v54 = v50[9];
      int v55 = v52[9];
      int * v56 = v15->cache_dirty;
      int v260 = 8 + ((((v51 + ((~(((v53 ^ -1) | (-(v53 ^ -1))) >> 31)) & 2)) - (v54 + ((~(((v55 ^ -1) | (-(v55 ^ -1))) >> 31)) & 2))) >> 31) & 1);
      int v57 = v56[v260];
      bool v261 = !(v57 == 0);
      if (v261) {
        int * v58 = v15->cache_tags;
        int v59 = v58[v260];
        int * v60 = v15->cache_vals;
        int v264 = (8 + ((((v51 + ((~(((v53 ^ -1) | (-(v53 ^ -1))) >> 31)) & 2)) - (v54 + ((~(((v55 ^ -1) | (-(v55 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
        int v61 = v60[v264];
        int v265 = ((8 + ((((v51 + ((~(((v53 ^ -1) | (-(v53 ^ -1))) >> 31)) & 2)) - (v54 + ((~(((v55 ^ -1) | (-(v55 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
        int v62 = v60[v265];
        int * v63 = v15->mem;
        int v267 = v59 * 2;
        v63[v267] = v61;
        int * v65 = v15->mem;
        int v270 = (v59 * 2) + 1;
        v65[v270] = v62;
        ;
      } else {
        ;
      }
      int * v70 = v15->mem;
      int v71 = v70[20];
      int v72 = v70[21];
      int * v73 = v15->cache_vals;
      int v278 = (8 + ((((v51 + ((~(((v53 ^ -1) | (-(v53 ^ -1))) >> 31)) & 2)) - (v54 + ((~(((v55 ^ -1) | (-(v55 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
      v73[v278] = v71;
      int * v75 = v15->cache_vals;
      int v281 = ((8 + ((((v51 + ((~(((v53 ^ -1) | (-(v53 ^ -1))) >> 31)) & 2)) - (v54 + ((~(((v55 ^ -1) | (-(v55 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
      v75[v281] = v72;
      int * v77 = v15->cache_tags;
      v77[v260] = 10;
      int * v79 = v15->cache_dirty;
      v79[v260] = 0;
      int * v81 = v15->cache_age;
      v81[v260] = 1;
      int * v83 = v15->cache_age;
      int v84 = v83[v260];
      int v85 = v83[8];
      int v288 = v85 + ((int)((unsigned int)(v85 - v84) >> 31));
      v83[8] = v288;
      int * v87 = v15->cache_age;
      int v88 = v87[9];
      int v290 = v88 + ((int)((unsigned int)(v88 - v84) >> 31));
      v87[9] = v290;
      int * v90 = v15->cache_age;
      v90[v260] = 0;
      v93 = v260;
    }
    int * v94 = v15->cache_vals;
    int v293 = v93 * 2;
    int v95 = v94[v293];
    int v294 = (v93 * 2) + 1;
    int v96 = v94[v294];
    int v295 = ((((v35 + ((~(((v37 ^ -1) | (-(v37 ^ -1))) >> 31)) & 2)) - (v38 + ((~(((v39 ^ -1) | (-(v39 ^ -1))) >> 31)) & 2))) >> 31) & 1) * 2;
    v94[v295] = v95;
    int * v98 = v15->cache_vals;
    int v298 = (((((v35 + ((~(((v37 ^ -1) | (-(v37 ^ -1))) >> 31)) & 2)) - (v38 + ((~(((v39 ^ -1) | (-(v39 ^ -1))) >> 31)) & 2))) >> 31) & 1) * 2) + 1;
    v98[v298] = v96;
    int * v100 = v15->cache_tags;
    int v301 = (((v35 + ((~(((v37 ^ -1) | (-(v37 ^ -1))) >> 31)) & 2)) - (v38 + ((~(((v39 ^ -1) | (-(v39 ^ -1))) >> 31)) & 2))) >> 31) & 1;
    v100[v301] = 10;
    int * v102 = v15->cache_dirty;
    v102[v301] = 0;
    int * v104 = v15->cache_age;
    v104[v301] = 1;
    int * v106 = v15->cache_age;
    int v107 = v106[v301];
    int v108 = v106[0];
    int v306 = v108 + ((int)((unsigned int)(v108 - v107) >> 31));
    v106[0] = v306;
    int * v110 = v15->cache_age;
    int v111 = v110[1];
    int v308 = v111 + ((int)((unsigned int)(v111 - v107) >> 31));
    v110[1] = v308;
    int * v113 = v15->cache_age;
    v113[v301] = 0;
    v116 = v301;
  }
  int v311 = v116 * 2;
  int v117 = v23[v311];
  int * v118 = v15->regs;
  v118[5] = v117;
  struct StateT * v120 = v2->b;
  int * v121 = v120->cache_tags;
  int v122 = v121[0];
  int v123 = v121[1];
  int v124 = v121[8];
  int v125 = v121[9];
  int v126 = v120->timer;
  int v317 = v126 + ((100 ^ (((~(((v124 ^ 10) | (-(v124 ^ 10))) >> 31)) | (~(((v125 ^ 10) | (-(v125 ^ 10))) >> 31))) & 104)) ^ (((~(((v122 ^ 10) | (-(v122 ^ 10))) >> 31)) | (~(((v123 ^ 10) | (-(v123 ^ 10))) >> 31))) & (1 ^ (100 ^ (((~(((v124 ^ 10) | (-(v124 ^ 10))) >> 31)) | (~(((v125 ^ 10) | (-(v125 ^ 10))) >> 31))) & 104)))));
  v120->timer = v317;
  int * v128 = v120->cache_vals;
  bool v318 = !(((~(((v122 ^ 10) | (-(v122 ^ 10))) >> 31)) | (~(((v123 ^ 10) | (-(v123 ^ 10))) >> 31))) == 0);
  int v221;
  if (v318) {
    int * v129 = v120->cache_age;
    int v320 = (~(((v123 ^ 10) | (-(v123 ^ 10))) >> 31)) & 1;
    int v130 = v129[v320];
    int v131 = v129[0];
    int v321 = v131 + ((int)((unsigned int)(v131 - v130) >> 31));
    v129[0] = v321;
    int * v133 = v120->cache_age;
    int v134 = v133[1];
    int v323 = v134 + ((int)((unsigned int)(v134 - v130) >> 31));
    v133[1] = v323;
    int * v136 = v120->cache_age;
    v136[v320] = 0;
    v221 = v320;
  } else {
    int * v139 = v120->cache_age;
    int v140 = v139[0];
    int * v141 = v120->cache_tags;
    int v142 = v141[0];
    int v143 = v139[1];
    int v144 = v141[1];
    bool v327 = !(((~(((v124 ^ 10) | (-(v124 ^ 10))) >> 31)) | (~(((v125 ^ 10) | (-(v125 ^ 10))) >> 31))) == 0);
    int v198;
    if (v327) {
      int * v145 = v120->cache_age;
      int v329 = 8 + ((~(((v125 ^ 10) | (-(v125 ^ 10))) >> 31)) & 1);
      int v146 = v145[v329];
      int v147 = v145[8];
      int v330 = v147 + ((int)((unsigned int)(v147 - v146) >> 31));
      v145[8] = v330;
      int * v149 = v120->cache_age;
      int v150 = v149[9];
      int v332 = v150 + ((int)((unsigned int)(v150 - v146) >> 31));
      v149[9] = v332;
      int * v152 = v120->cache_age;
      v152[v329] = 0;
      v198 = v329;
    } else {
      int * v155 = v120->cache_age;
      int v156 = v155[8];
      int * v157 = v120->cache_tags;
      int v158 = v157[8];
      int v159 = v155[9];
      int v160 = v157[9];
      int * v161 = v120->cache_dirty;
      int v337 = 8 + ((((v156 + ((~(((v158 ^ -1) | (-(v158 ^ -1))) >> 31)) & 2)) - (v159 + ((~(((v160 ^ -1) | (-(v160 ^ -1))) >> 31)) & 2))) >> 31) & 1);
      int v162 = v161[v337];
      bool v338 = !(v162 == 0);
      if (v338) {
        int * v163 = v120->cache_tags;
        int v164 = v163[v337];
        int * v165 = v120->cache_vals;
        int v341 = (8 + ((((v156 + ((~(((v158 ^ -1) | (-(v158 ^ -1))) >> 31)) & 2)) - (v159 + ((~(((v160 ^ -1) | (-(v160 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
        int v166 = v165[v341];
        int v342 = ((8 + ((((v156 + ((~(((v158 ^ -1) | (-(v158 ^ -1))) >> 31)) & 2)) - (v159 + ((~(((v160 ^ -1) | (-(v160 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
        int v167 = v165[v342];
        int * v168 = v120->mem;
        int v344 = v164 * 2;
        v168[v344] = v166;
        int * v170 = v120->mem;
        int v347 = (v164 * 2) + 1;
        v170[v347] = v167;
        ;
      } else {
        ;
      }
      int * v175 = v120->mem;
      int v176 = v175[20];
      int v177 = v175[21];
      int * v178 = v120->cache_vals;
      int v355 = (8 + ((((v156 + ((~(((v158 ^ -1) | (-(v158 ^ -1))) >> 31)) & 2)) - (v159 + ((~(((v160 ^ -1) | (-(v160 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
      v178[v355] = v176;
      int * v180 = v120->cache_vals;
      int v358 = ((8 + ((((v156 + ((~(((v158 ^ -1) | (-(v158 ^ -1))) >> 31)) & 2)) - (v159 + ((~(((v160 ^ -1) | (-(v160 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
      v180[v358] = v177;
      int * v182 = v120->cache_tags;
      v182[v337] = 10;
      int * v184 = v120->cache_dirty;
      v184[v337] = 0;
      int * v186 = v120->cache_age;
      v186[v337] = 1;
      int * v188 = v120->cache_age;
      int v189 = v188[v337];
      int v190 = v188[8];
      int v365 = v190 + ((int)((unsigned int)(v190 - v189) >> 31));
      v188[8] = v365;
      int * v192 = v120->cache_age;
      int v193 = v192[9];
      int v367 = v193 + ((int)((unsigned int)(v193 - v189) >> 31));
      v192[9] = v367;
      int * v195 = v120->cache_age;
      v195[v337] = 0;
      v198 = v337;
    }
    int * v199 = v120->cache_vals;
    int v370 = v198 * 2;
    int v200 = v199[v370];
    int v371 = (v198 * 2) + 1;
    int v201 = v199[v371];
    int v372 = ((((v140 + ((~(((v142 ^ -1) | (-(v142 ^ -1))) >> 31)) & 2)) - (v143 + ((~(((v144 ^ -1) | (-(v144 ^ -1))) >> 31)) & 2))) >> 31) & 1) * 2;
    v199[v372] = v200;
    int * v203 = v120->cache_vals;
    int v375 = (((((v140 + ((~(((v142 ^ -1) | (-(v142 ^ -1))) >> 31)) & 2)) - (v143 + ((~(((v144 ^ -1) | (-(v144 ^ -1))) >> 31)) & 2))) >> 31) & 1) * 2) + 1;
    v203[v375] = v201;
    int * v205 = v120->cache_tags;
    int v378 = (((v140 + ((~(((v142 ^ -1) | (-(v142 ^ -1))) >> 31)) & 2)) - (v143 + ((~(((v144 ^ -1) | (-(v144 ^ -1))) >> 31)) & 2))) >> 31) & 1;
    v205[v378] = 10;
    int * v207 = v120->cache_dirty;
    v207[v378] = 0;
    int * v209 = v120->cache_age;
    v209[v378] = 1;
    int * v211 = v120->cache_age;
    int v212 = v211[v378];
    int v213 = v211[0];
    int v383 = v213 + ((int)((unsigned int)(v213 - v212) >> 31));
    v211[0] = v383;
    int * v215 = v120->cache_age;
    int v216 = v215[1];
    int v385 = v216 + ((int)((unsigned int)(v216 - v212) >> 31));
    v215[1] = v385;
    int * v218 = v120->cache_age;
    v218[v378] = 0;
    v221 = v378;
  }
  int v388 = v221 * 2;
  int v222 = v128[v388];
  int * v223 = v120->regs;
  v223[5] = v222;
  struct StateT2 * v225 = slot_1(v2);
  return v225;
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
  koika_assert(p_->a->timer==p_->b->timer, "timing leak");
  return 0;
}