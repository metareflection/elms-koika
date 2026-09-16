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

struct StateT * slot_5(struct StateT * v84);
struct StateT * slot_2(struct StateT * v32);
struct StateT * slot_7(struct StateT * v121);
struct StateT * slot_3(struct StateT * v40);
struct StateT * snippet(struct StateT * v0);
struct StateT * slot_10(struct StateT * v340);
struct StateT * slot_1(struct StateT * v19);
struct StateT * slot_8(struct StateT * v219);
struct StateT * slot_4(struct StateT * v64);
struct StateT * slot_9(struct StateT * v324);
struct StateT * slot_0(struct StateT * v2);
struct StateT * slot_5(struct StateT * v84) {
  int * v85 = v84->regs;
  int v86 = v85[5];
  int * v87 = v84->regs;
  int v88 = v87[9];
  bool v108 = v86 >= v88;
  struct StateT * v102;
  if (v108) {
    int v89 = v84->timer;
    int v109 = v89 + 15;
    v84->timer = v109;
    int * v91 = v84->saved_regs;
    int v92 = v91[6];
    int * v93 = v84->regs;
    v93[6] = v92;
    int * v95 = v84->saved_regs;
    int v96 = v95[7];
    int * v97 = v84->regs;
    v97[7] = v96;
    v102 = v84;
  } else {
    struct StateT * v100 = slot_7(v84);
    v102 = v100;
  }
  return v102;
}

struct StateT * slot_2(struct StateT * v32) {
  int v33 = v32->timer;
  int v37 = v33 + 1;
  v32->timer = v37;
  struct StateT * v35 = slot_3(v32);
  return v35;
}

struct StateT * slot_7(struct StateT * v121) {
  int v122 = v121->timer;
  int v176 = v122 + 1;
  v121->timer = v176;
  int * v124 = v121->regs;
  int v125 = v124[6];
  int * v126 = v121->regs;
  int v127 = v126[7];
  int * v128 = v121->cache_keys;
  int v129 = v128[0];
  bool v183 = v129 == ((int)((unsigned int)v125 >> 2));
  int v173;
  if (v183) {
    int * v130 = v121->cache_vals;
    v130[0] = v127;
    v173 = v127;
  } else {
    int * v133 = v121->cache_keys;
    int v134 = v133[1];
    bool v188 = v134 == ((int)((unsigned int)v125 >> 2));
    int v171;
    if (v188) {
      int * v135 = v121->cache_keys;
      int * v136 = v121->cache_keys;
      int v137 = v136[0];
      v135[1] = v137;
      int * v139 = v121->cache_vals;
      int * v140 = v121->cache_vals;
      int v141 = v140[0];
      v139[1] = v141;
      int * v143 = v121->cache_keys;
      int v196 = (int)((unsigned int)v125 >> 2);
      v143[0] = v196;
      int * v145 = v121->cache_vals;
      v145[0] = v127;
      int v147 = v121->timer;
      int v199 = v147 + 1;
      v121->timer = v199;
      v171 = v127;
    } else {
      int * v150 = v121->mem;
      int * v151 = v121->cache_keys;
      int v152 = v151[1];
      int * v153 = v121->cache_vals;
      int v154 = v153[1];
      v150[v152] = v154;
      int * v156 = v121->cache_keys;
      int * v157 = v121->cache_keys;
      int v158 = v157[0];
      v156[1] = v158;
      int * v160 = v121->cache_vals;
      int * v161 = v121->cache_vals;
      int v162 = v161[0];
      v160[1] = v162;
      int * v164 = v121->cache_keys;
      int v212 = (int)((unsigned int)v125 >> 2);
      v164[0] = v212;
      int * v166 = v121->cache_vals;
      v166[0] = v127;
      int v168 = v121->timer;
      int v215 = v168 + 100;
      v121->timer = v215;
      v171 = v127;
    }
    v173 = v171;
  }
  struct StateT * v174 = slot_8(v121);
  return v174;
}

struct StateT * slot_3(struct StateT * v40) {
  int * v41 = v40->saved_regs;
  int * v42 = v40->regs;
  int v43 = v42[6];
  v41[6] = v43;
  int v45 = v40->timer;
  int v57 = v45 + 1;
  v40->timer = v57;
  int * v47 = v40->regs;
  int v48 = v47[5];
  int * v49 = v40->regs;
  int v61 = v48 + 80;
  v49[6] = v61;
  struct StateT * v51 = slot_4(v40);
  return v51;
}

struct StateT * snippet(struct StateT * v0) {
  struct StateT * v1 = slot_0(v0);
  return v1;
}

struct StateT * slot_10(struct StateT * v340) {
  int v341 = v340->timer;
  int v398 = v341 + 1;
  v340->timer = v398;
  int * v343 = v340->regs;
  int v344 = v343[11];
  int * v345 = v340->cache_keys;
  int v346 = v345[0];
  bool v403 = v346 == ((int)((unsigned int)v344 >> 2));
  int v394;
  if (v403) {
    int * v347 = v340->cache_vals;
    int v348 = v347[0];
    v394 = v348;
  } else {
    int * v350 = v340->cache_keys;
    int v351 = v350[1];
    bool v408 = v351 == ((int)((unsigned int)v344 >> 2));
    int v392;
    if (v408) {
      int * v352 = v340->cache_vals;
      int v353 = v352[1];
      int * v354 = v340->cache_keys;
      int * v355 = v340->cache_keys;
      int v356 = v355[0];
      v354[1] = v356;
      int * v358 = v340->cache_vals;
      int * v359 = v340->cache_vals;
      int v360 = v359[0];
      v358[1] = v360;
      int * v362 = v340->cache_keys;
      int v417 = (int)((unsigned int)v344 >> 2);
      v362[0] = v417;
      int * v364 = v340->cache_vals;
      v364[0] = v353;
      int v366 = v340->timer;
      int v420 = v366 + 1;
      v340->timer = v420;
      v392 = v353;
    } else {
      int * v369 = v340->mem;
      int v422 = (int)((unsigned int)v344 >> 2);
      int v370 = v369[v422];
      int * v371 = v340->mem;
      int * v372 = v340->cache_keys;
      int v373 = v372[1];
      int * v374 = v340->cache_vals;
      int v375 = v374[1];
      v371[v373] = v375;
      int * v377 = v340->cache_keys;
      int * v378 = v340->cache_keys;
      int v379 = v378[0];
      v377[1] = v379;
      int * v381 = v340->cache_vals;
      int * v382 = v340->cache_vals;
      int v383 = v382[0];
      v381[1] = v383;
      int * v385 = v340->cache_keys;
      v385[0] = v422;
      int * v387 = v340->cache_vals;
      v387[0] = v370;
      int v389 = v340->timer;
      int v437 = v389 + 100;
      v340->timer = v437;
      v392 = v370;
    }
    v394 = v392;
  }
  int * v395 = v340->regs;
  v395[12] = v394;
  return v340;
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

struct StateT * slot_8(struct StateT * v219) {
  int v220 = v219->timer;
  int v278 = v220 + 1;
  v219->timer = v278;
  int * v222 = v219->regs;
  int v223 = v222[6];
  int * v224 = v219->cache_keys;
  int v225 = v224[0];
  bool v283 = v225 == ((int)((unsigned int)v223 >> 2));
  int v273;
  if (v283) {
    int * v226 = v219->cache_vals;
    int v227 = v226[0];
    v273 = v227;
  } else {
    int * v229 = v219->cache_keys;
    int v230 = v229[1];
    bool v288 = v230 == ((int)((unsigned int)v223 >> 2));
    int v271;
    if (v288) {
      int * v231 = v219->cache_vals;
      int v232 = v231[1];
      int * v233 = v219->cache_keys;
      int * v234 = v219->cache_keys;
      int v235 = v234[0];
      v233[1] = v235;
      int * v237 = v219->cache_vals;
      int * v238 = v219->cache_vals;
      int v239 = v238[0];
      v237[1] = v239;
      int * v241 = v219->cache_keys;
      int v297 = (int)((unsigned int)v223 >> 2);
      v241[0] = v297;
      int * v243 = v219->cache_vals;
      v243[0] = v232;
      int v245 = v219->timer;
      int v300 = v245 + 1;
      v219->timer = v300;
      v271 = v232;
    } else {
      int * v248 = v219->mem;
      int v302 = (int)((unsigned int)v223 >> 2);
      int v249 = v248[v302];
      int * v250 = v219->mem;
      int * v251 = v219->cache_keys;
      int v252 = v251[1];
      int * v253 = v219->cache_vals;
      int v254 = v253[1];
      v250[v252] = v254;
      int * v256 = v219->cache_keys;
      int * v257 = v219->cache_keys;
      int v258 = v257[0];
      v256[1] = v258;
      int * v260 = v219->cache_vals;
      int * v261 = v219->cache_vals;
      int v262 = v261[0];
      v260[1] = v262;
      int * v264 = v219->cache_keys;
      v264[0] = v302;
      int * v266 = v219->cache_vals;
      v266[0] = v249;
      int v268 = v219->timer;
      int v317 = v268 + 100;
      v219->timer = v317;
      v271 = v249;
    }
    v273 = v271;
  }
  int * v274 = v219->regs;
  v274[11] = v273;
  struct StateT * v276 = slot_9(v219);
  return v276;
}

struct StateT * slot_4(struct StateT * v64) {
  int * v65 = v64->saved_regs;
  int * v66 = v64->regs;
  int v67 = v66[7];
  v65[7] = v67;
  int v69 = v64->timer;
  int v79 = v69 + 1;
  v64->timer = v79;
  int * v71 = v64->regs;
  v71[7] = 0;
  struct StateT * v73 = slot_5(v64);
  return v73;
}

struct StateT * slot_9(struct StateT * v324) {
  int v325 = v324->timer;
  int v333 = v325 + 1;
  v324->timer = v333;
  int * v327 = v324->regs;
  int v328 = v327[11];
  int * v329 = v324->regs;
  int v337 = v328 << 2;
  v329[11] = v337;
  struct StateT * v331 = slot_10(v324);
  return v331;
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