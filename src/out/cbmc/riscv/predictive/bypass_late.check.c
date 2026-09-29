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

struct StateT * slot_5(struct StateT * v84);
struct StateT * slot_2(struct StateT * v32);
struct StateT * slot_7(struct StateT * v121);
struct StateT * slot_3(struct StateT * v40);
struct StateT * snippet(struct StateT * v0);
struct StateT * slot_10(struct StateT * v772);
struct StateT * slot_1(struct StateT * v19);
struct StateT * slot_8(struct StateT * v506);
struct StateT * slot_4(struct StateT * v64);
struct StateT * slot_9(struct StateT * v756);
struct StateT * slot_0(struct StateT * v2);
struct StateT * slot_5(struct StateT * v84) {
  int * v85 = v84->regs;
  int v86 = v85[5];
  int * v87 = v84->regs;
  int v88 = v87[9];
  bool v108 = v86 >= v88;
  struct StateT * v102;
  if (v108) {
    int v89 = v84->timer;
    int v109 = v89 + 15;
    v84->timer = v109;
    int * v91 = v84->saved_regs;
    int v92 = v91[6];
    int * v93 = v84->regs;
    v93[6] = v92;
    int * v95 = v84->saved_regs;
    int v96 = v95[7];
    int * v97 = v84->regs;
    v97[7] = v96;
    v102 = v84;
  } else {
    struct StateT * v100 = slot_7(v84);
    v102 = v100;
  }
  return v102;
}

struct StateT * slot_2(struct StateT * v32) {
  int v33 = v32->timer;
  int v37 = v33 + 1;
  v32->timer = v37;
  struct StateT * v35 = slot_3(v32);
  return v35;
}

struct StateT * slot_7(struct StateT * v121) {
  int v122 = v121->timer;
  int v327 = v122 + 1;
  v121->timer = v327;
  int * v124 = v121->regs;
  int v125 = v124[6];
  int * v126 = v121->regs;
  int v127 = v126[7];
  int * v128 = v121->cache_tags;
  int v333 = (((int)((unsigned int)((int)((unsigned int)v125 >> 2)) >> 1)) & 1) * 2;
  int v129 = v128[v333];
  int * v130 = v121->cache_tags;
  int v335 = ((((int)((unsigned int)((int)((unsigned int)v125 >> 2)) >> 1)) & 1) * 2) + 1;
  int v131 = v130[v335];
  int * v132 = v121->cache_tags;
  int v337 = 4 + ((((int)((unsigned int)((int)((unsigned int)v125 >> 2)) >> 1)) & 3) * 2);
  int v133 = v132[v337];
  int * v134 = v121->cache_tags;
  int v339 = (4 + ((((int)((unsigned int)((int)((unsigned int)v125 >> 2)) >> 1)) & 3) * 2)) + 1;
  int v135 = v134[v339];
  int v136 = v121->timer;
  int v340 = v136 + ((100 ^ (((~(((v133 ^ ((int)((unsigned int)((int)((unsigned int)v125 >> 2)) >> 1))) | (-(v133 ^ ((int)((unsigned int)((int)((unsigned int)v125 >> 2)) >> 1))))) >> 31)) | (~(((v135 ^ ((int)((unsigned int)((int)((unsigned int)v125 >> 2)) >> 1))) | (-(v135 ^ ((int)((unsigned int)((int)((unsigned int)v125 >> 2)) >> 1))))) >> 31))) & 104)) ^ (((~(((v129 ^ ((int)((unsigned int)((int)((unsigned int)v125 >> 2)) >> 1))) | (-(v129 ^ ((int)((unsigned int)((int)((unsigned int)v125 >> 2)) >> 1))))) >> 31)) | (~(((v131 ^ ((int)((unsigned int)((int)((unsigned int)v125 >> 2)) >> 1))) | (-(v131 ^ ((int)((unsigned int)((int)((unsigned int)v125 >> 2)) >> 1))))) >> 31))) & (1 ^ (100 ^ (((~(((v133 ^ ((int)((unsigned int)((int)((unsigned int)v125 >> 2)) >> 1))) | (-(v133 ^ ((int)((unsigned int)((int)((unsigned int)v125 >> 2)) >> 1))))) >> 31)) | (~(((v135 ^ ((int)((unsigned int)((int)((unsigned int)v125 >> 2)) >> 1))) | (-(v135 ^ ((int)((unsigned int)((int)((unsigned int)v125 >> 2)) >> 1))))) >> 31))) & 104)))));
  v121->timer = v340;
  bool v341 = !(((~(((v129 ^ ((int)((unsigned int)((int)((unsigned int)v125 >> 2)) >> 1))) | (-(v129 ^ ((int)((unsigned int)((int)((unsigned int)v125 >> 2)) >> 1))))) >> 31)) | (~(((v131 ^ ((int)((unsigned int)((int)((unsigned int)v125 >> 2)) >> 1))) | (-(v131 ^ ((int)((unsigned int)((int)((unsigned int)v125 >> 2)) >> 1))))) >> 31))) == 0);
  int v250;
  if (v341) {
    int * v138 = v121->cache_age;
    int v343 = ((((int)((unsigned int)((int)((unsigned int)v125 >> 2)) >> 1)) & 1) * 2) + ((~(((v131 ^ ((int)((unsigned int)((int)((unsigned int)v125 >> 2)) >> 1))) | (-(v131 ^ ((int)((unsigned int)((int)((unsigned int)v125 >> 2)) >> 1))))) >> 31)) & 1);
    int v139 = v138[v343];
    int * v140 = v121->cache_age;
    int v141 = v140[v333];
    int * v142 = v121->cache_age;
    int v346 = v141 + ((int)((unsigned int)(v141 - v139) >> 31));
    v142[v333] = v346;
    int * v144 = v121->cache_age;
    int v145 = v144[v335];
    int * v146 = v121->cache_age;
    int v349 = v145 + ((int)((unsigned int)(v145 - v139) >> 31));
    v146[v335] = v349;
    int * v148 = v121->cache_age;
    v148[v343] = 0;
    v250 = v343;
  } else {
    int * v151 = v121->cache_age;
    int v353 = (((int)((unsigned int)((int)((unsigned int)v125 >> 2)) >> 1)) & 1) * 2;
    int v152 = v151[v353];
    int * v153 = v121->cache_tags;
    int v154 = v153[v353];
    int * v155 = v121->cache_age;
    int v156 = v155[v335];
    int * v157 = v121->cache_tags;
    int v158 = v157[v335];
    bool v357 = !(((~(((v133 ^ ((int)((unsigned int)((int)((unsigned int)v125 >> 2)) >> 1))) | (-(v133 ^ ((int)((unsigned int)((int)((unsigned int)v125 >> 2)) >> 1))))) >> 31)) | (~(((v135 ^ ((int)((unsigned int)((int)((unsigned int)v125 >> 2)) >> 1))) | (-(v135 ^ ((int)((unsigned int)((int)((unsigned int)v125 >> 2)) >> 1))))) >> 31))) == 0);
    int v222;
    if (v357) {
      int * v159 = v121->cache_age;
      int v359 = (4 + ((((int)((unsigned int)((int)((unsigned int)v125 >> 2)) >> 1)) & 3) * 2)) + ((~(((v135 ^ ((int)((unsigned int)((int)((unsigned int)v125 >> 2)) >> 1))) | (-(v135 ^ ((int)((unsigned int)((int)((unsigned int)v125 >> 2)) >> 1))))) >> 31)) & 1);
      int v160 = v159[v359];
      int * v161 = v121->cache_age;
      int v162 = v161[v337];
      int * v163 = v121->cache_age;
      int v362 = v162 + ((int)((unsigned int)(v162 - v160) >> 31));
      v163[v337] = v362;
      int * v165 = v121->cache_age;
      int v166 = v165[v339];
      int * v167 = v121->cache_age;
      int v365 = v166 + ((int)((unsigned int)(v166 - v160) >> 31));
      v167[v339] = v365;
      int * v169 = v121->cache_age;
      v169[v359] = 0;
      v222 = v359;
    } else {
      int * v172 = v121->cache_age;
      int v369 = 4 + ((((int)((unsigned int)((int)((unsigned int)v125 >> 2)) >> 1)) & 3) * 2);
      int v173 = v172[v369];
      int * v174 = v121->cache_tags;
      int v175 = v174[v369];
      int * v176 = v121->cache_age;
      int v177 = v176[v339];
      int * v178 = v121->cache_tags;
      int v179 = v178[v339];
      int * v180 = v121->cache_dirty;
      int v374 = (4 + ((((int)((unsigned int)((int)((unsigned int)v125 >> 2)) >> 1)) & 3) * 2)) + ((((v173 + ((~(((v175 ^ -1) | (-(v175 ^ -1))) >> 31)) & 2)) - (v177 + ((~(((v179 ^ -1) | (-(v179 ^ -1))) >> 31)) & 2))) >> 31) & 1);
      int v181 = v180[v374];
      bool v375 = !(v181 == 0);
      if (v375) {
        int * v182 = v121->cache_tags;
        int v183 = v182[v374];
        int * v184 = v121->cache_vals;
        int v378 = ((4 + ((((int)((unsigned int)((int)((unsigned int)v125 >> 2)) >> 1)) & 3) * 2)) + ((((v173 + ((~(((v175 ^ -1) | (-(v175 ^ -1))) >> 31)) & 2)) - (v177 + ((~(((v179 ^ -1) | (-(v179 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
        int v185 = v184[v378];
        int * v186 = v121->cache_vals;
        int v380 = (((4 + ((((int)((unsigned int)((int)((unsigned int)v125 >> 2)) >> 1)) & 3) * 2)) + ((((v173 + ((~(((v175 ^ -1) | (-(v175 ^ -1))) >> 31)) & 2)) - (v177 + ((~(((v179 ^ -1) | (-(v179 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
        int v187 = v186[v380];
        int * v188 = v121->mem;
        int v382 = v183 * 2;
        v188[v382] = v185;
        int * v190 = v121->mem;
        int v385 = (v183 * 2) + 1;
        v190[v385] = v187;
        ;
      } else {
        ;
      }
      int * v195 = v121->mem;
      int v390 = ((int)((unsigned int)((int)((unsigned int)v125 >> 2)) >> 1)) * 2;
      int v196 = v195[v390];
      int * v197 = v121->mem;
      int v392 = (((int)((unsigned int)((int)((unsigned int)v125 >> 2)) >> 1)) * 2) + 1;
      int v198 = v197[v392];
      int * v199 = v121->cache_vals;
      int v394 = ((4 + ((((int)((unsigned int)((int)((unsigned int)v125 >> 2)) >> 1)) & 3) * 2)) + ((((v173 + ((~(((v175 ^ -1) | (-(v175 ^ -1))) >> 31)) & 2)) - (v177 + ((~(((v179 ^ -1) | (-(v179 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
      v199[v394] = v196;
      int * v201 = v121->cache_vals;
      int v397 = (((4 + ((((int)((unsigned int)((int)((unsigned int)v125 >> 2)) >> 1)) & 3) * 2)) + ((((v173 + ((~(((v175 ^ -1) | (-(v175 ^ -1))) >> 31)) & 2)) - (v177 + ((~(((v179 ^ -1) | (-(v179 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
      v201[v397] = v198;
      int * v203 = v121->cache_tags;
      int v400 = (int)((unsigned int)((int)((unsigned int)v125 >> 2)) >> 1);
      v203[v374] = v400;
      int * v205 = v121->cache_dirty;
      v205[v374] = 0;
      int * v207 = v121->cache_age;
      v207[v374] = 1;
      int * v209 = v121->cache_age;
      int v210 = v209[v374];
      int * v211 = v121->cache_age;
      int v212 = v211[v337];
      int * v213 = v121->cache_age;
      int v408 = v212 + ((int)((unsigned int)(v212 - v210) >> 31));
      v213[v337] = v408;
      int * v215 = v121->cache_age;
      int v216 = v215[v339];
      int * v217 = v121->cache_age;
      int v411 = v216 + ((int)((unsigned int)(v216 - v210) >> 31));
      v217[v339] = v411;
      int * v219 = v121->cache_age;
      v219[v374] = 0;
      v222 = v374;
    }
    int * v223 = v121->cache_vals;
    int v414 = v222 * 2;
    int v224 = v223[v414];
    int * v225 = v121->cache_vals;
    int v416 = (v222 * 2) + 1;
    int v226 = v225[v416];
    int * v227 = v121->cache_vals;
    int v418 = (((((int)((unsigned int)((int)((unsigned int)v125 >> 2)) >> 1)) & 1) * 2) + ((((v152 + ((~(((v154 ^ -1) | (-(v154 ^ -1))) >> 31)) & 2)) - (v156 + ((~(((v158 ^ -1) | (-(v158 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
    v227[v418] = v224;
    int * v229 = v121->cache_vals;
    int v421 = ((((((int)((unsigned int)((int)((unsigned int)v125 >> 2)) >> 1)) & 1) * 2) + ((((v152 + ((~(((v154 ^ -1) | (-(v154 ^ -1))) >> 31)) & 2)) - (v156 + ((~(((v158 ^ -1) | (-(v158 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
    v229[v421] = v226;
    int * v231 = v121->cache_tags;
    int v424 = ((((int)((unsigned int)((int)((unsigned int)v125 >> 2)) >> 1)) & 1) * 2) + ((((v152 + ((~(((v154 ^ -1) | (-(v154 ^ -1))) >> 31)) & 2)) - (v156 + ((~(((v158 ^ -1) | (-(v158 ^ -1))) >> 31)) & 2))) >> 31) & 1);
    int v425 = (int)((unsigned int)((int)((unsigned int)v125 >> 2)) >> 1);
    v231[v424] = v425;
    int * v233 = v121->cache_dirty;
    v233[v424] = 0;
    int * v235 = v121->cache_age;
    v235[v424] = 1;
    int * v237 = v121->cache_age;
    int v238 = v237[v424];
    int * v239 = v121->cache_age;
    int v240 = v239[v333];
    int * v241 = v121->cache_age;
    int v433 = v240 + ((int)((unsigned int)(v240 - v238) >> 31));
    v241[v333] = v433;
    int * v243 = v121->cache_age;
    int v244 = v243[v335];
    int * v245 = v121->cache_age;
    int v436 = v244 + ((int)((unsigned int)(v244 - v238) >> 31));
    v245[v335] = v436;
    int * v247 = v121->cache_age;
    v247[v424] = 0;
    v250 = v424;
  }
  int * v251 = v121->cache_vals;
  int v439 = (v250 * 2) + (((int)((unsigned int)v125 >> 2)) & 1);
  v251[v439] = v127;
  int * v253 = v121->cache_tags;
  int v254 = v253[v337];
  int * v255 = v121->cache_tags;
  int v256 = v255[v339];
  bool v443 = !(((~(((v254 ^ ((int)((unsigned int)((int)((unsigned int)v125 >> 2)) >> 1))) | (-(v254 ^ ((int)((unsigned int)((int)((unsigned int)v125 >> 2)) >> 1))))) >> 31)) | (~(((v256 ^ ((int)((unsigned int)((int)((unsigned int)v125 >> 2)) >> 1))) | (-(v256 ^ ((int)((unsigned int)((int)((unsigned int)v125 >> 2)) >> 1))))) >> 31))) == 0);
  int v320;
  if (v443) {
    int * v257 = v121->cache_age;
    int v445 = (4 + ((((int)((unsigned int)((int)((unsigned int)v125 >> 2)) >> 1)) & 3) * 2)) + ((~(((v256 ^ ((int)((unsigned int)((int)((unsigned int)v125 >> 2)) >> 1))) | (-(v256 ^ ((int)((unsigned int)((int)((unsigned int)v125 >> 2)) >> 1))))) >> 31)) & 1);
    int v258 = v257[v445];
    int * v259 = v121->cache_age;
    int v260 = v259[v337];
    int * v261 = v121->cache_age;
    int v448 = v260 + ((int)((unsigned int)(v260 - v258) >> 31));
    v261[v337] = v448;
    int * v263 = v121->cache_age;
    int v264 = v263[v339];
    int * v265 = v121->cache_age;
    int v451 = v264 + ((int)((unsigned int)(v264 - v258) >> 31));
    v265[v339] = v451;
    int * v267 = v121->cache_age;
    v267[v445] = 0;
    v320 = v445;
  } else {
    int * v270 = v121->cache_age;
    int v455 = 4 + ((((int)((unsigned int)((int)((unsigned int)v125 >> 2)) >> 1)) & 3) * 2);
    int v271 = v270[v455];
    int * v272 = v121->cache_tags;
    int v273 = v272[v455];
    int * v274 = v121->cache_age;
    int v275 = v274[v339];
    int * v276 = v121->cache_tags;
    int v277 = v276[v339];
    int * v278 = v121->cache_dirty;
    int v460 = (4 + ((((int)((unsigned int)((int)((unsigned int)v125 >> 2)) >> 1)) & 3) * 2)) + ((((v271 + ((~(((v273 ^ -1) | (-(v273 ^ -1))) >> 31)) & 2)) - (v275 + ((~(((v277 ^ -1) | (-(v277 ^ -1))) >> 31)) & 2))) >> 31) & 1);
    int v279 = v278[v460];
    bool v461 = !(v279 == 0);
    if (v461) {
      int * v280 = v121->cache_tags;
      int v281 = v280[v460];
      int * v282 = v121->cache_vals;
      int v464 = ((4 + ((((int)((unsigned int)((int)((unsigned int)v125 >> 2)) >> 1)) & 3) * 2)) + ((((v271 + ((~(((v273 ^ -1) | (-(v273 ^ -1))) >> 31)) & 2)) - (v275 + ((~(((v277 ^ -1) | (-(v277 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
      int v283 = v282[v464];
      int * v284 = v121->cache_vals;
      int v466 = (((4 + ((((int)((unsigned int)((int)((unsigned int)v125 >> 2)) >> 1)) & 3) * 2)) + ((((v271 + ((~(((v273 ^ -1) | (-(v273 ^ -1))) >> 31)) & 2)) - (v275 + ((~(((v277 ^ -1) | (-(v277 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
      int v285 = v284[v466];
      int * v286 = v121->mem;
      int v468 = v281 * 2;
      v286[v468] = v283;
      int * v288 = v121->mem;
      int v471 = (v281 * 2) + 1;
      v288[v471] = v285;
      ;
    } else {
      ;
    }
    int * v293 = v121->mem;
    int v476 = ((int)((unsigned int)((int)((unsigned int)v125 >> 2)) >> 1)) * 2;
    int v294 = v293[v476];
    int * v295 = v121->mem;
    int v478 = (((int)((unsigned int)((int)((unsigned int)v125 >> 2)) >> 1)) * 2) + 1;
    int v296 = v295[v478];
    int * v297 = v121->cache_vals;
    int v480 = ((4 + ((((int)((unsigned int)((int)((unsigned int)v125 >> 2)) >> 1)) & 3) * 2)) + ((((v271 + ((~(((v273 ^ -1) | (-(v273 ^ -1))) >> 31)) & 2)) - (v275 + ((~(((v277 ^ -1) | (-(v277 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
    v297[v480] = v294;
    int * v299 = v121->cache_vals;
    int v483 = (((4 + ((((int)((unsigned int)((int)((unsigned int)v125 >> 2)) >> 1)) & 3) * 2)) + ((((v271 + ((~(((v273 ^ -1) | (-(v273 ^ -1))) >> 31)) & 2)) - (v275 + ((~(((v277 ^ -1) | (-(v277 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
    v299[v483] = v296;
    int * v301 = v121->cache_tags;
    int v486 = (int)((unsigned int)((int)((unsigned int)v125 >> 2)) >> 1);
    v301[v460] = v486;
    int * v303 = v121->cache_dirty;
    v303[v460] = 0;
    int * v305 = v121->cache_age;
    v305[v460] = 1;
    int * v307 = v121->cache_age;
    int v308 = v307[v460];
    int * v309 = v121->cache_age;
    int v310 = v309[v337];
    int * v311 = v121->cache_age;
    int v494 = v310 + ((int)((unsigned int)(v310 - v308) >> 31));
    v311[v337] = v494;
    int * v313 = v121->cache_age;
    int v314 = v313[v339];
    int * v315 = v121->cache_age;
    int v497 = v314 + ((int)((unsigned int)(v314 - v308) >> 31));
    v315[v339] = v497;
    int * v317 = v121->cache_age;
    v317[v460] = 0;
    v320 = v460;
  }
  int * v321 = v121->cache_vals;
  int v500 = (v320 * 2) + (((int)((unsigned int)v125 >> 2)) & 1);
  v321[v500] = v127;
  int * v323 = v121->cache_dirty;
  v323[v320] = 1;
  struct StateT * v325 = slot_8(v121);
  return v325;
}

struct StateT * slot_3(struct StateT * v40) {
  int * v41 = v40->saved_regs;
  int * v42 = v40->regs;
  int v43 = v42[6];
  v41[6] = v43;
  int v45 = v40->timer;
  int v57 = v45 + 1;
  v40->timer = v57;
  int * v47 = v40->regs;
  int v48 = v47[5];
  int * v49 = v40->regs;
  int v61 = v48 + 80;
  v49[6] = v61;
  struct StateT * v51 = slot_4(v40);
  return v51;
}

struct StateT * snippet(struct StateT * v0) {
  struct StateT * v1 = slot_0(v0);
  return v1;
}

struct StateT * slot_10(struct StateT * v772) {
  int v773 = v772->timer;
  int v905 = v773 + 1;
  v772->timer = v905;
  int * v775 = v772->regs;
  int v776 = v775[11];
  int * v777 = v772->cache_tags;
  int v909 = (((int)((unsigned int)((int)((unsigned int)v776 >> 2)) >> 1)) & 1) * 2;
  int v778 = v777[v909];
  int * v779 = v772->cache_tags;
  int v911 = ((((int)((unsigned int)((int)((unsigned int)v776 >> 2)) >> 1)) & 1) * 2) + 1;
  int v780 = v779[v911];
  int * v781 = v772->cache_tags;
  int v913 = 4 + ((((int)((unsigned int)((int)((unsigned int)v776 >> 2)) >> 1)) & 3) * 2);
  int v782 = v781[v913];
  int * v783 = v772->cache_tags;
  int v915 = (4 + ((((int)((unsigned int)((int)((unsigned int)v776 >> 2)) >> 1)) & 3) * 2)) + 1;
  int v784 = v783[v915];
  int v785 = v772->timer;
  int v916 = v785 + ((100 ^ (((~(((v782 ^ ((int)((unsigned int)((int)((unsigned int)v776 >> 2)) >> 1))) | (-(v782 ^ ((int)((unsigned int)((int)((unsigned int)v776 >> 2)) >> 1))))) >> 31)) | (~(((v784 ^ ((int)((unsigned int)((int)((unsigned int)v776 >> 2)) >> 1))) | (-(v784 ^ ((int)((unsigned int)((int)((unsigned int)v776 >> 2)) >> 1))))) >> 31))) & 104)) ^ (((~(((v778 ^ ((int)((unsigned int)((int)((unsigned int)v776 >> 2)) >> 1))) | (-(v778 ^ ((int)((unsigned int)((int)((unsigned int)v776 >> 2)) >> 1))))) >> 31)) | (~(((v780 ^ ((int)((unsigned int)((int)((unsigned int)v776 >> 2)) >> 1))) | (-(v780 ^ ((int)((unsigned int)((int)((unsigned int)v776 >> 2)) >> 1))))) >> 31))) & (1 ^ (100 ^ (((~(((v782 ^ ((int)((unsigned int)((int)((unsigned int)v776 >> 2)) >> 1))) | (-(v782 ^ ((int)((unsigned int)((int)((unsigned int)v776 >> 2)) >> 1))))) >> 31)) | (~(((v784 ^ ((int)((unsigned int)((int)((unsigned int)v776 >> 2)) >> 1))) | (-(v784 ^ ((int)((unsigned int)((int)((unsigned int)v776 >> 2)) >> 1))))) >> 31))) & 104)))));
  v772->timer = v916;
  int * v787 = v772->cache_vals;
  bool v917 = !(((~(((v778 ^ ((int)((unsigned int)((int)((unsigned int)v776 >> 2)) >> 1))) | (-(v778 ^ ((int)((unsigned int)((int)((unsigned int)v776 >> 2)) >> 1))))) >> 31)) | (~(((v780 ^ ((int)((unsigned int)((int)((unsigned int)v776 >> 2)) >> 1))) | (-(v780 ^ ((int)((unsigned int)((int)((unsigned int)v776 >> 2)) >> 1))))) >> 31))) == 0);
  int v900;
  if (v917) {
    int * v788 = v772->cache_age;
    int v919 = ((((int)((unsigned int)((int)((unsigned int)v776 >> 2)) >> 1)) & 1) * 2) + ((~(((v780 ^ ((int)((unsigned int)((int)((unsigned int)v776 >> 2)) >> 1))) | (-(v780 ^ ((int)((unsigned int)((int)((unsigned int)v776 >> 2)) >> 1))))) >> 31)) & 1);
    int v789 = v788[v919];
    int * v790 = v772->cache_age;
    int v791 = v790[v909];
    int * v792 = v772->cache_age;
    int v922 = v791 + ((int)((unsigned int)(v791 - v789) >> 31));
    v792[v909] = v922;
    int * v794 = v772->cache_age;
    int v795 = v794[v911];
    int * v796 = v772->cache_age;
    int v925 = v795 + ((int)((unsigned int)(v795 - v789) >> 31));
    v796[v911] = v925;
    int * v798 = v772->cache_age;
    v798[v919] = 0;
    v900 = v919;
  } else {
    int * v801 = v772->cache_age;
    int v929 = (((int)((unsigned int)((int)((unsigned int)v776 >> 2)) >> 1)) & 1) * 2;
    int v802 = v801[v929];
    int * v803 = v772->cache_tags;
    int v804 = v803[v929];
    int * v805 = v772->cache_age;
    int v806 = v805[v911];
    int * v807 = v772->cache_tags;
    int v808 = v807[v911];
    bool v933 = !(((~(((v782 ^ ((int)((unsigned int)((int)((unsigned int)v776 >> 2)) >> 1))) | (-(v782 ^ ((int)((unsigned int)((int)((unsigned int)v776 >> 2)) >> 1))))) >> 31)) | (~(((v784 ^ ((int)((unsigned int)((int)((unsigned int)v776 >> 2)) >> 1))) | (-(v784 ^ ((int)((unsigned int)((int)((unsigned int)v776 >> 2)) >> 1))))) >> 31))) == 0);
    int v872;
    if (v933) {
      int * v809 = v772->cache_age;
      int v935 = (4 + ((((int)((unsigned int)((int)((unsigned int)v776 >> 2)) >> 1)) & 3) * 2)) + ((~(((v784 ^ ((int)((unsigned int)((int)((unsigned int)v776 >> 2)) >> 1))) | (-(v784 ^ ((int)((unsigned int)((int)((unsigned int)v776 >> 2)) >> 1))))) >> 31)) & 1);
      int v810 = v809[v935];
      int * v811 = v772->cache_age;
      int v812 = v811[v913];
      int * v813 = v772->cache_age;
      int v938 = v812 + ((int)((unsigned int)(v812 - v810) >> 31));
      v813[v913] = v938;
      int * v815 = v772->cache_age;
      int v816 = v815[v915];
      int * v817 = v772->cache_age;
      int v941 = v816 + ((int)((unsigned int)(v816 - v810) >> 31));
      v817[v915] = v941;
      int * v819 = v772->cache_age;
      v819[v935] = 0;
      v872 = v935;
    } else {
      int * v822 = v772->cache_age;
      int v945 = 4 + ((((int)((unsigned int)((int)((unsigned int)v776 >> 2)) >> 1)) & 3) * 2);
      int v823 = v822[v945];
      int * v824 = v772->cache_tags;
      int v825 = v824[v945];
      int * v826 = v772->cache_age;
      int v827 = v826[v915];
      int * v828 = v772->cache_tags;
      int v829 = v828[v915];
      int * v830 = v772->cache_dirty;
      int v950 = (4 + ((((int)((unsigned int)((int)((unsigned int)v776 >> 2)) >> 1)) & 3) * 2)) + ((((v823 + ((~(((v825 ^ -1) | (-(v825 ^ -1))) >> 31)) & 2)) - (v827 + ((~(((v829 ^ -1) | (-(v829 ^ -1))) >> 31)) & 2))) >> 31) & 1);
      int v831 = v830[v950];
      bool v951 = !(v831 == 0);
      if (v951) {
        int * v832 = v772->cache_tags;
        int v833 = v832[v950];
        int * v834 = v772->cache_vals;
        int v954 = ((4 + ((((int)((unsigned int)((int)((unsigned int)v776 >> 2)) >> 1)) & 3) * 2)) + ((((v823 + ((~(((v825 ^ -1) | (-(v825 ^ -1))) >> 31)) & 2)) - (v827 + ((~(((v829 ^ -1) | (-(v829 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
        int v835 = v834[v954];
        int * v836 = v772->cache_vals;
        int v956 = (((4 + ((((int)((unsigned int)((int)((unsigned int)v776 >> 2)) >> 1)) & 3) * 2)) + ((((v823 + ((~(((v825 ^ -1) | (-(v825 ^ -1))) >> 31)) & 2)) - (v827 + ((~(((v829 ^ -1) | (-(v829 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
        int v837 = v836[v956];
        int * v838 = v772->mem;
        int v958 = v833 * 2;
        v838[v958] = v835;
        int * v840 = v772->mem;
        int v961 = (v833 * 2) + 1;
        v840[v961] = v837;
        ;
      } else {
        ;
      }
      int * v845 = v772->mem;
      int v966 = ((int)((unsigned int)((int)((unsigned int)v776 >> 2)) >> 1)) * 2;
      int v846 = v845[v966];
      int * v847 = v772->mem;
      int v968 = (((int)((unsigned int)((int)((unsigned int)v776 >> 2)) >> 1)) * 2) + 1;
      int v848 = v847[v968];
      int * v849 = v772->cache_vals;
      int v970 = ((4 + ((((int)((unsigned int)((int)((unsigned int)v776 >> 2)) >> 1)) & 3) * 2)) + ((((v823 + ((~(((v825 ^ -1) | (-(v825 ^ -1))) >> 31)) & 2)) - (v827 + ((~(((v829 ^ -1) | (-(v829 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
      v849[v970] = v846;
      int * v851 = v772->cache_vals;
      int v973 = (((4 + ((((int)((unsigned int)((int)((unsigned int)v776 >> 2)) >> 1)) & 3) * 2)) + ((((v823 + ((~(((v825 ^ -1) | (-(v825 ^ -1))) >> 31)) & 2)) - (v827 + ((~(((v829 ^ -1) | (-(v829 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
      v851[v973] = v848;
      int * v853 = v772->cache_tags;
      int v976 = (int)((unsigned int)((int)((unsigned int)v776 >> 2)) >> 1);
      v853[v950] = v976;
      int * v855 = v772->cache_dirty;
      v855[v950] = 0;
      int * v857 = v772->cache_age;
      v857[v950] = 1;
      int * v859 = v772->cache_age;
      int v860 = v859[v950];
      int * v861 = v772->cache_age;
      int v862 = v861[v913];
      int * v863 = v772->cache_age;
      int v984 = v862 + ((int)((unsigned int)(v862 - v860) >> 31));
      v863[v913] = v984;
      int * v865 = v772->cache_age;
      int v866 = v865[v915];
      int * v867 = v772->cache_age;
      int v987 = v866 + ((int)((unsigned int)(v866 - v860) >> 31));
      v867[v915] = v987;
      int * v869 = v772->cache_age;
      v869[v950] = 0;
      v872 = v950;
    }
    int * v873 = v772->cache_vals;
    int v990 = v872 * 2;
    int v874 = v873[v990];
    int * v875 = v772->cache_vals;
    int v992 = (v872 * 2) + 1;
    int v876 = v875[v992];
    int * v877 = v772->cache_vals;
    int v994 = (((((int)((unsigned int)((int)((unsigned int)v776 >> 2)) >> 1)) & 1) * 2) + ((((v802 + ((~(((v804 ^ -1) | (-(v804 ^ -1))) >> 31)) & 2)) - (v806 + ((~(((v808 ^ -1) | (-(v808 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
    v877[v994] = v874;
    int * v879 = v772->cache_vals;
    int v997 = ((((((int)((unsigned int)((int)((unsigned int)v776 >> 2)) >> 1)) & 1) * 2) + ((((v802 + ((~(((v804 ^ -1) | (-(v804 ^ -1))) >> 31)) & 2)) - (v806 + ((~(((v808 ^ -1) | (-(v808 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
    v879[v997] = v876;
    int * v881 = v772->cache_tags;
    int v1000 = ((((int)((unsigned int)((int)((unsigned int)v776 >> 2)) >> 1)) & 1) * 2) + ((((v802 + ((~(((v804 ^ -1) | (-(v804 ^ -1))) >> 31)) & 2)) - (v806 + ((~(((v808 ^ -1) | (-(v808 ^ -1))) >> 31)) & 2))) >> 31) & 1);
    int v1001 = (int)((unsigned int)((int)((unsigned int)v776 >> 2)) >> 1);
    v881[v1000] = v1001;
    int * v883 = v772->cache_dirty;
    v883[v1000] = 0;
    int * v885 = v772->cache_age;
    v885[v1000] = 1;
    int * v887 = v772->cache_age;
    int v888 = v887[v1000];
    int * v889 = v772->cache_age;
    int v890 = v889[v909];
    int * v891 = v772->cache_age;
    int v1009 = v890 + ((int)((unsigned int)(v890 - v888) >> 31));
    v891[v909] = v1009;
    int * v893 = v772->cache_age;
    int v894 = v893[v911];
    int * v895 = v772->cache_age;
    int v1012 = v894 + ((int)((unsigned int)(v894 - v888) >> 31));
    v895[v911] = v1012;
    int * v897 = v772->cache_age;
    v897[v1000] = 0;
    v900 = v1000;
  }
  int v1015 = (v900 * 2) + (((int)((unsigned int)v776 >> 2)) & 1);
  int v901 = v787[v1015];
  int * v902 = v772->regs;
  v902[12] = v901;
  return v772;
}

struct StateT * slot_1(struct StateT * v19) {
  int v20 = v19->timer;
  int v26 = v20 + 1;
  v19->timer = v26;
  int * v22 = v19->regs;
  v22[9] = 32;
  struct StateT * v24 = slot_2(v19);
  return v24;
}

struct StateT * slot_8(struct StateT * v506) {
  int v507 = v506->timer;
  int v640 = v507 + 1;
  v506->timer = v640;
  int * v509 = v506->regs;
  int v510 = v509[6];
  int * v511 = v506->cache_tags;
  int v644 = (((int)((unsigned int)((int)((unsigned int)v510 >> 2)) >> 1)) & 1) * 2;
  int v512 = v511[v644];
  int * v513 = v506->cache_tags;
  int v646 = ((((int)((unsigned int)((int)((unsigned int)v510 >> 2)) >> 1)) & 1) * 2) + 1;
  int v514 = v513[v646];
  int * v515 = v506->cache_tags;
  int v648 = 4 + ((((int)((unsigned int)((int)((unsigned int)v510 >> 2)) >> 1)) & 3) * 2);
  int v516 = v515[v648];
  int * v517 = v506->cache_tags;
  int v650 = (4 + ((((int)((unsigned int)((int)((unsigned int)v510 >> 2)) >> 1)) & 3) * 2)) + 1;
  int v518 = v517[v650];
  int v519 = v506->timer;
  int v651 = v519 + ((100 ^ (((~(((v516 ^ ((int)((unsigned int)((int)((unsigned int)v510 >> 2)) >> 1))) | (-(v516 ^ ((int)((unsigned int)((int)((unsigned int)v510 >> 2)) >> 1))))) >> 31)) | (~(((v518 ^ ((int)((unsigned int)((int)((unsigned int)v510 >> 2)) >> 1))) | (-(v518 ^ ((int)((unsigned int)((int)((unsigned int)v510 >> 2)) >> 1))))) >> 31))) & 104)) ^ (((~(((v512 ^ ((int)((unsigned int)((int)((unsigned int)v510 >> 2)) >> 1))) | (-(v512 ^ ((int)((unsigned int)((int)((unsigned int)v510 >> 2)) >> 1))))) >> 31)) | (~(((v514 ^ ((int)((unsigned int)((int)((unsigned int)v510 >> 2)) >> 1))) | (-(v514 ^ ((int)((unsigned int)((int)((unsigned int)v510 >> 2)) >> 1))))) >> 31))) & (1 ^ (100 ^ (((~(((v516 ^ ((int)((unsigned int)((int)((unsigned int)v510 >> 2)) >> 1))) | (-(v516 ^ ((int)((unsigned int)((int)((unsigned int)v510 >> 2)) >> 1))))) >> 31)) | (~(((v518 ^ ((int)((unsigned int)((int)((unsigned int)v510 >> 2)) >> 1))) | (-(v518 ^ ((int)((unsigned int)((int)((unsigned int)v510 >> 2)) >> 1))))) >> 31))) & 104)))));
  v506->timer = v651;
  int * v521 = v506->cache_vals;
  bool v652 = !(((~(((v512 ^ ((int)((unsigned int)((int)((unsigned int)v510 >> 2)) >> 1))) | (-(v512 ^ ((int)((unsigned int)((int)((unsigned int)v510 >> 2)) >> 1))))) >> 31)) | (~(((v514 ^ ((int)((unsigned int)((int)((unsigned int)v510 >> 2)) >> 1))) | (-(v514 ^ ((int)((unsigned int)((int)((unsigned int)v510 >> 2)) >> 1))))) >> 31))) == 0);
  int v634;
  if (v652) {
    int * v522 = v506->cache_age;
    int v654 = ((((int)((unsigned int)((int)((unsigned int)v510 >> 2)) >> 1)) & 1) * 2) + ((~(((v514 ^ ((int)((unsigned int)((int)((unsigned int)v510 >> 2)) >> 1))) | (-(v514 ^ ((int)((unsigned int)((int)((unsigned int)v510 >> 2)) >> 1))))) >> 31)) & 1);
    int v523 = v522[v654];
    int * v524 = v506->cache_age;
    int v525 = v524[v644];
    int * v526 = v506->cache_age;
    int v657 = v525 + ((int)((unsigned int)(v525 - v523) >> 31));
    v526[v644] = v657;
    int * v528 = v506->cache_age;
    int v529 = v528[v646];
    int * v530 = v506->cache_age;
    int v660 = v529 + ((int)((unsigned int)(v529 - v523) >> 31));
    v530[v646] = v660;
    int * v532 = v506->cache_age;
    v532[v654] = 0;
    v634 = v654;
  } else {
    int * v535 = v506->cache_age;
    int v664 = (((int)((unsigned int)((int)((unsigned int)v510 >> 2)) >> 1)) & 1) * 2;
    int v536 = v535[v664];
    int * v537 = v506->cache_tags;
    int v538 = v537[v664];
    int * v539 = v506->cache_age;
    int v540 = v539[v646];
    int * v541 = v506->cache_tags;
    int v542 = v541[v646];
    bool v668 = !(((~(((v516 ^ ((int)((unsigned int)((int)((unsigned int)v510 >> 2)) >> 1))) | (-(v516 ^ ((int)((unsigned int)((int)((unsigned int)v510 >> 2)) >> 1))))) >> 31)) | (~(((v518 ^ ((int)((unsigned int)((int)((unsigned int)v510 >> 2)) >> 1))) | (-(v518 ^ ((int)((unsigned int)((int)((unsigned int)v510 >> 2)) >> 1))))) >> 31))) == 0);
    int v606;
    if (v668) {
      int * v543 = v506->cache_age;
      int v670 = (4 + ((((int)((unsigned int)((int)((unsigned int)v510 >> 2)) >> 1)) & 3) * 2)) + ((~(((v518 ^ ((int)((unsigned int)((int)((unsigned int)v510 >> 2)) >> 1))) | (-(v518 ^ ((int)((unsigned int)((int)((unsigned int)v510 >> 2)) >> 1))))) >> 31)) & 1);
      int v544 = v543[v670];
      int * v545 = v506->cache_age;
      int v546 = v545[v648];
      int * v547 = v506->cache_age;
      int v673 = v546 + ((int)((unsigned int)(v546 - v544) >> 31));
      v547[v648] = v673;
      int * v549 = v506->cache_age;
      int v550 = v549[v650];
      int * v551 = v506->cache_age;
      int v676 = v550 + ((int)((unsigned int)(v550 - v544) >> 31));
      v551[v650] = v676;
      int * v553 = v506->cache_age;
      v553[v670] = 0;
      v606 = v670;
    } else {
      int * v556 = v506->cache_age;
      int v680 = 4 + ((((int)((unsigned int)((int)((unsigned int)v510 >> 2)) >> 1)) & 3) * 2);
      int v557 = v556[v680];
      int * v558 = v506->cache_tags;
      int v559 = v558[v680];
      int * v560 = v506->cache_age;
      int v561 = v560[v650];
      int * v562 = v506->cache_tags;
      int v563 = v562[v650];
      int * v564 = v506->cache_dirty;
      int v685 = (4 + ((((int)((unsigned int)((int)((unsigned int)v510 >> 2)) >> 1)) & 3) * 2)) + ((((v557 + ((~(((v559 ^ -1) | (-(v559 ^ -1))) >> 31)) & 2)) - (v561 + ((~(((v563 ^ -1) | (-(v563 ^ -1))) >> 31)) & 2))) >> 31) & 1);
      int v565 = v564[v685];
      bool v686 = !(v565 == 0);
      if (v686) {
        int * v566 = v506->cache_tags;
        int v567 = v566[v685];
        int * v568 = v506->cache_vals;
        int v689 = ((4 + ((((int)((unsigned int)((int)((unsigned int)v510 >> 2)) >> 1)) & 3) * 2)) + ((((v557 + ((~(((v559 ^ -1) | (-(v559 ^ -1))) >> 31)) & 2)) - (v561 + ((~(((v563 ^ -1) | (-(v563 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
        int v569 = v568[v689];
        int * v570 = v506->cache_vals;
        int v691 = (((4 + ((((int)((unsigned int)((int)((unsigned int)v510 >> 2)) >> 1)) & 3) * 2)) + ((((v557 + ((~(((v559 ^ -1) | (-(v559 ^ -1))) >> 31)) & 2)) - (v561 + ((~(((v563 ^ -1) | (-(v563 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
        int v571 = v570[v691];
        int * v572 = v506->mem;
        int v693 = v567 * 2;
        v572[v693] = v569;
        int * v574 = v506->mem;
        int v696 = (v567 * 2) + 1;
        v574[v696] = v571;
        ;
      } else {
        ;
      }
      int * v579 = v506->mem;
      int v701 = ((int)((unsigned int)((int)((unsigned int)v510 >> 2)) >> 1)) * 2;
      int v580 = v579[v701];
      int * v581 = v506->mem;
      int v703 = (((int)((unsigned int)((int)((unsigned int)v510 >> 2)) >> 1)) * 2) + 1;
      int v582 = v581[v703];
      int * v583 = v506->cache_vals;
      int v705 = ((4 + ((((int)((unsigned int)((int)((unsigned int)v510 >> 2)) >> 1)) & 3) * 2)) + ((((v557 + ((~(((v559 ^ -1) | (-(v559 ^ -1))) >> 31)) & 2)) - (v561 + ((~(((v563 ^ -1) | (-(v563 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
      v583[v705] = v580;
      int * v585 = v506->cache_vals;
      int v708 = (((4 + ((((int)((unsigned int)((int)((unsigned int)v510 >> 2)) >> 1)) & 3) * 2)) + ((((v557 + ((~(((v559 ^ -1) | (-(v559 ^ -1))) >> 31)) & 2)) - (v561 + ((~(((v563 ^ -1) | (-(v563 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
      v585[v708] = v582;
      int * v587 = v506->cache_tags;
      int v711 = (int)((unsigned int)((int)((unsigned int)v510 >> 2)) >> 1);
      v587[v685] = v711;
      int * v589 = v506->cache_dirty;
      v589[v685] = 0;
      int * v591 = v506->cache_age;
      v591[v685] = 1;
      int * v593 = v506->cache_age;
      int v594 = v593[v685];
      int * v595 = v506->cache_age;
      int v596 = v595[v648];
      int * v597 = v506->cache_age;
      int v719 = v596 + ((int)((unsigned int)(v596 - v594) >> 31));
      v597[v648] = v719;
      int * v599 = v506->cache_age;
      int v600 = v599[v650];
      int * v601 = v506->cache_age;
      int v722 = v600 + ((int)((unsigned int)(v600 - v594) >> 31));
      v601[v650] = v722;
      int * v603 = v506->cache_age;
      v603[v685] = 0;
      v606 = v685;
    }
    int * v607 = v506->cache_vals;
    int v725 = v606 * 2;
    int v608 = v607[v725];
    int * v609 = v506->cache_vals;
    int v727 = (v606 * 2) + 1;
    int v610 = v609[v727];
    int * v611 = v506->cache_vals;
    int v729 = (((((int)((unsigned int)((int)((unsigned int)v510 >> 2)) >> 1)) & 1) * 2) + ((((v536 + ((~(((v538 ^ -1) | (-(v538 ^ -1))) >> 31)) & 2)) - (v540 + ((~(((v542 ^ -1) | (-(v542 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
    v611[v729] = v608;
    int * v613 = v506->cache_vals;
    int v732 = ((((((int)((unsigned int)((int)((unsigned int)v510 >> 2)) >> 1)) & 1) * 2) + ((((v536 + ((~(((v538 ^ -1) | (-(v538 ^ -1))) >> 31)) & 2)) - (v540 + ((~(((v542 ^ -1) | (-(v542 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
    v613[v732] = v610;
    int * v615 = v506->cache_tags;
    int v735 = ((((int)((unsigned int)((int)((unsigned int)v510 >> 2)) >> 1)) & 1) * 2) + ((((v536 + ((~(((v538 ^ -1) | (-(v538 ^ -1))) >> 31)) & 2)) - (v540 + ((~(((v542 ^ -1) | (-(v542 ^ -1))) >> 31)) & 2))) >> 31) & 1);
    int v736 = (int)((unsigned int)((int)((unsigned int)v510 >> 2)) >> 1);
    v615[v735] = v736;
    int * v617 = v506->cache_dirty;
    v617[v735] = 0;
    int * v619 = v506->cache_age;
    v619[v735] = 1;
    int * v621 = v506->cache_age;
    int v622 = v621[v735];
    int * v623 = v506->cache_age;
    int v624 = v623[v644];
    int * v625 = v506->cache_age;
    int v744 = v624 + ((int)((unsigned int)(v624 - v622) >> 31));
    v625[v644] = v744;
    int * v627 = v506->cache_age;
    int v628 = v627[v646];
    int * v629 = v506->cache_age;
    int v747 = v628 + ((int)((unsigned int)(v628 - v622) >> 31));
    v629[v646] = v747;
    int * v631 = v506->cache_age;
    v631[v735] = 0;
    v634 = v735;
  }
  int v750 = (v634 * 2) + (((int)((unsigned int)v510 >> 2)) & 1);
  int v635 = v521[v750];
  int * v636 = v506->regs;
  v636[11] = v635;
  struct StateT * v638 = slot_9(v506);
  return v638;
}

struct StateT * slot_4(struct StateT * v64) {
  int * v65 = v64->saved_regs;
  int * v66 = v64->regs;
  int v67 = v66[7];
  v65[7] = v67;
  int v69 = v64->timer;
  int v79 = v69 + 1;
  v64->timer = v79;
  int * v71 = v64->regs;
  v71[7] = 0;
  struct StateT * v73 = slot_5(v64);
  return v73;
}

struct StateT * slot_9(struct StateT * v756) {
  int v757 = v756->timer;
  int v765 = v757 + 1;
  v756->timer = v765;
  int * v759 = v756->regs;
  int v760 = v759[11];
  int * v761 = v756->regs;
  int v769 = v760 << 2;
  v761[11] = v769;
  struct StateT * v763 = slot_10(v756);
  return v763;
}

struct StateT * slot_0(struct StateT * v2) {
  int v3 = v2->timer;
  int v11 = v3 + 1;
  v2->timer = v11;
  int * v5 = v2->regs;
  int v6 = v5[10];
  int * v7 = v2->regs;
  int v16 = v6 & 28;
  v7[5] = v16;
  struct StateT * v9 = slot_1(v2);
  return v9;
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