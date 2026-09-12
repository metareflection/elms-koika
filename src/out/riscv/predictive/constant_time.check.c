
#define NUM_REGS 32
#define MEM_SIZE 30
#define SECRET_SIZE 10
#define SECRET_OFFSET 20
#define CACHE_LRU_SIZE 10
#define BHT_SIZE 1
#ifndef CBMC
#define __CPROVER_assert(b,s) 0
#define nondet_uint() 0
#else
int nondet_uint();
#endif
int bounded(int low, int high) {
  int x = nondet_uint();
  __CPROVER_assume(low <= x && x <= high);
  return x;
}
struct StateT {
  int regs[NUM_REGS];
  int mem[MEM_SIZE];
  int saved_regs[NUM_REGS];
  int cache_keys[CACHE_LRU_SIZE];
  int cache_vals[CACHE_LRU_SIZE];
  int timer;
  int bht[BHT_SIZE];
};

void init(struct StateT *s) {
  for (int i=0; i<NUM_REGS; i++) {
    s->regs[i] = 0;
    s->saved_regs[i] = 0;
  }
  s->timer = 0;
  for (int i=0; i<MEM_SIZE; i++) {
    s->mem[i] = 0;
  }
  for (int i=0; i<CACHE_LRU_SIZE; i++) {
    s->cache_keys[i] = -1;
    s->cache_vals[i] = -1;
  }
  for (int i=0; i<BHT_SIZE; i++) {
    s->bht[i] = 0;
  }
}

/*****************************************
Emitting C Generated Code
*******************************************/

#include <stdbool.h>
#include <stdlib.h>

struct StateT * v19(struct StateT * v20);
struct StateT * v25(struct StateT * v26);
struct StateT * v70(struct StateT * v71);
struct StateT * v206(struct StateT * v207);
struct StateT * v653(struct StateT * v654);
struct StateT * v37(struct StateT * v38);
struct StateT * v512(struct StateT * v513);
struct StateT * v31(struct StateT * v32);
struct StateT * v216(struct StateT * v217);
struct StateT * v52(struct StateT * v53);
struct StateT * v7(struct StateT * v8);
struct StateT * v234(struct StateT * v235);
struct StateT * v80(struct StateT * v81);
struct StateT * v436(struct StateT * v437);
struct StateT * v13(struct StateT * v14);
struct StateT * v226(struct StateT * v227);
struct StateT * v526(struct StateT * v527);
struct StateT * v450(struct StateT * v451);
struct StateT * v138(struct StateT * v139);
struct StateT * v148(struct StateT * v149);
struct StateT * snippet(struct StateT * v0);
struct StateT * v1(struct StateT * v2);
struct StateT * v616(struct StateT * v617);
struct StateT * v588(struct StateT * v589);
struct StateT * v602(struct StateT * v603);
struct StateT * v19(struct StateT * v20) {
  int v21 = v20->timer;
  int v904 = v21 + 1;
  v20->timer = v904;int * v23 = v20->regs;
  v23[15] = 16;
  struct StateT * v902 = v25(v20);
  return v902;
}

struct StateT * v25(struct StateT * v26) {
  int v27 = v26->timer;
  int v896 = v27 + 1;
  v26->timer = v896;int * v29 = v26->regs;
  v29[5] = 0;
  struct StateT * v894 = v31(v26);
  return v894;
}

struct StateT * v70(struct StateT * v71) {
  int v72 = v71->timer;
  int v386 = v72 + 1;
  v71->timer = v386;int * v74 = v71->regs;
  int v75 = v74[12];
  int * v76 = v71->regs;
  int v77 = v76[14];
  int * v78 = v71->regs;
  int v393 = v75 + v77;
  v78[6] = v393;
  struct StateT * v384 = v80(v71);
  return v384;
}

struct StateT * v206(struct StateT * v207) {
  int v208 = v207->timer;
  int v266 = v208 + 1;
  v207->timer = v266;int * v210 = v207->regs;
  int v211 = v210[7];
  int * v212 = v207->regs;
  int v213 = v212[9];
  int * v214 = v207->regs;
  int v273 = v211 ^ v213;
  v214[16] = v273;
  struct StateT * v264 = v216(v207);
  return v264;
}

struct StateT * v653(struct StateT * v654) {
  int v655 = v654->timer;
  int v665 = v655 + 1;
  v654->timer = v665;int * v657 = v654->regs;
  int v658 = v657[5];
  bool v668 = (v658 ^ -2147483648) < -2147483647;
  int v661 = (v668 ? 1 : 0);
  int * v662 = v654->regs;
  v662[11] = v661;
  return v654;
}

struct StateT * v37(struct StateT * v38) {
  int * v39 = v38->saved_regs;
  int * v40 = v38->regs;
  int v41 = v40[11];
  v39[11] = v41;
  int v43 = v38->timer;
  int v424 = v43 + 1;
  v38->timer = v424;int * v45 = v38->regs;
  int v46 = v45[5];
  bool v427 = (v46 ^ -2147483648) < -2147483647;
  int v49 = (v427 ? 1 : 0);
  int * v50 = v38->regs;
  v50[11] = v49;
  struct StateT * v418 = v52(v38);
  return v418;
}

struct StateT * v512(struct StateT * v513) {
  int * v514 = v513->saved_regs;
  int * v515 = v513->regs;
  int v516 = v515[8];
  v514[8] = v516;
  int v518 = v513->timer;
  int v806 = v518 + 1;
  v513->timer = v806;int * v520 = v513->regs;
  int v521 = v520[13];
  int * v522 = v513->regs;
  int v523 = v522[14];
  int * v524 = v513->regs;
  int v812 = v521 + v523;
  v524[8] = v812;
  struct StateT * v800 = v526(v513);
  return v800;
}

struct StateT * v31(struct StateT * v32) {
  int v33 = v32->timer;
  int v885 = v33 + 1;
  v32->timer = v885;int * v35 = v32->bht;
  int v36 = v35[0];
  bool v888 = !(v36 == 0);
  struct StateT * v883 = (v888 ? ({
    struct StateT * v434 = v37(v32);
    v434;
  }) : ({
    struct StateT * v881 = v436(v32);
    v881;
  }));
  return v883;
}

struct StateT * v216(struct StateT * v217) {
  int v218 = v217->timer;
  int v255 = v218 + 1;
  v217->timer = v255;int * v220 = v217->regs;
  int v221 = v220[5];
  int * v222 = v217->regs;
  int v223 = v222[16];
  int * v224 = v217->regs;
  int v261 = v221 | v223;
  v224[5] = v261;
  struct StateT * v253 = v226(v217);
  return v253;
}

struct StateT * v52(struct StateT * v53) {
  int * v54 = v53->regs;
  int v55 = v54[14];
  int * v56 = v53->regs;
  int v57 = v56[15];
  int * v58 = v53->bht;
  bool v404 = v55 >= v57;
  int v61 = (v404 ? 1 : 0);
  v58[0] = v61;
  struct StateT * v398 = (v404 ? v53 : ({
    int v64 = v53->timer;
    int v410 = v64 + 15;
    v53->timer = v410;int * v66 = v53->saved_regs;
    int v67 = v66[11];
    int * v68 = v53->regs;
    v68[11] = v67;
    struct StateT * v396 = v70(v53);
    v396;
  }));
  return v398;
}

struct StateT * v7(struct StateT * v8) {
  int v9 = v8->timer;
  int v920 = v9 + 1;
  v8->timer = v920;int * v11 = v8->regs;
  v11[13] = 80;
  struct StateT * v918 = v13(v8);
  return v918;
}

struct StateT * v234(struct StateT * v235) {
  int v236 = v235->timer;
  int v241 = v236 + 1;
  v235->timer = v241;struct StateT * v239 = v31(v235);
  return v239;
}

struct StateT * v80(struct StateT * v81) {
  int v82 = v81->timer;
  int v338 = v82 + 1;
  v81->timer = v338;int * v84 = v81->regs;
  int v85 = v84[6];
  int * v86 = v81->cache_keys;
  int v87 = v86[0];
  bool v343 = v87 == ((int)((unsigned int)v85 >> 2));
  int v135 = (v343 ? ({
    int * v88 = v81->cache_vals;
    int v89 = v88[0];
    v89;
  }) : ({
    int * v91 = v81->cache_keys;
    int v92 = v91[1];
    bool v348 = v92 == ((int)((unsigned int)v85 >> 2));
    int v133 = (v348 ? ({
      int * v93 = v81->cache_vals;
      int v94 = v93[1];
      int * v95 = v81->cache_keys;
      int * v96 = v81->cache_keys;
      int v97 = v96[0];
      v95[1] = v97;
      int * v99 = v81->cache_vals;
      int * v100 = v81->cache_vals;
      int v101 = v100[0];
      v99[1] = v101;
      int * v103 = v81->cache_keys;
      int v357 = (int)((unsigned int)v85 >> 2);
      v103[0] = v357;
      int * v105 = v81->cache_vals;
      v105[0] = v94;
      int v107 = v81->timer;
      int v360 = v107 + 1;
      v81->timer = v360;v94;
    }) : ({
      int * v110 = v81->mem;
      int v362 = (int)((unsigned int)v85 >> 2);
      int v111 = v110[v362];
      int * v112 = v81->mem;
      int * v113 = v81->cache_keys;
      int v114 = v113[1];
      int * v115 = v81->cache_vals;
      int v116 = v115[1];
      v112[v114] = v116;
      int * v118 = v81->cache_keys;
      int * v119 = v81->cache_keys;
      int v120 = v119[0];
      v118[1] = v120;
      int * v122 = v81->cache_vals;
      int * v123 = v81->cache_vals;
      int v124 = v123[0];
      v122[1] = v124;
      int * v126 = v81->cache_keys;
      v126[0] = v362;
      int * v128 = v81->cache_vals;
      v128[0] = v111;
      int v130 = v81->timer;
      int v377 = v130 + 100;
      v81->timer = v377;v111;
    }));
    v133;
  }));
  int * v136 = v81->regs;
  v136[7] = v135;
  struct StateT * v336 = v138(v81);
  return v336;
}

struct StateT * v436(struct StateT * v437) {
  int * v438 = v437->saved_regs;
  int * v439 = v437->regs;
  int v440 = v439[6];
  v438[6] = v440;
  int v442 = v437->timer;
  int v872 = v442 + 1;
  v437->timer = v872;int * v444 = v437->regs;
  int v445 = v444[12];
  int * v446 = v437->regs;
  int v447 = v446[14];
  int * v448 = v437->regs;
  int v878 = v445 + v447;
  v448[6] = v878;
  struct StateT * v866 = v450(v437);
  return v866;
}

struct StateT * v13(struct StateT * v14) {
  int v15 = v14->timer;
  int v912 = v15 + 1;
  v14->timer = v912;int * v17 = v14->regs;
  v17[14] = 0;
  struct StateT * v910 = v19(v14);
  return v910;
}

struct StateT * v226(struct StateT * v227) {
  int v228 = v227->timer;
  int v246 = v228 + 1;
  v227->timer = v246;int * v230 = v227->regs;
  int v231 = v230[14];
  int * v232 = v227->regs;
  int v250 = v231 + 4;
  v232[14] = v250;
  struct StateT * v244 = v234(v227);
  return v244;
}

struct StateT * v526(struct StateT * v527) {
  int * v528 = v527->saved_regs;
  int * v529 = v527->regs;
  int v530 = v529[9];
  v528[9] = v530;
  int v532 = v527->timer;
  int v755 = v532 + 1;
  v527->timer = v755;int * v534 = v527->regs;
  int v535 = v534[8];
  int * v536 = v527->cache_keys;
  int v537 = v536[0];
  bool v760 = v537 == ((int)((unsigned int)v535 >> 2));
  int v585 = (v760 ? ({
    int * v538 = v527->cache_vals;
    int v539 = v538[0];
    v539;
  }) : ({
    int * v541 = v527->cache_keys;
    int v542 = v541[1];
    bool v765 = v542 == ((int)((unsigned int)v535 >> 2));
    int v583 = (v765 ? ({
      int * v543 = v527->cache_vals;
      int v544 = v543[1];
      int * v545 = v527->cache_keys;
      int * v546 = v527->cache_keys;
      int v547 = v546[0];
      v545[1] = v547;
      int * v549 = v527->cache_vals;
      int * v550 = v527->cache_vals;
      int v551 = v550[0];
      v549[1] = v551;
      int * v553 = v527->cache_keys;
      int v774 = (int)((unsigned int)v535 >> 2);
      v553[0] = v774;
      int * v555 = v527->cache_vals;
      v555[0] = v544;
      int v557 = v527->timer;
      int v777 = v557 + 1;
      v527->timer = v777;v544;
    }) : ({
      int * v560 = v527->mem;
      int v779 = (int)((unsigned int)v535 >> 2);
      int v561 = v560[v779];
      int * v562 = v527->mem;
      int * v563 = v527->cache_keys;
      int v564 = v563[1];
      int * v565 = v527->cache_vals;
      int v566 = v565[1];
      v562[v564] = v566;
      int * v568 = v527->cache_keys;
      int * v569 = v527->cache_keys;
      int v570 = v569[0];
      v568[1] = v570;
      int * v572 = v527->cache_vals;
      int * v573 = v527->cache_vals;
      int v574 = v573[0];
      v572[1] = v574;
      int * v576 = v527->cache_keys;
      v576[0] = v779;
      int * v578 = v527->cache_vals;
      v578[0] = v561;
      int v580 = v527->timer;
      int v794 = v580 + 100;
      v527->timer = v794;v561;
    }));
    v583;
  }));
  int * v586 = v527->regs;
  v586[9] = v585;
  struct StateT * v749 = v588(v527);
  return v749;
}

struct StateT * v450(struct StateT * v451) {
  int * v452 = v451->saved_regs;
  int * v453 = v451->regs;
  int v454 = v453[7];
  v452[7] = v454;
  int v456 = v451->timer;
  int v821 = v456 + 1;
  v451->timer = v821;int * v458 = v451->regs;
  int v459 = v458[6];
  int * v460 = v451->cache_keys;
  int v461 = v460[0];
  bool v826 = v461 == ((int)((unsigned int)v459 >> 2));
  int v509 = (v826 ? ({
    int * v462 = v451->cache_vals;
    int v463 = v462[0];
    v463;
  }) : ({
    int * v465 = v451->cache_keys;
    int v466 = v465[1];
    bool v831 = v466 == ((int)((unsigned int)v459 >> 2));
    int v507 = (v831 ? ({
      int * v467 = v451->cache_vals;
      int v468 = v467[1];
      int * v469 = v451->cache_keys;
      int * v470 = v451->cache_keys;
      int v471 = v470[0];
      v469[1] = v471;
      int * v473 = v451->cache_vals;
      int * v474 = v451->cache_vals;
      int v475 = v474[0];
      v473[1] = v475;
      int * v477 = v451->cache_keys;
      int v840 = (int)((unsigned int)v459 >> 2);
      v477[0] = v840;
      int * v479 = v451->cache_vals;
      v479[0] = v468;
      int v481 = v451->timer;
      int v843 = v481 + 1;
      v451->timer = v843;v468;
    }) : ({
      int * v484 = v451->mem;
      int v845 = (int)((unsigned int)v459 >> 2);
      int v485 = v484[v845];
      int * v486 = v451->mem;
      int * v487 = v451->cache_keys;
      int v488 = v487[1];
      int * v489 = v451->cache_vals;
      int v490 = v489[1];
      v486[v488] = v490;
      int * v492 = v451->cache_keys;
      int * v493 = v451->cache_keys;
      int v494 = v493[0];
      v492[1] = v494;
      int * v496 = v451->cache_vals;
      int * v497 = v451->cache_vals;
      int v498 = v497[0];
      v496[1] = v498;
      int * v500 = v451->cache_keys;
      v500[0] = v845;
      int * v502 = v451->cache_vals;
      v502[0] = v485;
      int v504 = v451->timer;
      int v860 = v504 + 100;
      v451->timer = v860;v485;
    }));
    v507;
  }));
  int * v510 = v451->regs;
  v510[7] = v509;
  struct StateT * v815 = v512(v451);
  return v815;
}

struct StateT * v138(struct StateT * v139) {
  int v140 = v139->timer;
  int v326 = v140 + 1;
  v139->timer = v326;int * v142 = v139->regs;
  int v143 = v142[13];
  int * v144 = v139->regs;
  int v145 = v144[14];
  int * v146 = v139->regs;
  int v333 = v143 + v145;
  v146[8] = v333;
  struct StateT * v324 = v148(v139);
  return v324;
}

struct StateT * v148(struct StateT * v149) {
  int v150 = v149->timer;
  int v278 = v150 + 1;
  v149->timer = v278;int * v152 = v149->regs;
  int v153 = v152[8];
  int * v154 = v149->cache_keys;
  int v155 = v154[0];
  bool v283 = v155 == ((int)((unsigned int)v153 >> 2));
  int v203 = (v283 ? ({
    int * v156 = v149->cache_vals;
    int v157 = v156[0];
    v157;
  }) : ({
    int * v159 = v149->cache_keys;
    int v160 = v159[1];
    bool v288 = v160 == ((int)((unsigned int)v153 >> 2));
    int v201 = (v288 ? ({
      int * v161 = v149->cache_vals;
      int v162 = v161[1];
      int * v163 = v149->cache_keys;
      int * v164 = v149->cache_keys;
      int v165 = v164[0];
      v163[1] = v165;
      int * v167 = v149->cache_vals;
      int * v168 = v149->cache_vals;
      int v169 = v168[0];
      v167[1] = v169;
      int * v171 = v149->cache_keys;
      int v297 = (int)((unsigned int)v153 >> 2);
      v171[0] = v297;
      int * v173 = v149->cache_vals;
      v173[0] = v162;
      int v175 = v149->timer;
      int v300 = v175 + 1;
      v149->timer = v300;v162;
    }) : ({
      int * v178 = v149->mem;
      int v302 = (int)((unsigned int)v153 >> 2);
      int v179 = v178[v302];
      int * v180 = v149->mem;
      int * v181 = v149->cache_keys;
      int v182 = v181[1];
      int * v183 = v149->cache_vals;
      int v184 = v183[1];
      v180[v182] = v184;
      int * v186 = v149->cache_keys;
      int * v187 = v149->cache_keys;
      int v188 = v187[0];
      v186[1] = v188;
      int * v190 = v149->cache_vals;
      int * v191 = v149->cache_vals;
      int v192 = v191[0];
      v190[1] = v192;
      int * v194 = v149->cache_keys;
      v194[0] = v302;
      int * v196 = v149->cache_vals;
      v196[0] = v179;
      int v198 = v149->timer;
      int v317 = v198 + 100;
      v149->timer = v317;v179;
    }));
    v201;
  }));
  int * v204 = v149->regs;
  v204[9] = v203;
  struct StateT * v276 = v206(v149);
  return v276;
}

struct StateT * snippet(struct StateT * v0) {
  struct StateT * v934 = v1(v0);
  return v934;
}

struct StateT * v1(struct StateT * v2) {
  int v3 = v2->timer;
  int v928 = v3 + 1;
  v2->timer = v928;int * v5 = v2->regs;
  v5[12] = 0;
  struct StateT * v926 = v7(v2);
  return v926;
}

struct StateT * v616(struct StateT * v617) {
  int * v618 = v617->regs;
  int v619 = v618[14];
  int * v620 = v617->regs;
  int v621 = v620[15];
  int * v622 = v617->bht;
  bool v684 = v619 >= v621;
  int v625 = (v684 ? 1 : 0);
  v622[0] = v625;
  struct StateT * v678 = (v684 ? ({
    int v627 = v617->timer;
    int v690 = v627 + 15;
    v617->timer = v690;int * v629 = v617->saved_regs;
    int v630 = v629[6];
    int * v631 = v617->regs;
    v631[6] = v630;
    int * v633 = v617->saved_regs;
    int v634 = v633[7];
    int * v635 = v617->regs;
    v635[7] = v634;
    int * v637 = v617->saved_regs;
    int v638 = v637[8];
    int * v639 = v617->regs;
    v639[8] = v638;
    int * v641 = v617->saved_regs;
    int v642 = v641[9];
    int * v643 = v617->regs;
    v643[9] = v642;
    int * v645 = v617->saved_regs;
    int v646 = v645[16];
    int * v647 = v617->regs;
    v647[16] = v646;
    int * v649 = v617->saved_regs;
    int v650 = v649[5];
    int * v651 = v617->regs;
    v651[5] = v650;
    struct StateT * v674 = v653(v617);
    v674;
  }) : ({
    struct StateT * v676 = v226(v617);
    v676;
  }));
  return v678;
}

struct StateT * v588(struct StateT * v589) {
  int * v590 = v589->saved_regs;
  int * v591 = v589->regs;
  int v592 = v591[16];
  v590[16] = v592;
  int v594 = v589->timer;
  int v740 = v594 + 1;
  v589->timer = v740;int * v596 = v589->regs;
  int v597 = v596[7];
  int * v598 = v589->regs;
  int v599 = v598[9];
  int * v600 = v589->regs;
  int v746 = v597 ^ v599;
  v600[16] = v746;
  struct StateT * v734 = v602(v589);
  return v734;
}

struct StateT * v602(struct StateT * v603) {
  int * v604 = v603->saved_regs;
  int * v605 = v603->regs;
  int v606 = v605[5];
  v604[5] = v606;
  int v608 = v603->timer;
  int v726 = v608 + 1;
  v603->timer = v726;int * v610 = v603->regs;
  int v611 = v610[5];
  int * v612 = v603->regs;
  int v613 = v612[16];
  int * v614 = v603->regs;
  int v731 = v611 | v613;
  v614[5] = v731;
  struct StateT * v720 = v616(v603);
  return v720;
}



/*****************************************
End of C Generated Code
*******************************************/

int main(int argc, char* argv[]) {
  struct StateT s1, s2;
  init(&s1);
  init(&s2);
  
  int x = bounded(0, 80);
  s1.regs[10] = x;
  s2.regs[10] = x;
  
  // initialize secret
  for (int i=0; i<SECRET_SIZE; i++) {
    s1.mem[SECRET_OFFSET+i] = bounded(0, 20);
    s2.mem[SECRET_OFFSET+i] = bounded(0, 20);
  }
  struct StateT *s1_ = snippet(&s1);
  struct StateT *s2_ = snippet(&s2);
  __CPROVER_assert(s1_->timer==s2_->timer, "timing leak");
  return 0;
}