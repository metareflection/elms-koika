// verify: clean (KLEE should report no failing assertion) [budget 1200s]
#define NUM_REGS 32
#define MEM_SIZE 64
#define SECRET_SIZE 10
#define SECRET_OFFSET 20
#define CACHE_ENTRIES 12
#define CACHE_WORDS 24

#ifdef KLEE
#include <assert.h>
#include <klee/klee.h>
#define koika_assert(b, s) klee_assert(b)
#define koika_assume(b) klee_assume(b)
#define koika_draw(x) klee_make_symbolic(&(x), sizeof(x), #x)
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

struct StateT2 {
  struct StateT * a;
  struct StateT * b;
};

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

void squared_assert(bool);
void squared_assume(bool);
void squared_diverged(bool);

struct StateT2 * slot_6(struct StateT2 * v631);
struct StateT2 * slot_5(struct StateT2 * v195);
struct StateT2 * slot_2(struct StateT2 * v74);
struct StateT2 * slot_3(struct StateT2 * v110);
struct StateT2 * snippet(struct StateT2 * v0);
struct StateT2 * slot_10(struct StateT2 * v1761);
struct StateT2 * slot_1(struct StateT2 * v38);
struct StateT2 * slot_8(struct StateT2 * v707);
struct StateT2 * slot_4(struct StateT2 * v134);
struct StateT2 * slot_9(struct StateT2 * v1343);
struct StateT2 * slot_11(struct StateT2 * v1800);
struct StateT2 * slot_0(struct StateT2 * v2);
struct StateT2 * slot_6(struct StateT2 * v631) {
  struct StateT * v632 = v631->a;
  int v633 = v632->timer;
  struct StateT * v634 = v631->b;
  int v635 = v634->timer;
  bool v677 = v633 == v635;
  squared_assert(v677);
  squared_assume(v677);
  struct StateT * v638 = v631->a;
  int * v639 = v638->regs;
  int v640 = v639[6];
  int v641 = v639[7];
  struct StateT * v642 = v631->b;
  int * v643 = v642->regs;
  int v644 = v643[6];
  int v645 = v643[7];
  bool v684 = (v640 >= v641) == (v644 >= v645);
  squared_diverged(v684);
  squared_assume(v684);
  bool v685 = v640 >= v641;
  struct StateT2 * v673;
  if (v685) {
    struct StateT * v648 = v631->a;
    int v649 = v648->timer;
    int v687 = v649 + 15;
    v648->timer = v687;
    int * v651 = v648->saved_regs;
    int v652 = v651[8];
    int * v653 = v648->regs;
    v653[8] = v652;
    int * v655 = v648->saved_regs;
    int v656 = v655[5];
    int * v657 = v648->regs;
    v657[5] = v656;
    struct StateT * v659 = v631->b;
    int v660 = v659->timer;
    int v697 = v660 + 15;
    v659->timer = v697;
    int * v662 = v659->saved_regs;
    int v663 = v662[8];
    int * v664 = v659->regs;
    v664[8] = v663;
    int * v666 = v659->saved_regs;
    int v667 = v666[5];
    int * v668 = v659->regs;
    v668[5] = v667;
    v673 = v631;
  } else {
    struct StateT2 * v671 = slot_8(v631);
    v673 = v671;
  }
  return v673;
}

struct StateT2 * slot_5(struct StateT2 * v195) {
  struct StateT * v196 = v195->a;
  int v197 = v196->timer;
  struct StateT * v198 = v195->b;
  int v199 = v198->timer;
  bool v436 = v197 == v199;
  squared_assert(v436);
  squared_assume(v436);
  struct StateT * v202 = v195->a;
  int * v203 = v202->saved_regs;
  int * v204 = v202->regs;
  int v205 = v204[5];
  v203[5] = v205;
  struct StateT * v207 = v195->b;
  int * v208 = v207->saved_regs;
  int * v209 = v207->regs;
  int v210 = v209[5];
  v208[5] = v210;
  struct StateT * v212 = v195->a;
  int v213 = v212->timer;
  int v447 = v213 + 1;
  v212->timer = v447;
  struct StateT * v215 = v195->b;
  int v216 = v215->timer;
  int v449 = v216 + 1;
  v215->timer = v449;
  struct StateT * v218 = v195->a;
  int * v219 = v218->regs;
  int v220 = v219[8];
  int * v221 = v218->cache_tags;
  int v454 = (((int)((unsigned int)((int)((unsigned int)v220 >> 2)) >> 1)) & 1) * 2;
  int v222 = v221[v454];
  int v455 = ((((int)((unsigned int)((int)((unsigned int)v220 >> 2)) >> 1)) & 1) * 2) + 1;
  int v223 = v221[v455];
  int v456 = 4 + ((((int)((unsigned int)((int)((unsigned int)v220 >> 2)) >> 1)) & 3) * 2);
  int v224 = v221[v456];
  int v457 = (4 + ((((int)((unsigned int)((int)((unsigned int)v220 >> 2)) >> 1)) & 3) * 2)) + 1;
  int v225 = v221[v457];
  int v226 = v218->timer;
  int v458 = v226 + ((100 ^ (((~(((v224 ^ ((int)((unsigned int)((int)((unsigned int)v220 >> 2)) >> 1))) | (-(v224 ^ ((int)((unsigned int)((int)((unsigned int)v220 >> 2)) >> 1))))) >> 31)) | (~(((v225 ^ ((int)((unsigned int)((int)((unsigned int)v220 >> 2)) >> 1))) | (-(v225 ^ ((int)((unsigned int)((int)((unsigned int)v220 >> 2)) >> 1))))) >> 31))) & 104)) ^ (((~(((v222 ^ ((int)((unsigned int)((int)((unsigned int)v220 >> 2)) >> 1))) | (-(v222 ^ ((int)((unsigned int)((int)((unsigned int)v220 >> 2)) >> 1))))) >> 31)) | (~(((v223 ^ ((int)((unsigned int)((int)((unsigned int)v220 >> 2)) >> 1))) | (-(v223 ^ ((int)((unsigned int)((int)((unsigned int)v220 >> 2)) >> 1))))) >> 31))) & (1 ^ (100 ^ (((~(((v224 ^ ((int)((unsigned int)((int)((unsigned int)v220 >> 2)) >> 1))) | (-(v224 ^ ((int)((unsigned int)((int)((unsigned int)v220 >> 2)) >> 1))))) >> 31)) | (~(((v225 ^ ((int)((unsigned int)((int)((unsigned int)v220 >> 2)) >> 1))) | (-(v225 ^ ((int)((unsigned int)((int)((unsigned int)v220 >> 2)) >> 1))))) >> 31))) & 104)))));
  v218->timer = v458;
  int * v228 = v218->cache_vals;
  bool v459 = !(((~(((v222 ^ ((int)((unsigned int)((int)((unsigned int)v220 >> 2)) >> 1))) | (-(v222 ^ ((int)((unsigned int)((int)((unsigned int)v220 >> 2)) >> 1))))) >> 31)) | (~(((v223 ^ ((int)((unsigned int)((int)((unsigned int)v220 >> 2)) >> 1))) | (-(v223 ^ ((int)((unsigned int)((int)((unsigned int)v220 >> 2)) >> 1))))) >> 31))) == 0);
  int v321;
  if (v459) {
    int * v229 = v218->cache_age;
    int v461 = ((((int)((unsigned int)((int)((unsigned int)v220 >> 2)) >> 1)) & 1) * 2) + ((~(((v223 ^ ((int)((unsigned int)((int)((unsigned int)v220 >> 2)) >> 1))) | (-(v223 ^ ((int)((unsigned int)((int)((unsigned int)v220 >> 2)) >> 1))))) >> 31)) & 1);
    int v230 = v229[v461];
    int v231 = v229[v454];
    int v462 = v231 + ((int)((unsigned int)(v231 - v230) >> 31));
    v229[v454] = v462;
    int * v233 = v218->cache_age;
    int v234 = v233[v455];
    int v464 = v234 + ((int)((unsigned int)(v234 - v230) >> 31));
    v233[v455] = v464;
    int * v236 = v218->cache_age;
    v236[v461] = 0;
    v321 = v461;
  } else {
    int * v239 = v218->cache_age;
    int v468 = (((int)((unsigned int)((int)((unsigned int)v220 >> 2)) >> 1)) & 1) * 2;
    int v240 = v239[v468];
    int * v241 = v218->cache_tags;
    int v242 = v241[v468];
    int v243 = v239[v455];
    int v244 = v241[v455];
    bool v470 = !(((~(((v224 ^ ((int)((unsigned int)((int)((unsigned int)v220 >> 2)) >> 1))) | (-(v224 ^ ((int)((unsigned int)((int)((unsigned int)v220 >> 2)) >> 1))))) >> 31)) | (~(((v225 ^ ((int)((unsigned int)((int)((unsigned int)v220 >> 2)) >> 1))) | (-(v225 ^ ((int)((unsigned int)((int)((unsigned int)v220 >> 2)) >> 1))))) >> 31))) == 0);
    int v298;
    if (v470) {
      int * v245 = v218->cache_age;
      int v472 = (4 + ((((int)((unsigned int)((int)((unsigned int)v220 >> 2)) >> 1)) & 3) * 2)) + ((~(((v225 ^ ((int)((unsigned int)((int)((unsigned int)v220 >> 2)) >> 1))) | (-(v225 ^ ((int)((unsigned int)((int)((unsigned int)v220 >> 2)) >> 1))))) >> 31)) & 1);
      int v246 = v245[v472];
      int v247 = v245[v456];
      int v473 = v247 + ((int)((unsigned int)(v247 - v246) >> 31));
      v245[v456] = v473;
      int * v249 = v218->cache_age;
      int v250 = v249[v457];
      int v475 = v250 + ((int)((unsigned int)(v250 - v246) >> 31));
      v249[v457] = v475;
      int * v252 = v218->cache_age;
      v252[v472] = 0;
      v298 = v472;
    } else {
      int * v255 = v218->cache_age;
      int v479 = 4 + ((((int)((unsigned int)((int)((unsigned int)v220 >> 2)) >> 1)) & 3) * 2);
      int v256 = v255[v479];
      int * v257 = v218->cache_tags;
      int v258 = v257[v479];
      int v259 = v255[v457];
      int v260 = v257[v457];
      int * v261 = v218->cache_dirty;
      int v482 = (4 + ((((int)((unsigned int)((int)((unsigned int)v220 >> 2)) >> 1)) & 3) * 2)) + ((((v256 + ((~(((v258 ^ -1) | (-(v258 ^ -1))) >> 31)) & 2)) - (v259 + ((~(((v260 ^ -1) | (-(v260 ^ -1))) >> 31)) & 2))) >> 31) & 1);
      int v262 = v261[v482];
      bool v483 = !(v262 == 0);
      if (v483) {
        int * v263 = v218->cache_tags;
        int v264 = v263[v482];
        int * v265 = v218->cache_vals;
        int v486 = ((4 + ((((int)((unsigned int)((int)((unsigned int)v220 >> 2)) >> 1)) & 3) * 2)) + ((((v256 + ((~(((v258 ^ -1) | (-(v258 ^ -1))) >> 31)) & 2)) - (v259 + ((~(((v260 ^ -1) | (-(v260 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
        int v266 = v265[v486];
        int v487 = (((4 + ((((int)((unsigned int)((int)((unsigned int)v220 >> 2)) >> 1)) & 3) * 2)) + ((((v256 + ((~(((v258 ^ -1) | (-(v258 ^ -1))) >> 31)) & 2)) - (v259 + ((~(((v260 ^ -1) | (-(v260 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
        int v267 = v265[v487];
        int * v268 = v218->mem;
        int v489 = v264 * 2;
        v268[v489] = v266;
        int * v270 = v218->mem;
        int v492 = (v264 * 2) + 1;
        v270[v492] = v267;
        ;
      } else {
        ;
      }
      int * v275 = v218->mem;
      int v497 = ((int)((unsigned int)((int)((unsigned int)v220 >> 2)) >> 1)) * 2;
      int v276 = v275[v497];
      int v498 = (((int)((unsigned int)((int)((unsigned int)v220 >> 2)) >> 1)) * 2) + 1;
      int v277 = v275[v498];
      int * v278 = v218->cache_vals;
      int v500 = ((4 + ((((int)((unsigned int)((int)((unsigned int)v220 >> 2)) >> 1)) & 3) * 2)) + ((((v256 + ((~(((v258 ^ -1) | (-(v258 ^ -1))) >> 31)) & 2)) - (v259 + ((~(((v260 ^ -1) | (-(v260 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
      v278[v500] = v276;
      int * v280 = v218->cache_vals;
      int v503 = (((4 + ((((int)((unsigned int)((int)((unsigned int)v220 >> 2)) >> 1)) & 3) * 2)) + ((((v256 + ((~(((v258 ^ -1) | (-(v258 ^ -1))) >> 31)) & 2)) - (v259 + ((~(((v260 ^ -1) | (-(v260 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
      v280[v503] = v277;
      int * v282 = v218->cache_tags;
      int v506 = (int)((unsigned int)((int)((unsigned int)v220 >> 2)) >> 1);
      v282[v482] = v506;
      int * v284 = v218->cache_dirty;
      v284[v482] = 0;
      int * v286 = v218->cache_age;
      v286[v482] = 1;
      int * v288 = v218->cache_age;
      int v289 = v288[v482];
      int v290 = v288[v456];
      int v512 = v290 + ((int)((unsigned int)(v290 - v289) >> 31));
      v288[v456] = v512;
      int * v292 = v218->cache_age;
      int v293 = v292[v457];
      int v514 = v293 + ((int)((unsigned int)(v293 - v289) >> 31));
      v292[v457] = v514;
      int * v295 = v218->cache_age;
      v295[v482] = 0;
      v298 = v482;
    }
    int * v299 = v218->cache_vals;
    int v517 = v298 * 2;
    int v300 = v299[v517];
    int v518 = (v298 * 2) + 1;
    int v301 = v299[v518];
    int v519 = (((((int)((unsigned int)((int)((unsigned int)v220 >> 2)) >> 1)) & 1) * 2) + ((((v240 + ((~(((v242 ^ -1) | (-(v242 ^ -1))) >> 31)) & 2)) - (v243 + ((~(((v244 ^ -1) | (-(v244 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
    v299[v519] = v300;
    int * v303 = v218->cache_vals;
    int v522 = ((((((int)((unsigned int)((int)((unsigned int)v220 >> 2)) >> 1)) & 1) * 2) + ((((v240 + ((~(((v242 ^ -1) | (-(v242 ^ -1))) >> 31)) & 2)) - (v243 + ((~(((v244 ^ -1) | (-(v244 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
    v303[v522] = v301;
    int * v305 = v218->cache_tags;
    int v525 = ((((int)((unsigned int)((int)((unsigned int)v220 >> 2)) >> 1)) & 1) * 2) + ((((v240 + ((~(((v242 ^ -1) | (-(v242 ^ -1))) >> 31)) & 2)) - (v243 + ((~(((v244 ^ -1) | (-(v244 ^ -1))) >> 31)) & 2))) >> 31) & 1);
    int v526 = (int)((unsigned int)((int)((unsigned int)v220 >> 2)) >> 1);
    v305[v525] = v526;
    int * v307 = v218->cache_dirty;
    v307[v525] = 0;
    int * v309 = v218->cache_age;
    v309[v525] = 1;
    int * v311 = v218->cache_age;
    int v312 = v311[v525];
    int v313 = v311[v454];
    int v532 = v313 + ((int)((unsigned int)(v313 - v312) >> 31));
    v311[v454] = v532;
    int * v315 = v218->cache_age;
    int v316 = v315[v455];
    int v534 = v316 + ((int)((unsigned int)(v316 - v312) >> 31));
    v315[v455] = v534;
    int * v318 = v218->cache_age;
    v318[v525] = 0;
    v321 = v525;
  }
  int v537 = (v321 * 2) + (((int)((unsigned int)v220 >> 2)) & 1);
  int v322 = v228[v537];
  int * v323 = v218->regs;
  v323[5] = v322;
  struct StateT * v325 = v195->b;
  int * v326 = v325->regs;
  int v327 = v326[8];
  int * v328 = v325->cache_tags;
  int v543 = (((int)((unsigned int)((int)((unsigned int)v327 >> 2)) >> 1)) & 1) * 2;
  int v329 = v328[v543];
  int v544 = ((((int)((unsigned int)((int)((unsigned int)v327 >> 2)) >> 1)) & 1) * 2) + 1;
  int v330 = v328[v544];
  int v545 = 4 + ((((int)((unsigned int)((int)((unsigned int)v327 >> 2)) >> 1)) & 3) * 2);
  int v331 = v328[v545];
  int v546 = (4 + ((((int)((unsigned int)((int)((unsigned int)v327 >> 2)) >> 1)) & 3) * 2)) + 1;
  int v332 = v328[v546];
  int v333 = v325->timer;
  int v547 = v333 + ((100 ^ (((~(((v331 ^ ((int)((unsigned int)((int)((unsigned int)v327 >> 2)) >> 1))) | (-(v331 ^ ((int)((unsigned int)((int)((unsigned int)v327 >> 2)) >> 1))))) >> 31)) | (~(((v332 ^ ((int)((unsigned int)((int)((unsigned int)v327 >> 2)) >> 1))) | (-(v332 ^ ((int)((unsigned int)((int)((unsigned int)v327 >> 2)) >> 1))))) >> 31))) & 104)) ^ (((~(((v329 ^ ((int)((unsigned int)((int)((unsigned int)v327 >> 2)) >> 1))) | (-(v329 ^ ((int)((unsigned int)((int)((unsigned int)v327 >> 2)) >> 1))))) >> 31)) | (~(((v330 ^ ((int)((unsigned int)((int)((unsigned int)v327 >> 2)) >> 1))) | (-(v330 ^ ((int)((unsigned int)((int)((unsigned int)v327 >> 2)) >> 1))))) >> 31))) & (1 ^ (100 ^ (((~(((v331 ^ ((int)((unsigned int)((int)((unsigned int)v327 >> 2)) >> 1))) | (-(v331 ^ ((int)((unsigned int)((int)((unsigned int)v327 >> 2)) >> 1))))) >> 31)) | (~(((v332 ^ ((int)((unsigned int)((int)((unsigned int)v327 >> 2)) >> 1))) | (-(v332 ^ ((int)((unsigned int)((int)((unsigned int)v327 >> 2)) >> 1))))) >> 31))) & 104)))));
  v325->timer = v547;
  int * v335 = v325->cache_vals;
  bool v548 = !(((~(((v329 ^ ((int)((unsigned int)((int)((unsigned int)v327 >> 2)) >> 1))) | (-(v329 ^ ((int)((unsigned int)((int)((unsigned int)v327 >> 2)) >> 1))))) >> 31)) | (~(((v330 ^ ((int)((unsigned int)((int)((unsigned int)v327 >> 2)) >> 1))) | (-(v330 ^ ((int)((unsigned int)((int)((unsigned int)v327 >> 2)) >> 1))))) >> 31))) == 0);
  int v428;
  if (v548) {
    int * v336 = v325->cache_age;
    int v550 = ((((int)((unsigned int)((int)((unsigned int)v327 >> 2)) >> 1)) & 1) * 2) + ((~(((v330 ^ ((int)((unsigned int)((int)((unsigned int)v327 >> 2)) >> 1))) | (-(v330 ^ ((int)((unsigned int)((int)((unsigned int)v327 >> 2)) >> 1))))) >> 31)) & 1);
    int v337 = v336[v550];
    int v338 = v336[v543];
    int v551 = v338 + ((int)((unsigned int)(v338 - v337) >> 31));
    v336[v543] = v551;
    int * v340 = v325->cache_age;
    int v341 = v340[v544];
    int v553 = v341 + ((int)((unsigned int)(v341 - v337) >> 31));
    v340[v544] = v553;
    int * v343 = v325->cache_age;
    v343[v550] = 0;
    v428 = v550;
  } else {
    int * v346 = v325->cache_age;
    int v557 = (((int)((unsigned int)((int)((unsigned int)v327 >> 2)) >> 1)) & 1) * 2;
    int v347 = v346[v557];
    int * v348 = v325->cache_tags;
    int v349 = v348[v557];
    int v350 = v346[v544];
    int v351 = v348[v544];
    bool v559 = !(((~(((v331 ^ ((int)((unsigned int)((int)((unsigned int)v327 >> 2)) >> 1))) | (-(v331 ^ ((int)((unsigned int)((int)((unsigned int)v327 >> 2)) >> 1))))) >> 31)) | (~(((v332 ^ ((int)((unsigned int)((int)((unsigned int)v327 >> 2)) >> 1))) | (-(v332 ^ ((int)((unsigned int)((int)((unsigned int)v327 >> 2)) >> 1))))) >> 31))) == 0);
    int v405;
    if (v559) {
      int * v352 = v325->cache_age;
      int v561 = (4 + ((((int)((unsigned int)((int)((unsigned int)v327 >> 2)) >> 1)) & 3) * 2)) + ((~(((v332 ^ ((int)((unsigned int)((int)((unsigned int)v327 >> 2)) >> 1))) | (-(v332 ^ ((int)((unsigned int)((int)((unsigned int)v327 >> 2)) >> 1))))) >> 31)) & 1);
      int v353 = v352[v561];
      int v354 = v352[v545];
      int v562 = v354 + ((int)((unsigned int)(v354 - v353) >> 31));
      v352[v545] = v562;
      int * v356 = v325->cache_age;
      int v357 = v356[v546];
      int v564 = v357 + ((int)((unsigned int)(v357 - v353) >> 31));
      v356[v546] = v564;
      int * v359 = v325->cache_age;
      v359[v561] = 0;
      v405 = v561;
    } else {
      int * v362 = v325->cache_age;
      int v568 = 4 + ((((int)((unsigned int)((int)((unsigned int)v327 >> 2)) >> 1)) & 3) * 2);
      int v363 = v362[v568];
      int * v364 = v325->cache_tags;
      int v365 = v364[v568];
      int v366 = v362[v546];
      int v367 = v364[v546];
      int * v368 = v325->cache_dirty;
      int v571 = (4 + ((((int)((unsigned int)((int)((unsigned int)v327 >> 2)) >> 1)) & 3) * 2)) + ((((v363 + ((~(((v365 ^ -1) | (-(v365 ^ -1))) >> 31)) & 2)) - (v366 + ((~(((v367 ^ -1) | (-(v367 ^ -1))) >> 31)) & 2))) >> 31) & 1);
      int v369 = v368[v571];
      bool v572 = !(v369 == 0);
      if (v572) {
        int * v370 = v325->cache_tags;
        int v371 = v370[v571];
        int * v372 = v325->cache_vals;
        int v575 = ((4 + ((((int)((unsigned int)((int)((unsigned int)v327 >> 2)) >> 1)) & 3) * 2)) + ((((v363 + ((~(((v365 ^ -1) | (-(v365 ^ -1))) >> 31)) & 2)) - (v366 + ((~(((v367 ^ -1) | (-(v367 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
        int v373 = v372[v575];
        int v576 = (((4 + ((((int)((unsigned int)((int)((unsigned int)v327 >> 2)) >> 1)) & 3) * 2)) + ((((v363 + ((~(((v365 ^ -1) | (-(v365 ^ -1))) >> 31)) & 2)) - (v366 + ((~(((v367 ^ -1) | (-(v367 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
        int v374 = v372[v576];
        int * v375 = v325->mem;
        int v578 = v371 * 2;
        v375[v578] = v373;
        int * v377 = v325->mem;
        int v581 = (v371 * 2) + 1;
        v377[v581] = v374;
        ;
      } else {
        ;
      }
      int * v382 = v325->mem;
      int v586 = ((int)((unsigned int)((int)((unsigned int)v327 >> 2)) >> 1)) * 2;
      int v383 = v382[v586];
      int v587 = (((int)((unsigned int)((int)((unsigned int)v327 >> 2)) >> 1)) * 2) + 1;
      int v384 = v382[v587];
      int * v385 = v325->cache_vals;
      int v589 = ((4 + ((((int)((unsigned int)((int)((unsigned int)v327 >> 2)) >> 1)) & 3) * 2)) + ((((v363 + ((~(((v365 ^ -1) | (-(v365 ^ -1))) >> 31)) & 2)) - (v366 + ((~(((v367 ^ -1) | (-(v367 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
      v385[v589] = v383;
      int * v387 = v325->cache_vals;
      int v592 = (((4 + ((((int)((unsigned int)((int)((unsigned int)v327 >> 2)) >> 1)) & 3) * 2)) + ((((v363 + ((~(((v365 ^ -1) | (-(v365 ^ -1))) >> 31)) & 2)) - (v366 + ((~(((v367 ^ -1) | (-(v367 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
      v387[v592] = v384;
      int * v389 = v325->cache_tags;
      int v595 = (int)((unsigned int)((int)((unsigned int)v327 >> 2)) >> 1);
      v389[v571] = v595;
      int * v391 = v325->cache_dirty;
      v391[v571] = 0;
      int * v393 = v325->cache_age;
      v393[v571] = 1;
      int * v395 = v325->cache_age;
      int v396 = v395[v571];
      int v397 = v395[v545];
      int v601 = v397 + ((int)((unsigned int)(v397 - v396) >> 31));
      v395[v545] = v601;
      int * v399 = v325->cache_age;
      int v400 = v399[v546];
      int v603 = v400 + ((int)((unsigned int)(v400 - v396) >> 31));
      v399[v546] = v603;
      int * v402 = v325->cache_age;
      v402[v571] = 0;
      v405 = v571;
    }
    int * v406 = v325->cache_vals;
    int v606 = v405 * 2;
    int v407 = v406[v606];
    int v607 = (v405 * 2) + 1;
    int v408 = v406[v607];
    int v608 = (((((int)((unsigned int)((int)((unsigned int)v327 >> 2)) >> 1)) & 1) * 2) + ((((v347 + ((~(((v349 ^ -1) | (-(v349 ^ -1))) >> 31)) & 2)) - (v350 + ((~(((v351 ^ -1) | (-(v351 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
    v406[v608] = v407;
    int * v410 = v325->cache_vals;
    int v611 = ((((((int)((unsigned int)((int)((unsigned int)v327 >> 2)) >> 1)) & 1) * 2) + ((((v347 + ((~(((v349 ^ -1) | (-(v349 ^ -1))) >> 31)) & 2)) - (v350 + ((~(((v351 ^ -1) | (-(v351 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
    v410[v611] = v408;
    int * v412 = v325->cache_tags;
    int v614 = ((((int)((unsigned int)((int)((unsigned int)v327 >> 2)) >> 1)) & 1) * 2) + ((((v347 + ((~(((v349 ^ -1) | (-(v349 ^ -1))) >> 31)) & 2)) - (v350 + ((~(((v351 ^ -1) | (-(v351 ^ -1))) >> 31)) & 2))) >> 31) & 1);
    int v615 = (int)((unsigned int)((int)((unsigned int)v327 >> 2)) >> 1);
    v412[v614] = v615;
    int * v414 = v325->cache_dirty;
    v414[v614] = 0;
    int * v416 = v325->cache_age;
    v416[v614] = 1;
    int * v418 = v325->cache_age;
    int v419 = v418[v614];
    int v420 = v418[v543];
    int v621 = v420 + ((int)((unsigned int)(v420 - v419) >> 31));
    v418[v543] = v621;
    int * v422 = v325->cache_age;
    int v423 = v422[v544];
    int v623 = v423 + ((int)((unsigned int)(v423 - v419) >> 31));
    v422[v544] = v623;
    int * v425 = v325->cache_age;
    v425[v614] = 0;
    v428 = v614;
  }
  int v626 = (v428 * 2) + (((int)((unsigned int)v327 >> 2)) & 1);
  int v429 = v335[v626];
  int * v430 = v325->regs;
  v430[5] = v429;
  struct StateT2 * v432 = slot_6(v195);
  return v432;
}

struct StateT2 * slot_2(struct StateT2 * v74) {
  struct StateT * v75 = v74->a;
  int v76 = v75->timer;
  struct StateT * v77 = v74->b;
  int v78 = v77->timer;
  bool v97 = v76 == v78;
  squared_assert(v97);
  squared_assume(v97);
  struct StateT * v81 = v74->a;
  int v82 = v81->timer;
  int v99 = v82 + 1;
  v81->timer = v99;
  struct StateT * v84 = v74->b;
  int v85 = v84->timer;
  int v101 = v85 + 1;
  v84->timer = v101;
  struct StateT * v87 = v74->a;
  int * v88 = v87->regs;
  v88[9] = 80;
  struct StateT * v90 = v74->b;
  int * v91 = v90->regs;
  v91[9] = 80;
  struct StateT2 * v93 = slot_3(v74);
  return v93;
}

struct StateT2 * slot_3(struct StateT2 * v110) {
  struct StateT * v111 = v110->a;
  int v112 = v111->timer;
  struct StateT * v113 = v110->b;
  int v114 = v113->timer;
  bool v127 = v112 == v114;
  squared_assert(v127);
  squared_assume(v127);
  struct StateT * v117 = v110->a;
  int v118 = v117->timer;
  int v129 = v118 + 1;
  v117->timer = v129;
  struct StateT * v120 = v110->b;
  int v121 = v120->timer;
  int v131 = v121 + 1;
  v120->timer = v131;
  struct StateT2 * v123 = slot_4(v110);
  return v123;
}

struct StateT2 * snippet(struct StateT2 * v0) {
  struct StateT2 * v1 = slot_0(v0);
  return v1;
}

struct StateT2 * slot_10(struct StateT2 * v1761) {
  struct StateT * v1762 = v1761->a;
  int v1763 = v1762->timer;
  struct StateT * v1764 = v1761->b;
  int v1765 = v1764->timer;
  bool v1786 = v1763 == v1765;
  squared_assert(v1786);
  squared_assume(v1786);
  struct StateT * v1768 = v1761->a;
  int v1769 = v1768->timer;
  int v1788 = v1769 + 1;
  v1768->timer = v1788;
  struct StateT * v1771 = v1761->b;
  int v1772 = v1771->timer;
  int v1790 = v1772 + 1;
  v1771->timer = v1790;
  struct StateT * v1774 = v1761->a;
  int * v1775 = v1774->regs;
  int v1776 = v1775[6];
  int v1794 = v1776 + 4;
  v1775[6] = v1794;
  struct StateT * v1778 = v1761->b;
  int * v1779 = v1778->regs;
  int v1780 = v1779[6];
  int v1797 = v1780 + 4;
  v1779[6] = v1797;
  struct StateT2 * v1782 = slot_11(v1761);
  return v1782;
}

struct StateT2 * slot_1(struct StateT2 * v38) {
  struct StateT * v39 = v38->a;
  int v40 = v39->timer;
  struct StateT * v41 = v38->b;
  int v42 = v41->timer;
  bool v61 = v40 == v42;
  squared_assert(v61);
  squared_assume(v61);
  struct StateT * v45 = v38->a;
  int v46 = v45->timer;
  int v63 = v46 + 1;
  v45->timer = v63;
  struct StateT * v48 = v38->b;
  int v49 = v48->timer;
  int v65 = v49 + 1;
  v48->timer = v65;
  struct StateT * v51 = v38->a;
  int * v52 = v51->regs;
  v52[7] = 16;
  struct StateT * v54 = v38->b;
  int * v55 = v54->regs;
  v55[7] = 16;
  struct StateT2 * v57 = slot_2(v38);
  return v57;
}

struct StateT2 * slot_8(struct StateT2 * v707) {
  struct StateT * v708 = v707->a;
  int v709 = v708->timer;
  struct StateT * v710 = v707->b;
  int v711 = v710->timer;
  bool v1058 = v709 == v711;
  squared_assert(v1058);
  squared_assume(v1058);
  struct StateT * v714 = v707->a;
  int v715 = v714->timer;
  int v1060 = v715 + 1;
  v714->timer = v1060;
  struct StateT * v717 = v707->b;
  int v718 = v717->timer;
  int v1062 = v718 + 1;
  v717->timer = v1062;
  struct StateT * v720 = v707->a;
  int * v721 = v720->regs;
  int v722 = v721[6];
  int v723 = v721[5];
  int * v724 = v720->cache_tags;
  int v1068 = (((int)((unsigned int)((int)((unsigned int)v722 >> 2)) >> 1)) & 1) * 2;
  int v725 = v724[v1068];
  int v1069 = ((((int)((unsigned int)((int)((unsigned int)v722 >> 2)) >> 1)) & 1) * 2) + 1;
  int v726 = v724[v1069];
  int v1070 = 4 + ((((int)((unsigned int)((int)((unsigned int)v722 >> 2)) >> 1)) & 3) * 2);
  int v727 = v724[v1070];
  int v1071 = (4 + ((((int)((unsigned int)((int)((unsigned int)v722 >> 2)) >> 1)) & 3) * 2)) + 1;
  int v728 = v724[v1071];
  int v729 = v720->timer;
  int v1072 = v729 + ((100 ^ (((~(((v727 ^ ((int)((unsigned int)((int)((unsigned int)v722 >> 2)) >> 1))) | (-(v727 ^ ((int)((unsigned int)((int)((unsigned int)v722 >> 2)) >> 1))))) >> 31)) | (~(((v728 ^ ((int)((unsigned int)((int)((unsigned int)v722 >> 2)) >> 1))) | (-(v728 ^ ((int)((unsigned int)((int)((unsigned int)v722 >> 2)) >> 1))))) >> 31))) & 104)) ^ (((~(((v725 ^ ((int)((unsigned int)((int)((unsigned int)v722 >> 2)) >> 1))) | (-(v725 ^ ((int)((unsigned int)((int)((unsigned int)v722 >> 2)) >> 1))))) >> 31)) | (~(((v726 ^ ((int)((unsigned int)((int)((unsigned int)v722 >> 2)) >> 1))) | (-(v726 ^ ((int)((unsigned int)((int)((unsigned int)v722 >> 2)) >> 1))))) >> 31))) & (1 ^ (100 ^ (((~(((v727 ^ ((int)((unsigned int)((int)((unsigned int)v722 >> 2)) >> 1))) | (-(v727 ^ ((int)((unsigned int)((int)((unsigned int)v722 >> 2)) >> 1))))) >> 31)) | (~(((v728 ^ ((int)((unsigned int)((int)((unsigned int)v722 >> 2)) >> 1))) | (-(v728 ^ ((int)((unsigned int)((int)((unsigned int)v722 >> 2)) >> 1))))) >> 31))) & 104)))));
  v720->timer = v1072;
  bool v1073 = !(((~(((v725 ^ ((int)((unsigned int)((int)((unsigned int)v722 >> 2)) >> 1))) | (-(v725 ^ ((int)((unsigned int)((int)((unsigned int)v722 >> 2)) >> 1))))) >> 31)) | (~(((v726 ^ ((int)((unsigned int)((int)((unsigned int)v722 >> 2)) >> 1))) | (-(v726 ^ ((int)((unsigned int)((int)((unsigned int)v722 >> 2)) >> 1))))) >> 31))) == 0);
  int v823;
  if (v1073) {
    int * v731 = v720->cache_age;
    int v1075 = ((((int)((unsigned int)((int)((unsigned int)v722 >> 2)) >> 1)) & 1) * 2) + ((~(((v726 ^ ((int)((unsigned int)((int)((unsigned int)v722 >> 2)) >> 1))) | (-(v726 ^ ((int)((unsigned int)((int)((unsigned int)v722 >> 2)) >> 1))))) >> 31)) & 1);
    int v732 = v731[v1075];
    int v733 = v731[v1068];
    int v1076 = v733 + ((int)((unsigned int)(v733 - v732) >> 31));
    v731[v1068] = v1076;
    int * v735 = v720->cache_age;
    int v736 = v735[v1069];
    int v1078 = v736 + ((int)((unsigned int)(v736 - v732) >> 31));
    v735[v1069] = v1078;
    int * v738 = v720->cache_age;
    v738[v1075] = 0;
    v823 = v1075;
  } else {
    int * v741 = v720->cache_age;
    int v1082 = (((int)((unsigned int)((int)((unsigned int)v722 >> 2)) >> 1)) & 1) * 2;
    int v742 = v741[v1082];
    int * v743 = v720->cache_tags;
    int v744 = v743[v1082];
    int v745 = v741[v1069];
    int v746 = v743[v1069];
    bool v1084 = !(((~(((v727 ^ ((int)((unsigned int)((int)((unsigned int)v722 >> 2)) >> 1))) | (-(v727 ^ ((int)((unsigned int)((int)((unsigned int)v722 >> 2)) >> 1))))) >> 31)) | (~(((v728 ^ ((int)((unsigned int)((int)((unsigned int)v722 >> 2)) >> 1))) | (-(v728 ^ ((int)((unsigned int)((int)((unsigned int)v722 >> 2)) >> 1))))) >> 31))) == 0);
    int v800;
    if (v1084) {
      int * v747 = v720->cache_age;
      int v1086 = (4 + ((((int)((unsigned int)((int)((unsigned int)v722 >> 2)) >> 1)) & 3) * 2)) + ((~(((v728 ^ ((int)((unsigned int)((int)((unsigned int)v722 >> 2)) >> 1))) | (-(v728 ^ ((int)((unsigned int)((int)((unsigned int)v722 >> 2)) >> 1))))) >> 31)) & 1);
      int v748 = v747[v1086];
      int v749 = v747[v1070];
      int v1087 = v749 + ((int)((unsigned int)(v749 - v748) >> 31));
      v747[v1070] = v1087;
      int * v751 = v720->cache_age;
      int v752 = v751[v1071];
      int v1089 = v752 + ((int)((unsigned int)(v752 - v748) >> 31));
      v751[v1071] = v1089;
      int * v754 = v720->cache_age;
      v754[v1086] = 0;
      v800 = v1086;
    } else {
      int * v757 = v720->cache_age;
      int v1093 = 4 + ((((int)((unsigned int)((int)((unsigned int)v722 >> 2)) >> 1)) & 3) * 2);
      int v758 = v757[v1093];
      int * v759 = v720->cache_tags;
      int v760 = v759[v1093];
      int v761 = v757[v1071];
      int v762 = v759[v1071];
      int * v763 = v720->cache_dirty;
      int v1096 = (4 + ((((int)((unsigned int)((int)((unsigned int)v722 >> 2)) >> 1)) & 3) * 2)) + ((((v758 + ((~(((v760 ^ -1) | (-(v760 ^ -1))) >> 31)) & 2)) - (v761 + ((~(((v762 ^ -1) | (-(v762 ^ -1))) >> 31)) & 2))) >> 31) & 1);
      int v764 = v763[v1096];
      bool v1097 = !(v764 == 0);
      if (v1097) {
        int * v765 = v720->cache_tags;
        int v766 = v765[v1096];
        int * v767 = v720->cache_vals;
        int v1100 = ((4 + ((((int)((unsigned int)((int)((unsigned int)v722 >> 2)) >> 1)) & 3) * 2)) + ((((v758 + ((~(((v760 ^ -1) | (-(v760 ^ -1))) >> 31)) & 2)) - (v761 + ((~(((v762 ^ -1) | (-(v762 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
        int v768 = v767[v1100];
        int v1101 = (((4 + ((((int)((unsigned int)((int)((unsigned int)v722 >> 2)) >> 1)) & 3) * 2)) + ((((v758 + ((~(((v760 ^ -1) | (-(v760 ^ -1))) >> 31)) & 2)) - (v761 + ((~(((v762 ^ -1) | (-(v762 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
        int v769 = v767[v1101];
        int * v770 = v720->mem;
        int v1103 = v766 * 2;
        v770[v1103] = v768;
        int * v772 = v720->mem;
        int v1106 = (v766 * 2) + 1;
        v772[v1106] = v769;
        ;
      } else {
        ;
      }
      int * v777 = v720->mem;
      int v1111 = ((int)((unsigned int)((int)((unsigned int)v722 >> 2)) >> 1)) * 2;
      int v778 = v777[v1111];
      int v1112 = (((int)((unsigned int)((int)((unsigned int)v722 >> 2)) >> 1)) * 2) + 1;
      int v779 = v777[v1112];
      int * v780 = v720->cache_vals;
      int v1114 = ((4 + ((((int)((unsigned int)((int)((unsigned int)v722 >> 2)) >> 1)) & 3) * 2)) + ((((v758 + ((~(((v760 ^ -1) | (-(v760 ^ -1))) >> 31)) & 2)) - (v761 + ((~(((v762 ^ -1) | (-(v762 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
      v780[v1114] = v778;
      int * v782 = v720->cache_vals;
      int v1117 = (((4 + ((((int)((unsigned int)((int)((unsigned int)v722 >> 2)) >> 1)) & 3) * 2)) + ((((v758 + ((~(((v760 ^ -1) | (-(v760 ^ -1))) >> 31)) & 2)) - (v761 + ((~(((v762 ^ -1) | (-(v762 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
      v782[v1117] = v779;
      int * v784 = v720->cache_tags;
      int v1120 = (int)((unsigned int)((int)((unsigned int)v722 >> 2)) >> 1);
      v784[v1096] = v1120;
      int * v786 = v720->cache_dirty;
      v786[v1096] = 0;
      int * v788 = v720->cache_age;
      v788[v1096] = 1;
      int * v790 = v720->cache_age;
      int v791 = v790[v1096];
      int v792 = v790[v1070];
      int v1126 = v792 + ((int)((unsigned int)(v792 - v791) >> 31));
      v790[v1070] = v1126;
      int * v794 = v720->cache_age;
      int v795 = v794[v1071];
      int v1128 = v795 + ((int)((unsigned int)(v795 - v791) >> 31));
      v794[v1071] = v1128;
      int * v797 = v720->cache_age;
      v797[v1096] = 0;
      v800 = v1096;
    }
    int * v801 = v720->cache_vals;
    int v1131 = v800 * 2;
    int v802 = v801[v1131];
    int v1132 = (v800 * 2) + 1;
    int v803 = v801[v1132];
    int v1133 = (((((int)((unsigned int)((int)((unsigned int)v722 >> 2)) >> 1)) & 1) * 2) + ((((v742 + ((~(((v744 ^ -1) | (-(v744 ^ -1))) >> 31)) & 2)) - (v745 + ((~(((v746 ^ -1) | (-(v746 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
    v801[v1133] = v802;
    int * v805 = v720->cache_vals;
    int v1136 = ((((((int)((unsigned int)((int)((unsigned int)v722 >> 2)) >> 1)) & 1) * 2) + ((((v742 + ((~(((v744 ^ -1) | (-(v744 ^ -1))) >> 31)) & 2)) - (v745 + ((~(((v746 ^ -1) | (-(v746 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
    v805[v1136] = v803;
    int * v807 = v720->cache_tags;
    int v1139 = ((((int)((unsigned int)((int)((unsigned int)v722 >> 2)) >> 1)) & 1) * 2) + ((((v742 + ((~(((v744 ^ -1) | (-(v744 ^ -1))) >> 31)) & 2)) - (v745 + ((~(((v746 ^ -1) | (-(v746 ^ -1))) >> 31)) & 2))) >> 31) & 1);
    int v1140 = (int)((unsigned int)((int)((unsigned int)v722 >> 2)) >> 1);
    v807[v1139] = v1140;
    int * v809 = v720->cache_dirty;
    v809[v1139] = 0;
    int * v811 = v720->cache_age;
    v811[v1139] = 1;
    int * v813 = v720->cache_age;
    int v814 = v813[v1139];
    int v815 = v813[v1068];
    int v1146 = v815 + ((int)((unsigned int)(v815 - v814) >> 31));
    v813[v1068] = v1146;
    int * v817 = v720->cache_age;
    int v818 = v817[v1069];
    int v1148 = v818 + ((int)((unsigned int)(v818 - v814) >> 31));
    v817[v1069] = v1148;
    int * v820 = v720->cache_age;
    v820[v1139] = 0;
    v823 = v1139;
  }
  int * v824 = v720->cache_vals;
  int v1151 = (v823 * 2) + (((int)((unsigned int)v722 >> 2)) & 1);
  v824[v1151] = v723;
  int * v826 = v720->cache_tags;
  int v827 = v826[v1070];
  int v828 = v826[v1071];
  bool v1154 = !(((~(((v827 ^ ((int)((unsigned int)((int)((unsigned int)v722 >> 2)) >> 1))) | (-(v827 ^ ((int)((unsigned int)((int)((unsigned int)v722 >> 2)) >> 1))))) >> 31)) | (~(((v828 ^ ((int)((unsigned int)((int)((unsigned int)v722 >> 2)) >> 1))) | (-(v828 ^ ((int)((unsigned int)((int)((unsigned int)v722 >> 2)) >> 1))))) >> 31))) == 0);
  int v882;
  if (v1154) {
    int * v829 = v720->cache_age;
    int v1156 = (4 + ((((int)((unsigned int)((int)((unsigned int)v722 >> 2)) >> 1)) & 3) * 2)) + ((~(((v828 ^ ((int)((unsigned int)((int)((unsigned int)v722 >> 2)) >> 1))) | (-(v828 ^ ((int)((unsigned int)((int)((unsigned int)v722 >> 2)) >> 1))))) >> 31)) & 1);
    int v830 = v829[v1156];
    int v831 = v829[v1070];
    int v1157 = v831 + ((int)((unsigned int)(v831 - v830) >> 31));
    v829[v1070] = v1157;
    int * v833 = v720->cache_age;
    int v834 = v833[v1071];
    int v1159 = v834 + ((int)((unsigned int)(v834 - v830) >> 31));
    v833[v1071] = v1159;
    int * v836 = v720->cache_age;
    v836[v1156] = 0;
    v882 = v1156;
  } else {
    int * v839 = v720->cache_age;
    int v1163 = 4 + ((((int)((unsigned int)((int)((unsigned int)v722 >> 2)) >> 1)) & 3) * 2);
    int v840 = v839[v1163];
    int * v841 = v720->cache_tags;
    int v842 = v841[v1163];
    int v843 = v839[v1071];
    int v844 = v841[v1071];
    int * v845 = v720->cache_dirty;
    int v1166 = (4 + ((((int)((unsigned int)((int)((unsigned int)v722 >> 2)) >> 1)) & 3) * 2)) + ((((v840 + ((~(((v842 ^ -1) | (-(v842 ^ -1))) >> 31)) & 2)) - (v843 + ((~(((v844 ^ -1) | (-(v844 ^ -1))) >> 31)) & 2))) >> 31) & 1);
    int v846 = v845[v1166];
    bool v1167 = !(v846 == 0);
    if (v1167) {
      int * v847 = v720->cache_tags;
      int v848 = v847[v1166];
      int * v849 = v720->cache_vals;
      int v1170 = ((4 + ((((int)((unsigned int)((int)((unsigned int)v722 >> 2)) >> 1)) & 3) * 2)) + ((((v840 + ((~(((v842 ^ -1) | (-(v842 ^ -1))) >> 31)) & 2)) - (v843 + ((~(((v844 ^ -1) | (-(v844 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
      int v850 = v849[v1170];
      int v1171 = (((4 + ((((int)((unsigned int)((int)((unsigned int)v722 >> 2)) >> 1)) & 3) * 2)) + ((((v840 + ((~(((v842 ^ -1) | (-(v842 ^ -1))) >> 31)) & 2)) - (v843 + ((~(((v844 ^ -1) | (-(v844 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
      int v851 = v849[v1171];
      int * v852 = v720->mem;
      int v1173 = v848 * 2;
      v852[v1173] = v850;
      int * v854 = v720->mem;
      int v1176 = (v848 * 2) + 1;
      v854[v1176] = v851;
      ;
    } else {
      ;
    }
    int * v859 = v720->mem;
    int v1181 = ((int)((unsigned int)((int)((unsigned int)v722 >> 2)) >> 1)) * 2;
    int v860 = v859[v1181];
    int v1182 = (((int)((unsigned int)((int)((unsigned int)v722 >> 2)) >> 1)) * 2) + 1;
    int v861 = v859[v1182];
    int * v862 = v720->cache_vals;
    int v1184 = ((4 + ((((int)((unsigned int)((int)((unsigned int)v722 >> 2)) >> 1)) & 3) * 2)) + ((((v840 + ((~(((v842 ^ -1) | (-(v842 ^ -1))) >> 31)) & 2)) - (v843 + ((~(((v844 ^ -1) | (-(v844 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
    v862[v1184] = v860;
    int * v864 = v720->cache_vals;
    int v1187 = (((4 + ((((int)((unsigned int)((int)((unsigned int)v722 >> 2)) >> 1)) & 3) * 2)) + ((((v840 + ((~(((v842 ^ -1) | (-(v842 ^ -1))) >> 31)) & 2)) - (v843 + ((~(((v844 ^ -1) | (-(v844 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
    v864[v1187] = v861;
    int * v866 = v720->cache_tags;
    int v1190 = (int)((unsigned int)((int)((unsigned int)v722 >> 2)) >> 1);
    v866[v1166] = v1190;
    int * v868 = v720->cache_dirty;
    v868[v1166] = 0;
    int * v870 = v720->cache_age;
    v870[v1166] = 1;
    int * v872 = v720->cache_age;
    int v873 = v872[v1166];
    int v874 = v872[v1070];
    int v1196 = v874 + ((int)((unsigned int)(v874 - v873) >> 31));
    v872[v1070] = v1196;
    int * v876 = v720->cache_age;
    int v877 = v876[v1071];
    int v1198 = v877 + ((int)((unsigned int)(v877 - v873) >> 31));
    v876[v1071] = v1198;
    int * v879 = v720->cache_age;
    v879[v1166] = 0;
    v882 = v1166;
  }
  int * v883 = v720->cache_vals;
  int v1201 = (v882 * 2) + (((int)((unsigned int)v722 >> 2)) & 1);
  v883[v1201] = v723;
  int * v885 = v720->cache_dirty;
  v885[v882] = 1;
  struct StateT * v887 = v707->b;
  int * v888 = v887->regs;
  int v889 = v888[6];
  int v890 = v888[5];
  int * v891 = v887->cache_tags;
  int v1208 = (((int)((unsigned int)((int)((unsigned int)v889 >> 2)) >> 1)) & 1) * 2;
  int v892 = v891[v1208];
  int v1209 = ((((int)((unsigned int)((int)((unsigned int)v889 >> 2)) >> 1)) & 1) * 2) + 1;
  int v893 = v891[v1209];
  int v1210 = 4 + ((((int)((unsigned int)((int)((unsigned int)v889 >> 2)) >> 1)) & 3) * 2);
  int v894 = v891[v1210];
  int v1211 = (4 + ((((int)((unsigned int)((int)((unsigned int)v889 >> 2)) >> 1)) & 3) * 2)) + 1;
  int v895 = v891[v1211];
  int v896 = v887->timer;
  int v1212 = v896 + ((100 ^ (((~(((v894 ^ ((int)((unsigned int)((int)((unsigned int)v889 >> 2)) >> 1))) | (-(v894 ^ ((int)((unsigned int)((int)((unsigned int)v889 >> 2)) >> 1))))) >> 31)) | (~(((v895 ^ ((int)((unsigned int)((int)((unsigned int)v889 >> 2)) >> 1))) | (-(v895 ^ ((int)((unsigned int)((int)((unsigned int)v889 >> 2)) >> 1))))) >> 31))) & 104)) ^ (((~(((v892 ^ ((int)((unsigned int)((int)((unsigned int)v889 >> 2)) >> 1))) | (-(v892 ^ ((int)((unsigned int)((int)((unsigned int)v889 >> 2)) >> 1))))) >> 31)) | (~(((v893 ^ ((int)((unsigned int)((int)((unsigned int)v889 >> 2)) >> 1))) | (-(v893 ^ ((int)((unsigned int)((int)((unsigned int)v889 >> 2)) >> 1))))) >> 31))) & (1 ^ (100 ^ (((~(((v894 ^ ((int)((unsigned int)((int)((unsigned int)v889 >> 2)) >> 1))) | (-(v894 ^ ((int)((unsigned int)((int)((unsigned int)v889 >> 2)) >> 1))))) >> 31)) | (~(((v895 ^ ((int)((unsigned int)((int)((unsigned int)v889 >> 2)) >> 1))) | (-(v895 ^ ((int)((unsigned int)((int)((unsigned int)v889 >> 2)) >> 1))))) >> 31))) & 104)))));
  v887->timer = v1212;
  bool v1213 = !(((~(((v892 ^ ((int)((unsigned int)((int)((unsigned int)v889 >> 2)) >> 1))) | (-(v892 ^ ((int)((unsigned int)((int)((unsigned int)v889 >> 2)) >> 1))))) >> 31)) | (~(((v893 ^ ((int)((unsigned int)((int)((unsigned int)v889 >> 2)) >> 1))) | (-(v893 ^ ((int)((unsigned int)((int)((unsigned int)v889 >> 2)) >> 1))))) >> 31))) == 0);
  int v990;
  if (v1213) {
    int * v898 = v887->cache_age;
    int v1215 = ((((int)((unsigned int)((int)((unsigned int)v889 >> 2)) >> 1)) & 1) * 2) + ((~(((v893 ^ ((int)((unsigned int)((int)((unsigned int)v889 >> 2)) >> 1))) | (-(v893 ^ ((int)((unsigned int)((int)((unsigned int)v889 >> 2)) >> 1))))) >> 31)) & 1);
    int v899 = v898[v1215];
    int v900 = v898[v1208];
    int v1216 = v900 + ((int)((unsigned int)(v900 - v899) >> 31));
    v898[v1208] = v1216;
    int * v902 = v887->cache_age;
    int v903 = v902[v1209];
    int v1218 = v903 + ((int)((unsigned int)(v903 - v899) >> 31));
    v902[v1209] = v1218;
    int * v905 = v887->cache_age;
    v905[v1215] = 0;
    v990 = v1215;
  } else {
    int * v908 = v887->cache_age;
    int v1222 = (((int)((unsigned int)((int)((unsigned int)v889 >> 2)) >> 1)) & 1) * 2;
    int v909 = v908[v1222];
    int * v910 = v887->cache_tags;
    int v911 = v910[v1222];
    int v912 = v908[v1209];
    int v913 = v910[v1209];
    bool v1224 = !(((~(((v894 ^ ((int)((unsigned int)((int)((unsigned int)v889 >> 2)) >> 1))) | (-(v894 ^ ((int)((unsigned int)((int)((unsigned int)v889 >> 2)) >> 1))))) >> 31)) | (~(((v895 ^ ((int)((unsigned int)((int)((unsigned int)v889 >> 2)) >> 1))) | (-(v895 ^ ((int)((unsigned int)((int)((unsigned int)v889 >> 2)) >> 1))))) >> 31))) == 0);
    int v967;
    if (v1224) {
      int * v914 = v887->cache_age;
      int v1226 = (4 + ((((int)((unsigned int)((int)((unsigned int)v889 >> 2)) >> 1)) & 3) * 2)) + ((~(((v895 ^ ((int)((unsigned int)((int)((unsigned int)v889 >> 2)) >> 1))) | (-(v895 ^ ((int)((unsigned int)((int)((unsigned int)v889 >> 2)) >> 1))))) >> 31)) & 1);
      int v915 = v914[v1226];
      int v916 = v914[v1210];
      int v1227 = v916 + ((int)((unsigned int)(v916 - v915) >> 31));
      v914[v1210] = v1227;
      int * v918 = v887->cache_age;
      int v919 = v918[v1211];
      int v1229 = v919 + ((int)((unsigned int)(v919 - v915) >> 31));
      v918[v1211] = v1229;
      int * v921 = v887->cache_age;
      v921[v1226] = 0;
      v967 = v1226;
    } else {
      int * v924 = v887->cache_age;
      int v1233 = 4 + ((((int)((unsigned int)((int)((unsigned int)v889 >> 2)) >> 1)) & 3) * 2);
      int v925 = v924[v1233];
      int * v926 = v887->cache_tags;
      int v927 = v926[v1233];
      int v928 = v924[v1211];
      int v929 = v926[v1211];
      int * v930 = v887->cache_dirty;
      int v1236 = (4 + ((((int)((unsigned int)((int)((unsigned int)v889 >> 2)) >> 1)) & 3) * 2)) + ((((v925 + ((~(((v927 ^ -1) | (-(v927 ^ -1))) >> 31)) & 2)) - (v928 + ((~(((v929 ^ -1) | (-(v929 ^ -1))) >> 31)) & 2))) >> 31) & 1);
      int v931 = v930[v1236];
      bool v1237 = !(v931 == 0);
      if (v1237) {
        int * v932 = v887->cache_tags;
        int v933 = v932[v1236];
        int * v934 = v887->cache_vals;
        int v1240 = ((4 + ((((int)((unsigned int)((int)((unsigned int)v889 >> 2)) >> 1)) & 3) * 2)) + ((((v925 + ((~(((v927 ^ -1) | (-(v927 ^ -1))) >> 31)) & 2)) - (v928 + ((~(((v929 ^ -1) | (-(v929 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
        int v935 = v934[v1240];
        int v1241 = (((4 + ((((int)((unsigned int)((int)((unsigned int)v889 >> 2)) >> 1)) & 3) * 2)) + ((((v925 + ((~(((v927 ^ -1) | (-(v927 ^ -1))) >> 31)) & 2)) - (v928 + ((~(((v929 ^ -1) | (-(v929 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
        int v936 = v934[v1241];
        int * v937 = v887->mem;
        int v1243 = v933 * 2;
        v937[v1243] = v935;
        int * v939 = v887->mem;
        int v1246 = (v933 * 2) + 1;
        v939[v1246] = v936;
        ;
      } else {
        ;
      }
      int * v944 = v887->mem;
      int v1251 = ((int)((unsigned int)((int)((unsigned int)v889 >> 2)) >> 1)) * 2;
      int v945 = v944[v1251];
      int v1252 = (((int)((unsigned int)((int)((unsigned int)v889 >> 2)) >> 1)) * 2) + 1;
      int v946 = v944[v1252];
      int * v947 = v887->cache_vals;
      int v1254 = ((4 + ((((int)((unsigned int)((int)((unsigned int)v889 >> 2)) >> 1)) & 3) * 2)) + ((((v925 + ((~(((v927 ^ -1) | (-(v927 ^ -1))) >> 31)) & 2)) - (v928 + ((~(((v929 ^ -1) | (-(v929 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
      v947[v1254] = v945;
      int * v949 = v887->cache_vals;
      int v1257 = (((4 + ((((int)((unsigned int)((int)((unsigned int)v889 >> 2)) >> 1)) & 3) * 2)) + ((((v925 + ((~(((v927 ^ -1) | (-(v927 ^ -1))) >> 31)) & 2)) - (v928 + ((~(((v929 ^ -1) | (-(v929 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
      v949[v1257] = v946;
      int * v951 = v887->cache_tags;
      int v1260 = (int)((unsigned int)((int)((unsigned int)v889 >> 2)) >> 1);
      v951[v1236] = v1260;
      int * v953 = v887->cache_dirty;
      v953[v1236] = 0;
      int * v955 = v887->cache_age;
      v955[v1236] = 1;
      int * v957 = v887->cache_age;
      int v958 = v957[v1236];
      int v959 = v957[v1210];
      int v1265 = v959 + ((int)((unsigned int)(v959 - v958) >> 31));
      v957[v1210] = v1265;
      int * v961 = v887->cache_age;
      int v962 = v961[v1211];
      int v1267 = v962 + ((int)((unsigned int)(v962 - v958) >> 31));
      v961[v1211] = v1267;
      int * v964 = v887->cache_age;
      v964[v1236] = 0;
      v967 = v1236;
    }
    int * v968 = v887->cache_vals;
    int v1270 = v967 * 2;
    int v969 = v968[v1270];
    int v1271 = (v967 * 2) + 1;
    int v970 = v968[v1271];
    int v1272 = (((((int)((unsigned int)((int)((unsigned int)v889 >> 2)) >> 1)) & 1) * 2) + ((((v909 + ((~(((v911 ^ -1) | (-(v911 ^ -1))) >> 31)) & 2)) - (v912 + ((~(((v913 ^ -1) | (-(v913 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
    v968[v1272] = v969;
    int * v972 = v887->cache_vals;
    int v1275 = ((((((int)((unsigned int)((int)((unsigned int)v889 >> 2)) >> 1)) & 1) * 2) + ((((v909 + ((~(((v911 ^ -1) | (-(v911 ^ -1))) >> 31)) & 2)) - (v912 + ((~(((v913 ^ -1) | (-(v913 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
    v972[v1275] = v970;
    int * v974 = v887->cache_tags;
    int v1278 = ((((int)((unsigned int)((int)((unsigned int)v889 >> 2)) >> 1)) & 1) * 2) + ((((v909 + ((~(((v911 ^ -1) | (-(v911 ^ -1))) >> 31)) & 2)) - (v912 + ((~(((v913 ^ -1) | (-(v913 ^ -1))) >> 31)) & 2))) >> 31) & 1);
    int v1279 = (int)((unsigned int)((int)((unsigned int)v889 >> 2)) >> 1);
    v974[v1278] = v1279;
    int * v976 = v887->cache_dirty;
    v976[v1278] = 0;
    int * v978 = v887->cache_age;
    v978[v1278] = 1;
    int * v980 = v887->cache_age;
    int v981 = v980[v1278];
    int v982 = v980[v1208];
    int v1284 = v982 + ((int)((unsigned int)(v982 - v981) >> 31));
    v980[v1208] = v1284;
    int * v984 = v887->cache_age;
    int v985 = v984[v1209];
    int v1286 = v985 + ((int)((unsigned int)(v985 - v981) >> 31));
    v984[v1209] = v1286;
    int * v987 = v887->cache_age;
    v987[v1278] = 0;
    v990 = v1278;
  }
  int * v991 = v887->cache_vals;
  int v1289 = (v990 * 2) + (((int)((unsigned int)v889 >> 2)) & 1);
  v991[v1289] = v890;
  int * v993 = v887->cache_tags;
  int v994 = v993[v1210];
  int v995 = v993[v1211];
  bool v1292 = !(((~(((v994 ^ ((int)((unsigned int)((int)((unsigned int)v889 >> 2)) >> 1))) | (-(v994 ^ ((int)((unsigned int)((int)((unsigned int)v889 >> 2)) >> 1))))) >> 31)) | (~(((v995 ^ ((int)((unsigned int)((int)((unsigned int)v889 >> 2)) >> 1))) | (-(v995 ^ ((int)((unsigned int)((int)((unsigned int)v889 >> 2)) >> 1))))) >> 31))) == 0);
  int v1049;
  if (v1292) {
    int * v996 = v887->cache_age;
    int v1294 = (4 + ((((int)((unsigned int)((int)((unsigned int)v889 >> 2)) >> 1)) & 3) * 2)) + ((~(((v995 ^ ((int)((unsigned int)((int)((unsigned int)v889 >> 2)) >> 1))) | (-(v995 ^ ((int)((unsigned int)((int)((unsigned int)v889 >> 2)) >> 1))))) >> 31)) & 1);
    int v997 = v996[v1294];
    int v998 = v996[v1210];
    int v1295 = v998 + ((int)((unsigned int)(v998 - v997) >> 31));
    v996[v1210] = v1295;
    int * v1000 = v887->cache_age;
    int v1001 = v1000[v1211];
    int v1297 = v1001 + ((int)((unsigned int)(v1001 - v997) >> 31));
    v1000[v1211] = v1297;
    int * v1003 = v887->cache_age;
    v1003[v1294] = 0;
    v1049 = v1294;
  } else {
    int * v1006 = v887->cache_age;
    int v1301 = 4 + ((((int)((unsigned int)((int)((unsigned int)v889 >> 2)) >> 1)) & 3) * 2);
    int v1007 = v1006[v1301];
    int * v1008 = v887->cache_tags;
    int v1009 = v1008[v1301];
    int v1010 = v1006[v1211];
    int v1011 = v1008[v1211];
    int * v1012 = v887->cache_dirty;
    int v1304 = (4 + ((((int)((unsigned int)((int)((unsigned int)v889 >> 2)) >> 1)) & 3) * 2)) + ((((v1007 + ((~(((v1009 ^ -1) | (-(v1009 ^ -1))) >> 31)) & 2)) - (v1010 + ((~(((v1011 ^ -1) | (-(v1011 ^ -1))) >> 31)) & 2))) >> 31) & 1);
    int v1013 = v1012[v1304];
    bool v1305 = !(v1013 == 0);
    if (v1305) {
      int * v1014 = v887->cache_tags;
      int v1015 = v1014[v1304];
      int * v1016 = v887->cache_vals;
      int v1308 = ((4 + ((((int)((unsigned int)((int)((unsigned int)v889 >> 2)) >> 1)) & 3) * 2)) + ((((v1007 + ((~(((v1009 ^ -1) | (-(v1009 ^ -1))) >> 31)) & 2)) - (v1010 + ((~(((v1011 ^ -1) | (-(v1011 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
      int v1017 = v1016[v1308];
      int v1309 = (((4 + ((((int)((unsigned int)((int)((unsigned int)v889 >> 2)) >> 1)) & 3) * 2)) + ((((v1007 + ((~(((v1009 ^ -1) | (-(v1009 ^ -1))) >> 31)) & 2)) - (v1010 + ((~(((v1011 ^ -1) | (-(v1011 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
      int v1018 = v1016[v1309];
      int * v1019 = v887->mem;
      int v1311 = v1015 * 2;
      v1019[v1311] = v1017;
      int * v1021 = v887->mem;
      int v1314 = (v1015 * 2) + 1;
      v1021[v1314] = v1018;
      ;
    } else {
      ;
    }
    int * v1026 = v887->mem;
    int v1319 = ((int)((unsigned int)((int)((unsigned int)v889 >> 2)) >> 1)) * 2;
    int v1027 = v1026[v1319];
    int v1320 = (((int)((unsigned int)((int)((unsigned int)v889 >> 2)) >> 1)) * 2) + 1;
    int v1028 = v1026[v1320];
    int * v1029 = v887->cache_vals;
    int v1322 = ((4 + ((((int)((unsigned int)((int)((unsigned int)v889 >> 2)) >> 1)) & 3) * 2)) + ((((v1007 + ((~(((v1009 ^ -1) | (-(v1009 ^ -1))) >> 31)) & 2)) - (v1010 + ((~(((v1011 ^ -1) | (-(v1011 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
    v1029[v1322] = v1027;
    int * v1031 = v887->cache_vals;
    int v1325 = (((4 + ((((int)((unsigned int)((int)((unsigned int)v889 >> 2)) >> 1)) & 3) * 2)) + ((((v1007 + ((~(((v1009 ^ -1) | (-(v1009 ^ -1))) >> 31)) & 2)) - (v1010 + ((~(((v1011 ^ -1) | (-(v1011 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
    v1031[v1325] = v1028;
    int * v1033 = v887->cache_tags;
    int v1328 = (int)((unsigned int)((int)((unsigned int)v889 >> 2)) >> 1);
    v1033[v1304] = v1328;
    int * v1035 = v887->cache_dirty;
    v1035[v1304] = 0;
    int * v1037 = v887->cache_age;
    v1037[v1304] = 1;
    int * v1039 = v887->cache_age;
    int v1040 = v1039[v1304];
    int v1041 = v1039[v1210];
    int v1333 = v1041 + ((int)((unsigned int)(v1041 - v1040) >> 31));
    v1039[v1210] = v1333;
    int * v1043 = v887->cache_age;
    int v1044 = v1043[v1211];
    int v1335 = v1044 + ((int)((unsigned int)(v1044 - v1040) >> 31));
    v1043[v1211] = v1335;
    int * v1046 = v887->cache_age;
    v1046[v1304] = 0;
    v1049 = v1304;
  }
  int * v1050 = v887->cache_vals;
  int v1338 = (v1049 * 2) + (((int)((unsigned int)v889 >> 2)) & 1);
  v1050[v1338] = v890;
  int * v1052 = v887->cache_dirty;
  v1052[v1049] = 1;
  struct StateT2 * v1054 = slot_9(v707);
  return v1054;
}

struct StateT2 * slot_4(struct StateT2 * v134) {
  struct StateT * v135 = v134->a;
  int v136 = v135->timer;
  struct StateT * v137 = v134->b;
  int v138 = v137->timer;
  bool v171 = v136 == v138;
  squared_assert(v171);
  squared_assume(v171);
  struct StateT * v141 = v134->a;
  int * v142 = v141->saved_regs;
  int * v143 = v141->regs;
  int v144 = v143[8];
  v142[8] = v144;
  struct StateT * v146 = v134->b;
  int * v147 = v146->saved_regs;
  int * v148 = v146->regs;
  int v149 = v148[8];
  v147[8] = v149;
  struct StateT * v151 = v134->a;
  int v152 = v151->timer;
  int v182 = v152 + 1;
  v151->timer = v182;
  struct StateT * v154 = v134->b;
  int v155 = v154->timer;
  int v184 = v155 + 1;
  v154->timer = v184;
  struct StateT * v157 = v134->a;
  int * v158 = v157->regs;
  int v159 = v158[9];
  int v160 = v158[6];
  int v189 = v159 + v160;
  v158[8] = v189;
  struct StateT * v162 = v134->b;
  int * v163 = v162->regs;
  int v164 = v163[9];
  int v165 = v163[6];
  int v192 = v164 + v165;
  v163[8] = v192;
  struct StateT2 * v167 = slot_5(v134);
  return v167;
}

struct StateT2 * slot_9(struct StateT2 * v1343) {
  struct StateT * v1344 = v1343->a;
  int v1345 = v1344->timer;
  struct StateT * v1346 = v1343->b;
  int v1347 = v1346->timer;
  bool v1574 = v1345 == v1347;
  squared_assert(v1574);
  squared_assume(v1574);
  struct StateT * v1350 = v1343->a;
  int v1351 = v1350->timer;
  int v1576 = v1351 + 1;
  v1350->timer = v1576;
  struct StateT * v1353 = v1343->b;
  int v1354 = v1353->timer;
  int v1578 = v1354 + 1;
  v1353->timer = v1578;
  struct StateT * v1356 = v1343->a;
  int * v1357 = v1356->regs;
  int v1358 = v1357[6];
  int * v1359 = v1356->cache_tags;
  int v1583 = (((int)((unsigned int)((int)((unsigned int)v1358 >> 2)) >> 1)) & 1) * 2;
  int v1360 = v1359[v1583];
  int v1584 = ((((int)((unsigned int)((int)((unsigned int)v1358 >> 2)) >> 1)) & 1) * 2) + 1;
  int v1361 = v1359[v1584];
  int v1585 = 4 + ((((int)((unsigned int)((int)((unsigned int)v1358 >> 2)) >> 1)) & 3) * 2);
  int v1362 = v1359[v1585];
  int v1586 = (4 + ((((int)((unsigned int)((int)((unsigned int)v1358 >> 2)) >> 1)) & 3) * 2)) + 1;
  int v1363 = v1359[v1586];
  int v1364 = v1356->timer;
  int v1587 = v1364 + ((100 ^ (((~(((v1362 ^ ((int)((unsigned int)((int)((unsigned int)v1358 >> 2)) >> 1))) | (-(v1362 ^ ((int)((unsigned int)((int)((unsigned int)v1358 >> 2)) >> 1))))) >> 31)) | (~(((v1363 ^ ((int)((unsigned int)((int)((unsigned int)v1358 >> 2)) >> 1))) | (-(v1363 ^ ((int)((unsigned int)((int)((unsigned int)v1358 >> 2)) >> 1))))) >> 31))) & 104)) ^ (((~(((v1360 ^ ((int)((unsigned int)((int)((unsigned int)v1358 >> 2)) >> 1))) | (-(v1360 ^ ((int)((unsigned int)((int)((unsigned int)v1358 >> 2)) >> 1))))) >> 31)) | (~(((v1361 ^ ((int)((unsigned int)((int)((unsigned int)v1358 >> 2)) >> 1))) | (-(v1361 ^ ((int)((unsigned int)((int)((unsigned int)v1358 >> 2)) >> 1))))) >> 31))) & (1 ^ (100 ^ (((~(((v1362 ^ ((int)((unsigned int)((int)((unsigned int)v1358 >> 2)) >> 1))) | (-(v1362 ^ ((int)((unsigned int)((int)((unsigned int)v1358 >> 2)) >> 1))))) >> 31)) | (~(((v1363 ^ ((int)((unsigned int)((int)((unsigned int)v1358 >> 2)) >> 1))) | (-(v1363 ^ ((int)((unsigned int)((int)((unsigned int)v1358 >> 2)) >> 1))))) >> 31))) & 104)))));
  v1356->timer = v1587;
  int * v1366 = v1356->cache_vals;
  bool v1588 = !(((~(((v1360 ^ ((int)((unsigned int)((int)((unsigned int)v1358 >> 2)) >> 1))) | (-(v1360 ^ ((int)((unsigned int)((int)((unsigned int)v1358 >> 2)) >> 1))))) >> 31)) | (~(((v1361 ^ ((int)((unsigned int)((int)((unsigned int)v1358 >> 2)) >> 1))) | (-(v1361 ^ ((int)((unsigned int)((int)((unsigned int)v1358 >> 2)) >> 1))))) >> 31))) == 0);
  int v1459;
  if (v1588) {
    int * v1367 = v1356->cache_age;
    int v1590 = ((((int)((unsigned int)((int)((unsigned int)v1358 >> 2)) >> 1)) & 1) * 2) + ((~(((v1361 ^ ((int)((unsigned int)((int)((unsigned int)v1358 >> 2)) >> 1))) | (-(v1361 ^ ((int)((unsigned int)((int)((unsigned int)v1358 >> 2)) >> 1))))) >> 31)) & 1);
    int v1368 = v1367[v1590];
    int v1369 = v1367[v1583];
    int v1591 = v1369 + ((int)((unsigned int)(v1369 - v1368) >> 31));
    v1367[v1583] = v1591;
    int * v1371 = v1356->cache_age;
    int v1372 = v1371[v1584];
    int v1593 = v1372 + ((int)((unsigned int)(v1372 - v1368) >> 31));
    v1371[v1584] = v1593;
    int * v1374 = v1356->cache_age;
    v1374[v1590] = 0;
    v1459 = v1590;
  } else {
    int * v1377 = v1356->cache_age;
    int v1597 = (((int)((unsigned int)((int)((unsigned int)v1358 >> 2)) >> 1)) & 1) * 2;
    int v1378 = v1377[v1597];
    int * v1379 = v1356->cache_tags;
    int v1380 = v1379[v1597];
    int v1381 = v1377[v1584];
    int v1382 = v1379[v1584];
    bool v1599 = !(((~(((v1362 ^ ((int)((unsigned int)((int)((unsigned int)v1358 >> 2)) >> 1))) | (-(v1362 ^ ((int)((unsigned int)((int)((unsigned int)v1358 >> 2)) >> 1))))) >> 31)) | (~(((v1363 ^ ((int)((unsigned int)((int)((unsigned int)v1358 >> 2)) >> 1))) | (-(v1363 ^ ((int)((unsigned int)((int)((unsigned int)v1358 >> 2)) >> 1))))) >> 31))) == 0);
    int v1436;
    if (v1599) {
      int * v1383 = v1356->cache_age;
      int v1601 = (4 + ((((int)((unsigned int)((int)((unsigned int)v1358 >> 2)) >> 1)) & 3) * 2)) + ((~(((v1363 ^ ((int)((unsigned int)((int)((unsigned int)v1358 >> 2)) >> 1))) | (-(v1363 ^ ((int)((unsigned int)((int)((unsigned int)v1358 >> 2)) >> 1))))) >> 31)) & 1);
      int v1384 = v1383[v1601];
      int v1385 = v1383[v1585];
      int v1602 = v1385 + ((int)((unsigned int)(v1385 - v1384) >> 31));
      v1383[v1585] = v1602;
      int * v1387 = v1356->cache_age;
      int v1388 = v1387[v1586];
      int v1604 = v1388 + ((int)((unsigned int)(v1388 - v1384) >> 31));
      v1387[v1586] = v1604;
      int * v1390 = v1356->cache_age;
      v1390[v1601] = 0;
      v1436 = v1601;
    } else {
      int * v1393 = v1356->cache_age;
      int v1608 = 4 + ((((int)((unsigned int)((int)((unsigned int)v1358 >> 2)) >> 1)) & 3) * 2);
      int v1394 = v1393[v1608];
      int * v1395 = v1356->cache_tags;
      int v1396 = v1395[v1608];
      int v1397 = v1393[v1586];
      int v1398 = v1395[v1586];
      int * v1399 = v1356->cache_dirty;
      int v1611 = (4 + ((((int)((unsigned int)((int)((unsigned int)v1358 >> 2)) >> 1)) & 3) * 2)) + ((((v1394 + ((~(((v1396 ^ -1) | (-(v1396 ^ -1))) >> 31)) & 2)) - (v1397 + ((~(((v1398 ^ -1) | (-(v1398 ^ -1))) >> 31)) & 2))) >> 31) & 1);
      int v1400 = v1399[v1611];
      bool v1612 = !(v1400 == 0);
      if (v1612) {
        int * v1401 = v1356->cache_tags;
        int v1402 = v1401[v1611];
        int * v1403 = v1356->cache_vals;
        int v1615 = ((4 + ((((int)((unsigned int)((int)((unsigned int)v1358 >> 2)) >> 1)) & 3) * 2)) + ((((v1394 + ((~(((v1396 ^ -1) | (-(v1396 ^ -1))) >> 31)) & 2)) - (v1397 + ((~(((v1398 ^ -1) | (-(v1398 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
        int v1404 = v1403[v1615];
        int v1616 = (((4 + ((((int)((unsigned int)((int)((unsigned int)v1358 >> 2)) >> 1)) & 3) * 2)) + ((((v1394 + ((~(((v1396 ^ -1) | (-(v1396 ^ -1))) >> 31)) & 2)) - (v1397 + ((~(((v1398 ^ -1) | (-(v1398 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
        int v1405 = v1403[v1616];
        int * v1406 = v1356->mem;
        int v1618 = v1402 * 2;
        v1406[v1618] = v1404;
        int * v1408 = v1356->mem;
        int v1621 = (v1402 * 2) + 1;
        v1408[v1621] = v1405;
        ;
      } else {
        ;
      }
      int * v1413 = v1356->mem;
      int v1626 = ((int)((unsigned int)((int)((unsigned int)v1358 >> 2)) >> 1)) * 2;
      int v1414 = v1413[v1626];
      int v1627 = (((int)((unsigned int)((int)((unsigned int)v1358 >> 2)) >> 1)) * 2) + 1;
      int v1415 = v1413[v1627];
      int * v1416 = v1356->cache_vals;
      int v1629 = ((4 + ((((int)((unsigned int)((int)((unsigned int)v1358 >> 2)) >> 1)) & 3) * 2)) + ((((v1394 + ((~(((v1396 ^ -1) | (-(v1396 ^ -1))) >> 31)) & 2)) - (v1397 + ((~(((v1398 ^ -1) | (-(v1398 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
      v1416[v1629] = v1414;
      int * v1418 = v1356->cache_vals;
      int v1632 = (((4 + ((((int)((unsigned int)((int)((unsigned int)v1358 >> 2)) >> 1)) & 3) * 2)) + ((((v1394 + ((~(((v1396 ^ -1) | (-(v1396 ^ -1))) >> 31)) & 2)) - (v1397 + ((~(((v1398 ^ -1) | (-(v1398 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
      v1418[v1632] = v1415;
      int * v1420 = v1356->cache_tags;
      int v1635 = (int)((unsigned int)((int)((unsigned int)v1358 >> 2)) >> 1);
      v1420[v1611] = v1635;
      int * v1422 = v1356->cache_dirty;
      v1422[v1611] = 0;
      int * v1424 = v1356->cache_age;
      v1424[v1611] = 1;
      int * v1426 = v1356->cache_age;
      int v1427 = v1426[v1611];
      int v1428 = v1426[v1585];
      int v1641 = v1428 + ((int)((unsigned int)(v1428 - v1427) >> 31));
      v1426[v1585] = v1641;
      int * v1430 = v1356->cache_age;
      int v1431 = v1430[v1586];
      int v1643 = v1431 + ((int)((unsigned int)(v1431 - v1427) >> 31));
      v1430[v1586] = v1643;
      int * v1433 = v1356->cache_age;
      v1433[v1611] = 0;
      v1436 = v1611;
    }
    int * v1437 = v1356->cache_vals;
    int v1646 = v1436 * 2;
    int v1438 = v1437[v1646];
    int v1647 = (v1436 * 2) + 1;
    int v1439 = v1437[v1647];
    int v1648 = (((((int)((unsigned int)((int)((unsigned int)v1358 >> 2)) >> 1)) & 1) * 2) + ((((v1378 + ((~(((v1380 ^ -1) | (-(v1380 ^ -1))) >> 31)) & 2)) - (v1381 + ((~(((v1382 ^ -1) | (-(v1382 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
    v1437[v1648] = v1438;
    int * v1441 = v1356->cache_vals;
    int v1651 = ((((((int)((unsigned int)((int)((unsigned int)v1358 >> 2)) >> 1)) & 1) * 2) + ((((v1378 + ((~(((v1380 ^ -1) | (-(v1380 ^ -1))) >> 31)) & 2)) - (v1381 + ((~(((v1382 ^ -1) | (-(v1382 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
    v1441[v1651] = v1439;
    int * v1443 = v1356->cache_tags;
    int v1654 = ((((int)((unsigned int)((int)((unsigned int)v1358 >> 2)) >> 1)) & 1) * 2) + ((((v1378 + ((~(((v1380 ^ -1) | (-(v1380 ^ -1))) >> 31)) & 2)) - (v1381 + ((~(((v1382 ^ -1) | (-(v1382 ^ -1))) >> 31)) & 2))) >> 31) & 1);
    int v1655 = (int)((unsigned int)((int)((unsigned int)v1358 >> 2)) >> 1);
    v1443[v1654] = v1655;
    int * v1445 = v1356->cache_dirty;
    v1445[v1654] = 0;
    int * v1447 = v1356->cache_age;
    v1447[v1654] = 1;
    int * v1449 = v1356->cache_age;
    int v1450 = v1449[v1654];
    int v1451 = v1449[v1583];
    int v1661 = v1451 + ((int)((unsigned int)(v1451 - v1450) >> 31));
    v1449[v1583] = v1661;
    int * v1453 = v1356->cache_age;
    int v1454 = v1453[v1584];
    int v1663 = v1454 + ((int)((unsigned int)(v1454 - v1450) >> 31));
    v1453[v1584] = v1663;
    int * v1456 = v1356->cache_age;
    v1456[v1654] = 0;
    v1459 = v1654;
  }
  int v1666 = (v1459 * 2) + (((int)((unsigned int)v1358 >> 2)) & 1);
  int v1460 = v1366[v1666];
  int * v1461 = v1356->regs;
  v1461[11] = v1460;
  struct StateT * v1463 = v1343->b;
  int * v1464 = v1463->regs;
  int v1465 = v1464[6];
  int * v1466 = v1463->cache_tags;
  int v1673 = (((int)((unsigned int)((int)((unsigned int)v1465 >> 2)) >> 1)) & 1) * 2;
  int v1467 = v1466[v1673];
  int v1674 = ((((int)((unsigned int)((int)((unsigned int)v1465 >> 2)) >> 1)) & 1) * 2) + 1;
  int v1468 = v1466[v1674];
  int v1675 = 4 + ((((int)((unsigned int)((int)((unsigned int)v1465 >> 2)) >> 1)) & 3) * 2);
  int v1469 = v1466[v1675];
  int v1676 = (4 + ((((int)((unsigned int)((int)((unsigned int)v1465 >> 2)) >> 1)) & 3) * 2)) + 1;
  int v1470 = v1466[v1676];
  int v1471 = v1463->timer;
  int v1677 = v1471 + ((100 ^ (((~(((v1469 ^ ((int)((unsigned int)((int)((unsigned int)v1465 >> 2)) >> 1))) | (-(v1469 ^ ((int)((unsigned int)((int)((unsigned int)v1465 >> 2)) >> 1))))) >> 31)) | (~(((v1470 ^ ((int)((unsigned int)((int)((unsigned int)v1465 >> 2)) >> 1))) | (-(v1470 ^ ((int)((unsigned int)((int)((unsigned int)v1465 >> 2)) >> 1))))) >> 31))) & 104)) ^ (((~(((v1467 ^ ((int)((unsigned int)((int)((unsigned int)v1465 >> 2)) >> 1))) | (-(v1467 ^ ((int)((unsigned int)((int)((unsigned int)v1465 >> 2)) >> 1))))) >> 31)) | (~(((v1468 ^ ((int)((unsigned int)((int)((unsigned int)v1465 >> 2)) >> 1))) | (-(v1468 ^ ((int)((unsigned int)((int)((unsigned int)v1465 >> 2)) >> 1))))) >> 31))) & (1 ^ (100 ^ (((~(((v1469 ^ ((int)((unsigned int)((int)((unsigned int)v1465 >> 2)) >> 1))) | (-(v1469 ^ ((int)((unsigned int)((int)((unsigned int)v1465 >> 2)) >> 1))))) >> 31)) | (~(((v1470 ^ ((int)((unsigned int)((int)((unsigned int)v1465 >> 2)) >> 1))) | (-(v1470 ^ ((int)((unsigned int)((int)((unsigned int)v1465 >> 2)) >> 1))))) >> 31))) & 104)))));
  v1463->timer = v1677;
  int * v1473 = v1463->cache_vals;
  bool v1678 = !(((~(((v1467 ^ ((int)((unsigned int)((int)((unsigned int)v1465 >> 2)) >> 1))) | (-(v1467 ^ ((int)((unsigned int)((int)((unsigned int)v1465 >> 2)) >> 1))))) >> 31)) | (~(((v1468 ^ ((int)((unsigned int)((int)((unsigned int)v1465 >> 2)) >> 1))) | (-(v1468 ^ ((int)((unsigned int)((int)((unsigned int)v1465 >> 2)) >> 1))))) >> 31))) == 0);
  int v1566;
  if (v1678) {
    int * v1474 = v1463->cache_age;
    int v1680 = ((((int)((unsigned int)((int)((unsigned int)v1465 >> 2)) >> 1)) & 1) * 2) + ((~(((v1468 ^ ((int)((unsigned int)((int)((unsigned int)v1465 >> 2)) >> 1))) | (-(v1468 ^ ((int)((unsigned int)((int)((unsigned int)v1465 >> 2)) >> 1))))) >> 31)) & 1);
    int v1475 = v1474[v1680];
    int v1476 = v1474[v1673];
    int v1681 = v1476 + ((int)((unsigned int)(v1476 - v1475) >> 31));
    v1474[v1673] = v1681;
    int * v1478 = v1463->cache_age;
    int v1479 = v1478[v1674];
    int v1683 = v1479 + ((int)((unsigned int)(v1479 - v1475) >> 31));
    v1478[v1674] = v1683;
    int * v1481 = v1463->cache_age;
    v1481[v1680] = 0;
    v1566 = v1680;
  } else {
    int * v1484 = v1463->cache_age;
    int v1687 = (((int)((unsigned int)((int)((unsigned int)v1465 >> 2)) >> 1)) & 1) * 2;
    int v1485 = v1484[v1687];
    int * v1486 = v1463->cache_tags;
    int v1487 = v1486[v1687];
    int v1488 = v1484[v1674];
    int v1489 = v1486[v1674];
    bool v1689 = !(((~(((v1469 ^ ((int)((unsigned int)((int)((unsigned int)v1465 >> 2)) >> 1))) | (-(v1469 ^ ((int)((unsigned int)((int)((unsigned int)v1465 >> 2)) >> 1))))) >> 31)) | (~(((v1470 ^ ((int)((unsigned int)((int)((unsigned int)v1465 >> 2)) >> 1))) | (-(v1470 ^ ((int)((unsigned int)((int)((unsigned int)v1465 >> 2)) >> 1))))) >> 31))) == 0);
    int v1543;
    if (v1689) {
      int * v1490 = v1463->cache_age;
      int v1691 = (4 + ((((int)((unsigned int)((int)((unsigned int)v1465 >> 2)) >> 1)) & 3) * 2)) + ((~(((v1470 ^ ((int)((unsigned int)((int)((unsigned int)v1465 >> 2)) >> 1))) | (-(v1470 ^ ((int)((unsigned int)((int)((unsigned int)v1465 >> 2)) >> 1))))) >> 31)) & 1);
      int v1491 = v1490[v1691];
      int v1492 = v1490[v1675];
      int v1692 = v1492 + ((int)((unsigned int)(v1492 - v1491) >> 31));
      v1490[v1675] = v1692;
      int * v1494 = v1463->cache_age;
      int v1495 = v1494[v1676];
      int v1694 = v1495 + ((int)((unsigned int)(v1495 - v1491) >> 31));
      v1494[v1676] = v1694;
      int * v1497 = v1463->cache_age;
      v1497[v1691] = 0;
      v1543 = v1691;
    } else {
      int * v1500 = v1463->cache_age;
      int v1698 = 4 + ((((int)((unsigned int)((int)((unsigned int)v1465 >> 2)) >> 1)) & 3) * 2);
      int v1501 = v1500[v1698];
      int * v1502 = v1463->cache_tags;
      int v1503 = v1502[v1698];
      int v1504 = v1500[v1676];
      int v1505 = v1502[v1676];
      int * v1506 = v1463->cache_dirty;
      int v1701 = (4 + ((((int)((unsigned int)((int)((unsigned int)v1465 >> 2)) >> 1)) & 3) * 2)) + ((((v1501 + ((~(((v1503 ^ -1) | (-(v1503 ^ -1))) >> 31)) & 2)) - (v1504 + ((~(((v1505 ^ -1) | (-(v1505 ^ -1))) >> 31)) & 2))) >> 31) & 1);
      int v1507 = v1506[v1701];
      bool v1702 = !(v1507 == 0);
      if (v1702) {
        int * v1508 = v1463->cache_tags;
        int v1509 = v1508[v1701];
        int * v1510 = v1463->cache_vals;
        int v1705 = ((4 + ((((int)((unsigned int)((int)((unsigned int)v1465 >> 2)) >> 1)) & 3) * 2)) + ((((v1501 + ((~(((v1503 ^ -1) | (-(v1503 ^ -1))) >> 31)) & 2)) - (v1504 + ((~(((v1505 ^ -1) | (-(v1505 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
        int v1511 = v1510[v1705];
        int v1706 = (((4 + ((((int)((unsigned int)((int)((unsigned int)v1465 >> 2)) >> 1)) & 3) * 2)) + ((((v1501 + ((~(((v1503 ^ -1) | (-(v1503 ^ -1))) >> 31)) & 2)) - (v1504 + ((~(((v1505 ^ -1) | (-(v1505 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
        int v1512 = v1510[v1706];
        int * v1513 = v1463->mem;
        int v1708 = v1509 * 2;
        v1513[v1708] = v1511;
        int * v1515 = v1463->mem;
        int v1711 = (v1509 * 2) + 1;
        v1515[v1711] = v1512;
        ;
      } else {
        ;
      }
      int * v1520 = v1463->mem;
      int v1716 = ((int)((unsigned int)((int)((unsigned int)v1465 >> 2)) >> 1)) * 2;
      int v1521 = v1520[v1716];
      int v1717 = (((int)((unsigned int)((int)((unsigned int)v1465 >> 2)) >> 1)) * 2) + 1;
      int v1522 = v1520[v1717];
      int * v1523 = v1463->cache_vals;
      int v1719 = ((4 + ((((int)((unsigned int)((int)((unsigned int)v1465 >> 2)) >> 1)) & 3) * 2)) + ((((v1501 + ((~(((v1503 ^ -1) | (-(v1503 ^ -1))) >> 31)) & 2)) - (v1504 + ((~(((v1505 ^ -1) | (-(v1505 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
      v1523[v1719] = v1521;
      int * v1525 = v1463->cache_vals;
      int v1722 = (((4 + ((((int)((unsigned int)((int)((unsigned int)v1465 >> 2)) >> 1)) & 3) * 2)) + ((((v1501 + ((~(((v1503 ^ -1) | (-(v1503 ^ -1))) >> 31)) & 2)) - (v1504 + ((~(((v1505 ^ -1) | (-(v1505 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
      v1525[v1722] = v1522;
      int * v1527 = v1463->cache_tags;
      int v1725 = (int)((unsigned int)((int)((unsigned int)v1465 >> 2)) >> 1);
      v1527[v1701] = v1725;
      int * v1529 = v1463->cache_dirty;
      v1529[v1701] = 0;
      int * v1531 = v1463->cache_age;
      v1531[v1701] = 1;
      int * v1533 = v1463->cache_age;
      int v1534 = v1533[v1701];
      int v1535 = v1533[v1675];
      int v1731 = v1535 + ((int)((unsigned int)(v1535 - v1534) >> 31));
      v1533[v1675] = v1731;
      int * v1537 = v1463->cache_age;
      int v1538 = v1537[v1676];
      int v1733 = v1538 + ((int)((unsigned int)(v1538 - v1534) >> 31));
      v1537[v1676] = v1733;
      int * v1540 = v1463->cache_age;
      v1540[v1701] = 0;
      v1543 = v1701;
    }
    int * v1544 = v1463->cache_vals;
    int v1736 = v1543 * 2;
    int v1545 = v1544[v1736];
    int v1737 = (v1543 * 2) + 1;
    int v1546 = v1544[v1737];
    int v1738 = (((((int)((unsigned int)((int)((unsigned int)v1465 >> 2)) >> 1)) & 1) * 2) + ((((v1485 + ((~(((v1487 ^ -1) | (-(v1487 ^ -1))) >> 31)) & 2)) - (v1488 + ((~(((v1489 ^ -1) | (-(v1489 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
    v1544[v1738] = v1545;
    int * v1548 = v1463->cache_vals;
    int v1741 = ((((((int)((unsigned int)((int)((unsigned int)v1465 >> 2)) >> 1)) & 1) * 2) + ((((v1485 + ((~(((v1487 ^ -1) | (-(v1487 ^ -1))) >> 31)) & 2)) - (v1488 + ((~(((v1489 ^ -1) | (-(v1489 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
    v1548[v1741] = v1546;
    int * v1550 = v1463->cache_tags;
    int v1744 = ((((int)((unsigned int)((int)((unsigned int)v1465 >> 2)) >> 1)) & 1) * 2) + ((((v1485 + ((~(((v1487 ^ -1) | (-(v1487 ^ -1))) >> 31)) & 2)) - (v1488 + ((~(((v1489 ^ -1) | (-(v1489 ^ -1))) >> 31)) & 2))) >> 31) & 1);
    int v1745 = (int)((unsigned int)((int)((unsigned int)v1465 >> 2)) >> 1);
    v1550[v1744] = v1745;
    int * v1552 = v1463->cache_dirty;
    v1552[v1744] = 0;
    int * v1554 = v1463->cache_age;
    v1554[v1744] = 1;
    int * v1556 = v1463->cache_age;
    int v1557 = v1556[v1744];
    int v1558 = v1556[v1673];
    int v1751 = v1558 + ((int)((unsigned int)(v1558 - v1557) >> 31));
    v1556[v1673] = v1751;
    int * v1560 = v1463->cache_age;
    int v1561 = v1560[v1674];
    int v1753 = v1561 + ((int)((unsigned int)(v1561 - v1557) >> 31));
    v1560[v1674] = v1753;
    int * v1563 = v1463->cache_age;
    v1563[v1744] = 0;
    v1566 = v1744;
  }
  int v1756 = (v1566 * 2) + (((int)((unsigned int)v1465 >> 2)) & 1);
  int v1567 = v1473[v1756];
  int * v1568 = v1463->regs;
  v1568[11] = v1567;
  struct StateT2 * v1570 = slot_10(v1343);
  return v1570;
}

struct StateT2 * slot_11(struct StateT2 * v1800) {
  struct StateT * v1801 = v1800->a;
  int v1802 = v1801->timer;
  struct StateT * v1803 = v1800->b;
  int v1804 = v1803->timer;
  bool v1819 = v1802 == v1804;
  squared_assert(v1819);
  squared_assume(v1819);
  struct StateT * v1807 = v1800->a;
  int v1808 = v1807->timer;
  int v1821 = v1808 + 1;
  v1807->timer = v1821;
  struct StateT * v1810 = v1800->b;
  int v1811 = v1810->timer;
  int v1823 = v1811 + 1;
  v1810->timer = v1823;
  struct StateT2 * v1815 = slot_3(v1800);
  return v1815;
}

struct StateT2 * slot_0(struct StateT2 * v2) {
  struct StateT * v3 = v2->a;
  int v4 = v3->timer;
  struct StateT * v5 = v2->b;
  int v6 = v5->timer;
  bool v25 = v4 == v6;
  squared_assert(v25);
  squared_assume(v25);
  struct StateT * v9 = v2->a;
  int v10 = v9->timer;
  int v27 = v10 + 1;
  v9->timer = v27;
  struct StateT * v12 = v2->b;
  int v13 = v12->timer;
  int v29 = v13 + 1;
  v12->timer = v29;
  struct StateT * v15 = v2->a;
  int * v16 = v15->regs;
  v16[6] = 0;
  struct StateT * v18 = v2->b;
  int * v19 = v18->regs;
  v19[6] = 0;
  struct StateT2 * v21 = slot_1(v2);
  return v21;
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
  for (int i=0; i<CACHE_ENTRIES; i++) {
    s->cache_tags[i] = -1;
    s->cache_dirty[i] = 0;
    s->cache_age[i] = 0;
  }
  for (int i=0; i<CACHE_WORDS; i++) {
    s->cache_vals[i] = 0;
  }
}

void squared_assert(bool c) { koika_assert(c, "timer drift"); }
void squared_diverged(bool c) { koika_assert(c, "control flow diverged"); }
void squared_assume(bool c) { koika_assume(c); }

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
  struct StateT2 p = { .a = &s1, .b = &s2 };
  struct StateT2 *p_ = snippet(&p);
  koika_assert(p_->a->timer==p_->b->timer, "timing leak");
  return 0;
}