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
struct StateT * slot_1(struct StateT * v23);
struct StateT * slot_2(struct StateT * v278);
struct StateT * slot_3(struct StateT * v302);
struct StateT * slot_0(struct StateT * v2);
struct StateT * snippet(struct StateT * v0) {
  struct StateT * v1 = slot_0(v0);
  int v554 = v1->timer;
  int * v555 = v1->reg_ready;
  int v556 = v555[0];
  int v687 = v556 + ((v554 - v556) & (~((v554 - v556) >> 31)));
  v1->timer = v687;
  int v558 = v1->timer;
  int * v559 = v1->reg_ready;
  int v560 = v559[1];
  int v690 = v560 + ((v558 - v560) & (~((v558 - v560) >> 31)));
  v1->timer = v690;
  int v562 = v1->timer;
  int * v563 = v1->reg_ready;
  int v564 = v563[2];
  int v693 = v564 + ((v562 - v564) & (~((v562 - v564) >> 31)));
  v1->timer = v693;
  int v566 = v1->timer;
  int * v567 = v1->reg_ready;
  int v568 = v567[3];
  int v696 = v568 + ((v566 - v568) & (~((v566 - v568) >> 31)));
  v1->timer = v696;
  int v570 = v1->timer;
  int * v571 = v1->reg_ready;
  int v572 = v571[4];
  int v699 = v572 + ((v570 - v572) & (~((v570 - v572) >> 31)));
  v1->timer = v699;
  int v574 = v1->timer;
  int * v575 = v1->reg_ready;
  int v576 = v575[5];
  int v702 = v576 + ((v574 - v576) & (~((v574 - v576) >> 31)));
  v1->timer = v702;
  int v578 = v1->timer;
  int * v579 = v1->reg_ready;
  int v580 = v579[6];
  int v705 = v580 + ((v578 - v580) & (~((v578 - v580) >> 31)));
  v1->timer = v705;
  int v582 = v1->timer;
  int * v583 = v1->reg_ready;
  int v584 = v583[7];
  int v708 = v584 + ((v582 - v584) & (~((v582 - v584) >> 31)));
  v1->timer = v708;
  int v586 = v1->timer;
  int * v587 = v1->reg_ready;
  int v588 = v587[8];
  int v711 = v588 + ((v586 - v588) & (~((v586 - v588) >> 31)));
  v1->timer = v711;
  int v590 = v1->timer;
  int * v591 = v1->reg_ready;
  int v592 = v591[9];
  int v714 = v592 + ((v590 - v592) & (~((v590 - v592) >> 31)));
  v1->timer = v714;
  int v594 = v1->timer;
  int * v595 = v1->reg_ready;
  int v596 = v595[10];
  int v717 = v596 + ((v594 - v596) & (~((v594 - v596) >> 31)));
  v1->timer = v717;
  int v598 = v1->timer;
  int * v599 = v1->reg_ready;
  int v600 = v599[11];
  int v720 = v600 + ((v598 - v600) & (~((v598 - v600) >> 31)));
  v1->timer = v720;
  int v602 = v1->timer;
  int * v603 = v1->reg_ready;
  int v604 = v603[12];
  int v723 = v604 + ((v602 - v604) & (~((v602 - v604) >> 31)));
  v1->timer = v723;
  int v606 = v1->timer;
  int * v607 = v1->reg_ready;
  int v608 = v607[13];
  int v726 = v608 + ((v606 - v608) & (~((v606 - v608) >> 31)));
  v1->timer = v726;
  int v610 = v1->timer;
  int * v611 = v1->reg_ready;
  int v612 = v611[14];
  int v729 = v612 + ((v610 - v612) & (~((v610 - v612) >> 31)));
  v1->timer = v729;
  int v614 = v1->timer;
  int * v615 = v1->reg_ready;
  int v616 = v615[15];
  int v732 = v616 + ((v614 - v616) & (~((v614 - v616) >> 31)));
  v1->timer = v732;
  int v618 = v1->timer;
  int * v619 = v1->reg_ready;
  int v620 = v619[16];
  int v735 = v620 + ((v618 - v620) & (~((v618 - v620) >> 31)));
  v1->timer = v735;
  int v622 = v1->timer;
  int * v623 = v1->reg_ready;
  int v624 = v623[17];
  int v738 = v624 + ((v622 - v624) & (~((v622 - v624) >> 31)));
  v1->timer = v738;
  int v626 = v1->timer;
  int * v627 = v1->reg_ready;
  int v628 = v627[18];
  int v741 = v628 + ((v626 - v628) & (~((v626 - v628) >> 31)));
  v1->timer = v741;
  int v630 = v1->timer;
  int * v631 = v1->reg_ready;
  int v632 = v631[19];
  int v744 = v632 + ((v630 - v632) & (~((v630 - v632) >> 31)));
  v1->timer = v744;
  int v634 = v1->timer;
  int * v635 = v1->reg_ready;
  int v636 = v635[20];
  int v747 = v636 + ((v634 - v636) & (~((v634 - v636) >> 31)));
  v1->timer = v747;
  int v638 = v1->timer;
  int * v639 = v1->reg_ready;
  int v640 = v639[21];
  int v750 = v640 + ((v638 - v640) & (~((v638 - v640) >> 31)));
  v1->timer = v750;
  int v642 = v1->timer;
  int * v643 = v1->reg_ready;
  int v644 = v643[22];
  int v753 = v644 + ((v642 - v644) & (~((v642 - v644) >> 31)));
  v1->timer = v753;
  int v646 = v1->timer;
  int * v647 = v1->reg_ready;
  int v648 = v647[23];
  int v756 = v648 + ((v646 - v648) & (~((v646 - v648) >> 31)));
  v1->timer = v756;
  int v650 = v1->timer;
  int * v651 = v1->reg_ready;
  int v652 = v651[24];
  int v759 = v652 + ((v650 - v652) & (~((v650 - v652) >> 31)));
  v1->timer = v759;
  int v654 = v1->timer;
  int * v655 = v1->reg_ready;
  int v656 = v655[25];
  int v762 = v656 + ((v654 - v656) & (~((v654 - v656) >> 31)));
  v1->timer = v762;
  int v658 = v1->timer;
  int * v659 = v1->reg_ready;
  int v660 = v659[26];
  int v765 = v660 + ((v658 - v660) & (~((v658 - v660) >> 31)));
  v1->timer = v765;
  int v662 = v1->timer;
  int * v663 = v1->reg_ready;
  int v664 = v663[27];
  int v768 = v664 + ((v662 - v664) & (~((v662 - v664) >> 31)));
  v1->timer = v768;
  int v666 = v1->timer;
  int * v667 = v1->reg_ready;
  int v668 = v667[28];
  int v771 = v668 + ((v666 - v668) & (~((v666 - v668) >> 31)));
  v1->timer = v771;
  int v670 = v1->timer;
  int * v671 = v1->reg_ready;
  int v672 = v671[29];
  int v774 = v672 + ((v670 - v672) & (~((v670 - v672) >> 31)));
  v1->timer = v774;
  int v674 = v1->timer;
  int * v675 = v1->reg_ready;
  int v676 = v675[30];
  int v777 = v676 + ((v674 - v676) & (~((v674 - v676) >> 31)));
  v1->timer = v777;
  int v678 = v1->timer;
  int * v679 = v1->reg_ready;
  int v680 = v679[31];
  int v780 = v680 + ((v678 - v680) & (~((v678 - v680) >> 31)));
  v1->timer = v780;
  return v1;
}

struct StateT * slot_1(struct StateT * v23) {
  int v24 = v23->timer;
  int v25 = v23->timer;
  int v160 = v25 + 1;
  v23->timer = v160;
  int * v27 = v23->reg_ready;
  int v28 = v27[10];
  int * v29 = v23->regs;
  int v30 = v29[10];
  int * v31 = v23->cache_tags;
  int v165 = (((int)((unsigned int)((int)((unsigned int)v30 >> 2)) >> 1)) & 1) * 2;
  int v32 = v31[v165];
  int * v33 = v23->cache_tags;
  int v167 = ((((int)((unsigned int)((int)((unsigned int)v30 >> 2)) >> 1)) & 1) * 2) + 1;
  int v34 = v33[v167];
  int * v35 = v23->cache_tags;
  int v169 = 4 + ((((int)((unsigned int)((int)((unsigned int)v30 >> 2)) >> 1)) & 3) * 2);
  int v36 = v35[v169];
  int * v37 = v23->cache_tags;
  int v171 = (4 + ((((int)((unsigned int)((int)((unsigned int)v30 >> 2)) >> 1)) & 3) * 2)) + 1;
  int v38 = v37[v171];
  int * v39 = v23->cache_vals;
  bool v172 = !(((~(((v32 ^ ((int)((unsigned int)((int)((unsigned int)v30 >> 2)) >> 1))) | (-(v32 ^ ((int)((unsigned int)((int)((unsigned int)v30 >> 2)) >> 1))))) >> 31)) | (~(((v34 ^ ((int)((unsigned int)((int)((unsigned int)v30 >> 2)) >> 1))) | (-(v34 ^ ((int)((unsigned int)((int)((unsigned int)v30 >> 2)) >> 1))))) >> 31))) == 0);
  int v152;
  if (v172) {
    int * v40 = v23->cache_age;
    int v174 = ((((int)((unsigned int)((int)((unsigned int)v30 >> 2)) >> 1)) & 1) * 2) + ((~(((v34 ^ ((int)((unsigned int)((int)((unsigned int)v30 >> 2)) >> 1))) | (-(v34 ^ ((int)((unsigned int)((int)((unsigned int)v30 >> 2)) >> 1))))) >> 31)) & 1);
    int v41 = v40[v174];
    int * v42 = v23->cache_age;
    int v43 = v42[v165];
    int * v44 = v23->cache_age;
    int v177 = v43 + ((int)((unsigned int)(v43 - v41) >> 31));
    v44[v165] = v177;
    int * v46 = v23->cache_age;
    int v47 = v46[v167];
    int * v48 = v23->cache_age;
    int v180 = v47 + ((int)((unsigned int)(v47 - v41) >> 31));
    v48[v167] = v180;
    int * v50 = v23->cache_age;
    v50[v174] = 0;
    v152 = v174;
  } else {
    int * v53 = v23->cache_age;
    int v184 = (((int)((unsigned int)((int)((unsigned int)v30 >> 2)) >> 1)) & 1) * 2;
    int v54 = v53[v184];
    int * v55 = v23->cache_tags;
    int v56 = v55[v184];
    int * v57 = v23->cache_age;
    int v58 = v57[v167];
    int * v59 = v23->cache_tags;
    int v60 = v59[v167];
    bool v188 = !(((~(((v36 ^ ((int)((unsigned int)((int)((unsigned int)v30 >> 2)) >> 1))) | (-(v36 ^ ((int)((unsigned int)((int)((unsigned int)v30 >> 2)) >> 1))))) >> 31)) | (~(((v38 ^ ((int)((unsigned int)((int)((unsigned int)v30 >> 2)) >> 1))) | (-(v38 ^ ((int)((unsigned int)((int)((unsigned int)v30 >> 2)) >> 1))))) >> 31))) == 0);
    int v124;
    if (v188) {
      int * v61 = v23->cache_age;
      int v190 = (4 + ((((int)((unsigned int)((int)((unsigned int)v30 >> 2)) >> 1)) & 3) * 2)) + ((~(((v38 ^ ((int)((unsigned int)((int)((unsigned int)v30 >> 2)) >> 1))) | (-(v38 ^ ((int)((unsigned int)((int)((unsigned int)v30 >> 2)) >> 1))))) >> 31)) & 1);
      int v62 = v61[v190];
      int * v63 = v23->cache_age;
      int v64 = v63[v169];
      int * v65 = v23->cache_age;
      int v193 = v64 + ((int)((unsigned int)(v64 - v62) >> 31));
      v65[v169] = v193;
      int * v67 = v23->cache_age;
      int v68 = v67[v171];
      int * v69 = v23->cache_age;
      int v196 = v68 + ((int)((unsigned int)(v68 - v62) >> 31));
      v69[v171] = v196;
      int * v71 = v23->cache_age;
      v71[v190] = 0;
      v124 = v190;
    } else {
      int * v74 = v23->cache_age;
      int v200 = 4 + ((((int)((unsigned int)((int)((unsigned int)v30 >> 2)) >> 1)) & 3) * 2);
      int v75 = v74[v200];
      int * v76 = v23->cache_tags;
      int v77 = v76[v200];
      int * v78 = v23->cache_age;
      int v79 = v78[v171];
      int * v80 = v23->cache_tags;
      int v81 = v80[v171];
      int * v82 = v23->cache_dirty;
      int v205 = (4 + ((((int)((unsigned int)((int)((unsigned int)v30 >> 2)) >> 1)) & 3) * 2)) + ((((v75 + ((~(((v77 ^ -1) | (-(v77 ^ -1))) >> 31)) & 2)) - (v79 + ((~(((v81 ^ -1) | (-(v81 ^ -1))) >> 31)) & 2))) >> 31) & 1);
      int v83 = v82[v205];
      bool v206 = !(v83 == 0);
      if (v206) {
        int * v84 = v23->cache_tags;
        int v85 = v84[v205];
        int * v86 = v23->cache_vals;
        int v209 = ((4 + ((((int)((unsigned int)((int)((unsigned int)v30 >> 2)) >> 1)) & 3) * 2)) + ((((v75 + ((~(((v77 ^ -1) | (-(v77 ^ -1))) >> 31)) & 2)) - (v79 + ((~(((v81 ^ -1) | (-(v81 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
        int v87 = v86[v209];
        int * v88 = v23->cache_vals;
        int v211 = (((4 + ((((int)((unsigned int)((int)((unsigned int)v30 >> 2)) >> 1)) & 3) * 2)) + ((((v75 + ((~(((v77 ^ -1) | (-(v77 ^ -1))) >> 31)) & 2)) - (v79 + ((~(((v81 ^ -1) | (-(v81 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
        int v89 = v88[v211];
        int * v90 = v23->mem;
        int v213 = v85 * 2;
        v90[v213] = v87;
        int * v92 = v23->mem;
        int v216 = (v85 * 2) + 1;
        v92[v216] = v89;
        ;
      } else {
        ;
      }
      int * v97 = v23->mem;
      int v221 = ((int)((unsigned int)((int)((unsigned int)v30 >> 2)) >> 1)) * 2;
      int v98 = v97[v221];
      int * v99 = v23->mem;
      int v223 = (((int)((unsigned int)((int)((unsigned int)v30 >> 2)) >> 1)) * 2) + 1;
      int v100 = v99[v223];
      int * v101 = v23->cache_vals;
      int v225 = ((4 + ((((int)((unsigned int)((int)((unsigned int)v30 >> 2)) >> 1)) & 3) * 2)) + ((((v75 + ((~(((v77 ^ -1) | (-(v77 ^ -1))) >> 31)) & 2)) - (v79 + ((~(((v81 ^ -1) | (-(v81 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
      v101[v225] = v98;
      int * v103 = v23->cache_vals;
      int v228 = (((4 + ((((int)((unsigned int)((int)((unsigned int)v30 >> 2)) >> 1)) & 3) * 2)) + ((((v75 + ((~(((v77 ^ -1) | (-(v77 ^ -1))) >> 31)) & 2)) - (v79 + ((~(((v81 ^ -1) | (-(v81 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
      v103[v228] = v100;
      int * v105 = v23->cache_tags;
      int v231 = (int)((unsigned int)((int)((unsigned int)v30 >> 2)) >> 1);
      v105[v205] = v231;
      int * v107 = v23->cache_dirty;
      v107[v205] = 0;
      int * v109 = v23->cache_age;
      v109[v205] = 1;
      int * v111 = v23->cache_age;
      int v112 = v111[v205];
      int * v113 = v23->cache_age;
      int v114 = v113[v169];
      int * v115 = v23->cache_age;
      int v239 = v114 + ((int)((unsigned int)(v114 - v112) >> 31));
      v115[v169] = v239;
      int * v117 = v23->cache_age;
      int v118 = v117[v171];
      int * v119 = v23->cache_age;
      int v242 = v118 + ((int)((unsigned int)(v118 - v112) >> 31));
      v119[v171] = v242;
      int * v121 = v23->cache_age;
      v121[v205] = 0;
      v124 = v205;
    }
    int * v125 = v23->cache_vals;
    int v245 = v124 * 2;
    int v126 = v125[v245];
    int * v127 = v23->cache_vals;
    int v247 = (v124 * 2) + 1;
    int v128 = v127[v247];
    int * v129 = v23->cache_vals;
    int v249 = (((((int)((unsigned int)((int)((unsigned int)v30 >> 2)) >> 1)) & 1) * 2) + ((((v54 + ((~(((v56 ^ -1) | (-(v56 ^ -1))) >> 31)) & 2)) - (v58 + ((~(((v60 ^ -1) | (-(v60 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
    v129[v249] = v126;
    int * v131 = v23->cache_vals;
    int v252 = ((((((int)((unsigned int)((int)((unsigned int)v30 >> 2)) >> 1)) & 1) * 2) + ((((v54 + ((~(((v56 ^ -1) | (-(v56 ^ -1))) >> 31)) & 2)) - (v58 + ((~(((v60 ^ -1) | (-(v60 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
    v131[v252] = v128;
    int * v133 = v23->cache_tags;
    int v255 = ((((int)((unsigned int)((int)((unsigned int)v30 >> 2)) >> 1)) & 1) * 2) + ((((v54 + ((~(((v56 ^ -1) | (-(v56 ^ -1))) >> 31)) & 2)) - (v58 + ((~(((v60 ^ -1) | (-(v60 ^ -1))) >> 31)) & 2))) >> 31) & 1);
    int v256 = (int)((unsigned int)((int)((unsigned int)v30 >> 2)) >> 1);
    v133[v255] = v256;
    int * v135 = v23->cache_dirty;
    v135[v255] = 0;
    int * v137 = v23->cache_age;
    v137[v255] = 1;
    int * v139 = v23->cache_age;
    int v140 = v139[v255];
    int * v141 = v23->cache_age;
    int v142 = v141[v165];
    int * v143 = v23->cache_age;
    int v264 = v142 + ((int)((unsigned int)(v142 - v140) >> 31));
    v143[v165] = v264;
    int * v145 = v23->cache_age;
    int v146 = v145[v167];
    int * v147 = v23->cache_age;
    int v267 = v146 + ((int)((unsigned int)(v146 - v140) >> 31));
    v147[v167] = v267;
    int * v149 = v23->cache_age;
    v149[v255] = 0;
    v152 = v255;
  }
  int v270 = (v152 * 2) + (((int)((unsigned int)v30 >> 2)) & 1);
  int v153 = v39[v270];
  int * v154 = v23->reg_ready;
  int v273 = ((v28 + ((v24 - v28) & (~((v24 - v28) >> 31)))) + 1) + ((100 ^ (((~(((v36 ^ ((int)((unsigned int)((int)((unsigned int)v30 >> 2)) >> 1))) | (-(v36 ^ ((int)((unsigned int)((int)((unsigned int)v30 >> 2)) >> 1))))) >> 31)) | (~(((v38 ^ ((int)((unsigned int)((int)((unsigned int)v30 >> 2)) >> 1))) | (-(v38 ^ ((int)((unsigned int)((int)((unsigned int)v30 >> 2)) >> 1))))) >> 31))) & 104)) ^ (((~(((v32 ^ ((int)((unsigned int)((int)((unsigned int)v30 >> 2)) >> 1))) | (-(v32 ^ ((int)((unsigned int)((int)((unsigned int)v30 >> 2)) >> 1))))) >> 31)) | (~(((v34 ^ ((int)((unsigned int)((int)((unsigned int)v30 >> 2)) >> 1))) | (-(v34 ^ ((int)((unsigned int)((int)((unsigned int)v30 >> 2)) >> 1))))) >> 31))) & (1 ^ (100 ^ (((~(((v36 ^ ((int)((unsigned int)((int)((unsigned int)v30 >> 2)) >> 1))) | (-(v36 ^ ((int)((unsigned int)((int)((unsigned int)v30 >> 2)) >> 1))))) >> 31)) | (~(((v38 ^ ((int)((unsigned int)((int)((unsigned int)v30 >> 2)) >> 1))) | (-(v38 ^ ((int)((unsigned int)((int)((unsigned int)v30 >> 2)) >> 1))))) >> 31))) & 104)))));
  v154[11] = v273;
  int * v156 = v23->regs;
  v156[11] = v153;
  struct StateT * v158 = slot_2(v23);
  return v158;
}

struct StateT * slot_2(struct StateT * v278) {
  int v279 = v278->timer;
  int v280 = v278->timer;
  int v292 = v280 + 1;
  v278->timer = v292;
  int * v282 = v278->reg_ready;
  int v283 = v282[11];
  int * v284 = v278->regs;
  int v285 = v284[11];
  int * v286 = v278->reg_ready;
  int v297 = (v283 + ((v279 - v283) & (~((v279 - v283) >> 31)))) + 1;
  v286[11] = v297;
  int * v288 = v278->regs;
  int v299 = v285 << 2;
  v288[11] = v299;
  struct StateT * v290 = slot_3(v278);
  return v290;
}

struct StateT * slot_3(struct StateT * v302) {
  int v303 = v302->timer;
  int v304 = v302->timer;
  int v438 = v304 + 1;
  v302->timer = v438;
  int * v306 = v302->reg_ready;
  int v307 = v306[11];
  int * v308 = v302->regs;
  int v309 = v308[11];
  int * v310 = v302->cache_tags;
  int v443 = (((int)((unsigned int)((int)((unsigned int)(v309 + 16) >> 2)) >> 1)) & 1) * 2;
  int v311 = v310[v443];
  int * v312 = v302->cache_tags;
  int v445 = ((((int)((unsigned int)((int)((unsigned int)(v309 + 16) >> 2)) >> 1)) & 1) * 2) + 1;
  int v313 = v312[v445];
  int * v314 = v302->cache_tags;
  int v447 = 4 + ((((int)((unsigned int)((int)((unsigned int)(v309 + 16) >> 2)) >> 1)) & 3) * 2);
  int v315 = v314[v447];
  int * v316 = v302->cache_tags;
  int v449 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v309 + 16) >> 2)) >> 1)) & 3) * 2)) + 1;
  int v317 = v316[v449];
  int * v318 = v302->cache_vals;
  bool v450 = !(((~(((v311 ^ ((int)((unsigned int)((int)((unsigned int)(v309 + 16) >> 2)) >> 1))) | (-(v311 ^ ((int)((unsigned int)((int)((unsigned int)(v309 + 16) >> 2)) >> 1))))) >> 31)) | (~(((v313 ^ ((int)((unsigned int)((int)((unsigned int)(v309 + 16) >> 2)) >> 1))) | (-(v313 ^ ((int)((unsigned int)((int)((unsigned int)(v309 + 16) >> 2)) >> 1))))) >> 31))) == 0);
  int v431;
  if (v450) {
    int * v319 = v302->cache_age;
    int v452 = ((((int)((unsigned int)((int)((unsigned int)(v309 + 16) >> 2)) >> 1)) & 1) * 2) + ((~(((v313 ^ ((int)((unsigned int)((int)((unsigned int)(v309 + 16) >> 2)) >> 1))) | (-(v313 ^ ((int)((unsigned int)((int)((unsigned int)(v309 + 16) >> 2)) >> 1))))) >> 31)) & 1);
    int v320 = v319[v452];
    int * v321 = v302->cache_age;
    int v322 = v321[v443];
    int * v323 = v302->cache_age;
    int v455 = v322 + ((int)((unsigned int)(v322 - v320) >> 31));
    v323[v443] = v455;
    int * v325 = v302->cache_age;
    int v326 = v325[v445];
    int * v327 = v302->cache_age;
    int v458 = v326 + ((int)((unsigned int)(v326 - v320) >> 31));
    v327[v445] = v458;
    int * v329 = v302->cache_age;
    v329[v452] = 0;
    v431 = v452;
  } else {
    int * v332 = v302->cache_age;
    int v462 = (((int)((unsigned int)((int)((unsigned int)(v309 + 16) >> 2)) >> 1)) & 1) * 2;
    int v333 = v332[v462];
    int * v334 = v302->cache_tags;
    int v335 = v334[v462];
    int * v336 = v302->cache_age;
    int v337 = v336[v445];
    int * v338 = v302->cache_tags;
    int v339 = v338[v445];
    bool v466 = !(((~(((v315 ^ ((int)((unsigned int)((int)((unsigned int)(v309 + 16) >> 2)) >> 1))) | (-(v315 ^ ((int)((unsigned int)((int)((unsigned int)(v309 + 16) >> 2)) >> 1))))) >> 31)) | (~(((v317 ^ ((int)((unsigned int)((int)((unsigned int)(v309 + 16) >> 2)) >> 1))) | (-(v317 ^ ((int)((unsigned int)((int)((unsigned int)(v309 + 16) >> 2)) >> 1))))) >> 31))) == 0);
    int v403;
    if (v466) {
      int * v340 = v302->cache_age;
      int v468 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v309 + 16) >> 2)) >> 1)) & 3) * 2)) + ((~(((v317 ^ ((int)((unsigned int)((int)((unsigned int)(v309 + 16) >> 2)) >> 1))) | (-(v317 ^ ((int)((unsigned int)((int)((unsigned int)(v309 + 16) >> 2)) >> 1))))) >> 31)) & 1);
      int v341 = v340[v468];
      int * v342 = v302->cache_age;
      int v343 = v342[v447];
      int * v344 = v302->cache_age;
      int v471 = v343 + ((int)((unsigned int)(v343 - v341) >> 31));
      v344[v447] = v471;
      int * v346 = v302->cache_age;
      int v347 = v346[v449];
      int * v348 = v302->cache_age;
      int v474 = v347 + ((int)((unsigned int)(v347 - v341) >> 31));
      v348[v449] = v474;
      int * v350 = v302->cache_age;
      v350[v468] = 0;
      v403 = v468;
    } else {
      int * v353 = v302->cache_age;
      int v478 = 4 + ((((int)((unsigned int)((int)((unsigned int)(v309 + 16) >> 2)) >> 1)) & 3) * 2);
      int v354 = v353[v478];
      int * v355 = v302->cache_tags;
      int v356 = v355[v478];
      int * v357 = v302->cache_age;
      int v358 = v357[v449];
      int * v359 = v302->cache_tags;
      int v360 = v359[v449];
      int * v361 = v302->cache_dirty;
      int v483 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v309 + 16) >> 2)) >> 1)) & 3) * 2)) + ((((v354 + ((~(((v356 ^ -1) | (-(v356 ^ -1))) >> 31)) & 2)) - (v358 + ((~(((v360 ^ -1) | (-(v360 ^ -1))) >> 31)) & 2))) >> 31) & 1);
      int v362 = v361[v483];
      bool v484 = !(v362 == 0);
      if (v484) {
        int * v363 = v302->cache_tags;
        int v364 = v363[v483];
        int * v365 = v302->cache_vals;
        int v487 = ((4 + ((((int)((unsigned int)((int)((unsigned int)(v309 + 16) >> 2)) >> 1)) & 3) * 2)) + ((((v354 + ((~(((v356 ^ -1) | (-(v356 ^ -1))) >> 31)) & 2)) - (v358 + ((~(((v360 ^ -1) | (-(v360 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
        int v366 = v365[v487];
        int * v367 = v302->cache_vals;
        int v489 = (((4 + ((((int)((unsigned int)((int)((unsigned int)(v309 + 16) >> 2)) >> 1)) & 3) * 2)) + ((((v354 + ((~(((v356 ^ -1) | (-(v356 ^ -1))) >> 31)) & 2)) - (v358 + ((~(((v360 ^ -1) | (-(v360 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
        int v368 = v367[v489];
        int * v369 = v302->mem;
        int v491 = v364 * 2;
        v369[v491] = v366;
        int * v371 = v302->mem;
        int v494 = (v364 * 2) + 1;
        v371[v494] = v368;
        ;
      } else {
        ;
      }
      int * v376 = v302->mem;
      int v499 = ((int)((unsigned int)((int)((unsigned int)(v309 + 16) >> 2)) >> 1)) * 2;
      int v377 = v376[v499];
      int * v378 = v302->mem;
      int v501 = (((int)((unsigned int)((int)((unsigned int)(v309 + 16) >> 2)) >> 1)) * 2) + 1;
      int v379 = v378[v501];
      int * v380 = v302->cache_vals;
      int v503 = ((4 + ((((int)((unsigned int)((int)((unsigned int)(v309 + 16) >> 2)) >> 1)) & 3) * 2)) + ((((v354 + ((~(((v356 ^ -1) | (-(v356 ^ -1))) >> 31)) & 2)) - (v358 + ((~(((v360 ^ -1) | (-(v360 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
      v380[v503] = v377;
      int * v382 = v302->cache_vals;
      int v506 = (((4 + ((((int)((unsigned int)((int)((unsigned int)(v309 + 16) >> 2)) >> 1)) & 3) * 2)) + ((((v354 + ((~(((v356 ^ -1) | (-(v356 ^ -1))) >> 31)) & 2)) - (v358 + ((~(((v360 ^ -1) | (-(v360 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
      v382[v506] = v379;
      int * v384 = v302->cache_tags;
      int v509 = (int)((unsigned int)((int)((unsigned int)(v309 + 16) >> 2)) >> 1);
      v384[v483] = v509;
      int * v386 = v302->cache_dirty;
      v386[v483] = 0;
      int * v388 = v302->cache_age;
      v388[v483] = 1;
      int * v390 = v302->cache_age;
      int v391 = v390[v483];
      int * v392 = v302->cache_age;
      int v393 = v392[v447];
      int * v394 = v302->cache_age;
      int v517 = v393 + ((int)((unsigned int)(v393 - v391) >> 31));
      v394[v447] = v517;
      int * v396 = v302->cache_age;
      int v397 = v396[v449];
      int * v398 = v302->cache_age;
      int v520 = v397 + ((int)((unsigned int)(v397 - v391) >> 31));
      v398[v449] = v520;
      int * v400 = v302->cache_age;
      v400[v483] = 0;
      v403 = v483;
    }
    int * v404 = v302->cache_vals;
    int v523 = v403 * 2;
    int v405 = v404[v523];
    int * v406 = v302->cache_vals;
    int v525 = (v403 * 2) + 1;
    int v407 = v406[v525];
    int * v408 = v302->cache_vals;
    int v527 = (((((int)((unsigned int)((int)((unsigned int)(v309 + 16) >> 2)) >> 1)) & 1) * 2) + ((((v333 + ((~(((v335 ^ -1) | (-(v335 ^ -1))) >> 31)) & 2)) - (v337 + ((~(((v339 ^ -1) | (-(v339 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
    v408[v527] = v405;
    int * v410 = v302->cache_vals;
    int v530 = ((((((int)((unsigned int)((int)((unsigned int)(v309 + 16) >> 2)) >> 1)) & 1) * 2) + ((((v333 + ((~(((v335 ^ -1) | (-(v335 ^ -1))) >> 31)) & 2)) - (v337 + ((~(((v339 ^ -1) | (-(v339 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
    v410[v530] = v407;
    int * v412 = v302->cache_tags;
    int v533 = ((((int)((unsigned int)((int)((unsigned int)(v309 + 16) >> 2)) >> 1)) & 1) * 2) + ((((v333 + ((~(((v335 ^ -1) | (-(v335 ^ -1))) >> 31)) & 2)) - (v337 + ((~(((v339 ^ -1) | (-(v339 ^ -1))) >> 31)) & 2))) >> 31) & 1);
    int v534 = (int)((unsigned int)((int)((unsigned int)(v309 + 16) >> 2)) >> 1);
    v412[v533] = v534;
    int * v414 = v302->cache_dirty;
    v414[v533] = 0;
    int * v416 = v302->cache_age;
    v416[v533] = 1;
    int * v418 = v302->cache_age;
    int v419 = v418[v533];
    int * v420 = v302->cache_age;
    int v421 = v420[v443];
    int * v422 = v302->cache_age;
    int v542 = v421 + ((int)((unsigned int)(v421 - v419) >> 31));
    v422[v443] = v542;
    int * v424 = v302->cache_age;
    int v425 = v424[v445];
    int * v426 = v302->cache_age;
    int v545 = v425 + ((int)((unsigned int)(v425 - v419) >> 31));
    v426[v445] = v545;
    int * v428 = v302->cache_age;
    v428[v533] = 0;
    v431 = v533;
  }
  int v548 = (v431 * 2) + (((int)((unsigned int)(v309 + 16) >> 2)) & 1);
  int v432 = v318[v548];
  int * v433 = v302->reg_ready;
  int v551 = ((v307 + ((v303 - v307) & (~((v303 - v307) >> 31)))) + 1) + ((100 ^ (((~(((v315 ^ ((int)((unsigned int)((int)((unsigned int)(v309 + 16) >> 2)) >> 1))) | (-(v315 ^ ((int)((unsigned int)((int)((unsigned int)(v309 + 16) >> 2)) >> 1))))) >> 31)) | (~(((v317 ^ ((int)((unsigned int)((int)((unsigned int)(v309 + 16) >> 2)) >> 1))) | (-(v317 ^ ((int)((unsigned int)((int)((unsigned int)(v309 + 16) >> 2)) >> 1))))) >> 31))) & 104)) ^ (((~(((v311 ^ ((int)((unsigned int)((int)((unsigned int)(v309 + 16) >> 2)) >> 1))) | (-(v311 ^ ((int)((unsigned int)((int)((unsigned int)(v309 + 16) >> 2)) >> 1))))) >> 31)) | (~(((v313 ^ ((int)((unsigned int)((int)((unsigned int)(v309 + 16) >> 2)) >> 1))) | (-(v313 ^ ((int)((unsigned int)((int)((unsigned int)(v309 + 16) >> 2)) >> 1))))) >> 31))) & (1 ^ (100 ^ (((~(((v315 ^ ((int)((unsigned int)((int)((unsigned int)(v309 + 16) >> 2)) >> 1))) | (-(v315 ^ ((int)((unsigned int)((int)((unsigned int)(v309 + 16) >> 2)) >> 1))))) >> 31)) | (~(((v317 ^ ((int)((unsigned int)((int)((unsigned int)(v309 + 16) >> 2)) >> 1))) | (-(v317 ^ ((int)((unsigned int)((int)((unsigned int)(v309 + 16) >> 2)) >> 1))))) >> 31))) & 104)))));
  v433[12] = v551;
  int * v435 = v302->regs;
  v435[12] = v432;
  return v302;
}

struct StateT * slot_0(struct StateT * v2) {
  int v3 = v2->timer;
  int v4 = v2->timer;
  int v15 = v4 + 1;
  v2->timer = v15;
  int * v6 = v2->reg_ready;
  int v7 = v6[10];
  int * v8 = v2->regs;
  int v9 = v8[10];
  bool v19 = v9 == 0;
  struct StateT * v13;
  if (v19) {
    v13 = v2;
  } else {
    struct StateT * v11 = slot_1(v2);
    v13 = v11;
  }
  return v13;
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