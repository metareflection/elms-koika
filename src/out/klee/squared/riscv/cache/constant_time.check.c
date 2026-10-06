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

struct StateT2 * slot_12(struct StateT2 * v1291);
struct StateT2 * slot_14(struct StateT2 * v231);
struct StateT2 * slot_6(struct StateT2 * v284);
struct StateT2 * slot_5(struct StateT2 * v182);
struct StateT2 * slot_2(struct StateT2 * v74);
struct StateT2 * slot_7(struct StateT2 * v327);
struct StateT2 * slot_3(struct StateT2 * v110);
struct StateT2 * snippet(struct StateT2 * v0);
struct StateT2 * slot_10(struct StateT2 * v1206);
struct StateT2 * slot_1(struct StateT2 * v38);
struct StateT2 * slot_8(struct StateT2 * v745);
struct StateT2 * slot_4(struct StateT2 * v146);
struct StateT2 * slot_13(struct StateT2 * v1330);
struct StateT2 * slot_9(struct StateT2 * v788);
struct StateT2 * slot_11(struct StateT2 * v1249);
struct StateT2 * slot_0(struct StateT2 * v2);
struct StateT2 * slot_12(struct StateT2 * v1291) {
  struct StateT * v1292 = v1291->a;
  int v1293 = v1292->timer;
  struct StateT * v1294 = v1291->b;
  int v1295 = v1294->timer;
  bool v1316 = v1293 == v1295;
  squared_assert(v1316);
  squared_assume(v1316);
  struct StateT * v1298 = v1291->a;
  int v1299 = v1298->timer;
  int v1318 = v1299 + 1;
  v1298->timer = v1318;
  struct StateT * v1301 = v1291->b;
  int v1302 = v1301->timer;
  int v1320 = v1302 + 1;
  v1301->timer = v1320;
  struct StateT * v1304 = v1291->a;
  int * v1305 = v1304->regs;
  int v1306 = v1305[14];
  int v1324 = v1306 + 4;
  v1305[14] = v1324;
  struct StateT * v1308 = v1291->b;
  int * v1309 = v1308->regs;
  int v1310 = v1309[14];
  int v1327 = v1310 + 4;
  v1309[14] = v1327;
  struct StateT2 * v1312 = slot_13(v1291);
  return v1312;
}

struct StateT2 * slot_14(struct StateT2 * v231) {
  struct StateT * v232 = v231->a;
  int v233 = v232->timer;
  struct StateT * v234 = v231->b;
  int v235 = v234->timer;
  bool v263 = v233 == v235;
  squared_assert(v263);
  squared_assume(v263);
  struct StateT * v238 = v231->a;
  int v239 = v238->timer;
  int v265 = v239 + 1;
  v238->timer = v265;
  struct StateT * v241 = v231->b;
  int v242 = v241->timer;
  int v267 = v242 + 1;
  v241->timer = v267;
  struct StateT * v244 = v231->a;
  int * v245 = v244->regs;
  int v246 = v245[5];
  bool v271 = (v246 ^ -2147483648) < -2147483647;
  int v249;
  if (v271) {
    v249 = 1;
  } else {
    v249 = 0;
  }
  int * v250 = v244->regs;
  v250[11] = v249;
  struct StateT * v252 = v231->b;
  int * v253 = v252->regs;
  int v254 = v253[5];
  bool v279 = (v254 ^ -2147483648) < -2147483647;
  int v257;
  if (v279) {
    v257 = 1;
  } else {
    v257 = 0;
  }
  int * v258 = v252->regs;
  v258[11] = v257;
  return v231;
}

struct StateT2 * slot_6(struct StateT2 * v284) {
  struct StateT * v285 = v284->a;
  int v286 = v285->timer;
  struct StateT * v287 = v284->b;
  int v288 = v287->timer;
  bool v311 = v286 == v288;
  squared_assert(v311);
  squared_assume(v311);
  struct StateT * v291 = v284->a;
  int v292 = v291->timer;
  int v313 = v292 + 1;
  v291->timer = v313;
  struct StateT * v294 = v284->b;
  int v295 = v294->timer;
  int v315 = v295 + 1;
  v294->timer = v315;
  struct StateT * v297 = v284->a;
  int * v298 = v297->regs;
  int v299 = v298[12];
  int v300 = v298[14];
  int v321 = v299 + v300;
  v298[6] = v321;
  struct StateT * v302 = v284->b;
  int * v303 = v302->regs;
  int v304 = v303[12];
  int v305 = v303[14];
  int v324 = v304 + v305;
  v303[6] = v324;
  struct StateT2 * v307 = slot_7(v284);
  return v307;
}

struct StateT2 * slot_5(struct StateT2 * v182) {
  struct StateT * v183 = v182->a;
  int v184 = v183->timer;
  struct StateT * v185 = v182->b;
  int v186 = v185->timer;
  bool v213 = v184 == v186;
  squared_assert(v213);
  squared_assume(v213);
  struct StateT * v189 = v182->a;
  int v190 = v189->timer;
  int v215 = v190 + 1;
  v189->timer = v215;
  struct StateT * v192 = v182->b;
  int v193 = v192->timer;
  int v217 = v193 + 1;
  v192->timer = v217;
  struct StateT * v195 = v182->a;
  int * v196 = v195->regs;
  int v197 = v196[14];
  int v198 = v196[15];
  struct StateT * v199 = v182->b;
  int * v200 = v199->regs;
  int v201 = v200[14];
  int v202 = v200[15];
  bool v224 = (v197 >= v198) == (v201 >= v202);
  squared_diverged(v224);
  squared_assume(v224);
  bool v225 = v197 >= v198;
  struct StateT2 * v209;
  if (v225) {
    struct StateT2 * v205 = slot_14(v182);
    v209 = v205;
  } else {
    struct StateT2 * v207 = slot_6(v182);
    v209 = v207;
  }
  return v209;
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

struct StateT2 * slot_7(struct StateT2 * v327) {
  struct StateT * v328 = v327->a;
  int v329 = v328->timer;
  struct StateT * v330 = v327->b;
  int v331 = v330->timer;
  bool v558 = v329 == v331;
  squared_assert(v558);
  squared_assume(v558);
  struct StateT * v334 = v327->a;
  int v335 = v334->timer;
  int v560 = v335 + 1;
  v334->timer = v560;
  struct StateT * v337 = v327->b;
  int v338 = v337->timer;
  int v562 = v338 + 1;
  v337->timer = v562;
  struct StateT * v340 = v327->a;
  int * v341 = v340->regs;
  int v342 = v341[6];
  int * v343 = v340->cache_tags;
  int v567 = (((int)((unsigned int)((int)((unsigned int)v342 >> 2)) >> 1)) & 1) * 2;
  int v344 = v343[v567];
  int v568 = ((((int)((unsigned int)((int)((unsigned int)v342 >> 2)) >> 1)) & 1) * 2) + 1;
  int v345 = v343[v568];
  int v569 = 4 + ((((int)((unsigned int)((int)((unsigned int)v342 >> 2)) >> 1)) & 3) * 2);
  int v346 = v343[v569];
  int v570 = (4 + ((((int)((unsigned int)((int)((unsigned int)v342 >> 2)) >> 1)) & 3) * 2)) + 1;
  int v347 = v343[v570];
  int v348 = v340->timer;
  int v571 = v348 + ((100 ^ (((~(((v346 ^ ((int)((unsigned int)((int)((unsigned int)v342 >> 2)) >> 1))) | (-(v346 ^ ((int)((unsigned int)((int)((unsigned int)v342 >> 2)) >> 1))))) >> 31)) | (~(((v347 ^ ((int)((unsigned int)((int)((unsigned int)v342 >> 2)) >> 1))) | (-(v347 ^ ((int)((unsigned int)((int)((unsigned int)v342 >> 2)) >> 1))))) >> 31))) & 104)) ^ (((~(((v344 ^ ((int)((unsigned int)((int)((unsigned int)v342 >> 2)) >> 1))) | (-(v344 ^ ((int)((unsigned int)((int)((unsigned int)v342 >> 2)) >> 1))))) >> 31)) | (~(((v345 ^ ((int)((unsigned int)((int)((unsigned int)v342 >> 2)) >> 1))) | (-(v345 ^ ((int)((unsigned int)((int)((unsigned int)v342 >> 2)) >> 1))))) >> 31))) & (1 ^ (100 ^ (((~(((v346 ^ ((int)((unsigned int)((int)((unsigned int)v342 >> 2)) >> 1))) | (-(v346 ^ ((int)((unsigned int)((int)((unsigned int)v342 >> 2)) >> 1))))) >> 31)) | (~(((v347 ^ ((int)((unsigned int)((int)((unsigned int)v342 >> 2)) >> 1))) | (-(v347 ^ ((int)((unsigned int)((int)((unsigned int)v342 >> 2)) >> 1))))) >> 31))) & 104)))));
  v340->timer = v571;
  int * v350 = v340->cache_vals;
  bool v572 = !(((~(((v344 ^ ((int)((unsigned int)((int)((unsigned int)v342 >> 2)) >> 1))) | (-(v344 ^ ((int)((unsigned int)((int)((unsigned int)v342 >> 2)) >> 1))))) >> 31)) | (~(((v345 ^ ((int)((unsigned int)((int)((unsigned int)v342 >> 2)) >> 1))) | (-(v345 ^ ((int)((unsigned int)((int)((unsigned int)v342 >> 2)) >> 1))))) >> 31))) == 0);
  int v443;
  if (v572) {
    int * v351 = v340->cache_age;
    int v574 = ((((int)((unsigned int)((int)((unsigned int)v342 >> 2)) >> 1)) & 1) * 2) + ((~(((v345 ^ ((int)((unsigned int)((int)((unsigned int)v342 >> 2)) >> 1))) | (-(v345 ^ ((int)((unsigned int)((int)((unsigned int)v342 >> 2)) >> 1))))) >> 31)) & 1);
    int v352 = v351[v574];
    int v353 = v351[v567];
    int v575 = v353 + ((int)((unsigned int)(v353 - v352) >> 31));
    v351[v567] = v575;
    int * v355 = v340->cache_age;
    int v356 = v355[v568];
    int v577 = v356 + ((int)((unsigned int)(v356 - v352) >> 31));
    v355[v568] = v577;
    int * v358 = v340->cache_age;
    v358[v574] = 0;
    v443 = v574;
  } else {
    int * v361 = v340->cache_age;
    int v581 = (((int)((unsigned int)((int)((unsigned int)v342 >> 2)) >> 1)) & 1) * 2;
    int v362 = v361[v581];
    int * v363 = v340->cache_tags;
    int v364 = v363[v581];
    int v365 = v361[v568];
    int v366 = v363[v568];
    bool v583 = !(((~(((v346 ^ ((int)((unsigned int)((int)((unsigned int)v342 >> 2)) >> 1))) | (-(v346 ^ ((int)((unsigned int)((int)((unsigned int)v342 >> 2)) >> 1))))) >> 31)) | (~(((v347 ^ ((int)((unsigned int)((int)((unsigned int)v342 >> 2)) >> 1))) | (-(v347 ^ ((int)((unsigned int)((int)((unsigned int)v342 >> 2)) >> 1))))) >> 31))) == 0);
    int v420;
    if (v583) {
      int * v367 = v340->cache_age;
      int v585 = (4 + ((((int)((unsigned int)((int)((unsigned int)v342 >> 2)) >> 1)) & 3) * 2)) + ((~(((v347 ^ ((int)((unsigned int)((int)((unsigned int)v342 >> 2)) >> 1))) | (-(v347 ^ ((int)((unsigned int)((int)((unsigned int)v342 >> 2)) >> 1))))) >> 31)) & 1);
      int v368 = v367[v585];
      int v369 = v367[v569];
      int v586 = v369 + ((int)((unsigned int)(v369 - v368) >> 31));
      v367[v569] = v586;
      int * v371 = v340->cache_age;
      int v372 = v371[v570];
      int v588 = v372 + ((int)((unsigned int)(v372 - v368) >> 31));
      v371[v570] = v588;
      int * v374 = v340->cache_age;
      v374[v585] = 0;
      v420 = v585;
    } else {
      int * v377 = v340->cache_age;
      int v592 = 4 + ((((int)((unsigned int)((int)((unsigned int)v342 >> 2)) >> 1)) & 3) * 2);
      int v378 = v377[v592];
      int * v379 = v340->cache_tags;
      int v380 = v379[v592];
      int v381 = v377[v570];
      int v382 = v379[v570];
      int * v383 = v340->cache_dirty;
      int v595 = (4 + ((((int)((unsigned int)((int)((unsigned int)v342 >> 2)) >> 1)) & 3) * 2)) + ((((v378 + ((~(((v380 ^ -1) | (-(v380 ^ -1))) >> 31)) & 2)) - (v381 + ((~(((v382 ^ -1) | (-(v382 ^ -1))) >> 31)) & 2))) >> 31) & 1);
      int v384 = v383[v595];
      bool v596 = !(v384 == 0);
      if (v596) {
        int * v385 = v340->cache_tags;
        int v386 = v385[v595];
        int * v387 = v340->cache_vals;
        int v599 = ((4 + ((((int)((unsigned int)((int)((unsigned int)v342 >> 2)) >> 1)) & 3) * 2)) + ((((v378 + ((~(((v380 ^ -1) | (-(v380 ^ -1))) >> 31)) & 2)) - (v381 + ((~(((v382 ^ -1) | (-(v382 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
        int v388 = v387[v599];
        int v600 = (((4 + ((((int)((unsigned int)((int)((unsigned int)v342 >> 2)) >> 1)) & 3) * 2)) + ((((v378 + ((~(((v380 ^ -1) | (-(v380 ^ -1))) >> 31)) & 2)) - (v381 + ((~(((v382 ^ -1) | (-(v382 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
        int v389 = v387[v600];
        int * v390 = v340->mem;
        int v602 = v386 * 2;
        v390[v602] = v388;
        int * v392 = v340->mem;
        int v605 = (v386 * 2) + 1;
        v392[v605] = v389;
        ;
      } else {
        ;
      }
      int * v397 = v340->mem;
      int v610 = ((int)((unsigned int)((int)((unsigned int)v342 >> 2)) >> 1)) * 2;
      int v398 = v397[v610];
      int v611 = (((int)((unsigned int)((int)((unsigned int)v342 >> 2)) >> 1)) * 2) + 1;
      int v399 = v397[v611];
      int * v400 = v340->cache_vals;
      int v613 = ((4 + ((((int)((unsigned int)((int)((unsigned int)v342 >> 2)) >> 1)) & 3) * 2)) + ((((v378 + ((~(((v380 ^ -1) | (-(v380 ^ -1))) >> 31)) & 2)) - (v381 + ((~(((v382 ^ -1) | (-(v382 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
      v400[v613] = v398;
      int * v402 = v340->cache_vals;
      int v616 = (((4 + ((((int)((unsigned int)((int)((unsigned int)v342 >> 2)) >> 1)) & 3) * 2)) + ((((v378 + ((~(((v380 ^ -1) | (-(v380 ^ -1))) >> 31)) & 2)) - (v381 + ((~(((v382 ^ -1) | (-(v382 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
      v402[v616] = v399;
      int * v404 = v340->cache_tags;
      int v619 = (int)((unsigned int)((int)((unsigned int)v342 >> 2)) >> 1);
      v404[v595] = v619;
      int * v406 = v340->cache_dirty;
      v406[v595] = 0;
      int * v408 = v340->cache_age;
      v408[v595] = 1;
      int * v410 = v340->cache_age;
      int v411 = v410[v595];
      int v412 = v410[v569];
      int v625 = v412 + ((int)((unsigned int)(v412 - v411) >> 31));
      v410[v569] = v625;
      int * v414 = v340->cache_age;
      int v415 = v414[v570];
      int v627 = v415 + ((int)((unsigned int)(v415 - v411) >> 31));
      v414[v570] = v627;
      int * v417 = v340->cache_age;
      v417[v595] = 0;
      v420 = v595;
    }
    int * v421 = v340->cache_vals;
    int v630 = v420 * 2;
    int v422 = v421[v630];
    int v631 = (v420 * 2) + 1;
    int v423 = v421[v631];
    int v632 = (((((int)((unsigned int)((int)((unsigned int)v342 >> 2)) >> 1)) & 1) * 2) + ((((v362 + ((~(((v364 ^ -1) | (-(v364 ^ -1))) >> 31)) & 2)) - (v365 + ((~(((v366 ^ -1) | (-(v366 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
    v421[v632] = v422;
    int * v425 = v340->cache_vals;
    int v635 = ((((((int)((unsigned int)((int)((unsigned int)v342 >> 2)) >> 1)) & 1) * 2) + ((((v362 + ((~(((v364 ^ -1) | (-(v364 ^ -1))) >> 31)) & 2)) - (v365 + ((~(((v366 ^ -1) | (-(v366 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
    v425[v635] = v423;
    int * v427 = v340->cache_tags;
    int v638 = ((((int)((unsigned int)((int)((unsigned int)v342 >> 2)) >> 1)) & 1) * 2) + ((((v362 + ((~(((v364 ^ -1) | (-(v364 ^ -1))) >> 31)) & 2)) - (v365 + ((~(((v366 ^ -1) | (-(v366 ^ -1))) >> 31)) & 2))) >> 31) & 1);
    int v639 = (int)((unsigned int)((int)((unsigned int)v342 >> 2)) >> 1);
    v427[v638] = v639;
    int * v429 = v340->cache_dirty;
    v429[v638] = 0;
    int * v431 = v340->cache_age;
    v431[v638] = 1;
    int * v433 = v340->cache_age;
    int v434 = v433[v638];
    int v435 = v433[v567];
    int v645 = v435 + ((int)((unsigned int)(v435 - v434) >> 31));
    v433[v567] = v645;
    int * v437 = v340->cache_age;
    int v438 = v437[v568];
    int v647 = v438 + ((int)((unsigned int)(v438 - v434) >> 31));
    v437[v568] = v647;
    int * v440 = v340->cache_age;
    v440[v638] = 0;
    v443 = v638;
  }
  int v650 = (v443 * 2) + (((int)((unsigned int)v342 >> 2)) & 1);
  int v444 = v350[v650];
  int * v445 = v340->regs;
  v445[7] = v444;
  struct StateT * v447 = v327->b;
  int * v448 = v447->regs;
  int v449 = v448[6];
  int * v450 = v447->cache_tags;
  int v657 = (((int)((unsigned int)((int)((unsigned int)v449 >> 2)) >> 1)) & 1) * 2;
  int v451 = v450[v657];
  int v658 = ((((int)((unsigned int)((int)((unsigned int)v449 >> 2)) >> 1)) & 1) * 2) + 1;
  int v452 = v450[v658];
  int v659 = 4 + ((((int)((unsigned int)((int)((unsigned int)v449 >> 2)) >> 1)) & 3) * 2);
  int v453 = v450[v659];
  int v660 = (4 + ((((int)((unsigned int)((int)((unsigned int)v449 >> 2)) >> 1)) & 3) * 2)) + 1;
  int v454 = v450[v660];
  int v455 = v447->timer;
  int v661 = v455 + ((100 ^ (((~(((v453 ^ ((int)((unsigned int)((int)((unsigned int)v449 >> 2)) >> 1))) | (-(v453 ^ ((int)((unsigned int)((int)((unsigned int)v449 >> 2)) >> 1))))) >> 31)) | (~(((v454 ^ ((int)((unsigned int)((int)((unsigned int)v449 >> 2)) >> 1))) | (-(v454 ^ ((int)((unsigned int)((int)((unsigned int)v449 >> 2)) >> 1))))) >> 31))) & 104)) ^ (((~(((v451 ^ ((int)((unsigned int)((int)((unsigned int)v449 >> 2)) >> 1))) | (-(v451 ^ ((int)((unsigned int)((int)((unsigned int)v449 >> 2)) >> 1))))) >> 31)) | (~(((v452 ^ ((int)((unsigned int)((int)((unsigned int)v449 >> 2)) >> 1))) | (-(v452 ^ ((int)((unsigned int)((int)((unsigned int)v449 >> 2)) >> 1))))) >> 31))) & (1 ^ (100 ^ (((~(((v453 ^ ((int)((unsigned int)((int)((unsigned int)v449 >> 2)) >> 1))) | (-(v453 ^ ((int)((unsigned int)((int)((unsigned int)v449 >> 2)) >> 1))))) >> 31)) | (~(((v454 ^ ((int)((unsigned int)((int)((unsigned int)v449 >> 2)) >> 1))) | (-(v454 ^ ((int)((unsigned int)((int)((unsigned int)v449 >> 2)) >> 1))))) >> 31))) & 104)))));
  v447->timer = v661;
  int * v457 = v447->cache_vals;
  bool v662 = !(((~(((v451 ^ ((int)((unsigned int)((int)((unsigned int)v449 >> 2)) >> 1))) | (-(v451 ^ ((int)((unsigned int)((int)((unsigned int)v449 >> 2)) >> 1))))) >> 31)) | (~(((v452 ^ ((int)((unsigned int)((int)((unsigned int)v449 >> 2)) >> 1))) | (-(v452 ^ ((int)((unsigned int)((int)((unsigned int)v449 >> 2)) >> 1))))) >> 31))) == 0);
  int v550;
  if (v662) {
    int * v458 = v447->cache_age;
    int v664 = ((((int)((unsigned int)((int)((unsigned int)v449 >> 2)) >> 1)) & 1) * 2) + ((~(((v452 ^ ((int)((unsigned int)((int)((unsigned int)v449 >> 2)) >> 1))) | (-(v452 ^ ((int)((unsigned int)((int)((unsigned int)v449 >> 2)) >> 1))))) >> 31)) & 1);
    int v459 = v458[v664];
    int v460 = v458[v657];
    int v665 = v460 + ((int)((unsigned int)(v460 - v459) >> 31));
    v458[v657] = v665;
    int * v462 = v447->cache_age;
    int v463 = v462[v658];
    int v667 = v463 + ((int)((unsigned int)(v463 - v459) >> 31));
    v462[v658] = v667;
    int * v465 = v447->cache_age;
    v465[v664] = 0;
    v550 = v664;
  } else {
    int * v468 = v447->cache_age;
    int v671 = (((int)((unsigned int)((int)((unsigned int)v449 >> 2)) >> 1)) & 1) * 2;
    int v469 = v468[v671];
    int * v470 = v447->cache_tags;
    int v471 = v470[v671];
    int v472 = v468[v658];
    int v473 = v470[v658];
    bool v673 = !(((~(((v453 ^ ((int)((unsigned int)((int)((unsigned int)v449 >> 2)) >> 1))) | (-(v453 ^ ((int)((unsigned int)((int)((unsigned int)v449 >> 2)) >> 1))))) >> 31)) | (~(((v454 ^ ((int)((unsigned int)((int)((unsigned int)v449 >> 2)) >> 1))) | (-(v454 ^ ((int)((unsigned int)((int)((unsigned int)v449 >> 2)) >> 1))))) >> 31))) == 0);
    int v527;
    if (v673) {
      int * v474 = v447->cache_age;
      int v675 = (4 + ((((int)((unsigned int)((int)((unsigned int)v449 >> 2)) >> 1)) & 3) * 2)) + ((~(((v454 ^ ((int)((unsigned int)((int)((unsigned int)v449 >> 2)) >> 1))) | (-(v454 ^ ((int)((unsigned int)((int)((unsigned int)v449 >> 2)) >> 1))))) >> 31)) & 1);
      int v475 = v474[v675];
      int v476 = v474[v659];
      int v676 = v476 + ((int)((unsigned int)(v476 - v475) >> 31));
      v474[v659] = v676;
      int * v478 = v447->cache_age;
      int v479 = v478[v660];
      int v678 = v479 + ((int)((unsigned int)(v479 - v475) >> 31));
      v478[v660] = v678;
      int * v481 = v447->cache_age;
      v481[v675] = 0;
      v527 = v675;
    } else {
      int * v484 = v447->cache_age;
      int v682 = 4 + ((((int)((unsigned int)((int)((unsigned int)v449 >> 2)) >> 1)) & 3) * 2);
      int v485 = v484[v682];
      int * v486 = v447->cache_tags;
      int v487 = v486[v682];
      int v488 = v484[v660];
      int v489 = v486[v660];
      int * v490 = v447->cache_dirty;
      int v685 = (4 + ((((int)((unsigned int)((int)((unsigned int)v449 >> 2)) >> 1)) & 3) * 2)) + ((((v485 + ((~(((v487 ^ -1) | (-(v487 ^ -1))) >> 31)) & 2)) - (v488 + ((~(((v489 ^ -1) | (-(v489 ^ -1))) >> 31)) & 2))) >> 31) & 1);
      int v491 = v490[v685];
      bool v686 = !(v491 == 0);
      if (v686) {
        int * v492 = v447->cache_tags;
        int v493 = v492[v685];
        int * v494 = v447->cache_vals;
        int v689 = ((4 + ((((int)((unsigned int)((int)((unsigned int)v449 >> 2)) >> 1)) & 3) * 2)) + ((((v485 + ((~(((v487 ^ -1) | (-(v487 ^ -1))) >> 31)) & 2)) - (v488 + ((~(((v489 ^ -1) | (-(v489 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
        int v495 = v494[v689];
        int v690 = (((4 + ((((int)((unsigned int)((int)((unsigned int)v449 >> 2)) >> 1)) & 3) * 2)) + ((((v485 + ((~(((v487 ^ -1) | (-(v487 ^ -1))) >> 31)) & 2)) - (v488 + ((~(((v489 ^ -1) | (-(v489 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
        int v496 = v494[v690];
        int * v497 = v447->mem;
        int v692 = v493 * 2;
        v497[v692] = v495;
        int * v499 = v447->mem;
        int v695 = (v493 * 2) + 1;
        v499[v695] = v496;
        ;
      } else {
        ;
      }
      int * v504 = v447->mem;
      int v700 = ((int)((unsigned int)((int)((unsigned int)v449 >> 2)) >> 1)) * 2;
      int v505 = v504[v700];
      int v701 = (((int)((unsigned int)((int)((unsigned int)v449 >> 2)) >> 1)) * 2) + 1;
      int v506 = v504[v701];
      int * v507 = v447->cache_vals;
      int v703 = ((4 + ((((int)((unsigned int)((int)((unsigned int)v449 >> 2)) >> 1)) & 3) * 2)) + ((((v485 + ((~(((v487 ^ -1) | (-(v487 ^ -1))) >> 31)) & 2)) - (v488 + ((~(((v489 ^ -1) | (-(v489 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
      v507[v703] = v505;
      int * v509 = v447->cache_vals;
      int v706 = (((4 + ((((int)((unsigned int)((int)((unsigned int)v449 >> 2)) >> 1)) & 3) * 2)) + ((((v485 + ((~(((v487 ^ -1) | (-(v487 ^ -1))) >> 31)) & 2)) - (v488 + ((~(((v489 ^ -1) | (-(v489 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
      v509[v706] = v506;
      int * v511 = v447->cache_tags;
      int v709 = (int)((unsigned int)((int)((unsigned int)v449 >> 2)) >> 1);
      v511[v685] = v709;
      int * v513 = v447->cache_dirty;
      v513[v685] = 0;
      int * v515 = v447->cache_age;
      v515[v685] = 1;
      int * v517 = v447->cache_age;
      int v518 = v517[v685];
      int v519 = v517[v659];
      int v715 = v519 + ((int)((unsigned int)(v519 - v518) >> 31));
      v517[v659] = v715;
      int * v521 = v447->cache_age;
      int v522 = v521[v660];
      int v717 = v522 + ((int)((unsigned int)(v522 - v518) >> 31));
      v521[v660] = v717;
      int * v524 = v447->cache_age;
      v524[v685] = 0;
      v527 = v685;
    }
    int * v528 = v447->cache_vals;
    int v720 = v527 * 2;
    int v529 = v528[v720];
    int v721 = (v527 * 2) + 1;
    int v530 = v528[v721];
    int v722 = (((((int)((unsigned int)((int)((unsigned int)v449 >> 2)) >> 1)) & 1) * 2) + ((((v469 + ((~(((v471 ^ -1) | (-(v471 ^ -1))) >> 31)) & 2)) - (v472 + ((~(((v473 ^ -1) | (-(v473 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
    v528[v722] = v529;
    int * v532 = v447->cache_vals;
    int v725 = ((((((int)((unsigned int)((int)((unsigned int)v449 >> 2)) >> 1)) & 1) * 2) + ((((v469 + ((~(((v471 ^ -1) | (-(v471 ^ -1))) >> 31)) & 2)) - (v472 + ((~(((v473 ^ -1) | (-(v473 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
    v532[v725] = v530;
    int * v534 = v447->cache_tags;
    int v728 = ((((int)((unsigned int)((int)((unsigned int)v449 >> 2)) >> 1)) & 1) * 2) + ((((v469 + ((~(((v471 ^ -1) | (-(v471 ^ -1))) >> 31)) & 2)) - (v472 + ((~(((v473 ^ -1) | (-(v473 ^ -1))) >> 31)) & 2))) >> 31) & 1);
    int v729 = (int)((unsigned int)((int)((unsigned int)v449 >> 2)) >> 1);
    v534[v728] = v729;
    int * v536 = v447->cache_dirty;
    v536[v728] = 0;
    int * v538 = v447->cache_age;
    v538[v728] = 1;
    int * v540 = v447->cache_age;
    int v541 = v540[v728];
    int v542 = v540[v657];
    int v735 = v542 + ((int)((unsigned int)(v542 - v541) >> 31));
    v540[v657] = v735;
    int * v544 = v447->cache_age;
    int v545 = v544[v658];
    int v737 = v545 + ((int)((unsigned int)(v545 - v541) >> 31));
    v544[v658] = v737;
    int * v547 = v447->cache_age;
    v547[v728] = 0;
    v550 = v728;
  }
  int v740 = (v550 * 2) + (((int)((unsigned int)v449 >> 2)) & 1);
  int v551 = v457[v740];
  int * v552 = v447->regs;
  v552[7] = v551;
  struct StateT2 * v554 = slot_8(v327);
  return v554;
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

struct StateT2 * slot_10(struct StateT2 * v1206) {
  struct StateT * v1207 = v1206->a;
  int v1208 = v1207->timer;
  struct StateT * v1209 = v1206->b;
  int v1210 = v1209->timer;
  bool v1233 = v1208 == v1210;
  squared_assert(v1233);
  squared_assume(v1233);
  struct StateT * v1213 = v1206->a;
  int v1214 = v1213->timer;
  int v1235 = v1214 + 1;
  v1213->timer = v1235;
  struct StateT * v1216 = v1206->b;
  int v1217 = v1216->timer;
  int v1237 = v1217 + 1;
  v1216->timer = v1237;
  struct StateT * v1219 = v1206->a;
  int * v1220 = v1219->regs;
  int v1221 = v1220[7];
  int v1222 = v1220[9];
  int v1243 = v1221 ^ v1222;
  v1220[16] = v1243;
  struct StateT * v1224 = v1206->b;
  int * v1225 = v1224->regs;
  int v1226 = v1225[7];
  int v1227 = v1225[9];
  int v1246 = v1226 ^ v1227;
  v1225[16] = v1246;
  struct StateT2 * v1229 = slot_11(v1206);
  return v1229;
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

struct StateT2 * slot_8(struct StateT2 * v745) {
  struct StateT * v746 = v745->a;
  int v747 = v746->timer;
  struct StateT * v748 = v745->b;
  int v749 = v748->timer;
  bool v772 = v747 == v749;
  squared_assert(v772);
  squared_assume(v772);
  struct StateT * v752 = v745->a;
  int v753 = v752->timer;
  int v774 = v753 + 1;
  v752->timer = v774;
  struct StateT * v755 = v745->b;
  int v756 = v755->timer;
  int v776 = v756 + 1;
  v755->timer = v776;
  struct StateT * v758 = v745->a;
  int * v759 = v758->regs;
  int v760 = v759[13];
  int v761 = v759[14];
  int v782 = v760 + v761;
  v759[8] = v782;
  struct StateT * v763 = v745->b;
  int * v764 = v763->regs;
  int v765 = v764[13];
  int v766 = v764[14];
  int v785 = v765 + v766;
  v764[8] = v785;
  struct StateT2 * v768 = slot_9(v745);
  return v768;
}

struct StateT2 * slot_4(struct StateT2 * v146) {
  struct StateT * v147 = v146->a;
  int v148 = v147->timer;
  struct StateT * v149 = v146->b;
  int v150 = v149->timer;
  bool v169 = v148 == v150;
  squared_assert(v169);
  squared_assume(v169);
  struct StateT * v153 = v146->a;
  int v154 = v153->timer;
  int v171 = v154 + 1;
  v153->timer = v171;
  struct StateT * v156 = v146->b;
  int v157 = v156->timer;
  int v173 = v157 + 1;
  v156->timer = v173;
  struct StateT * v159 = v146->a;
  int * v160 = v159->regs;
  v160[5] = 0;
  struct StateT * v162 = v146->b;
  int * v163 = v162->regs;
  v163[5] = 0;
  struct StateT2 * v165 = slot_5(v146);
  return v165;
}

struct StateT2 * slot_13(struct StateT2 * v1330) {
  struct StateT * v1331 = v1330->a;
  int v1332 = v1331->timer;
  struct StateT * v1333 = v1330->b;
  int v1334 = v1333->timer;
  bool v1349 = v1332 == v1334;
  squared_assert(v1349);
  squared_assume(v1349);
  struct StateT * v1337 = v1330->a;
  int v1338 = v1337->timer;
  int v1351 = v1338 + 1;
  v1337->timer = v1351;
  struct StateT * v1340 = v1330->b;
  int v1341 = v1340->timer;
  int v1353 = v1341 + 1;
  v1340->timer = v1353;
  struct StateT2 * v1345 = slot_5(v1330);
  return v1345;
}

struct StateT2 * slot_9(struct StateT2 * v788) {
  struct StateT * v789 = v788->a;
  int v790 = v789->timer;
  struct StateT * v791 = v788->b;
  int v792 = v791->timer;
  bool v1019 = v790 == v792;
  squared_assert(v1019);
  squared_assume(v1019);
  struct StateT * v795 = v788->a;
  int v796 = v795->timer;
  int v1021 = v796 + 1;
  v795->timer = v1021;
  struct StateT * v798 = v788->b;
  int v799 = v798->timer;
  int v1023 = v799 + 1;
  v798->timer = v1023;
  struct StateT * v801 = v788->a;
  int * v802 = v801->regs;
  int v803 = v802[8];
  int * v804 = v801->cache_tags;
  int v1028 = (((int)((unsigned int)((int)((unsigned int)v803 >> 2)) >> 1)) & 1) * 2;
  int v805 = v804[v1028];
  int v1029 = ((((int)((unsigned int)((int)((unsigned int)v803 >> 2)) >> 1)) & 1) * 2) + 1;
  int v806 = v804[v1029];
  int v1030 = 4 + ((((int)((unsigned int)((int)((unsigned int)v803 >> 2)) >> 1)) & 3) * 2);
  int v807 = v804[v1030];
  int v1031 = (4 + ((((int)((unsigned int)((int)((unsigned int)v803 >> 2)) >> 1)) & 3) * 2)) + 1;
  int v808 = v804[v1031];
  int v809 = v801->timer;
  int v1032 = v809 + ((100 ^ (((~(((v807 ^ ((int)((unsigned int)((int)((unsigned int)v803 >> 2)) >> 1))) | (-(v807 ^ ((int)((unsigned int)((int)((unsigned int)v803 >> 2)) >> 1))))) >> 31)) | (~(((v808 ^ ((int)((unsigned int)((int)((unsigned int)v803 >> 2)) >> 1))) | (-(v808 ^ ((int)((unsigned int)((int)((unsigned int)v803 >> 2)) >> 1))))) >> 31))) & 104)) ^ (((~(((v805 ^ ((int)((unsigned int)((int)((unsigned int)v803 >> 2)) >> 1))) | (-(v805 ^ ((int)((unsigned int)((int)((unsigned int)v803 >> 2)) >> 1))))) >> 31)) | (~(((v806 ^ ((int)((unsigned int)((int)((unsigned int)v803 >> 2)) >> 1))) | (-(v806 ^ ((int)((unsigned int)((int)((unsigned int)v803 >> 2)) >> 1))))) >> 31))) & (1 ^ (100 ^ (((~(((v807 ^ ((int)((unsigned int)((int)((unsigned int)v803 >> 2)) >> 1))) | (-(v807 ^ ((int)((unsigned int)((int)((unsigned int)v803 >> 2)) >> 1))))) >> 31)) | (~(((v808 ^ ((int)((unsigned int)((int)((unsigned int)v803 >> 2)) >> 1))) | (-(v808 ^ ((int)((unsigned int)((int)((unsigned int)v803 >> 2)) >> 1))))) >> 31))) & 104)))));
  v801->timer = v1032;
  int * v811 = v801->cache_vals;
  bool v1033 = !(((~(((v805 ^ ((int)((unsigned int)((int)((unsigned int)v803 >> 2)) >> 1))) | (-(v805 ^ ((int)((unsigned int)((int)((unsigned int)v803 >> 2)) >> 1))))) >> 31)) | (~(((v806 ^ ((int)((unsigned int)((int)((unsigned int)v803 >> 2)) >> 1))) | (-(v806 ^ ((int)((unsigned int)((int)((unsigned int)v803 >> 2)) >> 1))))) >> 31))) == 0);
  int v904;
  if (v1033) {
    int * v812 = v801->cache_age;
    int v1035 = ((((int)((unsigned int)((int)((unsigned int)v803 >> 2)) >> 1)) & 1) * 2) + ((~(((v806 ^ ((int)((unsigned int)((int)((unsigned int)v803 >> 2)) >> 1))) | (-(v806 ^ ((int)((unsigned int)((int)((unsigned int)v803 >> 2)) >> 1))))) >> 31)) & 1);
    int v813 = v812[v1035];
    int v814 = v812[v1028];
    int v1036 = v814 + ((int)((unsigned int)(v814 - v813) >> 31));
    v812[v1028] = v1036;
    int * v816 = v801->cache_age;
    int v817 = v816[v1029];
    int v1038 = v817 + ((int)((unsigned int)(v817 - v813) >> 31));
    v816[v1029] = v1038;
    int * v819 = v801->cache_age;
    v819[v1035] = 0;
    v904 = v1035;
  } else {
    int * v822 = v801->cache_age;
    int v1042 = (((int)((unsigned int)((int)((unsigned int)v803 >> 2)) >> 1)) & 1) * 2;
    int v823 = v822[v1042];
    int * v824 = v801->cache_tags;
    int v825 = v824[v1042];
    int v826 = v822[v1029];
    int v827 = v824[v1029];
    bool v1044 = !(((~(((v807 ^ ((int)((unsigned int)((int)((unsigned int)v803 >> 2)) >> 1))) | (-(v807 ^ ((int)((unsigned int)((int)((unsigned int)v803 >> 2)) >> 1))))) >> 31)) | (~(((v808 ^ ((int)((unsigned int)((int)((unsigned int)v803 >> 2)) >> 1))) | (-(v808 ^ ((int)((unsigned int)((int)((unsigned int)v803 >> 2)) >> 1))))) >> 31))) == 0);
    int v881;
    if (v1044) {
      int * v828 = v801->cache_age;
      int v1046 = (4 + ((((int)((unsigned int)((int)((unsigned int)v803 >> 2)) >> 1)) & 3) * 2)) + ((~(((v808 ^ ((int)((unsigned int)((int)((unsigned int)v803 >> 2)) >> 1))) | (-(v808 ^ ((int)((unsigned int)((int)((unsigned int)v803 >> 2)) >> 1))))) >> 31)) & 1);
      int v829 = v828[v1046];
      int v830 = v828[v1030];
      int v1047 = v830 + ((int)((unsigned int)(v830 - v829) >> 31));
      v828[v1030] = v1047;
      int * v832 = v801->cache_age;
      int v833 = v832[v1031];
      int v1049 = v833 + ((int)((unsigned int)(v833 - v829) >> 31));
      v832[v1031] = v1049;
      int * v835 = v801->cache_age;
      v835[v1046] = 0;
      v881 = v1046;
    } else {
      int * v838 = v801->cache_age;
      int v1053 = 4 + ((((int)((unsigned int)((int)((unsigned int)v803 >> 2)) >> 1)) & 3) * 2);
      int v839 = v838[v1053];
      int * v840 = v801->cache_tags;
      int v841 = v840[v1053];
      int v842 = v838[v1031];
      int v843 = v840[v1031];
      int * v844 = v801->cache_dirty;
      int v1056 = (4 + ((((int)((unsigned int)((int)((unsigned int)v803 >> 2)) >> 1)) & 3) * 2)) + ((((v839 + ((~(((v841 ^ -1) | (-(v841 ^ -1))) >> 31)) & 2)) - (v842 + ((~(((v843 ^ -1) | (-(v843 ^ -1))) >> 31)) & 2))) >> 31) & 1);
      int v845 = v844[v1056];
      bool v1057 = !(v845 == 0);
      if (v1057) {
        int * v846 = v801->cache_tags;
        int v847 = v846[v1056];
        int * v848 = v801->cache_vals;
        int v1060 = ((4 + ((((int)((unsigned int)((int)((unsigned int)v803 >> 2)) >> 1)) & 3) * 2)) + ((((v839 + ((~(((v841 ^ -1) | (-(v841 ^ -1))) >> 31)) & 2)) - (v842 + ((~(((v843 ^ -1) | (-(v843 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
        int v849 = v848[v1060];
        int v1061 = (((4 + ((((int)((unsigned int)((int)((unsigned int)v803 >> 2)) >> 1)) & 3) * 2)) + ((((v839 + ((~(((v841 ^ -1) | (-(v841 ^ -1))) >> 31)) & 2)) - (v842 + ((~(((v843 ^ -1) | (-(v843 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
        int v850 = v848[v1061];
        int * v851 = v801->mem;
        int v1063 = v847 * 2;
        v851[v1063] = v849;
        int * v853 = v801->mem;
        int v1066 = (v847 * 2) + 1;
        v853[v1066] = v850;
        ;
      } else {
        ;
      }
      int * v858 = v801->mem;
      int v1071 = ((int)((unsigned int)((int)((unsigned int)v803 >> 2)) >> 1)) * 2;
      int v859 = v858[v1071];
      int v1072 = (((int)((unsigned int)((int)((unsigned int)v803 >> 2)) >> 1)) * 2) + 1;
      int v860 = v858[v1072];
      int * v861 = v801->cache_vals;
      int v1074 = ((4 + ((((int)((unsigned int)((int)((unsigned int)v803 >> 2)) >> 1)) & 3) * 2)) + ((((v839 + ((~(((v841 ^ -1) | (-(v841 ^ -1))) >> 31)) & 2)) - (v842 + ((~(((v843 ^ -1) | (-(v843 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
      v861[v1074] = v859;
      int * v863 = v801->cache_vals;
      int v1077 = (((4 + ((((int)((unsigned int)((int)((unsigned int)v803 >> 2)) >> 1)) & 3) * 2)) + ((((v839 + ((~(((v841 ^ -1) | (-(v841 ^ -1))) >> 31)) & 2)) - (v842 + ((~(((v843 ^ -1) | (-(v843 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
      v863[v1077] = v860;
      int * v865 = v801->cache_tags;
      int v1080 = (int)((unsigned int)((int)((unsigned int)v803 >> 2)) >> 1);
      v865[v1056] = v1080;
      int * v867 = v801->cache_dirty;
      v867[v1056] = 0;
      int * v869 = v801->cache_age;
      v869[v1056] = 1;
      int * v871 = v801->cache_age;
      int v872 = v871[v1056];
      int v873 = v871[v1030];
      int v1086 = v873 + ((int)((unsigned int)(v873 - v872) >> 31));
      v871[v1030] = v1086;
      int * v875 = v801->cache_age;
      int v876 = v875[v1031];
      int v1088 = v876 + ((int)((unsigned int)(v876 - v872) >> 31));
      v875[v1031] = v1088;
      int * v878 = v801->cache_age;
      v878[v1056] = 0;
      v881 = v1056;
    }
    int * v882 = v801->cache_vals;
    int v1091 = v881 * 2;
    int v883 = v882[v1091];
    int v1092 = (v881 * 2) + 1;
    int v884 = v882[v1092];
    int v1093 = (((((int)((unsigned int)((int)((unsigned int)v803 >> 2)) >> 1)) & 1) * 2) + ((((v823 + ((~(((v825 ^ -1) | (-(v825 ^ -1))) >> 31)) & 2)) - (v826 + ((~(((v827 ^ -1) | (-(v827 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
    v882[v1093] = v883;
    int * v886 = v801->cache_vals;
    int v1096 = ((((((int)((unsigned int)((int)((unsigned int)v803 >> 2)) >> 1)) & 1) * 2) + ((((v823 + ((~(((v825 ^ -1) | (-(v825 ^ -1))) >> 31)) & 2)) - (v826 + ((~(((v827 ^ -1) | (-(v827 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
    v886[v1096] = v884;
    int * v888 = v801->cache_tags;
    int v1099 = ((((int)((unsigned int)((int)((unsigned int)v803 >> 2)) >> 1)) & 1) * 2) + ((((v823 + ((~(((v825 ^ -1) | (-(v825 ^ -1))) >> 31)) & 2)) - (v826 + ((~(((v827 ^ -1) | (-(v827 ^ -1))) >> 31)) & 2))) >> 31) & 1);
    int v1100 = (int)((unsigned int)((int)((unsigned int)v803 >> 2)) >> 1);
    v888[v1099] = v1100;
    int * v890 = v801->cache_dirty;
    v890[v1099] = 0;
    int * v892 = v801->cache_age;
    v892[v1099] = 1;
    int * v894 = v801->cache_age;
    int v895 = v894[v1099];
    int v896 = v894[v1028];
    int v1106 = v896 + ((int)((unsigned int)(v896 - v895) >> 31));
    v894[v1028] = v1106;
    int * v898 = v801->cache_age;
    int v899 = v898[v1029];
    int v1108 = v899 + ((int)((unsigned int)(v899 - v895) >> 31));
    v898[v1029] = v1108;
    int * v901 = v801->cache_age;
    v901[v1099] = 0;
    v904 = v1099;
  }
  int v1111 = (v904 * 2) + (((int)((unsigned int)v803 >> 2)) & 1);
  int v905 = v811[v1111];
  int * v906 = v801->regs;
  v906[9] = v905;
  struct StateT * v908 = v788->b;
  int * v909 = v908->regs;
  int v910 = v909[8];
  int * v911 = v908->cache_tags;
  int v1118 = (((int)((unsigned int)((int)((unsigned int)v910 >> 2)) >> 1)) & 1) * 2;
  int v912 = v911[v1118];
  int v1119 = ((((int)((unsigned int)((int)((unsigned int)v910 >> 2)) >> 1)) & 1) * 2) + 1;
  int v913 = v911[v1119];
  int v1120 = 4 + ((((int)((unsigned int)((int)((unsigned int)v910 >> 2)) >> 1)) & 3) * 2);
  int v914 = v911[v1120];
  int v1121 = (4 + ((((int)((unsigned int)((int)((unsigned int)v910 >> 2)) >> 1)) & 3) * 2)) + 1;
  int v915 = v911[v1121];
  int v916 = v908->timer;
  int v1122 = v916 + ((100 ^ (((~(((v914 ^ ((int)((unsigned int)((int)((unsigned int)v910 >> 2)) >> 1))) | (-(v914 ^ ((int)((unsigned int)((int)((unsigned int)v910 >> 2)) >> 1))))) >> 31)) | (~(((v915 ^ ((int)((unsigned int)((int)((unsigned int)v910 >> 2)) >> 1))) | (-(v915 ^ ((int)((unsigned int)((int)((unsigned int)v910 >> 2)) >> 1))))) >> 31))) & 104)) ^ (((~(((v912 ^ ((int)((unsigned int)((int)((unsigned int)v910 >> 2)) >> 1))) | (-(v912 ^ ((int)((unsigned int)((int)((unsigned int)v910 >> 2)) >> 1))))) >> 31)) | (~(((v913 ^ ((int)((unsigned int)((int)((unsigned int)v910 >> 2)) >> 1))) | (-(v913 ^ ((int)((unsigned int)((int)((unsigned int)v910 >> 2)) >> 1))))) >> 31))) & (1 ^ (100 ^ (((~(((v914 ^ ((int)((unsigned int)((int)((unsigned int)v910 >> 2)) >> 1))) | (-(v914 ^ ((int)((unsigned int)((int)((unsigned int)v910 >> 2)) >> 1))))) >> 31)) | (~(((v915 ^ ((int)((unsigned int)((int)((unsigned int)v910 >> 2)) >> 1))) | (-(v915 ^ ((int)((unsigned int)((int)((unsigned int)v910 >> 2)) >> 1))))) >> 31))) & 104)))));
  v908->timer = v1122;
  int * v918 = v908->cache_vals;
  bool v1123 = !(((~(((v912 ^ ((int)((unsigned int)((int)((unsigned int)v910 >> 2)) >> 1))) | (-(v912 ^ ((int)((unsigned int)((int)((unsigned int)v910 >> 2)) >> 1))))) >> 31)) | (~(((v913 ^ ((int)((unsigned int)((int)((unsigned int)v910 >> 2)) >> 1))) | (-(v913 ^ ((int)((unsigned int)((int)((unsigned int)v910 >> 2)) >> 1))))) >> 31))) == 0);
  int v1011;
  if (v1123) {
    int * v919 = v908->cache_age;
    int v1125 = ((((int)((unsigned int)((int)((unsigned int)v910 >> 2)) >> 1)) & 1) * 2) + ((~(((v913 ^ ((int)((unsigned int)((int)((unsigned int)v910 >> 2)) >> 1))) | (-(v913 ^ ((int)((unsigned int)((int)((unsigned int)v910 >> 2)) >> 1))))) >> 31)) & 1);
    int v920 = v919[v1125];
    int v921 = v919[v1118];
    int v1126 = v921 + ((int)((unsigned int)(v921 - v920) >> 31));
    v919[v1118] = v1126;
    int * v923 = v908->cache_age;
    int v924 = v923[v1119];
    int v1128 = v924 + ((int)((unsigned int)(v924 - v920) >> 31));
    v923[v1119] = v1128;
    int * v926 = v908->cache_age;
    v926[v1125] = 0;
    v1011 = v1125;
  } else {
    int * v929 = v908->cache_age;
    int v1132 = (((int)((unsigned int)((int)((unsigned int)v910 >> 2)) >> 1)) & 1) * 2;
    int v930 = v929[v1132];
    int * v931 = v908->cache_tags;
    int v932 = v931[v1132];
    int v933 = v929[v1119];
    int v934 = v931[v1119];
    bool v1134 = !(((~(((v914 ^ ((int)((unsigned int)((int)((unsigned int)v910 >> 2)) >> 1))) | (-(v914 ^ ((int)((unsigned int)((int)((unsigned int)v910 >> 2)) >> 1))))) >> 31)) | (~(((v915 ^ ((int)((unsigned int)((int)((unsigned int)v910 >> 2)) >> 1))) | (-(v915 ^ ((int)((unsigned int)((int)((unsigned int)v910 >> 2)) >> 1))))) >> 31))) == 0);
    int v988;
    if (v1134) {
      int * v935 = v908->cache_age;
      int v1136 = (4 + ((((int)((unsigned int)((int)((unsigned int)v910 >> 2)) >> 1)) & 3) * 2)) + ((~(((v915 ^ ((int)((unsigned int)((int)((unsigned int)v910 >> 2)) >> 1))) | (-(v915 ^ ((int)((unsigned int)((int)((unsigned int)v910 >> 2)) >> 1))))) >> 31)) & 1);
      int v936 = v935[v1136];
      int v937 = v935[v1120];
      int v1137 = v937 + ((int)((unsigned int)(v937 - v936) >> 31));
      v935[v1120] = v1137;
      int * v939 = v908->cache_age;
      int v940 = v939[v1121];
      int v1139 = v940 + ((int)((unsigned int)(v940 - v936) >> 31));
      v939[v1121] = v1139;
      int * v942 = v908->cache_age;
      v942[v1136] = 0;
      v988 = v1136;
    } else {
      int * v945 = v908->cache_age;
      int v1143 = 4 + ((((int)((unsigned int)((int)((unsigned int)v910 >> 2)) >> 1)) & 3) * 2);
      int v946 = v945[v1143];
      int * v947 = v908->cache_tags;
      int v948 = v947[v1143];
      int v949 = v945[v1121];
      int v950 = v947[v1121];
      int * v951 = v908->cache_dirty;
      int v1146 = (4 + ((((int)((unsigned int)((int)((unsigned int)v910 >> 2)) >> 1)) & 3) * 2)) + ((((v946 + ((~(((v948 ^ -1) | (-(v948 ^ -1))) >> 31)) & 2)) - (v949 + ((~(((v950 ^ -1) | (-(v950 ^ -1))) >> 31)) & 2))) >> 31) & 1);
      int v952 = v951[v1146];
      bool v1147 = !(v952 == 0);
      if (v1147) {
        int * v953 = v908->cache_tags;
        int v954 = v953[v1146];
        int * v955 = v908->cache_vals;
        int v1150 = ((4 + ((((int)((unsigned int)((int)((unsigned int)v910 >> 2)) >> 1)) & 3) * 2)) + ((((v946 + ((~(((v948 ^ -1) | (-(v948 ^ -1))) >> 31)) & 2)) - (v949 + ((~(((v950 ^ -1) | (-(v950 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
        int v956 = v955[v1150];
        int v1151 = (((4 + ((((int)((unsigned int)((int)((unsigned int)v910 >> 2)) >> 1)) & 3) * 2)) + ((((v946 + ((~(((v948 ^ -1) | (-(v948 ^ -1))) >> 31)) & 2)) - (v949 + ((~(((v950 ^ -1) | (-(v950 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
        int v957 = v955[v1151];
        int * v958 = v908->mem;
        int v1153 = v954 * 2;
        v958[v1153] = v956;
        int * v960 = v908->mem;
        int v1156 = (v954 * 2) + 1;
        v960[v1156] = v957;
        ;
      } else {
        ;
      }
      int * v965 = v908->mem;
      int v1161 = ((int)((unsigned int)((int)((unsigned int)v910 >> 2)) >> 1)) * 2;
      int v966 = v965[v1161];
      int v1162 = (((int)((unsigned int)((int)((unsigned int)v910 >> 2)) >> 1)) * 2) + 1;
      int v967 = v965[v1162];
      int * v968 = v908->cache_vals;
      int v1164 = ((4 + ((((int)((unsigned int)((int)((unsigned int)v910 >> 2)) >> 1)) & 3) * 2)) + ((((v946 + ((~(((v948 ^ -1) | (-(v948 ^ -1))) >> 31)) & 2)) - (v949 + ((~(((v950 ^ -1) | (-(v950 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
      v968[v1164] = v966;
      int * v970 = v908->cache_vals;
      int v1167 = (((4 + ((((int)((unsigned int)((int)((unsigned int)v910 >> 2)) >> 1)) & 3) * 2)) + ((((v946 + ((~(((v948 ^ -1) | (-(v948 ^ -1))) >> 31)) & 2)) - (v949 + ((~(((v950 ^ -1) | (-(v950 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
      v970[v1167] = v967;
      int * v972 = v908->cache_tags;
      int v1170 = (int)((unsigned int)((int)((unsigned int)v910 >> 2)) >> 1);
      v972[v1146] = v1170;
      int * v974 = v908->cache_dirty;
      v974[v1146] = 0;
      int * v976 = v908->cache_age;
      v976[v1146] = 1;
      int * v978 = v908->cache_age;
      int v979 = v978[v1146];
      int v980 = v978[v1120];
      int v1176 = v980 + ((int)((unsigned int)(v980 - v979) >> 31));
      v978[v1120] = v1176;
      int * v982 = v908->cache_age;
      int v983 = v982[v1121];
      int v1178 = v983 + ((int)((unsigned int)(v983 - v979) >> 31));
      v982[v1121] = v1178;
      int * v985 = v908->cache_age;
      v985[v1146] = 0;
      v988 = v1146;
    }
    int * v989 = v908->cache_vals;
    int v1181 = v988 * 2;
    int v990 = v989[v1181];
    int v1182 = (v988 * 2) + 1;
    int v991 = v989[v1182];
    int v1183 = (((((int)((unsigned int)((int)((unsigned int)v910 >> 2)) >> 1)) & 1) * 2) + ((((v930 + ((~(((v932 ^ -1) | (-(v932 ^ -1))) >> 31)) & 2)) - (v933 + ((~(((v934 ^ -1) | (-(v934 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
    v989[v1183] = v990;
    int * v993 = v908->cache_vals;
    int v1186 = ((((((int)((unsigned int)((int)((unsigned int)v910 >> 2)) >> 1)) & 1) * 2) + ((((v930 + ((~(((v932 ^ -1) | (-(v932 ^ -1))) >> 31)) & 2)) - (v933 + ((~(((v934 ^ -1) | (-(v934 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
    v993[v1186] = v991;
    int * v995 = v908->cache_tags;
    int v1189 = ((((int)((unsigned int)((int)((unsigned int)v910 >> 2)) >> 1)) & 1) * 2) + ((((v930 + ((~(((v932 ^ -1) | (-(v932 ^ -1))) >> 31)) & 2)) - (v933 + ((~(((v934 ^ -1) | (-(v934 ^ -1))) >> 31)) & 2))) >> 31) & 1);
    int v1190 = (int)((unsigned int)((int)((unsigned int)v910 >> 2)) >> 1);
    v995[v1189] = v1190;
    int * v997 = v908->cache_dirty;
    v997[v1189] = 0;
    int * v999 = v908->cache_age;
    v999[v1189] = 1;
    int * v1001 = v908->cache_age;
    int v1002 = v1001[v1189];
    int v1003 = v1001[v1118];
    int v1196 = v1003 + ((int)((unsigned int)(v1003 - v1002) >> 31));
    v1001[v1118] = v1196;
    int * v1005 = v908->cache_age;
    int v1006 = v1005[v1119];
    int v1198 = v1006 + ((int)((unsigned int)(v1006 - v1002) >> 31));
    v1005[v1119] = v1198;
    int * v1008 = v908->cache_age;
    v1008[v1189] = 0;
    v1011 = v1189;
  }
  int v1201 = (v1011 * 2) + (((int)((unsigned int)v910 >> 2)) & 1);
  int v1012 = v918[v1201];
  int * v1013 = v908->regs;
  v1013[9] = v1012;
  struct StateT2 * v1015 = slot_10(v788);
  return v1015;
}

struct StateT2 * slot_11(struct StateT2 * v1249) {
  struct StateT * v1250 = v1249->a;
  int v1251 = v1250->timer;
  struct StateT * v1252 = v1249->b;
  int v1253 = v1252->timer;
  bool v1276 = v1251 == v1253;
  squared_assert(v1276);
  squared_assume(v1276);
  struct StateT * v1256 = v1249->a;
  int v1257 = v1256->timer;
  int v1278 = v1257 + 1;
  v1256->timer = v1278;
  struct StateT * v1259 = v1249->b;
  int v1260 = v1259->timer;
  int v1280 = v1260 + 1;
  v1259->timer = v1280;
  struct StateT * v1262 = v1249->a;
  int * v1263 = v1262->regs;
  int v1264 = v1263[5];
  int v1265 = v1263[16];
  int v1285 = v1264 | v1265;
  v1263[5] = v1285;
  struct StateT * v1267 = v1249->b;
  int * v1268 = v1267->regs;
  int v1269 = v1268[5];
  int v1270 = v1268[16];
  int v1288 = v1269 | v1270;
  v1268[5] = v1288;
  struct StateT2 * v1272 = slot_12(v1249);
  return v1272;
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
  //@ assert untainted_timer: !\tainted(p_->a->timer==p_->b->timer);
  koika_assert(p_->a->timer==p_->b->timer, "timing leak");
  return 0;
}