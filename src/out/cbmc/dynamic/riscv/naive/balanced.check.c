// verify: clean (CBMC should report VERIFICATION SUCCESSFUL) [unwind 65]
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

struct StateT2 * slot_12(struct StateT2 * v301);
struct StateT2 * slot_14(struct StateT2 * v397);
struct StateT2 * slot_6(struct StateT2 * v196);
struct StateT2 * slot_16(struct StateT2 * v425);
struct StateT2 * slot_5(struct StateT2 * v439);
struct StateT2 * slot_2(struct StateT2 * v90);
struct StateT2 * slot_7(struct StateT2 * v360);
struct StateT2 * slot_3(struct StateT2 * v126);
struct StateT2 * snippet(struct StateT2 * v0);
struct StateT2 * slot_10(struct StateT2 * v255);
struct StateT2 * slot_1(struct StateT2 * v38);
struct StateT2 * slot_4(struct StateT2 * v324);
struct StateT2 * slot_13(struct StateT2 * v383);
struct StateT2 * slot_15(struct StateT2 * v411);
struct StateT2 * slot_9(struct StateT2 * v232);
struct StateT2 * slot_11(struct StateT2 * v278);
struct StateT2 * slot_0(struct StateT2 * v2);
struct StateT2 * slot_12(struct StateT2 * v301) {
  struct StateT * v302 = v301->b;
  int v303 = v302->timer;
  bool v315 = v303 == v303;
  squared_assert(v315);
  squared_assume(v315);
  struct StateT * v306 = v301->b;
  int v307 = v306->timer;
  int v317 = v307 + 1;
  v306->timer = v317;
  struct StateT * v309 = v301->b;
  int * v310 = v309->regs;
  v310[18] = 2;
  struct StateT2 * v312 = slot_16(v301);
  return v312;
}

struct StateT2 * slot_14(struct StateT2 * v397) {
  struct StateT * v398 = v397->b;
  int v399 = v398->timer;
  bool v408 = v399 == v399;
  squared_assert(v408);
  squared_assume(v408);
  struct StateT * v402 = v397->b;
  int v403 = v402->timer;
  int v410 = v403 + 1;
  v402->timer = v410;
  struct StateT * v405 = v397->b;
  return v397;
}

struct StateT2 * slot_6(struct StateT2 * v196) {
  struct StateT * v197 = v196->a;
  int v198 = v197->timer;
  struct StateT * v199 = v196->b;
  int v200 = v199->timer;
  bool v219 = v198 == v200;
  squared_assert(v219);
  squared_assume(v219);
  struct StateT * v203 = v196->a;
  int v204 = v203->timer;
  int v221 = v204 + 1;
  v203->timer = v221;
  struct StateT * v206 = v196->b;
  int v207 = v206->timer;
  int v223 = v207 + 1;
  v206->timer = v223;
  struct StateT * v209 = v196->a;
  int * v210 = v209->regs;
  v210[18] = 2;
  struct StateT * v212 = v196->b;
  int * v213 = v212->regs;
  v213[18] = 2;
  struct StateT2 * v215 = slot_7(v196);
  return v215;
}

struct StateT2 * slot_16(struct StateT2 * v425) {
  struct StateT * v426 = v425->b;
  int v427 = v426->timer;
  bool v436 = v427 == v427;
  squared_assert(v436);
  squared_assume(v436);
  struct StateT * v430 = v425->b;
  int v431 = v430->timer;
  int v438 = v431 + 1;
  v430->timer = v438;
  struct StateT * v433 = v425->b;
  return v425;
}

struct StateT2 * slot_5(struct StateT2 * v439) {
  struct StateT * v440 = v439->a;
  int v441 = v440->timer;
  struct StateT * v442 = v439->b;
  int v443 = v442->timer;
  bool v457 = v441 == v443;
  squared_assert(v457);
  squared_assume(v457);
  struct StateT * v446 = v439->a;
  int v447 = v446->timer;
  int v459 = v447 + 1;
  v446->timer = v459;
  struct StateT * v449 = v439->b;
  int v450 = v449->timer;
  int v461 = v450 + 1;
  v449->timer = v461;
  struct StateT * v452 = v439->a;
  struct StateT * v453 = v439->b;
  return v439;
}

struct StateT2 * slot_2(struct StateT2 * v90) {
  struct StateT * v91 = v90->a;
  int v92 = v91->timer;
  struct StateT * v93 = v90->b;
  int v94 = v93->timer;
  bool v113 = v92 == v94;
  squared_assert(v113);
  squared_assume(v113);
  struct StateT * v97 = v90->a;
  int v98 = v97->timer;
  int v115 = v98 + 1;
  v97->timer = v115;
  struct StateT * v100 = v90->b;
  int v101 = v100->timer;
  int v117 = v101 + 1;
  v100->timer = v117;
  struct StateT * v103 = v90->a;
  int * v104 = v103->regs;
  v104[17] = 10;
  struct StateT * v106 = v90->b;
  int * v107 = v106->regs;
  v107[17] = 10;
  struct StateT2 * v109 = slot_3(v90);
  return v109;
}

struct StateT2 * slot_7(struct StateT2 * v360) {
  struct StateT * v361 = v360->a;
  int v362 = v361->timer;
  struct StateT * v363 = v360->b;
  int v364 = v363->timer;
  bool v378 = v362 == v364;
  squared_assert(v378);
  squared_assume(v378);
  struct StateT * v367 = v360->a;
  int v368 = v367->timer;
  int v380 = v368 + 1;
  v367->timer = v380;
  struct StateT * v370 = v360->b;
  int v371 = v370->timer;
  int v382 = v371 + 1;
  v370->timer = v382;
  struct StateT * v373 = v360->a;
  struct StateT * v374 = v360->b;
  return v360;
}

struct StateT2 * slot_3(struct StateT2 * v126) {
  struct StateT * v127 = v126->a;
  int v128 = v127->timer;
  struct StateT * v129 = v126->b;
  int v130 = v129->timer;
  bool v167 = v128 == v130;
  squared_assert(v167);
  squared_assume(v167);
  struct StateT * v133 = v126->a;
  int v134 = v133->timer;
  int v169 = v134 + 1;
  v133->timer = v169;
  struct StateT * v136 = v126->b;
  int v137 = v136->timer;
  int v171 = v137 + 1;
  v136->timer = v171;
  struct StateT * v139 = v126->a;
  int * v140 = v139->regs;
  int v141 = v140[16];
  int * v142 = v139->regs;
  int v143 = v142[17];
  struct StateT * v144 = v126->b;
  int * v145 = v144->regs;
  int v146 = v145[16];
  int * v147 = v144->regs;
  int v148 = v147[17];
  bool v180 = v141 < v143;
  struct StateT2 * v163;
  if (v180) {
    bool v181 = v146 < v148;
    struct StateT2 * v154;
    if (v181) {
      struct StateT2 * v149 = slot_6(v126);
      v154 = v149;
    } else {
      struct StateT2 * v151 = slot_9(v126);
      struct StateT2 * v152 = slot_10(v126);
      v154 = v152;
    }
    v163 = v154;
  } else {
    bool v188 = v146 < v148;
    struct StateT2 * v161;
    if (v188) {
      struct StateT2 * v156 = slot_11(v126);
      struct StateT2 * v157 = slot_12(v126);
      v161 = v157;
    } else {
      struct StateT2 * v159 = slot_4(v126);
      v161 = v159;
    }
    v163 = v161;
  }
  return v163;
}

struct StateT2 * snippet(struct StateT2 * v0) {
  struct StateT2 * v1 = slot_0(v0);
  return v1;
}

struct StateT2 * slot_10(struct StateT2 * v255) {
  struct StateT * v256 = v255->b;
  int v257 = v256->timer;
  bool v269 = v257 == v257;
  squared_assert(v269);
  squared_assume(v269);
  struct StateT * v260 = v255->b;
  int v261 = v260->timer;
  int v271 = v261 + 1;
  v260->timer = v271;
  struct StateT * v263 = v255->b;
  int * v264 = v263->regs;
  v264[18] = 1;
  struct StateT2 * v266 = slot_14(v255);
  return v266;
}

struct StateT2 * slot_1(struct StateT2 * v38) {
  struct StateT * v39 = v38->a;
  int v40 = v39->timer;
  struct StateT * v41 = v38->b;
  int v42 = v41->timer;
  bool v69 = v40 == v42;
  squared_assert(v69);
  squared_assume(v69);
  struct StateT * v45 = v38->a;
  int v46 = v45->timer;
  int v71 = v46 + 1;
  v45->timer = v71;
  struct StateT * v48 = v38->b;
  int v49 = v48->timer;
  int v73 = v49 + 1;
  v48->timer = v73;
  struct StateT * v51 = v38->a;
  int * v52 = v51->regs;
  int v53 = v52[12];
  int * v54 = v51->mem;
  int v78 = (int)((unsigned int)v53 >> 2);
  int v55 = v54[v78];
  int * v56 = v51->regs;
  v56[16] = v55;
  struct StateT * v58 = v38->b;
  int * v59 = v58->regs;
  int v60 = v59[12];
  int * v61 = v58->mem;
  int v85 = (int)((unsigned int)v60 >> 2);
  int v62 = v61[v85];
  int * v63 = v58->regs;
  v63[16] = v62;
  struct StateT2 * v65 = slot_2(v38);
  return v65;
}

struct StateT2 * slot_4(struct StateT2 * v324) {
  struct StateT * v325 = v324->a;
  int v326 = v325->timer;
  struct StateT * v327 = v324->b;
  int v328 = v327->timer;
  bool v347 = v326 == v328;
  squared_assert(v347);
  squared_assume(v347);
  struct StateT * v331 = v324->a;
  int v332 = v331->timer;
  int v349 = v332 + 1;
  v331->timer = v349;
  struct StateT * v334 = v324->b;
  int v335 = v334->timer;
  int v351 = v335 + 1;
  v334->timer = v351;
  struct StateT * v337 = v324->a;
  int * v338 = v337->regs;
  v338[18] = 1;
  struct StateT * v340 = v324->b;
  int * v341 = v340->regs;
  v341[18] = 1;
  struct StateT2 * v343 = slot_5(v324);
  return v343;
}

struct StateT2 * slot_13(struct StateT2 * v383) {
  struct StateT * v384 = v383->a;
  int v385 = v384->timer;
  bool v394 = v385 == v385;
  squared_assert(v394);
  squared_assume(v394);
  struct StateT * v388 = v383->a;
  int v389 = v388->timer;
  int v396 = v389 + 1;
  v388->timer = v396;
  struct StateT * v391 = v383->a;
  return v383;
}

struct StateT2 * slot_15(struct StateT2 * v411) {
  struct StateT * v412 = v411->a;
  int v413 = v412->timer;
  bool v422 = v413 == v413;
  squared_assert(v422);
  squared_assume(v422);
  struct StateT * v416 = v411->a;
  int v417 = v416->timer;
  int v424 = v417 + 1;
  v416->timer = v424;
  struct StateT * v419 = v411->a;
  return v411;
}

struct StateT2 * slot_9(struct StateT2 * v232) {
  struct StateT * v233 = v232->a;
  int v234 = v233->timer;
  bool v246 = v234 == v234;
  squared_assert(v246);
  squared_assume(v246);
  struct StateT * v237 = v232->a;
  int v238 = v237->timer;
  int v248 = v238 + 1;
  v237->timer = v248;
  struct StateT * v240 = v232->a;
  int * v241 = v240->regs;
  v241[18] = 2;
  struct StateT2 * v243 = slot_13(v232);
  return v243;
}

struct StateT2 * slot_11(struct StateT2 * v278) {
  struct StateT * v279 = v278->a;
  int v280 = v279->timer;
  bool v292 = v280 == v280;
  squared_assert(v292);
  squared_assume(v292);
  struct StateT * v283 = v278->a;
  int v284 = v283->timer;
  int v294 = v284 + 1;
  v283->timer = v294;
  struct StateT * v286 = v278->a;
  int * v287 = v286->regs;
  v287[18] = 1;
  struct StateT2 * v289 = slot_15(v278);
  return v289;
}

struct StateT2 * slot_0(struct StateT2 * v2) {
  struct StateT * v3 = v2->a;
  int v4 = v3->timer;
  struct StateT * v5 = v2->b;
  int v6 = v5->timer;
  bool v25 = v4 == v6;
  squared_assert(v25);
  squared_assume(v25);
  struct StateT * v9 = v2->a;
  int v10 = v9->timer;
  int v27 = v10 + 1;
  v9->timer = v27;
  struct StateT * v12 = v2->b;
  int v13 = v12->timer;
  int v29 = v13 + 1;
  v12->timer = v29;
  struct StateT * v15 = v2->a;
  int * v16 = v15->regs;
  v16[12] = 80;
  struct StateT * v18 = v2->b;
  int * v19 = v18->regs;
  v19[12] = 80;
  struct StateT2 * v21 = slot_1(v2);
  return v21;
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
  
  int x = bounded(0, 80);
  s1.regs[10] = x;
  s2.regs[10] = x;
  
  // initialize secret
  for (int i=0; i<SECRET_SIZE; i++) {
    s1.mem[SECRET_OFFSET+i] = bounded(0, 20);
    s2.mem[SECRET_OFFSET+i] = bounded(0, 20);
  }
  struct StateT2 p = { .a = &s1, .b = &s2 };
  struct StateT2 *p_ = snippet(&p);
  koika_assert(p_->a->timer==p_->b->timer, "timing leak");
  return 0;
}