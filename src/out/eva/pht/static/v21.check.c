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

struct StateT * slot_12(struct StateT * v568);
struct StateT * slot_14(struct StateT * v787);
struct StateT * slot_6(struct StateT * v469);
struct StateT * slot_16(struct StateT * v811);
struct StateT * slot_5(struct StateT * v266);
struct StateT * slot_17(struct StateT * v831);
struct StateT * slot_20(struct StateT * v1173);
struct StateT * slot_2(struct StateT * v218);
struct StateT * slot_7(struct StateT * v489);
struct StateT * slot_21(struct StateT * v1181);
struct StateT * slot_3(struct StateT * v226);
struct StateT * snippet(struct StateT * v0);
struct StateT * slot_10(struct StateT * v554);
struct StateT * slot_1(struct StateT * v15);
struct StateT * slot_8(struct StateT * v503);
struct StateT * slot_19(struct StateT * v858);
struct StateT * slot_4(struct StateT * v246);
struct StateT * slot_13(struct StateT * v584);
struct StateT * slot_15(struct StateT * v803);
struct StateT * slot_18(struct StateT * v844);
struct StateT * slot_9(struct StateT * v549);
struct StateT * slot_0(struct StateT * v2);
struct StateT * slot_12(struct StateT * v568) {
  int v569 = v568->timer;
  int v577 = v569 + 1;
  v568->timer = v577;
  int * v571 = v568->regs;
  int v572 = v571[14];
  int v573 = v571[10];
  int v581 = v572 + v573;
  v571[10] = v581;
  struct StateT * v575 = slot_13(v568);
  return v575;
}

struct StateT * slot_14(struct StateT * v787) {
  int v788 = v787->timer;
  int v796 = v788 + 1;
  v787->timer = v796;
  int * v790 = v787->regs;
  int v791 = v790[12];
  int v792 = v790[10];
  int v800 = v791 & v792;
  v790[12] = v800;
  struct StateT * v794 = slot_15(v787);
  return v794;
}

struct StateT * slot_6(struct StateT * v469) {
  int * v470 = v469->saved_regs;
  int * v471 = v469->regs;
  int v472 = v471[14];
  v470[14] = v472;
  int v474 = v469->timer;
  int v484 = v474 + 1;
  v469->timer = v484;
  int * v476 = v469->regs;
  v476[14] = 0;
  struct StateT * v478 = slot_7(v469);
  return v478;
}

struct StateT * slot_16(struct StateT * v811) {
  int * v812 = v811->regs;
  int v813 = v812[13];
  bool v824 = !(v813 == 0);
  struct StateT * v820;
  if (v824) {
    int v814 = v811->timer;
    int v825 = v814 + 15;
    v811->timer = v825;
    struct StateT * v816 = slot_17(v811);
    v820 = v816;
  } else {
    struct StateT * v818 = slot_18(v811);
    v820 = v818;
  }
  return v820;
}

struct StateT * slot_5(struct StateT * v266) {
  int v267 = v266->timer;
  int v377 = v267 + 1;
  v266->timer = v377;
  int * v269 = v266->regs;
  int v270 = v269[12];
  int * v271 = v266->cache_tags;
  int v381 = (((int)((unsigned int)((int)((unsigned int)(v270 + 68) >> 2)) >> 1)) & 1) * 2;
  int v272 = v271[v381];
  int v382 = ((((int)((unsigned int)((int)((unsigned int)(v270 + 68) >> 2)) >> 1)) & 1) * 2) + 1;
  int v273 = v271[v382];
  int v383 = 4 + ((((int)((unsigned int)((int)((unsigned int)(v270 + 68) >> 2)) >> 1)) & 3) * 2);
  int v274 = v271[v383];
  int v384 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v270 + 68) >> 2)) >> 1)) & 3) * 2)) + 1;
  int v275 = v271[v384];
  int v276 = v266->timer;
  int v385 = v276 + ((100 ^ (((~(((v274 ^ ((int)((unsigned int)((int)((unsigned int)(v270 + 68) >> 2)) >> 1))) | (-(v274 ^ ((int)((unsigned int)((int)((unsigned int)(v270 + 68) >> 2)) >> 1))))) >> 31)) | (~(((v275 ^ ((int)((unsigned int)((int)((unsigned int)(v270 + 68) >> 2)) >> 1))) | (-(v275 ^ ((int)((unsigned int)((int)((unsigned int)(v270 + 68) >> 2)) >> 1))))) >> 31))) & 104)) ^ (((~(((v272 ^ ((int)((unsigned int)((int)((unsigned int)(v270 + 68) >> 2)) >> 1))) | (-(v272 ^ ((int)((unsigned int)((int)((unsigned int)(v270 + 68) >> 2)) >> 1))))) >> 31)) | (~(((v273 ^ ((int)((unsigned int)((int)((unsigned int)(v270 + 68) >> 2)) >> 1))) | (-(v273 ^ ((int)((unsigned int)((int)((unsigned int)(v270 + 68) >> 2)) >> 1))))) >> 31))) & (1 ^ (100 ^ (((~(((v274 ^ ((int)((unsigned int)((int)((unsigned int)(v270 + 68) >> 2)) >> 1))) | (-(v274 ^ ((int)((unsigned int)((int)((unsigned int)(v270 + 68) >> 2)) >> 1))))) >> 31)) | (~(((v275 ^ ((int)((unsigned int)((int)((unsigned int)(v270 + 68) >> 2)) >> 1))) | (-(v275 ^ ((int)((unsigned int)((int)((unsigned int)(v270 + 68) >> 2)) >> 1))))) >> 31))) & 104)))));
  v266->timer = v385;
  int * v278 = v266->cache_vals;
  bool v386 = !(((~(((v272 ^ ((int)((unsigned int)((int)((unsigned int)(v270 + 68) >> 2)) >> 1))) | (-(v272 ^ ((int)((unsigned int)((int)((unsigned int)(v270 + 68) >> 2)) >> 1))))) >> 31)) | (~(((v273 ^ ((int)((unsigned int)((int)((unsigned int)(v270 + 68) >> 2)) >> 1))) | (-(v273 ^ ((int)((unsigned int)((int)((unsigned int)(v270 + 68) >> 2)) >> 1))))) >> 31))) == 0);
  int v371;
  if (v386) {
    int * v279 = v266->cache_age;
    int v388 = ((((int)((unsigned int)((int)((unsigned int)(v270 + 68) >> 2)) >> 1)) & 1) * 2) + ((~(((v273 ^ ((int)((unsigned int)((int)((unsigned int)(v270 + 68) >> 2)) >> 1))) | (-(v273 ^ ((int)((unsigned int)((int)((unsigned int)(v270 + 68) >> 2)) >> 1))))) >> 31)) & 1);
    int v280 = v279[v388];
    int v281 = v279[v381];
    int v389 = v281 + ((int)((unsigned int)(v281 - v280) >> 31));
    v279[v381] = v389;
    int * v283 = v266->cache_age;
    int v284 = v283[v382];
    int v391 = v284 + ((int)((unsigned int)(v284 - v280) >> 31));
    v283[v382] = v391;
    int * v286 = v266->cache_age;
    v286[v388] = 0;
    v371 = v388;
  } else {
    int * v289 = v266->cache_age;
    int v395 = (((int)((unsigned int)((int)((unsigned int)(v270 + 68) >> 2)) >> 1)) & 1) * 2;
    int v290 = v289[v395];
    int * v291 = v266->cache_tags;
    int v292 = v291[v395];
    int v293 = v289[v382];
    int v294 = v291[v382];
    bool v397 = !(((~(((v274 ^ ((int)((unsigned int)((int)((unsigned int)(v270 + 68) >> 2)) >> 1))) | (-(v274 ^ ((int)((unsigned int)((int)((unsigned int)(v270 + 68) >> 2)) >> 1))))) >> 31)) | (~(((v275 ^ ((int)((unsigned int)((int)((unsigned int)(v270 + 68) >> 2)) >> 1))) | (-(v275 ^ ((int)((unsigned int)((int)((unsigned int)(v270 + 68) >> 2)) >> 1))))) >> 31))) == 0);
    int v348;
    if (v397) {
      int * v295 = v266->cache_age;
      int v399 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v270 + 68) >> 2)) >> 1)) & 3) * 2)) + ((~(((v275 ^ ((int)((unsigned int)((int)((unsigned int)(v270 + 68) >> 2)) >> 1))) | (-(v275 ^ ((int)((unsigned int)((int)((unsigned int)(v270 + 68) >> 2)) >> 1))))) >> 31)) & 1);
      int v296 = v295[v399];
      int v297 = v295[v383];
      int v400 = v297 + ((int)((unsigned int)(v297 - v296) >> 31));
      v295[v383] = v400;
      int * v299 = v266->cache_age;
      int v300 = v299[v384];
      int v402 = v300 + ((int)((unsigned int)(v300 - v296) >> 31));
      v299[v384] = v402;
      int * v302 = v266->cache_age;
      v302[v399] = 0;
      v348 = v399;
    } else {
      int * v305 = v266->cache_age;
      int v406 = 4 + ((((int)((unsigned int)((int)((unsigned int)(v270 + 68) >> 2)) >> 1)) & 3) * 2);
      int v306 = v305[v406];
      int * v307 = v266->cache_tags;
      int v308 = v307[v406];
      int v309 = v305[v384];
      int v310 = v307[v384];
      int * v311 = v266->cache_dirty;
      int v409 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v270 + 68) >> 2)) >> 1)) & 3) * 2)) + ((((v306 + ((~(((v308 ^ -1) | (-(v308 ^ -1))) >> 31)) & 2)) - (v309 + ((~(((v310 ^ -1) | (-(v310 ^ -1))) >> 31)) & 2))) >> 31) & 1);
      int v312 = v311[v409];
      bool v410 = !(v312 == 0);
      if (v410) {
        int * v313 = v266->cache_tags;
        int v314 = v313[v409];
        int * v315 = v266->cache_vals;
        int v413 = ((4 + ((((int)((unsigned int)((int)((unsigned int)(v270 + 68) >> 2)) >> 1)) & 3) * 2)) + ((((v306 + ((~(((v308 ^ -1) | (-(v308 ^ -1))) >> 31)) & 2)) - (v309 + ((~(((v310 ^ -1) | (-(v310 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
        int v316 = v315[v413];
        int v414 = (((4 + ((((int)((unsigned int)((int)((unsigned int)(v270 + 68) >> 2)) >> 1)) & 3) * 2)) + ((((v306 + ((~(((v308 ^ -1) | (-(v308 ^ -1))) >> 31)) & 2)) - (v309 + ((~(((v310 ^ -1) | (-(v310 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
        int v317 = v315[v414];
        int * v318 = v266->mem;
        int v416 = v314 * 2;
        v318[v416] = v316;
        int * v320 = v266->mem;
        int v419 = (v314 * 2) + 1;
        v320[v419] = v317;
        ;
      } else {
        ;
      }
      int * v325 = v266->mem;
      int v424 = ((int)((unsigned int)((int)((unsigned int)(v270 + 68) >> 2)) >> 1)) * 2;
      int v326 = v325[v424];
      int v425 = (((int)((unsigned int)((int)((unsigned int)(v270 + 68) >> 2)) >> 1)) * 2) + 1;
      int v327 = v325[v425];
      int * v328 = v266->cache_vals;
      int v427 = ((4 + ((((int)((unsigned int)((int)((unsigned int)(v270 + 68) >> 2)) >> 1)) & 3) * 2)) + ((((v306 + ((~(((v308 ^ -1) | (-(v308 ^ -1))) >> 31)) & 2)) - (v309 + ((~(((v310 ^ -1) | (-(v310 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
      v328[v427] = v326;
      int * v330 = v266->cache_vals;
      int v430 = (((4 + ((((int)((unsigned int)((int)((unsigned int)(v270 + 68) >> 2)) >> 1)) & 3) * 2)) + ((((v306 + ((~(((v308 ^ -1) | (-(v308 ^ -1))) >> 31)) & 2)) - (v309 + ((~(((v310 ^ -1) | (-(v310 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
      v330[v430] = v327;
      int * v332 = v266->cache_tags;
      int v433 = (int)((unsigned int)((int)((unsigned int)(v270 + 68) >> 2)) >> 1);
      v332[v409] = v433;
      int * v334 = v266->cache_dirty;
      v334[v409] = 0;
      int * v336 = v266->cache_age;
      v336[v409] = 1;
      int * v338 = v266->cache_age;
      int v339 = v338[v409];
      int v340 = v338[v383];
      int v439 = v340 + ((int)((unsigned int)(v340 - v339) >> 31));
      v338[v383] = v439;
      int * v342 = v266->cache_age;
      int v343 = v342[v384];
      int v441 = v343 + ((int)((unsigned int)(v343 - v339) >> 31));
      v342[v384] = v441;
      int * v345 = v266->cache_age;
      v345[v409] = 0;
      v348 = v409;
    }
    int * v349 = v266->cache_vals;
    int v444 = v348 * 2;
    int v350 = v349[v444];
    int v445 = (v348 * 2) + 1;
    int v351 = v349[v445];
    int v446 = (((((int)((unsigned int)((int)((unsigned int)(v270 + 68) >> 2)) >> 1)) & 1) * 2) + ((((v290 + ((~(((v292 ^ -1) | (-(v292 ^ -1))) >> 31)) & 2)) - (v293 + ((~(((v294 ^ -1) | (-(v294 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
    v349[v446] = v350;
    int * v353 = v266->cache_vals;
    int v449 = ((((((int)((unsigned int)((int)((unsigned int)(v270 + 68) >> 2)) >> 1)) & 1) * 2) + ((((v290 + ((~(((v292 ^ -1) | (-(v292 ^ -1))) >> 31)) & 2)) - (v293 + ((~(((v294 ^ -1) | (-(v294 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
    v353[v449] = v351;
    int * v355 = v266->cache_tags;
    int v452 = ((((int)((unsigned int)((int)((unsigned int)(v270 + 68) >> 2)) >> 1)) & 1) * 2) + ((((v290 + ((~(((v292 ^ -1) | (-(v292 ^ -1))) >> 31)) & 2)) - (v293 + ((~(((v294 ^ -1) | (-(v294 ^ -1))) >> 31)) & 2))) >> 31) & 1);
    int v453 = (int)((unsigned int)((int)((unsigned int)(v270 + 68) >> 2)) >> 1);
    v355[v452] = v453;
    int * v357 = v266->cache_dirty;
    v357[v452] = 0;
    int * v359 = v266->cache_age;
    v359[v452] = 1;
    int * v361 = v266->cache_age;
    int v362 = v361[v452];
    int v363 = v361[v381];
    int v459 = v363 + ((int)((unsigned int)(v363 - v362) >> 31));
    v361[v381] = v459;
    int * v365 = v266->cache_age;
    int v366 = v365[v382];
    int v461 = v366 + ((int)((unsigned int)(v366 - v362) >> 31));
    v365[v382] = v461;
    int * v368 = v266->cache_age;
    v368[v452] = 0;
    v371 = v452;
  }
  int v464 = (v371 * 2) + (((int)((unsigned int)(v270 + 68) >> 2)) & 1);
  int v372 = v278[v464];
  int * v373 = v266->regs;
  v373[12] = v372;
  struct StateT * v375 = slot_6(v266);
  return v375;
}

struct StateT * slot_17(struct StateT * v831) {
  int v832 = v831->timer;
  int v838 = v832 + 1;
  v831->timer = v838;
  int * v834 = v831->regs;
  v834[10] = 0;
  struct StateT * v836 = slot_19(v831);
  return v836;
}

struct StateT * slot_20(struct StateT * v1173) {
  int v1174 = v1173->timer;
  int v1178 = v1174 + 1;
  v1173->timer = v1178;
  struct StateT * v1176 = slot_21(v1173);
  return v1176;
}

struct StateT * slot_2(struct StateT * v218) {
  int v219 = v218->timer;
  int v223 = v219 + 1;
  v218->timer = v223;
  struct StateT * v221 = slot_3(v218);
  return v221;
}

struct StateT * slot_7(struct StateT * v489) {
  int v490 = v489->timer;
  int v497 = v490 + 1;
  v489->timer = v497;
  int * v492 = v489->regs;
  int v493 = v492[14];
  int v500 = v493 + 72;
  v492[14] = v500;
  struct StateT * v495 = slot_8(v489);
  return v495;
}

struct StateT * slot_21(struct StateT * v1181) {
  int * v1182 = v1181->regs;
  int v1183 = v1182[10];
  int v1184 = v1182[11];
  bool v1196 = (v1183 ^ -2147483648) < (v1184 ^ -2147483648);
  struct StateT * v1191;
  if (v1196) {
    int v1185 = v1181->timer;
    int v1197 = v1185 + 15;
    v1181->timer = v1197;
    struct StateT * v1187 = slot_10(v1181);
    v1191 = v1187;
  } else {
    struct StateT * v1189 = slot_17(v1181);
    v1191 = v1189;
  }
  return v1191;
}

struct StateT * slot_3(struct StateT * v226) {
  int * v227 = v226->saved_regs;
  int * v228 = v226->regs;
  int v229 = v228[13];
  v227[13] = v229;
  int v231 = v226->timer;
  int v241 = v231 + 1;
  v226->timer = v241;
  int * v233 = v226->regs;
  v233[13] = 0;
  struct StateT * v235 = slot_4(v226);
  return v235;
}

struct StateT * snippet(struct StateT * v0) {
  struct StateT * v1 = slot_0(v0);
  return v1;
}

struct StateT * slot_10(struct StateT * v554) {
  int v555 = v554->timer;
  int v562 = v555 + 1;
  v554->timer = v562;
  int * v557 = v554->regs;
  int v558 = v557[10];
  int v565 = v558 << 2;
  v557[10] = v565;
  struct StateT * v560 = slot_12(v554);
  return v560;
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

struct StateT * slot_8(struct StateT * v503) {
  int * v504 = v503->regs;
  int v505 = v504[10];
  int v506 = v504[11];
  bool v530 = (v505 ^ -2147483648) >= (v506 ^ -2147483648);
  struct StateT * v525;
  if (v530) {
    int v507 = v503->timer;
    int v531 = v507 + 15;
    v503->timer = v531;
    int * v509 = v503->saved_regs;
    int v510 = v509[13];
    int * v511 = v503->regs;
    v511[13] = v510;
    int * v513 = v503->saved_regs;
    int v514 = v513[12];
    int * v515 = v503->regs;
    v515[12] = v514;
    int * v517 = v503->saved_regs;
    int v518 = v517[14];
    int * v519 = v503->regs;
    v519[14] = v518;
    struct StateT * v521 = slot_9(v503);
    v525 = v521;
  } else {
    struct StateT * v523 = slot_10(v503);
    v525 = v523;
  }
  return v525;
}

struct StateT * slot_19(struct StateT * v858) {
  int v859 = v858->timer;
  int v1029 = v859 + 1;
  v858->timer = v1029;
  int * v861 = v858->regs;
  int v862 = v861[10];
  int v863 = v861[12];
  int * v864 = v858->cache_tags;
  int v1034 = (((int)((unsigned int)((int)((unsigned int)(v862 + 68) >> 2)) >> 1)) & 1) * 2;
  int v865 = v864[v1034];
  int v1035 = ((((int)((unsigned int)((int)((unsigned int)(v862 + 68) >> 2)) >> 1)) & 1) * 2) + 1;
  int v866 = v864[v1035];
  int v1036 = 4 + ((((int)((unsigned int)((int)((unsigned int)(v862 + 68) >> 2)) >> 1)) & 3) * 2);
  int v867 = v864[v1036];
  int v1037 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v862 + 68) >> 2)) >> 1)) & 3) * 2)) + 1;
  int v868 = v864[v1037];
  int v869 = v858->timer;
  int v1038 = v869 + ((100 ^ (((~(((v867 ^ ((int)((unsigned int)((int)((unsigned int)(v862 + 68) >> 2)) >> 1))) | (-(v867 ^ ((int)((unsigned int)((int)((unsigned int)(v862 + 68) >> 2)) >> 1))))) >> 31)) | (~(((v868 ^ ((int)((unsigned int)((int)((unsigned int)(v862 + 68) >> 2)) >> 1))) | (-(v868 ^ ((int)((unsigned int)((int)((unsigned int)(v862 + 68) >> 2)) >> 1))))) >> 31))) & 104)) ^ (((~(((v865 ^ ((int)((unsigned int)((int)((unsigned int)(v862 + 68) >> 2)) >> 1))) | (-(v865 ^ ((int)((unsigned int)((int)((unsigned int)(v862 + 68) >> 2)) >> 1))))) >> 31)) | (~(((v866 ^ ((int)((unsigned int)((int)((unsigned int)(v862 + 68) >> 2)) >> 1))) | (-(v866 ^ ((int)((unsigned int)((int)((unsigned int)(v862 + 68) >> 2)) >> 1))))) >> 31))) & (1 ^ (100 ^ (((~(((v867 ^ ((int)((unsigned int)((int)((unsigned int)(v862 + 68) >> 2)) >> 1))) | (-(v867 ^ ((int)((unsigned int)((int)((unsigned int)(v862 + 68) >> 2)) >> 1))))) >> 31)) | (~(((v868 ^ ((int)((unsigned int)((int)((unsigned int)(v862 + 68) >> 2)) >> 1))) | (-(v868 ^ ((int)((unsigned int)((int)((unsigned int)(v862 + 68) >> 2)) >> 1))))) >> 31))) & 104)))));
  v858->timer = v1038;
  bool v1039 = !(((~(((v865 ^ ((int)((unsigned int)((int)((unsigned int)(v862 + 68) >> 2)) >> 1))) | (-(v865 ^ ((int)((unsigned int)((int)((unsigned int)(v862 + 68) >> 2)) >> 1))))) >> 31)) | (~(((v866 ^ ((int)((unsigned int)((int)((unsigned int)(v862 + 68) >> 2)) >> 1))) | (-(v866 ^ ((int)((unsigned int)((int)((unsigned int)(v862 + 68) >> 2)) >> 1))))) >> 31))) == 0);
  int v963;
  if (v1039) {
    int * v871 = v858->cache_age;
    int v1041 = ((((int)((unsigned int)((int)((unsigned int)(v862 + 68) >> 2)) >> 1)) & 1) * 2) + ((~(((v866 ^ ((int)((unsigned int)((int)((unsigned int)(v862 + 68) >> 2)) >> 1))) | (-(v866 ^ ((int)((unsigned int)((int)((unsigned int)(v862 + 68) >> 2)) >> 1))))) >> 31)) & 1);
    int v872 = v871[v1041];
    int v873 = v871[v1034];
    int v1042 = v873 + ((int)((unsigned int)(v873 - v872) >> 31));
    v871[v1034] = v1042;
    int * v875 = v858->cache_age;
    int v876 = v875[v1035];
    int v1044 = v876 + ((int)((unsigned int)(v876 - v872) >> 31));
    v875[v1035] = v1044;
    int * v878 = v858->cache_age;
    v878[v1041] = 0;
    v963 = v1041;
  } else {
    int * v881 = v858->cache_age;
    int v1048 = (((int)((unsigned int)((int)((unsigned int)(v862 + 68) >> 2)) >> 1)) & 1) * 2;
    int v882 = v881[v1048];
    int * v883 = v858->cache_tags;
    int v884 = v883[v1048];
    int v885 = v881[v1035];
    int v886 = v883[v1035];
    bool v1050 = !(((~(((v867 ^ ((int)((unsigned int)((int)((unsigned int)(v862 + 68) >> 2)) >> 1))) | (-(v867 ^ ((int)((unsigned int)((int)((unsigned int)(v862 + 68) >> 2)) >> 1))))) >> 31)) | (~(((v868 ^ ((int)((unsigned int)((int)((unsigned int)(v862 + 68) >> 2)) >> 1))) | (-(v868 ^ ((int)((unsigned int)((int)((unsigned int)(v862 + 68) >> 2)) >> 1))))) >> 31))) == 0);
    int v940;
    if (v1050) {
      int * v887 = v858->cache_age;
      int v1052 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v862 + 68) >> 2)) >> 1)) & 3) * 2)) + ((~(((v868 ^ ((int)((unsigned int)((int)((unsigned int)(v862 + 68) >> 2)) >> 1))) | (-(v868 ^ ((int)((unsigned int)((int)((unsigned int)(v862 + 68) >> 2)) >> 1))))) >> 31)) & 1);
      int v888 = v887[v1052];
      int v889 = v887[v1036];
      int v1053 = v889 + ((int)((unsigned int)(v889 - v888) >> 31));
      v887[v1036] = v1053;
      int * v891 = v858->cache_age;
      int v892 = v891[v1037];
      int v1055 = v892 + ((int)((unsigned int)(v892 - v888) >> 31));
      v891[v1037] = v1055;
      int * v894 = v858->cache_age;
      v894[v1052] = 0;
      v940 = v1052;
    } else {
      int * v897 = v858->cache_age;
      int v1059 = 4 + ((((int)((unsigned int)((int)((unsigned int)(v862 + 68) >> 2)) >> 1)) & 3) * 2);
      int v898 = v897[v1059];
      int * v899 = v858->cache_tags;
      int v900 = v899[v1059];
      int v901 = v897[v1037];
      int v902 = v899[v1037];
      int * v903 = v858->cache_dirty;
      int v1062 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v862 + 68) >> 2)) >> 1)) & 3) * 2)) + ((((v898 + ((~(((v900 ^ -1) | (-(v900 ^ -1))) >> 31)) & 2)) - (v901 + ((~(((v902 ^ -1) | (-(v902 ^ -1))) >> 31)) & 2))) >> 31) & 1);
      int v904 = v903[v1062];
      bool v1063 = !(v904 == 0);
      if (v1063) {
        int * v905 = v858->cache_tags;
        int v906 = v905[v1062];
        int * v907 = v858->cache_vals;
        int v1066 = ((4 + ((((int)((unsigned int)((int)((unsigned int)(v862 + 68) >> 2)) >> 1)) & 3) * 2)) + ((((v898 + ((~(((v900 ^ -1) | (-(v900 ^ -1))) >> 31)) & 2)) - (v901 + ((~(((v902 ^ -1) | (-(v902 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
        int v908 = v907[v1066];
        int v1067 = (((4 + ((((int)((unsigned int)((int)((unsigned int)(v862 + 68) >> 2)) >> 1)) & 3) * 2)) + ((((v898 + ((~(((v900 ^ -1) | (-(v900 ^ -1))) >> 31)) & 2)) - (v901 + ((~(((v902 ^ -1) | (-(v902 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
        int v909 = v907[v1067];
        int * v910 = v858->mem;
        int v1069 = v906 * 2;
        v910[v1069] = v908;
        int * v912 = v858->mem;
        int v1072 = (v906 * 2) + 1;
        v912[v1072] = v909;
        ;
      } else {
        ;
      }
      int * v917 = v858->mem;
      int v1077 = ((int)((unsigned int)((int)((unsigned int)(v862 + 68) >> 2)) >> 1)) * 2;
      int v918 = v917[v1077];
      int v1078 = (((int)((unsigned int)((int)((unsigned int)(v862 + 68) >> 2)) >> 1)) * 2) + 1;
      int v919 = v917[v1078];
      int * v920 = v858->cache_vals;
      int v1080 = ((4 + ((((int)((unsigned int)((int)((unsigned int)(v862 + 68) >> 2)) >> 1)) & 3) * 2)) + ((((v898 + ((~(((v900 ^ -1) | (-(v900 ^ -1))) >> 31)) & 2)) - (v901 + ((~(((v902 ^ -1) | (-(v902 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
      v920[v1080] = v918;
      int * v922 = v858->cache_vals;
      int v1083 = (((4 + ((((int)((unsigned int)((int)((unsigned int)(v862 + 68) >> 2)) >> 1)) & 3) * 2)) + ((((v898 + ((~(((v900 ^ -1) | (-(v900 ^ -1))) >> 31)) & 2)) - (v901 + ((~(((v902 ^ -1) | (-(v902 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
      v922[v1083] = v919;
      int * v924 = v858->cache_tags;
      int v1086 = (int)((unsigned int)((int)((unsigned int)(v862 + 68) >> 2)) >> 1);
      v924[v1062] = v1086;
      int * v926 = v858->cache_dirty;
      v926[v1062] = 0;
      int * v928 = v858->cache_age;
      v928[v1062] = 1;
      int * v930 = v858->cache_age;
      int v931 = v930[v1062];
      int v932 = v930[v1036];
      int v1092 = v932 + ((int)((unsigned int)(v932 - v931) >> 31));
      v930[v1036] = v1092;
      int * v934 = v858->cache_age;
      int v935 = v934[v1037];
      int v1094 = v935 + ((int)((unsigned int)(v935 - v931) >> 31));
      v934[v1037] = v1094;
      int * v937 = v858->cache_age;
      v937[v1062] = 0;
      v940 = v1062;
    }
    int * v941 = v858->cache_vals;
    int v1097 = v940 * 2;
    int v942 = v941[v1097];
    int v1098 = (v940 * 2) + 1;
    int v943 = v941[v1098];
    int v1099 = (((((int)((unsigned int)((int)((unsigned int)(v862 + 68) >> 2)) >> 1)) & 1) * 2) + ((((v882 + ((~(((v884 ^ -1) | (-(v884 ^ -1))) >> 31)) & 2)) - (v885 + ((~(((v886 ^ -1) | (-(v886 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
    v941[v1099] = v942;
    int * v945 = v858->cache_vals;
    int v1102 = ((((((int)((unsigned int)((int)((unsigned int)(v862 + 68) >> 2)) >> 1)) & 1) * 2) + ((((v882 + ((~(((v884 ^ -1) | (-(v884 ^ -1))) >> 31)) & 2)) - (v885 + ((~(((v886 ^ -1) | (-(v886 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
    v945[v1102] = v943;
    int * v947 = v858->cache_tags;
    int v1105 = ((((int)((unsigned int)((int)((unsigned int)(v862 + 68) >> 2)) >> 1)) & 1) * 2) + ((((v882 + ((~(((v884 ^ -1) | (-(v884 ^ -1))) >> 31)) & 2)) - (v885 + ((~(((v886 ^ -1) | (-(v886 ^ -1))) >> 31)) & 2))) >> 31) & 1);
    int v1106 = (int)((unsigned int)((int)((unsigned int)(v862 + 68) >> 2)) >> 1);
    v947[v1105] = v1106;
    int * v949 = v858->cache_dirty;
    v949[v1105] = 0;
    int * v951 = v858->cache_age;
    v951[v1105] = 1;
    int * v953 = v858->cache_age;
    int v954 = v953[v1105];
    int v955 = v953[v1034];
    int v1112 = v955 + ((int)((unsigned int)(v955 - v954) >> 31));
    v953[v1034] = v1112;
    int * v957 = v858->cache_age;
    int v958 = v957[v1035];
    int v1114 = v958 + ((int)((unsigned int)(v958 - v954) >> 31));
    v957[v1035] = v1114;
    int * v960 = v858->cache_age;
    v960[v1105] = 0;
    v963 = v1105;
  }
  int * v964 = v858->cache_vals;
  int v1117 = (v963 * 2) + (((int)((unsigned int)(v862 + 68) >> 2)) & 1);
  v964[v1117] = v863;
  int * v966 = v858->cache_tags;
  int v967 = v966[v1036];
  int v968 = v966[v1037];
  bool v1120 = !(((~(((v967 ^ ((int)((unsigned int)((int)((unsigned int)(v862 + 68) >> 2)) >> 1))) | (-(v967 ^ ((int)((unsigned int)((int)((unsigned int)(v862 + 68) >> 2)) >> 1))))) >> 31)) | (~(((v968 ^ ((int)((unsigned int)((int)((unsigned int)(v862 + 68) >> 2)) >> 1))) | (-(v968 ^ ((int)((unsigned int)((int)((unsigned int)(v862 + 68) >> 2)) >> 1))))) >> 31))) == 0);
  int v1022;
  if (v1120) {
    int * v969 = v858->cache_age;
    int v1122 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v862 + 68) >> 2)) >> 1)) & 3) * 2)) + ((~(((v968 ^ ((int)((unsigned int)((int)((unsigned int)(v862 + 68) >> 2)) >> 1))) | (-(v968 ^ ((int)((unsigned int)((int)((unsigned int)(v862 + 68) >> 2)) >> 1))))) >> 31)) & 1);
    int v970 = v969[v1122];
    int v971 = v969[v1036];
    int v1123 = v971 + ((int)((unsigned int)(v971 - v970) >> 31));
    v969[v1036] = v1123;
    int * v973 = v858->cache_age;
    int v974 = v973[v1037];
    int v1125 = v974 + ((int)((unsigned int)(v974 - v970) >> 31));
    v973[v1037] = v1125;
    int * v976 = v858->cache_age;
    v976[v1122] = 0;
    v1022 = v1122;
  } else {
    int * v979 = v858->cache_age;
    int v1129 = 4 + ((((int)((unsigned int)((int)((unsigned int)(v862 + 68) >> 2)) >> 1)) & 3) * 2);
    int v980 = v979[v1129];
    int * v981 = v858->cache_tags;
    int v982 = v981[v1129];
    int v983 = v979[v1037];
    int v984 = v981[v1037];
    int * v985 = v858->cache_dirty;
    int v1132 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v862 + 68) >> 2)) >> 1)) & 3) * 2)) + ((((v980 + ((~(((v982 ^ -1) | (-(v982 ^ -1))) >> 31)) & 2)) - (v983 + ((~(((v984 ^ -1) | (-(v984 ^ -1))) >> 31)) & 2))) >> 31) & 1);
    int v986 = v985[v1132];
    bool v1133 = !(v986 == 0);
    if (v1133) {
      int * v987 = v858->cache_tags;
      int v988 = v987[v1132];
      int * v989 = v858->cache_vals;
      int v1136 = ((4 + ((((int)((unsigned int)((int)((unsigned int)(v862 + 68) >> 2)) >> 1)) & 3) * 2)) + ((((v980 + ((~(((v982 ^ -1) | (-(v982 ^ -1))) >> 31)) & 2)) - (v983 + ((~(((v984 ^ -1) | (-(v984 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
      int v990 = v989[v1136];
      int v1137 = (((4 + ((((int)((unsigned int)((int)((unsigned int)(v862 + 68) >> 2)) >> 1)) & 3) * 2)) + ((((v980 + ((~(((v982 ^ -1) | (-(v982 ^ -1))) >> 31)) & 2)) - (v983 + ((~(((v984 ^ -1) | (-(v984 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
      int v991 = v989[v1137];
      int * v992 = v858->mem;
      int v1139 = v988 * 2;
      v992[v1139] = v990;
      int * v994 = v858->mem;
      int v1142 = (v988 * 2) + 1;
      v994[v1142] = v991;
      ;
    } else {
      ;
    }
    int * v999 = v858->mem;
    int v1147 = ((int)((unsigned int)((int)((unsigned int)(v862 + 68) >> 2)) >> 1)) * 2;
    int v1000 = v999[v1147];
    int v1148 = (((int)((unsigned int)((int)((unsigned int)(v862 + 68) >> 2)) >> 1)) * 2) + 1;
    int v1001 = v999[v1148];
    int * v1002 = v858->cache_vals;
    int v1150 = ((4 + ((((int)((unsigned int)((int)((unsigned int)(v862 + 68) >> 2)) >> 1)) & 3) * 2)) + ((((v980 + ((~(((v982 ^ -1) | (-(v982 ^ -1))) >> 31)) & 2)) - (v983 + ((~(((v984 ^ -1) | (-(v984 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
    v1002[v1150] = v1000;
    int * v1004 = v858->cache_vals;
    int v1153 = (((4 + ((((int)((unsigned int)((int)((unsigned int)(v862 + 68) >> 2)) >> 1)) & 3) * 2)) + ((((v980 + ((~(((v982 ^ -1) | (-(v982 ^ -1))) >> 31)) & 2)) - (v983 + ((~(((v984 ^ -1) | (-(v984 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
    v1004[v1153] = v1001;
    int * v1006 = v858->cache_tags;
    int v1156 = (int)((unsigned int)((int)((unsigned int)(v862 + 68) >> 2)) >> 1);
    v1006[v1132] = v1156;
    int * v1008 = v858->cache_dirty;
    v1008[v1132] = 0;
    int * v1010 = v858->cache_age;
    v1010[v1132] = 1;
    int * v1012 = v858->cache_age;
    int v1013 = v1012[v1132];
    int v1014 = v1012[v1036];
    int v1162 = v1014 + ((int)((unsigned int)(v1014 - v1013) >> 31));
    v1012[v1036] = v1162;
    int * v1016 = v858->cache_age;
    int v1017 = v1016[v1037];
    int v1164 = v1017 + ((int)((unsigned int)(v1017 - v1013) >> 31));
    v1016[v1037] = v1164;
    int * v1019 = v858->cache_age;
    v1019[v1132] = 0;
    v1022 = v1132;
  }
  int * v1023 = v858->cache_vals;
  int v1167 = (v1022 * 2) + (((int)((unsigned int)(v862 + 68) >> 2)) & 1);
  v1023[v1167] = v863;
  int * v1025 = v858->cache_dirty;
  v1025[v1022] = 1;
  struct StateT * v1027 = slot_9(v858);
  return v1027;
}

struct StateT * slot_4(struct StateT * v246) {
  int * v247 = v246->saved_regs;
  int * v248 = v246->regs;
  int v249 = v248[12];
  v247[12] = v249;
  int v251 = v246->timer;
  int v261 = v251 + 1;
  v246->timer = v261;
  int * v253 = v246->regs;
  v253[12] = 0;
  struct StateT * v255 = slot_5(v246);
  return v255;
}

struct StateT * slot_13(struct StateT * v584) {
  int v585 = v584->timer;
  int v695 = v585 + 1;
  v584->timer = v695;
  int * v587 = v584->regs;
  int v588 = v587[10];
  int * v589 = v584->cache_tags;
  int v699 = (((int)((unsigned int)((int)((unsigned int)v588 >> 2)) >> 1)) & 1) * 2;
  int v590 = v589[v699];
  int v700 = ((((int)((unsigned int)((int)((unsigned int)v588 >> 2)) >> 1)) & 1) * 2) + 1;
  int v591 = v589[v700];
  int v701 = 4 + ((((int)((unsigned int)((int)((unsigned int)v588 >> 2)) >> 1)) & 3) * 2);
  int v592 = v589[v701];
  int v702 = (4 + ((((int)((unsigned int)((int)((unsigned int)v588 >> 2)) >> 1)) & 3) * 2)) + 1;
  int v593 = v589[v702];
  int v594 = v584->timer;
  int v703 = v594 + ((100 ^ (((~(((v592 ^ ((int)((unsigned int)((int)((unsigned int)v588 >> 2)) >> 1))) | (-(v592 ^ ((int)((unsigned int)((int)((unsigned int)v588 >> 2)) >> 1))))) >> 31)) | (~(((v593 ^ ((int)((unsigned int)((int)((unsigned int)v588 >> 2)) >> 1))) | (-(v593 ^ ((int)((unsigned int)((int)((unsigned int)v588 >> 2)) >> 1))))) >> 31))) & 104)) ^ (((~(((v590 ^ ((int)((unsigned int)((int)((unsigned int)v588 >> 2)) >> 1))) | (-(v590 ^ ((int)((unsigned int)((int)((unsigned int)v588 >> 2)) >> 1))))) >> 31)) | (~(((v591 ^ ((int)((unsigned int)((int)((unsigned int)v588 >> 2)) >> 1))) | (-(v591 ^ ((int)((unsigned int)((int)((unsigned int)v588 >> 2)) >> 1))))) >> 31))) & (1 ^ (100 ^ (((~(((v592 ^ ((int)((unsigned int)((int)((unsigned int)v588 >> 2)) >> 1))) | (-(v592 ^ ((int)((unsigned int)((int)((unsigned int)v588 >> 2)) >> 1))))) >> 31)) | (~(((v593 ^ ((int)((unsigned int)((int)((unsigned int)v588 >> 2)) >> 1))) | (-(v593 ^ ((int)((unsigned int)((int)((unsigned int)v588 >> 2)) >> 1))))) >> 31))) & 104)))));
  v584->timer = v703;
  int * v596 = v584->cache_vals;
  bool v704 = !(((~(((v590 ^ ((int)((unsigned int)((int)((unsigned int)v588 >> 2)) >> 1))) | (-(v590 ^ ((int)((unsigned int)((int)((unsigned int)v588 >> 2)) >> 1))))) >> 31)) | (~(((v591 ^ ((int)((unsigned int)((int)((unsigned int)v588 >> 2)) >> 1))) | (-(v591 ^ ((int)((unsigned int)((int)((unsigned int)v588 >> 2)) >> 1))))) >> 31))) == 0);
  int v689;
  if (v704) {
    int * v597 = v584->cache_age;
    int v706 = ((((int)((unsigned int)((int)((unsigned int)v588 >> 2)) >> 1)) & 1) * 2) + ((~(((v591 ^ ((int)((unsigned int)((int)((unsigned int)v588 >> 2)) >> 1))) | (-(v591 ^ ((int)((unsigned int)((int)((unsigned int)v588 >> 2)) >> 1))))) >> 31)) & 1);
    int v598 = v597[v706];
    int v599 = v597[v699];
    int v707 = v599 + ((int)((unsigned int)(v599 - v598) >> 31));
    v597[v699] = v707;
    int * v601 = v584->cache_age;
    int v602 = v601[v700];
    int v709 = v602 + ((int)((unsigned int)(v602 - v598) >> 31));
    v601[v700] = v709;
    int * v604 = v584->cache_age;
    v604[v706] = 0;
    v689 = v706;
  } else {
    int * v607 = v584->cache_age;
    int v713 = (((int)((unsigned int)((int)((unsigned int)v588 >> 2)) >> 1)) & 1) * 2;
    int v608 = v607[v713];
    int * v609 = v584->cache_tags;
    int v610 = v609[v713];
    int v611 = v607[v700];
    int v612 = v609[v700];
    bool v715 = !(((~(((v592 ^ ((int)((unsigned int)((int)((unsigned int)v588 >> 2)) >> 1))) | (-(v592 ^ ((int)((unsigned int)((int)((unsigned int)v588 >> 2)) >> 1))))) >> 31)) | (~(((v593 ^ ((int)((unsigned int)((int)((unsigned int)v588 >> 2)) >> 1))) | (-(v593 ^ ((int)((unsigned int)((int)((unsigned int)v588 >> 2)) >> 1))))) >> 31))) == 0);
    int v666;
    if (v715) {
      int * v613 = v584->cache_age;
      int v717 = (4 + ((((int)((unsigned int)((int)((unsigned int)v588 >> 2)) >> 1)) & 3) * 2)) + ((~(((v593 ^ ((int)((unsigned int)((int)((unsigned int)v588 >> 2)) >> 1))) | (-(v593 ^ ((int)((unsigned int)((int)((unsigned int)v588 >> 2)) >> 1))))) >> 31)) & 1);
      int v614 = v613[v717];
      int v615 = v613[v701];
      int v718 = v615 + ((int)((unsigned int)(v615 - v614) >> 31));
      v613[v701] = v718;
      int * v617 = v584->cache_age;
      int v618 = v617[v702];
      int v720 = v618 + ((int)((unsigned int)(v618 - v614) >> 31));
      v617[v702] = v720;
      int * v620 = v584->cache_age;
      v620[v717] = 0;
      v666 = v717;
    } else {
      int * v623 = v584->cache_age;
      int v724 = 4 + ((((int)((unsigned int)((int)((unsigned int)v588 >> 2)) >> 1)) & 3) * 2);
      int v624 = v623[v724];
      int * v625 = v584->cache_tags;
      int v626 = v625[v724];
      int v627 = v623[v702];
      int v628 = v625[v702];
      int * v629 = v584->cache_dirty;
      int v727 = (4 + ((((int)((unsigned int)((int)((unsigned int)v588 >> 2)) >> 1)) & 3) * 2)) + ((((v624 + ((~(((v626 ^ -1) | (-(v626 ^ -1))) >> 31)) & 2)) - (v627 + ((~(((v628 ^ -1) | (-(v628 ^ -1))) >> 31)) & 2))) >> 31) & 1);
      int v630 = v629[v727];
      bool v728 = !(v630 == 0);
      if (v728) {
        int * v631 = v584->cache_tags;
        int v632 = v631[v727];
        int * v633 = v584->cache_vals;
        int v731 = ((4 + ((((int)((unsigned int)((int)((unsigned int)v588 >> 2)) >> 1)) & 3) * 2)) + ((((v624 + ((~(((v626 ^ -1) | (-(v626 ^ -1))) >> 31)) & 2)) - (v627 + ((~(((v628 ^ -1) | (-(v628 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
        int v634 = v633[v731];
        int v732 = (((4 + ((((int)((unsigned int)((int)((unsigned int)v588 >> 2)) >> 1)) & 3) * 2)) + ((((v624 + ((~(((v626 ^ -1) | (-(v626 ^ -1))) >> 31)) & 2)) - (v627 + ((~(((v628 ^ -1) | (-(v628 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
        int v635 = v633[v732];
        int * v636 = v584->mem;
        int v734 = v632 * 2;
        v636[v734] = v634;
        int * v638 = v584->mem;
        int v737 = (v632 * 2) + 1;
        v638[v737] = v635;
        ;
      } else {
        ;
      }
      int * v643 = v584->mem;
      int v742 = ((int)((unsigned int)((int)((unsigned int)v588 >> 2)) >> 1)) * 2;
      int v644 = v643[v742];
      int v743 = (((int)((unsigned int)((int)((unsigned int)v588 >> 2)) >> 1)) * 2) + 1;
      int v645 = v643[v743];
      int * v646 = v584->cache_vals;
      int v745 = ((4 + ((((int)((unsigned int)((int)((unsigned int)v588 >> 2)) >> 1)) & 3) * 2)) + ((((v624 + ((~(((v626 ^ -1) | (-(v626 ^ -1))) >> 31)) & 2)) - (v627 + ((~(((v628 ^ -1) | (-(v628 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
      v646[v745] = v644;
      int * v648 = v584->cache_vals;
      int v748 = (((4 + ((((int)((unsigned int)((int)((unsigned int)v588 >> 2)) >> 1)) & 3) * 2)) + ((((v624 + ((~(((v626 ^ -1) | (-(v626 ^ -1))) >> 31)) & 2)) - (v627 + ((~(((v628 ^ -1) | (-(v628 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
      v648[v748] = v645;
      int * v650 = v584->cache_tags;
      int v751 = (int)((unsigned int)((int)((unsigned int)v588 >> 2)) >> 1);
      v650[v727] = v751;
      int * v652 = v584->cache_dirty;
      v652[v727] = 0;
      int * v654 = v584->cache_age;
      v654[v727] = 1;
      int * v656 = v584->cache_age;
      int v657 = v656[v727];
      int v658 = v656[v701];
      int v757 = v658 + ((int)((unsigned int)(v658 - v657) >> 31));
      v656[v701] = v757;
      int * v660 = v584->cache_age;
      int v661 = v660[v702];
      int v759 = v661 + ((int)((unsigned int)(v661 - v657) >> 31));
      v660[v702] = v759;
      int * v663 = v584->cache_age;
      v663[v727] = 0;
      v666 = v727;
    }
    int * v667 = v584->cache_vals;
    int v762 = v666 * 2;
    int v668 = v667[v762];
    int v763 = (v666 * 2) + 1;
    int v669 = v667[v763];
    int v764 = (((((int)((unsigned int)((int)((unsigned int)v588 >> 2)) >> 1)) & 1) * 2) + ((((v608 + ((~(((v610 ^ -1) | (-(v610 ^ -1))) >> 31)) & 2)) - (v611 + ((~(((v612 ^ -1) | (-(v612 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
    v667[v764] = v668;
    int * v671 = v584->cache_vals;
    int v767 = ((((((int)((unsigned int)((int)((unsigned int)v588 >> 2)) >> 1)) & 1) * 2) + ((((v608 + ((~(((v610 ^ -1) | (-(v610 ^ -1))) >> 31)) & 2)) - (v611 + ((~(((v612 ^ -1) | (-(v612 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
    v671[v767] = v669;
    int * v673 = v584->cache_tags;
    int v770 = ((((int)((unsigned int)((int)((unsigned int)v588 >> 2)) >> 1)) & 1) * 2) + ((((v608 + ((~(((v610 ^ -1) | (-(v610 ^ -1))) >> 31)) & 2)) - (v611 + ((~(((v612 ^ -1) | (-(v612 ^ -1))) >> 31)) & 2))) >> 31) & 1);
    int v771 = (int)((unsigned int)((int)((unsigned int)v588 >> 2)) >> 1);
    v673[v770] = v771;
    int * v675 = v584->cache_dirty;
    v675[v770] = 0;
    int * v677 = v584->cache_age;
    v677[v770] = 1;
    int * v679 = v584->cache_age;
    int v680 = v679[v770];
    int v681 = v679[v699];
    int v777 = v681 + ((int)((unsigned int)(v681 - v680) >> 31));
    v679[v699] = v777;
    int * v683 = v584->cache_age;
    int v684 = v683[v700];
    int v779 = v684 + ((int)((unsigned int)(v684 - v680) >> 31));
    v683[v700] = v779;
    int * v686 = v584->cache_age;
    v686[v770] = 0;
    v689 = v770;
  }
  int v782 = (v689 * 2) + (((int)((unsigned int)v588 >> 2)) & 1);
  int v690 = v596[v782];
  int * v691 = v584->regs;
  v691[10] = v690;
  struct StateT * v693 = slot_14(v584);
  return v693;
}

struct StateT * slot_15(struct StateT * v803) {
  int v804 = v803->timer;
  int v808 = v804 + 1;
  v803->timer = v808;
  struct StateT * v806 = slot_16(v803);
  return v806;
}

struct StateT * slot_18(struct StateT * v844) {
  int v845 = v844->timer;
  int v852 = v845 + 1;
  v844->timer = v852;
  int * v847 = v844->regs;
  int v848 = v847[13];
  int v855 = v848 + -1;
  v847[13] = v855;
  struct StateT * v850 = slot_20(v844);
  return v850;
}

struct StateT * slot_9(struct StateT * v549) {
  int v550 = v549->timer;
  int v553 = v550 + 1;
  v549->timer = v553;
  return v549;
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