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

struct StateT * slot_12(struct StateT * v567);
struct StateT * slot_6(struct StateT * v282);
struct StateT * slot_29(struct StateT * v1369);
struct StateT * slot_23(struct StateT * v906);
struct StateT * slot_5(struct StateT * v274);
struct StateT * slot_2(struct StateT * v30);
struct StateT * slot_7(struct StateT * v296);
struct StateT * slot_21(struct StateT * v687);
struct StateT * slot_31(struct StateT * v1698);
struct StateT * slot_3(struct StateT * v233);
struct StateT * slot_26(struct StateT * v1136);
struct StateT * slot_1(struct StateT * v10);
struct StateT * slot_13(struct StateT * v581);
struct StateT * slot_38(struct StateT * v2156);
struct StateT * slot_24(struct StateT * v919);
struct StateT * slot_0(struct StateT * v2);
struct StateT * slot_14(struct StateT * v597);
struct StateT * slot_28(struct StateT * v1353);
struct StateT * slot_32(struct StateT * v1712);
struct StateT * slot_33(struct StateT * v1717);
struct StateT * snippet(struct StateT * v0);
struct StateT * slot_4(struct StateT * v261);
struct StateT * slot_15(struct StateT * v610);
struct StateT * slot_18(struct StateT * v665);
struct StateT * slot_9(struct StateT * v520);
struct StateT * slot_11(struct StateT * v553);
struct StateT * slot_12(struct StateT * v567) {
  int v568 = v567->timer;
  int v575 = v568 + 1;
  v567->timer = v575;
  int * v570 = v567->regs;
  int v571 = v570[11];
  int v578 = v571 + 4;
  v570[11] = v578;
  struct StateT * v573 = slot_14(v567);
  return v573;
}

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

struct StateT * slot_29(struct StateT * v1369) {
  int v1370 = v1369->timer;
  int v1377 = v1370 + 1;
  v1369->timer = v1377;
  int * v1372 = v1369->regs;
  int v1373 = v1372[10];
  int v1380 = v1373 << 29;
  v1372[10] = v1380;
  struct StateT * v1375 = slot_31(v1369);
  return v1375;
}

struct StateT * slot_23(struct StateT * v906) {
  int v907 = v906->timer;
  int v913 = v907 + 1;
  v906->timer = v913;
  int * v909 = v906->regs;
  v909[11] = 0;
  struct StateT * v911 = slot_12(v906);
  return v911;
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
  int * v297 = v296->saved_regs;
  int * v298 = v296->regs;
  int v299 = v298[10];
  v297[10] = v299;
  int v301 = v296->timer;
  int v312 = v301 + 1;
  v296->timer = v312;
  int * v303 = v296->regs;
  int v304 = v303[10];
  int v314 = v304 << 2;
  v303[10] = v314;
  struct StateT * v306 = slot_9(v296);
  return v306;
}

struct StateT * slot_21(struct StateT * v687) {
  int v688 = v687->timer;
  int v798 = v688 + 1;
  v687->timer = v798;
  int * v690 = v687->regs;
  int v691 = v690[10];
  int * v692 = v687->cache_tags;
  int v802 = (((int)((unsigned int)((int)((unsigned int)v691 >> 2)) >> 1)) & 1) * 2;
  int v693 = v692[v802];
  int v803 = ((((int)((unsigned int)((int)((unsigned int)v691 >> 2)) >> 1)) & 1) * 2) + 1;
  int v694 = v692[v803];
  int v804 = 4 + ((((int)((unsigned int)((int)((unsigned int)v691 >> 2)) >> 1)) & 3) * 2);
  int v695 = v692[v804];
  int v805 = (4 + ((((int)((unsigned int)((int)((unsigned int)v691 >> 2)) >> 1)) & 3) * 2)) + 1;
  int v696 = v692[v805];
  int v697 = v687->timer;
  int v806 = v697 + ((100 ^ (((~(((v695 ^ ((int)((unsigned int)((int)((unsigned int)v691 >> 2)) >> 1))) | (-(v695 ^ ((int)((unsigned int)((int)((unsigned int)v691 >> 2)) >> 1))))) >> 31)) | (~(((v696 ^ ((int)((unsigned int)((int)((unsigned int)v691 >> 2)) >> 1))) | (-(v696 ^ ((int)((unsigned int)((int)((unsigned int)v691 >> 2)) >> 1))))) >> 31))) & 104)) ^ (((~(((v693 ^ ((int)((unsigned int)((int)((unsigned int)v691 >> 2)) >> 1))) | (-(v693 ^ ((int)((unsigned int)((int)((unsigned int)v691 >> 2)) >> 1))))) >> 31)) | (~(((v694 ^ ((int)((unsigned int)((int)((unsigned int)v691 >> 2)) >> 1))) | (-(v694 ^ ((int)((unsigned int)((int)((unsigned int)v691 >> 2)) >> 1))))) >> 31))) & (1 ^ (100 ^ (((~(((v695 ^ ((int)((unsigned int)((int)((unsigned int)v691 >> 2)) >> 1))) | (-(v695 ^ ((int)((unsigned int)((int)((unsigned int)v691 >> 2)) >> 1))))) >> 31)) | (~(((v696 ^ ((int)((unsigned int)((int)((unsigned int)v691 >> 2)) >> 1))) | (-(v696 ^ ((int)((unsigned int)((int)((unsigned int)v691 >> 2)) >> 1))))) >> 31))) & 104)))));
  v687->timer = v806;
  int * v699 = v687->cache_vals;
  bool v807 = !(((~(((v693 ^ ((int)((unsigned int)((int)((unsigned int)v691 >> 2)) >> 1))) | (-(v693 ^ ((int)((unsigned int)((int)((unsigned int)v691 >> 2)) >> 1))))) >> 31)) | (~(((v694 ^ ((int)((unsigned int)((int)((unsigned int)v691 >> 2)) >> 1))) | (-(v694 ^ ((int)((unsigned int)((int)((unsigned int)v691 >> 2)) >> 1))))) >> 31))) == 0);
  int v792;
  if (v807) {
    int * v700 = v687->cache_age;
    int v809 = ((((int)((unsigned int)((int)((unsigned int)v691 >> 2)) >> 1)) & 1) * 2) + ((~(((v694 ^ ((int)((unsigned int)((int)((unsigned int)v691 >> 2)) >> 1))) | (-(v694 ^ ((int)((unsigned int)((int)((unsigned int)v691 >> 2)) >> 1))))) >> 31)) & 1);
    int v701 = v700[v809];
    int v702 = v700[v802];
    int v810 = v702 + ((int)((unsigned int)(v702 - v701) >> 31));
    v700[v802] = v810;
    int * v704 = v687->cache_age;
    int v705 = v704[v803];
    int v812 = v705 + ((int)((unsigned int)(v705 - v701) >> 31));
    v704[v803] = v812;
    int * v707 = v687->cache_age;
    v707[v809] = 0;
    v792 = v809;
  } else {
    int * v710 = v687->cache_age;
    int v816 = (((int)((unsigned int)((int)((unsigned int)v691 >> 2)) >> 1)) & 1) * 2;
    int v711 = v710[v816];
    int * v712 = v687->cache_tags;
    int v713 = v712[v816];
    int v714 = v710[v803];
    int v715 = v712[v803];
    bool v818 = !(((~(((v695 ^ ((int)((unsigned int)((int)((unsigned int)v691 >> 2)) >> 1))) | (-(v695 ^ ((int)((unsigned int)((int)((unsigned int)v691 >> 2)) >> 1))))) >> 31)) | (~(((v696 ^ ((int)((unsigned int)((int)((unsigned int)v691 >> 2)) >> 1))) | (-(v696 ^ ((int)((unsigned int)((int)((unsigned int)v691 >> 2)) >> 1))))) >> 31))) == 0);
    int v769;
    if (v818) {
      int * v716 = v687->cache_age;
      int v820 = (4 + ((((int)((unsigned int)((int)((unsigned int)v691 >> 2)) >> 1)) & 3) * 2)) + ((~(((v696 ^ ((int)((unsigned int)((int)((unsigned int)v691 >> 2)) >> 1))) | (-(v696 ^ ((int)((unsigned int)((int)((unsigned int)v691 >> 2)) >> 1))))) >> 31)) & 1);
      int v717 = v716[v820];
      int v718 = v716[v804];
      int v821 = v718 + ((int)((unsigned int)(v718 - v717) >> 31));
      v716[v804] = v821;
      int * v720 = v687->cache_age;
      int v721 = v720[v805];
      int v823 = v721 + ((int)((unsigned int)(v721 - v717) >> 31));
      v720[v805] = v823;
      int * v723 = v687->cache_age;
      v723[v820] = 0;
      v769 = v820;
    } else {
      int * v726 = v687->cache_age;
      int v827 = 4 + ((((int)((unsigned int)((int)((unsigned int)v691 >> 2)) >> 1)) & 3) * 2);
      int v727 = v726[v827];
      int * v728 = v687->cache_tags;
      int v729 = v728[v827];
      int v730 = v726[v805];
      int v731 = v728[v805];
      int * v732 = v687->cache_dirty;
      int v830 = (4 + ((((int)((unsigned int)((int)((unsigned int)v691 >> 2)) >> 1)) & 3) * 2)) + ((((v727 + ((~(((v729 ^ -1) | (-(v729 ^ -1))) >> 31)) & 2)) - (v730 + ((~(((v731 ^ -1) | (-(v731 ^ -1))) >> 31)) & 2))) >> 31) & 1);
      int v733 = v732[v830];
      bool v831 = !(v733 == 0);
      if (v831) {
        int * v734 = v687->cache_tags;
        int v735 = v734[v830];
        int * v736 = v687->cache_vals;
        int v834 = ((4 + ((((int)((unsigned int)((int)((unsigned int)v691 >> 2)) >> 1)) & 3) * 2)) + ((((v727 + ((~(((v729 ^ -1) | (-(v729 ^ -1))) >> 31)) & 2)) - (v730 + ((~(((v731 ^ -1) | (-(v731 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
        int v737 = v736[v834];
        int v835 = (((4 + ((((int)((unsigned int)((int)((unsigned int)v691 >> 2)) >> 1)) & 3) * 2)) + ((((v727 + ((~(((v729 ^ -1) | (-(v729 ^ -1))) >> 31)) & 2)) - (v730 + ((~(((v731 ^ -1) | (-(v731 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
        int v738 = v736[v835];
        int * v739 = v687->mem;
        int v837 = v735 * 2;
        v739[v837] = v737;
        int * v741 = v687->mem;
        int v840 = (v735 * 2) + 1;
        v741[v840] = v738;
        ;
      } else {
        ;
      }
      int * v746 = v687->mem;
      int v845 = ((int)((unsigned int)((int)((unsigned int)v691 >> 2)) >> 1)) * 2;
      int v747 = v746[v845];
      int v846 = (((int)((unsigned int)((int)((unsigned int)v691 >> 2)) >> 1)) * 2) + 1;
      int v748 = v746[v846];
      int * v749 = v687->cache_vals;
      int v848 = ((4 + ((((int)((unsigned int)((int)((unsigned int)v691 >> 2)) >> 1)) & 3) * 2)) + ((((v727 + ((~(((v729 ^ -1) | (-(v729 ^ -1))) >> 31)) & 2)) - (v730 + ((~(((v731 ^ -1) | (-(v731 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
      v749[v848] = v747;
      int * v751 = v687->cache_vals;
      int v851 = (((4 + ((((int)((unsigned int)((int)((unsigned int)v691 >> 2)) >> 1)) & 3) * 2)) + ((((v727 + ((~(((v729 ^ -1) | (-(v729 ^ -1))) >> 31)) & 2)) - (v730 + ((~(((v731 ^ -1) | (-(v731 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
      v751[v851] = v748;
      int * v753 = v687->cache_tags;
      int v854 = (int)((unsigned int)((int)((unsigned int)v691 >> 2)) >> 1);
      v753[v830] = v854;
      int * v755 = v687->cache_dirty;
      v755[v830] = 0;
      int * v757 = v687->cache_age;
      v757[v830] = 1;
      int * v759 = v687->cache_age;
      int v760 = v759[v830];
      int v761 = v759[v804];
      int v860 = v761 + ((int)((unsigned int)(v761 - v760) >> 31));
      v759[v804] = v860;
      int * v763 = v687->cache_age;
      int v764 = v763[v805];
      int v862 = v764 + ((int)((unsigned int)(v764 - v760) >> 31));
      v763[v805] = v862;
      int * v766 = v687->cache_age;
      v766[v830] = 0;
      v769 = v830;
    }
    int * v770 = v687->cache_vals;
    int v865 = v769 * 2;
    int v771 = v770[v865];
    int v866 = (v769 * 2) + 1;
    int v772 = v770[v866];
    int v867 = (((((int)((unsigned int)((int)((unsigned int)v691 >> 2)) >> 1)) & 1) * 2) + ((((v711 + ((~(((v713 ^ -1) | (-(v713 ^ -1))) >> 31)) & 2)) - (v714 + ((~(((v715 ^ -1) | (-(v715 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
    v770[v867] = v771;
    int * v774 = v687->cache_vals;
    int v870 = ((((((int)((unsigned int)((int)((unsigned int)v691 >> 2)) >> 1)) & 1) * 2) + ((((v711 + ((~(((v713 ^ -1) | (-(v713 ^ -1))) >> 31)) & 2)) - (v714 + ((~(((v715 ^ -1) | (-(v715 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
    v774[v870] = v772;
    int * v776 = v687->cache_tags;
    int v873 = ((((int)((unsigned int)((int)((unsigned int)v691 >> 2)) >> 1)) & 1) * 2) + ((((v711 + ((~(((v713 ^ -1) | (-(v713 ^ -1))) >> 31)) & 2)) - (v714 + ((~(((v715 ^ -1) | (-(v715 ^ -1))) >> 31)) & 2))) >> 31) & 1);
    int v874 = (int)((unsigned int)((int)((unsigned int)v691 >> 2)) >> 1);
    v776[v873] = v874;
    int * v778 = v687->cache_dirty;
    v778[v873] = 0;
    int * v780 = v687->cache_age;
    v780[v873] = 1;
    int * v782 = v687->cache_age;
    int v783 = v782[v873];
    int v784 = v782[v802];
    int v880 = v784 + ((int)((unsigned int)(v784 - v783) >> 31));
    v782[v802] = v880;
    int * v786 = v687->cache_age;
    int v787 = v786[v803];
    int v882 = v787 + ((int)((unsigned int)(v787 - v783) >> 31));
    v786[v803] = v882;
    int * v789 = v687->cache_age;
    v789[v873] = 0;
    v792 = v873;
  }
  int v885 = (v792 * 2) + (((int)((unsigned int)v691 >> 2)) & 1);
  int v793 = v699[v885];
  int * v794 = v687->regs;
  v794[10] = v793;
  struct StateT * v796 = slot_23(v687);
  return v796;
}

struct StateT * slot_31(struct StateT * v1698) {
  int v1699 = v1698->timer;
  int v1706 = v1699 + 1;
  v1698->timer = v1706;
  int * v1701 = v1698->regs;
  int v1702 = v1701[10];
  int v1709 = (int)((unsigned int)v1702 >> 26);
  v1701[10] = v1709;
  struct StateT * v1704 = slot_33(v1698);
  return v1704;
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

struct StateT * slot_26(struct StateT * v1136) {
  int v1137 = v1136->timer;
  int v1247 = v1137 + 1;
  v1136->timer = v1247;
  int * v1139 = v1136->regs;
  int v1140 = v1139[12];
  int * v1141 = v1136->cache_tags;
  int v1251 = (((int)((unsigned int)((int)((unsigned int)(v1140 + 68) >> 2)) >> 1)) & 1) * 2;
  int v1142 = v1141[v1251];
  int v1252 = ((((int)((unsigned int)((int)((unsigned int)(v1140 + 68) >> 2)) >> 1)) & 1) * 2) + 1;
  int v1143 = v1141[v1252];
  int v1253 = 4 + ((((int)((unsigned int)((int)((unsigned int)(v1140 + 68) >> 2)) >> 1)) & 3) * 2);
  int v1144 = v1141[v1253];
  int v1254 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v1140 + 68) >> 2)) >> 1)) & 3) * 2)) + 1;
  int v1145 = v1141[v1254];
  int v1146 = v1136->timer;
  int v1255 = v1146 + ((100 ^ (((~(((v1144 ^ ((int)((unsigned int)((int)((unsigned int)(v1140 + 68) >> 2)) >> 1))) | (-(v1144 ^ ((int)((unsigned int)((int)((unsigned int)(v1140 + 68) >> 2)) >> 1))))) >> 31)) | (~(((v1145 ^ ((int)((unsigned int)((int)((unsigned int)(v1140 + 68) >> 2)) >> 1))) | (-(v1145 ^ ((int)((unsigned int)((int)((unsigned int)(v1140 + 68) >> 2)) >> 1))))) >> 31))) & 104)) ^ (((~(((v1142 ^ ((int)((unsigned int)((int)((unsigned int)(v1140 + 68) >> 2)) >> 1))) | (-(v1142 ^ ((int)((unsigned int)((int)((unsigned int)(v1140 + 68) >> 2)) >> 1))))) >> 31)) | (~(((v1143 ^ ((int)((unsigned int)((int)((unsigned int)(v1140 + 68) >> 2)) >> 1))) | (-(v1143 ^ ((int)((unsigned int)((int)((unsigned int)(v1140 + 68) >> 2)) >> 1))))) >> 31))) & (1 ^ (100 ^ (((~(((v1144 ^ ((int)((unsigned int)((int)((unsigned int)(v1140 + 68) >> 2)) >> 1))) | (-(v1144 ^ ((int)((unsigned int)((int)((unsigned int)(v1140 + 68) >> 2)) >> 1))))) >> 31)) | (~(((v1145 ^ ((int)((unsigned int)((int)((unsigned int)(v1140 + 68) >> 2)) >> 1))) | (-(v1145 ^ ((int)((unsigned int)((int)((unsigned int)(v1140 + 68) >> 2)) >> 1))))) >> 31))) & 104)))));
  v1136->timer = v1255;
  int * v1148 = v1136->cache_vals;
  bool v1256 = !(((~(((v1142 ^ ((int)((unsigned int)((int)((unsigned int)(v1140 + 68) >> 2)) >> 1))) | (-(v1142 ^ ((int)((unsigned int)((int)((unsigned int)(v1140 + 68) >> 2)) >> 1))))) >> 31)) | (~(((v1143 ^ ((int)((unsigned int)((int)((unsigned int)(v1140 + 68) >> 2)) >> 1))) | (-(v1143 ^ ((int)((unsigned int)((int)((unsigned int)(v1140 + 68) >> 2)) >> 1))))) >> 31))) == 0);
  int v1241;
  if (v1256) {
    int * v1149 = v1136->cache_age;
    int v1258 = ((((int)((unsigned int)((int)((unsigned int)(v1140 + 68) >> 2)) >> 1)) & 1) * 2) + ((~(((v1143 ^ ((int)((unsigned int)((int)((unsigned int)(v1140 + 68) >> 2)) >> 1))) | (-(v1143 ^ ((int)((unsigned int)((int)((unsigned int)(v1140 + 68) >> 2)) >> 1))))) >> 31)) & 1);
    int v1150 = v1149[v1258];
    int v1151 = v1149[v1251];
    int v1259 = v1151 + ((int)((unsigned int)(v1151 - v1150) >> 31));
    v1149[v1251] = v1259;
    int * v1153 = v1136->cache_age;
    int v1154 = v1153[v1252];
    int v1261 = v1154 + ((int)((unsigned int)(v1154 - v1150) >> 31));
    v1153[v1252] = v1261;
    int * v1156 = v1136->cache_age;
    v1156[v1258] = 0;
    v1241 = v1258;
  } else {
    int * v1159 = v1136->cache_age;
    int v1265 = (((int)((unsigned int)((int)((unsigned int)(v1140 + 68) >> 2)) >> 1)) & 1) * 2;
    int v1160 = v1159[v1265];
    int * v1161 = v1136->cache_tags;
    int v1162 = v1161[v1265];
    int v1163 = v1159[v1252];
    int v1164 = v1161[v1252];
    bool v1267 = !(((~(((v1144 ^ ((int)((unsigned int)((int)((unsigned int)(v1140 + 68) >> 2)) >> 1))) | (-(v1144 ^ ((int)((unsigned int)((int)((unsigned int)(v1140 + 68) >> 2)) >> 1))))) >> 31)) | (~(((v1145 ^ ((int)((unsigned int)((int)((unsigned int)(v1140 + 68) >> 2)) >> 1))) | (-(v1145 ^ ((int)((unsigned int)((int)((unsigned int)(v1140 + 68) >> 2)) >> 1))))) >> 31))) == 0);
    int v1218;
    if (v1267) {
      int * v1165 = v1136->cache_age;
      int v1269 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v1140 + 68) >> 2)) >> 1)) & 3) * 2)) + ((~(((v1145 ^ ((int)((unsigned int)((int)((unsigned int)(v1140 + 68) >> 2)) >> 1))) | (-(v1145 ^ ((int)((unsigned int)((int)((unsigned int)(v1140 + 68) >> 2)) >> 1))))) >> 31)) & 1);
      int v1166 = v1165[v1269];
      int v1167 = v1165[v1253];
      int v1270 = v1167 + ((int)((unsigned int)(v1167 - v1166) >> 31));
      v1165[v1253] = v1270;
      int * v1169 = v1136->cache_age;
      int v1170 = v1169[v1254];
      int v1272 = v1170 + ((int)((unsigned int)(v1170 - v1166) >> 31));
      v1169[v1254] = v1272;
      int * v1172 = v1136->cache_age;
      v1172[v1269] = 0;
      v1218 = v1269;
    } else {
      int * v1175 = v1136->cache_age;
      int v1276 = 4 + ((((int)((unsigned int)((int)((unsigned int)(v1140 + 68) >> 2)) >> 1)) & 3) * 2);
      int v1176 = v1175[v1276];
      int * v1177 = v1136->cache_tags;
      int v1178 = v1177[v1276];
      int v1179 = v1175[v1254];
      int v1180 = v1177[v1254];
      int * v1181 = v1136->cache_dirty;
      int v1279 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v1140 + 68) >> 2)) >> 1)) & 3) * 2)) + ((((v1176 + ((~(((v1178 ^ -1) | (-(v1178 ^ -1))) >> 31)) & 2)) - (v1179 + ((~(((v1180 ^ -1) | (-(v1180 ^ -1))) >> 31)) & 2))) >> 31) & 1);
      int v1182 = v1181[v1279];
      bool v1280 = !(v1182 == 0);
      if (v1280) {
        int * v1183 = v1136->cache_tags;
        int v1184 = v1183[v1279];
        int * v1185 = v1136->cache_vals;
        int v1283 = ((4 + ((((int)((unsigned int)((int)((unsigned int)(v1140 + 68) >> 2)) >> 1)) & 3) * 2)) + ((((v1176 + ((~(((v1178 ^ -1) | (-(v1178 ^ -1))) >> 31)) & 2)) - (v1179 + ((~(((v1180 ^ -1) | (-(v1180 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
        int v1186 = v1185[v1283];
        int v1284 = (((4 + ((((int)((unsigned int)((int)((unsigned int)(v1140 + 68) >> 2)) >> 1)) & 3) * 2)) + ((((v1176 + ((~(((v1178 ^ -1) | (-(v1178 ^ -1))) >> 31)) & 2)) - (v1179 + ((~(((v1180 ^ -1) | (-(v1180 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
        int v1187 = v1185[v1284];
        int * v1188 = v1136->mem;
        int v1286 = v1184 * 2;
        v1188[v1286] = v1186;
        int * v1190 = v1136->mem;
        int v1289 = (v1184 * 2) + 1;
        v1190[v1289] = v1187;
        ;
      } else {
        ;
      }
      int * v1195 = v1136->mem;
      int v1294 = ((int)((unsigned int)((int)((unsigned int)(v1140 + 68) >> 2)) >> 1)) * 2;
      int v1196 = v1195[v1294];
      int v1295 = (((int)((unsigned int)((int)((unsigned int)(v1140 + 68) >> 2)) >> 1)) * 2) + 1;
      int v1197 = v1195[v1295];
      int * v1198 = v1136->cache_vals;
      int v1297 = ((4 + ((((int)((unsigned int)((int)((unsigned int)(v1140 + 68) >> 2)) >> 1)) & 3) * 2)) + ((((v1176 + ((~(((v1178 ^ -1) | (-(v1178 ^ -1))) >> 31)) & 2)) - (v1179 + ((~(((v1180 ^ -1) | (-(v1180 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
      v1198[v1297] = v1196;
      int * v1200 = v1136->cache_vals;
      int v1300 = (((4 + ((((int)((unsigned int)((int)((unsigned int)(v1140 + 68) >> 2)) >> 1)) & 3) * 2)) + ((((v1176 + ((~(((v1178 ^ -1) | (-(v1178 ^ -1))) >> 31)) & 2)) - (v1179 + ((~(((v1180 ^ -1) | (-(v1180 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
      v1200[v1300] = v1197;
      int * v1202 = v1136->cache_tags;
      int v1303 = (int)((unsigned int)((int)((unsigned int)(v1140 + 68) >> 2)) >> 1);
      v1202[v1279] = v1303;
      int * v1204 = v1136->cache_dirty;
      v1204[v1279] = 0;
      int * v1206 = v1136->cache_age;
      v1206[v1279] = 1;
      int * v1208 = v1136->cache_age;
      int v1209 = v1208[v1279];
      int v1210 = v1208[v1253];
      int v1309 = v1210 + ((int)((unsigned int)(v1210 - v1209) >> 31));
      v1208[v1253] = v1309;
      int * v1212 = v1136->cache_age;
      int v1213 = v1212[v1254];
      int v1311 = v1213 + ((int)((unsigned int)(v1213 - v1209) >> 31));
      v1212[v1254] = v1311;
      int * v1215 = v1136->cache_age;
      v1215[v1279] = 0;
      v1218 = v1279;
    }
    int * v1219 = v1136->cache_vals;
    int v1314 = v1218 * 2;
    int v1220 = v1219[v1314];
    int v1315 = (v1218 * 2) + 1;
    int v1221 = v1219[v1315];
    int v1316 = (((((int)((unsigned int)((int)((unsigned int)(v1140 + 68) >> 2)) >> 1)) & 1) * 2) + ((((v1160 + ((~(((v1162 ^ -1) | (-(v1162 ^ -1))) >> 31)) & 2)) - (v1163 + ((~(((v1164 ^ -1) | (-(v1164 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
    v1219[v1316] = v1220;
    int * v1223 = v1136->cache_vals;
    int v1319 = ((((((int)((unsigned int)((int)((unsigned int)(v1140 + 68) >> 2)) >> 1)) & 1) * 2) + ((((v1160 + ((~(((v1162 ^ -1) | (-(v1162 ^ -1))) >> 31)) & 2)) - (v1163 + ((~(((v1164 ^ -1) | (-(v1164 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
    v1223[v1319] = v1221;
    int * v1225 = v1136->cache_tags;
    int v1322 = ((((int)((unsigned int)((int)((unsigned int)(v1140 + 68) >> 2)) >> 1)) & 1) * 2) + ((((v1160 + ((~(((v1162 ^ -1) | (-(v1162 ^ -1))) >> 31)) & 2)) - (v1163 + ((~(((v1164 ^ -1) | (-(v1164 ^ -1))) >> 31)) & 2))) >> 31) & 1);
    int v1323 = (int)((unsigned int)((int)((unsigned int)(v1140 + 68) >> 2)) >> 1);
    v1225[v1322] = v1323;
    int * v1227 = v1136->cache_dirty;
    v1227[v1322] = 0;
    int * v1229 = v1136->cache_age;
    v1229[v1322] = 1;
    int * v1231 = v1136->cache_age;
    int v1232 = v1231[v1322];
    int v1233 = v1231[v1251];
    int v1329 = v1233 + ((int)((unsigned int)(v1233 - v1232) >> 31));
    v1231[v1251] = v1329;
    int * v1235 = v1136->cache_age;
    int v1236 = v1235[v1252];
    int v1331 = v1236 + ((int)((unsigned int)(v1236 - v1232) >> 31));
    v1235[v1252] = v1331;
    int * v1238 = v1136->cache_age;
    v1238[v1322] = 0;
    v1241 = v1322;
  }
  int v1334 = (v1241 * 2) + (((int)((unsigned int)(v1140 + 68) >> 2)) & 1);
  int v1242 = v1148[v1334];
  int * v1243 = v1136->regs;
  v1243[11] = v1242;
  struct StateT * v1245 = slot_28(v1136);
  return v1245;
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

struct StateT * slot_13(struct StateT * v581) {
  int v582 = v581->timer;
  int v590 = v582 + 1;
  v581->timer = v590;
  int * v584 = v581->regs;
  int v585 = v584[11];
  int v586 = v584[10];
  int v594 = v585 + v586;
  v584[10] = v594;
  struct StateT * v588 = slot_15(v581);
  return v588;
}

struct StateT * slot_38(struct StateT * v2156) {
  int v2157 = v2156->timer;
  int v2327 = v2157 + 1;
  v2156->timer = v2327;
  int * v2159 = v2156->regs;
  int v2160 = v2159[12];
  int v2161 = v2159[10];
  int * v2162 = v2156->cache_tags;
  int v2332 = (((int)((unsigned int)((int)((unsigned int)(v2160 + 68) >> 2)) >> 1)) & 1) * 2;
  int v2163 = v2162[v2332];
  int v2333 = ((((int)((unsigned int)((int)((unsigned int)(v2160 + 68) >> 2)) >> 1)) & 1) * 2) + 1;
  int v2164 = v2162[v2333];
  int v2334 = 4 + ((((int)((unsigned int)((int)((unsigned int)(v2160 + 68) >> 2)) >> 1)) & 3) * 2);
  int v2165 = v2162[v2334];
  int v2335 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v2160 + 68) >> 2)) >> 1)) & 3) * 2)) + 1;
  int v2166 = v2162[v2335];
  int v2167 = v2156->timer;
  int v2336 = v2167 + ((100 ^ (((~(((v2165 ^ ((int)((unsigned int)((int)((unsigned int)(v2160 + 68) >> 2)) >> 1))) | (-(v2165 ^ ((int)((unsigned int)((int)((unsigned int)(v2160 + 68) >> 2)) >> 1))))) >> 31)) | (~(((v2166 ^ ((int)((unsigned int)((int)((unsigned int)(v2160 + 68) >> 2)) >> 1))) | (-(v2166 ^ ((int)((unsigned int)((int)((unsigned int)(v2160 + 68) >> 2)) >> 1))))) >> 31))) & 104)) ^ (((~(((v2163 ^ ((int)((unsigned int)((int)((unsigned int)(v2160 + 68) >> 2)) >> 1))) | (-(v2163 ^ ((int)((unsigned int)((int)((unsigned int)(v2160 + 68) >> 2)) >> 1))))) >> 31)) | (~(((v2164 ^ ((int)((unsigned int)((int)((unsigned int)(v2160 + 68) >> 2)) >> 1))) | (-(v2164 ^ ((int)((unsigned int)((int)((unsigned int)(v2160 + 68) >> 2)) >> 1))))) >> 31))) & (1 ^ (100 ^ (((~(((v2165 ^ ((int)((unsigned int)((int)((unsigned int)(v2160 + 68) >> 2)) >> 1))) | (-(v2165 ^ ((int)((unsigned int)((int)((unsigned int)(v2160 + 68) >> 2)) >> 1))))) >> 31)) | (~(((v2166 ^ ((int)((unsigned int)((int)((unsigned int)(v2160 + 68) >> 2)) >> 1))) | (-(v2166 ^ ((int)((unsigned int)((int)((unsigned int)(v2160 + 68) >> 2)) >> 1))))) >> 31))) & 104)))));
  v2156->timer = v2336;
  bool v2337 = !(((~(((v2163 ^ ((int)((unsigned int)((int)((unsigned int)(v2160 + 68) >> 2)) >> 1))) | (-(v2163 ^ ((int)((unsigned int)((int)((unsigned int)(v2160 + 68) >> 2)) >> 1))))) >> 31)) | (~(((v2164 ^ ((int)((unsigned int)((int)((unsigned int)(v2160 + 68) >> 2)) >> 1))) | (-(v2164 ^ ((int)((unsigned int)((int)((unsigned int)(v2160 + 68) >> 2)) >> 1))))) >> 31))) == 0);
  int v2261;
  if (v2337) {
    int * v2169 = v2156->cache_age;
    int v2339 = ((((int)((unsigned int)((int)((unsigned int)(v2160 + 68) >> 2)) >> 1)) & 1) * 2) + ((~(((v2164 ^ ((int)((unsigned int)((int)((unsigned int)(v2160 + 68) >> 2)) >> 1))) | (-(v2164 ^ ((int)((unsigned int)((int)((unsigned int)(v2160 + 68) >> 2)) >> 1))))) >> 31)) & 1);
    int v2170 = v2169[v2339];
    int v2171 = v2169[v2332];
    int v2340 = v2171 + ((int)((unsigned int)(v2171 - v2170) >> 31));
    v2169[v2332] = v2340;
    int * v2173 = v2156->cache_age;
    int v2174 = v2173[v2333];
    int v2342 = v2174 + ((int)((unsigned int)(v2174 - v2170) >> 31));
    v2173[v2333] = v2342;
    int * v2176 = v2156->cache_age;
    v2176[v2339] = 0;
    v2261 = v2339;
  } else {
    int * v2179 = v2156->cache_age;
    int v2346 = (((int)((unsigned int)((int)((unsigned int)(v2160 + 68) >> 2)) >> 1)) & 1) * 2;
    int v2180 = v2179[v2346];
    int * v2181 = v2156->cache_tags;
    int v2182 = v2181[v2346];
    int v2183 = v2179[v2333];
    int v2184 = v2181[v2333];
    bool v2348 = !(((~(((v2165 ^ ((int)((unsigned int)((int)((unsigned int)(v2160 + 68) >> 2)) >> 1))) | (-(v2165 ^ ((int)((unsigned int)((int)((unsigned int)(v2160 + 68) >> 2)) >> 1))))) >> 31)) | (~(((v2166 ^ ((int)((unsigned int)((int)((unsigned int)(v2160 + 68) >> 2)) >> 1))) | (-(v2166 ^ ((int)((unsigned int)((int)((unsigned int)(v2160 + 68) >> 2)) >> 1))))) >> 31))) == 0);
    int v2238;
    if (v2348) {
      int * v2185 = v2156->cache_age;
      int v2350 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v2160 + 68) >> 2)) >> 1)) & 3) * 2)) + ((~(((v2166 ^ ((int)((unsigned int)((int)((unsigned int)(v2160 + 68) >> 2)) >> 1))) | (-(v2166 ^ ((int)((unsigned int)((int)((unsigned int)(v2160 + 68) >> 2)) >> 1))))) >> 31)) & 1);
      int v2186 = v2185[v2350];
      int v2187 = v2185[v2334];
      int v2351 = v2187 + ((int)((unsigned int)(v2187 - v2186) >> 31));
      v2185[v2334] = v2351;
      int * v2189 = v2156->cache_age;
      int v2190 = v2189[v2335];
      int v2353 = v2190 + ((int)((unsigned int)(v2190 - v2186) >> 31));
      v2189[v2335] = v2353;
      int * v2192 = v2156->cache_age;
      v2192[v2350] = 0;
      v2238 = v2350;
    } else {
      int * v2195 = v2156->cache_age;
      int v2357 = 4 + ((((int)((unsigned int)((int)((unsigned int)(v2160 + 68) >> 2)) >> 1)) & 3) * 2);
      int v2196 = v2195[v2357];
      int * v2197 = v2156->cache_tags;
      int v2198 = v2197[v2357];
      int v2199 = v2195[v2335];
      int v2200 = v2197[v2335];
      int * v2201 = v2156->cache_dirty;
      int v2360 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v2160 + 68) >> 2)) >> 1)) & 3) * 2)) + ((((v2196 + ((~(((v2198 ^ -1) | (-(v2198 ^ -1))) >> 31)) & 2)) - (v2199 + ((~(((v2200 ^ -1) | (-(v2200 ^ -1))) >> 31)) & 2))) >> 31) & 1);
      int v2202 = v2201[v2360];
      bool v2361 = !(v2202 == 0);
      if (v2361) {
        int * v2203 = v2156->cache_tags;
        int v2204 = v2203[v2360];
        int * v2205 = v2156->cache_vals;
        int v2364 = ((4 + ((((int)((unsigned int)((int)((unsigned int)(v2160 + 68) >> 2)) >> 1)) & 3) * 2)) + ((((v2196 + ((~(((v2198 ^ -1) | (-(v2198 ^ -1))) >> 31)) & 2)) - (v2199 + ((~(((v2200 ^ -1) | (-(v2200 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
        int v2206 = v2205[v2364];
        int v2365 = (((4 + ((((int)((unsigned int)((int)((unsigned int)(v2160 + 68) >> 2)) >> 1)) & 3) * 2)) + ((((v2196 + ((~(((v2198 ^ -1) | (-(v2198 ^ -1))) >> 31)) & 2)) - (v2199 + ((~(((v2200 ^ -1) | (-(v2200 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
        int v2207 = v2205[v2365];
        int * v2208 = v2156->mem;
        int v2367 = v2204 * 2;
        v2208[v2367] = v2206;
        int * v2210 = v2156->mem;
        int v2370 = (v2204 * 2) + 1;
        v2210[v2370] = v2207;
        ;
      } else {
        ;
      }
      int * v2215 = v2156->mem;
      int v2375 = ((int)((unsigned int)((int)((unsigned int)(v2160 + 68) >> 2)) >> 1)) * 2;
      int v2216 = v2215[v2375];
      int v2376 = (((int)((unsigned int)((int)((unsigned int)(v2160 + 68) >> 2)) >> 1)) * 2) + 1;
      int v2217 = v2215[v2376];
      int * v2218 = v2156->cache_vals;
      int v2378 = ((4 + ((((int)((unsigned int)((int)((unsigned int)(v2160 + 68) >> 2)) >> 1)) & 3) * 2)) + ((((v2196 + ((~(((v2198 ^ -1) | (-(v2198 ^ -1))) >> 31)) & 2)) - (v2199 + ((~(((v2200 ^ -1) | (-(v2200 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
      v2218[v2378] = v2216;
      int * v2220 = v2156->cache_vals;
      int v2381 = (((4 + ((((int)((unsigned int)((int)((unsigned int)(v2160 + 68) >> 2)) >> 1)) & 3) * 2)) + ((((v2196 + ((~(((v2198 ^ -1) | (-(v2198 ^ -1))) >> 31)) & 2)) - (v2199 + ((~(((v2200 ^ -1) | (-(v2200 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
      v2220[v2381] = v2217;
      int * v2222 = v2156->cache_tags;
      int v2384 = (int)((unsigned int)((int)((unsigned int)(v2160 + 68) >> 2)) >> 1);
      v2222[v2360] = v2384;
      int * v2224 = v2156->cache_dirty;
      v2224[v2360] = 0;
      int * v2226 = v2156->cache_age;
      v2226[v2360] = 1;
      int * v2228 = v2156->cache_age;
      int v2229 = v2228[v2360];
      int v2230 = v2228[v2334];
      int v2390 = v2230 + ((int)((unsigned int)(v2230 - v2229) >> 31));
      v2228[v2334] = v2390;
      int * v2232 = v2156->cache_age;
      int v2233 = v2232[v2335];
      int v2392 = v2233 + ((int)((unsigned int)(v2233 - v2229) >> 31));
      v2232[v2335] = v2392;
      int * v2235 = v2156->cache_age;
      v2235[v2360] = 0;
      v2238 = v2360;
    }
    int * v2239 = v2156->cache_vals;
    int v2395 = v2238 * 2;
    int v2240 = v2239[v2395];
    int v2396 = (v2238 * 2) + 1;
    int v2241 = v2239[v2396];
    int v2397 = (((((int)((unsigned int)((int)((unsigned int)(v2160 + 68) >> 2)) >> 1)) & 1) * 2) + ((((v2180 + ((~(((v2182 ^ -1) | (-(v2182 ^ -1))) >> 31)) & 2)) - (v2183 + ((~(((v2184 ^ -1) | (-(v2184 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
    v2239[v2397] = v2240;
    int * v2243 = v2156->cache_vals;
    int v2400 = ((((((int)((unsigned int)((int)((unsigned int)(v2160 + 68) >> 2)) >> 1)) & 1) * 2) + ((((v2180 + ((~(((v2182 ^ -1) | (-(v2182 ^ -1))) >> 31)) & 2)) - (v2183 + ((~(((v2184 ^ -1) | (-(v2184 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
    v2243[v2400] = v2241;
    int * v2245 = v2156->cache_tags;
    int v2403 = ((((int)((unsigned int)((int)((unsigned int)(v2160 + 68) >> 2)) >> 1)) & 1) * 2) + ((((v2180 + ((~(((v2182 ^ -1) | (-(v2182 ^ -1))) >> 31)) & 2)) - (v2183 + ((~(((v2184 ^ -1) | (-(v2184 ^ -1))) >> 31)) & 2))) >> 31) & 1);
    int v2404 = (int)((unsigned int)((int)((unsigned int)(v2160 + 68) >> 2)) >> 1);
    v2245[v2403] = v2404;
    int * v2247 = v2156->cache_dirty;
    v2247[v2403] = 0;
    int * v2249 = v2156->cache_age;
    v2249[v2403] = 1;
    int * v2251 = v2156->cache_age;
    int v2252 = v2251[v2403];
    int v2253 = v2251[v2332];
    int v2410 = v2253 + ((int)((unsigned int)(v2253 - v2252) >> 31));
    v2251[v2332] = v2410;
    int * v2255 = v2156->cache_age;
    int v2256 = v2255[v2333];
    int v2412 = v2256 + ((int)((unsigned int)(v2256 - v2252) >> 31));
    v2255[v2333] = v2412;
    int * v2258 = v2156->cache_age;
    v2258[v2403] = 0;
    v2261 = v2403;
  }
  int * v2262 = v2156->cache_vals;
  int v2415 = (v2261 * 2) + (((int)((unsigned int)(v2160 + 68) >> 2)) & 1);
  v2262[v2415] = v2161;
  int * v2264 = v2156->cache_tags;
  int v2265 = v2264[v2334];
  int v2266 = v2264[v2335];
  bool v2418 = !(((~(((v2265 ^ ((int)((unsigned int)((int)((unsigned int)(v2160 + 68) >> 2)) >> 1))) | (-(v2265 ^ ((int)((unsigned int)((int)((unsigned int)(v2160 + 68) >> 2)) >> 1))))) >> 31)) | (~(((v2266 ^ ((int)((unsigned int)((int)((unsigned int)(v2160 + 68) >> 2)) >> 1))) | (-(v2266 ^ ((int)((unsigned int)((int)((unsigned int)(v2160 + 68) >> 2)) >> 1))))) >> 31))) == 0);
  int v2320;
  if (v2418) {
    int * v2267 = v2156->cache_age;
    int v2420 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v2160 + 68) >> 2)) >> 1)) & 3) * 2)) + ((~(((v2266 ^ ((int)((unsigned int)((int)((unsigned int)(v2160 + 68) >> 2)) >> 1))) | (-(v2266 ^ ((int)((unsigned int)((int)((unsigned int)(v2160 + 68) >> 2)) >> 1))))) >> 31)) & 1);
    int v2268 = v2267[v2420];
    int v2269 = v2267[v2334];
    int v2421 = v2269 + ((int)((unsigned int)(v2269 - v2268) >> 31));
    v2267[v2334] = v2421;
    int * v2271 = v2156->cache_age;
    int v2272 = v2271[v2335];
    int v2423 = v2272 + ((int)((unsigned int)(v2272 - v2268) >> 31));
    v2271[v2335] = v2423;
    int * v2274 = v2156->cache_age;
    v2274[v2420] = 0;
    v2320 = v2420;
  } else {
    int * v2277 = v2156->cache_age;
    int v2427 = 4 + ((((int)((unsigned int)((int)((unsigned int)(v2160 + 68) >> 2)) >> 1)) & 3) * 2);
    int v2278 = v2277[v2427];
    int * v2279 = v2156->cache_tags;
    int v2280 = v2279[v2427];
    int v2281 = v2277[v2335];
    int v2282 = v2279[v2335];
    int * v2283 = v2156->cache_dirty;
    int v2430 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v2160 + 68) >> 2)) >> 1)) & 3) * 2)) + ((((v2278 + ((~(((v2280 ^ -1) | (-(v2280 ^ -1))) >> 31)) & 2)) - (v2281 + ((~(((v2282 ^ -1) | (-(v2282 ^ -1))) >> 31)) & 2))) >> 31) & 1);
    int v2284 = v2283[v2430];
    bool v2431 = !(v2284 == 0);
    if (v2431) {
      int * v2285 = v2156->cache_tags;
      int v2286 = v2285[v2430];
      int * v2287 = v2156->cache_vals;
      int v2434 = ((4 + ((((int)((unsigned int)((int)((unsigned int)(v2160 + 68) >> 2)) >> 1)) & 3) * 2)) + ((((v2278 + ((~(((v2280 ^ -1) | (-(v2280 ^ -1))) >> 31)) & 2)) - (v2281 + ((~(((v2282 ^ -1) | (-(v2282 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
      int v2288 = v2287[v2434];
      int v2435 = (((4 + ((((int)((unsigned int)((int)((unsigned int)(v2160 + 68) >> 2)) >> 1)) & 3) * 2)) + ((((v2278 + ((~(((v2280 ^ -1) | (-(v2280 ^ -1))) >> 31)) & 2)) - (v2281 + ((~(((v2282 ^ -1) | (-(v2282 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
      int v2289 = v2287[v2435];
      int * v2290 = v2156->mem;
      int v2437 = v2286 * 2;
      v2290[v2437] = v2288;
      int * v2292 = v2156->mem;
      int v2440 = (v2286 * 2) + 1;
      v2292[v2440] = v2289;
      ;
    } else {
      ;
    }
    int * v2297 = v2156->mem;
    int v2445 = ((int)((unsigned int)((int)((unsigned int)(v2160 + 68) >> 2)) >> 1)) * 2;
    int v2298 = v2297[v2445];
    int v2446 = (((int)((unsigned int)((int)((unsigned int)(v2160 + 68) >> 2)) >> 1)) * 2) + 1;
    int v2299 = v2297[v2446];
    int * v2300 = v2156->cache_vals;
    int v2448 = ((4 + ((((int)((unsigned int)((int)((unsigned int)(v2160 + 68) >> 2)) >> 1)) & 3) * 2)) + ((((v2278 + ((~(((v2280 ^ -1) | (-(v2280 ^ -1))) >> 31)) & 2)) - (v2281 + ((~(((v2282 ^ -1) | (-(v2282 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
    v2300[v2448] = v2298;
    int * v2302 = v2156->cache_vals;
    int v2451 = (((4 + ((((int)((unsigned int)((int)((unsigned int)(v2160 + 68) >> 2)) >> 1)) & 3) * 2)) + ((((v2278 + ((~(((v2280 ^ -1) | (-(v2280 ^ -1))) >> 31)) & 2)) - (v2281 + ((~(((v2282 ^ -1) | (-(v2282 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
    v2302[v2451] = v2299;
    int * v2304 = v2156->cache_tags;
    int v2454 = (int)((unsigned int)((int)((unsigned int)(v2160 + 68) >> 2)) >> 1);
    v2304[v2430] = v2454;
    int * v2306 = v2156->cache_dirty;
    v2306[v2430] = 0;
    int * v2308 = v2156->cache_age;
    v2308[v2430] = 1;
    int * v2310 = v2156->cache_age;
    int v2311 = v2310[v2430];
    int v2312 = v2310[v2334];
    int v2460 = v2312 + ((int)((unsigned int)(v2312 - v2311) >> 31));
    v2310[v2334] = v2460;
    int * v2314 = v2156->cache_age;
    int v2315 = v2314[v2335];
    int v2462 = v2315 + ((int)((unsigned int)(v2315 - v2311) >> 31));
    v2314[v2335] = v2462;
    int * v2317 = v2156->cache_age;
    v2317[v2430] = 0;
    v2320 = v2430;
  }
  int * v2321 = v2156->cache_vals;
  int v2465 = (v2320 * 2) + (((int)((unsigned int)(v2160 + 68) >> 2)) & 1);
  v2321[v2465] = v2161;
  int * v2323 = v2156->cache_dirty;
  v2323[v2320] = 1;
  struct StateT * v2325 = slot_32(v2156);
  return v2325;
}

struct StateT * slot_24(struct StateT * v919) {
  int v920 = v919->timer;
  int v1030 = v920 + 1;
  v919->timer = v1030;
  int * v922 = v919->regs;
  int v923 = v922[10];
  int * v924 = v919->cache_tags;
  int v1034 = (((int)((unsigned int)((int)((unsigned int)v923 >> 2)) >> 1)) & 1) * 2;
  int v925 = v924[v1034];
  int v1035 = ((((int)((unsigned int)((int)((unsigned int)v923 >> 2)) >> 1)) & 1) * 2) + 1;
  int v926 = v924[v1035];
  int v1036 = 4 + ((((int)((unsigned int)((int)((unsigned int)v923 >> 2)) >> 1)) & 3) * 2);
  int v927 = v924[v1036];
  int v1037 = (4 + ((((int)((unsigned int)((int)((unsigned int)v923 >> 2)) >> 1)) & 3) * 2)) + 1;
  int v928 = v924[v1037];
  int v929 = v919->timer;
  int v1038 = v929 + ((100 ^ (((~(((v927 ^ ((int)((unsigned int)((int)((unsigned int)v923 >> 2)) >> 1))) | (-(v927 ^ ((int)((unsigned int)((int)((unsigned int)v923 >> 2)) >> 1))))) >> 31)) | (~(((v928 ^ ((int)((unsigned int)((int)((unsigned int)v923 >> 2)) >> 1))) | (-(v928 ^ ((int)((unsigned int)((int)((unsigned int)v923 >> 2)) >> 1))))) >> 31))) & 104)) ^ (((~(((v925 ^ ((int)((unsigned int)((int)((unsigned int)v923 >> 2)) >> 1))) | (-(v925 ^ ((int)((unsigned int)((int)((unsigned int)v923 >> 2)) >> 1))))) >> 31)) | (~(((v926 ^ ((int)((unsigned int)((int)((unsigned int)v923 >> 2)) >> 1))) | (-(v926 ^ ((int)((unsigned int)((int)((unsigned int)v923 >> 2)) >> 1))))) >> 31))) & (1 ^ (100 ^ (((~(((v927 ^ ((int)((unsigned int)((int)((unsigned int)v923 >> 2)) >> 1))) | (-(v927 ^ ((int)((unsigned int)((int)((unsigned int)v923 >> 2)) >> 1))))) >> 31)) | (~(((v928 ^ ((int)((unsigned int)((int)((unsigned int)v923 >> 2)) >> 1))) | (-(v928 ^ ((int)((unsigned int)((int)((unsigned int)v923 >> 2)) >> 1))))) >> 31))) & 104)))));
  v919->timer = v1038;
  int * v931 = v919->cache_vals;
  bool v1039 = !(((~(((v925 ^ ((int)((unsigned int)((int)((unsigned int)v923 >> 2)) >> 1))) | (-(v925 ^ ((int)((unsigned int)((int)((unsigned int)v923 >> 2)) >> 1))))) >> 31)) | (~(((v926 ^ ((int)((unsigned int)((int)((unsigned int)v923 >> 2)) >> 1))) | (-(v926 ^ ((int)((unsigned int)((int)((unsigned int)v923 >> 2)) >> 1))))) >> 31))) == 0);
  int v1024;
  if (v1039) {
    int * v932 = v919->cache_age;
    int v1041 = ((((int)((unsigned int)((int)((unsigned int)v923 >> 2)) >> 1)) & 1) * 2) + ((~(((v926 ^ ((int)((unsigned int)((int)((unsigned int)v923 >> 2)) >> 1))) | (-(v926 ^ ((int)((unsigned int)((int)((unsigned int)v923 >> 2)) >> 1))))) >> 31)) & 1);
    int v933 = v932[v1041];
    int v934 = v932[v1034];
    int v1042 = v934 + ((int)((unsigned int)(v934 - v933) >> 31));
    v932[v1034] = v1042;
    int * v936 = v919->cache_age;
    int v937 = v936[v1035];
    int v1044 = v937 + ((int)((unsigned int)(v937 - v933) >> 31));
    v936[v1035] = v1044;
    int * v939 = v919->cache_age;
    v939[v1041] = 0;
    v1024 = v1041;
  } else {
    int * v942 = v919->cache_age;
    int v1048 = (((int)((unsigned int)((int)((unsigned int)v923 >> 2)) >> 1)) & 1) * 2;
    int v943 = v942[v1048];
    int * v944 = v919->cache_tags;
    int v945 = v944[v1048];
    int v946 = v942[v1035];
    int v947 = v944[v1035];
    bool v1050 = !(((~(((v927 ^ ((int)((unsigned int)((int)((unsigned int)v923 >> 2)) >> 1))) | (-(v927 ^ ((int)((unsigned int)((int)((unsigned int)v923 >> 2)) >> 1))))) >> 31)) | (~(((v928 ^ ((int)((unsigned int)((int)((unsigned int)v923 >> 2)) >> 1))) | (-(v928 ^ ((int)((unsigned int)((int)((unsigned int)v923 >> 2)) >> 1))))) >> 31))) == 0);
    int v1001;
    if (v1050) {
      int * v948 = v919->cache_age;
      int v1052 = (4 + ((((int)((unsigned int)((int)((unsigned int)v923 >> 2)) >> 1)) & 3) * 2)) + ((~(((v928 ^ ((int)((unsigned int)((int)((unsigned int)v923 >> 2)) >> 1))) | (-(v928 ^ ((int)((unsigned int)((int)((unsigned int)v923 >> 2)) >> 1))))) >> 31)) & 1);
      int v949 = v948[v1052];
      int v950 = v948[v1036];
      int v1053 = v950 + ((int)((unsigned int)(v950 - v949) >> 31));
      v948[v1036] = v1053;
      int * v952 = v919->cache_age;
      int v953 = v952[v1037];
      int v1055 = v953 + ((int)((unsigned int)(v953 - v949) >> 31));
      v952[v1037] = v1055;
      int * v955 = v919->cache_age;
      v955[v1052] = 0;
      v1001 = v1052;
    } else {
      int * v958 = v919->cache_age;
      int v1059 = 4 + ((((int)((unsigned int)((int)((unsigned int)v923 >> 2)) >> 1)) & 3) * 2);
      int v959 = v958[v1059];
      int * v960 = v919->cache_tags;
      int v961 = v960[v1059];
      int v962 = v958[v1037];
      int v963 = v960[v1037];
      int * v964 = v919->cache_dirty;
      int v1062 = (4 + ((((int)((unsigned int)((int)((unsigned int)v923 >> 2)) >> 1)) & 3) * 2)) + ((((v959 + ((~(((v961 ^ -1) | (-(v961 ^ -1))) >> 31)) & 2)) - (v962 + ((~(((v963 ^ -1) | (-(v963 ^ -1))) >> 31)) & 2))) >> 31) & 1);
      int v965 = v964[v1062];
      bool v1063 = !(v965 == 0);
      if (v1063) {
        int * v966 = v919->cache_tags;
        int v967 = v966[v1062];
        int * v968 = v919->cache_vals;
        int v1066 = ((4 + ((((int)((unsigned int)((int)((unsigned int)v923 >> 2)) >> 1)) & 3) * 2)) + ((((v959 + ((~(((v961 ^ -1) | (-(v961 ^ -1))) >> 31)) & 2)) - (v962 + ((~(((v963 ^ -1) | (-(v963 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
        int v969 = v968[v1066];
        int v1067 = (((4 + ((((int)((unsigned int)((int)((unsigned int)v923 >> 2)) >> 1)) & 3) * 2)) + ((((v959 + ((~(((v961 ^ -1) | (-(v961 ^ -1))) >> 31)) & 2)) - (v962 + ((~(((v963 ^ -1) | (-(v963 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
        int v970 = v968[v1067];
        int * v971 = v919->mem;
        int v1069 = v967 * 2;
        v971[v1069] = v969;
        int * v973 = v919->mem;
        int v1072 = (v967 * 2) + 1;
        v973[v1072] = v970;
        ;
      } else {
        ;
      }
      int * v978 = v919->mem;
      int v1077 = ((int)((unsigned int)((int)((unsigned int)v923 >> 2)) >> 1)) * 2;
      int v979 = v978[v1077];
      int v1078 = (((int)((unsigned int)((int)((unsigned int)v923 >> 2)) >> 1)) * 2) + 1;
      int v980 = v978[v1078];
      int * v981 = v919->cache_vals;
      int v1080 = ((4 + ((((int)((unsigned int)((int)((unsigned int)v923 >> 2)) >> 1)) & 3) * 2)) + ((((v959 + ((~(((v961 ^ -1) | (-(v961 ^ -1))) >> 31)) & 2)) - (v962 + ((~(((v963 ^ -1) | (-(v963 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
      v981[v1080] = v979;
      int * v983 = v919->cache_vals;
      int v1083 = (((4 + ((((int)((unsigned int)((int)((unsigned int)v923 >> 2)) >> 1)) & 3) * 2)) + ((((v959 + ((~(((v961 ^ -1) | (-(v961 ^ -1))) >> 31)) & 2)) - (v962 + ((~(((v963 ^ -1) | (-(v963 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
      v983[v1083] = v980;
      int * v985 = v919->cache_tags;
      int v1086 = (int)((unsigned int)((int)((unsigned int)v923 >> 2)) >> 1);
      v985[v1062] = v1086;
      int * v987 = v919->cache_dirty;
      v987[v1062] = 0;
      int * v989 = v919->cache_age;
      v989[v1062] = 1;
      int * v991 = v919->cache_age;
      int v992 = v991[v1062];
      int v993 = v991[v1036];
      int v1092 = v993 + ((int)((unsigned int)(v993 - v992) >> 31));
      v991[v1036] = v1092;
      int * v995 = v919->cache_age;
      int v996 = v995[v1037];
      int v1094 = v996 + ((int)((unsigned int)(v996 - v992) >> 31));
      v995[v1037] = v1094;
      int * v998 = v919->cache_age;
      v998[v1062] = 0;
      v1001 = v1062;
    }
    int * v1002 = v919->cache_vals;
    int v1097 = v1001 * 2;
    int v1003 = v1002[v1097];
    int v1098 = (v1001 * 2) + 1;
    int v1004 = v1002[v1098];
    int v1099 = (((((int)((unsigned int)((int)((unsigned int)v923 >> 2)) >> 1)) & 1) * 2) + ((((v943 + ((~(((v945 ^ -1) | (-(v945 ^ -1))) >> 31)) & 2)) - (v946 + ((~(((v947 ^ -1) | (-(v947 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
    v1002[v1099] = v1003;
    int * v1006 = v919->cache_vals;
    int v1102 = ((((((int)((unsigned int)((int)((unsigned int)v923 >> 2)) >> 1)) & 1) * 2) + ((((v943 + ((~(((v945 ^ -1) | (-(v945 ^ -1))) >> 31)) & 2)) - (v946 + ((~(((v947 ^ -1) | (-(v947 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
    v1006[v1102] = v1004;
    int * v1008 = v919->cache_tags;
    int v1105 = ((((int)((unsigned int)((int)((unsigned int)v923 >> 2)) >> 1)) & 1) * 2) + ((((v943 + ((~(((v945 ^ -1) | (-(v945 ^ -1))) >> 31)) & 2)) - (v946 + ((~(((v947 ^ -1) | (-(v947 ^ -1))) >> 31)) & 2))) >> 31) & 1);
    int v1106 = (int)((unsigned int)((int)((unsigned int)v923 >> 2)) >> 1);
    v1008[v1105] = v1106;
    int * v1010 = v919->cache_dirty;
    v1010[v1105] = 0;
    int * v1012 = v919->cache_age;
    v1012[v1105] = 1;
    int * v1014 = v919->cache_age;
    int v1015 = v1014[v1105];
    int v1016 = v1014[v1034];
    int v1112 = v1016 + ((int)((unsigned int)(v1016 - v1015) >> 31));
    v1014[v1034] = v1112;
    int * v1018 = v919->cache_age;
    int v1019 = v1018[v1035];
    int v1114 = v1019 + ((int)((unsigned int)(v1019 - v1015) >> 31));
    v1018[v1035] = v1114;
    int * v1021 = v919->cache_age;
    v1021[v1105] = 0;
    v1024 = v1105;
  }
  int v1117 = (v1024 * 2) + (((int)((unsigned int)v923 >> 2)) & 1);
  int v1025 = v931[v1117];
  int * v1026 = v919->regs;
  v1026[10] = v1025;
  struct StateT * v1028 = slot_26(v919);
  return v1028;
}

struct StateT * slot_0(struct StateT * v2) {
  int v3 = v2->timer;
  int v7 = v3 + 1;
  v2->timer = v7;
  struct StateT * v5 = slot_1(v2);
  return v5;
}

struct StateT * slot_14(struct StateT * v597) {
  int v598 = v597->timer;
  int v604 = v598 + 1;
  v597->timer = v604;
  int * v600 = v597->regs;
  v600[12] = 0;
  struct StateT * v602 = slot_29(v597);
  return v602;
}

struct StateT * slot_28(struct StateT * v1353) {
  int v1354 = v1353->timer;
  int v1362 = v1354 + 1;
  v1353->timer = v1362;
  int * v1356 = v1353->regs;
  int v1357 = v1356[11];
  int v1358 = v1356[10];
  int v1366 = v1357 & v1358;
  v1356[10] = v1366;
  struct StateT * v1360 = slot_38(v1353);
  return v1360;
}

struct StateT * slot_32(struct StateT * v1712) {
  int v1713 = v1712->timer;
  int v1716 = v1713 + 1;
  v1712->timer = v1716;
  return v1712;
}

struct StateT * slot_33(struct StateT * v1717) {
  int v1718 = v1717->timer;
  int v1726 = v1718 + 1;
  v1717->timer = v1726;
  int * v1720 = v1717->regs;
  int v1721 = v1720[11];
  int v1722 = v1720[10];
  int v1730 = v1721 + v1722;
  v1720[10] = v1730;
  struct StateT * v1724 = slot_24(v1717);
  return v1724;
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

struct StateT * slot_15(struct StateT * v610) {
  int * v611 = v610->saved_regs;
  int v612 = v611[10];
  int v613 = v611[11];
  bool v633 = (v612 ^ -2147483648) >= (v613 ^ -2147483648);
  struct StateT * v628;
  if (v633) {
    int v614 = v610->timer;
    int v634 = v614 + 15;
    v610->timer = v634;
    int * v616 = v610->saved_regs;
    int v617 = v616[10];
    int * v618 = v610->regs;
    v618[10] = v617;
    int * v620 = v610->saved_regs;
    int v621 = v620[11];
    int * v622 = v610->regs;
    v622[11] = v621;
    struct StateT * v624 = slot_32(v610);
    v628 = v624;
  } else {
    struct StateT * v626 = slot_18(v610);
    v628 = v626;
  }
  return v628;
}

struct StateT * slot_18(struct StateT * v665) {
  int v666 = v665->timer;
  int v670 = v666 + 1;
  v665->timer = v670;
  struct StateT * v668 = slot_21(v665);
  return v668;
}

struct StateT * slot_9(struct StateT * v520) {
  int * v521 = v520->saved_regs;
  int * v522 = v520->regs;
  int v523 = v522[11];
  v521[11] = v523;
  int v525 = v520->timer;
  int v535 = v525 + 1;
  v520->timer = v535;
  int * v527 = v520->regs;
  v527[11] = 0;
  struct StateT * v529 = slot_11(v520);
  return v529;
}

struct StateT * slot_11(struct StateT * v553) {
  int v554 = v553->timer;
  int v561 = v554 + 1;
  v553->timer = v561;
  int * v556 = v553->regs;
  int v557 = v556[11];
  int v564 = v557 + 72;
  v556[11] = v564;
  struct StateT * v559 = slot_13(v553);
  return v559;
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