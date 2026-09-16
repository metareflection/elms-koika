// verify: leak (KLEE should report a failing assertion) [budget 1200s]
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
  int reg_ready[32];
  int cache_tags[12];
  int cache_dirty[12];
  int cache_age[12];
  int cache_vals[24];
  int timer;
};

struct StateT * snippet(struct StateT * v0);
struct StateT * slot_1(struct StateT * v19);
struct StateT * slot_2(struct StateT * v269);
struct StateT * slot_3(struct StateT * v285);
struct StateT * slot_0(struct StateT * v2);
struct StateT * snippet(struct StateT * v0) {
  struct StateT * v1 = slot_0(v0);
  return v1;
}

struct StateT * slot_1(struct StateT * v19) {
  int v20 = v19->timer;
  int v153 = v20 + 1;
  v19->timer = v153;
  int * v22 = v19->regs;
  int v23 = v22[10];
  int * v24 = v19->cache_tags;
  int v157 = (((int)((unsigned int)((int)((unsigned int)v23 >> 2)) >> 1)) & 1) * 2;
  int v25 = v24[v157];
  int * v26 = v19->cache_tags;
  int v159 = ((((int)((unsigned int)((int)((unsigned int)v23 >> 2)) >> 1)) & 1) * 2) + 1;
  int v27 = v26[v159];
  int * v28 = v19->cache_tags;
  int v161 = 4 + ((((int)((unsigned int)((int)((unsigned int)v23 >> 2)) >> 1)) & 3) * 2);
  int v29 = v28[v161];
  int * v30 = v19->cache_tags;
  int v163 = (4 + ((((int)((unsigned int)((int)((unsigned int)v23 >> 2)) >> 1)) & 3) * 2)) + 1;
  int v31 = v30[v163];
  int v32 = v19->timer;
  int v164 = v32 + ((100 ^ (((~(((v29 ^ ((int)((unsigned int)((int)((unsigned int)v23 >> 2)) >> 1))) | (-(v29 ^ ((int)((unsigned int)((int)((unsigned int)v23 >> 2)) >> 1))))) >> 31)) | (~(((v31 ^ ((int)((unsigned int)((int)((unsigned int)v23 >> 2)) >> 1))) | (-(v31 ^ ((int)((unsigned int)((int)((unsigned int)v23 >> 2)) >> 1))))) >> 31))) & 104)) ^ (((~(((v25 ^ ((int)((unsigned int)((int)((unsigned int)v23 >> 2)) >> 1))) | (-(v25 ^ ((int)((unsigned int)((int)((unsigned int)v23 >> 2)) >> 1))))) >> 31)) | (~(((v27 ^ ((int)((unsigned int)((int)((unsigned int)v23 >> 2)) >> 1))) | (-(v27 ^ ((int)((unsigned int)((int)((unsigned int)v23 >> 2)) >> 1))))) >> 31))) & (1 ^ (100 ^ (((~(((v29 ^ ((int)((unsigned int)((int)((unsigned int)v23 >> 2)) >> 1))) | (-(v29 ^ ((int)((unsigned int)((int)((unsigned int)v23 >> 2)) >> 1))))) >> 31)) | (~(((v31 ^ ((int)((unsigned int)((int)((unsigned int)v23 >> 2)) >> 1))) | (-(v31 ^ ((int)((unsigned int)((int)((unsigned int)v23 >> 2)) >> 1))))) >> 31))) & 104)))));
  v19->timer = v164;
  int * v34 = v19->cache_vals;
  bool v165 = !(((~(((v25 ^ ((int)((unsigned int)((int)((unsigned int)v23 >> 2)) >> 1))) | (-(v25 ^ ((int)((unsigned int)((int)((unsigned int)v23 >> 2)) >> 1))))) >> 31)) | (~(((v27 ^ ((int)((unsigned int)((int)((unsigned int)v23 >> 2)) >> 1))) | (-(v27 ^ ((int)((unsigned int)((int)((unsigned int)v23 >> 2)) >> 1))))) >> 31))) == 0);
  int v147;
  if (v165) {
    int * v35 = v19->cache_age;
    int v167 = ((((int)((unsigned int)((int)((unsigned int)v23 >> 2)) >> 1)) & 1) * 2) + ((~(((v27 ^ ((int)((unsigned int)((int)((unsigned int)v23 >> 2)) >> 1))) | (-(v27 ^ ((int)((unsigned int)((int)((unsigned int)v23 >> 2)) >> 1))))) >> 31)) & 1);
    int v36 = v35[v167];
    int * v37 = v19->cache_age;
    int v38 = v37[v157];
    int * v39 = v19->cache_age;
    int v170 = v38 + ((int)((unsigned int)(v38 - v36) >> 31));
    v39[v157] = v170;
    int * v41 = v19->cache_age;
    int v42 = v41[v159];
    int * v43 = v19->cache_age;
    int v173 = v42 + ((int)((unsigned int)(v42 - v36) >> 31));
    v43[v159] = v173;
    int * v45 = v19->cache_age;
    v45[v167] = 0;
    v147 = v167;
  } else {
    int * v48 = v19->cache_age;
    int v177 = (((int)((unsigned int)((int)((unsigned int)v23 >> 2)) >> 1)) & 1) * 2;
    int v49 = v48[v177];
    int * v50 = v19->cache_tags;
    int v51 = v50[v177];
    int * v52 = v19->cache_age;
    int v53 = v52[v159];
    int * v54 = v19->cache_tags;
    int v55 = v54[v159];
    bool v181 = !(((~(((v29 ^ ((int)((unsigned int)((int)((unsigned int)v23 >> 2)) >> 1))) | (-(v29 ^ ((int)((unsigned int)((int)((unsigned int)v23 >> 2)) >> 1))))) >> 31)) | (~(((v31 ^ ((int)((unsigned int)((int)((unsigned int)v23 >> 2)) >> 1))) | (-(v31 ^ ((int)((unsigned int)((int)((unsigned int)v23 >> 2)) >> 1))))) >> 31))) == 0);
    int v119;
    if (v181) {
      int * v56 = v19->cache_age;
      int v183 = (4 + ((((int)((unsigned int)((int)((unsigned int)v23 >> 2)) >> 1)) & 3) * 2)) + ((~(((v31 ^ ((int)((unsigned int)((int)((unsigned int)v23 >> 2)) >> 1))) | (-(v31 ^ ((int)((unsigned int)((int)((unsigned int)v23 >> 2)) >> 1))))) >> 31)) & 1);
      int v57 = v56[v183];
      int * v58 = v19->cache_age;
      int v59 = v58[v161];
      int * v60 = v19->cache_age;
      int v186 = v59 + ((int)((unsigned int)(v59 - v57) >> 31));
      v60[v161] = v186;
      int * v62 = v19->cache_age;
      int v63 = v62[v163];
      int * v64 = v19->cache_age;
      int v189 = v63 + ((int)((unsigned int)(v63 - v57) >> 31));
      v64[v163] = v189;
      int * v66 = v19->cache_age;
      v66[v183] = 0;
      v119 = v183;
    } else {
      int * v69 = v19->cache_age;
      int v193 = 4 + ((((int)((unsigned int)((int)((unsigned int)v23 >> 2)) >> 1)) & 3) * 2);
      int v70 = v69[v193];
      int * v71 = v19->cache_tags;
      int v72 = v71[v193];
      int * v73 = v19->cache_age;
      int v74 = v73[v163];
      int * v75 = v19->cache_tags;
      int v76 = v75[v163];
      int * v77 = v19->cache_dirty;
      int v198 = (4 + ((((int)((unsigned int)((int)((unsigned int)v23 >> 2)) >> 1)) & 3) * 2)) + ((((v70 + ((~(((v72 ^ -1) | (-(v72 ^ -1))) >> 31)) & 2)) - (v74 + ((~(((v76 ^ -1) | (-(v76 ^ -1))) >> 31)) & 2))) >> 31) & 1);
      int v78 = v77[v198];
      bool v199 = !(v78 == 0);
      if (v199) {
        int * v79 = v19->cache_tags;
        int v80 = v79[v198];
        int * v81 = v19->cache_vals;
        int v202 = ((4 + ((((int)((unsigned int)((int)((unsigned int)v23 >> 2)) >> 1)) & 3) * 2)) + ((((v70 + ((~(((v72 ^ -1) | (-(v72 ^ -1))) >> 31)) & 2)) - (v74 + ((~(((v76 ^ -1) | (-(v76 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
        int v82 = v81[v202];
        int * v83 = v19->cache_vals;
        int v204 = (((4 + ((((int)((unsigned int)((int)((unsigned int)v23 >> 2)) >> 1)) & 3) * 2)) + ((((v70 + ((~(((v72 ^ -1) | (-(v72 ^ -1))) >> 31)) & 2)) - (v74 + ((~(((v76 ^ -1) | (-(v76 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
        int v84 = v83[v204];
        int * v85 = v19->mem;
        int v206 = v80 * 2;
        v85[v206] = v82;
        int * v87 = v19->mem;
        int v209 = (v80 * 2) + 1;
        v87[v209] = v84;
        ;
      } else {
        ;
      }
      int * v92 = v19->mem;
      int v214 = ((int)((unsigned int)((int)((unsigned int)v23 >> 2)) >> 1)) * 2;
      int v93 = v92[v214];
      int * v94 = v19->mem;
      int v216 = (((int)((unsigned int)((int)((unsigned int)v23 >> 2)) >> 1)) * 2) + 1;
      int v95 = v94[v216];
      int * v96 = v19->cache_vals;
      int v218 = ((4 + ((((int)((unsigned int)((int)((unsigned int)v23 >> 2)) >> 1)) & 3) * 2)) + ((((v70 + ((~(((v72 ^ -1) | (-(v72 ^ -1))) >> 31)) & 2)) - (v74 + ((~(((v76 ^ -1) | (-(v76 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
      v96[v218] = v93;
      int * v98 = v19->cache_vals;
      int v221 = (((4 + ((((int)((unsigned int)((int)((unsigned int)v23 >> 2)) >> 1)) & 3) * 2)) + ((((v70 + ((~(((v72 ^ -1) | (-(v72 ^ -1))) >> 31)) & 2)) - (v74 + ((~(((v76 ^ -1) | (-(v76 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
      v98[v221] = v95;
      int * v100 = v19->cache_tags;
      int v224 = (int)((unsigned int)((int)((unsigned int)v23 >> 2)) >> 1);
      v100[v198] = v224;
      int * v102 = v19->cache_dirty;
      v102[v198] = 0;
      int * v104 = v19->cache_age;
      v104[v198] = 1;
      int * v106 = v19->cache_age;
      int v107 = v106[v198];
      int * v108 = v19->cache_age;
      int v109 = v108[v161];
      int * v110 = v19->cache_age;
      int v232 = v109 + ((int)((unsigned int)(v109 - v107) >> 31));
      v110[v161] = v232;
      int * v112 = v19->cache_age;
      int v113 = v112[v163];
      int * v114 = v19->cache_age;
      int v235 = v113 + ((int)((unsigned int)(v113 - v107) >> 31));
      v114[v163] = v235;
      int * v116 = v19->cache_age;
      v116[v198] = 0;
      v119 = v198;
    }
    int * v120 = v19->cache_vals;
    int v238 = v119 * 2;
    int v121 = v120[v238];
    int * v122 = v19->cache_vals;
    int v240 = (v119 * 2) + 1;
    int v123 = v122[v240];
    int * v124 = v19->cache_vals;
    int v242 = (((((int)((unsigned int)((int)((unsigned int)v23 >> 2)) >> 1)) & 1) * 2) + ((((v49 + ((~(((v51 ^ -1) | (-(v51 ^ -1))) >> 31)) & 2)) - (v53 + ((~(((v55 ^ -1) | (-(v55 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
    v124[v242] = v121;
    int * v126 = v19->cache_vals;
    int v245 = ((((((int)((unsigned int)((int)((unsigned int)v23 >> 2)) >> 1)) & 1) * 2) + ((((v49 + ((~(((v51 ^ -1) | (-(v51 ^ -1))) >> 31)) & 2)) - (v53 + ((~(((v55 ^ -1) | (-(v55 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
    v126[v245] = v123;
    int * v128 = v19->cache_tags;
    int v248 = ((((int)((unsigned int)((int)((unsigned int)v23 >> 2)) >> 1)) & 1) * 2) + ((((v49 + ((~(((v51 ^ -1) | (-(v51 ^ -1))) >> 31)) & 2)) - (v53 + ((~(((v55 ^ -1) | (-(v55 ^ -1))) >> 31)) & 2))) >> 31) & 1);
    int v249 = (int)((unsigned int)((int)((unsigned int)v23 >> 2)) >> 1);
    v128[v248] = v249;
    int * v130 = v19->cache_dirty;
    v130[v248] = 0;
    int * v132 = v19->cache_age;
    v132[v248] = 1;
    int * v134 = v19->cache_age;
    int v135 = v134[v248];
    int * v136 = v19->cache_age;
    int v137 = v136[v157];
    int * v138 = v19->cache_age;
    int v257 = v137 + ((int)((unsigned int)(v137 - v135) >> 31));
    v138[v157] = v257;
    int * v140 = v19->cache_age;
    int v141 = v140[v159];
    int * v142 = v19->cache_age;
    int v260 = v141 + ((int)((unsigned int)(v141 - v135) >> 31));
    v142[v159] = v260;
    int * v144 = v19->cache_age;
    v144[v248] = 0;
    v147 = v248;
  }
  int v263 = (v147 * 2) + (((int)((unsigned int)v23 >> 2)) & 1);
  int v148 = v34[v263];
  int * v149 = v19->regs;
  v149[11] = v148;
  struct StateT * v151 = slot_2(v19);
  return v151;
}

struct StateT * slot_2(struct StateT * v269) {
  int v270 = v269->timer;
  int v278 = v270 + 1;
  v269->timer = v278;
  int * v272 = v269->regs;
  int v273 = v272[11];
  int * v274 = v269->regs;
  int v282 = v273 << 2;
  v274[11] = v282;
  struct StateT * v276 = slot_3(v269);
  return v276;
}

struct StateT * slot_3(struct StateT * v285) {
  int v286 = v285->timer;
  int v418 = v286 + 1;
  v285->timer = v418;
  int * v288 = v285->regs;
  int v289 = v288[11];
  int * v290 = v285->cache_tags;
  int v422 = (((int)((unsigned int)((int)((unsigned int)(v289 + 16) >> 2)) >> 1)) & 1) * 2;
  int v291 = v290[v422];
  int * v292 = v285->cache_tags;
  int v424 = ((((int)((unsigned int)((int)((unsigned int)(v289 + 16) >> 2)) >> 1)) & 1) * 2) + 1;
  int v293 = v292[v424];
  int * v294 = v285->cache_tags;
  int v426 = 4 + ((((int)((unsigned int)((int)((unsigned int)(v289 + 16) >> 2)) >> 1)) & 3) * 2);
  int v295 = v294[v426];
  int * v296 = v285->cache_tags;
  int v428 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v289 + 16) >> 2)) >> 1)) & 3) * 2)) + 1;
  int v297 = v296[v428];
  int v298 = v285->timer;
  int v429 = v298 + ((100 ^ (((~(((v295 ^ ((int)((unsigned int)((int)((unsigned int)(v289 + 16) >> 2)) >> 1))) | (-(v295 ^ ((int)((unsigned int)((int)((unsigned int)(v289 + 16) >> 2)) >> 1))))) >> 31)) | (~(((v297 ^ ((int)((unsigned int)((int)((unsigned int)(v289 + 16) >> 2)) >> 1))) | (-(v297 ^ ((int)((unsigned int)((int)((unsigned int)(v289 + 16) >> 2)) >> 1))))) >> 31))) & 104)) ^ (((~(((v291 ^ ((int)((unsigned int)((int)((unsigned int)(v289 + 16) >> 2)) >> 1))) | (-(v291 ^ ((int)((unsigned int)((int)((unsigned int)(v289 + 16) >> 2)) >> 1))))) >> 31)) | (~(((v293 ^ ((int)((unsigned int)((int)((unsigned int)(v289 + 16) >> 2)) >> 1))) | (-(v293 ^ ((int)((unsigned int)((int)((unsigned int)(v289 + 16) >> 2)) >> 1))))) >> 31))) & (1 ^ (100 ^ (((~(((v295 ^ ((int)((unsigned int)((int)((unsigned int)(v289 + 16) >> 2)) >> 1))) | (-(v295 ^ ((int)((unsigned int)((int)((unsigned int)(v289 + 16) >> 2)) >> 1))))) >> 31)) | (~(((v297 ^ ((int)((unsigned int)((int)((unsigned int)(v289 + 16) >> 2)) >> 1))) | (-(v297 ^ ((int)((unsigned int)((int)((unsigned int)(v289 + 16) >> 2)) >> 1))))) >> 31))) & 104)))));
  v285->timer = v429;
  int * v300 = v285->cache_vals;
  bool v430 = !(((~(((v291 ^ ((int)((unsigned int)((int)((unsigned int)(v289 + 16) >> 2)) >> 1))) | (-(v291 ^ ((int)((unsigned int)((int)((unsigned int)(v289 + 16) >> 2)) >> 1))))) >> 31)) | (~(((v293 ^ ((int)((unsigned int)((int)((unsigned int)(v289 + 16) >> 2)) >> 1))) | (-(v293 ^ ((int)((unsigned int)((int)((unsigned int)(v289 + 16) >> 2)) >> 1))))) >> 31))) == 0);
  int v413;
  if (v430) {
    int * v301 = v285->cache_age;
    int v432 = ((((int)((unsigned int)((int)((unsigned int)(v289 + 16) >> 2)) >> 1)) & 1) * 2) + ((~(((v293 ^ ((int)((unsigned int)((int)((unsigned int)(v289 + 16) >> 2)) >> 1))) | (-(v293 ^ ((int)((unsigned int)((int)((unsigned int)(v289 + 16) >> 2)) >> 1))))) >> 31)) & 1);
    int v302 = v301[v432];
    int * v303 = v285->cache_age;
    int v304 = v303[v422];
    int * v305 = v285->cache_age;
    int v435 = v304 + ((int)((unsigned int)(v304 - v302) >> 31));
    v305[v422] = v435;
    int * v307 = v285->cache_age;
    int v308 = v307[v424];
    int * v309 = v285->cache_age;
    int v438 = v308 + ((int)((unsigned int)(v308 - v302) >> 31));
    v309[v424] = v438;
    int * v311 = v285->cache_age;
    v311[v432] = 0;
    v413 = v432;
  } else {
    int * v314 = v285->cache_age;
    int v442 = (((int)((unsigned int)((int)((unsigned int)(v289 + 16) >> 2)) >> 1)) & 1) * 2;
    int v315 = v314[v442];
    int * v316 = v285->cache_tags;
    int v317 = v316[v442];
    int * v318 = v285->cache_age;
    int v319 = v318[v424];
    int * v320 = v285->cache_tags;
    int v321 = v320[v424];
    bool v446 = !(((~(((v295 ^ ((int)((unsigned int)((int)((unsigned int)(v289 + 16) >> 2)) >> 1))) | (-(v295 ^ ((int)((unsigned int)((int)((unsigned int)(v289 + 16) >> 2)) >> 1))))) >> 31)) | (~(((v297 ^ ((int)((unsigned int)((int)((unsigned int)(v289 + 16) >> 2)) >> 1))) | (-(v297 ^ ((int)((unsigned int)((int)((unsigned int)(v289 + 16) >> 2)) >> 1))))) >> 31))) == 0);
    int v385;
    if (v446) {
      int * v322 = v285->cache_age;
      int v448 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v289 + 16) >> 2)) >> 1)) & 3) * 2)) + ((~(((v297 ^ ((int)((unsigned int)((int)((unsigned int)(v289 + 16) >> 2)) >> 1))) | (-(v297 ^ ((int)((unsigned int)((int)((unsigned int)(v289 + 16) >> 2)) >> 1))))) >> 31)) & 1);
      int v323 = v322[v448];
      int * v324 = v285->cache_age;
      int v325 = v324[v426];
      int * v326 = v285->cache_age;
      int v451 = v325 + ((int)((unsigned int)(v325 - v323) >> 31));
      v326[v426] = v451;
      int * v328 = v285->cache_age;
      int v329 = v328[v428];
      int * v330 = v285->cache_age;
      int v454 = v329 + ((int)((unsigned int)(v329 - v323) >> 31));
      v330[v428] = v454;
      int * v332 = v285->cache_age;
      v332[v448] = 0;
      v385 = v448;
    } else {
      int * v335 = v285->cache_age;
      int v458 = 4 + ((((int)((unsigned int)((int)((unsigned int)(v289 + 16) >> 2)) >> 1)) & 3) * 2);
      int v336 = v335[v458];
      int * v337 = v285->cache_tags;
      int v338 = v337[v458];
      int * v339 = v285->cache_age;
      int v340 = v339[v428];
      int * v341 = v285->cache_tags;
      int v342 = v341[v428];
      int * v343 = v285->cache_dirty;
      int v463 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v289 + 16) >> 2)) >> 1)) & 3) * 2)) + ((((v336 + ((~(((v338 ^ -1) | (-(v338 ^ -1))) >> 31)) & 2)) - (v340 + ((~(((v342 ^ -1) | (-(v342 ^ -1))) >> 31)) & 2))) >> 31) & 1);
      int v344 = v343[v463];
      bool v464 = !(v344 == 0);
      if (v464) {
        int * v345 = v285->cache_tags;
        int v346 = v345[v463];
        int * v347 = v285->cache_vals;
        int v467 = ((4 + ((((int)((unsigned int)((int)((unsigned int)(v289 + 16) >> 2)) >> 1)) & 3) * 2)) + ((((v336 + ((~(((v338 ^ -1) | (-(v338 ^ -1))) >> 31)) & 2)) - (v340 + ((~(((v342 ^ -1) | (-(v342 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
        int v348 = v347[v467];
        int * v349 = v285->cache_vals;
        int v469 = (((4 + ((((int)((unsigned int)((int)((unsigned int)(v289 + 16) >> 2)) >> 1)) & 3) * 2)) + ((((v336 + ((~(((v338 ^ -1) | (-(v338 ^ -1))) >> 31)) & 2)) - (v340 + ((~(((v342 ^ -1) | (-(v342 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
        int v350 = v349[v469];
        int * v351 = v285->mem;
        int v471 = v346 * 2;
        v351[v471] = v348;
        int * v353 = v285->mem;
        int v474 = (v346 * 2) + 1;
        v353[v474] = v350;
        ;
      } else {
        ;
      }
      int * v358 = v285->mem;
      int v479 = ((int)((unsigned int)((int)((unsigned int)(v289 + 16) >> 2)) >> 1)) * 2;
      int v359 = v358[v479];
      int * v360 = v285->mem;
      int v481 = (((int)((unsigned int)((int)((unsigned int)(v289 + 16) >> 2)) >> 1)) * 2) + 1;
      int v361 = v360[v481];
      int * v362 = v285->cache_vals;
      int v483 = ((4 + ((((int)((unsigned int)((int)((unsigned int)(v289 + 16) >> 2)) >> 1)) & 3) * 2)) + ((((v336 + ((~(((v338 ^ -1) | (-(v338 ^ -1))) >> 31)) & 2)) - (v340 + ((~(((v342 ^ -1) | (-(v342 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
      v362[v483] = v359;
      int * v364 = v285->cache_vals;
      int v486 = (((4 + ((((int)((unsigned int)((int)((unsigned int)(v289 + 16) >> 2)) >> 1)) & 3) * 2)) + ((((v336 + ((~(((v338 ^ -1) | (-(v338 ^ -1))) >> 31)) & 2)) - (v340 + ((~(((v342 ^ -1) | (-(v342 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
      v364[v486] = v361;
      int * v366 = v285->cache_tags;
      int v489 = (int)((unsigned int)((int)((unsigned int)(v289 + 16) >> 2)) >> 1);
      v366[v463] = v489;
      int * v368 = v285->cache_dirty;
      v368[v463] = 0;
      int * v370 = v285->cache_age;
      v370[v463] = 1;
      int * v372 = v285->cache_age;
      int v373 = v372[v463];
      int * v374 = v285->cache_age;
      int v375 = v374[v426];
      int * v376 = v285->cache_age;
      int v497 = v375 + ((int)((unsigned int)(v375 - v373) >> 31));
      v376[v426] = v497;
      int * v378 = v285->cache_age;
      int v379 = v378[v428];
      int * v380 = v285->cache_age;
      int v500 = v379 + ((int)((unsigned int)(v379 - v373) >> 31));
      v380[v428] = v500;
      int * v382 = v285->cache_age;
      v382[v463] = 0;
      v385 = v463;
    }
    int * v386 = v285->cache_vals;
    int v503 = v385 * 2;
    int v387 = v386[v503];
    int * v388 = v285->cache_vals;
    int v505 = (v385 * 2) + 1;
    int v389 = v388[v505];
    int * v390 = v285->cache_vals;
    int v507 = (((((int)((unsigned int)((int)((unsigned int)(v289 + 16) >> 2)) >> 1)) & 1) * 2) + ((((v315 + ((~(((v317 ^ -1) | (-(v317 ^ -1))) >> 31)) & 2)) - (v319 + ((~(((v321 ^ -1) | (-(v321 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
    v390[v507] = v387;
    int * v392 = v285->cache_vals;
    int v510 = ((((((int)((unsigned int)((int)((unsigned int)(v289 + 16) >> 2)) >> 1)) & 1) * 2) + ((((v315 + ((~(((v317 ^ -1) | (-(v317 ^ -1))) >> 31)) & 2)) - (v319 + ((~(((v321 ^ -1) | (-(v321 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
    v392[v510] = v389;
    int * v394 = v285->cache_tags;
    int v513 = ((((int)((unsigned int)((int)((unsigned int)(v289 + 16) >> 2)) >> 1)) & 1) * 2) + ((((v315 + ((~(((v317 ^ -1) | (-(v317 ^ -1))) >> 31)) & 2)) - (v319 + ((~(((v321 ^ -1) | (-(v321 ^ -1))) >> 31)) & 2))) >> 31) & 1);
    int v514 = (int)((unsigned int)((int)((unsigned int)(v289 + 16) >> 2)) >> 1);
    v394[v513] = v514;
    int * v396 = v285->cache_dirty;
    v396[v513] = 0;
    int * v398 = v285->cache_age;
    v398[v513] = 1;
    int * v400 = v285->cache_age;
    int v401 = v400[v513];
    int * v402 = v285->cache_age;
    int v403 = v402[v422];
    int * v404 = v285->cache_age;
    int v522 = v403 + ((int)((unsigned int)(v403 - v401) >> 31));
    v404[v422] = v522;
    int * v406 = v285->cache_age;
    int v407 = v406[v424];
    int * v408 = v285->cache_age;
    int v525 = v407 + ((int)((unsigned int)(v407 - v401) >> 31));
    v408[v424] = v525;
    int * v410 = v285->cache_age;
    v410[v513] = 0;
    v413 = v513;
  }
  int v528 = (v413 * 2) + (((int)((unsigned int)(v289 + 16) >> 2)) & 1);
  int v414 = v300[v528];
  int * v415 = v285->regs;
  v415[12] = v414;
  return v285;
}

struct StateT * slot_0(struct StateT * v2) {
  int v3 = v2->timer;
  int v12 = v3 + 1;
  v2->timer = v12;
  int * v5 = v2->regs;
  int v6 = v5[10];
  bool v15 = v6 == 0;
  struct StateT * v10;
  if (v15) {
    v10 = v2;
  } else {
    struct StateT * v8 = slot_1(v2);
    v10 = v8;
  }
  return v10;
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
    s1.mem[SECRET_OFFSET+i] = bounded(0, 20);
    s2.mem[SECRET_OFFSET+i] = bounded(0, 20);
  }
  struct StateT *s1_ = snippet(&s1);
  struct StateT *s2_ = snippet(&s2);
  koika_assert(s1_->timer==s2_->timer, "timing leak");
  return 0;
}