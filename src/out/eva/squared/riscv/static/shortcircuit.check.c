// verify: leak (Eva should report untainted_timer: unknown) [unroll 65]
#define NUM_REGS 32
#define MEM_SIZE 64
#define SECRET_SIZE 10
#define SECRET_OFFSET 20
#define CACHE_ENTRIES 12
#define CACHE_WORDS 24

#ifdef EVA
#include "__fc_builtin.h"
/*@ assigns *p \from \nothing;
    taints *p; */
void koika_mark(int *p);
#define koika_assert(b, s) ((void)0)
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

struct StateT2 * slot_14(struct StateT2 * v1387);
struct StateT2 * slot_6(struct StateT2 * v231);
struct StateT2 * slot_16(struct StateT2 * v1487);
struct StateT2 * slot_5(struct StateT2 * v170);
struct StateT2 * slot_17(struct StateT2 * v1513);
struct StateT2 * slot_2(struct StateT2 * v74);
struct StateT2 * slot_7(struct StateT2 * v667);
struct StateT2 * slot_3(struct StateT2 * v110);
struct StateT2 * snippet(struct StateT2 * v0);
struct StateT2 * slot_10(struct StateT2 * v1273);
struct StateT2 * slot_1(struct StateT2 * v38);
struct StateT2 * slot_8(struct StateT2 * v728);
struct StateT2 * slot_4(struct StateT2 * v146);
struct StateT2 * slot_13(struct StateT2 * v1330);
struct StateT2 * slot_15(struct StateT2 * v1451);
struct StateT2 * slot_9(struct StateT2 * v1164);
struct StateT2 * slot_11(struct StateT2 * v1306);
struct StateT2 * slot_0(struct StateT2 * v2);
struct StateT2 * slot_14(struct StateT2 * v1387) {
  struct StateT * v1388 = v1387->a;
  int v1389 = v1388->timer;
  struct StateT * v1390 = v1387->b;
  int v1391 = v1390->timer;
  bool v1426 = v1389 == v1391;
  squared_assert(v1426);
  squared_assume(v1426);
  struct StateT * v1394 = v1387->a;
  int * v1395 = v1394->regs;
  int v1396 = v1395[10];
  int v1397 = v1395[11];
  struct StateT * v1398 = v1387->b;
  int * v1399 = v1398->regs;
  int v1400 = v1399[10];
  int v1401 = v1399[11];
  bool v1433 = (!(v1396 == v1397)) == (!(v1400 == v1401));
  squared_diverged(v1433);
  squared_assume(v1433);
  bool v1434 = !(v1396 == v1397);
  struct StateT2 * v1422;
  if (v1434) {
    struct StateT * v1404 = v1387->a;
    int v1405 = v1404->timer;
    int v1436 = v1405 + 15;
    v1404->timer = v1436;
    int * v1407 = v1404->saved_regs;
    int v1408 = v1407[14];
    int * v1409 = v1404->regs;
    v1409[14] = v1408;
    struct StateT * v1411 = v1387->b;
    int v1412 = v1411->timer;
    int v1442 = v1412 + 15;
    v1411->timer = v1442;
    int * v1414 = v1411->saved_regs;
    int v1415 = v1414[14];
    int * v1416 = v1411->regs;
    v1416[14] = v1415;
    struct StateT2 * v1418 = slot_15(v1387);
    v1422 = v1418;
  } else {
    struct StateT2 * v1420 = slot_16(v1387);
    v1422 = v1420;
  }
  return v1422;
}

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
  struct StateT2 * v700 = slot_8(v667);
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

struct StateT2 * snippet(struct StateT2 * v0) {
  struct StateT2 * v1 = slot_0(v0);
  return v1;
}

struct StateT2 * slot_10(struct StateT2 * v1273) {
  struct StateT * v1274 = v1273->a;
  int v1275 = v1274->timer;
  struct StateT * v1276 = v1273->b;
  int v1277 = v1276->timer;
  bool v1295 = v1275 == v1277;
  squared_assert(v1295);
  squared_assume(v1295);
  struct StateT * v1280 = v1273->a;
  int v1281 = v1280->timer;
  int v1297 = v1281 + 1;
  v1280->timer = v1297;
  struct StateT * v1283 = v1273->b;
  int v1284 = v1283->timer;
  int v1299 = v1284 + 1;
  v1283->timer = v1299;
  struct StateT * v1286 = v1273->a;
  int * v1287 = v1286->regs;
  v1287[10] = 1;
  struct StateT * v1289 = v1273->b;
  int * v1290 = v1289->regs;
  v1290[10] = 1;
  return v1273;
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

struct StateT2 * slot_8(struct StateT2 * v728) {
  struct StateT * v729 = v728->a;
  int v730 = v729->timer;
  struct StateT * v731 = v728->b;
  int v732 = v731->timer;
  bool v969 = v730 == v732;
  squared_assert(v969);
  squared_assume(v969);
  struct StateT * v735 = v728->a;
  int * v736 = v735->saved_regs;
  int * v737 = v735->regs;
  int v738 = v737[11];
  v736[11] = v738;
  struct StateT * v740 = v728->b;
  int * v741 = v740->saved_regs;
  int * v742 = v740->regs;
  int v743 = v742[11];
  v741[11] = v743;
  struct StateT * v745 = v728->a;
  int v746 = v745->timer;
  int v980 = v746 + 1;
  v745->timer = v980;
  struct StateT * v748 = v728->b;
  int v749 = v748->timer;
  int v982 = v749 + 1;
  v748->timer = v982;
  struct StateT * v751 = v728->a;
  int * v752 = v751->regs;
  int v753 = v752[6];
  int * v754 = v751->cache_tags;
  int v987 = (((int)((unsigned int)((int)((unsigned int)v753 >> 2)) >> 1)) & 1) * 2;
  int v755 = v754[v987];
  int v988 = ((((int)((unsigned int)((int)((unsigned int)v753 >> 2)) >> 1)) & 1) * 2) + 1;
  int v756 = v754[v988];
  int v989 = 4 + ((((int)((unsigned int)((int)((unsigned int)v753 >> 2)) >> 1)) & 3) * 2);
  int v757 = v754[v989];
  int v990 = (4 + ((((int)((unsigned int)((int)((unsigned int)v753 >> 2)) >> 1)) & 3) * 2)) + 1;
  int v758 = v754[v990];
  int v759 = v751->timer;
  int v991 = v759 + ((100 ^ (((~(((v757 ^ ((int)((unsigned int)((int)((unsigned int)v753 >> 2)) >> 1))) | (-(v757 ^ ((int)((unsigned int)((int)((unsigned int)v753 >> 2)) >> 1))))) >> 31)) | (~(((v758 ^ ((int)((unsigned int)((int)((unsigned int)v753 >> 2)) >> 1))) | (-(v758 ^ ((int)((unsigned int)((int)((unsigned int)v753 >> 2)) >> 1))))) >> 31))) & 104)) ^ (((~(((v755 ^ ((int)((unsigned int)((int)((unsigned int)v753 >> 2)) >> 1))) | (-(v755 ^ ((int)((unsigned int)((int)((unsigned int)v753 >> 2)) >> 1))))) >> 31)) | (~(((v756 ^ ((int)((unsigned int)((int)((unsigned int)v753 >> 2)) >> 1))) | (-(v756 ^ ((int)((unsigned int)((int)((unsigned int)v753 >> 2)) >> 1))))) >> 31))) & (1 ^ (100 ^ (((~(((v757 ^ ((int)((unsigned int)((int)((unsigned int)v753 >> 2)) >> 1))) | (-(v757 ^ ((int)((unsigned int)((int)((unsigned int)v753 >> 2)) >> 1))))) >> 31)) | (~(((v758 ^ ((int)((unsigned int)((int)((unsigned int)v753 >> 2)) >> 1))) | (-(v758 ^ ((int)((unsigned int)((int)((unsigned int)v753 >> 2)) >> 1))))) >> 31))) & 104)))));
  v751->timer = v991;
  int * v761 = v751->cache_vals;
  bool v992 = !(((~(((v755 ^ ((int)((unsigned int)((int)((unsigned int)v753 >> 2)) >> 1))) | (-(v755 ^ ((int)((unsigned int)((int)((unsigned int)v753 >> 2)) >> 1))))) >> 31)) | (~(((v756 ^ ((int)((unsigned int)((int)((unsigned int)v753 >> 2)) >> 1))) | (-(v756 ^ ((int)((unsigned int)((int)((unsigned int)v753 >> 2)) >> 1))))) >> 31))) == 0);
  int v854;
  if (v992) {
    int * v762 = v751->cache_age;
    int v994 = ((((int)((unsigned int)((int)((unsigned int)v753 >> 2)) >> 1)) & 1) * 2) + ((~(((v756 ^ ((int)((unsigned int)((int)((unsigned int)v753 >> 2)) >> 1))) | (-(v756 ^ ((int)((unsigned int)((int)((unsigned int)v753 >> 2)) >> 1))))) >> 31)) & 1);
    int v763 = v762[v994];
    int v764 = v762[v987];
    int v995 = v764 + ((int)((unsigned int)(v764 - v763) >> 31));
    v762[v987] = v995;
    int * v766 = v751->cache_age;
    int v767 = v766[v988];
    int v997 = v767 + ((int)((unsigned int)(v767 - v763) >> 31));
    v766[v988] = v997;
    int * v769 = v751->cache_age;
    v769[v994] = 0;
    v854 = v994;
  } else {
    int * v772 = v751->cache_age;
    int v1001 = (((int)((unsigned int)((int)((unsigned int)v753 >> 2)) >> 1)) & 1) * 2;
    int v773 = v772[v1001];
    int * v774 = v751->cache_tags;
    int v775 = v774[v1001];
    int v776 = v772[v988];
    int v777 = v774[v988];
    bool v1003 = !(((~(((v757 ^ ((int)((unsigned int)((int)((unsigned int)v753 >> 2)) >> 1))) | (-(v757 ^ ((int)((unsigned int)((int)((unsigned int)v753 >> 2)) >> 1))))) >> 31)) | (~(((v758 ^ ((int)((unsigned int)((int)((unsigned int)v753 >> 2)) >> 1))) | (-(v758 ^ ((int)((unsigned int)((int)((unsigned int)v753 >> 2)) >> 1))))) >> 31))) == 0);
    int v831;
    if (v1003) {
      int * v778 = v751->cache_age;
      int v1005 = (4 + ((((int)((unsigned int)((int)((unsigned int)v753 >> 2)) >> 1)) & 3) * 2)) + ((~(((v758 ^ ((int)((unsigned int)((int)((unsigned int)v753 >> 2)) >> 1))) | (-(v758 ^ ((int)((unsigned int)((int)((unsigned int)v753 >> 2)) >> 1))))) >> 31)) & 1);
      int v779 = v778[v1005];
      int v780 = v778[v989];
      int v1006 = v780 + ((int)((unsigned int)(v780 - v779) >> 31));
      v778[v989] = v1006;
      int * v782 = v751->cache_age;
      int v783 = v782[v990];
      int v1008 = v783 + ((int)((unsigned int)(v783 - v779) >> 31));
      v782[v990] = v1008;
      int * v785 = v751->cache_age;
      v785[v1005] = 0;
      v831 = v1005;
    } else {
      int * v788 = v751->cache_age;
      int v1012 = 4 + ((((int)((unsigned int)((int)((unsigned int)v753 >> 2)) >> 1)) & 3) * 2);
      int v789 = v788[v1012];
      int * v790 = v751->cache_tags;
      int v791 = v790[v1012];
      int v792 = v788[v990];
      int v793 = v790[v990];
      int * v794 = v751->cache_dirty;
      int v1015 = (4 + ((((int)((unsigned int)((int)((unsigned int)v753 >> 2)) >> 1)) & 3) * 2)) + ((((v789 + ((~(((v791 ^ -1) | (-(v791 ^ -1))) >> 31)) & 2)) - (v792 + ((~(((v793 ^ -1) | (-(v793 ^ -1))) >> 31)) & 2))) >> 31) & 1);
      int v795 = v794[v1015];
      bool v1016 = !(v795 == 0);
      if (v1016) {
        int * v796 = v751->cache_tags;
        int v797 = v796[v1015];
        int * v798 = v751->cache_vals;
        int v1019 = ((4 + ((((int)((unsigned int)((int)((unsigned int)v753 >> 2)) >> 1)) & 3) * 2)) + ((((v789 + ((~(((v791 ^ -1) | (-(v791 ^ -1))) >> 31)) & 2)) - (v792 + ((~(((v793 ^ -1) | (-(v793 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
        int v799 = v798[v1019];
        int v1020 = (((4 + ((((int)((unsigned int)((int)((unsigned int)v753 >> 2)) >> 1)) & 3) * 2)) + ((((v789 + ((~(((v791 ^ -1) | (-(v791 ^ -1))) >> 31)) & 2)) - (v792 + ((~(((v793 ^ -1) | (-(v793 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
        int v800 = v798[v1020];
        int * v801 = v751->mem;
        int v1022 = v797 * 2;
        v801[v1022] = v799;
        int * v803 = v751->mem;
        int v1025 = (v797 * 2) + 1;
        v803[v1025] = v800;
        ;
      } else {
        ;
      }
      int * v808 = v751->mem;
      int v1030 = ((int)((unsigned int)((int)((unsigned int)v753 >> 2)) >> 1)) * 2;
      int v809 = v808[v1030];
      int v1031 = (((int)((unsigned int)((int)((unsigned int)v753 >> 2)) >> 1)) * 2) + 1;
      int v810 = v808[v1031];
      int * v811 = v751->cache_vals;
      int v1033 = ((4 + ((((int)((unsigned int)((int)((unsigned int)v753 >> 2)) >> 1)) & 3) * 2)) + ((((v789 + ((~(((v791 ^ -1) | (-(v791 ^ -1))) >> 31)) & 2)) - (v792 + ((~(((v793 ^ -1) | (-(v793 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
      v811[v1033] = v809;
      int * v813 = v751->cache_vals;
      int v1036 = (((4 + ((((int)((unsigned int)((int)((unsigned int)v753 >> 2)) >> 1)) & 3) * 2)) + ((((v789 + ((~(((v791 ^ -1) | (-(v791 ^ -1))) >> 31)) & 2)) - (v792 + ((~(((v793 ^ -1) | (-(v793 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
      v813[v1036] = v810;
      int * v815 = v751->cache_tags;
      int v1039 = (int)((unsigned int)((int)((unsigned int)v753 >> 2)) >> 1);
      v815[v1015] = v1039;
      int * v817 = v751->cache_dirty;
      v817[v1015] = 0;
      int * v819 = v751->cache_age;
      v819[v1015] = 1;
      int * v821 = v751->cache_age;
      int v822 = v821[v1015];
      int v823 = v821[v989];
      int v1045 = v823 + ((int)((unsigned int)(v823 - v822) >> 31));
      v821[v989] = v1045;
      int * v825 = v751->cache_age;
      int v826 = v825[v990];
      int v1047 = v826 + ((int)((unsigned int)(v826 - v822) >> 31));
      v825[v990] = v1047;
      int * v828 = v751->cache_age;
      v828[v1015] = 0;
      v831 = v1015;
    }
    int * v832 = v751->cache_vals;
    int v1050 = v831 * 2;
    int v833 = v832[v1050];
    int v1051 = (v831 * 2) + 1;
    int v834 = v832[v1051];
    int v1052 = (((((int)((unsigned int)((int)((unsigned int)v753 >> 2)) >> 1)) & 1) * 2) + ((((v773 + ((~(((v775 ^ -1) | (-(v775 ^ -1))) >> 31)) & 2)) - (v776 + ((~(((v777 ^ -1) | (-(v777 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
    v832[v1052] = v833;
    int * v836 = v751->cache_vals;
    int v1055 = ((((((int)((unsigned int)((int)((unsigned int)v753 >> 2)) >> 1)) & 1) * 2) + ((((v773 + ((~(((v775 ^ -1) | (-(v775 ^ -1))) >> 31)) & 2)) - (v776 + ((~(((v777 ^ -1) | (-(v777 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
    v836[v1055] = v834;
    int * v838 = v751->cache_tags;
    int v1058 = ((((int)((unsigned int)((int)((unsigned int)v753 >> 2)) >> 1)) & 1) * 2) + ((((v773 + ((~(((v775 ^ -1) | (-(v775 ^ -1))) >> 31)) & 2)) - (v776 + ((~(((v777 ^ -1) | (-(v777 ^ -1))) >> 31)) & 2))) >> 31) & 1);
    int v1059 = (int)((unsigned int)((int)((unsigned int)v753 >> 2)) >> 1);
    v838[v1058] = v1059;
    int * v840 = v751->cache_dirty;
    v840[v1058] = 0;
    int * v842 = v751->cache_age;
    v842[v1058] = 1;
    int * v844 = v751->cache_age;
    int v845 = v844[v1058];
    int v846 = v844[v987];
    int v1065 = v846 + ((int)((unsigned int)(v846 - v845) >> 31));
    v844[v987] = v1065;
    int * v848 = v751->cache_age;
    int v849 = v848[v988];
    int v1067 = v849 + ((int)((unsigned int)(v849 - v845) >> 31));
    v848[v988] = v1067;
    int * v851 = v751->cache_age;
    v851[v1058] = 0;
    v854 = v1058;
  }
  int v1070 = (v854 * 2) + (((int)((unsigned int)v753 >> 2)) & 1);
  int v855 = v761[v1070];
  int * v856 = v751->regs;
  v856[11] = v855;
  struct StateT * v858 = v728->b;
  int * v859 = v858->regs;
  int v860 = v859[6];
  int * v861 = v858->cache_tags;
  int v1076 = (((int)((unsigned int)((int)((unsigned int)v860 >> 2)) >> 1)) & 1) * 2;
  int v862 = v861[v1076];
  int v1077 = ((((int)((unsigned int)((int)((unsigned int)v860 >> 2)) >> 1)) & 1) * 2) + 1;
  int v863 = v861[v1077];
  int v1078 = 4 + ((((int)((unsigned int)((int)((unsigned int)v860 >> 2)) >> 1)) & 3) * 2);
  int v864 = v861[v1078];
  int v1079 = (4 + ((((int)((unsigned int)((int)((unsigned int)v860 >> 2)) >> 1)) & 3) * 2)) + 1;
  int v865 = v861[v1079];
  int v866 = v858->timer;
  int v1080 = v866 + ((100 ^ (((~(((v864 ^ ((int)((unsigned int)((int)((unsigned int)v860 >> 2)) >> 1))) | (-(v864 ^ ((int)((unsigned int)((int)((unsigned int)v860 >> 2)) >> 1))))) >> 31)) | (~(((v865 ^ ((int)((unsigned int)((int)((unsigned int)v860 >> 2)) >> 1))) | (-(v865 ^ ((int)((unsigned int)((int)((unsigned int)v860 >> 2)) >> 1))))) >> 31))) & 104)) ^ (((~(((v862 ^ ((int)((unsigned int)((int)((unsigned int)v860 >> 2)) >> 1))) | (-(v862 ^ ((int)((unsigned int)((int)((unsigned int)v860 >> 2)) >> 1))))) >> 31)) | (~(((v863 ^ ((int)((unsigned int)((int)((unsigned int)v860 >> 2)) >> 1))) | (-(v863 ^ ((int)((unsigned int)((int)((unsigned int)v860 >> 2)) >> 1))))) >> 31))) & (1 ^ (100 ^ (((~(((v864 ^ ((int)((unsigned int)((int)((unsigned int)v860 >> 2)) >> 1))) | (-(v864 ^ ((int)((unsigned int)((int)((unsigned int)v860 >> 2)) >> 1))))) >> 31)) | (~(((v865 ^ ((int)((unsigned int)((int)((unsigned int)v860 >> 2)) >> 1))) | (-(v865 ^ ((int)((unsigned int)((int)((unsigned int)v860 >> 2)) >> 1))))) >> 31))) & 104)))));
  v858->timer = v1080;
  int * v868 = v858->cache_vals;
  bool v1081 = !(((~(((v862 ^ ((int)((unsigned int)((int)((unsigned int)v860 >> 2)) >> 1))) | (-(v862 ^ ((int)((unsigned int)((int)((unsigned int)v860 >> 2)) >> 1))))) >> 31)) | (~(((v863 ^ ((int)((unsigned int)((int)((unsigned int)v860 >> 2)) >> 1))) | (-(v863 ^ ((int)((unsigned int)((int)((unsigned int)v860 >> 2)) >> 1))))) >> 31))) == 0);
  int v961;
  if (v1081) {
    int * v869 = v858->cache_age;
    int v1083 = ((((int)((unsigned int)((int)((unsigned int)v860 >> 2)) >> 1)) & 1) * 2) + ((~(((v863 ^ ((int)((unsigned int)((int)((unsigned int)v860 >> 2)) >> 1))) | (-(v863 ^ ((int)((unsigned int)((int)((unsigned int)v860 >> 2)) >> 1))))) >> 31)) & 1);
    int v870 = v869[v1083];
    int v871 = v869[v1076];
    int v1084 = v871 + ((int)((unsigned int)(v871 - v870) >> 31));
    v869[v1076] = v1084;
    int * v873 = v858->cache_age;
    int v874 = v873[v1077];
    int v1086 = v874 + ((int)((unsigned int)(v874 - v870) >> 31));
    v873[v1077] = v1086;
    int * v876 = v858->cache_age;
    v876[v1083] = 0;
    v961 = v1083;
  } else {
    int * v879 = v858->cache_age;
    int v1090 = (((int)((unsigned int)((int)((unsigned int)v860 >> 2)) >> 1)) & 1) * 2;
    int v880 = v879[v1090];
    int * v881 = v858->cache_tags;
    int v882 = v881[v1090];
    int v883 = v879[v1077];
    int v884 = v881[v1077];
    bool v1092 = !(((~(((v864 ^ ((int)((unsigned int)((int)((unsigned int)v860 >> 2)) >> 1))) | (-(v864 ^ ((int)((unsigned int)((int)((unsigned int)v860 >> 2)) >> 1))))) >> 31)) | (~(((v865 ^ ((int)((unsigned int)((int)((unsigned int)v860 >> 2)) >> 1))) | (-(v865 ^ ((int)((unsigned int)((int)((unsigned int)v860 >> 2)) >> 1))))) >> 31))) == 0);
    int v938;
    if (v1092) {
      int * v885 = v858->cache_age;
      int v1094 = (4 + ((((int)((unsigned int)((int)((unsigned int)v860 >> 2)) >> 1)) & 3) * 2)) + ((~(((v865 ^ ((int)((unsigned int)((int)((unsigned int)v860 >> 2)) >> 1))) | (-(v865 ^ ((int)((unsigned int)((int)((unsigned int)v860 >> 2)) >> 1))))) >> 31)) & 1);
      int v886 = v885[v1094];
      int v887 = v885[v1078];
      int v1095 = v887 + ((int)((unsigned int)(v887 - v886) >> 31));
      v885[v1078] = v1095;
      int * v889 = v858->cache_age;
      int v890 = v889[v1079];
      int v1097 = v890 + ((int)((unsigned int)(v890 - v886) >> 31));
      v889[v1079] = v1097;
      int * v892 = v858->cache_age;
      v892[v1094] = 0;
      v938 = v1094;
    } else {
      int * v895 = v858->cache_age;
      int v1101 = 4 + ((((int)((unsigned int)((int)((unsigned int)v860 >> 2)) >> 1)) & 3) * 2);
      int v896 = v895[v1101];
      int * v897 = v858->cache_tags;
      int v898 = v897[v1101];
      int v899 = v895[v1079];
      int v900 = v897[v1079];
      int * v901 = v858->cache_dirty;
      int v1104 = (4 + ((((int)((unsigned int)((int)((unsigned int)v860 >> 2)) >> 1)) & 3) * 2)) + ((((v896 + ((~(((v898 ^ -1) | (-(v898 ^ -1))) >> 31)) & 2)) - (v899 + ((~(((v900 ^ -1) | (-(v900 ^ -1))) >> 31)) & 2))) >> 31) & 1);
      int v902 = v901[v1104];
      bool v1105 = !(v902 == 0);
      if (v1105) {
        int * v903 = v858->cache_tags;
        int v904 = v903[v1104];
        int * v905 = v858->cache_vals;
        int v1108 = ((4 + ((((int)((unsigned int)((int)((unsigned int)v860 >> 2)) >> 1)) & 3) * 2)) + ((((v896 + ((~(((v898 ^ -1) | (-(v898 ^ -1))) >> 31)) & 2)) - (v899 + ((~(((v900 ^ -1) | (-(v900 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
        int v906 = v905[v1108];
        int v1109 = (((4 + ((((int)((unsigned int)((int)((unsigned int)v860 >> 2)) >> 1)) & 3) * 2)) + ((((v896 + ((~(((v898 ^ -1) | (-(v898 ^ -1))) >> 31)) & 2)) - (v899 + ((~(((v900 ^ -1) | (-(v900 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
        int v907 = v905[v1109];
        int * v908 = v858->mem;
        int v1111 = v904 * 2;
        v908[v1111] = v906;
        int * v910 = v858->mem;
        int v1114 = (v904 * 2) + 1;
        v910[v1114] = v907;
        ;
      } else {
        ;
      }
      int * v915 = v858->mem;
      int v1119 = ((int)((unsigned int)((int)((unsigned int)v860 >> 2)) >> 1)) * 2;
      int v916 = v915[v1119];
      int v1120 = (((int)((unsigned int)((int)((unsigned int)v860 >> 2)) >> 1)) * 2) + 1;
      int v917 = v915[v1120];
      int * v918 = v858->cache_vals;
      int v1122 = ((4 + ((((int)((unsigned int)((int)((unsigned int)v860 >> 2)) >> 1)) & 3) * 2)) + ((((v896 + ((~(((v898 ^ -1) | (-(v898 ^ -1))) >> 31)) & 2)) - (v899 + ((~(((v900 ^ -1) | (-(v900 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
      v918[v1122] = v916;
      int * v920 = v858->cache_vals;
      int v1125 = (((4 + ((((int)((unsigned int)((int)((unsigned int)v860 >> 2)) >> 1)) & 3) * 2)) + ((((v896 + ((~(((v898 ^ -1) | (-(v898 ^ -1))) >> 31)) & 2)) - (v899 + ((~(((v900 ^ -1) | (-(v900 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
      v920[v1125] = v917;
      int * v922 = v858->cache_tags;
      int v1128 = (int)((unsigned int)((int)((unsigned int)v860 >> 2)) >> 1);
      v922[v1104] = v1128;
      int * v924 = v858->cache_dirty;
      v924[v1104] = 0;
      int * v926 = v858->cache_age;
      v926[v1104] = 1;
      int * v928 = v858->cache_age;
      int v929 = v928[v1104];
      int v930 = v928[v1078];
      int v1134 = v930 + ((int)((unsigned int)(v930 - v929) >> 31));
      v928[v1078] = v1134;
      int * v932 = v858->cache_age;
      int v933 = v932[v1079];
      int v1136 = v933 + ((int)((unsigned int)(v933 - v929) >> 31));
      v932[v1079] = v1136;
      int * v935 = v858->cache_age;
      v935[v1104] = 0;
      v938 = v1104;
    }
    int * v939 = v858->cache_vals;
    int v1139 = v938 * 2;
    int v940 = v939[v1139];
    int v1140 = (v938 * 2) + 1;
    int v941 = v939[v1140];
    int v1141 = (((((int)((unsigned int)((int)((unsigned int)v860 >> 2)) >> 1)) & 1) * 2) + ((((v880 + ((~(((v882 ^ -1) | (-(v882 ^ -1))) >> 31)) & 2)) - (v883 + ((~(((v884 ^ -1) | (-(v884 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
    v939[v1141] = v940;
    int * v943 = v858->cache_vals;
    int v1144 = ((((((int)((unsigned int)((int)((unsigned int)v860 >> 2)) >> 1)) & 1) * 2) + ((((v880 + ((~(((v882 ^ -1) | (-(v882 ^ -1))) >> 31)) & 2)) - (v883 + ((~(((v884 ^ -1) | (-(v884 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
    v943[v1144] = v941;
    int * v945 = v858->cache_tags;
    int v1147 = ((((int)((unsigned int)((int)((unsigned int)v860 >> 2)) >> 1)) & 1) * 2) + ((((v880 + ((~(((v882 ^ -1) | (-(v882 ^ -1))) >> 31)) & 2)) - (v883 + ((~(((v884 ^ -1) | (-(v884 ^ -1))) >> 31)) & 2))) >> 31) & 1);
    int v1148 = (int)((unsigned int)((int)((unsigned int)v860 >> 2)) >> 1);
    v945[v1147] = v1148;
    int * v947 = v858->cache_dirty;
    v947[v1147] = 0;
    int * v949 = v858->cache_age;
    v949[v1147] = 1;
    int * v951 = v858->cache_age;
    int v952 = v951[v1147];
    int v953 = v951[v1076];
    int v1154 = v953 + ((int)((unsigned int)(v953 - v952) >> 31));
    v951[v1076] = v1154;
    int * v955 = v858->cache_age;
    int v956 = v955[v1077];
    int v1156 = v956 + ((int)((unsigned int)(v956 - v952) >> 31));
    v955[v1077] = v1156;
    int * v958 = v858->cache_age;
    v958[v1147] = 0;
    v961 = v1147;
  }
  int v1159 = (v961 * 2) + (((int)((unsigned int)v860 >> 2)) & 1);
  int v962 = v868[v1159];
  int * v963 = v858->regs;
  v963[11] = v962;
  struct StateT2 * v965 = slot_9(v728);
  return v965;
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
  struct StateT2 * v1361 = slot_14(v1330);
  return v1361;
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

struct StateT2 * slot_9(struct StateT2 * v1164) {
  struct StateT * v1165 = v1164->a;
  int v1166 = v1165->timer;
  struct StateT * v1167 = v1164->b;
  int v1168 = v1167->timer;
  bool v1227 = v1166 == v1168;
  squared_assert(v1227);
  squared_assume(v1227);
  struct StateT * v1171 = v1164->a;
  int * v1172 = v1171->regs;
  int v1173 = v1172[14];
  int v1174 = v1172[15];
  struct StateT * v1175 = v1164->b;
  int * v1176 = v1175->regs;
  int v1177 = v1176[14];
  int v1178 = v1176[15];
  bool v1234 = (v1173 >= v1174) == (v1177 >= v1178);
  squared_diverged(v1234);
  squared_assume(v1234);
  bool v1235 = v1173 >= v1174;
  struct StateT2 * v1223;
  if (v1235) {
    struct StateT * v1181 = v1164->a;
    int v1182 = v1181->timer;
    int v1237 = v1182 + 15;
    v1181->timer = v1237;
    int * v1184 = v1181->saved_regs;
    int v1185 = v1184[5];
    int * v1186 = v1181->regs;
    v1186[5] = v1185;
    int * v1188 = v1181->saved_regs;
    int v1189 = v1188[10];
    int * v1190 = v1181->regs;
    v1190[10] = v1189;
    int * v1192 = v1181->saved_regs;
    int v1193 = v1192[6];
    int * v1194 = v1181->regs;
    v1194[6] = v1193;
    int * v1196 = v1181->saved_regs;
    int v1197 = v1196[11];
    int * v1198 = v1181->regs;
    v1198[11] = v1197;
    struct StateT * v1200 = v1164->b;
    int v1201 = v1200->timer;
    int v1255 = v1201 + 15;
    v1200->timer = v1255;
    int * v1203 = v1200->saved_regs;
    int v1204 = v1203[5];
    int * v1205 = v1200->regs;
    v1205[5] = v1204;
    int * v1207 = v1200->saved_regs;
    int v1208 = v1207[10];
    int * v1209 = v1200->regs;
    v1209[10] = v1208;
    int * v1211 = v1200->saved_regs;
    int v1212 = v1211[6];
    int * v1213 = v1200->regs;
    v1213[6] = v1212;
    int * v1215 = v1200->saved_regs;
    int v1216 = v1215[11];
    int * v1217 = v1200->regs;
    v1217[11] = v1216;
    struct StateT2 * v1219 = slot_10(v1164);
    v1223 = v1219;
  } else {
    struct StateT2 * v1221 = slot_11(v1164);
    v1223 = v1221;
  }
  return v1223;
}

struct StateT2 * slot_11(struct StateT2 * v1306) {
  struct StateT * v1307 = v1306->a;
  int v1308 = v1307->timer;
  struct StateT * v1309 = v1306->b;
  int v1310 = v1309->timer;
  bool v1323 = v1308 == v1310;
  squared_assert(v1323);
  squared_assume(v1323);
  struct StateT * v1313 = v1306->a;
  int v1314 = v1313->timer;
  int v1325 = v1314 + 1;
  v1313->timer = v1325;
  struct StateT * v1316 = v1306->b;
  int v1317 = v1316->timer;
  int v1327 = v1317 + 1;
  v1316->timer = v1327;
  struct StateT2 * v1319 = slot_13(v1306);
  return v1319;
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
  //@ assert untainted_timer: !\tainted(p_->a->timer==p_->b->timer);
  koika_assert(p_->a->timer==p_->b->timer, "timing leak");
  return 0;
}