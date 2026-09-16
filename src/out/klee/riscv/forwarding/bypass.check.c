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
struct StateT * slot_1(struct StateT * v19);
struct StateT * slot_6(struct StateT * v518);
struct StateT * slot_5(struct StateT * v502);
struct StateT * slot_4(struct StateT * v397);
struct StateT * slot_2(struct StateT * v35);
struct StateT * slot_3(struct StateT * v48);
struct StateT * slot_0(struct StateT * v2);
struct StateT * snippet(struct StateT * v0) {
  struct StateT * v1 = slot_0(v0);
  return v1;
}

struct StateT * slot_1(struct StateT * v19) {
  int v20 = v19->timer;
  int v28 = v20 + 1;
  v19->timer = v28;
  int * v22 = v19->regs;
  int v23 = v22[6];
  int * v24 = v19->regs;
  int v32 = v23 + 80;
  v24[6] = v32;
  struct StateT * v26 = slot_2(v19);
  return v26;
}

struct StateT * slot_6(struct StateT * v518) {
  int v519 = v518->timer;
  int v576 = v519 + 1;
  v518->timer = v576;
  int * v521 = v518->regs;
  int v522 = v521[11];
  int * v523 = v518->cache_keys;
  int v524 = v523[0];
  bool v581 = v524 == ((int)((unsigned int)v522 >> 2));
  int v572;
  if (v581) {
    int * v525 = v518->cache_vals;
    int v526 = v525[0];
    v572 = v526;
  } else {
    int * v528 = v518->cache_keys;
    int v529 = v528[1];
    bool v586 = v529 == ((int)((unsigned int)v522 >> 2));
    int v570;
    if (v586) {
      int * v530 = v518->cache_vals;
      int v531 = v530[1];
      int * v532 = v518->cache_keys;
      int * v533 = v518->cache_keys;
      int v534 = v533[0];
      v532[1] = v534;
      int * v536 = v518->cache_vals;
      int * v537 = v518->cache_vals;
      int v538 = v537[0];
      v536[1] = v538;
      int * v540 = v518->cache_keys;
      int v595 = (int)((unsigned int)v522 >> 2);
      v540[0] = v595;
      int * v542 = v518->cache_vals;
      v542[0] = v531;
      int v544 = v518->timer;
      int v598 = v544 + 1;
      v518->timer = v598;
      v570 = v531;
    } else {
      int * v547 = v518->mem;
      int v600 = (int)((unsigned int)v522 >> 2);
      int v548 = v547[v600];
      int * v549 = v518->mem;
      int * v550 = v518->cache_keys;
      int v551 = v550[1];
      int * v552 = v518->cache_vals;
      int v553 = v552[1];
      v549[v551] = v553;
      int * v555 = v518->cache_keys;
      int * v556 = v518->cache_keys;
      int v557 = v556[0];
      v555[1] = v557;
      int * v559 = v518->cache_vals;
      int * v560 = v518->cache_vals;
      int v561 = v560[0];
      v559[1] = v561;
      int * v563 = v518->cache_keys;
      v563[0] = v600;
      int * v565 = v518->cache_vals;
      v565[0] = v548;
      int v567 = v518->timer;
      int v615 = v567 + 100;
      v518->timer = v615;
      v570 = v548;
    }
    v572 = v570;
  }
  int * v573 = v518->regs;
  v573[12] = v572;
  return v518;
}

struct StateT * slot_5(struct StateT * v502) {
  int v503 = v502->timer;
  int v511 = v503 + 1;
  v502->timer = v511;
  int * v505 = v502->regs;
  int v506 = v505[11];
  int * v507 = v502->regs;
  int v515 = v506 << 2;
  v507[11] = v515;
  struct StateT * v509 = slot_6(v502);
  return v509;
}

struct StateT * slot_4(struct StateT * v397) {
  int v398 = v397->timer;
  int v456 = v398 + 1;
  v397->timer = v456;
  int * v400 = v397->regs;
  int v401 = v400[6];
  int * v402 = v397->cache_keys;
  int v403 = v402[0];
  bool v461 = v403 == ((int)((unsigned int)v401 >> 2));
  int v451;
  if (v461) {
    int * v404 = v397->cache_vals;
    int v405 = v404[0];
    v451 = v405;
  } else {
    int * v407 = v397->cache_keys;
    int v408 = v407[1];
    bool v466 = v408 == ((int)((unsigned int)v401 >> 2));
    int v449;
    if (v466) {
      int * v409 = v397->cache_vals;
      int v410 = v409[1];
      int * v411 = v397->cache_keys;
      int * v412 = v397->cache_keys;
      int v413 = v412[0];
      v411[1] = v413;
      int * v415 = v397->cache_vals;
      int * v416 = v397->cache_vals;
      int v417 = v416[0];
      v415[1] = v417;
      int * v419 = v397->cache_keys;
      int v475 = (int)((unsigned int)v401 >> 2);
      v419[0] = v475;
      int * v421 = v397->cache_vals;
      v421[0] = v410;
      int v423 = v397->timer;
      int v478 = v423 + 1;
      v397->timer = v478;
      v449 = v410;
    } else {
      int * v426 = v397->mem;
      int v480 = (int)((unsigned int)v401 >> 2);
      int v427 = v426[v480];
      int * v428 = v397->mem;
      int * v429 = v397->cache_keys;
      int v430 = v429[1];
      int * v431 = v397->cache_vals;
      int v432 = v431[1];
      v428[v430] = v432;
      int * v434 = v397->cache_keys;
      int * v435 = v397->cache_keys;
      int v436 = v435[0];
      v434[1] = v436;
      int * v438 = v397->cache_vals;
      int * v439 = v397->cache_vals;
      int v440 = v439[0];
      v438[1] = v440;
      int * v442 = v397->cache_keys;
      v442[0] = v480;
      int * v444 = v397->cache_vals;
      v444[0] = v427;
      int v446 = v397->timer;
      int v495 = v446 + 100;
      v397->timer = v495;
      v449 = v427;
    }
    v451 = v449;
  }
  int * v452 = v397->regs;
  v452[11] = v451;
  struct StateT * v454 = slot_5(v397);
  return v454;
}

struct StateT * slot_2(struct StateT * v35) {
  int v36 = v35->timer;
  int v42 = v36 + 1;
  v35->timer = v42;
  int * v38 = v35->regs;
  v38[7] = 0;
  struct StateT * v40 = slot_3(v35);
  return v40;
}

struct StateT * slot_3(struct StateT * v48) {
  int v49 = v48->timer;
  int v247 = v49 + 1;
  v48->timer = v247;
  int * v51 = v48->regs;
  int v52 = v51[6];
  int * v53 = v48->regs;
  int v54 = v53[7];
  int * v55 = v48->saved_regs;
  int * v56 = v48->regs;
  int v57 = v56[11];
  v55[11] = v57;
  int v59 = v48->timer;
  int v256 = v59 + 1;
  v48->timer = v256;
  int * v61 = v48->regs;
  int v62 = v61[6];
  int * v63 = v48->cache_keys;
  int v64 = v63[0];
  bool v260 = v64 == ((int)((unsigned int)v62 >> 2));
  int v112;
  if (v260) {
    int * v65 = v48->cache_vals;
    int v66 = v65[0];
    v112 = v66;
  } else {
    int * v68 = v48->cache_keys;
    int v69 = v68[1];
    bool v265 = v69 == ((int)((unsigned int)v62 >> 2));
    int v110;
    if (v265) {
      int * v70 = v48->cache_vals;
      int v71 = v70[1];
      int * v72 = v48->cache_keys;
      int * v73 = v48->cache_keys;
      int v74 = v73[0];
      v72[1] = v74;
      int * v76 = v48->cache_vals;
      int * v77 = v48->cache_vals;
      int v78 = v77[0];
      v76[1] = v78;
      int * v80 = v48->cache_keys;
      int v274 = (int)((unsigned int)v62 >> 2);
      v80[0] = v274;
      int * v82 = v48->cache_vals;
      v82[0] = v71;
      int v84 = v48->timer;
      int v277 = v84 + 1;
      v48->timer = v277;
      v110 = v71;
    } else {
      int * v87 = v48->mem;
      int v279 = (int)((unsigned int)v62 >> 2);
      int v88 = v87[v279];
      int * v89 = v48->mem;
      int * v90 = v48->cache_keys;
      int v91 = v90[1];
      int * v92 = v48->cache_vals;
      int v93 = v92[1];
      v89[v91] = v93;
      int * v95 = v48->cache_keys;
      int * v96 = v48->cache_keys;
      int v97 = v96[0];
      v95[1] = v97;
      int * v99 = v48->cache_vals;
      int * v100 = v48->cache_vals;
      int v101 = v100[0];
      v99[1] = v101;
      int * v103 = v48->cache_keys;
      v103[0] = v279;
      int * v105 = v48->cache_vals;
      v105[0] = v88;
      int v107 = v48->timer;
      int v294 = v107 + 100;
      v48->timer = v294;
      v110 = v88;
    }
    v112 = v110;
  }
  int * v113 = v48->regs;
  v113[11] = v112;
  int v115 = v48->timer;
  int v298 = v115 + 1;
  v48->timer = v298;
  int * v117 = v48->regs;
  int v118 = v117[11];
  int * v119 = v48->regs;
  int v301 = v118 << 2;
  v119[11] = v301;
  int * v121 = v48->saved_regs;
  int * v122 = v48->regs;
  int v123 = v122[12];
  v121[12] = v123;
  int v125 = v48->timer;
  int v306 = v125 + 1;
  v48->timer = v306;
  int * v127 = v48->regs;
  int v128 = v127[11];
  bool v308 = (((int)((unsigned int)v52 >> 2)) & 3) == (((int)((unsigned int)v128 >> 2)) & 3);
  int v183;
  if (v308) {
    int v129 = v48->timer;
    int v309 = v129 + 1;
    v48->timer = v309;
    v183 = v54;
  } else {
    int * v132 = v48->cache_keys;
    int v133 = v132[0];
    bool v312 = v133 == ((int)((unsigned int)v128 >> 2));
    int v181;
    if (v312) {
      int * v134 = v48->cache_vals;
      int v135 = v134[0];
      v181 = v135;
    } else {
      int * v137 = v48->cache_keys;
      int v138 = v137[1];
      bool v317 = v138 == ((int)((unsigned int)v128 >> 2));
      int v179;
      if (v317) {
        int * v139 = v48->cache_vals;
        int v140 = v139[1];
        int * v141 = v48->cache_keys;
        int * v142 = v48->cache_keys;
        int v143 = v142[0];
        v141[1] = v143;
        int * v145 = v48->cache_vals;
        int * v146 = v48->cache_vals;
        int v147 = v146[0];
        v145[1] = v147;
        int * v149 = v48->cache_keys;
        int v326 = (int)((unsigned int)v128 >> 2);
        v149[0] = v326;
        int * v151 = v48->cache_vals;
        v151[0] = v140;
        int v153 = v48->timer;
        int v329 = v153 + 1;
        v48->timer = v329;
        v179 = v140;
      } else {
        int * v156 = v48->mem;
        int v331 = (int)((unsigned int)v128 >> 2);
        int v157 = v156[v331];
        int * v158 = v48->mem;
        int * v159 = v48->cache_keys;
        int v160 = v159[1];
        int * v161 = v48->cache_vals;
        int v162 = v161[1];
        v158[v160] = v162;
        int * v164 = v48->cache_keys;
        int * v165 = v48->cache_keys;
        int v166 = v165[0];
        v164[1] = v166;
        int * v168 = v48->cache_vals;
        int * v169 = v48->cache_vals;
        int v170 = v169[0];
        v168[1] = v170;
        int * v172 = v48->cache_keys;
        v172[0] = v331;
        int * v174 = v48->cache_vals;
        v174[0] = v157;
        int v176 = v48->timer;
        int v346 = v176 + 100;
        v48->timer = v346;
        v179 = v157;
      }
      v181 = v179;
    }
    v183 = v181;
  }
  int * v184 = v48->regs;
  v184[12] = v183;
  int * v186 = v48->cache_keys;
  int v187 = v186[0];
  bool v352 = v187 == ((int)((unsigned int)v52 >> 2));
  int v231;
  if (v352) {
    int * v188 = v48->cache_vals;
    v188[0] = v54;
    v231 = v54;
  } else {
    int * v191 = v48->cache_keys;
    int v192 = v191[1];
    bool v357 = v192 == ((int)((unsigned int)v52 >> 2));
    int v229;
    if (v357) {
      int * v193 = v48->cache_keys;
      int * v194 = v48->cache_keys;
      int v195 = v194[0];
      v193[1] = v195;
      int * v197 = v48->cache_vals;
      int * v198 = v48->cache_vals;
      int v199 = v198[0];
      v197[1] = v199;
      int * v201 = v48->cache_keys;
      int v365 = (int)((unsigned int)v52 >> 2);
      v201[0] = v365;
      int * v203 = v48->cache_vals;
      v203[0] = v54;
      int v205 = v48->timer;
      int v368 = v205 + 1;
      v48->timer = v368;
      v229 = v54;
    } else {
      int * v208 = v48->mem;
      int * v209 = v48->cache_keys;
      int v210 = v209[1];
      int * v211 = v48->cache_vals;
      int v212 = v211[1];
      v208[v210] = v212;
      int * v214 = v48->cache_keys;
      int * v215 = v48->cache_keys;
      int v216 = v215[0];
      v214[1] = v216;
      int * v218 = v48->cache_vals;
      int * v219 = v48->cache_vals;
      int v220 = v219[0];
      v218[1] = v220;
      int * v222 = v48->cache_keys;
      int v381 = (int)((unsigned int)v52 >> 2);
      v222[0] = v381;
      int * v224 = v48->cache_vals;
      v224[0] = v54;
      int v226 = v48->timer;
      int v384 = v226 + 100;
      v48->timer = v384;
      v229 = v54;
    }
    v231 = v229;
  }
  bool v386 = (((int)((unsigned int)v62 >> 2)) == ((int)((unsigned int)v52 >> 2))) | (((((int)((unsigned int)v128 >> 2)) & 3) == (((int)((unsigned int)v52 >> 2)) & 3)) & (!(((int)((unsigned int)v128 >> 2)) == ((int)((unsigned int)v52 >> 2)))));
  struct StateT * v245;
  if (v386) {
    int v232 = v48->timer;
    int v387 = v232 + 15;
    v48->timer = v387;
    int * v234 = v48->saved_regs;
    int v235 = v234[11];
    int * v236 = v48->regs;
    v236[11] = v235;
    int * v238 = v48->saved_regs;
    int v239 = v238[12];
    int * v240 = v48->regs;
    v240[12] = v239;
    struct StateT * v242 = slot_4(v48);
    v245 = v242;
  } else {
    v245 = v48;
  }
  return v245;
}

struct StateT * slot_0(struct StateT * v2) {
  int v3 = v2->timer;
  int v11 = v3 + 1;
  v2->timer = v11;
  int * v5 = v2->regs;
  int v6 = v5[10];
  int * v7 = v2->regs;
  int v16 = v6 & 28;
  v7[6] = v16;
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