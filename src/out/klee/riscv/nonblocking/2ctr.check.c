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
struct StateT * slot_1(struct StateT * v22);
struct StateT * slot_2(struct StateT * v230);
struct StateT * slot_3(struct StateT * v251);
struct StateT * slot_0(struct StateT * v2);
struct StateT * snippet(struct StateT * v0) {
  struct StateT * v1 = slot_0(v0);
  int v456 = v1->timer;
  int * v457 = v1->reg_ready;
  int v458 = v457[0];
  int v589 = v458 + ((v456 - v458) & (~((v456 - v458) >> 31)));
  v1->timer = v589;
  int v460 = v1->timer;
  int * v461 = v1->reg_ready;
  int v462 = v461[1];
  int v592 = v462 + ((v460 - v462) & (~((v460 - v462) >> 31)));
  v1->timer = v592;
  int v464 = v1->timer;
  int * v465 = v1->reg_ready;
  int v466 = v465[2];
  int v595 = v466 + ((v464 - v466) & (~((v464 - v466) >> 31)));
  v1->timer = v595;
  int v468 = v1->timer;
  int * v469 = v1->reg_ready;
  int v470 = v469[3];
  int v598 = v470 + ((v468 - v470) & (~((v468 - v470) >> 31)));
  v1->timer = v598;
  int v472 = v1->timer;
  int * v473 = v1->reg_ready;
  int v474 = v473[4];
  int v601 = v474 + ((v472 - v474) & (~((v472 - v474) >> 31)));
  v1->timer = v601;
  int v476 = v1->timer;
  int * v477 = v1->reg_ready;
  int v478 = v477[5];
  int v604 = v478 + ((v476 - v478) & (~((v476 - v478) >> 31)));
  v1->timer = v604;
  int v480 = v1->timer;
  int * v481 = v1->reg_ready;
  int v482 = v481[6];
  int v607 = v482 + ((v480 - v482) & (~((v480 - v482) >> 31)));
  v1->timer = v607;
  int v484 = v1->timer;
  int * v485 = v1->reg_ready;
  int v486 = v485[7];
  int v610 = v486 + ((v484 - v486) & (~((v484 - v486) >> 31)));
  v1->timer = v610;
  int v488 = v1->timer;
  int * v489 = v1->reg_ready;
  int v490 = v489[8];
  int v613 = v490 + ((v488 - v490) & (~((v488 - v490) >> 31)));
  v1->timer = v613;
  int v492 = v1->timer;
  int * v493 = v1->reg_ready;
  int v494 = v493[9];
  int v616 = v494 + ((v492 - v494) & (~((v492 - v494) >> 31)));
  v1->timer = v616;
  int v496 = v1->timer;
  int * v497 = v1->reg_ready;
  int v498 = v497[10];
  int v619 = v498 + ((v496 - v498) & (~((v496 - v498) >> 31)));
  v1->timer = v619;
  int v500 = v1->timer;
  int * v501 = v1->reg_ready;
  int v502 = v501[11];
  int v622 = v502 + ((v500 - v502) & (~((v500 - v502) >> 31)));
  v1->timer = v622;
  int v504 = v1->timer;
  int * v505 = v1->reg_ready;
  int v506 = v505[12];
  int v625 = v506 + ((v504 - v506) & (~((v504 - v506) >> 31)));
  v1->timer = v625;
  int v508 = v1->timer;
  int * v509 = v1->reg_ready;
  int v510 = v509[13];
  int v628 = v510 + ((v508 - v510) & (~((v508 - v510) >> 31)));
  v1->timer = v628;
  int v512 = v1->timer;
  int * v513 = v1->reg_ready;
  int v514 = v513[14];
  int v631 = v514 + ((v512 - v514) & (~((v512 - v514) >> 31)));
  v1->timer = v631;
  int v516 = v1->timer;
  int * v517 = v1->reg_ready;
  int v518 = v517[15];
  int v634 = v518 + ((v516 - v518) & (~((v516 - v518) >> 31)));
  v1->timer = v634;
  int v520 = v1->timer;
  int * v521 = v1->reg_ready;
  int v522 = v521[16];
  int v637 = v522 + ((v520 - v522) & (~((v520 - v522) >> 31)));
  v1->timer = v637;
  int v524 = v1->timer;
  int * v525 = v1->reg_ready;
  int v526 = v525[17];
  int v640 = v526 + ((v524 - v526) & (~((v524 - v526) >> 31)));
  v1->timer = v640;
  int v528 = v1->timer;
  int * v529 = v1->reg_ready;
  int v530 = v529[18];
  int v643 = v530 + ((v528 - v530) & (~((v528 - v530) >> 31)));
  v1->timer = v643;
  int v532 = v1->timer;
  int * v533 = v1->reg_ready;
  int v534 = v533[19];
  int v646 = v534 + ((v532 - v534) & (~((v532 - v534) >> 31)));
  v1->timer = v646;
  int v536 = v1->timer;
  int * v537 = v1->reg_ready;
  int v538 = v537[20];
  int v649 = v538 + ((v536 - v538) & (~((v536 - v538) >> 31)));
  v1->timer = v649;
  int v540 = v1->timer;
  int * v541 = v1->reg_ready;
  int v542 = v541[21];
  int v652 = v542 + ((v540 - v542) & (~((v540 - v542) >> 31)));
  v1->timer = v652;
  int v544 = v1->timer;
  int * v545 = v1->reg_ready;
  int v546 = v545[22];
  int v655 = v546 + ((v544 - v546) & (~((v544 - v546) >> 31)));
  v1->timer = v655;
  int v548 = v1->timer;
  int * v549 = v1->reg_ready;
  int v550 = v549[23];
  int v658 = v550 + ((v548 - v550) & (~((v548 - v550) >> 31)));
  v1->timer = v658;
  int v552 = v1->timer;
  int * v553 = v1->reg_ready;
  int v554 = v553[24];
  int v661 = v554 + ((v552 - v554) & (~((v552 - v554) >> 31)));
  v1->timer = v661;
  int v556 = v1->timer;
  int * v557 = v1->reg_ready;
  int v558 = v557[25];
  int v664 = v558 + ((v556 - v558) & (~((v556 - v558) >> 31)));
  v1->timer = v664;
  int v560 = v1->timer;
  int * v561 = v1->reg_ready;
  int v562 = v561[26];
  int v667 = v562 + ((v560 - v562) & (~((v560 - v562) >> 31)));
  v1->timer = v667;
  int v564 = v1->timer;
  int * v565 = v1->reg_ready;
  int v566 = v565[27];
  int v670 = v566 + ((v564 - v566) & (~((v564 - v566) >> 31)));
  v1->timer = v670;
  int v568 = v1->timer;
  int * v569 = v1->reg_ready;
  int v570 = v569[28];
  int v673 = v570 + ((v568 - v570) & (~((v568 - v570) >> 31)));
  v1->timer = v673;
  int v572 = v1->timer;
  int * v573 = v1->reg_ready;
  int v574 = v573[29];
  int v676 = v574 + ((v572 - v574) & (~((v572 - v574) >> 31)));
  v1->timer = v676;
  int v576 = v1->timer;
  int * v577 = v1->reg_ready;
  int v578 = v577[30];
  int v679 = v578 + ((v576 - v578) & (~((v576 - v578) >> 31)));
  v1->timer = v679;
  int v580 = v1->timer;
  int * v581 = v1->reg_ready;
  int v582 = v581[31];
  int v682 = v582 + ((v580 - v582) & (~((v580 - v582) >> 31)));
  v1->timer = v682;
  return v1;
}

struct StateT * slot_1(struct StateT * v22) {
  int v23 = v22->timer;
  int v135 = v23 + 1;
  v22->timer = v135;
  int * v25 = v22->reg_ready;
  int v26 = v25[10];
  int * v27 = v22->regs;
  int v28 = v27[10];
  int * v29 = v22->cache_tags;
  int v140 = (((int)((unsigned int)((int)((unsigned int)v28 >> 2)) >> 1)) & 1) * 2;
  int v30 = v29[v140];
  int v141 = ((((int)((unsigned int)((int)((unsigned int)v28 >> 2)) >> 1)) & 1) * 2) + 1;
  int v31 = v29[v141];
  int v142 = 4 + ((((int)((unsigned int)((int)((unsigned int)v28 >> 2)) >> 1)) & 3) * 2);
  int v32 = v29[v142];
  int v143 = (4 + ((((int)((unsigned int)((int)((unsigned int)v28 >> 2)) >> 1)) & 3) * 2)) + 1;
  int v33 = v29[v143];
  int * v34 = v22->cache_vals;
  bool v144 = !(((~(((v30 ^ ((int)((unsigned int)((int)((unsigned int)v28 >> 2)) >> 1))) | (-(v30 ^ ((int)((unsigned int)((int)((unsigned int)v28 >> 2)) >> 1))))) >> 31)) | (~(((v31 ^ ((int)((unsigned int)((int)((unsigned int)v28 >> 2)) >> 1))) | (-(v31 ^ ((int)((unsigned int)((int)((unsigned int)v28 >> 2)) >> 1))))) >> 31))) == 0);
  int v127;
  if (v144) {
    int * v35 = v22->cache_age;
    int v146 = ((((int)((unsigned int)((int)((unsigned int)v28 >> 2)) >> 1)) & 1) * 2) + ((~(((v31 ^ ((int)((unsigned int)((int)((unsigned int)v28 >> 2)) >> 1))) | (-(v31 ^ ((int)((unsigned int)((int)((unsigned int)v28 >> 2)) >> 1))))) >> 31)) & 1);
    int v36 = v35[v146];
    int v37 = v35[v140];
    int v147 = v37 + ((int)((unsigned int)(v37 - v36) >> 31));
    v35[v140] = v147;
    int * v39 = v22->cache_age;
    int v40 = v39[v141];
    int v149 = v40 + ((int)((unsigned int)(v40 - v36) >> 31));
    v39[v141] = v149;
    int * v42 = v22->cache_age;
    v42[v146] = 0;
    v127 = v146;
  } else {
    int * v45 = v22->cache_age;
    int v153 = (((int)((unsigned int)((int)((unsigned int)v28 >> 2)) >> 1)) & 1) * 2;
    int v46 = v45[v153];
    int * v47 = v22->cache_tags;
    int v48 = v47[v153];
    int v49 = v45[v141];
    int v50 = v47[v141];
    bool v155 = !(((~(((v32 ^ ((int)((unsigned int)((int)((unsigned int)v28 >> 2)) >> 1))) | (-(v32 ^ ((int)((unsigned int)((int)((unsigned int)v28 >> 2)) >> 1))))) >> 31)) | (~(((v33 ^ ((int)((unsigned int)((int)((unsigned int)v28 >> 2)) >> 1))) | (-(v33 ^ ((int)((unsigned int)((int)((unsigned int)v28 >> 2)) >> 1))))) >> 31))) == 0);
    int v104;
    if (v155) {
      int * v51 = v22->cache_age;
      int v157 = (4 + ((((int)((unsigned int)((int)((unsigned int)v28 >> 2)) >> 1)) & 3) * 2)) + ((~(((v33 ^ ((int)((unsigned int)((int)((unsigned int)v28 >> 2)) >> 1))) | (-(v33 ^ ((int)((unsigned int)((int)((unsigned int)v28 >> 2)) >> 1))))) >> 31)) & 1);
      int v52 = v51[v157];
      int v53 = v51[v142];
      int v158 = v53 + ((int)((unsigned int)(v53 - v52) >> 31));
      v51[v142] = v158;
      int * v55 = v22->cache_age;
      int v56 = v55[v143];
      int v160 = v56 + ((int)((unsigned int)(v56 - v52) >> 31));
      v55[v143] = v160;
      int * v58 = v22->cache_age;
      v58[v157] = 0;
      v104 = v157;
    } else {
      int * v61 = v22->cache_age;
      int v164 = 4 + ((((int)((unsigned int)((int)((unsigned int)v28 >> 2)) >> 1)) & 3) * 2);
      int v62 = v61[v164];
      int * v63 = v22->cache_tags;
      int v64 = v63[v164];
      int v65 = v61[v143];
      int v66 = v63[v143];
      int * v67 = v22->cache_dirty;
      int v167 = (4 + ((((int)((unsigned int)((int)((unsigned int)v28 >> 2)) >> 1)) & 3) * 2)) + ((((v62 + ((~(((v64 ^ -1) | (-(v64 ^ -1))) >> 31)) & 2)) - (v65 + ((~(((v66 ^ -1) | (-(v66 ^ -1))) >> 31)) & 2))) >> 31) & 1);
      int v68 = v67[v167];
      bool v168 = !(v68 == 0);
      if (v168) {
        int * v69 = v22->cache_tags;
        int v70 = v69[v167];
        int * v71 = v22->cache_vals;
        int v171 = ((4 + ((((int)((unsigned int)((int)((unsigned int)v28 >> 2)) >> 1)) & 3) * 2)) + ((((v62 + ((~(((v64 ^ -1) | (-(v64 ^ -1))) >> 31)) & 2)) - (v65 + ((~(((v66 ^ -1) | (-(v66 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
        int v72 = v71[v171];
        int v172 = (((4 + ((((int)((unsigned int)((int)((unsigned int)v28 >> 2)) >> 1)) & 3) * 2)) + ((((v62 + ((~(((v64 ^ -1) | (-(v64 ^ -1))) >> 31)) & 2)) - (v65 + ((~(((v66 ^ -1) | (-(v66 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
        int v73 = v71[v172];
        int * v74 = v22->mem;
        int v174 = v70 * 2;
        v74[v174] = v72;
        int * v76 = v22->mem;
        int v177 = (v70 * 2) + 1;
        v76[v177] = v73;
        ;
      } else {
        ;
      }
      int * v81 = v22->mem;
      int v182 = ((int)((unsigned int)((int)((unsigned int)v28 >> 2)) >> 1)) * 2;
      int v82 = v81[v182];
      int v183 = (((int)((unsigned int)((int)((unsigned int)v28 >> 2)) >> 1)) * 2) + 1;
      int v83 = v81[v183];
      int * v84 = v22->cache_vals;
      int v185 = ((4 + ((((int)((unsigned int)((int)((unsigned int)v28 >> 2)) >> 1)) & 3) * 2)) + ((((v62 + ((~(((v64 ^ -1) | (-(v64 ^ -1))) >> 31)) & 2)) - (v65 + ((~(((v66 ^ -1) | (-(v66 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
      v84[v185] = v82;
      int * v86 = v22->cache_vals;
      int v188 = (((4 + ((((int)((unsigned int)((int)((unsigned int)v28 >> 2)) >> 1)) & 3) * 2)) + ((((v62 + ((~(((v64 ^ -1) | (-(v64 ^ -1))) >> 31)) & 2)) - (v65 + ((~(((v66 ^ -1) | (-(v66 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
      v86[v188] = v83;
      int * v88 = v22->cache_tags;
      int v191 = (int)((unsigned int)((int)((unsigned int)v28 >> 2)) >> 1);
      v88[v167] = v191;
      int * v90 = v22->cache_dirty;
      v90[v167] = 0;
      int * v92 = v22->cache_age;
      v92[v167] = 1;
      int * v94 = v22->cache_age;
      int v95 = v94[v167];
      int v96 = v94[v142];
      int v197 = v96 + ((int)((unsigned int)(v96 - v95) >> 31));
      v94[v142] = v197;
      int * v98 = v22->cache_age;
      int v99 = v98[v143];
      int v199 = v99 + ((int)((unsigned int)(v99 - v95) >> 31));
      v98[v143] = v199;
      int * v101 = v22->cache_age;
      v101[v167] = 0;
      v104 = v167;
    }
    int * v105 = v22->cache_vals;
    int v202 = v104 * 2;
    int v106 = v105[v202];
    int v203 = (v104 * 2) + 1;
    int v107 = v105[v203];
    int v204 = (((((int)((unsigned int)((int)((unsigned int)v28 >> 2)) >> 1)) & 1) * 2) + ((((v46 + ((~(((v48 ^ -1) | (-(v48 ^ -1))) >> 31)) & 2)) - (v49 + ((~(((v50 ^ -1) | (-(v50 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
    v105[v204] = v106;
    int * v109 = v22->cache_vals;
    int v207 = ((((((int)((unsigned int)((int)((unsigned int)v28 >> 2)) >> 1)) & 1) * 2) + ((((v46 + ((~(((v48 ^ -1) | (-(v48 ^ -1))) >> 31)) & 2)) - (v49 + ((~(((v50 ^ -1) | (-(v50 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
    v109[v207] = v107;
    int * v111 = v22->cache_tags;
    int v210 = ((((int)((unsigned int)((int)((unsigned int)v28 >> 2)) >> 1)) & 1) * 2) + ((((v46 + ((~(((v48 ^ -1) | (-(v48 ^ -1))) >> 31)) & 2)) - (v49 + ((~(((v50 ^ -1) | (-(v50 ^ -1))) >> 31)) & 2))) >> 31) & 1);
    int v211 = (int)((unsigned int)((int)((unsigned int)v28 >> 2)) >> 1);
    v111[v210] = v211;
    int * v113 = v22->cache_dirty;
    v113[v210] = 0;
    int * v115 = v22->cache_age;
    v115[v210] = 1;
    int * v117 = v22->cache_age;
    int v118 = v117[v210];
    int v119 = v117[v140];
    int v217 = v119 + ((int)((unsigned int)(v119 - v118) >> 31));
    v117[v140] = v217;
    int * v121 = v22->cache_age;
    int v122 = v121[v141];
    int v219 = v122 + ((int)((unsigned int)(v122 - v118) >> 31));
    v121[v141] = v219;
    int * v124 = v22->cache_age;
    v124[v210] = 0;
    v127 = v210;
  }
  int v222 = (v127 * 2) + (((int)((unsigned int)v28 >> 2)) & 1);
  int v128 = v34[v222];
  int * v129 = v22->reg_ready;
  int v225 = ((v26 + ((v23 - v26) & (~((v23 - v26) >> 31)))) + 1) + ((100 ^ (((~(((v32 ^ ((int)((unsigned int)((int)((unsigned int)v28 >> 2)) >> 1))) | (-(v32 ^ ((int)((unsigned int)((int)((unsigned int)v28 >> 2)) >> 1))))) >> 31)) | (~(((v33 ^ ((int)((unsigned int)((int)((unsigned int)v28 >> 2)) >> 1))) | (-(v33 ^ ((int)((unsigned int)((int)((unsigned int)v28 >> 2)) >> 1))))) >> 31))) & 104)) ^ (((~(((v30 ^ ((int)((unsigned int)((int)((unsigned int)v28 >> 2)) >> 1))) | (-(v30 ^ ((int)((unsigned int)((int)((unsigned int)v28 >> 2)) >> 1))))) >> 31)) | (~(((v31 ^ ((int)((unsigned int)((int)((unsigned int)v28 >> 2)) >> 1))) | (-(v31 ^ ((int)((unsigned int)((int)((unsigned int)v28 >> 2)) >> 1))))) >> 31))) & (1 ^ (100 ^ (((~(((v32 ^ ((int)((unsigned int)((int)((unsigned int)v28 >> 2)) >> 1))) | (-(v32 ^ ((int)((unsigned int)((int)((unsigned int)v28 >> 2)) >> 1))))) >> 31)) | (~(((v33 ^ ((int)((unsigned int)((int)((unsigned int)v28 >> 2)) >> 1))) | (-(v33 ^ ((int)((unsigned int)((int)((unsigned int)v28 >> 2)) >> 1))))) >> 31))) & 104)))));
  v129[11] = v225;
  int * v131 = v22->regs;
  v131[11] = v128;
  struct StateT * v133 = slot_2(v22);
  return v133;
}

struct StateT * slot_2(struct StateT * v230) {
  int v231 = v230->timer;
  int v242 = v231 + 1;
  v230->timer = v242;
  int * v233 = v230->reg_ready;
  int v234 = v233[11];
  int * v235 = v230->regs;
  int v236 = v235[11];
  int v246 = (v234 + ((v231 - v234) & (~((v231 - v234) >> 31)))) + 1;
  v233[11] = v246;
  int * v238 = v230->regs;
  int v248 = v236 << 2;
  v238[11] = v248;
  struct StateT * v240 = slot_3(v230);
  return v240;
}

struct StateT * slot_3(struct StateT * v251) {
  int v252 = v251->timer;
  int v363 = v252 + 1;
  v251->timer = v363;
  int * v254 = v251->reg_ready;
  int v255 = v254[11];
  int * v256 = v251->regs;
  int v257 = v256[11];
  int * v258 = v251->cache_tags;
  int v368 = (((int)((unsigned int)((int)((unsigned int)(v257 + 16) >> 2)) >> 1)) & 1) * 2;
  int v259 = v258[v368];
  int v369 = ((((int)((unsigned int)((int)((unsigned int)(v257 + 16) >> 2)) >> 1)) & 1) * 2) + 1;
  int v260 = v258[v369];
  int v370 = 4 + ((((int)((unsigned int)((int)((unsigned int)(v257 + 16) >> 2)) >> 1)) & 3) * 2);
  int v261 = v258[v370];
  int v371 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v257 + 16) >> 2)) >> 1)) & 3) * 2)) + 1;
  int v262 = v258[v371];
  int * v263 = v251->cache_vals;
  bool v372 = !(((~(((v259 ^ ((int)((unsigned int)((int)((unsigned int)(v257 + 16) >> 2)) >> 1))) | (-(v259 ^ ((int)((unsigned int)((int)((unsigned int)(v257 + 16) >> 2)) >> 1))))) >> 31)) | (~(((v260 ^ ((int)((unsigned int)((int)((unsigned int)(v257 + 16) >> 2)) >> 1))) | (-(v260 ^ ((int)((unsigned int)((int)((unsigned int)(v257 + 16) >> 2)) >> 1))))) >> 31))) == 0);
  int v356;
  if (v372) {
    int * v264 = v251->cache_age;
    int v374 = ((((int)((unsigned int)((int)((unsigned int)(v257 + 16) >> 2)) >> 1)) & 1) * 2) + ((~(((v260 ^ ((int)((unsigned int)((int)((unsigned int)(v257 + 16) >> 2)) >> 1))) | (-(v260 ^ ((int)((unsigned int)((int)((unsigned int)(v257 + 16) >> 2)) >> 1))))) >> 31)) & 1);
    int v265 = v264[v374];
    int v266 = v264[v368];
    int v375 = v266 + ((int)((unsigned int)(v266 - v265) >> 31));
    v264[v368] = v375;
    int * v268 = v251->cache_age;
    int v269 = v268[v369];
    int v377 = v269 + ((int)((unsigned int)(v269 - v265) >> 31));
    v268[v369] = v377;
    int * v271 = v251->cache_age;
    v271[v374] = 0;
    v356 = v374;
  } else {
    int * v274 = v251->cache_age;
    int v381 = (((int)((unsigned int)((int)((unsigned int)(v257 + 16) >> 2)) >> 1)) & 1) * 2;
    int v275 = v274[v381];
    int * v276 = v251->cache_tags;
    int v277 = v276[v381];
    int v278 = v274[v369];
    int v279 = v276[v369];
    bool v383 = !(((~(((v261 ^ ((int)((unsigned int)((int)((unsigned int)(v257 + 16) >> 2)) >> 1))) | (-(v261 ^ ((int)((unsigned int)((int)((unsigned int)(v257 + 16) >> 2)) >> 1))))) >> 31)) | (~(((v262 ^ ((int)((unsigned int)((int)((unsigned int)(v257 + 16) >> 2)) >> 1))) | (-(v262 ^ ((int)((unsigned int)((int)((unsigned int)(v257 + 16) >> 2)) >> 1))))) >> 31))) == 0);
    int v333;
    if (v383) {
      int * v280 = v251->cache_age;
      int v385 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v257 + 16) >> 2)) >> 1)) & 3) * 2)) + ((~(((v262 ^ ((int)((unsigned int)((int)((unsigned int)(v257 + 16) >> 2)) >> 1))) | (-(v262 ^ ((int)((unsigned int)((int)((unsigned int)(v257 + 16) >> 2)) >> 1))))) >> 31)) & 1);
      int v281 = v280[v385];
      int v282 = v280[v370];
      int v386 = v282 + ((int)((unsigned int)(v282 - v281) >> 31));
      v280[v370] = v386;
      int * v284 = v251->cache_age;
      int v285 = v284[v371];
      int v388 = v285 + ((int)((unsigned int)(v285 - v281) >> 31));
      v284[v371] = v388;
      int * v287 = v251->cache_age;
      v287[v385] = 0;
      v333 = v385;
    } else {
      int * v290 = v251->cache_age;
      int v392 = 4 + ((((int)((unsigned int)((int)((unsigned int)(v257 + 16) >> 2)) >> 1)) & 3) * 2);
      int v291 = v290[v392];
      int * v292 = v251->cache_tags;
      int v293 = v292[v392];
      int v294 = v290[v371];
      int v295 = v292[v371];
      int * v296 = v251->cache_dirty;
      int v395 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v257 + 16) >> 2)) >> 1)) & 3) * 2)) + ((((v291 + ((~(((v293 ^ -1) | (-(v293 ^ -1))) >> 31)) & 2)) - (v294 + ((~(((v295 ^ -1) | (-(v295 ^ -1))) >> 31)) & 2))) >> 31) & 1);
      int v297 = v296[v395];
      bool v396 = !(v297 == 0);
      if (v396) {
        int * v298 = v251->cache_tags;
        int v299 = v298[v395];
        int * v300 = v251->cache_vals;
        int v399 = ((4 + ((((int)((unsigned int)((int)((unsigned int)(v257 + 16) >> 2)) >> 1)) & 3) * 2)) + ((((v291 + ((~(((v293 ^ -1) | (-(v293 ^ -1))) >> 31)) & 2)) - (v294 + ((~(((v295 ^ -1) | (-(v295 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
        int v301 = v300[v399];
        int v400 = (((4 + ((((int)((unsigned int)((int)((unsigned int)(v257 + 16) >> 2)) >> 1)) & 3) * 2)) + ((((v291 + ((~(((v293 ^ -1) | (-(v293 ^ -1))) >> 31)) & 2)) - (v294 + ((~(((v295 ^ -1) | (-(v295 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
        int v302 = v300[v400];
        int * v303 = v251->mem;
        int v402 = v299 * 2;
        v303[v402] = v301;
        int * v305 = v251->mem;
        int v405 = (v299 * 2) + 1;
        v305[v405] = v302;
        ;
      } else {
        ;
      }
      int * v310 = v251->mem;
      int v410 = ((int)((unsigned int)((int)((unsigned int)(v257 + 16) >> 2)) >> 1)) * 2;
      int v311 = v310[v410];
      int v411 = (((int)((unsigned int)((int)((unsigned int)(v257 + 16) >> 2)) >> 1)) * 2) + 1;
      int v312 = v310[v411];
      int * v313 = v251->cache_vals;
      int v413 = ((4 + ((((int)((unsigned int)((int)((unsigned int)(v257 + 16) >> 2)) >> 1)) & 3) * 2)) + ((((v291 + ((~(((v293 ^ -1) | (-(v293 ^ -1))) >> 31)) & 2)) - (v294 + ((~(((v295 ^ -1) | (-(v295 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
      v313[v413] = v311;
      int * v315 = v251->cache_vals;
      int v416 = (((4 + ((((int)((unsigned int)((int)((unsigned int)(v257 + 16) >> 2)) >> 1)) & 3) * 2)) + ((((v291 + ((~(((v293 ^ -1) | (-(v293 ^ -1))) >> 31)) & 2)) - (v294 + ((~(((v295 ^ -1) | (-(v295 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
      v315[v416] = v312;
      int * v317 = v251->cache_tags;
      int v419 = (int)((unsigned int)((int)((unsigned int)(v257 + 16) >> 2)) >> 1);
      v317[v395] = v419;
      int * v319 = v251->cache_dirty;
      v319[v395] = 0;
      int * v321 = v251->cache_age;
      v321[v395] = 1;
      int * v323 = v251->cache_age;
      int v324 = v323[v395];
      int v325 = v323[v370];
      int v425 = v325 + ((int)((unsigned int)(v325 - v324) >> 31));
      v323[v370] = v425;
      int * v327 = v251->cache_age;
      int v328 = v327[v371];
      int v427 = v328 + ((int)((unsigned int)(v328 - v324) >> 31));
      v327[v371] = v427;
      int * v330 = v251->cache_age;
      v330[v395] = 0;
      v333 = v395;
    }
    int * v334 = v251->cache_vals;
    int v430 = v333 * 2;
    int v335 = v334[v430];
    int v431 = (v333 * 2) + 1;
    int v336 = v334[v431];
    int v432 = (((((int)((unsigned int)((int)((unsigned int)(v257 + 16) >> 2)) >> 1)) & 1) * 2) + ((((v275 + ((~(((v277 ^ -1) | (-(v277 ^ -1))) >> 31)) & 2)) - (v278 + ((~(((v279 ^ -1) | (-(v279 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
    v334[v432] = v335;
    int * v338 = v251->cache_vals;
    int v435 = ((((((int)((unsigned int)((int)((unsigned int)(v257 + 16) >> 2)) >> 1)) & 1) * 2) + ((((v275 + ((~(((v277 ^ -1) | (-(v277 ^ -1))) >> 31)) & 2)) - (v278 + ((~(((v279 ^ -1) | (-(v279 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
    v338[v435] = v336;
    int * v340 = v251->cache_tags;
    int v438 = ((((int)((unsigned int)((int)((unsigned int)(v257 + 16) >> 2)) >> 1)) & 1) * 2) + ((((v275 + ((~(((v277 ^ -1) | (-(v277 ^ -1))) >> 31)) & 2)) - (v278 + ((~(((v279 ^ -1) | (-(v279 ^ -1))) >> 31)) & 2))) >> 31) & 1);
    int v439 = (int)((unsigned int)((int)((unsigned int)(v257 + 16) >> 2)) >> 1);
    v340[v438] = v439;
    int * v342 = v251->cache_dirty;
    v342[v438] = 0;
    int * v344 = v251->cache_age;
    v344[v438] = 1;
    int * v346 = v251->cache_age;
    int v347 = v346[v438];
    int v348 = v346[v368];
    int v445 = v348 + ((int)((unsigned int)(v348 - v347) >> 31));
    v346[v368] = v445;
    int * v350 = v251->cache_age;
    int v351 = v350[v369];
    int v447 = v351 + ((int)((unsigned int)(v351 - v347) >> 31));
    v350[v369] = v447;
    int * v353 = v251->cache_age;
    v353[v438] = 0;
    v356 = v438;
  }
  int v450 = (v356 * 2) + (((int)((unsigned int)(v257 + 16) >> 2)) & 1);
  int v357 = v263[v450];
  int * v358 = v251->reg_ready;
  int v453 = ((v255 + ((v252 - v255) & (~((v252 - v255) >> 31)))) + 1) + ((100 ^ (((~(((v261 ^ ((int)((unsigned int)((int)((unsigned int)(v257 + 16) >> 2)) >> 1))) | (-(v261 ^ ((int)((unsigned int)((int)((unsigned int)(v257 + 16) >> 2)) >> 1))))) >> 31)) | (~(((v262 ^ ((int)((unsigned int)((int)((unsigned int)(v257 + 16) >> 2)) >> 1))) | (-(v262 ^ ((int)((unsigned int)((int)((unsigned int)(v257 + 16) >> 2)) >> 1))))) >> 31))) & 104)) ^ (((~(((v259 ^ ((int)((unsigned int)((int)((unsigned int)(v257 + 16) >> 2)) >> 1))) | (-(v259 ^ ((int)((unsigned int)((int)((unsigned int)(v257 + 16) >> 2)) >> 1))))) >> 31)) | (~(((v260 ^ ((int)((unsigned int)((int)((unsigned int)(v257 + 16) >> 2)) >> 1))) | (-(v260 ^ ((int)((unsigned int)((int)((unsigned int)(v257 + 16) >> 2)) >> 1))))) >> 31))) & (1 ^ (100 ^ (((~(((v261 ^ ((int)((unsigned int)((int)((unsigned int)(v257 + 16) >> 2)) >> 1))) | (-(v261 ^ ((int)((unsigned int)((int)((unsigned int)(v257 + 16) >> 2)) >> 1))))) >> 31)) | (~(((v262 ^ ((int)((unsigned int)((int)((unsigned int)(v257 + 16) >> 2)) >> 1))) | (-(v262 ^ ((int)((unsigned int)((int)((unsigned int)(v257 + 16) >> 2)) >> 1))))) >> 31))) & 104)))));
  v358[12] = v453;
  int * v360 = v251->regs;
  v360[12] = v357;
  return v251;
}

struct StateT * slot_0(struct StateT * v2) {
  int v3 = v2->timer;
  int v14 = v3 + 1;
  v2->timer = v14;
  int * v5 = v2->reg_ready;
  int * v7 = v2->regs;
  int v8 = v7[10];
  bool v18 = v8 == 0;
  struct StateT * v12;
  if (v18) {
    v12 = v2;
  } else {
    struct StateT * v10 = slot_1(v2);
    v12 = v10;
  }
  return v12;
}



/*****************************************
End of C Generated Code
*******************************************/

void init(struct StateT *s) {
  for (int i=0; i<NUM_REGS; i++) {
    s->regs[i] = 0;
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
  koika_assert(s1_->timer==s2_->timer, "timing leak");
  return 0;
}