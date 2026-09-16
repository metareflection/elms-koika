// verify: clean (KLEE should report no failing assertion) [budget 120s]
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
struct StateT * slot_8(struct StateT * v554);
struct StateT * slot_9(struct StateT * v546);
struct StateT * slot_2(struct StateT * v28);
struct StateT * slot_7(struct StateT * v441);
struct StateT * slot_3(struct StateT * v41);
struct StateT * slot_0(struct StateT * v2);
struct StateT * snippet(struct StateT * v0) {
  struct StateT * v1 = slot_0(v0);
  return v1;
}

struct StateT * slot_1(struct StateT * v15) {
  int v16 = v15->timer;
  int v22 = v16 + 1;
  v15->timer = v22;
  int * v18 = v15->regs;
  v18[7] = 16;
  struct StateT * v20 = slot_2(v15);
  return v20;
}

struct StateT * slot_8(struct StateT * v554) {
  int v555 = v554->timer;
  int v563 = v555 + 1;
  v554->timer = v563;
  int * v557 = v554->regs;
  int v558 = v557[6];
  int * v559 = v554->regs;
  int v567 = v558 + 4;
  v559[6] = v567;
  struct StateT * v561 = slot_9(v554);
  return v561;
}

struct StateT * slot_9(struct StateT * v546) {
  int v547 = v546->timer;
  int v551 = v547 + 1;
  v546->timer = v551;
  struct StateT * v549 = slot_3(v546);
  return v549;
}

struct StateT * slot_2(struct StateT * v28) {
  int v29 = v28->timer;
  int v35 = v29 + 1;
  v28->timer = v35;
  int * v31 = v28->regs;
  v31[9] = 80;
  struct StateT * v33 = slot_3(v28);
  return v33;
}

struct StateT * slot_7(struct StateT * v441) {
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
  struct StateT * v498 = slot_8(v441);
  return v498;
}

struct StateT * slot_3(struct StateT * v41) {
  int * v42 = v41->saved_regs;
  int * v43 = v41->regs;
  int v44 = v43[8];
  v42[8] = v44;
  int v46 = v41->timer;
  int v273 = v46 + 1;
  v41->timer = v273;
  int * v48 = v41->regs;
  int v49 = v48[9];
  int * v50 = v41->regs;
  int v51 = v50[6];
  int * v52 = v41->regs;
  int v279 = v49 + v51;
  v52[8] = v279;
  int * v54 = v41->saved_regs;
  int * v55 = v41->regs;
  int v56 = v55[5];
  v54[5] = v56;
  int v58 = v41->timer;
  int v284 = v58 + 1;
  v41->timer = v284;
  int * v60 = v41->regs;
  int v61 = v60[8];
  int * v62 = v41->cache_keys;
  int v63 = v62[0];
  bool v288 = v63 == ((int)((unsigned int)v61 >> 2));
  int v111;
  if (v288) {
    int * v64 = v41->cache_vals;
    int v65 = v64[0];
    v111 = v65;
  } else {
    int * v67 = v41->cache_keys;
    int v68 = v67[1];
    bool v293 = v68 == ((int)((unsigned int)v61 >> 2));
    int v109;
    if (v293) {
      int * v69 = v41->cache_vals;
      int v70 = v69[1];
      int * v71 = v41->cache_keys;
      int * v72 = v41->cache_keys;
      int v73 = v72[0];
      v71[1] = v73;
      int * v75 = v41->cache_vals;
      int * v76 = v41->cache_vals;
      int v77 = v76[0];
      v75[1] = v77;
      int * v79 = v41->cache_keys;
      int v302 = (int)((unsigned int)v61 >> 2);
      v79[0] = v302;
      int * v81 = v41->cache_vals;
      v81[0] = v70;
      int v83 = v41->timer;
      int v305 = v83 + 1;
      v41->timer = v305;
      v109 = v70;
    } else {
      int * v86 = v41->mem;
      int v307 = (int)((unsigned int)v61 >> 2);
      int v87 = v86[v307];
      int * v88 = v41->mem;
      int * v89 = v41->cache_keys;
      int v90 = v89[1];
      int * v91 = v41->cache_vals;
      int v92 = v91[1];
      v88[v90] = v92;
      int * v94 = v41->cache_keys;
      int * v95 = v41->cache_keys;
      int v96 = v95[0];
      v94[1] = v96;
      int * v98 = v41->cache_vals;
      int * v99 = v41->cache_vals;
      int v100 = v99[0];
      v98[1] = v100;
      int * v102 = v41->cache_keys;
      v102[0] = v307;
      int * v104 = v41->cache_vals;
      v104[0] = v87;
      int v106 = v41->timer;
      int v322 = v106 + 100;
      v41->timer = v322;
      v109 = v87;
    }
    v111 = v109;
  }
  int * v112 = v41->regs;
  v112[5] = v111;
  int * v114 = v41->regs;
  int v115 = v114[6];
  int * v116 = v41->regs;
  int v117 = v116[7];
  bool v329 = v115 >= v117;
  struct StateT * v267;
  if (v329) {
    int v118 = v41->timer;
    int v330 = v118 + 15;
    v41->timer = v330;
    int * v120 = v41->saved_regs;
    int v121 = v120[8];
    int * v122 = v41->regs;
    v122[8] = v121;
    int * v124 = v41->saved_regs;
    int v125 = v124[5];
    int * v126 = v41->regs;
    v126[5] = v125;
    v267 = v41;
  } else {
    int v129 = v41->timer;
    int v337 = v129 + 1;
    v41->timer = v337;
    int * v131 = v41->regs;
    int v132 = v131[6];
    int * v133 = v41->regs;
    int v134 = v133[5];
    int * v135 = v41->saved_regs;
    int * v136 = v41->regs;
    int v137 = v136[11];
    v135[11] = v137;
    int v139 = v41->timer;
    int v344 = v139 + 1;
    v41->timer = v344;
    int * v141 = v41->regs;
    int v142 = v141[6];
    int * v143 = v41->cache_keys;
    int v144 = v143[0];
    bool v347 = v144 == ((int)((unsigned int)v142 >> 2));
    int v192;
    if (v347) {
      int * v145 = v41->cache_vals;
      int v146 = v145[0];
      v192 = v146;
    } else {
      int * v148 = v41->cache_keys;
      int v149 = v148[1];
      bool v352 = v149 == ((int)((unsigned int)v142 >> 2));
      int v190;
      if (v352) {
        int * v150 = v41->cache_vals;
        int v151 = v150[1];
        int * v152 = v41->cache_keys;
        int * v153 = v41->cache_keys;
        int v154 = v153[0];
        v152[1] = v154;
        int * v156 = v41->cache_vals;
        int * v157 = v41->cache_vals;
        int v158 = v157[0];
        v156[1] = v158;
        int * v160 = v41->cache_keys;
        int v361 = (int)((unsigned int)v142 >> 2);
        v160[0] = v361;
        int * v162 = v41->cache_vals;
        v162[0] = v151;
        int v164 = v41->timer;
        int v364 = v164 + 1;
        v41->timer = v364;
        v190 = v151;
      } else {
        int * v167 = v41->mem;
        int v366 = (int)((unsigned int)v142 >> 2);
        int v168 = v167[v366];
        int * v169 = v41->mem;
        int * v170 = v41->cache_keys;
        int v171 = v170[1];
        int * v172 = v41->cache_vals;
        int v173 = v172[1];
        v169[v171] = v173;
        int * v175 = v41->cache_keys;
        int * v176 = v41->cache_keys;
        int v177 = v176[0];
        v175[1] = v177;
        int * v179 = v41->cache_vals;
        int * v180 = v41->cache_vals;
        int v181 = v180[0];
        v179[1] = v181;
        int * v183 = v41->cache_keys;
        v183[0] = v366;
        int * v185 = v41->cache_vals;
        v185[0] = v168;
        int v187 = v41->timer;
        int v381 = v187 + 100;
        v41->timer = v381;
        v190 = v168;
      }
      v192 = v190;
    }
    int * v193 = v41->regs;
    v193[11] = v192;
    int * v195 = v41->saved_regs;
    int * v196 = v41->regs;
    int v197 = v196[6];
    v195[6] = v197;
    int v199 = v41->timer;
    int v388 = v199 + 1;
    v41->timer = v388;
    int * v201 = v41->regs;
    int v202 = v201[6];
    int * v203 = v41->regs;
    int v391 = v202 + 4;
    v203[6] = v391;
    int * v205 = v41->cache_keys;
    int v206 = v205[0];
    bool v393 = v206 == ((int)((unsigned int)v132 >> 2));
    int v250;
    if (v393) {
      int * v207 = v41->cache_vals;
      v207[0] = v134;
      v250 = v134;
    } else {
      int * v210 = v41->cache_keys;
      int v211 = v210[1];
      bool v398 = v211 == ((int)((unsigned int)v132 >> 2));
      int v248;
      if (v398) {
        int * v212 = v41->cache_keys;
        int * v213 = v41->cache_keys;
        int v214 = v213[0];
        v212[1] = v214;
        int * v216 = v41->cache_vals;
        int * v217 = v41->cache_vals;
        int v218 = v217[0];
        v216[1] = v218;
        int * v220 = v41->cache_keys;
        int v406 = (int)((unsigned int)v132 >> 2);
        v220[0] = v406;
        int * v222 = v41->cache_vals;
        v222[0] = v134;
        int v224 = v41->timer;
        int v409 = v224 + 1;
        v41->timer = v409;
        v248 = v134;
      } else {
        int * v227 = v41->mem;
        int * v228 = v41->cache_keys;
        int v229 = v228[1];
        int * v230 = v41->cache_vals;
        int v231 = v230[1];
        v227[v229] = v231;
        int * v233 = v41->cache_keys;
        int * v234 = v41->cache_keys;
        int v235 = v234[0];
        v233[1] = v235;
        int * v237 = v41->cache_vals;
        int * v238 = v41->cache_vals;
        int v239 = v238[0];
        v237[1] = v239;
        int * v241 = v41->cache_keys;
        int v422 = (int)((unsigned int)v132 >> 2);
        v241[0] = v422;
        int * v243 = v41->cache_vals;
        v243[0] = v134;
        int v245 = v41->timer;
        int v425 = v245 + 100;
        v41->timer = v425;
        v248 = v134;
      }
      v250 = v248;
    }
    bool v427 = ((int)((unsigned int)v142 >> 2)) == ((int)((unsigned int)v132 >> 2));
    struct StateT * v265;
    if (v427) {
      int v251 = v41->timer;
      int v428 = v251 + 15;
      v41->timer = v428;
      int * v253 = v41->saved_regs;
      int v254 = v253[11];
      int * v255 = v41->regs;
      v255[11] = v254;
      int * v257 = v41->saved_regs;
      int v258 = v257[6];
      int * v259 = v41->regs;
      v259[6] = v258;
      struct StateT * v261 = slot_7(v41);
      v265 = v261;
    } else {
      struct StateT * v263 = slot_9(v41);
      v265 = v263;
    }
    v267 = v265;
  }
  return v267;
}

struct StateT * slot_0(struct StateT * v2) {
  int v3 = v2->timer;
  int v9 = v3 + 1;
  v2->timer = v9;
  int * v5 = v2->regs;
  v5[6] = 0;
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