// verify: clean (CBMC should report VERIFICATION SUCCESSFUL) [unwind 33]
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
struct StateT * slot_8(struct StateT * v302);
struct StateT * slot_6(struct StateT * v181);
struct StateT * slot_5(struct StateT * v83);
struct StateT * slot_4(struct StateT * v70);
struct StateT * slot_2(struct StateT * v32);
struct StateT * slot_7(struct StateT * v286);
struct StateT * slot_3(struct StateT * v53);
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

struct StateT * slot_8(struct StateT * v302) {
  int v303 = v302->timer;
  int v360 = v303 + 1;
  v302->timer = v360;
  int * v305 = v302->regs;
  int v306 = v305[11];
  int * v307 = v302->cache_keys;
  int v308 = v307[0];
  bool v365 = v308 == ((int)((unsigned int)v306 >> 2));
  int v356;
  if (v365) {
    int * v309 = v302->cache_vals;
    int v310 = v309[0];
    v356 = v310;
  } else {
    int * v312 = v302->cache_keys;
    int v313 = v312[1];
    bool v370 = v313 == ((int)((unsigned int)v306 >> 2));
    int v354;
    if (v370) {
      int * v314 = v302->cache_vals;
      int v315 = v314[1];
      int * v316 = v302->cache_keys;
      int * v317 = v302->cache_keys;
      int v318 = v317[0];
      v316[1] = v318;
      int * v320 = v302->cache_vals;
      int * v321 = v302->cache_vals;
      int v322 = v321[0];
      v320[1] = v322;
      int * v324 = v302->cache_keys;
      int v379 = (int)((unsigned int)v306 >> 2);
      v324[0] = v379;
      int * v326 = v302->cache_vals;
      v326[0] = v315;
      int v328 = v302->timer;
      int v382 = v328 + 1;
      v302->timer = v382;
      v354 = v315;
    } else {
      int * v331 = v302->mem;
      int v384 = (int)((unsigned int)v306 >> 2);
      int v332 = v331[v384];
      int * v333 = v302->mem;
      int * v334 = v302->cache_keys;
      int v335 = v334[1];
      int * v336 = v302->cache_vals;
      int v337 = v336[1];
      v333[v335] = v337;
      int * v339 = v302->cache_keys;
      int * v340 = v302->cache_keys;
      int v341 = v340[0];
      v339[1] = v341;
      int * v343 = v302->cache_vals;
      int * v344 = v302->cache_vals;
      int v345 = v344[0];
      v343[1] = v345;
      int * v347 = v302->cache_keys;
      v347[0] = v384;
      int * v349 = v302->cache_vals;
      v349[0] = v332;
      int v351 = v302->timer;
      int v399 = v351 + 100;
      v302->timer = v399;
      v354 = v332;
    }
    v356 = v354;
  }
  int * v357 = v302->regs;
  v357[12] = v356;
  return v302;
}

struct StateT * slot_6(struct StateT * v181) {
  int v182 = v181->timer;
  int v240 = v182 + 1;
  v181->timer = v240;
  int * v184 = v181->regs;
  int v185 = v184[6];
  int * v186 = v181->cache_keys;
  int v187 = v186[0];
  bool v245 = v187 == ((int)((unsigned int)v185 >> 2));
  int v235;
  if (v245) {
    int * v188 = v181->cache_vals;
    int v189 = v188[0];
    v235 = v189;
  } else {
    int * v191 = v181->cache_keys;
    int v192 = v191[1];
    bool v250 = v192 == ((int)((unsigned int)v185 >> 2));
    int v233;
    if (v250) {
      int * v193 = v181->cache_vals;
      int v194 = v193[1];
      int * v195 = v181->cache_keys;
      int * v196 = v181->cache_keys;
      int v197 = v196[0];
      v195[1] = v197;
      int * v199 = v181->cache_vals;
      int * v200 = v181->cache_vals;
      int v201 = v200[0];
      v199[1] = v201;
      int * v203 = v181->cache_keys;
      int v259 = (int)((unsigned int)v185 >> 2);
      v203[0] = v259;
      int * v205 = v181->cache_vals;
      v205[0] = v194;
      int v207 = v181->timer;
      int v262 = v207 + 1;
      v181->timer = v262;
      v233 = v194;
    } else {
      int * v210 = v181->mem;
      int v264 = (int)((unsigned int)v185 >> 2);
      int v211 = v210[v264];
      int * v212 = v181->mem;
      int * v213 = v181->cache_keys;
      int v214 = v213[1];
      int * v215 = v181->cache_vals;
      int v216 = v215[1];
      v212[v214] = v216;
      int * v218 = v181->cache_keys;
      int * v219 = v181->cache_keys;
      int v220 = v219[0];
      v218[1] = v220;
      int * v222 = v181->cache_vals;
      int * v223 = v181->cache_vals;
      int v224 = v223[0];
      v222[1] = v224;
      int * v226 = v181->cache_keys;
      v226[0] = v264;
      int * v228 = v181->cache_vals;
      v228[0] = v211;
      int v230 = v181->timer;
      int v279 = v230 + 100;
      v181->timer = v279;
      v233 = v211;
    }
    v235 = v233;
  }
  int * v236 = v181->regs;
  v236[11] = v235;
  struct StateT * v238 = slot_7(v181);
  return v238;
}

struct StateT * slot_5(struct StateT * v83) {
  int v84 = v83->timer;
  int v138 = v84 + 1;
  v83->timer = v138;
  int * v86 = v83->regs;
  int v87 = v86[6];
  int * v88 = v83->regs;
  int v89 = v88[7];
  int * v90 = v83->cache_keys;
  int v91 = v90[0];
  bool v145 = v91 == ((int)((unsigned int)v87 >> 2));
  int v135;
  if (v145) {
    int * v92 = v83->cache_vals;
    v92[0] = v89;
    v135 = v89;
  } else {
    int * v95 = v83->cache_keys;
    int v96 = v95[1];
    bool v150 = v96 == ((int)((unsigned int)v87 >> 2));
    int v133;
    if (v150) {
      int * v97 = v83->cache_keys;
      int * v98 = v83->cache_keys;
      int v99 = v98[0];
      v97[1] = v99;
      int * v101 = v83->cache_vals;
      int * v102 = v83->cache_vals;
      int v103 = v102[0];
      v101[1] = v103;
      int * v105 = v83->cache_keys;
      int v158 = (int)((unsigned int)v87 >> 2);
      v105[0] = v158;
      int * v107 = v83->cache_vals;
      v107[0] = v89;
      int v109 = v83->timer;
      int v161 = v109 + 1;
      v83->timer = v161;
      v133 = v89;
    } else {
      int * v112 = v83->mem;
      int * v113 = v83->cache_keys;
      int v114 = v113[1];
      int * v115 = v83->cache_vals;
      int v116 = v115[1];
      v112[v114] = v116;
      int * v118 = v83->cache_keys;
      int * v119 = v83->cache_keys;
      int v120 = v119[0];
      v118[1] = v120;
      int * v122 = v83->cache_vals;
      int * v123 = v83->cache_vals;
      int v124 = v123[0];
      v122[1] = v124;
      int * v126 = v83->cache_keys;
      int v174 = (int)((unsigned int)v87 >> 2);
      v126[0] = v174;
      int * v128 = v83->cache_vals;
      v128[0] = v89;
      int v130 = v83->timer;
      int v177 = v130 + 100;
      v83->timer = v177;
      v133 = v89;
    }
    v135 = v133;
  }
  struct StateT * v136 = slot_6(v83);
  return v136;
}

struct StateT * slot_4(struct StateT * v70) {
  int v71 = v70->timer;
  int v77 = v71 + 1;
  v70->timer = v77;
  int * v73 = v70->regs;
  v73[7] = 0;
  struct StateT * v75 = slot_5(v70);
  return v75;
}

struct StateT * slot_2(struct StateT * v32) {
  int v33 = v32->timer;
  int v44 = v33 + 1;
  v32->timer = v44;
  int * v35 = v32->regs;
  int v36 = v35[5];
  int * v37 = v32->regs;
  int v38 = v37[9];
  bool v49 = v36 >= v38;
  struct StateT * v42;
  if (v49) {
    v42 = v32;
  } else {
    struct StateT * v40 = slot_3(v32);
    v42 = v40;
  }
  return v42;
}

struct StateT * slot_7(struct StateT * v286) {
  int v287 = v286->timer;
  int v295 = v287 + 1;
  v286->timer = v295;
  int * v289 = v286->regs;
  int v290 = v289[11];
  int * v291 = v286->regs;
  int v299 = v290 << 2;
  v291[11] = v299;
  struct StateT * v293 = slot_8(v286);
  return v293;
}

struct StateT * slot_3(struct StateT * v53) {
  int v54 = v53->timer;
  int v62 = v54 + 1;
  v53->timer = v62;
  int * v56 = v53->regs;
  int v57 = v56[5];
  int * v58 = v53->regs;
  int v67 = v57 + 80;
  v58[6] = v67;
  struct StateT * v60 = slot_4(v53);
  return v60;
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