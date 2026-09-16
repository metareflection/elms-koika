// verify: clean (CBMC should report VERIFICATION SUCCESSFUL) [unwind 33]
#define NUM_REGS 32
#define MEM_SIZE 30
#define SECRET_SIZE 10
#define SECRET_OFFSET 20
#define CACHE_LRU_SIZE 10

#ifdef CBMC
int nondet_uint();
#define koika_assert(b, s) __CPROVER_assert(b, s)
#define koika_assume(b) __CPROVER_assume(b)
#define koika_draw(x) ((x) = nondet_uint())
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
  int mem[30];
  int saved_regs[32];
  int cache_keys[10];
  int cache_vals[10];
  int timer;
};

struct StateT * slot_12(struct StateT * v453);
struct StateT * slot_14(struct StateT * v489);
struct StateT * slot_6(struct StateT * v189);
struct StateT * slot_5(struct StateT * v77);
struct StateT * slot_2(struct StateT * v28);
struct StateT * slot_3(struct StateT * v41);
struct StateT * snippet(struct StateT * v0);
struct StateT * slot_10(struct StateT * v429);
struct StateT * slot_1(struct StateT * v15);
struct StateT * slot_8(struct StateT * v226);
struct StateT * slot_4(struct StateT * v49);
struct StateT * slot_13(struct StateT * v461);
struct StateT * slot_15(struct StateT * v601);
struct StateT * slot_9(struct StateT * v324);
struct StateT * slot_11(struct StateT * v445);
struct StateT * slot_0(struct StateT * v2);
struct StateT * slot_12(struct StateT * v453) {
  int v454 = v453->timer;
  int v458 = v454 + 1;
  v453->timer = v458;
  struct StateT * v456 = slot_13(v453);
  return v456;
}

struct StateT * slot_14(struct StateT * v489) {
  int * v490 = v489->saved_regs;
  int * v491 = v489->regs;
  int v492 = v491[5];
  v490[5] = v492;
  int v494 = v489->timer;
  int v556 = v494 + 1;
  v489->timer = v556;
  int * v496 = v489->regs;
  int v497 = v496[8];
  int * v498 = v489->cache_keys;
  int v499 = v498[0];
  bool v561 = v499 == ((int)((unsigned int)v497 >> 2));
  int v547;
  if (v561) {
    int * v500 = v489->cache_vals;
    int v501 = v500[0];
    v547 = v501;
  } else {
    int * v503 = v489->cache_keys;
    int v504 = v503[1];
    bool v566 = v504 == ((int)((unsigned int)v497 >> 2));
    int v545;
    if (v566) {
      int * v505 = v489->cache_vals;
      int v506 = v505[1];
      int * v507 = v489->cache_keys;
      int * v508 = v489->cache_keys;
      int v509 = v508[0];
      v507[1] = v509;
      int * v511 = v489->cache_vals;
      int * v512 = v489->cache_vals;
      int v513 = v512[0];
      v511[1] = v513;
      int * v515 = v489->cache_keys;
      int v575 = (int)((unsigned int)v497 >> 2);
      v515[0] = v575;
      int * v517 = v489->cache_vals;
      v517[0] = v506;
      int v519 = v489->timer;
      int v578 = v519 + 1;
      v489->timer = v578;
      v545 = v506;
    } else {
      int * v522 = v489->mem;
      int v580 = (int)((unsigned int)v497 >> 2);
      int v523 = v522[v580];
      int * v524 = v489->mem;
      int * v525 = v489->cache_keys;
      int v526 = v525[1];
      int * v527 = v489->cache_vals;
      int v528 = v527[1];
      v524[v526] = v528;
      int * v530 = v489->cache_keys;
      int * v531 = v489->cache_keys;
      int v532 = v531[0];
      v530[1] = v532;
      int * v534 = v489->cache_vals;
      int * v535 = v489->cache_vals;
      int v536 = v535[0];
      v534[1] = v536;
      int * v538 = v489->cache_keys;
      v538[0] = v580;
      int * v540 = v489->cache_vals;
      v540[0] = v523;
      int v542 = v489->timer;
      int v595 = v542 + 100;
      v489->timer = v595;
      v545 = v523;
    }
    v547 = v545;
  }
  int * v548 = v489->regs;
  v548[5] = v547;
  struct StateT * v550 = slot_15(v489);
  return v550;
}

struct StateT * slot_6(struct StateT * v189) {
  int * v190 = v189->regs;
  int v191 = v190[6];
  int * v192 = v189->regs;
  int v193 = v192[7];
  bool v213 = v191 >= v193;
  struct StateT * v207;
  if (v213) {
    int v194 = v189->timer;
    int v214 = v194 + 15;
    v189->timer = v214;
    int * v196 = v189->saved_regs;
    int v197 = v196[8];
    int * v198 = v189->regs;
    v198[8] = v197;
    int * v200 = v189->saved_regs;
    int v201 = v200[5];
    int * v202 = v189->regs;
    v202[5] = v201;
    v207 = v189;
  } else {
    struct StateT * v205 = slot_8(v189);
    v207 = v205;
  }
  return v207;
}

struct StateT * slot_5(struct StateT * v77) {
  int * v78 = v77->saved_regs;
  int * v79 = v77->regs;
  int v80 = v79[5];
  v78[5] = v80;
  int v82 = v77->timer;
  int v144 = v82 + 1;
  v77->timer = v144;
  int * v84 = v77->regs;
  int v85 = v84[8];
  int * v86 = v77->cache_keys;
  int v87 = v86[0];
  bool v149 = v87 == ((int)((unsigned int)v85 >> 2));
  int v135;
  if (v149) {
    int * v88 = v77->cache_vals;
    int v89 = v88[0];
    v135 = v89;
  } else {
    int * v91 = v77->cache_keys;
    int v92 = v91[1];
    bool v154 = v92 == ((int)((unsigned int)v85 >> 2));
    int v133;
    if (v154) {
      int * v93 = v77->cache_vals;
      int v94 = v93[1];
      int * v95 = v77->cache_keys;
      int * v96 = v77->cache_keys;
      int v97 = v96[0];
      v95[1] = v97;
      int * v99 = v77->cache_vals;
      int * v100 = v77->cache_vals;
      int v101 = v100[0];
      v99[1] = v101;
      int * v103 = v77->cache_keys;
      int v163 = (int)((unsigned int)v85 >> 2);
      v103[0] = v163;
      int * v105 = v77->cache_vals;
      v105[0] = v94;
      int v107 = v77->timer;
      int v166 = v107 + 1;
      v77->timer = v166;
      v133 = v94;
    } else {
      int * v110 = v77->mem;
      int v168 = (int)((unsigned int)v85 >> 2);
      int v111 = v110[v168];
      int * v112 = v77->mem;
      int * v113 = v77->cache_keys;
      int v114 = v113[1];
      int * v115 = v77->cache_vals;
      int v116 = v115[1];
      v112[v114] = v116;
      int * v118 = v77->cache_keys;
      int * v119 = v77->cache_keys;
      int v120 = v119[0];
      v118[1] = v120;
      int * v122 = v77->cache_vals;
      int * v123 = v77->cache_vals;
      int v124 = v123[0];
      v122[1] = v124;
      int * v126 = v77->cache_keys;
      v126[0] = v168;
      int * v128 = v77->cache_vals;
      v128[0] = v111;
      int v130 = v77->timer;
      int v183 = v130 + 100;
      v77->timer = v183;
      v133 = v111;
    }
    v135 = v133;
  }
  int * v136 = v77->regs;
  v136[5] = v135;
  struct StateT * v138 = slot_6(v77);
  return v138;
}

struct StateT * slot_2(struct StateT * v28) {
  int v29 = v28->timer;
  int v35 = v29 + 1;
  v28->timer = v35;
  int * v31 = v28->regs;
  v31[9] = 80;
  struct StateT * v33 = slot_3(v28);
  return v33;
}

struct StateT * slot_3(struct StateT * v41) {
  int v42 = v41->timer;
  int v46 = v42 + 1;
  v41->timer = v46;
  struct StateT * v44 = slot_4(v41);
  return v44;
}

struct StateT * snippet(struct StateT * v0) {
  struct StateT * v1 = slot_0(v0);
  return v1;
}

struct StateT * slot_10(struct StateT * v429) {
  int v430 = v429->timer;
  int v438 = v430 + 1;
  v429->timer = v438;
  int * v432 = v429->regs;
  int v433 = v432[6];
  int * v434 = v429->regs;
  int v442 = v433 + 4;
  v434[6] = v442;
  struct StateT * v436 = slot_11(v429);
  return v436;
}

struct StateT * slot_1(struct StateT * v15) {
  int v16 = v15->timer;
  int v22 = v16 + 1;
  v15->timer = v22;
  int * v18 = v15->regs;
  v18[7] = 16;
  struct StateT * v20 = slot_2(v15);
  return v20;
}

struct StateT * slot_8(struct StateT * v226) {
  int v227 = v226->timer;
  int v281 = v227 + 1;
  v226->timer = v281;
  int * v229 = v226->regs;
  int v230 = v229[6];
  int * v231 = v226->regs;
  int v232 = v231[5];
  int * v233 = v226->cache_keys;
  int v234 = v233[0];
  bool v288 = v234 == ((int)((unsigned int)v230 >> 2));
  int v278;
  if (v288) {
    int * v235 = v226->cache_vals;
    v235[0] = v232;
    v278 = v232;
  } else {
    int * v238 = v226->cache_keys;
    int v239 = v238[1];
    bool v293 = v239 == ((int)((unsigned int)v230 >> 2));
    int v276;
    if (v293) {
      int * v240 = v226->cache_keys;
      int * v241 = v226->cache_keys;
      int v242 = v241[0];
      v240[1] = v242;
      int * v244 = v226->cache_vals;
      int * v245 = v226->cache_vals;
      int v246 = v245[0];
      v244[1] = v246;
      int * v248 = v226->cache_keys;
      int v301 = (int)((unsigned int)v230 >> 2);
      v248[0] = v301;
      int * v250 = v226->cache_vals;
      v250[0] = v232;
      int v252 = v226->timer;
      int v304 = v252 + 1;
      v226->timer = v304;
      v276 = v232;
    } else {
      int * v255 = v226->mem;
      int * v256 = v226->cache_keys;
      int v257 = v256[1];
      int * v258 = v226->cache_vals;
      int v259 = v258[1];
      v255[v257] = v259;
      int * v261 = v226->cache_keys;
      int * v262 = v226->cache_keys;
      int v263 = v262[0];
      v261[1] = v263;
      int * v265 = v226->cache_vals;
      int * v266 = v226->cache_vals;
      int v267 = v266[0];
      v265[1] = v267;
      int * v269 = v226->cache_keys;
      int v317 = (int)((unsigned int)v230 >> 2);
      v269[0] = v317;
      int * v271 = v226->cache_vals;
      v271[0] = v232;
      int v273 = v226->timer;
      int v320 = v273 + 100;
      v226->timer = v320;
      v276 = v232;
    }
    v278 = v276;
  }
  struct StateT * v279 = slot_9(v226);
  return v279;
}

struct StateT * slot_4(struct StateT * v49) {
  int * v50 = v49->saved_regs;
  int * v51 = v49->regs;
  int v52 = v51[8];
  v50[8] = v52;
  int v54 = v49->timer;
  int v68 = v54 + 1;
  v49->timer = v68;
  int * v56 = v49->regs;
  int v57 = v56[9];
  int * v58 = v49->regs;
  int v59 = v58[6];
  int * v60 = v49->regs;
  int v74 = v57 + v59;
  v60[8] = v74;
  struct StateT * v62 = slot_5(v49);
  return v62;
}

struct StateT * slot_13(struct StateT * v461) {
  int * v462 = v461->saved_regs;
  int * v463 = v461->regs;
  int v464 = v463[8];
  v462[8] = v464;
  int v466 = v461->timer;
  int v480 = v466 + 1;
  v461->timer = v480;
  int * v468 = v461->regs;
  int v469 = v468[9];
  int * v470 = v461->regs;
  int v471 = v470[6];
  int * v472 = v461->regs;
  int v486 = v469 + v471;
  v472[8] = v486;
  struct StateT * v474 = slot_14(v461);
  return v474;
}

struct StateT * slot_15(struct StateT * v601) {
  int * v602 = v601->regs;
  int v603 = v602[6];
  int * v604 = v601->regs;
  int v605 = v604[7];
  bool v625 = v603 >= v605;
  struct StateT * v619;
  if (v625) {
    int v606 = v601->timer;
    int v626 = v606 + 15;
    v601->timer = v626;
    int * v608 = v601->saved_regs;
    int v609 = v608[8];
    int * v610 = v601->regs;
    v610[8] = v609;
    int * v612 = v601->saved_regs;
    int v613 = v612[5];
    int * v614 = v601->regs;
    v614[5] = v613;
    v619 = v601;
  } else {
    struct StateT * v617 = slot_8(v601);
    v619 = v617;
  }
  return v619;
}

struct StateT * slot_9(struct StateT * v324) {
  int v325 = v324->timer;
  int v383 = v325 + 1;
  v324->timer = v383;
  int * v327 = v324->regs;
  int v328 = v327[6];
  int * v329 = v324->cache_keys;
  int v330 = v329[0];
  bool v388 = v330 == ((int)((unsigned int)v328 >> 2));
  int v378;
  if (v388) {
    int * v331 = v324->cache_vals;
    int v332 = v331[0];
    v378 = v332;
  } else {
    int * v334 = v324->cache_keys;
    int v335 = v334[1];
    bool v393 = v335 == ((int)((unsigned int)v328 >> 2));
    int v376;
    if (v393) {
      int * v336 = v324->cache_vals;
      int v337 = v336[1];
      int * v338 = v324->cache_keys;
      int * v339 = v324->cache_keys;
      int v340 = v339[0];
      v338[1] = v340;
      int * v342 = v324->cache_vals;
      int * v343 = v324->cache_vals;
      int v344 = v343[0];
      v342[1] = v344;
      int * v346 = v324->cache_keys;
      int v402 = (int)((unsigned int)v328 >> 2);
      v346[0] = v402;
      int * v348 = v324->cache_vals;
      v348[0] = v337;
      int v350 = v324->timer;
      int v405 = v350 + 1;
      v324->timer = v405;
      v376 = v337;
    } else {
      int * v353 = v324->mem;
      int v407 = (int)((unsigned int)v328 >> 2);
      int v354 = v353[v407];
      int * v355 = v324->mem;
      int * v356 = v324->cache_keys;
      int v357 = v356[1];
      int * v358 = v324->cache_vals;
      int v359 = v358[1];
      v355[v357] = v359;
      int * v361 = v324->cache_keys;
      int * v362 = v324->cache_keys;
      int v363 = v362[0];
      v361[1] = v363;
      int * v365 = v324->cache_vals;
      int * v366 = v324->cache_vals;
      int v367 = v366[0];
      v365[1] = v367;
      int * v369 = v324->cache_keys;
      v369[0] = v407;
      int * v371 = v324->cache_vals;
      v371[0] = v354;
      int v373 = v324->timer;
      int v422 = v373 + 100;
      v324->timer = v422;
      v376 = v354;
    }
    v378 = v376;
  }
  int * v379 = v324->regs;
  v379[11] = v378;
  struct StateT * v381 = slot_10(v324);
  return v381;
}

struct StateT * slot_11(struct StateT * v445) {
  int v446 = v445->timer;
  int v450 = v446 + 1;
  v445->timer = v450;
  struct StateT * v448 = slot_12(v445);
  return v448;
}

struct StateT * slot_0(struct StateT * v2) {
  int v3 = v2->timer;
  int v9 = v3 + 1;
  v2->timer = v9;
  int * v5 = v2->regs;
  v5[6] = 0;
  struct StateT * v7 = slot_1(v2);
  return v7;
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
  koika_assert(s1_->timer==s2_->timer, "timing leak");
  return 0;
}