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

struct StateT * slot_12(struct StateT * v561);
struct StateT * slot_6(struct StateT * v281);
struct StateT * slot_25(struct StateT * v2137);
struct StateT * slot_16(struct StateT * v998);
struct StateT * slot_23(struct StateT * v1806);
struct StateT * slot_5(struct StateT * v267);
struct StateT * slot_2(struct StateT * v218);
struct StateT * slot_7(struct StateT * v297);
struct StateT * slot_21(struct StateT * v1399);
struct StateT * slot_3(struct StateT * v226);
struct StateT * slot_10(struct StateT * v527);
struct StateT * slot_1(struct StateT * v15);
struct StateT * slot_19(struct StateT * v1071);
struct StateT * slot_13(struct StateT * v575);
struct StateT * slot_24(struct StateT * v1822);
struct StateT * slot_0(struct StateT * v2);
struct StateT * slot_14(struct StateT * v591);
struct StateT * slot_17(struct StateT * v1014);
struct StateT * slot_20(struct StateT * v1386);
struct StateT * snippet(struct StateT * v0);
struct StateT * slot_8(struct StateT * v500);
struct StateT * slot_4(struct StateT * v247);
struct StateT * slot_15(struct StateT * v794);
struct StateT * slot_18(struct StateT * v1058);
struct StateT * slot_9(struct StateT * v513);
struct StateT * slot_22(struct StateT * v1602);
struct StateT * slot_11(struct StateT * v547);
struct StateT * slot_12(struct StateT * v561) {
  int v562 = v561->timer;
  int v569 = v562 + 1;
  v561->timer = v569;
  int * v564 = v561->regs;
  int v565 = v564[10];
  int v572 = (int)((unsigned int)v565 >> 26);
  v564[10] = v572;
  struct StateT * v567 = slot_13(v561);
  return v567;
}

struct StateT * slot_6(struct StateT * v281) {
  int v282 = v281->timer;
  int v290 = v282 + 1;
  v281->timer = v290;
  int * v284 = v281->regs;
  int v285 = v284[11];
  int v286 = v284[10];
  int v294 = v285 + v286;
  v284[10] = v294;
  struct StateT * v288 = slot_7(v281);
  return v288;
}

struct StateT * slot_25(struct StateT * v2137) {
  int v2138 = v2137->timer;
  int v2141 = v2138 + 1;
  v2137->timer = v2141;
  return v2137;
}

struct StateT * slot_16(struct StateT * v998) {
  int v999 = v998->timer;
  int v1007 = v999 + 1;
  v998->timer = v1007;
  int * v1001 = v998->regs;
  int v1002 = v1001[11];
  int v1003 = v1001[10];
  int v1011 = v1002 & v1003;
  v1001[10] = v1011;
  struct StateT * v1005 = slot_17(v998);
  return v1005;
}

struct StateT * slot_23(struct StateT * v1806) {
  int v1807 = v1806->timer;
  int v1815 = v1807 + 1;
  v1806->timer = v1815;
  int * v1809 = v1806->regs;
  int v1810 = v1809[12];
  int v1811 = v1809[10];
  int v1819 = v1810 & v1811;
  v1809[10] = v1819;
  struct StateT * v1813 = slot_24(v1806);
  return v1813;
}

struct StateT * slot_5(struct StateT * v267) {
  int v268 = v267->timer;
  int v275 = v268 + 1;
  v267->timer = v275;
  int * v270 = v267->regs;
  int v271 = v270[11];
  int v278 = v271 + 72;
  v270[11] = v278;
  struct StateT * v273 = slot_6(v267);
  return v273;
}

struct StateT * slot_2(struct StateT * v218) {
  int v219 = v218->timer;
  int v223 = v219 + 1;
  v218->timer = v223;
  struct StateT * v221 = slot_3(v218);
  return v221;
}

struct StateT * slot_7(struct StateT * v297) {
  int v298 = v297->timer;
  int v408 = v298 + 1;
  v297->timer = v408;
  int * v300 = v297->regs;
  int v301 = v300[10];
  int * v302 = v297->cache_tags;
  int v412 = (((int)((unsigned int)((int)((unsigned int)v301 >> 2)) >> 1)) & 1) * 2;
  int v303 = v302[v412];
  int v413 = ((((int)((unsigned int)((int)((unsigned int)v301 >> 2)) >> 1)) & 1) * 2) + 1;
  int v304 = v302[v413];
  int v414 = 4 + ((((int)((unsigned int)((int)((unsigned int)v301 >> 2)) >> 1)) & 3) * 2);
  int v305 = v302[v414];
  int v415 = (4 + ((((int)((unsigned int)((int)((unsigned int)v301 >> 2)) >> 1)) & 3) * 2)) + 1;
  int v306 = v302[v415];
  int v307 = v297->timer;
  int v416 = v307 + ((100 ^ (((~(((v305 ^ ((int)((unsigned int)((int)((unsigned int)v301 >> 2)) >> 1))) | (-(v305 ^ ((int)((unsigned int)((int)((unsigned int)v301 >> 2)) >> 1))))) >> 31)) | (~(((v306 ^ ((int)((unsigned int)((int)((unsigned int)v301 >> 2)) >> 1))) | (-(v306 ^ ((int)((unsigned int)((int)((unsigned int)v301 >> 2)) >> 1))))) >> 31))) & 104)) ^ (((~(((v303 ^ ((int)((unsigned int)((int)((unsigned int)v301 >> 2)) >> 1))) | (-(v303 ^ ((int)((unsigned int)((int)((unsigned int)v301 >> 2)) >> 1))))) >> 31)) | (~(((v304 ^ ((int)((unsigned int)((int)((unsigned int)v301 >> 2)) >> 1))) | (-(v304 ^ ((int)((unsigned int)((int)((unsigned int)v301 >> 2)) >> 1))))) >> 31))) & (1 ^ (100 ^ (((~(((v305 ^ ((int)((unsigned int)((int)((unsigned int)v301 >> 2)) >> 1))) | (-(v305 ^ ((int)((unsigned int)((int)((unsigned int)v301 >> 2)) >> 1))))) >> 31)) | (~(((v306 ^ ((int)((unsigned int)((int)((unsigned int)v301 >> 2)) >> 1))) | (-(v306 ^ ((int)((unsigned int)((int)((unsigned int)v301 >> 2)) >> 1))))) >> 31))) & 104)))));
  v297->timer = v416;
  int * v309 = v297->cache_vals;
  bool v417 = !(((~(((v303 ^ ((int)((unsigned int)((int)((unsigned int)v301 >> 2)) >> 1))) | (-(v303 ^ ((int)((unsigned int)((int)((unsigned int)v301 >> 2)) >> 1))))) >> 31)) | (~(((v304 ^ ((int)((unsigned int)((int)((unsigned int)v301 >> 2)) >> 1))) | (-(v304 ^ ((int)((unsigned int)((int)((unsigned int)v301 >> 2)) >> 1))))) >> 31))) == 0);
  int v402;
  if (v417) {
    int * v310 = v297->cache_age;
    int v419 = ((((int)((unsigned int)((int)((unsigned int)v301 >> 2)) >> 1)) & 1) * 2) + ((~(((v304 ^ ((int)((unsigned int)((int)((unsigned int)v301 >> 2)) >> 1))) | (-(v304 ^ ((int)((unsigned int)((int)((unsigned int)v301 >> 2)) >> 1))))) >> 31)) & 1);
    int v311 = v310[v419];
    int v312 = v310[v412];
    int v420 = v312 + ((int)((unsigned int)(v312 - v311) >> 31));
    v310[v412] = v420;
    int * v314 = v297->cache_age;
    int v315 = v314[v413];
    int v422 = v315 + ((int)((unsigned int)(v315 - v311) >> 31));
    v314[v413] = v422;
    int * v317 = v297->cache_age;
    v317[v419] = 0;
    v402 = v419;
  } else {
    int * v320 = v297->cache_age;
    int v426 = (((int)((unsigned int)((int)((unsigned int)v301 >> 2)) >> 1)) & 1) * 2;
    int v321 = v320[v426];
    int * v322 = v297->cache_tags;
    int v323 = v322[v426];
    int v324 = v320[v413];
    int v325 = v322[v413];
    bool v428 = !(((~(((v305 ^ ((int)((unsigned int)((int)((unsigned int)v301 >> 2)) >> 1))) | (-(v305 ^ ((int)((unsigned int)((int)((unsigned int)v301 >> 2)) >> 1))))) >> 31)) | (~(((v306 ^ ((int)((unsigned int)((int)((unsigned int)v301 >> 2)) >> 1))) | (-(v306 ^ ((int)((unsigned int)((int)((unsigned int)v301 >> 2)) >> 1))))) >> 31))) == 0);
    int v379;
    if (v428) {
      int * v326 = v297->cache_age;
      int v430 = (4 + ((((int)((unsigned int)((int)((unsigned int)v301 >> 2)) >> 1)) & 3) * 2)) + ((~(((v306 ^ ((int)((unsigned int)((int)((unsigned int)v301 >> 2)) >> 1))) | (-(v306 ^ ((int)((unsigned int)((int)((unsigned int)v301 >> 2)) >> 1))))) >> 31)) & 1);
      int v327 = v326[v430];
      int v328 = v326[v414];
      int v431 = v328 + ((int)((unsigned int)(v328 - v327) >> 31));
      v326[v414] = v431;
      int * v330 = v297->cache_age;
      int v331 = v330[v415];
      int v433 = v331 + ((int)((unsigned int)(v331 - v327) >> 31));
      v330[v415] = v433;
      int * v333 = v297->cache_age;
      v333[v430] = 0;
      v379 = v430;
    } else {
      int * v336 = v297->cache_age;
      int v437 = 4 + ((((int)((unsigned int)((int)((unsigned int)v301 >> 2)) >> 1)) & 3) * 2);
      int v337 = v336[v437];
      int * v338 = v297->cache_tags;
      int v339 = v338[v437];
      int v340 = v336[v415];
      int v341 = v338[v415];
      int * v342 = v297->cache_dirty;
      int v440 = (4 + ((((int)((unsigned int)((int)((unsigned int)v301 >> 2)) >> 1)) & 3) * 2)) + ((((v337 + ((~(((v339 ^ -1) | (-(v339 ^ -1))) >> 31)) & 2)) - (v340 + ((~(((v341 ^ -1) | (-(v341 ^ -1))) >> 31)) & 2))) >> 31) & 1);
      int v343 = v342[v440];
      bool v441 = !(v343 == 0);
      if (v441) {
        int * v344 = v297->cache_tags;
        int v345 = v344[v440];
        int * v346 = v297->cache_vals;
        int v444 = ((4 + ((((int)((unsigned int)((int)((unsigned int)v301 >> 2)) >> 1)) & 3) * 2)) + ((((v337 + ((~(((v339 ^ -1) | (-(v339 ^ -1))) >> 31)) & 2)) - (v340 + ((~(((v341 ^ -1) | (-(v341 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
        int v347 = v346[v444];
        int v445 = (((4 + ((((int)((unsigned int)((int)((unsigned int)v301 >> 2)) >> 1)) & 3) * 2)) + ((((v337 + ((~(((v339 ^ -1) | (-(v339 ^ -1))) >> 31)) & 2)) - (v340 + ((~(((v341 ^ -1) | (-(v341 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
        int v348 = v346[v445];
        int * v349 = v297->mem;
        int v447 = v345 * 2;
        v349[v447] = v347;
        int * v351 = v297->mem;
        int v450 = (v345 * 2) + 1;
        v351[v450] = v348;
        ;
      } else {
        ;
      }
      int * v356 = v297->mem;
      int v455 = ((int)((unsigned int)((int)((unsigned int)v301 >> 2)) >> 1)) * 2;
      int v357 = v356[v455];
      int v456 = (((int)((unsigned int)((int)((unsigned int)v301 >> 2)) >> 1)) * 2) + 1;
      int v358 = v356[v456];
      int * v359 = v297->cache_vals;
      int v458 = ((4 + ((((int)((unsigned int)((int)((unsigned int)v301 >> 2)) >> 1)) & 3) * 2)) + ((((v337 + ((~(((v339 ^ -1) | (-(v339 ^ -1))) >> 31)) & 2)) - (v340 + ((~(((v341 ^ -1) | (-(v341 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
      v359[v458] = v357;
      int * v361 = v297->cache_vals;
      int v461 = (((4 + ((((int)((unsigned int)((int)((unsigned int)v301 >> 2)) >> 1)) & 3) * 2)) + ((((v337 + ((~(((v339 ^ -1) | (-(v339 ^ -1))) >> 31)) & 2)) - (v340 + ((~(((v341 ^ -1) | (-(v341 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
      v361[v461] = v358;
      int * v363 = v297->cache_tags;
      int v464 = (int)((unsigned int)((int)((unsigned int)v301 >> 2)) >> 1);
      v363[v440] = v464;
      int * v365 = v297->cache_dirty;
      v365[v440] = 0;
      int * v367 = v297->cache_age;
      v367[v440] = 1;
      int * v369 = v297->cache_age;
      int v370 = v369[v440];
      int v371 = v369[v414];
      int v470 = v371 + ((int)((unsigned int)(v371 - v370) >> 31));
      v369[v414] = v470;
      int * v373 = v297->cache_age;
      int v374 = v373[v415];
      int v472 = v374 + ((int)((unsigned int)(v374 - v370) >> 31));
      v373[v415] = v472;
      int * v376 = v297->cache_age;
      v376[v440] = 0;
      v379 = v440;
    }
    int * v380 = v297->cache_vals;
    int v475 = v379 * 2;
    int v381 = v380[v475];
    int v476 = (v379 * 2) + 1;
    int v382 = v380[v476];
    int v477 = (((((int)((unsigned int)((int)((unsigned int)v301 >> 2)) >> 1)) & 1) * 2) + ((((v321 + ((~(((v323 ^ -1) | (-(v323 ^ -1))) >> 31)) & 2)) - (v324 + ((~(((v325 ^ -1) | (-(v325 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
    v380[v477] = v381;
    int * v384 = v297->cache_vals;
    int v480 = ((((((int)((unsigned int)((int)((unsigned int)v301 >> 2)) >> 1)) & 1) * 2) + ((((v321 + ((~(((v323 ^ -1) | (-(v323 ^ -1))) >> 31)) & 2)) - (v324 + ((~(((v325 ^ -1) | (-(v325 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
    v384[v480] = v382;
    int * v386 = v297->cache_tags;
    int v483 = ((((int)((unsigned int)((int)((unsigned int)v301 >> 2)) >> 1)) & 1) * 2) + ((((v321 + ((~(((v323 ^ -1) | (-(v323 ^ -1))) >> 31)) & 2)) - (v324 + ((~(((v325 ^ -1) | (-(v325 ^ -1))) >> 31)) & 2))) >> 31) & 1);
    int v484 = (int)((unsigned int)((int)((unsigned int)v301 >> 2)) >> 1);
    v386[v483] = v484;
    int * v388 = v297->cache_dirty;
    v388[v483] = 0;
    int * v390 = v297->cache_age;
    v390[v483] = 1;
    int * v392 = v297->cache_age;
    int v393 = v392[v483];
    int v394 = v392[v412];
    int v490 = v394 + ((int)((unsigned int)(v394 - v393) >> 31));
    v392[v412] = v490;
    int * v396 = v297->cache_age;
    int v397 = v396[v413];
    int v492 = v397 + ((int)((unsigned int)(v397 - v393) >> 31));
    v396[v413] = v492;
    int * v399 = v297->cache_age;
    v399[v483] = 0;
    v402 = v483;
  }
  int v495 = (v402 * 2) + (((int)((unsigned int)v301 >> 2)) & 1);
  int v403 = v309[v495];
  int * v404 = v297->regs;
  v404[10] = v403;
  struct StateT * v406 = slot_8(v297);
  return v406;
}

struct StateT * slot_21(struct StateT * v1399) {
  int v1400 = v1399->timer;
  int v1510 = v1400 + 1;
  v1399->timer = v1510;
  int * v1402 = v1399->regs;
  int v1403 = v1402[10];
  int * v1404 = v1399->cache_tags;
  int v1514 = (((int)((unsigned int)((int)((unsigned int)(v1403 + 4) >> 2)) >> 1)) & 1) * 2;
  int v1405 = v1404[v1514];
  int v1515 = ((((int)((unsigned int)((int)((unsigned int)(v1403 + 4) >> 2)) >> 1)) & 1) * 2) + 1;
  int v1406 = v1404[v1515];
  int v1516 = 4 + ((((int)((unsigned int)((int)((unsigned int)(v1403 + 4) >> 2)) >> 1)) & 3) * 2);
  int v1407 = v1404[v1516];
  int v1517 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v1403 + 4) >> 2)) >> 1)) & 3) * 2)) + 1;
  int v1408 = v1404[v1517];
  int v1409 = v1399->timer;
  int v1518 = v1409 + ((100 ^ (((~(((v1407 ^ ((int)((unsigned int)((int)((unsigned int)(v1403 + 4) >> 2)) >> 1))) | (-(v1407 ^ ((int)((unsigned int)((int)((unsigned int)(v1403 + 4) >> 2)) >> 1))))) >> 31)) | (~(((v1408 ^ ((int)((unsigned int)((int)((unsigned int)(v1403 + 4) >> 2)) >> 1))) | (-(v1408 ^ ((int)((unsigned int)((int)((unsigned int)(v1403 + 4) >> 2)) >> 1))))) >> 31))) & 104)) ^ (((~(((v1405 ^ ((int)((unsigned int)((int)((unsigned int)(v1403 + 4) >> 2)) >> 1))) | (-(v1405 ^ ((int)((unsigned int)((int)((unsigned int)(v1403 + 4) >> 2)) >> 1))))) >> 31)) | (~(((v1406 ^ ((int)((unsigned int)((int)((unsigned int)(v1403 + 4) >> 2)) >> 1))) | (-(v1406 ^ ((int)((unsigned int)((int)((unsigned int)(v1403 + 4) >> 2)) >> 1))))) >> 31))) & (1 ^ (100 ^ (((~(((v1407 ^ ((int)((unsigned int)((int)((unsigned int)(v1403 + 4) >> 2)) >> 1))) | (-(v1407 ^ ((int)((unsigned int)((int)((unsigned int)(v1403 + 4) >> 2)) >> 1))))) >> 31)) | (~(((v1408 ^ ((int)((unsigned int)((int)((unsigned int)(v1403 + 4) >> 2)) >> 1))) | (-(v1408 ^ ((int)((unsigned int)((int)((unsigned int)(v1403 + 4) >> 2)) >> 1))))) >> 31))) & 104)))));
  v1399->timer = v1518;
  int * v1411 = v1399->cache_vals;
  bool v1519 = !(((~(((v1405 ^ ((int)((unsigned int)((int)((unsigned int)(v1403 + 4) >> 2)) >> 1))) | (-(v1405 ^ ((int)((unsigned int)((int)((unsigned int)(v1403 + 4) >> 2)) >> 1))))) >> 31)) | (~(((v1406 ^ ((int)((unsigned int)((int)((unsigned int)(v1403 + 4) >> 2)) >> 1))) | (-(v1406 ^ ((int)((unsigned int)((int)((unsigned int)(v1403 + 4) >> 2)) >> 1))))) >> 31))) == 0);
  int v1504;
  if (v1519) {
    int * v1412 = v1399->cache_age;
    int v1521 = ((((int)((unsigned int)((int)((unsigned int)(v1403 + 4) >> 2)) >> 1)) & 1) * 2) + ((~(((v1406 ^ ((int)((unsigned int)((int)((unsigned int)(v1403 + 4) >> 2)) >> 1))) | (-(v1406 ^ ((int)((unsigned int)((int)((unsigned int)(v1403 + 4) >> 2)) >> 1))))) >> 31)) & 1);
    int v1413 = v1412[v1521];
    int v1414 = v1412[v1514];
    int v1522 = v1414 + ((int)((unsigned int)(v1414 - v1413) >> 31));
    v1412[v1514] = v1522;
    int * v1416 = v1399->cache_age;
    int v1417 = v1416[v1515];
    int v1524 = v1417 + ((int)((unsigned int)(v1417 - v1413) >> 31));
    v1416[v1515] = v1524;
    int * v1419 = v1399->cache_age;
    v1419[v1521] = 0;
    v1504 = v1521;
  } else {
    int * v1422 = v1399->cache_age;
    int v1528 = (((int)((unsigned int)((int)((unsigned int)(v1403 + 4) >> 2)) >> 1)) & 1) * 2;
    int v1423 = v1422[v1528];
    int * v1424 = v1399->cache_tags;
    int v1425 = v1424[v1528];
    int v1426 = v1422[v1515];
    int v1427 = v1424[v1515];
    bool v1530 = !(((~(((v1407 ^ ((int)((unsigned int)((int)((unsigned int)(v1403 + 4) >> 2)) >> 1))) | (-(v1407 ^ ((int)((unsigned int)((int)((unsigned int)(v1403 + 4) >> 2)) >> 1))))) >> 31)) | (~(((v1408 ^ ((int)((unsigned int)((int)((unsigned int)(v1403 + 4) >> 2)) >> 1))) | (-(v1408 ^ ((int)((unsigned int)((int)((unsigned int)(v1403 + 4) >> 2)) >> 1))))) >> 31))) == 0);
    int v1481;
    if (v1530) {
      int * v1428 = v1399->cache_age;
      int v1532 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v1403 + 4) >> 2)) >> 1)) & 3) * 2)) + ((~(((v1408 ^ ((int)((unsigned int)((int)((unsigned int)(v1403 + 4) >> 2)) >> 1))) | (-(v1408 ^ ((int)((unsigned int)((int)((unsigned int)(v1403 + 4) >> 2)) >> 1))))) >> 31)) & 1);
      int v1429 = v1428[v1532];
      int v1430 = v1428[v1516];
      int v1533 = v1430 + ((int)((unsigned int)(v1430 - v1429) >> 31));
      v1428[v1516] = v1533;
      int * v1432 = v1399->cache_age;
      int v1433 = v1432[v1517];
      int v1535 = v1433 + ((int)((unsigned int)(v1433 - v1429) >> 31));
      v1432[v1517] = v1535;
      int * v1435 = v1399->cache_age;
      v1435[v1532] = 0;
      v1481 = v1532;
    } else {
      int * v1438 = v1399->cache_age;
      int v1539 = 4 + ((((int)((unsigned int)((int)((unsigned int)(v1403 + 4) >> 2)) >> 1)) & 3) * 2);
      int v1439 = v1438[v1539];
      int * v1440 = v1399->cache_tags;
      int v1441 = v1440[v1539];
      int v1442 = v1438[v1517];
      int v1443 = v1440[v1517];
      int * v1444 = v1399->cache_dirty;
      int v1542 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v1403 + 4) >> 2)) >> 1)) & 3) * 2)) + ((((v1439 + ((~(((v1441 ^ -1) | (-(v1441 ^ -1))) >> 31)) & 2)) - (v1442 + ((~(((v1443 ^ -1) | (-(v1443 ^ -1))) >> 31)) & 2))) >> 31) & 1);
      int v1445 = v1444[v1542];
      bool v1543 = !(v1445 == 0);
      if (v1543) {
        int * v1446 = v1399->cache_tags;
        int v1447 = v1446[v1542];
        int * v1448 = v1399->cache_vals;
        int v1546 = ((4 + ((((int)((unsigned int)((int)((unsigned int)(v1403 + 4) >> 2)) >> 1)) & 3) * 2)) + ((((v1439 + ((~(((v1441 ^ -1) | (-(v1441 ^ -1))) >> 31)) & 2)) - (v1442 + ((~(((v1443 ^ -1) | (-(v1443 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
        int v1449 = v1448[v1546];
        int v1547 = (((4 + ((((int)((unsigned int)((int)((unsigned int)(v1403 + 4) >> 2)) >> 1)) & 3) * 2)) + ((((v1439 + ((~(((v1441 ^ -1) | (-(v1441 ^ -1))) >> 31)) & 2)) - (v1442 + ((~(((v1443 ^ -1) | (-(v1443 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
        int v1450 = v1448[v1547];
        int * v1451 = v1399->mem;
        int v1549 = v1447 * 2;
        v1451[v1549] = v1449;
        int * v1453 = v1399->mem;
        int v1552 = (v1447 * 2) + 1;
        v1453[v1552] = v1450;
        ;
      } else {
        ;
      }
      int * v1458 = v1399->mem;
      int v1557 = ((int)((unsigned int)((int)((unsigned int)(v1403 + 4) >> 2)) >> 1)) * 2;
      int v1459 = v1458[v1557];
      int v1558 = (((int)((unsigned int)((int)((unsigned int)(v1403 + 4) >> 2)) >> 1)) * 2) + 1;
      int v1460 = v1458[v1558];
      int * v1461 = v1399->cache_vals;
      int v1560 = ((4 + ((((int)((unsigned int)((int)((unsigned int)(v1403 + 4) >> 2)) >> 1)) & 3) * 2)) + ((((v1439 + ((~(((v1441 ^ -1) | (-(v1441 ^ -1))) >> 31)) & 2)) - (v1442 + ((~(((v1443 ^ -1) | (-(v1443 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
      v1461[v1560] = v1459;
      int * v1463 = v1399->cache_vals;
      int v1563 = (((4 + ((((int)((unsigned int)((int)((unsigned int)(v1403 + 4) >> 2)) >> 1)) & 3) * 2)) + ((((v1439 + ((~(((v1441 ^ -1) | (-(v1441 ^ -1))) >> 31)) & 2)) - (v1442 + ((~(((v1443 ^ -1) | (-(v1443 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
      v1463[v1563] = v1460;
      int * v1465 = v1399->cache_tags;
      int v1566 = (int)((unsigned int)((int)((unsigned int)(v1403 + 4) >> 2)) >> 1);
      v1465[v1542] = v1566;
      int * v1467 = v1399->cache_dirty;
      v1467[v1542] = 0;
      int * v1469 = v1399->cache_age;
      v1469[v1542] = 1;
      int * v1471 = v1399->cache_age;
      int v1472 = v1471[v1542];
      int v1473 = v1471[v1516];
      int v1572 = v1473 + ((int)((unsigned int)(v1473 - v1472) >> 31));
      v1471[v1516] = v1572;
      int * v1475 = v1399->cache_age;
      int v1476 = v1475[v1517];
      int v1574 = v1476 + ((int)((unsigned int)(v1476 - v1472) >> 31));
      v1475[v1517] = v1574;
      int * v1478 = v1399->cache_age;
      v1478[v1542] = 0;
      v1481 = v1542;
    }
    int * v1482 = v1399->cache_vals;
    int v1577 = v1481 * 2;
    int v1483 = v1482[v1577];
    int v1578 = (v1481 * 2) + 1;
    int v1484 = v1482[v1578];
    int v1579 = (((((int)((unsigned int)((int)((unsigned int)(v1403 + 4) >> 2)) >> 1)) & 1) * 2) + ((((v1423 + ((~(((v1425 ^ -1) | (-(v1425 ^ -1))) >> 31)) & 2)) - (v1426 + ((~(((v1427 ^ -1) | (-(v1427 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
    v1482[v1579] = v1483;
    int * v1486 = v1399->cache_vals;
    int v1582 = ((((((int)((unsigned int)((int)((unsigned int)(v1403 + 4) >> 2)) >> 1)) & 1) * 2) + ((((v1423 + ((~(((v1425 ^ -1) | (-(v1425 ^ -1))) >> 31)) & 2)) - (v1426 + ((~(((v1427 ^ -1) | (-(v1427 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
    v1486[v1582] = v1484;
    int * v1488 = v1399->cache_tags;
    int v1585 = ((((int)((unsigned int)((int)((unsigned int)(v1403 + 4) >> 2)) >> 1)) & 1) * 2) + ((((v1423 + ((~(((v1425 ^ -1) | (-(v1425 ^ -1))) >> 31)) & 2)) - (v1426 + ((~(((v1427 ^ -1) | (-(v1427 ^ -1))) >> 31)) & 2))) >> 31) & 1);
    int v1586 = (int)((unsigned int)((int)((unsigned int)(v1403 + 4) >> 2)) >> 1);
    v1488[v1585] = v1586;
    int * v1490 = v1399->cache_dirty;
    v1490[v1585] = 0;
    int * v1492 = v1399->cache_age;
    v1492[v1585] = 1;
    int * v1494 = v1399->cache_age;
    int v1495 = v1494[v1585];
    int v1496 = v1494[v1514];
    int v1592 = v1496 + ((int)((unsigned int)(v1496 - v1495) >> 31));
    v1494[v1514] = v1592;
    int * v1498 = v1399->cache_age;
    int v1499 = v1498[v1515];
    int v1594 = v1499 + ((int)((unsigned int)(v1499 - v1495) >> 31));
    v1498[v1515] = v1594;
    int * v1501 = v1399->cache_age;
    v1501[v1585] = 0;
    v1504 = v1585;
  }
  int v1597 = (v1504 * 2) + (((int)((unsigned int)(v1403 + 4) >> 2)) & 1);
  int v1505 = v1411[v1597];
  int * v1506 = v1399->regs;
  v1506[10] = v1505;
  struct StateT * v1508 = slot_22(v1399);
  return v1508;
}

struct StateT * slot_3(struct StateT * v226) {
  int * v227 = v226->saved_regs;
  int * v228 = v226->regs;
  int v229 = v228[10];
  v227[10] = v229;
  int v231 = v226->timer;
  int v242 = v231 + 1;
  v226->timer = v242;
  int * v233 = v226->regs;
  int v234 = v233[10];
  int v244 = v234 << 2;
  v233[10] = v244;
  struct StateT * v236 = slot_4(v226);
  return v236;
}

struct StateT * slot_10(struct StateT * v527) {
  int * v528 = v527->saved_regs;
  int * v529 = v527->regs;
  int v530 = v529[12];
  v528[12] = v530;
  int v532 = v527->timer;
  int v542 = v532 + 1;
  v527->timer = v542;
  int * v534 = v527->regs;
  v534[12] = 0;
  struct StateT * v536 = slot_11(v527);
  return v536;
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

struct StateT * slot_19(struct StateT * v1071) {
  int v1072 = v1071->timer;
  int v1242 = v1072 + 1;
  v1071->timer = v1242;
  int * v1074 = v1071->regs;
  int v1075 = v1074[12];
  int v1076 = v1074[10];
  int * v1077 = v1071->cache_tags;
  int v1247 = (((int)((unsigned int)((int)((unsigned int)(v1075 + 68) >> 2)) >> 1)) & 1) * 2;
  int v1078 = v1077[v1247];
  int v1248 = ((((int)((unsigned int)((int)((unsigned int)(v1075 + 68) >> 2)) >> 1)) & 1) * 2) + 1;
  int v1079 = v1077[v1248];
  int v1249 = 4 + ((((int)((unsigned int)((int)((unsigned int)(v1075 + 68) >> 2)) >> 1)) & 3) * 2);
  int v1080 = v1077[v1249];
  int v1250 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v1075 + 68) >> 2)) >> 1)) & 3) * 2)) + 1;
  int v1081 = v1077[v1250];
  int v1082 = v1071->timer;
  int v1251 = v1082 + ((100 ^ (((~(((v1080 ^ ((int)((unsigned int)((int)((unsigned int)(v1075 + 68) >> 2)) >> 1))) | (-(v1080 ^ ((int)((unsigned int)((int)((unsigned int)(v1075 + 68) >> 2)) >> 1))))) >> 31)) | (~(((v1081 ^ ((int)((unsigned int)((int)((unsigned int)(v1075 + 68) >> 2)) >> 1))) | (-(v1081 ^ ((int)((unsigned int)((int)((unsigned int)(v1075 + 68) >> 2)) >> 1))))) >> 31))) & 104)) ^ (((~(((v1078 ^ ((int)((unsigned int)((int)((unsigned int)(v1075 + 68) >> 2)) >> 1))) | (-(v1078 ^ ((int)((unsigned int)((int)((unsigned int)(v1075 + 68) >> 2)) >> 1))))) >> 31)) | (~(((v1079 ^ ((int)((unsigned int)((int)((unsigned int)(v1075 + 68) >> 2)) >> 1))) | (-(v1079 ^ ((int)((unsigned int)((int)((unsigned int)(v1075 + 68) >> 2)) >> 1))))) >> 31))) & (1 ^ (100 ^ (((~(((v1080 ^ ((int)((unsigned int)((int)((unsigned int)(v1075 + 68) >> 2)) >> 1))) | (-(v1080 ^ ((int)((unsigned int)((int)((unsigned int)(v1075 + 68) >> 2)) >> 1))))) >> 31)) | (~(((v1081 ^ ((int)((unsigned int)((int)((unsigned int)(v1075 + 68) >> 2)) >> 1))) | (-(v1081 ^ ((int)((unsigned int)((int)((unsigned int)(v1075 + 68) >> 2)) >> 1))))) >> 31))) & 104)))));
  v1071->timer = v1251;
  bool v1252 = !(((~(((v1078 ^ ((int)((unsigned int)((int)((unsigned int)(v1075 + 68) >> 2)) >> 1))) | (-(v1078 ^ ((int)((unsigned int)((int)((unsigned int)(v1075 + 68) >> 2)) >> 1))))) >> 31)) | (~(((v1079 ^ ((int)((unsigned int)((int)((unsigned int)(v1075 + 68) >> 2)) >> 1))) | (-(v1079 ^ ((int)((unsigned int)((int)((unsigned int)(v1075 + 68) >> 2)) >> 1))))) >> 31))) == 0);
  int v1176;
  if (v1252) {
    int * v1084 = v1071->cache_age;
    int v1254 = ((((int)((unsigned int)((int)((unsigned int)(v1075 + 68) >> 2)) >> 1)) & 1) * 2) + ((~(((v1079 ^ ((int)((unsigned int)((int)((unsigned int)(v1075 + 68) >> 2)) >> 1))) | (-(v1079 ^ ((int)((unsigned int)((int)((unsigned int)(v1075 + 68) >> 2)) >> 1))))) >> 31)) & 1);
    int v1085 = v1084[v1254];
    int v1086 = v1084[v1247];
    int v1255 = v1086 + ((int)((unsigned int)(v1086 - v1085) >> 31));
    v1084[v1247] = v1255;
    int * v1088 = v1071->cache_age;
    int v1089 = v1088[v1248];
    int v1257 = v1089 + ((int)((unsigned int)(v1089 - v1085) >> 31));
    v1088[v1248] = v1257;
    int * v1091 = v1071->cache_age;
    v1091[v1254] = 0;
    v1176 = v1254;
  } else {
    int * v1094 = v1071->cache_age;
    int v1261 = (((int)((unsigned int)((int)((unsigned int)(v1075 + 68) >> 2)) >> 1)) & 1) * 2;
    int v1095 = v1094[v1261];
    int * v1096 = v1071->cache_tags;
    int v1097 = v1096[v1261];
    int v1098 = v1094[v1248];
    int v1099 = v1096[v1248];
    bool v1263 = !(((~(((v1080 ^ ((int)((unsigned int)((int)((unsigned int)(v1075 + 68) >> 2)) >> 1))) | (-(v1080 ^ ((int)((unsigned int)((int)((unsigned int)(v1075 + 68) >> 2)) >> 1))))) >> 31)) | (~(((v1081 ^ ((int)((unsigned int)((int)((unsigned int)(v1075 + 68) >> 2)) >> 1))) | (-(v1081 ^ ((int)((unsigned int)((int)((unsigned int)(v1075 + 68) >> 2)) >> 1))))) >> 31))) == 0);
    int v1153;
    if (v1263) {
      int * v1100 = v1071->cache_age;
      int v1265 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v1075 + 68) >> 2)) >> 1)) & 3) * 2)) + ((~(((v1081 ^ ((int)((unsigned int)((int)((unsigned int)(v1075 + 68) >> 2)) >> 1))) | (-(v1081 ^ ((int)((unsigned int)((int)((unsigned int)(v1075 + 68) >> 2)) >> 1))))) >> 31)) & 1);
      int v1101 = v1100[v1265];
      int v1102 = v1100[v1249];
      int v1266 = v1102 + ((int)((unsigned int)(v1102 - v1101) >> 31));
      v1100[v1249] = v1266;
      int * v1104 = v1071->cache_age;
      int v1105 = v1104[v1250];
      int v1268 = v1105 + ((int)((unsigned int)(v1105 - v1101) >> 31));
      v1104[v1250] = v1268;
      int * v1107 = v1071->cache_age;
      v1107[v1265] = 0;
      v1153 = v1265;
    } else {
      int * v1110 = v1071->cache_age;
      int v1272 = 4 + ((((int)((unsigned int)((int)((unsigned int)(v1075 + 68) >> 2)) >> 1)) & 3) * 2);
      int v1111 = v1110[v1272];
      int * v1112 = v1071->cache_tags;
      int v1113 = v1112[v1272];
      int v1114 = v1110[v1250];
      int v1115 = v1112[v1250];
      int * v1116 = v1071->cache_dirty;
      int v1275 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v1075 + 68) >> 2)) >> 1)) & 3) * 2)) + ((((v1111 + ((~(((v1113 ^ -1) | (-(v1113 ^ -1))) >> 31)) & 2)) - (v1114 + ((~(((v1115 ^ -1) | (-(v1115 ^ -1))) >> 31)) & 2))) >> 31) & 1);
      int v1117 = v1116[v1275];
      bool v1276 = !(v1117 == 0);
      if (v1276) {
        int * v1118 = v1071->cache_tags;
        int v1119 = v1118[v1275];
        int * v1120 = v1071->cache_vals;
        int v1279 = ((4 + ((((int)((unsigned int)((int)((unsigned int)(v1075 + 68) >> 2)) >> 1)) & 3) * 2)) + ((((v1111 + ((~(((v1113 ^ -1) | (-(v1113 ^ -1))) >> 31)) & 2)) - (v1114 + ((~(((v1115 ^ -1) | (-(v1115 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
        int v1121 = v1120[v1279];
        int v1280 = (((4 + ((((int)((unsigned int)((int)((unsigned int)(v1075 + 68) >> 2)) >> 1)) & 3) * 2)) + ((((v1111 + ((~(((v1113 ^ -1) | (-(v1113 ^ -1))) >> 31)) & 2)) - (v1114 + ((~(((v1115 ^ -1) | (-(v1115 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
        int v1122 = v1120[v1280];
        int * v1123 = v1071->mem;
        int v1282 = v1119 * 2;
        v1123[v1282] = v1121;
        int * v1125 = v1071->mem;
        int v1285 = (v1119 * 2) + 1;
        v1125[v1285] = v1122;
        ;
      } else {
        ;
      }
      int * v1130 = v1071->mem;
      int v1290 = ((int)((unsigned int)((int)((unsigned int)(v1075 + 68) >> 2)) >> 1)) * 2;
      int v1131 = v1130[v1290];
      int v1291 = (((int)((unsigned int)((int)((unsigned int)(v1075 + 68) >> 2)) >> 1)) * 2) + 1;
      int v1132 = v1130[v1291];
      int * v1133 = v1071->cache_vals;
      int v1293 = ((4 + ((((int)((unsigned int)((int)((unsigned int)(v1075 + 68) >> 2)) >> 1)) & 3) * 2)) + ((((v1111 + ((~(((v1113 ^ -1) | (-(v1113 ^ -1))) >> 31)) & 2)) - (v1114 + ((~(((v1115 ^ -1) | (-(v1115 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
      v1133[v1293] = v1131;
      int * v1135 = v1071->cache_vals;
      int v1296 = (((4 + ((((int)((unsigned int)((int)((unsigned int)(v1075 + 68) >> 2)) >> 1)) & 3) * 2)) + ((((v1111 + ((~(((v1113 ^ -1) | (-(v1113 ^ -1))) >> 31)) & 2)) - (v1114 + ((~(((v1115 ^ -1) | (-(v1115 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
      v1135[v1296] = v1132;
      int * v1137 = v1071->cache_tags;
      int v1299 = (int)((unsigned int)((int)((unsigned int)(v1075 + 68) >> 2)) >> 1);
      v1137[v1275] = v1299;
      int * v1139 = v1071->cache_dirty;
      v1139[v1275] = 0;
      int * v1141 = v1071->cache_age;
      v1141[v1275] = 1;
      int * v1143 = v1071->cache_age;
      int v1144 = v1143[v1275];
      int v1145 = v1143[v1249];
      int v1305 = v1145 + ((int)((unsigned int)(v1145 - v1144) >> 31));
      v1143[v1249] = v1305;
      int * v1147 = v1071->cache_age;
      int v1148 = v1147[v1250];
      int v1307 = v1148 + ((int)((unsigned int)(v1148 - v1144) >> 31));
      v1147[v1250] = v1307;
      int * v1150 = v1071->cache_age;
      v1150[v1275] = 0;
      v1153 = v1275;
    }
    int * v1154 = v1071->cache_vals;
    int v1310 = v1153 * 2;
    int v1155 = v1154[v1310];
    int v1311 = (v1153 * 2) + 1;
    int v1156 = v1154[v1311];
    int v1312 = (((((int)((unsigned int)((int)((unsigned int)(v1075 + 68) >> 2)) >> 1)) & 1) * 2) + ((((v1095 + ((~(((v1097 ^ -1) | (-(v1097 ^ -1))) >> 31)) & 2)) - (v1098 + ((~(((v1099 ^ -1) | (-(v1099 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
    v1154[v1312] = v1155;
    int * v1158 = v1071->cache_vals;
    int v1315 = ((((((int)((unsigned int)((int)((unsigned int)(v1075 + 68) >> 2)) >> 1)) & 1) * 2) + ((((v1095 + ((~(((v1097 ^ -1) | (-(v1097 ^ -1))) >> 31)) & 2)) - (v1098 + ((~(((v1099 ^ -1) | (-(v1099 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
    v1158[v1315] = v1156;
    int * v1160 = v1071->cache_tags;
    int v1318 = ((((int)((unsigned int)((int)((unsigned int)(v1075 + 68) >> 2)) >> 1)) & 1) * 2) + ((((v1095 + ((~(((v1097 ^ -1) | (-(v1097 ^ -1))) >> 31)) & 2)) - (v1098 + ((~(((v1099 ^ -1) | (-(v1099 ^ -1))) >> 31)) & 2))) >> 31) & 1);
    int v1319 = (int)((unsigned int)((int)((unsigned int)(v1075 + 68) >> 2)) >> 1);
    v1160[v1318] = v1319;
    int * v1162 = v1071->cache_dirty;
    v1162[v1318] = 0;
    int * v1164 = v1071->cache_age;
    v1164[v1318] = 1;
    int * v1166 = v1071->cache_age;
    int v1167 = v1166[v1318];
    int v1168 = v1166[v1247];
    int v1325 = v1168 + ((int)((unsigned int)(v1168 - v1167) >> 31));
    v1166[v1247] = v1325;
    int * v1170 = v1071->cache_age;
    int v1171 = v1170[v1248];
    int v1327 = v1171 + ((int)((unsigned int)(v1171 - v1167) >> 31));
    v1170[v1248] = v1327;
    int * v1173 = v1071->cache_age;
    v1173[v1318] = 0;
    v1176 = v1318;
  }
  int * v1177 = v1071->cache_vals;
  int v1330 = (v1176 * 2) + (((int)((unsigned int)(v1075 + 68) >> 2)) & 1);
  v1177[v1330] = v1076;
  int * v1179 = v1071->cache_tags;
  int v1180 = v1179[v1249];
  int v1181 = v1179[v1250];
  bool v1333 = !(((~(((v1180 ^ ((int)((unsigned int)((int)((unsigned int)(v1075 + 68) >> 2)) >> 1))) | (-(v1180 ^ ((int)((unsigned int)((int)((unsigned int)(v1075 + 68) >> 2)) >> 1))))) >> 31)) | (~(((v1181 ^ ((int)((unsigned int)((int)((unsigned int)(v1075 + 68) >> 2)) >> 1))) | (-(v1181 ^ ((int)((unsigned int)((int)((unsigned int)(v1075 + 68) >> 2)) >> 1))))) >> 31))) == 0);
  int v1235;
  if (v1333) {
    int * v1182 = v1071->cache_age;
    int v1335 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v1075 + 68) >> 2)) >> 1)) & 3) * 2)) + ((~(((v1181 ^ ((int)((unsigned int)((int)((unsigned int)(v1075 + 68) >> 2)) >> 1))) | (-(v1181 ^ ((int)((unsigned int)((int)((unsigned int)(v1075 + 68) >> 2)) >> 1))))) >> 31)) & 1);
    int v1183 = v1182[v1335];
    int v1184 = v1182[v1249];
    int v1336 = v1184 + ((int)((unsigned int)(v1184 - v1183) >> 31));
    v1182[v1249] = v1336;
    int * v1186 = v1071->cache_age;
    int v1187 = v1186[v1250];
    int v1338 = v1187 + ((int)((unsigned int)(v1187 - v1183) >> 31));
    v1186[v1250] = v1338;
    int * v1189 = v1071->cache_age;
    v1189[v1335] = 0;
    v1235 = v1335;
  } else {
    int * v1192 = v1071->cache_age;
    int v1342 = 4 + ((((int)((unsigned int)((int)((unsigned int)(v1075 + 68) >> 2)) >> 1)) & 3) * 2);
    int v1193 = v1192[v1342];
    int * v1194 = v1071->cache_tags;
    int v1195 = v1194[v1342];
    int v1196 = v1192[v1250];
    int v1197 = v1194[v1250];
    int * v1198 = v1071->cache_dirty;
    int v1345 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v1075 + 68) >> 2)) >> 1)) & 3) * 2)) + ((((v1193 + ((~(((v1195 ^ -1) | (-(v1195 ^ -1))) >> 31)) & 2)) - (v1196 + ((~(((v1197 ^ -1) | (-(v1197 ^ -1))) >> 31)) & 2))) >> 31) & 1);
    int v1199 = v1198[v1345];
    bool v1346 = !(v1199 == 0);
    if (v1346) {
      int * v1200 = v1071->cache_tags;
      int v1201 = v1200[v1345];
      int * v1202 = v1071->cache_vals;
      int v1349 = ((4 + ((((int)((unsigned int)((int)((unsigned int)(v1075 + 68) >> 2)) >> 1)) & 3) * 2)) + ((((v1193 + ((~(((v1195 ^ -1) | (-(v1195 ^ -1))) >> 31)) & 2)) - (v1196 + ((~(((v1197 ^ -1) | (-(v1197 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
      int v1203 = v1202[v1349];
      int v1350 = (((4 + ((((int)((unsigned int)((int)((unsigned int)(v1075 + 68) >> 2)) >> 1)) & 3) * 2)) + ((((v1193 + ((~(((v1195 ^ -1) | (-(v1195 ^ -1))) >> 31)) & 2)) - (v1196 + ((~(((v1197 ^ -1) | (-(v1197 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
      int v1204 = v1202[v1350];
      int * v1205 = v1071->mem;
      int v1352 = v1201 * 2;
      v1205[v1352] = v1203;
      int * v1207 = v1071->mem;
      int v1355 = (v1201 * 2) + 1;
      v1207[v1355] = v1204;
      ;
    } else {
      ;
    }
    int * v1212 = v1071->mem;
    int v1360 = ((int)((unsigned int)((int)((unsigned int)(v1075 + 68) >> 2)) >> 1)) * 2;
    int v1213 = v1212[v1360];
    int v1361 = (((int)((unsigned int)((int)((unsigned int)(v1075 + 68) >> 2)) >> 1)) * 2) + 1;
    int v1214 = v1212[v1361];
    int * v1215 = v1071->cache_vals;
    int v1363 = ((4 + ((((int)((unsigned int)((int)((unsigned int)(v1075 + 68) >> 2)) >> 1)) & 3) * 2)) + ((((v1193 + ((~(((v1195 ^ -1) | (-(v1195 ^ -1))) >> 31)) & 2)) - (v1196 + ((~(((v1197 ^ -1) | (-(v1197 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
    v1215[v1363] = v1213;
    int * v1217 = v1071->cache_vals;
    int v1366 = (((4 + ((((int)((unsigned int)((int)((unsigned int)(v1075 + 68) >> 2)) >> 1)) & 3) * 2)) + ((((v1193 + ((~(((v1195 ^ -1) | (-(v1195 ^ -1))) >> 31)) & 2)) - (v1196 + ((~(((v1197 ^ -1) | (-(v1197 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
    v1217[v1366] = v1214;
    int * v1219 = v1071->cache_tags;
    int v1369 = (int)((unsigned int)((int)((unsigned int)(v1075 + 68) >> 2)) >> 1);
    v1219[v1345] = v1369;
    int * v1221 = v1071->cache_dirty;
    v1221[v1345] = 0;
    int * v1223 = v1071->cache_age;
    v1223[v1345] = 1;
    int * v1225 = v1071->cache_age;
    int v1226 = v1225[v1345];
    int v1227 = v1225[v1249];
    int v1375 = v1227 + ((int)((unsigned int)(v1227 - v1226) >> 31));
    v1225[v1249] = v1375;
    int * v1229 = v1071->cache_age;
    int v1230 = v1229[v1250];
    int v1377 = v1230 + ((int)((unsigned int)(v1230 - v1226) >> 31));
    v1229[v1250] = v1377;
    int * v1232 = v1071->cache_age;
    v1232[v1345] = 0;
    v1235 = v1345;
  }
  int * v1236 = v1071->cache_vals;
  int v1380 = (v1235 * 2) + (((int)((unsigned int)(v1075 + 68) >> 2)) & 1);
  v1236[v1380] = v1076;
  int * v1238 = v1071->cache_dirty;
  v1238[v1235] = 1;
  struct StateT * v1240 = slot_18(v1071);
  return v1240;
}

struct StateT * slot_13(struct StateT * v575) {
  int v576 = v575->timer;
  int v584 = v576 + 1;
  v575->timer = v584;
  int * v578 = v575->regs;
  int v579 = v578[11];
  int v580 = v578[10];
  int v588 = v579 + v580;
  v578[10] = v588;
  struct StateT * v582 = slot_14(v575);
  return v582;
}

struct StateT * slot_24(struct StateT * v1822) {
  int v1823 = v1822->timer;
  int v1993 = v1823 + 1;
  v1822->timer = v1993;
  int * v1825 = v1822->regs;
  int v1826 = v1825[11];
  int v1827 = v1825[10];
  int * v1828 = v1822->cache_tags;
  int v1998 = (((int)((unsigned int)((int)((unsigned int)(v1826 + 68) >> 2)) >> 1)) & 1) * 2;
  int v1829 = v1828[v1998];
  int v1999 = ((((int)((unsigned int)((int)((unsigned int)(v1826 + 68) >> 2)) >> 1)) & 1) * 2) + 1;
  int v1830 = v1828[v1999];
  int v2000 = 4 + ((((int)((unsigned int)((int)((unsigned int)(v1826 + 68) >> 2)) >> 1)) & 3) * 2);
  int v1831 = v1828[v2000];
  int v2001 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v1826 + 68) >> 2)) >> 1)) & 3) * 2)) + 1;
  int v1832 = v1828[v2001];
  int v1833 = v1822->timer;
  int v2002 = v1833 + ((100 ^ (((~(((v1831 ^ ((int)((unsigned int)((int)((unsigned int)(v1826 + 68) >> 2)) >> 1))) | (-(v1831 ^ ((int)((unsigned int)((int)((unsigned int)(v1826 + 68) >> 2)) >> 1))))) >> 31)) | (~(((v1832 ^ ((int)((unsigned int)((int)((unsigned int)(v1826 + 68) >> 2)) >> 1))) | (-(v1832 ^ ((int)((unsigned int)((int)((unsigned int)(v1826 + 68) >> 2)) >> 1))))) >> 31))) & 104)) ^ (((~(((v1829 ^ ((int)((unsigned int)((int)((unsigned int)(v1826 + 68) >> 2)) >> 1))) | (-(v1829 ^ ((int)((unsigned int)((int)((unsigned int)(v1826 + 68) >> 2)) >> 1))))) >> 31)) | (~(((v1830 ^ ((int)((unsigned int)((int)((unsigned int)(v1826 + 68) >> 2)) >> 1))) | (-(v1830 ^ ((int)((unsigned int)((int)((unsigned int)(v1826 + 68) >> 2)) >> 1))))) >> 31))) & (1 ^ (100 ^ (((~(((v1831 ^ ((int)((unsigned int)((int)((unsigned int)(v1826 + 68) >> 2)) >> 1))) | (-(v1831 ^ ((int)((unsigned int)((int)((unsigned int)(v1826 + 68) >> 2)) >> 1))))) >> 31)) | (~(((v1832 ^ ((int)((unsigned int)((int)((unsigned int)(v1826 + 68) >> 2)) >> 1))) | (-(v1832 ^ ((int)((unsigned int)((int)((unsigned int)(v1826 + 68) >> 2)) >> 1))))) >> 31))) & 104)))));
  v1822->timer = v2002;
  bool v2003 = !(((~(((v1829 ^ ((int)((unsigned int)((int)((unsigned int)(v1826 + 68) >> 2)) >> 1))) | (-(v1829 ^ ((int)((unsigned int)((int)((unsigned int)(v1826 + 68) >> 2)) >> 1))))) >> 31)) | (~(((v1830 ^ ((int)((unsigned int)((int)((unsigned int)(v1826 + 68) >> 2)) >> 1))) | (-(v1830 ^ ((int)((unsigned int)((int)((unsigned int)(v1826 + 68) >> 2)) >> 1))))) >> 31))) == 0);
  int v1927;
  if (v2003) {
    int * v1835 = v1822->cache_age;
    int v2005 = ((((int)((unsigned int)((int)((unsigned int)(v1826 + 68) >> 2)) >> 1)) & 1) * 2) + ((~(((v1830 ^ ((int)((unsigned int)((int)((unsigned int)(v1826 + 68) >> 2)) >> 1))) | (-(v1830 ^ ((int)((unsigned int)((int)((unsigned int)(v1826 + 68) >> 2)) >> 1))))) >> 31)) & 1);
    int v1836 = v1835[v2005];
    int v1837 = v1835[v1998];
    int v2006 = v1837 + ((int)((unsigned int)(v1837 - v1836) >> 31));
    v1835[v1998] = v2006;
    int * v1839 = v1822->cache_age;
    int v1840 = v1839[v1999];
    int v2008 = v1840 + ((int)((unsigned int)(v1840 - v1836) >> 31));
    v1839[v1999] = v2008;
    int * v1842 = v1822->cache_age;
    v1842[v2005] = 0;
    v1927 = v2005;
  } else {
    int * v1845 = v1822->cache_age;
    int v2012 = (((int)((unsigned int)((int)((unsigned int)(v1826 + 68) >> 2)) >> 1)) & 1) * 2;
    int v1846 = v1845[v2012];
    int * v1847 = v1822->cache_tags;
    int v1848 = v1847[v2012];
    int v1849 = v1845[v1999];
    int v1850 = v1847[v1999];
    bool v2014 = !(((~(((v1831 ^ ((int)((unsigned int)((int)((unsigned int)(v1826 + 68) >> 2)) >> 1))) | (-(v1831 ^ ((int)((unsigned int)((int)((unsigned int)(v1826 + 68) >> 2)) >> 1))))) >> 31)) | (~(((v1832 ^ ((int)((unsigned int)((int)((unsigned int)(v1826 + 68) >> 2)) >> 1))) | (-(v1832 ^ ((int)((unsigned int)((int)((unsigned int)(v1826 + 68) >> 2)) >> 1))))) >> 31))) == 0);
    int v1904;
    if (v2014) {
      int * v1851 = v1822->cache_age;
      int v2016 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v1826 + 68) >> 2)) >> 1)) & 3) * 2)) + ((~(((v1832 ^ ((int)((unsigned int)((int)((unsigned int)(v1826 + 68) >> 2)) >> 1))) | (-(v1832 ^ ((int)((unsigned int)((int)((unsigned int)(v1826 + 68) >> 2)) >> 1))))) >> 31)) & 1);
      int v1852 = v1851[v2016];
      int v1853 = v1851[v2000];
      int v2017 = v1853 + ((int)((unsigned int)(v1853 - v1852) >> 31));
      v1851[v2000] = v2017;
      int * v1855 = v1822->cache_age;
      int v1856 = v1855[v2001];
      int v2019 = v1856 + ((int)((unsigned int)(v1856 - v1852) >> 31));
      v1855[v2001] = v2019;
      int * v1858 = v1822->cache_age;
      v1858[v2016] = 0;
      v1904 = v2016;
    } else {
      int * v1861 = v1822->cache_age;
      int v2023 = 4 + ((((int)((unsigned int)((int)((unsigned int)(v1826 + 68) >> 2)) >> 1)) & 3) * 2);
      int v1862 = v1861[v2023];
      int * v1863 = v1822->cache_tags;
      int v1864 = v1863[v2023];
      int v1865 = v1861[v2001];
      int v1866 = v1863[v2001];
      int * v1867 = v1822->cache_dirty;
      int v2026 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v1826 + 68) >> 2)) >> 1)) & 3) * 2)) + ((((v1862 + ((~(((v1864 ^ -1) | (-(v1864 ^ -1))) >> 31)) & 2)) - (v1865 + ((~(((v1866 ^ -1) | (-(v1866 ^ -1))) >> 31)) & 2))) >> 31) & 1);
      int v1868 = v1867[v2026];
      bool v2027 = !(v1868 == 0);
      if (v2027) {
        int * v1869 = v1822->cache_tags;
        int v1870 = v1869[v2026];
        int * v1871 = v1822->cache_vals;
        int v2030 = ((4 + ((((int)((unsigned int)((int)((unsigned int)(v1826 + 68) >> 2)) >> 1)) & 3) * 2)) + ((((v1862 + ((~(((v1864 ^ -1) | (-(v1864 ^ -1))) >> 31)) & 2)) - (v1865 + ((~(((v1866 ^ -1) | (-(v1866 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
        int v1872 = v1871[v2030];
        int v2031 = (((4 + ((((int)((unsigned int)((int)((unsigned int)(v1826 + 68) >> 2)) >> 1)) & 3) * 2)) + ((((v1862 + ((~(((v1864 ^ -1) | (-(v1864 ^ -1))) >> 31)) & 2)) - (v1865 + ((~(((v1866 ^ -1) | (-(v1866 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
        int v1873 = v1871[v2031];
        int * v1874 = v1822->mem;
        int v2033 = v1870 * 2;
        v1874[v2033] = v1872;
        int * v1876 = v1822->mem;
        int v2036 = (v1870 * 2) + 1;
        v1876[v2036] = v1873;
        ;
      } else {
        ;
      }
      int * v1881 = v1822->mem;
      int v2041 = ((int)((unsigned int)((int)((unsigned int)(v1826 + 68) >> 2)) >> 1)) * 2;
      int v1882 = v1881[v2041];
      int v2042 = (((int)((unsigned int)((int)((unsigned int)(v1826 + 68) >> 2)) >> 1)) * 2) + 1;
      int v1883 = v1881[v2042];
      int * v1884 = v1822->cache_vals;
      int v2044 = ((4 + ((((int)((unsigned int)((int)((unsigned int)(v1826 + 68) >> 2)) >> 1)) & 3) * 2)) + ((((v1862 + ((~(((v1864 ^ -1) | (-(v1864 ^ -1))) >> 31)) & 2)) - (v1865 + ((~(((v1866 ^ -1) | (-(v1866 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
      v1884[v2044] = v1882;
      int * v1886 = v1822->cache_vals;
      int v2047 = (((4 + ((((int)((unsigned int)((int)((unsigned int)(v1826 + 68) >> 2)) >> 1)) & 3) * 2)) + ((((v1862 + ((~(((v1864 ^ -1) | (-(v1864 ^ -1))) >> 31)) & 2)) - (v1865 + ((~(((v1866 ^ -1) | (-(v1866 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
      v1886[v2047] = v1883;
      int * v1888 = v1822->cache_tags;
      int v2050 = (int)((unsigned int)((int)((unsigned int)(v1826 + 68) >> 2)) >> 1);
      v1888[v2026] = v2050;
      int * v1890 = v1822->cache_dirty;
      v1890[v2026] = 0;
      int * v1892 = v1822->cache_age;
      v1892[v2026] = 1;
      int * v1894 = v1822->cache_age;
      int v1895 = v1894[v2026];
      int v1896 = v1894[v2000];
      int v2056 = v1896 + ((int)((unsigned int)(v1896 - v1895) >> 31));
      v1894[v2000] = v2056;
      int * v1898 = v1822->cache_age;
      int v1899 = v1898[v2001];
      int v2058 = v1899 + ((int)((unsigned int)(v1899 - v1895) >> 31));
      v1898[v2001] = v2058;
      int * v1901 = v1822->cache_age;
      v1901[v2026] = 0;
      v1904 = v2026;
    }
    int * v1905 = v1822->cache_vals;
    int v2061 = v1904 * 2;
    int v1906 = v1905[v2061];
    int v2062 = (v1904 * 2) + 1;
    int v1907 = v1905[v2062];
    int v2063 = (((((int)((unsigned int)((int)((unsigned int)(v1826 + 68) >> 2)) >> 1)) & 1) * 2) + ((((v1846 + ((~(((v1848 ^ -1) | (-(v1848 ^ -1))) >> 31)) & 2)) - (v1849 + ((~(((v1850 ^ -1) | (-(v1850 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
    v1905[v2063] = v1906;
    int * v1909 = v1822->cache_vals;
    int v2066 = ((((((int)((unsigned int)((int)((unsigned int)(v1826 + 68) >> 2)) >> 1)) & 1) * 2) + ((((v1846 + ((~(((v1848 ^ -1) | (-(v1848 ^ -1))) >> 31)) & 2)) - (v1849 + ((~(((v1850 ^ -1) | (-(v1850 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
    v1909[v2066] = v1907;
    int * v1911 = v1822->cache_tags;
    int v2069 = ((((int)((unsigned int)((int)((unsigned int)(v1826 + 68) >> 2)) >> 1)) & 1) * 2) + ((((v1846 + ((~(((v1848 ^ -1) | (-(v1848 ^ -1))) >> 31)) & 2)) - (v1849 + ((~(((v1850 ^ -1) | (-(v1850 ^ -1))) >> 31)) & 2))) >> 31) & 1);
    int v2070 = (int)((unsigned int)((int)((unsigned int)(v1826 + 68) >> 2)) >> 1);
    v1911[v2069] = v2070;
    int * v1913 = v1822->cache_dirty;
    v1913[v2069] = 0;
    int * v1915 = v1822->cache_age;
    v1915[v2069] = 1;
    int * v1917 = v1822->cache_age;
    int v1918 = v1917[v2069];
    int v1919 = v1917[v1998];
    int v2076 = v1919 + ((int)((unsigned int)(v1919 - v1918) >> 31));
    v1917[v1998] = v2076;
    int * v1921 = v1822->cache_age;
    int v1922 = v1921[v1999];
    int v2078 = v1922 + ((int)((unsigned int)(v1922 - v1918) >> 31));
    v1921[v1999] = v2078;
    int * v1924 = v1822->cache_age;
    v1924[v2069] = 0;
    v1927 = v2069;
  }
  int * v1928 = v1822->cache_vals;
  int v2081 = (v1927 * 2) + (((int)((unsigned int)(v1826 + 68) >> 2)) & 1);
  v1928[v2081] = v1827;
  int * v1930 = v1822->cache_tags;
  int v1931 = v1930[v2000];
  int v1932 = v1930[v2001];
  bool v2084 = !(((~(((v1931 ^ ((int)((unsigned int)((int)((unsigned int)(v1826 + 68) >> 2)) >> 1))) | (-(v1931 ^ ((int)((unsigned int)((int)((unsigned int)(v1826 + 68) >> 2)) >> 1))))) >> 31)) | (~(((v1932 ^ ((int)((unsigned int)((int)((unsigned int)(v1826 + 68) >> 2)) >> 1))) | (-(v1932 ^ ((int)((unsigned int)((int)((unsigned int)(v1826 + 68) >> 2)) >> 1))))) >> 31))) == 0);
  int v1986;
  if (v2084) {
    int * v1933 = v1822->cache_age;
    int v2086 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v1826 + 68) >> 2)) >> 1)) & 3) * 2)) + ((~(((v1932 ^ ((int)((unsigned int)((int)((unsigned int)(v1826 + 68) >> 2)) >> 1))) | (-(v1932 ^ ((int)((unsigned int)((int)((unsigned int)(v1826 + 68) >> 2)) >> 1))))) >> 31)) & 1);
    int v1934 = v1933[v2086];
    int v1935 = v1933[v2000];
    int v2087 = v1935 + ((int)((unsigned int)(v1935 - v1934) >> 31));
    v1933[v2000] = v2087;
    int * v1937 = v1822->cache_age;
    int v1938 = v1937[v2001];
    int v2089 = v1938 + ((int)((unsigned int)(v1938 - v1934) >> 31));
    v1937[v2001] = v2089;
    int * v1940 = v1822->cache_age;
    v1940[v2086] = 0;
    v1986 = v2086;
  } else {
    int * v1943 = v1822->cache_age;
    int v2093 = 4 + ((((int)((unsigned int)((int)((unsigned int)(v1826 + 68) >> 2)) >> 1)) & 3) * 2);
    int v1944 = v1943[v2093];
    int * v1945 = v1822->cache_tags;
    int v1946 = v1945[v2093];
    int v1947 = v1943[v2001];
    int v1948 = v1945[v2001];
    int * v1949 = v1822->cache_dirty;
    int v2096 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v1826 + 68) >> 2)) >> 1)) & 3) * 2)) + ((((v1944 + ((~(((v1946 ^ -1) | (-(v1946 ^ -1))) >> 31)) & 2)) - (v1947 + ((~(((v1948 ^ -1) | (-(v1948 ^ -1))) >> 31)) & 2))) >> 31) & 1);
    int v1950 = v1949[v2096];
    bool v2097 = !(v1950 == 0);
    if (v2097) {
      int * v1951 = v1822->cache_tags;
      int v1952 = v1951[v2096];
      int * v1953 = v1822->cache_vals;
      int v2100 = ((4 + ((((int)((unsigned int)((int)((unsigned int)(v1826 + 68) >> 2)) >> 1)) & 3) * 2)) + ((((v1944 + ((~(((v1946 ^ -1) | (-(v1946 ^ -1))) >> 31)) & 2)) - (v1947 + ((~(((v1948 ^ -1) | (-(v1948 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
      int v1954 = v1953[v2100];
      int v2101 = (((4 + ((((int)((unsigned int)((int)((unsigned int)(v1826 + 68) >> 2)) >> 1)) & 3) * 2)) + ((((v1944 + ((~(((v1946 ^ -1) | (-(v1946 ^ -1))) >> 31)) & 2)) - (v1947 + ((~(((v1948 ^ -1) | (-(v1948 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
      int v1955 = v1953[v2101];
      int * v1956 = v1822->mem;
      int v2103 = v1952 * 2;
      v1956[v2103] = v1954;
      int * v1958 = v1822->mem;
      int v2106 = (v1952 * 2) + 1;
      v1958[v2106] = v1955;
      ;
    } else {
      ;
    }
    int * v1963 = v1822->mem;
    int v2111 = ((int)((unsigned int)((int)((unsigned int)(v1826 + 68) >> 2)) >> 1)) * 2;
    int v1964 = v1963[v2111];
    int v2112 = (((int)((unsigned int)((int)((unsigned int)(v1826 + 68) >> 2)) >> 1)) * 2) + 1;
    int v1965 = v1963[v2112];
    int * v1966 = v1822->cache_vals;
    int v2114 = ((4 + ((((int)((unsigned int)((int)((unsigned int)(v1826 + 68) >> 2)) >> 1)) & 3) * 2)) + ((((v1944 + ((~(((v1946 ^ -1) | (-(v1946 ^ -1))) >> 31)) & 2)) - (v1947 + ((~(((v1948 ^ -1) | (-(v1948 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
    v1966[v2114] = v1964;
    int * v1968 = v1822->cache_vals;
    int v2117 = (((4 + ((((int)((unsigned int)((int)((unsigned int)(v1826 + 68) >> 2)) >> 1)) & 3) * 2)) + ((((v1944 + ((~(((v1946 ^ -1) | (-(v1946 ^ -1))) >> 31)) & 2)) - (v1947 + ((~(((v1948 ^ -1) | (-(v1948 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
    v1968[v2117] = v1965;
    int * v1970 = v1822->cache_tags;
    int v2120 = (int)((unsigned int)((int)((unsigned int)(v1826 + 68) >> 2)) >> 1);
    v1970[v2096] = v2120;
    int * v1972 = v1822->cache_dirty;
    v1972[v2096] = 0;
    int * v1974 = v1822->cache_age;
    v1974[v2096] = 1;
    int * v1976 = v1822->cache_age;
    int v1977 = v1976[v2096];
    int v1978 = v1976[v2000];
    int v2126 = v1978 + ((int)((unsigned int)(v1978 - v1977) >> 31));
    v1976[v2000] = v2126;
    int * v1980 = v1822->cache_age;
    int v1981 = v1980[v2001];
    int v2128 = v1981 + ((int)((unsigned int)(v1981 - v1977) >> 31));
    v1980[v2001] = v2128;
    int * v1983 = v1822->cache_age;
    v1983[v2096] = 0;
    v1986 = v2096;
  }
  int * v1987 = v1822->cache_vals;
  int v2131 = (v1986 * 2) + (((int)((unsigned int)(v1826 + 68) >> 2)) & 1);
  v1987[v2131] = v1827;
  int * v1989 = v1822->cache_dirty;
  v1989[v1986] = 1;
  struct StateT * v1991 = slot_25(v1822);
  return v1991;
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

struct StateT * slot_14(struct StateT * v591) {
  int v592 = v591->timer;
  int v702 = v592 + 1;
  v591->timer = v702;
  int * v594 = v591->regs;
  int v595 = v594[10];
  int * v596 = v591->cache_tags;
  int v706 = (((int)((unsigned int)((int)((unsigned int)v595 >> 2)) >> 1)) & 1) * 2;
  int v597 = v596[v706];
  int v707 = ((((int)((unsigned int)((int)((unsigned int)v595 >> 2)) >> 1)) & 1) * 2) + 1;
  int v598 = v596[v707];
  int v708 = 4 + ((((int)((unsigned int)((int)((unsigned int)v595 >> 2)) >> 1)) & 3) * 2);
  int v599 = v596[v708];
  int v709 = (4 + ((((int)((unsigned int)((int)((unsigned int)v595 >> 2)) >> 1)) & 3) * 2)) + 1;
  int v600 = v596[v709];
  int v601 = v591->timer;
  int v710 = v601 + ((100 ^ (((~(((v599 ^ ((int)((unsigned int)((int)((unsigned int)v595 >> 2)) >> 1))) | (-(v599 ^ ((int)((unsigned int)((int)((unsigned int)v595 >> 2)) >> 1))))) >> 31)) | (~(((v600 ^ ((int)((unsigned int)((int)((unsigned int)v595 >> 2)) >> 1))) | (-(v600 ^ ((int)((unsigned int)((int)((unsigned int)v595 >> 2)) >> 1))))) >> 31))) & 104)) ^ (((~(((v597 ^ ((int)((unsigned int)((int)((unsigned int)v595 >> 2)) >> 1))) | (-(v597 ^ ((int)((unsigned int)((int)((unsigned int)v595 >> 2)) >> 1))))) >> 31)) | (~(((v598 ^ ((int)((unsigned int)((int)((unsigned int)v595 >> 2)) >> 1))) | (-(v598 ^ ((int)((unsigned int)((int)((unsigned int)v595 >> 2)) >> 1))))) >> 31))) & (1 ^ (100 ^ (((~(((v599 ^ ((int)((unsigned int)((int)((unsigned int)v595 >> 2)) >> 1))) | (-(v599 ^ ((int)((unsigned int)((int)((unsigned int)v595 >> 2)) >> 1))))) >> 31)) | (~(((v600 ^ ((int)((unsigned int)((int)((unsigned int)v595 >> 2)) >> 1))) | (-(v600 ^ ((int)((unsigned int)((int)((unsigned int)v595 >> 2)) >> 1))))) >> 31))) & 104)))));
  v591->timer = v710;
  int * v603 = v591->cache_vals;
  bool v711 = !(((~(((v597 ^ ((int)((unsigned int)((int)((unsigned int)v595 >> 2)) >> 1))) | (-(v597 ^ ((int)((unsigned int)((int)((unsigned int)v595 >> 2)) >> 1))))) >> 31)) | (~(((v598 ^ ((int)((unsigned int)((int)((unsigned int)v595 >> 2)) >> 1))) | (-(v598 ^ ((int)((unsigned int)((int)((unsigned int)v595 >> 2)) >> 1))))) >> 31))) == 0);
  int v696;
  if (v711) {
    int * v604 = v591->cache_age;
    int v713 = ((((int)((unsigned int)((int)((unsigned int)v595 >> 2)) >> 1)) & 1) * 2) + ((~(((v598 ^ ((int)((unsigned int)((int)((unsigned int)v595 >> 2)) >> 1))) | (-(v598 ^ ((int)((unsigned int)((int)((unsigned int)v595 >> 2)) >> 1))))) >> 31)) & 1);
    int v605 = v604[v713];
    int v606 = v604[v706];
    int v714 = v606 + ((int)((unsigned int)(v606 - v605) >> 31));
    v604[v706] = v714;
    int * v608 = v591->cache_age;
    int v609 = v608[v707];
    int v716 = v609 + ((int)((unsigned int)(v609 - v605) >> 31));
    v608[v707] = v716;
    int * v611 = v591->cache_age;
    v611[v713] = 0;
    v696 = v713;
  } else {
    int * v614 = v591->cache_age;
    int v720 = (((int)((unsigned int)((int)((unsigned int)v595 >> 2)) >> 1)) & 1) * 2;
    int v615 = v614[v720];
    int * v616 = v591->cache_tags;
    int v617 = v616[v720];
    int v618 = v614[v707];
    int v619 = v616[v707];
    bool v722 = !(((~(((v599 ^ ((int)((unsigned int)((int)((unsigned int)v595 >> 2)) >> 1))) | (-(v599 ^ ((int)((unsigned int)((int)((unsigned int)v595 >> 2)) >> 1))))) >> 31)) | (~(((v600 ^ ((int)((unsigned int)((int)((unsigned int)v595 >> 2)) >> 1))) | (-(v600 ^ ((int)((unsigned int)((int)((unsigned int)v595 >> 2)) >> 1))))) >> 31))) == 0);
    int v673;
    if (v722) {
      int * v620 = v591->cache_age;
      int v724 = (4 + ((((int)((unsigned int)((int)((unsigned int)v595 >> 2)) >> 1)) & 3) * 2)) + ((~(((v600 ^ ((int)((unsigned int)((int)((unsigned int)v595 >> 2)) >> 1))) | (-(v600 ^ ((int)((unsigned int)((int)((unsigned int)v595 >> 2)) >> 1))))) >> 31)) & 1);
      int v621 = v620[v724];
      int v622 = v620[v708];
      int v725 = v622 + ((int)((unsigned int)(v622 - v621) >> 31));
      v620[v708] = v725;
      int * v624 = v591->cache_age;
      int v625 = v624[v709];
      int v727 = v625 + ((int)((unsigned int)(v625 - v621) >> 31));
      v624[v709] = v727;
      int * v627 = v591->cache_age;
      v627[v724] = 0;
      v673 = v724;
    } else {
      int * v630 = v591->cache_age;
      int v731 = 4 + ((((int)((unsigned int)((int)((unsigned int)v595 >> 2)) >> 1)) & 3) * 2);
      int v631 = v630[v731];
      int * v632 = v591->cache_tags;
      int v633 = v632[v731];
      int v634 = v630[v709];
      int v635 = v632[v709];
      int * v636 = v591->cache_dirty;
      int v734 = (4 + ((((int)((unsigned int)((int)((unsigned int)v595 >> 2)) >> 1)) & 3) * 2)) + ((((v631 + ((~(((v633 ^ -1) | (-(v633 ^ -1))) >> 31)) & 2)) - (v634 + ((~(((v635 ^ -1) | (-(v635 ^ -1))) >> 31)) & 2))) >> 31) & 1);
      int v637 = v636[v734];
      bool v735 = !(v637 == 0);
      if (v735) {
        int * v638 = v591->cache_tags;
        int v639 = v638[v734];
        int * v640 = v591->cache_vals;
        int v738 = ((4 + ((((int)((unsigned int)((int)((unsigned int)v595 >> 2)) >> 1)) & 3) * 2)) + ((((v631 + ((~(((v633 ^ -1) | (-(v633 ^ -1))) >> 31)) & 2)) - (v634 + ((~(((v635 ^ -1) | (-(v635 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
        int v641 = v640[v738];
        int v739 = (((4 + ((((int)((unsigned int)((int)((unsigned int)v595 >> 2)) >> 1)) & 3) * 2)) + ((((v631 + ((~(((v633 ^ -1) | (-(v633 ^ -1))) >> 31)) & 2)) - (v634 + ((~(((v635 ^ -1) | (-(v635 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
        int v642 = v640[v739];
        int * v643 = v591->mem;
        int v741 = v639 * 2;
        v643[v741] = v641;
        int * v645 = v591->mem;
        int v744 = (v639 * 2) + 1;
        v645[v744] = v642;
        ;
      } else {
        ;
      }
      int * v650 = v591->mem;
      int v749 = ((int)((unsigned int)((int)((unsigned int)v595 >> 2)) >> 1)) * 2;
      int v651 = v650[v749];
      int v750 = (((int)((unsigned int)((int)((unsigned int)v595 >> 2)) >> 1)) * 2) + 1;
      int v652 = v650[v750];
      int * v653 = v591->cache_vals;
      int v752 = ((4 + ((((int)((unsigned int)((int)((unsigned int)v595 >> 2)) >> 1)) & 3) * 2)) + ((((v631 + ((~(((v633 ^ -1) | (-(v633 ^ -1))) >> 31)) & 2)) - (v634 + ((~(((v635 ^ -1) | (-(v635 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
      v653[v752] = v651;
      int * v655 = v591->cache_vals;
      int v755 = (((4 + ((((int)((unsigned int)((int)((unsigned int)v595 >> 2)) >> 1)) & 3) * 2)) + ((((v631 + ((~(((v633 ^ -1) | (-(v633 ^ -1))) >> 31)) & 2)) - (v634 + ((~(((v635 ^ -1) | (-(v635 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
      v655[v755] = v652;
      int * v657 = v591->cache_tags;
      int v758 = (int)((unsigned int)((int)((unsigned int)v595 >> 2)) >> 1);
      v657[v734] = v758;
      int * v659 = v591->cache_dirty;
      v659[v734] = 0;
      int * v661 = v591->cache_age;
      v661[v734] = 1;
      int * v663 = v591->cache_age;
      int v664 = v663[v734];
      int v665 = v663[v708];
      int v764 = v665 + ((int)((unsigned int)(v665 - v664) >> 31));
      v663[v708] = v764;
      int * v667 = v591->cache_age;
      int v668 = v667[v709];
      int v766 = v668 + ((int)((unsigned int)(v668 - v664) >> 31));
      v667[v709] = v766;
      int * v670 = v591->cache_age;
      v670[v734] = 0;
      v673 = v734;
    }
    int * v674 = v591->cache_vals;
    int v769 = v673 * 2;
    int v675 = v674[v769];
    int v770 = (v673 * 2) + 1;
    int v676 = v674[v770];
    int v771 = (((((int)((unsigned int)((int)((unsigned int)v595 >> 2)) >> 1)) & 1) * 2) + ((((v615 + ((~(((v617 ^ -1) | (-(v617 ^ -1))) >> 31)) & 2)) - (v618 + ((~(((v619 ^ -1) | (-(v619 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
    v674[v771] = v675;
    int * v678 = v591->cache_vals;
    int v774 = ((((((int)((unsigned int)((int)((unsigned int)v595 >> 2)) >> 1)) & 1) * 2) + ((((v615 + ((~(((v617 ^ -1) | (-(v617 ^ -1))) >> 31)) & 2)) - (v618 + ((~(((v619 ^ -1) | (-(v619 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
    v678[v774] = v676;
    int * v680 = v591->cache_tags;
    int v777 = ((((int)((unsigned int)((int)((unsigned int)v595 >> 2)) >> 1)) & 1) * 2) + ((((v615 + ((~(((v617 ^ -1) | (-(v617 ^ -1))) >> 31)) & 2)) - (v618 + ((~(((v619 ^ -1) | (-(v619 ^ -1))) >> 31)) & 2))) >> 31) & 1);
    int v778 = (int)((unsigned int)((int)((unsigned int)v595 >> 2)) >> 1);
    v680[v777] = v778;
    int * v682 = v591->cache_dirty;
    v682[v777] = 0;
    int * v684 = v591->cache_age;
    v684[v777] = 1;
    int * v686 = v591->cache_age;
    int v687 = v686[v777];
    int v688 = v686[v706];
    int v784 = v688 + ((int)((unsigned int)(v688 - v687) >> 31));
    v686[v706] = v784;
    int * v690 = v591->cache_age;
    int v691 = v690[v707];
    int v786 = v691 + ((int)((unsigned int)(v691 - v687) >> 31));
    v690[v707] = v786;
    int * v693 = v591->cache_age;
    v693[v777] = 0;
    v696 = v777;
  }
  int v789 = (v696 * 2) + (((int)((unsigned int)v595 >> 2)) & 1);
  int v697 = v603[v789];
  int * v698 = v591->regs;
  v698[10] = v697;
  struct StateT * v700 = slot_15(v591);
  return v700;
}

struct StateT * slot_17(struct StateT * v1014) {
  int * v1015 = v1014->saved_regs;
  int v1016 = v1015[10];
  int v1017 = v1015[11];
  bool v1041 = (v1016 ^ -2147483648) >= (v1017 ^ -2147483648);
  struct StateT * v1036;
  if (v1041) {
    int v1018 = v1014->timer;
    int v1042 = v1018 + 15;
    v1014->timer = v1042;
    int * v1020 = v1014->saved_regs;
    int v1021 = v1020[10];
    int * v1022 = v1014->regs;
    v1022[10] = v1021;
    int * v1024 = v1014->saved_regs;
    int v1025 = v1024[11];
    int * v1026 = v1014->regs;
    v1026[11] = v1025;
    int * v1028 = v1014->saved_regs;
    int v1029 = v1028[12];
    int * v1030 = v1014->regs;
    v1030[12] = v1029;
    struct StateT * v1032 = slot_18(v1014);
    v1036 = v1032;
  } else {
    struct StateT * v1034 = slot_19(v1014);
    v1036 = v1034;
  }
  return v1036;
}

struct StateT * slot_20(struct StateT * v1386) {
  int v1387 = v1386->timer;
  int v1393 = v1387 + 1;
  v1386->timer = v1393;
  int * v1389 = v1386->regs;
  v1389[11] = 0;
  struct StateT * v1391 = slot_21(v1386);
  return v1391;
}

struct StateT * snippet(struct StateT * v0) {
  struct StateT * v1 = slot_0(v0);
  return v1;
}

struct StateT * slot_8(struct StateT * v500) {
  int v501 = v500->timer;
  int v507 = v501 + 1;
  v500->timer = v507;
  int * v503 = v500->regs;
  v503[11] = 0;
  struct StateT * v505 = slot_9(v500);
  return v505;
}

struct StateT * slot_4(struct StateT * v247) {
  int * v248 = v247->saved_regs;
  int * v249 = v247->regs;
  int v250 = v249[11];
  v248[11] = v250;
  int v252 = v247->timer;
  int v262 = v252 + 1;
  v247->timer = v262;
  int * v254 = v247->regs;
  v254[11] = 0;
  struct StateT * v256 = slot_5(v247);
  return v256;
}

struct StateT * slot_15(struct StateT * v794) {
  int v795 = v794->timer;
  int v905 = v795 + 1;
  v794->timer = v905;
  int * v797 = v794->regs;
  int v798 = v797[12];
  int * v799 = v794->cache_tags;
  int v909 = (((int)((unsigned int)((int)((unsigned int)(v798 + 68) >> 2)) >> 1)) & 1) * 2;
  int v800 = v799[v909];
  int v910 = ((((int)((unsigned int)((int)((unsigned int)(v798 + 68) >> 2)) >> 1)) & 1) * 2) + 1;
  int v801 = v799[v910];
  int v911 = 4 + ((((int)((unsigned int)((int)((unsigned int)(v798 + 68) >> 2)) >> 1)) & 3) * 2);
  int v802 = v799[v911];
  int v912 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v798 + 68) >> 2)) >> 1)) & 3) * 2)) + 1;
  int v803 = v799[v912];
  int v804 = v794->timer;
  int v913 = v804 + ((100 ^ (((~(((v802 ^ ((int)((unsigned int)((int)((unsigned int)(v798 + 68) >> 2)) >> 1))) | (-(v802 ^ ((int)((unsigned int)((int)((unsigned int)(v798 + 68) >> 2)) >> 1))))) >> 31)) | (~(((v803 ^ ((int)((unsigned int)((int)((unsigned int)(v798 + 68) >> 2)) >> 1))) | (-(v803 ^ ((int)((unsigned int)((int)((unsigned int)(v798 + 68) >> 2)) >> 1))))) >> 31))) & 104)) ^ (((~(((v800 ^ ((int)((unsigned int)((int)((unsigned int)(v798 + 68) >> 2)) >> 1))) | (-(v800 ^ ((int)((unsigned int)((int)((unsigned int)(v798 + 68) >> 2)) >> 1))))) >> 31)) | (~(((v801 ^ ((int)((unsigned int)((int)((unsigned int)(v798 + 68) >> 2)) >> 1))) | (-(v801 ^ ((int)((unsigned int)((int)((unsigned int)(v798 + 68) >> 2)) >> 1))))) >> 31))) & (1 ^ (100 ^ (((~(((v802 ^ ((int)((unsigned int)((int)((unsigned int)(v798 + 68) >> 2)) >> 1))) | (-(v802 ^ ((int)((unsigned int)((int)((unsigned int)(v798 + 68) >> 2)) >> 1))))) >> 31)) | (~(((v803 ^ ((int)((unsigned int)((int)((unsigned int)(v798 + 68) >> 2)) >> 1))) | (-(v803 ^ ((int)((unsigned int)((int)((unsigned int)(v798 + 68) >> 2)) >> 1))))) >> 31))) & 104)))));
  v794->timer = v913;
  int * v806 = v794->cache_vals;
  bool v914 = !(((~(((v800 ^ ((int)((unsigned int)((int)((unsigned int)(v798 + 68) >> 2)) >> 1))) | (-(v800 ^ ((int)((unsigned int)((int)((unsigned int)(v798 + 68) >> 2)) >> 1))))) >> 31)) | (~(((v801 ^ ((int)((unsigned int)((int)((unsigned int)(v798 + 68) >> 2)) >> 1))) | (-(v801 ^ ((int)((unsigned int)((int)((unsigned int)(v798 + 68) >> 2)) >> 1))))) >> 31))) == 0);
  int v899;
  if (v914) {
    int * v807 = v794->cache_age;
    int v916 = ((((int)((unsigned int)((int)((unsigned int)(v798 + 68) >> 2)) >> 1)) & 1) * 2) + ((~(((v801 ^ ((int)((unsigned int)((int)((unsigned int)(v798 + 68) >> 2)) >> 1))) | (-(v801 ^ ((int)((unsigned int)((int)((unsigned int)(v798 + 68) >> 2)) >> 1))))) >> 31)) & 1);
    int v808 = v807[v916];
    int v809 = v807[v909];
    int v917 = v809 + ((int)((unsigned int)(v809 - v808) >> 31));
    v807[v909] = v917;
    int * v811 = v794->cache_age;
    int v812 = v811[v910];
    int v919 = v812 + ((int)((unsigned int)(v812 - v808) >> 31));
    v811[v910] = v919;
    int * v814 = v794->cache_age;
    v814[v916] = 0;
    v899 = v916;
  } else {
    int * v817 = v794->cache_age;
    int v923 = (((int)((unsigned int)((int)((unsigned int)(v798 + 68) >> 2)) >> 1)) & 1) * 2;
    int v818 = v817[v923];
    int * v819 = v794->cache_tags;
    int v820 = v819[v923];
    int v821 = v817[v910];
    int v822 = v819[v910];
    bool v925 = !(((~(((v802 ^ ((int)((unsigned int)((int)((unsigned int)(v798 + 68) >> 2)) >> 1))) | (-(v802 ^ ((int)((unsigned int)((int)((unsigned int)(v798 + 68) >> 2)) >> 1))))) >> 31)) | (~(((v803 ^ ((int)((unsigned int)((int)((unsigned int)(v798 + 68) >> 2)) >> 1))) | (-(v803 ^ ((int)((unsigned int)((int)((unsigned int)(v798 + 68) >> 2)) >> 1))))) >> 31))) == 0);
    int v876;
    if (v925) {
      int * v823 = v794->cache_age;
      int v927 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v798 + 68) >> 2)) >> 1)) & 3) * 2)) + ((~(((v803 ^ ((int)((unsigned int)((int)((unsigned int)(v798 + 68) >> 2)) >> 1))) | (-(v803 ^ ((int)((unsigned int)((int)((unsigned int)(v798 + 68) >> 2)) >> 1))))) >> 31)) & 1);
      int v824 = v823[v927];
      int v825 = v823[v911];
      int v928 = v825 + ((int)((unsigned int)(v825 - v824) >> 31));
      v823[v911] = v928;
      int * v827 = v794->cache_age;
      int v828 = v827[v912];
      int v930 = v828 + ((int)((unsigned int)(v828 - v824) >> 31));
      v827[v912] = v930;
      int * v830 = v794->cache_age;
      v830[v927] = 0;
      v876 = v927;
    } else {
      int * v833 = v794->cache_age;
      int v934 = 4 + ((((int)((unsigned int)((int)((unsigned int)(v798 + 68) >> 2)) >> 1)) & 3) * 2);
      int v834 = v833[v934];
      int * v835 = v794->cache_tags;
      int v836 = v835[v934];
      int v837 = v833[v912];
      int v838 = v835[v912];
      int * v839 = v794->cache_dirty;
      int v937 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v798 + 68) >> 2)) >> 1)) & 3) * 2)) + ((((v834 + ((~(((v836 ^ -1) | (-(v836 ^ -1))) >> 31)) & 2)) - (v837 + ((~(((v838 ^ -1) | (-(v838 ^ -1))) >> 31)) & 2))) >> 31) & 1);
      int v840 = v839[v937];
      bool v938 = !(v840 == 0);
      if (v938) {
        int * v841 = v794->cache_tags;
        int v842 = v841[v937];
        int * v843 = v794->cache_vals;
        int v941 = ((4 + ((((int)((unsigned int)((int)((unsigned int)(v798 + 68) >> 2)) >> 1)) & 3) * 2)) + ((((v834 + ((~(((v836 ^ -1) | (-(v836 ^ -1))) >> 31)) & 2)) - (v837 + ((~(((v838 ^ -1) | (-(v838 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
        int v844 = v843[v941];
        int v942 = (((4 + ((((int)((unsigned int)((int)((unsigned int)(v798 + 68) >> 2)) >> 1)) & 3) * 2)) + ((((v834 + ((~(((v836 ^ -1) | (-(v836 ^ -1))) >> 31)) & 2)) - (v837 + ((~(((v838 ^ -1) | (-(v838 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
        int v845 = v843[v942];
        int * v846 = v794->mem;
        int v944 = v842 * 2;
        v846[v944] = v844;
        int * v848 = v794->mem;
        int v947 = (v842 * 2) + 1;
        v848[v947] = v845;
        ;
      } else {
        ;
      }
      int * v853 = v794->mem;
      int v952 = ((int)((unsigned int)((int)((unsigned int)(v798 + 68) >> 2)) >> 1)) * 2;
      int v854 = v853[v952];
      int v953 = (((int)((unsigned int)((int)((unsigned int)(v798 + 68) >> 2)) >> 1)) * 2) + 1;
      int v855 = v853[v953];
      int * v856 = v794->cache_vals;
      int v955 = ((4 + ((((int)((unsigned int)((int)((unsigned int)(v798 + 68) >> 2)) >> 1)) & 3) * 2)) + ((((v834 + ((~(((v836 ^ -1) | (-(v836 ^ -1))) >> 31)) & 2)) - (v837 + ((~(((v838 ^ -1) | (-(v838 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
      v856[v955] = v854;
      int * v858 = v794->cache_vals;
      int v958 = (((4 + ((((int)((unsigned int)((int)((unsigned int)(v798 + 68) >> 2)) >> 1)) & 3) * 2)) + ((((v834 + ((~(((v836 ^ -1) | (-(v836 ^ -1))) >> 31)) & 2)) - (v837 + ((~(((v838 ^ -1) | (-(v838 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
      v858[v958] = v855;
      int * v860 = v794->cache_tags;
      int v961 = (int)((unsigned int)((int)((unsigned int)(v798 + 68) >> 2)) >> 1);
      v860[v937] = v961;
      int * v862 = v794->cache_dirty;
      v862[v937] = 0;
      int * v864 = v794->cache_age;
      v864[v937] = 1;
      int * v866 = v794->cache_age;
      int v867 = v866[v937];
      int v868 = v866[v911];
      int v967 = v868 + ((int)((unsigned int)(v868 - v867) >> 31));
      v866[v911] = v967;
      int * v870 = v794->cache_age;
      int v871 = v870[v912];
      int v969 = v871 + ((int)((unsigned int)(v871 - v867) >> 31));
      v870[v912] = v969;
      int * v873 = v794->cache_age;
      v873[v937] = 0;
      v876 = v937;
    }
    int * v877 = v794->cache_vals;
    int v972 = v876 * 2;
    int v878 = v877[v972];
    int v973 = (v876 * 2) + 1;
    int v879 = v877[v973];
    int v974 = (((((int)((unsigned int)((int)((unsigned int)(v798 + 68) >> 2)) >> 1)) & 1) * 2) + ((((v818 + ((~(((v820 ^ -1) | (-(v820 ^ -1))) >> 31)) & 2)) - (v821 + ((~(((v822 ^ -1) | (-(v822 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
    v877[v974] = v878;
    int * v881 = v794->cache_vals;
    int v977 = ((((((int)((unsigned int)((int)((unsigned int)(v798 + 68) >> 2)) >> 1)) & 1) * 2) + ((((v818 + ((~(((v820 ^ -1) | (-(v820 ^ -1))) >> 31)) & 2)) - (v821 + ((~(((v822 ^ -1) | (-(v822 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
    v881[v977] = v879;
    int * v883 = v794->cache_tags;
    int v980 = ((((int)((unsigned int)((int)((unsigned int)(v798 + 68) >> 2)) >> 1)) & 1) * 2) + ((((v818 + ((~(((v820 ^ -1) | (-(v820 ^ -1))) >> 31)) & 2)) - (v821 + ((~(((v822 ^ -1) | (-(v822 ^ -1))) >> 31)) & 2))) >> 31) & 1);
    int v981 = (int)((unsigned int)((int)((unsigned int)(v798 + 68) >> 2)) >> 1);
    v883[v980] = v981;
    int * v885 = v794->cache_dirty;
    v885[v980] = 0;
    int * v887 = v794->cache_age;
    v887[v980] = 1;
    int * v889 = v794->cache_age;
    int v890 = v889[v980];
    int v891 = v889[v909];
    int v987 = v891 + ((int)((unsigned int)(v891 - v890) >> 31));
    v889[v909] = v987;
    int * v893 = v794->cache_age;
    int v894 = v893[v910];
    int v989 = v894 + ((int)((unsigned int)(v894 - v890) >> 31));
    v893[v910] = v989;
    int * v896 = v794->cache_age;
    v896[v980] = 0;
    v899 = v980;
  }
  int v992 = (v899 * 2) + (((int)((unsigned int)(v798 + 68) >> 2)) & 1);
  int v900 = v806[v992];
  int * v901 = v794->regs;
  v901[11] = v900;
  struct StateT * v903 = slot_16(v794);
  return v903;
}

struct StateT * slot_18(struct StateT * v1058) {
  int v1059 = v1058->timer;
  int v1065 = v1059 + 1;
  v1058->timer = v1065;
  int * v1061 = v1058->regs;
  v1061[10] = 0;
  struct StateT * v1063 = slot_20(v1058);
  return v1063;
}

struct StateT * slot_9(struct StateT * v513) {
  int v514 = v513->timer;
  int v521 = v514 + 1;
  v513->timer = v521;
  int * v516 = v513->regs;
  int v517 = v516[11];
  int v524 = v517 + 4;
  v516[11] = v524;
  struct StateT * v519 = slot_10(v513);
  return v519;
}

struct StateT * slot_22(struct StateT * v1602) {
  int v1603 = v1602->timer;
  int v1713 = v1603 + 1;
  v1602->timer = v1713;
  int * v1605 = v1602->regs;
  int v1606 = v1605[11];
  int * v1607 = v1602->cache_tags;
  int v1717 = (((int)((unsigned int)((int)((unsigned int)(v1606 + 68) >> 2)) >> 1)) & 1) * 2;
  int v1608 = v1607[v1717];
  int v1718 = ((((int)((unsigned int)((int)((unsigned int)(v1606 + 68) >> 2)) >> 1)) & 1) * 2) + 1;
  int v1609 = v1607[v1718];
  int v1719 = 4 + ((((int)((unsigned int)((int)((unsigned int)(v1606 + 68) >> 2)) >> 1)) & 3) * 2);
  int v1610 = v1607[v1719];
  int v1720 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v1606 + 68) >> 2)) >> 1)) & 3) * 2)) + 1;
  int v1611 = v1607[v1720];
  int v1612 = v1602->timer;
  int v1721 = v1612 + ((100 ^ (((~(((v1610 ^ ((int)((unsigned int)((int)((unsigned int)(v1606 + 68) >> 2)) >> 1))) | (-(v1610 ^ ((int)((unsigned int)((int)((unsigned int)(v1606 + 68) >> 2)) >> 1))))) >> 31)) | (~(((v1611 ^ ((int)((unsigned int)((int)((unsigned int)(v1606 + 68) >> 2)) >> 1))) | (-(v1611 ^ ((int)((unsigned int)((int)((unsigned int)(v1606 + 68) >> 2)) >> 1))))) >> 31))) & 104)) ^ (((~(((v1608 ^ ((int)((unsigned int)((int)((unsigned int)(v1606 + 68) >> 2)) >> 1))) | (-(v1608 ^ ((int)((unsigned int)((int)((unsigned int)(v1606 + 68) >> 2)) >> 1))))) >> 31)) | (~(((v1609 ^ ((int)((unsigned int)((int)((unsigned int)(v1606 + 68) >> 2)) >> 1))) | (-(v1609 ^ ((int)((unsigned int)((int)((unsigned int)(v1606 + 68) >> 2)) >> 1))))) >> 31))) & (1 ^ (100 ^ (((~(((v1610 ^ ((int)((unsigned int)((int)((unsigned int)(v1606 + 68) >> 2)) >> 1))) | (-(v1610 ^ ((int)((unsigned int)((int)((unsigned int)(v1606 + 68) >> 2)) >> 1))))) >> 31)) | (~(((v1611 ^ ((int)((unsigned int)((int)((unsigned int)(v1606 + 68) >> 2)) >> 1))) | (-(v1611 ^ ((int)((unsigned int)((int)((unsigned int)(v1606 + 68) >> 2)) >> 1))))) >> 31))) & 104)))));
  v1602->timer = v1721;
  int * v1614 = v1602->cache_vals;
  bool v1722 = !(((~(((v1608 ^ ((int)((unsigned int)((int)((unsigned int)(v1606 + 68) >> 2)) >> 1))) | (-(v1608 ^ ((int)((unsigned int)((int)((unsigned int)(v1606 + 68) >> 2)) >> 1))))) >> 31)) | (~(((v1609 ^ ((int)((unsigned int)((int)((unsigned int)(v1606 + 68) >> 2)) >> 1))) | (-(v1609 ^ ((int)((unsigned int)((int)((unsigned int)(v1606 + 68) >> 2)) >> 1))))) >> 31))) == 0);
  int v1707;
  if (v1722) {
    int * v1615 = v1602->cache_age;
    int v1724 = ((((int)((unsigned int)((int)((unsigned int)(v1606 + 68) >> 2)) >> 1)) & 1) * 2) + ((~(((v1609 ^ ((int)((unsigned int)((int)((unsigned int)(v1606 + 68) >> 2)) >> 1))) | (-(v1609 ^ ((int)((unsigned int)((int)((unsigned int)(v1606 + 68) >> 2)) >> 1))))) >> 31)) & 1);
    int v1616 = v1615[v1724];
    int v1617 = v1615[v1717];
    int v1725 = v1617 + ((int)((unsigned int)(v1617 - v1616) >> 31));
    v1615[v1717] = v1725;
    int * v1619 = v1602->cache_age;
    int v1620 = v1619[v1718];
    int v1727 = v1620 + ((int)((unsigned int)(v1620 - v1616) >> 31));
    v1619[v1718] = v1727;
    int * v1622 = v1602->cache_age;
    v1622[v1724] = 0;
    v1707 = v1724;
  } else {
    int * v1625 = v1602->cache_age;
    int v1731 = (((int)((unsigned int)((int)((unsigned int)(v1606 + 68) >> 2)) >> 1)) & 1) * 2;
    int v1626 = v1625[v1731];
    int * v1627 = v1602->cache_tags;
    int v1628 = v1627[v1731];
    int v1629 = v1625[v1718];
    int v1630 = v1627[v1718];
    bool v1733 = !(((~(((v1610 ^ ((int)((unsigned int)((int)((unsigned int)(v1606 + 68) >> 2)) >> 1))) | (-(v1610 ^ ((int)((unsigned int)((int)((unsigned int)(v1606 + 68) >> 2)) >> 1))))) >> 31)) | (~(((v1611 ^ ((int)((unsigned int)((int)((unsigned int)(v1606 + 68) >> 2)) >> 1))) | (-(v1611 ^ ((int)((unsigned int)((int)((unsigned int)(v1606 + 68) >> 2)) >> 1))))) >> 31))) == 0);
    int v1684;
    if (v1733) {
      int * v1631 = v1602->cache_age;
      int v1735 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v1606 + 68) >> 2)) >> 1)) & 3) * 2)) + ((~(((v1611 ^ ((int)((unsigned int)((int)((unsigned int)(v1606 + 68) >> 2)) >> 1))) | (-(v1611 ^ ((int)((unsigned int)((int)((unsigned int)(v1606 + 68) >> 2)) >> 1))))) >> 31)) & 1);
      int v1632 = v1631[v1735];
      int v1633 = v1631[v1719];
      int v1736 = v1633 + ((int)((unsigned int)(v1633 - v1632) >> 31));
      v1631[v1719] = v1736;
      int * v1635 = v1602->cache_age;
      int v1636 = v1635[v1720];
      int v1738 = v1636 + ((int)((unsigned int)(v1636 - v1632) >> 31));
      v1635[v1720] = v1738;
      int * v1638 = v1602->cache_age;
      v1638[v1735] = 0;
      v1684 = v1735;
    } else {
      int * v1641 = v1602->cache_age;
      int v1742 = 4 + ((((int)((unsigned int)((int)((unsigned int)(v1606 + 68) >> 2)) >> 1)) & 3) * 2);
      int v1642 = v1641[v1742];
      int * v1643 = v1602->cache_tags;
      int v1644 = v1643[v1742];
      int v1645 = v1641[v1720];
      int v1646 = v1643[v1720];
      int * v1647 = v1602->cache_dirty;
      int v1745 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v1606 + 68) >> 2)) >> 1)) & 3) * 2)) + ((((v1642 + ((~(((v1644 ^ -1) | (-(v1644 ^ -1))) >> 31)) & 2)) - (v1645 + ((~(((v1646 ^ -1) | (-(v1646 ^ -1))) >> 31)) & 2))) >> 31) & 1);
      int v1648 = v1647[v1745];
      bool v1746 = !(v1648 == 0);
      if (v1746) {
        int * v1649 = v1602->cache_tags;
        int v1650 = v1649[v1745];
        int * v1651 = v1602->cache_vals;
        int v1749 = ((4 + ((((int)((unsigned int)((int)((unsigned int)(v1606 + 68) >> 2)) >> 1)) & 3) * 2)) + ((((v1642 + ((~(((v1644 ^ -1) | (-(v1644 ^ -1))) >> 31)) & 2)) - (v1645 + ((~(((v1646 ^ -1) | (-(v1646 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
        int v1652 = v1651[v1749];
        int v1750 = (((4 + ((((int)((unsigned int)((int)((unsigned int)(v1606 + 68) >> 2)) >> 1)) & 3) * 2)) + ((((v1642 + ((~(((v1644 ^ -1) | (-(v1644 ^ -1))) >> 31)) & 2)) - (v1645 + ((~(((v1646 ^ -1) | (-(v1646 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
        int v1653 = v1651[v1750];
        int * v1654 = v1602->mem;
        int v1752 = v1650 * 2;
        v1654[v1752] = v1652;
        int * v1656 = v1602->mem;
        int v1755 = (v1650 * 2) + 1;
        v1656[v1755] = v1653;
        ;
      } else {
        ;
      }
      int * v1661 = v1602->mem;
      int v1760 = ((int)((unsigned int)((int)((unsigned int)(v1606 + 68) >> 2)) >> 1)) * 2;
      int v1662 = v1661[v1760];
      int v1761 = (((int)((unsigned int)((int)((unsigned int)(v1606 + 68) >> 2)) >> 1)) * 2) + 1;
      int v1663 = v1661[v1761];
      int * v1664 = v1602->cache_vals;
      int v1763 = ((4 + ((((int)((unsigned int)((int)((unsigned int)(v1606 + 68) >> 2)) >> 1)) & 3) * 2)) + ((((v1642 + ((~(((v1644 ^ -1) | (-(v1644 ^ -1))) >> 31)) & 2)) - (v1645 + ((~(((v1646 ^ -1) | (-(v1646 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
      v1664[v1763] = v1662;
      int * v1666 = v1602->cache_vals;
      int v1766 = (((4 + ((((int)((unsigned int)((int)((unsigned int)(v1606 + 68) >> 2)) >> 1)) & 3) * 2)) + ((((v1642 + ((~(((v1644 ^ -1) | (-(v1644 ^ -1))) >> 31)) & 2)) - (v1645 + ((~(((v1646 ^ -1) | (-(v1646 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
      v1666[v1766] = v1663;
      int * v1668 = v1602->cache_tags;
      int v1769 = (int)((unsigned int)((int)((unsigned int)(v1606 + 68) >> 2)) >> 1);
      v1668[v1745] = v1769;
      int * v1670 = v1602->cache_dirty;
      v1670[v1745] = 0;
      int * v1672 = v1602->cache_age;
      v1672[v1745] = 1;
      int * v1674 = v1602->cache_age;
      int v1675 = v1674[v1745];
      int v1676 = v1674[v1719];
      int v1775 = v1676 + ((int)((unsigned int)(v1676 - v1675) >> 31));
      v1674[v1719] = v1775;
      int * v1678 = v1602->cache_age;
      int v1679 = v1678[v1720];
      int v1777 = v1679 + ((int)((unsigned int)(v1679 - v1675) >> 31));
      v1678[v1720] = v1777;
      int * v1681 = v1602->cache_age;
      v1681[v1745] = 0;
      v1684 = v1745;
    }
    int * v1685 = v1602->cache_vals;
    int v1780 = v1684 * 2;
    int v1686 = v1685[v1780];
    int v1781 = (v1684 * 2) + 1;
    int v1687 = v1685[v1781];
    int v1782 = (((((int)((unsigned int)((int)((unsigned int)(v1606 + 68) >> 2)) >> 1)) & 1) * 2) + ((((v1626 + ((~(((v1628 ^ -1) | (-(v1628 ^ -1))) >> 31)) & 2)) - (v1629 + ((~(((v1630 ^ -1) | (-(v1630 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
    v1685[v1782] = v1686;
    int * v1689 = v1602->cache_vals;
    int v1785 = ((((((int)((unsigned int)((int)((unsigned int)(v1606 + 68) >> 2)) >> 1)) & 1) * 2) + ((((v1626 + ((~(((v1628 ^ -1) | (-(v1628 ^ -1))) >> 31)) & 2)) - (v1629 + ((~(((v1630 ^ -1) | (-(v1630 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
    v1689[v1785] = v1687;
    int * v1691 = v1602->cache_tags;
    int v1788 = ((((int)((unsigned int)((int)((unsigned int)(v1606 + 68) >> 2)) >> 1)) & 1) * 2) + ((((v1626 + ((~(((v1628 ^ -1) | (-(v1628 ^ -1))) >> 31)) & 2)) - (v1629 + ((~(((v1630 ^ -1) | (-(v1630 ^ -1))) >> 31)) & 2))) >> 31) & 1);
    int v1789 = (int)((unsigned int)((int)((unsigned int)(v1606 + 68) >> 2)) >> 1);
    v1691[v1788] = v1789;
    int * v1693 = v1602->cache_dirty;
    v1693[v1788] = 0;
    int * v1695 = v1602->cache_age;
    v1695[v1788] = 1;
    int * v1697 = v1602->cache_age;
    int v1698 = v1697[v1788];
    int v1699 = v1697[v1717];
    int v1795 = v1699 + ((int)((unsigned int)(v1699 - v1698) >> 31));
    v1697[v1717] = v1795;
    int * v1701 = v1602->cache_age;
    int v1702 = v1701[v1718];
    int v1797 = v1702 + ((int)((unsigned int)(v1702 - v1698) >> 31));
    v1701[v1718] = v1797;
    int * v1704 = v1602->cache_age;
    v1704[v1788] = 0;
    v1707 = v1788;
  }
  int v1800 = (v1707 * 2) + (((int)((unsigned int)(v1606 + 68) >> 2)) & 1);
  int v1708 = v1614[v1800];
  int * v1709 = v1602->regs;
  v1709[12] = v1708;
  struct StateT * v1711 = slot_23(v1602);
  return v1711;
}

struct StateT * slot_11(struct StateT * v547) {
  int v548 = v547->timer;
  int v555 = v548 + 1;
  v547->timer = v555;
  int * v550 = v547->regs;
  int v551 = v550[10];
  int v558 = v551 << 29;
  v550[10] = v558;
  struct StateT * v553 = slot_12(v547);
  return v553;
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