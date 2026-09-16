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
  int cache_tags[12];
  int cache_dirty[12];
  int cache_age[12];
  int cache_vals[24];
  int timer;
};

struct StateT * snippet(struct StateT * v0);
struct StateT * slot_1(struct StateT * v15);
struct StateT * slot_2(struct StateT * v28);
struct StateT * slot_3(struct StateT * v41);
struct StateT * slot_0(struct StateT * v2);
struct StateT * snippet(struct StateT * v0) {
  struct StateT * v1 = slot_0(v0);
  return v1;
}

struct StateT * slot_1(struct StateT * v15) {
  int v16 = v15->timer;
  int v22 = v16 + 1;
  v15->timer = v22;
  int * v18 = v15->regs;
  v18[10] = 80;
  struct StateT * v20 = slot_2(v15);
  return v20;
}

struct StateT * slot_2(struct StateT * v28) {
  int v29 = v28->timer;
  int v35 = v29 + 1;
  v28->timer = v35;
  int * v31 = v28->regs;
  v31[15] = 80;
  struct StateT * v33 = slot_3(v28);
  return v33;
}

struct StateT * slot_3(struct StateT * v41) {
  int * v42 = v41->saved_regs;
  int * v43 = v41->regs;
  int v44 = v43[5];
  v42[5] = v44;
  int v46 = v41->timer;
  int v356 = v46 + 1;
  v41->timer = v356;
  int * v48 = v41->regs;
  int v49 = v48[13];
  int * v50 = v41->regs;
  int v51 = v50[10];
  int * v52 = v41->regs;
  int v362 = v49 + v51;
  v52[5] = v362;
  int * v54 = v41->saved_regs;
  int * v55 = v41->regs;
  int v56 = v55[11];
  v54[11] = v56;
  int v58 = v41->timer;
  int v367 = v58 + 1;
  v41->timer = v367;
  int * v60 = v41->regs;
  int v61 = v60[5];
  int * v62 = v41->cache_tags;
  int v370 = (((int)((unsigned int)((int)((unsigned int)v61 >> 2)) >> 1)) & 1) * 2;
  int v63 = v62[v370];
  int * v64 = v41->cache_tags;
  int v372 = ((((int)((unsigned int)((int)((unsigned int)v61 >> 2)) >> 1)) & 1) * 2) + 1;
  int v65 = v64[v372];
  int * v66 = v41->cache_tags;
  int v374 = 4 + ((((int)((unsigned int)((int)((unsigned int)v61 >> 2)) >> 1)) & 3) * 2);
  int v67 = v66[v374];
  int * v68 = v41->cache_tags;
  int v376 = (4 + ((((int)((unsigned int)((int)((unsigned int)v61 >> 2)) >> 1)) & 3) * 2)) + 1;
  int v69 = v68[v376];
  int v70 = v41->timer;
  int v377 = v70 + ((100 ^ (((~(((v67 ^ ((int)((unsigned int)((int)((unsigned int)v61 >> 2)) >> 1))) | (-(v67 ^ ((int)((unsigned int)((int)((unsigned int)v61 >> 2)) >> 1))))) >> 31)) | (~(((v69 ^ ((int)((unsigned int)((int)((unsigned int)v61 >> 2)) >> 1))) | (-(v69 ^ ((int)((unsigned int)((int)((unsigned int)v61 >> 2)) >> 1))))) >> 31))) & 104)) ^ (((~(((v63 ^ ((int)((unsigned int)((int)((unsigned int)v61 >> 2)) >> 1))) | (-(v63 ^ ((int)((unsigned int)((int)((unsigned int)v61 >> 2)) >> 1))))) >> 31)) | (~(((v65 ^ ((int)((unsigned int)((int)((unsigned int)v61 >> 2)) >> 1))) | (-(v65 ^ ((int)((unsigned int)((int)((unsigned int)v61 >> 2)) >> 1))))) >> 31))) & (1 ^ (100 ^ (((~(((v67 ^ ((int)((unsigned int)((int)((unsigned int)v61 >> 2)) >> 1))) | (-(v67 ^ ((int)((unsigned int)((int)((unsigned int)v61 >> 2)) >> 1))))) >> 31)) | (~(((v69 ^ ((int)((unsigned int)((int)((unsigned int)v61 >> 2)) >> 1))) | (-(v69 ^ ((int)((unsigned int)((int)((unsigned int)v61 >> 2)) >> 1))))) >> 31))) & 104)))));
  v41->timer = v377;
  int * v72 = v41->cache_vals;
  bool v378 = !(((~(((v63 ^ ((int)((unsigned int)((int)((unsigned int)v61 >> 2)) >> 1))) | (-(v63 ^ ((int)((unsigned int)((int)((unsigned int)v61 >> 2)) >> 1))))) >> 31)) | (~(((v65 ^ ((int)((unsigned int)((int)((unsigned int)v61 >> 2)) >> 1))) | (-(v65 ^ ((int)((unsigned int)((int)((unsigned int)v61 >> 2)) >> 1))))) >> 31))) == 0);
  int v185;
  if (v378) {
    int * v73 = v41->cache_age;
    int v380 = ((((int)((unsigned int)((int)((unsigned int)v61 >> 2)) >> 1)) & 1) * 2) + ((~(((v65 ^ ((int)((unsigned int)((int)((unsigned int)v61 >> 2)) >> 1))) | (-(v65 ^ ((int)((unsigned int)((int)((unsigned int)v61 >> 2)) >> 1))))) >> 31)) & 1);
    int v74 = v73[v380];
    int * v75 = v41->cache_age;
    int v76 = v75[v370];
    int * v77 = v41->cache_age;
    int v383 = v76 + ((int)((unsigned int)(v76 - v74) >> 31));
    v77[v370] = v383;
    int * v79 = v41->cache_age;
    int v80 = v79[v372];
    int * v81 = v41->cache_age;
    int v386 = v80 + ((int)((unsigned int)(v80 - v74) >> 31));
    v81[v372] = v386;
    int * v83 = v41->cache_age;
    v83[v380] = 0;
    v185 = v380;
  } else {
    int * v86 = v41->cache_age;
    int v390 = (((int)((unsigned int)((int)((unsigned int)v61 >> 2)) >> 1)) & 1) * 2;
    int v87 = v86[v390];
    int * v88 = v41->cache_tags;
    int v89 = v88[v390];
    int * v90 = v41->cache_age;
    int v91 = v90[v372];
    int * v92 = v41->cache_tags;
    int v93 = v92[v372];
    bool v394 = !(((~(((v67 ^ ((int)((unsigned int)((int)((unsigned int)v61 >> 2)) >> 1))) | (-(v67 ^ ((int)((unsigned int)((int)((unsigned int)v61 >> 2)) >> 1))))) >> 31)) | (~(((v69 ^ ((int)((unsigned int)((int)((unsigned int)v61 >> 2)) >> 1))) | (-(v69 ^ ((int)((unsigned int)((int)((unsigned int)v61 >> 2)) >> 1))))) >> 31))) == 0);
    int v157;
    if (v394) {
      int * v94 = v41->cache_age;
      int v396 = (4 + ((((int)((unsigned int)((int)((unsigned int)v61 >> 2)) >> 1)) & 3) * 2)) + ((~(((v69 ^ ((int)((unsigned int)((int)((unsigned int)v61 >> 2)) >> 1))) | (-(v69 ^ ((int)((unsigned int)((int)((unsigned int)v61 >> 2)) >> 1))))) >> 31)) & 1);
      int v95 = v94[v396];
      int * v96 = v41->cache_age;
      int v97 = v96[v374];
      int * v98 = v41->cache_age;
      int v399 = v97 + ((int)((unsigned int)(v97 - v95) >> 31));
      v98[v374] = v399;
      int * v100 = v41->cache_age;
      int v101 = v100[v376];
      int * v102 = v41->cache_age;
      int v402 = v101 + ((int)((unsigned int)(v101 - v95) >> 31));
      v102[v376] = v402;
      int * v104 = v41->cache_age;
      v104[v396] = 0;
      v157 = v396;
    } else {
      int * v107 = v41->cache_age;
      int v406 = 4 + ((((int)((unsigned int)((int)((unsigned int)v61 >> 2)) >> 1)) & 3) * 2);
      int v108 = v107[v406];
      int * v109 = v41->cache_tags;
      int v110 = v109[v406];
      int * v111 = v41->cache_age;
      int v112 = v111[v376];
      int * v113 = v41->cache_tags;
      int v114 = v113[v376];
      int * v115 = v41->cache_dirty;
      int v411 = (4 + ((((int)((unsigned int)((int)((unsigned int)v61 >> 2)) >> 1)) & 3) * 2)) + ((((v108 + ((~(((v110 ^ -1) | (-(v110 ^ -1))) >> 31)) & 2)) - (v112 + ((~(((v114 ^ -1) | (-(v114 ^ -1))) >> 31)) & 2))) >> 31) & 1);
      int v116 = v115[v411];
      bool v412 = !(v116 == 0);
      if (v412) {
        int * v117 = v41->cache_tags;
        int v118 = v117[v411];
        int * v119 = v41->cache_vals;
        int v415 = ((4 + ((((int)((unsigned int)((int)((unsigned int)v61 >> 2)) >> 1)) & 3) * 2)) + ((((v108 + ((~(((v110 ^ -1) | (-(v110 ^ -1))) >> 31)) & 2)) - (v112 + ((~(((v114 ^ -1) | (-(v114 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
        int v120 = v119[v415];
        int * v121 = v41->cache_vals;
        int v417 = (((4 + ((((int)((unsigned int)((int)((unsigned int)v61 >> 2)) >> 1)) & 3) * 2)) + ((((v108 + ((~(((v110 ^ -1) | (-(v110 ^ -1))) >> 31)) & 2)) - (v112 + ((~(((v114 ^ -1) | (-(v114 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
        int v122 = v121[v417];
        int * v123 = v41->mem;
        int v419 = v118 * 2;
        v123[v419] = v120;
        int * v125 = v41->mem;
        int v422 = (v118 * 2) + 1;
        v125[v422] = v122;
        ;
      } else {
        ;
      }
      int * v130 = v41->mem;
      int v427 = ((int)((unsigned int)((int)((unsigned int)v61 >> 2)) >> 1)) * 2;
      int v131 = v130[v427];
      int * v132 = v41->mem;
      int v429 = (((int)((unsigned int)((int)((unsigned int)v61 >> 2)) >> 1)) * 2) + 1;
      int v133 = v132[v429];
      int * v134 = v41->cache_vals;
      int v431 = ((4 + ((((int)((unsigned int)((int)((unsigned int)v61 >> 2)) >> 1)) & 3) * 2)) + ((((v108 + ((~(((v110 ^ -1) | (-(v110 ^ -1))) >> 31)) & 2)) - (v112 + ((~(((v114 ^ -1) | (-(v114 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
      v134[v431] = v131;
      int * v136 = v41->cache_vals;
      int v434 = (((4 + ((((int)((unsigned int)((int)((unsigned int)v61 >> 2)) >> 1)) & 3) * 2)) + ((((v108 + ((~(((v110 ^ -1) | (-(v110 ^ -1))) >> 31)) & 2)) - (v112 + ((~(((v114 ^ -1) | (-(v114 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
      v136[v434] = v133;
      int * v138 = v41->cache_tags;
      int v437 = (int)((unsigned int)((int)((unsigned int)v61 >> 2)) >> 1);
      v138[v411] = v437;
      int * v140 = v41->cache_dirty;
      v140[v411] = 0;
      int * v142 = v41->cache_age;
      v142[v411] = 1;
      int * v144 = v41->cache_age;
      int v145 = v144[v411];
      int * v146 = v41->cache_age;
      int v147 = v146[v374];
      int * v148 = v41->cache_age;
      int v445 = v147 + ((int)((unsigned int)(v147 - v145) >> 31));
      v148[v374] = v445;
      int * v150 = v41->cache_age;
      int v151 = v150[v376];
      int * v152 = v41->cache_age;
      int v448 = v151 + ((int)((unsigned int)(v151 - v145) >> 31));
      v152[v376] = v448;
      int * v154 = v41->cache_age;
      v154[v411] = 0;
      v157 = v411;
    }
    int * v158 = v41->cache_vals;
    int v451 = v157 * 2;
    int v159 = v158[v451];
    int * v160 = v41->cache_vals;
    int v453 = (v157 * 2) + 1;
    int v161 = v160[v453];
    int * v162 = v41->cache_vals;
    int v455 = (((((int)((unsigned int)((int)((unsigned int)v61 >> 2)) >> 1)) & 1) * 2) + ((((v87 + ((~(((v89 ^ -1) | (-(v89 ^ -1))) >> 31)) & 2)) - (v91 + ((~(((v93 ^ -1) | (-(v93 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
    v162[v455] = v159;
    int * v164 = v41->cache_vals;
    int v458 = ((((((int)((unsigned int)((int)((unsigned int)v61 >> 2)) >> 1)) & 1) * 2) + ((((v87 + ((~(((v89 ^ -1) | (-(v89 ^ -1))) >> 31)) & 2)) - (v91 + ((~(((v93 ^ -1) | (-(v93 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
    v164[v458] = v161;
    int * v166 = v41->cache_tags;
    int v461 = ((((int)((unsigned int)((int)((unsigned int)v61 >> 2)) >> 1)) & 1) * 2) + ((((v87 + ((~(((v89 ^ -1) | (-(v89 ^ -1))) >> 31)) & 2)) - (v91 + ((~(((v93 ^ -1) | (-(v93 ^ -1))) >> 31)) & 2))) >> 31) & 1);
    int v462 = (int)((unsigned int)((int)((unsigned int)v61 >> 2)) >> 1);
    v166[v461] = v462;
    int * v168 = v41->cache_dirty;
    v168[v461] = 0;
    int * v170 = v41->cache_age;
    v170[v461] = 1;
    int * v172 = v41->cache_age;
    int v173 = v172[v461];
    int * v174 = v41->cache_age;
    int v175 = v174[v370];
    int * v176 = v41->cache_age;
    int v470 = v175 + ((int)((unsigned int)(v175 - v173) >> 31));
    v176[v370] = v470;
    int * v178 = v41->cache_age;
    int v179 = v178[v372];
    int * v180 = v41->cache_age;
    int v473 = v179 + ((int)((unsigned int)(v179 - v173) >> 31));
    v180[v372] = v473;
    int * v182 = v41->cache_age;
    v182[v461] = 0;
    v185 = v461;
  }
  int v476 = (v185 * 2) + (((int)((unsigned int)v61 >> 2)) & 1);
  int v186 = v72[v476];
  int * v187 = v41->regs;
  v187[11] = v186;
  int v189 = v41->timer;
  int v479 = v189 + 1;
  v41->timer = v479;
  int * v191 = v41->regs;
  int v192 = v191[11];
  int * v193 = v41->regs;
  int v482 = v192 << 2;
  v193[11] = v482;
  int * v195 = v41->saved_regs;
  int * v196 = v41->regs;
  int v197 = v196[12];
  v195[12] = v197;
  int v199 = v41->timer;
  int v487 = v199 + 1;
  v41->timer = v487;
  int * v201 = v41->regs;
  int v202 = v201[11];
  int * v203 = v41->cache_tags;
  int v490 = (((int)((unsigned int)((int)((unsigned int)v202 >> 2)) >> 1)) & 1) * 2;
  int v204 = v203[v490];
  int * v205 = v41->cache_tags;
  int v492 = ((((int)((unsigned int)((int)((unsigned int)v202 >> 2)) >> 1)) & 1) * 2) + 1;
  int v206 = v205[v492];
  int * v207 = v41->cache_tags;
  int v494 = 4 + ((((int)((unsigned int)((int)((unsigned int)v202 >> 2)) >> 1)) & 3) * 2);
  int v208 = v207[v494];
  int * v209 = v41->cache_tags;
  int v496 = (4 + ((((int)((unsigned int)((int)((unsigned int)v202 >> 2)) >> 1)) & 3) * 2)) + 1;
  int v210 = v209[v496];
  int v211 = v41->timer;
  int v497 = v211 + ((100 ^ (((~(((v208 ^ ((int)((unsigned int)((int)((unsigned int)v202 >> 2)) >> 1))) | (-(v208 ^ ((int)((unsigned int)((int)((unsigned int)v202 >> 2)) >> 1))))) >> 31)) | (~(((v210 ^ ((int)((unsigned int)((int)((unsigned int)v202 >> 2)) >> 1))) | (-(v210 ^ ((int)((unsigned int)((int)((unsigned int)v202 >> 2)) >> 1))))) >> 31))) & 104)) ^ (((~(((v204 ^ ((int)((unsigned int)((int)((unsigned int)v202 >> 2)) >> 1))) | (-(v204 ^ ((int)((unsigned int)((int)((unsigned int)v202 >> 2)) >> 1))))) >> 31)) | (~(((v206 ^ ((int)((unsigned int)((int)((unsigned int)v202 >> 2)) >> 1))) | (-(v206 ^ ((int)((unsigned int)((int)((unsigned int)v202 >> 2)) >> 1))))) >> 31))) & (1 ^ (100 ^ (((~(((v208 ^ ((int)((unsigned int)((int)((unsigned int)v202 >> 2)) >> 1))) | (-(v208 ^ ((int)((unsigned int)((int)((unsigned int)v202 >> 2)) >> 1))))) >> 31)) | (~(((v210 ^ ((int)((unsigned int)((int)((unsigned int)v202 >> 2)) >> 1))) | (-(v210 ^ ((int)((unsigned int)((int)((unsigned int)v202 >> 2)) >> 1))))) >> 31))) & 104)))));
  v41->timer = v497;
  int * v213 = v41->cache_vals;
  bool v498 = !(((~(((v204 ^ ((int)((unsigned int)((int)((unsigned int)v202 >> 2)) >> 1))) | (-(v204 ^ ((int)((unsigned int)((int)((unsigned int)v202 >> 2)) >> 1))))) >> 31)) | (~(((v206 ^ ((int)((unsigned int)((int)((unsigned int)v202 >> 2)) >> 1))) | (-(v206 ^ ((int)((unsigned int)((int)((unsigned int)v202 >> 2)) >> 1))))) >> 31))) == 0);
  int v326;
  if (v498) {
    int * v214 = v41->cache_age;
    int v500 = ((((int)((unsigned int)((int)((unsigned int)v202 >> 2)) >> 1)) & 1) * 2) + ((~(((v206 ^ ((int)((unsigned int)((int)((unsigned int)v202 >> 2)) >> 1))) | (-(v206 ^ ((int)((unsigned int)((int)((unsigned int)v202 >> 2)) >> 1))))) >> 31)) & 1);
    int v215 = v214[v500];
    int * v216 = v41->cache_age;
    int v217 = v216[v490];
    int * v218 = v41->cache_age;
    int v503 = v217 + ((int)((unsigned int)(v217 - v215) >> 31));
    v218[v490] = v503;
    int * v220 = v41->cache_age;
    int v221 = v220[v492];
    int * v222 = v41->cache_age;
    int v506 = v221 + ((int)((unsigned int)(v221 - v215) >> 31));
    v222[v492] = v506;
    int * v224 = v41->cache_age;
    v224[v500] = 0;
    v326 = v500;
  } else {
    int * v227 = v41->cache_age;
    int v510 = (((int)((unsigned int)((int)((unsigned int)v202 >> 2)) >> 1)) & 1) * 2;
    int v228 = v227[v510];
    int * v229 = v41->cache_tags;
    int v230 = v229[v510];
    int * v231 = v41->cache_age;
    int v232 = v231[v492];
    int * v233 = v41->cache_tags;
    int v234 = v233[v492];
    bool v514 = !(((~(((v208 ^ ((int)((unsigned int)((int)((unsigned int)v202 >> 2)) >> 1))) | (-(v208 ^ ((int)((unsigned int)((int)((unsigned int)v202 >> 2)) >> 1))))) >> 31)) | (~(((v210 ^ ((int)((unsigned int)((int)((unsigned int)v202 >> 2)) >> 1))) | (-(v210 ^ ((int)((unsigned int)((int)((unsigned int)v202 >> 2)) >> 1))))) >> 31))) == 0);
    int v298;
    if (v514) {
      int * v235 = v41->cache_age;
      int v516 = (4 + ((((int)((unsigned int)((int)((unsigned int)v202 >> 2)) >> 1)) & 3) * 2)) + ((~(((v210 ^ ((int)((unsigned int)((int)((unsigned int)v202 >> 2)) >> 1))) | (-(v210 ^ ((int)((unsigned int)((int)((unsigned int)v202 >> 2)) >> 1))))) >> 31)) & 1);
      int v236 = v235[v516];
      int * v237 = v41->cache_age;
      int v238 = v237[v494];
      int * v239 = v41->cache_age;
      int v519 = v238 + ((int)((unsigned int)(v238 - v236) >> 31));
      v239[v494] = v519;
      int * v241 = v41->cache_age;
      int v242 = v241[v496];
      int * v243 = v41->cache_age;
      int v522 = v242 + ((int)((unsigned int)(v242 - v236) >> 31));
      v243[v496] = v522;
      int * v245 = v41->cache_age;
      v245[v516] = 0;
      v298 = v516;
    } else {
      int * v248 = v41->cache_age;
      int v526 = 4 + ((((int)((unsigned int)((int)((unsigned int)v202 >> 2)) >> 1)) & 3) * 2);
      int v249 = v248[v526];
      int * v250 = v41->cache_tags;
      int v251 = v250[v526];
      int * v252 = v41->cache_age;
      int v253 = v252[v496];
      int * v254 = v41->cache_tags;
      int v255 = v254[v496];
      int * v256 = v41->cache_dirty;
      int v531 = (4 + ((((int)((unsigned int)((int)((unsigned int)v202 >> 2)) >> 1)) & 3) * 2)) + ((((v249 + ((~(((v251 ^ -1) | (-(v251 ^ -1))) >> 31)) & 2)) - (v253 + ((~(((v255 ^ -1) | (-(v255 ^ -1))) >> 31)) & 2))) >> 31) & 1);
      int v257 = v256[v531];
      bool v532 = !(v257 == 0);
      if (v532) {
        int * v258 = v41->cache_tags;
        int v259 = v258[v531];
        int * v260 = v41->cache_vals;
        int v535 = ((4 + ((((int)((unsigned int)((int)((unsigned int)v202 >> 2)) >> 1)) & 3) * 2)) + ((((v249 + ((~(((v251 ^ -1) | (-(v251 ^ -1))) >> 31)) & 2)) - (v253 + ((~(((v255 ^ -1) | (-(v255 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
        int v261 = v260[v535];
        int * v262 = v41->cache_vals;
        int v537 = (((4 + ((((int)((unsigned int)((int)((unsigned int)v202 >> 2)) >> 1)) & 3) * 2)) + ((((v249 + ((~(((v251 ^ -1) | (-(v251 ^ -1))) >> 31)) & 2)) - (v253 + ((~(((v255 ^ -1) | (-(v255 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
        int v263 = v262[v537];
        int * v264 = v41->mem;
        int v539 = v259 * 2;
        v264[v539] = v261;
        int * v266 = v41->mem;
        int v542 = (v259 * 2) + 1;
        v266[v542] = v263;
        ;
      } else {
        ;
      }
      int * v271 = v41->mem;
      int v547 = ((int)((unsigned int)((int)((unsigned int)v202 >> 2)) >> 1)) * 2;
      int v272 = v271[v547];
      int * v273 = v41->mem;
      int v549 = (((int)((unsigned int)((int)((unsigned int)v202 >> 2)) >> 1)) * 2) + 1;
      int v274 = v273[v549];
      int * v275 = v41->cache_vals;
      int v551 = ((4 + ((((int)((unsigned int)((int)((unsigned int)v202 >> 2)) >> 1)) & 3) * 2)) + ((((v249 + ((~(((v251 ^ -1) | (-(v251 ^ -1))) >> 31)) & 2)) - (v253 + ((~(((v255 ^ -1) | (-(v255 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
      v275[v551] = v272;
      int * v277 = v41->cache_vals;
      int v554 = (((4 + ((((int)((unsigned int)((int)((unsigned int)v202 >> 2)) >> 1)) & 3) * 2)) + ((((v249 + ((~(((v251 ^ -1) | (-(v251 ^ -1))) >> 31)) & 2)) - (v253 + ((~(((v255 ^ -1) | (-(v255 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
      v277[v554] = v274;
      int * v279 = v41->cache_tags;
      int v557 = (int)((unsigned int)((int)((unsigned int)v202 >> 2)) >> 1);
      v279[v531] = v557;
      int * v281 = v41->cache_dirty;
      v281[v531] = 0;
      int * v283 = v41->cache_age;
      v283[v531] = 1;
      int * v285 = v41->cache_age;
      int v286 = v285[v531];
      int * v287 = v41->cache_age;
      int v288 = v287[v494];
      int * v289 = v41->cache_age;
      int v565 = v288 + ((int)((unsigned int)(v288 - v286) >> 31));
      v289[v494] = v565;
      int * v291 = v41->cache_age;
      int v292 = v291[v496];
      int * v293 = v41->cache_age;
      int v568 = v292 + ((int)((unsigned int)(v292 - v286) >> 31));
      v293[v496] = v568;
      int * v295 = v41->cache_age;
      v295[v531] = 0;
      v298 = v531;
    }
    int * v299 = v41->cache_vals;
    int v571 = v298 * 2;
    int v300 = v299[v571];
    int * v301 = v41->cache_vals;
    int v573 = (v298 * 2) + 1;
    int v302 = v301[v573];
    int * v303 = v41->cache_vals;
    int v575 = (((((int)((unsigned int)((int)((unsigned int)v202 >> 2)) >> 1)) & 1) * 2) + ((((v228 + ((~(((v230 ^ -1) | (-(v230 ^ -1))) >> 31)) & 2)) - (v232 + ((~(((v234 ^ -1) | (-(v234 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
    v303[v575] = v300;
    int * v305 = v41->cache_vals;
    int v578 = ((((((int)((unsigned int)((int)((unsigned int)v202 >> 2)) >> 1)) & 1) * 2) + ((((v228 + ((~(((v230 ^ -1) | (-(v230 ^ -1))) >> 31)) & 2)) - (v232 + ((~(((v234 ^ -1) | (-(v234 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
    v305[v578] = v302;
    int * v307 = v41->cache_tags;
    int v581 = ((((int)((unsigned int)((int)((unsigned int)v202 >> 2)) >> 1)) & 1) * 2) + ((((v228 + ((~(((v230 ^ -1) | (-(v230 ^ -1))) >> 31)) & 2)) - (v232 + ((~(((v234 ^ -1) | (-(v234 ^ -1))) >> 31)) & 2))) >> 31) & 1);
    int v582 = (int)((unsigned int)((int)((unsigned int)v202 >> 2)) >> 1);
    v307[v581] = v582;
    int * v309 = v41->cache_dirty;
    v309[v581] = 0;
    int * v311 = v41->cache_age;
    v311[v581] = 1;
    int * v313 = v41->cache_age;
    int v314 = v313[v581];
    int * v315 = v41->cache_age;
    int v316 = v315[v490];
    int * v317 = v41->cache_age;
    int v590 = v316 + ((int)((unsigned int)(v316 - v314) >> 31));
    v317[v490] = v590;
    int * v319 = v41->cache_age;
    int v320 = v319[v492];
    int * v321 = v41->cache_age;
    int v593 = v320 + ((int)((unsigned int)(v320 - v314) >> 31));
    v321[v492] = v593;
    int * v323 = v41->cache_age;
    v323[v581] = 0;
    v326 = v581;
  }
  int v596 = (v326 * 2) + (((int)((unsigned int)v202 >> 2)) & 1);
  int v327 = v213[v596];
  int * v328 = v41->regs;
  v328[12] = v327;
  int * v330 = v41->regs;
  int v331 = v330[10];
  int * v332 = v41->regs;
  int v333 = v332[15];
  bool v602 = v331 >= v333;
  if (v602) {
    int v334 = v41->timer;
    int v603 = v334 + 15;
    v41->timer = v603;
    int * v336 = v41->saved_regs;
    int v337 = v336[5];
    int * v338 = v41->regs;
    v338[5] = v337;
    int * v340 = v41->saved_regs;
    int v341 = v340[11];
    int * v342 = v41->regs;
    v342[11] = v341;
    int * v344 = v41->saved_regs;
    int v345 = v344[12];
    int * v346 = v41->regs;
    v346[12] = v345;
    ;
  } else {
    ;
  }
  return v41;
}

struct StateT * slot_0(struct StateT * v2) {
  int v3 = v2->timer;
  int v9 = v3 + 1;
  v2->timer = v9;
  int * v5 = v2->regs;
  v5[13] = 0;
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