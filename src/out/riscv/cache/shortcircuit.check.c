// verify: leak (CBMC should report VERIFICATION FAILED) [unwind 33]

#define NUM_REGS 32
#define MEM_SIZE 30
#define SECRET_SIZE 10
#define SECRET_OFFSET 20
#define CACHE_LRU_SIZE 10
#ifndef CBMC
#define __CPROVER_assert(b,s) 0
#define nondet_uint() 0
#else
int nondet_uint();
#endif
int bounded(int low, int high) {
  int x = nondet_uint();
  __CPROVER_assume(low <= x && x <= high);
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

struct StateT * slot_12(struct StateT * v364);
struct StateT * slot_14(struct StateT * v78);
struct StateT * slot_6(struct StateT * v109);
struct StateT * slot_5(struct StateT * v88);
struct StateT * slot_2(struct StateT * v28);
struct StateT * slot_7(struct StateT * v214);
struct StateT * slot_3(struct StateT * v41);
struct StateT * snippet(struct StateT * v0);
struct StateT * slot_10(struct StateT * v377);
struct StateT * slot_1(struct StateT * v15);
struct StateT * slot_8(struct StateT * v235);
struct StateT * slot_4(struct StateT * v54);
struct StateT * slot_13(struct StateT * v393);
struct StateT * slot_9(struct StateT * v340);
struct StateT * slot_11(struct StateT * v398);
struct StateT * slot_0(struct StateT * v2);
struct StateT * slot_12(struct StateT * v364) {
  int v365 = v364->timer;
  int v371 = v365 + 1;
  v364->timer = v371;
  int * v367 = v364->regs;
  v367[10] = 0;
  struct StateT * v369 = slot_13(v364);
  return v369;
}

struct StateT * slot_14(struct StateT * v78) {
  int v79 = v78->timer;
  int v84 = v79 + 1;
  v78->timer = v84;
  int * v81 = v78->regs;
  v81[10] = 1;
  return v78;
}

struct StateT * slot_6(struct StateT * v109) {
  int v110 = v109->timer;
  int v168 = v110 + 1;
  v109->timer = v168;
  int * v112 = v109->regs;
  int v113 = v112[5];
  int * v114 = v109->cache_keys;
  int v115 = v114[0];
  bool v173 = v115 == ((int)((unsigned int)v113 >> 2));
  int v163;
  if (v173) {
    int * v116 = v109->cache_vals;
    int v117 = v116[0];
    v163 = v117;
  } else {
    int * v119 = v109->cache_keys;
    int v120 = v119[1];
    bool v178 = v120 == ((int)((unsigned int)v113 >> 2));
    int v161;
    if (v178) {
      int * v121 = v109->cache_vals;
      int v122 = v121[1];
      int * v123 = v109->cache_keys;
      int * v124 = v109->cache_keys;
      int v125 = v124[0];
      v123[1] = v125;
      int * v127 = v109->cache_vals;
      int * v128 = v109->cache_vals;
      int v129 = v128[0];
      v127[1] = v129;
      int * v131 = v109->cache_keys;
      int v187 = (int)((unsigned int)v113 >> 2);
      v131[0] = v187;
      int * v133 = v109->cache_vals;
      v133[0] = v122;
      int v135 = v109->timer;
      int v190 = v135 + 1;
      v109->timer = v190;
      v161 = v122;
    } else {
      int * v138 = v109->mem;
      int v192 = (int)((unsigned int)v113 >> 2);
      int v139 = v138[v192];
      int * v140 = v109->mem;
      int * v141 = v109->cache_keys;
      int v142 = v141[1];
      int * v143 = v109->cache_vals;
      int v144 = v143[1];
      v140[v142] = v144;
      int * v146 = v109->cache_keys;
      int * v147 = v109->cache_keys;
      int v148 = v147[0];
      v146[1] = v148;
      int * v150 = v109->cache_vals;
      int * v151 = v109->cache_vals;
      int v152 = v151[0];
      v150[1] = v152;
      int * v154 = v109->cache_keys;
      v154[0] = v192;
      int * v156 = v109->cache_vals;
      v156[0] = v139;
      int v158 = v109->timer;
      int v207 = v158 + 100;
      v109->timer = v207;
      v161 = v139;
    }
    v163 = v161;
  }
  int * v164 = v109->regs;
  v164[10] = v163;
  struct StateT * v166 = slot_7(v109);
  return v166;
}

struct StateT * slot_5(struct StateT * v88) {
  int v89 = v88->timer;
  int v99 = v89 + 1;
  v88->timer = v99;
  int * v91 = v88->regs;
  int v92 = v91[12];
  int * v93 = v88->regs;
  int v94 = v93[14];
  int * v95 = v88->regs;
  int v106 = v92 + v94;
  v95[5] = v106;
  struct StateT * v97 = slot_6(v88);
  return v97;
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

struct StateT * slot_7(struct StateT * v214) {
  int v215 = v214->timer;
  int v225 = v215 + 1;
  v214->timer = v225;
  int * v217 = v214->regs;
  int v218 = v217[13];
  int * v219 = v214->regs;
  int v220 = v219[14];
  int * v221 = v214->regs;
  int v232 = v218 + v220;
  v221[6] = v232;
  struct StateT * v223 = slot_8(v214);
  return v223;
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

struct StateT * snippet(struct StateT * v0) {
  struct StateT * v1 = slot_0(v0);
  return v1;
}

struct StateT * slot_10(struct StateT * v377) {
  int v378 = v377->timer;
  int v386 = v378 + 1;
  v377->timer = v386;
  int * v380 = v377->regs;
  int v381 = v380[14];
  int * v382 = v377->regs;
  int v390 = v381 + 4;
  v382[14] = v390;
  struct StateT * v384 = slot_11(v377);
  return v384;
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

struct StateT * slot_8(struct StateT * v235) {
  int v236 = v235->timer;
  int v294 = v236 + 1;
  v235->timer = v294;
  int * v238 = v235->regs;
  int v239 = v238[6];
  int * v240 = v235->cache_keys;
  int v241 = v240[0];
  bool v299 = v241 == ((int)((unsigned int)v239 >> 2));
  int v289;
  if (v299) {
    int * v242 = v235->cache_vals;
    int v243 = v242[0];
    v289 = v243;
  } else {
    int * v245 = v235->cache_keys;
    int v246 = v245[1];
    bool v304 = v246 == ((int)((unsigned int)v239 >> 2));
    int v287;
    if (v304) {
      int * v247 = v235->cache_vals;
      int v248 = v247[1];
      int * v249 = v235->cache_keys;
      int * v250 = v235->cache_keys;
      int v251 = v250[0];
      v249[1] = v251;
      int * v253 = v235->cache_vals;
      int * v254 = v235->cache_vals;
      int v255 = v254[0];
      v253[1] = v255;
      int * v257 = v235->cache_keys;
      int v313 = (int)((unsigned int)v239 >> 2);
      v257[0] = v313;
      int * v259 = v235->cache_vals;
      v259[0] = v248;
      int v261 = v235->timer;
      int v316 = v261 + 1;
      v235->timer = v316;
      v287 = v248;
    } else {
      int * v264 = v235->mem;
      int v318 = (int)((unsigned int)v239 >> 2);
      int v265 = v264[v318];
      int * v266 = v235->mem;
      int * v267 = v235->cache_keys;
      int v268 = v267[1];
      int * v269 = v235->cache_vals;
      int v270 = v269[1];
      v266[v268] = v270;
      int * v272 = v235->cache_keys;
      int * v273 = v235->cache_keys;
      int v274 = v273[0];
      v272[1] = v274;
      int * v276 = v235->cache_vals;
      int * v277 = v235->cache_vals;
      int v278 = v277[0];
      v276[1] = v278;
      int * v280 = v235->cache_keys;
      v280[0] = v318;
      int * v282 = v235->cache_vals;
      v282[0] = v265;
      int v284 = v235->timer;
      int v333 = v284 + 100;
      v235->timer = v333;
      v287 = v265;
    }
    v289 = v287;
  }
  int * v290 = v235->regs;
  v290[11] = v289;
  struct StateT * v292 = slot_9(v235);
  return v292;
}

struct StateT * slot_4(struct StateT * v54) {
  int v55 = v54->timer;
  int v67 = v55 + 1;
  v54->timer = v67;
  int * v57 = v54->regs;
  int v58 = v57[14];
  int * v59 = v54->regs;
  int v60 = v59[15];
  bool v72 = v58 >= v60;
  struct StateT * v65;
  if (v72) {
    struct StateT * v61 = slot_14(v54);
    v65 = v61;
  } else {
    struct StateT * v63 = slot_5(v54);
    v65 = v63;
  }
  return v65;
}

struct StateT * slot_13(struct StateT * v393) {
  int v394 = v393->timer;
  int v397 = v394 + 1;
  v393->timer = v397;
  return v393;
}

struct StateT * slot_9(struct StateT * v340) {
  int v341 = v340->timer;
  int v353 = v341 + 1;
  v340->timer = v353;
  int * v343 = v340->regs;
  int v344 = v343[10];
  int * v345 = v340->regs;
  int v346 = v345[11];
  bool v358 = !(v344 == v346);
  struct StateT * v351;
  if (v358) {
    struct StateT * v347 = slot_12(v340);
    v351 = v347;
  } else {
    struct StateT * v349 = slot_10(v340);
    v351 = v349;
  }
  return v351;
}

struct StateT * slot_11(struct StateT * v398) {
  int v399 = v398->timer;
  int v403 = v399 + 1;
  v398->timer = v403;
  struct StateT * v401 = slot_4(v398);
  return v401;
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
  __CPROVER_assert(s1_->timer==s2_->timer, "timing leak");
  return 0;
}