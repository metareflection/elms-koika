// verify: clean (CBMC should report VERIFICATION SUCCESSFUL) [unwind 65]
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

struct StateT * slot_12(struct StateT * v719);
struct StateT * slot_14(struct StateT * v300);
struct StateT * slot_6(struct StateT * v316);
struct StateT * slot_16(struct StateT * v460);
struct StateT * slot_5(struct StateT * v283);
struct StateT * slot_17(struct StateT * v574);
struct StateT * slot_2(struct StateT * v211);
struct StateT * slot_7(struct StateT * v356);
struct StateT * slot_3(struct StateT * v223);
struct StateT * snippet(struct StateT * v0);
struct StateT * slot_10(struct StateT * v595);
struct StateT * slot_1(struct StateT * v106);
struct StateT * slot_8(struct StateT * v558);
struct StateT * slot_4(struct StateT * v243);
struct StateT * slot_13(struct StateT * v267);
struct StateT * slot_15(struct StateT * v336);
struct StateT * slot_9(struct StateT * v579);
struct StateT * slot_11(struct StateT * v615);
struct StateT * slot_0(struct StateT * v2);
struct StateT * slot_12(struct StateT * v719) {
  int v720 = v719->timer;
  int v730 = v720 + 1;
  v719->timer = v730;
  int * v722 = v719->regs;
  int v723 = v722[12];
  int * v724 = v719->regs;
  int v725 = v724[11];
  int * v726 = v719->regs;
  int v736 = v723 + v725;
  v726[12] = v736;
  struct StateT * v728 = slot_13(v719);
  return v728;
}

struct StateT * slot_14(struct StateT * v300) {
  int v301 = v300->timer;
  int v309 = v301 + 1;
  v300->timer = v309;
  int * v303 = v300->regs;
  int v304 = v303[10];
  int * v305 = v300->regs;
  int v313 = v304 << 2;
  v305[10] = v313;
  struct StateT * v307 = slot_15(v300);
  return v307;
}

struct StateT * slot_6(struct StateT * v316) {
  int v317 = v316->timer;
  int v327 = v317 + 1;
  v316->timer = v327;
  int * v319 = v316->regs;
  int v320 = v319[11];
  int * v321 = v316->regs;
  int v322 = v321[14];
  int * v323 = v316->regs;
  int v333 = v320 + v322;
  v323[14] = v333;
  struct StateT * v325 = slot_7(v316);
  return v325;
}

struct StateT * slot_16(struct StateT * v460) {
  int v461 = v460->timer;
  int v515 = v461 + 1;
  v460->timer = v515;
  int * v463 = v460->regs;
  int v464 = v463[10];
  int * v465 = v460->regs;
  int v466 = v465[12];
  int * v467 = v460->cache_keys;
  int v468 = v467[0];
  bool v522 = v468 == ((int)((unsigned int)v464 >> 2));
  int v512;
  if (v522) {
    int * v469 = v460->cache_vals;
    v469[0] = v466;
    v512 = v466;
  } else {
    int * v472 = v460->cache_keys;
    int v473 = v472[1];
    bool v527 = v473 == ((int)((unsigned int)v464 >> 2));
    int v510;
    if (v527) {
      int * v474 = v460->cache_keys;
      int * v475 = v460->cache_keys;
      int v476 = v475[0];
      v474[1] = v476;
      int * v478 = v460->cache_vals;
      int * v479 = v460->cache_vals;
      int v480 = v479[0];
      v478[1] = v480;
      int * v482 = v460->cache_keys;
      int v535 = (int)((unsigned int)v464 >> 2);
      v482[0] = v535;
      int * v484 = v460->cache_vals;
      v484[0] = v466;
      int v486 = v460->timer;
      int v538 = v486 + 1;
      v460->timer = v538;
      v510 = v466;
    } else {
      int * v489 = v460->mem;
      int * v490 = v460->cache_keys;
      int v491 = v490[1];
      int * v492 = v460->cache_vals;
      int v493 = v492[1];
      v489[v491] = v493;
      int * v495 = v460->cache_keys;
      int * v496 = v460->cache_keys;
      int v497 = v496[0];
      v495[1] = v497;
      int * v499 = v460->cache_vals;
      int * v500 = v460->cache_vals;
      int v501 = v500[0];
      v499[1] = v501;
      int * v503 = v460->cache_keys;
      int v551 = (int)((unsigned int)v464 >> 2);
      v503[0] = v551;
      int * v505 = v460->cache_vals;
      v505[0] = v466;
      int v507 = v460->timer;
      int v554 = v507 + 100;
      v460->timer = v554;
      v510 = v466;
    }
    v512 = v510;
  }
  struct StateT * v513 = slot_17(v460);
  return v513;
}

struct StateT * slot_5(struct StateT * v283) {
  int v284 = v283->timer;
  int v292 = v284 + 1;
  v283->timer = v292;
  int * v286 = v283->regs;
  int v287 = v286[10];
  int * v288 = v283->regs;
  int v297 = v287 << 2;
  v288[14] = v297;
  struct StateT * v290 = slot_6(v283);
  return v290;
}

struct StateT * slot_17(struct StateT * v574) {
  int v575 = v574->timer;
  int v578 = v575 + 1;
  v574->timer = v578;
  return v574;
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

struct StateT * slot_7(struct StateT * v356) {
  int v357 = v356->timer;
  int v415 = v357 + 1;
  v356->timer = v415;
  int * v359 = v356->regs;
  int v360 = v359[14];
  int * v361 = v356->cache_keys;
  int v362 = v361[0];
  bool v420 = v362 == ((int)((unsigned int)v360 >> 2));
  int v410;
  if (v420) {
    int * v363 = v356->cache_vals;
    int v364 = v363[0];
    v410 = v364;
  } else {
    int * v366 = v356->cache_keys;
    int v367 = v366[1];
    bool v425 = v367 == ((int)((unsigned int)v360 >> 2));
    int v408;
    if (v425) {
      int * v368 = v356->cache_vals;
      int v369 = v368[1];
      int * v370 = v356->cache_keys;
      int * v371 = v356->cache_keys;
      int v372 = v371[0];
      v370[1] = v372;
      int * v374 = v356->cache_vals;
      int * v375 = v356->cache_vals;
      int v376 = v375[0];
      v374[1] = v376;
      int * v378 = v356->cache_keys;
      int v434 = (int)((unsigned int)v360 >> 2);
      v378[0] = v434;
      int * v380 = v356->cache_vals;
      v380[0] = v369;
      int v382 = v356->timer;
      int v437 = v382 + 1;
      v356->timer = v437;
      v408 = v369;
    } else {
      int * v385 = v356->mem;
      int v439 = (int)((unsigned int)v360 >> 2);
      int v386 = v385[v439];
      int * v387 = v356->mem;
      int * v388 = v356->cache_keys;
      int v389 = v388[1];
      int * v390 = v356->cache_vals;
      int v391 = v390[1];
      v387[v389] = v391;
      int * v393 = v356->cache_keys;
      int * v394 = v356->cache_keys;
      int v395 = v394[0];
      v393[1] = v395;
      int * v397 = v356->cache_vals;
      int * v398 = v356->cache_vals;
      int v399 = v398[0];
      v397[1] = v399;
      int * v401 = v356->cache_keys;
      v401[0] = v439;
      int * v403 = v356->cache_vals;
      v403[0] = v386;
      int v405 = v356->timer;
      int v454 = v405 + 100;
      v356->timer = v454;
      v408 = v386;
    }
    v410 = v408;
  }
  int * v411 = v356->regs;
  v411[14] = v410;
  struct StateT * v413 = slot_8(v356);
  return v413;
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

struct StateT * slot_10(struct StateT * v595) {
  int v596 = v595->timer;
  int v606 = v596 + 1;
  v595->timer = v606;
  int * v598 = v595->regs;
  int v599 = v598[11];
  int * v600 = v595->regs;
  int v601 = v600[14];
  int * v602 = v595->regs;
  int v612 = v599 + v601;
  v602[11] = v612;
  struct StateT * v604 = slot_11(v595);
  return v604;
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

struct StateT * slot_8(struct StateT * v558) {
  int v559 = v558->timer;
  int v567 = v559 + 1;
  v558->timer = v567;
  int * v561 = v558->regs;
  int v562 = v561[14];
  int * v563 = v558->regs;
  int v571 = v562 & 15;
  v563[14] = v571;
  struct StateT * v565 = slot_9(v558);
  return v565;
}

struct StateT * slot_4(struct StateT * v243) {
  int v244 = v243->timer;
  int v256 = v244 + 1;
  v243->timer = v256;
  int * v246 = v243->regs;
  int v247 = v246[15];
  int * v248 = v243->regs;
  int v249 = v248[10];
  bool v261 = (v247 ^ -2147483648) < (v249 ^ -2147483648);
  struct StateT * v254;
  if (v261) {
    struct StateT * v250 = slot_13(v243);
    v254 = v250;
  } else {
    struct StateT * v252 = slot_5(v243);
    v254 = v252;
  }
  return v254;
}

struct StateT * slot_13(struct StateT * v267) {
  int v268 = v267->timer;
  int v276 = v268 + 1;
  v267->timer = v276;
  int * v270 = v267->regs;
  int v271 = v270[10];
  int * v272 = v267->regs;
  int v280 = v271 & 7;
  v272[10] = v280;
  struct StateT * v274 = slot_14(v267);
  return v274;
}

struct StateT * slot_15(struct StateT * v336) {
  int v337 = v336->timer;
  int v347 = v337 + 1;
  v336->timer = v347;
  int * v339 = v336->regs;
  int v340 = v339[13];
  int * v341 = v336->regs;
  int v342 = v341[10];
  int * v343 = v336->regs;
  int v353 = v340 + v342;
  v343[10] = v353;
  struct StateT * v345 = slot_16(v336);
  return v345;
}

struct StateT * slot_9(struct StateT * v579) {
  int v580 = v579->timer;
  int v588 = v580 + 1;
  v579->timer = v588;
  int * v582 = v579->regs;
  int v583 = v582[14];
  int * v584 = v579->regs;
  int v592 = v583 << 2;
  v584[14] = v592;
  struct StateT * v586 = slot_10(v579);
  return v586;
}

struct StateT * slot_11(struct StateT * v615) {
  int v616 = v615->timer;
  int v674 = v616 + 1;
  v615->timer = v674;
  int * v618 = v615->regs;
  int v619 = v618[11];
  int * v620 = v615->cache_keys;
  int v621 = v620[0];
  bool v679 = v621 == ((int)((unsigned int)v619 >> 2));
  int v669;
  if (v679) {
    int * v622 = v615->cache_vals;
    int v623 = v622[0];
    v669 = v623;
  } else {
    int * v625 = v615->cache_keys;
    int v626 = v625[1];
    bool v684 = v626 == ((int)((unsigned int)v619 >> 2));
    int v667;
    if (v684) {
      int * v627 = v615->cache_vals;
      int v628 = v627[1];
      int * v629 = v615->cache_keys;
      int * v630 = v615->cache_keys;
      int v631 = v630[0];
      v629[1] = v631;
      int * v633 = v615->cache_vals;
      int * v634 = v615->cache_vals;
      int v635 = v634[0];
      v633[1] = v635;
      int * v637 = v615->cache_keys;
      int v693 = (int)((unsigned int)v619 >> 2);
      v637[0] = v693;
      int * v639 = v615->cache_vals;
      v639[0] = v628;
      int v641 = v615->timer;
      int v696 = v641 + 1;
      v615->timer = v696;
      v667 = v628;
    } else {
      int * v644 = v615->mem;
      int v698 = (int)((unsigned int)v619 >> 2);
      int v645 = v644[v698];
      int * v646 = v615->mem;
      int * v647 = v615->cache_keys;
      int v648 = v647[1];
      int * v649 = v615->cache_vals;
      int v650 = v649[1];
      v646[v648] = v650;
      int * v652 = v615->cache_keys;
      int * v653 = v615->cache_keys;
      int v654 = v653[0];
      v652[1] = v654;
      int * v656 = v615->cache_vals;
      int * v657 = v615->cache_vals;
      int v658 = v657[0];
      v656[1] = v658;
      int * v660 = v615->cache_keys;
      v660[0] = v698;
      int * v662 = v615->cache_vals;
      v662[0] = v645;
      int v664 = v615->timer;
      int v713 = v664 + 100;
      v615->timer = v713;
      v667 = v645;
    }
    v669 = v667;
  }
  int * v670 = v615->regs;
  v670[11] = v669;
  struct StateT * v672 = slot_12(v615);
  return v672;
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