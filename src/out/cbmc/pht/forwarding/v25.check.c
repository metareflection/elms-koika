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

struct StateT * slot_6(struct StateT * v282);
struct StateT * slot_29(struct StateT * v1341);
struct StateT * slot_25(struct StateT * v1094);
struct StateT * slot_16(struct StateT * v594);
struct StateT * slot_23(struct StateT * v878);
struct StateT * slot_5(struct StateT * v274);
struct StateT * slot_2(struct StateT * v30);
struct StateT * slot_7(struct StateT * v296);
struct StateT * slot_21(struct StateT * v659);
struct StateT * slot_31(struct StateT * v1670);
struct StateT * slot_3(struct StateT * v233);
struct StateT * slot_26(struct StateT * v1108);
struct StateT * slot_10(struct StateT * v526);
struct StateT * slot_1(struct StateT * v10);
struct StateT * slot_19(struct StateT * v637);
struct StateT * slot_13(struct StateT * v553);
struct StateT * slot_38(struct StateT * v2128);
struct StateT * slot_24(struct StateT * v891);
struct StateT * slot_0(struct StateT * v2);
struct StateT * slot_28(struct StateT * v1325);
struct StateT * slot_32(struct StateT * v1684);
struct StateT * slot_17(struct StateT * v607);
struct StateT * slot_33(struct StateT * v1689);
struct StateT * snippet(struct StateT * v0);
struct StateT * slot_4(struct StateT * v261);
struct StateT * slot_15(struct StateT * v580);
struct StateT * slot_6(struct StateT * v282) {
  int v283 = v282->timer;
  int v290 = v283 + 1;
  v282->timer = v290;
  int * v285 = v282->regs;
  int v286 = v285[10];
  int v293 = v286 + 72;
  v285[10] = v293;
  struct StateT * v288 = slot_21(v282);
  return v288;
}

struct StateT * slot_29(struct StateT * v1341) {
  int v1342 = v1341->timer;
  int v1349 = v1342 + 1;
  v1341->timer = v1349;
  int * v1344 = v1341->regs;
  int v1345 = v1344[10];
  int v1352 = v1345 << 29;
  v1344[10] = v1352;
  struct StateT * v1347 = slot_31(v1341);
  return v1347;
}

struct StateT * slot_25(struct StateT * v1094) {
  int v1095 = v1094->timer;
  int v1102 = v1095 + 1;
  v1094->timer = v1102;
  int * v1097 = v1094->regs;
  int v1098 = v1097[11];
  int v1105 = v1098 + 4;
  v1097[11] = v1105;
  struct StateT * v1100 = slot_16(v1094);
  return v1100;
}

struct StateT * slot_16(struct StateT * v594) {
  int v595 = v594->timer;
  int v601 = v595 + 1;
  v594->timer = v601;
  int * v597 = v594->regs;
  v597[12] = 0;
  struct StateT * v599 = slot_29(v594);
  return v599;
}

struct StateT * slot_23(struct StateT * v878) {
  int v879 = v878->timer;
  int v885 = v879 + 1;
  v878->timer = v885;
  int * v881 = v878->regs;
  v881[11] = 0;
  struct StateT * v883 = slot_25(v878);
  return v883;
}

struct StateT * slot_5(struct StateT * v274) {
  int v275 = v274->timer;
  int v279 = v275 + 1;
  v274->timer = v279;
  struct StateT * v277 = slot_7(v274);
  return v277;
}

struct StateT * slot_2(struct StateT * v30) {
  int v31 = v30->timer;
  int v141 = v31 + 1;
  v30->timer = v141;
  int * v33 = v30->regs;
  int v34 = v33[11];
  int * v35 = v30->cache_tags;
  int v145 = (((int)((unsigned int)((int)((unsigned int)v34 >> 2)) >> 1)) & 1) * 2;
  int v36 = v35[v145];
  int v146 = ((((int)((unsigned int)((int)((unsigned int)v34 >> 2)) >> 1)) & 1) * 2) + 1;
  int v37 = v35[v146];
  int v147 = 4 + ((((int)((unsigned int)((int)((unsigned int)v34 >> 2)) >> 1)) & 3) * 2);
  int v38 = v35[v147];
  int v148 = (4 + ((((int)((unsigned int)((int)((unsigned int)v34 >> 2)) >> 1)) & 3) * 2)) + 1;
  int v39 = v35[v148];
  int v40 = v30->timer;
  int v149 = v40 + ((100 ^ (((~(((v38 ^ ((int)((unsigned int)((int)((unsigned int)v34 >> 2)) >> 1))) | (-(v38 ^ ((int)((unsigned int)((int)((unsigned int)v34 >> 2)) >> 1))))) >> 31)) | (~(((v39 ^ ((int)((unsigned int)((int)((unsigned int)v34 >> 2)) >> 1))) | (-(v39 ^ ((int)((unsigned int)((int)((unsigned int)v34 >> 2)) >> 1))))) >> 31))) & 104)) ^ (((~(((v36 ^ ((int)((unsigned int)((int)((unsigned int)v34 >> 2)) >> 1))) | (-(v36 ^ ((int)((unsigned int)((int)((unsigned int)v34 >> 2)) >> 1))))) >> 31)) | (~(((v37 ^ ((int)((unsigned int)((int)((unsigned int)v34 >> 2)) >> 1))) | (-(v37 ^ ((int)((unsigned int)((int)((unsigned int)v34 >> 2)) >> 1))))) >> 31))) & (1 ^ (100 ^ (((~(((v38 ^ ((int)((unsigned int)((int)((unsigned int)v34 >> 2)) >> 1))) | (-(v38 ^ ((int)((unsigned int)((int)((unsigned int)v34 >> 2)) >> 1))))) >> 31)) | (~(((v39 ^ ((int)((unsigned int)((int)((unsigned int)v34 >> 2)) >> 1))) | (-(v39 ^ ((int)((unsigned int)((int)((unsigned int)v34 >> 2)) >> 1))))) >> 31))) & 104)))));
  v30->timer = v149;
  int * v42 = v30->cache_vals;
  bool v150 = !(((~(((v36 ^ ((int)((unsigned int)((int)((unsigned int)v34 >> 2)) >> 1))) | (-(v36 ^ ((int)((unsigned int)((int)((unsigned int)v34 >> 2)) >> 1))))) >> 31)) | (~(((v37 ^ ((int)((unsigned int)((int)((unsigned int)v34 >> 2)) >> 1))) | (-(v37 ^ ((int)((unsigned int)((int)((unsigned int)v34 >> 2)) >> 1))))) >> 31))) == 0);
  int v135;
  if (v150) {
    int * v43 = v30->cache_age;
    int v152 = ((((int)((unsigned int)((int)((unsigned int)v34 >> 2)) >> 1)) & 1) * 2) + ((~(((v37 ^ ((int)((unsigned int)((int)((unsigned int)v34 >> 2)) >> 1))) | (-(v37 ^ ((int)((unsigned int)((int)((unsigned int)v34 >> 2)) >> 1))))) >> 31)) & 1);
    int v44 = v43[v152];
    int v45 = v43[v145];
    int v153 = v45 + ((int)((unsigned int)(v45 - v44) >> 31));
    v43[v145] = v153;
    int * v47 = v30->cache_age;
    int v48 = v47[v146];
    int v155 = v48 + ((int)((unsigned int)(v48 - v44) >> 31));
    v47[v146] = v155;
    int * v50 = v30->cache_age;
    v50[v152] = 0;
    v135 = v152;
  } else {
    int * v53 = v30->cache_age;
    int v159 = (((int)((unsigned int)((int)((unsigned int)v34 >> 2)) >> 1)) & 1) * 2;
    int v54 = v53[v159];
    int * v55 = v30->cache_tags;
    int v56 = v55[v159];
    int v57 = v53[v146];
    int v58 = v55[v146];
    bool v161 = !(((~(((v38 ^ ((int)((unsigned int)((int)((unsigned int)v34 >> 2)) >> 1))) | (-(v38 ^ ((int)((unsigned int)((int)((unsigned int)v34 >> 2)) >> 1))))) >> 31)) | (~(((v39 ^ ((int)((unsigned int)((int)((unsigned int)v34 >> 2)) >> 1))) | (-(v39 ^ ((int)((unsigned int)((int)((unsigned int)v34 >> 2)) >> 1))))) >> 31))) == 0);
    int v112;
    if (v161) {
      int * v59 = v30->cache_age;
      int v163 = (4 + ((((int)((unsigned int)((int)((unsigned int)v34 >> 2)) >> 1)) & 3) * 2)) + ((~(((v39 ^ ((int)((unsigned int)((int)((unsigned int)v34 >> 2)) >> 1))) | (-(v39 ^ ((int)((unsigned int)((int)((unsigned int)v34 >> 2)) >> 1))))) >> 31)) & 1);
      int v60 = v59[v163];
      int v61 = v59[v147];
      int v164 = v61 + ((int)((unsigned int)(v61 - v60) >> 31));
      v59[v147] = v164;
      int * v63 = v30->cache_age;
      int v64 = v63[v148];
      int v166 = v64 + ((int)((unsigned int)(v64 - v60) >> 31));
      v63[v148] = v166;
      int * v66 = v30->cache_age;
      v66[v163] = 0;
      v112 = v163;
    } else {
      int * v69 = v30->cache_age;
      int v170 = 4 + ((((int)((unsigned int)((int)((unsigned int)v34 >> 2)) >> 1)) & 3) * 2);
      int v70 = v69[v170];
      int * v71 = v30->cache_tags;
      int v72 = v71[v170];
      int v73 = v69[v148];
      int v74 = v71[v148];
      int * v75 = v30->cache_dirty;
      int v173 = (4 + ((((int)((unsigned int)((int)((unsigned int)v34 >> 2)) >> 1)) & 3) * 2)) + ((((v70 + ((~(((v72 ^ -1) | (-(v72 ^ -1))) >> 31)) & 2)) - (v73 + ((~(((v74 ^ -1) | (-(v74 ^ -1))) >> 31)) & 2))) >> 31) & 1);
      int v76 = v75[v173];
      bool v174 = !(v76 == 0);
      if (v174) {
        int * v77 = v30->cache_tags;
        int v78 = v77[v173];
        int * v79 = v30->cache_vals;
        int v177 = ((4 + ((((int)((unsigned int)((int)((unsigned int)v34 >> 2)) >> 1)) & 3) * 2)) + ((((v70 + ((~(((v72 ^ -1) | (-(v72 ^ -1))) >> 31)) & 2)) - (v73 + ((~(((v74 ^ -1) | (-(v74 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
        int v80 = v79[v177];
        int v178 = (((4 + ((((int)((unsigned int)((int)((unsigned int)v34 >> 2)) >> 1)) & 3) * 2)) + ((((v70 + ((~(((v72 ^ -1) | (-(v72 ^ -1))) >> 31)) & 2)) - (v73 + ((~(((v74 ^ -1) | (-(v74 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
        int v81 = v79[v178];
        int * v82 = v30->mem;
        int v180 = v78 * 2;
        v82[v180] = v80;
        int * v84 = v30->mem;
        int v183 = (v78 * 2) + 1;
        v84[v183] = v81;
        ;
      } else {
        ;
      }
      int * v89 = v30->mem;
      int v188 = ((int)((unsigned int)((int)((unsigned int)v34 >> 2)) >> 1)) * 2;
      int v90 = v89[v188];
      int v189 = (((int)((unsigned int)((int)((unsigned int)v34 >> 2)) >> 1)) * 2) + 1;
      int v91 = v89[v189];
      int * v92 = v30->cache_vals;
      int v191 = ((4 + ((((int)((unsigned int)((int)((unsigned int)v34 >> 2)) >> 1)) & 3) * 2)) + ((((v70 + ((~(((v72 ^ -1) | (-(v72 ^ -1))) >> 31)) & 2)) - (v73 + ((~(((v74 ^ -1) | (-(v74 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
      v92[v191] = v90;
      int * v94 = v30->cache_vals;
      int v194 = (((4 + ((((int)((unsigned int)((int)((unsigned int)v34 >> 2)) >> 1)) & 3) * 2)) + ((((v70 + ((~(((v72 ^ -1) | (-(v72 ^ -1))) >> 31)) & 2)) - (v73 + ((~(((v74 ^ -1) | (-(v74 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
      v94[v194] = v91;
      int * v96 = v30->cache_tags;
      int v197 = (int)((unsigned int)((int)((unsigned int)v34 >> 2)) >> 1);
      v96[v173] = v197;
      int * v98 = v30->cache_dirty;
      v98[v173] = 0;
      int * v100 = v30->cache_age;
      v100[v173] = 1;
      int * v102 = v30->cache_age;
      int v103 = v102[v173];
      int v104 = v102[v147];
      int v203 = v104 + ((int)((unsigned int)(v104 - v103) >> 31));
      v102[v147] = v203;
      int * v106 = v30->cache_age;
      int v107 = v106[v148];
      int v205 = v107 + ((int)((unsigned int)(v107 - v103) >> 31));
      v106[v148] = v205;
      int * v109 = v30->cache_age;
      v109[v173] = 0;
      v112 = v173;
    }
    int * v113 = v30->cache_vals;
    int v208 = v112 * 2;
    int v114 = v113[v208];
    int v209 = (v112 * 2) + 1;
    int v115 = v113[v209];
    int v210 = (((((int)((unsigned int)((int)((unsigned int)v34 >> 2)) >> 1)) & 1) * 2) + ((((v54 + ((~(((v56 ^ -1) | (-(v56 ^ -1))) >> 31)) & 2)) - (v57 + ((~(((v58 ^ -1) | (-(v58 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
    v113[v210] = v114;
    int * v117 = v30->cache_vals;
    int v213 = ((((((int)((unsigned int)((int)((unsigned int)v34 >> 2)) >> 1)) & 1) * 2) + ((((v54 + ((~(((v56 ^ -1) | (-(v56 ^ -1))) >> 31)) & 2)) - (v57 + ((~(((v58 ^ -1) | (-(v58 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
    v117[v213] = v115;
    int * v119 = v30->cache_tags;
    int v216 = ((((int)((unsigned int)((int)((unsigned int)v34 >> 2)) >> 1)) & 1) * 2) + ((((v54 + ((~(((v56 ^ -1) | (-(v56 ^ -1))) >> 31)) & 2)) - (v57 + ((~(((v58 ^ -1) | (-(v58 ^ -1))) >> 31)) & 2))) >> 31) & 1);
    int v217 = (int)((unsigned int)((int)((unsigned int)v34 >> 2)) >> 1);
    v119[v216] = v217;
    int * v121 = v30->cache_dirty;
    v121[v216] = 0;
    int * v123 = v30->cache_age;
    v123[v216] = 1;
    int * v125 = v30->cache_age;
    int v126 = v125[v216];
    int v127 = v125[v145];
    int v223 = v127 + ((int)((unsigned int)(v127 - v126) >> 31));
    v125[v145] = v223;
    int * v129 = v30->cache_age;
    int v130 = v129[v146];
    int v225 = v130 + ((int)((unsigned int)(v130 - v126) >> 31));
    v129[v146] = v225;
    int * v132 = v30->cache_age;
    v132[v216] = 0;
    v135 = v216;
  }
  int v228 = (v135 * 2) + (((int)((unsigned int)v34 >> 2)) & 1);
  int v136 = v42[v228];
  int * v137 = v30->regs;
  v137[11] = v136;
  struct StateT * v139 = slot_3(v30);
  return v139;
}

struct StateT * slot_7(struct StateT * v296) {
  int * v297 = v296->regs;
  int v298 = v297[10];
  int v299 = v297[11];
  bool v311 = (v298 ^ -2147483648) >= (v299 ^ -2147483648);
  struct StateT * v306;
  if (v311) {
    int v300 = v296->timer;
    int v312 = v300 + 15;
    v296->timer = v312;
    struct StateT * v302 = slot_32(v296);
    v306 = v302;
  } else {
    struct StateT * v304 = slot_10(v296);
    v306 = v304;
  }
  return v306;
}

struct StateT * slot_21(struct StateT * v659) {
  int v660 = v659->timer;
  int v770 = v660 + 1;
  v659->timer = v770;
  int * v662 = v659->regs;
  int v663 = v662[10];
  int * v664 = v659->cache_tags;
  int v774 = (((int)((unsigned int)((int)((unsigned int)v663 >> 2)) >> 1)) & 1) * 2;
  int v665 = v664[v774];
  int v775 = ((((int)((unsigned int)((int)((unsigned int)v663 >> 2)) >> 1)) & 1) * 2) + 1;
  int v666 = v664[v775];
  int v776 = 4 + ((((int)((unsigned int)((int)((unsigned int)v663 >> 2)) >> 1)) & 3) * 2);
  int v667 = v664[v776];
  int v777 = (4 + ((((int)((unsigned int)((int)((unsigned int)v663 >> 2)) >> 1)) & 3) * 2)) + 1;
  int v668 = v664[v777];
  int v669 = v659->timer;
  int v778 = v669 + ((100 ^ (((~(((v667 ^ ((int)((unsigned int)((int)((unsigned int)v663 >> 2)) >> 1))) | (-(v667 ^ ((int)((unsigned int)((int)((unsigned int)v663 >> 2)) >> 1))))) >> 31)) | (~(((v668 ^ ((int)((unsigned int)((int)((unsigned int)v663 >> 2)) >> 1))) | (-(v668 ^ ((int)((unsigned int)((int)((unsigned int)v663 >> 2)) >> 1))))) >> 31))) & 104)) ^ (((~(((v665 ^ ((int)((unsigned int)((int)((unsigned int)v663 >> 2)) >> 1))) | (-(v665 ^ ((int)((unsigned int)((int)((unsigned int)v663 >> 2)) >> 1))))) >> 31)) | (~(((v666 ^ ((int)((unsigned int)((int)((unsigned int)v663 >> 2)) >> 1))) | (-(v666 ^ ((int)((unsigned int)((int)((unsigned int)v663 >> 2)) >> 1))))) >> 31))) & (1 ^ (100 ^ (((~(((v667 ^ ((int)((unsigned int)((int)((unsigned int)v663 >> 2)) >> 1))) | (-(v667 ^ ((int)((unsigned int)((int)((unsigned int)v663 >> 2)) >> 1))))) >> 31)) | (~(((v668 ^ ((int)((unsigned int)((int)((unsigned int)v663 >> 2)) >> 1))) | (-(v668 ^ ((int)((unsigned int)((int)((unsigned int)v663 >> 2)) >> 1))))) >> 31))) & 104)))));
  v659->timer = v778;
  int * v671 = v659->cache_vals;
  bool v779 = !(((~(((v665 ^ ((int)((unsigned int)((int)((unsigned int)v663 >> 2)) >> 1))) | (-(v665 ^ ((int)((unsigned int)((int)((unsigned int)v663 >> 2)) >> 1))))) >> 31)) | (~(((v666 ^ ((int)((unsigned int)((int)((unsigned int)v663 >> 2)) >> 1))) | (-(v666 ^ ((int)((unsigned int)((int)((unsigned int)v663 >> 2)) >> 1))))) >> 31))) == 0);
  int v764;
  if (v779) {
    int * v672 = v659->cache_age;
    int v781 = ((((int)((unsigned int)((int)((unsigned int)v663 >> 2)) >> 1)) & 1) * 2) + ((~(((v666 ^ ((int)((unsigned int)((int)((unsigned int)v663 >> 2)) >> 1))) | (-(v666 ^ ((int)((unsigned int)((int)((unsigned int)v663 >> 2)) >> 1))))) >> 31)) & 1);
    int v673 = v672[v781];
    int v674 = v672[v774];
    int v782 = v674 + ((int)((unsigned int)(v674 - v673) >> 31));
    v672[v774] = v782;
    int * v676 = v659->cache_age;
    int v677 = v676[v775];
    int v784 = v677 + ((int)((unsigned int)(v677 - v673) >> 31));
    v676[v775] = v784;
    int * v679 = v659->cache_age;
    v679[v781] = 0;
    v764 = v781;
  } else {
    int * v682 = v659->cache_age;
    int v788 = (((int)((unsigned int)((int)((unsigned int)v663 >> 2)) >> 1)) & 1) * 2;
    int v683 = v682[v788];
    int * v684 = v659->cache_tags;
    int v685 = v684[v788];
    int v686 = v682[v775];
    int v687 = v684[v775];
    bool v790 = !(((~(((v667 ^ ((int)((unsigned int)((int)((unsigned int)v663 >> 2)) >> 1))) | (-(v667 ^ ((int)((unsigned int)((int)((unsigned int)v663 >> 2)) >> 1))))) >> 31)) | (~(((v668 ^ ((int)((unsigned int)((int)((unsigned int)v663 >> 2)) >> 1))) | (-(v668 ^ ((int)((unsigned int)((int)((unsigned int)v663 >> 2)) >> 1))))) >> 31))) == 0);
    int v741;
    if (v790) {
      int * v688 = v659->cache_age;
      int v792 = (4 + ((((int)((unsigned int)((int)((unsigned int)v663 >> 2)) >> 1)) & 3) * 2)) + ((~(((v668 ^ ((int)((unsigned int)((int)((unsigned int)v663 >> 2)) >> 1))) | (-(v668 ^ ((int)((unsigned int)((int)((unsigned int)v663 >> 2)) >> 1))))) >> 31)) & 1);
      int v689 = v688[v792];
      int v690 = v688[v776];
      int v793 = v690 + ((int)((unsigned int)(v690 - v689) >> 31));
      v688[v776] = v793;
      int * v692 = v659->cache_age;
      int v693 = v692[v777];
      int v795 = v693 + ((int)((unsigned int)(v693 - v689) >> 31));
      v692[v777] = v795;
      int * v695 = v659->cache_age;
      v695[v792] = 0;
      v741 = v792;
    } else {
      int * v698 = v659->cache_age;
      int v799 = 4 + ((((int)((unsigned int)((int)((unsigned int)v663 >> 2)) >> 1)) & 3) * 2);
      int v699 = v698[v799];
      int * v700 = v659->cache_tags;
      int v701 = v700[v799];
      int v702 = v698[v777];
      int v703 = v700[v777];
      int * v704 = v659->cache_dirty;
      int v802 = (4 + ((((int)((unsigned int)((int)((unsigned int)v663 >> 2)) >> 1)) & 3) * 2)) + ((((v699 + ((~(((v701 ^ -1) | (-(v701 ^ -1))) >> 31)) & 2)) - (v702 + ((~(((v703 ^ -1) | (-(v703 ^ -1))) >> 31)) & 2))) >> 31) & 1);
      int v705 = v704[v802];
      bool v803 = !(v705 == 0);
      if (v803) {
        int * v706 = v659->cache_tags;
        int v707 = v706[v802];
        int * v708 = v659->cache_vals;
        int v806 = ((4 + ((((int)((unsigned int)((int)((unsigned int)v663 >> 2)) >> 1)) & 3) * 2)) + ((((v699 + ((~(((v701 ^ -1) | (-(v701 ^ -1))) >> 31)) & 2)) - (v702 + ((~(((v703 ^ -1) | (-(v703 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
        int v709 = v708[v806];
        int v807 = (((4 + ((((int)((unsigned int)((int)((unsigned int)v663 >> 2)) >> 1)) & 3) * 2)) + ((((v699 + ((~(((v701 ^ -1) | (-(v701 ^ -1))) >> 31)) & 2)) - (v702 + ((~(((v703 ^ -1) | (-(v703 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
        int v710 = v708[v807];
        int * v711 = v659->mem;
        int v809 = v707 * 2;
        v711[v809] = v709;
        int * v713 = v659->mem;
        int v812 = (v707 * 2) + 1;
        v713[v812] = v710;
        ;
      } else {
        ;
      }
      int * v718 = v659->mem;
      int v817 = ((int)((unsigned int)((int)((unsigned int)v663 >> 2)) >> 1)) * 2;
      int v719 = v718[v817];
      int v818 = (((int)((unsigned int)((int)((unsigned int)v663 >> 2)) >> 1)) * 2) + 1;
      int v720 = v718[v818];
      int * v721 = v659->cache_vals;
      int v820 = ((4 + ((((int)((unsigned int)((int)((unsigned int)v663 >> 2)) >> 1)) & 3) * 2)) + ((((v699 + ((~(((v701 ^ -1) | (-(v701 ^ -1))) >> 31)) & 2)) - (v702 + ((~(((v703 ^ -1) | (-(v703 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
      v721[v820] = v719;
      int * v723 = v659->cache_vals;
      int v823 = (((4 + ((((int)((unsigned int)((int)((unsigned int)v663 >> 2)) >> 1)) & 3) * 2)) + ((((v699 + ((~(((v701 ^ -1) | (-(v701 ^ -1))) >> 31)) & 2)) - (v702 + ((~(((v703 ^ -1) | (-(v703 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
      v723[v823] = v720;
      int * v725 = v659->cache_tags;
      int v826 = (int)((unsigned int)((int)((unsigned int)v663 >> 2)) >> 1);
      v725[v802] = v826;
      int * v727 = v659->cache_dirty;
      v727[v802] = 0;
      int * v729 = v659->cache_age;
      v729[v802] = 1;
      int * v731 = v659->cache_age;
      int v732 = v731[v802];
      int v733 = v731[v776];
      int v832 = v733 + ((int)((unsigned int)(v733 - v732) >> 31));
      v731[v776] = v832;
      int * v735 = v659->cache_age;
      int v736 = v735[v777];
      int v834 = v736 + ((int)((unsigned int)(v736 - v732) >> 31));
      v735[v777] = v834;
      int * v738 = v659->cache_age;
      v738[v802] = 0;
      v741 = v802;
    }
    int * v742 = v659->cache_vals;
    int v837 = v741 * 2;
    int v743 = v742[v837];
    int v838 = (v741 * 2) + 1;
    int v744 = v742[v838];
    int v839 = (((((int)((unsigned int)((int)((unsigned int)v663 >> 2)) >> 1)) & 1) * 2) + ((((v683 + ((~(((v685 ^ -1) | (-(v685 ^ -1))) >> 31)) & 2)) - (v686 + ((~(((v687 ^ -1) | (-(v687 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
    v742[v839] = v743;
    int * v746 = v659->cache_vals;
    int v842 = ((((((int)((unsigned int)((int)((unsigned int)v663 >> 2)) >> 1)) & 1) * 2) + ((((v683 + ((~(((v685 ^ -1) | (-(v685 ^ -1))) >> 31)) & 2)) - (v686 + ((~(((v687 ^ -1) | (-(v687 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
    v746[v842] = v744;
    int * v748 = v659->cache_tags;
    int v845 = ((((int)((unsigned int)((int)((unsigned int)v663 >> 2)) >> 1)) & 1) * 2) + ((((v683 + ((~(((v685 ^ -1) | (-(v685 ^ -1))) >> 31)) & 2)) - (v686 + ((~(((v687 ^ -1) | (-(v687 ^ -1))) >> 31)) & 2))) >> 31) & 1);
    int v846 = (int)((unsigned int)((int)((unsigned int)v663 >> 2)) >> 1);
    v748[v845] = v846;
    int * v750 = v659->cache_dirty;
    v750[v845] = 0;
    int * v752 = v659->cache_age;
    v752[v845] = 1;
    int * v754 = v659->cache_age;
    int v755 = v754[v845];
    int v756 = v754[v774];
    int v852 = v756 + ((int)((unsigned int)(v756 - v755) >> 31));
    v754[v774] = v852;
    int * v758 = v659->cache_age;
    int v759 = v758[v775];
    int v854 = v759 + ((int)((unsigned int)(v759 - v755) >> 31));
    v758[v775] = v854;
    int * v761 = v659->cache_age;
    v761[v845] = 0;
    v764 = v845;
  }
  int v857 = (v764 * 2) + (((int)((unsigned int)v663 >> 2)) & 1);
  int v765 = v671[v857];
  int * v766 = v659->regs;
  v766[10] = v765;
  struct StateT * v768 = slot_23(v659);
  return v768;
}

struct StateT * slot_31(struct StateT * v1670) {
  int v1671 = v1670->timer;
  int v1678 = v1671 + 1;
  v1670->timer = v1678;
  int * v1673 = v1670->regs;
  int v1674 = v1673[10];
  int v1681 = (int)((unsigned int)v1674 >> 26);
  v1673[10] = v1681;
  struct StateT * v1676 = slot_33(v1670);
  return v1676;
}

struct StateT * slot_3(struct StateT * v233) {
  int * v234 = v233->regs;
  int v235 = v234[10];
  bool v250 = v235 == 0;
  struct StateT * v246;
  if (v250) {
    int v236 = v233->timer;
    int v251 = v236 + 15;
    v233->timer = v251;
    int * v238 = v233->saved_regs;
    int v239 = v238[11];
    int * v240 = v233->regs;
    v240[11] = v239;
    struct StateT * v242 = slot_4(v233);
    v246 = v242;
  } else {
    struct StateT * v244 = slot_5(v233);
    v246 = v244;
  }
  return v246;
}

struct StateT * slot_26(struct StateT * v1108) {
  int v1109 = v1108->timer;
  int v1219 = v1109 + 1;
  v1108->timer = v1219;
  int * v1111 = v1108->regs;
  int v1112 = v1111[12];
  int * v1113 = v1108->cache_tags;
  int v1223 = (((int)((unsigned int)((int)((unsigned int)(v1112 + 68) >> 2)) >> 1)) & 1) * 2;
  int v1114 = v1113[v1223];
  int v1224 = ((((int)((unsigned int)((int)((unsigned int)(v1112 + 68) >> 2)) >> 1)) & 1) * 2) + 1;
  int v1115 = v1113[v1224];
  int v1225 = 4 + ((((int)((unsigned int)((int)((unsigned int)(v1112 + 68) >> 2)) >> 1)) & 3) * 2);
  int v1116 = v1113[v1225];
  int v1226 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v1112 + 68) >> 2)) >> 1)) & 3) * 2)) + 1;
  int v1117 = v1113[v1226];
  int v1118 = v1108->timer;
  int v1227 = v1118 + ((100 ^ (((~(((v1116 ^ ((int)((unsigned int)((int)((unsigned int)(v1112 + 68) >> 2)) >> 1))) | (-(v1116 ^ ((int)((unsigned int)((int)((unsigned int)(v1112 + 68) >> 2)) >> 1))))) >> 31)) | (~(((v1117 ^ ((int)((unsigned int)((int)((unsigned int)(v1112 + 68) >> 2)) >> 1))) | (-(v1117 ^ ((int)((unsigned int)((int)((unsigned int)(v1112 + 68) >> 2)) >> 1))))) >> 31))) & 104)) ^ (((~(((v1114 ^ ((int)((unsigned int)((int)((unsigned int)(v1112 + 68) >> 2)) >> 1))) | (-(v1114 ^ ((int)((unsigned int)((int)((unsigned int)(v1112 + 68) >> 2)) >> 1))))) >> 31)) | (~(((v1115 ^ ((int)((unsigned int)((int)((unsigned int)(v1112 + 68) >> 2)) >> 1))) | (-(v1115 ^ ((int)((unsigned int)((int)((unsigned int)(v1112 + 68) >> 2)) >> 1))))) >> 31))) & (1 ^ (100 ^ (((~(((v1116 ^ ((int)((unsigned int)((int)((unsigned int)(v1112 + 68) >> 2)) >> 1))) | (-(v1116 ^ ((int)((unsigned int)((int)((unsigned int)(v1112 + 68) >> 2)) >> 1))))) >> 31)) | (~(((v1117 ^ ((int)((unsigned int)((int)((unsigned int)(v1112 + 68) >> 2)) >> 1))) | (-(v1117 ^ ((int)((unsigned int)((int)((unsigned int)(v1112 + 68) >> 2)) >> 1))))) >> 31))) & 104)))));
  v1108->timer = v1227;
  int * v1120 = v1108->cache_vals;
  bool v1228 = !(((~(((v1114 ^ ((int)((unsigned int)((int)((unsigned int)(v1112 + 68) >> 2)) >> 1))) | (-(v1114 ^ ((int)((unsigned int)((int)((unsigned int)(v1112 + 68) >> 2)) >> 1))))) >> 31)) | (~(((v1115 ^ ((int)((unsigned int)((int)((unsigned int)(v1112 + 68) >> 2)) >> 1))) | (-(v1115 ^ ((int)((unsigned int)((int)((unsigned int)(v1112 + 68) >> 2)) >> 1))))) >> 31))) == 0);
  int v1213;
  if (v1228) {
    int * v1121 = v1108->cache_age;
    int v1230 = ((((int)((unsigned int)((int)((unsigned int)(v1112 + 68) >> 2)) >> 1)) & 1) * 2) + ((~(((v1115 ^ ((int)((unsigned int)((int)((unsigned int)(v1112 + 68) >> 2)) >> 1))) | (-(v1115 ^ ((int)((unsigned int)((int)((unsigned int)(v1112 + 68) >> 2)) >> 1))))) >> 31)) & 1);
    int v1122 = v1121[v1230];
    int v1123 = v1121[v1223];
    int v1231 = v1123 + ((int)((unsigned int)(v1123 - v1122) >> 31));
    v1121[v1223] = v1231;
    int * v1125 = v1108->cache_age;
    int v1126 = v1125[v1224];
    int v1233 = v1126 + ((int)((unsigned int)(v1126 - v1122) >> 31));
    v1125[v1224] = v1233;
    int * v1128 = v1108->cache_age;
    v1128[v1230] = 0;
    v1213 = v1230;
  } else {
    int * v1131 = v1108->cache_age;
    int v1237 = (((int)((unsigned int)((int)((unsigned int)(v1112 + 68) >> 2)) >> 1)) & 1) * 2;
    int v1132 = v1131[v1237];
    int * v1133 = v1108->cache_tags;
    int v1134 = v1133[v1237];
    int v1135 = v1131[v1224];
    int v1136 = v1133[v1224];
    bool v1239 = !(((~(((v1116 ^ ((int)((unsigned int)((int)((unsigned int)(v1112 + 68) >> 2)) >> 1))) | (-(v1116 ^ ((int)((unsigned int)((int)((unsigned int)(v1112 + 68) >> 2)) >> 1))))) >> 31)) | (~(((v1117 ^ ((int)((unsigned int)((int)((unsigned int)(v1112 + 68) >> 2)) >> 1))) | (-(v1117 ^ ((int)((unsigned int)((int)((unsigned int)(v1112 + 68) >> 2)) >> 1))))) >> 31))) == 0);
    int v1190;
    if (v1239) {
      int * v1137 = v1108->cache_age;
      int v1241 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v1112 + 68) >> 2)) >> 1)) & 3) * 2)) + ((~(((v1117 ^ ((int)((unsigned int)((int)((unsigned int)(v1112 + 68) >> 2)) >> 1))) | (-(v1117 ^ ((int)((unsigned int)((int)((unsigned int)(v1112 + 68) >> 2)) >> 1))))) >> 31)) & 1);
      int v1138 = v1137[v1241];
      int v1139 = v1137[v1225];
      int v1242 = v1139 + ((int)((unsigned int)(v1139 - v1138) >> 31));
      v1137[v1225] = v1242;
      int * v1141 = v1108->cache_age;
      int v1142 = v1141[v1226];
      int v1244 = v1142 + ((int)((unsigned int)(v1142 - v1138) >> 31));
      v1141[v1226] = v1244;
      int * v1144 = v1108->cache_age;
      v1144[v1241] = 0;
      v1190 = v1241;
    } else {
      int * v1147 = v1108->cache_age;
      int v1248 = 4 + ((((int)((unsigned int)((int)((unsigned int)(v1112 + 68) >> 2)) >> 1)) & 3) * 2);
      int v1148 = v1147[v1248];
      int * v1149 = v1108->cache_tags;
      int v1150 = v1149[v1248];
      int v1151 = v1147[v1226];
      int v1152 = v1149[v1226];
      int * v1153 = v1108->cache_dirty;
      int v1251 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v1112 + 68) >> 2)) >> 1)) & 3) * 2)) + ((((v1148 + ((~(((v1150 ^ -1) | (-(v1150 ^ -1))) >> 31)) & 2)) - (v1151 + ((~(((v1152 ^ -1) | (-(v1152 ^ -1))) >> 31)) & 2))) >> 31) & 1);
      int v1154 = v1153[v1251];
      bool v1252 = !(v1154 == 0);
      if (v1252) {
        int * v1155 = v1108->cache_tags;
        int v1156 = v1155[v1251];
        int * v1157 = v1108->cache_vals;
        int v1255 = ((4 + ((((int)((unsigned int)((int)((unsigned int)(v1112 + 68) >> 2)) >> 1)) & 3) * 2)) + ((((v1148 + ((~(((v1150 ^ -1) | (-(v1150 ^ -1))) >> 31)) & 2)) - (v1151 + ((~(((v1152 ^ -1) | (-(v1152 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
        int v1158 = v1157[v1255];
        int v1256 = (((4 + ((((int)((unsigned int)((int)((unsigned int)(v1112 + 68) >> 2)) >> 1)) & 3) * 2)) + ((((v1148 + ((~(((v1150 ^ -1) | (-(v1150 ^ -1))) >> 31)) & 2)) - (v1151 + ((~(((v1152 ^ -1) | (-(v1152 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
        int v1159 = v1157[v1256];
        int * v1160 = v1108->mem;
        int v1258 = v1156 * 2;
        v1160[v1258] = v1158;
        int * v1162 = v1108->mem;
        int v1261 = (v1156 * 2) + 1;
        v1162[v1261] = v1159;
        ;
      } else {
        ;
      }
      int * v1167 = v1108->mem;
      int v1266 = ((int)((unsigned int)((int)((unsigned int)(v1112 + 68) >> 2)) >> 1)) * 2;
      int v1168 = v1167[v1266];
      int v1267 = (((int)((unsigned int)((int)((unsigned int)(v1112 + 68) >> 2)) >> 1)) * 2) + 1;
      int v1169 = v1167[v1267];
      int * v1170 = v1108->cache_vals;
      int v1269 = ((4 + ((((int)((unsigned int)((int)((unsigned int)(v1112 + 68) >> 2)) >> 1)) & 3) * 2)) + ((((v1148 + ((~(((v1150 ^ -1) | (-(v1150 ^ -1))) >> 31)) & 2)) - (v1151 + ((~(((v1152 ^ -1) | (-(v1152 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
      v1170[v1269] = v1168;
      int * v1172 = v1108->cache_vals;
      int v1272 = (((4 + ((((int)((unsigned int)((int)((unsigned int)(v1112 + 68) >> 2)) >> 1)) & 3) * 2)) + ((((v1148 + ((~(((v1150 ^ -1) | (-(v1150 ^ -1))) >> 31)) & 2)) - (v1151 + ((~(((v1152 ^ -1) | (-(v1152 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
      v1172[v1272] = v1169;
      int * v1174 = v1108->cache_tags;
      int v1275 = (int)((unsigned int)((int)((unsigned int)(v1112 + 68) >> 2)) >> 1);
      v1174[v1251] = v1275;
      int * v1176 = v1108->cache_dirty;
      v1176[v1251] = 0;
      int * v1178 = v1108->cache_age;
      v1178[v1251] = 1;
      int * v1180 = v1108->cache_age;
      int v1181 = v1180[v1251];
      int v1182 = v1180[v1225];
      int v1281 = v1182 + ((int)((unsigned int)(v1182 - v1181) >> 31));
      v1180[v1225] = v1281;
      int * v1184 = v1108->cache_age;
      int v1185 = v1184[v1226];
      int v1283 = v1185 + ((int)((unsigned int)(v1185 - v1181) >> 31));
      v1184[v1226] = v1283;
      int * v1187 = v1108->cache_age;
      v1187[v1251] = 0;
      v1190 = v1251;
    }
    int * v1191 = v1108->cache_vals;
    int v1286 = v1190 * 2;
    int v1192 = v1191[v1286];
    int v1287 = (v1190 * 2) + 1;
    int v1193 = v1191[v1287];
    int v1288 = (((((int)((unsigned int)((int)((unsigned int)(v1112 + 68) >> 2)) >> 1)) & 1) * 2) + ((((v1132 + ((~(((v1134 ^ -1) | (-(v1134 ^ -1))) >> 31)) & 2)) - (v1135 + ((~(((v1136 ^ -1) | (-(v1136 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
    v1191[v1288] = v1192;
    int * v1195 = v1108->cache_vals;
    int v1291 = ((((((int)((unsigned int)((int)((unsigned int)(v1112 + 68) >> 2)) >> 1)) & 1) * 2) + ((((v1132 + ((~(((v1134 ^ -1) | (-(v1134 ^ -1))) >> 31)) & 2)) - (v1135 + ((~(((v1136 ^ -1) | (-(v1136 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
    v1195[v1291] = v1193;
    int * v1197 = v1108->cache_tags;
    int v1294 = ((((int)((unsigned int)((int)((unsigned int)(v1112 + 68) >> 2)) >> 1)) & 1) * 2) + ((((v1132 + ((~(((v1134 ^ -1) | (-(v1134 ^ -1))) >> 31)) & 2)) - (v1135 + ((~(((v1136 ^ -1) | (-(v1136 ^ -1))) >> 31)) & 2))) >> 31) & 1);
    int v1295 = (int)((unsigned int)((int)((unsigned int)(v1112 + 68) >> 2)) >> 1);
    v1197[v1294] = v1295;
    int * v1199 = v1108->cache_dirty;
    v1199[v1294] = 0;
    int * v1201 = v1108->cache_age;
    v1201[v1294] = 1;
    int * v1203 = v1108->cache_age;
    int v1204 = v1203[v1294];
    int v1205 = v1203[v1223];
    int v1301 = v1205 + ((int)((unsigned int)(v1205 - v1204) >> 31));
    v1203[v1223] = v1301;
    int * v1207 = v1108->cache_age;
    int v1208 = v1207[v1224];
    int v1303 = v1208 + ((int)((unsigned int)(v1208 - v1204) >> 31));
    v1207[v1224] = v1303;
    int * v1210 = v1108->cache_age;
    v1210[v1294] = 0;
    v1213 = v1294;
  }
  int v1306 = (v1213 * 2) + (((int)((unsigned int)(v1112 + 68) >> 2)) & 1);
  int v1214 = v1120[v1306];
  int * v1215 = v1108->regs;
  v1215[11] = v1214;
  struct StateT * v1217 = slot_28(v1108);
  return v1217;
}

struct StateT * slot_10(struct StateT * v526) {
  int v527 = v526->timer;
  int v534 = v527 + 1;
  v526->timer = v534;
  int * v529 = v526->regs;
  int v530 = v529[10];
  int v537 = v530 << 2;
  v529[10] = v537;
  struct StateT * v532 = slot_13(v526);
  return v532;
}

struct StateT * slot_1(struct StateT * v10) {
  int * v11 = v10->saved_regs;
  int * v12 = v10->regs;
  int v13 = v12[11];
  v11[11] = v13;
  int v15 = v10->timer;
  int v25 = v15 + 1;
  v10->timer = v25;
  int * v17 = v10->regs;
  v17[11] = 0;
  struct StateT * v19 = slot_2(v10);
  return v19;
}

struct StateT * slot_19(struct StateT * v637) {
  int v638 = v637->timer;
  int v642 = v638 + 1;
  v637->timer = v642;
  struct StateT * v640 = slot_21(v637);
  return v640;
}

struct StateT * slot_13(struct StateT * v553) {
  int v554 = v553->timer;
  int v560 = v554 + 1;
  v553->timer = v560;
  int * v556 = v553->regs;
  v556[11] = 0;
  struct StateT * v558 = slot_15(v553);
  return v558;
}

struct StateT * slot_38(struct StateT * v2128) {
  int v2129 = v2128->timer;
  int v2299 = v2129 + 1;
  v2128->timer = v2299;
  int * v2131 = v2128->regs;
  int v2132 = v2131[12];
  int v2133 = v2131[10];
  int * v2134 = v2128->cache_tags;
  int v2304 = (((int)((unsigned int)((int)((unsigned int)(v2132 + 68) >> 2)) >> 1)) & 1) * 2;
  int v2135 = v2134[v2304];
  int v2305 = ((((int)((unsigned int)((int)((unsigned int)(v2132 + 68) >> 2)) >> 1)) & 1) * 2) + 1;
  int v2136 = v2134[v2305];
  int v2306 = 4 + ((((int)((unsigned int)((int)((unsigned int)(v2132 + 68) >> 2)) >> 1)) & 3) * 2);
  int v2137 = v2134[v2306];
  int v2307 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v2132 + 68) >> 2)) >> 1)) & 3) * 2)) + 1;
  int v2138 = v2134[v2307];
  int v2139 = v2128->timer;
  int v2308 = v2139 + ((100 ^ (((~(((v2137 ^ ((int)((unsigned int)((int)((unsigned int)(v2132 + 68) >> 2)) >> 1))) | (-(v2137 ^ ((int)((unsigned int)((int)((unsigned int)(v2132 + 68) >> 2)) >> 1))))) >> 31)) | (~(((v2138 ^ ((int)((unsigned int)((int)((unsigned int)(v2132 + 68) >> 2)) >> 1))) | (-(v2138 ^ ((int)((unsigned int)((int)((unsigned int)(v2132 + 68) >> 2)) >> 1))))) >> 31))) & 104)) ^ (((~(((v2135 ^ ((int)((unsigned int)((int)((unsigned int)(v2132 + 68) >> 2)) >> 1))) | (-(v2135 ^ ((int)((unsigned int)((int)((unsigned int)(v2132 + 68) >> 2)) >> 1))))) >> 31)) | (~(((v2136 ^ ((int)((unsigned int)((int)((unsigned int)(v2132 + 68) >> 2)) >> 1))) | (-(v2136 ^ ((int)((unsigned int)((int)((unsigned int)(v2132 + 68) >> 2)) >> 1))))) >> 31))) & (1 ^ (100 ^ (((~(((v2137 ^ ((int)((unsigned int)((int)((unsigned int)(v2132 + 68) >> 2)) >> 1))) | (-(v2137 ^ ((int)((unsigned int)((int)((unsigned int)(v2132 + 68) >> 2)) >> 1))))) >> 31)) | (~(((v2138 ^ ((int)((unsigned int)((int)((unsigned int)(v2132 + 68) >> 2)) >> 1))) | (-(v2138 ^ ((int)((unsigned int)((int)((unsigned int)(v2132 + 68) >> 2)) >> 1))))) >> 31))) & 104)))));
  v2128->timer = v2308;
  bool v2309 = !(((~(((v2135 ^ ((int)((unsigned int)((int)((unsigned int)(v2132 + 68) >> 2)) >> 1))) | (-(v2135 ^ ((int)((unsigned int)((int)((unsigned int)(v2132 + 68) >> 2)) >> 1))))) >> 31)) | (~(((v2136 ^ ((int)((unsigned int)((int)((unsigned int)(v2132 + 68) >> 2)) >> 1))) | (-(v2136 ^ ((int)((unsigned int)((int)((unsigned int)(v2132 + 68) >> 2)) >> 1))))) >> 31))) == 0);
  int v2233;
  if (v2309) {
    int * v2141 = v2128->cache_age;
    int v2311 = ((((int)((unsigned int)((int)((unsigned int)(v2132 + 68) >> 2)) >> 1)) & 1) * 2) + ((~(((v2136 ^ ((int)((unsigned int)((int)((unsigned int)(v2132 + 68) >> 2)) >> 1))) | (-(v2136 ^ ((int)((unsigned int)((int)((unsigned int)(v2132 + 68) >> 2)) >> 1))))) >> 31)) & 1);
    int v2142 = v2141[v2311];
    int v2143 = v2141[v2304];
    int v2312 = v2143 + ((int)((unsigned int)(v2143 - v2142) >> 31));
    v2141[v2304] = v2312;
    int * v2145 = v2128->cache_age;
    int v2146 = v2145[v2305];
    int v2314 = v2146 + ((int)((unsigned int)(v2146 - v2142) >> 31));
    v2145[v2305] = v2314;
    int * v2148 = v2128->cache_age;
    v2148[v2311] = 0;
    v2233 = v2311;
  } else {
    int * v2151 = v2128->cache_age;
    int v2318 = (((int)((unsigned int)((int)((unsigned int)(v2132 + 68) >> 2)) >> 1)) & 1) * 2;
    int v2152 = v2151[v2318];
    int * v2153 = v2128->cache_tags;
    int v2154 = v2153[v2318];
    int v2155 = v2151[v2305];
    int v2156 = v2153[v2305];
    bool v2320 = !(((~(((v2137 ^ ((int)((unsigned int)((int)((unsigned int)(v2132 + 68) >> 2)) >> 1))) | (-(v2137 ^ ((int)((unsigned int)((int)((unsigned int)(v2132 + 68) >> 2)) >> 1))))) >> 31)) | (~(((v2138 ^ ((int)((unsigned int)((int)((unsigned int)(v2132 + 68) >> 2)) >> 1))) | (-(v2138 ^ ((int)((unsigned int)((int)((unsigned int)(v2132 + 68) >> 2)) >> 1))))) >> 31))) == 0);
    int v2210;
    if (v2320) {
      int * v2157 = v2128->cache_age;
      int v2322 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v2132 + 68) >> 2)) >> 1)) & 3) * 2)) + ((~(((v2138 ^ ((int)((unsigned int)((int)((unsigned int)(v2132 + 68) >> 2)) >> 1))) | (-(v2138 ^ ((int)((unsigned int)((int)((unsigned int)(v2132 + 68) >> 2)) >> 1))))) >> 31)) & 1);
      int v2158 = v2157[v2322];
      int v2159 = v2157[v2306];
      int v2323 = v2159 + ((int)((unsigned int)(v2159 - v2158) >> 31));
      v2157[v2306] = v2323;
      int * v2161 = v2128->cache_age;
      int v2162 = v2161[v2307];
      int v2325 = v2162 + ((int)((unsigned int)(v2162 - v2158) >> 31));
      v2161[v2307] = v2325;
      int * v2164 = v2128->cache_age;
      v2164[v2322] = 0;
      v2210 = v2322;
    } else {
      int * v2167 = v2128->cache_age;
      int v2329 = 4 + ((((int)((unsigned int)((int)((unsigned int)(v2132 + 68) >> 2)) >> 1)) & 3) * 2);
      int v2168 = v2167[v2329];
      int * v2169 = v2128->cache_tags;
      int v2170 = v2169[v2329];
      int v2171 = v2167[v2307];
      int v2172 = v2169[v2307];
      int * v2173 = v2128->cache_dirty;
      int v2332 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v2132 + 68) >> 2)) >> 1)) & 3) * 2)) + ((((v2168 + ((~(((v2170 ^ -1) | (-(v2170 ^ -1))) >> 31)) & 2)) - (v2171 + ((~(((v2172 ^ -1) | (-(v2172 ^ -1))) >> 31)) & 2))) >> 31) & 1);
      int v2174 = v2173[v2332];
      bool v2333 = !(v2174 == 0);
      if (v2333) {
        int * v2175 = v2128->cache_tags;
        int v2176 = v2175[v2332];
        int * v2177 = v2128->cache_vals;
        int v2336 = ((4 + ((((int)((unsigned int)((int)((unsigned int)(v2132 + 68) >> 2)) >> 1)) & 3) * 2)) + ((((v2168 + ((~(((v2170 ^ -1) | (-(v2170 ^ -1))) >> 31)) & 2)) - (v2171 + ((~(((v2172 ^ -1) | (-(v2172 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
        int v2178 = v2177[v2336];
        int v2337 = (((4 + ((((int)((unsigned int)((int)((unsigned int)(v2132 + 68) >> 2)) >> 1)) & 3) * 2)) + ((((v2168 + ((~(((v2170 ^ -1) | (-(v2170 ^ -1))) >> 31)) & 2)) - (v2171 + ((~(((v2172 ^ -1) | (-(v2172 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
        int v2179 = v2177[v2337];
        int * v2180 = v2128->mem;
        int v2339 = v2176 * 2;
        v2180[v2339] = v2178;
        int * v2182 = v2128->mem;
        int v2342 = (v2176 * 2) + 1;
        v2182[v2342] = v2179;
        ;
      } else {
        ;
      }
      int * v2187 = v2128->mem;
      int v2347 = ((int)((unsigned int)((int)((unsigned int)(v2132 + 68) >> 2)) >> 1)) * 2;
      int v2188 = v2187[v2347];
      int v2348 = (((int)((unsigned int)((int)((unsigned int)(v2132 + 68) >> 2)) >> 1)) * 2) + 1;
      int v2189 = v2187[v2348];
      int * v2190 = v2128->cache_vals;
      int v2350 = ((4 + ((((int)((unsigned int)((int)((unsigned int)(v2132 + 68) >> 2)) >> 1)) & 3) * 2)) + ((((v2168 + ((~(((v2170 ^ -1) | (-(v2170 ^ -1))) >> 31)) & 2)) - (v2171 + ((~(((v2172 ^ -1) | (-(v2172 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
      v2190[v2350] = v2188;
      int * v2192 = v2128->cache_vals;
      int v2353 = (((4 + ((((int)((unsigned int)((int)((unsigned int)(v2132 + 68) >> 2)) >> 1)) & 3) * 2)) + ((((v2168 + ((~(((v2170 ^ -1) | (-(v2170 ^ -1))) >> 31)) & 2)) - (v2171 + ((~(((v2172 ^ -1) | (-(v2172 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
      v2192[v2353] = v2189;
      int * v2194 = v2128->cache_tags;
      int v2356 = (int)((unsigned int)((int)((unsigned int)(v2132 + 68) >> 2)) >> 1);
      v2194[v2332] = v2356;
      int * v2196 = v2128->cache_dirty;
      v2196[v2332] = 0;
      int * v2198 = v2128->cache_age;
      v2198[v2332] = 1;
      int * v2200 = v2128->cache_age;
      int v2201 = v2200[v2332];
      int v2202 = v2200[v2306];
      int v2362 = v2202 + ((int)((unsigned int)(v2202 - v2201) >> 31));
      v2200[v2306] = v2362;
      int * v2204 = v2128->cache_age;
      int v2205 = v2204[v2307];
      int v2364 = v2205 + ((int)((unsigned int)(v2205 - v2201) >> 31));
      v2204[v2307] = v2364;
      int * v2207 = v2128->cache_age;
      v2207[v2332] = 0;
      v2210 = v2332;
    }
    int * v2211 = v2128->cache_vals;
    int v2367 = v2210 * 2;
    int v2212 = v2211[v2367];
    int v2368 = (v2210 * 2) + 1;
    int v2213 = v2211[v2368];
    int v2369 = (((((int)((unsigned int)((int)((unsigned int)(v2132 + 68) >> 2)) >> 1)) & 1) * 2) + ((((v2152 + ((~(((v2154 ^ -1) | (-(v2154 ^ -1))) >> 31)) & 2)) - (v2155 + ((~(((v2156 ^ -1) | (-(v2156 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
    v2211[v2369] = v2212;
    int * v2215 = v2128->cache_vals;
    int v2372 = ((((((int)((unsigned int)((int)((unsigned int)(v2132 + 68) >> 2)) >> 1)) & 1) * 2) + ((((v2152 + ((~(((v2154 ^ -1) | (-(v2154 ^ -1))) >> 31)) & 2)) - (v2155 + ((~(((v2156 ^ -1) | (-(v2156 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
    v2215[v2372] = v2213;
    int * v2217 = v2128->cache_tags;
    int v2375 = ((((int)((unsigned int)((int)((unsigned int)(v2132 + 68) >> 2)) >> 1)) & 1) * 2) + ((((v2152 + ((~(((v2154 ^ -1) | (-(v2154 ^ -1))) >> 31)) & 2)) - (v2155 + ((~(((v2156 ^ -1) | (-(v2156 ^ -1))) >> 31)) & 2))) >> 31) & 1);
    int v2376 = (int)((unsigned int)((int)((unsigned int)(v2132 + 68) >> 2)) >> 1);
    v2217[v2375] = v2376;
    int * v2219 = v2128->cache_dirty;
    v2219[v2375] = 0;
    int * v2221 = v2128->cache_age;
    v2221[v2375] = 1;
    int * v2223 = v2128->cache_age;
    int v2224 = v2223[v2375];
    int v2225 = v2223[v2304];
    int v2382 = v2225 + ((int)((unsigned int)(v2225 - v2224) >> 31));
    v2223[v2304] = v2382;
    int * v2227 = v2128->cache_age;
    int v2228 = v2227[v2305];
    int v2384 = v2228 + ((int)((unsigned int)(v2228 - v2224) >> 31));
    v2227[v2305] = v2384;
    int * v2230 = v2128->cache_age;
    v2230[v2375] = 0;
    v2233 = v2375;
  }
  int * v2234 = v2128->cache_vals;
  int v2387 = (v2233 * 2) + (((int)((unsigned int)(v2132 + 68) >> 2)) & 1);
  v2234[v2387] = v2133;
  int * v2236 = v2128->cache_tags;
  int v2237 = v2236[v2306];
  int v2238 = v2236[v2307];
  bool v2390 = !(((~(((v2237 ^ ((int)((unsigned int)((int)((unsigned int)(v2132 + 68) >> 2)) >> 1))) | (-(v2237 ^ ((int)((unsigned int)((int)((unsigned int)(v2132 + 68) >> 2)) >> 1))))) >> 31)) | (~(((v2238 ^ ((int)((unsigned int)((int)((unsigned int)(v2132 + 68) >> 2)) >> 1))) | (-(v2238 ^ ((int)((unsigned int)((int)((unsigned int)(v2132 + 68) >> 2)) >> 1))))) >> 31))) == 0);
  int v2292;
  if (v2390) {
    int * v2239 = v2128->cache_age;
    int v2392 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v2132 + 68) >> 2)) >> 1)) & 3) * 2)) + ((~(((v2238 ^ ((int)((unsigned int)((int)((unsigned int)(v2132 + 68) >> 2)) >> 1))) | (-(v2238 ^ ((int)((unsigned int)((int)((unsigned int)(v2132 + 68) >> 2)) >> 1))))) >> 31)) & 1);
    int v2240 = v2239[v2392];
    int v2241 = v2239[v2306];
    int v2393 = v2241 + ((int)((unsigned int)(v2241 - v2240) >> 31));
    v2239[v2306] = v2393;
    int * v2243 = v2128->cache_age;
    int v2244 = v2243[v2307];
    int v2395 = v2244 + ((int)((unsigned int)(v2244 - v2240) >> 31));
    v2243[v2307] = v2395;
    int * v2246 = v2128->cache_age;
    v2246[v2392] = 0;
    v2292 = v2392;
  } else {
    int * v2249 = v2128->cache_age;
    int v2399 = 4 + ((((int)((unsigned int)((int)((unsigned int)(v2132 + 68) >> 2)) >> 1)) & 3) * 2);
    int v2250 = v2249[v2399];
    int * v2251 = v2128->cache_tags;
    int v2252 = v2251[v2399];
    int v2253 = v2249[v2307];
    int v2254 = v2251[v2307];
    int * v2255 = v2128->cache_dirty;
    int v2402 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v2132 + 68) >> 2)) >> 1)) & 3) * 2)) + ((((v2250 + ((~(((v2252 ^ -1) | (-(v2252 ^ -1))) >> 31)) & 2)) - (v2253 + ((~(((v2254 ^ -1) | (-(v2254 ^ -1))) >> 31)) & 2))) >> 31) & 1);
    int v2256 = v2255[v2402];
    bool v2403 = !(v2256 == 0);
    if (v2403) {
      int * v2257 = v2128->cache_tags;
      int v2258 = v2257[v2402];
      int * v2259 = v2128->cache_vals;
      int v2406 = ((4 + ((((int)((unsigned int)((int)((unsigned int)(v2132 + 68) >> 2)) >> 1)) & 3) * 2)) + ((((v2250 + ((~(((v2252 ^ -1) | (-(v2252 ^ -1))) >> 31)) & 2)) - (v2253 + ((~(((v2254 ^ -1) | (-(v2254 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
      int v2260 = v2259[v2406];
      int v2407 = (((4 + ((((int)((unsigned int)((int)((unsigned int)(v2132 + 68) >> 2)) >> 1)) & 3) * 2)) + ((((v2250 + ((~(((v2252 ^ -1) | (-(v2252 ^ -1))) >> 31)) & 2)) - (v2253 + ((~(((v2254 ^ -1) | (-(v2254 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
      int v2261 = v2259[v2407];
      int * v2262 = v2128->mem;
      int v2409 = v2258 * 2;
      v2262[v2409] = v2260;
      int * v2264 = v2128->mem;
      int v2412 = (v2258 * 2) + 1;
      v2264[v2412] = v2261;
      ;
    } else {
      ;
    }
    int * v2269 = v2128->mem;
    int v2417 = ((int)((unsigned int)((int)((unsigned int)(v2132 + 68) >> 2)) >> 1)) * 2;
    int v2270 = v2269[v2417];
    int v2418 = (((int)((unsigned int)((int)((unsigned int)(v2132 + 68) >> 2)) >> 1)) * 2) + 1;
    int v2271 = v2269[v2418];
    int * v2272 = v2128->cache_vals;
    int v2420 = ((4 + ((((int)((unsigned int)((int)((unsigned int)(v2132 + 68) >> 2)) >> 1)) & 3) * 2)) + ((((v2250 + ((~(((v2252 ^ -1) | (-(v2252 ^ -1))) >> 31)) & 2)) - (v2253 + ((~(((v2254 ^ -1) | (-(v2254 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
    v2272[v2420] = v2270;
    int * v2274 = v2128->cache_vals;
    int v2423 = (((4 + ((((int)((unsigned int)((int)((unsigned int)(v2132 + 68) >> 2)) >> 1)) & 3) * 2)) + ((((v2250 + ((~(((v2252 ^ -1) | (-(v2252 ^ -1))) >> 31)) & 2)) - (v2253 + ((~(((v2254 ^ -1) | (-(v2254 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
    v2274[v2423] = v2271;
    int * v2276 = v2128->cache_tags;
    int v2426 = (int)((unsigned int)((int)((unsigned int)(v2132 + 68) >> 2)) >> 1);
    v2276[v2402] = v2426;
    int * v2278 = v2128->cache_dirty;
    v2278[v2402] = 0;
    int * v2280 = v2128->cache_age;
    v2280[v2402] = 1;
    int * v2282 = v2128->cache_age;
    int v2283 = v2282[v2402];
    int v2284 = v2282[v2306];
    int v2432 = v2284 + ((int)((unsigned int)(v2284 - v2283) >> 31));
    v2282[v2306] = v2432;
    int * v2286 = v2128->cache_age;
    int v2287 = v2286[v2307];
    int v2434 = v2287 + ((int)((unsigned int)(v2287 - v2283) >> 31));
    v2286[v2307] = v2434;
    int * v2289 = v2128->cache_age;
    v2289[v2402] = 0;
    v2292 = v2402;
  }
  int * v2293 = v2128->cache_vals;
  int v2437 = (v2292 * 2) + (((int)((unsigned int)(v2132 + 68) >> 2)) & 1);
  v2293[v2437] = v2133;
  int * v2295 = v2128->cache_dirty;
  v2295[v2292] = 1;
  struct StateT * v2297 = slot_32(v2128);
  return v2297;
}

struct StateT * slot_24(struct StateT * v891) {
  int v892 = v891->timer;
  int v1002 = v892 + 1;
  v891->timer = v1002;
  int * v894 = v891->regs;
  int v895 = v894[10];
  int * v896 = v891->cache_tags;
  int v1006 = (((int)((unsigned int)((int)((unsigned int)v895 >> 2)) >> 1)) & 1) * 2;
  int v897 = v896[v1006];
  int v1007 = ((((int)((unsigned int)((int)((unsigned int)v895 >> 2)) >> 1)) & 1) * 2) + 1;
  int v898 = v896[v1007];
  int v1008 = 4 + ((((int)((unsigned int)((int)((unsigned int)v895 >> 2)) >> 1)) & 3) * 2);
  int v899 = v896[v1008];
  int v1009 = (4 + ((((int)((unsigned int)((int)((unsigned int)v895 >> 2)) >> 1)) & 3) * 2)) + 1;
  int v900 = v896[v1009];
  int v901 = v891->timer;
  int v1010 = v901 + ((100 ^ (((~(((v899 ^ ((int)((unsigned int)((int)((unsigned int)v895 >> 2)) >> 1))) | (-(v899 ^ ((int)((unsigned int)((int)((unsigned int)v895 >> 2)) >> 1))))) >> 31)) | (~(((v900 ^ ((int)((unsigned int)((int)((unsigned int)v895 >> 2)) >> 1))) | (-(v900 ^ ((int)((unsigned int)((int)((unsigned int)v895 >> 2)) >> 1))))) >> 31))) & 104)) ^ (((~(((v897 ^ ((int)((unsigned int)((int)((unsigned int)v895 >> 2)) >> 1))) | (-(v897 ^ ((int)((unsigned int)((int)((unsigned int)v895 >> 2)) >> 1))))) >> 31)) | (~(((v898 ^ ((int)((unsigned int)((int)((unsigned int)v895 >> 2)) >> 1))) | (-(v898 ^ ((int)((unsigned int)((int)((unsigned int)v895 >> 2)) >> 1))))) >> 31))) & (1 ^ (100 ^ (((~(((v899 ^ ((int)((unsigned int)((int)((unsigned int)v895 >> 2)) >> 1))) | (-(v899 ^ ((int)((unsigned int)((int)((unsigned int)v895 >> 2)) >> 1))))) >> 31)) | (~(((v900 ^ ((int)((unsigned int)((int)((unsigned int)v895 >> 2)) >> 1))) | (-(v900 ^ ((int)((unsigned int)((int)((unsigned int)v895 >> 2)) >> 1))))) >> 31))) & 104)))));
  v891->timer = v1010;
  int * v903 = v891->cache_vals;
  bool v1011 = !(((~(((v897 ^ ((int)((unsigned int)((int)((unsigned int)v895 >> 2)) >> 1))) | (-(v897 ^ ((int)((unsigned int)((int)((unsigned int)v895 >> 2)) >> 1))))) >> 31)) | (~(((v898 ^ ((int)((unsigned int)((int)((unsigned int)v895 >> 2)) >> 1))) | (-(v898 ^ ((int)((unsigned int)((int)((unsigned int)v895 >> 2)) >> 1))))) >> 31))) == 0);
  int v996;
  if (v1011) {
    int * v904 = v891->cache_age;
    int v1013 = ((((int)((unsigned int)((int)((unsigned int)v895 >> 2)) >> 1)) & 1) * 2) + ((~(((v898 ^ ((int)((unsigned int)((int)((unsigned int)v895 >> 2)) >> 1))) | (-(v898 ^ ((int)((unsigned int)((int)((unsigned int)v895 >> 2)) >> 1))))) >> 31)) & 1);
    int v905 = v904[v1013];
    int v906 = v904[v1006];
    int v1014 = v906 + ((int)((unsigned int)(v906 - v905) >> 31));
    v904[v1006] = v1014;
    int * v908 = v891->cache_age;
    int v909 = v908[v1007];
    int v1016 = v909 + ((int)((unsigned int)(v909 - v905) >> 31));
    v908[v1007] = v1016;
    int * v911 = v891->cache_age;
    v911[v1013] = 0;
    v996 = v1013;
  } else {
    int * v914 = v891->cache_age;
    int v1020 = (((int)((unsigned int)((int)((unsigned int)v895 >> 2)) >> 1)) & 1) * 2;
    int v915 = v914[v1020];
    int * v916 = v891->cache_tags;
    int v917 = v916[v1020];
    int v918 = v914[v1007];
    int v919 = v916[v1007];
    bool v1022 = !(((~(((v899 ^ ((int)((unsigned int)((int)((unsigned int)v895 >> 2)) >> 1))) | (-(v899 ^ ((int)((unsigned int)((int)((unsigned int)v895 >> 2)) >> 1))))) >> 31)) | (~(((v900 ^ ((int)((unsigned int)((int)((unsigned int)v895 >> 2)) >> 1))) | (-(v900 ^ ((int)((unsigned int)((int)((unsigned int)v895 >> 2)) >> 1))))) >> 31))) == 0);
    int v973;
    if (v1022) {
      int * v920 = v891->cache_age;
      int v1024 = (4 + ((((int)((unsigned int)((int)((unsigned int)v895 >> 2)) >> 1)) & 3) * 2)) + ((~(((v900 ^ ((int)((unsigned int)((int)((unsigned int)v895 >> 2)) >> 1))) | (-(v900 ^ ((int)((unsigned int)((int)((unsigned int)v895 >> 2)) >> 1))))) >> 31)) & 1);
      int v921 = v920[v1024];
      int v922 = v920[v1008];
      int v1025 = v922 + ((int)((unsigned int)(v922 - v921) >> 31));
      v920[v1008] = v1025;
      int * v924 = v891->cache_age;
      int v925 = v924[v1009];
      int v1027 = v925 + ((int)((unsigned int)(v925 - v921) >> 31));
      v924[v1009] = v1027;
      int * v927 = v891->cache_age;
      v927[v1024] = 0;
      v973 = v1024;
    } else {
      int * v930 = v891->cache_age;
      int v1031 = 4 + ((((int)((unsigned int)((int)((unsigned int)v895 >> 2)) >> 1)) & 3) * 2);
      int v931 = v930[v1031];
      int * v932 = v891->cache_tags;
      int v933 = v932[v1031];
      int v934 = v930[v1009];
      int v935 = v932[v1009];
      int * v936 = v891->cache_dirty;
      int v1034 = (4 + ((((int)((unsigned int)((int)((unsigned int)v895 >> 2)) >> 1)) & 3) * 2)) + ((((v931 + ((~(((v933 ^ -1) | (-(v933 ^ -1))) >> 31)) & 2)) - (v934 + ((~(((v935 ^ -1) | (-(v935 ^ -1))) >> 31)) & 2))) >> 31) & 1);
      int v937 = v936[v1034];
      bool v1035 = !(v937 == 0);
      if (v1035) {
        int * v938 = v891->cache_tags;
        int v939 = v938[v1034];
        int * v940 = v891->cache_vals;
        int v1038 = ((4 + ((((int)((unsigned int)((int)((unsigned int)v895 >> 2)) >> 1)) & 3) * 2)) + ((((v931 + ((~(((v933 ^ -1) | (-(v933 ^ -1))) >> 31)) & 2)) - (v934 + ((~(((v935 ^ -1) | (-(v935 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
        int v941 = v940[v1038];
        int v1039 = (((4 + ((((int)((unsigned int)((int)((unsigned int)v895 >> 2)) >> 1)) & 3) * 2)) + ((((v931 + ((~(((v933 ^ -1) | (-(v933 ^ -1))) >> 31)) & 2)) - (v934 + ((~(((v935 ^ -1) | (-(v935 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
        int v942 = v940[v1039];
        int * v943 = v891->mem;
        int v1041 = v939 * 2;
        v943[v1041] = v941;
        int * v945 = v891->mem;
        int v1044 = (v939 * 2) + 1;
        v945[v1044] = v942;
        ;
      } else {
        ;
      }
      int * v950 = v891->mem;
      int v1049 = ((int)((unsigned int)((int)((unsigned int)v895 >> 2)) >> 1)) * 2;
      int v951 = v950[v1049];
      int v1050 = (((int)((unsigned int)((int)((unsigned int)v895 >> 2)) >> 1)) * 2) + 1;
      int v952 = v950[v1050];
      int * v953 = v891->cache_vals;
      int v1052 = ((4 + ((((int)((unsigned int)((int)((unsigned int)v895 >> 2)) >> 1)) & 3) * 2)) + ((((v931 + ((~(((v933 ^ -1) | (-(v933 ^ -1))) >> 31)) & 2)) - (v934 + ((~(((v935 ^ -1) | (-(v935 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
      v953[v1052] = v951;
      int * v955 = v891->cache_vals;
      int v1055 = (((4 + ((((int)((unsigned int)((int)((unsigned int)v895 >> 2)) >> 1)) & 3) * 2)) + ((((v931 + ((~(((v933 ^ -1) | (-(v933 ^ -1))) >> 31)) & 2)) - (v934 + ((~(((v935 ^ -1) | (-(v935 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
      v955[v1055] = v952;
      int * v957 = v891->cache_tags;
      int v1058 = (int)((unsigned int)((int)((unsigned int)v895 >> 2)) >> 1);
      v957[v1034] = v1058;
      int * v959 = v891->cache_dirty;
      v959[v1034] = 0;
      int * v961 = v891->cache_age;
      v961[v1034] = 1;
      int * v963 = v891->cache_age;
      int v964 = v963[v1034];
      int v965 = v963[v1008];
      int v1064 = v965 + ((int)((unsigned int)(v965 - v964) >> 31));
      v963[v1008] = v1064;
      int * v967 = v891->cache_age;
      int v968 = v967[v1009];
      int v1066 = v968 + ((int)((unsigned int)(v968 - v964) >> 31));
      v967[v1009] = v1066;
      int * v970 = v891->cache_age;
      v970[v1034] = 0;
      v973 = v1034;
    }
    int * v974 = v891->cache_vals;
    int v1069 = v973 * 2;
    int v975 = v974[v1069];
    int v1070 = (v973 * 2) + 1;
    int v976 = v974[v1070];
    int v1071 = (((((int)((unsigned int)((int)((unsigned int)v895 >> 2)) >> 1)) & 1) * 2) + ((((v915 + ((~(((v917 ^ -1) | (-(v917 ^ -1))) >> 31)) & 2)) - (v918 + ((~(((v919 ^ -1) | (-(v919 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
    v974[v1071] = v975;
    int * v978 = v891->cache_vals;
    int v1074 = ((((((int)((unsigned int)((int)((unsigned int)v895 >> 2)) >> 1)) & 1) * 2) + ((((v915 + ((~(((v917 ^ -1) | (-(v917 ^ -1))) >> 31)) & 2)) - (v918 + ((~(((v919 ^ -1) | (-(v919 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
    v978[v1074] = v976;
    int * v980 = v891->cache_tags;
    int v1077 = ((((int)((unsigned int)((int)((unsigned int)v895 >> 2)) >> 1)) & 1) * 2) + ((((v915 + ((~(((v917 ^ -1) | (-(v917 ^ -1))) >> 31)) & 2)) - (v918 + ((~(((v919 ^ -1) | (-(v919 ^ -1))) >> 31)) & 2))) >> 31) & 1);
    int v1078 = (int)((unsigned int)((int)((unsigned int)v895 >> 2)) >> 1);
    v980[v1077] = v1078;
    int * v982 = v891->cache_dirty;
    v982[v1077] = 0;
    int * v984 = v891->cache_age;
    v984[v1077] = 1;
    int * v986 = v891->cache_age;
    int v987 = v986[v1077];
    int v988 = v986[v1006];
    int v1084 = v988 + ((int)((unsigned int)(v988 - v987) >> 31));
    v986[v1006] = v1084;
    int * v990 = v891->cache_age;
    int v991 = v990[v1007];
    int v1086 = v991 + ((int)((unsigned int)(v991 - v987) >> 31));
    v990[v1007] = v1086;
    int * v993 = v891->cache_age;
    v993[v1077] = 0;
    v996 = v1077;
  }
  int v1089 = (v996 * 2) + (((int)((unsigned int)v895 >> 2)) & 1);
  int v997 = v903[v1089];
  int * v998 = v891->regs;
  v998[10] = v997;
  struct StateT * v1000 = slot_26(v891);
  return v1000;
}

struct StateT * slot_0(struct StateT * v2) {
  int v3 = v2->timer;
  int v7 = v3 + 1;
  v2->timer = v7;
  struct StateT * v5 = slot_1(v2);
  return v5;
}

struct StateT * slot_28(struct StateT * v1325) {
  int v1326 = v1325->timer;
  int v1334 = v1326 + 1;
  v1325->timer = v1334;
  int * v1328 = v1325->regs;
  int v1329 = v1328[11];
  int v1330 = v1328[10];
  int v1338 = v1329 & v1330;
  v1328[10] = v1338;
  struct StateT * v1332 = slot_38(v1325);
  return v1332;
}

struct StateT * slot_32(struct StateT * v1684) {
  int v1685 = v1684->timer;
  int v1688 = v1685 + 1;
  v1684->timer = v1688;
  return v1684;
}

struct StateT * slot_17(struct StateT * v607) {
  int v608 = v607->timer;
  int v616 = v608 + 1;
  v607->timer = v616;
  int * v610 = v607->regs;
  int v611 = v610[11];
  int v612 = v610[10];
  int v620 = v611 + v612;
  v610[10] = v620;
  struct StateT * v614 = slot_19(v607);
  return v614;
}

struct StateT * slot_33(struct StateT * v1689) {
  int v1690 = v1689->timer;
  int v1698 = v1690 + 1;
  v1689->timer = v1698;
  int * v1692 = v1689->regs;
  int v1693 = v1692[11];
  int v1694 = v1692[10];
  int v1702 = v1693 + v1694;
  v1692[10] = v1702;
  struct StateT * v1696 = slot_24(v1689);
  return v1696;
}

struct StateT * snippet(struct StateT * v0) {
  struct StateT * v1 = slot_0(v0);
  return v1;
}

struct StateT * slot_4(struct StateT * v261) {
  int v262 = v261->timer;
  int v268 = v262 + 1;
  v261->timer = v268;
  int * v264 = v261->regs;
  v264[10] = 0;
  struct StateT * v266 = slot_6(v261);
  return v266;
}

struct StateT * slot_15(struct StateT * v580) {
  int v581 = v580->timer;
  int v588 = v581 + 1;
  v580->timer = v588;
  int * v583 = v580->regs;
  int v584 = v583[11];
  int v591 = v584 + 72;
  v583[11] = v591;
  struct StateT * v586 = slot_17(v580);
  return v586;
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