// verify: leak (CBMC should report VERIFICATION FAILED) [unwind 65]
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

struct StateT2 * slot_12(struct StateT2 * v611);
struct StateT2 * slot_14(struct StateT2 * v128);
struct StateT2 * slot_6(struct StateT2 * v266);
struct StateT2 * slot_16(struct StateT2 * v545);
struct StateT2 * slot_5(struct StateT2 * v230);
struct StateT2 * slot_2(struct StateT2 * v82);
struct StateT2 * slot_7(struct StateT2 * v309);
struct StateT2 * slot_3(struct StateT2 * v151);
struct StateT2 * snippet(struct StateT2 * v0);
struct StateT2 * slot_10(struct StateT2 * v502);
struct StateT2 * slot_1(struct StateT2 * v46);
struct StateT2 * slot_8(struct StateT2 * v361);
struct StateT2 * slot_4(struct StateT2 * v187);
struct StateT2 * slot_13(struct StateT2 * v654);
struct StateT2 * slot_15(struct StateT2 * v466);
struct StateT2 * slot_9(struct StateT2 * v413);
struct StateT2 * slot_11(struct StateT2 * v568);
struct StateT2 * slot_0(struct StateT2 * v2);
struct StateT2 * slot_12(struct StateT2 * v611) {
  struct StateT * v612 = v611->a;
  int v613 = v612->timer;
  struct StateT * v614 = v611->b;
  int v615 = v614->timer;
  bool v638 = v613 == v615;
  squared_assert(v638);
  squared_assume(v638);
  struct StateT * v618 = v611->a;
  int v619 = v618->timer;
  int v640 = v619 + 1;
  v618->timer = v640;
  struct StateT * v621 = v611->b;
  int v622 = v621->timer;
  int v642 = v622 + 1;
  v621->timer = v642;
  struct StateT * v624 = v611->a;
  int * v625 = v624->regs;
  int v626 = v625[13];
  int * v627 = v624->regs;
  int v647 = v626 + 4;
  v627[13] = v647;
  struct StateT * v629 = v611->b;
  int * v630 = v629->regs;
  int v631 = v630[13];
  int * v632 = v629->regs;
  int v651 = v631 + 4;
  v632[13] = v651;
  struct StateT2 * v634 = slot_13(v611);
  return v634;
}

struct StateT2 * slot_14(struct StateT2 * v128) {
  struct StateT * v129 = v128->a;
  int v130 = v129->timer;
  struct StateT * v131 = v128->b;
  int v132 = v131->timer;
  bool v146 = v130 == v132;
  squared_assert(v146);
  squared_assume(v146);
  struct StateT * v135 = v128->a;
  int v136 = v135->timer;
  int v148 = v136 + 1;
  v135->timer = v148;
  struct StateT * v138 = v128->b;
  int v139 = v138->timer;
  int v150 = v139 + 1;
  v138->timer = v150;
  struct StateT * v141 = v128->a;
  struct StateT * v142 = v128->b;
  return v128;
}

struct StateT2 * slot_6(struct StateT2 * v266) {
  struct StateT * v267 = v266->a;
  int v268 = v267->timer;
  struct StateT * v269 = v266->b;
  int v270 = v269->timer;
  bool v293 = v268 == v270;
  squared_assert(v293);
  squared_assume(v293);
  struct StateT * v273 = v266->a;
  int v274 = v273->timer;
  int v295 = v274 + 1;
  v273->timer = v295;
  struct StateT * v276 = v266->b;
  int v277 = v276->timer;
  int v297 = v277 + 1;
  v276->timer = v297;
  struct StateT * v279 = v266->a;
  int * v280 = v279->regs;
  int v281 = v280[13];
  int * v282 = v279->regs;
  v282[13] = v281;
  struct StateT * v284 = v266->b;
  int * v285 = v284->regs;
  int v286 = v285[13];
  int * v287 = v284->regs;
  v287[13] = v286;
  struct StateT2 * v289 = slot_7(v266);
  return v289;
}

struct StateT2 * slot_16(struct StateT2 * v545) {
  struct StateT * v546 = v545->a;
  int v547 = v546->timer;
  struct StateT * v548 = v545->b;
  int v549 = v548->timer;
  bool v563 = v547 == v549;
  squared_assert(v563);
  squared_assume(v563);
  struct StateT * v552 = v545->a;
  int v553 = v552->timer;
  int v565 = v553 + 1;
  v552->timer = v565;
  struct StateT * v555 = v545->b;
  int v556 = v555->timer;
  int v567 = v556 + 1;
  v555->timer = v567;
  struct StateT * v558 = v545->a;
  struct StateT * v559 = v545->b;
  return v545;
}

struct StateT2 * slot_5(struct StateT2 * v230) {
  struct StateT * v231 = v230->a;
  int v232 = v231->timer;
  struct StateT * v233 = v230->b;
  int v234 = v233->timer;
  bool v253 = v232 == v234;
  squared_assert(v253);
  squared_assume(v253);
  struct StateT * v237 = v230->a;
  int v238 = v237->timer;
  int v255 = v238 + 1;
  v237->timer = v255;
  struct StateT * v240 = v230->b;
  int v241 = v240->timer;
  int v257 = v241 + 1;
  v240->timer = v257;
  struct StateT * v243 = v230->a;
  int * v244 = v243->regs;
  v244[13] = 0;
  struct StateT * v246 = v230->b;
  int * v247 = v246->regs;
  v247[13] = 0;
  struct StateT2 * v249 = slot_6(v230);
  return v249;
}

struct StateT2 * slot_2(struct StateT2 * v82) {
  struct StateT * v83 = v82->a;
  int v84 = v83->timer;
  struct StateT * v85 = v82->b;
  int v86 = v85->timer;
  bool v111 = v84 == v86;
  squared_assert(v111);
  squared_assume(v111);
  struct StateT * v89 = v82->a;
  int v90 = v89->timer;
  int v113 = v90 + 1;
  v89->timer = v113;
  struct StateT * v92 = v82->b;
  int v93 = v92->timer;
  int v115 = v93 + 1;
  v92->timer = v115;
  struct StateT * v95 = v82->a;
  int * v96 = v95->regs;
  int v97 = v96[11];
  struct StateT * v98 = v82->b;
  int * v99 = v98->regs;
  int v100 = v99[11];
  bool v121 = (0 >= v97) == (0 >= v100);
  squared_assert(v121);
  squared_assume(v121);
  bool v122 = 0 >= v97;
  struct StateT2 * v107;
  if (v122) {
    struct StateT2 * v103 = slot_14(v82);
    v107 = v103;
  } else {
    struct StateT2 * v105 = slot_3(v82);
    v107 = v105;
  }
  return v107;
}

struct StateT2 * slot_7(struct StateT2 * v309) {
  struct StateT * v310 = v309->a;
  int v311 = v310->timer;
  struct StateT * v312 = v309->b;
  int v313 = v312->timer;
  bool v340 = v311 == v313;
  squared_assert(v340);
  squared_assume(v340);
  struct StateT * v316 = v309->a;
  int v317 = v316->timer;
  int v342 = v317 + 1;
  v316->timer = v342;
  struct StateT * v319 = v309->b;
  int v320 = v319->timer;
  int v344 = v320 + 1;
  v319->timer = v344;
  struct StateT * v322 = v309->a;
  int * v323 = v322->regs;
  int v324 = v323[12];
  int * v325 = v322->mem;
  int v349 = (int)((unsigned int)v324 >> 2);
  int v326 = v325[v349];
  int * v327 = v322->regs;
  v327[14] = v326;
  struct StateT * v329 = v309->b;
  int * v330 = v329->regs;
  int v331 = v330[12];
  int * v332 = v329->mem;
  int v356 = (int)((unsigned int)v331 >> 2);
  int v333 = v332[v356];
  int * v334 = v329->regs;
  v334[14] = v333;
  struct StateT2 * v336 = slot_8(v309);
  return v336;
}

struct StateT2 * slot_3(struct StateT2 * v151) {
  struct StateT * v152 = v151->a;
  int v153 = v152->timer;
  struct StateT * v154 = v151->b;
  int v155 = v154->timer;
  bool v174 = v153 == v155;
  squared_assert(v174);
  squared_assume(v174);
  struct StateT * v158 = v151->a;
  int v159 = v158->timer;
  int v176 = v159 + 1;
  v158->timer = v176;
  struct StateT * v161 = v151->b;
  int v162 = v161->timer;
  int v178 = v162 + 1;
  v161->timer = v178;
  struct StateT * v164 = v151->a;
  int * v165 = v164->regs;
  v165[12] = 0;
  struct StateT * v167 = v151->b;
  int * v168 = v167->regs;
  v168[12] = 0;
  struct StateT2 * v170 = slot_4(v151);
  return v170;
}

struct StateT2 * snippet(struct StateT2 * v0) {
  struct StateT2 * v1 = slot_0(v0);
  return v1;
}

struct StateT2 * slot_10(struct StateT2 * v502) {
  struct StateT * v503 = v502->a;
  int v504 = v503->timer;
  struct StateT * v505 = v502->b;
  int v506 = v505->timer;
  bool v529 = v504 == v506;
  squared_assert(v529);
  squared_assume(v529);
  struct StateT * v509 = v502->a;
  int v510 = v509->timer;
  int v531 = v510 + 1;
  v509->timer = v531;
  struct StateT * v512 = v502->b;
  int v513 = v512->timer;
  int v533 = v513 + 1;
  v512->timer = v533;
  struct StateT * v515 = v502->a;
  int * v516 = v515->regs;
  int v517 = v516[11];
  int * v518 = v515->regs;
  int v538 = v517 + -1;
  v518[11] = v538;
  struct StateT * v520 = v502->b;
  int * v521 = v520->regs;
  int v522 = v521[11];
  int * v523 = v520->regs;
  int v542 = v522 + -1;
  v523[11] = v542;
  struct StateT2 * v525 = slot_11(v502);
  return v525;
}

struct StateT2 * slot_1(struct StateT2 * v46) {
  struct StateT * v47 = v46->a;
  int v48 = v47->timer;
  struct StateT * v49 = v46->b;
  int v50 = v49->timer;
  bool v69 = v48 == v50;
  squared_assert(v69);
  squared_assume(v69);
  struct StateT * v53 = v46->a;
  int v54 = v53->timer;
  int v71 = v54 + 1;
  v53->timer = v71;
  struct StateT * v56 = v46->b;
  int v57 = v56->timer;
  int v73 = v57 + 1;
  v56->timer = v73;
  struct StateT * v59 = v46->a;
  int * v60 = v59->regs;
  v60[10] = 1;
  struct StateT * v62 = v46->b;
  int * v63 = v62->regs;
  v63[10] = 1;
  struct StateT2 * v65 = slot_2(v46);
  return v65;
}

struct StateT2 * slot_8(struct StateT2 * v361) {
  struct StateT * v362 = v361->a;
  int v363 = v362->timer;
  struct StateT * v364 = v361->b;
  int v365 = v364->timer;
  bool v392 = v363 == v365;
  squared_assert(v392);
  squared_assume(v392);
  struct StateT * v368 = v361->a;
  int v369 = v368->timer;
  int v394 = v369 + 1;
  v368->timer = v394;
  struct StateT * v371 = v361->b;
  int v372 = v371->timer;
  int v396 = v372 + 1;
  v371->timer = v396;
  struct StateT * v374 = v361->a;
  int * v375 = v374->regs;
  int v376 = v375[13];
  int * v377 = v374->mem;
  int v401 = (int)((unsigned int)v376 >> 2);
  int v378 = v377[v401];
  int * v379 = v374->regs;
  v379[15] = v378;
  struct StateT * v381 = v361->b;
  int * v382 = v381->regs;
  int v383 = v382[13];
  int * v384 = v381->mem;
  int v408 = (int)((unsigned int)v383 >> 2);
  int v385 = v384[v408];
  int * v386 = v381->regs;
  v386[15] = v385;
  struct StateT2 * v388 = slot_9(v361);
  return v388;
}

struct StateT2 * slot_4(struct StateT2 * v187) {
  struct StateT * v188 = v187->a;
  int v189 = v188->timer;
  struct StateT * v190 = v187->b;
  int v191 = v190->timer;
  bool v214 = v189 == v191;
  squared_assert(v214);
  squared_assume(v214);
  struct StateT * v194 = v187->a;
  int v195 = v194->timer;
  int v216 = v195 + 1;
  v194->timer = v216;
  struct StateT * v197 = v187->b;
  int v198 = v197->timer;
  int v218 = v198 + 1;
  v197->timer = v218;
  struct StateT * v200 = v187->a;
  int * v201 = v200->regs;
  int v202 = v201[12];
  int * v203 = v200->regs;
  int v223 = v202 + 16;
  v203[12] = v223;
  struct StateT * v205 = v187->b;
  int * v206 = v205->regs;
  int v207 = v206[12];
  int * v208 = v205->regs;
  int v227 = v207 + 16;
  v208[12] = v227;
  struct StateT2 * v210 = slot_5(v187);
  return v210;
}

struct StateT2 * slot_13(struct StateT2 * v654) {
  struct StateT * v655 = v654->a;
  int v656 = v655->timer;
  struct StateT * v657 = v654->b;
  int v658 = v657->timer;
  bool v683 = v656 == v658;
  squared_assert(v683);
  squared_assume(v683);
  struct StateT * v661 = v654->a;
  int v662 = v661->timer;
  int v685 = v662 + 1;
  v661->timer = v685;
  struct StateT * v664 = v654->b;
  int v665 = v664->timer;
  int v687 = v665 + 1;
  v664->timer = v687;
  struct StateT * v667 = v654->a;
  int * v668 = v667->regs;
  int v669 = v668[11];
  struct StateT * v670 = v654->b;
  int * v671 = v670->regs;
  int v672 = v671[11];
  bool v693 = (!(v669 == 0)) == (!(v672 == 0));
  squared_assert(v693);
  squared_assume(v693);
  bool v694 = !(v669 == 0);
  struct StateT2 * v679;
  if (v694) {
    struct StateT2 * v675 = slot_7(v654);
    v679 = v675;
  } else {
    struct StateT2 * v677 = slot_14(v654);
    v679 = v677;
  }
  return v679;
}

struct StateT2 * slot_15(struct StateT2 * v466) {
  struct StateT * v467 = v466->a;
  int v468 = v467->timer;
  struct StateT * v469 = v466->b;
  int v470 = v469->timer;
  bool v489 = v468 == v470;
  squared_assert(v489);
  squared_assume(v489);
  struct StateT * v473 = v466->a;
  int v474 = v473->timer;
  int v491 = v474 + 1;
  v473->timer = v491;
  struct StateT * v476 = v466->b;
  int v477 = v476->timer;
  int v493 = v477 + 1;
  v476->timer = v493;
  struct StateT * v479 = v466->a;
  int * v480 = v479->regs;
  v480[10] = 0;
  struct StateT * v482 = v466->b;
  int * v483 = v482->regs;
  v483[10] = 0;
  struct StateT2 * v485 = slot_16(v466);
  return v485;
}

struct StateT2 * slot_9(struct StateT2 * v413) {
  struct StateT * v414 = v413->a;
  int v415 = v414->timer;
  struct StateT * v416 = v413->b;
  int v417 = v416->timer;
  bool v446 = v415 == v417;
  squared_assert(v446);
  squared_assume(v446);
  struct StateT * v420 = v413->a;
  int v421 = v420->timer;
  int v448 = v421 + 1;
  v420->timer = v448;
  struct StateT * v423 = v413->b;
  int v424 = v423->timer;
  int v450 = v424 + 1;
  v423->timer = v450;
  struct StateT * v426 = v413->a;
  int * v427 = v426->regs;
  int v428 = v427[14];
  int * v429 = v426->regs;
  int v430 = v429[15];
  struct StateT * v431 = v413->b;
  int * v432 = v431->regs;
  int v433 = v432[14];
  int * v434 = v431->regs;
  int v435 = v434[15];
  bool v459 = (!(v428 == v430)) == (!(v433 == v435));
  squared_assert(v459);
  squared_assume(v459);
  bool v460 = !(v428 == v430);
  struct StateT2 * v442;
  if (v460) {
    struct StateT2 * v438 = slot_15(v413);
    v442 = v438;
  } else {
    struct StateT2 * v440 = slot_10(v413);
    v442 = v440;
  }
  return v442;
}

struct StateT2 * slot_11(struct StateT2 * v568) {
  struct StateT * v569 = v568->a;
  int v570 = v569->timer;
  struct StateT * v571 = v568->b;
  int v572 = v571->timer;
  bool v595 = v570 == v572;
  squared_assert(v595);
  squared_assume(v595);
  struct StateT * v575 = v568->a;
  int v576 = v575->timer;
  int v597 = v576 + 1;
  v575->timer = v597;
  struct StateT * v578 = v568->b;
  int v579 = v578->timer;
  int v599 = v579 + 1;
  v578->timer = v599;
  struct StateT * v581 = v568->a;
  int * v582 = v581->regs;
  int v583 = v582[12];
  int * v584 = v581->regs;
  int v604 = v583 + 4;
  v584[12] = v604;
  struct StateT * v586 = v568->b;
  int * v587 = v586->regs;
  int v588 = v587[12];
  int * v589 = v586->regs;
  int v608 = v588 + 4;
  v589[12] = v608;
  struct StateT2 * v591 = slot_12(v568);
  return v591;
}

struct StateT2 * slot_0(struct StateT2 * v2) {
  struct StateT * v3 = v2->a;
  int v4 = v3->timer;
  struct StateT * v5 = v2->b;
  int v6 = v5->timer;
  bool v29 = v4 == v6;
  squared_assert(v29);
  squared_assume(v29);
  struct StateT * v9 = v2->a;
  int v10 = v9->timer;
  int v31 = v10 + 1;
  v9->timer = v31;
  struct StateT * v12 = v2->b;
  int v13 = v12->timer;
  int v33 = v13 + 1;
  v12->timer = v33;
  struct StateT * v15 = v2->a;
  int * v16 = v15->regs;
  int v17 = v16[10];
  int * v18 = v15->regs;
  v18[11] = v17;
  struct StateT * v20 = v2->b;
  int * v21 = v20->regs;
  int v22 = v21[10];
  int * v23 = v20->regs;
  v23[11] = v22;
  struct StateT2 * v25 = slot_1(v2);
  return v25;
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
}

void squared_assert(bool c) { koika_assert(c, "squared drift"); }
void squared_assume(bool c) { koika_assume(c); }

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
  struct StateT2 p = { .a = &s1, .b = &s2 };
  struct StateT2 *p_ = snippet(&p);
  koika_assert(p_->a->timer==p_->b->timer, "timing leak");
  return 0;
}