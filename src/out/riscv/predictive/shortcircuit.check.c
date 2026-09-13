// verify: leak (CBMC should report VERIFICATION FAILED)

#define NUM_REGS 32
#define MEM_SIZE 30
#define SECRET_SIZE 10
#define SECRET_OFFSET 20
#define CACHE_LRU_SIZE 10
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
}

/*****************************************
Emitting C Generated Code
*******************************************/

#include <stdbool.h>
#include <stdlib.h>

struct StateT * v469(struct StateT * v470);
struct StateT * v19(struct StateT * v20);
struct StateT * v276(struct StateT * v277);
struct StateT * v481(struct StateT * v482);
struct StateT * v25(struct StateT * v26);
struct StateT * v218(struct StateT * v219);
struct StateT * v366(struct StateT * v367);
struct StateT * v290(struct StateT * v291);
struct StateT * v465(struct StateT * v466);
struct StateT * v29(struct StateT * v30);
struct StateT * v452(struct StateT * v453);
struct StateT * v7(struct StateT * v8);
struct StateT * v105(struct StateT * v106);
struct StateT * v234(struct StateT * v235);
struct StateT * v13(struct StateT * v14);
struct StateT * v181(struct StateT * v182);
struct StateT * v43(struct StateT * v44);
struct StateT * v222(struct StateT * v223);
struct StateT * v252(struct StateT * v253);
struct StateT * v246(struct StateT * v247);
struct StateT * v119(struct StateT * v120);
struct StateT * v268(struct StateT * v269);
struct StateT * v428(struct StateT * v429);
struct StateT * snippet(struct StateT * v0);
struct StateT * v1(struct StateT * v2);
struct StateT * v352(struct StateT * v353);
struct StateT * v205(struct StateT * v206);
struct StateT * v272(struct StateT * v273);
struct StateT * v469(struct StateT * v470) {
  int * v471 = v470->saved_regs;
  int * v472 = v470->regs;
  int v473 = v472[14];
  v471[14] = v473;
  int v475 = v470->timer;
  int v521 = v475 + 1;
  v470->timer = v521;int * v477 = v470->regs;
  int v478 = v477[14];
  int * v479 = v470->regs;
  int v524 = v478 + 4;
  v479[14] = v524;
  struct StateT * v515 = v481(v470);
  return v515;
}

struct StateT * v19(struct StateT * v20) {
  int v21 = v20->timer;
  int v911 = v21 + 1;
  v20->timer = v911;int * v23 = v20->regs;
  v23[15] = 16;
  struct StateT * v909 = v25(v20);
  return v909;
}

struct StateT * v276(struct StateT * v277) {
  int * v278 = v277->saved_regs;
  int * v279 = v277->regs;
  int v280 = v279[5];
  v278[5] = v280;
  int v282 = v277->timer;
  int v686 = v282 + 1;
  v277->timer = v686;int * v284 = v277->regs;
  int v285 = v284[12];
  int * v286 = v277->regs;
  int v287 = v286[14];
  int * v288 = v277->regs;
  int v692 = v285 + v287;
  v288[5] = v692;
  struct StateT * v680 = v290(v277);
  return v680;
}

struct StateT * v481(struct StateT * v482) {
  int * v483 = v482->regs;
  int v484 = v483[10];
  int * v485 = v482->regs;
  int v486 = v485[11];
  bool v504 = !(v484 == v486);
  struct StateT * v498 = (v504 ? ({
    int v487 = v482->timer;
    int v505 = v487 + 15;
    v482->timer = v505;int * v489 = v482->saved_regs;
    int v490 = v489[14];
    int * v491 = v482->regs;
    v491[14] = v490;
    struct StateT * v493 = v246(v482);
    v493;
  }) : ({
    struct StateT * v496 = v268(v482);
    v496;
  }));
  return v498;
}

struct StateT * v25(struct StateT * v26) {
  int v27 = v26->timer;
  int v906 = v27 + 1;
  v26->timer = v906;struct StateT * v904 = v29(v26);
  return v904;
}

struct StateT * v218(struct StateT * v219) {
  int v220 = v219->timer;
  int v738 = v220 + 1;
  v219->timer = v738;struct StateT * v736 = v222(v219);
  return v736;
}

struct StateT * v366(struct StateT * v367) {
  int * v368 = v367->saved_regs;
  int * v369 = v367->regs;
  int v370 = v369[11];
  v368[11] = v370;
  int v372 = v367->timer;
  int v569 = v372 + 1;
  v367->timer = v569;int * v374 = v367->regs;
  int v375 = v374[6];
  int * v376 = v367->cache_keys;
  int v377 = v376[0];
  bool v574 = v377 == ((int)((unsigned int)v375 >> 2));
  int v425 = (v574 ? ({
    int * v378 = v367->cache_vals;
    int v379 = v378[0];
    v379;
  }) : ({
    int * v381 = v367->cache_keys;
    int v382 = v381[1];
    bool v579 = v382 == ((int)((unsigned int)v375 >> 2));
    int v423 = (v579 ? ({
      int * v383 = v367->cache_vals;
      int v384 = v383[1];
      int * v385 = v367->cache_keys;
      int * v386 = v367->cache_keys;
      int v387 = v386[0];
      v385[1] = v387;
      int * v389 = v367->cache_vals;
      int * v390 = v367->cache_vals;
      int v391 = v390[0];
      v389[1] = v391;
      int * v393 = v367->cache_keys;
      int v588 = (int)((unsigned int)v375 >> 2);
      v393[0] = v588;
      int * v395 = v367->cache_vals;
      v395[0] = v384;
      int v397 = v367->timer;
      int v591 = v397 + 1;
      v367->timer = v591;v384;
    }) : ({
      int * v400 = v367->mem;
      int v593 = (int)((unsigned int)v375 >> 2);
      int v401 = v400[v593];
      int * v402 = v367->mem;
      int * v403 = v367->cache_keys;
      int v404 = v403[1];
      int * v405 = v367->cache_vals;
      int v406 = v405[1];
      v402[v404] = v406;
      int * v408 = v367->cache_keys;
      int * v409 = v367->cache_keys;
      int v410 = v409[0];
      v408[1] = v410;
      int * v412 = v367->cache_vals;
      int * v413 = v367->cache_vals;
      int v414 = v413[0];
      v412[1] = v414;
      int * v416 = v367->cache_keys;
      v416[0] = v593;
      int * v418 = v367->cache_vals;
      v418[0] = v401;
      int v420 = v367->timer;
      int v608 = v420 + 100;
      v367->timer = v608;v401;
    }));
    v423;
  }));
  int * v426 = v367->regs;
  v426[11] = v425;
  struct StateT * v563 = v428(v367);
  return v563;
}

struct StateT * v290(struct StateT * v291) {
  int * v292 = v291->saved_regs;
  int * v293 = v291->regs;
  int v294 = v293[10];
  v292[10] = v294;
  int v296 = v291->timer;
  int v635 = v296 + 1;
  v291->timer = v635;int * v298 = v291->regs;
  int v299 = v298[5];
  int * v300 = v291->cache_keys;
  int v301 = v300[0];
  bool v640 = v301 == ((int)((unsigned int)v299 >> 2));
  int v349 = (v640 ? ({
    int * v302 = v291->cache_vals;
    int v303 = v302[0];
    v303;
  }) : ({
    int * v305 = v291->cache_keys;
    int v306 = v305[1];
    bool v645 = v306 == ((int)((unsigned int)v299 >> 2));
    int v347 = (v645 ? ({
      int * v307 = v291->cache_vals;
      int v308 = v307[1];
      int * v309 = v291->cache_keys;
      int * v310 = v291->cache_keys;
      int v311 = v310[0];
      v309[1] = v311;
      int * v313 = v291->cache_vals;
      int * v314 = v291->cache_vals;
      int v315 = v314[0];
      v313[1] = v315;
      int * v317 = v291->cache_keys;
      int v654 = (int)((unsigned int)v299 >> 2);
      v317[0] = v654;
      int * v319 = v291->cache_vals;
      v319[0] = v308;
      int v321 = v291->timer;
      int v657 = v321 + 1;
      v291->timer = v657;v308;
    }) : ({
      int * v324 = v291->mem;
      int v659 = (int)((unsigned int)v299 >> 2);
      int v325 = v324[v659];
      int * v326 = v291->mem;
      int * v327 = v291->cache_keys;
      int v328 = v327[1];
      int * v329 = v291->cache_vals;
      int v330 = v329[1];
      v326[v328] = v330;
      int * v332 = v291->cache_keys;
      int * v333 = v291->cache_keys;
      int v334 = v333[0];
      v332[1] = v334;
      int * v336 = v291->cache_vals;
      int * v337 = v291->cache_vals;
      int v338 = v337[0];
      v336[1] = v338;
      int * v340 = v291->cache_keys;
      v340[0] = v659;
      int * v342 = v291->cache_vals;
      v342[0] = v325;
      int v344 = v291->timer;
      int v674 = v344 + 100;
      v291->timer = v674;v325;
    }));
    v347;
  }));
  int * v350 = v291->regs;
  v350[10] = v349;
  struct StateT * v629 = v352(v291);
  return v629;
}

struct StateT * v465(struct StateT * v466) {
  int v467 = v466->timer;
  int v529 = v467 + 1;
  v466->timer = v529;struct StateT * v527 = v469(v466);
  return v527;
}

struct StateT * v29(struct StateT * v30) {
  int * v31 = v30->saved_regs;
  int * v32 = v30->regs;
  int v33 = v32[5];
  v31[5] = v33;
  int v35 = v30->timer;
  int v895 = v35 + 1;
  v30->timer = v895;int * v37 = v30->regs;
  int v38 = v37[12];
  int * v39 = v30->regs;
  int v40 = v39[14];
  int * v41 = v30->regs;
  int v901 = v38 + v40;
  v41[5] = v901;
  struct StateT * v889 = v43(v30);
  return v889;
}

struct StateT * v452(struct StateT * v453) {
  int v454 = v453->timer;
  int v459 = v454 + 1;
  v453->timer = v459;int * v456 = v453->regs;
  v456[10] = 1;
  return v453;
}

struct StateT * v7(struct StateT * v8) {
  int v9 = v8->timer;
  int v927 = v9 + 1;
  v8->timer = v927;int * v11 = v8->regs;
  v11[13] = 80;
  struct StateT * v925 = v13(v8);
  return v925;
}

struct StateT * v105(struct StateT * v106) {
  int * v107 = v106->saved_regs;
  int * v108 = v106->regs;
  int v109 = v108[6];
  v107[6] = v109;
  int v111 = v106->timer;
  int v829 = v111 + 1;
  v106->timer = v829;int * v113 = v106->regs;
  int v114 = v113[13];
  int * v115 = v106->regs;
  int v116 = v115[14];
  int * v117 = v106->regs;
  int v835 = v114 + v116;
  v117[6] = v835;
  struct StateT * v823 = v119(v106);
  return v823;
}

struct StateT * v234(struct StateT * v235) {
  int * v236 = v235->regs;
  int v237 = v236[10];
  int * v238 = v235->regs;
  int v239 = v238[11];
  bool v713 = !(v237 == v239);
  struct StateT * v707 = (v713 ? ({
    int v240 = v235->timer;
    int v714 = v240 + 15;
    v235->timer = v714;int * v242 = v235->saved_regs;
    int v243 = v242[14];
    int * v244 = v235->regs;
    v244[14] = v243;
    struct StateT * v266 = v246(v235);
    v266;
  }) : ({
    struct StateT * v705 = v268(v235);
    v705;
  }));
  return v707;
}

struct StateT * v13(struct StateT * v14) {
  int v15 = v14->timer;
  int v919 = v15 + 1;
  v14->timer = v919;int * v17 = v14->regs;
  v17[14] = 0;
  struct StateT * v917 = v19(v14);
  return v917;
}

struct StateT * v181(struct StateT * v182) {
  int * v183 = v182->regs;
  int v184 = v183[14];
  int * v185 = v182->regs;
  int v186 = v185[15];
  bool v749 = v184 >= v186;
  struct StateT * v743 = (v749 ? ({
    int v187 = v182->timer;
    int v750 = v187 + 15;
    v182->timer = v750;int * v189 = v182->saved_regs;
    int v190 = v189[5];
    int * v191 = v182->regs;
    v191[5] = v190;
    int * v193 = v182->saved_regs;
    int v194 = v193[10];
    int * v195 = v182->regs;
    v195[10] = v194;
    int * v197 = v182->saved_regs;
    int v198 = v197[6];
    int * v199 = v182->regs;
    v199[6] = v198;
    int * v201 = v182->saved_regs;
    int v202 = v201[11];
    int * v203 = v182->regs;
    v203[11] = v202;
    struct StateT * v216 = v205(v182);
    v216;
  }) : ({
    struct StateT * v741 = v218(v182);
    v741;
  }));
  return v743;
}

struct StateT * v43(struct StateT * v44) {
  int * v45 = v44->saved_regs;
  int * v46 = v44->regs;
  int v47 = v46[10];
  v45[10] = v47;
  int v49 = v44->timer;
  int v844 = v49 + 1;
  v44->timer = v844;int * v51 = v44->regs;
  int v52 = v51[5];
  int * v53 = v44->cache_keys;
  int v54 = v53[0];
  bool v849 = v54 == ((int)((unsigned int)v52 >> 2));
  int v102 = (v849 ? ({
    int * v55 = v44->cache_vals;
    int v56 = v55[0];
    v56;
  }) : ({
    int * v58 = v44->cache_keys;
    int v59 = v58[1];
    bool v854 = v59 == ((int)((unsigned int)v52 >> 2));
    int v100 = (v854 ? ({
      int * v60 = v44->cache_vals;
      int v61 = v60[1];
      int * v62 = v44->cache_keys;
      int * v63 = v44->cache_keys;
      int v64 = v63[0];
      v62[1] = v64;
      int * v66 = v44->cache_vals;
      int * v67 = v44->cache_vals;
      int v68 = v67[0];
      v66[1] = v68;
      int * v70 = v44->cache_keys;
      int v863 = (int)((unsigned int)v52 >> 2);
      v70[0] = v863;
      int * v72 = v44->cache_vals;
      v72[0] = v61;
      int v74 = v44->timer;
      int v866 = v74 + 1;
      v44->timer = v866;v61;
    }) : ({
      int * v77 = v44->mem;
      int v868 = (int)((unsigned int)v52 >> 2);
      int v78 = v77[v868];
      int * v79 = v44->mem;
      int * v80 = v44->cache_keys;
      int v81 = v80[1];
      int * v82 = v44->cache_vals;
      int v83 = v82[1];
      v79[v81] = v83;
      int * v85 = v44->cache_keys;
      int * v86 = v44->cache_keys;
      int v87 = v86[0];
      v85[1] = v87;
      int * v89 = v44->cache_vals;
      int * v90 = v44->cache_vals;
      int v91 = v90[0];
      v89[1] = v91;
      int * v93 = v44->cache_keys;
      v93[0] = v868;
      int * v95 = v44->cache_vals;
      v95[0] = v78;
      int v97 = v44->timer;
      int v883 = v97 + 100;
      v44->timer = v883;v78;
    }));
    v100;
  }));
  int * v103 = v44->regs;
  v103[10] = v102;
  struct StateT * v838 = v105(v44);
  return v838;
}

struct StateT * v222(struct StateT * v223) {
  int * v224 = v223->saved_regs;
  int * v225 = v223->regs;
  int v226 = v225[14];
  v224[14] = v226;
  int v228 = v223->timer;
  int v730 = v228 + 1;
  v223->timer = v730;int * v230 = v223->regs;
  int v231 = v230[14];
  int * v232 = v223->regs;
  int v733 = v231 + 4;
  v232[14] = v733;
  struct StateT * v724 = v234(v223);
  return v724;
}

struct StateT * v252(struct StateT * v253) {
  int v254 = v253->timer;
  int v257 = v254 + 1;
  v253->timer = v257;return v253;
}

struct StateT * v246(struct StateT * v247) {
  int v248 = v247->timer;
  int v260 = v248 + 1;
  v247->timer = v260;int * v250 = v247->regs;
  v250[10] = 0;
  struct StateT * v258 = v252(v247);
  return v258;
}

struct StateT * v119(struct StateT * v120) {
  int * v121 = v120->saved_regs;
  int * v122 = v120->regs;
  int v123 = v122[11];
  v121[11] = v123;
  int v125 = v120->timer;
  int v778 = v125 + 1;
  v120->timer = v778;int * v127 = v120->regs;
  int v128 = v127[6];
  int * v129 = v120->cache_keys;
  int v130 = v129[0];
  bool v783 = v130 == ((int)((unsigned int)v128 >> 2));
  int v178 = (v783 ? ({
    int * v131 = v120->cache_vals;
    int v132 = v131[0];
    v132;
  }) : ({
    int * v134 = v120->cache_keys;
    int v135 = v134[1];
    bool v788 = v135 == ((int)((unsigned int)v128 >> 2));
    int v176 = (v788 ? ({
      int * v136 = v120->cache_vals;
      int v137 = v136[1];
      int * v138 = v120->cache_keys;
      int * v139 = v120->cache_keys;
      int v140 = v139[0];
      v138[1] = v140;
      int * v142 = v120->cache_vals;
      int * v143 = v120->cache_vals;
      int v144 = v143[0];
      v142[1] = v144;
      int * v146 = v120->cache_keys;
      int v797 = (int)((unsigned int)v128 >> 2);
      v146[0] = v797;
      int * v148 = v120->cache_vals;
      v148[0] = v137;
      int v150 = v120->timer;
      int v800 = v150 + 1;
      v120->timer = v800;v137;
    }) : ({
      int * v153 = v120->mem;
      int v802 = (int)((unsigned int)v128 >> 2);
      int v154 = v153[v802];
      int * v155 = v120->mem;
      int * v156 = v120->cache_keys;
      int v157 = v156[1];
      int * v158 = v120->cache_vals;
      int v159 = v158[1];
      v155[v157] = v159;
      int * v161 = v120->cache_keys;
      int * v162 = v120->cache_keys;
      int v163 = v162[0];
      v161[1] = v163;
      int * v165 = v120->cache_vals;
      int * v166 = v120->cache_vals;
      int v167 = v166[0];
      v165[1] = v167;
      int * v169 = v120->cache_keys;
      v169[0] = v802;
      int * v171 = v120->cache_vals;
      v171[0] = v154;
      int v173 = v120->timer;
      int v817 = v173 + 100;
      v120->timer = v817;v154;
    }));
    v176;
  }));
  int * v179 = v120->regs;
  v179[11] = v178;
  struct StateT * v772 = v181(v120);
  return v772;
}

struct StateT * v268(struct StateT * v269) {
  int v270 = v269->timer;
  int v702 = v270 + 1;
  v269->timer = v702;struct StateT * v700 = v272(v269);
  return v700;
}

struct StateT * v428(struct StateT * v429) {
  int * v430 = v429->regs;
  int v431 = v430[14];
  int * v432 = v429->regs;
  int v433 = v432[15];
  bool v540 = v431 >= v433;
  struct StateT * v534 = (v540 ? ({
    int v434 = v429->timer;
    int v541 = v434 + 15;
    v429->timer = v541;int * v436 = v429->saved_regs;
    int v437 = v436[5];
    int * v438 = v429->regs;
    v438[5] = v437;
    int * v440 = v429->saved_regs;
    int v441 = v440[10];
    int * v442 = v429->regs;
    v442[10] = v441;
    int * v444 = v429->saved_regs;
    int v445 = v444[6];
    int * v446 = v429->regs;
    v446[6] = v445;
    int * v448 = v429->saved_regs;
    int v449 = v448[11];
    int * v450 = v429->regs;
    v450[11] = v449;
    struct StateT * v463 = v452(v429);
    v463;
  }) : ({
    struct StateT * v532 = v465(v429);
    v532;
  }));
  return v534;
}

struct StateT * snippet(struct StateT * v0) {
  struct StateT * v941 = v1(v0);
  return v941;
}

struct StateT * v1(struct StateT * v2) {
  int v3 = v2->timer;
  int v935 = v3 + 1;
  v2->timer = v935;int * v5 = v2->regs;
  v5[12] = 0;
  struct StateT * v933 = v7(v2);
  return v933;
}

struct StateT * v352(struct StateT * v353) {
  int * v354 = v353->saved_regs;
  int * v355 = v353->regs;
  int v356 = v355[6];
  v354[6] = v356;
  int v358 = v353->timer;
  int v620 = v358 + 1;
  v353->timer = v620;int * v360 = v353->regs;
  int v361 = v360[13];
  int * v362 = v353->regs;
  int v363 = v362[14];
  int * v364 = v353->regs;
  int v626 = v361 + v363;
  v364[6] = v626;
  struct StateT * v614 = v366(v353);
  return v614;
}

struct StateT * v205(struct StateT * v206) {
  int v207 = v206->timer;
  int v212 = v207 + 1;
  v206->timer = v212;int * v209 = v206->regs;
  v209[10] = 1;
  return v206;
}

struct StateT * v272(struct StateT * v273) {
  int v274 = v273->timer;
  int v697 = v274 + 1;
  v273->timer = v697;struct StateT * v695 = v276(v273);
  return v695;
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