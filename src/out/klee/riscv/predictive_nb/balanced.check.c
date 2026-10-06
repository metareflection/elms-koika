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
struct StateT * slot_1(struct StateT * v18);
struct StateT * slot_8(struct StateT * v513);
struct StateT * slot_6(struct StateT * v492);
struct StateT * slot_5(struct StateT * v273);
struct StateT * slot_4(struct StateT * v250);
struct StateT * slot_2(struct StateT * v226);
struct StateT * slot_3(struct StateT * v242);
struct StateT * slot_0(struct StateT * v2);
struct StateT * snippet(struct StateT * v0) {
  struct StateT * v1 = slot_0(v0);
  int v518 = v1->timer;
  int * v519 = v1->reg_ready;
  int v520 = v519[0];
  int v651 = v520 + ((v518 - v520) & (~((v518 - v520) >> 31)));
  v1->timer = v651;
  int v522 = v1->timer;
  int * v523 = v1->reg_ready;
  int v524 = v523[1];
  int v654 = v524 + ((v522 - v524) & (~((v522 - v524) >> 31)));
  v1->timer = v654;
  int v526 = v1->timer;
  int * v527 = v1->reg_ready;
  int v528 = v527[2];
  int v657 = v528 + ((v526 - v528) & (~((v526 - v528) >> 31)));
  v1->timer = v657;
  int v530 = v1->timer;
  int * v531 = v1->reg_ready;
  int v532 = v531[3];
  int v660 = v532 + ((v530 - v532) & (~((v530 - v532) >> 31)));
  v1->timer = v660;
  int v534 = v1->timer;
  int * v535 = v1->reg_ready;
  int v536 = v535[4];
  int v663 = v536 + ((v534 - v536) & (~((v534 - v536) >> 31)));
  v1->timer = v663;
  int v538 = v1->timer;
  int * v539 = v1->reg_ready;
  int v540 = v539[5];
  int v666 = v540 + ((v538 - v540) & (~((v538 - v540) >> 31)));
  v1->timer = v666;
  int v542 = v1->timer;
  int * v543 = v1->reg_ready;
  int v544 = v543[6];
  int v669 = v544 + ((v542 - v544) & (~((v542 - v544) >> 31)));
  v1->timer = v669;
  int v546 = v1->timer;
  int * v547 = v1->reg_ready;
  int v548 = v547[7];
  int v672 = v548 + ((v546 - v548) & (~((v546 - v548) >> 31)));
  v1->timer = v672;
  int v550 = v1->timer;
  int * v551 = v1->reg_ready;
  int v552 = v551[8];
  int v675 = v552 + ((v550 - v552) & (~((v550 - v552) >> 31)));
  v1->timer = v675;
  int v554 = v1->timer;
  int * v555 = v1->reg_ready;
  int v556 = v555[9];
  int v678 = v556 + ((v554 - v556) & (~((v554 - v556) >> 31)));
  v1->timer = v678;
  int v558 = v1->timer;
  int * v559 = v1->reg_ready;
  int v560 = v559[10];
  int v681 = v560 + ((v558 - v560) & (~((v558 - v560) >> 31)));
  v1->timer = v681;
  int v562 = v1->timer;
  int * v563 = v1->reg_ready;
  int v564 = v563[11];
  int v684 = v564 + ((v562 - v564) & (~((v562 - v564) >> 31)));
  v1->timer = v684;
  int v566 = v1->timer;
  int * v567 = v1->reg_ready;
  int v568 = v567[12];
  int v687 = v568 + ((v566 - v568) & (~((v566 - v568) >> 31)));
  v1->timer = v687;
  int v570 = v1->timer;
  int * v571 = v1->reg_ready;
  int v572 = v571[13];
  int v690 = v572 + ((v570 - v572) & (~((v570 - v572) >> 31)));
  v1->timer = v690;
  int v574 = v1->timer;
  int * v575 = v1->reg_ready;
  int v576 = v575[14];
  int v693 = v576 + ((v574 - v576) & (~((v574 - v576) >> 31)));
  v1->timer = v693;
  int v578 = v1->timer;
  int * v579 = v1->reg_ready;
  int v580 = v579[15];
  int v696 = v580 + ((v578 - v580) & (~((v578 - v580) >> 31)));
  v1->timer = v696;
  int v582 = v1->timer;
  int * v583 = v1->reg_ready;
  int v584 = v583[16];
  int v699 = v584 + ((v582 - v584) & (~((v582 - v584) >> 31)));
  v1->timer = v699;
  int v586 = v1->timer;
  int * v587 = v1->reg_ready;
  int v588 = v587[17];
  int v702 = v588 + ((v586 - v588) & (~((v586 - v588) >> 31)));
  v1->timer = v702;
  int v590 = v1->timer;
  int * v591 = v1->reg_ready;
  int v592 = v591[18];
  int v705 = v592 + ((v590 - v592) & (~((v590 - v592) >> 31)));
  v1->timer = v705;
  int v594 = v1->timer;
  int * v595 = v1->reg_ready;
  int v596 = v595[19];
  int v708 = v596 + ((v594 - v596) & (~((v594 - v596) >> 31)));
  v1->timer = v708;
  int v598 = v1->timer;
  int * v599 = v1->reg_ready;
  int v600 = v599[20];
  int v711 = v600 + ((v598 - v600) & (~((v598 - v600) >> 31)));
  v1->timer = v711;
  int v602 = v1->timer;
  int * v603 = v1->reg_ready;
  int v604 = v603[21];
  int v714 = v604 + ((v602 - v604) & (~((v602 - v604) >> 31)));
  v1->timer = v714;
  int v606 = v1->timer;
  int * v607 = v1->reg_ready;
  int v608 = v607[22];
  int v717 = v608 + ((v606 - v608) & (~((v606 - v608) >> 31)));
  v1->timer = v717;
  int v610 = v1->timer;
  int * v611 = v1->reg_ready;
  int v612 = v611[23];
  int v720 = v612 + ((v610 - v612) & (~((v610 - v612) >> 31)));
  v1->timer = v720;
  int v614 = v1->timer;
  int * v615 = v1->reg_ready;
  int v616 = v615[24];
  int v723 = v616 + ((v614 - v616) & (~((v614 - v616) >> 31)));
  v1->timer = v723;
  int v618 = v1->timer;
  int * v619 = v1->reg_ready;
  int v620 = v619[25];
  int v726 = v620 + ((v618 - v620) & (~((v618 - v620) >> 31)));
  v1->timer = v726;
  int v622 = v1->timer;
  int * v623 = v1->reg_ready;
  int v624 = v623[26];
  int v729 = v624 + ((v622 - v624) & (~((v622 - v624) >> 31)));
  v1->timer = v729;
  int v626 = v1->timer;
  int * v627 = v1->reg_ready;
  int v628 = v627[27];
  int v732 = v628 + ((v626 - v628) & (~((v626 - v628) >> 31)));
  v1->timer = v732;
  int v630 = v1->timer;
  int * v631 = v1->reg_ready;
  int v632 = v631[28];
  int v735 = v632 + ((v630 - v632) & (~((v630 - v632) >> 31)));
  v1->timer = v735;
  int v634 = v1->timer;
  int * v635 = v1->reg_ready;
  int v636 = v635[29];
  int v738 = v636 + ((v634 - v636) & (~((v634 - v636) >> 31)));
  v1->timer = v738;
  int v638 = v1->timer;
  int * v639 = v1->reg_ready;
  int v640 = v639[30];
  int v741 = v640 + ((v638 - v640) & (~((v638 - v640) >> 31)));
  v1->timer = v741;
  int v642 = v1->timer;
  int * v643 = v1->reg_ready;
  int v644 = v643[31];
  int v744 = v644 + ((v642 - v644) & (~((v642 - v644) >> 31)));
  v1->timer = v744;
  return v1;
}

struct StateT * slot_1(struct StateT * v18) {
  int v19 = v18->timer;
  int v131 = v19 + 1;
  v18->timer = v131;
  int * v21 = v18->reg_ready;
  int v22 = v21[12];
  int * v23 = v18->regs;
  int v24 = v23[12];
  int * v25 = v18->cache_tags;
  int v136 = (((int)((unsigned int)((int)((unsigned int)v24 >> 2)) >> 1)) & 1) * 2;
  int v26 = v25[v136];
  int v137 = ((((int)((unsigned int)((int)((unsigned int)v24 >> 2)) >> 1)) & 1) * 2) + 1;
  int v27 = v25[v137];
  int v138 = 4 + ((((int)((unsigned int)((int)((unsigned int)v24 >> 2)) >> 1)) & 3) * 2);
  int v28 = v25[v138];
  int v139 = (4 + ((((int)((unsigned int)((int)((unsigned int)v24 >> 2)) >> 1)) & 3) * 2)) + 1;
  int v29 = v25[v139];
  int * v30 = v18->cache_vals;
  bool v140 = !(((~(((v26 ^ ((int)((unsigned int)((int)((unsigned int)v24 >> 2)) >> 1))) | (-(v26 ^ ((int)((unsigned int)((int)((unsigned int)v24 >> 2)) >> 1))))) >> 31)) | (~(((v27 ^ ((int)((unsigned int)((int)((unsigned int)v24 >> 2)) >> 1))) | (-(v27 ^ ((int)((unsigned int)((int)((unsigned int)v24 >> 2)) >> 1))))) >> 31))) == 0);
  int v123;
  if (v140) {
    int * v31 = v18->cache_age;
    int v142 = ((((int)((unsigned int)((int)((unsigned int)v24 >> 2)) >> 1)) & 1) * 2) + ((~(((v27 ^ ((int)((unsigned int)((int)((unsigned int)v24 >> 2)) >> 1))) | (-(v27 ^ ((int)((unsigned int)((int)((unsigned int)v24 >> 2)) >> 1))))) >> 31)) & 1);
    int v32 = v31[v142];
    int v33 = v31[v136];
    int v143 = v33 + ((int)((unsigned int)(v33 - v32) >> 31));
    v31[v136] = v143;
    int * v35 = v18->cache_age;
    int v36 = v35[v137];
    int v145 = v36 + ((int)((unsigned int)(v36 - v32) >> 31));
    v35[v137] = v145;
    int * v38 = v18->cache_age;
    v38[v142] = 0;
    v123 = v142;
  } else {
    int * v41 = v18->cache_age;
    int v149 = (((int)((unsigned int)((int)((unsigned int)v24 >> 2)) >> 1)) & 1) * 2;
    int v42 = v41[v149];
    int * v43 = v18->cache_tags;
    int v44 = v43[v149];
    int v45 = v41[v137];
    int v46 = v43[v137];
    bool v151 = !(((~(((v28 ^ ((int)((unsigned int)((int)((unsigned int)v24 >> 2)) >> 1))) | (-(v28 ^ ((int)((unsigned int)((int)((unsigned int)v24 >> 2)) >> 1))))) >> 31)) | (~(((v29 ^ ((int)((unsigned int)((int)((unsigned int)v24 >> 2)) >> 1))) | (-(v29 ^ ((int)((unsigned int)((int)((unsigned int)v24 >> 2)) >> 1))))) >> 31))) == 0);
    int v100;
    if (v151) {
      int * v47 = v18->cache_age;
      int v153 = (4 + ((((int)((unsigned int)((int)((unsigned int)v24 >> 2)) >> 1)) & 3) * 2)) + ((~(((v29 ^ ((int)((unsigned int)((int)((unsigned int)v24 >> 2)) >> 1))) | (-(v29 ^ ((int)((unsigned int)((int)((unsigned int)v24 >> 2)) >> 1))))) >> 31)) & 1);
      int v48 = v47[v153];
      int v49 = v47[v138];
      int v154 = v49 + ((int)((unsigned int)(v49 - v48) >> 31));
      v47[v138] = v154;
      int * v51 = v18->cache_age;
      int v52 = v51[v139];
      int v156 = v52 + ((int)((unsigned int)(v52 - v48) >> 31));
      v51[v139] = v156;
      int * v54 = v18->cache_age;
      v54[v153] = 0;
      v100 = v153;
    } else {
      int * v57 = v18->cache_age;
      int v160 = 4 + ((((int)((unsigned int)((int)((unsigned int)v24 >> 2)) >> 1)) & 3) * 2);
      int v58 = v57[v160];
      int * v59 = v18->cache_tags;
      int v60 = v59[v160];
      int v61 = v57[v139];
      int v62 = v59[v139];
      int * v63 = v18->cache_dirty;
      int v163 = (4 + ((((int)((unsigned int)((int)((unsigned int)v24 >> 2)) >> 1)) & 3) * 2)) + ((((v58 + ((~(((v60 ^ -1) | (-(v60 ^ -1))) >> 31)) & 2)) - (v61 + ((~(((v62 ^ -1) | (-(v62 ^ -1))) >> 31)) & 2))) >> 31) & 1);
      int v64 = v63[v163];
      bool v164 = !(v64 == 0);
      if (v164) {
        int * v65 = v18->cache_tags;
        int v66 = v65[v163];
        int * v67 = v18->cache_vals;
        int v167 = ((4 + ((((int)((unsigned int)((int)((unsigned int)v24 >> 2)) >> 1)) & 3) * 2)) + ((((v58 + ((~(((v60 ^ -1) | (-(v60 ^ -1))) >> 31)) & 2)) - (v61 + ((~(((v62 ^ -1) | (-(v62 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
        int v68 = v67[v167];
        int v168 = (((4 + ((((int)((unsigned int)((int)((unsigned int)v24 >> 2)) >> 1)) & 3) * 2)) + ((((v58 + ((~(((v60 ^ -1) | (-(v60 ^ -1))) >> 31)) & 2)) - (v61 + ((~(((v62 ^ -1) | (-(v62 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
        int v69 = v67[v168];
        int * v70 = v18->mem;
        int v170 = v66 * 2;
        v70[v170] = v68;
        int * v72 = v18->mem;
        int v173 = (v66 * 2) + 1;
        v72[v173] = v69;
        ;
      } else {
        ;
      }
      int * v77 = v18->mem;
      int v178 = ((int)((unsigned int)((int)((unsigned int)v24 >> 2)) >> 1)) * 2;
      int v78 = v77[v178];
      int v179 = (((int)((unsigned int)((int)((unsigned int)v24 >> 2)) >> 1)) * 2) + 1;
      int v79 = v77[v179];
      int * v80 = v18->cache_vals;
      int v181 = ((4 + ((((int)((unsigned int)((int)((unsigned int)v24 >> 2)) >> 1)) & 3) * 2)) + ((((v58 + ((~(((v60 ^ -1) | (-(v60 ^ -1))) >> 31)) & 2)) - (v61 + ((~(((v62 ^ -1) | (-(v62 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
      v80[v181] = v78;
      int * v82 = v18->cache_vals;
      int v184 = (((4 + ((((int)((unsigned int)((int)((unsigned int)v24 >> 2)) >> 1)) & 3) * 2)) + ((((v58 + ((~(((v60 ^ -1) | (-(v60 ^ -1))) >> 31)) & 2)) - (v61 + ((~(((v62 ^ -1) | (-(v62 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
      v82[v184] = v79;
      int * v84 = v18->cache_tags;
      int v187 = (int)((unsigned int)((int)((unsigned int)v24 >> 2)) >> 1);
      v84[v163] = v187;
      int * v86 = v18->cache_dirty;
      v86[v163] = 0;
      int * v88 = v18->cache_age;
      v88[v163] = 1;
      int * v90 = v18->cache_age;
      int v91 = v90[v163];
      int v92 = v90[v138];
      int v193 = v92 + ((int)((unsigned int)(v92 - v91) >> 31));
      v90[v138] = v193;
      int * v94 = v18->cache_age;
      int v95 = v94[v139];
      int v195 = v95 + ((int)((unsigned int)(v95 - v91) >> 31));
      v94[v139] = v195;
      int * v97 = v18->cache_age;
      v97[v163] = 0;
      v100 = v163;
    }
    int * v101 = v18->cache_vals;
    int v198 = v100 * 2;
    int v102 = v101[v198];
    int v199 = (v100 * 2) + 1;
    int v103 = v101[v199];
    int v200 = (((((int)((unsigned int)((int)((unsigned int)v24 >> 2)) >> 1)) & 1) * 2) + ((((v42 + ((~(((v44 ^ -1) | (-(v44 ^ -1))) >> 31)) & 2)) - (v45 + ((~(((v46 ^ -1) | (-(v46 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
    v101[v200] = v102;
    int * v105 = v18->cache_vals;
    int v203 = ((((((int)((unsigned int)((int)((unsigned int)v24 >> 2)) >> 1)) & 1) * 2) + ((((v42 + ((~(((v44 ^ -1) | (-(v44 ^ -1))) >> 31)) & 2)) - (v45 + ((~(((v46 ^ -1) | (-(v46 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
    v105[v203] = v103;
    int * v107 = v18->cache_tags;
    int v206 = ((((int)((unsigned int)((int)((unsigned int)v24 >> 2)) >> 1)) & 1) * 2) + ((((v42 + ((~(((v44 ^ -1) | (-(v44 ^ -1))) >> 31)) & 2)) - (v45 + ((~(((v46 ^ -1) | (-(v46 ^ -1))) >> 31)) & 2))) >> 31) & 1);
    int v207 = (int)((unsigned int)((int)((unsigned int)v24 >> 2)) >> 1);
    v107[v206] = v207;
    int * v109 = v18->cache_dirty;
    v109[v206] = 0;
    int * v111 = v18->cache_age;
    v111[v206] = 1;
    int * v113 = v18->cache_age;
    int v114 = v113[v206];
    int v115 = v113[v136];
    int v213 = v115 + ((int)((unsigned int)(v115 - v114) >> 31));
    v113[v136] = v213;
    int * v117 = v18->cache_age;
    int v118 = v117[v137];
    int v215 = v118 + ((int)((unsigned int)(v118 - v114) >> 31));
    v117[v137] = v215;
    int * v120 = v18->cache_age;
    v120[v206] = 0;
    v123 = v206;
  }
  int v218 = (v123 * 2) + (((int)((unsigned int)v24 >> 2)) & 1);
  int v124 = v30[v218];
  int * v125 = v18->reg_ready;
  int v221 = ((v22 + ((v19 - v22) & (~((v19 - v22) >> 31)))) + 1) + ((100 ^ (((~(((v28 ^ ((int)((unsigned int)((int)((unsigned int)v24 >> 2)) >> 1))) | (-(v28 ^ ((int)((unsigned int)((int)((unsigned int)v24 >> 2)) >> 1))))) >> 31)) | (~(((v29 ^ ((int)((unsigned int)((int)((unsigned int)v24 >> 2)) >> 1))) | (-(v29 ^ ((int)((unsigned int)((int)((unsigned int)v24 >> 2)) >> 1))))) >> 31))) & 104)) ^ (((~(((v26 ^ ((int)((unsigned int)((int)((unsigned int)v24 >> 2)) >> 1))) | (-(v26 ^ ((int)((unsigned int)((int)((unsigned int)v24 >> 2)) >> 1))))) >> 31)) | (~(((v27 ^ ((int)((unsigned int)((int)((unsigned int)v24 >> 2)) >> 1))) | (-(v27 ^ ((int)((unsigned int)((int)((unsigned int)v24 >> 2)) >> 1))))) >> 31))) & (1 ^ (100 ^ (((~(((v28 ^ ((int)((unsigned int)((int)((unsigned int)v24 >> 2)) >> 1))) | (-(v28 ^ ((int)((unsigned int)((int)((unsigned int)v24 >> 2)) >> 1))))) >> 31)) | (~(((v29 ^ ((int)((unsigned int)((int)((unsigned int)v24 >> 2)) >> 1))) | (-(v29 ^ ((int)((unsigned int)((int)((unsigned int)v24 >> 2)) >> 1))))) >> 31))) & 104)))));
  v125[16] = v221;
  int * v127 = v18->regs;
  v127[16] = v124;
  struct StateT * v129 = slot_2(v18);
  return v129;
}

struct StateT * slot_8(struct StateT * v513) {
  int v514 = v513->timer;
  int v517 = v514 + 1;
  v513->timer = v517;
  return v513;
}

struct StateT * slot_6(struct StateT * v492) {
  int v493 = v492->timer;
  int v501 = v493 + 1;
  v492->timer = v501;
  int * v495 = v492->reg_ready;
  v495[18] = v501;
  int * v497 = v492->regs;
  v497[18] = 2;
  struct StateT * v499 = slot_8(v492);
  return v499;
}

struct StateT * slot_5(struct StateT * v273) {
  int * v274 = v273->regs;
  int v275 = v274[16];
  int v276 = v274[17];
  bool v388 = v275 < v276;
  struct StateT * v383;
  if (v388) {
    int v277 = v273->timer;
    int v389 = v277 + 15;
    v273->timer = v389;
    int * v279 = v273->saved_regs;
    int v280 = v279[18];
    int * v281 = v273->regs;
    v281[18] = v280;
    int * v283 = v273->reg_ready;
    int v284 = v273->timer;
    v283[0] = v284;
    int * v286 = v273->reg_ready;
    int v287 = v273->timer;
    v286[1] = v287;
    int * v289 = v273->reg_ready;
    int v290 = v273->timer;
    v289[2] = v290;
    int * v292 = v273->reg_ready;
    int v293 = v273->timer;
    v292[3] = v293;
    int * v295 = v273->reg_ready;
    int v296 = v273->timer;
    v295[4] = v296;
    int * v298 = v273->reg_ready;
    int v299 = v273->timer;
    v298[5] = v299;
    int * v301 = v273->reg_ready;
    int v302 = v273->timer;
    v301[6] = v302;
    int * v304 = v273->reg_ready;
    int v305 = v273->timer;
    v304[7] = v305;
    int * v307 = v273->reg_ready;
    int v308 = v273->timer;
    v307[8] = v308;
    int * v310 = v273->reg_ready;
    int v311 = v273->timer;
    v310[9] = v311;
    int * v313 = v273->reg_ready;
    int v314 = v273->timer;
    v313[10] = v314;
    int * v316 = v273->reg_ready;
    int v317 = v273->timer;
    v316[11] = v317;
    int * v319 = v273->reg_ready;
    int v320 = v273->timer;
    v319[12] = v320;
    int * v322 = v273->reg_ready;
    int v323 = v273->timer;
    v322[13] = v323;
    int * v325 = v273->reg_ready;
    int v326 = v273->timer;
    v325[14] = v326;
    int * v328 = v273->reg_ready;
    int v329 = v273->timer;
    v328[15] = v329;
    int * v331 = v273->reg_ready;
    int v332 = v273->timer;
    v331[16] = v332;
    int * v334 = v273->reg_ready;
    int v335 = v273->timer;
    v334[17] = v335;
    int * v337 = v273->reg_ready;
    int v338 = v273->timer;
    v337[18] = v338;
    int * v340 = v273->reg_ready;
    int v341 = v273->timer;
    v340[19] = v341;
    int * v343 = v273->reg_ready;
    int v344 = v273->timer;
    v343[20] = v344;
    int * v346 = v273->reg_ready;
    int v347 = v273->timer;
    v346[21] = v347;
    int * v349 = v273->reg_ready;
    int v350 = v273->timer;
    v349[22] = v350;
    int * v352 = v273->reg_ready;
    int v353 = v273->timer;
    v352[23] = v353;
    int * v355 = v273->reg_ready;
    int v356 = v273->timer;
    v355[24] = v356;
    int * v358 = v273->reg_ready;
    int v359 = v273->timer;
    v358[25] = v359;
    int * v361 = v273->reg_ready;
    int v362 = v273->timer;
    v361[26] = v362;
    int * v364 = v273->reg_ready;
    int v365 = v273->timer;
    v364[27] = v365;
    int * v367 = v273->reg_ready;
    int v368 = v273->timer;
    v367[28] = v368;
    int * v370 = v273->reg_ready;
    int v371 = v273->timer;
    v370[29] = v371;
    int * v373 = v273->reg_ready;
    int v374 = v273->timer;
    v373[30] = v374;
    int * v376 = v273->reg_ready;
    int v377 = v273->timer;
    v376[31] = v377;
    struct StateT * v379 = slot_6(v273);
    v383 = v379;
  } else {
    struct StateT * v381 = slot_8(v273);
    v383 = v381;
  }
  return v383;
}

struct StateT * slot_4(struct StateT * v250) {
  int * v251 = v250->saved_regs;
  int * v252 = v250->regs;
  int v253 = v252[18];
  v251[18] = v253;
  int v255 = v250->timer;
  int v267 = v255 + 1;
  v250->timer = v267;
  int * v257 = v250->reg_ready;
  v257[18] = v267;
  int * v259 = v250->regs;
  v259[18] = 1;
  struct StateT * v261 = slot_5(v250);
  return v261;
}

struct StateT * slot_2(struct StateT * v226) {
  int v227 = v226->timer;
  int v235 = v227 + 1;
  v226->timer = v235;
  int * v229 = v226->reg_ready;
  v229[17] = v235;
  int * v231 = v226->regs;
  v231[17] = 10;
  struct StateT * v233 = slot_3(v226);
  return v233;
}

struct StateT * slot_3(struct StateT * v242) {
  int v243 = v242->timer;
  int v247 = v243 + 1;
  v242->timer = v247;
  struct StateT * v245 = slot_4(v242);
  return v245;
}

struct StateT * slot_0(struct StateT * v2) {
  int v3 = v2->timer;
  int v11 = v3 + 1;
  v2->timer = v11;
  int * v5 = v2->reg_ready;
  v5[12] = v11;
  int * v7 = v2->regs;
  v7[12] = 80;
  struct StateT * v9 = slot_1(v2);
  return v9;
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
  koika_assert(s1_->timer==s2_->timer, "timing leak");
  return 0;
}