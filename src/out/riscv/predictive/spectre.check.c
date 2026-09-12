
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
struct StateT * v321(struct StateT * v322);
struct StateT * v39(struct StateT * v40);
struct StateT * v391(struct StateT * v392);
struct StateT * v307(struct StateT * v308);
struct StateT * v107(struct StateT * v108);
struct StateT * v383(struct StateT * v384);
struct StateT * v115(struct StateT * v116);
struct StateT * snippet(struct StateT * v0);
struct StateT * v1(struct StateT * v2);
struct StateT * v7(struct StateT * v8);
struct StateT * v13(struct StateT * v14);
struct StateT * v49(struct StateT * v50);
struct StateT * v453(struct StateT * v454);
struct StateT * v19(struct StateT * v20) {
  int v21 = v20->timer;
  int v636 = v21 + 1;
  v20->timer = v636;int * v23 = v20->bht;
  int v24 = v23[0];
  bool v639 = !(v24 == 0);
  struct StateT * v634 = (v639 ? ({
    struct StateT * v305 = v25(v20);
    v305;
  }) : ({
    struct StateT * v632 = v307(v20);
    v632;
  }));
  return v634;
}

struct StateT * v25(struct StateT * v26) {
  int * v27 = v26->regs;
  int v28 = v27[10];
  int * v29 = v26->regs;
  int v30 = v29[15];
  int * v31 = v26->bht;
  bool v295 = v28 >= v30;
  int v34 = (v295 ? 1 : 0);
  v31[0] = v34;
  struct StateT * v289 = (v295 ? v26 : ({
    int v37 = v26->timer;
    int v301 = v37 + 15;
    v26->timer = v301;struct StateT * v287 = v39(v26);
    v287;
  }));
  return v289;
}

struct StateT * v321(struct StateT * v322) {
  int * v323 = v322->saved_regs;
  int * v324 = v322->regs;
  int v325 = v324[11];
  v323[11] = v325;
  int v327 = v322->timer;
  int v572 = v327 + 1;
  v322->timer = v572;int * v329 = v322->regs;
  int v330 = v329[5];
  int * v331 = v322->cache_keys;
  int v332 = v331[0];
  bool v577 = v332 == ((int)((unsigned int)v330 >> 2));
  int v380 = (v577 ? ({
    int * v333 = v322->cache_vals;
    int v334 = v333[0];
    v334;
  }) : ({
    int * v336 = v322->cache_keys;
    int v337 = v336[1];
    bool v582 = v337 == ((int)((unsigned int)v330 >> 2));
    int v378 = (v582 ? ({
      int * v338 = v322->cache_vals;
      int v339 = v338[1];
      int * v340 = v322->cache_keys;
      int * v341 = v322->cache_keys;
      int v342 = v341[0];
      v340[1] = v342;
      int * v344 = v322->cache_vals;
      int * v345 = v322->cache_vals;
      int v346 = v345[0];
      v344[1] = v346;
      int * v348 = v322->cache_keys;
      int v591 = (int)((unsigned int)v330 >> 2);
      v348[0] = v591;
      int * v350 = v322->cache_vals;
      v350[0] = v339;
      int v352 = v322->timer;
      int v594 = v352 + 1;
      v322->timer = v594;v339;
    }) : ({
      int * v355 = v322->mem;
      int v596 = (int)((unsigned int)v330 >> 2);
      int v356 = v355[v596];
      int * v357 = v322->mem;
      int * v358 = v322->cache_keys;
      int v359 = v358[1];
      int * v360 = v322->cache_vals;
      int v361 = v360[1];
      v357[v359] = v361;
      int * v363 = v322->cache_keys;
      int * v364 = v322->cache_keys;
      int v365 = v364[0];
      v363[1] = v365;
      int * v367 = v322->cache_vals;
      int * v368 = v322->cache_vals;
      int v369 = v368[0];
      v367[1] = v369;
      int * v371 = v322->cache_keys;
      v371[0] = v596;
      int * v373 = v322->cache_vals;
      v373[0] = v356;
      int v375 = v322->timer;
      int v611 = v375 + 100;
      v322->timer = v611;v356;
    }));
    v378;
  }));
  int * v381 = v322->regs;
  v381[11] = v380;
  struct StateT * v566 = v383(v322);
  return v566;
}

struct StateT * v39(struct StateT * v40) {
  int v41 = v40->timer;
  int v277 = v41 + 1;
  v40->timer = v277;int * v43 = v40->regs;
  int v44 = v43[13];
  int * v45 = v40->regs;
  int v46 = v45[10];
  int * v47 = v40->regs;
  int v284 = v44 + v46;
  v47[5] = v284;
  struct StateT * v275 = v49(v40);
  return v275;
}

struct StateT * v391(struct StateT * v392) {
  int * v393 = v392->saved_regs;
  int * v394 = v392->regs;
  int v395 = v394[12];
  v393[12] = v395;
  int v397 = v392->timer;
  int v512 = v397 + 1;
  v392->timer = v512;int * v399 = v392->regs;
  int v400 = v399[11];
  int * v401 = v392->cache_keys;
  int v402 = v401[0];
  bool v517 = v402 == ((int)((unsigned int)v400 >> 2));
  int v450 = (v517 ? ({
    int * v403 = v392->cache_vals;
    int v404 = v403[0];
    v404;
  }) : ({
    int * v406 = v392->cache_keys;
    int v407 = v406[1];
    bool v522 = v407 == ((int)((unsigned int)v400 >> 2));
    int v448 = (v522 ? ({
      int * v408 = v392->cache_vals;
      int v409 = v408[1];
      int * v410 = v392->cache_keys;
      int * v411 = v392->cache_keys;
      int v412 = v411[0];
      v410[1] = v412;
      int * v414 = v392->cache_vals;
      int * v415 = v392->cache_vals;
      int v416 = v415[0];
      v414[1] = v416;
      int * v418 = v392->cache_keys;
      int v531 = (int)((unsigned int)v400 >> 2);
      v418[0] = v531;
      int * v420 = v392->cache_vals;
      v420[0] = v409;
      int v422 = v392->timer;
      int v534 = v422 + 1;
      v392->timer = v534;v409;
    }) : ({
      int * v425 = v392->mem;
      int v536 = (int)((unsigned int)v400 >> 2);
      int v426 = v425[v536];
      int * v427 = v392->mem;
      int * v428 = v392->cache_keys;
      int v429 = v428[1];
      int * v430 = v392->cache_vals;
      int v431 = v430[1];
      v427[v429] = v431;
      int * v433 = v392->cache_keys;
      int * v434 = v392->cache_keys;
      int v435 = v434[0];
      v433[1] = v435;
      int * v437 = v392->cache_vals;
      int * v438 = v392->cache_vals;
      int v439 = v438[0];
      v437[1] = v439;
      int * v441 = v392->cache_keys;
      v441[0] = v536;
      int * v443 = v392->cache_vals;
      v443[0] = v426;
      int v445 = v392->timer;
      int v551 = v445 + 100;
      v392->timer = v551;v426;
    }));
    v448;
  }));
  int * v451 = v392->regs;
  v451[12] = v450;
  struct StateT * v506 = v453(v392);
  return v506;
}

struct StateT * v307(struct StateT * v308) {
  int * v309 = v308->saved_regs;
  int * v310 = v308->regs;
  int v311 = v310[5];
  v309[5] = v311;
  int v313 = v308->timer;
  int v623 = v313 + 1;
  v308->timer = v623;int * v315 = v308->regs;
  int v316 = v315[13];
  int * v317 = v308->regs;
  int v318 = v317[10];
  int * v319 = v308->regs;
  int v629 = v316 + v318;
  v319[5] = v629;
  struct StateT * v617 = v321(v308);
  return v617;
}

struct StateT * v107(struct StateT * v108) {
  int v109 = v108->timer;
  int v220 = v109 + 1;
  v108->timer = v220;int * v111 = v108->regs;
  int v112 = v111[11];
  int * v113 = v108->regs;
  int v224 = v112 << 2;
  v113[11] = v224;
  struct StateT * v218 = v115(v108);
  return v218;
}

struct StateT * v383(struct StateT * v384) {
  int v385 = v384->timer;
  int v559 = v385 + 1;
  v384->timer = v559;int * v387 = v384->regs;
  int v388 = v387[11];
  int * v389 = v384->regs;
  int v563 = v388 << 2;
  v389[11] = v563;
  struct StateT * v557 = v391(v384);
  return v557;
}

struct StateT * v115(struct StateT * v116) {
  int v117 = v116->timer;
  int v174 = v117 + 1;
  v116->timer = v174;int * v119 = v116->regs;
  int v120 = v119[11];
  int * v121 = v116->cache_keys;
  int v122 = v121[0];
  bool v179 = v122 == ((int)((unsigned int)v120 >> 2));
  int v170 = (v179 ? ({
    int * v123 = v116->cache_vals;
    int v124 = v123[0];
    v124;
  }) : ({
    int * v126 = v116->cache_keys;
    int v127 = v126[1];
    bool v184 = v127 == ((int)((unsigned int)v120 >> 2));
    int v168 = (v184 ? ({
      int * v128 = v116->cache_vals;
      int v129 = v128[1];
      int * v130 = v116->cache_keys;
      int * v131 = v116->cache_keys;
      int v132 = v131[0];
      v130[1] = v132;
      int * v134 = v116->cache_vals;
      int * v135 = v116->cache_vals;
      int v136 = v135[0];
      v134[1] = v136;
      int * v138 = v116->cache_keys;
      int v193 = (int)((unsigned int)v120 >> 2);
      v138[0] = v193;
      int * v140 = v116->cache_vals;
      v140[0] = v129;
      int v142 = v116->timer;
      int v196 = v142 + 1;
      v116->timer = v196;v129;
    }) : ({
      int * v145 = v116->mem;
      int v198 = (int)((unsigned int)v120 >> 2);
      int v146 = v145[v198];
      int * v147 = v116->mem;
      int * v148 = v116->cache_keys;
      int v149 = v148[1];
      int * v150 = v116->cache_vals;
      int v151 = v150[1];
      v147[v149] = v151;
      int * v153 = v116->cache_keys;
      int * v154 = v116->cache_keys;
      int v155 = v154[0];
      v153[1] = v155;
      int * v157 = v116->cache_vals;
      int * v158 = v116->cache_vals;
      int v159 = v158[0];
      v157[1] = v159;
      int * v161 = v116->cache_keys;
      v161[0] = v198;
      int * v163 = v116->cache_vals;
      v163[0] = v146;
      int v165 = v116->timer;
      int v213 = v165 + 100;
      v116->timer = v213;v146;
    }));
    v168;
  }));
  int * v171 = v116->regs;
  v171[12] = v170;
  return v116;
}

struct StateT * snippet(struct StateT * v0) {
  struct StateT * v669 = v1(v0);
  return v669;
}

struct StateT * v1(struct StateT * v2) {
  int v3 = v2->timer;
  int v663 = v3 + 1;
  v2->timer = v663;int * v5 = v2->regs;
  v5[13] = 0;
  struct StateT * v661 = v7(v2);
  return v661;
}

struct StateT * v7(struct StateT * v8) {
  int v9 = v8->timer;
  int v655 = v9 + 1;
  v8->timer = v655;int * v11 = v8->regs;
  v11[10] = 80;
  struct StateT * v653 = v13(v8);
  return v653;
}

struct StateT * v13(struct StateT * v14) {
  int v15 = v14->timer;
  int v647 = v15 + 1;
  v14->timer = v647;int * v17 = v14->regs;
  v17[15] = 80;
  struct StateT * v645 = v19(v14);
  return v645;
}

struct StateT * v49(struct StateT * v50) {
  int v51 = v50->timer;
  int v229 = v51 + 1;
  v50->timer = v229;int * v53 = v50->regs;
  int v54 = v53[5];
  int * v55 = v50->cache_keys;
  int v56 = v55[0];
  bool v234 = v56 == ((int)((unsigned int)v54 >> 2));
  int v104 = (v234 ? ({
    int * v57 = v50->cache_vals;
    int v58 = v57[0];
    v58;
  }) : ({
    int * v60 = v50->cache_keys;
    int v61 = v60[1];
    bool v239 = v61 == ((int)((unsigned int)v54 >> 2));
    int v102 = (v239 ? ({
      int * v62 = v50->cache_vals;
      int v63 = v62[1];
      int * v64 = v50->cache_keys;
      int * v65 = v50->cache_keys;
      int v66 = v65[0];
      v64[1] = v66;
      int * v68 = v50->cache_vals;
      int * v69 = v50->cache_vals;
      int v70 = v69[0];
      v68[1] = v70;
      int * v72 = v50->cache_keys;
      int v248 = (int)((unsigned int)v54 >> 2);
      v72[0] = v248;
      int * v74 = v50->cache_vals;
      v74[0] = v63;
      int v76 = v50->timer;
      int v251 = v76 + 1;
      v50->timer = v251;v63;
    }) : ({
      int * v79 = v50->mem;
      int v253 = (int)((unsigned int)v54 >> 2);
      int v80 = v79[v253];
      int * v81 = v50->mem;
      int * v82 = v50->cache_keys;
      int v83 = v82[1];
      int * v84 = v50->cache_vals;
      int v85 = v84[1];
      v81[v83] = v85;
      int * v87 = v50->cache_keys;
      int * v88 = v50->cache_keys;
      int v89 = v88[0];
      v87[1] = v89;
      int * v91 = v50->cache_vals;
      int * v92 = v50->cache_vals;
      int v93 = v92[0];
      v91[1] = v93;
      int * v95 = v50->cache_keys;
      v95[0] = v253;
      int * v97 = v50->cache_vals;
      v97[0] = v80;
      int v99 = v50->timer;
      int v268 = v99 + 100;
      v50->timer = v268;v80;
    }));
    v102;
  }));
  int * v105 = v50->regs;
  v105[11] = v104;
  struct StateT * v227 = v107(v50);
  return v227;
}

struct StateT * v453(struct StateT * v454) {
  int * v455 = v454->regs;
  int v456 = v455[10];
  int * v457 = v454->regs;
  int v458 = v457[15];
  int * v459 = v454->bht;
  bool v486 = v456 >= v458;
  int v462 = (v486 ? 1 : 0);
  v459[0] = v462;
  struct StateT * v480 = (v486 ? ({
    int v464 = v454->timer;
    int v492 = v464 + 15;
    v454->timer = v492;int * v466 = v454->saved_regs;
    int v467 = v466[5];
    int * v468 = v454->regs;
    v468[5] = v467;
    int * v470 = v454->saved_regs;
    int v471 = v470[11];
    int * v472 = v454->regs;
    v472[11] = v471;
    int * v474 = v454->saved_regs;
    int v475 = v474[12];
    int * v476 = v454->regs;
    v476[12] = v475;
    v454;
  }) : v454);
  return v480;
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