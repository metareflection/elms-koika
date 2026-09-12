
#define NUM_REGS 32
#define MEM_SIZE 30
#define SECRET_SIZE 10
#define SECRET_OFFSET 20
#define CACHE_LRU_SIZE 10
#define BHT_SIZE 1
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
struct StateT {
  int regs[NUM_REGS];
  int mem[MEM_SIZE];
  int saved_regs[NUM_REGS];
  int cache_keys[CACHE_LRU_SIZE];
  int cache_vals[CACHE_LRU_SIZE];
  int timer;
  int bht[BHT_SIZE];
};

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
  for (int i=0; i<BHT_SIZE; i++) {
    s->bht[i] = 0;
  }
}

/*****************************************
Emitting C Generated Code
*******************************************/

#include <stdbool.h>
#include <stdlib.h>

struct StateT * v333(struct StateT * v334);
struct StateT * snippet(struct StateT * v0);
struct StateT * v19(struct StateT * v20);
struct StateT * v1(struct StateT * v2);
struct StateT * v395(struct StateT * v396);
struct StateT * v85(struct StateT * v86);
struct StateT * v263(struct StateT * v264);
struct StateT * v7(struct StateT * v8);
struct StateT * v77(struct StateT * v78);
struct StateT * v325(struct StateT * v326);
struct StateT * v333(struct StateT * v334) {
  int * v335 = v334->saved_regs;
  int * v336 = v334->regs;
  int v337 = v336[12];
  v335[12] = v337;
  int v339 = v334->timer;
  int v442 = v339 + 1;
  v334->timer = v442;int * v341 = v334->regs;
  int v342 = v341[11];
  int * v343 = v334->cache_keys;
  int v344 = v343[0];
  bool v447 = v344 == ((int)((unsigned int)(v342 + 16) >> 2));
  int v392 = (v447 ? ({
    int * v345 = v334->cache_vals;
    int v346 = v345[0];
    v346;
  }) : ({
    int * v348 = v334->cache_keys;
    int v349 = v348[1];
    bool v452 = v349 == ((int)((unsigned int)(v342 + 16) >> 2));
    int v390 = (v452 ? ({
      int * v350 = v334->cache_vals;
      int v351 = v350[1];
      int * v352 = v334->cache_keys;
      int * v353 = v334->cache_keys;
      int v354 = v353[0];
      v352[1] = v354;
      int * v356 = v334->cache_vals;
      int * v357 = v334->cache_vals;
      int v358 = v357[0];
      v356[1] = v358;
      int * v360 = v334->cache_keys;
      int v461 = (int)((unsigned int)(v342 + 16) >> 2);
      v360[0] = v461;
      int * v362 = v334->cache_vals;
      v362[0] = v351;
      int v364 = v334->timer;
      int v464 = v364 + 1;
      v334->timer = v464;v351;
    }) : ({
      int * v367 = v334->mem;
      int v466 = (int)((unsigned int)(v342 + 16) >> 2);
      int v368 = v367[v466];
      int * v369 = v334->mem;
      int * v370 = v334->cache_keys;
      int v371 = v370[1];
      int * v372 = v334->cache_vals;
      int v373 = v372[1];
      v369[v371] = v373;
      int * v375 = v334->cache_keys;
      int * v376 = v334->cache_keys;
      int v377 = v376[0];
      v375[1] = v377;
      int * v379 = v334->cache_vals;
      int * v380 = v334->cache_vals;
      int v381 = v380[0];
      v379[1] = v381;
      int * v383 = v334->cache_keys;
      v383[0] = v466;
      int * v385 = v334->cache_vals;
      v385[0] = v368;
      int v387 = v334->timer;
      int v481 = v387 + 100;
      v334->timer = v481;v368;
    }));
    v390;
  }));
  int * v393 = v334->regs;
  v393[12] = v392;
  struct StateT * v436 = v395(v334);
  return v436;
}

struct StateT * snippet(struct StateT * v0) {
  struct StateT * v560 = v1(v0);
  return v560;
}

struct StateT * v19(struct StateT * v20) {
  int v21 = v20->timer;
  int v199 = v21 + 1;
  v20->timer = v199;int * v23 = v20->regs;
  int v24 = v23[10];
  int * v25 = v20->cache_keys;
  int v26 = v25[0];
  bool v204 = v26 == ((int)((unsigned int)v24 >> 2));
  int v74 = (v204 ? ({
    int * v27 = v20->cache_vals;
    int v28 = v27[0];
    v28;
  }) : ({
    int * v30 = v20->cache_keys;
    int v31 = v30[1];
    bool v209 = v31 == ((int)((unsigned int)v24 >> 2));
    int v72 = (v209 ? ({
      int * v32 = v20->cache_vals;
      int v33 = v32[1];
      int * v34 = v20->cache_keys;
      int * v35 = v20->cache_keys;
      int v36 = v35[0];
      v34[1] = v36;
      int * v38 = v20->cache_vals;
      int * v39 = v20->cache_vals;
      int v40 = v39[0];
      v38[1] = v40;
      int * v42 = v20->cache_keys;
      int v218 = (int)((unsigned int)v24 >> 2);
      v42[0] = v218;
      int * v44 = v20->cache_vals;
      v44[0] = v33;
      int v46 = v20->timer;
      int v221 = v46 + 1;
      v20->timer = v221;v33;
    }) : ({
      int * v49 = v20->mem;
      int v223 = (int)((unsigned int)v24 >> 2);
      int v50 = v49[v223];
      int * v51 = v20->mem;
      int * v52 = v20->cache_keys;
      int v53 = v52[1];
      int * v54 = v20->cache_vals;
      int v55 = v54[1];
      v51[v53] = v55;
      int * v57 = v20->cache_keys;
      int * v58 = v20->cache_keys;
      int v59 = v58[0];
      v57[1] = v59;
      int * v61 = v20->cache_vals;
      int * v62 = v20->cache_vals;
      int v63 = v62[0];
      v61[1] = v63;
      int * v65 = v20->cache_keys;
      v65[0] = v223;
      int * v67 = v20->cache_vals;
      v67[0] = v50;
      int v69 = v20->timer;
      int v238 = v69 + 100;
      v20->timer = v238;v50;
    }));
    v72;
  }));
  int * v75 = v20->regs;
  v75[11] = v74;
  struct StateT * v197 = v77(v20);
  return v197;
}

struct StateT * v1(struct StateT * v2) {
  int v3 = v2->timer;
  int v551 = v3 + 1;
  v2->timer = v551;int * v5 = v2->bht;
  int v6 = v5[0];
  bool v554 = !(v6 == 0);
  struct StateT * v549 = (v554 ? ({
    struct StateT * v261 = v7(v2);
    v261;
  }) : ({
    struct StateT * v547 = v263(v2);
    v547;
  }));
  return v549;
}

struct StateT * v395(struct StateT * v396) {
  int * v397 = v396->regs;
  int v398 = v397[10];
  int * v399 = v396->bht;
  bool v420 = v398 == 0;
  int v402 = (v420 ? 1 : 0);
  v399[0] = v402;
  struct StateT * v416 = (v420 ? ({
    int v404 = v396->timer;
    int v426 = v404 + 15;
    v396->timer = v426;int * v406 = v396->saved_regs;
    int v407 = v406[11];
    int * v408 = v396->regs;
    v408[11] = v407;
    int * v410 = v396->saved_regs;
    int v411 = v410[12];
    int * v412 = v396->regs;
    v412[12] = v411;
    v396;
  }) : v396);
  return v416;
}

struct StateT * v85(struct StateT * v86) {
  int v87 = v86->timer;
  int v144 = v87 + 1;
  v86->timer = v144;int * v89 = v86->regs;
  int v90 = v89[11];
  int * v91 = v86->cache_keys;
  int v92 = v91[0];
  bool v149 = v92 == ((int)((unsigned int)(v90 + 16) >> 2));
  int v140 = (v149 ? ({
    int * v93 = v86->cache_vals;
    int v94 = v93[0];
    v94;
  }) : ({
    int * v96 = v86->cache_keys;
    int v97 = v96[1];
    bool v154 = v97 == ((int)((unsigned int)(v90 + 16) >> 2));
    int v138 = (v154 ? ({
      int * v98 = v86->cache_vals;
      int v99 = v98[1];
      int * v100 = v86->cache_keys;
      int * v101 = v86->cache_keys;
      int v102 = v101[0];
      v100[1] = v102;
      int * v104 = v86->cache_vals;
      int * v105 = v86->cache_vals;
      int v106 = v105[0];
      v104[1] = v106;
      int * v108 = v86->cache_keys;
      int v163 = (int)((unsigned int)(v90 + 16) >> 2);
      v108[0] = v163;
      int * v110 = v86->cache_vals;
      v110[0] = v99;
      int v112 = v86->timer;
      int v166 = v112 + 1;
      v86->timer = v166;v99;
    }) : ({
      int * v115 = v86->mem;
      int v168 = (int)((unsigned int)(v90 + 16) >> 2);
      int v116 = v115[v168];
      int * v117 = v86->mem;
      int * v118 = v86->cache_keys;
      int v119 = v118[1];
      int * v120 = v86->cache_vals;
      int v121 = v120[1];
      v117[v119] = v121;
      int * v123 = v86->cache_keys;
      int * v124 = v86->cache_keys;
      int v125 = v124[0];
      v123[1] = v125;
      int * v127 = v86->cache_vals;
      int * v128 = v86->cache_vals;
      int v129 = v128[0];
      v127[1] = v129;
      int * v131 = v86->cache_keys;
      v131[0] = v168;
      int * v133 = v86->cache_vals;
      v133[0] = v116;
      int v135 = v86->timer;
      int v183 = v135 + 100;
      v86->timer = v183;v116;
    }));
    v138;
  }));
  int * v141 = v86->regs;
  v141[12] = v140;
  return v86;
}

struct StateT * v263(struct StateT * v264) {
  int * v265 = v264->saved_regs;
  int * v266 = v264->regs;
  int v267 = v266[11];
  v265[11] = v267;
  int v269 = v264->timer;
  int v502 = v269 + 1;
  v264->timer = v502;int * v271 = v264->regs;
  int v272 = v271[10];
  int * v273 = v264->cache_keys;
  int v274 = v273[0];
  bool v507 = v274 == ((int)((unsigned int)v272 >> 2));
  int v322 = (v507 ? ({
    int * v275 = v264->cache_vals;
    int v276 = v275[0];
    v276;
  }) : ({
    int * v278 = v264->cache_keys;
    int v279 = v278[1];
    bool v512 = v279 == ((int)((unsigned int)v272 >> 2));
    int v320 = (v512 ? ({
      int * v280 = v264->cache_vals;
      int v281 = v280[1];
      int * v282 = v264->cache_keys;
      int * v283 = v264->cache_keys;
      int v284 = v283[0];
      v282[1] = v284;
      int * v286 = v264->cache_vals;
      int * v287 = v264->cache_vals;
      int v288 = v287[0];
      v286[1] = v288;
      int * v290 = v264->cache_keys;
      int v521 = (int)((unsigned int)v272 >> 2);
      v290[0] = v521;
      int * v292 = v264->cache_vals;
      v292[0] = v281;
      int v294 = v264->timer;
      int v524 = v294 + 1;
      v264->timer = v524;v281;
    }) : ({
      int * v297 = v264->mem;
      int v526 = (int)((unsigned int)v272 >> 2);
      int v298 = v297[v526];
      int * v299 = v264->mem;
      int * v300 = v264->cache_keys;
      int v301 = v300[1];
      int * v302 = v264->cache_vals;
      int v303 = v302[1];
      v299[v301] = v303;
      int * v305 = v264->cache_keys;
      int * v306 = v264->cache_keys;
      int v307 = v306[0];
      v305[1] = v307;
      int * v309 = v264->cache_vals;
      int * v310 = v264->cache_vals;
      int v311 = v310[0];
      v309[1] = v311;
      int * v313 = v264->cache_keys;
      v313[0] = v526;
      int * v315 = v264->cache_vals;
      v315[0] = v298;
      int v317 = v264->timer;
      int v541 = v317 + 100;
      v264->timer = v541;v298;
    }));
    v320;
  }));
  int * v323 = v264->regs;
  v323[11] = v322;
  struct StateT * v496 = v325(v264);
  return v496;
}

struct StateT * v7(struct StateT * v8) {
  int * v9 = v8->regs;
  int v10 = v9[10];
  int * v11 = v8->bht;
  bool v251 = v10 == 0;
  int v14 = (v251 ? 1 : 0);
  v11[0] = v14;
  struct StateT * v247 = (v251 ? v8 : ({
    int v17 = v8->timer;
    int v257 = v17 + 15;
    v8->timer = v257;struct StateT * v245 = v19(v8);
    v245;
  }));
  return v247;
}

struct StateT * v77(struct StateT * v78) {
  int v79 = v78->timer;
  int v190 = v79 + 1;
  v78->timer = v190;int * v81 = v78->regs;
  int v82 = v81[11];
  int * v83 = v78->regs;
  int v194 = v82 << 2;
  v83[11] = v194;
  struct StateT * v188 = v85(v78);
  return v188;
}

struct StateT * v325(struct StateT * v326) {
  int v327 = v326->timer;
  int v489 = v327 + 1;
  v326->timer = v489;int * v329 = v326->regs;
  int v330 = v329[11];
  int * v331 = v326->regs;
  int v493 = v330 << 2;
  v331[11] = v493;
  struct StateT * v487 = v333(v326);
  return v487;
}



/*****************************************
End of C Generated Code
*******************************************/

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