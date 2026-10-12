// verify: clean (Eva should report untainted_timer: Valid) [unroll 129]
#define NUM_REGS 32
#define MEM_SIZE 64
#define SECRET_SIZE 10
#define SECRET_OFFSET 20
#define CACHE_ENTRIES 12
#define CACHE_WORDS 24
#define PHT_ENTRIES 128
#define HISTORY_BITS 4

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

struct StateG {
  int regs[32];
  int mem[64];
  int saved_regs[32];
  int reg_ready[32];
  int cache_tags[12];
  int cache_dirty[12];
  int cache_age[12];
  int cache_vals[24];
  int pht[128];
  int timer;
};

struct StateG * slot_12(struct StateG * v711);
struct StateG * slot_6(struct StateG * v100);
struct StateG * slot_2(struct StateG * v30);
struct StateG * slot_7(struct StateG * v115);
struct StateG * slot_3(struct StateG * v50);
struct StateG * snippet(struct StateG * v0);
struct StateG * slot_10(struct StateG * v192);
struct StateG * slot_1(struct StateG * v17);
struct StateG * slot_8(struct StateG * v135);
struct StateG * slot_4(struct StateG * v78);
struct StateG * slot_13(struct StateG * v725);
struct StateG * slot_9(struct StateG * v148);
struct StateG * slot_11(struct StateG * v507);
struct StateG * slot_0(struct StateG * v2);
struct StateG * slot_12(struct StateG * v711) {
  int v712 = v711->timer;
  int v719 = v712 + 1;
  v711->timer = v719;
  int * v714 = v711->regs;
  int v715 = v714[11];
  int v722 = v715 << 2;
  v714[11] = v722;
  struct StateG * v717 = slot_13(v711);
  return v717;
}

struct StateG * slot_6(struct StateG * v100) {
  int v101 = v100->timer;
  int v108 = v101 + 1;
  v100->timer = v108;
  int * v103 = v100->regs;
  int v104 = v103[5];
  int v112 = v104 + 80;
  v103[6] = v112;
  struct StateG * v106 = slot_8(v100);
  return v106;
}

struct StateG * slot_2(struct StateG * v30) {
  int v31 = v30->timer;
  int v41 = v31 + 1;
  v30->timer = v41;
  int * v33 = v30->pht;
  int v34 = v33[0];
  bool v44 = !(v34 == 0);
  struct StateG * v39;
  if (v44) {
    struct StateG * v35 = slot_3(v30);
    v39 = v35;
  } else {
    struct StateG * v37 = slot_4(v30);
    v39 = v37;
  }
  return v39;
}

struct StateG * slot_7(struct StateG * v115) {
  int * v116 = v115->saved_regs;
  int * v117 = v115->regs;
  int v118 = v117[7];
  v116[7] = v118;
  int v120 = v115->timer;
  int v130 = v120 + 1;
  v115->timer = v130;
  int * v122 = v115->regs;
  v122[7] = 0;
  struct StateG * v124 = slot_9(v115);
  return v124;
}

struct StateG * slot_3(struct StateG * v50) {
  int * v51 = v50->regs;
  int v52 = v51[5];
  int v53 = v51[9];
  bool v68 = v52 >= v53;
  struct StateG * v63;
  if (v68) {
    int * v54 = v50->pht;
    v54[0] = 1;
    v63 = v50;
  } else {
    int * v57 = v50->pht;
    v57[0] = 0;
    int v59 = v50->timer;
    int v74 = v59 + 15;
    v50->timer = v74;
    struct StateG * v61 = slot_6(v50);
    v63 = v61;
  }
  return v63;
}

struct StateG * snippet(struct StateG * v0) {
  struct StateG * v1 = slot_0(v0);
  return v1;
}

struct StateG * slot_10(struct StateG * v192) {
  int v193 = v192->timer;
  int v363 = v193 + 1;
  v192->timer = v363;
  int * v195 = v192->regs;
  int v196 = v195[6];
  int v197 = v195[7];
  int * v198 = v192->cache_tags;
  int v368 = (((int)((unsigned int)((int)((unsigned int)v196 >> 2)) >> 1)) & 1) * 2;
  int v199 = v198[v368];
  int v369 = ((((int)((unsigned int)((int)((unsigned int)v196 >> 2)) >> 1)) & 1) * 2) + 1;
  int v200 = v198[v369];
  int v370 = 4 + ((((int)((unsigned int)((int)((unsigned int)v196 >> 2)) >> 1)) & 3) * 2);
  int v201 = v198[v370];
  int v371 = (4 + ((((int)((unsigned int)((int)((unsigned int)v196 >> 2)) >> 1)) & 3) * 2)) + 1;
  int v202 = v198[v371];
  int v203 = v192->timer;
  int v372 = v203 + ((100 ^ (((~(((v201 ^ ((int)((unsigned int)((int)((unsigned int)v196 >> 2)) >> 1))) | (-(v201 ^ ((int)((unsigned int)((int)((unsigned int)v196 >> 2)) >> 1))))) >> 31)) | (~(((v202 ^ ((int)((unsigned int)((int)((unsigned int)v196 >> 2)) >> 1))) | (-(v202 ^ ((int)((unsigned int)((int)((unsigned int)v196 >> 2)) >> 1))))) >> 31))) & 104)) ^ (((~(((v199 ^ ((int)((unsigned int)((int)((unsigned int)v196 >> 2)) >> 1))) | (-(v199 ^ ((int)((unsigned int)((int)((unsigned int)v196 >> 2)) >> 1))))) >> 31)) | (~(((v200 ^ ((int)((unsigned int)((int)((unsigned int)v196 >> 2)) >> 1))) | (-(v200 ^ ((int)((unsigned int)((int)((unsigned int)v196 >> 2)) >> 1))))) >> 31))) & (1 ^ (100 ^ (((~(((v201 ^ ((int)((unsigned int)((int)((unsigned int)v196 >> 2)) >> 1))) | (-(v201 ^ ((int)((unsigned int)((int)((unsigned int)v196 >> 2)) >> 1))))) >> 31)) | (~(((v202 ^ ((int)((unsigned int)((int)((unsigned int)v196 >> 2)) >> 1))) | (-(v202 ^ ((int)((unsigned int)((int)((unsigned int)v196 >> 2)) >> 1))))) >> 31))) & 104)))));
  v192->timer = v372;
  bool v373 = !(((~(((v199 ^ ((int)((unsigned int)((int)((unsigned int)v196 >> 2)) >> 1))) | (-(v199 ^ ((int)((unsigned int)((int)((unsigned int)v196 >> 2)) >> 1))))) >> 31)) | (~(((v200 ^ ((int)((unsigned int)((int)((unsigned int)v196 >> 2)) >> 1))) | (-(v200 ^ ((int)((unsigned int)((int)((unsigned int)v196 >> 2)) >> 1))))) >> 31))) == 0);
  int v297;
  if (v373) {
    int * v205 = v192->cache_age;
    int v375 = ((((int)((unsigned int)((int)((unsigned int)v196 >> 2)) >> 1)) & 1) * 2) + ((~(((v200 ^ ((int)((unsigned int)((int)((unsigned int)v196 >> 2)) >> 1))) | (-(v200 ^ ((int)((unsigned int)((int)((unsigned int)v196 >> 2)) >> 1))))) >> 31)) & 1);
    int v206 = v205[v375];
    int v207 = v205[v368];
    int v376 = v207 + ((int)((unsigned int)(v207 - v206) >> 31));
    v205[v368] = v376;
    int * v209 = v192->cache_age;
    int v210 = v209[v369];
    int v378 = v210 + ((int)((unsigned int)(v210 - v206) >> 31));
    v209[v369] = v378;
    int * v212 = v192->cache_age;
    v212[v375] = 0;
    v297 = v375;
  } else {
    int * v215 = v192->cache_age;
    int v382 = (((int)((unsigned int)((int)((unsigned int)v196 >> 2)) >> 1)) & 1) * 2;
    int v216 = v215[v382];
    int * v217 = v192->cache_tags;
    int v218 = v217[v382];
    int v219 = v215[v369];
    int v220 = v217[v369];
    bool v384 = !(((~(((v201 ^ ((int)((unsigned int)((int)((unsigned int)v196 >> 2)) >> 1))) | (-(v201 ^ ((int)((unsigned int)((int)((unsigned int)v196 >> 2)) >> 1))))) >> 31)) | (~(((v202 ^ ((int)((unsigned int)((int)((unsigned int)v196 >> 2)) >> 1))) | (-(v202 ^ ((int)((unsigned int)((int)((unsigned int)v196 >> 2)) >> 1))))) >> 31))) == 0);
    int v274;
    if (v384) {
      int * v221 = v192->cache_age;
      int v386 = (4 + ((((int)((unsigned int)((int)((unsigned int)v196 >> 2)) >> 1)) & 3) * 2)) + ((~(((v202 ^ ((int)((unsigned int)((int)((unsigned int)v196 >> 2)) >> 1))) | (-(v202 ^ ((int)((unsigned int)((int)((unsigned int)v196 >> 2)) >> 1))))) >> 31)) & 1);
      int v222 = v221[v386];
      int v223 = v221[v370];
      int v387 = v223 + ((int)((unsigned int)(v223 - v222) >> 31));
      v221[v370] = v387;
      int * v225 = v192->cache_age;
      int v226 = v225[v371];
      int v389 = v226 + ((int)((unsigned int)(v226 - v222) >> 31));
      v225[v371] = v389;
      int * v228 = v192->cache_age;
      v228[v386] = 0;
      v274 = v386;
    } else {
      int * v231 = v192->cache_age;
      int v393 = 4 + ((((int)((unsigned int)((int)((unsigned int)v196 >> 2)) >> 1)) & 3) * 2);
      int v232 = v231[v393];
      int * v233 = v192->cache_tags;
      int v234 = v233[v393];
      int v235 = v231[v371];
      int v236 = v233[v371];
      int * v237 = v192->cache_dirty;
      int v396 = (4 + ((((int)((unsigned int)((int)((unsigned int)v196 >> 2)) >> 1)) & 3) * 2)) + ((((v232 + ((~(((v234 ^ -1) | (-(v234 ^ -1))) >> 31)) & 2)) - (v235 + ((~(((v236 ^ -1) | (-(v236 ^ -1))) >> 31)) & 2))) >> 31) & 1);
      int v238 = v237[v396];
      bool v397 = !(v238 == 0);
      if (v397) {
        int * v239 = v192->cache_tags;
        int v240 = v239[v396];
        int * v241 = v192->cache_vals;
        int v400 = ((4 + ((((int)((unsigned int)((int)((unsigned int)v196 >> 2)) >> 1)) & 3) * 2)) + ((((v232 + ((~(((v234 ^ -1) | (-(v234 ^ -1))) >> 31)) & 2)) - (v235 + ((~(((v236 ^ -1) | (-(v236 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
        int v242 = v241[v400];
        int v401 = (((4 + ((((int)((unsigned int)((int)((unsigned int)v196 >> 2)) >> 1)) & 3) * 2)) + ((((v232 + ((~(((v234 ^ -1) | (-(v234 ^ -1))) >> 31)) & 2)) - (v235 + ((~(((v236 ^ -1) | (-(v236 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
        int v243 = v241[v401];
        int * v244 = v192->mem;
        int v403 = v240 * 2;
        v244[v403] = v242;
        int * v246 = v192->mem;
        int v406 = (v240 * 2) + 1;
        v246[v406] = v243;
        ;
      } else {
        ;
      }
      int * v251 = v192->mem;
      int v411 = ((int)((unsigned int)((int)((unsigned int)v196 >> 2)) >> 1)) * 2;
      int v252 = v251[v411];
      int v412 = (((int)((unsigned int)((int)((unsigned int)v196 >> 2)) >> 1)) * 2) + 1;
      int v253 = v251[v412];
      int * v254 = v192->cache_vals;
      int v414 = ((4 + ((((int)((unsigned int)((int)((unsigned int)v196 >> 2)) >> 1)) & 3) * 2)) + ((((v232 + ((~(((v234 ^ -1) | (-(v234 ^ -1))) >> 31)) & 2)) - (v235 + ((~(((v236 ^ -1) | (-(v236 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
      v254[v414] = v252;
      int * v256 = v192->cache_vals;
      int v417 = (((4 + ((((int)((unsigned int)((int)((unsigned int)v196 >> 2)) >> 1)) & 3) * 2)) + ((((v232 + ((~(((v234 ^ -1) | (-(v234 ^ -1))) >> 31)) & 2)) - (v235 + ((~(((v236 ^ -1) | (-(v236 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
      v256[v417] = v253;
      int * v258 = v192->cache_tags;
      int v420 = (int)((unsigned int)((int)((unsigned int)v196 >> 2)) >> 1);
      v258[v396] = v420;
      int * v260 = v192->cache_dirty;
      v260[v396] = 0;
      int * v262 = v192->cache_age;
      v262[v396] = 1;
      int * v264 = v192->cache_age;
      int v265 = v264[v396];
      int v266 = v264[v370];
      int v426 = v266 + ((int)((unsigned int)(v266 - v265) >> 31));
      v264[v370] = v426;
      int * v268 = v192->cache_age;
      int v269 = v268[v371];
      int v428 = v269 + ((int)((unsigned int)(v269 - v265) >> 31));
      v268[v371] = v428;
      int * v271 = v192->cache_age;
      v271[v396] = 0;
      v274 = v396;
    }
    int * v275 = v192->cache_vals;
    int v431 = v274 * 2;
    int v276 = v275[v431];
    int v432 = (v274 * 2) + 1;
    int v277 = v275[v432];
    int v433 = (((((int)((unsigned int)((int)((unsigned int)v196 >> 2)) >> 1)) & 1) * 2) + ((((v216 + ((~(((v218 ^ -1) | (-(v218 ^ -1))) >> 31)) & 2)) - (v219 + ((~(((v220 ^ -1) | (-(v220 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
    v275[v433] = v276;
    int * v279 = v192->cache_vals;
    int v436 = ((((((int)((unsigned int)((int)((unsigned int)v196 >> 2)) >> 1)) & 1) * 2) + ((((v216 + ((~(((v218 ^ -1) | (-(v218 ^ -1))) >> 31)) & 2)) - (v219 + ((~(((v220 ^ -1) | (-(v220 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
    v279[v436] = v277;
    int * v281 = v192->cache_tags;
    int v439 = ((((int)((unsigned int)((int)((unsigned int)v196 >> 2)) >> 1)) & 1) * 2) + ((((v216 + ((~(((v218 ^ -1) | (-(v218 ^ -1))) >> 31)) & 2)) - (v219 + ((~(((v220 ^ -1) | (-(v220 ^ -1))) >> 31)) & 2))) >> 31) & 1);
    int v440 = (int)((unsigned int)((int)((unsigned int)v196 >> 2)) >> 1);
    v281[v439] = v440;
    int * v283 = v192->cache_dirty;
    v283[v439] = 0;
    int * v285 = v192->cache_age;
    v285[v439] = 1;
    int * v287 = v192->cache_age;
    int v288 = v287[v439];
    int v289 = v287[v368];
    int v446 = v289 + ((int)((unsigned int)(v289 - v288) >> 31));
    v287[v368] = v446;
    int * v291 = v192->cache_age;
    int v292 = v291[v369];
    int v448 = v292 + ((int)((unsigned int)(v292 - v288) >> 31));
    v291[v369] = v448;
    int * v294 = v192->cache_age;
    v294[v439] = 0;
    v297 = v439;
  }
  int * v298 = v192->cache_vals;
  int v451 = (v297 * 2) + (((int)((unsigned int)v196 >> 2)) & 1);
  v298[v451] = v197;
  int * v300 = v192->cache_tags;
  int v301 = v300[v370];
  int v302 = v300[v371];
  bool v454 = !(((~(((v301 ^ ((int)((unsigned int)((int)((unsigned int)v196 >> 2)) >> 1))) | (-(v301 ^ ((int)((unsigned int)((int)((unsigned int)v196 >> 2)) >> 1))))) >> 31)) | (~(((v302 ^ ((int)((unsigned int)((int)((unsigned int)v196 >> 2)) >> 1))) | (-(v302 ^ ((int)((unsigned int)((int)((unsigned int)v196 >> 2)) >> 1))))) >> 31))) == 0);
  int v356;
  if (v454) {
    int * v303 = v192->cache_age;
    int v456 = (4 + ((((int)((unsigned int)((int)((unsigned int)v196 >> 2)) >> 1)) & 3) * 2)) + ((~(((v302 ^ ((int)((unsigned int)((int)((unsigned int)v196 >> 2)) >> 1))) | (-(v302 ^ ((int)((unsigned int)((int)((unsigned int)v196 >> 2)) >> 1))))) >> 31)) & 1);
    int v304 = v303[v456];
    int v305 = v303[v370];
    int v457 = v305 + ((int)((unsigned int)(v305 - v304) >> 31));
    v303[v370] = v457;
    int * v307 = v192->cache_age;
    int v308 = v307[v371];
    int v459 = v308 + ((int)((unsigned int)(v308 - v304) >> 31));
    v307[v371] = v459;
    int * v310 = v192->cache_age;
    v310[v456] = 0;
    v356 = v456;
  } else {
    int * v313 = v192->cache_age;
    int v463 = 4 + ((((int)((unsigned int)((int)((unsigned int)v196 >> 2)) >> 1)) & 3) * 2);
    int v314 = v313[v463];
    int * v315 = v192->cache_tags;
    int v316 = v315[v463];
    int v317 = v313[v371];
    int v318 = v315[v371];
    int * v319 = v192->cache_dirty;
    int v466 = (4 + ((((int)((unsigned int)((int)((unsigned int)v196 >> 2)) >> 1)) & 3) * 2)) + ((((v314 + ((~(((v316 ^ -1) | (-(v316 ^ -1))) >> 31)) & 2)) - (v317 + ((~(((v318 ^ -1) | (-(v318 ^ -1))) >> 31)) & 2))) >> 31) & 1);
    int v320 = v319[v466];
    bool v467 = !(v320 == 0);
    if (v467) {
      int * v321 = v192->cache_tags;
      int v322 = v321[v466];
      int * v323 = v192->cache_vals;
      int v470 = ((4 + ((((int)((unsigned int)((int)((unsigned int)v196 >> 2)) >> 1)) & 3) * 2)) + ((((v314 + ((~(((v316 ^ -1) | (-(v316 ^ -1))) >> 31)) & 2)) - (v317 + ((~(((v318 ^ -1) | (-(v318 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
      int v324 = v323[v470];
      int v471 = (((4 + ((((int)((unsigned int)((int)((unsigned int)v196 >> 2)) >> 1)) & 3) * 2)) + ((((v314 + ((~(((v316 ^ -1) | (-(v316 ^ -1))) >> 31)) & 2)) - (v317 + ((~(((v318 ^ -1) | (-(v318 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
      int v325 = v323[v471];
      int * v326 = v192->mem;
      int v473 = v322 * 2;
      v326[v473] = v324;
      int * v328 = v192->mem;
      int v476 = (v322 * 2) + 1;
      v328[v476] = v325;
      ;
    } else {
      ;
    }
    int * v333 = v192->mem;
    int v481 = ((int)((unsigned int)((int)((unsigned int)v196 >> 2)) >> 1)) * 2;
    int v334 = v333[v481];
    int v482 = (((int)((unsigned int)((int)((unsigned int)v196 >> 2)) >> 1)) * 2) + 1;
    int v335 = v333[v482];
    int * v336 = v192->cache_vals;
    int v484 = ((4 + ((((int)((unsigned int)((int)((unsigned int)v196 >> 2)) >> 1)) & 3) * 2)) + ((((v314 + ((~(((v316 ^ -1) | (-(v316 ^ -1))) >> 31)) & 2)) - (v317 + ((~(((v318 ^ -1) | (-(v318 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
    v336[v484] = v334;
    int * v338 = v192->cache_vals;
    int v487 = (((4 + ((((int)((unsigned int)((int)((unsigned int)v196 >> 2)) >> 1)) & 3) * 2)) + ((((v314 + ((~(((v316 ^ -1) | (-(v316 ^ -1))) >> 31)) & 2)) - (v317 + ((~(((v318 ^ -1) | (-(v318 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
    v338[v487] = v335;
    int * v340 = v192->cache_tags;
    int v490 = (int)((unsigned int)((int)((unsigned int)v196 >> 2)) >> 1);
    v340[v466] = v490;
    int * v342 = v192->cache_dirty;
    v342[v466] = 0;
    int * v344 = v192->cache_age;
    v344[v466] = 1;
    int * v346 = v192->cache_age;
    int v347 = v346[v466];
    int v348 = v346[v370];
    int v496 = v348 + ((int)((unsigned int)(v348 - v347) >> 31));
    v346[v370] = v496;
    int * v350 = v192->cache_age;
    int v351 = v350[v371];
    int v498 = v351 + ((int)((unsigned int)(v351 - v347) >> 31));
    v350[v371] = v498;
    int * v353 = v192->cache_age;
    v353[v466] = 0;
    v356 = v466;
  }
  int * v357 = v192->cache_vals;
  int v501 = (v356 * 2) + (((int)((unsigned int)v196 >> 2)) & 1);
  v357[v501] = v197;
  int * v359 = v192->cache_dirty;
  v359[v356] = 1;
  struct StateG * v361 = slot_11(v192);
  return v361;
}

struct StateG * slot_1(struct StateG * v17) {
  int v18 = v17->timer;
  int v24 = v18 + 1;
  v17->timer = v24;
  int * v20 = v17->regs;
  v20[9] = 32;
  struct StateG * v22 = slot_2(v17);
  return v22;
}

struct StateG * slot_8(struct StateG * v135) {
  int v136 = v135->timer;
  int v142 = v136 + 1;
  v135->timer = v142;
  int * v138 = v135->regs;
  v138[7] = 0;
  struct StateG * v140 = slot_10(v135);
  return v140;
}

struct StateG * slot_4(struct StateG * v78) {
  int * v79 = v78->saved_regs;
  int * v80 = v78->regs;
  int v81 = v80[6];
  v79[6] = v81;
  int v83 = v78->timer;
  int v94 = v83 + 1;
  v78->timer = v94;
  int * v85 = v78->regs;
  int v86 = v85[5];
  int v97 = v86 + 80;
  v85[6] = v97;
  struct StateG * v88 = slot_7(v78);
  return v88;
}

struct StateG * slot_13(struct StateG * v725) {
  int v726 = v725->timer;
  int v835 = v726 + 1;
  v725->timer = v835;
  int * v728 = v725->regs;
  int v729 = v728[11];
  int * v730 = v725->cache_tags;
  int v839 = (((int)((unsigned int)((int)((unsigned int)v729 >> 2)) >> 1)) & 1) * 2;
  int v731 = v730[v839];
  int v840 = ((((int)((unsigned int)((int)((unsigned int)v729 >> 2)) >> 1)) & 1) * 2) + 1;
  int v732 = v730[v840];
  int v841 = 4 + ((((int)((unsigned int)((int)((unsigned int)v729 >> 2)) >> 1)) & 3) * 2);
  int v733 = v730[v841];
  int v842 = (4 + ((((int)((unsigned int)((int)((unsigned int)v729 >> 2)) >> 1)) & 3) * 2)) + 1;
  int v734 = v730[v842];
  int v735 = v725->timer;
  int v843 = v735 + ((100 ^ (((~(((v733 ^ ((int)((unsigned int)((int)((unsigned int)v729 >> 2)) >> 1))) | (-(v733 ^ ((int)((unsigned int)((int)((unsigned int)v729 >> 2)) >> 1))))) >> 31)) | (~(((v734 ^ ((int)((unsigned int)((int)((unsigned int)v729 >> 2)) >> 1))) | (-(v734 ^ ((int)((unsigned int)((int)((unsigned int)v729 >> 2)) >> 1))))) >> 31))) & 104)) ^ (((~(((v731 ^ ((int)((unsigned int)((int)((unsigned int)v729 >> 2)) >> 1))) | (-(v731 ^ ((int)((unsigned int)((int)((unsigned int)v729 >> 2)) >> 1))))) >> 31)) | (~(((v732 ^ ((int)((unsigned int)((int)((unsigned int)v729 >> 2)) >> 1))) | (-(v732 ^ ((int)((unsigned int)((int)((unsigned int)v729 >> 2)) >> 1))))) >> 31))) & (1 ^ (100 ^ (((~(((v733 ^ ((int)((unsigned int)((int)((unsigned int)v729 >> 2)) >> 1))) | (-(v733 ^ ((int)((unsigned int)((int)((unsigned int)v729 >> 2)) >> 1))))) >> 31)) | (~(((v734 ^ ((int)((unsigned int)((int)((unsigned int)v729 >> 2)) >> 1))) | (-(v734 ^ ((int)((unsigned int)((int)((unsigned int)v729 >> 2)) >> 1))))) >> 31))) & 104)))));
  v725->timer = v843;
  int * v737 = v725->cache_vals;
  bool v844 = !(((~(((v731 ^ ((int)((unsigned int)((int)((unsigned int)v729 >> 2)) >> 1))) | (-(v731 ^ ((int)((unsigned int)((int)((unsigned int)v729 >> 2)) >> 1))))) >> 31)) | (~(((v732 ^ ((int)((unsigned int)((int)((unsigned int)v729 >> 2)) >> 1))) | (-(v732 ^ ((int)((unsigned int)((int)((unsigned int)v729 >> 2)) >> 1))))) >> 31))) == 0);
  int v830;
  if (v844) {
    int * v738 = v725->cache_age;
    int v846 = ((((int)((unsigned int)((int)((unsigned int)v729 >> 2)) >> 1)) & 1) * 2) + ((~(((v732 ^ ((int)((unsigned int)((int)((unsigned int)v729 >> 2)) >> 1))) | (-(v732 ^ ((int)((unsigned int)((int)((unsigned int)v729 >> 2)) >> 1))))) >> 31)) & 1);
    int v739 = v738[v846];
    int v740 = v738[v839];
    int v847 = v740 + ((int)((unsigned int)(v740 - v739) >> 31));
    v738[v839] = v847;
    int * v742 = v725->cache_age;
    int v743 = v742[v840];
    int v849 = v743 + ((int)((unsigned int)(v743 - v739) >> 31));
    v742[v840] = v849;
    int * v745 = v725->cache_age;
    v745[v846] = 0;
    v830 = v846;
  } else {
    int * v748 = v725->cache_age;
    int v853 = (((int)((unsigned int)((int)((unsigned int)v729 >> 2)) >> 1)) & 1) * 2;
    int v749 = v748[v853];
    int * v750 = v725->cache_tags;
    int v751 = v750[v853];
    int v752 = v748[v840];
    int v753 = v750[v840];
    bool v855 = !(((~(((v733 ^ ((int)((unsigned int)((int)((unsigned int)v729 >> 2)) >> 1))) | (-(v733 ^ ((int)((unsigned int)((int)((unsigned int)v729 >> 2)) >> 1))))) >> 31)) | (~(((v734 ^ ((int)((unsigned int)((int)((unsigned int)v729 >> 2)) >> 1))) | (-(v734 ^ ((int)((unsigned int)((int)((unsigned int)v729 >> 2)) >> 1))))) >> 31))) == 0);
    int v807;
    if (v855) {
      int * v754 = v725->cache_age;
      int v857 = (4 + ((((int)((unsigned int)((int)((unsigned int)v729 >> 2)) >> 1)) & 3) * 2)) + ((~(((v734 ^ ((int)((unsigned int)((int)((unsigned int)v729 >> 2)) >> 1))) | (-(v734 ^ ((int)((unsigned int)((int)((unsigned int)v729 >> 2)) >> 1))))) >> 31)) & 1);
      int v755 = v754[v857];
      int v756 = v754[v841];
      int v858 = v756 + ((int)((unsigned int)(v756 - v755) >> 31));
      v754[v841] = v858;
      int * v758 = v725->cache_age;
      int v759 = v758[v842];
      int v860 = v759 + ((int)((unsigned int)(v759 - v755) >> 31));
      v758[v842] = v860;
      int * v761 = v725->cache_age;
      v761[v857] = 0;
      v807 = v857;
    } else {
      int * v764 = v725->cache_age;
      int v864 = 4 + ((((int)((unsigned int)((int)((unsigned int)v729 >> 2)) >> 1)) & 3) * 2);
      int v765 = v764[v864];
      int * v766 = v725->cache_tags;
      int v767 = v766[v864];
      int v768 = v764[v842];
      int v769 = v766[v842];
      int * v770 = v725->cache_dirty;
      int v867 = (4 + ((((int)((unsigned int)((int)((unsigned int)v729 >> 2)) >> 1)) & 3) * 2)) + ((((v765 + ((~(((v767 ^ -1) | (-(v767 ^ -1))) >> 31)) & 2)) - (v768 + ((~(((v769 ^ -1) | (-(v769 ^ -1))) >> 31)) & 2))) >> 31) & 1);
      int v771 = v770[v867];
      bool v868 = !(v771 == 0);
      if (v868) {
        int * v772 = v725->cache_tags;
        int v773 = v772[v867];
        int * v774 = v725->cache_vals;
        int v871 = ((4 + ((((int)((unsigned int)((int)((unsigned int)v729 >> 2)) >> 1)) & 3) * 2)) + ((((v765 + ((~(((v767 ^ -1) | (-(v767 ^ -1))) >> 31)) & 2)) - (v768 + ((~(((v769 ^ -1) | (-(v769 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
        int v775 = v774[v871];
        int v872 = (((4 + ((((int)((unsigned int)((int)((unsigned int)v729 >> 2)) >> 1)) & 3) * 2)) + ((((v765 + ((~(((v767 ^ -1) | (-(v767 ^ -1))) >> 31)) & 2)) - (v768 + ((~(((v769 ^ -1) | (-(v769 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
        int v776 = v774[v872];
        int * v777 = v725->mem;
        int v874 = v773 * 2;
        v777[v874] = v775;
        int * v779 = v725->mem;
        int v877 = (v773 * 2) + 1;
        v779[v877] = v776;
        ;
      } else {
        ;
      }
      int * v784 = v725->mem;
      int v882 = ((int)((unsigned int)((int)((unsigned int)v729 >> 2)) >> 1)) * 2;
      int v785 = v784[v882];
      int v883 = (((int)((unsigned int)((int)((unsigned int)v729 >> 2)) >> 1)) * 2) + 1;
      int v786 = v784[v883];
      int * v787 = v725->cache_vals;
      int v885 = ((4 + ((((int)((unsigned int)((int)((unsigned int)v729 >> 2)) >> 1)) & 3) * 2)) + ((((v765 + ((~(((v767 ^ -1) | (-(v767 ^ -1))) >> 31)) & 2)) - (v768 + ((~(((v769 ^ -1) | (-(v769 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
      v787[v885] = v785;
      int * v789 = v725->cache_vals;
      int v888 = (((4 + ((((int)((unsigned int)((int)((unsigned int)v729 >> 2)) >> 1)) & 3) * 2)) + ((((v765 + ((~(((v767 ^ -1) | (-(v767 ^ -1))) >> 31)) & 2)) - (v768 + ((~(((v769 ^ -1) | (-(v769 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
      v789[v888] = v786;
      int * v791 = v725->cache_tags;
      int v891 = (int)((unsigned int)((int)((unsigned int)v729 >> 2)) >> 1);
      v791[v867] = v891;
      int * v793 = v725->cache_dirty;
      v793[v867] = 0;
      int * v795 = v725->cache_age;
      v795[v867] = 1;
      int * v797 = v725->cache_age;
      int v798 = v797[v867];
      int v799 = v797[v841];
      int v897 = v799 + ((int)((unsigned int)(v799 - v798) >> 31));
      v797[v841] = v897;
      int * v801 = v725->cache_age;
      int v802 = v801[v842];
      int v899 = v802 + ((int)((unsigned int)(v802 - v798) >> 31));
      v801[v842] = v899;
      int * v804 = v725->cache_age;
      v804[v867] = 0;
      v807 = v867;
    }
    int * v808 = v725->cache_vals;
    int v902 = v807 * 2;
    int v809 = v808[v902];
    int v903 = (v807 * 2) + 1;
    int v810 = v808[v903];
    int v904 = (((((int)((unsigned int)((int)((unsigned int)v729 >> 2)) >> 1)) & 1) * 2) + ((((v749 + ((~(((v751 ^ -1) | (-(v751 ^ -1))) >> 31)) & 2)) - (v752 + ((~(((v753 ^ -1) | (-(v753 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
    v808[v904] = v809;
    int * v812 = v725->cache_vals;
    int v907 = ((((((int)((unsigned int)((int)((unsigned int)v729 >> 2)) >> 1)) & 1) * 2) + ((((v749 + ((~(((v751 ^ -1) | (-(v751 ^ -1))) >> 31)) & 2)) - (v752 + ((~(((v753 ^ -1) | (-(v753 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
    v812[v907] = v810;
    int * v814 = v725->cache_tags;
    int v910 = ((((int)((unsigned int)((int)((unsigned int)v729 >> 2)) >> 1)) & 1) * 2) + ((((v749 + ((~(((v751 ^ -1) | (-(v751 ^ -1))) >> 31)) & 2)) - (v752 + ((~(((v753 ^ -1) | (-(v753 ^ -1))) >> 31)) & 2))) >> 31) & 1);
    int v911 = (int)((unsigned int)((int)((unsigned int)v729 >> 2)) >> 1);
    v814[v910] = v911;
    int * v816 = v725->cache_dirty;
    v816[v910] = 0;
    int * v818 = v725->cache_age;
    v818[v910] = 1;
    int * v820 = v725->cache_age;
    int v821 = v820[v910];
    int v822 = v820[v839];
    int v917 = v822 + ((int)((unsigned int)(v822 - v821) >> 31));
    v820[v839] = v917;
    int * v824 = v725->cache_age;
    int v825 = v824[v840];
    int v919 = v825 + ((int)((unsigned int)(v825 - v821) >> 31));
    v824[v840] = v919;
    int * v827 = v725->cache_age;
    v827[v910] = 0;
    v830 = v910;
  }
  int v922 = (v830 * 2) + (((int)((unsigned int)v729 >> 2)) & 1);
  int v831 = v737[v922];
  int * v832 = v725->regs;
  v832[12] = v831;
  return v725;
}

struct StateG * slot_9(struct StateG * v148) {
  int * v149 = v148->regs;
  int v150 = v149[5];
  int v151 = v149[9];
  bool v174 = v150 >= v151;
  struct StateG * v169;
  if (v174) {
    int * v152 = v148->pht;
    v152[0] = 1;
    int v154 = v148->timer;
    int v178 = v154 + 15;
    v148->timer = v178;
    int * v156 = v148->saved_regs;
    int v157 = v156[6];
    int * v158 = v148->regs;
    v158[6] = v157;
    int * v160 = v148->saved_regs;
    int v161 = v160[7];
    int * v162 = v148->regs;
    v162[7] = v161;
    v169 = v148;
  } else {
    int * v165 = v148->pht;
    v165[0] = 0;
    struct StateG * v167 = slot_10(v148);
    v169 = v167;
  }
  return v169;
}

struct StateG * slot_11(struct StateG * v507) {
  int v508 = v507->timer;
  int v618 = v508 + 1;
  v507->timer = v618;
  int * v510 = v507->regs;
  int v511 = v510[6];
  int * v512 = v507->cache_tags;
  int v622 = (((int)((unsigned int)((int)((unsigned int)v511 >> 2)) >> 1)) & 1) * 2;
  int v513 = v512[v622];
  int v623 = ((((int)((unsigned int)((int)((unsigned int)v511 >> 2)) >> 1)) & 1) * 2) + 1;
  int v514 = v512[v623];
  int v624 = 4 + ((((int)((unsigned int)((int)((unsigned int)v511 >> 2)) >> 1)) & 3) * 2);
  int v515 = v512[v624];
  int v625 = (4 + ((((int)((unsigned int)((int)((unsigned int)v511 >> 2)) >> 1)) & 3) * 2)) + 1;
  int v516 = v512[v625];
  int v517 = v507->timer;
  int v626 = v517 + ((100 ^ (((~(((v515 ^ ((int)((unsigned int)((int)((unsigned int)v511 >> 2)) >> 1))) | (-(v515 ^ ((int)((unsigned int)((int)((unsigned int)v511 >> 2)) >> 1))))) >> 31)) | (~(((v516 ^ ((int)((unsigned int)((int)((unsigned int)v511 >> 2)) >> 1))) | (-(v516 ^ ((int)((unsigned int)((int)((unsigned int)v511 >> 2)) >> 1))))) >> 31))) & 104)) ^ (((~(((v513 ^ ((int)((unsigned int)((int)((unsigned int)v511 >> 2)) >> 1))) | (-(v513 ^ ((int)((unsigned int)((int)((unsigned int)v511 >> 2)) >> 1))))) >> 31)) | (~(((v514 ^ ((int)((unsigned int)((int)((unsigned int)v511 >> 2)) >> 1))) | (-(v514 ^ ((int)((unsigned int)((int)((unsigned int)v511 >> 2)) >> 1))))) >> 31))) & (1 ^ (100 ^ (((~(((v515 ^ ((int)((unsigned int)((int)((unsigned int)v511 >> 2)) >> 1))) | (-(v515 ^ ((int)((unsigned int)((int)((unsigned int)v511 >> 2)) >> 1))))) >> 31)) | (~(((v516 ^ ((int)((unsigned int)((int)((unsigned int)v511 >> 2)) >> 1))) | (-(v516 ^ ((int)((unsigned int)((int)((unsigned int)v511 >> 2)) >> 1))))) >> 31))) & 104)))));
  v507->timer = v626;
  int * v519 = v507->cache_vals;
  bool v627 = !(((~(((v513 ^ ((int)((unsigned int)((int)((unsigned int)v511 >> 2)) >> 1))) | (-(v513 ^ ((int)((unsigned int)((int)((unsigned int)v511 >> 2)) >> 1))))) >> 31)) | (~(((v514 ^ ((int)((unsigned int)((int)((unsigned int)v511 >> 2)) >> 1))) | (-(v514 ^ ((int)((unsigned int)((int)((unsigned int)v511 >> 2)) >> 1))))) >> 31))) == 0);
  int v612;
  if (v627) {
    int * v520 = v507->cache_age;
    int v629 = ((((int)((unsigned int)((int)((unsigned int)v511 >> 2)) >> 1)) & 1) * 2) + ((~(((v514 ^ ((int)((unsigned int)((int)((unsigned int)v511 >> 2)) >> 1))) | (-(v514 ^ ((int)((unsigned int)((int)((unsigned int)v511 >> 2)) >> 1))))) >> 31)) & 1);
    int v521 = v520[v629];
    int v522 = v520[v622];
    int v630 = v522 + ((int)((unsigned int)(v522 - v521) >> 31));
    v520[v622] = v630;
    int * v524 = v507->cache_age;
    int v525 = v524[v623];
    int v632 = v525 + ((int)((unsigned int)(v525 - v521) >> 31));
    v524[v623] = v632;
    int * v527 = v507->cache_age;
    v527[v629] = 0;
    v612 = v629;
  } else {
    int * v530 = v507->cache_age;
    int v636 = (((int)((unsigned int)((int)((unsigned int)v511 >> 2)) >> 1)) & 1) * 2;
    int v531 = v530[v636];
    int * v532 = v507->cache_tags;
    int v533 = v532[v636];
    int v534 = v530[v623];
    int v535 = v532[v623];
    bool v638 = !(((~(((v515 ^ ((int)((unsigned int)((int)((unsigned int)v511 >> 2)) >> 1))) | (-(v515 ^ ((int)((unsigned int)((int)((unsigned int)v511 >> 2)) >> 1))))) >> 31)) | (~(((v516 ^ ((int)((unsigned int)((int)((unsigned int)v511 >> 2)) >> 1))) | (-(v516 ^ ((int)((unsigned int)((int)((unsigned int)v511 >> 2)) >> 1))))) >> 31))) == 0);
    int v589;
    if (v638) {
      int * v536 = v507->cache_age;
      int v640 = (4 + ((((int)((unsigned int)((int)((unsigned int)v511 >> 2)) >> 1)) & 3) * 2)) + ((~(((v516 ^ ((int)((unsigned int)((int)((unsigned int)v511 >> 2)) >> 1))) | (-(v516 ^ ((int)((unsigned int)((int)((unsigned int)v511 >> 2)) >> 1))))) >> 31)) & 1);
      int v537 = v536[v640];
      int v538 = v536[v624];
      int v641 = v538 + ((int)((unsigned int)(v538 - v537) >> 31));
      v536[v624] = v641;
      int * v540 = v507->cache_age;
      int v541 = v540[v625];
      int v643 = v541 + ((int)((unsigned int)(v541 - v537) >> 31));
      v540[v625] = v643;
      int * v543 = v507->cache_age;
      v543[v640] = 0;
      v589 = v640;
    } else {
      int * v546 = v507->cache_age;
      int v647 = 4 + ((((int)((unsigned int)((int)((unsigned int)v511 >> 2)) >> 1)) & 3) * 2);
      int v547 = v546[v647];
      int * v548 = v507->cache_tags;
      int v549 = v548[v647];
      int v550 = v546[v625];
      int v551 = v548[v625];
      int * v552 = v507->cache_dirty;
      int v650 = (4 + ((((int)((unsigned int)((int)((unsigned int)v511 >> 2)) >> 1)) & 3) * 2)) + ((((v547 + ((~(((v549 ^ -1) | (-(v549 ^ -1))) >> 31)) & 2)) - (v550 + ((~(((v551 ^ -1) | (-(v551 ^ -1))) >> 31)) & 2))) >> 31) & 1);
      int v553 = v552[v650];
      bool v651 = !(v553 == 0);
      if (v651) {
        int * v554 = v507->cache_tags;
        int v555 = v554[v650];
        int * v556 = v507->cache_vals;
        int v654 = ((4 + ((((int)((unsigned int)((int)((unsigned int)v511 >> 2)) >> 1)) & 3) * 2)) + ((((v547 + ((~(((v549 ^ -1) | (-(v549 ^ -1))) >> 31)) & 2)) - (v550 + ((~(((v551 ^ -1) | (-(v551 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
        int v557 = v556[v654];
        int v655 = (((4 + ((((int)((unsigned int)((int)((unsigned int)v511 >> 2)) >> 1)) & 3) * 2)) + ((((v547 + ((~(((v549 ^ -1) | (-(v549 ^ -1))) >> 31)) & 2)) - (v550 + ((~(((v551 ^ -1) | (-(v551 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
        int v558 = v556[v655];
        int * v559 = v507->mem;
        int v657 = v555 * 2;
        v559[v657] = v557;
        int * v561 = v507->mem;
        int v660 = (v555 * 2) + 1;
        v561[v660] = v558;
        ;
      } else {
        ;
      }
      int * v566 = v507->mem;
      int v665 = ((int)((unsigned int)((int)((unsigned int)v511 >> 2)) >> 1)) * 2;
      int v567 = v566[v665];
      int v666 = (((int)((unsigned int)((int)((unsigned int)v511 >> 2)) >> 1)) * 2) + 1;
      int v568 = v566[v666];
      int * v569 = v507->cache_vals;
      int v668 = ((4 + ((((int)((unsigned int)((int)((unsigned int)v511 >> 2)) >> 1)) & 3) * 2)) + ((((v547 + ((~(((v549 ^ -1) | (-(v549 ^ -1))) >> 31)) & 2)) - (v550 + ((~(((v551 ^ -1) | (-(v551 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
      v569[v668] = v567;
      int * v571 = v507->cache_vals;
      int v671 = (((4 + ((((int)((unsigned int)((int)((unsigned int)v511 >> 2)) >> 1)) & 3) * 2)) + ((((v547 + ((~(((v549 ^ -1) | (-(v549 ^ -1))) >> 31)) & 2)) - (v550 + ((~(((v551 ^ -1) | (-(v551 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
      v571[v671] = v568;
      int * v573 = v507->cache_tags;
      int v674 = (int)((unsigned int)((int)((unsigned int)v511 >> 2)) >> 1);
      v573[v650] = v674;
      int * v575 = v507->cache_dirty;
      v575[v650] = 0;
      int * v577 = v507->cache_age;
      v577[v650] = 1;
      int * v579 = v507->cache_age;
      int v580 = v579[v650];
      int v581 = v579[v624];
      int v680 = v581 + ((int)((unsigned int)(v581 - v580) >> 31));
      v579[v624] = v680;
      int * v583 = v507->cache_age;
      int v584 = v583[v625];
      int v682 = v584 + ((int)((unsigned int)(v584 - v580) >> 31));
      v583[v625] = v682;
      int * v586 = v507->cache_age;
      v586[v650] = 0;
      v589 = v650;
    }
    int * v590 = v507->cache_vals;
    int v685 = v589 * 2;
    int v591 = v590[v685];
    int v686 = (v589 * 2) + 1;
    int v592 = v590[v686];
    int v687 = (((((int)((unsigned int)((int)((unsigned int)v511 >> 2)) >> 1)) & 1) * 2) + ((((v531 + ((~(((v533 ^ -1) | (-(v533 ^ -1))) >> 31)) & 2)) - (v534 + ((~(((v535 ^ -1) | (-(v535 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
    v590[v687] = v591;
    int * v594 = v507->cache_vals;
    int v690 = ((((((int)((unsigned int)((int)((unsigned int)v511 >> 2)) >> 1)) & 1) * 2) + ((((v531 + ((~(((v533 ^ -1) | (-(v533 ^ -1))) >> 31)) & 2)) - (v534 + ((~(((v535 ^ -1) | (-(v535 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
    v594[v690] = v592;
    int * v596 = v507->cache_tags;
    int v693 = ((((int)((unsigned int)((int)((unsigned int)v511 >> 2)) >> 1)) & 1) * 2) + ((((v531 + ((~(((v533 ^ -1) | (-(v533 ^ -1))) >> 31)) & 2)) - (v534 + ((~(((v535 ^ -1) | (-(v535 ^ -1))) >> 31)) & 2))) >> 31) & 1);
    int v694 = (int)((unsigned int)((int)((unsigned int)v511 >> 2)) >> 1);
    v596[v693] = v694;
    int * v598 = v507->cache_dirty;
    v598[v693] = 0;
    int * v600 = v507->cache_age;
    v600[v693] = 1;
    int * v602 = v507->cache_age;
    int v603 = v602[v693];
    int v604 = v602[v622];
    int v700 = v604 + ((int)((unsigned int)(v604 - v603) >> 31));
    v602[v622] = v700;
    int * v606 = v507->cache_age;
    int v607 = v606[v623];
    int v702 = v607 + ((int)((unsigned int)(v607 - v603) >> 31));
    v606[v623] = v702;
    int * v609 = v507->cache_age;
    v609[v693] = 0;
    v612 = v693;
  }
  int v705 = (v612 * 2) + (((int)((unsigned int)v511 >> 2)) & 1);
  int v613 = v519[v705];
  int * v614 = v507->regs;
  v614[11] = v613;
  struct StateG * v616 = slot_12(v507);
  return v616;
}

struct StateG * slot_0(struct StateG * v2) {
  int v3 = v2->timer;
  int v10 = v3 + 1;
  v2->timer = v10;
  int * v5 = v2->regs;
  int v6 = v5[10];
  int v14 = v6 & 28;
  v5[5] = v14;
  struct StateG * v8 = slot_1(v2);
  return v8;
}



/*****************************************
End of C Generated Code
*******************************************/

void init(struct StateG *s) {
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
  for (int i=0; i<PHT_ENTRIES; i++) {
    s->pht[i] = 0;
  }
}

int main(int argc, char* argv[]) {
  struct StateG s1, s2;
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
  struct StateG *s1_ = snippet(&s1);
  struct StateG *s2_ = snippet(&s2);
  //@ assert untainted_timer: !\tainted(s1_->timer==s2_->timer);
  koika_assert(s1_->timer==s2_->timer, "timing leak");
  return 0;
}