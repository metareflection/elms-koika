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
void squared_diverged(bool);

struct StateT2 * slot_12(struct StateT2 * v579);
struct StateT2 * slot_14(struct StateT2 * v124);
struct StateT2 * slot_6(struct StateT2 * v258);
struct StateT2 * slot_5(struct StateT2 * v222);
struct StateT2 * slot_2(struct StateT2 * v78);
struct StateT2 * slot_7(struct StateT2 * v297);
struct StateT2 * slot_3(struct StateT2 * v147);
struct StateT2 * snippet(struct StateT2 * v0);
struct StateT2 * slot_10(struct StateT2 * v478);
struct StateT2 * slot_1(struct StateT2 * v42);
struct StateT2 * slot_8(struct StateT2 * v345);
struct StateT2 * slot_4(struct StateT2 * v183);
struct StateT2 * slot_13(struct StateT2 * v618);
struct StateT2 * slot_15(struct StateT2 * v442);
struct StateT2 * slot_9(struct StateT2 * v393);
struct StateT2 * slot_11(struct StateT2 * v540);
struct StateT2 * slot_0(struct StateT2 * v2);
struct StateT2 * slot_12(struct StateT2 * v579) {
  struct StateT * v580 = v579->a;
  int v581 = v580->timer;
  struct StateT * v582 = v579->b;
  int v583 = v582->timer;
  bool v604 = v581 == v583;
  squared_assert(v604);
  squared_assume(v604);
  struct StateT * v586 = v579->a;
  int v587 = v586->timer;
  int v606 = v587 + 1;
  v586->timer = v606;
  struct StateT * v589 = v579->b;
  int v590 = v589->timer;
  int v608 = v590 + 1;
  v589->timer = v608;
  struct StateT * v592 = v579->a;
  int * v593 = v592->regs;
  int v594 = v593[13];
  int v612 = v594 + 4;
  v593[13] = v612;
  struct StateT * v596 = v579->b;
  int * v597 = v596->regs;
  int v598 = v597[13];
  int v615 = v598 + 4;
  v597[13] = v615;
  struct StateT2 * v600 = slot_13(v579);
  return v600;
}

struct StateT2 * slot_14(struct StateT2 * v124) {
  struct StateT * v125 = v124->a;
  int v126 = v125->timer;
  struct StateT * v127 = v124->b;
  int v128 = v127->timer;
  bool v142 = v126 == v128;
  squared_assert(v142);
  squared_assume(v142);
  struct StateT * v131 = v124->a;
  int v132 = v131->timer;
  int v144 = v132 + 1;
  v131->timer = v144;
  struct StateT * v134 = v124->b;
  int v135 = v134->timer;
  int v146 = v135 + 1;
  v134->timer = v146;
  return v124;
}

struct StateT2 * slot_6(struct StateT2 * v258) {
  struct StateT * v259 = v258->a;
  int v260 = v259->timer;
  struct StateT * v261 = v258->b;
  int v262 = v261->timer;
  bool v283 = v260 == v262;
  squared_assert(v283);
  squared_assume(v283);
  struct StateT * v265 = v258->a;
  int v266 = v265->timer;
  int v285 = v266 + 1;
  v265->timer = v285;
  struct StateT * v268 = v258->b;
  int v269 = v268->timer;
  int v287 = v269 + 1;
  v268->timer = v287;
  struct StateT * v271 = v258->a;
  int * v272 = v271->regs;
  int v273 = v272[13];
  v272[13] = v273;
  struct StateT * v275 = v258->b;
  int * v276 = v275->regs;
  int v277 = v276[13];
  v276[13] = v277;
  struct StateT2 * v279 = slot_7(v258);
  return v279;
}

struct StateT2 * slot_5(struct StateT2 * v222) {
  struct StateT * v223 = v222->a;
  int v224 = v223->timer;
  struct StateT * v225 = v222->b;
  int v226 = v225->timer;
  bool v245 = v224 == v226;
  squared_assert(v245);
  squared_assume(v245);
  struct StateT * v229 = v222->a;
  int v230 = v229->timer;
  int v247 = v230 + 1;
  v229->timer = v247;
  struct StateT * v232 = v222->b;
  int v233 = v232->timer;
  int v249 = v233 + 1;
  v232->timer = v249;
  struct StateT * v235 = v222->a;
  int * v236 = v235->regs;
  v236[13] = 0;
  struct StateT * v238 = v222->b;
  int * v239 = v238->regs;
  v239[13] = 0;
  struct StateT2 * v241 = slot_6(v222);
  return v241;
}

struct StateT2 * slot_2(struct StateT2 * v78) {
  struct StateT * v79 = v78->a;
  int v80 = v79->timer;
  struct StateT * v81 = v78->b;
  int v82 = v81->timer;
  bool v107 = v80 == v82;
  squared_assert(v107);
  squared_assume(v107);
  struct StateT * v85 = v78->a;
  int v86 = v85->timer;
  int v109 = v86 + 1;
  v85->timer = v109;
  struct StateT * v88 = v78->b;
  int v89 = v88->timer;
  int v111 = v89 + 1;
  v88->timer = v111;
  struct StateT * v91 = v78->a;
  int * v92 = v91->regs;
  int v93 = v92[11];
  struct StateT * v94 = v78->b;
  int * v95 = v94->regs;
  int v96 = v95[11];
  bool v117 = (0 >= v93) == (0 >= v96);
  squared_diverged(v117);
  squared_assume(v117);
  bool v118 = 0 >= v93;
  struct StateT2 * v103;
  if (v118) {
    struct StateT2 * v99 = slot_14(v78);
    v103 = v99;
  } else {
    struct StateT2 * v101 = slot_3(v78);
    v103 = v101;
  }
  return v103;
}

struct StateT2 * slot_7(struct StateT2 * v297) {
  struct StateT * v298 = v297->a;
  int v299 = v298->timer;
  struct StateT * v300 = v297->b;
  int v301 = v300->timer;
  bool v326 = v299 == v301;
  squared_assert(v326);
  squared_assume(v326);
  struct StateT * v304 = v297->a;
  int v305 = v304->timer;
  int v328 = v305 + 1;
  v304->timer = v328;
  struct StateT * v307 = v297->b;
  int v308 = v307->timer;
  int v330 = v308 + 1;
  v307->timer = v330;
  struct StateT * v310 = v297->a;
  int * v311 = v310->regs;
  int v312 = v311[12];
  int * v313 = v310->mem;
  int v335 = (int)((unsigned int)v312 >> 2);
  int v314 = v313[v335];
  v311[14] = v314;
  struct StateT * v316 = v297->b;
  int * v317 = v316->regs;
  int v318 = v317[12];
  int * v319 = v316->mem;
  int v341 = (int)((unsigned int)v318 >> 2);
  int v320 = v319[v341];
  v317[14] = v320;
  struct StateT2 * v322 = slot_8(v297);
  return v322;
}

struct StateT2 * slot_3(struct StateT2 * v147) {
  struct StateT * v148 = v147->a;
  int v149 = v148->timer;
  struct StateT * v150 = v147->b;
  int v151 = v150->timer;
  bool v170 = v149 == v151;
  squared_assert(v170);
  squared_assume(v170);
  struct StateT * v154 = v147->a;
  int v155 = v154->timer;
  int v172 = v155 + 1;
  v154->timer = v172;
  struct StateT * v157 = v147->b;
  int v158 = v157->timer;
  int v174 = v158 + 1;
  v157->timer = v174;
  struct StateT * v160 = v147->a;
  int * v161 = v160->regs;
  v161[12] = 0;
  struct StateT * v163 = v147->b;
  int * v164 = v163->regs;
  v164[12] = 0;
  struct StateT2 * v166 = slot_4(v147);
  return v166;
}

struct StateT2 * snippet(struct StateT2 * v0) {
  struct StateT2 * v1 = slot_0(v0);
  return v1;
}

struct StateT2 * slot_10(struct StateT2 * v478) {
  struct StateT * v479 = v478->a;
  int v480 = v479->timer;
  struct StateT * v481 = v478->b;
  int v482 = v481->timer;
  bool v503 = v480 == v482;
  squared_assert(v503);
  squared_assume(v503);
  struct StateT * v485 = v478->a;
  int v486 = v485->timer;
  int v505 = v486 + 1;
  v485->timer = v505;
  struct StateT * v488 = v478->b;
  int v489 = v488->timer;
  int v507 = v489 + 1;
  v488->timer = v507;
  struct StateT * v491 = v478->a;
  int * v492 = v491->regs;
  int v493 = v492[11];
  int v511 = v493 + -1;
  v492[11] = v511;
  struct StateT * v495 = v478->b;
  int * v496 = v495->regs;
  int v497 = v496[11];
  int v514 = v497 + -1;
  v496[11] = v514;
  struct StateT2 * v499 = slot_11(v478);
  return v499;
}

struct StateT2 * slot_1(struct StateT2 * v42) {
  struct StateT * v43 = v42->a;
  int v44 = v43->timer;
  struct StateT * v45 = v42->b;
  int v46 = v45->timer;
  bool v65 = v44 == v46;
  squared_assert(v65);
  squared_assume(v65);
  struct StateT * v49 = v42->a;
  int v50 = v49->timer;
  int v67 = v50 + 1;
  v49->timer = v67;
  struct StateT * v52 = v42->b;
  int v53 = v52->timer;
  int v69 = v53 + 1;
  v52->timer = v69;
  struct StateT * v55 = v42->a;
  int * v56 = v55->regs;
  v56[10] = 1;
  struct StateT * v58 = v42->b;
  int * v59 = v58->regs;
  v59[10] = 1;
  struct StateT2 * v61 = slot_2(v42);
  return v61;
}

struct StateT2 * slot_8(struct StateT2 * v345) {
  struct StateT * v346 = v345->a;
  int v347 = v346->timer;
  struct StateT * v348 = v345->b;
  int v349 = v348->timer;
  bool v374 = v347 == v349;
  squared_assert(v374);
  squared_assume(v374);
  struct StateT * v352 = v345->a;
  int v353 = v352->timer;
  int v376 = v353 + 1;
  v352->timer = v376;
  struct StateT * v355 = v345->b;
  int v356 = v355->timer;
  int v378 = v356 + 1;
  v355->timer = v378;
  struct StateT * v358 = v345->a;
  int * v359 = v358->regs;
  int v360 = v359[13];
  int * v361 = v358->mem;
  int v383 = (int)((unsigned int)v360 >> 2);
  int v362 = v361[v383];
  v359[15] = v362;
  struct StateT * v364 = v345->b;
  int * v365 = v364->regs;
  int v366 = v365[13];
  int * v367 = v364->mem;
  int v389 = (int)((unsigned int)v366 >> 2);
  int v368 = v367[v389];
  v365[15] = v368;
  struct StateT2 * v370 = slot_9(v345);
  return v370;
}

struct StateT2 * slot_4(struct StateT2 * v183) {
  struct StateT * v184 = v183->a;
  int v185 = v184->timer;
  struct StateT * v186 = v183->b;
  int v187 = v186->timer;
  bool v208 = v185 == v187;
  squared_assert(v208);
  squared_assume(v208);
  struct StateT * v190 = v183->a;
  int v191 = v190->timer;
  int v210 = v191 + 1;
  v190->timer = v210;
  struct StateT * v193 = v183->b;
  int v194 = v193->timer;
  int v212 = v194 + 1;
  v193->timer = v212;
  struct StateT * v196 = v183->a;
  int * v197 = v196->regs;
  int v198 = v197[12];
  int v216 = v198 + 16;
  v197[12] = v216;
  struct StateT * v200 = v183->b;
  int * v201 = v200->regs;
  int v202 = v201[12];
  int v219 = v202 + 16;
  v201[12] = v219;
  struct StateT2 * v204 = slot_5(v183);
  return v204;
}

struct StateT2 * slot_13(struct StateT2 * v618) {
  struct StateT * v619 = v618->a;
  int v620 = v619->timer;
  struct StateT * v621 = v618->b;
  int v622 = v621->timer;
  bool v647 = v620 == v622;
  squared_assert(v647);
  squared_assume(v647);
  struct StateT * v625 = v618->a;
  int v626 = v625->timer;
  int v649 = v626 + 1;
  v625->timer = v649;
  struct StateT * v628 = v618->b;
  int v629 = v628->timer;
  int v651 = v629 + 1;
  v628->timer = v651;
  struct StateT * v631 = v618->a;
  int * v632 = v631->regs;
  int v633 = v632[11];
  struct StateT * v634 = v618->b;
  int * v635 = v634->regs;
  int v636 = v635[11];
  bool v657 = (!(v633 == 0)) == (!(v636 == 0));
  squared_diverged(v657);
  squared_assume(v657);
  bool v658 = !(v633 == 0);
  struct StateT2 * v643;
  if (v658) {
    struct StateT2 * v639 = slot_7(v618);
    v643 = v639;
  } else {
    struct StateT2 * v641 = slot_14(v618);
    v643 = v641;
  }
  return v643;
}

struct StateT2 * slot_15(struct StateT2 * v442) {
  struct StateT * v443 = v442->a;
  int v444 = v443->timer;
  struct StateT * v445 = v442->b;
  int v446 = v445->timer;
  bool v465 = v444 == v446;
  squared_assert(v465);
  squared_assume(v465);
  struct StateT * v449 = v442->a;
  int v450 = v449->timer;
  int v467 = v450 + 1;
  v449->timer = v467;
  struct StateT * v452 = v442->b;
  int v453 = v452->timer;
  int v469 = v453 + 1;
  v452->timer = v469;
  struct StateT * v455 = v442->a;
  int * v456 = v455->regs;
  v456[10] = 0;
  struct StateT * v458 = v442->b;
  int * v459 = v458->regs;
  v459[10] = 0;
  struct StateT2 * v461 = slot_14(v442);
  return v461;
}

struct StateT2 * slot_9(struct StateT2 * v393) {
  struct StateT * v394 = v393->a;
  int v395 = v394->timer;
  struct StateT * v396 = v393->b;
  int v397 = v396->timer;
  bool v424 = v395 == v397;
  squared_assert(v424);
  squared_assume(v424);
  struct StateT * v400 = v393->a;
  int v401 = v400->timer;
  int v426 = v401 + 1;
  v400->timer = v426;
  struct StateT * v403 = v393->b;
  int v404 = v403->timer;
  int v428 = v404 + 1;
  v403->timer = v428;
  struct StateT * v406 = v393->a;
  int * v407 = v406->regs;
  int v408 = v407[14];
  int v409 = v407[15];
  struct StateT * v410 = v393->b;
  int * v411 = v410->regs;
  int v412 = v411[14];
  int v413 = v411[15];
  bool v435 = (!(v408 == v409)) == (!(v412 == v413));
  squared_diverged(v435);
  squared_assume(v435);
  bool v436 = !(v408 == v409);
  struct StateT2 * v420;
  if (v436) {
    struct StateT2 * v416 = slot_15(v393);
    v420 = v416;
  } else {
    struct StateT2 * v418 = slot_10(v393);
    v420 = v418;
  }
  return v420;
}

struct StateT2 * slot_11(struct StateT2 * v540) {
  struct StateT * v541 = v540->a;
  int v542 = v541->timer;
  struct StateT * v543 = v540->b;
  int v544 = v543->timer;
  bool v565 = v542 == v544;
  squared_assert(v565);
  squared_assume(v565);
  struct StateT * v547 = v540->a;
  int v548 = v547->timer;
  int v567 = v548 + 1;
  v547->timer = v567;
  struct StateT * v550 = v540->b;
  int v551 = v550->timer;
  int v569 = v551 + 1;
  v550->timer = v569;
  struct StateT * v553 = v540->a;
  int * v554 = v553->regs;
  int v555 = v554[12];
  int v573 = v555 + 4;
  v554[12] = v573;
  struct StateT * v557 = v540->b;
  int * v558 = v557->regs;
  int v559 = v558[12];
  int v576 = v559 + 4;
  v558[12] = v576;
  struct StateT2 * v561 = slot_12(v540);
  return v561;
}

struct StateT2 * slot_0(struct StateT2 * v2) {
  struct StateT * v3 = v2->a;
  int v4 = v3->timer;
  struct StateT * v5 = v2->b;
  int v6 = v5->timer;
  bool v27 = v4 == v6;
  squared_assert(v27);
  squared_assume(v27);
  struct StateT * v9 = v2->a;
  int v10 = v9->timer;
  int v29 = v10 + 1;
  v9->timer = v29;
  struct StateT * v12 = v2->b;
  int v13 = v12->timer;
  int v31 = v13 + 1;
  v12->timer = v31;
  struct StateT * v15 = v2->a;
  int * v16 = v15->regs;
  int v17 = v16[10];
  v16[11] = v17;
  struct StateT * v19 = v2->b;
  int * v20 = v19->regs;
  int v21 = v20[10];
  v20[11] = v21;
  struct StateT2 * v23 = slot_1(v2);
  return v23;
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

void squared_assert(bool c) { koika_assert(c, "timer drift"); }
void squared_diverged(bool c) { koika_assert(c, "control flow diverged"); }
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
    s1.mem[0 + i] = secret(0, 20);
    s2.mem[0 + i] = secret(0, 20);
  }
  struct StateT2 p = { .a = &s1, .b = &s2 };
  struct StateT2 *p_ = snippet(&p);
  koika_assert(p_->a->timer==p_->b->timer, "timing leak");
  return 0;
}