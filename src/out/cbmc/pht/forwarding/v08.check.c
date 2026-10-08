// verify: leak (CBMC should report VERIFICATION FAILED) [unwind 65]
#define NUM_REGS 32
#define MEM_SIZE 64
#define SECRET_SIZE 10
#define SECRET_OFFSET 20
#define CACHE_ENTRIES 12
#define CACHE_WORDS 24

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
  int cache_tags[12];
  int cache_dirty[12];
  int cache_age[12];
  int cache_vals[24];
  int timer;
};

struct StateT * slot_12(struct StateT * v560);
struct StateT * slot_6(struct StateT * v284);
struct StateT * slot_16(struct StateT * v615);
struct StateT * slot_5(struct StateT * v270);
struct StateT * slot_2(struct StateT * v218);
struct StateT * slot_7(struct StateT * v298);
struct StateT * slot_21(struct StateT * v1369);
struct StateT * slot_3(struct StateT * v233);
struct StateT * slot_10(struct StateT * v344);
struct StateT * slot_1(struct StateT * v15);
struct StateT * slot_19(struct StateT * v1038);
struct StateT * slot_13(struct StateT * v574);
struct StateT * slot_0(struct StateT * v2);
struct StateT * slot_14(struct StateT * v587);
struct StateT * slot_17(struct StateT * v631);
struct StateT * slot_20(struct StateT * v1054);
struct StateT * snippet(struct StateT * v0);
struct StateT * slot_8(struct StateT * v314);
struct StateT * slot_4(struct StateT * v257);
struct StateT * slot_15(struct StateT * v601);
struct StateT * slot_18(struct StateT * v834);
struct StateT * slot_9(struct StateT * v328);
struct StateT * slot_11(struct StateT * v547);
struct StateT * slot_12(struct StateT * v560) {
  int v561 = v560->timer;
  int v568 = v561 + 1;
  v560->timer = v568;
  int * v563 = v560->regs;
  int v564 = v563[11];
  int v571 = v564 + 4;
  v563[11] = v571;
  struct StateT * v566 = slot_13(v560);
  return v566;
}

struct StateT * slot_6(struct StateT * v284) {
  int v285 = v284->timer;
  int v292 = v285 + 1;
  v284->timer = v292;
  int * v287 = v284->regs;
  int v288 = v287[10];
  int v295 = -v288;
  v287[10] = v295;
  struct StateT * v290 = slot_7(v284);
  return v290;
}

struct StateT * slot_16(struct StateT * v615) {
  int v616 = v615->timer;
  int v624 = v616 + 1;
  v615->timer = v624;
  int * v618 = v615->regs;
  int v619 = v618[11];
  int v620 = v618[10];
  int v628 = v619 + v620;
  v618[10] = v628;
  struct StateT * v622 = slot_17(v615);
  return v622;
}

struct StateT * slot_5(struct StateT * v270) {
  int v271 = v270->timer;
  int v278 = v271 + 1;
  v270->timer = v278;
  int * v273 = v270->regs;
  int v274 = v273[11];
  int v281 = v274 + 72;
  v273[11] = v281;
  struct StateT * v276 = slot_6(v270);
  return v276;
}

struct StateT * slot_2(struct StateT * v218) {
  int v219 = v218->timer;
  int v226 = v219 + 1;
  v218->timer = v226;
  int * v221 = v218->regs;
  int v222 = v221[10];
  int v230 = v222 + 1;
  v221[12] = v230;
  struct StateT * v224 = slot_3(v218);
  return v224;
}

struct StateT * slot_7(struct StateT * v298) {
  int v299 = v298->timer;
  int v307 = v299 + 1;
  v298->timer = v307;
  int * v301 = v298->regs;
  int v302 = v301[10];
  int v303 = v301[12];
  int v311 = v302 & v303;
  v301[10] = v311;
  struct StateT * v305 = slot_8(v298);
  return v305;
}

struct StateT * slot_21(struct StateT * v1369) {
  int v1370 = v1369->timer;
  int v1373 = v1370 + 1;
  v1369->timer = v1373;
  return v1369;
}

struct StateT * slot_3(struct StateT * v233) {
  int v234 = v233->timer;
  int v246 = v234 + 1;
  v233->timer = v246;
  int * v236 = v233->regs;
  int v237 = v236[10];
  int v238 = v236[11];
  bool v250 = (v237 ^ -2147483648) < (v238 ^ -2147483648);
  int v241;
  if (v250) {
    v241 = 1;
  } else {
    v241 = 0;
  }
  int * v242 = v233->regs;
  v242[10] = v241;
  struct StateT * v244 = slot_4(v233);
  return v244;
}

struct StateT * slot_10(struct StateT * v344) {
  int v345 = v344->timer;
  int v455 = v345 + 1;
  v344->timer = v455;
  int * v347 = v344->regs;
  int v348 = v347[10];
  int * v349 = v344->cache_tags;
  int v459 = (((int)((unsigned int)((int)((unsigned int)v348 >> 2)) >> 1)) & 1) * 2;
  int v350 = v349[v459];
  int v460 = ((((int)((unsigned int)((int)((unsigned int)v348 >> 2)) >> 1)) & 1) * 2) + 1;
  int v351 = v349[v460];
  int v461 = 4 + ((((int)((unsigned int)((int)((unsigned int)v348 >> 2)) >> 1)) & 3) * 2);
  int v352 = v349[v461];
  int v462 = (4 + ((((int)((unsigned int)((int)((unsigned int)v348 >> 2)) >> 1)) & 3) * 2)) + 1;
  int v353 = v349[v462];
  int v354 = v344->timer;
  int v463 = v354 + ((100 ^ (((~(((v352 ^ ((int)((unsigned int)((int)((unsigned int)v348 >> 2)) >> 1))) | (-(v352 ^ ((int)((unsigned int)((int)((unsigned int)v348 >> 2)) >> 1))))) >> 31)) | (~(((v353 ^ ((int)((unsigned int)((int)((unsigned int)v348 >> 2)) >> 1))) | (-(v353 ^ ((int)((unsigned int)((int)((unsigned int)v348 >> 2)) >> 1))))) >> 31))) & 104)) ^ (((~(((v350 ^ ((int)((unsigned int)((int)((unsigned int)v348 >> 2)) >> 1))) | (-(v350 ^ ((int)((unsigned int)((int)((unsigned int)v348 >> 2)) >> 1))))) >> 31)) | (~(((v351 ^ ((int)((unsigned int)((int)((unsigned int)v348 >> 2)) >> 1))) | (-(v351 ^ ((int)((unsigned int)((int)((unsigned int)v348 >> 2)) >> 1))))) >> 31))) & (1 ^ (100 ^ (((~(((v352 ^ ((int)((unsigned int)((int)((unsigned int)v348 >> 2)) >> 1))) | (-(v352 ^ ((int)((unsigned int)((int)((unsigned int)v348 >> 2)) >> 1))))) >> 31)) | (~(((v353 ^ ((int)((unsigned int)((int)((unsigned int)v348 >> 2)) >> 1))) | (-(v353 ^ ((int)((unsigned int)((int)((unsigned int)v348 >> 2)) >> 1))))) >> 31))) & 104)))));
  v344->timer = v463;
  int * v356 = v344->cache_vals;
  bool v464 = !(((~(((v350 ^ ((int)((unsigned int)((int)((unsigned int)v348 >> 2)) >> 1))) | (-(v350 ^ ((int)((unsigned int)((int)((unsigned int)v348 >> 2)) >> 1))))) >> 31)) | (~(((v351 ^ ((int)((unsigned int)((int)((unsigned int)v348 >> 2)) >> 1))) | (-(v351 ^ ((int)((unsigned int)((int)((unsigned int)v348 >> 2)) >> 1))))) >> 31))) == 0);
  int v449;
  if (v464) {
    int * v357 = v344->cache_age;
    int v466 = ((((int)((unsigned int)((int)((unsigned int)v348 >> 2)) >> 1)) & 1) * 2) + ((~(((v351 ^ ((int)((unsigned int)((int)((unsigned int)v348 >> 2)) >> 1))) | (-(v351 ^ ((int)((unsigned int)((int)((unsigned int)v348 >> 2)) >> 1))))) >> 31)) & 1);
    int v358 = v357[v466];
    int v359 = v357[v459];
    int v467 = v359 + ((int)((unsigned int)(v359 - v358) >> 31));
    v357[v459] = v467;
    int * v361 = v344->cache_age;
    int v362 = v361[v460];
    int v469 = v362 + ((int)((unsigned int)(v362 - v358) >> 31));
    v361[v460] = v469;
    int * v364 = v344->cache_age;
    v364[v466] = 0;
    v449 = v466;
  } else {
    int * v367 = v344->cache_age;
    int v473 = (((int)((unsigned int)((int)((unsigned int)v348 >> 2)) >> 1)) & 1) * 2;
    int v368 = v367[v473];
    int * v369 = v344->cache_tags;
    int v370 = v369[v473];
    int v371 = v367[v460];
    int v372 = v369[v460];
    bool v475 = !(((~(((v352 ^ ((int)((unsigned int)((int)((unsigned int)v348 >> 2)) >> 1))) | (-(v352 ^ ((int)((unsigned int)((int)((unsigned int)v348 >> 2)) >> 1))))) >> 31)) | (~(((v353 ^ ((int)((unsigned int)((int)((unsigned int)v348 >> 2)) >> 1))) | (-(v353 ^ ((int)((unsigned int)((int)((unsigned int)v348 >> 2)) >> 1))))) >> 31))) == 0);
    int v426;
    if (v475) {
      int * v373 = v344->cache_age;
      int v477 = (4 + ((((int)((unsigned int)((int)((unsigned int)v348 >> 2)) >> 1)) & 3) * 2)) + ((~(((v353 ^ ((int)((unsigned int)((int)((unsigned int)v348 >> 2)) >> 1))) | (-(v353 ^ ((int)((unsigned int)((int)((unsigned int)v348 >> 2)) >> 1))))) >> 31)) & 1);
      int v374 = v373[v477];
      int v375 = v373[v461];
      int v478 = v375 + ((int)((unsigned int)(v375 - v374) >> 31));
      v373[v461] = v478;
      int * v377 = v344->cache_age;
      int v378 = v377[v462];
      int v480 = v378 + ((int)((unsigned int)(v378 - v374) >> 31));
      v377[v462] = v480;
      int * v380 = v344->cache_age;
      v380[v477] = 0;
      v426 = v477;
    } else {
      int * v383 = v344->cache_age;
      int v484 = 4 + ((((int)((unsigned int)((int)((unsigned int)v348 >> 2)) >> 1)) & 3) * 2);
      int v384 = v383[v484];
      int * v385 = v344->cache_tags;
      int v386 = v385[v484];
      int v387 = v383[v462];
      int v388 = v385[v462];
      int * v389 = v344->cache_dirty;
      int v487 = (4 + ((((int)((unsigned int)((int)((unsigned int)v348 >> 2)) >> 1)) & 3) * 2)) + ((((v384 + ((~(((v386 ^ -1) | (-(v386 ^ -1))) >> 31)) & 2)) - (v387 + ((~(((v388 ^ -1) | (-(v388 ^ -1))) >> 31)) & 2))) >> 31) & 1);
      int v390 = v389[v487];
      bool v488 = !(v390 == 0);
      if (v488) {
        int * v391 = v344->cache_tags;
        int v392 = v391[v487];
        int * v393 = v344->cache_vals;
        int v491 = ((4 + ((((int)((unsigned int)((int)((unsigned int)v348 >> 2)) >> 1)) & 3) * 2)) + ((((v384 + ((~(((v386 ^ -1) | (-(v386 ^ -1))) >> 31)) & 2)) - (v387 + ((~(((v388 ^ -1) | (-(v388 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
        int v394 = v393[v491];
        int v492 = (((4 + ((((int)((unsigned int)((int)((unsigned int)v348 >> 2)) >> 1)) & 3) * 2)) + ((((v384 + ((~(((v386 ^ -1) | (-(v386 ^ -1))) >> 31)) & 2)) - (v387 + ((~(((v388 ^ -1) | (-(v388 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
        int v395 = v393[v492];
        int * v396 = v344->mem;
        int v494 = v392 * 2;
        v396[v494] = v394;
        int * v398 = v344->mem;
        int v497 = (v392 * 2) + 1;
        v398[v497] = v395;
        ;
      } else {
        ;
      }
      int * v403 = v344->mem;
      int v502 = ((int)((unsigned int)((int)((unsigned int)v348 >> 2)) >> 1)) * 2;
      int v404 = v403[v502];
      int v503 = (((int)((unsigned int)((int)((unsigned int)v348 >> 2)) >> 1)) * 2) + 1;
      int v405 = v403[v503];
      int * v406 = v344->cache_vals;
      int v505 = ((4 + ((((int)((unsigned int)((int)((unsigned int)v348 >> 2)) >> 1)) & 3) * 2)) + ((((v384 + ((~(((v386 ^ -1) | (-(v386 ^ -1))) >> 31)) & 2)) - (v387 + ((~(((v388 ^ -1) | (-(v388 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
      v406[v505] = v404;
      int * v408 = v344->cache_vals;
      int v508 = (((4 + ((((int)((unsigned int)((int)((unsigned int)v348 >> 2)) >> 1)) & 3) * 2)) + ((((v384 + ((~(((v386 ^ -1) | (-(v386 ^ -1))) >> 31)) & 2)) - (v387 + ((~(((v388 ^ -1) | (-(v388 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
      v408[v508] = v405;
      int * v410 = v344->cache_tags;
      int v511 = (int)((unsigned int)((int)((unsigned int)v348 >> 2)) >> 1);
      v410[v487] = v511;
      int * v412 = v344->cache_dirty;
      v412[v487] = 0;
      int * v414 = v344->cache_age;
      v414[v487] = 1;
      int * v416 = v344->cache_age;
      int v417 = v416[v487];
      int v418 = v416[v461];
      int v517 = v418 + ((int)((unsigned int)(v418 - v417) >> 31));
      v416[v461] = v517;
      int * v420 = v344->cache_age;
      int v421 = v420[v462];
      int v519 = v421 + ((int)((unsigned int)(v421 - v417) >> 31));
      v420[v462] = v519;
      int * v423 = v344->cache_age;
      v423[v487] = 0;
      v426 = v487;
    }
    int * v427 = v344->cache_vals;
    int v522 = v426 * 2;
    int v428 = v427[v522];
    int v523 = (v426 * 2) + 1;
    int v429 = v427[v523];
    int v524 = (((((int)((unsigned int)((int)((unsigned int)v348 >> 2)) >> 1)) & 1) * 2) + ((((v368 + ((~(((v370 ^ -1) | (-(v370 ^ -1))) >> 31)) & 2)) - (v371 + ((~(((v372 ^ -1) | (-(v372 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
    v427[v524] = v428;
    int * v431 = v344->cache_vals;
    int v527 = ((((((int)((unsigned int)((int)((unsigned int)v348 >> 2)) >> 1)) & 1) * 2) + ((((v368 + ((~(((v370 ^ -1) | (-(v370 ^ -1))) >> 31)) & 2)) - (v371 + ((~(((v372 ^ -1) | (-(v372 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
    v431[v527] = v429;
    int * v433 = v344->cache_tags;
    int v530 = ((((int)((unsigned int)((int)((unsigned int)v348 >> 2)) >> 1)) & 1) * 2) + ((((v368 + ((~(((v370 ^ -1) | (-(v370 ^ -1))) >> 31)) & 2)) - (v371 + ((~(((v372 ^ -1) | (-(v372 ^ -1))) >> 31)) & 2))) >> 31) & 1);
    int v531 = (int)((unsigned int)((int)((unsigned int)v348 >> 2)) >> 1);
    v433[v530] = v531;
    int * v435 = v344->cache_dirty;
    v435[v530] = 0;
    int * v437 = v344->cache_age;
    v437[v530] = 1;
    int * v439 = v344->cache_age;
    int v440 = v439[v530];
    int v441 = v439[v459];
    int v537 = v441 + ((int)((unsigned int)(v441 - v440) >> 31));
    v439[v459] = v537;
    int * v443 = v344->cache_age;
    int v444 = v443[v460];
    int v539 = v444 + ((int)((unsigned int)(v444 - v440) >> 31));
    v443[v460] = v539;
    int * v446 = v344->cache_age;
    v446[v530] = 0;
    v449 = v530;
  }
  int v542 = (v449 * 2) + (((int)((unsigned int)v348 >> 2)) & 1);
  int v450 = v356[v542];
  int * v451 = v344->regs;
  v451[10] = v450;
  struct StateT * v453 = slot_11(v344);
  return v453;
}

struct StateT * slot_1(struct StateT * v15) {
  int v16 = v15->timer;
  int v126 = v16 + 1;
  v15->timer = v126;
  int * v18 = v15->regs;
  int v19 = v18[11];
  int * v20 = v15->cache_tags;
  int v130 = (((int)((unsigned int)((int)((unsigned int)v19 >> 2)) >> 1)) & 1) * 2;
  int v21 = v20[v130];
  int v131 = ((((int)((unsigned int)((int)((unsigned int)v19 >> 2)) >> 1)) & 1) * 2) + 1;
  int v22 = v20[v131];
  int v132 = 4 + ((((int)((unsigned int)((int)((unsigned int)v19 >> 2)) >> 1)) & 3) * 2);
  int v23 = v20[v132];
  int v133 = (4 + ((((int)((unsigned int)((int)((unsigned int)v19 >> 2)) >> 1)) & 3) * 2)) + 1;
  int v24 = v20[v133];
  int v25 = v15->timer;
  int v134 = v25 + ((100 ^ (((~(((v23 ^ ((int)((unsigned int)((int)((unsigned int)v19 >> 2)) >> 1))) | (-(v23 ^ ((int)((unsigned int)((int)((unsigned int)v19 >> 2)) >> 1))))) >> 31)) | (~(((v24 ^ ((int)((unsigned int)((int)((unsigned int)v19 >> 2)) >> 1))) | (-(v24 ^ ((int)((unsigned int)((int)((unsigned int)v19 >> 2)) >> 1))))) >> 31))) & 104)) ^ (((~(((v21 ^ ((int)((unsigned int)((int)((unsigned int)v19 >> 2)) >> 1))) | (-(v21 ^ ((int)((unsigned int)((int)((unsigned int)v19 >> 2)) >> 1))))) >> 31)) | (~(((v22 ^ ((int)((unsigned int)((int)((unsigned int)v19 >> 2)) >> 1))) | (-(v22 ^ ((int)((unsigned int)((int)((unsigned int)v19 >> 2)) >> 1))))) >> 31))) & (1 ^ (100 ^ (((~(((v23 ^ ((int)((unsigned int)((int)((unsigned int)v19 >> 2)) >> 1))) | (-(v23 ^ ((int)((unsigned int)((int)((unsigned int)v19 >> 2)) >> 1))))) >> 31)) | (~(((v24 ^ ((int)((unsigned int)((int)((unsigned int)v19 >> 2)) >> 1))) | (-(v24 ^ ((int)((unsigned int)((int)((unsigned int)v19 >> 2)) >> 1))))) >> 31))) & 104)))));
  v15->timer = v134;
  int * v27 = v15->cache_vals;
  bool v135 = !(((~(((v21 ^ ((int)((unsigned int)((int)((unsigned int)v19 >> 2)) >> 1))) | (-(v21 ^ ((int)((unsigned int)((int)((unsigned int)v19 >> 2)) >> 1))))) >> 31)) | (~(((v22 ^ ((int)((unsigned int)((int)((unsigned int)v19 >> 2)) >> 1))) | (-(v22 ^ ((int)((unsigned int)((int)((unsigned int)v19 >> 2)) >> 1))))) >> 31))) == 0);
  int v120;
  if (v135) {
    int * v28 = v15->cache_age;
    int v137 = ((((int)((unsigned int)((int)((unsigned int)v19 >> 2)) >> 1)) & 1) * 2) + ((~(((v22 ^ ((int)((unsigned int)((int)((unsigned int)v19 >> 2)) >> 1))) | (-(v22 ^ ((int)((unsigned int)((int)((unsigned int)v19 >> 2)) >> 1))))) >> 31)) & 1);
    int v29 = v28[v137];
    int v30 = v28[v130];
    int v138 = v30 + ((int)((unsigned int)(v30 - v29) >> 31));
    v28[v130] = v138;
    int * v32 = v15->cache_age;
    int v33 = v32[v131];
    int v140 = v33 + ((int)((unsigned int)(v33 - v29) >> 31));
    v32[v131] = v140;
    int * v35 = v15->cache_age;
    v35[v137] = 0;
    v120 = v137;
  } else {
    int * v38 = v15->cache_age;
    int v144 = (((int)((unsigned int)((int)((unsigned int)v19 >> 2)) >> 1)) & 1) * 2;
    int v39 = v38[v144];
    int * v40 = v15->cache_tags;
    int v41 = v40[v144];
    int v42 = v38[v131];
    int v43 = v40[v131];
    bool v146 = !(((~(((v23 ^ ((int)((unsigned int)((int)((unsigned int)v19 >> 2)) >> 1))) | (-(v23 ^ ((int)((unsigned int)((int)((unsigned int)v19 >> 2)) >> 1))))) >> 31)) | (~(((v24 ^ ((int)((unsigned int)((int)((unsigned int)v19 >> 2)) >> 1))) | (-(v24 ^ ((int)((unsigned int)((int)((unsigned int)v19 >> 2)) >> 1))))) >> 31))) == 0);
    int v97;
    if (v146) {
      int * v44 = v15->cache_age;
      int v148 = (4 + ((((int)((unsigned int)((int)((unsigned int)v19 >> 2)) >> 1)) & 3) * 2)) + ((~(((v24 ^ ((int)((unsigned int)((int)((unsigned int)v19 >> 2)) >> 1))) | (-(v24 ^ ((int)((unsigned int)((int)((unsigned int)v19 >> 2)) >> 1))))) >> 31)) & 1);
      int v45 = v44[v148];
      int v46 = v44[v132];
      int v149 = v46 + ((int)((unsigned int)(v46 - v45) >> 31));
      v44[v132] = v149;
      int * v48 = v15->cache_age;
      int v49 = v48[v133];
      int v151 = v49 + ((int)((unsigned int)(v49 - v45) >> 31));
      v48[v133] = v151;
      int * v51 = v15->cache_age;
      v51[v148] = 0;
      v97 = v148;
    } else {
      int * v54 = v15->cache_age;
      int v155 = 4 + ((((int)((unsigned int)((int)((unsigned int)v19 >> 2)) >> 1)) & 3) * 2);
      int v55 = v54[v155];
      int * v56 = v15->cache_tags;
      int v57 = v56[v155];
      int v58 = v54[v133];
      int v59 = v56[v133];
      int * v60 = v15->cache_dirty;
      int v158 = (4 + ((((int)((unsigned int)((int)((unsigned int)v19 >> 2)) >> 1)) & 3) * 2)) + ((((v55 + ((~(((v57 ^ -1) | (-(v57 ^ -1))) >> 31)) & 2)) - (v58 + ((~(((v59 ^ -1) | (-(v59 ^ -1))) >> 31)) & 2))) >> 31) & 1);
      int v61 = v60[v158];
      bool v159 = !(v61 == 0);
      if (v159) {
        int * v62 = v15->cache_tags;
        int v63 = v62[v158];
        int * v64 = v15->cache_vals;
        int v162 = ((4 + ((((int)((unsigned int)((int)((unsigned int)v19 >> 2)) >> 1)) & 3) * 2)) + ((((v55 + ((~(((v57 ^ -1) | (-(v57 ^ -1))) >> 31)) & 2)) - (v58 + ((~(((v59 ^ -1) | (-(v59 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
        int v65 = v64[v162];
        int v163 = (((4 + ((((int)((unsigned int)((int)((unsigned int)v19 >> 2)) >> 1)) & 3) * 2)) + ((((v55 + ((~(((v57 ^ -1) | (-(v57 ^ -1))) >> 31)) & 2)) - (v58 + ((~(((v59 ^ -1) | (-(v59 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
        int v66 = v64[v163];
        int * v67 = v15->mem;
        int v165 = v63 * 2;
        v67[v165] = v65;
        int * v69 = v15->mem;
        int v168 = (v63 * 2) + 1;
        v69[v168] = v66;
        ;
      } else {
        ;
      }
      int * v74 = v15->mem;
      int v173 = ((int)((unsigned int)((int)((unsigned int)v19 >> 2)) >> 1)) * 2;
      int v75 = v74[v173];
      int v174 = (((int)((unsigned int)((int)((unsigned int)v19 >> 2)) >> 1)) * 2) + 1;
      int v76 = v74[v174];
      int * v77 = v15->cache_vals;
      int v176 = ((4 + ((((int)((unsigned int)((int)((unsigned int)v19 >> 2)) >> 1)) & 3) * 2)) + ((((v55 + ((~(((v57 ^ -1) | (-(v57 ^ -1))) >> 31)) & 2)) - (v58 + ((~(((v59 ^ -1) | (-(v59 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
      v77[v176] = v75;
      int * v79 = v15->cache_vals;
      int v179 = (((4 + ((((int)((unsigned int)((int)((unsigned int)v19 >> 2)) >> 1)) & 3) * 2)) + ((((v55 + ((~(((v57 ^ -1) | (-(v57 ^ -1))) >> 31)) & 2)) - (v58 + ((~(((v59 ^ -1) | (-(v59 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
      v79[v179] = v76;
      int * v81 = v15->cache_tags;
      int v182 = (int)((unsigned int)((int)((unsigned int)v19 >> 2)) >> 1);
      v81[v158] = v182;
      int * v83 = v15->cache_dirty;
      v83[v158] = 0;
      int * v85 = v15->cache_age;
      v85[v158] = 1;
      int * v87 = v15->cache_age;
      int v88 = v87[v158];
      int v89 = v87[v132];
      int v188 = v89 + ((int)((unsigned int)(v89 - v88) >> 31));
      v87[v132] = v188;
      int * v91 = v15->cache_age;
      int v92 = v91[v133];
      int v190 = v92 + ((int)((unsigned int)(v92 - v88) >> 31));
      v91[v133] = v190;
      int * v94 = v15->cache_age;
      v94[v158] = 0;
      v97 = v158;
    }
    int * v98 = v15->cache_vals;
    int v193 = v97 * 2;
    int v99 = v98[v193];
    int v194 = (v97 * 2) + 1;
    int v100 = v98[v194];
    int v195 = (((((int)((unsigned int)((int)((unsigned int)v19 >> 2)) >> 1)) & 1) * 2) + ((((v39 + ((~(((v41 ^ -1) | (-(v41 ^ -1))) >> 31)) & 2)) - (v42 + ((~(((v43 ^ -1) | (-(v43 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
    v98[v195] = v99;
    int * v102 = v15->cache_vals;
    int v198 = ((((((int)((unsigned int)((int)((unsigned int)v19 >> 2)) >> 1)) & 1) * 2) + ((((v39 + ((~(((v41 ^ -1) | (-(v41 ^ -1))) >> 31)) & 2)) - (v42 + ((~(((v43 ^ -1) | (-(v43 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
    v102[v198] = v100;
    int * v104 = v15->cache_tags;
    int v201 = ((((int)((unsigned int)((int)((unsigned int)v19 >> 2)) >> 1)) & 1) * 2) + ((((v39 + ((~(((v41 ^ -1) | (-(v41 ^ -1))) >> 31)) & 2)) - (v42 + ((~(((v43 ^ -1) | (-(v43 ^ -1))) >> 31)) & 2))) >> 31) & 1);
    int v202 = (int)((unsigned int)((int)((unsigned int)v19 >> 2)) >> 1);
    v104[v201] = v202;
    int * v106 = v15->cache_dirty;
    v106[v201] = 0;
    int * v108 = v15->cache_age;
    v108[v201] = 1;
    int * v110 = v15->cache_age;
    int v111 = v110[v201];
    int v112 = v110[v130];
    int v208 = v112 + ((int)((unsigned int)(v112 - v111) >> 31));
    v110[v130] = v208;
    int * v114 = v15->cache_age;
    int v115 = v114[v131];
    int v210 = v115 + ((int)((unsigned int)(v115 - v111) >> 31));
    v114[v131] = v210;
    int * v117 = v15->cache_age;
    v117[v201] = 0;
    v120 = v201;
  }
  int v213 = (v120 * 2) + (((int)((unsigned int)v19 >> 2)) & 1);
  int v121 = v27[v213];
  int * v122 = v15->regs;
  v122[11] = v121;
  struct StateT * v124 = slot_2(v15);
  return v124;
}

struct StateT * slot_19(struct StateT * v1038) {
  int v1039 = v1038->timer;
  int v1047 = v1039 + 1;
  v1038->timer = v1047;
  int * v1041 = v1038->regs;
  int v1042 = v1041[11];
  int v1043 = v1041[10];
  int v1051 = v1042 & v1043;
  v1041[10] = v1051;
  struct StateT * v1045 = slot_20(v1038);
  return v1045;
}

struct StateT * slot_13(struct StateT * v574) {
  int v575 = v574->timer;
  int v581 = v575 + 1;
  v574->timer = v581;
  int * v577 = v574->regs;
  v577[12] = 0;
  struct StateT * v579 = slot_14(v574);
  return v579;
}

struct StateT * slot_0(struct StateT * v2) {
  int v3 = v2->timer;
  int v9 = v3 + 1;
  v2->timer = v9;
  int * v5 = v2->regs;
  v5[11] = 0;
  struct StateT * v7 = slot_1(v2);
  return v7;
}

struct StateT * slot_14(struct StateT * v587) {
  int v588 = v587->timer;
  int v595 = v588 + 1;
  v587->timer = v595;
  int * v590 = v587->regs;
  int v591 = v590[10];
  int v598 = v591 << 29;
  v590[10] = v598;
  struct StateT * v593 = slot_15(v587);
  return v593;
}

struct StateT * slot_17(struct StateT * v631) {
  int v632 = v631->timer;
  int v742 = v632 + 1;
  v631->timer = v742;
  int * v634 = v631->regs;
  int v635 = v634[10];
  int * v636 = v631->cache_tags;
  int v746 = (((int)((unsigned int)((int)((unsigned int)v635 >> 2)) >> 1)) & 1) * 2;
  int v637 = v636[v746];
  int v747 = ((((int)((unsigned int)((int)((unsigned int)v635 >> 2)) >> 1)) & 1) * 2) + 1;
  int v638 = v636[v747];
  int v748 = 4 + ((((int)((unsigned int)((int)((unsigned int)v635 >> 2)) >> 1)) & 3) * 2);
  int v639 = v636[v748];
  int v749 = (4 + ((((int)((unsigned int)((int)((unsigned int)v635 >> 2)) >> 1)) & 3) * 2)) + 1;
  int v640 = v636[v749];
  int v641 = v631->timer;
  int v750 = v641 + ((100 ^ (((~(((v639 ^ ((int)((unsigned int)((int)((unsigned int)v635 >> 2)) >> 1))) | (-(v639 ^ ((int)((unsigned int)((int)((unsigned int)v635 >> 2)) >> 1))))) >> 31)) | (~(((v640 ^ ((int)((unsigned int)((int)((unsigned int)v635 >> 2)) >> 1))) | (-(v640 ^ ((int)((unsigned int)((int)((unsigned int)v635 >> 2)) >> 1))))) >> 31))) & 104)) ^ (((~(((v637 ^ ((int)((unsigned int)((int)((unsigned int)v635 >> 2)) >> 1))) | (-(v637 ^ ((int)((unsigned int)((int)((unsigned int)v635 >> 2)) >> 1))))) >> 31)) | (~(((v638 ^ ((int)((unsigned int)((int)((unsigned int)v635 >> 2)) >> 1))) | (-(v638 ^ ((int)((unsigned int)((int)((unsigned int)v635 >> 2)) >> 1))))) >> 31))) & (1 ^ (100 ^ (((~(((v639 ^ ((int)((unsigned int)((int)((unsigned int)v635 >> 2)) >> 1))) | (-(v639 ^ ((int)((unsigned int)((int)((unsigned int)v635 >> 2)) >> 1))))) >> 31)) | (~(((v640 ^ ((int)((unsigned int)((int)((unsigned int)v635 >> 2)) >> 1))) | (-(v640 ^ ((int)((unsigned int)((int)((unsigned int)v635 >> 2)) >> 1))))) >> 31))) & 104)))));
  v631->timer = v750;
  int * v643 = v631->cache_vals;
  bool v751 = !(((~(((v637 ^ ((int)((unsigned int)((int)((unsigned int)v635 >> 2)) >> 1))) | (-(v637 ^ ((int)((unsigned int)((int)((unsigned int)v635 >> 2)) >> 1))))) >> 31)) | (~(((v638 ^ ((int)((unsigned int)((int)((unsigned int)v635 >> 2)) >> 1))) | (-(v638 ^ ((int)((unsigned int)((int)((unsigned int)v635 >> 2)) >> 1))))) >> 31))) == 0);
  int v736;
  if (v751) {
    int * v644 = v631->cache_age;
    int v753 = ((((int)((unsigned int)((int)((unsigned int)v635 >> 2)) >> 1)) & 1) * 2) + ((~(((v638 ^ ((int)((unsigned int)((int)((unsigned int)v635 >> 2)) >> 1))) | (-(v638 ^ ((int)((unsigned int)((int)((unsigned int)v635 >> 2)) >> 1))))) >> 31)) & 1);
    int v645 = v644[v753];
    int v646 = v644[v746];
    int v754 = v646 + ((int)((unsigned int)(v646 - v645) >> 31));
    v644[v746] = v754;
    int * v648 = v631->cache_age;
    int v649 = v648[v747];
    int v756 = v649 + ((int)((unsigned int)(v649 - v645) >> 31));
    v648[v747] = v756;
    int * v651 = v631->cache_age;
    v651[v753] = 0;
    v736 = v753;
  } else {
    int * v654 = v631->cache_age;
    int v760 = (((int)((unsigned int)((int)((unsigned int)v635 >> 2)) >> 1)) & 1) * 2;
    int v655 = v654[v760];
    int * v656 = v631->cache_tags;
    int v657 = v656[v760];
    int v658 = v654[v747];
    int v659 = v656[v747];
    bool v762 = !(((~(((v639 ^ ((int)((unsigned int)((int)((unsigned int)v635 >> 2)) >> 1))) | (-(v639 ^ ((int)((unsigned int)((int)((unsigned int)v635 >> 2)) >> 1))))) >> 31)) | (~(((v640 ^ ((int)((unsigned int)((int)((unsigned int)v635 >> 2)) >> 1))) | (-(v640 ^ ((int)((unsigned int)((int)((unsigned int)v635 >> 2)) >> 1))))) >> 31))) == 0);
    int v713;
    if (v762) {
      int * v660 = v631->cache_age;
      int v764 = (4 + ((((int)((unsigned int)((int)((unsigned int)v635 >> 2)) >> 1)) & 3) * 2)) + ((~(((v640 ^ ((int)((unsigned int)((int)((unsigned int)v635 >> 2)) >> 1))) | (-(v640 ^ ((int)((unsigned int)((int)((unsigned int)v635 >> 2)) >> 1))))) >> 31)) & 1);
      int v661 = v660[v764];
      int v662 = v660[v748];
      int v765 = v662 + ((int)((unsigned int)(v662 - v661) >> 31));
      v660[v748] = v765;
      int * v664 = v631->cache_age;
      int v665 = v664[v749];
      int v767 = v665 + ((int)((unsigned int)(v665 - v661) >> 31));
      v664[v749] = v767;
      int * v667 = v631->cache_age;
      v667[v764] = 0;
      v713 = v764;
    } else {
      int * v670 = v631->cache_age;
      int v771 = 4 + ((((int)((unsigned int)((int)((unsigned int)v635 >> 2)) >> 1)) & 3) * 2);
      int v671 = v670[v771];
      int * v672 = v631->cache_tags;
      int v673 = v672[v771];
      int v674 = v670[v749];
      int v675 = v672[v749];
      int * v676 = v631->cache_dirty;
      int v774 = (4 + ((((int)((unsigned int)((int)((unsigned int)v635 >> 2)) >> 1)) & 3) * 2)) + ((((v671 + ((~(((v673 ^ -1) | (-(v673 ^ -1))) >> 31)) & 2)) - (v674 + ((~(((v675 ^ -1) | (-(v675 ^ -1))) >> 31)) & 2))) >> 31) & 1);
      int v677 = v676[v774];
      bool v775 = !(v677 == 0);
      if (v775) {
        int * v678 = v631->cache_tags;
        int v679 = v678[v774];
        int * v680 = v631->cache_vals;
        int v778 = ((4 + ((((int)((unsigned int)((int)((unsigned int)v635 >> 2)) >> 1)) & 3) * 2)) + ((((v671 + ((~(((v673 ^ -1) | (-(v673 ^ -1))) >> 31)) & 2)) - (v674 + ((~(((v675 ^ -1) | (-(v675 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
        int v681 = v680[v778];
        int v779 = (((4 + ((((int)((unsigned int)((int)((unsigned int)v635 >> 2)) >> 1)) & 3) * 2)) + ((((v671 + ((~(((v673 ^ -1) | (-(v673 ^ -1))) >> 31)) & 2)) - (v674 + ((~(((v675 ^ -1) | (-(v675 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
        int v682 = v680[v779];
        int * v683 = v631->mem;
        int v781 = v679 * 2;
        v683[v781] = v681;
        int * v685 = v631->mem;
        int v784 = (v679 * 2) + 1;
        v685[v784] = v682;
        ;
      } else {
        ;
      }
      int * v690 = v631->mem;
      int v789 = ((int)((unsigned int)((int)((unsigned int)v635 >> 2)) >> 1)) * 2;
      int v691 = v690[v789];
      int v790 = (((int)((unsigned int)((int)((unsigned int)v635 >> 2)) >> 1)) * 2) + 1;
      int v692 = v690[v790];
      int * v693 = v631->cache_vals;
      int v792 = ((4 + ((((int)((unsigned int)((int)((unsigned int)v635 >> 2)) >> 1)) & 3) * 2)) + ((((v671 + ((~(((v673 ^ -1) | (-(v673 ^ -1))) >> 31)) & 2)) - (v674 + ((~(((v675 ^ -1) | (-(v675 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
      v693[v792] = v691;
      int * v695 = v631->cache_vals;
      int v795 = (((4 + ((((int)((unsigned int)((int)((unsigned int)v635 >> 2)) >> 1)) & 3) * 2)) + ((((v671 + ((~(((v673 ^ -1) | (-(v673 ^ -1))) >> 31)) & 2)) - (v674 + ((~(((v675 ^ -1) | (-(v675 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
      v695[v795] = v692;
      int * v697 = v631->cache_tags;
      int v798 = (int)((unsigned int)((int)((unsigned int)v635 >> 2)) >> 1);
      v697[v774] = v798;
      int * v699 = v631->cache_dirty;
      v699[v774] = 0;
      int * v701 = v631->cache_age;
      v701[v774] = 1;
      int * v703 = v631->cache_age;
      int v704 = v703[v774];
      int v705 = v703[v748];
      int v804 = v705 + ((int)((unsigned int)(v705 - v704) >> 31));
      v703[v748] = v804;
      int * v707 = v631->cache_age;
      int v708 = v707[v749];
      int v806 = v708 + ((int)((unsigned int)(v708 - v704) >> 31));
      v707[v749] = v806;
      int * v710 = v631->cache_age;
      v710[v774] = 0;
      v713 = v774;
    }
    int * v714 = v631->cache_vals;
    int v809 = v713 * 2;
    int v715 = v714[v809];
    int v810 = (v713 * 2) + 1;
    int v716 = v714[v810];
    int v811 = (((((int)((unsigned int)((int)((unsigned int)v635 >> 2)) >> 1)) & 1) * 2) + ((((v655 + ((~(((v657 ^ -1) | (-(v657 ^ -1))) >> 31)) & 2)) - (v658 + ((~(((v659 ^ -1) | (-(v659 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
    v714[v811] = v715;
    int * v718 = v631->cache_vals;
    int v814 = ((((((int)((unsigned int)((int)((unsigned int)v635 >> 2)) >> 1)) & 1) * 2) + ((((v655 + ((~(((v657 ^ -1) | (-(v657 ^ -1))) >> 31)) & 2)) - (v658 + ((~(((v659 ^ -1) | (-(v659 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
    v718[v814] = v716;
    int * v720 = v631->cache_tags;
    int v817 = ((((int)((unsigned int)((int)((unsigned int)v635 >> 2)) >> 1)) & 1) * 2) + ((((v655 + ((~(((v657 ^ -1) | (-(v657 ^ -1))) >> 31)) & 2)) - (v658 + ((~(((v659 ^ -1) | (-(v659 ^ -1))) >> 31)) & 2))) >> 31) & 1);
    int v818 = (int)((unsigned int)((int)((unsigned int)v635 >> 2)) >> 1);
    v720[v817] = v818;
    int * v722 = v631->cache_dirty;
    v722[v817] = 0;
    int * v724 = v631->cache_age;
    v724[v817] = 1;
    int * v726 = v631->cache_age;
    int v727 = v726[v817];
    int v728 = v726[v746];
    int v824 = v728 + ((int)((unsigned int)(v728 - v727) >> 31));
    v726[v746] = v824;
    int * v730 = v631->cache_age;
    int v731 = v730[v747];
    int v826 = v731 + ((int)((unsigned int)(v731 - v727) >> 31));
    v730[v747] = v826;
    int * v733 = v631->cache_age;
    v733[v817] = 0;
    v736 = v817;
  }
  int v829 = (v736 * 2) + (((int)((unsigned int)v635 >> 2)) & 1);
  int v737 = v643[v829];
  int * v738 = v631->regs;
  v738[10] = v737;
  struct StateT * v740 = slot_18(v631);
  return v740;
}

struct StateT * slot_20(struct StateT * v1054) {
  int v1055 = v1054->timer;
  int v1225 = v1055 + 1;
  v1054->timer = v1225;
  int * v1057 = v1054->regs;
  int v1058 = v1057[12];
  int v1059 = v1057[10];
  int * v1060 = v1054->cache_tags;
  int v1230 = (((int)((unsigned int)((int)((unsigned int)(v1058 + 68) >> 2)) >> 1)) & 1) * 2;
  int v1061 = v1060[v1230];
  int v1231 = ((((int)((unsigned int)((int)((unsigned int)(v1058 + 68) >> 2)) >> 1)) & 1) * 2) + 1;
  int v1062 = v1060[v1231];
  int v1232 = 4 + ((((int)((unsigned int)((int)((unsigned int)(v1058 + 68) >> 2)) >> 1)) & 3) * 2);
  int v1063 = v1060[v1232];
  int v1233 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v1058 + 68) >> 2)) >> 1)) & 3) * 2)) + 1;
  int v1064 = v1060[v1233];
  int v1065 = v1054->timer;
  int v1234 = v1065 + ((100 ^ (((~(((v1063 ^ ((int)((unsigned int)((int)((unsigned int)(v1058 + 68) >> 2)) >> 1))) | (-(v1063 ^ ((int)((unsigned int)((int)((unsigned int)(v1058 + 68) >> 2)) >> 1))))) >> 31)) | (~(((v1064 ^ ((int)((unsigned int)((int)((unsigned int)(v1058 + 68) >> 2)) >> 1))) | (-(v1064 ^ ((int)((unsigned int)((int)((unsigned int)(v1058 + 68) >> 2)) >> 1))))) >> 31))) & 104)) ^ (((~(((v1061 ^ ((int)((unsigned int)((int)((unsigned int)(v1058 + 68) >> 2)) >> 1))) | (-(v1061 ^ ((int)((unsigned int)((int)((unsigned int)(v1058 + 68) >> 2)) >> 1))))) >> 31)) | (~(((v1062 ^ ((int)((unsigned int)((int)((unsigned int)(v1058 + 68) >> 2)) >> 1))) | (-(v1062 ^ ((int)((unsigned int)((int)((unsigned int)(v1058 + 68) >> 2)) >> 1))))) >> 31))) & (1 ^ (100 ^ (((~(((v1063 ^ ((int)((unsigned int)((int)((unsigned int)(v1058 + 68) >> 2)) >> 1))) | (-(v1063 ^ ((int)((unsigned int)((int)((unsigned int)(v1058 + 68) >> 2)) >> 1))))) >> 31)) | (~(((v1064 ^ ((int)((unsigned int)((int)((unsigned int)(v1058 + 68) >> 2)) >> 1))) | (-(v1064 ^ ((int)((unsigned int)((int)((unsigned int)(v1058 + 68) >> 2)) >> 1))))) >> 31))) & 104)))));
  v1054->timer = v1234;
  bool v1235 = !(((~(((v1061 ^ ((int)((unsigned int)((int)((unsigned int)(v1058 + 68) >> 2)) >> 1))) | (-(v1061 ^ ((int)((unsigned int)((int)((unsigned int)(v1058 + 68) >> 2)) >> 1))))) >> 31)) | (~(((v1062 ^ ((int)((unsigned int)((int)((unsigned int)(v1058 + 68) >> 2)) >> 1))) | (-(v1062 ^ ((int)((unsigned int)((int)((unsigned int)(v1058 + 68) >> 2)) >> 1))))) >> 31))) == 0);
  int v1159;
  if (v1235) {
    int * v1067 = v1054->cache_age;
    int v1237 = ((((int)((unsigned int)((int)((unsigned int)(v1058 + 68) >> 2)) >> 1)) & 1) * 2) + ((~(((v1062 ^ ((int)((unsigned int)((int)((unsigned int)(v1058 + 68) >> 2)) >> 1))) | (-(v1062 ^ ((int)((unsigned int)((int)((unsigned int)(v1058 + 68) >> 2)) >> 1))))) >> 31)) & 1);
    int v1068 = v1067[v1237];
    int v1069 = v1067[v1230];
    int v1238 = v1069 + ((int)((unsigned int)(v1069 - v1068) >> 31));
    v1067[v1230] = v1238;
    int * v1071 = v1054->cache_age;
    int v1072 = v1071[v1231];
    int v1240 = v1072 + ((int)((unsigned int)(v1072 - v1068) >> 31));
    v1071[v1231] = v1240;
    int * v1074 = v1054->cache_age;
    v1074[v1237] = 0;
    v1159 = v1237;
  } else {
    int * v1077 = v1054->cache_age;
    int v1244 = (((int)((unsigned int)((int)((unsigned int)(v1058 + 68) >> 2)) >> 1)) & 1) * 2;
    int v1078 = v1077[v1244];
    int * v1079 = v1054->cache_tags;
    int v1080 = v1079[v1244];
    int v1081 = v1077[v1231];
    int v1082 = v1079[v1231];
    bool v1246 = !(((~(((v1063 ^ ((int)((unsigned int)((int)((unsigned int)(v1058 + 68) >> 2)) >> 1))) | (-(v1063 ^ ((int)((unsigned int)((int)((unsigned int)(v1058 + 68) >> 2)) >> 1))))) >> 31)) | (~(((v1064 ^ ((int)((unsigned int)((int)((unsigned int)(v1058 + 68) >> 2)) >> 1))) | (-(v1064 ^ ((int)((unsigned int)((int)((unsigned int)(v1058 + 68) >> 2)) >> 1))))) >> 31))) == 0);
    int v1136;
    if (v1246) {
      int * v1083 = v1054->cache_age;
      int v1248 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v1058 + 68) >> 2)) >> 1)) & 3) * 2)) + ((~(((v1064 ^ ((int)((unsigned int)((int)((unsigned int)(v1058 + 68) >> 2)) >> 1))) | (-(v1064 ^ ((int)((unsigned int)((int)((unsigned int)(v1058 + 68) >> 2)) >> 1))))) >> 31)) & 1);
      int v1084 = v1083[v1248];
      int v1085 = v1083[v1232];
      int v1249 = v1085 + ((int)((unsigned int)(v1085 - v1084) >> 31));
      v1083[v1232] = v1249;
      int * v1087 = v1054->cache_age;
      int v1088 = v1087[v1233];
      int v1251 = v1088 + ((int)((unsigned int)(v1088 - v1084) >> 31));
      v1087[v1233] = v1251;
      int * v1090 = v1054->cache_age;
      v1090[v1248] = 0;
      v1136 = v1248;
    } else {
      int * v1093 = v1054->cache_age;
      int v1255 = 4 + ((((int)((unsigned int)((int)((unsigned int)(v1058 + 68) >> 2)) >> 1)) & 3) * 2);
      int v1094 = v1093[v1255];
      int * v1095 = v1054->cache_tags;
      int v1096 = v1095[v1255];
      int v1097 = v1093[v1233];
      int v1098 = v1095[v1233];
      int * v1099 = v1054->cache_dirty;
      int v1258 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v1058 + 68) >> 2)) >> 1)) & 3) * 2)) + ((((v1094 + ((~(((v1096 ^ -1) | (-(v1096 ^ -1))) >> 31)) & 2)) - (v1097 + ((~(((v1098 ^ -1) | (-(v1098 ^ -1))) >> 31)) & 2))) >> 31) & 1);
      int v1100 = v1099[v1258];
      bool v1259 = !(v1100 == 0);
      if (v1259) {
        int * v1101 = v1054->cache_tags;
        int v1102 = v1101[v1258];
        int * v1103 = v1054->cache_vals;
        int v1262 = ((4 + ((((int)((unsigned int)((int)((unsigned int)(v1058 + 68) >> 2)) >> 1)) & 3) * 2)) + ((((v1094 + ((~(((v1096 ^ -1) | (-(v1096 ^ -1))) >> 31)) & 2)) - (v1097 + ((~(((v1098 ^ -1) | (-(v1098 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
        int v1104 = v1103[v1262];
        int v1263 = (((4 + ((((int)((unsigned int)((int)((unsigned int)(v1058 + 68) >> 2)) >> 1)) & 3) * 2)) + ((((v1094 + ((~(((v1096 ^ -1) | (-(v1096 ^ -1))) >> 31)) & 2)) - (v1097 + ((~(((v1098 ^ -1) | (-(v1098 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
        int v1105 = v1103[v1263];
        int * v1106 = v1054->mem;
        int v1265 = v1102 * 2;
        v1106[v1265] = v1104;
        int * v1108 = v1054->mem;
        int v1268 = (v1102 * 2) + 1;
        v1108[v1268] = v1105;
        ;
      } else {
        ;
      }
      int * v1113 = v1054->mem;
      int v1273 = ((int)((unsigned int)((int)((unsigned int)(v1058 + 68) >> 2)) >> 1)) * 2;
      int v1114 = v1113[v1273];
      int v1274 = (((int)((unsigned int)((int)((unsigned int)(v1058 + 68) >> 2)) >> 1)) * 2) + 1;
      int v1115 = v1113[v1274];
      int * v1116 = v1054->cache_vals;
      int v1276 = ((4 + ((((int)((unsigned int)((int)((unsigned int)(v1058 + 68) >> 2)) >> 1)) & 3) * 2)) + ((((v1094 + ((~(((v1096 ^ -1) | (-(v1096 ^ -1))) >> 31)) & 2)) - (v1097 + ((~(((v1098 ^ -1) | (-(v1098 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
      v1116[v1276] = v1114;
      int * v1118 = v1054->cache_vals;
      int v1279 = (((4 + ((((int)((unsigned int)((int)((unsigned int)(v1058 + 68) >> 2)) >> 1)) & 3) * 2)) + ((((v1094 + ((~(((v1096 ^ -1) | (-(v1096 ^ -1))) >> 31)) & 2)) - (v1097 + ((~(((v1098 ^ -1) | (-(v1098 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
      v1118[v1279] = v1115;
      int * v1120 = v1054->cache_tags;
      int v1282 = (int)((unsigned int)((int)((unsigned int)(v1058 + 68) >> 2)) >> 1);
      v1120[v1258] = v1282;
      int * v1122 = v1054->cache_dirty;
      v1122[v1258] = 0;
      int * v1124 = v1054->cache_age;
      v1124[v1258] = 1;
      int * v1126 = v1054->cache_age;
      int v1127 = v1126[v1258];
      int v1128 = v1126[v1232];
      int v1288 = v1128 + ((int)((unsigned int)(v1128 - v1127) >> 31));
      v1126[v1232] = v1288;
      int * v1130 = v1054->cache_age;
      int v1131 = v1130[v1233];
      int v1290 = v1131 + ((int)((unsigned int)(v1131 - v1127) >> 31));
      v1130[v1233] = v1290;
      int * v1133 = v1054->cache_age;
      v1133[v1258] = 0;
      v1136 = v1258;
    }
    int * v1137 = v1054->cache_vals;
    int v1293 = v1136 * 2;
    int v1138 = v1137[v1293];
    int v1294 = (v1136 * 2) + 1;
    int v1139 = v1137[v1294];
    int v1295 = (((((int)((unsigned int)((int)((unsigned int)(v1058 + 68) >> 2)) >> 1)) & 1) * 2) + ((((v1078 + ((~(((v1080 ^ -1) | (-(v1080 ^ -1))) >> 31)) & 2)) - (v1081 + ((~(((v1082 ^ -1) | (-(v1082 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
    v1137[v1295] = v1138;
    int * v1141 = v1054->cache_vals;
    int v1298 = ((((((int)((unsigned int)((int)((unsigned int)(v1058 + 68) >> 2)) >> 1)) & 1) * 2) + ((((v1078 + ((~(((v1080 ^ -1) | (-(v1080 ^ -1))) >> 31)) & 2)) - (v1081 + ((~(((v1082 ^ -1) | (-(v1082 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
    v1141[v1298] = v1139;
    int * v1143 = v1054->cache_tags;
    int v1301 = ((((int)((unsigned int)((int)((unsigned int)(v1058 + 68) >> 2)) >> 1)) & 1) * 2) + ((((v1078 + ((~(((v1080 ^ -1) | (-(v1080 ^ -1))) >> 31)) & 2)) - (v1081 + ((~(((v1082 ^ -1) | (-(v1082 ^ -1))) >> 31)) & 2))) >> 31) & 1);
    int v1302 = (int)((unsigned int)((int)((unsigned int)(v1058 + 68) >> 2)) >> 1);
    v1143[v1301] = v1302;
    int * v1145 = v1054->cache_dirty;
    v1145[v1301] = 0;
    int * v1147 = v1054->cache_age;
    v1147[v1301] = 1;
    int * v1149 = v1054->cache_age;
    int v1150 = v1149[v1301];
    int v1151 = v1149[v1230];
    int v1308 = v1151 + ((int)((unsigned int)(v1151 - v1150) >> 31));
    v1149[v1230] = v1308;
    int * v1153 = v1054->cache_age;
    int v1154 = v1153[v1231];
    int v1310 = v1154 + ((int)((unsigned int)(v1154 - v1150) >> 31));
    v1153[v1231] = v1310;
    int * v1156 = v1054->cache_age;
    v1156[v1301] = 0;
    v1159 = v1301;
  }
  int * v1160 = v1054->cache_vals;
  int v1313 = (v1159 * 2) + (((int)((unsigned int)(v1058 + 68) >> 2)) & 1);
  v1160[v1313] = v1059;
  int * v1162 = v1054->cache_tags;
  int v1163 = v1162[v1232];
  int v1164 = v1162[v1233];
  bool v1316 = !(((~(((v1163 ^ ((int)((unsigned int)((int)((unsigned int)(v1058 + 68) >> 2)) >> 1))) | (-(v1163 ^ ((int)((unsigned int)((int)((unsigned int)(v1058 + 68) >> 2)) >> 1))))) >> 31)) | (~(((v1164 ^ ((int)((unsigned int)((int)((unsigned int)(v1058 + 68) >> 2)) >> 1))) | (-(v1164 ^ ((int)((unsigned int)((int)((unsigned int)(v1058 + 68) >> 2)) >> 1))))) >> 31))) == 0);
  int v1218;
  if (v1316) {
    int * v1165 = v1054->cache_age;
    int v1318 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v1058 + 68) >> 2)) >> 1)) & 3) * 2)) + ((~(((v1164 ^ ((int)((unsigned int)((int)((unsigned int)(v1058 + 68) >> 2)) >> 1))) | (-(v1164 ^ ((int)((unsigned int)((int)((unsigned int)(v1058 + 68) >> 2)) >> 1))))) >> 31)) & 1);
    int v1166 = v1165[v1318];
    int v1167 = v1165[v1232];
    int v1319 = v1167 + ((int)((unsigned int)(v1167 - v1166) >> 31));
    v1165[v1232] = v1319;
    int * v1169 = v1054->cache_age;
    int v1170 = v1169[v1233];
    int v1321 = v1170 + ((int)((unsigned int)(v1170 - v1166) >> 31));
    v1169[v1233] = v1321;
    int * v1172 = v1054->cache_age;
    v1172[v1318] = 0;
    v1218 = v1318;
  } else {
    int * v1175 = v1054->cache_age;
    int v1325 = 4 + ((((int)((unsigned int)((int)((unsigned int)(v1058 + 68) >> 2)) >> 1)) & 3) * 2);
    int v1176 = v1175[v1325];
    int * v1177 = v1054->cache_tags;
    int v1178 = v1177[v1325];
    int v1179 = v1175[v1233];
    int v1180 = v1177[v1233];
    int * v1181 = v1054->cache_dirty;
    int v1328 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v1058 + 68) >> 2)) >> 1)) & 3) * 2)) + ((((v1176 + ((~(((v1178 ^ -1) | (-(v1178 ^ -1))) >> 31)) & 2)) - (v1179 + ((~(((v1180 ^ -1) | (-(v1180 ^ -1))) >> 31)) & 2))) >> 31) & 1);
    int v1182 = v1181[v1328];
    bool v1329 = !(v1182 == 0);
    if (v1329) {
      int * v1183 = v1054->cache_tags;
      int v1184 = v1183[v1328];
      int * v1185 = v1054->cache_vals;
      int v1332 = ((4 + ((((int)((unsigned int)((int)((unsigned int)(v1058 + 68) >> 2)) >> 1)) & 3) * 2)) + ((((v1176 + ((~(((v1178 ^ -1) | (-(v1178 ^ -1))) >> 31)) & 2)) - (v1179 + ((~(((v1180 ^ -1) | (-(v1180 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
      int v1186 = v1185[v1332];
      int v1333 = (((4 + ((((int)((unsigned int)((int)((unsigned int)(v1058 + 68) >> 2)) >> 1)) & 3) * 2)) + ((((v1176 + ((~(((v1178 ^ -1) | (-(v1178 ^ -1))) >> 31)) & 2)) - (v1179 + ((~(((v1180 ^ -1) | (-(v1180 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
      int v1187 = v1185[v1333];
      int * v1188 = v1054->mem;
      int v1335 = v1184 * 2;
      v1188[v1335] = v1186;
      int * v1190 = v1054->mem;
      int v1338 = (v1184 * 2) + 1;
      v1190[v1338] = v1187;
      ;
    } else {
      ;
    }
    int * v1195 = v1054->mem;
    int v1343 = ((int)((unsigned int)((int)((unsigned int)(v1058 + 68) >> 2)) >> 1)) * 2;
    int v1196 = v1195[v1343];
    int v1344 = (((int)((unsigned int)((int)((unsigned int)(v1058 + 68) >> 2)) >> 1)) * 2) + 1;
    int v1197 = v1195[v1344];
    int * v1198 = v1054->cache_vals;
    int v1346 = ((4 + ((((int)((unsigned int)((int)((unsigned int)(v1058 + 68) >> 2)) >> 1)) & 3) * 2)) + ((((v1176 + ((~(((v1178 ^ -1) | (-(v1178 ^ -1))) >> 31)) & 2)) - (v1179 + ((~(((v1180 ^ -1) | (-(v1180 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
    v1198[v1346] = v1196;
    int * v1200 = v1054->cache_vals;
    int v1349 = (((4 + ((((int)((unsigned int)((int)((unsigned int)(v1058 + 68) >> 2)) >> 1)) & 3) * 2)) + ((((v1176 + ((~(((v1178 ^ -1) | (-(v1178 ^ -1))) >> 31)) & 2)) - (v1179 + ((~(((v1180 ^ -1) | (-(v1180 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
    v1200[v1349] = v1197;
    int * v1202 = v1054->cache_tags;
    int v1352 = (int)((unsigned int)((int)((unsigned int)(v1058 + 68) >> 2)) >> 1);
    v1202[v1328] = v1352;
    int * v1204 = v1054->cache_dirty;
    v1204[v1328] = 0;
    int * v1206 = v1054->cache_age;
    v1206[v1328] = 1;
    int * v1208 = v1054->cache_age;
    int v1209 = v1208[v1328];
    int v1210 = v1208[v1232];
    int v1358 = v1210 + ((int)((unsigned int)(v1210 - v1209) >> 31));
    v1208[v1232] = v1358;
    int * v1212 = v1054->cache_age;
    int v1213 = v1212[v1233];
    int v1360 = v1213 + ((int)((unsigned int)(v1213 - v1209) >> 31));
    v1212[v1233] = v1360;
    int * v1215 = v1054->cache_age;
    v1215[v1328] = 0;
    v1218 = v1328;
  }
  int * v1219 = v1054->cache_vals;
  int v1363 = (v1218 * 2) + (((int)((unsigned int)(v1058 + 68) >> 2)) & 1);
  v1219[v1363] = v1059;
  int * v1221 = v1054->cache_dirty;
  v1221[v1218] = 1;
  struct StateT * v1223 = slot_21(v1054);
  return v1223;
}

struct StateT * snippet(struct StateT * v0) {
  struct StateT * v1 = slot_0(v0);
  return v1;
}

struct StateT * slot_8(struct StateT * v314) {
  int v315 = v314->timer;
  int v322 = v315 + 1;
  v314->timer = v322;
  int * v317 = v314->regs;
  int v318 = v317[10];
  int v325 = v318 << 2;
  v317[10] = v325;
  struct StateT * v320 = slot_9(v314);
  return v320;
}

struct StateT * slot_4(struct StateT * v257) {
  int v258 = v257->timer;
  int v264 = v258 + 1;
  v257->timer = v264;
  int * v260 = v257->regs;
  v260[11] = 0;
  struct StateT * v262 = slot_5(v257);
  return v262;
}

struct StateT * slot_15(struct StateT * v601) {
  int v602 = v601->timer;
  int v609 = v602 + 1;
  v601->timer = v609;
  int * v604 = v601->regs;
  int v605 = v604[10];
  int v612 = (int)((unsigned int)v605 >> 26);
  v604[10] = v612;
  struct StateT * v607 = slot_16(v601);
  return v607;
}

struct StateT * slot_18(struct StateT * v834) {
  int v835 = v834->timer;
  int v945 = v835 + 1;
  v834->timer = v945;
  int * v837 = v834->regs;
  int v838 = v837[12];
  int * v839 = v834->cache_tags;
  int v949 = (((int)((unsigned int)((int)((unsigned int)(v838 + 68) >> 2)) >> 1)) & 1) * 2;
  int v840 = v839[v949];
  int v950 = ((((int)((unsigned int)((int)((unsigned int)(v838 + 68) >> 2)) >> 1)) & 1) * 2) + 1;
  int v841 = v839[v950];
  int v951 = 4 + ((((int)((unsigned int)((int)((unsigned int)(v838 + 68) >> 2)) >> 1)) & 3) * 2);
  int v842 = v839[v951];
  int v952 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v838 + 68) >> 2)) >> 1)) & 3) * 2)) + 1;
  int v843 = v839[v952];
  int v844 = v834->timer;
  int v953 = v844 + ((100 ^ (((~(((v842 ^ ((int)((unsigned int)((int)((unsigned int)(v838 + 68) >> 2)) >> 1))) | (-(v842 ^ ((int)((unsigned int)((int)((unsigned int)(v838 + 68) >> 2)) >> 1))))) >> 31)) | (~(((v843 ^ ((int)((unsigned int)((int)((unsigned int)(v838 + 68) >> 2)) >> 1))) | (-(v843 ^ ((int)((unsigned int)((int)((unsigned int)(v838 + 68) >> 2)) >> 1))))) >> 31))) & 104)) ^ (((~(((v840 ^ ((int)((unsigned int)((int)((unsigned int)(v838 + 68) >> 2)) >> 1))) | (-(v840 ^ ((int)((unsigned int)((int)((unsigned int)(v838 + 68) >> 2)) >> 1))))) >> 31)) | (~(((v841 ^ ((int)((unsigned int)((int)((unsigned int)(v838 + 68) >> 2)) >> 1))) | (-(v841 ^ ((int)((unsigned int)((int)((unsigned int)(v838 + 68) >> 2)) >> 1))))) >> 31))) & (1 ^ (100 ^ (((~(((v842 ^ ((int)((unsigned int)((int)((unsigned int)(v838 + 68) >> 2)) >> 1))) | (-(v842 ^ ((int)((unsigned int)((int)((unsigned int)(v838 + 68) >> 2)) >> 1))))) >> 31)) | (~(((v843 ^ ((int)((unsigned int)((int)((unsigned int)(v838 + 68) >> 2)) >> 1))) | (-(v843 ^ ((int)((unsigned int)((int)((unsigned int)(v838 + 68) >> 2)) >> 1))))) >> 31))) & 104)))));
  v834->timer = v953;
  int * v846 = v834->cache_vals;
  bool v954 = !(((~(((v840 ^ ((int)((unsigned int)((int)((unsigned int)(v838 + 68) >> 2)) >> 1))) | (-(v840 ^ ((int)((unsigned int)((int)((unsigned int)(v838 + 68) >> 2)) >> 1))))) >> 31)) | (~(((v841 ^ ((int)((unsigned int)((int)((unsigned int)(v838 + 68) >> 2)) >> 1))) | (-(v841 ^ ((int)((unsigned int)((int)((unsigned int)(v838 + 68) >> 2)) >> 1))))) >> 31))) == 0);
  int v939;
  if (v954) {
    int * v847 = v834->cache_age;
    int v956 = ((((int)((unsigned int)((int)((unsigned int)(v838 + 68) >> 2)) >> 1)) & 1) * 2) + ((~(((v841 ^ ((int)((unsigned int)((int)((unsigned int)(v838 + 68) >> 2)) >> 1))) | (-(v841 ^ ((int)((unsigned int)((int)((unsigned int)(v838 + 68) >> 2)) >> 1))))) >> 31)) & 1);
    int v848 = v847[v956];
    int v849 = v847[v949];
    int v957 = v849 + ((int)((unsigned int)(v849 - v848) >> 31));
    v847[v949] = v957;
    int * v851 = v834->cache_age;
    int v852 = v851[v950];
    int v959 = v852 + ((int)((unsigned int)(v852 - v848) >> 31));
    v851[v950] = v959;
    int * v854 = v834->cache_age;
    v854[v956] = 0;
    v939 = v956;
  } else {
    int * v857 = v834->cache_age;
    int v963 = (((int)((unsigned int)((int)((unsigned int)(v838 + 68) >> 2)) >> 1)) & 1) * 2;
    int v858 = v857[v963];
    int * v859 = v834->cache_tags;
    int v860 = v859[v963];
    int v861 = v857[v950];
    int v862 = v859[v950];
    bool v965 = !(((~(((v842 ^ ((int)((unsigned int)((int)((unsigned int)(v838 + 68) >> 2)) >> 1))) | (-(v842 ^ ((int)((unsigned int)((int)((unsigned int)(v838 + 68) >> 2)) >> 1))))) >> 31)) | (~(((v843 ^ ((int)((unsigned int)((int)((unsigned int)(v838 + 68) >> 2)) >> 1))) | (-(v843 ^ ((int)((unsigned int)((int)((unsigned int)(v838 + 68) >> 2)) >> 1))))) >> 31))) == 0);
    int v916;
    if (v965) {
      int * v863 = v834->cache_age;
      int v967 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v838 + 68) >> 2)) >> 1)) & 3) * 2)) + ((~(((v843 ^ ((int)((unsigned int)((int)((unsigned int)(v838 + 68) >> 2)) >> 1))) | (-(v843 ^ ((int)((unsigned int)((int)((unsigned int)(v838 + 68) >> 2)) >> 1))))) >> 31)) & 1);
      int v864 = v863[v967];
      int v865 = v863[v951];
      int v968 = v865 + ((int)((unsigned int)(v865 - v864) >> 31));
      v863[v951] = v968;
      int * v867 = v834->cache_age;
      int v868 = v867[v952];
      int v970 = v868 + ((int)((unsigned int)(v868 - v864) >> 31));
      v867[v952] = v970;
      int * v870 = v834->cache_age;
      v870[v967] = 0;
      v916 = v967;
    } else {
      int * v873 = v834->cache_age;
      int v974 = 4 + ((((int)((unsigned int)((int)((unsigned int)(v838 + 68) >> 2)) >> 1)) & 3) * 2);
      int v874 = v873[v974];
      int * v875 = v834->cache_tags;
      int v876 = v875[v974];
      int v877 = v873[v952];
      int v878 = v875[v952];
      int * v879 = v834->cache_dirty;
      int v977 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v838 + 68) >> 2)) >> 1)) & 3) * 2)) + ((((v874 + ((~(((v876 ^ -1) | (-(v876 ^ -1))) >> 31)) & 2)) - (v877 + ((~(((v878 ^ -1) | (-(v878 ^ -1))) >> 31)) & 2))) >> 31) & 1);
      int v880 = v879[v977];
      bool v978 = !(v880 == 0);
      if (v978) {
        int * v881 = v834->cache_tags;
        int v882 = v881[v977];
        int * v883 = v834->cache_vals;
        int v981 = ((4 + ((((int)((unsigned int)((int)((unsigned int)(v838 + 68) >> 2)) >> 1)) & 3) * 2)) + ((((v874 + ((~(((v876 ^ -1) | (-(v876 ^ -1))) >> 31)) & 2)) - (v877 + ((~(((v878 ^ -1) | (-(v878 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
        int v884 = v883[v981];
        int v982 = (((4 + ((((int)((unsigned int)((int)((unsigned int)(v838 + 68) >> 2)) >> 1)) & 3) * 2)) + ((((v874 + ((~(((v876 ^ -1) | (-(v876 ^ -1))) >> 31)) & 2)) - (v877 + ((~(((v878 ^ -1) | (-(v878 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
        int v885 = v883[v982];
        int * v886 = v834->mem;
        int v984 = v882 * 2;
        v886[v984] = v884;
        int * v888 = v834->mem;
        int v987 = (v882 * 2) + 1;
        v888[v987] = v885;
        ;
      } else {
        ;
      }
      int * v893 = v834->mem;
      int v992 = ((int)((unsigned int)((int)((unsigned int)(v838 + 68) >> 2)) >> 1)) * 2;
      int v894 = v893[v992];
      int v993 = (((int)((unsigned int)((int)((unsigned int)(v838 + 68) >> 2)) >> 1)) * 2) + 1;
      int v895 = v893[v993];
      int * v896 = v834->cache_vals;
      int v995 = ((4 + ((((int)((unsigned int)((int)((unsigned int)(v838 + 68) >> 2)) >> 1)) & 3) * 2)) + ((((v874 + ((~(((v876 ^ -1) | (-(v876 ^ -1))) >> 31)) & 2)) - (v877 + ((~(((v878 ^ -1) | (-(v878 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
      v896[v995] = v894;
      int * v898 = v834->cache_vals;
      int v998 = (((4 + ((((int)((unsigned int)((int)((unsigned int)(v838 + 68) >> 2)) >> 1)) & 3) * 2)) + ((((v874 + ((~(((v876 ^ -1) | (-(v876 ^ -1))) >> 31)) & 2)) - (v877 + ((~(((v878 ^ -1) | (-(v878 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
      v898[v998] = v895;
      int * v900 = v834->cache_tags;
      int v1001 = (int)((unsigned int)((int)((unsigned int)(v838 + 68) >> 2)) >> 1);
      v900[v977] = v1001;
      int * v902 = v834->cache_dirty;
      v902[v977] = 0;
      int * v904 = v834->cache_age;
      v904[v977] = 1;
      int * v906 = v834->cache_age;
      int v907 = v906[v977];
      int v908 = v906[v951];
      int v1007 = v908 + ((int)((unsigned int)(v908 - v907) >> 31));
      v906[v951] = v1007;
      int * v910 = v834->cache_age;
      int v911 = v910[v952];
      int v1009 = v911 + ((int)((unsigned int)(v911 - v907) >> 31));
      v910[v952] = v1009;
      int * v913 = v834->cache_age;
      v913[v977] = 0;
      v916 = v977;
    }
    int * v917 = v834->cache_vals;
    int v1012 = v916 * 2;
    int v918 = v917[v1012];
    int v1013 = (v916 * 2) + 1;
    int v919 = v917[v1013];
    int v1014 = (((((int)((unsigned int)((int)((unsigned int)(v838 + 68) >> 2)) >> 1)) & 1) * 2) + ((((v858 + ((~(((v860 ^ -1) | (-(v860 ^ -1))) >> 31)) & 2)) - (v861 + ((~(((v862 ^ -1) | (-(v862 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
    v917[v1014] = v918;
    int * v921 = v834->cache_vals;
    int v1017 = ((((((int)((unsigned int)((int)((unsigned int)(v838 + 68) >> 2)) >> 1)) & 1) * 2) + ((((v858 + ((~(((v860 ^ -1) | (-(v860 ^ -1))) >> 31)) & 2)) - (v861 + ((~(((v862 ^ -1) | (-(v862 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
    v921[v1017] = v919;
    int * v923 = v834->cache_tags;
    int v1020 = ((((int)((unsigned int)((int)((unsigned int)(v838 + 68) >> 2)) >> 1)) & 1) * 2) + ((((v858 + ((~(((v860 ^ -1) | (-(v860 ^ -1))) >> 31)) & 2)) - (v861 + ((~(((v862 ^ -1) | (-(v862 ^ -1))) >> 31)) & 2))) >> 31) & 1);
    int v1021 = (int)((unsigned int)((int)((unsigned int)(v838 + 68) >> 2)) >> 1);
    v923[v1020] = v1021;
    int * v925 = v834->cache_dirty;
    v925[v1020] = 0;
    int * v927 = v834->cache_age;
    v927[v1020] = 1;
    int * v929 = v834->cache_age;
    int v930 = v929[v1020];
    int v931 = v929[v949];
    int v1027 = v931 + ((int)((unsigned int)(v931 - v930) >> 31));
    v929[v949] = v1027;
    int * v933 = v834->cache_age;
    int v934 = v933[v950];
    int v1029 = v934 + ((int)((unsigned int)(v934 - v930) >> 31));
    v933[v950] = v1029;
    int * v936 = v834->cache_age;
    v936[v1020] = 0;
    v939 = v1020;
  }
  int v1032 = (v939 * 2) + (((int)((unsigned int)(v838 + 68) >> 2)) & 1);
  int v940 = v846[v1032];
  int * v941 = v834->regs;
  v941[11] = v940;
  struct StateT * v943 = slot_19(v834);
  return v943;
}

struct StateT * slot_9(struct StateT * v328) {
  int v329 = v328->timer;
  int v337 = v329 + 1;
  v328->timer = v337;
  int * v331 = v328->regs;
  int v332 = v331[11];
  int v333 = v331[10];
  int v341 = v332 + v333;
  v331[10] = v341;
  struct StateT * v335 = slot_10(v328);
  return v335;
}

struct StateT * slot_11(struct StateT * v547) {
  int v548 = v547->timer;
  int v554 = v548 + 1;
  v547->timer = v554;
  int * v550 = v547->regs;
  v550[11] = 0;
  struct StateT * v552 = slot_12(v547);
  return v552;
}



/*****************************************
End of C Generated Code
*******************************************/

void init(struct StateT *s) {
  for (int i=0; i<NUM_REGS; i++) {
    s->regs[i] = 0;
    s->saved_regs[i] = 0;
    s->reg_ready[i] = 0;
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
  
  // public data, where the section headers put it
  s1.mem[0] = 8;
  s2.mem[0] = 8;
  int x = bounded(0, 15);
  s1.regs[10] = x;
  s2.regs[10] = x;
  // probe, the attacker's: the same draw in both states
  for (int i=0; i<16; i++) {
    int v = bounded(0, 20);
    s1.mem[1 + i] = v;
    s2.mem[1 + i] = v;
  }
  // temp, the attacker's: the same draw in both states
  for (int i=0; i<1; i++) {
    int v = bounded(0, 20);
    s1.mem[17 + i] = v;
    s2.mem[17 + i] = v;
  }
  // publicarray, the attacker's: the same draw in both states
  for (int i=0; i<8; i++) {
    int v = bounded(0, 20);
    s1.mem[18 + i] = v;
    s2.mem[18 + i] = v;
  }
  
  // secretarray, secret: a different draw in each state
  for (int i=0; i<8; i++) {
    s1.mem[26 + i] = secret(0, 20);
    s2.mem[26 + i] = secret(0, 20);
  }
  struct StateT *s1_ = snippet(&s1);
  struct StateT *s2_ = snippet(&s2);
  //@ assert untainted_timer: !\tainted(s1_->timer==s2_->timer);
  koika_assert(s1_->timer==s2_->timer, "timing leak");
  return 0;
}