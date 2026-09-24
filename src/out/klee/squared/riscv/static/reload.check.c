// verify: leak (KLEE should report a failing assertion) [budget 1200s]
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

struct StateT2 * slot_6(struct StateT2 * v731);
struct StateT2 * slot_5(struct StateT2 * v203);
struct StateT2 * slot_2(struct StateT2 * v74);
struct StateT2 * slot_7(struct StateT2 * v774);
struct StateT2 * slot_3(struct StateT2 * v110);
struct StateT2 * snippet(struct StateT2 * v0);
struct StateT2 * slot_10(struct StateT2 * v1426);
struct StateT2 * slot_1(struct StateT2 * v38);
struct StateT2 * slot_8(struct StateT2 * v1302);
struct StateT2 * slot_4(struct StateT2 * v134);
struct StateT2 * slot_9(struct StateT2 * v1400);
struct StateT2 * slot_0(struct StateT2 * v2);
struct StateT2 * slot_6(struct StateT2 * v731) {
  struct StateT * v732 = v731->a;
  int v733 = v732->timer;
  struct StateT * v734 = v731->b;
  int v735 = v734->timer;
  bool v758 = v733 == v735;
  squared_assert(v758);
  squared_assume(v758);
  struct StateT * v738 = v731->a;
  int v739 = v738->timer;
  int v760 = v739 + 1;
  v738->timer = v760;
  struct StateT * v741 = v731->b;
  int v742 = v741->timer;
  int v762 = v742 + 1;
  v741->timer = v762;
  struct StateT * v744 = v731->a;
  int * v745 = v744->regs;
  int v746 = v745[11];
  int * v747 = v744->regs;
  int v767 = v746 << 2;
  v747[11] = v767;
  struct StateT * v749 = v731->b;
  int * v750 = v749->regs;
  int v751 = v750[11];
  int * v752 = v749->regs;
  int v771 = v751 << 2;
  v752[11] = v771;
  struct StateT2 * v754 = slot_7(v731);
  return v754;
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
  int v213 = v212[11];
  v211[11] = v213;
  struct StateT * v215 = v203->b;
  int * v216 = v215->saved_regs;
  int * v217 = v215->regs;
  int v218 = v217[11];
  v216[11] = v218;
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
  int v228 = v227[5];
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
  v354[11] = v353;
  struct StateT * v356 = v203->b;
  int * v357 = v356->regs;
  int v358 = v357[5];
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
  v484[11] = v483;
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
  v88[15] = 80;
  struct StateT * v90 = v74->b;
  int * v91 = v90->regs;
  v91[15] = 80;
  struct StateT2 * v93 = slot_3(v74);
  return v93;
}

struct StateT2 * slot_7(struct StateT2 * v774) {
  struct StateT * v775 = v774->a;
  int v776 = v775->timer;
  struct StateT * v777 = v774->b;
  int v778 = v777->timer;
  bool v1061 = v776 == v778;
  squared_assert(v1061);
  squared_assume(v1061);
  struct StateT * v781 = v774->a;
  int * v782 = v781->saved_regs;
  int * v783 = v781->regs;
  int v784 = v783[12];
  v782[12] = v784;
  struct StateT * v786 = v774->b;
  int * v787 = v786->saved_regs;
  int * v788 = v786->regs;
  int v789 = v788[12];
  v787[12] = v789;
  struct StateT * v791 = v774->a;
  int v792 = v791->timer;
  int v1072 = v792 + 1;
  v791->timer = v1072;
  struct StateT * v794 = v774->b;
  int v795 = v794->timer;
  int v1074 = v795 + 1;
  v794->timer = v1074;
  struct StateT * v797 = v774->a;
  int * v798 = v797->regs;
  int v799 = v798[11];
  int * v800 = v797->cache_tags;
  int v1079 = (((int)((unsigned int)((int)((unsigned int)v799 >> 2)) >> 1)) & 1) * 2;
  int v801 = v800[v1079];
  int * v802 = v797->cache_tags;
  int v1081 = ((((int)((unsigned int)((int)((unsigned int)v799 >> 2)) >> 1)) & 1) * 2) + 1;
  int v803 = v802[v1081];
  int * v804 = v797->cache_tags;
  int v1083 = 4 + ((((int)((unsigned int)((int)((unsigned int)v799 >> 2)) >> 1)) & 3) * 2);
  int v805 = v804[v1083];
  int * v806 = v797->cache_tags;
  int v1085 = (4 + ((((int)((unsigned int)((int)((unsigned int)v799 >> 2)) >> 1)) & 3) * 2)) + 1;
  int v807 = v806[v1085];
  int v808 = v797->timer;
  int v1086 = v808 + ((100 ^ (((~(((v805 ^ ((int)((unsigned int)((int)((unsigned int)v799 >> 2)) >> 1))) | (-(v805 ^ ((int)((unsigned int)((int)((unsigned int)v799 >> 2)) >> 1))))) >> 31)) | (~(((v807 ^ ((int)((unsigned int)((int)((unsigned int)v799 >> 2)) >> 1))) | (-(v807 ^ ((int)((unsigned int)((int)((unsigned int)v799 >> 2)) >> 1))))) >> 31))) & 104)) ^ (((~(((v801 ^ ((int)((unsigned int)((int)((unsigned int)v799 >> 2)) >> 1))) | (-(v801 ^ ((int)((unsigned int)((int)((unsigned int)v799 >> 2)) >> 1))))) >> 31)) | (~(((v803 ^ ((int)((unsigned int)((int)((unsigned int)v799 >> 2)) >> 1))) | (-(v803 ^ ((int)((unsigned int)((int)((unsigned int)v799 >> 2)) >> 1))))) >> 31))) & (1 ^ (100 ^ (((~(((v805 ^ ((int)((unsigned int)((int)((unsigned int)v799 >> 2)) >> 1))) | (-(v805 ^ ((int)((unsigned int)((int)((unsigned int)v799 >> 2)) >> 1))))) >> 31)) | (~(((v807 ^ ((int)((unsigned int)((int)((unsigned int)v799 >> 2)) >> 1))) | (-(v807 ^ ((int)((unsigned int)((int)((unsigned int)v799 >> 2)) >> 1))))) >> 31))) & 104)))));
  v797->timer = v1086;
  int * v810 = v797->cache_vals;
  bool v1087 = !(((~(((v801 ^ ((int)((unsigned int)((int)((unsigned int)v799 >> 2)) >> 1))) | (-(v801 ^ ((int)((unsigned int)((int)((unsigned int)v799 >> 2)) >> 1))))) >> 31)) | (~(((v803 ^ ((int)((unsigned int)((int)((unsigned int)v799 >> 2)) >> 1))) | (-(v803 ^ ((int)((unsigned int)((int)((unsigned int)v799 >> 2)) >> 1))))) >> 31))) == 0);
  int v923;
  if (v1087) {
    int * v811 = v797->cache_age;
    int v1089 = ((((int)((unsigned int)((int)((unsigned int)v799 >> 2)) >> 1)) & 1) * 2) + ((~(((v803 ^ ((int)((unsigned int)((int)((unsigned int)v799 >> 2)) >> 1))) | (-(v803 ^ ((int)((unsigned int)((int)((unsigned int)v799 >> 2)) >> 1))))) >> 31)) & 1);
    int v812 = v811[v1089];
    int * v813 = v797->cache_age;
    int v814 = v813[v1079];
    int * v815 = v797->cache_age;
    int v1092 = v814 + ((int)((unsigned int)(v814 - v812) >> 31));
    v815[v1079] = v1092;
    int * v817 = v797->cache_age;
    int v818 = v817[v1081];
    int * v819 = v797->cache_age;
    int v1095 = v818 + ((int)((unsigned int)(v818 - v812) >> 31));
    v819[v1081] = v1095;
    int * v821 = v797->cache_age;
    v821[v1089] = 0;
    v923 = v1089;
  } else {
    int * v824 = v797->cache_age;
    int v1099 = (((int)((unsigned int)((int)((unsigned int)v799 >> 2)) >> 1)) & 1) * 2;
    int v825 = v824[v1099];
    int * v826 = v797->cache_tags;
    int v827 = v826[v1099];
    int * v828 = v797->cache_age;
    int v829 = v828[v1081];
    int * v830 = v797->cache_tags;
    int v831 = v830[v1081];
    bool v1103 = !(((~(((v805 ^ ((int)((unsigned int)((int)((unsigned int)v799 >> 2)) >> 1))) | (-(v805 ^ ((int)((unsigned int)((int)((unsigned int)v799 >> 2)) >> 1))))) >> 31)) | (~(((v807 ^ ((int)((unsigned int)((int)((unsigned int)v799 >> 2)) >> 1))) | (-(v807 ^ ((int)((unsigned int)((int)((unsigned int)v799 >> 2)) >> 1))))) >> 31))) == 0);
    int v895;
    if (v1103) {
      int * v832 = v797->cache_age;
      int v1105 = (4 + ((((int)((unsigned int)((int)((unsigned int)v799 >> 2)) >> 1)) & 3) * 2)) + ((~(((v807 ^ ((int)((unsigned int)((int)((unsigned int)v799 >> 2)) >> 1))) | (-(v807 ^ ((int)((unsigned int)((int)((unsigned int)v799 >> 2)) >> 1))))) >> 31)) & 1);
      int v833 = v832[v1105];
      int * v834 = v797->cache_age;
      int v835 = v834[v1083];
      int * v836 = v797->cache_age;
      int v1108 = v835 + ((int)((unsigned int)(v835 - v833) >> 31));
      v836[v1083] = v1108;
      int * v838 = v797->cache_age;
      int v839 = v838[v1085];
      int * v840 = v797->cache_age;
      int v1111 = v839 + ((int)((unsigned int)(v839 - v833) >> 31));
      v840[v1085] = v1111;
      int * v842 = v797->cache_age;
      v842[v1105] = 0;
      v895 = v1105;
    } else {
      int * v845 = v797->cache_age;
      int v1115 = 4 + ((((int)((unsigned int)((int)((unsigned int)v799 >> 2)) >> 1)) & 3) * 2);
      int v846 = v845[v1115];
      int * v847 = v797->cache_tags;
      int v848 = v847[v1115];
      int * v849 = v797->cache_age;
      int v850 = v849[v1085];
      int * v851 = v797->cache_tags;
      int v852 = v851[v1085];
      int * v853 = v797->cache_dirty;
      int v1120 = (4 + ((((int)((unsigned int)((int)((unsigned int)v799 >> 2)) >> 1)) & 3) * 2)) + ((((v846 + ((~(((v848 ^ -1) | (-(v848 ^ -1))) >> 31)) & 2)) - (v850 + ((~(((v852 ^ -1) | (-(v852 ^ -1))) >> 31)) & 2))) >> 31) & 1);
      int v854 = v853[v1120];
      bool v1121 = !(v854 == 0);
      if (v1121) {
        int * v855 = v797->cache_tags;
        int v856 = v855[v1120];
        int * v857 = v797->cache_vals;
        int v1124 = ((4 + ((((int)((unsigned int)((int)((unsigned int)v799 >> 2)) >> 1)) & 3) * 2)) + ((((v846 + ((~(((v848 ^ -1) | (-(v848 ^ -1))) >> 31)) & 2)) - (v850 + ((~(((v852 ^ -1) | (-(v852 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
        int v858 = v857[v1124];
        int * v859 = v797->cache_vals;
        int v1126 = (((4 + ((((int)((unsigned int)((int)((unsigned int)v799 >> 2)) >> 1)) & 3) * 2)) + ((((v846 + ((~(((v848 ^ -1) | (-(v848 ^ -1))) >> 31)) & 2)) - (v850 + ((~(((v852 ^ -1) | (-(v852 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
        int v860 = v859[v1126];
        int * v861 = v797->mem;
        int v1128 = v856 * 2;
        v861[v1128] = v858;
        int * v863 = v797->mem;
        int v1131 = (v856 * 2) + 1;
        v863[v1131] = v860;
        ;
      } else {
        ;
      }
      int * v868 = v797->mem;
      int v1136 = ((int)((unsigned int)((int)((unsigned int)v799 >> 2)) >> 1)) * 2;
      int v869 = v868[v1136];
      int * v870 = v797->mem;
      int v1138 = (((int)((unsigned int)((int)((unsigned int)v799 >> 2)) >> 1)) * 2) + 1;
      int v871 = v870[v1138];
      int * v872 = v797->cache_vals;
      int v1140 = ((4 + ((((int)((unsigned int)((int)((unsigned int)v799 >> 2)) >> 1)) & 3) * 2)) + ((((v846 + ((~(((v848 ^ -1) | (-(v848 ^ -1))) >> 31)) & 2)) - (v850 + ((~(((v852 ^ -1) | (-(v852 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
      v872[v1140] = v869;
      int * v874 = v797->cache_vals;
      int v1143 = (((4 + ((((int)((unsigned int)((int)((unsigned int)v799 >> 2)) >> 1)) & 3) * 2)) + ((((v846 + ((~(((v848 ^ -1) | (-(v848 ^ -1))) >> 31)) & 2)) - (v850 + ((~(((v852 ^ -1) | (-(v852 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
      v874[v1143] = v871;
      int * v876 = v797->cache_tags;
      int v1146 = (int)((unsigned int)((int)((unsigned int)v799 >> 2)) >> 1);
      v876[v1120] = v1146;
      int * v878 = v797->cache_dirty;
      v878[v1120] = 0;
      int * v880 = v797->cache_age;
      v880[v1120] = 1;
      int * v882 = v797->cache_age;
      int v883 = v882[v1120];
      int * v884 = v797->cache_age;
      int v885 = v884[v1083];
      int * v886 = v797->cache_age;
      int v1154 = v885 + ((int)((unsigned int)(v885 - v883) >> 31));
      v886[v1083] = v1154;
      int * v888 = v797->cache_age;
      int v889 = v888[v1085];
      int * v890 = v797->cache_age;
      int v1157 = v889 + ((int)((unsigned int)(v889 - v883) >> 31));
      v890[v1085] = v1157;
      int * v892 = v797->cache_age;
      v892[v1120] = 0;
      v895 = v1120;
    }
    int * v896 = v797->cache_vals;
    int v1160 = v895 * 2;
    int v897 = v896[v1160];
    int * v898 = v797->cache_vals;
    int v1162 = (v895 * 2) + 1;
    int v899 = v898[v1162];
    int * v900 = v797->cache_vals;
    int v1164 = (((((int)((unsigned int)((int)((unsigned int)v799 >> 2)) >> 1)) & 1) * 2) + ((((v825 + ((~(((v827 ^ -1) | (-(v827 ^ -1))) >> 31)) & 2)) - (v829 + ((~(((v831 ^ -1) | (-(v831 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
    v900[v1164] = v897;
    int * v902 = v797->cache_vals;
    int v1167 = ((((((int)((unsigned int)((int)((unsigned int)v799 >> 2)) >> 1)) & 1) * 2) + ((((v825 + ((~(((v827 ^ -1) | (-(v827 ^ -1))) >> 31)) & 2)) - (v829 + ((~(((v831 ^ -1) | (-(v831 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
    v902[v1167] = v899;
    int * v904 = v797->cache_tags;
    int v1170 = ((((int)((unsigned int)((int)((unsigned int)v799 >> 2)) >> 1)) & 1) * 2) + ((((v825 + ((~(((v827 ^ -1) | (-(v827 ^ -1))) >> 31)) & 2)) - (v829 + ((~(((v831 ^ -1) | (-(v831 ^ -1))) >> 31)) & 2))) >> 31) & 1);
    int v1171 = (int)((unsigned int)((int)((unsigned int)v799 >> 2)) >> 1);
    v904[v1170] = v1171;
    int * v906 = v797->cache_dirty;
    v906[v1170] = 0;
    int * v908 = v797->cache_age;
    v908[v1170] = 1;
    int * v910 = v797->cache_age;
    int v911 = v910[v1170];
    int * v912 = v797->cache_age;
    int v913 = v912[v1079];
    int * v914 = v797->cache_age;
    int v1179 = v913 + ((int)((unsigned int)(v913 - v911) >> 31));
    v914[v1079] = v1179;
    int * v916 = v797->cache_age;
    int v917 = v916[v1081];
    int * v918 = v797->cache_age;
    int v1182 = v917 + ((int)((unsigned int)(v917 - v911) >> 31));
    v918[v1081] = v1182;
    int * v920 = v797->cache_age;
    v920[v1170] = 0;
    v923 = v1170;
  }
  int v1185 = (v923 * 2) + (((int)((unsigned int)v799 >> 2)) & 1);
  int v924 = v810[v1185];
  int * v925 = v797->regs;
  v925[12] = v924;
  struct StateT * v927 = v774->b;
  int * v928 = v927->regs;
  int v929 = v928[11];
  int * v930 = v927->cache_tags;
  int v1191 = (((int)((unsigned int)((int)((unsigned int)v929 >> 2)) >> 1)) & 1) * 2;
  int v931 = v930[v1191];
  int * v932 = v927->cache_tags;
  int v1193 = ((((int)((unsigned int)((int)((unsigned int)v929 >> 2)) >> 1)) & 1) * 2) + 1;
  int v933 = v932[v1193];
  int * v934 = v927->cache_tags;
  int v1195 = 4 + ((((int)((unsigned int)((int)((unsigned int)v929 >> 2)) >> 1)) & 3) * 2);
  int v935 = v934[v1195];
  int * v936 = v927->cache_tags;
  int v1197 = (4 + ((((int)((unsigned int)((int)((unsigned int)v929 >> 2)) >> 1)) & 3) * 2)) + 1;
  int v937 = v936[v1197];
  int v938 = v927->timer;
  int v1198 = v938 + ((100 ^ (((~(((v935 ^ ((int)((unsigned int)((int)((unsigned int)v929 >> 2)) >> 1))) | (-(v935 ^ ((int)((unsigned int)((int)((unsigned int)v929 >> 2)) >> 1))))) >> 31)) | (~(((v937 ^ ((int)((unsigned int)((int)((unsigned int)v929 >> 2)) >> 1))) | (-(v937 ^ ((int)((unsigned int)((int)((unsigned int)v929 >> 2)) >> 1))))) >> 31))) & 104)) ^ (((~(((v931 ^ ((int)((unsigned int)((int)((unsigned int)v929 >> 2)) >> 1))) | (-(v931 ^ ((int)((unsigned int)((int)((unsigned int)v929 >> 2)) >> 1))))) >> 31)) | (~(((v933 ^ ((int)((unsigned int)((int)((unsigned int)v929 >> 2)) >> 1))) | (-(v933 ^ ((int)((unsigned int)((int)((unsigned int)v929 >> 2)) >> 1))))) >> 31))) & (1 ^ (100 ^ (((~(((v935 ^ ((int)((unsigned int)((int)((unsigned int)v929 >> 2)) >> 1))) | (-(v935 ^ ((int)((unsigned int)((int)((unsigned int)v929 >> 2)) >> 1))))) >> 31)) | (~(((v937 ^ ((int)((unsigned int)((int)((unsigned int)v929 >> 2)) >> 1))) | (-(v937 ^ ((int)((unsigned int)((int)((unsigned int)v929 >> 2)) >> 1))))) >> 31))) & 104)))));
  v927->timer = v1198;
  int * v940 = v927->cache_vals;
  bool v1199 = !(((~(((v931 ^ ((int)((unsigned int)((int)((unsigned int)v929 >> 2)) >> 1))) | (-(v931 ^ ((int)((unsigned int)((int)((unsigned int)v929 >> 2)) >> 1))))) >> 31)) | (~(((v933 ^ ((int)((unsigned int)((int)((unsigned int)v929 >> 2)) >> 1))) | (-(v933 ^ ((int)((unsigned int)((int)((unsigned int)v929 >> 2)) >> 1))))) >> 31))) == 0);
  int v1053;
  if (v1199) {
    int * v941 = v927->cache_age;
    int v1201 = ((((int)((unsigned int)((int)((unsigned int)v929 >> 2)) >> 1)) & 1) * 2) + ((~(((v933 ^ ((int)((unsigned int)((int)((unsigned int)v929 >> 2)) >> 1))) | (-(v933 ^ ((int)((unsigned int)((int)((unsigned int)v929 >> 2)) >> 1))))) >> 31)) & 1);
    int v942 = v941[v1201];
    int * v943 = v927->cache_age;
    int v944 = v943[v1191];
    int * v945 = v927->cache_age;
    int v1204 = v944 + ((int)((unsigned int)(v944 - v942) >> 31));
    v945[v1191] = v1204;
    int * v947 = v927->cache_age;
    int v948 = v947[v1193];
    int * v949 = v927->cache_age;
    int v1207 = v948 + ((int)((unsigned int)(v948 - v942) >> 31));
    v949[v1193] = v1207;
    int * v951 = v927->cache_age;
    v951[v1201] = 0;
    v1053 = v1201;
  } else {
    int * v954 = v927->cache_age;
    int v1211 = (((int)((unsigned int)((int)((unsigned int)v929 >> 2)) >> 1)) & 1) * 2;
    int v955 = v954[v1211];
    int * v956 = v927->cache_tags;
    int v957 = v956[v1211];
    int * v958 = v927->cache_age;
    int v959 = v958[v1193];
    int * v960 = v927->cache_tags;
    int v961 = v960[v1193];
    bool v1215 = !(((~(((v935 ^ ((int)((unsigned int)((int)((unsigned int)v929 >> 2)) >> 1))) | (-(v935 ^ ((int)((unsigned int)((int)((unsigned int)v929 >> 2)) >> 1))))) >> 31)) | (~(((v937 ^ ((int)((unsigned int)((int)((unsigned int)v929 >> 2)) >> 1))) | (-(v937 ^ ((int)((unsigned int)((int)((unsigned int)v929 >> 2)) >> 1))))) >> 31))) == 0);
    int v1025;
    if (v1215) {
      int * v962 = v927->cache_age;
      int v1217 = (4 + ((((int)((unsigned int)((int)((unsigned int)v929 >> 2)) >> 1)) & 3) * 2)) + ((~(((v937 ^ ((int)((unsigned int)((int)((unsigned int)v929 >> 2)) >> 1))) | (-(v937 ^ ((int)((unsigned int)((int)((unsigned int)v929 >> 2)) >> 1))))) >> 31)) & 1);
      int v963 = v962[v1217];
      int * v964 = v927->cache_age;
      int v965 = v964[v1195];
      int * v966 = v927->cache_age;
      int v1220 = v965 + ((int)((unsigned int)(v965 - v963) >> 31));
      v966[v1195] = v1220;
      int * v968 = v927->cache_age;
      int v969 = v968[v1197];
      int * v970 = v927->cache_age;
      int v1223 = v969 + ((int)((unsigned int)(v969 - v963) >> 31));
      v970[v1197] = v1223;
      int * v972 = v927->cache_age;
      v972[v1217] = 0;
      v1025 = v1217;
    } else {
      int * v975 = v927->cache_age;
      int v1227 = 4 + ((((int)((unsigned int)((int)((unsigned int)v929 >> 2)) >> 1)) & 3) * 2);
      int v976 = v975[v1227];
      int * v977 = v927->cache_tags;
      int v978 = v977[v1227];
      int * v979 = v927->cache_age;
      int v980 = v979[v1197];
      int * v981 = v927->cache_tags;
      int v982 = v981[v1197];
      int * v983 = v927->cache_dirty;
      int v1232 = (4 + ((((int)((unsigned int)((int)((unsigned int)v929 >> 2)) >> 1)) & 3) * 2)) + ((((v976 + ((~(((v978 ^ -1) | (-(v978 ^ -1))) >> 31)) & 2)) - (v980 + ((~(((v982 ^ -1) | (-(v982 ^ -1))) >> 31)) & 2))) >> 31) & 1);
      int v984 = v983[v1232];
      bool v1233 = !(v984 == 0);
      if (v1233) {
        int * v985 = v927->cache_tags;
        int v986 = v985[v1232];
        int * v987 = v927->cache_vals;
        int v1236 = ((4 + ((((int)((unsigned int)((int)((unsigned int)v929 >> 2)) >> 1)) & 3) * 2)) + ((((v976 + ((~(((v978 ^ -1) | (-(v978 ^ -1))) >> 31)) & 2)) - (v980 + ((~(((v982 ^ -1) | (-(v982 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
        int v988 = v987[v1236];
        int * v989 = v927->cache_vals;
        int v1238 = (((4 + ((((int)((unsigned int)((int)((unsigned int)v929 >> 2)) >> 1)) & 3) * 2)) + ((((v976 + ((~(((v978 ^ -1) | (-(v978 ^ -1))) >> 31)) & 2)) - (v980 + ((~(((v982 ^ -1) | (-(v982 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
        int v990 = v989[v1238];
        int * v991 = v927->mem;
        int v1240 = v986 * 2;
        v991[v1240] = v988;
        int * v993 = v927->mem;
        int v1243 = (v986 * 2) + 1;
        v993[v1243] = v990;
        ;
      } else {
        ;
      }
      int * v998 = v927->mem;
      int v1248 = ((int)((unsigned int)((int)((unsigned int)v929 >> 2)) >> 1)) * 2;
      int v999 = v998[v1248];
      int * v1000 = v927->mem;
      int v1250 = (((int)((unsigned int)((int)((unsigned int)v929 >> 2)) >> 1)) * 2) + 1;
      int v1001 = v1000[v1250];
      int * v1002 = v927->cache_vals;
      int v1252 = ((4 + ((((int)((unsigned int)((int)((unsigned int)v929 >> 2)) >> 1)) & 3) * 2)) + ((((v976 + ((~(((v978 ^ -1) | (-(v978 ^ -1))) >> 31)) & 2)) - (v980 + ((~(((v982 ^ -1) | (-(v982 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
      v1002[v1252] = v999;
      int * v1004 = v927->cache_vals;
      int v1255 = (((4 + ((((int)((unsigned int)((int)((unsigned int)v929 >> 2)) >> 1)) & 3) * 2)) + ((((v976 + ((~(((v978 ^ -1) | (-(v978 ^ -1))) >> 31)) & 2)) - (v980 + ((~(((v982 ^ -1) | (-(v982 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
      v1004[v1255] = v1001;
      int * v1006 = v927->cache_tags;
      int v1258 = (int)((unsigned int)((int)((unsigned int)v929 >> 2)) >> 1);
      v1006[v1232] = v1258;
      int * v1008 = v927->cache_dirty;
      v1008[v1232] = 0;
      int * v1010 = v927->cache_age;
      v1010[v1232] = 1;
      int * v1012 = v927->cache_age;
      int v1013 = v1012[v1232];
      int * v1014 = v927->cache_age;
      int v1015 = v1014[v1195];
      int * v1016 = v927->cache_age;
      int v1266 = v1015 + ((int)((unsigned int)(v1015 - v1013) >> 31));
      v1016[v1195] = v1266;
      int * v1018 = v927->cache_age;
      int v1019 = v1018[v1197];
      int * v1020 = v927->cache_age;
      int v1269 = v1019 + ((int)((unsigned int)(v1019 - v1013) >> 31));
      v1020[v1197] = v1269;
      int * v1022 = v927->cache_age;
      v1022[v1232] = 0;
      v1025 = v1232;
    }
    int * v1026 = v927->cache_vals;
    int v1272 = v1025 * 2;
    int v1027 = v1026[v1272];
    int * v1028 = v927->cache_vals;
    int v1274 = (v1025 * 2) + 1;
    int v1029 = v1028[v1274];
    int * v1030 = v927->cache_vals;
    int v1276 = (((((int)((unsigned int)((int)((unsigned int)v929 >> 2)) >> 1)) & 1) * 2) + ((((v955 + ((~(((v957 ^ -1) | (-(v957 ^ -1))) >> 31)) & 2)) - (v959 + ((~(((v961 ^ -1) | (-(v961 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
    v1030[v1276] = v1027;
    int * v1032 = v927->cache_vals;
    int v1279 = ((((((int)((unsigned int)((int)((unsigned int)v929 >> 2)) >> 1)) & 1) * 2) + ((((v955 + ((~(((v957 ^ -1) | (-(v957 ^ -1))) >> 31)) & 2)) - (v959 + ((~(((v961 ^ -1) | (-(v961 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
    v1032[v1279] = v1029;
    int * v1034 = v927->cache_tags;
    int v1282 = ((((int)((unsigned int)((int)((unsigned int)v929 >> 2)) >> 1)) & 1) * 2) + ((((v955 + ((~(((v957 ^ -1) | (-(v957 ^ -1))) >> 31)) & 2)) - (v959 + ((~(((v961 ^ -1) | (-(v961 ^ -1))) >> 31)) & 2))) >> 31) & 1);
    int v1283 = (int)((unsigned int)((int)((unsigned int)v929 >> 2)) >> 1);
    v1034[v1282] = v1283;
    int * v1036 = v927->cache_dirty;
    v1036[v1282] = 0;
    int * v1038 = v927->cache_age;
    v1038[v1282] = 1;
    int * v1040 = v927->cache_age;
    int v1041 = v1040[v1282];
    int * v1042 = v927->cache_age;
    int v1043 = v1042[v1191];
    int * v1044 = v927->cache_age;
    int v1291 = v1043 + ((int)((unsigned int)(v1043 - v1041) >> 31));
    v1044[v1191] = v1291;
    int * v1046 = v927->cache_age;
    int v1047 = v1046[v1193];
    int * v1048 = v927->cache_age;
    int v1294 = v1047 + ((int)((unsigned int)(v1047 - v1041) >> 31));
    v1048[v1193] = v1294;
    int * v1050 = v927->cache_age;
    v1050[v1282] = 0;
    v1053 = v1282;
  }
  int v1297 = (v1053 * 2) + (((int)((unsigned int)v929 >> 2)) & 1);
  int v1054 = v940[v1297];
  int * v1055 = v927->regs;
  v1055[12] = v1054;
  struct StateT2 * v1057 = slot_8(v774);
  return v1057;
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

struct StateT2 * slot_10(struct StateT2 * v1426) {
  struct StateT * v1427 = v1426->a;
  int v1428 = v1427->timer;
  struct StateT * v1429 = v1426->b;
  int v1430 = v1429->timer;
  bool v1698 = v1428 == v1430;
  squared_assert(v1698);
  squared_assume(v1698);
  struct StateT * v1433 = v1426->a;
  int v1434 = v1433->timer;
  int v1700 = v1434 + 1;
  v1433->timer = v1700;
  struct StateT * v1436 = v1426->b;
  int v1437 = v1436->timer;
  int v1702 = v1437 + 1;
  v1436->timer = v1702;
  struct StateT * v1439 = v1426->a;
  int * v1440 = v1439->cache_tags;
  int v1441 = v1440[0];
  int * v1442 = v1439->cache_tags;
  int v1443 = v1442[1];
  int * v1444 = v1439->cache_tags;
  int v1445 = v1444[4];
  int * v1446 = v1439->cache_tags;
  int v1447 = v1446[5];
  int v1448 = v1439->timer;
  int v1712 = v1448 + ((100 ^ (((~((v1445 | (-v1445)) >> 31)) | (~((v1447 | (-v1447)) >> 31))) & 104)) ^ (((~((v1441 | (-v1441)) >> 31)) | (~((v1443 | (-v1443)) >> 31))) & (1 ^ (100 ^ (((~((v1445 | (-v1445)) >> 31)) | (~((v1447 | (-v1447)) >> 31))) & 104)))));
  v1439->timer = v1712;
  int * v1450 = v1439->cache_vals;
  bool v1713 = !(((~((v1441 | (-v1441)) >> 31)) | (~((v1443 | (-v1443)) >> 31))) == 0);
  int v1563;
  if (v1713) {
    int * v1451 = v1439->cache_age;
    int v1715 = (~((v1443 | (-v1443)) >> 31)) & 1;
    int v1452 = v1451[v1715];
    int * v1453 = v1439->cache_age;
    int v1454 = v1453[0];
    int * v1455 = v1439->cache_age;
    int v1718 = v1454 + ((int)((unsigned int)(v1454 - v1452) >> 31));
    v1455[0] = v1718;
    int * v1457 = v1439->cache_age;
    int v1458 = v1457[1];
    int * v1459 = v1439->cache_age;
    int v1721 = v1458 + ((int)((unsigned int)(v1458 - v1452) >> 31));
    v1459[1] = v1721;
    int * v1461 = v1439->cache_age;
    v1461[v1715] = 0;
    v1563 = v1715;
  } else {
    int * v1464 = v1439->cache_age;
    int v1465 = v1464[0];
    int * v1466 = v1439->cache_tags;
    int v1467 = v1466[0];
    int * v1468 = v1439->cache_age;
    int v1469 = v1468[1];
    int * v1470 = v1439->cache_tags;
    int v1471 = v1470[1];
    bool v1727 = !(((~((v1445 | (-v1445)) >> 31)) | (~((v1447 | (-v1447)) >> 31))) == 0);
    int v1535;
    if (v1727) {
      int * v1472 = v1439->cache_age;
      int v1729 = 4 + ((~((v1447 | (-v1447)) >> 31)) & 1);
      int v1473 = v1472[v1729];
      int * v1474 = v1439->cache_age;
      int v1475 = v1474[4];
      int * v1476 = v1439->cache_age;
      int v1732 = v1475 + ((int)((unsigned int)(v1475 - v1473) >> 31));
      v1476[4] = v1732;
      int * v1478 = v1439->cache_age;
      int v1479 = v1478[5];
      int * v1480 = v1439->cache_age;
      int v1735 = v1479 + ((int)((unsigned int)(v1479 - v1473) >> 31));
      v1480[5] = v1735;
      int * v1482 = v1439->cache_age;
      v1482[v1729] = 0;
      v1535 = v1729;
    } else {
      int * v1485 = v1439->cache_age;
      int v1486 = v1485[4];
      int * v1487 = v1439->cache_tags;
      int v1488 = v1487[4];
      int * v1489 = v1439->cache_age;
      int v1490 = v1489[5];
      int * v1491 = v1439->cache_tags;
      int v1492 = v1491[5];
      int * v1493 = v1439->cache_dirty;
      int v1742 = 4 + ((((v1486 + ((~(((v1488 ^ -1) | (-(v1488 ^ -1))) >> 31)) & 2)) - (v1490 + ((~(((v1492 ^ -1) | (-(v1492 ^ -1))) >> 31)) & 2))) >> 31) & 1);
      int v1494 = v1493[v1742];
      bool v1743 = !(v1494 == 0);
      if (v1743) {
        int * v1495 = v1439->cache_tags;
        int v1496 = v1495[v1742];
        int * v1497 = v1439->cache_vals;
        int v1746 = (4 + ((((v1486 + ((~(((v1488 ^ -1) | (-(v1488 ^ -1))) >> 31)) & 2)) - (v1490 + ((~(((v1492 ^ -1) | (-(v1492 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
        int v1498 = v1497[v1746];
        int * v1499 = v1439->cache_vals;
        int v1748 = ((4 + ((((v1486 + ((~(((v1488 ^ -1) | (-(v1488 ^ -1))) >> 31)) & 2)) - (v1490 + ((~(((v1492 ^ -1) | (-(v1492 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
        int v1500 = v1499[v1748];
        int * v1501 = v1439->mem;
        int v1750 = v1496 * 2;
        v1501[v1750] = v1498;
        int * v1503 = v1439->mem;
        int v1753 = (v1496 * 2) + 1;
        v1503[v1753] = v1500;
        ;
      } else {
        ;
      }
      int * v1508 = v1439->mem;
      int v1509 = v1508[0];
      int * v1510 = v1439->mem;
      int v1511 = v1510[1];
      int * v1512 = v1439->cache_vals;
      int v1760 = (4 + ((((v1486 + ((~(((v1488 ^ -1) | (-(v1488 ^ -1))) >> 31)) & 2)) - (v1490 + ((~(((v1492 ^ -1) | (-(v1492 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
      v1512[v1760] = v1509;
      int * v1514 = v1439->cache_vals;
      int v1763 = ((4 + ((((v1486 + ((~(((v1488 ^ -1) | (-(v1488 ^ -1))) >> 31)) & 2)) - (v1490 + ((~(((v1492 ^ -1) | (-(v1492 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
      v1514[v1763] = v1511;
      int * v1516 = v1439->cache_tags;
      v1516[v1742] = 0;
      int * v1518 = v1439->cache_dirty;
      v1518[v1742] = 0;
      int * v1520 = v1439->cache_age;
      v1520[v1742] = 1;
      int * v1522 = v1439->cache_age;
      int v1523 = v1522[v1742];
      int * v1524 = v1439->cache_age;
      int v1525 = v1524[4];
      int * v1526 = v1439->cache_age;
      int v1771 = v1525 + ((int)((unsigned int)(v1525 - v1523) >> 31));
      v1526[4] = v1771;
      int * v1528 = v1439->cache_age;
      int v1529 = v1528[5];
      int * v1530 = v1439->cache_age;
      int v1774 = v1529 + ((int)((unsigned int)(v1529 - v1523) >> 31));
      v1530[5] = v1774;
      int * v1532 = v1439->cache_age;
      v1532[v1742] = 0;
      v1535 = v1742;
    }
    int * v1536 = v1439->cache_vals;
    int v1777 = v1535 * 2;
    int v1537 = v1536[v1777];
    int * v1538 = v1439->cache_vals;
    int v1779 = (v1535 * 2) + 1;
    int v1539 = v1538[v1779];
    int * v1540 = v1439->cache_vals;
    int v1781 = ((((v1465 + ((~(((v1467 ^ -1) | (-(v1467 ^ -1))) >> 31)) & 2)) - (v1469 + ((~(((v1471 ^ -1) | (-(v1471 ^ -1))) >> 31)) & 2))) >> 31) & 1) * 2;
    v1540[v1781] = v1537;
    int * v1542 = v1439->cache_vals;
    int v1784 = (((((v1465 + ((~(((v1467 ^ -1) | (-(v1467 ^ -1))) >> 31)) & 2)) - (v1469 + ((~(((v1471 ^ -1) | (-(v1471 ^ -1))) >> 31)) & 2))) >> 31) & 1) * 2) + 1;
    v1542[v1784] = v1539;
    int * v1544 = v1439->cache_tags;
    int v1787 = (((v1465 + ((~(((v1467 ^ -1) | (-(v1467 ^ -1))) >> 31)) & 2)) - (v1469 + ((~(((v1471 ^ -1) | (-(v1471 ^ -1))) >> 31)) & 2))) >> 31) & 1;
    v1544[v1787] = 0;
    int * v1546 = v1439->cache_dirty;
    v1546[v1787] = 0;
    int * v1548 = v1439->cache_age;
    v1548[v1787] = 1;
    int * v1550 = v1439->cache_age;
    int v1551 = v1550[v1787];
    int * v1552 = v1439->cache_age;
    int v1553 = v1552[0];
    int * v1554 = v1439->cache_age;
    int v1793 = v1553 + ((int)((unsigned int)(v1553 - v1551) >> 31));
    v1554[0] = v1793;
    int * v1556 = v1439->cache_age;
    int v1557 = v1556[1];
    int * v1558 = v1439->cache_age;
    int v1796 = v1557 + ((int)((unsigned int)(v1557 - v1551) >> 31));
    v1558[1] = v1796;
    int * v1560 = v1439->cache_age;
    v1560[v1787] = 0;
    v1563 = v1787;
  }
  int v1799 = v1563 * 2;
  int v1564 = v1450[v1799];
  int * v1565 = v1439->regs;
  v1565[14] = v1564;
  struct StateT * v1567 = v1426->b;
  int * v1568 = v1567->cache_tags;
  int v1569 = v1568[0];
  int * v1570 = v1567->cache_tags;
  int v1571 = v1570[1];
  int * v1572 = v1567->cache_tags;
  int v1573 = v1572[4];
  int * v1574 = v1567->cache_tags;
  int v1575 = v1574[5];
  int v1576 = v1567->timer;
  int v1808 = v1576 + ((100 ^ (((~((v1573 | (-v1573)) >> 31)) | (~((v1575 | (-v1575)) >> 31))) & 104)) ^ (((~((v1569 | (-v1569)) >> 31)) | (~((v1571 | (-v1571)) >> 31))) & (1 ^ (100 ^ (((~((v1573 | (-v1573)) >> 31)) | (~((v1575 | (-v1575)) >> 31))) & 104)))));
  v1567->timer = v1808;
  int * v1578 = v1567->cache_vals;
  bool v1809 = !(((~((v1569 | (-v1569)) >> 31)) | (~((v1571 | (-v1571)) >> 31))) == 0);
  int v1691;
  if (v1809) {
    int * v1579 = v1567->cache_age;
    int v1811 = (~((v1571 | (-v1571)) >> 31)) & 1;
    int v1580 = v1579[v1811];
    int * v1581 = v1567->cache_age;
    int v1582 = v1581[0];
    int * v1583 = v1567->cache_age;
    int v1814 = v1582 + ((int)((unsigned int)(v1582 - v1580) >> 31));
    v1583[0] = v1814;
    int * v1585 = v1567->cache_age;
    int v1586 = v1585[1];
    int * v1587 = v1567->cache_age;
    int v1817 = v1586 + ((int)((unsigned int)(v1586 - v1580) >> 31));
    v1587[1] = v1817;
    int * v1589 = v1567->cache_age;
    v1589[v1811] = 0;
    v1691 = v1811;
  } else {
    int * v1592 = v1567->cache_age;
    int v1593 = v1592[0];
    int * v1594 = v1567->cache_tags;
    int v1595 = v1594[0];
    int * v1596 = v1567->cache_age;
    int v1597 = v1596[1];
    int * v1598 = v1567->cache_tags;
    int v1599 = v1598[1];
    bool v1823 = !(((~((v1573 | (-v1573)) >> 31)) | (~((v1575 | (-v1575)) >> 31))) == 0);
    int v1663;
    if (v1823) {
      int * v1600 = v1567->cache_age;
      int v1825 = 4 + ((~((v1575 | (-v1575)) >> 31)) & 1);
      int v1601 = v1600[v1825];
      int * v1602 = v1567->cache_age;
      int v1603 = v1602[4];
      int * v1604 = v1567->cache_age;
      int v1828 = v1603 + ((int)((unsigned int)(v1603 - v1601) >> 31));
      v1604[4] = v1828;
      int * v1606 = v1567->cache_age;
      int v1607 = v1606[5];
      int * v1608 = v1567->cache_age;
      int v1831 = v1607 + ((int)((unsigned int)(v1607 - v1601) >> 31));
      v1608[5] = v1831;
      int * v1610 = v1567->cache_age;
      v1610[v1825] = 0;
      v1663 = v1825;
    } else {
      int * v1613 = v1567->cache_age;
      int v1614 = v1613[4];
      int * v1615 = v1567->cache_tags;
      int v1616 = v1615[4];
      int * v1617 = v1567->cache_age;
      int v1618 = v1617[5];
      int * v1619 = v1567->cache_tags;
      int v1620 = v1619[5];
      int * v1621 = v1567->cache_dirty;
      int v1838 = 4 + ((((v1614 + ((~(((v1616 ^ -1) | (-(v1616 ^ -1))) >> 31)) & 2)) - (v1618 + ((~(((v1620 ^ -1) | (-(v1620 ^ -1))) >> 31)) & 2))) >> 31) & 1);
      int v1622 = v1621[v1838];
      bool v1839 = !(v1622 == 0);
      if (v1839) {
        int * v1623 = v1567->cache_tags;
        int v1624 = v1623[v1838];
        int * v1625 = v1567->cache_vals;
        int v1842 = (4 + ((((v1614 + ((~(((v1616 ^ -1) | (-(v1616 ^ -1))) >> 31)) & 2)) - (v1618 + ((~(((v1620 ^ -1) | (-(v1620 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
        int v1626 = v1625[v1842];
        int * v1627 = v1567->cache_vals;
        int v1844 = ((4 + ((((v1614 + ((~(((v1616 ^ -1) | (-(v1616 ^ -1))) >> 31)) & 2)) - (v1618 + ((~(((v1620 ^ -1) | (-(v1620 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
        int v1628 = v1627[v1844];
        int * v1629 = v1567->mem;
        int v1846 = v1624 * 2;
        v1629[v1846] = v1626;
        int * v1631 = v1567->mem;
        int v1849 = (v1624 * 2) + 1;
        v1631[v1849] = v1628;
        ;
      } else {
        ;
      }
      int * v1636 = v1567->mem;
      int v1637 = v1636[0];
      int * v1638 = v1567->mem;
      int v1639 = v1638[1];
      int * v1640 = v1567->cache_vals;
      int v1856 = (4 + ((((v1614 + ((~(((v1616 ^ -1) | (-(v1616 ^ -1))) >> 31)) & 2)) - (v1618 + ((~(((v1620 ^ -1) | (-(v1620 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
      v1640[v1856] = v1637;
      int * v1642 = v1567->cache_vals;
      int v1859 = ((4 + ((((v1614 + ((~(((v1616 ^ -1) | (-(v1616 ^ -1))) >> 31)) & 2)) - (v1618 + ((~(((v1620 ^ -1) | (-(v1620 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
      v1642[v1859] = v1639;
      int * v1644 = v1567->cache_tags;
      v1644[v1838] = 0;
      int * v1646 = v1567->cache_dirty;
      v1646[v1838] = 0;
      int * v1648 = v1567->cache_age;
      v1648[v1838] = 1;
      int * v1650 = v1567->cache_age;
      int v1651 = v1650[v1838];
      int * v1652 = v1567->cache_age;
      int v1653 = v1652[4];
      int * v1654 = v1567->cache_age;
      int v1867 = v1653 + ((int)((unsigned int)(v1653 - v1651) >> 31));
      v1654[4] = v1867;
      int * v1656 = v1567->cache_age;
      int v1657 = v1656[5];
      int * v1658 = v1567->cache_age;
      int v1870 = v1657 + ((int)((unsigned int)(v1657 - v1651) >> 31));
      v1658[5] = v1870;
      int * v1660 = v1567->cache_age;
      v1660[v1838] = 0;
      v1663 = v1838;
    }
    int * v1664 = v1567->cache_vals;
    int v1873 = v1663 * 2;
    int v1665 = v1664[v1873];
    int * v1666 = v1567->cache_vals;
    int v1875 = (v1663 * 2) + 1;
    int v1667 = v1666[v1875];
    int * v1668 = v1567->cache_vals;
    int v1877 = ((((v1593 + ((~(((v1595 ^ -1) | (-(v1595 ^ -1))) >> 31)) & 2)) - (v1597 + ((~(((v1599 ^ -1) | (-(v1599 ^ -1))) >> 31)) & 2))) >> 31) & 1) * 2;
    v1668[v1877] = v1665;
    int * v1670 = v1567->cache_vals;
    int v1880 = (((((v1593 + ((~(((v1595 ^ -1) | (-(v1595 ^ -1))) >> 31)) & 2)) - (v1597 + ((~(((v1599 ^ -1) | (-(v1599 ^ -1))) >> 31)) & 2))) >> 31) & 1) * 2) + 1;
    v1670[v1880] = v1667;
    int * v1672 = v1567->cache_tags;
    int v1883 = (((v1593 + ((~(((v1595 ^ -1) | (-(v1595 ^ -1))) >> 31)) & 2)) - (v1597 + ((~(((v1599 ^ -1) | (-(v1599 ^ -1))) >> 31)) & 2))) >> 31) & 1;
    v1672[v1883] = 0;
    int * v1674 = v1567->cache_dirty;
    v1674[v1883] = 0;
    int * v1676 = v1567->cache_age;
    v1676[v1883] = 1;
    int * v1678 = v1567->cache_age;
    int v1679 = v1678[v1883];
    int * v1680 = v1567->cache_age;
    int v1681 = v1680[0];
    int * v1682 = v1567->cache_age;
    int v1889 = v1681 + ((int)((unsigned int)(v1681 - v1679) >> 31));
    v1682[0] = v1889;
    int * v1684 = v1567->cache_age;
    int v1685 = v1684[1];
    int * v1686 = v1567->cache_age;
    int v1892 = v1685 + ((int)((unsigned int)(v1685 - v1679) >> 31));
    v1686[1] = v1892;
    int * v1688 = v1567->cache_age;
    v1688[v1883] = 0;
    v1691 = v1883;
  }
  int v1895 = v1691 * 2;
  int v1692 = v1578[v1895];
  int * v1693 = v1567->regs;
  v1693[14] = v1692;
  return v1426;
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
  v52[10] = 80;
  struct StateT * v54 = v38->b;
  int * v55 = v54->regs;
  v55[10] = 80;
  struct StateT2 * v57 = slot_2(v38);
  return v57;
}

struct StateT2 * slot_8(struct StateT2 * v1302) {
  struct StateT * v1303 = v1302->a;
  int v1304 = v1303->timer;
  struct StateT * v1305 = v1302->b;
  int v1306 = v1305->timer;
  bool v1359 = v1304 == v1306;
  squared_assert(v1359);
  squared_assume(v1359);
  struct StateT * v1309 = v1302->a;
  int * v1310 = v1309->regs;
  int v1311 = v1310[10];
  int * v1312 = v1309->regs;
  int v1313 = v1312[15];
  struct StateT * v1314 = v1302->b;
  int * v1315 = v1314->regs;
  int v1316 = v1315[10];
  int * v1317 = v1314->regs;
  int v1318 = v1317[15];
  bool v1368 = (v1311 >= v1313) == (v1316 >= v1318);
  squared_assert(v1368);
  squared_assume(v1368);
  bool v1369 = v1311 >= v1313;
  struct StateT2 * v1355;
  if (v1369) {
    struct StateT * v1321 = v1302->a;
    int v1322 = v1321->timer;
    int v1371 = v1322 + 15;
    v1321->timer = v1371;
    int * v1324 = v1321->saved_regs;
    int v1325 = v1324[5];
    int * v1326 = v1321->regs;
    v1326[5] = v1325;
    int * v1328 = v1321->saved_regs;
    int v1329 = v1328[11];
    int * v1330 = v1321->regs;
    v1330[11] = v1329;
    int * v1332 = v1321->saved_regs;
    int v1333 = v1332[12];
    int * v1334 = v1321->regs;
    v1334[12] = v1333;
    struct StateT * v1336 = v1302->b;
    int v1337 = v1336->timer;
    int v1385 = v1337 + 15;
    v1336->timer = v1385;
    int * v1339 = v1336->saved_regs;
    int v1340 = v1339[5];
    int * v1341 = v1336->regs;
    v1341[5] = v1340;
    int * v1343 = v1336->saved_regs;
    int v1344 = v1343[11];
    int * v1345 = v1336->regs;
    v1345[11] = v1344;
    int * v1347 = v1336->saved_regs;
    int v1348 = v1347[12];
    int * v1349 = v1336->regs;
    v1349[12] = v1348;
    struct StateT2 * v1351 = slot_9(v1302);
    v1355 = v1351;
  } else {
    struct StateT2 * v1353 = slot_9(v1302);
    v1355 = v1353;
  }
  return v1355;
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
  int v144 = v143[5];
  v142[5] = v144;
  struct StateT * v146 = v134->b;
  int * v147 = v146->saved_regs;
  int * v148 = v146->regs;
  int v149 = v148[5];
  v147[5] = v149;
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
  int v159 = v158[13];
  int * v160 = v157->regs;
  int v161 = v160[10];
  int * v162 = v157->regs;
  int v195 = v159 + v161;
  v162[5] = v195;
  struct StateT * v164 = v134->b;
  int * v165 = v164->regs;
  int v166 = v165[13];
  int * v167 = v164->regs;
  int v168 = v167[10];
  int * v169 = v164->regs;
  int v200 = v166 + v168;
  v169[5] = v200;
  struct StateT2 * v171 = slot_5(v134);
  return v171;
}

struct StateT2 * slot_9(struct StateT2 * v1400) {
  struct StateT * v1401 = v1400->a;
  int v1402 = v1401->timer;
  struct StateT * v1403 = v1400->b;
  int v1404 = v1403->timer;
  bool v1419 = v1402 == v1404;
  squared_assert(v1419);
  squared_assume(v1419);
  struct StateT * v1407 = v1400->a;
  int v1408 = v1407->timer;
  int v1421 = v1408 + 1;
  v1407->timer = v1421;
  struct StateT * v1410 = v1400->b;
  int v1411 = v1410->timer;
  int v1423 = v1411 + 1;
  v1410->timer = v1423;
  struct StateT * v1413 = v1400->a;
  struct StateT * v1414 = v1400->b;
  struct StateT2 * v1415 = slot_10(v1400);
  return v1415;
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
  v16[13] = 0;
  struct StateT * v18 = v2->b;
  int * v19 = v18->regs;
  v19[13] = 0;
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

void squared_assert(bool c) { koika_assert(c, "squared drift"); }
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