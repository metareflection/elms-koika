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

struct StateT * slot_12(struct StateT * v584);
struct StateT * slot_14(struct StateT * v89);
struct StateT * slot_6(struct StateT * v109);
struct StateT * slot_5(struct StateT * v67);
struct StateT * slot_2(struct StateT * v28);
struct StateT * slot_7(struct StateT * v126);
struct StateT * slot_3(struct StateT * v41);
struct StateT * snippet(struct StateT * v0);
struct StateT * slot_10(struct StateT * v551);
struct StateT * slot_1(struct StateT * v15);
struct StateT * slot_8(struct StateT * v330);
struct StateT * slot_4(struct StateT * v54);
struct StateT * slot_13(struct StateT * v598);
struct StateT * slot_9(struct StateT * v347);
struct StateT * slot_11(struct StateT * v568);
struct StateT * slot_0(struct StateT * v2);
struct StateT * slot_12(struct StateT * v584) {
  int v585 = v584->timer;
  int v592 = v585 + 1;
  v584->timer = v592;
  int * v587 = v584->regs;
  int v588 = v587[14];
  int v595 = v588 + 4;
  v587[14] = v595;
  struct StateT * v590 = slot_13(v584);
  return v590;
}

struct StateT * slot_14(struct StateT * v89) {
  int v90 = v89->timer;
  int v100 = v90 + 1;
  v89->timer = v100;
  int * v92 = v89->regs;
  int v93 = v92[5];
  bool v103 = (v93 ^ -2147483648) < -2147483647;
  int v96;
  if (v103) {
    v96 = 1;
  } else {
    v96 = 0;
  }
  int * v97 = v89->regs;
  v97[11] = v96;
  return v89;
}

struct StateT * slot_6(struct StateT * v109) {
  int v110 = v109->timer;
  int v118 = v110 + 1;
  v109->timer = v118;
  int * v112 = v109->regs;
  int v113 = v112[12];
  int v114 = v112[14];
  int v123 = v113 + v114;
  v112[6] = v123;
  struct StateT * v116 = slot_7(v109);
  return v116;
}

struct StateT * slot_5(struct StateT * v67) {
  int v68 = v67->timer;
  int v79 = v68 + 1;
  v67->timer = v79;
  int * v70 = v67->regs;
  int v71 = v70[14];
  int v72 = v70[15];
  bool v83 = v71 >= v72;
  struct StateT * v77;
  if (v83) {
    struct StateT * v73 = slot_14(v67);
    v77 = v73;
  } else {
    struct StateT * v75 = slot_6(v67);
    v77 = v75;
  }
  return v77;
}

struct StateT * slot_2(struct StateT * v28) {
  int v29 = v28->timer;
  int v35 = v29 + 1;
  v28->timer = v35;
  int * v31 = v28->regs;
  v31[14] = 0;
  struct StateT * v33 = slot_3(v28);
  return v33;
}

struct StateT * slot_7(struct StateT * v126) {
  int v127 = v126->timer;
  int v237 = v127 + 1;
  v126->timer = v237;
  int * v129 = v126->regs;
  int v130 = v129[6];
  int * v131 = v126->cache_tags;
  int v241 = (((int)((unsigned int)((int)((unsigned int)v130 >> 2)) >> 1)) & 1) * 2;
  int v132 = v131[v241];
  int v242 = ((((int)((unsigned int)((int)((unsigned int)v130 >> 2)) >> 1)) & 1) * 2) + 1;
  int v133 = v131[v242];
  int v243 = 4 + ((((int)((unsigned int)((int)((unsigned int)v130 >> 2)) >> 1)) & 3) * 2);
  int v134 = v131[v243];
  int v244 = (4 + ((((int)((unsigned int)((int)((unsigned int)v130 >> 2)) >> 1)) & 3) * 2)) + 1;
  int v135 = v131[v244];
  int v136 = v126->timer;
  int v245 = v136 + ((100 ^ (((~(((v134 ^ ((int)((unsigned int)((int)((unsigned int)v130 >> 2)) >> 1))) | (-(v134 ^ ((int)((unsigned int)((int)((unsigned int)v130 >> 2)) >> 1))))) >> 31)) | (~(((v135 ^ ((int)((unsigned int)((int)((unsigned int)v130 >> 2)) >> 1))) | (-(v135 ^ ((int)((unsigned int)((int)((unsigned int)v130 >> 2)) >> 1))))) >> 31))) & 104)) ^ (((~(((v132 ^ ((int)((unsigned int)((int)((unsigned int)v130 >> 2)) >> 1))) | (-(v132 ^ ((int)((unsigned int)((int)((unsigned int)v130 >> 2)) >> 1))))) >> 31)) | (~(((v133 ^ ((int)((unsigned int)((int)((unsigned int)v130 >> 2)) >> 1))) | (-(v133 ^ ((int)((unsigned int)((int)((unsigned int)v130 >> 2)) >> 1))))) >> 31))) & (1 ^ (100 ^ (((~(((v134 ^ ((int)((unsigned int)((int)((unsigned int)v130 >> 2)) >> 1))) | (-(v134 ^ ((int)((unsigned int)((int)((unsigned int)v130 >> 2)) >> 1))))) >> 31)) | (~(((v135 ^ ((int)((unsigned int)((int)((unsigned int)v130 >> 2)) >> 1))) | (-(v135 ^ ((int)((unsigned int)((int)((unsigned int)v130 >> 2)) >> 1))))) >> 31))) & 104)))));
  v126->timer = v245;
  int * v138 = v126->cache_vals;
  bool v246 = !(((~(((v132 ^ ((int)((unsigned int)((int)((unsigned int)v130 >> 2)) >> 1))) | (-(v132 ^ ((int)((unsigned int)((int)((unsigned int)v130 >> 2)) >> 1))))) >> 31)) | (~(((v133 ^ ((int)((unsigned int)((int)((unsigned int)v130 >> 2)) >> 1))) | (-(v133 ^ ((int)((unsigned int)((int)((unsigned int)v130 >> 2)) >> 1))))) >> 31))) == 0);
  int v231;
  if (v246) {
    int * v139 = v126->cache_age;
    int v248 = ((((int)((unsigned int)((int)((unsigned int)v130 >> 2)) >> 1)) & 1) * 2) + ((~(((v133 ^ ((int)((unsigned int)((int)((unsigned int)v130 >> 2)) >> 1))) | (-(v133 ^ ((int)((unsigned int)((int)((unsigned int)v130 >> 2)) >> 1))))) >> 31)) & 1);
    int v140 = v139[v248];
    int v141 = v139[v241];
    int v249 = v141 + ((int)((unsigned int)(v141 - v140) >> 31));
    v139[v241] = v249;
    int * v143 = v126->cache_age;
    int v144 = v143[v242];
    int v251 = v144 + ((int)((unsigned int)(v144 - v140) >> 31));
    v143[v242] = v251;
    int * v146 = v126->cache_age;
    v146[v248] = 0;
    v231 = v248;
  } else {
    int * v149 = v126->cache_age;
    int v255 = (((int)((unsigned int)((int)((unsigned int)v130 >> 2)) >> 1)) & 1) * 2;
    int v150 = v149[v255];
    int * v151 = v126->cache_tags;
    int v152 = v151[v255];
    int v153 = v149[v242];
    int v154 = v151[v242];
    bool v257 = !(((~(((v134 ^ ((int)((unsigned int)((int)((unsigned int)v130 >> 2)) >> 1))) | (-(v134 ^ ((int)((unsigned int)((int)((unsigned int)v130 >> 2)) >> 1))))) >> 31)) | (~(((v135 ^ ((int)((unsigned int)((int)((unsigned int)v130 >> 2)) >> 1))) | (-(v135 ^ ((int)((unsigned int)((int)((unsigned int)v130 >> 2)) >> 1))))) >> 31))) == 0);
    int v208;
    if (v257) {
      int * v155 = v126->cache_age;
      int v259 = (4 + ((((int)((unsigned int)((int)((unsigned int)v130 >> 2)) >> 1)) & 3) * 2)) + ((~(((v135 ^ ((int)((unsigned int)((int)((unsigned int)v130 >> 2)) >> 1))) | (-(v135 ^ ((int)((unsigned int)((int)((unsigned int)v130 >> 2)) >> 1))))) >> 31)) & 1);
      int v156 = v155[v259];
      int v157 = v155[v243];
      int v260 = v157 + ((int)((unsigned int)(v157 - v156) >> 31));
      v155[v243] = v260;
      int * v159 = v126->cache_age;
      int v160 = v159[v244];
      int v262 = v160 + ((int)((unsigned int)(v160 - v156) >> 31));
      v159[v244] = v262;
      int * v162 = v126->cache_age;
      v162[v259] = 0;
      v208 = v259;
    } else {
      int * v165 = v126->cache_age;
      int v266 = 4 + ((((int)((unsigned int)((int)((unsigned int)v130 >> 2)) >> 1)) & 3) * 2);
      int v166 = v165[v266];
      int * v167 = v126->cache_tags;
      int v168 = v167[v266];
      int v169 = v165[v244];
      int v170 = v167[v244];
      int * v171 = v126->cache_dirty;
      int v269 = (4 + ((((int)((unsigned int)((int)((unsigned int)v130 >> 2)) >> 1)) & 3) * 2)) + ((((v166 + ((~(((v168 ^ -1) | (-(v168 ^ -1))) >> 31)) & 2)) - (v169 + ((~(((v170 ^ -1) | (-(v170 ^ -1))) >> 31)) & 2))) >> 31) & 1);
      int v172 = v171[v269];
      bool v270 = !(v172 == 0);
      if (v270) {
        int * v173 = v126->cache_tags;
        int v174 = v173[v269];
        int * v175 = v126->cache_vals;
        int v273 = ((4 + ((((int)((unsigned int)((int)((unsigned int)v130 >> 2)) >> 1)) & 3) * 2)) + ((((v166 + ((~(((v168 ^ -1) | (-(v168 ^ -1))) >> 31)) & 2)) - (v169 + ((~(((v170 ^ -1) | (-(v170 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
        int v176 = v175[v273];
        int v274 = (((4 + ((((int)((unsigned int)((int)((unsigned int)v130 >> 2)) >> 1)) & 3) * 2)) + ((((v166 + ((~(((v168 ^ -1) | (-(v168 ^ -1))) >> 31)) & 2)) - (v169 + ((~(((v170 ^ -1) | (-(v170 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
        int v177 = v175[v274];
        int * v178 = v126->mem;
        int v276 = v174 * 2;
        v178[v276] = v176;
        int * v180 = v126->mem;
        int v279 = (v174 * 2) + 1;
        v180[v279] = v177;
        ;
      } else {
        ;
      }
      int * v185 = v126->mem;
      int v284 = ((int)((unsigned int)((int)((unsigned int)v130 >> 2)) >> 1)) * 2;
      int v186 = v185[v284];
      int v285 = (((int)((unsigned int)((int)((unsigned int)v130 >> 2)) >> 1)) * 2) + 1;
      int v187 = v185[v285];
      int * v188 = v126->cache_vals;
      int v287 = ((4 + ((((int)((unsigned int)((int)((unsigned int)v130 >> 2)) >> 1)) & 3) * 2)) + ((((v166 + ((~(((v168 ^ -1) | (-(v168 ^ -1))) >> 31)) & 2)) - (v169 + ((~(((v170 ^ -1) | (-(v170 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
      v188[v287] = v186;
      int * v190 = v126->cache_vals;
      int v290 = (((4 + ((((int)((unsigned int)((int)((unsigned int)v130 >> 2)) >> 1)) & 3) * 2)) + ((((v166 + ((~(((v168 ^ -1) | (-(v168 ^ -1))) >> 31)) & 2)) - (v169 + ((~(((v170 ^ -1) | (-(v170 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
      v190[v290] = v187;
      int * v192 = v126->cache_tags;
      int v293 = (int)((unsigned int)((int)((unsigned int)v130 >> 2)) >> 1);
      v192[v269] = v293;
      int * v194 = v126->cache_dirty;
      v194[v269] = 0;
      int * v196 = v126->cache_age;
      v196[v269] = 1;
      int * v198 = v126->cache_age;
      int v199 = v198[v269];
      int v200 = v198[v243];
      int v299 = v200 + ((int)((unsigned int)(v200 - v199) >> 31));
      v198[v243] = v299;
      int * v202 = v126->cache_age;
      int v203 = v202[v244];
      int v301 = v203 + ((int)((unsigned int)(v203 - v199) >> 31));
      v202[v244] = v301;
      int * v205 = v126->cache_age;
      v205[v269] = 0;
      v208 = v269;
    }
    int * v209 = v126->cache_vals;
    int v304 = v208 * 2;
    int v210 = v209[v304];
    int v305 = (v208 * 2) + 1;
    int v211 = v209[v305];
    int v306 = (((((int)((unsigned int)((int)((unsigned int)v130 >> 2)) >> 1)) & 1) * 2) + ((((v150 + ((~(((v152 ^ -1) | (-(v152 ^ -1))) >> 31)) & 2)) - (v153 + ((~(((v154 ^ -1) | (-(v154 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
    v209[v306] = v210;
    int * v213 = v126->cache_vals;
    int v309 = ((((((int)((unsigned int)((int)((unsigned int)v130 >> 2)) >> 1)) & 1) * 2) + ((((v150 + ((~(((v152 ^ -1) | (-(v152 ^ -1))) >> 31)) & 2)) - (v153 + ((~(((v154 ^ -1) | (-(v154 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
    v213[v309] = v211;
    int * v215 = v126->cache_tags;
    int v312 = ((((int)((unsigned int)((int)((unsigned int)v130 >> 2)) >> 1)) & 1) * 2) + ((((v150 + ((~(((v152 ^ -1) | (-(v152 ^ -1))) >> 31)) & 2)) - (v153 + ((~(((v154 ^ -1) | (-(v154 ^ -1))) >> 31)) & 2))) >> 31) & 1);
    int v313 = (int)((unsigned int)((int)((unsigned int)v130 >> 2)) >> 1);
    v215[v312] = v313;
    int * v217 = v126->cache_dirty;
    v217[v312] = 0;
    int * v219 = v126->cache_age;
    v219[v312] = 1;
    int * v221 = v126->cache_age;
    int v222 = v221[v312];
    int v223 = v221[v241];
    int v319 = v223 + ((int)((unsigned int)(v223 - v222) >> 31));
    v221[v241] = v319;
    int * v225 = v126->cache_age;
    int v226 = v225[v242];
    int v321 = v226 + ((int)((unsigned int)(v226 - v222) >> 31));
    v225[v242] = v321;
    int * v228 = v126->cache_age;
    v228[v312] = 0;
    v231 = v312;
  }
  int v324 = (v231 * 2) + (((int)((unsigned int)v130 >> 2)) & 1);
  int v232 = v138[v324];
  int * v233 = v126->regs;
  v233[7] = v232;
  struct StateT * v235 = slot_8(v126);
  return v235;
}

struct StateT * slot_3(struct StateT * v41) {
  int v42 = v41->timer;
  int v48 = v42 + 1;
  v41->timer = v48;
  int * v44 = v41->regs;
  v44[15] = 16;
  struct StateT * v46 = slot_4(v41);
  return v46;
}

struct StateT * snippet(struct StateT * v0) {
  struct StateT * v1 = slot_0(v0);
  return v1;
}

struct StateT * slot_10(struct StateT * v551) {
  int v552 = v551->timer;
  int v560 = v552 + 1;
  v551->timer = v560;
  int * v554 = v551->regs;
  int v555 = v554[7];
  int v556 = v554[9];
  int v565 = v555 ^ v556;
  v554[16] = v565;
  struct StateT * v558 = slot_11(v551);
  return v558;
}

struct StateT * slot_1(struct StateT * v15) {
  int v16 = v15->timer;
  int v22 = v16 + 1;
  v15->timer = v22;
  int * v18 = v15->regs;
  v18[13] = 80;
  struct StateT * v20 = slot_2(v15);
  return v20;
}

struct StateT * slot_8(struct StateT * v330) {
  int v331 = v330->timer;
  int v339 = v331 + 1;
  v330->timer = v339;
  int * v333 = v330->regs;
  int v334 = v333[13];
  int v335 = v333[14];
  int v344 = v334 + v335;
  v333[8] = v344;
  struct StateT * v337 = slot_9(v330);
  return v337;
}

struct StateT * slot_4(struct StateT * v54) {
  int v55 = v54->timer;
  int v61 = v55 + 1;
  v54->timer = v61;
  int * v57 = v54->regs;
  v57[5] = 0;
  struct StateT * v59 = slot_5(v54);
  return v59;
}

struct StateT * slot_13(struct StateT * v598) {
  int v599 = v598->timer;
  int v603 = v599 + 1;
  v598->timer = v603;
  struct StateT * v601 = slot_5(v598);
  return v601;
}

struct StateT * slot_9(struct StateT * v347) {
  int v348 = v347->timer;
  int v458 = v348 + 1;
  v347->timer = v458;
  int * v350 = v347->regs;
  int v351 = v350[8];
  int * v352 = v347->cache_tags;
  int v462 = (((int)((unsigned int)((int)((unsigned int)v351 >> 2)) >> 1)) & 1) * 2;
  int v353 = v352[v462];
  int v463 = ((((int)((unsigned int)((int)((unsigned int)v351 >> 2)) >> 1)) & 1) * 2) + 1;
  int v354 = v352[v463];
  int v464 = 4 + ((((int)((unsigned int)((int)((unsigned int)v351 >> 2)) >> 1)) & 3) * 2);
  int v355 = v352[v464];
  int v465 = (4 + ((((int)((unsigned int)((int)((unsigned int)v351 >> 2)) >> 1)) & 3) * 2)) + 1;
  int v356 = v352[v465];
  int v357 = v347->timer;
  int v466 = v357 + ((100 ^ (((~(((v355 ^ ((int)((unsigned int)((int)((unsigned int)v351 >> 2)) >> 1))) | (-(v355 ^ ((int)((unsigned int)((int)((unsigned int)v351 >> 2)) >> 1))))) >> 31)) | (~(((v356 ^ ((int)((unsigned int)((int)((unsigned int)v351 >> 2)) >> 1))) | (-(v356 ^ ((int)((unsigned int)((int)((unsigned int)v351 >> 2)) >> 1))))) >> 31))) & 104)) ^ (((~(((v353 ^ ((int)((unsigned int)((int)((unsigned int)v351 >> 2)) >> 1))) | (-(v353 ^ ((int)((unsigned int)((int)((unsigned int)v351 >> 2)) >> 1))))) >> 31)) | (~(((v354 ^ ((int)((unsigned int)((int)((unsigned int)v351 >> 2)) >> 1))) | (-(v354 ^ ((int)((unsigned int)((int)((unsigned int)v351 >> 2)) >> 1))))) >> 31))) & (1 ^ (100 ^ (((~(((v355 ^ ((int)((unsigned int)((int)((unsigned int)v351 >> 2)) >> 1))) | (-(v355 ^ ((int)((unsigned int)((int)((unsigned int)v351 >> 2)) >> 1))))) >> 31)) | (~(((v356 ^ ((int)((unsigned int)((int)((unsigned int)v351 >> 2)) >> 1))) | (-(v356 ^ ((int)((unsigned int)((int)((unsigned int)v351 >> 2)) >> 1))))) >> 31))) & 104)))));
  v347->timer = v466;
  int * v359 = v347->cache_vals;
  bool v467 = !(((~(((v353 ^ ((int)((unsigned int)((int)((unsigned int)v351 >> 2)) >> 1))) | (-(v353 ^ ((int)((unsigned int)((int)((unsigned int)v351 >> 2)) >> 1))))) >> 31)) | (~(((v354 ^ ((int)((unsigned int)((int)((unsigned int)v351 >> 2)) >> 1))) | (-(v354 ^ ((int)((unsigned int)((int)((unsigned int)v351 >> 2)) >> 1))))) >> 31))) == 0);
  int v452;
  if (v467) {
    int * v360 = v347->cache_age;
    int v469 = ((((int)((unsigned int)((int)((unsigned int)v351 >> 2)) >> 1)) & 1) * 2) + ((~(((v354 ^ ((int)((unsigned int)((int)((unsigned int)v351 >> 2)) >> 1))) | (-(v354 ^ ((int)((unsigned int)((int)((unsigned int)v351 >> 2)) >> 1))))) >> 31)) & 1);
    int v361 = v360[v469];
    int v362 = v360[v462];
    int v470 = v362 + ((int)((unsigned int)(v362 - v361) >> 31));
    v360[v462] = v470;
    int * v364 = v347->cache_age;
    int v365 = v364[v463];
    int v472 = v365 + ((int)((unsigned int)(v365 - v361) >> 31));
    v364[v463] = v472;
    int * v367 = v347->cache_age;
    v367[v469] = 0;
    v452 = v469;
  } else {
    int * v370 = v347->cache_age;
    int v476 = (((int)((unsigned int)((int)((unsigned int)v351 >> 2)) >> 1)) & 1) * 2;
    int v371 = v370[v476];
    int * v372 = v347->cache_tags;
    int v373 = v372[v476];
    int v374 = v370[v463];
    int v375 = v372[v463];
    bool v478 = !(((~(((v355 ^ ((int)((unsigned int)((int)((unsigned int)v351 >> 2)) >> 1))) | (-(v355 ^ ((int)((unsigned int)((int)((unsigned int)v351 >> 2)) >> 1))))) >> 31)) | (~(((v356 ^ ((int)((unsigned int)((int)((unsigned int)v351 >> 2)) >> 1))) | (-(v356 ^ ((int)((unsigned int)((int)((unsigned int)v351 >> 2)) >> 1))))) >> 31))) == 0);
    int v429;
    if (v478) {
      int * v376 = v347->cache_age;
      int v480 = (4 + ((((int)((unsigned int)((int)((unsigned int)v351 >> 2)) >> 1)) & 3) * 2)) + ((~(((v356 ^ ((int)((unsigned int)((int)((unsigned int)v351 >> 2)) >> 1))) | (-(v356 ^ ((int)((unsigned int)((int)((unsigned int)v351 >> 2)) >> 1))))) >> 31)) & 1);
      int v377 = v376[v480];
      int v378 = v376[v464];
      int v481 = v378 + ((int)((unsigned int)(v378 - v377) >> 31));
      v376[v464] = v481;
      int * v380 = v347->cache_age;
      int v381 = v380[v465];
      int v483 = v381 + ((int)((unsigned int)(v381 - v377) >> 31));
      v380[v465] = v483;
      int * v383 = v347->cache_age;
      v383[v480] = 0;
      v429 = v480;
    } else {
      int * v386 = v347->cache_age;
      int v487 = 4 + ((((int)((unsigned int)((int)((unsigned int)v351 >> 2)) >> 1)) & 3) * 2);
      int v387 = v386[v487];
      int * v388 = v347->cache_tags;
      int v389 = v388[v487];
      int v390 = v386[v465];
      int v391 = v388[v465];
      int * v392 = v347->cache_dirty;
      int v490 = (4 + ((((int)((unsigned int)((int)((unsigned int)v351 >> 2)) >> 1)) & 3) * 2)) + ((((v387 + ((~(((v389 ^ -1) | (-(v389 ^ -1))) >> 31)) & 2)) - (v390 + ((~(((v391 ^ -1) | (-(v391 ^ -1))) >> 31)) & 2))) >> 31) & 1);
      int v393 = v392[v490];
      bool v491 = !(v393 == 0);
      if (v491) {
        int * v394 = v347->cache_tags;
        int v395 = v394[v490];
        int * v396 = v347->cache_vals;
        int v494 = ((4 + ((((int)((unsigned int)((int)((unsigned int)v351 >> 2)) >> 1)) & 3) * 2)) + ((((v387 + ((~(((v389 ^ -1) | (-(v389 ^ -1))) >> 31)) & 2)) - (v390 + ((~(((v391 ^ -1) | (-(v391 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
        int v397 = v396[v494];
        int v495 = (((4 + ((((int)((unsigned int)((int)((unsigned int)v351 >> 2)) >> 1)) & 3) * 2)) + ((((v387 + ((~(((v389 ^ -1) | (-(v389 ^ -1))) >> 31)) & 2)) - (v390 + ((~(((v391 ^ -1) | (-(v391 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
        int v398 = v396[v495];
        int * v399 = v347->mem;
        int v497 = v395 * 2;
        v399[v497] = v397;
        int * v401 = v347->mem;
        int v500 = (v395 * 2) + 1;
        v401[v500] = v398;
        ;
      } else {
        ;
      }
      int * v406 = v347->mem;
      int v505 = ((int)((unsigned int)((int)((unsigned int)v351 >> 2)) >> 1)) * 2;
      int v407 = v406[v505];
      int v506 = (((int)((unsigned int)((int)((unsigned int)v351 >> 2)) >> 1)) * 2) + 1;
      int v408 = v406[v506];
      int * v409 = v347->cache_vals;
      int v508 = ((4 + ((((int)((unsigned int)((int)((unsigned int)v351 >> 2)) >> 1)) & 3) * 2)) + ((((v387 + ((~(((v389 ^ -1) | (-(v389 ^ -1))) >> 31)) & 2)) - (v390 + ((~(((v391 ^ -1) | (-(v391 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
      v409[v508] = v407;
      int * v411 = v347->cache_vals;
      int v511 = (((4 + ((((int)((unsigned int)((int)((unsigned int)v351 >> 2)) >> 1)) & 3) * 2)) + ((((v387 + ((~(((v389 ^ -1) | (-(v389 ^ -1))) >> 31)) & 2)) - (v390 + ((~(((v391 ^ -1) | (-(v391 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
      v411[v511] = v408;
      int * v413 = v347->cache_tags;
      int v514 = (int)((unsigned int)((int)((unsigned int)v351 >> 2)) >> 1);
      v413[v490] = v514;
      int * v415 = v347->cache_dirty;
      v415[v490] = 0;
      int * v417 = v347->cache_age;
      v417[v490] = 1;
      int * v419 = v347->cache_age;
      int v420 = v419[v490];
      int v421 = v419[v464];
      int v520 = v421 + ((int)((unsigned int)(v421 - v420) >> 31));
      v419[v464] = v520;
      int * v423 = v347->cache_age;
      int v424 = v423[v465];
      int v522 = v424 + ((int)((unsigned int)(v424 - v420) >> 31));
      v423[v465] = v522;
      int * v426 = v347->cache_age;
      v426[v490] = 0;
      v429 = v490;
    }
    int * v430 = v347->cache_vals;
    int v525 = v429 * 2;
    int v431 = v430[v525];
    int v526 = (v429 * 2) + 1;
    int v432 = v430[v526];
    int v527 = (((((int)((unsigned int)((int)((unsigned int)v351 >> 2)) >> 1)) & 1) * 2) + ((((v371 + ((~(((v373 ^ -1) | (-(v373 ^ -1))) >> 31)) & 2)) - (v374 + ((~(((v375 ^ -1) | (-(v375 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
    v430[v527] = v431;
    int * v434 = v347->cache_vals;
    int v530 = ((((((int)((unsigned int)((int)((unsigned int)v351 >> 2)) >> 1)) & 1) * 2) + ((((v371 + ((~(((v373 ^ -1) | (-(v373 ^ -1))) >> 31)) & 2)) - (v374 + ((~(((v375 ^ -1) | (-(v375 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
    v434[v530] = v432;
    int * v436 = v347->cache_tags;
    int v533 = ((((int)((unsigned int)((int)((unsigned int)v351 >> 2)) >> 1)) & 1) * 2) + ((((v371 + ((~(((v373 ^ -1) | (-(v373 ^ -1))) >> 31)) & 2)) - (v374 + ((~(((v375 ^ -1) | (-(v375 ^ -1))) >> 31)) & 2))) >> 31) & 1);
    int v534 = (int)((unsigned int)((int)((unsigned int)v351 >> 2)) >> 1);
    v436[v533] = v534;
    int * v438 = v347->cache_dirty;
    v438[v533] = 0;
    int * v440 = v347->cache_age;
    v440[v533] = 1;
    int * v442 = v347->cache_age;
    int v443 = v442[v533];
    int v444 = v442[v462];
    int v540 = v444 + ((int)((unsigned int)(v444 - v443) >> 31));
    v442[v462] = v540;
    int * v446 = v347->cache_age;
    int v447 = v446[v463];
    int v542 = v447 + ((int)((unsigned int)(v447 - v443) >> 31));
    v446[v463] = v542;
    int * v449 = v347->cache_age;
    v449[v533] = 0;
    v452 = v533;
  }
  int v545 = (v452 * 2) + (((int)((unsigned int)v351 >> 2)) & 1);
  int v453 = v359[v545];
  int * v454 = v347->regs;
  v454[9] = v453;
  struct StateT * v456 = slot_10(v347);
  return v456;
}

struct StateT * slot_11(struct StateT * v568) {
  int v569 = v568->timer;
  int v577 = v569 + 1;
  v568->timer = v577;
  int * v571 = v568->regs;
  int v572 = v571[5];
  int v573 = v571[16];
  int v581 = v572 | v573;
  v571[5] = v581;
  struct StateT * v575 = slot_12(v568);
  return v575;
}

struct StateT * slot_0(struct StateT * v2) {
  int v3 = v2->timer;
  int v9 = v3 + 1;
  v2->timer = v9;
  int * v5 = v2->regs;
  v5[12] = 0;
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