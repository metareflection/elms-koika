// verify: leak (CBMC should report VERIFICATION FAILED) [unwind 65]
#define NUM_REGS 32
#define MEM_SIZE 64
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
  int mem[64];
  int saved_regs[32];
  int cache_keys[10];
  int cache_vals[10];
  int timer;
};

struct StateT * slot_14(struct StateT * v589);
struct StateT * slot_16(struct StateT * v625);
struct StateT * slot_17(struct StateT * v723);
struct StateT * slot_2(struct StateT * v211);
struct StateT * slot_3(struct StateT * v223);
struct StateT * snippet(struct StateT * v0);
struct StateT * slot_1(struct StateT * v106);
struct StateT * slot_4(struct StateT * v243);
struct StateT * slot_13(struct StateT * v573);
struct StateT * slot_15(struct StateT * v605);
struct StateT * slot_0(struct StateT * v2);
struct StateT * slot_14(struct StateT * v589) {
  int v590 = v589->timer;
  int v598 = v590 + 1;
  v589->timer = v598;
  int * v592 = v589->regs;
  int v593 = v592[10];
  int * v594 = v589->regs;
  int v602 = v593 << 2;
  v594[10] = v602;
  struct StateT * v596 = slot_15(v589);
  return v596;
}

struct StateT * slot_16(struct StateT * v625) {
  int v626 = v625->timer;
  int v680 = v626 + 1;
  v625->timer = v680;
  int * v628 = v625->regs;
  int v629 = v628[10];
  int * v630 = v625->regs;
  int v631 = v630[12];
  int * v632 = v625->cache_keys;
  int v633 = v632[0];
  bool v687 = v633 == ((int)((unsigned int)v629 >> 2));
  int v677;
  if (v687) {
    int * v634 = v625->cache_vals;
    v634[0] = v631;
    v677 = v631;
  } else {
    int * v637 = v625->cache_keys;
    int v638 = v637[1];
    bool v692 = v638 == ((int)((unsigned int)v629 >> 2));
    int v675;
    if (v692) {
      int * v639 = v625->cache_keys;
      int * v640 = v625->cache_keys;
      int v641 = v640[0];
      v639[1] = v641;
      int * v643 = v625->cache_vals;
      int * v644 = v625->cache_vals;
      int v645 = v644[0];
      v643[1] = v645;
      int * v647 = v625->cache_keys;
      int v700 = (int)((unsigned int)v629 >> 2);
      v647[0] = v700;
      int * v649 = v625->cache_vals;
      v649[0] = v631;
      int v651 = v625->timer;
      int v703 = v651 + 1;
      v625->timer = v703;
      v675 = v631;
    } else {
      int * v654 = v625->mem;
      int * v655 = v625->cache_keys;
      int v656 = v655[1];
      int * v657 = v625->cache_vals;
      int v658 = v657[1];
      v654[v656] = v658;
      int * v660 = v625->cache_keys;
      int * v661 = v625->cache_keys;
      int v662 = v661[0];
      v660[1] = v662;
      int * v664 = v625->cache_vals;
      int * v665 = v625->cache_vals;
      int v666 = v665[0];
      v664[1] = v666;
      int * v668 = v625->cache_keys;
      int v716 = (int)((unsigned int)v629 >> 2);
      v668[0] = v716;
      int * v670 = v625->cache_vals;
      v670[0] = v631;
      int v672 = v625->timer;
      int v719 = v672 + 100;
      v625->timer = v719;
      v675 = v631;
    }
    v677 = v675;
  }
  struct StateT * v678 = slot_17(v625);
  return v678;
}

struct StateT * slot_17(struct StateT * v723) {
  int v724 = v723->timer;
  int v727 = v724 + 1;
  v723->timer = v727;
  return v723;
}

struct StateT * slot_2(struct StateT * v211) {
  int v212 = v211->timer;
  int v218 = v212 + 1;
  v211->timer = v218;
  int * v214 = v211->regs;
  v214[15] = 15;
  struct StateT * v216 = slot_3(v211);
  return v216;
}

struct StateT * slot_3(struct StateT * v223) {
  int v224 = v223->timer;
  int v234 = v224 + 1;
  v223->timer = v234;
  int * v226 = v223->regs;
  int v227 = v226[12];
  int * v228 = v223->regs;
  int v229 = v228[14];
  int * v230 = v223->regs;
  int v240 = v227 ^ v229;
  v230[12] = v240;
  struct StateT * v232 = slot_4(v223);
  return v232;
}

struct StateT * snippet(struct StateT * v0) {
  struct StateT * v1 = slot_0(v0);
  return v1;
}

struct StateT * slot_1(struct StateT * v106) {
  int v107 = v106->timer;
  int v165 = v107 + 1;
  v106->timer = v165;
  int * v109 = v106->regs;
  int v110 = v109[11];
  int * v111 = v106->cache_keys;
  int v112 = v111[0];
  bool v170 = v112 == ((int)((unsigned int)(v110 + 12) >> 2));
  int v160;
  if (v170) {
    int * v113 = v106->cache_vals;
    int v114 = v113[0];
    v160 = v114;
  } else {
    int * v116 = v106->cache_keys;
    int v117 = v116[1];
    bool v175 = v117 == ((int)((unsigned int)(v110 + 12) >> 2));
    int v158;
    if (v175) {
      int * v118 = v106->cache_vals;
      int v119 = v118[1];
      int * v120 = v106->cache_keys;
      int * v121 = v106->cache_keys;
      int v122 = v121[0];
      v120[1] = v122;
      int * v124 = v106->cache_vals;
      int * v125 = v106->cache_vals;
      int v126 = v125[0];
      v124[1] = v126;
      int * v128 = v106->cache_keys;
      int v184 = (int)((unsigned int)(v110 + 12) >> 2);
      v128[0] = v184;
      int * v130 = v106->cache_vals;
      v130[0] = v119;
      int v132 = v106->timer;
      int v187 = v132 + 1;
      v106->timer = v187;
      v158 = v119;
    } else {
      int * v135 = v106->mem;
      int v189 = (int)((unsigned int)(v110 + 12) >> 2);
      int v136 = v135[v189];
      int * v137 = v106->mem;
      int * v138 = v106->cache_keys;
      int v139 = v138[1];
      int * v140 = v106->cache_vals;
      int v141 = v140[1];
      v137[v139] = v141;
      int * v143 = v106->cache_keys;
      int * v144 = v106->cache_keys;
      int v145 = v144[0];
      v143[1] = v145;
      int * v147 = v106->cache_vals;
      int * v148 = v106->cache_vals;
      int v149 = v148[0];
      v147[1] = v149;
      int * v151 = v106->cache_keys;
      v151[0] = v189;
      int * v153 = v106->cache_vals;
      v153[0] = v136;
      int v155 = v106->timer;
      int v204 = v155 + 100;
      v106->timer = v204;
      v158 = v136;
    }
    v160 = v158;
  }
  int * v161 = v106->regs;
  v161[14] = v160;
  struct StateT * v163 = slot_2(v106);
  return v163;
}

struct StateT * slot_4(struct StateT * v243) {
  int * v244 = v243->saved_regs;
  int * v245 = v243->regs;
  int v246 = v245[14];
  v244[14] = v246;
  int v248 = v243->timer;
  int v437 = v248 + 1;
  v243->timer = v437;
  int * v250 = v243->regs;
  int v251 = v250[10];
  int * v252 = v243->regs;
  int v441 = v251 << 2;
  v252[14] = v441;
  int v254 = v243->timer;
  int v442 = v254 + 1;
  v243->timer = v442;
  int * v256 = v243->regs;
  int v257 = v256[11];
  int * v258 = v243->regs;
  int v259 = v258[14];
  int * v260 = v243->regs;
  int v447 = v257 + v259;
  v260[14] = v447;
  int v262 = v243->timer;
  int v448 = v262 + 1;
  v243->timer = v448;
  int * v264 = v243->regs;
  int v265 = v264[14];
  int * v266 = v243->cache_keys;
  int v267 = v266[0];
  bool v452 = v267 == ((int)((unsigned int)v265 >> 2));
  int v315;
  if (v452) {
    int * v268 = v243->cache_vals;
    int v269 = v268[0];
    v315 = v269;
  } else {
    int * v271 = v243->cache_keys;
    int v272 = v271[1];
    bool v457 = v272 == ((int)((unsigned int)v265 >> 2));
    int v313;
    if (v457) {
      int * v273 = v243->cache_vals;
      int v274 = v273[1];
      int * v275 = v243->cache_keys;
      int * v276 = v243->cache_keys;
      int v277 = v276[0];
      v275[1] = v277;
      int * v279 = v243->cache_vals;
      int * v280 = v243->cache_vals;
      int v281 = v280[0];
      v279[1] = v281;
      int * v283 = v243->cache_keys;
      int v466 = (int)((unsigned int)v265 >> 2);
      v283[0] = v466;
      int * v285 = v243->cache_vals;
      v285[0] = v274;
      int v287 = v243->timer;
      int v469 = v287 + 1;
      v243->timer = v469;
      v313 = v274;
    } else {
      int * v290 = v243->mem;
      int v471 = (int)((unsigned int)v265 >> 2);
      int v291 = v290[v471];
      int * v292 = v243->mem;
      int * v293 = v243->cache_keys;
      int v294 = v293[1];
      int * v295 = v243->cache_vals;
      int v296 = v295[1];
      v292[v294] = v296;
      int * v298 = v243->cache_keys;
      int * v299 = v243->cache_keys;
      int v300 = v299[0];
      v298[1] = v300;
      int * v302 = v243->cache_vals;
      int * v303 = v243->cache_vals;
      int v304 = v303[0];
      v302[1] = v304;
      int * v306 = v243->cache_keys;
      v306[0] = v471;
      int * v308 = v243->cache_vals;
      v308[0] = v291;
      int v310 = v243->timer;
      int v486 = v310 + 100;
      v243->timer = v486;
      v313 = v291;
    }
    v315 = v313;
  }
  int * v316 = v243->regs;
  v316[14] = v315;
  int v318 = v243->timer;
  int v490 = v318 + 1;
  v243->timer = v490;
  int * v320 = v243->regs;
  int v321 = v320[14];
  int * v322 = v243->regs;
  int v493 = v321 & 15;
  v322[14] = v493;
  int v324 = v243->timer;
  int v494 = v324 + 1;
  v243->timer = v494;
  int * v326 = v243->regs;
  int v327 = v326[14];
  int * v328 = v243->regs;
  int v497 = v327 << 2;
  v328[14] = v497;
  int * v330 = v243->saved_regs;
  int * v331 = v243->regs;
  int v332 = v331[11];
  v330[11] = v332;
  int v334 = v243->timer;
  int v501 = v334 + 1;
  v243->timer = v501;
  int * v336 = v243->regs;
  int v337 = v336[11];
  int * v338 = v243->regs;
  int v339 = v338[14];
  int * v340 = v243->regs;
  int v505 = v337 + v339;
  v340[11] = v505;
  int v342 = v243->timer;
  int v506 = v342 + 1;
  v243->timer = v506;
  int * v344 = v243->regs;
  int v345 = v344[11];
  int * v346 = v243->cache_keys;
  int v347 = v346[0];
  bool v509 = v347 == ((int)((unsigned int)v345 >> 2));
  int v395;
  if (v509) {
    int * v348 = v243->cache_vals;
    int v349 = v348[0];
    v395 = v349;
  } else {
    int * v351 = v243->cache_keys;
    int v352 = v351[1];
    bool v514 = v352 == ((int)((unsigned int)v345 >> 2));
    int v393;
    if (v514) {
      int * v353 = v243->cache_vals;
      int v354 = v353[1];
      int * v355 = v243->cache_keys;
      int * v356 = v243->cache_keys;
      int v357 = v356[0];
      v355[1] = v357;
      int * v359 = v243->cache_vals;
      int * v360 = v243->cache_vals;
      int v361 = v360[0];
      v359[1] = v361;
      int * v363 = v243->cache_keys;
      int v523 = (int)((unsigned int)v345 >> 2);
      v363[0] = v523;
      int * v365 = v243->cache_vals;
      v365[0] = v354;
      int v367 = v243->timer;
      int v526 = v367 + 1;
      v243->timer = v526;
      v393 = v354;
    } else {
      int * v370 = v243->mem;
      int v528 = (int)((unsigned int)v345 >> 2);
      int v371 = v370[v528];
      int * v372 = v243->mem;
      int * v373 = v243->cache_keys;
      int v374 = v373[1];
      int * v375 = v243->cache_vals;
      int v376 = v375[1];
      v372[v374] = v376;
      int * v378 = v243->cache_keys;
      int * v379 = v243->cache_keys;
      int v380 = v379[0];
      v378[1] = v380;
      int * v382 = v243->cache_vals;
      int * v383 = v243->cache_vals;
      int v384 = v383[0];
      v382[1] = v384;
      int * v386 = v243->cache_keys;
      v386[0] = v528;
      int * v388 = v243->cache_vals;
      v388[0] = v371;
      int v390 = v243->timer;
      int v543 = v390 + 100;
      v243->timer = v543;
      v393 = v371;
    }
    v395 = v393;
  }
  int * v396 = v243->regs;
  v396[11] = v395;
  int * v398 = v243->saved_regs;
  int * v399 = v243->regs;
  int v400 = v399[12];
  v398[12] = v400;
  int v402 = v243->timer;
  int v551 = v402 + 1;
  v243->timer = v551;
  int * v404 = v243->regs;
  int v405 = v404[12];
  int * v406 = v243->regs;
  int v407 = v406[11];
  int * v408 = v243->regs;
  int v555 = v405 + v407;
  v408[12] = v555;
  int * v410 = v243->regs;
  int v411 = v410[15];
  int * v412 = v243->regs;
  int v413 = v412[10];
  bool v559 = (v411 ^ -2147483648) < (v413 ^ -2147483648);
  if (v559) {
    int v414 = v243->timer;
    int v560 = v414 + 15;
    v243->timer = v560;
    int * v416 = v243->saved_regs;
    int v417 = v416[14];
    int * v418 = v243->regs;
    v418[14] = v417;
    int * v420 = v243->saved_regs;
    int v421 = v420[11];
    int * v422 = v243->regs;
    v422[11] = v421;
    int * v424 = v243->saved_regs;
    int v425 = v424[12];
    int * v426 = v243->regs;
    v426[12] = v425;
    struct StateT * v428 = slot_13(v243);
    ;
  } else {
    ;
  }
  return v243;
}

struct StateT * slot_13(struct StateT * v573) {
  int v574 = v573->timer;
  int v582 = v574 + 1;
  v573->timer = v582;
  int * v576 = v573->regs;
  int v577 = v576[10];
  int * v578 = v573->regs;
  int v586 = v577 & 7;
  v578[10] = v586;
  struct StateT * v580 = slot_14(v573);
  return v580;
}

struct StateT * slot_15(struct StateT * v605) {
  int v606 = v605->timer;
  int v616 = v606 + 1;
  v605->timer = v616;
  int * v608 = v605->regs;
  int v609 = v608[13];
  int * v610 = v605->regs;
  int v611 = v610[10];
  int * v612 = v605->regs;
  int v622 = v609 + v611;
  v612[10] = v622;
  struct StateT * v614 = slot_16(v605);
  return v614;
}

struct StateT * slot_0(struct StateT * v2) {
  int v3 = v2->timer;
  int v61 = v3 + 1;
  v2->timer = v61;
  int * v5 = v2->regs;
  int v6 = v5[12];
  int * v7 = v2->cache_keys;
  int v8 = v7[0];
  bool v66 = v8 == ((int)((unsigned int)v6 >> 2));
  int v56;
  if (v66) {
    int * v9 = v2->cache_vals;
    int v10 = v9[0];
    v56 = v10;
  } else {
    int * v12 = v2->cache_keys;
    int v13 = v12[1];
    bool v71 = v13 == ((int)((unsigned int)v6 >> 2));
    int v54;
    if (v71) {
      int * v14 = v2->cache_vals;
      int v15 = v14[1];
      int * v16 = v2->cache_keys;
      int * v17 = v2->cache_keys;
      int v18 = v17[0];
      v16[1] = v18;
      int * v20 = v2->cache_vals;
      int * v21 = v2->cache_vals;
      int v22 = v21[0];
      v20[1] = v22;
      int * v24 = v2->cache_keys;
      int v80 = (int)((unsigned int)v6 >> 2);
      v24[0] = v80;
      int * v26 = v2->cache_vals;
      v26[0] = v15;
      int v28 = v2->timer;
      int v83 = v28 + 1;
      v2->timer = v83;
      v54 = v15;
    } else {
      int * v31 = v2->mem;
      int v85 = (int)((unsigned int)v6 >> 2);
      int v32 = v31[v85];
      int * v33 = v2->mem;
      int * v34 = v2->cache_keys;
      int v35 = v34[1];
      int * v36 = v2->cache_vals;
      int v37 = v36[1];
      v33[v35] = v37;
      int * v39 = v2->cache_keys;
      int * v40 = v2->cache_keys;
      int v41 = v40[0];
      v39[1] = v41;
      int * v43 = v2->cache_vals;
      int * v44 = v2->cache_vals;
      int v45 = v44[0];
      v43[1] = v45;
      int * v47 = v2->cache_keys;
      v47[0] = v85;
      int * v49 = v2->cache_vals;
      v49[0] = v32;
      int v51 = v2->timer;
      int v100 = v51 + 100;
      v2->timer = v100;
      v54 = v32;
    }
    v56 = v54;
  }
  int * v57 = v2->regs;
  v57[12] = v56;
  struct StateT * v59 = slot_1(v2);
  return v59;
}



/*****************************************
End of C Generated Code
*******************************************/

void init(struct StateT *s) {
  for (int i=0; i<NUM_REGS; i++) {
    s->regs[i] = 0;
    s->saved_regs[i] = 0;
  }
  s->regs[2] = 4 * MEM_SIZE;
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
  
  // a10, public: one draw, written into both states
  int a10 = bounded(0, 23);
  s1.regs[10] = a10;
  s2.regs[10] = a10;
  // a11, 16 words read by the callee: the address is public
  s1.regs[11] = 0;
  s2.regs[11] = 0;
  // its contents, public: the same draw in both states
  for (int i=0; i<16; i++) {
    int v = bounded(0, 20);
    s1.mem[0 + i] = v;
    s2.mem[0 + i] = v;
  }
  // a12, 8 words read by the callee: the address is public
  s1.regs[12] = 64;
  s2.regs[12] = 64;
  // a13, 8 words written by the callee: the address is public
  s1.regs[13] = 96;
  s2.regs[13] = 96;
  
  // a12's contents, secret: a different draw in each state
  for (int i=0; i<8; i++) {
    s1.mem[16 + i] = bounded(0, 20);
    s2.mem[16 + i] = bounded(0, 20);
  }
  struct StateT *s1_ = snippet(&s1);
  struct StateT *s2_ = snippet(&s2);
  koika_assert(s1_->timer==s2_->timer, "timing leak");
  return 0;
}