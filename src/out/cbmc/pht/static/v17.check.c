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

struct StateT * slot_12(struct StateT * v527);
struct StateT * slot_14(struct StateT * v554);
struct StateT * slot_6(struct StateT * v275);
struct StateT * slot_16(struct StateT * v581);
struct StateT * slot_5(struct StateT * v72);
struct StateT * slot_17(struct StateT * v597);
struct StateT * slot_20(struct StateT * v1020);
struct StateT * slot_2(struct StateT * v29);
struct StateT * slot_7(struct StateT * v478);
struct StateT * slot_3(struct StateT * v43);
struct StateT * snippet(struct StateT * v0);
struct StateT * slot_10(struct StateT * v513);
struct StateT * slot_1(struct StateT * v16);
struct StateT * slot_8(struct StateT * v486);
struct StateT * slot_19(struct StateT * v1004);
struct StateT * slot_4(struct StateT * v59);
struct StateT * slot_13(struct StateT * v540);
struct StateT * slot_15(struct StateT * v567);
struct StateT * slot_18(struct StateT * v800);
struct StateT * slot_9(struct StateT * v508);
struct StateT * slot_0(struct StateT * v2);
struct StateT * slot_12(struct StateT * v527) {
  int v528 = v527->timer;
  int v534 = v528 + 1;
  v527->timer = v534;
  int * v530 = v527->regs;
  v530[11] = 0;
  struct StateT * v532 = slot_13(v527);
  return v532;
}

struct StateT * slot_14(struct StateT * v554) {
  int v555 = v554->timer;
  int v561 = v555 + 1;
  v554->timer = v561;
  int * v557 = v554->regs;
  v557[12] = 0;
  struct StateT * v559 = slot_15(v554);
  return v559;
}

struct StateT * slot_6(struct StateT * v275) {
  int v276 = v275->timer;
  int v386 = v276 + 1;
  v275->timer = v386;
  int * v278 = v275->regs;
  int v279 = v278[11];
  int * v280 = v275->cache_tags;
  int v390 = (((int)((unsigned int)((int)((unsigned int)v279 >> 2)) >> 1)) & 1) * 2;
  int v281 = v280[v390];
  int v391 = ((((int)((unsigned int)((int)((unsigned int)v279 >> 2)) >> 1)) & 1) * 2) + 1;
  int v282 = v280[v391];
  int v392 = 4 + ((((int)((unsigned int)((int)((unsigned int)v279 >> 2)) >> 1)) & 3) * 2);
  int v283 = v280[v392];
  int v393 = (4 + ((((int)((unsigned int)((int)((unsigned int)v279 >> 2)) >> 1)) & 3) * 2)) + 1;
  int v284 = v280[v393];
  int v285 = v275->timer;
  int v394 = v285 + ((100 ^ (((~(((v283 ^ ((int)((unsigned int)((int)((unsigned int)v279 >> 2)) >> 1))) | (-(v283 ^ ((int)((unsigned int)((int)((unsigned int)v279 >> 2)) >> 1))))) >> 31)) | (~(((v284 ^ ((int)((unsigned int)((int)((unsigned int)v279 >> 2)) >> 1))) | (-(v284 ^ ((int)((unsigned int)((int)((unsigned int)v279 >> 2)) >> 1))))) >> 31))) & 104)) ^ (((~(((v281 ^ ((int)((unsigned int)((int)((unsigned int)v279 >> 2)) >> 1))) | (-(v281 ^ ((int)((unsigned int)((int)((unsigned int)v279 >> 2)) >> 1))))) >> 31)) | (~(((v282 ^ ((int)((unsigned int)((int)((unsigned int)v279 >> 2)) >> 1))) | (-(v282 ^ ((int)((unsigned int)((int)((unsigned int)v279 >> 2)) >> 1))))) >> 31))) & (1 ^ (100 ^ (((~(((v283 ^ ((int)((unsigned int)((int)((unsigned int)v279 >> 2)) >> 1))) | (-(v283 ^ ((int)((unsigned int)((int)((unsigned int)v279 >> 2)) >> 1))))) >> 31)) | (~(((v284 ^ ((int)((unsigned int)((int)((unsigned int)v279 >> 2)) >> 1))) | (-(v284 ^ ((int)((unsigned int)((int)((unsigned int)v279 >> 2)) >> 1))))) >> 31))) & 104)))));
  v275->timer = v394;
  int * v287 = v275->cache_vals;
  bool v395 = !(((~(((v281 ^ ((int)((unsigned int)((int)((unsigned int)v279 >> 2)) >> 1))) | (-(v281 ^ ((int)((unsigned int)((int)((unsigned int)v279 >> 2)) >> 1))))) >> 31)) | (~(((v282 ^ ((int)((unsigned int)((int)((unsigned int)v279 >> 2)) >> 1))) | (-(v282 ^ ((int)((unsigned int)((int)((unsigned int)v279 >> 2)) >> 1))))) >> 31))) == 0);
  int v380;
  if (v395) {
    int * v288 = v275->cache_age;
    int v397 = ((((int)((unsigned int)((int)((unsigned int)v279 >> 2)) >> 1)) & 1) * 2) + ((~(((v282 ^ ((int)((unsigned int)((int)((unsigned int)v279 >> 2)) >> 1))) | (-(v282 ^ ((int)((unsigned int)((int)((unsigned int)v279 >> 2)) >> 1))))) >> 31)) & 1);
    int v289 = v288[v397];
    int v290 = v288[v390];
    int v398 = v290 + ((int)((unsigned int)(v290 - v289) >> 31));
    v288[v390] = v398;
    int * v292 = v275->cache_age;
    int v293 = v292[v391];
    int v400 = v293 + ((int)((unsigned int)(v293 - v289) >> 31));
    v292[v391] = v400;
    int * v295 = v275->cache_age;
    v295[v397] = 0;
    v380 = v397;
  } else {
    int * v298 = v275->cache_age;
    int v404 = (((int)((unsigned int)((int)((unsigned int)v279 >> 2)) >> 1)) & 1) * 2;
    int v299 = v298[v404];
    int * v300 = v275->cache_tags;
    int v301 = v300[v404];
    int v302 = v298[v391];
    int v303 = v300[v391];
    bool v406 = !(((~(((v283 ^ ((int)((unsigned int)((int)((unsigned int)v279 >> 2)) >> 1))) | (-(v283 ^ ((int)((unsigned int)((int)((unsigned int)v279 >> 2)) >> 1))))) >> 31)) | (~(((v284 ^ ((int)((unsigned int)((int)((unsigned int)v279 >> 2)) >> 1))) | (-(v284 ^ ((int)((unsigned int)((int)((unsigned int)v279 >> 2)) >> 1))))) >> 31))) == 0);
    int v357;
    if (v406) {
      int * v304 = v275->cache_age;
      int v408 = (4 + ((((int)((unsigned int)((int)((unsigned int)v279 >> 2)) >> 1)) & 3) * 2)) + ((~(((v284 ^ ((int)((unsigned int)((int)((unsigned int)v279 >> 2)) >> 1))) | (-(v284 ^ ((int)((unsigned int)((int)((unsigned int)v279 >> 2)) >> 1))))) >> 31)) & 1);
      int v305 = v304[v408];
      int v306 = v304[v392];
      int v409 = v306 + ((int)((unsigned int)(v306 - v305) >> 31));
      v304[v392] = v409;
      int * v308 = v275->cache_age;
      int v309 = v308[v393];
      int v411 = v309 + ((int)((unsigned int)(v309 - v305) >> 31));
      v308[v393] = v411;
      int * v311 = v275->cache_age;
      v311[v408] = 0;
      v357 = v408;
    } else {
      int * v314 = v275->cache_age;
      int v415 = 4 + ((((int)((unsigned int)((int)((unsigned int)v279 >> 2)) >> 1)) & 3) * 2);
      int v315 = v314[v415];
      int * v316 = v275->cache_tags;
      int v317 = v316[v415];
      int v318 = v314[v393];
      int v319 = v316[v393];
      int * v320 = v275->cache_dirty;
      int v418 = (4 + ((((int)((unsigned int)((int)((unsigned int)v279 >> 2)) >> 1)) & 3) * 2)) + ((((v315 + ((~(((v317 ^ -1) | (-(v317 ^ -1))) >> 31)) & 2)) - (v318 + ((~(((v319 ^ -1) | (-(v319 ^ -1))) >> 31)) & 2))) >> 31) & 1);
      int v321 = v320[v418];
      bool v419 = !(v321 == 0);
      if (v419) {
        int * v322 = v275->cache_tags;
        int v323 = v322[v418];
        int * v324 = v275->cache_vals;
        int v422 = ((4 + ((((int)((unsigned int)((int)((unsigned int)v279 >> 2)) >> 1)) & 3) * 2)) + ((((v315 + ((~(((v317 ^ -1) | (-(v317 ^ -1))) >> 31)) & 2)) - (v318 + ((~(((v319 ^ -1) | (-(v319 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
        int v325 = v324[v422];
        int v423 = (((4 + ((((int)((unsigned int)((int)((unsigned int)v279 >> 2)) >> 1)) & 3) * 2)) + ((((v315 + ((~(((v317 ^ -1) | (-(v317 ^ -1))) >> 31)) & 2)) - (v318 + ((~(((v319 ^ -1) | (-(v319 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
        int v326 = v324[v423];
        int * v327 = v275->mem;
        int v425 = v323 * 2;
        v327[v425] = v325;
        int * v329 = v275->mem;
        int v428 = (v323 * 2) + 1;
        v329[v428] = v326;
        ;
      } else {
        ;
      }
      int * v334 = v275->mem;
      int v433 = ((int)((unsigned int)((int)((unsigned int)v279 >> 2)) >> 1)) * 2;
      int v335 = v334[v433];
      int v434 = (((int)((unsigned int)((int)((unsigned int)v279 >> 2)) >> 1)) * 2) + 1;
      int v336 = v334[v434];
      int * v337 = v275->cache_vals;
      int v436 = ((4 + ((((int)((unsigned int)((int)((unsigned int)v279 >> 2)) >> 1)) & 3) * 2)) + ((((v315 + ((~(((v317 ^ -1) | (-(v317 ^ -1))) >> 31)) & 2)) - (v318 + ((~(((v319 ^ -1) | (-(v319 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
      v337[v436] = v335;
      int * v339 = v275->cache_vals;
      int v439 = (((4 + ((((int)((unsigned int)((int)((unsigned int)v279 >> 2)) >> 1)) & 3) * 2)) + ((((v315 + ((~(((v317 ^ -1) | (-(v317 ^ -1))) >> 31)) & 2)) - (v318 + ((~(((v319 ^ -1) | (-(v319 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
      v339[v439] = v336;
      int * v341 = v275->cache_tags;
      int v442 = (int)((unsigned int)((int)((unsigned int)v279 >> 2)) >> 1);
      v341[v418] = v442;
      int * v343 = v275->cache_dirty;
      v343[v418] = 0;
      int * v345 = v275->cache_age;
      v345[v418] = 1;
      int * v347 = v275->cache_age;
      int v348 = v347[v418];
      int v349 = v347[v392];
      int v448 = v349 + ((int)((unsigned int)(v349 - v348) >> 31));
      v347[v392] = v448;
      int * v351 = v275->cache_age;
      int v352 = v351[v393];
      int v450 = v352 + ((int)((unsigned int)(v352 - v348) >> 31));
      v351[v393] = v450;
      int * v354 = v275->cache_age;
      v354[v418] = 0;
      v357 = v418;
    }
    int * v358 = v275->cache_vals;
    int v453 = v357 * 2;
    int v359 = v358[v453];
    int v454 = (v357 * 2) + 1;
    int v360 = v358[v454];
    int v455 = (((((int)((unsigned int)((int)((unsigned int)v279 >> 2)) >> 1)) & 1) * 2) + ((((v299 + ((~(((v301 ^ -1) | (-(v301 ^ -1))) >> 31)) & 2)) - (v302 + ((~(((v303 ^ -1) | (-(v303 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
    v358[v455] = v359;
    int * v362 = v275->cache_vals;
    int v458 = ((((((int)((unsigned int)((int)((unsigned int)v279 >> 2)) >> 1)) & 1) * 2) + ((((v299 + ((~(((v301 ^ -1) | (-(v301 ^ -1))) >> 31)) & 2)) - (v302 + ((~(((v303 ^ -1) | (-(v303 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
    v362[v458] = v360;
    int * v364 = v275->cache_tags;
    int v461 = ((((int)((unsigned int)((int)((unsigned int)v279 >> 2)) >> 1)) & 1) * 2) + ((((v299 + ((~(((v301 ^ -1) | (-(v301 ^ -1))) >> 31)) & 2)) - (v302 + ((~(((v303 ^ -1) | (-(v303 ^ -1))) >> 31)) & 2))) >> 31) & 1);
    int v462 = (int)((unsigned int)((int)((unsigned int)v279 >> 2)) >> 1);
    v364[v461] = v462;
    int * v366 = v275->cache_dirty;
    v366[v461] = 0;
    int * v368 = v275->cache_age;
    v368[v461] = 1;
    int * v370 = v275->cache_age;
    int v371 = v370[v461];
    int v372 = v370[v390];
    int v468 = v372 + ((int)((unsigned int)(v372 - v371) >> 31));
    v370[v390] = v468;
    int * v374 = v275->cache_age;
    int v375 = v374[v391];
    int v470 = v375 + ((int)((unsigned int)(v375 - v371) >> 31));
    v374[v391] = v470;
    int * v377 = v275->cache_age;
    v377[v461] = 0;
    v380 = v461;
  }
  int v473 = (v380 * 2) + (((int)((unsigned int)v279 >> 2)) & 1);
  int v381 = v287[v473];
  int * v382 = v275->regs;
  v382[11] = v381;
  struct StateT * v384 = slot_7(v275);
  return v384;
}

struct StateT * slot_16(struct StateT * v581) {
  int v582 = v581->timer;
  int v590 = v582 + 1;
  v581->timer = v590;
  int * v584 = v581->regs;
  int v585 = v584[11];
  int v586 = v584[10];
  int v594 = v585 + v586;
  v584[10] = v594;
  struct StateT * v588 = slot_17(v581);
  return v588;
}

struct StateT * slot_5(struct StateT * v72) {
  int v73 = v72->timer;
  int v183 = v73 + 1;
  v72->timer = v183;
  int * v75 = v72->regs;
  int v76 = v75[10];
  int * v77 = v72->cache_tags;
  int v187 = (((int)((unsigned int)((int)((unsigned int)v76 >> 2)) >> 1)) & 1) * 2;
  int v78 = v77[v187];
  int v188 = ((((int)((unsigned int)((int)((unsigned int)v76 >> 2)) >> 1)) & 1) * 2) + 1;
  int v79 = v77[v188];
  int v189 = 4 + ((((int)((unsigned int)((int)((unsigned int)v76 >> 2)) >> 1)) & 3) * 2);
  int v80 = v77[v189];
  int v190 = (4 + ((((int)((unsigned int)((int)((unsigned int)v76 >> 2)) >> 1)) & 3) * 2)) + 1;
  int v81 = v77[v190];
  int v82 = v72->timer;
  int v191 = v82 + ((100 ^ (((~(((v80 ^ ((int)((unsigned int)((int)((unsigned int)v76 >> 2)) >> 1))) | (-(v80 ^ ((int)((unsigned int)((int)((unsigned int)v76 >> 2)) >> 1))))) >> 31)) | (~(((v81 ^ ((int)((unsigned int)((int)((unsigned int)v76 >> 2)) >> 1))) | (-(v81 ^ ((int)((unsigned int)((int)((unsigned int)v76 >> 2)) >> 1))))) >> 31))) & 104)) ^ (((~(((v78 ^ ((int)((unsigned int)((int)((unsigned int)v76 >> 2)) >> 1))) | (-(v78 ^ ((int)((unsigned int)((int)((unsigned int)v76 >> 2)) >> 1))))) >> 31)) | (~(((v79 ^ ((int)((unsigned int)((int)((unsigned int)v76 >> 2)) >> 1))) | (-(v79 ^ ((int)((unsigned int)((int)((unsigned int)v76 >> 2)) >> 1))))) >> 31))) & (1 ^ (100 ^ (((~(((v80 ^ ((int)((unsigned int)((int)((unsigned int)v76 >> 2)) >> 1))) | (-(v80 ^ ((int)((unsigned int)((int)((unsigned int)v76 >> 2)) >> 1))))) >> 31)) | (~(((v81 ^ ((int)((unsigned int)((int)((unsigned int)v76 >> 2)) >> 1))) | (-(v81 ^ ((int)((unsigned int)((int)((unsigned int)v76 >> 2)) >> 1))))) >> 31))) & 104)))));
  v72->timer = v191;
  int * v84 = v72->cache_vals;
  bool v192 = !(((~(((v78 ^ ((int)((unsigned int)((int)((unsigned int)v76 >> 2)) >> 1))) | (-(v78 ^ ((int)((unsigned int)((int)((unsigned int)v76 >> 2)) >> 1))))) >> 31)) | (~(((v79 ^ ((int)((unsigned int)((int)((unsigned int)v76 >> 2)) >> 1))) | (-(v79 ^ ((int)((unsigned int)((int)((unsigned int)v76 >> 2)) >> 1))))) >> 31))) == 0);
  int v177;
  if (v192) {
    int * v85 = v72->cache_age;
    int v194 = ((((int)((unsigned int)((int)((unsigned int)v76 >> 2)) >> 1)) & 1) * 2) + ((~(((v79 ^ ((int)((unsigned int)((int)((unsigned int)v76 >> 2)) >> 1))) | (-(v79 ^ ((int)((unsigned int)((int)((unsigned int)v76 >> 2)) >> 1))))) >> 31)) & 1);
    int v86 = v85[v194];
    int v87 = v85[v187];
    int v195 = v87 + ((int)((unsigned int)(v87 - v86) >> 31));
    v85[v187] = v195;
    int * v89 = v72->cache_age;
    int v90 = v89[v188];
    int v197 = v90 + ((int)((unsigned int)(v90 - v86) >> 31));
    v89[v188] = v197;
    int * v92 = v72->cache_age;
    v92[v194] = 0;
    v177 = v194;
  } else {
    int * v95 = v72->cache_age;
    int v201 = (((int)((unsigned int)((int)((unsigned int)v76 >> 2)) >> 1)) & 1) * 2;
    int v96 = v95[v201];
    int * v97 = v72->cache_tags;
    int v98 = v97[v201];
    int v99 = v95[v188];
    int v100 = v97[v188];
    bool v203 = !(((~(((v80 ^ ((int)((unsigned int)((int)((unsigned int)v76 >> 2)) >> 1))) | (-(v80 ^ ((int)((unsigned int)((int)((unsigned int)v76 >> 2)) >> 1))))) >> 31)) | (~(((v81 ^ ((int)((unsigned int)((int)((unsigned int)v76 >> 2)) >> 1))) | (-(v81 ^ ((int)((unsigned int)((int)((unsigned int)v76 >> 2)) >> 1))))) >> 31))) == 0);
    int v154;
    if (v203) {
      int * v101 = v72->cache_age;
      int v205 = (4 + ((((int)((unsigned int)((int)((unsigned int)v76 >> 2)) >> 1)) & 3) * 2)) + ((~(((v81 ^ ((int)((unsigned int)((int)((unsigned int)v76 >> 2)) >> 1))) | (-(v81 ^ ((int)((unsigned int)((int)((unsigned int)v76 >> 2)) >> 1))))) >> 31)) & 1);
      int v102 = v101[v205];
      int v103 = v101[v189];
      int v206 = v103 + ((int)((unsigned int)(v103 - v102) >> 31));
      v101[v189] = v206;
      int * v105 = v72->cache_age;
      int v106 = v105[v190];
      int v208 = v106 + ((int)((unsigned int)(v106 - v102) >> 31));
      v105[v190] = v208;
      int * v108 = v72->cache_age;
      v108[v205] = 0;
      v154 = v205;
    } else {
      int * v111 = v72->cache_age;
      int v212 = 4 + ((((int)((unsigned int)((int)((unsigned int)v76 >> 2)) >> 1)) & 3) * 2);
      int v112 = v111[v212];
      int * v113 = v72->cache_tags;
      int v114 = v113[v212];
      int v115 = v111[v190];
      int v116 = v113[v190];
      int * v117 = v72->cache_dirty;
      int v215 = (4 + ((((int)((unsigned int)((int)((unsigned int)v76 >> 2)) >> 1)) & 3) * 2)) + ((((v112 + ((~(((v114 ^ -1) | (-(v114 ^ -1))) >> 31)) & 2)) - (v115 + ((~(((v116 ^ -1) | (-(v116 ^ -1))) >> 31)) & 2))) >> 31) & 1);
      int v118 = v117[v215];
      bool v216 = !(v118 == 0);
      if (v216) {
        int * v119 = v72->cache_tags;
        int v120 = v119[v215];
        int * v121 = v72->cache_vals;
        int v219 = ((4 + ((((int)((unsigned int)((int)((unsigned int)v76 >> 2)) >> 1)) & 3) * 2)) + ((((v112 + ((~(((v114 ^ -1) | (-(v114 ^ -1))) >> 31)) & 2)) - (v115 + ((~(((v116 ^ -1) | (-(v116 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
        int v122 = v121[v219];
        int v220 = (((4 + ((((int)((unsigned int)((int)((unsigned int)v76 >> 2)) >> 1)) & 3) * 2)) + ((((v112 + ((~(((v114 ^ -1) | (-(v114 ^ -1))) >> 31)) & 2)) - (v115 + ((~(((v116 ^ -1) | (-(v116 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
        int v123 = v121[v220];
        int * v124 = v72->mem;
        int v222 = v120 * 2;
        v124[v222] = v122;
        int * v126 = v72->mem;
        int v225 = (v120 * 2) + 1;
        v126[v225] = v123;
        ;
      } else {
        ;
      }
      int * v131 = v72->mem;
      int v230 = ((int)((unsigned int)((int)((unsigned int)v76 >> 2)) >> 1)) * 2;
      int v132 = v131[v230];
      int v231 = (((int)((unsigned int)((int)((unsigned int)v76 >> 2)) >> 1)) * 2) + 1;
      int v133 = v131[v231];
      int * v134 = v72->cache_vals;
      int v233 = ((4 + ((((int)((unsigned int)((int)((unsigned int)v76 >> 2)) >> 1)) & 3) * 2)) + ((((v112 + ((~(((v114 ^ -1) | (-(v114 ^ -1))) >> 31)) & 2)) - (v115 + ((~(((v116 ^ -1) | (-(v116 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
      v134[v233] = v132;
      int * v136 = v72->cache_vals;
      int v236 = (((4 + ((((int)((unsigned int)((int)((unsigned int)v76 >> 2)) >> 1)) & 3) * 2)) + ((((v112 + ((~(((v114 ^ -1) | (-(v114 ^ -1))) >> 31)) & 2)) - (v115 + ((~(((v116 ^ -1) | (-(v116 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
      v136[v236] = v133;
      int * v138 = v72->cache_tags;
      int v239 = (int)((unsigned int)((int)((unsigned int)v76 >> 2)) >> 1);
      v138[v215] = v239;
      int * v140 = v72->cache_dirty;
      v140[v215] = 0;
      int * v142 = v72->cache_age;
      v142[v215] = 1;
      int * v144 = v72->cache_age;
      int v145 = v144[v215];
      int v146 = v144[v189];
      int v245 = v146 + ((int)((unsigned int)(v146 - v145) >> 31));
      v144[v189] = v245;
      int * v148 = v72->cache_age;
      int v149 = v148[v190];
      int v247 = v149 + ((int)((unsigned int)(v149 - v145) >> 31));
      v148[v190] = v247;
      int * v151 = v72->cache_age;
      v151[v215] = 0;
      v154 = v215;
    }
    int * v155 = v72->cache_vals;
    int v250 = v154 * 2;
    int v156 = v155[v250];
    int v251 = (v154 * 2) + 1;
    int v157 = v155[v251];
    int v252 = (((((int)((unsigned int)((int)((unsigned int)v76 >> 2)) >> 1)) & 1) * 2) + ((((v96 + ((~(((v98 ^ -1) | (-(v98 ^ -1))) >> 31)) & 2)) - (v99 + ((~(((v100 ^ -1) | (-(v100 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
    v155[v252] = v156;
    int * v159 = v72->cache_vals;
    int v255 = ((((((int)((unsigned int)((int)((unsigned int)v76 >> 2)) >> 1)) & 1) * 2) + ((((v96 + ((~(((v98 ^ -1) | (-(v98 ^ -1))) >> 31)) & 2)) - (v99 + ((~(((v100 ^ -1) | (-(v100 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
    v159[v255] = v157;
    int * v161 = v72->cache_tags;
    int v258 = ((((int)((unsigned int)((int)((unsigned int)v76 >> 2)) >> 1)) & 1) * 2) + ((((v96 + ((~(((v98 ^ -1) | (-(v98 ^ -1))) >> 31)) & 2)) - (v99 + ((~(((v100 ^ -1) | (-(v100 ^ -1))) >> 31)) & 2))) >> 31) & 1);
    int v259 = (int)((unsigned int)((int)((unsigned int)v76 >> 2)) >> 1);
    v161[v258] = v259;
    int * v163 = v72->cache_dirty;
    v163[v258] = 0;
    int * v165 = v72->cache_age;
    v165[v258] = 1;
    int * v167 = v72->cache_age;
    int v168 = v167[v258];
    int v169 = v167[v187];
    int v265 = v169 + ((int)((unsigned int)(v169 - v168) >> 31));
    v167[v187] = v265;
    int * v171 = v72->cache_age;
    int v172 = v171[v188];
    int v267 = v172 + ((int)((unsigned int)(v172 - v168) >> 31));
    v171[v188] = v267;
    int * v174 = v72->cache_age;
    v174[v258] = 0;
    v177 = v258;
  }
  int v270 = (v177 * 2) + (((int)((unsigned int)v76 >> 2)) & 1);
  int v178 = v84[v270];
  int * v179 = v72->regs;
  v179[10] = v178;
  struct StateT * v181 = slot_6(v72);
  return v181;
}

struct StateT * slot_17(struct StateT * v597) {
  int v598 = v597->timer;
  int v708 = v598 + 1;
  v597->timer = v708;
  int * v600 = v597->regs;
  int v601 = v600[10];
  int * v602 = v597->cache_tags;
  int v712 = (((int)((unsigned int)((int)((unsigned int)v601 >> 2)) >> 1)) & 1) * 2;
  int v603 = v602[v712];
  int v713 = ((((int)((unsigned int)((int)((unsigned int)v601 >> 2)) >> 1)) & 1) * 2) + 1;
  int v604 = v602[v713];
  int v714 = 4 + ((((int)((unsigned int)((int)((unsigned int)v601 >> 2)) >> 1)) & 3) * 2);
  int v605 = v602[v714];
  int v715 = (4 + ((((int)((unsigned int)((int)((unsigned int)v601 >> 2)) >> 1)) & 3) * 2)) + 1;
  int v606 = v602[v715];
  int v607 = v597->timer;
  int v716 = v607 + ((100 ^ (((~(((v605 ^ ((int)((unsigned int)((int)((unsigned int)v601 >> 2)) >> 1))) | (-(v605 ^ ((int)((unsigned int)((int)((unsigned int)v601 >> 2)) >> 1))))) >> 31)) | (~(((v606 ^ ((int)((unsigned int)((int)((unsigned int)v601 >> 2)) >> 1))) | (-(v606 ^ ((int)((unsigned int)((int)((unsigned int)v601 >> 2)) >> 1))))) >> 31))) & 104)) ^ (((~(((v603 ^ ((int)((unsigned int)((int)((unsigned int)v601 >> 2)) >> 1))) | (-(v603 ^ ((int)((unsigned int)((int)((unsigned int)v601 >> 2)) >> 1))))) >> 31)) | (~(((v604 ^ ((int)((unsigned int)((int)((unsigned int)v601 >> 2)) >> 1))) | (-(v604 ^ ((int)((unsigned int)((int)((unsigned int)v601 >> 2)) >> 1))))) >> 31))) & (1 ^ (100 ^ (((~(((v605 ^ ((int)((unsigned int)((int)((unsigned int)v601 >> 2)) >> 1))) | (-(v605 ^ ((int)((unsigned int)((int)((unsigned int)v601 >> 2)) >> 1))))) >> 31)) | (~(((v606 ^ ((int)((unsigned int)((int)((unsigned int)v601 >> 2)) >> 1))) | (-(v606 ^ ((int)((unsigned int)((int)((unsigned int)v601 >> 2)) >> 1))))) >> 31))) & 104)))));
  v597->timer = v716;
  int * v609 = v597->cache_vals;
  bool v717 = !(((~(((v603 ^ ((int)((unsigned int)((int)((unsigned int)v601 >> 2)) >> 1))) | (-(v603 ^ ((int)((unsigned int)((int)((unsigned int)v601 >> 2)) >> 1))))) >> 31)) | (~(((v604 ^ ((int)((unsigned int)((int)((unsigned int)v601 >> 2)) >> 1))) | (-(v604 ^ ((int)((unsigned int)((int)((unsigned int)v601 >> 2)) >> 1))))) >> 31))) == 0);
  int v702;
  if (v717) {
    int * v610 = v597->cache_age;
    int v719 = ((((int)((unsigned int)((int)((unsigned int)v601 >> 2)) >> 1)) & 1) * 2) + ((~(((v604 ^ ((int)((unsigned int)((int)((unsigned int)v601 >> 2)) >> 1))) | (-(v604 ^ ((int)((unsigned int)((int)((unsigned int)v601 >> 2)) >> 1))))) >> 31)) & 1);
    int v611 = v610[v719];
    int v612 = v610[v712];
    int v720 = v612 + ((int)((unsigned int)(v612 - v611) >> 31));
    v610[v712] = v720;
    int * v614 = v597->cache_age;
    int v615 = v614[v713];
    int v722 = v615 + ((int)((unsigned int)(v615 - v611) >> 31));
    v614[v713] = v722;
    int * v617 = v597->cache_age;
    v617[v719] = 0;
    v702 = v719;
  } else {
    int * v620 = v597->cache_age;
    int v726 = (((int)((unsigned int)((int)((unsigned int)v601 >> 2)) >> 1)) & 1) * 2;
    int v621 = v620[v726];
    int * v622 = v597->cache_tags;
    int v623 = v622[v726];
    int v624 = v620[v713];
    int v625 = v622[v713];
    bool v728 = !(((~(((v605 ^ ((int)((unsigned int)((int)((unsigned int)v601 >> 2)) >> 1))) | (-(v605 ^ ((int)((unsigned int)((int)((unsigned int)v601 >> 2)) >> 1))))) >> 31)) | (~(((v606 ^ ((int)((unsigned int)((int)((unsigned int)v601 >> 2)) >> 1))) | (-(v606 ^ ((int)((unsigned int)((int)((unsigned int)v601 >> 2)) >> 1))))) >> 31))) == 0);
    int v679;
    if (v728) {
      int * v626 = v597->cache_age;
      int v730 = (4 + ((((int)((unsigned int)((int)((unsigned int)v601 >> 2)) >> 1)) & 3) * 2)) + ((~(((v606 ^ ((int)((unsigned int)((int)((unsigned int)v601 >> 2)) >> 1))) | (-(v606 ^ ((int)((unsigned int)((int)((unsigned int)v601 >> 2)) >> 1))))) >> 31)) & 1);
      int v627 = v626[v730];
      int v628 = v626[v714];
      int v731 = v628 + ((int)((unsigned int)(v628 - v627) >> 31));
      v626[v714] = v731;
      int * v630 = v597->cache_age;
      int v631 = v630[v715];
      int v733 = v631 + ((int)((unsigned int)(v631 - v627) >> 31));
      v630[v715] = v733;
      int * v633 = v597->cache_age;
      v633[v730] = 0;
      v679 = v730;
    } else {
      int * v636 = v597->cache_age;
      int v737 = 4 + ((((int)((unsigned int)((int)((unsigned int)v601 >> 2)) >> 1)) & 3) * 2);
      int v637 = v636[v737];
      int * v638 = v597->cache_tags;
      int v639 = v638[v737];
      int v640 = v636[v715];
      int v641 = v638[v715];
      int * v642 = v597->cache_dirty;
      int v740 = (4 + ((((int)((unsigned int)((int)((unsigned int)v601 >> 2)) >> 1)) & 3) * 2)) + ((((v637 + ((~(((v639 ^ -1) | (-(v639 ^ -1))) >> 31)) & 2)) - (v640 + ((~(((v641 ^ -1) | (-(v641 ^ -1))) >> 31)) & 2))) >> 31) & 1);
      int v643 = v642[v740];
      bool v741 = !(v643 == 0);
      if (v741) {
        int * v644 = v597->cache_tags;
        int v645 = v644[v740];
        int * v646 = v597->cache_vals;
        int v744 = ((4 + ((((int)((unsigned int)((int)((unsigned int)v601 >> 2)) >> 1)) & 3) * 2)) + ((((v637 + ((~(((v639 ^ -1) | (-(v639 ^ -1))) >> 31)) & 2)) - (v640 + ((~(((v641 ^ -1) | (-(v641 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
        int v647 = v646[v744];
        int v745 = (((4 + ((((int)((unsigned int)((int)((unsigned int)v601 >> 2)) >> 1)) & 3) * 2)) + ((((v637 + ((~(((v639 ^ -1) | (-(v639 ^ -1))) >> 31)) & 2)) - (v640 + ((~(((v641 ^ -1) | (-(v641 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
        int v648 = v646[v745];
        int * v649 = v597->mem;
        int v747 = v645 * 2;
        v649[v747] = v647;
        int * v651 = v597->mem;
        int v750 = (v645 * 2) + 1;
        v651[v750] = v648;
        ;
      } else {
        ;
      }
      int * v656 = v597->mem;
      int v755 = ((int)((unsigned int)((int)((unsigned int)v601 >> 2)) >> 1)) * 2;
      int v657 = v656[v755];
      int v756 = (((int)((unsigned int)((int)((unsigned int)v601 >> 2)) >> 1)) * 2) + 1;
      int v658 = v656[v756];
      int * v659 = v597->cache_vals;
      int v758 = ((4 + ((((int)((unsigned int)((int)((unsigned int)v601 >> 2)) >> 1)) & 3) * 2)) + ((((v637 + ((~(((v639 ^ -1) | (-(v639 ^ -1))) >> 31)) & 2)) - (v640 + ((~(((v641 ^ -1) | (-(v641 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
      v659[v758] = v657;
      int * v661 = v597->cache_vals;
      int v761 = (((4 + ((((int)((unsigned int)((int)((unsigned int)v601 >> 2)) >> 1)) & 3) * 2)) + ((((v637 + ((~(((v639 ^ -1) | (-(v639 ^ -1))) >> 31)) & 2)) - (v640 + ((~(((v641 ^ -1) | (-(v641 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
      v661[v761] = v658;
      int * v663 = v597->cache_tags;
      int v764 = (int)((unsigned int)((int)((unsigned int)v601 >> 2)) >> 1);
      v663[v740] = v764;
      int * v665 = v597->cache_dirty;
      v665[v740] = 0;
      int * v667 = v597->cache_age;
      v667[v740] = 1;
      int * v669 = v597->cache_age;
      int v670 = v669[v740];
      int v671 = v669[v714];
      int v770 = v671 + ((int)((unsigned int)(v671 - v670) >> 31));
      v669[v714] = v770;
      int * v673 = v597->cache_age;
      int v674 = v673[v715];
      int v772 = v674 + ((int)((unsigned int)(v674 - v670) >> 31));
      v673[v715] = v772;
      int * v676 = v597->cache_age;
      v676[v740] = 0;
      v679 = v740;
    }
    int * v680 = v597->cache_vals;
    int v775 = v679 * 2;
    int v681 = v680[v775];
    int v776 = (v679 * 2) + 1;
    int v682 = v680[v776];
    int v777 = (((((int)((unsigned int)((int)((unsigned int)v601 >> 2)) >> 1)) & 1) * 2) + ((((v621 + ((~(((v623 ^ -1) | (-(v623 ^ -1))) >> 31)) & 2)) - (v624 + ((~(((v625 ^ -1) | (-(v625 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
    v680[v777] = v681;
    int * v684 = v597->cache_vals;
    int v780 = ((((((int)((unsigned int)((int)((unsigned int)v601 >> 2)) >> 1)) & 1) * 2) + ((((v621 + ((~(((v623 ^ -1) | (-(v623 ^ -1))) >> 31)) & 2)) - (v624 + ((~(((v625 ^ -1) | (-(v625 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
    v684[v780] = v682;
    int * v686 = v597->cache_tags;
    int v783 = ((((int)((unsigned int)((int)((unsigned int)v601 >> 2)) >> 1)) & 1) * 2) + ((((v621 + ((~(((v623 ^ -1) | (-(v623 ^ -1))) >> 31)) & 2)) - (v624 + ((~(((v625 ^ -1) | (-(v625 ^ -1))) >> 31)) & 2))) >> 31) & 1);
    int v784 = (int)((unsigned int)((int)((unsigned int)v601 >> 2)) >> 1);
    v686[v783] = v784;
    int * v688 = v597->cache_dirty;
    v688[v783] = 0;
    int * v690 = v597->cache_age;
    v690[v783] = 1;
    int * v692 = v597->cache_age;
    int v693 = v692[v783];
    int v694 = v692[v712];
    int v790 = v694 + ((int)((unsigned int)(v694 - v693) >> 31));
    v692[v712] = v790;
    int * v696 = v597->cache_age;
    int v697 = v696[v713];
    int v792 = v697 + ((int)((unsigned int)(v697 - v693) >> 31));
    v696[v713] = v792;
    int * v699 = v597->cache_age;
    v699[v783] = 0;
    v702 = v783;
  }
  int v795 = (v702 * 2) + (((int)((unsigned int)v601 >> 2)) & 1);
  int v703 = v609[v795];
  int * v704 = v597->regs;
  v704[10] = v703;
  struct StateT * v706 = slot_18(v597);
  return v706;
}

struct StateT * slot_20(struct StateT * v1020) {
  int v1021 = v1020->timer;
  int v1191 = v1021 + 1;
  v1020->timer = v1191;
  int * v1023 = v1020->regs;
  int v1024 = v1023[12];
  int v1025 = v1023[10];
  int * v1026 = v1020->cache_tags;
  int v1196 = (((int)((unsigned int)((int)((unsigned int)(v1024 + 68) >> 2)) >> 1)) & 1) * 2;
  int v1027 = v1026[v1196];
  int v1197 = ((((int)((unsigned int)((int)((unsigned int)(v1024 + 68) >> 2)) >> 1)) & 1) * 2) + 1;
  int v1028 = v1026[v1197];
  int v1198 = 4 + ((((int)((unsigned int)((int)((unsigned int)(v1024 + 68) >> 2)) >> 1)) & 3) * 2);
  int v1029 = v1026[v1198];
  int v1199 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v1024 + 68) >> 2)) >> 1)) & 3) * 2)) + 1;
  int v1030 = v1026[v1199];
  int v1031 = v1020->timer;
  int v1200 = v1031 + ((100 ^ (((~(((v1029 ^ ((int)((unsigned int)((int)((unsigned int)(v1024 + 68) >> 2)) >> 1))) | (-(v1029 ^ ((int)((unsigned int)((int)((unsigned int)(v1024 + 68) >> 2)) >> 1))))) >> 31)) | (~(((v1030 ^ ((int)((unsigned int)((int)((unsigned int)(v1024 + 68) >> 2)) >> 1))) | (-(v1030 ^ ((int)((unsigned int)((int)((unsigned int)(v1024 + 68) >> 2)) >> 1))))) >> 31))) & 104)) ^ (((~(((v1027 ^ ((int)((unsigned int)((int)((unsigned int)(v1024 + 68) >> 2)) >> 1))) | (-(v1027 ^ ((int)((unsigned int)((int)((unsigned int)(v1024 + 68) >> 2)) >> 1))))) >> 31)) | (~(((v1028 ^ ((int)((unsigned int)((int)((unsigned int)(v1024 + 68) >> 2)) >> 1))) | (-(v1028 ^ ((int)((unsigned int)((int)((unsigned int)(v1024 + 68) >> 2)) >> 1))))) >> 31))) & (1 ^ (100 ^ (((~(((v1029 ^ ((int)((unsigned int)((int)((unsigned int)(v1024 + 68) >> 2)) >> 1))) | (-(v1029 ^ ((int)((unsigned int)((int)((unsigned int)(v1024 + 68) >> 2)) >> 1))))) >> 31)) | (~(((v1030 ^ ((int)((unsigned int)((int)((unsigned int)(v1024 + 68) >> 2)) >> 1))) | (-(v1030 ^ ((int)((unsigned int)((int)((unsigned int)(v1024 + 68) >> 2)) >> 1))))) >> 31))) & 104)))));
  v1020->timer = v1200;
  bool v1201 = !(((~(((v1027 ^ ((int)((unsigned int)((int)((unsigned int)(v1024 + 68) >> 2)) >> 1))) | (-(v1027 ^ ((int)((unsigned int)((int)((unsigned int)(v1024 + 68) >> 2)) >> 1))))) >> 31)) | (~(((v1028 ^ ((int)((unsigned int)((int)((unsigned int)(v1024 + 68) >> 2)) >> 1))) | (-(v1028 ^ ((int)((unsigned int)((int)((unsigned int)(v1024 + 68) >> 2)) >> 1))))) >> 31))) == 0);
  int v1125;
  if (v1201) {
    int * v1033 = v1020->cache_age;
    int v1203 = ((((int)((unsigned int)((int)((unsigned int)(v1024 + 68) >> 2)) >> 1)) & 1) * 2) + ((~(((v1028 ^ ((int)((unsigned int)((int)((unsigned int)(v1024 + 68) >> 2)) >> 1))) | (-(v1028 ^ ((int)((unsigned int)((int)((unsigned int)(v1024 + 68) >> 2)) >> 1))))) >> 31)) & 1);
    int v1034 = v1033[v1203];
    int v1035 = v1033[v1196];
    int v1204 = v1035 + ((int)((unsigned int)(v1035 - v1034) >> 31));
    v1033[v1196] = v1204;
    int * v1037 = v1020->cache_age;
    int v1038 = v1037[v1197];
    int v1206 = v1038 + ((int)((unsigned int)(v1038 - v1034) >> 31));
    v1037[v1197] = v1206;
    int * v1040 = v1020->cache_age;
    v1040[v1203] = 0;
    v1125 = v1203;
  } else {
    int * v1043 = v1020->cache_age;
    int v1210 = (((int)((unsigned int)((int)((unsigned int)(v1024 + 68) >> 2)) >> 1)) & 1) * 2;
    int v1044 = v1043[v1210];
    int * v1045 = v1020->cache_tags;
    int v1046 = v1045[v1210];
    int v1047 = v1043[v1197];
    int v1048 = v1045[v1197];
    bool v1212 = !(((~(((v1029 ^ ((int)((unsigned int)((int)((unsigned int)(v1024 + 68) >> 2)) >> 1))) | (-(v1029 ^ ((int)((unsigned int)((int)((unsigned int)(v1024 + 68) >> 2)) >> 1))))) >> 31)) | (~(((v1030 ^ ((int)((unsigned int)((int)((unsigned int)(v1024 + 68) >> 2)) >> 1))) | (-(v1030 ^ ((int)((unsigned int)((int)((unsigned int)(v1024 + 68) >> 2)) >> 1))))) >> 31))) == 0);
    int v1102;
    if (v1212) {
      int * v1049 = v1020->cache_age;
      int v1214 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v1024 + 68) >> 2)) >> 1)) & 3) * 2)) + ((~(((v1030 ^ ((int)((unsigned int)((int)((unsigned int)(v1024 + 68) >> 2)) >> 1))) | (-(v1030 ^ ((int)((unsigned int)((int)((unsigned int)(v1024 + 68) >> 2)) >> 1))))) >> 31)) & 1);
      int v1050 = v1049[v1214];
      int v1051 = v1049[v1198];
      int v1215 = v1051 + ((int)((unsigned int)(v1051 - v1050) >> 31));
      v1049[v1198] = v1215;
      int * v1053 = v1020->cache_age;
      int v1054 = v1053[v1199];
      int v1217 = v1054 + ((int)((unsigned int)(v1054 - v1050) >> 31));
      v1053[v1199] = v1217;
      int * v1056 = v1020->cache_age;
      v1056[v1214] = 0;
      v1102 = v1214;
    } else {
      int * v1059 = v1020->cache_age;
      int v1221 = 4 + ((((int)((unsigned int)((int)((unsigned int)(v1024 + 68) >> 2)) >> 1)) & 3) * 2);
      int v1060 = v1059[v1221];
      int * v1061 = v1020->cache_tags;
      int v1062 = v1061[v1221];
      int v1063 = v1059[v1199];
      int v1064 = v1061[v1199];
      int * v1065 = v1020->cache_dirty;
      int v1224 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v1024 + 68) >> 2)) >> 1)) & 3) * 2)) + ((((v1060 + ((~(((v1062 ^ -1) | (-(v1062 ^ -1))) >> 31)) & 2)) - (v1063 + ((~(((v1064 ^ -1) | (-(v1064 ^ -1))) >> 31)) & 2))) >> 31) & 1);
      int v1066 = v1065[v1224];
      bool v1225 = !(v1066 == 0);
      if (v1225) {
        int * v1067 = v1020->cache_tags;
        int v1068 = v1067[v1224];
        int * v1069 = v1020->cache_vals;
        int v1228 = ((4 + ((((int)((unsigned int)((int)((unsigned int)(v1024 + 68) >> 2)) >> 1)) & 3) * 2)) + ((((v1060 + ((~(((v1062 ^ -1) | (-(v1062 ^ -1))) >> 31)) & 2)) - (v1063 + ((~(((v1064 ^ -1) | (-(v1064 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
        int v1070 = v1069[v1228];
        int v1229 = (((4 + ((((int)((unsigned int)((int)((unsigned int)(v1024 + 68) >> 2)) >> 1)) & 3) * 2)) + ((((v1060 + ((~(((v1062 ^ -1) | (-(v1062 ^ -1))) >> 31)) & 2)) - (v1063 + ((~(((v1064 ^ -1) | (-(v1064 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
        int v1071 = v1069[v1229];
        int * v1072 = v1020->mem;
        int v1231 = v1068 * 2;
        v1072[v1231] = v1070;
        int * v1074 = v1020->mem;
        int v1234 = (v1068 * 2) + 1;
        v1074[v1234] = v1071;
        ;
      } else {
        ;
      }
      int * v1079 = v1020->mem;
      int v1239 = ((int)((unsigned int)((int)((unsigned int)(v1024 + 68) >> 2)) >> 1)) * 2;
      int v1080 = v1079[v1239];
      int v1240 = (((int)((unsigned int)((int)((unsigned int)(v1024 + 68) >> 2)) >> 1)) * 2) + 1;
      int v1081 = v1079[v1240];
      int * v1082 = v1020->cache_vals;
      int v1242 = ((4 + ((((int)((unsigned int)((int)((unsigned int)(v1024 + 68) >> 2)) >> 1)) & 3) * 2)) + ((((v1060 + ((~(((v1062 ^ -1) | (-(v1062 ^ -1))) >> 31)) & 2)) - (v1063 + ((~(((v1064 ^ -1) | (-(v1064 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
      v1082[v1242] = v1080;
      int * v1084 = v1020->cache_vals;
      int v1245 = (((4 + ((((int)((unsigned int)((int)((unsigned int)(v1024 + 68) >> 2)) >> 1)) & 3) * 2)) + ((((v1060 + ((~(((v1062 ^ -1) | (-(v1062 ^ -1))) >> 31)) & 2)) - (v1063 + ((~(((v1064 ^ -1) | (-(v1064 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
      v1084[v1245] = v1081;
      int * v1086 = v1020->cache_tags;
      int v1248 = (int)((unsigned int)((int)((unsigned int)(v1024 + 68) >> 2)) >> 1);
      v1086[v1224] = v1248;
      int * v1088 = v1020->cache_dirty;
      v1088[v1224] = 0;
      int * v1090 = v1020->cache_age;
      v1090[v1224] = 1;
      int * v1092 = v1020->cache_age;
      int v1093 = v1092[v1224];
      int v1094 = v1092[v1198];
      int v1254 = v1094 + ((int)((unsigned int)(v1094 - v1093) >> 31));
      v1092[v1198] = v1254;
      int * v1096 = v1020->cache_age;
      int v1097 = v1096[v1199];
      int v1256 = v1097 + ((int)((unsigned int)(v1097 - v1093) >> 31));
      v1096[v1199] = v1256;
      int * v1099 = v1020->cache_age;
      v1099[v1224] = 0;
      v1102 = v1224;
    }
    int * v1103 = v1020->cache_vals;
    int v1259 = v1102 * 2;
    int v1104 = v1103[v1259];
    int v1260 = (v1102 * 2) + 1;
    int v1105 = v1103[v1260];
    int v1261 = (((((int)((unsigned int)((int)((unsigned int)(v1024 + 68) >> 2)) >> 1)) & 1) * 2) + ((((v1044 + ((~(((v1046 ^ -1) | (-(v1046 ^ -1))) >> 31)) & 2)) - (v1047 + ((~(((v1048 ^ -1) | (-(v1048 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
    v1103[v1261] = v1104;
    int * v1107 = v1020->cache_vals;
    int v1264 = ((((((int)((unsigned int)((int)((unsigned int)(v1024 + 68) >> 2)) >> 1)) & 1) * 2) + ((((v1044 + ((~(((v1046 ^ -1) | (-(v1046 ^ -1))) >> 31)) & 2)) - (v1047 + ((~(((v1048 ^ -1) | (-(v1048 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
    v1107[v1264] = v1105;
    int * v1109 = v1020->cache_tags;
    int v1267 = ((((int)((unsigned int)((int)((unsigned int)(v1024 + 68) >> 2)) >> 1)) & 1) * 2) + ((((v1044 + ((~(((v1046 ^ -1) | (-(v1046 ^ -1))) >> 31)) & 2)) - (v1047 + ((~(((v1048 ^ -1) | (-(v1048 ^ -1))) >> 31)) & 2))) >> 31) & 1);
    int v1268 = (int)((unsigned int)((int)((unsigned int)(v1024 + 68) >> 2)) >> 1);
    v1109[v1267] = v1268;
    int * v1111 = v1020->cache_dirty;
    v1111[v1267] = 0;
    int * v1113 = v1020->cache_age;
    v1113[v1267] = 1;
    int * v1115 = v1020->cache_age;
    int v1116 = v1115[v1267];
    int v1117 = v1115[v1196];
    int v1274 = v1117 + ((int)((unsigned int)(v1117 - v1116) >> 31));
    v1115[v1196] = v1274;
    int * v1119 = v1020->cache_age;
    int v1120 = v1119[v1197];
    int v1276 = v1120 + ((int)((unsigned int)(v1120 - v1116) >> 31));
    v1119[v1197] = v1276;
    int * v1122 = v1020->cache_age;
    v1122[v1267] = 0;
    v1125 = v1267;
  }
  int * v1126 = v1020->cache_vals;
  int v1279 = (v1125 * 2) + (((int)((unsigned int)(v1024 + 68) >> 2)) & 1);
  v1126[v1279] = v1025;
  int * v1128 = v1020->cache_tags;
  int v1129 = v1128[v1198];
  int v1130 = v1128[v1199];
  bool v1282 = !(((~(((v1129 ^ ((int)((unsigned int)((int)((unsigned int)(v1024 + 68) >> 2)) >> 1))) | (-(v1129 ^ ((int)((unsigned int)((int)((unsigned int)(v1024 + 68) >> 2)) >> 1))))) >> 31)) | (~(((v1130 ^ ((int)((unsigned int)((int)((unsigned int)(v1024 + 68) >> 2)) >> 1))) | (-(v1130 ^ ((int)((unsigned int)((int)((unsigned int)(v1024 + 68) >> 2)) >> 1))))) >> 31))) == 0);
  int v1184;
  if (v1282) {
    int * v1131 = v1020->cache_age;
    int v1284 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v1024 + 68) >> 2)) >> 1)) & 3) * 2)) + ((~(((v1130 ^ ((int)((unsigned int)((int)((unsigned int)(v1024 + 68) >> 2)) >> 1))) | (-(v1130 ^ ((int)((unsigned int)((int)((unsigned int)(v1024 + 68) >> 2)) >> 1))))) >> 31)) & 1);
    int v1132 = v1131[v1284];
    int v1133 = v1131[v1198];
    int v1285 = v1133 + ((int)((unsigned int)(v1133 - v1132) >> 31));
    v1131[v1198] = v1285;
    int * v1135 = v1020->cache_age;
    int v1136 = v1135[v1199];
    int v1287 = v1136 + ((int)((unsigned int)(v1136 - v1132) >> 31));
    v1135[v1199] = v1287;
    int * v1138 = v1020->cache_age;
    v1138[v1284] = 0;
    v1184 = v1284;
  } else {
    int * v1141 = v1020->cache_age;
    int v1291 = 4 + ((((int)((unsigned int)((int)((unsigned int)(v1024 + 68) >> 2)) >> 1)) & 3) * 2);
    int v1142 = v1141[v1291];
    int * v1143 = v1020->cache_tags;
    int v1144 = v1143[v1291];
    int v1145 = v1141[v1199];
    int v1146 = v1143[v1199];
    int * v1147 = v1020->cache_dirty;
    int v1294 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v1024 + 68) >> 2)) >> 1)) & 3) * 2)) + ((((v1142 + ((~(((v1144 ^ -1) | (-(v1144 ^ -1))) >> 31)) & 2)) - (v1145 + ((~(((v1146 ^ -1) | (-(v1146 ^ -1))) >> 31)) & 2))) >> 31) & 1);
    int v1148 = v1147[v1294];
    bool v1295 = !(v1148 == 0);
    if (v1295) {
      int * v1149 = v1020->cache_tags;
      int v1150 = v1149[v1294];
      int * v1151 = v1020->cache_vals;
      int v1298 = ((4 + ((((int)((unsigned int)((int)((unsigned int)(v1024 + 68) >> 2)) >> 1)) & 3) * 2)) + ((((v1142 + ((~(((v1144 ^ -1) | (-(v1144 ^ -1))) >> 31)) & 2)) - (v1145 + ((~(((v1146 ^ -1) | (-(v1146 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
      int v1152 = v1151[v1298];
      int v1299 = (((4 + ((((int)((unsigned int)((int)((unsigned int)(v1024 + 68) >> 2)) >> 1)) & 3) * 2)) + ((((v1142 + ((~(((v1144 ^ -1) | (-(v1144 ^ -1))) >> 31)) & 2)) - (v1145 + ((~(((v1146 ^ -1) | (-(v1146 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
      int v1153 = v1151[v1299];
      int * v1154 = v1020->mem;
      int v1301 = v1150 * 2;
      v1154[v1301] = v1152;
      int * v1156 = v1020->mem;
      int v1304 = (v1150 * 2) + 1;
      v1156[v1304] = v1153;
      ;
    } else {
      ;
    }
    int * v1161 = v1020->mem;
    int v1309 = ((int)((unsigned int)((int)((unsigned int)(v1024 + 68) >> 2)) >> 1)) * 2;
    int v1162 = v1161[v1309];
    int v1310 = (((int)((unsigned int)((int)((unsigned int)(v1024 + 68) >> 2)) >> 1)) * 2) + 1;
    int v1163 = v1161[v1310];
    int * v1164 = v1020->cache_vals;
    int v1312 = ((4 + ((((int)((unsigned int)((int)((unsigned int)(v1024 + 68) >> 2)) >> 1)) & 3) * 2)) + ((((v1142 + ((~(((v1144 ^ -1) | (-(v1144 ^ -1))) >> 31)) & 2)) - (v1145 + ((~(((v1146 ^ -1) | (-(v1146 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
    v1164[v1312] = v1162;
    int * v1166 = v1020->cache_vals;
    int v1315 = (((4 + ((((int)((unsigned int)((int)((unsigned int)(v1024 + 68) >> 2)) >> 1)) & 3) * 2)) + ((((v1142 + ((~(((v1144 ^ -1) | (-(v1144 ^ -1))) >> 31)) & 2)) - (v1145 + ((~(((v1146 ^ -1) | (-(v1146 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
    v1166[v1315] = v1163;
    int * v1168 = v1020->cache_tags;
    int v1318 = (int)((unsigned int)((int)((unsigned int)(v1024 + 68) >> 2)) >> 1);
    v1168[v1294] = v1318;
    int * v1170 = v1020->cache_dirty;
    v1170[v1294] = 0;
    int * v1172 = v1020->cache_age;
    v1172[v1294] = 1;
    int * v1174 = v1020->cache_age;
    int v1175 = v1174[v1294];
    int v1176 = v1174[v1198];
    int v1324 = v1176 + ((int)((unsigned int)(v1176 - v1175) >> 31));
    v1174[v1198] = v1324;
    int * v1178 = v1020->cache_age;
    int v1179 = v1178[v1199];
    int v1326 = v1179 + ((int)((unsigned int)(v1179 - v1175) >> 31));
    v1178[v1199] = v1326;
    int * v1181 = v1020->cache_age;
    v1181[v1294] = 0;
    v1184 = v1294;
  }
  int * v1185 = v1020->cache_vals;
  int v1329 = (v1184 * 2) + (((int)((unsigned int)(v1024 + 68) >> 2)) & 1);
  v1185[v1329] = v1025;
  int * v1187 = v1020->cache_dirty;
  v1187[v1184] = 1;
  struct StateT * v1189 = slot_9(v1020);
  return v1189;
}

struct StateT * slot_2(struct StateT * v29) {
  int v30 = v29->timer;
  int v37 = v30 + 1;
  v29->timer = v37;
  int * v32 = v29->regs;
  int v33 = v32[11];
  int v40 = v33 + 72;
  v32[11] = v40;
  struct StateT * v35 = slot_3(v29);
  return v35;
}

struct StateT * slot_7(struct StateT * v478) {
  int v479 = v478->timer;
  int v483 = v479 + 1;
  v478->timer = v483;
  struct StateT * v481 = slot_8(v478);
  return v481;
}

struct StateT * slot_3(struct StateT * v43) {
  int v44 = v43->timer;
  int v52 = v44 + 1;
  v43->timer = v52;
  int * v46 = v43->regs;
  int v47 = v46[11];
  int v48 = v46[10];
  int v56 = v47 + v48;
  v46[10] = v56;
  struct StateT * v50 = slot_4(v43);
  return v50;
}

struct StateT * snippet(struct StateT * v0) {
  struct StateT * v1 = slot_0(v0);
  return v1;
}

struct StateT * slot_10(struct StateT * v513) {
  int v514 = v513->timer;
  int v521 = v514 + 1;
  v513->timer = v521;
  int * v516 = v513->regs;
  int v517 = v516[10];
  int v524 = v517 << 29;
  v516[10] = v524;
  struct StateT * v519 = slot_12(v513);
  return v519;
}

struct StateT * slot_1(struct StateT * v16) {
  int v17 = v16->timer;
  int v23 = v17 + 1;
  v16->timer = v23;
  int * v19 = v16->regs;
  v19[11] = 0;
  struct StateT * v21 = slot_2(v16);
  return v21;
}

struct StateT * slot_8(struct StateT * v486) {
  int * v487 = v486->regs;
  int v488 = v487[10];
  int v489 = v487[11];
  bool v501 = (v488 ^ -2147483648) >= (v489 ^ -2147483648);
  struct StateT * v496;
  if (v501) {
    int v490 = v486->timer;
    int v502 = v490 + 15;
    v486->timer = v502;
    struct StateT * v492 = slot_9(v486);
    v496 = v492;
  } else {
    struct StateT * v494 = slot_10(v486);
    v496 = v494;
  }
  return v496;
}

struct StateT * slot_19(struct StateT * v1004) {
  int v1005 = v1004->timer;
  int v1013 = v1005 + 1;
  v1004->timer = v1013;
  int * v1007 = v1004->regs;
  int v1008 = v1007[11];
  int v1009 = v1007[10];
  int v1017 = v1008 & v1009;
  v1007[10] = v1017;
  struct StateT * v1011 = slot_20(v1004);
  return v1011;
}

struct StateT * slot_4(struct StateT * v59) {
  int v60 = v59->timer;
  int v66 = v60 + 1;
  v59->timer = v66;
  int * v62 = v59->regs;
  v62[11] = 0;
  struct StateT * v64 = slot_5(v59);
  return v64;
}

struct StateT * slot_13(struct StateT * v540) {
  int v541 = v540->timer;
  int v548 = v541 + 1;
  v540->timer = v548;
  int * v543 = v540->regs;
  int v544 = v543[11];
  int v551 = v544 + 4;
  v543[11] = v551;
  struct StateT * v546 = slot_14(v540);
  return v546;
}

struct StateT * slot_15(struct StateT * v567) {
  int v568 = v567->timer;
  int v575 = v568 + 1;
  v567->timer = v575;
  int * v570 = v567->regs;
  int v571 = v570[10];
  int v578 = (int)((unsigned int)v571 >> 26);
  v570[10] = v578;
  struct StateT * v573 = slot_16(v567);
  return v573;
}

struct StateT * slot_18(struct StateT * v800) {
  int v801 = v800->timer;
  int v911 = v801 + 1;
  v800->timer = v911;
  int * v803 = v800->regs;
  int v804 = v803[12];
  int * v805 = v800->cache_tags;
  int v915 = (((int)((unsigned int)((int)((unsigned int)(v804 + 68) >> 2)) >> 1)) & 1) * 2;
  int v806 = v805[v915];
  int v916 = ((((int)((unsigned int)((int)((unsigned int)(v804 + 68) >> 2)) >> 1)) & 1) * 2) + 1;
  int v807 = v805[v916];
  int v917 = 4 + ((((int)((unsigned int)((int)((unsigned int)(v804 + 68) >> 2)) >> 1)) & 3) * 2);
  int v808 = v805[v917];
  int v918 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v804 + 68) >> 2)) >> 1)) & 3) * 2)) + 1;
  int v809 = v805[v918];
  int v810 = v800->timer;
  int v919 = v810 + ((100 ^ (((~(((v808 ^ ((int)((unsigned int)((int)((unsigned int)(v804 + 68) >> 2)) >> 1))) | (-(v808 ^ ((int)((unsigned int)((int)((unsigned int)(v804 + 68) >> 2)) >> 1))))) >> 31)) | (~(((v809 ^ ((int)((unsigned int)((int)((unsigned int)(v804 + 68) >> 2)) >> 1))) | (-(v809 ^ ((int)((unsigned int)((int)((unsigned int)(v804 + 68) >> 2)) >> 1))))) >> 31))) & 104)) ^ (((~(((v806 ^ ((int)((unsigned int)((int)((unsigned int)(v804 + 68) >> 2)) >> 1))) | (-(v806 ^ ((int)((unsigned int)((int)((unsigned int)(v804 + 68) >> 2)) >> 1))))) >> 31)) | (~(((v807 ^ ((int)((unsigned int)((int)((unsigned int)(v804 + 68) >> 2)) >> 1))) | (-(v807 ^ ((int)((unsigned int)((int)((unsigned int)(v804 + 68) >> 2)) >> 1))))) >> 31))) & (1 ^ (100 ^ (((~(((v808 ^ ((int)((unsigned int)((int)((unsigned int)(v804 + 68) >> 2)) >> 1))) | (-(v808 ^ ((int)((unsigned int)((int)((unsigned int)(v804 + 68) >> 2)) >> 1))))) >> 31)) | (~(((v809 ^ ((int)((unsigned int)((int)((unsigned int)(v804 + 68) >> 2)) >> 1))) | (-(v809 ^ ((int)((unsigned int)((int)((unsigned int)(v804 + 68) >> 2)) >> 1))))) >> 31))) & 104)))));
  v800->timer = v919;
  int * v812 = v800->cache_vals;
  bool v920 = !(((~(((v806 ^ ((int)((unsigned int)((int)((unsigned int)(v804 + 68) >> 2)) >> 1))) | (-(v806 ^ ((int)((unsigned int)((int)((unsigned int)(v804 + 68) >> 2)) >> 1))))) >> 31)) | (~(((v807 ^ ((int)((unsigned int)((int)((unsigned int)(v804 + 68) >> 2)) >> 1))) | (-(v807 ^ ((int)((unsigned int)((int)((unsigned int)(v804 + 68) >> 2)) >> 1))))) >> 31))) == 0);
  int v905;
  if (v920) {
    int * v813 = v800->cache_age;
    int v922 = ((((int)((unsigned int)((int)((unsigned int)(v804 + 68) >> 2)) >> 1)) & 1) * 2) + ((~(((v807 ^ ((int)((unsigned int)((int)((unsigned int)(v804 + 68) >> 2)) >> 1))) | (-(v807 ^ ((int)((unsigned int)((int)((unsigned int)(v804 + 68) >> 2)) >> 1))))) >> 31)) & 1);
    int v814 = v813[v922];
    int v815 = v813[v915];
    int v923 = v815 + ((int)((unsigned int)(v815 - v814) >> 31));
    v813[v915] = v923;
    int * v817 = v800->cache_age;
    int v818 = v817[v916];
    int v925 = v818 + ((int)((unsigned int)(v818 - v814) >> 31));
    v817[v916] = v925;
    int * v820 = v800->cache_age;
    v820[v922] = 0;
    v905 = v922;
  } else {
    int * v823 = v800->cache_age;
    int v929 = (((int)((unsigned int)((int)((unsigned int)(v804 + 68) >> 2)) >> 1)) & 1) * 2;
    int v824 = v823[v929];
    int * v825 = v800->cache_tags;
    int v826 = v825[v929];
    int v827 = v823[v916];
    int v828 = v825[v916];
    bool v931 = !(((~(((v808 ^ ((int)((unsigned int)((int)((unsigned int)(v804 + 68) >> 2)) >> 1))) | (-(v808 ^ ((int)((unsigned int)((int)((unsigned int)(v804 + 68) >> 2)) >> 1))))) >> 31)) | (~(((v809 ^ ((int)((unsigned int)((int)((unsigned int)(v804 + 68) >> 2)) >> 1))) | (-(v809 ^ ((int)((unsigned int)((int)((unsigned int)(v804 + 68) >> 2)) >> 1))))) >> 31))) == 0);
    int v882;
    if (v931) {
      int * v829 = v800->cache_age;
      int v933 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v804 + 68) >> 2)) >> 1)) & 3) * 2)) + ((~(((v809 ^ ((int)((unsigned int)((int)((unsigned int)(v804 + 68) >> 2)) >> 1))) | (-(v809 ^ ((int)((unsigned int)((int)((unsigned int)(v804 + 68) >> 2)) >> 1))))) >> 31)) & 1);
      int v830 = v829[v933];
      int v831 = v829[v917];
      int v934 = v831 + ((int)((unsigned int)(v831 - v830) >> 31));
      v829[v917] = v934;
      int * v833 = v800->cache_age;
      int v834 = v833[v918];
      int v936 = v834 + ((int)((unsigned int)(v834 - v830) >> 31));
      v833[v918] = v936;
      int * v836 = v800->cache_age;
      v836[v933] = 0;
      v882 = v933;
    } else {
      int * v839 = v800->cache_age;
      int v940 = 4 + ((((int)((unsigned int)((int)((unsigned int)(v804 + 68) >> 2)) >> 1)) & 3) * 2);
      int v840 = v839[v940];
      int * v841 = v800->cache_tags;
      int v842 = v841[v940];
      int v843 = v839[v918];
      int v844 = v841[v918];
      int * v845 = v800->cache_dirty;
      int v943 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v804 + 68) >> 2)) >> 1)) & 3) * 2)) + ((((v840 + ((~(((v842 ^ -1) | (-(v842 ^ -1))) >> 31)) & 2)) - (v843 + ((~(((v844 ^ -1) | (-(v844 ^ -1))) >> 31)) & 2))) >> 31) & 1);
      int v846 = v845[v943];
      bool v944 = !(v846 == 0);
      if (v944) {
        int * v847 = v800->cache_tags;
        int v848 = v847[v943];
        int * v849 = v800->cache_vals;
        int v947 = ((4 + ((((int)((unsigned int)((int)((unsigned int)(v804 + 68) >> 2)) >> 1)) & 3) * 2)) + ((((v840 + ((~(((v842 ^ -1) | (-(v842 ^ -1))) >> 31)) & 2)) - (v843 + ((~(((v844 ^ -1) | (-(v844 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
        int v850 = v849[v947];
        int v948 = (((4 + ((((int)((unsigned int)((int)((unsigned int)(v804 + 68) >> 2)) >> 1)) & 3) * 2)) + ((((v840 + ((~(((v842 ^ -1) | (-(v842 ^ -1))) >> 31)) & 2)) - (v843 + ((~(((v844 ^ -1) | (-(v844 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
        int v851 = v849[v948];
        int * v852 = v800->mem;
        int v950 = v848 * 2;
        v852[v950] = v850;
        int * v854 = v800->mem;
        int v953 = (v848 * 2) + 1;
        v854[v953] = v851;
        ;
      } else {
        ;
      }
      int * v859 = v800->mem;
      int v958 = ((int)((unsigned int)((int)((unsigned int)(v804 + 68) >> 2)) >> 1)) * 2;
      int v860 = v859[v958];
      int v959 = (((int)((unsigned int)((int)((unsigned int)(v804 + 68) >> 2)) >> 1)) * 2) + 1;
      int v861 = v859[v959];
      int * v862 = v800->cache_vals;
      int v961 = ((4 + ((((int)((unsigned int)((int)((unsigned int)(v804 + 68) >> 2)) >> 1)) & 3) * 2)) + ((((v840 + ((~(((v842 ^ -1) | (-(v842 ^ -1))) >> 31)) & 2)) - (v843 + ((~(((v844 ^ -1) | (-(v844 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
      v862[v961] = v860;
      int * v864 = v800->cache_vals;
      int v964 = (((4 + ((((int)((unsigned int)((int)((unsigned int)(v804 + 68) >> 2)) >> 1)) & 3) * 2)) + ((((v840 + ((~(((v842 ^ -1) | (-(v842 ^ -1))) >> 31)) & 2)) - (v843 + ((~(((v844 ^ -1) | (-(v844 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
      v864[v964] = v861;
      int * v866 = v800->cache_tags;
      int v967 = (int)((unsigned int)((int)((unsigned int)(v804 + 68) >> 2)) >> 1);
      v866[v943] = v967;
      int * v868 = v800->cache_dirty;
      v868[v943] = 0;
      int * v870 = v800->cache_age;
      v870[v943] = 1;
      int * v872 = v800->cache_age;
      int v873 = v872[v943];
      int v874 = v872[v917];
      int v973 = v874 + ((int)((unsigned int)(v874 - v873) >> 31));
      v872[v917] = v973;
      int * v876 = v800->cache_age;
      int v877 = v876[v918];
      int v975 = v877 + ((int)((unsigned int)(v877 - v873) >> 31));
      v876[v918] = v975;
      int * v879 = v800->cache_age;
      v879[v943] = 0;
      v882 = v943;
    }
    int * v883 = v800->cache_vals;
    int v978 = v882 * 2;
    int v884 = v883[v978];
    int v979 = (v882 * 2) + 1;
    int v885 = v883[v979];
    int v980 = (((((int)((unsigned int)((int)((unsigned int)(v804 + 68) >> 2)) >> 1)) & 1) * 2) + ((((v824 + ((~(((v826 ^ -1) | (-(v826 ^ -1))) >> 31)) & 2)) - (v827 + ((~(((v828 ^ -1) | (-(v828 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
    v883[v980] = v884;
    int * v887 = v800->cache_vals;
    int v983 = ((((((int)((unsigned int)((int)((unsigned int)(v804 + 68) >> 2)) >> 1)) & 1) * 2) + ((((v824 + ((~(((v826 ^ -1) | (-(v826 ^ -1))) >> 31)) & 2)) - (v827 + ((~(((v828 ^ -1) | (-(v828 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
    v887[v983] = v885;
    int * v889 = v800->cache_tags;
    int v986 = ((((int)((unsigned int)((int)((unsigned int)(v804 + 68) >> 2)) >> 1)) & 1) * 2) + ((((v824 + ((~(((v826 ^ -1) | (-(v826 ^ -1))) >> 31)) & 2)) - (v827 + ((~(((v828 ^ -1) | (-(v828 ^ -1))) >> 31)) & 2))) >> 31) & 1);
    int v987 = (int)((unsigned int)((int)((unsigned int)(v804 + 68) >> 2)) >> 1);
    v889[v986] = v987;
    int * v891 = v800->cache_dirty;
    v891[v986] = 0;
    int * v893 = v800->cache_age;
    v893[v986] = 1;
    int * v895 = v800->cache_age;
    int v896 = v895[v986];
    int v897 = v895[v915];
    int v993 = v897 + ((int)((unsigned int)(v897 - v896) >> 31));
    v895[v915] = v993;
    int * v899 = v800->cache_age;
    int v900 = v899[v916];
    int v995 = v900 + ((int)((unsigned int)(v900 - v896) >> 31));
    v899[v916] = v995;
    int * v902 = v800->cache_age;
    v902[v986] = 0;
    v905 = v986;
  }
  int v998 = (v905 * 2) + (((int)((unsigned int)(v804 + 68) >> 2)) & 1);
  int v906 = v812[v998];
  int * v907 = v800->regs;
  v907[11] = v906;
  struct StateT * v909 = slot_19(v800);
  return v909;
}

struct StateT * slot_9(struct StateT * v508) {
  int v509 = v508->timer;
  int v512 = v509 + 1;
  v508->timer = v512;
  return v508;
}

struct StateT * slot_0(struct StateT * v2) {
  int v3 = v2->timer;
  int v10 = v3 + 1;
  v2->timer = v10;
  int * v5 = v2->regs;
  int v6 = v5[10];
  int v13 = v6 << 2;
  v5[10] = v13;
  struct StateT * v8 = slot_1(v2);
  return v8;
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