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

struct StateT * slot_12(struct StateT * v679);
struct StateT * slot_14(struct StateT * v669);
struct StateT * slot_2(struct StateT * v28);
struct StateT * slot_3(struct StateT * v41);
struct StateT * snippet(struct StateT * v0);
struct StateT * slot_10(struct StateT * v692);
struct StateT * slot_1(struct StateT * v15);
struct StateT * slot_4(struct StateT * v54);
struct StateT * slot_13(struct StateT * v708);
struct StateT * slot_11(struct StateT * v713);
struct StateT * slot_0(struct StateT * v2);
struct StateT * slot_12(struct StateT * v679) {
  int v680 = v679->timer;
  int v686 = v680 + 1;
  v679->timer = v686;
  int * v682 = v679->regs;
  v682[10] = 0;
  struct StateT * v684 = slot_13(v679);
  return v684;
}

struct StateT * slot_14(struct StateT * v669) {
  int v670 = v669->timer;
  int v675 = v670 + 1;
  v669->timer = v675;
  int * v672 = v669->regs;
  v672[10] = 1;
  return v669;
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

struct StateT * slot_10(struct StateT * v692) {
  int v693 = v692->timer;
  int v701 = v693 + 1;
  v692->timer = v701;
  int * v695 = v692->regs;
  int v696 = v695[14];
  int * v697 = v692->regs;
  int v705 = v696 + 4;
  v697[14] = v705;
  struct StateT * v699 = slot_11(v692);
  return v699;
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

struct StateT * slot_4(struct StateT * v54) {
  int * v55 = v54->saved_regs;
  int * v56 = v54->regs;
  int v57 = v56[5];
  v55[5] = v57;
  int v59 = v54->timer;
  int v391 = v59 + 1;
  v54->timer = v391;
  int * v61 = v54->regs;
  int v62 = v61[12];
  int * v63 = v54->regs;
  int v64 = v63[14];
  int * v65 = v54->regs;
  int v397 = v62 + v64;
  v65[5] = v397;
  int * v67 = v54->saved_regs;
  int * v68 = v54->regs;
  int v69 = v68[10];
  v67[10] = v69;
  int v71 = v54->timer;
  int v402 = v71 + 1;
  v54->timer = v402;
  int * v73 = v54->regs;
  int v74 = v73[5];
  int * v75 = v54->cache_tags;
  int v405 = (((int)((unsigned int)((int)((unsigned int)v74 >> 2)) >> 1)) & 1) * 2;
  int v76 = v75[v405];
  int * v77 = v54->cache_tags;
  int v407 = ((((int)((unsigned int)((int)((unsigned int)v74 >> 2)) >> 1)) & 1) * 2) + 1;
  int v78 = v77[v407];
  int * v79 = v54->cache_tags;
  int v409 = 4 + ((((int)((unsigned int)((int)((unsigned int)v74 >> 2)) >> 1)) & 3) * 2);
  int v80 = v79[v409];
  int * v81 = v54->cache_tags;
  int v411 = (4 + ((((int)((unsigned int)((int)((unsigned int)v74 >> 2)) >> 1)) & 3) * 2)) + 1;
  int v82 = v81[v411];
  int v83 = v54->timer;
  int v412 = v83 + ((100 ^ (((~(((v80 ^ ((int)((unsigned int)((int)((unsigned int)v74 >> 2)) >> 1))) | (-(v80 ^ ((int)((unsigned int)((int)((unsigned int)v74 >> 2)) >> 1))))) >> 31)) | (~(((v82 ^ ((int)((unsigned int)((int)((unsigned int)v74 >> 2)) >> 1))) | (-(v82 ^ ((int)((unsigned int)((int)((unsigned int)v74 >> 2)) >> 1))))) >> 31))) & 104)) ^ (((~(((v76 ^ ((int)((unsigned int)((int)((unsigned int)v74 >> 2)) >> 1))) | (-(v76 ^ ((int)((unsigned int)((int)((unsigned int)v74 >> 2)) >> 1))))) >> 31)) | (~(((v78 ^ ((int)((unsigned int)((int)((unsigned int)v74 >> 2)) >> 1))) | (-(v78 ^ ((int)((unsigned int)((int)((unsigned int)v74 >> 2)) >> 1))))) >> 31))) & (1 ^ (100 ^ (((~(((v80 ^ ((int)((unsigned int)((int)((unsigned int)v74 >> 2)) >> 1))) | (-(v80 ^ ((int)((unsigned int)((int)((unsigned int)v74 >> 2)) >> 1))))) >> 31)) | (~(((v82 ^ ((int)((unsigned int)((int)((unsigned int)v74 >> 2)) >> 1))) | (-(v82 ^ ((int)((unsigned int)((int)((unsigned int)v74 >> 2)) >> 1))))) >> 31))) & 104)))));
  v54->timer = v412;
  int * v85 = v54->cache_vals;
  bool v413 = !(((~(((v76 ^ ((int)((unsigned int)((int)((unsigned int)v74 >> 2)) >> 1))) | (-(v76 ^ ((int)((unsigned int)((int)((unsigned int)v74 >> 2)) >> 1))))) >> 31)) | (~(((v78 ^ ((int)((unsigned int)((int)((unsigned int)v74 >> 2)) >> 1))) | (-(v78 ^ ((int)((unsigned int)((int)((unsigned int)v74 >> 2)) >> 1))))) >> 31))) == 0);
  int v198;
  if (v413) {
    int * v86 = v54->cache_age;
    int v415 = ((((int)((unsigned int)((int)((unsigned int)v74 >> 2)) >> 1)) & 1) * 2) + ((~(((v78 ^ ((int)((unsigned int)((int)((unsigned int)v74 >> 2)) >> 1))) | (-(v78 ^ ((int)((unsigned int)((int)((unsigned int)v74 >> 2)) >> 1))))) >> 31)) & 1);
    int v87 = v86[v415];
    int * v88 = v54->cache_age;
    int v89 = v88[v405];
    int * v90 = v54->cache_age;
    int v418 = v89 + ((int)((unsigned int)(v89 - v87) >> 31));
    v90[v405] = v418;
    int * v92 = v54->cache_age;
    int v93 = v92[v407];
    int * v94 = v54->cache_age;
    int v421 = v93 + ((int)((unsigned int)(v93 - v87) >> 31));
    v94[v407] = v421;
    int * v96 = v54->cache_age;
    v96[v415] = 0;
    v198 = v415;
  } else {
    int * v99 = v54->cache_age;
    int v425 = (((int)((unsigned int)((int)((unsigned int)v74 >> 2)) >> 1)) & 1) * 2;
    int v100 = v99[v425];
    int * v101 = v54->cache_tags;
    int v102 = v101[v425];
    int * v103 = v54->cache_age;
    int v104 = v103[v407];
    int * v105 = v54->cache_tags;
    int v106 = v105[v407];
    bool v429 = !(((~(((v80 ^ ((int)((unsigned int)((int)((unsigned int)v74 >> 2)) >> 1))) | (-(v80 ^ ((int)((unsigned int)((int)((unsigned int)v74 >> 2)) >> 1))))) >> 31)) | (~(((v82 ^ ((int)((unsigned int)((int)((unsigned int)v74 >> 2)) >> 1))) | (-(v82 ^ ((int)((unsigned int)((int)((unsigned int)v74 >> 2)) >> 1))))) >> 31))) == 0);
    int v170;
    if (v429) {
      int * v107 = v54->cache_age;
      int v431 = (4 + ((((int)((unsigned int)((int)((unsigned int)v74 >> 2)) >> 1)) & 3) * 2)) + ((~(((v82 ^ ((int)((unsigned int)((int)((unsigned int)v74 >> 2)) >> 1))) | (-(v82 ^ ((int)((unsigned int)((int)((unsigned int)v74 >> 2)) >> 1))))) >> 31)) & 1);
      int v108 = v107[v431];
      int * v109 = v54->cache_age;
      int v110 = v109[v409];
      int * v111 = v54->cache_age;
      int v434 = v110 + ((int)((unsigned int)(v110 - v108) >> 31));
      v111[v409] = v434;
      int * v113 = v54->cache_age;
      int v114 = v113[v411];
      int * v115 = v54->cache_age;
      int v437 = v114 + ((int)((unsigned int)(v114 - v108) >> 31));
      v115[v411] = v437;
      int * v117 = v54->cache_age;
      v117[v431] = 0;
      v170 = v431;
    } else {
      int * v120 = v54->cache_age;
      int v441 = 4 + ((((int)((unsigned int)((int)((unsigned int)v74 >> 2)) >> 1)) & 3) * 2);
      int v121 = v120[v441];
      int * v122 = v54->cache_tags;
      int v123 = v122[v441];
      int * v124 = v54->cache_age;
      int v125 = v124[v411];
      int * v126 = v54->cache_tags;
      int v127 = v126[v411];
      int * v128 = v54->cache_dirty;
      int v446 = (4 + ((((int)((unsigned int)((int)((unsigned int)v74 >> 2)) >> 1)) & 3) * 2)) + ((((v121 + ((~(((v123 ^ -1) | (-(v123 ^ -1))) >> 31)) & 2)) - (v125 + ((~(((v127 ^ -1) | (-(v127 ^ -1))) >> 31)) & 2))) >> 31) & 1);
      int v129 = v128[v446];
      bool v447 = !(v129 == 0);
      if (v447) {
        int * v130 = v54->cache_tags;
        int v131 = v130[v446];
        int * v132 = v54->cache_vals;
        int v450 = ((4 + ((((int)((unsigned int)((int)((unsigned int)v74 >> 2)) >> 1)) & 3) * 2)) + ((((v121 + ((~(((v123 ^ -1) | (-(v123 ^ -1))) >> 31)) & 2)) - (v125 + ((~(((v127 ^ -1) | (-(v127 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
        int v133 = v132[v450];
        int * v134 = v54->cache_vals;
        int v452 = (((4 + ((((int)((unsigned int)((int)((unsigned int)v74 >> 2)) >> 1)) & 3) * 2)) + ((((v121 + ((~(((v123 ^ -1) | (-(v123 ^ -1))) >> 31)) & 2)) - (v125 + ((~(((v127 ^ -1) | (-(v127 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
        int v135 = v134[v452];
        int * v136 = v54->mem;
        int v454 = v131 * 2;
        v136[v454] = v133;
        int * v138 = v54->mem;
        int v457 = (v131 * 2) + 1;
        v138[v457] = v135;
        ;
      } else {
        ;
      }
      int * v143 = v54->mem;
      int v462 = ((int)((unsigned int)((int)((unsigned int)v74 >> 2)) >> 1)) * 2;
      int v144 = v143[v462];
      int * v145 = v54->mem;
      int v464 = (((int)((unsigned int)((int)((unsigned int)v74 >> 2)) >> 1)) * 2) + 1;
      int v146 = v145[v464];
      int * v147 = v54->cache_vals;
      int v466 = ((4 + ((((int)((unsigned int)((int)((unsigned int)v74 >> 2)) >> 1)) & 3) * 2)) + ((((v121 + ((~(((v123 ^ -1) | (-(v123 ^ -1))) >> 31)) & 2)) - (v125 + ((~(((v127 ^ -1) | (-(v127 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
      v147[v466] = v144;
      int * v149 = v54->cache_vals;
      int v469 = (((4 + ((((int)((unsigned int)((int)((unsigned int)v74 >> 2)) >> 1)) & 3) * 2)) + ((((v121 + ((~(((v123 ^ -1) | (-(v123 ^ -1))) >> 31)) & 2)) - (v125 + ((~(((v127 ^ -1) | (-(v127 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
      v149[v469] = v146;
      int * v151 = v54->cache_tags;
      int v472 = (int)((unsigned int)((int)((unsigned int)v74 >> 2)) >> 1);
      v151[v446] = v472;
      int * v153 = v54->cache_dirty;
      v153[v446] = 0;
      int * v155 = v54->cache_age;
      v155[v446] = 1;
      int * v157 = v54->cache_age;
      int v158 = v157[v446];
      int * v159 = v54->cache_age;
      int v160 = v159[v409];
      int * v161 = v54->cache_age;
      int v480 = v160 + ((int)((unsigned int)(v160 - v158) >> 31));
      v161[v409] = v480;
      int * v163 = v54->cache_age;
      int v164 = v163[v411];
      int * v165 = v54->cache_age;
      int v483 = v164 + ((int)((unsigned int)(v164 - v158) >> 31));
      v165[v411] = v483;
      int * v167 = v54->cache_age;
      v167[v446] = 0;
      v170 = v446;
    }
    int * v171 = v54->cache_vals;
    int v486 = v170 * 2;
    int v172 = v171[v486];
    int * v173 = v54->cache_vals;
    int v488 = (v170 * 2) + 1;
    int v174 = v173[v488];
    int * v175 = v54->cache_vals;
    int v490 = (((((int)((unsigned int)((int)((unsigned int)v74 >> 2)) >> 1)) & 1) * 2) + ((((v100 + ((~(((v102 ^ -1) | (-(v102 ^ -1))) >> 31)) & 2)) - (v104 + ((~(((v106 ^ -1) | (-(v106 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
    v175[v490] = v172;
    int * v177 = v54->cache_vals;
    int v493 = ((((((int)((unsigned int)((int)((unsigned int)v74 >> 2)) >> 1)) & 1) * 2) + ((((v100 + ((~(((v102 ^ -1) | (-(v102 ^ -1))) >> 31)) & 2)) - (v104 + ((~(((v106 ^ -1) | (-(v106 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
    v177[v493] = v174;
    int * v179 = v54->cache_tags;
    int v496 = ((((int)((unsigned int)((int)((unsigned int)v74 >> 2)) >> 1)) & 1) * 2) + ((((v100 + ((~(((v102 ^ -1) | (-(v102 ^ -1))) >> 31)) & 2)) - (v104 + ((~(((v106 ^ -1) | (-(v106 ^ -1))) >> 31)) & 2))) >> 31) & 1);
    int v497 = (int)((unsigned int)((int)((unsigned int)v74 >> 2)) >> 1);
    v179[v496] = v497;
    int * v181 = v54->cache_dirty;
    v181[v496] = 0;
    int * v183 = v54->cache_age;
    v183[v496] = 1;
    int * v185 = v54->cache_age;
    int v186 = v185[v496];
    int * v187 = v54->cache_age;
    int v188 = v187[v405];
    int * v189 = v54->cache_age;
    int v505 = v188 + ((int)((unsigned int)(v188 - v186) >> 31));
    v189[v405] = v505;
    int * v191 = v54->cache_age;
    int v192 = v191[v407];
    int * v193 = v54->cache_age;
    int v508 = v192 + ((int)((unsigned int)(v192 - v186) >> 31));
    v193[v407] = v508;
    int * v195 = v54->cache_age;
    v195[v496] = 0;
    v198 = v496;
  }
  int v511 = (v198 * 2) + (((int)((unsigned int)v74 >> 2)) & 1);
  int v199 = v85[v511];
  int * v200 = v54->regs;
  v200[10] = v199;
  int * v202 = v54->saved_regs;
  int * v203 = v54->regs;
  int v204 = v203[6];
  v202[6] = v204;
  int v206 = v54->timer;
  int v518 = v206 + 1;
  v54->timer = v518;
  int * v208 = v54->regs;
  int v209 = v208[13];
  int * v210 = v54->regs;
  int v211 = v210[14];
  int * v212 = v54->regs;
  int v523 = v209 + v211;
  v212[6] = v523;
  int * v214 = v54->saved_regs;
  int * v215 = v54->regs;
  int v216 = v215[11];
  v214[11] = v216;
  int v218 = v54->timer;
  int v528 = v218 + 1;
  v54->timer = v528;
  int * v220 = v54->regs;
  int v221 = v220[6];
  int * v222 = v54->cache_tags;
  int v531 = (((int)((unsigned int)((int)((unsigned int)v221 >> 2)) >> 1)) & 1) * 2;
  int v223 = v222[v531];
  int * v224 = v54->cache_tags;
  int v533 = ((((int)((unsigned int)((int)((unsigned int)v221 >> 2)) >> 1)) & 1) * 2) + 1;
  int v225 = v224[v533];
  int * v226 = v54->cache_tags;
  int v535 = 4 + ((((int)((unsigned int)((int)((unsigned int)v221 >> 2)) >> 1)) & 3) * 2);
  int v227 = v226[v535];
  int * v228 = v54->cache_tags;
  int v537 = (4 + ((((int)((unsigned int)((int)((unsigned int)v221 >> 2)) >> 1)) & 3) * 2)) + 1;
  int v229 = v228[v537];
  int v230 = v54->timer;
  int v538 = v230 + ((100 ^ (((~(((v227 ^ ((int)((unsigned int)((int)((unsigned int)v221 >> 2)) >> 1))) | (-(v227 ^ ((int)((unsigned int)((int)((unsigned int)v221 >> 2)) >> 1))))) >> 31)) | (~(((v229 ^ ((int)((unsigned int)((int)((unsigned int)v221 >> 2)) >> 1))) | (-(v229 ^ ((int)((unsigned int)((int)((unsigned int)v221 >> 2)) >> 1))))) >> 31))) & 104)) ^ (((~(((v223 ^ ((int)((unsigned int)((int)((unsigned int)v221 >> 2)) >> 1))) | (-(v223 ^ ((int)((unsigned int)((int)((unsigned int)v221 >> 2)) >> 1))))) >> 31)) | (~(((v225 ^ ((int)((unsigned int)((int)((unsigned int)v221 >> 2)) >> 1))) | (-(v225 ^ ((int)((unsigned int)((int)((unsigned int)v221 >> 2)) >> 1))))) >> 31))) & (1 ^ (100 ^ (((~(((v227 ^ ((int)((unsigned int)((int)((unsigned int)v221 >> 2)) >> 1))) | (-(v227 ^ ((int)((unsigned int)((int)((unsigned int)v221 >> 2)) >> 1))))) >> 31)) | (~(((v229 ^ ((int)((unsigned int)((int)((unsigned int)v221 >> 2)) >> 1))) | (-(v229 ^ ((int)((unsigned int)((int)((unsigned int)v221 >> 2)) >> 1))))) >> 31))) & 104)))));
  v54->timer = v538;
  int * v232 = v54->cache_vals;
  bool v539 = !(((~(((v223 ^ ((int)((unsigned int)((int)((unsigned int)v221 >> 2)) >> 1))) | (-(v223 ^ ((int)((unsigned int)((int)((unsigned int)v221 >> 2)) >> 1))))) >> 31)) | (~(((v225 ^ ((int)((unsigned int)((int)((unsigned int)v221 >> 2)) >> 1))) | (-(v225 ^ ((int)((unsigned int)((int)((unsigned int)v221 >> 2)) >> 1))))) >> 31))) == 0);
  int v345;
  if (v539) {
    int * v233 = v54->cache_age;
    int v541 = ((((int)((unsigned int)((int)((unsigned int)v221 >> 2)) >> 1)) & 1) * 2) + ((~(((v225 ^ ((int)((unsigned int)((int)((unsigned int)v221 >> 2)) >> 1))) | (-(v225 ^ ((int)((unsigned int)((int)((unsigned int)v221 >> 2)) >> 1))))) >> 31)) & 1);
    int v234 = v233[v541];
    int * v235 = v54->cache_age;
    int v236 = v235[v531];
    int * v237 = v54->cache_age;
    int v544 = v236 + ((int)((unsigned int)(v236 - v234) >> 31));
    v237[v531] = v544;
    int * v239 = v54->cache_age;
    int v240 = v239[v533];
    int * v241 = v54->cache_age;
    int v547 = v240 + ((int)((unsigned int)(v240 - v234) >> 31));
    v241[v533] = v547;
    int * v243 = v54->cache_age;
    v243[v541] = 0;
    v345 = v541;
  } else {
    int * v246 = v54->cache_age;
    int v551 = (((int)((unsigned int)((int)((unsigned int)v221 >> 2)) >> 1)) & 1) * 2;
    int v247 = v246[v551];
    int * v248 = v54->cache_tags;
    int v249 = v248[v551];
    int * v250 = v54->cache_age;
    int v251 = v250[v533];
    int * v252 = v54->cache_tags;
    int v253 = v252[v533];
    bool v555 = !(((~(((v227 ^ ((int)((unsigned int)((int)((unsigned int)v221 >> 2)) >> 1))) | (-(v227 ^ ((int)((unsigned int)((int)((unsigned int)v221 >> 2)) >> 1))))) >> 31)) | (~(((v229 ^ ((int)((unsigned int)((int)((unsigned int)v221 >> 2)) >> 1))) | (-(v229 ^ ((int)((unsigned int)((int)((unsigned int)v221 >> 2)) >> 1))))) >> 31))) == 0);
    int v317;
    if (v555) {
      int * v254 = v54->cache_age;
      int v557 = (4 + ((((int)((unsigned int)((int)((unsigned int)v221 >> 2)) >> 1)) & 3) * 2)) + ((~(((v229 ^ ((int)((unsigned int)((int)((unsigned int)v221 >> 2)) >> 1))) | (-(v229 ^ ((int)((unsigned int)((int)((unsigned int)v221 >> 2)) >> 1))))) >> 31)) & 1);
      int v255 = v254[v557];
      int * v256 = v54->cache_age;
      int v257 = v256[v535];
      int * v258 = v54->cache_age;
      int v560 = v257 + ((int)((unsigned int)(v257 - v255) >> 31));
      v258[v535] = v560;
      int * v260 = v54->cache_age;
      int v261 = v260[v537];
      int * v262 = v54->cache_age;
      int v563 = v261 + ((int)((unsigned int)(v261 - v255) >> 31));
      v262[v537] = v563;
      int * v264 = v54->cache_age;
      v264[v557] = 0;
      v317 = v557;
    } else {
      int * v267 = v54->cache_age;
      int v567 = 4 + ((((int)((unsigned int)((int)((unsigned int)v221 >> 2)) >> 1)) & 3) * 2);
      int v268 = v267[v567];
      int * v269 = v54->cache_tags;
      int v270 = v269[v567];
      int * v271 = v54->cache_age;
      int v272 = v271[v537];
      int * v273 = v54->cache_tags;
      int v274 = v273[v537];
      int * v275 = v54->cache_dirty;
      int v572 = (4 + ((((int)((unsigned int)((int)((unsigned int)v221 >> 2)) >> 1)) & 3) * 2)) + ((((v268 + ((~(((v270 ^ -1) | (-(v270 ^ -1))) >> 31)) & 2)) - (v272 + ((~(((v274 ^ -1) | (-(v274 ^ -1))) >> 31)) & 2))) >> 31) & 1);
      int v276 = v275[v572];
      bool v573 = !(v276 == 0);
      if (v573) {
        int * v277 = v54->cache_tags;
        int v278 = v277[v572];
        int * v279 = v54->cache_vals;
        int v576 = ((4 + ((((int)((unsigned int)((int)((unsigned int)v221 >> 2)) >> 1)) & 3) * 2)) + ((((v268 + ((~(((v270 ^ -1) | (-(v270 ^ -1))) >> 31)) & 2)) - (v272 + ((~(((v274 ^ -1) | (-(v274 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
        int v280 = v279[v576];
        int * v281 = v54->cache_vals;
        int v578 = (((4 + ((((int)((unsigned int)((int)((unsigned int)v221 >> 2)) >> 1)) & 3) * 2)) + ((((v268 + ((~(((v270 ^ -1) | (-(v270 ^ -1))) >> 31)) & 2)) - (v272 + ((~(((v274 ^ -1) | (-(v274 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
        int v282 = v281[v578];
        int * v283 = v54->mem;
        int v580 = v278 * 2;
        v283[v580] = v280;
        int * v285 = v54->mem;
        int v583 = (v278 * 2) + 1;
        v285[v583] = v282;
        ;
      } else {
        ;
      }
      int * v290 = v54->mem;
      int v588 = ((int)((unsigned int)((int)((unsigned int)v221 >> 2)) >> 1)) * 2;
      int v291 = v290[v588];
      int * v292 = v54->mem;
      int v590 = (((int)((unsigned int)((int)((unsigned int)v221 >> 2)) >> 1)) * 2) + 1;
      int v293 = v292[v590];
      int * v294 = v54->cache_vals;
      int v592 = ((4 + ((((int)((unsigned int)((int)((unsigned int)v221 >> 2)) >> 1)) & 3) * 2)) + ((((v268 + ((~(((v270 ^ -1) | (-(v270 ^ -1))) >> 31)) & 2)) - (v272 + ((~(((v274 ^ -1) | (-(v274 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
      v294[v592] = v291;
      int * v296 = v54->cache_vals;
      int v595 = (((4 + ((((int)((unsigned int)((int)((unsigned int)v221 >> 2)) >> 1)) & 3) * 2)) + ((((v268 + ((~(((v270 ^ -1) | (-(v270 ^ -1))) >> 31)) & 2)) - (v272 + ((~(((v274 ^ -1) | (-(v274 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
      v296[v595] = v293;
      int * v298 = v54->cache_tags;
      int v598 = (int)((unsigned int)((int)((unsigned int)v221 >> 2)) >> 1);
      v298[v572] = v598;
      int * v300 = v54->cache_dirty;
      v300[v572] = 0;
      int * v302 = v54->cache_age;
      v302[v572] = 1;
      int * v304 = v54->cache_age;
      int v305 = v304[v572];
      int * v306 = v54->cache_age;
      int v307 = v306[v535];
      int * v308 = v54->cache_age;
      int v606 = v307 + ((int)((unsigned int)(v307 - v305) >> 31));
      v308[v535] = v606;
      int * v310 = v54->cache_age;
      int v311 = v310[v537];
      int * v312 = v54->cache_age;
      int v609 = v311 + ((int)((unsigned int)(v311 - v305) >> 31));
      v312[v537] = v609;
      int * v314 = v54->cache_age;
      v314[v572] = 0;
      v317 = v572;
    }
    int * v318 = v54->cache_vals;
    int v612 = v317 * 2;
    int v319 = v318[v612];
    int * v320 = v54->cache_vals;
    int v614 = (v317 * 2) + 1;
    int v321 = v320[v614];
    int * v322 = v54->cache_vals;
    int v616 = (((((int)((unsigned int)((int)((unsigned int)v221 >> 2)) >> 1)) & 1) * 2) + ((((v247 + ((~(((v249 ^ -1) | (-(v249 ^ -1))) >> 31)) & 2)) - (v251 + ((~(((v253 ^ -1) | (-(v253 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
    v322[v616] = v319;
    int * v324 = v54->cache_vals;
    int v619 = ((((((int)((unsigned int)((int)((unsigned int)v221 >> 2)) >> 1)) & 1) * 2) + ((((v247 + ((~(((v249 ^ -1) | (-(v249 ^ -1))) >> 31)) & 2)) - (v251 + ((~(((v253 ^ -1) | (-(v253 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
    v324[v619] = v321;
    int * v326 = v54->cache_tags;
    int v622 = ((((int)((unsigned int)((int)((unsigned int)v221 >> 2)) >> 1)) & 1) * 2) + ((((v247 + ((~(((v249 ^ -1) | (-(v249 ^ -1))) >> 31)) & 2)) - (v251 + ((~(((v253 ^ -1) | (-(v253 ^ -1))) >> 31)) & 2))) >> 31) & 1);
    int v623 = (int)((unsigned int)((int)((unsigned int)v221 >> 2)) >> 1);
    v326[v622] = v623;
    int * v328 = v54->cache_dirty;
    v328[v622] = 0;
    int * v330 = v54->cache_age;
    v330[v622] = 1;
    int * v332 = v54->cache_age;
    int v333 = v332[v622];
    int * v334 = v54->cache_age;
    int v335 = v334[v531];
    int * v336 = v54->cache_age;
    int v631 = v335 + ((int)((unsigned int)(v335 - v333) >> 31));
    v336[v531] = v631;
    int * v338 = v54->cache_age;
    int v339 = v338[v533];
    int * v340 = v54->cache_age;
    int v634 = v339 + ((int)((unsigned int)(v339 - v333) >> 31));
    v340[v533] = v634;
    int * v342 = v54->cache_age;
    v342[v622] = 0;
    v345 = v622;
  }
  int v637 = (v345 * 2) + (((int)((unsigned int)v221 >> 2)) & 1);
  int v346 = v232[v637];
  int * v347 = v54->regs;
  v347[11] = v346;
  int * v349 = v54->regs;
  int v350 = v349[14];
  int * v351 = v54->regs;
  int v352 = v351[15];
  bool v643 = v350 >= v352;
  struct StateT * v385;
  if (v643) {
    int v353 = v54->timer;
    int v644 = v353 + 15;
    v54->timer = v644;
    int * v355 = v54->saved_regs;
    int v356 = v355[5];
    int * v357 = v54->regs;
    v357[5] = v356;
    int * v359 = v54->saved_regs;
    int v360 = v359[10];
    int * v361 = v54->regs;
    v361[10] = v360;
    int * v363 = v54->saved_regs;
    int v364 = v363[6];
    int * v365 = v54->regs;
    v365[6] = v364;
    int * v367 = v54->saved_regs;
    int v368 = v367[11];
    int * v369 = v54->regs;
    v369[11] = v368;
    struct StateT * v371 = slot_14(v54);
    v385 = v371;
  } else {
    int v373 = v54->timer;
    int v659 = v373 + 1;
    v54->timer = v659;
    int * v375 = v54->regs;
    int v376 = v375[10];
    int * v377 = v54->regs;
    int v378 = v377[11];
    bool v662 = !(v376 == v378);
    struct StateT * v383;
    if (v662) {
      struct StateT * v379 = slot_12(v54);
      v383 = v379;
    } else {
      struct StateT * v381 = slot_10(v54);
      v383 = v381;
    }
    v385 = v383;
  }
  return v385;
}

struct StateT * slot_13(struct StateT * v708) {
  int v709 = v708->timer;
  int v712 = v709 + 1;
  v708->timer = v712;
  return v708;
}

struct StateT * slot_11(struct StateT * v713) {
  int v714 = v713->timer;
  int v718 = v714 + 1;
  v713->timer = v718;
  struct StateT * v716 = slot_4(v713);
  return v716;
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