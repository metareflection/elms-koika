// verify: clean (CBMC should report VERIFICATION SUCCESSFUL) [unwind 33]

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

struct StateT * slot_12(struct StateT * v404);
struct StateT * slot_14(struct StateT * v91);
struct StateT * slot_6(struct StateT * v111);
struct StateT * slot_5(struct StateT * v67);
struct StateT * slot_2(struct StateT * v28);
struct StateT * slot_7(struct StateT * v132);
struct StateT * slot_3(struct StateT * v41);
struct StateT * snippet(struct StateT * v0);
struct StateT * slot_10(struct StateT * v363);
struct StateT * slot_1(struct StateT * v15);
struct StateT * slot_8(struct StateT * v237);
struct StateT * slot_4(struct StateT * v54);
struct StateT * slot_13(struct StateT * v420);
struct StateT * slot_9(struct StateT * v258);
struct StateT * slot_11(struct StateT * v384);
struct StateT * slot_0(struct StateT * v2);
struct StateT * slot_12(struct StateT * v404) {
  int v405 = v404->timer;
  int v413 = v405 + 1;
  v404->timer = v413;
  int * v407 = v404->regs;
  int v408 = v407[14];
  int * v409 = v404->regs;
  int v417 = v408 + 4;
  v409[14] = v417;
  struct StateT * v411 = slot_13(v404);
  return v411;
}

struct StateT * slot_14(struct StateT * v91) {
  int v92 = v91->timer;
  int v102 = v92 + 1;
  v91->timer = v102;
  int * v94 = v91->regs;
  int v95 = v94[5];
  bool v105 = (v95 ^ -2147483648) < -2147483647;
  int v98;
  if (v105) {
    v98 = 1;
  } else {
    v98 = 0;
  }
  int * v99 = v91->regs;
  v99[11] = v98;
  return v91;
}

struct StateT * slot_6(struct StateT * v111) {
  int v112 = v111->timer;
  int v122 = v112 + 1;
  v111->timer = v122;
  int * v114 = v111->regs;
  int v115 = v114[12];
  int * v116 = v111->regs;
  int v117 = v116[14];
  int * v118 = v111->regs;
  int v129 = v115 + v117;
  v118[6] = v129;
  struct StateT * v120 = slot_7(v111);
  return v120;
}

struct StateT * slot_5(struct StateT * v67) {
  int v68 = v67->timer;
  int v80 = v68 + 1;
  v67->timer = v80;
  int * v70 = v67->regs;
  int v71 = v70[14];
  int * v72 = v67->regs;
  int v73 = v72[15];
  bool v85 = v71 >= v73;
  struct StateT * v78;
  if (v85) {
    struct StateT * v74 = slot_14(v67);
    v78 = v74;
  } else {
    struct StateT * v76 = slot_6(v67);
    v78 = v76;
  }
  return v78;
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

struct StateT * slot_7(struct StateT * v132) {
  int v133 = v132->timer;
  int v191 = v133 + 1;
  v132->timer = v191;
  int * v135 = v132->regs;
  int v136 = v135[6];
  int * v137 = v132->cache_keys;
  int v138 = v137[0];
  bool v196 = v138 == ((int)((unsigned int)v136 >> 2));
  int v186;
  if (v196) {
    int * v139 = v132->cache_vals;
    int v140 = v139[0];
    v186 = v140;
  } else {
    int * v142 = v132->cache_keys;
    int v143 = v142[1];
    bool v201 = v143 == ((int)((unsigned int)v136 >> 2));
    int v184;
    if (v201) {
      int * v144 = v132->cache_vals;
      int v145 = v144[1];
      int * v146 = v132->cache_keys;
      int * v147 = v132->cache_keys;
      int v148 = v147[0];
      v146[1] = v148;
      int * v150 = v132->cache_vals;
      int * v151 = v132->cache_vals;
      int v152 = v151[0];
      v150[1] = v152;
      int * v154 = v132->cache_keys;
      int v210 = (int)((unsigned int)v136 >> 2);
      v154[0] = v210;
      int * v156 = v132->cache_vals;
      v156[0] = v145;
      int v158 = v132->timer;
      int v213 = v158 + 1;
      v132->timer = v213;
      v184 = v145;
    } else {
      int * v161 = v132->mem;
      int v215 = (int)((unsigned int)v136 >> 2);
      int v162 = v161[v215];
      int * v163 = v132->mem;
      int * v164 = v132->cache_keys;
      int v165 = v164[1];
      int * v166 = v132->cache_vals;
      int v167 = v166[1];
      v163[v165] = v167;
      int * v169 = v132->cache_keys;
      int * v170 = v132->cache_keys;
      int v171 = v170[0];
      v169[1] = v171;
      int * v173 = v132->cache_vals;
      int * v174 = v132->cache_vals;
      int v175 = v174[0];
      v173[1] = v175;
      int * v177 = v132->cache_keys;
      v177[0] = v215;
      int * v179 = v132->cache_vals;
      v179[0] = v162;
      int v181 = v132->timer;
      int v230 = v181 + 100;
      v132->timer = v230;
      v184 = v162;
    }
    v186 = v184;
  }
  int * v187 = v132->regs;
  v187[7] = v186;
  struct StateT * v189 = slot_8(v132);
  return v189;
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

struct StateT * slot_10(struct StateT * v363) {
  int v364 = v363->timer;
  int v374 = v364 + 1;
  v363->timer = v374;
  int * v366 = v363->regs;
  int v367 = v366[7];
  int * v368 = v363->regs;
  int v369 = v368[9];
  int * v370 = v363->regs;
  int v381 = v367 ^ v369;
  v370[16] = v381;
  struct StateT * v372 = slot_11(v363);
  return v372;
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

struct StateT * slot_8(struct StateT * v237) {
  int v238 = v237->timer;
  int v248 = v238 + 1;
  v237->timer = v248;
  int * v240 = v237->regs;
  int v241 = v240[13];
  int * v242 = v237->regs;
  int v243 = v242[14];
  int * v244 = v237->regs;
  int v255 = v241 + v243;
  v244[8] = v255;
  struct StateT * v246 = slot_9(v237);
  return v246;
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

struct StateT * slot_13(struct StateT * v420) {
  int v421 = v420->timer;
  int v425 = v421 + 1;
  v420->timer = v425;
  struct StateT * v423 = slot_5(v420);
  return v423;
}

struct StateT * slot_9(struct StateT * v258) {
  int v259 = v258->timer;
  int v317 = v259 + 1;
  v258->timer = v317;
  int * v261 = v258->regs;
  int v262 = v261[8];
  int * v263 = v258->cache_keys;
  int v264 = v263[0];
  bool v322 = v264 == ((int)((unsigned int)v262 >> 2));
  int v312;
  if (v322) {
    int * v265 = v258->cache_vals;
    int v266 = v265[0];
    v312 = v266;
  } else {
    int * v268 = v258->cache_keys;
    int v269 = v268[1];
    bool v327 = v269 == ((int)((unsigned int)v262 >> 2));
    int v310;
    if (v327) {
      int * v270 = v258->cache_vals;
      int v271 = v270[1];
      int * v272 = v258->cache_keys;
      int * v273 = v258->cache_keys;
      int v274 = v273[0];
      v272[1] = v274;
      int * v276 = v258->cache_vals;
      int * v277 = v258->cache_vals;
      int v278 = v277[0];
      v276[1] = v278;
      int * v280 = v258->cache_keys;
      int v336 = (int)((unsigned int)v262 >> 2);
      v280[0] = v336;
      int * v282 = v258->cache_vals;
      v282[0] = v271;
      int v284 = v258->timer;
      int v339 = v284 + 1;
      v258->timer = v339;
      v310 = v271;
    } else {
      int * v287 = v258->mem;
      int v341 = (int)((unsigned int)v262 >> 2);
      int v288 = v287[v341];
      int * v289 = v258->mem;
      int * v290 = v258->cache_keys;
      int v291 = v290[1];
      int * v292 = v258->cache_vals;
      int v293 = v292[1];
      v289[v291] = v293;
      int * v295 = v258->cache_keys;
      int * v296 = v258->cache_keys;
      int v297 = v296[0];
      v295[1] = v297;
      int * v299 = v258->cache_vals;
      int * v300 = v258->cache_vals;
      int v301 = v300[0];
      v299[1] = v301;
      int * v303 = v258->cache_keys;
      v303[0] = v341;
      int * v305 = v258->cache_vals;
      v305[0] = v288;
      int v307 = v258->timer;
      int v356 = v307 + 100;
      v258->timer = v356;
      v310 = v288;
    }
    v312 = v310;
  }
  int * v313 = v258->regs;
  v313[9] = v312;
  struct StateT * v315 = slot_10(v258);
  return v315;
}

struct StateT * slot_11(struct StateT * v384) {
  int v385 = v384->timer;
  int v395 = v385 + 1;
  v384->timer = v395;
  int * v387 = v384->regs;
  int v388 = v387[5];
  int * v389 = v384->regs;
  int v390 = v389[16];
  int * v391 = v384->regs;
  int v401 = v388 | v390;
  v391[5] = v401;
  struct StateT * v393 = slot_12(v384);
  return v393;
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