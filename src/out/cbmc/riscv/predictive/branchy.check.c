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
#else
#define koika_assert(b, s) 0
#define koika_assume(b) 0
#define koika_draw(x) ((x) = 0)
#endif
int bounded(int low, int high) {
  int x;
  koika_draw(x);
  koika_assume(low <= x && x <= high);
  return x;
}

/*****************************************
Emitting C Generated Code
*******************************************/

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

struct StateT {
  int regs[32];
  int mem[64];
  int saved_regs[32];
  int cache_tags[12];
  int cache_dirty[12];
  int cache_age[12];
  int cache_vals[24];
  int timer;
};

struct StateT * slot_12(struct StateT * v890);
struct StateT * slot_6(struct StateT * v321);
struct StateT * slot_16(struct StateT * v959);
struct StateT * slot_5(struct StateT * v305);
struct StateT * slot_2(struct StateT * v252);
struct StateT * slot_7(struct StateT * v571);
struct StateT * slot_21(struct StateT * v1278);
struct StateT * slot_3(struct StateT * v272);
struct StateT * slot_10(struct StateT * v624);
struct StateT * slot_1(struct StateT * v15);
struct StateT * slot_19(struct StateT * v1246);
struct StateT * slot_13(struct StateT * v910);
struct StateT * slot_0(struct StateT * v2);
struct StateT * slot_14(struct StateT * v927);
struct StateT * slot_17(struct StateT * v1209);
struct StateT * slot_20(struct StateT * v1262);
struct StateT * snippet(struct StateT * v0);
struct StateT * slot_8(struct StateT * v591);
struct StateT * slot_4(struct StateT * v289);
struct StateT * slot_15(struct StateT * v943);
struct StateT * slot_18(struct StateT * v1229);
struct StateT * slot_9(struct StateT * v608);
struct StateT * slot_22(struct StateT * v1528);
struct StateT * slot_11(struct StateT * v640);
struct StateT * slot_12(struct StateT * v890) {
  int v891 = v890->timer;
  int v901 = v891 + 1;
  v890->timer = v901;
  int * v893 = v890->regs;
  int v894 = v893[5];
  int * v895 = v890->regs;
  int v896 = v895[7];
  int * v897 = v890->regs;
  int v907 = v894 ^ v896;
  v897[5] = v907;
  struct StateT * v899 = slot_13(v890);
  return v899;
}

struct StateT * slot_6(struct StateT * v321) {
  int v322 = v321->timer;
  int v455 = v322 + 1;
  v321->timer = v455;
  int * v324 = v321->regs;
  int v325 = v324[6];
  int * v326 = v321->cache_tags;
  int v459 = (((int)((unsigned int)((int)((unsigned int)v325 >> 2)) >> 1)) & 1) * 2;
  int v327 = v326[v459];
  int * v328 = v321->cache_tags;
  int v461 = ((((int)((unsigned int)((int)((unsigned int)v325 >> 2)) >> 1)) & 1) * 2) + 1;
  int v329 = v328[v461];
  int * v330 = v321->cache_tags;
  int v463 = 4 + ((((int)((unsigned int)((int)((unsigned int)v325 >> 2)) >> 1)) & 3) * 2);
  int v331 = v330[v463];
  int * v332 = v321->cache_tags;
  int v465 = (4 + ((((int)((unsigned int)((int)((unsigned int)v325 >> 2)) >> 1)) & 3) * 2)) + 1;
  int v333 = v332[v465];
  int v334 = v321->timer;
  int v466 = v334 + ((100 ^ (((~(((v331 ^ ((int)((unsigned int)((int)((unsigned int)v325 >> 2)) >> 1))) | (-(v331 ^ ((int)((unsigned int)((int)((unsigned int)v325 >> 2)) >> 1))))) >> 31)) | (~(((v333 ^ ((int)((unsigned int)((int)((unsigned int)v325 >> 2)) >> 1))) | (-(v333 ^ ((int)((unsigned int)((int)((unsigned int)v325 >> 2)) >> 1))))) >> 31))) & 104)) ^ (((~(((v327 ^ ((int)((unsigned int)((int)((unsigned int)v325 >> 2)) >> 1))) | (-(v327 ^ ((int)((unsigned int)((int)((unsigned int)v325 >> 2)) >> 1))))) >> 31)) | (~(((v329 ^ ((int)((unsigned int)((int)((unsigned int)v325 >> 2)) >> 1))) | (-(v329 ^ ((int)((unsigned int)((int)((unsigned int)v325 >> 2)) >> 1))))) >> 31))) & (1 ^ (100 ^ (((~(((v331 ^ ((int)((unsigned int)((int)((unsigned int)v325 >> 2)) >> 1))) | (-(v331 ^ ((int)((unsigned int)((int)((unsigned int)v325 >> 2)) >> 1))))) >> 31)) | (~(((v333 ^ ((int)((unsigned int)((int)((unsigned int)v325 >> 2)) >> 1))) | (-(v333 ^ ((int)((unsigned int)((int)((unsigned int)v325 >> 2)) >> 1))))) >> 31))) & 104)))));
  v321->timer = v466;
  int * v336 = v321->cache_vals;
  bool v467 = !(((~(((v327 ^ ((int)((unsigned int)((int)((unsigned int)v325 >> 2)) >> 1))) | (-(v327 ^ ((int)((unsigned int)((int)((unsigned int)v325 >> 2)) >> 1))))) >> 31)) | (~(((v329 ^ ((int)((unsigned int)((int)((unsigned int)v325 >> 2)) >> 1))) | (-(v329 ^ ((int)((unsigned int)((int)((unsigned int)v325 >> 2)) >> 1))))) >> 31))) == 0);
  int v449;
  if (v467) {
    int * v337 = v321->cache_age;
    int v469 = ((((int)((unsigned int)((int)((unsigned int)v325 >> 2)) >> 1)) & 1) * 2) + ((~(((v329 ^ ((int)((unsigned int)((int)((unsigned int)v325 >> 2)) >> 1))) | (-(v329 ^ ((int)((unsigned int)((int)((unsigned int)v325 >> 2)) >> 1))))) >> 31)) & 1);
    int v338 = v337[v469];
    int * v339 = v321->cache_age;
    int v340 = v339[v459];
    int * v341 = v321->cache_age;
    int v472 = v340 + ((int)((unsigned int)(v340 - v338) >> 31));
    v341[v459] = v472;
    int * v343 = v321->cache_age;
    int v344 = v343[v461];
    int * v345 = v321->cache_age;
    int v475 = v344 + ((int)((unsigned int)(v344 - v338) >> 31));
    v345[v461] = v475;
    int * v347 = v321->cache_age;
    v347[v469] = 0;
    v449 = v469;
  } else {
    int * v350 = v321->cache_age;
    int v479 = (((int)((unsigned int)((int)((unsigned int)v325 >> 2)) >> 1)) & 1) * 2;
    int v351 = v350[v479];
    int * v352 = v321->cache_tags;
    int v353 = v352[v479];
    int * v354 = v321->cache_age;
    int v355 = v354[v461];
    int * v356 = v321->cache_tags;
    int v357 = v356[v461];
    bool v483 = !(((~(((v331 ^ ((int)((unsigned int)((int)((unsigned int)v325 >> 2)) >> 1))) | (-(v331 ^ ((int)((unsigned int)((int)((unsigned int)v325 >> 2)) >> 1))))) >> 31)) | (~(((v333 ^ ((int)((unsigned int)((int)((unsigned int)v325 >> 2)) >> 1))) | (-(v333 ^ ((int)((unsigned int)((int)((unsigned int)v325 >> 2)) >> 1))))) >> 31))) == 0);
    int v421;
    if (v483) {
      int * v358 = v321->cache_age;
      int v485 = (4 + ((((int)((unsigned int)((int)((unsigned int)v325 >> 2)) >> 1)) & 3) * 2)) + ((~(((v333 ^ ((int)((unsigned int)((int)((unsigned int)v325 >> 2)) >> 1))) | (-(v333 ^ ((int)((unsigned int)((int)((unsigned int)v325 >> 2)) >> 1))))) >> 31)) & 1);
      int v359 = v358[v485];
      int * v360 = v321->cache_age;
      int v361 = v360[v463];
      int * v362 = v321->cache_age;
      int v488 = v361 + ((int)((unsigned int)(v361 - v359) >> 31));
      v362[v463] = v488;
      int * v364 = v321->cache_age;
      int v365 = v364[v465];
      int * v366 = v321->cache_age;
      int v491 = v365 + ((int)((unsigned int)(v365 - v359) >> 31));
      v366[v465] = v491;
      int * v368 = v321->cache_age;
      v368[v485] = 0;
      v421 = v485;
    } else {
      int * v371 = v321->cache_age;
      int v495 = 4 + ((((int)((unsigned int)((int)((unsigned int)v325 >> 2)) >> 1)) & 3) * 2);
      int v372 = v371[v495];
      int * v373 = v321->cache_tags;
      int v374 = v373[v495];
      int * v375 = v321->cache_age;
      int v376 = v375[v465];
      int * v377 = v321->cache_tags;
      int v378 = v377[v465];
      int * v379 = v321->cache_dirty;
      int v500 = (4 + ((((int)((unsigned int)((int)((unsigned int)v325 >> 2)) >> 1)) & 3) * 2)) + ((((v372 + ((~(((v374 ^ -1) | (-(v374 ^ -1))) >> 31)) & 2)) - (v376 + ((~(((v378 ^ -1) | (-(v378 ^ -1))) >> 31)) & 2))) >> 31) & 1);
      int v380 = v379[v500];
      bool v501 = !(v380 == 0);
      if (v501) {
        int * v381 = v321->cache_tags;
        int v382 = v381[v500];
        int * v383 = v321->cache_vals;
        int v504 = ((4 + ((((int)((unsigned int)((int)((unsigned int)v325 >> 2)) >> 1)) & 3) * 2)) + ((((v372 + ((~(((v374 ^ -1) | (-(v374 ^ -1))) >> 31)) & 2)) - (v376 + ((~(((v378 ^ -1) | (-(v378 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
        int v384 = v383[v504];
        int * v385 = v321->cache_vals;
        int v506 = (((4 + ((((int)((unsigned int)((int)((unsigned int)v325 >> 2)) >> 1)) & 3) * 2)) + ((((v372 + ((~(((v374 ^ -1) | (-(v374 ^ -1))) >> 31)) & 2)) - (v376 + ((~(((v378 ^ -1) | (-(v378 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
        int v386 = v385[v506];
        int * v387 = v321->mem;
        int v508 = v382 * 2;
        v387[v508] = v384;
        int * v389 = v321->mem;
        int v511 = (v382 * 2) + 1;
        v389[v511] = v386;
        ;
      } else {
        ;
      }
      int * v394 = v321->mem;
      int v516 = ((int)((unsigned int)((int)((unsigned int)v325 >> 2)) >> 1)) * 2;
      int v395 = v394[v516];
      int * v396 = v321->mem;
      int v518 = (((int)((unsigned int)((int)((unsigned int)v325 >> 2)) >> 1)) * 2) + 1;
      int v397 = v396[v518];
      int * v398 = v321->cache_vals;
      int v520 = ((4 + ((((int)((unsigned int)((int)((unsigned int)v325 >> 2)) >> 1)) & 3) * 2)) + ((((v372 + ((~(((v374 ^ -1) | (-(v374 ^ -1))) >> 31)) & 2)) - (v376 + ((~(((v378 ^ -1) | (-(v378 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
      v398[v520] = v395;
      int * v400 = v321->cache_vals;
      int v523 = (((4 + ((((int)((unsigned int)((int)((unsigned int)v325 >> 2)) >> 1)) & 3) * 2)) + ((((v372 + ((~(((v374 ^ -1) | (-(v374 ^ -1))) >> 31)) & 2)) - (v376 + ((~(((v378 ^ -1) | (-(v378 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
      v400[v523] = v397;
      int * v402 = v321->cache_tags;
      int v526 = (int)((unsigned int)((int)((unsigned int)v325 >> 2)) >> 1);
      v402[v500] = v526;
      int * v404 = v321->cache_dirty;
      v404[v500] = 0;
      int * v406 = v321->cache_age;
      v406[v500] = 1;
      int * v408 = v321->cache_age;
      int v409 = v408[v500];
      int * v410 = v321->cache_age;
      int v411 = v410[v463];
      int * v412 = v321->cache_age;
      int v534 = v411 + ((int)((unsigned int)(v411 - v409) >> 31));
      v412[v463] = v534;
      int * v414 = v321->cache_age;
      int v415 = v414[v465];
      int * v416 = v321->cache_age;
      int v537 = v415 + ((int)((unsigned int)(v415 - v409) >> 31));
      v416[v465] = v537;
      int * v418 = v321->cache_age;
      v418[v500] = 0;
      v421 = v500;
    }
    int * v422 = v321->cache_vals;
    int v540 = v421 * 2;
    int v423 = v422[v540];
    int * v424 = v321->cache_vals;
    int v542 = (v421 * 2) + 1;
    int v425 = v424[v542];
    int * v426 = v321->cache_vals;
    int v544 = (((((int)((unsigned int)((int)((unsigned int)v325 >> 2)) >> 1)) & 1) * 2) + ((((v351 + ((~(((v353 ^ -1) | (-(v353 ^ -1))) >> 31)) & 2)) - (v355 + ((~(((v357 ^ -1) | (-(v357 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
    v426[v544] = v423;
    int * v428 = v321->cache_vals;
    int v547 = ((((((int)((unsigned int)((int)((unsigned int)v325 >> 2)) >> 1)) & 1) * 2) + ((((v351 + ((~(((v353 ^ -1) | (-(v353 ^ -1))) >> 31)) & 2)) - (v355 + ((~(((v357 ^ -1) | (-(v357 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
    v428[v547] = v425;
    int * v430 = v321->cache_tags;
    int v550 = ((((int)((unsigned int)((int)((unsigned int)v325 >> 2)) >> 1)) & 1) * 2) + ((((v351 + ((~(((v353 ^ -1) | (-(v353 ^ -1))) >> 31)) & 2)) - (v355 + ((~(((v357 ^ -1) | (-(v357 ^ -1))) >> 31)) & 2))) >> 31) & 1);
    int v551 = (int)((unsigned int)((int)((unsigned int)v325 >> 2)) >> 1);
    v430[v550] = v551;
    int * v432 = v321->cache_dirty;
    v432[v550] = 0;
    int * v434 = v321->cache_age;
    v434[v550] = 1;
    int * v436 = v321->cache_age;
    int v437 = v436[v550];
    int * v438 = v321->cache_age;
    int v439 = v438[v459];
    int * v440 = v321->cache_age;
    int v559 = v439 + ((int)((unsigned int)(v439 - v437) >> 31));
    v440[v459] = v559;
    int * v442 = v321->cache_age;
    int v443 = v442[v461];
    int * v444 = v321->cache_age;
    int v562 = v443 + ((int)((unsigned int)(v443 - v437) >> 31));
    v444[v461] = v562;
    int * v446 = v321->cache_age;
    v446[v550] = 0;
    v449 = v550;
  }
  int v565 = (v449 * 2) + (((int)((unsigned int)v325 >> 2)) & 1);
  int v450 = v336[v565];
  int * v451 = v321->regs;
  v451[7] = v450;
  struct StateT * v453 = slot_7(v321);
  return v453;
}

struct StateT * slot_16(struct StateT * v959) {
  int v960 = v959->timer;
  int v1093 = v960 + 1;
  v959->timer = v1093;
  int * v962 = v959->regs;
  int v963 = v962[6];
  int * v964 = v959->cache_tags;
  int v1097 = (((int)((unsigned int)((int)((unsigned int)v963 >> 2)) >> 1)) & 1) * 2;
  int v965 = v964[v1097];
  int * v966 = v959->cache_tags;
  int v1099 = ((((int)((unsigned int)((int)((unsigned int)v963 >> 2)) >> 1)) & 1) * 2) + 1;
  int v967 = v966[v1099];
  int * v968 = v959->cache_tags;
  int v1101 = 4 + ((((int)((unsigned int)((int)((unsigned int)v963 >> 2)) >> 1)) & 3) * 2);
  int v969 = v968[v1101];
  int * v970 = v959->cache_tags;
  int v1103 = (4 + ((((int)((unsigned int)((int)((unsigned int)v963 >> 2)) >> 1)) & 3) * 2)) + 1;
  int v971 = v970[v1103];
  int v972 = v959->timer;
  int v1104 = v972 + ((100 ^ (((~(((v969 ^ ((int)((unsigned int)((int)((unsigned int)v963 >> 2)) >> 1))) | (-(v969 ^ ((int)((unsigned int)((int)((unsigned int)v963 >> 2)) >> 1))))) >> 31)) | (~(((v971 ^ ((int)((unsigned int)((int)((unsigned int)v963 >> 2)) >> 1))) | (-(v971 ^ ((int)((unsigned int)((int)((unsigned int)v963 >> 2)) >> 1))))) >> 31))) & 104)) ^ (((~(((v965 ^ ((int)((unsigned int)((int)((unsigned int)v963 >> 2)) >> 1))) | (-(v965 ^ ((int)((unsigned int)((int)((unsigned int)v963 >> 2)) >> 1))))) >> 31)) | (~(((v967 ^ ((int)((unsigned int)((int)((unsigned int)v963 >> 2)) >> 1))) | (-(v967 ^ ((int)((unsigned int)((int)((unsigned int)v963 >> 2)) >> 1))))) >> 31))) & (1 ^ (100 ^ (((~(((v969 ^ ((int)((unsigned int)((int)((unsigned int)v963 >> 2)) >> 1))) | (-(v969 ^ ((int)((unsigned int)((int)((unsigned int)v963 >> 2)) >> 1))))) >> 31)) | (~(((v971 ^ ((int)((unsigned int)((int)((unsigned int)v963 >> 2)) >> 1))) | (-(v971 ^ ((int)((unsigned int)((int)((unsigned int)v963 >> 2)) >> 1))))) >> 31))) & 104)))));
  v959->timer = v1104;
  int * v974 = v959->cache_vals;
  bool v1105 = !(((~(((v965 ^ ((int)((unsigned int)((int)((unsigned int)v963 >> 2)) >> 1))) | (-(v965 ^ ((int)((unsigned int)((int)((unsigned int)v963 >> 2)) >> 1))))) >> 31)) | (~(((v967 ^ ((int)((unsigned int)((int)((unsigned int)v963 >> 2)) >> 1))) | (-(v967 ^ ((int)((unsigned int)((int)((unsigned int)v963 >> 2)) >> 1))))) >> 31))) == 0);
  int v1087;
  if (v1105) {
    int * v975 = v959->cache_age;
    int v1107 = ((((int)((unsigned int)((int)((unsigned int)v963 >> 2)) >> 1)) & 1) * 2) + ((~(((v967 ^ ((int)((unsigned int)((int)((unsigned int)v963 >> 2)) >> 1))) | (-(v967 ^ ((int)((unsigned int)((int)((unsigned int)v963 >> 2)) >> 1))))) >> 31)) & 1);
    int v976 = v975[v1107];
    int * v977 = v959->cache_age;
    int v978 = v977[v1097];
    int * v979 = v959->cache_age;
    int v1110 = v978 + ((int)((unsigned int)(v978 - v976) >> 31));
    v979[v1097] = v1110;
    int * v981 = v959->cache_age;
    int v982 = v981[v1099];
    int * v983 = v959->cache_age;
    int v1113 = v982 + ((int)((unsigned int)(v982 - v976) >> 31));
    v983[v1099] = v1113;
    int * v985 = v959->cache_age;
    v985[v1107] = 0;
    v1087 = v1107;
  } else {
    int * v988 = v959->cache_age;
    int v1117 = (((int)((unsigned int)((int)((unsigned int)v963 >> 2)) >> 1)) & 1) * 2;
    int v989 = v988[v1117];
    int * v990 = v959->cache_tags;
    int v991 = v990[v1117];
    int * v992 = v959->cache_age;
    int v993 = v992[v1099];
    int * v994 = v959->cache_tags;
    int v995 = v994[v1099];
    bool v1121 = !(((~(((v969 ^ ((int)((unsigned int)((int)((unsigned int)v963 >> 2)) >> 1))) | (-(v969 ^ ((int)((unsigned int)((int)((unsigned int)v963 >> 2)) >> 1))))) >> 31)) | (~(((v971 ^ ((int)((unsigned int)((int)((unsigned int)v963 >> 2)) >> 1))) | (-(v971 ^ ((int)((unsigned int)((int)((unsigned int)v963 >> 2)) >> 1))))) >> 31))) == 0);
    int v1059;
    if (v1121) {
      int * v996 = v959->cache_age;
      int v1123 = (4 + ((((int)((unsigned int)((int)((unsigned int)v963 >> 2)) >> 1)) & 3) * 2)) + ((~(((v971 ^ ((int)((unsigned int)((int)((unsigned int)v963 >> 2)) >> 1))) | (-(v971 ^ ((int)((unsigned int)((int)((unsigned int)v963 >> 2)) >> 1))))) >> 31)) & 1);
      int v997 = v996[v1123];
      int * v998 = v959->cache_age;
      int v999 = v998[v1101];
      int * v1000 = v959->cache_age;
      int v1126 = v999 + ((int)((unsigned int)(v999 - v997) >> 31));
      v1000[v1101] = v1126;
      int * v1002 = v959->cache_age;
      int v1003 = v1002[v1103];
      int * v1004 = v959->cache_age;
      int v1129 = v1003 + ((int)((unsigned int)(v1003 - v997) >> 31));
      v1004[v1103] = v1129;
      int * v1006 = v959->cache_age;
      v1006[v1123] = 0;
      v1059 = v1123;
    } else {
      int * v1009 = v959->cache_age;
      int v1133 = 4 + ((((int)((unsigned int)((int)((unsigned int)v963 >> 2)) >> 1)) & 3) * 2);
      int v1010 = v1009[v1133];
      int * v1011 = v959->cache_tags;
      int v1012 = v1011[v1133];
      int * v1013 = v959->cache_age;
      int v1014 = v1013[v1103];
      int * v1015 = v959->cache_tags;
      int v1016 = v1015[v1103];
      int * v1017 = v959->cache_dirty;
      int v1138 = (4 + ((((int)((unsigned int)((int)((unsigned int)v963 >> 2)) >> 1)) & 3) * 2)) + ((((v1010 + ((~(((v1012 ^ -1) | (-(v1012 ^ -1))) >> 31)) & 2)) - (v1014 + ((~(((v1016 ^ -1) | (-(v1016 ^ -1))) >> 31)) & 2))) >> 31) & 1);
      int v1018 = v1017[v1138];
      bool v1139 = !(v1018 == 0);
      if (v1139) {
        int * v1019 = v959->cache_tags;
        int v1020 = v1019[v1138];
        int * v1021 = v959->cache_vals;
        int v1142 = ((4 + ((((int)((unsigned int)((int)((unsigned int)v963 >> 2)) >> 1)) & 3) * 2)) + ((((v1010 + ((~(((v1012 ^ -1) | (-(v1012 ^ -1))) >> 31)) & 2)) - (v1014 + ((~(((v1016 ^ -1) | (-(v1016 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
        int v1022 = v1021[v1142];
        int * v1023 = v959->cache_vals;
        int v1144 = (((4 + ((((int)((unsigned int)((int)((unsigned int)v963 >> 2)) >> 1)) & 3) * 2)) + ((((v1010 + ((~(((v1012 ^ -1) | (-(v1012 ^ -1))) >> 31)) & 2)) - (v1014 + ((~(((v1016 ^ -1) | (-(v1016 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
        int v1024 = v1023[v1144];
        int * v1025 = v959->mem;
        int v1146 = v1020 * 2;
        v1025[v1146] = v1022;
        int * v1027 = v959->mem;
        int v1149 = (v1020 * 2) + 1;
        v1027[v1149] = v1024;
        ;
      } else {
        ;
      }
      int * v1032 = v959->mem;
      int v1154 = ((int)((unsigned int)((int)((unsigned int)v963 >> 2)) >> 1)) * 2;
      int v1033 = v1032[v1154];
      int * v1034 = v959->mem;
      int v1156 = (((int)((unsigned int)((int)((unsigned int)v963 >> 2)) >> 1)) * 2) + 1;
      int v1035 = v1034[v1156];
      int * v1036 = v959->cache_vals;
      int v1158 = ((4 + ((((int)((unsigned int)((int)((unsigned int)v963 >> 2)) >> 1)) & 3) * 2)) + ((((v1010 + ((~(((v1012 ^ -1) | (-(v1012 ^ -1))) >> 31)) & 2)) - (v1014 + ((~(((v1016 ^ -1) | (-(v1016 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
      v1036[v1158] = v1033;
      int * v1038 = v959->cache_vals;
      int v1161 = (((4 + ((((int)((unsigned int)((int)((unsigned int)v963 >> 2)) >> 1)) & 3) * 2)) + ((((v1010 + ((~(((v1012 ^ -1) | (-(v1012 ^ -1))) >> 31)) & 2)) - (v1014 + ((~(((v1016 ^ -1) | (-(v1016 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
      v1038[v1161] = v1035;
      int * v1040 = v959->cache_tags;
      int v1164 = (int)((unsigned int)((int)((unsigned int)v963 >> 2)) >> 1);
      v1040[v1138] = v1164;
      int * v1042 = v959->cache_dirty;
      v1042[v1138] = 0;
      int * v1044 = v959->cache_age;
      v1044[v1138] = 1;
      int * v1046 = v959->cache_age;
      int v1047 = v1046[v1138];
      int * v1048 = v959->cache_age;
      int v1049 = v1048[v1101];
      int * v1050 = v959->cache_age;
      int v1172 = v1049 + ((int)((unsigned int)(v1049 - v1047) >> 31));
      v1050[v1101] = v1172;
      int * v1052 = v959->cache_age;
      int v1053 = v1052[v1103];
      int * v1054 = v959->cache_age;
      int v1175 = v1053 + ((int)((unsigned int)(v1053 - v1047) >> 31));
      v1054[v1103] = v1175;
      int * v1056 = v959->cache_age;
      v1056[v1138] = 0;
      v1059 = v1138;
    }
    int * v1060 = v959->cache_vals;
    int v1178 = v1059 * 2;
    int v1061 = v1060[v1178];
    int * v1062 = v959->cache_vals;
    int v1180 = (v1059 * 2) + 1;
    int v1063 = v1062[v1180];
    int * v1064 = v959->cache_vals;
    int v1182 = (((((int)((unsigned int)((int)((unsigned int)v963 >> 2)) >> 1)) & 1) * 2) + ((((v989 + ((~(((v991 ^ -1) | (-(v991 ^ -1))) >> 31)) & 2)) - (v993 + ((~(((v995 ^ -1) | (-(v995 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
    v1064[v1182] = v1061;
    int * v1066 = v959->cache_vals;
    int v1185 = ((((((int)((unsigned int)((int)((unsigned int)v963 >> 2)) >> 1)) & 1) * 2) + ((((v989 + ((~(((v991 ^ -1) | (-(v991 ^ -1))) >> 31)) & 2)) - (v993 + ((~(((v995 ^ -1) | (-(v995 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
    v1066[v1185] = v1063;
    int * v1068 = v959->cache_tags;
    int v1188 = ((((int)((unsigned int)((int)((unsigned int)v963 >> 2)) >> 1)) & 1) * 2) + ((((v989 + ((~(((v991 ^ -1) | (-(v991 ^ -1))) >> 31)) & 2)) - (v993 + ((~(((v995 ^ -1) | (-(v995 ^ -1))) >> 31)) & 2))) >> 31) & 1);
    int v1189 = (int)((unsigned int)((int)((unsigned int)v963 >> 2)) >> 1);
    v1068[v1188] = v1189;
    int * v1070 = v959->cache_dirty;
    v1070[v1188] = 0;
    int * v1072 = v959->cache_age;
    v1072[v1188] = 1;
    int * v1074 = v959->cache_age;
    int v1075 = v1074[v1188];
    int * v1076 = v959->cache_age;
    int v1077 = v1076[v1097];
    int * v1078 = v959->cache_age;
    int v1197 = v1077 + ((int)((unsigned int)(v1077 - v1075) >> 31));
    v1078[v1097] = v1197;
    int * v1080 = v959->cache_age;
    int v1081 = v1080[v1099];
    int * v1082 = v959->cache_age;
    int v1200 = v1081 + ((int)((unsigned int)(v1081 - v1075) >> 31));
    v1082[v1099] = v1200;
    int * v1084 = v959->cache_age;
    v1084[v1188] = 0;
    v1087 = v1188;
  }
  int v1203 = (v1087 * 2) + (((int)((unsigned int)v963 >> 2)) & 1);
  int v1088 = v974[v1203];
  int * v1089 = v959->regs;
  v1089[7] = v1088;
  struct StateT * v1091 = slot_17(v959);
  return v1091;
}

struct StateT * slot_5(struct StateT * v305) {
  int v306 = v305->timer;
  int v314 = v306 + 1;
  v305->timer = v314;
  int * v308 = v305->regs;
  int v309 = v308[6];
  int * v310 = v305->regs;
  int v318 = v309 << 2;
  v310[6] = v318;
  struct StateT * v312 = slot_6(v305);
  return v312;
}

struct StateT * slot_2(struct StateT * v252) {
  int v253 = v252->timer;
  int v263 = v253 + 1;
  v252->timer = v263;
  int * v255 = v252->regs;
  int v256 = v255[5];
  int * v257 = v252->regs;
  int v258 = v257[9];
  int * v259 = v252->regs;
  int v269 = v256 ^ v258;
  v259[5] = v269;
  struct StateT * v261 = slot_3(v252);
  return v261;
}

struct StateT * slot_7(struct StateT * v571) {
  int v572 = v571->timer;
  int v582 = v572 + 1;
  v571->timer = v582;
  int * v574 = v571->regs;
  int v575 = v574[5];
  int * v576 = v571->regs;
  int v577 = v576[7];
  int * v578 = v571->regs;
  int v588 = v575 ^ v577;
  v578[5] = v588;
  struct StateT * v580 = slot_8(v571);
  return v580;
}

struct StateT * slot_21(struct StateT * v1278) {
  int v1279 = v1278->timer;
  int v1412 = v1279 + 1;
  v1278->timer = v1412;
  int * v1281 = v1278->regs;
  int v1282 = v1281[6];
  int * v1283 = v1278->cache_tags;
  int v1416 = (((int)((unsigned int)((int)((unsigned int)v1282 >> 2)) >> 1)) & 1) * 2;
  int v1284 = v1283[v1416];
  int * v1285 = v1278->cache_tags;
  int v1418 = ((((int)((unsigned int)((int)((unsigned int)v1282 >> 2)) >> 1)) & 1) * 2) + 1;
  int v1286 = v1285[v1418];
  int * v1287 = v1278->cache_tags;
  int v1420 = 4 + ((((int)((unsigned int)((int)((unsigned int)v1282 >> 2)) >> 1)) & 3) * 2);
  int v1288 = v1287[v1420];
  int * v1289 = v1278->cache_tags;
  int v1422 = (4 + ((((int)((unsigned int)((int)((unsigned int)v1282 >> 2)) >> 1)) & 3) * 2)) + 1;
  int v1290 = v1289[v1422];
  int v1291 = v1278->timer;
  int v1423 = v1291 + ((100 ^ (((~(((v1288 ^ ((int)((unsigned int)((int)((unsigned int)v1282 >> 2)) >> 1))) | (-(v1288 ^ ((int)((unsigned int)((int)((unsigned int)v1282 >> 2)) >> 1))))) >> 31)) | (~(((v1290 ^ ((int)((unsigned int)((int)((unsigned int)v1282 >> 2)) >> 1))) | (-(v1290 ^ ((int)((unsigned int)((int)((unsigned int)v1282 >> 2)) >> 1))))) >> 31))) & 104)) ^ (((~(((v1284 ^ ((int)((unsigned int)((int)((unsigned int)v1282 >> 2)) >> 1))) | (-(v1284 ^ ((int)((unsigned int)((int)((unsigned int)v1282 >> 2)) >> 1))))) >> 31)) | (~(((v1286 ^ ((int)((unsigned int)((int)((unsigned int)v1282 >> 2)) >> 1))) | (-(v1286 ^ ((int)((unsigned int)((int)((unsigned int)v1282 >> 2)) >> 1))))) >> 31))) & (1 ^ (100 ^ (((~(((v1288 ^ ((int)((unsigned int)((int)((unsigned int)v1282 >> 2)) >> 1))) | (-(v1288 ^ ((int)((unsigned int)((int)((unsigned int)v1282 >> 2)) >> 1))))) >> 31)) | (~(((v1290 ^ ((int)((unsigned int)((int)((unsigned int)v1282 >> 2)) >> 1))) | (-(v1290 ^ ((int)((unsigned int)((int)((unsigned int)v1282 >> 2)) >> 1))))) >> 31))) & 104)))));
  v1278->timer = v1423;
  int * v1293 = v1278->cache_vals;
  bool v1424 = !(((~(((v1284 ^ ((int)((unsigned int)((int)((unsigned int)v1282 >> 2)) >> 1))) | (-(v1284 ^ ((int)((unsigned int)((int)((unsigned int)v1282 >> 2)) >> 1))))) >> 31)) | (~(((v1286 ^ ((int)((unsigned int)((int)((unsigned int)v1282 >> 2)) >> 1))) | (-(v1286 ^ ((int)((unsigned int)((int)((unsigned int)v1282 >> 2)) >> 1))))) >> 31))) == 0);
  int v1406;
  if (v1424) {
    int * v1294 = v1278->cache_age;
    int v1426 = ((((int)((unsigned int)((int)((unsigned int)v1282 >> 2)) >> 1)) & 1) * 2) + ((~(((v1286 ^ ((int)((unsigned int)((int)((unsigned int)v1282 >> 2)) >> 1))) | (-(v1286 ^ ((int)((unsigned int)((int)((unsigned int)v1282 >> 2)) >> 1))))) >> 31)) & 1);
    int v1295 = v1294[v1426];
    int * v1296 = v1278->cache_age;
    int v1297 = v1296[v1416];
    int * v1298 = v1278->cache_age;
    int v1429 = v1297 + ((int)((unsigned int)(v1297 - v1295) >> 31));
    v1298[v1416] = v1429;
    int * v1300 = v1278->cache_age;
    int v1301 = v1300[v1418];
    int * v1302 = v1278->cache_age;
    int v1432 = v1301 + ((int)((unsigned int)(v1301 - v1295) >> 31));
    v1302[v1418] = v1432;
    int * v1304 = v1278->cache_age;
    v1304[v1426] = 0;
    v1406 = v1426;
  } else {
    int * v1307 = v1278->cache_age;
    int v1436 = (((int)((unsigned int)((int)((unsigned int)v1282 >> 2)) >> 1)) & 1) * 2;
    int v1308 = v1307[v1436];
    int * v1309 = v1278->cache_tags;
    int v1310 = v1309[v1436];
    int * v1311 = v1278->cache_age;
    int v1312 = v1311[v1418];
    int * v1313 = v1278->cache_tags;
    int v1314 = v1313[v1418];
    bool v1440 = !(((~(((v1288 ^ ((int)((unsigned int)((int)((unsigned int)v1282 >> 2)) >> 1))) | (-(v1288 ^ ((int)((unsigned int)((int)((unsigned int)v1282 >> 2)) >> 1))))) >> 31)) | (~(((v1290 ^ ((int)((unsigned int)((int)((unsigned int)v1282 >> 2)) >> 1))) | (-(v1290 ^ ((int)((unsigned int)((int)((unsigned int)v1282 >> 2)) >> 1))))) >> 31))) == 0);
    int v1378;
    if (v1440) {
      int * v1315 = v1278->cache_age;
      int v1442 = (4 + ((((int)((unsigned int)((int)((unsigned int)v1282 >> 2)) >> 1)) & 3) * 2)) + ((~(((v1290 ^ ((int)((unsigned int)((int)((unsigned int)v1282 >> 2)) >> 1))) | (-(v1290 ^ ((int)((unsigned int)((int)((unsigned int)v1282 >> 2)) >> 1))))) >> 31)) & 1);
      int v1316 = v1315[v1442];
      int * v1317 = v1278->cache_age;
      int v1318 = v1317[v1420];
      int * v1319 = v1278->cache_age;
      int v1445 = v1318 + ((int)((unsigned int)(v1318 - v1316) >> 31));
      v1319[v1420] = v1445;
      int * v1321 = v1278->cache_age;
      int v1322 = v1321[v1422];
      int * v1323 = v1278->cache_age;
      int v1448 = v1322 + ((int)((unsigned int)(v1322 - v1316) >> 31));
      v1323[v1422] = v1448;
      int * v1325 = v1278->cache_age;
      v1325[v1442] = 0;
      v1378 = v1442;
    } else {
      int * v1328 = v1278->cache_age;
      int v1452 = 4 + ((((int)((unsigned int)((int)((unsigned int)v1282 >> 2)) >> 1)) & 3) * 2);
      int v1329 = v1328[v1452];
      int * v1330 = v1278->cache_tags;
      int v1331 = v1330[v1452];
      int * v1332 = v1278->cache_age;
      int v1333 = v1332[v1422];
      int * v1334 = v1278->cache_tags;
      int v1335 = v1334[v1422];
      int * v1336 = v1278->cache_dirty;
      int v1457 = (4 + ((((int)((unsigned int)((int)((unsigned int)v1282 >> 2)) >> 1)) & 3) * 2)) + ((((v1329 + ((~(((v1331 ^ -1) | (-(v1331 ^ -1))) >> 31)) & 2)) - (v1333 + ((~(((v1335 ^ -1) | (-(v1335 ^ -1))) >> 31)) & 2))) >> 31) & 1);
      int v1337 = v1336[v1457];
      bool v1458 = !(v1337 == 0);
      if (v1458) {
        int * v1338 = v1278->cache_tags;
        int v1339 = v1338[v1457];
        int * v1340 = v1278->cache_vals;
        int v1461 = ((4 + ((((int)((unsigned int)((int)((unsigned int)v1282 >> 2)) >> 1)) & 3) * 2)) + ((((v1329 + ((~(((v1331 ^ -1) | (-(v1331 ^ -1))) >> 31)) & 2)) - (v1333 + ((~(((v1335 ^ -1) | (-(v1335 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
        int v1341 = v1340[v1461];
        int * v1342 = v1278->cache_vals;
        int v1463 = (((4 + ((((int)((unsigned int)((int)((unsigned int)v1282 >> 2)) >> 1)) & 3) * 2)) + ((((v1329 + ((~(((v1331 ^ -1) | (-(v1331 ^ -1))) >> 31)) & 2)) - (v1333 + ((~(((v1335 ^ -1) | (-(v1335 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
        int v1343 = v1342[v1463];
        int * v1344 = v1278->mem;
        int v1465 = v1339 * 2;
        v1344[v1465] = v1341;
        int * v1346 = v1278->mem;
        int v1468 = (v1339 * 2) + 1;
        v1346[v1468] = v1343;
        ;
      } else {
        ;
      }
      int * v1351 = v1278->mem;
      int v1473 = ((int)((unsigned int)((int)((unsigned int)v1282 >> 2)) >> 1)) * 2;
      int v1352 = v1351[v1473];
      int * v1353 = v1278->mem;
      int v1475 = (((int)((unsigned int)((int)((unsigned int)v1282 >> 2)) >> 1)) * 2) + 1;
      int v1354 = v1353[v1475];
      int * v1355 = v1278->cache_vals;
      int v1477 = ((4 + ((((int)((unsigned int)((int)((unsigned int)v1282 >> 2)) >> 1)) & 3) * 2)) + ((((v1329 + ((~(((v1331 ^ -1) | (-(v1331 ^ -1))) >> 31)) & 2)) - (v1333 + ((~(((v1335 ^ -1) | (-(v1335 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
      v1355[v1477] = v1352;
      int * v1357 = v1278->cache_vals;
      int v1480 = (((4 + ((((int)((unsigned int)((int)((unsigned int)v1282 >> 2)) >> 1)) & 3) * 2)) + ((((v1329 + ((~(((v1331 ^ -1) | (-(v1331 ^ -1))) >> 31)) & 2)) - (v1333 + ((~(((v1335 ^ -1) | (-(v1335 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
      v1357[v1480] = v1354;
      int * v1359 = v1278->cache_tags;
      int v1483 = (int)((unsigned int)((int)((unsigned int)v1282 >> 2)) >> 1);
      v1359[v1457] = v1483;
      int * v1361 = v1278->cache_dirty;
      v1361[v1457] = 0;
      int * v1363 = v1278->cache_age;
      v1363[v1457] = 1;
      int * v1365 = v1278->cache_age;
      int v1366 = v1365[v1457];
      int * v1367 = v1278->cache_age;
      int v1368 = v1367[v1420];
      int * v1369 = v1278->cache_age;
      int v1491 = v1368 + ((int)((unsigned int)(v1368 - v1366) >> 31));
      v1369[v1420] = v1491;
      int * v1371 = v1278->cache_age;
      int v1372 = v1371[v1422];
      int * v1373 = v1278->cache_age;
      int v1494 = v1372 + ((int)((unsigned int)(v1372 - v1366) >> 31));
      v1373[v1422] = v1494;
      int * v1375 = v1278->cache_age;
      v1375[v1457] = 0;
      v1378 = v1457;
    }
    int * v1379 = v1278->cache_vals;
    int v1497 = v1378 * 2;
    int v1380 = v1379[v1497];
    int * v1381 = v1278->cache_vals;
    int v1499 = (v1378 * 2) + 1;
    int v1382 = v1381[v1499];
    int * v1383 = v1278->cache_vals;
    int v1501 = (((((int)((unsigned int)((int)((unsigned int)v1282 >> 2)) >> 1)) & 1) * 2) + ((((v1308 + ((~(((v1310 ^ -1) | (-(v1310 ^ -1))) >> 31)) & 2)) - (v1312 + ((~(((v1314 ^ -1) | (-(v1314 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
    v1383[v1501] = v1380;
    int * v1385 = v1278->cache_vals;
    int v1504 = ((((((int)((unsigned int)((int)((unsigned int)v1282 >> 2)) >> 1)) & 1) * 2) + ((((v1308 + ((~(((v1310 ^ -1) | (-(v1310 ^ -1))) >> 31)) & 2)) - (v1312 + ((~(((v1314 ^ -1) | (-(v1314 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
    v1385[v1504] = v1382;
    int * v1387 = v1278->cache_tags;
    int v1507 = ((((int)((unsigned int)((int)((unsigned int)v1282 >> 2)) >> 1)) & 1) * 2) + ((((v1308 + ((~(((v1310 ^ -1) | (-(v1310 ^ -1))) >> 31)) & 2)) - (v1312 + ((~(((v1314 ^ -1) | (-(v1314 ^ -1))) >> 31)) & 2))) >> 31) & 1);
    int v1508 = (int)((unsigned int)((int)((unsigned int)v1282 >> 2)) >> 1);
    v1387[v1507] = v1508;
    int * v1389 = v1278->cache_dirty;
    v1389[v1507] = 0;
    int * v1391 = v1278->cache_age;
    v1391[v1507] = 1;
    int * v1393 = v1278->cache_age;
    int v1394 = v1393[v1507];
    int * v1395 = v1278->cache_age;
    int v1396 = v1395[v1416];
    int * v1397 = v1278->cache_age;
    int v1516 = v1396 + ((int)((unsigned int)(v1396 - v1394) >> 31));
    v1397[v1416] = v1516;
    int * v1399 = v1278->cache_age;
    int v1400 = v1399[v1418];
    int * v1401 = v1278->cache_age;
    int v1519 = v1400 + ((int)((unsigned int)(v1400 - v1394) >> 31));
    v1401[v1418] = v1519;
    int * v1403 = v1278->cache_age;
    v1403[v1507] = 0;
    v1406 = v1507;
  }
  int v1522 = (v1406 * 2) + (((int)((unsigned int)v1282 >> 2)) & 1);
  int v1407 = v1293[v1522];
  int * v1408 = v1278->regs;
  v1408[7] = v1407;
  struct StateT * v1410 = slot_22(v1278);
  return v1410;
}

struct StateT * slot_3(struct StateT * v272) {
  int v273 = v272->timer;
  int v281 = v273 + 1;
  v272->timer = v281;
  int * v275 = v272->regs;
  int v276 = v275[10];
  int * v277 = v272->regs;
  v277[6] = v276;
  struct StateT * v279 = slot_4(v272);
  return v279;
}

struct StateT * slot_10(struct StateT * v624) {
  int v625 = v624->timer;
  int v633 = v625 + 1;
  v624->timer = v633;
  int * v627 = v624->regs;
  int v628 = v627[6];
  int * v629 = v624->regs;
  int v637 = v628 << 2;
  v629[6] = v637;
  struct StateT * v631 = slot_11(v624);
  return v631;
}

struct StateT * slot_1(struct StateT * v15) {
  int v16 = v15->timer;
  int v147 = v16 + 1;
  v15->timer = v147;
  int * v18 = v15->cache_tags;
  int v19 = v18[0];
  int * v20 = v15->cache_tags;
  int v21 = v20[1];
  int * v22 = v15->cache_tags;
  int v23 = v22[8];
  int * v24 = v15->cache_tags;
  int v25 = v24[9];
  int v26 = v15->timer;
  int v156 = v26 + ((100 ^ (((~(((v23 ^ 10) | (-(v23 ^ 10))) >> 31)) | (~(((v25 ^ 10) | (-(v25 ^ 10))) >> 31))) & 104)) ^ (((~(((v19 ^ 10) | (-(v19 ^ 10))) >> 31)) | (~(((v21 ^ 10) | (-(v21 ^ 10))) >> 31))) & (1 ^ (100 ^ (((~(((v23 ^ 10) | (-(v23 ^ 10))) >> 31)) | (~(((v25 ^ 10) | (-(v25 ^ 10))) >> 31))) & 104)))));
  v15->timer = v156;
  int * v28 = v15->cache_vals;
  bool v157 = !(((~(((v19 ^ 10) | (-(v19 ^ 10))) >> 31)) | (~(((v21 ^ 10) | (-(v21 ^ 10))) >> 31))) == 0);
  int v141;
  if (v157) {
    int * v29 = v15->cache_age;
    int v159 = (~(((v21 ^ 10) | (-(v21 ^ 10))) >> 31)) & 1;
    int v30 = v29[v159];
    int * v31 = v15->cache_age;
    int v32 = v31[0];
    int * v33 = v15->cache_age;
    int v162 = v32 + ((int)((unsigned int)(v32 - v30) >> 31));
    v33[0] = v162;
    int * v35 = v15->cache_age;
    int v36 = v35[1];
    int * v37 = v15->cache_age;
    int v165 = v36 + ((int)((unsigned int)(v36 - v30) >> 31));
    v37[1] = v165;
    int * v39 = v15->cache_age;
    v39[v159] = 0;
    v141 = v159;
  } else {
    int * v42 = v15->cache_age;
    int v43 = v42[0];
    int * v44 = v15->cache_tags;
    int v45 = v44[0];
    int * v46 = v15->cache_age;
    int v47 = v46[1];
    int * v48 = v15->cache_tags;
    int v49 = v48[1];
    bool v171 = !(((~(((v23 ^ 10) | (-(v23 ^ 10))) >> 31)) | (~(((v25 ^ 10) | (-(v25 ^ 10))) >> 31))) == 0);
    int v113;
    if (v171) {
      int * v50 = v15->cache_age;
      int v173 = 8 + ((~(((v25 ^ 10) | (-(v25 ^ 10))) >> 31)) & 1);
      int v51 = v50[v173];
      int * v52 = v15->cache_age;
      int v53 = v52[8];
      int * v54 = v15->cache_age;
      int v176 = v53 + ((int)((unsigned int)(v53 - v51) >> 31));
      v54[8] = v176;
      int * v56 = v15->cache_age;
      int v57 = v56[9];
      int * v58 = v15->cache_age;
      int v179 = v57 + ((int)((unsigned int)(v57 - v51) >> 31));
      v58[9] = v179;
      int * v60 = v15->cache_age;
      v60[v173] = 0;
      v113 = v173;
    } else {
      int * v63 = v15->cache_age;
      int v64 = v63[8];
      int * v65 = v15->cache_tags;
      int v66 = v65[8];
      int * v67 = v15->cache_age;
      int v68 = v67[9];
      int * v69 = v15->cache_tags;
      int v70 = v69[9];
      int * v71 = v15->cache_dirty;
      int v186 = 8 + ((((v64 + ((~(((v66 ^ -1) | (-(v66 ^ -1))) >> 31)) & 2)) - (v68 + ((~(((v70 ^ -1) | (-(v70 ^ -1))) >> 31)) & 2))) >> 31) & 1);
      int v72 = v71[v186];
      bool v187 = !(v72 == 0);
      if (v187) {
        int * v73 = v15->cache_tags;
        int v74 = v73[v186];
        int * v75 = v15->cache_vals;
        int v190 = (8 + ((((v64 + ((~(((v66 ^ -1) | (-(v66 ^ -1))) >> 31)) & 2)) - (v68 + ((~(((v70 ^ -1) | (-(v70 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
        int v76 = v75[v190];
        int * v77 = v15->cache_vals;
        int v192 = ((8 + ((((v64 + ((~(((v66 ^ -1) | (-(v66 ^ -1))) >> 31)) & 2)) - (v68 + ((~(((v70 ^ -1) | (-(v70 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
        int v78 = v77[v192];
        int * v79 = v15->mem;
        int v194 = v74 * 2;
        v79[v194] = v76;
        int * v81 = v15->mem;
        int v197 = (v74 * 2) + 1;
        v81[v197] = v78;
        ;
      } else {
        ;
      }
      int * v86 = v15->mem;
      int v87 = v86[20];
      int * v88 = v15->mem;
      int v89 = v88[21];
      int * v90 = v15->cache_vals;
      int v206 = (8 + ((((v64 + ((~(((v66 ^ -1) | (-(v66 ^ -1))) >> 31)) & 2)) - (v68 + ((~(((v70 ^ -1) | (-(v70 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
      v90[v206] = v87;
      int * v92 = v15->cache_vals;
      int v209 = ((8 + ((((v64 + ((~(((v66 ^ -1) | (-(v66 ^ -1))) >> 31)) & 2)) - (v68 + ((~(((v70 ^ -1) | (-(v70 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
      v92[v209] = v89;
      int * v94 = v15->cache_tags;
      v94[v186] = 10;
      int * v96 = v15->cache_dirty;
      v96[v186] = 0;
      int * v98 = v15->cache_age;
      v98[v186] = 1;
      int * v100 = v15->cache_age;
      int v101 = v100[v186];
      int * v102 = v15->cache_age;
      int v103 = v102[8];
      int * v104 = v15->cache_age;
      int v218 = v103 + ((int)((unsigned int)(v103 - v101) >> 31));
      v104[8] = v218;
      int * v106 = v15->cache_age;
      int v107 = v106[9];
      int * v108 = v15->cache_age;
      int v221 = v107 + ((int)((unsigned int)(v107 - v101) >> 31));
      v108[9] = v221;
      int * v110 = v15->cache_age;
      v110[v186] = 0;
      v113 = v186;
    }
    int * v114 = v15->cache_vals;
    int v224 = v113 * 2;
    int v115 = v114[v224];
    int * v116 = v15->cache_vals;
    int v226 = (v113 * 2) + 1;
    int v117 = v116[v226];
    int * v118 = v15->cache_vals;
    int v228 = ((((v43 + ((~(((v45 ^ -1) | (-(v45 ^ -1))) >> 31)) & 2)) - (v47 + ((~(((v49 ^ -1) | (-(v49 ^ -1))) >> 31)) & 2))) >> 31) & 1) * 2;
    v118[v228] = v115;
    int * v120 = v15->cache_vals;
    int v231 = (((((v43 + ((~(((v45 ^ -1) | (-(v45 ^ -1))) >> 31)) & 2)) - (v47 + ((~(((v49 ^ -1) | (-(v49 ^ -1))) >> 31)) & 2))) >> 31) & 1) * 2) + 1;
    v120[v231] = v117;
    int * v122 = v15->cache_tags;
    int v234 = (((v43 + ((~(((v45 ^ -1) | (-(v45 ^ -1))) >> 31)) & 2)) - (v47 + ((~(((v49 ^ -1) | (-(v49 ^ -1))) >> 31)) & 2))) >> 31) & 1;
    v122[v234] = 10;
    int * v124 = v15->cache_dirty;
    v124[v234] = 0;
    int * v126 = v15->cache_age;
    v126[v234] = 1;
    int * v128 = v15->cache_age;
    int v129 = v128[v234];
    int * v130 = v15->cache_age;
    int v131 = v130[0];
    int * v132 = v15->cache_age;
    int v241 = v131 + ((int)((unsigned int)(v131 - v129) >> 31));
    v132[0] = v241;
    int * v134 = v15->cache_age;
    int v135 = v134[1];
    int * v136 = v15->cache_age;
    int v244 = v135 + ((int)((unsigned int)(v135 - v129) >> 31));
    v136[1] = v244;
    int * v138 = v15->cache_age;
    v138[v234] = 0;
    v141 = v234;
  }
  int v247 = v141 * 2;
  int v142 = v28[v247];
  int * v143 = v15->regs;
  v143[9] = v142;
  struct StateT * v145 = slot_2(v15);
  return v145;
}

struct StateT * slot_19(struct StateT * v1246) {
  int v1247 = v1246->timer;
  int v1255 = v1247 + 1;
  v1246->timer = v1255;
  int * v1249 = v1246->regs;
  int v1250 = v1249[6];
  int * v1251 = v1246->regs;
  int v1259 = v1250 & 63;
  v1251[6] = v1259;
  struct StateT * v1253 = slot_20(v1246);
  return v1253;
}

struct StateT * slot_13(struct StateT * v910) {
  int v911 = v910->timer;
  int v919 = v911 + 1;
  v910->timer = v919;
  int * v913 = v910->regs;
  int v914 = v913[10];
  int * v915 = v910->regs;
  int v924 = (int)((unsigned int)v914 >> 16);
  v915[6] = v924;
  struct StateT * v917 = slot_14(v910);
  return v917;
}

struct StateT * slot_0(struct StateT * v2) {
  int v3 = v2->timer;
  int v9 = v3 + 1;
  v2->timer = v9;
  int * v5 = v2->regs;
  v5[5] = 0;
  struct StateT * v7 = slot_1(v2);
  return v7;
}

struct StateT * slot_14(struct StateT * v927) {
  int v928 = v927->timer;
  int v936 = v928 + 1;
  v927->timer = v936;
  int * v930 = v927->regs;
  int v931 = v930[6];
  int * v932 = v927->regs;
  int v940 = v931 & 63;
  v932[6] = v940;
  struct StateT * v934 = slot_15(v927);
  return v934;
}

struct StateT * slot_17(struct StateT * v1209) {
  int v1210 = v1209->timer;
  int v1220 = v1210 + 1;
  v1209->timer = v1220;
  int * v1212 = v1209->regs;
  int v1213 = v1212[5];
  int * v1214 = v1209->regs;
  int v1215 = v1214[7];
  int * v1216 = v1209->regs;
  int v1226 = v1213 ^ v1215;
  v1216[5] = v1226;
  struct StateT * v1218 = slot_18(v1209);
  return v1218;
}

struct StateT * slot_20(struct StateT * v1262) {
  int v1263 = v1262->timer;
  int v1271 = v1263 + 1;
  v1262->timer = v1271;
  int * v1265 = v1262->regs;
  int v1266 = v1265[6];
  int * v1267 = v1262->regs;
  int v1275 = v1266 << 2;
  v1267[6] = v1275;
  struct StateT * v1269 = slot_21(v1262);
  return v1269;
}

struct StateT * snippet(struct StateT * v0) {
  struct StateT * v1 = slot_0(v0);
  return v1;
}

struct StateT * slot_8(struct StateT * v591) {
  int v592 = v591->timer;
  int v600 = v592 + 1;
  v591->timer = v600;
  int * v594 = v591->regs;
  int v595 = v594[10];
  int * v596 = v591->regs;
  int v605 = (int)((unsigned int)v595 >> 8);
  v596[6] = v605;
  struct StateT * v598 = slot_9(v591);
  return v598;
}

struct StateT * slot_4(struct StateT * v289) {
  int v290 = v289->timer;
  int v298 = v290 + 1;
  v289->timer = v298;
  int * v292 = v289->regs;
  int v293 = v292[6];
  int * v294 = v289->regs;
  int v302 = v293 & 63;
  v294[6] = v302;
  struct StateT * v296 = slot_5(v289);
  return v296;
}

struct StateT * slot_15(struct StateT * v943) {
  int v944 = v943->timer;
  int v952 = v944 + 1;
  v943->timer = v952;
  int * v946 = v943->regs;
  int v947 = v946[6];
  int * v948 = v943->regs;
  int v956 = v947 << 2;
  v948[6] = v956;
  struct StateT * v950 = slot_16(v943);
  return v950;
}

struct StateT * slot_18(struct StateT * v1229) {
  int v1230 = v1229->timer;
  int v1238 = v1230 + 1;
  v1229->timer = v1238;
  int * v1232 = v1229->regs;
  int v1233 = v1232[10];
  int * v1234 = v1229->regs;
  int v1243 = (int)((unsigned int)v1233 >> 24);
  v1234[6] = v1243;
  struct StateT * v1236 = slot_19(v1229);
  return v1236;
}

struct StateT * slot_9(struct StateT * v608) {
  int v609 = v608->timer;
  int v617 = v609 + 1;
  v608->timer = v617;
  int * v611 = v608->regs;
  int v612 = v611[6];
  int * v613 = v608->regs;
  int v621 = v612 & 63;
  v613[6] = v621;
  struct StateT * v615 = slot_10(v608);
  return v615;
}

struct StateT * slot_22(struct StateT * v1528) {
  int v1529 = v1528->timer;
  int v1538 = v1529 + 1;
  v1528->timer = v1538;
  int * v1531 = v1528->regs;
  int v1532 = v1531[5];
  int * v1533 = v1528->regs;
  int v1534 = v1533[7];
  int * v1535 = v1528->regs;
  int v1544 = v1532 ^ v1534;
  v1535[5] = v1544;
  return v1528;
}

struct StateT * slot_11(struct StateT * v640) {
  int v641 = v640->timer;
  int v774 = v641 + 1;
  v640->timer = v774;
  int * v643 = v640->regs;
  int v644 = v643[6];
  int * v645 = v640->cache_tags;
  int v778 = (((int)((unsigned int)((int)((unsigned int)v644 >> 2)) >> 1)) & 1) * 2;
  int v646 = v645[v778];
  int * v647 = v640->cache_tags;
  int v780 = ((((int)((unsigned int)((int)((unsigned int)v644 >> 2)) >> 1)) & 1) * 2) + 1;
  int v648 = v647[v780];
  int * v649 = v640->cache_tags;
  int v782 = 4 + ((((int)((unsigned int)((int)((unsigned int)v644 >> 2)) >> 1)) & 3) * 2);
  int v650 = v649[v782];
  int * v651 = v640->cache_tags;
  int v784 = (4 + ((((int)((unsigned int)((int)((unsigned int)v644 >> 2)) >> 1)) & 3) * 2)) + 1;
  int v652 = v651[v784];
  int v653 = v640->timer;
  int v785 = v653 + ((100 ^ (((~(((v650 ^ ((int)((unsigned int)((int)((unsigned int)v644 >> 2)) >> 1))) | (-(v650 ^ ((int)((unsigned int)((int)((unsigned int)v644 >> 2)) >> 1))))) >> 31)) | (~(((v652 ^ ((int)((unsigned int)((int)((unsigned int)v644 >> 2)) >> 1))) | (-(v652 ^ ((int)((unsigned int)((int)((unsigned int)v644 >> 2)) >> 1))))) >> 31))) & 104)) ^ (((~(((v646 ^ ((int)((unsigned int)((int)((unsigned int)v644 >> 2)) >> 1))) | (-(v646 ^ ((int)((unsigned int)((int)((unsigned int)v644 >> 2)) >> 1))))) >> 31)) | (~(((v648 ^ ((int)((unsigned int)((int)((unsigned int)v644 >> 2)) >> 1))) | (-(v648 ^ ((int)((unsigned int)((int)((unsigned int)v644 >> 2)) >> 1))))) >> 31))) & (1 ^ (100 ^ (((~(((v650 ^ ((int)((unsigned int)((int)((unsigned int)v644 >> 2)) >> 1))) | (-(v650 ^ ((int)((unsigned int)((int)((unsigned int)v644 >> 2)) >> 1))))) >> 31)) | (~(((v652 ^ ((int)((unsigned int)((int)((unsigned int)v644 >> 2)) >> 1))) | (-(v652 ^ ((int)((unsigned int)((int)((unsigned int)v644 >> 2)) >> 1))))) >> 31))) & 104)))));
  v640->timer = v785;
  int * v655 = v640->cache_vals;
  bool v786 = !(((~(((v646 ^ ((int)((unsigned int)((int)((unsigned int)v644 >> 2)) >> 1))) | (-(v646 ^ ((int)((unsigned int)((int)((unsigned int)v644 >> 2)) >> 1))))) >> 31)) | (~(((v648 ^ ((int)((unsigned int)((int)((unsigned int)v644 >> 2)) >> 1))) | (-(v648 ^ ((int)((unsigned int)((int)((unsigned int)v644 >> 2)) >> 1))))) >> 31))) == 0);
  int v768;
  if (v786) {
    int * v656 = v640->cache_age;
    int v788 = ((((int)((unsigned int)((int)((unsigned int)v644 >> 2)) >> 1)) & 1) * 2) + ((~(((v648 ^ ((int)((unsigned int)((int)((unsigned int)v644 >> 2)) >> 1))) | (-(v648 ^ ((int)((unsigned int)((int)((unsigned int)v644 >> 2)) >> 1))))) >> 31)) & 1);
    int v657 = v656[v788];
    int * v658 = v640->cache_age;
    int v659 = v658[v778];
    int * v660 = v640->cache_age;
    int v791 = v659 + ((int)((unsigned int)(v659 - v657) >> 31));
    v660[v778] = v791;
    int * v662 = v640->cache_age;
    int v663 = v662[v780];
    int * v664 = v640->cache_age;
    int v794 = v663 + ((int)((unsigned int)(v663 - v657) >> 31));
    v664[v780] = v794;
    int * v666 = v640->cache_age;
    v666[v788] = 0;
    v768 = v788;
  } else {
    int * v669 = v640->cache_age;
    int v798 = (((int)((unsigned int)((int)((unsigned int)v644 >> 2)) >> 1)) & 1) * 2;
    int v670 = v669[v798];
    int * v671 = v640->cache_tags;
    int v672 = v671[v798];
    int * v673 = v640->cache_age;
    int v674 = v673[v780];
    int * v675 = v640->cache_tags;
    int v676 = v675[v780];
    bool v802 = !(((~(((v650 ^ ((int)((unsigned int)((int)((unsigned int)v644 >> 2)) >> 1))) | (-(v650 ^ ((int)((unsigned int)((int)((unsigned int)v644 >> 2)) >> 1))))) >> 31)) | (~(((v652 ^ ((int)((unsigned int)((int)((unsigned int)v644 >> 2)) >> 1))) | (-(v652 ^ ((int)((unsigned int)((int)((unsigned int)v644 >> 2)) >> 1))))) >> 31))) == 0);
    int v740;
    if (v802) {
      int * v677 = v640->cache_age;
      int v804 = (4 + ((((int)((unsigned int)((int)((unsigned int)v644 >> 2)) >> 1)) & 3) * 2)) + ((~(((v652 ^ ((int)((unsigned int)((int)((unsigned int)v644 >> 2)) >> 1))) | (-(v652 ^ ((int)((unsigned int)((int)((unsigned int)v644 >> 2)) >> 1))))) >> 31)) & 1);
      int v678 = v677[v804];
      int * v679 = v640->cache_age;
      int v680 = v679[v782];
      int * v681 = v640->cache_age;
      int v807 = v680 + ((int)((unsigned int)(v680 - v678) >> 31));
      v681[v782] = v807;
      int * v683 = v640->cache_age;
      int v684 = v683[v784];
      int * v685 = v640->cache_age;
      int v810 = v684 + ((int)((unsigned int)(v684 - v678) >> 31));
      v685[v784] = v810;
      int * v687 = v640->cache_age;
      v687[v804] = 0;
      v740 = v804;
    } else {
      int * v690 = v640->cache_age;
      int v814 = 4 + ((((int)((unsigned int)((int)((unsigned int)v644 >> 2)) >> 1)) & 3) * 2);
      int v691 = v690[v814];
      int * v692 = v640->cache_tags;
      int v693 = v692[v814];
      int * v694 = v640->cache_age;
      int v695 = v694[v784];
      int * v696 = v640->cache_tags;
      int v697 = v696[v784];
      int * v698 = v640->cache_dirty;
      int v819 = (4 + ((((int)((unsigned int)((int)((unsigned int)v644 >> 2)) >> 1)) & 3) * 2)) + ((((v691 + ((~(((v693 ^ -1) | (-(v693 ^ -1))) >> 31)) & 2)) - (v695 + ((~(((v697 ^ -1) | (-(v697 ^ -1))) >> 31)) & 2))) >> 31) & 1);
      int v699 = v698[v819];
      bool v820 = !(v699 == 0);
      if (v820) {
        int * v700 = v640->cache_tags;
        int v701 = v700[v819];
        int * v702 = v640->cache_vals;
        int v823 = ((4 + ((((int)((unsigned int)((int)((unsigned int)v644 >> 2)) >> 1)) & 3) * 2)) + ((((v691 + ((~(((v693 ^ -1) | (-(v693 ^ -1))) >> 31)) & 2)) - (v695 + ((~(((v697 ^ -1) | (-(v697 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
        int v703 = v702[v823];
        int * v704 = v640->cache_vals;
        int v825 = (((4 + ((((int)((unsigned int)((int)((unsigned int)v644 >> 2)) >> 1)) & 3) * 2)) + ((((v691 + ((~(((v693 ^ -1) | (-(v693 ^ -1))) >> 31)) & 2)) - (v695 + ((~(((v697 ^ -1) | (-(v697 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
        int v705 = v704[v825];
        int * v706 = v640->mem;
        int v827 = v701 * 2;
        v706[v827] = v703;
        int * v708 = v640->mem;
        int v830 = (v701 * 2) + 1;
        v708[v830] = v705;
        ;
      } else {
        ;
      }
      int * v713 = v640->mem;
      int v835 = ((int)((unsigned int)((int)((unsigned int)v644 >> 2)) >> 1)) * 2;
      int v714 = v713[v835];
      int * v715 = v640->mem;
      int v837 = (((int)((unsigned int)((int)((unsigned int)v644 >> 2)) >> 1)) * 2) + 1;
      int v716 = v715[v837];
      int * v717 = v640->cache_vals;
      int v839 = ((4 + ((((int)((unsigned int)((int)((unsigned int)v644 >> 2)) >> 1)) & 3) * 2)) + ((((v691 + ((~(((v693 ^ -1) | (-(v693 ^ -1))) >> 31)) & 2)) - (v695 + ((~(((v697 ^ -1) | (-(v697 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
      v717[v839] = v714;
      int * v719 = v640->cache_vals;
      int v842 = (((4 + ((((int)((unsigned int)((int)((unsigned int)v644 >> 2)) >> 1)) & 3) * 2)) + ((((v691 + ((~(((v693 ^ -1) | (-(v693 ^ -1))) >> 31)) & 2)) - (v695 + ((~(((v697 ^ -1) | (-(v697 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
      v719[v842] = v716;
      int * v721 = v640->cache_tags;
      int v845 = (int)((unsigned int)((int)((unsigned int)v644 >> 2)) >> 1);
      v721[v819] = v845;
      int * v723 = v640->cache_dirty;
      v723[v819] = 0;
      int * v725 = v640->cache_age;
      v725[v819] = 1;
      int * v727 = v640->cache_age;
      int v728 = v727[v819];
      int * v729 = v640->cache_age;
      int v730 = v729[v782];
      int * v731 = v640->cache_age;
      int v853 = v730 + ((int)((unsigned int)(v730 - v728) >> 31));
      v731[v782] = v853;
      int * v733 = v640->cache_age;
      int v734 = v733[v784];
      int * v735 = v640->cache_age;
      int v856 = v734 + ((int)((unsigned int)(v734 - v728) >> 31));
      v735[v784] = v856;
      int * v737 = v640->cache_age;
      v737[v819] = 0;
      v740 = v819;
    }
    int * v741 = v640->cache_vals;
    int v859 = v740 * 2;
    int v742 = v741[v859];
    int * v743 = v640->cache_vals;
    int v861 = (v740 * 2) + 1;
    int v744 = v743[v861];
    int * v745 = v640->cache_vals;
    int v863 = (((((int)((unsigned int)((int)((unsigned int)v644 >> 2)) >> 1)) & 1) * 2) + ((((v670 + ((~(((v672 ^ -1) | (-(v672 ^ -1))) >> 31)) & 2)) - (v674 + ((~(((v676 ^ -1) | (-(v676 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
    v745[v863] = v742;
    int * v747 = v640->cache_vals;
    int v866 = ((((((int)((unsigned int)((int)((unsigned int)v644 >> 2)) >> 1)) & 1) * 2) + ((((v670 + ((~(((v672 ^ -1) | (-(v672 ^ -1))) >> 31)) & 2)) - (v674 + ((~(((v676 ^ -1) | (-(v676 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
    v747[v866] = v744;
    int * v749 = v640->cache_tags;
    int v869 = ((((int)((unsigned int)((int)((unsigned int)v644 >> 2)) >> 1)) & 1) * 2) + ((((v670 + ((~(((v672 ^ -1) | (-(v672 ^ -1))) >> 31)) & 2)) - (v674 + ((~(((v676 ^ -1) | (-(v676 ^ -1))) >> 31)) & 2))) >> 31) & 1);
    int v870 = (int)((unsigned int)((int)((unsigned int)v644 >> 2)) >> 1);
    v749[v869] = v870;
    int * v751 = v640->cache_dirty;
    v751[v869] = 0;
    int * v753 = v640->cache_age;
    v753[v869] = 1;
    int * v755 = v640->cache_age;
    int v756 = v755[v869];
    int * v757 = v640->cache_age;
    int v758 = v757[v778];
    int * v759 = v640->cache_age;
    int v878 = v758 + ((int)((unsigned int)(v758 - v756) >> 31));
    v759[v778] = v878;
    int * v761 = v640->cache_age;
    int v762 = v761[v780];
    int * v763 = v640->cache_age;
    int v881 = v762 + ((int)((unsigned int)(v762 - v756) >> 31));
    v763[v780] = v881;
    int * v765 = v640->cache_age;
    v765[v869] = 0;
    v768 = v869;
  }
  int v884 = (v768 * 2) + (((int)((unsigned int)v644 >> 2)) & 1);
  int v769 = v655[v884];
  int * v770 = v640->regs;
  v770[7] = v769;
  struct StateT * v772 = slot_12(v640);
  return v772;
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

int main(int argc, char* argv[]) {
  struct StateT s1, s2;
  init(&s1);
  init(&s2);
  
  // the indices, public: one draw into both states
  int i10 = bounded(0, 1073741823);
  s1.regs[10] = i10;
  s2.regs[10] = i10;
  
  // initialize secret
  for (int i=0; i<SECRET_SIZE; i++) {
    s1.mem[SECRET_OFFSET+i] = bounded(0, 20);
    s2.mem[SECRET_OFFSET+i] = bounded(0, 20);
  }
  struct StateT *s1_ = snippet(&s1);
  struct StateT *s2_ = snippet(&s2);
  koika_assert(s1_->timer==s2_->timer, "timing leak");
  return 0;
}