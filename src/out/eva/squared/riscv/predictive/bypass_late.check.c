// verify: leak widened (the program is clean; Eva cannot prove it) [unroll 65]
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

struct StateT2 * slot_5(struct StateT2 * v214);
struct StateT2 * slot_2(struct StateT2 * v78);
struct StateT2 * slot_7(struct StateT2 * v290);
struct StateT2 * slot_3(struct StateT2 * v102);
struct StateT2 * snippet(struct StateT2 * v0);
struct StateT2 * slot_10(struct StateT2 * v1383);
struct StateT2 * slot_1(struct StateT2 * v42);
struct StateT2 * slot_8(struct StateT2 * v926);
struct StateT2 * slot_4(struct StateT2 * v160);
struct StateT2 * slot_9(struct StateT2 * v1344);
struct StateT2 * slot_0(struct StateT2 * v2);
struct StateT2 * slot_5(struct StateT2 * v214) {
  struct StateT * v215 = v214->a;
  int v216 = v215->timer;
  struct StateT * v217 = v214->b;
  int v218 = v217->timer;
  bool v260 = v216 == v218;
  squared_assert(v260);
  squared_assume(v260);
  struct StateT * v221 = v214->a;
  int * v222 = v221->regs;
  int v223 = v222[5];
  int v224 = v222[9];
  struct StateT * v225 = v214->b;
  int * v226 = v225->regs;
  int v227 = v226[5];
  int v228 = v226[9];
  bool v267 = (v223 >= v224) == (v227 >= v228);
  squared_diverged(v267);
  squared_assume(v267);
  bool v268 = v223 >= v224;
  struct StateT2 * v256;
  if (v268) {
    struct StateT * v231 = v214->a;
    int v232 = v231->timer;
    int v270 = v232 + 15;
    v231->timer = v270;
    int * v234 = v231->saved_regs;
    int v235 = v234[6];
    int * v236 = v231->regs;
    v236[6] = v235;
    int * v238 = v231->saved_regs;
    int v239 = v238[7];
    int * v240 = v231->regs;
    v240[7] = v239;
    struct StateT * v242 = v214->b;
    int v243 = v242->timer;
    int v280 = v243 + 15;
    v242->timer = v280;
    int * v245 = v242->saved_regs;
    int v246 = v245[6];
    int * v247 = v242->regs;
    v247[6] = v246;
    int * v249 = v242->saved_regs;
    int v250 = v249[7];
    int * v251 = v242->regs;
    v251[7] = v250;
    v256 = v214;
  } else {
    struct StateT2 * v254 = slot_7(v214);
    v256 = v254;
  }
  return v256;
}

struct StateT2 * slot_2(struct StateT2 * v78) {
  struct StateT * v79 = v78->a;
  int v80 = v79->timer;
  struct StateT * v81 = v78->b;
  int v82 = v81->timer;
  bool v95 = v80 == v82;
  squared_assert(v95);
  squared_assume(v95);
  struct StateT * v85 = v78->a;
  int v86 = v85->timer;
  int v97 = v86 + 1;
  v85->timer = v97;
  struct StateT * v88 = v78->b;
  int v89 = v88->timer;
  int v99 = v89 + 1;
  v88->timer = v99;
  struct StateT2 * v91 = slot_3(v78);
  return v91;
}

struct StateT2 * slot_7(struct StateT2 * v290) {
  struct StateT * v291 = v290->a;
  int v292 = v291->timer;
  struct StateT * v293 = v290->b;
  int v294 = v293->timer;
  bool v641 = v292 == v294;
  squared_assert(v641);
  squared_assume(v641);
  struct StateT * v297 = v290->a;
  int v298 = v297->timer;
  int v643 = v298 + 1;
  v297->timer = v643;
  struct StateT * v300 = v290->b;
  int v301 = v300->timer;
  int v645 = v301 + 1;
  v300->timer = v645;
  struct StateT * v303 = v290->a;
  int * v304 = v303->regs;
  int v305 = v304[6];
  int v306 = v304[7];
  int * v307 = v303->cache_tags;
  int v651 = (((int)((unsigned int)((int)((unsigned int)v305 >> 2)) >> 1)) & 1) * 2;
  int v308 = v307[v651];
  int v652 = ((((int)((unsigned int)((int)((unsigned int)v305 >> 2)) >> 1)) & 1) * 2) + 1;
  int v309 = v307[v652];
  int v653 = 4 + ((((int)((unsigned int)((int)((unsigned int)v305 >> 2)) >> 1)) & 3) * 2);
  int v310 = v307[v653];
  int v654 = (4 + ((((int)((unsigned int)((int)((unsigned int)v305 >> 2)) >> 1)) & 3) * 2)) + 1;
  int v311 = v307[v654];
  int v312 = v303->timer;
  int v655 = v312 + ((100 ^ (((~(((v310 ^ ((int)((unsigned int)((int)((unsigned int)v305 >> 2)) >> 1))) | (-(v310 ^ ((int)((unsigned int)((int)((unsigned int)v305 >> 2)) >> 1))))) >> 31)) | (~(((v311 ^ ((int)((unsigned int)((int)((unsigned int)v305 >> 2)) >> 1))) | (-(v311 ^ ((int)((unsigned int)((int)((unsigned int)v305 >> 2)) >> 1))))) >> 31))) & 104)) ^ (((~(((v308 ^ ((int)((unsigned int)((int)((unsigned int)v305 >> 2)) >> 1))) | (-(v308 ^ ((int)((unsigned int)((int)((unsigned int)v305 >> 2)) >> 1))))) >> 31)) | (~(((v309 ^ ((int)((unsigned int)((int)((unsigned int)v305 >> 2)) >> 1))) | (-(v309 ^ ((int)((unsigned int)((int)((unsigned int)v305 >> 2)) >> 1))))) >> 31))) & (1 ^ (100 ^ (((~(((v310 ^ ((int)((unsigned int)((int)((unsigned int)v305 >> 2)) >> 1))) | (-(v310 ^ ((int)((unsigned int)((int)((unsigned int)v305 >> 2)) >> 1))))) >> 31)) | (~(((v311 ^ ((int)((unsigned int)((int)((unsigned int)v305 >> 2)) >> 1))) | (-(v311 ^ ((int)((unsigned int)((int)((unsigned int)v305 >> 2)) >> 1))))) >> 31))) & 104)))));
  v303->timer = v655;
  bool v656 = !(((~(((v308 ^ ((int)((unsigned int)((int)((unsigned int)v305 >> 2)) >> 1))) | (-(v308 ^ ((int)((unsigned int)((int)((unsigned int)v305 >> 2)) >> 1))))) >> 31)) | (~(((v309 ^ ((int)((unsigned int)((int)((unsigned int)v305 >> 2)) >> 1))) | (-(v309 ^ ((int)((unsigned int)((int)((unsigned int)v305 >> 2)) >> 1))))) >> 31))) == 0);
  int v406;
  if (v656) {
    int * v314 = v303->cache_age;
    int v658 = ((((int)((unsigned int)((int)((unsigned int)v305 >> 2)) >> 1)) & 1) * 2) + ((~(((v309 ^ ((int)((unsigned int)((int)((unsigned int)v305 >> 2)) >> 1))) | (-(v309 ^ ((int)((unsigned int)((int)((unsigned int)v305 >> 2)) >> 1))))) >> 31)) & 1);
    int v315 = v314[v658];
    int v316 = v314[v651];
    int v659 = v316 + ((int)((unsigned int)(v316 - v315) >> 31));
    v314[v651] = v659;
    int * v318 = v303->cache_age;
    int v319 = v318[v652];
    int v661 = v319 + ((int)((unsigned int)(v319 - v315) >> 31));
    v318[v652] = v661;
    int * v321 = v303->cache_age;
    v321[v658] = 0;
    v406 = v658;
  } else {
    int * v324 = v303->cache_age;
    int v665 = (((int)((unsigned int)((int)((unsigned int)v305 >> 2)) >> 1)) & 1) * 2;
    int v325 = v324[v665];
    int * v326 = v303->cache_tags;
    int v327 = v326[v665];
    int v328 = v324[v652];
    int v329 = v326[v652];
    bool v667 = !(((~(((v310 ^ ((int)((unsigned int)((int)((unsigned int)v305 >> 2)) >> 1))) | (-(v310 ^ ((int)((unsigned int)((int)((unsigned int)v305 >> 2)) >> 1))))) >> 31)) | (~(((v311 ^ ((int)((unsigned int)((int)((unsigned int)v305 >> 2)) >> 1))) | (-(v311 ^ ((int)((unsigned int)((int)((unsigned int)v305 >> 2)) >> 1))))) >> 31))) == 0);
    int v383;
    if (v667) {
      int * v330 = v303->cache_age;
      int v669 = (4 + ((((int)((unsigned int)((int)((unsigned int)v305 >> 2)) >> 1)) & 3) * 2)) + ((~(((v311 ^ ((int)((unsigned int)((int)((unsigned int)v305 >> 2)) >> 1))) | (-(v311 ^ ((int)((unsigned int)((int)((unsigned int)v305 >> 2)) >> 1))))) >> 31)) & 1);
      int v331 = v330[v669];
      int v332 = v330[v653];
      int v670 = v332 + ((int)((unsigned int)(v332 - v331) >> 31));
      v330[v653] = v670;
      int * v334 = v303->cache_age;
      int v335 = v334[v654];
      int v672 = v335 + ((int)((unsigned int)(v335 - v331) >> 31));
      v334[v654] = v672;
      int * v337 = v303->cache_age;
      v337[v669] = 0;
      v383 = v669;
    } else {
      int * v340 = v303->cache_age;
      int v676 = 4 + ((((int)((unsigned int)((int)((unsigned int)v305 >> 2)) >> 1)) & 3) * 2);
      int v341 = v340[v676];
      int * v342 = v303->cache_tags;
      int v343 = v342[v676];
      int v344 = v340[v654];
      int v345 = v342[v654];
      int * v346 = v303->cache_dirty;
      int v679 = (4 + ((((int)((unsigned int)((int)((unsigned int)v305 >> 2)) >> 1)) & 3) * 2)) + ((((v341 + ((~(((v343 ^ -1) | (-(v343 ^ -1))) >> 31)) & 2)) - (v344 + ((~(((v345 ^ -1) | (-(v345 ^ -1))) >> 31)) & 2))) >> 31) & 1);
      int v347 = v346[v679];
      bool v680 = !(v347 == 0);
      if (v680) {
        int * v348 = v303->cache_tags;
        int v349 = v348[v679];
        int * v350 = v303->cache_vals;
        int v683 = ((4 + ((((int)((unsigned int)((int)((unsigned int)v305 >> 2)) >> 1)) & 3) * 2)) + ((((v341 + ((~(((v343 ^ -1) | (-(v343 ^ -1))) >> 31)) & 2)) - (v344 + ((~(((v345 ^ -1) | (-(v345 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
        int v351 = v350[v683];
        int v684 = (((4 + ((((int)((unsigned int)((int)((unsigned int)v305 >> 2)) >> 1)) & 3) * 2)) + ((((v341 + ((~(((v343 ^ -1) | (-(v343 ^ -1))) >> 31)) & 2)) - (v344 + ((~(((v345 ^ -1) | (-(v345 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
        int v352 = v350[v684];
        int * v353 = v303->mem;
        int v686 = v349 * 2;
        v353[v686] = v351;
        int * v355 = v303->mem;
        int v689 = (v349 * 2) + 1;
        v355[v689] = v352;
        ;
      } else {
        ;
      }
      int * v360 = v303->mem;
      int v694 = ((int)((unsigned int)((int)((unsigned int)v305 >> 2)) >> 1)) * 2;
      int v361 = v360[v694];
      int v695 = (((int)((unsigned int)((int)((unsigned int)v305 >> 2)) >> 1)) * 2) + 1;
      int v362 = v360[v695];
      int * v363 = v303->cache_vals;
      int v697 = ((4 + ((((int)((unsigned int)((int)((unsigned int)v305 >> 2)) >> 1)) & 3) * 2)) + ((((v341 + ((~(((v343 ^ -1) | (-(v343 ^ -1))) >> 31)) & 2)) - (v344 + ((~(((v345 ^ -1) | (-(v345 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
      v363[v697] = v361;
      int * v365 = v303->cache_vals;
      int v700 = (((4 + ((((int)((unsigned int)((int)((unsigned int)v305 >> 2)) >> 1)) & 3) * 2)) + ((((v341 + ((~(((v343 ^ -1) | (-(v343 ^ -1))) >> 31)) & 2)) - (v344 + ((~(((v345 ^ -1) | (-(v345 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
      v365[v700] = v362;
      int * v367 = v303->cache_tags;
      int v703 = (int)((unsigned int)((int)((unsigned int)v305 >> 2)) >> 1);
      v367[v679] = v703;
      int * v369 = v303->cache_dirty;
      v369[v679] = 0;
      int * v371 = v303->cache_age;
      v371[v679] = 1;
      int * v373 = v303->cache_age;
      int v374 = v373[v679];
      int v375 = v373[v653];
      int v709 = v375 + ((int)((unsigned int)(v375 - v374) >> 31));
      v373[v653] = v709;
      int * v377 = v303->cache_age;
      int v378 = v377[v654];
      int v711 = v378 + ((int)((unsigned int)(v378 - v374) >> 31));
      v377[v654] = v711;
      int * v380 = v303->cache_age;
      v380[v679] = 0;
      v383 = v679;
    }
    int * v384 = v303->cache_vals;
    int v714 = v383 * 2;
    int v385 = v384[v714];
    int v715 = (v383 * 2) + 1;
    int v386 = v384[v715];
    int v716 = (((((int)((unsigned int)((int)((unsigned int)v305 >> 2)) >> 1)) & 1) * 2) + ((((v325 + ((~(((v327 ^ -1) | (-(v327 ^ -1))) >> 31)) & 2)) - (v328 + ((~(((v329 ^ -1) | (-(v329 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
    v384[v716] = v385;
    int * v388 = v303->cache_vals;
    int v719 = ((((((int)((unsigned int)((int)((unsigned int)v305 >> 2)) >> 1)) & 1) * 2) + ((((v325 + ((~(((v327 ^ -1) | (-(v327 ^ -1))) >> 31)) & 2)) - (v328 + ((~(((v329 ^ -1) | (-(v329 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
    v388[v719] = v386;
    int * v390 = v303->cache_tags;
    int v722 = ((((int)((unsigned int)((int)((unsigned int)v305 >> 2)) >> 1)) & 1) * 2) + ((((v325 + ((~(((v327 ^ -1) | (-(v327 ^ -1))) >> 31)) & 2)) - (v328 + ((~(((v329 ^ -1) | (-(v329 ^ -1))) >> 31)) & 2))) >> 31) & 1);
    int v723 = (int)((unsigned int)((int)((unsigned int)v305 >> 2)) >> 1);
    v390[v722] = v723;
    int * v392 = v303->cache_dirty;
    v392[v722] = 0;
    int * v394 = v303->cache_age;
    v394[v722] = 1;
    int * v396 = v303->cache_age;
    int v397 = v396[v722];
    int v398 = v396[v651];
    int v729 = v398 + ((int)((unsigned int)(v398 - v397) >> 31));
    v396[v651] = v729;
    int * v400 = v303->cache_age;
    int v401 = v400[v652];
    int v731 = v401 + ((int)((unsigned int)(v401 - v397) >> 31));
    v400[v652] = v731;
    int * v403 = v303->cache_age;
    v403[v722] = 0;
    v406 = v722;
  }
  int * v407 = v303->cache_vals;
  int v734 = (v406 * 2) + (((int)((unsigned int)v305 >> 2)) & 1);
  v407[v734] = v306;
  int * v409 = v303->cache_tags;
  int v410 = v409[v653];
  int v411 = v409[v654];
  bool v737 = !(((~(((v410 ^ ((int)((unsigned int)((int)((unsigned int)v305 >> 2)) >> 1))) | (-(v410 ^ ((int)((unsigned int)((int)((unsigned int)v305 >> 2)) >> 1))))) >> 31)) | (~(((v411 ^ ((int)((unsigned int)((int)((unsigned int)v305 >> 2)) >> 1))) | (-(v411 ^ ((int)((unsigned int)((int)((unsigned int)v305 >> 2)) >> 1))))) >> 31))) == 0);
  int v465;
  if (v737) {
    int * v412 = v303->cache_age;
    int v739 = (4 + ((((int)((unsigned int)((int)((unsigned int)v305 >> 2)) >> 1)) & 3) * 2)) + ((~(((v411 ^ ((int)((unsigned int)((int)((unsigned int)v305 >> 2)) >> 1))) | (-(v411 ^ ((int)((unsigned int)((int)((unsigned int)v305 >> 2)) >> 1))))) >> 31)) & 1);
    int v413 = v412[v739];
    int v414 = v412[v653];
    int v740 = v414 + ((int)((unsigned int)(v414 - v413) >> 31));
    v412[v653] = v740;
    int * v416 = v303->cache_age;
    int v417 = v416[v654];
    int v742 = v417 + ((int)((unsigned int)(v417 - v413) >> 31));
    v416[v654] = v742;
    int * v419 = v303->cache_age;
    v419[v739] = 0;
    v465 = v739;
  } else {
    int * v422 = v303->cache_age;
    int v746 = 4 + ((((int)((unsigned int)((int)((unsigned int)v305 >> 2)) >> 1)) & 3) * 2);
    int v423 = v422[v746];
    int * v424 = v303->cache_tags;
    int v425 = v424[v746];
    int v426 = v422[v654];
    int v427 = v424[v654];
    int * v428 = v303->cache_dirty;
    int v749 = (4 + ((((int)((unsigned int)((int)((unsigned int)v305 >> 2)) >> 1)) & 3) * 2)) + ((((v423 + ((~(((v425 ^ -1) | (-(v425 ^ -1))) >> 31)) & 2)) - (v426 + ((~(((v427 ^ -1) | (-(v427 ^ -1))) >> 31)) & 2))) >> 31) & 1);
    int v429 = v428[v749];
    bool v750 = !(v429 == 0);
    if (v750) {
      int * v430 = v303->cache_tags;
      int v431 = v430[v749];
      int * v432 = v303->cache_vals;
      int v753 = ((4 + ((((int)((unsigned int)((int)((unsigned int)v305 >> 2)) >> 1)) & 3) * 2)) + ((((v423 + ((~(((v425 ^ -1) | (-(v425 ^ -1))) >> 31)) & 2)) - (v426 + ((~(((v427 ^ -1) | (-(v427 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
      int v433 = v432[v753];
      int v754 = (((4 + ((((int)((unsigned int)((int)((unsigned int)v305 >> 2)) >> 1)) & 3) * 2)) + ((((v423 + ((~(((v425 ^ -1) | (-(v425 ^ -1))) >> 31)) & 2)) - (v426 + ((~(((v427 ^ -1) | (-(v427 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
      int v434 = v432[v754];
      int * v435 = v303->mem;
      int v756 = v431 * 2;
      v435[v756] = v433;
      int * v437 = v303->mem;
      int v759 = (v431 * 2) + 1;
      v437[v759] = v434;
      ;
    } else {
      ;
    }
    int * v442 = v303->mem;
    int v764 = ((int)((unsigned int)((int)((unsigned int)v305 >> 2)) >> 1)) * 2;
    int v443 = v442[v764];
    int v765 = (((int)((unsigned int)((int)((unsigned int)v305 >> 2)) >> 1)) * 2) + 1;
    int v444 = v442[v765];
    int * v445 = v303->cache_vals;
    int v767 = ((4 + ((((int)((unsigned int)((int)((unsigned int)v305 >> 2)) >> 1)) & 3) * 2)) + ((((v423 + ((~(((v425 ^ -1) | (-(v425 ^ -1))) >> 31)) & 2)) - (v426 + ((~(((v427 ^ -1) | (-(v427 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
    v445[v767] = v443;
    int * v447 = v303->cache_vals;
    int v770 = (((4 + ((((int)((unsigned int)((int)((unsigned int)v305 >> 2)) >> 1)) & 3) * 2)) + ((((v423 + ((~(((v425 ^ -1) | (-(v425 ^ -1))) >> 31)) & 2)) - (v426 + ((~(((v427 ^ -1) | (-(v427 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
    v447[v770] = v444;
    int * v449 = v303->cache_tags;
    int v773 = (int)((unsigned int)((int)((unsigned int)v305 >> 2)) >> 1);
    v449[v749] = v773;
    int * v451 = v303->cache_dirty;
    v451[v749] = 0;
    int * v453 = v303->cache_age;
    v453[v749] = 1;
    int * v455 = v303->cache_age;
    int v456 = v455[v749];
    int v457 = v455[v653];
    int v779 = v457 + ((int)((unsigned int)(v457 - v456) >> 31));
    v455[v653] = v779;
    int * v459 = v303->cache_age;
    int v460 = v459[v654];
    int v781 = v460 + ((int)((unsigned int)(v460 - v456) >> 31));
    v459[v654] = v781;
    int * v462 = v303->cache_age;
    v462[v749] = 0;
    v465 = v749;
  }
  int * v466 = v303->cache_vals;
  int v784 = (v465 * 2) + (((int)((unsigned int)v305 >> 2)) & 1);
  v466[v784] = v306;
  int * v468 = v303->cache_dirty;
  v468[v465] = 1;
  struct StateT * v470 = v290->b;
  int * v471 = v470->regs;
  int v472 = v471[6];
  int v473 = v471[7];
  int * v474 = v470->cache_tags;
  int v791 = (((int)((unsigned int)((int)((unsigned int)v472 >> 2)) >> 1)) & 1) * 2;
  int v475 = v474[v791];
  int v792 = ((((int)((unsigned int)((int)((unsigned int)v472 >> 2)) >> 1)) & 1) * 2) + 1;
  int v476 = v474[v792];
  int v793 = 4 + ((((int)((unsigned int)((int)((unsigned int)v472 >> 2)) >> 1)) & 3) * 2);
  int v477 = v474[v793];
  int v794 = (4 + ((((int)((unsigned int)((int)((unsigned int)v472 >> 2)) >> 1)) & 3) * 2)) + 1;
  int v478 = v474[v794];
  int v479 = v470->timer;
  int v795 = v479 + ((100 ^ (((~(((v477 ^ ((int)((unsigned int)((int)((unsigned int)v472 >> 2)) >> 1))) | (-(v477 ^ ((int)((unsigned int)((int)((unsigned int)v472 >> 2)) >> 1))))) >> 31)) | (~(((v478 ^ ((int)((unsigned int)((int)((unsigned int)v472 >> 2)) >> 1))) | (-(v478 ^ ((int)((unsigned int)((int)((unsigned int)v472 >> 2)) >> 1))))) >> 31))) & 104)) ^ (((~(((v475 ^ ((int)((unsigned int)((int)((unsigned int)v472 >> 2)) >> 1))) | (-(v475 ^ ((int)((unsigned int)((int)((unsigned int)v472 >> 2)) >> 1))))) >> 31)) | (~(((v476 ^ ((int)((unsigned int)((int)((unsigned int)v472 >> 2)) >> 1))) | (-(v476 ^ ((int)((unsigned int)((int)((unsigned int)v472 >> 2)) >> 1))))) >> 31))) & (1 ^ (100 ^ (((~(((v477 ^ ((int)((unsigned int)((int)((unsigned int)v472 >> 2)) >> 1))) | (-(v477 ^ ((int)((unsigned int)((int)((unsigned int)v472 >> 2)) >> 1))))) >> 31)) | (~(((v478 ^ ((int)((unsigned int)((int)((unsigned int)v472 >> 2)) >> 1))) | (-(v478 ^ ((int)((unsigned int)((int)((unsigned int)v472 >> 2)) >> 1))))) >> 31))) & 104)))));
  v470->timer = v795;
  bool v796 = !(((~(((v475 ^ ((int)((unsigned int)((int)((unsigned int)v472 >> 2)) >> 1))) | (-(v475 ^ ((int)((unsigned int)((int)((unsigned int)v472 >> 2)) >> 1))))) >> 31)) | (~(((v476 ^ ((int)((unsigned int)((int)((unsigned int)v472 >> 2)) >> 1))) | (-(v476 ^ ((int)((unsigned int)((int)((unsigned int)v472 >> 2)) >> 1))))) >> 31))) == 0);
  int v573;
  if (v796) {
    int * v481 = v470->cache_age;
    int v798 = ((((int)((unsigned int)((int)((unsigned int)v472 >> 2)) >> 1)) & 1) * 2) + ((~(((v476 ^ ((int)((unsigned int)((int)((unsigned int)v472 >> 2)) >> 1))) | (-(v476 ^ ((int)((unsigned int)((int)((unsigned int)v472 >> 2)) >> 1))))) >> 31)) & 1);
    int v482 = v481[v798];
    int v483 = v481[v791];
    int v799 = v483 + ((int)((unsigned int)(v483 - v482) >> 31));
    v481[v791] = v799;
    int * v485 = v470->cache_age;
    int v486 = v485[v792];
    int v801 = v486 + ((int)((unsigned int)(v486 - v482) >> 31));
    v485[v792] = v801;
    int * v488 = v470->cache_age;
    v488[v798] = 0;
    v573 = v798;
  } else {
    int * v491 = v470->cache_age;
    int v805 = (((int)((unsigned int)((int)((unsigned int)v472 >> 2)) >> 1)) & 1) * 2;
    int v492 = v491[v805];
    int * v493 = v470->cache_tags;
    int v494 = v493[v805];
    int v495 = v491[v792];
    int v496 = v493[v792];
    bool v807 = !(((~(((v477 ^ ((int)((unsigned int)((int)((unsigned int)v472 >> 2)) >> 1))) | (-(v477 ^ ((int)((unsigned int)((int)((unsigned int)v472 >> 2)) >> 1))))) >> 31)) | (~(((v478 ^ ((int)((unsigned int)((int)((unsigned int)v472 >> 2)) >> 1))) | (-(v478 ^ ((int)((unsigned int)((int)((unsigned int)v472 >> 2)) >> 1))))) >> 31))) == 0);
    int v550;
    if (v807) {
      int * v497 = v470->cache_age;
      int v809 = (4 + ((((int)((unsigned int)((int)((unsigned int)v472 >> 2)) >> 1)) & 3) * 2)) + ((~(((v478 ^ ((int)((unsigned int)((int)((unsigned int)v472 >> 2)) >> 1))) | (-(v478 ^ ((int)((unsigned int)((int)((unsigned int)v472 >> 2)) >> 1))))) >> 31)) & 1);
      int v498 = v497[v809];
      int v499 = v497[v793];
      int v810 = v499 + ((int)((unsigned int)(v499 - v498) >> 31));
      v497[v793] = v810;
      int * v501 = v470->cache_age;
      int v502 = v501[v794];
      int v812 = v502 + ((int)((unsigned int)(v502 - v498) >> 31));
      v501[v794] = v812;
      int * v504 = v470->cache_age;
      v504[v809] = 0;
      v550 = v809;
    } else {
      int * v507 = v470->cache_age;
      int v816 = 4 + ((((int)((unsigned int)((int)((unsigned int)v472 >> 2)) >> 1)) & 3) * 2);
      int v508 = v507[v816];
      int * v509 = v470->cache_tags;
      int v510 = v509[v816];
      int v511 = v507[v794];
      int v512 = v509[v794];
      int * v513 = v470->cache_dirty;
      int v819 = (4 + ((((int)((unsigned int)((int)((unsigned int)v472 >> 2)) >> 1)) & 3) * 2)) + ((((v508 + ((~(((v510 ^ -1) | (-(v510 ^ -1))) >> 31)) & 2)) - (v511 + ((~(((v512 ^ -1) | (-(v512 ^ -1))) >> 31)) & 2))) >> 31) & 1);
      int v514 = v513[v819];
      bool v820 = !(v514 == 0);
      if (v820) {
        int * v515 = v470->cache_tags;
        int v516 = v515[v819];
        int * v517 = v470->cache_vals;
        int v823 = ((4 + ((((int)((unsigned int)((int)((unsigned int)v472 >> 2)) >> 1)) & 3) * 2)) + ((((v508 + ((~(((v510 ^ -1) | (-(v510 ^ -1))) >> 31)) & 2)) - (v511 + ((~(((v512 ^ -1) | (-(v512 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
        int v518 = v517[v823];
        int v824 = (((4 + ((((int)((unsigned int)((int)((unsigned int)v472 >> 2)) >> 1)) & 3) * 2)) + ((((v508 + ((~(((v510 ^ -1) | (-(v510 ^ -1))) >> 31)) & 2)) - (v511 + ((~(((v512 ^ -1) | (-(v512 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
        int v519 = v517[v824];
        int * v520 = v470->mem;
        int v826 = v516 * 2;
        v520[v826] = v518;
        int * v522 = v470->mem;
        int v829 = (v516 * 2) + 1;
        v522[v829] = v519;
        ;
      } else {
        ;
      }
      int * v527 = v470->mem;
      int v834 = ((int)((unsigned int)((int)((unsigned int)v472 >> 2)) >> 1)) * 2;
      int v528 = v527[v834];
      int v835 = (((int)((unsigned int)((int)((unsigned int)v472 >> 2)) >> 1)) * 2) + 1;
      int v529 = v527[v835];
      int * v530 = v470->cache_vals;
      int v837 = ((4 + ((((int)((unsigned int)((int)((unsigned int)v472 >> 2)) >> 1)) & 3) * 2)) + ((((v508 + ((~(((v510 ^ -1) | (-(v510 ^ -1))) >> 31)) & 2)) - (v511 + ((~(((v512 ^ -1) | (-(v512 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
      v530[v837] = v528;
      int * v532 = v470->cache_vals;
      int v840 = (((4 + ((((int)((unsigned int)((int)((unsigned int)v472 >> 2)) >> 1)) & 3) * 2)) + ((((v508 + ((~(((v510 ^ -1) | (-(v510 ^ -1))) >> 31)) & 2)) - (v511 + ((~(((v512 ^ -1) | (-(v512 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
      v532[v840] = v529;
      int * v534 = v470->cache_tags;
      int v843 = (int)((unsigned int)((int)((unsigned int)v472 >> 2)) >> 1);
      v534[v819] = v843;
      int * v536 = v470->cache_dirty;
      v536[v819] = 0;
      int * v538 = v470->cache_age;
      v538[v819] = 1;
      int * v540 = v470->cache_age;
      int v541 = v540[v819];
      int v542 = v540[v793];
      int v848 = v542 + ((int)((unsigned int)(v542 - v541) >> 31));
      v540[v793] = v848;
      int * v544 = v470->cache_age;
      int v545 = v544[v794];
      int v850 = v545 + ((int)((unsigned int)(v545 - v541) >> 31));
      v544[v794] = v850;
      int * v547 = v470->cache_age;
      v547[v819] = 0;
      v550 = v819;
    }
    int * v551 = v470->cache_vals;
    int v853 = v550 * 2;
    int v552 = v551[v853];
    int v854 = (v550 * 2) + 1;
    int v553 = v551[v854];
    int v855 = (((((int)((unsigned int)((int)((unsigned int)v472 >> 2)) >> 1)) & 1) * 2) + ((((v492 + ((~(((v494 ^ -1) | (-(v494 ^ -1))) >> 31)) & 2)) - (v495 + ((~(((v496 ^ -1) | (-(v496 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
    v551[v855] = v552;
    int * v555 = v470->cache_vals;
    int v858 = ((((((int)((unsigned int)((int)((unsigned int)v472 >> 2)) >> 1)) & 1) * 2) + ((((v492 + ((~(((v494 ^ -1) | (-(v494 ^ -1))) >> 31)) & 2)) - (v495 + ((~(((v496 ^ -1) | (-(v496 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
    v555[v858] = v553;
    int * v557 = v470->cache_tags;
    int v861 = ((((int)((unsigned int)((int)((unsigned int)v472 >> 2)) >> 1)) & 1) * 2) + ((((v492 + ((~(((v494 ^ -1) | (-(v494 ^ -1))) >> 31)) & 2)) - (v495 + ((~(((v496 ^ -1) | (-(v496 ^ -1))) >> 31)) & 2))) >> 31) & 1);
    int v862 = (int)((unsigned int)((int)((unsigned int)v472 >> 2)) >> 1);
    v557[v861] = v862;
    int * v559 = v470->cache_dirty;
    v559[v861] = 0;
    int * v561 = v470->cache_age;
    v561[v861] = 1;
    int * v563 = v470->cache_age;
    int v564 = v563[v861];
    int v565 = v563[v791];
    int v867 = v565 + ((int)((unsigned int)(v565 - v564) >> 31));
    v563[v791] = v867;
    int * v567 = v470->cache_age;
    int v568 = v567[v792];
    int v869 = v568 + ((int)((unsigned int)(v568 - v564) >> 31));
    v567[v792] = v869;
    int * v570 = v470->cache_age;
    v570[v861] = 0;
    v573 = v861;
  }
  int * v574 = v470->cache_vals;
  int v872 = (v573 * 2) + (((int)((unsigned int)v472 >> 2)) & 1);
  v574[v872] = v473;
  int * v576 = v470->cache_tags;
  int v577 = v576[v793];
  int v578 = v576[v794];
  bool v875 = !(((~(((v577 ^ ((int)((unsigned int)((int)((unsigned int)v472 >> 2)) >> 1))) | (-(v577 ^ ((int)((unsigned int)((int)((unsigned int)v472 >> 2)) >> 1))))) >> 31)) | (~(((v578 ^ ((int)((unsigned int)((int)((unsigned int)v472 >> 2)) >> 1))) | (-(v578 ^ ((int)((unsigned int)((int)((unsigned int)v472 >> 2)) >> 1))))) >> 31))) == 0);
  int v632;
  if (v875) {
    int * v579 = v470->cache_age;
    int v877 = (4 + ((((int)((unsigned int)((int)((unsigned int)v472 >> 2)) >> 1)) & 3) * 2)) + ((~(((v578 ^ ((int)((unsigned int)((int)((unsigned int)v472 >> 2)) >> 1))) | (-(v578 ^ ((int)((unsigned int)((int)((unsigned int)v472 >> 2)) >> 1))))) >> 31)) & 1);
    int v580 = v579[v877];
    int v581 = v579[v793];
    int v878 = v581 + ((int)((unsigned int)(v581 - v580) >> 31));
    v579[v793] = v878;
    int * v583 = v470->cache_age;
    int v584 = v583[v794];
    int v880 = v584 + ((int)((unsigned int)(v584 - v580) >> 31));
    v583[v794] = v880;
    int * v586 = v470->cache_age;
    v586[v877] = 0;
    v632 = v877;
  } else {
    int * v589 = v470->cache_age;
    int v884 = 4 + ((((int)((unsigned int)((int)((unsigned int)v472 >> 2)) >> 1)) & 3) * 2);
    int v590 = v589[v884];
    int * v591 = v470->cache_tags;
    int v592 = v591[v884];
    int v593 = v589[v794];
    int v594 = v591[v794];
    int * v595 = v470->cache_dirty;
    int v887 = (4 + ((((int)((unsigned int)((int)((unsigned int)v472 >> 2)) >> 1)) & 3) * 2)) + ((((v590 + ((~(((v592 ^ -1) | (-(v592 ^ -1))) >> 31)) & 2)) - (v593 + ((~(((v594 ^ -1) | (-(v594 ^ -1))) >> 31)) & 2))) >> 31) & 1);
    int v596 = v595[v887];
    bool v888 = !(v596 == 0);
    if (v888) {
      int * v597 = v470->cache_tags;
      int v598 = v597[v887];
      int * v599 = v470->cache_vals;
      int v891 = ((4 + ((((int)((unsigned int)((int)((unsigned int)v472 >> 2)) >> 1)) & 3) * 2)) + ((((v590 + ((~(((v592 ^ -1) | (-(v592 ^ -1))) >> 31)) & 2)) - (v593 + ((~(((v594 ^ -1) | (-(v594 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
      int v600 = v599[v891];
      int v892 = (((4 + ((((int)((unsigned int)((int)((unsigned int)v472 >> 2)) >> 1)) & 3) * 2)) + ((((v590 + ((~(((v592 ^ -1) | (-(v592 ^ -1))) >> 31)) & 2)) - (v593 + ((~(((v594 ^ -1) | (-(v594 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
      int v601 = v599[v892];
      int * v602 = v470->mem;
      int v894 = v598 * 2;
      v602[v894] = v600;
      int * v604 = v470->mem;
      int v897 = (v598 * 2) + 1;
      v604[v897] = v601;
      ;
    } else {
      ;
    }
    int * v609 = v470->mem;
    int v902 = ((int)((unsigned int)((int)((unsigned int)v472 >> 2)) >> 1)) * 2;
    int v610 = v609[v902];
    int v903 = (((int)((unsigned int)((int)((unsigned int)v472 >> 2)) >> 1)) * 2) + 1;
    int v611 = v609[v903];
    int * v612 = v470->cache_vals;
    int v905 = ((4 + ((((int)((unsigned int)((int)((unsigned int)v472 >> 2)) >> 1)) & 3) * 2)) + ((((v590 + ((~(((v592 ^ -1) | (-(v592 ^ -1))) >> 31)) & 2)) - (v593 + ((~(((v594 ^ -1) | (-(v594 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
    v612[v905] = v610;
    int * v614 = v470->cache_vals;
    int v908 = (((4 + ((((int)((unsigned int)((int)((unsigned int)v472 >> 2)) >> 1)) & 3) * 2)) + ((((v590 + ((~(((v592 ^ -1) | (-(v592 ^ -1))) >> 31)) & 2)) - (v593 + ((~(((v594 ^ -1) | (-(v594 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
    v614[v908] = v611;
    int * v616 = v470->cache_tags;
    int v911 = (int)((unsigned int)((int)((unsigned int)v472 >> 2)) >> 1);
    v616[v887] = v911;
    int * v618 = v470->cache_dirty;
    v618[v887] = 0;
    int * v620 = v470->cache_age;
    v620[v887] = 1;
    int * v622 = v470->cache_age;
    int v623 = v622[v887];
    int v624 = v622[v793];
    int v916 = v624 + ((int)((unsigned int)(v624 - v623) >> 31));
    v622[v793] = v916;
    int * v626 = v470->cache_age;
    int v627 = v626[v794];
    int v918 = v627 + ((int)((unsigned int)(v627 - v623) >> 31));
    v626[v794] = v918;
    int * v629 = v470->cache_age;
    v629[v887] = 0;
    v632 = v887;
  }
  int * v633 = v470->cache_vals;
  int v921 = (v632 * 2) + (((int)((unsigned int)v472 >> 2)) & 1);
  v633[v921] = v473;
  int * v635 = v470->cache_dirty;
  v635[v632] = 1;
  struct StateT2 * v637 = slot_8(v290);
  return v637;
}

struct StateT2 * slot_3(struct StateT2 * v102) {
  struct StateT * v103 = v102->a;
  int v104 = v103->timer;
  struct StateT * v105 = v102->b;
  int v106 = v105->timer;
  bool v137 = v104 == v106;
  squared_assert(v137);
  squared_assume(v137);
  struct StateT * v109 = v102->a;
  int * v110 = v109->saved_regs;
  int * v111 = v109->regs;
  int v112 = v111[6];
  v110[6] = v112;
  struct StateT * v114 = v102->b;
  int * v115 = v114->saved_regs;
  int * v116 = v114->regs;
  int v117 = v116[6];
  v115[6] = v117;
  struct StateT * v119 = v102->a;
  int v120 = v119->timer;
  int v148 = v120 + 1;
  v119->timer = v148;
  struct StateT * v122 = v102->b;
  int v123 = v122->timer;
  int v150 = v123 + 1;
  v122->timer = v150;
  struct StateT * v125 = v102->a;
  int * v126 = v125->regs;
  int v127 = v126[5];
  int v154 = v127 + 80;
  v126[6] = v154;
  struct StateT * v129 = v102->b;
  int * v130 = v129->regs;
  int v131 = v130[5];
  int v157 = v131 + 80;
  v130[6] = v157;
  struct StateT2 * v133 = slot_4(v102);
  return v133;
}

struct StateT2 * snippet(struct StateT2 * v0) {
  struct StateT2 * v1 = slot_0(v0);
  return v1;
}

struct StateT2 * slot_10(struct StateT2 * v1383) {
  struct StateT * v1384 = v1383->a;
  int v1385 = v1384->timer;
  struct StateT * v1386 = v1383->b;
  int v1387 = v1386->timer;
  bool v1613 = v1385 == v1387;
  squared_assert(v1613);
  squared_assume(v1613);
  struct StateT * v1390 = v1383->a;
  int v1391 = v1390->timer;
  int v1615 = v1391 + 1;
  v1390->timer = v1615;
  struct StateT * v1393 = v1383->b;
  int v1394 = v1393->timer;
  int v1617 = v1394 + 1;
  v1393->timer = v1617;
  struct StateT * v1396 = v1383->a;
  int * v1397 = v1396->regs;
  int v1398 = v1397[11];
  int * v1399 = v1396->cache_tags;
  int v1622 = (((int)((unsigned int)((int)((unsigned int)v1398 >> 2)) >> 1)) & 1) * 2;
  int v1400 = v1399[v1622];
  int v1623 = ((((int)((unsigned int)((int)((unsigned int)v1398 >> 2)) >> 1)) & 1) * 2) + 1;
  int v1401 = v1399[v1623];
  int v1624 = 4 + ((((int)((unsigned int)((int)((unsigned int)v1398 >> 2)) >> 1)) & 3) * 2);
  int v1402 = v1399[v1624];
  int v1625 = (4 + ((((int)((unsigned int)((int)((unsigned int)v1398 >> 2)) >> 1)) & 3) * 2)) + 1;
  int v1403 = v1399[v1625];
  int v1404 = v1396->timer;
  int v1626 = v1404 + ((100 ^ (((~(((v1402 ^ ((int)((unsigned int)((int)((unsigned int)v1398 >> 2)) >> 1))) | (-(v1402 ^ ((int)((unsigned int)((int)((unsigned int)v1398 >> 2)) >> 1))))) >> 31)) | (~(((v1403 ^ ((int)((unsigned int)((int)((unsigned int)v1398 >> 2)) >> 1))) | (-(v1403 ^ ((int)((unsigned int)((int)((unsigned int)v1398 >> 2)) >> 1))))) >> 31))) & 104)) ^ (((~(((v1400 ^ ((int)((unsigned int)((int)((unsigned int)v1398 >> 2)) >> 1))) | (-(v1400 ^ ((int)((unsigned int)((int)((unsigned int)v1398 >> 2)) >> 1))))) >> 31)) | (~(((v1401 ^ ((int)((unsigned int)((int)((unsigned int)v1398 >> 2)) >> 1))) | (-(v1401 ^ ((int)((unsigned int)((int)((unsigned int)v1398 >> 2)) >> 1))))) >> 31))) & (1 ^ (100 ^ (((~(((v1402 ^ ((int)((unsigned int)((int)((unsigned int)v1398 >> 2)) >> 1))) | (-(v1402 ^ ((int)((unsigned int)((int)((unsigned int)v1398 >> 2)) >> 1))))) >> 31)) | (~(((v1403 ^ ((int)((unsigned int)((int)((unsigned int)v1398 >> 2)) >> 1))) | (-(v1403 ^ ((int)((unsigned int)((int)((unsigned int)v1398 >> 2)) >> 1))))) >> 31))) & 104)))));
  v1396->timer = v1626;
  int * v1406 = v1396->cache_vals;
  bool v1627 = !(((~(((v1400 ^ ((int)((unsigned int)((int)((unsigned int)v1398 >> 2)) >> 1))) | (-(v1400 ^ ((int)((unsigned int)((int)((unsigned int)v1398 >> 2)) >> 1))))) >> 31)) | (~(((v1401 ^ ((int)((unsigned int)((int)((unsigned int)v1398 >> 2)) >> 1))) | (-(v1401 ^ ((int)((unsigned int)((int)((unsigned int)v1398 >> 2)) >> 1))))) >> 31))) == 0);
  int v1499;
  if (v1627) {
    int * v1407 = v1396->cache_age;
    int v1629 = ((((int)((unsigned int)((int)((unsigned int)v1398 >> 2)) >> 1)) & 1) * 2) + ((~(((v1401 ^ ((int)((unsigned int)((int)((unsigned int)v1398 >> 2)) >> 1))) | (-(v1401 ^ ((int)((unsigned int)((int)((unsigned int)v1398 >> 2)) >> 1))))) >> 31)) & 1);
    int v1408 = v1407[v1629];
    int v1409 = v1407[v1622];
    int v1630 = v1409 + ((int)((unsigned int)(v1409 - v1408) >> 31));
    v1407[v1622] = v1630;
    int * v1411 = v1396->cache_age;
    int v1412 = v1411[v1623];
    int v1632 = v1412 + ((int)((unsigned int)(v1412 - v1408) >> 31));
    v1411[v1623] = v1632;
    int * v1414 = v1396->cache_age;
    v1414[v1629] = 0;
    v1499 = v1629;
  } else {
    int * v1417 = v1396->cache_age;
    int v1636 = (((int)((unsigned int)((int)((unsigned int)v1398 >> 2)) >> 1)) & 1) * 2;
    int v1418 = v1417[v1636];
    int * v1419 = v1396->cache_tags;
    int v1420 = v1419[v1636];
    int v1421 = v1417[v1623];
    int v1422 = v1419[v1623];
    bool v1638 = !(((~(((v1402 ^ ((int)((unsigned int)((int)((unsigned int)v1398 >> 2)) >> 1))) | (-(v1402 ^ ((int)((unsigned int)((int)((unsigned int)v1398 >> 2)) >> 1))))) >> 31)) | (~(((v1403 ^ ((int)((unsigned int)((int)((unsigned int)v1398 >> 2)) >> 1))) | (-(v1403 ^ ((int)((unsigned int)((int)((unsigned int)v1398 >> 2)) >> 1))))) >> 31))) == 0);
    int v1476;
    if (v1638) {
      int * v1423 = v1396->cache_age;
      int v1640 = (4 + ((((int)((unsigned int)((int)((unsigned int)v1398 >> 2)) >> 1)) & 3) * 2)) + ((~(((v1403 ^ ((int)((unsigned int)((int)((unsigned int)v1398 >> 2)) >> 1))) | (-(v1403 ^ ((int)((unsigned int)((int)((unsigned int)v1398 >> 2)) >> 1))))) >> 31)) & 1);
      int v1424 = v1423[v1640];
      int v1425 = v1423[v1624];
      int v1641 = v1425 + ((int)((unsigned int)(v1425 - v1424) >> 31));
      v1423[v1624] = v1641;
      int * v1427 = v1396->cache_age;
      int v1428 = v1427[v1625];
      int v1643 = v1428 + ((int)((unsigned int)(v1428 - v1424) >> 31));
      v1427[v1625] = v1643;
      int * v1430 = v1396->cache_age;
      v1430[v1640] = 0;
      v1476 = v1640;
    } else {
      int * v1433 = v1396->cache_age;
      int v1647 = 4 + ((((int)((unsigned int)((int)((unsigned int)v1398 >> 2)) >> 1)) & 3) * 2);
      int v1434 = v1433[v1647];
      int * v1435 = v1396->cache_tags;
      int v1436 = v1435[v1647];
      int v1437 = v1433[v1625];
      int v1438 = v1435[v1625];
      int * v1439 = v1396->cache_dirty;
      int v1650 = (4 + ((((int)((unsigned int)((int)((unsigned int)v1398 >> 2)) >> 1)) & 3) * 2)) + ((((v1434 + ((~(((v1436 ^ -1) | (-(v1436 ^ -1))) >> 31)) & 2)) - (v1437 + ((~(((v1438 ^ -1) | (-(v1438 ^ -1))) >> 31)) & 2))) >> 31) & 1);
      int v1440 = v1439[v1650];
      bool v1651 = !(v1440 == 0);
      if (v1651) {
        int * v1441 = v1396->cache_tags;
        int v1442 = v1441[v1650];
        int * v1443 = v1396->cache_vals;
        int v1654 = ((4 + ((((int)((unsigned int)((int)((unsigned int)v1398 >> 2)) >> 1)) & 3) * 2)) + ((((v1434 + ((~(((v1436 ^ -1) | (-(v1436 ^ -1))) >> 31)) & 2)) - (v1437 + ((~(((v1438 ^ -1) | (-(v1438 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
        int v1444 = v1443[v1654];
        int v1655 = (((4 + ((((int)((unsigned int)((int)((unsigned int)v1398 >> 2)) >> 1)) & 3) * 2)) + ((((v1434 + ((~(((v1436 ^ -1) | (-(v1436 ^ -1))) >> 31)) & 2)) - (v1437 + ((~(((v1438 ^ -1) | (-(v1438 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
        int v1445 = v1443[v1655];
        int * v1446 = v1396->mem;
        int v1657 = v1442 * 2;
        v1446[v1657] = v1444;
        int * v1448 = v1396->mem;
        int v1660 = (v1442 * 2) + 1;
        v1448[v1660] = v1445;
        ;
      } else {
        ;
      }
      int * v1453 = v1396->mem;
      int v1665 = ((int)((unsigned int)((int)((unsigned int)v1398 >> 2)) >> 1)) * 2;
      int v1454 = v1453[v1665];
      int v1666 = (((int)((unsigned int)((int)((unsigned int)v1398 >> 2)) >> 1)) * 2) + 1;
      int v1455 = v1453[v1666];
      int * v1456 = v1396->cache_vals;
      int v1668 = ((4 + ((((int)((unsigned int)((int)((unsigned int)v1398 >> 2)) >> 1)) & 3) * 2)) + ((((v1434 + ((~(((v1436 ^ -1) | (-(v1436 ^ -1))) >> 31)) & 2)) - (v1437 + ((~(((v1438 ^ -1) | (-(v1438 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
      v1456[v1668] = v1454;
      int * v1458 = v1396->cache_vals;
      int v1671 = (((4 + ((((int)((unsigned int)((int)((unsigned int)v1398 >> 2)) >> 1)) & 3) * 2)) + ((((v1434 + ((~(((v1436 ^ -1) | (-(v1436 ^ -1))) >> 31)) & 2)) - (v1437 + ((~(((v1438 ^ -1) | (-(v1438 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
      v1458[v1671] = v1455;
      int * v1460 = v1396->cache_tags;
      int v1674 = (int)((unsigned int)((int)((unsigned int)v1398 >> 2)) >> 1);
      v1460[v1650] = v1674;
      int * v1462 = v1396->cache_dirty;
      v1462[v1650] = 0;
      int * v1464 = v1396->cache_age;
      v1464[v1650] = 1;
      int * v1466 = v1396->cache_age;
      int v1467 = v1466[v1650];
      int v1468 = v1466[v1624];
      int v1680 = v1468 + ((int)((unsigned int)(v1468 - v1467) >> 31));
      v1466[v1624] = v1680;
      int * v1470 = v1396->cache_age;
      int v1471 = v1470[v1625];
      int v1682 = v1471 + ((int)((unsigned int)(v1471 - v1467) >> 31));
      v1470[v1625] = v1682;
      int * v1473 = v1396->cache_age;
      v1473[v1650] = 0;
      v1476 = v1650;
    }
    int * v1477 = v1396->cache_vals;
    int v1685 = v1476 * 2;
    int v1478 = v1477[v1685];
    int v1686 = (v1476 * 2) + 1;
    int v1479 = v1477[v1686];
    int v1687 = (((((int)((unsigned int)((int)((unsigned int)v1398 >> 2)) >> 1)) & 1) * 2) + ((((v1418 + ((~(((v1420 ^ -1) | (-(v1420 ^ -1))) >> 31)) & 2)) - (v1421 + ((~(((v1422 ^ -1) | (-(v1422 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
    v1477[v1687] = v1478;
    int * v1481 = v1396->cache_vals;
    int v1690 = ((((((int)((unsigned int)((int)((unsigned int)v1398 >> 2)) >> 1)) & 1) * 2) + ((((v1418 + ((~(((v1420 ^ -1) | (-(v1420 ^ -1))) >> 31)) & 2)) - (v1421 + ((~(((v1422 ^ -1) | (-(v1422 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
    v1481[v1690] = v1479;
    int * v1483 = v1396->cache_tags;
    int v1693 = ((((int)((unsigned int)((int)((unsigned int)v1398 >> 2)) >> 1)) & 1) * 2) + ((((v1418 + ((~(((v1420 ^ -1) | (-(v1420 ^ -1))) >> 31)) & 2)) - (v1421 + ((~(((v1422 ^ -1) | (-(v1422 ^ -1))) >> 31)) & 2))) >> 31) & 1);
    int v1694 = (int)((unsigned int)((int)((unsigned int)v1398 >> 2)) >> 1);
    v1483[v1693] = v1694;
    int * v1485 = v1396->cache_dirty;
    v1485[v1693] = 0;
    int * v1487 = v1396->cache_age;
    v1487[v1693] = 1;
    int * v1489 = v1396->cache_age;
    int v1490 = v1489[v1693];
    int v1491 = v1489[v1622];
    int v1700 = v1491 + ((int)((unsigned int)(v1491 - v1490) >> 31));
    v1489[v1622] = v1700;
    int * v1493 = v1396->cache_age;
    int v1494 = v1493[v1623];
    int v1702 = v1494 + ((int)((unsigned int)(v1494 - v1490) >> 31));
    v1493[v1623] = v1702;
    int * v1496 = v1396->cache_age;
    v1496[v1693] = 0;
    v1499 = v1693;
  }
  int v1705 = (v1499 * 2) + (((int)((unsigned int)v1398 >> 2)) & 1);
  int v1500 = v1406[v1705];
  int * v1501 = v1396->regs;
  v1501[12] = v1500;
  struct StateT * v1503 = v1383->b;
  int * v1504 = v1503->regs;
  int v1505 = v1504[11];
  int * v1506 = v1503->cache_tags;
  int v1712 = (((int)((unsigned int)((int)((unsigned int)v1505 >> 2)) >> 1)) & 1) * 2;
  int v1507 = v1506[v1712];
  int v1713 = ((((int)((unsigned int)((int)((unsigned int)v1505 >> 2)) >> 1)) & 1) * 2) + 1;
  int v1508 = v1506[v1713];
  int v1714 = 4 + ((((int)((unsigned int)((int)((unsigned int)v1505 >> 2)) >> 1)) & 3) * 2);
  int v1509 = v1506[v1714];
  int v1715 = (4 + ((((int)((unsigned int)((int)((unsigned int)v1505 >> 2)) >> 1)) & 3) * 2)) + 1;
  int v1510 = v1506[v1715];
  int v1511 = v1503->timer;
  int v1716 = v1511 + ((100 ^ (((~(((v1509 ^ ((int)((unsigned int)((int)((unsigned int)v1505 >> 2)) >> 1))) | (-(v1509 ^ ((int)((unsigned int)((int)((unsigned int)v1505 >> 2)) >> 1))))) >> 31)) | (~(((v1510 ^ ((int)((unsigned int)((int)((unsigned int)v1505 >> 2)) >> 1))) | (-(v1510 ^ ((int)((unsigned int)((int)((unsigned int)v1505 >> 2)) >> 1))))) >> 31))) & 104)) ^ (((~(((v1507 ^ ((int)((unsigned int)((int)((unsigned int)v1505 >> 2)) >> 1))) | (-(v1507 ^ ((int)((unsigned int)((int)((unsigned int)v1505 >> 2)) >> 1))))) >> 31)) | (~(((v1508 ^ ((int)((unsigned int)((int)((unsigned int)v1505 >> 2)) >> 1))) | (-(v1508 ^ ((int)((unsigned int)((int)((unsigned int)v1505 >> 2)) >> 1))))) >> 31))) & (1 ^ (100 ^ (((~(((v1509 ^ ((int)((unsigned int)((int)((unsigned int)v1505 >> 2)) >> 1))) | (-(v1509 ^ ((int)((unsigned int)((int)((unsigned int)v1505 >> 2)) >> 1))))) >> 31)) | (~(((v1510 ^ ((int)((unsigned int)((int)((unsigned int)v1505 >> 2)) >> 1))) | (-(v1510 ^ ((int)((unsigned int)((int)((unsigned int)v1505 >> 2)) >> 1))))) >> 31))) & 104)))));
  v1503->timer = v1716;
  int * v1513 = v1503->cache_vals;
  bool v1717 = !(((~(((v1507 ^ ((int)((unsigned int)((int)((unsigned int)v1505 >> 2)) >> 1))) | (-(v1507 ^ ((int)((unsigned int)((int)((unsigned int)v1505 >> 2)) >> 1))))) >> 31)) | (~(((v1508 ^ ((int)((unsigned int)((int)((unsigned int)v1505 >> 2)) >> 1))) | (-(v1508 ^ ((int)((unsigned int)((int)((unsigned int)v1505 >> 2)) >> 1))))) >> 31))) == 0);
  int v1606;
  if (v1717) {
    int * v1514 = v1503->cache_age;
    int v1719 = ((((int)((unsigned int)((int)((unsigned int)v1505 >> 2)) >> 1)) & 1) * 2) + ((~(((v1508 ^ ((int)((unsigned int)((int)((unsigned int)v1505 >> 2)) >> 1))) | (-(v1508 ^ ((int)((unsigned int)((int)((unsigned int)v1505 >> 2)) >> 1))))) >> 31)) & 1);
    int v1515 = v1514[v1719];
    int v1516 = v1514[v1712];
    int v1720 = v1516 + ((int)((unsigned int)(v1516 - v1515) >> 31));
    v1514[v1712] = v1720;
    int * v1518 = v1503->cache_age;
    int v1519 = v1518[v1713];
    int v1722 = v1519 + ((int)((unsigned int)(v1519 - v1515) >> 31));
    v1518[v1713] = v1722;
    int * v1521 = v1503->cache_age;
    v1521[v1719] = 0;
    v1606 = v1719;
  } else {
    int * v1524 = v1503->cache_age;
    int v1726 = (((int)((unsigned int)((int)((unsigned int)v1505 >> 2)) >> 1)) & 1) * 2;
    int v1525 = v1524[v1726];
    int * v1526 = v1503->cache_tags;
    int v1527 = v1526[v1726];
    int v1528 = v1524[v1713];
    int v1529 = v1526[v1713];
    bool v1728 = !(((~(((v1509 ^ ((int)((unsigned int)((int)((unsigned int)v1505 >> 2)) >> 1))) | (-(v1509 ^ ((int)((unsigned int)((int)((unsigned int)v1505 >> 2)) >> 1))))) >> 31)) | (~(((v1510 ^ ((int)((unsigned int)((int)((unsigned int)v1505 >> 2)) >> 1))) | (-(v1510 ^ ((int)((unsigned int)((int)((unsigned int)v1505 >> 2)) >> 1))))) >> 31))) == 0);
    int v1583;
    if (v1728) {
      int * v1530 = v1503->cache_age;
      int v1730 = (4 + ((((int)((unsigned int)((int)((unsigned int)v1505 >> 2)) >> 1)) & 3) * 2)) + ((~(((v1510 ^ ((int)((unsigned int)((int)((unsigned int)v1505 >> 2)) >> 1))) | (-(v1510 ^ ((int)((unsigned int)((int)((unsigned int)v1505 >> 2)) >> 1))))) >> 31)) & 1);
      int v1531 = v1530[v1730];
      int v1532 = v1530[v1714];
      int v1731 = v1532 + ((int)((unsigned int)(v1532 - v1531) >> 31));
      v1530[v1714] = v1731;
      int * v1534 = v1503->cache_age;
      int v1535 = v1534[v1715];
      int v1733 = v1535 + ((int)((unsigned int)(v1535 - v1531) >> 31));
      v1534[v1715] = v1733;
      int * v1537 = v1503->cache_age;
      v1537[v1730] = 0;
      v1583 = v1730;
    } else {
      int * v1540 = v1503->cache_age;
      int v1737 = 4 + ((((int)((unsigned int)((int)((unsigned int)v1505 >> 2)) >> 1)) & 3) * 2);
      int v1541 = v1540[v1737];
      int * v1542 = v1503->cache_tags;
      int v1543 = v1542[v1737];
      int v1544 = v1540[v1715];
      int v1545 = v1542[v1715];
      int * v1546 = v1503->cache_dirty;
      int v1740 = (4 + ((((int)((unsigned int)((int)((unsigned int)v1505 >> 2)) >> 1)) & 3) * 2)) + ((((v1541 + ((~(((v1543 ^ -1) | (-(v1543 ^ -1))) >> 31)) & 2)) - (v1544 + ((~(((v1545 ^ -1) | (-(v1545 ^ -1))) >> 31)) & 2))) >> 31) & 1);
      int v1547 = v1546[v1740];
      bool v1741 = !(v1547 == 0);
      if (v1741) {
        int * v1548 = v1503->cache_tags;
        int v1549 = v1548[v1740];
        int * v1550 = v1503->cache_vals;
        int v1744 = ((4 + ((((int)((unsigned int)((int)((unsigned int)v1505 >> 2)) >> 1)) & 3) * 2)) + ((((v1541 + ((~(((v1543 ^ -1) | (-(v1543 ^ -1))) >> 31)) & 2)) - (v1544 + ((~(((v1545 ^ -1) | (-(v1545 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
        int v1551 = v1550[v1744];
        int v1745 = (((4 + ((((int)((unsigned int)((int)((unsigned int)v1505 >> 2)) >> 1)) & 3) * 2)) + ((((v1541 + ((~(((v1543 ^ -1) | (-(v1543 ^ -1))) >> 31)) & 2)) - (v1544 + ((~(((v1545 ^ -1) | (-(v1545 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
        int v1552 = v1550[v1745];
        int * v1553 = v1503->mem;
        int v1747 = v1549 * 2;
        v1553[v1747] = v1551;
        int * v1555 = v1503->mem;
        int v1750 = (v1549 * 2) + 1;
        v1555[v1750] = v1552;
        ;
      } else {
        ;
      }
      int * v1560 = v1503->mem;
      int v1755 = ((int)((unsigned int)((int)((unsigned int)v1505 >> 2)) >> 1)) * 2;
      int v1561 = v1560[v1755];
      int v1756 = (((int)((unsigned int)((int)((unsigned int)v1505 >> 2)) >> 1)) * 2) + 1;
      int v1562 = v1560[v1756];
      int * v1563 = v1503->cache_vals;
      int v1758 = ((4 + ((((int)((unsigned int)((int)((unsigned int)v1505 >> 2)) >> 1)) & 3) * 2)) + ((((v1541 + ((~(((v1543 ^ -1) | (-(v1543 ^ -1))) >> 31)) & 2)) - (v1544 + ((~(((v1545 ^ -1) | (-(v1545 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
      v1563[v1758] = v1561;
      int * v1565 = v1503->cache_vals;
      int v1761 = (((4 + ((((int)((unsigned int)((int)((unsigned int)v1505 >> 2)) >> 1)) & 3) * 2)) + ((((v1541 + ((~(((v1543 ^ -1) | (-(v1543 ^ -1))) >> 31)) & 2)) - (v1544 + ((~(((v1545 ^ -1) | (-(v1545 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
      v1565[v1761] = v1562;
      int * v1567 = v1503->cache_tags;
      int v1764 = (int)((unsigned int)((int)((unsigned int)v1505 >> 2)) >> 1);
      v1567[v1740] = v1764;
      int * v1569 = v1503->cache_dirty;
      v1569[v1740] = 0;
      int * v1571 = v1503->cache_age;
      v1571[v1740] = 1;
      int * v1573 = v1503->cache_age;
      int v1574 = v1573[v1740];
      int v1575 = v1573[v1714];
      int v1770 = v1575 + ((int)((unsigned int)(v1575 - v1574) >> 31));
      v1573[v1714] = v1770;
      int * v1577 = v1503->cache_age;
      int v1578 = v1577[v1715];
      int v1772 = v1578 + ((int)((unsigned int)(v1578 - v1574) >> 31));
      v1577[v1715] = v1772;
      int * v1580 = v1503->cache_age;
      v1580[v1740] = 0;
      v1583 = v1740;
    }
    int * v1584 = v1503->cache_vals;
    int v1775 = v1583 * 2;
    int v1585 = v1584[v1775];
    int v1776 = (v1583 * 2) + 1;
    int v1586 = v1584[v1776];
    int v1777 = (((((int)((unsigned int)((int)((unsigned int)v1505 >> 2)) >> 1)) & 1) * 2) + ((((v1525 + ((~(((v1527 ^ -1) | (-(v1527 ^ -1))) >> 31)) & 2)) - (v1528 + ((~(((v1529 ^ -1) | (-(v1529 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
    v1584[v1777] = v1585;
    int * v1588 = v1503->cache_vals;
    int v1780 = ((((((int)((unsigned int)((int)((unsigned int)v1505 >> 2)) >> 1)) & 1) * 2) + ((((v1525 + ((~(((v1527 ^ -1) | (-(v1527 ^ -1))) >> 31)) & 2)) - (v1528 + ((~(((v1529 ^ -1) | (-(v1529 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
    v1588[v1780] = v1586;
    int * v1590 = v1503->cache_tags;
    int v1783 = ((((int)((unsigned int)((int)((unsigned int)v1505 >> 2)) >> 1)) & 1) * 2) + ((((v1525 + ((~(((v1527 ^ -1) | (-(v1527 ^ -1))) >> 31)) & 2)) - (v1528 + ((~(((v1529 ^ -1) | (-(v1529 ^ -1))) >> 31)) & 2))) >> 31) & 1);
    int v1784 = (int)((unsigned int)((int)((unsigned int)v1505 >> 2)) >> 1);
    v1590[v1783] = v1784;
    int * v1592 = v1503->cache_dirty;
    v1592[v1783] = 0;
    int * v1594 = v1503->cache_age;
    v1594[v1783] = 1;
    int * v1596 = v1503->cache_age;
    int v1597 = v1596[v1783];
    int v1598 = v1596[v1712];
    int v1790 = v1598 + ((int)((unsigned int)(v1598 - v1597) >> 31));
    v1596[v1712] = v1790;
    int * v1600 = v1503->cache_age;
    int v1601 = v1600[v1713];
    int v1792 = v1601 + ((int)((unsigned int)(v1601 - v1597) >> 31));
    v1600[v1713] = v1792;
    int * v1603 = v1503->cache_age;
    v1603[v1783] = 0;
    v1606 = v1783;
  }
  int v1795 = (v1606 * 2) + (((int)((unsigned int)v1505 >> 2)) & 1);
  int v1607 = v1513[v1795];
  int * v1608 = v1503->regs;
  v1608[12] = v1607;
  return v1383;
}

struct StateT2 * slot_1(struct StateT2 * v42) {
  struct StateT * v43 = v42->a;
  int v44 = v43->timer;
  struct StateT * v45 = v42->b;
  int v46 = v45->timer;
  bool v65 = v44 == v46;
  squared_assert(v65);
  squared_assume(v65);
  struct StateT * v49 = v42->a;
  int v50 = v49->timer;
  int v67 = v50 + 1;
  v49->timer = v67;
  struct StateT * v52 = v42->b;
  int v53 = v52->timer;
  int v69 = v53 + 1;
  v52->timer = v69;
  struct StateT * v55 = v42->a;
  int * v56 = v55->regs;
  v56[9] = 32;
  struct StateT * v58 = v42->b;
  int * v59 = v58->regs;
  v59[9] = 32;
  struct StateT2 * v61 = slot_2(v42);
  return v61;
}

struct StateT2 * slot_8(struct StateT2 * v926) {
  struct StateT * v927 = v926->a;
  int v928 = v927->timer;
  struct StateT * v929 = v926->b;
  int v930 = v929->timer;
  bool v1157 = v928 == v930;
  squared_assert(v1157);
  squared_assume(v1157);
  struct StateT * v933 = v926->a;
  int v934 = v933->timer;
  int v1159 = v934 + 1;
  v933->timer = v1159;
  struct StateT * v936 = v926->b;
  int v937 = v936->timer;
  int v1161 = v937 + 1;
  v936->timer = v1161;
  struct StateT * v939 = v926->a;
  int * v940 = v939->regs;
  int v941 = v940[6];
  int * v942 = v939->cache_tags;
  int v1166 = (((int)((unsigned int)((int)((unsigned int)v941 >> 2)) >> 1)) & 1) * 2;
  int v943 = v942[v1166];
  int v1167 = ((((int)((unsigned int)((int)((unsigned int)v941 >> 2)) >> 1)) & 1) * 2) + 1;
  int v944 = v942[v1167];
  int v1168 = 4 + ((((int)((unsigned int)((int)((unsigned int)v941 >> 2)) >> 1)) & 3) * 2);
  int v945 = v942[v1168];
  int v1169 = (4 + ((((int)((unsigned int)((int)((unsigned int)v941 >> 2)) >> 1)) & 3) * 2)) + 1;
  int v946 = v942[v1169];
  int v947 = v939->timer;
  int v1170 = v947 + ((100 ^ (((~(((v945 ^ ((int)((unsigned int)((int)((unsigned int)v941 >> 2)) >> 1))) | (-(v945 ^ ((int)((unsigned int)((int)((unsigned int)v941 >> 2)) >> 1))))) >> 31)) | (~(((v946 ^ ((int)((unsigned int)((int)((unsigned int)v941 >> 2)) >> 1))) | (-(v946 ^ ((int)((unsigned int)((int)((unsigned int)v941 >> 2)) >> 1))))) >> 31))) & 104)) ^ (((~(((v943 ^ ((int)((unsigned int)((int)((unsigned int)v941 >> 2)) >> 1))) | (-(v943 ^ ((int)((unsigned int)((int)((unsigned int)v941 >> 2)) >> 1))))) >> 31)) | (~(((v944 ^ ((int)((unsigned int)((int)((unsigned int)v941 >> 2)) >> 1))) | (-(v944 ^ ((int)((unsigned int)((int)((unsigned int)v941 >> 2)) >> 1))))) >> 31))) & (1 ^ (100 ^ (((~(((v945 ^ ((int)((unsigned int)((int)((unsigned int)v941 >> 2)) >> 1))) | (-(v945 ^ ((int)((unsigned int)((int)((unsigned int)v941 >> 2)) >> 1))))) >> 31)) | (~(((v946 ^ ((int)((unsigned int)((int)((unsigned int)v941 >> 2)) >> 1))) | (-(v946 ^ ((int)((unsigned int)((int)((unsigned int)v941 >> 2)) >> 1))))) >> 31))) & 104)))));
  v939->timer = v1170;
  int * v949 = v939->cache_vals;
  bool v1171 = !(((~(((v943 ^ ((int)((unsigned int)((int)((unsigned int)v941 >> 2)) >> 1))) | (-(v943 ^ ((int)((unsigned int)((int)((unsigned int)v941 >> 2)) >> 1))))) >> 31)) | (~(((v944 ^ ((int)((unsigned int)((int)((unsigned int)v941 >> 2)) >> 1))) | (-(v944 ^ ((int)((unsigned int)((int)((unsigned int)v941 >> 2)) >> 1))))) >> 31))) == 0);
  int v1042;
  if (v1171) {
    int * v950 = v939->cache_age;
    int v1173 = ((((int)((unsigned int)((int)((unsigned int)v941 >> 2)) >> 1)) & 1) * 2) + ((~(((v944 ^ ((int)((unsigned int)((int)((unsigned int)v941 >> 2)) >> 1))) | (-(v944 ^ ((int)((unsigned int)((int)((unsigned int)v941 >> 2)) >> 1))))) >> 31)) & 1);
    int v951 = v950[v1173];
    int v952 = v950[v1166];
    int v1174 = v952 + ((int)((unsigned int)(v952 - v951) >> 31));
    v950[v1166] = v1174;
    int * v954 = v939->cache_age;
    int v955 = v954[v1167];
    int v1176 = v955 + ((int)((unsigned int)(v955 - v951) >> 31));
    v954[v1167] = v1176;
    int * v957 = v939->cache_age;
    v957[v1173] = 0;
    v1042 = v1173;
  } else {
    int * v960 = v939->cache_age;
    int v1180 = (((int)((unsigned int)((int)((unsigned int)v941 >> 2)) >> 1)) & 1) * 2;
    int v961 = v960[v1180];
    int * v962 = v939->cache_tags;
    int v963 = v962[v1180];
    int v964 = v960[v1167];
    int v965 = v962[v1167];
    bool v1182 = !(((~(((v945 ^ ((int)((unsigned int)((int)((unsigned int)v941 >> 2)) >> 1))) | (-(v945 ^ ((int)((unsigned int)((int)((unsigned int)v941 >> 2)) >> 1))))) >> 31)) | (~(((v946 ^ ((int)((unsigned int)((int)((unsigned int)v941 >> 2)) >> 1))) | (-(v946 ^ ((int)((unsigned int)((int)((unsigned int)v941 >> 2)) >> 1))))) >> 31))) == 0);
    int v1019;
    if (v1182) {
      int * v966 = v939->cache_age;
      int v1184 = (4 + ((((int)((unsigned int)((int)((unsigned int)v941 >> 2)) >> 1)) & 3) * 2)) + ((~(((v946 ^ ((int)((unsigned int)((int)((unsigned int)v941 >> 2)) >> 1))) | (-(v946 ^ ((int)((unsigned int)((int)((unsigned int)v941 >> 2)) >> 1))))) >> 31)) & 1);
      int v967 = v966[v1184];
      int v968 = v966[v1168];
      int v1185 = v968 + ((int)((unsigned int)(v968 - v967) >> 31));
      v966[v1168] = v1185;
      int * v970 = v939->cache_age;
      int v971 = v970[v1169];
      int v1187 = v971 + ((int)((unsigned int)(v971 - v967) >> 31));
      v970[v1169] = v1187;
      int * v973 = v939->cache_age;
      v973[v1184] = 0;
      v1019 = v1184;
    } else {
      int * v976 = v939->cache_age;
      int v1191 = 4 + ((((int)((unsigned int)((int)((unsigned int)v941 >> 2)) >> 1)) & 3) * 2);
      int v977 = v976[v1191];
      int * v978 = v939->cache_tags;
      int v979 = v978[v1191];
      int v980 = v976[v1169];
      int v981 = v978[v1169];
      int * v982 = v939->cache_dirty;
      int v1194 = (4 + ((((int)((unsigned int)((int)((unsigned int)v941 >> 2)) >> 1)) & 3) * 2)) + ((((v977 + ((~(((v979 ^ -1) | (-(v979 ^ -1))) >> 31)) & 2)) - (v980 + ((~(((v981 ^ -1) | (-(v981 ^ -1))) >> 31)) & 2))) >> 31) & 1);
      int v983 = v982[v1194];
      bool v1195 = !(v983 == 0);
      if (v1195) {
        int * v984 = v939->cache_tags;
        int v985 = v984[v1194];
        int * v986 = v939->cache_vals;
        int v1198 = ((4 + ((((int)((unsigned int)((int)((unsigned int)v941 >> 2)) >> 1)) & 3) * 2)) + ((((v977 + ((~(((v979 ^ -1) | (-(v979 ^ -1))) >> 31)) & 2)) - (v980 + ((~(((v981 ^ -1) | (-(v981 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
        int v987 = v986[v1198];
        int v1199 = (((4 + ((((int)((unsigned int)((int)((unsigned int)v941 >> 2)) >> 1)) & 3) * 2)) + ((((v977 + ((~(((v979 ^ -1) | (-(v979 ^ -1))) >> 31)) & 2)) - (v980 + ((~(((v981 ^ -1) | (-(v981 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
        int v988 = v986[v1199];
        int * v989 = v939->mem;
        int v1201 = v985 * 2;
        v989[v1201] = v987;
        int * v991 = v939->mem;
        int v1204 = (v985 * 2) + 1;
        v991[v1204] = v988;
        ;
      } else {
        ;
      }
      int * v996 = v939->mem;
      int v1209 = ((int)((unsigned int)((int)((unsigned int)v941 >> 2)) >> 1)) * 2;
      int v997 = v996[v1209];
      int v1210 = (((int)((unsigned int)((int)((unsigned int)v941 >> 2)) >> 1)) * 2) + 1;
      int v998 = v996[v1210];
      int * v999 = v939->cache_vals;
      int v1212 = ((4 + ((((int)((unsigned int)((int)((unsigned int)v941 >> 2)) >> 1)) & 3) * 2)) + ((((v977 + ((~(((v979 ^ -1) | (-(v979 ^ -1))) >> 31)) & 2)) - (v980 + ((~(((v981 ^ -1) | (-(v981 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
      v999[v1212] = v997;
      int * v1001 = v939->cache_vals;
      int v1215 = (((4 + ((((int)((unsigned int)((int)((unsigned int)v941 >> 2)) >> 1)) & 3) * 2)) + ((((v977 + ((~(((v979 ^ -1) | (-(v979 ^ -1))) >> 31)) & 2)) - (v980 + ((~(((v981 ^ -1) | (-(v981 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
      v1001[v1215] = v998;
      int * v1003 = v939->cache_tags;
      int v1218 = (int)((unsigned int)((int)((unsigned int)v941 >> 2)) >> 1);
      v1003[v1194] = v1218;
      int * v1005 = v939->cache_dirty;
      v1005[v1194] = 0;
      int * v1007 = v939->cache_age;
      v1007[v1194] = 1;
      int * v1009 = v939->cache_age;
      int v1010 = v1009[v1194];
      int v1011 = v1009[v1168];
      int v1224 = v1011 + ((int)((unsigned int)(v1011 - v1010) >> 31));
      v1009[v1168] = v1224;
      int * v1013 = v939->cache_age;
      int v1014 = v1013[v1169];
      int v1226 = v1014 + ((int)((unsigned int)(v1014 - v1010) >> 31));
      v1013[v1169] = v1226;
      int * v1016 = v939->cache_age;
      v1016[v1194] = 0;
      v1019 = v1194;
    }
    int * v1020 = v939->cache_vals;
    int v1229 = v1019 * 2;
    int v1021 = v1020[v1229];
    int v1230 = (v1019 * 2) + 1;
    int v1022 = v1020[v1230];
    int v1231 = (((((int)((unsigned int)((int)((unsigned int)v941 >> 2)) >> 1)) & 1) * 2) + ((((v961 + ((~(((v963 ^ -1) | (-(v963 ^ -1))) >> 31)) & 2)) - (v964 + ((~(((v965 ^ -1) | (-(v965 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
    v1020[v1231] = v1021;
    int * v1024 = v939->cache_vals;
    int v1234 = ((((((int)((unsigned int)((int)((unsigned int)v941 >> 2)) >> 1)) & 1) * 2) + ((((v961 + ((~(((v963 ^ -1) | (-(v963 ^ -1))) >> 31)) & 2)) - (v964 + ((~(((v965 ^ -1) | (-(v965 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
    v1024[v1234] = v1022;
    int * v1026 = v939->cache_tags;
    int v1237 = ((((int)((unsigned int)((int)((unsigned int)v941 >> 2)) >> 1)) & 1) * 2) + ((((v961 + ((~(((v963 ^ -1) | (-(v963 ^ -1))) >> 31)) & 2)) - (v964 + ((~(((v965 ^ -1) | (-(v965 ^ -1))) >> 31)) & 2))) >> 31) & 1);
    int v1238 = (int)((unsigned int)((int)((unsigned int)v941 >> 2)) >> 1);
    v1026[v1237] = v1238;
    int * v1028 = v939->cache_dirty;
    v1028[v1237] = 0;
    int * v1030 = v939->cache_age;
    v1030[v1237] = 1;
    int * v1032 = v939->cache_age;
    int v1033 = v1032[v1237];
    int v1034 = v1032[v1166];
    int v1244 = v1034 + ((int)((unsigned int)(v1034 - v1033) >> 31));
    v1032[v1166] = v1244;
    int * v1036 = v939->cache_age;
    int v1037 = v1036[v1167];
    int v1246 = v1037 + ((int)((unsigned int)(v1037 - v1033) >> 31));
    v1036[v1167] = v1246;
    int * v1039 = v939->cache_age;
    v1039[v1237] = 0;
    v1042 = v1237;
  }
  int v1249 = (v1042 * 2) + (((int)((unsigned int)v941 >> 2)) & 1);
  int v1043 = v949[v1249];
  int * v1044 = v939->regs;
  v1044[11] = v1043;
  struct StateT * v1046 = v926->b;
  int * v1047 = v1046->regs;
  int v1048 = v1047[6];
  int * v1049 = v1046->cache_tags;
  int v1256 = (((int)((unsigned int)((int)((unsigned int)v1048 >> 2)) >> 1)) & 1) * 2;
  int v1050 = v1049[v1256];
  int v1257 = ((((int)((unsigned int)((int)((unsigned int)v1048 >> 2)) >> 1)) & 1) * 2) + 1;
  int v1051 = v1049[v1257];
  int v1258 = 4 + ((((int)((unsigned int)((int)((unsigned int)v1048 >> 2)) >> 1)) & 3) * 2);
  int v1052 = v1049[v1258];
  int v1259 = (4 + ((((int)((unsigned int)((int)((unsigned int)v1048 >> 2)) >> 1)) & 3) * 2)) + 1;
  int v1053 = v1049[v1259];
  int v1054 = v1046->timer;
  int v1260 = v1054 + ((100 ^ (((~(((v1052 ^ ((int)((unsigned int)((int)((unsigned int)v1048 >> 2)) >> 1))) | (-(v1052 ^ ((int)((unsigned int)((int)((unsigned int)v1048 >> 2)) >> 1))))) >> 31)) | (~(((v1053 ^ ((int)((unsigned int)((int)((unsigned int)v1048 >> 2)) >> 1))) | (-(v1053 ^ ((int)((unsigned int)((int)((unsigned int)v1048 >> 2)) >> 1))))) >> 31))) & 104)) ^ (((~(((v1050 ^ ((int)((unsigned int)((int)((unsigned int)v1048 >> 2)) >> 1))) | (-(v1050 ^ ((int)((unsigned int)((int)((unsigned int)v1048 >> 2)) >> 1))))) >> 31)) | (~(((v1051 ^ ((int)((unsigned int)((int)((unsigned int)v1048 >> 2)) >> 1))) | (-(v1051 ^ ((int)((unsigned int)((int)((unsigned int)v1048 >> 2)) >> 1))))) >> 31))) & (1 ^ (100 ^ (((~(((v1052 ^ ((int)((unsigned int)((int)((unsigned int)v1048 >> 2)) >> 1))) | (-(v1052 ^ ((int)((unsigned int)((int)((unsigned int)v1048 >> 2)) >> 1))))) >> 31)) | (~(((v1053 ^ ((int)((unsigned int)((int)((unsigned int)v1048 >> 2)) >> 1))) | (-(v1053 ^ ((int)((unsigned int)((int)((unsigned int)v1048 >> 2)) >> 1))))) >> 31))) & 104)))));
  v1046->timer = v1260;
  int * v1056 = v1046->cache_vals;
  bool v1261 = !(((~(((v1050 ^ ((int)((unsigned int)((int)((unsigned int)v1048 >> 2)) >> 1))) | (-(v1050 ^ ((int)((unsigned int)((int)((unsigned int)v1048 >> 2)) >> 1))))) >> 31)) | (~(((v1051 ^ ((int)((unsigned int)((int)((unsigned int)v1048 >> 2)) >> 1))) | (-(v1051 ^ ((int)((unsigned int)((int)((unsigned int)v1048 >> 2)) >> 1))))) >> 31))) == 0);
  int v1149;
  if (v1261) {
    int * v1057 = v1046->cache_age;
    int v1263 = ((((int)((unsigned int)((int)((unsigned int)v1048 >> 2)) >> 1)) & 1) * 2) + ((~(((v1051 ^ ((int)((unsigned int)((int)((unsigned int)v1048 >> 2)) >> 1))) | (-(v1051 ^ ((int)((unsigned int)((int)((unsigned int)v1048 >> 2)) >> 1))))) >> 31)) & 1);
    int v1058 = v1057[v1263];
    int v1059 = v1057[v1256];
    int v1264 = v1059 + ((int)((unsigned int)(v1059 - v1058) >> 31));
    v1057[v1256] = v1264;
    int * v1061 = v1046->cache_age;
    int v1062 = v1061[v1257];
    int v1266 = v1062 + ((int)((unsigned int)(v1062 - v1058) >> 31));
    v1061[v1257] = v1266;
    int * v1064 = v1046->cache_age;
    v1064[v1263] = 0;
    v1149 = v1263;
  } else {
    int * v1067 = v1046->cache_age;
    int v1270 = (((int)((unsigned int)((int)((unsigned int)v1048 >> 2)) >> 1)) & 1) * 2;
    int v1068 = v1067[v1270];
    int * v1069 = v1046->cache_tags;
    int v1070 = v1069[v1270];
    int v1071 = v1067[v1257];
    int v1072 = v1069[v1257];
    bool v1272 = !(((~(((v1052 ^ ((int)((unsigned int)((int)((unsigned int)v1048 >> 2)) >> 1))) | (-(v1052 ^ ((int)((unsigned int)((int)((unsigned int)v1048 >> 2)) >> 1))))) >> 31)) | (~(((v1053 ^ ((int)((unsigned int)((int)((unsigned int)v1048 >> 2)) >> 1))) | (-(v1053 ^ ((int)((unsigned int)((int)((unsigned int)v1048 >> 2)) >> 1))))) >> 31))) == 0);
    int v1126;
    if (v1272) {
      int * v1073 = v1046->cache_age;
      int v1274 = (4 + ((((int)((unsigned int)((int)((unsigned int)v1048 >> 2)) >> 1)) & 3) * 2)) + ((~(((v1053 ^ ((int)((unsigned int)((int)((unsigned int)v1048 >> 2)) >> 1))) | (-(v1053 ^ ((int)((unsigned int)((int)((unsigned int)v1048 >> 2)) >> 1))))) >> 31)) & 1);
      int v1074 = v1073[v1274];
      int v1075 = v1073[v1258];
      int v1275 = v1075 + ((int)((unsigned int)(v1075 - v1074) >> 31));
      v1073[v1258] = v1275;
      int * v1077 = v1046->cache_age;
      int v1078 = v1077[v1259];
      int v1277 = v1078 + ((int)((unsigned int)(v1078 - v1074) >> 31));
      v1077[v1259] = v1277;
      int * v1080 = v1046->cache_age;
      v1080[v1274] = 0;
      v1126 = v1274;
    } else {
      int * v1083 = v1046->cache_age;
      int v1281 = 4 + ((((int)((unsigned int)((int)((unsigned int)v1048 >> 2)) >> 1)) & 3) * 2);
      int v1084 = v1083[v1281];
      int * v1085 = v1046->cache_tags;
      int v1086 = v1085[v1281];
      int v1087 = v1083[v1259];
      int v1088 = v1085[v1259];
      int * v1089 = v1046->cache_dirty;
      int v1284 = (4 + ((((int)((unsigned int)((int)((unsigned int)v1048 >> 2)) >> 1)) & 3) * 2)) + ((((v1084 + ((~(((v1086 ^ -1) | (-(v1086 ^ -1))) >> 31)) & 2)) - (v1087 + ((~(((v1088 ^ -1) | (-(v1088 ^ -1))) >> 31)) & 2))) >> 31) & 1);
      int v1090 = v1089[v1284];
      bool v1285 = !(v1090 == 0);
      if (v1285) {
        int * v1091 = v1046->cache_tags;
        int v1092 = v1091[v1284];
        int * v1093 = v1046->cache_vals;
        int v1288 = ((4 + ((((int)((unsigned int)((int)((unsigned int)v1048 >> 2)) >> 1)) & 3) * 2)) + ((((v1084 + ((~(((v1086 ^ -1) | (-(v1086 ^ -1))) >> 31)) & 2)) - (v1087 + ((~(((v1088 ^ -1) | (-(v1088 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
        int v1094 = v1093[v1288];
        int v1289 = (((4 + ((((int)((unsigned int)((int)((unsigned int)v1048 >> 2)) >> 1)) & 3) * 2)) + ((((v1084 + ((~(((v1086 ^ -1) | (-(v1086 ^ -1))) >> 31)) & 2)) - (v1087 + ((~(((v1088 ^ -1) | (-(v1088 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
        int v1095 = v1093[v1289];
        int * v1096 = v1046->mem;
        int v1291 = v1092 * 2;
        v1096[v1291] = v1094;
        int * v1098 = v1046->mem;
        int v1294 = (v1092 * 2) + 1;
        v1098[v1294] = v1095;
        ;
      } else {
        ;
      }
      int * v1103 = v1046->mem;
      int v1299 = ((int)((unsigned int)((int)((unsigned int)v1048 >> 2)) >> 1)) * 2;
      int v1104 = v1103[v1299];
      int v1300 = (((int)((unsigned int)((int)((unsigned int)v1048 >> 2)) >> 1)) * 2) + 1;
      int v1105 = v1103[v1300];
      int * v1106 = v1046->cache_vals;
      int v1302 = ((4 + ((((int)((unsigned int)((int)((unsigned int)v1048 >> 2)) >> 1)) & 3) * 2)) + ((((v1084 + ((~(((v1086 ^ -1) | (-(v1086 ^ -1))) >> 31)) & 2)) - (v1087 + ((~(((v1088 ^ -1) | (-(v1088 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
      v1106[v1302] = v1104;
      int * v1108 = v1046->cache_vals;
      int v1305 = (((4 + ((((int)((unsigned int)((int)((unsigned int)v1048 >> 2)) >> 1)) & 3) * 2)) + ((((v1084 + ((~(((v1086 ^ -1) | (-(v1086 ^ -1))) >> 31)) & 2)) - (v1087 + ((~(((v1088 ^ -1) | (-(v1088 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
      v1108[v1305] = v1105;
      int * v1110 = v1046->cache_tags;
      int v1308 = (int)((unsigned int)((int)((unsigned int)v1048 >> 2)) >> 1);
      v1110[v1284] = v1308;
      int * v1112 = v1046->cache_dirty;
      v1112[v1284] = 0;
      int * v1114 = v1046->cache_age;
      v1114[v1284] = 1;
      int * v1116 = v1046->cache_age;
      int v1117 = v1116[v1284];
      int v1118 = v1116[v1258];
      int v1314 = v1118 + ((int)((unsigned int)(v1118 - v1117) >> 31));
      v1116[v1258] = v1314;
      int * v1120 = v1046->cache_age;
      int v1121 = v1120[v1259];
      int v1316 = v1121 + ((int)((unsigned int)(v1121 - v1117) >> 31));
      v1120[v1259] = v1316;
      int * v1123 = v1046->cache_age;
      v1123[v1284] = 0;
      v1126 = v1284;
    }
    int * v1127 = v1046->cache_vals;
    int v1319 = v1126 * 2;
    int v1128 = v1127[v1319];
    int v1320 = (v1126 * 2) + 1;
    int v1129 = v1127[v1320];
    int v1321 = (((((int)((unsigned int)((int)((unsigned int)v1048 >> 2)) >> 1)) & 1) * 2) + ((((v1068 + ((~(((v1070 ^ -1) | (-(v1070 ^ -1))) >> 31)) & 2)) - (v1071 + ((~(((v1072 ^ -1) | (-(v1072 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
    v1127[v1321] = v1128;
    int * v1131 = v1046->cache_vals;
    int v1324 = ((((((int)((unsigned int)((int)((unsigned int)v1048 >> 2)) >> 1)) & 1) * 2) + ((((v1068 + ((~(((v1070 ^ -1) | (-(v1070 ^ -1))) >> 31)) & 2)) - (v1071 + ((~(((v1072 ^ -1) | (-(v1072 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
    v1131[v1324] = v1129;
    int * v1133 = v1046->cache_tags;
    int v1327 = ((((int)((unsigned int)((int)((unsigned int)v1048 >> 2)) >> 1)) & 1) * 2) + ((((v1068 + ((~(((v1070 ^ -1) | (-(v1070 ^ -1))) >> 31)) & 2)) - (v1071 + ((~(((v1072 ^ -1) | (-(v1072 ^ -1))) >> 31)) & 2))) >> 31) & 1);
    int v1328 = (int)((unsigned int)((int)((unsigned int)v1048 >> 2)) >> 1);
    v1133[v1327] = v1328;
    int * v1135 = v1046->cache_dirty;
    v1135[v1327] = 0;
    int * v1137 = v1046->cache_age;
    v1137[v1327] = 1;
    int * v1139 = v1046->cache_age;
    int v1140 = v1139[v1327];
    int v1141 = v1139[v1256];
    int v1334 = v1141 + ((int)((unsigned int)(v1141 - v1140) >> 31));
    v1139[v1256] = v1334;
    int * v1143 = v1046->cache_age;
    int v1144 = v1143[v1257];
    int v1336 = v1144 + ((int)((unsigned int)(v1144 - v1140) >> 31));
    v1143[v1257] = v1336;
    int * v1146 = v1046->cache_age;
    v1146[v1327] = 0;
    v1149 = v1327;
  }
  int v1339 = (v1149 * 2) + (((int)((unsigned int)v1048 >> 2)) & 1);
  int v1150 = v1056[v1339];
  int * v1151 = v1046->regs;
  v1151[11] = v1150;
  struct StateT2 * v1153 = slot_9(v926);
  return v1153;
}

struct StateT2 * slot_4(struct StateT2 * v160) {
  struct StateT * v161 = v160->a;
  int v162 = v161->timer;
  struct StateT * v163 = v160->b;
  int v164 = v163->timer;
  bool v193 = v162 == v164;
  squared_assert(v193);
  squared_assume(v193);
  struct StateT * v167 = v160->a;
  int * v168 = v167->saved_regs;
  int * v169 = v167->regs;
  int v170 = v169[7];
  v168[7] = v170;
  struct StateT * v172 = v160->b;
  int * v173 = v172->saved_regs;
  int * v174 = v172->regs;
  int v175 = v174[7];
  v173[7] = v175;
  struct StateT * v177 = v160->a;
  int v178 = v177->timer;
  int v204 = v178 + 1;
  v177->timer = v204;
  struct StateT * v180 = v160->b;
  int v181 = v180->timer;
  int v206 = v181 + 1;
  v180->timer = v206;
  struct StateT * v183 = v160->a;
  int * v184 = v183->regs;
  v184[7] = 0;
  struct StateT * v186 = v160->b;
  int * v187 = v186->regs;
  v187[7] = 0;
  struct StateT2 * v189 = slot_5(v160);
  return v189;
}

struct StateT2 * slot_9(struct StateT2 * v1344) {
  struct StateT * v1345 = v1344->a;
  int v1346 = v1345->timer;
  struct StateT * v1347 = v1344->b;
  int v1348 = v1347->timer;
  bool v1369 = v1346 == v1348;
  squared_assert(v1369);
  squared_assume(v1369);
  struct StateT * v1351 = v1344->a;
  int v1352 = v1351->timer;
  int v1371 = v1352 + 1;
  v1351->timer = v1371;
  struct StateT * v1354 = v1344->b;
  int v1355 = v1354->timer;
  int v1373 = v1355 + 1;
  v1354->timer = v1373;
  struct StateT * v1357 = v1344->a;
  int * v1358 = v1357->regs;
  int v1359 = v1358[11];
  int v1377 = v1359 << 2;
  v1358[11] = v1377;
  struct StateT * v1361 = v1344->b;
  int * v1362 = v1361->regs;
  int v1363 = v1362[11];
  int v1380 = v1363 << 2;
  v1362[11] = v1380;
  struct StateT2 * v1365 = slot_10(v1344);
  return v1365;
}

struct StateT2 * slot_0(struct StateT2 * v2) {
  struct StateT * v3 = v2->a;
  int v4 = v3->timer;
  struct StateT * v5 = v2->b;
  int v6 = v5->timer;
  bool v27 = v4 == v6;
  squared_assert(v27);
  squared_assume(v27);
  struct StateT * v9 = v2->a;
  int v10 = v9->timer;
  int v29 = v10 + 1;
  v9->timer = v29;
  struct StateT * v12 = v2->b;
  int v13 = v12->timer;
  int v31 = v13 + 1;
  v12->timer = v31;
  struct StateT * v15 = v2->a;
  int * v16 = v15->regs;
  int v17 = v16[10];
  int v36 = v17 & 28;
  v16[5] = v36;
  struct StateT * v19 = v2->b;
  int * v20 = v19->regs;
  int v21 = v20[10];
  int v39 = v21 & 28;
  v20[5] = v39;
  struct StateT2 * v23 = slot_1(v2);
  return v23;
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