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

struct StateT * slot_12(struct StateT * v589);
struct StateT * slot_14(struct StateT * v622);
struct StateT * slot_6(struct StateT * v112);
struct StateT * slot_16(struct StateT * v652);
struct StateT * slot_5(struct StateT * v90);
struct StateT * slot_17(struct StateT * v73);
struct StateT * slot_2(struct StateT * v28);
struct StateT * slot_7(struct StateT * v129);
struct StateT * slot_3(struct StateT * v41);
struct StateT * snippet(struct StateT * v0);
struct StateT * slot_10(struct StateT * v551);
struct StateT * slot_1(struct StateT * v15);
struct StateT * slot_8(struct StateT * v332);
struct StateT * slot_4(struct StateT * v53);
struct StateT * slot_13(struct StateT * v606);
struct StateT * slot_15(struct StateT * v638);
struct StateT * slot_18(struct StateT * v107);
struct StateT * slot_9(struct StateT * v535);
struct StateT * slot_11(struct StateT * v573);
struct StateT * slot_0(struct StateT * v2);
struct StateT * slot_12(struct StateT * v589) {
  int v590 = v589->timer;
  int v598 = v590 + 1;
  v589->timer = v598;
  int * v592 = v589->regs;
  int v593 = v592[16];
  int v594 = v592[12];
  int v603 = v593 & v594;
  v592[17] = v603;
  struct StateT * v596 = slot_13(v589);
  return v596;
}

struct StateT * slot_14(struct StateT * v622) {
  int v623 = v622->timer;
  int v631 = v623 + 1;
  v622->timer = v631;
  int * v625 = v622->regs;
  int v626 = v625[12];
  int v627 = v625[17];
  int v635 = v626 ^ v627;
  v625[12] = v635;
  struct StateT * v629 = slot_15(v622);
  return v629;
}

struct StateT * slot_6(struct StateT * v112) {
  int v113 = v112->timer;
  int v121 = v113 + 1;
  v112->timer = v121;
  int * v115 = v112->regs;
  int v116 = v115[11];
  int v117 = v115[13];
  int v126 = v116 + v117;
  v115[17] = v126;
  struct StateT * v119 = slot_7(v112);
  return v119;
}

struct StateT * slot_16(struct StateT * v652) {
  int v653 = v652->timer;
  int v664 = v653 + 1;
  v652->timer = v664;
  int * v655 = v652->regs;
  int v656 = v655[15];
  int v657 = v655[13];
  bool v668 = (v656 ^ -2147483648) >= (v657 ^ -2147483648);
  struct StateT * v662;
  if (v668) {
    struct StateT * v658 = slot_5(v652);
    v662 = v658;
  } else {
    struct StateT * v660 = slot_17(v652);
    v662 = v660;
  }
  return v662;
}

struct StateT * slot_5(struct StateT * v90) {
  int v91 = v90->timer;
  int v99 = v91 + 1;
  v90->timer = v99;
  int * v93 = v90->regs;
  int v94 = v93[10];
  int v95 = v93[13];
  int v104 = v94 + v95;
  v93[16] = v104;
  struct StateT * v97 = slot_6(v90);
  return v97;
}

struct StateT * slot_17(struct StateT * v73) {
  int v74 = v73->timer;
  int v82 = v74 + 1;
  v73->timer = v82;
  int * v76 = v73->regs;
  int v77 = v76[14];
  int v78 = v76[12];
  int v87 = v77 | v78;
  v76[10] = v87;
  struct StateT * v80 = slot_18(v73);
  return v80;
}

struct StateT * slot_2(struct StateT * v28) {
  int v29 = v28->timer;
  int v35 = v29 + 1;
  v28->timer = v35;
  int * v31 = v28->regs;
  v31[14] = 1;
  struct StateT * v33 = slot_3(v28);
  return v33;
}

struct StateT * slot_7(struct StateT * v129) {
  int v130 = v129->timer;
  int v240 = v130 + 1;
  v129->timer = v240;
  int * v132 = v129->regs;
  int v133 = v132[16];
  int * v134 = v129->cache_tags;
  int v244 = (((int)((unsigned int)((int)((unsigned int)v133 >> 2)) >> 1)) & 1) * 2;
  int v135 = v134[v244];
  int v245 = ((((int)((unsigned int)((int)((unsigned int)v133 >> 2)) >> 1)) & 1) * 2) + 1;
  int v136 = v134[v245];
  int v246 = 4 + ((((int)((unsigned int)((int)((unsigned int)v133 >> 2)) >> 1)) & 3) * 2);
  int v137 = v134[v246];
  int v247 = (4 + ((((int)((unsigned int)((int)((unsigned int)v133 >> 2)) >> 1)) & 3) * 2)) + 1;
  int v138 = v134[v247];
  int v139 = v129->timer;
  int v248 = v139 + ((100 ^ (((~(((v137 ^ ((int)((unsigned int)((int)((unsigned int)v133 >> 2)) >> 1))) | (-(v137 ^ ((int)((unsigned int)((int)((unsigned int)v133 >> 2)) >> 1))))) >> 31)) | (~(((v138 ^ ((int)((unsigned int)((int)((unsigned int)v133 >> 2)) >> 1))) | (-(v138 ^ ((int)((unsigned int)((int)((unsigned int)v133 >> 2)) >> 1))))) >> 31))) & 104)) ^ (((~(((v135 ^ ((int)((unsigned int)((int)((unsigned int)v133 >> 2)) >> 1))) | (-(v135 ^ ((int)((unsigned int)((int)((unsigned int)v133 >> 2)) >> 1))))) >> 31)) | (~(((v136 ^ ((int)((unsigned int)((int)((unsigned int)v133 >> 2)) >> 1))) | (-(v136 ^ ((int)((unsigned int)((int)((unsigned int)v133 >> 2)) >> 1))))) >> 31))) & (1 ^ (100 ^ (((~(((v137 ^ ((int)((unsigned int)((int)((unsigned int)v133 >> 2)) >> 1))) | (-(v137 ^ ((int)((unsigned int)((int)((unsigned int)v133 >> 2)) >> 1))))) >> 31)) | (~(((v138 ^ ((int)((unsigned int)((int)((unsigned int)v133 >> 2)) >> 1))) | (-(v138 ^ ((int)((unsigned int)((int)((unsigned int)v133 >> 2)) >> 1))))) >> 31))) & 104)))));
  v129->timer = v248;
  int * v141 = v129->cache_vals;
  bool v249 = !(((~(((v135 ^ ((int)((unsigned int)((int)((unsigned int)v133 >> 2)) >> 1))) | (-(v135 ^ ((int)((unsigned int)((int)((unsigned int)v133 >> 2)) >> 1))))) >> 31)) | (~(((v136 ^ ((int)((unsigned int)((int)((unsigned int)v133 >> 2)) >> 1))) | (-(v136 ^ ((int)((unsigned int)((int)((unsigned int)v133 >> 2)) >> 1))))) >> 31))) == 0);
  int v234;
  if (v249) {
    int * v142 = v129->cache_age;
    int v251 = ((((int)((unsigned int)((int)((unsigned int)v133 >> 2)) >> 1)) & 1) * 2) + ((~(((v136 ^ ((int)((unsigned int)((int)((unsigned int)v133 >> 2)) >> 1))) | (-(v136 ^ ((int)((unsigned int)((int)((unsigned int)v133 >> 2)) >> 1))))) >> 31)) & 1);
    int v143 = v142[v251];
    int v144 = v142[v244];
    int v252 = v144 + ((int)((unsigned int)(v144 - v143) >> 31));
    v142[v244] = v252;
    int * v146 = v129->cache_age;
    int v147 = v146[v245];
    int v254 = v147 + ((int)((unsigned int)(v147 - v143) >> 31));
    v146[v245] = v254;
    int * v149 = v129->cache_age;
    v149[v251] = 0;
    v234 = v251;
  } else {
    int * v152 = v129->cache_age;
    int v258 = (((int)((unsigned int)((int)((unsigned int)v133 >> 2)) >> 1)) & 1) * 2;
    int v153 = v152[v258];
    int * v154 = v129->cache_tags;
    int v155 = v154[v258];
    int v156 = v152[v245];
    int v157 = v154[v245];
    bool v260 = !(((~(((v137 ^ ((int)((unsigned int)((int)((unsigned int)v133 >> 2)) >> 1))) | (-(v137 ^ ((int)((unsigned int)((int)((unsigned int)v133 >> 2)) >> 1))))) >> 31)) | (~(((v138 ^ ((int)((unsigned int)((int)((unsigned int)v133 >> 2)) >> 1))) | (-(v138 ^ ((int)((unsigned int)((int)((unsigned int)v133 >> 2)) >> 1))))) >> 31))) == 0);
    int v211;
    if (v260) {
      int * v158 = v129->cache_age;
      int v262 = (4 + ((((int)((unsigned int)((int)((unsigned int)v133 >> 2)) >> 1)) & 3) * 2)) + ((~(((v138 ^ ((int)((unsigned int)((int)((unsigned int)v133 >> 2)) >> 1))) | (-(v138 ^ ((int)((unsigned int)((int)((unsigned int)v133 >> 2)) >> 1))))) >> 31)) & 1);
      int v159 = v158[v262];
      int v160 = v158[v246];
      int v263 = v160 + ((int)((unsigned int)(v160 - v159) >> 31));
      v158[v246] = v263;
      int * v162 = v129->cache_age;
      int v163 = v162[v247];
      int v265 = v163 + ((int)((unsigned int)(v163 - v159) >> 31));
      v162[v247] = v265;
      int * v165 = v129->cache_age;
      v165[v262] = 0;
      v211 = v262;
    } else {
      int * v168 = v129->cache_age;
      int v269 = 4 + ((((int)((unsigned int)((int)((unsigned int)v133 >> 2)) >> 1)) & 3) * 2);
      int v169 = v168[v269];
      int * v170 = v129->cache_tags;
      int v171 = v170[v269];
      int v172 = v168[v247];
      int v173 = v170[v247];
      int * v174 = v129->cache_dirty;
      int v272 = (4 + ((((int)((unsigned int)((int)((unsigned int)v133 >> 2)) >> 1)) & 3) * 2)) + ((((v169 + ((~(((v171 ^ -1) | (-(v171 ^ -1))) >> 31)) & 2)) - (v172 + ((~(((v173 ^ -1) | (-(v173 ^ -1))) >> 31)) & 2))) >> 31) & 1);
      int v175 = v174[v272];
      bool v273 = !(v175 == 0);
      if (v273) {
        int * v176 = v129->cache_tags;
        int v177 = v176[v272];
        int * v178 = v129->cache_vals;
        int v276 = ((4 + ((((int)((unsigned int)((int)((unsigned int)v133 >> 2)) >> 1)) & 3) * 2)) + ((((v169 + ((~(((v171 ^ -1) | (-(v171 ^ -1))) >> 31)) & 2)) - (v172 + ((~(((v173 ^ -1) | (-(v173 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
        int v179 = v178[v276];
        int v277 = (((4 + ((((int)((unsigned int)((int)((unsigned int)v133 >> 2)) >> 1)) & 3) * 2)) + ((((v169 + ((~(((v171 ^ -1) | (-(v171 ^ -1))) >> 31)) & 2)) - (v172 + ((~(((v173 ^ -1) | (-(v173 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
        int v180 = v178[v277];
        int * v181 = v129->mem;
        int v279 = v177 * 2;
        v181[v279] = v179;
        int * v183 = v129->mem;
        int v282 = (v177 * 2) + 1;
        v183[v282] = v180;
        ;
      } else {
        ;
      }
      int * v188 = v129->mem;
      int v287 = ((int)((unsigned int)((int)((unsigned int)v133 >> 2)) >> 1)) * 2;
      int v189 = v188[v287];
      int v288 = (((int)((unsigned int)((int)((unsigned int)v133 >> 2)) >> 1)) * 2) + 1;
      int v190 = v188[v288];
      int * v191 = v129->cache_vals;
      int v290 = ((4 + ((((int)((unsigned int)((int)((unsigned int)v133 >> 2)) >> 1)) & 3) * 2)) + ((((v169 + ((~(((v171 ^ -1) | (-(v171 ^ -1))) >> 31)) & 2)) - (v172 + ((~(((v173 ^ -1) | (-(v173 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
      v191[v290] = v189;
      int * v193 = v129->cache_vals;
      int v293 = (((4 + ((((int)((unsigned int)((int)((unsigned int)v133 >> 2)) >> 1)) & 3) * 2)) + ((((v169 + ((~(((v171 ^ -1) | (-(v171 ^ -1))) >> 31)) & 2)) - (v172 + ((~(((v173 ^ -1) | (-(v173 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
      v193[v293] = v190;
      int * v195 = v129->cache_tags;
      int v296 = (int)((unsigned int)((int)((unsigned int)v133 >> 2)) >> 1);
      v195[v272] = v296;
      int * v197 = v129->cache_dirty;
      v197[v272] = 0;
      int * v199 = v129->cache_age;
      v199[v272] = 1;
      int * v201 = v129->cache_age;
      int v202 = v201[v272];
      int v203 = v201[v246];
      int v302 = v203 + ((int)((unsigned int)(v203 - v202) >> 31));
      v201[v246] = v302;
      int * v205 = v129->cache_age;
      int v206 = v205[v247];
      int v304 = v206 + ((int)((unsigned int)(v206 - v202) >> 31));
      v205[v247] = v304;
      int * v208 = v129->cache_age;
      v208[v272] = 0;
      v211 = v272;
    }
    int * v212 = v129->cache_vals;
    int v307 = v211 * 2;
    int v213 = v212[v307];
    int v308 = (v211 * 2) + 1;
    int v214 = v212[v308];
    int v309 = (((((int)((unsigned int)((int)((unsigned int)v133 >> 2)) >> 1)) & 1) * 2) + ((((v153 + ((~(((v155 ^ -1) | (-(v155 ^ -1))) >> 31)) & 2)) - (v156 + ((~(((v157 ^ -1) | (-(v157 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
    v212[v309] = v213;
    int * v216 = v129->cache_vals;
    int v312 = ((((((int)((unsigned int)((int)((unsigned int)v133 >> 2)) >> 1)) & 1) * 2) + ((((v153 + ((~(((v155 ^ -1) | (-(v155 ^ -1))) >> 31)) & 2)) - (v156 + ((~(((v157 ^ -1) | (-(v157 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
    v216[v312] = v214;
    int * v218 = v129->cache_tags;
    int v315 = ((((int)((unsigned int)((int)((unsigned int)v133 >> 2)) >> 1)) & 1) * 2) + ((((v153 + ((~(((v155 ^ -1) | (-(v155 ^ -1))) >> 31)) & 2)) - (v156 + ((~(((v157 ^ -1) | (-(v157 ^ -1))) >> 31)) & 2))) >> 31) & 1);
    int v316 = (int)((unsigned int)((int)((unsigned int)v133 >> 2)) >> 1);
    v218[v315] = v316;
    int * v220 = v129->cache_dirty;
    v220[v315] = 0;
    int * v222 = v129->cache_age;
    v222[v315] = 1;
    int * v224 = v129->cache_age;
    int v225 = v224[v315];
    int v226 = v224[v244];
    int v322 = v226 + ((int)((unsigned int)(v226 - v225) >> 31));
    v224[v244] = v322;
    int * v228 = v129->cache_age;
    int v229 = v228[v245];
    int v324 = v229 + ((int)((unsigned int)(v229 - v225) >> 31));
    v228[v245] = v324;
    int * v231 = v129->cache_age;
    v231[v315] = 0;
    v234 = v315;
  }
  int v327 = (v234 * 2) + (((int)((unsigned int)v133 >> 2)) & 1);
  int v235 = v141[v327];
  int * v236 = v129->regs;
  int v329 = ((int)((unsigned int)v235 >> ((v133 & 3) << 3))) & 255;
  v236[16] = v329;
  struct StateT * v238 = slot_8(v129);
  return v238;
}

struct StateT * slot_3(struct StateT * v41) {
  int v42 = v41->timer;
  int v48 = v42 + 1;
  v41->timer = v48;
  int * v44 = v41->regs;
  v44[15] = 15;
  struct StateT * v46 = slot_4(v41);
  return v46;
}

struct StateT * snippet(struct StateT * v0) {
  struct StateT * v1 = slot_0(v0);
  return v1;
}

struct StateT * slot_10(struct StateT * v551) {
  int v552 = v551->timer;
  int v563 = v552 + 1;
  v551->timer = v563;
  int * v554 = v551->regs;
  int v555 = v554[16];
  bool v566 = -2147483648 < (v555 ^ -2147483648);
  int v558;
  if (v566) {
    v558 = 1;
  } else {
    v558 = 0;
  }
  int * v559 = v551->regs;
  v559[16] = v558;
  struct StateT * v561 = slot_11(v551);
  return v561;
}

struct StateT * slot_1(struct StateT * v15) {
  int v16 = v15->timer;
  int v22 = v16 + 1;
  v15->timer = v22;
  int * v18 = v15->regs;
  v18[13] = 0;
  struct StateT * v20 = slot_2(v15);
  return v20;
}

struct StateT * slot_8(struct StateT * v332) {
  int v333 = v332->timer;
  int v443 = v333 + 1;
  v332->timer = v443;
  int * v335 = v332->regs;
  int v336 = v335[17];
  int * v337 = v332->cache_tags;
  int v447 = (((int)((unsigned int)((int)((unsigned int)v336 >> 2)) >> 1)) & 1) * 2;
  int v338 = v337[v447];
  int v448 = ((((int)((unsigned int)((int)((unsigned int)v336 >> 2)) >> 1)) & 1) * 2) + 1;
  int v339 = v337[v448];
  int v449 = 4 + ((((int)((unsigned int)((int)((unsigned int)v336 >> 2)) >> 1)) & 3) * 2);
  int v340 = v337[v449];
  int v450 = (4 + ((((int)((unsigned int)((int)((unsigned int)v336 >> 2)) >> 1)) & 3) * 2)) + 1;
  int v341 = v337[v450];
  int v342 = v332->timer;
  int v451 = v342 + ((100 ^ (((~(((v340 ^ ((int)((unsigned int)((int)((unsigned int)v336 >> 2)) >> 1))) | (-(v340 ^ ((int)((unsigned int)((int)((unsigned int)v336 >> 2)) >> 1))))) >> 31)) | (~(((v341 ^ ((int)((unsigned int)((int)((unsigned int)v336 >> 2)) >> 1))) | (-(v341 ^ ((int)((unsigned int)((int)((unsigned int)v336 >> 2)) >> 1))))) >> 31))) & 104)) ^ (((~(((v338 ^ ((int)((unsigned int)((int)((unsigned int)v336 >> 2)) >> 1))) | (-(v338 ^ ((int)((unsigned int)((int)((unsigned int)v336 >> 2)) >> 1))))) >> 31)) | (~(((v339 ^ ((int)((unsigned int)((int)((unsigned int)v336 >> 2)) >> 1))) | (-(v339 ^ ((int)((unsigned int)((int)((unsigned int)v336 >> 2)) >> 1))))) >> 31))) & (1 ^ (100 ^ (((~(((v340 ^ ((int)((unsigned int)((int)((unsigned int)v336 >> 2)) >> 1))) | (-(v340 ^ ((int)((unsigned int)((int)((unsigned int)v336 >> 2)) >> 1))))) >> 31)) | (~(((v341 ^ ((int)((unsigned int)((int)((unsigned int)v336 >> 2)) >> 1))) | (-(v341 ^ ((int)((unsigned int)((int)((unsigned int)v336 >> 2)) >> 1))))) >> 31))) & 104)))));
  v332->timer = v451;
  int * v344 = v332->cache_vals;
  bool v452 = !(((~(((v338 ^ ((int)((unsigned int)((int)((unsigned int)v336 >> 2)) >> 1))) | (-(v338 ^ ((int)((unsigned int)((int)((unsigned int)v336 >> 2)) >> 1))))) >> 31)) | (~(((v339 ^ ((int)((unsigned int)((int)((unsigned int)v336 >> 2)) >> 1))) | (-(v339 ^ ((int)((unsigned int)((int)((unsigned int)v336 >> 2)) >> 1))))) >> 31))) == 0);
  int v437;
  if (v452) {
    int * v345 = v332->cache_age;
    int v454 = ((((int)((unsigned int)((int)((unsigned int)v336 >> 2)) >> 1)) & 1) * 2) + ((~(((v339 ^ ((int)((unsigned int)((int)((unsigned int)v336 >> 2)) >> 1))) | (-(v339 ^ ((int)((unsigned int)((int)((unsigned int)v336 >> 2)) >> 1))))) >> 31)) & 1);
    int v346 = v345[v454];
    int v347 = v345[v447];
    int v455 = v347 + ((int)((unsigned int)(v347 - v346) >> 31));
    v345[v447] = v455;
    int * v349 = v332->cache_age;
    int v350 = v349[v448];
    int v457 = v350 + ((int)((unsigned int)(v350 - v346) >> 31));
    v349[v448] = v457;
    int * v352 = v332->cache_age;
    v352[v454] = 0;
    v437 = v454;
  } else {
    int * v355 = v332->cache_age;
    int v461 = (((int)((unsigned int)((int)((unsigned int)v336 >> 2)) >> 1)) & 1) * 2;
    int v356 = v355[v461];
    int * v357 = v332->cache_tags;
    int v358 = v357[v461];
    int v359 = v355[v448];
    int v360 = v357[v448];
    bool v463 = !(((~(((v340 ^ ((int)((unsigned int)((int)((unsigned int)v336 >> 2)) >> 1))) | (-(v340 ^ ((int)((unsigned int)((int)((unsigned int)v336 >> 2)) >> 1))))) >> 31)) | (~(((v341 ^ ((int)((unsigned int)((int)((unsigned int)v336 >> 2)) >> 1))) | (-(v341 ^ ((int)((unsigned int)((int)((unsigned int)v336 >> 2)) >> 1))))) >> 31))) == 0);
    int v414;
    if (v463) {
      int * v361 = v332->cache_age;
      int v465 = (4 + ((((int)((unsigned int)((int)((unsigned int)v336 >> 2)) >> 1)) & 3) * 2)) + ((~(((v341 ^ ((int)((unsigned int)((int)((unsigned int)v336 >> 2)) >> 1))) | (-(v341 ^ ((int)((unsigned int)((int)((unsigned int)v336 >> 2)) >> 1))))) >> 31)) & 1);
      int v362 = v361[v465];
      int v363 = v361[v449];
      int v466 = v363 + ((int)((unsigned int)(v363 - v362) >> 31));
      v361[v449] = v466;
      int * v365 = v332->cache_age;
      int v366 = v365[v450];
      int v468 = v366 + ((int)((unsigned int)(v366 - v362) >> 31));
      v365[v450] = v468;
      int * v368 = v332->cache_age;
      v368[v465] = 0;
      v414 = v465;
    } else {
      int * v371 = v332->cache_age;
      int v472 = 4 + ((((int)((unsigned int)((int)((unsigned int)v336 >> 2)) >> 1)) & 3) * 2);
      int v372 = v371[v472];
      int * v373 = v332->cache_tags;
      int v374 = v373[v472];
      int v375 = v371[v450];
      int v376 = v373[v450];
      int * v377 = v332->cache_dirty;
      int v475 = (4 + ((((int)((unsigned int)((int)((unsigned int)v336 >> 2)) >> 1)) & 3) * 2)) + ((((v372 + ((~(((v374 ^ -1) | (-(v374 ^ -1))) >> 31)) & 2)) - (v375 + ((~(((v376 ^ -1) | (-(v376 ^ -1))) >> 31)) & 2))) >> 31) & 1);
      int v378 = v377[v475];
      bool v476 = !(v378 == 0);
      if (v476) {
        int * v379 = v332->cache_tags;
        int v380 = v379[v475];
        int * v381 = v332->cache_vals;
        int v479 = ((4 + ((((int)((unsigned int)((int)((unsigned int)v336 >> 2)) >> 1)) & 3) * 2)) + ((((v372 + ((~(((v374 ^ -1) | (-(v374 ^ -1))) >> 31)) & 2)) - (v375 + ((~(((v376 ^ -1) | (-(v376 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
        int v382 = v381[v479];
        int v480 = (((4 + ((((int)((unsigned int)((int)((unsigned int)v336 >> 2)) >> 1)) & 3) * 2)) + ((((v372 + ((~(((v374 ^ -1) | (-(v374 ^ -1))) >> 31)) & 2)) - (v375 + ((~(((v376 ^ -1) | (-(v376 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
        int v383 = v381[v480];
        int * v384 = v332->mem;
        int v482 = v380 * 2;
        v384[v482] = v382;
        int * v386 = v332->mem;
        int v485 = (v380 * 2) + 1;
        v386[v485] = v383;
        ;
      } else {
        ;
      }
      int * v391 = v332->mem;
      int v490 = ((int)((unsigned int)((int)((unsigned int)v336 >> 2)) >> 1)) * 2;
      int v392 = v391[v490];
      int v491 = (((int)((unsigned int)((int)((unsigned int)v336 >> 2)) >> 1)) * 2) + 1;
      int v393 = v391[v491];
      int * v394 = v332->cache_vals;
      int v493 = ((4 + ((((int)((unsigned int)((int)((unsigned int)v336 >> 2)) >> 1)) & 3) * 2)) + ((((v372 + ((~(((v374 ^ -1) | (-(v374 ^ -1))) >> 31)) & 2)) - (v375 + ((~(((v376 ^ -1) | (-(v376 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
      v394[v493] = v392;
      int * v396 = v332->cache_vals;
      int v496 = (((4 + ((((int)((unsigned int)((int)((unsigned int)v336 >> 2)) >> 1)) & 3) * 2)) + ((((v372 + ((~(((v374 ^ -1) | (-(v374 ^ -1))) >> 31)) & 2)) - (v375 + ((~(((v376 ^ -1) | (-(v376 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
      v396[v496] = v393;
      int * v398 = v332->cache_tags;
      int v499 = (int)((unsigned int)((int)((unsigned int)v336 >> 2)) >> 1);
      v398[v475] = v499;
      int * v400 = v332->cache_dirty;
      v400[v475] = 0;
      int * v402 = v332->cache_age;
      v402[v475] = 1;
      int * v404 = v332->cache_age;
      int v405 = v404[v475];
      int v406 = v404[v449];
      int v505 = v406 + ((int)((unsigned int)(v406 - v405) >> 31));
      v404[v449] = v505;
      int * v408 = v332->cache_age;
      int v409 = v408[v450];
      int v507 = v409 + ((int)((unsigned int)(v409 - v405) >> 31));
      v408[v450] = v507;
      int * v411 = v332->cache_age;
      v411[v475] = 0;
      v414 = v475;
    }
    int * v415 = v332->cache_vals;
    int v510 = v414 * 2;
    int v416 = v415[v510];
    int v511 = (v414 * 2) + 1;
    int v417 = v415[v511];
    int v512 = (((((int)((unsigned int)((int)((unsigned int)v336 >> 2)) >> 1)) & 1) * 2) + ((((v356 + ((~(((v358 ^ -1) | (-(v358 ^ -1))) >> 31)) & 2)) - (v359 + ((~(((v360 ^ -1) | (-(v360 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
    v415[v512] = v416;
    int * v419 = v332->cache_vals;
    int v515 = ((((((int)((unsigned int)((int)((unsigned int)v336 >> 2)) >> 1)) & 1) * 2) + ((((v356 + ((~(((v358 ^ -1) | (-(v358 ^ -1))) >> 31)) & 2)) - (v359 + ((~(((v360 ^ -1) | (-(v360 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
    v419[v515] = v417;
    int * v421 = v332->cache_tags;
    int v518 = ((((int)((unsigned int)((int)((unsigned int)v336 >> 2)) >> 1)) & 1) * 2) + ((((v356 + ((~(((v358 ^ -1) | (-(v358 ^ -1))) >> 31)) & 2)) - (v359 + ((~(((v360 ^ -1) | (-(v360 ^ -1))) >> 31)) & 2))) >> 31) & 1);
    int v519 = (int)((unsigned int)((int)((unsigned int)v336 >> 2)) >> 1);
    v421[v518] = v519;
    int * v423 = v332->cache_dirty;
    v423[v518] = 0;
    int * v425 = v332->cache_age;
    v425[v518] = 1;
    int * v427 = v332->cache_age;
    int v428 = v427[v518];
    int v429 = v427[v447];
    int v525 = v429 + ((int)((unsigned int)(v429 - v428) >> 31));
    v427[v447] = v525;
    int * v431 = v332->cache_age;
    int v432 = v431[v448];
    int v527 = v432 + ((int)((unsigned int)(v432 - v428) >> 31));
    v431[v448] = v527;
    int * v434 = v332->cache_age;
    v434[v518] = 0;
    v437 = v518;
  }
  int v530 = (v437 * 2) + (((int)((unsigned int)v336 >> 2)) & 1);
  int v438 = v344[v530];
  int * v439 = v332->regs;
  int v532 = ((int)((unsigned int)v438 >> ((v336 & 3) << 3))) & 255;
  v439[17] = v532;
  struct StateT * v441 = slot_9(v332);
  return v441;
}

struct StateT * slot_4(struct StateT * v53) {
  int v54 = v53->timer;
  int v64 = v54 + 1;
  v53->timer = v64;
  int * v56 = v53->regs;
  int v57 = v56[15];
  bool v67 = (v57 ^ -2147483648) < -2147483648;
  struct StateT * v62;
  if (v67) {
    struct StateT * v58 = slot_17(v53);
    v62 = v58;
  } else {
    struct StateT * v60 = slot_5(v53);
    v62 = v60;
  }
  return v62;
}

struct StateT * slot_13(struct StateT * v606) {
  int v607 = v606->timer;
  int v615 = v607 + 1;
  v606->timer = v615;
  int * v609 = v606->regs;
  int v610 = v609[14];
  int v611 = v609[16];
  int v619 = v610 ^ v611;
  v609[14] = v619;
  struct StateT * v613 = slot_14(v606);
  return v613;
}

struct StateT * slot_15(struct StateT * v638) {
  int v639 = v638->timer;
  int v646 = v639 + 1;
  v638->timer = v646;
  int * v641 = v638->regs;
  int v642 = v641[13];
  int v649 = v642 + 1;
  v641[13] = v649;
  struct StateT * v644 = slot_16(v638);
  return v644;
}

struct StateT * slot_18(struct StateT * v107) {
  int v108 = v107->timer;
  int v111 = v108 + 1;
  v107->timer = v111;
  return v107;
}

struct StateT * slot_9(struct StateT * v535) {
  int v536 = v535->timer;
  int v544 = v536 + 1;
  v535->timer = v544;
  int * v538 = v535->regs;
  int v539 = v538[16];
  int v540 = v538[17];
  int v548 = v539 ^ v540;
  v538[16] = v548;
  struct StateT * v542 = slot_10(v535);
  return v542;
}

struct StateT * slot_11(struct StateT * v573) {
  int v574 = v573->timer;
  int v582 = v574 + 1;
  v573->timer = v582;
  int * v576 = v573->regs;
  int v577 = v576[16];
  int v578 = v576[14];
  int v586 = v577 & v578;
  v576[16] = v586;
  struct StateT * v580 = slot_12(v573);
  return v580;
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
  s->regs[2] = 4 * MEM_SIZE;
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
  
  // a10, 4 words read by the callee: the address is public
  s1.regs[10] = 0;
  s2.regs[10] = 0;
  // a11, 4 words read by the callee: the address is public
  s1.regs[11] = 16;
  s2.regs[11] = 16;
  
  // a10's contents, secret: a different draw in each state
  for (int i=0; i<4; i++) {
    s1.mem[0 + i] = secret(0, 20);
    s2.mem[0 + i] = secret(0, 20);
  }
  // a11's contents, secret: a different draw in each state
  for (int i=0; i<4; i++) {
    s1.mem[4 + i] = secret(0, 20);
    s2.mem[4 + i] = secret(0, 20);
  }
  struct StateT *s1_ = snippet(&s1);
  struct StateT *s2_ = snippet(&s2);
  //@ assert untainted_timer: !\tainted(s1_->timer==s2_->timer);
  koika_assert(s1_->timer==s2_->timer, "timing leak");
  return 0;
}