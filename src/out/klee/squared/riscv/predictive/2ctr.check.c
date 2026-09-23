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

struct StateT2 {
  struct StateT * a;
  struct StateT * b;
};

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

void squared_assert(bool);
void squared_assume(bool);

struct StateT2 * snippet(struct StateT2 * v0);
struct StateT2 * slot_1(struct StateT2 * v26);
struct StateT2 * slot_4(struct StateT2 * v1125);
struct StateT2 * slot_2(struct StateT2 * v554);
struct StateT2 * slot_3(struct StateT2 * v597);
struct StateT2 * slot_0(struct StateT2 * v2);
struct StateT2 * snippet(struct StateT2 * v0) {
  struct StateT2 * v1 = slot_0(v0);
  return v1;
}

struct StateT2 * slot_1(struct StateT2 * v26) {
  struct StateT * v27 = v26->a;
  int v28 = v27->timer;
  struct StateT * v29 = v26->b;
  int v30 = v29->timer;
  bool v313 = v28 == v30;
  squared_assert(v313);
  squared_assume(v313);
  struct StateT * v33 = v26->a;
  int * v34 = v33->saved_regs;
  int * v35 = v33->regs;
  int v36 = v35[11];
  v34[11] = v36;
  struct StateT * v38 = v26->b;
  int * v39 = v38->saved_regs;
  int * v40 = v38->regs;
  int v41 = v40[11];
  v39[11] = v41;
  struct StateT * v43 = v26->a;
  int v44 = v43->timer;
  int v324 = v44 + 1;
  v43->timer = v324;
  struct StateT * v46 = v26->b;
  int v47 = v46->timer;
  int v326 = v47 + 1;
  v46->timer = v326;
  struct StateT * v49 = v26->a;
  int * v50 = v49->regs;
  int v51 = v50[10];
  int * v52 = v49->cache_tags;
  int v331 = (((int)((unsigned int)((int)((unsigned int)v51 >> 2)) >> 1)) & 1) * 2;
  int v53 = v52[v331];
  int * v54 = v49->cache_tags;
  int v333 = ((((int)((unsigned int)((int)((unsigned int)v51 >> 2)) >> 1)) & 1) * 2) + 1;
  int v55 = v54[v333];
  int * v56 = v49->cache_tags;
  int v335 = 4 + ((((int)((unsigned int)((int)((unsigned int)v51 >> 2)) >> 1)) & 3) * 2);
  int v57 = v56[v335];
  int * v58 = v49->cache_tags;
  int v337 = (4 + ((((int)((unsigned int)((int)((unsigned int)v51 >> 2)) >> 1)) & 3) * 2)) + 1;
  int v59 = v58[v337];
  int v60 = v49->timer;
  int v338 = v60 + ((100 ^ (((~(((v57 ^ ((int)((unsigned int)((int)((unsigned int)v51 >> 2)) >> 1))) | (-(v57 ^ ((int)((unsigned int)((int)((unsigned int)v51 >> 2)) >> 1))))) >> 31)) | (~(((v59 ^ ((int)((unsigned int)((int)((unsigned int)v51 >> 2)) >> 1))) | (-(v59 ^ ((int)((unsigned int)((int)((unsigned int)v51 >> 2)) >> 1))))) >> 31))) & 104)) ^ (((~(((v53 ^ ((int)((unsigned int)((int)((unsigned int)v51 >> 2)) >> 1))) | (-(v53 ^ ((int)((unsigned int)((int)((unsigned int)v51 >> 2)) >> 1))))) >> 31)) | (~(((v55 ^ ((int)((unsigned int)((int)((unsigned int)v51 >> 2)) >> 1))) | (-(v55 ^ ((int)((unsigned int)((int)((unsigned int)v51 >> 2)) >> 1))))) >> 31))) & (1 ^ (100 ^ (((~(((v57 ^ ((int)((unsigned int)((int)((unsigned int)v51 >> 2)) >> 1))) | (-(v57 ^ ((int)((unsigned int)((int)((unsigned int)v51 >> 2)) >> 1))))) >> 31)) | (~(((v59 ^ ((int)((unsigned int)((int)((unsigned int)v51 >> 2)) >> 1))) | (-(v59 ^ ((int)((unsigned int)((int)((unsigned int)v51 >> 2)) >> 1))))) >> 31))) & 104)))));
  v49->timer = v338;
  int * v62 = v49->cache_vals;
  bool v339 = !(((~(((v53 ^ ((int)((unsigned int)((int)((unsigned int)v51 >> 2)) >> 1))) | (-(v53 ^ ((int)((unsigned int)((int)((unsigned int)v51 >> 2)) >> 1))))) >> 31)) | (~(((v55 ^ ((int)((unsigned int)((int)((unsigned int)v51 >> 2)) >> 1))) | (-(v55 ^ ((int)((unsigned int)((int)((unsigned int)v51 >> 2)) >> 1))))) >> 31))) == 0);
  int v175;
  if (v339) {
    int * v63 = v49->cache_age;
    int v341 = ((((int)((unsigned int)((int)((unsigned int)v51 >> 2)) >> 1)) & 1) * 2) + ((~(((v55 ^ ((int)((unsigned int)((int)((unsigned int)v51 >> 2)) >> 1))) | (-(v55 ^ ((int)((unsigned int)((int)((unsigned int)v51 >> 2)) >> 1))))) >> 31)) & 1);
    int v64 = v63[v341];
    int * v65 = v49->cache_age;
    int v66 = v65[v331];
    int * v67 = v49->cache_age;
    int v344 = v66 + ((int)((unsigned int)(v66 - v64) >> 31));
    v67[v331] = v344;
    int * v69 = v49->cache_age;
    int v70 = v69[v333];
    int * v71 = v49->cache_age;
    int v347 = v70 + ((int)((unsigned int)(v70 - v64) >> 31));
    v71[v333] = v347;
    int * v73 = v49->cache_age;
    v73[v341] = 0;
    v175 = v341;
  } else {
    int * v76 = v49->cache_age;
    int v351 = (((int)((unsigned int)((int)((unsigned int)v51 >> 2)) >> 1)) & 1) * 2;
    int v77 = v76[v351];
    int * v78 = v49->cache_tags;
    int v79 = v78[v351];
    int * v80 = v49->cache_age;
    int v81 = v80[v333];
    int * v82 = v49->cache_tags;
    int v83 = v82[v333];
    bool v355 = !(((~(((v57 ^ ((int)((unsigned int)((int)((unsigned int)v51 >> 2)) >> 1))) | (-(v57 ^ ((int)((unsigned int)((int)((unsigned int)v51 >> 2)) >> 1))))) >> 31)) | (~(((v59 ^ ((int)((unsigned int)((int)((unsigned int)v51 >> 2)) >> 1))) | (-(v59 ^ ((int)((unsigned int)((int)((unsigned int)v51 >> 2)) >> 1))))) >> 31))) == 0);
    int v147;
    if (v355) {
      int * v84 = v49->cache_age;
      int v357 = (4 + ((((int)((unsigned int)((int)((unsigned int)v51 >> 2)) >> 1)) & 3) * 2)) + ((~(((v59 ^ ((int)((unsigned int)((int)((unsigned int)v51 >> 2)) >> 1))) | (-(v59 ^ ((int)((unsigned int)((int)((unsigned int)v51 >> 2)) >> 1))))) >> 31)) & 1);
      int v85 = v84[v357];
      int * v86 = v49->cache_age;
      int v87 = v86[v335];
      int * v88 = v49->cache_age;
      int v360 = v87 + ((int)((unsigned int)(v87 - v85) >> 31));
      v88[v335] = v360;
      int * v90 = v49->cache_age;
      int v91 = v90[v337];
      int * v92 = v49->cache_age;
      int v363 = v91 + ((int)((unsigned int)(v91 - v85) >> 31));
      v92[v337] = v363;
      int * v94 = v49->cache_age;
      v94[v357] = 0;
      v147 = v357;
    } else {
      int * v97 = v49->cache_age;
      int v367 = 4 + ((((int)((unsigned int)((int)((unsigned int)v51 >> 2)) >> 1)) & 3) * 2);
      int v98 = v97[v367];
      int * v99 = v49->cache_tags;
      int v100 = v99[v367];
      int * v101 = v49->cache_age;
      int v102 = v101[v337];
      int * v103 = v49->cache_tags;
      int v104 = v103[v337];
      int * v105 = v49->cache_dirty;
      int v372 = (4 + ((((int)((unsigned int)((int)((unsigned int)v51 >> 2)) >> 1)) & 3) * 2)) + ((((v98 + ((~(((v100 ^ -1) | (-(v100 ^ -1))) >> 31)) & 2)) - (v102 + ((~(((v104 ^ -1) | (-(v104 ^ -1))) >> 31)) & 2))) >> 31) & 1);
      int v106 = v105[v372];
      bool v373 = !(v106 == 0);
      if (v373) {
        int * v107 = v49->cache_tags;
        int v108 = v107[v372];
        int * v109 = v49->cache_vals;
        int v376 = ((4 + ((((int)((unsigned int)((int)((unsigned int)v51 >> 2)) >> 1)) & 3) * 2)) + ((((v98 + ((~(((v100 ^ -1) | (-(v100 ^ -1))) >> 31)) & 2)) - (v102 + ((~(((v104 ^ -1) | (-(v104 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
        int v110 = v109[v376];
        int * v111 = v49->cache_vals;
        int v378 = (((4 + ((((int)((unsigned int)((int)((unsigned int)v51 >> 2)) >> 1)) & 3) * 2)) + ((((v98 + ((~(((v100 ^ -1) | (-(v100 ^ -1))) >> 31)) & 2)) - (v102 + ((~(((v104 ^ -1) | (-(v104 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
        int v112 = v111[v378];
        int * v113 = v49->mem;
        int v380 = v108 * 2;
        v113[v380] = v110;
        int * v115 = v49->mem;
        int v383 = (v108 * 2) + 1;
        v115[v383] = v112;
        ;
      } else {
        ;
      }
      int * v120 = v49->mem;
      int v388 = ((int)((unsigned int)((int)((unsigned int)v51 >> 2)) >> 1)) * 2;
      int v121 = v120[v388];
      int * v122 = v49->mem;
      int v390 = (((int)((unsigned int)((int)((unsigned int)v51 >> 2)) >> 1)) * 2) + 1;
      int v123 = v122[v390];
      int * v124 = v49->cache_vals;
      int v392 = ((4 + ((((int)((unsigned int)((int)((unsigned int)v51 >> 2)) >> 1)) & 3) * 2)) + ((((v98 + ((~(((v100 ^ -1) | (-(v100 ^ -1))) >> 31)) & 2)) - (v102 + ((~(((v104 ^ -1) | (-(v104 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
      v124[v392] = v121;
      int * v126 = v49->cache_vals;
      int v395 = (((4 + ((((int)((unsigned int)((int)((unsigned int)v51 >> 2)) >> 1)) & 3) * 2)) + ((((v98 + ((~(((v100 ^ -1) | (-(v100 ^ -1))) >> 31)) & 2)) - (v102 + ((~(((v104 ^ -1) | (-(v104 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
      v126[v395] = v123;
      int * v128 = v49->cache_tags;
      int v398 = (int)((unsigned int)((int)((unsigned int)v51 >> 2)) >> 1);
      v128[v372] = v398;
      int * v130 = v49->cache_dirty;
      v130[v372] = 0;
      int * v132 = v49->cache_age;
      v132[v372] = 1;
      int * v134 = v49->cache_age;
      int v135 = v134[v372];
      int * v136 = v49->cache_age;
      int v137 = v136[v335];
      int * v138 = v49->cache_age;
      int v406 = v137 + ((int)((unsigned int)(v137 - v135) >> 31));
      v138[v335] = v406;
      int * v140 = v49->cache_age;
      int v141 = v140[v337];
      int * v142 = v49->cache_age;
      int v409 = v141 + ((int)((unsigned int)(v141 - v135) >> 31));
      v142[v337] = v409;
      int * v144 = v49->cache_age;
      v144[v372] = 0;
      v147 = v372;
    }
    int * v148 = v49->cache_vals;
    int v412 = v147 * 2;
    int v149 = v148[v412];
    int * v150 = v49->cache_vals;
    int v414 = (v147 * 2) + 1;
    int v151 = v150[v414];
    int * v152 = v49->cache_vals;
    int v416 = (((((int)((unsigned int)((int)((unsigned int)v51 >> 2)) >> 1)) & 1) * 2) + ((((v77 + ((~(((v79 ^ -1) | (-(v79 ^ -1))) >> 31)) & 2)) - (v81 + ((~(((v83 ^ -1) | (-(v83 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
    v152[v416] = v149;
    int * v154 = v49->cache_vals;
    int v419 = ((((((int)((unsigned int)((int)((unsigned int)v51 >> 2)) >> 1)) & 1) * 2) + ((((v77 + ((~(((v79 ^ -1) | (-(v79 ^ -1))) >> 31)) & 2)) - (v81 + ((~(((v83 ^ -1) | (-(v83 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
    v154[v419] = v151;
    int * v156 = v49->cache_tags;
    int v422 = ((((int)((unsigned int)((int)((unsigned int)v51 >> 2)) >> 1)) & 1) * 2) + ((((v77 + ((~(((v79 ^ -1) | (-(v79 ^ -1))) >> 31)) & 2)) - (v81 + ((~(((v83 ^ -1) | (-(v83 ^ -1))) >> 31)) & 2))) >> 31) & 1);
    int v423 = (int)((unsigned int)((int)((unsigned int)v51 >> 2)) >> 1);
    v156[v422] = v423;
    int * v158 = v49->cache_dirty;
    v158[v422] = 0;
    int * v160 = v49->cache_age;
    v160[v422] = 1;
    int * v162 = v49->cache_age;
    int v163 = v162[v422];
    int * v164 = v49->cache_age;
    int v165 = v164[v331];
    int * v166 = v49->cache_age;
    int v431 = v165 + ((int)((unsigned int)(v165 - v163) >> 31));
    v166[v331] = v431;
    int * v168 = v49->cache_age;
    int v169 = v168[v333];
    int * v170 = v49->cache_age;
    int v434 = v169 + ((int)((unsigned int)(v169 - v163) >> 31));
    v170[v333] = v434;
    int * v172 = v49->cache_age;
    v172[v422] = 0;
    v175 = v422;
  }
  int v437 = (v175 * 2) + (((int)((unsigned int)v51 >> 2)) & 1);
  int v176 = v62[v437];
  int * v177 = v49->regs;
  v177[11] = v176;
  struct StateT * v179 = v26->b;
  int * v180 = v179->regs;
  int v181 = v180[10];
  int * v182 = v179->cache_tags;
  int v443 = (((int)((unsigned int)((int)((unsigned int)v181 >> 2)) >> 1)) & 1) * 2;
  int v183 = v182[v443];
  int * v184 = v179->cache_tags;
  int v445 = ((((int)((unsigned int)((int)((unsigned int)v181 >> 2)) >> 1)) & 1) * 2) + 1;
  int v185 = v184[v445];
  int * v186 = v179->cache_tags;
  int v447 = 4 + ((((int)((unsigned int)((int)((unsigned int)v181 >> 2)) >> 1)) & 3) * 2);
  int v187 = v186[v447];
  int * v188 = v179->cache_tags;
  int v449 = (4 + ((((int)((unsigned int)((int)((unsigned int)v181 >> 2)) >> 1)) & 3) * 2)) + 1;
  int v189 = v188[v449];
  int v190 = v179->timer;
  int v450 = v190 + ((100 ^ (((~(((v187 ^ ((int)((unsigned int)((int)((unsigned int)v181 >> 2)) >> 1))) | (-(v187 ^ ((int)((unsigned int)((int)((unsigned int)v181 >> 2)) >> 1))))) >> 31)) | (~(((v189 ^ ((int)((unsigned int)((int)((unsigned int)v181 >> 2)) >> 1))) | (-(v189 ^ ((int)((unsigned int)((int)((unsigned int)v181 >> 2)) >> 1))))) >> 31))) & 104)) ^ (((~(((v183 ^ ((int)((unsigned int)((int)((unsigned int)v181 >> 2)) >> 1))) | (-(v183 ^ ((int)((unsigned int)((int)((unsigned int)v181 >> 2)) >> 1))))) >> 31)) | (~(((v185 ^ ((int)((unsigned int)((int)((unsigned int)v181 >> 2)) >> 1))) | (-(v185 ^ ((int)((unsigned int)((int)((unsigned int)v181 >> 2)) >> 1))))) >> 31))) & (1 ^ (100 ^ (((~(((v187 ^ ((int)((unsigned int)((int)((unsigned int)v181 >> 2)) >> 1))) | (-(v187 ^ ((int)((unsigned int)((int)((unsigned int)v181 >> 2)) >> 1))))) >> 31)) | (~(((v189 ^ ((int)((unsigned int)((int)((unsigned int)v181 >> 2)) >> 1))) | (-(v189 ^ ((int)((unsigned int)((int)((unsigned int)v181 >> 2)) >> 1))))) >> 31))) & 104)))));
  v179->timer = v450;
  int * v192 = v179->cache_vals;
  bool v451 = !(((~(((v183 ^ ((int)((unsigned int)((int)((unsigned int)v181 >> 2)) >> 1))) | (-(v183 ^ ((int)((unsigned int)((int)((unsigned int)v181 >> 2)) >> 1))))) >> 31)) | (~(((v185 ^ ((int)((unsigned int)((int)((unsigned int)v181 >> 2)) >> 1))) | (-(v185 ^ ((int)((unsigned int)((int)((unsigned int)v181 >> 2)) >> 1))))) >> 31))) == 0);
  int v305;
  if (v451) {
    int * v193 = v179->cache_age;
    int v453 = ((((int)((unsigned int)((int)((unsigned int)v181 >> 2)) >> 1)) & 1) * 2) + ((~(((v185 ^ ((int)((unsigned int)((int)((unsigned int)v181 >> 2)) >> 1))) | (-(v185 ^ ((int)((unsigned int)((int)((unsigned int)v181 >> 2)) >> 1))))) >> 31)) & 1);
    int v194 = v193[v453];
    int * v195 = v179->cache_age;
    int v196 = v195[v443];
    int * v197 = v179->cache_age;
    int v456 = v196 + ((int)((unsigned int)(v196 - v194) >> 31));
    v197[v443] = v456;
    int * v199 = v179->cache_age;
    int v200 = v199[v445];
    int * v201 = v179->cache_age;
    int v459 = v200 + ((int)((unsigned int)(v200 - v194) >> 31));
    v201[v445] = v459;
    int * v203 = v179->cache_age;
    v203[v453] = 0;
    v305 = v453;
  } else {
    int * v206 = v179->cache_age;
    int v463 = (((int)((unsigned int)((int)((unsigned int)v181 >> 2)) >> 1)) & 1) * 2;
    int v207 = v206[v463];
    int * v208 = v179->cache_tags;
    int v209 = v208[v463];
    int * v210 = v179->cache_age;
    int v211 = v210[v445];
    int * v212 = v179->cache_tags;
    int v213 = v212[v445];
    bool v467 = !(((~(((v187 ^ ((int)((unsigned int)((int)((unsigned int)v181 >> 2)) >> 1))) | (-(v187 ^ ((int)((unsigned int)((int)((unsigned int)v181 >> 2)) >> 1))))) >> 31)) | (~(((v189 ^ ((int)((unsigned int)((int)((unsigned int)v181 >> 2)) >> 1))) | (-(v189 ^ ((int)((unsigned int)((int)((unsigned int)v181 >> 2)) >> 1))))) >> 31))) == 0);
    int v277;
    if (v467) {
      int * v214 = v179->cache_age;
      int v469 = (4 + ((((int)((unsigned int)((int)((unsigned int)v181 >> 2)) >> 1)) & 3) * 2)) + ((~(((v189 ^ ((int)((unsigned int)((int)((unsigned int)v181 >> 2)) >> 1))) | (-(v189 ^ ((int)((unsigned int)((int)((unsigned int)v181 >> 2)) >> 1))))) >> 31)) & 1);
      int v215 = v214[v469];
      int * v216 = v179->cache_age;
      int v217 = v216[v447];
      int * v218 = v179->cache_age;
      int v472 = v217 + ((int)((unsigned int)(v217 - v215) >> 31));
      v218[v447] = v472;
      int * v220 = v179->cache_age;
      int v221 = v220[v449];
      int * v222 = v179->cache_age;
      int v475 = v221 + ((int)((unsigned int)(v221 - v215) >> 31));
      v222[v449] = v475;
      int * v224 = v179->cache_age;
      v224[v469] = 0;
      v277 = v469;
    } else {
      int * v227 = v179->cache_age;
      int v479 = 4 + ((((int)((unsigned int)((int)((unsigned int)v181 >> 2)) >> 1)) & 3) * 2);
      int v228 = v227[v479];
      int * v229 = v179->cache_tags;
      int v230 = v229[v479];
      int * v231 = v179->cache_age;
      int v232 = v231[v449];
      int * v233 = v179->cache_tags;
      int v234 = v233[v449];
      int * v235 = v179->cache_dirty;
      int v484 = (4 + ((((int)((unsigned int)((int)((unsigned int)v181 >> 2)) >> 1)) & 3) * 2)) + ((((v228 + ((~(((v230 ^ -1) | (-(v230 ^ -1))) >> 31)) & 2)) - (v232 + ((~(((v234 ^ -1) | (-(v234 ^ -1))) >> 31)) & 2))) >> 31) & 1);
      int v236 = v235[v484];
      bool v485 = !(v236 == 0);
      if (v485) {
        int * v237 = v179->cache_tags;
        int v238 = v237[v484];
        int * v239 = v179->cache_vals;
        int v488 = ((4 + ((((int)((unsigned int)((int)((unsigned int)v181 >> 2)) >> 1)) & 3) * 2)) + ((((v228 + ((~(((v230 ^ -1) | (-(v230 ^ -1))) >> 31)) & 2)) - (v232 + ((~(((v234 ^ -1) | (-(v234 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
        int v240 = v239[v488];
        int * v241 = v179->cache_vals;
        int v490 = (((4 + ((((int)((unsigned int)((int)((unsigned int)v181 >> 2)) >> 1)) & 3) * 2)) + ((((v228 + ((~(((v230 ^ -1) | (-(v230 ^ -1))) >> 31)) & 2)) - (v232 + ((~(((v234 ^ -1) | (-(v234 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
        int v242 = v241[v490];
        int * v243 = v179->mem;
        int v492 = v238 * 2;
        v243[v492] = v240;
        int * v245 = v179->mem;
        int v495 = (v238 * 2) + 1;
        v245[v495] = v242;
        ;
      } else {
        ;
      }
      int * v250 = v179->mem;
      int v500 = ((int)((unsigned int)((int)((unsigned int)v181 >> 2)) >> 1)) * 2;
      int v251 = v250[v500];
      int * v252 = v179->mem;
      int v502 = (((int)((unsigned int)((int)((unsigned int)v181 >> 2)) >> 1)) * 2) + 1;
      int v253 = v252[v502];
      int * v254 = v179->cache_vals;
      int v504 = ((4 + ((((int)((unsigned int)((int)((unsigned int)v181 >> 2)) >> 1)) & 3) * 2)) + ((((v228 + ((~(((v230 ^ -1) | (-(v230 ^ -1))) >> 31)) & 2)) - (v232 + ((~(((v234 ^ -1) | (-(v234 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
      v254[v504] = v251;
      int * v256 = v179->cache_vals;
      int v507 = (((4 + ((((int)((unsigned int)((int)((unsigned int)v181 >> 2)) >> 1)) & 3) * 2)) + ((((v228 + ((~(((v230 ^ -1) | (-(v230 ^ -1))) >> 31)) & 2)) - (v232 + ((~(((v234 ^ -1) | (-(v234 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
      v256[v507] = v253;
      int * v258 = v179->cache_tags;
      int v510 = (int)((unsigned int)((int)((unsigned int)v181 >> 2)) >> 1);
      v258[v484] = v510;
      int * v260 = v179->cache_dirty;
      v260[v484] = 0;
      int * v262 = v179->cache_age;
      v262[v484] = 1;
      int * v264 = v179->cache_age;
      int v265 = v264[v484];
      int * v266 = v179->cache_age;
      int v267 = v266[v447];
      int * v268 = v179->cache_age;
      int v518 = v267 + ((int)((unsigned int)(v267 - v265) >> 31));
      v268[v447] = v518;
      int * v270 = v179->cache_age;
      int v271 = v270[v449];
      int * v272 = v179->cache_age;
      int v521 = v271 + ((int)((unsigned int)(v271 - v265) >> 31));
      v272[v449] = v521;
      int * v274 = v179->cache_age;
      v274[v484] = 0;
      v277 = v484;
    }
    int * v278 = v179->cache_vals;
    int v524 = v277 * 2;
    int v279 = v278[v524];
    int * v280 = v179->cache_vals;
    int v526 = (v277 * 2) + 1;
    int v281 = v280[v526];
    int * v282 = v179->cache_vals;
    int v528 = (((((int)((unsigned int)((int)((unsigned int)v181 >> 2)) >> 1)) & 1) * 2) + ((((v207 + ((~(((v209 ^ -1) | (-(v209 ^ -1))) >> 31)) & 2)) - (v211 + ((~(((v213 ^ -1) | (-(v213 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
    v282[v528] = v279;
    int * v284 = v179->cache_vals;
    int v531 = ((((((int)((unsigned int)((int)((unsigned int)v181 >> 2)) >> 1)) & 1) * 2) + ((((v207 + ((~(((v209 ^ -1) | (-(v209 ^ -1))) >> 31)) & 2)) - (v211 + ((~(((v213 ^ -1) | (-(v213 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
    v284[v531] = v281;
    int * v286 = v179->cache_tags;
    int v534 = ((((int)((unsigned int)((int)((unsigned int)v181 >> 2)) >> 1)) & 1) * 2) + ((((v207 + ((~(((v209 ^ -1) | (-(v209 ^ -1))) >> 31)) & 2)) - (v211 + ((~(((v213 ^ -1) | (-(v213 ^ -1))) >> 31)) & 2))) >> 31) & 1);
    int v535 = (int)((unsigned int)((int)((unsigned int)v181 >> 2)) >> 1);
    v286[v534] = v535;
    int * v288 = v179->cache_dirty;
    v288[v534] = 0;
    int * v290 = v179->cache_age;
    v290[v534] = 1;
    int * v292 = v179->cache_age;
    int v293 = v292[v534];
    int * v294 = v179->cache_age;
    int v295 = v294[v443];
    int * v296 = v179->cache_age;
    int v543 = v295 + ((int)((unsigned int)(v295 - v293) >> 31));
    v296[v443] = v543;
    int * v298 = v179->cache_age;
    int v299 = v298[v445];
    int * v300 = v179->cache_age;
    int v546 = v299 + ((int)((unsigned int)(v299 - v293) >> 31));
    v300[v445] = v546;
    int * v302 = v179->cache_age;
    v302[v534] = 0;
    v305 = v534;
  }
  int v549 = (v305 * 2) + (((int)((unsigned int)v181 >> 2)) & 1);
  int v306 = v192[v549];
  int * v307 = v179->regs;
  v307[11] = v306;
  struct StateT2 * v309 = slot_2(v26);
  return v309;
}

struct StateT2 * slot_4(struct StateT2 * v1125) {
  struct StateT * v1126 = v1125->a;
  int v1127 = v1126->timer;
  struct StateT * v1128 = v1125->b;
  int v1129 = v1128->timer;
  bool v1168 = v1127 == v1129;
  squared_assert(v1168);
  squared_assume(v1168);
  struct StateT * v1132 = v1125->a;
  int * v1133 = v1132->regs;
  int v1134 = v1133[10];
  struct StateT * v1135 = v1125->b;
  int * v1136 = v1135->regs;
  int v1137 = v1136[10];
  bool v1174 = (v1134 == 0) == (v1137 == 0);
  squared_assert(v1174);
  squared_assume(v1174);
  bool v1175 = v1134 == 0;
  struct StateT2 * v1164;
  if (v1175) {
    struct StateT * v1140 = v1125->a;
    int v1141 = v1140->timer;
    int v1177 = v1141 + 15;
    v1140->timer = v1177;
    int * v1143 = v1140->saved_regs;
    int v1144 = v1143[11];
    int * v1145 = v1140->regs;
    v1145[11] = v1144;
    int * v1147 = v1140->saved_regs;
    int v1148 = v1147[12];
    int * v1149 = v1140->regs;
    v1149[12] = v1148;
    struct StateT * v1151 = v1125->b;
    int v1152 = v1151->timer;
    int v1187 = v1152 + 15;
    v1151->timer = v1187;
    int * v1154 = v1151->saved_regs;
    int v1155 = v1154[11];
    int * v1156 = v1151->regs;
    v1156[11] = v1155;
    int * v1158 = v1151->saved_regs;
    int v1159 = v1158[12];
    int * v1160 = v1151->regs;
    v1160[12] = v1159;
    v1164 = v1125;
  } else {
    v1164 = v1125;
  }
  return v1164;
}

struct StateT2 * slot_2(struct StateT2 * v554) {
  struct StateT * v555 = v554->a;
  int v556 = v555->timer;
  struct StateT * v557 = v554->b;
  int v558 = v557->timer;
  bool v581 = v556 == v558;
  squared_assert(v581);
  squared_assume(v581);
  struct StateT * v561 = v554->a;
  int v562 = v561->timer;
  int v583 = v562 + 1;
  v561->timer = v583;
  struct StateT * v564 = v554->b;
  int v565 = v564->timer;
  int v585 = v565 + 1;
  v564->timer = v585;
  struct StateT * v567 = v554->a;
  int * v568 = v567->regs;
  int v569 = v568[11];
  int * v570 = v567->regs;
  int v590 = v569 << 2;
  v570[11] = v590;
  struct StateT * v572 = v554->b;
  int * v573 = v572->regs;
  int v574 = v573[11];
  int * v575 = v572->regs;
  int v594 = v574 << 2;
  v575[11] = v594;
  struct StateT2 * v577 = slot_3(v554);
  return v577;
}

struct StateT2 * slot_3(struct StateT2 * v597) {
  struct StateT * v598 = v597->a;
  int v599 = v598->timer;
  struct StateT * v600 = v597->b;
  int v601 = v600->timer;
  bool v884 = v599 == v601;
  squared_assert(v884);
  squared_assume(v884);
  struct StateT * v604 = v597->a;
  int * v605 = v604->saved_regs;
  int * v606 = v604->regs;
  int v607 = v606[12];
  v605[12] = v607;
  struct StateT * v609 = v597->b;
  int * v610 = v609->saved_regs;
  int * v611 = v609->regs;
  int v612 = v611[12];
  v610[12] = v612;
  struct StateT * v614 = v597->a;
  int v615 = v614->timer;
  int v895 = v615 + 1;
  v614->timer = v895;
  struct StateT * v617 = v597->b;
  int v618 = v617->timer;
  int v897 = v618 + 1;
  v617->timer = v897;
  struct StateT * v620 = v597->a;
  int * v621 = v620->regs;
  int v622 = v621[11];
  int * v623 = v620->cache_tags;
  int v902 = (((int)((unsigned int)((int)((unsigned int)(v622 + 16) >> 2)) >> 1)) & 1) * 2;
  int v624 = v623[v902];
  int * v625 = v620->cache_tags;
  int v904 = ((((int)((unsigned int)((int)((unsigned int)(v622 + 16) >> 2)) >> 1)) & 1) * 2) + 1;
  int v626 = v625[v904];
  int * v627 = v620->cache_tags;
  int v906 = 4 + ((((int)((unsigned int)((int)((unsigned int)(v622 + 16) >> 2)) >> 1)) & 3) * 2);
  int v628 = v627[v906];
  int * v629 = v620->cache_tags;
  int v908 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v622 + 16) >> 2)) >> 1)) & 3) * 2)) + 1;
  int v630 = v629[v908];
  int v631 = v620->timer;
  int v909 = v631 + ((100 ^ (((~(((v628 ^ ((int)((unsigned int)((int)((unsigned int)(v622 + 16) >> 2)) >> 1))) | (-(v628 ^ ((int)((unsigned int)((int)((unsigned int)(v622 + 16) >> 2)) >> 1))))) >> 31)) | (~(((v630 ^ ((int)((unsigned int)((int)((unsigned int)(v622 + 16) >> 2)) >> 1))) | (-(v630 ^ ((int)((unsigned int)((int)((unsigned int)(v622 + 16) >> 2)) >> 1))))) >> 31))) & 104)) ^ (((~(((v624 ^ ((int)((unsigned int)((int)((unsigned int)(v622 + 16) >> 2)) >> 1))) | (-(v624 ^ ((int)((unsigned int)((int)((unsigned int)(v622 + 16) >> 2)) >> 1))))) >> 31)) | (~(((v626 ^ ((int)((unsigned int)((int)((unsigned int)(v622 + 16) >> 2)) >> 1))) | (-(v626 ^ ((int)((unsigned int)((int)((unsigned int)(v622 + 16) >> 2)) >> 1))))) >> 31))) & (1 ^ (100 ^ (((~(((v628 ^ ((int)((unsigned int)((int)((unsigned int)(v622 + 16) >> 2)) >> 1))) | (-(v628 ^ ((int)((unsigned int)((int)((unsigned int)(v622 + 16) >> 2)) >> 1))))) >> 31)) | (~(((v630 ^ ((int)((unsigned int)((int)((unsigned int)(v622 + 16) >> 2)) >> 1))) | (-(v630 ^ ((int)((unsigned int)((int)((unsigned int)(v622 + 16) >> 2)) >> 1))))) >> 31))) & 104)))));
  v620->timer = v909;
  int * v633 = v620->cache_vals;
  bool v910 = !(((~(((v624 ^ ((int)((unsigned int)((int)((unsigned int)(v622 + 16) >> 2)) >> 1))) | (-(v624 ^ ((int)((unsigned int)((int)((unsigned int)(v622 + 16) >> 2)) >> 1))))) >> 31)) | (~(((v626 ^ ((int)((unsigned int)((int)((unsigned int)(v622 + 16) >> 2)) >> 1))) | (-(v626 ^ ((int)((unsigned int)((int)((unsigned int)(v622 + 16) >> 2)) >> 1))))) >> 31))) == 0);
  int v746;
  if (v910) {
    int * v634 = v620->cache_age;
    int v912 = ((((int)((unsigned int)((int)((unsigned int)(v622 + 16) >> 2)) >> 1)) & 1) * 2) + ((~(((v626 ^ ((int)((unsigned int)((int)((unsigned int)(v622 + 16) >> 2)) >> 1))) | (-(v626 ^ ((int)((unsigned int)((int)((unsigned int)(v622 + 16) >> 2)) >> 1))))) >> 31)) & 1);
    int v635 = v634[v912];
    int * v636 = v620->cache_age;
    int v637 = v636[v902];
    int * v638 = v620->cache_age;
    int v915 = v637 + ((int)((unsigned int)(v637 - v635) >> 31));
    v638[v902] = v915;
    int * v640 = v620->cache_age;
    int v641 = v640[v904];
    int * v642 = v620->cache_age;
    int v918 = v641 + ((int)((unsigned int)(v641 - v635) >> 31));
    v642[v904] = v918;
    int * v644 = v620->cache_age;
    v644[v912] = 0;
    v746 = v912;
  } else {
    int * v647 = v620->cache_age;
    int v922 = (((int)((unsigned int)((int)((unsigned int)(v622 + 16) >> 2)) >> 1)) & 1) * 2;
    int v648 = v647[v922];
    int * v649 = v620->cache_tags;
    int v650 = v649[v922];
    int * v651 = v620->cache_age;
    int v652 = v651[v904];
    int * v653 = v620->cache_tags;
    int v654 = v653[v904];
    bool v926 = !(((~(((v628 ^ ((int)((unsigned int)((int)((unsigned int)(v622 + 16) >> 2)) >> 1))) | (-(v628 ^ ((int)((unsigned int)((int)((unsigned int)(v622 + 16) >> 2)) >> 1))))) >> 31)) | (~(((v630 ^ ((int)((unsigned int)((int)((unsigned int)(v622 + 16) >> 2)) >> 1))) | (-(v630 ^ ((int)((unsigned int)((int)((unsigned int)(v622 + 16) >> 2)) >> 1))))) >> 31))) == 0);
    int v718;
    if (v926) {
      int * v655 = v620->cache_age;
      int v928 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v622 + 16) >> 2)) >> 1)) & 3) * 2)) + ((~(((v630 ^ ((int)((unsigned int)((int)((unsigned int)(v622 + 16) >> 2)) >> 1))) | (-(v630 ^ ((int)((unsigned int)((int)((unsigned int)(v622 + 16) >> 2)) >> 1))))) >> 31)) & 1);
      int v656 = v655[v928];
      int * v657 = v620->cache_age;
      int v658 = v657[v906];
      int * v659 = v620->cache_age;
      int v931 = v658 + ((int)((unsigned int)(v658 - v656) >> 31));
      v659[v906] = v931;
      int * v661 = v620->cache_age;
      int v662 = v661[v908];
      int * v663 = v620->cache_age;
      int v934 = v662 + ((int)((unsigned int)(v662 - v656) >> 31));
      v663[v908] = v934;
      int * v665 = v620->cache_age;
      v665[v928] = 0;
      v718 = v928;
    } else {
      int * v668 = v620->cache_age;
      int v938 = 4 + ((((int)((unsigned int)((int)((unsigned int)(v622 + 16) >> 2)) >> 1)) & 3) * 2);
      int v669 = v668[v938];
      int * v670 = v620->cache_tags;
      int v671 = v670[v938];
      int * v672 = v620->cache_age;
      int v673 = v672[v908];
      int * v674 = v620->cache_tags;
      int v675 = v674[v908];
      int * v676 = v620->cache_dirty;
      int v943 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v622 + 16) >> 2)) >> 1)) & 3) * 2)) + ((((v669 + ((~(((v671 ^ -1) | (-(v671 ^ -1))) >> 31)) & 2)) - (v673 + ((~(((v675 ^ -1) | (-(v675 ^ -1))) >> 31)) & 2))) >> 31) & 1);
      int v677 = v676[v943];
      bool v944 = !(v677 == 0);
      if (v944) {
        int * v678 = v620->cache_tags;
        int v679 = v678[v943];
        int * v680 = v620->cache_vals;
        int v947 = ((4 + ((((int)((unsigned int)((int)((unsigned int)(v622 + 16) >> 2)) >> 1)) & 3) * 2)) + ((((v669 + ((~(((v671 ^ -1) | (-(v671 ^ -1))) >> 31)) & 2)) - (v673 + ((~(((v675 ^ -1) | (-(v675 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
        int v681 = v680[v947];
        int * v682 = v620->cache_vals;
        int v949 = (((4 + ((((int)((unsigned int)((int)((unsigned int)(v622 + 16) >> 2)) >> 1)) & 3) * 2)) + ((((v669 + ((~(((v671 ^ -1) | (-(v671 ^ -1))) >> 31)) & 2)) - (v673 + ((~(((v675 ^ -1) | (-(v675 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
        int v683 = v682[v949];
        int * v684 = v620->mem;
        int v951 = v679 * 2;
        v684[v951] = v681;
        int * v686 = v620->mem;
        int v954 = (v679 * 2) + 1;
        v686[v954] = v683;
        ;
      } else {
        ;
      }
      int * v691 = v620->mem;
      int v959 = ((int)((unsigned int)((int)((unsigned int)(v622 + 16) >> 2)) >> 1)) * 2;
      int v692 = v691[v959];
      int * v693 = v620->mem;
      int v961 = (((int)((unsigned int)((int)((unsigned int)(v622 + 16) >> 2)) >> 1)) * 2) + 1;
      int v694 = v693[v961];
      int * v695 = v620->cache_vals;
      int v963 = ((4 + ((((int)((unsigned int)((int)((unsigned int)(v622 + 16) >> 2)) >> 1)) & 3) * 2)) + ((((v669 + ((~(((v671 ^ -1) | (-(v671 ^ -1))) >> 31)) & 2)) - (v673 + ((~(((v675 ^ -1) | (-(v675 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
      v695[v963] = v692;
      int * v697 = v620->cache_vals;
      int v966 = (((4 + ((((int)((unsigned int)((int)((unsigned int)(v622 + 16) >> 2)) >> 1)) & 3) * 2)) + ((((v669 + ((~(((v671 ^ -1) | (-(v671 ^ -1))) >> 31)) & 2)) - (v673 + ((~(((v675 ^ -1) | (-(v675 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
      v697[v966] = v694;
      int * v699 = v620->cache_tags;
      int v969 = (int)((unsigned int)((int)((unsigned int)(v622 + 16) >> 2)) >> 1);
      v699[v943] = v969;
      int * v701 = v620->cache_dirty;
      v701[v943] = 0;
      int * v703 = v620->cache_age;
      v703[v943] = 1;
      int * v705 = v620->cache_age;
      int v706 = v705[v943];
      int * v707 = v620->cache_age;
      int v708 = v707[v906];
      int * v709 = v620->cache_age;
      int v977 = v708 + ((int)((unsigned int)(v708 - v706) >> 31));
      v709[v906] = v977;
      int * v711 = v620->cache_age;
      int v712 = v711[v908];
      int * v713 = v620->cache_age;
      int v980 = v712 + ((int)((unsigned int)(v712 - v706) >> 31));
      v713[v908] = v980;
      int * v715 = v620->cache_age;
      v715[v943] = 0;
      v718 = v943;
    }
    int * v719 = v620->cache_vals;
    int v983 = v718 * 2;
    int v720 = v719[v983];
    int * v721 = v620->cache_vals;
    int v985 = (v718 * 2) + 1;
    int v722 = v721[v985];
    int * v723 = v620->cache_vals;
    int v987 = (((((int)((unsigned int)((int)((unsigned int)(v622 + 16) >> 2)) >> 1)) & 1) * 2) + ((((v648 + ((~(((v650 ^ -1) | (-(v650 ^ -1))) >> 31)) & 2)) - (v652 + ((~(((v654 ^ -1) | (-(v654 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
    v723[v987] = v720;
    int * v725 = v620->cache_vals;
    int v990 = ((((((int)((unsigned int)((int)((unsigned int)(v622 + 16) >> 2)) >> 1)) & 1) * 2) + ((((v648 + ((~(((v650 ^ -1) | (-(v650 ^ -1))) >> 31)) & 2)) - (v652 + ((~(((v654 ^ -1) | (-(v654 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
    v725[v990] = v722;
    int * v727 = v620->cache_tags;
    int v993 = ((((int)((unsigned int)((int)((unsigned int)(v622 + 16) >> 2)) >> 1)) & 1) * 2) + ((((v648 + ((~(((v650 ^ -1) | (-(v650 ^ -1))) >> 31)) & 2)) - (v652 + ((~(((v654 ^ -1) | (-(v654 ^ -1))) >> 31)) & 2))) >> 31) & 1);
    int v994 = (int)((unsigned int)((int)((unsigned int)(v622 + 16) >> 2)) >> 1);
    v727[v993] = v994;
    int * v729 = v620->cache_dirty;
    v729[v993] = 0;
    int * v731 = v620->cache_age;
    v731[v993] = 1;
    int * v733 = v620->cache_age;
    int v734 = v733[v993];
    int * v735 = v620->cache_age;
    int v736 = v735[v902];
    int * v737 = v620->cache_age;
    int v1002 = v736 + ((int)((unsigned int)(v736 - v734) >> 31));
    v737[v902] = v1002;
    int * v739 = v620->cache_age;
    int v740 = v739[v904];
    int * v741 = v620->cache_age;
    int v1005 = v740 + ((int)((unsigned int)(v740 - v734) >> 31));
    v741[v904] = v1005;
    int * v743 = v620->cache_age;
    v743[v993] = 0;
    v746 = v993;
  }
  int v1008 = (v746 * 2) + (((int)((unsigned int)(v622 + 16) >> 2)) & 1);
  int v747 = v633[v1008];
  int * v748 = v620->regs;
  v748[12] = v747;
  struct StateT * v750 = v597->b;
  int * v751 = v750->regs;
  int v752 = v751[11];
  int * v753 = v750->cache_tags;
  int v1014 = (((int)((unsigned int)((int)((unsigned int)(v752 + 16) >> 2)) >> 1)) & 1) * 2;
  int v754 = v753[v1014];
  int * v755 = v750->cache_tags;
  int v1016 = ((((int)((unsigned int)((int)((unsigned int)(v752 + 16) >> 2)) >> 1)) & 1) * 2) + 1;
  int v756 = v755[v1016];
  int * v757 = v750->cache_tags;
  int v1018 = 4 + ((((int)((unsigned int)((int)((unsigned int)(v752 + 16) >> 2)) >> 1)) & 3) * 2);
  int v758 = v757[v1018];
  int * v759 = v750->cache_tags;
  int v1020 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v752 + 16) >> 2)) >> 1)) & 3) * 2)) + 1;
  int v760 = v759[v1020];
  int v761 = v750->timer;
  int v1021 = v761 + ((100 ^ (((~(((v758 ^ ((int)((unsigned int)((int)((unsigned int)(v752 + 16) >> 2)) >> 1))) | (-(v758 ^ ((int)((unsigned int)((int)((unsigned int)(v752 + 16) >> 2)) >> 1))))) >> 31)) | (~(((v760 ^ ((int)((unsigned int)((int)((unsigned int)(v752 + 16) >> 2)) >> 1))) | (-(v760 ^ ((int)((unsigned int)((int)((unsigned int)(v752 + 16) >> 2)) >> 1))))) >> 31))) & 104)) ^ (((~(((v754 ^ ((int)((unsigned int)((int)((unsigned int)(v752 + 16) >> 2)) >> 1))) | (-(v754 ^ ((int)((unsigned int)((int)((unsigned int)(v752 + 16) >> 2)) >> 1))))) >> 31)) | (~(((v756 ^ ((int)((unsigned int)((int)((unsigned int)(v752 + 16) >> 2)) >> 1))) | (-(v756 ^ ((int)((unsigned int)((int)((unsigned int)(v752 + 16) >> 2)) >> 1))))) >> 31))) & (1 ^ (100 ^ (((~(((v758 ^ ((int)((unsigned int)((int)((unsigned int)(v752 + 16) >> 2)) >> 1))) | (-(v758 ^ ((int)((unsigned int)((int)((unsigned int)(v752 + 16) >> 2)) >> 1))))) >> 31)) | (~(((v760 ^ ((int)((unsigned int)((int)((unsigned int)(v752 + 16) >> 2)) >> 1))) | (-(v760 ^ ((int)((unsigned int)((int)((unsigned int)(v752 + 16) >> 2)) >> 1))))) >> 31))) & 104)))));
  v750->timer = v1021;
  int * v763 = v750->cache_vals;
  bool v1022 = !(((~(((v754 ^ ((int)((unsigned int)((int)((unsigned int)(v752 + 16) >> 2)) >> 1))) | (-(v754 ^ ((int)((unsigned int)((int)((unsigned int)(v752 + 16) >> 2)) >> 1))))) >> 31)) | (~(((v756 ^ ((int)((unsigned int)((int)((unsigned int)(v752 + 16) >> 2)) >> 1))) | (-(v756 ^ ((int)((unsigned int)((int)((unsigned int)(v752 + 16) >> 2)) >> 1))))) >> 31))) == 0);
  int v876;
  if (v1022) {
    int * v764 = v750->cache_age;
    int v1024 = ((((int)((unsigned int)((int)((unsigned int)(v752 + 16) >> 2)) >> 1)) & 1) * 2) + ((~(((v756 ^ ((int)((unsigned int)((int)((unsigned int)(v752 + 16) >> 2)) >> 1))) | (-(v756 ^ ((int)((unsigned int)((int)((unsigned int)(v752 + 16) >> 2)) >> 1))))) >> 31)) & 1);
    int v765 = v764[v1024];
    int * v766 = v750->cache_age;
    int v767 = v766[v1014];
    int * v768 = v750->cache_age;
    int v1027 = v767 + ((int)((unsigned int)(v767 - v765) >> 31));
    v768[v1014] = v1027;
    int * v770 = v750->cache_age;
    int v771 = v770[v1016];
    int * v772 = v750->cache_age;
    int v1030 = v771 + ((int)((unsigned int)(v771 - v765) >> 31));
    v772[v1016] = v1030;
    int * v774 = v750->cache_age;
    v774[v1024] = 0;
    v876 = v1024;
  } else {
    int * v777 = v750->cache_age;
    int v1034 = (((int)((unsigned int)((int)((unsigned int)(v752 + 16) >> 2)) >> 1)) & 1) * 2;
    int v778 = v777[v1034];
    int * v779 = v750->cache_tags;
    int v780 = v779[v1034];
    int * v781 = v750->cache_age;
    int v782 = v781[v1016];
    int * v783 = v750->cache_tags;
    int v784 = v783[v1016];
    bool v1038 = !(((~(((v758 ^ ((int)((unsigned int)((int)((unsigned int)(v752 + 16) >> 2)) >> 1))) | (-(v758 ^ ((int)((unsigned int)((int)((unsigned int)(v752 + 16) >> 2)) >> 1))))) >> 31)) | (~(((v760 ^ ((int)((unsigned int)((int)((unsigned int)(v752 + 16) >> 2)) >> 1))) | (-(v760 ^ ((int)((unsigned int)((int)((unsigned int)(v752 + 16) >> 2)) >> 1))))) >> 31))) == 0);
    int v848;
    if (v1038) {
      int * v785 = v750->cache_age;
      int v1040 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v752 + 16) >> 2)) >> 1)) & 3) * 2)) + ((~(((v760 ^ ((int)((unsigned int)((int)((unsigned int)(v752 + 16) >> 2)) >> 1))) | (-(v760 ^ ((int)((unsigned int)((int)((unsigned int)(v752 + 16) >> 2)) >> 1))))) >> 31)) & 1);
      int v786 = v785[v1040];
      int * v787 = v750->cache_age;
      int v788 = v787[v1018];
      int * v789 = v750->cache_age;
      int v1043 = v788 + ((int)((unsigned int)(v788 - v786) >> 31));
      v789[v1018] = v1043;
      int * v791 = v750->cache_age;
      int v792 = v791[v1020];
      int * v793 = v750->cache_age;
      int v1046 = v792 + ((int)((unsigned int)(v792 - v786) >> 31));
      v793[v1020] = v1046;
      int * v795 = v750->cache_age;
      v795[v1040] = 0;
      v848 = v1040;
    } else {
      int * v798 = v750->cache_age;
      int v1050 = 4 + ((((int)((unsigned int)((int)((unsigned int)(v752 + 16) >> 2)) >> 1)) & 3) * 2);
      int v799 = v798[v1050];
      int * v800 = v750->cache_tags;
      int v801 = v800[v1050];
      int * v802 = v750->cache_age;
      int v803 = v802[v1020];
      int * v804 = v750->cache_tags;
      int v805 = v804[v1020];
      int * v806 = v750->cache_dirty;
      int v1055 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v752 + 16) >> 2)) >> 1)) & 3) * 2)) + ((((v799 + ((~(((v801 ^ -1) | (-(v801 ^ -1))) >> 31)) & 2)) - (v803 + ((~(((v805 ^ -1) | (-(v805 ^ -1))) >> 31)) & 2))) >> 31) & 1);
      int v807 = v806[v1055];
      bool v1056 = !(v807 == 0);
      if (v1056) {
        int * v808 = v750->cache_tags;
        int v809 = v808[v1055];
        int * v810 = v750->cache_vals;
        int v1059 = ((4 + ((((int)((unsigned int)((int)((unsigned int)(v752 + 16) >> 2)) >> 1)) & 3) * 2)) + ((((v799 + ((~(((v801 ^ -1) | (-(v801 ^ -1))) >> 31)) & 2)) - (v803 + ((~(((v805 ^ -1) | (-(v805 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
        int v811 = v810[v1059];
        int * v812 = v750->cache_vals;
        int v1061 = (((4 + ((((int)((unsigned int)((int)((unsigned int)(v752 + 16) >> 2)) >> 1)) & 3) * 2)) + ((((v799 + ((~(((v801 ^ -1) | (-(v801 ^ -1))) >> 31)) & 2)) - (v803 + ((~(((v805 ^ -1) | (-(v805 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
        int v813 = v812[v1061];
        int * v814 = v750->mem;
        int v1063 = v809 * 2;
        v814[v1063] = v811;
        int * v816 = v750->mem;
        int v1066 = (v809 * 2) + 1;
        v816[v1066] = v813;
        ;
      } else {
        ;
      }
      int * v821 = v750->mem;
      int v1071 = ((int)((unsigned int)((int)((unsigned int)(v752 + 16) >> 2)) >> 1)) * 2;
      int v822 = v821[v1071];
      int * v823 = v750->mem;
      int v1073 = (((int)((unsigned int)((int)((unsigned int)(v752 + 16) >> 2)) >> 1)) * 2) + 1;
      int v824 = v823[v1073];
      int * v825 = v750->cache_vals;
      int v1075 = ((4 + ((((int)((unsigned int)((int)((unsigned int)(v752 + 16) >> 2)) >> 1)) & 3) * 2)) + ((((v799 + ((~(((v801 ^ -1) | (-(v801 ^ -1))) >> 31)) & 2)) - (v803 + ((~(((v805 ^ -1) | (-(v805 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
      v825[v1075] = v822;
      int * v827 = v750->cache_vals;
      int v1078 = (((4 + ((((int)((unsigned int)((int)((unsigned int)(v752 + 16) >> 2)) >> 1)) & 3) * 2)) + ((((v799 + ((~(((v801 ^ -1) | (-(v801 ^ -1))) >> 31)) & 2)) - (v803 + ((~(((v805 ^ -1) | (-(v805 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
      v827[v1078] = v824;
      int * v829 = v750->cache_tags;
      int v1081 = (int)((unsigned int)((int)((unsigned int)(v752 + 16) >> 2)) >> 1);
      v829[v1055] = v1081;
      int * v831 = v750->cache_dirty;
      v831[v1055] = 0;
      int * v833 = v750->cache_age;
      v833[v1055] = 1;
      int * v835 = v750->cache_age;
      int v836 = v835[v1055];
      int * v837 = v750->cache_age;
      int v838 = v837[v1018];
      int * v839 = v750->cache_age;
      int v1089 = v838 + ((int)((unsigned int)(v838 - v836) >> 31));
      v839[v1018] = v1089;
      int * v841 = v750->cache_age;
      int v842 = v841[v1020];
      int * v843 = v750->cache_age;
      int v1092 = v842 + ((int)((unsigned int)(v842 - v836) >> 31));
      v843[v1020] = v1092;
      int * v845 = v750->cache_age;
      v845[v1055] = 0;
      v848 = v1055;
    }
    int * v849 = v750->cache_vals;
    int v1095 = v848 * 2;
    int v850 = v849[v1095];
    int * v851 = v750->cache_vals;
    int v1097 = (v848 * 2) + 1;
    int v852 = v851[v1097];
    int * v853 = v750->cache_vals;
    int v1099 = (((((int)((unsigned int)((int)((unsigned int)(v752 + 16) >> 2)) >> 1)) & 1) * 2) + ((((v778 + ((~(((v780 ^ -1) | (-(v780 ^ -1))) >> 31)) & 2)) - (v782 + ((~(((v784 ^ -1) | (-(v784 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
    v853[v1099] = v850;
    int * v855 = v750->cache_vals;
    int v1102 = ((((((int)((unsigned int)((int)((unsigned int)(v752 + 16) >> 2)) >> 1)) & 1) * 2) + ((((v778 + ((~(((v780 ^ -1) | (-(v780 ^ -1))) >> 31)) & 2)) - (v782 + ((~(((v784 ^ -1) | (-(v784 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
    v855[v1102] = v852;
    int * v857 = v750->cache_tags;
    int v1105 = ((((int)((unsigned int)((int)((unsigned int)(v752 + 16) >> 2)) >> 1)) & 1) * 2) + ((((v778 + ((~(((v780 ^ -1) | (-(v780 ^ -1))) >> 31)) & 2)) - (v782 + ((~(((v784 ^ -1) | (-(v784 ^ -1))) >> 31)) & 2))) >> 31) & 1);
    int v1106 = (int)((unsigned int)((int)((unsigned int)(v752 + 16) >> 2)) >> 1);
    v857[v1105] = v1106;
    int * v859 = v750->cache_dirty;
    v859[v1105] = 0;
    int * v861 = v750->cache_age;
    v861[v1105] = 1;
    int * v863 = v750->cache_age;
    int v864 = v863[v1105];
    int * v865 = v750->cache_age;
    int v866 = v865[v1014];
    int * v867 = v750->cache_age;
    int v1114 = v866 + ((int)((unsigned int)(v866 - v864) >> 31));
    v867[v1014] = v1114;
    int * v869 = v750->cache_age;
    int v870 = v869[v1016];
    int * v871 = v750->cache_age;
    int v1117 = v870 + ((int)((unsigned int)(v870 - v864) >> 31));
    v871[v1016] = v1117;
    int * v873 = v750->cache_age;
    v873[v1105] = 0;
    v876 = v1105;
  }
  int v1120 = (v876 * 2) + (((int)((unsigned int)(v752 + 16) >> 2)) & 1);
  int v877 = v763[v1120];
  int * v878 = v750->regs;
  v878[12] = v877;
  struct StateT2 * v880 = slot_4(v597);
  return v880;
}

struct StateT2 * slot_0(struct StateT2 * v2) {
  struct StateT * v3 = v2->a;
  int v4 = v3->timer;
  struct StateT * v5 = v2->b;
  int v6 = v5->timer;
  bool v19 = v4 == v6;
  squared_assert(v19);
  squared_assume(v19);
  struct StateT * v9 = v2->a;
  int v10 = v9->timer;
  int v21 = v10 + 1;
  v9->timer = v21;
  struct StateT * v12 = v2->b;
  int v13 = v12->timer;
  int v23 = v13 + 1;
  v12->timer = v23;
  struct StateT2 * v15 = slot_1(v2);
  return v15;
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

void squared_assert(bool c) { koika_assert(c, "squared drift"); }
void squared_assume(bool c) { koika_assume(c); }

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
  struct StateT2 p = { .a = &s1, .b = &s2 };
  struct StateT2 *p_ = snippet(&p);
  koika_assert(p_->a->timer==p_->b->timer, "timing leak");
  return 0;
}