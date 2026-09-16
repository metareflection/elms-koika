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

struct StateT * snippet(struct StateT * v0);
struct StateT * slot_1(struct StateT * v15);
struct StateT * slot_8(struct StateT * v660);
struct StateT * slot_6(struct StateT * v539);
struct StateT * slot_5(struct StateT * v526);
struct StateT * slot_4(struct StateT * v146);
struct StateT * slot_2(struct StateT * v120);
struct StateT * slot_7(struct StateT * v555);
struct StateT * slot_3(struct StateT * v133);
struct StateT * slot_0(struct StateT * v2);
struct StateT * snippet(struct StateT * v0) {
  struct StateT * v1 = slot_0(v0);
  return v1;
}

struct StateT * slot_1(struct StateT * v15) {
  int v16 = v15->timer;
  int v74 = v16 + 1;
  v15->timer = v74;
  int * v18 = v15->regs;
  int v19 = v18[6];
  int * v20 = v15->cache_keys;
  int v21 = v20[0];
  bool v79 = v21 == ((int)((unsigned int)v19 >> 2));
  int v69;
  if (v79) {
    int * v22 = v15->cache_vals;
    int v23 = v22[0];
    v69 = v23;
  } else {
    int * v25 = v15->cache_keys;
    int v26 = v25[1];
    bool v84 = v26 == ((int)((unsigned int)v19 >> 2));
    int v67;
    if (v84) {
      int * v27 = v15->cache_vals;
      int v28 = v27[1];
      int * v29 = v15->cache_keys;
      int * v30 = v15->cache_keys;
      int v31 = v30[0];
      v29[1] = v31;
      int * v33 = v15->cache_vals;
      int * v34 = v15->cache_vals;
      int v35 = v34[0];
      v33[1] = v35;
      int * v37 = v15->cache_keys;
      int v93 = (int)((unsigned int)v19 >> 2);
      v37[0] = v93;
      int * v39 = v15->cache_vals;
      v39[0] = v28;
      int v41 = v15->timer;
      int v96 = v41 + 1;
      v15->timer = v96;
      v67 = v28;
    } else {
      int * v44 = v15->mem;
      int v98 = (int)((unsigned int)v19 >> 2);
      int v45 = v44[v98];
      int * v46 = v15->mem;
      int * v47 = v15->cache_keys;
      int v48 = v47[1];
      int * v49 = v15->cache_vals;
      int v50 = v49[1];
      v46[v48] = v50;
      int * v52 = v15->cache_keys;
      int * v53 = v15->cache_keys;
      int v54 = v53[0];
      v52[1] = v54;
      int * v56 = v15->cache_vals;
      int * v57 = v15->cache_vals;
      int v58 = v57[0];
      v56[1] = v58;
      int * v60 = v15->cache_keys;
      v60[0] = v98;
      int * v62 = v15->cache_vals;
      v62[0] = v45;
      int v64 = v15->timer;
      int v113 = v64 + 100;
      v15->timer = v113;
      v67 = v45;
    }
    v69 = v67;
  }
  int * v70 = v15->regs;
  v70[5] = v69;
  struct StateT * v72 = slot_2(v15);
  return v72;
}

struct StateT * slot_8(struct StateT * v660) {
  int v661 = v660->timer;
  int v718 = v661 + 1;
  v660->timer = v718;
  int * v663 = v660->regs;
  int v664 = v663[11];
  int * v665 = v660->cache_keys;
  int v666 = v665[0];
  bool v723 = v666 == ((int)((unsigned int)v664 >> 2));
  int v714;
  if (v723) {
    int * v667 = v660->cache_vals;
    int v668 = v667[0];
    v714 = v668;
  } else {
    int * v670 = v660->cache_keys;
    int v671 = v670[1];
    bool v728 = v671 == ((int)((unsigned int)v664 >> 2));
    int v712;
    if (v728) {
      int * v672 = v660->cache_vals;
      int v673 = v672[1];
      int * v674 = v660->cache_keys;
      int * v675 = v660->cache_keys;
      int v676 = v675[0];
      v674[1] = v676;
      int * v678 = v660->cache_vals;
      int * v679 = v660->cache_vals;
      int v680 = v679[0];
      v678[1] = v680;
      int * v682 = v660->cache_keys;
      int v737 = (int)((unsigned int)v664 >> 2);
      v682[0] = v737;
      int * v684 = v660->cache_vals;
      v684[0] = v673;
      int v686 = v660->timer;
      int v740 = v686 + 1;
      v660->timer = v740;
      v712 = v673;
    } else {
      int * v689 = v660->mem;
      int v742 = (int)((unsigned int)v664 >> 2);
      int v690 = v689[v742];
      int * v691 = v660->mem;
      int * v692 = v660->cache_keys;
      int v693 = v692[1];
      int * v694 = v660->cache_vals;
      int v695 = v694[1];
      v691[v693] = v695;
      int * v697 = v660->cache_keys;
      int * v698 = v660->cache_keys;
      int v699 = v698[0];
      v697[1] = v699;
      int * v701 = v660->cache_vals;
      int * v702 = v660->cache_vals;
      int v703 = v702[0];
      v701[1] = v703;
      int * v705 = v660->cache_keys;
      v705[0] = v742;
      int * v707 = v660->cache_vals;
      v707[0] = v690;
      int v709 = v660->timer;
      int v757 = v709 + 100;
      v660->timer = v757;
      v712 = v690;
    }
    v714 = v712;
  }
  int * v715 = v660->regs;
  v715[12] = v714;
  return v660;
}

struct StateT * slot_6(struct StateT * v539) {
  int v540 = v539->timer;
  int v548 = v540 + 1;
  v539->timer = v548;
  int * v542 = v539->regs;
  int v543 = v542[7];
  int * v544 = v539->regs;
  int v552 = v543 + 1;
  v544[7] = v552;
  struct StateT * v546 = slot_7(v539);
  return v546;
}

struct StateT * slot_5(struct StateT * v526) {
  int v527 = v526->timer;
  int v533 = v527 + 1;
  v526->timer = v533;
  int * v529 = v526->regs;
  v529[7] = 0;
  struct StateT * v531 = slot_6(v526);
  return v531;
}

struct StateT * slot_4(struct StateT * v146) {
  int v147 = v146->timer;
  int v362 = v147 + 1;
  v146->timer = v362;
  int * v149 = v146->regs;
  int v150 = v149[8];
  int * v151 = v146->regs;
  int v152 = v151[5];
  int * v153 = v146->saved_regs;
  int * v154 = v146->regs;
  int v155 = v154[7];
  v153[7] = v155;
  int v157 = v146->timer;
  int v371 = v157 + 1;
  v146->timer = v371;
  int * v159 = v146->regs;
  v159[7] = 0;
  int v161 = v146->timer;
  int v374 = v161 + 1;
  v146->timer = v374;
  int * v163 = v146->regs;
  int v164 = v163[7];
  int * v165 = v146->regs;
  int v377 = v164 + 1;
  v165[7] = v377;
  int * v167 = v146->saved_regs;
  int * v168 = v146->regs;
  int v169 = v168[11];
  v167[11] = v169;
  int v171 = v146->timer;
  int v382 = v171 + 1;
  v146->timer = v382;
  int * v173 = v146->regs;
  int v174 = v173[9];
  bool v385 = (((int)((unsigned int)v150 >> 2)) & 3) == (((int)((unsigned int)v174 >> 2)) & 3);
  int v229;
  if (v385) {
    int v175 = v146->timer;
    int v386 = v175 + 1;
    v146->timer = v386;
    v229 = v152;
  } else {
    int * v178 = v146->cache_keys;
    int v179 = v178[0];
    bool v389 = v179 == ((int)((unsigned int)v174 >> 2));
    int v227;
    if (v389) {
      int * v180 = v146->cache_vals;
      int v181 = v180[0];
      v227 = v181;
    } else {
      int * v183 = v146->cache_keys;
      int v184 = v183[1];
      bool v394 = v184 == ((int)((unsigned int)v174 >> 2));
      int v225;
      if (v394) {
        int * v185 = v146->cache_vals;
        int v186 = v185[1];
        int * v187 = v146->cache_keys;
        int * v188 = v146->cache_keys;
        int v189 = v188[0];
        v187[1] = v189;
        int * v191 = v146->cache_vals;
        int * v192 = v146->cache_vals;
        int v193 = v192[0];
        v191[1] = v193;
        int * v195 = v146->cache_keys;
        int v403 = (int)((unsigned int)v174 >> 2);
        v195[0] = v403;
        int * v197 = v146->cache_vals;
        v197[0] = v186;
        int v199 = v146->timer;
        int v406 = v199 + 1;
        v146->timer = v406;
        v225 = v186;
      } else {
        int * v202 = v146->mem;
        int v408 = (int)((unsigned int)v174 >> 2);
        int v203 = v202[v408];
        int * v204 = v146->mem;
        int * v205 = v146->cache_keys;
        int v206 = v205[1];
        int * v207 = v146->cache_vals;
        int v208 = v207[1];
        v204[v206] = v208;
        int * v210 = v146->cache_keys;
        int * v211 = v146->cache_keys;
        int v212 = v211[0];
        v210[1] = v212;
        int * v214 = v146->cache_vals;
        int * v215 = v146->cache_vals;
        int v216 = v215[0];
        v214[1] = v216;
        int * v218 = v146->cache_keys;
        v218[0] = v408;
        int * v220 = v146->cache_vals;
        v220[0] = v203;
        int v222 = v146->timer;
        int v423 = v222 + 100;
        v146->timer = v423;
        v225 = v203;
      }
      v227 = v225;
    }
    v229 = v227;
  }
  int * v230 = v146->regs;
  v230[11] = v229;
  int * v232 = v146->saved_regs;
  int * v233 = v146->regs;
  int v234 = v233[12];
  v232[12] = v234;
  int v236 = v146->timer;
  int v432 = v236 + 1;
  v146->timer = v432;
  int * v238 = v146->regs;
  int v239 = v238[11];
  bool v434 = (((int)((unsigned int)v150 >> 2)) & 3) == (((int)((unsigned int)v239 >> 2)) & 3);
  int v294;
  if (v434) {
    int v240 = v146->timer;
    int v435 = v240 + 1;
    v146->timer = v435;
    v294 = v152;
  } else {
    int * v243 = v146->cache_keys;
    int v244 = v243[0];
    bool v438 = v244 == ((int)((unsigned int)v239 >> 2));
    int v292;
    if (v438) {
      int * v245 = v146->cache_vals;
      int v246 = v245[0];
      v292 = v246;
    } else {
      int * v248 = v146->cache_keys;
      int v249 = v248[1];
      bool v443 = v249 == ((int)((unsigned int)v239 >> 2));
      int v290;
      if (v443) {
        int * v250 = v146->cache_vals;
        int v251 = v250[1];
        int * v252 = v146->cache_keys;
        int * v253 = v146->cache_keys;
        int v254 = v253[0];
        v252[1] = v254;
        int * v256 = v146->cache_vals;
        int * v257 = v146->cache_vals;
        int v258 = v257[0];
        v256[1] = v258;
        int * v260 = v146->cache_keys;
        int v452 = (int)((unsigned int)v239 >> 2);
        v260[0] = v452;
        int * v262 = v146->cache_vals;
        v262[0] = v251;
        int v264 = v146->timer;
        int v455 = v264 + 1;
        v146->timer = v455;
        v290 = v251;
      } else {
        int * v267 = v146->mem;
        int v457 = (int)((unsigned int)v239 >> 2);
        int v268 = v267[v457];
        int * v269 = v146->mem;
        int * v270 = v146->cache_keys;
        int v271 = v270[1];
        int * v272 = v146->cache_vals;
        int v273 = v272[1];
        v269[v271] = v273;
        int * v275 = v146->cache_keys;
        int * v276 = v146->cache_keys;
        int v277 = v276[0];
        v275[1] = v277;
        int * v279 = v146->cache_vals;
        int * v280 = v146->cache_vals;
        int v281 = v280[0];
        v279[1] = v281;
        int * v283 = v146->cache_keys;
        v283[0] = v457;
        int * v285 = v146->cache_vals;
        v285[0] = v268;
        int v287 = v146->timer;
        int v472 = v287 + 100;
        v146->timer = v472;
        v290 = v268;
      }
      v292 = v290;
    }
    v294 = v292;
  }
  int * v295 = v146->regs;
  v295[12] = v294;
  int * v297 = v146->cache_keys;
  int v298 = v297[0];
  bool v478 = v298 == ((int)((unsigned int)v150 >> 2));
  int v342;
  if (v478) {
    int * v299 = v146->cache_vals;
    v299[0] = v152;
    v342 = v152;
  } else {
    int * v302 = v146->cache_keys;
    int v303 = v302[1];
    bool v483 = v303 == ((int)((unsigned int)v150 >> 2));
    int v340;
    if (v483) {
      int * v304 = v146->cache_keys;
      int * v305 = v146->cache_keys;
      int v306 = v305[0];
      v304[1] = v306;
      int * v308 = v146->cache_vals;
      int * v309 = v146->cache_vals;
      int v310 = v309[0];
      v308[1] = v310;
      int * v312 = v146->cache_keys;
      int v491 = (int)((unsigned int)v150 >> 2);
      v312[0] = v491;
      int * v314 = v146->cache_vals;
      v314[0] = v152;
      int v316 = v146->timer;
      int v494 = v316 + 1;
      v146->timer = v494;
      v340 = v152;
    } else {
      int * v319 = v146->mem;
      int * v320 = v146->cache_keys;
      int v321 = v320[1];
      int * v322 = v146->cache_vals;
      int v323 = v322[1];
      v319[v321] = v323;
      int * v325 = v146->cache_keys;
      int * v326 = v146->cache_keys;
      int v327 = v326[0];
      v325[1] = v327;
      int * v329 = v146->cache_vals;
      int * v330 = v146->cache_vals;
      int v331 = v330[0];
      v329[1] = v331;
      int * v333 = v146->cache_keys;
      int v507 = (int)((unsigned int)v150 >> 2);
      v333[0] = v507;
      int * v335 = v146->cache_vals;
      v335[0] = v152;
      int v337 = v146->timer;
      int v510 = v337 + 100;
      v146->timer = v510;
      v340 = v152;
    }
    v342 = v340;
  }
  bool v512 = (((((int)((unsigned int)v174 >> 2)) & 3) == (((int)((unsigned int)v150 >> 2)) & 3)) & (!(((int)((unsigned int)v174 >> 2)) == ((int)((unsigned int)v150 >> 2))))) | (((((int)((unsigned int)v239 >> 2)) & 3) == (((int)((unsigned int)v150 >> 2)) & 3)) & (!(((int)((unsigned int)v239 >> 2)) == ((int)((unsigned int)v150 >> 2)))));
  struct StateT * v360;
  if (v512) {
    int v343 = v146->timer;
    int v513 = v343 + 15;
    v146->timer = v513;
    int * v345 = v146->saved_regs;
    int v346 = v345[7];
    int * v347 = v146->regs;
    v347[7] = v346;
    int * v349 = v146->saved_regs;
    int v350 = v349[11];
    int * v351 = v146->regs;
    v351[11] = v350;
    int * v353 = v146->saved_regs;
    int v354 = v353[12];
    int * v355 = v146->regs;
    v355[12] = v354;
    struct StateT * v357 = slot_5(v146);
    v360 = v357;
  } else {
    v360 = v146;
  }
  return v360;
}

struct StateT * slot_2(struct StateT * v120) {
  int v121 = v120->timer;
  int v127 = v121 + 1;
  v120->timer = v127;
  int * v123 = v120->regs;
  v123[8] = 96;
  struct StateT * v125 = slot_3(v120);
  return v125;
}

struct StateT * slot_7(struct StateT * v555) {
  int v556 = v555->timer;
  int v614 = v556 + 1;
  v555->timer = v614;
  int * v558 = v555->regs;
  int v559 = v558[9];
  int * v560 = v555->cache_keys;
  int v561 = v560[0];
  bool v619 = v561 == ((int)((unsigned int)v559 >> 2));
  int v609;
  if (v619) {
    int * v562 = v555->cache_vals;
    int v563 = v562[0];
    v609 = v563;
  } else {
    int * v565 = v555->cache_keys;
    int v566 = v565[1];
    bool v624 = v566 == ((int)((unsigned int)v559 >> 2));
    int v607;
    if (v624) {
      int * v567 = v555->cache_vals;
      int v568 = v567[1];
      int * v569 = v555->cache_keys;
      int * v570 = v555->cache_keys;
      int v571 = v570[0];
      v569[1] = v571;
      int * v573 = v555->cache_vals;
      int * v574 = v555->cache_vals;
      int v575 = v574[0];
      v573[1] = v575;
      int * v577 = v555->cache_keys;
      int v633 = (int)((unsigned int)v559 >> 2);
      v577[0] = v633;
      int * v579 = v555->cache_vals;
      v579[0] = v568;
      int v581 = v555->timer;
      int v636 = v581 + 1;
      v555->timer = v636;
      v607 = v568;
    } else {
      int * v584 = v555->mem;
      int v638 = (int)((unsigned int)v559 >> 2);
      int v585 = v584[v638];
      int * v586 = v555->mem;
      int * v587 = v555->cache_keys;
      int v588 = v587[1];
      int * v589 = v555->cache_vals;
      int v590 = v589[1];
      v586[v588] = v590;
      int * v592 = v555->cache_keys;
      int * v593 = v555->cache_keys;
      int v594 = v593[0];
      v592[1] = v594;
      int * v596 = v555->cache_vals;
      int * v597 = v555->cache_vals;
      int v598 = v597[0];
      v596[1] = v598;
      int * v600 = v555->cache_keys;
      v600[0] = v638;
      int * v602 = v555->cache_vals;
      v602[0] = v585;
      int v604 = v555->timer;
      int v653 = v604 + 100;
      v555->timer = v653;
      v607 = v585;
    }
    v609 = v607;
  }
  int * v610 = v555->regs;
  v610[11] = v609;
  struct StateT * v612 = slot_8(v555);
  return v612;
}

struct StateT * slot_3(struct StateT * v133) {
  int v134 = v133->timer;
  int v140 = v134 + 1;
  v133->timer = v140;
  int * v136 = v133->regs;
  v136[9] = 0;
  struct StateT * v138 = slot_4(v133);
  return v138;
}

struct StateT * slot_0(struct StateT * v2) {
  int v3 = v2->timer;
  int v9 = v3 + 1;
  v2->timer = v9;
  int * v5 = v2->regs;
  v5[6] = 80;
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