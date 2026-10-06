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

struct StateT2 * slot_12(struct StateT2 * v1293);
struct StateT2 * slot_14(struct StateT2 * v227);
struct StateT2 * slot_6(struct StateT2 * v325);
struct StateT2 * slot_5(struct StateT2 * v266);
struct StateT2 * slot_2(struct StateT2 * v86);
struct StateT2 * slot_7(struct StateT2 * v751);
struct StateT2 * slot_3(struct StateT2 * v128);
struct StateT2 * snippet(struct StateT2 * v0);
struct StateT2 * slot_10(struct StateT2 * v1335);
struct StateT2 * slot_1(struct StateT2 * v44);
struct StateT2 * slot_8(struct StateT2 * v810);
struct StateT2 * slot_4(struct StateT2 * v170);
struct StateT2 * slot_13(struct StateT2 * v1388);
struct StateT2 * slot_9(struct StateT2 * v1236);
struct StateT2 * slot_11(struct StateT2 * v1411);
struct StateT2 * slot_0(struct StateT2 * v2);
struct StateT2 * slot_12(struct StateT2 * v1293) {
  struct StateT * v1294 = v1293->a;
  int v1295 = v1294->timer;
  struct StateT * v1296 = v1293->b;
  int v1297 = v1296->timer;
  bool v1320 = v1295 == v1297;
  squared_assert(v1320);
  squared_assume(v1320);
  struct StateT * v1300 = v1293->a;
  int v1301 = v1300->timer;
  int v1322 = v1301 + 1;
  v1300->timer = v1322;
  struct StateT * v1303 = v1293->b;
  int v1304 = v1303->timer;
  int v1324 = v1304 + 1;
  v1303->timer = v1324;
  struct StateT * v1306 = v1293->a;
  int * v1307 = v1306->reg_ready;
  v1307[10] = v1322;
  int * v1309 = v1306->regs;
  v1309[10] = 0;
  struct StateT * v1311 = v1293->b;
  int * v1312 = v1311->reg_ready;
  v1312[10] = v1324;
  int * v1314 = v1311->regs;
  v1314[10] = 0;
  struct StateT2 * v1316 = slot_13(v1293);
  return v1316;
}

struct StateT2 * slot_14(struct StateT2 * v227) {
  struct StateT * v228 = v227->a;
  int v229 = v228->timer;
  struct StateT * v230 = v227->b;
  int v231 = v230->timer;
  bool v253 = v229 == v231;
  squared_assert(v253);
  squared_assume(v253);
  struct StateT * v234 = v227->a;
  int v235 = v234->timer;
  int v255 = v235 + 1;
  v234->timer = v255;
  struct StateT * v237 = v227->b;
  int v238 = v237->timer;
  int v257 = v238 + 1;
  v237->timer = v257;
  struct StateT * v240 = v227->a;
  int * v241 = v240->reg_ready;
  v241[10] = v255;
  int * v243 = v240->regs;
  v243[10] = 1;
  struct StateT * v245 = v227->b;
  int * v246 = v245->reg_ready;
  v246[10] = v257;
  int * v248 = v245->regs;
  v248[10] = 1;
  return v227;
}

struct StateT2 * slot_6(struct StateT2 * v325) {
  struct StateT * v326 = v325->a;
  int v327 = v326->timer;
  struct StateT * v328 = v325->b;
  int v329 = v328->timer;
  bool v560 = v327 == v329;
  squared_assert(v560);
  squared_assume(v560);
  struct StateT * v332 = v325->a;
  int v333 = v332->timer;
  int v562 = v333 + 1;
  v332->timer = v562;
  struct StateT * v335 = v325->b;
  int v336 = v335->timer;
  int v564 = v336 + 1;
  v335->timer = v564;
  struct StateT * v338 = v325->a;
  int * v339 = v338->reg_ready;
  int v340 = v339[5];
  int * v341 = v338->regs;
  int v342 = v341[5];
  int * v343 = v338->cache_tags;
  int v570 = (((int)((unsigned int)((int)((unsigned int)v342 >> 2)) >> 1)) & 1) * 2;
  int v344 = v343[v570];
  int v571 = ((((int)((unsigned int)((int)((unsigned int)v342 >> 2)) >> 1)) & 1) * 2) + 1;
  int v345 = v343[v571];
  int v572 = 4 + ((((int)((unsigned int)((int)((unsigned int)v342 >> 2)) >> 1)) & 3) * 2);
  int v346 = v343[v572];
  int v573 = (4 + ((((int)((unsigned int)((int)((unsigned int)v342 >> 2)) >> 1)) & 3) * 2)) + 1;
  int v347 = v343[v573];
  int * v348 = v338->cache_vals;
  bool v574 = !(((~(((v344 ^ ((int)((unsigned int)((int)((unsigned int)v342 >> 2)) >> 1))) | (-(v344 ^ ((int)((unsigned int)((int)((unsigned int)v342 >> 2)) >> 1))))) >> 31)) | (~(((v345 ^ ((int)((unsigned int)((int)((unsigned int)v342 >> 2)) >> 1))) | (-(v345 ^ ((int)((unsigned int)((int)((unsigned int)v342 >> 2)) >> 1))))) >> 31))) == 0);
  int v441;
  if (v574) {
    int * v349 = v338->cache_age;
    int v576 = ((((int)((unsigned int)((int)((unsigned int)v342 >> 2)) >> 1)) & 1) * 2) + ((~(((v345 ^ ((int)((unsigned int)((int)((unsigned int)v342 >> 2)) >> 1))) | (-(v345 ^ ((int)((unsigned int)((int)((unsigned int)v342 >> 2)) >> 1))))) >> 31)) & 1);
    int v350 = v349[v576];
    int v351 = v349[v570];
    int v577 = v351 + ((int)((unsigned int)(v351 - v350) >> 31));
    v349[v570] = v577;
    int * v353 = v338->cache_age;
    int v354 = v353[v571];
    int v579 = v354 + ((int)((unsigned int)(v354 - v350) >> 31));
    v353[v571] = v579;
    int * v356 = v338->cache_age;
    v356[v576] = 0;
    v441 = v576;
  } else {
    int * v359 = v338->cache_age;
    int v583 = (((int)((unsigned int)((int)((unsigned int)v342 >> 2)) >> 1)) & 1) * 2;
    int v360 = v359[v583];
    int * v361 = v338->cache_tags;
    int v362 = v361[v583];
    int v363 = v359[v571];
    int v364 = v361[v571];
    bool v585 = !(((~(((v346 ^ ((int)((unsigned int)((int)((unsigned int)v342 >> 2)) >> 1))) | (-(v346 ^ ((int)((unsigned int)((int)((unsigned int)v342 >> 2)) >> 1))))) >> 31)) | (~(((v347 ^ ((int)((unsigned int)((int)((unsigned int)v342 >> 2)) >> 1))) | (-(v347 ^ ((int)((unsigned int)((int)((unsigned int)v342 >> 2)) >> 1))))) >> 31))) == 0);
    int v418;
    if (v585) {
      int * v365 = v338->cache_age;
      int v587 = (4 + ((((int)((unsigned int)((int)((unsigned int)v342 >> 2)) >> 1)) & 3) * 2)) + ((~(((v347 ^ ((int)((unsigned int)((int)((unsigned int)v342 >> 2)) >> 1))) | (-(v347 ^ ((int)((unsigned int)((int)((unsigned int)v342 >> 2)) >> 1))))) >> 31)) & 1);
      int v366 = v365[v587];
      int v367 = v365[v572];
      int v588 = v367 + ((int)((unsigned int)(v367 - v366) >> 31));
      v365[v572] = v588;
      int * v369 = v338->cache_age;
      int v370 = v369[v573];
      int v590 = v370 + ((int)((unsigned int)(v370 - v366) >> 31));
      v369[v573] = v590;
      int * v372 = v338->cache_age;
      v372[v587] = 0;
      v418 = v587;
    } else {
      int * v375 = v338->cache_age;
      int v594 = 4 + ((((int)((unsigned int)((int)((unsigned int)v342 >> 2)) >> 1)) & 3) * 2);
      int v376 = v375[v594];
      int * v377 = v338->cache_tags;
      int v378 = v377[v594];
      int v379 = v375[v573];
      int v380 = v377[v573];
      int * v381 = v338->cache_dirty;
      int v597 = (4 + ((((int)((unsigned int)((int)((unsigned int)v342 >> 2)) >> 1)) & 3) * 2)) + ((((v376 + ((~(((v378 ^ -1) | (-(v378 ^ -1))) >> 31)) & 2)) - (v379 + ((~(((v380 ^ -1) | (-(v380 ^ -1))) >> 31)) & 2))) >> 31) & 1);
      int v382 = v381[v597];
      bool v598 = !(v382 == 0);
      if (v598) {
        int * v383 = v338->cache_tags;
        int v384 = v383[v597];
        int * v385 = v338->cache_vals;
        int v601 = ((4 + ((((int)((unsigned int)((int)((unsigned int)v342 >> 2)) >> 1)) & 3) * 2)) + ((((v376 + ((~(((v378 ^ -1) | (-(v378 ^ -1))) >> 31)) & 2)) - (v379 + ((~(((v380 ^ -1) | (-(v380 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
        int v386 = v385[v601];
        int v602 = (((4 + ((((int)((unsigned int)((int)((unsigned int)v342 >> 2)) >> 1)) & 3) * 2)) + ((((v376 + ((~(((v378 ^ -1) | (-(v378 ^ -1))) >> 31)) & 2)) - (v379 + ((~(((v380 ^ -1) | (-(v380 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
        int v387 = v385[v602];
        int * v388 = v338->mem;
        int v604 = v384 * 2;
        v388[v604] = v386;
        int * v390 = v338->mem;
        int v607 = (v384 * 2) + 1;
        v390[v607] = v387;
        ;
      } else {
        ;
      }
      int * v395 = v338->mem;
      int v612 = ((int)((unsigned int)((int)((unsigned int)v342 >> 2)) >> 1)) * 2;
      int v396 = v395[v612];
      int v613 = (((int)((unsigned int)((int)((unsigned int)v342 >> 2)) >> 1)) * 2) + 1;
      int v397 = v395[v613];
      int * v398 = v338->cache_vals;
      int v615 = ((4 + ((((int)((unsigned int)((int)((unsigned int)v342 >> 2)) >> 1)) & 3) * 2)) + ((((v376 + ((~(((v378 ^ -1) | (-(v378 ^ -1))) >> 31)) & 2)) - (v379 + ((~(((v380 ^ -1) | (-(v380 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
      v398[v615] = v396;
      int * v400 = v338->cache_vals;
      int v618 = (((4 + ((((int)((unsigned int)((int)((unsigned int)v342 >> 2)) >> 1)) & 3) * 2)) + ((((v376 + ((~(((v378 ^ -1) | (-(v378 ^ -1))) >> 31)) & 2)) - (v379 + ((~(((v380 ^ -1) | (-(v380 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
      v400[v618] = v397;
      int * v402 = v338->cache_tags;
      int v621 = (int)((unsigned int)((int)((unsigned int)v342 >> 2)) >> 1);
      v402[v597] = v621;
      int * v404 = v338->cache_dirty;
      v404[v597] = 0;
      int * v406 = v338->cache_age;
      v406[v597] = 1;
      int * v408 = v338->cache_age;
      int v409 = v408[v597];
      int v410 = v408[v572];
      int v627 = v410 + ((int)((unsigned int)(v410 - v409) >> 31));
      v408[v572] = v627;
      int * v412 = v338->cache_age;
      int v413 = v412[v573];
      int v629 = v413 + ((int)((unsigned int)(v413 - v409) >> 31));
      v412[v573] = v629;
      int * v415 = v338->cache_age;
      v415[v597] = 0;
      v418 = v597;
    }
    int * v419 = v338->cache_vals;
    int v632 = v418 * 2;
    int v420 = v419[v632];
    int v633 = (v418 * 2) + 1;
    int v421 = v419[v633];
    int v634 = (((((int)((unsigned int)((int)((unsigned int)v342 >> 2)) >> 1)) & 1) * 2) + ((((v360 + ((~(((v362 ^ -1) | (-(v362 ^ -1))) >> 31)) & 2)) - (v363 + ((~(((v364 ^ -1) | (-(v364 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
    v419[v634] = v420;
    int * v423 = v338->cache_vals;
    int v637 = ((((((int)((unsigned int)((int)((unsigned int)v342 >> 2)) >> 1)) & 1) * 2) + ((((v360 + ((~(((v362 ^ -1) | (-(v362 ^ -1))) >> 31)) & 2)) - (v363 + ((~(((v364 ^ -1) | (-(v364 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
    v423[v637] = v421;
    int * v425 = v338->cache_tags;
    int v640 = ((((int)((unsigned int)((int)((unsigned int)v342 >> 2)) >> 1)) & 1) * 2) + ((((v360 + ((~(((v362 ^ -1) | (-(v362 ^ -1))) >> 31)) & 2)) - (v363 + ((~(((v364 ^ -1) | (-(v364 ^ -1))) >> 31)) & 2))) >> 31) & 1);
    int v641 = (int)((unsigned int)((int)((unsigned int)v342 >> 2)) >> 1);
    v425[v640] = v641;
    int * v427 = v338->cache_dirty;
    v427[v640] = 0;
    int * v429 = v338->cache_age;
    v429[v640] = 1;
    int * v431 = v338->cache_age;
    int v432 = v431[v640];
    int v433 = v431[v570];
    int v647 = v433 + ((int)((unsigned int)(v433 - v432) >> 31));
    v431[v570] = v647;
    int * v435 = v338->cache_age;
    int v436 = v435[v571];
    int v649 = v436 + ((int)((unsigned int)(v436 - v432) >> 31));
    v435[v571] = v649;
    int * v438 = v338->cache_age;
    v438[v640] = 0;
    v441 = v640;
  }
  int v652 = (v441 * 2) + (((int)((unsigned int)v342 >> 2)) & 1);
  int v442 = v348[v652];
  int * v443 = v338->reg_ready;
  int v655 = ((v340 + ((v333 - v340) & (~((v333 - v340) >> 31)))) + 1) + ((100 ^ (((~(((v346 ^ ((int)((unsigned int)((int)((unsigned int)v342 >> 2)) >> 1))) | (-(v346 ^ ((int)((unsigned int)((int)((unsigned int)v342 >> 2)) >> 1))))) >> 31)) | (~(((v347 ^ ((int)((unsigned int)((int)((unsigned int)v342 >> 2)) >> 1))) | (-(v347 ^ ((int)((unsigned int)((int)((unsigned int)v342 >> 2)) >> 1))))) >> 31))) & 104)) ^ (((~(((v344 ^ ((int)((unsigned int)((int)((unsigned int)v342 >> 2)) >> 1))) | (-(v344 ^ ((int)((unsigned int)((int)((unsigned int)v342 >> 2)) >> 1))))) >> 31)) | (~(((v345 ^ ((int)((unsigned int)((int)((unsigned int)v342 >> 2)) >> 1))) | (-(v345 ^ ((int)((unsigned int)((int)((unsigned int)v342 >> 2)) >> 1))))) >> 31))) & (1 ^ (100 ^ (((~(((v346 ^ ((int)((unsigned int)((int)((unsigned int)v342 >> 2)) >> 1))) | (-(v346 ^ ((int)((unsigned int)((int)((unsigned int)v342 >> 2)) >> 1))))) >> 31)) | (~(((v347 ^ ((int)((unsigned int)((int)((unsigned int)v342 >> 2)) >> 1))) | (-(v347 ^ ((int)((unsigned int)((int)((unsigned int)v342 >> 2)) >> 1))))) >> 31))) & 104)))));
  v443[10] = v655;
  int * v445 = v338->regs;
  v445[10] = v442;
  struct StateT * v447 = v325->b;
  int * v448 = v447->reg_ready;
  int v449 = v448[5];
  int * v450 = v447->regs;
  int v451 = v450[5];
  int * v452 = v447->cache_tags;
  int v662 = (((int)((unsigned int)((int)((unsigned int)v451 >> 2)) >> 1)) & 1) * 2;
  int v453 = v452[v662];
  int v663 = ((((int)((unsigned int)((int)((unsigned int)v451 >> 2)) >> 1)) & 1) * 2) + 1;
  int v454 = v452[v663];
  int v664 = 4 + ((((int)((unsigned int)((int)((unsigned int)v451 >> 2)) >> 1)) & 3) * 2);
  int v455 = v452[v664];
  int v665 = (4 + ((((int)((unsigned int)((int)((unsigned int)v451 >> 2)) >> 1)) & 3) * 2)) + 1;
  int v456 = v452[v665];
  int * v457 = v447->cache_vals;
  bool v666 = !(((~(((v453 ^ ((int)((unsigned int)((int)((unsigned int)v451 >> 2)) >> 1))) | (-(v453 ^ ((int)((unsigned int)((int)((unsigned int)v451 >> 2)) >> 1))))) >> 31)) | (~(((v454 ^ ((int)((unsigned int)((int)((unsigned int)v451 >> 2)) >> 1))) | (-(v454 ^ ((int)((unsigned int)((int)((unsigned int)v451 >> 2)) >> 1))))) >> 31))) == 0);
  int v550;
  if (v666) {
    int * v458 = v447->cache_age;
    int v668 = ((((int)((unsigned int)((int)((unsigned int)v451 >> 2)) >> 1)) & 1) * 2) + ((~(((v454 ^ ((int)((unsigned int)((int)((unsigned int)v451 >> 2)) >> 1))) | (-(v454 ^ ((int)((unsigned int)((int)((unsigned int)v451 >> 2)) >> 1))))) >> 31)) & 1);
    int v459 = v458[v668];
    int v460 = v458[v662];
    int v669 = v460 + ((int)((unsigned int)(v460 - v459) >> 31));
    v458[v662] = v669;
    int * v462 = v447->cache_age;
    int v463 = v462[v663];
    int v671 = v463 + ((int)((unsigned int)(v463 - v459) >> 31));
    v462[v663] = v671;
    int * v465 = v447->cache_age;
    v465[v668] = 0;
    v550 = v668;
  } else {
    int * v468 = v447->cache_age;
    int v675 = (((int)((unsigned int)((int)((unsigned int)v451 >> 2)) >> 1)) & 1) * 2;
    int v469 = v468[v675];
    int * v470 = v447->cache_tags;
    int v471 = v470[v675];
    int v472 = v468[v663];
    int v473 = v470[v663];
    bool v677 = !(((~(((v455 ^ ((int)((unsigned int)((int)((unsigned int)v451 >> 2)) >> 1))) | (-(v455 ^ ((int)((unsigned int)((int)((unsigned int)v451 >> 2)) >> 1))))) >> 31)) | (~(((v456 ^ ((int)((unsigned int)((int)((unsigned int)v451 >> 2)) >> 1))) | (-(v456 ^ ((int)((unsigned int)((int)((unsigned int)v451 >> 2)) >> 1))))) >> 31))) == 0);
    int v527;
    if (v677) {
      int * v474 = v447->cache_age;
      int v679 = (4 + ((((int)((unsigned int)((int)((unsigned int)v451 >> 2)) >> 1)) & 3) * 2)) + ((~(((v456 ^ ((int)((unsigned int)((int)((unsigned int)v451 >> 2)) >> 1))) | (-(v456 ^ ((int)((unsigned int)((int)((unsigned int)v451 >> 2)) >> 1))))) >> 31)) & 1);
      int v475 = v474[v679];
      int v476 = v474[v664];
      int v680 = v476 + ((int)((unsigned int)(v476 - v475) >> 31));
      v474[v664] = v680;
      int * v478 = v447->cache_age;
      int v479 = v478[v665];
      int v682 = v479 + ((int)((unsigned int)(v479 - v475) >> 31));
      v478[v665] = v682;
      int * v481 = v447->cache_age;
      v481[v679] = 0;
      v527 = v679;
    } else {
      int * v484 = v447->cache_age;
      int v686 = 4 + ((((int)((unsigned int)((int)((unsigned int)v451 >> 2)) >> 1)) & 3) * 2);
      int v485 = v484[v686];
      int * v486 = v447->cache_tags;
      int v487 = v486[v686];
      int v488 = v484[v665];
      int v489 = v486[v665];
      int * v490 = v447->cache_dirty;
      int v689 = (4 + ((((int)((unsigned int)((int)((unsigned int)v451 >> 2)) >> 1)) & 3) * 2)) + ((((v485 + ((~(((v487 ^ -1) | (-(v487 ^ -1))) >> 31)) & 2)) - (v488 + ((~(((v489 ^ -1) | (-(v489 ^ -1))) >> 31)) & 2))) >> 31) & 1);
      int v491 = v490[v689];
      bool v690 = !(v491 == 0);
      if (v690) {
        int * v492 = v447->cache_tags;
        int v493 = v492[v689];
        int * v494 = v447->cache_vals;
        int v693 = ((4 + ((((int)((unsigned int)((int)((unsigned int)v451 >> 2)) >> 1)) & 3) * 2)) + ((((v485 + ((~(((v487 ^ -1) | (-(v487 ^ -1))) >> 31)) & 2)) - (v488 + ((~(((v489 ^ -1) | (-(v489 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
        int v495 = v494[v693];
        int v694 = (((4 + ((((int)((unsigned int)((int)((unsigned int)v451 >> 2)) >> 1)) & 3) * 2)) + ((((v485 + ((~(((v487 ^ -1) | (-(v487 ^ -1))) >> 31)) & 2)) - (v488 + ((~(((v489 ^ -1) | (-(v489 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
        int v496 = v494[v694];
        int * v497 = v447->mem;
        int v696 = v493 * 2;
        v497[v696] = v495;
        int * v499 = v447->mem;
        int v699 = (v493 * 2) + 1;
        v499[v699] = v496;
        ;
      } else {
        ;
      }
      int * v504 = v447->mem;
      int v704 = ((int)((unsigned int)((int)((unsigned int)v451 >> 2)) >> 1)) * 2;
      int v505 = v504[v704];
      int v705 = (((int)((unsigned int)((int)((unsigned int)v451 >> 2)) >> 1)) * 2) + 1;
      int v506 = v504[v705];
      int * v507 = v447->cache_vals;
      int v707 = ((4 + ((((int)((unsigned int)((int)((unsigned int)v451 >> 2)) >> 1)) & 3) * 2)) + ((((v485 + ((~(((v487 ^ -1) | (-(v487 ^ -1))) >> 31)) & 2)) - (v488 + ((~(((v489 ^ -1) | (-(v489 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
      v507[v707] = v505;
      int * v509 = v447->cache_vals;
      int v710 = (((4 + ((((int)((unsigned int)((int)((unsigned int)v451 >> 2)) >> 1)) & 3) * 2)) + ((((v485 + ((~(((v487 ^ -1) | (-(v487 ^ -1))) >> 31)) & 2)) - (v488 + ((~(((v489 ^ -1) | (-(v489 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
      v509[v710] = v506;
      int * v511 = v447->cache_tags;
      int v713 = (int)((unsigned int)((int)((unsigned int)v451 >> 2)) >> 1);
      v511[v689] = v713;
      int * v513 = v447->cache_dirty;
      v513[v689] = 0;
      int * v515 = v447->cache_age;
      v515[v689] = 1;
      int * v517 = v447->cache_age;
      int v518 = v517[v689];
      int v519 = v517[v664];
      int v719 = v519 + ((int)((unsigned int)(v519 - v518) >> 31));
      v517[v664] = v719;
      int * v521 = v447->cache_age;
      int v522 = v521[v665];
      int v721 = v522 + ((int)((unsigned int)(v522 - v518) >> 31));
      v521[v665] = v721;
      int * v524 = v447->cache_age;
      v524[v689] = 0;
      v527 = v689;
    }
    int * v528 = v447->cache_vals;
    int v724 = v527 * 2;
    int v529 = v528[v724];
    int v725 = (v527 * 2) + 1;
    int v530 = v528[v725];
    int v726 = (((((int)((unsigned int)((int)((unsigned int)v451 >> 2)) >> 1)) & 1) * 2) + ((((v469 + ((~(((v471 ^ -1) | (-(v471 ^ -1))) >> 31)) & 2)) - (v472 + ((~(((v473 ^ -1) | (-(v473 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
    v528[v726] = v529;
    int * v532 = v447->cache_vals;
    int v729 = ((((((int)((unsigned int)((int)((unsigned int)v451 >> 2)) >> 1)) & 1) * 2) + ((((v469 + ((~(((v471 ^ -1) | (-(v471 ^ -1))) >> 31)) & 2)) - (v472 + ((~(((v473 ^ -1) | (-(v473 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
    v532[v729] = v530;
    int * v534 = v447->cache_tags;
    int v732 = ((((int)((unsigned int)((int)((unsigned int)v451 >> 2)) >> 1)) & 1) * 2) + ((((v469 + ((~(((v471 ^ -1) | (-(v471 ^ -1))) >> 31)) & 2)) - (v472 + ((~(((v473 ^ -1) | (-(v473 ^ -1))) >> 31)) & 2))) >> 31) & 1);
    int v733 = (int)((unsigned int)((int)((unsigned int)v451 >> 2)) >> 1);
    v534[v732] = v733;
    int * v536 = v447->cache_dirty;
    v536[v732] = 0;
    int * v538 = v447->cache_age;
    v538[v732] = 1;
    int * v540 = v447->cache_age;
    int v541 = v540[v732];
    int v542 = v540[v662];
    int v739 = v542 + ((int)((unsigned int)(v542 - v541) >> 31));
    v540[v662] = v739;
    int * v544 = v447->cache_age;
    int v545 = v544[v663];
    int v741 = v545 + ((int)((unsigned int)(v545 - v541) >> 31));
    v544[v663] = v741;
    int * v547 = v447->cache_age;
    v547[v732] = 0;
    v550 = v732;
  }
  int v744 = (v550 * 2) + (((int)((unsigned int)v451 >> 2)) & 1);
  int v551 = v457[v744];
  int * v552 = v447->reg_ready;
  int v746 = ((v449 + ((v336 - v449) & (~((v336 - v449) >> 31)))) + 1) + ((100 ^ (((~(((v455 ^ ((int)((unsigned int)((int)((unsigned int)v451 >> 2)) >> 1))) | (-(v455 ^ ((int)((unsigned int)((int)((unsigned int)v451 >> 2)) >> 1))))) >> 31)) | (~(((v456 ^ ((int)((unsigned int)((int)((unsigned int)v451 >> 2)) >> 1))) | (-(v456 ^ ((int)((unsigned int)((int)((unsigned int)v451 >> 2)) >> 1))))) >> 31))) & 104)) ^ (((~(((v453 ^ ((int)((unsigned int)((int)((unsigned int)v451 >> 2)) >> 1))) | (-(v453 ^ ((int)((unsigned int)((int)((unsigned int)v451 >> 2)) >> 1))))) >> 31)) | (~(((v454 ^ ((int)((unsigned int)((int)((unsigned int)v451 >> 2)) >> 1))) | (-(v454 ^ ((int)((unsigned int)((int)((unsigned int)v451 >> 2)) >> 1))))) >> 31))) & (1 ^ (100 ^ (((~(((v455 ^ ((int)((unsigned int)((int)((unsigned int)v451 >> 2)) >> 1))) | (-(v455 ^ ((int)((unsigned int)((int)((unsigned int)v451 >> 2)) >> 1))))) >> 31)) | (~(((v456 ^ ((int)((unsigned int)((int)((unsigned int)v451 >> 2)) >> 1))) | (-(v456 ^ ((int)((unsigned int)((int)((unsigned int)v451 >> 2)) >> 1))))) >> 31))) & 104)))));
  v552[10] = v746;
  int * v554 = v447->regs;
  v554[10] = v551;
  struct StateT2 * v556 = slot_7(v325);
  return v556;
}

struct StateT2 * slot_5(struct StateT2 * v266) {
  struct StateT * v267 = v266->a;
  int v268 = v267->timer;
  struct StateT * v269 = v266->b;
  int v270 = v269->timer;
  bool v303 = v268 == v270;
  squared_assert(v303);
  squared_assume(v303);
  struct StateT * v273 = v266->a;
  int v274 = v273->timer;
  int v305 = v274 + 1;
  v273->timer = v305;
  struct StateT * v276 = v266->b;
  int v277 = v276->timer;
  int v307 = v277 + 1;
  v276->timer = v307;
  struct StateT * v279 = v266->a;
  int * v280 = v279->reg_ready;
  int v281 = v280[12];
  int * v282 = v279->regs;
  int v283 = v282[12];
  int v284 = v280[14];
  int v285 = v282[14];
  int v314 = (v284 + (((v281 + ((v274 - v281) & (~((v274 - v281) >> 31)))) - v284) & (~(((v281 + ((v274 - v281) & (~((v274 - v281) >> 31)))) - v284) >> 31)))) + 1;
  v280[5] = v314;
  int * v287 = v279->regs;
  int v316 = v283 + v285;
  v287[5] = v316;
  struct StateT * v289 = v266->b;
  int * v290 = v289->reg_ready;
  int v291 = v290[12];
  int * v292 = v289->regs;
  int v293 = v292[12];
  int v294 = v290[14];
  int v295 = v292[14];
  int v320 = (v294 + (((v291 + ((v277 - v291) & (~((v277 - v291) >> 31)))) - v294) & (~(((v291 + ((v277 - v291) & (~((v277 - v291) >> 31)))) - v294) >> 31)))) + 1;
  v290[5] = v320;
  int * v297 = v289->regs;
  int v322 = v293 + v295;
  v297[5] = v322;
  struct StateT2 * v299 = slot_6(v266);
  return v299;
}

struct StateT2 * slot_2(struct StateT2 * v86) {
  struct StateT * v87 = v86->a;
  int v88 = v87->timer;
  struct StateT * v89 = v86->b;
  int v90 = v89->timer;
  bool v113 = v88 == v90;
  squared_assert(v113);
  squared_assume(v113);
  struct StateT * v93 = v86->a;
  int v94 = v93->timer;
  int v115 = v94 + 1;
  v93->timer = v115;
  struct StateT * v96 = v86->b;
  int v97 = v96->timer;
  int v117 = v97 + 1;
  v96->timer = v117;
  struct StateT * v99 = v86->a;
  int * v100 = v99->reg_ready;
  v100[14] = v115;
  int * v102 = v99->regs;
  v102[14] = 0;
  struct StateT * v104 = v86->b;
  int * v105 = v104->reg_ready;
  v105[14] = v117;
  int * v107 = v104->regs;
  v107[14] = 0;
  struct StateT2 * v109 = slot_3(v86);
  return v109;
}

struct StateT2 * slot_7(struct StateT2 * v751) {
  struct StateT * v752 = v751->a;
  int v753 = v752->timer;
  struct StateT * v754 = v751->b;
  int v755 = v754->timer;
  bool v788 = v753 == v755;
  squared_assert(v788);
  squared_assume(v788);
  struct StateT * v758 = v751->a;
  int v759 = v758->timer;
  int v790 = v759 + 1;
  v758->timer = v790;
  struct StateT * v761 = v751->b;
  int v762 = v761->timer;
  int v792 = v762 + 1;
  v761->timer = v792;
  struct StateT * v764 = v751->a;
  int * v765 = v764->reg_ready;
  int v766 = v765[13];
  int * v767 = v764->regs;
  int v768 = v767[13];
  int v769 = v765[14];
  int v770 = v767[14];
  int v799 = (v769 + (((v766 + ((v759 - v766) & (~((v759 - v766) >> 31)))) - v769) & (~(((v766 + ((v759 - v766) & (~((v759 - v766) >> 31)))) - v769) >> 31)))) + 1;
  v765[6] = v799;
  int * v772 = v764->regs;
  int v801 = v768 + v770;
  v772[6] = v801;
  struct StateT * v774 = v751->b;
  int * v775 = v774->reg_ready;
  int v776 = v775[13];
  int * v777 = v774->regs;
  int v778 = v777[13];
  int v779 = v775[14];
  int v780 = v777[14];
  int v805 = (v779 + (((v776 + ((v762 - v776) & (~((v762 - v776) >> 31)))) - v779) & (~(((v776 + ((v762 - v776) & (~((v762 - v776) >> 31)))) - v779) >> 31)))) + 1;
  v775[6] = v805;
  int * v782 = v774->regs;
  int v807 = v778 + v780;
  v782[6] = v807;
  struct StateT2 * v784 = slot_8(v751);
  return v784;
}

struct StateT2 * slot_3(struct StateT2 * v128) {
  struct StateT * v129 = v128->a;
  int v130 = v129->timer;
  struct StateT * v131 = v128->b;
  int v132 = v131->timer;
  bool v155 = v130 == v132;
  squared_assert(v155);
  squared_assume(v155);
  struct StateT * v135 = v128->a;
  int v136 = v135->timer;
  int v157 = v136 + 1;
  v135->timer = v157;
  struct StateT * v138 = v128->b;
  int v139 = v138->timer;
  int v159 = v139 + 1;
  v138->timer = v159;
  struct StateT * v141 = v128->a;
  int * v142 = v141->reg_ready;
  v142[15] = v157;
  int * v144 = v141->regs;
  v144[15] = 16;
  struct StateT * v146 = v128->b;
  int * v147 = v146->reg_ready;
  v147[15] = v159;
  int * v149 = v146->regs;
  v149[15] = 16;
  struct StateT2 * v151 = slot_4(v128);
  return v151;
}

struct StateT2 * snippet(struct StateT2 * v0) {
  struct StateT2 * v1 = slot_0(v0);
  struct StateT * v1437 = v1->a;
  int v1438 = v1437->timer;
  int * v1439 = v1437->reg_ready;
  int v1440 = v1439[0];
  int v1701 = v1440 + ((v1438 - v1440) & (~((v1438 - v1440) >> 31)));
  v1437->timer = v1701;
  int v1442 = v1437->timer;
  int * v1443 = v1437->reg_ready;
  int v1444 = v1443[1];
  int v1704 = v1444 + ((v1442 - v1444) & (~((v1442 - v1444) >> 31)));
  v1437->timer = v1704;
  int v1446 = v1437->timer;
  int * v1447 = v1437->reg_ready;
  int v1448 = v1447[2];
  int v1707 = v1448 + ((v1446 - v1448) & (~((v1446 - v1448) >> 31)));
  v1437->timer = v1707;
  int v1450 = v1437->timer;
  int * v1451 = v1437->reg_ready;
  int v1452 = v1451[3];
  int v1710 = v1452 + ((v1450 - v1452) & (~((v1450 - v1452) >> 31)));
  v1437->timer = v1710;
  int v1454 = v1437->timer;
  int * v1455 = v1437->reg_ready;
  int v1456 = v1455[4];
  int v1713 = v1456 + ((v1454 - v1456) & (~((v1454 - v1456) >> 31)));
  v1437->timer = v1713;
  int v1458 = v1437->timer;
  int * v1459 = v1437->reg_ready;
  int v1460 = v1459[5];
  int v1716 = v1460 + ((v1458 - v1460) & (~((v1458 - v1460) >> 31)));
  v1437->timer = v1716;
  int v1462 = v1437->timer;
  int * v1463 = v1437->reg_ready;
  int v1464 = v1463[6];
  int v1719 = v1464 + ((v1462 - v1464) & (~((v1462 - v1464) >> 31)));
  v1437->timer = v1719;
  int v1466 = v1437->timer;
  int * v1467 = v1437->reg_ready;
  int v1468 = v1467[7];
  int v1722 = v1468 + ((v1466 - v1468) & (~((v1466 - v1468) >> 31)));
  v1437->timer = v1722;
  int v1470 = v1437->timer;
  int * v1471 = v1437->reg_ready;
  int v1472 = v1471[8];
  int v1725 = v1472 + ((v1470 - v1472) & (~((v1470 - v1472) >> 31)));
  v1437->timer = v1725;
  int v1474 = v1437->timer;
  int * v1475 = v1437->reg_ready;
  int v1476 = v1475[9];
  int v1728 = v1476 + ((v1474 - v1476) & (~((v1474 - v1476) >> 31)));
  v1437->timer = v1728;
  int v1478 = v1437->timer;
  int * v1479 = v1437->reg_ready;
  int v1480 = v1479[10];
  int v1731 = v1480 + ((v1478 - v1480) & (~((v1478 - v1480) >> 31)));
  v1437->timer = v1731;
  int v1482 = v1437->timer;
  int * v1483 = v1437->reg_ready;
  int v1484 = v1483[11];
  int v1734 = v1484 + ((v1482 - v1484) & (~((v1482 - v1484) >> 31)));
  v1437->timer = v1734;
  int v1486 = v1437->timer;
  int * v1487 = v1437->reg_ready;
  int v1488 = v1487[12];
  int v1737 = v1488 + ((v1486 - v1488) & (~((v1486 - v1488) >> 31)));
  v1437->timer = v1737;
  int v1490 = v1437->timer;
  int * v1491 = v1437->reg_ready;
  int v1492 = v1491[13];
  int v1740 = v1492 + ((v1490 - v1492) & (~((v1490 - v1492) >> 31)));
  v1437->timer = v1740;
  int v1494 = v1437->timer;
  int * v1495 = v1437->reg_ready;
  int v1496 = v1495[14];
  int v1743 = v1496 + ((v1494 - v1496) & (~((v1494 - v1496) >> 31)));
  v1437->timer = v1743;
  int v1498 = v1437->timer;
  int * v1499 = v1437->reg_ready;
  int v1500 = v1499[15];
  int v1746 = v1500 + ((v1498 - v1500) & (~((v1498 - v1500) >> 31)));
  v1437->timer = v1746;
  int v1502 = v1437->timer;
  int * v1503 = v1437->reg_ready;
  int v1504 = v1503[16];
  int v1749 = v1504 + ((v1502 - v1504) & (~((v1502 - v1504) >> 31)));
  v1437->timer = v1749;
  int v1506 = v1437->timer;
  int * v1507 = v1437->reg_ready;
  int v1508 = v1507[17];
  int v1752 = v1508 + ((v1506 - v1508) & (~((v1506 - v1508) >> 31)));
  v1437->timer = v1752;
  int v1510 = v1437->timer;
  int * v1511 = v1437->reg_ready;
  int v1512 = v1511[18];
  int v1755 = v1512 + ((v1510 - v1512) & (~((v1510 - v1512) >> 31)));
  v1437->timer = v1755;
  int v1514 = v1437->timer;
  int * v1515 = v1437->reg_ready;
  int v1516 = v1515[19];
  int v1758 = v1516 + ((v1514 - v1516) & (~((v1514 - v1516) >> 31)));
  v1437->timer = v1758;
  int v1518 = v1437->timer;
  int * v1519 = v1437->reg_ready;
  int v1520 = v1519[20];
  int v1761 = v1520 + ((v1518 - v1520) & (~((v1518 - v1520) >> 31)));
  v1437->timer = v1761;
  int v1522 = v1437->timer;
  int * v1523 = v1437->reg_ready;
  int v1524 = v1523[21];
  int v1764 = v1524 + ((v1522 - v1524) & (~((v1522 - v1524) >> 31)));
  v1437->timer = v1764;
  int v1526 = v1437->timer;
  int * v1527 = v1437->reg_ready;
  int v1528 = v1527[22];
  int v1767 = v1528 + ((v1526 - v1528) & (~((v1526 - v1528) >> 31)));
  v1437->timer = v1767;
  int v1530 = v1437->timer;
  int * v1531 = v1437->reg_ready;
  int v1532 = v1531[23];
  int v1770 = v1532 + ((v1530 - v1532) & (~((v1530 - v1532) >> 31)));
  v1437->timer = v1770;
  int v1534 = v1437->timer;
  int * v1535 = v1437->reg_ready;
  int v1536 = v1535[24];
  int v1773 = v1536 + ((v1534 - v1536) & (~((v1534 - v1536) >> 31)));
  v1437->timer = v1773;
  int v1538 = v1437->timer;
  int * v1539 = v1437->reg_ready;
  int v1540 = v1539[25];
  int v1776 = v1540 + ((v1538 - v1540) & (~((v1538 - v1540) >> 31)));
  v1437->timer = v1776;
  int v1542 = v1437->timer;
  int * v1543 = v1437->reg_ready;
  int v1544 = v1543[26];
  int v1779 = v1544 + ((v1542 - v1544) & (~((v1542 - v1544) >> 31)));
  v1437->timer = v1779;
  int v1546 = v1437->timer;
  int * v1547 = v1437->reg_ready;
  int v1548 = v1547[27];
  int v1782 = v1548 + ((v1546 - v1548) & (~((v1546 - v1548) >> 31)));
  v1437->timer = v1782;
  int v1550 = v1437->timer;
  int * v1551 = v1437->reg_ready;
  int v1552 = v1551[28];
  int v1785 = v1552 + ((v1550 - v1552) & (~((v1550 - v1552) >> 31)));
  v1437->timer = v1785;
  int v1554 = v1437->timer;
  int * v1555 = v1437->reg_ready;
  int v1556 = v1555[29];
  int v1788 = v1556 + ((v1554 - v1556) & (~((v1554 - v1556) >> 31)));
  v1437->timer = v1788;
  int v1558 = v1437->timer;
  int * v1559 = v1437->reg_ready;
  int v1560 = v1559[30];
  int v1791 = v1560 + ((v1558 - v1560) & (~((v1558 - v1560) >> 31)));
  v1437->timer = v1791;
  int v1562 = v1437->timer;
  int * v1563 = v1437->reg_ready;
  int v1564 = v1563[31];
  int v1794 = v1564 + ((v1562 - v1564) & (~((v1562 - v1564) >> 31)));
  v1437->timer = v1794;
  struct StateT * v1566 = v1->b;
  int v1567 = v1566->timer;
  int * v1568 = v1566->reg_ready;
  int v1569 = v1568[0];
  int v1797 = v1569 + ((v1567 - v1569) & (~((v1567 - v1569) >> 31)));
  v1566->timer = v1797;
  int v1571 = v1566->timer;
  int * v1572 = v1566->reg_ready;
  int v1573 = v1572[1];
  int v1799 = v1573 + ((v1571 - v1573) & (~((v1571 - v1573) >> 31)));
  v1566->timer = v1799;
  int v1575 = v1566->timer;
  int * v1576 = v1566->reg_ready;
  int v1577 = v1576[2];
  int v1801 = v1577 + ((v1575 - v1577) & (~((v1575 - v1577) >> 31)));
  v1566->timer = v1801;
  int v1579 = v1566->timer;
  int * v1580 = v1566->reg_ready;
  int v1581 = v1580[3];
  int v1803 = v1581 + ((v1579 - v1581) & (~((v1579 - v1581) >> 31)));
  v1566->timer = v1803;
  int v1583 = v1566->timer;
  int * v1584 = v1566->reg_ready;
  int v1585 = v1584[4];
  int v1805 = v1585 + ((v1583 - v1585) & (~((v1583 - v1585) >> 31)));
  v1566->timer = v1805;
  int v1587 = v1566->timer;
  int * v1588 = v1566->reg_ready;
  int v1589 = v1588[5];
  int v1807 = v1589 + ((v1587 - v1589) & (~((v1587 - v1589) >> 31)));
  v1566->timer = v1807;
  int v1591 = v1566->timer;
  int * v1592 = v1566->reg_ready;
  int v1593 = v1592[6];
  int v1809 = v1593 + ((v1591 - v1593) & (~((v1591 - v1593) >> 31)));
  v1566->timer = v1809;
  int v1595 = v1566->timer;
  int * v1596 = v1566->reg_ready;
  int v1597 = v1596[7];
  int v1811 = v1597 + ((v1595 - v1597) & (~((v1595 - v1597) >> 31)));
  v1566->timer = v1811;
  int v1599 = v1566->timer;
  int * v1600 = v1566->reg_ready;
  int v1601 = v1600[8];
  int v1813 = v1601 + ((v1599 - v1601) & (~((v1599 - v1601) >> 31)));
  v1566->timer = v1813;
  int v1603 = v1566->timer;
  int * v1604 = v1566->reg_ready;
  int v1605 = v1604[9];
  int v1815 = v1605 + ((v1603 - v1605) & (~((v1603 - v1605) >> 31)));
  v1566->timer = v1815;
  int v1607 = v1566->timer;
  int * v1608 = v1566->reg_ready;
  int v1609 = v1608[10];
  int v1817 = v1609 + ((v1607 - v1609) & (~((v1607 - v1609) >> 31)));
  v1566->timer = v1817;
  int v1611 = v1566->timer;
  int * v1612 = v1566->reg_ready;
  int v1613 = v1612[11];
  int v1819 = v1613 + ((v1611 - v1613) & (~((v1611 - v1613) >> 31)));
  v1566->timer = v1819;
  int v1615 = v1566->timer;
  int * v1616 = v1566->reg_ready;
  int v1617 = v1616[12];
  int v1821 = v1617 + ((v1615 - v1617) & (~((v1615 - v1617) >> 31)));
  v1566->timer = v1821;
  int v1619 = v1566->timer;
  int * v1620 = v1566->reg_ready;
  int v1621 = v1620[13];
  int v1823 = v1621 + ((v1619 - v1621) & (~((v1619 - v1621) >> 31)));
  v1566->timer = v1823;
  int v1623 = v1566->timer;
  int * v1624 = v1566->reg_ready;
  int v1625 = v1624[14];
  int v1825 = v1625 + ((v1623 - v1625) & (~((v1623 - v1625) >> 31)));
  v1566->timer = v1825;
  int v1627 = v1566->timer;
  int * v1628 = v1566->reg_ready;
  int v1629 = v1628[15];
  int v1827 = v1629 + ((v1627 - v1629) & (~((v1627 - v1629) >> 31)));
  v1566->timer = v1827;
  int v1631 = v1566->timer;
  int * v1632 = v1566->reg_ready;
  int v1633 = v1632[16];
  int v1829 = v1633 + ((v1631 - v1633) & (~((v1631 - v1633) >> 31)));
  v1566->timer = v1829;
  int v1635 = v1566->timer;
  int * v1636 = v1566->reg_ready;
  int v1637 = v1636[17];
  int v1831 = v1637 + ((v1635 - v1637) & (~((v1635 - v1637) >> 31)));
  v1566->timer = v1831;
  int v1639 = v1566->timer;
  int * v1640 = v1566->reg_ready;
  int v1641 = v1640[18];
  int v1833 = v1641 + ((v1639 - v1641) & (~((v1639 - v1641) >> 31)));
  v1566->timer = v1833;
  int v1643 = v1566->timer;
  int * v1644 = v1566->reg_ready;
  int v1645 = v1644[19];
  int v1835 = v1645 + ((v1643 - v1645) & (~((v1643 - v1645) >> 31)));
  v1566->timer = v1835;
  int v1647 = v1566->timer;
  int * v1648 = v1566->reg_ready;
  int v1649 = v1648[20];
  int v1837 = v1649 + ((v1647 - v1649) & (~((v1647 - v1649) >> 31)));
  v1566->timer = v1837;
  int v1651 = v1566->timer;
  int * v1652 = v1566->reg_ready;
  int v1653 = v1652[21];
  int v1839 = v1653 + ((v1651 - v1653) & (~((v1651 - v1653) >> 31)));
  v1566->timer = v1839;
  int v1655 = v1566->timer;
  int * v1656 = v1566->reg_ready;
  int v1657 = v1656[22];
  int v1841 = v1657 + ((v1655 - v1657) & (~((v1655 - v1657) >> 31)));
  v1566->timer = v1841;
  int v1659 = v1566->timer;
  int * v1660 = v1566->reg_ready;
  int v1661 = v1660[23];
  int v1843 = v1661 + ((v1659 - v1661) & (~((v1659 - v1661) >> 31)));
  v1566->timer = v1843;
  int v1663 = v1566->timer;
  int * v1664 = v1566->reg_ready;
  int v1665 = v1664[24];
  int v1845 = v1665 + ((v1663 - v1665) & (~((v1663 - v1665) >> 31)));
  v1566->timer = v1845;
  int v1667 = v1566->timer;
  int * v1668 = v1566->reg_ready;
  int v1669 = v1668[25];
  int v1847 = v1669 + ((v1667 - v1669) & (~((v1667 - v1669) >> 31)));
  v1566->timer = v1847;
  int v1671 = v1566->timer;
  int * v1672 = v1566->reg_ready;
  int v1673 = v1672[26];
  int v1849 = v1673 + ((v1671 - v1673) & (~((v1671 - v1673) >> 31)));
  v1566->timer = v1849;
  int v1675 = v1566->timer;
  int * v1676 = v1566->reg_ready;
  int v1677 = v1676[27];
  int v1851 = v1677 + ((v1675 - v1677) & (~((v1675 - v1677) >> 31)));
  v1566->timer = v1851;
  int v1679 = v1566->timer;
  int * v1680 = v1566->reg_ready;
  int v1681 = v1680[28];
  int v1853 = v1681 + ((v1679 - v1681) & (~((v1679 - v1681) >> 31)));
  v1566->timer = v1853;
  int v1683 = v1566->timer;
  int * v1684 = v1566->reg_ready;
  int v1685 = v1684[29];
  int v1855 = v1685 + ((v1683 - v1685) & (~((v1683 - v1685) >> 31)));
  v1566->timer = v1855;
  int v1687 = v1566->timer;
  int * v1688 = v1566->reg_ready;
  int v1689 = v1688[30];
  int v1857 = v1689 + ((v1687 - v1689) & (~((v1687 - v1689) >> 31)));
  v1566->timer = v1857;
  int v1691 = v1566->timer;
  int * v1692 = v1566->reg_ready;
  int v1693 = v1692[31];
  int v1859 = v1693 + ((v1691 - v1693) & (~((v1691 - v1693) >> 31)));
  v1566->timer = v1859;
  return v1;
}

struct StateT2 * slot_10(struct StateT2 * v1335) {
  struct StateT * v1336 = v1335->a;
  int v1337 = v1336->timer;
  struct StateT * v1338 = v1335->b;
  int v1339 = v1338->timer;
  bool v1368 = v1337 == v1339;
  squared_assert(v1368);
  squared_assume(v1368);
  struct StateT * v1342 = v1335->a;
  int v1343 = v1342->timer;
  int v1370 = v1343 + 1;
  v1342->timer = v1370;
  struct StateT * v1345 = v1335->b;
  int v1346 = v1345->timer;
  int v1372 = v1346 + 1;
  v1345->timer = v1372;
  struct StateT * v1348 = v1335->a;
  int * v1349 = v1348->reg_ready;
  int v1350 = v1349[14];
  int * v1351 = v1348->regs;
  int v1352 = v1351[14];
  int v1377 = (v1350 + ((v1343 - v1350) & (~((v1343 - v1350) >> 31)))) + 1;
  v1349[14] = v1377;
  int * v1354 = v1348->regs;
  int v1379 = v1352 + 4;
  v1354[14] = v1379;
  struct StateT * v1356 = v1335->b;
  int * v1357 = v1356->reg_ready;
  int v1358 = v1357[14];
  int * v1359 = v1356->regs;
  int v1360 = v1359[14];
  int v1383 = (v1358 + ((v1346 - v1358) & (~((v1346 - v1358) >> 31)))) + 1;
  v1357[14] = v1383;
  int * v1362 = v1356->regs;
  int v1385 = v1360 + 4;
  v1362[14] = v1385;
  struct StateT2 * v1364 = slot_11(v1335);
  return v1364;
}

struct StateT2 * slot_1(struct StateT2 * v44) {
  struct StateT * v45 = v44->a;
  int v46 = v45->timer;
  struct StateT * v47 = v44->b;
  int v48 = v47->timer;
  bool v71 = v46 == v48;
  squared_assert(v71);
  squared_assume(v71);
  struct StateT * v51 = v44->a;
  int v52 = v51->timer;
  int v73 = v52 + 1;
  v51->timer = v73;
  struct StateT * v54 = v44->b;
  int v55 = v54->timer;
  int v75 = v55 + 1;
  v54->timer = v75;
  struct StateT * v57 = v44->a;
  int * v58 = v57->reg_ready;
  v58[13] = v73;
  int * v60 = v57->regs;
  v60[13] = 80;
  struct StateT * v62 = v44->b;
  int * v63 = v62->reg_ready;
  v63[13] = v75;
  int * v65 = v62->regs;
  v65[13] = 80;
  struct StateT2 * v67 = slot_2(v44);
  return v67;
}

struct StateT2 * slot_8(struct StateT2 * v810) {
  struct StateT * v811 = v810->a;
  int v812 = v811->timer;
  struct StateT * v813 = v810->b;
  int v814 = v813->timer;
  bool v1045 = v812 == v814;
  squared_assert(v1045);
  squared_assume(v1045);
  struct StateT * v817 = v810->a;
  int v818 = v817->timer;
  int v1047 = v818 + 1;
  v817->timer = v1047;
  struct StateT * v820 = v810->b;
  int v821 = v820->timer;
  int v1049 = v821 + 1;
  v820->timer = v1049;
  struct StateT * v823 = v810->a;
  int * v824 = v823->reg_ready;
  int v825 = v824[6];
  int * v826 = v823->regs;
  int v827 = v826[6];
  int * v828 = v823->cache_tags;
  int v1055 = (((int)((unsigned int)((int)((unsigned int)v827 >> 2)) >> 1)) & 1) * 2;
  int v829 = v828[v1055];
  int v1056 = ((((int)((unsigned int)((int)((unsigned int)v827 >> 2)) >> 1)) & 1) * 2) + 1;
  int v830 = v828[v1056];
  int v1057 = 4 + ((((int)((unsigned int)((int)((unsigned int)v827 >> 2)) >> 1)) & 3) * 2);
  int v831 = v828[v1057];
  int v1058 = (4 + ((((int)((unsigned int)((int)((unsigned int)v827 >> 2)) >> 1)) & 3) * 2)) + 1;
  int v832 = v828[v1058];
  int * v833 = v823->cache_vals;
  bool v1059 = !(((~(((v829 ^ ((int)((unsigned int)((int)((unsigned int)v827 >> 2)) >> 1))) | (-(v829 ^ ((int)((unsigned int)((int)((unsigned int)v827 >> 2)) >> 1))))) >> 31)) | (~(((v830 ^ ((int)((unsigned int)((int)((unsigned int)v827 >> 2)) >> 1))) | (-(v830 ^ ((int)((unsigned int)((int)((unsigned int)v827 >> 2)) >> 1))))) >> 31))) == 0);
  int v926;
  if (v1059) {
    int * v834 = v823->cache_age;
    int v1061 = ((((int)((unsigned int)((int)((unsigned int)v827 >> 2)) >> 1)) & 1) * 2) + ((~(((v830 ^ ((int)((unsigned int)((int)((unsigned int)v827 >> 2)) >> 1))) | (-(v830 ^ ((int)((unsigned int)((int)((unsigned int)v827 >> 2)) >> 1))))) >> 31)) & 1);
    int v835 = v834[v1061];
    int v836 = v834[v1055];
    int v1062 = v836 + ((int)((unsigned int)(v836 - v835) >> 31));
    v834[v1055] = v1062;
    int * v838 = v823->cache_age;
    int v839 = v838[v1056];
    int v1064 = v839 + ((int)((unsigned int)(v839 - v835) >> 31));
    v838[v1056] = v1064;
    int * v841 = v823->cache_age;
    v841[v1061] = 0;
    v926 = v1061;
  } else {
    int * v844 = v823->cache_age;
    int v1068 = (((int)((unsigned int)((int)((unsigned int)v827 >> 2)) >> 1)) & 1) * 2;
    int v845 = v844[v1068];
    int * v846 = v823->cache_tags;
    int v847 = v846[v1068];
    int v848 = v844[v1056];
    int v849 = v846[v1056];
    bool v1070 = !(((~(((v831 ^ ((int)((unsigned int)((int)((unsigned int)v827 >> 2)) >> 1))) | (-(v831 ^ ((int)((unsigned int)((int)((unsigned int)v827 >> 2)) >> 1))))) >> 31)) | (~(((v832 ^ ((int)((unsigned int)((int)((unsigned int)v827 >> 2)) >> 1))) | (-(v832 ^ ((int)((unsigned int)((int)((unsigned int)v827 >> 2)) >> 1))))) >> 31))) == 0);
    int v903;
    if (v1070) {
      int * v850 = v823->cache_age;
      int v1072 = (4 + ((((int)((unsigned int)((int)((unsigned int)v827 >> 2)) >> 1)) & 3) * 2)) + ((~(((v832 ^ ((int)((unsigned int)((int)((unsigned int)v827 >> 2)) >> 1))) | (-(v832 ^ ((int)((unsigned int)((int)((unsigned int)v827 >> 2)) >> 1))))) >> 31)) & 1);
      int v851 = v850[v1072];
      int v852 = v850[v1057];
      int v1073 = v852 + ((int)((unsigned int)(v852 - v851) >> 31));
      v850[v1057] = v1073;
      int * v854 = v823->cache_age;
      int v855 = v854[v1058];
      int v1075 = v855 + ((int)((unsigned int)(v855 - v851) >> 31));
      v854[v1058] = v1075;
      int * v857 = v823->cache_age;
      v857[v1072] = 0;
      v903 = v1072;
    } else {
      int * v860 = v823->cache_age;
      int v1079 = 4 + ((((int)((unsigned int)((int)((unsigned int)v827 >> 2)) >> 1)) & 3) * 2);
      int v861 = v860[v1079];
      int * v862 = v823->cache_tags;
      int v863 = v862[v1079];
      int v864 = v860[v1058];
      int v865 = v862[v1058];
      int * v866 = v823->cache_dirty;
      int v1082 = (4 + ((((int)((unsigned int)((int)((unsigned int)v827 >> 2)) >> 1)) & 3) * 2)) + ((((v861 + ((~(((v863 ^ -1) | (-(v863 ^ -1))) >> 31)) & 2)) - (v864 + ((~(((v865 ^ -1) | (-(v865 ^ -1))) >> 31)) & 2))) >> 31) & 1);
      int v867 = v866[v1082];
      bool v1083 = !(v867 == 0);
      if (v1083) {
        int * v868 = v823->cache_tags;
        int v869 = v868[v1082];
        int * v870 = v823->cache_vals;
        int v1086 = ((4 + ((((int)((unsigned int)((int)((unsigned int)v827 >> 2)) >> 1)) & 3) * 2)) + ((((v861 + ((~(((v863 ^ -1) | (-(v863 ^ -1))) >> 31)) & 2)) - (v864 + ((~(((v865 ^ -1) | (-(v865 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
        int v871 = v870[v1086];
        int v1087 = (((4 + ((((int)((unsigned int)((int)((unsigned int)v827 >> 2)) >> 1)) & 3) * 2)) + ((((v861 + ((~(((v863 ^ -1) | (-(v863 ^ -1))) >> 31)) & 2)) - (v864 + ((~(((v865 ^ -1) | (-(v865 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
        int v872 = v870[v1087];
        int * v873 = v823->mem;
        int v1089 = v869 * 2;
        v873[v1089] = v871;
        int * v875 = v823->mem;
        int v1092 = (v869 * 2) + 1;
        v875[v1092] = v872;
        ;
      } else {
        ;
      }
      int * v880 = v823->mem;
      int v1097 = ((int)((unsigned int)((int)((unsigned int)v827 >> 2)) >> 1)) * 2;
      int v881 = v880[v1097];
      int v1098 = (((int)((unsigned int)((int)((unsigned int)v827 >> 2)) >> 1)) * 2) + 1;
      int v882 = v880[v1098];
      int * v883 = v823->cache_vals;
      int v1100 = ((4 + ((((int)((unsigned int)((int)((unsigned int)v827 >> 2)) >> 1)) & 3) * 2)) + ((((v861 + ((~(((v863 ^ -1) | (-(v863 ^ -1))) >> 31)) & 2)) - (v864 + ((~(((v865 ^ -1) | (-(v865 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
      v883[v1100] = v881;
      int * v885 = v823->cache_vals;
      int v1103 = (((4 + ((((int)((unsigned int)((int)((unsigned int)v827 >> 2)) >> 1)) & 3) * 2)) + ((((v861 + ((~(((v863 ^ -1) | (-(v863 ^ -1))) >> 31)) & 2)) - (v864 + ((~(((v865 ^ -1) | (-(v865 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
      v885[v1103] = v882;
      int * v887 = v823->cache_tags;
      int v1106 = (int)((unsigned int)((int)((unsigned int)v827 >> 2)) >> 1);
      v887[v1082] = v1106;
      int * v889 = v823->cache_dirty;
      v889[v1082] = 0;
      int * v891 = v823->cache_age;
      v891[v1082] = 1;
      int * v893 = v823->cache_age;
      int v894 = v893[v1082];
      int v895 = v893[v1057];
      int v1112 = v895 + ((int)((unsigned int)(v895 - v894) >> 31));
      v893[v1057] = v1112;
      int * v897 = v823->cache_age;
      int v898 = v897[v1058];
      int v1114 = v898 + ((int)((unsigned int)(v898 - v894) >> 31));
      v897[v1058] = v1114;
      int * v900 = v823->cache_age;
      v900[v1082] = 0;
      v903 = v1082;
    }
    int * v904 = v823->cache_vals;
    int v1117 = v903 * 2;
    int v905 = v904[v1117];
    int v1118 = (v903 * 2) + 1;
    int v906 = v904[v1118];
    int v1119 = (((((int)((unsigned int)((int)((unsigned int)v827 >> 2)) >> 1)) & 1) * 2) + ((((v845 + ((~(((v847 ^ -1) | (-(v847 ^ -1))) >> 31)) & 2)) - (v848 + ((~(((v849 ^ -1) | (-(v849 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
    v904[v1119] = v905;
    int * v908 = v823->cache_vals;
    int v1122 = ((((((int)((unsigned int)((int)((unsigned int)v827 >> 2)) >> 1)) & 1) * 2) + ((((v845 + ((~(((v847 ^ -1) | (-(v847 ^ -1))) >> 31)) & 2)) - (v848 + ((~(((v849 ^ -1) | (-(v849 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
    v908[v1122] = v906;
    int * v910 = v823->cache_tags;
    int v1125 = ((((int)((unsigned int)((int)((unsigned int)v827 >> 2)) >> 1)) & 1) * 2) + ((((v845 + ((~(((v847 ^ -1) | (-(v847 ^ -1))) >> 31)) & 2)) - (v848 + ((~(((v849 ^ -1) | (-(v849 ^ -1))) >> 31)) & 2))) >> 31) & 1);
    int v1126 = (int)((unsigned int)((int)((unsigned int)v827 >> 2)) >> 1);
    v910[v1125] = v1126;
    int * v912 = v823->cache_dirty;
    v912[v1125] = 0;
    int * v914 = v823->cache_age;
    v914[v1125] = 1;
    int * v916 = v823->cache_age;
    int v917 = v916[v1125];
    int v918 = v916[v1055];
    int v1132 = v918 + ((int)((unsigned int)(v918 - v917) >> 31));
    v916[v1055] = v1132;
    int * v920 = v823->cache_age;
    int v921 = v920[v1056];
    int v1134 = v921 + ((int)((unsigned int)(v921 - v917) >> 31));
    v920[v1056] = v1134;
    int * v923 = v823->cache_age;
    v923[v1125] = 0;
    v926 = v1125;
  }
  int v1137 = (v926 * 2) + (((int)((unsigned int)v827 >> 2)) & 1);
  int v927 = v833[v1137];
  int * v928 = v823->reg_ready;
  int v1140 = ((v825 + ((v818 - v825) & (~((v818 - v825) >> 31)))) + 1) + ((100 ^ (((~(((v831 ^ ((int)((unsigned int)((int)((unsigned int)v827 >> 2)) >> 1))) | (-(v831 ^ ((int)((unsigned int)((int)((unsigned int)v827 >> 2)) >> 1))))) >> 31)) | (~(((v832 ^ ((int)((unsigned int)((int)((unsigned int)v827 >> 2)) >> 1))) | (-(v832 ^ ((int)((unsigned int)((int)((unsigned int)v827 >> 2)) >> 1))))) >> 31))) & 104)) ^ (((~(((v829 ^ ((int)((unsigned int)((int)((unsigned int)v827 >> 2)) >> 1))) | (-(v829 ^ ((int)((unsigned int)((int)((unsigned int)v827 >> 2)) >> 1))))) >> 31)) | (~(((v830 ^ ((int)((unsigned int)((int)((unsigned int)v827 >> 2)) >> 1))) | (-(v830 ^ ((int)((unsigned int)((int)((unsigned int)v827 >> 2)) >> 1))))) >> 31))) & (1 ^ (100 ^ (((~(((v831 ^ ((int)((unsigned int)((int)((unsigned int)v827 >> 2)) >> 1))) | (-(v831 ^ ((int)((unsigned int)((int)((unsigned int)v827 >> 2)) >> 1))))) >> 31)) | (~(((v832 ^ ((int)((unsigned int)((int)((unsigned int)v827 >> 2)) >> 1))) | (-(v832 ^ ((int)((unsigned int)((int)((unsigned int)v827 >> 2)) >> 1))))) >> 31))) & 104)))));
  v928[11] = v1140;
  int * v930 = v823->regs;
  v930[11] = v927;
  struct StateT * v932 = v810->b;
  int * v933 = v932->reg_ready;
  int v934 = v933[6];
  int * v935 = v932->regs;
  int v936 = v935[6];
  int * v937 = v932->cache_tags;
  int v1147 = (((int)((unsigned int)((int)((unsigned int)v936 >> 2)) >> 1)) & 1) * 2;
  int v938 = v937[v1147];
  int v1148 = ((((int)((unsigned int)((int)((unsigned int)v936 >> 2)) >> 1)) & 1) * 2) + 1;
  int v939 = v937[v1148];
  int v1149 = 4 + ((((int)((unsigned int)((int)((unsigned int)v936 >> 2)) >> 1)) & 3) * 2);
  int v940 = v937[v1149];
  int v1150 = (4 + ((((int)((unsigned int)((int)((unsigned int)v936 >> 2)) >> 1)) & 3) * 2)) + 1;
  int v941 = v937[v1150];
  int * v942 = v932->cache_vals;
  bool v1151 = !(((~(((v938 ^ ((int)((unsigned int)((int)((unsigned int)v936 >> 2)) >> 1))) | (-(v938 ^ ((int)((unsigned int)((int)((unsigned int)v936 >> 2)) >> 1))))) >> 31)) | (~(((v939 ^ ((int)((unsigned int)((int)((unsigned int)v936 >> 2)) >> 1))) | (-(v939 ^ ((int)((unsigned int)((int)((unsigned int)v936 >> 2)) >> 1))))) >> 31))) == 0);
  int v1035;
  if (v1151) {
    int * v943 = v932->cache_age;
    int v1153 = ((((int)((unsigned int)((int)((unsigned int)v936 >> 2)) >> 1)) & 1) * 2) + ((~(((v939 ^ ((int)((unsigned int)((int)((unsigned int)v936 >> 2)) >> 1))) | (-(v939 ^ ((int)((unsigned int)((int)((unsigned int)v936 >> 2)) >> 1))))) >> 31)) & 1);
    int v944 = v943[v1153];
    int v945 = v943[v1147];
    int v1154 = v945 + ((int)((unsigned int)(v945 - v944) >> 31));
    v943[v1147] = v1154;
    int * v947 = v932->cache_age;
    int v948 = v947[v1148];
    int v1156 = v948 + ((int)((unsigned int)(v948 - v944) >> 31));
    v947[v1148] = v1156;
    int * v950 = v932->cache_age;
    v950[v1153] = 0;
    v1035 = v1153;
  } else {
    int * v953 = v932->cache_age;
    int v1160 = (((int)((unsigned int)((int)((unsigned int)v936 >> 2)) >> 1)) & 1) * 2;
    int v954 = v953[v1160];
    int * v955 = v932->cache_tags;
    int v956 = v955[v1160];
    int v957 = v953[v1148];
    int v958 = v955[v1148];
    bool v1162 = !(((~(((v940 ^ ((int)((unsigned int)((int)((unsigned int)v936 >> 2)) >> 1))) | (-(v940 ^ ((int)((unsigned int)((int)((unsigned int)v936 >> 2)) >> 1))))) >> 31)) | (~(((v941 ^ ((int)((unsigned int)((int)((unsigned int)v936 >> 2)) >> 1))) | (-(v941 ^ ((int)((unsigned int)((int)((unsigned int)v936 >> 2)) >> 1))))) >> 31))) == 0);
    int v1012;
    if (v1162) {
      int * v959 = v932->cache_age;
      int v1164 = (4 + ((((int)((unsigned int)((int)((unsigned int)v936 >> 2)) >> 1)) & 3) * 2)) + ((~(((v941 ^ ((int)((unsigned int)((int)((unsigned int)v936 >> 2)) >> 1))) | (-(v941 ^ ((int)((unsigned int)((int)((unsigned int)v936 >> 2)) >> 1))))) >> 31)) & 1);
      int v960 = v959[v1164];
      int v961 = v959[v1149];
      int v1165 = v961 + ((int)((unsigned int)(v961 - v960) >> 31));
      v959[v1149] = v1165;
      int * v963 = v932->cache_age;
      int v964 = v963[v1150];
      int v1167 = v964 + ((int)((unsigned int)(v964 - v960) >> 31));
      v963[v1150] = v1167;
      int * v966 = v932->cache_age;
      v966[v1164] = 0;
      v1012 = v1164;
    } else {
      int * v969 = v932->cache_age;
      int v1171 = 4 + ((((int)((unsigned int)((int)((unsigned int)v936 >> 2)) >> 1)) & 3) * 2);
      int v970 = v969[v1171];
      int * v971 = v932->cache_tags;
      int v972 = v971[v1171];
      int v973 = v969[v1150];
      int v974 = v971[v1150];
      int * v975 = v932->cache_dirty;
      int v1174 = (4 + ((((int)((unsigned int)((int)((unsigned int)v936 >> 2)) >> 1)) & 3) * 2)) + ((((v970 + ((~(((v972 ^ -1) | (-(v972 ^ -1))) >> 31)) & 2)) - (v973 + ((~(((v974 ^ -1) | (-(v974 ^ -1))) >> 31)) & 2))) >> 31) & 1);
      int v976 = v975[v1174];
      bool v1175 = !(v976 == 0);
      if (v1175) {
        int * v977 = v932->cache_tags;
        int v978 = v977[v1174];
        int * v979 = v932->cache_vals;
        int v1178 = ((4 + ((((int)((unsigned int)((int)((unsigned int)v936 >> 2)) >> 1)) & 3) * 2)) + ((((v970 + ((~(((v972 ^ -1) | (-(v972 ^ -1))) >> 31)) & 2)) - (v973 + ((~(((v974 ^ -1) | (-(v974 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
        int v980 = v979[v1178];
        int v1179 = (((4 + ((((int)((unsigned int)((int)((unsigned int)v936 >> 2)) >> 1)) & 3) * 2)) + ((((v970 + ((~(((v972 ^ -1) | (-(v972 ^ -1))) >> 31)) & 2)) - (v973 + ((~(((v974 ^ -1) | (-(v974 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
        int v981 = v979[v1179];
        int * v982 = v932->mem;
        int v1181 = v978 * 2;
        v982[v1181] = v980;
        int * v984 = v932->mem;
        int v1184 = (v978 * 2) + 1;
        v984[v1184] = v981;
        ;
      } else {
        ;
      }
      int * v989 = v932->mem;
      int v1189 = ((int)((unsigned int)((int)((unsigned int)v936 >> 2)) >> 1)) * 2;
      int v990 = v989[v1189];
      int v1190 = (((int)((unsigned int)((int)((unsigned int)v936 >> 2)) >> 1)) * 2) + 1;
      int v991 = v989[v1190];
      int * v992 = v932->cache_vals;
      int v1192 = ((4 + ((((int)((unsigned int)((int)((unsigned int)v936 >> 2)) >> 1)) & 3) * 2)) + ((((v970 + ((~(((v972 ^ -1) | (-(v972 ^ -1))) >> 31)) & 2)) - (v973 + ((~(((v974 ^ -1) | (-(v974 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
      v992[v1192] = v990;
      int * v994 = v932->cache_vals;
      int v1195 = (((4 + ((((int)((unsigned int)((int)((unsigned int)v936 >> 2)) >> 1)) & 3) * 2)) + ((((v970 + ((~(((v972 ^ -1) | (-(v972 ^ -1))) >> 31)) & 2)) - (v973 + ((~(((v974 ^ -1) | (-(v974 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
      v994[v1195] = v991;
      int * v996 = v932->cache_tags;
      int v1198 = (int)((unsigned int)((int)((unsigned int)v936 >> 2)) >> 1);
      v996[v1174] = v1198;
      int * v998 = v932->cache_dirty;
      v998[v1174] = 0;
      int * v1000 = v932->cache_age;
      v1000[v1174] = 1;
      int * v1002 = v932->cache_age;
      int v1003 = v1002[v1174];
      int v1004 = v1002[v1149];
      int v1204 = v1004 + ((int)((unsigned int)(v1004 - v1003) >> 31));
      v1002[v1149] = v1204;
      int * v1006 = v932->cache_age;
      int v1007 = v1006[v1150];
      int v1206 = v1007 + ((int)((unsigned int)(v1007 - v1003) >> 31));
      v1006[v1150] = v1206;
      int * v1009 = v932->cache_age;
      v1009[v1174] = 0;
      v1012 = v1174;
    }
    int * v1013 = v932->cache_vals;
    int v1209 = v1012 * 2;
    int v1014 = v1013[v1209];
    int v1210 = (v1012 * 2) + 1;
    int v1015 = v1013[v1210];
    int v1211 = (((((int)((unsigned int)((int)((unsigned int)v936 >> 2)) >> 1)) & 1) * 2) + ((((v954 + ((~(((v956 ^ -1) | (-(v956 ^ -1))) >> 31)) & 2)) - (v957 + ((~(((v958 ^ -1) | (-(v958 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
    v1013[v1211] = v1014;
    int * v1017 = v932->cache_vals;
    int v1214 = ((((((int)((unsigned int)((int)((unsigned int)v936 >> 2)) >> 1)) & 1) * 2) + ((((v954 + ((~(((v956 ^ -1) | (-(v956 ^ -1))) >> 31)) & 2)) - (v957 + ((~(((v958 ^ -1) | (-(v958 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
    v1017[v1214] = v1015;
    int * v1019 = v932->cache_tags;
    int v1217 = ((((int)((unsigned int)((int)((unsigned int)v936 >> 2)) >> 1)) & 1) * 2) + ((((v954 + ((~(((v956 ^ -1) | (-(v956 ^ -1))) >> 31)) & 2)) - (v957 + ((~(((v958 ^ -1) | (-(v958 ^ -1))) >> 31)) & 2))) >> 31) & 1);
    int v1218 = (int)((unsigned int)((int)((unsigned int)v936 >> 2)) >> 1);
    v1019[v1217] = v1218;
    int * v1021 = v932->cache_dirty;
    v1021[v1217] = 0;
    int * v1023 = v932->cache_age;
    v1023[v1217] = 1;
    int * v1025 = v932->cache_age;
    int v1026 = v1025[v1217];
    int v1027 = v1025[v1147];
    int v1224 = v1027 + ((int)((unsigned int)(v1027 - v1026) >> 31));
    v1025[v1147] = v1224;
    int * v1029 = v932->cache_age;
    int v1030 = v1029[v1148];
    int v1226 = v1030 + ((int)((unsigned int)(v1030 - v1026) >> 31));
    v1029[v1148] = v1226;
    int * v1032 = v932->cache_age;
    v1032[v1217] = 0;
    v1035 = v1217;
  }
  int v1229 = (v1035 * 2) + (((int)((unsigned int)v936 >> 2)) & 1);
  int v1036 = v942[v1229];
  int * v1037 = v932->reg_ready;
  int v1231 = ((v934 + ((v821 - v934) & (~((v821 - v934) >> 31)))) + 1) + ((100 ^ (((~(((v940 ^ ((int)((unsigned int)((int)((unsigned int)v936 >> 2)) >> 1))) | (-(v940 ^ ((int)((unsigned int)((int)((unsigned int)v936 >> 2)) >> 1))))) >> 31)) | (~(((v941 ^ ((int)((unsigned int)((int)((unsigned int)v936 >> 2)) >> 1))) | (-(v941 ^ ((int)((unsigned int)((int)((unsigned int)v936 >> 2)) >> 1))))) >> 31))) & 104)) ^ (((~(((v938 ^ ((int)((unsigned int)((int)((unsigned int)v936 >> 2)) >> 1))) | (-(v938 ^ ((int)((unsigned int)((int)((unsigned int)v936 >> 2)) >> 1))))) >> 31)) | (~(((v939 ^ ((int)((unsigned int)((int)((unsigned int)v936 >> 2)) >> 1))) | (-(v939 ^ ((int)((unsigned int)((int)((unsigned int)v936 >> 2)) >> 1))))) >> 31))) & (1 ^ (100 ^ (((~(((v940 ^ ((int)((unsigned int)((int)((unsigned int)v936 >> 2)) >> 1))) | (-(v940 ^ ((int)((unsigned int)((int)((unsigned int)v936 >> 2)) >> 1))))) >> 31)) | (~(((v941 ^ ((int)((unsigned int)((int)((unsigned int)v936 >> 2)) >> 1))) | (-(v941 ^ ((int)((unsigned int)((int)((unsigned int)v936 >> 2)) >> 1))))) >> 31))) & 104)))));
  v1037[11] = v1231;
  int * v1039 = v932->regs;
  v1039[11] = v1036;
  struct StateT2 * v1041 = slot_9(v810);
  return v1041;
}

struct StateT2 * slot_4(struct StateT2 * v170) {
  struct StateT * v171 = v170->a;
  int v172 = v171->timer;
  struct StateT * v173 = v170->b;
  int v174 = v173->timer;
  bool v207 = v172 == v174;
  squared_assert(v207);
  squared_assume(v207);
  struct StateT * v177 = v170->a;
  int v178 = v177->timer;
  int v209 = v178 + 1;
  v177->timer = v209;
  struct StateT * v180 = v170->b;
  int v181 = v180->timer;
  int v211 = v181 + 1;
  v180->timer = v211;
  struct StateT * v183 = v170->a;
  int * v184 = v183->reg_ready;
  int * v186 = v183->regs;
  int v187 = v186[14];
  int v189 = v186[15];
  struct StateT * v190 = v170->b;
  int * v191 = v190->reg_ready;
  int * v193 = v190->regs;
  int v194 = v193[14];
  int v196 = v193[15];
  bool v220 = (v187 >= v189) == (v194 >= v196);
  squared_diverged(v220);
  squared_assume(v220);
  bool v221 = v187 >= v189;
  struct StateT2 * v203;
  if (v221) {
    struct StateT2 * v199 = slot_14(v170);
    v203 = v199;
  } else {
    struct StateT2 * v201 = slot_5(v170);
    v203 = v201;
  }
  return v203;
}

struct StateT2 * slot_13(struct StateT2 * v1388) {
  struct StateT * v1389 = v1388->a;
  int v1390 = v1389->timer;
  struct StateT * v1391 = v1388->b;
  int v1392 = v1391->timer;
  bool v1406 = v1390 == v1392;
  squared_assert(v1406);
  squared_assume(v1406);
  struct StateT * v1395 = v1388->a;
  int v1396 = v1395->timer;
  int v1408 = v1396 + 1;
  v1395->timer = v1408;
  struct StateT * v1398 = v1388->b;
  int v1399 = v1398->timer;
  int v1410 = v1399 + 1;
  v1398->timer = v1410;
  return v1388;
}

struct StateT2 * slot_9(struct StateT2 * v1236) {
  struct StateT * v1237 = v1236->a;
  int v1238 = v1237->timer;
  struct StateT * v1239 = v1236->b;
  int v1240 = v1239->timer;
  bool v1273 = v1238 == v1240;
  squared_assert(v1273);
  squared_assume(v1273);
  struct StateT * v1243 = v1236->a;
  int v1244 = v1243->timer;
  int v1275 = v1244 + 1;
  v1243->timer = v1275;
  struct StateT * v1246 = v1236->b;
  int v1247 = v1246->timer;
  int v1277 = v1247 + 1;
  v1246->timer = v1277;
  struct StateT * v1249 = v1236->a;
  int * v1250 = v1249->reg_ready;
  int * v1252 = v1249->regs;
  int v1253 = v1252[10];
  int v1255 = v1252[11];
  struct StateT * v1256 = v1236->b;
  int * v1257 = v1256->reg_ready;
  int * v1259 = v1256->regs;
  int v1260 = v1259[10];
  int v1262 = v1259[11];
  bool v1286 = (!(v1253 == v1255)) == (!(v1260 == v1262));
  squared_diverged(v1286);
  squared_assume(v1286);
  bool v1287 = !(v1253 == v1255);
  struct StateT2 * v1269;
  if (v1287) {
    struct StateT2 * v1265 = slot_12(v1236);
    v1269 = v1265;
  } else {
    struct StateT2 * v1267 = slot_10(v1236);
    v1269 = v1267;
  }
  return v1269;
}

struct StateT2 * slot_11(struct StateT2 * v1411) {
  struct StateT * v1412 = v1411->a;
  int v1413 = v1412->timer;
  struct StateT * v1414 = v1411->b;
  int v1415 = v1414->timer;
  bool v1430 = v1413 == v1415;
  squared_assert(v1430);
  squared_assume(v1430);
  struct StateT * v1418 = v1411->a;
  int v1419 = v1418->timer;
  int v1432 = v1419 + 1;
  v1418->timer = v1432;
  struct StateT * v1421 = v1411->b;
  int v1422 = v1421->timer;
  int v1434 = v1422 + 1;
  v1421->timer = v1434;
  struct StateT2 * v1426 = slot_4(v1411);
  return v1426;
}

struct StateT2 * slot_0(struct StateT2 * v2) {
  struct StateT * v3 = v2->a;
  int v4 = v3->timer;
  struct StateT * v5 = v2->b;
  int v6 = v5->timer;
  bool v29 = v4 == v6;
  squared_assert(v29);
  squared_assume(v29);
  struct StateT * v9 = v2->a;
  int v10 = v9->timer;
  int v31 = v10 + 1;
  v9->timer = v31;
  struct StateT * v12 = v2->b;
  int v13 = v12->timer;
  int v33 = v13 + 1;
  v12->timer = v33;
  struct StateT * v15 = v2->a;
  int * v16 = v15->reg_ready;
  v16[12] = v31;
  int * v18 = v15->regs;
  v18[12] = 0;
  struct StateT * v20 = v2->b;
  int * v21 = v20->reg_ready;
  v21[12] = v33;
  int * v23 = v20->regs;
  v23[12] = 0;
  struct StateT2 * v25 = slot_1(v2);
  return v25;
}



/*****************************************
End of C Generated Code
*******************************************/

void init(struct StateT *s) {
  for (int i=0; i<NUM_REGS; i++) {
    s->regs[i] = 0;
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