// verify: leak (Eva should report untainted_timer: unknown) [unroll 65]
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

struct StateT * slot_12(struct StateT * v561);
struct StateT * slot_6(struct StateT * v281);
struct StateT * slot_25(struct StateT * v2596);
struct StateT * slot_16(struct StateT * v998);
struct StateT * slot_23(struct StateT * v1858);
struct StateT * slot_5(struct StateT * v267);
struct StateT * slot_2(struct StateT * v218);
struct StateT * slot_7(struct StateT * v297);
struct StateT * slot_21(struct StateT * v1874);
struct StateT * slot_3(struct StateT * v226);
struct StateT * slot_10(struct StateT * v527);
struct StateT * slot_1(struct StateT * v15);
struct StateT * slot_19(struct StateT * v1071);
struct StateT * slot_13(struct StateT * v575);
struct StateT * slot_24(struct StateT * v2077);
struct StateT * slot_0(struct StateT * v2);
struct StateT * slot_14(struct StateT * v591);
struct StateT * slot_17(struct StateT * v1014);
struct StateT * slot_20(struct StateT * v1845);
struct StateT * snippet(struct StateT * v0);
struct StateT * slot_8(struct StateT * v500);
struct StateT * slot_4(struct StateT * v247);
struct StateT * slot_15(struct StateT * v794);
struct StateT * slot_18(struct StateT * v1058);
struct StateT * slot_9(struct StateT * v513);
struct StateT * slot_22(struct StateT * v2392);
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

struct StateT * slot_25(struct StateT * v2596) {
  int v2597 = v2596->timer;
  int v2600 = v2597 + 1;
  v2596->timer = v2600;
  return v2596;
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

struct StateT * slot_23(struct StateT * v1858) {
  int v1859 = v1858->timer;
  int v1867 = v1859 + 1;
  v1858->timer = v1867;
  int * v1861 = v1858->regs;
  int v1862 = v1861[12];
  int v1863 = v1861[10];
  int v1871 = v1862 & v1863;
  v1861[10] = v1871;
  struct StateT * v1865 = slot_24(v1858);
  return v1865;
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

struct StateT * slot_21(struct StateT * v1874) {
  int v1875 = v1874->timer;
  int v1985 = v1875 + 1;
  v1874->timer = v1985;
  int * v1877 = v1874->regs;
  int v1878 = v1877[10];
  int * v1879 = v1874->cache_tags;
  int v1989 = (((int)((unsigned int)((int)((unsigned int)(v1878 + 4) >> 2)) >> 1)) & 1) * 2;
  int v1880 = v1879[v1989];
  int v1990 = ((((int)((unsigned int)((int)((unsigned int)(v1878 + 4) >> 2)) >> 1)) & 1) * 2) + 1;
  int v1881 = v1879[v1990];
  int v1991 = 4 + ((((int)((unsigned int)((int)((unsigned int)(v1878 + 4) >> 2)) >> 1)) & 3) * 2);
  int v1882 = v1879[v1991];
  int v1992 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v1878 + 4) >> 2)) >> 1)) & 3) * 2)) + 1;
  int v1883 = v1879[v1992];
  int v1884 = v1874->timer;
  int v1993 = v1884 + ((100 ^ (((~(((v1882 ^ ((int)((unsigned int)((int)((unsigned int)(v1878 + 4) >> 2)) >> 1))) | (-(v1882 ^ ((int)((unsigned int)((int)((unsigned int)(v1878 + 4) >> 2)) >> 1))))) >> 31)) | (~(((v1883 ^ ((int)((unsigned int)((int)((unsigned int)(v1878 + 4) >> 2)) >> 1))) | (-(v1883 ^ ((int)((unsigned int)((int)((unsigned int)(v1878 + 4) >> 2)) >> 1))))) >> 31))) & 104)) ^ (((~(((v1880 ^ ((int)((unsigned int)((int)((unsigned int)(v1878 + 4) >> 2)) >> 1))) | (-(v1880 ^ ((int)((unsigned int)((int)((unsigned int)(v1878 + 4) >> 2)) >> 1))))) >> 31)) | (~(((v1881 ^ ((int)((unsigned int)((int)((unsigned int)(v1878 + 4) >> 2)) >> 1))) | (-(v1881 ^ ((int)((unsigned int)((int)((unsigned int)(v1878 + 4) >> 2)) >> 1))))) >> 31))) & (1 ^ (100 ^ (((~(((v1882 ^ ((int)((unsigned int)((int)((unsigned int)(v1878 + 4) >> 2)) >> 1))) | (-(v1882 ^ ((int)((unsigned int)((int)((unsigned int)(v1878 + 4) >> 2)) >> 1))))) >> 31)) | (~(((v1883 ^ ((int)((unsigned int)((int)((unsigned int)(v1878 + 4) >> 2)) >> 1))) | (-(v1883 ^ ((int)((unsigned int)((int)((unsigned int)(v1878 + 4) >> 2)) >> 1))))) >> 31))) & 104)))));
  v1874->timer = v1993;
  int * v1886 = v1874->cache_vals;
  bool v1994 = !(((~(((v1880 ^ ((int)((unsigned int)((int)((unsigned int)(v1878 + 4) >> 2)) >> 1))) | (-(v1880 ^ ((int)((unsigned int)((int)((unsigned int)(v1878 + 4) >> 2)) >> 1))))) >> 31)) | (~(((v1881 ^ ((int)((unsigned int)((int)((unsigned int)(v1878 + 4) >> 2)) >> 1))) | (-(v1881 ^ ((int)((unsigned int)((int)((unsigned int)(v1878 + 4) >> 2)) >> 1))))) >> 31))) == 0);
  int v1979;
  if (v1994) {
    int * v1887 = v1874->cache_age;
    int v1996 = ((((int)((unsigned int)((int)((unsigned int)(v1878 + 4) >> 2)) >> 1)) & 1) * 2) + ((~(((v1881 ^ ((int)((unsigned int)((int)((unsigned int)(v1878 + 4) >> 2)) >> 1))) | (-(v1881 ^ ((int)((unsigned int)((int)((unsigned int)(v1878 + 4) >> 2)) >> 1))))) >> 31)) & 1);
    int v1888 = v1887[v1996];
    int v1889 = v1887[v1989];
    int v1997 = v1889 + ((int)((unsigned int)(v1889 - v1888) >> 31));
    v1887[v1989] = v1997;
    int * v1891 = v1874->cache_age;
    int v1892 = v1891[v1990];
    int v1999 = v1892 + ((int)((unsigned int)(v1892 - v1888) >> 31));
    v1891[v1990] = v1999;
    int * v1894 = v1874->cache_age;
    v1894[v1996] = 0;
    v1979 = v1996;
  } else {
    int * v1897 = v1874->cache_age;
    int v2003 = (((int)((unsigned int)((int)((unsigned int)(v1878 + 4) >> 2)) >> 1)) & 1) * 2;
    int v1898 = v1897[v2003];
    int * v1899 = v1874->cache_tags;
    int v1900 = v1899[v2003];
    int v1901 = v1897[v1990];
    int v1902 = v1899[v1990];
    bool v2005 = !(((~(((v1882 ^ ((int)((unsigned int)((int)((unsigned int)(v1878 + 4) >> 2)) >> 1))) | (-(v1882 ^ ((int)((unsigned int)((int)((unsigned int)(v1878 + 4) >> 2)) >> 1))))) >> 31)) | (~(((v1883 ^ ((int)((unsigned int)((int)((unsigned int)(v1878 + 4) >> 2)) >> 1))) | (-(v1883 ^ ((int)((unsigned int)((int)((unsigned int)(v1878 + 4) >> 2)) >> 1))))) >> 31))) == 0);
    int v1956;
    if (v2005) {
      int * v1903 = v1874->cache_age;
      int v2007 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v1878 + 4) >> 2)) >> 1)) & 3) * 2)) + ((~(((v1883 ^ ((int)((unsigned int)((int)((unsigned int)(v1878 + 4) >> 2)) >> 1))) | (-(v1883 ^ ((int)((unsigned int)((int)((unsigned int)(v1878 + 4) >> 2)) >> 1))))) >> 31)) & 1);
      int v1904 = v1903[v2007];
      int v1905 = v1903[v1991];
      int v2008 = v1905 + ((int)((unsigned int)(v1905 - v1904) >> 31));
      v1903[v1991] = v2008;
      int * v1907 = v1874->cache_age;
      int v1908 = v1907[v1992];
      int v2010 = v1908 + ((int)((unsigned int)(v1908 - v1904) >> 31));
      v1907[v1992] = v2010;
      int * v1910 = v1874->cache_age;
      v1910[v2007] = 0;
      v1956 = v2007;
    } else {
      int * v1913 = v1874->cache_age;
      int v2014 = 4 + ((((int)((unsigned int)((int)((unsigned int)(v1878 + 4) >> 2)) >> 1)) & 3) * 2);
      int v1914 = v1913[v2014];
      int * v1915 = v1874->cache_tags;
      int v1916 = v1915[v2014];
      int v1917 = v1913[v1992];
      int v1918 = v1915[v1992];
      int * v1919 = v1874->cache_dirty;
      int v2017 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v1878 + 4) >> 2)) >> 1)) & 3) * 2)) + ((((v1914 + ((~(((v1916 ^ -1) | (-(v1916 ^ -1))) >> 31)) & 2)) - (v1917 + ((~(((v1918 ^ -1) | (-(v1918 ^ -1))) >> 31)) & 2))) >> 31) & 1);
      int v1920 = v1919[v2017];
      bool v2018 = !(v1920 == 0);
      if (v2018) {
        int * v1921 = v1874->cache_tags;
        int v1922 = v1921[v2017];
        int * v1923 = v1874->cache_vals;
        int v2021 = ((4 + ((((int)((unsigned int)((int)((unsigned int)(v1878 + 4) >> 2)) >> 1)) & 3) * 2)) + ((((v1914 + ((~(((v1916 ^ -1) | (-(v1916 ^ -1))) >> 31)) & 2)) - (v1917 + ((~(((v1918 ^ -1) | (-(v1918 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
        int v1924 = v1923[v2021];
        int v2022 = (((4 + ((((int)((unsigned int)((int)((unsigned int)(v1878 + 4) >> 2)) >> 1)) & 3) * 2)) + ((((v1914 + ((~(((v1916 ^ -1) | (-(v1916 ^ -1))) >> 31)) & 2)) - (v1917 + ((~(((v1918 ^ -1) | (-(v1918 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
        int v1925 = v1923[v2022];
        int * v1926 = v1874->mem;
        int v2024 = v1922 * 2;
        v1926[v2024] = v1924;
        int * v1928 = v1874->mem;
        int v2027 = (v1922 * 2) + 1;
        v1928[v2027] = v1925;
        ;
      } else {
        ;
      }
      int * v1933 = v1874->mem;
      int v2032 = ((int)((unsigned int)((int)((unsigned int)(v1878 + 4) >> 2)) >> 1)) * 2;
      int v1934 = v1933[v2032];
      int v2033 = (((int)((unsigned int)((int)((unsigned int)(v1878 + 4) >> 2)) >> 1)) * 2) + 1;
      int v1935 = v1933[v2033];
      int * v1936 = v1874->cache_vals;
      int v2035 = ((4 + ((((int)((unsigned int)((int)((unsigned int)(v1878 + 4) >> 2)) >> 1)) & 3) * 2)) + ((((v1914 + ((~(((v1916 ^ -1) | (-(v1916 ^ -1))) >> 31)) & 2)) - (v1917 + ((~(((v1918 ^ -1) | (-(v1918 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
      v1936[v2035] = v1934;
      int * v1938 = v1874->cache_vals;
      int v2038 = (((4 + ((((int)((unsigned int)((int)((unsigned int)(v1878 + 4) >> 2)) >> 1)) & 3) * 2)) + ((((v1914 + ((~(((v1916 ^ -1) | (-(v1916 ^ -1))) >> 31)) & 2)) - (v1917 + ((~(((v1918 ^ -1) | (-(v1918 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
      v1938[v2038] = v1935;
      int * v1940 = v1874->cache_tags;
      int v2041 = (int)((unsigned int)((int)((unsigned int)(v1878 + 4) >> 2)) >> 1);
      v1940[v2017] = v2041;
      int * v1942 = v1874->cache_dirty;
      v1942[v2017] = 0;
      int * v1944 = v1874->cache_age;
      v1944[v2017] = 1;
      int * v1946 = v1874->cache_age;
      int v1947 = v1946[v2017];
      int v1948 = v1946[v1991];
      int v2047 = v1948 + ((int)((unsigned int)(v1948 - v1947) >> 31));
      v1946[v1991] = v2047;
      int * v1950 = v1874->cache_age;
      int v1951 = v1950[v1992];
      int v2049 = v1951 + ((int)((unsigned int)(v1951 - v1947) >> 31));
      v1950[v1992] = v2049;
      int * v1953 = v1874->cache_age;
      v1953[v2017] = 0;
      v1956 = v2017;
    }
    int * v1957 = v1874->cache_vals;
    int v2052 = v1956 * 2;
    int v1958 = v1957[v2052];
    int v2053 = (v1956 * 2) + 1;
    int v1959 = v1957[v2053];
    int v2054 = (((((int)((unsigned int)((int)((unsigned int)(v1878 + 4) >> 2)) >> 1)) & 1) * 2) + ((((v1898 + ((~(((v1900 ^ -1) | (-(v1900 ^ -1))) >> 31)) & 2)) - (v1901 + ((~(((v1902 ^ -1) | (-(v1902 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
    v1957[v2054] = v1958;
    int * v1961 = v1874->cache_vals;
    int v2057 = ((((((int)((unsigned int)((int)((unsigned int)(v1878 + 4) >> 2)) >> 1)) & 1) * 2) + ((((v1898 + ((~(((v1900 ^ -1) | (-(v1900 ^ -1))) >> 31)) & 2)) - (v1901 + ((~(((v1902 ^ -1) | (-(v1902 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
    v1961[v2057] = v1959;
    int * v1963 = v1874->cache_tags;
    int v2060 = ((((int)((unsigned int)((int)((unsigned int)(v1878 + 4) >> 2)) >> 1)) & 1) * 2) + ((((v1898 + ((~(((v1900 ^ -1) | (-(v1900 ^ -1))) >> 31)) & 2)) - (v1901 + ((~(((v1902 ^ -1) | (-(v1902 ^ -1))) >> 31)) & 2))) >> 31) & 1);
    int v2061 = (int)((unsigned int)((int)((unsigned int)(v1878 + 4) >> 2)) >> 1);
    v1963[v2060] = v2061;
    int * v1965 = v1874->cache_dirty;
    v1965[v2060] = 0;
    int * v1967 = v1874->cache_age;
    v1967[v2060] = 1;
    int * v1969 = v1874->cache_age;
    int v1970 = v1969[v2060];
    int v1971 = v1969[v1989];
    int v2067 = v1971 + ((int)((unsigned int)(v1971 - v1970) >> 31));
    v1969[v1989] = v2067;
    int * v1973 = v1874->cache_age;
    int v1974 = v1973[v1990];
    int v2069 = v1974 + ((int)((unsigned int)(v1974 - v1970) >> 31));
    v1973[v1990] = v2069;
    int * v1976 = v1874->cache_age;
    v1976[v2060] = 0;
    v1979 = v2060;
  }
  int v2072 = (v1979 * 2) + (((int)((unsigned int)(v1878 + 4) >> 2)) & 1);
  int v1980 = v1886[v2072];
  int * v1981 = v1874->regs;
  v1981[10] = v1980;
  struct StateT * v1983 = slot_22(v1874);
  return v1983;
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
  int v1504 = v1072 + 1;
  v1071->timer = v1504;
  int * v1074 = v1071->regs;
  int v1075 = v1074[12];
  int v1076 = v1074[10];
  int * v1077 = v1071->saved_regs;
  v1077[10] = v1076;
  int v1079 = v1071->timer;
  int v1510 = v1079 + 1;
  v1071->timer = v1510;
  int * v1081 = v1071->regs;
  v1081[10] = 0;
  int * v1083 = v1071->saved_regs;
  int * v1084 = v1071->regs;
  int v1085 = v1084[11];
  v1083[11] = v1085;
  int v1087 = v1071->timer;
  int v1517 = v1087 + 1;
  v1071->timer = v1517;
  int * v1089 = v1071->regs;
  v1089[11] = 0;
  int v1091 = v1071->timer;
  int v1519 = v1091 + 1;
  v1071->timer = v1519;
  int * v1093 = v1071->regs;
  int v1094 = v1093[10];
  bool v1521 = (((int)((unsigned int)(v1075 + 68) >> 2)) & 3) == (((int)((unsigned int)(v1094 + 4) >> 2)) & 3);
  int v1201;
  if (v1521) {
    int v1095 = v1071->timer;
    int v1522 = v1095 + 1;
    v1071->timer = v1522;
    v1201 = v1076;
  } else {
    int * v1098 = v1071->cache_tags;
    int v1524 = (((int)((unsigned int)((int)((unsigned int)(v1094 + 4) >> 2)) >> 1)) & 1) * 2;
    int v1099 = v1098[v1524];
    int v1525 = ((((int)((unsigned int)((int)((unsigned int)(v1094 + 4) >> 2)) >> 1)) & 1) * 2) + 1;
    int v1100 = v1098[v1525];
    int v1526 = 4 + ((((int)((unsigned int)((int)((unsigned int)(v1094 + 4) >> 2)) >> 1)) & 3) * 2);
    int v1101 = v1098[v1526];
    int v1527 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v1094 + 4) >> 2)) >> 1)) & 3) * 2)) + 1;
    int v1102 = v1098[v1527];
    int v1103 = v1071->timer;
    int v1528 = v1103 + ((100 ^ (((~(((v1101 ^ ((int)((unsigned int)((int)((unsigned int)(v1094 + 4) >> 2)) >> 1))) | (-(v1101 ^ ((int)((unsigned int)((int)((unsigned int)(v1094 + 4) >> 2)) >> 1))))) >> 31)) | (~(((v1102 ^ ((int)((unsigned int)((int)((unsigned int)(v1094 + 4) >> 2)) >> 1))) | (-(v1102 ^ ((int)((unsigned int)((int)((unsigned int)(v1094 + 4) >> 2)) >> 1))))) >> 31))) & 104)) ^ (((~(((v1099 ^ ((int)((unsigned int)((int)((unsigned int)(v1094 + 4) >> 2)) >> 1))) | (-(v1099 ^ ((int)((unsigned int)((int)((unsigned int)(v1094 + 4) >> 2)) >> 1))))) >> 31)) | (~(((v1100 ^ ((int)((unsigned int)((int)((unsigned int)(v1094 + 4) >> 2)) >> 1))) | (-(v1100 ^ ((int)((unsigned int)((int)((unsigned int)(v1094 + 4) >> 2)) >> 1))))) >> 31))) & (1 ^ (100 ^ (((~(((v1101 ^ ((int)((unsigned int)((int)((unsigned int)(v1094 + 4) >> 2)) >> 1))) | (-(v1101 ^ ((int)((unsigned int)((int)((unsigned int)(v1094 + 4) >> 2)) >> 1))))) >> 31)) | (~(((v1102 ^ ((int)((unsigned int)((int)((unsigned int)(v1094 + 4) >> 2)) >> 1))) | (-(v1102 ^ ((int)((unsigned int)((int)((unsigned int)(v1094 + 4) >> 2)) >> 1))))) >> 31))) & 104)))));
    v1071->timer = v1528;
    int * v1105 = v1071->cache_vals;
    bool v1529 = !(((~(((v1099 ^ ((int)((unsigned int)((int)((unsigned int)(v1094 + 4) >> 2)) >> 1))) | (-(v1099 ^ ((int)((unsigned int)((int)((unsigned int)(v1094 + 4) >> 2)) >> 1))))) >> 31)) | (~(((v1100 ^ ((int)((unsigned int)((int)((unsigned int)(v1094 + 4) >> 2)) >> 1))) | (-(v1100 ^ ((int)((unsigned int)((int)((unsigned int)(v1094 + 4) >> 2)) >> 1))))) >> 31))) == 0);
    int v1198;
    if (v1529) {
      int * v1106 = v1071->cache_age;
      int v1531 = ((((int)((unsigned int)((int)((unsigned int)(v1094 + 4) >> 2)) >> 1)) & 1) * 2) + ((~(((v1100 ^ ((int)((unsigned int)((int)((unsigned int)(v1094 + 4) >> 2)) >> 1))) | (-(v1100 ^ ((int)((unsigned int)((int)((unsigned int)(v1094 + 4) >> 2)) >> 1))))) >> 31)) & 1);
      int v1107 = v1106[v1531];
      int v1108 = v1106[v1524];
      int v1532 = v1108 + ((int)((unsigned int)(v1108 - v1107) >> 31));
      v1106[v1524] = v1532;
      int * v1110 = v1071->cache_age;
      int v1111 = v1110[v1525];
      int v1534 = v1111 + ((int)((unsigned int)(v1111 - v1107) >> 31));
      v1110[v1525] = v1534;
      int * v1113 = v1071->cache_age;
      v1113[v1531] = 0;
      v1198 = v1531;
    } else {
      int * v1116 = v1071->cache_age;
      int v1537 = (((int)((unsigned int)((int)((unsigned int)(v1094 + 4) >> 2)) >> 1)) & 1) * 2;
      int v1117 = v1116[v1537];
      int * v1118 = v1071->cache_tags;
      int v1119 = v1118[v1537];
      int v1120 = v1116[v1525];
      int v1121 = v1118[v1525];
      bool v1539 = !(((~(((v1101 ^ ((int)((unsigned int)((int)((unsigned int)(v1094 + 4) >> 2)) >> 1))) | (-(v1101 ^ ((int)((unsigned int)((int)((unsigned int)(v1094 + 4) >> 2)) >> 1))))) >> 31)) | (~(((v1102 ^ ((int)((unsigned int)((int)((unsigned int)(v1094 + 4) >> 2)) >> 1))) | (-(v1102 ^ ((int)((unsigned int)((int)((unsigned int)(v1094 + 4) >> 2)) >> 1))))) >> 31))) == 0);
      int v1175;
      if (v1539) {
        int * v1122 = v1071->cache_age;
        int v1541 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v1094 + 4) >> 2)) >> 1)) & 3) * 2)) + ((~(((v1102 ^ ((int)((unsigned int)((int)((unsigned int)(v1094 + 4) >> 2)) >> 1))) | (-(v1102 ^ ((int)((unsigned int)((int)((unsigned int)(v1094 + 4) >> 2)) >> 1))))) >> 31)) & 1);
        int v1123 = v1122[v1541];
        int v1124 = v1122[v1526];
        int v1542 = v1124 + ((int)((unsigned int)(v1124 - v1123) >> 31));
        v1122[v1526] = v1542;
        int * v1126 = v1071->cache_age;
        int v1127 = v1126[v1527];
        int v1544 = v1127 + ((int)((unsigned int)(v1127 - v1123) >> 31));
        v1126[v1527] = v1544;
        int * v1129 = v1071->cache_age;
        v1129[v1541] = 0;
        v1175 = v1541;
      } else {
        int * v1132 = v1071->cache_age;
        int v1547 = 4 + ((((int)((unsigned int)((int)((unsigned int)(v1094 + 4) >> 2)) >> 1)) & 3) * 2);
        int v1133 = v1132[v1547];
        int * v1134 = v1071->cache_tags;
        int v1135 = v1134[v1547];
        int v1136 = v1132[v1527];
        int v1137 = v1134[v1527];
        int * v1138 = v1071->cache_dirty;
        int v1550 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v1094 + 4) >> 2)) >> 1)) & 3) * 2)) + ((((v1133 + ((~(((v1135 ^ -1) | (-(v1135 ^ -1))) >> 31)) & 2)) - (v1136 + ((~(((v1137 ^ -1) | (-(v1137 ^ -1))) >> 31)) & 2))) >> 31) & 1);
        int v1139 = v1138[v1550];
        bool v1551 = !(v1139 == 0);
        if (v1551) {
          int * v1140 = v1071->cache_tags;
          int v1141 = v1140[v1550];
          int * v1142 = v1071->cache_vals;
          int v1554 = ((4 + ((((int)((unsigned int)((int)((unsigned int)(v1094 + 4) >> 2)) >> 1)) & 3) * 2)) + ((((v1133 + ((~(((v1135 ^ -1) | (-(v1135 ^ -1))) >> 31)) & 2)) - (v1136 + ((~(((v1137 ^ -1) | (-(v1137 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
          int v1143 = v1142[v1554];
          int v1555 = (((4 + ((((int)((unsigned int)((int)((unsigned int)(v1094 + 4) >> 2)) >> 1)) & 3) * 2)) + ((((v1133 + ((~(((v1135 ^ -1) | (-(v1135 ^ -1))) >> 31)) & 2)) - (v1136 + ((~(((v1137 ^ -1) | (-(v1137 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
          int v1144 = v1142[v1555];
          int * v1145 = v1071->mem;
          int v1557 = v1141 * 2;
          v1145[v1557] = v1143;
          int * v1147 = v1071->mem;
          int v1560 = (v1141 * 2) + 1;
          v1147[v1560] = v1144;
          ;
        } else {
          ;
        }
        int * v1152 = v1071->mem;
        int v1565 = ((int)((unsigned int)((int)((unsigned int)(v1094 + 4) >> 2)) >> 1)) * 2;
        int v1153 = v1152[v1565];
        int v1566 = (((int)((unsigned int)((int)((unsigned int)(v1094 + 4) >> 2)) >> 1)) * 2) + 1;
        int v1154 = v1152[v1566];
        int * v1155 = v1071->cache_vals;
        int v1568 = ((4 + ((((int)((unsigned int)((int)((unsigned int)(v1094 + 4) >> 2)) >> 1)) & 3) * 2)) + ((((v1133 + ((~(((v1135 ^ -1) | (-(v1135 ^ -1))) >> 31)) & 2)) - (v1136 + ((~(((v1137 ^ -1) | (-(v1137 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
        v1155[v1568] = v1153;
        int * v1157 = v1071->cache_vals;
        int v1571 = (((4 + ((((int)((unsigned int)((int)((unsigned int)(v1094 + 4) >> 2)) >> 1)) & 3) * 2)) + ((((v1133 + ((~(((v1135 ^ -1) | (-(v1135 ^ -1))) >> 31)) & 2)) - (v1136 + ((~(((v1137 ^ -1) | (-(v1137 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
        v1157[v1571] = v1154;
        int * v1159 = v1071->cache_tags;
        int v1574 = (int)((unsigned int)((int)((unsigned int)(v1094 + 4) >> 2)) >> 1);
        v1159[v1550] = v1574;
        int * v1161 = v1071->cache_dirty;
        v1161[v1550] = 0;
        int * v1163 = v1071->cache_age;
        v1163[v1550] = 1;
        int * v1165 = v1071->cache_age;
        int v1166 = v1165[v1550];
        int v1167 = v1165[v1526];
        int v1579 = v1167 + ((int)((unsigned int)(v1167 - v1166) >> 31));
        v1165[v1526] = v1579;
        int * v1169 = v1071->cache_age;
        int v1170 = v1169[v1527];
        int v1581 = v1170 + ((int)((unsigned int)(v1170 - v1166) >> 31));
        v1169[v1527] = v1581;
        int * v1172 = v1071->cache_age;
        v1172[v1550] = 0;
        v1175 = v1550;
      }
      int * v1176 = v1071->cache_vals;
      int v1584 = v1175 * 2;
      int v1177 = v1176[v1584];
      int v1585 = (v1175 * 2) + 1;
      int v1178 = v1176[v1585];
      int v1586 = (((((int)((unsigned int)((int)((unsigned int)(v1094 + 4) >> 2)) >> 1)) & 1) * 2) + ((((v1117 + ((~(((v1119 ^ -1) | (-(v1119 ^ -1))) >> 31)) & 2)) - (v1120 + ((~(((v1121 ^ -1) | (-(v1121 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
      v1176[v1586] = v1177;
      int * v1180 = v1071->cache_vals;
      int v1589 = ((((((int)((unsigned int)((int)((unsigned int)(v1094 + 4) >> 2)) >> 1)) & 1) * 2) + ((((v1117 + ((~(((v1119 ^ -1) | (-(v1119 ^ -1))) >> 31)) & 2)) - (v1120 + ((~(((v1121 ^ -1) | (-(v1121 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
      v1180[v1589] = v1178;
      int * v1182 = v1071->cache_tags;
      int v1592 = ((((int)((unsigned int)((int)((unsigned int)(v1094 + 4) >> 2)) >> 1)) & 1) * 2) + ((((v1117 + ((~(((v1119 ^ -1) | (-(v1119 ^ -1))) >> 31)) & 2)) - (v1120 + ((~(((v1121 ^ -1) | (-(v1121 ^ -1))) >> 31)) & 2))) >> 31) & 1);
      int v1593 = (int)((unsigned int)((int)((unsigned int)(v1094 + 4) >> 2)) >> 1);
      v1182[v1592] = v1593;
      int * v1184 = v1071->cache_dirty;
      v1184[v1592] = 0;
      int * v1186 = v1071->cache_age;
      v1186[v1592] = 1;
      int * v1188 = v1071->cache_age;
      int v1189 = v1188[v1592];
      int v1190 = v1188[v1524];
      int v1598 = v1190 + ((int)((unsigned int)(v1190 - v1189) >> 31));
      v1188[v1524] = v1598;
      int * v1192 = v1071->cache_age;
      int v1193 = v1192[v1525];
      int v1600 = v1193 + ((int)((unsigned int)(v1193 - v1189) >> 31));
      v1192[v1525] = v1600;
      int * v1195 = v1071->cache_age;
      v1195[v1592] = 0;
      v1198 = v1592;
    }
    int v1603 = (v1198 * 2) + (((int)((unsigned int)(v1094 + 4) >> 2)) & 1);
    int v1199 = v1105[v1603];
    v1201 = v1199;
  }
  int * v1202 = v1071->regs;
  v1202[10] = v1201;
  int * v1204 = v1071->saved_regs;
  int * v1205 = v1071->regs;
  int v1206 = v1205[12];
  v1204[12] = v1206;
  int v1208 = v1071->timer;
  int v1610 = v1208 + 1;
  v1071->timer = v1610;
  int * v1210 = v1071->regs;
  int v1211 = v1210[11];
  bool v1612 = (((int)((unsigned int)(v1075 + 68) >> 2)) & 3) == (((int)((unsigned int)(v1211 + 68) >> 2)) & 3);
  int v1318;
  if (v1612) {
    int v1212 = v1071->timer;
    int v1613 = v1212 + 1;
    v1071->timer = v1613;
    v1318 = v1076;
  } else {
    int * v1215 = v1071->cache_tags;
    int v1615 = (((int)((unsigned int)((int)((unsigned int)(v1211 + 68) >> 2)) >> 1)) & 1) * 2;
    int v1216 = v1215[v1615];
    int v1616 = ((((int)((unsigned int)((int)((unsigned int)(v1211 + 68) >> 2)) >> 1)) & 1) * 2) + 1;
    int v1217 = v1215[v1616];
    int v1617 = 4 + ((((int)((unsigned int)((int)((unsigned int)(v1211 + 68) >> 2)) >> 1)) & 3) * 2);
    int v1218 = v1215[v1617];
    int v1618 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v1211 + 68) >> 2)) >> 1)) & 3) * 2)) + 1;
    int v1219 = v1215[v1618];
    int v1220 = v1071->timer;
    int v1619 = v1220 + ((100 ^ (((~(((v1218 ^ ((int)((unsigned int)((int)((unsigned int)(v1211 + 68) >> 2)) >> 1))) | (-(v1218 ^ ((int)((unsigned int)((int)((unsigned int)(v1211 + 68) >> 2)) >> 1))))) >> 31)) | (~(((v1219 ^ ((int)((unsigned int)((int)((unsigned int)(v1211 + 68) >> 2)) >> 1))) | (-(v1219 ^ ((int)((unsigned int)((int)((unsigned int)(v1211 + 68) >> 2)) >> 1))))) >> 31))) & 104)) ^ (((~(((v1216 ^ ((int)((unsigned int)((int)((unsigned int)(v1211 + 68) >> 2)) >> 1))) | (-(v1216 ^ ((int)((unsigned int)((int)((unsigned int)(v1211 + 68) >> 2)) >> 1))))) >> 31)) | (~(((v1217 ^ ((int)((unsigned int)((int)((unsigned int)(v1211 + 68) >> 2)) >> 1))) | (-(v1217 ^ ((int)((unsigned int)((int)((unsigned int)(v1211 + 68) >> 2)) >> 1))))) >> 31))) & (1 ^ (100 ^ (((~(((v1218 ^ ((int)((unsigned int)((int)((unsigned int)(v1211 + 68) >> 2)) >> 1))) | (-(v1218 ^ ((int)((unsigned int)((int)((unsigned int)(v1211 + 68) >> 2)) >> 1))))) >> 31)) | (~(((v1219 ^ ((int)((unsigned int)((int)((unsigned int)(v1211 + 68) >> 2)) >> 1))) | (-(v1219 ^ ((int)((unsigned int)((int)((unsigned int)(v1211 + 68) >> 2)) >> 1))))) >> 31))) & 104)))));
    v1071->timer = v1619;
    int * v1222 = v1071->cache_vals;
    bool v1620 = !(((~(((v1216 ^ ((int)((unsigned int)((int)((unsigned int)(v1211 + 68) >> 2)) >> 1))) | (-(v1216 ^ ((int)((unsigned int)((int)((unsigned int)(v1211 + 68) >> 2)) >> 1))))) >> 31)) | (~(((v1217 ^ ((int)((unsigned int)((int)((unsigned int)(v1211 + 68) >> 2)) >> 1))) | (-(v1217 ^ ((int)((unsigned int)((int)((unsigned int)(v1211 + 68) >> 2)) >> 1))))) >> 31))) == 0);
    int v1315;
    if (v1620) {
      int * v1223 = v1071->cache_age;
      int v1622 = ((((int)((unsigned int)((int)((unsigned int)(v1211 + 68) >> 2)) >> 1)) & 1) * 2) + ((~(((v1217 ^ ((int)((unsigned int)((int)((unsigned int)(v1211 + 68) >> 2)) >> 1))) | (-(v1217 ^ ((int)((unsigned int)((int)((unsigned int)(v1211 + 68) >> 2)) >> 1))))) >> 31)) & 1);
      int v1224 = v1223[v1622];
      int v1225 = v1223[v1615];
      int v1623 = v1225 + ((int)((unsigned int)(v1225 - v1224) >> 31));
      v1223[v1615] = v1623;
      int * v1227 = v1071->cache_age;
      int v1228 = v1227[v1616];
      int v1625 = v1228 + ((int)((unsigned int)(v1228 - v1224) >> 31));
      v1227[v1616] = v1625;
      int * v1230 = v1071->cache_age;
      v1230[v1622] = 0;
      v1315 = v1622;
    } else {
      int * v1233 = v1071->cache_age;
      int v1628 = (((int)((unsigned int)((int)((unsigned int)(v1211 + 68) >> 2)) >> 1)) & 1) * 2;
      int v1234 = v1233[v1628];
      int * v1235 = v1071->cache_tags;
      int v1236 = v1235[v1628];
      int v1237 = v1233[v1616];
      int v1238 = v1235[v1616];
      bool v1630 = !(((~(((v1218 ^ ((int)((unsigned int)((int)((unsigned int)(v1211 + 68) >> 2)) >> 1))) | (-(v1218 ^ ((int)((unsigned int)((int)((unsigned int)(v1211 + 68) >> 2)) >> 1))))) >> 31)) | (~(((v1219 ^ ((int)((unsigned int)((int)((unsigned int)(v1211 + 68) >> 2)) >> 1))) | (-(v1219 ^ ((int)((unsigned int)((int)((unsigned int)(v1211 + 68) >> 2)) >> 1))))) >> 31))) == 0);
      int v1292;
      if (v1630) {
        int * v1239 = v1071->cache_age;
        int v1632 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v1211 + 68) >> 2)) >> 1)) & 3) * 2)) + ((~(((v1219 ^ ((int)((unsigned int)((int)((unsigned int)(v1211 + 68) >> 2)) >> 1))) | (-(v1219 ^ ((int)((unsigned int)((int)((unsigned int)(v1211 + 68) >> 2)) >> 1))))) >> 31)) & 1);
        int v1240 = v1239[v1632];
        int v1241 = v1239[v1617];
        int v1633 = v1241 + ((int)((unsigned int)(v1241 - v1240) >> 31));
        v1239[v1617] = v1633;
        int * v1243 = v1071->cache_age;
        int v1244 = v1243[v1618];
        int v1635 = v1244 + ((int)((unsigned int)(v1244 - v1240) >> 31));
        v1243[v1618] = v1635;
        int * v1246 = v1071->cache_age;
        v1246[v1632] = 0;
        v1292 = v1632;
      } else {
        int * v1249 = v1071->cache_age;
        int v1638 = 4 + ((((int)((unsigned int)((int)((unsigned int)(v1211 + 68) >> 2)) >> 1)) & 3) * 2);
        int v1250 = v1249[v1638];
        int * v1251 = v1071->cache_tags;
        int v1252 = v1251[v1638];
        int v1253 = v1249[v1618];
        int v1254 = v1251[v1618];
        int * v1255 = v1071->cache_dirty;
        int v1641 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v1211 + 68) >> 2)) >> 1)) & 3) * 2)) + ((((v1250 + ((~(((v1252 ^ -1) | (-(v1252 ^ -1))) >> 31)) & 2)) - (v1253 + ((~(((v1254 ^ -1) | (-(v1254 ^ -1))) >> 31)) & 2))) >> 31) & 1);
        int v1256 = v1255[v1641];
        bool v1642 = !(v1256 == 0);
        if (v1642) {
          int * v1257 = v1071->cache_tags;
          int v1258 = v1257[v1641];
          int * v1259 = v1071->cache_vals;
          int v1645 = ((4 + ((((int)((unsigned int)((int)((unsigned int)(v1211 + 68) >> 2)) >> 1)) & 3) * 2)) + ((((v1250 + ((~(((v1252 ^ -1) | (-(v1252 ^ -1))) >> 31)) & 2)) - (v1253 + ((~(((v1254 ^ -1) | (-(v1254 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
          int v1260 = v1259[v1645];
          int v1646 = (((4 + ((((int)((unsigned int)((int)((unsigned int)(v1211 + 68) >> 2)) >> 1)) & 3) * 2)) + ((((v1250 + ((~(((v1252 ^ -1) | (-(v1252 ^ -1))) >> 31)) & 2)) - (v1253 + ((~(((v1254 ^ -1) | (-(v1254 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
          int v1261 = v1259[v1646];
          int * v1262 = v1071->mem;
          int v1648 = v1258 * 2;
          v1262[v1648] = v1260;
          int * v1264 = v1071->mem;
          int v1651 = (v1258 * 2) + 1;
          v1264[v1651] = v1261;
          ;
        } else {
          ;
        }
        int * v1269 = v1071->mem;
        int v1656 = ((int)((unsigned int)((int)((unsigned int)(v1211 + 68) >> 2)) >> 1)) * 2;
        int v1270 = v1269[v1656];
        int v1657 = (((int)((unsigned int)((int)((unsigned int)(v1211 + 68) >> 2)) >> 1)) * 2) + 1;
        int v1271 = v1269[v1657];
        int * v1272 = v1071->cache_vals;
        int v1659 = ((4 + ((((int)((unsigned int)((int)((unsigned int)(v1211 + 68) >> 2)) >> 1)) & 3) * 2)) + ((((v1250 + ((~(((v1252 ^ -1) | (-(v1252 ^ -1))) >> 31)) & 2)) - (v1253 + ((~(((v1254 ^ -1) | (-(v1254 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
        v1272[v1659] = v1270;
        int * v1274 = v1071->cache_vals;
        int v1662 = (((4 + ((((int)((unsigned int)((int)((unsigned int)(v1211 + 68) >> 2)) >> 1)) & 3) * 2)) + ((((v1250 + ((~(((v1252 ^ -1) | (-(v1252 ^ -1))) >> 31)) & 2)) - (v1253 + ((~(((v1254 ^ -1) | (-(v1254 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
        v1274[v1662] = v1271;
        int * v1276 = v1071->cache_tags;
        int v1665 = (int)((unsigned int)((int)((unsigned int)(v1211 + 68) >> 2)) >> 1);
        v1276[v1641] = v1665;
        int * v1278 = v1071->cache_dirty;
        v1278[v1641] = 0;
        int * v1280 = v1071->cache_age;
        v1280[v1641] = 1;
        int * v1282 = v1071->cache_age;
        int v1283 = v1282[v1641];
        int v1284 = v1282[v1617];
        int v1670 = v1284 + ((int)((unsigned int)(v1284 - v1283) >> 31));
        v1282[v1617] = v1670;
        int * v1286 = v1071->cache_age;
        int v1287 = v1286[v1618];
        int v1672 = v1287 + ((int)((unsigned int)(v1287 - v1283) >> 31));
        v1286[v1618] = v1672;
        int * v1289 = v1071->cache_age;
        v1289[v1641] = 0;
        v1292 = v1641;
      }
      int * v1293 = v1071->cache_vals;
      int v1675 = v1292 * 2;
      int v1294 = v1293[v1675];
      int v1676 = (v1292 * 2) + 1;
      int v1295 = v1293[v1676];
      int v1677 = (((((int)((unsigned int)((int)((unsigned int)(v1211 + 68) >> 2)) >> 1)) & 1) * 2) + ((((v1234 + ((~(((v1236 ^ -1) | (-(v1236 ^ -1))) >> 31)) & 2)) - (v1237 + ((~(((v1238 ^ -1) | (-(v1238 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
      v1293[v1677] = v1294;
      int * v1297 = v1071->cache_vals;
      int v1680 = ((((((int)((unsigned int)((int)((unsigned int)(v1211 + 68) >> 2)) >> 1)) & 1) * 2) + ((((v1234 + ((~(((v1236 ^ -1) | (-(v1236 ^ -1))) >> 31)) & 2)) - (v1237 + ((~(((v1238 ^ -1) | (-(v1238 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
      v1297[v1680] = v1295;
      int * v1299 = v1071->cache_tags;
      int v1683 = ((((int)((unsigned int)((int)((unsigned int)(v1211 + 68) >> 2)) >> 1)) & 1) * 2) + ((((v1234 + ((~(((v1236 ^ -1) | (-(v1236 ^ -1))) >> 31)) & 2)) - (v1237 + ((~(((v1238 ^ -1) | (-(v1238 ^ -1))) >> 31)) & 2))) >> 31) & 1);
      int v1684 = (int)((unsigned int)((int)((unsigned int)(v1211 + 68) >> 2)) >> 1);
      v1299[v1683] = v1684;
      int * v1301 = v1071->cache_dirty;
      v1301[v1683] = 0;
      int * v1303 = v1071->cache_age;
      v1303[v1683] = 1;
      int * v1305 = v1071->cache_age;
      int v1306 = v1305[v1683];
      int v1307 = v1305[v1615];
      int v1689 = v1307 + ((int)((unsigned int)(v1307 - v1306) >> 31));
      v1305[v1615] = v1689;
      int * v1309 = v1071->cache_age;
      int v1310 = v1309[v1616];
      int v1691 = v1310 + ((int)((unsigned int)(v1310 - v1306) >> 31));
      v1309[v1616] = v1691;
      int * v1312 = v1071->cache_age;
      v1312[v1683] = 0;
      v1315 = v1683;
    }
    int v1694 = (v1315 * 2) + (((int)((unsigned int)(v1211 + 68) >> 2)) & 1);
    int v1316 = v1222[v1694];
    v1318 = v1316;
  }
  int * v1319 = v1071->regs;
  v1319[12] = v1318;
  int * v1321 = v1071->cache_tags;
  int v1699 = (((int)((unsigned int)((int)((unsigned int)(v1075 + 68) >> 2)) >> 1)) & 1) * 2;
  int v1322 = v1321[v1699];
  int v1700 = ((((int)((unsigned int)((int)((unsigned int)(v1075 + 68) >> 2)) >> 1)) & 1) * 2) + 1;
  int v1323 = v1321[v1700];
  int v1701 = 4 + ((((int)((unsigned int)((int)((unsigned int)(v1075 + 68) >> 2)) >> 1)) & 3) * 2);
  int v1324 = v1321[v1701];
  int v1702 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v1075 + 68) >> 2)) >> 1)) & 3) * 2)) + 1;
  int v1325 = v1321[v1702];
  int v1326 = v1071->timer;
  int v1703 = v1326 + ((100 ^ (((~(((v1324 ^ ((int)((unsigned int)((int)((unsigned int)(v1075 + 68) >> 2)) >> 1))) | (-(v1324 ^ ((int)((unsigned int)((int)((unsigned int)(v1075 + 68) >> 2)) >> 1))))) >> 31)) | (~(((v1325 ^ ((int)((unsigned int)((int)((unsigned int)(v1075 + 68) >> 2)) >> 1))) | (-(v1325 ^ ((int)((unsigned int)((int)((unsigned int)(v1075 + 68) >> 2)) >> 1))))) >> 31))) & 104)) ^ (((~(((v1322 ^ ((int)((unsigned int)((int)((unsigned int)(v1075 + 68) >> 2)) >> 1))) | (-(v1322 ^ ((int)((unsigned int)((int)((unsigned int)(v1075 + 68) >> 2)) >> 1))))) >> 31)) | (~(((v1323 ^ ((int)((unsigned int)((int)((unsigned int)(v1075 + 68) >> 2)) >> 1))) | (-(v1323 ^ ((int)((unsigned int)((int)((unsigned int)(v1075 + 68) >> 2)) >> 1))))) >> 31))) & (1 ^ (100 ^ (((~(((v1324 ^ ((int)((unsigned int)((int)((unsigned int)(v1075 + 68) >> 2)) >> 1))) | (-(v1324 ^ ((int)((unsigned int)((int)((unsigned int)(v1075 + 68) >> 2)) >> 1))))) >> 31)) | (~(((v1325 ^ ((int)((unsigned int)((int)((unsigned int)(v1075 + 68) >> 2)) >> 1))) | (-(v1325 ^ ((int)((unsigned int)((int)((unsigned int)(v1075 + 68) >> 2)) >> 1))))) >> 31))) & 104)))));
  v1071->timer = v1703;
  bool v1704 = !(((~(((v1322 ^ ((int)((unsigned int)((int)((unsigned int)(v1075 + 68) >> 2)) >> 1))) | (-(v1322 ^ ((int)((unsigned int)((int)((unsigned int)(v1075 + 68) >> 2)) >> 1))))) >> 31)) | (~(((v1323 ^ ((int)((unsigned int)((int)((unsigned int)(v1075 + 68) >> 2)) >> 1))) | (-(v1323 ^ ((int)((unsigned int)((int)((unsigned int)(v1075 + 68) >> 2)) >> 1))))) >> 31))) == 0);
  int v1420;
  if (v1704) {
    int * v1328 = v1071->cache_age;
    int v1706 = ((((int)((unsigned int)((int)((unsigned int)(v1075 + 68) >> 2)) >> 1)) & 1) * 2) + ((~(((v1323 ^ ((int)((unsigned int)((int)((unsigned int)(v1075 + 68) >> 2)) >> 1))) | (-(v1323 ^ ((int)((unsigned int)((int)((unsigned int)(v1075 + 68) >> 2)) >> 1))))) >> 31)) & 1);
    int v1329 = v1328[v1706];
    int v1330 = v1328[v1699];
    int v1707 = v1330 + ((int)((unsigned int)(v1330 - v1329) >> 31));
    v1328[v1699] = v1707;
    int * v1332 = v1071->cache_age;
    int v1333 = v1332[v1700];
    int v1709 = v1333 + ((int)((unsigned int)(v1333 - v1329) >> 31));
    v1332[v1700] = v1709;
    int * v1335 = v1071->cache_age;
    v1335[v1706] = 0;
    v1420 = v1706;
  } else {
    int * v1338 = v1071->cache_age;
    int v1712 = (((int)((unsigned int)((int)((unsigned int)(v1075 + 68) >> 2)) >> 1)) & 1) * 2;
    int v1339 = v1338[v1712];
    int * v1340 = v1071->cache_tags;
    int v1341 = v1340[v1712];
    int v1342 = v1338[v1700];
    int v1343 = v1340[v1700];
    bool v1714 = !(((~(((v1324 ^ ((int)((unsigned int)((int)((unsigned int)(v1075 + 68) >> 2)) >> 1))) | (-(v1324 ^ ((int)((unsigned int)((int)((unsigned int)(v1075 + 68) >> 2)) >> 1))))) >> 31)) | (~(((v1325 ^ ((int)((unsigned int)((int)((unsigned int)(v1075 + 68) >> 2)) >> 1))) | (-(v1325 ^ ((int)((unsigned int)((int)((unsigned int)(v1075 + 68) >> 2)) >> 1))))) >> 31))) == 0);
    int v1397;
    if (v1714) {
      int * v1344 = v1071->cache_age;
      int v1716 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v1075 + 68) >> 2)) >> 1)) & 3) * 2)) + ((~(((v1325 ^ ((int)((unsigned int)((int)((unsigned int)(v1075 + 68) >> 2)) >> 1))) | (-(v1325 ^ ((int)((unsigned int)((int)((unsigned int)(v1075 + 68) >> 2)) >> 1))))) >> 31)) & 1);
      int v1345 = v1344[v1716];
      int v1346 = v1344[v1701];
      int v1717 = v1346 + ((int)((unsigned int)(v1346 - v1345) >> 31));
      v1344[v1701] = v1717;
      int * v1348 = v1071->cache_age;
      int v1349 = v1348[v1702];
      int v1719 = v1349 + ((int)((unsigned int)(v1349 - v1345) >> 31));
      v1348[v1702] = v1719;
      int * v1351 = v1071->cache_age;
      v1351[v1716] = 0;
      v1397 = v1716;
    } else {
      int * v1354 = v1071->cache_age;
      int v1722 = 4 + ((((int)((unsigned int)((int)((unsigned int)(v1075 + 68) >> 2)) >> 1)) & 3) * 2);
      int v1355 = v1354[v1722];
      int * v1356 = v1071->cache_tags;
      int v1357 = v1356[v1722];
      int v1358 = v1354[v1702];
      int v1359 = v1356[v1702];
      int * v1360 = v1071->cache_dirty;
      int v1725 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v1075 + 68) >> 2)) >> 1)) & 3) * 2)) + ((((v1355 + ((~(((v1357 ^ -1) | (-(v1357 ^ -1))) >> 31)) & 2)) - (v1358 + ((~(((v1359 ^ -1) | (-(v1359 ^ -1))) >> 31)) & 2))) >> 31) & 1);
      int v1361 = v1360[v1725];
      bool v1726 = !(v1361 == 0);
      if (v1726) {
        int * v1362 = v1071->cache_tags;
        int v1363 = v1362[v1725];
        int * v1364 = v1071->cache_vals;
        int v1729 = ((4 + ((((int)((unsigned int)((int)((unsigned int)(v1075 + 68) >> 2)) >> 1)) & 3) * 2)) + ((((v1355 + ((~(((v1357 ^ -1) | (-(v1357 ^ -1))) >> 31)) & 2)) - (v1358 + ((~(((v1359 ^ -1) | (-(v1359 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
        int v1365 = v1364[v1729];
        int v1730 = (((4 + ((((int)((unsigned int)((int)((unsigned int)(v1075 + 68) >> 2)) >> 1)) & 3) * 2)) + ((((v1355 + ((~(((v1357 ^ -1) | (-(v1357 ^ -1))) >> 31)) & 2)) - (v1358 + ((~(((v1359 ^ -1) | (-(v1359 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
        int v1366 = v1364[v1730];
        int * v1367 = v1071->mem;
        int v1732 = v1363 * 2;
        v1367[v1732] = v1365;
        int * v1369 = v1071->mem;
        int v1735 = (v1363 * 2) + 1;
        v1369[v1735] = v1366;
        ;
      } else {
        ;
      }
      int * v1374 = v1071->mem;
      int v1740 = ((int)((unsigned int)((int)((unsigned int)(v1075 + 68) >> 2)) >> 1)) * 2;
      int v1375 = v1374[v1740];
      int v1741 = (((int)((unsigned int)((int)((unsigned int)(v1075 + 68) >> 2)) >> 1)) * 2) + 1;
      int v1376 = v1374[v1741];
      int * v1377 = v1071->cache_vals;
      int v1743 = ((4 + ((((int)((unsigned int)((int)((unsigned int)(v1075 + 68) >> 2)) >> 1)) & 3) * 2)) + ((((v1355 + ((~(((v1357 ^ -1) | (-(v1357 ^ -1))) >> 31)) & 2)) - (v1358 + ((~(((v1359 ^ -1) | (-(v1359 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
      v1377[v1743] = v1375;
      int * v1379 = v1071->cache_vals;
      int v1746 = (((4 + ((((int)((unsigned int)((int)((unsigned int)(v1075 + 68) >> 2)) >> 1)) & 3) * 2)) + ((((v1355 + ((~(((v1357 ^ -1) | (-(v1357 ^ -1))) >> 31)) & 2)) - (v1358 + ((~(((v1359 ^ -1) | (-(v1359 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
      v1379[v1746] = v1376;
      int * v1381 = v1071->cache_tags;
      int v1749 = (int)((unsigned int)((int)((unsigned int)(v1075 + 68) >> 2)) >> 1);
      v1381[v1725] = v1749;
      int * v1383 = v1071->cache_dirty;
      v1383[v1725] = 0;
      int * v1385 = v1071->cache_age;
      v1385[v1725] = 1;
      int * v1387 = v1071->cache_age;
      int v1388 = v1387[v1725];
      int v1389 = v1387[v1701];
      int v1754 = v1389 + ((int)((unsigned int)(v1389 - v1388) >> 31));
      v1387[v1701] = v1754;
      int * v1391 = v1071->cache_age;
      int v1392 = v1391[v1702];
      int v1756 = v1392 + ((int)((unsigned int)(v1392 - v1388) >> 31));
      v1391[v1702] = v1756;
      int * v1394 = v1071->cache_age;
      v1394[v1725] = 0;
      v1397 = v1725;
    }
    int * v1398 = v1071->cache_vals;
    int v1759 = v1397 * 2;
    int v1399 = v1398[v1759];
    int v1760 = (v1397 * 2) + 1;
    int v1400 = v1398[v1760];
    int v1761 = (((((int)((unsigned int)((int)((unsigned int)(v1075 + 68) >> 2)) >> 1)) & 1) * 2) + ((((v1339 + ((~(((v1341 ^ -1) | (-(v1341 ^ -1))) >> 31)) & 2)) - (v1342 + ((~(((v1343 ^ -1) | (-(v1343 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
    v1398[v1761] = v1399;
    int * v1402 = v1071->cache_vals;
    int v1764 = ((((((int)((unsigned int)((int)((unsigned int)(v1075 + 68) >> 2)) >> 1)) & 1) * 2) + ((((v1339 + ((~(((v1341 ^ -1) | (-(v1341 ^ -1))) >> 31)) & 2)) - (v1342 + ((~(((v1343 ^ -1) | (-(v1343 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
    v1402[v1764] = v1400;
    int * v1404 = v1071->cache_tags;
    int v1767 = ((((int)((unsigned int)((int)((unsigned int)(v1075 + 68) >> 2)) >> 1)) & 1) * 2) + ((((v1339 + ((~(((v1341 ^ -1) | (-(v1341 ^ -1))) >> 31)) & 2)) - (v1342 + ((~(((v1343 ^ -1) | (-(v1343 ^ -1))) >> 31)) & 2))) >> 31) & 1);
    int v1768 = (int)((unsigned int)((int)((unsigned int)(v1075 + 68) >> 2)) >> 1);
    v1404[v1767] = v1768;
    int * v1406 = v1071->cache_dirty;
    v1406[v1767] = 0;
    int * v1408 = v1071->cache_age;
    v1408[v1767] = 1;
    int * v1410 = v1071->cache_age;
    int v1411 = v1410[v1767];
    int v1412 = v1410[v1699];
    int v1773 = v1412 + ((int)((unsigned int)(v1412 - v1411) >> 31));
    v1410[v1699] = v1773;
    int * v1414 = v1071->cache_age;
    int v1415 = v1414[v1700];
    int v1775 = v1415 + ((int)((unsigned int)(v1415 - v1411) >> 31));
    v1414[v1700] = v1775;
    int * v1417 = v1071->cache_age;
    v1417[v1767] = 0;
    v1420 = v1767;
  }
  int * v1421 = v1071->cache_vals;
  int v1778 = (v1420 * 2) + (((int)((unsigned int)(v1075 + 68) >> 2)) & 1);
  v1421[v1778] = v1076;
  int * v1423 = v1071->cache_tags;
  int v1424 = v1423[v1701];
  int v1425 = v1423[v1702];
  bool v1780 = !(((~(((v1424 ^ ((int)((unsigned int)((int)((unsigned int)(v1075 + 68) >> 2)) >> 1))) | (-(v1424 ^ ((int)((unsigned int)((int)((unsigned int)(v1075 + 68) >> 2)) >> 1))))) >> 31)) | (~(((v1425 ^ ((int)((unsigned int)((int)((unsigned int)(v1075 + 68) >> 2)) >> 1))) | (-(v1425 ^ ((int)((unsigned int)((int)((unsigned int)(v1075 + 68) >> 2)) >> 1))))) >> 31))) == 0);
  int v1479;
  if (v1780) {
    int * v1426 = v1071->cache_age;
    int v1782 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v1075 + 68) >> 2)) >> 1)) & 3) * 2)) + ((~(((v1425 ^ ((int)((unsigned int)((int)((unsigned int)(v1075 + 68) >> 2)) >> 1))) | (-(v1425 ^ ((int)((unsigned int)((int)((unsigned int)(v1075 + 68) >> 2)) >> 1))))) >> 31)) & 1);
    int v1427 = v1426[v1782];
    int v1428 = v1426[v1701];
    int v1783 = v1428 + ((int)((unsigned int)(v1428 - v1427) >> 31));
    v1426[v1701] = v1783;
    int * v1430 = v1071->cache_age;
    int v1431 = v1430[v1702];
    int v1785 = v1431 + ((int)((unsigned int)(v1431 - v1427) >> 31));
    v1430[v1702] = v1785;
    int * v1433 = v1071->cache_age;
    v1433[v1782] = 0;
    v1479 = v1782;
  } else {
    int * v1436 = v1071->cache_age;
    int v1788 = 4 + ((((int)((unsigned int)((int)((unsigned int)(v1075 + 68) >> 2)) >> 1)) & 3) * 2);
    int v1437 = v1436[v1788];
    int * v1438 = v1071->cache_tags;
    int v1439 = v1438[v1788];
    int v1440 = v1436[v1702];
    int v1441 = v1438[v1702];
    int * v1442 = v1071->cache_dirty;
    int v1791 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v1075 + 68) >> 2)) >> 1)) & 3) * 2)) + ((((v1437 + ((~(((v1439 ^ -1) | (-(v1439 ^ -1))) >> 31)) & 2)) - (v1440 + ((~(((v1441 ^ -1) | (-(v1441 ^ -1))) >> 31)) & 2))) >> 31) & 1);
    int v1443 = v1442[v1791];
    bool v1792 = !(v1443 == 0);
    if (v1792) {
      int * v1444 = v1071->cache_tags;
      int v1445 = v1444[v1791];
      int * v1446 = v1071->cache_vals;
      int v1795 = ((4 + ((((int)((unsigned int)((int)((unsigned int)(v1075 + 68) >> 2)) >> 1)) & 3) * 2)) + ((((v1437 + ((~(((v1439 ^ -1) | (-(v1439 ^ -1))) >> 31)) & 2)) - (v1440 + ((~(((v1441 ^ -1) | (-(v1441 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
      int v1447 = v1446[v1795];
      int v1796 = (((4 + ((((int)((unsigned int)((int)((unsigned int)(v1075 + 68) >> 2)) >> 1)) & 3) * 2)) + ((((v1437 + ((~(((v1439 ^ -1) | (-(v1439 ^ -1))) >> 31)) & 2)) - (v1440 + ((~(((v1441 ^ -1) | (-(v1441 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
      int v1448 = v1446[v1796];
      int * v1449 = v1071->mem;
      int v1798 = v1445 * 2;
      v1449[v1798] = v1447;
      int * v1451 = v1071->mem;
      int v1801 = (v1445 * 2) + 1;
      v1451[v1801] = v1448;
      ;
    } else {
      ;
    }
    int * v1456 = v1071->mem;
    int v1806 = ((int)((unsigned int)((int)((unsigned int)(v1075 + 68) >> 2)) >> 1)) * 2;
    int v1457 = v1456[v1806];
    int v1807 = (((int)((unsigned int)((int)((unsigned int)(v1075 + 68) >> 2)) >> 1)) * 2) + 1;
    int v1458 = v1456[v1807];
    int * v1459 = v1071->cache_vals;
    int v1809 = ((4 + ((((int)((unsigned int)((int)((unsigned int)(v1075 + 68) >> 2)) >> 1)) & 3) * 2)) + ((((v1437 + ((~(((v1439 ^ -1) | (-(v1439 ^ -1))) >> 31)) & 2)) - (v1440 + ((~(((v1441 ^ -1) | (-(v1441 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
    v1459[v1809] = v1457;
    int * v1461 = v1071->cache_vals;
    int v1812 = (((4 + ((((int)((unsigned int)((int)((unsigned int)(v1075 + 68) >> 2)) >> 1)) & 3) * 2)) + ((((v1437 + ((~(((v1439 ^ -1) | (-(v1439 ^ -1))) >> 31)) & 2)) - (v1440 + ((~(((v1441 ^ -1) | (-(v1441 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
    v1461[v1812] = v1458;
    int * v1463 = v1071->cache_tags;
    int v1815 = (int)((unsigned int)((int)((unsigned int)(v1075 + 68) >> 2)) >> 1);
    v1463[v1791] = v1815;
    int * v1465 = v1071->cache_dirty;
    v1465[v1791] = 0;
    int * v1467 = v1071->cache_age;
    v1467[v1791] = 1;
    int * v1469 = v1071->cache_age;
    int v1470 = v1469[v1791];
    int v1471 = v1469[v1701];
    int v1820 = v1471 + ((int)((unsigned int)(v1471 - v1470) >> 31));
    v1469[v1701] = v1820;
    int * v1473 = v1071->cache_age;
    int v1474 = v1473[v1702];
    int v1822 = v1474 + ((int)((unsigned int)(v1474 - v1470) >> 31));
    v1473[v1702] = v1822;
    int * v1476 = v1071->cache_age;
    v1476[v1791] = 0;
    v1479 = v1791;
  }
  int * v1480 = v1071->cache_vals;
  int v1825 = (v1479 * 2) + (((int)((unsigned int)(v1075 + 68) >> 2)) & 1);
  v1480[v1825] = v1076;
  int * v1482 = v1071->cache_dirty;
  v1482[v1479] = 1;
  bool v1829 = (((((int)((unsigned int)(v1094 + 4) >> 2)) & 3) == (((int)((unsigned int)(v1075 + 68) >> 2)) & 3)) & (!(((int)((unsigned int)(v1094 + 4) >> 2)) == ((int)((unsigned int)(v1075 + 68) >> 2))))) | (((((int)((unsigned int)(v1211 + 68) >> 2)) & 3) == (((int)((unsigned int)(v1075 + 68) >> 2)) & 3)) & (!(((int)((unsigned int)(v1211 + 68) >> 2)) == ((int)((unsigned int)(v1075 + 68) >> 2)))));
  struct StateT * v1502;
  if (v1829) {
    int v1484 = v1071->timer;
    int v1830 = v1484 + 15;
    v1071->timer = v1830;
    int * v1486 = v1071->saved_regs;
    int v1487 = v1486[10];
    int * v1488 = v1071->regs;
    v1488[10] = v1487;
    int * v1490 = v1071->saved_regs;
    int v1491 = v1490[11];
    int * v1492 = v1071->regs;
    v1492[11] = v1491;
    int * v1494 = v1071->saved_regs;
    int v1495 = v1494[12];
    int * v1496 = v1071->regs;
    v1496[12] = v1495;
    struct StateT * v1498 = slot_18(v1071);
    v1502 = v1498;
  } else {
    struct StateT * v1500 = slot_23(v1071);
    v1502 = v1500;
  }
  return v1502;
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

struct StateT * slot_24(struct StateT * v2077) {
  int v2078 = v2077->timer;
  int v2248 = v2078 + 1;
  v2077->timer = v2248;
  int * v2080 = v2077->regs;
  int v2081 = v2080[11];
  int v2082 = v2080[10];
  int * v2083 = v2077->cache_tags;
  int v2253 = (((int)((unsigned int)((int)((unsigned int)(v2081 + 68) >> 2)) >> 1)) & 1) * 2;
  int v2084 = v2083[v2253];
  int v2254 = ((((int)((unsigned int)((int)((unsigned int)(v2081 + 68) >> 2)) >> 1)) & 1) * 2) + 1;
  int v2085 = v2083[v2254];
  int v2255 = 4 + ((((int)((unsigned int)((int)((unsigned int)(v2081 + 68) >> 2)) >> 1)) & 3) * 2);
  int v2086 = v2083[v2255];
  int v2256 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v2081 + 68) >> 2)) >> 1)) & 3) * 2)) + 1;
  int v2087 = v2083[v2256];
  int v2088 = v2077->timer;
  int v2257 = v2088 + ((100 ^ (((~(((v2086 ^ ((int)((unsigned int)((int)((unsigned int)(v2081 + 68) >> 2)) >> 1))) | (-(v2086 ^ ((int)((unsigned int)((int)((unsigned int)(v2081 + 68) >> 2)) >> 1))))) >> 31)) | (~(((v2087 ^ ((int)((unsigned int)((int)((unsigned int)(v2081 + 68) >> 2)) >> 1))) | (-(v2087 ^ ((int)((unsigned int)((int)((unsigned int)(v2081 + 68) >> 2)) >> 1))))) >> 31))) & 104)) ^ (((~(((v2084 ^ ((int)((unsigned int)((int)((unsigned int)(v2081 + 68) >> 2)) >> 1))) | (-(v2084 ^ ((int)((unsigned int)((int)((unsigned int)(v2081 + 68) >> 2)) >> 1))))) >> 31)) | (~(((v2085 ^ ((int)((unsigned int)((int)((unsigned int)(v2081 + 68) >> 2)) >> 1))) | (-(v2085 ^ ((int)((unsigned int)((int)((unsigned int)(v2081 + 68) >> 2)) >> 1))))) >> 31))) & (1 ^ (100 ^ (((~(((v2086 ^ ((int)((unsigned int)((int)((unsigned int)(v2081 + 68) >> 2)) >> 1))) | (-(v2086 ^ ((int)((unsigned int)((int)((unsigned int)(v2081 + 68) >> 2)) >> 1))))) >> 31)) | (~(((v2087 ^ ((int)((unsigned int)((int)((unsigned int)(v2081 + 68) >> 2)) >> 1))) | (-(v2087 ^ ((int)((unsigned int)((int)((unsigned int)(v2081 + 68) >> 2)) >> 1))))) >> 31))) & 104)))));
  v2077->timer = v2257;
  bool v2258 = !(((~(((v2084 ^ ((int)((unsigned int)((int)((unsigned int)(v2081 + 68) >> 2)) >> 1))) | (-(v2084 ^ ((int)((unsigned int)((int)((unsigned int)(v2081 + 68) >> 2)) >> 1))))) >> 31)) | (~(((v2085 ^ ((int)((unsigned int)((int)((unsigned int)(v2081 + 68) >> 2)) >> 1))) | (-(v2085 ^ ((int)((unsigned int)((int)((unsigned int)(v2081 + 68) >> 2)) >> 1))))) >> 31))) == 0);
  int v2182;
  if (v2258) {
    int * v2090 = v2077->cache_age;
    int v2260 = ((((int)((unsigned int)((int)((unsigned int)(v2081 + 68) >> 2)) >> 1)) & 1) * 2) + ((~(((v2085 ^ ((int)((unsigned int)((int)((unsigned int)(v2081 + 68) >> 2)) >> 1))) | (-(v2085 ^ ((int)((unsigned int)((int)((unsigned int)(v2081 + 68) >> 2)) >> 1))))) >> 31)) & 1);
    int v2091 = v2090[v2260];
    int v2092 = v2090[v2253];
    int v2261 = v2092 + ((int)((unsigned int)(v2092 - v2091) >> 31));
    v2090[v2253] = v2261;
    int * v2094 = v2077->cache_age;
    int v2095 = v2094[v2254];
    int v2263 = v2095 + ((int)((unsigned int)(v2095 - v2091) >> 31));
    v2094[v2254] = v2263;
    int * v2097 = v2077->cache_age;
    v2097[v2260] = 0;
    v2182 = v2260;
  } else {
    int * v2100 = v2077->cache_age;
    int v2267 = (((int)((unsigned int)((int)((unsigned int)(v2081 + 68) >> 2)) >> 1)) & 1) * 2;
    int v2101 = v2100[v2267];
    int * v2102 = v2077->cache_tags;
    int v2103 = v2102[v2267];
    int v2104 = v2100[v2254];
    int v2105 = v2102[v2254];
    bool v2269 = !(((~(((v2086 ^ ((int)((unsigned int)((int)((unsigned int)(v2081 + 68) >> 2)) >> 1))) | (-(v2086 ^ ((int)((unsigned int)((int)((unsigned int)(v2081 + 68) >> 2)) >> 1))))) >> 31)) | (~(((v2087 ^ ((int)((unsigned int)((int)((unsigned int)(v2081 + 68) >> 2)) >> 1))) | (-(v2087 ^ ((int)((unsigned int)((int)((unsigned int)(v2081 + 68) >> 2)) >> 1))))) >> 31))) == 0);
    int v2159;
    if (v2269) {
      int * v2106 = v2077->cache_age;
      int v2271 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v2081 + 68) >> 2)) >> 1)) & 3) * 2)) + ((~(((v2087 ^ ((int)((unsigned int)((int)((unsigned int)(v2081 + 68) >> 2)) >> 1))) | (-(v2087 ^ ((int)((unsigned int)((int)((unsigned int)(v2081 + 68) >> 2)) >> 1))))) >> 31)) & 1);
      int v2107 = v2106[v2271];
      int v2108 = v2106[v2255];
      int v2272 = v2108 + ((int)((unsigned int)(v2108 - v2107) >> 31));
      v2106[v2255] = v2272;
      int * v2110 = v2077->cache_age;
      int v2111 = v2110[v2256];
      int v2274 = v2111 + ((int)((unsigned int)(v2111 - v2107) >> 31));
      v2110[v2256] = v2274;
      int * v2113 = v2077->cache_age;
      v2113[v2271] = 0;
      v2159 = v2271;
    } else {
      int * v2116 = v2077->cache_age;
      int v2278 = 4 + ((((int)((unsigned int)((int)((unsigned int)(v2081 + 68) >> 2)) >> 1)) & 3) * 2);
      int v2117 = v2116[v2278];
      int * v2118 = v2077->cache_tags;
      int v2119 = v2118[v2278];
      int v2120 = v2116[v2256];
      int v2121 = v2118[v2256];
      int * v2122 = v2077->cache_dirty;
      int v2281 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v2081 + 68) >> 2)) >> 1)) & 3) * 2)) + ((((v2117 + ((~(((v2119 ^ -1) | (-(v2119 ^ -1))) >> 31)) & 2)) - (v2120 + ((~(((v2121 ^ -1) | (-(v2121 ^ -1))) >> 31)) & 2))) >> 31) & 1);
      int v2123 = v2122[v2281];
      bool v2282 = !(v2123 == 0);
      if (v2282) {
        int * v2124 = v2077->cache_tags;
        int v2125 = v2124[v2281];
        int * v2126 = v2077->cache_vals;
        int v2285 = ((4 + ((((int)((unsigned int)((int)((unsigned int)(v2081 + 68) >> 2)) >> 1)) & 3) * 2)) + ((((v2117 + ((~(((v2119 ^ -1) | (-(v2119 ^ -1))) >> 31)) & 2)) - (v2120 + ((~(((v2121 ^ -1) | (-(v2121 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
        int v2127 = v2126[v2285];
        int v2286 = (((4 + ((((int)((unsigned int)((int)((unsigned int)(v2081 + 68) >> 2)) >> 1)) & 3) * 2)) + ((((v2117 + ((~(((v2119 ^ -1) | (-(v2119 ^ -1))) >> 31)) & 2)) - (v2120 + ((~(((v2121 ^ -1) | (-(v2121 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
        int v2128 = v2126[v2286];
        int * v2129 = v2077->mem;
        int v2288 = v2125 * 2;
        v2129[v2288] = v2127;
        int * v2131 = v2077->mem;
        int v2291 = (v2125 * 2) + 1;
        v2131[v2291] = v2128;
        ;
      } else {
        ;
      }
      int * v2136 = v2077->mem;
      int v2296 = ((int)((unsigned int)((int)((unsigned int)(v2081 + 68) >> 2)) >> 1)) * 2;
      int v2137 = v2136[v2296];
      int v2297 = (((int)((unsigned int)((int)((unsigned int)(v2081 + 68) >> 2)) >> 1)) * 2) + 1;
      int v2138 = v2136[v2297];
      int * v2139 = v2077->cache_vals;
      int v2299 = ((4 + ((((int)((unsigned int)((int)((unsigned int)(v2081 + 68) >> 2)) >> 1)) & 3) * 2)) + ((((v2117 + ((~(((v2119 ^ -1) | (-(v2119 ^ -1))) >> 31)) & 2)) - (v2120 + ((~(((v2121 ^ -1) | (-(v2121 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
      v2139[v2299] = v2137;
      int * v2141 = v2077->cache_vals;
      int v2302 = (((4 + ((((int)((unsigned int)((int)((unsigned int)(v2081 + 68) >> 2)) >> 1)) & 3) * 2)) + ((((v2117 + ((~(((v2119 ^ -1) | (-(v2119 ^ -1))) >> 31)) & 2)) - (v2120 + ((~(((v2121 ^ -1) | (-(v2121 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
      v2141[v2302] = v2138;
      int * v2143 = v2077->cache_tags;
      int v2305 = (int)((unsigned int)((int)((unsigned int)(v2081 + 68) >> 2)) >> 1);
      v2143[v2281] = v2305;
      int * v2145 = v2077->cache_dirty;
      v2145[v2281] = 0;
      int * v2147 = v2077->cache_age;
      v2147[v2281] = 1;
      int * v2149 = v2077->cache_age;
      int v2150 = v2149[v2281];
      int v2151 = v2149[v2255];
      int v2311 = v2151 + ((int)((unsigned int)(v2151 - v2150) >> 31));
      v2149[v2255] = v2311;
      int * v2153 = v2077->cache_age;
      int v2154 = v2153[v2256];
      int v2313 = v2154 + ((int)((unsigned int)(v2154 - v2150) >> 31));
      v2153[v2256] = v2313;
      int * v2156 = v2077->cache_age;
      v2156[v2281] = 0;
      v2159 = v2281;
    }
    int * v2160 = v2077->cache_vals;
    int v2316 = v2159 * 2;
    int v2161 = v2160[v2316];
    int v2317 = (v2159 * 2) + 1;
    int v2162 = v2160[v2317];
    int v2318 = (((((int)((unsigned int)((int)((unsigned int)(v2081 + 68) >> 2)) >> 1)) & 1) * 2) + ((((v2101 + ((~(((v2103 ^ -1) | (-(v2103 ^ -1))) >> 31)) & 2)) - (v2104 + ((~(((v2105 ^ -1) | (-(v2105 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
    v2160[v2318] = v2161;
    int * v2164 = v2077->cache_vals;
    int v2321 = ((((((int)((unsigned int)((int)((unsigned int)(v2081 + 68) >> 2)) >> 1)) & 1) * 2) + ((((v2101 + ((~(((v2103 ^ -1) | (-(v2103 ^ -1))) >> 31)) & 2)) - (v2104 + ((~(((v2105 ^ -1) | (-(v2105 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
    v2164[v2321] = v2162;
    int * v2166 = v2077->cache_tags;
    int v2324 = ((((int)((unsigned int)((int)((unsigned int)(v2081 + 68) >> 2)) >> 1)) & 1) * 2) + ((((v2101 + ((~(((v2103 ^ -1) | (-(v2103 ^ -1))) >> 31)) & 2)) - (v2104 + ((~(((v2105 ^ -1) | (-(v2105 ^ -1))) >> 31)) & 2))) >> 31) & 1);
    int v2325 = (int)((unsigned int)((int)((unsigned int)(v2081 + 68) >> 2)) >> 1);
    v2166[v2324] = v2325;
    int * v2168 = v2077->cache_dirty;
    v2168[v2324] = 0;
    int * v2170 = v2077->cache_age;
    v2170[v2324] = 1;
    int * v2172 = v2077->cache_age;
    int v2173 = v2172[v2324];
    int v2174 = v2172[v2253];
    int v2331 = v2174 + ((int)((unsigned int)(v2174 - v2173) >> 31));
    v2172[v2253] = v2331;
    int * v2176 = v2077->cache_age;
    int v2177 = v2176[v2254];
    int v2333 = v2177 + ((int)((unsigned int)(v2177 - v2173) >> 31));
    v2176[v2254] = v2333;
    int * v2179 = v2077->cache_age;
    v2179[v2324] = 0;
    v2182 = v2324;
  }
  int * v2183 = v2077->cache_vals;
  int v2336 = (v2182 * 2) + (((int)((unsigned int)(v2081 + 68) >> 2)) & 1);
  v2183[v2336] = v2082;
  int * v2185 = v2077->cache_tags;
  int v2186 = v2185[v2255];
  int v2187 = v2185[v2256];
  bool v2339 = !(((~(((v2186 ^ ((int)((unsigned int)((int)((unsigned int)(v2081 + 68) >> 2)) >> 1))) | (-(v2186 ^ ((int)((unsigned int)((int)((unsigned int)(v2081 + 68) >> 2)) >> 1))))) >> 31)) | (~(((v2187 ^ ((int)((unsigned int)((int)((unsigned int)(v2081 + 68) >> 2)) >> 1))) | (-(v2187 ^ ((int)((unsigned int)((int)((unsigned int)(v2081 + 68) >> 2)) >> 1))))) >> 31))) == 0);
  int v2241;
  if (v2339) {
    int * v2188 = v2077->cache_age;
    int v2341 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v2081 + 68) >> 2)) >> 1)) & 3) * 2)) + ((~(((v2187 ^ ((int)((unsigned int)((int)((unsigned int)(v2081 + 68) >> 2)) >> 1))) | (-(v2187 ^ ((int)((unsigned int)((int)((unsigned int)(v2081 + 68) >> 2)) >> 1))))) >> 31)) & 1);
    int v2189 = v2188[v2341];
    int v2190 = v2188[v2255];
    int v2342 = v2190 + ((int)((unsigned int)(v2190 - v2189) >> 31));
    v2188[v2255] = v2342;
    int * v2192 = v2077->cache_age;
    int v2193 = v2192[v2256];
    int v2344 = v2193 + ((int)((unsigned int)(v2193 - v2189) >> 31));
    v2192[v2256] = v2344;
    int * v2195 = v2077->cache_age;
    v2195[v2341] = 0;
    v2241 = v2341;
  } else {
    int * v2198 = v2077->cache_age;
    int v2348 = 4 + ((((int)((unsigned int)((int)((unsigned int)(v2081 + 68) >> 2)) >> 1)) & 3) * 2);
    int v2199 = v2198[v2348];
    int * v2200 = v2077->cache_tags;
    int v2201 = v2200[v2348];
    int v2202 = v2198[v2256];
    int v2203 = v2200[v2256];
    int * v2204 = v2077->cache_dirty;
    int v2351 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v2081 + 68) >> 2)) >> 1)) & 3) * 2)) + ((((v2199 + ((~(((v2201 ^ -1) | (-(v2201 ^ -1))) >> 31)) & 2)) - (v2202 + ((~(((v2203 ^ -1) | (-(v2203 ^ -1))) >> 31)) & 2))) >> 31) & 1);
    int v2205 = v2204[v2351];
    bool v2352 = !(v2205 == 0);
    if (v2352) {
      int * v2206 = v2077->cache_tags;
      int v2207 = v2206[v2351];
      int * v2208 = v2077->cache_vals;
      int v2355 = ((4 + ((((int)((unsigned int)((int)((unsigned int)(v2081 + 68) >> 2)) >> 1)) & 3) * 2)) + ((((v2199 + ((~(((v2201 ^ -1) | (-(v2201 ^ -1))) >> 31)) & 2)) - (v2202 + ((~(((v2203 ^ -1) | (-(v2203 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
      int v2209 = v2208[v2355];
      int v2356 = (((4 + ((((int)((unsigned int)((int)((unsigned int)(v2081 + 68) >> 2)) >> 1)) & 3) * 2)) + ((((v2199 + ((~(((v2201 ^ -1) | (-(v2201 ^ -1))) >> 31)) & 2)) - (v2202 + ((~(((v2203 ^ -1) | (-(v2203 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
      int v2210 = v2208[v2356];
      int * v2211 = v2077->mem;
      int v2358 = v2207 * 2;
      v2211[v2358] = v2209;
      int * v2213 = v2077->mem;
      int v2361 = (v2207 * 2) + 1;
      v2213[v2361] = v2210;
      ;
    } else {
      ;
    }
    int * v2218 = v2077->mem;
    int v2366 = ((int)((unsigned int)((int)((unsigned int)(v2081 + 68) >> 2)) >> 1)) * 2;
    int v2219 = v2218[v2366];
    int v2367 = (((int)((unsigned int)((int)((unsigned int)(v2081 + 68) >> 2)) >> 1)) * 2) + 1;
    int v2220 = v2218[v2367];
    int * v2221 = v2077->cache_vals;
    int v2369 = ((4 + ((((int)((unsigned int)((int)((unsigned int)(v2081 + 68) >> 2)) >> 1)) & 3) * 2)) + ((((v2199 + ((~(((v2201 ^ -1) | (-(v2201 ^ -1))) >> 31)) & 2)) - (v2202 + ((~(((v2203 ^ -1) | (-(v2203 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
    v2221[v2369] = v2219;
    int * v2223 = v2077->cache_vals;
    int v2372 = (((4 + ((((int)((unsigned int)((int)((unsigned int)(v2081 + 68) >> 2)) >> 1)) & 3) * 2)) + ((((v2199 + ((~(((v2201 ^ -1) | (-(v2201 ^ -1))) >> 31)) & 2)) - (v2202 + ((~(((v2203 ^ -1) | (-(v2203 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
    v2223[v2372] = v2220;
    int * v2225 = v2077->cache_tags;
    int v2375 = (int)((unsigned int)((int)((unsigned int)(v2081 + 68) >> 2)) >> 1);
    v2225[v2351] = v2375;
    int * v2227 = v2077->cache_dirty;
    v2227[v2351] = 0;
    int * v2229 = v2077->cache_age;
    v2229[v2351] = 1;
    int * v2231 = v2077->cache_age;
    int v2232 = v2231[v2351];
    int v2233 = v2231[v2255];
    int v2381 = v2233 + ((int)((unsigned int)(v2233 - v2232) >> 31));
    v2231[v2255] = v2381;
    int * v2235 = v2077->cache_age;
    int v2236 = v2235[v2256];
    int v2383 = v2236 + ((int)((unsigned int)(v2236 - v2232) >> 31));
    v2235[v2256] = v2383;
    int * v2238 = v2077->cache_age;
    v2238[v2351] = 0;
    v2241 = v2351;
  }
  int * v2242 = v2077->cache_vals;
  int v2386 = (v2241 * 2) + (((int)((unsigned int)(v2081 + 68) >> 2)) & 1);
  v2242[v2386] = v2082;
  int * v2244 = v2077->cache_dirty;
  v2244[v2241] = 1;
  struct StateT * v2246 = slot_25(v2077);
  return v2246;
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

struct StateT * slot_20(struct StateT * v1845) {
  int v1846 = v1845->timer;
  int v1852 = v1846 + 1;
  v1845->timer = v1852;
  int * v1848 = v1845->regs;
  v1848[11] = 0;
  struct StateT * v1850 = slot_21(v1845);
  return v1850;
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

struct StateT * slot_22(struct StateT * v2392) {
  int v2393 = v2392->timer;
  int v2503 = v2393 + 1;
  v2392->timer = v2503;
  int * v2395 = v2392->regs;
  int v2396 = v2395[11];
  int * v2397 = v2392->cache_tags;
  int v2507 = (((int)((unsigned int)((int)((unsigned int)(v2396 + 68) >> 2)) >> 1)) & 1) * 2;
  int v2398 = v2397[v2507];
  int v2508 = ((((int)((unsigned int)((int)((unsigned int)(v2396 + 68) >> 2)) >> 1)) & 1) * 2) + 1;
  int v2399 = v2397[v2508];
  int v2509 = 4 + ((((int)((unsigned int)((int)((unsigned int)(v2396 + 68) >> 2)) >> 1)) & 3) * 2);
  int v2400 = v2397[v2509];
  int v2510 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v2396 + 68) >> 2)) >> 1)) & 3) * 2)) + 1;
  int v2401 = v2397[v2510];
  int v2402 = v2392->timer;
  int v2511 = v2402 + ((100 ^ (((~(((v2400 ^ ((int)((unsigned int)((int)((unsigned int)(v2396 + 68) >> 2)) >> 1))) | (-(v2400 ^ ((int)((unsigned int)((int)((unsigned int)(v2396 + 68) >> 2)) >> 1))))) >> 31)) | (~(((v2401 ^ ((int)((unsigned int)((int)((unsigned int)(v2396 + 68) >> 2)) >> 1))) | (-(v2401 ^ ((int)((unsigned int)((int)((unsigned int)(v2396 + 68) >> 2)) >> 1))))) >> 31))) & 104)) ^ (((~(((v2398 ^ ((int)((unsigned int)((int)((unsigned int)(v2396 + 68) >> 2)) >> 1))) | (-(v2398 ^ ((int)((unsigned int)((int)((unsigned int)(v2396 + 68) >> 2)) >> 1))))) >> 31)) | (~(((v2399 ^ ((int)((unsigned int)((int)((unsigned int)(v2396 + 68) >> 2)) >> 1))) | (-(v2399 ^ ((int)((unsigned int)((int)((unsigned int)(v2396 + 68) >> 2)) >> 1))))) >> 31))) & (1 ^ (100 ^ (((~(((v2400 ^ ((int)((unsigned int)((int)((unsigned int)(v2396 + 68) >> 2)) >> 1))) | (-(v2400 ^ ((int)((unsigned int)((int)((unsigned int)(v2396 + 68) >> 2)) >> 1))))) >> 31)) | (~(((v2401 ^ ((int)((unsigned int)((int)((unsigned int)(v2396 + 68) >> 2)) >> 1))) | (-(v2401 ^ ((int)((unsigned int)((int)((unsigned int)(v2396 + 68) >> 2)) >> 1))))) >> 31))) & 104)))));
  v2392->timer = v2511;
  int * v2404 = v2392->cache_vals;
  bool v2512 = !(((~(((v2398 ^ ((int)((unsigned int)((int)((unsigned int)(v2396 + 68) >> 2)) >> 1))) | (-(v2398 ^ ((int)((unsigned int)((int)((unsigned int)(v2396 + 68) >> 2)) >> 1))))) >> 31)) | (~(((v2399 ^ ((int)((unsigned int)((int)((unsigned int)(v2396 + 68) >> 2)) >> 1))) | (-(v2399 ^ ((int)((unsigned int)((int)((unsigned int)(v2396 + 68) >> 2)) >> 1))))) >> 31))) == 0);
  int v2497;
  if (v2512) {
    int * v2405 = v2392->cache_age;
    int v2514 = ((((int)((unsigned int)((int)((unsigned int)(v2396 + 68) >> 2)) >> 1)) & 1) * 2) + ((~(((v2399 ^ ((int)((unsigned int)((int)((unsigned int)(v2396 + 68) >> 2)) >> 1))) | (-(v2399 ^ ((int)((unsigned int)((int)((unsigned int)(v2396 + 68) >> 2)) >> 1))))) >> 31)) & 1);
    int v2406 = v2405[v2514];
    int v2407 = v2405[v2507];
    int v2515 = v2407 + ((int)((unsigned int)(v2407 - v2406) >> 31));
    v2405[v2507] = v2515;
    int * v2409 = v2392->cache_age;
    int v2410 = v2409[v2508];
    int v2517 = v2410 + ((int)((unsigned int)(v2410 - v2406) >> 31));
    v2409[v2508] = v2517;
    int * v2412 = v2392->cache_age;
    v2412[v2514] = 0;
    v2497 = v2514;
  } else {
    int * v2415 = v2392->cache_age;
    int v2521 = (((int)((unsigned int)((int)((unsigned int)(v2396 + 68) >> 2)) >> 1)) & 1) * 2;
    int v2416 = v2415[v2521];
    int * v2417 = v2392->cache_tags;
    int v2418 = v2417[v2521];
    int v2419 = v2415[v2508];
    int v2420 = v2417[v2508];
    bool v2523 = !(((~(((v2400 ^ ((int)((unsigned int)((int)((unsigned int)(v2396 + 68) >> 2)) >> 1))) | (-(v2400 ^ ((int)((unsigned int)((int)((unsigned int)(v2396 + 68) >> 2)) >> 1))))) >> 31)) | (~(((v2401 ^ ((int)((unsigned int)((int)((unsigned int)(v2396 + 68) >> 2)) >> 1))) | (-(v2401 ^ ((int)((unsigned int)((int)((unsigned int)(v2396 + 68) >> 2)) >> 1))))) >> 31))) == 0);
    int v2474;
    if (v2523) {
      int * v2421 = v2392->cache_age;
      int v2525 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v2396 + 68) >> 2)) >> 1)) & 3) * 2)) + ((~(((v2401 ^ ((int)((unsigned int)((int)((unsigned int)(v2396 + 68) >> 2)) >> 1))) | (-(v2401 ^ ((int)((unsigned int)((int)((unsigned int)(v2396 + 68) >> 2)) >> 1))))) >> 31)) & 1);
      int v2422 = v2421[v2525];
      int v2423 = v2421[v2509];
      int v2526 = v2423 + ((int)((unsigned int)(v2423 - v2422) >> 31));
      v2421[v2509] = v2526;
      int * v2425 = v2392->cache_age;
      int v2426 = v2425[v2510];
      int v2528 = v2426 + ((int)((unsigned int)(v2426 - v2422) >> 31));
      v2425[v2510] = v2528;
      int * v2428 = v2392->cache_age;
      v2428[v2525] = 0;
      v2474 = v2525;
    } else {
      int * v2431 = v2392->cache_age;
      int v2532 = 4 + ((((int)((unsigned int)((int)((unsigned int)(v2396 + 68) >> 2)) >> 1)) & 3) * 2);
      int v2432 = v2431[v2532];
      int * v2433 = v2392->cache_tags;
      int v2434 = v2433[v2532];
      int v2435 = v2431[v2510];
      int v2436 = v2433[v2510];
      int * v2437 = v2392->cache_dirty;
      int v2535 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v2396 + 68) >> 2)) >> 1)) & 3) * 2)) + ((((v2432 + ((~(((v2434 ^ -1) | (-(v2434 ^ -1))) >> 31)) & 2)) - (v2435 + ((~(((v2436 ^ -1) | (-(v2436 ^ -1))) >> 31)) & 2))) >> 31) & 1);
      int v2438 = v2437[v2535];
      bool v2536 = !(v2438 == 0);
      if (v2536) {
        int * v2439 = v2392->cache_tags;
        int v2440 = v2439[v2535];
        int * v2441 = v2392->cache_vals;
        int v2539 = ((4 + ((((int)((unsigned int)((int)((unsigned int)(v2396 + 68) >> 2)) >> 1)) & 3) * 2)) + ((((v2432 + ((~(((v2434 ^ -1) | (-(v2434 ^ -1))) >> 31)) & 2)) - (v2435 + ((~(((v2436 ^ -1) | (-(v2436 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
        int v2442 = v2441[v2539];
        int v2540 = (((4 + ((((int)((unsigned int)((int)((unsigned int)(v2396 + 68) >> 2)) >> 1)) & 3) * 2)) + ((((v2432 + ((~(((v2434 ^ -1) | (-(v2434 ^ -1))) >> 31)) & 2)) - (v2435 + ((~(((v2436 ^ -1) | (-(v2436 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
        int v2443 = v2441[v2540];
        int * v2444 = v2392->mem;
        int v2542 = v2440 * 2;
        v2444[v2542] = v2442;
        int * v2446 = v2392->mem;
        int v2545 = (v2440 * 2) + 1;
        v2446[v2545] = v2443;
        ;
      } else {
        ;
      }
      int * v2451 = v2392->mem;
      int v2550 = ((int)((unsigned int)((int)((unsigned int)(v2396 + 68) >> 2)) >> 1)) * 2;
      int v2452 = v2451[v2550];
      int v2551 = (((int)((unsigned int)((int)((unsigned int)(v2396 + 68) >> 2)) >> 1)) * 2) + 1;
      int v2453 = v2451[v2551];
      int * v2454 = v2392->cache_vals;
      int v2553 = ((4 + ((((int)((unsigned int)((int)((unsigned int)(v2396 + 68) >> 2)) >> 1)) & 3) * 2)) + ((((v2432 + ((~(((v2434 ^ -1) | (-(v2434 ^ -1))) >> 31)) & 2)) - (v2435 + ((~(((v2436 ^ -1) | (-(v2436 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
      v2454[v2553] = v2452;
      int * v2456 = v2392->cache_vals;
      int v2556 = (((4 + ((((int)((unsigned int)((int)((unsigned int)(v2396 + 68) >> 2)) >> 1)) & 3) * 2)) + ((((v2432 + ((~(((v2434 ^ -1) | (-(v2434 ^ -1))) >> 31)) & 2)) - (v2435 + ((~(((v2436 ^ -1) | (-(v2436 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
      v2456[v2556] = v2453;
      int * v2458 = v2392->cache_tags;
      int v2559 = (int)((unsigned int)((int)((unsigned int)(v2396 + 68) >> 2)) >> 1);
      v2458[v2535] = v2559;
      int * v2460 = v2392->cache_dirty;
      v2460[v2535] = 0;
      int * v2462 = v2392->cache_age;
      v2462[v2535] = 1;
      int * v2464 = v2392->cache_age;
      int v2465 = v2464[v2535];
      int v2466 = v2464[v2509];
      int v2565 = v2466 + ((int)((unsigned int)(v2466 - v2465) >> 31));
      v2464[v2509] = v2565;
      int * v2468 = v2392->cache_age;
      int v2469 = v2468[v2510];
      int v2567 = v2469 + ((int)((unsigned int)(v2469 - v2465) >> 31));
      v2468[v2510] = v2567;
      int * v2471 = v2392->cache_age;
      v2471[v2535] = 0;
      v2474 = v2535;
    }
    int * v2475 = v2392->cache_vals;
    int v2570 = v2474 * 2;
    int v2476 = v2475[v2570];
    int v2571 = (v2474 * 2) + 1;
    int v2477 = v2475[v2571];
    int v2572 = (((((int)((unsigned int)((int)((unsigned int)(v2396 + 68) >> 2)) >> 1)) & 1) * 2) + ((((v2416 + ((~(((v2418 ^ -1) | (-(v2418 ^ -1))) >> 31)) & 2)) - (v2419 + ((~(((v2420 ^ -1) | (-(v2420 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
    v2475[v2572] = v2476;
    int * v2479 = v2392->cache_vals;
    int v2575 = ((((((int)((unsigned int)((int)((unsigned int)(v2396 + 68) >> 2)) >> 1)) & 1) * 2) + ((((v2416 + ((~(((v2418 ^ -1) | (-(v2418 ^ -1))) >> 31)) & 2)) - (v2419 + ((~(((v2420 ^ -1) | (-(v2420 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
    v2479[v2575] = v2477;
    int * v2481 = v2392->cache_tags;
    int v2578 = ((((int)((unsigned int)((int)((unsigned int)(v2396 + 68) >> 2)) >> 1)) & 1) * 2) + ((((v2416 + ((~(((v2418 ^ -1) | (-(v2418 ^ -1))) >> 31)) & 2)) - (v2419 + ((~(((v2420 ^ -1) | (-(v2420 ^ -1))) >> 31)) & 2))) >> 31) & 1);
    int v2579 = (int)((unsigned int)((int)((unsigned int)(v2396 + 68) >> 2)) >> 1);
    v2481[v2578] = v2579;
    int * v2483 = v2392->cache_dirty;
    v2483[v2578] = 0;
    int * v2485 = v2392->cache_age;
    v2485[v2578] = 1;
    int * v2487 = v2392->cache_age;
    int v2488 = v2487[v2578];
    int v2489 = v2487[v2507];
    int v2585 = v2489 + ((int)((unsigned int)(v2489 - v2488) >> 31));
    v2487[v2507] = v2585;
    int * v2491 = v2392->cache_age;
    int v2492 = v2491[v2508];
    int v2587 = v2492 + ((int)((unsigned int)(v2492 - v2488) >> 31));
    v2491[v2508] = v2587;
    int * v2494 = v2392->cache_age;
    v2494[v2578] = 0;
    v2497 = v2578;
  }
  int v2590 = (v2497 * 2) + (((int)((unsigned int)(v2396 + 68) >> 2)) & 1);
  int v2498 = v2404[v2590];
  int * v2499 = v2392->regs;
  v2499[12] = v2498;
  struct StateT * v2501 = slot_23(v2392);
  return v2501;
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