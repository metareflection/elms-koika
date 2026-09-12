
#define NUM_REGS 32
#define MEM_SIZE 30
#define SECRET_SIZE 10
#define SECRET_OFFSET 20
#define CACHE_LRU_SIZE 10
#define BHT_SIZE 2
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
struct StateT * v534(struct StateT * v535);
struct StateT * v218(struct StateT * v219);
struct StateT * v195(struct StateT * v196);
struct StateT * v672(struct StateT * v673);
struct StateT * v127(struct StateT * v128);
struct StateT * v31(struct StateT * v32);
struct StateT * v212(struct StateT * v213);
struct StateT * v69(struct StateT * v70);
struct StateT * v137(struct StateT * v138);
struct StateT * v7(struct StateT * v8);
struct StateT * v285(struct StateT * v286);
struct StateT * v236(struct StateT * v237);
struct StateT * v13(struct StateT * v14);
struct StateT * v297(struct StateT * v298);
struct StateT * v701(struct StateT * v702);
struct StateT * v41(struct StateT * v42);
struct StateT * v520(struct StateT * v521);
struct StateT * v610(struct StateT * v611);
struct StateT * v201(struct StateT * v202);
struct StateT * v596(struct StateT * v597);
struct StateT * snippet(struct StateT * v0);
struct StateT * v244(struct StateT * v245);
struct StateT * v1(struct StateT * v2);
struct StateT * v59(struct StateT * v60);
struct StateT * v19(struct StateT * v20) {
  int v21 = v20->timer;
  int v897 = v21 + 1;
  v20->timer = v897;int * v23 = v20->regs;
  v23[15] = 16;
  struct StateT * v895 = v25(v20);
  return v895;
}

struct StateT * v25(struct StateT * v26) {
  int v27 = v26->timer;
  int v886 = v27 + 1;
  v26->timer = v886;int * v29 = v26->bht;
  int v30 = v29[0];
  bool v889 = !(v30 == 0);
  struct StateT * v884 = (v889 ? ({
    struct StateT * v518 = v31(v26);
    v518;
  }) : ({
    struct StateT * v882 = v520(v26);
    v882;
  }));
  return v884;
}

struct StateT * v534(struct StateT * v535) {
  int * v536 = v535->saved_regs;
  int * v537 = v535->regs;
  int v538 = v537[10];
  v536[10] = v538;
  int v540 = v535->timer;
  int v822 = v540 + 1;
  v535->timer = v822;int * v542 = v535->regs;
  int v543 = v542[5];
  int * v544 = v535->cache_keys;
  int v545 = v544[0];
  bool v827 = v545 == ((int)((unsigned int)v543 >> 2));
  int v593 = (v827 ? ({
    int * v546 = v535->cache_vals;
    int v547 = v546[0];
    v547;
  }) : ({
    int * v549 = v535->cache_keys;
    int v550 = v549[1];
    bool v832 = v550 == ((int)((unsigned int)v543 >> 2));
    int v591 = (v832 ? ({
      int * v551 = v535->cache_vals;
      int v552 = v551[1];
      int * v553 = v535->cache_keys;
      int * v554 = v535->cache_keys;
      int v555 = v554[0];
      v553[1] = v555;
      int * v557 = v535->cache_vals;
      int * v558 = v535->cache_vals;
      int v559 = v558[0];
      v557[1] = v559;
      int * v561 = v535->cache_keys;
      int v841 = (int)((unsigned int)v543 >> 2);
      v561[0] = v841;
      int * v563 = v535->cache_vals;
      v563[0] = v552;
      int v565 = v535->timer;
      int v844 = v565 + 1;
      v535->timer = v844;v552;
    }) : ({
      int * v568 = v535->mem;
      int v846 = (int)((unsigned int)v543 >> 2);
      int v569 = v568[v846];
      int * v570 = v535->mem;
      int * v571 = v535->cache_keys;
      int v572 = v571[1];
      int * v573 = v535->cache_vals;
      int v574 = v573[1];
      v570[v572] = v574;
      int * v576 = v535->cache_keys;
      int * v577 = v535->cache_keys;
      int v578 = v577[0];
      v576[1] = v578;
      int * v580 = v535->cache_vals;
      int * v581 = v535->cache_vals;
      int v582 = v581[0];
      v580[1] = v582;
      int * v584 = v535->cache_keys;
      v584[0] = v846;
      int * v586 = v535->cache_vals;
      v586[0] = v569;
      int v588 = v535->timer;
      int v861 = v588 + 100;
      v535->timer = v861;v569;
    }));
    v591;
  }));
  int * v594 = v535->regs;
  v594[10] = v593;
  struct StateT * v816 = v596(v535);
  return v816;
}

struct StateT * v218(struct StateT * v219) {
  int v220 = v219->timer;
  int v223 = v220 + 1;
  v219->timer = v223;return v219;
}

struct StateT * v195(struct StateT * v196) {
  int v197 = v196->timer;
  int v356 = v197 + 1;
  v196->timer = v356;int * v199 = v196->bht;
  int v200 = v199[1];
  bool v359 = !(v200 == 0);
  struct StateT * v354 = (v359 ? ({
    struct StateT * v283 = v201(v196);
    v283;
  }) : ({
    struct StateT * v352 = v285(v196);
    v352;
  }));
  return v354;
}

struct StateT * v672(struct StateT * v673) {
  int * v674 = v673->regs;
  int v675 = v674[14];
  int * v676 = v673->regs;
  int v677 = v676[15];
  int * v678 = v673->bht;
  bool v722 = v675 >= v677;
  int v681 = (v722 ? 1 : 0);
  v678[0] = v681;
  struct StateT * v716 = (v722 ? ({
    int v683 = v673->timer;
    int v728 = v683 + 15;
    v673->timer = v728;int * v685 = v673->saved_regs;
    int v686 = v685[5];
    int * v687 = v673->regs;
    v687[5] = v686;
    int * v689 = v673->saved_regs;
    int v690 = v689[10];
    int * v691 = v673->regs;
    v691[10] = v690;
    int * v693 = v673->saved_regs;
    int v694 = v693[6];
    int * v695 = v673->regs;
    v695[6] = v694;
    int * v697 = v673->saved_regs;
    int v698 = v697[11];
    int * v699 = v673->regs;
    v699[11] = v698;
    struct StateT * v712 = v701(v673);
    v712;
  }) : ({
    struct StateT * v714 = v195(v673);
    v714;
  }));
  return v716;
}

struct StateT * v127(struct StateT * v128) {
  int v129 = v128->timer;
  int v415 = v129 + 1;
  v128->timer = v415;int * v131 = v128->regs;
  int v132 = v131[13];
  int * v133 = v128->regs;
  int v134 = v133[14];
  int * v135 = v128->regs;
  int v422 = v132 + v134;
  v135[6] = v422;
  struct StateT * v413 = v137(v128);
  return v413;
}

struct StateT * v31(struct StateT * v32) {
  int * v33 = v32->saved_regs;
  int * v34 = v32->regs;
  int v35 = v34[10];
  v33[10] = v35;
  int v37 = v32->timer;
  int v513 = v37 + 1;
  v32->timer = v513;int * v39 = v32->regs;
  v39[10] = 1;
  struct StateT * v507 = v41(v32);
  return v507;
}

struct StateT * v212(struct StateT * v213) {
  int v214 = v213->timer;
  int v226 = v214 + 1;
  v213->timer = v226;int * v216 = v213->regs;
  v216[10] = 0;
  struct StateT * v224 = v218(v213);
  return v224;
}

struct StateT * v69(struct StateT * v70) {
  int v71 = v70->timer;
  int v427 = v71 + 1;
  v70->timer = v427;int * v73 = v70->regs;
  int v74 = v73[5];
  int * v75 = v70->cache_keys;
  int v76 = v75[0];
  bool v432 = v76 == ((int)((unsigned int)v74 >> 2));
  int v124 = (v432 ? ({
    int * v77 = v70->cache_vals;
    int v78 = v77[0];
    v78;
  }) : ({
    int * v80 = v70->cache_keys;
    int v81 = v80[1];
    bool v437 = v81 == ((int)((unsigned int)v74 >> 2));
    int v122 = (v437 ? ({
      int * v82 = v70->cache_vals;
      int v83 = v82[1];
      int * v84 = v70->cache_keys;
      int * v85 = v70->cache_keys;
      int v86 = v85[0];
      v84[1] = v86;
      int * v88 = v70->cache_vals;
      int * v89 = v70->cache_vals;
      int v90 = v89[0];
      v88[1] = v90;
      int * v92 = v70->cache_keys;
      int v446 = (int)((unsigned int)v74 >> 2);
      v92[0] = v446;
      int * v94 = v70->cache_vals;
      v94[0] = v83;
      int v96 = v70->timer;
      int v449 = v96 + 1;
      v70->timer = v449;v83;
    }) : ({
      int * v99 = v70->mem;
      int v451 = (int)((unsigned int)v74 >> 2);
      int v100 = v99[v451];
      int * v101 = v70->mem;
      int * v102 = v70->cache_keys;
      int v103 = v102[1];
      int * v104 = v70->cache_vals;
      int v105 = v104[1];
      v101[v103] = v105;
      int * v107 = v70->cache_keys;
      int * v108 = v70->cache_keys;
      int v109 = v108[0];
      v107[1] = v109;
      int * v111 = v70->cache_vals;
      int * v112 = v70->cache_vals;
      int v113 = v112[0];
      v111[1] = v113;
      int * v115 = v70->cache_keys;
      v115[0] = v451;
      int * v117 = v70->cache_vals;
      v117[0] = v100;
      int v119 = v70->timer;
      int v466 = v119 + 100;
      v70->timer = v466;v100;
    }));
    v122;
  }));
  int * v125 = v70->regs;
  v125[10] = v124;
  struct StateT * v425 = v127(v70);
  return v425;
}

struct StateT * v137(struct StateT * v138) {
  int v139 = v138->timer;
  int v367 = v139 + 1;
  v138->timer = v367;int * v141 = v138->regs;
  int v142 = v141[6];
  int * v143 = v138->cache_keys;
  int v144 = v143[0];
  bool v372 = v144 == ((int)((unsigned int)v142 >> 2));
  int v192 = (v372 ? ({
    int * v145 = v138->cache_vals;
    int v146 = v145[0];
    v146;
  }) : ({
    int * v148 = v138->cache_keys;
    int v149 = v148[1];
    bool v377 = v149 == ((int)((unsigned int)v142 >> 2));
    int v190 = (v377 ? ({
      int * v150 = v138->cache_vals;
      int v151 = v150[1];
      int * v152 = v138->cache_keys;
      int * v153 = v138->cache_keys;
      int v154 = v153[0];
      v152[1] = v154;
      int * v156 = v138->cache_vals;
      int * v157 = v138->cache_vals;
      int v158 = v157[0];
      v156[1] = v158;
      int * v160 = v138->cache_keys;
      int v386 = (int)((unsigned int)v142 >> 2);
      v160[0] = v386;
      int * v162 = v138->cache_vals;
      v162[0] = v151;
      int v164 = v138->timer;
      int v389 = v164 + 1;
      v138->timer = v389;v151;
    }) : ({
      int * v167 = v138->mem;
      int v391 = (int)((unsigned int)v142 >> 2);
      int v168 = v167[v391];
      int * v169 = v138->mem;
      int * v170 = v138->cache_keys;
      int v171 = v170[1];
      int * v172 = v138->cache_vals;
      int v173 = v172[1];
      v169[v171] = v173;
      int * v175 = v138->cache_keys;
      int * v176 = v138->cache_keys;
      int v177 = v176[0];
      v175[1] = v177;
      int * v179 = v138->cache_vals;
      int * v180 = v138->cache_vals;
      int v181 = v180[0];
      v179[1] = v181;
      int * v183 = v138->cache_keys;
      v183[0] = v391;
      int * v185 = v138->cache_vals;
      v185[0] = v168;
      int v187 = v138->timer;
      int v406 = v187 + 100;
      v138->timer = v406;v168;
    }));
    v190;
  }));
  int * v193 = v138->regs;
  v193[11] = v192;
  struct StateT * v365 = v195(v138);
  return v365;
}

struct StateT * v7(struct StateT * v8) {
  int v9 = v8->timer;
  int v913 = v9 + 1;
  v8->timer = v913;int * v11 = v8->regs;
  v11[13] = 80;
  struct StateT * v911 = v13(v8);
  return v911;
}

struct StateT * v285(struct StateT * v286) {
  int * v287 = v286->saved_regs;
  int * v288 = v286->regs;
  int v289 = v288[14];
  v287[14] = v289;
  int v291 = v286->timer;
  int v346 = v291 + 1;
  v286->timer = v346;int * v293 = v286->regs;
  int v294 = v293[14];
  int * v295 = v286->regs;
  int v349 = v294 + 4;
  v295[14] = v349;
  struct StateT * v340 = v297(v286);
  return v340;
}

struct StateT * v236(struct StateT * v237) {
  int v238 = v237->timer;
  int v256 = v238 + 1;
  v237->timer = v256;int * v240 = v237->regs;
  int v241 = v240[14];
  int * v242 = v237->regs;
  int v260 = v241 + 4;
  v242[14] = v260;
  struct StateT * v254 = v244(v237);
  return v254;
}

struct StateT * v13(struct StateT * v14) {
  int v15 = v14->timer;
  int v905 = v15 + 1;
  v14->timer = v905;int * v17 = v14->regs;
  v17[14] = 0;
  struct StateT * v903 = v19(v14);
  return v903;
}

struct StateT * v297(struct StateT * v298) {
  int * v299 = v298->regs;
  int v300 = v299[10];
  int * v301 = v298->regs;
  int v302 = v301[11];
  int * v303 = v298->bht;
  bool v324 = !(v300 == v302);
  int v306 = (v324 ? 1 : 0);
  v303[1] = v306;
  struct StateT * v318 = (v324 ? ({
    int v308 = v298->timer;
    int v330 = v308 + 15;
    v298->timer = v330;int * v310 = v298->saved_regs;
    int v311 = v310[14];
    int * v312 = v298->regs;
    v312[14] = v311;
    struct StateT * v314 = v212(v298);
    v314;
  }) : ({
    struct StateT * v316 = v244(v298);
    v316;
  }));
  return v318;
}

struct StateT * v701(struct StateT * v702) {
  int v703 = v702->timer;
  int v708 = v703 + 1;
  v702->timer = v708;int * v705 = v702->regs;
  v705[10] = 1;
  return v702;
}

struct StateT * v41(struct StateT * v42) {
  int * v43 = v42->regs;
  int v44 = v43[14];
  int * v45 = v42->regs;
  int v46 = v45[15];
  int * v47 = v42->bht;
  bool v493 = v44 >= v46;
  int v50 = (v493 ? 1 : 0);
  v47[0] = v50;
  struct StateT * v487 = (v493 ? v42 : ({
    int v53 = v42->timer;
    int v499 = v53 + 15;
    v42->timer = v499;int * v55 = v42->saved_regs;
    int v56 = v55[10];
    int * v57 = v42->regs;
    v57[10] = v56;
    struct StateT * v485 = v59(v42);
    v485;
  }));
  return v487;
}

struct StateT * v520(struct StateT * v521) {
  int * v522 = v521->saved_regs;
  int * v523 = v521->regs;
  int v524 = v523[5];
  v522[5] = v524;
  int v526 = v521->timer;
  int v873 = v526 + 1;
  v521->timer = v873;int * v528 = v521->regs;
  int v529 = v528[12];
  int * v530 = v521->regs;
  int v531 = v530[14];
  int * v532 = v521->regs;
  int v879 = v529 + v531;
  v532[5] = v879;
  struct StateT * v867 = v534(v521);
  return v867;
}

struct StateT * v610(struct StateT * v611) {
  int * v612 = v611->saved_regs;
  int * v613 = v611->regs;
  int v614 = v613[11];
  v612[11] = v614;
  int v616 = v611->timer;
  int v756 = v616 + 1;
  v611->timer = v756;int * v618 = v611->regs;
  int v619 = v618[6];
  int * v620 = v611->cache_keys;
  int v621 = v620[0];
  bool v761 = v621 == ((int)((unsigned int)v619 >> 2));
  int v669 = (v761 ? ({
    int * v622 = v611->cache_vals;
    int v623 = v622[0];
    v623;
  }) : ({
    int * v625 = v611->cache_keys;
    int v626 = v625[1];
    bool v766 = v626 == ((int)((unsigned int)v619 >> 2));
    int v667 = (v766 ? ({
      int * v627 = v611->cache_vals;
      int v628 = v627[1];
      int * v629 = v611->cache_keys;
      int * v630 = v611->cache_keys;
      int v631 = v630[0];
      v629[1] = v631;
      int * v633 = v611->cache_vals;
      int * v634 = v611->cache_vals;
      int v635 = v634[0];
      v633[1] = v635;
      int * v637 = v611->cache_keys;
      int v775 = (int)((unsigned int)v619 >> 2);
      v637[0] = v775;
      int * v639 = v611->cache_vals;
      v639[0] = v628;
      int v641 = v611->timer;
      int v778 = v641 + 1;
      v611->timer = v778;v628;
    }) : ({
      int * v644 = v611->mem;
      int v780 = (int)((unsigned int)v619 >> 2);
      int v645 = v644[v780];
      int * v646 = v611->mem;
      int * v647 = v611->cache_keys;
      int v648 = v647[1];
      int * v649 = v611->cache_vals;
      int v650 = v649[1];
      v646[v648] = v650;
      int * v652 = v611->cache_keys;
      int * v653 = v611->cache_keys;
      int v654 = v653[0];
      v652[1] = v654;
      int * v656 = v611->cache_vals;
      int * v657 = v611->cache_vals;
      int v658 = v657[0];
      v656[1] = v658;
      int * v660 = v611->cache_keys;
      v660[0] = v780;
      int * v662 = v611->cache_vals;
      v662[0] = v645;
      int v664 = v611->timer;
      int v795 = v664 + 100;
      v611->timer = v795;v645;
    }));
    v667;
  }));
  int * v670 = v611->regs;
  v670[11] = v669;
  struct StateT * v750 = v672(v611);
  return v750;
}

struct StateT * v201(struct StateT * v202) {
  int * v203 = v202->regs;
  int v204 = v203[10];
  int * v205 = v202->regs;
  int v206 = v205[11];
  int * v207 = v202->bht;
  bool v271 = !(v204 == v206);
  int v210 = (v271 ? 1 : 0);
  v207[1] = v210;
  struct StateT * v265 = (v271 ? ({
    struct StateT * v232 = v212(v202);
    v232;
  }) : ({
    int v234 = v202->timer;
    int v279 = v234 + 15;
    v202->timer = v279;struct StateT * v263 = v236(v202);
    v263;
  }));
  return v265;
}

struct StateT * v596(struct StateT * v597) {
  int * v598 = v597->saved_regs;
  int * v599 = v597->regs;
  int v600 = v599[6];
  v598[6] = v600;
  int v602 = v597->timer;
  int v807 = v602 + 1;
  v597->timer = v807;int * v604 = v597->regs;
  int v605 = v604[13];
  int * v606 = v597->regs;
  int v607 = v606[14];
  int * v608 = v597->regs;
  int v813 = v605 + v607;
  v608[6] = v813;
  struct StateT * v801 = v610(v597);
  return v801;
}

struct StateT * snippet(struct StateT * v0) {
  struct StateT * v927 = v1(v0);
  return v927;
}

struct StateT * v244(struct StateT * v245) {
  int v246 = v245->timer;
  int v251 = v246 + 1;
  v245->timer = v251;struct StateT * v249 = v25(v245);
  return v249;
}

struct StateT * v1(struct StateT * v2) {
  int v3 = v2->timer;
  int v921 = v3 + 1;
  v2->timer = v921;int * v5 = v2->regs;
  v5[12] = 0;
  struct StateT * v919 = v7(v2);
  return v919;
}

struct StateT * v59(struct StateT * v60) {
  int v61 = v60->timer;
  int v475 = v61 + 1;
  v60->timer = v475;int * v63 = v60->regs;
  int v64 = v63[12];
  int * v65 = v60->regs;
  int v66 = v65[14];
  int * v67 = v60->regs;
  int v482 = v64 + v66;
  v67[5] = v482;
  struct StateT * v473 = v69(v60);
  return v473;
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