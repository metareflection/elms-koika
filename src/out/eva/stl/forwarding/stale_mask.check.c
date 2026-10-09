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

struct StateT * snippet(struct StateT * v0);
struct StateT * slot_1(struct StateT * v15);
struct StateT * slot_6(struct StateT * v1490);
struct StateT * slot_5(struct StateT * v1473);
struct StateT * slot_4(struct StateT * v1282);
struct StateT * slot_7(struct StateT * v1694);
struct StateT * slot_3(struct StateT * v328);
struct StateT * slot_0(struct StateT * v2);
struct StateT * snippet(struct StateT * v0) {
  struct StateT * v1 = slot_0(v0);
  return v1;
}

struct StateT * slot_1(struct StateT * v15) {
  int v16 = v15->timer;
  int v192 = v16 + 1;
  v15->timer = v192;
  int * v18 = v15->regs;
  int v19 = v18[5];
  int * v20 = v15->saved_regs;
  int v21 = v18[7];
  v20[7] = v21;
  int v23 = v15->timer;
  int v198 = v23 + 1;
  v15->timer = v198;
  int * v25 = v15->regs;
  v25[7] = 28;
  int * v27 = v15->cache_tags;
  int v28 = v27[0];
  int v29 = v27[1];
  int v30 = v27[8];
  int v31 = v27[9];
  int v32 = v15->timer;
  int v206 = v32 + ((100 ^ (((~(((v30 ^ 6) | (-(v30 ^ 6))) >> 31)) | (~(((v31 ^ 6) | (-(v31 ^ 6))) >> 31))) & 104)) ^ (((~(((v28 ^ 6) | (-(v28 ^ 6))) >> 31)) | (~(((v29 ^ 6) | (-(v29 ^ 6))) >> 31))) & (1 ^ (100 ^ (((~(((v30 ^ 6) | (-(v30 ^ 6))) >> 31)) | (~(((v31 ^ 6) | (-(v31 ^ 6))) >> 31))) & 104)))));
  v15->timer = v206;
  bool v207 = !(((~(((v28 ^ 6) | (-(v28 ^ 6))) >> 31)) | (~(((v29 ^ 6) | (-(v29 ^ 6))) >> 31))) == 0);
  int v126;
  if (v207) {
    int * v34 = v15->cache_age;
    int v209 = (~(((v29 ^ 6) | (-(v29 ^ 6))) >> 31)) & 1;
    int v35 = v34[v209];
    int v36 = v34[0];
    int v210 = v36 + ((int)((unsigned int)(v36 - v35) >> 31));
    v34[0] = v210;
    int * v38 = v15->cache_age;
    int v39 = v38[1];
    int v212 = v39 + ((int)((unsigned int)(v39 - v35) >> 31));
    v38[1] = v212;
    int * v41 = v15->cache_age;
    v41[v209] = 0;
    v126 = v209;
  } else {
    int * v44 = v15->cache_age;
    int v45 = v44[0];
    int * v46 = v15->cache_tags;
    int v47 = v46[0];
    int v48 = v44[1];
    int v49 = v46[1];
    bool v216 = !(((~(((v30 ^ 6) | (-(v30 ^ 6))) >> 31)) | (~(((v31 ^ 6) | (-(v31 ^ 6))) >> 31))) == 0);
    int v103;
    if (v216) {
      int * v50 = v15->cache_age;
      int v218 = 8 + ((~(((v31 ^ 6) | (-(v31 ^ 6))) >> 31)) & 1);
      int v51 = v50[v218];
      int v52 = v50[8];
      int v219 = v52 + ((int)((unsigned int)(v52 - v51) >> 31));
      v50[8] = v219;
      int * v54 = v15->cache_age;
      int v55 = v54[9];
      int v221 = v55 + ((int)((unsigned int)(v55 - v51) >> 31));
      v54[9] = v221;
      int * v57 = v15->cache_age;
      v57[v218] = 0;
      v103 = v218;
    } else {
      int * v60 = v15->cache_age;
      int v61 = v60[8];
      int * v62 = v15->cache_tags;
      int v63 = v62[8];
      int v64 = v60[9];
      int v65 = v62[9];
      int * v66 = v15->cache_dirty;
      int v226 = 8 + ((((v61 + ((~(((v63 ^ -1) | (-(v63 ^ -1))) >> 31)) & 2)) - (v64 + ((~(((v65 ^ -1) | (-(v65 ^ -1))) >> 31)) & 2))) >> 31) & 1);
      int v67 = v66[v226];
      bool v227 = !(v67 == 0);
      if (v227) {
        int * v68 = v15->cache_tags;
        int v69 = v68[v226];
        int * v70 = v15->cache_vals;
        int v230 = (8 + ((((v61 + ((~(((v63 ^ -1) | (-(v63 ^ -1))) >> 31)) & 2)) - (v64 + ((~(((v65 ^ -1) | (-(v65 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
        int v71 = v70[v230];
        int v231 = ((8 + ((((v61 + ((~(((v63 ^ -1) | (-(v63 ^ -1))) >> 31)) & 2)) - (v64 + ((~(((v65 ^ -1) | (-(v65 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
        int v72 = v70[v231];
        int * v73 = v15->mem;
        int v233 = v69 * 2;
        v73[v233] = v71;
        int * v75 = v15->mem;
        int v236 = (v69 * 2) + 1;
        v75[v236] = v72;
        ;
      } else {
        ;
      }
      int * v80 = v15->mem;
      int v81 = v80[12];
      int v82 = v80[13];
      int * v83 = v15->cache_vals;
      int v244 = (8 + ((((v61 + ((~(((v63 ^ -1) | (-(v63 ^ -1))) >> 31)) & 2)) - (v64 + ((~(((v65 ^ -1) | (-(v65 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
      v83[v244] = v81;
      int * v85 = v15->cache_vals;
      int v247 = ((8 + ((((v61 + ((~(((v63 ^ -1) | (-(v63 ^ -1))) >> 31)) & 2)) - (v64 + ((~(((v65 ^ -1) | (-(v65 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
      v85[v247] = v82;
      int * v87 = v15->cache_tags;
      v87[v226] = 6;
      int * v89 = v15->cache_dirty;
      v89[v226] = 0;
      int * v91 = v15->cache_age;
      v91[v226] = 1;
      int * v93 = v15->cache_age;
      int v94 = v93[v226];
      int v95 = v93[8];
      int v254 = v95 + ((int)((unsigned int)(v95 - v94) >> 31));
      v93[8] = v254;
      int * v97 = v15->cache_age;
      int v98 = v97[9];
      int v256 = v98 + ((int)((unsigned int)(v98 - v94) >> 31));
      v97[9] = v256;
      int * v100 = v15->cache_age;
      v100[v226] = 0;
      v103 = v226;
    }
    int * v104 = v15->cache_vals;
    int v259 = v103 * 2;
    int v105 = v104[v259];
    int v260 = (v103 * 2) + 1;
    int v106 = v104[v260];
    int v261 = ((((v45 + ((~(((v47 ^ -1) | (-(v47 ^ -1))) >> 31)) & 2)) - (v48 + ((~(((v49 ^ -1) | (-(v49 ^ -1))) >> 31)) & 2))) >> 31) & 1) * 2;
    v104[v261] = v105;
    int * v108 = v15->cache_vals;
    int v264 = (((((v45 + ((~(((v47 ^ -1) | (-(v47 ^ -1))) >> 31)) & 2)) - (v48 + ((~(((v49 ^ -1) | (-(v49 ^ -1))) >> 31)) & 2))) >> 31) & 1) * 2) + 1;
    v108[v264] = v106;
    int * v110 = v15->cache_tags;
    int v267 = (((v45 + ((~(((v47 ^ -1) | (-(v47 ^ -1))) >> 31)) & 2)) - (v48 + ((~(((v49 ^ -1) | (-(v49 ^ -1))) >> 31)) & 2))) >> 31) & 1;
    v110[v267] = 6;
    int * v112 = v15->cache_dirty;
    v112[v267] = 0;
    int * v114 = v15->cache_age;
    v114[v267] = 1;
    int * v116 = v15->cache_age;
    int v117 = v116[v267];
    int v118 = v116[0];
    int v272 = v118 + ((int)((unsigned int)(v118 - v117) >> 31));
    v116[0] = v272;
    int * v120 = v15->cache_age;
    int v121 = v120[1];
    int v274 = v121 + ((int)((unsigned int)(v121 - v117) >> 31));
    v120[1] = v274;
    int * v123 = v15->cache_age;
    v123[v267] = 0;
    v126 = v267;
  }
  int * v127 = v15->cache_vals;
  int v277 = (v126 * 2) + 1;
  v127[v277] = v19;
  int * v129 = v15->cache_tags;
  int v130 = v129[8];
  int v131 = v129[9];
  bool v280 = !(((~(((v130 ^ 6) | (-(v130 ^ 6))) >> 31)) | (~(((v131 ^ 6) | (-(v131 ^ 6))) >> 31))) == 0);
  int v185;
  if (v280) {
    int * v132 = v15->cache_age;
    int v282 = 8 + ((~(((v131 ^ 6) | (-(v131 ^ 6))) >> 31)) & 1);
    int v133 = v132[v282];
    int v134 = v132[8];
    int v283 = v134 + ((int)((unsigned int)(v134 - v133) >> 31));
    v132[8] = v283;
    int * v136 = v15->cache_age;
    int v137 = v136[9];
    int v285 = v137 + ((int)((unsigned int)(v137 - v133) >> 31));
    v136[9] = v285;
    int * v139 = v15->cache_age;
    v139[v282] = 0;
    v185 = v282;
  } else {
    int * v142 = v15->cache_age;
    int v143 = v142[8];
    int * v144 = v15->cache_tags;
    int v145 = v144[8];
    int v146 = v142[9];
    int v147 = v144[9];
    int * v148 = v15->cache_dirty;
    int v290 = 8 + ((((v143 + ((~(((v145 ^ -1) | (-(v145 ^ -1))) >> 31)) & 2)) - (v146 + ((~(((v147 ^ -1) | (-(v147 ^ -1))) >> 31)) & 2))) >> 31) & 1);
    int v149 = v148[v290];
    bool v291 = !(v149 == 0);
    if (v291) {
      int * v150 = v15->cache_tags;
      int v151 = v150[v290];
      int * v152 = v15->cache_vals;
      int v294 = (8 + ((((v143 + ((~(((v145 ^ -1) | (-(v145 ^ -1))) >> 31)) & 2)) - (v146 + ((~(((v147 ^ -1) | (-(v147 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
      int v153 = v152[v294];
      int v295 = ((8 + ((((v143 + ((~(((v145 ^ -1) | (-(v145 ^ -1))) >> 31)) & 2)) - (v146 + ((~(((v147 ^ -1) | (-(v147 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
      int v154 = v152[v295];
      int * v155 = v15->mem;
      int v297 = v151 * 2;
      v155[v297] = v153;
      int * v157 = v15->mem;
      int v300 = (v151 * 2) + 1;
      v157[v300] = v154;
      ;
    } else {
      ;
    }
    int * v162 = v15->mem;
    int v163 = v162[12];
    int v164 = v162[13];
    int * v165 = v15->cache_vals;
    int v308 = (8 + ((((v143 + ((~(((v145 ^ -1) | (-(v145 ^ -1))) >> 31)) & 2)) - (v146 + ((~(((v147 ^ -1) | (-(v147 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
    v165[v308] = v163;
    int * v167 = v15->cache_vals;
    int v311 = ((8 + ((((v143 + ((~(((v145 ^ -1) | (-(v145 ^ -1))) >> 31)) & 2)) - (v146 + ((~(((v147 ^ -1) | (-(v147 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
    v167[v311] = v164;
    int * v169 = v15->cache_tags;
    v169[v290] = 6;
    int * v171 = v15->cache_dirty;
    v171[v290] = 0;
    int * v173 = v15->cache_age;
    v173[v290] = 1;
    int * v175 = v15->cache_age;
    int v176 = v175[v290];
    int v177 = v175[8];
    int v318 = v177 + ((int)((unsigned int)(v177 - v176) >> 31));
    v175[8] = v318;
    int * v179 = v15->cache_age;
    int v180 = v179[9];
    int v320 = v180 + ((int)((unsigned int)(v180 - v176) >> 31));
    v179[9] = v320;
    int * v182 = v15->cache_age;
    v182[v290] = 0;
    v185 = v290;
  }
  int * v186 = v15->cache_vals;
  int v323 = (v185 * 2) + 1;
  v186[v323] = v19;
  int * v188 = v15->cache_dirty;
  v188[v185] = 1;
  struct StateT * v190 = slot_3(v15);
  return v190;
}

struct StateT * slot_6(struct StateT * v1490) {
  int v1491 = v1490->timer;
  int v1601 = v1491 + 1;
  v1490->timer = v1601;
  int * v1493 = v1490->regs;
  int v1494 = v1493[9];
  int * v1495 = v1490->cache_tags;
  int v1605 = (((int)((unsigned int)((int)((unsigned int)v1494 >> 2)) >> 1)) & 1) * 2;
  int v1496 = v1495[v1605];
  int v1606 = ((((int)((unsigned int)((int)((unsigned int)v1494 >> 2)) >> 1)) & 1) * 2) + 1;
  int v1497 = v1495[v1606];
  int v1607 = 4 + ((((int)((unsigned int)((int)((unsigned int)v1494 >> 2)) >> 1)) & 3) * 2);
  int v1498 = v1495[v1607];
  int v1608 = (4 + ((((int)((unsigned int)((int)((unsigned int)v1494 >> 2)) >> 1)) & 3) * 2)) + 1;
  int v1499 = v1495[v1608];
  int v1500 = v1490->timer;
  int v1609 = v1500 + ((100 ^ (((~(((v1498 ^ ((int)((unsigned int)((int)((unsigned int)v1494 >> 2)) >> 1))) | (-(v1498 ^ ((int)((unsigned int)((int)((unsigned int)v1494 >> 2)) >> 1))))) >> 31)) | (~(((v1499 ^ ((int)((unsigned int)((int)((unsigned int)v1494 >> 2)) >> 1))) | (-(v1499 ^ ((int)((unsigned int)((int)((unsigned int)v1494 >> 2)) >> 1))))) >> 31))) & 104)) ^ (((~(((v1496 ^ ((int)((unsigned int)((int)((unsigned int)v1494 >> 2)) >> 1))) | (-(v1496 ^ ((int)((unsigned int)((int)((unsigned int)v1494 >> 2)) >> 1))))) >> 31)) | (~(((v1497 ^ ((int)((unsigned int)((int)((unsigned int)v1494 >> 2)) >> 1))) | (-(v1497 ^ ((int)((unsigned int)((int)((unsigned int)v1494 >> 2)) >> 1))))) >> 31))) & (1 ^ (100 ^ (((~(((v1498 ^ ((int)((unsigned int)((int)((unsigned int)v1494 >> 2)) >> 1))) | (-(v1498 ^ ((int)((unsigned int)((int)((unsigned int)v1494 >> 2)) >> 1))))) >> 31)) | (~(((v1499 ^ ((int)((unsigned int)((int)((unsigned int)v1494 >> 2)) >> 1))) | (-(v1499 ^ ((int)((unsigned int)((int)((unsigned int)v1494 >> 2)) >> 1))))) >> 31))) & 104)))));
  v1490->timer = v1609;
  int * v1502 = v1490->cache_vals;
  bool v1610 = !(((~(((v1496 ^ ((int)((unsigned int)((int)((unsigned int)v1494 >> 2)) >> 1))) | (-(v1496 ^ ((int)((unsigned int)((int)((unsigned int)v1494 >> 2)) >> 1))))) >> 31)) | (~(((v1497 ^ ((int)((unsigned int)((int)((unsigned int)v1494 >> 2)) >> 1))) | (-(v1497 ^ ((int)((unsigned int)((int)((unsigned int)v1494 >> 2)) >> 1))))) >> 31))) == 0);
  int v1595;
  if (v1610) {
    int * v1503 = v1490->cache_age;
    int v1612 = ((((int)((unsigned int)((int)((unsigned int)v1494 >> 2)) >> 1)) & 1) * 2) + ((~(((v1497 ^ ((int)((unsigned int)((int)((unsigned int)v1494 >> 2)) >> 1))) | (-(v1497 ^ ((int)((unsigned int)((int)((unsigned int)v1494 >> 2)) >> 1))))) >> 31)) & 1);
    int v1504 = v1503[v1612];
    int v1505 = v1503[v1605];
    int v1613 = v1505 + ((int)((unsigned int)(v1505 - v1504) >> 31));
    v1503[v1605] = v1613;
    int * v1507 = v1490->cache_age;
    int v1508 = v1507[v1606];
    int v1615 = v1508 + ((int)((unsigned int)(v1508 - v1504) >> 31));
    v1507[v1606] = v1615;
    int * v1510 = v1490->cache_age;
    v1510[v1612] = 0;
    v1595 = v1612;
  } else {
    int * v1513 = v1490->cache_age;
    int v1619 = (((int)((unsigned int)((int)((unsigned int)v1494 >> 2)) >> 1)) & 1) * 2;
    int v1514 = v1513[v1619];
    int * v1515 = v1490->cache_tags;
    int v1516 = v1515[v1619];
    int v1517 = v1513[v1606];
    int v1518 = v1515[v1606];
    bool v1621 = !(((~(((v1498 ^ ((int)((unsigned int)((int)((unsigned int)v1494 >> 2)) >> 1))) | (-(v1498 ^ ((int)((unsigned int)((int)((unsigned int)v1494 >> 2)) >> 1))))) >> 31)) | (~(((v1499 ^ ((int)((unsigned int)((int)((unsigned int)v1494 >> 2)) >> 1))) | (-(v1499 ^ ((int)((unsigned int)((int)((unsigned int)v1494 >> 2)) >> 1))))) >> 31))) == 0);
    int v1572;
    if (v1621) {
      int * v1519 = v1490->cache_age;
      int v1623 = (4 + ((((int)((unsigned int)((int)((unsigned int)v1494 >> 2)) >> 1)) & 3) * 2)) + ((~(((v1499 ^ ((int)((unsigned int)((int)((unsigned int)v1494 >> 2)) >> 1))) | (-(v1499 ^ ((int)((unsigned int)((int)((unsigned int)v1494 >> 2)) >> 1))))) >> 31)) & 1);
      int v1520 = v1519[v1623];
      int v1521 = v1519[v1607];
      int v1624 = v1521 + ((int)((unsigned int)(v1521 - v1520) >> 31));
      v1519[v1607] = v1624;
      int * v1523 = v1490->cache_age;
      int v1524 = v1523[v1608];
      int v1626 = v1524 + ((int)((unsigned int)(v1524 - v1520) >> 31));
      v1523[v1608] = v1626;
      int * v1526 = v1490->cache_age;
      v1526[v1623] = 0;
      v1572 = v1623;
    } else {
      int * v1529 = v1490->cache_age;
      int v1630 = 4 + ((((int)((unsigned int)((int)((unsigned int)v1494 >> 2)) >> 1)) & 3) * 2);
      int v1530 = v1529[v1630];
      int * v1531 = v1490->cache_tags;
      int v1532 = v1531[v1630];
      int v1533 = v1529[v1608];
      int v1534 = v1531[v1608];
      int * v1535 = v1490->cache_dirty;
      int v1633 = (4 + ((((int)((unsigned int)((int)((unsigned int)v1494 >> 2)) >> 1)) & 3) * 2)) + ((((v1530 + ((~(((v1532 ^ -1) | (-(v1532 ^ -1))) >> 31)) & 2)) - (v1533 + ((~(((v1534 ^ -1) | (-(v1534 ^ -1))) >> 31)) & 2))) >> 31) & 1);
      int v1536 = v1535[v1633];
      bool v1634 = !(v1536 == 0);
      if (v1634) {
        int * v1537 = v1490->cache_tags;
        int v1538 = v1537[v1633];
        int * v1539 = v1490->cache_vals;
        int v1637 = ((4 + ((((int)((unsigned int)((int)((unsigned int)v1494 >> 2)) >> 1)) & 3) * 2)) + ((((v1530 + ((~(((v1532 ^ -1) | (-(v1532 ^ -1))) >> 31)) & 2)) - (v1533 + ((~(((v1534 ^ -1) | (-(v1534 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
        int v1540 = v1539[v1637];
        int v1638 = (((4 + ((((int)((unsigned int)((int)((unsigned int)v1494 >> 2)) >> 1)) & 3) * 2)) + ((((v1530 + ((~(((v1532 ^ -1) | (-(v1532 ^ -1))) >> 31)) & 2)) - (v1533 + ((~(((v1534 ^ -1) | (-(v1534 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
        int v1541 = v1539[v1638];
        int * v1542 = v1490->mem;
        int v1640 = v1538 * 2;
        v1542[v1640] = v1540;
        int * v1544 = v1490->mem;
        int v1643 = (v1538 * 2) + 1;
        v1544[v1643] = v1541;
        ;
      } else {
        ;
      }
      int * v1549 = v1490->mem;
      int v1648 = ((int)((unsigned int)((int)((unsigned int)v1494 >> 2)) >> 1)) * 2;
      int v1550 = v1549[v1648];
      int v1649 = (((int)((unsigned int)((int)((unsigned int)v1494 >> 2)) >> 1)) * 2) + 1;
      int v1551 = v1549[v1649];
      int * v1552 = v1490->cache_vals;
      int v1651 = ((4 + ((((int)((unsigned int)((int)((unsigned int)v1494 >> 2)) >> 1)) & 3) * 2)) + ((((v1530 + ((~(((v1532 ^ -1) | (-(v1532 ^ -1))) >> 31)) & 2)) - (v1533 + ((~(((v1534 ^ -1) | (-(v1534 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
      v1552[v1651] = v1550;
      int * v1554 = v1490->cache_vals;
      int v1654 = (((4 + ((((int)((unsigned int)((int)((unsigned int)v1494 >> 2)) >> 1)) & 3) * 2)) + ((((v1530 + ((~(((v1532 ^ -1) | (-(v1532 ^ -1))) >> 31)) & 2)) - (v1533 + ((~(((v1534 ^ -1) | (-(v1534 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
      v1554[v1654] = v1551;
      int * v1556 = v1490->cache_tags;
      int v1657 = (int)((unsigned int)((int)((unsigned int)v1494 >> 2)) >> 1);
      v1556[v1633] = v1657;
      int * v1558 = v1490->cache_dirty;
      v1558[v1633] = 0;
      int * v1560 = v1490->cache_age;
      v1560[v1633] = 1;
      int * v1562 = v1490->cache_age;
      int v1563 = v1562[v1633];
      int v1564 = v1562[v1607];
      int v1663 = v1564 + ((int)((unsigned int)(v1564 - v1563) >> 31));
      v1562[v1607] = v1663;
      int * v1566 = v1490->cache_age;
      int v1567 = v1566[v1608];
      int v1665 = v1567 + ((int)((unsigned int)(v1567 - v1563) >> 31));
      v1566[v1608] = v1665;
      int * v1569 = v1490->cache_age;
      v1569[v1633] = 0;
      v1572 = v1633;
    }
    int * v1573 = v1490->cache_vals;
    int v1668 = v1572 * 2;
    int v1574 = v1573[v1668];
    int v1669 = (v1572 * 2) + 1;
    int v1575 = v1573[v1669];
    int v1670 = (((((int)((unsigned int)((int)((unsigned int)v1494 >> 2)) >> 1)) & 1) * 2) + ((((v1514 + ((~(((v1516 ^ -1) | (-(v1516 ^ -1))) >> 31)) & 2)) - (v1517 + ((~(((v1518 ^ -1) | (-(v1518 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
    v1573[v1670] = v1574;
    int * v1577 = v1490->cache_vals;
    int v1673 = ((((((int)((unsigned int)((int)((unsigned int)v1494 >> 2)) >> 1)) & 1) * 2) + ((((v1514 + ((~(((v1516 ^ -1) | (-(v1516 ^ -1))) >> 31)) & 2)) - (v1517 + ((~(((v1518 ^ -1) | (-(v1518 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
    v1577[v1673] = v1575;
    int * v1579 = v1490->cache_tags;
    int v1676 = ((((int)((unsigned int)((int)((unsigned int)v1494 >> 2)) >> 1)) & 1) * 2) + ((((v1514 + ((~(((v1516 ^ -1) | (-(v1516 ^ -1))) >> 31)) & 2)) - (v1517 + ((~(((v1518 ^ -1) | (-(v1518 ^ -1))) >> 31)) & 2))) >> 31) & 1);
    int v1677 = (int)((unsigned int)((int)((unsigned int)v1494 >> 2)) >> 1);
    v1579[v1676] = v1677;
    int * v1581 = v1490->cache_dirty;
    v1581[v1676] = 0;
    int * v1583 = v1490->cache_age;
    v1583[v1676] = 1;
    int * v1585 = v1490->cache_age;
    int v1586 = v1585[v1676];
    int v1587 = v1585[v1605];
    int v1683 = v1587 + ((int)((unsigned int)(v1587 - v1586) >> 31));
    v1585[v1605] = v1683;
    int * v1589 = v1490->cache_age;
    int v1590 = v1589[v1606];
    int v1685 = v1590 + ((int)((unsigned int)(v1590 - v1586) >> 31));
    v1589[v1606] = v1685;
    int * v1592 = v1490->cache_age;
    v1592[v1676] = 0;
    v1595 = v1676;
  }
  int v1688 = (v1595 * 2) + (((int)((unsigned int)v1494 >> 2)) & 1);
  int v1596 = v1502[v1688];
  int * v1597 = v1490->regs;
  v1597[11] = v1596;
  struct StateT * v1599 = slot_7(v1490);
  return v1599;
}

struct StateT * slot_5(struct StateT * v1473) {
  int v1474 = v1473->timer;
  int v1482 = v1474 + 1;
  v1473->timer = v1482;
  int * v1476 = v1473->regs;
  int v1477 = v1476[10];
  int v1478 = v1476[8];
  int v1487 = v1477 & v1478;
  v1476[9] = v1487;
  struct StateT * v1480 = slot_6(v1473);
  return v1480;
}

struct StateT * slot_4(struct StateT * v1282) {
  int v1283 = v1282->timer;
  int v1391 = v1283 + 1;
  v1282->timer = v1391;
  int * v1285 = v1282->cache_tags;
  int v1286 = v1285[0];
  int v1287 = v1285[1];
  int v1288 = v1285[8];
  int v1289 = v1285[9];
  int v1290 = v1282->timer;
  int v1397 = v1290 + ((100 ^ (((~(((v1288 ^ 6) | (-(v1288 ^ 6))) >> 31)) | (~(((v1289 ^ 6) | (-(v1289 ^ 6))) >> 31))) & 104)) ^ (((~(((v1286 ^ 6) | (-(v1286 ^ 6))) >> 31)) | (~(((v1287 ^ 6) | (-(v1287 ^ 6))) >> 31))) & (1 ^ (100 ^ (((~(((v1288 ^ 6) | (-(v1288 ^ 6))) >> 31)) | (~(((v1289 ^ 6) | (-(v1289 ^ 6))) >> 31))) & 104)))));
  v1282->timer = v1397;
  int * v1292 = v1282->cache_vals;
  bool v1398 = !(((~(((v1286 ^ 6) | (-(v1286 ^ 6))) >> 31)) | (~(((v1287 ^ 6) | (-(v1287 ^ 6))) >> 31))) == 0);
  int v1385;
  if (v1398) {
    int * v1293 = v1282->cache_age;
    int v1400 = (~(((v1287 ^ 6) | (-(v1287 ^ 6))) >> 31)) & 1;
    int v1294 = v1293[v1400];
    int v1295 = v1293[0];
    int v1401 = v1295 + ((int)((unsigned int)(v1295 - v1294) >> 31));
    v1293[0] = v1401;
    int * v1297 = v1282->cache_age;
    int v1298 = v1297[1];
    int v1403 = v1298 + ((int)((unsigned int)(v1298 - v1294) >> 31));
    v1297[1] = v1403;
    int * v1300 = v1282->cache_age;
    v1300[v1400] = 0;
    v1385 = v1400;
  } else {
    int * v1303 = v1282->cache_age;
    int v1304 = v1303[0];
    int * v1305 = v1282->cache_tags;
    int v1306 = v1305[0];
    int v1307 = v1303[1];
    int v1308 = v1305[1];
    bool v1407 = !(((~(((v1288 ^ 6) | (-(v1288 ^ 6))) >> 31)) | (~(((v1289 ^ 6) | (-(v1289 ^ 6))) >> 31))) == 0);
    int v1362;
    if (v1407) {
      int * v1309 = v1282->cache_age;
      int v1409 = 8 + ((~(((v1289 ^ 6) | (-(v1289 ^ 6))) >> 31)) & 1);
      int v1310 = v1309[v1409];
      int v1311 = v1309[8];
      int v1410 = v1311 + ((int)((unsigned int)(v1311 - v1310) >> 31));
      v1309[8] = v1410;
      int * v1313 = v1282->cache_age;
      int v1314 = v1313[9];
      int v1412 = v1314 + ((int)((unsigned int)(v1314 - v1310) >> 31));
      v1313[9] = v1412;
      int * v1316 = v1282->cache_age;
      v1316[v1409] = 0;
      v1362 = v1409;
    } else {
      int * v1319 = v1282->cache_age;
      int v1320 = v1319[8];
      int * v1321 = v1282->cache_tags;
      int v1322 = v1321[8];
      int v1323 = v1319[9];
      int v1324 = v1321[9];
      int * v1325 = v1282->cache_dirty;
      int v1417 = 8 + ((((v1320 + ((~(((v1322 ^ -1) | (-(v1322 ^ -1))) >> 31)) & 2)) - (v1323 + ((~(((v1324 ^ -1) | (-(v1324 ^ -1))) >> 31)) & 2))) >> 31) & 1);
      int v1326 = v1325[v1417];
      bool v1418 = !(v1326 == 0);
      if (v1418) {
        int * v1327 = v1282->cache_tags;
        int v1328 = v1327[v1417];
        int * v1329 = v1282->cache_vals;
        int v1421 = (8 + ((((v1320 + ((~(((v1322 ^ -1) | (-(v1322 ^ -1))) >> 31)) & 2)) - (v1323 + ((~(((v1324 ^ -1) | (-(v1324 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
        int v1330 = v1329[v1421];
        int v1422 = ((8 + ((((v1320 + ((~(((v1322 ^ -1) | (-(v1322 ^ -1))) >> 31)) & 2)) - (v1323 + ((~(((v1324 ^ -1) | (-(v1324 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
        int v1331 = v1329[v1422];
        int * v1332 = v1282->mem;
        int v1424 = v1328 * 2;
        v1332[v1424] = v1330;
        int * v1334 = v1282->mem;
        int v1427 = (v1328 * 2) + 1;
        v1334[v1427] = v1331;
        ;
      } else {
        ;
      }
      int * v1339 = v1282->mem;
      int v1340 = v1339[12];
      int v1341 = v1339[13];
      int * v1342 = v1282->cache_vals;
      int v1435 = (8 + ((((v1320 + ((~(((v1322 ^ -1) | (-(v1322 ^ -1))) >> 31)) & 2)) - (v1323 + ((~(((v1324 ^ -1) | (-(v1324 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
      v1342[v1435] = v1340;
      int * v1344 = v1282->cache_vals;
      int v1438 = ((8 + ((((v1320 + ((~(((v1322 ^ -1) | (-(v1322 ^ -1))) >> 31)) & 2)) - (v1323 + ((~(((v1324 ^ -1) | (-(v1324 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
      v1344[v1438] = v1341;
      int * v1346 = v1282->cache_tags;
      v1346[v1417] = 6;
      int * v1348 = v1282->cache_dirty;
      v1348[v1417] = 0;
      int * v1350 = v1282->cache_age;
      v1350[v1417] = 1;
      int * v1352 = v1282->cache_age;
      int v1353 = v1352[v1417];
      int v1354 = v1352[8];
      int v1445 = v1354 + ((int)((unsigned int)(v1354 - v1353) >> 31));
      v1352[8] = v1445;
      int * v1356 = v1282->cache_age;
      int v1357 = v1356[9];
      int v1447 = v1357 + ((int)((unsigned int)(v1357 - v1353) >> 31));
      v1356[9] = v1447;
      int * v1359 = v1282->cache_age;
      v1359[v1417] = 0;
      v1362 = v1417;
    }
    int * v1363 = v1282->cache_vals;
    int v1450 = v1362 * 2;
    int v1364 = v1363[v1450];
    int v1451 = (v1362 * 2) + 1;
    int v1365 = v1363[v1451];
    int v1452 = ((((v1304 + ((~(((v1306 ^ -1) | (-(v1306 ^ -1))) >> 31)) & 2)) - (v1307 + ((~(((v1308 ^ -1) | (-(v1308 ^ -1))) >> 31)) & 2))) >> 31) & 1) * 2;
    v1363[v1452] = v1364;
    int * v1367 = v1282->cache_vals;
    int v1455 = (((((v1304 + ((~(((v1306 ^ -1) | (-(v1306 ^ -1))) >> 31)) & 2)) - (v1307 + ((~(((v1308 ^ -1) | (-(v1308 ^ -1))) >> 31)) & 2))) >> 31) & 1) * 2) + 1;
    v1367[v1455] = v1365;
    int * v1369 = v1282->cache_tags;
    int v1458 = (((v1304 + ((~(((v1306 ^ -1) | (-(v1306 ^ -1))) >> 31)) & 2)) - (v1307 + ((~(((v1308 ^ -1) | (-(v1308 ^ -1))) >> 31)) & 2))) >> 31) & 1;
    v1369[v1458] = 6;
    int * v1371 = v1282->cache_dirty;
    v1371[v1458] = 0;
    int * v1373 = v1282->cache_age;
    v1373[v1458] = 1;
    int * v1375 = v1282->cache_age;
    int v1376 = v1375[v1458];
    int v1377 = v1375[0];
    int v1463 = v1377 + ((int)((unsigned int)(v1377 - v1376) >> 31));
    v1375[0] = v1463;
    int * v1379 = v1282->cache_age;
    int v1380 = v1379[1];
    int v1465 = v1380 + ((int)((unsigned int)(v1380 - v1376) >> 31));
    v1379[1] = v1465;
    int * v1382 = v1282->cache_age;
    v1382[v1458] = 0;
    v1385 = v1458;
  }
  int v1468 = (v1385 * 2) + 1;
  int v1386 = v1292[v1468];
  int * v1387 = v1282->regs;
  v1387[8] = v1386;
  struct StateT * v1389 = slot_5(v1282);
  return v1389;
}

struct StateT * slot_7(struct StateT * v1694) {
  int v1695 = v1694->timer;
  int v1804 = v1695 + 1;
  v1694->timer = v1804;
  int * v1697 = v1694->regs;
  int v1698 = v1697[11];
  int * v1699 = v1694->cache_tags;
  int v1808 = (((int)((unsigned int)((int)((unsigned int)v1698 >> 2)) >> 1)) & 1) * 2;
  int v1700 = v1699[v1808];
  int v1809 = ((((int)((unsigned int)((int)((unsigned int)v1698 >> 2)) >> 1)) & 1) * 2) + 1;
  int v1701 = v1699[v1809];
  int v1810 = 4 + ((((int)((unsigned int)((int)((unsigned int)v1698 >> 2)) >> 1)) & 3) * 2);
  int v1702 = v1699[v1810];
  int v1811 = (4 + ((((int)((unsigned int)((int)((unsigned int)v1698 >> 2)) >> 1)) & 3) * 2)) + 1;
  int v1703 = v1699[v1811];
  int v1704 = v1694->timer;
  int v1812 = v1704 + ((100 ^ (((~(((v1702 ^ ((int)((unsigned int)((int)((unsigned int)v1698 >> 2)) >> 1))) | (-(v1702 ^ ((int)((unsigned int)((int)((unsigned int)v1698 >> 2)) >> 1))))) >> 31)) | (~(((v1703 ^ ((int)((unsigned int)((int)((unsigned int)v1698 >> 2)) >> 1))) | (-(v1703 ^ ((int)((unsigned int)((int)((unsigned int)v1698 >> 2)) >> 1))))) >> 31))) & 104)) ^ (((~(((v1700 ^ ((int)((unsigned int)((int)((unsigned int)v1698 >> 2)) >> 1))) | (-(v1700 ^ ((int)((unsigned int)((int)((unsigned int)v1698 >> 2)) >> 1))))) >> 31)) | (~(((v1701 ^ ((int)((unsigned int)((int)((unsigned int)v1698 >> 2)) >> 1))) | (-(v1701 ^ ((int)((unsigned int)((int)((unsigned int)v1698 >> 2)) >> 1))))) >> 31))) & (1 ^ (100 ^ (((~(((v1702 ^ ((int)((unsigned int)((int)((unsigned int)v1698 >> 2)) >> 1))) | (-(v1702 ^ ((int)((unsigned int)((int)((unsigned int)v1698 >> 2)) >> 1))))) >> 31)) | (~(((v1703 ^ ((int)((unsigned int)((int)((unsigned int)v1698 >> 2)) >> 1))) | (-(v1703 ^ ((int)((unsigned int)((int)((unsigned int)v1698 >> 2)) >> 1))))) >> 31))) & 104)))));
  v1694->timer = v1812;
  int * v1706 = v1694->cache_vals;
  bool v1813 = !(((~(((v1700 ^ ((int)((unsigned int)((int)((unsigned int)v1698 >> 2)) >> 1))) | (-(v1700 ^ ((int)((unsigned int)((int)((unsigned int)v1698 >> 2)) >> 1))))) >> 31)) | (~(((v1701 ^ ((int)((unsigned int)((int)((unsigned int)v1698 >> 2)) >> 1))) | (-(v1701 ^ ((int)((unsigned int)((int)((unsigned int)v1698 >> 2)) >> 1))))) >> 31))) == 0);
  int v1799;
  if (v1813) {
    int * v1707 = v1694->cache_age;
    int v1815 = ((((int)((unsigned int)((int)((unsigned int)v1698 >> 2)) >> 1)) & 1) * 2) + ((~(((v1701 ^ ((int)((unsigned int)((int)((unsigned int)v1698 >> 2)) >> 1))) | (-(v1701 ^ ((int)((unsigned int)((int)((unsigned int)v1698 >> 2)) >> 1))))) >> 31)) & 1);
    int v1708 = v1707[v1815];
    int v1709 = v1707[v1808];
    int v1816 = v1709 + ((int)((unsigned int)(v1709 - v1708) >> 31));
    v1707[v1808] = v1816;
    int * v1711 = v1694->cache_age;
    int v1712 = v1711[v1809];
    int v1818 = v1712 + ((int)((unsigned int)(v1712 - v1708) >> 31));
    v1711[v1809] = v1818;
    int * v1714 = v1694->cache_age;
    v1714[v1815] = 0;
    v1799 = v1815;
  } else {
    int * v1717 = v1694->cache_age;
    int v1822 = (((int)((unsigned int)((int)((unsigned int)v1698 >> 2)) >> 1)) & 1) * 2;
    int v1718 = v1717[v1822];
    int * v1719 = v1694->cache_tags;
    int v1720 = v1719[v1822];
    int v1721 = v1717[v1809];
    int v1722 = v1719[v1809];
    bool v1824 = !(((~(((v1702 ^ ((int)((unsigned int)((int)((unsigned int)v1698 >> 2)) >> 1))) | (-(v1702 ^ ((int)((unsigned int)((int)((unsigned int)v1698 >> 2)) >> 1))))) >> 31)) | (~(((v1703 ^ ((int)((unsigned int)((int)((unsigned int)v1698 >> 2)) >> 1))) | (-(v1703 ^ ((int)((unsigned int)((int)((unsigned int)v1698 >> 2)) >> 1))))) >> 31))) == 0);
    int v1776;
    if (v1824) {
      int * v1723 = v1694->cache_age;
      int v1826 = (4 + ((((int)((unsigned int)((int)((unsigned int)v1698 >> 2)) >> 1)) & 3) * 2)) + ((~(((v1703 ^ ((int)((unsigned int)((int)((unsigned int)v1698 >> 2)) >> 1))) | (-(v1703 ^ ((int)((unsigned int)((int)((unsigned int)v1698 >> 2)) >> 1))))) >> 31)) & 1);
      int v1724 = v1723[v1826];
      int v1725 = v1723[v1810];
      int v1827 = v1725 + ((int)((unsigned int)(v1725 - v1724) >> 31));
      v1723[v1810] = v1827;
      int * v1727 = v1694->cache_age;
      int v1728 = v1727[v1811];
      int v1829 = v1728 + ((int)((unsigned int)(v1728 - v1724) >> 31));
      v1727[v1811] = v1829;
      int * v1730 = v1694->cache_age;
      v1730[v1826] = 0;
      v1776 = v1826;
    } else {
      int * v1733 = v1694->cache_age;
      int v1833 = 4 + ((((int)((unsigned int)((int)((unsigned int)v1698 >> 2)) >> 1)) & 3) * 2);
      int v1734 = v1733[v1833];
      int * v1735 = v1694->cache_tags;
      int v1736 = v1735[v1833];
      int v1737 = v1733[v1811];
      int v1738 = v1735[v1811];
      int * v1739 = v1694->cache_dirty;
      int v1836 = (4 + ((((int)((unsigned int)((int)((unsigned int)v1698 >> 2)) >> 1)) & 3) * 2)) + ((((v1734 + ((~(((v1736 ^ -1) | (-(v1736 ^ -1))) >> 31)) & 2)) - (v1737 + ((~(((v1738 ^ -1) | (-(v1738 ^ -1))) >> 31)) & 2))) >> 31) & 1);
      int v1740 = v1739[v1836];
      bool v1837 = !(v1740 == 0);
      if (v1837) {
        int * v1741 = v1694->cache_tags;
        int v1742 = v1741[v1836];
        int * v1743 = v1694->cache_vals;
        int v1840 = ((4 + ((((int)((unsigned int)((int)((unsigned int)v1698 >> 2)) >> 1)) & 3) * 2)) + ((((v1734 + ((~(((v1736 ^ -1) | (-(v1736 ^ -1))) >> 31)) & 2)) - (v1737 + ((~(((v1738 ^ -1) | (-(v1738 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
        int v1744 = v1743[v1840];
        int v1841 = (((4 + ((((int)((unsigned int)((int)((unsigned int)v1698 >> 2)) >> 1)) & 3) * 2)) + ((((v1734 + ((~(((v1736 ^ -1) | (-(v1736 ^ -1))) >> 31)) & 2)) - (v1737 + ((~(((v1738 ^ -1) | (-(v1738 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
        int v1745 = v1743[v1841];
        int * v1746 = v1694->mem;
        int v1843 = v1742 * 2;
        v1746[v1843] = v1744;
        int * v1748 = v1694->mem;
        int v1846 = (v1742 * 2) + 1;
        v1748[v1846] = v1745;
        ;
      } else {
        ;
      }
      int * v1753 = v1694->mem;
      int v1851 = ((int)((unsigned int)((int)((unsigned int)v1698 >> 2)) >> 1)) * 2;
      int v1754 = v1753[v1851];
      int v1852 = (((int)((unsigned int)((int)((unsigned int)v1698 >> 2)) >> 1)) * 2) + 1;
      int v1755 = v1753[v1852];
      int * v1756 = v1694->cache_vals;
      int v1854 = ((4 + ((((int)((unsigned int)((int)((unsigned int)v1698 >> 2)) >> 1)) & 3) * 2)) + ((((v1734 + ((~(((v1736 ^ -1) | (-(v1736 ^ -1))) >> 31)) & 2)) - (v1737 + ((~(((v1738 ^ -1) | (-(v1738 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
      v1756[v1854] = v1754;
      int * v1758 = v1694->cache_vals;
      int v1857 = (((4 + ((((int)((unsigned int)((int)((unsigned int)v1698 >> 2)) >> 1)) & 3) * 2)) + ((((v1734 + ((~(((v1736 ^ -1) | (-(v1736 ^ -1))) >> 31)) & 2)) - (v1737 + ((~(((v1738 ^ -1) | (-(v1738 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
      v1758[v1857] = v1755;
      int * v1760 = v1694->cache_tags;
      int v1860 = (int)((unsigned int)((int)((unsigned int)v1698 >> 2)) >> 1);
      v1760[v1836] = v1860;
      int * v1762 = v1694->cache_dirty;
      v1762[v1836] = 0;
      int * v1764 = v1694->cache_age;
      v1764[v1836] = 1;
      int * v1766 = v1694->cache_age;
      int v1767 = v1766[v1836];
      int v1768 = v1766[v1810];
      int v1866 = v1768 + ((int)((unsigned int)(v1768 - v1767) >> 31));
      v1766[v1810] = v1866;
      int * v1770 = v1694->cache_age;
      int v1771 = v1770[v1811];
      int v1868 = v1771 + ((int)((unsigned int)(v1771 - v1767) >> 31));
      v1770[v1811] = v1868;
      int * v1773 = v1694->cache_age;
      v1773[v1836] = 0;
      v1776 = v1836;
    }
    int * v1777 = v1694->cache_vals;
    int v1871 = v1776 * 2;
    int v1778 = v1777[v1871];
    int v1872 = (v1776 * 2) + 1;
    int v1779 = v1777[v1872];
    int v1873 = (((((int)((unsigned int)((int)((unsigned int)v1698 >> 2)) >> 1)) & 1) * 2) + ((((v1718 + ((~(((v1720 ^ -1) | (-(v1720 ^ -1))) >> 31)) & 2)) - (v1721 + ((~(((v1722 ^ -1) | (-(v1722 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
    v1777[v1873] = v1778;
    int * v1781 = v1694->cache_vals;
    int v1876 = ((((((int)((unsigned int)((int)((unsigned int)v1698 >> 2)) >> 1)) & 1) * 2) + ((((v1718 + ((~(((v1720 ^ -1) | (-(v1720 ^ -1))) >> 31)) & 2)) - (v1721 + ((~(((v1722 ^ -1) | (-(v1722 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
    v1781[v1876] = v1779;
    int * v1783 = v1694->cache_tags;
    int v1879 = ((((int)((unsigned int)((int)((unsigned int)v1698 >> 2)) >> 1)) & 1) * 2) + ((((v1718 + ((~(((v1720 ^ -1) | (-(v1720 ^ -1))) >> 31)) & 2)) - (v1721 + ((~(((v1722 ^ -1) | (-(v1722 ^ -1))) >> 31)) & 2))) >> 31) & 1);
    int v1880 = (int)((unsigned int)((int)((unsigned int)v1698 >> 2)) >> 1);
    v1783[v1879] = v1880;
    int * v1785 = v1694->cache_dirty;
    v1785[v1879] = 0;
    int * v1787 = v1694->cache_age;
    v1787[v1879] = 1;
    int * v1789 = v1694->cache_age;
    int v1790 = v1789[v1879];
    int v1791 = v1789[v1808];
    int v1886 = v1791 + ((int)((unsigned int)(v1791 - v1790) >> 31));
    v1789[v1808] = v1886;
    int * v1793 = v1694->cache_age;
    int v1794 = v1793[v1809];
    int v1888 = v1794 + ((int)((unsigned int)(v1794 - v1790) >> 31));
    v1793[v1809] = v1888;
    int * v1796 = v1694->cache_age;
    v1796[v1879] = 0;
    v1799 = v1879;
  }
  int v1891 = (v1799 * 2) + (((int)((unsigned int)v1698 >> 2)) & 1);
  int v1800 = v1706[v1891];
  int * v1801 = v1694->regs;
  v1801[12] = v1800;
  return v1694;
}

struct StateT * slot_3(struct StateT * v328) {
  int v329 = v328->timer;
  int v872 = v329 + 1;
  v328->timer = v872;
  int * v331 = v328->regs;
  int v332 = v331[7];
  int * v333 = v328->saved_regs;
  int v334 = v331[8];
  v333[8] = v334;
  int v336 = v328->timer;
  int v878 = v336 + 1;
  v328->timer = v878;
  int * v338 = v328->cache_tags;
  int v339 = v338[0];
  int v340 = v338[1];
  int v341 = v338[8];
  int v342 = v338[9];
  int v343 = v328->timer;
  int v883 = v343 + ((100 ^ (((~(((v341 ^ 6) | (-(v341 ^ 6))) >> 31)) | (~(((v342 ^ 6) | (-(v342 ^ 6))) >> 31))) & 104)) ^ (((~(((v339 ^ 6) | (-(v339 ^ 6))) >> 31)) | (~(((v340 ^ 6) | (-(v340 ^ 6))) >> 31))) & (1 ^ (100 ^ (((~(((v341 ^ 6) | (-(v341 ^ 6))) >> 31)) | (~(((v342 ^ 6) | (-(v342 ^ 6))) >> 31))) & 104)))));
  v328->timer = v883;
  int * v345 = v328->cache_vals;
  bool v884 = !(((~(((v339 ^ 6) | (-(v339 ^ 6))) >> 31)) | (~(((v340 ^ 6) | (-(v340 ^ 6))) >> 31))) == 0);
  int v438;
  if (v884) {
    int * v346 = v328->cache_age;
    int v886 = (~(((v340 ^ 6) | (-(v340 ^ 6))) >> 31)) & 1;
    int v347 = v346[v886];
    int v348 = v346[0];
    int v887 = v348 + ((int)((unsigned int)(v348 - v347) >> 31));
    v346[0] = v887;
    int * v350 = v328->cache_age;
    int v351 = v350[1];
    int v889 = v351 + ((int)((unsigned int)(v351 - v347) >> 31));
    v350[1] = v889;
    int * v353 = v328->cache_age;
    v353[v886] = 0;
    v438 = v886;
  } else {
    int * v356 = v328->cache_age;
    int v357 = v356[0];
    int * v358 = v328->cache_tags;
    int v359 = v358[0];
    int v360 = v356[1];
    int v361 = v358[1];
    bool v893 = !(((~(((v341 ^ 6) | (-(v341 ^ 6))) >> 31)) | (~(((v342 ^ 6) | (-(v342 ^ 6))) >> 31))) == 0);
    int v415;
    if (v893) {
      int * v362 = v328->cache_age;
      int v895 = 8 + ((~(((v342 ^ 6) | (-(v342 ^ 6))) >> 31)) & 1);
      int v363 = v362[v895];
      int v364 = v362[8];
      int v896 = v364 + ((int)((unsigned int)(v364 - v363) >> 31));
      v362[8] = v896;
      int * v366 = v328->cache_age;
      int v367 = v366[9];
      int v898 = v367 + ((int)((unsigned int)(v367 - v363) >> 31));
      v366[9] = v898;
      int * v369 = v328->cache_age;
      v369[v895] = 0;
      v415 = v895;
    } else {
      int * v372 = v328->cache_age;
      int v373 = v372[8];
      int * v374 = v328->cache_tags;
      int v375 = v374[8];
      int v376 = v372[9];
      int v377 = v374[9];
      int * v378 = v328->cache_dirty;
      int v903 = 8 + ((((v373 + ((~(((v375 ^ -1) | (-(v375 ^ -1))) >> 31)) & 2)) - (v376 + ((~(((v377 ^ -1) | (-(v377 ^ -1))) >> 31)) & 2))) >> 31) & 1);
      int v379 = v378[v903];
      bool v904 = !(v379 == 0);
      if (v904) {
        int * v380 = v328->cache_tags;
        int v381 = v380[v903];
        int * v382 = v328->cache_vals;
        int v907 = (8 + ((((v373 + ((~(((v375 ^ -1) | (-(v375 ^ -1))) >> 31)) & 2)) - (v376 + ((~(((v377 ^ -1) | (-(v377 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
        int v383 = v382[v907];
        int v908 = ((8 + ((((v373 + ((~(((v375 ^ -1) | (-(v375 ^ -1))) >> 31)) & 2)) - (v376 + ((~(((v377 ^ -1) | (-(v377 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
        int v384 = v382[v908];
        int * v385 = v328->mem;
        int v910 = v381 * 2;
        v385[v910] = v383;
        int * v387 = v328->mem;
        int v913 = (v381 * 2) + 1;
        v387[v913] = v384;
        ;
      } else {
        ;
      }
      int * v392 = v328->mem;
      int v393 = v392[12];
      int v394 = v392[13];
      int * v395 = v328->cache_vals;
      int v921 = (8 + ((((v373 + ((~(((v375 ^ -1) | (-(v375 ^ -1))) >> 31)) & 2)) - (v376 + ((~(((v377 ^ -1) | (-(v377 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
      v395[v921] = v393;
      int * v397 = v328->cache_vals;
      int v924 = ((8 + ((((v373 + ((~(((v375 ^ -1) | (-(v375 ^ -1))) >> 31)) & 2)) - (v376 + ((~(((v377 ^ -1) | (-(v377 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
      v397[v924] = v394;
      int * v399 = v328->cache_tags;
      v399[v903] = 6;
      int * v401 = v328->cache_dirty;
      v401[v903] = 0;
      int * v403 = v328->cache_age;
      v403[v903] = 1;
      int * v405 = v328->cache_age;
      int v406 = v405[v903];
      int v407 = v405[8];
      int v931 = v407 + ((int)((unsigned int)(v407 - v406) >> 31));
      v405[8] = v931;
      int * v409 = v328->cache_age;
      int v410 = v409[9];
      int v933 = v410 + ((int)((unsigned int)(v410 - v406) >> 31));
      v409[9] = v933;
      int * v412 = v328->cache_age;
      v412[v903] = 0;
      v415 = v903;
    }
    int * v416 = v328->cache_vals;
    int v936 = v415 * 2;
    int v417 = v416[v936];
    int v937 = (v415 * 2) + 1;
    int v418 = v416[v937];
    int v938 = ((((v357 + ((~(((v359 ^ -1) | (-(v359 ^ -1))) >> 31)) & 2)) - (v360 + ((~(((v361 ^ -1) | (-(v361 ^ -1))) >> 31)) & 2))) >> 31) & 1) * 2;
    v416[v938] = v417;
    int * v420 = v328->cache_vals;
    int v941 = (((((v357 + ((~(((v359 ^ -1) | (-(v359 ^ -1))) >> 31)) & 2)) - (v360 + ((~(((v361 ^ -1) | (-(v361 ^ -1))) >> 31)) & 2))) >> 31) & 1) * 2) + 1;
    v420[v941] = v418;
    int * v422 = v328->cache_tags;
    int v944 = (((v357 + ((~(((v359 ^ -1) | (-(v359 ^ -1))) >> 31)) & 2)) - (v360 + ((~(((v361 ^ -1) | (-(v361 ^ -1))) >> 31)) & 2))) >> 31) & 1;
    v422[v944] = 6;
    int * v424 = v328->cache_dirty;
    v424[v944] = 0;
    int * v426 = v328->cache_age;
    v426[v944] = 1;
    int * v428 = v328->cache_age;
    int v429 = v428[v944];
    int v430 = v428[0];
    int v949 = v430 + ((int)((unsigned int)(v430 - v429) >> 31));
    v428[0] = v949;
    int * v432 = v328->cache_age;
    int v433 = v432[1];
    int v951 = v433 + ((int)((unsigned int)(v433 - v429) >> 31));
    v432[1] = v951;
    int * v435 = v328->cache_age;
    v435[v944] = 0;
    v438 = v944;
  }
  int v954 = (v438 * 2) + 1;
  int v439 = v345[v954];
  int * v440 = v328->regs;
  v440[8] = v439;
  int * v442 = v328->saved_regs;
  int * v443 = v328->regs;
  int v444 = v443[9];
  v442[9] = v444;
  int v446 = v328->timer;
  int v960 = v446 + 1;
  v328->timer = v960;
  int * v448 = v328->regs;
  int v449 = v448[10];
  int v450 = v448[8];
  int v963 = v449 & v450;
  v448[9] = v963;
  int * v452 = v328->saved_regs;
  int * v453 = v328->regs;
  int v454 = v453[11];
  v452[11] = v454;
  int v456 = v328->timer;
  int v968 = v456 + 1;
  v328->timer = v968;
  int * v458 = v328->regs;
  int v459 = v458[9];
  bool v970 = 1 == (((int)((unsigned int)v459 >> 2)) & 3);
  int v566;
  if (v970) {
    int v460 = v328->timer;
    int v971 = v460 + 1;
    v328->timer = v971;
    v566 = v332;
  } else {
    int * v463 = v328->cache_tags;
    int v974 = (((int)((unsigned int)((int)((unsigned int)v459 >> 2)) >> 1)) & 1) * 2;
    int v464 = v463[v974];
    int v975 = ((((int)((unsigned int)((int)((unsigned int)v459 >> 2)) >> 1)) & 1) * 2) + 1;
    int v465 = v463[v975];
    int v976 = 4 + ((((int)((unsigned int)((int)((unsigned int)v459 >> 2)) >> 1)) & 3) * 2);
    int v466 = v463[v976];
    int v977 = (4 + ((((int)((unsigned int)((int)((unsigned int)v459 >> 2)) >> 1)) & 3) * 2)) + 1;
    int v467 = v463[v977];
    int v468 = v328->timer;
    int v978 = v468 + ((100 ^ (((~(((v466 ^ ((int)((unsigned int)((int)((unsigned int)v459 >> 2)) >> 1))) | (-(v466 ^ ((int)((unsigned int)((int)((unsigned int)v459 >> 2)) >> 1))))) >> 31)) | (~(((v467 ^ ((int)((unsigned int)((int)((unsigned int)v459 >> 2)) >> 1))) | (-(v467 ^ ((int)((unsigned int)((int)((unsigned int)v459 >> 2)) >> 1))))) >> 31))) & 104)) ^ (((~(((v464 ^ ((int)((unsigned int)((int)((unsigned int)v459 >> 2)) >> 1))) | (-(v464 ^ ((int)((unsigned int)((int)((unsigned int)v459 >> 2)) >> 1))))) >> 31)) | (~(((v465 ^ ((int)((unsigned int)((int)((unsigned int)v459 >> 2)) >> 1))) | (-(v465 ^ ((int)((unsigned int)((int)((unsigned int)v459 >> 2)) >> 1))))) >> 31))) & (1 ^ (100 ^ (((~(((v466 ^ ((int)((unsigned int)((int)((unsigned int)v459 >> 2)) >> 1))) | (-(v466 ^ ((int)((unsigned int)((int)((unsigned int)v459 >> 2)) >> 1))))) >> 31)) | (~(((v467 ^ ((int)((unsigned int)((int)((unsigned int)v459 >> 2)) >> 1))) | (-(v467 ^ ((int)((unsigned int)((int)((unsigned int)v459 >> 2)) >> 1))))) >> 31))) & 104)))));
    v328->timer = v978;
    int * v470 = v328->cache_vals;
    bool v979 = !(((~(((v464 ^ ((int)((unsigned int)((int)((unsigned int)v459 >> 2)) >> 1))) | (-(v464 ^ ((int)((unsigned int)((int)((unsigned int)v459 >> 2)) >> 1))))) >> 31)) | (~(((v465 ^ ((int)((unsigned int)((int)((unsigned int)v459 >> 2)) >> 1))) | (-(v465 ^ ((int)((unsigned int)((int)((unsigned int)v459 >> 2)) >> 1))))) >> 31))) == 0);
    int v563;
    if (v979) {
      int * v471 = v328->cache_age;
      int v981 = ((((int)((unsigned int)((int)((unsigned int)v459 >> 2)) >> 1)) & 1) * 2) + ((~(((v465 ^ ((int)((unsigned int)((int)((unsigned int)v459 >> 2)) >> 1))) | (-(v465 ^ ((int)((unsigned int)((int)((unsigned int)v459 >> 2)) >> 1))))) >> 31)) & 1);
      int v472 = v471[v981];
      int v473 = v471[v974];
      int v982 = v473 + ((int)((unsigned int)(v473 - v472) >> 31));
      v471[v974] = v982;
      int * v475 = v328->cache_age;
      int v476 = v475[v975];
      int v984 = v476 + ((int)((unsigned int)(v476 - v472) >> 31));
      v475[v975] = v984;
      int * v478 = v328->cache_age;
      v478[v981] = 0;
      v563 = v981;
    } else {
      int * v481 = v328->cache_age;
      int v987 = (((int)((unsigned int)((int)((unsigned int)v459 >> 2)) >> 1)) & 1) * 2;
      int v482 = v481[v987];
      int * v483 = v328->cache_tags;
      int v484 = v483[v987];
      int v485 = v481[v975];
      int v486 = v483[v975];
      bool v989 = !(((~(((v466 ^ ((int)((unsigned int)((int)((unsigned int)v459 >> 2)) >> 1))) | (-(v466 ^ ((int)((unsigned int)((int)((unsigned int)v459 >> 2)) >> 1))))) >> 31)) | (~(((v467 ^ ((int)((unsigned int)((int)((unsigned int)v459 >> 2)) >> 1))) | (-(v467 ^ ((int)((unsigned int)((int)((unsigned int)v459 >> 2)) >> 1))))) >> 31))) == 0);
      int v540;
      if (v989) {
        int * v487 = v328->cache_age;
        int v991 = (4 + ((((int)((unsigned int)((int)((unsigned int)v459 >> 2)) >> 1)) & 3) * 2)) + ((~(((v467 ^ ((int)((unsigned int)((int)((unsigned int)v459 >> 2)) >> 1))) | (-(v467 ^ ((int)((unsigned int)((int)((unsigned int)v459 >> 2)) >> 1))))) >> 31)) & 1);
        int v488 = v487[v991];
        int v489 = v487[v976];
        int v992 = v489 + ((int)((unsigned int)(v489 - v488) >> 31));
        v487[v976] = v992;
        int * v491 = v328->cache_age;
        int v492 = v491[v977];
        int v994 = v492 + ((int)((unsigned int)(v492 - v488) >> 31));
        v491[v977] = v994;
        int * v494 = v328->cache_age;
        v494[v991] = 0;
        v540 = v991;
      } else {
        int * v497 = v328->cache_age;
        int v997 = 4 + ((((int)((unsigned int)((int)((unsigned int)v459 >> 2)) >> 1)) & 3) * 2);
        int v498 = v497[v997];
        int * v499 = v328->cache_tags;
        int v500 = v499[v997];
        int v501 = v497[v977];
        int v502 = v499[v977];
        int * v503 = v328->cache_dirty;
        int v1000 = (4 + ((((int)((unsigned int)((int)((unsigned int)v459 >> 2)) >> 1)) & 3) * 2)) + ((((v498 + ((~(((v500 ^ -1) | (-(v500 ^ -1))) >> 31)) & 2)) - (v501 + ((~(((v502 ^ -1) | (-(v502 ^ -1))) >> 31)) & 2))) >> 31) & 1);
        int v504 = v503[v1000];
        bool v1001 = !(v504 == 0);
        if (v1001) {
          int * v505 = v328->cache_tags;
          int v506 = v505[v1000];
          int * v507 = v328->cache_vals;
          int v1004 = ((4 + ((((int)((unsigned int)((int)((unsigned int)v459 >> 2)) >> 1)) & 3) * 2)) + ((((v498 + ((~(((v500 ^ -1) | (-(v500 ^ -1))) >> 31)) & 2)) - (v501 + ((~(((v502 ^ -1) | (-(v502 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
          int v508 = v507[v1004];
          int v1005 = (((4 + ((((int)((unsigned int)((int)((unsigned int)v459 >> 2)) >> 1)) & 3) * 2)) + ((((v498 + ((~(((v500 ^ -1) | (-(v500 ^ -1))) >> 31)) & 2)) - (v501 + ((~(((v502 ^ -1) | (-(v502 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
          int v509 = v507[v1005];
          int * v510 = v328->mem;
          int v1007 = v506 * 2;
          v510[v1007] = v508;
          int * v512 = v328->mem;
          int v1010 = (v506 * 2) + 1;
          v512[v1010] = v509;
          ;
        } else {
          ;
        }
        int * v517 = v328->mem;
        int v1015 = ((int)((unsigned int)((int)((unsigned int)v459 >> 2)) >> 1)) * 2;
        int v518 = v517[v1015];
        int v1016 = (((int)((unsigned int)((int)((unsigned int)v459 >> 2)) >> 1)) * 2) + 1;
        int v519 = v517[v1016];
        int * v520 = v328->cache_vals;
        int v1018 = ((4 + ((((int)((unsigned int)((int)((unsigned int)v459 >> 2)) >> 1)) & 3) * 2)) + ((((v498 + ((~(((v500 ^ -1) | (-(v500 ^ -1))) >> 31)) & 2)) - (v501 + ((~(((v502 ^ -1) | (-(v502 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
        v520[v1018] = v518;
        int * v522 = v328->cache_vals;
        int v1021 = (((4 + ((((int)((unsigned int)((int)((unsigned int)v459 >> 2)) >> 1)) & 3) * 2)) + ((((v498 + ((~(((v500 ^ -1) | (-(v500 ^ -1))) >> 31)) & 2)) - (v501 + ((~(((v502 ^ -1) | (-(v502 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
        v522[v1021] = v519;
        int * v524 = v328->cache_tags;
        int v1024 = (int)((unsigned int)((int)((unsigned int)v459 >> 2)) >> 1);
        v524[v1000] = v1024;
        int * v526 = v328->cache_dirty;
        v526[v1000] = 0;
        int * v528 = v328->cache_age;
        v528[v1000] = 1;
        int * v530 = v328->cache_age;
        int v531 = v530[v1000];
        int v532 = v530[v976];
        int v1028 = v532 + ((int)((unsigned int)(v532 - v531) >> 31));
        v530[v976] = v1028;
        int * v534 = v328->cache_age;
        int v535 = v534[v977];
        int v1030 = v535 + ((int)((unsigned int)(v535 - v531) >> 31));
        v534[v977] = v1030;
        int * v537 = v328->cache_age;
        v537[v1000] = 0;
        v540 = v1000;
      }
      int * v541 = v328->cache_vals;
      int v1033 = v540 * 2;
      int v542 = v541[v1033];
      int v1034 = (v540 * 2) + 1;
      int v543 = v541[v1034];
      int v1035 = (((((int)((unsigned int)((int)((unsigned int)v459 >> 2)) >> 1)) & 1) * 2) + ((((v482 + ((~(((v484 ^ -1) | (-(v484 ^ -1))) >> 31)) & 2)) - (v485 + ((~(((v486 ^ -1) | (-(v486 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
      v541[v1035] = v542;
      int * v545 = v328->cache_vals;
      int v1038 = ((((((int)((unsigned int)((int)((unsigned int)v459 >> 2)) >> 1)) & 1) * 2) + ((((v482 + ((~(((v484 ^ -1) | (-(v484 ^ -1))) >> 31)) & 2)) - (v485 + ((~(((v486 ^ -1) | (-(v486 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
      v545[v1038] = v543;
      int * v547 = v328->cache_tags;
      int v1041 = ((((int)((unsigned int)((int)((unsigned int)v459 >> 2)) >> 1)) & 1) * 2) + ((((v482 + ((~(((v484 ^ -1) | (-(v484 ^ -1))) >> 31)) & 2)) - (v485 + ((~(((v486 ^ -1) | (-(v486 ^ -1))) >> 31)) & 2))) >> 31) & 1);
      int v1042 = (int)((unsigned int)((int)((unsigned int)v459 >> 2)) >> 1);
      v547[v1041] = v1042;
      int * v549 = v328->cache_dirty;
      v549[v1041] = 0;
      int * v551 = v328->cache_age;
      v551[v1041] = 1;
      int * v553 = v328->cache_age;
      int v554 = v553[v1041];
      int v555 = v553[v974];
      int v1046 = v555 + ((int)((unsigned int)(v555 - v554) >> 31));
      v553[v974] = v1046;
      int * v557 = v328->cache_age;
      int v558 = v557[v975];
      int v1048 = v558 + ((int)((unsigned int)(v558 - v554) >> 31));
      v557[v975] = v1048;
      int * v560 = v328->cache_age;
      v560[v1041] = 0;
      v563 = v1041;
    }
    int v1051 = (v563 * 2) + (((int)((unsigned int)v459 >> 2)) & 1);
    int v564 = v470[v1051];
    v566 = v564;
  }
  int * v567 = v328->regs;
  v567[11] = v566;
  int * v569 = v328->saved_regs;
  int * v570 = v328->regs;
  int v571 = v570[12];
  v569[12] = v571;
  int v573 = v328->timer;
  int v1059 = v573 + 1;
  v328->timer = v1059;
  int * v575 = v328->regs;
  int v576 = v575[11];
  bool v1061 = 1 == (((int)((unsigned int)v576 >> 2)) & 3);
  int v683;
  if (v1061) {
    int v577 = v328->timer;
    int v1062 = v577 + 1;
    v328->timer = v1062;
    v683 = v332;
  } else {
    int * v580 = v328->cache_tags;
    int v1065 = (((int)((unsigned int)((int)((unsigned int)v576 >> 2)) >> 1)) & 1) * 2;
    int v581 = v580[v1065];
    int v1066 = ((((int)((unsigned int)((int)((unsigned int)v576 >> 2)) >> 1)) & 1) * 2) + 1;
    int v582 = v580[v1066];
    int v1067 = 4 + ((((int)((unsigned int)((int)((unsigned int)v576 >> 2)) >> 1)) & 3) * 2);
    int v583 = v580[v1067];
    int v1068 = (4 + ((((int)((unsigned int)((int)((unsigned int)v576 >> 2)) >> 1)) & 3) * 2)) + 1;
    int v584 = v580[v1068];
    int v585 = v328->timer;
    int v1069 = v585 + ((100 ^ (((~(((v583 ^ ((int)((unsigned int)((int)((unsigned int)v576 >> 2)) >> 1))) | (-(v583 ^ ((int)((unsigned int)((int)((unsigned int)v576 >> 2)) >> 1))))) >> 31)) | (~(((v584 ^ ((int)((unsigned int)((int)((unsigned int)v576 >> 2)) >> 1))) | (-(v584 ^ ((int)((unsigned int)((int)((unsigned int)v576 >> 2)) >> 1))))) >> 31))) & 104)) ^ (((~(((v581 ^ ((int)((unsigned int)((int)((unsigned int)v576 >> 2)) >> 1))) | (-(v581 ^ ((int)((unsigned int)((int)((unsigned int)v576 >> 2)) >> 1))))) >> 31)) | (~(((v582 ^ ((int)((unsigned int)((int)((unsigned int)v576 >> 2)) >> 1))) | (-(v582 ^ ((int)((unsigned int)((int)((unsigned int)v576 >> 2)) >> 1))))) >> 31))) & (1 ^ (100 ^ (((~(((v583 ^ ((int)((unsigned int)((int)((unsigned int)v576 >> 2)) >> 1))) | (-(v583 ^ ((int)((unsigned int)((int)((unsigned int)v576 >> 2)) >> 1))))) >> 31)) | (~(((v584 ^ ((int)((unsigned int)((int)((unsigned int)v576 >> 2)) >> 1))) | (-(v584 ^ ((int)((unsigned int)((int)((unsigned int)v576 >> 2)) >> 1))))) >> 31))) & 104)))));
    v328->timer = v1069;
    int * v587 = v328->cache_vals;
    bool v1070 = !(((~(((v581 ^ ((int)((unsigned int)((int)((unsigned int)v576 >> 2)) >> 1))) | (-(v581 ^ ((int)((unsigned int)((int)((unsigned int)v576 >> 2)) >> 1))))) >> 31)) | (~(((v582 ^ ((int)((unsigned int)((int)((unsigned int)v576 >> 2)) >> 1))) | (-(v582 ^ ((int)((unsigned int)((int)((unsigned int)v576 >> 2)) >> 1))))) >> 31))) == 0);
    int v680;
    if (v1070) {
      int * v588 = v328->cache_age;
      int v1072 = ((((int)((unsigned int)((int)((unsigned int)v576 >> 2)) >> 1)) & 1) * 2) + ((~(((v582 ^ ((int)((unsigned int)((int)((unsigned int)v576 >> 2)) >> 1))) | (-(v582 ^ ((int)((unsigned int)((int)((unsigned int)v576 >> 2)) >> 1))))) >> 31)) & 1);
      int v589 = v588[v1072];
      int v590 = v588[v1065];
      int v1073 = v590 + ((int)((unsigned int)(v590 - v589) >> 31));
      v588[v1065] = v1073;
      int * v592 = v328->cache_age;
      int v593 = v592[v1066];
      int v1075 = v593 + ((int)((unsigned int)(v593 - v589) >> 31));
      v592[v1066] = v1075;
      int * v595 = v328->cache_age;
      v595[v1072] = 0;
      v680 = v1072;
    } else {
      int * v598 = v328->cache_age;
      int v1078 = (((int)((unsigned int)((int)((unsigned int)v576 >> 2)) >> 1)) & 1) * 2;
      int v599 = v598[v1078];
      int * v600 = v328->cache_tags;
      int v601 = v600[v1078];
      int v602 = v598[v1066];
      int v603 = v600[v1066];
      bool v1080 = !(((~(((v583 ^ ((int)((unsigned int)((int)((unsigned int)v576 >> 2)) >> 1))) | (-(v583 ^ ((int)((unsigned int)((int)((unsigned int)v576 >> 2)) >> 1))))) >> 31)) | (~(((v584 ^ ((int)((unsigned int)((int)((unsigned int)v576 >> 2)) >> 1))) | (-(v584 ^ ((int)((unsigned int)((int)((unsigned int)v576 >> 2)) >> 1))))) >> 31))) == 0);
      int v657;
      if (v1080) {
        int * v604 = v328->cache_age;
        int v1082 = (4 + ((((int)((unsigned int)((int)((unsigned int)v576 >> 2)) >> 1)) & 3) * 2)) + ((~(((v584 ^ ((int)((unsigned int)((int)((unsigned int)v576 >> 2)) >> 1))) | (-(v584 ^ ((int)((unsigned int)((int)((unsigned int)v576 >> 2)) >> 1))))) >> 31)) & 1);
        int v605 = v604[v1082];
        int v606 = v604[v1067];
        int v1083 = v606 + ((int)((unsigned int)(v606 - v605) >> 31));
        v604[v1067] = v1083;
        int * v608 = v328->cache_age;
        int v609 = v608[v1068];
        int v1085 = v609 + ((int)((unsigned int)(v609 - v605) >> 31));
        v608[v1068] = v1085;
        int * v611 = v328->cache_age;
        v611[v1082] = 0;
        v657 = v1082;
      } else {
        int * v614 = v328->cache_age;
        int v1088 = 4 + ((((int)((unsigned int)((int)((unsigned int)v576 >> 2)) >> 1)) & 3) * 2);
        int v615 = v614[v1088];
        int * v616 = v328->cache_tags;
        int v617 = v616[v1088];
        int v618 = v614[v1068];
        int v619 = v616[v1068];
        int * v620 = v328->cache_dirty;
        int v1091 = (4 + ((((int)((unsigned int)((int)((unsigned int)v576 >> 2)) >> 1)) & 3) * 2)) + ((((v615 + ((~(((v617 ^ -1) | (-(v617 ^ -1))) >> 31)) & 2)) - (v618 + ((~(((v619 ^ -1) | (-(v619 ^ -1))) >> 31)) & 2))) >> 31) & 1);
        int v621 = v620[v1091];
        bool v1092 = !(v621 == 0);
        if (v1092) {
          int * v622 = v328->cache_tags;
          int v623 = v622[v1091];
          int * v624 = v328->cache_vals;
          int v1095 = ((4 + ((((int)((unsigned int)((int)((unsigned int)v576 >> 2)) >> 1)) & 3) * 2)) + ((((v615 + ((~(((v617 ^ -1) | (-(v617 ^ -1))) >> 31)) & 2)) - (v618 + ((~(((v619 ^ -1) | (-(v619 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
          int v625 = v624[v1095];
          int v1096 = (((4 + ((((int)((unsigned int)((int)((unsigned int)v576 >> 2)) >> 1)) & 3) * 2)) + ((((v615 + ((~(((v617 ^ -1) | (-(v617 ^ -1))) >> 31)) & 2)) - (v618 + ((~(((v619 ^ -1) | (-(v619 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
          int v626 = v624[v1096];
          int * v627 = v328->mem;
          int v1098 = v623 * 2;
          v627[v1098] = v625;
          int * v629 = v328->mem;
          int v1101 = (v623 * 2) + 1;
          v629[v1101] = v626;
          ;
        } else {
          ;
        }
        int * v634 = v328->mem;
        int v1106 = ((int)((unsigned int)((int)((unsigned int)v576 >> 2)) >> 1)) * 2;
        int v635 = v634[v1106];
        int v1107 = (((int)((unsigned int)((int)((unsigned int)v576 >> 2)) >> 1)) * 2) + 1;
        int v636 = v634[v1107];
        int * v637 = v328->cache_vals;
        int v1109 = ((4 + ((((int)((unsigned int)((int)((unsigned int)v576 >> 2)) >> 1)) & 3) * 2)) + ((((v615 + ((~(((v617 ^ -1) | (-(v617 ^ -1))) >> 31)) & 2)) - (v618 + ((~(((v619 ^ -1) | (-(v619 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
        v637[v1109] = v635;
        int * v639 = v328->cache_vals;
        int v1112 = (((4 + ((((int)((unsigned int)((int)((unsigned int)v576 >> 2)) >> 1)) & 3) * 2)) + ((((v615 + ((~(((v617 ^ -1) | (-(v617 ^ -1))) >> 31)) & 2)) - (v618 + ((~(((v619 ^ -1) | (-(v619 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
        v639[v1112] = v636;
        int * v641 = v328->cache_tags;
        int v1115 = (int)((unsigned int)((int)((unsigned int)v576 >> 2)) >> 1);
        v641[v1091] = v1115;
        int * v643 = v328->cache_dirty;
        v643[v1091] = 0;
        int * v645 = v328->cache_age;
        v645[v1091] = 1;
        int * v647 = v328->cache_age;
        int v648 = v647[v1091];
        int v649 = v647[v1067];
        int v1119 = v649 + ((int)((unsigned int)(v649 - v648) >> 31));
        v647[v1067] = v1119;
        int * v651 = v328->cache_age;
        int v652 = v651[v1068];
        int v1121 = v652 + ((int)((unsigned int)(v652 - v648) >> 31));
        v651[v1068] = v1121;
        int * v654 = v328->cache_age;
        v654[v1091] = 0;
        v657 = v1091;
      }
      int * v658 = v328->cache_vals;
      int v1124 = v657 * 2;
      int v659 = v658[v1124];
      int v1125 = (v657 * 2) + 1;
      int v660 = v658[v1125];
      int v1126 = (((((int)((unsigned int)((int)((unsigned int)v576 >> 2)) >> 1)) & 1) * 2) + ((((v599 + ((~(((v601 ^ -1) | (-(v601 ^ -1))) >> 31)) & 2)) - (v602 + ((~(((v603 ^ -1) | (-(v603 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
      v658[v1126] = v659;
      int * v662 = v328->cache_vals;
      int v1129 = ((((((int)((unsigned int)((int)((unsigned int)v576 >> 2)) >> 1)) & 1) * 2) + ((((v599 + ((~(((v601 ^ -1) | (-(v601 ^ -1))) >> 31)) & 2)) - (v602 + ((~(((v603 ^ -1) | (-(v603 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
      v662[v1129] = v660;
      int * v664 = v328->cache_tags;
      int v1132 = ((((int)((unsigned int)((int)((unsigned int)v576 >> 2)) >> 1)) & 1) * 2) + ((((v599 + ((~(((v601 ^ -1) | (-(v601 ^ -1))) >> 31)) & 2)) - (v602 + ((~(((v603 ^ -1) | (-(v603 ^ -1))) >> 31)) & 2))) >> 31) & 1);
      int v1133 = (int)((unsigned int)((int)((unsigned int)v576 >> 2)) >> 1);
      v664[v1132] = v1133;
      int * v666 = v328->cache_dirty;
      v666[v1132] = 0;
      int * v668 = v328->cache_age;
      v668[v1132] = 1;
      int * v670 = v328->cache_age;
      int v671 = v670[v1132];
      int v672 = v670[v1065];
      int v1137 = v672 + ((int)((unsigned int)(v672 - v671) >> 31));
      v670[v1065] = v1137;
      int * v674 = v328->cache_age;
      int v675 = v674[v1066];
      int v1139 = v675 + ((int)((unsigned int)(v675 - v671) >> 31));
      v674[v1066] = v1139;
      int * v677 = v328->cache_age;
      v677[v1132] = 0;
      v680 = v1132;
    }
    int v1142 = (v680 * 2) + (((int)((unsigned int)v576 >> 2)) & 1);
    int v681 = v587[v1142];
    v683 = v681;
  }
  int * v684 = v328->regs;
  v684[12] = v683;
  int * v686 = v328->cache_tags;
  int v687 = v686[0];
  int v688 = v686[1];
  int v689 = v686[8];
  int v690 = v686[9];
  int v691 = v328->timer;
  int v1147 = v691 + ((100 ^ (((~(((v689 ^ 6) | (-(v689 ^ 6))) >> 31)) | (~(((v690 ^ 6) | (-(v690 ^ 6))) >> 31))) & 104)) ^ (((~(((v687 ^ 6) | (-(v687 ^ 6))) >> 31)) | (~(((v688 ^ 6) | (-(v688 ^ 6))) >> 31))) & (1 ^ (100 ^ (((~(((v689 ^ 6) | (-(v689 ^ 6))) >> 31)) | (~(((v690 ^ 6) | (-(v690 ^ 6))) >> 31))) & 104)))));
  v328->timer = v1147;
  bool v1148 = !(((~(((v687 ^ 6) | (-(v687 ^ 6))) >> 31)) | (~(((v688 ^ 6) | (-(v688 ^ 6))) >> 31))) == 0);
  int v785;
  if (v1148) {
    int * v693 = v328->cache_age;
    int v1150 = (~(((v688 ^ 6) | (-(v688 ^ 6))) >> 31)) & 1;
    int v694 = v693[v1150];
    int v695 = v693[0];
    int v1151 = v695 + ((int)((unsigned int)(v695 - v694) >> 31));
    v693[0] = v1151;
    int * v697 = v328->cache_age;
    int v698 = v697[1];
    int v1153 = v698 + ((int)((unsigned int)(v698 - v694) >> 31));
    v697[1] = v1153;
    int * v700 = v328->cache_age;
    v700[v1150] = 0;
    v785 = v1150;
  } else {
    int * v703 = v328->cache_age;
    int v704 = v703[0];
    int * v705 = v328->cache_tags;
    int v706 = v705[0];
    int v707 = v703[1];
    int v708 = v705[1];
    bool v1157 = !(((~(((v689 ^ 6) | (-(v689 ^ 6))) >> 31)) | (~(((v690 ^ 6) | (-(v690 ^ 6))) >> 31))) == 0);
    int v762;
    if (v1157) {
      int * v709 = v328->cache_age;
      int v1159 = 8 + ((~(((v690 ^ 6) | (-(v690 ^ 6))) >> 31)) & 1);
      int v710 = v709[v1159];
      int v711 = v709[8];
      int v1160 = v711 + ((int)((unsigned int)(v711 - v710) >> 31));
      v709[8] = v1160;
      int * v713 = v328->cache_age;
      int v714 = v713[9];
      int v1162 = v714 + ((int)((unsigned int)(v714 - v710) >> 31));
      v713[9] = v1162;
      int * v716 = v328->cache_age;
      v716[v1159] = 0;
      v762 = v1159;
    } else {
      int * v719 = v328->cache_age;
      int v720 = v719[8];
      int * v721 = v328->cache_tags;
      int v722 = v721[8];
      int v723 = v719[9];
      int v724 = v721[9];
      int * v725 = v328->cache_dirty;
      int v1167 = 8 + ((((v720 + ((~(((v722 ^ -1) | (-(v722 ^ -1))) >> 31)) & 2)) - (v723 + ((~(((v724 ^ -1) | (-(v724 ^ -1))) >> 31)) & 2))) >> 31) & 1);
      int v726 = v725[v1167];
      bool v1168 = !(v726 == 0);
      if (v1168) {
        int * v727 = v328->cache_tags;
        int v728 = v727[v1167];
        int * v729 = v328->cache_vals;
        int v1171 = (8 + ((((v720 + ((~(((v722 ^ -1) | (-(v722 ^ -1))) >> 31)) & 2)) - (v723 + ((~(((v724 ^ -1) | (-(v724 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
        int v730 = v729[v1171];
        int v1172 = ((8 + ((((v720 + ((~(((v722 ^ -1) | (-(v722 ^ -1))) >> 31)) & 2)) - (v723 + ((~(((v724 ^ -1) | (-(v724 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
        int v731 = v729[v1172];
        int * v732 = v328->mem;
        int v1174 = v728 * 2;
        v732[v1174] = v730;
        int * v734 = v328->mem;
        int v1177 = (v728 * 2) + 1;
        v734[v1177] = v731;
        ;
      } else {
        ;
      }
      int * v739 = v328->mem;
      int v740 = v739[12];
      int v741 = v739[13];
      int * v742 = v328->cache_vals;
      int v1184 = (8 + ((((v720 + ((~(((v722 ^ -1) | (-(v722 ^ -1))) >> 31)) & 2)) - (v723 + ((~(((v724 ^ -1) | (-(v724 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
      v742[v1184] = v740;
      int * v744 = v328->cache_vals;
      int v1187 = ((8 + ((((v720 + ((~(((v722 ^ -1) | (-(v722 ^ -1))) >> 31)) & 2)) - (v723 + ((~(((v724 ^ -1) | (-(v724 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
      v744[v1187] = v741;
      int * v746 = v328->cache_tags;
      v746[v1167] = 6;
      int * v748 = v328->cache_dirty;
      v748[v1167] = 0;
      int * v750 = v328->cache_age;
      v750[v1167] = 1;
      int * v752 = v328->cache_age;
      int v753 = v752[v1167];
      int v754 = v752[8];
      int v1194 = v754 + ((int)((unsigned int)(v754 - v753) >> 31));
      v752[8] = v1194;
      int * v756 = v328->cache_age;
      int v757 = v756[9];
      int v1196 = v757 + ((int)((unsigned int)(v757 - v753) >> 31));
      v756[9] = v1196;
      int * v759 = v328->cache_age;
      v759[v1167] = 0;
      v762 = v1167;
    }
    int * v763 = v328->cache_vals;
    int v1199 = v762 * 2;
    int v764 = v763[v1199];
    int v1200 = (v762 * 2) + 1;
    int v765 = v763[v1200];
    int v1201 = ((((v704 + ((~(((v706 ^ -1) | (-(v706 ^ -1))) >> 31)) & 2)) - (v707 + ((~(((v708 ^ -1) | (-(v708 ^ -1))) >> 31)) & 2))) >> 31) & 1) * 2;
    v763[v1201] = v764;
    int * v767 = v328->cache_vals;
    int v1204 = (((((v704 + ((~(((v706 ^ -1) | (-(v706 ^ -1))) >> 31)) & 2)) - (v707 + ((~(((v708 ^ -1) | (-(v708 ^ -1))) >> 31)) & 2))) >> 31) & 1) * 2) + 1;
    v767[v1204] = v765;
    int * v769 = v328->cache_tags;
    int v1207 = (((v704 + ((~(((v706 ^ -1) | (-(v706 ^ -1))) >> 31)) & 2)) - (v707 + ((~(((v708 ^ -1) | (-(v708 ^ -1))) >> 31)) & 2))) >> 31) & 1;
    v769[v1207] = 6;
    int * v771 = v328->cache_dirty;
    v771[v1207] = 0;
    int * v773 = v328->cache_age;
    v773[v1207] = 1;
    int * v775 = v328->cache_age;
    int v776 = v775[v1207];
    int v777 = v775[0];
    int v1212 = v777 + ((int)((unsigned int)(v777 - v776) >> 31));
    v775[0] = v1212;
    int * v779 = v328->cache_age;
    int v780 = v779[1];
    int v1214 = v780 + ((int)((unsigned int)(v780 - v776) >> 31));
    v779[1] = v1214;
    int * v782 = v328->cache_age;
    v782[v1207] = 0;
    v785 = v1207;
  }
  int * v786 = v328->cache_vals;
  int v1217 = (v785 * 2) + 1;
  v786[v1217] = v332;
  int * v788 = v328->cache_tags;
  int v789 = v788[8];
  int v790 = v788[9];
  bool v1220 = !(((~(((v789 ^ 6) | (-(v789 ^ 6))) >> 31)) | (~(((v790 ^ 6) | (-(v790 ^ 6))) >> 31))) == 0);
  int v844;
  if (v1220) {
    int * v791 = v328->cache_age;
    int v1222 = 8 + ((~(((v790 ^ 6) | (-(v790 ^ 6))) >> 31)) & 1);
    int v792 = v791[v1222];
    int v793 = v791[8];
    int v1223 = v793 + ((int)((unsigned int)(v793 - v792) >> 31));
    v791[8] = v1223;
    int * v795 = v328->cache_age;
    int v796 = v795[9];
    int v1225 = v796 + ((int)((unsigned int)(v796 - v792) >> 31));
    v795[9] = v1225;
    int * v798 = v328->cache_age;
    v798[v1222] = 0;
    v844 = v1222;
  } else {
    int * v801 = v328->cache_age;
    int v802 = v801[8];
    int * v803 = v328->cache_tags;
    int v804 = v803[8];
    int v805 = v801[9];
    int v806 = v803[9];
    int * v807 = v328->cache_dirty;
    int v1230 = 8 + ((((v802 + ((~(((v804 ^ -1) | (-(v804 ^ -1))) >> 31)) & 2)) - (v805 + ((~(((v806 ^ -1) | (-(v806 ^ -1))) >> 31)) & 2))) >> 31) & 1);
    int v808 = v807[v1230];
    bool v1231 = !(v808 == 0);
    if (v1231) {
      int * v809 = v328->cache_tags;
      int v810 = v809[v1230];
      int * v811 = v328->cache_vals;
      int v1234 = (8 + ((((v802 + ((~(((v804 ^ -1) | (-(v804 ^ -1))) >> 31)) & 2)) - (v805 + ((~(((v806 ^ -1) | (-(v806 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
      int v812 = v811[v1234];
      int v1235 = ((8 + ((((v802 + ((~(((v804 ^ -1) | (-(v804 ^ -1))) >> 31)) & 2)) - (v805 + ((~(((v806 ^ -1) | (-(v806 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
      int v813 = v811[v1235];
      int * v814 = v328->mem;
      int v1237 = v810 * 2;
      v814[v1237] = v812;
      int * v816 = v328->mem;
      int v1240 = (v810 * 2) + 1;
      v816[v1240] = v813;
      ;
    } else {
      ;
    }
    int * v821 = v328->mem;
    int v822 = v821[12];
    int v823 = v821[13];
    int * v824 = v328->cache_vals;
    int v1247 = (8 + ((((v802 + ((~(((v804 ^ -1) | (-(v804 ^ -1))) >> 31)) & 2)) - (v805 + ((~(((v806 ^ -1) | (-(v806 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
    v824[v1247] = v822;
    int * v826 = v328->cache_vals;
    int v1250 = ((8 + ((((v802 + ((~(((v804 ^ -1) | (-(v804 ^ -1))) >> 31)) & 2)) - (v805 + ((~(((v806 ^ -1) | (-(v806 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
    v826[v1250] = v823;
    int * v828 = v328->cache_tags;
    v828[v1230] = 6;
    int * v830 = v328->cache_dirty;
    v830[v1230] = 0;
    int * v832 = v328->cache_age;
    v832[v1230] = 1;
    int * v834 = v328->cache_age;
    int v835 = v834[v1230];
    int v836 = v834[8];
    int v1257 = v836 + ((int)((unsigned int)(v836 - v835) >> 31));
    v834[8] = v1257;
    int * v838 = v328->cache_age;
    int v839 = v838[9];
    int v1259 = v839 + ((int)((unsigned int)(v839 - v835) >> 31));
    v838[9] = v1259;
    int * v841 = v328->cache_age;
    v841[v1230] = 0;
    v844 = v1230;
  }
  int * v845 = v328->cache_vals;
  int v1262 = (v844 * 2) + 1;
  v845[v1262] = v332;
  int * v847 = v328->cache_dirty;
  v847[v844] = 1;
  struct StateT * v870;
  int v849 = v328->timer;
  int v1266 = v849 + 15;
  v328->timer = v1266;
  int * v851 = v328->saved_regs;
  int v852 = v851[8];
  int * v853 = v328->regs;
  v853[8] = v852;
  int * v855 = v328->saved_regs;
  int v856 = v855[9];
  int * v857 = v328->regs;
  v857[9] = v856;
  int * v859 = v328->saved_regs;
  int v860 = v859[11];
  int * v861 = v328->regs;
  v861[11] = v860;
  int * v863 = v328->saved_regs;
  int v864 = v863[12];
  int * v865 = v328->regs;
  v865[12] = v864;
  struct StateT * v867 = slot_4(v328);
  v870 = v867;
  return v870;
}

struct StateT * slot_0(struct StateT * v2) {
  int v3 = v2->timer;
  int v9 = v3 + 1;
  v2->timer = v9;
  int * v5 = v2->regs;
  v5[5] = -1;
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