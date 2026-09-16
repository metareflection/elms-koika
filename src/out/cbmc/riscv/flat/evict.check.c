// verify: clean (CBMC should report VERIFICATION SUCCESSFUL) [unwind 65]
#define NUM_REGS 32
#define MEM_SIZE 64
#define SECRET_SIZE 10
#define SECRET_OFFSET 20
#define CACHE_ENTRIES 2
#define CACHE_WORDS 2

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
  int cache_tags[2];
  int cache_dirty[2];
  int cache_age[2];
  int cache_vals[2];
  int timer;
};

struct StateT * snippet(struct StateT * v0);
struct StateT * slot_1(struct StateT * v127);
struct StateT * slot_6(struct StateT * v425);
struct StateT * slot_5(struct StateT * v300);
struct StateT * slot_4(struct StateT * v176);
struct StateT * slot_2(struct StateT * v144);
struct StateT * slot_7(struct StateT * v559);
struct StateT * slot_3(struct StateT * v160);
struct StateT * slot_0(struct StateT * v2);
struct StateT * snippet(struct StateT * v0) {
  struct StateT * v1 = slot_0(v0);
  return v1;
}

struct StateT * slot_1(struct StateT * v127) {
  int v128 = v127->timer;
  int v136 = v128 + 1;
  v127->timer = v136;
  int * v130 = v127->regs;
  int v131 = v130[5];
  int * v132 = v127->regs;
  int v141 = v131 & 1;
  v132[6] = v141;
  struct StateT * v134 = slot_2(v127);
  return v134;
}

struct StateT * slot_6(struct StateT * v425) {
  int v426 = v425->timer;
  int v498 = v426 + 1;
  v425->timer = v498;
  int * v428 = v425->regs;
  int v429 = v428[6];
  int * v430 = v425->cache_tags;
  int v431 = v430[0];
  int * v432 = v425->cache_tags;
  int v433 = v432[1];
  int v434 = v425->timer;
  int v505 = v434 + (100 ^ (((~(((v431 ^ ((int)((unsigned int)v429 >> 2))) | (-(v431 ^ ((int)((unsigned int)v429 >> 2))))) >> 31)) | (~(((v433 ^ ((int)((unsigned int)v429 >> 2))) | (-(v433 ^ ((int)((unsigned int)v429 >> 2))))) >> 31))) & 101));
  v425->timer = v505;
  int * v436 = v425->cache_vals;
  bool v506 = !(((~(((v431 ^ ((int)((unsigned int)v429 >> 2))) | (-(v431 ^ ((int)((unsigned int)v429 >> 2))))) >> 31)) | (~(((v433 ^ ((int)((unsigned int)v429 >> 2))) | (-(v433 ^ ((int)((unsigned int)v429 >> 2))))) >> 31))) == 0);
  int v492;
  if (v506) {
    int * v437 = v425->cache_age;
    int v508 = (~(((v433 ^ ((int)((unsigned int)v429 >> 2))) | (-(v433 ^ ((int)((unsigned int)v429 >> 2))))) >> 31)) & 1;
    int v438 = v437[v508];
    int * v439 = v425->cache_age;
    int v440 = v439[0];
    int * v441 = v425->cache_age;
    int v511 = v440 + ((int)((unsigned int)(v440 - v438) >> 31));
    v441[0] = v511;
    int * v443 = v425->cache_age;
    int v444 = v443[1];
    int * v445 = v425->cache_age;
    int v514 = v444 + ((int)((unsigned int)(v444 - v438) >> 31));
    v445[1] = v514;
    int * v447 = v425->cache_age;
    v447[v508] = 0;
    v492 = v508;
  } else {
    int * v450 = v425->cache_age;
    int v451 = v450[0];
    int * v452 = v425->cache_tags;
    int v453 = v452[0];
    int * v454 = v425->cache_age;
    int v455 = v454[1];
    int * v456 = v425->cache_tags;
    int v457 = v456[1];
    int * v458 = v425->cache_dirty;
    int v523 = (((v451 + ((~(((v453 ^ -1) | (-(v453 ^ -1))) >> 31)) & 2)) - (v455 + ((~(((v457 ^ -1) | (-(v457 ^ -1))) >> 31)) & 2))) >> 31) & 1;
    int v459 = v458[v523];
    bool v524 = !(v459 == 0);
    if (v524) {
      int * v460 = v425->cache_tags;
      int v461 = v460[v523];
      int * v462 = v425->cache_vals;
      int v527 = (((v451 + ((~(((v453 ^ -1) | (-(v453 ^ -1))) >> 31)) & 2)) - (v455 + ((~(((v457 ^ -1) | (-(v457 ^ -1))) >> 31)) & 2))) >> 31) & 1;
      int v463 = v462[v527];
      int * v464 = v425->mem;
      v464[v461] = v463;
      ;
    } else {
      ;
    }
    int * v469 = v425->mem;
    int v534 = (int)((unsigned int)v429 >> 2);
    int v470 = v469[v534];
    int * v471 = v425->cache_vals;
    int v536 = (((v451 + ((~(((v453 ^ -1) | (-(v453 ^ -1))) >> 31)) & 2)) - (v455 + ((~(((v457 ^ -1) | (-(v457 ^ -1))) >> 31)) & 2))) >> 31) & 1;
    v471[v536] = v470;
    int * v473 = v425->cache_tags;
    int v539 = (int)((unsigned int)v429 >> 2);
    v473[v523] = v539;
    int * v475 = v425->cache_dirty;
    v475[v523] = 0;
    int * v477 = v425->cache_age;
    v477[v523] = 1;
    int * v479 = v425->cache_age;
    int v480 = v479[v523];
    int * v481 = v425->cache_age;
    int v482 = v481[0];
    int * v483 = v425->cache_age;
    int v547 = v482 + ((int)((unsigned int)(v482 - v480) >> 31));
    v483[0] = v547;
    int * v485 = v425->cache_age;
    int v486 = v485[1];
    int * v487 = v425->cache_age;
    int v550 = v486 + ((int)((unsigned int)(v486 - v480) >> 31));
    v487[1] = v550;
    int * v489 = v425->cache_age;
    v489[v523] = 0;
    v492 = v523;
  }
  int v493 = v436[v492];
  int * v494 = v425->regs;
  v494[9] = v493;
  struct StateT * v496 = slot_7(v425);
  return v496;
}

struct StateT * slot_5(struct StateT * v300) {
  int v301 = v300->timer;
  int v371 = v301 + 1;
  v300->timer = v371;
  int * v303 = v300->cache_tags;
  int v304 = v303[0];
  int * v305 = v300->cache_tags;
  int v306 = v305[1];
  int v307 = v300->timer;
  int v376 = v307 + (100 ^ (((~(((v304 ^ 4) | (-(v304 ^ 4))) >> 31)) | (~(((v306 ^ 4) | (-(v306 ^ 4))) >> 31))) & 101));
  v300->timer = v376;
  int * v309 = v300->cache_vals;
  bool v377 = !(((~(((v304 ^ 4) | (-(v304 ^ 4))) >> 31)) | (~(((v306 ^ 4) | (-(v306 ^ 4))) >> 31))) == 0);
  int v365;
  if (v377) {
    int * v310 = v300->cache_age;
    int v379 = (~(((v306 ^ 4) | (-(v306 ^ 4))) >> 31)) & 1;
    int v311 = v310[v379];
    int * v312 = v300->cache_age;
    int v313 = v312[0];
    int * v314 = v300->cache_age;
    int v382 = v313 + ((int)((unsigned int)(v313 - v311) >> 31));
    v314[0] = v382;
    int * v316 = v300->cache_age;
    int v317 = v316[1];
    int * v318 = v300->cache_age;
    int v385 = v317 + ((int)((unsigned int)(v317 - v311) >> 31));
    v318[1] = v385;
    int * v320 = v300->cache_age;
    v320[v379] = 0;
    v365 = v379;
  } else {
    int * v323 = v300->cache_age;
    int v324 = v323[0];
    int * v325 = v300->cache_tags;
    int v326 = v325[0];
    int * v327 = v300->cache_age;
    int v328 = v327[1];
    int * v329 = v300->cache_tags;
    int v330 = v329[1];
    int * v331 = v300->cache_dirty;
    int v392 = (((v324 + ((~(((v326 ^ -1) | (-(v326 ^ -1))) >> 31)) & 2)) - (v328 + ((~(((v330 ^ -1) | (-(v330 ^ -1))) >> 31)) & 2))) >> 31) & 1;
    int v332 = v331[v392];
    bool v393 = !(v332 == 0);
    if (v393) {
      int * v333 = v300->cache_tags;
      int v334 = v333[v392];
      int * v335 = v300->cache_vals;
      int v396 = (((v324 + ((~(((v326 ^ -1) | (-(v326 ^ -1))) >> 31)) & 2)) - (v328 + ((~(((v330 ^ -1) | (-(v330 ^ -1))) >> 31)) & 2))) >> 31) & 1;
      int v336 = v335[v396];
      int * v337 = v300->mem;
      v337[v334] = v336;
      ;
    } else {
      ;
    }
    int * v342 = v300->mem;
    int v343 = v342[4];
    int * v344 = v300->cache_vals;
    int v405 = (((v324 + ((~(((v326 ^ -1) | (-(v326 ^ -1))) >> 31)) & 2)) - (v328 + ((~(((v330 ^ -1) | (-(v330 ^ -1))) >> 31)) & 2))) >> 31) & 1;
    v344[v405] = v343;
    int * v346 = v300->cache_tags;
    v346[v392] = 4;
    int * v348 = v300->cache_dirty;
    v348[v392] = 0;
    int * v350 = v300->cache_age;
    v350[v392] = 1;
    int * v352 = v300->cache_age;
    int v353 = v352[v392];
    int * v354 = v300->cache_age;
    int v355 = v354[0];
    int * v356 = v300->cache_age;
    int v413 = v355 + ((int)((unsigned int)(v355 - v353) >> 31));
    v356[0] = v413;
    int * v358 = v300->cache_age;
    int v359 = v358[1];
    int * v360 = v300->cache_age;
    int v416 = v359 + ((int)((unsigned int)(v359 - v353) >> 31));
    v360[1] = v416;
    int * v362 = v300->cache_age;
    v362[v392] = 0;
    v365 = v392;
  }
  int v366 = v309[v365];
  int * v367 = v300->regs;
  v367[8] = v366;
  struct StateT * v369 = slot_6(v300);
  return v369;
}

struct StateT * slot_4(struct StateT * v176) {
  int v177 = v176->timer;
  int v247 = v177 + 1;
  v176->timer = v247;
  int * v179 = v176->cache_tags;
  int v180 = v179[0];
  int * v181 = v176->cache_tags;
  int v182 = v181[1];
  int v183 = v176->timer;
  int v252 = v183 + (100 ^ (((~((v180 | (-v180)) >> 31)) | (~((v182 | (-v182)) >> 31))) & 101));
  v176->timer = v252;
  int * v185 = v176->cache_vals;
  bool v253 = !(((~((v180 | (-v180)) >> 31)) | (~((v182 | (-v182)) >> 31))) == 0);
  int v241;
  if (v253) {
    int * v186 = v176->cache_age;
    int v255 = (~((v182 | (-v182)) >> 31)) & 1;
    int v187 = v186[v255];
    int * v188 = v176->cache_age;
    int v189 = v188[0];
    int * v190 = v176->cache_age;
    int v258 = v189 + ((int)((unsigned int)(v189 - v187) >> 31));
    v190[0] = v258;
    int * v192 = v176->cache_age;
    int v193 = v192[1];
    int * v194 = v176->cache_age;
    int v261 = v193 + ((int)((unsigned int)(v193 - v187) >> 31));
    v194[1] = v261;
    int * v196 = v176->cache_age;
    v196[v255] = 0;
    v241 = v255;
  } else {
    int * v199 = v176->cache_age;
    int v200 = v199[0];
    int * v201 = v176->cache_tags;
    int v202 = v201[0];
    int * v203 = v176->cache_age;
    int v204 = v203[1];
    int * v205 = v176->cache_tags;
    int v206 = v205[1];
    int * v207 = v176->cache_dirty;
    int v268 = (((v200 + ((~(((v202 ^ -1) | (-(v202 ^ -1))) >> 31)) & 2)) - (v204 + ((~(((v206 ^ -1) | (-(v206 ^ -1))) >> 31)) & 2))) >> 31) & 1;
    int v208 = v207[v268];
    bool v269 = !(v208 == 0);
    if (v269) {
      int * v209 = v176->cache_tags;
      int v210 = v209[v268];
      int * v211 = v176->cache_vals;
      int v272 = (((v200 + ((~(((v202 ^ -1) | (-(v202 ^ -1))) >> 31)) & 2)) - (v204 + ((~(((v206 ^ -1) | (-(v206 ^ -1))) >> 31)) & 2))) >> 31) & 1;
      int v212 = v211[v272];
      int * v213 = v176->mem;
      v213[v210] = v212;
      ;
    } else {
      ;
    }
    int * v218 = v176->mem;
    int v219 = v218[0];
    int * v220 = v176->cache_vals;
    int v280 = (((v200 + ((~(((v202 ^ -1) | (-(v202 ^ -1))) >> 31)) & 2)) - (v204 + ((~(((v206 ^ -1) | (-(v206 ^ -1))) >> 31)) & 2))) >> 31) & 1;
    v220[v280] = v219;
    int * v222 = v176->cache_tags;
    v222[v268] = 0;
    int * v224 = v176->cache_dirty;
    v224[v268] = 0;
    int * v226 = v176->cache_age;
    v226[v268] = 1;
    int * v228 = v176->cache_age;
    int v229 = v228[v268];
    int * v230 = v176->cache_age;
    int v231 = v230[0];
    int * v232 = v176->cache_age;
    int v288 = v231 + ((int)((unsigned int)(v231 - v229) >> 31));
    v232[0] = v288;
    int * v234 = v176->cache_age;
    int v235 = v234[1];
    int * v236 = v176->cache_age;
    int v291 = v235 + ((int)((unsigned int)(v235 - v229) >> 31));
    v236[1] = v291;
    int * v238 = v176->cache_age;
    v238[v268] = 0;
    v241 = v268;
  }
  int v242 = v185[v241];
  int * v243 = v176->regs;
  v243[7] = v242;
  struct StateT * v245 = slot_5(v176);
  return v245;
}

struct StateT * slot_2(struct StateT * v144) {
  int v145 = v144->timer;
  int v153 = v145 + 1;
  v144->timer = v153;
  int * v147 = v144->regs;
  int v148 = v147[6];
  int * v149 = v144->regs;
  int v157 = v148 << 3;
  v149[6] = v157;
  struct StateT * v151 = slot_3(v144);
  return v151;
}

struct StateT * slot_7(struct StateT * v559) {
  int v560 = v559->timer;
  int v629 = v560 + 1;
  v559->timer = v629;
  int * v562 = v559->cache_tags;
  int v563 = v562[0];
  int * v564 = v559->cache_tags;
  int v565 = v564[1];
  int v566 = v559->timer;
  int v634 = v566 + (100 ^ (((~((v563 | (-v563)) >> 31)) | (~((v565 | (-v565)) >> 31))) & 101));
  v559->timer = v634;
  int * v568 = v559->cache_vals;
  bool v635 = !(((~((v563 | (-v563)) >> 31)) | (~((v565 | (-v565)) >> 31))) == 0);
  int v624;
  if (v635) {
    int * v569 = v559->cache_age;
    int v637 = (~((v565 | (-v565)) >> 31)) & 1;
    int v570 = v569[v637];
    int * v571 = v559->cache_age;
    int v572 = v571[0];
    int * v573 = v559->cache_age;
    int v640 = v572 + ((int)((unsigned int)(v572 - v570) >> 31));
    v573[0] = v640;
    int * v575 = v559->cache_age;
    int v576 = v575[1];
    int * v577 = v559->cache_age;
    int v643 = v576 + ((int)((unsigned int)(v576 - v570) >> 31));
    v577[1] = v643;
    int * v579 = v559->cache_age;
    v579[v637] = 0;
    v624 = v637;
  } else {
    int * v582 = v559->cache_age;
    int v583 = v582[0];
    int * v584 = v559->cache_tags;
    int v585 = v584[0];
    int * v586 = v559->cache_age;
    int v587 = v586[1];
    int * v588 = v559->cache_tags;
    int v589 = v588[1];
    int * v590 = v559->cache_dirty;
    int v650 = (((v583 + ((~(((v585 ^ -1) | (-(v585 ^ -1))) >> 31)) & 2)) - (v587 + ((~(((v589 ^ -1) | (-(v589 ^ -1))) >> 31)) & 2))) >> 31) & 1;
    int v591 = v590[v650];
    bool v651 = !(v591 == 0);
    if (v651) {
      int * v592 = v559->cache_tags;
      int v593 = v592[v650];
      int * v594 = v559->cache_vals;
      int v654 = (((v583 + ((~(((v585 ^ -1) | (-(v585 ^ -1))) >> 31)) & 2)) - (v587 + ((~(((v589 ^ -1) | (-(v589 ^ -1))) >> 31)) & 2))) >> 31) & 1;
      int v595 = v594[v654];
      int * v596 = v559->mem;
      v596[v593] = v595;
      ;
    } else {
      ;
    }
    int * v601 = v559->mem;
    int v602 = v601[0];
    int * v603 = v559->cache_vals;
    int v662 = (((v583 + ((~(((v585 ^ -1) | (-(v585 ^ -1))) >> 31)) & 2)) - (v587 + ((~(((v589 ^ -1) | (-(v589 ^ -1))) >> 31)) & 2))) >> 31) & 1;
    v603[v662] = v602;
    int * v605 = v559->cache_tags;
    v605[v650] = 0;
    int * v607 = v559->cache_dirty;
    v607[v650] = 0;
    int * v609 = v559->cache_age;
    v609[v650] = 1;
    int * v611 = v559->cache_age;
    int v612 = v611[v650];
    int * v613 = v559->cache_age;
    int v614 = v613[0];
    int * v615 = v559->cache_age;
    int v670 = v614 + ((int)((unsigned int)(v614 - v612) >> 31));
    v615[0] = v670;
    int * v617 = v559->cache_age;
    int v618 = v617[1];
    int * v619 = v559->cache_age;
    int v673 = v618 + ((int)((unsigned int)(v618 - v612) >> 31));
    v619[1] = v673;
    int * v621 = v559->cache_age;
    v621[v650] = 0;
    v624 = v650;
  }
  int v625 = v568[v624];
  int * v626 = v559->regs;
  v626[11] = v625;
  return v559;
}

struct StateT * slot_3(struct StateT * v160) {
  int v161 = v160->timer;
  int v169 = v161 + 1;
  v160->timer = v169;
  int * v163 = v160->regs;
  int v164 = v163[6];
  int * v165 = v160->regs;
  int v173 = v164 + 32;
  v165[6] = v173;
  struct StateT * v167 = slot_4(v160);
  return v167;
}

struct StateT * slot_0(struct StateT * v2) {
  int v3 = v2->timer;
  int v73 = v3 + 1;
  v2->timer = v73;
  int * v5 = v2->cache_tags;
  int v6 = v5[0];
  int * v7 = v2->cache_tags;
  int v8 = v7[1];
  int v9 = v2->timer;
  int v78 = v9 + (100 ^ (((~(((v6 ^ 20) | (-(v6 ^ 20))) >> 31)) | (~(((v8 ^ 20) | (-(v8 ^ 20))) >> 31))) & 101));
  v2->timer = v78;
  int * v11 = v2->cache_vals;
  bool v79 = !(((~(((v6 ^ 20) | (-(v6 ^ 20))) >> 31)) | (~(((v8 ^ 20) | (-(v8 ^ 20))) >> 31))) == 0);
  int v67;
  if (v79) {
    int * v12 = v2->cache_age;
    int v81 = (~(((v8 ^ 20) | (-(v8 ^ 20))) >> 31)) & 1;
    int v13 = v12[v81];
    int * v14 = v2->cache_age;
    int v15 = v14[0];
    int * v16 = v2->cache_age;
    int v84 = v15 + ((int)((unsigned int)(v15 - v13) >> 31));
    v16[0] = v84;
    int * v18 = v2->cache_age;
    int v19 = v18[1];
    int * v20 = v2->cache_age;
    int v87 = v19 + ((int)((unsigned int)(v19 - v13) >> 31));
    v20[1] = v87;
    int * v22 = v2->cache_age;
    v22[v81] = 0;
    v67 = v81;
  } else {
    int * v25 = v2->cache_age;
    int v26 = v25[0];
    int * v27 = v2->cache_tags;
    int v28 = v27[0];
    int * v29 = v2->cache_age;
    int v30 = v29[1];
    int * v31 = v2->cache_tags;
    int v32 = v31[1];
    int * v33 = v2->cache_dirty;
    int v94 = (((v26 + ((~(((v28 ^ -1) | (-(v28 ^ -1))) >> 31)) & 2)) - (v30 + ((~(((v32 ^ -1) | (-(v32 ^ -1))) >> 31)) & 2))) >> 31) & 1;
    int v34 = v33[v94];
    bool v95 = !(v34 == 0);
    if (v95) {
      int * v35 = v2->cache_tags;
      int v36 = v35[v94];
      int * v37 = v2->cache_vals;
      int v98 = (((v26 + ((~(((v28 ^ -1) | (-(v28 ^ -1))) >> 31)) & 2)) - (v30 + ((~(((v32 ^ -1) | (-(v32 ^ -1))) >> 31)) & 2))) >> 31) & 1;
      int v38 = v37[v98];
      int * v39 = v2->mem;
      v39[v36] = v38;
      ;
    } else {
      ;
    }
    int * v44 = v2->mem;
    int v45 = v44[20];
    int * v46 = v2->cache_vals;
    int v107 = (((v26 + ((~(((v28 ^ -1) | (-(v28 ^ -1))) >> 31)) & 2)) - (v30 + ((~(((v32 ^ -1) | (-(v32 ^ -1))) >> 31)) & 2))) >> 31) & 1;
    v46[v107] = v45;
    int * v48 = v2->cache_tags;
    v48[v94] = 20;
    int * v50 = v2->cache_dirty;
    v50[v94] = 0;
    int * v52 = v2->cache_age;
    v52[v94] = 1;
    int * v54 = v2->cache_age;
    int v55 = v54[v94];
    int * v56 = v2->cache_age;
    int v57 = v56[0];
    int * v58 = v2->cache_age;
    int v115 = v57 + ((int)((unsigned int)(v57 - v55) >> 31));
    v58[0] = v115;
    int * v60 = v2->cache_age;
    int v61 = v60[1];
    int * v62 = v2->cache_age;
    int v118 = v61 + ((int)((unsigned int)(v61 - v55) >> 31));
    v62[1] = v118;
    int * v64 = v2->cache_age;
    v64[v94] = 0;
    v67 = v94;
  }
  int v68 = v11[v67];
  int * v69 = v2->regs;
  v69[5] = v68;
  struct StateT * v71 = slot_1(v2);
  return v71;
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
  for (int i=0; i<CACHE_ENTRIES; i++) {
    s->cache_tags[i] = -1;
    s->cache_dirty[i] = 0;
    s->cache_age[i] = 0;
  }
  for (int i=0; i<CACHE_WORDS; i++) {
    s->cache_vals[i] = 0;
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