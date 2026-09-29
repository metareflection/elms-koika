// verify: leak (Eva should report untainted: unknown) [unroll 65]
#define NUM_REGS 32
#define MEM_SIZE 64
#define SECRET_SIZE 10
#define SECRET_OFFSET 20
#define CACHE_ENTRIES 12
#define CACHE_WORDS 24

#ifdef EVA
#include "__fc_builtin.h"
/*@ requires untainted: !\tainted(b);
    assigns \nothing; */
void koika_check(int b);
/*@ assigns *p \from \nothing;
    taints *p; */
void koika_mark(int *p);
#define koika_assert(b, s) koika_check(b)
#define koika_assume(b) do { if (!(b)) Frama_C_abort(); } while (0)
#define koika_draw(x) ((x) = Frama_C_interval(-2147483647-1, 2147483647))
#define koika_secret(x) koika_mark(&(x))
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

struct StateT2 * slot_6(struct StateT2 * v231);
struct StateT2 * slot_29(struct StateT2 * v2777);
struct StateT2 * slot_25(struct StateT2 * v2663);
struct StateT2 * slot_16(struct StateT2 * v1487);
struct StateT2 * slot_23(struct StateT2 * v2118);
struct StateT2 * slot_5(struct StateT2 * v170);
struct StateT2 * slot_2(struct StateT2 * v74);
struct StateT2 * slot_7(struct StateT2 * v667);
struct StateT2 * slot_3(struct StateT2 * v110);
struct StateT2 * slot_26(struct StateT2 * v2696);
struct StateT2 * slot_1(struct StateT2 * v38);
struct StateT2 * slot_13(struct StateT2 * v1330);
struct StateT2 * slot_24(struct StateT2 * v2554);
struct StateT2 * slot_0(struct StateT2 * v2);
struct StateT2 * slot_17(struct StateT2 * v1513);
struct StateT2 * snippet(struct StateT2 * v0);
struct StateT2 * slot_4(struct StateT2 * v146);
struct StateT2 * slot_15(struct StateT2 * v1451);
struct StateT2 * slot_6(struct StateT2 * v231) {
  struct StateT * v232 = v231->a;
  int v233 = v232->timer;
  struct StateT * v234 = v231->b;
  int v235 = v234->timer;
  bool v472 = v233 == v235;
  squared_assert(v472);
  squared_assume(v472);
  struct StateT * v238 = v231->a;
  int * v239 = v238->saved_regs;
  int * v240 = v238->regs;
  int v241 = v240[10];
  v239[10] = v241;
  struct StateT * v243 = v231->b;
  int * v244 = v243->saved_regs;
  int * v245 = v243->regs;
  int v246 = v245[10];
  v244[10] = v246;
  struct StateT * v248 = v231->a;
  int v249 = v248->timer;
  int v483 = v249 + 1;
  v248->timer = v483;
  struct StateT * v251 = v231->b;
  int v252 = v251->timer;
  int v485 = v252 + 1;
  v251->timer = v485;
  struct StateT * v254 = v231->a;
  int * v255 = v254->regs;
  int v256 = v255[5];
  int * v257 = v254->cache_tags;
  int v490 = (((int)((unsigned int)((int)((unsigned int)v256 >> 2)) >> 1)) & 1) * 2;
  int v258 = v257[v490];
  int v491 = ((((int)((unsigned int)((int)((unsigned int)v256 >> 2)) >> 1)) & 1) * 2) + 1;
  int v259 = v257[v491];
  int v492 = 4 + ((((int)((unsigned int)((int)((unsigned int)v256 >> 2)) >> 1)) & 3) * 2);
  int v260 = v257[v492];
  int v493 = (4 + ((((int)((unsigned int)((int)((unsigned int)v256 >> 2)) >> 1)) & 3) * 2)) + 1;
  int v261 = v257[v493];
  int v262 = v254->timer;
  int v494 = v262 + ((100 ^ (((~(((v260 ^ ((int)((unsigned int)((int)((unsigned int)v256 >> 2)) >> 1))) | (-(v260 ^ ((int)((unsigned int)((int)((unsigned int)v256 >> 2)) >> 1))))) >> 31)) | (~(((v261 ^ ((int)((unsigned int)((int)((unsigned int)v256 >> 2)) >> 1))) | (-(v261 ^ ((int)((unsigned int)((int)((unsigned int)v256 >> 2)) >> 1))))) >> 31))) & 104)) ^ (((~(((v258 ^ ((int)((unsigned int)((int)((unsigned int)v256 >> 2)) >> 1))) | (-(v258 ^ ((int)((unsigned int)((int)((unsigned int)v256 >> 2)) >> 1))))) >> 31)) | (~(((v259 ^ ((int)((unsigned int)((int)((unsigned int)v256 >> 2)) >> 1))) | (-(v259 ^ ((int)((unsigned int)((int)((unsigned int)v256 >> 2)) >> 1))))) >> 31))) & (1 ^ (100 ^ (((~(((v260 ^ ((int)((unsigned int)((int)((unsigned int)v256 >> 2)) >> 1))) | (-(v260 ^ ((int)((unsigned int)((int)((unsigned int)v256 >> 2)) >> 1))))) >> 31)) | (~(((v261 ^ ((int)((unsigned int)((int)((unsigned int)v256 >> 2)) >> 1))) | (-(v261 ^ ((int)((unsigned int)((int)((unsigned int)v256 >> 2)) >> 1))))) >> 31))) & 104)))));
  v254->timer = v494;
  int * v264 = v254->cache_vals;
  bool v495 = !(((~(((v258 ^ ((int)((unsigned int)((int)((unsigned int)v256 >> 2)) >> 1))) | (-(v258 ^ ((int)((unsigned int)((int)((unsigned int)v256 >> 2)) >> 1))))) >> 31)) | (~(((v259 ^ ((int)((unsigned int)((int)((unsigned int)v256 >> 2)) >> 1))) | (-(v259 ^ ((int)((unsigned int)((int)((unsigned int)v256 >> 2)) >> 1))))) >> 31))) == 0);
  int v357;
  if (v495) {
    int * v265 = v254->cache_age;
    int v497 = ((((int)((unsigned int)((int)((unsigned int)v256 >> 2)) >> 1)) & 1) * 2) + ((~(((v259 ^ ((int)((unsigned int)((int)((unsigned int)v256 >> 2)) >> 1))) | (-(v259 ^ ((int)((unsigned int)((int)((unsigned int)v256 >> 2)) >> 1))))) >> 31)) & 1);
    int v266 = v265[v497];
    int v267 = v265[v490];
    int v498 = v267 + ((int)((unsigned int)(v267 - v266) >> 31));
    v265[v490] = v498;
    int * v269 = v254->cache_age;
    int v270 = v269[v491];
    int v500 = v270 + ((int)((unsigned int)(v270 - v266) >> 31));
    v269[v491] = v500;
    int * v272 = v254->cache_age;
    v272[v497] = 0;
    v357 = v497;
  } else {
    int * v275 = v254->cache_age;
    int v504 = (((int)((unsigned int)((int)((unsigned int)v256 >> 2)) >> 1)) & 1) * 2;
    int v276 = v275[v504];
    int * v277 = v254->cache_tags;
    int v278 = v277[v504];
    int v279 = v275[v491];
    int v280 = v277[v491];
    bool v506 = !(((~(((v260 ^ ((int)((unsigned int)((int)((unsigned int)v256 >> 2)) >> 1))) | (-(v260 ^ ((int)((unsigned int)((int)((unsigned int)v256 >> 2)) >> 1))))) >> 31)) | (~(((v261 ^ ((int)((unsigned int)((int)((unsigned int)v256 >> 2)) >> 1))) | (-(v261 ^ ((int)((unsigned int)((int)((unsigned int)v256 >> 2)) >> 1))))) >> 31))) == 0);
    int v334;
    if (v506) {
      int * v281 = v254->cache_age;
      int v508 = (4 + ((((int)((unsigned int)((int)((unsigned int)v256 >> 2)) >> 1)) & 3) * 2)) + ((~(((v261 ^ ((int)((unsigned int)((int)((unsigned int)v256 >> 2)) >> 1))) | (-(v261 ^ ((int)((unsigned int)((int)((unsigned int)v256 >> 2)) >> 1))))) >> 31)) & 1);
      int v282 = v281[v508];
      int v283 = v281[v492];
      int v509 = v283 + ((int)((unsigned int)(v283 - v282) >> 31));
      v281[v492] = v509;
      int * v285 = v254->cache_age;
      int v286 = v285[v493];
      int v511 = v286 + ((int)((unsigned int)(v286 - v282) >> 31));
      v285[v493] = v511;
      int * v288 = v254->cache_age;
      v288[v508] = 0;
      v334 = v508;
    } else {
      int * v291 = v254->cache_age;
      int v515 = 4 + ((((int)((unsigned int)((int)((unsigned int)v256 >> 2)) >> 1)) & 3) * 2);
      int v292 = v291[v515];
      int * v293 = v254->cache_tags;
      int v294 = v293[v515];
      int v295 = v291[v493];
      int v296 = v293[v493];
      int * v297 = v254->cache_dirty;
      int v518 = (4 + ((((int)((unsigned int)((int)((unsigned int)v256 >> 2)) >> 1)) & 3) * 2)) + ((((v292 + ((~(((v294 ^ -1) | (-(v294 ^ -1))) >> 31)) & 2)) - (v295 + ((~(((v296 ^ -1) | (-(v296 ^ -1))) >> 31)) & 2))) >> 31) & 1);
      int v298 = v297[v518];
      bool v519 = !(v298 == 0);
      if (v519) {
        int * v299 = v254->cache_tags;
        int v300 = v299[v518];
        int * v301 = v254->cache_vals;
        int v522 = ((4 + ((((int)((unsigned int)((int)((unsigned int)v256 >> 2)) >> 1)) & 3) * 2)) + ((((v292 + ((~(((v294 ^ -1) | (-(v294 ^ -1))) >> 31)) & 2)) - (v295 + ((~(((v296 ^ -1) | (-(v296 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
        int v302 = v301[v522];
        int v523 = (((4 + ((((int)((unsigned int)((int)((unsigned int)v256 >> 2)) >> 1)) & 3) * 2)) + ((((v292 + ((~(((v294 ^ -1) | (-(v294 ^ -1))) >> 31)) & 2)) - (v295 + ((~(((v296 ^ -1) | (-(v296 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
        int v303 = v301[v523];
        int * v304 = v254->mem;
        int v525 = v300 * 2;
        v304[v525] = v302;
        int * v306 = v254->mem;
        int v528 = (v300 * 2) + 1;
        v306[v528] = v303;
        ;
      } else {
        ;
      }
      int * v311 = v254->mem;
      int v533 = ((int)((unsigned int)((int)((unsigned int)v256 >> 2)) >> 1)) * 2;
      int v312 = v311[v533];
      int v534 = (((int)((unsigned int)((int)((unsigned int)v256 >> 2)) >> 1)) * 2) + 1;
      int v313 = v311[v534];
      int * v314 = v254->cache_vals;
      int v536 = ((4 + ((((int)((unsigned int)((int)((unsigned int)v256 >> 2)) >> 1)) & 3) * 2)) + ((((v292 + ((~(((v294 ^ -1) | (-(v294 ^ -1))) >> 31)) & 2)) - (v295 + ((~(((v296 ^ -1) | (-(v296 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
      v314[v536] = v312;
      int * v316 = v254->cache_vals;
      int v539 = (((4 + ((((int)((unsigned int)((int)((unsigned int)v256 >> 2)) >> 1)) & 3) * 2)) + ((((v292 + ((~(((v294 ^ -1) | (-(v294 ^ -1))) >> 31)) & 2)) - (v295 + ((~(((v296 ^ -1) | (-(v296 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
      v316[v539] = v313;
      int * v318 = v254->cache_tags;
      int v542 = (int)((unsigned int)((int)((unsigned int)v256 >> 2)) >> 1);
      v318[v518] = v542;
      int * v320 = v254->cache_dirty;
      v320[v518] = 0;
      int * v322 = v254->cache_age;
      v322[v518] = 1;
      int * v324 = v254->cache_age;
      int v325 = v324[v518];
      int v326 = v324[v492];
      int v548 = v326 + ((int)((unsigned int)(v326 - v325) >> 31));
      v324[v492] = v548;
      int * v328 = v254->cache_age;
      int v329 = v328[v493];
      int v550 = v329 + ((int)((unsigned int)(v329 - v325) >> 31));
      v328[v493] = v550;
      int * v331 = v254->cache_age;
      v331[v518] = 0;
      v334 = v518;
    }
    int * v335 = v254->cache_vals;
    int v553 = v334 * 2;
    int v336 = v335[v553];
    int v554 = (v334 * 2) + 1;
    int v337 = v335[v554];
    int v555 = (((((int)((unsigned int)((int)((unsigned int)v256 >> 2)) >> 1)) & 1) * 2) + ((((v276 + ((~(((v278 ^ -1) | (-(v278 ^ -1))) >> 31)) & 2)) - (v279 + ((~(((v280 ^ -1) | (-(v280 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
    v335[v555] = v336;
    int * v339 = v254->cache_vals;
    int v558 = ((((((int)((unsigned int)((int)((unsigned int)v256 >> 2)) >> 1)) & 1) * 2) + ((((v276 + ((~(((v278 ^ -1) | (-(v278 ^ -1))) >> 31)) & 2)) - (v279 + ((~(((v280 ^ -1) | (-(v280 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
    v339[v558] = v337;
    int * v341 = v254->cache_tags;
    int v561 = ((((int)((unsigned int)((int)((unsigned int)v256 >> 2)) >> 1)) & 1) * 2) + ((((v276 + ((~(((v278 ^ -1) | (-(v278 ^ -1))) >> 31)) & 2)) - (v279 + ((~(((v280 ^ -1) | (-(v280 ^ -1))) >> 31)) & 2))) >> 31) & 1);
    int v562 = (int)((unsigned int)((int)((unsigned int)v256 >> 2)) >> 1);
    v341[v561] = v562;
    int * v343 = v254->cache_dirty;
    v343[v561] = 0;
    int * v345 = v254->cache_age;
    v345[v561] = 1;
    int * v347 = v254->cache_age;
    int v348 = v347[v561];
    int v349 = v347[v490];
    int v568 = v349 + ((int)((unsigned int)(v349 - v348) >> 31));
    v347[v490] = v568;
    int * v351 = v254->cache_age;
    int v352 = v351[v491];
    int v570 = v352 + ((int)((unsigned int)(v352 - v348) >> 31));
    v351[v491] = v570;
    int * v354 = v254->cache_age;
    v354[v561] = 0;
    v357 = v561;
  }
  int v573 = (v357 * 2) + (((int)((unsigned int)v256 >> 2)) & 1);
  int v358 = v264[v573];
  int * v359 = v254->regs;
  v359[10] = v358;
  struct StateT * v361 = v231->b;
  int * v362 = v361->regs;
  int v363 = v362[5];
  int * v364 = v361->cache_tags;
  int v579 = (((int)((unsigned int)((int)((unsigned int)v363 >> 2)) >> 1)) & 1) * 2;
  int v365 = v364[v579];
  int v580 = ((((int)((unsigned int)((int)((unsigned int)v363 >> 2)) >> 1)) & 1) * 2) + 1;
  int v366 = v364[v580];
  int v581 = 4 + ((((int)((unsigned int)((int)((unsigned int)v363 >> 2)) >> 1)) & 3) * 2);
  int v367 = v364[v581];
  int v582 = (4 + ((((int)((unsigned int)((int)((unsigned int)v363 >> 2)) >> 1)) & 3) * 2)) + 1;
  int v368 = v364[v582];
  int v369 = v361->timer;
  int v583 = v369 + ((100 ^ (((~(((v367 ^ ((int)((unsigned int)((int)((unsigned int)v363 >> 2)) >> 1))) | (-(v367 ^ ((int)((unsigned int)((int)((unsigned int)v363 >> 2)) >> 1))))) >> 31)) | (~(((v368 ^ ((int)((unsigned int)((int)((unsigned int)v363 >> 2)) >> 1))) | (-(v368 ^ ((int)((unsigned int)((int)((unsigned int)v363 >> 2)) >> 1))))) >> 31))) & 104)) ^ (((~(((v365 ^ ((int)((unsigned int)((int)((unsigned int)v363 >> 2)) >> 1))) | (-(v365 ^ ((int)((unsigned int)((int)((unsigned int)v363 >> 2)) >> 1))))) >> 31)) | (~(((v366 ^ ((int)((unsigned int)((int)((unsigned int)v363 >> 2)) >> 1))) | (-(v366 ^ ((int)((unsigned int)((int)((unsigned int)v363 >> 2)) >> 1))))) >> 31))) & (1 ^ (100 ^ (((~(((v367 ^ ((int)((unsigned int)((int)((unsigned int)v363 >> 2)) >> 1))) | (-(v367 ^ ((int)((unsigned int)((int)((unsigned int)v363 >> 2)) >> 1))))) >> 31)) | (~(((v368 ^ ((int)((unsigned int)((int)((unsigned int)v363 >> 2)) >> 1))) | (-(v368 ^ ((int)((unsigned int)((int)((unsigned int)v363 >> 2)) >> 1))))) >> 31))) & 104)))));
  v361->timer = v583;
  int * v371 = v361->cache_vals;
  bool v584 = !(((~(((v365 ^ ((int)((unsigned int)((int)((unsigned int)v363 >> 2)) >> 1))) | (-(v365 ^ ((int)((unsigned int)((int)((unsigned int)v363 >> 2)) >> 1))))) >> 31)) | (~(((v366 ^ ((int)((unsigned int)((int)((unsigned int)v363 >> 2)) >> 1))) | (-(v366 ^ ((int)((unsigned int)((int)((unsigned int)v363 >> 2)) >> 1))))) >> 31))) == 0);
  int v464;
  if (v584) {
    int * v372 = v361->cache_age;
    int v586 = ((((int)((unsigned int)((int)((unsigned int)v363 >> 2)) >> 1)) & 1) * 2) + ((~(((v366 ^ ((int)((unsigned int)((int)((unsigned int)v363 >> 2)) >> 1))) | (-(v366 ^ ((int)((unsigned int)((int)((unsigned int)v363 >> 2)) >> 1))))) >> 31)) & 1);
    int v373 = v372[v586];
    int v374 = v372[v579];
    int v587 = v374 + ((int)((unsigned int)(v374 - v373) >> 31));
    v372[v579] = v587;
    int * v376 = v361->cache_age;
    int v377 = v376[v580];
    int v589 = v377 + ((int)((unsigned int)(v377 - v373) >> 31));
    v376[v580] = v589;
    int * v379 = v361->cache_age;
    v379[v586] = 0;
    v464 = v586;
  } else {
    int * v382 = v361->cache_age;
    int v593 = (((int)((unsigned int)((int)((unsigned int)v363 >> 2)) >> 1)) & 1) * 2;
    int v383 = v382[v593];
    int * v384 = v361->cache_tags;
    int v385 = v384[v593];
    int v386 = v382[v580];
    int v387 = v384[v580];
    bool v595 = !(((~(((v367 ^ ((int)((unsigned int)((int)((unsigned int)v363 >> 2)) >> 1))) | (-(v367 ^ ((int)((unsigned int)((int)((unsigned int)v363 >> 2)) >> 1))))) >> 31)) | (~(((v368 ^ ((int)((unsigned int)((int)((unsigned int)v363 >> 2)) >> 1))) | (-(v368 ^ ((int)((unsigned int)((int)((unsigned int)v363 >> 2)) >> 1))))) >> 31))) == 0);
    int v441;
    if (v595) {
      int * v388 = v361->cache_age;
      int v597 = (4 + ((((int)((unsigned int)((int)((unsigned int)v363 >> 2)) >> 1)) & 3) * 2)) + ((~(((v368 ^ ((int)((unsigned int)((int)((unsigned int)v363 >> 2)) >> 1))) | (-(v368 ^ ((int)((unsigned int)((int)((unsigned int)v363 >> 2)) >> 1))))) >> 31)) & 1);
      int v389 = v388[v597];
      int v390 = v388[v581];
      int v598 = v390 + ((int)((unsigned int)(v390 - v389) >> 31));
      v388[v581] = v598;
      int * v392 = v361->cache_age;
      int v393 = v392[v582];
      int v600 = v393 + ((int)((unsigned int)(v393 - v389) >> 31));
      v392[v582] = v600;
      int * v395 = v361->cache_age;
      v395[v597] = 0;
      v441 = v597;
    } else {
      int * v398 = v361->cache_age;
      int v604 = 4 + ((((int)((unsigned int)((int)((unsigned int)v363 >> 2)) >> 1)) & 3) * 2);
      int v399 = v398[v604];
      int * v400 = v361->cache_tags;
      int v401 = v400[v604];
      int v402 = v398[v582];
      int v403 = v400[v582];
      int * v404 = v361->cache_dirty;
      int v607 = (4 + ((((int)((unsigned int)((int)((unsigned int)v363 >> 2)) >> 1)) & 3) * 2)) + ((((v399 + ((~(((v401 ^ -1) | (-(v401 ^ -1))) >> 31)) & 2)) - (v402 + ((~(((v403 ^ -1) | (-(v403 ^ -1))) >> 31)) & 2))) >> 31) & 1);
      int v405 = v404[v607];
      bool v608 = !(v405 == 0);
      if (v608) {
        int * v406 = v361->cache_tags;
        int v407 = v406[v607];
        int * v408 = v361->cache_vals;
        int v611 = ((4 + ((((int)((unsigned int)((int)((unsigned int)v363 >> 2)) >> 1)) & 3) * 2)) + ((((v399 + ((~(((v401 ^ -1) | (-(v401 ^ -1))) >> 31)) & 2)) - (v402 + ((~(((v403 ^ -1) | (-(v403 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
        int v409 = v408[v611];
        int v612 = (((4 + ((((int)((unsigned int)((int)((unsigned int)v363 >> 2)) >> 1)) & 3) * 2)) + ((((v399 + ((~(((v401 ^ -1) | (-(v401 ^ -1))) >> 31)) & 2)) - (v402 + ((~(((v403 ^ -1) | (-(v403 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
        int v410 = v408[v612];
        int * v411 = v361->mem;
        int v614 = v407 * 2;
        v411[v614] = v409;
        int * v413 = v361->mem;
        int v617 = (v407 * 2) + 1;
        v413[v617] = v410;
        ;
      } else {
        ;
      }
      int * v418 = v361->mem;
      int v622 = ((int)((unsigned int)((int)((unsigned int)v363 >> 2)) >> 1)) * 2;
      int v419 = v418[v622];
      int v623 = (((int)((unsigned int)((int)((unsigned int)v363 >> 2)) >> 1)) * 2) + 1;
      int v420 = v418[v623];
      int * v421 = v361->cache_vals;
      int v625 = ((4 + ((((int)((unsigned int)((int)((unsigned int)v363 >> 2)) >> 1)) & 3) * 2)) + ((((v399 + ((~(((v401 ^ -1) | (-(v401 ^ -1))) >> 31)) & 2)) - (v402 + ((~(((v403 ^ -1) | (-(v403 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
      v421[v625] = v419;
      int * v423 = v361->cache_vals;
      int v628 = (((4 + ((((int)((unsigned int)((int)((unsigned int)v363 >> 2)) >> 1)) & 3) * 2)) + ((((v399 + ((~(((v401 ^ -1) | (-(v401 ^ -1))) >> 31)) & 2)) - (v402 + ((~(((v403 ^ -1) | (-(v403 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
      v423[v628] = v420;
      int * v425 = v361->cache_tags;
      int v631 = (int)((unsigned int)((int)((unsigned int)v363 >> 2)) >> 1);
      v425[v607] = v631;
      int * v427 = v361->cache_dirty;
      v427[v607] = 0;
      int * v429 = v361->cache_age;
      v429[v607] = 1;
      int * v431 = v361->cache_age;
      int v432 = v431[v607];
      int v433 = v431[v581];
      int v637 = v433 + ((int)((unsigned int)(v433 - v432) >> 31));
      v431[v581] = v637;
      int * v435 = v361->cache_age;
      int v436 = v435[v582];
      int v639 = v436 + ((int)((unsigned int)(v436 - v432) >> 31));
      v435[v582] = v639;
      int * v438 = v361->cache_age;
      v438[v607] = 0;
      v441 = v607;
    }
    int * v442 = v361->cache_vals;
    int v642 = v441 * 2;
    int v443 = v442[v642];
    int v643 = (v441 * 2) + 1;
    int v444 = v442[v643];
    int v644 = (((((int)((unsigned int)((int)((unsigned int)v363 >> 2)) >> 1)) & 1) * 2) + ((((v383 + ((~(((v385 ^ -1) | (-(v385 ^ -1))) >> 31)) & 2)) - (v386 + ((~(((v387 ^ -1) | (-(v387 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
    v442[v644] = v443;
    int * v446 = v361->cache_vals;
    int v647 = ((((((int)((unsigned int)((int)((unsigned int)v363 >> 2)) >> 1)) & 1) * 2) + ((((v383 + ((~(((v385 ^ -1) | (-(v385 ^ -1))) >> 31)) & 2)) - (v386 + ((~(((v387 ^ -1) | (-(v387 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
    v446[v647] = v444;
    int * v448 = v361->cache_tags;
    int v650 = ((((int)((unsigned int)((int)((unsigned int)v363 >> 2)) >> 1)) & 1) * 2) + ((((v383 + ((~(((v385 ^ -1) | (-(v385 ^ -1))) >> 31)) & 2)) - (v386 + ((~(((v387 ^ -1) | (-(v387 ^ -1))) >> 31)) & 2))) >> 31) & 1);
    int v651 = (int)((unsigned int)((int)((unsigned int)v363 >> 2)) >> 1);
    v448[v650] = v651;
    int * v450 = v361->cache_dirty;
    v450[v650] = 0;
    int * v452 = v361->cache_age;
    v452[v650] = 1;
    int * v454 = v361->cache_age;
    int v455 = v454[v650];
    int v456 = v454[v579];
    int v657 = v456 + ((int)((unsigned int)(v456 - v455) >> 31));
    v454[v579] = v657;
    int * v458 = v361->cache_age;
    int v459 = v458[v580];
    int v659 = v459 + ((int)((unsigned int)(v459 - v455) >> 31));
    v458[v580] = v659;
    int * v461 = v361->cache_age;
    v461[v650] = 0;
    v464 = v650;
  }
  int v662 = (v464 * 2) + (((int)((unsigned int)v363 >> 2)) & 1);
  int v465 = v371[v662];
  int * v466 = v361->regs;
  v466[10] = v465;
  struct StateT2 * v468 = slot_7(v231);
  return v468;
}

struct StateT2 * slot_29(struct StateT2 * v2777) {
  struct StateT * v2778 = v2777->a;
  int v2779 = v2778->timer;
  struct StateT * v2780 = v2777->b;
  int v2781 = v2780->timer;
  bool v2816 = v2779 == v2781;
  squared_assert(v2816);
  squared_assume(v2816);
  struct StateT * v2784 = v2777->a;
  int * v2785 = v2784->regs;
  int v2786 = v2785[10];
  int v2787 = v2785[11];
  struct StateT * v2788 = v2777->b;
  int * v2789 = v2788->regs;
  int v2790 = v2789[10];
  int v2791 = v2789[11];
  bool v2823 = (!(v2786 == v2787)) == (!(v2790 == v2791));
  squared_diverged(v2823);
  squared_assume(v2823);
  bool v2824 = !(v2786 == v2787);
  struct StateT2 * v2812;
  if (v2824) {
    struct StateT * v2794 = v2777->a;
    int v2795 = v2794->timer;
    int v2826 = v2795 + 15;
    v2794->timer = v2826;
    int * v2797 = v2794->saved_regs;
    int v2798 = v2797[14];
    int * v2799 = v2794->regs;
    v2799[14] = v2798;
    struct StateT * v2801 = v2777->b;
    int v2802 = v2801->timer;
    int v2832 = v2802 + 15;
    v2801->timer = v2832;
    int * v2804 = v2801->saved_regs;
    int v2805 = v2804[14];
    int * v2806 = v2801->regs;
    v2806[14] = v2805;
    struct StateT2 * v2808 = slot_15(v2777);
    v2812 = v2808;
  } else {
    struct StateT2 * v2810 = slot_16(v2777);
    v2812 = v2810;
  }
  return v2812;
}

struct StateT2 * slot_25(struct StateT2 * v2663) {
  struct StateT * v2664 = v2663->a;
  int v2665 = v2664->timer;
  struct StateT * v2666 = v2663->b;
  int v2667 = v2666->timer;
  bool v2685 = v2665 == v2667;
  squared_assert(v2685);
  squared_assume(v2685);
  struct StateT * v2670 = v2663->a;
  int v2671 = v2670->timer;
  int v2687 = v2671 + 1;
  v2670->timer = v2687;
  struct StateT * v2673 = v2663->b;
  int v2674 = v2673->timer;
  int v2689 = v2674 + 1;
  v2673->timer = v2689;
  struct StateT * v2676 = v2663->a;
  int * v2677 = v2676->regs;
  v2677[10] = 1;
  struct StateT * v2679 = v2663->b;
  int * v2680 = v2679->regs;
  v2680[10] = 1;
  return v2663;
}

struct StateT2 * slot_16(struct StateT2 * v1487) {
  struct StateT * v1488 = v1487->a;
  int v1489 = v1488->timer;
  struct StateT * v1490 = v1487->b;
  int v1491 = v1490->timer;
  bool v1506 = v1489 == v1491;
  squared_assert(v1506);
  squared_assume(v1506);
  struct StateT * v1494 = v1487->a;
  int v1495 = v1494->timer;
  int v1508 = v1495 + 1;
  v1494->timer = v1508;
  struct StateT * v1497 = v1487->b;
  int v1498 = v1497->timer;
  int v1510 = v1498 + 1;
  v1497->timer = v1510;
  struct StateT2 * v1502 = slot_4(v1487);
  return v1502;
}

struct StateT2 * slot_23(struct StateT2 * v2118) {
  struct StateT * v2119 = v2118->a;
  int v2120 = v2119->timer;
  struct StateT * v2121 = v2118->b;
  int v2122 = v2121->timer;
  bool v2359 = v2120 == v2122;
  squared_assert(v2359);
  squared_assume(v2359);
  struct StateT * v2125 = v2118->a;
  int * v2126 = v2125->saved_regs;
  int * v2127 = v2125->regs;
  int v2128 = v2127[11];
  v2126[11] = v2128;
  struct StateT * v2130 = v2118->b;
  int * v2131 = v2130->saved_regs;
  int * v2132 = v2130->regs;
  int v2133 = v2132[11];
  v2131[11] = v2133;
  struct StateT * v2135 = v2118->a;
  int v2136 = v2135->timer;
  int v2370 = v2136 + 1;
  v2135->timer = v2370;
  struct StateT * v2138 = v2118->b;
  int v2139 = v2138->timer;
  int v2372 = v2139 + 1;
  v2138->timer = v2372;
  struct StateT * v2141 = v2118->a;
  int * v2142 = v2141->regs;
  int v2143 = v2142[6];
  int * v2144 = v2141->cache_tags;
  int v2377 = (((int)((unsigned int)((int)((unsigned int)v2143 >> 2)) >> 1)) & 1) * 2;
  int v2145 = v2144[v2377];
  int v2378 = ((((int)((unsigned int)((int)((unsigned int)v2143 >> 2)) >> 1)) & 1) * 2) + 1;
  int v2146 = v2144[v2378];
  int v2379 = 4 + ((((int)((unsigned int)((int)((unsigned int)v2143 >> 2)) >> 1)) & 3) * 2);
  int v2147 = v2144[v2379];
  int v2380 = (4 + ((((int)((unsigned int)((int)((unsigned int)v2143 >> 2)) >> 1)) & 3) * 2)) + 1;
  int v2148 = v2144[v2380];
  int v2149 = v2141->timer;
  int v2381 = v2149 + ((100 ^ (((~(((v2147 ^ ((int)((unsigned int)((int)((unsigned int)v2143 >> 2)) >> 1))) | (-(v2147 ^ ((int)((unsigned int)((int)((unsigned int)v2143 >> 2)) >> 1))))) >> 31)) | (~(((v2148 ^ ((int)((unsigned int)((int)((unsigned int)v2143 >> 2)) >> 1))) | (-(v2148 ^ ((int)((unsigned int)((int)((unsigned int)v2143 >> 2)) >> 1))))) >> 31))) & 104)) ^ (((~(((v2145 ^ ((int)((unsigned int)((int)((unsigned int)v2143 >> 2)) >> 1))) | (-(v2145 ^ ((int)((unsigned int)((int)((unsigned int)v2143 >> 2)) >> 1))))) >> 31)) | (~(((v2146 ^ ((int)((unsigned int)((int)((unsigned int)v2143 >> 2)) >> 1))) | (-(v2146 ^ ((int)((unsigned int)((int)((unsigned int)v2143 >> 2)) >> 1))))) >> 31))) & (1 ^ (100 ^ (((~(((v2147 ^ ((int)((unsigned int)((int)((unsigned int)v2143 >> 2)) >> 1))) | (-(v2147 ^ ((int)((unsigned int)((int)((unsigned int)v2143 >> 2)) >> 1))))) >> 31)) | (~(((v2148 ^ ((int)((unsigned int)((int)((unsigned int)v2143 >> 2)) >> 1))) | (-(v2148 ^ ((int)((unsigned int)((int)((unsigned int)v2143 >> 2)) >> 1))))) >> 31))) & 104)))));
  v2141->timer = v2381;
  int * v2151 = v2141->cache_vals;
  bool v2382 = !(((~(((v2145 ^ ((int)((unsigned int)((int)((unsigned int)v2143 >> 2)) >> 1))) | (-(v2145 ^ ((int)((unsigned int)((int)((unsigned int)v2143 >> 2)) >> 1))))) >> 31)) | (~(((v2146 ^ ((int)((unsigned int)((int)((unsigned int)v2143 >> 2)) >> 1))) | (-(v2146 ^ ((int)((unsigned int)((int)((unsigned int)v2143 >> 2)) >> 1))))) >> 31))) == 0);
  int v2244;
  if (v2382) {
    int * v2152 = v2141->cache_age;
    int v2384 = ((((int)((unsigned int)((int)((unsigned int)v2143 >> 2)) >> 1)) & 1) * 2) + ((~(((v2146 ^ ((int)((unsigned int)((int)((unsigned int)v2143 >> 2)) >> 1))) | (-(v2146 ^ ((int)((unsigned int)((int)((unsigned int)v2143 >> 2)) >> 1))))) >> 31)) & 1);
    int v2153 = v2152[v2384];
    int v2154 = v2152[v2377];
    int v2385 = v2154 + ((int)((unsigned int)(v2154 - v2153) >> 31));
    v2152[v2377] = v2385;
    int * v2156 = v2141->cache_age;
    int v2157 = v2156[v2378];
    int v2387 = v2157 + ((int)((unsigned int)(v2157 - v2153) >> 31));
    v2156[v2378] = v2387;
    int * v2159 = v2141->cache_age;
    v2159[v2384] = 0;
    v2244 = v2384;
  } else {
    int * v2162 = v2141->cache_age;
    int v2391 = (((int)((unsigned int)((int)((unsigned int)v2143 >> 2)) >> 1)) & 1) * 2;
    int v2163 = v2162[v2391];
    int * v2164 = v2141->cache_tags;
    int v2165 = v2164[v2391];
    int v2166 = v2162[v2378];
    int v2167 = v2164[v2378];
    bool v2393 = !(((~(((v2147 ^ ((int)((unsigned int)((int)((unsigned int)v2143 >> 2)) >> 1))) | (-(v2147 ^ ((int)((unsigned int)((int)((unsigned int)v2143 >> 2)) >> 1))))) >> 31)) | (~(((v2148 ^ ((int)((unsigned int)((int)((unsigned int)v2143 >> 2)) >> 1))) | (-(v2148 ^ ((int)((unsigned int)((int)((unsigned int)v2143 >> 2)) >> 1))))) >> 31))) == 0);
    int v2221;
    if (v2393) {
      int * v2168 = v2141->cache_age;
      int v2395 = (4 + ((((int)((unsigned int)((int)((unsigned int)v2143 >> 2)) >> 1)) & 3) * 2)) + ((~(((v2148 ^ ((int)((unsigned int)((int)((unsigned int)v2143 >> 2)) >> 1))) | (-(v2148 ^ ((int)((unsigned int)((int)((unsigned int)v2143 >> 2)) >> 1))))) >> 31)) & 1);
      int v2169 = v2168[v2395];
      int v2170 = v2168[v2379];
      int v2396 = v2170 + ((int)((unsigned int)(v2170 - v2169) >> 31));
      v2168[v2379] = v2396;
      int * v2172 = v2141->cache_age;
      int v2173 = v2172[v2380];
      int v2398 = v2173 + ((int)((unsigned int)(v2173 - v2169) >> 31));
      v2172[v2380] = v2398;
      int * v2175 = v2141->cache_age;
      v2175[v2395] = 0;
      v2221 = v2395;
    } else {
      int * v2178 = v2141->cache_age;
      int v2402 = 4 + ((((int)((unsigned int)((int)((unsigned int)v2143 >> 2)) >> 1)) & 3) * 2);
      int v2179 = v2178[v2402];
      int * v2180 = v2141->cache_tags;
      int v2181 = v2180[v2402];
      int v2182 = v2178[v2380];
      int v2183 = v2180[v2380];
      int * v2184 = v2141->cache_dirty;
      int v2405 = (4 + ((((int)((unsigned int)((int)((unsigned int)v2143 >> 2)) >> 1)) & 3) * 2)) + ((((v2179 + ((~(((v2181 ^ -1) | (-(v2181 ^ -1))) >> 31)) & 2)) - (v2182 + ((~(((v2183 ^ -1) | (-(v2183 ^ -1))) >> 31)) & 2))) >> 31) & 1);
      int v2185 = v2184[v2405];
      bool v2406 = !(v2185 == 0);
      if (v2406) {
        int * v2186 = v2141->cache_tags;
        int v2187 = v2186[v2405];
        int * v2188 = v2141->cache_vals;
        int v2409 = ((4 + ((((int)((unsigned int)((int)((unsigned int)v2143 >> 2)) >> 1)) & 3) * 2)) + ((((v2179 + ((~(((v2181 ^ -1) | (-(v2181 ^ -1))) >> 31)) & 2)) - (v2182 + ((~(((v2183 ^ -1) | (-(v2183 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
        int v2189 = v2188[v2409];
        int v2410 = (((4 + ((((int)((unsigned int)((int)((unsigned int)v2143 >> 2)) >> 1)) & 3) * 2)) + ((((v2179 + ((~(((v2181 ^ -1) | (-(v2181 ^ -1))) >> 31)) & 2)) - (v2182 + ((~(((v2183 ^ -1) | (-(v2183 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
        int v2190 = v2188[v2410];
        int * v2191 = v2141->mem;
        int v2412 = v2187 * 2;
        v2191[v2412] = v2189;
        int * v2193 = v2141->mem;
        int v2415 = (v2187 * 2) + 1;
        v2193[v2415] = v2190;
        ;
      } else {
        ;
      }
      int * v2198 = v2141->mem;
      int v2420 = ((int)((unsigned int)((int)((unsigned int)v2143 >> 2)) >> 1)) * 2;
      int v2199 = v2198[v2420];
      int v2421 = (((int)((unsigned int)((int)((unsigned int)v2143 >> 2)) >> 1)) * 2) + 1;
      int v2200 = v2198[v2421];
      int * v2201 = v2141->cache_vals;
      int v2423 = ((4 + ((((int)((unsigned int)((int)((unsigned int)v2143 >> 2)) >> 1)) & 3) * 2)) + ((((v2179 + ((~(((v2181 ^ -1) | (-(v2181 ^ -1))) >> 31)) & 2)) - (v2182 + ((~(((v2183 ^ -1) | (-(v2183 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
      v2201[v2423] = v2199;
      int * v2203 = v2141->cache_vals;
      int v2426 = (((4 + ((((int)((unsigned int)((int)((unsigned int)v2143 >> 2)) >> 1)) & 3) * 2)) + ((((v2179 + ((~(((v2181 ^ -1) | (-(v2181 ^ -1))) >> 31)) & 2)) - (v2182 + ((~(((v2183 ^ -1) | (-(v2183 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
      v2203[v2426] = v2200;
      int * v2205 = v2141->cache_tags;
      int v2429 = (int)((unsigned int)((int)((unsigned int)v2143 >> 2)) >> 1);
      v2205[v2405] = v2429;
      int * v2207 = v2141->cache_dirty;
      v2207[v2405] = 0;
      int * v2209 = v2141->cache_age;
      v2209[v2405] = 1;
      int * v2211 = v2141->cache_age;
      int v2212 = v2211[v2405];
      int v2213 = v2211[v2379];
      int v2435 = v2213 + ((int)((unsigned int)(v2213 - v2212) >> 31));
      v2211[v2379] = v2435;
      int * v2215 = v2141->cache_age;
      int v2216 = v2215[v2380];
      int v2437 = v2216 + ((int)((unsigned int)(v2216 - v2212) >> 31));
      v2215[v2380] = v2437;
      int * v2218 = v2141->cache_age;
      v2218[v2405] = 0;
      v2221 = v2405;
    }
    int * v2222 = v2141->cache_vals;
    int v2440 = v2221 * 2;
    int v2223 = v2222[v2440];
    int v2441 = (v2221 * 2) + 1;
    int v2224 = v2222[v2441];
    int v2442 = (((((int)((unsigned int)((int)((unsigned int)v2143 >> 2)) >> 1)) & 1) * 2) + ((((v2163 + ((~(((v2165 ^ -1) | (-(v2165 ^ -1))) >> 31)) & 2)) - (v2166 + ((~(((v2167 ^ -1) | (-(v2167 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
    v2222[v2442] = v2223;
    int * v2226 = v2141->cache_vals;
    int v2445 = ((((((int)((unsigned int)((int)((unsigned int)v2143 >> 2)) >> 1)) & 1) * 2) + ((((v2163 + ((~(((v2165 ^ -1) | (-(v2165 ^ -1))) >> 31)) & 2)) - (v2166 + ((~(((v2167 ^ -1) | (-(v2167 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
    v2226[v2445] = v2224;
    int * v2228 = v2141->cache_tags;
    int v2448 = ((((int)((unsigned int)((int)((unsigned int)v2143 >> 2)) >> 1)) & 1) * 2) + ((((v2163 + ((~(((v2165 ^ -1) | (-(v2165 ^ -1))) >> 31)) & 2)) - (v2166 + ((~(((v2167 ^ -1) | (-(v2167 ^ -1))) >> 31)) & 2))) >> 31) & 1);
    int v2449 = (int)((unsigned int)((int)((unsigned int)v2143 >> 2)) >> 1);
    v2228[v2448] = v2449;
    int * v2230 = v2141->cache_dirty;
    v2230[v2448] = 0;
    int * v2232 = v2141->cache_age;
    v2232[v2448] = 1;
    int * v2234 = v2141->cache_age;
    int v2235 = v2234[v2448];
    int v2236 = v2234[v2377];
    int v2455 = v2236 + ((int)((unsigned int)(v2236 - v2235) >> 31));
    v2234[v2377] = v2455;
    int * v2238 = v2141->cache_age;
    int v2239 = v2238[v2378];
    int v2457 = v2239 + ((int)((unsigned int)(v2239 - v2235) >> 31));
    v2238[v2378] = v2457;
    int * v2241 = v2141->cache_age;
    v2241[v2448] = 0;
    v2244 = v2448;
  }
  int v2460 = (v2244 * 2) + (((int)((unsigned int)v2143 >> 2)) & 1);
  int v2245 = v2151[v2460];
  int * v2246 = v2141->regs;
  v2246[11] = v2245;
  struct StateT * v2248 = v2118->b;
  int * v2249 = v2248->regs;
  int v2250 = v2249[6];
  int * v2251 = v2248->cache_tags;
  int v2466 = (((int)((unsigned int)((int)((unsigned int)v2250 >> 2)) >> 1)) & 1) * 2;
  int v2252 = v2251[v2466];
  int v2467 = ((((int)((unsigned int)((int)((unsigned int)v2250 >> 2)) >> 1)) & 1) * 2) + 1;
  int v2253 = v2251[v2467];
  int v2468 = 4 + ((((int)((unsigned int)((int)((unsigned int)v2250 >> 2)) >> 1)) & 3) * 2);
  int v2254 = v2251[v2468];
  int v2469 = (4 + ((((int)((unsigned int)((int)((unsigned int)v2250 >> 2)) >> 1)) & 3) * 2)) + 1;
  int v2255 = v2251[v2469];
  int v2256 = v2248->timer;
  int v2470 = v2256 + ((100 ^ (((~(((v2254 ^ ((int)((unsigned int)((int)((unsigned int)v2250 >> 2)) >> 1))) | (-(v2254 ^ ((int)((unsigned int)((int)((unsigned int)v2250 >> 2)) >> 1))))) >> 31)) | (~(((v2255 ^ ((int)((unsigned int)((int)((unsigned int)v2250 >> 2)) >> 1))) | (-(v2255 ^ ((int)((unsigned int)((int)((unsigned int)v2250 >> 2)) >> 1))))) >> 31))) & 104)) ^ (((~(((v2252 ^ ((int)((unsigned int)((int)((unsigned int)v2250 >> 2)) >> 1))) | (-(v2252 ^ ((int)((unsigned int)((int)((unsigned int)v2250 >> 2)) >> 1))))) >> 31)) | (~(((v2253 ^ ((int)((unsigned int)((int)((unsigned int)v2250 >> 2)) >> 1))) | (-(v2253 ^ ((int)((unsigned int)((int)((unsigned int)v2250 >> 2)) >> 1))))) >> 31))) & (1 ^ (100 ^ (((~(((v2254 ^ ((int)((unsigned int)((int)((unsigned int)v2250 >> 2)) >> 1))) | (-(v2254 ^ ((int)((unsigned int)((int)((unsigned int)v2250 >> 2)) >> 1))))) >> 31)) | (~(((v2255 ^ ((int)((unsigned int)((int)((unsigned int)v2250 >> 2)) >> 1))) | (-(v2255 ^ ((int)((unsigned int)((int)((unsigned int)v2250 >> 2)) >> 1))))) >> 31))) & 104)))));
  v2248->timer = v2470;
  int * v2258 = v2248->cache_vals;
  bool v2471 = !(((~(((v2252 ^ ((int)((unsigned int)((int)((unsigned int)v2250 >> 2)) >> 1))) | (-(v2252 ^ ((int)((unsigned int)((int)((unsigned int)v2250 >> 2)) >> 1))))) >> 31)) | (~(((v2253 ^ ((int)((unsigned int)((int)((unsigned int)v2250 >> 2)) >> 1))) | (-(v2253 ^ ((int)((unsigned int)((int)((unsigned int)v2250 >> 2)) >> 1))))) >> 31))) == 0);
  int v2351;
  if (v2471) {
    int * v2259 = v2248->cache_age;
    int v2473 = ((((int)((unsigned int)((int)((unsigned int)v2250 >> 2)) >> 1)) & 1) * 2) + ((~(((v2253 ^ ((int)((unsigned int)((int)((unsigned int)v2250 >> 2)) >> 1))) | (-(v2253 ^ ((int)((unsigned int)((int)((unsigned int)v2250 >> 2)) >> 1))))) >> 31)) & 1);
    int v2260 = v2259[v2473];
    int v2261 = v2259[v2466];
    int v2474 = v2261 + ((int)((unsigned int)(v2261 - v2260) >> 31));
    v2259[v2466] = v2474;
    int * v2263 = v2248->cache_age;
    int v2264 = v2263[v2467];
    int v2476 = v2264 + ((int)((unsigned int)(v2264 - v2260) >> 31));
    v2263[v2467] = v2476;
    int * v2266 = v2248->cache_age;
    v2266[v2473] = 0;
    v2351 = v2473;
  } else {
    int * v2269 = v2248->cache_age;
    int v2480 = (((int)((unsigned int)((int)((unsigned int)v2250 >> 2)) >> 1)) & 1) * 2;
    int v2270 = v2269[v2480];
    int * v2271 = v2248->cache_tags;
    int v2272 = v2271[v2480];
    int v2273 = v2269[v2467];
    int v2274 = v2271[v2467];
    bool v2482 = !(((~(((v2254 ^ ((int)((unsigned int)((int)((unsigned int)v2250 >> 2)) >> 1))) | (-(v2254 ^ ((int)((unsigned int)((int)((unsigned int)v2250 >> 2)) >> 1))))) >> 31)) | (~(((v2255 ^ ((int)((unsigned int)((int)((unsigned int)v2250 >> 2)) >> 1))) | (-(v2255 ^ ((int)((unsigned int)((int)((unsigned int)v2250 >> 2)) >> 1))))) >> 31))) == 0);
    int v2328;
    if (v2482) {
      int * v2275 = v2248->cache_age;
      int v2484 = (4 + ((((int)((unsigned int)((int)((unsigned int)v2250 >> 2)) >> 1)) & 3) * 2)) + ((~(((v2255 ^ ((int)((unsigned int)((int)((unsigned int)v2250 >> 2)) >> 1))) | (-(v2255 ^ ((int)((unsigned int)((int)((unsigned int)v2250 >> 2)) >> 1))))) >> 31)) & 1);
      int v2276 = v2275[v2484];
      int v2277 = v2275[v2468];
      int v2485 = v2277 + ((int)((unsigned int)(v2277 - v2276) >> 31));
      v2275[v2468] = v2485;
      int * v2279 = v2248->cache_age;
      int v2280 = v2279[v2469];
      int v2487 = v2280 + ((int)((unsigned int)(v2280 - v2276) >> 31));
      v2279[v2469] = v2487;
      int * v2282 = v2248->cache_age;
      v2282[v2484] = 0;
      v2328 = v2484;
    } else {
      int * v2285 = v2248->cache_age;
      int v2491 = 4 + ((((int)((unsigned int)((int)((unsigned int)v2250 >> 2)) >> 1)) & 3) * 2);
      int v2286 = v2285[v2491];
      int * v2287 = v2248->cache_tags;
      int v2288 = v2287[v2491];
      int v2289 = v2285[v2469];
      int v2290 = v2287[v2469];
      int * v2291 = v2248->cache_dirty;
      int v2494 = (4 + ((((int)((unsigned int)((int)((unsigned int)v2250 >> 2)) >> 1)) & 3) * 2)) + ((((v2286 + ((~(((v2288 ^ -1) | (-(v2288 ^ -1))) >> 31)) & 2)) - (v2289 + ((~(((v2290 ^ -1) | (-(v2290 ^ -1))) >> 31)) & 2))) >> 31) & 1);
      int v2292 = v2291[v2494];
      bool v2495 = !(v2292 == 0);
      if (v2495) {
        int * v2293 = v2248->cache_tags;
        int v2294 = v2293[v2494];
        int * v2295 = v2248->cache_vals;
        int v2498 = ((4 + ((((int)((unsigned int)((int)((unsigned int)v2250 >> 2)) >> 1)) & 3) * 2)) + ((((v2286 + ((~(((v2288 ^ -1) | (-(v2288 ^ -1))) >> 31)) & 2)) - (v2289 + ((~(((v2290 ^ -1) | (-(v2290 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
        int v2296 = v2295[v2498];
        int v2499 = (((4 + ((((int)((unsigned int)((int)((unsigned int)v2250 >> 2)) >> 1)) & 3) * 2)) + ((((v2286 + ((~(((v2288 ^ -1) | (-(v2288 ^ -1))) >> 31)) & 2)) - (v2289 + ((~(((v2290 ^ -1) | (-(v2290 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
        int v2297 = v2295[v2499];
        int * v2298 = v2248->mem;
        int v2501 = v2294 * 2;
        v2298[v2501] = v2296;
        int * v2300 = v2248->mem;
        int v2504 = (v2294 * 2) + 1;
        v2300[v2504] = v2297;
        ;
      } else {
        ;
      }
      int * v2305 = v2248->mem;
      int v2509 = ((int)((unsigned int)((int)((unsigned int)v2250 >> 2)) >> 1)) * 2;
      int v2306 = v2305[v2509];
      int v2510 = (((int)((unsigned int)((int)((unsigned int)v2250 >> 2)) >> 1)) * 2) + 1;
      int v2307 = v2305[v2510];
      int * v2308 = v2248->cache_vals;
      int v2512 = ((4 + ((((int)((unsigned int)((int)((unsigned int)v2250 >> 2)) >> 1)) & 3) * 2)) + ((((v2286 + ((~(((v2288 ^ -1) | (-(v2288 ^ -1))) >> 31)) & 2)) - (v2289 + ((~(((v2290 ^ -1) | (-(v2290 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
      v2308[v2512] = v2306;
      int * v2310 = v2248->cache_vals;
      int v2515 = (((4 + ((((int)((unsigned int)((int)((unsigned int)v2250 >> 2)) >> 1)) & 3) * 2)) + ((((v2286 + ((~(((v2288 ^ -1) | (-(v2288 ^ -1))) >> 31)) & 2)) - (v2289 + ((~(((v2290 ^ -1) | (-(v2290 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
      v2310[v2515] = v2307;
      int * v2312 = v2248->cache_tags;
      int v2518 = (int)((unsigned int)((int)((unsigned int)v2250 >> 2)) >> 1);
      v2312[v2494] = v2518;
      int * v2314 = v2248->cache_dirty;
      v2314[v2494] = 0;
      int * v2316 = v2248->cache_age;
      v2316[v2494] = 1;
      int * v2318 = v2248->cache_age;
      int v2319 = v2318[v2494];
      int v2320 = v2318[v2468];
      int v2524 = v2320 + ((int)((unsigned int)(v2320 - v2319) >> 31));
      v2318[v2468] = v2524;
      int * v2322 = v2248->cache_age;
      int v2323 = v2322[v2469];
      int v2526 = v2323 + ((int)((unsigned int)(v2323 - v2319) >> 31));
      v2322[v2469] = v2526;
      int * v2325 = v2248->cache_age;
      v2325[v2494] = 0;
      v2328 = v2494;
    }
    int * v2329 = v2248->cache_vals;
    int v2529 = v2328 * 2;
    int v2330 = v2329[v2529];
    int v2530 = (v2328 * 2) + 1;
    int v2331 = v2329[v2530];
    int v2531 = (((((int)((unsigned int)((int)((unsigned int)v2250 >> 2)) >> 1)) & 1) * 2) + ((((v2270 + ((~(((v2272 ^ -1) | (-(v2272 ^ -1))) >> 31)) & 2)) - (v2273 + ((~(((v2274 ^ -1) | (-(v2274 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
    v2329[v2531] = v2330;
    int * v2333 = v2248->cache_vals;
    int v2534 = ((((((int)((unsigned int)((int)((unsigned int)v2250 >> 2)) >> 1)) & 1) * 2) + ((((v2270 + ((~(((v2272 ^ -1) | (-(v2272 ^ -1))) >> 31)) & 2)) - (v2273 + ((~(((v2274 ^ -1) | (-(v2274 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
    v2333[v2534] = v2331;
    int * v2335 = v2248->cache_tags;
    int v2537 = ((((int)((unsigned int)((int)((unsigned int)v2250 >> 2)) >> 1)) & 1) * 2) + ((((v2270 + ((~(((v2272 ^ -1) | (-(v2272 ^ -1))) >> 31)) & 2)) - (v2273 + ((~(((v2274 ^ -1) | (-(v2274 ^ -1))) >> 31)) & 2))) >> 31) & 1);
    int v2538 = (int)((unsigned int)((int)((unsigned int)v2250 >> 2)) >> 1);
    v2335[v2537] = v2538;
    int * v2337 = v2248->cache_dirty;
    v2337[v2537] = 0;
    int * v2339 = v2248->cache_age;
    v2339[v2537] = 1;
    int * v2341 = v2248->cache_age;
    int v2342 = v2341[v2537];
    int v2343 = v2341[v2466];
    int v2544 = v2343 + ((int)((unsigned int)(v2343 - v2342) >> 31));
    v2341[v2466] = v2544;
    int * v2345 = v2248->cache_age;
    int v2346 = v2345[v2467];
    int v2546 = v2346 + ((int)((unsigned int)(v2346 - v2342) >> 31));
    v2345[v2467] = v2546;
    int * v2348 = v2248->cache_age;
    v2348[v2537] = 0;
    v2351 = v2537;
  }
  int v2549 = (v2351 * 2) + (((int)((unsigned int)v2250 >> 2)) & 1);
  int v2352 = v2258[v2549];
  int * v2353 = v2248->regs;
  v2353[11] = v2352;
  struct StateT2 * v2355 = slot_24(v2118);
  return v2355;
}

struct StateT2 * slot_5(struct StateT2 * v170) {
  struct StateT * v171 = v170->a;
  int v172 = v171->timer;
  struct StateT * v173 = v170->b;
  int v174 = v173->timer;
  bool v207 = v172 == v174;
  squared_assert(v207);
  squared_assume(v207);
  struct StateT * v177 = v170->a;
  int * v178 = v177->saved_regs;
  int * v179 = v177->regs;
  int v180 = v179[5];
  v178[5] = v180;
  struct StateT * v182 = v170->b;
  int * v183 = v182->saved_regs;
  int * v184 = v182->regs;
  int v185 = v184[5];
  v183[5] = v185;
  struct StateT * v187 = v170->a;
  int v188 = v187->timer;
  int v218 = v188 + 1;
  v187->timer = v218;
  struct StateT * v190 = v170->b;
  int v191 = v190->timer;
  int v220 = v191 + 1;
  v190->timer = v220;
  struct StateT * v193 = v170->a;
  int * v194 = v193->regs;
  int v195 = v194[12];
  int v196 = v194[14];
  int v225 = v195 + v196;
  v194[5] = v225;
  struct StateT * v198 = v170->b;
  int * v199 = v198->regs;
  int v200 = v199[12];
  int v201 = v199[14];
  int v228 = v200 + v201;
  v199[5] = v228;
  struct StateT2 * v203 = slot_6(v170);
  return v203;
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
  v88[14] = 0;
  struct StateT * v90 = v74->b;
  int * v91 = v90->regs;
  v91[14] = 0;
  struct StateT2 * v93 = slot_3(v74);
  return v93;
}

struct StateT2 * slot_7(struct StateT2 * v667) {
  struct StateT * v668 = v667->a;
  int v669 = v668->timer;
  struct StateT * v670 = v667->b;
  int v671 = v670->timer;
  bool v704 = v669 == v671;
  squared_assert(v704);
  squared_assume(v704);
  struct StateT * v674 = v667->a;
  int * v675 = v674->saved_regs;
  int * v676 = v674->regs;
  int v677 = v676[6];
  v675[6] = v677;
  struct StateT * v679 = v667->b;
  int * v680 = v679->saved_regs;
  int * v681 = v679->regs;
  int v682 = v681[6];
  v680[6] = v682;
  struct StateT * v684 = v667->a;
  int v685 = v684->timer;
  int v715 = v685 + 1;
  v684->timer = v715;
  struct StateT * v687 = v667->b;
  int v688 = v687->timer;
  int v717 = v688 + 1;
  v687->timer = v717;
  struct StateT * v690 = v667->a;
  int * v691 = v690->regs;
  int v692 = v691[13];
  int v693 = v691[14];
  int v722 = v692 + v693;
  v691[6] = v722;
  struct StateT * v695 = v667->b;
  int * v696 = v695->regs;
  int v697 = v696[13];
  int v698 = v696[14];
  int v725 = v697 + v698;
  v696[6] = v725;
  struct StateT2 * v700 = slot_23(v667);
  return v700;
}

struct StateT2 * slot_3(struct StateT2 * v110) {
  struct StateT * v111 = v110->a;
  int v112 = v111->timer;
  struct StateT * v113 = v110->b;
  int v114 = v113->timer;
  bool v133 = v112 == v114;
  squared_assert(v133);
  squared_assume(v133);
  struct StateT * v117 = v110->a;
  int v118 = v117->timer;
  int v135 = v118 + 1;
  v117->timer = v135;
  struct StateT * v120 = v110->b;
  int v121 = v120->timer;
  int v137 = v121 + 1;
  v120->timer = v137;
  struct StateT * v123 = v110->a;
  int * v124 = v123->regs;
  v124[15] = 16;
  struct StateT * v126 = v110->b;
  int * v127 = v126->regs;
  v127[15] = 16;
  struct StateT2 * v129 = slot_4(v110);
  return v129;
}

struct StateT2 * slot_26(struct StateT2 * v2696) {
  struct StateT * v2697 = v2696->a;
  int v2698 = v2697->timer;
  struct StateT * v2699 = v2696->b;
  int v2700 = v2699->timer;
  bool v2713 = v2698 == v2700;
  squared_assert(v2713);
  squared_assume(v2713);
  struct StateT * v2703 = v2696->a;
  int v2704 = v2703->timer;
  int v2715 = v2704 + 1;
  v2703->timer = v2715;
  struct StateT * v2706 = v2696->b;
  int v2707 = v2706->timer;
  int v2717 = v2707 + 1;
  v2706->timer = v2717;
  struct StateT2 * v2709 = slot_13(v2696);
  return v2709;
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
  v52[13] = 80;
  struct StateT * v54 = v38->b;
  int * v55 = v54->regs;
  v55[13] = 80;
  struct StateT2 * v57 = slot_2(v38);
  return v57;
}

struct StateT2 * slot_13(struct StateT2 * v1330) {
  struct StateT * v1331 = v1330->a;
  int v1332 = v1331->timer;
  struct StateT * v1333 = v1330->b;
  int v1334 = v1333->timer;
  bool v1365 = v1332 == v1334;
  squared_assert(v1365);
  squared_assume(v1365);
  struct StateT * v1337 = v1330->a;
  int * v1338 = v1337->saved_regs;
  int * v1339 = v1337->regs;
  int v1340 = v1339[14];
  v1338[14] = v1340;
  struct StateT * v1342 = v1330->b;
  int * v1343 = v1342->saved_regs;
  int * v1344 = v1342->regs;
  int v1345 = v1344[14];
  v1343[14] = v1345;
  struct StateT * v1347 = v1330->a;
  int v1348 = v1347->timer;
  int v1376 = v1348 + 1;
  v1347->timer = v1376;
  struct StateT * v1350 = v1330->b;
  int v1351 = v1350->timer;
  int v1378 = v1351 + 1;
  v1350->timer = v1378;
  struct StateT * v1353 = v1330->a;
  int * v1354 = v1353->regs;
  int v1355 = v1354[14];
  int v1381 = v1355 + 4;
  v1354[14] = v1381;
  struct StateT * v1357 = v1330->b;
  int * v1358 = v1357->regs;
  int v1359 = v1358[14];
  int v1384 = v1359 + 4;
  v1358[14] = v1384;
  struct StateT2 * v1361 = slot_29(v1330);
  return v1361;
}

struct StateT2 * slot_24(struct StateT2 * v2554) {
  struct StateT * v2555 = v2554->a;
  int v2556 = v2555->timer;
  struct StateT * v2557 = v2554->b;
  int v2558 = v2557->timer;
  bool v2617 = v2556 == v2558;
  squared_assert(v2617);
  squared_assume(v2617);
  struct StateT * v2561 = v2554->a;
  int * v2562 = v2561->regs;
  int v2563 = v2562[14];
  int v2564 = v2562[15];
  struct StateT * v2565 = v2554->b;
  int * v2566 = v2565->regs;
  int v2567 = v2566[14];
  int v2568 = v2566[15];
  bool v2624 = (v2563 >= v2564) == (v2567 >= v2568);
  squared_diverged(v2624);
  squared_assume(v2624);
  bool v2625 = v2563 >= v2564;
  struct StateT2 * v2613;
  if (v2625) {
    struct StateT * v2571 = v2554->a;
    int v2572 = v2571->timer;
    int v2627 = v2572 + 15;
    v2571->timer = v2627;
    int * v2574 = v2571->saved_regs;
    int v2575 = v2574[5];
    int * v2576 = v2571->regs;
    v2576[5] = v2575;
    int * v2578 = v2571->saved_regs;
    int v2579 = v2578[10];
    int * v2580 = v2571->regs;
    v2580[10] = v2579;
    int * v2582 = v2571->saved_regs;
    int v2583 = v2582[6];
    int * v2584 = v2571->regs;
    v2584[6] = v2583;
    int * v2586 = v2571->saved_regs;
    int v2587 = v2586[11];
    int * v2588 = v2571->regs;
    v2588[11] = v2587;
    struct StateT * v2590 = v2554->b;
    int v2591 = v2590->timer;
    int v2645 = v2591 + 15;
    v2590->timer = v2645;
    int * v2593 = v2590->saved_regs;
    int v2594 = v2593[5];
    int * v2595 = v2590->regs;
    v2595[5] = v2594;
    int * v2597 = v2590->saved_regs;
    int v2598 = v2597[10];
    int * v2599 = v2590->regs;
    v2599[10] = v2598;
    int * v2601 = v2590->saved_regs;
    int v2602 = v2601[6];
    int * v2603 = v2590->regs;
    v2603[6] = v2602;
    int * v2605 = v2590->saved_regs;
    int v2606 = v2605[11];
    int * v2607 = v2590->regs;
    v2607[11] = v2606;
    struct StateT2 * v2609 = slot_25(v2554);
    v2613 = v2609;
  } else {
    struct StateT2 * v2611 = slot_26(v2554);
    v2613 = v2611;
  }
  return v2613;
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
  v16[12] = 0;
  struct StateT * v18 = v2->b;
  int * v19 = v18->regs;
  v19[12] = 0;
  struct StateT2 * v21 = slot_1(v2);
  return v21;
}

struct StateT2 * slot_17(struct StateT2 * v1513) {
  struct StateT * v1514 = v1513->a;
  int v1515 = v1514->timer;
  struct StateT * v1516 = v1513->b;
  int v1517 = v1516->timer;
  bool v1531 = v1515 == v1517;
  squared_assert(v1531);
  squared_assume(v1531);
  struct StateT * v1520 = v1513->a;
  int v1521 = v1520->timer;
  int v1533 = v1521 + 1;
  v1520->timer = v1533;
  struct StateT * v1523 = v1513->b;
  int v1524 = v1523->timer;
  int v1535 = v1524 + 1;
  v1523->timer = v1535;
  return v1513;
}

struct StateT2 * snippet(struct StateT2 * v0) {
  struct StateT2 * v1 = slot_0(v0);
  return v1;
}

struct StateT2 * slot_4(struct StateT2 * v146) {
  struct StateT * v147 = v146->a;
  int v148 = v147->timer;
  struct StateT * v149 = v146->b;
  int v150 = v149->timer;
  bool v163 = v148 == v150;
  squared_assert(v163);
  squared_assume(v163);
  struct StateT * v153 = v146->a;
  int v154 = v153->timer;
  int v165 = v154 + 1;
  v153->timer = v165;
  struct StateT * v156 = v146->b;
  int v157 = v156->timer;
  int v167 = v157 + 1;
  v156->timer = v167;
  struct StateT2 * v159 = slot_5(v146);
  return v159;
}

struct StateT2 * slot_15(struct StateT2 * v1451) {
  struct StateT * v1452 = v1451->a;
  int v1453 = v1452->timer;
  struct StateT * v1454 = v1451->b;
  int v1455 = v1454->timer;
  bool v1474 = v1453 == v1455;
  squared_assert(v1474);
  squared_assume(v1474);
  struct StateT * v1458 = v1451->a;
  int v1459 = v1458->timer;
  int v1476 = v1459 + 1;
  v1458->timer = v1476;
  struct StateT * v1461 = v1451->b;
  int v1462 = v1461->timer;
  int v1478 = v1462 + 1;
  v1461->timer = v1478;
  struct StateT * v1464 = v1451->a;
  int * v1465 = v1464->regs;
  v1465[10] = 0;
  struct StateT * v1467 = v1451->b;
  int * v1468 = v1467->regs;
  v1468[10] = 0;
  struct StateT2 * v1470 = slot_17(v1451);
  return v1470;
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