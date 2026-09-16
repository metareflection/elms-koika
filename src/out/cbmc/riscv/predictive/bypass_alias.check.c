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
struct StateT * slot_1(struct StateT * v15);
struct StateT * slot_8(struct StateT * v378);
struct StateT * slot_6(struct StateT * v257);
struct StateT * slot_5(struct StateT * v244);
struct StateT * slot_4(struct StateT * v146);
struct StateT * slot_2(struct StateT * v120);
struct StateT * slot_7(struct StateT * v273);
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

struct StateT * slot_8(struct StateT * v378) {
  int v379 = v378->timer;
  int v436 = v379 + 1;
  v378->timer = v436;
  int * v381 = v378->regs;
  int v382 = v381[11];
  int * v383 = v378->cache_keys;
  int v384 = v383[0];
  bool v441 = v384 == ((int)((unsigned int)v382 >> 2));
  int v432;
  if (v441) {
    int * v385 = v378->cache_vals;
    int v386 = v385[0];
    v432 = v386;
  } else {
    int * v388 = v378->cache_keys;
    int v389 = v388[1];
    bool v446 = v389 == ((int)((unsigned int)v382 >> 2));
    int v430;
    if (v446) {
      int * v390 = v378->cache_vals;
      int v391 = v390[1];
      int * v392 = v378->cache_keys;
      int * v393 = v378->cache_keys;
      int v394 = v393[0];
      v392[1] = v394;
      int * v396 = v378->cache_vals;
      int * v397 = v378->cache_vals;
      int v398 = v397[0];
      v396[1] = v398;
      int * v400 = v378->cache_keys;
      int v455 = (int)((unsigned int)v382 >> 2);
      v400[0] = v455;
      int * v402 = v378->cache_vals;
      v402[0] = v391;
      int v404 = v378->timer;
      int v458 = v404 + 1;
      v378->timer = v458;
      v430 = v391;
    } else {
      int * v407 = v378->mem;
      int v460 = (int)((unsigned int)v382 >> 2);
      int v408 = v407[v460];
      int * v409 = v378->mem;
      int * v410 = v378->cache_keys;
      int v411 = v410[1];
      int * v412 = v378->cache_vals;
      int v413 = v412[1];
      v409[v411] = v413;
      int * v415 = v378->cache_keys;
      int * v416 = v378->cache_keys;
      int v417 = v416[0];
      v415[1] = v417;
      int * v419 = v378->cache_vals;
      int * v420 = v378->cache_vals;
      int v421 = v420[0];
      v419[1] = v421;
      int * v423 = v378->cache_keys;
      v423[0] = v460;
      int * v425 = v378->cache_vals;
      v425[0] = v408;
      int v427 = v378->timer;
      int v475 = v427 + 100;
      v378->timer = v475;
      v430 = v408;
    }
    v432 = v430;
  }
  int * v433 = v378->regs;
  v433[12] = v432;
  return v378;
}

struct StateT * slot_6(struct StateT * v257) {
  int v258 = v257->timer;
  int v266 = v258 + 1;
  v257->timer = v266;
  int * v260 = v257->regs;
  int v261 = v260[7];
  int * v262 = v257->regs;
  int v270 = v261 + 1;
  v262[7] = v270;
  struct StateT * v264 = slot_7(v257);
  return v264;
}

struct StateT * slot_5(struct StateT * v244) {
  int v245 = v244->timer;
  int v251 = v245 + 1;
  v244->timer = v251;
  int * v247 = v244->regs;
  v247[7] = 0;
  struct StateT * v249 = slot_6(v244);
  return v249;
}

struct StateT * slot_4(struct StateT * v146) {
  int v147 = v146->timer;
  int v201 = v147 + 1;
  v146->timer = v201;
  int * v149 = v146->regs;
  int v150 = v149[8];
  int * v151 = v146->regs;
  int v152 = v151[5];
  int * v153 = v146->cache_keys;
  int v154 = v153[0];
  bool v208 = v154 == ((int)((unsigned int)v150 >> 2));
  int v198;
  if (v208) {
    int * v155 = v146->cache_vals;
    v155[0] = v152;
    v198 = v152;
  } else {
    int * v158 = v146->cache_keys;
    int v159 = v158[1];
    bool v213 = v159 == ((int)((unsigned int)v150 >> 2));
    int v196;
    if (v213) {
      int * v160 = v146->cache_keys;
      int * v161 = v146->cache_keys;
      int v162 = v161[0];
      v160[1] = v162;
      int * v164 = v146->cache_vals;
      int * v165 = v146->cache_vals;
      int v166 = v165[0];
      v164[1] = v166;
      int * v168 = v146->cache_keys;
      int v221 = (int)((unsigned int)v150 >> 2);
      v168[0] = v221;
      int * v170 = v146->cache_vals;
      v170[0] = v152;
      int v172 = v146->timer;
      int v224 = v172 + 1;
      v146->timer = v224;
      v196 = v152;
    } else {
      int * v175 = v146->mem;
      int * v176 = v146->cache_keys;
      int v177 = v176[1];
      int * v178 = v146->cache_vals;
      int v179 = v178[1];
      v175[v177] = v179;
      int * v181 = v146->cache_keys;
      int * v182 = v146->cache_keys;
      int v183 = v182[0];
      v181[1] = v183;
      int * v185 = v146->cache_vals;
      int * v186 = v146->cache_vals;
      int v187 = v186[0];
      v185[1] = v187;
      int * v189 = v146->cache_keys;
      int v237 = (int)((unsigned int)v150 >> 2);
      v189[0] = v237;
      int * v191 = v146->cache_vals;
      v191[0] = v152;
      int v193 = v146->timer;
      int v240 = v193 + 100;
      v146->timer = v240;
      v196 = v152;
    }
    v198 = v196;
  }
  struct StateT * v199 = slot_5(v146);
  return v199;
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

struct StateT * slot_7(struct StateT * v273) {
  int v274 = v273->timer;
  int v332 = v274 + 1;
  v273->timer = v332;
  int * v276 = v273->regs;
  int v277 = v276[9];
  int * v278 = v273->cache_keys;
  int v279 = v278[0];
  bool v337 = v279 == ((int)((unsigned int)v277 >> 2));
  int v327;
  if (v337) {
    int * v280 = v273->cache_vals;
    int v281 = v280[0];
    v327 = v281;
  } else {
    int * v283 = v273->cache_keys;
    int v284 = v283[1];
    bool v342 = v284 == ((int)((unsigned int)v277 >> 2));
    int v325;
    if (v342) {
      int * v285 = v273->cache_vals;
      int v286 = v285[1];
      int * v287 = v273->cache_keys;
      int * v288 = v273->cache_keys;
      int v289 = v288[0];
      v287[1] = v289;
      int * v291 = v273->cache_vals;
      int * v292 = v273->cache_vals;
      int v293 = v292[0];
      v291[1] = v293;
      int * v295 = v273->cache_keys;
      int v351 = (int)((unsigned int)v277 >> 2);
      v295[0] = v351;
      int * v297 = v273->cache_vals;
      v297[0] = v286;
      int v299 = v273->timer;
      int v354 = v299 + 1;
      v273->timer = v354;
      v325 = v286;
    } else {
      int * v302 = v273->mem;
      int v356 = (int)((unsigned int)v277 >> 2);
      int v303 = v302[v356];
      int * v304 = v273->mem;
      int * v305 = v273->cache_keys;
      int v306 = v305[1];
      int * v307 = v273->cache_vals;
      int v308 = v307[1];
      v304[v306] = v308;
      int * v310 = v273->cache_keys;
      int * v311 = v273->cache_keys;
      int v312 = v311[0];
      v310[1] = v312;
      int * v314 = v273->cache_vals;
      int * v315 = v273->cache_vals;
      int v316 = v315[0];
      v314[1] = v316;
      int * v318 = v273->cache_keys;
      v318[0] = v356;
      int * v320 = v273->cache_vals;
      v320[0] = v303;
      int v322 = v273->timer;
      int v371 = v322 + 100;
      v273->timer = v371;
      v325 = v303;
    }
    v327 = v325;
  }
  int * v328 = v273->regs;
  v328[11] = v327;
  struct StateT * v330 = slot_8(v273);
  return v330;
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