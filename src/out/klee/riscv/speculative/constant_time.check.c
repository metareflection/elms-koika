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
struct StateT * slot_14(struct StateT * v440);
struct StateT * slot_1(struct StateT * v15);
struct StateT * slot_5(struct StateT * v67);
struct StateT * slot_4(struct StateT * v54);
struct StateT * slot_13(struct StateT * v460);
struct StateT * slot_2(struct StateT * v28);
struct StateT * slot_3(struct StateT * v41);
struct StateT * slot_0(struct StateT * v2);
struct StateT * snippet(struct StateT * v0) {
  struct StateT * v1 = slot_0(v0);
  return v1;
}

struct StateT * slot_14(struct StateT * v440) {
  int v441 = v440->timer;
  int v451 = v441 + 1;
  v440->timer = v451;
  int * v443 = v440->regs;
  int v444 = v443[5];
  bool v454 = (v444 ^ -2147483648) < -2147483647;
  int v447;
  if (v454) {
    v447 = 1;
  } else {
    v447 = 0;
  }
  int * v448 = v440->regs;
  v448[11] = v447;
  return v440;
}

struct StateT * slot_1(struct StateT * v15) {
  int v16 = v15->timer;
  int v22 = v16 + 1;
  v15->timer = v22;
  int * v18 = v15->regs;
  v18[13] = 80;
  struct StateT * v20 = slot_2(v15);
  return v20;
}

struct StateT * slot_5(struct StateT * v67) {
  int * v68 = v67->saved_regs;
  int * v69 = v67->regs;
  int v70 = v69[6];
  v68[6] = v70;
  int v72 = v67->timer;
  int v282 = v72 + 1;
  v67->timer = v282;
  int * v74 = v67->regs;
  int v75 = v74[12];
  int * v76 = v67->regs;
  int v77 = v76[14];
  int * v78 = v67->regs;
  int v288 = v75 + v77;
  v78[6] = v288;
  int * v80 = v67->saved_regs;
  int * v81 = v67->regs;
  int v82 = v81[7];
  v80[7] = v82;
  int v84 = v67->timer;
  int v293 = v84 + 1;
  v67->timer = v293;
  int * v86 = v67->regs;
  int v87 = v86[6];
  int * v88 = v67->cache_keys;
  int v89 = v88[0];
  bool v297 = v89 == ((int)((unsigned int)v87 >> 2));
  int v137;
  if (v297) {
    int * v90 = v67->cache_vals;
    int v91 = v90[0];
    v137 = v91;
  } else {
    int * v93 = v67->cache_keys;
    int v94 = v93[1];
    bool v302 = v94 == ((int)((unsigned int)v87 >> 2));
    int v135;
    if (v302) {
      int * v95 = v67->cache_vals;
      int v96 = v95[1];
      int * v97 = v67->cache_keys;
      int * v98 = v67->cache_keys;
      int v99 = v98[0];
      v97[1] = v99;
      int * v101 = v67->cache_vals;
      int * v102 = v67->cache_vals;
      int v103 = v102[0];
      v101[1] = v103;
      int * v105 = v67->cache_keys;
      int v311 = (int)((unsigned int)v87 >> 2);
      v105[0] = v311;
      int * v107 = v67->cache_vals;
      v107[0] = v96;
      int v109 = v67->timer;
      int v314 = v109 + 1;
      v67->timer = v314;
      v135 = v96;
    } else {
      int * v112 = v67->mem;
      int v316 = (int)((unsigned int)v87 >> 2);
      int v113 = v112[v316];
      int * v114 = v67->mem;
      int * v115 = v67->cache_keys;
      int v116 = v115[1];
      int * v117 = v67->cache_vals;
      int v118 = v117[1];
      v114[v116] = v118;
      int * v120 = v67->cache_keys;
      int * v121 = v67->cache_keys;
      int v122 = v121[0];
      v120[1] = v122;
      int * v124 = v67->cache_vals;
      int * v125 = v67->cache_vals;
      int v126 = v125[0];
      v124[1] = v126;
      int * v128 = v67->cache_keys;
      v128[0] = v316;
      int * v130 = v67->cache_vals;
      v130[0] = v113;
      int v132 = v67->timer;
      int v331 = v132 + 100;
      v67->timer = v331;
      v135 = v113;
    }
    v137 = v135;
  }
  int * v138 = v67->regs;
  v138[7] = v137;
  int * v140 = v67->saved_regs;
  int * v141 = v67->regs;
  int v142 = v141[8];
  v140[8] = v142;
  int v144 = v67->timer;
  int v339 = v144 + 1;
  v67->timer = v339;
  int * v146 = v67->regs;
  int v147 = v146[13];
  int * v148 = v67->regs;
  int v149 = v148[14];
  int * v150 = v67->regs;
  int v344 = v147 + v149;
  v150[8] = v344;
  int * v152 = v67->saved_regs;
  int * v153 = v67->regs;
  int v154 = v153[9];
  v152[9] = v154;
  int v156 = v67->timer;
  int v349 = v156 + 1;
  v67->timer = v349;
  int * v158 = v67->regs;
  int v159 = v158[8];
  int * v160 = v67->cache_keys;
  int v161 = v160[0];
  bool v352 = v161 == ((int)((unsigned int)v159 >> 2));
  int v209;
  if (v352) {
    int * v162 = v67->cache_vals;
    int v163 = v162[0];
    v209 = v163;
  } else {
    int * v165 = v67->cache_keys;
    int v166 = v165[1];
    bool v357 = v166 == ((int)((unsigned int)v159 >> 2));
    int v207;
    if (v357) {
      int * v167 = v67->cache_vals;
      int v168 = v167[1];
      int * v169 = v67->cache_keys;
      int * v170 = v67->cache_keys;
      int v171 = v170[0];
      v169[1] = v171;
      int * v173 = v67->cache_vals;
      int * v174 = v67->cache_vals;
      int v175 = v174[0];
      v173[1] = v175;
      int * v177 = v67->cache_keys;
      int v366 = (int)((unsigned int)v159 >> 2);
      v177[0] = v366;
      int * v179 = v67->cache_vals;
      v179[0] = v168;
      int v181 = v67->timer;
      int v369 = v181 + 1;
      v67->timer = v369;
      v207 = v168;
    } else {
      int * v184 = v67->mem;
      int v371 = (int)((unsigned int)v159 >> 2);
      int v185 = v184[v371];
      int * v186 = v67->mem;
      int * v187 = v67->cache_keys;
      int v188 = v187[1];
      int * v189 = v67->cache_vals;
      int v190 = v189[1];
      v186[v188] = v190;
      int * v192 = v67->cache_keys;
      int * v193 = v67->cache_keys;
      int v194 = v193[0];
      v192[1] = v194;
      int * v196 = v67->cache_vals;
      int * v197 = v67->cache_vals;
      int v198 = v197[0];
      v196[1] = v198;
      int * v200 = v67->cache_keys;
      v200[0] = v371;
      int * v202 = v67->cache_vals;
      v202[0] = v185;
      int v204 = v67->timer;
      int v386 = v204 + 100;
      v67->timer = v386;
      v207 = v185;
    }
    v209 = v207;
  }
  int * v210 = v67->regs;
  v210[9] = v209;
  int * v212 = v67->saved_regs;
  int * v213 = v67->regs;
  int v214 = v213[16];
  v212[16] = v214;
  int v216 = v67->timer;
  int v394 = v216 + 1;
  v67->timer = v394;
  int * v218 = v67->regs;
  int v219 = v218[7];
  int * v220 = v67->regs;
  int v221 = v220[9];
  int * v222 = v67->regs;
  int v398 = v219 ^ v221;
  v222[16] = v398;
  int * v224 = v67->saved_regs;
  int * v225 = v67->regs;
  int v226 = v225[5];
  v224[5] = v226;
  int v228 = v67->timer;
  int v403 = v228 + 1;
  v67->timer = v403;
  int * v230 = v67->regs;
  int v231 = v230[5];
  int * v232 = v67->regs;
  int v233 = v232[16];
  int * v234 = v67->regs;
  int v407 = v231 | v233;
  v234[5] = v407;
  int * v236 = v67->regs;
  int v237 = v236[14];
  int * v238 = v67->regs;
  int v239 = v238[15];
  bool v411 = v237 >= v239;
  struct StateT * v276;
  if (v411) {
    int v240 = v67->timer;
    int v412 = v240 + 15;
    v67->timer = v412;
    int * v242 = v67->saved_regs;
    int v243 = v242[6];
    int * v244 = v67->regs;
    v244[6] = v243;
    int * v246 = v67->saved_regs;
    int v247 = v246[7];
    int * v248 = v67->regs;
    v248[7] = v247;
    int * v250 = v67->saved_regs;
    int v251 = v250[8];
    int * v252 = v67->regs;
    v252[8] = v251;
    int * v254 = v67->saved_regs;
    int v255 = v254[9];
    int * v256 = v67->regs;
    v256[9] = v255;
    int * v258 = v67->saved_regs;
    int v259 = v258[16];
    int * v260 = v67->regs;
    v260[16] = v259;
    int * v262 = v67->saved_regs;
    int v263 = v262[5];
    int * v264 = v67->regs;
    v264[5] = v263;
    struct StateT * v266 = slot_14(v67);
    v276 = v266;
  } else {
    int v268 = v67->timer;
    int v433 = v268 + 1;
    v67->timer = v433;
    int * v270 = v67->regs;
    int v271 = v270[14];
    int * v272 = v67->regs;
    int v436 = v271 + 4;
    v272[14] = v436;
    struct StateT * v274 = slot_13(v67);
    v276 = v274;
  }
  return v276;
}

struct StateT * slot_4(struct StateT * v54) {
  int v55 = v54->timer;
  int v61 = v55 + 1;
  v54->timer = v61;
  int * v57 = v54->regs;
  v57[5] = 0;
  struct StateT * v59 = slot_5(v54);
  return v59;
}

struct StateT * slot_13(struct StateT * v460) {
  int v461 = v460->timer;
  int v465 = v461 + 1;
  v460->timer = v465;
  struct StateT * v463 = slot_5(v460);
  return v463;
}

struct StateT * slot_2(struct StateT * v28) {
  int v29 = v28->timer;
  int v35 = v29 + 1;
  v28->timer = v35;
  int * v31 = v28->regs;
  v31[14] = 0;
  struct StateT * v33 = slot_3(v28);
  return v33;
}

struct StateT * slot_3(struct StateT * v41) {
  int v42 = v41->timer;
  int v48 = v42 + 1;
  v41->timer = v48;
  int * v44 = v41->regs;
  v44[15] = 16;
  struct StateT * v46 = slot_4(v41);
  return v46;
}

struct StateT * slot_0(struct StateT * v2) {
  int v3 = v2->timer;
  int v9 = v3 + 1;
  v2->timer = v9;
  int * v5 = v2->regs;
  v5[12] = 0;
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