// verify: leak (KLEE should report a failing assertion) [budget 1200s]
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
struct StateT * slot_1(struct StateT * v15);
struct StateT * slot_8(struct StateT * v1516);
struct StateT * slot_6(struct StateT * v1250);
struct StateT * slot_5(struct StateT * v1237);
struct StateT * slot_4(struct StateT * v291);
struct StateT * slot_2(struct StateT * v265);
struct StateT * slot_7(struct StateT * v1266);
struct StateT * slot_3(struct StateT * v278);
struct StateT * slot_0(struct StateT * v2);
struct StateT * snippet(struct StateT * v0) {
  struct StateT * v1 = slot_0(v0);
  return v1;
}

struct StateT * slot_1(struct StateT * v15) {
  int v16 = v15->timer;
  int v149 = v16 + 1;
  v15->timer = v149;
  int * v18 = v15->regs;
  int v19 = v18[6];
  int * v20 = v15->cache_tags;
  int v153 = (((int)((unsigned int)((int)((unsigned int)v19 >> 2)) >> 1)) & 1) * 2;
  int v21 = v20[v153];
  int * v22 = v15->cache_tags;
  int v155 = ((((int)((unsigned int)((int)((unsigned int)v19 >> 2)) >> 1)) & 1) * 2) + 1;
  int v23 = v22[v155];
  int * v24 = v15->cache_tags;
  int v157 = 4 + ((((int)((unsigned int)((int)((unsigned int)v19 >> 2)) >> 1)) & 3) * 2);
  int v25 = v24[v157];
  int * v26 = v15->cache_tags;
  int v159 = (4 + ((((int)((unsigned int)((int)((unsigned int)v19 >> 2)) >> 1)) & 3) * 2)) + 1;
  int v27 = v26[v159];
  int v28 = v15->timer;
  int v160 = v28 + ((100 ^ (((~(((v25 ^ ((int)((unsigned int)((int)((unsigned int)v19 >> 2)) >> 1))) | (-(v25 ^ ((int)((unsigned int)((int)((unsigned int)v19 >> 2)) >> 1))))) >> 31)) | (~(((v27 ^ ((int)((unsigned int)((int)((unsigned int)v19 >> 2)) >> 1))) | (-(v27 ^ ((int)((unsigned int)((int)((unsigned int)v19 >> 2)) >> 1))))) >> 31))) & 104)) ^ (((~(((v21 ^ ((int)((unsigned int)((int)((unsigned int)v19 >> 2)) >> 1))) | (-(v21 ^ ((int)((unsigned int)((int)((unsigned int)v19 >> 2)) >> 1))))) >> 31)) | (~(((v23 ^ ((int)((unsigned int)((int)((unsigned int)v19 >> 2)) >> 1))) | (-(v23 ^ ((int)((unsigned int)((int)((unsigned int)v19 >> 2)) >> 1))))) >> 31))) & (1 ^ (100 ^ (((~(((v25 ^ ((int)((unsigned int)((int)((unsigned int)v19 >> 2)) >> 1))) | (-(v25 ^ ((int)((unsigned int)((int)((unsigned int)v19 >> 2)) >> 1))))) >> 31)) | (~(((v27 ^ ((int)((unsigned int)((int)((unsigned int)v19 >> 2)) >> 1))) | (-(v27 ^ ((int)((unsigned int)((int)((unsigned int)v19 >> 2)) >> 1))))) >> 31))) & 104)))));
  v15->timer = v160;
  int * v30 = v15->cache_vals;
  bool v161 = !(((~(((v21 ^ ((int)((unsigned int)((int)((unsigned int)v19 >> 2)) >> 1))) | (-(v21 ^ ((int)((unsigned int)((int)((unsigned int)v19 >> 2)) >> 1))))) >> 31)) | (~(((v23 ^ ((int)((unsigned int)((int)((unsigned int)v19 >> 2)) >> 1))) | (-(v23 ^ ((int)((unsigned int)((int)((unsigned int)v19 >> 2)) >> 1))))) >> 31))) == 0);
  int v143;
  if (v161) {
    int * v31 = v15->cache_age;
    int v163 = ((((int)((unsigned int)((int)((unsigned int)v19 >> 2)) >> 1)) & 1) * 2) + ((~(((v23 ^ ((int)((unsigned int)((int)((unsigned int)v19 >> 2)) >> 1))) | (-(v23 ^ ((int)((unsigned int)((int)((unsigned int)v19 >> 2)) >> 1))))) >> 31)) & 1);
    int v32 = v31[v163];
    int * v33 = v15->cache_age;
    int v34 = v33[v153];
    int * v35 = v15->cache_age;
    int v166 = v34 + ((int)((unsigned int)(v34 - v32) >> 31));
    v35[v153] = v166;
    int * v37 = v15->cache_age;
    int v38 = v37[v155];
    int * v39 = v15->cache_age;
    int v169 = v38 + ((int)((unsigned int)(v38 - v32) >> 31));
    v39[v155] = v169;
    int * v41 = v15->cache_age;
    v41[v163] = 0;
    v143 = v163;
  } else {
    int * v44 = v15->cache_age;
    int v173 = (((int)((unsigned int)((int)((unsigned int)v19 >> 2)) >> 1)) & 1) * 2;
    int v45 = v44[v173];
    int * v46 = v15->cache_tags;
    int v47 = v46[v173];
    int * v48 = v15->cache_age;
    int v49 = v48[v155];
    int * v50 = v15->cache_tags;
    int v51 = v50[v155];
    bool v177 = !(((~(((v25 ^ ((int)((unsigned int)((int)((unsigned int)v19 >> 2)) >> 1))) | (-(v25 ^ ((int)((unsigned int)((int)((unsigned int)v19 >> 2)) >> 1))))) >> 31)) | (~(((v27 ^ ((int)((unsigned int)((int)((unsigned int)v19 >> 2)) >> 1))) | (-(v27 ^ ((int)((unsigned int)((int)((unsigned int)v19 >> 2)) >> 1))))) >> 31))) == 0);
    int v115;
    if (v177) {
      int * v52 = v15->cache_age;
      int v179 = (4 + ((((int)((unsigned int)((int)((unsigned int)v19 >> 2)) >> 1)) & 3) * 2)) + ((~(((v27 ^ ((int)((unsigned int)((int)((unsigned int)v19 >> 2)) >> 1))) | (-(v27 ^ ((int)((unsigned int)((int)((unsigned int)v19 >> 2)) >> 1))))) >> 31)) & 1);
      int v53 = v52[v179];
      int * v54 = v15->cache_age;
      int v55 = v54[v157];
      int * v56 = v15->cache_age;
      int v182 = v55 + ((int)((unsigned int)(v55 - v53) >> 31));
      v56[v157] = v182;
      int * v58 = v15->cache_age;
      int v59 = v58[v159];
      int * v60 = v15->cache_age;
      int v185 = v59 + ((int)((unsigned int)(v59 - v53) >> 31));
      v60[v159] = v185;
      int * v62 = v15->cache_age;
      v62[v179] = 0;
      v115 = v179;
    } else {
      int * v65 = v15->cache_age;
      int v189 = 4 + ((((int)((unsigned int)((int)((unsigned int)v19 >> 2)) >> 1)) & 3) * 2);
      int v66 = v65[v189];
      int * v67 = v15->cache_tags;
      int v68 = v67[v189];
      int * v69 = v15->cache_age;
      int v70 = v69[v159];
      int * v71 = v15->cache_tags;
      int v72 = v71[v159];
      int * v73 = v15->cache_dirty;
      int v194 = (4 + ((((int)((unsigned int)((int)((unsigned int)v19 >> 2)) >> 1)) & 3) * 2)) + ((((v66 + ((~(((v68 ^ -1) | (-(v68 ^ -1))) >> 31)) & 2)) - (v70 + ((~(((v72 ^ -1) | (-(v72 ^ -1))) >> 31)) & 2))) >> 31) & 1);
      int v74 = v73[v194];
      bool v195 = !(v74 == 0);
      if (v195) {
        int * v75 = v15->cache_tags;
        int v76 = v75[v194];
        int * v77 = v15->cache_vals;
        int v198 = ((4 + ((((int)((unsigned int)((int)((unsigned int)v19 >> 2)) >> 1)) & 3) * 2)) + ((((v66 + ((~(((v68 ^ -1) | (-(v68 ^ -1))) >> 31)) & 2)) - (v70 + ((~(((v72 ^ -1) | (-(v72 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
        int v78 = v77[v198];
        int * v79 = v15->cache_vals;
        int v200 = (((4 + ((((int)((unsigned int)((int)((unsigned int)v19 >> 2)) >> 1)) & 3) * 2)) + ((((v66 + ((~(((v68 ^ -1) | (-(v68 ^ -1))) >> 31)) & 2)) - (v70 + ((~(((v72 ^ -1) | (-(v72 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
        int v80 = v79[v200];
        int * v81 = v15->mem;
        int v202 = v76 * 2;
        v81[v202] = v78;
        int * v83 = v15->mem;
        int v205 = (v76 * 2) + 1;
        v83[v205] = v80;
        ;
      } else {
        ;
      }
      int * v88 = v15->mem;
      int v210 = ((int)((unsigned int)((int)((unsigned int)v19 >> 2)) >> 1)) * 2;
      int v89 = v88[v210];
      int * v90 = v15->mem;
      int v212 = (((int)((unsigned int)((int)((unsigned int)v19 >> 2)) >> 1)) * 2) + 1;
      int v91 = v90[v212];
      int * v92 = v15->cache_vals;
      int v214 = ((4 + ((((int)((unsigned int)((int)((unsigned int)v19 >> 2)) >> 1)) & 3) * 2)) + ((((v66 + ((~(((v68 ^ -1) | (-(v68 ^ -1))) >> 31)) & 2)) - (v70 + ((~(((v72 ^ -1) | (-(v72 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
      v92[v214] = v89;
      int * v94 = v15->cache_vals;
      int v217 = (((4 + ((((int)((unsigned int)((int)((unsigned int)v19 >> 2)) >> 1)) & 3) * 2)) + ((((v66 + ((~(((v68 ^ -1) | (-(v68 ^ -1))) >> 31)) & 2)) - (v70 + ((~(((v72 ^ -1) | (-(v72 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
      v94[v217] = v91;
      int * v96 = v15->cache_tags;
      int v220 = (int)((unsigned int)((int)((unsigned int)v19 >> 2)) >> 1);
      v96[v194] = v220;
      int * v98 = v15->cache_dirty;
      v98[v194] = 0;
      int * v100 = v15->cache_age;
      v100[v194] = 1;
      int * v102 = v15->cache_age;
      int v103 = v102[v194];
      int * v104 = v15->cache_age;
      int v105 = v104[v157];
      int * v106 = v15->cache_age;
      int v228 = v105 + ((int)((unsigned int)(v105 - v103) >> 31));
      v106[v157] = v228;
      int * v108 = v15->cache_age;
      int v109 = v108[v159];
      int * v110 = v15->cache_age;
      int v231 = v109 + ((int)((unsigned int)(v109 - v103) >> 31));
      v110[v159] = v231;
      int * v112 = v15->cache_age;
      v112[v194] = 0;
      v115 = v194;
    }
    int * v116 = v15->cache_vals;
    int v234 = v115 * 2;
    int v117 = v116[v234];
    int * v118 = v15->cache_vals;
    int v236 = (v115 * 2) + 1;
    int v119 = v118[v236];
    int * v120 = v15->cache_vals;
    int v238 = (((((int)((unsigned int)((int)((unsigned int)v19 >> 2)) >> 1)) & 1) * 2) + ((((v45 + ((~(((v47 ^ -1) | (-(v47 ^ -1))) >> 31)) & 2)) - (v49 + ((~(((v51 ^ -1) | (-(v51 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
    v120[v238] = v117;
    int * v122 = v15->cache_vals;
    int v241 = ((((((int)((unsigned int)((int)((unsigned int)v19 >> 2)) >> 1)) & 1) * 2) + ((((v45 + ((~(((v47 ^ -1) | (-(v47 ^ -1))) >> 31)) & 2)) - (v49 + ((~(((v51 ^ -1) | (-(v51 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
    v122[v241] = v119;
    int * v124 = v15->cache_tags;
    int v244 = ((((int)((unsigned int)((int)((unsigned int)v19 >> 2)) >> 1)) & 1) * 2) + ((((v45 + ((~(((v47 ^ -1) | (-(v47 ^ -1))) >> 31)) & 2)) - (v49 + ((~(((v51 ^ -1) | (-(v51 ^ -1))) >> 31)) & 2))) >> 31) & 1);
    int v245 = (int)((unsigned int)((int)((unsigned int)v19 >> 2)) >> 1);
    v124[v244] = v245;
    int * v126 = v15->cache_dirty;
    v126[v244] = 0;
    int * v128 = v15->cache_age;
    v128[v244] = 1;
    int * v130 = v15->cache_age;
    int v131 = v130[v244];
    int * v132 = v15->cache_age;
    int v133 = v132[v153];
    int * v134 = v15->cache_age;
    int v253 = v133 + ((int)((unsigned int)(v133 - v131) >> 31));
    v134[v153] = v253;
    int * v136 = v15->cache_age;
    int v137 = v136[v155];
    int * v138 = v15->cache_age;
    int v256 = v137 + ((int)((unsigned int)(v137 - v131) >> 31));
    v138[v155] = v256;
    int * v140 = v15->cache_age;
    v140[v244] = 0;
    v143 = v244;
  }
  int v259 = (v143 * 2) + (((int)((unsigned int)v19 >> 2)) & 1);
  int v144 = v30[v259];
  int * v145 = v15->regs;
  v145[5] = v144;
  struct StateT * v147 = slot_2(v15);
  return v147;
}

struct StateT * slot_8(struct StateT * v1516) {
  int v1517 = v1516->timer;
  int v1649 = v1517 + 1;
  v1516->timer = v1649;
  int * v1519 = v1516->regs;
  int v1520 = v1519[11];
  int * v1521 = v1516->cache_tags;
  int v1653 = (((int)((unsigned int)((int)((unsigned int)v1520 >> 2)) >> 1)) & 1) * 2;
  int v1522 = v1521[v1653];
  int * v1523 = v1516->cache_tags;
  int v1655 = ((((int)((unsigned int)((int)((unsigned int)v1520 >> 2)) >> 1)) & 1) * 2) + 1;
  int v1524 = v1523[v1655];
  int * v1525 = v1516->cache_tags;
  int v1657 = 4 + ((((int)((unsigned int)((int)((unsigned int)v1520 >> 2)) >> 1)) & 3) * 2);
  int v1526 = v1525[v1657];
  int * v1527 = v1516->cache_tags;
  int v1659 = (4 + ((((int)((unsigned int)((int)((unsigned int)v1520 >> 2)) >> 1)) & 3) * 2)) + 1;
  int v1528 = v1527[v1659];
  int v1529 = v1516->timer;
  int v1660 = v1529 + ((100 ^ (((~(((v1526 ^ ((int)((unsigned int)((int)((unsigned int)v1520 >> 2)) >> 1))) | (-(v1526 ^ ((int)((unsigned int)((int)((unsigned int)v1520 >> 2)) >> 1))))) >> 31)) | (~(((v1528 ^ ((int)((unsigned int)((int)((unsigned int)v1520 >> 2)) >> 1))) | (-(v1528 ^ ((int)((unsigned int)((int)((unsigned int)v1520 >> 2)) >> 1))))) >> 31))) & 104)) ^ (((~(((v1522 ^ ((int)((unsigned int)((int)((unsigned int)v1520 >> 2)) >> 1))) | (-(v1522 ^ ((int)((unsigned int)((int)((unsigned int)v1520 >> 2)) >> 1))))) >> 31)) | (~(((v1524 ^ ((int)((unsigned int)((int)((unsigned int)v1520 >> 2)) >> 1))) | (-(v1524 ^ ((int)((unsigned int)((int)((unsigned int)v1520 >> 2)) >> 1))))) >> 31))) & (1 ^ (100 ^ (((~(((v1526 ^ ((int)((unsigned int)((int)((unsigned int)v1520 >> 2)) >> 1))) | (-(v1526 ^ ((int)((unsigned int)((int)((unsigned int)v1520 >> 2)) >> 1))))) >> 31)) | (~(((v1528 ^ ((int)((unsigned int)((int)((unsigned int)v1520 >> 2)) >> 1))) | (-(v1528 ^ ((int)((unsigned int)((int)((unsigned int)v1520 >> 2)) >> 1))))) >> 31))) & 104)))));
  v1516->timer = v1660;
  int * v1531 = v1516->cache_vals;
  bool v1661 = !(((~(((v1522 ^ ((int)((unsigned int)((int)((unsigned int)v1520 >> 2)) >> 1))) | (-(v1522 ^ ((int)((unsigned int)((int)((unsigned int)v1520 >> 2)) >> 1))))) >> 31)) | (~(((v1524 ^ ((int)((unsigned int)((int)((unsigned int)v1520 >> 2)) >> 1))) | (-(v1524 ^ ((int)((unsigned int)((int)((unsigned int)v1520 >> 2)) >> 1))))) >> 31))) == 0);
  int v1644;
  if (v1661) {
    int * v1532 = v1516->cache_age;
    int v1663 = ((((int)((unsigned int)((int)((unsigned int)v1520 >> 2)) >> 1)) & 1) * 2) + ((~(((v1524 ^ ((int)((unsigned int)((int)((unsigned int)v1520 >> 2)) >> 1))) | (-(v1524 ^ ((int)((unsigned int)((int)((unsigned int)v1520 >> 2)) >> 1))))) >> 31)) & 1);
    int v1533 = v1532[v1663];
    int * v1534 = v1516->cache_age;
    int v1535 = v1534[v1653];
    int * v1536 = v1516->cache_age;
    int v1666 = v1535 + ((int)((unsigned int)(v1535 - v1533) >> 31));
    v1536[v1653] = v1666;
    int * v1538 = v1516->cache_age;
    int v1539 = v1538[v1655];
    int * v1540 = v1516->cache_age;
    int v1669 = v1539 + ((int)((unsigned int)(v1539 - v1533) >> 31));
    v1540[v1655] = v1669;
    int * v1542 = v1516->cache_age;
    v1542[v1663] = 0;
    v1644 = v1663;
  } else {
    int * v1545 = v1516->cache_age;
    int v1673 = (((int)((unsigned int)((int)((unsigned int)v1520 >> 2)) >> 1)) & 1) * 2;
    int v1546 = v1545[v1673];
    int * v1547 = v1516->cache_tags;
    int v1548 = v1547[v1673];
    int * v1549 = v1516->cache_age;
    int v1550 = v1549[v1655];
    int * v1551 = v1516->cache_tags;
    int v1552 = v1551[v1655];
    bool v1677 = !(((~(((v1526 ^ ((int)((unsigned int)((int)((unsigned int)v1520 >> 2)) >> 1))) | (-(v1526 ^ ((int)((unsigned int)((int)((unsigned int)v1520 >> 2)) >> 1))))) >> 31)) | (~(((v1528 ^ ((int)((unsigned int)((int)((unsigned int)v1520 >> 2)) >> 1))) | (-(v1528 ^ ((int)((unsigned int)((int)((unsigned int)v1520 >> 2)) >> 1))))) >> 31))) == 0);
    int v1616;
    if (v1677) {
      int * v1553 = v1516->cache_age;
      int v1679 = (4 + ((((int)((unsigned int)((int)((unsigned int)v1520 >> 2)) >> 1)) & 3) * 2)) + ((~(((v1528 ^ ((int)((unsigned int)((int)((unsigned int)v1520 >> 2)) >> 1))) | (-(v1528 ^ ((int)((unsigned int)((int)((unsigned int)v1520 >> 2)) >> 1))))) >> 31)) & 1);
      int v1554 = v1553[v1679];
      int * v1555 = v1516->cache_age;
      int v1556 = v1555[v1657];
      int * v1557 = v1516->cache_age;
      int v1682 = v1556 + ((int)((unsigned int)(v1556 - v1554) >> 31));
      v1557[v1657] = v1682;
      int * v1559 = v1516->cache_age;
      int v1560 = v1559[v1659];
      int * v1561 = v1516->cache_age;
      int v1685 = v1560 + ((int)((unsigned int)(v1560 - v1554) >> 31));
      v1561[v1659] = v1685;
      int * v1563 = v1516->cache_age;
      v1563[v1679] = 0;
      v1616 = v1679;
    } else {
      int * v1566 = v1516->cache_age;
      int v1689 = 4 + ((((int)((unsigned int)((int)((unsigned int)v1520 >> 2)) >> 1)) & 3) * 2);
      int v1567 = v1566[v1689];
      int * v1568 = v1516->cache_tags;
      int v1569 = v1568[v1689];
      int * v1570 = v1516->cache_age;
      int v1571 = v1570[v1659];
      int * v1572 = v1516->cache_tags;
      int v1573 = v1572[v1659];
      int * v1574 = v1516->cache_dirty;
      int v1694 = (4 + ((((int)((unsigned int)((int)((unsigned int)v1520 >> 2)) >> 1)) & 3) * 2)) + ((((v1567 + ((~(((v1569 ^ -1) | (-(v1569 ^ -1))) >> 31)) & 2)) - (v1571 + ((~(((v1573 ^ -1) | (-(v1573 ^ -1))) >> 31)) & 2))) >> 31) & 1);
      int v1575 = v1574[v1694];
      bool v1695 = !(v1575 == 0);
      if (v1695) {
        int * v1576 = v1516->cache_tags;
        int v1577 = v1576[v1694];
        int * v1578 = v1516->cache_vals;
        int v1698 = ((4 + ((((int)((unsigned int)((int)((unsigned int)v1520 >> 2)) >> 1)) & 3) * 2)) + ((((v1567 + ((~(((v1569 ^ -1) | (-(v1569 ^ -1))) >> 31)) & 2)) - (v1571 + ((~(((v1573 ^ -1) | (-(v1573 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
        int v1579 = v1578[v1698];
        int * v1580 = v1516->cache_vals;
        int v1700 = (((4 + ((((int)((unsigned int)((int)((unsigned int)v1520 >> 2)) >> 1)) & 3) * 2)) + ((((v1567 + ((~(((v1569 ^ -1) | (-(v1569 ^ -1))) >> 31)) & 2)) - (v1571 + ((~(((v1573 ^ -1) | (-(v1573 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
        int v1581 = v1580[v1700];
        int * v1582 = v1516->mem;
        int v1702 = v1577 * 2;
        v1582[v1702] = v1579;
        int * v1584 = v1516->mem;
        int v1705 = (v1577 * 2) + 1;
        v1584[v1705] = v1581;
        ;
      } else {
        ;
      }
      int * v1589 = v1516->mem;
      int v1710 = ((int)((unsigned int)((int)((unsigned int)v1520 >> 2)) >> 1)) * 2;
      int v1590 = v1589[v1710];
      int * v1591 = v1516->mem;
      int v1712 = (((int)((unsigned int)((int)((unsigned int)v1520 >> 2)) >> 1)) * 2) + 1;
      int v1592 = v1591[v1712];
      int * v1593 = v1516->cache_vals;
      int v1714 = ((4 + ((((int)((unsigned int)((int)((unsigned int)v1520 >> 2)) >> 1)) & 3) * 2)) + ((((v1567 + ((~(((v1569 ^ -1) | (-(v1569 ^ -1))) >> 31)) & 2)) - (v1571 + ((~(((v1573 ^ -1) | (-(v1573 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
      v1593[v1714] = v1590;
      int * v1595 = v1516->cache_vals;
      int v1717 = (((4 + ((((int)((unsigned int)((int)((unsigned int)v1520 >> 2)) >> 1)) & 3) * 2)) + ((((v1567 + ((~(((v1569 ^ -1) | (-(v1569 ^ -1))) >> 31)) & 2)) - (v1571 + ((~(((v1573 ^ -1) | (-(v1573 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
      v1595[v1717] = v1592;
      int * v1597 = v1516->cache_tags;
      int v1720 = (int)((unsigned int)((int)((unsigned int)v1520 >> 2)) >> 1);
      v1597[v1694] = v1720;
      int * v1599 = v1516->cache_dirty;
      v1599[v1694] = 0;
      int * v1601 = v1516->cache_age;
      v1601[v1694] = 1;
      int * v1603 = v1516->cache_age;
      int v1604 = v1603[v1694];
      int * v1605 = v1516->cache_age;
      int v1606 = v1605[v1657];
      int * v1607 = v1516->cache_age;
      int v1728 = v1606 + ((int)((unsigned int)(v1606 - v1604) >> 31));
      v1607[v1657] = v1728;
      int * v1609 = v1516->cache_age;
      int v1610 = v1609[v1659];
      int * v1611 = v1516->cache_age;
      int v1731 = v1610 + ((int)((unsigned int)(v1610 - v1604) >> 31));
      v1611[v1659] = v1731;
      int * v1613 = v1516->cache_age;
      v1613[v1694] = 0;
      v1616 = v1694;
    }
    int * v1617 = v1516->cache_vals;
    int v1734 = v1616 * 2;
    int v1618 = v1617[v1734];
    int * v1619 = v1516->cache_vals;
    int v1736 = (v1616 * 2) + 1;
    int v1620 = v1619[v1736];
    int * v1621 = v1516->cache_vals;
    int v1738 = (((((int)((unsigned int)((int)((unsigned int)v1520 >> 2)) >> 1)) & 1) * 2) + ((((v1546 + ((~(((v1548 ^ -1) | (-(v1548 ^ -1))) >> 31)) & 2)) - (v1550 + ((~(((v1552 ^ -1) | (-(v1552 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
    v1621[v1738] = v1618;
    int * v1623 = v1516->cache_vals;
    int v1741 = ((((((int)((unsigned int)((int)((unsigned int)v1520 >> 2)) >> 1)) & 1) * 2) + ((((v1546 + ((~(((v1548 ^ -1) | (-(v1548 ^ -1))) >> 31)) & 2)) - (v1550 + ((~(((v1552 ^ -1) | (-(v1552 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
    v1623[v1741] = v1620;
    int * v1625 = v1516->cache_tags;
    int v1744 = ((((int)((unsigned int)((int)((unsigned int)v1520 >> 2)) >> 1)) & 1) * 2) + ((((v1546 + ((~(((v1548 ^ -1) | (-(v1548 ^ -1))) >> 31)) & 2)) - (v1550 + ((~(((v1552 ^ -1) | (-(v1552 ^ -1))) >> 31)) & 2))) >> 31) & 1);
    int v1745 = (int)((unsigned int)((int)((unsigned int)v1520 >> 2)) >> 1);
    v1625[v1744] = v1745;
    int * v1627 = v1516->cache_dirty;
    v1627[v1744] = 0;
    int * v1629 = v1516->cache_age;
    v1629[v1744] = 1;
    int * v1631 = v1516->cache_age;
    int v1632 = v1631[v1744];
    int * v1633 = v1516->cache_age;
    int v1634 = v1633[v1653];
    int * v1635 = v1516->cache_age;
    int v1753 = v1634 + ((int)((unsigned int)(v1634 - v1632) >> 31));
    v1635[v1653] = v1753;
    int * v1637 = v1516->cache_age;
    int v1638 = v1637[v1655];
    int * v1639 = v1516->cache_age;
    int v1756 = v1638 + ((int)((unsigned int)(v1638 - v1632) >> 31));
    v1639[v1655] = v1756;
    int * v1641 = v1516->cache_age;
    v1641[v1744] = 0;
    v1644 = v1744;
  }
  int v1759 = (v1644 * 2) + (((int)((unsigned int)v1520 >> 2)) & 1);
  int v1645 = v1531[v1759];
  int * v1646 = v1516->regs;
  v1646[12] = v1645;
  return v1516;
}

struct StateT * slot_6(struct StateT * v1250) {
  int v1251 = v1250->timer;
  int v1259 = v1251 + 1;
  v1250->timer = v1259;
  int * v1253 = v1250->regs;
  int v1254 = v1253[7];
  int * v1255 = v1250->regs;
  int v1263 = v1254 + 1;
  v1255[7] = v1263;
  struct StateT * v1257 = slot_7(v1250);
  return v1257;
}

struct StateT * slot_5(struct StateT * v1237) {
  int v1238 = v1237->timer;
  int v1244 = v1238 + 1;
  v1237->timer = v1244;
  int * v1240 = v1237->regs;
  v1240[7] = 0;
  struct StateT * v1242 = slot_6(v1237);
  return v1242;
}

struct StateT * slot_4(struct StateT * v291) {
  int v292 = v291->timer;
  int v808 = v292 + 1;
  v291->timer = v808;
  int * v294 = v291->regs;
  int v295 = v294[8];
  int * v296 = v291->regs;
  int v297 = v296[5];
  int * v298 = v291->saved_regs;
  int * v299 = v291->regs;
  int v300 = v299[7];
  v298[7] = v300;
  int v302 = v291->timer;
  int v817 = v302 + 1;
  v291->timer = v817;
  int * v304 = v291->regs;
  v304[7] = 0;
  int v306 = v291->timer;
  int v820 = v306 + 1;
  v291->timer = v820;
  int * v308 = v291->regs;
  int v309 = v308[7];
  int * v310 = v291->regs;
  int v823 = v309 + 1;
  v310[7] = v823;
  int * v312 = v291->saved_regs;
  int * v313 = v291->regs;
  int v314 = v313[11];
  v312[11] = v314;
  int v316 = v291->timer;
  int v828 = v316 + 1;
  v291->timer = v828;
  int * v318 = v291->regs;
  int v319 = v318[9];
  bool v831 = (((int)((unsigned int)v295 >> 2)) & 3) == (((int)((unsigned int)v319 >> 2)) & 3);
  int v449;
  if (v831) {
    int v320 = v291->timer;
    int v832 = v320 + 1;
    v291->timer = v832;
    v449 = v297;
  } else {
    int * v323 = v291->cache_tags;
    int v835 = (((int)((unsigned int)((int)((unsigned int)v319 >> 2)) >> 1)) & 1) * 2;
    int v324 = v323[v835];
    int * v325 = v291->cache_tags;
    int v837 = ((((int)((unsigned int)((int)((unsigned int)v319 >> 2)) >> 1)) & 1) * 2) + 1;
    int v326 = v325[v837];
    int * v327 = v291->cache_tags;
    int v839 = 4 + ((((int)((unsigned int)((int)((unsigned int)v319 >> 2)) >> 1)) & 3) * 2);
    int v328 = v327[v839];
    int * v329 = v291->cache_tags;
    int v841 = (4 + ((((int)((unsigned int)((int)((unsigned int)v319 >> 2)) >> 1)) & 3) * 2)) + 1;
    int v330 = v329[v841];
    int v331 = v291->timer;
    int v842 = v331 + ((100 ^ (((~(((v328 ^ ((int)((unsigned int)((int)((unsigned int)v319 >> 2)) >> 1))) | (-(v328 ^ ((int)((unsigned int)((int)((unsigned int)v319 >> 2)) >> 1))))) >> 31)) | (~(((v330 ^ ((int)((unsigned int)((int)((unsigned int)v319 >> 2)) >> 1))) | (-(v330 ^ ((int)((unsigned int)((int)((unsigned int)v319 >> 2)) >> 1))))) >> 31))) & 104)) ^ (((~(((v324 ^ ((int)((unsigned int)((int)((unsigned int)v319 >> 2)) >> 1))) | (-(v324 ^ ((int)((unsigned int)((int)((unsigned int)v319 >> 2)) >> 1))))) >> 31)) | (~(((v326 ^ ((int)((unsigned int)((int)((unsigned int)v319 >> 2)) >> 1))) | (-(v326 ^ ((int)((unsigned int)((int)((unsigned int)v319 >> 2)) >> 1))))) >> 31))) & (1 ^ (100 ^ (((~(((v328 ^ ((int)((unsigned int)((int)((unsigned int)v319 >> 2)) >> 1))) | (-(v328 ^ ((int)((unsigned int)((int)((unsigned int)v319 >> 2)) >> 1))))) >> 31)) | (~(((v330 ^ ((int)((unsigned int)((int)((unsigned int)v319 >> 2)) >> 1))) | (-(v330 ^ ((int)((unsigned int)((int)((unsigned int)v319 >> 2)) >> 1))))) >> 31))) & 104)))));
    v291->timer = v842;
    int * v333 = v291->cache_vals;
    bool v843 = !(((~(((v324 ^ ((int)((unsigned int)((int)((unsigned int)v319 >> 2)) >> 1))) | (-(v324 ^ ((int)((unsigned int)((int)((unsigned int)v319 >> 2)) >> 1))))) >> 31)) | (~(((v326 ^ ((int)((unsigned int)((int)((unsigned int)v319 >> 2)) >> 1))) | (-(v326 ^ ((int)((unsigned int)((int)((unsigned int)v319 >> 2)) >> 1))))) >> 31))) == 0);
    int v446;
    if (v843) {
      int * v334 = v291->cache_age;
      int v845 = ((((int)((unsigned int)((int)((unsigned int)v319 >> 2)) >> 1)) & 1) * 2) + ((~(((v326 ^ ((int)((unsigned int)((int)((unsigned int)v319 >> 2)) >> 1))) | (-(v326 ^ ((int)((unsigned int)((int)((unsigned int)v319 >> 2)) >> 1))))) >> 31)) & 1);
      int v335 = v334[v845];
      int * v336 = v291->cache_age;
      int v337 = v336[v835];
      int * v338 = v291->cache_age;
      int v848 = v337 + ((int)((unsigned int)(v337 - v335) >> 31));
      v338[v835] = v848;
      int * v340 = v291->cache_age;
      int v341 = v340[v837];
      int * v342 = v291->cache_age;
      int v851 = v341 + ((int)((unsigned int)(v341 - v335) >> 31));
      v342[v837] = v851;
      int * v344 = v291->cache_age;
      v344[v845] = 0;
      v446 = v845;
    } else {
      int * v347 = v291->cache_age;
      int v854 = (((int)((unsigned int)((int)((unsigned int)v319 >> 2)) >> 1)) & 1) * 2;
      int v348 = v347[v854];
      int * v349 = v291->cache_tags;
      int v350 = v349[v854];
      int * v351 = v291->cache_age;
      int v352 = v351[v837];
      int * v353 = v291->cache_tags;
      int v354 = v353[v837];
      bool v858 = !(((~(((v328 ^ ((int)((unsigned int)((int)((unsigned int)v319 >> 2)) >> 1))) | (-(v328 ^ ((int)((unsigned int)((int)((unsigned int)v319 >> 2)) >> 1))))) >> 31)) | (~(((v330 ^ ((int)((unsigned int)((int)((unsigned int)v319 >> 2)) >> 1))) | (-(v330 ^ ((int)((unsigned int)((int)((unsigned int)v319 >> 2)) >> 1))))) >> 31))) == 0);
      int v418;
      if (v858) {
        int * v355 = v291->cache_age;
        int v860 = (4 + ((((int)((unsigned int)((int)((unsigned int)v319 >> 2)) >> 1)) & 3) * 2)) + ((~(((v330 ^ ((int)((unsigned int)((int)((unsigned int)v319 >> 2)) >> 1))) | (-(v330 ^ ((int)((unsigned int)((int)((unsigned int)v319 >> 2)) >> 1))))) >> 31)) & 1);
        int v356 = v355[v860];
        int * v357 = v291->cache_age;
        int v358 = v357[v839];
        int * v359 = v291->cache_age;
        int v863 = v358 + ((int)((unsigned int)(v358 - v356) >> 31));
        v359[v839] = v863;
        int * v361 = v291->cache_age;
        int v362 = v361[v841];
        int * v363 = v291->cache_age;
        int v866 = v362 + ((int)((unsigned int)(v362 - v356) >> 31));
        v363[v841] = v866;
        int * v365 = v291->cache_age;
        v365[v860] = 0;
        v418 = v860;
      } else {
        int * v368 = v291->cache_age;
        int v869 = 4 + ((((int)((unsigned int)((int)((unsigned int)v319 >> 2)) >> 1)) & 3) * 2);
        int v369 = v368[v869];
        int * v370 = v291->cache_tags;
        int v371 = v370[v869];
        int * v372 = v291->cache_age;
        int v373 = v372[v841];
        int * v374 = v291->cache_tags;
        int v375 = v374[v841];
        int * v376 = v291->cache_dirty;
        int v874 = (4 + ((((int)((unsigned int)((int)((unsigned int)v319 >> 2)) >> 1)) & 3) * 2)) + ((((v369 + ((~(((v371 ^ -1) | (-(v371 ^ -1))) >> 31)) & 2)) - (v373 + ((~(((v375 ^ -1) | (-(v375 ^ -1))) >> 31)) & 2))) >> 31) & 1);
        int v377 = v376[v874];
        bool v875 = !(v377 == 0);
        if (v875) {
          int * v378 = v291->cache_tags;
          int v379 = v378[v874];
          int * v380 = v291->cache_vals;
          int v878 = ((4 + ((((int)((unsigned int)((int)((unsigned int)v319 >> 2)) >> 1)) & 3) * 2)) + ((((v369 + ((~(((v371 ^ -1) | (-(v371 ^ -1))) >> 31)) & 2)) - (v373 + ((~(((v375 ^ -1) | (-(v375 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
          int v381 = v380[v878];
          int * v382 = v291->cache_vals;
          int v880 = (((4 + ((((int)((unsigned int)((int)((unsigned int)v319 >> 2)) >> 1)) & 3) * 2)) + ((((v369 + ((~(((v371 ^ -1) | (-(v371 ^ -1))) >> 31)) & 2)) - (v373 + ((~(((v375 ^ -1) | (-(v375 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
          int v383 = v382[v880];
          int * v384 = v291->mem;
          int v882 = v379 * 2;
          v384[v882] = v381;
          int * v386 = v291->mem;
          int v885 = (v379 * 2) + 1;
          v386[v885] = v383;
          ;
        } else {
          ;
        }
        int * v391 = v291->mem;
        int v890 = ((int)((unsigned int)((int)((unsigned int)v319 >> 2)) >> 1)) * 2;
        int v392 = v391[v890];
        int * v393 = v291->mem;
        int v892 = (((int)((unsigned int)((int)((unsigned int)v319 >> 2)) >> 1)) * 2) + 1;
        int v394 = v393[v892];
        int * v395 = v291->cache_vals;
        int v894 = ((4 + ((((int)((unsigned int)((int)((unsigned int)v319 >> 2)) >> 1)) & 3) * 2)) + ((((v369 + ((~(((v371 ^ -1) | (-(v371 ^ -1))) >> 31)) & 2)) - (v373 + ((~(((v375 ^ -1) | (-(v375 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
        v395[v894] = v392;
        int * v397 = v291->cache_vals;
        int v897 = (((4 + ((((int)((unsigned int)((int)((unsigned int)v319 >> 2)) >> 1)) & 3) * 2)) + ((((v369 + ((~(((v371 ^ -1) | (-(v371 ^ -1))) >> 31)) & 2)) - (v373 + ((~(((v375 ^ -1) | (-(v375 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
        v397[v897] = v394;
        int * v399 = v291->cache_tags;
        int v900 = (int)((unsigned int)((int)((unsigned int)v319 >> 2)) >> 1);
        v399[v874] = v900;
        int * v401 = v291->cache_dirty;
        v401[v874] = 0;
        int * v403 = v291->cache_age;
        v403[v874] = 1;
        int * v405 = v291->cache_age;
        int v406 = v405[v874];
        int * v407 = v291->cache_age;
        int v408 = v407[v839];
        int * v409 = v291->cache_age;
        int v907 = v408 + ((int)((unsigned int)(v408 - v406) >> 31));
        v409[v839] = v907;
        int * v411 = v291->cache_age;
        int v412 = v411[v841];
        int * v413 = v291->cache_age;
        int v910 = v412 + ((int)((unsigned int)(v412 - v406) >> 31));
        v413[v841] = v910;
        int * v415 = v291->cache_age;
        v415[v874] = 0;
        v418 = v874;
      }
      int * v419 = v291->cache_vals;
      int v913 = v418 * 2;
      int v420 = v419[v913];
      int * v421 = v291->cache_vals;
      int v915 = (v418 * 2) + 1;
      int v422 = v421[v915];
      int * v423 = v291->cache_vals;
      int v917 = (((((int)((unsigned int)((int)((unsigned int)v319 >> 2)) >> 1)) & 1) * 2) + ((((v348 + ((~(((v350 ^ -1) | (-(v350 ^ -1))) >> 31)) & 2)) - (v352 + ((~(((v354 ^ -1) | (-(v354 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
      v423[v917] = v420;
      int * v425 = v291->cache_vals;
      int v920 = ((((((int)((unsigned int)((int)((unsigned int)v319 >> 2)) >> 1)) & 1) * 2) + ((((v348 + ((~(((v350 ^ -1) | (-(v350 ^ -1))) >> 31)) & 2)) - (v352 + ((~(((v354 ^ -1) | (-(v354 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
      v425[v920] = v422;
      int * v427 = v291->cache_tags;
      int v923 = ((((int)((unsigned int)((int)((unsigned int)v319 >> 2)) >> 1)) & 1) * 2) + ((((v348 + ((~(((v350 ^ -1) | (-(v350 ^ -1))) >> 31)) & 2)) - (v352 + ((~(((v354 ^ -1) | (-(v354 ^ -1))) >> 31)) & 2))) >> 31) & 1);
      int v924 = (int)((unsigned int)((int)((unsigned int)v319 >> 2)) >> 1);
      v427[v923] = v924;
      int * v429 = v291->cache_dirty;
      v429[v923] = 0;
      int * v431 = v291->cache_age;
      v431[v923] = 1;
      int * v433 = v291->cache_age;
      int v434 = v433[v923];
      int * v435 = v291->cache_age;
      int v436 = v435[v835];
      int * v437 = v291->cache_age;
      int v931 = v436 + ((int)((unsigned int)(v436 - v434) >> 31));
      v437[v835] = v931;
      int * v439 = v291->cache_age;
      int v440 = v439[v837];
      int * v441 = v291->cache_age;
      int v934 = v440 + ((int)((unsigned int)(v440 - v434) >> 31));
      v441[v837] = v934;
      int * v443 = v291->cache_age;
      v443[v923] = 0;
      v446 = v923;
    }
    int v937 = (v446 * 2) + (((int)((unsigned int)v319 >> 2)) & 1);
    int v447 = v333[v937];
    v449 = v447;
  }
  int * v450 = v291->regs;
  v450[11] = v449;
  int * v452 = v291->saved_regs;
  int * v453 = v291->regs;
  int v454 = v453[12];
  v452[12] = v454;
  int v456 = v291->timer;
  int v945 = v456 + 1;
  v291->timer = v945;
  int * v458 = v291->regs;
  int v459 = v458[11];
  bool v947 = (((int)((unsigned int)v295 >> 2)) & 3) == (((int)((unsigned int)v459 >> 2)) & 3);
  int v589;
  if (v947) {
    int v460 = v291->timer;
    int v948 = v460 + 1;
    v291->timer = v948;
    v589 = v297;
  } else {
    int * v463 = v291->cache_tags;
    int v951 = (((int)((unsigned int)((int)((unsigned int)v459 >> 2)) >> 1)) & 1) * 2;
    int v464 = v463[v951];
    int * v465 = v291->cache_tags;
    int v953 = ((((int)((unsigned int)((int)((unsigned int)v459 >> 2)) >> 1)) & 1) * 2) + 1;
    int v466 = v465[v953];
    int * v467 = v291->cache_tags;
    int v955 = 4 + ((((int)((unsigned int)((int)((unsigned int)v459 >> 2)) >> 1)) & 3) * 2);
    int v468 = v467[v955];
    int * v469 = v291->cache_tags;
    int v957 = (4 + ((((int)((unsigned int)((int)((unsigned int)v459 >> 2)) >> 1)) & 3) * 2)) + 1;
    int v470 = v469[v957];
    int v471 = v291->timer;
    int v958 = v471 + ((100 ^ (((~(((v468 ^ ((int)((unsigned int)((int)((unsigned int)v459 >> 2)) >> 1))) | (-(v468 ^ ((int)((unsigned int)((int)((unsigned int)v459 >> 2)) >> 1))))) >> 31)) | (~(((v470 ^ ((int)((unsigned int)((int)((unsigned int)v459 >> 2)) >> 1))) | (-(v470 ^ ((int)((unsigned int)((int)((unsigned int)v459 >> 2)) >> 1))))) >> 31))) & 104)) ^ (((~(((v464 ^ ((int)((unsigned int)((int)((unsigned int)v459 >> 2)) >> 1))) | (-(v464 ^ ((int)((unsigned int)((int)((unsigned int)v459 >> 2)) >> 1))))) >> 31)) | (~(((v466 ^ ((int)((unsigned int)((int)((unsigned int)v459 >> 2)) >> 1))) | (-(v466 ^ ((int)((unsigned int)((int)((unsigned int)v459 >> 2)) >> 1))))) >> 31))) & (1 ^ (100 ^ (((~(((v468 ^ ((int)((unsigned int)((int)((unsigned int)v459 >> 2)) >> 1))) | (-(v468 ^ ((int)((unsigned int)((int)((unsigned int)v459 >> 2)) >> 1))))) >> 31)) | (~(((v470 ^ ((int)((unsigned int)((int)((unsigned int)v459 >> 2)) >> 1))) | (-(v470 ^ ((int)((unsigned int)((int)((unsigned int)v459 >> 2)) >> 1))))) >> 31))) & 104)))));
    v291->timer = v958;
    int * v473 = v291->cache_vals;
    bool v959 = !(((~(((v464 ^ ((int)((unsigned int)((int)((unsigned int)v459 >> 2)) >> 1))) | (-(v464 ^ ((int)((unsigned int)((int)((unsigned int)v459 >> 2)) >> 1))))) >> 31)) | (~(((v466 ^ ((int)((unsigned int)((int)((unsigned int)v459 >> 2)) >> 1))) | (-(v466 ^ ((int)((unsigned int)((int)((unsigned int)v459 >> 2)) >> 1))))) >> 31))) == 0);
    int v586;
    if (v959) {
      int * v474 = v291->cache_age;
      int v961 = ((((int)((unsigned int)((int)((unsigned int)v459 >> 2)) >> 1)) & 1) * 2) + ((~(((v466 ^ ((int)((unsigned int)((int)((unsigned int)v459 >> 2)) >> 1))) | (-(v466 ^ ((int)((unsigned int)((int)((unsigned int)v459 >> 2)) >> 1))))) >> 31)) & 1);
      int v475 = v474[v961];
      int * v476 = v291->cache_age;
      int v477 = v476[v951];
      int * v478 = v291->cache_age;
      int v964 = v477 + ((int)((unsigned int)(v477 - v475) >> 31));
      v478[v951] = v964;
      int * v480 = v291->cache_age;
      int v481 = v480[v953];
      int * v482 = v291->cache_age;
      int v967 = v481 + ((int)((unsigned int)(v481 - v475) >> 31));
      v482[v953] = v967;
      int * v484 = v291->cache_age;
      v484[v961] = 0;
      v586 = v961;
    } else {
      int * v487 = v291->cache_age;
      int v970 = (((int)((unsigned int)((int)((unsigned int)v459 >> 2)) >> 1)) & 1) * 2;
      int v488 = v487[v970];
      int * v489 = v291->cache_tags;
      int v490 = v489[v970];
      int * v491 = v291->cache_age;
      int v492 = v491[v953];
      int * v493 = v291->cache_tags;
      int v494 = v493[v953];
      bool v974 = !(((~(((v468 ^ ((int)((unsigned int)((int)((unsigned int)v459 >> 2)) >> 1))) | (-(v468 ^ ((int)((unsigned int)((int)((unsigned int)v459 >> 2)) >> 1))))) >> 31)) | (~(((v470 ^ ((int)((unsigned int)((int)((unsigned int)v459 >> 2)) >> 1))) | (-(v470 ^ ((int)((unsigned int)((int)((unsigned int)v459 >> 2)) >> 1))))) >> 31))) == 0);
      int v558;
      if (v974) {
        int * v495 = v291->cache_age;
        int v976 = (4 + ((((int)((unsigned int)((int)((unsigned int)v459 >> 2)) >> 1)) & 3) * 2)) + ((~(((v470 ^ ((int)((unsigned int)((int)((unsigned int)v459 >> 2)) >> 1))) | (-(v470 ^ ((int)((unsigned int)((int)((unsigned int)v459 >> 2)) >> 1))))) >> 31)) & 1);
        int v496 = v495[v976];
        int * v497 = v291->cache_age;
        int v498 = v497[v955];
        int * v499 = v291->cache_age;
        int v979 = v498 + ((int)((unsigned int)(v498 - v496) >> 31));
        v499[v955] = v979;
        int * v501 = v291->cache_age;
        int v502 = v501[v957];
        int * v503 = v291->cache_age;
        int v982 = v502 + ((int)((unsigned int)(v502 - v496) >> 31));
        v503[v957] = v982;
        int * v505 = v291->cache_age;
        v505[v976] = 0;
        v558 = v976;
      } else {
        int * v508 = v291->cache_age;
        int v985 = 4 + ((((int)((unsigned int)((int)((unsigned int)v459 >> 2)) >> 1)) & 3) * 2);
        int v509 = v508[v985];
        int * v510 = v291->cache_tags;
        int v511 = v510[v985];
        int * v512 = v291->cache_age;
        int v513 = v512[v957];
        int * v514 = v291->cache_tags;
        int v515 = v514[v957];
        int * v516 = v291->cache_dirty;
        int v990 = (4 + ((((int)((unsigned int)((int)((unsigned int)v459 >> 2)) >> 1)) & 3) * 2)) + ((((v509 + ((~(((v511 ^ -1) | (-(v511 ^ -1))) >> 31)) & 2)) - (v513 + ((~(((v515 ^ -1) | (-(v515 ^ -1))) >> 31)) & 2))) >> 31) & 1);
        int v517 = v516[v990];
        bool v991 = !(v517 == 0);
        if (v991) {
          int * v518 = v291->cache_tags;
          int v519 = v518[v990];
          int * v520 = v291->cache_vals;
          int v994 = ((4 + ((((int)((unsigned int)((int)((unsigned int)v459 >> 2)) >> 1)) & 3) * 2)) + ((((v509 + ((~(((v511 ^ -1) | (-(v511 ^ -1))) >> 31)) & 2)) - (v513 + ((~(((v515 ^ -1) | (-(v515 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
          int v521 = v520[v994];
          int * v522 = v291->cache_vals;
          int v996 = (((4 + ((((int)((unsigned int)((int)((unsigned int)v459 >> 2)) >> 1)) & 3) * 2)) + ((((v509 + ((~(((v511 ^ -1) | (-(v511 ^ -1))) >> 31)) & 2)) - (v513 + ((~(((v515 ^ -1) | (-(v515 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
          int v523 = v522[v996];
          int * v524 = v291->mem;
          int v998 = v519 * 2;
          v524[v998] = v521;
          int * v526 = v291->mem;
          int v1001 = (v519 * 2) + 1;
          v526[v1001] = v523;
          ;
        } else {
          ;
        }
        int * v531 = v291->mem;
        int v1006 = ((int)((unsigned int)((int)((unsigned int)v459 >> 2)) >> 1)) * 2;
        int v532 = v531[v1006];
        int * v533 = v291->mem;
        int v1008 = (((int)((unsigned int)((int)((unsigned int)v459 >> 2)) >> 1)) * 2) + 1;
        int v534 = v533[v1008];
        int * v535 = v291->cache_vals;
        int v1010 = ((4 + ((((int)((unsigned int)((int)((unsigned int)v459 >> 2)) >> 1)) & 3) * 2)) + ((((v509 + ((~(((v511 ^ -1) | (-(v511 ^ -1))) >> 31)) & 2)) - (v513 + ((~(((v515 ^ -1) | (-(v515 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
        v535[v1010] = v532;
        int * v537 = v291->cache_vals;
        int v1013 = (((4 + ((((int)((unsigned int)((int)((unsigned int)v459 >> 2)) >> 1)) & 3) * 2)) + ((((v509 + ((~(((v511 ^ -1) | (-(v511 ^ -1))) >> 31)) & 2)) - (v513 + ((~(((v515 ^ -1) | (-(v515 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
        v537[v1013] = v534;
        int * v539 = v291->cache_tags;
        int v1016 = (int)((unsigned int)((int)((unsigned int)v459 >> 2)) >> 1);
        v539[v990] = v1016;
        int * v541 = v291->cache_dirty;
        v541[v990] = 0;
        int * v543 = v291->cache_age;
        v543[v990] = 1;
        int * v545 = v291->cache_age;
        int v546 = v545[v990];
        int * v547 = v291->cache_age;
        int v548 = v547[v955];
        int * v549 = v291->cache_age;
        int v1023 = v548 + ((int)((unsigned int)(v548 - v546) >> 31));
        v549[v955] = v1023;
        int * v551 = v291->cache_age;
        int v552 = v551[v957];
        int * v553 = v291->cache_age;
        int v1026 = v552 + ((int)((unsigned int)(v552 - v546) >> 31));
        v553[v957] = v1026;
        int * v555 = v291->cache_age;
        v555[v990] = 0;
        v558 = v990;
      }
      int * v559 = v291->cache_vals;
      int v1029 = v558 * 2;
      int v560 = v559[v1029];
      int * v561 = v291->cache_vals;
      int v1031 = (v558 * 2) + 1;
      int v562 = v561[v1031];
      int * v563 = v291->cache_vals;
      int v1033 = (((((int)((unsigned int)((int)((unsigned int)v459 >> 2)) >> 1)) & 1) * 2) + ((((v488 + ((~(((v490 ^ -1) | (-(v490 ^ -1))) >> 31)) & 2)) - (v492 + ((~(((v494 ^ -1) | (-(v494 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
      v563[v1033] = v560;
      int * v565 = v291->cache_vals;
      int v1036 = ((((((int)((unsigned int)((int)((unsigned int)v459 >> 2)) >> 1)) & 1) * 2) + ((((v488 + ((~(((v490 ^ -1) | (-(v490 ^ -1))) >> 31)) & 2)) - (v492 + ((~(((v494 ^ -1) | (-(v494 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
      v565[v1036] = v562;
      int * v567 = v291->cache_tags;
      int v1039 = ((((int)((unsigned int)((int)((unsigned int)v459 >> 2)) >> 1)) & 1) * 2) + ((((v488 + ((~(((v490 ^ -1) | (-(v490 ^ -1))) >> 31)) & 2)) - (v492 + ((~(((v494 ^ -1) | (-(v494 ^ -1))) >> 31)) & 2))) >> 31) & 1);
      int v1040 = (int)((unsigned int)((int)((unsigned int)v459 >> 2)) >> 1);
      v567[v1039] = v1040;
      int * v569 = v291->cache_dirty;
      v569[v1039] = 0;
      int * v571 = v291->cache_age;
      v571[v1039] = 1;
      int * v573 = v291->cache_age;
      int v574 = v573[v1039];
      int * v575 = v291->cache_age;
      int v576 = v575[v951];
      int * v577 = v291->cache_age;
      int v1047 = v576 + ((int)((unsigned int)(v576 - v574) >> 31));
      v577[v951] = v1047;
      int * v579 = v291->cache_age;
      int v580 = v579[v953];
      int * v581 = v291->cache_age;
      int v1050 = v580 + ((int)((unsigned int)(v580 - v574) >> 31));
      v581[v953] = v1050;
      int * v583 = v291->cache_age;
      v583[v1039] = 0;
      v586 = v1039;
    }
    int v1053 = (v586 * 2) + (((int)((unsigned int)v459 >> 2)) & 1);
    int v587 = v473[v1053];
    v589 = v587;
  }
  int * v590 = v291->regs;
  v590[12] = v589;
  int * v592 = v291->cache_tags;
  int v1058 = (((int)((unsigned int)((int)((unsigned int)v295 >> 2)) >> 1)) & 1) * 2;
  int v593 = v592[v1058];
  int * v594 = v291->cache_tags;
  int v1060 = ((((int)((unsigned int)((int)((unsigned int)v295 >> 2)) >> 1)) & 1) * 2) + 1;
  int v595 = v594[v1060];
  int * v596 = v291->cache_tags;
  int v1062 = 4 + ((((int)((unsigned int)((int)((unsigned int)v295 >> 2)) >> 1)) & 3) * 2);
  int v597 = v596[v1062];
  int * v598 = v291->cache_tags;
  int v1064 = (4 + ((((int)((unsigned int)((int)((unsigned int)v295 >> 2)) >> 1)) & 3) * 2)) + 1;
  int v599 = v598[v1064];
  int v600 = v291->timer;
  int v1065 = v600 + ((100 ^ (((~(((v597 ^ ((int)((unsigned int)((int)((unsigned int)v295 >> 2)) >> 1))) | (-(v597 ^ ((int)((unsigned int)((int)((unsigned int)v295 >> 2)) >> 1))))) >> 31)) | (~(((v599 ^ ((int)((unsigned int)((int)((unsigned int)v295 >> 2)) >> 1))) | (-(v599 ^ ((int)((unsigned int)((int)((unsigned int)v295 >> 2)) >> 1))))) >> 31))) & 104)) ^ (((~(((v593 ^ ((int)((unsigned int)((int)((unsigned int)v295 >> 2)) >> 1))) | (-(v593 ^ ((int)((unsigned int)((int)((unsigned int)v295 >> 2)) >> 1))))) >> 31)) | (~(((v595 ^ ((int)((unsigned int)((int)((unsigned int)v295 >> 2)) >> 1))) | (-(v595 ^ ((int)((unsigned int)((int)((unsigned int)v295 >> 2)) >> 1))))) >> 31))) & (1 ^ (100 ^ (((~(((v597 ^ ((int)((unsigned int)((int)((unsigned int)v295 >> 2)) >> 1))) | (-(v597 ^ ((int)((unsigned int)((int)((unsigned int)v295 >> 2)) >> 1))))) >> 31)) | (~(((v599 ^ ((int)((unsigned int)((int)((unsigned int)v295 >> 2)) >> 1))) | (-(v599 ^ ((int)((unsigned int)((int)((unsigned int)v295 >> 2)) >> 1))))) >> 31))) & 104)))));
  v291->timer = v1065;
  bool v1066 = !(((~(((v593 ^ ((int)((unsigned int)((int)((unsigned int)v295 >> 2)) >> 1))) | (-(v593 ^ ((int)((unsigned int)((int)((unsigned int)v295 >> 2)) >> 1))))) >> 31)) | (~(((v595 ^ ((int)((unsigned int)((int)((unsigned int)v295 >> 2)) >> 1))) | (-(v595 ^ ((int)((unsigned int)((int)((unsigned int)v295 >> 2)) >> 1))))) >> 31))) == 0);
  int v714;
  if (v1066) {
    int * v602 = v291->cache_age;
    int v1068 = ((((int)((unsigned int)((int)((unsigned int)v295 >> 2)) >> 1)) & 1) * 2) + ((~(((v595 ^ ((int)((unsigned int)((int)((unsigned int)v295 >> 2)) >> 1))) | (-(v595 ^ ((int)((unsigned int)((int)((unsigned int)v295 >> 2)) >> 1))))) >> 31)) & 1);
    int v603 = v602[v1068];
    int * v604 = v291->cache_age;
    int v605 = v604[v1058];
    int * v606 = v291->cache_age;
    int v1071 = v605 + ((int)((unsigned int)(v605 - v603) >> 31));
    v606[v1058] = v1071;
    int * v608 = v291->cache_age;
    int v609 = v608[v1060];
    int * v610 = v291->cache_age;
    int v1074 = v609 + ((int)((unsigned int)(v609 - v603) >> 31));
    v610[v1060] = v1074;
    int * v612 = v291->cache_age;
    v612[v1068] = 0;
    v714 = v1068;
  } else {
    int * v615 = v291->cache_age;
    int v1077 = (((int)((unsigned int)((int)((unsigned int)v295 >> 2)) >> 1)) & 1) * 2;
    int v616 = v615[v1077];
    int * v617 = v291->cache_tags;
    int v618 = v617[v1077];
    int * v619 = v291->cache_age;
    int v620 = v619[v1060];
    int * v621 = v291->cache_tags;
    int v622 = v621[v1060];
    bool v1081 = !(((~(((v597 ^ ((int)((unsigned int)((int)((unsigned int)v295 >> 2)) >> 1))) | (-(v597 ^ ((int)((unsigned int)((int)((unsigned int)v295 >> 2)) >> 1))))) >> 31)) | (~(((v599 ^ ((int)((unsigned int)((int)((unsigned int)v295 >> 2)) >> 1))) | (-(v599 ^ ((int)((unsigned int)((int)((unsigned int)v295 >> 2)) >> 1))))) >> 31))) == 0);
    int v686;
    if (v1081) {
      int * v623 = v291->cache_age;
      int v1083 = (4 + ((((int)((unsigned int)((int)((unsigned int)v295 >> 2)) >> 1)) & 3) * 2)) + ((~(((v599 ^ ((int)((unsigned int)((int)((unsigned int)v295 >> 2)) >> 1))) | (-(v599 ^ ((int)((unsigned int)((int)((unsigned int)v295 >> 2)) >> 1))))) >> 31)) & 1);
      int v624 = v623[v1083];
      int * v625 = v291->cache_age;
      int v626 = v625[v1062];
      int * v627 = v291->cache_age;
      int v1086 = v626 + ((int)((unsigned int)(v626 - v624) >> 31));
      v627[v1062] = v1086;
      int * v629 = v291->cache_age;
      int v630 = v629[v1064];
      int * v631 = v291->cache_age;
      int v1089 = v630 + ((int)((unsigned int)(v630 - v624) >> 31));
      v631[v1064] = v1089;
      int * v633 = v291->cache_age;
      v633[v1083] = 0;
      v686 = v1083;
    } else {
      int * v636 = v291->cache_age;
      int v1092 = 4 + ((((int)((unsigned int)((int)((unsigned int)v295 >> 2)) >> 1)) & 3) * 2);
      int v637 = v636[v1092];
      int * v638 = v291->cache_tags;
      int v639 = v638[v1092];
      int * v640 = v291->cache_age;
      int v641 = v640[v1064];
      int * v642 = v291->cache_tags;
      int v643 = v642[v1064];
      int * v644 = v291->cache_dirty;
      int v1097 = (4 + ((((int)((unsigned int)((int)((unsigned int)v295 >> 2)) >> 1)) & 3) * 2)) + ((((v637 + ((~(((v639 ^ -1) | (-(v639 ^ -1))) >> 31)) & 2)) - (v641 + ((~(((v643 ^ -1) | (-(v643 ^ -1))) >> 31)) & 2))) >> 31) & 1);
      int v645 = v644[v1097];
      bool v1098 = !(v645 == 0);
      if (v1098) {
        int * v646 = v291->cache_tags;
        int v647 = v646[v1097];
        int * v648 = v291->cache_vals;
        int v1101 = ((4 + ((((int)((unsigned int)((int)((unsigned int)v295 >> 2)) >> 1)) & 3) * 2)) + ((((v637 + ((~(((v639 ^ -1) | (-(v639 ^ -1))) >> 31)) & 2)) - (v641 + ((~(((v643 ^ -1) | (-(v643 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
        int v649 = v648[v1101];
        int * v650 = v291->cache_vals;
        int v1103 = (((4 + ((((int)((unsigned int)((int)((unsigned int)v295 >> 2)) >> 1)) & 3) * 2)) + ((((v637 + ((~(((v639 ^ -1) | (-(v639 ^ -1))) >> 31)) & 2)) - (v641 + ((~(((v643 ^ -1) | (-(v643 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
        int v651 = v650[v1103];
        int * v652 = v291->mem;
        int v1105 = v647 * 2;
        v652[v1105] = v649;
        int * v654 = v291->mem;
        int v1108 = (v647 * 2) + 1;
        v654[v1108] = v651;
        ;
      } else {
        ;
      }
      int * v659 = v291->mem;
      int v1113 = ((int)((unsigned int)((int)((unsigned int)v295 >> 2)) >> 1)) * 2;
      int v660 = v659[v1113];
      int * v661 = v291->mem;
      int v1115 = (((int)((unsigned int)((int)((unsigned int)v295 >> 2)) >> 1)) * 2) + 1;
      int v662 = v661[v1115];
      int * v663 = v291->cache_vals;
      int v1117 = ((4 + ((((int)((unsigned int)((int)((unsigned int)v295 >> 2)) >> 1)) & 3) * 2)) + ((((v637 + ((~(((v639 ^ -1) | (-(v639 ^ -1))) >> 31)) & 2)) - (v641 + ((~(((v643 ^ -1) | (-(v643 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
      v663[v1117] = v660;
      int * v665 = v291->cache_vals;
      int v1120 = (((4 + ((((int)((unsigned int)((int)((unsigned int)v295 >> 2)) >> 1)) & 3) * 2)) + ((((v637 + ((~(((v639 ^ -1) | (-(v639 ^ -1))) >> 31)) & 2)) - (v641 + ((~(((v643 ^ -1) | (-(v643 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
      v665[v1120] = v662;
      int * v667 = v291->cache_tags;
      int v1123 = (int)((unsigned int)((int)((unsigned int)v295 >> 2)) >> 1);
      v667[v1097] = v1123;
      int * v669 = v291->cache_dirty;
      v669[v1097] = 0;
      int * v671 = v291->cache_age;
      v671[v1097] = 1;
      int * v673 = v291->cache_age;
      int v674 = v673[v1097];
      int * v675 = v291->cache_age;
      int v676 = v675[v1062];
      int * v677 = v291->cache_age;
      int v1130 = v676 + ((int)((unsigned int)(v676 - v674) >> 31));
      v677[v1062] = v1130;
      int * v679 = v291->cache_age;
      int v680 = v679[v1064];
      int * v681 = v291->cache_age;
      int v1133 = v680 + ((int)((unsigned int)(v680 - v674) >> 31));
      v681[v1064] = v1133;
      int * v683 = v291->cache_age;
      v683[v1097] = 0;
      v686 = v1097;
    }
    int * v687 = v291->cache_vals;
    int v1136 = v686 * 2;
    int v688 = v687[v1136];
    int * v689 = v291->cache_vals;
    int v1138 = (v686 * 2) + 1;
    int v690 = v689[v1138];
    int * v691 = v291->cache_vals;
    int v1140 = (((((int)((unsigned int)((int)((unsigned int)v295 >> 2)) >> 1)) & 1) * 2) + ((((v616 + ((~(((v618 ^ -1) | (-(v618 ^ -1))) >> 31)) & 2)) - (v620 + ((~(((v622 ^ -1) | (-(v622 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
    v691[v1140] = v688;
    int * v693 = v291->cache_vals;
    int v1143 = ((((((int)((unsigned int)((int)((unsigned int)v295 >> 2)) >> 1)) & 1) * 2) + ((((v616 + ((~(((v618 ^ -1) | (-(v618 ^ -1))) >> 31)) & 2)) - (v620 + ((~(((v622 ^ -1) | (-(v622 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
    v693[v1143] = v690;
    int * v695 = v291->cache_tags;
    int v1146 = ((((int)((unsigned int)((int)((unsigned int)v295 >> 2)) >> 1)) & 1) * 2) + ((((v616 + ((~(((v618 ^ -1) | (-(v618 ^ -1))) >> 31)) & 2)) - (v620 + ((~(((v622 ^ -1) | (-(v622 ^ -1))) >> 31)) & 2))) >> 31) & 1);
    int v1147 = (int)((unsigned int)((int)((unsigned int)v295 >> 2)) >> 1);
    v695[v1146] = v1147;
    int * v697 = v291->cache_dirty;
    v697[v1146] = 0;
    int * v699 = v291->cache_age;
    v699[v1146] = 1;
    int * v701 = v291->cache_age;
    int v702 = v701[v1146];
    int * v703 = v291->cache_age;
    int v704 = v703[v1058];
    int * v705 = v291->cache_age;
    int v1154 = v704 + ((int)((unsigned int)(v704 - v702) >> 31));
    v705[v1058] = v1154;
    int * v707 = v291->cache_age;
    int v708 = v707[v1060];
    int * v709 = v291->cache_age;
    int v1157 = v708 + ((int)((unsigned int)(v708 - v702) >> 31));
    v709[v1060] = v1157;
    int * v711 = v291->cache_age;
    v711[v1146] = 0;
    v714 = v1146;
  }
  int * v715 = v291->cache_vals;
  int v1160 = (v714 * 2) + (((int)((unsigned int)v295 >> 2)) & 1);
  v715[v1160] = v297;
  int * v717 = v291->cache_tags;
  int v718 = v717[v1062];
  int * v719 = v291->cache_tags;
  int v720 = v719[v1064];
  bool v1164 = !(((~(((v718 ^ ((int)((unsigned int)((int)((unsigned int)v295 >> 2)) >> 1))) | (-(v718 ^ ((int)((unsigned int)((int)((unsigned int)v295 >> 2)) >> 1))))) >> 31)) | (~(((v720 ^ ((int)((unsigned int)((int)((unsigned int)v295 >> 2)) >> 1))) | (-(v720 ^ ((int)((unsigned int)((int)((unsigned int)v295 >> 2)) >> 1))))) >> 31))) == 0);
  int v784;
  if (v1164) {
    int * v721 = v291->cache_age;
    int v1166 = (4 + ((((int)((unsigned int)((int)((unsigned int)v295 >> 2)) >> 1)) & 3) * 2)) + ((~(((v720 ^ ((int)((unsigned int)((int)((unsigned int)v295 >> 2)) >> 1))) | (-(v720 ^ ((int)((unsigned int)((int)((unsigned int)v295 >> 2)) >> 1))))) >> 31)) & 1);
    int v722 = v721[v1166];
    int * v723 = v291->cache_age;
    int v724 = v723[v1062];
    int * v725 = v291->cache_age;
    int v1169 = v724 + ((int)((unsigned int)(v724 - v722) >> 31));
    v725[v1062] = v1169;
    int * v727 = v291->cache_age;
    int v728 = v727[v1064];
    int * v729 = v291->cache_age;
    int v1172 = v728 + ((int)((unsigned int)(v728 - v722) >> 31));
    v729[v1064] = v1172;
    int * v731 = v291->cache_age;
    v731[v1166] = 0;
    v784 = v1166;
  } else {
    int * v734 = v291->cache_age;
    int v1175 = 4 + ((((int)((unsigned int)((int)((unsigned int)v295 >> 2)) >> 1)) & 3) * 2);
    int v735 = v734[v1175];
    int * v736 = v291->cache_tags;
    int v737 = v736[v1175];
    int * v738 = v291->cache_age;
    int v739 = v738[v1064];
    int * v740 = v291->cache_tags;
    int v741 = v740[v1064];
    int * v742 = v291->cache_dirty;
    int v1180 = (4 + ((((int)((unsigned int)((int)((unsigned int)v295 >> 2)) >> 1)) & 3) * 2)) + ((((v735 + ((~(((v737 ^ -1) | (-(v737 ^ -1))) >> 31)) & 2)) - (v739 + ((~(((v741 ^ -1) | (-(v741 ^ -1))) >> 31)) & 2))) >> 31) & 1);
    int v743 = v742[v1180];
    bool v1181 = !(v743 == 0);
    if (v1181) {
      int * v744 = v291->cache_tags;
      int v745 = v744[v1180];
      int * v746 = v291->cache_vals;
      int v1184 = ((4 + ((((int)((unsigned int)((int)((unsigned int)v295 >> 2)) >> 1)) & 3) * 2)) + ((((v735 + ((~(((v737 ^ -1) | (-(v737 ^ -1))) >> 31)) & 2)) - (v739 + ((~(((v741 ^ -1) | (-(v741 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
      int v747 = v746[v1184];
      int * v748 = v291->cache_vals;
      int v1186 = (((4 + ((((int)((unsigned int)((int)((unsigned int)v295 >> 2)) >> 1)) & 3) * 2)) + ((((v735 + ((~(((v737 ^ -1) | (-(v737 ^ -1))) >> 31)) & 2)) - (v739 + ((~(((v741 ^ -1) | (-(v741 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
      int v749 = v748[v1186];
      int * v750 = v291->mem;
      int v1188 = v745 * 2;
      v750[v1188] = v747;
      int * v752 = v291->mem;
      int v1191 = (v745 * 2) + 1;
      v752[v1191] = v749;
      ;
    } else {
      ;
    }
    int * v757 = v291->mem;
    int v1196 = ((int)((unsigned int)((int)((unsigned int)v295 >> 2)) >> 1)) * 2;
    int v758 = v757[v1196];
    int * v759 = v291->mem;
    int v1198 = (((int)((unsigned int)((int)((unsigned int)v295 >> 2)) >> 1)) * 2) + 1;
    int v760 = v759[v1198];
    int * v761 = v291->cache_vals;
    int v1200 = ((4 + ((((int)((unsigned int)((int)((unsigned int)v295 >> 2)) >> 1)) & 3) * 2)) + ((((v735 + ((~(((v737 ^ -1) | (-(v737 ^ -1))) >> 31)) & 2)) - (v739 + ((~(((v741 ^ -1) | (-(v741 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
    v761[v1200] = v758;
    int * v763 = v291->cache_vals;
    int v1203 = (((4 + ((((int)((unsigned int)((int)((unsigned int)v295 >> 2)) >> 1)) & 3) * 2)) + ((((v735 + ((~(((v737 ^ -1) | (-(v737 ^ -1))) >> 31)) & 2)) - (v739 + ((~(((v741 ^ -1) | (-(v741 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
    v763[v1203] = v760;
    int * v765 = v291->cache_tags;
    int v1206 = (int)((unsigned int)((int)((unsigned int)v295 >> 2)) >> 1);
    v765[v1180] = v1206;
    int * v767 = v291->cache_dirty;
    v767[v1180] = 0;
    int * v769 = v291->cache_age;
    v769[v1180] = 1;
    int * v771 = v291->cache_age;
    int v772 = v771[v1180];
    int * v773 = v291->cache_age;
    int v774 = v773[v1062];
    int * v775 = v291->cache_age;
    int v1213 = v774 + ((int)((unsigned int)(v774 - v772) >> 31));
    v775[v1062] = v1213;
    int * v777 = v291->cache_age;
    int v778 = v777[v1064];
    int * v779 = v291->cache_age;
    int v1216 = v778 + ((int)((unsigned int)(v778 - v772) >> 31));
    v779[v1064] = v1216;
    int * v781 = v291->cache_age;
    v781[v1180] = 0;
    v784 = v1180;
  }
  int * v785 = v291->cache_vals;
  int v1219 = (v784 * 2) + (((int)((unsigned int)v295 >> 2)) & 1);
  v785[v1219] = v297;
  int * v787 = v291->cache_dirty;
  v787[v784] = 1;
  bool v1223 = (((((int)((unsigned int)v319 >> 2)) & 3) == (((int)((unsigned int)v295 >> 2)) & 3)) & (!(((int)((unsigned int)v319 >> 2)) == ((int)((unsigned int)v295 >> 2))))) | (((((int)((unsigned int)v459 >> 2)) & 3) == (((int)((unsigned int)v295 >> 2)) & 3)) & (!(((int)((unsigned int)v459 >> 2)) == ((int)((unsigned int)v295 >> 2)))));
  struct StateT * v806;
  if (v1223) {
    int v789 = v291->timer;
    int v1224 = v789 + 15;
    v291->timer = v1224;
    int * v791 = v291->saved_regs;
    int v792 = v791[7];
    int * v793 = v291->regs;
    v793[7] = v792;
    int * v795 = v291->saved_regs;
    int v796 = v795[11];
    int * v797 = v291->regs;
    v797[11] = v796;
    int * v799 = v291->saved_regs;
    int v800 = v799[12];
    int * v801 = v291->regs;
    v801[12] = v800;
    struct StateT * v803 = slot_5(v291);
    v806 = v803;
  } else {
    v806 = v291;
  }
  return v806;
}

struct StateT * slot_2(struct StateT * v265) {
  int v266 = v265->timer;
  int v272 = v266 + 1;
  v265->timer = v272;
  int * v268 = v265->regs;
  v268[8] = 96;
  struct StateT * v270 = slot_3(v265);
  return v270;
}

struct StateT * slot_7(struct StateT * v1266) {
  int v1267 = v1266->timer;
  int v1400 = v1267 + 1;
  v1266->timer = v1400;
  int * v1269 = v1266->regs;
  int v1270 = v1269[9];
  int * v1271 = v1266->cache_tags;
  int v1404 = (((int)((unsigned int)((int)((unsigned int)v1270 >> 2)) >> 1)) & 1) * 2;
  int v1272 = v1271[v1404];
  int * v1273 = v1266->cache_tags;
  int v1406 = ((((int)((unsigned int)((int)((unsigned int)v1270 >> 2)) >> 1)) & 1) * 2) + 1;
  int v1274 = v1273[v1406];
  int * v1275 = v1266->cache_tags;
  int v1408 = 4 + ((((int)((unsigned int)((int)((unsigned int)v1270 >> 2)) >> 1)) & 3) * 2);
  int v1276 = v1275[v1408];
  int * v1277 = v1266->cache_tags;
  int v1410 = (4 + ((((int)((unsigned int)((int)((unsigned int)v1270 >> 2)) >> 1)) & 3) * 2)) + 1;
  int v1278 = v1277[v1410];
  int v1279 = v1266->timer;
  int v1411 = v1279 + ((100 ^ (((~(((v1276 ^ ((int)((unsigned int)((int)((unsigned int)v1270 >> 2)) >> 1))) | (-(v1276 ^ ((int)((unsigned int)((int)((unsigned int)v1270 >> 2)) >> 1))))) >> 31)) | (~(((v1278 ^ ((int)((unsigned int)((int)((unsigned int)v1270 >> 2)) >> 1))) | (-(v1278 ^ ((int)((unsigned int)((int)((unsigned int)v1270 >> 2)) >> 1))))) >> 31))) & 104)) ^ (((~(((v1272 ^ ((int)((unsigned int)((int)((unsigned int)v1270 >> 2)) >> 1))) | (-(v1272 ^ ((int)((unsigned int)((int)((unsigned int)v1270 >> 2)) >> 1))))) >> 31)) | (~(((v1274 ^ ((int)((unsigned int)((int)((unsigned int)v1270 >> 2)) >> 1))) | (-(v1274 ^ ((int)((unsigned int)((int)((unsigned int)v1270 >> 2)) >> 1))))) >> 31))) & (1 ^ (100 ^ (((~(((v1276 ^ ((int)((unsigned int)((int)((unsigned int)v1270 >> 2)) >> 1))) | (-(v1276 ^ ((int)((unsigned int)((int)((unsigned int)v1270 >> 2)) >> 1))))) >> 31)) | (~(((v1278 ^ ((int)((unsigned int)((int)((unsigned int)v1270 >> 2)) >> 1))) | (-(v1278 ^ ((int)((unsigned int)((int)((unsigned int)v1270 >> 2)) >> 1))))) >> 31))) & 104)))));
  v1266->timer = v1411;
  int * v1281 = v1266->cache_vals;
  bool v1412 = !(((~(((v1272 ^ ((int)((unsigned int)((int)((unsigned int)v1270 >> 2)) >> 1))) | (-(v1272 ^ ((int)((unsigned int)((int)((unsigned int)v1270 >> 2)) >> 1))))) >> 31)) | (~(((v1274 ^ ((int)((unsigned int)((int)((unsigned int)v1270 >> 2)) >> 1))) | (-(v1274 ^ ((int)((unsigned int)((int)((unsigned int)v1270 >> 2)) >> 1))))) >> 31))) == 0);
  int v1394;
  if (v1412) {
    int * v1282 = v1266->cache_age;
    int v1414 = ((((int)((unsigned int)((int)((unsigned int)v1270 >> 2)) >> 1)) & 1) * 2) + ((~(((v1274 ^ ((int)((unsigned int)((int)((unsigned int)v1270 >> 2)) >> 1))) | (-(v1274 ^ ((int)((unsigned int)((int)((unsigned int)v1270 >> 2)) >> 1))))) >> 31)) & 1);
    int v1283 = v1282[v1414];
    int * v1284 = v1266->cache_age;
    int v1285 = v1284[v1404];
    int * v1286 = v1266->cache_age;
    int v1417 = v1285 + ((int)((unsigned int)(v1285 - v1283) >> 31));
    v1286[v1404] = v1417;
    int * v1288 = v1266->cache_age;
    int v1289 = v1288[v1406];
    int * v1290 = v1266->cache_age;
    int v1420 = v1289 + ((int)((unsigned int)(v1289 - v1283) >> 31));
    v1290[v1406] = v1420;
    int * v1292 = v1266->cache_age;
    v1292[v1414] = 0;
    v1394 = v1414;
  } else {
    int * v1295 = v1266->cache_age;
    int v1424 = (((int)((unsigned int)((int)((unsigned int)v1270 >> 2)) >> 1)) & 1) * 2;
    int v1296 = v1295[v1424];
    int * v1297 = v1266->cache_tags;
    int v1298 = v1297[v1424];
    int * v1299 = v1266->cache_age;
    int v1300 = v1299[v1406];
    int * v1301 = v1266->cache_tags;
    int v1302 = v1301[v1406];
    bool v1428 = !(((~(((v1276 ^ ((int)((unsigned int)((int)((unsigned int)v1270 >> 2)) >> 1))) | (-(v1276 ^ ((int)((unsigned int)((int)((unsigned int)v1270 >> 2)) >> 1))))) >> 31)) | (~(((v1278 ^ ((int)((unsigned int)((int)((unsigned int)v1270 >> 2)) >> 1))) | (-(v1278 ^ ((int)((unsigned int)((int)((unsigned int)v1270 >> 2)) >> 1))))) >> 31))) == 0);
    int v1366;
    if (v1428) {
      int * v1303 = v1266->cache_age;
      int v1430 = (4 + ((((int)((unsigned int)((int)((unsigned int)v1270 >> 2)) >> 1)) & 3) * 2)) + ((~(((v1278 ^ ((int)((unsigned int)((int)((unsigned int)v1270 >> 2)) >> 1))) | (-(v1278 ^ ((int)((unsigned int)((int)((unsigned int)v1270 >> 2)) >> 1))))) >> 31)) & 1);
      int v1304 = v1303[v1430];
      int * v1305 = v1266->cache_age;
      int v1306 = v1305[v1408];
      int * v1307 = v1266->cache_age;
      int v1433 = v1306 + ((int)((unsigned int)(v1306 - v1304) >> 31));
      v1307[v1408] = v1433;
      int * v1309 = v1266->cache_age;
      int v1310 = v1309[v1410];
      int * v1311 = v1266->cache_age;
      int v1436 = v1310 + ((int)((unsigned int)(v1310 - v1304) >> 31));
      v1311[v1410] = v1436;
      int * v1313 = v1266->cache_age;
      v1313[v1430] = 0;
      v1366 = v1430;
    } else {
      int * v1316 = v1266->cache_age;
      int v1440 = 4 + ((((int)((unsigned int)((int)((unsigned int)v1270 >> 2)) >> 1)) & 3) * 2);
      int v1317 = v1316[v1440];
      int * v1318 = v1266->cache_tags;
      int v1319 = v1318[v1440];
      int * v1320 = v1266->cache_age;
      int v1321 = v1320[v1410];
      int * v1322 = v1266->cache_tags;
      int v1323 = v1322[v1410];
      int * v1324 = v1266->cache_dirty;
      int v1445 = (4 + ((((int)((unsigned int)((int)((unsigned int)v1270 >> 2)) >> 1)) & 3) * 2)) + ((((v1317 + ((~(((v1319 ^ -1) | (-(v1319 ^ -1))) >> 31)) & 2)) - (v1321 + ((~(((v1323 ^ -1) | (-(v1323 ^ -1))) >> 31)) & 2))) >> 31) & 1);
      int v1325 = v1324[v1445];
      bool v1446 = !(v1325 == 0);
      if (v1446) {
        int * v1326 = v1266->cache_tags;
        int v1327 = v1326[v1445];
        int * v1328 = v1266->cache_vals;
        int v1449 = ((4 + ((((int)((unsigned int)((int)((unsigned int)v1270 >> 2)) >> 1)) & 3) * 2)) + ((((v1317 + ((~(((v1319 ^ -1) | (-(v1319 ^ -1))) >> 31)) & 2)) - (v1321 + ((~(((v1323 ^ -1) | (-(v1323 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
        int v1329 = v1328[v1449];
        int * v1330 = v1266->cache_vals;
        int v1451 = (((4 + ((((int)((unsigned int)((int)((unsigned int)v1270 >> 2)) >> 1)) & 3) * 2)) + ((((v1317 + ((~(((v1319 ^ -1) | (-(v1319 ^ -1))) >> 31)) & 2)) - (v1321 + ((~(((v1323 ^ -1) | (-(v1323 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
        int v1331 = v1330[v1451];
        int * v1332 = v1266->mem;
        int v1453 = v1327 * 2;
        v1332[v1453] = v1329;
        int * v1334 = v1266->mem;
        int v1456 = (v1327 * 2) + 1;
        v1334[v1456] = v1331;
        ;
      } else {
        ;
      }
      int * v1339 = v1266->mem;
      int v1461 = ((int)((unsigned int)((int)((unsigned int)v1270 >> 2)) >> 1)) * 2;
      int v1340 = v1339[v1461];
      int * v1341 = v1266->mem;
      int v1463 = (((int)((unsigned int)((int)((unsigned int)v1270 >> 2)) >> 1)) * 2) + 1;
      int v1342 = v1341[v1463];
      int * v1343 = v1266->cache_vals;
      int v1465 = ((4 + ((((int)((unsigned int)((int)((unsigned int)v1270 >> 2)) >> 1)) & 3) * 2)) + ((((v1317 + ((~(((v1319 ^ -1) | (-(v1319 ^ -1))) >> 31)) & 2)) - (v1321 + ((~(((v1323 ^ -1) | (-(v1323 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
      v1343[v1465] = v1340;
      int * v1345 = v1266->cache_vals;
      int v1468 = (((4 + ((((int)((unsigned int)((int)((unsigned int)v1270 >> 2)) >> 1)) & 3) * 2)) + ((((v1317 + ((~(((v1319 ^ -1) | (-(v1319 ^ -1))) >> 31)) & 2)) - (v1321 + ((~(((v1323 ^ -1) | (-(v1323 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
      v1345[v1468] = v1342;
      int * v1347 = v1266->cache_tags;
      int v1471 = (int)((unsigned int)((int)((unsigned int)v1270 >> 2)) >> 1);
      v1347[v1445] = v1471;
      int * v1349 = v1266->cache_dirty;
      v1349[v1445] = 0;
      int * v1351 = v1266->cache_age;
      v1351[v1445] = 1;
      int * v1353 = v1266->cache_age;
      int v1354 = v1353[v1445];
      int * v1355 = v1266->cache_age;
      int v1356 = v1355[v1408];
      int * v1357 = v1266->cache_age;
      int v1479 = v1356 + ((int)((unsigned int)(v1356 - v1354) >> 31));
      v1357[v1408] = v1479;
      int * v1359 = v1266->cache_age;
      int v1360 = v1359[v1410];
      int * v1361 = v1266->cache_age;
      int v1482 = v1360 + ((int)((unsigned int)(v1360 - v1354) >> 31));
      v1361[v1410] = v1482;
      int * v1363 = v1266->cache_age;
      v1363[v1445] = 0;
      v1366 = v1445;
    }
    int * v1367 = v1266->cache_vals;
    int v1485 = v1366 * 2;
    int v1368 = v1367[v1485];
    int * v1369 = v1266->cache_vals;
    int v1487 = (v1366 * 2) + 1;
    int v1370 = v1369[v1487];
    int * v1371 = v1266->cache_vals;
    int v1489 = (((((int)((unsigned int)((int)((unsigned int)v1270 >> 2)) >> 1)) & 1) * 2) + ((((v1296 + ((~(((v1298 ^ -1) | (-(v1298 ^ -1))) >> 31)) & 2)) - (v1300 + ((~(((v1302 ^ -1) | (-(v1302 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
    v1371[v1489] = v1368;
    int * v1373 = v1266->cache_vals;
    int v1492 = ((((((int)((unsigned int)((int)((unsigned int)v1270 >> 2)) >> 1)) & 1) * 2) + ((((v1296 + ((~(((v1298 ^ -1) | (-(v1298 ^ -1))) >> 31)) & 2)) - (v1300 + ((~(((v1302 ^ -1) | (-(v1302 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
    v1373[v1492] = v1370;
    int * v1375 = v1266->cache_tags;
    int v1495 = ((((int)((unsigned int)((int)((unsigned int)v1270 >> 2)) >> 1)) & 1) * 2) + ((((v1296 + ((~(((v1298 ^ -1) | (-(v1298 ^ -1))) >> 31)) & 2)) - (v1300 + ((~(((v1302 ^ -1) | (-(v1302 ^ -1))) >> 31)) & 2))) >> 31) & 1);
    int v1496 = (int)((unsigned int)((int)((unsigned int)v1270 >> 2)) >> 1);
    v1375[v1495] = v1496;
    int * v1377 = v1266->cache_dirty;
    v1377[v1495] = 0;
    int * v1379 = v1266->cache_age;
    v1379[v1495] = 1;
    int * v1381 = v1266->cache_age;
    int v1382 = v1381[v1495];
    int * v1383 = v1266->cache_age;
    int v1384 = v1383[v1404];
    int * v1385 = v1266->cache_age;
    int v1504 = v1384 + ((int)((unsigned int)(v1384 - v1382) >> 31));
    v1385[v1404] = v1504;
    int * v1387 = v1266->cache_age;
    int v1388 = v1387[v1406];
    int * v1389 = v1266->cache_age;
    int v1507 = v1388 + ((int)((unsigned int)(v1388 - v1382) >> 31));
    v1389[v1406] = v1507;
    int * v1391 = v1266->cache_age;
    v1391[v1495] = 0;
    v1394 = v1495;
  }
  int v1510 = (v1394 * 2) + (((int)((unsigned int)v1270 >> 2)) & 1);
  int v1395 = v1281[v1510];
  int * v1396 = v1266->regs;
  v1396[11] = v1395;
  struct StateT * v1398 = slot_8(v1266);
  return v1398;
}

struct StateT * slot_3(struct StateT * v278) {
  int v279 = v278->timer;
  int v285 = v279 + 1;
  v278->timer = v285;
  int * v281 = v278->regs;
  v281[9] = 0;
  struct StateT * v283 = slot_4(v278);
  return v283;
}

struct StateT * slot_0(struct StateT * v2) {
  int v3 = v2->timer;
  int v9 = v3 + 1;
  v2->timer = v9;
  int * v5 = v2->regs;
  v5[6] = 80;
  struct StateT * v7 = slot_1(v2);
  return v7;
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