// verify: leak (CBMC should report VERIFICATION FAILED) [unwind 65]
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

struct StateT * slot_12(struct StateT * v617);
struct StateT * slot_6(struct StateT * v305);
struct StateT * slot_25(struct StateT * v2269);
struct StateT * slot_16(struct StateT * v1077);
struct StateT * slot_23(struct StateT * v1926);
struct StateT * slot_5(struct StateT * v284);
struct StateT * slot_2(struct StateT * v225);
struct StateT * slot_7(struct StateT * v329);
struct StateT * slot_21(struct StateT * v1511);
struct StateT * slot_3(struct StateT * v233);
struct StateT * slot_10(struct StateT * v573);
struct StateT * slot_1(struct StateT * v18);
struct StateT * slot_19(struct StateT * v1176);
struct StateT * slot_13(struct StateT * v638);
struct StateT * slot_24(struct StateT * v1950);
struct StateT * slot_0(struct StateT * v2);
struct StateT * slot_14(struct StateT * v662);
struct StateT * slot_17(struct StateT * v1101);
struct StateT * slot_20(struct StateT * v1495);
struct StateT * snippet(struct StateT * v0);
struct StateT * slot_8(struct StateT * v536);
struct StateT * slot_4(struct StateT * v261);
struct StateT * slot_15(struct StateT * v869);
struct StateT * slot_18(struct StateT * v1160);
struct StateT * slot_9(struct StateT * v552);
struct StateT * slot_22(struct StateT * v1718);
struct StateT * slot_11(struct StateT * v596);
struct StateT * slot_12(struct StateT * v617) {
  int v618 = v617->timer;
  int v629 = v618 + 1;
  v617->timer = v629;
  int * v620 = v617->reg_ready;
  int v621 = v620[10];
  int * v622 = v617->regs;
  int v623 = v622[10];
  int v633 = (v621 + ((v618 - v621) & (~((v618 - v621) >> 31)))) + 1;
  v620[10] = v633;
  int * v625 = v617->regs;
  int v635 = (int)((unsigned int)v623 >> 26);
  v625[10] = v635;
  struct StateT * v627 = slot_13(v617);
  return v627;
}

struct StateT * slot_6(struct StateT * v305) {
  int v306 = v305->timer;
  int v319 = v306 + 1;
  v305->timer = v319;
  int * v308 = v305->reg_ready;
  int v309 = v308[11];
  int * v310 = v305->regs;
  int v311 = v310[11];
  int v312 = v308[10];
  int v313 = v310[10];
  int v324 = (v312 + (((v309 + ((v306 - v309) & (~((v306 - v309) >> 31)))) - v312) & (~(((v309 + ((v306 - v309) & (~((v306 - v309) >> 31)))) - v312) >> 31)))) + 1;
  v308[10] = v324;
  int * v315 = v305->regs;
  int v326 = v311 + v313;
  v315[10] = v326;
  struct StateT * v317 = slot_7(v305);
  return v317;
}

struct StateT * slot_25(struct StateT * v2269) {
  int v2270 = v2269->timer;
  int v2273 = v2270 + 1;
  v2269->timer = v2273;
  return v2269;
}

struct StateT * slot_16(struct StateT * v1077) {
  int v1078 = v1077->timer;
  int v1091 = v1078 + 1;
  v1077->timer = v1091;
  int * v1080 = v1077->reg_ready;
  int v1081 = v1080[11];
  int * v1082 = v1077->regs;
  int v1083 = v1082[11];
  int v1084 = v1080[10];
  int v1085 = v1082[10];
  int v1096 = (v1084 + (((v1081 + ((v1078 - v1081) & (~((v1078 - v1081) >> 31)))) - v1084) & (~(((v1081 + ((v1078 - v1081) & (~((v1078 - v1081) >> 31)))) - v1084) >> 31)))) + 1;
  v1080[10] = v1096;
  int * v1087 = v1077->regs;
  int v1098 = v1083 & v1085;
  v1087[10] = v1098;
  struct StateT * v1089 = slot_17(v1077);
  return v1089;
}

struct StateT * slot_23(struct StateT * v1926) {
  int v1927 = v1926->timer;
  int v1940 = v1927 + 1;
  v1926->timer = v1940;
  int * v1929 = v1926->reg_ready;
  int v1930 = v1929[12];
  int * v1931 = v1926->regs;
  int v1932 = v1931[12];
  int v1933 = v1929[10];
  int v1934 = v1931[10];
  int v1945 = (v1933 + (((v1930 + ((v1927 - v1930) & (~((v1927 - v1930) >> 31)))) - v1933) & (~(((v1930 + ((v1927 - v1930) & (~((v1927 - v1930) >> 31)))) - v1933) >> 31)))) + 1;
  v1929[10] = v1945;
  int * v1936 = v1926->regs;
  int v1947 = v1932 & v1934;
  v1936[10] = v1947;
  struct StateT * v1938 = slot_24(v1926);
  return v1938;
}

struct StateT * slot_5(struct StateT * v284) {
  int v285 = v284->timer;
  int v296 = v285 + 1;
  v284->timer = v296;
  int * v287 = v284->reg_ready;
  int v288 = v287[11];
  int * v289 = v284->regs;
  int v290 = v289[11];
  int v300 = (v288 + ((v285 - v288) & (~((v285 - v288) >> 31)))) + 1;
  v287[11] = v300;
  int * v292 = v284->regs;
  int v302 = v290 + 72;
  v292[11] = v302;
  struct StateT * v294 = slot_6(v284);
  return v294;
}

struct StateT * slot_2(struct StateT * v225) {
  int v226 = v225->timer;
  int v230 = v226 + 1;
  v225->timer = v230;
  struct StateT * v228 = slot_3(v225);
  return v228;
}

struct StateT * slot_7(struct StateT * v329) {
  int v330 = v329->timer;
  int v442 = v330 + 1;
  v329->timer = v442;
  int * v332 = v329->reg_ready;
  int v333 = v332[10];
  int * v334 = v329->regs;
  int v335 = v334[10];
  int * v336 = v329->cache_tags;
  int v447 = (((int)((unsigned int)((int)((unsigned int)v335 >> 2)) >> 1)) & 1) * 2;
  int v337 = v336[v447];
  int v448 = ((((int)((unsigned int)((int)((unsigned int)v335 >> 2)) >> 1)) & 1) * 2) + 1;
  int v338 = v336[v448];
  int v449 = 4 + ((((int)((unsigned int)((int)((unsigned int)v335 >> 2)) >> 1)) & 3) * 2);
  int v339 = v336[v449];
  int v450 = (4 + ((((int)((unsigned int)((int)((unsigned int)v335 >> 2)) >> 1)) & 3) * 2)) + 1;
  int v340 = v336[v450];
  int * v341 = v329->cache_vals;
  bool v451 = !(((~(((v337 ^ ((int)((unsigned int)((int)((unsigned int)v335 >> 2)) >> 1))) | (-(v337 ^ ((int)((unsigned int)((int)((unsigned int)v335 >> 2)) >> 1))))) >> 31)) | (~(((v338 ^ ((int)((unsigned int)((int)((unsigned int)v335 >> 2)) >> 1))) | (-(v338 ^ ((int)((unsigned int)((int)((unsigned int)v335 >> 2)) >> 1))))) >> 31))) == 0);
  int v434;
  if (v451) {
    int * v342 = v329->cache_age;
    int v453 = ((((int)((unsigned int)((int)((unsigned int)v335 >> 2)) >> 1)) & 1) * 2) + ((~(((v338 ^ ((int)((unsigned int)((int)((unsigned int)v335 >> 2)) >> 1))) | (-(v338 ^ ((int)((unsigned int)((int)((unsigned int)v335 >> 2)) >> 1))))) >> 31)) & 1);
    int v343 = v342[v453];
    int v344 = v342[v447];
    int v454 = v344 + ((int)((unsigned int)(v344 - v343) >> 31));
    v342[v447] = v454;
    int * v346 = v329->cache_age;
    int v347 = v346[v448];
    int v456 = v347 + ((int)((unsigned int)(v347 - v343) >> 31));
    v346[v448] = v456;
    int * v349 = v329->cache_age;
    v349[v453] = 0;
    v434 = v453;
  } else {
    int * v352 = v329->cache_age;
    int v460 = (((int)((unsigned int)((int)((unsigned int)v335 >> 2)) >> 1)) & 1) * 2;
    int v353 = v352[v460];
    int * v354 = v329->cache_tags;
    int v355 = v354[v460];
    int v356 = v352[v448];
    int v357 = v354[v448];
    bool v462 = !(((~(((v339 ^ ((int)((unsigned int)((int)((unsigned int)v335 >> 2)) >> 1))) | (-(v339 ^ ((int)((unsigned int)((int)((unsigned int)v335 >> 2)) >> 1))))) >> 31)) | (~(((v340 ^ ((int)((unsigned int)((int)((unsigned int)v335 >> 2)) >> 1))) | (-(v340 ^ ((int)((unsigned int)((int)((unsigned int)v335 >> 2)) >> 1))))) >> 31))) == 0);
    int v411;
    if (v462) {
      int * v358 = v329->cache_age;
      int v464 = (4 + ((((int)((unsigned int)((int)((unsigned int)v335 >> 2)) >> 1)) & 3) * 2)) + ((~(((v340 ^ ((int)((unsigned int)((int)((unsigned int)v335 >> 2)) >> 1))) | (-(v340 ^ ((int)((unsigned int)((int)((unsigned int)v335 >> 2)) >> 1))))) >> 31)) & 1);
      int v359 = v358[v464];
      int v360 = v358[v449];
      int v465 = v360 + ((int)((unsigned int)(v360 - v359) >> 31));
      v358[v449] = v465;
      int * v362 = v329->cache_age;
      int v363 = v362[v450];
      int v467 = v363 + ((int)((unsigned int)(v363 - v359) >> 31));
      v362[v450] = v467;
      int * v365 = v329->cache_age;
      v365[v464] = 0;
      v411 = v464;
    } else {
      int * v368 = v329->cache_age;
      int v471 = 4 + ((((int)((unsigned int)((int)((unsigned int)v335 >> 2)) >> 1)) & 3) * 2);
      int v369 = v368[v471];
      int * v370 = v329->cache_tags;
      int v371 = v370[v471];
      int v372 = v368[v450];
      int v373 = v370[v450];
      int * v374 = v329->cache_dirty;
      int v474 = (4 + ((((int)((unsigned int)((int)((unsigned int)v335 >> 2)) >> 1)) & 3) * 2)) + ((((v369 + ((~(((v371 ^ -1) | (-(v371 ^ -1))) >> 31)) & 2)) - (v372 + ((~(((v373 ^ -1) | (-(v373 ^ -1))) >> 31)) & 2))) >> 31) & 1);
      int v375 = v374[v474];
      bool v475 = !(v375 == 0);
      if (v475) {
        int * v376 = v329->cache_tags;
        int v377 = v376[v474];
        int * v378 = v329->cache_vals;
        int v478 = ((4 + ((((int)((unsigned int)((int)((unsigned int)v335 >> 2)) >> 1)) & 3) * 2)) + ((((v369 + ((~(((v371 ^ -1) | (-(v371 ^ -1))) >> 31)) & 2)) - (v372 + ((~(((v373 ^ -1) | (-(v373 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
        int v379 = v378[v478];
        int v479 = (((4 + ((((int)((unsigned int)((int)((unsigned int)v335 >> 2)) >> 1)) & 3) * 2)) + ((((v369 + ((~(((v371 ^ -1) | (-(v371 ^ -1))) >> 31)) & 2)) - (v372 + ((~(((v373 ^ -1) | (-(v373 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
        int v380 = v378[v479];
        int * v381 = v329->mem;
        int v481 = v377 * 2;
        v381[v481] = v379;
        int * v383 = v329->mem;
        int v484 = (v377 * 2) + 1;
        v383[v484] = v380;
        ;
      } else {
        ;
      }
      int * v388 = v329->mem;
      int v489 = ((int)((unsigned int)((int)((unsigned int)v335 >> 2)) >> 1)) * 2;
      int v389 = v388[v489];
      int v490 = (((int)((unsigned int)((int)((unsigned int)v335 >> 2)) >> 1)) * 2) + 1;
      int v390 = v388[v490];
      int * v391 = v329->cache_vals;
      int v492 = ((4 + ((((int)((unsigned int)((int)((unsigned int)v335 >> 2)) >> 1)) & 3) * 2)) + ((((v369 + ((~(((v371 ^ -1) | (-(v371 ^ -1))) >> 31)) & 2)) - (v372 + ((~(((v373 ^ -1) | (-(v373 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
      v391[v492] = v389;
      int * v393 = v329->cache_vals;
      int v495 = (((4 + ((((int)((unsigned int)((int)((unsigned int)v335 >> 2)) >> 1)) & 3) * 2)) + ((((v369 + ((~(((v371 ^ -1) | (-(v371 ^ -1))) >> 31)) & 2)) - (v372 + ((~(((v373 ^ -1) | (-(v373 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
      v393[v495] = v390;
      int * v395 = v329->cache_tags;
      int v498 = (int)((unsigned int)((int)((unsigned int)v335 >> 2)) >> 1);
      v395[v474] = v498;
      int * v397 = v329->cache_dirty;
      v397[v474] = 0;
      int * v399 = v329->cache_age;
      v399[v474] = 1;
      int * v401 = v329->cache_age;
      int v402 = v401[v474];
      int v403 = v401[v449];
      int v504 = v403 + ((int)((unsigned int)(v403 - v402) >> 31));
      v401[v449] = v504;
      int * v405 = v329->cache_age;
      int v406 = v405[v450];
      int v506 = v406 + ((int)((unsigned int)(v406 - v402) >> 31));
      v405[v450] = v506;
      int * v408 = v329->cache_age;
      v408[v474] = 0;
      v411 = v474;
    }
    int * v412 = v329->cache_vals;
    int v509 = v411 * 2;
    int v413 = v412[v509];
    int v510 = (v411 * 2) + 1;
    int v414 = v412[v510];
    int v511 = (((((int)((unsigned int)((int)((unsigned int)v335 >> 2)) >> 1)) & 1) * 2) + ((((v353 + ((~(((v355 ^ -1) | (-(v355 ^ -1))) >> 31)) & 2)) - (v356 + ((~(((v357 ^ -1) | (-(v357 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
    v412[v511] = v413;
    int * v416 = v329->cache_vals;
    int v514 = ((((((int)((unsigned int)((int)((unsigned int)v335 >> 2)) >> 1)) & 1) * 2) + ((((v353 + ((~(((v355 ^ -1) | (-(v355 ^ -1))) >> 31)) & 2)) - (v356 + ((~(((v357 ^ -1) | (-(v357 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
    v416[v514] = v414;
    int * v418 = v329->cache_tags;
    int v517 = ((((int)((unsigned int)((int)((unsigned int)v335 >> 2)) >> 1)) & 1) * 2) + ((((v353 + ((~(((v355 ^ -1) | (-(v355 ^ -1))) >> 31)) & 2)) - (v356 + ((~(((v357 ^ -1) | (-(v357 ^ -1))) >> 31)) & 2))) >> 31) & 1);
    int v518 = (int)((unsigned int)((int)((unsigned int)v335 >> 2)) >> 1);
    v418[v517] = v518;
    int * v420 = v329->cache_dirty;
    v420[v517] = 0;
    int * v422 = v329->cache_age;
    v422[v517] = 1;
    int * v424 = v329->cache_age;
    int v425 = v424[v517];
    int v426 = v424[v447];
    int v524 = v426 + ((int)((unsigned int)(v426 - v425) >> 31));
    v424[v447] = v524;
    int * v428 = v329->cache_age;
    int v429 = v428[v448];
    int v526 = v429 + ((int)((unsigned int)(v429 - v425) >> 31));
    v428[v448] = v526;
    int * v431 = v329->cache_age;
    v431[v517] = 0;
    v434 = v517;
  }
  int v529 = (v434 * 2) + (((int)((unsigned int)v335 >> 2)) & 1);
  int v435 = v341[v529];
  int * v436 = v329->reg_ready;
  int v531 = ((v333 + ((v330 - v333) & (~((v330 - v333) >> 31)))) + 1) + ((100 ^ (((~(((v339 ^ ((int)((unsigned int)((int)((unsigned int)v335 >> 2)) >> 1))) | (-(v339 ^ ((int)((unsigned int)((int)((unsigned int)v335 >> 2)) >> 1))))) >> 31)) | (~(((v340 ^ ((int)((unsigned int)((int)((unsigned int)v335 >> 2)) >> 1))) | (-(v340 ^ ((int)((unsigned int)((int)((unsigned int)v335 >> 2)) >> 1))))) >> 31))) & 104)) ^ (((~(((v337 ^ ((int)((unsigned int)((int)((unsigned int)v335 >> 2)) >> 1))) | (-(v337 ^ ((int)((unsigned int)((int)((unsigned int)v335 >> 2)) >> 1))))) >> 31)) | (~(((v338 ^ ((int)((unsigned int)((int)((unsigned int)v335 >> 2)) >> 1))) | (-(v338 ^ ((int)((unsigned int)((int)((unsigned int)v335 >> 2)) >> 1))))) >> 31))) & (1 ^ (100 ^ (((~(((v339 ^ ((int)((unsigned int)((int)((unsigned int)v335 >> 2)) >> 1))) | (-(v339 ^ ((int)((unsigned int)((int)((unsigned int)v335 >> 2)) >> 1))))) >> 31)) | (~(((v340 ^ ((int)((unsigned int)((int)((unsigned int)v335 >> 2)) >> 1))) | (-(v340 ^ ((int)((unsigned int)((int)((unsigned int)v335 >> 2)) >> 1))))) >> 31))) & 104)))));
  v436[10] = v531;
  int * v438 = v329->regs;
  v438[10] = v435;
  struct StateT * v440 = slot_8(v329);
  return v440;
}

struct StateT * slot_21(struct StateT * v1511) {
  int v1512 = v1511->timer;
  int v1624 = v1512 + 1;
  v1511->timer = v1624;
  int * v1514 = v1511->reg_ready;
  int v1515 = v1514[10];
  int * v1516 = v1511->regs;
  int v1517 = v1516[10];
  int * v1518 = v1511->cache_tags;
  int v1629 = (((int)((unsigned int)((int)((unsigned int)(v1517 + 4) >> 2)) >> 1)) & 1) * 2;
  int v1519 = v1518[v1629];
  int v1630 = ((((int)((unsigned int)((int)((unsigned int)(v1517 + 4) >> 2)) >> 1)) & 1) * 2) + 1;
  int v1520 = v1518[v1630];
  int v1631 = 4 + ((((int)((unsigned int)((int)((unsigned int)(v1517 + 4) >> 2)) >> 1)) & 3) * 2);
  int v1521 = v1518[v1631];
  int v1632 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v1517 + 4) >> 2)) >> 1)) & 3) * 2)) + 1;
  int v1522 = v1518[v1632];
  int * v1523 = v1511->cache_vals;
  bool v1633 = !(((~(((v1519 ^ ((int)((unsigned int)((int)((unsigned int)(v1517 + 4) >> 2)) >> 1))) | (-(v1519 ^ ((int)((unsigned int)((int)((unsigned int)(v1517 + 4) >> 2)) >> 1))))) >> 31)) | (~(((v1520 ^ ((int)((unsigned int)((int)((unsigned int)(v1517 + 4) >> 2)) >> 1))) | (-(v1520 ^ ((int)((unsigned int)((int)((unsigned int)(v1517 + 4) >> 2)) >> 1))))) >> 31))) == 0);
  int v1616;
  if (v1633) {
    int * v1524 = v1511->cache_age;
    int v1635 = ((((int)((unsigned int)((int)((unsigned int)(v1517 + 4) >> 2)) >> 1)) & 1) * 2) + ((~(((v1520 ^ ((int)((unsigned int)((int)((unsigned int)(v1517 + 4) >> 2)) >> 1))) | (-(v1520 ^ ((int)((unsigned int)((int)((unsigned int)(v1517 + 4) >> 2)) >> 1))))) >> 31)) & 1);
    int v1525 = v1524[v1635];
    int v1526 = v1524[v1629];
    int v1636 = v1526 + ((int)((unsigned int)(v1526 - v1525) >> 31));
    v1524[v1629] = v1636;
    int * v1528 = v1511->cache_age;
    int v1529 = v1528[v1630];
    int v1638 = v1529 + ((int)((unsigned int)(v1529 - v1525) >> 31));
    v1528[v1630] = v1638;
    int * v1531 = v1511->cache_age;
    v1531[v1635] = 0;
    v1616 = v1635;
  } else {
    int * v1534 = v1511->cache_age;
    int v1642 = (((int)((unsigned int)((int)((unsigned int)(v1517 + 4) >> 2)) >> 1)) & 1) * 2;
    int v1535 = v1534[v1642];
    int * v1536 = v1511->cache_tags;
    int v1537 = v1536[v1642];
    int v1538 = v1534[v1630];
    int v1539 = v1536[v1630];
    bool v1644 = !(((~(((v1521 ^ ((int)((unsigned int)((int)((unsigned int)(v1517 + 4) >> 2)) >> 1))) | (-(v1521 ^ ((int)((unsigned int)((int)((unsigned int)(v1517 + 4) >> 2)) >> 1))))) >> 31)) | (~(((v1522 ^ ((int)((unsigned int)((int)((unsigned int)(v1517 + 4) >> 2)) >> 1))) | (-(v1522 ^ ((int)((unsigned int)((int)((unsigned int)(v1517 + 4) >> 2)) >> 1))))) >> 31))) == 0);
    int v1593;
    if (v1644) {
      int * v1540 = v1511->cache_age;
      int v1646 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v1517 + 4) >> 2)) >> 1)) & 3) * 2)) + ((~(((v1522 ^ ((int)((unsigned int)((int)((unsigned int)(v1517 + 4) >> 2)) >> 1))) | (-(v1522 ^ ((int)((unsigned int)((int)((unsigned int)(v1517 + 4) >> 2)) >> 1))))) >> 31)) & 1);
      int v1541 = v1540[v1646];
      int v1542 = v1540[v1631];
      int v1647 = v1542 + ((int)((unsigned int)(v1542 - v1541) >> 31));
      v1540[v1631] = v1647;
      int * v1544 = v1511->cache_age;
      int v1545 = v1544[v1632];
      int v1649 = v1545 + ((int)((unsigned int)(v1545 - v1541) >> 31));
      v1544[v1632] = v1649;
      int * v1547 = v1511->cache_age;
      v1547[v1646] = 0;
      v1593 = v1646;
    } else {
      int * v1550 = v1511->cache_age;
      int v1653 = 4 + ((((int)((unsigned int)((int)((unsigned int)(v1517 + 4) >> 2)) >> 1)) & 3) * 2);
      int v1551 = v1550[v1653];
      int * v1552 = v1511->cache_tags;
      int v1553 = v1552[v1653];
      int v1554 = v1550[v1632];
      int v1555 = v1552[v1632];
      int * v1556 = v1511->cache_dirty;
      int v1656 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v1517 + 4) >> 2)) >> 1)) & 3) * 2)) + ((((v1551 + ((~(((v1553 ^ -1) | (-(v1553 ^ -1))) >> 31)) & 2)) - (v1554 + ((~(((v1555 ^ -1) | (-(v1555 ^ -1))) >> 31)) & 2))) >> 31) & 1);
      int v1557 = v1556[v1656];
      bool v1657 = !(v1557 == 0);
      if (v1657) {
        int * v1558 = v1511->cache_tags;
        int v1559 = v1558[v1656];
        int * v1560 = v1511->cache_vals;
        int v1660 = ((4 + ((((int)((unsigned int)((int)((unsigned int)(v1517 + 4) >> 2)) >> 1)) & 3) * 2)) + ((((v1551 + ((~(((v1553 ^ -1) | (-(v1553 ^ -1))) >> 31)) & 2)) - (v1554 + ((~(((v1555 ^ -1) | (-(v1555 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
        int v1561 = v1560[v1660];
        int v1661 = (((4 + ((((int)((unsigned int)((int)((unsigned int)(v1517 + 4) >> 2)) >> 1)) & 3) * 2)) + ((((v1551 + ((~(((v1553 ^ -1) | (-(v1553 ^ -1))) >> 31)) & 2)) - (v1554 + ((~(((v1555 ^ -1) | (-(v1555 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
        int v1562 = v1560[v1661];
        int * v1563 = v1511->mem;
        int v1663 = v1559 * 2;
        v1563[v1663] = v1561;
        int * v1565 = v1511->mem;
        int v1666 = (v1559 * 2) + 1;
        v1565[v1666] = v1562;
        ;
      } else {
        ;
      }
      int * v1570 = v1511->mem;
      int v1671 = ((int)((unsigned int)((int)((unsigned int)(v1517 + 4) >> 2)) >> 1)) * 2;
      int v1571 = v1570[v1671];
      int v1672 = (((int)((unsigned int)((int)((unsigned int)(v1517 + 4) >> 2)) >> 1)) * 2) + 1;
      int v1572 = v1570[v1672];
      int * v1573 = v1511->cache_vals;
      int v1674 = ((4 + ((((int)((unsigned int)((int)((unsigned int)(v1517 + 4) >> 2)) >> 1)) & 3) * 2)) + ((((v1551 + ((~(((v1553 ^ -1) | (-(v1553 ^ -1))) >> 31)) & 2)) - (v1554 + ((~(((v1555 ^ -1) | (-(v1555 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
      v1573[v1674] = v1571;
      int * v1575 = v1511->cache_vals;
      int v1677 = (((4 + ((((int)((unsigned int)((int)((unsigned int)(v1517 + 4) >> 2)) >> 1)) & 3) * 2)) + ((((v1551 + ((~(((v1553 ^ -1) | (-(v1553 ^ -1))) >> 31)) & 2)) - (v1554 + ((~(((v1555 ^ -1) | (-(v1555 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
      v1575[v1677] = v1572;
      int * v1577 = v1511->cache_tags;
      int v1680 = (int)((unsigned int)((int)((unsigned int)(v1517 + 4) >> 2)) >> 1);
      v1577[v1656] = v1680;
      int * v1579 = v1511->cache_dirty;
      v1579[v1656] = 0;
      int * v1581 = v1511->cache_age;
      v1581[v1656] = 1;
      int * v1583 = v1511->cache_age;
      int v1584 = v1583[v1656];
      int v1585 = v1583[v1631];
      int v1686 = v1585 + ((int)((unsigned int)(v1585 - v1584) >> 31));
      v1583[v1631] = v1686;
      int * v1587 = v1511->cache_age;
      int v1588 = v1587[v1632];
      int v1688 = v1588 + ((int)((unsigned int)(v1588 - v1584) >> 31));
      v1587[v1632] = v1688;
      int * v1590 = v1511->cache_age;
      v1590[v1656] = 0;
      v1593 = v1656;
    }
    int * v1594 = v1511->cache_vals;
    int v1691 = v1593 * 2;
    int v1595 = v1594[v1691];
    int v1692 = (v1593 * 2) + 1;
    int v1596 = v1594[v1692];
    int v1693 = (((((int)((unsigned int)((int)((unsigned int)(v1517 + 4) >> 2)) >> 1)) & 1) * 2) + ((((v1535 + ((~(((v1537 ^ -1) | (-(v1537 ^ -1))) >> 31)) & 2)) - (v1538 + ((~(((v1539 ^ -1) | (-(v1539 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
    v1594[v1693] = v1595;
    int * v1598 = v1511->cache_vals;
    int v1696 = ((((((int)((unsigned int)((int)((unsigned int)(v1517 + 4) >> 2)) >> 1)) & 1) * 2) + ((((v1535 + ((~(((v1537 ^ -1) | (-(v1537 ^ -1))) >> 31)) & 2)) - (v1538 + ((~(((v1539 ^ -1) | (-(v1539 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
    v1598[v1696] = v1596;
    int * v1600 = v1511->cache_tags;
    int v1699 = ((((int)((unsigned int)((int)((unsigned int)(v1517 + 4) >> 2)) >> 1)) & 1) * 2) + ((((v1535 + ((~(((v1537 ^ -1) | (-(v1537 ^ -1))) >> 31)) & 2)) - (v1538 + ((~(((v1539 ^ -1) | (-(v1539 ^ -1))) >> 31)) & 2))) >> 31) & 1);
    int v1700 = (int)((unsigned int)((int)((unsigned int)(v1517 + 4) >> 2)) >> 1);
    v1600[v1699] = v1700;
    int * v1602 = v1511->cache_dirty;
    v1602[v1699] = 0;
    int * v1604 = v1511->cache_age;
    v1604[v1699] = 1;
    int * v1606 = v1511->cache_age;
    int v1607 = v1606[v1699];
    int v1608 = v1606[v1629];
    int v1706 = v1608 + ((int)((unsigned int)(v1608 - v1607) >> 31));
    v1606[v1629] = v1706;
    int * v1610 = v1511->cache_age;
    int v1611 = v1610[v1630];
    int v1708 = v1611 + ((int)((unsigned int)(v1611 - v1607) >> 31));
    v1610[v1630] = v1708;
    int * v1613 = v1511->cache_age;
    v1613[v1699] = 0;
    v1616 = v1699;
  }
  int v1711 = (v1616 * 2) + (((int)((unsigned int)(v1517 + 4) >> 2)) & 1);
  int v1617 = v1523[v1711];
  int * v1618 = v1511->reg_ready;
  int v1713 = ((v1515 + ((v1512 - v1515) & (~((v1512 - v1515) >> 31)))) + 1) + ((100 ^ (((~(((v1521 ^ ((int)((unsigned int)((int)((unsigned int)(v1517 + 4) >> 2)) >> 1))) | (-(v1521 ^ ((int)((unsigned int)((int)((unsigned int)(v1517 + 4) >> 2)) >> 1))))) >> 31)) | (~(((v1522 ^ ((int)((unsigned int)((int)((unsigned int)(v1517 + 4) >> 2)) >> 1))) | (-(v1522 ^ ((int)((unsigned int)((int)((unsigned int)(v1517 + 4) >> 2)) >> 1))))) >> 31))) & 104)) ^ (((~(((v1519 ^ ((int)((unsigned int)((int)((unsigned int)(v1517 + 4) >> 2)) >> 1))) | (-(v1519 ^ ((int)((unsigned int)((int)((unsigned int)(v1517 + 4) >> 2)) >> 1))))) >> 31)) | (~(((v1520 ^ ((int)((unsigned int)((int)((unsigned int)(v1517 + 4) >> 2)) >> 1))) | (-(v1520 ^ ((int)((unsigned int)((int)((unsigned int)(v1517 + 4) >> 2)) >> 1))))) >> 31))) & (1 ^ (100 ^ (((~(((v1521 ^ ((int)((unsigned int)((int)((unsigned int)(v1517 + 4) >> 2)) >> 1))) | (-(v1521 ^ ((int)((unsigned int)((int)((unsigned int)(v1517 + 4) >> 2)) >> 1))))) >> 31)) | (~(((v1522 ^ ((int)((unsigned int)((int)((unsigned int)(v1517 + 4) >> 2)) >> 1))) | (-(v1522 ^ ((int)((unsigned int)((int)((unsigned int)(v1517 + 4) >> 2)) >> 1))))) >> 31))) & 104)))));
  v1618[10] = v1713;
  int * v1620 = v1511->regs;
  v1620[10] = v1617;
  struct StateT * v1622 = slot_22(v1511);
  return v1622;
}

struct StateT * slot_3(struct StateT * v233) {
  int * v234 = v233->saved_regs;
  int * v235 = v233->regs;
  int v236 = v235[10];
  v234[10] = v236;
  int v238 = v233->timer;
  int v253 = v238 + 1;
  v233->timer = v253;
  int * v240 = v233->reg_ready;
  int v241 = v240[10];
  int * v242 = v233->regs;
  int v243 = v242[10];
  int v256 = (v241 + ((v238 - v241) & (~((v238 - v241) >> 31)))) + 1;
  v240[10] = v256;
  int * v245 = v233->regs;
  int v258 = v243 << 2;
  v245[10] = v258;
  struct StateT * v247 = slot_4(v233);
  return v247;
}

struct StateT * slot_10(struct StateT * v573) {
  int * v574 = v573->saved_regs;
  int * v575 = v573->regs;
  int v576 = v575[12];
  v574[12] = v576;
  int v578 = v573->timer;
  int v590 = v578 + 1;
  v573->timer = v590;
  int * v580 = v573->reg_ready;
  v580[12] = v590;
  int * v582 = v573->regs;
  v582[12] = 0;
  struct StateT * v584 = slot_11(v573);
  return v584;
}

struct StateT * slot_1(struct StateT * v18) {
  int v19 = v18->timer;
  int v131 = v19 + 1;
  v18->timer = v131;
  int * v21 = v18->reg_ready;
  int v22 = v21[11];
  int * v23 = v18->regs;
  int v24 = v23[11];
  int * v25 = v18->cache_tags;
  int v136 = (((int)((unsigned int)((int)((unsigned int)v24 >> 2)) >> 1)) & 1) * 2;
  int v26 = v25[v136];
  int v137 = ((((int)((unsigned int)((int)((unsigned int)v24 >> 2)) >> 1)) & 1) * 2) + 1;
  int v27 = v25[v137];
  int v138 = 4 + ((((int)((unsigned int)((int)((unsigned int)v24 >> 2)) >> 1)) & 3) * 2);
  int v28 = v25[v138];
  int v139 = (4 + ((((int)((unsigned int)((int)((unsigned int)v24 >> 2)) >> 1)) & 3) * 2)) + 1;
  int v29 = v25[v139];
  int * v30 = v18->cache_vals;
  bool v140 = !(((~(((v26 ^ ((int)((unsigned int)((int)((unsigned int)v24 >> 2)) >> 1))) | (-(v26 ^ ((int)((unsigned int)((int)((unsigned int)v24 >> 2)) >> 1))))) >> 31)) | (~(((v27 ^ ((int)((unsigned int)((int)((unsigned int)v24 >> 2)) >> 1))) | (-(v27 ^ ((int)((unsigned int)((int)((unsigned int)v24 >> 2)) >> 1))))) >> 31))) == 0);
  int v123;
  if (v140) {
    int * v31 = v18->cache_age;
    int v142 = ((((int)((unsigned int)((int)((unsigned int)v24 >> 2)) >> 1)) & 1) * 2) + ((~(((v27 ^ ((int)((unsigned int)((int)((unsigned int)v24 >> 2)) >> 1))) | (-(v27 ^ ((int)((unsigned int)((int)((unsigned int)v24 >> 2)) >> 1))))) >> 31)) & 1);
    int v32 = v31[v142];
    int v33 = v31[v136];
    int v143 = v33 + ((int)((unsigned int)(v33 - v32) >> 31));
    v31[v136] = v143;
    int * v35 = v18->cache_age;
    int v36 = v35[v137];
    int v145 = v36 + ((int)((unsigned int)(v36 - v32) >> 31));
    v35[v137] = v145;
    int * v38 = v18->cache_age;
    v38[v142] = 0;
    v123 = v142;
  } else {
    int * v41 = v18->cache_age;
    int v149 = (((int)((unsigned int)((int)((unsigned int)v24 >> 2)) >> 1)) & 1) * 2;
    int v42 = v41[v149];
    int * v43 = v18->cache_tags;
    int v44 = v43[v149];
    int v45 = v41[v137];
    int v46 = v43[v137];
    bool v151 = !(((~(((v28 ^ ((int)((unsigned int)((int)((unsigned int)v24 >> 2)) >> 1))) | (-(v28 ^ ((int)((unsigned int)((int)((unsigned int)v24 >> 2)) >> 1))))) >> 31)) | (~(((v29 ^ ((int)((unsigned int)((int)((unsigned int)v24 >> 2)) >> 1))) | (-(v29 ^ ((int)((unsigned int)((int)((unsigned int)v24 >> 2)) >> 1))))) >> 31))) == 0);
    int v100;
    if (v151) {
      int * v47 = v18->cache_age;
      int v153 = (4 + ((((int)((unsigned int)((int)((unsigned int)v24 >> 2)) >> 1)) & 3) * 2)) + ((~(((v29 ^ ((int)((unsigned int)((int)((unsigned int)v24 >> 2)) >> 1))) | (-(v29 ^ ((int)((unsigned int)((int)((unsigned int)v24 >> 2)) >> 1))))) >> 31)) & 1);
      int v48 = v47[v153];
      int v49 = v47[v138];
      int v154 = v49 + ((int)((unsigned int)(v49 - v48) >> 31));
      v47[v138] = v154;
      int * v51 = v18->cache_age;
      int v52 = v51[v139];
      int v156 = v52 + ((int)((unsigned int)(v52 - v48) >> 31));
      v51[v139] = v156;
      int * v54 = v18->cache_age;
      v54[v153] = 0;
      v100 = v153;
    } else {
      int * v57 = v18->cache_age;
      int v160 = 4 + ((((int)((unsigned int)((int)((unsigned int)v24 >> 2)) >> 1)) & 3) * 2);
      int v58 = v57[v160];
      int * v59 = v18->cache_tags;
      int v60 = v59[v160];
      int v61 = v57[v139];
      int v62 = v59[v139];
      int * v63 = v18->cache_dirty;
      int v163 = (4 + ((((int)((unsigned int)((int)((unsigned int)v24 >> 2)) >> 1)) & 3) * 2)) + ((((v58 + ((~(((v60 ^ -1) | (-(v60 ^ -1))) >> 31)) & 2)) - (v61 + ((~(((v62 ^ -1) | (-(v62 ^ -1))) >> 31)) & 2))) >> 31) & 1);
      int v64 = v63[v163];
      bool v164 = !(v64 == 0);
      if (v164) {
        int * v65 = v18->cache_tags;
        int v66 = v65[v163];
        int * v67 = v18->cache_vals;
        int v167 = ((4 + ((((int)((unsigned int)((int)((unsigned int)v24 >> 2)) >> 1)) & 3) * 2)) + ((((v58 + ((~(((v60 ^ -1) | (-(v60 ^ -1))) >> 31)) & 2)) - (v61 + ((~(((v62 ^ -1) | (-(v62 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
        int v68 = v67[v167];
        int v168 = (((4 + ((((int)((unsigned int)((int)((unsigned int)v24 >> 2)) >> 1)) & 3) * 2)) + ((((v58 + ((~(((v60 ^ -1) | (-(v60 ^ -1))) >> 31)) & 2)) - (v61 + ((~(((v62 ^ -1) | (-(v62 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
        int v69 = v67[v168];
        int * v70 = v18->mem;
        int v170 = v66 * 2;
        v70[v170] = v68;
        int * v72 = v18->mem;
        int v173 = (v66 * 2) + 1;
        v72[v173] = v69;
        ;
      } else {
        ;
      }
      int * v77 = v18->mem;
      int v178 = ((int)((unsigned int)((int)((unsigned int)v24 >> 2)) >> 1)) * 2;
      int v78 = v77[v178];
      int v179 = (((int)((unsigned int)((int)((unsigned int)v24 >> 2)) >> 1)) * 2) + 1;
      int v79 = v77[v179];
      int * v80 = v18->cache_vals;
      int v181 = ((4 + ((((int)((unsigned int)((int)((unsigned int)v24 >> 2)) >> 1)) & 3) * 2)) + ((((v58 + ((~(((v60 ^ -1) | (-(v60 ^ -1))) >> 31)) & 2)) - (v61 + ((~(((v62 ^ -1) | (-(v62 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
      v80[v181] = v78;
      int * v82 = v18->cache_vals;
      int v184 = (((4 + ((((int)((unsigned int)((int)((unsigned int)v24 >> 2)) >> 1)) & 3) * 2)) + ((((v58 + ((~(((v60 ^ -1) | (-(v60 ^ -1))) >> 31)) & 2)) - (v61 + ((~(((v62 ^ -1) | (-(v62 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
      v82[v184] = v79;
      int * v84 = v18->cache_tags;
      int v187 = (int)((unsigned int)((int)((unsigned int)v24 >> 2)) >> 1);
      v84[v163] = v187;
      int * v86 = v18->cache_dirty;
      v86[v163] = 0;
      int * v88 = v18->cache_age;
      v88[v163] = 1;
      int * v90 = v18->cache_age;
      int v91 = v90[v163];
      int v92 = v90[v138];
      int v193 = v92 + ((int)((unsigned int)(v92 - v91) >> 31));
      v90[v138] = v193;
      int * v94 = v18->cache_age;
      int v95 = v94[v139];
      int v195 = v95 + ((int)((unsigned int)(v95 - v91) >> 31));
      v94[v139] = v195;
      int * v97 = v18->cache_age;
      v97[v163] = 0;
      v100 = v163;
    }
    int * v101 = v18->cache_vals;
    int v198 = v100 * 2;
    int v102 = v101[v198];
    int v199 = (v100 * 2) + 1;
    int v103 = v101[v199];
    int v200 = (((((int)((unsigned int)((int)((unsigned int)v24 >> 2)) >> 1)) & 1) * 2) + ((((v42 + ((~(((v44 ^ -1) | (-(v44 ^ -1))) >> 31)) & 2)) - (v45 + ((~(((v46 ^ -1) | (-(v46 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
    v101[v200] = v102;
    int * v105 = v18->cache_vals;
    int v203 = ((((((int)((unsigned int)((int)((unsigned int)v24 >> 2)) >> 1)) & 1) * 2) + ((((v42 + ((~(((v44 ^ -1) | (-(v44 ^ -1))) >> 31)) & 2)) - (v45 + ((~(((v46 ^ -1) | (-(v46 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
    v105[v203] = v103;
    int * v107 = v18->cache_tags;
    int v206 = ((((int)((unsigned int)((int)((unsigned int)v24 >> 2)) >> 1)) & 1) * 2) + ((((v42 + ((~(((v44 ^ -1) | (-(v44 ^ -1))) >> 31)) & 2)) - (v45 + ((~(((v46 ^ -1) | (-(v46 ^ -1))) >> 31)) & 2))) >> 31) & 1);
    int v207 = (int)((unsigned int)((int)((unsigned int)v24 >> 2)) >> 1);
    v107[v206] = v207;
    int * v109 = v18->cache_dirty;
    v109[v206] = 0;
    int * v111 = v18->cache_age;
    v111[v206] = 1;
    int * v113 = v18->cache_age;
    int v114 = v113[v206];
    int v115 = v113[v136];
    int v213 = v115 + ((int)((unsigned int)(v115 - v114) >> 31));
    v113[v136] = v213;
    int * v117 = v18->cache_age;
    int v118 = v117[v137];
    int v215 = v118 + ((int)((unsigned int)(v118 - v114) >> 31));
    v117[v137] = v215;
    int * v120 = v18->cache_age;
    v120[v206] = 0;
    v123 = v206;
  }
  int v218 = (v123 * 2) + (((int)((unsigned int)v24 >> 2)) & 1);
  int v124 = v30[v218];
  int * v125 = v18->reg_ready;
  int v220 = ((v22 + ((v19 - v22) & (~((v19 - v22) >> 31)))) + 1) + ((100 ^ (((~(((v28 ^ ((int)((unsigned int)((int)((unsigned int)v24 >> 2)) >> 1))) | (-(v28 ^ ((int)((unsigned int)((int)((unsigned int)v24 >> 2)) >> 1))))) >> 31)) | (~(((v29 ^ ((int)((unsigned int)((int)((unsigned int)v24 >> 2)) >> 1))) | (-(v29 ^ ((int)((unsigned int)((int)((unsigned int)v24 >> 2)) >> 1))))) >> 31))) & 104)) ^ (((~(((v26 ^ ((int)((unsigned int)((int)((unsigned int)v24 >> 2)) >> 1))) | (-(v26 ^ ((int)((unsigned int)((int)((unsigned int)v24 >> 2)) >> 1))))) >> 31)) | (~(((v27 ^ ((int)((unsigned int)((int)((unsigned int)v24 >> 2)) >> 1))) | (-(v27 ^ ((int)((unsigned int)((int)((unsigned int)v24 >> 2)) >> 1))))) >> 31))) & (1 ^ (100 ^ (((~(((v28 ^ ((int)((unsigned int)((int)((unsigned int)v24 >> 2)) >> 1))) | (-(v28 ^ ((int)((unsigned int)((int)((unsigned int)v24 >> 2)) >> 1))))) >> 31)) | (~(((v29 ^ ((int)((unsigned int)((int)((unsigned int)v24 >> 2)) >> 1))) | (-(v29 ^ ((int)((unsigned int)((int)((unsigned int)v24 >> 2)) >> 1))))) >> 31))) & 104)))));
  v125[11] = v220;
  int * v127 = v18->regs;
  v127[11] = v124;
  struct StateT * v129 = slot_2(v18);
  return v129;
}

struct StateT * slot_19(struct StateT * v1176) {
  int v1177 = v1176->timer;
  int v1350 = v1177 + 1;
  v1176->timer = v1350;
  int * v1179 = v1176->reg_ready;
  int * v1181 = v1176->regs;
  int v1182 = v1181[12];
  int v1184 = v1181[10];
  int * v1185 = v1176->cache_tags;
  int v1356 = (((int)((unsigned int)((int)((unsigned int)(v1182 + 68) >> 2)) >> 1)) & 1) * 2;
  int v1186 = v1185[v1356];
  int v1357 = ((((int)((unsigned int)((int)((unsigned int)(v1182 + 68) >> 2)) >> 1)) & 1) * 2) + 1;
  int v1187 = v1185[v1357];
  int v1358 = 4 + ((((int)((unsigned int)((int)((unsigned int)(v1182 + 68) >> 2)) >> 1)) & 3) * 2);
  int v1188 = v1185[v1358];
  int v1359 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v1182 + 68) >> 2)) >> 1)) & 3) * 2)) + 1;
  int v1189 = v1185[v1359];
  int v1190 = v1176->timer;
  int v1360 = v1190 + ((100 ^ (((~(((v1188 ^ ((int)((unsigned int)((int)((unsigned int)(v1182 + 68) >> 2)) >> 1))) | (-(v1188 ^ ((int)((unsigned int)((int)((unsigned int)(v1182 + 68) >> 2)) >> 1))))) >> 31)) | (~(((v1189 ^ ((int)((unsigned int)((int)((unsigned int)(v1182 + 68) >> 2)) >> 1))) | (-(v1189 ^ ((int)((unsigned int)((int)((unsigned int)(v1182 + 68) >> 2)) >> 1))))) >> 31))) & 104)) ^ (((~(((v1186 ^ ((int)((unsigned int)((int)((unsigned int)(v1182 + 68) >> 2)) >> 1))) | (-(v1186 ^ ((int)((unsigned int)((int)((unsigned int)(v1182 + 68) >> 2)) >> 1))))) >> 31)) | (~(((v1187 ^ ((int)((unsigned int)((int)((unsigned int)(v1182 + 68) >> 2)) >> 1))) | (-(v1187 ^ ((int)((unsigned int)((int)((unsigned int)(v1182 + 68) >> 2)) >> 1))))) >> 31))) & (1 ^ (100 ^ (((~(((v1188 ^ ((int)((unsigned int)((int)((unsigned int)(v1182 + 68) >> 2)) >> 1))) | (-(v1188 ^ ((int)((unsigned int)((int)((unsigned int)(v1182 + 68) >> 2)) >> 1))))) >> 31)) | (~(((v1189 ^ ((int)((unsigned int)((int)((unsigned int)(v1182 + 68) >> 2)) >> 1))) | (-(v1189 ^ ((int)((unsigned int)((int)((unsigned int)(v1182 + 68) >> 2)) >> 1))))) >> 31))) & 104)))));
  v1176->timer = v1360;
  bool v1361 = !(((~(((v1186 ^ ((int)((unsigned int)((int)((unsigned int)(v1182 + 68) >> 2)) >> 1))) | (-(v1186 ^ ((int)((unsigned int)((int)((unsigned int)(v1182 + 68) >> 2)) >> 1))))) >> 31)) | (~(((v1187 ^ ((int)((unsigned int)((int)((unsigned int)(v1182 + 68) >> 2)) >> 1))) | (-(v1187 ^ ((int)((unsigned int)((int)((unsigned int)(v1182 + 68) >> 2)) >> 1))))) >> 31))) == 0);
  int v1284;
  if (v1361) {
    int * v1192 = v1176->cache_age;
    int v1363 = ((((int)((unsigned int)((int)((unsigned int)(v1182 + 68) >> 2)) >> 1)) & 1) * 2) + ((~(((v1187 ^ ((int)((unsigned int)((int)((unsigned int)(v1182 + 68) >> 2)) >> 1))) | (-(v1187 ^ ((int)((unsigned int)((int)((unsigned int)(v1182 + 68) >> 2)) >> 1))))) >> 31)) & 1);
    int v1193 = v1192[v1363];
    int v1194 = v1192[v1356];
    int v1364 = v1194 + ((int)((unsigned int)(v1194 - v1193) >> 31));
    v1192[v1356] = v1364;
    int * v1196 = v1176->cache_age;
    int v1197 = v1196[v1357];
    int v1366 = v1197 + ((int)((unsigned int)(v1197 - v1193) >> 31));
    v1196[v1357] = v1366;
    int * v1199 = v1176->cache_age;
    v1199[v1363] = 0;
    v1284 = v1363;
  } else {
    int * v1202 = v1176->cache_age;
    int v1370 = (((int)((unsigned int)((int)((unsigned int)(v1182 + 68) >> 2)) >> 1)) & 1) * 2;
    int v1203 = v1202[v1370];
    int * v1204 = v1176->cache_tags;
    int v1205 = v1204[v1370];
    int v1206 = v1202[v1357];
    int v1207 = v1204[v1357];
    bool v1372 = !(((~(((v1188 ^ ((int)((unsigned int)((int)((unsigned int)(v1182 + 68) >> 2)) >> 1))) | (-(v1188 ^ ((int)((unsigned int)((int)((unsigned int)(v1182 + 68) >> 2)) >> 1))))) >> 31)) | (~(((v1189 ^ ((int)((unsigned int)((int)((unsigned int)(v1182 + 68) >> 2)) >> 1))) | (-(v1189 ^ ((int)((unsigned int)((int)((unsigned int)(v1182 + 68) >> 2)) >> 1))))) >> 31))) == 0);
    int v1261;
    if (v1372) {
      int * v1208 = v1176->cache_age;
      int v1374 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v1182 + 68) >> 2)) >> 1)) & 3) * 2)) + ((~(((v1189 ^ ((int)((unsigned int)((int)((unsigned int)(v1182 + 68) >> 2)) >> 1))) | (-(v1189 ^ ((int)((unsigned int)((int)((unsigned int)(v1182 + 68) >> 2)) >> 1))))) >> 31)) & 1);
      int v1209 = v1208[v1374];
      int v1210 = v1208[v1358];
      int v1375 = v1210 + ((int)((unsigned int)(v1210 - v1209) >> 31));
      v1208[v1358] = v1375;
      int * v1212 = v1176->cache_age;
      int v1213 = v1212[v1359];
      int v1377 = v1213 + ((int)((unsigned int)(v1213 - v1209) >> 31));
      v1212[v1359] = v1377;
      int * v1215 = v1176->cache_age;
      v1215[v1374] = 0;
      v1261 = v1374;
    } else {
      int * v1218 = v1176->cache_age;
      int v1381 = 4 + ((((int)((unsigned int)((int)((unsigned int)(v1182 + 68) >> 2)) >> 1)) & 3) * 2);
      int v1219 = v1218[v1381];
      int * v1220 = v1176->cache_tags;
      int v1221 = v1220[v1381];
      int v1222 = v1218[v1359];
      int v1223 = v1220[v1359];
      int * v1224 = v1176->cache_dirty;
      int v1384 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v1182 + 68) >> 2)) >> 1)) & 3) * 2)) + ((((v1219 + ((~(((v1221 ^ -1) | (-(v1221 ^ -1))) >> 31)) & 2)) - (v1222 + ((~(((v1223 ^ -1) | (-(v1223 ^ -1))) >> 31)) & 2))) >> 31) & 1);
      int v1225 = v1224[v1384];
      bool v1385 = !(v1225 == 0);
      if (v1385) {
        int * v1226 = v1176->cache_tags;
        int v1227 = v1226[v1384];
        int * v1228 = v1176->cache_vals;
        int v1388 = ((4 + ((((int)((unsigned int)((int)((unsigned int)(v1182 + 68) >> 2)) >> 1)) & 3) * 2)) + ((((v1219 + ((~(((v1221 ^ -1) | (-(v1221 ^ -1))) >> 31)) & 2)) - (v1222 + ((~(((v1223 ^ -1) | (-(v1223 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
        int v1229 = v1228[v1388];
        int v1389 = (((4 + ((((int)((unsigned int)((int)((unsigned int)(v1182 + 68) >> 2)) >> 1)) & 3) * 2)) + ((((v1219 + ((~(((v1221 ^ -1) | (-(v1221 ^ -1))) >> 31)) & 2)) - (v1222 + ((~(((v1223 ^ -1) | (-(v1223 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
        int v1230 = v1228[v1389];
        int * v1231 = v1176->mem;
        int v1391 = v1227 * 2;
        v1231[v1391] = v1229;
        int * v1233 = v1176->mem;
        int v1394 = (v1227 * 2) + 1;
        v1233[v1394] = v1230;
        ;
      } else {
        ;
      }
      int * v1238 = v1176->mem;
      int v1399 = ((int)((unsigned int)((int)((unsigned int)(v1182 + 68) >> 2)) >> 1)) * 2;
      int v1239 = v1238[v1399];
      int v1400 = (((int)((unsigned int)((int)((unsigned int)(v1182 + 68) >> 2)) >> 1)) * 2) + 1;
      int v1240 = v1238[v1400];
      int * v1241 = v1176->cache_vals;
      int v1402 = ((4 + ((((int)((unsigned int)((int)((unsigned int)(v1182 + 68) >> 2)) >> 1)) & 3) * 2)) + ((((v1219 + ((~(((v1221 ^ -1) | (-(v1221 ^ -1))) >> 31)) & 2)) - (v1222 + ((~(((v1223 ^ -1) | (-(v1223 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
      v1241[v1402] = v1239;
      int * v1243 = v1176->cache_vals;
      int v1405 = (((4 + ((((int)((unsigned int)((int)((unsigned int)(v1182 + 68) >> 2)) >> 1)) & 3) * 2)) + ((((v1219 + ((~(((v1221 ^ -1) | (-(v1221 ^ -1))) >> 31)) & 2)) - (v1222 + ((~(((v1223 ^ -1) | (-(v1223 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
      v1243[v1405] = v1240;
      int * v1245 = v1176->cache_tags;
      int v1408 = (int)((unsigned int)((int)((unsigned int)(v1182 + 68) >> 2)) >> 1);
      v1245[v1384] = v1408;
      int * v1247 = v1176->cache_dirty;
      v1247[v1384] = 0;
      int * v1249 = v1176->cache_age;
      v1249[v1384] = 1;
      int * v1251 = v1176->cache_age;
      int v1252 = v1251[v1384];
      int v1253 = v1251[v1358];
      int v1414 = v1253 + ((int)((unsigned int)(v1253 - v1252) >> 31));
      v1251[v1358] = v1414;
      int * v1255 = v1176->cache_age;
      int v1256 = v1255[v1359];
      int v1416 = v1256 + ((int)((unsigned int)(v1256 - v1252) >> 31));
      v1255[v1359] = v1416;
      int * v1258 = v1176->cache_age;
      v1258[v1384] = 0;
      v1261 = v1384;
    }
    int * v1262 = v1176->cache_vals;
    int v1419 = v1261 * 2;
    int v1263 = v1262[v1419];
    int v1420 = (v1261 * 2) + 1;
    int v1264 = v1262[v1420];
    int v1421 = (((((int)((unsigned int)((int)((unsigned int)(v1182 + 68) >> 2)) >> 1)) & 1) * 2) + ((((v1203 + ((~(((v1205 ^ -1) | (-(v1205 ^ -1))) >> 31)) & 2)) - (v1206 + ((~(((v1207 ^ -1) | (-(v1207 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
    v1262[v1421] = v1263;
    int * v1266 = v1176->cache_vals;
    int v1424 = ((((((int)((unsigned int)((int)((unsigned int)(v1182 + 68) >> 2)) >> 1)) & 1) * 2) + ((((v1203 + ((~(((v1205 ^ -1) | (-(v1205 ^ -1))) >> 31)) & 2)) - (v1206 + ((~(((v1207 ^ -1) | (-(v1207 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
    v1266[v1424] = v1264;
    int * v1268 = v1176->cache_tags;
    int v1427 = ((((int)((unsigned int)((int)((unsigned int)(v1182 + 68) >> 2)) >> 1)) & 1) * 2) + ((((v1203 + ((~(((v1205 ^ -1) | (-(v1205 ^ -1))) >> 31)) & 2)) - (v1206 + ((~(((v1207 ^ -1) | (-(v1207 ^ -1))) >> 31)) & 2))) >> 31) & 1);
    int v1428 = (int)((unsigned int)((int)((unsigned int)(v1182 + 68) >> 2)) >> 1);
    v1268[v1427] = v1428;
    int * v1270 = v1176->cache_dirty;
    v1270[v1427] = 0;
    int * v1272 = v1176->cache_age;
    v1272[v1427] = 1;
    int * v1274 = v1176->cache_age;
    int v1275 = v1274[v1427];
    int v1276 = v1274[v1356];
    int v1434 = v1276 + ((int)((unsigned int)(v1276 - v1275) >> 31));
    v1274[v1356] = v1434;
    int * v1278 = v1176->cache_age;
    int v1279 = v1278[v1357];
    int v1436 = v1279 + ((int)((unsigned int)(v1279 - v1275) >> 31));
    v1278[v1357] = v1436;
    int * v1281 = v1176->cache_age;
    v1281[v1427] = 0;
    v1284 = v1427;
  }
  int * v1285 = v1176->cache_vals;
  int v1439 = (v1284 * 2) + (((int)((unsigned int)(v1182 + 68) >> 2)) & 1);
  v1285[v1439] = v1184;
  int * v1287 = v1176->cache_tags;
  int v1288 = v1287[v1358];
  int v1289 = v1287[v1359];
  bool v1442 = !(((~(((v1288 ^ ((int)((unsigned int)((int)((unsigned int)(v1182 + 68) >> 2)) >> 1))) | (-(v1288 ^ ((int)((unsigned int)((int)((unsigned int)(v1182 + 68) >> 2)) >> 1))))) >> 31)) | (~(((v1289 ^ ((int)((unsigned int)((int)((unsigned int)(v1182 + 68) >> 2)) >> 1))) | (-(v1289 ^ ((int)((unsigned int)((int)((unsigned int)(v1182 + 68) >> 2)) >> 1))))) >> 31))) == 0);
  int v1343;
  if (v1442) {
    int * v1290 = v1176->cache_age;
    int v1444 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v1182 + 68) >> 2)) >> 1)) & 3) * 2)) + ((~(((v1289 ^ ((int)((unsigned int)((int)((unsigned int)(v1182 + 68) >> 2)) >> 1))) | (-(v1289 ^ ((int)((unsigned int)((int)((unsigned int)(v1182 + 68) >> 2)) >> 1))))) >> 31)) & 1);
    int v1291 = v1290[v1444];
    int v1292 = v1290[v1358];
    int v1445 = v1292 + ((int)((unsigned int)(v1292 - v1291) >> 31));
    v1290[v1358] = v1445;
    int * v1294 = v1176->cache_age;
    int v1295 = v1294[v1359];
    int v1447 = v1295 + ((int)((unsigned int)(v1295 - v1291) >> 31));
    v1294[v1359] = v1447;
    int * v1297 = v1176->cache_age;
    v1297[v1444] = 0;
    v1343 = v1444;
  } else {
    int * v1300 = v1176->cache_age;
    int v1451 = 4 + ((((int)((unsigned int)((int)((unsigned int)(v1182 + 68) >> 2)) >> 1)) & 3) * 2);
    int v1301 = v1300[v1451];
    int * v1302 = v1176->cache_tags;
    int v1303 = v1302[v1451];
    int v1304 = v1300[v1359];
    int v1305 = v1302[v1359];
    int * v1306 = v1176->cache_dirty;
    int v1454 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v1182 + 68) >> 2)) >> 1)) & 3) * 2)) + ((((v1301 + ((~(((v1303 ^ -1) | (-(v1303 ^ -1))) >> 31)) & 2)) - (v1304 + ((~(((v1305 ^ -1) | (-(v1305 ^ -1))) >> 31)) & 2))) >> 31) & 1);
    int v1307 = v1306[v1454];
    bool v1455 = !(v1307 == 0);
    if (v1455) {
      int * v1308 = v1176->cache_tags;
      int v1309 = v1308[v1454];
      int * v1310 = v1176->cache_vals;
      int v1458 = ((4 + ((((int)((unsigned int)((int)((unsigned int)(v1182 + 68) >> 2)) >> 1)) & 3) * 2)) + ((((v1301 + ((~(((v1303 ^ -1) | (-(v1303 ^ -1))) >> 31)) & 2)) - (v1304 + ((~(((v1305 ^ -1) | (-(v1305 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
      int v1311 = v1310[v1458];
      int v1459 = (((4 + ((((int)((unsigned int)((int)((unsigned int)(v1182 + 68) >> 2)) >> 1)) & 3) * 2)) + ((((v1301 + ((~(((v1303 ^ -1) | (-(v1303 ^ -1))) >> 31)) & 2)) - (v1304 + ((~(((v1305 ^ -1) | (-(v1305 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
      int v1312 = v1310[v1459];
      int * v1313 = v1176->mem;
      int v1461 = v1309 * 2;
      v1313[v1461] = v1311;
      int * v1315 = v1176->mem;
      int v1464 = (v1309 * 2) + 1;
      v1315[v1464] = v1312;
      ;
    } else {
      ;
    }
    int * v1320 = v1176->mem;
    int v1469 = ((int)((unsigned int)((int)((unsigned int)(v1182 + 68) >> 2)) >> 1)) * 2;
    int v1321 = v1320[v1469];
    int v1470 = (((int)((unsigned int)((int)((unsigned int)(v1182 + 68) >> 2)) >> 1)) * 2) + 1;
    int v1322 = v1320[v1470];
    int * v1323 = v1176->cache_vals;
    int v1472 = ((4 + ((((int)((unsigned int)((int)((unsigned int)(v1182 + 68) >> 2)) >> 1)) & 3) * 2)) + ((((v1301 + ((~(((v1303 ^ -1) | (-(v1303 ^ -1))) >> 31)) & 2)) - (v1304 + ((~(((v1305 ^ -1) | (-(v1305 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
    v1323[v1472] = v1321;
    int * v1325 = v1176->cache_vals;
    int v1475 = (((4 + ((((int)((unsigned int)((int)((unsigned int)(v1182 + 68) >> 2)) >> 1)) & 3) * 2)) + ((((v1301 + ((~(((v1303 ^ -1) | (-(v1303 ^ -1))) >> 31)) & 2)) - (v1304 + ((~(((v1305 ^ -1) | (-(v1305 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
    v1325[v1475] = v1322;
    int * v1327 = v1176->cache_tags;
    int v1478 = (int)((unsigned int)((int)((unsigned int)(v1182 + 68) >> 2)) >> 1);
    v1327[v1454] = v1478;
    int * v1329 = v1176->cache_dirty;
    v1329[v1454] = 0;
    int * v1331 = v1176->cache_age;
    v1331[v1454] = 1;
    int * v1333 = v1176->cache_age;
    int v1334 = v1333[v1454];
    int v1335 = v1333[v1358];
    int v1484 = v1335 + ((int)((unsigned int)(v1335 - v1334) >> 31));
    v1333[v1358] = v1484;
    int * v1337 = v1176->cache_age;
    int v1338 = v1337[v1359];
    int v1486 = v1338 + ((int)((unsigned int)(v1338 - v1334) >> 31));
    v1337[v1359] = v1486;
    int * v1340 = v1176->cache_age;
    v1340[v1454] = 0;
    v1343 = v1454;
  }
  int * v1344 = v1176->cache_vals;
  int v1489 = (v1343 * 2) + (((int)((unsigned int)(v1182 + 68) >> 2)) & 1);
  v1344[v1489] = v1184;
  int * v1346 = v1176->cache_dirty;
  v1346[v1343] = 1;
  struct StateT * v1348 = slot_18(v1176);
  return v1348;
}

struct StateT * slot_13(struct StateT * v638) {
  int v639 = v638->timer;
  int v652 = v639 + 1;
  v638->timer = v652;
  int * v641 = v638->reg_ready;
  int v642 = v641[11];
  int * v643 = v638->regs;
  int v644 = v643[11];
  int v645 = v641[10];
  int v646 = v643[10];
  int v657 = (v645 + (((v642 + ((v639 - v642) & (~((v639 - v642) >> 31)))) - v645) & (~(((v642 + ((v639 - v642) & (~((v639 - v642) >> 31)))) - v645) >> 31)))) + 1;
  v641[10] = v657;
  int * v648 = v638->regs;
  int v659 = v644 + v646;
  v648[10] = v659;
  struct StateT * v650 = slot_14(v638);
  return v650;
}

struct StateT * slot_24(struct StateT * v1950) {
  int v1951 = v1950->timer;
  int v2124 = v1951 + 1;
  v1950->timer = v2124;
  int * v1953 = v1950->reg_ready;
  int * v1955 = v1950->regs;
  int v1956 = v1955[11];
  int v1958 = v1955[10];
  int * v1959 = v1950->cache_tags;
  int v2130 = (((int)((unsigned int)((int)((unsigned int)(v1956 + 68) >> 2)) >> 1)) & 1) * 2;
  int v1960 = v1959[v2130];
  int v2131 = ((((int)((unsigned int)((int)((unsigned int)(v1956 + 68) >> 2)) >> 1)) & 1) * 2) + 1;
  int v1961 = v1959[v2131];
  int v2132 = 4 + ((((int)((unsigned int)((int)((unsigned int)(v1956 + 68) >> 2)) >> 1)) & 3) * 2);
  int v1962 = v1959[v2132];
  int v2133 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v1956 + 68) >> 2)) >> 1)) & 3) * 2)) + 1;
  int v1963 = v1959[v2133];
  int v1964 = v1950->timer;
  int v2134 = v1964 + ((100 ^ (((~(((v1962 ^ ((int)((unsigned int)((int)((unsigned int)(v1956 + 68) >> 2)) >> 1))) | (-(v1962 ^ ((int)((unsigned int)((int)((unsigned int)(v1956 + 68) >> 2)) >> 1))))) >> 31)) | (~(((v1963 ^ ((int)((unsigned int)((int)((unsigned int)(v1956 + 68) >> 2)) >> 1))) | (-(v1963 ^ ((int)((unsigned int)((int)((unsigned int)(v1956 + 68) >> 2)) >> 1))))) >> 31))) & 104)) ^ (((~(((v1960 ^ ((int)((unsigned int)((int)((unsigned int)(v1956 + 68) >> 2)) >> 1))) | (-(v1960 ^ ((int)((unsigned int)((int)((unsigned int)(v1956 + 68) >> 2)) >> 1))))) >> 31)) | (~(((v1961 ^ ((int)((unsigned int)((int)((unsigned int)(v1956 + 68) >> 2)) >> 1))) | (-(v1961 ^ ((int)((unsigned int)((int)((unsigned int)(v1956 + 68) >> 2)) >> 1))))) >> 31))) & (1 ^ (100 ^ (((~(((v1962 ^ ((int)((unsigned int)((int)((unsigned int)(v1956 + 68) >> 2)) >> 1))) | (-(v1962 ^ ((int)((unsigned int)((int)((unsigned int)(v1956 + 68) >> 2)) >> 1))))) >> 31)) | (~(((v1963 ^ ((int)((unsigned int)((int)((unsigned int)(v1956 + 68) >> 2)) >> 1))) | (-(v1963 ^ ((int)((unsigned int)((int)((unsigned int)(v1956 + 68) >> 2)) >> 1))))) >> 31))) & 104)))));
  v1950->timer = v2134;
  bool v2135 = !(((~(((v1960 ^ ((int)((unsigned int)((int)((unsigned int)(v1956 + 68) >> 2)) >> 1))) | (-(v1960 ^ ((int)((unsigned int)((int)((unsigned int)(v1956 + 68) >> 2)) >> 1))))) >> 31)) | (~(((v1961 ^ ((int)((unsigned int)((int)((unsigned int)(v1956 + 68) >> 2)) >> 1))) | (-(v1961 ^ ((int)((unsigned int)((int)((unsigned int)(v1956 + 68) >> 2)) >> 1))))) >> 31))) == 0);
  int v2058;
  if (v2135) {
    int * v1966 = v1950->cache_age;
    int v2137 = ((((int)((unsigned int)((int)((unsigned int)(v1956 + 68) >> 2)) >> 1)) & 1) * 2) + ((~(((v1961 ^ ((int)((unsigned int)((int)((unsigned int)(v1956 + 68) >> 2)) >> 1))) | (-(v1961 ^ ((int)((unsigned int)((int)((unsigned int)(v1956 + 68) >> 2)) >> 1))))) >> 31)) & 1);
    int v1967 = v1966[v2137];
    int v1968 = v1966[v2130];
    int v2138 = v1968 + ((int)((unsigned int)(v1968 - v1967) >> 31));
    v1966[v2130] = v2138;
    int * v1970 = v1950->cache_age;
    int v1971 = v1970[v2131];
    int v2140 = v1971 + ((int)((unsigned int)(v1971 - v1967) >> 31));
    v1970[v2131] = v2140;
    int * v1973 = v1950->cache_age;
    v1973[v2137] = 0;
    v2058 = v2137;
  } else {
    int * v1976 = v1950->cache_age;
    int v2144 = (((int)((unsigned int)((int)((unsigned int)(v1956 + 68) >> 2)) >> 1)) & 1) * 2;
    int v1977 = v1976[v2144];
    int * v1978 = v1950->cache_tags;
    int v1979 = v1978[v2144];
    int v1980 = v1976[v2131];
    int v1981 = v1978[v2131];
    bool v2146 = !(((~(((v1962 ^ ((int)((unsigned int)((int)((unsigned int)(v1956 + 68) >> 2)) >> 1))) | (-(v1962 ^ ((int)((unsigned int)((int)((unsigned int)(v1956 + 68) >> 2)) >> 1))))) >> 31)) | (~(((v1963 ^ ((int)((unsigned int)((int)((unsigned int)(v1956 + 68) >> 2)) >> 1))) | (-(v1963 ^ ((int)((unsigned int)((int)((unsigned int)(v1956 + 68) >> 2)) >> 1))))) >> 31))) == 0);
    int v2035;
    if (v2146) {
      int * v1982 = v1950->cache_age;
      int v2148 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v1956 + 68) >> 2)) >> 1)) & 3) * 2)) + ((~(((v1963 ^ ((int)((unsigned int)((int)((unsigned int)(v1956 + 68) >> 2)) >> 1))) | (-(v1963 ^ ((int)((unsigned int)((int)((unsigned int)(v1956 + 68) >> 2)) >> 1))))) >> 31)) & 1);
      int v1983 = v1982[v2148];
      int v1984 = v1982[v2132];
      int v2149 = v1984 + ((int)((unsigned int)(v1984 - v1983) >> 31));
      v1982[v2132] = v2149;
      int * v1986 = v1950->cache_age;
      int v1987 = v1986[v2133];
      int v2151 = v1987 + ((int)((unsigned int)(v1987 - v1983) >> 31));
      v1986[v2133] = v2151;
      int * v1989 = v1950->cache_age;
      v1989[v2148] = 0;
      v2035 = v2148;
    } else {
      int * v1992 = v1950->cache_age;
      int v2155 = 4 + ((((int)((unsigned int)((int)((unsigned int)(v1956 + 68) >> 2)) >> 1)) & 3) * 2);
      int v1993 = v1992[v2155];
      int * v1994 = v1950->cache_tags;
      int v1995 = v1994[v2155];
      int v1996 = v1992[v2133];
      int v1997 = v1994[v2133];
      int * v1998 = v1950->cache_dirty;
      int v2158 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v1956 + 68) >> 2)) >> 1)) & 3) * 2)) + ((((v1993 + ((~(((v1995 ^ -1) | (-(v1995 ^ -1))) >> 31)) & 2)) - (v1996 + ((~(((v1997 ^ -1) | (-(v1997 ^ -1))) >> 31)) & 2))) >> 31) & 1);
      int v1999 = v1998[v2158];
      bool v2159 = !(v1999 == 0);
      if (v2159) {
        int * v2000 = v1950->cache_tags;
        int v2001 = v2000[v2158];
        int * v2002 = v1950->cache_vals;
        int v2162 = ((4 + ((((int)((unsigned int)((int)((unsigned int)(v1956 + 68) >> 2)) >> 1)) & 3) * 2)) + ((((v1993 + ((~(((v1995 ^ -1) | (-(v1995 ^ -1))) >> 31)) & 2)) - (v1996 + ((~(((v1997 ^ -1) | (-(v1997 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
        int v2003 = v2002[v2162];
        int v2163 = (((4 + ((((int)((unsigned int)((int)((unsigned int)(v1956 + 68) >> 2)) >> 1)) & 3) * 2)) + ((((v1993 + ((~(((v1995 ^ -1) | (-(v1995 ^ -1))) >> 31)) & 2)) - (v1996 + ((~(((v1997 ^ -1) | (-(v1997 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
        int v2004 = v2002[v2163];
        int * v2005 = v1950->mem;
        int v2165 = v2001 * 2;
        v2005[v2165] = v2003;
        int * v2007 = v1950->mem;
        int v2168 = (v2001 * 2) + 1;
        v2007[v2168] = v2004;
        ;
      } else {
        ;
      }
      int * v2012 = v1950->mem;
      int v2173 = ((int)((unsigned int)((int)((unsigned int)(v1956 + 68) >> 2)) >> 1)) * 2;
      int v2013 = v2012[v2173];
      int v2174 = (((int)((unsigned int)((int)((unsigned int)(v1956 + 68) >> 2)) >> 1)) * 2) + 1;
      int v2014 = v2012[v2174];
      int * v2015 = v1950->cache_vals;
      int v2176 = ((4 + ((((int)((unsigned int)((int)((unsigned int)(v1956 + 68) >> 2)) >> 1)) & 3) * 2)) + ((((v1993 + ((~(((v1995 ^ -1) | (-(v1995 ^ -1))) >> 31)) & 2)) - (v1996 + ((~(((v1997 ^ -1) | (-(v1997 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
      v2015[v2176] = v2013;
      int * v2017 = v1950->cache_vals;
      int v2179 = (((4 + ((((int)((unsigned int)((int)((unsigned int)(v1956 + 68) >> 2)) >> 1)) & 3) * 2)) + ((((v1993 + ((~(((v1995 ^ -1) | (-(v1995 ^ -1))) >> 31)) & 2)) - (v1996 + ((~(((v1997 ^ -1) | (-(v1997 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
      v2017[v2179] = v2014;
      int * v2019 = v1950->cache_tags;
      int v2182 = (int)((unsigned int)((int)((unsigned int)(v1956 + 68) >> 2)) >> 1);
      v2019[v2158] = v2182;
      int * v2021 = v1950->cache_dirty;
      v2021[v2158] = 0;
      int * v2023 = v1950->cache_age;
      v2023[v2158] = 1;
      int * v2025 = v1950->cache_age;
      int v2026 = v2025[v2158];
      int v2027 = v2025[v2132];
      int v2188 = v2027 + ((int)((unsigned int)(v2027 - v2026) >> 31));
      v2025[v2132] = v2188;
      int * v2029 = v1950->cache_age;
      int v2030 = v2029[v2133];
      int v2190 = v2030 + ((int)((unsigned int)(v2030 - v2026) >> 31));
      v2029[v2133] = v2190;
      int * v2032 = v1950->cache_age;
      v2032[v2158] = 0;
      v2035 = v2158;
    }
    int * v2036 = v1950->cache_vals;
    int v2193 = v2035 * 2;
    int v2037 = v2036[v2193];
    int v2194 = (v2035 * 2) + 1;
    int v2038 = v2036[v2194];
    int v2195 = (((((int)((unsigned int)((int)((unsigned int)(v1956 + 68) >> 2)) >> 1)) & 1) * 2) + ((((v1977 + ((~(((v1979 ^ -1) | (-(v1979 ^ -1))) >> 31)) & 2)) - (v1980 + ((~(((v1981 ^ -1) | (-(v1981 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
    v2036[v2195] = v2037;
    int * v2040 = v1950->cache_vals;
    int v2198 = ((((((int)((unsigned int)((int)((unsigned int)(v1956 + 68) >> 2)) >> 1)) & 1) * 2) + ((((v1977 + ((~(((v1979 ^ -1) | (-(v1979 ^ -1))) >> 31)) & 2)) - (v1980 + ((~(((v1981 ^ -1) | (-(v1981 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
    v2040[v2198] = v2038;
    int * v2042 = v1950->cache_tags;
    int v2201 = ((((int)((unsigned int)((int)((unsigned int)(v1956 + 68) >> 2)) >> 1)) & 1) * 2) + ((((v1977 + ((~(((v1979 ^ -1) | (-(v1979 ^ -1))) >> 31)) & 2)) - (v1980 + ((~(((v1981 ^ -1) | (-(v1981 ^ -1))) >> 31)) & 2))) >> 31) & 1);
    int v2202 = (int)((unsigned int)((int)((unsigned int)(v1956 + 68) >> 2)) >> 1);
    v2042[v2201] = v2202;
    int * v2044 = v1950->cache_dirty;
    v2044[v2201] = 0;
    int * v2046 = v1950->cache_age;
    v2046[v2201] = 1;
    int * v2048 = v1950->cache_age;
    int v2049 = v2048[v2201];
    int v2050 = v2048[v2130];
    int v2208 = v2050 + ((int)((unsigned int)(v2050 - v2049) >> 31));
    v2048[v2130] = v2208;
    int * v2052 = v1950->cache_age;
    int v2053 = v2052[v2131];
    int v2210 = v2053 + ((int)((unsigned int)(v2053 - v2049) >> 31));
    v2052[v2131] = v2210;
    int * v2055 = v1950->cache_age;
    v2055[v2201] = 0;
    v2058 = v2201;
  }
  int * v2059 = v1950->cache_vals;
  int v2213 = (v2058 * 2) + (((int)((unsigned int)(v1956 + 68) >> 2)) & 1);
  v2059[v2213] = v1958;
  int * v2061 = v1950->cache_tags;
  int v2062 = v2061[v2132];
  int v2063 = v2061[v2133];
  bool v2216 = !(((~(((v2062 ^ ((int)((unsigned int)((int)((unsigned int)(v1956 + 68) >> 2)) >> 1))) | (-(v2062 ^ ((int)((unsigned int)((int)((unsigned int)(v1956 + 68) >> 2)) >> 1))))) >> 31)) | (~(((v2063 ^ ((int)((unsigned int)((int)((unsigned int)(v1956 + 68) >> 2)) >> 1))) | (-(v2063 ^ ((int)((unsigned int)((int)((unsigned int)(v1956 + 68) >> 2)) >> 1))))) >> 31))) == 0);
  int v2117;
  if (v2216) {
    int * v2064 = v1950->cache_age;
    int v2218 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v1956 + 68) >> 2)) >> 1)) & 3) * 2)) + ((~(((v2063 ^ ((int)((unsigned int)((int)((unsigned int)(v1956 + 68) >> 2)) >> 1))) | (-(v2063 ^ ((int)((unsigned int)((int)((unsigned int)(v1956 + 68) >> 2)) >> 1))))) >> 31)) & 1);
    int v2065 = v2064[v2218];
    int v2066 = v2064[v2132];
    int v2219 = v2066 + ((int)((unsigned int)(v2066 - v2065) >> 31));
    v2064[v2132] = v2219;
    int * v2068 = v1950->cache_age;
    int v2069 = v2068[v2133];
    int v2221 = v2069 + ((int)((unsigned int)(v2069 - v2065) >> 31));
    v2068[v2133] = v2221;
    int * v2071 = v1950->cache_age;
    v2071[v2218] = 0;
    v2117 = v2218;
  } else {
    int * v2074 = v1950->cache_age;
    int v2225 = 4 + ((((int)((unsigned int)((int)((unsigned int)(v1956 + 68) >> 2)) >> 1)) & 3) * 2);
    int v2075 = v2074[v2225];
    int * v2076 = v1950->cache_tags;
    int v2077 = v2076[v2225];
    int v2078 = v2074[v2133];
    int v2079 = v2076[v2133];
    int * v2080 = v1950->cache_dirty;
    int v2228 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v1956 + 68) >> 2)) >> 1)) & 3) * 2)) + ((((v2075 + ((~(((v2077 ^ -1) | (-(v2077 ^ -1))) >> 31)) & 2)) - (v2078 + ((~(((v2079 ^ -1) | (-(v2079 ^ -1))) >> 31)) & 2))) >> 31) & 1);
    int v2081 = v2080[v2228];
    bool v2229 = !(v2081 == 0);
    if (v2229) {
      int * v2082 = v1950->cache_tags;
      int v2083 = v2082[v2228];
      int * v2084 = v1950->cache_vals;
      int v2232 = ((4 + ((((int)((unsigned int)((int)((unsigned int)(v1956 + 68) >> 2)) >> 1)) & 3) * 2)) + ((((v2075 + ((~(((v2077 ^ -1) | (-(v2077 ^ -1))) >> 31)) & 2)) - (v2078 + ((~(((v2079 ^ -1) | (-(v2079 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
      int v2085 = v2084[v2232];
      int v2233 = (((4 + ((((int)((unsigned int)((int)((unsigned int)(v1956 + 68) >> 2)) >> 1)) & 3) * 2)) + ((((v2075 + ((~(((v2077 ^ -1) | (-(v2077 ^ -1))) >> 31)) & 2)) - (v2078 + ((~(((v2079 ^ -1) | (-(v2079 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
      int v2086 = v2084[v2233];
      int * v2087 = v1950->mem;
      int v2235 = v2083 * 2;
      v2087[v2235] = v2085;
      int * v2089 = v1950->mem;
      int v2238 = (v2083 * 2) + 1;
      v2089[v2238] = v2086;
      ;
    } else {
      ;
    }
    int * v2094 = v1950->mem;
    int v2243 = ((int)((unsigned int)((int)((unsigned int)(v1956 + 68) >> 2)) >> 1)) * 2;
    int v2095 = v2094[v2243];
    int v2244 = (((int)((unsigned int)((int)((unsigned int)(v1956 + 68) >> 2)) >> 1)) * 2) + 1;
    int v2096 = v2094[v2244];
    int * v2097 = v1950->cache_vals;
    int v2246 = ((4 + ((((int)((unsigned int)((int)((unsigned int)(v1956 + 68) >> 2)) >> 1)) & 3) * 2)) + ((((v2075 + ((~(((v2077 ^ -1) | (-(v2077 ^ -1))) >> 31)) & 2)) - (v2078 + ((~(((v2079 ^ -1) | (-(v2079 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
    v2097[v2246] = v2095;
    int * v2099 = v1950->cache_vals;
    int v2249 = (((4 + ((((int)((unsigned int)((int)((unsigned int)(v1956 + 68) >> 2)) >> 1)) & 3) * 2)) + ((((v2075 + ((~(((v2077 ^ -1) | (-(v2077 ^ -1))) >> 31)) & 2)) - (v2078 + ((~(((v2079 ^ -1) | (-(v2079 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
    v2099[v2249] = v2096;
    int * v2101 = v1950->cache_tags;
    int v2252 = (int)((unsigned int)((int)((unsigned int)(v1956 + 68) >> 2)) >> 1);
    v2101[v2228] = v2252;
    int * v2103 = v1950->cache_dirty;
    v2103[v2228] = 0;
    int * v2105 = v1950->cache_age;
    v2105[v2228] = 1;
    int * v2107 = v1950->cache_age;
    int v2108 = v2107[v2228];
    int v2109 = v2107[v2132];
    int v2258 = v2109 + ((int)((unsigned int)(v2109 - v2108) >> 31));
    v2107[v2132] = v2258;
    int * v2111 = v1950->cache_age;
    int v2112 = v2111[v2133];
    int v2260 = v2112 + ((int)((unsigned int)(v2112 - v2108) >> 31));
    v2111[v2133] = v2260;
    int * v2114 = v1950->cache_age;
    v2114[v2228] = 0;
    v2117 = v2228;
  }
  int * v2118 = v1950->cache_vals;
  int v2263 = (v2117 * 2) + (((int)((unsigned int)(v1956 + 68) >> 2)) & 1);
  v2118[v2263] = v1958;
  int * v2120 = v1950->cache_dirty;
  v2120[v2117] = 1;
  struct StateT * v2122 = slot_25(v1950);
  return v2122;
}

struct StateT * slot_0(struct StateT * v2) {
  int v3 = v2->timer;
  int v11 = v3 + 1;
  v2->timer = v11;
  int * v5 = v2->reg_ready;
  v5[11] = v11;
  int * v7 = v2->regs;
  v7[11] = 0;
  struct StateT * v9 = slot_1(v2);
  return v9;
}

struct StateT * slot_14(struct StateT * v662) {
  int v663 = v662->timer;
  int v775 = v663 + 1;
  v662->timer = v775;
  int * v665 = v662->reg_ready;
  int v666 = v665[10];
  int * v667 = v662->regs;
  int v668 = v667[10];
  int * v669 = v662->cache_tags;
  int v780 = (((int)((unsigned int)((int)((unsigned int)v668 >> 2)) >> 1)) & 1) * 2;
  int v670 = v669[v780];
  int v781 = ((((int)((unsigned int)((int)((unsigned int)v668 >> 2)) >> 1)) & 1) * 2) + 1;
  int v671 = v669[v781];
  int v782 = 4 + ((((int)((unsigned int)((int)((unsigned int)v668 >> 2)) >> 1)) & 3) * 2);
  int v672 = v669[v782];
  int v783 = (4 + ((((int)((unsigned int)((int)((unsigned int)v668 >> 2)) >> 1)) & 3) * 2)) + 1;
  int v673 = v669[v783];
  int * v674 = v662->cache_vals;
  bool v784 = !(((~(((v670 ^ ((int)((unsigned int)((int)((unsigned int)v668 >> 2)) >> 1))) | (-(v670 ^ ((int)((unsigned int)((int)((unsigned int)v668 >> 2)) >> 1))))) >> 31)) | (~(((v671 ^ ((int)((unsigned int)((int)((unsigned int)v668 >> 2)) >> 1))) | (-(v671 ^ ((int)((unsigned int)((int)((unsigned int)v668 >> 2)) >> 1))))) >> 31))) == 0);
  int v767;
  if (v784) {
    int * v675 = v662->cache_age;
    int v786 = ((((int)((unsigned int)((int)((unsigned int)v668 >> 2)) >> 1)) & 1) * 2) + ((~(((v671 ^ ((int)((unsigned int)((int)((unsigned int)v668 >> 2)) >> 1))) | (-(v671 ^ ((int)((unsigned int)((int)((unsigned int)v668 >> 2)) >> 1))))) >> 31)) & 1);
    int v676 = v675[v786];
    int v677 = v675[v780];
    int v787 = v677 + ((int)((unsigned int)(v677 - v676) >> 31));
    v675[v780] = v787;
    int * v679 = v662->cache_age;
    int v680 = v679[v781];
    int v789 = v680 + ((int)((unsigned int)(v680 - v676) >> 31));
    v679[v781] = v789;
    int * v682 = v662->cache_age;
    v682[v786] = 0;
    v767 = v786;
  } else {
    int * v685 = v662->cache_age;
    int v793 = (((int)((unsigned int)((int)((unsigned int)v668 >> 2)) >> 1)) & 1) * 2;
    int v686 = v685[v793];
    int * v687 = v662->cache_tags;
    int v688 = v687[v793];
    int v689 = v685[v781];
    int v690 = v687[v781];
    bool v795 = !(((~(((v672 ^ ((int)((unsigned int)((int)((unsigned int)v668 >> 2)) >> 1))) | (-(v672 ^ ((int)((unsigned int)((int)((unsigned int)v668 >> 2)) >> 1))))) >> 31)) | (~(((v673 ^ ((int)((unsigned int)((int)((unsigned int)v668 >> 2)) >> 1))) | (-(v673 ^ ((int)((unsigned int)((int)((unsigned int)v668 >> 2)) >> 1))))) >> 31))) == 0);
    int v744;
    if (v795) {
      int * v691 = v662->cache_age;
      int v797 = (4 + ((((int)((unsigned int)((int)((unsigned int)v668 >> 2)) >> 1)) & 3) * 2)) + ((~(((v673 ^ ((int)((unsigned int)((int)((unsigned int)v668 >> 2)) >> 1))) | (-(v673 ^ ((int)((unsigned int)((int)((unsigned int)v668 >> 2)) >> 1))))) >> 31)) & 1);
      int v692 = v691[v797];
      int v693 = v691[v782];
      int v798 = v693 + ((int)((unsigned int)(v693 - v692) >> 31));
      v691[v782] = v798;
      int * v695 = v662->cache_age;
      int v696 = v695[v783];
      int v800 = v696 + ((int)((unsigned int)(v696 - v692) >> 31));
      v695[v783] = v800;
      int * v698 = v662->cache_age;
      v698[v797] = 0;
      v744 = v797;
    } else {
      int * v701 = v662->cache_age;
      int v804 = 4 + ((((int)((unsigned int)((int)((unsigned int)v668 >> 2)) >> 1)) & 3) * 2);
      int v702 = v701[v804];
      int * v703 = v662->cache_tags;
      int v704 = v703[v804];
      int v705 = v701[v783];
      int v706 = v703[v783];
      int * v707 = v662->cache_dirty;
      int v807 = (4 + ((((int)((unsigned int)((int)((unsigned int)v668 >> 2)) >> 1)) & 3) * 2)) + ((((v702 + ((~(((v704 ^ -1) | (-(v704 ^ -1))) >> 31)) & 2)) - (v705 + ((~(((v706 ^ -1) | (-(v706 ^ -1))) >> 31)) & 2))) >> 31) & 1);
      int v708 = v707[v807];
      bool v808 = !(v708 == 0);
      if (v808) {
        int * v709 = v662->cache_tags;
        int v710 = v709[v807];
        int * v711 = v662->cache_vals;
        int v811 = ((4 + ((((int)((unsigned int)((int)((unsigned int)v668 >> 2)) >> 1)) & 3) * 2)) + ((((v702 + ((~(((v704 ^ -1) | (-(v704 ^ -1))) >> 31)) & 2)) - (v705 + ((~(((v706 ^ -1) | (-(v706 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
        int v712 = v711[v811];
        int v812 = (((4 + ((((int)((unsigned int)((int)((unsigned int)v668 >> 2)) >> 1)) & 3) * 2)) + ((((v702 + ((~(((v704 ^ -1) | (-(v704 ^ -1))) >> 31)) & 2)) - (v705 + ((~(((v706 ^ -1) | (-(v706 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
        int v713 = v711[v812];
        int * v714 = v662->mem;
        int v814 = v710 * 2;
        v714[v814] = v712;
        int * v716 = v662->mem;
        int v817 = (v710 * 2) + 1;
        v716[v817] = v713;
        ;
      } else {
        ;
      }
      int * v721 = v662->mem;
      int v822 = ((int)((unsigned int)((int)((unsigned int)v668 >> 2)) >> 1)) * 2;
      int v722 = v721[v822];
      int v823 = (((int)((unsigned int)((int)((unsigned int)v668 >> 2)) >> 1)) * 2) + 1;
      int v723 = v721[v823];
      int * v724 = v662->cache_vals;
      int v825 = ((4 + ((((int)((unsigned int)((int)((unsigned int)v668 >> 2)) >> 1)) & 3) * 2)) + ((((v702 + ((~(((v704 ^ -1) | (-(v704 ^ -1))) >> 31)) & 2)) - (v705 + ((~(((v706 ^ -1) | (-(v706 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
      v724[v825] = v722;
      int * v726 = v662->cache_vals;
      int v828 = (((4 + ((((int)((unsigned int)((int)((unsigned int)v668 >> 2)) >> 1)) & 3) * 2)) + ((((v702 + ((~(((v704 ^ -1) | (-(v704 ^ -1))) >> 31)) & 2)) - (v705 + ((~(((v706 ^ -1) | (-(v706 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
      v726[v828] = v723;
      int * v728 = v662->cache_tags;
      int v831 = (int)((unsigned int)((int)((unsigned int)v668 >> 2)) >> 1);
      v728[v807] = v831;
      int * v730 = v662->cache_dirty;
      v730[v807] = 0;
      int * v732 = v662->cache_age;
      v732[v807] = 1;
      int * v734 = v662->cache_age;
      int v735 = v734[v807];
      int v736 = v734[v782];
      int v837 = v736 + ((int)((unsigned int)(v736 - v735) >> 31));
      v734[v782] = v837;
      int * v738 = v662->cache_age;
      int v739 = v738[v783];
      int v839 = v739 + ((int)((unsigned int)(v739 - v735) >> 31));
      v738[v783] = v839;
      int * v741 = v662->cache_age;
      v741[v807] = 0;
      v744 = v807;
    }
    int * v745 = v662->cache_vals;
    int v842 = v744 * 2;
    int v746 = v745[v842];
    int v843 = (v744 * 2) + 1;
    int v747 = v745[v843];
    int v844 = (((((int)((unsigned int)((int)((unsigned int)v668 >> 2)) >> 1)) & 1) * 2) + ((((v686 + ((~(((v688 ^ -1) | (-(v688 ^ -1))) >> 31)) & 2)) - (v689 + ((~(((v690 ^ -1) | (-(v690 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
    v745[v844] = v746;
    int * v749 = v662->cache_vals;
    int v847 = ((((((int)((unsigned int)((int)((unsigned int)v668 >> 2)) >> 1)) & 1) * 2) + ((((v686 + ((~(((v688 ^ -1) | (-(v688 ^ -1))) >> 31)) & 2)) - (v689 + ((~(((v690 ^ -1) | (-(v690 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
    v749[v847] = v747;
    int * v751 = v662->cache_tags;
    int v850 = ((((int)((unsigned int)((int)((unsigned int)v668 >> 2)) >> 1)) & 1) * 2) + ((((v686 + ((~(((v688 ^ -1) | (-(v688 ^ -1))) >> 31)) & 2)) - (v689 + ((~(((v690 ^ -1) | (-(v690 ^ -1))) >> 31)) & 2))) >> 31) & 1);
    int v851 = (int)((unsigned int)((int)((unsigned int)v668 >> 2)) >> 1);
    v751[v850] = v851;
    int * v753 = v662->cache_dirty;
    v753[v850] = 0;
    int * v755 = v662->cache_age;
    v755[v850] = 1;
    int * v757 = v662->cache_age;
    int v758 = v757[v850];
    int v759 = v757[v780];
    int v857 = v759 + ((int)((unsigned int)(v759 - v758) >> 31));
    v757[v780] = v857;
    int * v761 = v662->cache_age;
    int v762 = v761[v781];
    int v859 = v762 + ((int)((unsigned int)(v762 - v758) >> 31));
    v761[v781] = v859;
    int * v764 = v662->cache_age;
    v764[v850] = 0;
    v767 = v850;
  }
  int v862 = (v767 * 2) + (((int)((unsigned int)v668 >> 2)) & 1);
  int v768 = v674[v862];
  int * v769 = v662->reg_ready;
  int v864 = ((v666 + ((v663 - v666) & (~((v663 - v666) >> 31)))) + 1) + ((100 ^ (((~(((v672 ^ ((int)((unsigned int)((int)((unsigned int)v668 >> 2)) >> 1))) | (-(v672 ^ ((int)((unsigned int)((int)((unsigned int)v668 >> 2)) >> 1))))) >> 31)) | (~(((v673 ^ ((int)((unsigned int)((int)((unsigned int)v668 >> 2)) >> 1))) | (-(v673 ^ ((int)((unsigned int)((int)((unsigned int)v668 >> 2)) >> 1))))) >> 31))) & 104)) ^ (((~(((v670 ^ ((int)((unsigned int)((int)((unsigned int)v668 >> 2)) >> 1))) | (-(v670 ^ ((int)((unsigned int)((int)((unsigned int)v668 >> 2)) >> 1))))) >> 31)) | (~(((v671 ^ ((int)((unsigned int)((int)((unsigned int)v668 >> 2)) >> 1))) | (-(v671 ^ ((int)((unsigned int)((int)((unsigned int)v668 >> 2)) >> 1))))) >> 31))) & (1 ^ (100 ^ (((~(((v672 ^ ((int)((unsigned int)((int)((unsigned int)v668 >> 2)) >> 1))) | (-(v672 ^ ((int)((unsigned int)((int)((unsigned int)v668 >> 2)) >> 1))))) >> 31)) | (~(((v673 ^ ((int)((unsigned int)((int)((unsigned int)v668 >> 2)) >> 1))) | (-(v673 ^ ((int)((unsigned int)((int)((unsigned int)v668 >> 2)) >> 1))))) >> 31))) & 104)))));
  v769[10] = v864;
  int * v771 = v662->regs;
  v771[10] = v768;
  struct StateT * v773 = slot_15(v662);
  return v773;
}

struct StateT * slot_17(struct StateT * v1101) {
  int * v1102 = v1101->saved_regs;
  int v1103 = v1102[10];
  int v1104 = v1102[11];
  bool v1137 = (v1103 ^ -2147483648) >= (v1104 ^ -2147483648);
  struct StateT * v1132;
  if (v1137) {
    int v1105 = v1101->timer;
    int v1138 = v1105 + 15;
    v1101->timer = v1138;
    int * v1107 = v1101->saved_regs;
    int v1108 = v1107[10];
    int * v1109 = v1101->regs;
    v1109[10] = v1108;
    int * v1111 = v1101->saved_regs;
    int v1112 = v1111[11];
    int * v1113 = v1101->regs;
    v1113[11] = v1112;
    int * v1115 = v1101->saved_regs;
    int v1116 = v1115[12];
    int * v1117 = v1101->regs;
    v1117[12] = v1116;
    int * v1119 = v1101->reg_ready;
    int v1120 = v1101->timer;
    v1119[10] = v1120;
    int * v1122 = v1101->reg_ready;
    int v1123 = v1101->timer;
    v1122[11] = v1123;
    int * v1125 = v1101->reg_ready;
    int v1126 = v1101->timer;
    v1125[12] = v1126;
    struct StateT * v1128 = slot_18(v1101);
    v1132 = v1128;
  } else {
    struct StateT * v1130 = slot_19(v1101);
    v1132 = v1130;
  }
  return v1132;
}

struct StateT * slot_20(struct StateT * v1495) {
  int v1496 = v1495->timer;
  int v1504 = v1496 + 1;
  v1495->timer = v1504;
  int * v1498 = v1495->reg_ready;
  v1498[11] = v1504;
  int * v1500 = v1495->regs;
  v1500[11] = 0;
  struct StateT * v1502 = slot_21(v1495);
  return v1502;
}

struct StateT * snippet(struct StateT * v0) {
  struct StateT * v1 = slot_0(v0);
  int v2274 = v1->timer;
  int * v2275 = v1->reg_ready;
  int v2276 = v2275[0];
  int v2407 = v2276 + ((v2274 - v2276) & (~((v2274 - v2276) >> 31)));
  v1->timer = v2407;
  int v2278 = v1->timer;
  int * v2279 = v1->reg_ready;
  int v2280 = v2279[1];
  int v2410 = v2280 + ((v2278 - v2280) & (~((v2278 - v2280) >> 31)));
  v1->timer = v2410;
  int v2282 = v1->timer;
  int * v2283 = v1->reg_ready;
  int v2284 = v2283[2];
  int v2413 = v2284 + ((v2282 - v2284) & (~((v2282 - v2284) >> 31)));
  v1->timer = v2413;
  int v2286 = v1->timer;
  int * v2287 = v1->reg_ready;
  int v2288 = v2287[3];
  int v2416 = v2288 + ((v2286 - v2288) & (~((v2286 - v2288) >> 31)));
  v1->timer = v2416;
  int v2290 = v1->timer;
  int * v2291 = v1->reg_ready;
  int v2292 = v2291[4];
  int v2419 = v2292 + ((v2290 - v2292) & (~((v2290 - v2292) >> 31)));
  v1->timer = v2419;
  int v2294 = v1->timer;
  int * v2295 = v1->reg_ready;
  int v2296 = v2295[5];
  int v2422 = v2296 + ((v2294 - v2296) & (~((v2294 - v2296) >> 31)));
  v1->timer = v2422;
  int v2298 = v1->timer;
  int * v2299 = v1->reg_ready;
  int v2300 = v2299[6];
  int v2425 = v2300 + ((v2298 - v2300) & (~((v2298 - v2300) >> 31)));
  v1->timer = v2425;
  int v2302 = v1->timer;
  int * v2303 = v1->reg_ready;
  int v2304 = v2303[7];
  int v2428 = v2304 + ((v2302 - v2304) & (~((v2302 - v2304) >> 31)));
  v1->timer = v2428;
  int v2306 = v1->timer;
  int * v2307 = v1->reg_ready;
  int v2308 = v2307[8];
  int v2431 = v2308 + ((v2306 - v2308) & (~((v2306 - v2308) >> 31)));
  v1->timer = v2431;
  int v2310 = v1->timer;
  int * v2311 = v1->reg_ready;
  int v2312 = v2311[9];
  int v2434 = v2312 + ((v2310 - v2312) & (~((v2310 - v2312) >> 31)));
  v1->timer = v2434;
  int v2314 = v1->timer;
  int * v2315 = v1->reg_ready;
  int v2316 = v2315[10];
  int v2437 = v2316 + ((v2314 - v2316) & (~((v2314 - v2316) >> 31)));
  v1->timer = v2437;
  int v2318 = v1->timer;
  int * v2319 = v1->reg_ready;
  int v2320 = v2319[11];
  int v2440 = v2320 + ((v2318 - v2320) & (~((v2318 - v2320) >> 31)));
  v1->timer = v2440;
  int v2322 = v1->timer;
  int * v2323 = v1->reg_ready;
  int v2324 = v2323[12];
  int v2443 = v2324 + ((v2322 - v2324) & (~((v2322 - v2324) >> 31)));
  v1->timer = v2443;
  int v2326 = v1->timer;
  int * v2327 = v1->reg_ready;
  int v2328 = v2327[13];
  int v2446 = v2328 + ((v2326 - v2328) & (~((v2326 - v2328) >> 31)));
  v1->timer = v2446;
  int v2330 = v1->timer;
  int * v2331 = v1->reg_ready;
  int v2332 = v2331[14];
  int v2449 = v2332 + ((v2330 - v2332) & (~((v2330 - v2332) >> 31)));
  v1->timer = v2449;
  int v2334 = v1->timer;
  int * v2335 = v1->reg_ready;
  int v2336 = v2335[15];
  int v2452 = v2336 + ((v2334 - v2336) & (~((v2334 - v2336) >> 31)));
  v1->timer = v2452;
  int v2338 = v1->timer;
  int * v2339 = v1->reg_ready;
  int v2340 = v2339[16];
  int v2455 = v2340 + ((v2338 - v2340) & (~((v2338 - v2340) >> 31)));
  v1->timer = v2455;
  int v2342 = v1->timer;
  int * v2343 = v1->reg_ready;
  int v2344 = v2343[17];
  int v2458 = v2344 + ((v2342 - v2344) & (~((v2342 - v2344) >> 31)));
  v1->timer = v2458;
  int v2346 = v1->timer;
  int * v2347 = v1->reg_ready;
  int v2348 = v2347[18];
  int v2461 = v2348 + ((v2346 - v2348) & (~((v2346 - v2348) >> 31)));
  v1->timer = v2461;
  int v2350 = v1->timer;
  int * v2351 = v1->reg_ready;
  int v2352 = v2351[19];
  int v2464 = v2352 + ((v2350 - v2352) & (~((v2350 - v2352) >> 31)));
  v1->timer = v2464;
  int v2354 = v1->timer;
  int * v2355 = v1->reg_ready;
  int v2356 = v2355[20];
  int v2467 = v2356 + ((v2354 - v2356) & (~((v2354 - v2356) >> 31)));
  v1->timer = v2467;
  int v2358 = v1->timer;
  int * v2359 = v1->reg_ready;
  int v2360 = v2359[21];
  int v2470 = v2360 + ((v2358 - v2360) & (~((v2358 - v2360) >> 31)));
  v1->timer = v2470;
  int v2362 = v1->timer;
  int * v2363 = v1->reg_ready;
  int v2364 = v2363[22];
  int v2473 = v2364 + ((v2362 - v2364) & (~((v2362 - v2364) >> 31)));
  v1->timer = v2473;
  int v2366 = v1->timer;
  int * v2367 = v1->reg_ready;
  int v2368 = v2367[23];
  int v2476 = v2368 + ((v2366 - v2368) & (~((v2366 - v2368) >> 31)));
  v1->timer = v2476;
  int v2370 = v1->timer;
  int * v2371 = v1->reg_ready;
  int v2372 = v2371[24];
  int v2479 = v2372 + ((v2370 - v2372) & (~((v2370 - v2372) >> 31)));
  v1->timer = v2479;
  int v2374 = v1->timer;
  int * v2375 = v1->reg_ready;
  int v2376 = v2375[25];
  int v2482 = v2376 + ((v2374 - v2376) & (~((v2374 - v2376) >> 31)));
  v1->timer = v2482;
  int v2378 = v1->timer;
  int * v2379 = v1->reg_ready;
  int v2380 = v2379[26];
  int v2485 = v2380 + ((v2378 - v2380) & (~((v2378 - v2380) >> 31)));
  v1->timer = v2485;
  int v2382 = v1->timer;
  int * v2383 = v1->reg_ready;
  int v2384 = v2383[27];
  int v2488 = v2384 + ((v2382 - v2384) & (~((v2382 - v2384) >> 31)));
  v1->timer = v2488;
  int v2386 = v1->timer;
  int * v2387 = v1->reg_ready;
  int v2388 = v2387[28];
  int v2491 = v2388 + ((v2386 - v2388) & (~((v2386 - v2388) >> 31)));
  v1->timer = v2491;
  int v2390 = v1->timer;
  int * v2391 = v1->reg_ready;
  int v2392 = v2391[29];
  int v2494 = v2392 + ((v2390 - v2392) & (~((v2390 - v2392) >> 31)));
  v1->timer = v2494;
  int v2394 = v1->timer;
  int * v2395 = v1->reg_ready;
  int v2396 = v2395[30];
  int v2497 = v2396 + ((v2394 - v2396) & (~((v2394 - v2396) >> 31)));
  v1->timer = v2497;
  int v2398 = v1->timer;
  int * v2399 = v1->reg_ready;
  int v2400 = v2399[31];
  int v2500 = v2400 + ((v2398 - v2400) & (~((v2398 - v2400) >> 31)));
  v1->timer = v2500;
  return v1;
}

struct StateT * slot_8(struct StateT * v536) {
  int v537 = v536->timer;
  int v545 = v537 + 1;
  v536->timer = v545;
  int * v539 = v536->reg_ready;
  v539[11] = v545;
  int * v541 = v536->regs;
  v541[11] = 0;
  struct StateT * v543 = slot_9(v536);
  return v543;
}

struct StateT * slot_4(struct StateT * v261) {
  int * v262 = v261->saved_regs;
  int * v263 = v261->regs;
  int v264 = v263[11];
  v262[11] = v264;
  int v266 = v261->timer;
  int v278 = v266 + 1;
  v261->timer = v278;
  int * v268 = v261->reg_ready;
  v268[11] = v278;
  int * v270 = v261->regs;
  v270[11] = 0;
  struct StateT * v272 = slot_5(v261);
  return v272;
}

struct StateT * slot_15(struct StateT * v869) {
  int v870 = v869->timer;
  int v982 = v870 + 1;
  v869->timer = v982;
  int * v872 = v869->reg_ready;
  int v873 = v872[12];
  int * v874 = v869->regs;
  int v875 = v874[12];
  int * v876 = v869->cache_tags;
  int v987 = (((int)((unsigned int)((int)((unsigned int)(v875 + 68) >> 2)) >> 1)) & 1) * 2;
  int v877 = v876[v987];
  int v988 = ((((int)((unsigned int)((int)((unsigned int)(v875 + 68) >> 2)) >> 1)) & 1) * 2) + 1;
  int v878 = v876[v988];
  int v989 = 4 + ((((int)((unsigned int)((int)((unsigned int)(v875 + 68) >> 2)) >> 1)) & 3) * 2);
  int v879 = v876[v989];
  int v990 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v875 + 68) >> 2)) >> 1)) & 3) * 2)) + 1;
  int v880 = v876[v990];
  int * v881 = v869->cache_vals;
  bool v991 = !(((~(((v877 ^ ((int)((unsigned int)((int)((unsigned int)(v875 + 68) >> 2)) >> 1))) | (-(v877 ^ ((int)((unsigned int)((int)((unsigned int)(v875 + 68) >> 2)) >> 1))))) >> 31)) | (~(((v878 ^ ((int)((unsigned int)((int)((unsigned int)(v875 + 68) >> 2)) >> 1))) | (-(v878 ^ ((int)((unsigned int)((int)((unsigned int)(v875 + 68) >> 2)) >> 1))))) >> 31))) == 0);
  int v974;
  if (v991) {
    int * v882 = v869->cache_age;
    int v993 = ((((int)((unsigned int)((int)((unsigned int)(v875 + 68) >> 2)) >> 1)) & 1) * 2) + ((~(((v878 ^ ((int)((unsigned int)((int)((unsigned int)(v875 + 68) >> 2)) >> 1))) | (-(v878 ^ ((int)((unsigned int)((int)((unsigned int)(v875 + 68) >> 2)) >> 1))))) >> 31)) & 1);
    int v883 = v882[v993];
    int v884 = v882[v987];
    int v994 = v884 + ((int)((unsigned int)(v884 - v883) >> 31));
    v882[v987] = v994;
    int * v886 = v869->cache_age;
    int v887 = v886[v988];
    int v996 = v887 + ((int)((unsigned int)(v887 - v883) >> 31));
    v886[v988] = v996;
    int * v889 = v869->cache_age;
    v889[v993] = 0;
    v974 = v993;
  } else {
    int * v892 = v869->cache_age;
    int v1000 = (((int)((unsigned int)((int)((unsigned int)(v875 + 68) >> 2)) >> 1)) & 1) * 2;
    int v893 = v892[v1000];
    int * v894 = v869->cache_tags;
    int v895 = v894[v1000];
    int v896 = v892[v988];
    int v897 = v894[v988];
    bool v1002 = !(((~(((v879 ^ ((int)((unsigned int)((int)((unsigned int)(v875 + 68) >> 2)) >> 1))) | (-(v879 ^ ((int)((unsigned int)((int)((unsigned int)(v875 + 68) >> 2)) >> 1))))) >> 31)) | (~(((v880 ^ ((int)((unsigned int)((int)((unsigned int)(v875 + 68) >> 2)) >> 1))) | (-(v880 ^ ((int)((unsigned int)((int)((unsigned int)(v875 + 68) >> 2)) >> 1))))) >> 31))) == 0);
    int v951;
    if (v1002) {
      int * v898 = v869->cache_age;
      int v1004 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v875 + 68) >> 2)) >> 1)) & 3) * 2)) + ((~(((v880 ^ ((int)((unsigned int)((int)((unsigned int)(v875 + 68) >> 2)) >> 1))) | (-(v880 ^ ((int)((unsigned int)((int)((unsigned int)(v875 + 68) >> 2)) >> 1))))) >> 31)) & 1);
      int v899 = v898[v1004];
      int v900 = v898[v989];
      int v1005 = v900 + ((int)((unsigned int)(v900 - v899) >> 31));
      v898[v989] = v1005;
      int * v902 = v869->cache_age;
      int v903 = v902[v990];
      int v1007 = v903 + ((int)((unsigned int)(v903 - v899) >> 31));
      v902[v990] = v1007;
      int * v905 = v869->cache_age;
      v905[v1004] = 0;
      v951 = v1004;
    } else {
      int * v908 = v869->cache_age;
      int v1011 = 4 + ((((int)((unsigned int)((int)((unsigned int)(v875 + 68) >> 2)) >> 1)) & 3) * 2);
      int v909 = v908[v1011];
      int * v910 = v869->cache_tags;
      int v911 = v910[v1011];
      int v912 = v908[v990];
      int v913 = v910[v990];
      int * v914 = v869->cache_dirty;
      int v1014 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v875 + 68) >> 2)) >> 1)) & 3) * 2)) + ((((v909 + ((~(((v911 ^ -1) | (-(v911 ^ -1))) >> 31)) & 2)) - (v912 + ((~(((v913 ^ -1) | (-(v913 ^ -1))) >> 31)) & 2))) >> 31) & 1);
      int v915 = v914[v1014];
      bool v1015 = !(v915 == 0);
      if (v1015) {
        int * v916 = v869->cache_tags;
        int v917 = v916[v1014];
        int * v918 = v869->cache_vals;
        int v1018 = ((4 + ((((int)((unsigned int)((int)((unsigned int)(v875 + 68) >> 2)) >> 1)) & 3) * 2)) + ((((v909 + ((~(((v911 ^ -1) | (-(v911 ^ -1))) >> 31)) & 2)) - (v912 + ((~(((v913 ^ -1) | (-(v913 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
        int v919 = v918[v1018];
        int v1019 = (((4 + ((((int)((unsigned int)((int)((unsigned int)(v875 + 68) >> 2)) >> 1)) & 3) * 2)) + ((((v909 + ((~(((v911 ^ -1) | (-(v911 ^ -1))) >> 31)) & 2)) - (v912 + ((~(((v913 ^ -1) | (-(v913 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
        int v920 = v918[v1019];
        int * v921 = v869->mem;
        int v1021 = v917 * 2;
        v921[v1021] = v919;
        int * v923 = v869->mem;
        int v1024 = (v917 * 2) + 1;
        v923[v1024] = v920;
        ;
      } else {
        ;
      }
      int * v928 = v869->mem;
      int v1029 = ((int)((unsigned int)((int)((unsigned int)(v875 + 68) >> 2)) >> 1)) * 2;
      int v929 = v928[v1029];
      int v1030 = (((int)((unsigned int)((int)((unsigned int)(v875 + 68) >> 2)) >> 1)) * 2) + 1;
      int v930 = v928[v1030];
      int * v931 = v869->cache_vals;
      int v1032 = ((4 + ((((int)((unsigned int)((int)((unsigned int)(v875 + 68) >> 2)) >> 1)) & 3) * 2)) + ((((v909 + ((~(((v911 ^ -1) | (-(v911 ^ -1))) >> 31)) & 2)) - (v912 + ((~(((v913 ^ -1) | (-(v913 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
      v931[v1032] = v929;
      int * v933 = v869->cache_vals;
      int v1035 = (((4 + ((((int)((unsigned int)((int)((unsigned int)(v875 + 68) >> 2)) >> 1)) & 3) * 2)) + ((((v909 + ((~(((v911 ^ -1) | (-(v911 ^ -1))) >> 31)) & 2)) - (v912 + ((~(((v913 ^ -1) | (-(v913 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
      v933[v1035] = v930;
      int * v935 = v869->cache_tags;
      int v1038 = (int)((unsigned int)((int)((unsigned int)(v875 + 68) >> 2)) >> 1);
      v935[v1014] = v1038;
      int * v937 = v869->cache_dirty;
      v937[v1014] = 0;
      int * v939 = v869->cache_age;
      v939[v1014] = 1;
      int * v941 = v869->cache_age;
      int v942 = v941[v1014];
      int v943 = v941[v989];
      int v1044 = v943 + ((int)((unsigned int)(v943 - v942) >> 31));
      v941[v989] = v1044;
      int * v945 = v869->cache_age;
      int v946 = v945[v990];
      int v1046 = v946 + ((int)((unsigned int)(v946 - v942) >> 31));
      v945[v990] = v1046;
      int * v948 = v869->cache_age;
      v948[v1014] = 0;
      v951 = v1014;
    }
    int * v952 = v869->cache_vals;
    int v1049 = v951 * 2;
    int v953 = v952[v1049];
    int v1050 = (v951 * 2) + 1;
    int v954 = v952[v1050];
    int v1051 = (((((int)((unsigned int)((int)((unsigned int)(v875 + 68) >> 2)) >> 1)) & 1) * 2) + ((((v893 + ((~(((v895 ^ -1) | (-(v895 ^ -1))) >> 31)) & 2)) - (v896 + ((~(((v897 ^ -1) | (-(v897 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
    v952[v1051] = v953;
    int * v956 = v869->cache_vals;
    int v1054 = ((((((int)((unsigned int)((int)((unsigned int)(v875 + 68) >> 2)) >> 1)) & 1) * 2) + ((((v893 + ((~(((v895 ^ -1) | (-(v895 ^ -1))) >> 31)) & 2)) - (v896 + ((~(((v897 ^ -1) | (-(v897 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
    v956[v1054] = v954;
    int * v958 = v869->cache_tags;
    int v1057 = ((((int)((unsigned int)((int)((unsigned int)(v875 + 68) >> 2)) >> 1)) & 1) * 2) + ((((v893 + ((~(((v895 ^ -1) | (-(v895 ^ -1))) >> 31)) & 2)) - (v896 + ((~(((v897 ^ -1) | (-(v897 ^ -1))) >> 31)) & 2))) >> 31) & 1);
    int v1058 = (int)((unsigned int)((int)((unsigned int)(v875 + 68) >> 2)) >> 1);
    v958[v1057] = v1058;
    int * v960 = v869->cache_dirty;
    v960[v1057] = 0;
    int * v962 = v869->cache_age;
    v962[v1057] = 1;
    int * v964 = v869->cache_age;
    int v965 = v964[v1057];
    int v966 = v964[v987];
    int v1064 = v966 + ((int)((unsigned int)(v966 - v965) >> 31));
    v964[v987] = v1064;
    int * v968 = v869->cache_age;
    int v969 = v968[v988];
    int v1066 = v969 + ((int)((unsigned int)(v969 - v965) >> 31));
    v968[v988] = v1066;
    int * v971 = v869->cache_age;
    v971[v1057] = 0;
    v974 = v1057;
  }
  int v1069 = (v974 * 2) + (((int)((unsigned int)(v875 + 68) >> 2)) & 1);
  int v975 = v881[v1069];
  int * v976 = v869->reg_ready;
  int v1072 = ((v873 + ((v870 - v873) & (~((v870 - v873) >> 31)))) + 1) + ((100 ^ (((~(((v879 ^ ((int)((unsigned int)((int)((unsigned int)(v875 + 68) >> 2)) >> 1))) | (-(v879 ^ ((int)((unsigned int)((int)((unsigned int)(v875 + 68) >> 2)) >> 1))))) >> 31)) | (~(((v880 ^ ((int)((unsigned int)((int)((unsigned int)(v875 + 68) >> 2)) >> 1))) | (-(v880 ^ ((int)((unsigned int)((int)((unsigned int)(v875 + 68) >> 2)) >> 1))))) >> 31))) & 104)) ^ (((~(((v877 ^ ((int)((unsigned int)((int)((unsigned int)(v875 + 68) >> 2)) >> 1))) | (-(v877 ^ ((int)((unsigned int)((int)((unsigned int)(v875 + 68) >> 2)) >> 1))))) >> 31)) | (~(((v878 ^ ((int)((unsigned int)((int)((unsigned int)(v875 + 68) >> 2)) >> 1))) | (-(v878 ^ ((int)((unsigned int)((int)((unsigned int)(v875 + 68) >> 2)) >> 1))))) >> 31))) & (1 ^ (100 ^ (((~(((v879 ^ ((int)((unsigned int)((int)((unsigned int)(v875 + 68) >> 2)) >> 1))) | (-(v879 ^ ((int)((unsigned int)((int)((unsigned int)(v875 + 68) >> 2)) >> 1))))) >> 31)) | (~(((v880 ^ ((int)((unsigned int)((int)((unsigned int)(v875 + 68) >> 2)) >> 1))) | (-(v880 ^ ((int)((unsigned int)((int)((unsigned int)(v875 + 68) >> 2)) >> 1))))) >> 31))) & 104)))));
  v976[11] = v1072;
  int * v978 = v869->regs;
  v978[11] = v975;
  struct StateT * v980 = slot_16(v869);
  return v980;
}

struct StateT * slot_18(struct StateT * v1160) {
  int v1161 = v1160->timer;
  int v1169 = v1161 + 1;
  v1160->timer = v1169;
  int * v1163 = v1160->reg_ready;
  v1163[10] = v1169;
  int * v1165 = v1160->regs;
  v1165[10] = 0;
  struct StateT * v1167 = slot_20(v1160);
  return v1167;
}

struct StateT * slot_9(struct StateT * v552) {
  int v553 = v552->timer;
  int v564 = v553 + 1;
  v552->timer = v564;
  int * v555 = v552->reg_ready;
  int v556 = v555[11];
  int * v557 = v552->regs;
  int v558 = v557[11];
  int v568 = (v556 + ((v553 - v556) & (~((v553 - v556) >> 31)))) + 1;
  v555[11] = v568;
  int * v560 = v552->regs;
  int v570 = v558 + 4;
  v560[11] = v570;
  struct StateT * v562 = slot_10(v552);
  return v562;
}

struct StateT * slot_22(struct StateT * v1718) {
  int v1719 = v1718->timer;
  int v1831 = v1719 + 1;
  v1718->timer = v1831;
  int * v1721 = v1718->reg_ready;
  int v1722 = v1721[11];
  int * v1723 = v1718->regs;
  int v1724 = v1723[11];
  int * v1725 = v1718->cache_tags;
  int v1836 = (((int)((unsigned int)((int)((unsigned int)(v1724 + 68) >> 2)) >> 1)) & 1) * 2;
  int v1726 = v1725[v1836];
  int v1837 = ((((int)((unsigned int)((int)((unsigned int)(v1724 + 68) >> 2)) >> 1)) & 1) * 2) + 1;
  int v1727 = v1725[v1837];
  int v1838 = 4 + ((((int)((unsigned int)((int)((unsigned int)(v1724 + 68) >> 2)) >> 1)) & 3) * 2);
  int v1728 = v1725[v1838];
  int v1839 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v1724 + 68) >> 2)) >> 1)) & 3) * 2)) + 1;
  int v1729 = v1725[v1839];
  int * v1730 = v1718->cache_vals;
  bool v1840 = !(((~(((v1726 ^ ((int)((unsigned int)((int)((unsigned int)(v1724 + 68) >> 2)) >> 1))) | (-(v1726 ^ ((int)((unsigned int)((int)((unsigned int)(v1724 + 68) >> 2)) >> 1))))) >> 31)) | (~(((v1727 ^ ((int)((unsigned int)((int)((unsigned int)(v1724 + 68) >> 2)) >> 1))) | (-(v1727 ^ ((int)((unsigned int)((int)((unsigned int)(v1724 + 68) >> 2)) >> 1))))) >> 31))) == 0);
  int v1823;
  if (v1840) {
    int * v1731 = v1718->cache_age;
    int v1842 = ((((int)((unsigned int)((int)((unsigned int)(v1724 + 68) >> 2)) >> 1)) & 1) * 2) + ((~(((v1727 ^ ((int)((unsigned int)((int)((unsigned int)(v1724 + 68) >> 2)) >> 1))) | (-(v1727 ^ ((int)((unsigned int)((int)((unsigned int)(v1724 + 68) >> 2)) >> 1))))) >> 31)) & 1);
    int v1732 = v1731[v1842];
    int v1733 = v1731[v1836];
    int v1843 = v1733 + ((int)((unsigned int)(v1733 - v1732) >> 31));
    v1731[v1836] = v1843;
    int * v1735 = v1718->cache_age;
    int v1736 = v1735[v1837];
    int v1845 = v1736 + ((int)((unsigned int)(v1736 - v1732) >> 31));
    v1735[v1837] = v1845;
    int * v1738 = v1718->cache_age;
    v1738[v1842] = 0;
    v1823 = v1842;
  } else {
    int * v1741 = v1718->cache_age;
    int v1849 = (((int)((unsigned int)((int)((unsigned int)(v1724 + 68) >> 2)) >> 1)) & 1) * 2;
    int v1742 = v1741[v1849];
    int * v1743 = v1718->cache_tags;
    int v1744 = v1743[v1849];
    int v1745 = v1741[v1837];
    int v1746 = v1743[v1837];
    bool v1851 = !(((~(((v1728 ^ ((int)((unsigned int)((int)((unsigned int)(v1724 + 68) >> 2)) >> 1))) | (-(v1728 ^ ((int)((unsigned int)((int)((unsigned int)(v1724 + 68) >> 2)) >> 1))))) >> 31)) | (~(((v1729 ^ ((int)((unsigned int)((int)((unsigned int)(v1724 + 68) >> 2)) >> 1))) | (-(v1729 ^ ((int)((unsigned int)((int)((unsigned int)(v1724 + 68) >> 2)) >> 1))))) >> 31))) == 0);
    int v1800;
    if (v1851) {
      int * v1747 = v1718->cache_age;
      int v1853 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v1724 + 68) >> 2)) >> 1)) & 3) * 2)) + ((~(((v1729 ^ ((int)((unsigned int)((int)((unsigned int)(v1724 + 68) >> 2)) >> 1))) | (-(v1729 ^ ((int)((unsigned int)((int)((unsigned int)(v1724 + 68) >> 2)) >> 1))))) >> 31)) & 1);
      int v1748 = v1747[v1853];
      int v1749 = v1747[v1838];
      int v1854 = v1749 + ((int)((unsigned int)(v1749 - v1748) >> 31));
      v1747[v1838] = v1854;
      int * v1751 = v1718->cache_age;
      int v1752 = v1751[v1839];
      int v1856 = v1752 + ((int)((unsigned int)(v1752 - v1748) >> 31));
      v1751[v1839] = v1856;
      int * v1754 = v1718->cache_age;
      v1754[v1853] = 0;
      v1800 = v1853;
    } else {
      int * v1757 = v1718->cache_age;
      int v1860 = 4 + ((((int)((unsigned int)((int)((unsigned int)(v1724 + 68) >> 2)) >> 1)) & 3) * 2);
      int v1758 = v1757[v1860];
      int * v1759 = v1718->cache_tags;
      int v1760 = v1759[v1860];
      int v1761 = v1757[v1839];
      int v1762 = v1759[v1839];
      int * v1763 = v1718->cache_dirty;
      int v1863 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v1724 + 68) >> 2)) >> 1)) & 3) * 2)) + ((((v1758 + ((~(((v1760 ^ -1) | (-(v1760 ^ -1))) >> 31)) & 2)) - (v1761 + ((~(((v1762 ^ -1) | (-(v1762 ^ -1))) >> 31)) & 2))) >> 31) & 1);
      int v1764 = v1763[v1863];
      bool v1864 = !(v1764 == 0);
      if (v1864) {
        int * v1765 = v1718->cache_tags;
        int v1766 = v1765[v1863];
        int * v1767 = v1718->cache_vals;
        int v1867 = ((4 + ((((int)((unsigned int)((int)((unsigned int)(v1724 + 68) >> 2)) >> 1)) & 3) * 2)) + ((((v1758 + ((~(((v1760 ^ -1) | (-(v1760 ^ -1))) >> 31)) & 2)) - (v1761 + ((~(((v1762 ^ -1) | (-(v1762 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
        int v1768 = v1767[v1867];
        int v1868 = (((4 + ((((int)((unsigned int)((int)((unsigned int)(v1724 + 68) >> 2)) >> 1)) & 3) * 2)) + ((((v1758 + ((~(((v1760 ^ -1) | (-(v1760 ^ -1))) >> 31)) & 2)) - (v1761 + ((~(((v1762 ^ -1) | (-(v1762 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
        int v1769 = v1767[v1868];
        int * v1770 = v1718->mem;
        int v1870 = v1766 * 2;
        v1770[v1870] = v1768;
        int * v1772 = v1718->mem;
        int v1873 = (v1766 * 2) + 1;
        v1772[v1873] = v1769;
        ;
      } else {
        ;
      }
      int * v1777 = v1718->mem;
      int v1878 = ((int)((unsigned int)((int)((unsigned int)(v1724 + 68) >> 2)) >> 1)) * 2;
      int v1778 = v1777[v1878];
      int v1879 = (((int)((unsigned int)((int)((unsigned int)(v1724 + 68) >> 2)) >> 1)) * 2) + 1;
      int v1779 = v1777[v1879];
      int * v1780 = v1718->cache_vals;
      int v1881 = ((4 + ((((int)((unsigned int)((int)((unsigned int)(v1724 + 68) >> 2)) >> 1)) & 3) * 2)) + ((((v1758 + ((~(((v1760 ^ -1) | (-(v1760 ^ -1))) >> 31)) & 2)) - (v1761 + ((~(((v1762 ^ -1) | (-(v1762 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
      v1780[v1881] = v1778;
      int * v1782 = v1718->cache_vals;
      int v1884 = (((4 + ((((int)((unsigned int)((int)((unsigned int)(v1724 + 68) >> 2)) >> 1)) & 3) * 2)) + ((((v1758 + ((~(((v1760 ^ -1) | (-(v1760 ^ -1))) >> 31)) & 2)) - (v1761 + ((~(((v1762 ^ -1) | (-(v1762 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
      v1782[v1884] = v1779;
      int * v1784 = v1718->cache_tags;
      int v1887 = (int)((unsigned int)((int)((unsigned int)(v1724 + 68) >> 2)) >> 1);
      v1784[v1863] = v1887;
      int * v1786 = v1718->cache_dirty;
      v1786[v1863] = 0;
      int * v1788 = v1718->cache_age;
      v1788[v1863] = 1;
      int * v1790 = v1718->cache_age;
      int v1791 = v1790[v1863];
      int v1792 = v1790[v1838];
      int v1893 = v1792 + ((int)((unsigned int)(v1792 - v1791) >> 31));
      v1790[v1838] = v1893;
      int * v1794 = v1718->cache_age;
      int v1795 = v1794[v1839];
      int v1895 = v1795 + ((int)((unsigned int)(v1795 - v1791) >> 31));
      v1794[v1839] = v1895;
      int * v1797 = v1718->cache_age;
      v1797[v1863] = 0;
      v1800 = v1863;
    }
    int * v1801 = v1718->cache_vals;
    int v1898 = v1800 * 2;
    int v1802 = v1801[v1898];
    int v1899 = (v1800 * 2) + 1;
    int v1803 = v1801[v1899];
    int v1900 = (((((int)((unsigned int)((int)((unsigned int)(v1724 + 68) >> 2)) >> 1)) & 1) * 2) + ((((v1742 + ((~(((v1744 ^ -1) | (-(v1744 ^ -1))) >> 31)) & 2)) - (v1745 + ((~(((v1746 ^ -1) | (-(v1746 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
    v1801[v1900] = v1802;
    int * v1805 = v1718->cache_vals;
    int v1903 = ((((((int)((unsigned int)((int)((unsigned int)(v1724 + 68) >> 2)) >> 1)) & 1) * 2) + ((((v1742 + ((~(((v1744 ^ -1) | (-(v1744 ^ -1))) >> 31)) & 2)) - (v1745 + ((~(((v1746 ^ -1) | (-(v1746 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
    v1805[v1903] = v1803;
    int * v1807 = v1718->cache_tags;
    int v1906 = ((((int)((unsigned int)((int)((unsigned int)(v1724 + 68) >> 2)) >> 1)) & 1) * 2) + ((((v1742 + ((~(((v1744 ^ -1) | (-(v1744 ^ -1))) >> 31)) & 2)) - (v1745 + ((~(((v1746 ^ -1) | (-(v1746 ^ -1))) >> 31)) & 2))) >> 31) & 1);
    int v1907 = (int)((unsigned int)((int)((unsigned int)(v1724 + 68) >> 2)) >> 1);
    v1807[v1906] = v1907;
    int * v1809 = v1718->cache_dirty;
    v1809[v1906] = 0;
    int * v1811 = v1718->cache_age;
    v1811[v1906] = 1;
    int * v1813 = v1718->cache_age;
    int v1814 = v1813[v1906];
    int v1815 = v1813[v1836];
    int v1913 = v1815 + ((int)((unsigned int)(v1815 - v1814) >> 31));
    v1813[v1836] = v1913;
    int * v1817 = v1718->cache_age;
    int v1818 = v1817[v1837];
    int v1915 = v1818 + ((int)((unsigned int)(v1818 - v1814) >> 31));
    v1817[v1837] = v1915;
    int * v1820 = v1718->cache_age;
    v1820[v1906] = 0;
    v1823 = v1906;
  }
  int v1918 = (v1823 * 2) + (((int)((unsigned int)(v1724 + 68) >> 2)) & 1);
  int v1824 = v1730[v1918];
  int * v1825 = v1718->reg_ready;
  int v1921 = ((v1722 + ((v1719 - v1722) & (~((v1719 - v1722) >> 31)))) + 1) + ((100 ^ (((~(((v1728 ^ ((int)((unsigned int)((int)((unsigned int)(v1724 + 68) >> 2)) >> 1))) | (-(v1728 ^ ((int)((unsigned int)((int)((unsigned int)(v1724 + 68) >> 2)) >> 1))))) >> 31)) | (~(((v1729 ^ ((int)((unsigned int)((int)((unsigned int)(v1724 + 68) >> 2)) >> 1))) | (-(v1729 ^ ((int)((unsigned int)((int)((unsigned int)(v1724 + 68) >> 2)) >> 1))))) >> 31))) & 104)) ^ (((~(((v1726 ^ ((int)((unsigned int)((int)((unsigned int)(v1724 + 68) >> 2)) >> 1))) | (-(v1726 ^ ((int)((unsigned int)((int)((unsigned int)(v1724 + 68) >> 2)) >> 1))))) >> 31)) | (~(((v1727 ^ ((int)((unsigned int)((int)((unsigned int)(v1724 + 68) >> 2)) >> 1))) | (-(v1727 ^ ((int)((unsigned int)((int)((unsigned int)(v1724 + 68) >> 2)) >> 1))))) >> 31))) & (1 ^ (100 ^ (((~(((v1728 ^ ((int)((unsigned int)((int)((unsigned int)(v1724 + 68) >> 2)) >> 1))) | (-(v1728 ^ ((int)((unsigned int)((int)((unsigned int)(v1724 + 68) >> 2)) >> 1))))) >> 31)) | (~(((v1729 ^ ((int)((unsigned int)((int)((unsigned int)(v1724 + 68) >> 2)) >> 1))) | (-(v1729 ^ ((int)((unsigned int)((int)((unsigned int)(v1724 + 68) >> 2)) >> 1))))) >> 31))) & 104)))));
  v1825[12] = v1921;
  int * v1827 = v1718->regs;
  v1827[12] = v1824;
  struct StateT * v1829 = slot_23(v1718);
  return v1829;
}

struct StateT * slot_11(struct StateT * v596) {
  int v597 = v596->timer;
  int v608 = v597 + 1;
  v596->timer = v608;
  int * v599 = v596->reg_ready;
  int v600 = v599[10];
  int * v601 = v596->regs;
  int v602 = v601[10];
  int v612 = (v600 + ((v597 - v600) & (~((v597 - v600) >> 31)))) + 1;
  v599[10] = v612;
  int * v604 = v596->regs;
  int v614 = v602 << 29;
  v604[10] = v614;
  struct StateT * v606 = slot_12(v596);
  return v606;
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