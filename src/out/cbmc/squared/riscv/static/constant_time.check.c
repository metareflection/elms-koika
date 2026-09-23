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

struct StateT2 * slot_12(struct StateT2 * v1537);
struct StateT2 * slot_14(struct StateT2 * v1733);
struct StateT2 * slot_6(struct StateT2 * v206);
struct StateT2 * slot_16(struct StateT2 * v1776);
struct StateT2 * slot_5(struct StateT2 * v182);
struct StateT2 * slot_2(struct StateT2 * v74);
struct StateT2 * slot_7(struct StateT2 * v275);
struct StateT2 * slot_3(struct StateT2 * v110);
struct StateT2 * snippet(struct StateT2 * v0);
struct StateT2 * slot_10(struct StateT2 * v1400);
struct StateT2 * slot_1(struct StateT2 * v38);
struct StateT2 * slot_8(struct StateT2 * v803);
struct StateT2 * slot_4(struct StateT2 * v146);
struct StateT2 * slot_13(struct StateT2 * v1680);
struct StateT2 * slot_9(struct StateT2 * v872);
struct StateT2 * slot_11(struct StateT2 * v1469);
struct StateT2 * slot_0(struct StateT2 * v2);
struct StateT2 * slot_12(struct StateT2 * v1537) {
  struct StateT * v1538 = v1537->a;
  int v1539 = v1538->timer;
  struct StateT * v1540 = v1537->b;
  int v1541 = v1540->timer;
  bool v1618 = v1539 == v1541;
  squared_assert(v1618);
  squared_assume(v1618);
  struct StateT * v1544 = v1537->a;
  int * v1545 = v1544->regs;
  int v1546 = v1545[14];
  int * v1547 = v1544->regs;
  int v1548 = v1547[15];
  struct StateT * v1549 = v1537->b;
  int * v1550 = v1549->regs;
  int v1551 = v1550[14];
  int * v1552 = v1549->regs;
  int v1553 = v1552[15];
  bool v1627 = (v1546 >= v1548) == (v1551 >= v1553);
  squared_assert(v1627);
  squared_assume(v1627);
  bool v1628 = v1546 >= v1548;
  struct StateT2 * v1614;
  if (v1628) {
    struct StateT * v1556 = v1537->a;
    int v1557 = v1556->timer;
    int v1630 = v1557 + 15;
    v1556->timer = v1630;
    int * v1559 = v1556->saved_regs;
    int v1560 = v1559[6];
    int * v1561 = v1556->regs;
    v1561[6] = v1560;
    int * v1563 = v1556->saved_regs;
    int v1564 = v1563[7];
    int * v1565 = v1556->regs;
    v1565[7] = v1564;
    int * v1567 = v1556->saved_regs;
    int v1568 = v1567[8];
    int * v1569 = v1556->regs;
    v1569[8] = v1568;
    int * v1571 = v1556->saved_regs;
    int v1572 = v1571[9];
    int * v1573 = v1556->regs;
    v1573[9] = v1572;
    int * v1575 = v1556->saved_regs;
    int v1576 = v1575[16];
    int * v1577 = v1556->regs;
    v1577[16] = v1576;
    int * v1579 = v1556->saved_regs;
    int v1580 = v1579[5];
    int * v1581 = v1556->regs;
    v1581[5] = v1580;
    struct StateT * v1583 = v1537->b;
    int v1584 = v1583->timer;
    int v1656 = v1584 + 15;
    v1583->timer = v1656;
    int * v1586 = v1583->saved_regs;
    int v1587 = v1586[6];
    int * v1588 = v1583->regs;
    v1588[6] = v1587;
    int * v1590 = v1583->saved_regs;
    int v1591 = v1590[7];
    int * v1592 = v1583->regs;
    v1592[7] = v1591;
    int * v1594 = v1583->saved_regs;
    int v1595 = v1594[8];
    int * v1596 = v1583->regs;
    v1596[8] = v1595;
    int * v1598 = v1583->saved_regs;
    int v1599 = v1598[9];
    int * v1600 = v1583->regs;
    v1600[9] = v1599;
    int * v1602 = v1583->saved_regs;
    int v1603 = v1602[16];
    int * v1604 = v1583->regs;
    v1604[16] = v1603;
    int * v1606 = v1583->saved_regs;
    int v1607 = v1606[5];
    int * v1608 = v1583->regs;
    v1608[5] = v1607;
    struct StateT2 * v1610 = slot_13(v1537);
    v1614 = v1610;
  } else {
    struct StateT2 * v1612 = slot_14(v1537);
    v1614 = v1612;
  }
  return v1614;
}

struct StateT2 * slot_14(struct StateT2 * v1733) {
  struct StateT * v1734 = v1733->a;
  int v1735 = v1734->timer;
  struct StateT * v1736 = v1733->b;
  int v1737 = v1736->timer;
  bool v1760 = v1735 == v1737;
  squared_assert(v1760);
  squared_assume(v1760);
  struct StateT * v1740 = v1733->a;
  int v1741 = v1740->timer;
  int v1762 = v1741 + 1;
  v1740->timer = v1762;
  struct StateT * v1743 = v1733->b;
  int v1744 = v1743->timer;
  int v1764 = v1744 + 1;
  v1743->timer = v1764;
  struct StateT * v1746 = v1733->a;
  int * v1747 = v1746->regs;
  int v1748 = v1747[14];
  int * v1749 = v1746->regs;
  int v1769 = v1748 + 4;
  v1749[14] = v1769;
  struct StateT * v1751 = v1733->b;
  int * v1752 = v1751->regs;
  int v1753 = v1752[14];
  int * v1754 = v1751->regs;
  int v1773 = v1753 + 4;
  v1754[14] = v1773;
  struct StateT2 * v1756 = slot_16(v1733);
  return v1756;
}

struct StateT2 * slot_6(struct StateT2 * v206) {
  struct StateT * v207 = v206->a;
  int v208 = v207->timer;
  struct StateT * v209 = v206->b;
  int v210 = v209->timer;
  bool v247 = v208 == v210;
  squared_assert(v247);
  squared_assume(v247);
  struct StateT * v213 = v206->a;
  int * v214 = v213->saved_regs;
  int * v215 = v213->regs;
  int v216 = v215[6];
  v214[6] = v216;
  struct StateT * v218 = v206->b;
  int * v219 = v218->saved_regs;
  int * v220 = v218->regs;
  int v221 = v220[6];
  v219[6] = v221;
  struct StateT * v223 = v206->a;
  int v224 = v223->timer;
  int v258 = v224 + 1;
  v223->timer = v258;
  struct StateT * v226 = v206->b;
  int v227 = v226->timer;
  int v260 = v227 + 1;
  v226->timer = v260;
  struct StateT * v229 = v206->a;
  int * v230 = v229->regs;
  int v231 = v230[12];
  int * v232 = v229->regs;
  int v233 = v232[14];
  int * v234 = v229->regs;
  int v267 = v231 + v233;
  v234[6] = v267;
  struct StateT * v236 = v206->b;
  int * v237 = v236->regs;
  int v238 = v237[12];
  int * v239 = v236->regs;
  int v240 = v239[14];
  int * v241 = v236->regs;
  int v272 = v238 + v240;
  v241[6] = v272;
  struct StateT2 * v243 = slot_7(v206);
  return v243;
}

struct StateT2 * slot_16(struct StateT2 * v1776) {
  struct StateT * v1777 = v1776->a;
  int v1778 = v1777->timer;
  struct StateT * v1779 = v1776->b;
  int v1780 = v1779->timer;
  bool v1795 = v1778 == v1780;
  squared_assert(v1795);
  squared_assume(v1795);
  struct StateT * v1783 = v1776->a;
  int v1784 = v1783->timer;
  int v1797 = v1784 + 1;
  v1783->timer = v1797;
  struct StateT * v1786 = v1776->b;
  int v1787 = v1786->timer;
  int v1799 = v1787 + 1;
  v1786->timer = v1799;
  struct StateT * v1789 = v1776->a;
  struct StateT * v1790 = v1776->b;
  struct StateT2 * v1791 = slot_5(v1776);
  return v1791;
}

struct StateT2 * slot_5(struct StateT2 * v182) {
  struct StateT * v183 = v182->a;
  int v184 = v183->timer;
  struct StateT * v185 = v182->b;
  int v186 = v185->timer;
  bool v199 = v184 == v186;
  squared_assert(v199);
  squared_assume(v199);
  struct StateT * v189 = v182->a;
  int v190 = v189->timer;
  int v201 = v190 + 1;
  v189->timer = v201;
  struct StateT * v192 = v182->b;
  int v193 = v192->timer;
  int v203 = v193 + 1;
  v192->timer = v203;
  struct StateT2 * v195 = slot_6(v182);
  return v195;
}

struct StateT2 * slot_2(struct StateT2 * v74) {
  struct StateT * v75 = v74->a;
  int v76 = v75->timer;
  struct StateT * v77 = v74->b;
  int v78 = v77->timer;
  bool v97 = v76 == v78;
  squared_assert(v97);
  squared_assume(v97);
  struct StateT * v81 = v74->a;
  int v82 = v81->timer;
  int v99 = v82 + 1;
  v81->timer = v99;
  struct StateT * v84 = v74->b;
  int v85 = v84->timer;
  int v101 = v85 + 1;
  v84->timer = v101;
  struct StateT * v87 = v74->a;
  int * v88 = v87->regs;
  v88[14] = 0;
  struct StateT * v90 = v74->b;
  int * v91 = v90->regs;
  v91[14] = 0;
  struct StateT2 * v93 = slot_3(v74);
  return v93;
}

struct StateT2 * slot_7(struct StateT2 * v275) {
  struct StateT * v276 = v275->a;
  int v277 = v276->timer;
  struct StateT * v278 = v275->b;
  int v279 = v278->timer;
  bool v562 = v277 == v279;
  squared_assert(v562);
  squared_assume(v562);
  struct StateT * v282 = v275->a;
  int * v283 = v282->saved_regs;
  int * v284 = v282->regs;
  int v285 = v284[7];
  v283[7] = v285;
  struct StateT * v287 = v275->b;
  int * v288 = v287->saved_regs;
  int * v289 = v287->regs;
  int v290 = v289[7];
  v288[7] = v290;
  struct StateT * v292 = v275->a;
  int v293 = v292->timer;
  int v573 = v293 + 1;
  v292->timer = v573;
  struct StateT * v295 = v275->b;
  int v296 = v295->timer;
  int v575 = v296 + 1;
  v295->timer = v575;
  struct StateT * v298 = v275->a;
  int * v299 = v298->regs;
  int v300 = v299[6];
  int * v301 = v298->cache_tags;
  int v580 = (((int)((unsigned int)((int)((unsigned int)v300 >> 2)) >> 1)) & 1) * 2;
  int v302 = v301[v580];
  int * v303 = v298->cache_tags;
  int v582 = ((((int)((unsigned int)((int)((unsigned int)v300 >> 2)) >> 1)) & 1) * 2) + 1;
  int v304 = v303[v582];
  int * v305 = v298->cache_tags;
  int v584 = 4 + ((((int)((unsigned int)((int)((unsigned int)v300 >> 2)) >> 1)) & 3) * 2);
  int v306 = v305[v584];
  int * v307 = v298->cache_tags;
  int v586 = (4 + ((((int)((unsigned int)((int)((unsigned int)v300 >> 2)) >> 1)) & 3) * 2)) + 1;
  int v308 = v307[v586];
  int v309 = v298->timer;
  int v587 = v309 + ((100 ^ (((~(((v306 ^ ((int)((unsigned int)((int)((unsigned int)v300 >> 2)) >> 1))) | (-(v306 ^ ((int)((unsigned int)((int)((unsigned int)v300 >> 2)) >> 1))))) >> 31)) | (~(((v308 ^ ((int)((unsigned int)((int)((unsigned int)v300 >> 2)) >> 1))) | (-(v308 ^ ((int)((unsigned int)((int)((unsigned int)v300 >> 2)) >> 1))))) >> 31))) & 104)) ^ (((~(((v302 ^ ((int)((unsigned int)((int)((unsigned int)v300 >> 2)) >> 1))) | (-(v302 ^ ((int)((unsigned int)((int)((unsigned int)v300 >> 2)) >> 1))))) >> 31)) | (~(((v304 ^ ((int)((unsigned int)((int)((unsigned int)v300 >> 2)) >> 1))) | (-(v304 ^ ((int)((unsigned int)((int)((unsigned int)v300 >> 2)) >> 1))))) >> 31))) & (1 ^ (100 ^ (((~(((v306 ^ ((int)((unsigned int)((int)((unsigned int)v300 >> 2)) >> 1))) | (-(v306 ^ ((int)((unsigned int)((int)((unsigned int)v300 >> 2)) >> 1))))) >> 31)) | (~(((v308 ^ ((int)((unsigned int)((int)((unsigned int)v300 >> 2)) >> 1))) | (-(v308 ^ ((int)((unsigned int)((int)((unsigned int)v300 >> 2)) >> 1))))) >> 31))) & 104)))));
  v298->timer = v587;
  int * v311 = v298->cache_vals;
  bool v588 = !(((~(((v302 ^ ((int)((unsigned int)((int)((unsigned int)v300 >> 2)) >> 1))) | (-(v302 ^ ((int)((unsigned int)((int)((unsigned int)v300 >> 2)) >> 1))))) >> 31)) | (~(((v304 ^ ((int)((unsigned int)((int)((unsigned int)v300 >> 2)) >> 1))) | (-(v304 ^ ((int)((unsigned int)((int)((unsigned int)v300 >> 2)) >> 1))))) >> 31))) == 0);
  int v424;
  if (v588) {
    int * v312 = v298->cache_age;
    int v590 = ((((int)((unsigned int)((int)((unsigned int)v300 >> 2)) >> 1)) & 1) * 2) + ((~(((v304 ^ ((int)((unsigned int)((int)((unsigned int)v300 >> 2)) >> 1))) | (-(v304 ^ ((int)((unsigned int)((int)((unsigned int)v300 >> 2)) >> 1))))) >> 31)) & 1);
    int v313 = v312[v590];
    int * v314 = v298->cache_age;
    int v315 = v314[v580];
    int * v316 = v298->cache_age;
    int v593 = v315 + ((int)((unsigned int)(v315 - v313) >> 31));
    v316[v580] = v593;
    int * v318 = v298->cache_age;
    int v319 = v318[v582];
    int * v320 = v298->cache_age;
    int v596 = v319 + ((int)((unsigned int)(v319 - v313) >> 31));
    v320[v582] = v596;
    int * v322 = v298->cache_age;
    v322[v590] = 0;
    v424 = v590;
  } else {
    int * v325 = v298->cache_age;
    int v600 = (((int)((unsigned int)((int)((unsigned int)v300 >> 2)) >> 1)) & 1) * 2;
    int v326 = v325[v600];
    int * v327 = v298->cache_tags;
    int v328 = v327[v600];
    int * v329 = v298->cache_age;
    int v330 = v329[v582];
    int * v331 = v298->cache_tags;
    int v332 = v331[v582];
    bool v604 = !(((~(((v306 ^ ((int)((unsigned int)((int)((unsigned int)v300 >> 2)) >> 1))) | (-(v306 ^ ((int)((unsigned int)((int)((unsigned int)v300 >> 2)) >> 1))))) >> 31)) | (~(((v308 ^ ((int)((unsigned int)((int)((unsigned int)v300 >> 2)) >> 1))) | (-(v308 ^ ((int)((unsigned int)((int)((unsigned int)v300 >> 2)) >> 1))))) >> 31))) == 0);
    int v396;
    if (v604) {
      int * v333 = v298->cache_age;
      int v606 = (4 + ((((int)((unsigned int)((int)((unsigned int)v300 >> 2)) >> 1)) & 3) * 2)) + ((~(((v308 ^ ((int)((unsigned int)((int)((unsigned int)v300 >> 2)) >> 1))) | (-(v308 ^ ((int)((unsigned int)((int)((unsigned int)v300 >> 2)) >> 1))))) >> 31)) & 1);
      int v334 = v333[v606];
      int * v335 = v298->cache_age;
      int v336 = v335[v584];
      int * v337 = v298->cache_age;
      int v609 = v336 + ((int)((unsigned int)(v336 - v334) >> 31));
      v337[v584] = v609;
      int * v339 = v298->cache_age;
      int v340 = v339[v586];
      int * v341 = v298->cache_age;
      int v612 = v340 + ((int)((unsigned int)(v340 - v334) >> 31));
      v341[v586] = v612;
      int * v343 = v298->cache_age;
      v343[v606] = 0;
      v396 = v606;
    } else {
      int * v346 = v298->cache_age;
      int v616 = 4 + ((((int)((unsigned int)((int)((unsigned int)v300 >> 2)) >> 1)) & 3) * 2);
      int v347 = v346[v616];
      int * v348 = v298->cache_tags;
      int v349 = v348[v616];
      int * v350 = v298->cache_age;
      int v351 = v350[v586];
      int * v352 = v298->cache_tags;
      int v353 = v352[v586];
      int * v354 = v298->cache_dirty;
      int v621 = (4 + ((((int)((unsigned int)((int)((unsigned int)v300 >> 2)) >> 1)) & 3) * 2)) + ((((v347 + ((~(((v349 ^ -1) | (-(v349 ^ -1))) >> 31)) & 2)) - (v351 + ((~(((v353 ^ -1) | (-(v353 ^ -1))) >> 31)) & 2))) >> 31) & 1);
      int v355 = v354[v621];
      bool v622 = !(v355 == 0);
      if (v622) {
        int * v356 = v298->cache_tags;
        int v357 = v356[v621];
        int * v358 = v298->cache_vals;
        int v625 = ((4 + ((((int)((unsigned int)((int)((unsigned int)v300 >> 2)) >> 1)) & 3) * 2)) + ((((v347 + ((~(((v349 ^ -1) | (-(v349 ^ -1))) >> 31)) & 2)) - (v351 + ((~(((v353 ^ -1) | (-(v353 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
        int v359 = v358[v625];
        int * v360 = v298->cache_vals;
        int v627 = (((4 + ((((int)((unsigned int)((int)((unsigned int)v300 >> 2)) >> 1)) & 3) * 2)) + ((((v347 + ((~(((v349 ^ -1) | (-(v349 ^ -1))) >> 31)) & 2)) - (v351 + ((~(((v353 ^ -1) | (-(v353 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
        int v361 = v360[v627];
        int * v362 = v298->mem;
        int v629 = v357 * 2;
        v362[v629] = v359;
        int * v364 = v298->mem;
        int v632 = (v357 * 2) + 1;
        v364[v632] = v361;
        ;
      } else {
        ;
      }
      int * v369 = v298->mem;
      int v637 = ((int)((unsigned int)((int)((unsigned int)v300 >> 2)) >> 1)) * 2;
      int v370 = v369[v637];
      int * v371 = v298->mem;
      int v639 = (((int)((unsigned int)((int)((unsigned int)v300 >> 2)) >> 1)) * 2) + 1;
      int v372 = v371[v639];
      int * v373 = v298->cache_vals;
      int v641 = ((4 + ((((int)((unsigned int)((int)((unsigned int)v300 >> 2)) >> 1)) & 3) * 2)) + ((((v347 + ((~(((v349 ^ -1) | (-(v349 ^ -1))) >> 31)) & 2)) - (v351 + ((~(((v353 ^ -1) | (-(v353 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
      v373[v641] = v370;
      int * v375 = v298->cache_vals;
      int v644 = (((4 + ((((int)((unsigned int)((int)((unsigned int)v300 >> 2)) >> 1)) & 3) * 2)) + ((((v347 + ((~(((v349 ^ -1) | (-(v349 ^ -1))) >> 31)) & 2)) - (v351 + ((~(((v353 ^ -1) | (-(v353 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
      v375[v644] = v372;
      int * v377 = v298->cache_tags;
      int v647 = (int)((unsigned int)((int)((unsigned int)v300 >> 2)) >> 1);
      v377[v621] = v647;
      int * v379 = v298->cache_dirty;
      v379[v621] = 0;
      int * v381 = v298->cache_age;
      v381[v621] = 1;
      int * v383 = v298->cache_age;
      int v384 = v383[v621];
      int * v385 = v298->cache_age;
      int v386 = v385[v584];
      int * v387 = v298->cache_age;
      int v655 = v386 + ((int)((unsigned int)(v386 - v384) >> 31));
      v387[v584] = v655;
      int * v389 = v298->cache_age;
      int v390 = v389[v586];
      int * v391 = v298->cache_age;
      int v658 = v390 + ((int)((unsigned int)(v390 - v384) >> 31));
      v391[v586] = v658;
      int * v393 = v298->cache_age;
      v393[v621] = 0;
      v396 = v621;
    }
    int * v397 = v298->cache_vals;
    int v661 = v396 * 2;
    int v398 = v397[v661];
    int * v399 = v298->cache_vals;
    int v663 = (v396 * 2) + 1;
    int v400 = v399[v663];
    int * v401 = v298->cache_vals;
    int v665 = (((((int)((unsigned int)((int)((unsigned int)v300 >> 2)) >> 1)) & 1) * 2) + ((((v326 + ((~(((v328 ^ -1) | (-(v328 ^ -1))) >> 31)) & 2)) - (v330 + ((~(((v332 ^ -1) | (-(v332 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
    v401[v665] = v398;
    int * v403 = v298->cache_vals;
    int v668 = ((((((int)((unsigned int)((int)((unsigned int)v300 >> 2)) >> 1)) & 1) * 2) + ((((v326 + ((~(((v328 ^ -1) | (-(v328 ^ -1))) >> 31)) & 2)) - (v330 + ((~(((v332 ^ -1) | (-(v332 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
    v403[v668] = v400;
    int * v405 = v298->cache_tags;
    int v671 = ((((int)((unsigned int)((int)((unsigned int)v300 >> 2)) >> 1)) & 1) * 2) + ((((v326 + ((~(((v328 ^ -1) | (-(v328 ^ -1))) >> 31)) & 2)) - (v330 + ((~(((v332 ^ -1) | (-(v332 ^ -1))) >> 31)) & 2))) >> 31) & 1);
    int v672 = (int)((unsigned int)((int)((unsigned int)v300 >> 2)) >> 1);
    v405[v671] = v672;
    int * v407 = v298->cache_dirty;
    v407[v671] = 0;
    int * v409 = v298->cache_age;
    v409[v671] = 1;
    int * v411 = v298->cache_age;
    int v412 = v411[v671];
    int * v413 = v298->cache_age;
    int v414 = v413[v580];
    int * v415 = v298->cache_age;
    int v680 = v414 + ((int)((unsigned int)(v414 - v412) >> 31));
    v415[v580] = v680;
    int * v417 = v298->cache_age;
    int v418 = v417[v582];
    int * v419 = v298->cache_age;
    int v683 = v418 + ((int)((unsigned int)(v418 - v412) >> 31));
    v419[v582] = v683;
    int * v421 = v298->cache_age;
    v421[v671] = 0;
    v424 = v671;
  }
  int v686 = (v424 * 2) + (((int)((unsigned int)v300 >> 2)) & 1);
  int v425 = v311[v686];
  int * v426 = v298->regs;
  v426[7] = v425;
  struct StateT * v428 = v275->b;
  int * v429 = v428->regs;
  int v430 = v429[6];
  int * v431 = v428->cache_tags;
  int v692 = (((int)((unsigned int)((int)((unsigned int)v430 >> 2)) >> 1)) & 1) * 2;
  int v432 = v431[v692];
  int * v433 = v428->cache_tags;
  int v694 = ((((int)((unsigned int)((int)((unsigned int)v430 >> 2)) >> 1)) & 1) * 2) + 1;
  int v434 = v433[v694];
  int * v435 = v428->cache_tags;
  int v696 = 4 + ((((int)((unsigned int)((int)((unsigned int)v430 >> 2)) >> 1)) & 3) * 2);
  int v436 = v435[v696];
  int * v437 = v428->cache_tags;
  int v698 = (4 + ((((int)((unsigned int)((int)((unsigned int)v430 >> 2)) >> 1)) & 3) * 2)) + 1;
  int v438 = v437[v698];
  int v439 = v428->timer;
  int v699 = v439 + ((100 ^ (((~(((v436 ^ ((int)((unsigned int)((int)((unsigned int)v430 >> 2)) >> 1))) | (-(v436 ^ ((int)((unsigned int)((int)((unsigned int)v430 >> 2)) >> 1))))) >> 31)) | (~(((v438 ^ ((int)((unsigned int)((int)((unsigned int)v430 >> 2)) >> 1))) | (-(v438 ^ ((int)((unsigned int)((int)((unsigned int)v430 >> 2)) >> 1))))) >> 31))) & 104)) ^ (((~(((v432 ^ ((int)((unsigned int)((int)((unsigned int)v430 >> 2)) >> 1))) | (-(v432 ^ ((int)((unsigned int)((int)((unsigned int)v430 >> 2)) >> 1))))) >> 31)) | (~(((v434 ^ ((int)((unsigned int)((int)((unsigned int)v430 >> 2)) >> 1))) | (-(v434 ^ ((int)((unsigned int)((int)((unsigned int)v430 >> 2)) >> 1))))) >> 31))) & (1 ^ (100 ^ (((~(((v436 ^ ((int)((unsigned int)((int)((unsigned int)v430 >> 2)) >> 1))) | (-(v436 ^ ((int)((unsigned int)((int)((unsigned int)v430 >> 2)) >> 1))))) >> 31)) | (~(((v438 ^ ((int)((unsigned int)((int)((unsigned int)v430 >> 2)) >> 1))) | (-(v438 ^ ((int)((unsigned int)((int)((unsigned int)v430 >> 2)) >> 1))))) >> 31))) & 104)))));
  v428->timer = v699;
  int * v441 = v428->cache_vals;
  bool v700 = !(((~(((v432 ^ ((int)((unsigned int)((int)((unsigned int)v430 >> 2)) >> 1))) | (-(v432 ^ ((int)((unsigned int)((int)((unsigned int)v430 >> 2)) >> 1))))) >> 31)) | (~(((v434 ^ ((int)((unsigned int)((int)((unsigned int)v430 >> 2)) >> 1))) | (-(v434 ^ ((int)((unsigned int)((int)((unsigned int)v430 >> 2)) >> 1))))) >> 31))) == 0);
  int v554;
  if (v700) {
    int * v442 = v428->cache_age;
    int v702 = ((((int)((unsigned int)((int)((unsigned int)v430 >> 2)) >> 1)) & 1) * 2) + ((~(((v434 ^ ((int)((unsigned int)((int)((unsigned int)v430 >> 2)) >> 1))) | (-(v434 ^ ((int)((unsigned int)((int)((unsigned int)v430 >> 2)) >> 1))))) >> 31)) & 1);
    int v443 = v442[v702];
    int * v444 = v428->cache_age;
    int v445 = v444[v692];
    int * v446 = v428->cache_age;
    int v705 = v445 + ((int)((unsigned int)(v445 - v443) >> 31));
    v446[v692] = v705;
    int * v448 = v428->cache_age;
    int v449 = v448[v694];
    int * v450 = v428->cache_age;
    int v708 = v449 + ((int)((unsigned int)(v449 - v443) >> 31));
    v450[v694] = v708;
    int * v452 = v428->cache_age;
    v452[v702] = 0;
    v554 = v702;
  } else {
    int * v455 = v428->cache_age;
    int v712 = (((int)((unsigned int)((int)((unsigned int)v430 >> 2)) >> 1)) & 1) * 2;
    int v456 = v455[v712];
    int * v457 = v428->cache_tags;
    int v458 = v457[v712];
    int * v459 = v428->cache_age;
    int v460 = v459[v694];
    int * v461 = v428->cache_tags;
    int v462 = v461[v694];
    bool v716 = !(((~(((v436 ^ ((int)((unsigned int)((int)((unsigned int)v430 >> 2)) >> 1))) | (-(v436 ^ ((int)((unsigned int)((int)((unsigned int)v430 >> 2)) >> 1))))) >> 31)) | (~(((v438 ^ ((int)((unsigned int)((int)((unsigned int)v430 >> 2)) >> 1))) | (-(v438 ^ ((int)((unsigned int)((int)((unsigned int)v430 >> 2)) >> 1))))) >> 31))) == 0);
    int v526;
    if (v716) {
      int * v463 = v428->cache_age;
      int v718 = (4 + ((((int)((unsigned int)((int)((unsigned int)v430 >> 2)) >> 1)) & 3) * 2)) + ((~(((v438 ^ ((int)((unsigned int)((int)((unsigned int)v430 >> 2)) >> 1))) | (-(v438 ^ ((int)((unsigned int)((int)((unsigned int)v430 >> 2)) >> 1))))) >> 31)) & 1);
      int v464 = v463[v718];
      int * v465 = v428->cache_age;
      int v466 = v465[v696];
      int * v467 = v428->cache_age;
      int v721 = v466 + ((int)((unsigned int)(v466 - v464) >> 31));
      v467[v696] = v721;
      int * v469 = v428->cache_age;
      int v470 = v469[v698];
      int * v471 = v428->cache_age;
      int v724 = v470 + ((int)((unsigned int)(v470 - v464) >> 31));
      v471[v698] = v724;
      int * v473 = v428->cache_age;
      v473[v718] = 0;
      v526 = v718;
    } else {
      int * v476 = v428->cache_age;
      int v728 = 4 + ((((int)((unsigned int)((int)((unsigned int)v430 >> 2)) >> 1)) & 3) * 2);
      int v477 = v476[v728];
      int * v478 = v428->cache_tags;
      int v479 = v478[v728];
      int * v480 = v428->cache_age;
      int v481 = v480[v698];
      int * v482 = v428->cache_tags;
      int v483 = v482[v698];
      int * v484 = v428->cache_dirty;
      int v733 = (4 + ((((int)((unsigned int)((int)((unsigned int)v430 >> 2)) >> 1)) & 3) * 2)) + ((((v477 + ((~(((v479 ^ -1) | (-(v479 ^ -1))) >> 31)) & 2)) - (v481 + ((~(((v483 ^ -1) | (-(v483 ^ -1))) >> 31)) & 2))) >> 31) & 1);
      int v485 = v484[v733];
      bool v734 = !(v485 == 0);
      if (v734) {
        int * v486 = v428->cache_tags;
        int v487 = v486[v733];
        int * v488 = v428->cache_vals;
        int v737 = ((4 + ((((int)((unsigned int)((int)((unsigned int)v430 >> 2)) >> 1)) & 3) * 2)) + ((((v477 + ((~(((v479 ^ -1) | (-(v479 ^ -1))) >> 31)) & 2)) - (v481 + ((~(((v483 ^ -1) | (-(v483 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
        int v489 = v488[v737];
        int * v490 = v428->cache_vals;
        int v739 = (((4 + ((((int)((unsigned int)((int)((unsigned int)v430 >> 2)) >> 1)) & 3) * 2)) + ((((v477 + ((~(((v479 ^ -1) | (-(v479 ^ -1))) >> 31)) & 2)) - (v481 + ((~(((v483 ^ -1) | (-(v483 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
        int v491 = v490[v739];
        int * v492 = v428->mem;
        int v741 = v487 * 2;
        v492[v741] = v489;
        int * v494 = v428->mem;
        int v744 = (v487 * 2) + 1;
        v494[v744] = v491;
        ;
      } else {
        ;
      }
      int * v499 = v428->mem;
      int v749 = ((int)((unsigned int)((int)((unsigned int)v430 >> 2)) >> 1)) * 2;
      int v500 = v499[v749];
      int * v501 = v428->mem;
      int v751 = (((int)((unsigned int)((int)((unsigned int)v430 >> 2)) >> 1)) * 2) + 1;
      int v502 = v501[v751];
      int * v503 = v428->cache_vals;
      int v753 = ((4 + ((((int)((unsigned int)((int)((unsigned int)v430 >> 2)) >> 1)) & 3) * 2)) + ((((v477 + ((~(((v479 ^ -1) | (-(v479 ^ -1))) >> 31)) & 2)) - (v481 + ((~(((v483 ^ -1) | (-(v483 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
      v503[v753] = v500;
      int * v505 = v428->cache_vals;
      int v756 = (((4 + ((((int)((unsigned int)((int)((unsigned int)v430 >> 2)) >> 1)) & 3) * 2)) + ((((v477 + ((~(((v479 ^ -1) | (-(v479 ^ -1))) >> 31)) & 2)) - (v481 + ((~(((v483 ^ -1) | (-(v483 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
      v505[v756] = v502;
      int * v507 = v428->cache_tags;
      int v759 = (int)((unsigned int)((int)((unsigned int)v430 >> 2)) >> 1);
      v507[v733] = v759;
      int * v509 = v428->cache_dirty;
      v509[v733] = 0;
      int * v511 = v428->cache_age;
      v511[v733] = 1;
      int * v513 = v428->cache_age;
      int v514 = v513[v733];
      int * v515 = v428->cache_age;
      int v516 = v515[v696];
      int * v517 = v428->cache_age;
      int v767 = v516 + ((int)((unsigned int)(v516 - v514) >> 31));
      v517[v696] = v767;
      int * v519 = v428->cache_age;
      int v520 = v519[v698];
      int * v521 = v428->cache_age;
      int v770 = v520 + ((int)((unsigned int)(v520 - v514) >> 31));
      v521[v698] = v770;
      int * v523 = v428->cache_age;
      v523[v733] = 0;
      v526 = v733;
    }
    int * v527 = v428->cache_vals;
    int v773 = v526 * 2;
    int v528 = v527[v773];
    int * v529 = v428->cache_vals;
    int v775 = (v526 * 2) + 1;
    int v530 = v529[v775];
    int * v531 = v428->cache_vals;
    int v777 = (((((int)((unsigned int)((int)((unsigned int)v430 >> 2)) >> 1)) & 1) * 2) + ((((v456 + ((~(((v458 ^ -1) | (-(v458 ^ -1))) >> 31)) & 2)) - (v460 + ((~(((v462 ^ -1) | (-(v462 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
    v531[v777] = v528;
    int * v533 = v428->cache_vals;
    int v780 = ((((((int)((unsigned int)((int)((unsigned int)v430 >> 2)) >> 1)) & 1) * 2) + ((((v456 + ((~(((v458 ^ -1) | (-(v458 ^ -1))) >> 31)) & 2)) - (v460 + ((~(((v462 ^ -1) | (-(v462 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
    v533[v780] = v530;
    int * v535 = v428->cache_tags;
    int v783 = ((((int)((unsigned int)((int)((unsigned int)v430 >> 2)) >> 1)) & 1) * 2) + ((((v456 + ((~(((v458 ^ -1) | (-(v458 ^ -1))) >> 31)) & 2)) - (v460 + ((~(((v462 ^ -1) | (-(v462 ^ -1))) >> 31)) & 2))) >> 31) & 1);
    int v784 = (int)((unsigned int)((int)((unsigned int)v430 >> 2)) >> 1);
    v535[v783] = v784;
    int * v537 = v428->cache_dirty;
    v537[v783] = 0;
    int * v539 = v428->cache_age;
    v539[v783] = 1;
    int * v541 = v428->cache_age;
    int v542 = v541[v783];
    int * v543 = v428->cache_age;
    int v544 = v543[v692];
    int * v545 = v428->cache_age;
    int v792 = v544 + ((int)((unsigned int)(v544 - v542) >> 31));
    v545[v692] = v792;
    int * v547 = v428->cache_age;
    int v548 = v547[v694];
    int * v549 = v428->cache_age;
    int v795 = v548 + ((int)((unsigned int)(v548 - v542) >> 31));
    v549[v694] = v795;
    int * v551 = v428->cache_age;
    v551[v783] = 0;
    v554 = v783;
  }
  int v798 = (v554 * 2) + (((int)((unsigned int)v430 >> 2)) & 1);
  int v555 = v441[v798];
  int * v556 = v428->regs;
  v556[7] = v555;
  struct StateT2 * v558 = slot_8(v275);
  return v558;
}

struct StateT2 * slot_3(struct StateT2 * v110) {
  struct StateT * v111 = v110->a;
  int v112 = v111->timer;
  struct StateT * v113 = v110->b;
  int v114 = v113->timer;
  bool v133 = v112 == v114;
  squared_assert(v133);
  squared_assume(v133);
  struct StateT * v117 = v110->a;
  int v118 = v117->timer;
  int v135 = v118 + 1;
  v117->timer = v135;
  struct StateT * v120 = v110->b;
  int v121 = v120->timer;
  int v137 = v121 + 1;
  v120->timer = v137;
  struct StateT * v123 = v110->a;
  int * v124 = v123->regs;
  v124[15] = 16;
  struct StateT * v126 = v110->b;
  int * v127 = v126->regs;
  v127[15] = 16;
  struct StateT2 * v129 = slot_4(v110);
  return v129;
}

struct StateT2 * snippet(struct StateT2 * v0) {
  struct StateT2 * v1 = slot_0(v0);
  return v1;
}

struct StateT2 * slot_10(struct StateT2 * v1400) {
  struct StateT * v1401 = v1400->a;
  int v1402 = v1401->timer;
  struct StateT * v1403 = v1400->b;
  int v1404 = v1403->timer;
  bool v1441 = v1402 == v1404;
  squared_assert(v1441);
  squared_assume(v1441);
  struct StateT * v1407 = v1400->a;
  int * v1408 = v1407->saved_regs;
  int * v1409 = v1407->regs;
  int v1410 = v1409[16];
  v1408[16] = v1410;
  struct StateT * v1412 = v1400->b;
  int * v1413 = v1412->saved_regs;
  int * v1414 = v1412->regs;
  int v1415 = v1414[16];
  v1413[16] = v1415;
  struct StateT * v1417 = v1400->a;
  int v1418 = v1417->timer;
  int v1452 = v1418 + 1;
  v1417->timer = v1452;
  struct StateT * v1420 = v1400->b;
  int v1421 = v1420->timer;
  int v1454 = v1421 + 1;
  v1420->timer = v1454;
  struct StateT * v1423 = v1400->a;
  int * v1424 = v1423->regs;
  int v1425 = v1424[7];
  int * v1426 = v1423->regs;
  int v1427 = v1426[9];
  int * v1428 = v1423->regs;
  int v1461 = v1425 ^ v1427;
  v1428[16] = v1461;
  struct StateT * v1430 = v1400->b;
  int * v1431 = v1430->regs;
  int v1432 = v1431[7];
  int * v1433 = v1430->regs;
  int v1434 = v1433[9];
  int * v1435 = v1430->regs;
  int v1466 = v1432 ^ v1434;
  v1435[16] = v1466;
  struct StateT2 * v1437 = slot_11(v1400);
  return v1437;
}

struct StateT2 * slot_1(struct StateT2 * v38) {
  struct StateT * v39 = v38->a;
  int v40 = v39->timer;
  struct StateT * v41 = v38->b;
  int v42 = v41->timer;
  bool v61 = v40 == v42;
  squared_assert(v61);
  squared_assume(v61);
  struct StateT * v45 = v38->a;
  int v46 = v45->timer;
  int v63 = v46 + 1;
  v45->timer = v63;
  struct StateT * v48 = v38->b;
  int v49 = v48->timer;
  int v65 = v49 + 1;
  v48->timer = v65;
  struct StateT * v51 = v38->a;
  int * v52 = v51->regs;
  v52[13] = 80;
  struct StateT * v54 = v38->b;
  int * v55 = v54->regs;
  v55[13] = 80;
  struct StateT2 * v57 = slot_2(v38);
  return v57;
}

struct StateT2 * slot_8(struct StateT2 * v803) {
  struct StateT * v804 = v803->a;
  int v805 = v804->timer;
  struct StateT * v806 = v803->b;
  int v807 = v806->timer;
  bool v844 = v805 == v807;
  squared_assert(v844);
  squared_assume(v844);
  struct StateT * v810 = v803->a;
  int * v811 = v810->saved_regs;
  int * v812 = v810->regs;
  int v813 = v812[8];
  v811[8] = v813;
  struct StateT * v815 = v803->b;
  int * v816 = v815->saved_regs;
  int * v817 = v815->regs;
  int v818 = v817[8];
  v816[8] = v818;
  struct StateT * v820 = v803->a;
  int v821 = v820->timer;
  int v855 = v821 + 1;
  v820->timer = v855;
  struct StateT * v823 = v803->b;
  int v824 = v823->timer;
  int v857 = v824 + 1;
  v823->timer = v857;
  struct StateT * v826 = v803->a;
  int * v827 = v826->regs;
  int v828 = v827[13];
  int * v829 = v826->regs;
  int v830 = v829[14];
  int * v831 = v826->regs;
  int v864 = v828 + v830;
  v831[8] = v864;
  struct StateT * v833 = v803->b;
  int * v834 = v833->regs;
  int v835 = v834[13];
  int * v836 = v833->regs;
  int v837 = v836[14];
  int * v838 = v833->regs;
  int v869 = v835 + v837;
  v838[8] = v869;
  struct StateT2 * v840 = slot_9(v803);
  return v840;
}

struct StateT2 * slot_4(struct StateT2 * v146) {
  struct StateT * v147 = v146->a;
  int v148 = v147->timer;
  struct StateT * v149 = v146->b;
  int v150 = v149->timer;
  bool v169 = v148 == v150;
  squared_assert(v169);
  squared_assume(v169);
  struct StateT * v153 = v146->a;
  int v154 = v153->timer;
  int v171 = v154 + 1;
  v153->timer = v171;
  struct StateT * v156 = v146->b;
  int v157 = v156->timer;
  int v173 = v157 + 1;
  v156->timer = v173;
  struct StateT * v159 = v146->a;
  int * v160 = v159->regs;
  v160[5] = 0;
  struct StateT * v162 = v146->b;
  int * v163 = v162->regs;
  v163[5] = 0;
  struct StateT2 * v165 = slot_5(v146);
  return v165;
}

struct StateT2 * slot_13(struct StateT2 * v1680) {
  struct StateT * v1681 = v1680->a;
  int v1682 = v1681->timer;
  struct StateT * v1683 = v1680->b;
  int v1684 = v1683->timer;
  bool v1712 = v1682 == v1684;
  squared_assert(v1712);
  squared_assume(v1712);
  struct StateT * v1687 = v1680->a;
  int v1688 = v1687->timer;
  int v1714 = v1688 + 1;
  v1687->timer = v1714;
  struct StateT * v1690 = v1680->b;
  int v1691 = v1690->timer;
  int v1716 = v1691 + 1;
  v1690->timer = v1716;
  struct StateT * v1693 = v1680->a;
  int * v1694 = v1693->regs;
  int v1695 = v1694[5];
  bool v1720 = (v1695 ^ -2147483648) < -2147483647;
  int v1698;
  if (v1720) {
    v1698 = 1;
  } else {
    v1698 = 0;
  }
  int * v1699 = v1693->regs;
  v1699[11] = v1698;
  struct StateT * v1701 = v1680->b;
  int * v1702 = v1701->regs;
  int v1703 = v1702[5];
  bool v1728 = (v1703 ^ -2147483648) < -2147483647;
  int v1706;
  if (v1728) {
    v1706 = 1;
  } else {
    v1706 = 0;
  }
  int * v1707 = v1701->regs;
  v1707[11] = v1706;
  return v1680;
}

struct StateT2 * slot_9(struct StateT2 * v872) {
  struct StateT * v873 = v872->a;
  int v874 = v873->timer;
  struct StateT * v875 = v872->b;
  int v876 = v875->timer;
  bool v1159 = v874 == v876;
  squared_assert(v1159);
  squared_assume(v1159);
  struct StateT * v879 = v872->a;
  int * v880 = v879->saved_regs;
  int * v881 = v879->regs;
  int v882 = v881[9];
  v880[9] = v882;
  struct StateT * v884 = v872->b;
  int * v885 = v884->saved_regs;
  int * v886 = v884->regs;
  int v887 = v886[9];
  v885[9] = v887;
  struct StateT * v889 = v872->a;
  int v890 = v889->timer;
  int v1170 = v890 + 1;
  v889->timer = v1170;
  struct StateT * v892 = v872->b;
  int v893 = v892->timer;
  int v1172 = v893 + 1;
  v892->timer = v1172;
  struct StateT * v895 = v872->a;
  int * v896 = v895->regs;
  int v897 = v896[8];
  int * v898 = v895->cache_tags;
  int v1177 = (((int)((unsigned int)((int)((unsigned int)v897 >> 2)) >> 1)) & 1) * 2;
  int v899 = v898[v1177];
  int * v900 = v895->cache_tags;
  int v1179 = ((((int)((unsigned int)((int)((unsigned int)v897 >> 2)) >> 1)) & 1) * 2) + 1;
  int v901 = v900[v1179];
  int * v902 = v895->cache_tags;
  int v1181 = 4 + ((((int)((unsigned int)((int)((unsigned int)v897 >> 2)) >> 1)) & 3) * 2);
  int v903 = v902[v1181];
  int * v904 = v895->cache_tags;
  int v1183 = (4 + ((((int)((unsigned int)((int)((unsigned int)v897 >> 2)) >> 1)) & 3) * 2)) + 1;
  int v905 = v904[v1183];
  int v906 = v895->timer;
  int v1184 = v906 + ((100 ^ (((~(((v903 ^ ((int)((unsigned int)((int)((unsigned int)v897 >> 2)) >> 1))) | (-(v903 ^ ((int)((unsigned int)((int)((unsigned int)v897 >> 2)) >> 1))))) >> 31)) | (~(((v905 ^ ((int)((unsigned int)((int)((unsigned int)v897 >> 2)) >> 1))) | (-(v905 ^ ((int)((unsigned int)((int)((unsigned int)v897 >> 2)) >> 1))))) >> 31))) & 104)) ^ (((~(((v899 ^ ((int)((unsigned int)((int)((unsigned int)v897 >> 2)) >> 1))) | (-(v899 ^ ((int)((unsigned int)((int)((unsigned int)v897 >> 2)) >> 1))))) >> 31)) | (~(((v901 ^ ((int)((unsigned int)((int)((unsigned int)v897 >> 2)) >> 1))) | (-(v901 ^ ((int)((unsigned int)((int)((unsigned int)v897 >> 2)) >> 1))))) >> 31))) & (1 ^ (100 ^ (((~(((v903 ^ ((int)((unsigned int)((int)((unsigned int)v897 >> 2)) >> 1))) | (-(v903 ^ ((int)((unsigned int)((int)((unsigned int)v897 >> 2)) >> 1))))) >> 31)) | (~(((v905 ^ ((int)((unsigned int)((int)((unsigned int)v897 >> 2)) >> 1))) | (-(v905 ^ ((int)((unsigned int)((int)((unsigned int)v897 >> 2)) >> 1))))) >> 31))) & 104)))));
  v895->timer = v1184;
  int * v908 = v895->cache_vals;
  bool v1185 = !(((~(((v899 ^ ((int)((unsigned int)((int)((unsigned int)v897 >> 2)) >> 1))) | (-(v899 ^ ((int)((unsigned int)((int)((unsigned int)v897 >> 2)) >> 1))))) >> 31)) | (~(((v901 ^ ((int)((unsigned int)((int)((unsigned int)v897 >> 2)) >> 1))) | (-(v901 ^ ((int)((unsigned int)((int)((unsigned int)v897 >> 2)) >> 1))))) >> 31))) == 0);
  int v1021;
  if (v1185) {
    int * v909 = v895->cache_age;
    int v1187 = ((((int)((unsigned int)((int)((unsigned int)v897 >> 2)) >> 1)) & 1) * 2) + ((~(((v901 ^ ((int)((unsigned int)((int)((unsigned int)v897 >> 2)) >> 1))) | (-(v901 ^ ((int)((unsigned int)((int)((unsigned int)v897 >> 2)) >> 1))))) >> 31)) & 1);
    int v910 = v909[v1187];
    int * v911 = v895->cache_age;
    int v912 = v911[v1177];
    int * v913 = v895->cache_age;
    int v1190 = v912 + ((int)((unsigned int)(v912 - v910) >> 31));
    v913[v1177] = v1190;
    int * v915 = v895->cache_age;
    int v916 = v915[v1179];
    int * v917 = v895->cache_age;
    int v1193 = v916 + ((int)((unsigned int)(v916 - v910) >> 31));
    v917[v1179] = v1193;
    int * v919 = v895->cache_age;
    v919[v1187] = 0;
    v1021 = v1187;
  } else {
    int * v922 = v895->cache_age;
    int v1197 = (((int)((unsigned int)((int)((unsigned int)v897 >> 2)) >> 1)) & 1) * 2;
    int v923 = v922[v1197];
    int * v924 = v895->cache_tags;
    int v925 = v924[v1197];
    int * v926 = v895->cache_age;
    int v927 = v926[v1179];
    int * v928 = v895->cache_tags;
    int v929 = v928[v1179];
    bool v1201 = !(((~(((v903 ^ ((int)((unsigned int)((int)((unsigned int)v897 >> 2)) >> 1))) | (-(v903 ^ ((int)((unsigned int)((int)((unsigned int)v897 >> 2)) >> 1))))) >> 31)) | (~(((v905 ^ ((int)((unsigned int)((int)((unsigned int)v897 >> 2)) >> 1))) | (-(v905 ^ ((int)((unsigned int)((int)((unsigned int)v897 >> 2)) >> 1))))) >> 31))) == 0);
    int v993;
    if (v1201) {
      int * v930 = v895->cache_age;
      int v1203 = (4 + ((((int)((unsigned int)((int)((unsigned int)v897 >> 2)) >> 1)) & 3) * 2)) + ((~(((v905 ^ ((int)((unsigned int)((int)((unsigned int)v897 >> 2)) >> 1))) | (-(v905 ^ ((int)((unsigned int)((int)((unsigned int)v897 >> 2)) >> 1))))) >> 31)) & 1);
      int v931 = v930[v1203];
      int * v932 = v895->cache_age;
      int v933 = v932[v1181];
      int * v934 = v895->cache_age;
      int v1206 = v933 + ((int)((unsigned int)(v933 - v931) >> 31));
      v934[v1181] = v1206;
      int * v936 = v895->cache_age;
      int v937 = v936[v1183];
      int * v938 = v895->cache_age;
      int v1209 = v937 + ((int)((unsigned int)(v937 - v931) >> 31));
      v938[v1183] = v1209;
      int * v940 = v895->cache_age;
      v940[v1203] = 0;
      v993 = v1203;
    } else {
      int * v943 = v895->cache_age;
      int v1213 = 4 + ((((int)((unsigned int)((int)((unsigned int)v897 >> 2)) >> 1)) & 3) * 2);
      int v944 = v943[v1213];
      int * v945 = v895->cache_tags;
      int v946 = v945[v1213];
      int * v947 = v895->cache_age;
      int v948 = v947[v1183];
      int * v949 = v895->cache_tags;
      int v950 = v949[v1183];
      int * v951 = v895->cache_dirty;
      int v1218 = (4 + ((((int)((unsigned int)((int)((unsigned int)v897 >> 2)) >> 1)) & 3) * 2)) + ((((v944 + ((~(((v946 ^ -1) | (-(v946 ^ -1))) >> 31)) & 2)) - (v948 + ((~(((v950 ^ -1) | (-(v950 ^ -1))) >> 31)) & 2))) >> 31) & 1);
      int v952 = v951[v1218];
      bool v1219 = !(v952 == 0);
      if (v1219) {
        int * v953 = v895->cache_tags;
        int v954 = v953[v1218];
        int * v955 = v895->cache_vals;
        int v1222 = ((4 + ((((int)((unsigned int)((int)((unsigned int)v897 >> 2)) >> 1)) & 3) * 2)) + ((((v944 + ((~(((v946 ^ -1) | (-(v946 ^ -1))) >> 31)) & 2)) - (v948 + ((~(((v950 ^ -1) | (-(v950 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
        int v956 = v955[v1222];
        int * v957 = v895->cache_vals;
        int v1224 = (((4 + ((((int)((unsigned int)((int)((unsigned int)v897 >> 2)) >> 1)) & 3) * 2)) + ((((v944 + ((~(((v946 ^ -1) | (-(v946 ^ -1))) >> 31)) & 2)) - (v948 + ((~(((v950 ^ -1) | (-(v950 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
        int v958 = v957[v1224];
        int * v959 = v895->mem;
        int v1226 = v954 * 2;
        v959[v1226] = v956;
        int * v961 = v895->mem;
        int v1229 = (v954 * 2) + 1;
        v961[v1229] = v958;
        ;
      } else {
        ;
      }
      int * v966 = v895->mem;
      int v1234 = ((int)((unsigned int)((int)((unsigned int)v897 >> 2)) >> 1)) * 2;
      int v967 = v966[v1234];
      int * v968 = v895->mem;
      int v1236 = (((int)((unsigned int)((int)((unsigned int)v897 >> 2)) >> 1)) * 2) + 1;
      int v969 = v968[v1236];
      int * v970 = v895->cache_vals;
      int v1238 = ((4 + ((((int)((unsigned int)((int)((unsigned int)v897 >> 2)) >> 1)) & 3) * 2)) + ((((v944 + ((~(((v946 ^ -1) | (-(v946 ^ -1))) >> 31)) & 2)) - (v948 + ((~(((v950 ^ -1) | (-(v950 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
      v970[v1238] = v967;
      int * v972 = v895->cache_vals;
      int v1241 = (((4 + ((((int)((unsigned int)((int)((unsigned int)v897 >> 2)) >> 1)) & 3) * 2)) + ((((v944 + ((~(((v946 ^ -1) | (-(v946 ^ -1))) >> 31)) & 2)) - (v948 + ((~(((v950 ^ -1) | (-(v950 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
      v972[v1241] = v969;
      int * v974 = v895->cache_tags;
      int v1244 = (int)((unsigned int)((int)((unsigned int)v897 >> 2)) >> 1);
      v974[v1218] = v1244;
      int * v976 = v895->cache_dirty;
      v976[v1218] = 0;
      int * v978 = v895->cache_age;
      v978[v1218] = 1;
      int * v980 = v895->cache_age;
      int v981 = v980[v1218];
      int * v982 = v895->cache_age;
      int v983 = v982[v1181];
      int * v984 = v895->cache_age;
      int v1252 = v983 + ((int)((unsigned int)(v983 - v981) >> 31));
      v984[v1181] = v1252;
      int * v986 = v895->cache_age;
      int v987 = v986[v1183];
      int * v988 = v895->cache_age;
      int v1255 = v987 + ((int)((unsigned int)(v987 - v981) >> 31));
      v988[v1183] = v1255;
      int * v990 = v895->cache_age;
      v990[v1218] = 0;
      v993 = v1218;
    }
    int * v994 = v895->cache_vals;
    int v1258 = v993 * 2;
    int v995 = v994[v1258];
    int * v996 = v895->cache_vals;
    int v1260 = (v993 * 2) + 1;
    int v997 = v996[v1260];
    int * v998 = v895->cache_vals;
    int v1262 = (((((int)((unsigned int)((int)((unsigned int)v897 >> 2)) >> 1)) & 1) * 2) + ((((v923 + ((~(((v925 ^ -1) | (-(v925 ^ -1))) >> 31)) & 2)) - (v927 + ((~(((v929 ^ -1) | (-(v929 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
    v998[v1262] = v995;
    int * v1000 = v895->cache_vals;
    int v1265 = ((((((int)((unsigned int)((int)((unsigned int)v897 >> 2)) >> 1)) & 1) * 2) + ((((v923 + ((~(((v925 ^ -1) | (-(v925 ^ -1))) >> 31)) & 2)) - (v927 + ((~(((v929 ^ -1) | (-(v929 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
    v1000[v1265] = v997;
    int * v1002 = v895->cache_tags;
    int v1268 = ((((int)((unsigned int)((int)((unsigned int)v897 >> 2)) >> 1)) & 1) * 2) + ((((v923 + ((~(((v925 ^ -1) | (-(v925 ^ -1))) >> 31)) & 2)) - (v927 + ((~(((v929 ^ -1) | (-(v929 ^ -1))) >> 31)) & 2))) >> 31) & 1);
    int v1269 = (int)((unsigned int)((int)((unsigned int)v897 >> 2)) >> 1);
    v1002[v1268] = v1269;
    int * v1004 = v895->cache_dirty;
    v1004[v1268] = 0;
    int * v1006 = v895->cache_age;
    v1006[v1268] = 1;
    int * v1008 = v895->cache_age;
    int v1009 = v1008[v1268];
    int * v1010 = v895->cache_age;
    int v1011 = v1010[v1177];
    int * v1012 = v895->cache_age;
    int v1277 = v1011 + ((int)((unsigned int)(v1011 - v1009) >> 31));
    v1012[v1177] = v1277;
    int * v1014 = v895->cache_age;
    int v1015 = v1014[v1179];
    int * v1016 = v895->cache_age;
    int v1280 = v1015 + ((int)((unsigned int)(v1015 - v1009) >> 31));
    v1016[v1179] = v1280;
    int * v1018 = v895->cache_age;
    v1018[v1268] = 0;
    v1021 = v1268;
  }
  int v1283 = (v1021 * 2) + (((int)((unsigned int)v897 >> 2)) & 1);
  int v1022 = v908[v1283];
  int * v1023 = v895->regs;
  v1023[9] = v1022;
  struct StateT * v1025 = v872->b;
  int * v1026 = v1025->regs;
  int v1027 = v1026[8];
  int * v1028 = v1025->cache_tags;
  int v1289 = (((int)((unsigned int)((int)((unsigned int)v1027 >> 2)) >> 1)) & 1) * 2;
  int v1029 = v1028[v1289];
  int * v1030 = v1025->cache_tags;
  int v1291 = ((((int)((unsigned int)((int)((unsigned int)v1027 >> 2)) >> 1)) & 1) * 2) + 1;
  int v1031 = v1030[v1291];
  int * v1032 = v1025->cache_tags;
  int v1293 = 4 + ((((int)((unsigned int)((int)((unsigned int)v1027 >> 2)) >> 1)) & 3) * 2);
  int v1033 = v1032[v1293];
  int * v1034 = v1025->cache_tags;
  int v1295 = (4 + ((((int)((unsigned int)((int)((unsigned int)v1027 >> 2)) >> 1)) & 3) * 2)) + 1;
  int v1035 = v1034[v1295];
  int v1036 = v1025->timer;
  int v1296 = v1036 + ((100 ^ (((~(((v1033 ^ ((int)((unsigned int)((int)((unsigned int)v1027 >> 2)) >> 1))) | (-(v1033 ^ ((int)((unsigned int)((int)((unsigned int)v1027 >> 2)) >> 1))))) >> 31)) | (~(((v1035 ^ ((int)((unsigned int)((int)((unsigned int)v1027 >> 2)) >> 1))) | (-(v1035 ^ ((int)((unsigned int)((int)((unsigned int)v1027 >> 2)) >> 1))))) >> 31))) & 104)) ^ (((~(((v1029 ^ ((int)((unsigned int)((int)((unsigned int)v1027 >> 2)) >> 1))) | (-(v1029 ^ ((int)((unsigned int)((int)((unsigned int)v1027 >> 2)) >> 1))))) >> 31)) | (~(((v1031 ^ ((int)((unsigned int)((int)((unsigned int)v1027 >> 2)) >> 1))) | (-(v1031 ^ ((int)((unsigned int)((int)((unsigned int)v1027 >> 2)) >> 1))))) >> 31))) & (1 ^ (100 ^ (((~(((v1033 ^ ((int)((unsigned int)((int)((unsigned int)v1027 >> 2)) >> 1))) | (-(v1033 ^ ((int)((unsigned int)((int)((unsigned int)v1027 >> 2)) >> 1))))) >> 31)) | (~(((v1035 ^ ((int)((unsigned int)((int)((unsigned int)v1027 >> 2)) >> 1))) | (-(v1035 ^ ((int)((unsigned int)((int)((unsigned int)v1027 >> 2)) >> 1))))) >> 31))) & 104)))));
  v1025->timer = v1296;
  int * v1038 = v1025->cache_vals;
  bool v1297 = !(((~(((v1029 ^ ((int)((unsigned int)((int)((unsigned int)v1027 >> 2)) >> 1))) | (-(v1029 ^ ((int)((unsigned int)((int)((unsigned int)v1027 >> 2)) >> 1))))) >> 31)) | (~(((v1031 ^ ((int)((unsigned int)((int)((unsigned int)v1027 >> 2)) >> 1))) | (-(v1031 ^ ((int)((unsigned int)((int)((unsigned int)v1027 >> 2)) >> 1))))) >> 31))) == 0);
  int v1151;
  if (v1297) {
    int * v1039 = v1025->cache_age;
    int v1299 = ((((int)((unsigned int)((int)((unsigned int)v1027 >> 2)) >> 1)) & 1) * 2) + ((~(((v1031 ^ ((int)((unsigned int)((int)((unsigned int)v1027 >> 2)) >> 1))) | (-(v1031 ^ ((int)((unsigned int)((int)((unsigned int)v1027 >> 2)) >> 1))))) >> 31)) & 1);
    int v1040 = v1039[v1299];
    int * v1041 = v1025->cache_age;
    int v1042 = v1041[v1289];
    int * v1043 = v1025->cache_age;
    int v1302 = v1042 + ((int)((unsigned int)(v1042 - v1040) >> 31));
    v1043[v1289] = v1302;
    int * v1045 = v1025->cache_age;
    int v1046 = v1045[v1291];
    int * v1047 = v1025->cache_age;
    int v1305 = v1046 + ((int)((unsigned int)(v1046 - v1040) >> 31));
    v1047[v1291] = v1305;
    int * v1049 = v1025->cache_age;
    v1049[v1299] = 0;
    v1151 = v1299;
  } else {
    int * v1052 = v1025->cache_age;
    int v1309 = (((int)((unsigned int)((int)((unsigned int)v1027 >> 2)) >> 1)) & 1) * 2;
    int v1053 = v1052[v1309];
    int * v1054 = v1025->cache_tags;
    int v1055 = v1054[v1309];
    int * v1056 = v1025->cache_age;
    int v1057 = v1056[v1291];
    int * v1058 = v1025->cache_tags;
    int v1059 = v1058[v1291];
    bool v1313 = !(((~(((v1033 ^ ((int)((unsigned int)((int)((unsigned int)v1027 >> 2)) >> 1))) | (-(v1033 ^ ((int)((unsigned int)((int)((unsigned int)v1027 >> 2)) >> 1))))) >> 31)) | (~(((v1035 ^ ((int)((unsigned int)((int)((unsigned int)v1027 >> 2)) >> 1))) | (-(v1035 ^ ((int)((unsigned int)((int)((unsigned int)v1027 >> 2)) >> 1))))) >> 31))) == 0);
    int v1123;
    if (v1313) {
      int * v1060 = v1025->cache_age;
      int v1315 = (4 + ((((int)((unsigned int)((int)((unsigned int)v1027 >> 2)) >> 1)) & 3) * 2)) + ((~(((v1035 ^ ((int)((unsigned int)((int)((unsigned int)v1027 >> 2)) >> 1))) | (-(v1035 ^ ((int)((unsigned int)((int)((unsigned int)v1027 >> 2)) >> 1))))) >> 31)) & 1);
      int v1061 = v1060[v1315];
      int * v1062 = v1025->cache_age;
      int v1063 = v1062[v1293];
      int * v1064 = v1025->cache_age;
      int v1318 = v1063 + ((int)((unsigned int)(v1063 - v1061) >> 31));
      v1064[v1293] = v1318;
      int * v1066 = v1025->cache_age;
      int v1067 = v1066[v1295];
      int * v1068 = v1025->cache_age;
      int v1321 = v1067 + ((int)((unsigned int)(v1067 - v1061) >> 31));
      v1068[v1295] = v1321;
      int * v1070 = v1025->cache_age;
      v1070[v1315] = 0;
      v1123 = v1315;
    } else {
      int * v1073 = v1025->cache_age;
      int v1325 = 4 + ((((int)((unsigned int)((int)((unsigned int)v1027 >> 2)) >> 1)) & 3) * 2);
      int v1074 = v1073[v1325];
      int * v1075 = v1025->cache_tags;
      int v1076 = v1075[v1325];
      int * v1077 = v1025->cache_age;
      int v1078 = v1077[v1295];
      int * v1079 = v1025->cache_tags;
      int v1080 = v1079[v1295];
      int * v1081 = v1025->cache_dirty;
      int v1330 = (4 + ((((int)((unsigned int)((int)((unsigned int)v1027 >> 2)) >> 1)) & 3) * 2)) + ((((v1074 + ((~(((v1076 ^ -1) | (-(v1076 ^ -1))) >> 31)) & 2)) - (v1078 + ((~(((v1080 ^ -1) | (-(v1080 ^ -1))) >> 31)) & 2))) >> 31) & 1);
      int v1082 = v1081[v1330];
      bool v1331 = !(v1082 == 0);
      if (v1331) {
        int * v1083 = v1025->cache_tags;
        int v1084 = v1083[v1330];
        int * v1085 = v1025->cache_vals;
        int v1334 = ((4 + ((((int)((unsigned int)((int)((unsigned int)v1027 >> 2)) >> 1)) & 3) * 2)) + ((((v1074 + ((~(((v1076 ^ -1) | (-(v1076 ^ -1))) >> 31)) & 2)) - (v1078 + ((~(((v1080 ^ -1) | (-(v1080 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
        int v1086 = v1085[v1334];
        int * v1087 = v1025->cache_vals;
        int v1336 = (((4 + ((((int)((unsigned int)((int)((unsigned int)v1027 >> 2)) >> 1)) & 3) * 2)) + ((((v1074 + ((~(((v1076 ^ -1) | (-(v1076 ^ -1))) >> 31)) & 2)) - (v1078 + ((~(((v1080 ^ -1) | (-(v1080 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
        int v1088 = v1087[v1336];
        int * v1089 = v1025->mem;
        int v1338 = v1084 * 2;
        v1089[v1338] = v1086;
        int * v1091 = v1025->mem;
        int v1341 = (v1084 * 2) + 1;
        v1091[v1341] = v1088;
        ;
      } else {
        ;
      }
      int * v1096 = v1025->mem;
      int v1346 = ((int)((unsigned int)((int)((unsigned int)v1027 >> 2)) >> 1)) * 2;
      int v1097 = v1096[v1346];
      int * v1098 = v1025->mem;
      int v1348 = (((int)((unsigned int)((int)((unsigned int)v1027 >> 2)) >> 1)) * 2) + 1;
      int v1099 = v1098[v1348];
      int * v1100 = v1025->cache_vals;
      int v1350 = ((4 + ((((int)((unsigned int)((int)((unsigned int)v1027 >> 2)) >> 1)) & 3) * 2)) + ((((v1074 + ((~(((v1076 ^ -1) | (-(v1076 ^ -1))) >> 31)) & 2)) - (v1078 + ((~(((v1080 ^ -1) | (-(v1080 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
      v1100[v1350] = v1097;
      int * v1102 = v1025->cache_vals;
      int v1353 = (((4 + ((((int)((unsigned int)((int)((unsigned int)v1027 >> 2)) >> 1)) & 3) * 2)) + ((((v1074 + ((~(((v1076 ^ -1) | (-(v1076 ^ -1))) >> 31)) & 2)) - (v1078 + ((~(((v1080 ^ -1) | (-(v1080 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
      v1102[v1353] = v1099;
      int * v1104 = v1025->cache_tags;
      int v1356 = (int)((unsigned int)((int)((unsigned int)v1027 >> 2)) >> 1);
      v1104[v1330] = v1356;
      int * v1106 = v1025->cache_dirty;
      v1106[v1330] = 0;
      int * v1108 = v1025->cache_age;
      v1108[v1330] = 1;
      int * v1110 = v1025->cache_age;
      int v1111 = v1110[v1330];
      int * v1112 = v1025->cache_age;
      int v1113 = v1112[v1293];
      int * v1114 = v1025->cache_age;
      int v1364 = v1113 + ((int)((unsigned int)(v1113 - v1111) >> 31));
      v1114[v1293] = v1364;
      int * v1116 = v1025->cache_age;
      int v1117 = v1116[v1295];
      int * v1118 = v1025->cache_age;
      int v1367 = v1117 + ((int)((unsigned int)(v1117 - v1111) >> 31));
      v1118[v1295] = v1367;
      int * v1120 = v1025->cache_age;
      v1120[v1330] = 0;
      v1123 = v1330;
    }
    int * v1124 = v1025->cache_vals;
    int v1370 = v1123 * 2;
    int v1125 = v1124[v1370];
    int * v1126 = v1025->cache_vals;
    int v1372 = (v1123 * 2) + 1;
    int v1127 = v1126[v1372];
    int * v1128 = v1025->cache_vals;
    int v1374 = (((((int)((unsigned int)((int)((unsigned int)v1027 >> 2)) >> 1)) & 1) * 2) + ((((v1053 + ((~(((v1055 ^ -1) | (-(v1055 ^ -1))) >> 31)) & 2)) - (v1057 + ((~(((v1059 ^ -1) | (-(v1059 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
    v1128[v1374] = v1125;
    int * v1130 = v1025->cache_vals;
    int v1377 = ((((((int)((unsigned int)((int)((unsigned int)v1027 >> 2)) >> 1)) & 1) * 2) + ((((v1053 + ((~(((v1055 ^ -1) | (-(v1055 ^ -1))) >> 31)) & 2)) - (v1057 + ((~(((v1059 ^ -1) | (-(v1059 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
    v1130[v1377] = v1127;
    int * v1132 = v1025->cache_tags;
    int v1380 = ((((int)((unsigned int)((int)((unsigned int)v1027 >> 2)) >> 1)) & 1) * 2) + ((((v1053 + ((~(((v1055 ^ -1) | (-(v1055 ^ -1))) >> 31)) & 2)) - (v1057 + ((~(((v1059 ^ -1) | (-(v1059 ^ -1))) >> 31)) & 2))) >> 31) & 1);
    int v1381 = (int)((unsigned int)((int)((unsigned int)v1027 >> 2)) >> 1);
    v1132[v1380] = v1381;
    int * v1134 = v1025->cache_dirty;
    v1134[v1380] = 0;
    int * v1136 = v1025->cache_age;
    v1136[v1380] = 1;
    int * v1138 = v1025->cache_age;
    int v1139 = v1138[v1380];
    int * v1140 = v1025->cache_age;
    int v1141 = v1140[v1289];
    int * v1142 = v1025->cache_age;
    int v1389 = v1141 + ((int)((unsigned int)(v1141 - v1139) >> 31));
    v1142[v1289] = v1389;
    int * v1144 = v1025->cache_age;
    int v1145 = v1144[v1291];
    int * v1146 = v1025->cache_age;
    int v1392 = v1145 + ((int)((unsigned int)(v1145 - v1139) >> 31));
    v1146[v1291] = v1392;
    int * v1148 = v1025->cache_age;
    v1148[v1380] = 0;
    v1151 = v1380;
  }
  int v1395 = (v1151 * 2) + (((int)((unsigned int)v1027 >> 2)) & 1);
  int v1152 = v1038[v1395];
  int * v1153 = v1025->regs;
  v1153[9] = v1152;
  struct StateT2 * v1155 = slot_10(v872);
  return v1155;
}

struct StateT2 * slot_11(struct StateT2 * v1469) {
  struct StateT * v1470 = v1469->a;
  int v1471 = v1470->timer;
  struct StateT * v1472 = v1469->b;
  int v1473 = v1472->timer;
  bool v1510 = v1471 == v1473;
  squared_assert(v1510);
  squared_assume(v1510);
  struct StateT * v1476 = v1469->a;
  int * v1477 = v1476->saved_regs;
  int * v1478 = v1476->regs;
  int v1479 = v1478[5];
  v1477[5] = v1479;
  struct StateT * v1481 = v1469->b;
  int * v1482 = v1481->saved_regs;
  int * v1483 = v1481->regs;
  int v1484 = v1483[5];
  v1482[5] = v1484;
  struct StateT * v1486 = v1469->a;
  int v1487 = v1486->timer;
  int v1521 = v1487 + 1;
  v1486->timer = v1521;
  struct StateT * v1489 = v1469->b;
  int v1490 = v1489->timer;
  int v1523 = v1490 + 1;
  v1489->timer = v1523;
  struct StateT * v1492 = v1469->a;
  int * v1493 = v1492->regs;
  int v1494 = v1493[5];
  int * v1495 = v1492->regs;
  int v1496 = v1495[16];
  int * v1497 = v1492->regs;
  int v1529 = v1494 | v1496;
  v1497[5] = v1529;
  struct StateT * v1499 = v1469->b;
  int * v1500 = v1499->regs;
  int v1501 = v1500[5];
  int * v1502 = v1499->regs;
  int v1503 = v1502[16];
  int * v1504 = v1499->regs;
  int v1534 = v1501 | v1503;
  v1504[5] = v1534;
  struct StateT2 * v1506 = slot_12(v1469);
  return v1506;
}

struct StateT2 * slot_0(struct StateT2 * v2) {
  struct StateT * v3 = v2->a;
  int v4 = v3->timer;
  struct StateT * v5 = v2->b;
  int v6 = v5->timer;
  bool v25 = v4 == v6;
  squared_assert(v25);
  squared_assume(v25);
  struct StateT * v9 = v2->a;
  int v10 = v9->timer;
  int v27 = v10 + 1;
  v9->timer = v27;
  struct StateT * v12 = v2->b;
  int v13 = v12->timer;
  int v29 = v13 + 1;
  v12->timer = v29;
  struct StateT * v15 = v2->a;
  int * v16 = v15->regs;
  v16[12] = 0;
  struct StateT * v18 = v2->b;
  int * v19 = v18->regs;
  v19[12] = 0;
  struct StateT2 * v21 = slot_1(v2);
  return v21;
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

void squared_assert(bool c) { koika_assert(c, "squared drift"); }
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
    s1.mem[SECRET_OFFSET+i] = bounded(0, 20);
    s2.mem[SECRET_OFFSET+i] = bounded(0, 20);
  }
  struct StateT2 p = { .a = &s1, .b = &s2 };
  struct StateT2 *p_ = snippet(&p);
  koika_assert(p_->a->timer==p_->b->timer, "timing leak");
  return 0;
}