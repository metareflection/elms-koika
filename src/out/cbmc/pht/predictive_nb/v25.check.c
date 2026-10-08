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

struct StateT * slot_6(struct StateT * v482);
struct StateT * slot_29(struct StateT * v1835);
struct StateT * slot_25(struct StateT * v1566);
struct StateT * slot_16(struct StateT * v1022);
struct StateT * slot_23(struct StateT * v1343);
struct StateT * slot_5(struct StateT * v474);
struct StateT * slot_2(struct StateT * v33);
struct StateT * slot_7(struct StateT * v503);
struct StateT * slot_21(struct StateT * v1112);
struct StateT * slot_31(struct StateT * v2175);
struct StateT * slot_3(struct StateT * v240);
struct StateT * slot_26(struct StateT * v1587);
struct StateT * slot_10(struct StateT * v927);
struct StateT * slot_1(struct StateT * v10);
struct StateT * slot_19(struct StateT * v1083);
struct StateT * slot_13(struct StateT * v964);
struct StateT * slot_38(struct StateT * v2664);
struct StateT * slot_24(struct StateT * v1359);
struct StateT * slot_0(struct StateT * v2);
struct StateT * slot_28(struct StateT * v1811);
struct StateT * slot_32(struct StateT * v2196);
struct StateT * slot_17(struct StateT * v1038);
struct StateT * slot_33(struct StateT * v2201);
struct StateT * snippet(struct StateT * v0);
struct StateT * slot_4(struct StateT * v458);
struct StateT * slot_15(struct StateT * v1001);
struct StateT * slot_6(struct StateT * v482) {
  int v483 = v482->timer;
  int v494 = v483 + 1;
  v482->timer = v494;
  int * v485 = v482->reg_ready;
  int v486 = v485[10];
  int * v487 = v482->regs;
  int v488 = v487[10];
  int v498 = (v486 + ((v483 - v486) & (~((v483 - v486) >> 31)))) + 1;
  v485[10] = v498;
  int * v490 = v482->regs;
  int v500 = v488 + 72;
  v490[10] = v500;
  struct StateT * v492 = slot_21(v482);
  return v492;
}

struct StateT * slot_29(struct StateT * v1835) {
  int v1836 = v1835->timer;
  int v1847 = v1836 + 1;
  v1835->timer = v1847;
  int * v1838 = v1835->reg_ready;
  int v1839 = v1838[10];
  int * v1840 = v1835->regs;
  int v1841 = v1840[10];
  int v1851 = (v1839 + ((v1836 - v1839) & (~((v1836 - v1839) >> 31)))) + 1;
  v1838[10] = v1851;
  int * v1843 = v1835->regs;
  int v1853 = v1841 << 29;
  v1843[10] = v1853;
  struct StateT * v1845 = slot_31(v1835);
  return v1845;
}

struct StateT * slot_25(struct StateT * v1566) {
  int v1567 = v1566->timer;
  int v1578 = v1567 + 1;
  v1566->timer = v1578;
  int * v1569 = v1566->reg_ready;
  int v1570 = v1569[11];
  int * v1571 = v1566->regs;
  int v1572 = v1571[11];
  int v1582 = (v1570 + ((v1567 - v1570) & (~((v1567 - v1570) >> 31)))) + 1;
  v1569[11] = v1582;
  int * v1574 = v1566->regs;
  int v1584 = v1572 + 4;
  v1574[11] = v1584;
  struct StateT * v1576 = slot_16(v1566);
  return v1576;
}

struct StateT * slot_16(struct StateT * v1022) {
  int v1023 = v1022->timer;
  int v1031 = v1023 + 1;
  v1022->timer = v1031;
  int * v1025 = v1022->reg_ready;
  v1025[12] = v1031;
  int * v1027 = v1022->regs;
  v1027[12] = 0;
  struct StateT * v1029 = slot_29(v1022);
  return v1029;
}

struct StateT * slot_23(struct StateT * v1343) {
  int v1344 = v1343->timer;
  int v1352 = v1344 + 1;
  v1343->timer = v1352;
  int * v1346 = v1343->reg_ready;
  v1346[11] = v1352;
  int * v1348 = v1343->regs;
  v1348[11] = 0;
  struct StateT * v1350 = slot_25(v1343);
  return v1350;
}

struct StateT * slot_5(struct StateT * v474) {
  int v475 = v474->timer;
  int v479 = v475 + 1;
  v474->timer = v479;
  struct StateT * v477 = slot_7(v474);
  return v477;
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

struct StateT * slot_7(struct StateT * v503) {
  int * v504 = v503->regs;
  int v505 = v504[10];
  int v506 = v504[11];
  bool v614 = (v505 ^ -2147483648) >= (v506 ^ -2147483648);
  struct StateT * v609;
  if (v614) {
    int v507 = v503->timer;
    int v615 = v507 + 15;
    v503->timer = v615;
    int * v509 = v503->reg_ready;
    int v510 = v503->timer;
    v509[0] = v510;
    int * v512 = v503->reg_ready;
    int v513 = v503->timer;
    v512[1] = v513;
    int * v515 = v503->reg_ready;
    int v516 = v503->timer;
    v515[2] = v516;
    int * v518 = v503->reg_ready;
    int v519 = v503->timer;
    v518[3] = v519;
    int * v521 = v503->reg_ready;
    int v522 = v503->timer;
    v521[4] = v522;
    int * v524 = v503->reg_ready;
    int v525 = v503->timer;
    v524[5] = v525;
    int * v527 = v503->reg_ready;
    int v528 = v503->timer;
    v527[6] = v528;
    int * v530 = v503->reg_ready;
    int v531 = v503->timer;
    v530[7] = v531;
    int * v533 = v503->reg_ready;
    int v534 = v503->timer;
    v533[8] = v534;
    int * v536 = v503->reg_ready;
    int v537 = v503->timer;
    v536[9] = v537;
    int * v539 = v503->reg_ready;
    int v540 = v503->timer;
    v539[10] = v540;
    int * v542 = v503->reg_ready;
    int v543 = v503->timer;
    v542[11] = v543;
    int * v545 = v503->reg_ready;
    int v546 = v503->timer;
    v545[12] = v546;
    int * v548 = v503->reg_ready;
    int v549 = v503->timer;
    v548[13] = v549;
    int * v551 = v503->reg_ready;
    int v552 = v503->timer;
    v551[14] = v552;
    int * v554 = v503->reg_ready;
    int v555 = v503->timer;
    v554[15] = v555;
    int * v557 = v503->reg_ready;
    int v558 = v503->timer;
    v557[16] = v558;
    int * v560 = v503->reg_ready;
    int v561 = v503->timer;
    v560[17] = v561;
    int * v563 = v503->reg_ready;
    int v564 = v503->timer;
    v563[18] = v564;
    int * v566 = v503->reg_ready;
    int v567 = v503->timer;
    v566[19] = v567;
    int * v569 = v503->reg_ready;
    int v570 = v503->timer;
    v569[20] = v570;
    int * v572 = v503->reg_ready;
    int v573 = v503->timer;
    v572[21] = v573;
    int * v575 = v503->reg_ready;
    int v576 = v503->timer;
    v575[22] = v576;
    int * v578 = v503->reg_ready;
    int v579 = v503->timer;
    v578[23] = v579;
    int * v581 = v503->reg_ready;
    int v582 = v503->timer;
    v581[24] = v582;
    int * v584 = v503->reg_ready;
    int v585 = v503->timer;
    v584[25] = v585;
    int * v587 = v503->reg_ready;
    int v588 = v503->timer;
    v587[26] = v588;
    int * v590 = v503->reg_ready;
    int v591 = v503->timer;
    v590[27] = v591;
    int * v593 = v503->reg_ready;
    int v594 = v503->timer;
    v593[28] = v594;
    int * v596 = v503->reg_ready;
    int v597 = v503->timer;
    v596[29] = v597;
    int * v599 = v503->reg_ready;
    int v600 = v503->timer;
    v599[30] = v600;
    int * v602 = v503->reg_ready;
    int v603 = v503->timer;
    v602[31] = v603;
    struct StateT * v605 = slot_32(v503);
    v609 = v605;
  } else {
    struct StateT * v607 = slot_10(v503);
    v609 = v607;
  }
  return v609;
}

struct StateT * slot_21(struct StateT * v1112) {
  int v1113 = v1112->timer;
  int v1225 = v1113 + 1;
  v1112->timer = v1225;
  int * v1115 = v1112->reg_ready;
  int v1116 = v1115[10];
  int * v1117 = v1112->regs;
  int v1118 = v1117[10];
  int * v1119 = v1112->cache_tags;
  int v1230 = (((int)((unsigned int)((int)((unsigned int)v1118 >> 2)) >> 1)) & 1) * 2;
  int v1120 = v1119[v1230];
  int v1231 = ((((int)((unsigned int)((int)((unsigned int)v1118 >> 2)) >> 1)) & 1) * 2) + 1;
  int v1121 = v1119[v1231];
  int v1232 = 4 + ((((int)((unsigned int)((int)((unsigned int)v1118 >> 2)) >> 1)) & 3) * 2);
  int v1122 = v1119[v1232];
  int v1233 = (4 + ((((int)((unsigned int)((int)((unsigned int)v1118 >> 2)) >> 1)) & 3) * 2)) + 1;
  int v1123 = v1119[v1233];
  int * v1124 = v1112->cache_vals;
  bool v1234 = !(((~(((v1120 ^ ((int)((unsigned int)((int)((unsigned int)v1118 >> 2)) >> 1))) | (-(v1120 ^ ((int)((unsigned int)((int)((unsigned int)v1118 >> 2)) >> 1))))) >> 31)) | (~(((v1121 ^ ((int)((unsigned int)((int)((unsigned int)v1118 >> 2)) >> 1))) | (-(v1121 ^ ((int)((unsigned int)((int)((unsigned int)v1118 >> 2)) >> 1))))) >> 31))) == 0);
  int v1217;
  if (v1234) {
    int * v1125 = v1112->cache_age;
    int v1236 = ((((int)((unsigned int)((int)((unsigned int)v1118 >> 2)) >> 1)) & 1) * 2) + ((~(((v1121 ^ ((int)((unsigned int)((int)((unsigned int)v1118 >> 2)) >> 1))) | (-(v1121 ^ ((int)((unsigned int)((int)((unsigned int)v1118 >> 2)) >> 1))))) >> 31)) & 1);
    int v1126 = v1125[v1236];
    int v1127 = v1125[v1230];
    int v1237 = v1127 + ((int)((unsigned int)(v1127 - v1126) >> 31));
    v1125[v1230] = v1237;
    int * v1129 = v1112->cache_age;
    int v1130 = v1129[v1231];
    int v1239 = v1130 + ((int)((unsigned int)(v1130 - v1126) >> 31));
    v1129[v1231] = v1239;
    int * v1132 = v1112->cache_age;
    v1132[v1236] = 0;
    v1217 = v1236;
  } else {
    int * v1135 = v1112->cache_age;
    int v1243 = (((int)((unsigned int)((int)((unsigned int)v1118 >> 2)) >> 1)) & 1) * 2;
    int v1136 = v1135[v1243];
    int * v1137 = v1112->cache_tags;
    int v1138 = v1137[v1243];
    int v1139 = v1135[v1231];
    int v1140 = v1137[v1231];
    bool v1245 = !(((~(((v1122 ^ ((int)((unsigned int)((int)((unsigned int)v1118 >> 2)) >> 1))) | (-(v1122 ^ ((int)((unsigned int)((int)((unsigned int)v1118 >> 2)) >> 1))))) >> 31)) | (~(((v1123 ^ ((int)((unsigned int)((int)((unsigned int)v1118 >> 2)) >> 1))) | (-(v1123 ^ ((int)((unsigned int)((int)((unsigned int)v1118 >> 2)) >> 1))))) >> 31))) == 0);
    int v1194;
    if (v1245) {
      int * v1141 = v1112->cache_age;
      int v1247 = (4 + ((((int)((unsigned int)((int)((unsigned int)v1118 >> 2)) >> 1)) & 3) * 2)) + ((~(((v1123 ^ ((int)((unsigned int)((int)((unsigned int)v1118 >> 2)) >> 1))) | (-(v1123 ^ ((int)((unsigned int)((int)((unsigned int)v1118 >> 2)) >> 1))))) >> 31)) & 1);
      int v1142 = v1141[v1247];
      int v1143 = v1141[v1232];
      int v1248 = v1143 + ((int)((unsigned int)(v1143 - v1142) >> 31));
      v1141[v1232] = v1248;
      int * v1145 = v1112->cache_age;
      int v1146 = v1145[v1233];
      int v1250 = v1146 + ((int)((unsigned int)(v1146 - v1142) >> 31));
      v1145[v1233] = v1250;
      int * v1148 = v1112->cache_age;
      v1148[v1247] = 0;
      v1194 = v1247;
    } else {
      int * v1151 = v1112->cache_age;
      int v1254 = 4 + ((((int)((unsigned int)((int)((unsigned int)v1118 >> 2)) >> 1)) & 3) * 2);
      int v1152 = v1151[v1254];
      int * v1153 = v1112->cache_tags;
      int v1154 = v1153[v1254];
      int v1155 = v1151[v1233];
      int v1156 = v1153[v1233];
      int * v1157 = v1112->cache_dirty;
      int v1257 = (4 + ((((int)((unsigned int)((int)((unsigned int)v1118 >> 2)) >> 1)) & 3) * 2)) + ((((v1152 + ((~(((v1154 ^ -1) | (-(v1154 ^ -1))) >> 31)) & 2)) - (v1155 + ((~(((v1156 ^ -1) | (-(v1156 ^ -1))) >> 31)) & 2))) >> 31) & 1);
      int v1158 = v1157[v1257];
      bool v1258 = !(v1158 == 0);
      if (v1258) {
        int * v1159 = v1112->cache_tags;
        int v1160 = v1159[v1257];
        int * v1161 = v1112->cache_vals;
        int v1261 = ((4 + ((((int)((unsigned int)((int)((unsigned int)v1118 >> 2)) >> 1)) & 3) * 2)) + ((((v1152 + ((~(((v1154 ^ -1) | (-(v1154 ^ -1))) >> 31)) & 2)) - (v1155 + ((~(((v1156 ^ -1) | (-(v1156 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
        int v1162 = v1161[v1261];
        int v1262 = (((4 + ((((int)((unsigned int)((int)((unsigned int)v1118 >> 2)) >> 1)) & 3) * 2)) + ((((v1152 + ((~(((v1154 ^ -1) | (-(v1154 ^ -1))) >> 31)) & 2)) - (v1155 + ((~(((v1156 ^ -1) | (-(v1156 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
        int v1163 = v1161[v1262];
        int * v1164 = v1112->mem;
        int v1264 = v1160 * 2;
        v1164[v1264] = v1162;
        int * v1166 = v1112->mem;
        int v1267 = (v1160 * 2) + 1;
        v1166[v1267] = v1163;
        ;
      } else {
        ;
      }
      int * v1171 = v1112->mem;
      int v1272 = ((int)((unsigned int)((int)((unsigned int)v1118 >> 2)) >> 1)) * 2;
      int v1172 = v1171[v1272];
      int v1273 = (((int)((unsigned int)((int)((unsigned int)v1118 >> 2)) >> 1)) * 2) + 1;
      int v1173 = v1171[v1273];
      int * v1174 = v1112->cache_vals;
      int v1275 = ((4 + ((((int)((unsigned int)((int)((unsigned int)v1118 >> 2)) >> 1)) & 3) * 2)) + ((((v1152 + ((~(((v1154 ^ -1) | (-(v1154 ^ -1))) >> 31)) & 2)) - (v1155 + ((~(((v1156 ^ -1) | (-(v1156 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
      v1174[v1275] = v1172;
      int * v1176 = v1112->cache_vals;
      int v1278 = (((4 + ((((int)((unsigned int)((int)((unsigned int)v1118 >> 2)) >> 1)) & 3) * 2)) + ((((v1152 + ((~(((v1154 ^ -1) | (-(v1154 ^ -1))) >> 31)) & 2)) - (v1155 + ((~(((v1156 ^ -1) | (-(v1156 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
      v1176[v1278] = v1173;
      int * v1178 = v1112->cache_tags;
      int v1281 = (int)((unsigned int)((int)((unsigned int)v1118 >> 2)) >> 1);
      v1178[v1257] = v1281;
      int * v1180 = v1112->cache_dirty;
      v1180[v1257] = 0;
      int * v1182 = v1112->cache_age;
      v1182[v1257] = 1;
      int * v1184 = v1112->cache_age;
      int v1185 = v1184[v1257];
      int v1186 = v1184[v1232];
      int v1287 = v1186 + ((int)((unsigned int)(v1186 - v1185) >> 31));
      v1184[v1232] = v1287;
      int * v1188 = v1112->cache_age;
      int v1189 = v1188[v1233];
      int v1289 = v1189 + ((int)((unsigned int)(v1189 - v1185) >> 31));
      v1188[v1233] = v1289;
      int * v1191 = v1112->cache_age;
      v1191[v1257] = 0;
      v1194 = v1257;
    }
    int * v1195 = v1112->cache_vals;
    int v1292 = v1194 * 2;
    int v1196 = v1195[v1292];
    int v1293 = (v1194 * 2) + 1;
    int v1197 = v1195[v1293];
    int v1294 = (((((int)((unsigned int)((int)((unsigned int)v1118 >> 2)) >> 1)) & 1) * 2) + ((((v1136 + ((~(((v1138 ^ -1) | (-(v1138 ^ -1))) >> 31)) & 2)) - (v1139 + ((~(((v1140 ^ -1) | (-(v1140 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
    v1195[v1294] = v1196;
    int * v1199 = v1112->cache_vals;
    int v1297 = ((((((int)((unsigned int)((int)((unsigned int)v1118 >> 2)) >> 1)) & 1) * 2) + ((((v1136 + ((~(((v1138 ^ -1) | (-(v1138 ^ -1))) >> 31)) & 2)) - (v1139 + ((~(((v1140 ^ -1) | (-(v1140 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
    v1199[v1297] = v1197;
    int * v1201 = v1112->cache_tags;
    int v1300 = ((((int)((unsigned int)((int)((unsigned int)v1118 >> 2)) >> 1)) & 1) * 2) + ((((v1136 + ((~(((v1138 ^ -1) | (-(v1138 ^ -1))) >> 31)) & 2)) - (v1139 + ((~(((v1140 ^ -1) | (-(v1140 ^ -1))) >> 31)) & 2))) >> 31) & 1);
    int v1301 = (int)((unsigned int)((int)((unsigned int)v1118 >> 2)) >> 1);
    v1201[v1300] = v1301;
    int * v1203 = v1112->cache_dirty;
    v1203[v1300] = 0;
    int * v1205 = v1112->cache_age;
    v1205[v1300] = 1;
    int * v1207 = v1112->cache_age;
    int v1208 = v1207[v1300];
    int v1209 = v1207[v1230];
    int v1307 = v1209 + ((int)((unsigned int)(v1209 - v1208) >> 31));
    v1207[v1230] = v1307;
    int * v1211 = v1112->cache_age;
    int v1212 = v1211[v1231];
    int v1309 = v1212 + ((int)((unsigned int)(v1212 - v1208) >> 31));
    v1211[v1231] = v1309;
    int * v1214 = v1112->cache_age;
    v1214[v1300] = 0;
    v1217 = v1300;
  }
  int v1312 = (v1217 * 2) + (((int)((unsigned int)v1118 >> 2)) & 1);
  int v1218 = v1124[v1312];
  int * v1219 = v1112->reg_ready;
  int v1314 = ((v1116 + ((v1113 - v1116) & (~((v1113 - v1116) >> 31)))) + 1) + ((100 ^ (((~(((v1122 ^ ((int)((unsigned int)((int)((unsigned int)v1118 >> 2)) >> 1))) | (-(v1122 ^ ((int)((unsigned int)((int)((unsigned int)v1118 >> 2)) >> 1))))) >> 31)) | (~(((v1123 ^ ((int)((unsigned int)((int)((unsigned int)v1118 >> 2)) >> 1))) | (-(v1123 ^ ((int)((unsigned int)((int)((unsigned int)v1118 >> 2)) >> 1))))) >> 31))) & 104)) ^ (((~(((v1120 ^ ((int)((unsigned int)((int)((unsigned int)v1118 >> 2)) >> 1))) | (-(v1120 ^ ((int)((unsigned int)((int)((unsigned int)v1118 >> 2)) >> 1))))) >> 31)) | (~(((v1121 ^ ((int)((unsigned int)((int)((unsigned int)v1118 >> 2)) >> 1))) | (-(v1121 ^ ((int)((unsigned int)((int)((unsigned int)v1118 >> 2)) >> 1))))) >> 31))) & (1 ^ (100 ^ (((~(((v1122 ^ ((int)((unsigned int)((int)((unsigned int)v1118 >> 2)) >> 1))) | (-(v1122 ^ ((int)((unsigned int)((int)((unsigned int)v1118 >> 2)) >> 1))))) >> 31)) | (~(((v1123 ^ ((int)((unsigned int)((int)((unsigned int)v1118 >> 2)) >> 1))) | (-(v1123 ^ ((int)((unsigned int)((int)((unsigned int)v1118 >> 2)) >> 1))))) >> 31))) & 104)))));
  v1219[10] = v1314;
  int * v1221 = v1112->regs;
  v1221[10] = v1218;
  struct StateT * v1223 = slot_23(v1112);
  return v1223;
}

struct StateT * slot_31(struct StateT * v2175) {
  int v2176 = v2175->timer;
  int v2187 = v2176 + 1;
  v2175->timer = v2187;
  int * v2178 = v2175->reg_ready;
  int v2179 = v2178[10];
  int * v2180 = v2175->regs;
  int v2181 = v2180[10];
  int v2191 = (v2179 + ((v2176 - v2179) & (~((v2176 - v2179) >> 31)))) + 1;
  v2178[10] = v2191;
  int * v2183 = v2175->regs;
  int v2193 = (int)((unsigned int)v2181 >> 26);
  v2183[10] = v2193;
  struct StateT * v2185 = slot_33(v2175);
  return v2185;
}

struct StateT * slot_3(struct StateT * v240) {
  int * v241 = v240->regs;
  int v242 = v241[10];
  bool v353 = v242 == 0;
  struct StateT * v349;
  if (v353) {
    int v243 = v240->timer;
    int v354 = v243 + 15;
    v240->timer = v354;
    int * v245 = v240->saved_regs;
    int v246 = v245[11];
    int * v247 = v240->regs;
    v247[11] = v246;
    int * v249 = v240->reg_ready;
    int v250 = v240->timer;
    v249[0] = v250;
    int * v252 = v240->reg_ready;
    int v253 = v240->timer;
    v252[1] = v253;
    int * v255 = v240->reg_ready;
    int v256 = v240->timer;
    v255[2] = v256;
    int * v258 = v240->reg_ready;
    int v259 = v240->timer;
    v258[3] = v259;
    int * v261 = v240->reg_ready;
    int v262 = v240->timer;
    v261[4] = v262;
    int * v264 = v240->reg_ready;
    int v265 = v240->timer;
    v264[5] = v265;
    int * v267 = v240->reg_ready;
    int v268 = v240->timer;
    v267[6] = v268;
    int * v270 = v240->reg_ready;
    int v271 = v240->timer;
    v270[7] = v271;
    int * v273 = v240->reg_ready;
    int v274 = v240->timer;
    v273[8] = v274;
    int * v276 = v240->reg_ready;
    int v277 = v240->timer;
    v276[9] = v277;
    int * v279 = v240->reg_ready;
    int v280 = v240->timer;
    v279[10] = v280;
    int * v282 = v240->reg_ready;
    int v283 = v240->timer;
    v282[11] = v283;
    int * v285 = v240->reg_ready;
    int v286 = v240->timer;
    v285[12] = v286;
    int * v288 = v240->reg_ready;
    int v289 = v240->timer;
    v288[13] = v289;
    int * v291 = v240->reg_ready;
    int v292 = v240->timer;
    v291[14] = v292;
    int * v294 = v240->reg_ready;
    int v295 = v240->timer;
    v294[15] = v295;
    int * v297 = v240->reg_ready;
    int v298 = v240->timer;
    v297[16] = v298;
    int * v300 = v240->reg_ready;
    int v301 = v240->timer;
    v300[17] = v301;
    int * v303 = v240->reg_ready;
    int v304 = v240->timer;
    v303[18] = v304;
    int * v306 = v240->reg_ready;
    int v307 = v240->timer;
    v306[19] = v307;
    int * v309 = v240->reg_ready;
    int v310 = v240->timer;
    v309[20] = v310;
    int * v312 = v240->reg_ready;
    int v313 = v240->timer;
    v312[21] = v313;
    int * v315 = v240->reg_ready;
    int v316 = v240->timer;
    v315[22] = v316;
    int * v318 = v240->reg_ready;
    int v319 = v240->timer;
    v318[23] = v319;
    int * v321 = v240->reg_ready;
    int v322 = v240->timer;
    v321[24] = v322;
    int * v324 = v240->reg_ready;
    int v325 = v240->timer;
    v324[25] = v325;
    int * v327 = v240->reg_ready;
    int v328 = v240->timer;
    v327[26] = v328;
    int * v330 = v240->reg_ready;
    int v331 = v240->timer;
    v330[27] = v331;
    int * v333 = v240->reg_ready;
    int v334 = v240->timer;
    v333[28] = v334;
    int * v336 = v240->reg_ready;
    int v337 = v240->timer;
    v336[29] = v337;
    int * v339 = v240->reg_ready;
    int v340 = v240->timer;
    v339[30] = v340;
    int * v342 = v240->reg_ready;
    int v343 = v240->timer;
    v342[31] = v343;
    struct StateT * v345 = slot_4(v240);
    v349 = v345;
  } else {
    struct StateT * v347 = slot_5(v240);
    v349 = v347;
  }
  return v349;
}

struct StateT * slot_26(struct StateT * v1587) {
  int v1588 = v1587->timer;
  int v1700 = v1588 + 1;
  v1587->timer = v1700;
  int * v1590 = v1587->reg_ready;
  int v1591 = v1590[12];
  int * v1592 = v1587->regs;
  int v1593 = v1592[12];
  int * v1594 = v1587->cache_tags;
  int v1705 = (((int)((unsigned int)((int)((unsigned int)(v1593 + 68) >> 2)) >> 1)) & 1) * 2;
  int v1595 = v1594[v1705];
  int v1706 = ((((int)((unsigned int)((int)((unsigned int)(v1593 + 68) >> 2)) >> 1)) & 1) * 2) + 1;
  int v1596 = v1594[v1706];
  int v1707 = 4 + ((((int)((unsigned int)((int)((unsigned int)(v1593 + 68) >> 2)) >> 1)) & 3) * 2);
  int v1597 = v1594[v1707];
  int v1708 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v1593 + 68) >> 2)) >> 1)) & 3) * 2)) + 1;
  int v1598 = v1594[v1708];
  int * v1599 = v1587->cache_vals;
  bool v1709 = !(((~(((v1595 ^ ((int)((unsigned int)((int)((unsigned int)(v1593 + 68) >> 2)) >> 1))) | (-(v1595 ^ ((int)((unsigned int)((int)((unsigned int)(v1593 + 68) >> 2)) >> 1))))) >> 31)) | (~(((v1596 ^ ((int)((unsigned int)((int)((unsigned int)(v1593 + 68) >> 2)) >> 1))) | (-(v1596 ^ ((int)((unsigned int)((int)((unsigned int)(v1593 + 68) >> 2)) >> 1))))) >> 31))) == 0);
  int v1692;
  if (v1709) {
    int * v1600 = v1587->cache_age;
    int v1711 = ((((int)((unsigned int)((int)((unsigned int)(v1593 + 68) >> 2)) >> 1)) & 1) * 2) + ((~(((v1596 ^ ((int)((unsigned int)((int)((unsigned int)(v1593 + 68) >> 2)) >> 1))) | (-(v1596 ^ ((int)((unsigned int)((int)((unsigned int)(v1593 + 68) >> 2)) >> 1))))) >> 31)) & 1);
    int v1601 = v1600[v1711];
    int v1602 = v1600[v1705];
    int v1712 = v1602 + ((int)((unsigned int)(v1602 - v1601) >> 31));
    v1600[v1705] = v1712;
    int * v1604 = v1587->cache_age;
    int v1605 = v1604[v1706];
    int v1714 = v1605 + ((int)((unsigned int)(v1605 - v1601) >> 31));
    v1604[v1706] = v1714;
    int * v1607 = v1587->cache_age;
    v1607[v1711] = 0;
    v1692 = v1711;
  } else {
    int * v1610 = v1587->cache_age;
    int v1718 = (((int)((unsigned int)((int)((unsigned int)(v1593 + 68) >> 2)) >> 1)) & 1) * 2;
    int v1611 = v1610[v1718];
    int * v1612 = v1587->cache_tags;
    int v1613 = v1612[v1718];
    int v1614 = v1610[v1706];
    int v1615 = v1612[v1706];
    bool v1720 = !(((~(((v1597 ^ ((int)((unsigned int)((int)((unsigned int)(v1593 + 68) >> 2)) >> 1))) | (-(v1597 ^ ((int)((unsigned int)((int)((unsigned int)(v1593 + 68) >> 2)) >> 1))))) >> 31)) | (~(((v1598 ^ ((int)((unsigned int)((int)((unsigned int)(v1593 + 68) >> 2)) >> 1))) | (-(v1598 ^ ((int)((unsigned int)((int)((unsigned int)(v1593 + 68) >> 2)) >> 1))))) >> 31))) == 0);
    int v1669;
    if (v1720) {
      int * v1616 = v1587->cache_age;
      int v1722 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v1593 + 68) >> 2)) >> 1)) & 3) * 2)) + ((~(((v1598 ^ ((int)((unsigned int)((int)((unsigned int)(v1593 + 68) >> 2)) >> 1))) | (-(v1598 ^ ((int)((unsigned int)((int)((unsigned int)(v1593 + 68) >> 2)) >> 1))))) >> 31)) & 1);
      int v1617 = v1616[v1722];
      int v1618 = v1616[v1707];
      int v1723 = v1618 + ((int)((unsigned int)(v1618 - v1617) >> 31));
      v1616[v1707] = v1723;
      int * v1620 = v1587->cache_age;
      int v1621 = v1620[v1708];
      int v1725 = v1621 + ((int)((unsigned int)(v1621 - v1617) >> 31));
      v1620[v1708] = v1725;
      int * v1623 = v1587->cache_age;
      v1623[v1722] = 0;
      v1669 = v1722;
    } else {
      int * v1626 = v1587->cache_age;
      int v1729 = 4 + ((((int)((unsigned int)((int)((unsigned int)(v1593 + 68) >> 2)) >> 1)) & 3) * 2);
      int v1627 = v1626[v1729];
      int * v1628 = v1587->cache_tags;
      int v1629 = v1628[v1729];
      int v1630 = v1626[v1708];
      int v1631 = v1628[v1708];
      int * v1632 = v1587->cache_dirty;
      int v1732 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v1593 + 68) >> 2)) >> 1)) & 3) * 2)) + ((((v1627 + ((~(((v1629 ^ -1) | (-(v1629 ^ -1))) >> 31)) & 2)) - (v1630 + ((~(((v1631 ^ -1) | (-(v1631 ^ -1))) >> 31)) & 2))) >> 31) & 1);
      int v1633 = v1632[v1732];
      bool v1733 = !(v1633 == 0);
      if (v1733) {
        int * v1634 = v1587->cache_tags;
        int v1635 = v1634[v1732];
        int * v1636 = v1587->cache_vals;
        int v1736 = ((4 + ((((int)((unsigned int)((int)((unsigned int)(v1593 + 68) >> 2)) >> 1)) & 3) * 2)) + ((((v1627 + ((~(((v1629 ^ -1) | (-(v1629 ^ -1))) >> 31)) & 2)) - (v1630 + ((~(((v1631 ^ -1) | (-(v1631 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
        int v1637 = v1636[v1736];
        int v1737 = (((4 + ((((int)((unsigned int)((int)((unsigned int)(v1593 + 68) >> 2)) >> 1)) & 3) * 2)) + ((((v1627 + ((~(((v1629 ^ -1) | (-(v1629 ^ -1))) >> 31)) & 2)) - (v1630 + ((~(((v1631 ^ -1) | (-(v1631 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
        int v1638 = v1636[v1737];
        int * v1639 = v1587->mem;
        int v1739 = v1635 * 2;
        v1639[v1739] = v1637;
        int * v1641 = v1587->mem;
        int v1742 = (v1635 * 2) + 1;
        v1641[v1742] = v1638;
        ;
      } else {
        ;
      }
      int * v1646 = v1587->mem;
      int v1747 = ((int)((unsigned int)((int)((unsigned int)(v1593 + 68) >> 2)) >> 1)) * 2;
      int v1647 = v1646[v1747];
      int v1748 = (((int)((unsigned int)((int)((unsigned int)(v1593 + 68) >> 2)) >> 1)) * 2) + 1;
      int v1648 = v1646[v1748];
      int * v1649 = v1587->cache_vals;
      int v1750 = ((4 + ((((int)((unsigned int)((int)((unsigned int)(v1593 + 68) >> 2)) >> 1)) & 3) * 2)) + ((((v1627 + ((~(((v1629 ^ -1) | (-(v1629 ^ -1))) >> 31)) & 2)) - (v1630 + ((~(((v1631 ^ -1) | (-(v1631 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
      v1649[v1750] = v1647;
      int * v1651 = v1587->cache_vals;
      int v1753 = (((4 + ((((int)((unsigned int)((int)((unsigned int)(v1593 + 68) >> 2)) >> 1)) & 3) * 2)) + ((((v1627 + ((~(((v1629 ^ -1) | (-(v1629 ^ -1))) >> 31)) & 2)) - (v1630 + ((~(((v1631 ^ -1) | (-(v1631 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
      v1651[v1753] = v1648;
      int * v1653 = v1587->cache_tags;
      int v1756 = (int)((unsigned int)((int)((unsigned int)(v1593 + 68) >> 2)) >> 1);
      v1653[v1732] = v1756;
      int * v1655 = v1587->cache_dirty;
      v1655[v1732] = 0;
      int * v1657 = v1587->cache_age;
      v1657[v1732] = 1;
      int * v1659 = v1587->cache_age;
      int v1660 = v1659[v1732];
      int v1661 = v1659[v1707];
      int v1762 = v1661 + ((int)((unsigned int)(v1661 - v1660) >> 31));
      v1659[v1707] = v1762;
      int * v1663 = v1587->cache_age;
      int v1664 = v1663[v1708];
      int v1764 = v1664 + ((int)((unsigned int)(v1664 - v1660) >> 31));
      v1663[v1708] = v1764;
      int * v1666 = v1587->cache_age;
      v1666[v1732] = 0;
      v1669 = v1732;
    }
    int * v1670 = v1587->cache_vals;
    int v1767 = v1669 * 2;
    int v1671 = v1670[v1767];
    int v1768 = (v1669 * 2) + 1;
    int v1672 = v1670[v1768];
    int v1769 = (((((int)((unsigned int)((int)((unsigned int)(v1593 + 68) >> 2)) >> 1)) & 1) * 2) + ((((v1611 + ((~(((v1613 ^ -1) | (-(v1613 ^ -1))) >> 31)) & 2)) - (v1614 + ((~(((v1615 ^ -1) | (-(v1615 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
    v1670[v1769] = v1671;
    int * v1674 = v1587->cache_vals;
    int v1772 = ((((((int)((unsigned int)((int)((unsigned int)(v1593 + 68) >> 2)) >> 1)) & 1) * 2) + ((((v1611 + ((~(((v1613 ^ -1) | (-(v1613 ^ -1))) >> 31)) & 2)) - (v1614 + ((~(((v1615 ^ -1) | (-(v1615 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
    v1674[v1772] = v1672;
    int * v1676 = v1587->cache_tags;
    int v1775 = ((((int)((unsigned int)((int)((unsigned int)(v1593 + 68) >> 2)) >> 1)) & 1) * 2) + ((((v1611 + ((~(((v1613 ^ -1) | (-(v1613 ^ -1))) >> 31)) & 2)) - (v1614 + ((~(((v1615 ^ -1) | (-(v1615 ^ -1))) >> 31)) & 2))) >> 31) & 1);
    int v1776 = (int)((unsigned int)((int)((unsigned int)(v1593 + 68) >> 2)) >> 1);
    v1676[v1775] = v1776;
    int * v1678 = v1587->cache_dirty;
    v1678[v1775] = 0;
    int * v1680 = v1587->cache_age;
    v1680[v1775] = 1;
    int * v1682 = v1587->cache_age;
    int v1683 = v1682[v1775];
    int v1684 = v1682[v1705];
    int v1782 = v1684 + ((int)((unsigned int)(v1684 - v1683) >> 31));
    v1682[v1705] = v1782;
    int * v1686 = v1587->cache_age;
    int v1687 = v1686[v1706];
    int v1784 = v1687 + ((int)((unsigned int)(v1687 - v1683) >> 31));
    v1686[v1706] = v1784;
    int * v1689 = v1587->cache_age;
    v1689[v1775] = 0;
    v1692 = v1775;
  }
  int v1787 = (v1692 * 2) + (((int)((unsigned int)(v1593 + 68) >> 2)) & 1);
  int v1693 = v1599[v1787];
  int * v1694 = v1587->reg_ready;
  int v1790 = ((v1591 + ((v1588 - v1591) & (~((v1588 - v1591) >> 31)))) + 1) + ((100 ^ (((~(((v1597 ^ ((int)((unsigned int)((int)((unsigned int)(v1593 + 68) >> 2)) >> 1))) | (-(v1597 ^ ((int)((unsigned int)((int)((unsigned int)(v1593 + 68) >> 2)) >> 1))))) >> 31)) | (~(((v1598 ^ ((int)((unsigned int)((int)((unsigned int)(v1593 + 68) >> 2)) >> 1))) | (-(v1598 ^ ((int)((unsigned int)((int)((unsigned int)(v1593 + 68) >> 2)) >> 1))))) >> 31))) & 104)) ^ (((~(((v1595 ^ ((int)((unsigned int)((int)((unsigned int)(v1593 + 68) >> 2)) >> 1))) | (-(v1595 ^ ((int)((unsigned int)((int)((unsigned int)(v1593 + 68) >> 2)) >> 1))))) >> 31)) | (~(((v1596 ^ ((int)((unsigned int)((int)((unsigned int)(v1593 + 68) >> 2)) >> 1))) | (-(v1596 ^ ((int)((unsigned int)((int)((unsigned int)(v1593 + 68) >> 2)) >> 1))))) >> 31))) & (1 ^ (100 ^ (((~(((v1597 ^ ((int)((unsigned int)((int)((unsigned int)(v1593 + 68) >> 2)) >> 1))) | (-(v1597 ^ ((int)((unsigned int)((int)((unsigned int)(v1593 + 68) >> 2)) >> 1))))) >> 31)) | (~(((v1598 ^ ((int)((unsigned int)((int)((unsigned int)(v1593 + 68) >> 2)) >> 1))) | (-(v1598 ^ ((int)((unsigned int)((int)((unsigned int)(v1593 + 68) >> 2)) >> 1))))) >> 31))) & 104)))));
  v1694[11] = v1790;
  int * v1696 = v1587->regs;
  v1696[11] = v1693;
  struct StateT * v1698 = slot_28(v1587);
  return v1698;
}

struct StateT * slot_10(struct StateT * v927) {
  int v928 = v927->timer;
  int v939 = v928 + 1;
  v927->timer = v939;
  int * v930 = v927->reg_ready;
  int v931 = v930[10];
  int * v932 = v927->regs;
  int v933 = v932[10];
  int v943 = (v931 + ((v928 - v931) & (~((v928 - v931) >> 31)))) + 1;
  v930[10] = v943;
  int * v935 = v927->regs;
  int v945 = v933 << 2;
  v935[10] = v945;
  struct StateT * v937 = slot_13(v927);
  return v937;
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

struct StateT * slot_19(struct StateT * v1083) {
  int v1084 = v1083->timer;
  int v1088 = v1084 + 1;
  v1083->timer = v1088;
  struct StateT * v1086 = slot_21(v1083);
  return v1086;
}

struct StateT * slot_13(struct StateT * v964) {
  int v965 = v964->timer;
  int v973 = v965 + 1;
  v964->timer = v973;
  int * v967 = v964->reg_ready;
  v967[11] = v973;
  int * v969 = v964->regs;
  v969[11] = 0;
  struct StateT * v971 = slot_15(v964);
  return v971;
}

struct StateT * slot_38(struct StateT * v2664) {
  int v2665 = v2664->timer;
  int v2838 = v2665 + 1;
  v2664->timer = v2838;
  int * v2667 = v2664->reg_ready;
  int * v2669 = v2664->regs;
  int v2670 = v2669[12];
  int v2672 = v2669[10];
  int * v2673 = v2664->cache_tags;
  int v2844 = (((int)((unsigned int)((int)((unsigned int)(v2670 + 68) >> 2)) >> 1)) & 1) * 2;
  int v2674 = v2673[v2844];
  int v2845 = ((((int)((unsigned int)((int)((unsigned int)(v2670 + 68) >> 2)) >> 1)) & 1) * 2) + 1;
  int v2675 = v2673[v2845];
  int v2846 = 4 + ((((int)((unsigned int)((int)((unsigned int)(v2670 + 68) >> 2)) >> 1)) & 3) * 2);
  int v2676 = v2673[v2846];
  int v2847 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v2670 + 68) >> 2)) >> 1)) & 3) * 2)) + 1;
  int v2677 = v2673[v2847];
  int v2678 = v2664->timer;
  int v2848 = v2678 + ((100 ^ (((~(((v2676 ^ ((int)((unsigned int)((int)((unsigned int)(v2670 + 68) >> 2)) >> 1))) | (-(v2676 ^ ((int)((unsigned int)((int)((unsigned int)(v2670 + 68) >> 2)) >> 1))))) >> 31)) | (~(((v2677 ^ ((int)((unsigned int)((int)((unsigned int)(v2670 + 68) >> 2)) >> 1))) | (-(v2677 ^ ((int)((unsigned int)((int)((unsigned int)(v2670 + 68) >> 2)) >> 1))))) >> 31))) & 104)) ^ (((~(((v2674 ^ ((int)((unsigned int)((int)((unsigned int)(v2670 + 68) >> 2)) >> 1))) | (-(v2674 ^ ((int)((unsigned int)((int)((unsigned int)(v2670 + 68) >> 2)) >> 1))))) >> 31)) | (~(((v2675 ^ ((int)((unsigned int)((int)((unsigned int)(v2670 + 68) >> 2)) >> 1))) | (-(v2675 ^ ((int)((unsigned int)((int)((unsigned int)(v2670 + 68) >> 2)) >> 1))))) >> 31))) & (1 ^ (100 ^ (((~(((v2676 ^ ((int)((unsigned int)((int)((unsigned int)(v2670 + 68) >> 2)) >> 1))) | (-(v2676 ^ ((int)((unsigned int)((int)((unsigned int)(v2670 + 68) >> 2)) >> 1))))) >> 31)) | (~(((v2677 ^ ((int)((unsigned int)((int)((unsigned int)(v2670 + 68) >> 2)) >> 1))) | (-(v2677 ^ ((int)((unsigned int)((int)((unsigned int)(v2670 + 68) >> 2)) >> 1))))) >> 31))) & 104)))));
  v2664->timer = v2848;
  bool v2849 = !(((~(((v2674 ^ ((int)((unsigned int)((int)((unsigned int)(v2670 + 68) >> 2)) >> 1))) | (-(v2674 ^ ((int)((unsigned int)((int)((unsigned int)(v2670 + 68) >> 2)) >> 1))))) >> 31)) | (~(((v2675 ^ ((int)((unsigned int)((int)((unsigned int)(v2670 + 68) >> 2)) >> 1))) | (-(v2675 ^ ((int)((unsigned int)((int)((unsigned int)(v2670 + 68) >> 2)) >> 1))))) >> 31))) == 0);
  int v2772;
  if (v2849) {
    int * v2680 = v2664->cache_age;
    int v2851 = ((((int)((unsigned int)((int)((unsigned int)(v2670 + 68) >> 2)) >> 1)) & 1) * 2) + ((~(((v2675 ^ ((int)((unsigned int)((int)((unsigned int)(v2670 + 68) >> 2)) >> 1))) | (-(v2675 ^ ((int)((unsigned int)((int)((unsigned int)(v2670 + 68) >> 2)) >> 1))))) >> 31)) & 1);
    int v2681 = v2680[v2851];
    int v2682 = v2680[v2844];
    int v2852 = v2682 + ((int)((unsigned int)(v2682 - v2681) >> 31));
    v2680[v2844] = v2852;
    int * v2684 = v2664->cache_age;
    int v2685 = v2684[v2845];
    int v2854 = v2685 + ((int)((unsigned int)(v2685 - v2681) >> 31));
    v2684[v2845] = v2854;
    int * v2687 = v2664->cache_age;
    v2687[v2851] = 0;
    v2772 = v2851;
  } else {
    int * v2690 = v2664->cache_age;
    int v2858 = (((int)((unsigned int)((int)((unsigned int)(v2670 + 68) >> 2)) >> 1)) & 1) * 2;
    int v2691 = v2690[v2858];
    int * v2692 = v2664->cache_tags;
    int v2693 = v2692[v2858];
    int v2694 = v2690[v2845];
    int v2695 = v2692[v2845];
    bool v2860 = !(((~(((v2676 ^ ((int)((unsigned int)((int)((unsigned int)(v2670 + 68) >> 2)) >> 1))) | (-(v2676 ^ ((int)((unsigned int)((int)((unsigned int)(v2670 + 68) >> 2)) >> 1))))) >> 31)) | (~(((v2677 ^ ((int)((unsigned int)((int)((unsigned int)(v2670 + 68) >> 2)) >> 1))) | (-(v2677 ^ ((int)((unsigned int)((int)((unsigned int)(v2670 + 68) >> 2)) >> 1))))) >> 31))) == 0);
    int v2749;
    if (v2860) {
      int * v2696 = v2664->cache_age;
      int v2862 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v2670 + 68) >> 2)) >> 1)) & 3) * 2)) + ((~(((v2677 ^ ((int)((unsigned int)((int)((unsigned int)(v2670 + 68) >> 2)) >> 1))) | (-(v2677 ^ ((int)((unsigned int)((int)((unsigned int)(v2670 + 68) >> 2)) >> 1))))) >> 31)) & 1);
      int v2697 = v2696[v2862];
      int v2698 = v2696[v2846];
      int v2863 = v2698 + ((int)((unsigned int)(v2698 - v2697) >> 31));
      v2696[v2846] = v2863;
      int * v2700 = v2664->cache_age;
      int v2701 = v2700[v2847];
      int v2865 = v2701 + ((int)((unsigned int)(v2701 - v2697) >> 31));
      v2700[v2847] = v2865;
      int * v2703 = v2664->cache_age;
      v2703[v2862] = 0;
      v2749 = v2862;
    } else {
      int * v2706 = v2664->cache_age;
      int v2869 = 4 + ((((int)((unsigned int)((int)((unsigned int)(v2670 + 68) >> 2)) >> 1)) & 3) * 2);
      int v2707 = v2706[v2869];
      int * v2708 = v2664->cache_tags;
      int v2709 = v2708[v2869];
      int v2710 = v2706[v2847];
      int v2711 = v2708[v2847];
      int * v2712 = v2664->cache_dirty;
      int v2872 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v2670 + 68) >> 2)) >> 1)) & 3) * 2)) + ((((v2707 + ((~(((v2709 ^ -1) | (-(v2709 ^ -1))) >> 31)) & 2)) - (v2710 + ((~(((v2711 ^ -1) | (-(v2711 ^ -1))) >> 31)) & 2))) >> 31) & 1);
      int v2713 = v2712[v2872];
      bool v2873 = !(v2713 == 0);
      if (v2873) {
        int * v2714 = v2664->cache_tags;
        int v2715 = v2714[v2872];
        int * v2716 = v2664->cache_vals;
        int v2876 = ((4 + ((((int)((unsigned int)((int)((unsigned int)(v2670 + 68) >> 2)) >> 1)) & 3) * 2)) + ((((v2707 + ((~(((v2709 ^ -1) | (-(v2709 ^ -1))) >> 31)) & 2)) - (v2710 + ((~(((v2711 ^ -1) | (-(v2711 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
        int v2717 = v2716[v2876];
        int v2877 = (((4 + ((((int)((unsigned int)((int)((unsigned int)(v2670 + 68) >> 2)) >> 1)) & 3) * 2)) + ((((v2707 + ((~(((v2709 ^ -1) | (-(v2709 ^ -1))) >> 31)) & 2)) - (v2710 + ((~(((v2711 ^ -1) | (-(v2711 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
        int v2718 = v2716[v2877];
        int * v2719 = v2664->mem;
        int v2879 = v2715 * 2;
        v2719[v2879] = v2717;
        int * v2721 = v2664->mem;
        int v2882 = (v2715 * 2) + 1;
        v2721[v2882] = v2718;
        ;
      } else {
        ;
      }
      int * v2726 = v2664->mem;
      int v2887 = ((int)((unsigned int)((int)((unsigned int)(v2670 + 68) >> 2)) >> 1)) * 2;
      int v2727 = v2726[v2887];
      int v2888 = (((int)((unsigned int)((int)((unsigned int)(v2670 + 68) >> 2)) >> 1)) * 2) + 1;
      int v2728 = v2726[v2888];
      int * v2729 = v2664->cache_vals;
      int v2890 = ((4 + ((((int)((unsigned int)((int)((unsigned int)(v2670 + 68) >> 2)) >> 1)) & 3) * 2)) + ((((v2707 + ((~(((v2709 ^ -1) | (-(v2709 ^ -1))) >> 31)) & 2)) - (v2710 + ((~(((v2711 ^ -1) | (-(v2711 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
      v2729[v2890] = v2727;
      int * v2731 = v2664->cache_vals;
      int v2893 = (((4 + ((((int)((unsigned int)((int)((unsigned int)(v2670 + 68) >> 2)) >> 1)) & 3) * 2)) + ((((v2707 + ((~(((v2709 ^ -1) | (-(v2709 ^ -1))) >> 31)) & 2)) - (v2710 + ((~(((v2711 ^ -1) | (-(v2711 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
      v2731[v2893] = v2728;
      int * v2733 = v2664->cache_tags;
      int v2896 = (int)((unsigned int)((int)((unsigned int)(v2670 + 68) >> 2)) >> 1);
      v2733[v2872] = v2896;
      int * v2735 = v2664->cache_dirty;
      v2735[v2872] = 0;
      int * v2737 = v2664->cache_age;
      v2737[v2872] = 1;
      int * v2739 = v2664->cache_age;
      int v2740 = v2739[v2872];
      int v2741 = v2739[v2846];
      int v2902 = v2741 + ((int)((unsigned int)(v2741 - v2740) >> 31));
      v2739[v2846] = v2902;
      int * v2743 = v2664->cache_age;
      int v2744 = v2743[v2847];
      int v2904 = v2744 + ((int)((unsigned int)(v2744 - v2740) >> 31));
      v2743[v2847] = v2904;
      int * v2746 = v2664->cache_age;
      v2746[v2872] = 0;
      v2749 = v2872;
    }
    int * v2750 = v2664->cache_vals;
    int v2907 = v2749 * 2;
    int v2751 = v2750[v2907];
    int v2908 = (v2749 * 2) + 1;
    int v2752 = v2750[v2908];
    int v2909 = (((((int)((unsigned int)((int)((unsigned int)(v2670 + 68) >> 2)) >> 1)) & 1) * 2) + ((((v2691 + ((~(((v2693 ^ -1) | (-(v2693 ^ -1))) >> 31)) & 2)) - (v2694 + ((~(((v2695 ^ -1) | (-(v2695 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
    v2750[v2909] = v2751;
    int * v2754 = v2664->cache_vals;
    int v2912 = ((((((int)((unsigned int)((int)((unsigned int)(v2670 + 68) >> 2)) >> 1)) & 1) * 2) + ((((v2691 + ((~(((v2693 ^ -1) | (-(v2693 ^ -1))) >> 31)) & 2)) - (v2694 + ((~(((v2695 ^ -1) | (-(v2695 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
    v2754[v2912] = v2752;
    int * v2756 = v2664->cache_tags;
    int v2915 = ((((int)((unsigned int)((int)((unsigned int)(v2670 + 68) >> 2)) >> 1)) & 1) * 2) + ((((v2691 + ((~(((v2693 ^ -1) | (-(v2693 ^ -1))) >> 31)) & 2)) - (v2694 + ((~(((v2695 ^ -1) | (-(v2695 ^ -1))) >> 31)) & 2))) >> 31) & 1);
    int v2916 = (int)((unsigned int)((int)((unsigned int)(v2670 + 68) >> 2)) >> 1);
    v2756[v2915] = v2916;
    int * v2758 = v2664->cache_dirty;
    v2758[v2915] = 0;
    int * v2760 = v2664->cache_age;
    v2760[v2915] = 1;
    int * v2762 = v2664->cache_age;
    int v2763 = v2762[v2915];
    int v2764 = v2762[v2844];
    int v2922 = v2764 + ((int)((unsigned int)(v2764 - v2763) >> 31));
    v2762[v2844] = v2922;
    int * v2766 = v2664->cache_age;
    int v2767 = v2766[v2845];
    int v2924 = v2767 + ((int)((unsigned int)(v2767 - v2763) >> 31));
    v2766[v2845] = v2924;
    int * v2769 = v2664->cache_age;
    v2769[v2915] = 0;
    v2772 = v2915;
  }
  int * v2773 = v2664->cache_vals;
  int v2927 = (v2772 * 2) + (((int)((unsigned int)(v2670 + 68) >> 2)) & 1);
  v2773[v2927] = v2672;
  int * v2775 = v2664->cache_tags;
  int v2776 = v2775[v2846];
  int v2777 = v2775[v2847];
  bool v2930 = !(((~(((v2776 ^ ((int)((unsigned int)((int)((unsigned int)(v2670 + 68) >> 2)) >> 1))) | (-(v2776 ^ ((int)((unsigned int)((int)((unsigned int)(v2670 + 68) >> 2)) >> 1))))) >> 31)) | (~(((v2777 ^ ((int)((unsigned int)((int)((unsigned int)(v2670 + 68) >> 2)) >> 1))) | (-(v2777 ^ ((int)((unsigned int)((int)((unsigned int)(v2670 + 68) >> 2)) >> 1))))) >> 31))) == 0);
  int v2831;
  if (v2930) {
    int * v2778 = v2664->cache_age;
    int v2932 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v2670 + 68) >> 2)) >> 1)) & 3) * 2)) + ((~(((v2777 ^ ((int)((unsigned int)((int)((unsigned int)(v2670 + 68) >> 2)) >> 1))) | (-(v2777 ^ ((int)((unsigned int)((int)((unsigned int)(v2670 + 68) >> 2)) >> 1))))) >> 31)) & 1);
    int v2779 = v2778[v2932];
    int v2780 = v2778[v2846];
    int v2933 = v2780 + ((int)((unsigned int)(v2780 - v2779) >> 31));
    v2778[v2846] = v2933;
    int * v2782 = v2664->cache_age;
    int v2783 = v2782[v2847];
    int v2935 = v2783 + ((int)((unsigned int)(v2783 - v2779) >> 31));
    v2782[v2847] = v2935;
    int * v2785 = v2664->cache_age;
    v2785[v2932] = 0;
    v2831 = v2932;
  } else {
    int * v2788 = v2664->cache_age;
    int v2939 = 4 + ((((int)((unsigned int)((int)((unsigned int)(v2670 + 68) >> 2)) >> 1)) & 3) * 2);
    int v2789 = v2788[v2939];
    int * v2790 = v2664->cache_tags;
    int v2791 = v2790[v2939];
    int v2792 = v2788[v2847];
    int v2793 = v2790[v2847];
    int * v2794 = v2664->cache_dirty;
    int v2942 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v2670 + 68) >> 2)) >> 1)) & 3) * 2)) + ((((v2789 + ((~(((v2791 ^ -1) | (-(v2791 ^ -1))) >> 31)) & 2)) - (v2792 + ((~(((v2793 ^ -1) | (-(v2793 ^ -1))) >> 31)) & 2))) >> 31) & 1);
    int v2795 = v2794[v2942];
    bool v2943 = !(v2795 == 0);
    if (v2943) {
      int * v2796 = v2664->cache_tags;
      int v2797 = v2796[v2942];
      int * v2798 = v2664->cache_vals;
      int v2946 = ((4 + ((((int)((unsigned int)((int)((unsigned int)(v2670 + 68) >> 2)) >> 1)) & 3) * 2)) + ((((v2789 + ((~(((v2791 ^ -1) | (-(v2791 ^ -1))) >> 31)) & 2)) - (v2792 + ((~(((v2793 ^ -1) | (-(v2793 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
      int v2799 = v2798[v2946];
      int v2947 = (((4 + ((((int)((unsigned int)((int)((unsigned int)(v2670 + 68) >> 2)) >> 1)) & 3) * 2)) + ((((v2789 + ((~(((v2791 ^ -1) | (-(v2791 ^ -1))) >> 31)) & 2)) - (v2792 + ((~(((v2793 ^ -1) | (-(v2793 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
      int v2800 = v2798[v2947];
      int * v2801 = v2664->mem;
      int v2949 = v2797 * 2;
      v2801[v2949] = v2799;
      int * v2803 = v2664->mem;
      int v2952 = (v2797 * 2) + 1;
      v2803[v2952] = v2800;
      ;
    } else {
      ;
    }
    int * v2808 = v2664->mem;
    int v2957 = ((int)((unsigned int)((int)((unsigned int)(v2670 + 68) >> 2)) >> 1)) * 2;
    int v2809 = v2808[v2957];
    int v2958 = (((int)((unsigned int)((int)((unsigned int)(v2670 + 68) >> 2)) >> 1)) * 2) + 1;
    int v2810 = v2808[v2958];
    int * v2811 = v2664->cache_vals;
    int v2960 = ((4 + ((((int)((unsigned int)((int)((unsigned int)(v2670 + 68) >> 2)) >> 1)) & 3) * 2)) + ((((v2789 + ((~(((v2791 ^ -1) | (-(v2791 ^ -1))) >> 31)) & 2)) - (v2792 + ((~(((v2793 ^ -1) | (-(v2793 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
    v2811[v2960] = v2809;
    int * v2813 = v2664->cache_vals;
    int v2963 = (((4 + ((((int)((unsigned int)((int)((unsigned int)(v2670 + 68) >> 2)) >> 1)) & 3) * 2)) + ((((v2789 + ((~(((v2791 ^ -1) | (-(v2791 ^ -1))) >> 31)) & 2)) - (v2792 + ((~(((v2793 ^ -1) | (-(v2793 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
    v2813[v2963] = v2810;
    int * v2815 = v2664->cache_tags;
    int v2966 = (int)((unsigned int)((int)((unsigned int)(v2670 + 68) >> 2)) >> 1);
    v2815[v2942] = v2966;
    int * v2817 = v2664->cache_dirty;
    v2817[v2942] = 0;
    int * v2819 = v2664->cache_age;
    v2819[v2942] = 1;
    int * v2821 = v2664->cache_age;
    int v2822 = v2821[v2942];
    int v2823 = v2821[v2846];
    int v2972 = v2823 + ((int)((unsigned int)(v2823 - v2822) >> 31));
    v2821[v2846] = v2972;
    int * v2825 = v2664->cache_age;
    int v2826 = v2825[v2847];
    int v2974 = v2826 + ((int)((unsigned int)(v2826 - v2822) >> 31));
    v2825[v2847] = v2974;
    int * v2828 = v2664->cache_age;
    v2828[v2942] = 0;
    v2831 = v2942;
  }
  int * v2832 = v2664->cache_vals;
  int v2977 = (v2831 * 2) + (((int)((unsigned int)(v2670 + 68) >> 2)) & 1);
  v2832[v2977] = v2672;
  int * v2834 = v2664->cache_dirty;
  v2834[v2831] = 1;
  struct StateT * v2836 = slot_32(v2664);
  return v2836;
}

struct StateT * slot_24(struct StateT * v1359) {
  int v1360 = v1359->timer;
  int v1472 = v1360 + 1;
  v1359->timer = v1472;
  int * v1362 = v1359->reg_ready;
  int v1363 = v1362[10];
  int * v1364 = v1359->regs;
  int v1365 = v1364[10];
  int * v1366 = v1359->cache_tags;
  int v1477 = (((int)((unsigned int)((int)((unsigned int)v1365 >> 2)) >> 1)) & 1) * 2;
  int v1367 = v1366[v1477];
  int v1478 = ((((int)((unsigned int)((int)((unsigned int)v1365 >> 2)) >> 1)) & 1) * 2) + 1;
  int v1368 = v1366[v1478];
  int v1479 = 4 + ((((int)((unsigned int)((int)((unsigned int)v1365 >> 2)) >> 1)) & 3) * 2);
  int v1369 = v1366[v1479];
  int v1480 = (4 + ((((int)((unsigned int)((int)((unsigned int)v1365 >> 2)) >> 1)) & 3) * 2)) + 1;
  int v1370 = v1366[v1480];
  int * v1371 = v1359->cache_vals;
  bool v1481 = !(((~(((v1367 ^ ((int)((unsigned int)((int)((unsigned int)v1365 >> 2)) >> 1))) | (-(v1367 ^ ((int)((unsigned int)((int)((unsigned int)v1365 >> 2)) >> 1))))) >> 31)) | (~(((v1368 ^ ((int)((unsigned int)((int)((unsigned int)v1365 >> 2)) >> 1))) | (-(v1368 ^ ((int)((unsigned int)((int)((unsigned int)v1365 >> 2)) >> 1))))) >> 31))) == 0);
  int v1464;
  if (v1481) {
    int * v1372 = v1359->cache_age;
    int v1483 = ((((int)((unsigned int)((int)((unsigned int)v1365 >> 2)) >> 1)) & 1) * 2) + ((~(((v1368 ^ ((int)((unsigned int)((int)((unsigned int)v1365 >> 2)) >> 1))) | (-(v1368 ^ ((int)((unsigned int)((int)((unsigned int)v1365 >> 2)) >> 1))))) >> 31)) & 1);
    int v1373 = v1372[v1483];
    int v1374 = v1372[v1477];
    int v1484 = v1374 + ((int)((unsigned int)(v1374 - v1373) >> 31));
    v1372[v1477] = v1484;
    int * v1376 = v1359->cache_age;
    int v1377 = v1376[v1478];
    int v1486 = v1377 + ((int)((unsigned int)(v1377 - v1373) >> 31));
    v1376[v1478] = v1486;
    int * v1379 = v1359->cache_age;
    v1379[v1483] = 0;
    v1464 = v1483;
  } else {
    int * v1382 = v1359->cache_age;
    int v1490 = (((int)((unsigned int)((int)((unsigned int)v1365 >> 2)) >> 1)) & 1) * 2;
    int v1383 = v1382[v1490];
    int * v1384 = v1359->cache_tags;
    int v1385 = v1384[v1490];
    int v1386 = v1382[v1478];
    int v1387 = v1384[v1478];
    bool v1492 = !(((~(((v1369 ^ ((int)((unsigned int)((int)((unsigned int)v1365 >> 2)) >> 1))) | (-(v1369 ^ ((int)((unsigned int)((int)((unsigned int)v1365 >> 2)) >> 1))))) >> 31)) | (~(((v1370 ^ ((int)((unsigned int)((int)((unsigned int)v1365 >> 2)) >> 1))) | (-(v1370 ^ ((int)((unsigned int)((int)((unsigned int)v1365 >> 2)) >> 1))))) >> 31))) == 0);
    int v1441;
    if (v1492) {
      int * v1388 = v1359->cache_age;
      int v1494 = (4 + ((((int)((unsigned int)((int)((unsigned int)v1365 >> 2)) >> 1)) & 3) * 2)) + ((~(((v1370 ^ ((int)((unsigned int)((int)((unsigned int)v1365 >> 2)) >> 1))) | (-(v1370 ^ ((int)((unsigned int)((int)((unsigned int)v1365 >> 2)) >> 1))))) >> 31)) & 1);
      int v1389 = v1388[v1494];
      int v1390 = v1388[v1479];
      int v1495 = v1390 + ((int)((unsigned int)(v1390 - v1389) >> 31));
      v1388[v1479] = v1495;
      int * v1392 = v1359->cache_age;
      int v1393 = v1392[v1480];
      int v1497 = v1393 + ((int)((unsigned int)(v1393 - v1389) >> 31));
      v1392[v1480] = v1497;
      int * v1395 = v1359->cache_age;
      v1395[v1494] = 0;
      v1441 = v1494;
    } else {
      int * v1398 = v1359->cache_age;
      int v1501 = 4 + ((((int)((unsigned int)((int)((unsigned int)v1365 >> 2)) >> 1)) & 3) * 2);
      int v1399 = v1398[v1501];
      int * v1400 = v1359->cache_tags;
      int v1401 = v1400[v1501];
      int v1402 = v1398[v1480];
      int v1403 = v1400[v1480];
      int * v1404 = v1359->cache_dirty;
      int v1504 = (4 + ((((int)((unsigned int)((int)((unsigned int)v1365 >> 2)) >> 1)) & 3) * 2)) + ((((v1399 + ((~(((v1401 ^ -1) | (-(v1401 ^ -1))) >> 31)) & 2)) - (v1402 + ((~(((v1403 ^ -1) | (-(v1403 ^ -1))) >> 31)) & 2))) >> 31) & 1);
      int v1405 = v1404[v1504];
      bool v1505 = !(v1405 == 0);
      if (v1505) {
        int * v1406 = v1359->cache_tags;
        int v1407 = v1406[v1504];
        int * v1408 = v1359->cache_vals;
        int v1508 = ((4 + ((((int)((unsigned int)((int)((unsigned int)v1365 >> 2)) >> 1)) & 3) * 2)) + ((((v1399 + ((~(((v1401 ^ -1) | (-(v1401 ^ -1))) >> 31)) & 2)) - (v1402 + ((~(((v1403 ^ -1) | (-(v1403 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
        int v1409 = v1408[v1508];
        int v1509 = (((4 + ((((int)((unsigned int)((int)((unsigned int)v1365 >> 2)) >> 1)) & 3) * 2)) + ((((v1399 + ((~(((v1401 ^ -1) | (-(v1401 ^ -1))) >> 31)) & 2)) - (v1402 + ((~(((v1403 ^ -1) | (-(v1403 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
        int v1410 = v1408[v1509];
        int * v1411 = v1359->mem;
        int v1511 = v1407 * 2;
        v1411[v1511] = v1409;
        int * v1413 = v1359->mem;
        int v1514 = (v1407 * 2) + 1;
        v1413[v1514] = v1410;
        ;
      } else {
        ;
      }
      int * v1418 = v1359->mem;
      int v1519 = ((int)((unsigned int)((int)((unsigned int)v1365 >> 2)) >> 1)) * 2;
      int v1419 = v1418[v1519];
      int v1520 = (((int)((unsigned int)((int)((unsigned int)v1365 >> 2)) >> 1)) * 2) + 1;
      int v1420 = v1418[v1520];
      int * v1421 = v1359->cache_vals;
      int v1522 = ((4 + ((((int)((unsigned int)((int)((unsigned int)v1365 >> 2)) >> 1)) & 3) * 2)) + ((((v1399 + ((~(((v1401 ^ -1) | (-(v1401 ^ -1))) >> 31)) & 2)) - (v1402 + ((~(((v1403 ^ -1) | (-(v1403 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
      v1421[v1522] = v1419;
      int * v1423 = v1359->cache_vals;
      int v1525 = (((4 + ((((int)((unsigned int)((int)((unsigned int)v1365 >> 2)) >> 1)) & 3) * 2)) + ((((v1399 + ((~(((v1401 ^ -1) | (-(v1401 ^ -1))) >> 31)) & 2)) - (v1402 + ((~(((v1403 ^ -1) | (-(v1403 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
      v1423[v1525] = v1420;
      int * v1425 = v1359->cache_tags;
      int v1528 = (int)((unsigned int)((int)((unsigned int)v1365 >> 2)) >> 1);
      v1425[v1504] = v1528;
      int * v1427 = v1359->cache_dirty;
      v1427[v1504] = 0;
      int * v1429 = v1359->cache_age;
      v1429[v1504] = 1;
      int * v1431 = v1359->cache_age;
      int v1432 = v1431[v1504];
      int v1433 = v1431[v1479];
      int v1534 = v1433 + ((int)((unsigned int)(v1433 - v1432) >> 31));
      v1431[v1479] = v1534;
      int * v1435 = v1359->cache_age;
      int v1436 = v1435[v1480];
      int v1536 = v1436 + ((int)((unsigned int)(v1436 - v1432) >> 31));
      v1435[v1480] = v1536;
      int * v1438 = v1359->cache_age;
      v1438[v1504] = 0;
      v1441 = v1504;
    }
    int * v1442 = v1359->cache_vals;
    int v1539 = v1441 * 2;
    int v1443 = v1442[v1539];
    int v1540 = (v1441 * 2) + 1;
    int v1444 = v1442[v1540];
    int v1541 = (((((int)((unsigned int)((int)((unsigned int)v1365 >> 2)) >> 1)) & 1) * 2) + ((((v1383 + ((~(((v1385 ^ -1) | (-(v1385 ^ -1))) >> 31)) & 2)) - (v1386 + ((~(((v1387 ^ -1) | (-(v1387 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
    v1442[v1541] = v1443;
    int * v1446 = v1359->cache_vals;
    int v1544 = ((((((int)((unsigned int)((int)((unsigned int)v1365 >> 2)) >> 1)) & 1) * 2) + ((((v1383 + ((~(((v1385 ^ -1) | (-(v1385 ^ -1))) >> 31)) & 2)) - (v1386 + ((~(((v1387 ^ -1) | (-(v1387 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
    v1446[v1544] = v1444;
    int * v1448 = v1359->cache_tags;
    int v1547 = ((((int)((unsigned int)((int)((unsigned int)v1365 >> 2)) >> 1)) & 1) * 2) + ((((v1383 + ((~(((v1385 ^ -1) | (-(v1385 ^ -1))) >> 31)) & 2)) - (v1386 + ((~(((v1387 ^ -1) | (-(v1387 ^ -1))) >> 31)) & 2))) >> 31) & 1);
    int v1548 = (int)((unsigned int)((int)((unsigned int)v1365 >> 2)) >> 1);
    v1448[v1547] = v1548;
    int * v1450 = v1359->cache_dirty;
    v1450[v1547] = 0;
    int * v1452 = v1359->cache_age;
    v1452[v1547] = 1;
    int * v1454 = v1359->cache_age;
    int v1455 = v1454[v1547];
    int v1456 = v1454[v1477];
    int v1554 = v1456 + ((int)((unsigned int)(v1456 - v1455) >> 31));
    v1454[v1477] = v1554;
    int * v1458 = v1359->cache_age;
    int v1459 = v1458[v1478];
    int v1556 = v1459 + ((int)((unsigned int)(v1459 - v1455) >> 31));
    v1458[v1478] = v1556;
    int * v1461 = v1359->cache_age;
    v1461[v1547] = 0;
    v1464 = v1547;
  }
  int v1559 = (v1464 * 2) + (((int)((unsigned int)v1365 >> 2)) & 1);
  int v1465 = v1371[v1559];
  int * v1466 = v1359->reg_ready;
  int v1561 = ((v1363 + ((v1360 - v1363) & (~((v1360 - v1363) >> 31)))) + 1) + ((100 ^ (((~(((v1369 ^ ((int)((unsigned int)((int)((unsigned int)v1365 >> 2)) >> 1))) | (-(v1369 ^ ((int)((unsigned int)((int)((unsigned int)v1365 >> 2)) >> 1))))) >> 31)) | (~(((v1370 ^ ((int)((unsigned int)((int)((unsigned int)v1365 >> 2)) >> 1))) | (-(v1370 ^ ((int)((unsigned int)((int)((unsigned int)v1365 >> 2)) >> 1))))) >> 31))) & 104)) ^ (((~(((v1367 ^ ((int)((unsigned int)((int)((unsigned int)v1365 >> 2)) >> 1))) | (-(v1367 ^ ((int)((unsigned int)((int)((unsigned int)v1365 >> 2)) >> 1))))) >> 31)) | (~(((v1368 ^ ((int)((unsigned int)((int)((unsigned int)v1365 >> 2)) >> 1))) | (-(v1368 ^ ((int)((unsigned int)((int)((unsigned int)v1365 >> 2)) >> 1))))) >> 31))) & (1 ^ (100 ^ (((~(((v1369 ^ ((int)((unsigned int)((int)((unsigned int)v1365 >> 2)) >> 1))) | (-(v1369 ^ ((int)((unsigned int)((int)((unsigned int)v1365 >> 2)) >> 1))))) >> 31)) | (~(((v1370 ^ ((int)((unsigned int)((int)((unsigned int)v1365 >> 2)) >> 1))) | (-(v1370 ^ ((int)((unsigned int)((int)((unsigned int)v1365 >> 2)) >> 1))))) >> 31))) & 104)))));
  v1466[10] = v1561;
  int * v1468 = v1359->regs;
  v1468[10] = v1465;
  struct StateT * v1470 = slot_26(v1359);
  return v1470;
}

struct StateT * slot_0(struct StateT * v2) {
  int v3 = v2->timer;
  int v7 = v3 + 1;
  v2->timer = v7;
  struct StateT * v5 = slot_1(v2);
  return v5;
}

struct StateT * slot_28(struct StateT * v1811) {
  int v1812 = v1811->timer;
  int v1825 = v1812 + 1;
  v1811->timer = v1825;
  int * v1814 = v1811->reg_ready;
  int v1815 = v1814[11];
  int * v1816 = v1811->regs;
  int v1817 = v1816[11];
  int v1818 = v1814[10];
  int v1819 = v1816[10];
  int v1830 = (v1818 + (((v1815 + ((v1812 - v1815) & (~((v1812 - v1815) >> 31)))) - v1818) & (~(((v1815 + ((v1812 - v1815) & (~((v1812 - v1815) >> 31)))) - v1818) >> 31)))) + 1;
  v1814[10] = v1830;
  int * v1821 = v1811->regs;
  int v1832 = v1817 & v1819;
  v1821[10] = v1832;
  struct StateT * v1823 = slot_38(v1811);
  return v1823;
}

struct StateT * slot_32(struct StateT * v2196) {
  int v2197 = v2196->timer;
  int v2200 = v2197 + 1;
  v2196->timer = v2200;
  return v2196;
}

struct StateT * slot_17(struct StateT * v1038) {
  int v1039 = v1038->timer;
  int v1052 = v1039 + 1;
  v1038->timer = v1052;
  int * v1041 = v1038->reg_ready;
  int v1042 = v1041[11];
  int * v1043 = v1038->regs;
  int v1044 = v1043[11];
  int v1045 = v1041[10];
  int v1046 = v1043[10];
  int v1057 = (v1045 + (((v1042 + ((v1039 - v1042) & (~((v1039 - v1042) >> 31)))) - v1045) & (~(((v1042 + ((v1039 - v1042) & (~((v1039 - v1042) >> 31)))) - v1045) >> 31)))) + 1;
  v1041[10] = v1057;
  int * v1048 = v1038->regs;
  int v1059 = v1044 + v1046;
  v1048[10] = v1059;
  struct StateT * v1050 = slot_19(v1038);
  return v1050;
}

struct StateT * slot_33(struct StateT * v2201) {
  int v2202 = v2201->timer;
  int v2215 = v2202 + 1;
  v2201->timer = v2215;
  int * v2204 = v2201->reg_ready;
  int v2205 = v2204[11];
  int * v2206 = v2201->regs;
  int v2207 = v2206[11];
  int v2208 = v2204[10];
  int v2209 = v2206[10];
  int v2220 = (v2208 + (((v2205 + ((v2202 - v2205) & (~((v2202 - v2205) >> 31)))) - v2208) & (~(((v2205 + ((v2202 - v2205) & (~((v2202 - v2205) >> 31)))) - v2208) >> 31)))) + 1;
  v2204[10] = v2220;
  int * v2211 = v2201->regs;
  int v2222 = v2207 + v2209;
  v2211[10] = v2222;
  struct StateT * v2213 = slot_24(v2201);
  return v2213;
}

struct StateT * snippet(struct StateT * v0) {
  struct StateT * v1 = slot_0(v0);
  int v2988 = v1->timer;
  int * v2989 = v1->reg_ready;
  int v2990 = v2989[0];
  int v3121 = v2990 + ((v2988 - v2990) & (~((v2988 - v2990) >> 31)));
  v1->timer = v3121;
  int v2992 = v1->timer;
  int * v2993 = v1->reg_ready;
  int v2994 = v2993[1];
  int v3124 = v2994 + ((v2992 - v2994) & (~((v2992 - v2994) >> 31)));
  v1->timer = v3124;
  int v2996 = v1->timer;
  int * v2997 = v1->reg_ready;
  int v2998 = v2997[2];
  int v3127 = v2998 + ((v2996 - v2998) & (~((v2996 - v2998) >> 31)));
  v1->timer = v3127;
  int v3000 = v1->timer;
  int * v3001 = v1->reg_ready;
  int v3002 = v3001[3];
  int v3130 = v3002 + ((v3000 - v3002) & (~((v3000 - v3002) >> 31)));
  v1->timer = v3130;
  int v3004 = v1->timer;
  int * v3005 = v1->reg_ready;
  int v3006 = v3005[4];
  int v3133 = v3006 + ((v3004 - v3006) & (~((v3004 - v3006) >> 31)));
  v1->timer = v3133;
  int v3008 = v1->timer;
  int * v3009 = v1->reg_ready;
  int v3010 = v3009[5];
  int v3136 = v3010 + ((v3008 - v3010) & (~((v3008 - v3010) >> 31)));
  v1->timer = v3136;
  int v3012 = v1->timer;
  int * v3013 = v1->reg_ready;
  int v3014 = v3013[6];
  int v3139 = v3014 + ((v3012 - v3014) & (~((v3012 - v3014) >> 31)));
  v1->timer = v3139;
  int v3016 = v1->timer;
  int * v3017 = v1->reg_ready;
  int v3018 = v3017[7];
  int v3142 = v3018 + ((v3016 - v3018) & (~((v3016 - v3018) >> 31)));
  v1->timer = v3142;
  int v3020 = v1->timer;
  int * v3021 = v1->reg_ready;
  int v3022 = v3021[8];
  int v3145 = v3022 + ((v3020 - v3022) & (~((v3020 - v3022) >> 31)));
  v1->timer = v3145;
  int v3024 = v1->timer;
  int * v3025 = v1->reg_ready;
  int v3026 = v3025[9];
  int v3148 = v3026 + ((v3024 - v3026) & (~((v3024 - v3026) >> 31)));
  v1->timer = v3148;
  int v3028 = v1->timer;
  int * v3029 = v1->reg_ready;
  int v3030 = v3029[10];
  int v3151 = v3030 + ((v3028 - v3030) & (~((v3028 - v3030) >> 31)));
  v1->timer = v3151;
  int v3032 = v1->timer;
  int * v3033 = v1->reg_ready;
  int v3034 = v3033[11];
  int v3154 = v3034 + ((v3032 - v3034) & (~((v3032 - v3034) >> 31)));
  v1->timer = v3154;
  int v3036 = v1->timer;
  int * v3037 = v1->reg_ready;
  int v3038 = v3037[12];
  int v3157 = v3038 + ((v3036 - v3038) & (~((v3036 - v3038) >> 31)));
  v1->timer = v3157;
  int v3040 = v1->timer;
  int * v3041 = v1->reg_ready;
  int v3042 = v3041[13];
  int v3160 = v3042 + ((v3040 - v3042) & (~((v3040 - v3042) >> 31)));
  v1->timer = v3160;
  int v3044 = v1->timer;
  int * v3045 = v1->reg_ready;
  int v3046 = v3045[14];
  int v3163 = v3046 + ((v3044 - v3046) & (~((v3044 - v3046) >> 31)));
  v1->timer = v3163;
  int v3048 = v1->timer;
  int * v3049 = v1->reg_ready;
  int v3050 = v3049[15];
  int v3166 = v3050 + ((v3048 - v3050) & (~((v3048 - v3050) >> 31)));
  v1->timer = v3166;
  int v3052 = v1->timer;
  int * v3053 = v1->reg_ready;
  int v3054 = v3053[16];
  int v3169 = v3054 + ((v3052 - v3054) & (~((v3052 - v3054) >> 31)));
  v1->timer = v3169;
  int v3056 = v1->timer;
  int * v3057 = v1->reg_ready;
  int v3058 = v3057[17];
  int v3172 = v3058 + ((v3056 - v3058) & (~((v3056 - v3058) >> 31)));
  v1->timer = v3172;
  int v3060 = v1->timer;
  int * v3061 = v1->reg_ready;
  int v3062 = v3061[18];
  int v3175 = v3062 + ((v3060 - v3062) & (~((v3060 - v3062) >> 31)));
  v1->timer = v3175;
  int v3064 = v1->timer;
  int * v3065 = v1->reg_ready;
  int v3066 = v3065[19];
  int v3178 = v3066 + ((v3064 - v3066) & (~((v3064 - v3066) >> 31)));
  v1->timer = v3178;
  int v3068 = v1->timer;
  int * v3069 = v1->reg_ready;
  int v3070 = v3069[20];
  int v3181 = v3070 + ((v3068 - v3070) & (~((v3068 - v3070) >> 31)));
  v1->timer = v3181;
  int v3072 = v1->timer;
  int * v3073 = v1->reg_ready;
  int v3074 = v3073[21];
  int v3184 = v3074 + ((v3072 - v3074) & (~((v3072 - v3074) >> 31)));
  v1->timer = v3184;
  int v3076 = v1->timer;
  int * v3077 = v1->reg_ready;
  int v3078 = v3077[22];
  int v3187 = v3078 + ((v3076 - v3078) & (~((v3076 - v3078) >> 31)));
  v1->timer = v3187;
  int v3080 = v1->timer;
  int * v3081 = v1->reg_ready;
  int v3082 = v3081[23];
  int v3190 = v3082 + ((v3080 - v3082) & (~((v3080 - v3082) >> 31)));
  v1->timer = v3190;
  int v3084 = v1->timer;
  int * v3085 = v1->reg_ready;
  int v3086 = v3085[24];
  int v3193 = v3086 + ((v3084 - v3086) & (~((v3084 - v3086) >> 31)));
  v1->timer = v3193;
  int v3088 = v1->timer;
  int * v3089 = v1->reg_ready;
  int v3090 = v3089[25];
  int v3196 = v3090 + ((v3088 - v3090) & (~((v3088 - v3090) >> 31)));
  v1->timer = v3196;
  int v3092 = v1->timer;
  int * v3093 = v1->reg_ready;
  int v3094 = v3093[26];
  int v3199 = v3094 + ((v3092 - v3094) & (~((v3092 - v3094) >> 31)));
  v1->timer = v3199;
  int v3096 = v1->timer;
  int * v3097 = v1->reg_ready;
  int v3098 = v3097[27];
  int v3202 = v3098 + ((v3096 - v3098) & (~((v3096 - v3098) >> 31)));
  v1->timer = v3202;
  int v3100 = v1->timer;
  int * v3101 = v1->reg_ready;
  int v3102 = v3101[28];
  int v3205 = v3102 + ((v3100 - v3102) & (~((v3100 - v3102) >> 31)));
  v1->timer = v3205;
  int v3104 = v1->timer;
  int * v3105 = v1->reg_ready;
  int v3106 = v3105[29];
  int v3208 = v3106 + ((v3104 - v3106) & (~((v3104 - v3106) >> 31)));
  v1->timer = v3208;
  int v3108 = v1->timer;
  int * v3109 = v1->reg_ready;
  int v3110 = v3109[30];
  int v3211 = v3110 + ((v3108 - v3110) & (~((v3108 - v3110) >> 31)));
  v1->timer = v3211;
  int v3112 = v1->timer;
  int * v3113 = v1->reg_ready;
  int v3114 = v3113[31];
  int v3214 = v3114 + ((v3112 - v3114) & (~((v3112 - v3114) >> 31)));
  v1->timer = v3214;
  return v1;
}

struct StateT * slot_4(struct StateT * v458) {
  int v459 = v458->timer;
  int v467 = v459 + 1;
  v458->timer = v467;
  int * v461 = v458->reg_ready;
  v461[10] = v467;
  int * v463 = v458->regs;
  v463[10] = 0;
  struct StateT * v465 = slot_6(v458);
  return v465;
}

struct StateT * slot_15(struct StateT * v1001) {
  int v1002 = v1001->timer;
  int v1013 = v1002 + 1;
  v1001->timer = v1013;
  int * v1004 = v1001->reg_ready;
  int v1005 = v1004[11];
  int * v1006 = v1001->regs;
  int v1007 = v1006[11];
  int v1017 = (v1005 + ((v1002 - v1005) & (~((v1002 - v1005) >> 31)))) + 1;
  v1004[11] = v1017;
  int * v1009 = v1001->regs;
  int v1019 = v1007 + 72;
  v1009[11] = v1019;
  struct StateT * v1011 = slot_17(v1001);
  return v1011;
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