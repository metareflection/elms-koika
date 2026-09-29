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
struct StateT * slot_1(struct StateT * v10);
struct StateT * slot_4(struct StateT * v540);
struct StateT * slot_2(struct StateT * v267);
struct StateT * slot_3(struct StateT * v283);
struct StateT * slot_0(struct StateT * v2);
struct StateT * snippet(struct StateT * v0) {
  struct StateT * v1 = slot_0(v0);
  return v1;
}

struct StateT * slot_1(struct StateT * v10) {
  int * v11 = v10->saved_regs;
  int * v12 = v10->regs;
  int v13 = v12[11];
  v11[11] = v13;
  int v15 = v10->timer;
  int v152 = v15 + 1;
  v10->timer = v152;
  int * v17 = v10->regs;
  int v18 = v17[10];
  int * v19 = v10->cache_tags;
  int v156 = (((int)((unsigned int)((int)((unsigned int)v18 >> 2)) >> 1)) & 1) * 2;
  int v20 = v19[v156];
  int * v21 = v10->cache_tags;
  int v158 = ((((int)((unsigned int)((int)((unsigned int)v18 >> 2)) >> 1)) & 1) * 2) + 1;
  int v22 = v21[v158];
  int * v23 = v10->cache_tags;
  int v160 = 4 + ((((int)((unsigned int)((int)((unsigned int)v18 >> 2)) >> 1)) & 3) * 2);
  int v24 = v23[v160];
  int * v25 = v10->cache_tags;
  int v162 = (4 + ((((int)((unsigned int)((int)((unsigned int)v18 >> 2)) >> 1)) & 3) * 2)) + 1;
  int v26 = v25[v162];
  int v27 = v10->timer;
  int v163 = v27 + ((100 ^ (((~(((v24 ^ ((int)((unsigned int)((int)((unsigned int)v18 >> 2)) >> 1))) | (-(v24 ^ ((int)((unsigned int)((int)((unsigned int)v18 >> 2)) >> 1))))) >> 31)) | (~(((v26 ^ ((int)((unsigned int)((int)((unsigned int)v18 >> 2)) >> 1))) | (-(v26 ^ ((int)((unsigned int)((int)((unsigned int)v18 >> 2)) >> 1))))) >> 31))) & 104)) ^ (((~(((v20 ^ ((int)((unsigned int)((int)((unsigned int)v18 >> 2)) >> 1))) | (-(v20 ^ ((int)((unsigned int)((int)((unsigned int)v18 >> 2)) >> 1))))) >> 31)) | (~(((v22 ^ ((int)((unsigned int)((int)((unsigned int)v18 >> 2)) >> 1))) | (-(v22 ^ ((int)((unsigned int)((int)((unsigned int)v18 >> 2)) >> 1))))) >> 31))) & (1 ^ (100 ^ (((~(((v24 ^ ((int)((unsigned int)((int)((unsigned int)v18 >> 2)) >> 1))) | (-(v24 ^ ((int)((unsigned int)((int)((unsigned int)v18 >> 2)) >> 1))))) >> 31)) | (~(((v26 ^ ((int)((unsigned int)((int)((unsigned int)v18 >> 2)) >> 1))) | (-(v26 ^ ((int)((unsigned int)((int)((unsigned int)v18 >> 2)) >> 1))))) >> 31))) & 104)))));
  v10->timer = v163;
  int * v29 = v10->cache_vals;
  bool v164 = !(((~(((v20 ^ ((int)((unsigned int)((int)((unsigned int)v18 >> 2)) >> 1))) | (-(v20 ^ ((int)((unsigned int)((int)((unsigned int)v18 >> 2)) >> 1))))) >> 31)) | (~(((v22 ^ ((int)((unsigned int)((int)((unsigned int)v18 >> 2)) >> 1))) | (-(v22 ^ ((int)((unsigned int)((int)((unsigned int)v18 >> 2)) >> 1))))) >> 31))) == 0);
  int v142;
  if (v164) {
    int * v30 = v10->cache_age;
    int v166 = ((((int)((unsigned int)((int)((unsigned int)v18 >> 2)) >> 1)) & 1) * 2) + ((~(((v22 ^ ((int)((unsigned int)((int)((unsigned int)v18 >> 2)) >> 1))) | (-(v22 ^ ((int)((unsigned int)((int)((unsigned int)v18 >> 2)) >> 1))))) >> 31)) & 1);
    int v31 = v30[v166];
    int * v32 = v10->cache_age;
    int v33 = v32[v156];
    int * v34 = v10->cache_age;
    int v169 = v33 + ((int)((unsigned int)(v33 - v31) >> 31));
    v34[v156] = v169;
    int * v36 = v10->cache_age;
    int v37 = v36[v158];
    int * v38 = v10->cache_age;
    int v172 = v37 + ((int)((unsigned int)(v37 - v31) >> 31));
    v38[v158] = v172;
    int * v40 = v10->cache_age;
    v40[v166] = 0;
    v142 = v166;
  } else {
    int * v43 = v10->cache_age;
    int v176 = (((int)((unsigned int)((int)((unsigned int)v18 >> 2)) >> 1)) & 1) * 2;
    int v44 = v43[v176];
    int * v45 = v10->cache_tags;
    int v46 = v45[v176];
    int * v47 = v10->cache_age;
    int v48 = v47[v158];
    int * v49 = v10->cache_tags;
    int v50 = v49[v158];
    bool v180 = !(((~(((v24 ^ ((int)((unsigned int)((int)((unsigned int)v18 >> 2)) >> 1))) | (-(v24 ^ ((int)((unsigned int)((int)((unsigned int)v18 >> 2)) >> 1))))) >> 31)) | (~(((v26 ^ ((int)((unsigned int)((int)((unsigned int)v18 >> 2)) >> 1))) | (-(v26 ^ ((int)((unsigned int)((int)((unsigned int)v18 >> 2)) >> 1))))) >> 31))) == 0);
    int v114;
    if (v180) {
      int * v51 = v10->cache_age;
      int v182 = (4 + ((((int)((unsigned int)((int)((unsigned int)v18 >> 2)) >> 1)) & 3) * 2)) + ((~(((v26 ^ ((int)((unsigned int)((int)((unsigned int)v18 >> 2)) >> 1))) | (-(v26 ^ ((int)((unsigned int)((int)((unsigned int)v18 >> 2)) >> 1))))) >> 31)) & 1);
      int v52 = v51[v182];
      int * v53 = v10->cache_age;
      int v54 = v53[v160];
      int * v55 = v10->cache_age;
      int v185 = v54 + ((int)((unsigned int)(v54 - v52) >> 31));
      v55[v160] = v185;
      int * v57 = v10->cache_age;
      int v58 = v57[v162];
      int * v59 = v10->cache_age;
      int v188 = v58 + ((int)((unsigned int)(v58 - v52) >> 31));
      v59[v162] = v188;
      int * v61 = v10->cache_age;
      v61[v182] = 0;
      v114 = v182;
    } else {
      int * v64 = v10->cache_age;
      int v192 = 4 + ((((int)((unsigned int)((int)((unsigned int)v18 >> 2)) >> 1)) & 3) * 2);
      int v65 = v64[v192];
      int * v66 = v10->cache_tags;
      int v67 = v66[v192];
      int * v68 = v10->cache_age;
      int v69 = v68[v162];
      int * v70 = v10->cache_tags;
      int v71 = v70[v162];
      int * v72 = v10->cache_dirty;
      int v197 = (4 + ((((int)((unsigned int)((int)((unsigned int)v18 >> 2)) >> 1)) & 3) * 2)) + ((((v65 + ((~(((v67 ^ -1) | (-(v67 ^ -1))) >> 31)) & 2)) - (v69 + ((~(((v71 ^ -1) | (-(v71 ^ -1))) >> 31)) & 2))) >> 31) & 1);
      int v73 = v72[v197];
      bool v198 = !(v73 == 0);
      if (v198) {
        int * v74 = v10->cache_tags;
        int v75 = v74[v197];
        int * v76 = v10->cache_vals;
        int v201 = ((4 + ((((int)((unsigned int)((int)((unsigned int)v18 >> 2)) >> 1)) & 3) * 2)) + ((((v65 + ((~(((v67 ^ -1) | (-(v67 ^ -1))) >> 31)) & 2)) - (v69 + ((~(((v71 ^ -1) | (-(v71 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
        int v77 = v76[v201];
        int * v78 = v10->cache_vals;
        int v203 = (((4 + ((((int)((unsigned int)((int)((unsigned int)v18 >> 2)) >> 1)) & 3) * 2)) + ((((v65 + ((~(((v67 ^ -1) | (-(v67 ^ -1))) >> 31)) & 2)) - (v69 + ((~(((v71 ^ -1) | (-(v71 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
        int v79 = v78[v203];
        int * v80 = v10->mem;
        int v205 = v75 * 2;
        v80[v205] = v77;
        int * v82 = v10->mem;
        int v208 = (v75 * 2) + 1;
        v82[v208] = v79;
        ;
      } else {
        ;
      }
      int * v87 = v10->mem;
      int v213 = ((int)((unsigned int)((int)((unsigned int)v18 >> 2)) >> 1)) * 2;
      int v88 = v87[v213];
      int * v89 = v10->mem;
      int v215 = (((int)((unsigned int)((int)((unsigned int)v18 >> 2)) >> 1)) * 2) + 1;
      int v90 = v89[v215];
      int * v91 = v10->cache_vals;
      int v217 = ((4 + ((((int)((unsigned int)((int)((unsigned int)v18 >> 2)) >> 1)) & 3) * 2)) + ((((v65 + ((~(((v67 ^ -1) | (-(v67 ^ -1))) >> 31)) & 2)) - (v69 + ((~(((v71 ^ -1) | (-(v71 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
      v91[v217] = v88;
      int * v93 = v10->cache_vals;
      int v220 = (((4 + ((((int)((unsigned int)((int)((unsigned int)v18 >> 2)) >> 1)) & 3) * 2)) + ((((v65 + ((~(((v67 ^ -1) | (-(v67 ^ -1))) >> 31)) & 2)) - (v69 + ((~(((v71 ^ -1) | (-(v71 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
      v93[v220] = v90;
      int * v95 = v10->cache_tags;
      int v223 = (int)((unsigned int)((int)((unsigned int)v18 >> 2)) >> 1);
      v95[v197] = v223;
      int * v97 = v10->cache_dirty;
      v97[v197] = 0;
      int * v99 = v10->cache_age;
      v99[v197] = 1;
      int * v101 = v10->cache_age;
      int v102 = v101[v197];
      int * v103 = v10->cache_age;
      int v104 = v103[v160];
      int * v105 = v10->cache_age;
      int v231 = v104 + ((int)((unsigned int)(v104 - v102) >> 31));
      v105[v160] = v231;
      int * v107 = v10->cache_age;
      int v108 = v107[v162];
      int * v109 = v10->cache_age;
      int v234 = v108 + ((int)((unsigned int)(v108 - v102) >> 31));
      v109[v162] = v234;
      int * v111 = v10->cache_age;
      v111[v197] = 0;
      v114 = v197;
    }
    int * v115 = v10->cache_vals;
    int v237 = v114 * 2;
    int v116 = v115[v237];
    int * v117 = v10->cache_vals;
    int v239 = (v114 * 2) + 1;
    int v118 = v117[v239];
    int * v119 = v10->cache_vals;
    int v241 = (((((int)((unsigned int)((int)((unsigned int)v18 >> 2)) >> 1)) & 1) * 2) + ((((v44 + ((~(((v46 ^ -1) | (-(v46 ^ -1))) >> 31)) & 2)) - (v48 + ((~(((v50 ^ -1) | (-(v50 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
    v119[v241] = v116;
    int * v121 = v10->cache_vals;
    int v244 = ((((((int)((unsigned int)((int)((unsigned int)v18 >> 2)) >> 1)) & 1) * 2) + ((((v44 + ((~(((v46 ^ -1) | (-(v46 ^ -1))) >> 31)) & 2)) - (v48 + ((~(((v50 ^ -1) | (-(v50 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
    v121[v244] = v118;
    int * v123 = v10->cache_tags;
    int v247 = ((((int)((unsigned int)((int)((unsigned int)v18 >> 2)) >> 1)) & 1) * 2) + ((((v44 + ((~(((v46 ^ -1) | (-(v46 ^ -1))) >> 31)) & 2)) - (v48 + ((~(((v50 ^ -1) | (-(v50 ^ -1))) >> 31)) & 2))) >> 31) & 1);
    int v248 = (int)((unsigned int)((int)((unsigned int)v18 >> 2)) >> 1);
    v123[v247] = v248;
    int * v125 = v10->cache_dirty;
    v125[v247] = 0;
    int * v127 = v10->cache_age;
    v127[v247] = 1;
    int * v129 = v10->cache_age;
    int v130 = v129[v247];
    int * v131 = v10->cache_age;
    int v132 = v131[v156];
    int * v133 = v10->cache_age;
    int v256 = v132 + ((int)((unsigned int)(v132 - v130) >> 31));
    v133[v156] = v256;
    int * v135 = v10->cache_age;
    int v136 = v135[v158];
    int * v137 = v10->cache_age;
    int v259 = v136 + ((int)((unsigned int)(v136 - v130) >> 31));
    v137[v158] = v259;
    int * v139 = v10->cache_age;
    v139[v247] = 0;
    v142 = v247;
  }
  int v262 = (v142 * 2) + (((int)((unsigned int)v18 >> 2)) & 1);
  int v143 = v29[v262];
  int * v144 = v10->regs;
  v144[11] = v143;
  struct StateT * v146 = slot_2(v10);
  return v146;
}

struct StateT * slot_4(struct StateT * v540) {
  int * v541 = v540->regs;
  int v542 = v541[10];
  bool v559 = v542 == 0;
  struct StateT * v555;
  if (v559) {
    int v543 = v540->timer;
    int v560 = v543 + 15;
    v540->timer = v560;
    int * v545 = v540->saved_regs;
    int v546 = v545[11];
    int * v547 = v540->regs;
    v547[11] = v546;
    int * v549 = v540->saved_regs;
    int v550 = v549[12];
    int * v551 = v540->regs;
    v551[12] = v550;
    v555 = v540;
  } else {
    v555 = v540;
  }
  return v555;
}

struct StateT * slot_2(struct StateT * v267) {
  int v268 = v267->timer;
  int v276 = v268 + 1;
  v267->timer = v276;
  int * v270 = v267->regs;
  int v271 = v270[11];
  int * v272 = v267->regs;
  int v280 = v271 << 2;
  v272[11] = v280;
  struct StateT * v274 = slot_3(v267);
  return v274;
}

struct StateT * slot_3(struct StateT * v283) {
  int * v284 = v283->saved_regs;
  int * v285 = v283->regs;
  int v286 = v285[12];
  v284[12] = v286;
  int v288 = v283->timer;
  int v425 = v288 + 1;
  v283->timer = v425;
  int * v290 = v283->regs;
  int v291 = v290[11];
  int * v292 = v283->cache_tags;
  int v429 = (((int)((unsigned int)((int)((unsigned int)(v291 + 16) >> 2)) >> 1)) & 1) * 2;
  int v293 = v292[v429];
  int * v294 = v283->cache_tags;
  int v431 = ((((int)((unsigned int)((int)((unsigned int)(v291 + 16) >> 2)) >> 1)) & 1) * 2) + 1;
  int v295 = v294[v431];
  int * v296 = v283->cache_tags;
  int v433 = 4 + ((((int)((unsigned int)((int)((unsigned int)(v291 + 16) >> 2)) >> 1)) & 3) * 2);
  int v297 = v296[v433];
  int * v298 = v283->cache_tags;
  int v435 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v291 + 16) >> 2)) >> 1)) & 3) * 2)) + 1;
  int v299 = v298[v435];
  int v300 = v283->timer;
  int v436 = v300 + ((100 ^ (((~(((v297 ^ ((int)((unsigned int)((int)((unsigned int)(v291 + 16) >> 2)) >> 1))) | (-(v297 ^ ((int)((unsigned int)((int)((unsigned int)(v291 + 16) >> 2)) >> 1))))) >> 31)) | (~(((v299 ^ ((int)((unsigned int)((int)((unsigned int)(v291 + 16) >> 2)) >> 1))) | (-(v299 ^ ((int)((unsigned int)((int)((unsigned int)(v291 + 16) >> 2)) >> 1))))) >> 31))) & 104)) ^ (((~(((v293 ^ ((int)((unsigned int)((int)((unsigned int)(v291 + 16) >> 2)) >> 1))) | (-(v293 ^ ((int)((unsigned int)((int)((unsigned int)(v291 + 16) >> 2)) >> 1))))) >> 31)) | (~(((v295 ^ ((int)((unsigned int)((int)((unsigned int)(v291 + 16) >> 2)) >> 1))) | (-(v295 ^ ((int)((unsigned int)((int)((unsigned int)(v291 + 16) >> 2)) >> 1))))) >> 31))) & (1 ^ (100 ^ (((~(((v297 ^ ((int)((unsigned int)((int)((unsigned int)(v291 + 16) >> 2)) >> 1))) | (-(v297 ^ ((int)((unsigned int)((int)((unsigned int)(v291 + 16) >> 2)) >> 1))))) >> 31)) | (~(((v299 ^ ((int)((unsigned int)((int)((unsigned int)(v291 + 16) >> 2)) >> 1))) | (-(v299 ^ ((int)((unsigned int)((int)((unsigned int)(v291 + 16) >> 2)) >> 1))))) >> 31))) & 104)))));
  v283->timer = v436;
  int * v302 = v283->cache_vals;
  bool v437 = !(((~(((v293 ^ ((int)((unsigned int)((int)((unsigned int)(v291 + 16) >> 2)) >> 1))) | (-(v293 ^ ((int)((unsigned int)((int)((unsigned int)(v291 + 16) >> 2)) >> 1))))) >> 31)) | (~(((v295 ^ ((int)((unsigned int)((int)((unsigned int)(v291 + 16) >> 2)) >> 1))) | (-(v295 ^ ((int)((unsigned int)((int)((unsigned int)(v291 + 16) >> 2)) >> 1))))) >> 31))) == 0);
  int v415;
  if (v437) {
    int * v303 = v283->cache_age;
    int v439 = ((((int)((unsigned int)((int)((unsigned int)(v291 + 16) >> 2)) >> 1)) & 1) * 2) + ((~(((v295 ^ ((int)((unsigned int)((int)((unsigned int)(v291 + 16) >> 2)) >> 1))) | (-(v295 ^ ((int)((unsigned int)((int)((unsigned int)(v291 + 16) >> 2)) >> 1))))) >> 31)) & 1);
    int v304 = v303[v439];
    int * v305 = v283->cache_age;
    int v306 = v305[v429];
    int * v307 = v283->cache_age;
    int v442 = v306 + ((int)((unsigned int)(v306 - v304) >> 31));
    v307[v429] = v442;
    int * v309 = v283->cache_age;
    int v310 = v309[v431];
    int * v311 = v283->cache_age;
    int v445 = v310 + ((int)((unsigned int)(v310 - v304) >> 31));
    v311[v431] = v445;
    int * v313 = v283->cache_age;
    v313[v439] = 0;
    v415 = v439;
  } else {
    int * v316 = v283->cache_age;
    int v449 = (((int)((unsigned int)((int)((unsigned int)(v291 + 16) >> 2)) >> 1)) & 1) * 2;
    int v317 = v316[v449];
    int * v318 = v283->cache_tags;
    int v319 = v318[v449];
    int * v320 = v283->cache_age;
    int v321 = v320[v431];
    int * v322 = v283->cache_tags;
    int v323 = v322[v431];
    bool v453 = !(((~(((v297 ^ ((int)((unsigned int)((int)((unsigned int)(v291 + 16) >> 2)) >> 1))) | (-(v297 ^ ((int)((unsigned int)((int)((unsigned int)(v291 + 16) >> 2)) >> 1))))) >> 31)) | (~(((v299 ^ ((int)((unsigned int)((int)((unsigned int)(v291 + 16) >> 2)) >> 1))) | (-(v299 ^ ((int)((unsigned int)((int)((unsigned int)(v291 + 16) >> 2)) >> 1))))) >> 31))) == 0);
    int v387;
    if (v453) {
      int * v324 = v283->cache_age;
      int v455 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v291 + 16) >> 2)) >> 1)) & 3) * 2)) + ((~(((v299 ^ ((int)((unsigned int)((int)((unsigned int)(v291 + 16) >> 2)) >> 1))) | (-(v299 ^ ((int)((unsigned int)((int)((unsigned int)(v291 + 16) >> 2)) >> 1))))) >> 31)) & 1);
      int v325 = v324[v455];
      int * v326 = v283->cache_age;
      int v327 = v326[v433];
      int * v328 = v283->cache_age;
      int v458 = v327 + ((int)((unsigned int)(v327 - v325) >> 31));
      v328[v433] = v458;
      int * v330 = v283->cache_age;
      int v331 = v330[v435];
      int * v332 = v283->cache_age;
      int v461 = v331 + ((int)((unsigned int)(v331 - v325) >> 31));
      v332[v435] = v461;
      int * v334 = v283->cache_age;
      v334[v455] = 0;
      v387 = v455;
    } else {
      int * v337 = v283->cache_age;
      int v465 = 4 + ((((int)((unsigned int)((int)((unsigned int)(v291 + 16) >> 2)) >> 1)) & 3) * 2);
      int v338 = v337[v465];
      int * v339 = v283->cache_tags;
      int v340 = v339[v465];
      int * v341 = v283->cache_age;
      int v342 = v341[v435];
      int * v343 = v283->cache_tags;
      int v344 = v343[v435];
      int * v345 = v283->cache_dirty;
      int v470 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v291 + 16) >> 2)) >> 1)) & 3) * 2)) + ((((v338 + ((~(((v340 ^ -1) | (-(v340 ^ -1))) >> 31)) & 2)) - (v342 + ((~(((v344 ^ -1) | (-(v344 ^ -1))) >> 31)) & 2))) >> 31) & 1);
      int v346 = v345[v470];
      bool v471 = !(v346 == 0);
      if (v471) {
        int * v347 = v283->cache_tags;
        int v348 = v347[v470];
        int * v349 = v283->cache_vals;
        int v474 = ((4 + ((((int)((unsigned int)((int)((unsigned int)(v291 + 16) >> 2)) >> 1)) & 3) * 2)) + ((((v338 + ((~(((v340 ^ -1) | (-(v340 ^ -1))) >> 31)) & 2)) - (v342 + ((~(((v344 ^ -1) | (-(v344 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
        int v350 = v349[v474];
        int * v351 = v283->cache_vals;
        int v476 = (((4 + ((((int)((unsigned int)((int)((unsigned int)(v291 + 16) >> 2)) >> 1)) & 3) * 2)) + ((((v338 + ((~(((v340 ^ -1) | (-(v340 ^ -1))) >> 31)) & 2)) - (v342 + ((~(((v344 ^ -1) | (-(v344 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
        int v352 = v351[v476];
        int * v353 = v283->mem;
        int v478 = v348 * 2;
        v353[v478] = v350;
        int * v355 = v283->mem;
        int v481 = (v348 * 2) + 1;
        v355[v481] = v352;
        ;
      } else {
        ;
      }
      int * v360 = v283->mem;
      int v486 = ((int)((unsigned int)((int)((unsigned int)(v291 + 16) >> 2)) >> 1)) * 2;
      int v361 = v360[v486];
      int * v362 = v283->mem;
      int v488 = (((int)((unsigned int)((int)((unsigned int)(v291 + 16) >> 2)) >> 1)) * 2) + 1;
      int v363 = v362[v488];
      int * v364 = v283->cache_vals;
      int v490 = ((4 + ((((int)((unsigned int)((int)((unsigned int)(v291 + 16) >> 2)) >> 1)) & 3) * 2)) + ((((v338 + ((~(((v340 ^ -1) | (-(v340 ^ -1))) >> 31)) & 2)) - (v342 + ((~(((v344 ^ -1) | (-(v344 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
      v364[v490] = v361;
      int * v366 = v283->cache_vals;
      int v493 = (((4 + ((((int)((unsigned int)((int)((unsigned int)(v291 + 16) >> 2)) >> 1)) & 3) * 2)) + ((((v338 + ((~(((v340 ^ -1) | (-(v340 ^ -1))) >> 31)) & 2)) - (v342 + ((~(((v344 ^ -1) | (-(v344 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
      v366[v493] = v363;
      int * v368 = v283->cache_tags;
      int v496 = (int)((unsigned int)((int)((unsigned int)(v291 + 16) >> 2)) >> 1);
      v368[v470] = v496;
      int * v370 = v283->cache_dirty;
      v370[v470] = 0;
      int * v372 = v283->cache_age;
      v372[v470] = 1;
      int * v374 = v283->cache_age;
      int v375 = v374[v470];
      int * v376 = v283->cache_age;
      int v377 = v376[v433];
      int * v378 = v283->cache_age;
      int v504 = v377 + ((int)((unsigned int)(v377 - v375) >> 31));
      v378[v433] = v504;
      int * v380 = v283->cache_age;
      int v381 = v380[v435];
      int * v382 = v283->cache_age;
      int v507 = v381 + ((int)((unsigned int)(v381 - v375) >> 31));
      v382[v435] = v507;
      int * v384 = v283->cache_age;
      v384[v470] = 0;
      v387 = v470;
    }
    int * v388 = v283->cache_vals;
    int v510 = v387 * 2;
    int v389 = v388[v510];
    int * v390 = v283->cache_vals;
    int v512 = (v387 * 2) + 1;
    int v391 = v390[v512];
    int * v392 = v283->cache_vals;
    int v514 = (((((int)((unsigned int)((int)((unsigned int)(v291 + 16) >> 2)) >> 1)) & 1) * 2) + ((((v317 + ((~(((v319 ^ -1) | (-(v319 ^ -1))) >> 31)) & 2)) - (v321 + ((~(((v323 ^ -1) | (-(v323 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
    v392[v514] = v389;
    int * v394 = v283->cache_vals;
    int v517 = ((((((int)((unsigned int)((int)((unsigned int)(v291 + 16) >> 2)) >> 1)) & 1) * 2) + ((((v317 + ((~(((v319 ^ -1) | (-(v319 ^ -1))) >> 31)) & 2)) - (v321 + ((~(((v323 ^ -1) | (-(v323 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
    v394[v517] = v391;
    int * v396 = v283->cache_tags;
    int v520 = ((((int)((unsigned int)((int)((unsigned int)(v291 + 16) >> 2)) >> 1)) & 1) * 2) + ((((v317 + ((~(((v319 ^ -1) | (-(v319 ^ -1))) >> 31)) & 2)) - (v321 + ((~(((v323 ^ -1) | (-(v323 ^ -1))) >> 31)) & 2))) >> 31) & 1);
    int v521 = (int)((unsigned int)((int)((unsigned int)(v291 + 16) >> 2)) >> 1);
    v396[v520] = v521;
    int * v398 = v283->cache_dirty;
    v398[v520] = 0;
    int * v400 = v283->cache_age;
    v400[v520] = 1;
    int * v402 = v283->cache_age;
    int v403 = v402[v520];
    int * v404 = v283->cache_age;
    int v405 = v404[v429];
    int * v406 = v283->cache_age;
    int v529 = v405 + ((int)((unsigned int)(v405 - v403) >> 31));
    v406[v429] = v529;
    int * v408 = v283->cache_age;
    int v409 = v408[v431];
    int * v410 = v283->cache_age;
    int v532 = v409 + ((int)((unsigned int)(v409 - v403) >> 31));
    v410[v431] = v532;
    int * v412 = v283->cache_age;
    v412[v520] = 0;
    v415 = v520;
  }
  int v535 = (v415 * 2) + (((int)((unsigned int)(v291 + 16) >> 2)) & 1);
  int v416 = v302[v535];
  int * v417 = v283->regs;
  v417[12] = v416;
  struct StateT * v419 = slot_4(v283);
  return v419;
}

struct StateT * slot_0(struct StateT * v2) {
  int v3 = v2->timer;
  int v7 = v3 + 1;
  v2->timer = v7;
  struct StateT * v5 = slot_1(v2);
  return v5;
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