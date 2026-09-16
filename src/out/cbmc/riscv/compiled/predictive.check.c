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

struct StateT * slot_34(struct StateT * v1510);
struct StateT * slot_6(struct StateT * v96);
struct StateT * slot_29(struct StateT * v1413);
struct StateT * slot_16(struct StateT * v760);
struct StateT * slot_23(struct StateT * v1104);
struct StateT * slot_5(struct StateT * v76);
struct StateT * slot_2(struct StateT * v32);
struct StateT * slot_7(struct StateT * v112);
struct StateT * slot_31(struct StateT * v1484);
struct StateT * slot_3(struct StateT * v40);
struct StateT * slot_26(struct StateT * v1359);
struct StateT * slot_10(struct StateT * v678);
struct StateT * slot_1(struct StateT * v19);
struct StateT * slot_19(struct StateT * v829);
struct StateT * slot_13(struct StateT * v691);
struct StateT * slot_24(struct StateT * v1109);
struct StateT * slot_0(struct StateT * v2);
struct StateT * slot_14(struct StateT * v714);
struct StateT * slot_28(struct StateT * v1390);
struct StateT * slot_32(struct StateT * v1497);
struct StateT * slot_17(struct StateT * v808);
struct StateT * slot_20(struct StateT * v834);
struct StateT * slot_33(struct StateT * v1505);
struct StateT * slot_36(struct StateT * v1767);
struct StateT * slot_37(struct StateT * v2024);
struct StateT * snippet(struct StateT * v0);
struct StateT * slot_8(struct StateT * v369);
struct StateT * slot_27(struct StateT * v1367);
struct StateT * slot_30(struct StateT * v1436);
struct StateT * slot_4(struct StateT * v60);
struct StateT * slot_15(struct StateT * v737);
struct StateT * slot_18(struct StateT * v821);
struct StateT * slot_9(struct StateT * v626);
struct StateT * slot_22(struct StateT * v854);
struct StateT * slot_11(struct StateT * v683);
struct StateT * slot_34(struct StateT * v1510) {
  int * v1511 = v1510->saved_regs;
  int * v1512 = v1510->regs;
  int v1513 = v1512[14];
  v1511[14] = v1513;
  int v1515 = v1510->timer;
  int v1652 = v1515 + 1;
  v1510->timer = v1652;
  int * v1517 = v1510->regs;
  int v1518 = v1517[12];
  int * v1519 = v1510->cache_tags;
  int v1656 = (((int)((unsigned int)((int)((unsigned int)v1518 >> 2)) >> 1)) & 1) * 2;
  int v1520 = v1519[v1656];
  int * v1521 = v1510->cache_tags;
  int v1658 = ((((int)((unsigned int)((int)((unsigned int)v1518 >> 2)) >> 1)) & 1) * 2) + 1;
  int v1522 = v1521[v1658];
  int * v1523 = v1510->cache_tags;
  int v1660 = 4 + ((((int)((unsigned int)((int)((unsigned int)v1518 >> 2)) >> 1)) & 3) * 2);
  int v1524 = v1523[v1660];
  int * v1525 = v1510->cache_tags;
  int v1662 = (4 + ((((int)((unsigned int)((int)((unsigned int)v1518 >> 2)) >> 1)) & 3) * 2)) + 1;
  int v1526 = v1525[v1662];
  int v1527 = v1510->timer;
  int v1663 = v1527 + ((100 ^ (((~(((v1524 ^ ((int)((unsigned int)((int)((unsigned int)v1518 >> 2)) >> 1))) | (-(v1524 ^ ((int)((unsigned int)((int)((unsigned int)v1518 >> 2)) >> 1))))) >> 31)) | (~(((v1526 ^ ((int)((unsigned int)((int)((unsigned int)v1518 >> 2)) >> 1))) | (-(v1526 ^ ((int)((unsigned int)((int)((unsigned int)v1518 >> 2)) >> 1))))) >> 31))) & 104)) ^ (((~(((v1520 ^ ((int)((unsigned int)((int)((unsigned int)v1518 >> 2)) >> 1))) | (-(v1520 ^ ((int)((unsigned int)((int)((unsigned int)v1518 >> 2)) >> 1))))) >> 31)) | (~(((v1522 ^ ((int)((unsigned int)((int)((unsigned int)v1518 >> 2)) >> 1))) | (-(v1522 ^ ((int)((unsigned int)((int)((unsigned int)v1518 >> 2)) >> 1))))) >> 31))) & (1 ^ (100 ^ (((~(((v1524 ^ ((int)((unsigned int)((int)((unsigned int)v1518 >> 2)) >> 1))) | (-(v1524 ^ ((int)((unsigned int)((int)((unsigned int)v1518 >> 2)) >> 1))))) >> 31)) | (~(((v1526 ^ ((int)((unsigned int)((int)((unsigned int)v1518 >> 2)) >> 1))) | (-(v1526 ^ ((int)((unsigned int)((int)((unsigned int)v1518 >> 2)) >> 1))))) >> 31))) & 104)))));
  v1510->timer = v1663;
  int * v1529 = v1510->cache_vals;
  bool v1664 = !(((~(((v1520 ^ ((int)((unsigned int)((int)((unsigned int)v1518 >> 2)) >> 1))) | (-(v1520 ^ ((int)((unsigned int)((int)((unsigned int)v1518 >> 2)) >> 1))))) >> 31)) | (~(((v1522 ^ ((int)((unsigned int)((int)((unsigned int)v1518 >> 2)) >> 1))) | (-(v1522 ^ ((int)((unsigned int)((int)((unsigned int)v1518 >> 2)) >> 1))))) >> 31))) == 0);
  int v1642;
  if (v1664) {
    int * v1530 = v1510->cache_age;
    int v1666 = ((((int)((unsigned int)((int)((unsigned int)v1518 >> 2)) >> 1)) & 1) * 2) + ((~(((v1522 ^ ((int)((unsigned int)((int)((unsigned int)v1518 >> 2)) >> 1))) | (-(v1522 ^ ((int)((unsigned int)((int)((unsigned int)v1518 >> 2)) >> 1))))) >> 31)) & 1);
    int v1531 = v1530[v1666];
    int * v1532 = v1510->cache_age;
    int v1533 = v1532[v1656];
    int * v1534 = v1510->cache_age;
    int v1669 = v1533 + ((int)((unsigned int)(v1533 - v1531) >> 31));
    v1534[v1656] = v1669;
    int * v1536 = v1510->cache_age;
    int v1537 = v1536[v1658];
    int * v1538 = v1510->cache_age;
    int v1672 = v1537 + ((int)((unsigned int)(v1537 - v1531) >> 31));
    v1538[v1658] = v1672;
    int * v1540 = v1510->cache_age;
    v1540[v1666] = 0;
    v1642 = v1666;
  } else {
    int * v1543 = v1510->cache_age;
    int v1676 = (((int)((unsigned int)((int)((unsigned int)v1518 >> 2)) >> 1)) & 1) * 2;
    int v1544 = v1543[v1676];
    int * v1545 = v1510->cache_tags;
    int v1546 = v1545[v1676];
    int * v1547 = v1510->cache_age;
    int v1548 = v1547[v1658];
    int * v1549 = v1510->cache_tags;
    int v1550 = v1549[v1658];
    bool v1680 = !(((~(((v1524 ^ ((int)((unsigned int)((int)((unsigned int)v1518 >> 2)) >> 1))) | (-(v1524 ^ ((int)((unsigned int)((int)((unsigned int)v1518 >> 2)) >> 1))))) >> 31)) | (~(((v1526 ^ ((int)((unsigned int)((int)((unsigned int)v1518 >> 2)) >> 1))) | (-(v1526 ^ ((int)((unsigned int)((int)((unsigned int)v1518 >> 2)) >> 1))))) >> 31))) == 0);
    int v1614;
    if (v1680) {
      int * v1551 = v1510->cache_age;
      int v1682 = (4 + ((((int)((unsigned int)((int)((unsigned int)v1518 >> 2)) >> 1)) & 3) * 2)) + ((~(((v1526 ^ ((int)((unsigned int)((int)((unsigned int)v1518 >> 2)) >> 1))) | (-(v1526 ^ ((int)((unsigned int)((int)((unsigned int)v1518 >> 2)) >> 1))))) >> 31)) & 1);
      int v1552 = v1551[v1682];
      int * v1553 = v1510->cache_age;
      int v1554 = v1553[v1660];
      int * v1555 = v1510->cache_age;
      int v1685 = v1554 + ((int)((unsigned int)(v1554 - v1552) >> 31));
      v1555[v1660] = v1685;
      int * v1557 = v1510->cache_age;
      int v1558 = v1557[v1662];
      int * v1559 = v1510->cache_age;
      int v1688 = v1558 + ((int)((unsigned int)(v1558 - v1552) >> 31));
      v1559[v1662] = v1688;
      int * v1561 = v1510->cache_age;
      v1561[v1682] = 0;
      v1614 = v1682;
    } else {
      int * v1564 = v1510->cache_age;
      int v1692 = 4 + ((((int)((unsigned int)((int)((unsigned int)v1518 >> 2)) >> 1)) & 3) * 2);
      int v1565 = v1564[v1692];
      int * v1566 = v1510->cache_tags;
      int v1567 = v1566[v1692];
      int * v1568 = v1510->cache_age;
      int v1569 = v1568[v1662];
      int * v1570 = v1510->cache_tags;
      int v1571 = v1570[v1662];
      int * v1572 = v1510->cache_dirty;
      int v1697 = (4 + ((((int)((unsigned int)((int)((unsigned int)v1518 >> 2)) >> 1)) & 3) * 2)) + ((((v1565 + ((~(((v1567 ^ -1) | (-(v1567 ^ -1))) >> 31)) & 2)) - (v1569 + ((~(((v1571 ^ -1) | (-(v1571 ^ -1))) >> 31)) & 2))) >> 31) & 1);
      int v1573 = v1572[v1697];
      bool v1698 = !(v1573 == 0);
      if (v1698) {
        int * v1574 = v1510->cache_tags;
        int v1575 = v1574[v1697];
        int * v1576 = v1510->cache_vals;
        int v1701 = ((4 + ((((int)((unsigned int)((int)((unsigned int)v1518 >> 2)) >> 1)) & 3) * 2)) + ((((v1565 + ((~(((v1567 ^ -1) | (-(v1567 ^ -1))) >> 31)) & 2)) - (v1569 + ((~(((v1571 ^ -1) | (-(v1571 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
        int v1577 = v1576[v1701];
        int * v1578 = v1510->cache_vals;
        int v1703 = (((4 + ((((int)((unsigned int)((int)((unsigned int)v1518 >> 2)) >> 1)) & 3) * 2)) + ((((v1565 + ((~(((v1567 ^ -1) | (-(v1567 ^ -1))) >> 31)) & 2)) - (v1569 + ((~(((v1571 ^ -1) | (-(v1571 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
        int v1579 = v1578[v1703];
        int * v1580 = v1510->mem;
        int v1705 = v1575 * 2;
        v1580[v1705] = v1577;
        int * v1582 = v1510->mem;
        int v1708 = (v1575 * 2) + 1;
        v1582[v1708] = v1579;
        ;
      } else {
        ;
      }
      int * v1587 = v1510->mem;
      int v1713 = ((int)((unsigned int)((int)((unsigned int)v1518 >> 2)) >> 1)) * 2;
      int v1588 = v1587[v1713];
      int * v1589 = v1510->mem;
      int v1715 = (((int)((unsigned int)((int)((unsigned int)v1518 >> 2)) >> 1)) * 2) + 1;
      int v1590 = v1589[v1715];
      int * v1591 = v1510->cache_vals;
      int v1717 = ((4 + ((((int)((unsigned int)((int)((unsigned int)v1518 >> 2)) >> 1)) & 3) * 2)) + ((((v1565 + ((~(((v1567 ^ -1) | (-(v1567 ^ -1))) >> 31)) & 2)) - (v1569 + ((~(((v1571 ^ -1) | (-(v1571 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
      v1591[v1717] = v1588;
      int * v1593 = v1510->cache_vals;
      int v1720 = (((4 + ((((int)((unsigned int)((int)((unsigned int)v1518 >> 2)) >> 1)) & 3) * 2)) + ((((v1565 + ((~(((v1567 ^ -1) | (-(v1567 ^ -1))) >> 31)) & 2)) - (v1569 + ((~(((v1571 ^ -1) | (-(v1571 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
      v1593[v1720] = v1590;
      int * v1595 = v1510->cache_tags;
      int v1723 = (int)((unsigned int)((int)((unsigned int)v1518 >> 2)) >> 1);
      v1595[v1697] = v1723;
      int * v1597 = v1510->cache_dirty;
      v1597[v1697] = 0;
      int * v1599 = v1510->cache_age;
      v1599[v1697] = 1;
      int * v1601 = v1510->cache_age;
      int v1602 = v1601[v1697];
      int * v1603 = v1510->cache_age;
      int v1604 = v1603[v1660];
      int * v1605 = v1510->cache_age;
      int v1731 = v1604 + ((int)((unsigned int)(v1604 - v1602) >> 31));
      v1605[v1660] = v1731;
      int * v1607 = v1510->cache_age;
      int v1608 = v1607[v1662];
      int * v1609 = v1510->cache_age;
      int v1734 = v1608 + ((int)((unsigned int)(v1608 - v1602) >> 31));
      v1609[v1662] = v1734;
      int * v1611 = v1510->cache_age;
      v1611[v1697] = 0;
      v1614 = v1697;
    }
    int * v1615 = v1510->cache_vals;
    int v1737 = v1614 * 2;
    int v1616 = v1615[v1737];
    int * v1617 = v1510->cache_vals;
    int v1739 = (v1614 * 2) + 1;
    int v1618 = v1617[v1739];
    int * v1619 = v1510->cache_vals;
    int v1741 = (((((int)((unsigned int)((int)((unsigned int)v1518 >> 2)) >> 1)) & 1) * 2) + ((((v1544 + ((~(((v1546 ^ -1) | (-(v1546 ^ -1))) >> 31)) & 2)) - (v1548 + ((~(((v1550 ^ -1) | (-(v1550 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
    v1619[v1741] = v1616;
    int * v1621 = v1510->cache_vals;
    int v1744 = ((((((int)((unsigned int)((int)((unsigned int)v1518 >> 2)) >> 1)) & 1) * 2) + ((((v1544 + ((~(((v1546 ^ -1) | (-(v1546 ^ -1))) >> 31)) & 2)) - (v1548 + ((~(((v1550 ^ -1) | (-(v1550 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
    v1621[v1744] = v1618;
    int * v1623 = v1510->cache_tags;
    int v1747 = ((((int)((unsigned int)((int)((unsigned int)v1518 >> 2)) >> 1)) & 1) * 2) + ((((v1544 + ((~(((v1546 ^ -1) | (-(v1546 ^ -1))) >> 31)) & 2)) - (v1548 + ((~(((v1550 ^ -1) | (-(v1550 ^ -1))) >> 31)) & 2))) >> 31) & 1);
    int v1748 = (int)((unsigned int)((int)((unsigned int)v1518 >> 2)) >> 1);
    v1623[v1747] = v1748;
    int * v1625 = v1510->cache_dirty;
    v1625[v1747] = 0;
    int * v1627 = v1510->cache_age;
    v1627[v1747] = 1;
    int * v1629 = v1510->cache_age;
    int v1630 = v1629[v1747];
    int * v1631 = v1510->cache_age;
    int v1632 = v1631[v1656];
    int * v1633 = v1510->cache_age;
    int v1756 = v1632 + ((int)((unsigned int)(v1632 - v1630) >> 31));
    v1633[v1656] = v1756;
    int * v1635 = v1510->cache_age;
    int v1636 = v1635[v1658];
    int * v1637 = v1510->cache_age;
    int v1759 = v1636 + ((int)((unsigned int)(v1636 - v1630) >> 31));
    v1637[v1658] = v1759;
    int * v1639 = v1510->cache_age;
    v1639[v1747] = 0;
    v1642 = v1747;
  }
  int v1762 = (v1642 * 2) + (((int)((unsigned int)v1518 >> 2)) & 1);
  int v1643 = v1529[v1762];
  int * v1644 = v1510->regs;
  v1644[14] = v1643;
  struct StateT * v1646 = slot_36(v1510);
  return v1646;
}

struct StateT * slot_6(struct StateT * v96) {
  int v97 = v96->timer;
  int v105 = v97 + 1;
  v96->timer = v105;
  int * v99 = v96->regs;
  int v100 = v99[13];
  int * v101 = v96->regs;
  v101[13] = v100;
  struct StateT * v103 = slot_7(v96);
  return v103;
}

struct StateT * slot_29(struct StateT * v1413) {
  int * v1414 = v1413->saved_regs;
  int * v1415 = v1413->regs;
  int v1416 = v1415[13];
  v1414[13] = v1416;
  int v1418 = v1413->timer;
  int v1430 = v1418 + 1;
  v1413->timer = v1430;
  int * v1420 = v1413->regs;
  int v1421 = v1420[13];
  int * v1422 = v1413->regs;
  int v1433 = v1421 + 4;
  v1422[13] = v1433;
  struct StateT * v1424 = slot_30(v1413);
  return v1424;
}

struct StateT * slot_16(struct StateT * v760) {
  int * v761 = v760->regs;
  int v762 = v761[14];
  int * v763 = v760->regs;
  int v764 = v763[15];
  bool v789 = !(v762 == v764);
  struct StateT * v783;
  if (v789) {
    int v765 = v760->timer;
    int v790 = v765 + 15;
    v760->timer = v790;
    int * v767 = v760->saved_regs;
    int v768 = v767[11];
    int * v769 = v760->regs;
    v769[11] = v768;
    int * v771 = v760->saved_regs;
    int v772 = v771[12];
    int * v773 = v760->regs;
    v773[12] = v772;
    int * v775 = v760->saved_regs;
    int v776 = v775[13];
    int * v777 = v760->regs;
    v777[13] = v776;
    struct StateT * v779 = slot_17(v760);
    v783 = v779;
  } else {
    struct StateT * v781 = slot_18(v760);
    v783 = v781;
  }
  return v783;
}

struct StateT * slot_23(struct StateT * v1104) {
  int v1105 = v1104->timer;
  int v1108 = v1105 + 1;
  v1104->timer = v1108;
  return v1104;
}

struct StateT * slot_5(struct StateT * v76) {
  int * v77 = v76->saved_regs;
  int * v78 = v76->regs;
  int v79 = v78[13];
  v77[13] = v79;
  int v81 = v76->timer;
  int v91 = v81 + 1;
  v76->timer = v91;
  int * v83 = v76->regs;
  v83[13] = 0;
  struct StateT * v85 = slot_6(v76);
  return v85;
}

struct StateT * slot_2(struct StateT * v32) {
  int v33 = v32->timer;
  int v37 = v33 + 1;
  v32->timer = v37;
  struct StateT * v35 = slot_3(v32);
  return v35;
}

struct StateT * slot_7(struct StateT * v112) {
  int * v113 = v112->saved_regs;
  int * v114 = v112->regs;
  int v115 = v114[14];
  v113[14] = v115;
  int v117 = v112->timer;
  int v254 = v117 + 1;
  v112->timer = v254;
  int * v119 = v112->regs;
  int v120 = v119[12];
  int * v121 = v112->cache_tags;
  int v258 = (((int)((unsigned int)((int)((unsigned int)v120 >> 2)) >> 1)) & 1) * 2;
  int v122 = v121[v258];
  int * v123 = v112->cache_tags;
  int v260 = ((((int)((unsigned int)((int)((unsigned int)v120 >> 2)) >> 1)) & 1) * 2) + 1;
  int v124 = v123[v260];
  int * v125 = v112->cache_tags;
  int v262 = 4 + ((((int)((unsigned int)((int)((unsigned int)v120 >> 2)) >> 1)) & 3) * 2);
  int v126 = v125[v262];
  int * v127 = v112->cache_tags;
  int v264 = (4 + ((((int)((unsigned int)((int)((unsigned int)v120 >> 2)) >> 1)) & 3) * 2)) + 1;
  int v128 = v127[v264];
  int v129 = v112->timer;
  int v265 = v129 + ((100 ^ (((~(((v126 ^ ((int)((unsigned int)((int)((unsigned int)v120 >> 2)) >> 1))) | (-(v126 ^ ((int)((unsigned int)((int)((unsigned int)v120 >> 2)) >> 1))))) >> 31)) | (~(((v128 ^ ((int)((unsigned int)((int)((unsigned int)v120 >> 2)) >> 1))) | (-(v128 ^ ((int)((unsigned int)((int)((unsigned int)v120 >> 2)) >> 1))))) >> 31))) & 104)) ^ (((~(((v122 ^ ((int)((unsigned int)((int)((unsigned int)v120 >> 2)) >> 1))) | (-(v122 ^ ((int)((unsigned int)((int)((unsigned int)v120 >> 2)) >> 1))))) >> 31)) | (~(((v124 ^ ((int)((unsigned int)((int)((unsigned int)v120 >> 2)) >> 1))) | (-(v124 ^ ((int)((unsigned int)((int)((unsigned int)v120 >> 2)) >> 1))))) >> 31))) & (1 ^ (100 ^ (((~(((v126 ^ ((int)((unsigned int)((int)((unsigned int)v120 >> 2)) >> 1))) | (-(v126 ^ ((int)((unsigned int)((int)((unsigned int)v120 >> 2)) >> 1))))) >> 31)) | (~(((v128 ^ ((int)((unsigned int)((int)((unsigned int)v120 >> 2)) >> 1))) | (-(v128 ^ ((int)((unsigned int)((int)((unsigned int)v120 >> 2)) >> 1))))) >> 31))) & 104)))));
  v112->timer = v265;
  int * v131 = v112->cache_vals;
  bool v266 = !(((~(((v122 ^ ((int)((unsigned int)((int)((unsigned int)v120 >> 2)) >> 1))) | (-(v122 ^ ((int)((unsigned int)((int)((unsigned int)v120 >> 2)) >> 1))))) >> 31)) | (~(((v124 ^ ((int)((unsigned int)((int)((unsigned int)v120 >> 2)) >> 1))) | (-(v124 ^ ((int)((unsigned int)((int)((unsigned int)v120 >> 2)) >> 1))))) >> 31))) == 0);
  int v244;
  if (v266) {
    int * v132 = v112->cache_age;
    int v268 = ((((int)((unsigned int)((int)((unsigned int)v120 >> 2)) >> 1)) & 1) * 2) + ((~(((v124 ^ ((int)((unsigned int)((int)((unsigned int)v120 >> 2)) >> 1))) | (-(v124 ^ ((int)((unsigned int)((int)((unsigned int)v120 >> 2)) >> 1))))) >> 31)) & 1);
    int v133 = v132[v268];
    int * v134 = v112->cache_age;
    int v135 = v134[v258];
    int * v136 = v112->cache_age;
    int v271 = v135 + ((int)((unsigned int)(v135 - v133) >> 31));
    v136[v258] = v271;
    int * v138 = v112->cache_age;
    int v139 = v138[v260];
    int * v140 = v112->cache_age;
    int v274 = v139 + ((int)((unsigned int)(v139 - v133) >> 31));
    v140[v260] = v274;
    int * v142 = v112->cache_age;
    v142[v268] = 0;
    v244 = v268;
  } else {
    int * v145 = v112->cache_age;
    int v278 = (((int)((unsigned int)((int)((unsigned int)v120 >> 2)) >> 1)) & 1) * 2;
    int v146 = v145[v278];
    int * v147 = v112->cache_tags;
    int v148 = v147[v278];
    int * v149 = v112->cache_age;
    int v150 = v149[v260];
    int * v151 = v112->cache_tags;
    int v152 = v151[v260];
    bool v282 = !(((~(((v126 ^ ((int)((unsigned int)((int)((unsigned int)v120 >> 2)) >> 1))) | (-(v126 ^ ((int)((unsigned int)((int)((unsigned int)v120 >> 2)) >> 1))))) >> 31)) | (~(((v128 ^ ((int)((unsigned int)((int)((unsigned int)v120 >> 2)) >> 1))) | (-(v128 ^ ((int)((unsigned int)((int)((unsigned int)v120 >> 2)) >> 1))))) >> 31))) == 0);
    int v216;
    if (v282) {
      int * v153 = v112->cache_age;
      int v284 = (4 + ((((int)((unsigned int)((int)((unsigned int)v120 >> 2)) >> 1)) & 3) * 2)) + ((~(((v128 ^ ((int)((unsigned int)((int)((unsigned int)v120 >> 2)) >> 1))) | (-(v128 ^ ((int)((unsigned int)((int)((unsigned int)v120 >> 2)) >> 1))))) >> 31)) & 1);
      int v154 = v153[v284];
      int * v155 = v112->cache_age;
      int v156 = v155[v262];
      int * v157 = v112->cache_age;
      int v287 = v156 + ((int)((unsigned int)(v156 - v154) >> 31));
      v157[v262] = v287;
      int * v159 = v112->cache_age;
      int v160 = v159[v264];
      int * v161 = v112->cache_age;
      int v290 = v160 + ((int)((unsigned int)(v160 - v154) >> 31));
      v161[v264] = v290;
      int * v163 = v112->cache_age;
      v163[v284] = 0;
      v216 = v284;
    } else {
      int * v166 = v112->cache_age;
      int v294 = 4 + ((((int)((unsigned int)((int)((unsigned int)v120 >> 2)) >> 1)) & 3) * 2);
      int v167 = v166[v294];
      int * v168 = v112->cache_tags;
      int v169 = v168[v294];
      int * v170 = v112->cache_age;
      int v171 = v170[v264];
      int * v172 = v112->cache_tags;
      int v173 = v172[v264];
      int * v174 = v112->cache_dirty;
      int v299 = (4 + ((((int)((unsigned int)((int)((unsigned int)v120 >> 2)) >> 1)) & 3) * 2)) + ((((v167 + ((~(((v169 ^ -1) | (-(v169 ^ -1))) >> 31)) & 2)) - (v171 + ((~(((v173 ^ -1) | (-(v173 ^ -1))) >> 31)) & 2))) >> 31) & 1);
      int v175 = v174[v299];
      bool v300 = !(v175 == 0);
      if (v300) {
        int * v176 = v112->cache_tags;
        int v177 = v176[v299];
        int * v178 = v112->cache_vals;
        int v303 = ((4 + ((((int)((unsigned int)((int)((unsigned int)v120 >> 2)) >> 1)) & 3) * 2)) + ((((v167 + ((~(((v169 ^ -1) | (-(v169 ^ -1))) >> 31)) & 2)) - (v171 + ((~(((v173 ^ -1) | (-(v173 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
        int v179 = v178[v303];
        int * v180 = v112->cache_vals;
        int v305 = (((4 + ((((int)((unsigned int)((int)((unsigned int)v120 >> 2)) >> 1)) & 3) * 2)) + ((((v167 + ((~(((v169 ^ -1) | (-(v169 ^ -1))) >> 31)) & 2)) - (v171 + ((~(((v173 ^ -1) | (-(v173 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
        int v181 = v180[v305];
        int * v182 = v112->mem;
        int v307 = v177 * 2;
        v182[v307] = v179;
        int * v184 = v112->mem;
        int v310 = (v177 * 2) + 1;
        v184[v310] = v181;
        ;
      } else {
        ;
      }
      int * v189 = v112->mem;
      int v315 = ((int)((unsigned int)((int)((unsigned int)v120 >> 2)) >> 1)) * 2;
      int v190 = v189[v315];
      int * v191 = v112->mem;
      int v317 = (((int)((unsigned int)((int)((unsigned int)v120 >> 2)) >> 1)) * 2) + 1;
      int v192 = v191[v317];
      int * v193 = v112->cache_vals;
      int v319 = ((4 + ((((int)((unsigned int)((int)((unsigned int)v120 >> 2)) >> 1)) & 3) * 2)) + ((((v167 + ((~(((v169 ^ -1) | (-(v169 ^ -1))) >> 31)) & 2)) - (v171 + ((~(((v173 ^ -1) | (-(v173 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
      v193[v319] = v190;
      int * v195 = v112->cache_vals;
      int v322 = (((4 + ((((int)((unsigned int)((int)((unsigned int)v120 >> 2)) >> 1)) & 3) * 2)) + ((((v167 + ((~(((v169 ^ -1) | (-(v169 ^ -1))) >> 31)) & 2)) - (v171 + ((~(((v173 ^ -1) | (-(v173 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
      v195[v322] = v192;
      int * v197 = v112->cache_tags;
      int v325 = (int)((unsigned int)((int)((unsigned int)v120 >> 2)) >> 1);
      v197[v299] = v325;
      int * v199 = v112->cache_dirty;
      v199[v299] = 0;
      int * v201 = v112->cache_age;
      v201[v299] = 1;
      int * v203 = v112->cache_age;
      int v204 = v203[v299];
      int * v205 = v112->cache_age;
      int v206 = v205[v262];
      int * v207 = v112->cache_age;
      int v333 = v206 + ((int)((unsigned int)(v206 - v204) >> 31));
      v207[v262] = v333;
      int * v209 = v112->cache_age;
      int v210 = v209[v264];
      int * v211 = v112->cache_age;
      int v336 = v210 + ((int)((unsigned int)(v210 - v204) >> 31));
      v211[v264] = v336;
      int * v213 = v112->cache_age;
      v213[v299] = 0;
      v216 = v299;
    }
    int * v217 = v112->cache_vals;
    int v339 = v216 * 2;
    int v218 = v217[v339];
    int * v219 = v112->cache_vals;
    int v341 = (v216 * 2) + 1;
    int v220 = v219[v341];
    int * v221 = v112->cache_vals;
    int v343 = (((((int)((unsigned int)((int)((unsigned int)v120 >> 2)) >> 1)) & 1) * 2) + ((((v146 + ((~(((v148 ^ -1) | (-(v148 ^ -1))) >> 31)) & 2)) - (v150 + ((~(((v152 ^ -1) | (-(v152 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
    v221[v343] = v218;
    int * v223 = v112->cache_vals;
    int v346 = ((((((int)((unsigned int)((int)((unsigned int)v120 >> 2)) >> 1)) & 1) * 2) + ((((v146 + ((~(((v148 ^ -1) | (-(v148 ^ -1))) >> 31)) & 2)) - (v150 + ((~(((v152 ^ -1) | (-(v152 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
    v223[v346] = v220;
    int * v225 = v112->cache_tags;
    int v349 = ((((int)((unsigned int)((int)((unsigned int)v120 >> 2)) >> 1)) & 1) * 2) + ((((v146 + ((~(((v148 ^ -1) | (-(v148 ^ -1))) >> 31)) & 2)) - (v150 + ((~(((v152 ^ -1) | (-(v152 ^ -1))) >> 31)) & 2))) >> 31) & 1);
    int v350 = (int)((unsigned int)((int)((unsigned int)v120 >> 2)) >> 1);
    v225[v349] = v350;
    int * v227 = v112->cache_dirty;
    v227[v349] = 0;
    int * v229 = v112->cache_age;
    v229[v349] = 1;
    int * v231 = v112->cache_age;
    int v232 = v231[v349];
    int * v233 = v112->cache_age;
    int v234 = v233[v258];
    int * v235 = v112->cache_age;
    int v358 = v234 + ((int)((unsigned int)(v234 - v232) >> 31));
    v235[v258] = v358;
    int * v237 = v112->cache_age;
    int v238 = v237[v260];
    int * v239 = v112->cache_age;
    int v361 = v238 + ((int)((unsigned int)(v238 - v232) >> 31));
    v239[v260] = v361;
    int * v241 = v112->cache_age;
    v241[v349] = 0;
    v244 = v349;
  }
  int v364 = (v244 * 2) + (((int)((unsigned int)v120 >> 2)) & 1);
  int v245 = v131[v364];
  int * v246 = v112->regs;
  v246[14] = v245;
  struct StateT * v248 = slot_8(v112);
  return v248;
}

struct StateT * slot_31(struct StateT * v1484) {
  int v1485 = v1484->timer;
  int v1491 = v1485 + 1;
  v1484->timer = v1491;
  int * v1487 = v1484->regs;
  v1487[10] = 0;
  struct StateT * v1489 = slot_33(v1484);
  return v1489;
}

struct StateT * slot_3(struct StateT * v40) {
  int * v41 = v40->saved_regs;
  int * v42 = v40->regs;
  int v43 = v42[12];
  v41[12] = v43;
  int v45 = v40->timer;
  int v55 = v45 + 1;
  v40->timer = v55;
  int * v47 = v40->regs;
  v47[12] = 0;
  struct StateT * v49 = slot_4(v40);
  return v49;
}

struct StateT * slot_26(struct StateT * v1359) {
  int v1360 = v1359->timer;
  int v1364 = v1360 + 1;
  v1359->timer = v1364;
  struct StateT * v1362 = slot_27(v1359);
  return v1362;
}

struct StateT * slot_10(struct StateT * v678) {
  int v679 = v678->timer;
  int v682 = v679 + 1;
  v678->timer = v682;
  return v678;
}

struct StateT * slot_1(struct StateT * v19) {
  int v20 = v19->timer;
  int v26 = v20 + 1;
  v19->timer = v26;
  int * v22 = v19->regs;
  v22[10] = 1;
  struct StateT * v24 = slot_2(v19);
  return v24;
}

struct StateT * slot_19(struct StateT * v829) {
  int v830 = v829->timer;
  int v833 = v830 + 1;
  v829->timer = v833;
  return v829;
}

struct StateT * slot_13(struct StateT * v691) {
  int * v692 = v691->saved_regs;
  int * v693 = v691->regs;
  int v694 = v693[11];
  v692[11] = v694;
  int v696 = v691->timer;
  int v708 = v696 + 1;
  v691->timer = v708;
  int * v698 = v691->regs;
  int v699 = v698[11];
  int * v700 = v691->regs;
  int v711 = v699 + -1;
  v700[11] = v711;
  struct StateT * v702 = slot_14(v691);
  return v702;
}

struct StateT * slot_24(struct StateT * v1109) {
  int v1110 = v1109->timer;
  int v1243 = v1110 + 1;
  v1109->timer = v1243;
  int * v1112 = v1109->regs;
  int v1113 = v1112[13];
  int * v1114 = v1109->cache_tags;
  int v1247 = (((int)((unsigned int)((int)((unsigned int)v1113 >> 2)) >> 1)) & 1) * 2;
  int v1115 = v1114[v1247];
  int * v1116 = v1109->cache_tags;
  int v1249 = ((((int)((unsigned int)((int)((unsigned int)v1113 >> 2)) >> 1)) & 1) * 2) + 1;
  int v1117 = v1116[v1249];
  int * v1118 = v1109->cache_tags;
  int v1251 = 4 + ((((int)((unsigned int)((int)((unsigned int)v1113 >> 2)) >> 1)) & 3) * 2);
  int v1119 = v1118[v1251];
  int * v1120 = v1109->cache_tags;
  int v1253 = (4 + ((((int)((unsigned int)((int)((unsigned int)v1113 >> 2)) >> 1)) & 3) * 2)) + 1;
  int v1121 = v1120[v1253];
  int v1122 = v1109->timer;
  int v1254 = v1122 + ((100 ^ (((~(((v1119 ^ ((int)((unsigned int)((int)((unsigned int)v1113 >> 2)) >> 1))) | (-(v1119 ^ ((int)((unsigned int)((int)((unsigned int)v1113 >> 2)) >> 1))))) >> 31)) | (~(((v1121 ^ ((int)((unsigned int)((int)((unsigned int)v1113 >> 2)) >> 1))) | (-(v1121 ^ ((int)((unsigned int)((int)((unsigned int)v1113 >> 2)) >> 1))))) >> 31))) & 104)) ^ (((~(((v1115 ^ ((int)((unsigned int)((int)((unsigned int)v1113 >> 2)) >> 1))) | (-(v1115 ^ ((int)((unsigned int)((int)((unsigned int)v1113 >> 2)) >> 1))))) >> 31)) | (~(((v1117 ^ ((int)((unsigned int)((int)((unsigned int)v1113 >> 2)) >> 1))) | (-(v1117 ^ ((int)((unsigned int)((int)((unsigned int)v1113 >> 2)) >> 1))))) >> 31))) & (1 ^ (100 ^ (((~(((v1119 ^ ((int)((unsigned int)((int)((unsigned int)v1113 >> 2)) >> 1))) | (-(v1119 ^ ((int)((unsigned int)((int)((unsigned int)v1113 >> 2)) >> 1))))) >> 31)) | (~(((v1121 ^ ((int)((unsigned int)((int)((unsigned int)v1113 >> 2)) >> 1))) | (-(v1121 ^ ((int)((unsigned int)((int)((unsigned int)v1113 >> 2)) >> 1))))) >> 31))) & 104)))));
  v1109->timer = v1254;
  int * v1124 = v1109->cache_vals;
  bool v1255 = !(((~(((v1115 ^ ((int)((unsigned int)((int)((unsigned int)v1113 >> 2)) >> 1))) | (-(v1115 ^ ((int)((unsigned int)((int)((unsigned int)v1113 >> 2)) >> 1))))) >> 31)) | (~(((v1117 ^ ((int)((unsigned int)((int)((unsigned int)v1113 >> 2)) >> 1))) | (-(v1117 ^ ((int)((unsigned int)((int)((unsigned int)v1113 >> 2)) >> 1))))) >> 31))) == 0);
  int v1237;
  if (v1255) {
    int * v1125 = v1109->cache_age;
    int v1257 = ((((int)((unsigned int)((int)((unsigned int)v1113 >> 2)) >> 1)) & 1) * 2) + ((~(((v1117 ^ ((int)((unsigned int)((int)((unsigned int)v1113 >> 2)) >> 1))) | (-(v1117 ^ ((int)((unsigned int)((int)((unsigned int)v1113 >> 2)) >> 1))))) >> 31)) & 1);
    int v1126 = v1125[v1257];
    int * v1127 = v1109->cache_age;
    int v1128 = v1127[v1247];
    int * v1129 = v1109->cache_age;
    int v1260 = v1128 + ((int)((unsigned int)(v1128 - v1126) >> 31));
    v1129[v1247] = v1260;
    int * v1131 = v1109->cache_age;
    int v1132 = v1131[v1249];
    int * v1133 = v1109->cache_age;
    int v1263 = v1132 + ((int)((unsigned int)(v1132 - v1126) >> 31));
    v1133[v1249] = v1263;
    int * v1135 = v1109->cache_age;
    v1135[v1257] = 0;
    v1237 = v1257;
  } else {
    int * v1138 = v1109->cache_age;
    int v1267 = (((int)((unsigned int)((int)((unsigned int)v1113 >> 2)) >> 1)) & 1) * 2;
    int v1139 = v1138[v1267];
    int * v1140 = v1109->cache_tags;
    int v1141 = v1140[v1267];
    int * v1142 = v1109->cache_age;
    int v1143 = v1142[v1249];
    int * v1144 = v1109->cache_tags;
    int v1145 = v1144[v1249];
    bool v1271 = !(((~(((v1119 ^ ((int)((unsigned int)((int)((unsigned int)v1113 >> 2)) >> 1))) | (-(v1119 ^ ((int)((unsigned int)((int)((unsigned int)v1113 >> 2)) >> 1))))) >> 31)) | (~(((v1121 ^ ((int)((unsigned int)((int)((unsigned int)v1113 >> 2)) >> 1))) | (-(v1121 ^ ((int)((unsigned int)((int)((unsigned int)v1113 >> 2)) >> 1))))) >> 31))) == 0);
    int v1209;
    if (v1271) {
      int * v1146 = v1109->cache_age;
      int v1273 = (4 + ((((int)((unsigned int)((int)((unsigned int)v1113 >> 2)) >> 1)) & 3) * 2)) + ((~(((v1121 ^ ((int)((unsigned int)((int)((unsigned int)v1113 >> 2)) >> 1))) | (-(v1121 ^ ((int)((unsigned int)((int)((unsigned int)v1113 >> 2)) >> 1))))) >> 31)) & 1);
      int v1147 = v1146[v1273];
      int * v1148 = v1109->cache_age;
      int v1149 = v1148[v1251];
      int * v1150 = v1109->cache_age;
      int v1276 = v1149 + ((int)((unsigned int)(v1149 - v1147) >> 31));
      v1150[v1251] = v1276;
      int * v1152 = v1109->cache_age;
      int v1153 = v1152[v1253];
      int * v1154 = v1109->cache_age;
      int v1279 = v1153 + ((int)((unsigned int)(v1153 - v1147) >> 31));
      v1154[v1253] = v1279;
      int * v1156 = v1109->cache_age;
      v1156[v1273] = 0;
      v1209 = v1273;
    } else {
      int * v1159 = v1109->cache_age;
      int v1283 = 4 + ((((int)((unsigned int)((int)((unsigned int)v1113 >> 2)) >> 1)) & 3) * 2);
      int v1160 = v1159[v1283];
      int * v1161 = v1109->cache_tags;
      int v1162 = v1161[v1283];
      int * v1163 = v1109->cache_age;
      int v1164 = v1163[v1253];
      int * v1165 = v1109->cache_tags;
      int v1166 = v1165[v1253];
      int * v1167 = v1109->cache_dirty;
      int v1288 = (4 + ((((int)((unsigned int)((int)((unsigned int)v1113 >> 2)) >> 1)) & 3) * 2)) + ((((v1160 + ((~(((v1162 ^ -1) | (-(v1162 ^ -1))) >> 31)) & 2)) - (v1164 + ((~(((v1166 ^ -1) | (-(v1166 ^ -1))) >> 31)) & 2))) >> 31) & 1);
      int v1168 = v1167[v1288];
      bool v1289 = !(v1168 == 0);
      if (v1289) {
        int * v1169 = v1109->cache_tags;
        int v1170 = v1169[v1288];
        int * v1171 = v1109->cache_vals;
        int v1292 = ((4 + ((((int)((unsigned int)((int)((unsigned int)v1113 >> 2)) >> 1)) & 3) * 2)) + ((((v1160 + ((~(((v1162 ^ -1) | (-(v1162 ^ -1))) >> 31)) & 2)) - (v1164 + ((~(((v1166 ^ -1) | (-(v1166 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
        int v1172 = v1171[v1292];
        int * v1173 = v1109->cache_vals;
        int v1294 = (((4 + ((((int)((unsigned int)((int)((unsigned int)v1113 >> 2)) >> 1)) & 3) * 2)) + ((((v1160 + ((~(((v1162 ^ -1) | (-(v1162 ^ -1))) >> 31)) & 2)) - (v1164 + ((~(((v1166 ^ -1) | (-(v1166 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
        int v1174 = v1173[v1294];
        int * v1175 = v1109->mem;
        int v1296 = v1170 * 2;
        v1175[v1296] = v1172;
        int * v1177 = v1109->mem;
        int v1299 = (v1170 * 2) + 1;
        v1177[v1299] = v1174;
        ;
      } else {
        ;
      }
      int * v1182 = v1109->mem;
      int v1304 = ((int)((unsigned int)((int)((unsigned int)v1113 >> 2)) >> 1)) * 2;
      int v1183 = v1182[v1304];
      int * v1184 = v1109->mem;
      int v1306 = (((int)((unsigned int)((int)((unsigned int)v1113 >> 2)) >> 1)) * 2) + 1;
      int v1185 = v1184[v1306];
      int * v1186 = v1109->cache_vals;
      int v1308 = ((4 + ((((int)((unsigned int)((int)((unsigned int)v1113 >> 2)) >> 1)) & 3) * 2)) + ((((v1160 + ((~(((v1162 ^ -1) | (-(v1162 ^ -1))) >> 31)) & 2)) - (v1164 + ((~(((v1166 ^ -1) | (-(v1166 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
      v1186[v1308] = v1183;
      int * v1188 = v1109->cache_vals;
      int v1311 = (((4 + ((((int)((unsigned int)((int)((unsigned int)v1113 >> 2)) >> 1)) & 3) * 2)) + ((((v1160 + ((~(((v1162 ^ -1) | (-(v1162 ^ -1))) >> 31)) & 2)) - (v1164 + ((~(((v1166 ^ -1) | (-(v1166 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
      v1188[v1311] = v1185;
      int * v1190 = v1109->cache_tags;
      int v1314 = (int)((unsigned int)((int)((unsigned int)v1113 >> 2)) >> 1);
      v1190[v1288] = v1314;
      int * v1192 = v1109->cache_dirty;
      v1192[v1288] = 0;
      int * v1194 = v1109->cache_age;
      v1194[v1288] = 1;
      int * v1196 = v1109->cache_age;
      int v1197 = v1196[v1288];
      int * v1198 = v1109->cache_age;
      int v1199 = v1198[v1251];
      int * v1200 = v1109->cache_age;
      int v1322 = v1199 + ((int)((unsigned int)(v1199 - v1197) >> 31));
      v1200[v1251] = v1322;
      int * v1202 = v1109->cache_age;
      int v1203 = v1202[v1253];
      int * v1204 = v1109->cache_age;
      int v1325 = v1203 + ((int)((unsigned int)(v1203 - v1197) >> 31));
      v1204[v1253] = v1325;
      int * v1206 = v1109->cache_age;
      v1206[v1288] = 0;
      v1209 = v1288;
    }
    int * v1210 = v1109->cache_vals;
    int v1328 = v1209 * 2;
    int v1211 = v1210[v1328];
    int * v1212 = v1109->cache_vals;
    int v1330 = (v1209 * 2) + 1;
    int v1213 = v1212[v1330];
    int * v1214 = v1109->cache_vals;
    int v1332 = (((((int)((unsigned int)((int)((unsigned int)v1113 >> 2)) >> 1)) & 1) * 2) + ((((v1139 + ((~(((v1141 ^ -1) | (-(v1141 ^ -1))) >> 31)) & 2)) - (v1143 + ((~(((v1145 ^ -1) | (-(v1145 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
    v1214[v1332] = v1211;
    int * v1216 = v1109->cache_vals;
    int v1335 = ((((((int)((unsigned int)((int)((unsigned int)v1113 >> 2)) >> 1)) & 1) * 2) + ((((v1139 + ((~(((v1141 ^ -1) | (-(v1141 ^ -1))) >> 31)) & 2)) - (v1143 + ((~(((v1145 ^ -1) | (-(v1145 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
    v1216[v1335] = v1213;
    int * v1218 = v1109->cache_tags;
    int v1338 = ((((int)((unsigned int)((int)((unsigned int)v1113 >> 2)) >> 1)) & 1) * 2) + ((((v1139 + ((~(((v1141 ^ -1) | (-(v1141 ^ -1))) >> 31)) & 2)) - (v1143 + ((~(((v1145 ^ -1) | (-(v1145 ^ -1))) >> 31)) & 2))) >> 31) & 1);
    int v1339 = (int)((unsigned int)((int)((unsigned int)v1113 >> 2)) >> 1);
    v1218[v1338] = v1339;
    int * v1220 = v1109->cache_dirty;
    v1220[v1338] = 0;
    int * v1222 = v1109->cache_age;
    v1222[v1338] = 1;
    int * v1224 = v1109->cache_age;
    int v1225 = v1224[v1338];
    int * v1226 = v1109->cache_age;
    int v1227 = v1226[v1247];
    int * v1228 = v1109->cache_age;
    int v1347 = v1227 + ((int)((unsigned int)(v1227 - v1225) >> 31));
    v1228[v1247] = v1347;
    int * v1230 = v1109->cache_age;
    int v1231 = v1230[v1249];
    int * v1232 = v1109->cache_age;
    int v1350 = v1231 + ((int)((unsigned int)(v1231 - v1225) >> 31));
    v1232[v1249] = v1350;
    int * v1234 = v1109->cache_age;
    v1234[v1338] = 0;
    v1237 = v1338;
  }
  int v1353 = (v1237 * 2) + (((int)((unsigned int)v1113 >> 2)) & 1);
  int v1238 = v1124[v1353];
  int * v1239 = v1109->regs;
  v1239[15] = v1238;
  struct StateT * v1241 = slot_26(v1109);
  return v1241;
}

struct StateT * slot_0(struct StateT * v2) {
  int v3 = v2->timer;
  int v11 = v3 + 1;
  v2->timer = v11;
  int * v5 = v2->regs;
  int v6 = v5[10];
  int * v7 = v2->regs;
  v7[11] = v6;
  struct StateT * v9 = slot_1(v2);
  return v9;
}

struct StateT * slot_14(struct StateT * v714) {
  int * v715 = v714->saved_regs;
  int * v716 = v714->regs;
  int v717 = v716[12];
  v715[12] = v717;
  int v719 = v714->timer;
  int v731 = v719 + 1;
  v714->timer = v731;
  int * v721 = v714->regs;
  int v722 = v721[12];
  int * v723 = v714->regs;
  int v734 = v722 + 4;
  v723[12] = v734;
  struct StateT * v725 = slot_15(v714);
  return v725;
}

struct StateT * slot_28(struct StateT * v1390) {
  int * v1391 = v1390->saved_regs;
  int * v1392 = v1390->regs;
  int v1393 = v1392[12];
  v1391[12] = v1393;
  int v1395 = v1390->timer;
  int v1407 = v1395 + 1;
  v1390->timer = v1407;
  int * v1397 = v1390->regs;
  int v1398 = v1397[12];
  int * v1399 = v1390->regs;
  int v1410 = v1398 + 4;
  v1399[12] = v1410;
  struct StateT * v1401 = slot_29(v1390);
  return v1401;
}

struct StateT * slot_32(struct StateT * v1497) {
  int v1498 = v1497->timer;
  int v1502 = v1498 + 1;
  v1497->timer = v1502;
  struct StateT * v1500 = slot_34(v1497);
  return v1500;
}

struct StateT * slot_17(struct StateT * v808) {
  int v809 = v808->timer;
  int v815 = v809 + 1;
  v808->timer = v815;
  int * v811 = v808->regs;
  v811[10] = 0;
  struct StateT * v813 = slot_19(v808);
  return v813;
}

struct StateT * slot_20(struct StateT * v834) {
  int * v835 = v834->regs;
  int v836 = v835[11];
  bool v847 = !(v836 == 0);
  struct StateT * v843;
  if (v847) {
    int v837 = v834->timer;
    int v848 = v837 + 15;
    v834->timer = v848;
    struct StateT * v839 = slot_22(v834);
    v843 = v839;
  } else {
    struct StateT * v841 = slot_23(v834);
    v843 = v841;
  }
  return v843;
}

struct StateT * slot_33(struct StateT * v1505) {
  int v1506 = v1505->timer;
  int v1509 = v1506 + 1;
  v1505->timer = v1509;
  return v1505;
}

struct StateT * slot_36(struct StateT * v1767) {
  int * v1768 = v1767->saved_regs;
  int * v1769 = v1767->regs;
  int v1770 = v1769[15];
  v1768[15] = v1770;
  int v1772 = v1767->timer;
  int v1909 = v1772 + 1;
  v1767->timer = v1909;
  int * v1774 = v1767->regs;
  int v1775 = v1774[13];
  int * v1776 = v1767->cache_tags;
  int v1913 = (((int)((unsigned int)((int)((unsigned int)v1775 >> 2)) >> 1)) & 1) * 2;
  int v1777 = v1776[v1913];
  int * v1778 = v1767->cache_tags;
  int v1915 = ((((int)((unsigned int)((int)((unsigned int)v1775 >> 2)) >> 1)) & 1) * 2) + 1;
  int v1779 = v1778[v1915];
  int * v1780 = v1767->cache_tags;
  int v1917 = 4 + ((((int)((unsigned int)((int)((unsigned int)v1775 >> 2)) >> 1)) & 3) * 2);
  int v1781 = v1780[v1917];
  int * v1782 = v1767->cache_tags;
  int v1919 = (4 + ((((int)((unsigned int)((int)((unsigned int)v1775 >> 2)) >> 1)) & 3) * 2)) + 1;
  int v1783 = v1782[v1919];
  int v1784 = v1767->timer;
  int v1920 = v1784 + ((100 ^ (((~(((v1781 ^ ((int)((unsigned int)((int)((unsigned int)v1775 >> 2)) >> 1))) | (-(v1781 ^ ((int)((unsigned int)((int)((unsigned int)v1775 >> 2)) >> 1))))) >> 31)) | (~(((v1783 ^ ((int)((unsigned int)((int)((unsigned int)v1775 >> 2)) >> 1))) | (-(v1783 ^ ((int)((unsigned int)((int)((unsigned int)v1775 >> 2)) >> 1))))) >> 31))) & 104)) ^ (((~(((v1777 ^ ((int)((unsigned int)((int)((unsigned int)v1775 >> 2)) >> 1))) | (-(v1777 ^ ((int)((unsigned int)((int)((unsigned int)v1775 >> 2)) >> 1))))) >> 31)) | (~(((v1779 ^ ((int)((unsigned int)((int)((unsigned int)v1775 >> 2)) >> 1))) | (-(v1779 ^ ((int)((unsigned int)((int)((unsigned int)v1775 >> 2)) >> 1))))) >> 31))) & (1 ^ (100 ^ (((~(((v1781 ^ ((int)((unsigned int)((int)((unsigned int)v1775 >> 2)) >> 1))) | (-(v1781 ^ ((int)((unsigned int)((int)((unsigned int)v1775 >> 2)) >> 1))))) >> 31)) | (~(((v1783 ^ ((int)((unsigned int)((int)((unsigned int)v1775 >> 2)) >> 1))) | (-(v1783 ^ ((int)((unsigned int)((int)((unsigned int)v1775 >> 2)) >> 1))))) >> 31))) & 104)))));
  v1767->timer = v1920;
  int * v1786 = v1767->cache_vals;
  bool v1921 = !(((~(((v1777 ^ ((int)((unsigned int)((int)((unsigned int)v1775 >> 2)) >> 1))) | (-(v1777 ^ ((int)((unsigned int)((int)((unsigned int)v1775 >> 2)) >> 1))))) >> 31)) | (~(((v1779 ^ ((int)((unsigned int)((int)((unsigned int)v1775 >> 2)) >> 1))) | (-(v1779 ^ ((int)((unsigned int)((int)((unsigned int)v1775 >> 2)) >> 1))))) >> 31))) == 0);
  int v1899;
  if (v1921) {
    int * v1787 = v1767->cache_age;
    int v1923 = ((((int)((unsigned int)((int)((unsigned int)v1775 >> 2)) >> 1)) & 1) * 2) + ((~(((v1779 ^ ((int)((unsigned int)((int)((unsigned int)v1775 >> 2)) >> 1))) | (-(v1779 ^ ((int)((unsigned int)((int)((unsigned int)v1775 >> 2)) >> 1))))) >> 31)) & 1);
    int v1788 = v1787[v1923];
    int * v1789 = v1767->cache_age;
    int v1790 = v1789[v1913];
    int * v1791 = v1767->cache_age;
    int v1926 = v1790 + ((int)((unsigned int)(v1790 - v1788) >> 31));
    v1791[v1913] = v1926;
    int * v1793 = v1767->cache_age;
    int v1794 = v1793[v1915];
    int * v1795 = v1767->cache_age;
    int v1929 = v1794 + ((int)((unsigned int)(v1794 - v1788) >> 31));
    v1795[v1915] = v1929;
    int * v1797 = v1767->cache_age;
    v1797[v1923] = 0;
    v1899 = v1923;
  } else {
    int * v1800 = v1767->cache_age;
    int v1933 = (((int)((unsigned int)((int)((unsigned int)v1775 >> 2)) >> 1)) & 1) * 2;
    int v1801 = v1800[v1933];
    int * v1802 = v1767->cache_tags;
    int v1803 = v1802[v1933];
    int * v1804 = v1767->cache_age;
    int v1805 = v1804[v1915];
    int * v1806 = v1767->cache_tags;
    int v1807 = v1806[v1915];
    bool v1937 = !(((~(((v1781 ^ ((int)((unsigned int)((int)((unsigned int)v1775 >> 2)) >> 1))) | (-(v1781 ^ ((int)((unsigned int)((int)((unsigned int)v1775 >> 2)) >> 1))))) >> 31)) | (~(((v1783 ^ ((int)((unsigned int)((int)((unsigned int)v1775 >> 2)) >> 1))) | (-(v1783 ^ ((int)((unsigned int)((int)((unsigned int)v1775 >> 2)) >> 1))))) >> 31))) == 0);
    int v1871;
    if (v1937) {
      int * v1808 = v1767->cache_age;
      int v1939 = (4 + ((((int)((unsigned int)((int)((unsigned int)v1775 >> 2)) >> 1)) & 3) * 2)) + ((~(((v1783 ^ ((int)((unsigned int)((int)((unsigned int)v1775 >> 2)) >> 1))) | (-(v1783 ^ ((int)((unsigned int)((int)((unsigned int)v1775 >> 2)) >> 1))))) >> 31)) & 1);
      int v1809 = v1808[v1939];
      int * v1810 = v1767->cache_age;
      int v1811 = v1810[v1917];
      int * v1812 = v1767->cache_age;
      int v1942 = v1811 + ((int)((unsigned int)(v1811 - v1809) >> 31));
      v1812[v1917] = v1942;
      int * v1814 = v1767->cache_age;
      int v1815 = v1814[v1919];
      int * v1816 = v1767->cache_age;
      int v1945 = v1815 + ((int)((unsigned int)(v1815 - v1809) >> 31));
      v1816[v1919] = v1945;
      int * v1818 = v1767->cache_age;
      v1818[v1939] = 0;
      v1871 = v1939;
    } else {
      int * v1821 = v1767->cache_age;
      int v1949 = 4 + ((((int)((unsigned int)((int)((unsigned int)v1775 >> 2)) >> 1)) & 3) * 2);
      int v1822 = v1821[v1949];
      int * v1823 = v1767->cache_tags;
      int v1824 = v1823[v1949];
      int * v1825 = v1767->cache_age;
      int v1826 = v1825[v1919];
      int * v1827 = v1767->cache_tags;
      int v1828 = v1827[v1919];
      int * v1829 = v1767->cache_dirty;
      int v1954 = (4 + ((((int)((unsigned int)((int)((unsigned int)v1775 >> 2)) >> 1)) & 3) * 2)) + ((((v1822 + ((~(((v1824 ^ -1) | (-(v1824 ^ -1))) >> 31)) & 2)) - (v1826 + ((~(((v1828 ^ -1) | (-(v1828 ^ -1))) >> 31)) & 2))) >> 31) & 1);
      int v1830 = v1829[v1954];
      bool v1955 = !(v1830 == 0);
      if (v1955) {
        int * v1831 = v1767->cache_tags;
        int v1832 = v1831[v1954];
        int * v1833 = v1767->cache_vals;
        int v1958 = ((4 + ((((int)((unsigned int)((int)((unsigned int)v1775 >> 2)) >> 1)) & 3) * 2)) + ((((v1822 + ((~(((v1824 ^ -1) | (-(v1824 ^ -1))) >> 31)) & 2)) - (v1826 + ((~(((v1828 ^ -1) | (-(v1828 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
        int v1834 = v1833[v1958];
        int * v1835 = v1767->cache_vals;
        int v1960 = (((4 + ((((int)((unsigned int)((int)((unsigned int)v1775 >> 2)) >> 1)) & 3) * 2)) + ((((v1822 + ((~(((v1824 ^ -1) | (-(v1824 ^ -1))) >> 31)) & 2)) - (v1826 + ((~(((v1828 ^ -1) | (-(v1828 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
        int v1836 = v1835[v1960];
        int * v1837 = v1767->mem;
        int v1962 = v1832 * 2;
        v1837[v1962] = v1834;
        int * v1839 = v1767->mem;
        int v1965 = (v1832 * 2) + 1;
        v1839[v1965] = v1836;
        ;
      } else {
        ;
      }
      int * v1844 = v1767->mem;
      int v1970 = ((int)((unsigned int)((int)((unsigned int)v1775 >> 2)) >> 1)) * 2;
      int v1845 = v1844[v1970];
      int * v1846 = v1767->mem;
      int v1972 = (((int)((unsigned int)((int)((unsigned int)v1775 >> 2)) >> 1)) * 2) + 1;
      int v1847 = v1846[v1972];
      int * v1848 = v1767->cache_vals;
      int v1974 = ((4 + ((((int)((unsigned int)((int)((unsigned int)v1775 >> 2)) >> 1)) & 3) * 2)) + ((((v1822 + ((~(((v1824 ^ -1) | (-(v1824 ^ -1))) >> 31)) & 2)) - (v1826 + ((~(((v1828 ^ -1) | (-(v1828 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
      v1848[v1974] = v1845;
      int * v1850 = v1767->cache_vals;
      int v1977 = (((4 + ((((int)((unsigned int)((int)((unsigned int)v1775 >> 2)) >> 1)) & 3) * 2)) + ((((v1822 + ((~(((v1824 ^ -1) | (-(v1824 ^ -1))) >> 31)) & 2)) - (v1826 + ((~(((v1828 ^ -1) | (-(v1828 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
      v1850[v1977] = v1847;
      int * v1852 = v1767->cache_tags;
      int v1980 = (int)((unsigned int)((int)((unsigned int)v1775 >> 2)) >> 1);
      v1852[v1954] = v1980;
      int * v1854 = v1767->cache_dirty;
      v1854[v1954] = 0;
      int * v1856 = v1767->cache_age;
      v1856[v1954] = 1;
      int * v1858 = v1767->cache_age;
      int v1859 = v1858[v1954];
      int * v1860 = v1767->cache_age;
      int v1861 = v1860[v1917];
      int * v1862 = v1767->cache_age;
      int v1988 = v1861 + ((int)((unsigned int)(v1861 - v1859) >> 31));
      v1862[v1917] = v1988;
      int * v1864 = v1767->cache_age;
      int v1865 = v1864[v1919];
      int * v1866 = v1767->cache_age;
      int v1991 = v1865 + ((int)((unsigned int)(v1865 - v1859) >> 31));
      v1866[v1919] = v1991;
      int * v1868 = v1767->cache_age;
      v1868[v1954] = 0;
      v1871 = v1954;
    }
    int * v1872 = v1767->cache_vals;
    int v1994 = v1871 * 2;
    int v1873 = v1872[v1994];
    int * v1874 = v1767->cache_vals;
    int v1996 = (v1871 * 2) + 1;
    int v1875 = v1874[v1996];
    int * v1876 = v1767->cache_vals;
    int v1998 = (((((int)((unsigned int)((int)((unsigned int)v1775 >> 2)) >> 1)) & 1) * 2) + ((((v1801 + ((~(((v1803 ^ -1) | (-(v1803 ^ -1))) >> 31)) & 2)) - (v1805 + ((~(((v1807 ^ -1) | (-(v1807 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
    v1876[v1998] = v1873;
    int * v1878 = v1767->cache_vals;
    int v2001 = ((((((int)((unsigned int)((int)((unsigned int)v1775 >> 2)) >> 1)) & 1) * 2) + ((((v1801 + ((~(((v1803 ^ -1) | (-(v1803 ^ -1))) >> 31)) & 2)) - (v1805 + ((~(((v1807 ^ -1) | (-(v1807 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
    v1878[v2001] = v1875;
    int * v1880 = v1767->cache_tags;
    int v2004 = ((((int)((unsigned int)((int)((unsigned int)v1775 >> 2)) >> 1)) & 1) * 2) + ((((v1801 + ((~(((v1803 ^ -1) | (-(v1803 ^ -1))) >> 31)) & 2)) - (v1805 + ((~(((v1807 ^ -1) | (-(v1807 ^ -1))) >> 31)) & 2))) >> 31) & 1);
    int v2005 = (int)((unsigned int)((int)((unsigned int)v1775 >> 2)) >> 1);
    v1880[v2004] = v2005;
    int * v1882 = v1767->cache_dirty;
    v1882[v2004] = 0;
    int * v1884 = v1767->cache_age;
    v1884[v2004] = 1;
    int * v1886 = v1767->cache_age;
    int v1887 = v1886[v2004];
    int * v1888 = v1767->cache_age;
    int v1889 = v1888[v1913];
    int * v1890 = v1767->cache_age;
    int v2013 = v1889 + ((int)((unsigned int)(v1889 - v1887) >> 31));
    v1890[v1913] = v2013;
    int * v1892 = v1767->cache_age;
    int v1893 = v1892[v1915];
    int * v1894 = v1767->cache_age;
    int v2016 = v1893 + ((int)((unsigned int)(v1893 - v1887) >> 31));
    v1894[v1915] = v2016;
    int * v1896 = v1767->cache_age;
    v1896[v2004] = 0;
    v1899 = v2004;
  }
  int v2019 = (v1899 * 2) + (((int)((unsigned int)v1775 >> 2)) & 1);
  int v1900 = v1786[v2019];
  int * v1901 = v1767->regs;
  v1901[15] = v1900;
  struct StateT * v1903 = slot_37(v1767);
  return v1903;
}

struct StateT * slot_37(struct StateT * v2024) {
  int * v2025 = v2024->regs;
  int v2026 = v2025[11];
  bool v2045 = !(v2026 == 0);
  struct StateT * v2041;
  if (v2045) {
    struct StateT * v2027 = slot_26(v2024);
    v2041 = v2027;
  } else {
    int v2029 = v2024->timer;
    int v2048 = v2029 + 15;
    v2024->timer = v2048;
    int * v2031 = v2024->saved_regs;
    int v2032 = v2031[14];
    int * v2033 = v2024->regs;
    v2033[14] = v2032;
    int * v2035 = v2024->saved_regs;
    int v2036 = v2035[15];
    int * v2037 = v2024->regs;
    v2037[15] = v2036;
    struct StateT * v2039 = slot_23(v2024);
    v2041 = v2039;
  }
  return v2041;
}

struct StateT * snippet(struct StateT * v0) {
  struct StateT * v1 = slot_0(v0);
  return v1;
}

struct StateT * slot_8(struct StateT * v369) {
  int * v370 = v369->saved_regs;
  int * v371 = v369->regs;
  int v372 = v371[15];
  v370[15] = v372;
  int v374 = v369->timer;
  int v511 = v374 + 1;
  v369->timer = v511;
  int * v376 = v369->regs;
  int v377 = v376[13];
  int * v378 = v369->cache_tags;
  int v515 = (((int)((unsigned int)((int)((unsigned int)v377 >> 2)) >> 1)) & 1) * 2;
  int v379 = v378[v515];
  int * v380 = v369->cache_tags;
  int v517 = ((((int)((unsigned int)((int)((unsigned int)v377 >> 2)) >> 1)) & 1) * 2) + 1;
  int v381 = v380[v517];
  int * v382 = v369->cache_tags;
  int v519 = 4 + ((((int)((unsigned int)((int)((unsigned int)v377 >> 2)) >> 1)) & 3) * 2);
  int v383 = v382[v519];
  int * v384 = v369->cache_tags;
  int v521 = (4 + ((((int)((unsigned int)((int)((unsigned int)v377 >> 2)) >> 1)) & 3) * 2)) + 1;
  int v385 = v384[v521];
  int v386 = v369->timer;
  int v522 = v386 + ((100 ^ (((~(((v383 ^ ((int)((unsigned int)((int)((unsigned int)v377 >> 2)) >> 1))) | (-(v383 ^ ((int)((unsigned int)((int)((unsigned int)v377 >> 2)) >> 1))))) >> 31)) | (~(((v385 ^ ((int)((unsigned int)((int)((unsigned int)v377 >> 2)) >> 1))) | (-(v385 ^ ((int)((unsigned int)((int)((unsigned int)v377 >> 2)) >> 1))))) >> 31))) & 104)) ^ (((~(((v379 ^ ((int)((unsigned int)((int)((unsigned int)v377 >> 2)) >> 1))) | (-(v379 ^ ((int)((unsigned int)((int)((unsigned int)v377 >> 2)) >> 1))))) >> 31)) | (~(((v381 ^ ((int)((unsigned int)((int)((unsigned int)v377 >> 2)) >> 1))) | (-(v381 ^ ((int)((unsigned int)((int)((unsigned int)v377 >> 2)) >> 1))))) >> 31))) & (1 ^ (100 ^ (((~(((v383 ^ ((int)((unsigned int)((int)((unsigned int)v377 >> 2)) >> 1))) | (-(v383 ^ ((int)((unsigned int)((int)((unsigned int)v377 >> 2)) >> 1))))) >> 31)) | (~(((v385 ^ ((int)((unsigned int)((int)((unsigned int)v377 >> 2)) >> 1))) | (-(v385 ^ ((int)((unsigned int)((int)((unsigned int)v377 >> 2)) >> 1))))) >> 31))) & 104)))));
  v369->timer = v522;
  int * v388 = v369->cache_vals;
  bool v523 = !(((~(((v379 ^ ((int)((unsigned int)((int)((unsigned int)v377 >> 2)) >> 1))) | (-(v379 ^ ((int)((unsigned int)((int)((unsigned int)v377 >> 2)) >> 1))))) >> 31)) | (~(((v381 ^ ((int)((unsigned int)((int)((unsigned int)v377 >> 2)) >> 1))) | (-(v381 ^ ((int)((unsigned int)((int)((unsigned int)v377 >> 2)) >> 1))))) >> 31))) == 0);
  int v501;
  if (v523) {
    int * v389 = v369->cache_age;
    int v525 = ((((int)((unsigned int)((int)((unsigned int)v377 >> 2)) >> 1)) & 1) * 2) + ((~(((v381 ^ ((int)((unsigned int)((int)((unsigned int)v377 >> 2)) >> 1))) | (-(v381 ^ ((int)((unsigned int)((int)((unsigned int)v377 >> 2)) >> 1))))) >> 31)) & 1);
    int v390 = v389[v525];
    int * v391 = v369->cache_age;
    int v392 = v391[v515];
    int * v393 = v369->cache_age;
    int v528 = v392 + ((int)((unsigned int)(v392 - v390) >> 31));
    v393[v515] = v528;
    int * v395 = v369->cache_age;
    int v396 = v395[v517];
    int * v397 = v369->cache_age;
    int v531 = v396 + ((int)((unsigned int)(v396 - v390) >> 31));
    v397[v517] = v531;
    int * v399 = v369->cache_age;
    v399[v525] = 0;
    v501 = v525;
  } else {
    int * v402 = v369->cache_age;
    int v535 = (((int)((unsigned int)((int)((unsigned int)v377 >> 2)) >> 1)) & 1) * 2;
    int v403 = v402[v535];
    int * v404 = v369->cache_tags;
    int v405 = v404[v535];
    int * v406 = v369->cache_age;
    int v407 = v406[v517];
    int * v408 = v369->cache_tags;
    int v409 = v408[v517];
    bool v539 = !(((~(((v383 ^ ((int)((unsigned int)((int)((unsigned int)v377 >> 2)) >> 1))) | (-(v383 ^ ((int)((unsigned int)((int)((unsigned int)v377 >> 2)) >> 1))))) >> 31)) | (~(((v385 ^ ((int)((unsigned int)((int)((unsigned int)v377 >> 2)) >> 1))) | (-(v385 ^ ((int)((unsigned int)((int)((unsigned int)v377 >> 2)) >> 1))))) >> 31))) == 0);
    int v473;
    if (v539) {
      int * v410 = v369->cache_age;
      int v541 = (4 + ((((int)((unsigned int)((int)((unsigned int)v377 >> 2)) >> 1)) & 3) * 2)) + ((~(((v385 ^ ((int)((unsigned int)((int)((unsigned int)v377 >> 2)) >> 1))) | (-(v385 ^ ((int)((unsigned int)((int)((unsigned int)v377 >> 2)) >> 1))))) >> 31)) & 1);
      int v411 = v410[v541];
      int * v412 = v369->cache_age;
      int v413 = v412[v519];
      int * v414 = v369->cache_age;
      int v544 = v413 + ((int)((unsigned int)(v413 - v411) >> 31));
      v414[v519] = v544;
      int * v416 = v369->cache_age;
      int v417 = v416[v521];
      int * v418 = v369->cache_age;
      int v547 = v417 + ((int)((unsigned int)(v417 - v411) >> 31));
      v418[v521] = v547;
      int * v420 = v369->cache_age;
      v420[v541] = 0;
      v473 = v541;
    } else {
      int * v423 = v369->cache_age;
      int v551 = 4 + ((((int)((unsigned int)((int)((unsigned int)v377 >> 2)) >> 1)) & 3) * 2);
      int v424 = v423[v551];
      int * v425 = v369->cache_tags;
      int v426 = v425[v551];
      int * v427 = v369->cache_age;
      int v428 = v427[v521];
      int * v429 = v369->cache_tags;
      int v430 = v429[v521];
      int * v431 = v369->cache_dirty;
      int v556 = (4 + ((((int)((unsigned int)((int)((unsigned int)v377 >> 2)) >> 1)) & 3) * 2)) + ((((v424 + ((~(((v426 ^ -1) | (-(v426 ^ -1))) >> 31)) & 2)) - (v428 + ((~(((v430 ^ -1) | (-(v430 ^ -1))) >> 31)) & 2))) >> 31) & 1);
      int v432 = v431[v556];
      bool v557 = !(v432 == 0);
      if (v557) {
        int * v433 = v369->cache_tags;
        int v434 = v433[v556];
        int * v435 = v369->cache_vals;
        int v560 = ((4 + ((((int)((unsigned int)((int)((unsigned int)v377 >> 2)) >> 1)) & 3) * 2)) + ((((v424 + ((~(((v426 ^ -1) | (-(v426 ^ -1))) >> 31)) & 2)) - (v428 + ((~(((v430 ^ -1) | (-(v430 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
        int v436 = v435[v560];
        int * v437 = v369->cache_vals;
        int v562 = (((4 + ((((int)((unsigned int)((int)((unsigned int)v377 >> 2)) >> 1)) & 3) * 2)) + ((((v424 + ((~(((v426 ^ -1) | (-(v426 ^ -1))) >> 31)) & 2)) - (v428 + ((~(((v430 ^ -1) | (-(v430 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
        int v438 = v437[v562];
        int * v439 = v369->mem;
        int v564 = v434 * 2;
        v439[v564] = v436;
        int * v441 = v369->mem;
        int v567 = (v434 * 2) + 1;
        v441[v567] = v438;
        ;
      } else {
        ;
      }
      int * v446 = v369->mem;
      int v572 = ((int)((unsigned int)((int)((unsigned int)v377 >> 2)) >> 1)) * 2;
      int v447 = v446[v572];
      int * v448 = v369->mem;
      int v574 = (((int)((unsigned int)((int)((unsigned int)v377 >> 2)) >> 1)) * 2) + 1;
      int v449 = v448[v574];
      int * v450 = v369->cache_vals;
      int v576 = ((4 + ((((int)((unsigned int)((int)((unsigned int)v377 >> 2)) >> 1)) & 3) * 2)) + ((((v424 + ((~(((v426 ^ -1) | (-(v426 ^ -1))) >> 31)) & 2)) - (v428 + ((~(((v430 ^ -1) | (-(v430 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
      v450[v576] = v447;
      int * v452 = v369->cache_vals;
      int v579 = (((4 + ((((int)((unsigned int)((int)((unsigned int)v377 >> 2)) >> 1)) & 3) * 2)) + ((((v424 + ((~(((v426 ^ -1) | (-(v426 ^ -1))) >> 31)) & 2)) - (v428 + ((~(((v430 ^ -1) | (-(v430 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
      v452[v579] = v449;
      int * v454 = v369->cache_tags;
      int v582 = (int)((unsigned int)((int)((unsigned int)v377 >> 2)) >> 1);
      v454[v556] = v582;
      int * v456 = v369->cache_dirty;
      v456[v556] = 0;
      int * v458 = v369->cache_age;
      v458[v556] = 1;
      int * v460 = v369->cache_age;
      int v461 = v460[v556];
      int * v462 = v369->cache_age;
      int v463 = v462[v519];
      int * v464 = v369->cache_age;
      int v590 = v463 + ((int)((unsigned int)(v463 - v461) >> 31));
      v464[v519] = v590;
      int * v466 = v369->cache_age;
      int v467 = v466[v521];
      int * v468 = v369->cache_age;
      int v593 = v467 + ((int)((unsigned int)(v467 - v461) >> 31));
      v468[v521] = v593;
      int * v470 = v369->cache_age;
      v470[v556] = 0;
      v473 = v556;
    }
    int * v474 = v369->cache_vals;
    int v596 = v473 * 2;
    int v475 = v474[v596];
    int * v476 = v369->cache_vals;
    int v598 = (v473 * 2) + 1;
    int v477 = v476[v598];
    int * v478 = v369->cache_vals;
    int v600 = (((((int)((unsigned int)((int)((unsigned int)v377 >> 2)) >> 1)) & 1) * 2) + ((((v403 + ((~(((v405 ^ -1) | (-(v405 ^ -1))) >> 31)) & 2)) - (v407 + ((~(((v409 ^ -1) | (-(v409 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
    v478[v600] = v475;
    int * v480 = v369->cache_vals;
    int v603 = ((((((int)((unsigned int)((int)((unsigned int)v377 >> 2)) >> 1)) & 1) * 2) + ((((v403 + ((~(((v405 ^ -1) | (-(v405 ^ -1))) >> 31)) & 2)) - (v407 + ((~(((v409 ^ -1) | (-(v409 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
    v480[v603] = v477;
    int * v482 = v369->cache_tags;
    int v606 = ((((int)((unsigned int)((int)((unsigned int)v377 >> 2)) >> 1)) & 1) * 2) + ((((v403 + ((~(((v405 ^ -1) | (-(v405 ^ -1))) >> 31)) & 2)) - (v407 + ((~(((v409 ^ -1) | (-(v409 ^ -1))) >> 31)) & 2))) >> 31) & 1);
    int v607 = (int)((unsigned int)((int)((unsigned int)v377 >> 2)) >> 1);
    v482[v606] = v607;
    int * v484 = v369->cache_dirty;
    v484[v606] = 0;
    int * v486 = v369->cache_age;
    v486[v606] = 1;
    int * v488 = v369->cache_age;
    int v489 = v488[v606];
    int * v490 = v369->cache_age;
    int v491 = v490[v515];
    int * v492 = v369->cache_age;
    int v615 = v491 + ((int)((unsigned int)(v491 - v489) >> 31));
    v492[v515] = v615;
    int * v494 = v369->cache_age;
    int v495 = v494[v517];
    int * v496 = v369->cache_age;
    int v618 = v495 + ((int)((unsigned int)(v495 - v489) >> 31));
    v496[v517] = v618;
    int * v498 = v369->cache_age;
    v498[v606] = 0;
    v501 = v606;
  }
  int v621 = (v501 * 2) + (((int)((unsigned int)v377 >> 2)) & 1);
  int v502 = v388[v621];
  int * v503 = v369->regs;
  v503[15] = v502;
  struct StateT * v505 = slot_9(v369);
  return v505;
}

struct StateT * slot_27(struct StateT * v1367) {
  int * v1368 = v1367->saved_regs;
  int * v1369 = v1367->regs;
  int v1370 = v1369[11];
  v1368[11] = v1370;
  int v1372 = v1367->timer;
  int v1384 = v1372 + 1;
  v1367->timer = v1384;
  int * v1374 = v1367->regs;
  int v1375 = v1374[11];
  int * v1376 = v1367->regs;
  int v1387 = v1375 + -1;
  v1376[11] = v1387;
  struct StateT * v1378 = slot_28(v1367);
  return v1378;
}

struct StateT * slot_30(struct StateT * v1436) {
  int * v1437 = v1436->regs;
  int v1438 = v1437[14];
  int * v1439 = v1436->regs;
  int v1440 = v1439[15];
  bool v1465 = !(v1438 == v1440);
  struct StateT * v1459;
  if (v1465) {
    int v1441 = v1436->timer;
    int v1466 = v1441 + 15;
    v1436->timer = v1466;
    int * v1443 = v1436->saved_regs;
    int v1444 = v1443[11];
    int * v1445 = v1436->regs;
    v1445[11] = v1444;
    int * v1447 = v1436->saved_regs;
    int v1448 = v1447[12];
    int * v1449 = v1436->regs;
    v1449[12] = v1448;
    int * v1451 = v1436->saved_regs;
    int v1452 = v1451[13];
    int * v1453 = v1436->regs;
    v1453[13] = v1452;
    struct StateT * v1455 = slot_31(v1436);
    v1459 = v1455;
  } else {
    struct StateT * v1457 = slot_32(v1436);
    v1459 = v1457;
  }
  return v1459;
}

struct StateT * slot_4(struct StateT * v60) {
  int v61 = v60->timer;
  int v69 = v61 + 1;
  v60->timer = v69;
  int * v63 = v60->regs;
  int v64 = v63[12];
  int * v65 = v60->regs;
  int v73 = v64 + 16;
  v65[12] = v73;
  struct StateT * v67 = slot_5(v60);
  return v67;
}

struct StateT * slot_15(struct StateT * v737) {
  int * v738 = v737->saved_regs;
  int * v739 = v737->regs;
  int v740 = v739[13];
  v738[13] = v740;
  int v742 = v737->timer;
  int v754 = v742 + 1;
  v737->timer = v754;
  int * v744 = v737->regs;
  int v745 = v744[13];
  int * v746 = v737->regs;
  int v757 = v745 + 4;
  v746[13] = v757;
  struct StateT * v748 = slot_16(v737);
  return v748;
}

struct StateT * slot_18(struct StateT * v821) {
  int v822 = v821->timer;
  int v826 = v822 + 1;
  v821->timer = v826;
  struct StateT * v824 = slot_20(v821);
  return v824;
}

struct StateT * slot_9(struct StateT * v626) {
  int * v627 = v626->regs;
  int v628 = v627[11];
  bool v655 = 0 >= v628;
  struct StateT * v651;
  if (v655) {
    int v629 = v626->timer;
    int v656 = v629 + 15;
    v626->timer = v656;
    int * v631 = v626->saved_regs;
    int v632 = v631[12];
    int * v633 = v626->regs;
    v633[12] = v632;
    int * v635 = v626->saved_regs;
    int v636 = v635[13];
    int * v637 = v626->regs;
    v637[13] = v636;
    int * v639 = v626->saved_regs;
    int v640 = v639[14];
    int * v641 = v626->regs;
    v641[14] = v640;
    int * v643 = v626->saved_regs;
    int v644 = v643[15];
    int * v645 = v626->regs;
    v645[15] = v644;
    struct StateT * v647 = slot_10(v626);
    v651 = v647;
  } else {
    struct StateT * v649 = slot_11(v626);
    v651 = v649;
  }
  return v651;
}

struct StateT * slot_22(struct StateT * v854) {
  int v855 = v854->timer;
  int v988 = v855 + 1;
  v854->timer = v988;
  int * v857 = v854->regs;
  int v858 = v857[12];
  int * v859 = v854->cache_tags;
  int v992 = (((int)((unsigned int)((int)((unsigned int)v858 >> 2)) >> 1)) & 1) * 2;
  int v860 = v859[v992];
  int * v861 = v854->cache_tags;
  int v994 = ((((int)((unsigned int)((int)((unsigned int)v858 >> 2)) >> 1)) & 1) * 2) + 1;
  int v862 = v861[v994];
  int * v863 = v854->cache_tags;
  int v996 = 4 + ((((int)((unsigned int)((int)((unsigned int)v858 >> 2)) >> 1)) & 3) * 2);
  int v864 = v863[v996];
  int * v865 = v854->cache_tags;
  int v998 = (4 + ((((int)((unsigned int)((int)((unsigned int)v858 >> 2)) >> 1)) & 3) * 2)) + 1;
  int v866 = v865[v998];
  int v867 = v854->timer;
  int v999 = v867 + ((100 ^ (((~(((v864 ^ ((int)((unsigned int)((int)((unsigned int)v858 >> 2)) >> 1))) | (-(v864 ^ ((int)((unsigned int)((int)((unsigned int)v858 >> 2)) >> 1))))) >> 31)) | (~(((v866 ^ ((int)((unsigned int)((int)((unsigned int)v858 >> 2)) >> 1))) | (-(v866 ^ ((int)((unsigned int)((int)((unsigned int)v858 >> 2)) >> 1))))) >> 31))) & 104)) ^ (((~(((v860 ^ ((int)((unsigned int)((int)((unsigned int)v858 >> 2)) >> 1))) | (-(v860 ^ ((int)((unsigned int)((int)((unsigned int)v858 >> 2)) >> 1))))) >> 31)) | (~(((v862 ^ ((int)((unsigned int)((int)((unsigned int)v858 >> 2)) >> 1))) | (-(v862 ^ ((int)((unsigned int)((int)((unsigned int)v858 >> 2)) >> 1))))) >> 31))) & (1 ^ (100 ^ (((~(((v864 ^ ((int)((unsigned int)((int)((unsigned int)v858 >> 2)) >> 1))) | (-(v864 ^ ((int)((unsigned int)((int)((unsigned int)v858 >> 2)) >> 1))))) >> 31)) | (~(((v866 ^ ((int)((unsigned int)((int)((unsigned int)v858 >> 2)) >> 1))) | (-(v866 ^ ((int)((unsigned int)((int)((unsigned int)v858 >> 2)) >> 1))))) >> 31))) & 104)))));
  v854->timer = v999;
  int * v869 = v854->cache_vals;
  bool v1000 = !(((~(((v860 ^ ((int)((unsigned int)((int)((unsigned int)v858 >> 2)) >> 1))) | (-(v860 ^ ((int)((unsigned int)((int)((unsigned int)v858 >> 2)) >> 1))))) >> 31)) | (~(((v862 ^ ((int)((unsigned int)((int)((unsigned int)v858 >> 2)) >> 1))) | (-(v862 ^ ((int)((unsigned int)((int)((unsigned int)v858 >> 2)) >> 1))))) >> 31))) == 0);
  int v982;
  if (v1000) {
    int * v870 = v854->cache_age;
    int v1002 = ((((int)((unsigned int)((int)((unsigned int)v858 >> 2)) >> 1)) & 1) * 2) + ((~(((v862 ^ ((int)((unsigned int)((int)((unsigned int)v858 >> 2)) >> 1))) | (-(v862 ^ ((int)((unsigned int)((int)((unsigned int)v858 >> 2)) >> 1))))) >> 31)) & 1);
    int v871 = v870[v1002];
    int * v872 = v854->cache_age;
    int v873 = v872[v992];
    int * v874 = v854->cache_age;
    int v1005 = v873 + ((int)((unsigned int)(v873 - v871) >> 31));
    v874[v992] = v1005;
    int * v876 = v854->cache_age;
    int v877 = v876[v994];
    int * v878 = v854->cache_age;
    int v1008 = v877 + ((int)((unsigned int)(v877 - v871) >> 31));
    v878[v994] = v1008;
    int * v880 = v854->cache_age;
    v880[v1002] = 0;
    v982 = v1002;
  } else {
    int * v883 = v854->cache_age;
    int v1012 = (((int)((unsigned int)((int)((unsigned int)v858 >> 2)) >> 1)) & 1) * 2;
    int v884 = v883[v1012];
    int * v885 = v854->cache_tags;
    int v886 = v885[v1012];
    int * v887 = v854->cache_age;
    int v888 = v887[v994];
    int * v889 = v854->cache_tags;
    int v890 = v889[v994];
    bool v1016 = !(((~(((v864 ^ ((int)((unsigned int)((int)((unsigned int)v858 >> 2)) >> 1))) | (-(v864 ^ ((int)((unsigned int)((int)((unsigned int)v858 >> 2)) >> 1))))) >> 31)) | (~(((v866 ^ ((int)((unsigned int)((int)((unsigned int)v858 >> 2)) >> 1))) | (-(v866 ^ ((int)((unsigned int)((int)((unsigned int)v858 >> 2)) >> 1))))) >> 31))) == 0);
    int v954;
    if (v1016) {
      int * v891 = v854->cache_age;
      int v1018 = (4 + ((((int)((unsigned int)((int)((unsigned int)v858 >> 2)) >> 1)) & 3) * 2)) + ((~(((v866 ^ ((int)((unsigned int)((int)((unsigned int)v858 >> 2)) >> 1))) | (-(v866 ^ ((int)((unsigned int)((int)((unsigned int)v858 >> 2)) >> 1))))) >> 31)) & 1);
      int v892 = v891[v1018];
      int * v893 = v854->cache_age;
      int v894 = v893[v996];
      int * v895 = v854->cache_age;
      int v1021 = v894 + ((int)((unsigned int)(v894 - v892) >> 31));
      v895[v996] = v1021;
      int * v897 = v854->cache_age;
      int v898 = v897[v998];
      int * v899 = v854->cache_age;
      int v1024 = v898 + ((int)((unsigned int)(v898 - v892) >> 31));
      v899[v998] = v1024;
      int * v901 = v854->cache_age;
      v901[v1018] = 0;
      v954 = v1018;
    } else {
      int * v904 = v854->cache_age;
      int v1028 = 4 + ((((int)((unsigned int)((int)((unsigned int)v858 >> 2)) >> 1)) & 3) * 2);
      int v905 = v904[v1028];
      int * v906 = v854->cache_tags;
      int v907 = v906[v1028];
      int * v908 = v854->cache_age;
      int v909 = v908[v998];
      int * v910 = v854->cache_tags;
      int v911 = v910[v998];
      int * v912 = v854->cache_dirty;
      int v1033 = (4 + ((((int)((unsigned int)((int)((unsigned int)v858 >> 2)) >> 1)) & 3) * 2)) + ((((v905 + ((~(((v907 ^ -1) | (-(v907 ^ -1))) >> 31)) & 2)) - (v909 + ((~(((v911 ^ -1) | (-(v911 ^ -1))) >> 31)) & 2))) >> 31) & 1);
      int v913 = v912[v1033];
      bool v1034 = !(v913 == 0);
      if (v1034) {
        int * v914 = v854->cache_tags;
        int v915 = v914[v1033];
        int * v916 = v854->cache_vals;
        int v1037 = ((4 + ((((int)((unsigned int)((int)((unsigned int)v858 >> 2)) >> 1)) & 3) * 2)) + ((((v905 + ((~(((v907 ^ -1) | (-(v907 ^ -1))) >> 31)) & 2)) - (v909 + ((~(((v911 ^ -1) | (-(v911 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
        int v917 = v916[v1037];
        int * v918 = v854->cache_vals;
        int v1039 = (((4 + ((((int)((unsigned int)((int)((unsigned int)v858 >> 2)) >> 1)) & 3) * 2)) + ((((v905 + ((~(((v907 ^ -1) | (-(v907 ^ -1))) >> 31)) & 2)) - (v909 + ((~(((v911 ^ -1) | (-(v911 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
        int v919 = v918[v1039];
        int * v920 = v854->mem;
        int v1041 = v915 * 2;
        v920[v1041] = v917;
        int * v922 = v854->mem;
        int v1044 = (v915 * 2) + 1;
        v922[v1044] = v919;
        ;
      } else {
        ;
      }
      int * v927 = v854->mem;
      int v1049 = ((int)((unsigned int)((int)((unsigned int)v858 >> 2)) >> 1)) * 2;
      int v928 = v927[v1049];
      int * v929 = v854->mem;
      int v1051 = (((int)((unsigned int)((int)((unsigned int)v858 >> 2)) >> 1)) * 2) + 1;
      int v930 = v929[v1051];
      int * v931 = v854->cache_vals;
      int v1053 = ((4 + ((((int)((unsigned int)((int)((unsigned int)v858 >> 2)) >> 1)) & 3) * 2)) + ((((v905 + ((~(((v907 ^ -1) | (-(v907 ^ -1))) >> 31)) & 2)) - (v909 + ((~(((v911 ^ -1) | (-(v911 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
      v931[v1053] = v928;
      int * v933 = v854->cache_vals;
      int v1056 = (((4 + ((((int)((unsigned int)((int)((unsigned int)v858 >> 2)) >> 1)) & 3) * 2)) + ((((v905 + ((~(((v907 ^ -1) | (-(v907 ^ -1))) >> 31)) & 2)) - (v909 + ((~(((v911 ^ -1) | (-(v911 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
      v933[v1056] = v930;
      int * v935 = v854->cache_tags;
      int v1059 = (int)((unsigned int)((int)((unsigned int)v858 >> 2)) >> 1);
      v935[v1033] = v1059;
      int * v937 = v854->cache_dirty;
      v937[v1033] = 0;
      int * v939 = v854->cache_age;
      v939[v1033] = 1;
      int * v941 = v854->cache_age;
      int v942 = v941[v1033];
      int * v943 = v854->cache_age;
      int v944 = v943[v996];
      int * v945 = v854->cache_age;
      int v1067 = v944 + ((int)((unsigned int)(v944 - v942) >> 31));
      v945[v996] = v1067;
      int * v947 = v854->cache_age;
      int v948 = v947[v998];
      int * v949 = v854->cache_age;
      int v1070 = v948 + ((int)((unsigned int)(v948 - v942) >> 31));
      v949[v998] = v1070;
      int * v951 = v854->cache_age;
      v951[v1033] = 0;
      v954 = v1033;
    }
    int * v955 = v854->cache_vals;
    int v1073 = v954 * 2;
    int v956 = v955[v1073];
    int * v957 = v854->cache_vals;
    int v1075 = (v954 * 2) + 1;
    int v958 = v957[v1075];
    int * v959 = v854->cache_vals;
    int v1077 = (((((int)((unsigned int)((int)((unsigned int)v858 >> 2)) >> 1)) & 1) * 2) + ((((v884 + ((~(((v886 ^ -1) | (-(v886 ^ -1))) >> 31)) & 2)) - (v888 + ((~(((v890 ^ -1) | (-(v890 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
    v959[v1077] = v956;
    int * v961 = v854->cache_vals;
    int v1080 = ((((((int)((unsigned int)((int)((unsigned int)v858 >> 2)) >> 1)) & 1) * 2) + ((((v884 + ((~(((v886 ^ -1) | (-(v886 ^ -1))) >> 31)) & 2)) - (v888 + ((~(((v890 ^ -1) | (-(v890 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
    v961[v1080] = v958;
    int * v963 = v854->cache_tags;
    int v1083 = ((((int)((unsigned int)((int)((unsigned int)v858 >> 2)) >> 1)) & 1) * 2) + ((((v884 + ((~(((v886 ^ -1) | (-(v886 ^ -1))) >> 31)) & 2)) - (v888 + ((~(((v890 ^ -1) | (-(v890 ^ -1))) >> 31)) & 2))) >> 31) & 1);
    int v1084 = (int)((unsigned int)((int)((unsigned int)v858 >> 2)) >> 1);
    v963[v1083] = v1084;
    int * v965 = v854->cache_dirty;
    v965[v1083] = 0;
    int * v967 = v854->cache_age;
    v967[v1083] = 1;
    int * v969 = v854->cache_age;
    int v970 = v969[v1083];
    int * v971 = v854->cache_age;
    int v972 = v971[v992];
    int * v973 = v854->cache_age;
    int v1092 = v972 + ((int)((unsigned int)(v972 - v970) >> 31));
    v973[v992] = v1092;
    int * v975 = v854->cache_age;
    int v976 = v975[v994];
    int * v977 = v854->cache_age;
    int v1095 = v976 + ((int)((unsigned int)(v976 - v970) >> 31));
    v977[v994] = v1095;
    int * v979 = v854->cache_age;
    v979[v1083] = 0;
    v982 = v1083;
  }
  int v1098 = (v982 * 2) + (((int)((unsigned int)v858 >> 2)) & 1);
  int v983 = v869[v1098];
  int * v984 = v854->regs;
  v984[14] = v983;
  struct StateT * v986 = slot_24(v854);
  return v986;
}

struct StateT * slot_11(struct StateT * v683) {
  int v684 = v683->timer;
  int v688 = v684 + 1;
  v683->timer = v688;
  struct StateT * v686 = slot_13(v683);
  return v686;
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
    s1.mem[0 + i] = bounded(0, 20);
    s2.mem[0 + i] = bounded(0, 20);
  }
  struct StateT *s1_ = snippet(&s1);
  struct StateT *s2_ = snippet(&s2);
  koika_assert(s1_->timer==s2_->timer, "timing leak");
  return 0;
}