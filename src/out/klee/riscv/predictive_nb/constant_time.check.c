// verify: clean (KLEE should report no failing assertion) [budget 1200s]
#define NUM_REGS 32
#define MEM_SIZE 64
#define SECRET_SIZE 10
#define SECRET_OFFSET 20
#define CACHE_ENTRIES 12
#define CACHE_WORDS 24

#ifdef KLEE
#include <assert.h>
#include <klee/klee.h>
#define koika_assert(b, s) klee_assert(b)
#define koika_assume(b) klee_assume(b)
#define koika_draw(x) klee_make_symbolic(&(x), sizeof(x), #x)
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

struct StateT * slot_12(struct StateT * v647);
struct StateT * slot_6(struct StateT * v90);
struct StateT * slot_25(struct StateT * v1566);
struct StateT * slot_23(struct StateT * v1507);
struct StateT * slot_5(struct StateT * v82);
struct StateT * slot_2(struct StateT * v34);
struct StateT * slot_7(struct StateT * v122);
struct StateT * slot_21(struct StateT * v1260);
struct StateT * slot_3(struct StateT * v50);
struct StateT * slot_10(struct StateT * v584);
struct StateT * slot_1(struct StateT * v18);
struct StateT * slot_0(struct StateT * v2);
struct StateT * slot_14(struct StateT * v938);
struct StateT * slot_20(struct StateT * v1228);
struct StateT * snippet(struct StateT * v0);
struct StateT * slot_4(struct StateT * v66);
struct StateT * slot_15(struct StateT * v965);
struct StateT * slot_12(struct StateT * v647) {
  int * v648 = v647->saved_regs;
  int * v649 = v647->regs;
  int v650 = v649[14];
  v648[14] = v650;
  int v652 = v647->timer;
  int v667 = v652 + 1;
  v647->timer = v667;
  int * v654 = v647->reg_ready;
  int v655 = v654[14];
  int * v656 = v647->regs;
  int v657 = v656[14];
  int v670 = (v655 + ((v652 - v655) & (~((v652 - v655) >> 31)))) + 1;
  v654[14] = v670;
  int * v659 = v647->regs;
  int v672 = v657 + 4;
  v659[14] = v672;
  struct StateT * v661 = slot_25(v647);
  return v661;
}

struct StateT * slot_6(struct StateT * v90) {
  int * v91 = v90->saved_regs;
  int * v92 = v90->regs;
  int v93 = v92[6];
  v91[6] = v93;
  int v95 = v90->timer;
  int v112 = v95 + 1;
  v90->timer = v112;
  int * v97 = v90->reg_ready;
  int v98 = v97[12];
  int * v99 = v90->regs;
  int v100 = v99[12];
  int v101 = v97[14];
  int v102 = v99[14];
  int v117 = (v101 + (((v98 + ((v95 - v98) & (~((v95 - v98) >> 31)))) - v101) & (~(((v98 + ((v95 - v98) & (~((v95 - v98) >> 31)))) - v101) >> 31)))) + 1;
  v97[6] = v117;
  int * v104 = v90->regs;
  int v119 = v100 + v102;
  v104[6] = v119;
  struct StateT * v106 = slot_7(v90);
  return v106;
}

struct StateT * slot_25(struct StateT * v1566) {
  int * v1567 = v1566->saved_regs;
  int v1568 = v1567[14];
  int * v1569 = v1566->regs;
  int v1570 = v1569[15];
  bool v1707 = v1568 >= v1570;
  struct StateT * v1701;
  if (v1707) {
    int v1571 = v1566->timer;
    int v1708 = v1571 + 15;
    v1566->timer = v1708;
    int * v1573 = v1566->saved_regs;
    int v1574 = v1573[6];
    int * v1575 = v1566->regs;
    v1575[6] = v1574;
    int * v1577 = v1566->saved_regs;
    int v1578 = v1577[7];
    int * v1579 = v1566->regs;
    v1579[7] = v1578;
    int * v1581 = v1566->saved_regs;
    int v1582 = v1581[8];
    int * v1583 = v1566->regs;
    v1583[8] = v1582;
    int * v1585 = v1566->saved_regs;
    int v1586 = v1585[9];
    int * v1587 = v1566->regs;
    v1587[9] = v1586;
    int * v1589 = v1566->saved_regs;
    int v1590 = v1589[16];
    int * v1591 = v1566->regs;
    v1591[16] = v1590;
    int * v1593 = v1566->saved_regs;
    int v1594 = v1593[5];
    int * v1595 = v1566->regs;
    v1595[5] = v1594;
    int * v1597 = v1566->saved_regs;
    int v1598 = v1597[14];
    int * v1599 = v1566->regs;
    v1599[14] = v1598;
    int * v1601 = v1566->reg_ready;
    int v1602 = v1566->timer;
    v1601[0] = v1602;
    int * v1604 = v1566->reg_ready;
    int v1605 = v1566->timer;
    v1604[1] = v1605;
    int * v1607 = v1566->reg_ready;
    int v1608 = v1566->timer;
    v1607[2] = v1608;
    int * v1610 = v1566->reg_ready;
    int v1611 = v1566->timer;
    v1610[3] = v1611;
    int * v1613 = v1566->reg_ready;
    int v1614 = v1566->timer;
    v1613[4] = v1614;
    int * v1616 = v1566->reg_ready;
    int v1617 = v1566->timer;
    v1616[5] = v1617;
    int * v1619 = v1566->reg_ready;
    int v1620 = v1566->timer;
    v1619[6] = v1620;
    int * v1622 = v1566->reg_ready;
    int v1623 = v1566->timer;
    v1622[7] = v1623;
    int * v1625 = v1566->reg_ready;
    int v1626 = v1566->timer;
    v1625[8] = v1626;
    int * v1628 = v1566->reg_ready;
    int v1629 = v1566->timer;
    v1628[9] = v1629;
    int * v1631 = v1566->reg_ready;
    int v1632 = v1566->timer;
    v1631[10] = v1632;
    int * v1634 = v1566->reg_ready;
    int v1635 = v1566->timer;
    v1634[11] = v1635;
    int * v1637 = v1566->reg_ready;
    int v1638 = v1566->timer;
    v1637[12] = v1638;
    int * v1640 = v1566->reg_ready;
    int v1641 = v1566->timer;
    v1640[13] = v1641;
    int * v1643 = v1566->reg_ready;
    int v1644 = v1566->timer;
    v1643[14] = v1644;
    int * v1646 = v1566->reg_ready;
    int v1647 = v1566->timer;
    v1646[15] = v1647;
    int * v1649 = v1566->reg_ready;
    int v1650 = v1566->timer;
    v1649[16] = v1650;
    int * v1652 = v1566->reg_ready;
    int v1653 = v1566->timer;
    v1652[17] = v1653;
    int * v1655 = v1566->reg_ready;
    int v1656 = v1566->timer;
    v1655[18] = v1656;
    int * v1658 = v1566->reg_ready;
    int v1659 = v1566->timer;
    v1658[19] = v1659;
    int * v1661 = v1566->reg_ready;
    int v1662 = v1566->timer;
    v1661[20] = v1662;
    int * v1664 = v1566->reg_ready;
    int v1665 = v1566->timer;
    v1664[21] = v1665;
    int * v1667 = v1566->reg_ready;
    int v1668 = v1566->timer;
    v1667[22] = v1668;
    int * v1670 = v1566->reg_ready;
    int v1671 = v1566->timer;
    v1670[23] = v1671;
    int * v1673 = v1566->reg_ready;
    int v1674 = v1566->timer;
    v1673[24] = v1674;
    int * v1676 = v1566->reg_ready;
    int v1677 = v1566->timer;
    v1676[25] = v1677;
    int * v1679 = v1566->reg_ready;
    int v1680 = v1566->timer;
    v1679[26] = v1680;
    int * v1682 = v1566->reg_ready;
    int v1683 = v1566->timer;
    v1682[27] = v1683;
    int * v1685 = v1566->reg_ready;
    int v1686 = v1566->timer;
    v1685[28] = v1686;
    int * v1688 = v1566->reg_ready;
    int v1689 = v1566->timer;
    v1688[29] = v1689;
    int * v1691 = v1566->reg_ready;
    int v1692 = v1566->timer;
    v1691[30] = v1692;
    int * v1694 = v1566->reg_ready;
    int v1695 = v1566->timer;
    v1694[31] = v1695;
    struct StateT * v1697 = slot_14(v1566);
    v1701 = v1697;
  } else {
    struct StateT * v1699 = slot_15(v1566);
    v1701 = v1699;
  }
  return v1701;
}

struct StateT * slot_23(struct StateT * v1507) {
  int * v1508 = v1507->saved_regs;
  int * v1509 = v1507->regs;
  int v1510 = v1509[5];
  v1508[5] = v1510;
  int v1512 = v1507->timer;
  int v1529 = v1512 + 1;
  v1507->timer = v1529;
  int * v1514 = v1507->reg_ready;
  int v1515 = v1514[5];
  int * v1516 = v1507->regs;
  int v1517 = v1516[5];
  int v1518 = v1514[16];
  int v1519 = v1516[16];
  int v1533 = (v1518 + (((v1515 + ((v1512 - v1515) & (~((v1512 - v1515) >> 31)))) - v1518) & (~(((v1515 + ((v1512 - v1515) & (~((v1512 - v1515) >> 31)))) - v1518) >> 31)))) + 1;
  v1514[5] = v1533;
  int * v1521 = v1507->regs;
  int v1535 = v1517 | v1519;
  v1521[5] = v1535;
  struct StateT * v1523 = slot_12(v1507);
  return v1523;
}

struct StateT * slot_5(struct StateT * v82) {
  int v83 = v82->timer;
  int v87 = v83 + 1;
  v82->timer = v87;
  struct StateT * v85 = slot_6(v82);
  return v85;
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

struct StateT * slot_7(struct StateT * v122) {
  int * v123 = v122->saved_regs;
  int * v124 = v122->regs;
  int v125 = v124[7];
  v123[7] = v125;
  int v127 = v122->timer;
  int v243 = v127 + 1;
  v122->timer = v243;
  int * v129 = v122->reg_ready;
  int v130 = v129[6];
  int * v131 = v122->regs;
  int v132 = v131[6];
  int * v133 = v122->cache_tags;
  int v248 = (((int)((unsigned int)((int)((unsigned int)v132 >> 2)) >> 1)) & 1) * 2;
  int v134 = v133[v248];
  int v249 = ((((int)((unsigned int)((int)((unsigned int)v132 >> 2)) >> 1)) & 1) * 2) + 1;
  int v135 = v133[v249];
  int v250 = 4 + ((((int)((unsigned int)((int)((unsigned int)v132 >> 2)) >> 1)) & 3) * 2);
  int v136 = v133[v250];
  int v251 = (4 + ((((int)((unsigned int)((int)((unsigned int)v132 >> 2)) >> 1)) & 3) * 2)) + 1;
  int v137 = v133[v251];
  int * v138 = v122->cache_vals;
  bool v252 = !(((~(((v134 ^ ((int)((unsigned int)((int)((unsigned int)v132 >> 2)) >> 1))) | (-(v134 ^ ((int)((unsigned int)((int)((unsigned int)v132 >> 2)) >> 1))))) >> 31)) | (~(((v135 ^ ((int)((unsigned int)((int)((unsigned int)v132 >> 2)) >> 1))) | (-(v135 ^ ((int)((unsigned int)((int)((unsigned int)v132 >> 2)) >> 1))))) >> 31))) == 0);
  int v231;
  if (v252) {
    int * v139 = v122->cache_age;
    int v254 = ((((int)((unsigned int)((int)((unsigned int)v132 >> 2)) >> 1)) & 1) * 2) + ((~(((v135 ^ ((int)((unsigned int)((int)((unsigned int)v132 >> 2)) >> 1))) | (-(v135 ^ ((int)((unsigned int)((int)((unsigned int)v132 >> 2)) >> 1))))) >> 31)) & 1);
    int v140 = v139[v254];
    int v141 = v139[v248];
    int v255 = v141 + ((int)((unsigned int)(v141 - v140) >> 31));
    v139[v248] = v255;
    int * v143 = v122->cache_age;
    int v144 = v143[v249];
    int v257 = v144 + ((int)((unsigned int)(v144 - v140) >> 31));
    v143[v249] = v257;
    int * v146 = v122->cache_age;
    v146[v254] = 0;
    v231 = v254;
  } else {
    int * v149 = v122->cache_age;
    int v261 = (((int)((unsigned int)((int)((unsigned int)v132 >> 2)) >> 1)) & 1) * 2;
    int v150 = v149[v261];
    int * v151 = v122->cache_tags;
    int v152 = v151[v261];
    int v153 = v149[v249];
    int v154 = v151[v249];
    bool v263 = !(((~(((v136 ^ ((int)((unsigned int)((int)((unsigned int)v132 >> 2)) >> 1))) | (-(v136 ^ ((int)((unsigned int)((int)((unsigned int)v132 >> 2)) >> 1))))) >> 31)) | (~(((v137 ^ ((int)((unsigned int)((int)((unsigned int)v132 >> 2)) >> 1))) | (-(v137 ^ ((int)((unsigned int)((int)((unsigned int)v132 >> 2)) >> 1))))) >> 31))) == 0);
    int v208;
    if (v263) {
      int * v155 = v122->cache_age;
      int v265 = (4 + ((((int)((unsigned int)((int)((unsigned int)v132 >> 2)) >> 1)) & 3) * 2)) + ((~(((v137 ^ ((int)((unsigned int)((int)((unsigned int)v132 >> 2)) >> 1))) | (-(v137 ^ ((int)((unsigned int)((int)((unsigned int)v132 >> 2)) >> 1))))) >> 31)) & 1);
      int v156 = v155[v265];
      int v157 = v155[v250];
      int v266 = v157 + ((int)((unsigned int)(v157 - v156) >> 31));
      v155[v250] = v266;
      int * v159 = v122->cache_age;
      int v160 = v159[v251];
      int v268 = v160 + ((int)((unsigned int)(v160 - v156) >> 31));
      v159[v251] = v268;
      int * v162 = v122->cache_age;
      v162[v265] = 0;
      v208 = v265;
    } else {
      int * v165 = v122->cache_age;
      int v272 = 4 + ((((int)((unsigned int)((int)((unsigned int)v132 >> 2)) >> 1)) & 3) * 2);
      int v166 = v165[v272];
      int * v167 = v122->cache_tags;
      int v168 = v167[v272];
      int v169 = v165[v251];
      int v170 = v167[v251];
      int * v171 = v122->cache_dirty;
      int v275 = (4 + ((((int)((unsigned int)((int)((unsigned int)v132 >> 2)) >> 1)) & 3) * 2)) + ((((v166 + ((~(((v168 ^ -1) | (-(v168 ^ -1))) >> 31)) & 2)) - (v169 + ((~(((v170 ^ -1) | (-(v170 ^ -1))) >> 31)) & 2))) >> 31) & 1);
      int v172 = v171[v275];
      bool v276 = !(v172 == 0);
      if (v276) {
        int * v173 = v122->cache_tags;
        int v174 = v173[v275];
        int * v175 = v122->cache_vals;
        int v279 = ((4 + ((((int)((unsigned int)((int)((unsigned int)v132 >> 2)) >> 1)) & 3) * 2)) + ((((v166 + ((~(((v168 ^ -1) | (-(v168 ^ -1))) >> 31)) & 2)) - (v169 + ((~(((v170 ^ -1) | (-(v170 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
        int v176 = v175[v279];
        int v280 = (((4 + ((((int)((unsigned int)((int)((unsigned int)v132 >> 2)) >> 1)) & 3) * 2)) + ((((v166 + ((~(((v168 ^ -1) | (-(v168 ^ -1))) >> 31)) & 2)) - (v169 + ((~(((v170 ^ -1) | (-(v170 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
        int v177 = v175[v280];
        int * v178 = v122->mem;
        int v282 = v174 * 2;
        v178[v282] = v176;
        int * v180 = v122->mem;
        int v285 = (v174 * 2) + 1;
        v180[v285] = v177;
        ;
      } else {
        ;
      }
      int * v185 = v122->mem;
      int v290 = ((int)((unsigned int)((int)((unsigned int)v132 >> 2)) >> 1)) * 2;
      int v186 = v185[v290];
      int v291 = (((int)((unsigned int)((int)((unsigned int)v132 >> 2)) >> 1)) * 2) + 1;
      int v187 = v185[v291];
      int * v188 = v122->cache_vals;
      int v293 = ((4 + ((((int)((unsigned int)((int)((unsigned int)v132 >> 2)) >> 1)) & 3) * 2)) + ((((v166 + ((~(((v168 ^ -1) | (-(v168 ^ -1))) >> 31)) & 2)) - (v169 + ((~(((v170 ^ -1) | (-(v170 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
      v188[v293] = v186;
      int * v190 = v122->cache_vals;
      int v296 = (((4 + ((((int)((unsigned int)((int)((unsigned int)v132 >> 2)) >> 1)) & 3) * 2)) + ((((v166 + ((~(((v168 ^ -1) | (-(v168 ^ -1))) >> 31)) & 2)) - (v169 + ((~(((v170 ^ -1) | (-(v170 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
      v190[v296] = v187;
      int * v192 = v122->cache_tags;
      int v299 = (int)((unsigned int)((int)((unsigned int)v132 >> 2)) >> 1);
      v192[v275] = v299;
      int * v194 = v122->cache_dirty;
      v194[v275] = 0;
      int * v196 = v122->cache_age;
      v196[v275] = 1;
      int * v198 = v122->cache_age;
      int v199 = v198[v275];
      int v200 = v198[v250];
      int v305 = v200 + ((int)((unsigned int)(v200 - v199) >> 31));
      v198[v250] = v305;
      int * v202 = v122->cache_age;
      int v203 = v202[v251];
      int v307 = v203 + ((int)((unsigned int)(v203 - v199) >> 31));
      v202[v251] = v307;
      int * v205 = v122->cache_age;
      v205[v275] = 0;
      v208 = v275;
    }
    int * v209 = v122->cache_vals;
    int v310 = v208 * 2;
    int v210 = v209[v310];
    int v311 = (v208 * 2) + 1;
    int v211 = v209[v311];
    int v312 = (((((int)((unsigned int)((int)((unsigned int)v132 >> 2)) >> 1)) & 1) * 2) + ((((v150 + ((~(((v152 ^ -1) | (-(v152 ^ -1))) >> 31)) & 2)) - (v153 + ((~(((v154 ^ -1) | (-(v154 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
    v209[v312] = v210;
    int * v213 = v122->cache_vals;
    int v315 = ((((((int)((unsigned int)((int)((unsigned int)v132 >> 2)) >> 1)) & 1) * 2) + ((((v150 + ((~(((v152 ^ -1) | (-(v152 ^ -1))) >> 31)) & 2)) - (v153 + ((~(((v154 ^ -1) | (-(v154 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
    v213[v315] = v211;
    int * v215 = v122->cache_tags;
    int v318 = ((((int)((unsigned int)((int)((unsigned int)v132 >> 2)) >> 1)) & 1) * 2) + ((((v150 + ((~(((v152 ^ -1) | (-(v152 ^ -1))) >> 31)) & 2)) - (v153 + ((~(((v154 ^ -1) | (-(v154 ^ -1))) >> 31)) & 2))) >> 31) & 1);
    int v319 = (int)((unsigned int)((int)((unsigned int)v132 >> 2)) >> 1);
    v215[v318] = v319;
    int * v217 = v122->cache_dirty;
    v217[v318] = 0;
    int * v219 = v122->cache_age;
    v219[v318] = 1;
    int * v221 = v122->cache_age;
    int v222 = v221[v318];
    int v223 = v221[v248];
    int v325 = v223 + ((int)((unsigned int)(v223 - v222) >> 31));
    v221[v248] = v325;
    int * v225 = v122->cache_age;
    int v226 = v225[v249];
    int v327 = v226 + ((int)((unsigned int)(v226 - v222) >> 31));
    v225[v249] = v327;
    int * v228 = v122->cache_age;
    v228[v318] = 0;
    v231 = v318;
  }
  int v330 = (v231 * 2) + (((int)((unsigned int)v132 >> 2)) & 1);
  int v232 = v138[v330];
  int * v233 = v122->reg_ready;
  int v332 = ((v130 + ((v127 - v130) & (~((v127 - v130) >> 31)))) + 1) + ((100 ^ (((~(((v136 ^ ((int)((unsigned int)((int)((unsigned int)v132 >> 2)) >> 1))) | (-(v136 ^ ((int)((unsigned int)((int)((unsigned int)v132 >> 2)) >> 1))))) >> 31)) | (~(((v137 ^ ((int)((unsigned int)((int)((unsigned int)v132 >> 2)) >> 1))) | (-(v137 ^ ((int)((unsigned int)((int)((unsigned int)v132 >> 2)) >> 1))))) >> 31))) & 104)) ^ (((~(((v134 ^ ((int)((unsigned int)((int)((unsigned int)v132 >> 2)) >> 1))) | (-(v134 ^ ((int)((unsigned int)((int)((unsigned int)v132 >> 2)) >> 1))))) >> 31)) | (~(((v135 ^ ((int)((unsigned int)((int)((unsigned int)v132 >> 2)) >> 1))) | (-(v135 ^ ((int)((unsigned int)((int)((unsigned int)v132 >> 2)) >> 1))))) >> 31))) & (1 ^ (100 ^ (((~(((v136 ^ ((int)((unsigned int)((int)((unsigned int)v132 >> 2)) >> 1))) | (-(v136 ^ ((int)((unsigned int)((int)((unsigned int)v132 >> 2)) >> 1))))) >> 31)) | (~(((v137 ^ ((int)((unsigned int)((int)((unsigned int)v132 >> 2)) >> 1))) | (-(v137 ^ ((int)((unsigned int)((int)((unsigned int)v132 >> 2)) >> 1))))) >> 31))) & 104)))));
  v233[7] = v332;
  int * v235 = v122->regs;
  v235[7] = v232;
  struct StateT * v237 = slot_20(v122);
  return v237;
}

struct StateT * slot_21(struct StateT * v1260) {
  int * v1261 = v1260->saved_regs;
  int * v1262 = v1260->regs;
  int v1263 = v1262[9];
  v1261[9] = v1263;
  int v1265 = v1260->timer;
  int v1381 = v1265 + 1;
  v1260->timer = v1381;
  int * v1267 = v1260->reg_ready;
  int v1268 = v1267[8];
  int * v1269 = v1260->regs;
  int v1270 = v1269[8];
  int * v1271 = v1260->cache_tags;
  int v1386 = (((int)((unsigned int)((int)((unsigned int)v1270 >> 2)) >> 1)) & 1) * 2;
  int v1272 = v1271[v1386];
  int v1387 = ((((int)((unsigned int)((int)((unsigned int)v1270 >> 2)) >> 1)) & 1) * 2) + 1;
  int v1273 = v1271[v1387];
  int v1388 = 4 + ((((int)((unsigned int)((int)((unsigned int)v1270 >> 2)) >> 1)) & 3) * 2);
  int v1274 = v1271[v1388];
  int v1389 = (4 + ((((int)((unsigned int)((int)((unsigned int)v1270 >> 2)) >> 1)) & 3) * 2)) + 1;
  int v1275 = v1271[v1389];
  int * v1276 = v1260->cache_vals;
  bool v1390 = !(((~(((v1272 ^ ((int)((unsigned int)((int)((unsigned int)v1270 >> 2)) >> 1))) | (-(v1272 ^ ((int)((unsigned int)((int)((unsigned int)v1270 >> 2)) >> 1))))) >> 31)) | (~(((v1273 ^ ((int)((unsigned int)((int)((unsigned int)v1270 >> 2)) >> 1))) | (-(v1273 ^ ((int)((unsigned int)((int)((unsigned int)v1270 >> 2)) >> 1))))) >> 31))) == 0);
  int v1369;
  if (v1390) {
    int * v1277 = v1260->cache_age;
    int v1392 = ((((int)((unsigned int)((int)((unsigned int)v1270 >> 2)) >> 1)) & 1) * 2) + ((~(((v1273 ^ ((int)((unsigned int)((int)((unsigned int)v1270 >> 2)) >> 1))) | (-(v1273 ^ ((int)((unsigned int)((int)((unsigned int)v1270 >> 2)) >> 1))))) >> 31)) & 1);
    int v1278 = v1277[v1392];
    int v1279 = v1277[v1386];
    int v1393 = v1279 + ((int)((unsigned int)(v1279 - v1278) >> 31));
    v1277[v1386] = v1393;
    int * v1281 = v1260->cache_age;
    int v1282 = v1281[v1387];
    int v1395 = v1282 + ((int)((unsigned int)(v1282 - v1278) >> 31));
    v1281[v1387] = v1395;
    int * v1284 = v1260->cache_age;
    v1284[v1392] = 0;
    v1369 = v1392;
  } else {
    int * v1287 = v1260->cache_age;
    int v1399 = (((int)((unsigned int)((int)((unsigned int)v1270 >> 2)) >> 1)) & 1) * 2;
    int v1288 = v1287[v1399];
    int * v1289 = v1260->cache_tags;
    int v1290 = v1289[v1399];
    int v1291 = v1287[v1387];
    int v1292 = v1289[v1387];
    bool v1401 = !(((~(((v1274 ^ ((int)((unsigned int)((int)((unsigned int)v1270 >> 2)) >> 1))) | (-(v1274 ^ ((int)((unsigned int)((int)((unsigned int)v1270 >> 2)) >> 1))))) >> 31)) | (~(((v1275 ^ ((int)((unsigned int)((int)((unsigned int)v1270 >> 2)) >> 1))) | (-(v1275 ^ ((int)((unsigned int)((int)((unsigned int)v1270 >> 2)) >> 1))))) >> 31))) == 0);
    int v1346;
    if (v1401) {
      int * v1293 = v1260->cache_age;
      int v1403 = (4 + ((((int)((unsigned int)((int)((unsigned int)v1270 >> 2)) >> 1)) & 3) * 2)) + ((~(((v1275 ^ ((int)((unsigned int)((int)((unsigned int)v1270 >> 2)) >> 1))) | (-(v1275 ^ ((int)((unsigned int)((int)((unsigned int)v1270 >> 2)) >> 1))))) >> 31)) & 1);
      int v1294 = v1293[v1403];
      int v1295 = v1293[v1388];
      int v1404 = v1295 + ((int)((unsigned int)(v1295 - v1294) >> 31));
      v1293[v1388] = v1404;
      int * v1297 = v1260->cache_age;
      int v1298 = v1297[v1389];
      int v1406 = v1298 + ((int)((unsigned int)(v1298 - v1294) >> 31));
      v1297[v1389] = v1406;
      int * v1300 = v1260->cache_age;
      v1300[v1403] = 0;
      v1346 = v1403;
    } else {
      int * v1303 = v1260->cache_age;
      int v1410 = 4 + ((((int)((unsigned int)((int)((unsigned int)v1270 >> 2)) >> 1)) & 3) * 2);
      int v1304 = v1303[v1410];
      int * v1305 = v1260->cache_tags;
      int v1306 = v1305[v1410];
      int v1307 = v1303[v1389];
      int v1308 = v1305[v1389];
      int * v1309 = v1260->cache_dirty;
      int v1413 = (4 + ((((int)((unsigned int)((int)((unsigned int)v1270 >> 2)) >> 1)) & 3) * 2)) + ((((v1304 + ((~(((v1306 ^ -1) | (-(v1306 ^ -1))) >> 31)) & 2)) - (v1307 + ((~(((v1308 ^ -1) | (-(v1308 ^ -1))) >> 31)) & 2))) >> 31) & 1);
      int v1310 = v1309[v1413];
      bool v1414 = !(v1310 == 0);
      if (v1414) {
        int * v1311 = v1260->cache_tags;
        int v1312 = v1311[v1413];
        int * v1313 = v1260->cache_vals;
        int v1417 = ((4 + ((((int)((unsigned int)((int)((unsigned int)v1270 >> 2)) >> 1)) & 3) * 2)) + ((((v1304 + ((~(((v1306 ^ -1) | (-(v1306 ^ -1))) >> 31)) & 2)) - (v1307 + ((~(((v1308 ^ -1) | (-(v1308 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
        int v1314 = v1313[v1417];
        int v1418 = (((4 + ((((int)((unsigned int)((int)((unsigned int)v1270 >> 2)) >> 1)) & 3) * 2)) + ((((v1304 + ((~(((v1306 ^ -1) | (-(v1306 ^ -1))) >> 31)) & 2)) - (v1307 + ((~(((v1308 ^ -1) | (-(v1308 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
        int v1315 = v1313[v1418];
        int * v1316 = v1260->mem;
        int v1420 = v1312 * 2;
        v1316[v1420] = v1314;
        int * v1318 = v1260->mem;
        int v1423 = (v1312 * 2) + 1;
        v1318[v1423] = v1315;
        ;
      } else {
        ;
      }
      int * v1323 = v1260->mem;
      int v1428 = ((int)((unsigned int)((int)((unsigned int)v1270 >> 2)) >> 1)) * 2;
      int v1324 = v1323[v1428];
      int v1429 = (((int)((unsigned int)((int)((unsigned int)v1270 >> 2)) >> 1)) * 2) + 1;
      int v1325 = v1323[v1429];
      int * v1326 = v1260->cache_vals;
      int v1431 = ((4 + ((((int)((unsigned int)((int)((unsigned int)v1270 >> 2)) >> 1)) & 3) * 2)) + ((((v1304 + ((~(((v1306 ^ -1) | (-(v1306 ^ -1))) >> 31)) & 2)) - (v1307 + ((~(((v1308 ^ -1) | (-(v1308 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
      v1326[v1431] = v1324;
      int * v1328 = v1260->cache_vals;
      int v1434 = (((4 + ((((int)((unsigned int)((int)((unsigned int)v1270 >> 2)) >> 1)) & 3) * 2)) + ((((v1304 + ((~(((v1306 ^ -1) | (-(v1306 ^ -1))) >> 31)) & 2)) - (v1307 + ((~(((v1308 ^ -1) | (-(v1308 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
      v1328[v1434] = v1325;
      int * v1330 = v1260->cache_tags;
      int v1437 = (int)((unsigned int)((int)((unsigned int)v1270 >> 2)) >> 1);
      v1330[v1413] = v1437;
      int * v1332 = v1260->cache_dirty;
      v1332[v1413] = 0;
      int * v1334 = v1260->cache_age;
      v1334[v1413] = 1;
      int * v1336 = v1260->cache_age;
      int v1337 = v1336[v1413];
      int v1338 = v1336[v1388];
      int v1443 = v1338 + ((int)((unsigned int)(v1338 - v1337) >> 31));
      v1336[v1388] = v1443;
      int * v1340 = v1260->cache_age;
      int v1341 = v1340[v1389];
      int v1445 = v1341 + ((int)((unsigned int)(v1341 - v1337) >> 31));
      v1340[v1389] = v1445;
      int * v1343 = v1260->cache_age;
      v1343[v1413] = 0;
      v1346 = v1413;
    }
    int * v1347 = v1260->cache_vals;
    int v1448 = v1346 * 2;
    int v1348 = v1347[v1448];
    int v1449 = (v1346 * 2) + 1;
    int v1349 = v1347[v1449];
    int v1450 = (((((int)((unsigned int)((int)((unsigned int)v1270 >> 2)) >> 1)) & 1) * 2) + ((((v1288 + ((~(((v1290 ^ -1) | (-(v1290 ^ -1))) >> 31)) & 2)) - (v1291 + ((~(((v1292 ^ -1) | (-(v1292 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
    v1347[v1450] = v1348;
    int * v1351 = v1260->cache_vals;
    int v1453 = ((((((int)((unsigned int)((int)((unsigned int)v1270 >> 2)) >> 1)) & 1) * 2) + ((((v1288 + ((~(((v1290 ^ -1) | (-(v1290 ^ -1))) >> 31)) & 2)) - (v1291 + ((~(((v1292 ^ -1) | (-(v1292 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
    v1351[v1453] = v1349;
    int * v1353 = v1260->cache_tags;
    int v1456 = ((((int)((unsigned int)((int)((unsigned int)v1270 >> 2)) >> 1)) & 1) * 2) + ((((v1288 + ((~(((v1290 ^ -1) | (-(v1290 ^ -1))) >> 31)) & 2)) - (v1291 + ((~(((v1292 ^ -1) | (-(v1292 ^ -1))) >> 31)) & 2))) >> 31) & 1);
    int v1457 = (int)((unsigned int)((int)((unsigned int)v1270 >> 2)) >> 1);
    v1353[v1456] = v1457;
    int * v1355 = v1260->cache_dirty;
    v1355[v1456] = 0;
    int * v1357 = v1260->cache_age;
    v1357[v1456] = 1;
    int * v1359 = v1260->cache_age;
    int v1360 = v1359[v1456];
    int v1361 = v1359[v1386];
    int v1463 = v1361 + ((int)((unsigned int)(v1361 - v1360) >> 31));
    v1359[v1386] = v1463;
    int * v1363 = v1260->cache_age;
    int v1364 = v1363[v1387];
    int v1465 = v1364 + ((int)((unsigned int)(v1364 - v1360) >> 31));
    v1363[v1387] = v1465;
    int * v1366 = v1260->cache_age;
    v1366[v1456] = 0;
    v1369 = v1456;
  }
  int v1468 = (v1369 * 2) + (((int)((unsigned int)v1270 >> 2)) & 1);
  int v1370 = v1276[v1468];
  int * v1371 = v1260->reg_ready;
  int v1470 = ((v1268 + ((v1265 - v1268) & (~((v1265 - v1268) >> 31)))) + 1) + ((100 ^ (((~(((v1274 ^ ((int)((unsigned int)((int)((unsigned int)v1270 >> 2)) >> 1))) | (-(v1274 ^ ((int)((unsigned int)((int)((unsigned int)v1270 >> 2)) >> 1))))) >> 31)) | (~(((v1275 ^ ((int)((unsigned int)((int)((unsigned int)v1270 >> 2)) >> 1))) | (-(v1275 ^ ((int)((unsigned int)((int)((unsigned int)v1270 >> 2)) >> 1))))) >> 31))) & 104)) ^ (((~(((v1272 ^ ((int)((unsigned int)((int)((unsigned int)v1270 >> 2)) >> 1))) | (-(v1272 ^ ((int)((unsigned int)((int)((unsigned int)v1270 >> 2)) >> 1))))) >> 31)) | (~(((v1273 ^ ((int)((unsigned int)((int)((unsigned int)v1270 >> 2)) >> 1))) | (-(v1273 ^ ((int)((unsigned int)((int)((unsigned int)v1270 >> 2)) >> 1))))) >> 31))) & (1 ^ (100 ^ (((~(((v1274 ^ ((int)((unsigned int)((int)((unsigned int)v1270 >> 2)) >> 1))) | (-(v1274 ^ ((int)((unsigned int)((int)((unsigned int)v1270 >> 2)) >> 1))))) >> 31)) | (~(((v1275 ^ ((int)((unsigned int)((int)((unsigned int)v1270 >> 2)) >> 1))) | (-(v1275 ^ ((int)((unsigned int)((int)((unsigned int)v1270 >> 2)) >> 1))))) >> 31))) & 104)))));
  v1371[9] = v1470;
  int * v1373 = v1260->regs;
  v1373[9] = v1370;
  struct StateT * v1375 = slot_10(v1260);
  return v1375;
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

struct StateT * slot_10(struct StateT * v584) {
  int * v585 = v584->saved_regs;
  int * v586 = v584->regs;
  int v587 = v586[16];
  v585[16] = v587;
  int v589 = v584->timer;
  int v606 = v589 + 1;
  v584->timer = v606;
  int * v591 = v584->reg_ready;
  int v592 = v591[7];
  int * v593 = v584->regs;
  int v594 = v593[7];
  int v595 = v591[9];
  int v596 = v593[9];
  int v611 = (v595 + (((v592 + ((v589 - v592) & (~((v589 - v592) >> 31)))) - v595) & (~(((v592 + ((v589 - v592) & (~((v589 - v592) >> 31)))) - v595) >> 31)))) + 1;
  v591[16] = v611;
  int * v598 = v584->regs;
  int v613 = v594 ^ v596;
  v598[16] = v613;
  struct StateT * v600 = slot_23(v584);
  return v600;
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

struct StateT * slot_14(struct StateT * v938) {
  int v939 = v938->timer;
  int v953 = v939 + 1;
  v938->timer = v953;
  int * v941 = v938->reg_ready;
  int v942 = v941[5];
  int * v943 = v938->regs;
  int v944 = v943[5];
  bool v957 = (v944 ^ -2147483648) < -2147483647;
  int v947;
  if (v957) {
    v947 = 1;
  } else {
    v947 = 0;
  }
  int * v948 = v938->reg_ready;
  int v962 = (v942 + ((v939 - v942) & (~((v939 - v942) >> 31)))) + 1;
  v948[11] = v962;
  int * v950 = v938->regs;
  v950[11] = v947;
  return v938;
}

struct StateT * slot_20(struct StateT * v1228) {
  int * v1229 = v1228->saved_regs;
  int * v1230 = v1228->regs;
  int v1231 = v1230[8];
  v1229[8] = v1231;
  int v1233 = v1228->timer;
  int v1250 = v1233 + 1;
  v1228->timer = v1250;
  int * v1235 = v1228->reg_ready;
  int v1236 = v1235[13];
  int * v1237 = v1228->regs;
  int v1238 = v1237[13];
  int v1239 = v1235[14];
  int v1240 = v1237[14];
  int v1255 = (v1239 + (((v1236 + ((v1233 - v1236) & (~((v1233 - v1236) >> 31)))) - v1239) & (~(((v1236 + ((v1233 - v1236) & (~((v1233 - v1236) >> 31)))) - v1239) >> 31)))) + 1;
  v1235[8] = v1255;
  int * v1242 = v1228->regs;
  int v1257 = v1238 + v1240;
  v1242[8] = v1257;
  struct StateT * v1244 = slot_21(v1228);
  return v1244;
}

struct StateT * snippet(struct StateT * v0) {
  struct StateT * v1 = slot_0(v0);
  int v1829 = v1->timer;
  int * v1830 = v1->reg_ready;
  int v1831 = v1830[0];
  int v1962 = v1831 + ((v1829 - v1831) & (~((v1829 - v1831) >> 31)));
  v1->timer = v1962;
  int v1833 = v1->timer;
  int * v1834 = v1->reg_ready;
  int v1835 = v1834[1];
  int v1965 = v1835 + ((v1833 - v1835) & (~((v1833 - v1835) >> 31)));
  v1->timer = v1965;
  int v1837 = v1->timer;
  int * v1838 = v1->reg_ready;
  int v1839 = v1838[2];
  int v1968 = v1839 + ((v1837 - v1839) & (~((v1837 - v1839) >> 31)));
  v1->timer = v1968;
  int v1841 = v1->timer;
  int * v1842 = v1->reg_ready;
  int v1843 = v1842[3];
  int v1971 = v1843 + ((v1841 - v1843) & (~((v1841 - v1843) >> 31)));
  v1->timer = v1971;
  int v1845 = v1->timer;
  int * v1846 = v1->reg_ready;
  int v1847 = v1846[4];
  int v1974 = v1847 + ((v1845 - v1847) & (~((v1845 - v1847) >> 31)));
  v1->timer = v1974;
  int v1849 = v1->timer;
  int * v1850 = v1->reg_ready;
  int v1851 = v1850[5];
  int v1977 = v1851 + ((v1849 - v1851) & (~((v1849 - v1851) >> 31)));
  v1->timer = v1977;
  int v1853 = v1->timer;
  int * v1854 = v1->reg_ready;
  int v1855 = v1854[6];
  int v1980 = v1855 + ((v1853 - v1855) & (~((v1853 - v1855) >> 31)));
  v1->timer = v1980;
  int v1857 = v1->timer;
  int * v1858 = v1->reg_ready;
  int v1859 = v1858[7];
  int v1983 = v1859 + ((v1857 - v1859) & (~((v1857 - v1859) >> 31)));
  v1->timer = v1983;
  int v1861 = v1->timer;
  int * v1862 = v1->reg_ready;
  int v1863 = v1862[8];
  int v1986 = v1863 + ((v1861 - v1863) & (~((v1861 - v1863) >> 31)));
  v1->timer = v1986;
  int v1865 = v1->timer;
  int * v1866 = v1->reg_ready;
  int v1867 = v1866[9];
  int v1989 = v1867 + ((v1865 - v1867) & (~((v1865 - v1867) >> 31)));
  v1->timer = v1989;
  int v1869 = v1->timer;
  int * v1870 = v1->reg_ready;
  int v1871 = v1870[10];
  int v1992 = v1871 + ((v1869 - v1871) & (~((v1869 - v1871) >> 31)));
  v1->timer = v1992;
  int v1873 = v1->timer;
  int * v1874 = v1->reg_ready;
  int v1875 = v1874[11];
  int v1995 = v1875 + ((v1873 - v1875) & (~((v1873 - v1875) >> 31)));
  v1->timer = v1995;
  int v1877 = v1->timer;
  int * v1878 = v1->reg_ready;
  int v1879 = v1878[12];
  int v1998 = v1879 + ((v1877 - v1879) & (~((v1877 - v1879) >> 31)));
  v1->timer = v1998;
  int v1881 = v1->timer;
  int * v1882 = v1->reg_ready;
  int v1883 = v1882[13];
  int v2001 = v1883 + ((v1881 - v1883) & (~((v1881 - v1883) >> 31)));
  v1->timer = v2001;
  int v1885 = v1->timer;
  int * v1886 = v1->reg_ready;
  int v1887 = v1886[14];
  int v2004 = v1887 + ((v1885 - v1887) & (~((v1885 - v1887) >> 31)));
  v1->timer = v2004;
  int v1889 = v1->timer;
  int * v1890 = v1->reg_ready;
  int v1891 = v1890[15];
  int v2007 = v1891 + ((v1889 - v1891) & (~((v1889 - v1891) >> 31)));
  v1->timer = v2007;
  int v1893 = v1->timer;
  int * v1894 = v1->reg_ready;
  int v1895 = v1894[16];
  int v2010 = v1895 + ((v1893 - v1895) & (~((v1893 - v1895) >> 31)));
  v1->timer = v2010;
  int v1897 = v1->timer;
  int * v1898 = v1->reg_ready;
  int v1899 = v1898[17];
  int v2013 = v1899 + ((v1897 - v1899) & (~((v1897 - v1899) >> 31)));
  v1->timer = v2013;
  int v1901 = v1->timer;
  int * v1902 = v1->reg_ready;
  int v1903 = v1902[18];
  int v2016 = v1903 + ((v1901 - v1903) & (~((v1901 - v1903) >> 31)));
  v1->timer = v2016;
  int v1905 = v1->timer;
  int * v1906 = v1->reg_ready;
  int v1907 = v1906[19];
  int v2019 = v1907 + ((v1905 - v1907) & (~((v1905 - v1907) >> 31)));
  v1->timer = v2019;
  int v1909 = v1->timer;
  int * v1910 = v1->reg_ready;
  int v1911 = v1910[20];
  int v2022 = v1911 + ((v1909 - v1911) & (~((v1909 - v1911) >> 31)));
  v1->timer = v2022;
  int v1913 = v1->timer;
  int * v1914 = v1->reg_ready;
  int v1915 = v1914[21];
  int v2025 = v1915 + ((v1913 - v1915) & (~((v1913 - v1915) >> 31)));
  v1->timer = v2025;
  int v1917 = v1->timer;
  int * v1918 = v1->reg_ready;
  int v1919 = v1918[22];
  int v2028 = v1919 + ((v1917 - v1919) & (~((v1917 - v1919) >> 31)));
  v1->timer = v2028;
  int v1921 = v1->timer;
  int * v1922 = v1->reg_ready;
  int v1923 = v1922[23];
  int v2031 = v1923 + ((v1921 - v1923) & (~((v1921 - v1923) >> 31)));
  v1->timer = v2031;
  int v1925 = v1->timer;
  int * v1926 = v1->reg_ready;
  int v1927 = v1926[24];
  int v2034 = v1927 + ((v1925 - v1927) & (~((v1925 - v1927) >> 31)));
  v1->timer = v2034;
  int v1929 = v1->timer;
  int * v1930 = v1->reg_ready;
  int v1931 = v1930[25];
  int v2037 = v1931 + ((v1929 - v1931) & (~((v1929 - v1931) >> 31)));
  v1->timer = v2037;
  int v1933 = v1->timer;
  int * v1934 = v1->reg_ready;
  int v1935 = v1934[26];
  int v2040 = v1935 + ((v1933 - v1935) & (~((v1933 - v1935) >> 31)));
  v1->timer = v2040;
  int v1937 = v1->timer;
  int * v1938 = v1->reg_ready;
  int v1939 = v1938[27];
  int v2043 = v1939 + ((v1937 - v1939) & (~((v1937 - v1939) >> 31)));
  v1->timer = v2043;
  int v1941 = v1->timer;
  int * v1942 = v1->reg_ready;
  int v1943 = v1942[28];
  int v2046 = v1943 + ((v1941 - v1943) & (~((v1941 - v1943) >> 31)));
  v1->timer = v2046;
  int v1945 = v1->timer;
  int * v1946 = v1->reg_ready;
  int v1947 = v1946[29];
  int v2049 = v1947 + ((v1945 - v1947) & (~((v1945 - v1947) >> 31)));
  v1->timer = v2049;
  int v1949 = v1->timer;
  int * v1950 = v1->reg_ready;
  int v1951 = v1950[30];
  int v2052 = v1951 + ((v1949 - v1951) & (~((v1949 - v1951) >> 31)));
  v1->timer = v2052;
  int v1953 = v1->timer;
  int * v1954 = v1->reg_ready;
  int v1955 = v1954[31];
  int v2055 = v1955 + ((v1953 - v1955) & (~((v1953 - v1955) >> 31)));
  v1->timer = v2055;
  return v1;
}

struct StateT * slot_4(struct StateT * v66) {
  int v67 = v66->timer;
  int v75 = v67 + 1;
  v66->timer = v75;
  int * v69 = v66->reg_ready;
  v69[5] = v75;
  int * v71 = v66->regs;
  v71[5] = 0;
  struct StateT * v73 = slot_5(v66);
  return v73;
}

struct StateT * slot_15(struct StateT * v965) {
  int v966 = v965->timer;
  int v970 = v966 + 1;
  v965->timer = v970;
  struct StateT * v968 = slot_5(v965);
  return v968;
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