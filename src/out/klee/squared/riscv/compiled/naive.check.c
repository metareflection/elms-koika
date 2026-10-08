// verify: leak (KLEE should report a failing assertion) [budget 1200s]
#define NUM_REGS 32
#define MEM_SIZE 64
#define SECRET_SIZE 10
#define SECRET_OFFSET 20
#define CACHE_ENTRIES 12
#define CACHE_WORDS 24

#ifdef KLEE
#include <assert.h>
#include <klee/klee.h>
#define koika_assert(b, s) klee_assert(b)
#define koika_assume(b) klee_assume(b)
#define koika_draw(x) klee_make_symbolic(&(x), sizeof(x), #x)
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

struct StateT2 * slot_12(struct StateT2 * v575);
struct StateT2 * slot_14(struct StateT2 * v124);
struct StateT2 * slot_6(struct StateT2 * v256);
struct StateT2 * slot_5(struct StateT2 * v220);
struct StateT2 * slot_2(struct StateT2 * v78);
struct StateT2 * slot_7(struct StateT2 * v295);
struct StateT2 * slot_3(struct StateT2 * v145);
struct StateT2 * snippet(struct StateT2 * v0);
struct StateT2 * slot_10(struct StateT2 * v476);
struct StateT2 * slot_1(struct StateT2 * v42);
struct StateT2 * slot_8(struct StateT2 * v343);
struct StateT2 * slot_4(struct StateT2 * v181);
struct StateT2 * slot_13(struct StateT2 * v614);
struct StateT2 * slot_15(struct StateT2 * v440);
struct StateT2 * slot_9(struct StateT2 * v391);
struct StateT2 * slot_11(struct StateT2 * v536);
struct StateT2 * slot_0(struct StateT2 * v2);
struct StateT2 * slot_12(struct StateT2 * v575) {
  struct StateT * v576 = v575->a;
  int v577 = v576->timer;
  struct StateT * v578 = v575->b;
  int v579 = v578->timer;
  bool v600 = v577 == v579;
  squared_assert(v600);
  squared_assume(v600);
  struct StateT * v582 = v575->a;
  int v583 = v582->timer;
  int v602 = v583 + 1;
  v582->timer = v602;
  struct StateT * v585 = v575->b;
  int v586 = v585->timer;
  int v604 = v586 + 1;
  v585->timer = v604;
  struct StateT * v588 = v575->a;
  int * v589 = v588->regs;
  int v590 = v589[13];
  int v608 = v590 + 4;
  v589[13] = v608;
  struct StateT * v592 = v575->b;
  int * v593 = v592->regs;
  int v594 = v593[13];
  int v611 = v594 + 4;
  v593[13] = v611;
  struct StateT2 * v596 = slot_13(v575);
  return v596;
}

struct StateT2 * slot_14(struct StateT2 * v124) {
  struct StateT * v125 = v124->a;
  int v126 = v125->timer;
  struct StateT * v127 = v124->b;
  int v128 = v127->timer;
  bool v140 = v126 == v128;
  squared_assert(v140);
  squared_assume(v140);
  struct StateT * v131 = v124->a;
  int v132 = v131->timer;
  int v142 = v132 + 1;
  v131->timer = v142;
  struct StateT * v134 = v124->b;
  int v135 = v134->timer;
  int v144 = v135 + 1;
  v134->timer = v144;
  return v124;
}

struct StateT2 * slot_6(struct StateT2 * v256) {
  struct StateT * v257 = v256->a;
  int v258 = v257->timer;
  struct StateT * v259 = v256->b;
  int v260 = v259->timer;
  bool v281 = v258 == v260;
  squared_assert(v281);
  squared_assume(v281);
  struct StateT * v263 = v256->a;
  int v264 = v263->timer;
  int v283 = v264 + 1;
  v263->timer = v283;
  struct StateT * v266 = v256->b;
  int v267 = v266->timer;
  int v285 = v267 + 1;
  v266->timer = v285;
  struct StateT * v269 = v256->a;
  int * v270 = v269->regs;
  int v271 = v270[13];
  v270[13] = v271;
  struct StateT * v273 = v256->b;
  int * v274 = v273->regs;
  int v275 = v274[13];
  v274[13] = v275;
  struct StateT2 * v277 = slot_7(v256);
  return v277;
}

struct StateT2 * slot_5(struct StateT2 * v220) {
  struct StateT * v221 = v220->a;
  int v222 = v221->timer;
  struct StateT * v223 = v220->b;
  int v224 = v223->timer;
  bool v243 = v222 == v224;
  squared_assert(v243);
  squared_assume(v243);
  struct StateT * v227 = v220->a;
  int v228 = v227->timer;
  int v245 = v228 + 1;
  v227->timer = v245;
  struct StateT * v230 = v220->b;
  int v231 = v230->timer;
  int v247 = v231 + 1;
  v230->timer = v247;
  struct StateT * v233 = v220->a;
  int * v234 = v233->regs;
  v234[13] = 0;
  struct StateT * v236 = v220->b;
  int * v237 = v236->regs;
  v237[13] = 0;
  struct StateT2 * v239 = slot_6(v220);
  return v239;
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

struct StateT2 * slot_7(struct StateT2 * v295) {
  struct StateT * v296 = v295->a;
  int v297 = v296->timer;
  struct StateT * v298 = v295->b;
  int v299 = v298->timer;
  bool v324 = v297 == v299;
  squared_assert(v324);
  squared_assume(v324);
  struct StateT * v302 = v295->a;
  int v303 = v302->timer;
  int v326 = v303 + 1;
  v302->timer = v326;
  struct StateT * v305 = v295->b;
  int v306 = v305->timer;
  int v328 = v306 + 1;
  v305->timer = v328;
  struct StateT * v308 = v295->a;
  int * v309 = v308->regs;
  int v310 = v309[12];
  int * v311 = v308->mem;
  int v333 = (int)((unsigned int)v310 >> 2);
  int v312 = v311[v333];
  v309[14] = v312;
  struct StateT * v314 = v295->b;
  int * v315 = v314->regs;
  int v316 = v315[12];
  int * v317 = v314->mem;
  int v339 = (int)((unsigned int)v316 >> 2);
  int v318 = v317[v339];
  v315[14] = v318;
  struct StateT2 * v320 = slot_8(v295);
  return v320;
}

struct StateT2 * slot_3(struct StateT2 * v145) {
  struct StateT * v146 = v145->a;
  int v147 = v146->timer;
  struct StateT * v148 = v145->b;
  int v149 = v148->timer;
  bool v168 = v147 == v149;
  squared_assert(v168);
  squared_assume(v168);
  struct StateT * v152 = v145->a;
  int v153 = v152->timer;
  int v170 = v153 + 1;
  v152->timer = v170;
  struct StateT * v155 = v145->b;
  int v156 = v155->timer;
  int v172 = v156 + 1;
  v155->timer = v172;
  struct StateT * v158 = v145->a;
  int * v159 = v158->regs;
  v159[12] = 0;
  struct StateT * v161 = v145->b;
  int * v162 = v161->regs;
  v162[12] = 0;
  struct StateT2 * v164 = slot_4(v145);
  return v164;
}

struct StateT2 * snippet(struct StateT2 * v0) {
  struct StateT2 * v1 = slot_0(v0);
  return v1;
}

struct StateT2 * slot_10(struct StateT2 * v476) {
  struct StateT * v477 = v476->a;
  int v478 = v477->timer;
  struct StateT * v479 = v476->b;
  int v480 = v479->timer;
  bool v501 = v478 == v480;
  squared_assert(v501);
  squared_assume(v501);
  struct StateT * v483 = v476->a;
  int v484 = v483->timer;
  int v503 = v484 + 1;
  v483->timer = v503;
  struct StateT * v486 = v476->b;
  int v487 = v486->timer;
  int v505 = v487 + 1;
  v486->timer = v505;
  struct StateT * v489 = v476->a;
  int * v490 = v489->regs;
  int v491 = v490[11];
  int v509 = v491 + -1;
  v490[11] = v509;
  struct StateT * v493 = v476->b;
  int * v494 = v493->regs;
  int v495 = v494[11];
  int v512 = v495 + -1;
  v494[11] = v512;
  struct StateT2 * v497 = slot_11(v476);
  return v497;
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

struct StateT2 * slot_8(struct StateT2 * v343) {
  struct StateT * v344 = v343->a;
  int v345 = v344->timer;
  struct StateT * v346 = v343->b;
  int v347 = v346->timer;
  bool v372 = v345 == v347;
  squared_assert(v372);
  squared_assume(v372);
  struct StateT * v350 = v343->a;
  int v351 = v350->timer;
  int v374 = v351 + 1;
  v350->timer = v374;
  struct StateT * v353 = v343->b;
  int v354 = v353->timer;
  int v376 = v354 + 1;
  v353->timer = v376;
  struct StateT * v356 = v343->a;
  int * v357 = v356->regs;
  int v358 = v357[13];
  int * v359 = v356->mem;
  int v381 = (int)((unsigned int)v358 >> 2);
  int v360 = v359[v381];
  v357[15] = v360;
  struct StateT * v362 = v343->b;
  int * v363 = v362->regs;
  int v364 = v363[13];
  int * v365 = v362->mem;
  int v387 = (int)((unsigned int)v364 >> 2);
  int v366 = v365[v387];
  v363[15] = v366;
  struct StateT2 * v368 = slot_9(v343);
  return v368;
}

struct StateT2 * slot_4(struct StateT2 * v181) {
  struct StateT * v182 = v181->a;
  int v183 = v182->timer;
  struct StateT * v184 = v181->b;
  int v185 = v184->timer;
  bool v206 = v183 == v185;
  squared_assert(v206);
  squared_assume(v206);
  struct StateT * v188 = v181->a;
  int v189 = v188->timer;
  int v208 = v189 + 1;
  v188->timer = v208;
  struct StateT * v191 = v181->b;
  int v192 = v191->timer;
  int v210 = v192 + 1;
  v191->timer = v210;
  struct StateT * v194 = v181->a;
  int * v195 = v194->regs;
  int v196 = v195[12];
  int v214 = v196 + 16;
  v195[12] = v214;
  struct StateT * v198 = v181->b;
  int * v199 = v198->regs;
  int v200 = v199[12];
  int v217 = v200 + 16;
  v199[12] = v217;
  struct StateT2 * v202 = slot_5(v181);
  return v202;
}

struct StateT2 * slot_13(struct StateT2 * v614) {
  struct StateT * v615 = v614->a;
  int v616 = v615->timer;
  struct StateT * v617 = v614->b;
  int v618 = v617->timer;
  bool v643 = v616 == v618;
  squared_assert(v643);
  squared_assume(v643);
  struct StateT * v621 = v614->a;
  int v622 = v621->timer;
  int v645 = v622 + 1;
  v621->timer = v645;
  struct StateT * v624 = v614->b;
  int v625 = v624->timer;
  int v647 = v625 + 1;
  v624->timer = v647;
  struct StateT * v627 = v614->a;
  int * v628 = v627->regs;
  int v629 = v628[11];
  struct StateT * v630 = v614->b;
  int * v631 = v630->regs;
  int v632 = v631[11];
  bool v653 = (!(v629 == 0)) == (!(v632 == 0));
  squared_diverged(v653);
  squared_assume(v653);
  bool v654 = !(v629 == 0);
  struct StateT2 * v639;
  if (v654) {
    struct StateT2 * v635 = slot_7(v614);
    v639 = v635;
  } else {
    struct StateT2 * v637 = slot_14(v614);
    v639 = v637;
  }
  return v639;
}

struct StateT2 * slot_15(struct StateT2 * v440) {
  struct StateT * v441 = v440->a;
  int v442 = v441->timer;
  struct StateT * v443 = v440->b;
  int v444 = v443->timer;
  bool v463 = v442 == v444;
  squared_assert(v463);
  squared_assume(v463);
  struct StateT * v447 = v440->a;
  int v448 = v447->timer;
  int v465 = v448 + 1;
  v447->timer = v465;
  struct StateT * v450 = v440->b;
  int v451 = v450->timer;
  int v467 = v451 + 1;
  v450->timer = v467;
  struct StateT * v453 = v440->a;
  int * v454 = v453->regs;
  v454[10] = 0;
  struct StateT * v456 = v440->b;
  int * v457 = v456->regs;
  v457[10] = 0;
  struct StateT2 * v459 = slot_14(v440);
  return v459;
}

struct StateT2 * slot_9(struct StateT2 * v391) {
  struct StateT * v392 = v391->a;
  int v393 = v392->timer;
  struct StateT * v394 = v391->b;
  int v395 = v394->timer;
  bool v422 = v393 == v395;
  squared_assert(v422);
  squared_assume(v422);
  struct StateT * v398 = v391->a;
  int v399 = v398->timer;
  int v424 = v399 + 1;
  v398->timer = v424;
  struct StateT * v401 = v391->b;
  int v402 = v401->timer;
  int v426 = v402 + 1;
  v401->timer = v426;
  struct StateT * v404 = v391->a;
  int * v405 = v404->regs;
  int v406 = v405[14];
  int v407 = v405[15];
  struct StateT * v408 = v391->b;
  int * v409 = v408->regs;
  int v410 = v409[14];
  int v411 = v409[15];
  bool v433 = (!(v406 == v407)) == (!(v410 == v411));
  squared_diverged(v433);
  squared_assume(v433);
  bool v434 = !(v406 == v407);
  struct StateT2 * v418;
  if (v434) {
    struct StateT2 * v414 = slot_15(v391);
    v418 = v414;
  } else {
    struct StateT2 * v416 = slot_10(v391);
    v418 = v416;
  }
  return v418;
}

struct StateT2 * slot_11(struct StateT2 * v536) {
  struct StateT * v537 = v536->a;
  int v538 = v537->timer;
  struct StateT * v539 = v536->b;
  int v540 = v539->timer;
  bool v561 = v538 == v540;
  squared_assert(v561);
  squared_assume(v561);
  struct StateT * v543 = v536->a;
  int v544 = v543->timer;
  int v563 = v544 + 1;
  v543->timer = v563;
  struct StateT * v546 = v536->b;
  int v547 = v546->timer;
  int v565 = v547 + 1;
  v546->timer = v565;
  struct StateT * v549 = v536->a;
  int * v550 = v549->regs;
  int v551 = v550[12];
  int v569 = v551 + 4;
  v550[12] = v569;
  struct StateT * v553 = v536->b;
  int * v554 = v553->regs;
  int v555 = v554[12];
  int v572 = v555 + 4;
  v554[12] = v572;
  struct StateT2 * v557 = slot_12(v536);
  return v557;
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
  //@ assert untainted_timer: !\tainted(p_->a->timer==p_->b->timer);
  koika_assert(p_->a->timer==p_->b->timer, "timing leak");
  return 0;
}