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
struct StateT * slot_1(struct StateT * v19);
struct StateT * slot_8(struct StateT * v311);
struct StateT * slot_6(struct StateT * v190);
struct StateT * slot_2(struct StateT * v32);
struct StateT * slot_7(struct StateT * v295);
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

struct StateT * slot_8(struct StateT * v311) {
  int v312 = v311->timer;
  int v369 = v312 + 1;
  v311->timer = v369;
  int * v314 = v311->regs;
  int v315 = v314[11];
  int * v316 = v311->cache_keys;
  int v317 = v316[0];
  bool v374 = v317 == ((int)((unsigned int)v315 >> 2));
  int v365;
  if (v374) {
    int * v318 = v311->cache_vals;
    int v319 = v318[0];
    v365 = v319;
  } else {
    int * v321 = v311->cache_keys;
    int v322 = v321[1];
    bool v379 = v322 == ((int)((unsigned int)v315 >> 2));
    int v363;
    if (v379) {
      int * v323 = v311->cache_vals;
      int v324 = v323[1];
      int * v325 = v311->cache_keys;
      int * v326 = v311->cache_keys;
      int v327 = v326[0];
      v325[1] = v327;
      int * v329 = v311->cache_vals;
      int * v330 = v311->cache_vals;
      int v331 = v330[0];
      v329[1] = v331;
      int * v333 = v311->cache_keys;
      int v388 = (int)((unsigned int)v315 >> 2);
      v333[0] = v388;
      int * v335 = v311->cache_vals;
      v335[0] = v324;
      int v337 = v311->timer;
      int v391 = v337 + 1;
      v311->timer = v391;
      v363 = v324;
    } else {
      int * v340 = v311->mem;
      int v393 = (int)((unsigned int)v315 >> 2);
      int v341 = v340[v393];
      int * v342 = v311->mem;
      int * v343 = v311->cache_keys;
      int v344 = v343[1];
      int * v345 = v311->cache_vals;
      int v346 = v345[1];
      v342[v344] = v346;
      int * v348 = v311->cache_keys;
      int * v349 = v311->cache_keys;
      int v350 = v349[0];
      v348[1] = v350;
      int * v352 = v311->cache_vals;
      int * v353 = v311->cache_vals;
      int v354 = v353[0];
      v352[1] = v354;
      int * v356 = v311->cache_keys;
      v356[0] = v393;
      int * v358 = v311->cache_vals;
      v358[0] = v341;
      int v360 = v311->timer;
      int v408 = v360 + 100;
      v311->timer = v408;
      v363 = v341;
    }
    v365 = v363;
  }
  int * v366 = v311->regs;
  v366[12] = v365;
  return v311;
}

struct StateT * slot_6(struct StateT * v190) {
  int v191 = v190->timer;
  int v249 = v191 + 1;
  v190->timer = v249;
  int * v193 = v190->regs;
  int v194 = v193[6];
  int * v195 = v190->cache_keys;
  int v196 = v195[0];
  bool v254 = v196 == ((int)((unsigned int)v194 >> 2));
  int v244;
  if (v254) {
    int * v197 = v190->cache_vals;
    int v198 = v197[0];
    v244 = v198;
  } else {
    int * v200 = v190->cache_keys;
    int v201 = v200[1];
    bool v259 = v201 == ((int)((unsigned int)v194 >> 2));
    int v242;
    if (v259) {
      int * v202 = v190->cache_vals;
      int v203 = v202[1];
      int * v204 = v190->cache_keys;
      int * v205 = v190->cache_keys;
      int v206 = v205[0];
      v204[1] = v206;
      int * v208 = v190->cache_vals;
      int * v209 = v190->cache_vals;
      int v210 = v209[0];
      v208[1] = v210;
      int * v212 = v190->cache_keys;
      int v268 = (int)((unsigned int)v194 >> 2);
      v212[0] = v268;
      int * v214 = v190->cache_vals;
      v214[0] = v203;
      int v216 = v190->timer;
      int v271 = v216 + 1;
      v190->timer = v271;
      v242 = v203;
    } else {
      int * v219 = v190->mem;
      int v273 = (int)((unsigned int)v194 >> 2);
      int v220 = v219[v273];
      int * v221 = v190->mem;
      int * v222 = v190->cache_keys;
      int v223 = v222[1];
      int * v224 = v190->cache_vals;
      int v225 = v224[1];
      v221[v223] = v225;
      int * v227 = v190->cache_keys;
      int * v228 = v190->cache_keys;
      int v229 = v228[0];
      v227[1] = v229;
      int * v231 = v190->cache_vals;
      int * v232 = v190->cache_vals;
      int v233 = v232[0];
      v231[1] = v233;
      int * v235 = v190->cache_keys;
      v235[0] = v273;
      int * v237 = v190->cache_vals;
      v237[0] = v220;
      int v239 = v190->timer;
      int v288 = v239 + 100;
      v190->timer = v288;
      v242 = v220;
    }
    v244 = v242;
  }
  int * v245 = v190->regs;
  v245[11] = v244;
  struct StateT * v247 = slot_7(v190);
  return v247;
}

struct StateT * slot_2(struct StateT * v32) {
  int * v33 = v32->saved_regs;
  int * v34 = v32->regs;
  int v35 = v34[6];
  v33[6] = v35;
  int v37 = v32->timer;
  int v126 = v37 + 1;
  v32->timer = v126;
  int * v39 = v32->regs;
  int v40 = v39[5];
  int * v41 = v32->regs;
  int v130 = v40 + 80;
  v41[6] = v130;
  int * v43 = v32->saved_regs;
  int * v44 = v32->regs;
  int v45 = v44[7];
  v43[7] = v45;
  int v47 = v32->timer;
  int v135 = v47 + 1;
  v32->timer = v135;
  int * v49 = v32->regs;
  v49[7] = 0;
  int * v51 = v32->regs;
  int v52 = v51[5];
  int * v53 = v32->regs;
  int v54 = v53[9];
  bool v141 = v52 >= v54;
  struct StateT * v120;
  if (v141) {
    int v55 = v32->timer;
    int v142 = v55 + 15;
    v32->timer = v142;
    int * v57 = v32->saved_regs;
    int v58 = v57[6];
    int * v59 = v32->regs;
    v59[6] = v58;
    int * v61 = v32->saved_regs;
    int v62 = v61[7];
    int * v63 = v32->regs;
    v63[7] = v62;
    v120 = v32;
  } else {
    int v66 = v32->timer;
    int v149 = v66 + 1;
    v32->timer = v149;
    int * v68 = v32->regs;
    int v69 = v68[6];
    int * v70 = v32->regs;
    int v71 = v70[7];
    int * v72 = v32->cache_keys;
    int v73 = v72[0];
    bool v153 = v73 == ((int)((unsigned int)v69 >> 2));
    int v117;
    if (v153) {
      int * v74 = v32->cache_vals;
      v74[0] = v71;
      v117 = v71;
    } else {
      int * v77 = v32->cache_keys;
      int v78 = v77[1];
      bool v158 = v78 == ((int)((unsigned int)v69 >> 2));
      int v115;
      if (v158) {
        int * v79 = v32->cache_keys;
        int * v80 = v32->cache_keys;
        int v81 = v80[0];
        v79[1] = v81;
        int * v83 = v32->cache_vals;
        int * v84 = v32->cache_vals;
        int v85 = v84[0];
        v83[1] = v85;
        int * v87 = v32->cache_keys;
        int v166 = (int)((unsigned int)v69 >> 2);
        v87[0] = v166;
        int * v89 = v32->cache_vals;
        v89[0] = v71;
        int v91 = v32->timer;
        int v169 = v91 + 1;
        v32->timer = v169;
        v115 = v71;
      } else {
        int * v94 = v32->mem;
        int * v95 = v32->cache_keys;
        int v96 = v95[1];
        int * v97 = v32->cache_vals;
        int v98 = v97[1];
        v94[v96] = v98;
        int * v100 = v32->cache_keys;
        int * v101 = v32->cache_keys;
        int v102 = v101[0];
        v100[1] = v102;
        int * v104 = v32->cache_vals;
        int * v105 = v32->cache_vals;
        int v106 = v105[0];
        v104[1] = v106;
        int * v108 = v32->cache_keys;
        int v182 = (int)((unsigned int)v69 >> 2);
        v108[0] = v182;
        int * v110 = v32->cache_vals;
        v110[0] = v71;
        int v112 = v32->timer;
        int v185 = v112 + 100;
        v32->timer = v185;
        v115 = v71;
      }
      v117 = v115;
    }
    struct StateT * v118 = slot_6(v32);
    v120 = v118;
  }
  return v120;
}

struct StateT * slot_7(struct StateT * v295) {
  int v296 = v295->timer;
  int v304 = v296 + 1;
  v295->timer = v304;
  int * v298 = v295->regs;
  int v299 = v298[11];
  int * v300 = v295->regs;
  int v308 = v299 << 2;
  v300[11] = v308;
  struct StateT * v302 = slot_8(v295);
  return v302;
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