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
struct StateT * slot_1(struct StateT * v24);
struct StateT * slot_8(struct StateT * v1299);
struct StateT * slot_6(struct StateT * v883);
struct StateT * slot_5(struct StateT * v684);
struct StateT * slot_4(struct StateT * v374);
struct StateT * slot_2(struct StateT * v46);
struct StateT * slot_7(struct StateT * v1091);
struct StateT * slot_3(struct StateT * v358);
struct StateT * slot_0(struct StateT * v2);
struct StateT * snippet(struct StateT * v0) {
  struct StateT * v1 = slot_0(v0);
  int v1504 = v1->timer;
  int * v1505 = v1->reg_ready;
  int v1506 = v1505[0];
  int v1637 = v1506 + ((v1504 - v1506) & (~((v1504 - v1506) >> 31)));
  v1->timer = v1637;
  int v1508 = v1->timer;
  int * v1509 = v1->reg_ready;
  int v1510 = v1509[1];
  int v1640 = v1510 + ((v1508 - v1510) & (~((v1508 - v1510) >> 31)));
  v1->timer = v1640;
  int v1512 = v1->timer;
  int * v1513 = v1->reg_ready;
  int v1514 = v1513[2];
  int v1643 = v1514 + ((v1512 - v1514) & (~((v1512 - v1514) >> 31)));
  v1->timer = v1643;
  int v1516 = v1->timer;
  int * v1517 = v1->reg_ready;
  int v1518 = v1517[3];
  int v1646 = v1518 + ((v1516 - v1518) & (~((v1516 - v1518) >> 31)));
  v1->timer = v1646;
  int v1520 = v1->timer;
  int * v1521 = v1->reg_ready;
  int v1522 = v1521[4];
  int v1649 = v1522 + ((v1520 - v1522) & (~((v1520 - v1522) >> 31)));
  v1->timer = v1649;
  int v1524 = v1->timer;
  int * v1525 = v1->reg_ready;
  int v1526 = v1525[5];
  int v1652 = v1526 + ((v1524 - v1526) & (~((v1524 - v1526) >> 31)));
  v1->timer = v1652;
  int v1528 = v1->timer;
  int * v1529 = v1->reg_ready;
  int v1530 = v1529[6];
  int v1655 = v1530 + ((v1528 - v1530) & (~((v1528 - v1530) >> 31)));
  v1->timer = v1655;
  int v1532 = v1->timer;
  int * v1533 = v1->reg_ready;
  int v1534 = v1533[7];
  int v1658 = v1534 + ((v1532 - v1534) & (~((v1532 - v1534) >> 31)));
  v1->timer = v1658;
  int v1536 = v1->timer;
  int * v1537 = v1->reg_ready;
  int v1538 = v1537[8];
  int v1661 = v1538 + ((v1536 - v1538) & (~((v1536 - v1538) >> 31)));
  v1->timer = v1661;
  int v1540 = v1->timer;
  int * v1541 = v1->reg_ready;
  int v1542 = v1541[9];
  int v1664 = v1542 + ((v1540 - v1542) & (~((v1540 - v1542) >> 31)));
  v1->timer = v1664;
  int v1544 = v1->timer;
  int * v1545 = v1->reg_ready;
  int v1546 = v1545[10];
  int v1667 = v1546 + ((v1544 - v1546) & (~((v1544 - v1546) >> 31)));
  v1->timer = v1667;
  int v1548 = v1->timer;
  int * v1549 = v1->reg_ready;
  int v1550 = v1549[11];
  int v1670 = v1550 + ((v1548 - v1550) & (~((v1548 - v1550) >> 31)));
  v1->timer = v1670;
  int v1552 = v1->timer;
  int * v1553 = v1->reg_ready;
  int v1554 = v1553[12];
  int v1673 = v1554 + ((v1552 - v1554) & (~((v1552 - v1554) >> 31)));
  v1->timer = v1673;
  int v1556 = v1->timer;
  int * v1557 = v1->reg_ready;
  int v1558 = v1557[13];
  int v1676 = v1558 + ((v1556 - v1558) & (~((v1556 - v1558) >> 31)));
  v1->timer = v1676;
  int v1560 = v1->timer;
  int * v1561 = v1->reg_ready;
  int v1562 = v1561[14];
  int v1679 = v1562 + ((v1560 - v1562) & (~((v1560 - v1562) >> 31)));
  v1->timer = v1679;
  int v1564 = v1->timer;
  int * v1565 = v1->reg_ready;
  int v1566 = v1565[15];
  int v1682 = v1566 + ((v1564 - v1566) & (~((v1564 - v1566) >> 31)));
  v1->timer = v1682;
  int v1568 = v1->timer;
  int * v1569 = v1->reg_ready;
  int v1570 = v1569[16];
  int v1685 = v1570 + ((v1568 - v1570) & (~((v1568 - v1570) >> 31)));
  v1->timer = v1685;
  int v1572 = v1->timer;
  int * v1573 = v1->reg_ready;
  int v1574 = v1573[17];
  int v1688 = v1574 + ((v1572 - v1574) & (~((v1572 - v1574) >> 31)));
  v1->timer = v1688;
  int v1576 = v1->timer;
  int * v1577 = v1->reg_ready;
  int v1578 = v1577[18];
  int v1691 = v1578 + ((v1576 - v1578) & (~((v1576 - v1578) >> 31)));
  v1->timer = v1691;
  int v1580 = v1->timer;
  int * v1581 = v1->reg_ready;
  int v1582 = v1581[19];
  int v1694 = v1582 + ((v1580 - v1582) & (~((v1580 - v1582) >> 31)));
  v1->timer = v1694;
  int v1584 = v1->timer;
  int * v1585 = v1->reg_ready;
  int v1586 = v1585[20];
  int v1697 = v1586 + ((v1584 - v1586) & (~((v1584 - v1586) >> 31)));
  v1->timer = v1697;
  int v1588 = v1->timer;
  int * v1589 = v1->reg_ready;
  int v1590 = v1589[21];
  int v1700 = v1590 + ((v1588 - v1590) & (~((v1588 - v1590) >> 31)));
  v1->timer = v1700;
  int v1592 = v1->timer;
  int * v1593 = v1->reg_ready;
  int v1594 = v1593[22];
  int v1703 = v1594 + ((v1592 - v1594) & (~((v1592 - v1594) >> 31)));
  v1->timer = v1703;
  int v1596 = v1->timer;
  int * v1597 = v1->reg_ready;
  int v1598 = v1597[23];
  int v1706 = v1598 + ((v1596 - v1598) & (~((v1596 - v1598) >> 31)));
  v1->timer = v1706;
  int v1600 = v1->timer;
  int * v1601 = v1->reg_ready;
  int v1602 = v1601[24];
  int v1709 = v1602 + ((v1600 - v1602) & (~((v1600 - v1602) >> 31)));
  v1->timer = v1709;
  int v1604 = v1->timer;
  int * v1605 = v1->reg_ready;
  int v1606 = v1605[25];
  int v1712 = v1606 + ((v1604 - v1606) & (~((v1604 - v1606) >> 31)));
  v1->timer = v1712;
  int v1608 = v1->timer;
  int * v1609 = v1->reg_ready;
  int v1610 = v1609[26];
  int v1715 = v1610 + ((v1608 - v1610) & (~((v1608 - v1610) >> 31)));
  v1->timer = v1715;
  int v1612 = v1->timer;
  int * v1613 = v1->reg_ready;
  int v1614 = v1613[27];
  int v1718 = v1614 + ((v1612 - v1614) & (~((v1612 - v1614) >> 31)));
  v1->timer = v1718;
  int v1616 = v1->timer;
  int * v1617 = v1->reg_ready;
  int v1618 = v1617[28];
  int v1721 = v1618 + ((v1616 - v1618) & (~((v1616 - v1618) >> 31)));
  v1->timer = v1721;
  int v1620 = v1->timer;
  int * v1621 = v1->reg_ready;
  int v1622 = v1621[29];
  int v1724 = v1622 + ((v1620 - v1622) & (~((v1620 - v1622) >> 31)));
  v1->timer = v1724;
  int v1624 = v1->timer;
  int * v1625 = v1->reg_ready;
  int v1626 = v1625[30];
  int v1727 = v1626 + ((v1624 - v1626) & (~((v1624 - v1626) >> 31)));
  v1->timer = v1727;
  int v1628 = v1->timer;
  int * v1629 = v1->reg_ready;
  int v1630 = v1629[31];
  int v1730 = v1630 + ((v1628 - v1630) & (~((v1628 - v1630) >> 31)));
  v1->timer = v1730;
  return v1;
}

struct StateT * slot_1(struct StateT * v24) {
  int v25 = v24->timer;
  int v36 = v25 + 1;
  v24->timer = v36;
  int * v27 = v24->reg_ready;
  int v28 = v27[5];
  int * v29 = v24->regs;
  int v30 = v29[5];
  int v41 = (v28 + ((v25 - v28) & (~((v25 - v28) >> 31)))) + 1;
  v27[6] = v41;
  int * v32 = v24->regs;
  int v43 = v30 + 80;
  v32[6] = v43;
  struct StateT * v34 = slot_2(v24);
  return v34;
}

struct StateT * slot_8(struct StateT * v1299) {
  int v1300 = v1299->timer;
  int v1411 = v1300 + 1;
  v1299->timer = v1411;
  int * v1302 = v1299->reg_ready;
  int v1303 = v1302[11];
  int * v1304 = v1299->regs;
  int v1305 = v1304[11];
  int * v1306 = v1299->cache_tags;
  int v1416 = (((int)((unsigned int)((int)((unsigned int)v1305 >> 2)) >> 1)) & 1) * 2;
  int v1307 = v1306[v1416];
  int v1417 = ((((int)((unsigned int)((int)((unsigned int)v1305 >> 2)) >> 1)) & 1) * 2) + 1;
  int v1308 = v1306[v1417];
  int v1418 = 4 + ((((int)((unsigned int)((int)((unsigned int)v1305 >> 2)) >> 1)) & 3) * 2);
  int v1309 = v1306[v1418];
  int v1419 = (4 + ((((int)((unsigned int)((int)((unsigned int)v1305 >> 2)) >> 1)) & 3) * 2)) + 1;
  int v1310 = v1306[v1419];
  int * v1311 = v1299->cache_vals;
  bool v1420 = !(((~(((v1307 ^ ((int)((unsigned int)((int)((unsigned int)v1305 >> 2)) >> 1))) | (-(v1307 ^ ((int)((unsigned int)((int)((unsigned int)v1305 >> 2)) >> 1))))) >> 31)) | (~(((v1308 ^ ((int)((unsigned int)((int)((unsigned int)v1305 >> 2)) >> 1))) | (-(v1308 ^ ((int)((unsigned int)((int)((unsigned int)v1305 >> 2)) >> 1))))) >> 31))) == 0);
  int v1404;
  if (v1420) {
    int * v1312 = v1299->cache_age;
    int v1422 = ((((int)((unsigned int)((int)((unsigned int)v1305 >> 2)) >> 1)) & 1) * 2) + ((~(((v1308 ^ ((int)((unsigned int)((int)((unsigned int)v1305 >> 2)) >> 1))) | (-(v1308 ^ ((int)((unsigned int)((int)((unsigned int)v1305 >> 2)) >> 1))))) >> 31)) & 1);
    int v1313 = v1312[v1422];
    int v1314 = v1312[v1416];
    int v1423 = v1314 + ((int)((unsigned int)(v1314 - v1313) >> 31));
    v1312[v1416] = v1423;
    int * v1316 = v1299->cache_age;
    int v1317 = v1316[v1417];
    int v1425 = v1317 + ((int)((unsigned int)(v1317 - v1313) >> 31));
    v1316[v1417] = v1425;
    int * v1319 = v1299->cache_age;
    v1319[v1422] = 0;
    v1404 = v1422;
  } else {
    int * v1322 = v1299->cache_age;
    int v1429 = (((int)((unsigned int)((int)((unsigned int)v1305 >> 2)) >> 1)) & 1) * 2;
    int v1323 = v1322[v1429];
    int * v1324 = v1299->cache_tags;
    int v1325 = v1324[v1429];
    int v1326 = v1322[v1417];
    int v1327 = v1324[v1417];
    bool v1431 = !(((~(((v1309 ^ ((int)((unsigned int)((int)((unsigned int)v1305 >> 2)) >> 1))) | (-(v1309 ^ ((int)((unsigned int)((int)((unsigned int)v1305 >> 2)) >> 1))))) >> 31)) | (~(((v1310 ^ ((int)((unsigned int)((int)((unsigned int)v1305 >> 2)) >> 1))) | (-(v1310 ^ ((int)((unsigned int)((int)((unsigned int)v1305 >> 2)) >> 1))))) >> 31))) == 0);
    int v1381;
    if (v1431) {
      int * v1328 = v1299->cache_age;
      int v1433 = (4 + ((((int)((unsigned int)((int)((unsigned int)v1305 >> 2)) >> 1)) & 3) * 2)) + ((~(((v1310 ^ ((int)((unsigned int)((int)((unsigned int)v1305 >> 2)) >> 1))) | (-(v1310 ^ ((int)((unsigned int)((int)((unsigned int)v1305 >> 2)) >> 1))))) >> 31)) & 1);
      int v1329 = v1328[v1433];
      int v1330 = v1328[v1418];
      int v1434 = v1330 + ((int)((unsigned int)(v1330 - v1329) >> 31));
      v1328[v1418] = v1434;
      int * v1332 = v1299->cache_age;
      int v1333 = v1332[v1419];
      int v1436 = v1333 + ((int)((unsigned int)(v1333 - v1329) >> 31));
      v1332[v1419] = v1436;
      int * v1335 = v1299->cache_age;
      v1335[v1433] = 0;
      v1381 = v1433;
    } else {
      int * v1338 = v1299->cache_age;
      int v1440 = 4 + ((((int)((unsigned int)((int)((unsigned int)v1305 >> 2)) >> 1)) & 3) * 2);
      int v1339 = v1338[v1440];
      int * v1340 = v1299->cache_tags;
      int v1341 = v1340[v1440];
      int v1342 = v1338[v1419];
      int v1343 = v1340[v1419];
      int * v1344 = v1299->cache_dirty;
      int v1443 = (4 + ((((int)((unsigned int)((int)((unsigned int)v1305 >> 2)) >> 1)) & 3) * 2)) + ((((v1339 + ((~(((v1341 ^ -1) | (-(v1341 ^ -1))) >> 31)) & 2)) - (v1342 + ((~(((v1343 ^ -1) | (-(v1343 ^ -1))) >> 31)) & 2))) >> 31) & 1);
      int v1345 = v1344[v1443];
      bool v1444 = !(v1345 == 0);
      if (v1444) {
        int * v1346 = v1299->cache_tags;
        int v1347 = v1346[v1443];
        int * v1348 = v1299->cache_vals;
        int v1447 = ((4 + ((((int)((unsigned int)((int)((unsigned int)v1305 >> 2)) >> 1)) & 3) * 2)) + ((((v1339 + ((~(((v1341 ^ -1) | (-(v1341 ^ -1))) >> 31)) & 2)) - (v1342 + ((~(((v1343 ^ -1) | (-(v1343 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
        int v1349 = v1348[v1447];
        int v1448 = (((4 + ((((int)((unsigned int)((int)((unsigned int)v1305 >> 2)) >> 1)) & 3) * 2)) + ((((v1339 + ((~(((v1341 ^ -1) | (-(v1341 ^ -1))) >> 31)) & 2)) - (v1342 + ((~(((v1343 ^ -1) | (-(v1343 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
        int v1350 = v1348[v1448];
        int * v1351 = v1299->mem;
        int v1450 = v1347 * 2;
        v1351[v1450] = v1349;
        int * v1353 = v1299->mem;
        int v1453 = (v1347 * 2) + 1;
        v1353[v1453] = v1350;
        ;
      } else {
        ;
      }
      int * v1358 = v1299->mem;
      int v1458 = ((int)((unsigned int)((int)((unsigned int)v1305 >> 2)) >> 1)) * 2;
      int v1359 = v1358[v1458];
      int v1459 = (((int)((unsigned int)((int)((unsigned int)v1305 >> 2)) >> 1)) * 2) + 1;
      int v1360 = v1358[v1459];
      int * v1361 = v1299->cache_vals;
      int v1461 = ((4 + ((((int)((unsigned int)((int)((unsigned int)v1305 >> 2)) >> 1)) & 3) * 2)) + ((((v1339 + ((~(((v1341 ^ -1) | (-(v1341 ^ -1))) >> 31)) & 2)) - (v1342 + ((~(((v1343 ^ -1) | (-(v1343 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
      v1361[v1461] = v1359;
      int * v1363 = v1299->cache_vals;
      int v1464 = (((4 + ((((int)((unsigned int)((int)((unsigned int)v1305 >> 2)) >> 1)) & 3) * 2)) + ((((v1339 + ((~(((v1341 ^ -1) | (-(v1341 ^ -1))) >> 31)) & 2)) - (v1342 + ((~(((v1343 ^ -1) | (-(v1343 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
      v1363[v1464] = v1360;
      int * v1365 = v1299->cache_tags;
      int v1467 = (int)((unsigned int)((int)((unsigned int)v1305 >> 2)) >> 1);
      v1365[v1443] = v1467;
      int * v1367 = v1299->cache_dirty;
      v1367[v1443] = 0;
      int * v1369 = v1299->cache_age;
      v1369[v1443] = 1;
      int * v1371 = v1299->cache_age;
      int v1372 = v1371[v1443];
      int v1373 = v1371[v1418];
      int v1473 = v1373 + ((int)((unsigned int)(v1373 - v1372) >> 31));
      v1371[v1418] = v1473;
      int * v1375 = v1299->cache_age;
      int v1376 = v1375[v1419];
      int v1475 = v1376 + ((int)((unsigned int)(v1376 - v1372) >> 31));
      v1375[v1419] = v1475;
      int * v1378 = v1299->cache_age;
      v1378[v1443] = 0;
      v1381 = v1443;
    }
    int * v1382 = v1299->cache_vals;
    int v1478 = v1381 * 2;
    int v1383 = v1382[v1478];
    int v1479 = (v1381 * 2) + 1;
    int v1384 = v1382[v1479];
    int v1480 = (((((int)((unsigned int)((int)((unsigned int)v1305 >> 2)) >> 1)) & 1) * 2) + ((((v1323 + ((~(((v1325 ^ -1) | (-(v1325 ^ -1))) >> 31)) & 2)) - (v1326 + ((~(((v1327 ^ -1) | (-(v1327 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
    v1382[v1480] = v1383;
    int * v1386 = v1299->cache_vals;
    int v1483 = ((((((int)((unsigned int)((int)((unsigned int)v1305 >> 2)) >> 1)) & 1) * 2) + ((((v1323 + ((~(((v1325 ^ -1) | (-(v1325 ^ -1))) >> 31)) & 2)) - (v1326 + ((~(((v1327 ^ -1) | (-(v1327 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
    v1386[v1483] = v1384;
    int * v1388 = v1299->cache_tags;
    int v1486 = ((((int)((unsigned int)((int)((unsigned int)v1305 >> 2)) >> 1)) & 1) * 2) + ((((v1323 + ((~(((v1325 ^ -1) | (-(v1325 ^ -1))) >> 31)) & 2)) - (v1326 + ((~(((v1327 ^ -1) | (-(v1327 ^ -1))) >> 31)) & 2))) >> 31) & 1);
    int v1487 = (int)((unsigned int)((int)((unsigned int)v1305 >> 2)) >> 1);
    v1388[v1486] = v1487;
    int * v1390 = v1299->cache_dirty;
    v1390[v1486] = 0;
    int * v1392 = v1299->cache_age;
    v1392[v1486] = 1;
    int * v1394 = v1299->cache_age;
    int v1395 = v1394[v1486];
    int v1396 = v1394[v1416];
    int v1493 = v1396 + ((int)((unsigned int)(v1396 - v1395) >> 31));
    v1394[v1416] = v1493;
    int * v1398 = v1299->cache_age;
    int v1399 = v1398[v1417];
    int v1495 = v1399 + ((int)((unsigned int)(v1399 - v1395) >> 31));
    v1398[v1417] = v1495;
    int * v1401 = v1299->cache_age;
    v1401[v1486] = 0;
    v1404 = v1486;
  }
  int v1498 = (v1404 * 2) + (((int)((unsigned int)v1305 >> 2)) & 1);
  int v1405 = v1311[v1498];
  int * v1406 = v1299->reg_ready;
  int v1501 = ((v1303 + ((v1300 - v1303) & (~((v1300 - v1303) >> 31)))) + 1) + ((100 ^ (((~(((v1309 ^ ((int)((unsigned int)((int)((unsigned int)v1305 >> 2)) >> 1))) | (-(v1309 ^ ((int)((unsigned int)((int)((unsigned int)v1305 >> 2)) >> 1))))) >> 31)) | (~(((v1310 ^ ((int)((unsigned int)((int)((unsigned int)v1305 >> 2)) >> 1))) | (-(v1310 ^ ((int)((unsigned int)((int)((unsigned int)v1305 >> 2)) >> 1))))) >> 31))) & 104)) ^ (((~(((v1307 ^ ((int)((unsigned int)((int)((unsigned int)v1305 >> 2)) >> 1))) | (-(v1307 ^ ((int)((unsigned int)((int)((unsigned int)v1305 >> 2)) >> 1))))) >> 31)) | (~(((v1308 ^ ((int)((unsigned int)((int)((unsigned int)v1305 >> 2)) >> 1))) | (-(v1308 ^ ((int)((unsigned int)((int)((unsigned int)v1305 >> 2)) >> 1))))) >> 31))) & (1 ^ (100 ^ (((~(((v1309 ^ ((int)((unsigned int)((int)((unsigned int)v1305 >> 2)) >> 1))) | (-(v1309 ^ ((int)((unsigned int)((int)((unsigned int)v1305 >> 2)) >> 1))))) >> 31)) | (~(((v1310 ^ ((int)((unsigned int)((int)((unsigned int)v1305 >> 2)) >> 1))) | (-(v1310 ^ ((int)((unsigned int)((int)((unsigned int)v1305 >> 2)) >> 1))))) >> 31))) & 104)))));
  v1406[12] = v1501;
  int * v1408 = v1299->regs;
  v1408[12] = v1405;
  return v1299;
}

struct StateT * slot_6(struct StateT * v883) {
  int v884 = v883->timer;
  int v996 = v884 + 1;
  v883->timer = v996;
  int * v886 = v883->reg_ready;
  int v887 = v886[8];
  int * v888 = v883->regs;
  int v889 = v888[8];
  int * v890 = v883->cache_tags;
  int v1001 = (((int)((unsigned int)((int)((unsigned int)(v889 + 40) >> 2)) >> 1)) & 1) * 2;
  int v891 = v890[v1001];
  int v1002 = ((((int)((unsigned int)((int)((unsigned int)(v889 + 40) >> 2)) >> 1)) & 1) * 2) + 1;
  int v892 = v890[v1002];
  int v1003 = 4 + ((((int)((unsigned int)((int)((unsigned int)(v889 + 40) >> 2)) >> 1)) & 3) * 2);
  int v893 = v890[v1003];
  int v1004 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v889 + 40) >> 2)) >> 1)) & 3) * 2)) + 1;
  int v894 = v890[v1004];
  int * v895 = v883->cache_vals;
  bool v1005 = !(((~(((v891 ^ ((int)((unsigned int)((int)((unsigned int)(v889 + 40) >> 2)) >> 1))) | (-(v891 ^ ((int)((unsigned int)((int)((unsigned int)(v889 + 40) >> 2)) >> 1))))) >> 31)) | (~(((v892 ^ ((int)((unsigned int)((int)((unsigned int)(v889 + 40) >> 2)) >> 1))) | (-(v892 ^ ((int)((unsigned int)((int)((unsigned int)(v889 + 40) >> 2)) >> 1))))) >> 31))) == 0);
  int v988;
  if (v1005) {
    int * v896 = v883->cache_age;
    int v1007 = ((((int)((unsigned int)((int)((unsigned int)(v889 + 40) >> 2)) >> 1)) & 1) * 2) + ((~(((v892 ^ ((int)((unsigned int)((int)((unsigned int)(v889 + 40) >> 2)) >> 1))) | (-(v892 ^ ((int)((unsigned int)((int)((unsigned int)(v889 + 40) >> 2)) >> 1))))) >> 31)) & 1);
    int v897 = v896[v1007];
    int v898 = v896[v1001];
    int v1008 = v898 + ((int)((unsigned int)(v898 - v897) >> 31));
    v896[v1001] = v1008;
    int * v900 = v883->cache_age;
    int v901 = v900[v1002];
    int v1010 = v901 + ((int)((unsigned int)(v901 - v897) >> 31));
    v900[v1002] = v1010;
    int * v903 = v883->cache_age;
    v903[v1007] = 0;
    v988 = v1007;
  } else {
    int * v906 = v883->cache_age;
    int v1014 = (((int)((unsigned int)((int)((unsigned int)(v889 + 40) >> 2)) >> 1)) & 1) * 2;
    int v907 = v906[v1014];
    int * v908 = v883->cache_tags;
    int v909 = v908[v1014];
    int v910 = v906[v1002];
    int v911 = v908[v1002];
    bool v1016 = !(((~(((v893 ^ ((int)((unsigned int)((int)((unsigned int)(v889 + 40) >> 2)) >> 1))) | (-(v893 ^ ((int)((unsigned int)((int)((unsigned int)(v889 + 40) >> 2)) >> 1))))) >> 31)) | (~(((v894 ^ ((int)((unsigned int)((int)((unsigned int)(v889 + 40) >> 2)) >> 1))) | (-(v894 ^ ((int)((unsigned int)((int)((unsigned int)(v889 + 40) >> 2)) >> 1))))) >> 31))) == 0);
    int v965;
    if (v1016) {
      int * v912 = v883->cache_age;
      int v1018 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v889 + 40) >> 2)) >> 1)) & 3) * 2)) + ((~(((v894 ^ ((int)((unsigned int)((int)((unsigned int)(v889 + 40) >> 2)) >> 1))) | (-(v894 ^ ((int)((unsigned int)((int)((unsigned int)(v889 + 40) >> 2)) >> 1))))) >> 31)) & 1);
      int v913 = v912[v1018];
      int v914 = v912[v1003];
      int v1019 = v914 + ((int)((unsigned int)(v914 - v913) >> 31));
      v912[v1003] = v1019;
      int * v916 = v883->cache_age;
      int v917 = v916[v1004];
      int v1021 = v917 + ((int)((unsigned int)(v917 - v913) >> 31));
      v916[v1004] = v1021;
      int * v919 = v883->cache_age;
      v919[v1018] = 0;
      v965 = v1018;
    } else {
      int * v922 = v883->cache_age;
      int v1025 = 4 + ((((int)((unsigned int)((int)((unsigned int)(v889 + 40) >> 2)) >> 1)) & 3) * 2);
      int v923 = v922[v1025];
      int * v924 = v883->cache_tags;
      int v925 = v924[v1025];
      int v926 = v922[v1004];
      int v927 = v924[v1004];
      int * v928 = v883->cache_dirty;
      int v1028 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v889 + 40) >> 2)) >> 1)) & 3) * 2)) + ((((v923 + ((~(((v925 ^ -1) | (-(v925 ^ -1))) >> 31)) & 2)) - (v926 + ((~(((v927 ^ -1) | (-(v927 ^ -1))) >> 31)) & 2))) >> 31) & 1);
      int v929 = v928[v1028];
      bool v1029 = !(v929 == 0);
      if (v1029) {
        int * v930 = v883->cache_tags;
        int v931 = v930[v1028];
        int * v932 = v883->cache_vals;
        int v1032 = ((4 + ((((int)((unsigned int)((int)((unsigned int)(v889 + 40) >> 2)) >> 1)) & 3) * 2)) + ((((v923 + ((~(((v925 ^ -1) | (-(v925 ^ -1))) >> 31)) & 2)) - (v926 + ((~(((v927 ^ -1) | (-(v927 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
        int v933 = v932[v1032];
        int v1033 = (((4 + ((((int)((unsigned int)((int)((unsigned int)(v889 + 40) >> 2)) >> 1)) & 3) * 2)) + ((((v923 + ((~(((v925 ^ -1) | (-(v925 ^ -1))) >> 31)) & 2)) - (v926 + ((~(((v927 ^ -1) | (-(v927 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
        int v934 = v932[v1033];
        int * v935 = v883->mem;
        int v1035 = v931 * 2;
        v935[v1035] = v933;
        int * v937 = v883->mem;
        int v1038 = (v931 * 2) + 1;
        v937[v1038] = v934;
        ;
      } else {
        ;
      }
      int * v942 = v883->mem;
      int v1043 = ((int)((unsigned int)((int)((unsigned int)(v889 + 40) >> 2)) >> 1)) * 2;
      int v943 = v942[v1043];
      int v1044 = (((int)((unsigned int)((int)((unsigned int)(v889 + 40) >> 2)) >> 1)) * 2) + 1;
      int v944 = v942[v1044];
      int * v945 = v883->cache_vals;
      int v1046 = ((4 + ((((int)((unsigned int)((int)((unsigned int)(v889 + 40) >> 2)) >> 1)) & 3) * 2)) + ((((v923 + ((~(((v925 ^ -1) | (-(v925 ^ -1))) >> 31)) & 2)) - (v926 + ((~(((v927 ^ -1) | (-(v927 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
      v945[v1046] = v943;
      int * v947 = v883->cache_vals;
      int v1049 = (((4 + ((((int)((unsigned int)((int)((unsigned int)(v889 + 40) >> 2)) >> 1)) & 3) * 2)) + ((((v923 + ((~(((v925 ^ -1) | (-(v925 ^ -1))) >> 31)) & 2)) - (v926 + ((~(((v927 ^ -1) | (-(v927 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
      v947[v1049] = v944;
      int * v949 = v883->cache_tags;
      int v1052 = (int)((unsigned int)((int)((unsigned int)(v889 + 40) >> 2)) >> 1);
      v949[v1028] = v1052;
      int * v951 = v883->cache_dirty;
      v951[v1028] = 0;
      int * v953 = v883->cache_age;
      v953[v1028] = 1;
      int * v955 = v883->cache_age;
      int v956 = v955[v1028];
      int v957 = v955[v1003];
      int v1058 = v957 + ((int)((unsigned int)(v957 - v956) >> 31));
      v955[v1003] = v1058;
      int * v959 = v883->cache_age;
      int v960 = v959[v1004];
      int v1060 = v960 + ((int)((unsigned int)(v960 - v956) >> 31));
      v959[v1004] = v1060;
      int * v962 = v883->cache_age;
      v962[v1028] = 0;
      v965 = v1028;
    }
    int * v966 = v883->cache_vals;
    int v1063 = v965 * 2;
    int v967 = v966[v1063];
    int v1064 = (v965 * 2) + 1;
    int v968 = v966[v1064];
    int v1065 = (((((int)((unsigned int)((int)((unsigned int)(v889 + 40) >> 2)) >> 1)) & 1) * 2) + ((((v907 + ((~(((v909 ^ -1) | (-(v909 ^ -1))) >> 31)) & 2)) - (v910 + ((~(((v911 ^ -1) | (-(v911 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
    v966[v1065] = v967;
    int * v970 = v883->cache_vals;
    int v1068 = ((((((int)((unsigned int)((int)((unsigned int)(v889 + 40) >> 2)) >> 1)) & 1) * 2) + ((((v907 + ((~(((v909 ^ -1) | (-(v909 ^ -1))) >> 31)) & 2)) - (v910 + ((~(((v911 ^ -1) | (-(v911 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
    v970[v1068] = v968;
    int * v972 = v883->cache_tags;
    int v1071 = ((((int)((unsigned int)((int)((unsigned int)(v889 + 40) >> 2)) >> 1)) & 1) * 2) + ((((v907 + ((~(((v909 ^ -1) | (-(v909 ^ -1))) >> 31)) & 2)) - (v910 + ((~(((v911 ^ -1) | (-(v911 ^ -1))) >> 31)) & 2))) >> 31) & 1);
    int v1072 = (int)((unsigned int)((int)((unsigned int)(v889 + 40) >> 2)) >> 1);
    v972[v1071] = v1072;
    int * v974 = v883->cache_dirty;
    v974[v1071] = 0;
    int * v976 = v883->cache_age;
    v976[v1071] = 1;
    int * v978 = v883->cache_age;
    int v979 = v978[v1071];
    int v980 = v978[v1001];
    int v1078 = v980 + ((int)((unsigned int)(v980 - v979) >> 31));
    v978[v1001] = v1078;
    int * v982 = v883->cache_age;
    int v983 = v982[v1002];
    int v1080 = v983 + ((int)((unsigned int)(v983 - v979) >> 31));
    v982[v1002] = v1080;
    int * v985 = v883->cache_age;
    v985[v1071] = 0;
    v988 = v1071;
  }
  int v1083 = (v988 * 2) + (((int)((unsigned int)(v889 + 40) >> 2)) & 1);
  int v989 = v895[v1083];
  int * v990 = v883->reg_ready;
  int v1086 = ((v887 + ((v884 - v887) & (~((v884 - v887) >> 31)))) + 1) + ((100 ^ (((~(((v893 ^ ((int)((unsigned int)((int)((unsigned int)(v889 + 40) >> 2)) >> 1))) | (-(v893 ^ ((int)((unsigned int)((int)((unsigned int)(v889 + 40) >> 2)) >> 1))))) >> 31)) | (~(((v894 ^ ((int)((unsigned int)((int)((unsigned int)(v889 + 40) >> 2)) >> 1))) | (-(v894 ^ ((int)((unsigned int)((int)((unsigned int)(v889 + 40) >> 2)) >> 1))))) >> 31))) & 104)) ^ (((~(((v891 ^ ((int)((unsigned int)((int)((unsigned int)(v889 + 40) >> 2)) >> 1))) | (-(v891 ^ ((int)((unsigned int)((int)((unsigned int)(v889 + 40) >> 2)) >> 1))))) >> 31)) | (~(((v892 ^ ((int)((unsigned int)((int)((unsigned int)(v889 + 40) >> 2)) >> 1))) | (-(v892 ^ ((int)((unsigned int)((int)((unsigned int)(v889 + 40) >> 2)) >> 1))))) >> 31))) & (1 ^ (100 ^ (((~(((v893 ^ ((int)((unsigned int)((int)((unsigned int)(v889 + 40) >> 2)) >> 1))) | (-(v893 ^ ((int)((unsigned int)((int)((unsigned int)(v889 + 40) >> 2)) >> 1))))) >> 31)) | (~(((v894 ^ ((int)((unsigned int)((int)((unsigned int)(v889 + 40) >> 2)) >> 1))) | (-(v894 ^ ((int)((unsigned int)((int)((unsigned int)(v889 + 40) >> 2)) >> 1))))) >> 31))) & 104)))));
  v990[9] = v1086;
  int * v992 = v883->regs;
  v992[9] = v989;
  struct StateT * v994 = slot_7(v883);
  return v994;
}

struct StateT * slot_5(struct StateT * v684) {
  int v685 = v684->timer;
  int v793 = v685 + 1;
  v684->timer = v793;
  int * v687 = v684->cache_tags;
  int v688 = v687[2];
  int v689 = v687[3];
  int v690 = v687[10];
  int v691 = v687[11];
  int * v692 = v684->cache_vals;
  bool v799 = !(((~(((v688 ^ 7) | (-(v688 ^ 7))) >> 31)) | (~(((v689 ^ 7) | (-(v689 ^ 7))) >> 31))) == 0);
  int v785;
  if (v799) {
    int * v693 = v684->cache_age;
    int v801 = 2 + ((~(((v689 ^ 7) | (-(v689 ^ 7))) >> 31)) & 1);
    int v694 = v693[v801];
    int v695 = v693[2];
    int v802 = v695 + ((int)((unsigned int)(v695 - v694) >> 31));
    v693[2] = v802;
    int * v697 = v684->cache_age;
    int v698 = v697[3];
    int v804 = v698 + ((int)((unsigned int)(v698 - v694) >> 31));
    v697[3] = v804;
    int * v700 = v684->cache_age;
    v700[v801] = 0;
    v785 = v801;
  } else {
    int * v703 = v684->cache_age;
    int v704 = v703[2];
    int * v705 = v684->cache_tags;
    int v706 = v705[2];
    int v707 = v703[3];
    int v708 = v705[3];
    bool v809 = !(((~(((v690 ^ 7) | (-(v690 ^ 7))) >> 31)) | (~(((v691 ^ 7) | (-(v691 ^ 7))) >> 31))) == 0);
    int v762;
    if (v809) {
      int * v709 = v684->cache_age;
      int v811 = 10 + ((~(((v691 ^ 7) | (-(v691 ^ 7))) >> 31)) & 1);
      int v710 = v709[v811];
      int v711 = v709[10];
      int v812 = v711 + ((int)((unsigned int)(v711 - v710) >> 31));
      v709[10] = v812;
      int * v713 = v684->cache_age;
      int v714 = v713[11];
      int v814 = v714 + ((int)((unsigned int)(v714 - v710) >> 31));
      v713[11] = v814;
      int * v716 = v684->cache_age;
      v716[v811] = 0;
      v762 = v811;
    } else {
      int * v719 = v684->cache_age;
      int v720 = v719[10];
      int * v721 = v684->cache_tags;
      int v722 = v721[10];
      int v723 = v719[11];
      int v724 = v721[11];
      int * v725 = v684->cache_dirty;
      int v820 = 10 + ((((v720 + ((~(((v722 ^ -1) | (-(v722 ^ -1))) >> 31)) & 2)) - (v723 + ((~(((v724 ^ -1) | (-(v724 ^ -1))) >> 31)) & 2))) >> 31) & 1);
      int v726 = v725[v820];
      bool v821 = !(v726 == 0);
      if (v821) {
        int * v727 = v684->cache_tags;
        int v728 = v727[v820];
        int * v729 = v684->cache_vals;
        int v824 = (10 + ((((v720 + ((~(((v722 ^ -1) | (-(v722 ^ -1))) >> 31)) & 2)) - (v723 + ((~(((v724 ^ -1) | (-(v724 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
        int v730 = v729[v824];
        int v825 = ((10 + ((((v720 + ((~(((v722 ^ -1) | (-(v722 ^ -1))) >> 31)) & 2)) - (v723 + ((~(((v724 ^ -1) | (-(v724 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
        int v731 = v729[v825];
        int * v732 = v684->mem;
        int v827 = v728 * 2;
        v732[v827] = v730;
        int * v734 = v684->mem;
        int v830 = (v728 * 2) + 1;
        v734[v830] = v731;
        ;
      } else {
        ;
      }
      int * v739 = v684->mem;
      int v740 = v739[14];
      int v741 = v739[15];
      int * v742 = v684->cache_vals;
      int v838 = (10 + ((((v720 + ((~(((v722 ^ -1) | (-(v722 ^ -1))) >> 31)) & 2)) - (v723 + ((~(((v724 ^ -1) | (-(v724 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
      v742[v838] = v740;
      int * v744 = v684->cache_vals;
      int v841 = ((10 + ((((v720 + ((~(((v722 ^ -1) | (-(v722 ^ -1))) >> 31)) & 2)) - (v723 + ((~(((v724 ^ -1) | (-(v724 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
      v744[v841] = v741;
      int * v746 = v684->cache_tags;
      v746[v820] = 7;
      int * v748 = v684->cache_dirty;
      v748[v820] = 0;
      int * v750 = v684->cache_age;
      v750[v820] = 1;
      int * v752 = v684->cache_age;
      int v753 = v752[v820];
      int v754 = v752[10];
      int v850 = v754 + ((int)((unsigned int)(v754 - v753) >> 31));
      v752[10] = v850;
      int * v756 = v684->cache_age;
      int v757 = v756[11];
      int v852 = v757 + ((int)((unsigned int)(v757 - v753) >> 31));
      v756[11] = v852;
      int * v759 = v684->cache_age;
      v759[v820] = 0;
      v762 = v820;
    }
    int * v763 = v684->cache_vals;
    int v855 = v762 * 2;
    int v764 = v763[v855];
    int v856 = (v762 * 2) + 1;
    int v765 = v763[v856];
    int v857 = (2 + ((((v704 + ((~(((v706 ^ -1) | (-(v706 ^ -1))) >> 31)) & 2)) - (v707 + ((~(((v708 ^ -1) | (-(v708 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
    v763[v857] = v764;
    int * v767 = v684->cache_vals;
    int v860 = ((2 + ((((v704 + ((~(((v706 ^ -1) | (-(v706 ^ -1))) >> 31)) & 2)) - (v707 + ((~(((v708 ^ -1) | (-(v708 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
    v767[v860] = v765;
    int * v769 = v684->cache_tags;
    int v863 = 2 + ((((v704 + ((~(((v706 ^ -1) | (-(v706 ^ -1))) >> 31)) & 2)) - (v707 + ((~(((v708 ^ -1) | (-(v708 ^ -1))) >> 31)) & 2))) >> 31) & 1);
    v769[v863] = 7;
    int * v771 = v684->cache_dirty;
    v771[v863] = 0;
    int * v773 = v684->cache_age;
    v773[v863] = 1;
    int * v775 = v684->cache_age;
    int v776 = v775[v863];
    int v777 = v775[2];
    int v870 = v777 + ((int)((unsigned int)(v777 - v776) >> 31));
    v775[2] = v870;
    int * v779 = v684->cache_age;
    int v780 = v779[3];
    int v872 = v780 + ((int)((unsigned int)(v780 - v776) >> 31));
    v779[3] = v872;
    int * v782 = v684->cache_age;
    v782[v863] = 0;
    v785 = v863;
  }
  int v875 = v785 * 2;
  int v786 = v692[v875];
  int * v787 = v684->reg_ready;
  int v878 = (v685 + 1) + ((100 ^ (((~(((v690 ^ 7) | (-(v690 ^ 7))) >> 31)) | (~(((v691 ^ 7) | (-(v691 ^ 7))) >> 31))) & 104)) ^ (((~(((v688 ^ 7) | (-(v688 ^ 7))) >> 31)) | (~(((v689 ^ 7) | (-(v689 ^ 7))) >> 31))) & (1 ^ (100 ^ (((~(((v690 ^ 7) | (-(v690 ^ 7))) >> 31)) | (~(((v691 ^ 7) | (-(v691 ^ 7))) >> 31))) & 104)))));
  v787[8] = v878;
  int * v789 = v684->regs;
  v789[8] = v786;
  struct StateT * v791 = slot_6(v684);
  return v791;
}

struct StateT * slot_4(struct StateT * v374) {
  int v375 = v374->timer;
  int v546 = v375 + 1;
  v374->timer = v546;
  int * v377 = v374->reg_ready;
  int * v379 = v374->regs;
  int v380 = v379[7];
  int * v381 = v374->cache_tags;
  int v382 = v381[2];
  int v383 = v381[3];
  int v384 = v381[10];
  int v385 = v381[11];
  int v386 = v374->timer;
  int v555 = v386 + ((100 ^ (((~(((v384 ^ 7) | (-(v384 ^ 7))) >> 31)) | (~(((v385 ^ 7) | (-(v385 ^ 7))) >> 31))) & 104)) ^ (((~(((v382 ^ 7) | (-(v382 ^ 7))) >> 31)) | (~(((v383 ^ 7) | (-(v383 ^ 7))) >> 31))) & (1 ^ (100 ^ (((~(((v384 ^ 7) | (-(v384 ^ 7))) >> 31)) | (~(((v385 ^ 7) | (-(v385 ^ 7))) >> 31))) & 104)))));
  v374->timer = v555;
  bool v556 = !(((~(((v382 ^ 7) | (-(v382 ^ 7))) >> 31)) | (~(((v383 ^ 7) | (-(v383 ^ 7))) >> 31))) == 0);
  int v480;
  if (v556) {
    int * v388 = v374->cache_age;
    int v558 = 2 + ((~(((v383 ^ 7) | (-(v383 ^ 7))) >> 31)) & 1);
    int v389 = v388[v558];
    int v390 = v388[2];
    int v559 = v390 + ((int)((unsigned int)(v390 - v389) >> 31));
    v388[2] = v559;
    int * v392 = v374->cache_age;
    int v393 = v392[3];
    int v561 = v393 + ((int)((unsigned int)(v393 - v389) >> 31));
    v392[3] = v561;
    int * v395 = v374->cache_age;
    v395[v558] = 0;
    v480 = v558;
  } else {
    int * v398 = v374->cache_age;
    int v399 = v398[2];
    int * v400 = v374->cache_tags;
    int v401 = v400[2];
    int v402 = v398[3];
    int v403 = v400[3];
    bool v566 = !(((~(((v384 ^ 7) | (-(v384 ^ 7))) >> 31)) | (~(((v385 ^ 7) | (-(v385 ^ 7))) >> 31))) == 0);
    int v457;
    if (v566) {
      int * v404 = v374->cache_age;
      int v568 = 10 + ((~(((v385 ^ 7) | (-(v385 ^ 7))) >> 31)) & 1);
      int v405 = v404[v568];
      int v406 = v404[10];
      int v569 = v406 + ((int)((unsigned int)(v406 - v405) >> 31));
      v404[10] = v569;
      int * v408 = v374->cache_age;
      int v409 = v408[11];
      int v571 = v409 + ((int)((unsigned int)(v409 - v405) >> 31));
      v408[11] = v571;
      int * v411 = v374->cache_age;
      v411[v568] = 0;
      v457 = v568;
    } else {
      int * v414 = v374->cache_age;
      int v415 = v414[10];
      int * v416 = v374->cache_tags;
      int v417 = v416[10];
      int v418 = v414[11];
      int v419 = v416[11];
      int * v420 = v374->cache_dirty;
      int v577 = 10 + ((((v415 + ((~(((v417 ^ -1) | (-(v417 ^ -1))) >> 31)) & 2)) - (v418 + ((~(((v419 ^ -1) | (-(v419 ^ -1))) >> 31)) & 2))) >> 31) & 1);
      int v421 = v420[v577];
      bool v578 = !(v421 == 0);
      if (v578) {
        int * v422 = v374->cache_tags;
        int v423 = v422[v577];
        int * v424 = v374->cache_vals;
        int v581 = (10 + ((((v415 + ((~(((v417 ^ -1) | (-(v417 ^ -1))) >> 31)) & 2)) - (v418 + ((~(((v419 ^ -1) | (-(v419 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
        int v425 = v424[v581];
        int v582 = ((10 + ((((v415 + ((~(((v417 ^ -1) | (-(v417 ^ -1))) >> 31)) & 2)) - (v418 + ((~(((v419 ^ -1) | (-(v419 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
        int v426 = v424[v582];
        int * v427 = v374->mem;
        int v584 = v423 * 2;
        v427[v584] = v425;
        int * v429 = v374->mem;
        int v587 = (v423 * 2) + 1;
        v429[v587] = v426;
        ;
      } else {
        ;
      }
      int * v434 = v374->mem;
      int v435 = v434[14];
      int v436 = v434[15];
      int * v437 = v374->cache_vals;
      int v595 = (10 + ((((v415 + ((~(((v417 ^ -1) | (-(v417 ^ -1))) >> 31)) & 2)) - (v418 + ((~(((v419 ^ -1) | (-(v419 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
      v437[v595] = v435;
      int * v439 = v374->cache_vals;
      int v598 = ((10 + ((((v415 + ((~(((v417 ^ -1) | (-(v417 ^ -1))) >> 31)) & 2)) - (v418 + ((~(((v419 ^ -1) | (-(v419 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
      v439[v598] = v436;
      int * v441 = v374->cache_tags;
      v441[v577] = 7;
      int * v443 = v374->cache_dirty;
      v443[v577] = 0;
      int * v445 = v374->cache_age;
      v445[v577] = 1;
      int * v447 = v374->cache_age;
      int v448 = v447[v577];
      int v449 = v447[10];
      int v606 = v449 + ((int)((unsigned int)(v449 - v448) >> 31));
      v447[10] = v606;
      int * v451 = v374->cache_age;
      int v452 = v451[11];
      int v608 = v452 + ((int)((unsigned int)(v452 - v448) >> 31));
      v451[11] = v608;
      int * v454 = v374->cache_age;
      v454[v577] = 0;
      v457 = v577;
    }
    int * v458 = v374->cache_vals;
    int v611 = v457 * 2;
    int v459 = v458[v611];
    int v612 = (v457 * 2) + 1;
    int v460 = v458[v612];
    int v613 = (2 + ((((v399 + ((~(((v401 ^ -1) | (-(v401 ^ -1))) >> 31)) & 2)) - (v402 + ((~(((v403 ^ -1) | (-(v403 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
    v458[v613] = v459;
    int * v462 = v374->cache_vals;
    int v616 = ((2 + ((((v399 + ((~(((v401 ^ -1) | (-(v401 ^ -1))) >> 31)) & 2)) - (v402 + ((~(((v403 ^ -1) | (-(v403 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
    v462[v616] = v460;
    int * v464 = v374->cache_tags;
    int v619 = 2 + ((((v399 + ((~(((v401 ^ -1) | (-(v401 ^ -1))) >> 31)) & 2)) - (v402 + ((~(((v403 ^ -1) | (-(v403 ^ -1))) >> 31)) & 2))) >> 31) & 1);
    v464[v619] = 7;
    int * v466 = v374->cache_dirty;
    v466[v619] = 0;
    int * v468 = v374->cache_age;
    v468[v619] = 1;
    int * v470 = v374->cache_age;
    int v471 = v470[v619];
    int v472 = v470[2];
    int v625 = v472 + ((int)((unsigned int)(v472 - v471) >> 31));
    v470[2] = v625;
    int * v474 = v374->cache_age;
    int v475 = v474[3];
    int v627 = v475 + ((int)((unsigned int)(v475 - v471) >> 31));
    v474[3] = v627;
    int * v477 = v374->cache_age;
    v477[v619] = 0;
    v480 = v619;
  }
  int * v481 = v374->cache_vals;
  int v630 = v480 * 2;
  v481[v630] = v380;
  int * v483 = v374->cache_tags;
  int v484 = v483[10];
  int v485 = v483[11];
  bool v633 = !(((~(((v484 ^ 7) | (-(v484 ^ 7))) >> 31)) | (~(((v485 ^ 7) | (-(v485 ^ 7))) >> 31))) == 0);
  int v539;
  if (v633) {
    int * v486 = v374->cache_age;
    int v635 = 10 + ((~(((v485 ^ 7) | (-(v485 ^ 7))) >> 31)) & 1);
    int v487 = v486[v635];
    int v488 = v486[10];
    int v636 = v488 + ((int)((unsigned int)(v488 - v487) >> 31));
    v486[10] = v636;
    int * v490 = v374->cache_age;
    int v491 = v490[11];
    int v638 = v491 + ((int)((unsigned int)(v491 - v487) >> 31));
    v490[11] = v638;
    int * v493 = v374->cache_age;
    v493[v635] = 0;
    v539 = v635;
  } else {
    int * v496 = v374->cache_age;
    int v497 = v496[10];
    int * v498 = v374->cache_tags;
    int v499 = v498[10];
    int v500 = v496[11];
    int v501 = v498[11];
    int * v502 = v374->cache_dirty;
    int v644 = 10 + ((((v497 + ((~(((v499 ^ -1) | (-(v499 ^ -1))) >> 31)) & 2)) - (v500 + ((~(((v501 ^ -1) | (-(v501 ^ -1))) >> 31)) & 2))) >> 31) & 1);
    int v503 = v502[v644];
    bool v645 = !(v503 == 0);
    if (v645) {
      int * v504 = v374->cache_tags;
      int v505 = v504[v644];
      int * v506 = v374->cache_vals;
      int v648 = (10 + ((((v497 + ((~(((v499 ^ -1) | (-(v499 ^ -1))) >> 31)) & 2)) - (v500 + ((~(((v501 ^ -1) | (-(v501 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
      int v507 = v506[v648];
      int v649 = ((10 + ((((v497 + ((~(((v499 ^ -1) | (-(v499 ^ -1))) >> 31)) & 2)) - (v500 + ((~(((v501 ^ -1) | (-(v501 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
      int v508 = v506[v649];
      int * v509 = v374->mem;
      int v651 = v505 * 2;
      v509[v651] = v507;
      int * v511 = v374->mem;
      int v654 = (v505 * 2) + 1;
      v511[v654] = v508;
      ;
    } else {
      ;
    }
    int * v516 = v374->mem;
    int v517 = v516[14];
    int v518 = v516[15];
    int * v519 = v374->cache_vals;
    int v662 = (10 + ((((v497 + ((~(((v499 ^ -1) | (-(v499 ^ -1))) >> 31)) & 2)) - (v500 + ((~(((v501 ^ -1) | (-(v501 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
    v519[v662] = v517;
    int * v521 = v374->cache_vals;
    int v665 = ((10 + ((((v497 + ((~(((v499 ^ -1) | (-(v499 ^ -1))) >> 31)) & 2)) - (v500 + ((~(((v501 ^ -1) | (-(v501 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
    v521[v665] = v518;
    int * v523 = v374->cache_tags;
    v523[v644] = 7;
    int * v525 = v374->cache_dirty;
    v525[v644] = 0;
    int * v527 = v374->cache_age;
    v527[v644] = 1;
    int * v529 = v374->cache_age;
    int v530 = v529[v644];
    int v531 = v529[10];
    int v673 = v531 + ((int)((unsigned int)(v531 - v530) >> 31));
    v529[10] = v673;
    int * v533 = v374->cache_age;
    int v534 = v533[11];
    int v675 = v534 + ((int)((unsigned int)(v534 - v530) >> 31));
    v533[11] = v675;
    int * v536 = v374->cache_age;
    v536[v644] = 0;
    v539 = v644;
  }
  int * v540 = v374->cache_vals;
  int v678 = v539 * 2;
  v540[v678] = v380;
  int * v542 = v374->cache_dirty;
  v542[v539] = 1;
  struct StateT * v544 = slot_5(v374);
  return v544;
}

struct StateT * slot_2(struct StateT * v46) {
  int v47 = v46->timer;
  int v218 = v47 + 1;
  v46->timer = v218;
  int * v49 = v46->reg_ready;
  int * v51 = v46->regs;
  int v52 = v51[6];
  int * v53 = v46->cache_tags;
  int v54 = v53[2];
  int v55 = v53[3];
  int v56 = v53[6];
  int v57 = v53[7];
  int v58 = v46->timer;
  int v226 = v58 + ((100 ^ (((~(((v56 ^ 5) | (-(v56 ^ 5))) >> 31)) | (~(((v57 ^ 5) | (-(v57 ^ 5))) >> 31))) & 104)) ^ (((~(((v54 ^ 5) | (-(v54 ^ 5))) >> 31)) | (~(((v55 ^ 5) | (-(v55 ^ 5))) >> 31))) & (1 ^ (100 ^ (((~(((v56 ^ 5) | (-(v56 ^ 5))) >> 31)) | (~(((v57 ^ 5) | (-(v57 ^ 5))) >> 31))) & 104)))));
  v46->timer = v226;
  bool v227 = !(((~(((v54 ^ 5) | (-(v54 ^ 5))) >> 31)) | (~(((v55 ^ 5) | (-(v55 ^ 5))) >> 31))) == 0);
  int v152;
  if (v227) {
    int * v60 = v46->cache_age;
    int v229 = 2 + ((~(((v55 ^ 5) | (-(v55 ^ 5))) >> 31)) & 1);
    int v61 = v60[v229];
    int v62 = v60[2];
    int v230 = v62 + ((int)((unsigned int)(v62 - v61) >> 31));
    v60[2] = v230;
    int * v64 = v46->cache_age;
    int v65 = v64[3];
    int v232 = v65 + ((int)((unsigned int)(v65 - v61) >> 31));
    v64[3] = v232;
    int * v67 = v46->cache_age;
    v67[v229] = 0;
    v152 = v229;
  } else {
    int * v70 = v46->cache_age;
    int v71 = v70[2];
    int * v72 = v46->cache_tags;
    int v73 = v72[2];
    int v74 = v70[3];
    int v75 = v72[3];
    bool v237 = !(((~(((v56 ^ 5) | (-(v56 ^ 5))) >> 31)) | (~(((v57 ^ 5) | (-(v57 ^ 5))) >> 31))) == 0);
    int v129;
    if (v237) {
      int * v76 = v46->cache_age;
      int v239 = 6 + ((~(((v57 ^ 5) | (-(v57 ^ 5))) >> 31)) & 1);
      int v77 = v76[v239];
      int v78 = v76[6];
      int v240 = v78 + ((int)((unsigned int)(v78 - v77) >> 31));
      v76[6] = v240;
      int * v80 = v46->cache_age;
      int v81 = v80[7];
      int v242 = v81 + ((int)((unsigned int)(v81 - v77) >> 31));
      v80[7] = v242;
      int * v83 = v46->cache_age;
      v83[v239] = 0;
      v129 = v239;
    } else {
      int * v86 = v46->cache_age;
      int v87 = v86[6];
      int * v88 = v46->cache_tags;
      int v89 = v88[6];
      int v90 = v86[7];
      int v91 = v88[7];
      int * v92 = v46->cache_dirty;
      int v248 = 6 + ((((v87 + ((~(((v89 ^ -1) | (-(v89 ^ -1))) >> 31)) & 2)) - (v90 + ((~(((v91 ^ -1) | (-(v91 ^ -1))) >> 31)) & 2))) >> 31) & 1);
      int v93 = v92[v248];
      bool v249 = !(v93 == 0);
      if (v249) {
        int * v94 = v46->cache_tags;
        int v95 = v94[v248];
        int * v96 = v46->cache_vals;
        int v252 = (6 + ((((v87 + ((~(((v89 ^ -1) | (-(v89 ^ -1))) >> 31)) & 2)) - (v90 + ((~(((v91 ^ -1) | (-(v91 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
        int v97 = v96[v252];
        int v253 = ((6 + ((((v87 + ((~(((v89 ^ -1) | (-(v89 ^ -1))) >> 31)) & 2)) - (v90 + ((~(((v91 ^ -1) | (-(v91 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
        int v98 = v96[v253];
        int * v99 = v46->mem;
        int v255 = v95 * 2;
        v99[v255] = v97;
        int * v101 = v46->mem;
        int v258 = (v95 * 2) + 1;
        v101[v258] = v98;
        ;
      } else {
        ;
      }
      int * v106 = v46->mem;
      int v107 = v106[10];
      int v108 = v106[11];
      int * v109 = v46->cache_vals;
      int v266 = (6 + ((((v87 + ((~(((v89 ^ -1) | (-(v89 ^ -1))) >> 31)) & 2)) - (v90 + ((~(((v91 ^ -1) | (-(v91 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
      v109[v266] = v107;
      int * v111 = v46->cache_vals;
      int v269 = ((6 + ((((v87 + ((~(((v89 ^ -1) | (-(v89 ^ -1))) >> 31)) & 2)) - (v90 + ((~(((v91 ^ -1) | (-(v91 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
      v111[v269] = v108;
      int * v113 = v46->cache_tags;
      v113[v248] = 5;
      int * v115 = v46->cache_dirty;
      v115[v248] = 0;
      int * v117 = v46->cache_age;
      v117[v248] = 1;
      int * v119 = v46->cache_age;
      int v120 = v119[v248];
      int v121 = v119[6];
      int v278 = v121 + ((int)((unsigned int)(v121 - v120) >> 31));
      v119[6] = v278;
      int * v123 = v46->cache_age;
      int v124 = v123[7];
      int v280 = v124 + ((int)((unsigned int)(v124 - v120) >> 31));
      v123[7] = v280;
      int * v126 = v46->cache_age;
      v126[v248] = 0;
      v129 = v248;
    }
    int * v130 = v46->cache_vals;
    int v283 = v129 * 2;
    int v131 = v130[v283];
    int v284 = (v129 * 2) + 1;
    int v132 = v130[v284];
    int v285 = (2 + ((((v71 + ((~(((v73 ^ -1) | (-(v73 ^ -1))) >> 31)) & 2)) - (v74 + ((~(((v75 ^ -1) | (-(v75 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
    v130[v285] = v131;
    int * v134 = v46->cache_vals;
    int v288 = ((2 + ((((v71 + ((~(((v73 ^ -1) | (-(v73 ^ -1))) >> 31)) & 2)) - (v74 + ((~(((v75 ^ -1) | (-(v75 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
    v134[v288] = v132;
    int * v136 = v46->cache_tags;
    int v291 = 2 + ((((v71 + ((~(((v73 ^ -1) | (-(v73 ^ -1))) >> 31)) & 2)) - (v74 + ((~(((v75 ^ -1) | (-(v75 ^ -1))) >> 31)) & 2))) >> 31) & 1);
    v136[v291] = 5;
    int * v138 = v46->cache_dirty;
    v138[v291] = 0;
    int * v140 = v46->cache_age;
    v140[v291] = 1;
    int * v142 = v46->cache_age;
    int v143 = v142[v291];
    int v144 = v142[2];
    int v298 = v144 + ((int)((unsigned int)(v144 - v143) >> 31));
    v142[2] = v298;
    int * v146 = v46->cache_age;
    int v147 = v146[3];
    int v300 = v147 + ((int)((unsigned int)(v147 - v143) >> 31));
    v146[3] = v300;
    int * v149 = v46->cache_age;
    v149[v291] = 0;
    v152 = v291;
  }
  int * v153 = v46->cache_vals;
  int v303 = v152 * 2;
  v153[v303] = v52;
  int * v155 = v46->cache_tags;
  int v156 = v155[6];
  int v157 = v155[7];
  bool v306 = !(((~(((v156 ^ 5) | (-(v156 ^ 5))) >> 31)) | (~(((v157 ^ 5) | (-(v157 ^ 5))) >> 31))) == 0);
  int v211;
  if (v306) {
    int * v158 = v46->cache_age;
    int v308 = 6 + ((~(((v157 ^ 5) | (-(v157 ^ 5))) >> 31)) & 1);
    int v159 = v158[v308];
    int v160 = v158[6];
    int v309 = v160 + ((int)((unsigned int)(v160 - v159) >> 31));
    v158[6] = v309;
    int * v162 = v46->cache_age;
    int v163 = v162[7];
    int v311 = v163 + ((int)((unsigned int)(v163 - v159) >> 31));
    v162[7] = v311;
    int * v165 = v46->cache_age;
    v165[v308] = 0;
    v211 = v308;
  } else {
    int * v168 = v46->cache_age;
    int v169 = v168[6];
    int * v170 = v46->cache_tags;
    int v171 = v170[6];
    int v172 = v168[7];
    int v173 = v170[7];
    int * v174 = v46->cache_dirty;
    int v317 = 6 + ((((v169 + ((~(((v171 ^ -1) | (-(v171 ^ -1))) >> 31)) & 2)) - (v172 + ((~(((v173 ^ -1) | (-(v173 ^ -1))) >> 31)) & 2))) >> 31) & 1);
    int v175 = v174[v317];
    bool v318 = !(v175 == 0);
    if (v318) {
      int * v176 = v46->cache_tags;
      int v177 = v176[v317];
      int * v178 = v46->cache_vals;
      int v321 = (6 + ((((v169 + ((~(((v171 ^ -1) | (-(v171 ^ -1))) >> 31)) & 2)) - (v172 + ((~(((v173 ^ -1) | (-(v173 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
      int v179 = v178[v321];
      int v322 = ((6 + ((((v169 + ((~(((v171 ^ -1) | (-(v171 ^ -1))) >> 31)) & 2)) - (v172 + ((~(((v173 ^ -1) | (-(v173 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
      int v180 = v178[v322];
      int * v181 = v46->mem;
      int v324 = v177 * 2;
      v181[v324] = v179;
      int * v183 = v46->mem;
      int v327 = (v177 * 2) + 1;
      v183[v327] = v180;
      ;
    } else {
      ;
    }
    int * v188 = v46->mem;
    int v189 = v188[10];
    int v190 = v188[11];
    int * v191 = v46->cache_vals;
    int v335 = (6 + ((((v169 + ((~(((v171 ^ -1) | (-(v171 ^ -1))) >> 31)) & 2)) - (v172 + ((~(((v173 ^ -1) | (-(v173 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
    v191[v335] = v189;
    int * v193 = v46->cache_vals;
    int v338 = ((6 + ((((v169 + ((~(((v171 ^ -1) | (-(v171 ^ -1))) >> 31)) & 2)) - (v172 + ((~(((v173 ^ -1) | (-(v173 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
    v193[v338] = v190;
    int * v195 = v46->cache_tags;
    v195[v317] = 5;
    int * v197 = v46->cache_dirty;
    v197[v317] = 0;
    int * v199 = v46->cache_age;
    v199[v317] = 1;
    int * v201 = v46->cache_age;
    int v202 = v201[v317];
    int v203 = v201[6];
    int v347 = v203 + ((int)((unsigned int)(v203 - v202) >> 31));
    v201[6] = v347;
    int * v205 = v46->cache_age;
    int v206 = v205[7];
    int v349 = v206 + ((int)((unsigned int)(v206 - v202) >> 31));
    v205[7] = v349;
    int * v208 = v46->cache_age;
    v208[v317] = 0;
    v211 = v317;
  }
  int * v212 = v46->cache_vals;
  int v352 = v211 * 2;
  v212[v352] = v52;
  int * v214 = v46->cache_dirty;
  v214[v211] = 1;
  struct StateT * v216 = slot_3(v46);
  return v216;
}

struct StateT * slot_7(struct StateT * v1091) {
  int v1092 = v1091->timer;
  int v1204 = v1092 + 1;
  v1091->timer = v1204;
  int * v1094 = v1091->reg_ready;
  int v1095 = v1094[9];
  int * v1096 = v1091->regs;
  int v1097 = v1096[9];
  int * v1098 = v1091->cache_tags;
  int v1209 = (((int)((unsigned int)((int)((unsigned int)v1097 >> 2)) >> 1)) & 1) * 2;
  int v1099 = v1098[v1209];
  int v1210 = ((((int)((unsigned int)((int)((unsigned int)v1097 >> 2)) >> 1)) & 1) * 2) + 1;
  int v1100 = v1098[v1210];
  int v1211 = 4 + ((((int)((unsigned int)((int)((unsigned int)v1097 >> 2)) >> 1)) & 3) * 2);
  int v1101 = v1098[v1211];
  int v1212 = (4 + ((((int)((unsigned int)((int)((unsigned int)v1097 >> 2)) >> 1)) & 3) * 2)) + 1;
  int v1102 = v1098[v1212];
  int * v1103 = v1091->cache_vals;
  bool v1213 = !(((~(((v1099 ^ ((int)((unsigned int)((int)((unsigned int)v1097 >> 2)) >> 1))) | (-(v1099 ^ ((int)((unsigned int)((int)((unsigned int)v1097 >> 2)) >> 1))))) >> 31)) | (~(((v1100 ^ ((int)((unsigned int)((int)((unsigned int)v1097 >> 2)) >> 1))) | (-(v1100 ^ ((int)((unsigned int)((int)((unsigned int)v1097 >> 2)) >> 1))))) >> 31))) == 0);
  int v1196;
  if (v1213) {
    int * v1104 = v1091->cache_age;
    int v1215 = ((((int)((unsigned int)((int)((unsigned int)v1097 >> 2)) >> 1)) & 1) * 2) + ((~(((v1100 ^ ((int)((unsigned int)((int)((unsigned int)v1097 >> 2)) >> 1))) | (-(v1100 ^ ((int)((unsigned int)((int)((unsigned int)v1097 >> 2)) >> 1))))) >> 31)) & 1);
    int v1105 = v1104[v1215];
    int v1106 = v1104[v1209];
    int v1216 = v1106 + ((int)((unsigned int)(v1106 - v1105) >> 31));
    v1104[v1209] = v1216;
    int * v1108 = v1091->cache_age;
    int v1109 = v1108[v1210];
    int v1218 = v1109 + ((int)((unsigned int)(v1109 - v1105) >> 31));
    v1108[v1210] = v1218;
    int * v1111 = v1091->cache_age;
    v1111[v1215] = 0;
    v1196 = v1215;
  } else {
    int * v1114 = v1091->cache_age;
    int v1222 = (((int)((unsigned int)((int)((unsigned int)v1097 >> 2)) >> 1)) & 1) * 2;
    int v1115 = v1114[v1222];
    int * v1116 = v1091->cache_tags;
    int v1117 = v1116[v1222];
    int v1118 = v1114[v1210];
    int v1119 = v1116[v1210];
    bool v1224 = !(((~(((v1101 ^ ((int)((unsigned int)((int)((unsigned int)v1097 >> 2)) >> 1))) | (-(v1101 ^ ((int)((unsigned int)((int)((unsigned int)v1097 >> 2)) >> 1))))) >> 31)) | (~(((v1102 ^ ((int)((unsigned int)((int)((unsigned int)v1097 >> 2)) >> 1))) | (-(v1102 ^ ((int)((unsigned int)((int)((unsigned int)v1097 >> 2)) >> 1))))) >> 31))) == 0);
    int v1173;
    if (v1224) {
      int * v1120 = v1091->cache_age;
      int v1226 = (4 + ((((int)((unsigned int)((int)((unsigned int)v1097 >> 2)) >> 1)) & 3) * 2)) + ((~(((v1102 ^ ((int)((unsigned int)((int)((unsigned int)v1097 >> 2)) >> 1))) | (-(v1102 ^ ((int)((unsigned int)((int)((unsigned int)v1097 >> 2)) >> 1))))) >> 31)) & 1);
      int v1121 = v1120[v1226];
      int v1122 = v1120[v1211];
      int v1227 = v1122 + ((int)((unsigned int)(v1122 - v1121) >> 31));
      v1120[v1211] = v1227;
      int * v1124 = v1091->cache_age;
      int v1125 = v1124[v1212];
      int v1229 = v1125 + ((int)((unsigned int)(v1125 - v1121) >> 31));
      v1124[v1212] = v1229;
      int * v1127 = v1091->cache_age;
      v1127[v1226] = 0;
      v1173 = v1226;
    } else {
      int * v1130 = v1091->cache_age;
      int v1233 = 4 + ((((int)((unsigned int)((int)((unsigned int)v1097 >> 2)) >> 1)) & 3) * 2);
      int v1131 = v1130[v1233];
      int * v1132 = v1091->cache_tags;
      int v1133 = v1132[v1233];
      int v1134 = v1130[v1212];
      int v1135 = v1132[v1212];
      int * v1136 = v1091->cache_dirty;
      int v1236 = (4 + ((((int)((unsigned int)((int)((unsigned int)v1097 >> 2)) >> 1)) & 3) * 2)) + ((((v1131 + ((~(((v1133 ^ -1) | (-(v1133 ^ -1))) >> 31)) & 2)) - (v1134 + ((~(((v1135 ^ -1) | (-(v1135 ^ -1))) >> 31)) & 2))) >> 31) & 1);
      int v1137 = v1136[v1236];
      bool v1237 = !(v1137 == 0);
      if (v1237) {
        int * v1138 = v1091->cache_tags;
        int v1139 = v1138[v1236];
        int * v1140 = v1091->cache_vals;
        int v1240 = ((4 + ((((int)((unsigned int)((int)((unsigned int)v1097 >> 2)) >> 1)) & 3) * 2)) + ((((v1131 + ((~(((v1133 ^ -1) | (-(v1133 ^ -1))) >> 31)) & 2)) - (v1134 + ((~(((v1135 ^ -1) | (-(v1135 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
        int v1141 = v1140[v1240];
        int v1241 = (((4 + ((((int)((unsigned int)((int)((unsigned int)v1097 >> 2)) >> 1)) & 3) * 2)) + ((((v1131 + ((~(((v1133 ^ -1) | (-(v1133 ^ -1))) >> 31)) & 2)) - (v1134 + ((~(((v1135 ^ -1) | (-(v1135 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
        int v1142 = v1140[v1241];
        int * v1143 = v1091->mem;
        int v1243 = v1139 * 2;
        v1143[v1243] = v1141;
        int * v1145 = v1091->mem;
        int v1246 = (v1139 * 2) + 1;
        v1145[v1246] = v1142;
        ;
      } else {
        ;
      }
      int * v1150 = v1091->mem;
      int v1251 = ((int)((unsigned int)((int)((unsigned int)v1097 >> 2)) >> 1)) * 2;
      int v1151 = v1150[v1251];
      int v1252 = (((int)((unsigned int)((int)((unsigned int)v1097 >> 2)) >> 1)) * 2) + 1;
      int v1152 = v1150[v1252];
      int * v1153 = v1091->cache_vals;
      int v1254 = ((4 + ((((int)((unsigned int)((int)((unsigned int)v1097 >> 2)) >> 1)) & 3) * 2)) + ((((v1131 + ((~(((v1133 ^ -1) | (-(v1133 ^ -1))) >> 31)) & 2)) - (v1134 + ((~(((v1135 ^ -1) | (-(v1135 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
      v1153[v1254] = v1151;
      int * v1155 = v1091->cache_vals;
      int v1257 = (((4 + ((((int)((unsigned int)((int)((unsigned int)v1097 >> 2)) >> 1)) & 3) * 2)) + ((((v1131 + ((~(((v1133 ^ -1) | (-(v1133 ^ -1))) >> 31)) & 2)) - (v1134 + ((~(((v1135 ^ -1) | (-(v1135 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
      v1155[v1257] = v1152;
      int * v1157 = v1091->cache_tags;
      int v1260 = (int)((unsigned int)((int)((unsigned int)v1097 >> 2)) >> 1);
      v1157[v1236] = v1260;
      int * v1159 = v1091->cache_dirty;
      v1159[v1236] = 0;
      int * v1161 = v1091->cache_age;
      v1161[v1236] = 1;
      int * v1163 = v1091->cache_age;
      int v1164 = v1163[v1236];
      int v1165 = v1163[v1211];
      int v1266 = v1165 + ((int)((unsigned int)(v1165 - v1164) >> 31));
      v1163[v1211] = v1266;
      int * v1167 = v1091->cache_age;
      int v1168 = v1167[v1212];
      int v1268 = v1168 + ((int)((unsigned int)(v1168 - v1164) >> 31));
      v1167[v1212] = v1268;
      int * v1170 = v1091->cache_age;
      v1170[v1236] = 0;
      v1173 = v1236;
    }
    int * v1174 = v1091->cache_vals;
    int v1271 = v1173 * 2;
    int v1175 = v1174[v1271];
    int v1272 = (v1173 * 2) + 1;
    int v1176 = v1174[v1272];
    int v1273 = (((((int)((unsigned int)((int)((unsigned int)v1097 >> 2)) >> 1)) & 1) * 2) + ((((v1115 + ((~(((v1117 ^ -1) | (-(v1117 ^ -1))) >> 31)) & 2)) - (v1118 + ((~(((v1119 ^ -1) | (-(v1119 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
    v1174[v1273] = v1175;
    int * v1178 = v1091->cache_vals;
    int v1276 = ((((((int)((unsigned int)((int)((unsigned int)v1097 >> 2)) >> 1)) & 1) * 2) + ((((v1115 + ((~(((v1117 ^ -1) | (-(v1117 ^ -1))) >> 31)) & 2)) - (v1118 + ((~(((v1119 ^ -1) | (-(v1119 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
    v1178[v1276] = v1176;
    int * v1180 = v1091->cache_tags;
    int v1279 = ((((int)((unsigned int)((int)((unsigned int)v1097 >> 2)) >> 1)) & 1) * 2) + ((((v1115 + ((~(((v1117 ^ -1) | (-(v1117 ^ -1))) >> 31)) & 2)) - (v1118 + ((~(((v1119 ^ -1) | (-(v1119 ^ -1))) >> 31)) & 2))) >> 31) & 1);
    int v1280 = (int)((unsigned int)((int)((unsigned int)v1097 >> 2)) >> 1);
    v1180[v1279] = v1280;
    int * v1182 = v1091->cache_dirty;
    v1182[v1279] = 0;
    int * v1184 = v1091->cache_age;
    v1184[v1279] = 1;
    int * v1186 = v1091->cache_age;
    int v1187 = v1186[v1279];
    int v1188 = v1186[v1209];
    int v1286 = v1188 + ((int)((unsigned int)(v1188 - v1187) >> 31));
    v1186[v1209] = v1286;
    int * v1190 = v1091->cache_age;
    int v1191 = v1190[v1210];
    int v1288 = v1191 + ((int)((unsigned int)(v1191 - v1187) >> 31));
    v1190[v1210] = v1288;
    int * v1193 = v1091->cache_age;
    v1193[v1279] = 0;
    v1196 = v1279;
  }
  int v1291 = (v1196 * 2) + (((int)((unsigned int)v1097 >> 2)) & 1);
  int v1197 = v1103[v1291];
  int * v1198 = v1091->reg_ready;
  int v1294 = ((v1095 + ((v1092 - v1095) & (~((v1092 - v1095) >> 31)))) + 1) + ((100 ^ (((~(((v1101 ^ ((int)((unsigned int)((int)((unsigned int)v1097 >> 2)) >> 1))) | (-(v1101 ^ ((int)((unsigned int)((int)((unsigned int)v1097 >> 2)) >> 1))))) >> 31)) | (~(((v1102 ^ ((int)((unsigned int)((int)((unsigned int)v1097 >> 2)) >> 1))) | (-(v1102 ^ ((int)((unsigned int)((int)((unsigned int)v1097 >> 2)) >> 1))))) >> 31))) & 104)) ^ (((~(((v1099 ^ ((int)((unsigned int)((int)((unsigned int)v1097 >> 2)) >> 1))) | (-(v1099 ^ ((int)((unsigned int)((int)((unsigned int)v1097 >> 2)) >> 1))))) >> 31)) | (~(((v1100 ^ ((int)((unsigned int)((int)((unsigned int)v1097 >> 2)) >> 1))) | (-(v1100 ^ ((int)((unsigned int)((int)((unsigned int)v1097 >> 2)) >> 1))))) >> 31))) & (1 ^ (100 ^ (((~(((v1101 ^ ((int)((unsigned int)((int)((unsigned int)v1097 >> 2)) >> 1))) | (-(v1101 ^ ((int)((unsigned int)((int)((unsigned int)v1097 >> 2)) >> 1))))) >> 31)) | (~(((v1102 ^ ((int)((unsigned int)((int)((unsigned int)v1097 >> 2)) >> 1))) | (-(v1102 ^ ((int)((unsigned int)((int)((unsigned int)v1097 >> 2)) >> 1))))) >> 31))) & 104)))));
  v1198[11] = v1294;
  int * v1200 = v1091->regs;
  v1200[11] = v1197;
  struct StateT * v1202 = slot_8(v1091);
  return v1202;
}

struct StateT * slot_3(struct StateT * v358) {
  int v359 = v358->timer;
  int v367 = v359 + 1;
  v358->timer = v367;
  int * v361 = v358->reg_ready;
  v361[7] = v367;
  int * v363 = v358->regs;
  v363[7] = 4;
  struct StateT * v365 = slot_4(v358);
  return v365;
}

struct StateT * slot_0(struct StateT * v2) {
  int v3 = v2->timer;
  int v14 = v3 + 1;
  v2->timer = v14;
  int * v5 = v2->reg_ready;
  int v6 = v5[10];
  int * v7 = v2->regs;
  int v8 = v7[10];
  int v19 = (v6 + ((v3 - v6) & (~((v3 - v6) >> 31)))) + 1;
  v5[5] = v19;
  int * v10 = v2->regs;
  int v21 = v8 & 28;
  v10[5] = v21;
  struct StateT * v12 = slot_1(v2);
  return v12;
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