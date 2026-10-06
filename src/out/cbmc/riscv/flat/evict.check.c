// verify: clean (CBMC should report VERIFICATION SUCCESSFUL) [unwind 65]
#define NUM_REGS 32
#define MEM_SIZE 64
#define SECRET_SIZE 10
#define SECRET_OFFSET 20
#define CACHE_ENTRIES 2
#define CACHE_WORDS 2

#ifdef CBMC
int nondet_uint();
#define koika_assert(b, s) __CPROVER_assert(b, s)
#define koika_assume(b) __CPROVER_assume(b)
#define koika_draw(x) ((x) = nondet_uint())
#define koika_secret(x) ((void)0)
#else
#define koika_assert(b, s) 0
#define koika_assume(b) 0
#define koika_draw(x) ((x) = 0)
#define koika_secret(x) ((void)0)
#endif
int bounded(int low, int high) {
  int x;
  koika_draw(x);
  koika_assume(low <= x && x <= high);
  return x;
}
// Same draw as `bounded`, said of the secret, so a backend that tracks
// where the secret goes has somewhere to start. Self-composition already
// encodes the split by drawing these twice, which is why the mark is
// nothing under a checker that reads the two runs exactly.
int secret(int low, int high) {
  int x = bounded(low, high);
  koika_secret(x);
  return x;
}

/*****************************************
Emitting C Generated Code
*******************************************/

#include <stdbool.h>

struct StateT {
  int regs[32];
  int mem[64];
  int saved_regs[32];
  int reg_ready[32];
  int cache_tags[2];
  int cache_dirty[2];
  int cache_age[2];
  int cache_vals[2];
  int timer;
};

struct StateT * snippet(struct StateT * v0);
struct StateT * slot_1(struct StateT * v109);
struct StateT * slot_6(struct StateT * v365);
struct StateT * slot_5(struct StateT * v258);
struct StateT * slot_4(struct StateT * v152);
struct StateT * slot_2(struct StateT * v124);
struct StateT * slot_7(struct StateT * v481);
struct StateT * slot_3(struct StateT * v138);
struct StateT * slot_0(struct StateT * v2);
struct StateT * snippet(struct StateT * v0) {
  struct StateT * v1 = slot_0(v0);
  return v1;
}

struct StateT * slot_1(struct StateT * v109) {
  int v110 = v109->timer;
  int v117 = v110 + 1;
  v109->timer = v117;
  int * v112 = v109->regs;
  int v113 = v112[5];
  int v121 = v113 & 1;
  v112[6] = v121;
  struct StateT * v115 = slot_2(v109);
  return v115;
}

struct StateT * slot_6(struct StateT * v365) {
  int v366 = v365->timer;
  int v429 = v366 + 1;
  v365->timer = v429;
  int * v368 = v365->regs;
  int v369 = v368[6];
  int * v370 = v365->cache_tags;
  int v371 = v370[0];
  int v372 = v370[1];
  int v373 = v365->timer;
  int v435 = v373 + (100 ^ (((~(((v371 ^ ((int)((unsigned int)v369 >> 2))) | (-(v371 ^ ((int)((unsigned int)v369 >> 2))))) >> 31)) | (~(((v372 ^ ((int)((unsigned int)v369 >> 2))) | (-(v372 ^ ((int)((unsigned int)v369 >> 2))))) >> 31))) & 101));
  v365->timer = v435;
  int * v375 = v365->cache_vals;
  bool v436 = !(((~(((v371 ^ ((int)((unsigned int)v369 >> 2))) | (-(v371 ^ ((int)((unsigned int)v369 >> 2))))) >> 31)) | (~(((v372 ^ ((int)((unsigned int)v369 >> 2))) | (-(v372 ^ ((int)((unsigned int)v369 >> 2))))) >> 31))) == 0);
  int v423;
  if (v436) {
    int * v376 = v365->cache_age;
    int v438 = (~(((v372 ^ ((int)((unsigned int)v369 >> 2))) | (-(v372 ^ ((int)((unsigned int)v369 >> 2))))) >> 31)) & 1;
    int v377 = v376[v438];
    int v378 = v376[0];
    int v439 = v378 + ((int)((unsigned int)(v378 - v377) >> 31));
    v376[0] = v439;
    int * v380 = v365->cache_age;
    int v381 = v380[1];
    int v441 = v381 + ((int)((unsigned int)(v381 - v377) >> 31));
    v380[1] = v441;
    int * v383 = v365->cache_age;
    v383[v438] = 0;
    v423 = v438;
  } else {
    int * v386 = v365->cache_age;
    int v387 = v386[0];
    int * v388 = v365->cache_tags;
    int v389 = v388[0];
    int v390 = v386[1];
    int v391 = v388[1];
    int * v392 = v365->cache_dirty;
    int v448 = (((v387 + ((~(((v389 ^ -1) | (-(v389 ^ -1))) >> 31)) & 2)) - (v390 + ((~(((v391 ^ -1) | (-(v391 ^ -1))) >> 31)) & 2))) >> 31) & 1;
    int v393 = v392[v448];
    bool v449 = !(v393 == 0);
    if (v449) {
      int * v394 = v365->cache_tags;
      int v395 = v394[v448];
      int * v396 = v365->cache_vals;
      int v452 = (((v387 + ((~(((v389 ^ -1) | (-(v389 ^ -1))) >> 31)) & 2)) - (v390 + ((~(((v391 ^ -1) | (-(v391 ^ -1))) >> 31)) & 2))) >> 31) & 1;
      int v397 = v396[v452];
      int * v398 = v365->mem;
      v398[v395] = v397;
      ;
    } else {
      ;
    }
    int * v403 = v365->mem;
    int v459 = (int)((unsigned int)v369 >> 2);
    int v404 = v403[v459];
    int * v405 = v365->cache_vals;
    int v461 = (((v387 + ((~(((v389 ^ -1) | (-(v389 ^ -1))) >> 31)) & 2)) - (v390 + ((~(((v391 ^ -1) | (-(v391 ^ -1))) >> 31)) & 2))) >> 31) & 1;
    v405[v461] = v404;
    int * v407 = v365->cache_tags;
    int v464 = (int)((unsigned int)v369 >> 2);
    v407[v448] = v464;
    int * v409 = v365->cache_dirty;
    v409[v448] = 0;
    int * v411 = v365->cache_age;
    v411[v448] = 1;
    int * v413 = v365->cache_age;
    int v414 = v413[v448];
    int v415 = v413[0];
    int v470 = v415 + ((int)((unsigned int)(v415 - v414) >> 31));
    v413[0] = v470;
    int * v417 = v365->cache_age;
    int v418 = v417[1];
    int v472 = v418 + ((int)((unsigned int)(v418 - v414) >> 31));
    v417[1] = v472;
    int * v420 = v365->cache_age;
    v420[v448] = 0;
    v423 = v448;
  }
  int v424 = v375[v423];
  int * v425 = v365->regs;
  v425[9] = v424;
  struct StateT * v427 = slot_7(v365);
  return v427;
}

struct StateT * slot_5(struct StateT * v258) {
  int v259 = v258->timer;
  int v320 = v259 + 1;
  v258->timer = v320;
  int * v261 = v258->cache_tags;
  int v262 = v261[0];
  int v263 = v261[1];
  int v264 = v258->timer;
  int v324 = v264 + (100 ^ (((~(((v262 ^ 4) | (-(v262 ^ 4))) >> 31)) | (~(((v263 ^ 4) | (-(v263 ^ 4))) >> 31))) & 101));
  v258->timer = v324;
  int * v266 = v258->cache_vals;
  bool v325 = !(((~(((v262 ^ 4) | (-(v262 ^ 4))) >> 31)) | (~(((v263 ^ 4) | (-(v263 ^ 4))) >> 31))) == 0);
  int v314;
  if (v325) {
    int * v267 = v258->cache_age;
    int v327 = (~(((v263 ^ 4) | (-(v263 ^ 4))) >> 31)) & 1;
    int v268 = v267[v327];
    int v269 = v267[0];
    int v328 = v269 + ((int)((unsigned int)(v269 - v268) >> 31));
    v267[0] = v328;
    int * v271 = v258->cache_age;
    int v272 = v271[1];
    int v330 = v272 + ((int)((unsigned int)(v272 - v268) >> 31));
    v271[1] = v330;
    int * v274 = v258->cache_age;
    v274[v327] = 0;
    v314 = v327;
  } else {
    int * v277 = v258->cache_age;
    int v278 = v277[0];
    int * v279 = v258->cache_tags;
    int v280 = v279[0];
    int v281 = v277[1];
    int v282 = v279[1];
    int * v283 = v258->cache_dirty;
    int v335 = (((v278 + ((~(((v280 ^ -1) | (-(v280 ^ -1))) >> 31)) & 2)) - (v281 + ((~(((v282 ^ -1) | (-(v282 ^ -1))) >> 31)) & 2))) >> 31) & 1;
    int v284 = v283[v335];
    bool v336 = !(v284 == 0);
    if (v336) {
      int * v285 = v258->cache_tags;
      int v286 = v285[v335];
      int * v287 = v258->cache_vals;
      int v339 = (((v278 + ((~(((v280 ^ -1) | (-(v280 ^ -1))) >> 31)) & 2)) - (v281 + ((~(((v282 ^ -1) | (-(v282 ^ -1))) >> 31)) & 2))) >> 31) & 1;
      int v288 = v287[v339];
      int * v289 = v258->mem;
      v289[v286] = v288;
      ;
    } else {
      ;
    }
    int * v294 = v258->mem;
    int v295 = v294[4];
    int * v296 = v258->cache_vals;
    int v348 = (((v278 + ((~(((v280 ^ -1) | (-(v280 ^ -1))) >> 31)) & 2)) - (v281 + ((~(((v282 ^ -1) | (-(v282 ^ -1))) >> 31)) & 2))) >> 31) & 1;
    v296[v348] = v295;
    int * v298 = v258->cache_tags;
    v298[v335] = 4;
    int * v300 = v258->cache_dirty;
    v300[v335] = 0;
    int * v302 = v258->cache_age;
    v302[v335] = 1;
    int * v304 = v258->cache_age;
    int v305 = v304[v335];
    int v306 = v304[0];
    int v354 = v306 + ((int)((unsigned int)(v306 - v305) >> 31));
    v304[0] = v354;
    int * v308 = v258->cache_age;
    int v309 = v308[1];
    int v356 = v309 + ((int)((unsigned int)(v309 - v305) >> 31));
    v308[1] = v356;
    int * v311 = v258->cache_age;
    v311[v335] = 0;
    v314 = v335;
  }
  int v315 = v266[v314];
  int * v316 = v258->regs;
  v316[8] = v315;
  struct StateT * v318 = slot_6(v258);
  return v318;
}

struct StateT * slot_4(struct StateT * v152) {
  int v153 = v152->timer;
  int v214 = v153 + 1;
  v152->timer = v214;
  int * v155 = v152->cache_tags;
  int v156 = v155[0];
  int v157 = v155[1];
  int v158 = v152->timer;
  int v218 = v158 + (100 ^ (((~((v156 | (-v156)) >> 31)) | (~((v157 | (-v157)) >> 31))) & 101));
  v152->timer = v218;
  int * v160 = v152->cache_vals;
  bool v219 = !(((~((v156 | (-v156)) >> 31)) | (~((v157 | (-v157)) >> 31))) == 0);
  int v208;
  if (v219) {
    int * v161 = v152->cache_age;
    int v221 = (~((v157 | (-v157)) >> 31)) & 1;
    int v162 = v161[v221];
    int v163 = v161[0];
    int v222 = v163 + ((int)((unsigned int)(v163 - v162) >> 31));
    v161[0] = v222;
    int * v165 = v152->cache_age;
    int v166 = v165[1];
    int v224 = v166 + ((int)((unsigned int)(v166 - v162) >> 31));
    v165[1] = v224;
    int * v168 = v152->cache_age;
    v168[v221] = 0;
    v208 = v221;
  } else {
    int * v171 = v152->cache_age;
    int v172 = v171[0];
    int * v173 = v152->cache_tags;
    int v174 = v173[0];
    int v175 = v171[1];
    int v176 = v173[1];
    int * v177 = v152->cache_dirty;
    int v229 = (((v172 + ((~(((v174 ^ -1) | (-(v174 ^ -1))) >> 31)) & 2)) - (v175 + ((~(((v176 ^ -1) | (-(v176 ^ -1))) >> 31)) & 2))) >> 31) & 1;
    int v178 = v177[v229];
    bool v230 = !(v178 == 0);
    if (v230) {
      int * v179 = v152->cache_tags;
      int v180 = v179[v229];
      int * v181 = v152->cache_vals;
      int v233 = (((v172 + ((~(((v174 ^ -1) | (-(v174 ^ -1))) >> 31)) & 2)) - (v175 + ((~(((v176 ^ -1) | (-(v176 ^ -1))) >> 31)) & 2))) >> 31) & 1;
      int v182 = v181[v233];
      int * v183 = v152->mem;
      v183[v180] = v182;
      ;
    } else {
      ;
    }
    int * v188 = v152->mem;
    int v189 = v188[0];
    int * v190 = v152->cache_vals;
    int v241 = (((v172 + ((~(((v174 ^ -1) | (-(v174 ^ -1))) >> 31)) & 2)) - (v175 + ((~(((v176 ^ -1) | (-(v176 ^ -1))) >> 31)) & 2))) >> 31) & 1;
    v190[v241] = v189;
    int * v192 = v152->cache_tags;
    v192[v229] = 0;
    int * v194 = v152->cache_dirty;
    v194[v229] = 0;
    int * v196 = v152->cache_age;
    v196[v229] = 1;
    int * v198 = v152->cache_age;
    int v199 = v198[v229];
    int v200 = v198[0];
    int v247 = v200 + ((int)((unsigned int)(v200 - v199) >> 31));
    v198[0] = v247;
    int * v202 = v152->cache_age;
    int v203 = v202[1];
    int v249 = v203 + ((int)((unsigned int)(v203 - v199) >> 31));
    v202[1] = v249;
    int * v205 = v152->cache_age;
    v205[v229] = 0;
    v208 = v229;
  }
  int v209 = v160[v208];
  int * v210 = v152->regs;
  v210[7] = v209;
  struct StateT * v212 = slot_5(v152);
  return v212;
}

struct StateT * slot_2(struct StateT * v124) {
  int v125 = v124->timer;
  int v132 = v125 + 1;
  v124->timer = v132;
  int * v127 = v124->regs;
  int v128 = v127[6];
  int v135 = v128 << 3;
  v127[6] = v135;
  struct StateT * v130 = slot_3(v124);
  return v130;
}

struct StateT * slot_7(struct StateT * v481) {
  int v482 = v481->timer;
  int v542 = v482 + 1;
  v481->timer = v542;
  int * v484 = v481->cache_tags;
  int v485 = v484[0];
  int v486 = v484[1];
  int v487 = v481->timer;
  int v546 = v487 + (100 ^ (((~((v485 | (-v485)) >> 31)) | (~((v486 | (-v486)) >> 31))) & 101));
  v481->timer = v546;
  int * v489 = v481->cache_vals;
  bool v547 = !(((~((v485 | (-v485)) >> 31)) | (~((v486 | (-v486)) >> 31))) == 0);
  int v537;
  if (v547) {
    int * v490 = v481->cache_age;
    int v549 = (~((v486 | (-v486)) >> 31)) & 1;
    int v491 = v490[v549];
    int v492 = v490[0];
    int v550 = v492 + ((int)((unsigned int)(v492 - v491) >> 31));
    v490[0] = v550;
    int * v494 = v481->cache_age;
    int v495 = v494[1];
    int v552 = v495 + ((int)((unsigned int)(v495 - v491) >> 31));
    v494[1] = v552;
    int * v497 = v481->cache_age;
    v497[v549] = 0;
    v537 = v549;
  } else {
    int * v500 = v481->cache_age;
    int v501 = v500[0];
    int * v502 = v481->cache_tags;
    int v503 = v502[0];
    int v504 = v500[1];
    int v505 = v502[1];
    int * v506 = v481->cache_dirty;
    int v557 = (((v501 + ((~(((v503 ^ -1) | (-(v503 ^ -1))) >> 31)) & 2)) - (v504 + ((~(((v505 ^ -1) | (-(v505 ^ -1))) >> 31)) & 2))) >> 31) & 1;
    int v507 = v506[v557];
    bool v558 = !(v507 == 0);
    if (v558) {
      int * v508 = v481->cache_tags;
      int v509 = v508[v557];
      int * v510 = v481->cache_vals;
      int v561 = (((v501 + ((~(((v503 ^ -1) | (-(v503 ^ -1))) >> 31)) & 2)) - (v504 + ((~(((v505 ^ -1) | (-(v505 ^ -1))) >> 31)) & 2))) >> 31) & 1;
      int v511 = v510[v561];
      int * v512 = v481->mem;
      v512[v509] = v511;
      ;
    } else {
      ;
    }
    int * v517 = v481->mem;
    int v518 = v517[0];
    int * v519 = v481->cache_vals;
    int v569 = (((v501 + ((~(((v503 ^ -1) | (-(v503 ^ -1))) >> 31)) & 2)) - (v504 + ((~(((v505 ^ -1) | (-(v505 ^ -1))) >> 31)) & 2))) >> 31) & 1;
    v519[v569] = v518;
    int * v521 = v481->cache_tags;
    v521[v557] = 0;
    int * v523 = v481->cache_dirty;
    v523[v557] = 0;
    int * v525 = v481->cache_age;
    v525[v557] = 1;
    int * v527 = v481->cache_age;
    int v528 = v527[v557];
    int v529 = v527[0];
    int v575 = v529 + ((int)((unsigned int)(v529 - v528) >> 31));
    v527[0] = v575;
    int * v531 = v481->cache_age;
    int v532 = v531[1];
    int v577 = v532 + ((int)((unsigned int)(v532 - v528) >> 31));
    v531[1] = v577;
    int * v534 = v481->cache_age;
    v534[v557] = 0;
    v537 = v557;
  }
  int v538 = v489[v537];
  int * v539 = v481->regs;
  v539[11] = v538;
  return v481;
}

struct StateT * slot_3(struct StateT * v138) {
  int v139 = v138->timer;
  int v146 = v139 + 1;
  v138->timer = v146;
  int * v141 = v138->regs;
  int v142 = v141[6];
  int v149 = v142 + 32;
  v141[6] = v149;
  struct StateT * v144 = slot_4(v138);
  return v144;
}

struct StateT * slot_0(struct StateT * v2) {
  int v3 = v2->timer;
  int v64 = v3 + 1;
  v2->timer = v64;
  int * v5 = v2->cache_tags;
  int v6 = v5[0];
  int v7 = v5[1];
  int v8 = v2->timer;
  int v68 = v8 + (100 ^ (((~(((v6 ^ 20) | (-(v6 ^ 20))) >> 31)) | (~(((v7 ^ 20) | (-(v7 ^ 20))) >> 31))) & 101));
  v2->timer = v68;
  int * v10 = v2->cache_vals;
  bool v69 = !(((~(((v6 ^ 20) | (-(v6 ^ 20))) >> 31)) | (~(((v7 ^ 20) | (-(v7 ^ 20))) >> 31))) == 0);
  int v58;
  if (v69) {
    int * v11 = v2->cache_age;
    int v71 = (~(((v7 ^ 20) | (-(v7 ^ 20))) >> 31)) & 1;
    int v12 = v11[v71];
    int v13 = v11[0];
    int v72 = v13 + ((int)((unsigned int)(v13 - v12) >> 31));
    v11[0] = v72;
    int * v15 = v2->cache_age;
    int v16 = v15[1];
    int v74 = v16 + ((int)((unsigned int)(v16 - v12) >> 31));
    v15[1] = v74;
    int * v18 = v2->cache_age;
    v18[v71] = 0;
    v58 = v71;
  } else {
    int * v21 = v2->cache_age;
    int v22 = v21[0];
    int * v23 = v2->cache_tags;
    int v24 = v23[0];
    int v25 = v21[1];
    int v26 = v23[1];
    int * v27 = v2->cache_dirty;
    int v79 = (((v22 + ((~(((v24 ^ -1) | (-(v24 ^ -1))) >> 31)) & 2)) - (v25 + ((~(((v26 ^ -1) | (-(v26 ^ -1))) >> 31)) & 2))) >> 31) & 1;
    int v28 = v27[v79];
    bool v80 = !(v28 == 0);
    if (v80) {
      int * v29 = v2->cache_tags;
      int v30 = v29[v79];
      int * v31 = v2->cache_vals;
      int v83 = (((v22 + ((~(((v24 ^ -1) | (-(v24 ^ -1))) >> 31)) & 2)) - (v25 + ((~(((v26 ^ -1) | (-(v26 ^ -1))) >> 31)) & 2))) >> 31) & 1;
      int v32 = v31[v83];
      int * v33 = v2->mem;
      v33[v30] = v32;
      ;
    } else {
      ;
    }
    int * v38 = v2->mem;
    int v39 = v38[20];
    int * v40 = v2->cache_vals;
    int v92 = (((v22 + ((~(((v24 ^ -1) | (-(v24 ^ -1))) >> 31)) & 2)) - (v25 + ((~(((v26 ^ -1) | (-(v26 ^ -1))) >> 31)) & 2))) >> 31) & 1;
    v40[v92] = v39;
    int * v42 = v2->cache_tags;
    v42[v79] = 20;
    int * v44 = v2->cache_dirty;
    v44[v79] = 0;
    int * v46 = v2->cache_age;
    v46[v79] = 1;
    int * v48 = v2->cache_age;
    int v49 = v48[v79];
    int v50 = v48[0];
    int v98 = v50 + ((int)((unsigned int)(v50 - v49) >> 31));
    v48[0] = v98;
    int * v52 = v2->cache_age;
    int v53 = v52[1];
    int v100 = v53 + ((int)((unsigned int)(v53 - v49) >> 31));
    v52[1] = v100;
    int * v55 = v2->cache_age;
    v55[v79] = 0;
    v58 = v79;
  }
  int v59 = v10[v58];
  int * v60 = v2->regs;
  v60[5] = v59;
  struct StateT * v62 = slot_1(v2);
  return v62;
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
  for (int i=0; i<CACHE_ENTRIES; i++) {
    s->cache_tags[i] = -1;
    s->cache_dirty[i] = 0;
    s->cache_age[i] = 0;
  }
  for (int i=0; i<CACHE_WORDS; i++) {
    s->cache_vals[i] = 0;
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
    s1.mem[SECRET_OFFSET+i] = secret(0, 20);
    s2.mem[SECRET_OFFSET+i] = secret(0, 20);
  }
  struct StateT *s1_ = snippet(&s1);
  struct StateT *s2_ = snippet(&s2);
  //@ assert untainted_timer: !\tainted(s1_->timer==s2_->timer);
  koika_assert(s1_->timer==s2_->timer, "timing leak");
  return 0;
}