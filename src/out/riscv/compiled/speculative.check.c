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

/*****************************************
Emitting C Generated Code
*******************************************/

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

struct StateT {
  int regs[32];
  int mem[30];
  int saved_regs[32];
  int cache_keys[10];
  int cache_vals[10];
  int timer;
};

struct StateT * v367(struct StateT * v368);
struct StateT * v15(struct StateT * v16);
struct StateT * v185(struct StateT * v186);
struct StateT * v221(struct StateT * v222);
struct StateT * v245(struct StateT * v246);
struct StateT * v237(struct StateT * v238);
struct StateT * v251(struct StateT * v252);
struct StateT * v9(struct StateT * v10);
struct StateT * snippet(struct StateT * v0);
struct StateT * v229(struct StateT * v230);
struct StateT * v1(struct StateT * v2);
struct StateT * v205(struct StateT * v206);
struct StateT * v199(struct StateT * v200);
struct StateT * v309(struct StateT * v310);
struct StateT * v367(struct StateT * v368) {
  int * v369 = v368->saved_regs;
  int * v370 = v368->regs;
  int v371 = v370[11];
  v369[11] = v371;
  int v373 = v368->timer;
  int v436 = v373 + 1;
  v368->timer = v436;
  int * v375 = v368->regs;
  int v376 = v375[11];
  int * v377 = v368->regs;
  int v439 = v376 + -1;
  v377[11] = v439;
  int v379 = v368->timer;
  int v440 = v379 + 1;
  v368->timer = v440;
  int * v381 = v368->regs;
  int v382 = v381[12];
  int * v383 = v368->regs;
  int v444 = v382 + 4;
  v383[12] = v444;
  int v385 = v368->timer;
  int v445 = v385 + 1;
  v368->timer = v445;
  int * v387 = v368->regs;
  int v388 = v387[13];
  int * v389 = v368->regs;
  int v449 = v388 + 4;
  v389[13] = v449;
  int * v391 = v368->regs;
  int v392 = v391[14];
  int * v393 = v368->regs;
  int v394 = v393[15];
  bool v454 = !(v392 == v394);
  struct StateT * v430;
  if (v454) {
    int v395 = v368->timer;
    int v455 = v395 + 15;
    v368->timer = v455;
    int * v397 = v368->saved_regs;
    int v398 = v397[12];
    int * v399 = v368->regs;
    v399[12] = v398;
    int * v401 = v368->saved_regs;
    int v402 = v401[13];
    int * v403 = v368->regs;
    v403[13] = v402;
    int * v405 = v368->saved_regs;
    int v406 = v405[14];
    int * v407 = v368->regs;
    v407[14] = v406;
    int * v409 = v368->saved_regs;
    int v410 = v409[15];
    int * v411 = v368->regs;
    v411[15] = v410;
    int * v413 = v368->saved_regs;
    int v414 = v413[11];
    int * v415 = v368->regs;
    v415[11] = v414;
    struct StateT * v417 = v199(v368);
    v430 = v417;
  } else {
    int v419 = v368->timer;
    int v473 = v419 + 1;
    v368->timer = v473;
    int * v421 = v368->regs;
    int v422 = v421[11];
    bool v475 = !(v422 == 0);
    struct StateT * v428;
    if (v475) {
      struct StateT * v424 = v251(v368);
      v428 = v424;
    } else {
      struct StateT * v426 = v185(v368);
      v428 = v426;
    }
    v430 = v428;
  }
  return v430;
}

struct StateT * v15(struct StateT * v16) {
  int * v17 = v16->saved_regs;
  int * v18 = v16->regs;
  int v19 = v18[12];
  v17[12] = v19;
  int v21 = v16->timer;
  int v630 = v21 + 1;
  v16->timer = v630;
  int * v23 = v16->regs;
  v23[12] = 0;
  int v25 = v16->timer;
  int v633 = v25 + 1;
  v16->timer = v633;
  int * v27 = v16->regs;
  int v28 = v27[12];
  int * v29 = v16->regs;
  int v636 = v28 + 16;
  v29[12] = v636;
  int * v31 = v16->saved_regs;
  int * v32 = v16->regs;
  int v33 = v32[13];
  v31[13] = v33;
  int v35 = v16->timer;
  int v641 = v35 + 1;
  v16->timer = v641;
  int * v37 = v16->regs;
  v37[13] = 0;
  int v39 = v16->timer;
  int v643 = v39 + 1;
  v16->timer = v643;
  int * v41 = v16->regs;
  int v42 = v41[13];
  int * v43 = v16->regs;
  v43[13] = v42;
  int * v45 = v16->saved_regs;
  int * v46 = v16->regs;
  int v47 = v46[14];
  v45[14] = v47;
  int v49 = v16->timer;
  int v651 = v49 + 1;
  v16->timer = v651;
  int * v51 = v16->regs;
  int v52 = v51[12];
  int * v53 = v16->cache_keys;
  int v54 = v53[0];
  bool v654 = v54 == ((int)((unsigned int)v52 >> 2));
  int v102;
  if (v654) {
    int * v55 = v16->cache_vals;
    int v56 = v55[0];
    v102 = v56;
  } else {
    int * v58 = v16->cache_keys;
    int v59 = v58[1];
    bool v659 = v59 == ((int)((unsigned int)v52 >> 2));
    int v100;
    if (v659) {
      int * v60 = v16->cache_vals;
      int v61 = v60[1];
      int * v62 = v16->cache_keys;
      int * v63 = v16->cache_keys;
      int v64 = v63[0];
      v62[1] = v64;
      int * v66 = v16->cache_vals;
      int * v67 = v16->cache_vals;
      int v68 = v67[0];
      v66[1] = v68;
      int * v70 = v16->cache_keys;
      int v668 = (int)((unsigned int)v52 >> 2);
      v70[0] = v668;
      int * v72 = v16->cache_vals;
      v72[0] = v61;
      int v74 = v16->timer;
      int v671 = v74 + 1;
      v16->timer = v671;
      v100 = v61;
    } else {
      int * v77 = v16->mem;
      int v673 = (int)((unsigned int)v52 >> 2);
      int v78 = v77[v673];
      int * v79 = v16->mem;
      int * v80 = v16->cache_keys;
      int v81 = v80[1];
      int * v82 = v16->cache_vals;
      int v83 = v82[1];
      v79[v81] = v83;
      int * v85 = v16->cache_keys;
      int * v86 = v16->cache_keys;
      int v87 = v86[0];
      v85[1] = v87;
      int * v89 = v16->cache_vals;
      int * v90 = v16->cache_vals;
      int v91 = v90[0];
      v89[1] = v91;
      int * v93 = v16->cache_keys;
      v93[0] = v673;
      int * v95 = v16->cache_vals;
      v95[0] = v78;
      int v97 = v16->timer;
      int v688 = v97 + 100;
      v16->timer = v688;
      v100 = v78;
    }
    v102 = v100;
  }
  int * v103 = v16->regs;
  v103[14] = v102;
  int * v105 = v16->saved_regs;
  int * v106 = v16->regs;
  int v107 = v106[15];
  v105[15] = v107;
  int v109 = v16->timer;
  int v696 = v109 + 1;
  v16->timer = v696;
  int * v111 = v16->regs;
  int v112 = v111[13];
  int * v113 = v16->cache_keys;
  int v114 = v113[0];
  bool v699 = v114 == ((int)((unsigned int)v112 >> 2));
  int v162;
  if (v699) {
    int * v115 = v16->cache_vals;
    int v116 = v115[0];
    v162 = v116;
  } else {
    int * v118 = v16->cache_keys;
    int v119 = v118[1];
    bool v704 = v119 == ((int)((unsigned int)v112 >> 2));
    int v160;
    if (v704) {
      int * v120 = v16->cache_vals;
      int v121 = v120[1];
      int * v122 = v16->cache_keys;
      int * v123 = v16->cache_keys;
      int v124 = v123[0];
      v122[1] = v124;
      int * v126 = v16->cache_vals;
      int * v127 = v16->cache_vals;
      int v128 = v127[0];
      v126[1] = v128;
      int * v130 = v16->cache_keys;
      int v713 = (int)((unsigned int)v112 >> 2);
      v130[0] = v713;
      int * v132 = v16->cache_vals;
      v132[0] = v121;
      int v134 = v16->timer;
      int v716 = v134 + 1;
      v16->timer = v716;
      v160 = v121;
    } else {
      int * v137 = v16->mem;
      int v718 = (int)((unsigned int)v112 >> 2);
      int v138 = v137[v718];
      int * v139 = v16->mem;
      int * v140 = v16->cache_keys;
      int v141 = v140[1];
      int * v142 = v16->cache_vals;
      int v143 = v142[1];
      v139[v141] = v143;
      int * v145 = v16->cache_keys;
      int * v146 = v16->cache_keys;
      int v147 = v146[0];
      v145[1] = v147;
      int * v149 = v16->cache_vals;
      int * v150 = v16->cache_vals;
      int v151 = v150[0];
      v149[1] = v151;
      int * v153 = v16->cache_keys;
      v153[0] = v718;
      int * v155 = v16->cache_vals;
      v155[0] = v138;
      int v157 = v16->timer;
      int v733 = v157 + 100;
      v16->timer = v733;
      v160 = v138;
    }
    v162 = v160;
  }
  int * v163 = v16->regs;
  v163[15] = v162;
  int * v165 = v16->regs;
  int v166 = v165[11];
  bool v739 = 0 >= v166;
  struct StateT * v624;
  if (v739) {
    int v167 = v16->timer;
    int v740 = v167 + 15;
    v16->timer = v740;
    int * v169 = v16->saved_regs;
    int v170 = v169[12];
    int * v171 = v16->regs;
    v171[12] = v170;
    int * v173 = v16->saved_regs;
    int v174 = v173[13];
    int * v175 = v16->regs;
    v175[13] = v174;
    int * v177 = v16->saved_regs;
    int v178 = v177[14];
    int * v179 = v16->regs;
    v179[14] = v178;
    int * v181 = v16->saved_regs;
    int v182 = v181[15];
    int * v183 = v16->regs;
    v183[15] = v182;
    struct StateT * v191 = v185(v16);
    v624 = v191;
  } else {
    int v193 = v16->timer;
    int v755 = v193 + 1;
    v16->timer = v755;
    int * v195 = v16->regs;
    int v196 = v195[14];
    int * v197 = v16->regs;
    int v198 = v197[15];
    bool v758 = !(v196 == v198);
    struct StateT * v622;
    if (v758) {
      struct StateT * v219 = v199(v16);
      v622 = v219;
    } else {
      struct StateT * v620 = v221(v16);
      v622 = v620;
    }
    v624 = v622;
  }
  return v624;
}

struct StateT * v185(struct StateT * v186) {
  int v187 = v186->timer;
  int v190 = v187 + 1;
  v186->timer = v190;
  return v186;
}

struct StateT * v221(struct StateT * v222) {
  int v223 = v222->timer;
  int v613 = v223 + 1;
  v222->timer = v613;
  int * v225 = v222->regs;
  int v226 = v225[11];
  int * v227 = v222->regs;
  int v617 = v226 + -1;
  v227[11] = v617;
  struct StateT * v611 = v229(v222);
  return v611;
}

struct StateT * v245(struct StateT * v246) {
  int v247 = v246->timer;
  int v584 = v247 + 1;
  v246->timer = v584;
  int * v249 = v246->regs;
  int v250 = v249[11];
  bool v587 = !(v250 == 0);
  struct StateT * v582;
  if (v587) {
    struct StateT * v578 = v251(v246);
    v582 = v578;
  } else {
    struct StateT * v580 = v185(v246);
    v582 = v580;
  }
  return v582;
}

struct StateT * v237(struct StateT * v238) {
  int v239 = v238->timer;
  int v595 = v239 + 1;
  v238->timer = v595;
  int * v241 = v238->regs;
  int v242 = v241[13];
  int * v243 = v238->regs;
  int v599 = v242 + 4;
  v243[13] = v599;
  struct StateT * v593 = v245(v238);
  return v593;
}

struct StateT * v251(struct StateT * v252) {
  int v253 = v252->timer;
  int v532 = v253 + 1;
  v252->timer = v532;
  int * v255 = v252->regs;
  int v256 = v255[12];
  int * v257 = v252->cache_keys;
  int v258 = v257[0];
  bool v537 = v258 == ((int)((unsigned int)v256 >> 2));
  int v306;
  if (v537) {
    int * v259 = v252->cache_vals;
    int v260 = v259[0];
    v306 = v260;
  } else {
    int * v262 = v252->cache_keys;
    int v263 = v262[1];
    bool v542 = v263 == ((int)((unsigned int)v256 >> 2));
    int v304;
    if (v542) {
      int * v264 = v252->cache_vals;
      int v265 = v264[1];
      int * v266 = v252->cache_keys;
      int * v267 = v252->cache_keys;
      int v268 = v267[0];
      v266[1] = v268;
      int * v270 = v252->cache_vals;
      int * v271 = v252->cache_vals;
      int v272 = v271[0];
      v270[1] = v272;
      int * v274 = v252->cache_keys;
      int v551 = (int)((unsigned int)v256 >> 2);
      v274[0] = v551;
      int * v276 = v252->cache_vals;
      v276[0] = v265;
      int v278 = v252->timer;
      int v554 = v278 + 1;
      v252->timer = v554;
      v304 = v265;
    } else {
      int * v281 = v252->mem;
      int v556 = (int)((unsigned int)v256 >> 2);
      int v282 = v281[v556];
      int * v283 = v252->mem;
      int * v284 = v252->cache_keys;
      int v285 = v284[1];
      int * v286 = v252->cache_vals;
      int v287 = v286[1];
      v283[v285] = v287;
      int * v289 = v252->cache_keys;
      int * v290 = v252->cache_keys;
      int v291 = v290[0];
      v289[1] = v291;
      int * v293 = v252->cache_vals;
      int * v294 = v252->cache_vals;
      int v295 = v294[0];
      v293[1] = v295;
      int * v297 = v252->cache_keys;
      v297[0] = v556;
      int * v299 = v252->cache_vals;
      v299[0] = v282;
      int v301 = v252->timer;
      int v571 = v301 + 100;
      v252->timer = v571;
      v304 = v282;
    }
    v306 = v304;
  }
  int * v307 = v252->regs;
  v307[14] = v306;
  struct StateT * v530 = v309(v252);
  return v530;
}

struct StateT * v9(struct StateT * v10) {
  int v11 = v10->timer;
  int v767 = v11 + 1;
  v10->timer = v767;
  int * v13 = v10->regs;
  v13[10] = 1;
  struct StateT * v765 = v15(v10);
  return v765;
}

struct StateT * snippet(struct StateT * v0) {
  struct StateT * v783 = v1(v0);
  return v783;
}

struct StateT * v229(struct StateT * v230) {
  int v231 = v230->timer;
  int v604 = v231 + 1;
  v230->timer = v604;
  int * v233 = v230->regs;
  int v234 = v233[12];
  int * v235 = v230->regs;
  int v608 = v234 + 4;
  v235[12] = v608;
  struct StateT * v602 = v237(v230);
  return v602;
}

struct StateT * v1(struct StateT * v2) {
  int v3 = v2->timer;
  int v775 = v3 + 1;
  v2->timer = v775;
  int * v5 = v2->regs;
  int v6 = v5[10];
  int * v7 = v2->regs;
  v7[11] = v6;
  struct StateT * v773 = v9(v2);
  return v773;
}

struct StateT * v205(struct StateT * v206) {
  int v207 = v206->timer;
  int v210 = v207 + 1;
  v206->timer = v210;
  return v206;
}

struct StateT * v199(struct StateT * v200) {
  int v201 = v200->timer;
  int v213 = v201 + 1;
  v200->timer = v213;
  int * v203 = v200->regs;
  v203[10] = 0;
  struct StateT * v211 = v205(v200);
  return v211;
}

struct StateT * v309(struct StateT * v310) {
  int v311 = v310->timer;
  int v484 = v311 + 1;
  v310->timer = v484;
  int * v313 = v310->regs;
  int v314 = v313[13];
  int * v315 = v310->cache_keys;
  int v316 = v315[0];
  bool v489 = v316 == ((int)((unsigned int)v314 >> 2));
  int v364;
  if (v489) {
    int * v317 = v310->cache_vals;
    int v318 = v317[0];
    v364 = v318;
  } else {
    int * v320 = v310->cache_keys;
    int v321 = v320[1];
    bool v494 = v321 == ((int)((unsigned int)v314 >> 2));
    int v362;
    if (v494) {
      int * v322 = v310->cache_vals;
      int v323 = v322[1];
      int * v324 = v310->cache_keys;
      int * v325 = v310->cache_keys;
      int v326 = v325[0];
      v324[1] = v326;
      int * v328 = v310->cache_vals;
      int * v329 = v310->cache_vals;
      int v330 = v329[0];
      v328[1] = v330;
      int * v332 = v310->cache_keys;
      int v503 = (int)((unsigned int)v314 >> 2);
      v332[0] = v503;
      int * v334 = v310->cache_vals;
      v334[0] = v323;
      int v336 = v310->timer;
      int v506 = v336 + 1;
      v310->timer = v506;
      v362 = v323;
    } else {
      int * v339 = v310->mem;
      int v508 = (int)((unsigned int)v314 >> 2);
      int v340 = v339[v508];
      int * v341 = v310->mem;
      int * v342 = v310->cache_keys;
      int v343 = v342[1];
      int * v344 = v310->cache_vals;
      int v345 = v344[1];
      v341[v343] = v345;
      int * v347 = v310->cache_keys;
      int * v348 = v310->cache_keys;
      int v349 = v348[0];
      v347[1] = v349;
      int * v351 = v310->cache_vals;
      int * v352 = v310->cache_vals;
      int v353 = v352[0];
      v351[1] = v353;
      int * v355 = v310->cache_keys;
      v355[0] = v508;
      int * v357 = v310->cache_vals;
      v357[0] = v340;
      int v359 = v310->timer;
      int v523 = v359 + 100;
      v310->timer = v523;
      v362 = v340;
    }
    v364 = v362;
  }
  int * v365 = v310->regs;
  v365[15] = v364;
  struct StateT * v482 = v367(v310);
  return v482;
}



/*****************************************
End of C Generated Code
*******************************************/

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

int main(int argc, char* argv[]) {
  struct StateT s1, s2;
  init(&s1);
  init(&s2);
  
  int n = bounded(0, 4);
  s1.regs[10] = n;
  s2.regs[10] = n;
  // guess, the attacker's: the same draw in both states
  for (int i=0; i<4; i++) {
    int v = bounded(0, 20);
    s1.mem[4 + i] = v;
    s2.mem[4 + i] = v;
  }
  
  // secret, secret: a different draw in each state
  for (int i=0; i<4; i++) {
    s1.mem[0 + i] = bounded(0, 20);
    s2.mem[0 + i] = bounded(0, 20);
  }
  struct StateT *s1_ = snippet(&s1);
  struct StateT *s2_ = snippet(&s2);
  __CPROVER_assert(s1_->timer==s2_->timer, "timing leak");
  return 0;
}