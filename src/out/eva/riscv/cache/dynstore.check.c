// verify: clean (Eva should report untainted_timer: Valid) [unroll 65]
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

struct StateT * slot_6(struct StateT * v281);
struct StateT * slot_5(struct StateT * v77);
struct StateT * slot_2(struct StateT * v28);
struct StateT * slot_7(struct StateT * v596);
struct StateT * slot_3(struct StateT * v41);
struct StateT * snippet(struct StateT * v0);
struct StateT * slot_1(struct StateT * v15);
struct StateT * slot_8(struct StateT * v800);
struct StateT * slot_4(struct StateT * v60);
struct StateT * slot_9(struct StateT * v814);
struct StateT * slot_0(struct StateT * v2);
struct StateT * slot_6(struct StateT * v281) {
  int v282 = v281->timer;
  int v452 = v282 + 1;
  v281->timer = v452;
  int * v284 = v281->regs;
  int v285 = v284[6];
  int v286 = v284[5];
  int * v287 = v281->cache_tags;
  int v457 = (((int)((unsigned int)((int)((unsigned int)v285 >> 2)) >> 1)) & 1) * 2;
  int v288 = v287[v457];
  int v458 = ((((int)((unsigned int)((int)((unsigned int)v285 >> 2)) >> 1)) & 1) * 2) + 1;
  int v289 = v287[v458];
  int v459 = 4 + ((((int)((unsigned int)((int)((unsigned int)v285 >> 2)) >> 1)) & 3) * 2);
  int v290 = v287[v459];
  int v460 = (4 + ((((int)((unsigned int)((int)((unsigned int)v285 >> 2)) >> 1)) & 3) * 2)) + 1;
  int v291 = v287[v460];
  int v292 = v281->timer;
  int v461 = v292 + ((100 ^ (((~(((v290 ^ ((int)((unsigned int)((int)((unsigned int)v285 >> 2)) >> 1))) | (-(v290 ^ ((int)((unsigned int)((int)((unsigned int)v285 >> 2)) >> 1))))) >> 31)) | (~(((v291 ^ ((int)((unsigned int)((int)((unsigned int)v285 >> 2)) >> 1))) | (-(v291 ^ ((int)((unsigned int)((int)((unsigned int)v285 >> 2)) >> 1))))) >> 31))) & 104)) ^ (((~(((v288 ^ ((int)((unsigned int)((int)((unsigned int)v285 >> 2)) >> 1))) | (-(v288 ^ ((int)((unsigned int)((int)((unsigned int)v285 >> 2)) >> 1))))) >> 31)) | (~(((v289 ^ ((int)((unsigned int)((int)((unsigned int)v285 >> 2)) >> 1))) | (-(v289 ^ ((int)((unsigned int)((int)((unsigned int)v285 >> 2)) >> 1))))) >> 31))) & (1 ^ (100 ^ (((~(((v290 ^ ((int)((unsigned int)((int)((unsigned int)v285 >> 2)) >> 1))) | (-(v290 ^ ((int)((unsigned int)((int)((unsigned int)v285 >> 2)) >> 1))))) >> 31)) | (~(((v291 ^ ((int)((unsigned int)((int)((unsigned int)v285 >> 2)) >> 1))) | (-(v291 ^ ((int)((unsigned int)((int)((unsigned int)v285 >> 2)) >> 1))))) >> 31))) & 104)))));
  v281->timer = v461;
  bool v462 = !(((~(((v288 ^ ((int)((unsigned int)((int)((unsigned int)v285 >> 2)) >> 1))) | (-(v288 ^ ((int)((unsigned int)((int)((unsigned int)v285 >> 2)) >> 1))))) >> 31)) | (~(((v289 ^ ((int)((unsigned int)((int)((unsigned int)v285 >> 2)) >> 1))) | (-(v289 ^ ((int)((unsigned int)((int)((unsigned int)v285 >> 2)) >> 1))))) >> 31))) == 0);
  int v386;
  if (v462) {
    int * v294 = v281->cache_age;
    int v464 = ((((int)((unsigned int)((int)((unsigned int)v285 >> 2)) >> 1)) & 1) * 2) + ((~(((v289 ^ ((int)((unsigned int)((int)((unsigned int)v285 >> 2)) >> 1))) | (-(v289 ^ ((int)((unsigned int)((int)((unsigned int)v285 >> 2)) >> 1))))) >> 31)) & 1);
    int v295 = v294[v464];
    int v296 = v294[v457];
    int v465 = v296 + ((int)((unsigned int)(v296 - v295) >> 31));
    v294[v457] = v465;
    int * v298 = v281->cache_age;
    int v299 = v298[v458];
    int v467 = v299 + ((int)((unsigned int)(v299 - v295) >> 31));
    v298[v458] = v467;
    int * v301 = v281->cache_age;
    v301[v464] = 0;
    v386 = v464;
  } else {
    int * v304 = v281->cache_age;
    int v471 = (((int)((unsigned int)((int)((unsigned int)v285 >> 2)) >> 1)) & 1) * 2;
    int v305 = v304[v471];
    int * v306 = v281->cache_tags;
    int v307 = v306[v471];
    int v308 = v304[v458];
    int v309 = v306[v458];
    bool v473 = !(((~(((v290 ^ ((int)((unsigned int)((int)((unsigned int)v285 >> 2)) >> 1))) | (-(v290 ^ ((int)((unsigned int)((int)((unsigned int)v285 >> 2)) >> 1))))) >> 31)) | (~(((v291 ^ ((int)((unsigned int)((int)((unsigned int)v285 >> 2)) >> 1))) | (-(v291 ^ ((int)((unsigned int)((int)((unsigned int)v285 >> 2)) >> 1))))) >> 31))) == 0);
    int v363;
    if (v473) {
      int * v310 = v281->cache_age;
      int v475 = (4 + ((((int)((unsigned int)((int)((unsigned int)v285 >> 2)) >> 1)) & 3) * 2)) + ((~(((v291 ^ ((int)((unsigned int)((int)((unsigned int)v285 >> 2)) >> 1))) | (-(v291 ^ ((int)((unsigned int)((int)((unsigned int)v285 >> 2)) >> 1))))) >> 31)) & 1);
      int v311 = v310[v475];
      int v312 = v310[v459];
      int v476 = v312 + ((int)((unsigned int)(v312 - v311) >> 31));
      v310[v459] = v476;
      int * v314 = v281->cache_age;
      int v315 = v314[v460];
      int v478 = v315 + ((int)((unsigned int)(v315 - v311) >> 31));
      v314[v460] = v478;
      int * v317 = v281->cache_age;
      v317[v475] = 0;
      v363 = v475;
    } else {
      int * v320 = v281->cache_age;
      int v482 = 4 + ((((int)((unsigned int)((int)((unsigned int)v285 >> 2)) >> 1)) & 3) * 2);
      int v321 = v320[v482];
      int * v322 = v281->cache_tags;
      int v323 = v322[v482];
      int v324 = v320[v460];
      int v325 = v322[v460];
      int * v326 = v281->cache_dirty;
      int v485 = (4 + ((((int)((unsigned int)((int)((unsigned int)v285 >> 2)) >> 1)) & 3) * 2)) + ((((v321 + ((~(((v323 ^ -1) | (-(v323 ^ -1))) >> 31)) & 2)) - (v324 + ((~(((v325 ^ -1) | (-(v325 ^ -1))) >> 31)) & 2))) >> 31) & 1);
      int v327 = v326[v485];
      bool v486 = !(v327 == 0);
      if (v486) {
        int * v328 = v281->cache_tags;
        int v329 = v328[v485];
        int * v330 = v281->cache_vals;
        int v489 = ((4 + ((((int)((unsigned int)((int)((unsigned int)v285 >> 2)) >> 1)) & 3) * 2)) + ((((v321 + ((~(((v323 ^ -1) | (-(v323 ^ -1))) >> 31)) & 2)) - (v324 + ((~(((v325 ^ -1) | (-(v325 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
        int v331 = v330[v489];
        int v490 = (((4 + ((((int)((unsigned int)((int)((unsigned int)v285 >> 2)) >> 1)) & 3) * 2)) + ((((v321 + ((~(((v323 ^ -1) | (-(v323 ^ -1))) >> 31)) & 2)) - (v324 + ((~(((v325 ^ -1) | (-(v325 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
        int v332 = v330[v490];
        int * v333 = v281->mem;
        int v492 = v329 * 2;
        v333[v492] = v331;
        int * v335 = v281->mem;
        int v495 = (v329 * 2) + 1;
        v335[v495] = v332;
        ;
      } else {
        ;
      }
      int * v340 = v281->mem;
      int v500 = ((int)((unsigned int)((int)((unsigned int)v285 >> 2)) >> 1)) * 2;
      int v341 = v340[v500];
      int v501 = (((int)((unsigned int)((int)((unsigned int)v285 >> 2)) >> 1)) * 2) + 1;
      int v342 = v340[v501];
      int * v343 = v281->cache_vals;
      int v503 = ((4 + ((((int)((unsigned int)((int)((unsigned int)v285 >> 2)) >> 1)) & 3) * 2)) + ((((v321 + ((~(((v323 ^ -1) | (-(v323 ^ -1))) >> 31)) & 2)) - (v324 + ((~(((v325 ^ -1) | (-(v325 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
      v343[v503] = v341;
      int * v345 = v281->cache_vals;
      int v506 = (((4 + ((((int)((unsigned int)((int)((unsigned int)v285 >> 2)) >> 1)) & 3) * 2)) + ((((v321 + ((~(((v323 ^ -1) | (-(v323 ^ -1))) >> 31)) & 2)) - (v324 + ((~(((v325 ^ -1) | (-(v325 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
      v345[v506] = v342;
      int * v347 = v281->cache_tags;
      int v509 = (int)((unsigned int)((int)((unsigned int)v285 >> 2)) >> 1);
      v347[v485] = v509;
      int * v349 = v281->cache_dirty;
      v349[v485] = 0;
      int * v351 = v281->cache_age;
      v351[v485] = 1;
      int * v353 = v281->cache_age;
      int v354 = v353[v485];
      int v355 = v353[v459];
      int v515 = v355 + ((int)((unsigned int)(v355 - v354) >> 31));
      v353[v459] = v515;
      int * v357 = v281->cache_age;
      int v358 = v357[v460];
      int v517 = v358 + ((int)((unsigned int)(v358 - v354) >> 31));
      v357[v460] = v517;
      int * v360 = v281->cache_age;
      v360[v485] = 0;
      v363 = v485;
    }
    int * v364 = v281->cache_vals;
    int v520 = v363 * 2;
    int v365 = v364[v520];
    int v521 = (v363 * 2) + 1;
    int v366 = v364[v521];
    int v522 = (((((int)((unsigned int)((int)((unsigned int)v285 >> 2)) >> 1)) & 1) * 2) + ((((v305 + ((~(((v307 ^ -1) | (-(v307 ^ -1))) >> 31)) & 2)) - (v308 + ((~(((v309 ^ -1) | (-(v309 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
    v364[v522] = v365;
    int * v368 = v281->cache_vals;
    int v525 = ((((((int)((unsigned int)((int)((unsigned int)v285 >> 2)) >> 1)) & 1) * 2) + ((((v305 + ((~(((v307 ^ -1) | (-(v307 ^ -1))) >> 31)) & 2)) - (v308 + ((~(((v309 ^ -1) | (-(v309 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
    v368[v525] = v366;
    int * v370 = v281->cache_tags;
    int v528 = ((((int)((unsigned int)((int)((unsigned int)v285 >> 2)) >> 1)) & 1) * 2) + ((((v305 + ((~(((v307 ^ -1) | (-(v307 ^ -1))) >> 31)) & 2)) - (v308 + ((~(((v309 ^ -1) | (-(v309 ^ -1))) >> 31)) & 2))) >> 31) & 1);
    int v529 = (int)((unsigned int)((int)((unsigned int)v285 >> 2)) >> 1);
    v370[v528] = v529;
    int * v372 = v281->cache_dirty;
    v372[v528] = 0;
    int * v374 = v281->cache_age;
    v374[v528] = 1;
    int * v376 = v281->cache_age;
    int v377 = v376[v528];
    int v378 = v376[v457];
    int v535 = v378 + ((int)((unsigned int)(v378 - v377) >> 31));
    v376[v457] = v535;
    int * v380 = v281->cache_age;
    int v381 = v380[v458];
    int v537 = v381 + ((int)((unsigned int)(v381 - v377) >> 31));
    v380[v458] = v537;
    int * v383 = v281->cache_age;
    v383[v528] = 0;
    v386 = v528;
  }
  int * v387 = v281->cache_vals;
  int v540 = (v386 * 2) + (((int)((unsigned int)v285 >> 2)) & 1);
  v387[v540] = v286;
  int * v389 = v281->cache_tags;
  int v390 = v389[v459];
  int v391 = v389[v460];
  bool v543 = !(((~(((v390 ^ ((int)((unsigned int)((int)((unsigned int)v285 >> 2)) >> 1))) | (-(v390 ^ ((int)((unsigned int)((int)((unsigned int)v285 >> 2)) >> 1))))) >> 31)) | (~(((v391 ^ ((int)((unsigned int)((int)((unsigned int)v285 >> 2)) >> 1))) | (-(v391 ^ ((int)((unsigned int)((int)((unsigned int)v285 >> 2)) >> 1))))) >> 31))) == 0);
  int v445;
  if (v543) {
    int * v392 = v281->cache_age;
    int v545 = (4 + ((((int)((unsigned int)((int)((unsigned int)v285 >> 2)) >> 1)) & 3) * 2)) + ((~(((v391 ^ ((int)((unsigned int)((int)((unsigned int)v285 >> 2)) >> 1))) | (-(v391 ^ ((int)((unsigned int)((int)((unsigned int)v285 >> 2)) >> 1))))) >> 31)) & 1);
    int v393 = v392[v545];
    int v394 = v392[v459];
    int v546 = v394 + ((int)((unsigned int)(v394 - v393) >> 31));
    v392[v459] = v546;
    int * v396 = v281->cache_age;
    int v397 = v396[v460];
    int v548 = v397 + ((int)((unsigned int)(v397 - v393) >> 31));
    v396[v460] = v548;
    int * v399 = v281->cache_age;
    v399[v545] = 0;
    v445 = v545;
  } else {
    int * v402 = v281->cache_age;
    int v552 = 4 + ((((int)((unsigned int)((int)((unsigned int)v285 >> 2)) >> 1)) & 3) * 2);
    int v403 = v402[v552];
    int * v404 = v281->cache_tags;
    int v405 = v404[v552];
    int v406 = v402[v460];
    int v407 = v404[v460];
    int * v408 = v281->cache_dirty;
    int v555 = (4 + ((((int)((unsigned int)((int)((unsigned int)v285 >> 2)) >> 1)) & 3) * 2)) + ((((v403 + ((~(((v405 ^ -1) | (-(v405 ^ -1))) >> 31)) & 2)) - (v406 + ((~(((v407 ^ -1) | (-(v407 ^ -1))) >> 31)) & 2))) >> 31) & 1);
    int v409 = v408[v555];
    bool v556 = !(v409 == 0);
    if (v556) {
      int * v410 = v281->cache_tags;
      int v411 = v410[v555];
      int * v412 = v281->cache_vals;
      int v559 = ((4 + ((((int)((unsigned int)((int)((unsigned int)v285 >> 2)) >> 1)) & 3) * 2)) + ((((v403 + ((~(((v405 ^ -1) | (-(v405 ^ -1))) >> 31)) & 2)) - (v406 + ((~(((v407 ^ -1) | (-(v407 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
      int v413 = v412[v559];
      int v560 = (((4 + ((((int)((unsigned int)((int)((unsigned int)v285 >> 2)) >> 1)) & 3) * 2)) + ((((v403 + ((~(((v405 ^ -1) | (-(v405 ^ -1))) >> 31)) & 2)) - (v406 + ((~(((v407 ^ -1) | (-(v407 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
      int v414 = v412[v560];
      int * v415 = v281->mem;
      int v562 = v411 * 2;
      v415[v562] = v413;
      int * v417 = v281->mem;
      int v565 = (v411 * 2) + 1;
      v417[v565] = v414;
      ;
    } else {
      ;
    }
    int * v422 = v281->mem;
    int v570 = ((int)((unsigned int)((int)((unsigned int)v285 >> 2)) >> 1)) * 2;
    int v423 = v422[v570];
    int v571 = (((int)((unsigned int)((int)((unsigned int)v285 >> 2)) >> 1)) * 2) + 1;
    int v424 = v422[v571];
    int * v425 = v281->cache_vals;
    int v573 = ((4 + ((((int)((unsigned int)((int)((unsigned int)v285 >> 2)) >> 1)) & 3) * 2)) + ((((v403 + ((~(((v405 ^ -1) | (-(v405 ^ -1))) >> 31)) & 2)) - (v406 + ((~(((v407 ^ -1) | (-(v407 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
    v425[v573] = v423;
    int * v427 = v281->cache_vals;
    int v576 = (((4 + ((((int)((unsigned int)((int)((unsigned int)v285 >> 2)) >> 1)) & 3) * 2)) + ((((v403 + ((~(((v405 ^ -1) | (-(v405 ^ -1))) >> 31)) & 2)) - (v406 + ((~(((v407 ^ -1) | (-(v407 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
    v427[v576] = v424;
    int * v429 = v281->cache_tags;
    int v579 = (int)((unsigned int)((int)((unsigned int)v285 >> 2)) >> 1);
    v429[v555] = v579;
    int * v431 = v281->cache_dirty;
    v431[v555] = 0;
    int * v433 = v281->cache_age;
    v433[v555] = 1;
    int * v435 = v281->cache_age;
    int v436 = v435[v555];
    int v437 = v435[v459];
    int v585 = v437 + ((int)((unsigned int)(v437 - v436) >> 31));
    v435[v459] = v585;
    int * v439 = v281->cache_age;
    int v440 = v439[v460];
    int v587 = v440 + ((int)((unsigned int)(v440 - v436) >> 31));
    v439[v460] = v587;
    int * v442 = v281->cache_age;
    v442[v555] = 0;
    v445 = v555;
  }
  int * v446 = v281->cache_vals;
  int v590 = (v445 * 2) + (((int)((unsigned int)v285 >> 2)) & 1);
  v446[v590] = v286;
  int * v448 = v281->cache_dirty;
  v448[v445] = 1;
  struct StateT * v450 = slot_7(v281);
  return v450;
}

struct StateT * slot_5(struct StateT * v77) {
  int v78 = v77->timer;
  int v188 = v78 + 1;
  v77->timer = v188;
  int * v80 = v77->regs;
  int v81 = v80[8];
  int * v82 = v77->cache_tags;
  int v192 = (((int)((unsigned int)((int)((unsigned int)v81 >> 2)) >> 1)) & 1) * 2;
  int v83 = v82[v192];
  int v193 = ((((int)((unsigned int)((int)((unsigned int)v81 >> 2)) >> 1)) & 1) * 2) + 1;
  int v84 = v82[v193];
  int v194 = 4 + ((((int)((unsigned int)((int)((unsigned int)v81 >> 2)) >> 1)) & 3) * 2);
  int v85 = v82[v194];
  int v195 = (4 + ((((int)((unsigned int)((int)((unsigned int)v81 >> 2)) >> 1)) & 3) * 2)) + 1;
  int v86 = v82[v195];
  int v87 = v77->timer;
  int v196 = v87 + ((100 ^ (((~(((v85 ^ ((int)((unsigned int)((int)((unsigned int)v81 >> 2)) >> 1))) | (-(v85 ^ ((int)((unsigned int)((int)((unsigned int)v81 >> 2)) >> 1))))) >> 31)) | (~(((v86 ^ ((int)((unsigned int)((int)((unsigned int)v81 >> 2)) >> 1))) | (-(v86 ^ ((int)((unsigned int)((int)((unsigned int)v81 >> 2)) >> 1))))) >> 31))) & 104)) ^ (((~(((v83 ^ ((int)((unsigned int)((int)((unsigned int)v81 >> 2)) >> 1))) | (-(v83 ^ ((int)((unsigned int)((int)((unsigned int)v81 >> 2)) >> 1))))) >> 31)) | (~(((v84 ^ ((int)((unsigned int)((int)((unsigned int)v81 >> 2)) >> 1))) | (-(v84 ^ ((int)((unsigned int)((int)((unsigned int)v81 >> 2)) >> 1))))) >> 31))) & (1 ^ (100 ^ (((~(((v85 ^ ((int)((unsigned int)((int)((unsigned int)v81 >> 2)) >> 1))) | (-(v85 ^ ((int)((unsigned int)((int)((unsigned int)v81 >> 2)) >> 1))))) >> 31)) | (~(((v86 ^ ((int)((unsigned int)((int)((unsigned int)v81 >> 2)) >> 1))) | (-(v86 ^ ((int)((unsigned int)((int)((unsigned int)v81 >> 2)) >> 1))))) >> 31))) & 104)))));
  v77->timer = v196;
  int * v89 = v77->cache_vals;
  bool v197 = !(((~(((v83 ^ ((int)((unsigned int)((int)((unsigned int)v81 >> 2)) >> 1))) | (-(v83 ^ ((int)((unsigned int)((int)((unsigned int)v81 >> 2)) >> 1))))) >> 31)) | (~(((v84 ^ ((int)((unsigned int)((int)((unsigned int)v81 >> 2)) >> 1))) | (-(v84 ^ ((int)((unsigned int)((int)((unsigned int)v81 >> 2)) >> 1))))) >> 31))) == 0);
  int v182;
  if (v197) {
    int * v90 = v77->cache_age;
    int v199 = ((((int)((unsigned int)((int)((unsigned int)v81 >> 2)) >> 1)) & 1) * 2) + ((~(((v84 ^ ((int)((unsigned int)((int)((unsigned int)v81 >> 2)) >> 1))) | (-(v84 ^ ((int)((unsigned int)((int)((unsigned int)v81 >> 2)) >> 1))))) >> 31)) & 1);
    int v91 = v90[v199];
    int v92 = v90[v192];
    int v200 = v92 + ((int)((unsigned int)(v92 - v91) >> 31));
    v90[v192] = v200;
    int * v94 = v77->cache_age;
    int v95 = v94[v193];
    int v202 = v95 + ((int)((unsigned int)(v95 - v91) >> 31));
    v94[v193] = v202;
    int * v97 = v77->cache_age;
    v97[v199] = 0;
    v182 = v199;
  } else {
    int * v100 = v77->cache_age;
    int v206 = (((int)((unsigned int)((int)((unsigned int)v81 >> 2)) >> 1)) & 1) * 2;
    int v101 = v100[v206];
    int * v102 = v77->cache_tags;
    int v103 = v102[v206];
    int v104 = v100[v193];
    int v105 = v102[v193];
    bool v208 = !(((~(((v85 ^ ((int)((unsigned int)((int)((unsigned int)v81 >> 2)) >> 1))) | (-(v85 ^ ((int)((unsigned int)((int)((unsigned int)v81 >> 2)) >> 1))))) >> 31)) | (~(((v86 ^ ((int)((unsigned int)((int)((unsigned int)v81 >> 2)) >> 1))) | (-(v86 ^ ((int)((unsigned int)((int)((unsigned int)v81 >> 2)) >> 1))))) >> 31))) == 0);
    int v159;
    if (v208) {
      int * v106 = v77->cache_age;
      int v210 = (4 + ((((int)((unsigned int)((int)((unsigned int)v81 >> 2)) >> 1)) & 3) * 2)) + ((~(((v86 ^ ((int)((unsigned int)((int)((unsigned int)v81 >> 2)) >> 1))) | (-(v86 ^ ((int)((unsigned int)((int)((unsigned int)v81 >> 2)) >> 1))))) >> 31)) & 1);
      int v107 = v106[v210];
      int v108 = v106[v194];
      int v211 = v108 + ((int)((unsigned int)(v108 - v107) >> 31));
      v106[v194] = v211;
      int * v110 = v77->cache_age;
      int v111 = v110[v195];
      int v213 = v111 + ((int)((unsigned int)(v111 - v107) >> 31));
      v110[v195] = v213;
      int * v113 = v77->cache_age;
      v113[v210] = 0;
      v159 = v210;
    } else {
      int * v116 = v77->cache_age;
      int v217 = 4 + ((((int)((unsigned int)((int)((unsigned int)v81 >> 2)) >> 1)) & 3) * 2);
      int v117 = v116[v217];
      int * v118 = v77->cache_tags;
      int v119 = v118[v217];
      int v120 = v116[v195];
      int v121 = v118[v195];
      int * v122 = v77->cache_dirty;
      int v220 = (4 + ((((int)((unsigned int)((int)((unsigned int)v81 >> 2)) >> 1)) & 3) * 2)) + ((((v117 + ((~(((v119 ^ -1) | (-(v119 ^ -1))) >> 31)) & 2)) - (v120 + ((~(((v121 ^ -1) | (-(v121 ^ -1))) >> 31)) & 2))) >> 31) & 1);
      int v123 = v122[v220];
      bool v221 = !(v123 == 0);
      if (v221) {
        int * v124 = v77->cache_tags;
        int v125 = v124[v220];
        int * v126 = v77->cache_vals;
        int v224 = ((4 + ((((int)((unsigned int)((int)((unsigned int)v81 >> 2)) >> 1)) & 3) * 2)) + ((((v117 + ((~(((v119 ^ -1) | (-(v119 ^ -1))) >> 31)) & 2)) - (v120 + ((~(((v121 ^ -1) | (-(v121 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
        int v127 = v126[v224];
        int v225 = (((4 + ((((int)((unsigned int)((int)((unsigned int)v81 >> 2)) >> 1)) & 3) * 2)) + ((((v117 + ((~(((v119 ^ -1) | (-(v119 ^ -1))) >> 31)) & 2)) - (v120 + ((~(((v121 ^ -1) | (-(v121 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
        int v128 = v126[v225];
        int * v129 = v77->mem;
        int v227 = v125 * 2;
        v129[v227] = v127;
        int * v131 = v77->mem;
        int v230 = (v125 * 2) + 1;
        v131[v230] = v128;
        ;
      } else {
        ;
      }
      int * v136 = v77->mem;
      int v235 = ((int)((unsigned int)((int)((unsigned int)v81 >> 2)) >> 1)) * 2;
      int v137 = v136[v235];
      int v236 = (((int)((unsigned int)((int)((unsigned int)v81 >> 2)) >> 1)) * 2) + 1;
      int v138 = v136[v236];
      int * v139 = v77->cache_vals;
      int v238 = ((4 + ((((int)((unsigned int)((int)((unsigned int)v81 >> 2)) >> 1)) & 3) * 2)) + ((((v117 + ((~(((v119 ^ -1) | (-(v119 ^ -1))) >> 31)) & 2)) - (v120 + ((~(((v121 ^ -1) | (-(v121 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
      v139[v238] = v137;
      int * v141 = v77->cache_vals;
      int v241 = (((4 + ((((int)((unsigned int)((int)((unsigned int)v81 >> 2)) >> 1)) & 3) * 2)) + ((((v117 + ((~(((v119 ^ -1) | (-(v119 ^ -1))) >> 31)) & 2)) - (v120 + ((~(((v121 ^ -1) | (-(v121 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
      v141[v241] = v138;
      int * v143 = v77->cache_tags;
      int v244 = (int)((unsigned int)((int)((unsigned int)v81 >> 2)) >> 1);
      v143[v220] = v244;
      int * v145 = v77->cache_dirty;
      v145[v220] = 0;
      int * v147 = v77->cache_age;
      v147[v220] = 1;
      int * v149 = v77->cache_age;
      int v150 = v149[v220];
      int v151 = v149[v194];
      int v250 = v151 + ((int)((unsigned int)(v151 - v150) >> 31));
      v149[v194] = v250;
      int * v153 = v77->cache_age;
      int v154 = v153[v195];
      int v252 = v154 + ((int)((unsigned int)(v154 - v150) >> 31));
      v153[v195] = v252;
      int * v156 = v77->cache_age;
      v156[v220] = 0;
      v159 = v220;
    }
    int * v160 = v77->cache_vals;
    int v255 = v159 * 2;
    int v161 = v160[v255];
    int v256 = (v159 * 2) + 1;
    int v162 = v160[v256];
    int v257 = (((((int)((unsigned int)((int)((unsigned int)v81 >> 2)) >> 1)) & 1) * 2) + ((((v101 + ((~(((v103 ^ -1) | (-(v103 ^ -1))) >> 31)) & 2)) - (v104 + ((~(((v105 ^ -1) | (-(v105 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
    v160[v257] = v161;
    int * v164 = v77->cache_vals;
    int v260 = ((((((int)((unsigned int)((int)((unsigned int)v81 >> 2)) >> 1)) & 1) * 2) + ((((v101 + ((~(((v103 ^ -1) | (-(v103 ^ -1))) >> 31)) & 2)) - (v104 + ((~(((v105 ^ -1) | (-(v105 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
    v164[v260] = v162;
    int * v166 = v77->cache_tags;
    int v263 = ((((int)((unsigned int)((int)((unsigned int)v81 >> 2)) >> 1)) & 1) * 2) + ((((v101 + ((~(((v103 ^ -1) | (-(v103 ^ -1))) >> 31)) & 2)) - (v104 + ((~(((v105 ^ -1) | (-(v105 ^ -1))) >> 31)) & 2))) >> 31) & 1);
    int v264 = (int)((unsigned int)((int)((unsigned int)v81 >> 2)) >> 1);
    v166[v263] = v264;
    int * v168 = v77->cache_dirty;
    v168[v263] = 0;
    int * v170 = v77->cache_age;
    v170[v263] = 1;
    int * v172 = v77->cache_age;
    int v173 = v172[v263];
    int v174 = v172[v192];
    int v270 = v174 + ((int)((unsigned int)(v174 - v173) >> 31));
    v172[v192] = v270;
    int * v176 = v77->cache_age;
    int v177 = v176[v193];
    int v272 = v177 + ((int)((unsigned int)(v177 - v173) >> 31));
    v176[v193] = v272;
    int * v179 = v77->cache_age;
    v179[v263] = 0;
    v182 = v263;
  }
  int v275 = (v182 * 2) + (((int)((unsigned int)v81 >> 2)) & 1);
  int v183 = v89[v275];
  int * v184 = v77->regs;
  v184[5] = v183;
  struct StateT * v186 = slot_6(v77);
  return v186;
}

struct StateT * slot_2(struct StateT * v28) {
  int v29 = v28->timer;
  int v35 = v29 + 1;
  v28->timer = v35;
  int * v31 = v28->regs;
  v31[9] = 80;
  struct StateT * v33 = slot_3(v28);
  return v33;
}

struct StateT * slot_7(struct StateT * v596) {
  int v597 = v596->timer;
  int v707 = v597 + 1;
  v596->timer = v707;
  int * v599 = v596->regs;
  int v600 = v599[6];
  int * v601 = v596->cache_tags;
  int v711 = (((int)((unsigned int)((int)((unsigned int)v600 >> 2)) >> 1)) & 1) * 2;
  int v602 = v601[v711];
  int v712 = ((((int)((unsigned int)((int)((unsigned int)v600 >> 2)) >> 1)) & 1) * 2) + 1;
  int v603 = v601[v712];
  int v713 = 4 + ((((int)((unsigned int)((int)((unsigned int)v600 >> 2)) >> 1)) & 3) * 2);
  int v604 = v601[v713];
  int v714 = (4 + ((((int)((unsigned int)((int)((unsigned int)v600 >> 2)) >> 1)) & 3) * 2)) + 1;
  int v605 = v601[v714];
  int v606 = v596->timer;
  int v715 = v606 + ((100 ^ (((~(((v604 ^ ((int)((unsigned int)((int)((unsigned int)v600 >> 2)) >> 1))) | (-(v604 ^ ((int)((unsigned int)((int)((unsigned int)v600 >> 2)) >> 1))))) >> 31)) | (~(((v605 ^ ((int)((unsigned int)((int)((unsigned int)v600 >> 2)) >> 1))) | (-(v605 ^ ((int)((unsigned int)((int)((unsigned int)v600 >> 2)) >> 1))))) >> 31))) & 104)) ^ (((~(((v602 ^ ((int)((unsigned int)((int)((unsigned int)v600 >> 2)) >> 1))) | (-(v602 ^ ((int)((unsigned int)((int)((unsigned int)v600 >> 2)) >> 1))))) >> 31)) | (~(((v603 ^ ((int)((unsigned int)((int)((unsigned int)v600 >> 2)) >> 1))) | (-(v603 ^ ((int)((unsigned int)((int)((unsigned int)v600 >> 2)) >> 1))))) >> 31))) & (1 ^ (100 ^ (((~(((v604 ^ ((int)((unsigned int)((int)((unsigned int)v600 >> 2)) >> 1))) | (-(v604 ^ ((int)((unsigned int)((int)((unsigned int)v600 >> 2)) >> 1))))) >> 31)) | (~(((v605 ^ ((int)((unsigned int)((int)((unsigned int)v600 >> 2)) >> 1))) | (-(v605 ^ ((int)((unsigned int)((int)((unsigned int)v600 >> 2)) >> 1))))) >> 31))) & 104)))));
  v596->timer = v715;
  int * v608 = v596->cache_vals;
  bool v716 = !(((~(((v602 ^ ((int)((unsigned int)((int)((unsigned int)v600 >> 2)) >> 1))) | (-(v602 ^ ((int)((unsigned int)((int)((unsigned int)v600 >> 2)) >> 1))))) >> 31)) | (~(((v603 ^ ((int)((unsigned int)((int)((unsigned int)v600 >> 2)) >> 1))) | (-(v603 ^ ((int)((unsigned int)((int)((unsigned int)v600 >> 2)) >> 1))))) >> 31))) == 0);
  int v701;
  if (v716) {
    int * v609 = v596->cache_age;
    int v718 = ((((int)((unsigned int)((int)((unsigned int)v600 >> 2)) >> 1)) & 1) * 2) + ((~(((v603 ^ ((int)((unsigned int)((int)((unsigned int)v600 >> 2)) >> 1))) | (-(v603 ^ ((int)((unsigned int)((int)((unsigned int)v600 >> 2)) >> 1))))) >> 31)) & 1);
    int v610 = v609[v718];
    int v611 = v609[v711];
    int v719 = v611 + ((int)((unsigned int)(v611 - v610) >> 31));
    v609[v711] = v719;
    int * v613 = v596->cache_age;
    int v614 = v613[v712];
    int v721 = v614 + ((int)((unsigned int)(v614 - v610) >> 31));
    v613[v712] = v721;
    int * v616 = v596->cache_age;
    v616[v718] = 0;
    v701 = v718;
  } else {
    int * v619 = v596->cache_age;
    int v725 = (((int)((unsigned int)((int)((unsigned int)v600 >> 2)) >> 1)) & 1) * 2;
    int v620 = v619[v725];
    int * v621 = v596->cache_tags;
    int v622 = v621[v725];
    int v623 = v619[v712];
    int v624 = v621[v712];
    bool v727 = !(((~(((v604 ^ ((int)((unsigned int)((int)((unsigned int)v600 >> 2)) >> 1))) | (-(v604 ^ ((int)((unsigned int)((int)((unsigned int)v600 >> 2)) >> 1))))) >> 31)) | (~(((v605 ^ ((int)((unsigned int)((int)((unsigned int)v600 >> 2)) >> 1))) | (-(v605 ^ ((int)((unsigned int)((int)((unsigned int)v600 >> 2)) >> 1))))) >> 31))) == 0);
    int v678;
    if (v727) {
      int * v625 = v596->cache_age;
      int v729 = (4 + ((((int)((unsigned int)((int)((unsigned int)v600 >> 2)) >> 1)) & 3) * 2)) + ((~(((v605 ^ ((int)((unsigned int)((int)((unsigned int)v600 >> 2)) >> 1))) | (-(v605 ^ ((int)((unsigned int)((int)((unsigned int)v600 >> 2)) >> 1))))) >> 31)) & 1);
      int v626 = v625[v729];
      int v627 = v625[v713];
      int v730 = v627 + ((int)((unsigned int)(v627 - v626) >> 31));
      v625[v713] = v730;
      int * v629 = v596->cache_age;
      int v630 = v629[v714];
      int v732 = v630 + ((int)((unsigned int)(v630 - v626) >> 31));
      v629[v714] = v732;
      int * v632 = v596->cache_age;
      v632[v729] = 0;
      v678 = v729;
    } else {
      int * v635 = v596->cache_age;
      int v736 = 4 + ((((int)((unsigned int)((int)((unsigned int)v600 >> 2)) >> 1)) & 3) * 2);
      int v636 = v635[v736];
      int * v637 = v596->cache_tags;
      int v638 = v637[v736];
      int v639 = v635[v714];
      int v640 = v637[v714];
      int * v641 = v596->cache_dirty;
      int v739 = (4 + ((((int)((unsigned int)((int)((unsigned int)v600 >> 2)) >> 1)) & 3) * 2)) + ((((v636 + ((~(((v638 ^ -1) | (-(v638 ^ -1))) >> 31)) & 2)) - (v639 + ((~(((v640 ^ -1) | (-(v640 ^ -1))) >> 31)) & 2))) >> 31) & 1);
      int v642 = v641[v739];
      bool v740 = !(v642 == 0);
      if (v740) {
        int * v643 = v596->cache_tags;
        int v644 = v643[v739];
        int * v645 = v596->cache_vals;
        int v743 = ((4 + ((((int)((unsigned int)((int)((unsigned int)v600 >> 2)) >> 1)) & 3) * 2)) + ((((v636 + ((~(((v638 ^ -1) | (-(v638 ^ -1))) >> 31)) & 2)) - (v639 + ((~(((v640 ^ -1) | (-(v640 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
        int v646 = v645[v743];
        int v744 = (((4 + ((((int)((unsigned int)((int)((unsigned int)v600 >> 2)) >> 1)) & 3) * 2)) + ((((v636 + ((~(((v638 ^ -1) | (-(v638 ^ -1))) >> 31)) & 2)) - (v639 + ((~(((v640 ^ -1) | (-(v640 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
        int v647 = v645[v744];
        int * v648 = v596->mem;
        int v746 = v644 * 2;
        v648[v746] = v646;
        int * v650 = v596->mem;
        int v749 = (v644 * 2) + 1;
        v650[v749] = v647;
        ;
      } else {
        ;
      }
      int * v655 = v596->mem;
      int v754 = ((int)((unsigned int)((int)((unsigned int)v600 >> 2)) >> 1)) * 2;
      int v656 = v655[v754];
      int v755 = (((int)((unsigned int)((int)((unsigned int)v600 >> 2)) >> 1)) * 2) + 1;
      int v657 = v655[v755];
      int * v658 = v596->cache_vals;
      int v757 = ((4 + ((((int)((unsigned int)((int)((unsigned int)v600 >> 2)) >> 1)) & 3) * 2)) + ((((v636 + ((~(((v638 ^ -1) | (-(v638 ^ -1))) >> 31)) & 2)) - (v639 + ((~(((v640 ^ -1) | (-(v640 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
      v658[v757] = v656;
      int * v660 = v596->cache_vals;
      int v760 = (((4 + ((((int)((unsigned int)((int)((unsigned int)v600 >> 2)) >> 1)) & 3) * 2)) + ((((v636 + ((~(((v638 ^ -1) | (-(v638 ^ -1))) >> 31)) & 2)) - (v639 + ((~(((v640 ^ -1) | (-(v640 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
      v660[v760] = v657;
      int * v662 = v596->cache_tags;
      int v763 = (int)((unsigned int)((int)((unsigned int)v600 >> 2)) >> 1);
      v662[v739] = v763;
      int * v664 = v596->cache_dirty;
      v664[v739] = 0;
      int * v666 = v596->cache_age;
      v666[v739] = 1;
      int * v668 = v596->cache_age;
      int v669 = v668[v739];
      int v670 = v668[v713];
      int v769 = v670 + ((int)((unsigned int)(v670 - v669) >> 31));
      v668[v713] = v769;
      int * v672 = v596->cache_age;
      int v673 = v672[v714];
      int v771 = v673 + ((int)((unsigned int)(v673 - v669) >> 31));
      v672[v714] = v771;
      int * v675 = v596->cache_age;
      v675[v739] = 0;
      v678 = v739;
    }
    int * v679 = v596->cache_vals;
    int v774 = v678 * 2;
    int v680 = v679[v774];
    int v775 = (v678 * 2) + 1;
    int v681 = v679[v775];
    int v776 = (((((int)((unsigned int)((int)((unsigned int)v600 >> 2)) >> 1)) & 1) * 2) + ((((v620 + ((~(((v622 ^ -1) | (-(v622 ^ -1))) >> 31)) & 2)) - (v623 + ((~(((v624 ^ -1) | (-(v624 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
    v679[v776] = v680;
    int * v683 = v596->cache_vals;
    int v779 = ((((((int)((unsigned int)((int)((unsigned int)v600 >> 2)) >> 1)) & 1) * 2) + ((((v620 + ((~(((v622 ^ -1) | (-(v622 ^ -1))) >> 31)) & 2)) - (v623 + ((~(((v624 ^ -1) | (-(v624 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
    v683[v779] = v681;
    int * v685 = v596->cache_tags;
    int v782 = ((((int)((unsigned int)((int)((unsigned int)v600 >> 2)) >> 1)) & 1) * 2) + ((((v620 + ((~(((v622 ^ -1) | (-(v622 ^ -1))) >> 31)) & 2)) - (v623 + ((~(((v624 ^ -1) | (-(v624 ^ -1))) >> 31)) & 2))) >> 31) & 1);
    int v783 = (int)((unsigned int)((int)((unsigned int)v600 >> 2)) >> 1);
    v685[v782] = v783;
    int * v687 = v596->cache_dirty;
    v687[v782] = 0;
    int * v689 = v596->cache_age;
    v689[v782] = 1;
    int * v691 = v596->cache_age;
    int v692 = v691[v782];
    int v693 = v691[v711];
    int v789 = v693 + ((int)((unsigned int)(v693 - v692) >> 31));
    v691[v711] = v789;
    int * v695 = v596->cache_age;
    int v696 = v695[v712];
    int v791 = v696 + ((int)((unsigned int)(v696 - v692) >> 31));
    v695[v712] = v791;
    int * v698 = v596->cache_age;
    v698[v782] = 0;
    v701 = v782;
  }
  int v794 = (v701 * 2) + (((int)((unsigned int)v600 >> 2)) & 1);
  int v702 = v608[v794];
  int * v703 = v596->regs;
  v703[11] = v702;
  struct StateT * v705 = slot_8(v596);
  return v705;
}

struct StateT * slot_3(struct StateT * v41) {
  int v42 = v41->timer;
  int v52 = v42 + 1;
  v41->timer = v52;
  int * v44 = v41->regs;
  int v45 = v44[6];
  int v46 = v44[7];
  bool v56 = v45 >= v46;
  struct StateT * v50;
  if (v56) {
    v50 = v41;
  } else {
    struct StateT * v48 = slot_4(v41);
    v50 = v48;
  }
  return v50;
}

struct StateT * snippet(struct StateT * v0) {
  struct StateT * v1 = slot_0(v0);
  return v1;
}

struct StateT * slot_1(struct StateT * v15) {
  int v16 = v15->timer;
  int v22 = v16 + 1;
  v15->timer = v22;
  int * v18 = v15->regs;
  v18[7] = 16;
  struct StateT * v20 = slot_2(v15);
  return v20;
}

struct StateT * slot_8(struct StateT * v800) {
  int v801 = v800->timer;
  int v808 = v801 + 1;
  v800->timer = v808;
  int * v803 = v800->regs;
  int v804 = v803[6];
  int v811 = v804 + 4;
  v803[6] = v811;
  struct StateT * v806 = slot_9(v800);
  return v806;
}

struct StateT * slot_4(struct StateT * v60) {
  int v61 = v60->timer;
  int v69 = v61 + 1;
  v60->timer = v69;
  int * v63 = v60->regs;
  int v64 = v63[9];
  int v65 = v63[6];
  int v74 = v64 + v65;
  v63[8] = v74;
  struct StateT * v67 = slot_5(v60);
  return v67;
}

struct StateT * slot_9(struct StateT * v814) {
  int v815 = v814->timer;
  int v819 = v815 + 1;
  v814->timer = v819;
  struct StateT * v817 = slot_3(v814);
  return v817;
}

struct StateT * slot_0(struct StateT * v2) {
  int v3 = v2->timer;
  int v9 = v3 + 1;
  v2->timer = v9;
  int * v5 = v2->regs;
  v5[6] = 0;
  struct StateT * v7 = slot_1(v2);
  return v7;
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
  struct StateT *s1_ = snippet(&s1);
  struct StateT *s2_ = snippet(&s2);
  //@ assert untainted_timer: !\tainted(s1_->timer==s2_->timer);
  koika_assert(s1_->timer==s2_->timer, "timing leak");
  return 0;
}