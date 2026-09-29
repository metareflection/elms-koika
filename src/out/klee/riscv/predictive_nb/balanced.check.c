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
struct StateT * slot_1(struct StateT * v20);
struct StateT * slot_8(struct StateT * v572);
struct StateT * slot_6(struct StateT * v548);
struct StateT * slot_5(struct StateT * v327);
struct StateT * slot_4(struct StateT * v302);
struct StateT * slot_2(struct StateT * v275);
struct StateT * slot_7(struct StateT * v566);
struct StateT * slot_3(struct StateT * v293);
struct StateT * slot_0(struct StateT * v2);
struct StateT * snippet(struct StateT * v0) {
  struct StateT * v1 = slot_0(v0);
  int v578 = v1->timer;
  int * v579 = v1->reg_ready;
  int v580 = v579[0];
  int v711 = v580 + ((v578 - v580) & (~((v578 - v580) >> 31)));
  v1->timer = v711;
  int v582 = v1->timer;
  int * v583 = v1->reg_ready;
  int v584 = v583[1];
  int v714 = v584 + ((v582 - v584) & (~((v582 - v584) >> 31)));
  v1->timer = v714;
  int v586 = v1->timer;
  int * v587 = v1->reg_ready;
  int v588 = v587[2];
  int v717 = v588 + ((v586 - v588) & (~((v586 - v588) >> 31)));
  v1->timer = v717;
  int v590 = v1->timer;
  int * v591 = v1->reg_ready;
  int v592 = v591[3];
  int v720 = v592 + ((v590 - v592) & (~((v590 - v592) >> 31)));
  v1->timer = v720;
  int v594 = v1->timer;
  int * v595 = v1->reg_ready;
  int v596 = v595[4];
  int v723 = v596 + ((v594 - v596) & (~((v594 - v596) >> 31)));
  v1->timer = v723;
  int v598 = v1->timer;
  int * v599 = v1->reg_ready;
  int v600 = v599[5];
  int v726 = v600 + ((v598 - v600) & (~((v598 - v600) >> 31)));
  v1->timer = v726;
  int v602 = v1->timer;
  int * v603 = v1->reg_ready;
  int v604 = v603[6];
  int v729 = v604 + ((v602 - v604) & (~((v602 - v604) >> 31)));
  v1->timer = v729;
  int v606 = v1->timer;
  int * v607 = v1->reg_ready;
  int v608 = v607[7];
  int v732 = v608 + ((v606 - v608) & (~((v606 - v608) >> 31)));
  v1->timer = v732;
  int v610 = v1->timer;
  int * v611 = v1->reg_ready;
  int v612 = v611[8];
  int v735 = v612 + ((v610 - v612) & (~((v610 - v612) >> 31)));
  v1->timer = v735;
  int v614 = v1->timer;
  int * v615 = v1->reg_ready;
  int v616 = v615[9];
  int v738 = v616 + ((v614 - v616) & (~((v614 - v616) >> 31)));
  v1->timer = v738;
  int v618 = v1->timer;
  int * v619 = v1->reg_ready;
  int v620 = v619[10];
  int v741 = v620 + ((v618 - v620) & (~((v618 - v620) >> 31)));
  v1->timer = v741;
  int v622 = v1->timer;
  int * v623 = v1->reg_ready;
  int v624 = v623[11];
  int v744 = v624 + ((v622 - v624) & (~((v622 - v624) >> 31)));
  v1->timer = v744;
  int v626 = v1->timer;
  int * v627 = v1->reg_ready;
  int v628 = v627[12];
  int v747 = v628 + ((v626 - v628) & (~((v626 - v628) >> 31)));
  v1->timer = v747;
  int v630 = v1->timer;
  int * v631 = v1->reg_ready;
  int v632 = v631[13];
  int v750 = v632 + ((v630 - v632) & (~((v630 - v632) >> 31)));
  v1->timer = v750;
  int v634 = v1->timer;
  int * v635 = v1->reg_ready;
  int v636 = v635[14];
  int v753 = v636 + ((v634 - v636) & (~((v634 - v636) >> 31)));
  v1->timer = v753;
  int v638 = v1->timer;
  int * v639 = v1->reg_ready;
  int v640 = v639[15];
  int v756 = v640 + ((v638 - v640) & (~((v638 - v640) >> 31)));
  v1->timer = v756;
  int v642 = v1->timer;
  int * v643 = v1->reg_ready;
  int v644 = v643[16];
  int v759 = v644 + ((v642 - v644) & (~((v642 - v644) >> 31)));
  v1->timer = v759;
  int v646 = v1->timer;
  int * v647 = v1->reg_ready;
  int v648 = v647[17];
  int v762 = v648 + ((v646 - v648) & (~((v646 - v648) >> 31)));
  v1->timer = v762;
  int v650 = v1->timer;
  int * v651 = v1->reg_ready;
  int v652 = v651[18];
  int v765 = v652 + ((v650 - v652) & (~((v650 - v652) >> 31)));
  v1->timer = v765;
  int v654 = v1->timer;
  int * v655 = v1->reg_ready;
  int v656 = v655[19];
  int v768 = v656 + ((v654 - v656) & (~((v654 - v656) >> 31)));
  v1->timer = v768;
  int v658 = v1->timer;
  int * v659 = v1->reg_ready;
  int v660 = v659[20];
  int v771 = v660 + ((v658 - v660) & (~((v658 - v660) >> 31)));
  v1->timer = v771;
  int v662 = v1->timer;
  int * v663 = v1->reg_ready;
  int v664 = v663[21];
  int v774 = v664 + ((v662 - v664) & (~((v662 - v664) >> 31)));
  v1->timer = v774;
  int v666 = v1->timer;
  int * v667 = v1->reg_ready;
  int v668 = v667[22];
  int v777 = v668 + ((v666 - v668) & (~((v666 - v668) >> 31)));
  v1->timer = v777;
  int v670 = v1->timer;
  int * v671 = v1->reg_ready;
  int v672 = v671[23];
  int v780 = v672 + ((v670 - v672) & (~((v670 - v672) >> 31)));
  v1->timer = v780;
  int v674 = v1->timer;
  int * v675 = v1->reg_ready;
  int v676 = v675[24];
  int v783 = v676 + ((v674 - v676) & (~((v674 - v676) >> 31)));
  v1->timer = v783;
  int v678 = v1->timer;
  int * v679 = v1->reg_ready;
  int v680 = v679[25];
  int v786 = v680 + ((v678 - v680) & (~((v678 - v680) >> 31)));
  v1->timer = v786;
  int v682 = v1->timer;
  int * v683 = v1->reg_ready;
  int v684 = v683[26];
  int v789 = v684 + ((v682 - v684) & (~((v682 - v684) >> 31)));
  v1->timer = v789;
  int v686 = v1->timer;
  int * v687 = v1->reg_ready;
  int v688 = v687[27];
  int v792 = v688 + ((v686 - v688) & (~((v686 - v688) >> 31)));
  v1->timer = v792;
  int v690 = v1->timer;
  int * v691 = v1->reg_ready;
  int v692 = v691[28];
  int v795 = v692 + ((v690 - v692) & (~((v690 - v692) >> 31)));
  v1->timer = v795;
  int v694 = v1->timer;
  int * v695 = v1->reg_ready;
  int v696 = v695[29];
  int v798 = v696 + ((v694 - v696) & (~((v694 - v696) >> 31)));
  v1->timer = v798;
  int v698 = v1->timer;
  int * v699 = v1->reg_ready;
  int v700 = v699[30];
  int v801 = v700 + ((v698 - v700) & (~((v698 - v700) >> 31)));
  v1->timer = v801;
  int v702 = v1->timer;
  int * v703 = v1->reg_ready;
  int v704 = v703[31];
  int v804 = v704 + ((v702 - v704) & (~((v702 - v704) >> 31)));
  v1->timer = v804;
  return v1;
}

struct StateT * slot_1(struct StateT * v20) {
  int v21 = v20->timer;
  int v22 = v20->timer;
  int v157 = v22 + 1;
  v20->timer = v157;
  int * v24 = v20->reg_ready;
  int v25 = v24[12];
  int * v26 = v20->regs;
  int v27 = v26[12];
  int * v28 = v20->cache_tags;
  int v162 = (((int)((unsigned int)((int)((unsigned int)v27 >> 2)) >> 1)) & 1) * 2;
  int v29 = v28[v162];
  int * v30 = v20->cache_tags;
  int v164 = ((((int)((unsigned int)((int)((unsigned int)v27 >> 2)) >> 1)) & 1) * 2) + 1;
  int v31 = v30[v164];
  int * v32 = v20->cache_tags;
  int v166 = 4 + ((((int)((unsigned int)((int)((unsigned int)v27 >> 2)) >> 1)) & 3) * 2);
  int v33 = v32[v166];
  int * v34 = v20->cache_tags;
  int v168 = (4 + ((((int)((unsigned int)((int)((unsigned int)v27 >> 2)) >> 1)) & 3) * 2)) + 1;
  int v35 = v34[v168];
  int * v36 = v20->cache_vals;
  bool v169 = !(((~(((v29 ^ ((int)((unsigned int)((int)((unsigned int)v27 >> 2)) >> 1))) | (-(v29 ^ ((int)((unsigned int)((int)((unsigned int)v27 >> 2)) >> 1))))) >> 31)) | (~(((v31 ^ ((int)((unsigned int)((int)((unsigned int)v27 >> 2)) >> 1))) | (-(v31 ^ ((int)((unsigned int)((int)((unsigned int)v27 >> 2)) >> 1))))) >> 31))) == 0);
  int v149;
  if (v169) {
    int * v37 = v20->cache_age;
    int v171 = ((((int)((unsigned int)((int)((unsigned int)v27 >> 2)) >> 1)) & 1) * 2) + ((~(((v31 ^ ((int)((unsigned int)((int)((unsigned int)v27 >> 2)) >> 1))) | (-(v31 ^ ((int)((unsigned int)((int)((unsigned int)v27 >> 2)) >> 1))))) >> 31)) & 1);
    int v38 = v37[v171];
    int * v39 = v20->cache_age;
    int v40 = v39[v162];
    int * v41 = v20->cache_age;
    int v174 = v40 + ((int)((unsigned int)(v40 - v38) >> 31));
    v41[v162] = v174;
    int * v43 = v20->cache_age;
    int v44 = v43[v164];
    int * v45 = v20->cache_age;
    int v177 = v44 + ((int)((unsigned int)(v44 - v38) >> 31));
    v45[v164] = v177;
    int * v47 = v20->cache_age;
    v47[v171] = 0;
    v149 = v171;
  } else {
    int * v50 = v20->cache_age;
    int v181 = (((int)((unsigned int)((int)((unsigned int)v27 >> 2)) >> 1)) & 1) * 2;
    int v51 = v50[v181];
    int * v52 = v20->cache_tags;
    int v53 = v52[v181];
    int * v54 = v20->cache_age;
    int v55 = v54[v164];
    int * v56 = v20->cache_tags;
    int v57 = v56[v164];
    bool v185 = !(((~(((v33 ^ ((int)((unsigned int)((int)((unsigned int)v27 >> 2)) >> 1))) | (-(v33 ^ ((int)((unsigned int)((int)((unsigned int)v27 >> 2)) >> 1))))) >> 31)) | (~(((v35 ^ ((int)((unsigned int)((int)((unsigned int)v27 >> 2)) >> 1))) | (-(v35 ^ ((int)((unsigned int)((int)((unsigned int)v27 >> 2)) >> 1))))) >> 31))) == 0);
    int v121;
    if (v185) {
      int * v58 = v20->cache_age;
      int v187 = (4 + ((((int)((unsigned int)((int)((unsigned int)v27 >> 2)) >> 1)) & 3) * 2)) + ((~(((v35 ^ ((int)((unsigned int)((int)((unsigned int)v27 >> 2)) >> 1))) | (-(v35 ^ ((int)((unsigned int)((int)((unsigned int)v27 >> 2)) >> 1))))) >> 31)) & 1);
      int v59 = v58[v187];
      int * v60 = v20->cache_age;
      int v61 = v60[v166];
      int * v62 = v20->cache_age;
      int v190 = v61 + ((int)((unsigned int)(v61 - v59) >> 31));
      v62[v166] = v190;
      int * v64 = v20->cache_age;
      int v65 = v64[v168];
      int * v66 = v20->cache_age;
      int v193 = v65 + ((int)((unsigned int)(v65 - v59) >> 31));
      v66[v168] = v193;
      int * v68 = v20->cache_age;
      v68[v187] = 0;
      v121 = v187;
    } else {
      int * v71 = v20->cache_age;
      int v197 = 4 + ((((int)((unsigned int)((int)((unsigned int)v27 >> 2)) >> 1)) & 3) * 2);
      int v72 = v71[v197];
      int * v73 = v20->cache_tags;
      int v74 = v73[v197];
      int * v75 = v20->cache_age;
      int v76 = v75[v168];
      int * v77 = v20->cache_tags;
      int v78 = v77[v168];
      int * v79 = v20->cache_dirty;
      int v202 = (4 + ((((int)((unsigned int)((int)((unsigned int)v27 >> 2)) >> 1)) & 3) * 2)) + ((((v72 + ((~(((v74 ^ -1) | (-(v74 ^ -1))) >> 31)) & 2)) - (v76 + ((~(((v78 ^ -1) | (-(v78 ^ -1))) >> 31)) & 2))) >> 31) & 1);
      int v80 = v79[v202];
      bool v203 = !(v80 == 0);
      if (v203) {
        int * v81 = v20->cache_tags;
        int v82 = v81[v202];
        int * v83 = v20->cache_vals;
        int v206 = ((4 + ((((int)((unsigned int)((int)((unsigned int)v27 >> 2)) >> 1)) & 3) * 2)) + ((((v72 + ((~(((v74 ^ -1) | (-(v74 ^ -1))) >> 31)) & 2)) - (v76 + ((~(((v78 ^ -1) | (-(v78 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
        int v84 = v83[v206];
        int * v85 = v20->cache_vals;
        int v208 = (((4 + ((((int)((unsigned int)((int)((unsigned int)v27 >> 2)) >> 1)) & 3) * 2)) + ((((v72 + ((~(((v74 ^ -1) | (-(v74 ^ -1))) >> 31)) & 2)) - (v76 + ((~(((v78 ^ -1) | (-(v78 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
        int v86 = v85[v208];
        int * v87 = v20->mem;
        int v210 = v82 * 2;
        v87[v210] = v84;
        int * v89 = v20->mem;
        int v213 = (v82 * 2) + 1;
        v89[v213] = v86;
        ;
      } else {
        ;
      }
      int * v94 = v20->mem;
      int v218 = ((int)((unsigned int)((int)((unsigned int)v27 >> 2)) >> 1)) * 2;
      int v95 = v94[v218];
      int * v96 = v20->mem;
      int v220 = (((int)((unsigned int)((int)((unsigned int)v27 >> 2)) >> 1)) * 2) + 1;
      int v97 = v96[v220];
      int * v98 = v20->cache_vals;
      int v222 = ((4 + ((((int)((unsigned int)((int)((unsigned int)v27 >> 2)) >> 1)) & 3) * 2)) + ((((v72 + ((~(((v74 ^ -1) | (-(v74 ^ -1))) >> 31)) & 2)) - (v76 + ((~(((v78 ^ -1) | (-(v78 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
      v98[v222] = v95;
      int * v100 = v20->cache_vals;
      int v225 = (((4 + ((((int)((unsigned int)((int)((unsigned int)v27 >> 2)) >> 1)) & 3) * 2)) + ((((v72 + ((~(((v74 ^ -1) | (-(v74 ^ -1))) >> 31)) & 2)) - (v76 + ((~(((v78 ^ -1) | (-(v78 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
      v100[v225] = v97;
      int * v102 = v20->cache_tags;
      int v228 = (int)((unsigned int)((int)((unsigned int)v27 >> 2)) >> 1);
      v102[v202] = v228;
      int * v104 = v20->cache_dirty;
      v104[v202] = 0;
      int * v106 = v20->cache_age;
      v106[v202] = 1;
      int * v108 = v20->cache_age;
      int v109 = v108[v202];
      int * v110 = v20->cache_age;
      int v111 = v110[v166];
      int * v112 = v20->cache_age;
      int v236 = v111 + ((int)((unsigned int)(v111 - v109) >> 31));
      v112[v166] = v236;
      int * v114 = v20->cache_age;
      int v115 = v114[v168];
      int * v116 = v20->cache_age;
      int v239 = v115 + ((int)((unsigned int)(v115 - v109) >> 31));
      v116[v168] = v239;
      int * v118 = v20->cache_age;
      v118[v202] = 0;
      v121 = v202;
    }
    int * v122 = v20->cache_vals;
    int v242 = v121 * 2;
    int v123 = v122[v242];
    int * v124 = v20->cache_vals;
    int v244 = (v121 * 2) + 1;
    int v125 = v124[v244];
    int * v126 = v20->cache_vals;
    int v246 = (((((int)((unsigned int)((int)((unsigned int)v27 >> 2)) >> 1)) & 1) * 2) + ((((v51 + ((~(((v53 ^ -1) | (-(v53 ^ -1))) >> 31)) & 2)) - (v55 + ((~(((v57 ^ -1) | (-(v57 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
    v126[v246] = v123;
    int * v128 = v20->cache_vals;
    int v249 = ((((((int)((unsigned int)((int)((unsigned int)v27 >> 2)) >> 1)) & 1) * 2) + ((((v51 + ((~(((v53 ^ -1) | (-(v53 ^ -1))) >> 31)) & 2)) - (v55 + ((~(((v57 ^ -1) | (-(v57 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
    v128[v249] = v125;
    int * v130 = v20->cache_tags;
    int v252 = ((((int)((unsigned int)((int)((unsigned int)v27 >> 2)) >> 1)) & 1) * 2) + ((((v51 + ((~(((v53 ^ -1) | (-(v53 ^ -1))) >> 31)) & 2)) - (v55 + ((~(((v57 ^ -1) | (-(v57 ^ -1))) >> 31)) & 2))) >> 31) & 1);
    int v253 = (int)((unsigned int)((int)((unsigned int)v27 >> 2)) >> 1);
    v130[v252] = v253;
    int * v132 = v20->cache_dirty;
    v132[v252] = 0;
    int * v134 = v20->cache_age;
    v134[v252] = 1;
    int * v136 = v20->cache_age;
    int v137 = v136[v252];
    int * v138 = v20->cache_age;
    int v139 = v138[v162];
    int * v140 = v20->cache_age;
    int v261 = v139 + ((int)((unsigned int)(v139 - v137) >> 31));
    v140[v162] = v261;
    int * v142 = v20->cache_age;
    int v143 = v142[v164];
    int * v144 = v20->cache_age;
    int v264 = v143 + ((int)((unsigned int)(v143 - v137) >> 31));
    v144[v164] = v264;
    int * v146 = v20->cache_age;
    v146[v252] = 0;
    v149 = v252;
  }
  int v267 = (v149 * 2) + (((int)((unsigned int)v27 >> 2)) & 1);
  int v150 = v36[v267];
  int * v151 = v20->reg_ready;
  int v270 = ((v25 + ((v21 - v25) & (~((v21 - v25) >> 31)))) + 1) + ((100 ^ (((~(((v33 ^ ((int)((unsigned int)((int)((unsigned int)v27 >> 2)) >> 1))) | (-(v33 ^ ((int)((unsigned int)((int)((unsigned int)v27 >> 2)) >> 1))))) >> 31)) | (~(((v35 ^ ((int)((unsigned int)((int)((unsigned int)v27 >> 2)) >> 1))) | (-(v35 ^ ((int)((unsigned int)((int)((unsigned int)v27 >> 2)) >> 1))))) >> 31))) & 104)) ^ (((~(((v29 ^ ((int)((unsigned int)((int)((unsigned int)v27 >> 2)) >> 1))) | (-(v29 ^ ((int)((unsigned int)((int)((unsigned int)v27 >> 2)) >> 1))))) >> 31)) | (~(((v31 ^ ((int)((unsigned int)((int)((unsigned int)v27 >> 2)) >> 1))) | (-(v31 ^ ((int)((unsigned int)((int)((unsigned int)v27 >> 2)) >> 1))))) >> 31))) & (1 ^ (100 ^ (((~(((v33 ^ ((int)((unsigned int)((int)((unsigned int)v27 >> 2)) >> 1))) | (-(v33 ^ ((int)((unsigned int)((int)((unsigned int)v27 >> 2)) >> 1))))) >> 31)) | (~(((v35 ^ ((int)((unsigned int)((int)((unsigned int)v27 >> 2)) >> 1))) | (-(v35 ^ ((int)((unsigned int)((int)((unsigned int)v27 >> 2)) >> 1))))) >> 31))) & 104)))));
  v151[16] = v270;
  int * v153 = v20->regs;
  v153[16] = v150;
  struct StateT * v155 = slot_2(v20);
  return v155;
}

struct StateT * slot_8(struct StateT * v572) {
  int v573 = v572->timer;
  int v574 = v572->timer;
  int v577 = v574 + 1;
  v572->timer = v577;
  return v572;
}

struct StateT * slot_6(struct StateT * v548) {
  int v549 = v548->timer;
  int v550 = v548->timer;
  int v558 = v550 + 1;
  v548->timer = v558;
  int * v552 = v548->reg_ready;
  int v561 = v549 + 1;
  v552[18] = v561;
  int * v554 = v548->regs;
  v554[18] = 2;
  struct StateT * v556 = slot_8(v548);
  return v556;
}

struct StateT * slot_5(struct StateT * v327) {
  int * v328 = v327->regs;
  int v329 = v328[16];
  int * v330 = v327->regs;
  int v331 = v330[17];
  bool v444 = v329 < v331;
  struct StateT * v438;
  if (v444) {
    int v332 = v327->timer;
    int v445 = v332 + 15;
    v327->timer = v445;
    int * v334 = v327->saved_regs;
    int v335 = v334[18];
    int * v336 = v327->regs;
    v336[18] = v335;
    int * v338 = v327->reg_ready;
    int v339 = v327->timer;
    v338[0] = v339;
    int * v341 = v327->reg_ready;
    int v342 = v327->timer;
    v341[1] = v342;
    int * v344 = v327->reg_ready;
    int v345 = v327->timer;
    v344[2] = v345;
    int * v347 = v327->reg_ready;
    int v348 = v327->timer;
    v347[3] = v348;
    int * v350 = v327->reg_ready;
    int v351 = v327->timer;
    v350[4] = v351;
    int * v353 = v327->reg_ready;
    int v354 = v327->timer;
    v353[5] = v354;
    int * v356 = v327->reg_ready;
    int v357 = v327->timer;
    v356[6] = v357;
    int * v359 = v327->reg_ready;
    int v360 = v327->timer;
    v359[7] = v360;
    int * v362 = v327->reg_ready;
    int v363 = v327->timer;
    v362[8] = v363;
    int * v365 = v327->reg_ready;
    int v366 = v327->timer;
    v365[9] = v366;
    int * v368 = v327->reg_ready;
    int v369 = v327->timer;
    v368[10] = v369;
    int * v371 = v327->reg_ready;
    int v372 = v327->timer;
    v371[11] = v372;
    int * v374 = v327->reg_ready;
    int v375 = v327->timer;
    v374[12] = v375;
    int * v377 = v327->reg_ready;
    int v378 = v327->timer;
    v377[13] = v378;
    int * v380 = v327->reg_ready;
    int v381 = v327->timer;
    v380[14] = v381;
    int * v383 = v327->reg_ready;
    int v384 = v327->timer;
    v383[15] = v384;
    int * v386 = v327->reg_ready;
    int v387 = v327->timer;
    v386[16] = v387;
    int * v389 = v327->reg_ready;
    int v390 = v327->timer;
    v389[17] = v390;
    int * v392 = v327->reg_ready;
    int v393 = v327->timer;
    v392[18] = v393;
    int * v395 = v327->reg_ready;
    int v396 = v327->timer;
    v395[19] = v396;
    int * v398 = v327->reg_ready;
    int v399 = v327->timer;
    v398[20] = v399;
    int * v401 = v327->reg_ready;
    int v402 = v327->timer;
    v401[21] = v402;
    int * v404 = v327->reg_ready;
    int v405 = v327->timer;
    v404[22] = v405;
    int * v407 = v327->reg_ready;
    int v408 = v327->timer;
    v407[23] = v408;
    int * v410 = v327->reg_ready;
    int v411 = v327->timer;
    v410[24] = v411;
    int * v413 = v327->reg_ready;
    int v414 = v327->timer;
    v413[25] = v414;
    int * v416 = v327->reg_ready;
    int v417 = v327->timer;
    v416[26] = v417;
    int * v419 = v327->reg_ready;
    int v420 = v327->timer;
    v419[27] = v420;
    int * v422 = v327->reg_ready;
    int v423 = v327->timer;
    v422[28] = v423;
    int * v425 = v327->reg_ready;
    int v426 = v327->timer;
    v425[29] = v426;
    int * v428 = v327->reg_ready;
    int v429 = v327->timer;
    v428[30] = v429;
    int * v431 = v327->reg_ready;
    int v432 = v327->timer;
    v431[31] = v432;
    struct StateT * v434 = slot_6(v327);
    v438 = v434;
  } else {
    struct StateT * v436 = slot_7(v327);
    v438 = v436;
  }
  return v438;
}

struct StateT * slot_4(struct StateT * v302) {
  int * v303 = v302->saved_regs;
  int * v304 = v302->regs;
  int v305 = v304[18];
  v303[18] = v305;
  int v307 = v302->timer;
  int v308 = v302->timer;
  int v320 = v308 + 1;
  v302->timer = v320;
  int * v310 = v302->reg_ready;
  int v322 = v307 + 1;
  v310[18] = v322;
  int * v312 = v302->regs;
  v312[18] = 1;
  struct StateT * v314 = slot_5(v302);
  return v314;
}

struct StateT * slot_2(struct StateT * v275) {
  int v276 = v275->timer;
  int v277 = v275->timer;
  int v285 = v277 + 1;
  v275->timer = v285;
  int * v279 = v275->reg_ready;
  int v288 = v276 + 1;
  v279[17] = v288;
  int * v281 = v275->regs;
  v281[17] = 10;
  struct StateT * v283 = slot_3(v275);
  return v283;
}

struct StateT * slot_7(struct StateT * v566) {
  int v567 = v566->timer;
  int v568 = v566->timer;
  int v571 = v568 + 1;
  v566->timer = v571;
  return v566;
}

struct StateT * slot_3(struct StateT * v293) {
  int v294 = v293->timer;
  int v295 = v293->timer;
  int v299 = v295 + 1;
  v293->timer = v299;
  struct StateT * v297 = slot_4(v293);
  return v297;
}

struct StateT * slot_0(struct StateT * v2) {
  int v3 = v2->timer;
  int v4 = v2->timer;
  int v12 = v4 + 1;
  v2->timer = v12;
  int * v6 = v2->reg_ready;
  int v15 = v3 + 1;
  v6[12] = v15;
  int * v8 = v2->regs;
  v8[12] = 80;
  struct StateT * v10 = slot_1(v2);
  return v10;
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