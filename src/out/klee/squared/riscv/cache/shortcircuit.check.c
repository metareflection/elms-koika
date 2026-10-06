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

struct StateT2 * slot_12(struct StateT2 * v1199);
struct StateT2 * slot_14(struct StateT2 * v195);
struct StateT2 * slot_6(struct StateT2 * v271);
struct StateT2 * slot_5(struct StateT2 * v228);
struct StateT2 * slot_2(struct StateT2 * v74);
struct StateT2 * slot_7(struct StateT2 * v689);
struct StateT2 * slot_3(struct StateT2 * v110);
struct StateT2 * snippet(struct StateT2 * v0);
struct StateT2 * slot_10(struct StateT2 * v1235);
struct StateT2 * slot_1(struct StateT2 * v38);
struct StateT2 * slot_8(struct StateT2 * v732);
struct StateT2 * slot_4(struct StateT2 * v146);
struct StateT2 * slot_13(struct StateT2 * v1274);
struct StateT2 * slot_9(struct StateT2 * v1150);
struct StateT2 * slot_11(struct StateT2 * v1297);
struct StateT2 * slot_0(struct StateT2 * v2);
struct StateT2 * slot_12(struct StateT2 * v1199) {
  struct StateT * v1200 = v1199->a;
  int v1201 = v1200->timer;
  struct StateT * v1202 = v1199->b;
  int v1203 = v1202->timer;
  bool v1222 = v1201 == v1203;
  squared_assert(v1222);
  squared_assume(v1222);
  struct StateT * v1206 = v1199->a;
  int v1207 = v1206->timer;
  int v1224 = v1207 + 1;
  v1206->timer = v1224;
  struct StateT * v1209 = v1199->b;
  int v1210 = v1209->timer;
  int v1226 = v1210 + 1;
  v1209->timer = v1226;
  struct StateT * v1212 = v1199->a;
  int * v1213 = v1212->regs;
  v1213[10] = 0;
  struct StateT * v1215 = v1199->b;
  int * v1216 = v1215->regs;
  v1216[10] = 0;
  struct StateT2 * v1218 = slot_13(v1199);
  return v1218;
}

struct StateT2 * slot_14(struct StateT2 * v195) {
  struct StateT * v196 = v195->a;
  int v197 = v196->timer;
  struct StateT * v198 = v195->b;
  int v199 = v198->timer;
  bool v217 = v197 == v199;
  squared_assert(v217);
  squared_assume(v217);
  struct StateT * v202 = v195->a;
  int v203 = v202->timer;
  int v219 = v203 + 1;
  v202->timer = v219;
  struct StateT * v205 = v195->b;
  int v206 = v205->timer;
  int v221 = v206 + 1;
  v205->timer = v221;
  struct StateT * v208 = v195->a;
  int * v209 = v208->regs;
  v209[10] = 1;
  struct StateT * v211 = v195->b;
  int * v212 = v211->regs;
  v212[10] = 1;
  return v195;
}

struct StateT2 * slot_6(struct StateT2 * v271) {
  struct StateT * v272 = v271->a;
  int v273 = v272->timer;
  struct StateT * v274 = v271->b;
  int v275 = v274->timer;
  bool v502 = v273 == v275;
  squared_assert(v502);
  squared_assume(v502);
  struct StateT * v278 = v271->a;
  int v279 = v278->timer;
  int v504 = v279 + 1;
  v278->timer = v504;
  struct StateT * v281 = v271->b;
  int v282 = v281->timer;
  int v506 = v282 + 1;
  v281->timer = v506;
  struct StateT * v284 = v271->a;
  int * v285 = v284->regs;
  int v286 = v285[5];
  int * v287 = v284->cache_tags;
  int v511 = (((int)((unsigned int)((int)((unsigned int)v286 >> 2)) >> 1)) & 1) * 2;
  int v288 = v287[v511];
  int v512 = ((((int)((unsigned int)((int)((unsigned int)v286 >> 2)) >> 1)) & 1) * 2) + 1;
  int v289 = v287[v512];
  int v513 = 4 + ((((int)((unsigned int)((int)((unsigned int)v286 >> 2)) >> 1)) & 3) * 2);
  int v290 = v287[v513];
  int v514 = (4 + ((((int)((unsigned int)((int)((unsigned int)v286 >> 2)) >> 1)) & 3) * 2)) + 1;
  int v291 = v287[v514];
  int v292 = v284->timer;
  int v515 = v292 + ((100 ^ (((~(((v290 ^ ((int)((unsigned int)((int)((unsigned int)v286 >> 2)) >> 1))) | (-(v290 ^ ((int)((unsigned int)((int)((unsigned int)v286 >> 2)) >> 1))))) >> 31)) | (~(((v291 ^ ((int)((unsigned int)((int)((unsigned int)v286 >> 2)) >> 1))) | (-(v291 ^ ((int)((unsigned int)((int)((unsigned int)v286 >> 2)) >> 1))))) >> 31))) & 104)) ^ (((~(((v288 ^ ((int)((unsigned int)((int)((unsigned int)v286 >> 2)) >> 1))) | (-(v288 ^ ((int)((unsigned int)((int)((unsigned int)v286 >> 2)) >> 1))))) >> 31)) | (~(((v289 ^ ((int)((unsigned int)((int)((unsigned int)v286 >> 2)) >> 1))) | (-(v289 ^ ((int)((unsigned int)((int)((unsigned int)v286 >> 2)) >> 1))))) >> 31))) & (1 ^ (100 ^ (((~(((v290 ^ ((int)((unsigned int)((int)((unsigned int)v286 >> 2)) >> 1))) | (-(v290 ^ ((int)((unsigned int)((int)((unsigned int)v286 >> 2)) >> 1))))) >> 31)) | (~(((v291 ^ ((int)((unsigned int)((int)((unsigned int)v286 >> 2)) >> 1))) | (-(v291 ^ ((int)((unsigned int)((int)((unsigned int)v286 >> 2)) >> 1))))) >> 31))) & 104)))));
  v284->timer = v515;
  int * v294 = v284->cache_vals;
  bool v516 = !(((~(((v288 ^ ((int)((unsigned int)((int)((unsigned int)v286 >> 2)) >> 1))) | (-(v288 ^ ((int)((unsigned int)((int)((unsigned int)v286 >> 2)) >> 1))))) >> 31)) | (~(((v289 ^ ((int)((unsigned int)((int)((unsigned int)v286 >> 2)) >> 1))) | (-(v289 ^ ((int)((unsigned int)((int)((unsigned int)v286 >> 2)) >> 1))))) >> 31))) == 0);
  int v387;
  if (v516) {
    int * v295 = v284->cache_age;
    int v518 = ((((int)((unsigned int)((int)((unsigned int)v286 >> 2)) >> 1)) & 1) * 2) + ((~(((v289 ^ ((int)((unsigned int)((int)((unsigned int)v286 >> 2)) >> 1))) | (-(v289 ^ ((int)((unsigned int)((int)((unsigned int)v286 >> 2)) >> 1))))) >> 31)) & 1);
    int v296 = v295[v518];
    int v297 = v295[v511];
    int v519 = v297 + ((int)((unsigned int)(v297 - v296) >> 31));
    v295[v511] = v519;
    int * v299 = v284->cache_age;
    int v300 = v299[v512];
    int v521 = v300 + ((int)((unsigned int)(v300 - v296) >> 31));
    v299[v512] = v521;
    int * v302 = v284->cache_age;
    v302[v518] = 0;
    v387 = v518;
  } else {
    int * v305 = v284->cache_age;
    int v525 = (((int)((unsigned int)((int)((unsigned int)v286 >> 2)) >> 1)) & 1) * 2;
    int v306 = v305[v525];
    int * v307 = v284->cache_tags;
    int v308 = v307[v525];
    int v309 = v305[v512];
    int v310 = v307[v512];
    bool v527 = !(((~(((v290 ^ ((int)((unsigned int)((int)((unsigned int)v286 >> 2)) >> 1))) | (-(v290 ^ ((int)((unsigned int)((int)((unsigned int)v286 >> 2)) >> 1))))) >> 31)) | (~(((v291 ^ ((int)((unsigned int)((int)((unsigned int)v286 >> 2)) >> 1))) | (-(v291 ^ ((int)((unsigned int)((int)((unsigned int)v286 >> 2)) >> 1))))) >> 31))) == 0);
    int v364;
    if (v527) {
      int * v311 = v284->cache_age;
      int v529 = (4 + ((((int)((unsigned int)((int)((unsigned int)v286 >> 2)) >> 1)) & 3) * 2)) + ((~(((v291 ^ ((int)((unsigned int)((int)((unsigned int)v286 >> 2)) >> 1))) | (-(v291 ^ ((int)((unsigned int)((int)((unsigned int)v286 >> 2)) >> 1))))) >> 31)) & 1);
      int v312 = v311[v529];
      int v313 = v311[v513];
      int v530 = v313 + ((int)((unsigned int)(v313 - v312) >> 31));
      v311[v513] = v530;
      int * v315 = v284->cache_age;
      int v316 = v315[v514];
      int v532 = v316 + ((int)((unsigned int)(v316 - v312) >> 31));
      v315[v514] = v532;
      int * v318 = v284->cache_age;
      v318[v529] = 0;
      v364 = v529;
    } else {
      int * v321 = v284->cache_age;
      int v536 = 4 + ((((int)((unsigned int)((int)((unsigned int)v286 >> 2)) >> 1)) & 3) * 2);
      int v322 = v321[v536];
      int * v323 = v284->cache_tags;
      int v324 = v323[v536];
      int v325 = v321[v514];
      int v326 = v323[v514];
      int * v327 = v284->cache_dirty;
      int v539 = (4 + ((((int)((unsigned int)((int)((unsigned int)v286 >> 2)) >> 1)) & 3) * 2)) + ((((v322 + ((~(((v324 ^ -1) | (-(v324 ^ -1))) >> 31)) & 2)) - (v325 + ((~(((v326 ^ -1) | (-(v326 ^ -1))) >> 31)) & 2))) >> 31) & 1);
      int v328 = v327[v539];
      bool v540 = !(v328 == 0);
      if (v540) {
        int * v329 = v284->cache_tags;
        int v330 = v329[v539];
        int * v331 = v284->cache_vals;
        int v543 = ((4 + ((((int)((unsigned int)((int)((unsigned int)v286 >> 2)) >> 1)) & 3) * 2)) + ((((v322 + ((~(((v324 ^ -1) | (-(v324 ^ -1))) >> 31)) & 2)) - (v325 + ((~(((v326 ^ -1) | (-(v326 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
        int v332 = v331[v543];
        int v544 = (((4 + ((((int)((unsigned int)((int)((unsigned int)v286 >> 2)) >> 1)) & 3) * 2)) + ((((v322 + ((~(((v324 ^ -1) | (-(v324 ^ -1))) >> 31)) & 2)) - (v325 + ((~(((v326 ^ -1) | (-(v326 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
        int v333 = v331[v544];
        int * v334 = v284->mem;
        int v546 = v330 * 2;
        v334[v546] = v332;
        int * v336 = v284->mem;
        int v549 = (v330 * 2) + 1;
        v336[v549] = v333;
        ;
      } else {
        ;
      }
      int * v341 = v284->mem;
      int v554 = ((int)((unsigned int)((int)((unsigned int)v286 >> 2)) >> 1)) * 2;
      int v342 = v341[v554];
      int v555 = (((int)((unsigned int)((int)((unsigned int)v286 >> 2)) >> 1)) * 2) + 1;
      int v343 = v341[v555];
      int * v344 = v284->cache_vals;
      int v557 = ((4 + ((((int)((unsigned int)((int)((unsigned int)v286 >> 2)) >> 1)) & 3) * 2)) + ((((v322 + ((~(((v324 ^ -1) | (-(v324 ^ -1))) >> 31)) & 2)) - (v325 + ((~(((v326 ^ -1) | (-(v326 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
      v344[v557] = v342;
      int * v346 = v284->cache_vals;
      int v560 = (((4 + ((((int)((unsigned int)((int)((unsigned int)v286 >> 2)) >> 1)) & 3) * 2)) + ((((v322 + ((~(((v324 ^ -1) | (-(v324 ^ -1))) >> 31)) & 2)) - (v325 + ((~(((v326 ^ -1) | (-(v326 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
      v346[v560] = v343;
      int * v348 = v284->cache_tags;
      int v563 = (int)((unsigned int)((int)((unsigned int)v286 >> 2)) >> 1);
      v348[v539] = v563;
      int * v350 = v284->cache_dirty;
      v350[v539] = 0;
      int * v352 = v284->cache_age;
      v352[v539] = 1;
      int * v354 = v284->cache_age;
      int v355 = v354[v539];
      int v356 = v354[v513];
      int v569 = v356 + ((int)((unsigned int)(v356 - v355) >> 31));
      v354[v513] = v569;
      int * v358 = v284->cache_age;
      int v359 = v358[v514];
      int v571 = v359 + ((int)((unsigned int)(v359 - v355) >> 31));
      v358[v514] = v571;
      int * v361 = v284->cache_age;
      v361[v539] = 0;
      v364 = v539;
    }
    int * v365 = v284->cache_vals;
    int v574 = v364 * 2;
    int v366 = v365[v574];
    int v575 = (v364 * 2) + 1;
    int v367 = v365[v575];
    int v576 = (((((int)((unsigned int)((int)((unsigned int)v286 >> 2)) >> 1)) & 1) * 2) + ((((v306 + ((~(((v308 ^ -1) | (-(v308 ^ -1))) >> 31)) & 2)) - (v309 + ((~(((v310 ^ -1) | (-(v310 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
    v365[v576] = v366;
    int * v369 = v284->cache_vals;
    int v579 = ((((((int)((unsigned int)((int)((unsigned int)v286 >> 2)) >> 1)) & 1) * 2) + ((((v306 + ((~(((v308 ^ -1) | (-(v308 ^ -1))) >> 31)) & 2)) - (v309 + ((~(((v310 ^ -1) | (-(v310 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
    v369[v579] = v367;
    int * v371 = v284->cache_tags;
    int v582 = ((((int)((unsigned int)((int)((unsigned int)v286 >> 2)) >> 1)) & 1) * 2) + ((((v306 + ((~(((v308 ^ -1) | (-(v308 ^ -1))) >> 31)) & 2)) - (v309 + ((~(((v310 ^ -1) | (-(v310 ^ -1))) >> 31)) & 2))) >> 31) & 1);
    int v583 = (int)((unsigned int)((int)((unsigned int)v286 >> 2)) >> 1);
    v371[v582] = v583;
    int * v373 = v284->cache_dirty;
    v373[v582] = 0;
    int * v375 = v284->cache_age;
    v375[v582] = 1;
    int * v377 = v284->cache_age;
    int v378 = v377[v582];
    int v379 = v377[v511];
    int v589 = v379 + ((int)((unsigned int)(v379 - v378) >> 31));
    v377[v511] = v589;
    int * v381 = v284->cache_age;
    int v382 = v381[v512];
    int v591 = v382 + ((int)((unsigned int)(v382 - v378) >> 31));
    v381[v512] = v591;
    int * v384 = v284->cache_age;
    v384[v582] = 0;
    v387 = v582;
  }
  int v594 = (v387 * 2) + (((int)((unsigned int)v286 >> 2)) & 1);
  int v388 = v294[v594];
  int * v389 = v284->regs;
  v389[10] = v388;
  struct StateT * v391 = v271->b;
  int * v392 = v391->regs;
  int v393 = v392[5];
  int * v394 = v391->cache_tags;
  int v601 = (((int)((unsigned int)((int)((unsigned int)v393 >> 2)) >> 1)) & 1) * 2;
  int v395 = v394[v601];
  int v602 = ((((int)((unsigned int)((int)((unsigned int)v393 >> 2)) >> 1)) & 1) * 2) + 1;
  int v396 = v394[v602];
  int v603 = 4 + ((((int)((unsigned int)((int)((unsigned int)v393 >> 2)) >> 1)) & 3) * 2);
  int v397 = v394[v603];
  int v604 = (4 + ((((int)((unsigned int)((int)((unsigned int)v393 >> 2)) >> 1)) & 3) * 2)) + 1;
  int v398 = v394[v604];
  int v399 = v391->timer;
  int v605 = v399 + ((100 ^ (((~(((v397 ^ ((int)((unsigned int)((int)((unsigned int)v393 >> 2)) >> 1))) | (-(v397 ^ ((int)((unsigned int)((int)((unsigned int)v393 >> 2)) >> 1))))) >> 31)) | (~(((v398 ^ ((int)((unsigned int)((int)((unsigned int)v393 >> 2)) >> 1))) | (-(v398 ^ ((int)((unsigned int)((int)((unsigned int)v393 >> 2)) >> 1))))) >> 31))) & 104)) ^ (((~(((v395 ^ ((int)((unsigned int)((int)((unsigned int)v393 >> 2)) >> 1))) | (-(v395 ^ ((int)((unsigned int)((int)((unsigned int)v393 >> 2)) >> 1))))) >> 31)) | (~(((v396 ^ ((int)((unsigned int)((int)((unsigned int)v393 >> 2)) >> 1))) | (-(v396 ^ ((int)((unsigned int)((int)((unsigned int)v393 >> 2)) >> 1))))) >> 31))) & (1 ^ (100 ^ (((~(((v397 ^ ((int)((unsigned int)((int)((unsigned int)v393 >> 2)) >> 1))) | (-(v397 ^ ((int)((unsigned int)((int)((unsigned int)v393 >> 2)) >> 1))))) >> 31)) | (~(((v398 ^ ((int)((unsigned int)((int)((unsigned int)v393 >> 2)) >> 1))) | (-(v398 ^ ((int)((unsigned int)((int)((unsigned int)v393 >> 2)) >> 1))))) >> 31))) & 104)))));
  v391->timer = v605;
  int * v401 = v391->cache_vals;
  bool v606 = !(((~(((v395 ^ ((int)((unsigned int)((int)((unsigned int)v393 >> 2)) >> 1))) | (-(v395 ^ ((int)((unsigned int)((int)((unsigned int)v393 >> 2)) >> 1))))) >> 31)) | (~(((v396 ^ ((int)((unsigned int)((int)((unsigned int)v393 >> 2)) >> 1))) | (-(v396 ^ ((int)((unsigned int)((int)((unsigned int)v393 >> 2)) >> 1))))) >> 31))) == 0);
  int v494;
  if (v606) {
    int * v402 = v391->cache_age;
    int v608 = ((((int)((unsigned int)((int)((unsigned int)v393 >> 2)) >> 1)) & 1) * 2) + ((~(((v396 ^ ((int)((unsigned int)((int)((unsigned int)v393 >> 2)) >> 1))) | (-(v396 ^ ((int)((unsigned int)((int)((unsigned int)v393 >> 2)) >> 1))))) >> 31)) & 1);
    int v403 = v402[v608];
    int v404 = v402[v601];
    int v609 = v404 + ((int)((unsigned int)(v404 - v403) >> 31));
    v402[v601] = v609;
    int * v406 = v391->cache_age;
    int v407 = v406[v602];
    int v611 = v407 + ((int)((unsigned int)(v407 - v403) >> 31));
    v406[v602] = v611;
    int * v409 = v391->cache_age;
    v409[v608] = 0;
    v494 = v608;
  } else {
    int * v412 = v391->cache_age;
    int v615 = (((int)((unsigned int)((int)((unsigned int)v393 >> 2)) >> 1)) & 1) * 2;
    int v413 = v412[v615];
    int * v414 = v391->cache_tags;
    int v415 = v414[v615];
    int v416 = v412[v602];
    int v417 = v414[v602];
    bool v617 = !(((~(((v397 ^ ((int)((unsigned int)((int)((unsigned int)v393 >> 2)) >> 1))) | (-(v397 ^ ((int)((unsigned int)((int)((unsigned int)v393 >> 2)) >> 1))))) >> 31)) | (~(((v398 ^ ((int)((unsigned int)((int)((unsigned int)v393 >> 2)) >> 1))) | (-(v398 ^ ((int)((unsigned int)((int)((unsigned int)v393 >> 2)) >> 1))))) >> 31))) == 0);
    int v471;
    if (v617) {
      int * v418 = v391->cache_age;
      int v619 = (4 + ((((int)((unsigned int)((int)((unsigned int)v393 >> 2)) >> 1)) & 3) * 2)) + ((~(((v398 ^ ((int)((unsigned int)((int)((unsigned int)v393 >> 2)) >> 1))) | (-(v398 ^ ((int)((unsigned int)((int)((unsigned int)v393 >> 2)) >> 1))))) >> 31)) & 1);
      int v419 = v418[v619];
      int v420 = v418[v603];
      int v620 = v420 + ((int)((unsigned int)(v420 - v419) >> 31));
      v418[v603] = v620;
      int * v422 = v391->cache_age;
      int v423 = v422[v604];
      int v622 = v423 + ((int)((unsigned int)(v423 - v419) >> 31));
      v422[v604] = v622;
      int * v425 = v391->cache_age;
      v425[v619] = 0;
      v471 = v619;
    } else {
      int * v428 = v391->cache_age;
      int v626 = 4 + ((((int)((unsigned int)((int)((unsigned int)v393 >> 2)) >> 1)) & 3) * 2);
      int v429 = v428[v626];
      int * v430 = v391->cache_tags;
      int v431 = v430[v626];
      int v432 = v428[v604];
      int v433 = v430[v604];
      int * v434 = v391->cache_dirty;
      int v629 = (4 + ((((int)((unsigned int)((int)((unsigned int)v393 >> 2)) >> 1)) & 3) * 2)) + ((((v429 + ((~(((v431 ^ -1) | (-(v431 ^ -1))) >> 31)) & 2)) - (v432 + ((~(((v433 ^ -1) | (-(v433 ^ -1))) >> 31)) & 2))) >> 31) & 1);
      int v435 = v434[v629];
      bool v630 = !(v435 == 0);
      if (v630) {
        int * v436 = v391->cache_tags;
        int v437 = v436[v629];
        int * v438 = v391->cache_vals;
        int v633 = ((4 + ((((int)((unsigned int)((int)((unsigned int)v393 >> 2)) >> 1)) & 3) * 2)) + ((((v429 + ((~(((v431 ^ -1) | (-(v431 ^ -1))) >> 31)) & 2)) - (v432 + ((~(((v433 ^ -1) | (-(v433 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
        int v439 = v438[v633];
        int v634 = (((4 + ((((int)((unsigned int)((int)((unsigned int)v393 >> 2)) >> 1)) & 3) * 2)) + ((((v429 + ((~(((v431 ^ -1) | (-(v431 ^ -1))) >> 31)) & 2)) - (v432 + ((~(((v433 ^ -1) | (-(v433 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
        int v440 = v438[v634];
        int * v441 = v391->mem;
        int v636 = v437 * 2;
        v441[v636] = v439;
        int * v443 = v391->mem;
        int v639 = (v437 * 2) + 1;
        v443[v639] = v440;
        ;
      } else {
        ;
      }
      int * v448 = v391->mem;
      int v644 = ((int)((unsigned int)((int)((unsigned int)v393 >> 2)) >> 1)) * 2;
      int v449 = v448[v644];
      int v645 = (((int)((unsigned int)((int)((unsigned int)v393 >> 2)) >> 1)) * 2) + 1;
      int v450 = v448[v645];
      int * v451 = v391->cache_vals;
      int v647 = ((4 + ((((int)((unsigned int)((int)((unsigned int)v393 >> 2)) >> 1)) & 3) * 2)) + ((((v429 + ((~(((v431 ^ -1) | (-(v431 ^ -1))) >> 31)) & 2)) - (v432 + ((~(((v433 ^ -1) | (-(v433 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
      v451[v647] = v449;
      int * v453 = v391->cache_vals;
      int v650 = (((4 + ((((int)((unsigned int)((int)((unsigned int)v393 >> 2)) >> 1)) & 3) * 2)) + ((((v429 + ((~(((v431 ^ -1) | (-(v431 ^ -1))) >> 31)) & 2)) - (v432 + ((~(((v433 ^ -1) | (-(v433 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
      v453[v650] = v450;
      int * v455 = v391->cache_tags;
      int v653 = (int)((unsigned int)((int)((unsigned int)v393 >> 2)) >> 1);
      v455[v629] = v653;
      int * v457 = v391->cache_dirty;
      v457[v629] = 0;
      int * v459 = v391->cache_age;
      v459[v629] = 1;
      int * v461 = v391->cache_age;
      int v462 = v461[v629];
      int v463 = v461[v603];
      int v659 = v463 + ((int)((unsigned int)(v463 - v462) >> 31));
      v461[v603] = v659;
      int * v465 = v391->cache_age;
      int v466 = v465[v604];
      int v661 = v466 + ((int)((unsigned int)(v466 - v462) >> 31));
      v465[v604] = v661;
      int * v468 = v391->cache_age;
      v468[v629] = 0;
      v471 = v629;
    }
    int * v472 = v391->cache_vals;
    int v664 = v471 * 2;
    int v473 = v472[v664];
    int v665 = (v471 * 2) + 1;
    int v474 = v472[v665];
    int v666 = (((((int)((unsigned int)((int)((unsigned int)v393 >> 2)) >> 1)) & 1) * 2) + ((((v413 + ((~(((v415 ^ -1) | (-(v415 ^ -1))) >> 31)) & 2)) - (v416 + ((~(((v417 ^ -1) | (-(v417 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
    v472[v666] = v473;
    int * v476 = v391->cache_vals;
    int v669 = ((((((int)((unsigned int)((int)((unsigned int)v393 >> 2)) >> 1)) & 1) * 2) + ((((v413 + ((~(((v415 ^ -1) | (-(v415 ^ -1))) >> 31)) & 2)) - (v416 + ((~(((v417 ^ -1) | (-(v417 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
    v476[v669] = v474;
    int * v478 = v391->cache_tags;
    int v672 = ((((int)((unsigned int)((int)((unsigned int)v393 >> 2)) >> 1)) & 1) * 2) + ((((v413 + ((~(((v415 ^ -1) | (-(v415 ^ -1))) >> 31)) & 2)) - (v416 + ((~(((v417 ^ -1) | (-(v417 ^ -1))) >> 31)) & 2))) >> 31) & 1);
    int v673 = (int)((unsigned int)((int)((unsigned int)v393 >> 2)) >> 1);
    v478[v672] = v673;
    int * v480 = v391->cache_dirty;
    v480[v672] = 0;
    int * v482 = v391->cache_age;
    v482[v672] = 1;
    int * v484 = v391->cache_age;
    int v485 = v484[v672];
    int v486 = v484[v601];
    int v679 = v486 + ((int)((unsigned int)(v486 - v485) >> 31));
    v484[v601] = v679;
    int * v488 = v391->cache_age;
    int v489 = v488[v602];
    int v681 = v489 + ((int)((unsigned int)(v489 - v485) >> 31));
    v488[v602] = v681;
    int * v491 = v391->cache_age;
    v491[v672] = 0;
    v494 = v672;
  }
  int v684 = (v494 * 2) + (((int)((unsigned int)v393 >> 2)) & 1);
  int v495 = v401[v684];
  int * v496 = v391->regs;
  v496[10] = v495;
  struct StateT2 * v498 = slot_7(v271);
  return v498;
}

struct StateT2 * slot_5(struct StateT2 * v228) {
  struct StateT * v229 = v228->a;
  int v230 = v229->timer;
  struct StateT * v231 = v228->b;
  int v232 = v231->timer;
  bool v255 = v230 == v232;
  squared_assert(v255);
  squared_assume(v255);
  struct StateT * v235 = v228->a;
  int v236 = v235->timer;
  int v257 = v236 + 1;
  v235->timer = v257;
  struct StateT * v238 = v228->b;
  int v239 = v238->timer;
  int v259 = v239 + 1;
  v238->timer = v259;
  struct StateT * v241 = v228->a;
  int * v242 = v241->regs;
  int v243 = v242[12];
  int v244 = v242[14];
  int v265 = v243 + v244;
  v242[5] = v265;
  struct StateT * v246 = v228->b;
  int * v247 = v246->regs;
  int v248 = v247[12];
  int v249 = v247[14];
  int v268 = v248 + v249;
  v247[5] = v268;
  struct StateT2 * v251 = slot_6(v228);
  return v251;
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

struct StateT2 * slot_7(struct StateT2 * v689) {
  struct StateT * v690 = v689->a;
  int v691 = v690->timer;
  struct StateT * v692 = v689->b;
  int v693 = v692->timer;
  bool v716 = v691 == v693;
  squared_assert(v716);
  squared_assume(v716);
  struct StateT * v696 = v689->a;
  int v697 = v696->timer;
  int v718 = v697 + 1;
  v696->timer = v718;
  struct StateT * v699 = v689->b;
  int v700 = v699->timer;
  int v720 = v700 + 1;
  v699->timer = v720;
  struct StateT * v702 = v689->a;
  int * v703 = v702->regs;
  int v704 = v703[13];
  int v705 = v703[14];
  int v726 = v704 + v705;
  v703[6] = v726;
  struct StateT * v707 = v689->b;
  int * v708 = v707->regs;
  int v709 = v708[13];
  int v710 = v708[14];
  int v729 = v709 + v710;
  v708[6] = v729;
  struct StateT2 * v712 = slot_8(v689);
  return v712;
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

struct StateT2 * slot_10(struct StateT2 * v1235) {
  struct StateT * v1236 = v1235->a;
  int v1237 = v1236->timer;
  struct StateT * v1238 = v1235->b;
  int v1239 = v1238->timer;
  bool v1260 = v1237 == v1239;
  squared_assert(v1260);
  squared_assume(v1260);
  struct StateT * v1242 = v1235->a;
  int v1243 = v1242->timer;
  int v1262 = v1243 + 1;
  v1242->timer = v1262;
  struct StateT * v1245 = v1235->b;
  int v1246 = v1245->timer;
  int v1264 = v1246 + 1;
  v1245->timer = v1264;
  struct StateT * v1248 = v1235->a;
  int * v1249 = v1248->regs;
  int v1250 = v1249[14];
  int v1268 = v1250 + 4;
  v1249[14] = v1268;
  struct StateT * v1252 = v1235->b;
  int * v1253 = v1252->regs;
  int v1254 = v1253[14];
  int v1271 = v1254 + 4;
  v1253[14] = v1271;
  struct StateT2 * v1256 = slot_11(v1235);
  return v1256;
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

struct StateT2 * slot_8(struct StateT2 * v732) {
  struct StateT * v733 = v732->a;
  int v734 = v733->timer;
  struct StateT * v735 = v732->b;
  int v736 = v735->timer;
  bool v963 = v734 == v736;
  squared_assert(v963);
  squared_assume(v963);
  struct StateT * v739 = v732->a;
  int v740 = v739->timer;
  int v965 = v740 + 1;
  v739->timer = v965;
  struct StateT * v742 = v732->b;
  int v743 = v742->timer;
  int v967 = v743 + 1;
  v742->timer = v967;
  struct StateT * v745 = v732->a;
  int * v746 = v745->regs;
  int v747 = v746[6];
  int * v748 = v745->cache_tags;
  int v972 = (((int)((unsigned int)((int)((unsigned int)v747 >> 2)) >> 1)) & 1) * 2;
  int v749 = v748[v972];
  int v973 = ((((int)((unsigned int)((int)((unsigned int)v747 >> 2)) >> 1)) & 1) * 2) + 1;
  int v750 = v748[v973];
  int v974 = 4 + ((((int)((unsigned int)((int)((unsigned int)v747 >> 2)) >> 1)) & 3) * 2);
  int v751 = v748[v974];
  int v975 = (4 + ((((int)((unsigned int)((int)((unsigned int)v747 >> 2)) >> 1)) & 3) * 2)) + 1;
  int v752 = v748[v975];
  int v753 = v745->timer;
  int v976 = v753 + ((100 ^ (((~(((v751 ^ ((int)((unsigned int)((int)((unsigned int)v747 >> 2)) >> 1))) | (-(v751 ^ ((int)((unsigned int)((int)((unsigned int)v747 >> 2)) >> 1))))) >> 31)) | (~(((v752 ^ ((int)((unsigned int)((int)((unsigned int)v747 >> 2)) >> 1))) | (-(v752 ^ ((int)((unsigned int)((int)((unsigned int)v747 >> 2)) >> 1))))) >> 31))) & 104)) ^ (((~(((v749 ^ ((int)((unsigned int)((int)((unsigned int)v747 >> 2)) >> 1))) | (-(v749 ^ ((int)((unsigned int)((int)((unsigned int)v747 >> 2)) >> 1))))) >> 31)) | (~(((v750 ^ ((int)((unsigned int)((int)((unsigned int)v747 >> 2)) >> 1))) | (-(v750 ^ ((int)((unsigned int)((int)((unsigned int)v747 >> 2)) >> 1))))) >> 31))) & (1 ^ (100 ^ (((~(((v751 ^ ((int)((unsigned int)((int)((unsigned int)v747 >> 2)) >> 1))) | (-(v751 ^ ((int)((unsigned int)((int)((unsigned int)v747 >> 2)) >> 1))))) >> 31)) | (~(((v752 ^ ((int)((unsigned int)((int)((unsigned int)v747 >> 2)) >> 1))) | (-(v752 ^ ((int)((unsigned int)((int)((unsigned int)v747 >> 2)) >> 1))))) >> 31))) & 104)))));
  v745->timer = v976;
  int * v755 = v745->cache_vals;
  bool v977 = !(((~(((v749 ^ ((int)((unsigned int)((int)((unsigned int)v747 >> 2)) >> 1))) | (-(v749 ^ ((int)((unsigned int)((int)((unsigned int)v747 >> 2)) >> 1))))) >> 31)) | (~(((v750 ^ ((int)((unsigned int)((int)((unsigned int)v747 >> 2)) >> 1))) | (-(v750 ^ ((int)((unsigned int)((int)((unsigned int)v747 >> 2)) >> 1))))) >> 31))) == 0);
  int v848;
  if (v977) {
    int * v756 = v745->cache_age;
    int v979 = ((((int)((unsigned int)((int)((unsigned int)v747 >> 2)) >> 1)) & 1) * 2) + ((~(((v750 ^ ((int)((unsigned int)((int)((unsigned int)v747 >> 2)) >> 1))) | (-(v750 ^ ((int)((unsigned int)((int)((unsigned int)v747 >> 2)) >> 1))))) >> 31)) & 1);
    int v757 = v756[v979];
    int v758 = v756[v972];
    int v980 = v758 + ((int)((unsigned int)(v758 - v757) >> 31));
    v756[v972] = v980;
    int * v760 = v745->cache_age;
    int v761 = v760[v973];
    int v982 = v761 + ((int)((unsigned int)(v761 - v757) >> 31));
    v760[v973] = v982;
    int * v763 = v745->cache_age;
    v763[v979] = 0;
    v848 = v979;
  } else {
    int * v766 = v745->cache_age;
    int v986 = (((int)((unsigned int)((int)((unsigned int)v747 >> 2)) >> 1)) & 1) * 2;
    int v767 = v766[v986];
    int * v768 = v745->cache_tags;
    int v769 = v768[v986];
    int v770 = v766[v973];
    int v771 = v768[v973];
    bool v988 = !(((~(((v751 ^ ((int)((unsigned int)((int)((unsigned int)v747 >> 2)) >> 1))) | (-(v751 ^ ((int)((unsigned int)((int)((unsigned int)v747 >> 2)) >> 1))))) >> 31)) | (~(((v752 ^ ((int)((unsigned int)((int)((unsigned int)v747 >> 2)) >> 1))) | (-(v752 ^ ((int)((unsigned int)((int)((unsigned int)v747 >> 2)) >> 1))))) >> 31))) == 0);
    int v825;
    if (v988) {
      int * v772 = v745->cache_age;
      int v990 = (4 + ((((int)((unsigned int)((int)((unsigned int)v747 >> 2)) >> 1)) & 3) * 2)) + ((~(((v752 ^ ((int)((unsigned int)((int)((unsigned int)v747 >> 2)) >> 1))) | (-(v752 ^ ((int)((unsigned int)((int)((unsigned int)v747 >> 2)) >> 1))))) >> 31)) & 1);
      int v773 = v772[v990];
      int v774 = v772[v974];
      int v991 = v774 + ((int)((unsigned int)(v774 - v773) >> 31));
      v772[v974] = v991;
      int * v776 = v745->cache_age;
      int v777 = v776[v975];
      int v993 = v777 + ((int)((unsigned int)(v777 - v773) >> 31));
      v776[v975] = v993;
      int * v779 = v745->cache_age;
      v779[v990] = 0;
      v825 = v990;
    } else {
      int * v782 = v745->cache_age;
      int v997 = 4 + ((((int)((unsigned int)((int)((unsigned int)v747 >> 2)) >> 1)) & 3) * 2);
      int v783 = v782[v997];
      int * v784 = v745->cache_tags;
      int v785 = v784[v997];
      int v786 = v782[v975];
      int v787 = v784[v975];
      int * v788 = v745->cache_dirty;
      int v1000 = (4 + ((((int)((unsigned int)((int)((unsigned int)v747 >> 2)) >> 1)) & 3) * 2)) + ((((v783 + ((~(((v785 ^ -1) | (-(v785 ^ -1))) >> 31)) & 2)) - (v786 + ((~(((v787 ^ -1) | (-(v787 ^ -1))) >> 31)) & 2))) >> 31) & 1);
      int v789 = v788[v1000];
      bool v1001 = !(v789 == 0);
      if (v1001) {
        int * v790 = v745->cache_tags;
        int v791 = v790[v1000];
        int * v792 = v745->cache_vals;
        int v1004 = ((4 + ((((int)((unsigned int)((int)((unsigned int)v747 >> 2)) >> 1)) & 3) * 2)) + ((((v783 + ((~(((v785 ^ -1) | (-(v785 ^ -1))) >> 31)) & 2)) - (v786 + ((~(((v787 ^ -1) | (-(v787 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
        int v793 = v792[v1004];
        int v1005 = (((4 + ((((int)((unsigned int)((int)((unsigned int)v747 >> 2)) >> 1)) & 3) * 2)) + ((((v783 + ((~(((v785 ^ -1) | (-(v785 ^ -1))) >> 31)) & 2)) - (v786 + ((~(((v787 ^ -1) | (-(v787 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
        int v794 = v792[v1005];
        int * v795 = v745->mem;
        int v1007 = v791 * 2;
        v795[v1007] = v793;
        int * v797 = v745->mem;
        int v1010 = (v791 * 2) + 1;
        v797[v1010] = v794;
        ;
      } else {
        ;
      }
      int * v802 = v745->mem;
      int v1015 = ((int)((unsigned int)((int)((unsigned int)v747 >> 2)) >> 1)) * 2;
      int v803 = v802[v1015];
      int v1016 = (((int)((unsigned int)((int)((unsigned int)v747 >> 2)) >> 1)) * 2) + 1;
      int v804 = v802[v1016];
      int * v805 = v745->cache_vals;
      int v1018 = ((4 + ((((int)((unsigned int)((int)((unsigned int)v747 >> 2)) >> 1)) & 3) * 2)) + ((((v783 + ((~(((v785 ^ -1) | (-(v785 ^ -1))) >> 31)) & 2)) - (v786 + ((~(((v787 ^ -1) | (-(v787 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
      v805[v1018] = v803;
      int * v807 = v745->cache_vals;
      int v1021 = (((4 + ((((int)((unsigned int)((int)((unsigned int)v747 >> 2)) >> 1)) & 3) * 2)) + ((((v783 + ((~(((v785 ^ -1) | (-(v785 ^ -1))) >> 31)) & 2)) - (v786 + ((~(((v787 ^ -1) | (-(v787 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
      v807[v1021] = v804;
      int * v809 = v745->cache_tags;
      int v1024 = (int)((unsigned int)((int)((unsigned int)v747 >> 2)) >> 1);
      v809[v1000] = v1024;
      int * v811 = v745->cache_dirty;
      v811[v1000] = 0;
      int * v813 = v745->cache_age;
      v813[v1000] = 1;
      int * v815 = v745->cache_age;
      int v816 = v815[v1000];
      int v817 = v815[v974];
      int v1030 = v817 + ((int)((unsigned int)(v817 - v816) >> 31));
      v815[v974] = v1030;
      int * v819 = v745->cache_age;
      int v820 = v819[v975];
      int v1032 = v820 + ((int)((unsigned int)(v820 - v816) >> 31));
      v819[v975] = v1032;
      int * v822 = v745->cache_age;
      v822[v1000] = 0;
      v825 = v1000;
    }
    int * v826 = v745->cache_vals;
    int v1035 = v825 * 2;
    int v827 = v826[v1035];
    int v1036 = (v825 * 2) + 1;
    int v828 = v826[v1036];
    int v1037 = (((((int)((unsigned int)((int)((unsigned int)v747 >> 2)) >> 1)) & 1) * 2) + ((((v767 + ((~(((v769 ^ -1) | (-(v769 ^ -1))) >> 31)) & 2)) - (v770 + ((~(((v771 ^ -1) | (-(v771 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
    v826[v1037] = v827;
    int * v830 = v745->cache_vals;
    int v1040 = ((((((int)((unsigned int)((int)((unsigned int)v747 >> 2)) >> 1)) & 1) * 2) + ((((v767 + ((~(((v769 ^ -1) | (-(v769 ^ -1))) >> 31)) & 2)) - (v770 + ((~(((v771 ^ -1) | (-(v771 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
    v830[v1040] = v828;
    int * v832 = v745->cache_tags;
    int v1043 = ((((int)((unsigned int)((int)((unsigned int)v747 >> 2)) >> 1)) & 1) * 2) + ((((v767 + ((~(((v769 ^ -1) | (-(v769 ^ -1))) >> 31)) & 2)) - (v770 + ((~(((v771 ^ -1) | (-(v771 ^ -1))) >> 31)) & 2))) >> 31) & 1);
    int v1044 = (int)((unsigned int)((int)((unsigned int)v747 >> 2)) >> 1);
    v832[v1043] = v1044;
    int * v834 = v745->cache_dirty;
    v834[v1043] = 0;
    int * v836 = v745->cache_age;
    v836[v1043] = 1;
    int * v838 = v745->cache_age;
    int v839 = v838[v1043];
    int v840 = v838[v972];
    int v1050 = v840 + ((int)((unsigned int)(v840 - v839) >> 31));
    v838[v972] = v1050;
    int * v842 = v745->cache_age;
    int v843 = v842[v973];
    int v1052 = v843 + ((int)((unsigned int)(v843 - v839) >> 31));
    v842[v973] = v1052;
    int * v845 = v745->cache_age;
    v845[v1043] = 0;
    v848 = v1043;
  }
  int v1055 = (v848 * 2) + (((int)((unsigned int)v747 >> 2)) & 1);
  int v849 = v755[v1055];
  int * v850 = v745->regs;
  v850[11] = v849;
  struct StateT * v852 = v732->b;
  int * v853 = v852->regs;
  int v854 = v853[6];
  int * v855 = v852->cache_tags;
  int v1062 = (((int)((unsigned int)((int)((unsigned int)v854 >> 2)) >> 1)) & 1) * 2;
  int v856 = v855[v1062];
  int v1063 = ((((int)((unsigned int)((int)((unsigned int)v854 >> 2)) >> 1)) & 1) * 2) + 1;
  int v857 = v855[v1063];
  int v1064 = 4 + ((((int)((unsigned int)((int)((unsigned int)v854 >> 2)) >> 1)) & 3) * 2);
  int v858 = v855[v1064];
  int v1065 = (4 + ((((int)((unsigned int)((int)((unsigned int)v854 >> 2)) >> 1)) & 3) * 2)) + 1;
  int v859 = v855[v1065];
  int v860 = v852->timer;
  int v1066 = v860 + ((100 ^ (((~(((v858 ^ ((int)((unsigned int)((int)((unsigned int)v854 >> 2)) >> 1))) | (-(v858 ^ ((int)((unsigned int)((int)((unsigned int)v854 >> 2)) >> 1))))) >> 31)) | (~(((v859 ^ ((int)((unsigned int)((int)((unsigned int)v854 >> 2)) >> 1))) | (-(v859 ^ ((int)((unsigned int)((int)((unsigned int)v854 >> 2)) >> 1))))) >> 31))) & 104)) ^ (((~(((v856 ^ ((int)((unsigned int)((int)((unsigned int)v854 >> 2)) >> 1))) | (-(v856 ^ ((int)((unsigned int)((int)((unsigned int)v854 >> 2)) >> 1))))) >> 31)) | (~(((v857 ^ ((int)((unsigned int)((int)((unsigned int)v854 >> 2)) >> 1))) | (-(v857 ^ ((int)((unsigned int)((int)((unsigned int)v854 >> 2)) >> 1))))) >> 31))) & (1 ^ (100 ^ (((~(((v858 ^ ((int)((unsigned int)((int)((unsigned int)v854 >> 2)) >> 1))) | (-(v858 ^ ((int)((unsigned int)((int)((unsigned int)v854 >> 2)) >> 1))))) >> 31)) | (~(((v859 ^ ((int)((unsigned int)((int)((unsigned int)v854 >> 2)) >> 1))) | (-(v859 ^ ((int)((unsigned int)((int)((unsigned int)v854 >> 2)) >> 1))))) >> 31))) & 104)))));
  v852->timer = v1066;
  int * v862 = v852->cache_vals;
  bool v1067 = !(((~(((v856 ^ ((int)((unsigned int)((int)((unsigned int)v854 >> 2)) >> 1))) | (-(v856 ^ ((int)((unsigned int)((int)((unsigned int)v854 >> 2)) >> 1))))) >> 31)) | (~(((v857 ^ ((int)((unsigned int)((int)((unsigned int)v854 >> 2)) >> 1))) | (-(v857 ^ ((int)((unsigned int)((int)((unsigned int)v854 >> 2)) >> 1))))) >> 31))) == 0);
  int v955;
  if (v1067) {
    int * v863 = v852->cache_age;
    int v1069 = ((((int)((unsigned int)((int)((unsigned int)v854 >> 2)) >> 1)) & 1) * 2) + ((~(((v857 ^ ((int)((unsigned int)((int)((unsigned int)v854 >> 2)) >> 1))) | (-(v857 ^ ((int)((unsigned int)((int)((unsigned int)v854 >> 2)) >> 1))))) >> 31)) & 1);
    int v864 = v863[v1069];
    int v865 = v863[v1062];
    int v1070 = v865 + ((int)((unsigned int)(v865 - v864) >> 31));
    v863[v1062] = v1070;
    int * v867 = v852->cache_age;
    int v868 = v867[v1063];
    int v1072 = v868 + ((int)((unsigned int)(v868 - v864) >> 31));
    v867[v1063] = v1072;
    int * v870 = v852->cache_age;
    v870[v1069] = 0;
    v955 = v1069;
  } else {
    int * v873 = v852->cache_age;
    int v1076 = (((int)((unsigned int)((int)((unsigned int)v854 >> 2)) >> 1)) & 1) * 2;
    int v874 = v873[v1076];
    int * v875 = v852->cache_tags;
    int v876 = v875[v1076];
    int v877 = v873[v1063];
    int v878 = v875[v1063];
    bool v1078 = !(((~(((v858 ^ ((int)((unsigned int)((int)((unsigned int)v854 >> 2)) >> 1))) | (-(v858 ^ ((int)((unsigned int)((int)((unsigned int)v854 >> 2)) >> 1))))) >> 31)) | (~(((v859 ^ ((int)((unsigned int)((int)((unsigned int)v854 >> 2)) >> 1))) | (-(v859 ^ ((int)((unsigned int)((int)((unsigned int)v854 >> 2)) >> 1))))) >> 31))) == 0);
    int v932;
    if (v1078) {
      int * v879 = v852->cache_age;
      int v1080 = (4 + ((((int)((unsigned int)((int)((unsigned int)v854 >> 2)) >> 1)) & 3) * 2)) + ((~(((v859 ^ ((int)((unsigned int)((int)((unsigned int)v854 >> 2)) >> 1))) | (-(v859 ^ ((int)((unsigned int)((int)((unsigned int)v854 >> 2)) >> 1))))) >> 31)) & 1);
      int v880 = v879[v1080];
      int v881 = v879[v1064];
      int v1081 = v881 + ((int)((unsigned int)(v881 - v880) >> 31));
      v879[v1064] = v1081;
      int * v883 = v852->cache_age;
      int v884 = v883[v1065];
      int v1083 = v884 + ((int)((unsigned int)(v884 - v880) >> 31));
      v883[v1065] = v1083;
      int * v886 = v852->cache_age;
      v886[v1080] = 0;
      v932 = v1080;
    } else {
      int * v889 = v852->cache_age;
      int v1087 = 4 + ((((int)((unsigned int)((int)((unsigned int)v854 >> 2)) >> 1)) & 3) * 2);
      int v890 = v889[v1087];
      int * v891 = v852->cache_tags;
      int v892 = v891[v1087];
      int v893 = v889[v1065];
      int v894 = v891[v1065];
      int * v895 = v852->cache_dirty;
      int v1090 = (4 + ((((int)((unsigned int)((int)((unsigned int)v854 >> 2)) >> 1)) & 3) * 2)) + ((((v890 + ((~(((v892 ^ -1) | (-(v892 ^ -1))) >> 31)) & 2)) - (v893 + ((~(((v894 ^ -1) | (-(v894 ^ -1))) >> 31)) & 2))) >> 31) & 1);
      int v896 = v895[v1090];
      bool v1091 = !(v896 == 0);
      if (v1091) {
        int * v897 = v852->cache_tags;
        int v898 = v897[v1090];
        int * v899 = v852->cache_vals;
        int v1094 = ((4 + ((((int)((unsigned int)((int)((unsigned int)v854 >> 2)) >> 1)) & 3) * 2)) + ((((v890 + ((~(((v892 ^ -1) | (-(v892 ^ -1))) >> 31)) & 2)) - (v893 + ((~(((v894 ^ -1) | (-(v894 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
        int v900 = v899[v1094];
        int v1095 = (((4 + ((((int)((unsigned int)((int)((unsigned int)v854 >> 2)) >> 1)) & 3) * 2)) + ((((v890 + ((~(((v892 ^ -1) | (-(v892 ^ -1))) >> 31)) & 2)) - (v893 + ((~(((v894 ^ -1) | (-(v894 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
        int v901 = v899[v1095];
        int * v902 = v852->mem;
        int v1097 = v898 * 2;
        v902[v1097] = v900;
        int * v904 = v852->mem;
        int v1100 = (v898 * 2) + 1;
        v904[v1100] = v901;
        ;
      } else {
        ;
      }
      int * v909 = v852->mem;
      int v1105 = ((int)((unsigned int)((int)((unsigned int)v854 >> 2)) >> 1)) * 2;
      int v910 = v909[v1105];
      int v1106 = (((int)((unsigned int)((int)((unsigned int)v854 >> 2)) >> 1)) * 2) + 1;
      int v911 = v909[v1106];
      int * v912 = v852->cache_vals;
      int v1108 = ((4 + ((((int)((unsigned int)((int)((unsigned int)v854 >> 2)) >> 1)) & 3) * 2)) + ((((v890 + ((~(((v892 ^ -1) | (-(v892 ^ -1))) >> 31)) & 2)) - (v893 + ((~(((v894 ^ -1) | (-(v894 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
      v912[v1108] = v910;
      int * v914 = v852->cache_vals;
      int v1111 = (((4 + ((((int)((unsigned int)((int)((unsigned int)v854 >> 2)) >> 1)) & 3) * 2)) + ((((v890 + ((~(((v892 ^ -1) | (-(v892 ^ -1))) >> 31)) & 2)) - (v893 + ((~(((v894 ^ -1) | (-(v894 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
      v914[v1111] = v911;
      int * v916 = v852->cache_tags;
      int v1114 = (int)((unsigned int)((int)((unsigned int)v854 >> 2)) >> 1);
      v916[v1090] = v1114;
      int * v918 = v852->cache_dirty;
      v918[v1090] = 0;
      int * v920 = v852->cache_age;
      v920[v1090] = 1;
      int * v922 = v852->cache_age;
      int v923 = v922[v1090];
      int v924 = v922[v1064];
      int v1120 = v924 + ((int)((unsigned int)(v924 - v923) >> 31));
      v922[v1064] = v1120;
      int * v926 = v852->cache_age;
      int v927 = v926[v1065];
      int v1122 = v927 + ((int)((unsigned int)(v927 - v923) >> 31));
      v926[v1065] = v1122;
      int * v929 = v852->cache_age;
      v929[v1090] = 0;
      v932 = v1090;
    }
    int * v933 = v852->cache_vals;
    int v1125 = v932 * 2;
    int v934 = v933[v1125];
    int v1126 = (v932 * 2) + 1;
    int v935 = v933[v1126];
    int v1127 = (((((int)((unsigned int)((int)((unsigned int)v854 >> 2)) >> 1)) & 1) * 2) + ((((v874 + ((~(((v876 ^ -1) | (-(v876 ^ -1))) >> 31)) & 2)) - (v877 + ((~(((v878 ^ -1) | (-(v878 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
    v933[v1127] = v934;
    int * v937 = v852->cache_vals;
    int v1130 = ((((((int)((unsigned int)((int)((unsigned int)v854 >> 2)) >> 1)) & 1) * 2) + ((((v874 + ((~(((v876 ^ -1) | (-(v876 ^ -1))) >> 31)) & 2)) - (v877 + ((~(((v878 ^ -1) | (-(v878 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
    v937[v1130] = v935;
    int * v939 = v852->cache_tags;
    int v1133 = ((((int)((unsigned int)((int)((unsigned int)v854 >> 2)) >> 1)) & 1) * 2) + ((((v874 + ((~(((v876 ^ -1) | (-(v876 ^ -1))) >> 31)) & 2)) - (v877 + ((~(((v878 ^ -1) | (-(v878 ^ -1))) >> 31)) & 2))) >> 31) & 1);
    int v1134 = (int)((unsigned int)((int)((unsigned int)v854 >> 2)) >> 1);
    v939[v1133] = v1134;
    int * v941 = v852->cache_dirty;
    v941[v1133] = 0;
    int * v943 = v852->cache_age;
    v943[v1133] = 1;
    int * v945 = v852->cache_age;
    int v946 = v945[v1133];
    int v947 = v945[v1062];
    int v1140 = v947 + ((int)((unsigned int)(v947 - v946) >> 31));
    v945[v1062] = v1140;
    int * v949 = v852->cache_age;
    int v950 = v949[v1063];
    int v1142 = v950 + ((int)((unsigned int)(v950 - v946) >> 31));
    v949[v1063] = v1142;
    int * v952 = v852->cache_age;
    v952[v1133] = 0;
    v955 = v1133;
  }
  int v1145 = (v955 * 2) + (((int)((unsigned int)v854 >> 2)) & 1);
  int v956 = v862[v1145];
  int * v957 = v852->regs;
  v957[11] = v956;
  struct StateT2 * v959 = slot_9(v732);
  return v959;
}

struct StateT2 * slot_4(struct StateT2 * v146) {
  struct StateT * v147 = v146->a;
  int v148 = v147->timer;
  struct StateT * v149 = v146->b;
  int v150 = v149->timer;
  bool v177 = v148 == v150;
  squared_assert(v177);
  squared_assume(v177);
  struct StateT * v153 = v146->a;
  int v154 = v153->timer;
  int v179 = v154 + 1;
  v153->timer = v179;
  struct StateT * v156 = v146->b;
  int v157 = v156->timer;
  int v181 = v157 + 1;
  v156->timer = v181;
  struct StateT * v159 = v146->a;
  int * v160 = v159->regs;
  int v161 = v160[14];
  int v162 = v160[15];
  struct StateT * v163 = v146->b;
  int * v164 = v163->regs;
  int v165 = v164[14];
  int v166 = v164[15];
  bool v188 = (v161 >= v162) == (v165 >= v166);
  squared_diverged(v188);
  squared_assume(v188);
  bool v189 = v161 >= v162;
  struct StateT2 * v173;
  if (v189) {
    struct StateT2 * v169 = slot_14(v146);
    v173 = v169;
  } else {
    struct StateT2 * v171 = slot_5(v146);
    v173 = v171;
  }
  return v173;
}

struct StateT2 * slot_13(struct StateT2 * v1274) {
  struct StateT * v1275 = v1274->a;
  int v1276 = v1275->timer;
  struct StateT * v1277 = v1274->b;
  int v1278 = v1277->timer;
  bool v1292 = v1276 == v1278;
  squared_assert(v1292);
  squared_assume(v1292);
  struct StateT * v1281 = v1274->a;
  int v1282 = v1281->timer;
  int v1294 = v1282 + 1;
  v1281->timer = v1294;
  struct StateT * v1284 = v1274->b;
  int v1285 = v1284->timer;
  int v1296 = v1285 + 1;
  v1284->timer = v1296;
  return v1274;
}

struct StateT2 * slot_9(struct StateT2 * v1150) {
  struct StateT * v1151 = v1150->a;
  int v1152 = v1151->timer;
  struct StateT * v1153 = v1150->b;
  int v1154 = v1153->timer;
  bool v1181 = v1152 == v1154;
  squared_assert(v1181);
  squared_assume(v1181);
  struct StateT * v1157 = v1150->a;
  int v1158 = v1157->timer;
  int v1183 = v1158 + 1;
  v1157->timer = v1183;
  struct StateT * v1160 = v1150->b;
  int v1161 = v1160->timer;
  int v1185 = v1161 + 1;
  v1160->timer = v1185;
  struct StateT * v1163 = v1150->a;
  int * v1164 = v1163->regs;
  int v1165 = v1164[10];
  int v1166 = v1164[11];
  struct StateT * v1167 = v1150->b;
  int * v1168 = v1167->regs;
  int v1169 = v1168[10];
  int v1170 = v1168[11];
  bool v1192 = (!(v1165 == v1166)) == (!(v1169 == v1170));
  squared_diverged(v1192);
  squared_assume(v1192);
  bool v1193 = !(v1165 == v1166);
  struct StateT2 * v1177;
  if (v1193) {
    struct StateT2 * v1173 = slot_12(v1150);
    v1177 = v1173;
  } else {
    struct StateT2 * v1175 = slot_10(v1150);
    v1177 = v1175;
  }
  return v1177;
}

struct StateT2 * slot_11(struct StateT2 * v1297) {
  struct StateT * v1298 = v1297->a;
  int v1299 = v1298->timer;
  struct StateT * v1300 = v1297->b;
  int v1301 = v1300->timer;
  bool v1316 = v1299 == v1301;
  squared_assert(v1316);
  squared_assume(v1316);
  struct StateT * v1304 = v1297->a;
  int v1305 = v1304->timer;
  int v1318 = v1305 + 1;
  v1304->timer = v1318;
  struct StateT * v1307 = v1297->b;
  int v1308 = v1307->timer;
  int v1320 = v1308 + 1;
  v1307->timer = v1320;
  struct StateT2 * v1312 = slot_4(v1297);
  return v1312;
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