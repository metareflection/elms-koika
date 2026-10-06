// verify: clean (CBMC should report VERIFICATION SUCCESSFUL) [unwind 65]
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

struct StateT2 * slot_12(struct StateT2 * v1423);
struct StateT2 * slot_14(struct StateT2 * v269);
struct StateT2 * slot_6(struct StateT2 * v336);
struct StateT2 * slot_5(struct StateT2 * v212);
struct StateT2 * slot_2(struct StateT2 * v86);
struct StateT2 * slot_7(struct StateT2 * v395);
struct StateT2 * slot_3(struct StateT2 * v128);
struct StateT2 * snippet(struct StateT2 * v0);
struct StateT2 * slot_10(struct StateT2 * v1306);
struct StateT2 * slot_1(struct StateT2 * v44);
struct StateT2 * slot_8(struct StateT2 * v821);
struct StateT2 * slot_4(struct StateT2 * v170);
struct StateT2 * slot_13(struct StateT2 * v1476);
struct StateT2 * slot_9(struct StateT2 * v880);
struct StateT2 * slot_11(struct StateT2 * v1365);
struct StateT2 * slot_0(struct StateT2 * v2);
struct StateT2 * slot_12(struct StateT2 * v1423) {
  struct StateT * v1424 = v1423->a;
  int v1425 = v1424->timer;
  struct StateT * v1426 = v1423->b;
  int v1427 = v1426->timer;
  bool v1456 = v1425 == v1427;
  squared_assert(v1456);
  squared_assume(v1456);
  struct StateT * v1430 = v1423->a;
  int v1431 = v1430->timer;
  int v1458 = v1431 + 1;
  v1430->timer = v1458;
  struct StateT * v1433 = v1423->b;
  int v1434 = v1433->timer;
  int v1460 = v1434 + 1;
  v1433->timer = v1460;
  struct StateT * v1436 = v1423->a;
  int * v1437 = v1436->reg_ready;
  int v1438 = v1437[14];
  int * v1439 = v1436->regs;
  int v1440 = v1439[14];
  int v1465 = (v1438 + ((v1431 - v1438) & (~((v1431 - v1438) >> 31)))) + 1;
  v1437[14] = v1465;
  int * v1442 = v1436->regs;
  int v1467 = v1440 + 4;
  v1442[14] = v1467;
  struct StateT * v1444 = v1423->b;
  int * v1445 = v1444->reg_ready;
  int v1446 = v1445[14];
  int * v1447 = v1444->regs;
  int v1448 = v1447[14];
  int v1471 = (v1446 + ((v1434 - v1446) & (~((v1434 - v1446) >> 31)))) + 1;
  v1445[14] = v1471;
  int * v1450 = v1444->regs;
  int v1473 = v1448 + 4;
  v1450[14] = v1473;
  struct StateT2 * v1452 = slot_13(v1423);
  return v1452;
}

struct StateT2 * slot_14(struct StateT2 * v269) {
  struct StateT * v270 = v269->a;
  int v271 = v270->timer;
  struct StateT * v272 = v269->b;
  int v273 = v272->timer;
  bool v309 = v271 == v273;
  squared_assert(v309);
  squared_assume(v309);
  struct StateT * v276 = v269->a;
  int v277 = v276->timer;
  int v311 = v277 + 1;
  v276->timer = v311;
  struct StateT * v279 = v269->b;
  int v280 = v279->timer;
  int v313 = v280 + 1;
  v279->timer = v313;
  struct StateT * v282 = v269->a;
  int * v283 = v282->reg_ready;
  int v284 = v283[5];
  int * v285 = v282->regs;
  int v286 = v285[5];
  bool v318 = (v286 ^ -2147483648) < -2147483647;
  int v289;
  if (v318) {
    v289 = 1;
  } else {
    v289 = 0;
  }
  int * v290 = v282->reg_ready;
  int v323 = (v284 + ((v277 - v284) & (~((v277 - v284) >> 31)))) + 1;
  v290[11] = v323;
  int * v292 = v282->regs;
  v292[11] = v289;
  struct StateT * v294 = v269->b;
  int * v295 = v294->reg_ready;
  int v296 = v295[5];
  int * v297 = v294->regs;
  int v298 = v297[5];
  bool v329 = (v298 ^ -2147483648) < -2147483647;
  int v301;
  if (v329) {
    v301 = 1;
  } else {
    v301 = 0;
  }
  int * v302 = v294->reg_ready;
  int v333 = (v296 + ((v280 - v296) & (~((v280 - v296) >> 31)))) + 1;
  v302[11] = v333;
  int * v304 = v294->regs;
  v304[11] = v301;
  return v269;
}

struct StateT2 * slot_6(struct StateT2 * v336) {
  struct StateT * v337 = v336->a;
  int v338 = v337->timer;
  struct StateT * v339 = v336->b;
  int v340 = v339->timer;
  bool v373 = v338 == v340;
  squared_assert(v373);
  squared_assume(v373);
  struct StateT * v343 = v336->a;
  int v344 = v343->timer;
  int v375 = v344 + 1;
  v343->timer = v375;
  struct StateT * v346 = v336->b;
  int v347 = v346->timer;
  int v377 = v347 + 1;
  v346->timer = v377;
  struct StateT * v349 = v336->a;
  int * v350 = v349->reg_ready;
  int v351 = v350[12];
  int * v352 = v349->regs;
  int v353 = v352[12];
  int v354 = v350[14];
  int v355 = v352[14];
  int v384 = (v354 + (((v351 + ((v344 - v351) & (~((v344 - v351) >> 31)))) - v354) & (~(((v351 + ((v344 - v351) & (~((v344 - v351) >> 31)))) - v354) >> 31)))) + 1;
  v350[6] = v384;
  int * v357 = v349->regs;
  int v386 = v353 + v355;
  v357[6] = v386;
  struct StateT * v359 = v336->b;
  int * v360 = v359->reg_ready;
  int v361 = v360[12];
  int * v362 = v359->regs;
  int v363 = v362[12];
  int v364 = v360[14];
  int v365 = v362[14];
  int v390 = (v364 + (((v361 + ((v347 - v361) & (~((v347 - v361) >> 31)))) - v364) & (~(((v361 + ((v347 - v361) & (~((v347 - v361) >> 31)))) - v364) >> 31)))) + 1;
  v360[6] = v390;
  int * v367 = v359->regs;
  int v392 = v363 + v365;
  v367[6] = v392;
  struct StateT2 * v369 = slot_7(v336);
  return v369;
}

struct StateT2 * slot_5(struct StateT2 * v212) {
  struct StateT * v213 = v212->a;
  int v214 = v213->timer;
  struct StateT * v215 = v212->b;
  int v216 = v215->timer;
  bool v249 = v214 == v216;
  squared_assert(v249);
  squared_assume(v249);
  struct StateT * v219 = v212->a;
  int v220 = v219->timer;
  int v251 = v220 + 1;
  v219->timer = v251;
  struct StateT * v222 = v212->b;
  int v223 = v222->timer;
  int v253 = v223 + 1;
  v222->timer = v253;
  struct StateT * v225 = v212->a;
  int * v226 = v225->reg_ready;
  int * v228 = v225->regs;
  int v229 = v228[14];
  int v231 = v228[15];
  struct StateT * v232 = v212->b;
  int * v233 = v232->reg_ready;
  int * v235 = v232->regs;
  int v236 = v235[14];
  int v238 = v235[15];
  bool v262 = (v229 >= v231) == (v236 >= v238);
  squared_diverged(v262);
  squared_assume(v262);
  bool v263 = v229 >= v231;
  struct StateT2 * v245;
  if (v263) {
    struct StateT2 * v241 = slot_14(v212);
    v245 = v241;
  } else {
    struct StateT2 * v243 = slot_6(v212);
    v245 = v243;
  }
  return v245;
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

struct StateT2 * slot_7(struct StateT2 * v395) {
  struct StateT * v396 = v395->a;
  int v397 = v396->timer;
  struct StateT * v398 = v395->b;
  int v399 = v398->timer;
  bool v630 = v397 == v399;
  squared_assert(v630);
  squared_assume(v630);
  struct StateT * v402 = v395->a;
  int v403 = v402->timer;
  int v632 = v403 + 1;
  v402->timer = v632;
  struct StateT * v405 = v395->b;
  int v406 = v405->timer;
  int v634 = v406 + 1;
  v405->timer = v634;
  struct StateT * v408 = v395->a;
  int * v409 = v408->reg_ready;
  int v410 = v409[6];
  int * v411 = v408->regs;
  int v412 = v411[6];
  int * v413 = v408->cache_tags;
  int v640 = (((int)((unsigned int)((int)((unsigned int)v412 >> 2)) >> 1)) & 1) * 2;
  int v414 = v413[v640];
  int v641 = ((((int)((unsigned int)((int)((unsigned int)v412 >> 2)) >> 1)) & 1) * 2) + 1;
  int v415 = v413[v641];
  int v642 = 4 + ((((int)((unsigned int)((int)((unsigned int)v412 >> 2)) >> 1)) & 3) * 2);
  int v416 = v413[v642];
  int v643 = (4 + ((((int)((unsigned int)((int)((unsigned int)v412 >> 2)) >> 1)) & 3) * 2)) + 1;
  int v417 = v413[v643];
  int * v418 = v408->cache_vals;
  bool v644 = !(((~(((v414 ^ ((int)((unsigned int)((int)((unsigned int)v412 >> 2)) >> 1))) | (-(v414 ^ ((int)((unsigned int)((int)((unsigned int)v412 >> 2)) >> 1))))) >> 31)) | (~(((v415 ^ ((int)((unsigned int)((int)((unsigned int)v412 >> 2)) >> 1))) | (-(v415 ^ ((int)((unsigned int)((int)((unsigned int)v412 >> 2)) >> 1))))) >> 31))) == 0);
  int v511;
  if (v644) {
    int * v419 = v408->cache_age;
    int v646 = ((((int)((unsigned int)((int)((unsigned int)v412 >> 2)) >> 1)) & 1) * 2) + ((~(((v415 ^ ((int)((unsigned int)((int)((unsigned int)v412 >> 2)) >> 1))) | (-(v415 ^ ((int)((unsigned int)((int)((unsigned int)v412 >> 2)) >> 1))))) >> 31)) & 1);
    int v420 = v419[v646];
    int v421 = v419[v640];
    int v647 = v421 + ((int)((unsigned int)(v421 - v420) >> 31));
    v419[v640] = v647;
    int * v423 = v408->cache_age;
    int v424 = v423[v641];
    int v649 = v424 + ((int)((unsigned int)(v424 - v420) >> 31));
    v423[v641] = v649;
    int * v426 = v408->cache_age;
    v426[v646] = 0;
    v511 = v646;
  } else {
    int * v429 = v408->cache_age;
    int v653 = (((int)((unsigned int)((int)((unsigned int)v412 >> 2)) >> 1)) & 1) * 2;
    int v430 = v429[v653];
    int * v431 = v408->cache_tags;
    int v432 = v431[v653];
    int v433 = v429[v641];
    int v434 = v431[v641];
    bool v655 = !(((~(((v416 ^ ((int)((unsigned int)((int)((unsigned int)v412 >> 2)) >> 1))) | (-(v416 ^ ((int)((unsigned int)((int)((unsigned int)v412 >> 2)) >> 1))))) >> 31)) | (~(((v417 ^ ((int)((unsigned int)((int)((unsigned int)v412 >> 2)) >> 1))) | (-(v417 ^ ((int)((unsigned int)((int)((unsigned int)v412 >> 2)) >> 1))))) >> 31))) == 0);
    int v488;
    if (v655) {
      int * v435 = v408->cache_age;
      int v657 = (4 + ((((int)((unsigned int)((int)((unsigned int)v412 >> 2)) >> 1)) & 3) * 2)) + ((~(((v417 ^ ((int)((unsigned int)((int)((unsigned int)v412 >> 2)) >> 1))) | (-(v417 ^ ((int)((unsigned int)((int)((unsigned int)v412 >> 2)) >> 1))))) >> 31)) & 1);
      int v436 = v435[v657];
      int v437 = v435[v642];
      int v658 = v437 + ((int)((unsigned int)(v437 - v436) >> 31));
      v435[v642] = v658;
      int * v439 = v408->cache_age;
      int v440 = v439[v643];
      int v660 = v440 + ((int)((unsigned int)(v440 - v436) >> 31));
      v439[v643] = v660;
      int * v442 = v408->cache_age;
      v442[v657] = 0;
      v488 = v657;
    } else {
      int * v445 = v408->cache_age;
      int v664 = 4 + ((((int)((unsigned int)((int)((unsigned int)v412 >> 2)) >> 1)) & 3) * 2);
      int v446 = v445[v664];
      int * v447 = v408->cache_tags;
      int v448 = v447[v664];
      int v449 = v445[v643];
      int v450 = v447[v643];
      int * v451 = v408->cache_dirty;
      int v667 = (4 + ((((int)((unsigned int)((int)((unsigned int)v412 >> 2)) >> 1)) & 3) * 2)) + ((((v446 + ((~(((v448 ^ -1) | (-(v448 ^ -1))) >> 31)) & 2)) - (v449 + ((~(((v450 ^ -1) | (-(v450 ^ -1))) >> 31)) & 2))) >> 31) & 1);
      int v452 = v451[v667];
      bool v668 = !(v452 == 0);
      if (v668) {
        int * v453 = v408->cache_tags;
        int v454 = v453[v667];
        int * v455 = v408->cache_vals;
        int v671 = ((4 + ((((int)((unsigned int)((int)((unsigned int)v412 >> 2)) >> 1)) & 3) * 2)) + ((((v446 + ((~(((v448 ^ -1) | (-(v448 ^ -1))) >> 31)) & 2)) - (v449 + ((~(((v450 ^ -1) | (-(v450 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
        int v456 = v455[v671];
        int v672 = (((4 + ((((int)((unsigned int)((int)((unsigned int)v412 >> 2)) >> 1)) & 3) * 2)) + ((((v446 + ((~(((v448 ^ -1) | (-(v448 ^ -1))) >> 31)) & 2)) - (v449 + ((~(((v450 ^ -1) | (-(v450 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
        int v457 = v455[v672];
        int * v458 = v408->mem;
        int v674 = v454 * 2;
        v458[v674] = v456;
        int * v460 = v408->mem;
        int v677 = (v454 * 2) + 1;
        v460[v677] = v457;
        ;
      } else {
        ;
      }
      int * v465 = v408->mem;
      int v682 = ((int)((unsigned int)((int)((unsigned int)v412 >> 2)) >> 1)) * 2;
      int v466 = v465[v682];
      int v683 = (((int)((unsigned int)((int)((unsigned int)v412 >> 2)) >> 1)) * 2) + 1;
      int v467 = v465[v683];
      int * v468 = v408->cache_vals;
      int v685 = ((4 + ((((int)((unsigned int)((int)((unsigned int)v412 >> 2)) >> 1)) & 3) * 2)) + ((((v446 + ((~(((v448 ^ -1) | (-(v448 ^ -1))) >> 31)) & 2)) - (v449 + ((~(((v450 ^ -1) | (-(v450 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
      v468[v685] = v466;
      int * v470 = v408->cache_vals;
      int v688 = (((4 + ((((int)((unsigned int)((int)((unsigned int)v412 >> 2)) >> 1)) & 3) * 2)) + ((((v446 + ((~(((v448 ^ -1) | (-(v448 ^ -1))) >> 31)) & 2)) - (v449 + ((~(((v450 ^ -1) | (-(v450 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
      v470[v688] = v467;
      int * v472 = v408->cache_tags;
      int v691 = (int)((unsigned int)((int)((unsigned int)v412 >> 2)) >> 1);
      v472[v667] = v691;
      int * v474 = v408->cache_dirty;
      v474[v667] = 0;
      int * v476 = v408->cache_age;
      v476[v667] = 1;
      int * v478 = v408->cache_age;
      int v479 = v478[v667];
      int v480 = v478[v642];
      int v697 = v480 + ((int)((unsigned int)(v480 - v479) >> 31));
      v478[v642] = v697;
      int * v482 = v408->cache_age;
      int v483 = v482[v643];
      int v699 = v483 + ((int)((unsigned int)(v483 - v479) >> 31));
      v482[v643] = v699;
      int * v485 = v408->cache_age;
      v485[v667] = 0;
      v488 = v667;
    }
    int * v489 = v408->cache_vals;
    int v702 = v488 * 2;
    int v490 = v489[v702];
    int v703 = (v488 * 2) + 1;
    int v491 = v489[v703];
    int v704 = (((((int)((unsigned int)((int)((unsigned int)v412 >> 2)) >> 1)) & 1) * 2) + ((((v430 + ((~(((v432 ^ -1) | (-(v432 ^ -1))) >> 31)) & 2)) - (v433 + ((~(((v434 ^ -1) | (-(v434 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
    v489[v704] = v490;
    int * v493 = v408->cache_vals;
    int v707 = ((((((int)((unsigned int)((int)((unsigned int)v412 >> 2)) >> 1)) & 1) * 2) + ((((v430 + ((~(((v432 ^ -1) | (-(v432 ^ -1))) >> 31)) & 2)) - (v433 + ((~(((v434 ^ -1) | (-(v434 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
    v493[v707] = v491;
    int * v495 = v408->cache_tags;
    int v710 = ((((int)((unsigned int)((int)((unsigned int)v412 >> 2)) >> 1)) & 1) * 2) + ((((v430 + ((~(((v432 ^ -1) | (-(v432 ^ -1))) >> 31)) & 2)) - (v433 + ((~(((v434 ^ -1) | (-(v434 ^ -1))) >> 31)) & 2))) >> 31) & 1);
    int v711 = (int)((unsigned int)((int)((unsigned int)v412 >> 2)) >> 1);
    v495[v710] = v711;
    int * v497 = v408->cache_dirty;
    v497[v710] = 0;
    int * v499 = v408->cache_age;
    v499[v710] = 1;
    int * v501 = v408->cache_age;
    int v502 = v501[v710];
    int v503 = v501[v640];
    int v717 = v503 + ((int)((unsigned int)(v503 - v502) >> 31));
    v501[v640] = v717;
    int * v505 = v408->cache_age;
    int v506 = v505[v641];
    int v719 = v506 + ((int)((unsigned int)(v506 - v502) >> 31));
    v505[v641] = v719;
    int * v508 = v408->cache_age;
    v508[v710] = 0;
    v511 = v710;
  }
  int v722 = (v511 * 2) + (((int)((unsigned int)v412 >> 2)) & 1);
  int v512 = v418[v722];
  int * v513 = v408->reg_ready;
  int v725 = ((v410 + ((v403 - v410) & (~((v403 - v410) >> 31)))) + 1) + ((100 ^ (((~(((v416 ^ ((int)((unsigned int)((int)((unsigned int)v412 >> 2)) >> 1))) | (-(v416 ^ ((int)((unsigned int)((int)((unsigned int)v412 >> 2)) >> 1))))) >> 31)) | (~(((v417 ^ ((int)((unsigned int)((int)((unsigned int)v412 >> 2)) >> 1))) | (-(v417 ^ ((int)((unsigned int)((int)((unsigned int)v412 >> 2)) >> 1))))) >> 31))) & 104)) ^ (((~(((v414 ^ ((int)((unsigned int)((int)((unsigned int)v412 >> 2)) >> 1))) | (-(v414 ^ ((int)((unsigned int)((int)((unsigned int)v412 >> 2)) >> 1))))) >> 31)) | (~(((v415 ^ ((int)((unsigned int)((int)((unsigned int)v412 >> 2)) >> 1))) | (-(v415 ^ ((int)((unsigned int)((int)((unsigned int)v412 >> 2)) >> 1))))) >> 31))) & (1 ^ (100 ^ (((~(((v416 ^ ((int)((unsigned int)((int)((unsigned int)v412 >> 2)) >> 1))) | (-(v416 ^ ((int)((unsigned int)((int)((unsigned int)v412 >> 2)) >> 1))))) >> 31)) | (~(((v417 ^ ((int)((unsigned int)((int)((unsigned int)v412 >> 2)) >> 1))) | (-(v417 ^ ((int)((unsigned int)((int)((unsigned int)v412 >> 2)) >> 1))))) >> 31))) & 104)))));
  v513[7] = v725;
  int * v515 = v408->regs;
  v515[7] = v512;
  struct StateT * v517 = v395->b;
  int * v518 = v517->reg_ready;
  int v519 = v518[6];
  int * v520 = v517->regs;
  int v521 = v520[6];
  int * v522 = v517->cache_tags;
  int v732 = (((int)((unsigned int)((int)((unsigned int)v521 >> 2)) >> 1)) & 1) * 2;
  int v523 = v522[v732];
  int v733 = ((((int)((unsigned int)((int)((unsigned int)v521 >> 2)) >> 1)) & 1) * 2) + 1;
  int v524 = v522[v733];
  int v734 = 4 + ((((int)((unsigned int)((int)((unsigned int)v521 >> 2)) >> 1)) & 3) * 2);
  int v525 = v522[v734];
  int v735 = (4 + ((((int)((unsigned int)((int)((unsigned int)v521 >> 2)) >> 1)) & 3) * 2)) + 1;
  int v526 = v522[v735];
  int * v527 = v517->cache_vals;
  bool v736 = !(((~(((v523 ^ ((int)((unsigned int)((int)((unsigned int)v521 >> 2)) >> 1))) | (-(v523 ^ ((int)((unsigned int)((int)((unsigned int)v521 >> 2)) >> 1))))) >> 31)) | (~(((v524 ^ ((int)((unsigned int)((int)((unsigned int)v521 >> 2)) >> 1))) | (-(v524 ^ ((int)((unsigned int)((int)((unsigned int)v521 >> 2)) >> 1))))) >> 31))) == 0);
  int v620;
  if (v736) {
    int * v528 = v517->cache_age;
    int v738 = ((((int)((unsigned int)((int)((unsigned int)v521 >> 2)) >> 1)) & 1) * 2) + ((~(((v524 ^ ((int)((unsigned int)((int)((unsigned int)v521 >> 2)) >> 1))) | (-(v524 ^ ((int)((unsigned int)((int)((unsigned int)v521 >> 2)) >> 1))))) >> 31)) & 1);
    int v529 = v528[v738];
    int v530 = v528[v732];
    int v739 = v530 + ((int)((unsigned int)(v530 - v529) >> 31));
    v528[v732] = v739;
    int * v532 = v517->cache_age;
    int v533 = v532[v733];
    int v741 = v533 + ((int)((unsigned int)(v533 - v529) >> 31));
    v532[v733] = v741;
    int * v535 = v517->cache_age;
    v535[v738] = 0;
    v620 = v738;
  } else {
    int * v538 = v517->cache_age;
    int v745 = (((int)((unsigned int)((int)((unsigned int)v521 >> 2)) >> 1)) & 1) * 2;
    int v539 = v538[v745];
    int * v540 = v517->cache_tags;
    int v541 = v540[v745];
    int v542 = v538[v733];
    int v543 = v540[v733];
    bool v747 = !(((~(((v525 ^ ((int)((unsigned int)((int)((unsigned int)v521 >> 2)) >> 1))) | (-(v525 ^ ((int)((unsigned int)((int)((unsigned int)v521 >> 2)) >> 1))))) >> 31)) | (~(((v526 ^ ((int)((unsigned int)((int)((unsigned int)v521 >> 2)) >> 1))) | (-(v526 ^ ((int)((unsigned int)((int)((unsigned int)v521 >> 2)) >> 1))))) >> 31))) == 0);
    int v597;
    if (v747) {
      int * v544 = v517->cache_age;
      int v749 = (4 + ((((int)((unsigned int)((int)((unsigned int)v521 >> 2)) >> 1)) & 3) * 2)) + ((~(((v526 ^ ((int)((unsigned int)((int)((unsigned int)v521 >> 2)) >> 1))) | (-(v526 ^ ((int)((unsigned int)((int)((unsigned int)v521 >> 2)) >> 1))))) >> 31)) & 1);
      int v545 = v544[v749];
      int v546 = v544[v734];
      int v750 = v546 + ((int)((unsigned int)(v546 - v545) >> 31));
      v544[v734] = v750;
      int * v548 = v517->cache_age;
      int v549 = v548[v735];
      int v752 = v549 + ((int)((unsigned int)(v549 - v545) >> 31));
      v548[v735] = v752;
      int * v551 = v517->cache_age;
      v551[v749] = 0;
      v597 = v749;
    } else {
      int * v554 = v517->cache_age;
      int v756 = 4 + ((((int)((unsigned int)((int)((unsigned int)v521 >> 2)) >> 1)) & 3) * 2);
      int v555 = v554[v756];
      int * v556 = v517->cache_tags;
      int v557 = v556[v756];
      int v558 = v554[v735];
      int v559 = v556[v735];
      int * v560 = v517->cache_dirty;
      int v759 = (4 + ((((int)((unsigned int)((int)((unsigned int)v521 >> 2)) >> 1)) & 3) * 2)) + ((((v555 + ((~(((v557 ^ -1) | (-(v557 ^ -1))) >> 31)) & 2)) - (v558 + ((~(((v559 ^ -1) | (-(v559 ^ -1))) >> 31)) & 2))) >> 31) & 1);
      int v561 = v560[v759];
      bool v760 = !(v561 == 0);
      if (v760) {
        int * v562 = v517->cache_tags;
        int v563 = v562[v759];
        int * v564 = v517->cache_vals;
        int v763 = ((4 + ((((int)((unsigned int)((int)((unsigned int)v521 >> 2)) >> 1)) & 3) * 2)) + ((((v555 + ((~(((v557 ^ -1) | (-(v557 ^ -1))) >> 31)) & 2)) - (v558 + ((~(((v559 ^ -1) | (-(v559 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
        int v565 = v564[v763];
        int v764 = (((4 + ((((int)((unsigned int)((int)((unsigned int)v521 >> 2)) >> 1)) & 3) * 2)) + ((((v555 + ((~(((v557 ^ -1) | (-(v557 ^ -1))) >> 31)) & 2)) - (v558 + ((~(((v559 ^ -1) | (-(v559 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
        int v566 = v564[v764];
        int * v567 = v517->mem;
        int v766 = v563 * 2;
        v567[v766] = v565;
        int * v569 = v517->mem;
        int v769 = (v563 * 2) + 1;
        v569[v769] = v566;
        ;
      } else {
        ;
      }
      int * v574 = v517->mem;
      int v774 = ((int)((unsigned int)((int)((unsigned int)v521 >> 2)) >> 1)) * 2;
      int v575 = v574[v774];
      int v775 = (((int)((unsigned int)((int)((unsigned int)v521 >> 2)) >> 1)) * 2) + 1;
      int v576 = v574[v775];
      int * v577 = v517->cache_vals;
      int v777 = ((4 + ((((int)((unsigned int)((int)((unsigned int)v521 >> 2)) >> 1)) & 3) * 2)) + ((((v555 + ((~(((v557 ^ -1) | (-(v557 ^ -1))) >> 31)) & 2)) - (v558 + ((~(((v559 ^ -1) | (-(v559 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
      v577[v777] = v575;
      int * v579 = v517->cache_vals;
      int v780 = (((4 + ((((int)((unsigned int)((int)((unsigned int)v521 >> 2)) >> 1)) & 3) * 2)) + ((((v555 + ((~(((v557 ^ -1) | (-(v557 ^ -1))) >> 31)) & 2)) - (v558 + ((~(((v559 ^ -1) | (-(v559 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
      v579[v780] = v576;
      int * v581 = v517->cache_tags;
      int v783 = (int)((unsigned int)((int)((unsigned int)v521 >> 2)) >> 1);
      v581[v759] = v783;
      int * v583 = v517->cache_dirty;
      v583[v759] = 0;
      int * v585 = v517->cache_age;
      v585[v759] = 1;
      int * v587 = v517->cache_age;
      int v588 = v587[v759];
      int v589 = v587[v734];
      int v789 = v589 + ((int)((unsigned int)(v589 - v588) >> 31));
      v587[v734] = v789;
      int * v591 = v517->cache_age;
      int v592 = v591[v735];
      int v791 = v592 + ((int)((unsigned int)(v592 - v588) >> 31));
      v591[v735] = v791;
      int * v594 = v517->cache_age;
      v594[v759] = 0;
      v597 = v759;
    }
    int * v598 = v517->cache_vals;
    int v794 = v597 * 2;
    int v599 = v598[v794];
    int v795 = (v597 * 2) + 1;
    int v600 = v598[v795];
    int v796 = (((((int)((unsigned int)((int)((unsigned int)v521 >> 2)) >> 1)) & 1) * 2) + ((((v539 + ((~(((v541 ^ -1) | (-(v541 ^ -1))) >> 31)) & 2)) - (v542 + ((~(((v543 ^ -1) | (-(v543 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
    v598[v796] = v599;
    int * v602 = v517->cache_vals;
    int v799 = ((((((int)((unsigned int)((int)((unsigned int)v521 >> 2)) >> 1)) & 1) * 2) + ((((v539 + ((~(((v541 ^ -1) | (-(v541 ^ -1))) >> 31)) & 2)) - (v542 + ((~(((v543 ^ -1) | (-(v543 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
    v602[v799] = v600;
    int * v604 = v517->cache_tags;
    int v802 = ((((int)((unsigned int)((int)((unsigned int)v521 >> 2)) >> 1)) & 1) * 2) + ((((v539 + ((~(((v541 ^ -1) | (-(v541 ^ -1))) >> 31)) & 2)) - (v542 + ((~(((v543 ^ -1) | (-(v543 ^ -1))) >> 31)) & 2))) >> 31) & 1);
    int v803 = (int)((unsigned int)((int)((unsigned int)v521 >> 2)) >> 1);
    v604[v802] = v803;
    int * v606 = v517->cache_dirty;
    v606[v802] = 0;
    int * v608 = v517->cache_age;
    v608[v802] = 1;
    int * v610 = v517->cache_age;
    int v611 = v610[v802];
    int v612 = v610[v732];
    int v809 = v612 + ((int)((unsigned int)(v612 - v611) >> 31));
    v610[v732] = v809;
    int * v614 = v517->cache_age;
    int v615 = v614[v733];
    int v811 = v615 + ((int)((unsigned int)(v615 - v611) >> 31));
    v614[v733] = v811;
    int * v617 = v517->cache_age;
    v617[v802] = 0;
    v620 = v802;
  }
  int v814 = (v620 * 2) + (((int)((unsigned int)v521 >> 2)) & 1);
  int v621 = v527[v814];
  int * v622 = v517->reg_ready;
  int v816 = ((v519 + ((v406 - v519) & (~((v406 - v519) >> 31)))) + 1) + ((100 ^ (((~(((v525 ^ ((int)((unsigned int)((int)((unsigned int)v521 >> 2)) >> 1))) | (-(v525 ^ ((int)((unsigned int)((int)((unsigned int)v521 >> 2)) >> 1))))) >> 31)) | (~(((v526 ^ ((int)((unsigned int)((int)((unsigned int)v521 >> 2)) >> 1))) | (-(v526 ^ ((int)((unsigned int)((int)((unsigned int)v521 >> 2)) >> 1))))) >> 31))) & 104)) ^ (((~(((v523 ^ ((int)((unsigned int)((int)((unsigned int)v521 >> 2)) >> 1))) | (-(v523 ^ ((int)((unsigned int)((int)((unsigned int)v521 >> 2)) >> 1))))) >> 31)) | (~(((v524 ^ ((int)((unsigned int)((int)((unsigned int)v521 >> 2)) >> 1))) | (-(v524 ^ ((int)((unsigned int)((int)((unsigned int)v521 >> 2)) >> 1))))) >> 31))) & (1 ^ (100 ^ (((~(((v525 ^ ((int)((unsigned int)((int)((unsigned int)v521 >> 2)) >> 1))) | (-(v525 ^ ((int)((unsigned int)((int)((unsigned int)v521 >> 2)) >> 1))))) >> 31)) | (~(((v526 ^ ((int)((unsigned int)((int)((unsigned int)v521 >> 2)) >> 1))) | (-(v526 ^ ((int)((unsigned int)((int)((unsigned int)v521 >> 2)) >> 1))))) >> 31))) & 104)))));
  v622[7] = v816;
  int * v624 = v517->regs;
  v624[7] = v621;
  struct StateT2 * v626 = slot_8(v395);
  return v626;
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
  struct StateT * v1502 = v1->a;
  int v1503 = v1502->timer;
  int * v1504 = v1502->reg_ready;
  int v1505 = v1504[0];
  int v1766 = v1505 + ((v1503 - v1505) & (~((v1503 - v1505) >> 31)));
  v1502->timer = v1766;
  int v1507 = v1502->timer;
  int * v1508 = v1502->reg_ready;
  int v1509 = v1508[1];
  int v1769 = v1509 + ((v1507 - v1509) & (~((v1507 - v1509) >> 31)));
  v1502->timer = v1769;
  int v1511 = v1502->timer;
  int * v1512 = v1502->reg_ready;
  int v1513 = v1512[2];
  int v1772 = v1513 + ((v1511 - v1513) & (~((v1511 - v1513) >> 31)));
  v1502->timer = v1772;
  int v1515 = v1502->timer;
  int * v1516 = v1502->reg_ready;
  int v1517 = v1516[3];
  int v1775 = v1517 + ((v1515 - v1517) & (~((v1515 - v1517) >> 31)));
  v1502->timer = v1775;
  int v1519 = v1502->timer;
  int * v1520 = v1502->reg_ready;
  int v1521 = v1520[4];
  int v1778 = v1521 + ((v1519 - v1521) & (~((v1519 - v1521) >> 31)));
  v1502->timer = v1778;
  int v1523 = v1502->timer;
  int * v1524 = v1502->reg_ready;
  int v1525 = v1524[5];
  int v1781 = v1525 + ((v1523 - v1525) & (~((v1523 - v1525) >> 31)));
  v1502->timer = v1781;
  int v1527 = v1502->timer;
  int * v1528 = v1502->reg_ready;
  int v1529 = v1528[6];
  int v1784 = v1529 + ((v1527 - v1529) & (~((v1527 - v1529) >> 31)));
  v1502->timer = v1784;
  int v1531 = v1502->timer;
  int * v1532 = v1502->reg_ready;
  int v1533 = v1532[7];
  int v1787 = v1533 + ((v1531 - v1533) & (~((v1531 - v1533) >> 31)));
  v1502->timer = v1787;
  int v1535 = v1502->timer;
  int * v1536 = v1502->reg_ready;
  int v1537 = v1536[8];
  int v1790 = v1537 + ((v1535 - v1537) & (~((v1535 - v1537) >> 31)));
  v1502->timer = v1790;
  int v1539 = v1502->timer;
  int * v1540 = v1502->reg_ready;
  int v1541 = v1540[9];
  int v1793 = v1541 + ((v1539 - v1541) & (~((v1539 - v1541) >> 31)));
  v1502->timer = v1793;
  int v1543 = v1502->timer;
  int * v1544 = v1502->reg_ready;
  int v1545 = v1544[10];
  int v1796 = v1545 + ((v1543 - v1545) & (~((v1543 - v1545) >> 31)));
  v1502->timer = v1796;
  int v1547 = v1502->timer;
  int * v1548 = v1502->reg_ready;
  int v1549 = v1548[11];
  int v1799 = v1549 + ((v1547 - v1549) & (~((v1547 - v1549) >> 31)));
  v1502->timer = v1799;
  int v1551 = v1502->timer;
  int * v1552 = v1502->reg_ready;
  int v1553 = v1552[12];
  int v1802 = v1553 + ((v1551 - v1553) & (~((v1551 - v1553) >> 31)));
  v1502->timer = v1802;
  int v1555 = v1502->timer;
  int * v1556 = v1502->reg_ready;
  int v1557 = v1556[13];
  int v1805 = v1557 + ((v1555 - v1557) & (~((v1555 - v1557) >> 31)));
  v1502->timer = v1805;
  int v1559 = v1502->timer;
  int * v1560 = v1502->reg_ready;
  int v1561 = v1560[14];
  int v1808 = v1561 + ((v1559 - v1561) & (~((v1559 - v1561) >> 31)));
  v1502->timer = v1808;
  int v1563 = v1502->timer;
  int * v1564 = v1502->reg_ready;
  int v1565 = v1564[15];
  int v1811 = v1565 + ((v1563 - v1565) & (~((v1563 - v1565) >> 31)));
  v1502->timer = v1811;
  int v1567 = v1502->timer;
  int * v1568 = v1502->reg_ready;
  int v1569 = v1568[16];
  int v1814 = v1569 + ((v1567 - v1569) & (~((v1567 - v1569) >> 31)));
  v1502->timer = v1814;
  int v1571 = v1502->timer;
  int * v1572 = v1502->reg_ready;
  int v1573 = v1572[17];
  int v1817 = v1573 + ((v1571 - v1573) & (~((v1571 - v1573) >> 31)));
  v1502->timer = v1817;
  int v1575 = v1502->timer;
  int * v1576 = v1502->reg_ready;
  int v1577 = v1576[18];
  int v1820 = v1577 + ((v1575 - v1577) & (~((v1575 - v1577) >> 31)));
  v1502->timer = v1820;
  int v1579 = v1502->timer;
  int * v1580 = v1502->reg_ready;
  int v1581 = v1580[19];
  int v1823 = v1581 + ((v1579 - v1581) & (~((v1579 - v1581) >> 31)));
  v1502->timer = v1823;
  int v1583 = v1502->timer;
  int * v1584 = v1502->reg_ready;
  int v1585 = v1584[20];
  int v1826 = v1585 + ((v1583 - v1585) & (~((v1583 - v1585) >> 31)));
  v1502->timer = v1826;
  int v1587 = v1502->timer;
  int * v1588 = v1502->reg_ready;
  int v1589 = v1588[21];
  int v1829 = v1589 + ((v1587 - v1589) & (~((v1587 - v1589) >> 31)));
  v1502->timer = v1829;
  int v1591 = v1502->timer;
  int * v1592 = v1502->reg_ready;
  int v1593 = v1592[22];
  int v1832 = v1593 + ((v1591 - v1593) & (~((v1591 - v1593) >> 31)));
  v1502->timer = v1832;
  int v1595 = v1502->timer;
  int * v1596 = v1502->reg_ready;
  int v1597 = v1596[23];
  int v1835 = v1597 + ((v1595 - v1597) & (~((v1595 - v1597) >> 31)));
  v1502->timer = v1835;
  int v1599 = v1502->timer;
  int * v1600 = v1502->reg_ready;
  int v1601 = v1600[24];
  int v1838 = v1601 + ((v1599 - v1601) & (~((v1599 - v1601) >> 31)));
  v1502->timer = v1838;
  int v1603 = v1502->timer;
  int * v1604 = v1502->reg_ready;
  int v1605 = v1604[25];
  int v1841 = v1605 + ((v1603 - v1605) & (~((v1603 - v1605) >> 31)));
  v1502->timer = v1841;
  int v1607 = v1502->timer;
  int * v1608 = v1502->reg_ready;
  int v1609 = v1608[26];
  int v1844 = v1609 + ((v1607 - v1609) & (~((v1607 - v1609) >> 31)));
  v1502->timer = v1844;
  int v1611 = v1502->timer;
  int * v1612 = v1502->reg_ready;
  int v1613 = v1612[27];
  int v1847 = v1613 + ((v1611 - v1613) & (~((v1611 - v1613) >> 31)));
  v1502->timer = v1847;
  int v1615 = v1502->timer;
  int * v1616 = v1502->reg_ready;
  int v1617 = v1616[28];
  int v1850 = v1617 + ((v1615 - v1617) & (~((v1615 - v1617) >> 31)));
  v1502->timer = v1850;
  int v1619 = v1502->timer;
  int * v1620 = v1502->reg_ready;
  int v1621 = v1620[29];
  int v1853 = v1621 + ((v1619 - v1621) & (~((v1619 - v1621) >> 31)));
  v1502->timer = v1853;
  int v1623 = v1502->timer;
  int * v1624 = v1502->reg_ready;
  int v1625 = v1624[30];
  int v1856 = v1625 + ((v1623 - v1625) & (~((v1623 - v1625) >> 31)));
  v1502->timer = v1856;
  int v1627 = v1502->timer;
  int * v1628 = v1502->reg_ready;
  int v1629 = v1628[31];
  int v1859 = v1629 + ((v1627 - v1629) & (~((v1627 - v1629) >> 31)));
  v1502->timer = v1859;
  struct StateT * v1631 = v1->b;
  int v1632 = v1631->timer;
  int * v1633 = v1631->reg_ready;
  int v1634 = v1633[0];
  int v1862 = v1634 + ((v1632 - v1634) & (~((v1632 - v1634) >> 31)));
  v1631->timer = v1862;
  int v1636 = v1631->timer;
  int * v1637 = v1631->reg_ready;
  int v1638 = v1637[1];
  int v1864 = v1638 + ((v1636 - v1638) & (~((v1636 - v1638) >> 31)));
  v1631->timer = v1864;
  int v1640 = v1631->timer;
  int * v1641 = v1631->reg_ready;
  int v1642 = v1641[2];
  int v1866 = v1642 + ((v1640 - v1642) & (~((v1640 - v1642) >> 31)));
  v1631->timer = v1866;
  int v1644 = v1631->timer;
  int * v1645 = v1631->reg_ready;
  int v1646 = v1645[3];
  int v1868 = v1646 + ((v1644 - v1646) & (~((v1644 - v1646) >> 31)));
  v1631->timer = v1868;
  int v1648 = v1631->timer;
  int * v1649 = v1631->reg_ready;
  int v1650 = v1649[4];
  int v1870 = v1650 + ((v1648 - v1650) & (~((v1648 - v1650) >> 31)));
  v1631->timer = v1870;
  int v1652 = v1631->timer;
  int * v1653 = v1631->reg_ready;
  int v1654 = v1653[5];
  int v1872 = v1654 + ((v1652 - v1654) & (~((v1652 - v1654) >> 31)));
  v1631->timer = v1872;
  int v1656 = v1631->timer;
  int * v1657 = v1631->reg_ready;
  int v1658 = v1657[6];
  int v1874 = v1658 + ((v1656 - v1658) & (~((v1656 - v1658) >> 31)));
  v1631->timer = v1874;
  int v1660 = v1631->timer;
  int * v1661 = v1631->reg_ready;
  int v1662 = v1661[7];
  int v1876 = v1662 + ((v1660 - v1662) & (~((v1660 - v1662) >> 31)));
  v1631->timer = v1876;
  int v1664 = v1631->timer;
  int * v1665 = v1631->reg_ready;
  int v1666 = v1665[8];
  int v1878 = v1666 + ((v1664 - v1666) & (~((v1664 - v1666) >> 31)));
  v1631->timer = v1878;
  int v1668 = v1631->timer;
  int * v1669 = v1631->reg_ready;
  int v1670 = v1669[9];
  int v1880 = v1670 + ((v1668 - v1670) & (~((v1668 - v1670) >> 31)));
  v1631->timer = v1880;
  int v1672 = v1631->timer;
  int * v1673 = v1631->reg_ready;
  int v1674 = v1673[10];
  int v1882 = v1674 + ((v1672 - v1674) & (~((v1672 - v1674) >> 31)));
  v1631->timer = v1882;
  int v1676 = v1631->timer;
  int * v1677 = v1631->reg_ready;
  int v1678 = v1677[11];
  int v1884 = v1678 + ((v1676 - v1678) & (~((v1676 - v1678) >> 31)));
  v1631->timer = v1884;
  int v1680 = v1631->timer;
  int * v1681 = v1631->reg_ready;
  int v1682 = v1681[12];
  int v1886 = v1682 + ((v1680 - v1682) & (~((v1680 - v1682) >> 31)));
  v1631->timer = v1886;
  int v1684 = v1631->timer;
  int * v1685 = v1631->reg_ready;
  int v1686 = v1685[13];
  int v1888 = v1686 + ((v1684 - v1686) & (~((v1684 - v1686) >> 31)));
  v1631->timer = v1888;
  int v1688 = v1631->timer;
  int * v1689 = v1631->reg_ready;
  int v1690 = v1689[14];
  int v1890 = v1690 + ((v1688 - v1690) & (~((v1688 - v1690) >> 31)));
  v1631->timer = v1890;
  int v1692 = v1631->timer;
  int * v1693 = v1631->reg_ready;
  int v1694 = v1693[15];
  int v1892 = v1694 + ((v1692 - v1694) & (~((v1692 - v1694) >> 31)));
  v1631->timer = v1892;
  int v1696 = v1631->timer;
  int * v1697 = v1631->reg_ready;
  int v1698 = v1697[16];
  int v1894 = v1698 + ((v1696 - v1698) & (~((v1696 - v1698) >> 31)));
  v1631->timer = v1894;
  int v1700 = v1631->timer;
  int * v1701 = v1631->reg_ready;
  int v1702 = v1701[17];
  int v1896 = v1702 + ((v1700 - v1702) & (~((v1700 - v1702) >> 31)));
  v1631->timer = v1896;
  int v1704 = v1631->timer;
  int * v1705 = v1631->reg_ready;
  int v1706 = v1705[18];
  int v1898 = v1706 + ((v1704 - v1706) & (~((v1704 - v1706) >> 31)));
  v1631->timer = v1898;
  int v1708 = v1631->timer;
  int * v1709 = v1631->reg_ready;
  int v1710 = v1709[19];
  int v1900 = v1710 + ((v1708 - v1710) & (~((v1708 - v1710) >> 31)));
  v1631->timer = v1900;
  int v1712 = v1631->timer;
  int * v1713 = v1631->reg_ready;
  int v1714 = v1713[20];
  int v1902 = v1714 + ((v1712 - v1714) & (~((v1712 - v1714) >> 31)));
  v1631->timer = v1902;
  int v1716 = v1631->timer;
  int * v1717 = v1631->reg_ready;
  int v1718 = v1717[21];
  int v1904 = v1718 + ((v1716 - v1718) & (~((v1716 - v1718) >> 31)));
  v1631->timer = v1904;
  int v1720 = v1631->timer;
  int * v1721 = v1631->reg_ready;
  int v1722 = v1721[22];
  int v1906 = v1722 + ((v1720 - v1722) & (~((v1720 - v1722) >> 31)));
  v1631->timer = v1906;
  int v1724 = v1631->timer;
  int * v1725 = v1631->reg_ready;
  int v1726 = v1725[23];
  int v1908 = v1726 + ((v1724 - v1726) & (~((v1724 - v1726) >> 31)));
  v1631->timer = v1908;
  int v1728 = v1631->timer;
  int * v1729 = v1631->reg_ready;
  int v1730 = v1729[24];
  int v1910 = v1730 + ((v1728 - v1730) & (~((v1728 - v1730) >> 31)));
  v1631->timer = v1910;
  int v1732 = v1631->timer;
  int * v1733 = v1631->reg_ready;
  int v1734 = v1733[25];
  int v1912 = v1734 + ((v1732 - v1734) & (~((v1732 - v1734) >> 31)));
  v1631->timer = v1912;
  int v1736 = v1631->timer;
  int * v1737 = v1631->reg_ready;
  int v1738 = v1737[26];
  int v1914 = v1738 + ((v1736 - v1738) & (~((v1736 - v1738) >> 31)));
  v1631->timer = v1914;
  int v1740 = v1631->timer;
  int * v1741 = v1631->reg_ready;
  int v1742 = v1741[27];
  int v1916 = v1742 + ((v1740 - v1742) & (~((v1740 - v1742) >> 31)));
  v1631->timer = v1916;
  int v1744 = v1631->timer;
  int * v1745 = v1631->reg_ready;
  int v1746 = v1745[28];
  int v1918 = v1746 + ((v1744 - v1746) & (~((v1744 - v1746) >> 31)));
  v1631->timer = v1918;
  int v1748 = v1631->timer;
  int * v1749 = v1631->reg_ready;
  int v1750 = v1749[29];
  int v1920 = v1750 + ((v1748 - v1750) & (~((v1748 - v1750) >> 31)));
  v1631->timer = v1920;
  int v1752 = v1631->timer;
  int * v1753 = v1631->reg_ready;
  int v1754 = v1753[30];
  int v1922 = v1754 + ((v1752 - v1754) & (~((v1752 - v1754) >> 31)));
  v1631->timer = v1922;
  int v1756 = v1631->timer;
  int * v1757 = v1631->reg_ready;
  int v1758 = v1757[31];
  int v1924 = v1758 + ((v1756 - v1758) & (~((v1756 - v1758) >> 31)));
  v1631->timer = v1924;
  return v1;
}

struct StateT2 * slot_10(struct StateT2 * v1306) {
  struct StateT * v1307 = v1306->a;
  int v1308 = v1307->timer;
  struct StateT * v1309 = v1306->b;
  int v1310 = v1309->timer;
  bool v1343 = v1308 == v1310;
  squared_assert(v1343);
  squared_assume(v1343);
  struct StateT * v1313 = v1306->a;
  int v1314 = v1313->timer;
  int v1345 = v1314 + 1;
  v1313->timer = v1345;
  struct StateT * v1316 = v1306->b;
  int v1317 = v1316->timer;
  int v1347 = v1317 + 1;
  v1316->timer = v1347;
  struct StateT * v1319 = v1306->a;
  int * v1320 = v1319->reg_ready;
  int v1321 = v1320[7];
  int * v1322 = v1319->regs;
  int v1323 = v1322[7];
  int v1324 = v1320[9];
  int v1325 = v1322[9];
  int v1354 = (v1324 + (((v1321 + ((v1314 - v1321) & (~((v1314 - v1321) >> 31)))) - v1324) & (~(((v1321 + ((v1314 - v1321) & (~((v1314 - v1321) >> 31)))) - v1324) >> 31)))) + 1;
  v1320[16] = v1354;
  int * v1327 = v1319->regs;
  int v1356 = v1323 ^ v1325;
  v1327[16] = v1356;
  struct StateT * v1329 = v1306->b;
  int * v1330 = v1329->reg_ready;
  int v1331 = v1330[7];
  int * v1332 = v1329->regs;
  int v1333 = v1332[7];
  int v1334 = v1330[9];
  int v1335 = v1332[9];
  int v1360 = (v1334 + (((v1331 + ((v1317 - v1331) & (~((v1317 - v1331) >> 31)))) - v1334) & (~(((v1331 + ((v1317 - v1331) & (~((v1317 - v1331) >> 31)))) - v1334) >> 31)))) + 1;
  v1330[16] = v1360;
  int * v1337 = v1329->regs;
  int v1362 = v1333 ^ v1335;
  v1337[16] = v1362;
  struct StateT2 * v1339 = slot_11(v1306);
  return v1339;
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

struct StateT2 * slot_8(struct StateT2 * v821) {
  struct StateT * v822 = v821->a;
  int v823 = v822->timer;
  struct StateT * v824 = v821->b;
  int v825 = v824->timer;
  bool v858 = v823 == v825;
  squared_assert(v858);
  squared_assume(v858);
  struct StateT * v828 = v821->a;
  int v829 = v828->timer;
  int v860 = v829 + 1;
  v828->timer = v860;
  struct StateT * v831 = v821->b;
  int v832 = v831->timer;
  int v862 = v832 + 1;
  v831->timer = v862;
  struct StateT * v834 = v821->a;
  int * v835 = v834->reg_ready;
  int v836 = v835[13];
  int * v837 = v834->regs;
  int v838 = v837[13];
  int v839 = v835[14];
  int v840 = v837[14];
  int v869 = (v839 + (((v836 + ((v829 - v836) & (~((v829 - v836) >> 31)))) - v839) & (~(((v836 + ((v829 - v836) & (~((v829 - v836) >> 31)))) - v839) >> 31)))) + 1;
  v835[8] = v869;
  int * v842 = v834->regs;
  int v871 = v838 + v840;
  v842[8] = v871;
  struct StateT * v844 = v821->b;
  int * v845 = v844->reg_ready;
  int v846 = v845[13];
  int * v847 = v844->regs;
  int v848 = v847[13];
  int v849 = v845[14];
  int v850 = v847[14];
  int v875 = (v849 + (((v846 + ((v832 - v846) & (~((v832 - v846) >> 31)))) - v849) & (~(((v846 + ((v832 - v846) & (~((v832 - v846) >> 31)))) - v849) >> 31)))) + 1;
  v845[8] = v875;
  int * v852 = v844->regs;
  int v877 = v848 + v850;
  v852[8] = v877;
  struct StateT2 * v854 = slot_9(v821);
  return v854;
}

struct StateT2 * slot_4(struct StateT2 * v170) {
  struct StateT * v171 = v170->a;
  int v172 = v171->timer;
  struct StateT * v173 = v170->b;
  int v174 = v173->timer;
  bool v197 = v172 == v174;
  squared_assert(v197);
  squared_assume(v197);
  struct StateT * v177 = v170->a;
  int v178 = v177->timer;
  int v199 = v178 + 1;
  v177->timer = v199;
  struct StateT * v180 = v170->b;
  int v181 = v180->timer;
  int v201 = v181 + 1;
  v180->timer = v201;
  struct StateT * v183 = v170->a;
  int * v184 = v183->reg_ready;
  v184[5] = v199;
  int * v186 = v183->regs;
  v186[5] = 0;
  struct StateT * v188 = v170->b;
  int * v189 = v188->reg_ready;
  v189[5] = v201;
  int * v191 = v188->regs;
  v191[5] = 0;
  struct StateT2 * v193 = slot_5(v170);
  return v193;
}

struct StateT2 * slot_13(struct StateT2 * v1476) {
  struct StateT * v1477 = v1476->a;
  int v1478 = v1477->timer;
  struct StateT * v1479 = v1476->b;
  int v1480 = v1479->timer;
  bool v1495 = v1478 == v1480;
  squared_assert(v1495);
  squared_assume(v1495);
  struct StateT * v1483 = v1476->a;
  int v1484 = v1483->timer;
  int v1497 = v1484 + 1;
  v1483->timer = v1497;
  struct StateT * v1486 = v1476->b;
  int v1487 = v1486->timer;
  int v1499 = v1487 + 1;
  v1486->timer = v1499;
  struct StateT2 * v1491 = slot_5(v1476);
  return v1491;
}

struct StateT2 * slot_9(struct StateT2 * v880) {
  struct StateT * v881 = v880->a;
  int v882 = v881->timer;
  struct StateT * v883 = v880->b;
  int v884 = v883->timer;
  bool v1115 = v882 == v884;
  squared_assert(v1115);
  squared_assume(v1115);
  struct StateT * v887 = v880->a;
  int v888 = v887->timer;
  int v1117 = v888 + 1;
  v887->timer = v1117;
  struct StateT * v890 = v880->b;
  int v891 = v890->timer;
  int v1119 = v891 + 1;
  v890->timer = v1119;
  struct StateT * v893 = v880->a;
  int * v894 = v893->reg_ready;
  int v895 = v894[8];
  int * v896 = v893->regs;
  int v897 = v896[8];
  int * v898 = v893->cache_tags;
  int v1125 = (((int)((unsigned int)((int)((unsigned int)v897 >> 2)) >> 1)) & 1) * 2;
  int v899 = v898[v1125];
  int v1126 = ((((int)((unsigned int)((int)((unsigned int)v897 >> 2)) >> 1)) & 1) * 2) + 1;
  int v900 = v898[v1126];
  int v1127 = 4 + ((((int)((unsigned int)((int)((unsigned int)v897 >> 2)) >> 1)) & 3) * 2);
  int v901 = v898[v1127];
  int v1128 = (4 + ((((int)((unsigned int)((int)((unsigned int)v897 >> 2)) >> 1)) & 3) * 2)) + 1;
  int v902 = v898[v1128];
  int * v903 = v893->cache_vals;
  bool v1129 = !(((~(((v899 ^ ((int)((unsigned int)((int)((unsigned int)v897 >> 2)) >> 1))) | (-(v899 ^ ((int)((unsigned int)((int)((unsigned int)v897 >> 2)) >> 1))))) >> 31)) | (~(((v900 ^ ((int)((unsigned int)((int)((unsigned int)v897 >> 2)) >> 1))) | (-(v900 ^ ((int)((unsigned int)((int)((unsigned int)v897 >> 2)) >> 1))))) >> 31))) == 0);
  int v996;
  if (v1129) {
    int * v904 = v893->cache_age;
    int v1131 = ((((int)((unsigned int)((int)((unsigned int)v897 >> 2)) >> 1)) & 1) * 2) + ((~(((v900 ^ ((int)((unsigned int)((int)((unsigned int)v897 >> 2)) >> 1))) | (-(v900 ^ ((int)((unsigned int)((int)((unsigned int)v897 >> 2)) >> 1))))) >> 31)) & 1);
    int v905 = v904[v1131];
    int v906 = v904[v1125];
    int v1132 = v906 + ((int)((unsigned int)(v906 - v905) >> 31));
    v904[v1125] = v1132;
    int * v908 = v893->cache_age;
    int v909 = v908[v1126];
    int v1134 = v909 + ((int)((unsigned int)(v909 - v905) >> 31));
    v908[v1126] = v1134;
    int * v911 = v893->cache_age;
    v911[v1131] = 0;
    v996 = v1131;
  } else {
    int * v914 = v893->cache_age;
    int v1138 = (((int)((unsigned int)((int)((unsigned int)v897 >> 2)) >> 1)) & 1) * 2;
    int v915 = v914[v1138];
    int * v916 = v893->cache_tags;
    int v917 = v916[v1138];
    int v918 = v914[v1126];
    int v919 = v916[v1126];
    bool v1140 = !(((~(((v901 ^ ((int)((unsigned int)((int)((unsigned int)v897 >> 2)) >> 1))) | (-(v901 ^ ((int)((unsigned int)((int)((unsigned int)v897 >> 2)) >> 1))))) >> 31)) | (~(((v902 ^ ((int)((unsigned int)((int)((unsigned int)v897 >> 2)) >> 1))) | (-(v902 ^ ((int)((unsigned int)((int)((unsigned int)v897 >> 2)) >> 1))))) >> 31))) == 0);
    int v973;
    if (v1140) {
      int * v920 = v893->cache_age;
      int v1142 = (4 + ((((int)((unsigned int)((int)((unsigned int)v897 >> 2)) >> 1)) & 3) * 2)) + ((~(((v902 ^ ((int)((unsigned int)((int)((unsigned int)v897 >> 2)) >> 1))) | (-(v902 ^ ((int)((unsigned int)((int)((unsigned int)v897 >> 2)) >> 1))))) >> 31)) & 1);
      int v921 = v920[v1142];
      int v922 = v920[v1127];
      int v1143 = v922 + ((int)((unsigned int)(v922 - v921) >> 31));
      v920[v1127] = v1143;
      int * v924 = v893->cache_age;
      int v925 = v924[v1128];
      int v1145 = v925 + ((int)((unsigned int)(v925 - v921) >> 31));
      v924[v1128] = v1145;
      int * v927 = v893->cache_age;
      v927[v1142] = 0;
      v973 = v1142;
    } else {
      int * v930 = v893->cache_age;
      int v1149 = 4 + ((((int)((unsigned int)((int)((unsigned int)v897 >> 2)) >> 1)) & 3) * 2);
      int v931 = v930[v1149];
      int * v932 = v893->cache_tags;
      int v933 = v932[v1149];
      int v934 = v930[v1128];
      int v935 = v932[v1128];
      int * v936 = v893->cache_dirty;
      int v1152 = (4 + ((((int)((unsigned int)((int)((unsigned int)v897 >> 2)) >> 1)) & 3) * 2)) + ((((v931 + ((~(((v933 ^ -1) | (-(v933 ^ -1))) >> 31)) & 2)) - (v934 + ((~(((v935 ^ -1) | (-(v935 ^ -1))) >> 31)) & 2))) >> 31) & 1);
      int v937 = v936[v1152];
      bool v1153 = !(v937 == 0);
      if (v1153) {
        int * v938 = v893->cache_tags;
        int v939 = v938[v1152];
        int * v940 = v893->cache_vals;
        int v1156 = ((4 + ((((int)((unsigned int)((int)((unsigned int)v897 >> 2)) >> 1)) & 3) * 2)) + ((((v931 + ((~(((v933 ^ -1) | (-(v933 ^ -1))) >> 31)) & 2)) - (v934 + ((~(((v935 ^ -1) | (-(v935 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
        int v941 = v940[v1156];
        int v1157 = (((4 + ((((int)((unsigned int)((int)((unsigned int)v897 >> 2)) >> 1)) & 3) * 2)) + ((((v931 + ((~(((v933 ^ -1) | (-(v933 ^ -1))) >> 31)) & 2)) - (v934 + ((~(((v935 ^ -1) | (-(v935 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
        int v942 = v940[v1157];
        int * v943 = v893->mem;
        int v1159 = v939 * 2;
        v943[v1159] = v941;
        int * v945 = v893->mem;
        int v1162 = (v939 * 2) + 1;
        v945[v1162] = v942;
        ;
      } else {
        ;
      }
      int * v950 = v893->mem;
      int v1167 = ((int)((unsigned int)((int)((unsigned int)v897 >> 2)) >> 1)) * 2;
      int v951 = v950[v1167];
      int v1168 = (((int)((unsigned int)((int)((unsigned int)v897 >> 2)) >> 1)) * 2) + 1;
      int v952 = v950[v1168];
      int * v953 = v893->cache_vals;
      int v1170 = ((4 + ((((int)((unsigned int)((int)((unsigned int)v897 >> 2)) >> 1)) & 3) * 2)) + ((((v931 + ((~(((v933 ^ -1) | (-(v933 ^ -1))) >> 31)) & 2)) - (v934 + ((~(((v935 ^ -1) | (-(v935 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
      v953[v1170] = v951;
      int * v955 = v893->cache_vals;
      int v1173 = (((4 + ((((int)((unsigned int)((int)((unsigned int)v897 >> 2)) >> 1)) & 3) * 2)) + ((((v931 + ((~(((v933 ^ -1) | (-(v933 ^ -1))) >> 31)) & 2)) - (v934 + ((~(((v935 ^ -1) | (-(v935 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
      v955[v1173] = v952;
      int * v957 = v893->cache_tags;
      int v1176 = (int)((unsigned int)((int)((unsigned int)v897 >> 2)) >> 1);
      v957[v1152] = v1176;
      int * v959 = v893->cache_dirty;
      v959[v1152] = 0;
      int * v961 = v893->cache_age;
      v961[v1152] = 1;
      int * v963 = v893->cache_age;
      int v964 = v963[v1152];
      int v965 = v963[v1127];
      int v1182 = v965 + ((int)((unsigned int)(v965 - v964) >> 31));
      v963[v1127] = v1182;
      int * v967 = v893->cache_age;
      int v968 = v967[v1128];
      int v1184 = v968 + ((int)((unsigned int)(v968 - v964) >> 31));
      v967[v1128] = v1184;
      int * v970 = v893->cache_age;
      v970[v1152] = 0;
      v973 = v1152;
    }
    int * v974 = v893->cache_vals;
    int v1187 = v973 * 2;
    int v975 = v974[v1187];
    int v1188 = (v973 * 2) + 1;
    int v976 = v974[v1188];
    int v1189 = (((((int)((unsigned int)((int)((unsigned int)v897 >> 2)) >> 1)) & 1) * 2) + ((((v915 + ((~(((v917 ^ -1) | (-(v917 ^ -1))) >> 31)) & 2)) - (v918 + ((~(((v919 ^ -1) | (-(v919 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
    v974[v1189] = v975;
    int * v978 = v893->cache_vals;
    int v1192 = ((((((int)((unsigned int)((int)((unsigned int)v897 >> 2)) >> 1)) & 1) * 2) + ((((v915 + ((~(((v917 ^ -1) | (-(v917 ^ -1))) >> 31)) & 2)) - (v918 + ((~(((v919 ^ -1) | (-(v919 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
    v978[v1192] = v976;
    int * v980 = v893->cache_tags;
    int v1195 = ((((int)((unsigned int)((int)((unsigned int)v897 >> 2)) >> 1)) & 1) * 2) + ((((v915 + ((~(((v917 ^ -1) | (-(v917 ^ -1))) >> 31)) & 2)) - (v918 + ((~(((v919 ^ -1) | (-(v919 ^ -1))) >> 31)) & 2))) >> 31) & 1);
    int v1196 = (int)((unsigned int)((int)((unsigned int)v897 >> 2)) >> 1);
    v980[v1195] = v1196;
    int * v982 = v893->cache_dirty;
    v982[v1195] = 0;
    int * v984 = v893->cache_age;
    v984[v1195] = 1;
    int * v986 = v893->cache_age;
    int v987 = v986[v1195];
    int v988 = v986[v1125];
    int v1202 = v988 + ((int)((unsigned int)(v988 - v987) >> 31));
    v986[v1125] = v1202;
    int * v990 = v893->cache_age;
    int v991 = v990[v1126];
    int v1204 = v991 + ((int)((unsigned int)(v991 - v987) >> 31));
    v990[v1126] = v1204;
    int * v993 = v893->cache_age;
    v993[v1195] = 0;
    v996 = v1195;
  }
  int v1207 = (v996 * 2) + (((int)((unsigned int)v897 >> 2)) & 1);
  int v997 = v903[v1207];
  int * v998 = v893->reg_ready;
  int v1210 = ((v895 + ((v888 - v895) & (~((v888 - v895) >> 31)))) + 1) + ((100 ^ (((~(((v901 ^ ((int)((unsigned int)((int)((unsigned int)v897 >> 2)) >> 1))) | (-(v901 ^ ((int)((unsigned int)((int)((unsigned int)v897 >> 2)) >> 1))))) >> 31)) | (~(((v902 ^ ((int)((unsigned int)((int)((unsigned int)v897 >> 2)) >> 1))) | (-(v902 ^ ((int)((unsigned int)((int)((unsigned int)v897 >> 2)) >> 1))))) >> 31))) & 104)) ^ (((~(((v899 ^ ((int)((unsigned int)((int)((unsigned int)v897 >> 2)) >> 1))) | (-(v899 ^ ((int)((unsigned int)((int)((unsigned int)v897 >> 2)) >> 1))))) >> 31)) | (~(((v900 ^ ((int)((unsigned int)((int)((unsigned int)v897 >> 2)) >> 1))) | (-(v900 ^ ((int)((unsigned int)((int)((unsigned int)v897 >> 2)) >> 1))))) >> 31))) & (1 ^ (100 ^ (((~(((v901 ^ ((int)((unsigned int)((int)((unsigned int)v897 >> 2)) >> 1))) | (-(v901 ^ ((int)((unsigned int)((int)((unsigned int)v897 >> 2)) >> 1))))) >> 31)) | (~(((v902 ^ ((int)((unsigned int)((int)((unsigned int)v897 >> 2)) >> 1))) | (-(v902 ^ ((int)((unsigned int)((int)((unsigned int)v897 >> 2)) >> 1))))) >> 31))) & 104)))));
  v998[9] = v1210;
  int * v1000 = v893->regs;
  v1000[9] = v997;
  struct StateT * v1002 = v880->b;
  int * v1003 = v1002->reg_ready;
  int v1004 = v1003[8];
  int * v1005 = v1002->regs;
  int v1006 = v1005[8];
  int * v1007 = v1002->cache_tags;
  int v1217 = (((int)((unsigned int)((int)((unsigned int)v1006 >> 2)) >> 1)) & 1) * 2;
  int v1008 = v1007[v1217];
  int v1218 = ((((int)((unsigned int)((int)((unsigned int)v1006 >> 2)) >> 1)) & 1) * 2) + 1;
  int v1009 = v1007[v1218];
  int v1219 = 4 + ((((int)((unsigned int)((int)((unsigned int)v1006 >> 2)) >> 1)) & 3) * 2);
  int v1010 = v1007[v1219];
  int v1220 = (4 + ((((int)((unsigned int)((int)((unsigned int)v1006 >> 2)) >> 1)) & 3) * 2)) + 1;
  int v1011 = v1007[v1220];
  int * v1012 = v1002->cache_vals;
  bool v1221 = !(((~(((v1008 ^ ((int)((unsigned int)((int)((unsigned int)v1006 >> 2)) >> 1))) | (-(v1008 ^ ((int)((unsigned int)((int)((unsigned int)v1006 >> 2)) >> 1))))) >> 31)) | (~(((v1009 ^ ((int)((unsigned int)((int)((unsigned int)v1006 >> 2)) >> 1))) | (-(v1009 ^ ((int)((unsigned int)((int)((unsigned int)v1006 >> 2)) >> 1))))) >> 31))) == 0);
  int v1105;
  if (v1221) {
    int * v1013 = v1002->cache_age;
    int v1223 = ((((int)((unsigned int)((int)((unsigned int)v1006 >> 2)) >> 1)) & 1) * 2) + ((~(((v1009 ^ ((int)((unsigned int)((int)((unsigned int)v1006 >> 2)) >> 1))) | (-(v1009 ^ ((int)((unsigned int)((int)((unsigned int)v1006 >> 2)) >> 1))))) >> 31)) & 1);
    int v1014 = v1013[v1223];
    int v1015 = v1013[v1217];
    int v1224 = v1015 + ((int)((unsigned int)(v1015 - v1014) >> 31));
    v1013[v1217] = v1224;
    int * v1017 = v1002->cache_age;
    int v1018 = v1017[v1218];
    int v1226 = v1018 + ((int)((unsigned int)(v1018 - v1014) >> 31));
    v1017[v1218] = v1226;
    int * v1020 = v1002->cache_age;
    v1020[v1223] = 0;
    v1105 = v1223;
  } else {
    int * v1023 = v1002->cache_age;
    int v1230 = (((int)((unsigned int)((int)((unsigned int)v1006 >> 2)) >> 1)) & 1) * 2;
    int v1024 = v1023[v1230];
    int * v1025 = v1002->cache_tags;
    int v1026 = v1025[v1230];
    int v1027 = v1023[v1218];
    int v1028 = v1025[v1218];
    bool v1232 = !(((~(((v1010 ^ ((int)((unsigned int)((int)((unsigned int)v1006 >> 2)) >> 1))) | (-(v1010 ^ ((int)((unsigned int)((int)((unsigned int)v1006 >> 2)) >> 1))))) >> 31)) | (~(((v1011 ^ ((int)((unsigned int)((int)((unsigned int)v1006 >> 2)) >> 1))) | (-(v1011 ^ ((int)((unsigned int)((int)((unsigned int)v1006 >> 2)) >> 1))))) >> 31))) == 0);
    int v1082;
    if (v1232) {
      int * v1029 = v1002->cache_age;
      int v1234 = (4 + ((((int)((unsigned int)((int)((unsigned int)v1006 >> 2)) >> 1)) & 3) * 2)) + ((~(((v1011 ^ ((int)((unsigned int)((int)((unsigned int)v1006 >> 2)) >> 1))) | (-(v1011 ^ ((int)((unsigned int)((int)((unsigned int)v1006 >> 2)) >> 1))))) >> 31)) & 1);
      int v1030 = v1029[v1234];
      int v1031 = v1029[v1219];
      int v1235 = v1031 + ((int)((unsigned int)(v1031 - v1030) >> 31));
      v1029[v1219] = v1235;
      int * v1033 = v1002->cache_age;
      int v1034 = v1033[v1220];
      int v1237 = v1034 + ((int)((unsigned int)(v1034 - v1030) >> 31));
      v1033[v1220] = v1237;
      int * v1036 = v1002->cache_age;
      v1036[v1234] = 0;
      v1082 = v1234;
    } else {
      int * v1039 = v1002->cache_age;
      int v1241 = 4 + ((((int)((unsigned int)((int)((unsigned int)v1006 >> 2)) >> 1)) & 3) * 2);
      int v1040 = v1039[v1241];
      int * v1041 = v1002->cache_tags;
      int v1042 = v1041[v1241];
      int v1043 = v1039[v1220];
      int v1044 = v1041[v1220];
      int * v1045 = v1002->cache_dirty;
      int v1244 = (4 + ((((int)((unsigned int)((int)((unsigned int)v1006 >> 2)) >> 1)) & 3) * 2)) + ((((v1040 + ((~(((v1042 ^ -1) | (-(v1042 ^ -1))) >> 31)) & 2)) - (v1043 + ((~(((v1044 ^ -1) | (-(v1044 ^ -1))) >> 31)) & 2))) >> 31) & 1);
      int v1046 = v1045[v1244];
      bool v1245 = !(v1046 == 0);
      if (v1245) {
        int * v1047 = v1002->cache_tags;
        int v1048 = v1047[v1244];
        int * v1049 = v1002->cache_vals;
        int v1248 = ((4 + ((((int)((unsigned int)((int)((unsigned int)v1006 >> 2)) >> 1)) & 3) * 2)) + ((((v1040 + ((~(((v1042 ^ -1) | (-(v1042 ^ -1))) >> 31)) & 2)) - (v1043 + ((~(((v1044 ^ -1) | (-(v1044 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
        int v1050 = v1049[v1248];
        int v1249 = (((4 + ((((int)((unsigned int)((int)((unsigned int)v1006 >> 2)) >> 1)) & 3) * 2)) + ((((v1040 + ((~(((v1042 ^ -1) | (-(v1042 ^ -1))) >> 31)) & 2)) - (v1043 + ((~(((v1044 ^ -1) | (-(v1044 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
        int v1051 = v1049[v1249];
        int * v1052 = v1002->mem;
        int v1251 = v1048 * 2;
        v1052[v1251] = v1050;
        int * v1054 = v1002->mem;
        int v1254 = (v1048 * 2) + 1;
        v1054[v1254] = v1051;
        ;
      } else {
        ;
      }
      int * v1059 = v1002->mem;
      int v1259 = ((int)((unsigned int)((int)((unsigned int)v1006 >> 2)) >> 1)) * 2;
      int v1060 = v1059[v1259];
      int v1260 = (((int)((unsigned int)((int)((unsigned int)v1006 >> 2)) >> 1)) * 2) + 1;
      int v1061 = v1059[v1260];
      int * v1062 = v1002->cache_vals;
      int v1262 = ((4 + ((((int)((unsigned int)((int)((unsigned int)v1006 >> 2)) >> 1)) & 3) * 2)) + ((((v1040 + ((~(((v1042 ^ -1) | (-(v1042 ^ -1))) >> 31)) & 2)) - (v1043 + ((~(((v1044 ^ -1) | (-(v1044 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
      v1062[v1262] = v1060;
      int * v1064 = v1002->cache_vals;
      int v1265 = (((4 + ((((int)((unsigned int)((int)((unsigned int)v1006 >> 2)) >> 1)) & 3) * 2)) + ((((v1040 + ((~(((v1042 ^ -1) | (-(v1042 ^ -1))) >> 31)) & 2)) - (v1043 + ((~(((v1044 ^ -1) | (-(v1044 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
      v1064[v1265] = v1061;
      int * v1066 = v1002->cache_tags;
      int v1268 = (int)((unsigned int)((int)((unsigned int)v1006 >> 2)) >> 1);
      v1066[v1244] = v1268;
      int * v1068 = v1002->cache_dirty;
      v1068[v1244] = 0;
      int * v1070 = v1002->cache_age;
      v1070[v1244] = 1;
      int * v1072 = v1002->cache_age;
      int v1073 = v1072[v1244];
      int v1074 = v1072[v1219];
      int v1274 = v1074 + ((int)((unsigned int)(v1074 - v1073) >> 31));
      v1072[v1219] = v1274;
      int * v1076 = v1002->cache_age;
      int v1077 = v1076[v1220];
      int v1276 = v1077 + ((int)((unsigned int)(v1077 - v1073) >> 31));
      v1076[v1220] = v1276;
      int * v1079 = v1002->cache_age;
      v1079[v1244] = 0;
      v1082 = v1244;
    }
    int * v1083 = v1002->cache_vals;
    int v1279 = v1082 * 2;
    int v1084 = v1083[v1279];
    int v1280 = (v1082 * 2) + 1;
    int v1085 = v1083[v1280];
    int v1281 = (((((int)((unsigned int)((int)((unsigned int)v1006 >> 2)) >> 1)) & 1) * 2) + ((((v1024 + ((~(((v1026 ^ -1) | (-(v1026 ^ -1))) >> 31)) & 2)) - (v1027 + ((~(((v1028 ^ -1) | (-(v1028 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
    v1083[v1281] = v1084;
    int * v1087 = v1002->cache_vals;
    int v1284 = ((((((int)((unsigned int)((int)((unsigned int)v1006 >> 2)) >> 1)) & 1) * 2) + ((((v1024 + ((~(((v1026 ^ -1) | (-(v1026 ^ -1))) >> 31)) & 2)) - (v1027 + ((~(((v1028 ^ -1) | (-(v1028 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
    v1087[v1284] = v1085;
    int * v1089 = v1002->cache_tags;
    int v1287 = ((((int)((unsigned int)((int)((unsigned int)v1006 >> 2)) >> 1)) & 1) * 2) + ((((v1024 + ((~(((v1026 ^ -1) | (-(v1026 ^ -1))) >> 31)) & 2)) - (v1027 + ((~(((v1028 ^ -1) | (-(v1028 ^ -1))) >> 31)) & 2))) >> 31) & 1);
    int v1288 = (int)((unsigned int)((int)((unsigned int)v1006 >> 2)) >> 1);
    v1089[v1287] = v1288;
    int * v1091 = v1002->cache_dirty;
    v1091[v1287] = 0;
    int * v1093 = v1002->cache_age;
    v1093[v1287] = 1;
    int * v1095 = v1002->cache_age;
    int v1096 = v1095[v1287];
    int v1097 = v1095[v1217];
    int v1294 = v1097 + ((int)((unsigned int)(v1097 - v1096) >> 31));
    v1095[v1217] = v1294;
    int * v1099 = v1002->cache_age;
    int v1100 = v1099[v1218];
    int v1296 = v1100 + ((int)((unsigned int)(v1100 - v1096) >> 31));
    v1099[v1218] = v1296;
    int * v1102 = v1002->cache_age;
    v1102[v1287] = 0;
    v1105 = v1287;
  }
  int v1299 = (v1105 * 2) + (((int)((unsigned int)v1006 >> 2)) & 1);
  int v1106 = v1012[v1299];
  int * v1107 = v1002->reg_ready;
  int v1301 = ((v1004 + ((v891 - v1004) & (~((v891 - v1004) >> 31)))) + 1) + ((100 ^ (((~(((v1010 ^ ((int)((unsigned int)((int)((unsigned int)v1006 >> 2)) >> 1))) | (-(v1010 ^ ((int)((unsigned int)((int)((unsigned int)v1006 >> 2)) >> 1))))) >> 31)) | (~(((v1011 ^ ((int)((unsigned int)((int)((unsigned int)v1006 >> 2)) >> 1))) | (-(v1011 ^ ((int)((unsigned int)((int)((unsigned int)v1006 >> 2)) >> 1))))) >> 31))) & 104)) ^ (((~(((v1008 ^ ((int)((unsigned int)((int)((unsigned int)v1006 >> 2)) >> 1))) | (-(v1008 ^ ((int)((unsigned int)((int)((unsigned int)v1006 >> 2)) >> 1))))) >> 31)) | (~(((v1009 ^ ((int)((unsigned int)((int)((unsigned int)v1006 >> 2)) >> 1))) | (-(v1009 ^ ((int)((unsigned int)((int)((unsigned int)v1006 >> 2)) >> 1))))) >> 31))) & (1 ^ (100 ^ (((~(((v1010 ^ ((int)((unsigned int)((int)((unsigned int)v1006 >> 2)) >> 1))) | (-(v1010 ^ ((int)((unsigned int)((int)((unsigned int)v1006 >> 2)) >> 1))))) >> 31)) | (~(((v1011 ^ ((int)((unsigned int)((int)((unsigned int)v1006 >> 2)) >> 1))) | (-(v1011 ^ ((int)((unsigned int)((int)((unsigned int)v1006 >> 2)) >> 1))))) >> 31))) & 104)))));
  v1107[9] = v1301;
  int * v1109 = v1002->regs;
  v1109[9] = v1106;
  struct StateT2 * v1111 = slot_10(v880);
  return v1111;
}

struct StateT2 * slot_11(struct StateT2 * v1365) {
  struct StateT * v1366 = v1365->a;
  int v1367 = v1366->timer;
  struct StateT * v1368 = v1365->b;
  int v1369 = v1368->timer;
  bool v1402 = v1367 == v1369;
  squared_assert(v1402);
  squared_assume(v1402);
  struct StateT * v1372 = v1365->a;
  int v1373 = v1372->timer;
  int v1404 = v1373 + 1;
  v1372->timer = v1404;
  struct StateT * v1375 = v1365->b;
  int v1376 = v1375->timer;
  int v1406 = v1376 + 1;
  v1375->timer = v1406;
  struct StateT * v1378 = v1365->a;
  int * v1379 = v1378->reg_ready;
  int v1380 = v1379[5];
  int * v1381 = v1378->regs;
  int v1382 = v1381[5];
  int v1383 = v1379[16];
  int v1384 = v1381[16];
  int v1412 = (v1383 + (((v1380 + ((v1373 - v1380) & (~((v1373 - v1380) >> 31)))) - v1383) & (~(((v1380 + ((v1373 - v1380) & (~((v1373 - v1380) >> 31)))) - v1383) >> 31)))) + 1;
  v1379[5] = v1412;
  int * v1386 = v1378->regs;
  int v1414 = v1382 | v1384;
  v1386[5] = v1414;
  struct StateT * v1388 = v1365->b;
  int * v1389 = v1388->reg_ready;
  int v1390 = v1389[5];
  int * v1391 = v1388->regs;
  int v1392 = v1391[5];
  int v1393 = v1389[16];
  int v1394 = v1391[16];
  int v1418 = (v1393 + (((v1390 + ((v1376 - v1390) & (~((v1376 - v1390) >> 31)))) - v1393) & (~(((v1390 + ((v1376 - v1390) & (~((v1376 - v1390) >> 31)))) - v1393) >> 31)))) + 1;
  v1389[5] = v1418;
  int * v1396 = v1388->regs;
  int v1420 = v1392 | v1394;
  v1396[5] = v1420;
  struct StateT2 * v1398 = slot_12(v1365);
  return v1398;
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
  //@ assert untainted_timer: !\tainted(p_->a->timer==p_->b->timer);
  koika_assert(p_->a->timer==p_->b->timer, "timing leak");
  return 0;
}