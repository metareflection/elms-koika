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

struct StateT * slot_5(struct StateT * v100);
struct StateT * slot_2(struct StateT * v40);
struct StateT * slot_7(struct StateT * v323);
struct StateT * slot_3(struct StateT * v48);
struct StateT * snippet(struct StateT * v0);
struct StateT * slot_10(struct StateT * v871);
struct StateT * slot_1(struct StateT * v24);
struct StateT * slot_8(struct StateT * v642);
struct StateT * slot_4(struct StateT * v77);
struct StateT * slot_9(struct StateT * v850);
struct StateT * slot_0(struct StateT * v2);
struct StateT * slot_5(struct StateT * v100) {
  int * v101 = v100->regs;
  int v102 = v101[5];
  int v103 = v101[9];
  bool v218 = v102 >= v103;
  struct StateT * v213;
  if (v218) {
    int v104 = v100->timer;
    int v219 = v104 + 15;
    v100->timer = v219;
    int * v106 = v100->saved_regs;
    int v107 = v106[6];
    int * v108 = v100->regs;
    v108[6] = v107;
    int * v110 = v100->saved_regs;
    int v111 = v110[7];
    int * v112 = v100->regs;
    v112[7] = v111;
    int * v114 = v100->reg_ready;
    int v115 = v100->timer;
    v114[0] = v115;
    int * v117 = v100->reg_ready;
    int v118 = v100->timer;
    v117[1] = v118;
    int * v120 = v100->reg_ready;
    int v121 = v100->timer;
    v120[2] = v121;
    int * v123 = v100->reg_ready;
    int v124 = v100->timer;
    v123[3] = v124;
    int * v126 = v100->reg_ready;
    int v127 = v100->timer;
    v126[4] = v127;
    int * v129 = v100->reg_ready;
    int v130 = v100->timer;
    v129[5] = v130;
    int * v132 = v100->reg_ready;
    int v133 = v100->timer;
    v132[6] = v133;
    int * v135 = v100->reg_ready;
    int v136 = v100->timer;
    v135[7] = v136;
    int * v138 = v100->reg_ready;
    int v139 = v100->timer;
    v138[8] = v139;
    int * v141 = v100->reg_ready;
    int v142 = v100->timer;
    v141[9] = v142;
    int * v144 = v100->reg_ready;
    int v145 = v100->timer;
    v144[10] = v145;
    int * v147 = v100->reg_ready;
    int v148 = v100->timer;
    v147[11] = v148;
    int * v150 = v100->reg_ready;
    int v151 = v100->timer;
    v150[12] = v151;
    int * v153 = v100->reg_ready;
    int v154 = v100->timer;
    v153[13] = v154;
    int * v156 = v100->reg_ready;
    int v157 = v100->timer;
    v156[14] = v157;
    int * v159 = v100->reg_ready;
    int v160 = v100->timer;
    v159[15] = v160;
    int * v162 = v100->reg_ready;
    int v163 = v100->timer;
    v162[16] = v163;
    int * v165 = v100->reg_ready;
    int v166 = v100->timer;
    v165[17] = v166;
    int * v168 = v100->reg_ready;
    int v169 = v100->timer;
    v168[18] = v169;
    int * v171 = v100->reg_ready;
    int v172 = v100->timer;
    v171[19] = v172;
    int * v174 = v100->reg_ready;
    int v175 = v100->timer;
    v174[20] = v175;
    int * v177 = v100->reg_ready;
    int v178 = v100->timer;
    v177[21] = v178;
    int * v180 = v100->reg_ready;
    int v181 = v100->timer;
    v180[22] = v181;
    int * v183 = v100->reg_ready;
    int v184 = v100->timer;
    v183[23] = v184;
    int * v186 = v100->reg_ready;
    int v187 = v100->timer;
    v186[24] = v187;
    int * v189 = v100->reg_ready;
    int v190 = v100->timer;
    v189[25] = v190;
    int * v192 = v100->reg_ready;
    int v193 = v100->timer;
    v192[26] = v193;
    int * v195 = v100->reg_ready;
    int v196 = v100->timer;
    v195[27] = v196;
    int * v198 = v100->reg_ready;
    int v199 = v100->timer;
    v198[28] = v199;
    int * v201 = v100->reg_ready;
    int v202 = v100->timer;
    v201[29] = v202;
    int * v204 = v100->reg_ready;
    int v205 = v100->timer;
    v204[30] = v205;
    int * v207 = v100->reg_ready;
    int v208 = v100->timer;
    v207[31] = v208;
    v213 = v100;
  } else {
    struct StateT * v211 = slot_7(v100);
    v213 = v211;
  }
  return v213;
}

struct StateT * slot_2(struct StateT * v40) {
  int v41 = v40->timer;
  int v45 = v41 + 1;
  v40->timer = v45;
  struct StateT * v43 = slot_3(v40);
  return v43;
}

struct StateT * slot_7(struct StateT * v323) {
  int v324 = v323->timer;
  int v497 = v324 + 1;
  v323->timer = v497;
  int * v326 = v323->reg_ready;
  int * v328 = v323->regs;
  int v329 = v328[6];
  int v331 = v328[7];
  int * v332 = v323->cache_tags;
  int v503 = (((int)((unsigned int)((int)((unsigned int)v329 >> 2)) >> 1)) & 1) * 2;
  int v333 = v332[v503];
  int v504 = ((((int)((unsigned int)((int)((unsigned int)v329 >> 2)) >> 1)) & 1) * 2) + 1;
  int v334 = v332[v504];
  int v505 = 4 + ((((int)((unsigned int)((int)((unsigned int)v329 >> 2)) >> 1)) & 3) * 2);
  int v335 = v332[v505];
  int v506 = (4 + ((((int)((unsigned int)((int)((unsigned int)v329 >> 2)) >> 1)) & 3) * 2)) + 1;
  int v336 = v332[v506];
  int v337 = v323->timer;
  int v507 = v337 + ((100 ^ (((~(((v335 ^ ((int)((unsigned int)((int)((unsigned int)v329 >> 2)) >> 1))) | (-(v335 ^ ((int)((unsigned int)((int)((unsigned int)v329 >> 2)) >> 1))))) >> 31)) | (~(((v336 ^ ((int)((unsigned int)((int)((unsigned int)v329 >> 2)) >> 1))) | (-(v336 ^ ((int)((unsigned int)((int)((unsigned int)v329 >> 2)) >> 1))))) >> 31))) & 104)) ^ (((~(((v333 ^ ((int)((unsigned int)((int)((unsigned int)v329 >> 2)) >> 1))) | (-(v333 ^ ((int)((unsigned int)((int)((unsigned int)v329 >> 2)) >> 1))))) >> 31)) | (~(((v334 ^ ((int)((unsigned int)((int)((unsigned int)v329 >> 2)) >> 1))) | (-(v334 ^ ((int)((unsigned int)((int)((unsigned int)v329 >> 2)) >> 1))))) >> 31))) & (1 ^ (100 ^ (((~(((v335 ^ ((int)((unsigned int)((int)((unsigned int)v329 >> 2)) >> 1))) | (-(v335 ^ ((int)((unsigned int)((int)((unsigned int)v329 >> 2)) >> 1))))) >> 31)) | (~(((v336 ^ ((int)((unsigned int)((int)((unsigned int)v329 >> 2)) >> 1))) | (-(v336 ^ ((int)((unsigned int)((int)((unsigned int)v329 >> 2)) >> 1))))) >> 31))) & 104)))));
  v323->timer = v507;
  bool v508 = !(((~(((v333 ^ ((int)((unsigned int)((int)((unsigned int)v329 >> 2)) >> 1))) | (-(v333 ^ ((int)((unsigned int)((int)((unsigned int)v329 >> 2)) >> 1))))) >> 31)) | (~(((v334 ^ ((int)((unsigned int)((int)((unsigned int)v329 >> 2)) >> 1))) | (-(v334 ^ ((int)((unsigned int)((int)((unsigned int)v329 >> 2)) >> 1))))) >> 31))) == 0);
  int v431;
  if (v508) {
    int * v339 = v323->cache_age;
    int v510 = ((((int)((unsigned int)((int)((unsigned int)v329 >> 2)) >> 1)) & 1) * 2) + ((~(((v334 ^ ((int)((unsigned int)((int)((unsigned int)v329 >> 2)) >> 1))) | (-(v334 ^ ((int)((unsigned int)((int)((unsigned int)v329 >> 2)) >> 1))))) >> 31)) & 1);
    int v340 = v339[v510];
    int v341 = v339[v503];
    int v511 = v341 + ((int)((unsigned int)(v341 - v340) >> 31));
    v339[v503] = v511;
    int * v343 = v323->cache_age;
    int v344 = v343[v504];
    int v513 = v344 + ((int)((unsigned int)(v344 - v340) >> 31));
    v343[v504] = v513;
    int * v346 = v323->cache_age;
    v346[v510] = 0;
    v431 = v510;
  } else {
    int * v349 = v323->cache_age;
    int v517 = (((int)((unsigned int)((int)((unsigned int)v329 >> 2)) >> 1)) & 1) * 2;
    int v350 = v349[v517];
    int * v351 = v323->cache_tags;
    int v352 = v351[v517];
    int v353 = v349[v504];
    int v354 = v351[v504];
    bool v519 = !(((~(((v335 ^ ((int)((unsigned int)((int)((unsigned int)v329 >> 2)) >> 1))) | (-(v335 ^ ((int)((unsigned int)((int)((unsigned int)v329 >> 2)) >> 1))))) >> 31)) | (~(((v336 ^ ((int)((unsigned int)((int)((unsigned int)v329 >> 2)) >> 1))) | (-(v336 ^ ((int)((unsigned int)((int)((unsigned int)v329 >> 2)) >> 1))))) >> 31))) == 0);
    int v408;
    if (v519) {
      int * v355 = v323->cache_age;
      int v521 = (4 + ((((int)((unsigned int)((int)((unsigned int)v329 >> 2)) >> 1)) & 3) * 2)) + ((~(((v336 ^ ((int)((unsigned int)((int)((unsigned int)v329 >> 2)) >> 1))) | (-(v336 ^ ((int)((unsigned int)((int)((unsigned int)v329 >> 2)) >> 1))))) >> 31)) & 1);
      int v356 = v355[v521];
      int v357 = v355[v505];
      int v522 = v357 + ((int)((unsigned int)(v357 - v356) >> 31));
      v355[v505] = v522;
      int * v359 = v323->cache_age;
      int v360 = v359[v506];
      int v524 = v360 + ((int)((unsigned int)(v360 - v356) >> 31));
      v359[v506] = v524;
      int * v362 = v323->cache_age;
      v362[v521] = 0;
      v408 = v521;
    } else {
      int * v365 = v323->cache_age;
      int v528 = 4 + ((((int)((unsigned int)((int)((unsigned int)v329 >> 2)) >> 1)) & 3) * 2);
      int v366 = v365[v528];
      int * v367 = v323->cache_tags;
      int v368 = v367[v528];
      int v369 = v365[v506];
      int v370 = v367[v506];
      int * v371 = v323->cache_dirty;
      int v531 = (4 + ((((int)((unsigned int)((int)((unsigned int)v329 >> 2)) >> 1)) & 3) * 2)) + ((((v366 + ((~(((v368 ^ -1) | (-(v368 ^ -1))) >> 31)) & 2)) - (v369 + ((~(((v370 ^ -1) | (-(v370 ^ -1))) >> 31)) & 2))) >> 31) & 1);
      int v372 = v371[v531];
      bool v532 = !(v372 == 0);
      if (v532) {
        int * v373 = v323->cache_tags;
        int v374 = v373[v531];
        int * v375 = v323->cache_vals;
        int v535 = ((4 + ((((int)((unsigned int)((int)((unsigned int)v329 >> 2)) >> 1)) & 3) * 2)) + ((((v366 + ((~(((v368 ^ -1) | (-(v368 ^ -1))) >> 31)) & 2)) - (v369 + ((~(((v370 ^ -1) | (-(v370 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
        int v376 = v375[v535];
        int v536 = (((4 + ((((int)((unsigned int)((int)((unsigned int)v329 >> 2)) >> 1)) & 3) * 2)) + ((((v366 + ((~(((v368 ^ -1) | (-(v368 ^ -1))) >> 31)) & 2)) - (v369 + ((~(((v370 ^ -1) | (-(v370 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
        int v377 = v375[v536];
        int * v378 = v323->mem;
        int v538 = v374 * 2;
        v378[v538] = v376;
        int * v380 = v323->mem;
        int v541 = (v374 * 2) + 1;
        v380[v541] = v377;
        ;
      } else {
        ;
      }
      int * v385 = v323->mem;
      int v546 = ((int)((unsigned int)((int)((unsigned int)v329 >> 2)) >> 1)) * 2;
      int v386 = v385[v546];
      int v547 = (((int)((unsigned int)((int)((unsigned int)v329 >> 2)) >> 1)) * 2) + 1;
      int v387 = v385[v547];
      int * v388 = v323->cache_vals;
      int v549 = ((4 + ((((int)((unsigned int)((int)((unsigned int)v329 >> 2)) >> 1)) & 3) * 2)) + ((((v366 + ((~(((v368 ^ -1) | (-(v368 ^ -1))) >> 31)) & 2)) - (v369 + ((~(((v370 ^ -1) | (-(v370 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
      v388[v549] = v386;
      int * v390 = v323->cache_vals;
      int v552 = (((4 + ((((int)((unsigned int)((int)((unsigned int)v329 >> 2)) >> 1)) & 3) * 2)) + ((((v366 + ((~(((v368 ^ -1) | (-(v368 ^ -1))) >> 31)) & 2)) - (v369 + ((~(((v370 ^ -1) | (-(v370 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
      v390[v552] = v387;
      int * v392 = v323->cache_tags;
      int v555 = (int)((unsigned int)((int)((unsigned int)v329 >> 2)) >> 1);
      v392[v531] = v555;
      int * v394 = v323->cache_dirty;
      v394[v531] = 0;
      int * v396 = v323->cache_age;
      v396[v531] = 1;
      int * v398 = v323->cache_age;
      int v399 = v398[v531];
      int v400 = v398[v505];
      int v561 = v400 + ((int)((unsigned int)(v400 - v399) >> 31));
      v398[v505] = v561;
      int * v402 = v323->cache_age;
      int v403 = v402[v506];
      int v563 = v403 + ((int)((unsigned int)(v403 - v399) >> 31));
      v402[v506] = v563;
      int * v405 = v323->cache_age;
      v405[v531] = 0;
      v408 = v531;
    }
    int * v409 = v323->cache_vals;
    int v566 = v408 * 2;
    int v410 = v409[v566];
    int v567 = (v408 * 2) + 1;
    int v411 = v409[v567];
    int v568 = (((((int)((unsigned int)((int)((unsigned int)v329 >> 2)) >> 1)) & 1) * 2) + ((((v350 + ((~(((v352 ^ -1) | (-(v352 ^ -1))) >> 31)) & 2)) - (v353 + ((~(((v354 ^ -1) | (-(v354 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
    v409[v568] = v410;
    int * v413 = v323->cache_vals;
    int v571 = ((((((int)((unsigned int)((int)((unsigned int)v329 >> 2)) >> 1)) & 1) * 2) + ((((v350 + ((~(((v352 ^ -1) | (-(v352 ^ -1))) >> 31)) & 2)) - (v353 + ((~(((v354 ^ -1) | (-(v354 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
    v413[v571] = v411;
    int * v415 = v323->cache_tags;
    int v574 = ((((int)((unsigned int)((int)((unsigned int)v329 >> 2)) >> 1)) & 1) * 2) + ((((v350 + ((~(((v352 ^ -1) | (-(v352 ^ -1))) >> 31)) & 2)) - (v353 + ((~(((v354 ^ -1) | (-(v354 ^ -1))) >> 31)) & 2))) >> 31) & 1);
    int v575 = (int)((unsigned int)((int)((unsigned int)v329 >> 2)) >> 1);
    v415[v574] = v575;
    int * v417 = v323->cache_dirty;
    v417[v574] = 0;
    int * v419 = v323->cache_age;
    v419[v574] = 1;
    int * v421 = v323->cache_age;
    int v422 = v421[v574];
    int v423 = v421[v503];
    int v581 = v423 + ((int)((unsigned int)(v423 - v422) >> 31));
    v421[v503] = v581;
    int * v425 = v323->cache_age;
    int v426 = v425[v504];
    int v583 = v426 + ((int)((unsigned int)(v426 - v422) >> 31));
    v425[v504] = v583;
    int * v428 = v323->cache_age;
    v428[v574] = 0;
    v431 = v574;
  }
  int * v432 = v323->cache_vals;
  int v586 = (v431 * 2) + (((int)((unsigned int)v329 >> 2)) & 1);
  v432[v586] = v331;
  int * v434 = v323->cache_tags;
  int v435 = v434[v505];
  int v436 = v434[v506];
  bool v589 = !(((~(((v435 ^ ((int)((unsigned int)((int)((unsigned int)v329 >> 2)) >> 1))) | (-(v435 ^ ((int)((unsigned int)((int)((unsigned int)v329 >> 2)) >> 1))))) >> 31)) | (~(((v436 ^ ((int)((unsigned int)((int)((unsigned int)v329 >> 2)) >> 1))) | (-(v436 ^ ((int)((unsigned int)((int)((unsigned int)v329 >> 2)) >> 1))))) >> 31))) == 0);
  int v490;
  if (v589) {
    int * v437 = v323->cache_age;
    int v591 = (4 + ((((int)((unsigned int)((int)((unsigned int)v329 >> 2)) >> 1)) & 3) * 2)) + ((~(((v436 ^ ((int)((unsigned int)((int)((unsigned int)v329 >> 2)) >> 1))) | (-(v436 ^ ((int)((unsigned int)((int)((unsigned int)v329 >> 2)) >> 1))))) >> 31)) & 1);
    int v438 = v437[v591];
    int v439 = v437[v505];
    int v592 = v439 + ((int)((unsigned int)(v439 - v438) >> 31));
    v437[v505] = v592;
    int * v441 = v323->cache_age;
    int v442 = v441[v506];
    int v594 = v442 + ((int)((unsigned int)(v442 - v438) >> 31));
    v441[v506] = v594;
    int * v444 = v323->cache_age;
    v444[v591] = 0;
    v490 = v591;
  } else {
    int * v447 = v323->cache_age;
    int v598 = 4 + ((((int)((unsigned int)((int)((unsigned int)v329 >> 2)) >> 1)) & 3) * 2);
    int v448 = v447[v598];
    int * v449 = v323->cache_tags;
    int v450 = v449[v598];
    int v451 = v447[v506];
    int v452 = v449[v506];
    int * v453 = v323->cache_dirty;
    int v601 = (4 + ((((int)((unsigned int)((int)((unsigned int)v329 >> 2)) >> 1)) & 3) * 2)) + ((((v448 + ((~(((v450 ^ -1) | (-(v450 ^ -1))) >> 31)) & 2)) - (v451 + ((~(((v452 ^ -1) | (-(v452 ^ -1))) >> 31)) & 2))) >> 31) & 1);
    int v454 = v453[v601];
    bool v602 = !(v454 == 0);
    if (v602) {
      int * v455 = v323->cache_tags;
      int v456 = v455[v601];
      int * v457 = v323->cache_vals;
      int v605 = ((4 + ((((int)((unsigned int)((int)((unsigned int)v329 >> 2)) >> 1)) & 3) * 2)) + ((((v448 + ((~(((v450 ^ -1) | (-(v450 ^ -1))) >> 31)) & 2)) - (v451 + ((~(((v452 ^ -1) | (-(v452 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
      int v458 = v457[v605];
      int v606 = (((4 + ((((int)((unsigned int)((int)((unsigned int)v329 >> 2)) >> 1)) & 3) * 2)) + ((((v448 + ((~(((v450 ^ -1) | (-(v450 ^ -1))) >> 31)) & 2)) - (v451 + ((~(((v452 ^ -1) | (-(v452 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
      int v459 = v457[v606];
      int * v460 = v323->mem;
      int v608 = v456 * 2;
      v460[v608] = v458;
      int * v462 = v323->mem;
      int v611 = (v456 * 2) + 1;
      v462[v611] = v459;
      ;
    } else {
      ;
    }
    int * v467 = v323->mem;
    int v616 = ((int)((unsigned int)((int)((unsigned int)v329 >> 2)) >> 1)) * 2;
    int v468 = v467[v616];
    int v617 = (((int)((unsigned int)((int)((unsigned int)v329 >> 2)) >> 1)) * 2) + 1;
    int v469 = v467[v617];
    int * v470 = v323->cache_vals;
    int v619 = ((4 + ((((int)((unsigned int)((int)((unsigned int)v329 >> 2)) >> 1)) & 3) * 2)) + ((((v448 + ((~(((v450 ^ -1) | (-(v450 ^ -1))) >> 31)) & 2)) - (v451 + ((~(((v452 ^ -1) | (-(v452 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
    v470[v619] = v468;
    int * v472 = v323->cache_vals;
    int v622 = (((4 + ((((int)((unsigned int)((int)((unsigned int)v329 >> 2)) >> 1)) & 3) * 2)) + ((((v448 + ((~(((v450 ^ -1) | (-(v450 ^ -1))) >> 31)) & 2)) - (v451 + ((~(((v452 ^ -1) | (-(v452 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
    v472[v622] = v469;
    int * v474 = v323->cache_tags;
    int v625 = (int)((unsigned int)((int)((unsigned int)v329 >> 2)) >> 1);
    v474[v601] = v625;
    int * v476 = v323->cache_dirty;
    v476[v601] = 0;
    int * v478 = v323->cache_age;
    v478[v601] = 1;
    int * v480 = v323->cache_age;
    int v481 = v480[v601];
    int v482 = v480[v505];
    int v631 = v482 + ((int)((unsigned int)(v482 - v481) >> 31));
    v480[v505] = v631;
    int * v484 = v323->cache_age;
    int v485 = v484[v506];
    int v633 = v485 + ((int)((unsigned int)(v485 - v481) >> 31));
    v484[v506] = v633;
    int * v487 = v323->cache_age;
    v487[v601] = 0;
    v490 = v601;
  }
  int * v491 = v323->cache_vals;
  int v636 = (v490 * 2) + (((int)((unsigned int)v329 >> 2)) & 1);
  v491[v636] = v331;
  int * v493 = v323->cache_dirty;
  v493[v490] = 1;
  struct StateT * v495 = slot_8(v323);
  return v495;
}

struct StateT * slot_3(struct StateT * v48) {
  int * v49 = v48->saved_regs;
  int * v50 = v48->regs;
  int v51 = v50[6];
  v49[6] = v51;
  int v53 = v48->timer;
  int v68 = v53 + 1;
  v48->timer = v68;
  int * v55 = v48->reg_ready;
  int v56 = v55[5];
  int * v57 = v48->regs;
  int v58 = v57[5];
  int v72 = (v56 + ((v53 - v56) & (~((v53 - v56) >> 31)))) + 1;
  v55[6] = v72;
  int * v60 = v48->regs;
  int v74 = v58 + 80;
  v60[6] = v74;
  struct StateT * v62 = slot_4(v48);
  return v62;
}

struct StateT * snippet(struct StateT * v0) {
  struct StateT * v1 = slot_0(v0);
  int v1076 = v1->timer;
  int * v1077 = v1->reg_ready;
  int v1078 = v1077[0];
  int v1209 = v1078 + ((v1076 - v1078) & (~((v1076 - v1078) >> 31)));
  v1->timer = v1209;
  int v1080 = v1->timer;
  int * v1081 = v1->reg_ready;
  int v1082 = v1081[1];
  int v1212 = v1082 + ((v1080 - v1082) & (~((v1080 - v1082) >> 31)));
  v1->timer = v1212;
  int v1084 = v1->timer;
  int * v1085 = v1->reg_ready;
  int v1086 = v1085[2];
  int v1215 = v1086 + ((v1084 - v1086) & (~((v1084 - v1086) >> 31)));
  v1->timer = v1215;
  int v1088 = v1->timer;
  int * v1089 = v1->reg_ready;
  int v1090 = v1089[3];
  int v1218 = v1090 + ((v1088 - v1090) & (~((v1088 - v1090) >> 31)));
  v1->timer = v1218;
  int v1092 = v1->timer;
  int * v1093 = v1->reg_ready;
  int v1094 = v1093[4];
  int v1221 = v1094 + ((v1092 - v1094) & (~((v1092 - v1094) >> 31)));
  v1->timer = v1221;
  int v1096 = v1->timer;
  int * v1097 = v1->reg_ready;
  int v1098 = v1097[5];
  int v1224 = v1098 + ((v1096 - v1098) & (~((v1096 - v1098) >> 31)));
  v1->timer = v1224;
  int v1100 = v1->timer;
  int * v1101 = v1->reg_ready;
  int v1102 = v1101[6];
  int v1227 = v1102 + ((v1100 - v1102) & (~((v1100 - v1102) >> 31)));
  v1->timer = v1227;
  int v1104 = v1->timer;
  int * v1105 = v1->reg_ready;
  int v1106 = v1105[7];
  int v1230 = v1106 + ((v1104 - v1106) & (~((v1104 - v1106) >> 31)));
  v1->timer = v1230;
  int v1108 = v1->timer;
  int * v1109 = v1->reg_ready;
  int v1110 = v1109[8];
  int v1233 = v1110 + ((v1108 - v1110) & (~((v1108 - v1110) >> 31)));
  v1->timer = v1233;
  int v1112 = v1->timer;
  int * v1113 = v1->reg_ready;
  int v1114 = v1113[9];
  int v1236 = v1114 + ((v1112 - v1114) & (~((v1112 - v1114) >> 31)));
  v1->timer = v1236;
  int v1116 = v1->timer;
  int * v1117 = v1->reg_ready;
  int v1118 = v1117[10];
  int v1239 = v1118 + ((v1116 - v1118) & (~((v1116 - v1118) >> 31)));
  v1->timer = v1239;
  int v1120 = v1->timer;
  int * v1121 = v1->reg_ready;
  int v1122 = v1121[11];
  int v1242 = v1122 + ((v1120 - v1122) & (~((v1120 - v1122) >> 31)));
  v1->timer = v1242;
  int v1124 = v1->timer;
  int * v1125 = v1->reg_ready;
  int v1126 = v1125[12];
  int v1245 = v1126 + ((v1124 - v1126) & (~((v1124 - v1126) >> 31)));
  v1->timer = v1245;
  int v1128 = v1->timer;
  int * v1129 = v1->reg_ready;
  int v1130 = v1129[13];
  int v1248 = v1130 + ((v1128 - v1130) & (~((v1128 - v1130) >> 31)));
  v1->timer = v1248;
  int v1132 = v1->timer;
  int * v1133 = v1->reg_ready;
  int v1134 = v1133[14];
  int v1251 = v1134 + ((v1132 - v1134) & (~((v1132 - v1134) >> 31)));
  v1->timer = v1251;
  int v1136 = v1->timer;
  int * v1137 = v1->reg_ready;
  int v1138 = v1137[15];
  int v1254 = v1138 + ((v1136 - v1138) & (~((v1136 - v1138) >> 31)));
  v1->timer = v1254;
  int v1140 = v1->timer;
  int * v1141 = v1->reg_ready;
  int v1142 = v1141[16];
  int v1257 = v1142 + ((v1140 - v1142) & (~((v1140 - v1142) >> 31)));
  v1->timer = v1257;
  int v1144 = v1->timer;
  int * v1145 = v1->reg_ready;
  int v1146 = v1145[17];
  int v1260 = v1146 + ((v1144 - v1146) & (~((v1144 - v1146) >> 31)));
  v1->timer = v1260;
  int v1148 = v1->timer;
  int * v1149 = v1->reg_ready;
  int v1150 = v1149[18];
  int v1263 = v1150 + ((v1148 - v1150) & (~((v1148 - v1150) >> 31)));
  v1->timer = v1263;
  int v1152 = v1->timer;
  int * v1153 = v1->reg_ready;
  int v1154 = v1153[19];
  int v1266 = v1154 + ((v1152 - v1154) & (~((v1152 - v1154) >> 31)));
  v1->timer = v1266;
  int v1156 = v1->timer;
  int * v1157 = v1->reg_ready;
  int v1158 = v1157[20];
  int v1269 = v1158 + ((v1156 - v1158) & (~((v1156 - v1158) >> 31)));
  v1->timer = v1269;
  int v1160 = v1->timer;
  int * v1161 = v1->reg_ready;
  int v1162 = v1161[21];
  int v1272 = v1162 + ((v1160 - v1162) & (~((v1160 - v1162) >> 31)));
  v1->timer = v1272;
  int v1164 = v1->timer;
  int * v1165 = v1->reg_ready;
  int v1166 = v1165[22];
  int v1275 = v1166 + ((v1164 - v1166) & (~((v1164 - v1166) >> 31)));
  v1->timer = v1275;
  int v1168 = v1->timer;
  int * v1169 = v1->reg_ready;
  int v1170 = v1169[23];
  int v1278 = v1170 + ((v1168 - v1170) & (~((v1168 - v1170) >> 31)));
  v1->timer = v1278;
  int v1172 = v1->timer;
  int * v1173 = v1->reg_ready;
  int v1174 = v1173[24];
  int v1281 = v1174 + ((v1172 - v1174) & (~((v1172 - v1174) >> 31)));
  v1->timer = v1281;
  int v1176 = v1->timer;
  int * v1177 = v1->reg_ready;
  int v1178 = v1177[25];
  int v1284 = v1178 + ((v1176 - v1178) & (~((v1176 - v1178) >> 31)));
  v1->timer = v1284;
  int v1180 = v1->timer;
  int * v1181 = v1->reg_ready;
  int v1182 = v1181[26];
  int v1287 = v1182 + ((v1180 - v1182) & (~((v1180 - v1182) >> 31)));
  v1->timer = v1287;
  int v1184 = v1->timer;
  int * v1185 = v1->reg_ready;
  int v1186 = v1185[27];
  int v1290 = v1186 + ((v1184 - v1186) & (~((v1184 - v1186) >> 31)));
  v1->timer = v1290;
  int v1188 = v1->timer;
  int * v1189 = v1->reg_ready;
  int v1190 = v1189[28];
  int v1293 = v1190 + ((v1188 - v1190) & (~((v1188 - v1190) >> 31)));
  v1->timer = v1293;
  int v1192 = v1->timer;
  int * v1193 = v1->reg_ready;
  int v1194 = v1193[29];
  int v1296 = v1194 + ((v1192 - v1194) & (~((v1192 - v1194) >> 31)));
  v1->timer = v1296;
  int v1196 = v1->timer;
  int * v1197 = v1->reg_ready;
  int v1198 = v1197[30];
  int v1299 = v1198 + ((v1196 - v1198) & (~((v1196 - v1198) >> 31)));
  v1->timer = v1299;
  int v1200 = v1->timer;
  int * v1201 = v1->reg_ready;
  int v1202 = v1201[31];
  int v1302 = v1202 + ((v1200 - v1202) & (~((v1200 - v1202) >> 31)));
  v1->timer = v1302;
  return v1;
}

struct StateT * slot_10(struct StateT * v871) {
  int v872 = v871->timer;
  int v983 = v872 + 1;
  v871->timer = v983;
  int * v874 = v871->reg_ready;
  int v875 = v874[11];
  int * v876 = v871->regs;
  int v877 = v876[11];
  int * v878 = v871->cache_tags;
  int v988 = (((int)((unsigned int)((int)((unsigned int)v877 >> 2)) >> 1)) & 1) * 2;
  int v879 = v878[v988];
  int v989 = ((((int)((unsigned int)((int)((unsigned int)v877 >> 2)) >> 1)) & 1) * 2) + 1;
  int v880 = v878[v989];
  int v990 = 4 + ((((int)((unsigned int)((int)((unsigned int)v877 >> 2)) >> 1)) & 3) * 2);
  int v881 = v878[v990];
  int v991 = (4 + ((((int)((unsigned int)((int)((unsigned int)v877 >> 2)) >> 1)) & 3) * 2)) + 1;
  int v882 = v878[v991];
  int * v883 = v871->cache_vals;
  bool v992 = !(((~(((v879 ^ ((int)((unsigned int)((int)((unsigned int)v877 >> 2)) >> 1))) | (-(v879 ^ ((int)((unsigned int)((int)((unsigned int)v877 >> 2)) >> 1))))) >> 31)) | (~(((v880 ^ ((int)((unsigned int)((int)((unsigned int)v877 >> 2)) >> 1))) | (-(v880 ^ ((int)((unsigned int)((int)((unsigned int)v877 >> 2)) >> 1))))) >> 31))) == 0);
  int v976;
  if (v992) {
    int * v884 = v871->cache_age;
    int v994 = ((((int)((unsigned int)((int)((unsigned int)v877 >> 2)) >> 1)) & 1) * 2) + ((~(((v880 ^ ((int)((unsigned int)((int)((unsigned int)v877 >> 2)) >> 1))) | (-(v880 ^ ((int)((unsigned int)((int)((unsigned int)v877 >> 2)) >> 1))))) >> 31)) & 1);
    int v885 = v884[v994];
    int v886 = v884[v988];
    int v995 = v886 + ((int)((unsigned int)(v886 - v885) >> 31));
    v884[v988] = v995;
    int * v888 = v871->cache_age;
    int v889 = v888[v989];
    int v997 = v889 + ((int)((unsigned int)(v889 - v885) >> 31));
    v888[v989] = v997;
    int * v891 = v871->cache_age;
    v891[v994] = 0;
    v976 = v994;
  } else {
    int * v894 = v871->cache_age;
    int v1001 = (((int)((unsigned int)((int)((unsigned int)v877 >> 2)) >> 1)) & 1) * 2;
    int v895 = v894[v1001];
    int * v896 = v871->cache_tags;
    int v897 = v896[v1001];
    int v898 = v894[v989];
    int v899 = v896[v989];
    bool v1003 = !(((~(((v881 ^ ((int)((unsigned int)((int)((unsigned int)v877 >> 2)) >> 1))) | (-(v881 ^ ((int)((unsigned int)((int)((unsigned int)v877 >> 2)) >> 1))))) >> 31)) | (~(((v882 ^ ((int)((unsigned int)((int)((unsigned int)v877 >> 2)) >> 1))) | (-(v882 ^ ((int)((unsigned int)((int)((unsigned int)v877 >> 2)) >> 1))))) >> 31))) == 0);
    int v953;
    if (v1003) {
      int * v900 = v871->cache_age;
      int v1005 = (4 + ((((int)((unsigned int)((int)((unsigned int)v877 >> 2)) >> 1)) & 3) * 2)) + ((~(((v882 ^ ((int)((unsigned int)((int)((unsigned int)v877 >> 2)) >> 1))) | (-(v882 ^ ((int)((unsigned int)((int)((unsigned int)v877 >> 2)) >> 1))))) >> 31)) & 1);
      int v901 = v900[v1005];
      int v902 = v900[v990];
      int v1006 = v902 + ((int)((unsigned int)(v902 - v901) >> 31));
      v900[v990] = v1006;
      int * v904 = v871->cache_age;
      int v905 = v904[v991];
      int v1008 = v905 + ((int)((unsigned int)(v905 - v901) >> 31));
      v904[v991] = v1008;
      int * v907 = v871->cache_age;
      v907[v1005] = 0;
      v953 = v1005;
    } else {
      int * v910 = v871->cache_age;
      int v1012 = 4 + ((((int)((unsigned int)((int)((unsigned int)v877 >> 2)) >> 1)) & 3) * 2);
      int v911 = v910[v1012];
      int * v912 = v871->cache_tags;
      int v913 = v912[v1012];
      int v914 = v910[v991];
      int v915 = v912[v991];
      int * v916 = v871->cache_dirty;
      int v1015 = (4 + ((((int)((unsigned int)((int)((unsigned int)v877 >> 2)) >> 1)) & 3) * 2)) + ((((v911 + ((~(((v913 ^ -1) | (-(v913 ^ -1))) >> 31)) & 2)) - (v914 + ((~(((v915 ^ -1) | (-(v915 ^ -1))) >> 31)) & 2))) >> 31) & 1);
      int v917 = v916[v1015];
      bool v1016 = !(v917 == 0);
      if (v1016) {
        int * v918 = v871->cache_tags;
        int v919 = v918[v1015];
        int * v920 = v871->cache_vals;
        int v1019 = ((4 + ((((int)((unsigned int)((int)((unsigned int)v877 >> 2)) >> 1)) & 3) * 2)) + ((((v911 + ((~(((v913 ^ -1) | (-(v913 ^ -1))) >> 31)) & 2)) - (v914 + ((~(((v915 ^ -1) | (-(v915 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
        int v921 = v920[v1019];
        int v1020 = (((4 + ((((int)((unsigned int)((int)((unsigned int)v877 >> 2)) >> 1)) & 3) * 2)) + ((((v911 + ((~(((v913 ^ -1) | (-(v913 ^ -1))) >> 31)) & 2)) - (v914 + ((~(((v915 ^ -1) | (-(v915 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
        int v922 = v920[v1020];
        int * v923 = v871->mem;
        int v1022 = v919 * 2;
        v923[v1022] = v921;
        int * v925 = v871->mem;
        int v1025 = (v919 * 2) + 1;
        v925[v1025] = v922;
        ;
      } else {
        ;
      }
      int * v930 = v871->mem;
      int v1030 = ((int)((unsigned int)((int)((unsigned int)v877 >> 2)) >> 1)) * 2;
      int v931 = v930[v1030];
      int v1031 = (((int)((unsigned int)((int)((unsigned int)v877 >> 2)) >> 1)) * 2) + 1;
      int v932 = v930[v1031];
      int * v933 = v871->cache_vals;
      int v1033 = ((4 + ((((int)((unsigned int)((int)((unsigned int)v877 >> 2)) >> 1)) & 3) * 2)) + ((((v911 + ((~(((v913 ^ -1) | (-(v913 ^ -1))) >> 31)) & 2)) - (v914 + ((~(((v915 ^ -1) | (-(v915 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
      v933[v1033] = v931;
      int * v935 = v871->cache_vals;
      int v1036 = (((4 + ((((int)((unsigned int)((int)((unsigned int)v877 >> 2)) >> 1)) & 3) * 2)) + ((((v911 + ((~(((v913 ^ -1) | (-(v913 ^ -1))) >> 31)) & 2)) - (v914 + ((~(((v915 ^ -1) | (-(v915 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
      v935[v1036] = v932;
      int * v937 = v871->cache_tags;
      int v1039 = (int)((unsigned int)((int)((unsigned int)v877 >> 2)) >> 1);
      v937[v1015] = v1039;
      int * v939 = v871->cache_dirty;
      v939[v1015] = 0;
      int * v941 = v871->cache_age;
      v941[v1015] = 1;
      int * v943 = v871->cache_age;
      int v944 = v943[v1015];
      int v945 = v943[v990];
      int v1045 = v945 + ((int)((unsigned int)(v945 - v944) >> 31));
      v943[v990] = v1045;
      int * v947 = v871->cache_age;
      int v948 = v947[v991];
      int v1047 = v948 + ((int)((unsigned int)(v948 - v944) >> 31));
      v947[v991] = v1047;
      int * v950 = v871->cache_age;
      v950[v1015] = 0;
      v953 = v1015;
    }
    int * v954 = v871->cache_vals;
    int v1050 = v953 * 2;
    int v955 = v954[v1050];
    int v1051 = (v953 * 2) + 1;
    int v956 = v954[v1051];
    int v1052 = (((((int)((unsigned int)((int)((unsigned int)v877 >> 2)) >> 1)) & 1) * 2) + ((((v895 + ((~(((v897 ^ -1) | (-(v897 ^ -1))) >> 31)) & 2)) - (v898 + ((~(((v899 ^ -1) | (-(v899 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
    v954[v1052] = v955;
    int * v958 = v871->cache_vals;
    int v1055 = ((((((int)((unsigned int)((int)((unsigned int)v877 >> 2)) >> 1)) & 1) * 2) + ((((v895 + ((~(((v897 ^ -1) | (-(v897 ^ -1))) >> 31)) & 2)) - (v898 + ((~(((v899 ^ -1) | (-(v899 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
    v958[v1055] = v956;
    int * v960 = v871->cache_tags;
    int v1058 = ((((int)((unsigned int)((int)((unsigned int)v877 >> 2)) >> 1)) & 1) * 2) + ((((v895 + ((~(((v897 ^ -1) | (-(v897 ^ -1))) >> 31)) & 2)) - (v898 + ((~(((v899 ^ -1) | (-(v899 ^ -1))) >> 31)) & 2))) >> 31) & 1);
    int v1059 = (int)((unsigned int)((int)((unsigned int)v877 >> 2)) >> 1);
    v960[v1058] = v1059;
    int * v962 = v871->cache_dirty;
    v962[v1058] = 0;
    int * v964 = v871->cache_age;
    v964[v1058] = 1;
    int * v966 = v871->cache_age;
    int v967 = v966[v1058];
    int v968 = v966[v988];
    int v1065 = v968 + ((int)((unsigned int)(v968 - v967) >> 31));
    v966[v988] = v1065;
    int * v970 = v871->cache_age;
    int v971 = v970[v989];
    int v1067 = v971 + ((int)((unsigned int)(v971 - v967) >> 31));
    v970[v989] = v1067;
    int * v973 = v871->cache_age;
    v973[v1058] = 0;
    v976 = v1058;
  }
  int v1070 = (v976 * 2) + (((int)((unsigned int)v877 >> 2)) & 1);
  int v977 = v883[v1070];
  int * v978 = v871->reg_ready;
  int v1073 = ((v875 + ((v872 - v875) & (~((v872 - v875) >> 31)))) + 1) + ((100 ^ (((~(((v881 ^ ((int)((unsigned int)((int)((unsigned int)v877 >> 2)) >> 1))) | (-(v881 ^ ((int)((unsigned int)((int)((unsigned int)v877 >> 2)) >> 1))))) >> 31)) | (~(((v882 ^ ((int)((unsigned int)((int)((unsigned int)v877 >> 2)) >> 1))) | (-(v882 ^ ((int)((unsigned int)((int)((unsigned int)v877 >> 2)) >> 1))))) >> 31))) & 104)) ^ (((~(((v879 ^ ((int)((unsigned int)((int)((unsigned int)v877 >> 2)) >> 1))) | (-(v879 ^ ((int)((unsigned int)((int)((unsigned int)v877 >> 2)) >> 1))))) >> 31)) | (~(((v880 ^ ((int)((unsigned int)((int)((unsigned int)v877 >> 2)) >> 1))) | (-(v880 ^ ((int)((unsigned int)((int)((unsigned int)v877 >> 2)) >> 1))))) >> 31))) & (1 ^ (100 ^ (((~(((v881 ^ ((int)((unsigned int)((int)((unsigned int)v877 >> 2)) >> 1))) | (-(v881 ^ ((int)((unsigned int)((int)((unsigned int)v877 >> 2)) >> 1))))) >> 31)) | (~(((v882 ^ ((int)((unsigned int)((int)((unsigned int)v877 >> 2)) >> 1))) | (-(v882 ^ ((int)((unsigned int)((int)((unsigned int)v877 >> 2)) >> 1))))) >> 31))) & 104)))));
  v978[12] = v1073;
  int * v980 = v871->regs;
  v980[12] = v977;
  return v871;
}

struct StateT * slot_1(struct StateT * v24) {
  int v25 = v24->timer;
  int v33 = v25 + 1;
  v24->timer = v33;
  int * v27 = v24->reg_ready;
  v27[9] = v33;
  int * v29 = v24->regs;
  v29[9] = 32;
  struct StateT * v31 = slot_2(v24);
  return v31;
}

struct StateT * slot_8(struct StateT * v642) {
  int v643 = v642->timer;
  int v755 = v643 + 1;
  v642->timer = v755;
  int * v645 = v642->reg_ready;
  int v646 = v645[6];
  int * v647 = v642->regs;
  int v648 = v647[6];
  int * v649 = v642->cache_tags;
  int v760 = (((int)((unsigned int)((int)((unsigned int)v648 >> 2)) >> 1)) & 1) * 2;
  int v650 = v649[v760];
  int v761 = ((((int)((unsigned int)((int)((unsigned int)v648 >> 2)) >> 1)) & 1) * 2) + 1;
  int v651 = v649[v761];
  int v762 = 4 + ((((int)((unsigned int)((int)((unsigned int)v648 >> 2)) >> 1)) & 3) * 2);
  int v652 = v649[v762];
  int v763 = (4 + ((((int)((unsigned int)((int)((unsigned int)v648 >> 2)) >> 1)) & 3) * 2)) + 1;
  int v653 = v649[v763];
  int * v654 = v642->cache_vals;
  bool v764 = !(((~(((v650 ^ ((int)((unsigned int)((int)((unsigned int)v648 >> 2)) >> 1))) | (-(v650 ^ ((int)((unsigned int)((int)((unsigned int)v648 >> 2)) >> 1))))) >> 31)) | (~(((v651 ^ ((int)((unsigned int)((int)((unsigned int)v648 >> 2)) >> 1))) | (-(v651 ^ ((int)((unsigned int)((int)((unsigned int)v648 >> 2)) >> 1))))) >> 31))) == 0);
  int v747;
  if (v764) {
    int * v655 = v642->cache_age;
    int v766 = ((((int)((unsigned int)((int)((unsigned int)v648 >> 2)) >> 1)) & 1) * 2) + ((~(((v651 ^ ((int)((unsigned int)((int)((unsigned int)v648 >> 2)) >> 1))) | (-(v651 ^ ((int)((unsigned int)((int)((unsigned int)v648 >> 2)) >> 1))))) >> 31)) & 1);
    int v656 = v655[v766];
    int v657 = v655[v760];
    int v767 = v657 + ((int)((unsigned int)(v657 - v656) >> 31));
    v655[v760] = v767;
    int * v659 = v642->cache_age;
    int v660 = v659[v761];
    int v769 = v660 + ((int)((unsigned int)(v660 - v656) >> 31));
    v659[v761] = v769;
    int * v662 = v642->cache_age;
    v662[v766] = 0;
    v747 = v766;
  } else {
    int * v665 = v642->cache_age;
    int v773 = (((int)((unsigned int)((int)((unsigned int)v648 >> 2)) >> 1)) & 1) * 2;
    int v666 = v665[v773];
    int * v667 = v642->cache_tags;
    int v668 = v667[v773];
    int v669 = v665[v761];
    int v670 = v667[v761];
    bool v775 = !(((~(((v652 ^ ((int)((unsigned int)((int)((unsigned int)v648 >> 2)) >> 1))) | (-(v652 ^ ((int)((unsigned int)((int)((unsigned int)v648 >> 2)) >> 1))))) >> 31)) | (~(((v653 ^ ((int)((unsigned int)((int)((unsigned int)v648 >> 2)) >> 1))) | (-(v653 ^ ((int)((unsigned int)((int)((unsigned int)v648 >> 2)) >> 1))))) >> 31))) == 0);
    int v724;
    if (v775) {
      int * v671 = v642->cache_age;
      int v777 = (4 + ((((int)((unsigned int)((int)((unsigned int)v648 >> 2)) >> 1)) & 3) * 2)) + ((~(((v653 ^ ((int)((unsigned int)((int)((unsigned int)v648 >> 2)) >> 1))) | (-(v653 ^ ((int)((unsigned int)((int)((unsigned int)v648 >> 2)) >> 1))))) >> 31)) & 1);
      int v672 = v671[v777];
      int v673 = v671[v762];
      int v778 = v673 + ((int)((unsigned int)(v673 - v672) >> 31));
      v671[v762] = v778;
      int * v675 = v642->cache_age;
      int v676 = v675[v763];
      int v780 = v676 + ((int)((unsigned int)(v676 - v672) >> 31));
      v675[v763] = v780;
      int * v678 = v642->cache_age;
      v678[v777] = 0;
      v724 = v777;
    } else {
      int * v681 = v642->cache_age;
      int v784 = 4 + ((((int)((unsigned int)((int)((unsigned int)v648 >> 2)) >> 1)) & 3) * 2);
      int v682 = v681[v784];
      int * v683 = v642->cache_tags;
      int v684 = v683[v784];
      int v685 = v681[v763];
      int v686 = v683[v763];
      int * v687 = v642->cache_dirty;
      int v787 = (4 + ((((int)((unsigned int)((int)((unsigned int)v648 >> 2)) >> 1)) & 3) * 2)) + ((((v682 + ((~(((v684 ^ -1) | (-(v684 ^ -1))) >> 31)) & 2)) - (v685 + ((~(((v686 ^ -1) | (-(v686 ^ -1))) >> 31)) & 2))) >> 31) & 1);
      int v688 = v687[v787];
      bool v788 = !(v688 == 0);
      if (v788) {
        int * v689 = v642->cache_tags;
        int v690 = v689[v787];
        int * v691 = v642->cache_vals;
        int v791 = ((4 + ((((int)((unsigned int)((int)((unsigned int)v648 >> 2)) >> 1)) & 3) * 2)) + ((((v682 + ((~(((v684 ^ -1) | (-(v684 ^ -1))) >> 31)) & 2)) - (v685 + ((~(((v686 ^ -1) | (-(v686 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
        int v692 = v691[v791];
        int v792 = (((4 + ((((int)((unsigned int)((int)((unsigned int)v648 >> 2)) >> 1)) & 3) * 2)) + ((((v682 + ((~(((v684 ^ -1) | (-(v684 ^ -1))) >> 31)) & 2)) - (v685 + ((~(((v686 ^ -1) | (-(v686 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
        int v693 = v691[v792];
        int * v694 = v642->mem;
        int v794 = v690 * 2;
        v694[v794] = v692;
        int * v696 = v642->mem;
        int v797 = (v690 * 2) + 1;
        v696[v797] = v693;
        ;
      } else {
        ;
      }
      int * v701 = v642->mem;
      int v802 = ((int)((unsigned int)((int)((unsigned int)v648 >> 2)) >> 1)) * 2;
      int v702 = v701[v802];
      int v803 = (((int)((unsigned int)((int)((unsigned int)v648 >> 2)) >> 1)) * 2) + 1;
      int v703 = v701[v803];
      int * v704 = v642->cache_vals;
      int v805 = ((4 + ((((int)((unsigned int)((int)((unsigned int)v648 >> 2)) >> 1)) & 3) * 2)) + ((((v682 + ((~(((v684 ^ -1) | (-(v684 ^ -1))) >> 31)) & 2)) - (v685 + ((~(((v686 ^ -1) | (-(v686 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
      v704[v805] = v702;
      int * v706 = v642->cache_vals;
      int v808 = (((4 + ((((int)((unsigned int)((int)((unsigned int)v648 >> 2)) >> 1)) & 3) * 2)) + ((((v682 + ((~(((v684 ^ -1) | (-(v684 ^ -1))) >> 31)) & 2)) - (v685 + ((~(((v686 ^ -1) | (-(v686 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
      v706[v808] = v703;
      int * v708 = v642->cache_tags;
      int v811 = (int)((unsigned int)((int)((unsigned int)v648 >> 2)) >> 1);
      v708[v787] = v811;
      int * v710 = v642->cache_dirty;
      v710[v787] = 0;
      int * v712 = v642->cache_age;
      v712[v787] = 1;
      int * v714 = v642->cache_age;
      int v715 = v714[v787];
      int v716 = v714[v762];
      int v817 = v716 + ((int)((unsigned int)(v716 - v715) >> 31));
      v714[v762] = v817;
      int * v718 = v642->cache_age;
      int v719 = v718[v763];
      int v819 = v719 + ((int)((unsigned int)(v719 - v715) >> 31));
      v718[v763] = v819;
      int * v721 = v642->cache_age;
      v721[v787] = 0;
      v724 = v787;
    }
    int * v725 = v642->cache_vals;
    int v822 = v724 * 2;
    int v726 = v725[v822];
    int v823 = (v724 * 2) + 1;
    int v727 = v725[v823];
    int v824 = (((((int)((unsigned int)((int)((unsigned int)v648 >> 2)) >> 1)) & 1) * 2) + ((((v666 + ((~(((v668 ^ -1) | (-(v668 ^ -1))) >> 31)) & 2)) - (v669 + ((~(((v670 ^ -1) | (-(v670 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
    v725[v824] = v726;
    int * v729 = v642->cache_vals;
    int v827 = ((((((int)((unsigned int)((int)((unsigned int)v648 >> 2)) >> 1)) & 1) * 2) + ((((v666 + ((~(((v668 ^ -1) | (-(v668 ^ -1))) >> 31)) & 2)) - (v669 + ((~(((v670 ^ -1) | (-(v670 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
    v729[v827] = v727;
    int * v731 = v642->cache_tags;
    int v830 = ((((int)((unsigned int)((int)((unsigned int)v648 >> 2)) >> 1)) & 1) * 2) + ((((v666 + ((~(((v668 ^ -1) | (-(v668 ^ -1))) >> 31)) & 2)) - (v669 + ((~(((v670 ^ -1) | (-(v670 ^ -1))) >> 31)) & 2))) >> 31) & 1);
    int v831 = (int)((unsigned int)((int)((unsigned int)v648 >> 2)) >> 1);
    v731[v830] = v831;
    int * v733 = v642->cache_dirty;
    v733[v830] = 0;
    int * v735 = v642->cache_age;
    v735[v830] = 1;
    int * v737 = v642->cache_age;
    int v738 = v737[v830];
    int v739 = v737[v760];
    int v837 = v739 + ((int)((unsigned int)(v739 - v738) >> 31));
    v737[v760] = v837;
    int * v741 = v642->cache_age;
    int v742 = v741[v761];
    int v839 = v742 + ((int)((unsigned int)(v742 - v738) >> 31));
    v741[v761] = v839;
    int * v744 = v642->cache_age;
    v744[v830] = 0;
    v747 = v830;
  }
  int v842 = (v747 * 2) + (((int)((unsigned int)v648 >> 2)) & 1);
  int v748 = v654[v842];
  int * v749 = v642->reg_ready;
  int v845 = ((v646 + ((v643 - v646) & (~((v643 - v646) >> 31)))) + 1) + ((100 ^ (((~(((v652 ^ ((int)((unsigned int)((int)((unsigned int)v648 >> 2)) >> 1))) | (-(v652 ^ ((int)((unsigned int)((int)((unsigned int)v648 >> 2)) >> 1))))) >> 31)) | (~(((v653 ^ ((int)((unsigned int)((int)((unsigned int)v648 >> 2)) >> 1))) | (-(v653 ^ ((int)((unsigned int)((int)((unsigned int)v648 >> 2)) >> 1))))) >> 31))) & 104)) ^ (((~(((v650 ^ ((int)((unsigned int)((int)((unsigned int)v648 >> 2)) >> 1))) | (-(v650 ^ ((int)((unsigned int)((int)((unsigned int)v648 >> 2)) >> 1))))) >> 31)) | (~(((v651 ^ ((int)((unsigned int)((int)((unsigned int)v648 >> 2)) >> 1))) | (-(v651 ^ ((int)((unsigned int)((int)((unsigned int)v648 >> 2)) >> 1))))) >> 31))) & (1 ^ (100 ^ (((~(((v652 ^ ((int)((unsigned int)((int)((unsigned int)v648 >> 2)) >> 1))) | (-(v652 ^ ((int)((unsigned int)((int)((unsigned int)v648 >> 2)) >> 1))))) >> 31)) | (~(((v653 ^ ((int)((unsigned int)((int)((unsigned int)v648 >> 2)) >> 1))) | (-(v653 ^ ((int)((unsigned int)((int)((unsigned int)v648 >> 2)) >> 1))))) >> 31))) & 104)))));
  v749[11] = v845;
  int * v751 = v642->regs;
  v751[11] = v748;
  struct StateT * v753 = slot_9(v642);
  return v753;
}

struct StateT * slot_4(struct StateT * v77) {
  int * v78 = v77->saved_regs;
  int * v79 = v77->regs;
  int v80 = v79[7];
  v78[7] = v80;
  int v82 = v77->timer;
  int v94 = v82 + 1;
  v77->timer = v94;
  int * v84 = v77->reg_ready;
  v84[7] = v94;
  int * v86 = v77->regs;
  v86[7] = 0;
  struct StateT * v88 = slot_5(v77);
  return v88;
}

struct StateT * slot_9(struct StateT * v850) {
  int v851 = v850->timer;
  int v862 = v851 + 1;
  v850->timer = v862;
  int * v853 = v850->reg_ready;
  int v854 = v853[11];
  int * v855 = v850->regs;
  int v856 = v855[11];
  int v866 = (v854 + ((v851 - v854) & (~((v851 - v854) >> 31)))) + 1;
  v853[11] = v866;
  int * v858 = v850->regs;
  int v868 = v856 << 2;
  v858[11] = v868;
  struct StateT * v860 = slot_10(v850);
  return v860;
}

struct StateT * slot_0(struct StateT * v2) {
  int v3 = v2->timer;
  int v14 = v3 + 1;
  v2->timer = v14;
  int * v5 = v2->reg_ready;
  int v6 = v5[10];
  int * v7 = v2->regs;
  int v8 = v7[10];
  int v19 = (v6 + ((v3 - v6) & (~((v3 - v6) >> 31)))) + 1;
  v5[5] = v19;
  int * v10 = v2->regs;
  int v21 = v8 & 28;
  v10[5] = v21;
  struct StateT * v12 = slot_1(v2);
  return v12;
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
  koika_assert(s1_->timer==s2_->timer, "timing leak");
  return 0;
}