// verify: leak (KLEE should report a failing assertion) [budget 120s]
#define NUM_REGS 32
#define MEM_SIZE 30
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
  int mem[30];
  int saved_regs[32];
  int cache_keys[10];
  int cache_vals[10];
  int timer;
};

struct StateT * slot_12(struct StateT * v411);
struct StateT * slot_14(struct StateT * v356);
struct StateT * slot_16(struct StateT * v390);
struct StateT * slot_2(struct StateT * v32);
struct StateT * slot_7(struct StateT * v447);
struct StateT * snippet(struct StateT * v0);
struct StateT * slot_10(struct StateT * v374);
struct StateT * slot_1(struct StateT * v19);
struct StateT * slot_8(struct StateT * v552);
struct StateT * slot_13(struct StateT * v427);
struct StateT * slot_15(struct StateT * v361);
struct StateT * slot_9(struct StateT * v657);
struct StateT * slot_11(struct StateT * v395);
struct StateT * slot_0(struct StateT * v2);
struct StateT * slot_12(struct StateT * v411) {
  int v412 = v411->timer;
  int v420 = v412 + 1;
  v411->timer = v420;
  int * v414 = v411->regs;
  int v415 = v414[13];
  int * v416 = v411->regs;
  int v424 = v415 + 4;
  v416[13] = v424;
  struct StateT * v418 = slot_13(v411);
  return v418;
}

struct StateT * slot_14(struct StateT * v356) {
  int v357 = v356->timer;
  int v360 = v357 + 1;
  v356->timer = v360;
  return v356;
}

struct StateT * slot_16(struct StateT * v390) {
  int v391 = v390->timer;
  int v394 = v391 + 1;
  v390->timer = v394;
  return v390;
}

struct StateT * slot_2(struct StateT * v32) {
  int * v33 = v32->saved_regs;
  int * v34 = v32->regs;
  int v35 = v34[12];
  v33[12] = v35;
  int v37 = v32->timer;
  int v221 = v37 + 1;
  v32->timer = v221;
  int * v39 = v32->regs;
  v39[12] = 0;
  int v41 = v32->timer;
  int v224 = v41 + 1;
  v32->timer = v224;
  int * v43 = v32->regs;
  int v44 = v43[12];
  int * v45 = v32->regs;
  int v227 = v44 + 16;
  v45[12] = v227;
  int * v47 = v32->saved_regs;
  int * v48 = v32->regs;
  int v49 = v48[13];
  v47[13] = v49;
  int v51 = v32->timer;
  int v232 = v51 + 1;
  v32->timer = v232;
  int * v53 = v32->regs;
  v53[13] = 0;
  int v55 = v32->timer;
  int v234 = v55 + 1;
  v32->timer = v234;
  int * v57 = v32->regs;
  int v58 = v57[13];
  int * v59 = v32->regs;
  v59[13] = v58;
  int * v61 = v32->saved_regs;
  int * v62 = v32->regs;
  int v63 = v62[14];
  v61[14] = v63;
  int v65 = v32->timer;
  int v242 = v65 + 1;
  v32->timer = v242;
  int * v67 = v32->regs;
  int v68 = v67[12];
  int * v69 = v32->cache_keys;
  int v70 = v69[0];
  bool v245 = v70 == ((int)((unsigned int)v68 >> 2));
  int v118;
  if (v245) {
    int * v71 = v32->cache_vals;
    int v72 = v71[0];
    v118 = v72;
  } else {
    int * v74 = v32->cache_keys;
    int v75 = v74[1];
    bool v250 = v75 == ((int)((unsigned int)v68 >> 2));
    int v116;
    if (v250) {
      int * v76 = v32->cache_vals;
      int v77 = v76[1];
      int * v78 = v32->cache_keys;
      int * v79 = v32->cache_keys;
      int v80 = v79[0];
      v78[1] = v80;
      int * v82 = v32->cache_vals;
      int * v83 = v32->cache_vals;
      int v84 = v83[0];
      v82[1] = v84;
      int * v86 = v32->cache_keys;
      int v259 = (int)((unsigned int)v68 >> 2);
      v86[0] = v259;
      int * v88 = v32->cache_vals;
      v88[0] = v77;
      int v90 = v32->timer;
      int v262 = v90 + 1;
      v32->timer = v262;
      v116 = v77;
    } else {
      int * v93 = v32->mem;
      int v264 = (int)((unsigned int)v68 >> 2);
      int v94 = v93[v264];
      int * v95 = v32->mem;
      int * v96 = v32->cache_keys;
      int v97 = v96[1];
      int * v98 = v32->cache_vals;
      int v99 = v98[1];
      v95[v97] = v99;
      int * v101 = v32->cache_keys;
      int * v102 = v32->cache_keys;
      int v103 = v102[0];
      v101[1] = v103;
      int * v105 = v32->cache_vals;
      int * v106 = v32->cache_vals;
      int v107 = v106[0];
      v105[1] = v107;
      int * v109 = v32->cache_keys;
      v109[0] = v264;
      int * v111 = v32->cache_vals;
      v111[0] = v94;
      int v113 = v32->timer;
      int v279 = v113 + 100;
      v32->timer = v279;
      v116 = v94;
    }
    v118 = v116;
  }
  int * v119 = v32->regs;
  v119[14] = v118;
  int * v121 = v32->saved_regs;
  int * v122 = v32->regs;
  int v123 = v122[15];
  v121[15] = v123;
  int v125 = v32->timer;
  int v287 = v125 + 1;
  v32->timer = v287;
  int * v127 = v32->regs;
  int v128 = v127[13];
  int * v129 = v32->cache_keys;
  int v130 = v129[0];
  bool v290 = v130 == ((int)((unsigned int)v128 >> 2));
  int v178;
  if (v290) {
    int * v131 = v32->cache_vals;
    int v132 = v131[0];
    v178 = v132;
  } else {
    int * v134 = v32->cache_keys;
    int v135 = v134[1];
    bool v295 = v135 == ((int)((unsigned int)v128 >> 2));
    int v176;
    if (v295) {
      int * v136 = v32->cache_vals;
      int v137 = v136[1];
      int * v138 = v32->cache_keys;
      int * v139 = v32->cache_keys;
      int v140 = v139[0];
      v138[1] = v140;
      int * v142 = v32->cache_vals;
      int * v143 = v32->cache_vals;
      int v144 = v143[0];
      v142[1] = v144;
      int * v146 = v32->cache_keys;
      int v304 = (int)((unsigned int)v128 >> 2);
      v146[0] = v304;
      int * v148 = v32->cache_vals;
      v148[0] = v137;
      int v150 = v32->timer;
      int v307 = v150 + 1;
      v32->timer = v307;
      v176 = v137;
    } else {
      int * v153 = v32->mem;
      int v309 = (int)((unsigned int)v128 >> 2);
      int v154 = v153[v309];
      int * v155 = v32->mem;
      int * v156 = v32->cache_keys;
      int v157 = v156[1];
      int * v158 = v32->cache_vals;
      int v159 = v158[1];
      v155[v157] = v159;
      int * v161 = v32->cache_keys;
      int * v162 = v32->cache_keys;
      int v163 = v162[0];
      v161[1] = v163;
      int * v165 = v32->cache_vals;
      int * v166 = v32->cache_vals;
      int v167 = v166[0];
      v165[1] = v167;
      int * v169 = v32->cache_keys;
      v169[0] = v309;
      int * v171 = v32->cache_vals;
      v171[0] = v154;
      int v173 = v32->timer;
      int v324 = v173 + 100;
      v32->timer = v324;
      v176 = v154;
    }
    v178 = v176;
  }
  int * v179 = v32->regs;
  v179[15] = v178;
  int * v181 = v32->regs;
  int v182 = v181[11];
  bool v330 = 0 >= v182;
  struct StateT * v215;
  if (v330) {
    int v183 = v32->timer;
    int v331 = v183 + 15;
    v32->timer = v331;
    int * v185 = v32->saved_regs;
    int v186 = v185[12];
    int * v187 = v32->regs;
    v187[12] = v186;
    int * v189 = v32->saved_regs;
    int v190 = v189[13];
    int * v191 = v32->regs;
    v191[13] = v190;
    int * v193 = v32->saved_regs;
    int v194 = v193[14];
    int * v195 = v32->regs;
    v195[14] = v194;
    int * v197 = v32->saved_regs;
    int v198 = v197[15];
    int * v199 = v32->regs;
    v199[15] = v198;
    struct StateT * v201 = slot_14(v32);
    v215 = v201;
  } else {
    int v203 = v32->timer;
    int v346 = v203 + 1;
    v32->timer = v346;
    int * v205 = v32->regs;
    int v206 = v205[14];
    int * v207 = v32->regs;
    int v208 = v207[15];
    bool v349 = !(v206 == v208);
    struct StateT * v213;
    if (v349) {
      struct StateT * v209 = slot_15(v32);
      v213 = v209;
    } else {
      struct StateT * v211 = slot_10(v32);
      v213 = v211;
    }
    v215 = v213;
  }
  return v215;
}

struct StateT * slot_7(struct StateT * v447) {
  int v448 = v447->timer;
  int v506 = v448 + 1;
  v447->timer = v506;
  int * v450 = v447->regs;
  int v451 = v450[12];
  int * v452 = v447->cache_keys;
  int v453 = v452[0];
  bool v511 = v453 == ((int)((unsigned int)v451 >> 2));
  int v501;
  if (v511) {
    int * v454 = v447->cache_vals;
    int v455 = v454[0];
    v501 = v455;
  } else {
    int * v457 = v447->cache_keys;
    int v458 = v457[1];
    bool v516 = v458 == ((int)((unsigned int)v451 >> 2));
    int v499;
    if (v516) {
      int * v459 = v447->cache_vals;
      int v460 = v459[1];
      int * v461 = v447->cache_keys;
      int * v462 = v447->cache_keys;
      int v463 = v462[0];
      v461[1] = v463;
      int * v465 = v447->cache_vals;
      int * v466 = v447->cache_vals;
      int v467 = v466[0];
      v465[1] = v467;
      int * v469 = v447->cache_keys;
      int v525 = (int)((unsigned int)v451 >> 2);
      v469[0] = v525;
      int * v471 = v447->cache_vals;
      v471[0] = v460;
      int v473 = v447->timer;
      int v528 = v473 + 1;
      v447->timer = v528;
      v499 = v460;
    } else {
      int * v476 = v447->mem;
      int v530 = (int)((unsigned int)v451 >> 2);
      int v477 = v476[v530];
      int * v478 = v447->mem;
      int * v479 = v447->cache_keys;
      int v480 = v479[1];
      int * v481 = v447->cache_vals;
      int v482 = v481[1];
      v478[v480] = v482;
      int * v484 = v447->cache_keys;
      int * v485 = v447->cache_keys;
      int v486 = v485[0];
      v484[1] = v486;
      int * v488 = v447->cache_vals;
      int * v489 = v447->cache_vals;
      int v490 = v489[0];
      v488[1] = v490;
      int * v492 = v447->cache_keys;
      v492[0] = v530;
      int * v494 = v447->cache_vals;
      v494[0] = v477;
      int v496 = v447->timer;
      int v545 = v496 + 100;
      v447->timer = v545;
      v499 = v477;
    }
    v501 = v499;
  }
  int * v502 = v447->regs;
  v502[14] = v501;
  struct StateT * v504 = slot_8(v447);
  return v504;
}

struct StateT * snippet(struct StateT * v0) {
  struct StateT * v1 = slot_0(v0);
  return v1;
}

struct StateT * slot_10(struct StateT * v374) {
  int v375 = v374->timer;
  int v383 = v375 + 1;
  v374->timer = v383;
  int * v377 = v374->regs;
  int v378 = v377[11];
  int * v379 = v374->regs;
  int v387 = v378 + -1;
  v379[11] = v387;
  struct StateT * v381 = slot_11(v374);
  return v381;
}

struct StateT * slot_1(struct StateT * v19) {
  int v20 = v19->timer;
  int v26 = v20 + 1;
  v19->timer = v26;
  int * v22 = v19->regs;
  v22[10] = 1;
  struct StateT * v24 = slot_2(v19);
  return v24;
}

struct StateT * slot_8(struct StateT * v552) {
  int v553 = v552->timer;
  int v611 = v553 + 1;
  v552->timer = v611;
  int * v555 = v552->regs;
  int v556 = v555[13];
  int * v557 = v552->cache_keys;
  int v558 = v557[0];
  bool v616 = v558 == ((int)((unsigned int)v556 >> 2));
  int v606;
  if (v616) {
    int * v559 = v552->cache_vals;
    int v560 = v559[0];
    v606 = v560;
  } else {
    int * v562 = v552->cache_keys;
    int v563 = v562[1];
    bool v621 = v563 == ((int)((unsigned int)v556 >> 2));
    int v604;
    if (v621) {
      int * v564 = v552->cache_vals;
      int v565 = v564[1];
      int * v566 = v552->cache_keys;
      int * v567 = v552->cache_keys;
      int v568 = v567[0];
      v566[1] = v568;
      int * v570 = v552->cache_vals;
      int * v571 = v552->cache_vals;
      int v572 = v571[0];
      v570[1] = v572;
      int * v574 = v552->cache_keys;
      int v630 = (int)((unsigned int)v556 >> 2);
      v574[0] = v630;
      int * v576 = v552->cache_vals;
      v576[0] = v565;
      int v578 = v552->timer;
      int v633 = v578 + 1;
      v552->timer = v633;
      v604 = v565;
    } else {
      int * v581 = v552->mem;
      int v635 = (int)((unsigned int)v556 >> 2);
      int v582 = v581[v635];
      int * v583 = v552->mem;
      int * v584 = v552->cache_keys;
      int v585 = v584[1];
      int * v586 = v552->cache_vals;
      int v587 = v586[1];
      v583[v585] = v587;
      int * v589 = v552->cache_keys;
      int * v590 = v552->cache_keys;
      int v591 = v590[0];
      v589[1] = v591;
      int * v593 = v552->cache_vals;
      int * v594 = v552->cache_vals;
      int v595 = v594[0];
      v593[1] = v595;
      int * v597 = v552->cache_keys;
      v597[0] = v635;
      int * v599 = v552->cache_vals;
      v599[0] = v582;
      int v601 = v552->timer;
      int v650 = v601 + 100;
      v552->timer = v650;
      v604 = v582;
    }
    v606 = v604;
  }
  int * v607 = v552->regs;
  v607[15] = v606;
  struct StateT * v609 = slot_9(v552);
  return v609;
}

struct StateT * slot_13(struct StateT * v427) {
  int v428 = v427->timer;
  int v438 = v428 + 1;
  v427->timer = v438;
  int * v430 = v427->regs;
  int v431 = v430[11];
  bool v441 = !(v431 == 0);
  struct StateT * v436;
  if (v441) {
    struct StateT * v432 = slot_7(v427);
    v436 = v432;
  } else {
    struct StateT * v434 = slot_14(v427);
    v436 = v434;
  }
  return v436;
}

struct StateT * slot_15(struct StateT * v361) {
  int v362 = v361->timer;
  int v368 = v362 + 1;
  v361->timer = v368;
  int * v364 = v361->regs;
  v364[10] = 0;
  struct StateT * v366 = slot_16(v361);
  return v366;
}

struct StateT * slot_9(struct StateT * v657) {
  int * v658 = v657->saved_regs;
  int * v659 = v657->regs;
  int v660 = v659[11];
  v658[11] = v660;
  int v662 = v657->timer;
  int v724 = v662 + 1;
  v657->timer = v724;
  int * v664 = v657->regs;
  int v665 = v664[11];
  int * v666 = v657->regs;
  int v727 = v665 + -1;
  v666[11] = v727;
  int v668 = v657->timer;
  int v728 = v668 + 1;
  v657->timer = v728;
  int * v670 = v657->regs;
  int v671 = v670[12];
  int * v672 = v657->regs;
  int v732 = v671 + 4;
  v672[12] = v732;
  int v674 = v657->timer;
  int v733 = v674 + 1;
  v657->timer = v733;
  int * v676 = v657->regs;
  int v677 = v676[13];
  int * v678 = v657->regs;
  int v737 = v677 + 4;
  v678[13] = v737;
  int * v680 = v657->regs;
  int v681 = v680[14];
  int * v682 = v657->regs;
  int v683 = v682[15];
  bool v742 = !(v681 == v683);
  struct StateT * v718;
  if (v742) {
    int v684 = v657->timer;
    int v743 = v684 + 15;
    v657->timer = v743;
    int * v686 = v657->saved_regs;
    int v687 = v686[12];
    int * v688 = v657->regs;
    v688[12] = v687;
    int * v690 = v657->saved_regs;
    int v691 = v690[13];
    int * v692 = v657->regs;
    v692[13] = v691;
    int * v694 = v657->saved_regs;
    int v695 = v694[14];
    int * v696 = v657->regs;
    v696[14] = v695;
    int * v698 = v657->saved_regs;
    int v699 = v698[15];
    int * v700 = v657->regs;
    v700[15] = v699;
    int * v702 = v657->saved_regs;
    int v703 = v702[11];
    int * v704 = v657->regs;
    v704[11] = v703;
    struct StateT * v706 = slot_15(v657);
    v718 = v706;
  } else {
    int v708 = v657->timer;
    int v761 = v708 + 1;
    v657->timer = v761;
    int * v710 = v657->regs;
    int v711 = v710[11];
    bool v763 = !(v711 == 0);
    struct StateT * v716;
    if (v763) {
      struct StateT * v712 = slot_7(v657);
      v716 = v712;
    } else {
      struct StateT * v714 = slot_14(v657);
      v716 = v714;
    }
    v718 = v716;
  }
  return v718;
}

struct StateT * slot_11(struct StateT * v395) {
  int v396 = v395->timer;
  int v404 = v396 + 1;
  v395->timer = v404;
  int * v398 = v395->regs;
  int v399 = v398[12];
  int * v400 = v395->regs;
  int v408 = v399 + 4;
  v400[12] = v408;
  struct StateT * v402 = slot_12(v395);
  return v402;
}

struct StateT * slot_0(struct StateT * v2) {
  int v3 = v2->timer;
  int v11 = v3 + 1;
  v2->timer = v11;
  int * v5 = v2->regs;
  int v6 = v5[10];
  int * v7 = v2->regs;
  v7[11] = v6;
  struct StateT * v9 = slot_1(v2);
  return v9;
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
  koika_assert(s1_->timer==s2_->timer, "timing leak");
  return 0;
}