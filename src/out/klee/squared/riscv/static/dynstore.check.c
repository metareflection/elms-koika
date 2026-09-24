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

struct StateT2 * slot_6(struct StateT2 * v731);
struct StateT2 * slot_5(struct StateT2 * v203);
struct StateT2 * slot_2(struct StateT2 * v74);
struct StateT2 * slot_3(struct StateT2 * v110);
struct StateT2 * snippet(struct StateT2 * v0);
struct StateT2 * slot_10(struct StateT2 * v2097);
struct StateT2 * slot_1(struct StateT2 * v38);
struct StateT2 * slot_8(struct StateT2 * v811);
struct StateT2 * slot_4(struct StateT2 * v134);
struct StateT2 * slot_9(struct StateT2 * v1587);
struct StateT2 * slot_11(struct StateT2 * v2140);
struct StateT2 * slot_0(struct StateT2 * v2);
struct StateT2 * slot_6(struct StateT2 * v731) {
  struct StateT * v732 = v731->a;
  int v733 = v732->timer;
  struct StateT * v734 = v731->b;
  int v735 = v734->timer;
  bool v779 = v733 == v735;
  squared_assert(v779);
  squared_assume(v779);
  struct StateT * v738 = v731->a;
  int * v739 = v738->regs;
  int v740 = v739[6];
  int * v741 = v738->regs;
  int v742 = v741[7];
  struct StateT * v743 = v731->b;
  int * v744 = v743->regs;
  int v745 = v744[6];
  int * v746 = v743->regs;
  int v747 = v746[7];
  bool v788 = (v740 >= v742) == (v745 >= v747);
  squared_diverged(v788);
  squared_assume(v788);
  bool v789 = v740 >= v742;
  struct StateT2 * v775;
  if (v789) {
    struct StateT * v750 = v731->a;
    int v751 = v750->timer;
    int v791 = v751 + 15;
    v750->timer = v791;
    int * v753 = v750->saved_regs;
    int v754 = v753[8];
    int * v755 = v750->regs;
    v755[8] = v754;
    int * v757 = v750->saved_regs;
    int v758 = v757[5];
    int * v759 = v750->regs;
    v759[5] = v758;
    struct StateT * v761 = v731->b;
    int v762 = v761->timer;
    int v801 = v762 + 15;
    v761->timer = v801;
    int * v764 = v761->saved_regs;
    int v765 = v764[8];
    int * v766 = v761->regs;
    v766[8] = v765;
    int * v768 = v761->saved_regs;
    int v769 = v768[5];
    int * v770 = v761->regs;
    v770[5] = v769;
    v775 = v731;
  } else {
    struct StateT2 * v773 = slot_8(v731);
    v775 = v773;
  }
  return v775;
}

struct StateT2 * slot_5(struct StateT2 * v203) {
  struct StateT * v204 = v203->a;
  int v205 = v204->timer;
  struct StateT * v206 = v203->b;
  int v207 = v206->timer;
  bool v490 = v205 == v207;
  squared_assert(v490);
  squared_assume(v490);
  struct StateT * v210 = v203->a;
  int * v211 = v210->saved_regs;
  int * v212 = v210->regs;
  int v213 = v212[5];
  v211[5] = v213;
  struct StateT * v215 = v203->b;
  int * v216 = v215->saved_regs;
  int * v217 = v215->regs;
  int v218 = v217[5];
  v216[5] = v218;
  struct StateT * v220 = v203->a;
  int v221 = v220->timer;
  int v501 = v221 + 1;
  v220->timer = v501;
  struct StateT * v223 = v203->b;
  int v224 = v223->timer;
  int v503 = v224 + 1;
  v223->timer = v503;
  struct StateT * v226 = v203->a;
  int * v227 = v226->regs;
  int v228 = v227[8];
  int * v229 = v226->cache_tags;
  int v508 = (((int)((unsigned int)((int)((unsigned int)v228 >> 2)) >> 1)) & 1) * 2;
  int v230 = v229[v508];
  int * v231 = v226->cache_tags;
  int v510 = ((((int)((unsigned int)((int)((unsigned int)v228 >> 2)) >> 1)) & 1) * 2) + 1;
  int v232 = v231[v510];
  int * v233 = v226->cache_tags;
  int v512 = 4 + ((((int)((unsigned int)((int)((unsigned int)v228 >> 2)) >> 1)) & 3) * 2);
  int v234 = v233[v512];
  int * v235 = v226->cache_tags;
  int v514 = (4 + ((((int)((unsigned int)((int)((unsigned int)v228 >> 2)) >> 1)) & 3) * 2)) + 1;
  int v236 = v235[v514];
  int v237 = v226->timer;
  int v515 = v237 + ((100 ^ (((~(((v234 ^ ((int)((unsigned int)((int)((unsigned int)v228 >> 2)) >> 1))) | (-(v234 ^ ((int)((unsigned int)((int)((unsigned int)v228 >> 2)) >> 1))))) >> 31)) | (~(((v236 ^ ((int)((unsigned int)((int)((unsigned int)v228 >> 2)) >> 1))) | (-(v236 ^ ((int)((unsigned int)((int)((unsigned int)v228 >> 2)) >> 1))))) >> 31))) & 104)) ^ (((~(((v230 ^ ((int)((unsigned int)((int)((unsigned int)v228 >> 2)) >> 1))) | (-(v230 ^ ((int)((unsigned int)((int)((unsigned int)v228 >> 2)) >> 1))))) >> 31)) | (~(((v232 ^ ((int)((unsigned int)((int)((unsigned int)v228 >> 2)) >> 1))) | (-(v232 ^ ((int)((unsigned int)((int)((unsigned int)v228 >> 2)) >> 1))))) >> 31))) & (1 ^ (100 ^ (((~(((v234 ^ ((int)((unsigned int)((int)((unsigned int)v228 >> 2)) >> 1))) | (-(v234 ^ ((int)((unsigned int)((int)((unsigned int)v228 >> 2)) >> 1))))) >> 31)) | (~(((v236 ^ ((int)((unsigned int)((int)((unsigned int)v228 >> 2)) >> 1))) | (-(v236 ^ ((int)((unsigned int)((int)((unsigned int)v228 >> 2)) >> 1))))) >> 31))) & 104)))));
  v226->timer = v515;
  int * v239 = v226->cache_vals;
  bool v516 = !(((~(((v230 ^ ((int)((unsigned int)((int)((unsigned int)v228 >> 2)) >> 1))) | (-(v230 ^ ((int)((unsigned int)((int)((unsigned int)v228 >> 2)) >> 1))))) >> 31)) | (~(((v232 ^ ((int)((unsigned int)((int)((unsigned int)v228 >> 2)) >> 1))) | (-(v232 ^ ((int)((unsigned int)((int)((unsigned int)v228 >> 2)) >> 1))))) >> 31))) == 0);
  int v352;
  if (v516) {
    int * v240 = v226->cache_age;
    int v518 = ((((int)((unsigned int)((int)((unsigned int)v228 >> 2)) >> 1)) & 1) * 2) + ((~(((v232 ^ ((int)((unsigned int)((int)((unsigned int)v228 >> 2)) >> 1))) | (-(v232 ^ ((int)((unsigned int)((int)((unsigned int)v228 >> 2)) >> 1))))) >> 31)) & 1);
    int v241 = v240[v518];
    int * v242 = v226->cache_age;
    int v243 = v242[v508];
    int * v244 = v226->cache_age;
    int v521 = v243 + ((int)((unsigned int)(v243 - v241) >> 31));
    v244[v508] = v521;
    int * v246 = v226->cache_age;
    int v247 = v246[v510];
    int * v248 = v226->cache_age;
    int v524 = v247 + ((int)((unsigned int)(v247 - v241) >> 31));
    v248[v510] = v524;
    int * v250 = v226->cache_age;
    v250[v518] = 0;
    v352 = v518;
  } else {
    int * v253 = v226->cache_age;
    int v528 = (((int)((unsigned int)((int)((unsigned int)v228 >> 2)) >> 1)) & 1) * 2;
    int v254 = v253[v528];
    int * v255 = v226->cache_tags;
    int v256 = v255[v528];
    int * v257 = v226->cache_age;
    int v258 = v257[v510];
    int * v259 = v226->cache_tags;
    int v260 = v259[v510];
    bool v532 = !(((~(((v234 ^ ((int)((unsigned int)((int)((unsigned int)v228 >> 2)) >> 1))) | (-(v234 ^ ((int)((unsigned int)((int)((unsigned int)v228 >> 2)) >> 1))))) >> 31)) | (~(((v236 ^ ((int)((unsigned int)((int)((unsigned int)v228 >> 2)) >> 1))) | (-(v236 ^ ((int)((unsigned int)((int)((unsigned int)v228 >> 2)) >> 1))))) >> 31))) == 0);
    int v324;
    if (v532) {
      int * v261 = v226->cache_age;
      int v534 = (4 + ((((int)((unsigned int)((int)((unsigned int)v228 >> 2)) >> 1)) & 3) * 2)) + ((~(((v236 ^ ((int)((unsigned int)((int)((unsigned int)v228 >> 2)) >> 1))) | (-(v236 ^ ((int)((unsigned int)((int)((unsigned int)v228 >> 2)) >> 1))))) >> 31)) & 1);
      int v262 = v261[v534];
      int * v263 = v226->cache_age;
      int v264 = v263[v512];
      int * v265 = v226->cache_age;
      int v537 = v264 + ((int)((unsigned int)(v264 - v262) >> 31));
      v265[v512] = v537;
      int * v267 = v226->cache_age;
      int v268 = v267[v514];
      int * v269 = v226->cache_age;
      int v540 = v268 + ((int)((unsigned int)(v268 - v262) >> 31));
      v269[v514] = v540;
      int * v271 = v226->cache_age;
      v271[v534] = 0;
      v324 = v534;
    } else {
      int * v274 = v226->cache_age;
      int v544 = 4 + ((((int)((unsigned int)((int)((unsigned int)v228 >> 2)) >> 1)) & 3) * 2);
      int v275 = v274[v544];
      int * v276 = v226->cache_tags;
      int v277 = v276[v544];
      int * v278 = v226->cache_age;
      int v279 = v278[v514];
      int * v280 = v226->cache_tags;
      int v281 = v280[v514];
      int * v282 = v226->cache_dirty;
      int v549 = (4 + ((((int)((unsigned int)((int)((unsigned int)v228 >> 2)) >> 1)) & 3) * 2)) + ((((v275 + ((~(((v277 ^ -1) | (-(v277 ^ -1))) >> 31)) & 2)) - (v279 + ((~(((v281 ^ -1) | (-(v281 ^ -1))) >> 31)) & 2))) >> 31) & 1);
      int v283 = v282[v549];
      bool v550 = !(v283 == 0);
      if (v550) {
        int * v284 = v226->cache_tags;
        int v285 = v284[v549];
        int * v286 = v226->cache_vals;
        int v553 = ((4 + ((((int)((unsigned int)((int)((unsigned int)v228 >> 2)) >> 1)) & 3) * 2)) + ((((v275 + ((~(((v277 ^ -1) | (-(v277 ^ -1))) >> 31)) & 2)) - (v279 + ((~(((v281 ^ -1) | (-(v281 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
        int v287 = v286[v553];
        int * v288 = v226->cache_vals;
        int v555 = (((4 + ((((int)((unsigned int)((int)((unsigned int)v228 >> 2)) >> 1)) & 3) * 2)) + ((((v275 + ((~(((v277 ^ -1) | (-(v277 ^ -1))) >> 31)) & 2)) - (v279 + ((~(((v281 ^ -1) | (-(v281 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
        int v289 = v288[v555];
        int * v290 = v226->mem;
        int v557 = v285 * 2;
        v290[v557] = v287;
        int * v292 = v226->mem;
        int v560 = (v285 * 2) + 1;
        v292[v560] = v289;
        ;
      } else {
        ;
      }
      int * v297 = v226->mem;
      int v565 = ((int)((unsigned int)((int)((unsigned int)v228 >> 2)) >> 1)) * 2;
      int v298 = v297[v565];
      int * v299 = v226->mem;
      int v567 = (((int)((unsigned int)((int)((unsigned int)v228 >> 2)) >> 1)) * 2) + 1;
      int v300 = v299[v567];
      int * v301 = v226->cache_vals;
      int v569 = ((4 + ((((int)((unsigned int)((int)((unsigned int)v228 >> 2)) >> 1)) & 3) * 2)) + ((((v275 + ((~(((v277 ^ -1) | (-(v277 ^ -1))) >> 31)) & 2)) - (v279 + ((~(((v281 ^ -1) | (-(v281 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
      v301[v569] = v298;
      int * v303 = v226->cache_vals;
      int v572 = (((4 + ((((int)((unsigned int)((int)((unsigned int)v228 >> 2)) >> 1)) & 3) * 2)) + ((((v275 + ((~(((v277 ^ -1) | (-(v277 ^ -1))) >> 31)) & 2)) - (v279 + ((~(((v281 ^ -1) | (-(v281 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
      v303[v572] = v300;
      int * v305 = v226->cache_tags;
      int v575 = (int)((unsigned int)((int)((unsigned int)v228 >> 2)) >> 1);
      v305[v549] = v575;
      int * v307 = v226->cache_dirty;
      v307[v549] = 0;
      int * v309 = v226->cache_age;
      v309[v549] = 1;
      int * v311 = v226->cache_age;
      int v312 = v311[v549];
      int * v313 = v226->cache_age;
      int v314 = v313[v512];
      int * v315 = v226->cache_age;
      int v583 = v314 + ((int)((unsigned int)(v314 - v312) >> 31));
      v315[v512] = v583;
      int * v317 = v226->cache_age;
      int v318 = v317[v514];
      int * v319 = v226->cache_age;
      int v586 = v318 + ((int)((unsigned int)(v318 - v312) >> 31));
      v319[v514] = v586;
      int * v321 = v226->cache_age;
      v321[v549] = 0;
      v324 = v549;
    }
    int * v325 = v226->cache_vals;
    int v589 = v324 * 2;
    int v326 = v325[v589];
    int * v327 = v226->cache_vals;
    int v591 = (v324 * 2) + 1;
    int v328 = v327[v591];
    int * v329 = v226->cache_vals;
    int v593 = (((((int)((unsigned int)((int)((unsigned int)v228 >> 2)) >> 1)) & 1) * 2) + ((((v254 + ((~(((v256 ^ -1) | (-(v256 ^ -1))) >> 31)) & 2)) - (v258 + ((~(((v260 ^ -1) | (-(v260 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
    v329[v593] = v326;
    int * v331 = v226->cache_vals;
    int v596 = ((((((int)((unsigned int)((int)((unsigned int)v228 >> 2)) >> 1)) & 1) * 2) + ((((v254 + ((~(((v256 ^ -1) | (-(v256 ^ -1))) >> 31)) & 2)) - (v258 + ((~(((v260 ^ -1) | (-(v260 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
    v331[v596] = v328;
    int * v333 = v226->cache_tags;
    int v599 = ((((int)((unsigned int)((int)((unsigned int)v228 >> 2)) >> 1)) & 1) * 2) + ((((v254 + ((~(((v256 ^ -1) | (-(v256 ^ -1))) >> 31)) & 2)) - (v258 + ((~(((v260 ^ -1) | (-(v260 ^ -1))) >> 31)) & 2))) >> 31) & 1);
    int v600 = (int)((unsigned int)((int)((unsigned int)v228 >> 2)) >> 1);
    v333[v599] = v600;
    int * v335 = v226->cache_dirty;
    v335[v599] = 0;
    int * v337 = v226->cache_age;
    v337[v599] = 1;
    int * v339 = v226->cache_age;
    int v340 = v339[v599];
    int * v341 = v226->cache_age;
    int v342 = v341[v508];
    int * v343 = v226->cache_age;
    int v608 = v342 + ((int)((unsigned int)(v342 - v340) >> 31));
    v343[v508] = v608;
    int * v345 = v226->cache_age;
    int v346 = v345[v510];
    int * v347 = v226->cache_age;
    int v611 = v346 + ((int)((unsigned int)(v346 - v340) >> 31));
    v347[v510] = v611;
    int * v349 = v226->cache_age;
    v349[v599] = 0;
    v352 = v599;
  }
  int v614 = (v352 * 2) + (((int)((unsigned int)v228 >> 2)) & 1);
  int v353 = v239[v614];
  int * v354 = v226->regs;
  v354[5] = v353;
  struct StateT * v356 = v203->b;
  int * v357 = v356->regs;
  int v358 = v357[8];
  int * v359 = v356->cache_tags;
  int v620 = (((int)((unsigned int)((int)((unsigned int)v358 >> 2)) >> 1)) & 1) * 2;
  int v360 = v359[v620];
  int * v361 = v356->cache_tags;
  int v622 = ((((int)((unsigned int)((int)((unsigned int)v358 >> 2)) >> 1)) & 1) * 2) + 1;
  int v362 = v361[v622];
  int * v363 = v356->cache_tags;
  int v624 = 4 + ((((int)((unsigned int)((int)((unsigned int)v358 >> 2)) >> 1)) & 3) * 2);
  int v364 = v363[v624];
  int * v365 = v356->cache_tags;
  int v626 = (4 + ((((int)((unsigned int)((int)((unsigned int)v358 >> 2)) >> 1)) & 3) * 2)) + 1;
  int v366 = v365[v626];
  int v367 = v356->timer;
  int v627 = v367 + ((100 ^ (((~(((v364 ^ ((int)((unsigned int)((int)((unsigned int)v358 >> 2)) >> 1))) | (-(v364 ^ ((int)((unsigned int)((int)((unsigned int)v358 >> 2)) >> 1))))) >> 31)) | (~(((v366 ^ ((int)((unsigned int)((int)((unsigned int)v358 >> 2)) >> 1))) | (-(v366 ^ ((int)((unsigned int)((int)((unsigned int)v358 >> 2)) >> 1))))) >> 31))) & 104)) ^ (((~(((v360 ^ ((int)((unsigned int)((int)((unsigned int)v358 >> 2)) >> 1))) | (-(v360 ^ ((int)((unsigned int)((int)((unsigned int)v358 >> 2)) >> 1))))) >> 31)) | (~(((v362 ^ ((int)((unsigned int)((int)((unsigned int)v358 >> 2)) >> 1))) | (-(v362 ^ ((int)((unsigned int)((int)((unsigned int)v358 >> 2)) >> 1))))) >> 31))) & (1 ^ (100 ^ (((~(((v364 ^ ((int)((unsigned int)((int)((unsigned int)v358 >> 2)) >> 1))) | (-(v364 ^ ((int)((unsigned int)((int)((unsigned int)v358 >> 2)) >> 1))))) >> 31)) | (~(((v366 ^ ((int)((unsigned int)((int)((unsigned int)v358 >> 2)) >> 1))) | (-(v366 ^ ((int)((unsigned int)((int)((unsigned int)v358 >> 2)) >> 1))))) >> 31))) & 104)))));
  v356->timer = v627;
  int * v369 = v356->cache_vals;
  bool v628 = !(((~(((v360 ^ ((int)((unsigned int)((int)((unsigned int)v358 >> 2)) >> 1))) | (-(v360 ^ ((int)((unsigned int)((int)((unsigned int)v358 >> 2)) >> 1))))) >> 31)) | (~(((v362 ^ ((int)((unsigned int)((int)((unsigned int)v358 >> 2)) >> 1))) | (-(v362 ^ ((int)((unsigned int)((int)((unsigned int)v358 >> 2)) >> 1))))) >> 31))) == 0);
  int v482;
  if (v628) {
    int * v370 = v356->cache_age;
    int v630 = ((((int)((unsigned int)((int)((unsigned int)v358 >> 2)) >> 1)) & 1) * 2) + ((~(((v362 ^ ((int)((unsigned int)((int)((unsigned int)v358 >> 2)) >> 1))) | (-(v362 ^ ((int)((unsigned int)((int)((unsigned int)v358 >> 2)) >> 1))))) >> 31)) & 1);
    int v371 = v370[v630];
    int * v372 = v356->cache_age;
    int v373 = v372[v620];
    int * v374 = v356->cache_age;
    int v633 = v373 + ((int)((unsigned int)(v373 - v371) >> 31));
    v374[v620] = v633;
    int * v376 = v356->cache_age;
    int v377 = v376[v622];
    int * v378 = v356->cache_age;
    int v636 = v377 + ((int)((unsigned int)(v377 - v371) >> 31));
    v378[v622] = v636;
    int * v380 = v356->cache_age;
    v380[v630] = 0;
    v482 = v630;
  } else {
    int * v383 = v356->cache_age;
    int v640 = (((int)((unsigned int)((int)((unsigned int)v358 >> 2)) >> 1)) & 1) * 2;
    int v384 = v383[v640];
    int * v385 = v356->cache_tags;
    int v386 = v385[v640];
    int * v387 = v356->cache_age;
    int v388 = v387[v622];
    int * v389 = v356->cache_tags;
    int v390 = v389[v622];
    bool v644 = !(((~(((v364 ^ ((int)((unsigned int)((int)((unsigned int)v358 >> 2)) >> 1))) | (-(v364 ^ ((int)((unsigned int)((int)((unsigned int)v358 >> 2)) >> 1))))) >> 31)) | (~(((v366 ^ ((int)((unsigned int)((int)((unsigned int)v358 >> 2)) >> 1))) | (-(v366 ^ ((int)((unsigned int)((int)((unsigned int)v358 >> 2)) >> 1))))) >> 31))) == 0);
    int v454;
    if (v644) {
      int * v391 = v356->cache_age;
      int v646 = (4 + ((((int)((unsigned int)((int)((unsigned int)v358 >> 2)) >> 1)) & 3) * 2)) + ((~(((v366 ^ ((int)((unsigned int)((int)((unsigned int)v358 >> 2)) >> 1))) | (-(v366 ^ ((int)((unsigned int)((int)((unsigned int)v358 >> 2)) >> 1))))) >> 31)) & 1);
      int v392 = v391[v646];
      int * v393 = v356->cache_age;
      int v394 = v393[v624];
      int * v395 = v356->cache_age;
      int v649 = v394 + ((int)((unsigned int)(v394 - v392) >> 31));
      v395[v624] = v649;
      int * v397 = v356->cache_age;
      int v398 = v397[v626];
      int * v399 = v356->cache_age;
      int v652 = v398 + ((int)((unsigned int)(v398 - v392) >> 31));
      v399[v626] = v652;
      int * v401 = v356->cache_age;
      v401[v646] = 0;
      v454 = v646;
    } else {
      int * v404 = v356->cache_age;
      int v656 = 4 + ((((int)((unsigned int)((int)((unsigned int)v358 >> 2)) >> 1)) & 3) * 2);
      int v405 = v404[v656];
      int * v406 = v356->cache_tags;
      int v407 = v406[v656];
      int * v408 = v356->cache_age;
      int v409 = v408[v626];
      int * v410 = v356->cache_tags;
      int v411 = v410[v626];
      int * v412 = v356->cache_dirty;
      int v661 = (4 + ((((int)((unsigned int)((int)((unsigned int)v358 >> 2)) >> 1)) & 3) * 2)) + ((((v405 + ((~(((v407 ^ -1) | (-(v407 ^ -1))) >> 31)) & 2)) - (v409 + ((~(((v411 ^ -1) | (-(v411 ^ -1))) >> 31)) & 2))) >> 31) & 1);
      int v413 = v412[v661];
      bool v662 = !(v413 == 0);
      if (v662) {
        int * v414 = v356->cache_tags;
        int v415 = v414[v661];
        int * v416 = v356->cache_vals;
        int v665 = ((4 + ((((int)((unsigned int)((int)((unsigned int)v358 >> 2)) >> 1)) & 3) * 2)) + ((((v405 + ((~(((v407 ^ -1) | (-(v407 ^ -1))) >> 31)) & 2)) - (v409 + ((~(((v411 ^ -1) | (-(v411 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
        int v417 = v416[v665];
        int * v418 = v356->cache_vals;
        int v667 = (((4 + ((((int)((unsigned int)((int)((unsigned int)v358 >> 2)) >> 1)) & 3) * 2)) + ((((v405 + ((~(((v407 ^ -1) | (-(v407 ^ -1))) >> 31)) & 2)) - (v409 + ((~(((v411 ^ -1) | (-(v411 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
        int v419 = v418[v667];
        int * v420 = v356->mem;
        int v669 = v415 * 2;
        v420[v669] = v417;
        int * v422 = v356->mem;
        int v672 = (v415 * 2) + 1;
        v422[v672] = v419;
        ;
      } else {
        ;
      }
      int * v427 = v356->mem;
      int v677 = ((int)((unsigned int)((int)((unsigned int)v358 >> 2)) >> 1)) * 2;
      int v428 = v427[v677];
      int * v429 = v356->mem;
      int v679 = (((int)((unsigned int)((int)((unsigned int)v358 >> 2)) >> 1)) * 2) + 1;
      int v430 = v429[v679];
      int * v431 = v356->cache_vals;
      int v681 = ((4 + ((((int)((unsigned int)((int)((unsigned int)v358 >> 2)) >> 1)) & 3) * 2)) + ((((v405 + ((~(((v407 ^ -1) | (-(v407 ^ -1))) >> 31)) & 2)) - (v409 + ((~(((v411 ^ -1) | (-(v411 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
      v431[v681] = v428;
      int * v433 = v356->cache_vals;
      int v684 = (((4 + ((((int)((unsigned int)((int)((unsigned int)v358 >> 2)) >> 1)) & 3) * 2)) + ((((v405 + ((~(((v407 ^ -1) | (-(v407 ^ -1))) >> 31)) & 2)) - (v409 + ((~(((v411 ^ -1) | (-(v411 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
      v433[v684] = v430;
      int * v435 = v356->cache_tags;
      int v687 = (int)((unsigned int)((int)((unsigned int)v358 >> 2)) >> 1);
      v435[v661] = v687;
      int * v437 = v356->cache_dirty;
      v437[v661] = 0;
      int * v439 = v356->cache_age;
      v439[v661] = 1;
      int * v441 = v356->cache_age;
      int v442 = v441[v661];
      int * v443 = v356->cache_age;
      int v444 = v443[v624];
      int * v445 = v356->cache_age;
      int v695 = v444 + ((int)((unsigned int)(v444 - v442) >> 31));
      v445[v624] = v695;
      int * v447 = v356->cache_age;
      int v448 = v447[v626];
      int * v449 = v356->cache_age;
      int v698 = v448 + ((int)((unsigned int)(v448 - v442) >> 31));
      v449[v626] = v698;
      int * v451 = v356->cache_age;
      v451[v661] = 0;
      v454 = v661;
    }
    int * v455 = v356->cache_vals;
    int v701 = v454 * 2;
    int v456 = v455[v701];
    int * v457 = v356->cache_vals;
    int v703 = (v454 * 2) + 1;
    int v458 = v457[v703];
    int * v459 = v356->cache_vals;
    int v705 = (((((int)((unsigned int)((int)((unsigned int)v358 >> 2)) >> 1)) & 1) * 2) + ((((v384 + ((~(((v386 ^ -1) | (-(v386 ^ -1))) >> 31)) & 2)) - (v388 + ((~(((v390 ^ -1) | (-(v390 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
    v459[v705] = v456;
    int * v461 = v356->cache_vals;
    int v708 = ((((((int)((unsigned int)((int)((unsigned int)v358 >> 2)) >> 1)) & 1) * 2) + ((((v384 + ((~(((v386 ^ -1) | (-(v386 ^ -1))) >> 31)) & 2)) - (v388 + ((~(((v390 ^ -1) | (-(v390 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
    v461[v708] = v458;
    int * v463 = v356->cache_tags;
    int v711 = ((((int)((unsigned int)((int)((unsigned int)v358 >> 2)) >> 1)) & 1) * 2) + ((((v384 + ((~(((v386 ^ -1) | (-(v386 ^ -1))) >> 31)) & 2)) - (v388 + ((~(((v390 ^ -1) | (-(v390 ^ -1))) >> 31)) & 2))) >> 31) & 1);
    int v712 = (int)((unsigned int)((int)((unsigned int)v358 >> 2)) >> 1);
    v463[v711] = v712;
    int * v465 = v356->cache_dirty;
    v465[v711] = 0;
    int * v467 = v356->cache_age;
    v467[v711] = 1;
    int * v469 = v356->cache_age;
    int v470 = v469[v711];
    int * v471 = v356->cache_age;
    int v472 = v471[v620];
    int * v473 = v356->cache_age;
    int v720 = v472 + ((int)((unsigned int)(v472 - v470) >> 31));
    v473[v620] = v720;
    int * v475 = v356->cache_age;
    int v476 = v475[v622];
    int * v477 = v356->cache_age;
    int v723 = v476 + ((int)((unsigned int)(v476 - v470) >> 31));
    v477[v622] = v723;
    int * v479 = v356->cache_age;
    v479[v711] = 0;
    v482 = v711;
  }
  int v726 = (v482 * 2) + (((int)((unsigned int)v358 >> 2)) & 1);
  int v483 = v369[v726];
  int * v484 = v356->regs;
  v484[5] = v483;
  struct StateT2 * v486 = slot_6(v203);
  return v486;
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

struct StateT2 * slot_10(struct StateT2 * v2097) {
  struct StateT * v2098 = v2097->a;
  int v2099 = v2098->timer;
  struct StateT * v2100 = v2097->b;
  int v2101 = v2100->timer;
  bool v2124 = v2099 == v2101;
  squared_assert(v2124);
  squared_assume(v2124);
  struct StateT * v2104 = v2097->a;
  int v2105 = v2104->timer;
  int v2126 = v2105 + 1;
  v2104->timer = v2126;
  struct StateT * v2107 = v2097->b;
  int v2108 = v2107->timer;
  int v2128 = v2108 + 1;
  v2107->timer = v2128;
  struct StateT * v2110 = v2097->a;
  int * v2111 = v2110->regs;
  int v2112 = v2111[6];
  int * v2113 = v2110->regs;
  int v2133 = v2112 + 4;
  v2113[6] = v2133;
  struct StateT * v2115 = v2097->b;
  int * v2116 = v2115->regs;
  int v2117 = v2116[6];
  int * v2118 = v2115->regs;
  int v2137 = v2117 + 4;
  v2118[6] = v2137;
  struct StateT2 * v2120 = slot_11(v2097);
  return v2120;
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

struct StateT2 * slot_8(struct StateT2 * v811) {
  struct StateT * v812 = v811->a;
  int v813 = v812->timer;
  struct StateT * v814 = v811->b;
  int v815 = v814->timer;
  bool v1232 = v813 == v815;
  squared_assert(v1232);
  squared_assume(v1232);
  struct StateT * v818 = v811->a;
  int v819 = v818->timer;
  int v1234 = v819 + 1;
  v818->timer = v1234;
  struct StateT * v821 = v811->b;
  int v822 = v821->timer;
  int v1236 = v822 + 1;
  v821->timer = v1236;
  struct StateT * v824 = v811->a;
  int * v825 = v824->regs;
  int v826 = v825[6];
  int * v827 = v824->regs;
  int v828 = v827[5];
  int * v829 = v824->cache_tags;
  int v1243 = (((int)((unsigned int)((int)((unsigned int)v826 >> 2)) >> 1)) & 1) * 2;
  int v830 = v829[v1243];
  int * v831 = v824->cache_tags;
  int v1245 = ((((int)((unsigned int)((int)((unsigned int)v826 >> 2)) >> 1)) & 1) * 2) + 1;
  int v832 = v831[v1245];
  int * v833 = v824->cache_tags;
  int v1247 = 4 + ((((int)((unsigned int)((int)((unsigned int)v826 >> 2)) >> 1)) & 3) * 2);
  int v834 = v833[v1247];
  int * v835 = v824->cache_tags;
  int v1249 = (4 + ((((int)((unsigned int)((int)((unsigned int)v826 >> 2)) >> 1)) & 3) * 2)) + 1;
  int v836 = v835[v1249];
  int v837 = v824->timer;
  int v1250 = v837 + ((100 ^ (((~(((v834 ^ ((int)((unsigned int)((int)((unsigned int)v826 >> 2)) >> 1))) | (-(v834 ^ ((int)((unsigned int)((int)((unsigned int)v826 >> 2)) >> 1))))) >> 31)) | (~(((v836 ^ ((int)((unsigned int)((int)((unsigned int)v826 >> 2)) >> 1))) | (-(v836 ^ ((int)((unsigned int)((int)((unsigned int)v826 >> 2)) >> 1))))) >> 31))) & 104)) ^ (((~(((v830 ^ ((int)((unsigned int)((int)((unsigned int)v826 >> 2)) >> 1))) | (-(v830 ^ ((int)((unsigned int)((int)((unsigned int)v826 >> 2)) >> 1))))) >> 31)) | (~(((v832 ^ ((int)((unsigned int)((int)((unsigned int)v826 >> 2)) >> 1))) | (-(v832 ^ ((int)((unsigned int)((int)((unsigned int)v826 >> 2)) >> 1))))) >> 31))) & (1 ^ (100 ^ (((~(((v834 ^ ((int)((unsigned int)((int)((unsigned int)v826 >> 2)) >> 1))) | (-(v834 ^ ((int)((unsigned int)((int)((unsigned int)v826 >> 2)) >> 1))))) >> 31)) | (~(((v836 ^ ((int)((unsigned int)((int)((unsigned int)v826 >> 2)) >> 1))) | (-(v836 ^ ((int)((unsigned int)((int)((unsigned int)v826 >> 2)) >> 1))))) >> 31))) & 104)))));
  v824->timer = v1250;
  bool v1251 = !(((~(((v830 ^ ((int)((unsigned int)((int)((unsigned int)v826 >> 2)) >> 1))) | (-(v830 ^ ((int)((unsigned int)((int)((unsigned int)v826 >> 2)) >> 1))))) >> 31)) | (~(((v832 ^ ((int)((unsigned int)((int)((unsigned int)v826 >> 2)) >> 1))) | (-(v832 ^ ((int)((unsigned int)((int)((unsigned int)v826 >> 2)) >> 1))))) >> 31))) == 0);
  int v951;
  if (v1251) {
    int * v839 = v824->cache_age;
    int v1253 = ((((int)((unsigned int)((int)((unsigned int)v826 >> 2)) >> 1)) & 1) * 2) + ((~(((v832 ^ ((int)((unsigned int)((int)((unsigned int)v826 >> 2)) >> 1))) | (-(v832 ^ ((int)((unsigned int)((int)((unsigned int)v826 >> 2)) >> 1))))) >> 31)) & 1);
    int v840 = v839[v1253];
    int * v841 = v824->cache_age;
    int v842 = v841[v1243];
    int * v843 = v824->cache_age;
    int v1256 = v842 + ((int)((unsigned int)(v842 - v840) >> 31));
    v843[v1243] = v1256;
    int * v845 = v824->cache_age;
    int v846 = v845[v1245];
    int * v847 = v824->cache_age;
    int v1259 = v846 + ((int)((unsigned int)(v846 - v840) >> 31));
    v847[v1245] = v1259;
    int * v849 = v824->cache_age;
    v849[v1253] = 0;
    v951 = v1253;
  } else {
    int * v852 = v824->cache_age;
    int v1263 = (((int)((unsigned int)((int)((unsigned int)v826 >> 2)) >> 1)) & 1) * 2;
    int v853 = v852[v1263];
    int * v854 = v824->cache_tags;
    int v855 = v854[v1263];
    int * v856 = v824->cache_age;
    int v857 = v856[v1245];
    int * v858 = v824->cache_tags;
    int v859 = v858[v1245];
    bool v1267 = !(((~(((v834 ^ ((int)((unsigned int)((int)((unsigned int)v826 >> 2)) >> 1))) | (-(v834 ^ ((int)((unsigned int)((int)((unsigned int)v826 >> 2)) >> 1))))) >> 31)) | (~(((v836 ^ ((int)((unsigned int)((int)((unsigned int)v826 >> 2)) >> 1))) | (-(v836 ^ ((int)((unsigned int)((int)((unsigned int)v826 >> 2)) >> 1))))) >> 31))) == 0);
    int v923;
    if (v1267) {
      int * v860 = v824->cache_age;
      int v1269 = (4 + ((((int)((unsigned int)((int)((unsigned int)v826 >> 2)) >> 1)) & 3) * 2)) + ((~(((v836 ^ ((int)((unsigned int)((int)((unsigned int)v826 >> 2)) >> 1))) | (-(v836 ^ ((int)((unsigned int)((int)((unsigned int)v826 >> 2)) >> 1))))) >> 31)) & 1);
      int v861 = v860[v1269];
      int * v862 = v824->cache_age;
      int v863 = v862[v1247];
      int * v864 = v824->cache_age;
      int v1272 = v863 + ((int)((unsigned int)(v863 - v861) >> 31));
      v864[v1247] = v1272;
      int * v866 = v824->cache_age;
      int v867 = v866[v1249];
      int * v868 = v824->cache_age;
      int v1275 = v867 + ((int)((unsigned int)(v867 - v861) >> 31));
      v868[v1249] = v1275;
      int * v870 = v824->cache_age;
      v870[v1269] = 0;
      v923 = v1269;
    } else {
      int * v873 = v824->cache_age;
      int v1279 = 4 + ((((int)((unsigned int)((int)((unsigned int)v826 >> 2)) >> 1)) & 3) * 2);
      int v874 = v873[v1279];
      int * v875 = v824->cache_tags;
      int v876 = v875[v1279];
      int * v877 = v824->cache_age;
      int v878 = v877[v1249];
      int * v879 = v824->cache_tags;
      int v880 = v879[v1249];
      int * v881 = v824->cache_dirty;
      int v1284 = (4 + ((((int)((unsigned int)((int)((unsigned int)v826 >> 2)) >> 1)) & 3) * 2)) + ((((v874 + ((~(((v876 ^ -1) | (-(v876 ^ -1))) >> 31)) & 2)) - (v878 + ((~(((v880 ^ -1) | (-(v880 ^ -1))) >> 31)) & 2))) >> 31) & 1);
      int v882 = v881[v1284];
      bool v1285 = !(v882 == 0);
      if (v1285) {
        int * v883 = v824->cache_tags;
        int v884 = v883[v1284];
        int * v885 = v824->cache_vals;
        int v1288 = ((4 + ((((int)((unsigned int)((int)((unsigned int)v826 >> 2)) >> 1)) & 3) * 2)) + ((((v874 + ((~(((v876 ^ -1) | (-(v876 ^ -1))) >> 31)) & 2)) - (v878 + ((~(((v880 ^ -1) | (-(v880 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
        int v886 = v885[v1288];
        int * v887 = v824->cache_vals;
        int v1290 = (((4 + ((((int)((unsigned int)((int)((unsigned int)v826 >> 2)) >> 1)) & 3) * 2)) + ((((v874 + ((~(((v876 ^ -1) | (-(v876 ^ -1))) >> 31)) & 2)) - (v878 + ((~(((v880 ^ -1) | (-(v880 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
        int v888 = v887[v1290];
        int * v889 = v824->mem;
        int v1292 = v884 * 2;
        v889[v1292] = v886;
        int * v891 = v824->mem;
        int v1295 = (v884 * 2) + 1;
        v891[v1295] = v888;
        ;
      } else {
        ;
      }
      int * v896 = v824->mem;
      int v1300 = ((int)((unsigned int)((int)((unsigned int)v826 >> 2)) >> 1)) * 2;
      int v897 = v896[v1300];
      int * v898 = v824->mem;
      int v1302 = (((int)((unsigned int)((int)((unsigned int)v826 >> 2)) >> 1)) * 2) + 1;
      int v899 = v898[v1302];
      int * v900 = v824->cache_vals;
      int v1304 = ((4 + ((((int)((unsigned int)((int)((unsigned int)v826 >> 2)) >> 1)) & 3) * 2)) + ((((v874 + ((~(((v876 ^ -1) | (-(v876 ^ -1))) >> 31)) & 2)) - (v878 + ((~(((v880 ^ -1) | (-(v880 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
      v900[v1304] = v897;
      int * v902 = v824->cache_vals;
      int v1307 = (((4 + ((((int)((unsigned int)((int)((unsigned int)v826 >> 2)) >> 1)) & 3) * 2)) + ((((v874 + ((~(((v876 ^ -1) | (-(v876 ^ -1))) >> 31)) & 2)) - (v878 + ((~(((v880 ^ -1) | (-(v880 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
      v902[v1307] = v899;
      int * v904 = v824->cache_tags;
      int v1310 = (int)((unsigned int)((int)((unsigned int)v826 >> 2)) >> 1);
      v904[v1284] = v1310;
      int * v906 = v824->cache_dirty;
      v906[v1284] = 0;
      int * v908 = v824->cache_age;
      v908[v1284] = 1;
      int * v910 = v824->cache_age;
      int v911 = v910[v1284];
      int * v912 = v824->cache_age;
      int v913 = v912[v1247];
      int * v914 = v824->cache_age;
      int v1318 = v913 + ((int)((unsigned int)(v913 - v911) >> 31));
      v914[v1247] = v1318;
      int * v916 = v824->cache_age;
      int v917 = v916[v1249];
      int * v918 = v824->cache_age;
      int v1321 = v917 + ((int)((unsigned int)(v917 - v911) >> 31));
      v918[v1249] = v1321;
      int * v920 = v824->cache_age;
      v920[v1284] = 0;
      v923 = v1284;
    }
    int * v924 = v824->cache_vals;
    int v1324 = v923 * 2;
    int v925 = v924[v1324];
    int * v926 = v824->cache_vals;
    int v1326 = (v923 * 2) + 1;
    int v927 = v926[v1326];
    int * v928 = v824->cache_vals;
    int v1328 = (((((int)((unsigned int)((int)((unsigned int)v826 >> 2)) >> 1)) & 1) * 2) + ((((v853 + ((~(((v855 ^ -1) | (-(v855 ^ -1))) >> 31)) & 2)) - (v857 + ((~(((v859 ^ -1) | (-(v859 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
    v928[v1328] = v925;
    int * v930 = v824->cache_vals;
    int v1331 = ((((((int)((unsigned int)((int)((unsigned int)v826 >> 2)) >> 1)) & 1) * 2) + ((((v853 + ((~(((v855 ^ -1) | (-(v855 ^ -1))) >> 31)) & 2)) - (v857 + ((~(((v859 ^ -1) | (-(v859 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
    v930[v1331] = v927;
    int * v932 = v824->cache_tags;
    int v1334 = ((((int)((unsigned int)((int)((unsigned int)v826 >> 2)) >> 1)) & 1) * 2) + ((((v853 + ((~(((v855 ^ -1) | (-(v855 ^ -1))) >> 31)) & 2)) - (v857 + ((~(((v859 ^ -1) | (-(v859 ^ -1))) >> 31)) & 2))) >> 31) & 1);
    int v1335 = (int)((unsigned int)((int)((unsigned int)v826 >> 2)) >> 1);
    v932[v1334] = v1335;
    int * v934 = v824->cache_dirty;
    v934[v1334] = 0;
    int * v936 = v824->cache_age;
    v936[v1334] = 1;
    int * v938 = v824->cache_age;
    int v939 = v938[v1334];
    int * v940 = v824->cache_age;
    int v941 = v940[v1243];
    int * v942 = v824->cache_age;
    int v1343 = v941 + ((int)((unsigned int)(v941 - v939) >> 31));
    v942[v1243] = v1343;
    int * v944 = v824->cache_age;
    int v945 = v944[v1245];
    int * v946 = v824->cache_age;
    int v1346 = v945 + ((int)((unsigned int)(v945 - v939) >> 31));
    v946[v1245] = v1346;
    int * v948 = v824->cache_age;
    v948[v1334] = 0;
    v951 = v1334;
  }
  int * v952 = v824->cache_vals;
  int v1349 = (v951 * 2) + (((int)((unsigned int)v826 >> 2)) & 1);
  v952[v1349] = v828;
  int * v954 = v824->cache_tags;
  int v955 = v954[v1247];
  int * v956 = v824->cache_tags;
  int v957 = v956[v1249];
  bool v1353 = !(((~(((v955 ^ ((int)((unsigned int)((int)((unsigned int)v826 >> 2)) >> 1))) | (-(v955 ^ ((int)((unsigned int)((int)((unsigned int)v826 >> 2)) >> 1))))) >> 31)) | (~(((v957 ^ ((int)((unsigned int)((int)((unsigned int)v826 >> 2)) >> 1))) | (-(v957 ^ ((int)((unsigned int)((int)((unsigned int)v826 >> 2)) >> 1))))) >> 31))) == 0);
  int v1021;
  if (v1353) {
    int * v958 = v824->cache_age;
    int v1355 = (4 + ((((int)((unsigned int)((int)((unsigned int)v826 >> 2)) >> 1)) & 3) * 2)) + ((~(((v957 ^ ((int)((unsigned int)((int)((unsigned int)v826 >> 2)) >> 1))) | (-(v957 ^ ((int)((unsigned int)((int)((unsigned int)v826 >> 2)) >> 1))))) >> 31)) & 1);
    int v959 = v958[v1355];
    int * v960 = v824->cache_age;
    int v961 = v960[v1247];
    int * v962 = v824->cache_age;
    int v1358 = v961 + ((int)((unsigned int)(v961 - v959) >> 31));
    v962[v1247] = v1358;
    int * v964 = v824->cache_age;
    int v965 = v964[v1249];
    int * v966 = v824->cache_age;
    int v1361 = v965 + ((int)((unsigned int)(v965 - v959) >> 31));
    v966[v1249] = v1361;
    int * v968 = v824->cache_age;
    v968[v1355] = 0;
    v1021 = v1355;
  } else {
    int * v971 = v824->cache_age;
    int v1365 = 4 + ((((int)((unsigned int)((int)((unsigned int)v826 >> 2)) >> 1)) & 3) * 2);
    int v972 = v971[v1365];
    int * v973 = v824->cache_tags;
    int v974 = v973[v1365];
    int * v975 = v824->cache_age;
    int v976 = v975[v1249];
    int * v977 = v824->cache_tags;
    int v978 = v977[v1249];
    int * v979 = v824->cache_dirty;
    int v1370 = (4 + ((((int)((unsigned int)((int)((unsigned int)v826 >> 2)) >> 1)) & 3) * 2)) + ((((v972 + ((~(((v974 ^ -1) | (-(v974 ^ -1))) >> 31)) & 2)) - (v976 + ((~(((v978 ^ -1) | (-(v978 ^ -1))) >> 31)) & 2))) >> 31) & 1);
    int v980 = v979[v1370];
    bool v1371 = !(v980 == 0);
    if (v1371) {
      int * v981 = v824->cache_tags;
      int v982 = v981[v1370];
      int * v983 = v824->cache_vals;
      int v1374 = ((4 + ((((int)((unsigned int)((int)((unsigned int)v826 >> 2)) >> 1)) & 3) * 2)) + ((((v972 + ((~(((v974 ^ -1) | (-(v974 ^ -1))) >> 31)) & 2)) - (v976 + ((~(((v978 ^ -1) | (-(v978 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
      int v984 = v983[v1374];
      int * v985 = v824->cache_vals;
      int v1376 = (((4 + ((((int)((unsigned int)((int)((unsigned int)v826 >> 2)) >> 1)) & 3) * 2)) + ((((v972 + ((~(((v974 ^ -1) | (-(v974 ^ -1))) >> 31)) & 2)) - (v976 + ((~(((v978 ^ -1) | (-(v978 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
      int v986 = v985[v1376];
      int * v987 = v824->mem;
      int v1378 = v982 * 2;
      v987[v1378] = v984;
      int * v989 = v824->mem;
      int v1381 = (v982 * 2) + 1;
      v989[v1381] = v986;
      ;
    } else {
      ;
    }
    int * v994 = v824->mem;
    int v1386 = ((int)((unsigned int)((int)((unsigned int)v826 >> 2)) >> 1)) * 2;
    int v995 = v994[v1386];
    int * v996 = v824->mem;
    int v1388 = (((int)((unsigned int)((int)((unsigned int)v826 >> 2)) >> 1)) * 2) + 1;
    int v997 = v996[v1388];
    int * v998 = v824->cache_vals;
    int v1390 = ((4 + ((((int)((unsigned int)((int)((unsigned int)v826 >> 2)) >> 1)) & 3) * 2)) + ((((v972 + ((~(((v974 ^ -1) | (-(v974 ^ -1))) >> 31)) & 2)) - (v976 + ((~(((v978 ^ -1) | (-(v978 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
    v998[v1390] = v995;
    int * v1000 = v824->cache_vals;
    int v1393 = (((4 + ((((int)((unsigned int)((int)((unsigned int)v826 >> 2)) >> 1)) & 3) * 2)) + ((((v972 + ((~(((v974 ^ -1) | (-(v974 ^ -1))) >> 31)) & 2)) - (v976 + ((~(((v978 ^ -1) | (-(v978 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
    v1000[v1393] = v997;
    int * v1002 = v824->cache_tags;
    int v1396 = (int)((unsigned int)((int)((unsigned int)v826 >> 2)) >> 1);
    v1002[v1370] = v1396;
    int * v1004 = v824->cache_dirty;
    v1004[v1370] = 0;
    int * v1006 = v824->cache_age;
    v1006[v1370] = 1;
    int * v1008 = v824->cache_age;
    int v1009 = v1008[v1370];
    int * v1010 = v824->cache_age;
    int v1011 = v1010[v1247];
    int * v1012 = v824->cache_age;
    int v1404 = v1011 + ((int)((unsigned int)(v1011 - v1009) >> 31));
    v1012[v1247] = v1404;
    int * v1014 = v824->cache_age;
    int v1015 = v1014[v1249];
    int * v1016 = v824->cache_age;
    int v1407 = v1015 + ((int)((unsigned int)(v1015 - v1009) >> 31));
    v1016[v1249] = v1407;
    int * v1018 = v824->cache_age;
    v1018[v1370] = 0;
    v1021 = v1370;
  }
  int * v1022 = v824->cache_vals;
  int v1410 = (v1021 * 2) + (((int)((unsigned int)v826 >> 2)) & 1);
  v1022[v1410] = v828;
  int * v1024 = v824->cache_dirty;
  v1024[v1021] = 1;
  struct StateT * v1026 = v811->b;
  int * v1027 = v1026->regs;
  int v1028 = v1027[6];
  int * v1029 = v1026->regs;
  int v1030 = v1029[5];
  int * v1031 = v1026->cache_tags;
  int v1418 = (((int)((unsigned int)((int)((unsigned int)v1028 >> 2)) >> 1)) & 1) * 2;
  int v1032 = v1031[v1418];
  int * v1033 = v1026->cache_tags;
  int v1420 = ((((int)((unsigned int)((int)((unsigned int)v1028 >> 2)) >> 1)) & 1) * 2) + 1;
  int v1034 = v1033[v1420];
  int * v1035 = v1026->cache_tags;
  int v1422 = 4 + ((((int)((unsigned int)((int)((unsigned int)v1028 >> 2)) >> 1)) & 3) * 2);
  int v1036 = v1035[v1422];
  int * v1037 = v1026->cache_tags;
  int v1424 = (4 + ((((int)((unsigned int)((int)((unsigned int)v1028 >> 2)) >> 1)) & 3) * 2)) + 1;
  int v1038 = v1037[v1424];
  int v1039 = v1026->timer;
  int v1425 = v1039 + ((100 ^ (((~(((v1036 ^ ((int)((unsigned int)((int)((unsigned int)v1028 >> 2)) >> 1))) | (-(v1036 ^ ((int)((unsigned int)((int)((unsigned int)v1028 >> 2)) >> 1))))) >> 31)) | (~(((v1038 ^ ((int)((unsigned int)((int)((unsigned int)v1028 >> 2)) >> 1))) | (-(v1038 ^ ((int)((unsigned int)((int)((unsigned int)v1028 >> 2)) >> 1))))) >> 31))) & 104)) ^ (((~(((v1032 ^ ((int)((unsigned int)((int)((unsigned int)v1028 >> 2)) >> 1))) | (-(v1032 ^ ((int)((unsigned int)((int)((unsigned int)v1028 >> 2)) >> 1))))) >> 31)) | (~(((v1034 ^ ((int)((unsigned int)((int)((unsigned int)v1028 >> 2)) >> 1))) | (-(v1034 ^ ((int)((unsigned int)((int)((unsigned int)v1028 >> 2)) >> 1))))) >> 31))) & (1 ^ (100 ^ (((~(((v1036 ^ ((int)((unsigned int)((int)((unsigned int)v1028 >> 2)) >> 1))) | (-(v1036 ^ ((int)((unsigned int)((int)((unsigned int)v1028 >> 2)) >> 1))))) >> 31)) | (~(((v1038 ^ ((int)((unsigned int)((int)((unsigned int)v1028 >> 2)) >> 1))) | (-(v1038 ^ ((int)((unsigned int)((int)((unsigned int)v1028 >> 2)) >> 1))))) >> 31))) & 104)))));
  v1026->timer = v1425;
  bool v1426 = !(((~(((v1032 ^ ((int)((unsigned int)((int)((unsigned int)v1028 >> 2)) >> 1))) | (-(v1032 ^ ((int)((unsigned int)((int)((unsigned int)v1028 >> 2)) >> 1))))) >> 31)) | (~(((v1034 ^ ((int)((unsigned int)((int)((unsigned int)v1028 >> 2)) >> 1))) | (-(v1034 ^ ((int)((unsigned int)((int)((unsigned int)v1028 >> 2)) >> 1))))) >> 31))) == 0);
  int v1153;
  if (v1426) {
    int * v1041 = v1026->cache_age;
    int v1428 = ((((int)((unsigned int)((int)((unsigned int)v1028 >> 2)) >> 1)) & 1) * 2) + ((~(((v1034 ^ ((int)((unsigned int)((int)((unsigned int)v1028 >> 2)) >> 1))) | (-(v1034 ^ ((int)((unsigned int)((int)((unsigned int)v1028 >> 2)) >> 1))))) >> 31)) & 1);
    int v1042 = v1041[v1428];
    int * v1043 = v1026->cache_age;
    int v1044 = v1043[v1418];
    int * v1045 = v1026->cache_age;
    int v1431 = v1044 + ((int)((unsigned int)(v1044 - v1042) >> 31));
    v1045[v1418] = v1431;
    int * v1047 = v1026->cache_age;
    int v1048 = v1047[v1420];
    int * v1049 = v1026->cache_age;
    int v1434 = v1048 + ((int)((unsigned int)(v1048 - v1042) >> 31));
    v1049[v1420] = v1434;
    int * v1051 = v1026->cache_age;
    v1051[v1428] = 0;
    v1153 = v1428;
  } else {
    int * v1054 = v1026->cache_age;
    int v1438 = (((int)((unsigned int)((int)((unsigned int)v1028 >> 2)) >> 1)) & 1) * 2;
    int v1055 = v1054[v1438];
    int * v1056 = v1026->cache_tags;
    int v1057 = v1056[v1438];
    int * v1058 = v1026->cache_age;
    int v1059 = v1058[v1420];
    int * v1060 = v1026->cache_tags;
    int v1061 = v1060[v1420];
    bool v1442 = !(((~(((v1036 ^ ((int)((unsigned int)((int)((unsigned int)v1028 >> 2)) >> 1))) | (-(v1036 ^ ((int)((unsigned int)((int)((unsigned int)v1028 >> 2)) >> 1))))) >> 31)) | (~(((v1038 ^ ((int)((unsigned int)((int)((unsigned int)v1028 >> 2)) >> 1))) | (-(v1038 ^ ((int)((unsigned int)((int)((unsigned int)v1028 >> 2)) >> 1))))) >> 31))) == 0);
    int v1125;
    if (v1442) {
      int * v1062 = v1026->cache_age;
      int v1444 = (4 + ((((int)((unsigned int)((int)((unsigned int)v1028 >> 2)) >> 1)) & 3) * 2)) + ((~(((v1038 ^ ((int)((unsigned int)((int)((unsigned int)v1028 >> 2)) >> 1))) | (-(v1038 ^ ((int)((unsigned int)((int)((unsigned int)v1028 >> 2)) >> 1))))) >> 31)) & 1);
      int v1063 = v1062[v1444];
      int * v1064 = v1026->cache_age;
      int v1065 = v1064[v1422];
      int * v1066 = v1026->cache_age;
      int v1447 = v1065 + ((int)((unsigned int)(v1065 - v1063) >> 31));
      v1066[v1422] = v1447;
      int * v1068 = v1026->cache_age;
      int v1069 = v1068[v1424];
      int * v1070 = v1026->cache_age;
      int v1450 = v1069 + ((int)((unsigned int)(v1069 - v1063) >> 31));
      v1070[v1424] = v1450;
      int * v1072 = v1026->cache_age;
      v1072[v1444] = 0;
      v1125 = v1444;
    } else {
      int * v1075 = v1026->cache_age;
      int v1454 = 4 + ((((int)((unsigned int)((int)((unsigned int)v1028 >> 2)) >> 1)) & 3) * 2);
      int v1076 = v1075[v1454];
      int * v1077 = v1026->cache_tags;
      int v1078 = v1077[v1454];
      int * v1079 = v1026->cache_age;
      int v1080 = v1079[v1424];
      int * v1081 = v1026->cache_tags;
      int v1082 = v1081[v1424];
      int * v1083 = v1026->cache_dirty;
      int v1459 = (4 + ((((int)((unsigned int)((int)((unsigned int)v1028 >> 2)) >> 1)) & 3) * 2)) + ((((v1076 + ((~(((v1078 ^ -1) | (-(v1078 ^ -1))) >> 31)) & 2)) - (v1080 + ((~(((v1082 ^ -1) | (-(v1082 ^ -1))) >> 31)) & 2))) >> 31) & 1);
      int v1084 = v1083[v1459];
      bool v1460 = !(v1084 == 0);
      if (v1460) {
        int * v1085 = v1026->cache_tags;
        int v1086 = v1085[v1459];
        int * v1087 = v1026->cache_vals;
        int v1463 = ((4 + ((((int)((unsigned int)((int)((unsigned int)v1028 >> 2)) >> 1)) & 3) * 2)) + ((((v1076 + ((~(((v1078 ^ -1) | (-(v1078 ^ -1))) >> 31)) & 2)) - (v1080 + ((~(((v1082 ^ -1) | (-(v1082 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
        int v1088 = v1087[v1463];
        int * v1089 = v1026->cache_vals;
        int v1465 = (((4 + ((((int)((unsigned int)((int)((unsigned int)v1028 >> 2)) >> 1)) & 3) * 2)) + ((((v1076 + ((~(((v1078 ^ -1) | (-(v1078 ^ -1))) >> 31)) & 2)) - (v1080 + ((~(((v1082 ^ -1) | (-(v1082 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
        int v1090 = v1089[v1465];
        int * v1091 = v1026->mem;
        int v1467 = v1086 * 2;
        v1091[v1467] = v1088;
        int * v1093 = v1026->mem;
        int v1470 = (v1086 * 2) + 1;
        v1093[v1470] = v1090;
        ;
      } else {
        ;
      }
      int * v1098 = v1026->mem;
      int v1475 = ((int)((unsigned int)((int)((unsigned int)v1028 >> 2)) >> 1)) * 2;
      int v1099 = v1098[v1475];
      int * v1100 = v1026->mem;
      int v1477 = (((int)((unsigned int)((int)((unsigned int)v1028 >> 2)) >> 1)) * 2) + 1;
      int v1101 = v1100[v1477];
      int * v1102 = v1026->cache_vals;
      int v1479 = ((4 + ((((int)((unsigned int)((int)((unsigned int)v1028 >> 2)) >> 1)) & 3) * 2)) + ((((v1076 + ((~(((v1078 ^ -1) | (-(v1078 ^ -1))) >> 31)) & 2)) - (v1080 + ((~(((v1082 ^ -1) | (-(v1082 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
      v1102[v1479] = v1099;
      int * v1104 = v1026->cache_vals;
      int v1482 = (((4 + ((((int)((unsigned int)((int)((unsigned int)v1028 >> 2)) >> 1)) & 3) * 2)) + ((((v1076 + ((~(((v1078 ^ -1) | (-(v1078 ^ -1))) >> 31)) & 2)) - (v1080 + ((~(((v1082 ^ -1) | (-(v1082 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
      v1104[v1482] = v1101;
      int * v1106 = v1026->cache_tags;
      int v1485 = (int)((unsigned int)((int)((unsigned int)v1028 >> 2)) >> 1);
      v1106[v1459] = v1485;
      int * v1108 = v1026->cache_dirty;
      v1108[v1459] = 0;
      int * v1110 = v1026->cache_age;
      v1110[v1459] = 1;
      int * v1112 = v1026->cache_age;
      int v1113 = v1112[v1459];
      int * v1114 = v1026->cache_age;
      int v1115 = v1114[v1422];
      int * v1116 = v1026->cache_age;
      int v1492 = v1115 + ((int)((unsigned int)(v1115 - v1113) >> 31));
      v1116[v1422] = v1492;
      int * v1118 = v1026->cache_age;
      int v1119 = v1118[v1424];
      int * v1120 = v1026->cache_age;
      int v1495 = v1119 + ((int)((unsigned int)(v1119 - v1113) >> 31));
      v1120[v1424] = v1495;
      int * v1122 = v1026->cache_age;
      v1122[v1459] = 0;
      v1125 = v1459;
    }
    int * v1126 = v1026->cache_vals;
    int v1498 = v1125 * 2;
    int v1127 = v1126[v1498];
    int * v1128 = v1026->cache_vals;
    int v1500 = (v1125 * 2) + 1;
    int v1129 = v1128[v1500];
    int * v1130 = v1026->cache_vals;
    int v1502 = (((((int)((unsigned int)((int)((unsigned int)v1028 >> 2)) >> 1)) & 1) * 2) + ((((v1055 + ((~(((v1057 ^ -1) | (-(v1057 ^ -1))) >> 31)) & 2)) - (v1059 + ((~(((v1061 ^ -1) | (-(v1061 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
    v1130[v1502] = v1127;
    int * v1132 = v1026->cache_vals;
    int v1505 = ((((((int)((unsigned int)((int)((unsigned int)v1028 >> 2)) >> 1)) & 1) * 2) + ((((v1055 + ((~(((v1057 ^ -1) | (-(v1057 ^ -1))) >> 31)) & 2)) - (v1059 + ((~(((v1061 ^ -1) | (-(v1061 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
    v1132[v1505] = v1129;
    int * v1134 = v1026->cache_tags;
    int v1508 = ((((int)((unsigned int)((int)((unsigned int)v1028 >> 2)) >> 1)) & 1) * 2) + ((((v1055 + ((~(((v1057 ^ -1) | (-(v1057 ^ -1))) >> 31)) & 2)) - (v1059 + ((~(((v1061 ^ -1) | (-(v1061 ^ -1))) >> 31)) & 2))) >> 31) & 1);
    int v1509 = (int)((unsigned int)((int)((unsigned int)v1028 >> 2)) >> 1);
    v1134[v1508] = v1509;
    int * v1136 = v1026->cache_dirty;
    v1136[v1508] = 0;
    int * v1138 = v1026->cache_age;
    v1138[v1508] = 1;
    int * v1140 = v1026->cache_age;
    int v1141 = v1140[v1508];
    int * v1142 = v1026->cache_age;
    int v1143 = v1142[v1418];
    int * v1144 = v1026->cache_age;
    int v1516 = v1143 + ((int)((unsigned int)(v1143 - v1141) >> 31));
    v1144[v1418] = v1516;
    int * v1146 = v1026->cache_age;
    int v1147 = v1146[v1420];
    int * v1148 = v1026->cache_age;
    int v1519 = v1147 + ((int)((unsigned int)(v1147 - v1141) >> 31));
    v1148[v1420] = v1519;
    int * v1150 = v1026->cache_age;
    v1150[v1508] = 0;
    v1153 = v1508;
  }
  int * v1154 = v1026->cache_vals;
  int v1522 = (v1153 * 2) + (((int)((unsigned int)v1028 >> 2)) & 1);
  v1154[v1522] = v1030;
  int * v1156 = v1026->cache_tags;
  int v1157 = v1156[v1422];
  int * v1158 = v1026->cache_tags;
  int v1159 = v1158[v1424];
  bool v1526 = !(((~(((v1157 ^ ((int)((unsigned int)((int)((unsigned int)v1028 >> 2)) >> 1))) | (-(v1157 ^ ((int)((unsigned int)((int)((unsigned int)v1028 >> 2)) >> 1))))) >> 31)) | (~(((v1159 ^ ((int)((unsigned int)((int)((unsigned int)v1028 >> 2)) >> 1))) | (-(v1159 ^ ((int)((unsigned int)((int)((unsigned int)v1028 >> 2)) >> 1))))) >> 31))) == 0);
  int v1223;
  if (v1526) {
    int * v1160 = v1026->cache_age;
    int v1528 = (4 + ((((int)((unsigned int)((int)((unsigned int)v1028 >> 2)) >> 1)) & 3) * 2)) + ((~(((v1159 ^ ((int)((unsigned int)((int)((unsigned int)v1028 >> 2)) >> 1))) | (-(v1159 ^ ((int)((unsigned int)((int)((unsigned int)v1028 >> 2)) >> 1))))) >> 31)) & 1);
    int v1161 = v1160[v1528];
    int * v1162 = v1026->cache_age;
    int v1163 = v1162[v1422];
    int * v1164 = v1026->cache_age;
    int v1531 = v1163 + ((int)((unsigned int)(v1163 - v1161) >> 31));
    v1164[v1422] = v1531;
    int * v1166 = v1026->cache_age;
    int v1167 = v1166[v1424];
    int * v1168 = v1026->cache_age;
    int v1534 = v1167 + ((int)((unsigned int)(v1167 - v1161) >> 31));
    v1168[v1424] = v1534;
    int * v1170 = v1026->cache_age;
    v1170[v1528] = 0;
    v1223 = v1528;
  } else {
    int * v1173 = v1026->cache_age;
    int v1538 = 4 + ((((int)((unsigned int)((int)((unsigned int)v1028 >> 2)) >> 1)) & 3) * 2);
    int v1174 = v1173[v1538];
    int * v1175 = v1026->cache_tags;
    int v1176 = v1175[v1538];
    int * v1177 = v1026->cache_age;
    int v1178 = v1177[v1424];
    int * v1179 = v1026->cache_tags;
    int v1180 = v1179[v1424];
    int * v1181 = v1026->cache_dirty;
    int v1543 = (4 + ((((int)((unsigned int)((int)((unsigned int)v1028 >> 2)) >> 1)) & 3) * 2)) + ((((v1174 + ((~(((v1176 ^ -1) | (-(v1176 ^ -1))) >> 31)) & 2)) - (v1178 + ((~(((v1180 ^ -1) | (-(v1180 ^ -1))) >> 31)) & 2))) >> 31) & 1);
    int v1182 = v1181[v1543];
    bool v1544 = !(v1182 == 0);
    if (v1544) {
      int * v1183 = v1026->cache_tags;
      int v1184 = v1183[v1543];
      int * v1185 = v1026->cache_vals;
      int v1547 = ((4 + ((((int)((unsigned int)((int)((unsigned int)v1028 >> 2)) >> 1)) & 3) * 2)) + ((((v1174 + ((~(((v1176 ^ -1) | (-(v1176 ^ -1))) >> 31)) & 2)) - (v1178 + ((~(((v1180 ^ -1) | (-(v1180 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
      int v1186 = v1185[v1547];
      int * v1187 = v1026->cache_vals;
      int v1549 = (((4 + ((((int)((unsigned int)((int)((unsigned int)v1028 >> 2)) >> 1)) & 3) * 2)) + ((((v1174 + ((~(((v1176 ^ -1) | (-(v1176 ^ -1))) >> 31)) & 2)) - (v1178 + ((~(((v1180 ^ -1) | (-(v1180 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
      int v1188 = v1187[v1549];
      int * v1189 = v1026->mem;
      int v1551 = v1184 * 2;
      v1189[v1551] = v1186;
      int * v1191 = v1026->mem;
      int v1554 = (v1184 * 2) + 1;
      v1191[v1554] = v1188;
      ;
    } else {
      ;
    }
    int * v1196 = v1026->mem;
    int v1559 = ((int)((unsigned int)((int)((unsigned int)v1028 >> 2)) >> 1)) * 2;
    int v1197 = v1196[v1559];
    int * v1198 = v1026->mem;
    int v1561 = (((int)((unsigned int)((int)((unsigned int)v1028 >> 2)) >> 1)) * 2) + 1;
    int v1199 = v1198[v1561];
    int * v1200 = v1026->cache_vals;
    int v1563 = ((4 + ((((int)((unsigned int)((int)((unsigned int)v1028 >> 2)) >> 1)) & 3) * 2)) + ((((v1174 + ((~(((v1176 ^ -1) | (-(v1176 ^ -1))) >> 31)) & 2)) - (v1178 + ((~(((v1180 ^ -1) | (-(v1180 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
    v1200[v1563] = v1197;
    int * v1202 = v1026->cache_vals;
    int v1566 = (((4 + ((((int)((unsigned int)((int)((unsigned int)v1028 >> 2)) >> 1)) & 3) * 2)) + ((((v1174 + ((~(((v1176 ^ -1) | (-(v1176 ^ -1))) >> 31)) & 2)) - (v1178 + ((~(((v1180 ^ -1) | (-(v1180 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
    v1202[v1566] = v1199;
    int * v1204 = v1026->cache_tags;
    int v1569 = (int)((unsigned int)((int)((unsigned int)v1028 >> 2)) >> 1);
    v1204[v1543] = v1569;
    int * v1206 = v1026->cache_dirty;
    v1206[v1543] = 0;
    int * v1208 = v1026->cache_age;
    v1208[v1543] = 1;
    int * v1210 = v1026->cache_age;
    int v1211 = v1210[v1543];
    int * v1212 = v1026->cache_age;
    int v1213 = v1212[v1422];
    int * v1214 = v1026->cache_age;
    int v1576 = v1213 + ((int)((unsigned int)(v1213 - v1211) >> 31));
    v1214[v1422] = v1576;
    int * v1216 = v1026->cache_age;
    int v1217 = v1216[v1424];
    int * v1218 = v1026->cache_age;
    int v1579 = v1217 + ((int)((unsigned int)(v1217 - v1211) >> 31));
    v1218[v1424] = v1579;
    int * v1220 = v1026->cache_age;
    v1220[v1543] = 0;
    v1223 = v1543;
  }
  int * v1224 = v1026->cache_vals;
  int v1582 = (v1223 * 2) + (((int)((unsigned int)v1028 >> 2)) & 1);
  v1224[v1582] = v1030;
  int * v1226 = v1026->cache_dirty;
  v1226[v1223] = 1;
  struct StateT2 * v1228 = slot_9(v811);
  return v1228;
}

struct StateT2 * slot_4(struct StateT2 * v134) {
  struct StateT * v135 = v134->a;
  int v136 = v135->timer;
  struct StateT * v137 = v134->b;
  int v138 = v137->timer;
  bool v175 = v136 == v138;
  squared_assert(v175);
  squared_assume(v175);
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
  int v186 = v152 + 1;
  v151->timer = v186;
  struct StateT * v154 = v134->b;
  int v155 = v154->timer;
  int v188 = v155 + 1;
  v154->timer = v188;
  struct StateT * v157 = v134->a;
  int * v158 = v157->regs;
  int v159 = v158[9];
  int * v160 = v157->regs;
  int v161 = v160[6];
  int * v162 = v157->regs;
  int v195 = v159 + v161;
  v162[8] = v195;
  struct StateT * v164 = v134->b;
  int * v165 = v164->regs;
  int v166 = v165[9];
  int * v167 = v164->regs;
  int v168 = v167[6];
  int * v169 = v164->regs;
  int v200 = v166 + v168;
  v169[8] = v200;
  struct StateT2 * v171 = slot_5(v134);
  return v171;
}

struct StateT2 * slot_9(struct StateT2 * v1587) {
  struct StateT * v1588 = v1587->a;
  int v1589 = v1588->timer;
  struct StateT * v1590 = v1587->b;
  int v1591 = v1590->timer;
  bool v1864 = v1589 == v1591;
  squared_assert(v1864);
  squared_assume(v1864);
  struct StateT * v1594 = v1587->a;
  int v1595 = v1594->timer;
  int v1866 = v1595 + 1;
  v1594->timer = v1866;
  struct StateT * v1597 = v1587->b;
  int v1598 = v1597->timer;
  int v1868 = v1598 + 1;
  v1597->timer = v1868;
  struct StateT * v1600 = v1587->a;
  int * v1601 = v1600->regs;
  int v1602 = v1601[6];
  int * v1603 = v1600->cache_tags;
  int v1873 = (((int)((unsigned int)((int)((unsigned int)v1602 >> 2)) >> 1)) & 1) * 2;
  int v1604 = v1603[v1873];
  int * v1605 = v1600->cache_tags;
  int v1875 = ((((int)((unsigned int)((int)((unsigned int)v1602 >> 2)) >> 1)) & 1) * 2) + 1;
  int v1606 = v1605[v1875];
  int * v1607 = v1600->cache_tags;
  int v1877 = 4 + ((((int)((unsigned int)((int)((unsigned int)v1602 >> 2)) >> 1)) & 3) * 2);
  int v1608 = v1607[v1877];
  int * v1609 = v1600->cache_tags;
  int v1879 = (4 + ((((int)((unsigned int)((int)((unsigned int)v1602 >> 2)) >> 1)) & 3) * 2)) + 1;
  int v1610 = v1609[v1879];
  int v1611 = v1600->timer;
  int v1880 = v1611 + ((100 ^ (((~(((v1608 ^ ((int)((unsigned int)((int)((unsigned int)v1602 >> 2)) >> 1))) | (-(v1608 ^ ((int)((unsigned int)((int)((unsigned int)v1602 >> 2)) >> 1))))) >> 31)) | (~(((v1610 ^ ((int)((unsigned int)((int)((unsigned int)v1602 >> 2)) >> 1))) | (-(v1610 ^ ((int)((unsigned int)((int)((unsigned int)v1602 >> 2)) >> 1))))) >> 31))) & 104)) ^ (((~(((v1604 ^ ((int)((unsigned int)((int)((unsigned int)v1602 >> 2)) >> 1))) | (-(v1604 ^ ((int)((unsigned int)((int)((unsigned int)v1602 >> 2)) >> 1))))) >> 31)) | (~(((v1606 ^ ((int)((unsigned int)((int)((unsigned int)v1602 >> 2)) >> 1))) | (-(v1606 ^ ((int)((unsigned int)((int)((unsigned int)v1602 >> 2)) >> 1))))) >> 31))) & (1 ^ (100 ^ (((~(((v1608 ^ ((int)((unsigned int)((int)((unsigned int)v1602 >> 2)) >> 1))) | (-(v1608 ^ ((int)((unsigned int)((int)((unsigned int)v1602 >> 2)) >> 1))))) >> 31)) | (~(((v1610 ^ ((int)((unsigned int)((int)((unsigned int)v1602 >> 2)) >> 1))) | (-(v1610 ^ ((int)((unsigned int)((int)((unsigned int)v1602 >> 2)) >> 1))))) >> 31))) & 104)))));
  v1600->timer = v1880;
  int * v1613 = v1600->cache_vals;
  bool v1881 = !(((~(((v1604 ^ ((int)((unsigned int)((int)((unsigned int)v1602 >> 2)) >> 1))) | (-(v1604 ^ ((int)((unsigned int)((int)((unsigned int)v1602 >> 2)) >> 1))))) >> 31)) | (~(((v1606 ^ ((int)((unsigned int)((int)((unsigned int)v1602 >> 2)) >> 1))) | (-(v1606 ^ ((int)((unsigned int)((int)((unsigned int)v1602 >> 2)) >> 1))))) >> 31))) == 0);
  int v1726;
  if (v1881) {
    int * v1614 = v1600->cache_age;
    int v1883 = ((((int)((unsigned int)((int)((unsigned int)v1602 >> 2)) >> 1)) & 1) * 2) + ((~(((v1606 ^ ((int)((unsigned int)((int)((unsigned int)v1602 >> 2)) >> 1))) | (-(v1606 ^ ((int)((unsigned int)((int)((unsigned int)v1602 >> 2)) >> 1))))) >> 31)) & 1);
    int v1615 = v1614[v1883];
    int * v1616 = v1600->cache_age;
    int v1617 = v1616[v1873];
    int * v1618 = v1600->cache_age;
    int v1886 = v1617 + ((int)((unsigned int)(v1617 - v1615) >> 31));
    v1618[v1873] = v1886;
    int * v1620 = v1600->cache_age;
    int v1621 = v1620[v1875];
    int * v1622 = v1600->cache_age;
    int v1889 = v1621 + ((int)((unsigned int)(v1621 - v1615) >> 31));
    v1622[v1875] = v1889;
    int * v1624 = v1600->cache_age;
    v1624[v1883] = 0;
    v1726 = v1883;
  } else {
    int * v1627 = v1600->cache_age;
    int v1893 = (((int)((unsigned int)((int)((unsigned int)v1602 >> 2)) >> 1)) & 1) * 2;
    int v1628 = v1627[v1893];
    int * v1629 = v1600->cache_tags;
    int v1630 = v1629[v1893];
    int * v1631 = v1600->cache_age;
    int v1632 = v1631[v1875];
    int * v1633 = v1600->cache_tags;
    int v1634 = v1633[v1875];
    bool v1897 = !(((~(((v1608 ^ ((int)((unsigned int)((int)((unsigned int)v1602 >> 2)) >> 1))) | (-(v1608 ^ ((int)((unsigned int)((int)((unsigned int)v1602 >> 2)) >> 1))))) >> 31)) | (~(((v1610 ^ ((int)((unsigned int)((int)((unsigned int)v1602 >> 2)) >> 1))) | (-(v1610 ^ ((int)((unsigned int)((int)((unsigned int)v1602 >> 2)) >> 1))))) >> 31))) == 0);
    int v1698;
    if (v1897) {
      int * v1635 = v1600->cache_age;
      int v1899 = (4 + ((((int)((unsigned int)((int)((unsigned int)v1602 >> 2)) >> 1)) & 3) * 2)) + ((~(((v1610 ^ ((int)((unsigned int)((int)((unsigned int)v1602 >> 2)) >> 1))) | (-(v1610 ^ ((int)((unsigned int)((int)((unsigned int)v1602 >> 2)) >> 1))))) >> 31)) & 1);
      int v1636 = v1635[v1899];
      int * v1637 = v1600->cache_age;
      int v1638 = v1637[v1877];
      int * v1639 = v1600->cache_age;
      int v1902 = v1638 + ((int)((unsigned int)(v1638 - v1636) >> 31));
      v1639[v1877] = v1902;
      int * v1641 = v1600->cache_age;
      int v1642 = v1641[v1879];
      int * v1643 = v1600->cache_age;
      int v1905 = v1642 + ((int)((unsigned int)(v1642 - v1636) >> 31));
      v1643[v1879] = v1905;
      int * v1645 = v1600->cache_age;
      v1645[v1899] = 0;
      v1698 = v1899;
    } else {
      int * v1648 = v1600->cache_age;
      int v1909 = 4 + ((((int)((unsigned int)((int)((unsigned int)v1602 >> 2)) >> 1)) & 3) * 2);
      int v1649 = v1648[v1909];
      int * v1650 = v1600->cache_tags;
      int v1651 = v1650[v1909];
      int * v1652 = v1600->cache_age;
      int v1653 = v1652[v1879];
      int * v1654 = v1600->cache_tags;
      int v1655 = v1654[v1879];
      int * v1656 = v1600->cache_dirty;
      int v1914 = (4 + ((((int)((unsigned int)((int)((unsigned int)v1602 >> 2)) >> 1)) & 3) * 2)) + ((((v1649 + ((~(((v1651 ^ -1) | (-(v1651 ^ -1))) >> 31)) & 2)) - (v1653 + ((~(((v1655 ^ -1) | (-(v1655 ^ -1))) >> 31)) & 2))) >> 31) & 1);
      int v1657 = v1656[v1914];
      bool v1915 = !(v1657 == 0);
      if (v1915) {
        int * v1658 = v1600->cache_tags;
        int v1659 = v1658[v1914];
        int * v1660 = v1600->cache_vals;
        int v1918 = ((4 + ((((int)((unsigned int)((int)((unsigned int)v1602 >> 2)) >> 1)) & 3) * 2)) + ((((v1649 + ((~(((v1651 ^ -1) | (-(v1651 ^ -1))) >> 31)) & 2)) - (v1653 + ((~(((v1655 ^ -1) | (-(v1655 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
        int v1661 = v1660[v1918];
        int * v1662 = v1600->cache_vals;
        int v1920 = (((4 + ((((int)((unsigned int)((int)((unsigned int)v1602 >> 2)) >> 1)) & 3) * 2)) + ((((v1649 + ((~(((v1651 ^ -1) | (-(v1651 ^ -1))) >> 31)) & 2)) - (v1653 + ((~(((v1655 ^ -1) | (-(v1655 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
        int v1663 = v1662[v1920];
        int * v1664 = v1600->mem;
        int v1922 = v1659 * 2;
        v1664[v1922] = v1661;
        int * v1666 = v1600->mem;
        int v1925 = (v1659 * 2) + 1;
        v1666[v1925] = v1663;
        ;
      } else {
        ;
      }
      int * v1671 = v1600->mem;
      int v1930 = ((int)((unsigned int)((int)((unsigned int)v1602 >> 2)) >> 1)) * 2;
      int v1672 = v1671[v1930];
      int * v1673 = v1600->mem;
      int v1932 = (((int)((unsigned int)((int)((unsigned int)v1602 >> 2)) >> 1)) * 2) + 1;
      int v1674 = v1673[v1932];
      int * v1675 = v1600->cache_vals;
      int v1934 = ((4 + ((((int)((unsigned int)((int)((unsigned int)v1602 >> 2)) >> 1)) & 3) * 2)) + ((((v1649 + ((~(((v1651 ^ -1) | (-(v1651 ^ -1))) >> 31)) & 2)) - (v1653 + ((~(((v1655 ^ -1) | (-(v1655 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
      v1675[v1934] = v1672;
      int * v1677 = v1600->cache_vals;
      int v1937 = (((4 + ((((int)((unsigned int)((int)((unsigned int)v1602 >> 2)) >> 1)) & 3) * 2)) + ((((v1649 + ((~(((v1651 ^ -1) | (-(v1651 ^ -1))) >> 31)) & 2)) - (v1653 + ((~(((v1655 ^ -1) | (-(v1655 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
      v1677[v1937] = v1674;
      int * v1679 = v1600->cache_tags;
      int v1940 = (int)((unsigned int)((int)((unsigned int)v1602 >> 2)) >> 1);
      v1679[v1914] = v1940;
      int * v1681 = v1600->cache_dirty;
      v1681[v1914] = 0;
      int * v1683 = v1600->cache_age;
      v1683[v1914] = 1;
      int * v1685 = v1600->cache_age;
      int v1686 = v1685[v1914];
      int * v1687 = v1600->cache_age;
      int v1688 = v1687[v1877];
      int * v1689 = v1600->cache_age;
      int v1948 = v1688 + ((int)((unsigned int)(v1688 - v1686) >> 31));
      v1689[v1877] = v1948;
      int * v1691 = v1600->cache_age;
      int v1692 = v1691[v1879];
      int * v1693 = v1600->cache_age;
      int v1951 = v1692 + ((int)((unsigned int)(v1692 - v1686) >> 31));
      v1693[v1879] = v1951;
      int * v1695 = v1600->cache_age;
      v1695[v1914] = 0;
      v1698 = v1914;
    }
    int * v1699 = v1600->cache_vals;
    int v1954 = v1698 * 2;
    int v1700 = v1699[v1954];
    int * v1701 = v1600->cache_vals;
    int v1956 = (v1698 * 2) + 1;
    int v1702 = v1701[v1956];
    int * v1703 = v1600->cache_vals;
    int v1958 = (((((int)((unsigned int)((int)((unsigned int)v1602 >> 2)) >> 1)) & 1) * 2) + ((((v1628 + ((~(((v1630 ^ -1) | (-(v1630 ^ -1))) >> 31)) & 2)) - (v1632 + ((~(((v1634 ^ -1) | (-(v1634 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
    v1703[v1958] = v1700;
    int * v1705 = v1600->cache_vals;
    int v1961 = ((((((int)((unsigned int)((int)((unsigned int)v1602 >> 2)) >> 1)) & 1) * 2) + ((((v1628 + ((~(((v1630 ^ -1) | (-(v1630 ^ -1))) >> 31)) & 2)) - (v1632 + ((~(((v1634 ^ -1) | (-(v1634 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
    v1705[v1961] = v1702;
    int * v1707 = v1600->cache_tags;
    int v1964 = ((((int)((unsigned int)((int)((unsigned int)v1602 >> 2)) >> 1)) & 1) * 2) + ((((v1628 + ((~(((v1630 ^ -1) | (-(v1630 ^ -1))) >> 31)) & 2)) - (v1632 + ((~(((v1634 ^ -1) | (-(v1634 ^ -1))) >> 31)) & 2))) >> 31) & 1);
    int v1965 = (int)((unsigned int)((int)((unsigned int)v1602 >> 2)) >> 1);
    v1707[v1964] = v1965;
    int * v1709 = v1600->cache_dirty;
    v1709[v1964] = 0;
    int * v1711 = v1600->cache_age;
    v1711[v1964] = 1;
    int * v1713 = v1600->cache_age;
    int v1714 = v1713[v1964];
    int * v1715 = v1600->cache_age;
    int v1716 = v1715[v1873];
    int * v1717 = v1600->cache_age;
    int v1973 = v1716 + ((int)((unsigned int)(v1716 - v1714) >> 31));
    v1717[v1873] = v1973;
    int * v1719 = v1600->cache_age;
    int v1720 = v1719[v1875];
    int * v1721 = v1600->cache_age;
    int v1976 = v1720 + ((int)((unsigned int)(v1720 - v1714) >> 31));
    v1721[v1875] = v1976;
    int * v1723 = v1600->cache_age;
    v1723[v1964] = 0;
    v1726 = v1964;
  }
  int v1979 = (v1726 * 2) + (((int)((unsigned int)v1602 >> 2)) & 1);
  int v1727 = v1613[v1979];
  int * v1728 = v1600->regs;
  v1728[11] = v1727;
  struct StateT * v1730 = v1587->b;
  int * v1731 = v1730->regs;
  int v1732 = v1731[6];
  int * v1733 = v1730->cache_tags;
  int v1986 = (((int)((unsigned int)((int)((unsigned int)v1732 >> 2)) >> 1)) & 1) * 2;
  int v1734 = v1733[v1986];
  int * v1735 = v1730->cache_tags;
  int v1988 = ((((int)((unsigned int)((int)((unsigned int)v1732 >> 2)) >> 1)) & 1) * 2) + 1;
  int v1736 = v1735[v1988];
  int * v1737 = v1730->cache_tags;
  int v1990 = 4 + ((((int)((unsigned int)((int)((unsigned int)v1732 >> 2)) >> 1)) & 3) * 2);
  int v1738 = v1737[v1990];
  int * v1739 = v1730->cache_tags;
  int v1992 = (4 + ((((int)((unsigned int)((int)((unsigned int)v1732 >> 2)) >> 1)) & 3) * 2)) + 1;
  int v1740 = v1739[v1992];
  int v1741 = v1730->timer;
  int v1993 = v1741 + ((100 ^ (((~(((v1738 ^ ((int)((unsigned int)((int)((unsigned int)v1732 >> 2)) >> 1))) | (-(v1738 ^ ((int)((unsigned int)((int)((unsigned int)v1732 >> 2)) >> 1))))) >> 31)) | (~(((v1740 ^ ((int)((unsigned int)((int)((unsigned int)v1732 >> 2)) >> 1))) | (-(v1740 ^ ((int)((unsigned int)((int)((unsigned int)v1732 >> 2)) >> 1))))) >> 31))) & 104)) ^ (((~(((v1734 ^ ((int)((unsigned int)((int)((unsigned int)v1732 >> 2)) >> 1))) | (-(v1734 ^ ((int)((unsigned int)((int)((unsigned int)v1732 >> 2)) >> 1))))) >> 31)) | (~(((v1736 ^ ((int)((unsigned int)((int)((unsigned int)v1732 >> 2)) >> 1))) | (-(v1736 ^ ((int)((unsigned int)((int)((unsigned int)v1732 >> 2)) >> 1))))) >> 31))) & (1 ^ (100 ^ (((~(((v1738 ^ ((int)((unsigned int)((int)((unsigned int)v1732 >> 2)) >> 1))) | (-(v1738 ^ ((int)((unsigned int)((int)((unsigned int)v1732 >> 2)) >> 1))))) >> 31)) | (~(((v1740 ^ ((int)((unsigned int)((int)((unsigned int)v1732 >> 2)) >> 1))) | (-(v1740 ^ ((int)((unsigned int)((int)((unsigned int)v1732 >> 2)) >> 1))))) >> 31))) & 104)))));
  v1730->timer = v1993;
  int * v1743 = v1730->cache_vals;
  bool v1994 = !(((~(((v1734 ^ ((int)((unsigned int)((int)((unsigned int)v1732 >> 2)) >> 1))) | (-(v1734 ^ ((int)((unsigned int)((int)((unsigned int)v1732 >> 2)) >> 1))))) >> 31)) | (~(((v1736 ^ ((int)((unsigned int)((int)((unsigned int)v1732 >> 2)) >> 1))) | (-(v1736 ^ ((int)((unsigned int)((int)((unsigned int)v1732 >> 2)) >> 1))))) >> 31))) == 0);
  int v1856;
  if (v1994) {
    int * v1744 = v1730->cache_age;
    int v1996 = ((((int)((unsigned int)((int)((unsigned int)v1732 >> 2)) >> 1)) & 1) * 2) + ((~(((v1736 ^ ((int)((unsigned int)((int)((unsigned int)v1732 >> 2)) >> 1))) | (-(v1736 ^ ((int)((unsigned int)((int)((unsigned int)v1732 >> 2)) >> 1))))) >> 31)) & 1);
    int v1745 = v1744[v1996];
    int * v1746 = v1730->cache_age;
    int v1747 = v1746[v1986];
    int * v1748 = v1730->cache_age;
    int v1999 = v1747 + ((int)((unsigned int)(v1747 - v1745) >> 31));
    v1748[v1986] = v1999;
    int * v1750 = v1730->cache_age;
    int v1751 = v1750[v1988];
    int * v1752 = v1730->cache_age;
    int v2002 = v1751 + ((int)((unsigned int)(v1751 - v1745) >> 31));
    v1752[v1988] = v2002;
    int * v1754 = v1730->cache_age;
    v1754[v1996] = 0;
    v1856 = v1996;
  } else {
    int * v1757 = v1730->cache_age;
    int v2006 = (((int)((unsigned int)((int)((unsigned int)v1732 >> 2)) >> 1)) & 1) * 2;
    int v1758 = v1757[v2006];
    int * v1759 = v1730->cache_tags;
    int v1760 = v1759[v2006];
    int * v1761 = v1730->cache_age;
    int v1762 = v1761[v1988];
    int * v1763 = v1730->cache_tags;
    int v1764 = v1763[v1988];
    bool v2010 = !(((~(((v1738 ^ ((int)((unsigned int)((int)((unsigned int)v1732 >> 2)) >> 1))) | (-(v1738 ^ ((int)((unsigned int)((int)((unsigned int)v1732 >> 2)) >> 1))))) >> 31)) | (~(((v1740 ^ ((int)((unsigned int)((int)((unsigned int)v1732 >> 2)) >> 1))) | (-(v1740 ^ ((int)((unsigned int)((int)((unsigned int)v1732 >> 2)) >> 1))))) >> 31))) == 0);
    int v1828;
    if (v2010) {
      int * v1765 = v1730->cache_age;
      int v2012 = (4 + ((((int)((unsigned int)((int)((unsigned int)v1732 >> 2)) >> 1)) & 3) * 2)) + ((~(((v1740 ^ ((int)((unsigned int)((int)((unsigned int)v1732 >> 2)) >> 1))) | (-(v1740 ^ ((int)((unsigned int)((int)((unsigned int)v1732 >> 2)) >> 1))))) >> 31)) & 1);
      int v1766 = v1765[v2012];
      int * v1767 = v1730->cache_age;
      int v1768 = v1767[v1990];
      int * v1769 = v1730->cache_age;
      int v2015 = v1768 + ((int)((unsigned int)(v1768 - v1766) >> 31));
      v1769[v1990] = v2015;
      int * v1771 = v1730->cache_age;
      int v1772 = v1771[v1992];
      int * v1773 = v1730->cache_age;
      int v2018 = v1772 + ((int)((unsigned int)(v1772 - v1766) >> 31));
      v1773[v1992] = v2018;
      int * v1775 = v1730->cache_age;
      v1775[v2012] = 0;
      v1828 = v2012;
    } else {
      int * v1778 = v1730->cache_age;
      int v2022 = 4 + ((((int)((unsigned int)((int)((unsigned int)v1732 >> 2)) >> 1)) & 3) * 2);
      int v1779 = v1778[v2022];
      int * v1780 = v1730->cache_tags;
      int v1781 = v1780[v2022];
      int * v1782 = v1730->cache_age;
      int v1783 = v1782[v1992];
      int * v1784 = v1730->cache_tags;
      int v1785 = v1784[v1992];
      int * v1786 = v1730->cache_dirty;
      int v2027 = (4 + ((((int)((unsigned int)((int)((unsigned int)v1732 >> 2)) >> 1)) & 3) * 2)) + ((((v1779 + ((~(((v1781 ^ -1) | (-(v1781 ^ -1))) >> 31)) & 2)) - (v1783 + ((~(((v1785 ^ -1) | (-(v1785 ^ -1))) >> 31)) & 2))) >> 31) & 1);
      int v1787 = v1786[v2027];
      bool v2028 = !(v1787 == 0);
      if (v2028) {
        int * v1788 = v1730->cache_tags;
        int v1789 = v1788[v2027];
        int * v1790 = v1730->cache_vals;
        int v2031 = ((4 + ((((int)((unsigned int)((int)((unsigned int)v1732 >> 2)) >> 1)) & 3) * 2)) + ((((v1779 + ((~(((v1781 ^ -1) | (-(v1781 ^ -1))) >> 31)) & 2)) - (v1783 + ((~(((v1785 ^ -1) | (-(v1785 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
        int v1791 = v1790[v2031];
        int * v1792 = v1730->cache_vals;
        int v2033 = (((4 + ((((int)((unsigned int)((int)((unsigned int)v1732 >> 2)) >> 1)) & 3) * 2)) + ((((v1779 + ((~(((v1781 ^ -1) | (-(v1781 ^ -1))) >> 31)) & 2)) - (v1783 + ((~(((v1785 ^ -1) | (-(v1785 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
        int v1793 = v1792[v2033];
        int * v1794 = v1730->mem;
        int v2035 = v1789 * 2;
        v1794[v2035] = v1791;
        int * v1796 = v1730->mem;
        int v2038 = (v1789 * 2) + 1;
        v1796[v2038] = v1793;
        ;
      } else {
        ;
      }
      int * v1801 = v1730->mem;
      int v2043 = ((int)((unsigned int)((int)((unsigned int)v1732 >> 2)) >> 1)) * 2;
      int v1802 = v1801[v2043];
      int * v1803 = v1730->mem;
      int v2045 = (((int)((unsigned int)((int)((unsigned int)v1732 >> 2)) >> 1)) * 2) + 1;
      int v1804 = v1803[v2045];
      int * v1805 = v1730->cache_vals;
      int v2047 = ((4 + ((((int)((unsigned int)((int)((unsigned int)v1732 >> 2)) >> 1)) & 3) * 2)) + ((((v1779 + ((~(((v1781 ^ -1) | (-(v1781 ^ -1))) >> 31)) & 2)) - (v1783 + ((~(((v1785 ^ -1) | (-(v1785 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
      v1805[v2047] = v1802;
      int * v1807 = v1730->cache_vals;
      int v2050 = (((4 + ((((int)((unsigned int)((int)((unsigned int)v1732 >> 2)) >> 1)) & 3) * 2)) + ((((v1779 + ((~(((v1781 ^ -1) | (-(v1781 ^ -1))) >> 31)) & 2)) - (v1783 + ((~(((v1785 ^ -1) | (-(v1785 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
      v1807[v2050] = v1804;
      int * v1809 = v1730->cache_tags;
      int v2053 = (int)((unsigned int)((int)((unsigned int)v1732 >> 2)) >> 1);
      v1809[v2027] = v2053;
      int * v1811 = v1730->cache_dirty;
      v1811[v2027] = 0;
      int * v1813 = v1730->cache_age;
      v1813[v2027] = 1;
      int * v1815 = v1730->cache_age;
      int v1816 = v1815[v2027];
      int * v1817 = v1730->cache_age;
      int v1818 = v1817[v1990];
      int * v1819 = v1730->cache_age;
      int v2061 = v1818 + ((int)((unsigned int)(v1818 - v1816) >> 31));
      v1819[v1990] = v2061;
      int * v1821 = v1730->cache_age;
      int v1822 = v1821[v1992];
      int * v1823 = v1730->cache_age;
      int v2064 = v1822 + ((int)((unsigned int)(v1822 - v1816) >> 31));
      v1823[v1992] = v2064;
      int * v1825 = v1730->cache_age;
      v1825[v2027] = 0;
      v1828 = v2027;
    }
    int * v1829 = v1730->cache_vals;
    int v2067 = v1828 * 2;
    int v1830 = v1829[v2067];
    int * v1831 = v1730->cache_vals;
    int v2069 = (v1828 * 2) + 1;
    int v1832 = v1831[v2069];
    int * v1833 = v1730->cache_vals;
    int v2071 = (((((int)((unsigned int)((int)((unsigned int)v1732 >> 2)) >> 1)) & 1) * 2) + ((((v1758 + ((~(((v1760 ^ -1) | (-(v1760 ^ -1))) >> 31)) & 2)) - (v1762 + ((~(((v1764 ^ -1) | (-(v1764 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
    v1833[v2071] = v1830;
    int * v1835 = v1730->cache_vals;
    int v2074 = ((((((int)((unsigned int)((int)((unsigned int)v1732 >> 2)) >> 1)) & 1) * 2) + ((((v1758 + ((~(((v1760 ^ -1) | (-(v1760 ^ -1))) >> 31)) & 2)) - (v1762 + ((~(((v1764 ^ -1) | (-(v1764 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
    v1835[v2074] = v1832;
    int * v1837 = v1730->cache_tags;
    int v2077 = ((((int)((unsigned int)((int)((unsigned int)v1732 >> 2)) >> 1)) & 1) * 2) + ((((v1758 + ((~(((v1760 ^ -1) | (-(v1760 ^ -1))) >> 31)) & 2)) - (v1762 + ((~(((v1764 ^ -1) | (-(v1764 ^ -1))) >> 31)) & 2))) >> 31) & 1);
    int v2078 = (int)((unsigned int)((int)((unsigned int)v1732 >> 2)) >> 1);
    v1837[v2077] = v2078;
    int * v1839 = v1730->cache_dirty;
    v1839[v2077] = 0;
    int * v1841 = v1730->cache_age;
    v1841[v2077] = 1;
    int * v1843 = v1730->cache_age;
    int v1844 = v1843[v2077];
    int * v1845 = v1730->cache_age;
    int v1846 = v1845[v1986];
    int * v1847 = v1730->cache_age;
    int v2086 = v1846 + ((int)((unsigned int)(v1846 - v1844) >> 31));
    v1847[v1986] = v2086;
    int * v1849 = v1730->cache_age;
    int v1850 = v1849[v1988];
    int * v1851 = v1730->cache_age;
    int v2089 = v1850 + ((int)((unsigned int)(v1850 - v1844) >> 31));
    v1851[v1988] = v2089;
    int * v1853 = v1730->cache_age;
    v1853[v2077] = 0;
    v1856 = v2077;
  }
  int v2092 = (v1856 * 2) + (((int)((unsigned int)v1732 >> 2)) & 1);
  int v1857 = v1743[v2092];
  int * v1858 = v1730->regs;
  v1858[11] = v1857;
  struct StateT2 * v1860 = slot_10(v1587);
  return v1860;
}

struct StateT2 * slot_11(struct StateT2 * v2140) {
  struct StateT * v2141 = v2140->a;
  int v2142 = v2141->timer;
  struct StateT * v2143 = v2140->b;
  int v2144 = v2143->timer;
  bool v2159 = v2142 == v2144;
  squared_assert(v2159);
  squared_assume(v2159);
  struct StateT * v2147 = v2140->a;
  int v2148 = v2147->timer;
  int v2161 = v2148 + 1;
  v2147->timer = v2161;
  struct StateT * v2150 = v2140->b;
  int v2151 = v2150->timer;
  int v2163 = v2151 + 1;
  v2150->timer = v2163;
  struct StateT * v2153 = v2140->a;
  struct StateT * v2154 = v2140->b;
  struct StateT2 * v2155 = slot_3(v2140);
  return v2155;
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
    s1.mem[SECRET_OFFSET+i] = bounded(0, 20);
    s2.mem[SECRET_OFFSET+i] = bounded(0, 20);
  }
  struct StateT2 p = { .a = &s1, .b = &s2 };
  struct StateT2 *p_ = snippet(&p);
  koika_assert(p_->a->timer==p_->b->timer, "timing leak");
  return 0;
}