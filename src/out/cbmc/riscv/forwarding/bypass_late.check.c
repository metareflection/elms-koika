// verify: leak (CBMC should report VERIFICATION FAILED) [unwind 33]
#define NUM_REGS 32
#define MEM_SIZE 30
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
  int mem[30];
  int saved_regs[32];
  int cache_keys[10];
  int cache_vals[10];
  int timer;
};

struct StateT * snippet(struct StateT * v0);
struct StateT * slot_1(struct StateT * v19);
struct StateT * slot_8(struct StateT * v562);
struct StateT * slot_6(struct StateT * v441);
struct StateT * slot_2(struct StateT * v32);
struct StateT * slot_7(struct StateT * v546);
struct StateT * slot_0(struct StateT * v2);
struct StateT * snippet(struct StateT * v0) {
  struct StateT * v1 = slot_0(v0);
  return v1;
}

struct StateT * slot_1(struct StateT * v19) {
  int v20 = v19->timer;
  int v26 = v20 + 1;
  v19->timer = v26;
  int * v22 = v19->regs;
  v22[9] = 32;
  struct StateT * v24 = slot_2(v19);
  return v24;
}

struct StateT * slot_8(struct StateT * v562) {
  int v563 = v562->timer;
  int v620 = v563 + 1;
  v562->timer = v620;
  int * v565 = v562->regs;
  int v566 = v565[11];
  int * v567 = v562->cache_keys;
  int v568 = v567[0];
  bool v625 = v568 == ((int)((unsigned int)v566 >> 2));
  int v616;
  if (v625) {
    int * v569 = v562->cache_vals;
    int v570 = v569[0];
    v616 = v570;
  } else {
    int * v572 = v562->cache_keys;
    int v573 = v572[1];
    bool v630 = v573 == ((int)((unsigned int)v566 >> 2));
    int v614;
    if (v630) {
      int * v574 = v562->cache_vals;
      int v575 = v574[1];
      int * v576 = v562->cache_keys;
      int * v577 = v562->cache_keys;
      int v578 = v577[0];
      v576[1] = v578;
      int * v580 = v562->cache_vals;
      int * v581 = v562->cache_vals;
      int v582 = v581[0];
      v580[1] = v582;
      int * v584 = v562->cache_keys;
      int v639 = (int)((unsigned int)v566 >> 2);
      v584[0] = v639;
      int * v586 = v562->cache_vals;
      v586[0] = v575;
      int v588 = v562->timer;
      int v642 = v588 + 1;
      v562->timer = v642;
      v614 = v575;
    } else {
      int * v591 = v562->mem;
      int v644 = (int)((unsigned int)v566 >> 2);
      int v592 = v591[v644];
      int * v593 = v562->mem;
      int * v594 = v562->cache_keys;
      int v595 = v594[1];
      int * v596 = v562->cache_vals;
      int v597 = v596[1];
      v593[v595] = v597;
      int * v599 = v562->cache_keys;
      int * v600 = v562->cache_keys;
      int v601 = v600[0];
      v599[1] = v601;
      int * v603 = v562->cache_vals;
      int * v604 = v562->cache_vals;
      int v605 = v604[0];
      v603[1] = v605;
      int * v607 = v562->cache_keys;
      v607[0] = v644;
      int * v609 = v562->cache_vals;
      v609[0] = v592;
      int v611 = v562->timer;
      int v659 = v611 + 100;
      v562->timer = v659;
      v614 = v592;
    }
    v616 = v614;
  }
  int * v617 = v562->regs;
  v617[12] = v616;
  return v562;
}

struct StateT * slot_6(struct StateT * v441) {
  int v442 = v441->timer;
  int v500 = v442 + 1;
  v441->timer = v500;
  int * v444 = v441->regs;
  int v445 = v444[6];
  int * v446 = v441->cache_keys;
  int v447 = v446[0];
  bool v505 = v447 == ((int)((unsigned int)v445 >> 2));
  int v495;
  if (v505) {
    int * v448 = v441->cache_vals;
    int v449 = v448[0];
    v495 = v449;
  } else {
    int * v451 = v441->cache_keys;
    int v452 = v451[1];
    bool v510 = v452 == ((int)((unsigned int)v445 >> 2));
    int v493;
    if (v510) {
      int * v453 = v441->cache_vals;
      int v454 = v453[1];
      int * v455 = v441->cache_keys;
      int * v456 = v441->cache_keys;
      int v457 = v456[0];
      v455[1] = v457;
      int * v459 = v441->cache_vals;
      int * v460 = v441->cache_vals;
      int v461 = v460[0];
      v459[1] = v461;
      int * v463 = v441->cache_keys;
      int v519 = (int)((unsigned int)v445 >> 2);
      v463[0] = v519;
      int * v465 = v441->cache_vals;
      v465[0] = v454;
      int v467 = v441->timer;
      int v522 = v467 + 1;
      v441->timer = v522;
      v493 = v454;
    } else {
      int * v470 = v441->mem;
      int v524 = (int)((unsigned int)v445 >> 2);
      int v471 = v470[v524];
      int * v472 = v441->mem;
      int * v473 = v441->cache_keys;
      int v474 = v473[1];
      int * v475 = v441->cache_vals;
      int v476 = v475[1];
      v472[v474] = v476;
      int * v478 = v441->cache_keys;
      int * v479 = v441->cache_keys;
      int v480 = v479[0];
      v478[1] = v480;
      int * v482 = v441->cache_vals;
      int * v483 = v441->cache_vals;
      int v484 = v483[0];
      v482[1] = v484;
      int * v486 = v441->cache_keys;
      v486[0] = v524;
      int * v488 = v441->cache_vals;
      v488[0] = v471;
      int v490 = v441->timer;
      int v539 = v490 + 100;
      v441->timer = v539;
      v493 = v471;
    }
    v495 = v493;
  }
  int * v496 = v441->regs;
  v496[11] = v495;
  struct StateT * v498 = slot_7(v441);
  return v498;
}

struct StateT * slot_2(struct StateT * v32) {
  int * v33 = v32->saved_regs;
  int * v34 = v32->regs;
  int v35 = v34[6];
  v33[6] = v35;
  int v37 = v32->timer;
  int v270 = v37 + 1;
  v32->timer = v270;
  int * v39 = v32->regs;
  int v40 = v39[5];
  int * v41 = v32->regs;
  int v274 = v40 + 80;
  v41[6] = v274;
  int * v43 = v32->saved_regs;
  int * v44 = v32->regs;
  int v45 = v44[7];
  v43[7] = v45;
  int v47 = v32->timer;
  int v279 = v47 + 1;
  v32->timer = v279;
  int * v49 = v32->regs;
  v49[7] = 0;
  int * v51 = v32->regs;
  int v52 = v51[5];
  int * v53 = v32->regs;
  int v54 = v53[9];
  bool v285 = v52 >= v54;
  struct StateT * v264;
  if (v285) {
    int v55 = v32->timer;
    int v286 = v55 + 15;
    v32->timer = v286;
    int * v57 = v32->saved_regs;
    int v58 = v57[6];
    int * v59 = v32->regs;
    v59[6] = v58;
    int * v61 = v32->saved_regs;
    int v62 = v61[7];
    int * v63 = v32->regs;
    v63[7] = v62;
    v264 = v32;
  } else {
    int v66 = v32->timer;
    int v293 = v66 + 1;
    v32->timer = v293;
    int * v68 = v32->regs;
    int v69 = v68[6];
    int * v70 = v32->regs;
    int v71 = v70[7];
    int * v72 = v32->saved_regs;
    int * v73 = v32->regs;
    int v74 = v73[11];
    v72[11] = v74;
    int v76 = v32->timer;
    int v300 = v76 + 1;
    v32->timer = v300;
    int * v78 = v32->regs;
    int v79 = v78[6];
    int * v80 = v32->cache_keys;
    int v81 = v80[0];
    bool v303 = v81 == ((int)((unsigned int)v79 >> 2));
    int v129;
    if (v303) {
      int * v82 = v32->cache_vals;
      int v83 = v82[0];
      v129 = v83;
    } else {
      int * v85 = v32->cache_keys;
      int v86 = v85[1];
      bool v308 = v86 == ((int)((unsigned int)v79 >> 2));
      int v127;
      if (v308) {
        int * v87 = v32->cache_vals;
        int v88 = v87[1];
        int * v89 = v32->cache_keys;
        int * v90 = v32->cache_keys;
        int v91 = v90[0];
        v89[1] = v91;
        int * v93 = v32->cache_vals;
        int * v94 = v32->cache_vals;
        int v95 = v94[0];
        v93[1] = v95;
        int * v97 = v32->cache_keys;
        int v317 = (int)((unsigned int)v79 >> 2);
        v97[0] = v317;
        int * v99 = v32->cache_vals;
        v99[0] = v88;
        int v101 = v32->timer;
        int v320 = v101 + 1;
        v32->timer = v320;
        v127 = v88;
      } else {
        int * v104 = v32->mem;
        int v322 = (int)((unsigned int)v79 >> 2);
        int v105 = v104[v322];
        int * v106 = v32->mem;
        int * v107 = v32->cache_keys;
        int v108 = v107[1];
        int * v109 = v32->cache_vals;
        int v110 = v109[1];
        v106[v108] = v110;
        int * v112 = v32->cache_keys;
        int * v113 = v32->cache_keys;
        int v114 = v113[0];
        v112[1] = v114;
        int * v116 = v32->cache_vals;
        int * v117 = v32->cache_vals;
        int v118 = v117[0];
        v116[1] = v118;
        int * v120 = v32->cache_keys;
        v120[0] = v322;
        int * v122 = v32->cache_vals;
        v122[0] = v105;
        int v124 = v32->timer;
        int v337 = v124 + 100;
        v32->timer = v337;
        v127 = v105;
      }
      v129 = v127;
    }
    int * v130 = v32->regs;
    v130[11] = v129;
    int v132 = v32->timer;
    int v341 = v132 + 1;
    v32->timer = v341;
    int * v134 = v32->regs;
    int v135 = v134[11];
    int * v136 = v32->regs;
    int v344 = v135 << 2;
    v136[11] = v344;
    int * v138 = v32->saved_regs;
    int * v139 = v32->regs;
    int v140 = v139[12];
    v138[12] = v140;
    int v142 = v32->timer;
    int v349 = v142 + 1;
    v32->timer = v349;
    int * v144 = v32->regs;
    int v145 = v144[11];
    bool v351 = (((int)((unsigned int)v69 >> 2)) & 3) == (((int)((unsigned int)v145 >> 2)) & 3);
    int v200;
    if (v351) {
      int v146 = v32->timer;
      int v352 = v146 + 1;
      v32->timer = v352;
      v200 = v71;
    } else {
      int * v149 = v32->cache_keys;
      int v150 = v149[0];
      bool v355 = v150 == ((int)((unsigned int)v145 >> 2));
      int v198;
      if (v355) {
        int * v151 = v32->cache_vals;
        int v152 = v151[0];
        v198 = v152;
      } else {
        int * v154 = v32->cache_keys;
        int v155 = v154[1];
        bool v360 = v155 == ((int)((unsigned int)v145 >> 2));
        int v196;
        if (v360) {
          int * v156 = v32->cache_vals;
          int v157 = v156[1];
          int * v158 = v32->cache_keys;
          int * v159 = v32->cache_keys;
          int v160 = v159[0];
          v158[1] = v160;
          int * v162 = v32->cache_vals;
          int * v163 = v32->cache_vals;
          int v164 = v163[0];
          v162[1] = v164;
          int * v166 = v32->cache_keys;
          int v369 = (int)((unsigned int)v145 >> 2);
          v166[0] = v369;
          int * v168 = v32->cache_vals;
          v168[0] = v157;
          int v170 = v32->timer;
          int v372 = v170 + 1;
          v32->timer = v372;
          v196 = v157;
        } else {
          int * v173 = v32->mem;
          int v374 = (int)((unsigned int)v145 >> 2);
          int v174 = v173[v374];
          int * v175 = v32->mem;
          int * v176 = v32->cache_keys;
          int v177 = v176[1];
          int * v178 = v32->cache_vals;
          int v179 = v178[1];
          v175[v177] = v179;
          int * v181 = v32->cache_keys;
          int * v182 = v32->cache_keys;
          int v183 = v182[0];
          v181[1] = v183;
          int * v185 = v32->cache_vals;
          int * v186 = v32->cache_vals;
          int v187 = v186[0];
          v185[1] = v187;
          int * v189 = v32->cache_keys;
          v189[0] = v374;
          int * v191 = v32->cache_vals;
          v191[0] = v174;
          int v193 = v32->timer;
          int v389 = v193 + 100;
          v32->timer = v389;
          v196 = v174;
        }
        v198 = v196;
      }
      v200 = v198;
    }
    int * v201 = v32->regs;
    v201[12] = v200;
    int * v203 = v32->cache_keys;
    int v204 = v203[0];
    bool v395 = v204 == ((int)((unsigned int)v69 >> 2));
    int v248;
    if (v395) {
      int * v205 = v32->cache_vals;
      v205[0] = v71;
      v248 = v71;
    } else {
      int * v208 = v32->cache_keys;
      int v209 = v208[1];
      bool v400 = v209 == ((int)((unsigned int)v69 >> 2));
      int v246;
      if (v400) {
        int * v210 = v32->cache_keys;
        int * v211 = v32->cache_keys;
        int v212 = v211[0];
        v210[1] = v212;
        int * v214 = v32->cache_vals;
        int * v215 = v32->cache_vals;
        int v216 = v215[0];
        v214[1] = v216;
        int * v218 = v32->cache_keys;
        int v408 = (int)((unsigned int)v69 >> 2);
        v218[0] = v408;
        int * v220 = v32->cache_vals;
        v220[0] = v71;
        int v222 = v32->timer;
        int v411 = v222 + 1;
        v32->timer = v411;
        v246 = v71;
      } else {
        int * v225 = v32->mem;
        int * v226 = v32->cache_keys;
        int v227 = v226[1];
        int * v228 = v32->cache_vals;
        int v229 = v228[1];
        v225[v227] = v229;
        int * v231 = v32->cache_keys;
        int * v232 = v32->cache_keys;
        int v233 = v232[0];
        v231[1] = v233;
        int * v235 = v32->cache_vals;
        int * v236 = v32->cache_vals;
        int v237 = v236[0];
        v235[1] = v237;
        int * v239 = v32->cache_keys;
        int v424 = (int)((unsigned int)v69 >> 2);
        v239[0] = v424;
        int * v241 = v32->cache_vals;
        v241[0] = v71;
        int v243 = v32->timer;
        int v427 = v243 + 100;
        v32->timer = v427;
        v246 = v71;
      }
      v248 = v246;
    }
    bool v429 = (((int)((unsigned int)v79 >> 2)) == ((int)((unsigned int)v69 >> 2))) | (((((int)((unsigned int)v145 >> 2)) & 3) == (((int)((unsigned int)v69 >> 2)) & 3)) & (!(((int)((unsigned int)v145 >> 2)) == ((int)((unsigned int)v69 >> 2)))));
    struct StateT * v262;
    if (v429) {
      int v249 = v32->timer;
      int v430 = v249 + 15;
      v32->timer = v430;
      int * v251 = v32->saved_regs;
      int v252 = v251[11];
      int * v253 = v32->regs;
      v253[11] = v252;
      int * v255 = v32->saved_regs;
      int v256 = v255[12];
      int * v257 = v32->regs;
      v257[12] = v256;
      struct StateT * v259 = slot_6(v32);
      v262 = v259;
    } else {
      v262 = v32;
    }
    v264 = v262;
  }
  return v264;
}

struct StateT * slot_7(struct StateT * v546) {
  int v547 = v546->timer;
  int v555 = v547 + 1;
  v546->timer = v555;
  int * v549 = v546->regs;
  int v550 = v549[11];
  int * v551 = v546->regs;
  int v559 = v550 << 2;
  v551[11] = v559;
  struct StateT * v553 = slot_8(v546);
  return v553;
}

struct StateT * slot_0(struct StateT * v2) {
  int v3 = v2->timer;
  int v11 = v3 + 1;
  v2->timer = v11;
  int * v5 = v2->regs;
  int v6 = v5[10];
  int * v7 = v2->regs;
  int v16 = v6 & 28;
  v7[5] = v16;
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