// verify: leak (KLEE should report a failing assertion) [budget 120s]
#define NUM_REGS 32
#define MEM_SIZE 64
#define SECRET_SIZE 10
#define SECRET_OFFSET 20
#define CACHE_LRU_SIZE 10

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
  int cache_keys[10];
  int cache_vals[10];
  int timer;
};

struct StateT * slot_12(struct StateT * v562);
struct StateT * slot_6(struct StateT * v275);
struct StateT * slot_16(struct StateT * v669);
struct StateT * slot_23(struct StateT * v942);
struct StateT * slot_5(struct StateT * v251);
struct StateT * slot_2(struct StateT * v211);
struct StateT * slot_7(struct StateT * v295);
struct StateT * slot_21(struct StateT * v839);
struct StateT * slot_3(struct StateT * v223);
struct StateT * slot_10(struct StateT * v431);
struct StateT * slot_1(struct StateT * v106);
struct StateT * slot_19(struct StateT * v721);
struct StateT * slot_13(struct StateT * v589);
struct StateT * slot_0(struct StateT * v2);
struct StateT * slot_14(struct StateT * v637);
struct StateT * slot_17(struct StateT * v685);
struct StateT * slot_20(struct StateT * v741);
struct StateT * snippet(struct StateT * v0);
struct StateT * slot_8(struct StateT * v399);
struct StateT * slot_4(struct StateT * v243);
struct StateT * slot_15(struct StateT * v653);
struct StateT * slot_18(struct StateT * v701);
struct StateT * slot_9(struct StateT * v415);
struct StateT * slot_22(struct StateT * v937);
struct StateT * slot_11(struct StateT * v458);
struct StateT * slot_12(struct StateT * v562) {
  int * v563 = v562->saved_regs;
  int * v564 = v562->regs;
  int v565 = v564[12];
  v563[12] = v565;
  int v567 = v562->timer;
  int v581 = v567 + 1;
  v562->timer = v581;
  int * v569 = v562->regs;
  int v570 = v569[12];
  int * v571 = v562->regs;
  int v572 = v571[11];
  int * v573 = v562->regs;
  int v586 = v570 + v572;
  v573[12] = v586;
  struct StateT * v575 = slot_13(v562);
  return v575;
}

struct StateT * slot_6(struct StateT * v275) {
  int v276 = v275->timer;
  int v286 = v276 + 1;
  v275->timer = v286;
  int * v278 = v275->regs;
  int v279 = v278[11];
  int * v280 = v275->regs;
  int v281 = v280[14];
  int * v282 = v275->regs;
  int v292 = v279 + v281;
  v282[14] = v292;
  struct StateT * v284 = slot_7(v275);
  return v284;
}

struct StateT * slot_16(struct StateT * v669) {
  int v670 = v669->timer;
  int v678 = v670 + 1;
  v669->timer = v678;
  int * v672 = v669->regs;
  int v673 = v672[10];
  int * v674 = v669->regs;
  int v682 = v673 << 2;
  v674[10] = v682;
  struct StateT * v676 = slot_18(v669);
  return v676;
}

struct StateT * slot_23(struct StateT * v942) {
  int v943 = v942->timer;
  int v946 = v943 + 1;
  v942->timer = v946;
  return v942;
}

struct StateT * slot_5(struct StateT * v251) {
  int * v252 = v251->saved_regs;
  int * v253 = v251->regs;
  int v254 = v253[14];
  v252[14] = v254;
  int v256 = v251->timer;
  int v268 = v256 + 1;
  v251->timer = v268;
  int * v258 = v251->regs;
  int v259 = v258[10];
  int * v260 = v251->regs;
  int v272 = v259 << 2;
  v260[14] = v272;
  struct StateT * v262 = slot_6(v251);
  return v262;
}

struct StateT * slot_2(struct StateT * v211) {
  int v212 = v211->timer;
  int v218 = v212 + 1;
  v211->timer = v218;
  int * v214 = v211->regs;
  v214[15] = 15;
  struct StateT * v216 = slot_3(v211);
  return v216;
}

struct StateT * slot_7(struct StateT * v295) {
  int v296 = v295->timer;
  int v354 = v296 + 1;
  v295->timer = v354;
  int * v298 = v295->regs;
  int v299 = v298[14];
  int * v300 = v295->cache_keys;
  int v301 = v300[0];
  bool v359 = v301 == ((int)((unsigned int)v299 >> 2));
  int v349;
  if (v359) {
    int * v302 = v295->cache_vals;
    int v303 = v302[0];
    v349 = v303;
  } else {
    int * v305 = v295->cache_keys;
    int v306 = v305[1];
    bool v364 = v306 == ((int)((unsigned int)v299 >> 2));
    int v347;
    if (v364) {
      int * v307 = v295->cache_vals;
      int v308 = v307[1];
      int * v309 = v295->cache_keys;
      int * v310 = v295->cache_keys;
      int v311 = v310[0];
      v309[1] = v311;
      int * v313 = v295->cache_vals;
      int * v314 = v295->cache_vals;
      int v315 = v314[0];
      v313[1] = v315;
      int * v317 = v295->cache_keys;
      int v373 = (int)((unsigned int)v299 >> 2);
      v317[0] = v373;
      int * v319 = v295->cache_vals;
      v319[0] = v308;
      int v321 = v295->timer;
      int v376 = v321 + 1;
      v295->timer = v376;
      v347 = v308;
    } else {
      int * v324 = v295->mem;
      int v378 = (int)((unsigned int)v299 >> 2);
      int v325 = v324[v378];
      int * v326 = v295->mem;
      int * v327 = v295->cache_keys;
      int v328 = v327[1];
      int * v329 = v295->cache_vals;
      int v330 = v329[1];
      v326[v328] = v330;
      int * v332 = v295->cache_keys;
      int * v333 = v295->cache_keys;
      int v334 = v333[0];
      v332[1] = v334;
      int * v336 = v295->cache_vals;
      int * v337 = v295->cache_vals;
      int v338 = v337[0];
      v336[1] = v338;
      int * v340 = v295->cache_keys;
      v340[0] = v378;
      int * v342 = v295->cache_vals;
      v342[0] = v325;
      int v344 = v295->timer;
      int v393 = v344 + 100;
      v295->timer = v393;
      v347 = v325;
    }
    v349 = v347;
  }
  int * v350 = v295->regs;
  v350[14] = v349;
  struct StateT * v352 = slot_8(v295);
  return v352;
}

struct StateT * slot_21(struct StateT * v839) {
  int v840 = v839->timer;
  int v894 = v840 + 1;
  v839->timer = v894;
  int * v842 = v839->regs;
  int v843 = v842[10];
  int * v844 = v839->regs;
  int v845 = v844[12];
  int * v846 = v839->cache_keys;
  int v847 = v846[0];
  bool v901 = v847 == ((int)((unsigned int)v843 >> 2));
  int v891;
  if (v901) {
    int * v848 = v839->cache_vals;
    v848[0] = v845;
    v891 = v845;
  } else {
    int * v851 = v839->cache_keys;
    int v852 = v851[1];
    bool v906 = v852 == ((int)((unsigned int)v843 >> 2));
    int v889;
    if (v906) {
      int * v853 = v839->cache_keys;
      int * v854 = v839->cache_keys;
      int v855 = v854[0];
      v853[1] = v855;
      int * v857 = v839->cache_vals;
      int * v858 = v839->cache_vals;
      int v859 = v858[0];
      v857[1] = v859;
      int * v861 = v839->cache_keys;
      int v914 = (int)((unsigned int)v843 >> 2);
      v861[0] = v914;
      int * v863 = v839->cache_vals;
      v863[0] = v845;
      int v865 = v839->timer;
      int v917 = v865 + 1;
      v839->timer = v917;
      v889 = v845;
    } else {
      int * v868 = v839->mem;
      int * v869 = v839->cache_keys;
      int v870 = v869[1];
      int * v871 = v839->cache_vals;
      int v872 = v871[1];
      v868[v870] = v872;
      int * v874 = v839->cache_keys;
      int * v875 = v839->cache_keys;
      int v876 = v875[0];
      v874[1] = v876;
      int * v878 = v839->cache_vals;
      int * v879 = v839->cache_vals;
      int v880 = v879[0];
      v878[1] = v880;
      int * v882 = v839->cache_keys;
      int v930 = (int)((unsigned int)v843 >> 2);
      v882[0] = v930;
      int * v884 = v839->cache_vals;
      v884[0] = v845;
      int v886 = v839->timer;
      int v933 = v886 + 100;
      v839->timer = v933;
      v889 = v845;
    }
    v891 = v889;
  }
  struct StateT * v892 = slot_23(v839);
  return v892;
}

struct StateT * slot_3(struct StateT * v223) {
  int v224 = v223->timer;
  int v234 = v224 + 1;
  v223->timer = v234;
  int * v226 = v223->regs;
  int v227 = v226[12];
  int * v228 = v223->regs;
  int v229 = v228[14];
  int * v230 = v223->regs;
  int v240 = v227 ^ v229;
  v230[12] = v240;
  struct StateT * v232 = slot_4(v223);
  return v232;
}

struct StateT * slot_10(struct StateT * v431) {
  int * v432 = v431->saved_regs;
  int * v433 = v431->regs;
  int v434 = v433[11];
  v432[11] = v434;
  int v436 = v431->timer;
  int v450 = v436 + 1;
  v431->timer = v450;
  int * v438 = v431->regs;
  int v439 = v438[11];
  int * v440 = v431->regs;
  int v441 = v440[14];
  int * v442 = v431->regs;
  int v455 = v439 + v441;
  v442[11] = v455;
  struct StateT * v444 = slot_11(v431);
  return v444;
}

struct StateT * slot_1(struct StateT * v106) {
  int v107 = v106->timer;
  int v165 = v107 + 1;
  v106->timer = v165;
  int * v109 = v106->regs;
  int v110 = v109[11];
  int * v111 = v106->cache_keys;
  int v112 = v111[0];
  bool v170 = v112 == ((int)((unsigned int)(v110 + 12) >> 2));
  int v160;
  if (v170) {
    int * v113 = v106->cache_vals;
    int v114 = v113[0];
    v160 = v114;
  } else {
    int * v116 = v106->cache_keys;
    int v117 = v116[1];
    bool v175 = v117 == ((int)((unsigned int)(v110 + 12) >> 2));
    int v158;
    if (v175) {
      int * v118 = v106->cache_vals;
      int v119 = v118[1];
      int * v120 = v106->cache_keys;
      int * v121 = v106->cache_keys;
      int v122 = v121[0];
      v120[1] = v122;
      int * v124 = v106->cache_vals;
      int * v125 = v106->cache_vals;
      int v126 = v125[0];
      v124[1] = v126;
      int * v128 = v106->cache_keys;
      int v184 = (int)((unsigned int)(v110 + 12) >> 2);
      v128[0] = v184;
      int * v130 = v106->cache_vals;
      v130[0] = v119;
      int v132 = v106->timer;
      int v187 = v132 + 1;
      v106->timer = v187;
      v158 = v119;
    } else {
      int * v135 = v106->mem;
      int v189 = (int)((unsigned int)(v110 + 12) >> 2);
      int v136 = v135[v189];
      int * v137 = v106->mem;
      int * v138 = v106->cache_keys;
      int v139 = v138[1];
      int * v140 = v106->cache_vals;
      int v141 = v140[1];
      v137[v139] = v141;
      int * v143 = v106->cache_keys;
      int * v144 = v106->cache_keys;
      int v145 = v144[0];
      v143[1] = v145;
      int * v147 = v106->cache_vals;
      int * v148 = v106->cache_vals;
      int v149 = v148[0];
      v147[1] = v149;
      int * v151 = v106->cache_keys;
      v151[0] = v189;
      int * v153 = v106->cache_vals;
      v153[0] = v136;
      int v155 = v106->timer;
      int v204 = v155 + 100;
      v106->timer = v204;
      v158 = v136;
    }
    v160 = v158;
  }
  int * v161 = v106->regs;
  v161[14] = v160;
  struct StateT * v163 = slot_2(v106);
  return v163;
}

struct StateT * slot_19(struct StateT * v721) {
  int v722 = v721->timer;
  int v732 = v722 + 1;
  v721->timer = v732;
  int * v724 = v721->regs;
  int v725 = v724[13];
  int * v726 = v721->regs;
  int v727 = v726[10];
  int * v728 = v721->regs;
  int v738 = v725 + v727;
  v728[10] = v738;
  struct StateT * v730 = slot_21(v721);
  return v730;
}

struct StateT * slot_13(struct StateT * v589) {
  int * v590 = v589->regs;
  int v591 = v590[15];
  int * v592 = v589->regs;
  int v593 = v592[10];
  bool v618 = (v591 ^ -2147483648) < (v593 ^ -2147483648);
  struct StateT * v612;
  if (v618) {
    int v594 = v589->timer;
    int v619 = v594 + 15;
    v589->timer = v619;
    int * v596 = v589->saved_regs;
    int v597 = v596[14];
    int * v598 = v589->regs;
    v598[14] = v597;
    int * v600 = v589->saved_regs;
    int v601 = v600[11];
    int * v602 = v589->regs;
    v602[11] = v601;
    int * v604 = v589->saved_regs;
    int v605 = v604[12];
    int * v606 = v589->regs;
    v606[12] = v605;
    struct StateT * v608 = slot_14(v589);
    v612 = v608;
  } else {
    struct StateT * v610 = slot_15(v589);
    v612 = v610;
  }
  return v612;
}

struct StateT * slot_0(struct StateT * v2) {
  int v3 = v2->timer;
  int v61 = v3 + 1;
  v2->timer = v61;
  int * v5 = v2->regs;
  int v6 = v5[12];
  int * v7 = v2->cache_keys;
  int v8 = v7[0];
  bool v66 = v8 == ((int)((unsigned int)v6 >> 2));
  int v56;
  if (v66) {
    int * v9 = v2->cache_vals;
    int v10 = v9[0];
    v56 = v10;
  } else {
    int * v12 = v2->cache_keys;
    int v13 = v12[1];
    bool v71 = v13 == ((int)((unsigned int)v6 >> 2));
    int v54;
    if (v71) {
      int * v14 = v2->cache_vals;
      int v15 = v14[1];
      int * v16 = v2->cache_keys;
      int * v17 = v2->cache_keys;
      int v18 = v17[0];
      v16[1] = v18;
      int * v20 = v2->cache_vals;
      int * v21 = v2->cache_vals;
      int v22 = v21[0];
      v20[1] = v22;
      int * v24 = v2->cache_keys;
      int v80 = (int)((unsigned int)v6 >> 2);
      v24[0] = v80;
      int * v26 = v2->cache_vals;
      v26[0] = v15;
      int v28 = v2->timer;
      int v83 = v28 + 1;
      v2->timer = v83;
      v54 = v15;
    } else {
      int * v31 = v2->mem;
      int v85 = (int)((unsigned int)v6 >> 2);
      int v32 = v31[v85];
      int * v33 = v2->mem;
      int * v34 = v2->cache_keys;
      int v35 = v34[1];
      int * v36 = v2->cache_vals;
      int v37 = v36[1];
      v33[v35] = v37;
      int * v39 = v2->cache_keys;
      int * v40 = v2->cache_keys;
      int v41 = v40[0];
      v39[1] = v41;
      int * v43 = v2->cache_vals;
      int * v44 = v2->cache_vals;
      int v45 = v44[0];
      v43[1] = v45;
      int * v47 = v2->cache_keys;
      v47[0] = v85;
      int * v49 = v2->cache_vals;
      v49[0] = v32;
      int v51 = v2->timer;
      int v100 = v51 + 100;
      v2->timer = v100;
      v54 = v32;
    }
    v56 = v54;
  }
  int * v57 = v2->regs;
  v57[12] = v56;
  struct StateT * v59 = slot_1(v2);
  return v59;
}

struct StateT * slot_14(struct StateT * v637) {
  int v638 = v637->timer;
  int v646 = v638 + 1;
  v637->timer = v646;
  int * v640 = v637->regs;
  int v641 = v640[10];
  int * v642 = v637->regs;
  int v650 = v641 & 7;
  v642[10] = v650;
  struct StateT * v644 = slot_16(v637);
  return v644;
}

struct StateT * slot_17(struct StateT * v685) {
  int v686 = v685->timer;
  int v694 = v686 + 1;
  v685->timer = v694;
  int * v688 = v685->regs;
  int v689 = v688[10];
  int * v690 = v685->regs;
  int v698 = v689 << 2;
  v690[10] = v698;
  struct StateT * v692 = slot_19(v685);
  return v692;
}

struct StateT * slot_20(struct StateT * v741) {
  int v742 = v741->timer;
  int v796 = v742 + 1;
  v741->timer = v796;
  int * v744 = v741->regs;
  int v745 = v744[10];
  int * v746 = v741->regs;
  int v747 = v746[12];
  int * v748 = v741->cache_keys;
  int v749 = v748[0];
  bool v803 = v749 == ((int)((unsigned int)v745 >> 2));
  int v793;
  if (v803) {
    int * v750 = v741->cache_vals;
    v750[0] = v747;
    v793 = v747;
  } else {
    int * v753 = v741->cache_keys;
    int v754 = v753[1];
    bool v808 = v754 == ((int)((unsigned int)v745 >> 2));
    int v791;
    if (v808) {
      int * v755 = v741->cache_keys;
      int * v756 = v741->cache_keys;
      int v757 = v756[0];
      v755[1] = v757;
      int * v759 = v741->cache_vals;
      int * v760 = v741->cache_vals;
      int v761 = v760[0];
      v759[1] = v761;
      int * v763 = v741->cache_keys;
      int v816 = (int)((unsigned int)v745 >> 2);
      v763[0] = v816;
      int * v765 = v741->cache_vals;
      v765[0] = v747;
      int v767 = v741->timer;
      int v819 = v767 + 1;
      v741->timer = v819;
      v791 = v747;
    } else {
      int * v770 = v741->mem;
      int * v771 = v741->cache_keys;
      int v772 = v771[1];
      int * v773 = v741->cache_vals;
      int v774 = v773[1];
      v770[v772] = v774;
      int * v776 = v741->cache_keys;
      int * v777 = v741->cache_keys;
      int v778 = v777[0];
      v776[1] = v778;
      int * v780 = v741->cache_vals;
      int * v781 = v741->cache_vals;
      int v782 = v781[0];
      v780[1] = v782;
      int * v784 = v741->cache_keys;
      int v832 = (int)((unsigned int)v745 >> 2);
      v784[0] = v832;
      int * v786 = v741->cache_vals;
      v786[0] = v747;
      int v788 = v741->timer;
      int v835 = v788 + 100;
      v741->timer = v835;
      v791 = v747;
    }
    v793 = v791;
  }
  struct StateT * v794 = slot_22(v741);
  return v794;
}

struct StateT * snippet(struct StateT * v0) {
  struct StateT * v1 = slot_0(v0);
  return v1;
}

struct StateT * slot_8(struct StateT * v399) {
  int v400 = v399->timer;
  int v408 = v400 + 1;
  v399->timer = v408;
  int * v402 = v399->regs;
  int v403 = v402[14];
  int * v404 = v399->regs;
  int v412 = v403 & 15;
  v404[14] = v412;
  struct StateT * v406 = slot_9(v399);
  return v406;
}

struct StateT * slot_4(struct StateT * v243) {
  int v244 = v243->timer;
  int v248 = v244 + 1;
  v243->timer = v248;
  struct StateT * v246 = slot_5(v243);
  return v246;
}

struct StateT * slot_15(struct StateT * v653) {
  int v654 = v653->timer;
  int v662 = v654 + 1;
  v653->timer = v662;
  int * v656 = v653->regs;
  int v657 = v656[10];
  int * v658 = v653->regs;
  int v666 = v657 & 7;
  v658[10] = v666;
  struct StateT * v660 = slot_17(v653);
  return v660;
}

struct StateT * slot_18(struct StateT * v701) {
  int v702 = v701->timer;
  int v712 = v702 + 1;
  v701->timer = v712;
  int * v704 = v701->regs;
  int v705 = v704[13];
  int * v706 = v701->regs;
  int v707 = v706[10];
  int * v708 = v701->regs;
  int v718 = v705 + v707;
  v708[10] = v718;
  struct StateT * v710 = slot_20(v701);
  return v710;
}

struct StateT * slot_9(struct StateT * v415) {
  int v416 = v415->timer;
  int v424 = v416 + 1;
  v415->timer = v424;
  int * v418 = v415->regs;
  int v419 = v418[14];
  int * v420 = v415->regs;
  int v428 = v419 << 2;
  v420[14] = v428;
  struct StateT * v422 = slot_10(v415);
  return v422;
}

struct StateT * slot_22(struct StateT * v937) {
  int v938 = v937->timer;
  int v941 = v938 + 1;
  v937->timer = v941;
  return v937;
}

struct StateT * slot_11(struct StateT * v458) {
  int v459 = v458->timer;
  int v517 = v459 + 1;
  v458->timer = v517;
  int * v461 = v458->regs;
  int v462 = v461[11];
  int * v463 = v458->cache_keys;
  int v464 = v463[0];
  bool v522 = v464 == ((int)((unsigned int)v462 >> 2));
  int v512;
  if (v522) {
    int * v465 = v458->cache_vals;
    int v466 = v465[0];
    v512 = v466;
  } else {
    int * v468 = v458->cache_keys;
    int v469 = v468[1];
    bool v527 = v469 == ((int)((unsigned int)v462 >> 2));
    int v510;
    if (v527) {
      int * v470 = v458->cache_vals;
      int v471 = v470[1];
      int * v472 = v458->cache_keys;
      int * v473 = v458->cache_keys;
      int v474 = v473[0];
      v472[1] = v474;
      int * v476 = v458->cache_vals;
      int * v477 = v458->cache_vals;
      int v478 = v477[0];
      v476[1] = v478;
      int * v480 = v458->cache_keys;
      int v536 = (int)((unsigned int)v462 >> 2);
      v480[0] = v536;
      int * v482 = v458->cache_vals;
      v482[0] = v471;
      int v484 = v458->timer;
      int v539 = v484 + 1;
      v458->timer = v539;
      v510 = v471;
    } else {
      int * v487 = v458->mem;
      int v541 = (int)((unsigned int)v462 >> 2);
      int v488 = v487[v541];
      int * v489 = v458->mem;
      int * v490 = v458->cache_keys;
      int v491 = v490[1];
      int * v492 = v458->cache_vals;
      int v493 = v492[1];
      v489[v491] = v493;
      int * v495 = v458->cache_keys;
      int * v496 = v458->cache_keys;
      int v497 = v496[0];
      v495[1] = v497;
      int * v499 = v458->cache_vals;
      int * v500 = v458->cache_vals;
      int v501 = v500[0];
      v499[1] = v501;
      int * v503 = v458->cache_keys;
      v503[0] = v541;
      int * v505 = v458->cache_vals;
      v505[0] = v488;
      int v507 = v458->timer;
      int v556 = v507 + 100;
      v458->timer = v556;
      v510 = v488;
    }
    v512 = v510;
  }
  int * v513 = v458->regs;
  v513[11] = v512;
  struct StateT * v515 = slot_12(v458);
  return v515;
}



/*****************************************
End of C Generated Code
*******************************************/

void init(struct StateT *s) {
  for (int i=0; i<NUM_REGS; i++) {
    s->regs[i] = 0;
    s->saved_regs[i] = 0;
  }
  s->regs[2] = 4 * MEM_SIZE;
  s->timer = 0;
  for (int i=0; i<MEM_SIZE; i++) {
    s->mem[i] = 0;
  }
  for (int i=0; i<CACHE_LRU_SIZE; i++) {
    s->cache_keys[i] = -1;
    s->cache_vals[i] = -1;
  }
}

int main(int argc, char* argv[]) {
  struct StateT s1, s2;
  init(&s1);
  init(&s2);
  
  // a10, public: one draw, written into both states
  int a10 = bounded(0, 23);
  s1.regs[10] = a10;
  s2.regs[10] = a10;
  // a11, 16 words read by the callee: the address is public
  s1.regs[11] = 0;
  s2.regs[11] = 0;
  // its contents, public: the same draw in both states
  for (int i=0; i<16; i++) {
    int v = bounded(0, 20);
    s1.mem[0 + i] = v;
    s2.mem[0 + i] = v;
  }
  // a12, 8 words read by the callee: the address is public
  s1.regs[12] = 64;
  s2.regs[12] = 64;
  // a13, 8 words written by the callee: the address is public
  s1.regs[13] = 96;
  s2.regs[13] = 96;
  
  // a12's contents, secret: a different draw in each state
  for (int i=0; i<8; i++) {
    s1.mem[16 + i] = bounded(0, 20);
    s2.mem[16 + i] = bounded(0, 20);
  }
  struct StateT *s1_ = snippet(&s1);
  struct StateT *s2_ = snippet(&s2);
  koika_assert(s1_->timer==s2_->timer, "timing leak");
  return 0;
}