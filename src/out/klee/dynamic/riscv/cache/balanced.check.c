// verify: clean (KLEE should report no failing assertion) [budget 1200s]
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

struct StateT2 * slot_12(struct StateT2 * v759);
struct StateT2 * slot_14(struct StateT2 * v855);
struct StateT2 * slot_6(struct StateT2 * v654);
struct StateT2 * slot_16(struct StateT2 * v883);
struct StateT2 * slot_5(struct StateT2 * v897);
struct StateT2 * slot_2(struct StateT2 * v548);
struct StateT2 * slot_7(struct StateT2 * v818);
struct StateT2 * slot_3(struct StateT2 * v584);
struct StateT2 * snippet(struct StateT2 * v0);
struct StateT2 * slot_10(struct StateT2 * v713);
struct StateT2 * slot_1(struct StateT2 * v38);
struct StateT2 * slot_4(struct StateT2 * v782);
struct StateT2 * slot_13(struct StateT2 * v841);
struct StateT2 * slot_15(struct StateT2 * v869);
struct StateT2 * slot_9(struct StateT2 * v690);
struct StateT2 * slot_11(struct StateT2 * v736);
struct StateT2 * slot_0(struct StateT2 * v2);
struct StateT2 * slot_12(struct StateT2 * v759) {
  struct StateT * v760 = v759->b;
  int v761 = v760->timer;
  bool v773 = v761 == v761;
  squared_assert(v773);
  squared_assume(v773);
  struct StateT * v764 = v759->b;
  int v765 = v764->timer;
  int v775 = v765 + 1;
  v764->timer = v775;
  struct StateT * v767 = v759->b;
  int * v768 = v767->regs;
  v768[18] = 2;
  struct StateT2 * v770 = slot_16(v759);
  return v770;
}

struct StateT2 * slot_14(struct StateT2 * v855) {
  struct StateT * v856 = v855->b;
  int v857 = v856->timer;
  bool v866 = v857 == v857;
  squared_assert(v866);
  squared_assume(v866);
  struct StateT * v860 = v855->b;
  int v861 = v860->timer;
  int v868 = v861 + 1;
  v860->timer = v868;
  struct StateT * v863 = v855->b;
  return v855;
}

struct StateT2 * slot_6(struct StateT2 * v654) {
  struct StateT * v655 = v654->a;
  int v656 = v655->timer;
  struct StateT * v657 = v654->b;
  int v658 = v657->timer;
  bool v677 = v656 == v658;
  squared_assert(v677);
  squared_assume(v677);
  struct StateT * v661 = v654->a;
  int v662 = v661->timer;
  int v679 = v662 + 1;
  v661->timer = v679;
  struct StateT * v664 = v654->b;
  int v665 = v664->timer;
  int v681 = v665 + 1;
  v664->timer = v681;
  struct StateT * v667 = v654->a;
  int * v668 = v667->regs;
  v668[18] = 2;
  struct StateT * v670 = v654->b;
  int * v671 = v670->regs;
  v671[18] = 2;
  struct StateT2 * v673 = slot_7(v654);
  return v673;
}

struct StateT2 * slot_16(struct StateT2 * v883) {
  struct StateT * v884 = v883->b;
  int v885 = v884->timer;
  bool v894 = v885 == v885;
  squared_assert(v894);
  squared_assume(v894);
  struct StateT * v888 = v883->b;
  int v889 = v888->timer;
  int v896 = v889 + 1;
  v888->timer = v896;
  struct StateT * v891 = v883->b;
  return v883;
}

struct StateT2 * slot_5(struct StateT2 * v897) {
  struct StateT * v898 = v897->a;
  int v899 = v898->timer;
  struct StateT * v900 = v897->b;
  int v901 = v900->timer;
  bool v915 = v899 == v901;
  squared_assert(v915);
  squared_assume(v915);
  struct StateT * v904 = v897->a;
  int v905 = v904->timer;
  int v917 = v905 + 1;
  v904->timer = v917;
  struct StateT * v907 = v897->b;
  int v908 = v907->timer;
  int v919 = v908 + 1;
  v907->timer = v919;
  struct StateT * v910 = v897->a;
  struct StateT * v911 = v897->b;
  return v897;
}

struct StateT2 * slot_2(struct StateT2 * v548) {
  struct StateT * v549 = v548->a;
  int v550 = v549->timer;
  struct StateT * v551 = v548->b;
  int v552 = v551->timer;
  bool v571 = v550 == v552;
  squared_assert(v571);
  squared_assume(v571);
  struct StateT * v555 = v548->a;
  int v556 = v555->timer;
  int v573 = v556 + 1;
  v555->timer = v573;
  struct StateT * v558 = v548->b;
  int v559 = v558->timer;
  int v575 = v559 + 1;
  v558->timer = v575;
  struct StateT * v561 = v548->a;
  int * v562 = v561->regs;
  v562[17] = 10;
  struct StateT * v564 = v548->b;
  int * v565 = v564->regs;
  v565[17] = 10;
  struct StateT2 * v567 = slot_3(v548);
  return v567;
}

struct StateT2 * slot_7(struct StateT2 * v818) {
  struct StateT * v819 = v818->a;
  int v820 = v819->timer;
  struct StateT * v821 = v818->b;
  int v822 = v821->timer;
  bool v836 = v820 == v822;
  squared_assert(v836);
  squared_assume(v836);
  struct StateT * v825 = v818->a;
  int v826 = v825->timer;
  int v838 = v826 + 1;
  v825->timer = v838;
  struct StateT * v828 = v818->b;
  int v829 = v828->timer;
  int v840 = v829 + 1;
  v828->timer = v840;
  struct StateT * v831 = v818->a;
  struct StateT * v832 = v818->b;
  return v818;
}

struct StateT2 * slot_3(struct StateT2 * v584) {
  struct StateT * v585 = v584->a;
  int v586 = v585->timer;
  struct StateT * v587 = v584->b;
  int v588 = v587->timer;
  bool v625 = v586 == v588;
  squared_assert(v625);
  squared_assume(v625);
  struct StateT * v591 = v584->a;
  int v592 = v591->timer;
  int v627 = v592 + 1;
  v591->timer = v627;
  struct StateT * v594 = v584->b;
  int v595 = v594->timer;
  int v629 = v595 + 1;
  v594->timer = v629;
  struct StateT * v597 = v584->a;
  int * v598 = v597->regs;
  int v599 = v598[16];
  int * v600 = v597->regs;
  int v601 = v600[17];
  struct StateT * v602 = v584->b;
  int * v603 = v602->regs;
  int v604 = v603[16];
  int * v605 = v602->regs;
  int v606 = v605[17];
  bool v638 = v599 < v601;
  struct StateT2 * v621;
  if (v638) {
    bool v639 = v604 < v606;
    struct StateT2 * v612;
    if (v639) {
      struct StateT2 * v607 = slot_6(v584);
      v612 = v607;
    } else {
      struct StateT2 * v609 = slot_9(v584);
      struct StateT2 * v610 = slot_10(v584);
      v612 = v610;
    }
    v621 = v612;
  } else {
    bool v646 = v604 < v606;
    struct StateT2 * v619;
    if (v646) {
      struct StateT2 * v614 = slot_11(v584);
      struct StateT2 * v615 = slot_12(v584);
      v619 = v615;
    } else {
      struct StateT2 * v617 = slot_4(v584);
      v619 = v617;
    }
    v621 = v619;
  }
  return v621;
}

struct StateT2 * snippet(struct StateT2 * v0) {
  struct StateT2 * v1 = slot_0(v0);
  return v1;
}

struct StateT2 * slot_10(struct StateT2 * v713) {
  struct StateT * v714 = v713->b;
  int v715 = v714->timer;
  bool v727 = v715 == v715;
  squared_assert(v727);
  squared_assume(v727);
  struct StateT * v718 = v713->b;
  int v719 = v718->timer;
  int v729 = v719 + 1;
  v718->timer = v729;
  struct StateT * v721 = v713->b;
  int * v722 = v721->regs;
  v722[18] = 1;
  struct StateT2 * v724 = slot_14(v713);
  return v724;
}

struct StateT2 * slot_1(struct StateT2 * v38) {
  struct StateT * v39 = v38->a;
  int v40 = v39->timer;
  struct StateT * v41 = v38->b;
  int v42 = v41->timer;
  bool v315 = v40 == v42;
  squared_assert(v315);
  squared_assume(v315);
  struct StateT * v45 = v38->a;
  int v46 = v45->timer;
  int v317 = v46 + 1;
  v45->timer = v317;
  struct StateT * v48 = v38->b;
  int v49 = v48->timer;
  int v319 = v49 + 1;
  v48->timer = v319;
  struct StateT * v51 = v38->a;
  int * v52 = v51->regs;
  int v53 = v52[12];
  int * v54 = v51->cache_tags;
  int v324 = (((int)((unsigned int)((int)((unsigned int)v53 >> 2)) >> 1)) & 1) * 2;
  int v55 = v54[v324];
  int * v56 = v51->cache_tags;
  int v326 = ((((int)((unsigned int)((int)((unsigned int)v53 >> 2)) >> 1)) & 1) * 2) + 1;
  int v57 = v56[v326];
  int * v58 = v51->cache_tags;
  int v328 = 4 + ((((int)((unsigned int)((int)((unsigned int)v53 >> 2)) >> 1)) & 3) * 2);
  int v59 = v58[v328];
  int * v60 = v51->cache_tags;
  int v330 = (4 + ((((int)((unsigned int)((int)((unsigned int)v53 >> 2)) >> 1)) & 3) * 2)) + 1;
  int v61 = v60[v330];
  int v62 = v51->timer;
  int v331 = v62 + ((100 ^ (((~(((v59 ^ ((int)((unsigned int)((int)((unsigned int)v53 >> 2)) >> 1))) | (-(v59 ^ ((int)((unsigned int)((int)((unsigned int)v53 >> 2)) >> 1))))) >> 31)) | (~(((v61 ^ ((int)((unsigned int)((int)((unsigned int)v53 >> 2)) >> 1))) | (-(v61 ^ ((int)((unsigned int)((int)((unsigned int)v53 >> 2)) >> 1))))) >> 31))) & 104)) ^ (((~(((v55 ^ ((int)((unsigned int)((int)((unsigned int)v53 >> 2)) >> 1))) | (-(v55 ^ ((int)((unsigned int)((int)((unsigned int)v53 >> 2)) >> 1))))) >> 31)) | (~(((v57 ^ ((int)((unsigned int)((int)((unsigned int)v53 >> 2)) >> 1))) | (-(v57 ^ ((int)((unsigned int)((int)((unsigned int)v53 >> 2)) >> 1))))) >> 31))) & (1 ^ (100 ^ (((~(((v59 ^ ((int)((unsigned int)((int)((unsigned int)v53 >> 2)) >> 1))) | (-(v59 ^ ((int)((unsigned int)((int)((unsigned int)v53 >> 2)) >> 1))))) >> 31)) | (~(((v61 ^ ((int)((unsigned int)((int)((unsigned int)v53 >> 2)) >> 1))) | (-(v61 ^ ((int)((unsigned int)((int)((unsigned int)v53 >> 2)) >> 1))))) >> 31))) & 104)))));
  v51->timer = v331;
  int * v64 = v51->cache_vals;
  bool v332 = !(((~(((v55 ^ ((int)((unsigned int)((int)((unsigned int)v53 >> 2)) >> 1))) | (-(v55 ^ ((int)((unsigned int)((int)((unsigned int)v53 >> 2)) >> 1))))) >> 31)) | (~(((v57 ^ ((int)((unsigned int)((int)((unsigned int)v53 >> 2)) >> 1))) | (-(v57 ^ ((int)((unsigned int)((int)((unsigned int)v53 >> 2)) >> 1))))) >> 31))) == 0);
  int v177;
  if (v332) {
    int * v65 = v51->cache_age;
    int v334 = ((((int)((unsigned int)((int)((unsigned int)v53 >> 2)) >> 1)) & 1) * 2) + ((~(((v57 ^ ((int)((unsigned int)((int)((unsigned int)v53 >> 2)) >> 1))) | (-(v57 ^ ((int)((unsigned int)((int)((unsigned int)v53 >> 2)) >> 1))))) >> 31)) & 1);
    int v66 = v65[v334];
    int * v67 = v51->cache_age;
    int v68 = v67[v324];
    int * v69 = v51->cache_age;
    int v337 = v68 + ((int)((unsigned int)(v68 - v66) >> 31));
    v69[v324] = v337;
    int * v71 = v51->cache_age;
    int v72 = v71[v326];
    int * v73 = v51->cache_age;
    int v340 = v72 + ((int)((unsigned int)(v72 - v66) >> 31));
    v73[v326] = v340;
    int * v75 = v51->cache_age;
    v75[v334] = 0;
    v177 = v334;
  } else {
    int * v78 = v51->cache_age;
    int v344 = (((int)((unsigned int)((int)((unsigned int)v53 >> 2)) >> 1)) & 1) * 2;
    int v79 = v78[v344];
    int * v80 = v51->cache_tags;
    int v81 = v80[v344];
    int * v82 = v51->cache_age;
    int v83 = v82[v326];
    int * v84 = v51->cache_tags;
    int v85 = v84[v326];
    bool v348 = !(((~(((v59 ^ ((int)((unsigned int)((int)((unsigned int)v53 >> 2)) >> 1))) | (-(v59 ^ ((int)((unsigned int)((int)((unsigned int)v53 >> 2)) >> 1))))) >> 31)) | (~(((v61 ^ ((int)((unsigned int)((int)((unsigned int)v53 >> 2)) >> 1))) | (-(v61 ^ ((int)((unsigned int)((int)((unsigned int)v53 >> 2)) >> 1))))) >> 31))) == 0);
    int v149;
    if (v348) {
      int * v86 = v51->cache_age;
      int v350 = (4 + ((((int)((unsigned int)((int)((unsigned int)v53 >> 2)) >> 1)) & 3) * 2)) + ((~(((v61 ^ ((int)((unsigned int)((int)((unsigned int)v53 >> 2)) >> 1))) | (-(v61 ^ ((int)((unsigned int)((int)((unsigned int)v53 >> 2)) >> 1))))) >> 31)) & 1);
      int v87 = v86[v350];
      int * v88 = v51->cache_age;
      int v89 = v88[v328];
      int * v90 = v51->cache_age;
      int v353 = v89 + ((int)((unsigned int)(v89 - v87) >> 31));
      v90[v328] = v353;
      int * v92 = v51->cache_age;
      int v93 = v92[v330];
      int * v94 = v51->cache_age;
      int v356 = v93 + ((int)((unsigned int)(v93 - v87) >> 31));
      v94[v330] = v356;
      int * v96 = v51->cache_age;
      v96[v350] = 0;
      v149 = v350;
    } else {
      int * v99 = v51->cache_age;
      int v360 = 4 + ((((int)((unsigned int)((int)((unsigned int)v53 >> 2)) >> 1)) & 3) * 2);
      int v100 = v99[v360];
      int * v101 = v51->cache_tags;
      int v102 = v101[v360];
      int * v103 = v51->cache_age;
      int v104 = v103[v330];
      int * v105 = v51->cache_tags;
      int v106 = v105[v330];
      int * v107 = v51->cache_dirty;
      int v365 = (4 + ((((int)((unsigned int)((int)((unsigned int)v53 >> 2)) >> 1)) & 3) * 2)) + ((((v100 + ((~(((v102 ^ -1) | (-(v102 ^ -1))) >> 31)) & 2)) - (v104 + ((~(((v106 ^ -1) | (-(v106 ^ -1))) >> 31)) & 2))) >> 31) & 1);
      int v108 = v107[v365];
      bool v366 = !(v108 == 0);
      if (v366) {
        int * v109 = v51->cache_tags;
        int v110 = v109[v365];
        int * v111 = v51->cache_vals;
        int v369 = ((4 + ((((int)((unsigned int)((int)((unsigned int)v53 >> 2)) >> 1)) & 3) * 2)) + ((((v100 + ((~(((v102 ^ -1) | (-(v102 ^ -1))) >> 31)) & 2)) - (v104 + ((~(((v106 ^ -1) | (-(v106 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
        int v112 = v111[v369];
        int * v113 = v51->cache_vals;
        int v371 = (((4 + ((((int)((unsigned int)((int)((unsigned int)v53 >> 2)) >> 1)) & 3) * 2)) + ((((v100 + ((~(((v102 ^ -1) | (-(v102 ^ -1))) >> 31)) & 2)) - (v104 + ((~(((v106 ^ -1) | (-(v106 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
        int v114 = v113[v371];
        int * v115 = v51->mem;
        int v373 = v110 * 2;
        v115[v373] = v112;
        int * v117 = v51->mem;
        int v376 = (v110 * 2) + 1;
        v117[v376] = v114;
        ;
      } else {
        ;
      }
      int * v122 = v51->mem;
      int v381 = ((int)((unsigned int)((int)((unsigned int)v53 >> 2)) >> 1)) * 2;
      int v123 = v122[v381];
      int * v124 = v51->mem;
      int v383 = (((int)((unsigned int)((int)((unsigned int)v53 >> 2)) >> 1)) * 2) + 1;
      int v125 = v124[v383];
      int * v126 = v51->cache_vals;
      int v385 = ((4 + ((((int)((unsigned int)((int)((unsigned int)v53 >> 2)) >> 1)) & 3) * 2)) + ((((v100 + ((~(((v102 ^ -1) | (-(v102 ^ -1))) >> 31)) & 2)) - (v104 + ((~(((v106 ^ -1) | (-(v106 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
      v126[v385] = v123;
      int * v128 = v51->cache_vals;
      int v388 = (((4 + ((((int)((unsigned int)((int)((unsigned int)v53 >> 2)) >> 1)) & 3) * 2)) + ((((v100 + ((~(((v102 ^ -1) | (-(v102 ^ -1))) >> 31)) & 2)) - (v104 + ((~(((v106 ^ -1) | (-(v106 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
      v128[v388] = v125;
      int * v130 = v51->cache_tags;
      int v391 = (int)((unsigned int)((int)((unsigned int)v53 >> 2)) >> 1);
      v130[v365] = v391;
      int * v132 = v51->cache_dirty;
      v132[v365] = 0;
      int * v134 = v51->cache_age;
      v134[v365] = 1;
      int * v136 = v51->cache_age;
      int v137 = v136[v365];
      int * v138 = v51->cache_age;
      int v139 = v138[v328];
      int * v140 = v51->cache_age;
      int v399 = v139 + ((int)((unsigned int)(v139 - v137) >> 31));
      v140[v328] = v399;
      int * v142 = v51->cache_age;
      int v143 = v142[v330];
      int * v144 = v51->cache_age;
      int v402 = v143 + ((int)((unsigned int)(v143 - v137) >> 31));
      v144[v330] = v402;
      int * v146 = v51->cache_age;
      v146[v365] = 0;
      v149 = v365;
    }
    int * v150 = v51->cache_vals;
    int v405 = v149 * 2;
    int v151 = v150[v405];
    int * v152 = v51->cache_vals;
    int v407 = (v149 * 2) + 1;
    int v153 = v152[v407];
    int * v154 = v51->cache_vals;
    int v409 = (((((int)((unsigned int)((int)((unsigned int)v53 >> 2)) >> 1)) & 1) * 2) + ((((v79 + ((~(((v81 ^ -1) | (-(v81 ^ -1))) >> 31)) & 2)) - (v83 + ((~(((v85 ^ -1) | (-(v85 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
    v154[v409] = v151;
    int * v156 = v51->cache_vals;
    int v412 = ((((((int)((unsigned int)((int)((unsigned int)v53 >> 2)) >> 1)) & 1) * 2) + ((((v79 + ((~(((v81 ^ -1) | (-(v81 ^ -1))) >> 31)) & 2)) - (v83 + ((~(((v85 ^ -1) | (-(v85 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
    v156[v412] = v153;
    int * v158 = v51->cache_tags;
    int v415 = ((((int)((unsigned int)((int)((unsigned int)v53 >> 2)) >> 1)) & 1) * 2) + ((((v79 + ((~(((v81 ^ -1) | (-(v81 ^ -1))) >> 31)) & 2)) - (v83 + ((~(((v85 ^ -1) | (-(v85 ^ -1))) >> 31)) & 2))) >> 31) & 1);
    int v416 = (int)((unsigned int)((int)((unsigned int)v53 >> 2)) >> 1);
    v158[v415] = v416;
    int * v160 = v51->cache_dirty;
    v160[v415] = 0;
    int * v162 = v51->cache_age;
    v162[v415] = 1;
    int * v164 = v51->cache_age;
    int v165 = v164[v415];
    int * v166 = v51->cache_age;
    int v167 = v166[v324];
    int * v168 = v51->cache_age;
    int v424 = v167 + ((int)((unsigned int)(v167 - v165) >> 31));
    v168[v324] = v424;
    int * v170 = v51->cache_age;
    int v171 = v170[v326];
    int * v172 = v51->cache_age;
    int v427 = v171 + ((int)((unsigned int)(v171 - v165) >> 31));
    v172[v326] = v427;
    int * v174 = v51->cache_age;
    v174[v415] = 0;
    v177 = v415;
  }
  int v430 = (v177 * 2) + (((int)((unsigned int)v53 >> 2)) & 1);
  int v178 = v64[v430];
  int * v179 = v51->regs;
  v179[16] = v178;
  struct StateT * v181 = v38->b;
  int * v182 = v181->regs;
  int v183 = v182[12];
  int * v184 = v181->cache_tags;
  int v437 = (((int)((unsigned int)((int)((unsigned int)v183 >> 2)) >> 1)) & 1) * 2;
  int v185 = v184[v437];
  int * v186 = v181->cache_tags;
  int v439 = ((((int)((unsigned int)((int)((unsigned int)v183 >> 2)) >> 1)) & 1) * 2) + 1;
  int v187 = v186[v439];
  int * v188 = v181->cache_tags;
  int v441 = 4 + ((((int)((unsigned int)((int)((unsigned int)v183 >> 2)) >> 1)) & 3) * 2);
  int v189 = v188[v441];
  int * v190 = v181->cache_tags;
  int v443 = (4 + ((((int)((unsigned int)((int)((unsigned int)v183 >> 2)) >> 1)) & 3) * 2)) + 1;
  int v191 = v190[v443];
  int v192 = v181->timer;
  int v444 = v192 + ((100 ^ (((~(((v189 ^ ((int)((unsigned int)((int)((unsigned int)v183 >> 2)) >> 1))) | (-(v189 ^ ((int)((unsigned int)((int)((unsigned int)v183 >> 2)) >> 1))))) >> 31)) | (~(((v191 ^ ((int)((unsigned int)((int)((unsigned int)v183 >> 2)) >> 1))) | (-(v191 ^ ((int)((unsigned int)((int)((unsigned int)v183 >> 2)) >> 1))))) >> 31))) & 104)) ^ (((~(((v185 ^ ((int)((unsigned int)((int)((unsigned int)v183 >> 2)) >> 1))) | (-(v185 ^ ((int)((unsigned int)((int)((unsigned int)v183 >> 2)) >> 1))))) >> 31)) | (~(((v187 ^ ((int)((unsigned int)((int)((unsigned int)v183 >> 2)) >> 1))) | (-(v187 ^ ((int)((unsigned int)((int)((unsigned int)v183 >> 2)) >> 1))))) >> 31))) & (1 ^ (100 ^ (((~(((v189 ^ ((int)((unsigned int)((int)((unsigned int)v183 >> 2)) >> 1))) | (-(v189 ^ ((int)((unsigned int)((int)((unsigned int)v183 >> 2)) >> 1))))) >> 31)) | (~(((v191 ^ ((int)((unsigned int)((int)((unsigned int)v183 >> 2)) >> 1))) | (-(v191 ^ ((int)((unsigned int)((int)((unsigned int)v183 >> 2)) >> 1))))) >> 31))) & 104)))));
  v181->timer = v444;
  int * v194 = v181->cache_vals;
  bool v445 = !(((~(((v185 ^ ((int)((unsigned int)((int)((unsigned int)v183 >> 2)) >> 1))) | (-(v185 ^ ((int)((unsigned int)((int)((unsigned int)v183 >> 2)) >> 1))))) >> 31)) | (~(((v187 ^ ((int)((unsigned int)((int)((unsigned int)v183 >> 2)) >> 1))) | (-(v187 ^ ((int)((unsigned int)((int)((unsigned int)v183 >> 2)) >> 1))))) >> 31))) == 0);
  int v307;
  if (v445) {
    int * v195 = v181->cache_age;
    int v447 = ((((int)((unsigned int)((int)((unsigned int)v183 >> 2)) >> 1)) & 1) * 2) + ((~(((v187 ^ ((int)((unsigned int)((int)((unsigned int)v183 >> 2)) >> 1))) | (-(v187 ^ ((int)((unsigned int)((int)((unsigned int)v183 >> 2)) >> 1))))) >> 31)) & 1);
    int v196 = v195[v447];
    int * v197 = v181->cache_age;
    int v198 = v197[v437];
    int * v199 = v181->cache_age;
    int v450 = v198 + ((int)((unsigned int)(v198 - v196) >> 31));
    v199[v437] = v450;
    int * v201 = v181->cache_age;
    int v202 = v201[v439];
    int * v203 = v181->cache_age;
    int v453 = v202 + ((int)((unsigned int)(v202 - v196) >> 31));
    v203[v439] = v453;
    int * v205 = v181->cache_age;
    v205[v447] = 0;
    v307 = v447;
  } else {
    int * v208 = v181->cache_age;
    int v457 = (((int)((unsigned int)((int)((unsigned int)v183 >> 2)) >> 1)) & 1) * 2;
    int v209 = v208[v457];
    int * v210 = v181->cache_tags;
    int v211 = v210[v457];
    int * v212 = v181->cache_age;
    int v213 = v212[v439];
    int * v214 = v181->cache_tags;
    int v215 = v214[v439];
    bool v461 = !(((~(((v189 ^ ((int)((unsigned int)((int)((unsigned int)v183 >> 2)) >> 1))) | (-(v189 ^ ((int)((unsigned int)((int)((unsigned int)v183 >> 2)) >> 1))))) >> 31)) | (~(((v191 ^ ((int)((unsigned int)((int)((unsigned int)v183 >> 2)) >> 1))) | (-(v191 ^ ((int)((unsigned int)((int)((unsigned int)v183 >> 2)) >> 1))))) >> 31))) == 0);
    int v279;
    if (v461) {
      int * v216 = v181->cache_age;
      int v463 = (4 + ((((int)((unsigned int)((int)((unsigned int)v183 >> 2)) >> 1)) & 3) * 2)) + ((~(((v191 ^ ((int)((unsigned int)((int)((unsigned int)v183 >> 2)) >> 1))) | (-(v191 ^ ((int)((unsigned int)((int)((unsigned int)v183 >> 2)) >> 1))))) >> 31)) & 1);
      int v217 = v216[v463];
      int * v218 = v181->cache_age;
      int v219 = v218[v441];
      int * v220 = v181->cache_age;
      int v466 = v219 + ((int)((unsigned int)(v219 - v217) >> 31));
      v220[v441] = v466;
      int * v222 = v181->cache_age;
      int v223 = v222[v443];
      int * v224 = v181->cache_age;
      int v469 = v223 + ((int)((unsigned int)(v223 - v217) >> 31));
      v224[v443] = v469;
      int * v226 = v181->cache_age;
      v226[v463] = 0;
      v279 = v463;
    } else {
      int * v229 = v181->cache_age;
      int v473 = 4 + ((((int)((unsigned int)((int)((unsigned int)v183 >> 2)) >> 1)) & 3) * 2);
      int v230 = v229[v473];
      int * v231 = v181->cache_tags;
      int v232 = v231[v473];
      int * v233 = v181->cache_age;
      int v234 = v233[v443];
      int * v235 = v181->cache_tags;
      int v236 = v235[v443];
      int * v237 = v181->cache_dirty;
      int v478 = (4 + ((((int)((unsigned int)((int)((unsigned int)v183 >> 2)) >> 1)) & 3) * 2)) + ((((v230 + ((~(((v232 ^ -1) | (-(v232 ^ -1))) >> 31)) & 2)) - (v234 + ((~(((v236 ^ -1) | (-(v236 ^ -1))) >> 31)) & 2))) >> 31) & 1);
      int v238 = v237[v478];
      bool v479 = !(v238 == 0);
      if (v479) {
        int * v239 = v181->cache_tags;
        int v240 = v239[v478];
        int * v241 = v181->cache_vals;
        int v482 = ((4 + ((((int)((unsigned int)((int)((unsigned int)v183 >> 2)) >> 1)) & 3) * 2)) + ((((v230 + ((~(((v232 ^ -1) | (-(v232 ^ -1))) >> 31)) & 2)) - (v234 + ((~(((v236 ^ -1) | (-(v236 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
        int v242 = v241[v482];
        int * v243 = v181->cache_vals;
        int v484 = (((4 + ((((int)((unsigned int)((int)((unsigned int)v183 >> 2)) >> 1)) & 3) * 2)) + ((((v230 + ((~(((v232 ^ -1) | (-(v232 ^ -1))) >> 31)) & 2)) - (v234 + ((~(((v236 ^ -1) | (-(v236 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
        int v244 = v243[v484];
        int * v245 = v181->mem;
        int v486 = v240 * 2;
        v245[v486] = v242;
        int * v247 = v181->mem;
        int v489 = (v240 * 2) + 1;
        v247[v489] = v244;
        ;
      } else {
        ;
      }
      int * v252 = v181->mem;
      int v494 = ((int)((unsigned int)((int)((unsigned int)v183 >> 2)) >> 1)) * 2;
      int v253 = v252[v494];
      int * v254 = v181->mem;
      int v496 = (((int)((unsigned int)((int)((unsigned int)v183 >> 2)) >> 1)) * 2) + 1;
      int v255 = v254[v496];
      int * v256 = v181->cache_vals;
      int v498 = ((4 + ((((int)((unsigned int)((int)((unsigned int)v183 >> 2)) >> 1)) & 3) * 2)) + ((((v230 + ((~(((v232 ^ -1) | (-(v232 ^ -1))) >> 31)) & 2)) - (v234 + ((~(((v236 ^ -1) | (-(v236 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
      v256[v498] = v253;
      int * v258 = v181->cache_vals;
      int v501 = (((4 + ((((int)((unsigned int)((int)((unsigned int)v183 >> 2)) >> 1)) & 3) * 2)) + ((((v230 + ((~(((v232 ^ -1) | (-(v232 ^ -1))) >> 31)) & 2)) - (v234 + ((~(((v236 ^ -1) | (-(v236 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
      v258[v501] = v255;
      int * v260 = v181->cache_tags;
      int v504 = (int)((unsigned int)((int)((unsigned int)v183 >> 2)) >> 1);
      v260[v478] = v504;
      int * v262 = v181->cache_dirty;
      v262[v478] = 0;
      int * v264 = v181->cache_age;
      v264[v478] = 1;
      int * v266 = v181->cache_age;
      int v267 = v266[v478];
      int * v268 = v181->cache_age;
      int v269 = v268[v441];
      int * v270 = v181->cache_age;
      int v512 = v269 + ((int)((unsigned int)(v269 - v267) >> 31));
      v270[v441] = v512;
      int * v272 = v181->cache_age;
      int v273 = v272[v443];
      int * v274 = v181->cache_age;
      int v515 = v273 + ((int)((unsigned int)(v273 - v267) >> 31));
      v274[v443] = v515;
      int * v276 = v181->cache_age;
      v276[v478] = 0;
      v279 = v478;
    }
    int * v280 = v181->cache_vals;
    int v518 = v279 * 2;
    int v281 = v280[v518];
    int * v282 = v181->cache_vals;
    int v520 = (v279 * 2) + 1;
    int v283 = v282[v520];
    int * v284 = v181->cache_vals;
    int v522 = (((((int)((unsigned int)((int)((unsigned int)v183 >> 2)) >> 1)) & 1) * 2) + ((((v209 + ((~(((v211 ^ -1) | (-(v211 ^ -1))) >> 31)) & 2)) - (v213 + ((~(((v215 ^ -1) | (-(v215 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
    v284[v522] = v281;
    int * v286 = v181->cache_vals;
    int v525 = ((((((int)((unsigned int)((int)((unsigned int)v183 >> 2)) >> 1)) & 1) * 2) + ((((v209 + ((~(((v211 ^ -1) | (-(v211 ^ -1))) >> 31)) & 2)) - (v213 + ((~(((v215 ^ -1) | (-(v215 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
    v286[v525] = v283;
    int * v288 = v181->cache_tags;
    int v528 = ((((int)((unsigned int)((int)((unsigned int)v183 >> 2)) >> 1)) & 1) * 2) + ((((v209 + ((~(((v211 ^ -1) | (-(v211 ^ -1))) >> 31)) & 2)) - (v213 + ((~(((v215 ^ -1) | (-(v215 ^ -1))) >> 31)) & 2))) >> 31) & 1);
    int v529 = (int)((unsigned int)((int)((unsigned int)v183 >> 2)) >> 1);
    v288[v528] = v529;
    int * v290 = v181->cache_dirty;
    v290[v528] = 0;
    int * v292 = v181->cache_age;
    v292[v528] = 1;
    int * v294 = v181->cache_age;
    int v295 = v294[v528];
    int * v296 = v181->cache_age;
    int v297 = v296[v437];
    int * v298 = v181->cache_age;
    int v537 = v297 + ((int)((unsigned int)(v297 - v295) >> 31));
    v298[v437] = v537;
    int * v300 = v181->cache_age;
    int v301 = v300[v439];
    int * v302 = v181->cache_age;
    int v540 = v301 + ((int)((unsigned int)(v301 - v295) >> 31));
    v302[v439] = v540;
    int * v304 = v181->cache_age;
    v304[v528] = 0;
    v307 = v528;
  }
  int v543 = (v307 * 2) + (((int)((unsigned int)v183 >> 2)) & 1);
  int v308 = v194[v543];
  int * v309 = v181->regs;
  v309[16] = v308;
  struct StateT2 * v311 = slot_2(v38);
  return v311;
}

struct StateT2 * slot_4(struct StateT2 * v782) {
  struct StateT * v783 = v782->a;
  int v784 = v783->timer;
  struct StateT * v785 = v782->b;
  int v786 = v785->timer;
  bool v805 = v784 == v786;
  squared_assert(v805);
  squared_assume(v805);
  struct StateT * v789 = v782->a;
  int v790 = v789->timer;
  int v807 = v790 + 1;
  v789->timer = v807;
  struct StateT * v792 = v782->b;
  int v793 = v792->timer;
  int v809 = v793 + 1;
  v792->timer = v809;
  struct StateT * v795 = v782->a;
  int * v796 = v795->regs;
  v796[18] = 1;
  struct StateT * v798 = v782->b;
  int * v799 = v798->regs;
  v799[18] = 1;
  struct StateT2 * v801 = slot_5(v782);
  return v801;
}

struct StateT2 * slot_13(struct StateT2 * v841) {
  struct StateT * v842 = v841->a;
  int v843 = v842->timer;
  bool v852 = v843 == v843;
  squared_assert(v852);
  squared_assume(v852);
  struct StateT * v846 = v841->a;
  int v847 = v846->timer;
  int v854 = v847 + 1;
  v846->timer = v854;
  struct StateT * v849 = v841->a;
  return v841;
}

struct StateT2 * slot_15(struct StateT2 * v869) {
  struct StateT * v870 = v869->a;
  int v871 = v870->timer;
  bool v880 = v871 == v871;
  squared_assert(v880);
  squared_assume(v880);
  struct StateT * v874 = v869->a;
  int v875 = v874->timer;
  int v882 = v875 + 1;
  v874->timer = v882;
  struct StateT * v877 = v869->a;
  return v869;
}

struct StateT2 * slot_9(struct StateT2 * v690) {
  struct StateT * v691 = v690->a;
  int v692 = v691->timer;
  bool v704 = v692 == v692;
  squared_assert(v704);
  squared_assume(v704);
  struct StateT * v695 = v690->a;
  int v696 = v695->timer;
  int v706 = v696 + 1;
  v695->timer = v706;
  struct StateT * v698 = v690->a;
  int * v699 = v698->regs;
  v699[18] = 2;
  struct StateT2 * v701 = slot_13(v690);
  return v701;
}

struct StateT2 * slot_11(struct StateT2 * v736) {
  struct StateT * v737 = v736->a;
  int v738 = v737->timer;
  bool v750 = v738 == v738;
  squared_assert(v750);
  squared_assume(v750);
  struct StateT * v741 = v736->a;
  int v742 = v741->timer;
  int v752 = v742 + 1;
  v741->timer = v752;
  struct StateT * v744 = v736->a;
  int * v745 = v744->regs;
  v745[18] = 1;
  struct StateT2 * v747 = slot_15(v736);
  return v747;
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
  v16[12] = 80;
  struct StateT * v18 = v2->b;
  int * v19 = v18->regs;
  v19[12] = 80;
  struct StateT2 * v21 = slot_1(v2);
  return v21;
}



/*****************************************
End of C Generated Code
*******************************************/

void init(struct StateT *s) {
  for (int i=0; i<NUM_REGS; i++) {
    s->regs[i] = 0;
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

void squared_assert(bool c) { koika_assert(c, "timer drift"); }
void squared_diverged(bool c) { koika_assert(c, "control flow diverged"); }
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
    s1.mem[SECRET_OFFSET+i] = secret(0, 20);
    s2.mem[SECRET_OFFSET+i] = secret(0, 20);
  }
  struct StateT2 p = { .a = &s1, .b = &s2 };
  struct StateT2 *p_ = snippet(&p);
  koika_assert(p_->a->timer==p_->b->timer, "timing leak");
  return 0;
}