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

struct StateT * slot_12(struct StateT * v695);
struct StateT * slot_14(struct StateT * v640);
struct StateT * slot_16(struct StateT * v674);
struct StateT * slot_2(struct StateT * v32);
struct StateT * slot_7(struct StateT * v731);
struct StateT * snippet(struct StateT * v0);
struct StateT * slot_10(struct StateT * v658);
struct StateT * slot_1(struct StateT * v19);
struct StateT * slot_8(struct StateT * v981);
struct StateT * slot_13(struct StateT * v711);
struct StateT * slot_15(struct StateT * v645);
struct StateT * slot_9(struct StateT * v1231);
struct StateT * slot_11(struct StateT * v679);
struct StateT * slot_0(struct StateT * v2);
struct StateT * slot_12(struct StateT * v695) {
  int v696 = v695->timer;
  int v704 = v696 + 1;
  v695->timer = v704;
  int * v698 = v695->regs;
  int v699 = v698[13];
  int * v700 = v695->regs;
  int v708 = v699 + 4;
  v700[13] = v708;
  struct StateT * v702 = slot_13(v695);
  return v702;
}

struct StateT * slot_14(struct StateT * v640) {
  int v641 = v640->timer;
  int v644 = v641 + 1;
  v640->timer = v644;
  return v640;
}

struct StateT * slot_16(struct StateT * v674) {
  int v675 = v674->timer;
  int v678 = v675 + 1;
  v674->timer = v678;
  return v674;
}

struct StateT * slot_2(struct StateT * v32) {
  int * v33 = v32->saved_regs;
  int * v34 = v32->regs;
  int v35 = v34[12];
  v33[12] = v35;
  int v37 = v32->timer;
  int v371 = v37 + 1;
  v32->timer = v371;
  int * v39 = v32->regs;
  v39[12] = 0;
  int v41 = v32->timer;
  int v374 = v41 + 1;
  v32->timer = v374;
  int * v43 = v32->regs;
  int v44 = v43[12];
  int * v45 = v32->regs;
  int v377 = v44 + 16;
  v45[12] = v377;
  int * v47 = v32->saved_regs;
  int * v48 = v32->regs;
  int v49 = v48[13];
  v47[13] = v49;
  int v51 = v32->timer;
  int v382 = v51 + 1;
  v32->timer = v382;
  int * v53 = v32->regs;
  v53[13] = 0;
  int v55 = v32->timer;
  int v384 = v55 + 1;
  v32->timer = v384;
  int * v57 = v32->regs;
  int v58 = v57[13];
  int * v59 = v32->regs;
  v59[13] = v58;
  int * v61 = v32->saved_regs;
  int * v62 = v32->regs;
  int v63 = v62[14];
  v61[14] = v63;
  int v65 = v32->timer;
  int v392 = v65 + 1;
  v32->timer = v392;
  int * v67 = v32->regs;
  int v68 = v67[12];
  int * v69 = v32->cache_tags;
  int v395 = (((int)((unsigned int)((int)((unsigned int)v68 >> 2)) >> 1)) & 1) * 2;
  int v70 = v69[v395];
  int * v71 = v32->cache_tags;
  int v397 = ((((int)((unsigned int)((int)((unsigned int)v68 >> 2)) >> 1)) & 1) * 2) + 1;
  int v72 = v71[v397];
  int * v73 = v32->cache_tags;
  int v399 = 4 + ((((int)((unsigned int)((int)((unsigned int)v68 >> 2)) >> 1)) & 3) * 2);
  int v74 = v73[v399];
  int * v75 = v32->cache_tags;
  int v401 = (4 + ((((int)((unsigned int)((int)((unsigned int)v68 >> 2)) >> 1)) & 3) * 2)) + 1;
  int v76 = v75[v401];
  int v77 = v32->timer;
  int v402 = v77 + ((100 ^ (((~(((v74 ^ ((int)((unsigned int)((int)((unsigned int)v68 >> 2)) >> 1))) | (-(v74 ^ ((int)((unsigned int)((int)((unsigned int)v68 >> 2)) >> 1))))) >> 31)) | (~(((v76 ^ ((int)((unsigned int)((int)((unsigned int)v68 >> 2)) >> 1))) | (-(v76 ^ ((int)((unsigned int)((int)((unsigned int)v68 >> 2)) >> 1))))) >> 31))) & 104)) ^ (((~(((v70 ^ ((int)((unsigned int)((int)((unsigned int)v68 >> 2)) >> 1))) | (-(v70 ^ ((int)((unsigned int)((int)((unsigned int)v68 >> 2)) >> 1))))) >> 31)) | (~(((v72 ^ ((int)((unsigned int)((int)((unsigned int)v68 >> 2)) >> 1))) | (-(v72 ^ ((int)((unsigned int)((int)((unsigned int)v68 >> 2)) >> 1))))) >> 31))) & (1 ^ (100 ^ (((~(((v74 ^ ((int)((unsigned int)((int)((unsigned int)v68 >> 2)) >> 1))) | (-(v74 ^ ((int)((unsigned int)((int)((unsigned int)v68 >> 2)) >> 1))))) >> 31)) | (~(((v76 ^ ((int)((unsigned int)((int)((unsigned int)v68 >> 2)) >> 1))) | (-(v76 ^ ((int)((unsigned int)((int)((unsigned int)v68 >> 2)) >> 1))))) >> 31))) & 104)))));
  v32->timer = v402;
  int * v79 = v32->cache_vals;
  bool v403 = !(((~(((v70 ^ ((int)((unsigned int)((int)((unsigned int)v68 >> 2)) >> 1))) | (-(v70 ^ ((int)((unsigned int)((int)((unsigned int)v68 >> 2)) >> 1))))) >> 31)) | (~(((v72 ^ ((int)((unsigned int)((int)((unsigned int)v68 >> 2)) >> 1))) | (-(v72 ^ ((int)((unsigned int)((int)((unsigned int)v68 >> 2)) >> 1))))) >> 31))) == 0);
  int v192;
  if (v403) {
    int * v80 = v32->cache_age;
    int v405 = ((((int)((unsigned int)((int)((unsigned int)v68 >> 2)) >> 1)) & 1) * 2) + ((~(((v72 ^ ((int)((unsigned int)((int)((unsigned int)v68 >> 2)) >> 1))) | (-(v72 ^ ((int)((unsigned int)((int)((unsigned int)v68 >> 2)) >> 1))))) >> 31)) & 1);
    int v81 = v80[v405];
    int * v82 = v32->cache_age;
    int v83 = v82[v395];
    int * v84 = v32->cache_age;
    int v408 = v83 + ((int)((unsigned int)(v83 - v81) >> 31));
    v84[v395] = v408;
    int * v86 = v32->cache_age;
    int v87 = v86[v397];
    int * v88 = v32->cache_age;
    int v411 = v87 + ((int)((unsigned int)(v87 - v81) >> 31));
    v88[v397] = v411;
    int * v90 = v32->cache_age;
    v90[v405] = 0;
    v192 = v405;
  } else {
    int * v93 = v32->cache_age;
    int v414 = (((int)((unsigned int)((int)((unsigned int)v68 >> 2)) >> 1)) & 1) * 2;
    int v94 = v93[v414];
    int * v95 = v32->cache_tags;
    int v96 = v95[v414];
    int * v97 = v32->cache_age;
    int v98 = v97[v397];
    int * v99 = v32->cache_tags;
    int v100 = v99[v397];
    bool v418 = !(((~(((v74 ^ ((int)((unsigned int)((int)((unsigned int)v68 >> 2)) >> 1))) | (-(v74 ^ ((int)((unsigned int)((int)((unsigned int)v68 >> 2)) >> 1))))) >> 31)) | (~(((v76 ^ ((int)((unsigned int)((int)((unsigned int)v68 >> 2)) >> 1))) | (-(v76 ^ ((int)((unsigned int)((int)((unsigned int)v68 >> 2)) >> 1))))) >> 31))) == 0);
    int v164;
    if (v418) {
      int * v101 = v32->cache_age;
      int v420 = (4 + ((((int)((unsigned int)((int)((unsigned int)v68 >> 2)) >> 1)) & 3) * 2)) + ((~(((v76 ^ ((int)((unsigned int)((int)((unsigned int)v68 >> 2)) >> 1))) | (-(v76 ^ ((int)((unsigned int)((int)((unsigned int)v68 >> 2)) >> 1))))) >> 31)) & 1);
      int v102 = v101[v420];
      int * v103 = v32->cache_age;
      int v104 = v103[v399];
      int * v105 = v32->cache_age;
      int v423 = v104 + ((int)((unsigned int)(v104 - v102) >> 31));
      v105[v399] = v423;
      int * v107 = v32->cache_age;
      int v108 = v107[v401];
      int * v109 = v32->cache_age;
      int v426 = v108 + ((int)((unsigned int)(v108 - v102) >> 31));
      v109[v401] = v426;
      int * v111 = v32->cache_age;
      v111[v420] = 0;
      v164 = v420;
    } else {
      int * v114 = v32->cache_age;
      int v429 = 4 + ((((int)((unsigned int)((int)((unsigned int)v68 >> 2)) >> 1)) & 3) * 2);
      int v115 = v114[v429];
      int * v116 = v32->cache_tags;
      int v117 = v116[v429];
      int * v118 = v32->cache_age;
      int v119 = v118[v401];
      int * v120 = v32->cache_tags;
      int v121 = v120[v401];
      int * v122 = v32->cache_dirty;
      int v434 = (4 + ((((int)((unsigned int)((int)((unsigned int)v68 >> 2)) >> 1)) & 3) * 2)) + ((((v115 + ((~(((v117 ^ -1) | (-(v117 ^ -1))) >> 31)) & 2)) - (v119 + ((~(((v121 ^ -1) | (-(v121 ^ -1))) >> 31)) & 2))) >> 31) & 1);
      int v123 = v122[v434];
      bool v435 = !(v123 == 0);
      if (v435) {
        int * v124 = v32->cache_tags;
        int v125 = v124[v434];
        int * v126 = v32->cache_vals;
        int v438 = ((4 + ((((int)((unsigned int)((int)((unsigned int)v68 >> 2)) >> 1)) & 3) * 2)) + ((((v115 + ((~(((v117 ^ -1) | (-(v117 ^ -1))) >> 31)) & 2)) - (v119 + ((~(((v121 ^ -1) | (-(v121 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
        int v127 = v126[v438];
        int * v128 = v32->cache_vals;
        int v440 = (((4 + ((((int)((unsigned int)((int)((unsigned int)v68 >> 2)) >> 1)) & 3) * 2)) + ((((v115 + ((~(((v117 ^ -1) | (-(v117 ^ -1))) >> 31)) & 2)) - (v119 + ((~(((v121 ^ -1) | (-(v121 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
        int v129 = v128[v440];
        int * v130 = v32->mem;
        int v442 = v125 * 2;
        v130[v442] = v127;
        int * v132 = v32->mem;
        int v445 = (v125 * 2) + 1;
        v132[v445] = v129;
        ;
      } else {
        ;
      }
      int * v137 = v32->mem;
      int v450 = ((int)((unsigned int)((int)((unsigned int)v68 >> 2)) >> 1)) * 2;
      int v138 = v137[v450];
      int * v139 = v32->mem;
      int v452 = (((int)((unsigned int)((int)((unsigned int)v68 >> 2)) >> 1)) * 2) + 1;
      int v140 = v139[v452];
      int * v141 = v32->cache_vals;
      int v454 = ((4 + ((((int)((unsigned int)((int)((unsigned int)v68 >> 2)) >> 1)) & 3) * 2)) + ((((v115 + ((~(((v117 ^ -1) | (-(v117 ^ -1))) >> 31)) & 2)) - (v119 + ((~(((v121 ^ -1) | (-(v121 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
      v141[v454] = v138;
      int * v143 = v32->cache_vals;
      int v457 = (((4 + ((((int)((unsigned int)((int)((unsigned int)v68 >> 2)) >> 1)) & 3) * 2)) + ((((v115 + ((~(((v117 ^ -1) | (-(v117 ^ -1))) >> 31)) & 2)) - (v119 + ((~(((v121 ^ -1) | (-(v121 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
      v143[v457] = v140;
      int * v145 = v32->cache_tags;
      int v460 = (int)((unsigned int)((int)((unsigned int)v68 >> 2)) >> 1);
      v145[v434] = v460;
      int * v147 = v32->cache_dirty;
      v147[v434] = 0;
      int * v149 = v32->cache_age;
      v149[v434] = 1;
      int * v151 = v32->cache_age;
      int v152 = v151[v434];
      int * v153 = v32->cache_age;
      int v154 = v153[v399];
      int * v155 = v32->cache_age;
      int v467 = v154 + ((int)((unsigned int)(v154 - v152) >> 31));
      v155[v399] = v467;
      int * v157 = v32->cache_age;
      int v158 = v157[v401];
      int * v159 = v32->cache_age;
      int v470 = v158 + ((int)((unsigned int)(v158 - v152) >> 31));
      v159[v401] = v470;
      int * v161 = v32->cache_age;
      v161[v434] = 0;
      v164 = v434;
    }
    int * v165 = v32->cache_vals;
    int v473 = v164 * 2;
    int v166 = v165[v473];
    int * v167 = v32->cache_vals;
    int v475 = (v164 * 2) + 1;
    int v168 = v167[v475];
    int * v169 = v32->cache_vals;
    int v477 = (((((int)((unsigned int)((int)((unsigned int)v68 >> 2)) >> 1)) & 1) * 2) + ((((v94 + ((~(((v96 ^ -1) | (-(v96 ^ -1))) >> 31)) & 2)) - (v98 + ((~(((v100 ^ -1) | (-(v100 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
    v169[v477] = v166;
    int * v171 = v32->cache_vals;
    int v480 = ((((((int)((unsigned int)((int)((unsigned int)v68 >> 2)) >> 1)) & 1) * 2) + ((((v94 + ((~(((v96 ^ -1) | (-(v96 ^ -1))) >> 31)) & 2)) - (v98 + ((~(((v100 ^ -1) | (-(v100 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
    v171[v480] = v168;
    int * v173 = v32->cache_tags;
    int v483 = ((((int)((unsigned int)((int)((unsigned int)v68 >> 2)) >> 1)) & 1) * 2) + ((((v94 + ((~(((v96 ^ -1) | (-(v96 ^ -1))) >> 31)) & 2)) - (v98 + ((~(((v100 ^ -1) | (-(v100 ^ -1))) >> 31)) & 2))) >> 31) & 1);
    int v484 = (int)((unsigned int)((int)((unsigned int)v68 >> 2)) >> 1);
    v173[v483] = v484;
    int * v175 = v32->cache_dirty;
    v175[v483] = 0;
    int * v177 = v32->cache_age;
    v177[v483] = 1;
    int * v179 = v32->cache_age;
    int v180 = v179[v483];
    int * v181 = v32->cache_age;
    int v182 = v181[v395];
    int * v183 = v32->cache_age;
    int v491 = v182 + ((int)((unsigned int)(v182 - v180) >> 31));
    v183[v395] = v491;
    int * v185 = v32->cache_age;
    int v186 = v185[v397];
    int * v187 = v32->cache_age;
    int v494 = v186 + ((int)((unsigned int)(v186 - v180) >> 31));
    v187[v397] = v494;
    int * v189 = v32->cache_age;
    v189[v483] = 0;
    v192 = v483;
  }
  int v497 = (v192 * 2) + (((int)((unsigned int)v68 >> 2)) & 1);
  int v193 = v79[v497];
  int * v194 = v32->regs;
  v194[14] = v193;
  int * v196 = v32->saved_regs;
  int * v197 = v32->regs;
  int v198 = v197[15];
  v196[15] = v198;
  int v200 = v32->timer;
  int v504 = v200 + 1;
  v32->timer = v504;
  int * v202 = v32->regs;
  int v203 = v202[13];
  int * v204 = v32->cache_tags;
  int v507 = (((int)((unsigned int)((int)((unsigned int)v203 >> 2)) >> 1)) & 1) * 2;
  int v205 = v204[v507];
  int * v206 = v32->cache_tags;
  int v509 = ((((int)((unsigned int)((int)((unsigned int)v203 >> 2)) >> 1)) & 1) * 2) + 1;
  int v207 = v206[v509];
  int * v208 = v32->cache_tags;
  int v511 = 4 + ((((int)((unsigned int)((int)((unsigned int)v203 >> 2)) >> 1)) & 3) * 2);
  int v209 = v208[v511];
  int * v210 = v32->cache_tags;
  int v513 = (4 + ((((int)((unsigned int)((int)((unsigned int)v203 >> 2)) >> 1)) & 3) * 2)) + 1;
  int v211 = v210[v513];
  int v212 = v32->timer;
  int v514 = v212 + ((100 ^ (((~(((v209 ^ ((int)((unsigned int)((int)((unsigned int)v203 >> 2)) >> 1))) | (-(v209 ^ ((int)((unsigned int)((int)((unsigned int)v203 >> 2)) >> 1))))) >> 31)) | (~(((v211 ^ ((int)((unsigned int)((int)((unsigned int)v203 >> 2)) >> 1))) | (-(v211 ^ ((int)((unsigned int)((int)((unsigned int)v203 >> 2)) >> 1))))) >> 31))) & 104)) ^ (((~(((v205 ^ ((int)((unsigned int)((int)((unsigned int)v203 >> 2)) >> 1))) | (-(v205 ^ ((int)((unsigned int)((int)((unsigned int)v203 >> 2)) >> 1))))) >> 31)) | (~(((v207 ^ ((int)((unsigned int)((int)((unsigned int)v203 >> 2)) >> 1))) | (-(v207 ^ ((int)((unsigned int)((int)((unsigned int)v203 >> 2)) >> 1))))) >> 31))) & (1 ^ (100 ^ (((~(((v209 ^ ((int)((unsigned int)((int)((unsigned int)v203 >> 2)) >> 1))) | (-(v209 ^ ((int)((unsigned int)((int)((unsigned int)v203 >> 2)) >> 1))))) >> 31)) | (~(((v211 ^ ((int)((unsigned int)((int)((unsigned int)v203 >> 2)) >> 1))) | (-(v211 ^ ((int)((unsigned int)((int)((unsigned int)v203 >> 2)) >> 1))))) >> 31))) & 104)))));
  v32->timer = v514;
  int * v214 = v32->cache_vals;
  bool v515 = !(((~(((v205 ^ ((int)((unsigned int)((int)((unsigned int)v203 >> 2)) >> 1))) | (-(v205 ^ ((int)((unsigned int)((int)((unsigned int)v203 >> 2)) >> 1))))) >> 31)) | (~(((v207 ^ ((int)((unsigned int)((int)((unsigned int)v203 >> 2)) >> 1))) | (-(v207 ^ ((int)((unsigned int)((int)((unsigned int)v203 >> 2)) >> 1))))) >> 31))) == 0);
  int v327;
  if (v515) {
    int * v215 = v32->cache_age;
    int v517 = ((((int)((unsigned int)((int)((unsigned int)v203 >> 2)) >> 1)) & 1) * 2) + ((~(((v207 ^ ((int)((unsigned int)((int)((unsigned int)v203 >> 2)) >> 1))) | (-(v207 ^ ((int)((unsigned int)((int)((unsigned int)v203 >> 2)) >> 1))))) >> 31)) & 1);
    int v216 = v215[v517];
    int * v217 = v32->cache_age;
    int v218 = v217[v507];
    int * v219 = v32->cache_age;
    int v520 = v218 + ((int)((unsigned int)(v218 - v216) >> 31));
    v219[v507] = v520;
    int * v221 = v32->cache_age;
    int v222 = v221[v509];
    int * v223 = v32->cache_age;
    int v523 = v222 + ((int)((unsigned int)(v222 - v216) >> 31));
    v223[v509] = v523;
    int * v225 = v32->cache_age;
    v225[v517] = 0;
    v327 = v517;
  } else {
    int * v228 = v32->cache_age;
    int v526 = (((int)((unsigned int)((int)((unsigned int)v203 >> 2)) >> 1)) & 1) * 2;
    int v229 = v228[v526];
    int * v230 = v32->cache_tags;
    int v231 = v230[v526];
    int * v232 = v32->cache_age;
    int v233 = v232[v509];
    int * v234 = v32->cache_tags;
    int v235 = v234[v509];
    bool v530 = !(((~(((v209 ^ ((int)((unsigned int)((int)((unsigned int)v203 >> 2)) >> 1))) | (-(v209 ^ ((int)((unsigned int)((int)((unsigned int)v203 >> 2)) >> 1))))) >> 31)) | (~(((v211 ^ ((int)((unsigned int)((int)((unsigned int)v203 >> 2)) >> 1))) | (-(v211 ^ ((int)((unsigned int)((int)((unsigned int)v203 >> 2)) >> 1))))) >> 31))) == 0);
    int v299;
    if (v530) {
      int * v236 = v32->cache_age;
      int v532 = (4 + ((((int)((unsigned int)((int)((unsigned int)v203 >> 2)) >> 1)) & 3) * 2)) + ((~(((v211 ^ ((int)((unsigned int)((int)((unsigned int)v203 >> 2)) >> 1))) | (-(v211 ^ ((int)((unsigned int)((int)((unsigned int)v203 >> 2)) >> 1))))) >> 31)) & 1);
      int v237 = v236[v532];
      int * v238 = v32->cache_age;
      int v239 = v238[v511];
      int * v240 = v32->cache_age;
      int v535 = v239 + ((int)((unsigned int)(v239 - v237) >> 31));
      v240[v511] = v535;
      int * v242 = v32->cache_age;
      int v243 = v242[v513];
      int * v244 = v32->cache_age;
      int v538 = v243 + ((int)((unsigned int)(v243 - v237) >> 31));
      v244[v513] = v538;
      int * v246 = v32->cache_age;
      v246[v532] = 0;
      v299 = v532;
    } else {
      int * v249 = v32->cache_age;
      int v541 = 4 + ((((int)((unsigned int)((int)((unsigned int)v203 >> 2)) >> 1)) & 3) * 2);
      int v250 = v249[v541];
      int * v251 = v32->cache_tags;
      int v252 = v251[v541];
      int * v253 = v32->cache_age;
      int v254 = v253[v513];
      int * v255 = v32->cache_tags;
      int v256 = v255[v513];
      int * v257 = v32->cache_dirty;
      int v546 = (4 + ((((int)((unsigned int)((int)((unsigned int)v203 >> 2)) >> 1)) & 3) * 2)) + ((((v250 + ((~(((v252 ^ -1) | (-(v252 ^ -1))) >> 31)) & 2)) - (v254 + ((~(((v256 ^ -1) | (-(v256 ^ -1))) >> 31)) & 2))) >> 31) & 1);
      int v258 = v257[v546];
      bool v547 = !(v258 == 0);
      if (v547) {
        int * v259 = v32->cache_tags;
        int v260 = v259[v546];
        int * v261 = v32->cache_vals;
        int v550 = ((4 + ((((int)((unsigned int)((int)((unsigned int)v203 >> 2)) >> 1)) & 3) * 2)) + ((((v250 + ((~(((v252 ^ -1) | (-(v252 ^ -1))) >> 31)) & 2)) - (v254 + ((~(((v256 ^ -1) | (-(v256 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
        int v262 = v261[v550];
        int * v263 = v32->cache_vals;
        int v552 = (((4 + ((((int)((unsigned int)((int)((unsigned int)v203 >> 2)) >> 1)) & 3) * 2)) + ((((v250 + ((~(((v252 ^ -1) | (-(v252 ^ -1))) >> 31)) & 2)) - (v254 + ((~(((v256 ^ -1) | (-(v256 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
        int v264 = v263[v552];
        int * v265 = v32->mem;
        int v554 = v260 * 2;
        v265[v554] = v262;
        int * v267 = v32->mem;
        int v557 = (v260 * 2) + 1;
        v267[v557] = v264;
        ;
      } else {
        ;
      }
      int * v272 = v32->mem;
      int v562 = ((int)((unsigned int)((int)((unsigned int)v203 >> 2)) >> 1)) * 2;
      int v273 = v272[v562];
      int * v274 = v32->mem;
      int v564 = (((int)((unsigned int)((int)((unsigned int)v203 >> 2)) >> 1)) * 2) + 1;
      int v275 = v274[v564];
      int * v276 = v32->cache_vals;
      int v566 = ((4 + ((((int)((unsigned int)((int)((unsigned int)v203 >> 2)) >> 1)) & 3) * 2)) + ((((v250 + ((~(((v252 ^ -1) | (-(v252 ^ -1))) >> 31)) & 2)) - (v254 + ((~(((v256 ^ -1) | (-(v256 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
      v276[v566] = v273;
      int * v278 = v32->cache_vals;
      int v569 = (((4 + ((((int)((unsigned int)((int)((unsigned int)v203 >> 2)) >> 1)) & 3) * 2)) + ((((v250 + ((~(((v252 ^ -1) | (-(v252 ^ -1))) >> 31)) & 2)) - (v254 + ((~(((v256 ^ -1) | (-(v256 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
      v278[v569] = v275;
      int * v280 = v32->cache_tags;
      int v572 = (int)((unsigned int)((int)((unsigned int)v203 >> 2)) >> 1);
      v280[v546] = v572;
      int * v282 = v32->cache_dirty;
      v282[v546] = 0;
      int * v284 = v32->cache_age;
      v284[v546] = 1;
      int * v286 = v32->cache_age;
      int v287 = v286[v546];
      int * v288 = v32->cache_age;
      int v289 = v288[v511];
      int * v290 = v32->cache_age;
      int v579 = v289 + ((int)((unsigned int)(v289 - v287) >> 31));
      v290[v511] = v579;
      int * v292 = v32->cache_age;
      int v293 = v292[v513];
      int * v294 = v32->cache_age;
      int v582 = v293 + ((int)((unsigned int)(v293 - v287) >> 31));
      v294[v513] = v582;
      int * v296 = v32->cache_age;
      v296[v546] = 0;
      v299 = v546;
    }
    int * v300 = v32->cache_vals;
    int v585 = v299 * 2;
    int v301 = v300[v585];
    int * v302 = v32->cache_vals;
    int v587 = (v299 * 2) + 1;
    int v303 = v302[v587];
    int * v304 = v32->cache_vals;
    int v589 = (((((int)((unsigned int)((int)((unsigned int)v203 >> 2)) >> 1)) & 1) * 2) + ((((v229 + ((~(((v231 ^ -1) | (-(v231 ^ -1))) >> 31)) & 2)) - (v233 + ((~(((v235 ^ -1) | (-(v235 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
    v304[v589] = v301;
    int * v306 = v32->cache_vals;
    int v592 = ((((((int)((unsigned int)((int)((unsigned int)v203 >> 2)) >> 1)) & 1) * 2) + ((((v229 + ((~(((v231 ^ -1) | (-(v231 ^ -1))) >> 31)) & 2)) - (v233 + ((~(((v235 ^ -1) | (-(v235 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
    v306[v592] = v303;
    int * v308 = v32->cache_tags;
    int v595 = ((((int)((unsigned int)((int)((unsigned int)v203 >> 2)) >> 1)) & 1) * 2) + ((((v229 + ((~(((v231 ^ -1) | (-(v231 ^ -1))) >> 31)) & 2)) - (v233 + ((~(((v235 ^ -1) | (-(v235 ^ -1))) >> 31)) & 2))) >> 31) & 1);
    int v596 = (int)((unsigned int)((int)((unsigned int)v203 >> 2)) >> 1);
    v308[v595] = v596;
    int * v310 = v32->cache_dirty;
    v310[v595] = 0;
    int * v312 = v32->cache_age;
    v312[v595] = 1;
    int * v314 = v32->cache_age;
    int v315 = v314[v595];
    int * v316 = v32->cache_age;
    int v317 = v316[v507];
    int * v318 = v32->cache_age;
    int v603 = v317 + ((int)((unsigned int)(v317 - v315) >> 31));
    v318[v507] = v603;
    int * v320 = v32->cache_age;
    int v321 = v320[v509];
    int * v322 = v32->cache_age;
    int v606 = v321 + ((int)((unsigned int)(v321 - v315) >> 31));
    v322[v509] = v606;
    int * v324 = v32->cache_age;
    v324[v595] = 0;
    v327 = v595;
  }
  int v609 = (v327 * 2) + (((int)((unsigned int)v203 >> 2)) & 1);
  int v328 = v214[v609];
  int * v329 = v32->regs;
  v329[15] = v328;
  int * v331 = v32->regs;
  int v332 = v331[11];
  bool v614 = 0 >= v332;
  struct StateT * v365;
  if (v614) {
    int v333 = v32->timer;
    int v615 = v333 + 15;
    v32->timer = v615;
    int * v335 = v32->saved_regs;
    int v336 = v335[12];
    int * v337 = v32->regs;
    v337[12] = v336;
    int * v339 = v32->saved_regs;
    int v340 = v339[13];
    int * v341 = v32->regs;
    v341[13] = v340;
    int * v343 = v32->saved_regs;
    int v344 = v343[14];
    int * v345 = v32->regs;
    v345[14] = v344;
    int * v347 = v32->saved_regs;
    int v348 = v347[15];
    int * v349 = v32->regs;
    v349[15] = v348;
    struct StateT * v351 = slot_14(v32);
    v365 = v351;
  } else {
    int v353 = v32->timer;
    int v630 = v353 + 1;
    v32->timer = v630;
    int * v355 = v32->regs;
    int v356 = v355[14];
    int * v357 = v32->regs;
    int v358 = v357[15];
    bool v633 = !(v356 == v358);
    struct StateT * v363;
    if (v633) {
      struct StateT * v359 = slot_15(v32);
      v363 = v359;
    } else {
      struct StateT * v361 = slot_10(v32);
      v363 = v361;
    }
    v365 = v363;
  }
  return v365;
}

struct StateT * slot_7(struct StateT * v731) {
  int v732 = v731->timer;
  int v865 = v732 + 1;
  v731->timer = v865;
  int * v734 = v731->regs;
  int v735 = v734[12];
  int * v736 = v731->cache_tags;
  int v869 = (((int)((unsigned int)((int)((unsigned int)v735 >> 2)) >> 1)) & 1) * 2;
  int v737 = v736[v869];
  int * v738 = v731->cache_tags;
  int v871 = ((((int)((unsigned int)((int)((unsigned int)v735 >> 2)) >> 1)) & 1) * 2) + 1;
  int v739 = v738[v871];
  int * v740 = v731->cache_tags;
  int v873 = 4 + ((((int)((unsigned int)((int)((unsigned int)v735 >> 2)) >> 1)) & 3) * 2);
  int v741 = v740[v873];
  int * v742 = v731->cache_tags;
  int v875 = (4 + ((((int)((unsigned int)((int)((unsigned int)v735 >> 2)) >> 1)) & 3) * 2)) + 1;
  int v743 = v742[v875];
  int v744 = v731->timer;
  int v876 = v744 + ((100 ^ (((~(((v741 ^ ((int)((unsigned int)((int)((unsigned int)v735 >> 2)) >> 1))) | (-(v741 ^ ((int)((unsigned int)((int)((unsigned int)v735 >> 2)) >> 1))))) >> 31)) | (~(((v743 ^ ((int)((unsigned int)((int)((unsigned int)v735 >> 2)) >> 1))) | (-(v743 ^ ((int)((unsigned int)((int)((unsigned int)v735 >> 2)) >> 1))))) >> 31))) & 104)) ^ (((~(((v737 ^ ((int)((unsigned int)((int)((unsigned int)v735 >> 2)) >> 1))) | (-(v737 ^ ((int)((unsigned int)((int)((unsigned int)v735 >> 2)) >> 1))))) >> 31)) | (~(((v739 ^ ((int)((unsigned int)((int)((unsigned int)v735 >> 2)) >> 1))) | (-(v739 ^ ((int)((unsigned int)((int)((unsigned int)v735 >> 2)) >> 1))))) >> 31))) & (1 ^ (100 ^ (((~(((v741 ^ ((int)((unsigned int)((int)((unsigned int)v735 >> 2)) >> 1))) | (-(v741 ^ ((int)((unsigned int)((int)((unsigned int)v735 >> 2)) >> 1))))) >> 31)) | (~(((v743 ^ ((int)((unsigned int)((int)((unsigned int)v735 >> 2)) >> 1))) | (-(v743 ^ ((int)((unsigned int)((int)((unsigned int)v735 >> 2)) >> 1))))) >> 31))) & 104)))));
  v731->timer = v876;
  int * v746 = v731->cache_vals;
  bool v877 = !(((~(((v737 ^ ((int)((unsigned int)((int)((unsigned int)v735 >> 2)) >> 1))) | (-(v737 ^ ((int)((unsigned int)((int)((unsigned int)v735 >> 2)) >> 1))))) >> 31)) | (~(((v739 ^ ((int)((unsigned int)((int)((unsigned int)v735 >> 2)) >> 1))) | (-(v739 ^ ((int)((unsigned int)((int)((unsigned int)v735 >> 2)) >> 1))))) >> 31))) == 0);
  int v859;
  if (v877) {
    int * v747 = v731->cache_age;
    int v879 = ((((int)((unsigned int)((int)((unsigned int)v735 >> 2)) >> 1)) & 1) * 2) + ((~(((v739 ^ ((int)((unsigned int)((int)((unsigned int)v735 >> 2)) >> 1))) | (-(v739 ^ ((int)((unsigned int)((int)((unsigned int)v735 >> 2)) >> 1))))) >> 31)) & 1);
    int v748 = v747[v879];
    int * v749 = v731->cache_age;
    int v750 = v749[v869];
    int * v751 = v731->cache_age;
    int v882 = v750 + ((int)((unsigned int)(v750 - v748) >> 31));
    v751[v869] = v882;
    int * v753 = v731->cache_age;
    int v754 = v753[v871];
    int * v755 = v731->cache_age;
    int v885 = v754 + ((int)((unsigned int)(v754 - v748) >> 31));
    v755[v871] = v885;
    int * v757 = v731->cache_age;
    v757[v879] = 0;
    v859 = v879;
  } else {
    int * v760 = v731->cache_age;
    int v889 = (((int)((unsigned int)((int)((unsigned int)v735 >> 2)) >> 1)) & 1) * 2;
    int v761 = v760[v889];
    int * v762 = v731->cache_tags;
    int v763 = v762[v889];
    int * v764 = v731->cache_age;
    int v765 = v764[v871];
    int * v766 = v731->cache_tags;
    int v767 = v766[v871];
    bool v893 = !(((~(((v741 ^ ((int)((unsigned int)((int)((unsigned int)v735 >> 2)) >> 1))) | (-(v741 ^ ((int)((unsigned int)((int)((unsigned int)v735 >> 2)) >> 1))))) >> 31)) | (~(((v743 ^ ((int)((unsigned int)((int)((unsigned int)v735 >> 2)) >> 1))) | (-(v743 ^ ((int)((unsigned int)((int)((unsigned int)v735 >> 2)) >> 1))))) >> 31))) == 0);
    int v831;
    if (v893) {
      int * v768 = v731->cache_age;
      int v895 = (4 + ((((int)((unsigned int)((int)((unsigned int)v735 >> 2)) >> 1)) & 3) * 2)) + ((~(((v743 ^ ((int)((unsigned int)((int)((unsigned int)v735 >> 2)) >> 1))) | (-(v743 ^ ((int)((unsigned int)((int)((unsigned int)v735 >> 2)) >> 1))))) >> 31)) & 1);
      int v769 = v768[v895];
      int * v770 = v731->cache_age;
      int v771 = v770[v873];
      int * v772 = v731->cache_age;
      int v898 = v771 + ((int)((unsigned int)(v771 - v769) >> 31));
      v772[v873] = v898;
      int * v774 = v731->cache_age;
      int v775 = v774[v875];
      int * v776 = v731->cache_age;
      int v901 = v775 + ((int)((unsigned int)(v775 - v769) >> 31));
      v776[v875] = v901;
      int * v778 = v731->cache_age;
      v778[v895] = 0;
      v831 = v895;
    } else {
      int * v781 = v731->cache_age;
      int v905 = 4 + ((((int)((unsigned int)((int)((unsigned int)v735 >> 2)) >> 1)) & 3) * 2);
      int v782 = v781[v905];
      int * v783 = v731->cache_tags;
      int v784 = v783[v905];
      int * v785 = v731->cache_age;
      int v786 = v785[v875];
      int * v787 = v731->cache_tags;
      int v788 = v787[v875];
      int * v789 = v731->cache_dirty;
      int v910 = (4 + ((((int)((unsigned int)((int)((unsigned int)v735 >> 2)) >> 1)) & 3) * 2)) + ((((v782 + ((~(((v784 ^ -1) | (-(v784 ^ -1))) >> 31)) & 2)) - (v786 + ((~(((v788 ^ -1) | (-(v788 ^ -1))) >> 31)) & 2))) >> 31) & 1);
      int v790 = v789[v910];
      bool v911 = !(v790 == 0);
      if (v911) {
        int * v791 = v731->cache_tags;
        int v792 = v791[v910];
        int * v793 = v731->cache_vals;
        int v914 = ((4 + ((((int)((unsigned int)((int)((unsigned int)v735 >> 2)) >> 1)) & 3) * 2)) + ((((v782 + ((~(((v784 ^ -1) | (-(v784 ^ -1))) >> 31)) & 2)) - (v786 + ((~(((v788 ^ -1) | (-(v788 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
        int v794 = v793[v914];
        int * v795 = v731->cache_vals;
        int v916 = (((4 + ((((int)((unsigned int)((int)((unsigned int)v735 >> 2)) >> 1)) & 3) * 2)) + ((((v782 + ((~(((v784 ^ -1) | (-(v784 ^ -1))) >> 31)) & 2)) - (v786 + ((~(((v788 ^ -1) | (-(v788 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
        int v796 = v795[v916];
        int * v797 = v731->mem;
        int v918 = v792 * 2;
        v797[v918] = v794;
        int * v799 = v731->mem;
        int v921 = (v792 * 2) + 1;
        v799[v921] = v796;
        ;
      } else {
        ;
      }
      int * v804 = v731->mem;
      int v926 = ((int)((unsigned int)((int)((unsigned int)v735 >> 2)) >> 1)) * 2;
      int v805 = v804[v926];
      int * v806 = v731->mem;
      int v928 = (((int)((unsigned int)((int)((unsigned int)v735 >> 2)) >> 1)) * 2) + 1;
      int v807 = v806[v928];
      int * v808 = v731->cache_vals;
      int v930 = ((4 + ((((int)((unsigned int)((int)((unsigned int)v735 >> 2)) >> 1)) & 3) * 2)) + ((((v782 + ((~(((v784 ^ -1) | (-(v784 ^ -1))) >> 31)) & 2)) - (v786 + ((~(((v788 ^ -1) | (-(v788 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
      v808[v930] = v805;
      int * v810 = v731->cache_vals;
      int v933 = (((4 + ((((int)((unsigned int)((int)((unsigned int)v735 >> 2)) >> 1)) & 3) * 2)) + ((((v782 + ((~(((v784 ^ -1) | (-(v784 ^ -1))) >> 31)) & 2)) - (v786 + ((~(((v788 ^ -1) | (-(v788 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
      v810[v933] = v807;
      int * v812 = v731->cache_tags;
      int v936 = (int)((unsigned int)((int)((unsigned int)v735 >> 2)) >> 1);
      v812[v910] = v936;
      int * v814 = v731->cache_dirty;
      v814[v910] = 0;
      int * v816 = v731->cache_age;
      v816[v910] = 1;
      int * v818 = v731->cache_age;
      int v819 = v818[v910];
      int * v820 = v731->cache_age;
      int v821 = v820[v873];
      int * v822 = v731->cache_age;
      int v944 = v821 + ((int)((unsigned int)(v821 - v819) >> 31));
      v822[v873] = v944;
      int * v824 = v731->cache_age;
      int v825 = v824[v875];
      int * v826 = v731->cache_age;
      int v947 = v825 + ((int)((unsigned int)(v825 - v819) >> 31));
      v826[v875] = v947;
      int * v828 = v731->cache_age;
      v828[v910] = 0;
      v831 = v910;
    }
    int * v832 = v731->cache_vals;
    int v950 = v831 * 2;
    int v833 = v832[v950];
    int * v834 = v731->cache_vals;
    int v952 = (v831 * 2) + 1;
    int v835 = v834[v952];
    int * v836 = v731->cache_vals;
    int v954 = (((((int)((unsigned int)((int)((unsigned int)v735 >> 2)) >> 1)) & 1) * 2) + ((((v761 + ((~(((v763 ^ -1) | (-(v763 ^ -1))) >> 31)) & 2)) - (v765 + ((~(((v767 ^ -1) | (-(v767 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
    v836[v954] = v833;
    int * v838 = v731->cache_vals;
    int v957 = ((((((int)((unsigned int)((int)((unsigned int)v735 >> 2)) >> 1)) & 1) * 2) + ((((v761 + ((~(((v763 ^ -1) | (-(v763 ^ -1))) >> 31)) & 2)) - (v765 + ((~(((v767 ^ -1) | (-(v767 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
    v838[v957] = v835;
    int * v840 = v731->cache_tags;
    int v960 = ((((int)((unsigned int)((int)((unsigned int)v735 >> 2)) >> 1)) & 1) * 2) + ((((v761 + ((~(((v763 ^ -1) | (-(v763 ^ -1))) >> 31)) & 2)) - (v765 + ((~(((v767 ^ -1) | (-(v767 ^ -1))) >> 31)) & 2))) >> 31) & 1);
    int v961 = (int)((unsigned int)((int)((unsigned int)v735 >> 2)) >> 1);
    v840[v960] = v961;
    int * v842 = v731->cache_dirty;
    v842[v960] = 0;
    int * v844 = v731->cache_age;
    v844[v960] = 1;
    int * v846 = v731->cache_age;
    int v847 = v846[v960];
    int * v848 = v731->cache_age;
    int v849 = v848[v869];
    int * v850 = v731->cache_age;
    int v969 = v849 + ((int)((unsigned int)(v849 - v847) >> 31));
    v850[v869] = v969;
    int * v852 = v731->cache_age;
    int v853 = v852[v871];
    int * v854 = v731->cache_age;
    int v972 = v853 + ((int)((unsigned int)(v853 - v847) >> 31));
    v854[v871] = v972;
    int * v856 = v731->cache_age;
    v856[v960] = 0;
    v859 = v960;
  }
  int v975 = (v859 * 2) + (((int)((unsigned int)v735 >> 2)) & 1);
  int v860 = v746[v975];
  int * v861 = v731->regs;
  v861[14] = v860;
  struct StateT * v863 = slot_8(v731);
  return v863;
}

struct StateT * snippet(struct StateT * v0) {
  struct StateT * v1 = slot_0(v0);
  return v1;
}

struct StateT * slot_10(struct StateT * v658) {
  int v659 = v658->timer;
  int v667 = v659 + 1;
  v658->timer = v667;
  int * v661 = v658->regs;
  int v662 = v661[11];
  int * v663 = v658->regs;
  int v671 = v662 + -1;
  v663[11] = v671;
  struct StateT * v665 = slot_11(v658);
  return v665;
}

struct StateT * slot_1(struct StateT * v19) {
  int v20 = v19->timer;
  int v26 = v20 + 1;
  v19->timer = v26;
  int * v22 = v19->regs;
  v22[10] = 1;
  struct StateT * v24 = slot_2(v19);
  return v24;
}

struct StateT * slot_8(struct StateT * v981) {
  int v982 = v981->timer;
  int v1115 = v982 + 1;
  v981->timer = v1115;
  int * v984 = v981->regs;
  int v985 = v984[13];
  int * v986 = v981->cache_tags;
  int v1119 = (((int)((unsigned int)((int)((unsigned int)v985 >> 2)) >> 1)) & 1) * 2;
  int v987 = v986[v1119];
  int * v988 = v981->cache_tags;
  int v1121 = ((((int)((unsigned int)((int)((unsigned int)v985 >> 2)) >> 1)) & 1) * 2) + 1;
  int v989 = v988[v1121];
  int * v990 = v981->cache_tags;
  int v1123 = 4 + ((((int)((unsigned int)((int)((unsigned int)v985 >> 2)) >> 1)) & 3) * 2);
  int v991 = v990[v1123];
  int * v992 = v981->cache_tags;
  int v1125 = (4 + ((((int)((unsigned int)((int)((unsigned int)v985 >> 2)) >> 1)) & 3) * 2)) + 1;
  int v993 = v992[v1125];
  int v994 = v981->timer;
  int v1126 = v994 + ((100 ^ (((~(((v991 ^ ((int)((unsigned int)((int)((unsigned int)v985 >> 2)) >> 1))) | (-(v991 ^ ((int)((unsigned int)((int)((unsigned int)v985 >> 2)) >> 1))))) >> 31)) | (~(((v993 ^ ((int)((unsigned int)((int)((unsigned int)v985 >> 2)) >> 1))) | (-(v993 ^ ((int)((unsigned int)((int)((unsigned int)v985 >> 2)) >> 1))))) >> 31))) & 104)) ^ (((~(((v987 ^ ((int)((unsigned int)((int)((unsigned int)v985 >> 2)) >> 1))) | (-(v987 ^ ((int)((unsigned int)((int)((unsigned int)v985 >> 2)) >> 1))))) >> 31)) | (~(((v989 ^ ((int)((unsigned int)((int)((unsigned int)v985 >> 2)) >> 1))) | (-(v989 ^ ((int)((unsigned int)((int)((unsigned int)v985 >> 2)) >> 1))))) >> 31))) & (1 ^ (100 ^ (((~(((v991 ^ ((int)((unsigned int)((int)((unsigned int)v985 >> 2)) >> 1))) | (-(v991 ^ ((int)((unsigned int)((int)((unsigned int)v985 >> 2)) >> 1))))) >> 31)) | (~(((v993 ^ ((int)((unsigned int)((int)((unsigned int)v985 >> 2)) >> 1))) | (-(v993 ^ ((int)((unsigned int)((int)((unsigned int)v985 >> 2)) >> 1))))) >> 31))) & 104)))));
  v981->timer = v1126;
  int * v996 = v981->cache_vals;
  bool v1127 = !(((~(((v987 ^ ((int)((unsigned int)((int)((unsigned int)v985 >> 2)) >> 1))) | (-(v987 ^ ((int)((unsigned int)((int)((unsigned int)v985 >> 2)) >> 1))))) >> 31)) | (~(((v989 ^ ((int)((unsigned int)((int)((unsigned int)v985 >> 2)) >> 1))) | (-(v989 ^ ((int)((unsigned int)((int)((unsigned int)v985 >> 2)) >> 1))))) >> 31))) == 0);
  int v1109;
  if (v1127) {
    int * v997 = v981->cache_age;
    int v1129 = ((((int)((unsigned int)((int)((unsigned int)v985 >> 2)) >> 1)) & 1) * 2) + ((~(((v989 ^ ((int)((unsigned int)((int)((unsigned int)v985 >> 2)) >> 1))) | (-(v989 ^ ((int)((unsigned int)((int)((unsigned int)v985 >> 2)) >> 1))))) >> 31)) & 1);
    int v998 = v997[v1129];
    int * v999 = v981->cache_age;
    int v1000 = v999[v1119];
    int * v1001 = v981->cache_age;
    int v1132 = v1000 + ((int)((unsigned int)(v1000 - v998) >> 31));
    v1001[v1119] = v1132;
    int * v1003 = v981->cache_age;
    int v1004 = v1003[v1121];
    int * v1005 = v981->cache_age;
    int v1135 = v1004 + ((int)((unsigned int)(v1004 - v998) >> 31));
    v1005[v1121] = v1135;
    int * v1007 = v981->cache_age;
    v1007[v1129] = 0;
    v1109 = v1129;
  } else {
    int * v1010 = v981->cache_age;
    int v1139 = (((int)((unsigned int)((int)((unsigned int)v985 >> 2)) >> 1)) & 1) * 2;
    int v1011 = v1010[v1139];
    int * v1012 = v981->cache_tags;
    int v1013 = v1012[v1139];
    int * v1014 = v981->cache_age;
    int v1015 = v1014[v1121];
    int * v1016 = v981->cache_tags;
    int v1017 = v1016[v1121];
    bool v1143 = !(((~(((v991 ^ ((int)((unsigned int)((int)((unsigned int)v985 >> 2)) >> 1))) | (-(v991 ^ ((int)((unsigned int)((int)((unsigned int)v985 >> 2)) >> 1))))) >> 31)) | (~(((v993 ^ ((int)((unsigned int)((int)((unsigned int)v985 >> 2)) >> 1))) | (-(v993 ^ ((int)((unsigned int)((int)((unsigned int)v985 >> 2)) >> 1))))) >> 31))) == 0);
    int v1081;
    if (v1143) {
      int * v1018 = v981->cache_age;
      int v1145 = (4 + ((((int)((unsigned int)((int)((unsigned int)v985 >> 2)) >> 1)) & 3) * 2)) + ((~(((v993 ^ ((int)((unsigned int)((int)((unsigned int)v985 >> 2)) >> 1))) | (-(v993 ^ ((int)((unsigned int)((int)((unsigned int)v985 >> 2)) >> 1))))) >> 31)) & 1);
      int v1019 = v1018[v1145];
      int * v1020 = v981->cache_age;
      int v1021 = v1020[v1123];
      int * v1022 = v981->cache_age;
      int v1148 = v1021 + ((int)((unsigned int)(v1021 - v1019) >> 31));
      v1022[v1123] = v1148;
      int * v1024 = v981->cache_age;
      int v1025 = v1024[v1125];
      int * v1026 = v981->cache_age;
      int v1151 = v1025 + ((int)((unsigned int)(v1025 - v1019) >> 31));
      v1026[v1125] = v1151;
      int * v1028 = v981->cache_age;
      v1028[v1145] = 0;
      v1081 = v1145;
    } else {
      int * v1031 = v981->cache_age;
      int v1155 = 4 + ((((int)((unsigned int)((int)((unsigned int)v985 >> 2)) >> 1)) & 3) * 2);
      int v1032 = v1031[v1155];
      int * v1033 = v981->cache_tags;
      int v1034 = v1033[v1155];
      int * v1035 = v981->cache_age;
      int v1036 = v1035[v1125];
      int * v1037 = v981->cache_tags;
      int v1038 = v1037[v1125];
      int * v1039 = v981->cache_dirty;
      int v1160 = (4 + ((((int)((unsigned int)((int)((unsigned int)v985 >> 2)) >> 1)) & 3) * 2)) + ((((v1032 + ((~(((v1034 ^ -1) | (-(v1034 ^ -1))) >> 31)) & 2)) - (v1036 + ((~(((v1038 ^ -1) | (-(v1038 ^ -1))) >> 31)) & 2))) >> 31) & 1);
      int v1040 = v1039[v1160];
      bool v1161 = !(v1040 == 0);
      if (v1161) {
        int * v1041 = v981->cache_tags;
        int v1042 = v1041[v1160];
        int * v1043 = v981->cache_vals;
        int v1164 = ((4 + ((((int)((unsigned int)((int)((unsigned int)v985 >> 2)) >> 1)) & 3) * 2)) + ((((v1032 + ((~(((v1034 ^ -1) | (-(v1034 ^ -1))) >> 31)) & 2)) - (v1036 + ((~(((v1038 ^ -1) | (-(v1038 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
        int v1044 = v1043[v1164];
        int * v1045 = v981->cache_vals;
        int v1166 = (((4 + ((((int)((unsigned int)((int)((unsigned int)v985 >> 2)) >> 1)) & 3) * 2)) + ((((v1032 + ((~(((v1034 ^ -1) | (-(v1034 ^ -1))) >> 31)) & 2)) - (v1036 + ((~(((v1038 ^ -1) | (-(v1038 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
        int v1046 = v1045[v1166];
        int * v1047 = v981->mem;
        int v1168 = v1042 * 2;
        v1047[v1168] = v1044;
        int * v1049 = v981->mem;
        int v1171 = (v1042 * 2) + 1;
        v1049[v1171] = v1046;
        ;
      } else {
        ;
      }
      int * v1054 = v981->mem;
      int v1176 = ((int)((unsigned int)((int)((unsigned int)v985 >> 2)) >> 1)) * 2;
      int v1055 = v1054[v1176];
      int * v1056 = v981->mem;
      int v1178 = (((int)((unsigned int)((int)((unsigned int)v985 >> 2)) >> 1)) * 2) + 1;
      int v1057 = v1056[v1178];
      int * v1058 = v981->cache_vals;
      int v1180 = ((4 + ((((int)((unsigned int)((int)((unsigned int)v985 >> 2)) >> 1)) & 3) * 2)) + ((((v1032 + ((~(((v1034 ^ -1) | (-(v1034 ^ -1))) >> 31)) & 2)) - (v1036 + ((~(((v1038 ^ -1) | (-(v1038 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
      v1058[v1180] = v1055;
      int * v1060 = v981->cache_vals;
      int v1183 = (((4 + ((((int)((unsigned int)((int)((unsigned int)v985 >> 2)) >> 1)) & 3) * 2)) + ((((v1032 + ((~(((v1034 ^ -1) | (-(v1034 ^ -1))) >> 31)) & 2)) - (v1036 + ((~(((v1038 ^ -1) | (-(v1038 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
      v1060[v1183] = v1057;
      int * v1062 = v981->cache_tags;
      int v1186 = (int)((unsigned int)((int)((unsigned int)v985 >> 2)) >> 1);
      v1062[v1160] = v1186;
      int * v1064 = v981->cache_dirty;
      v1064[v1160] = 0;
      int * v1066 = v981->cache_age;
      v1066[v1160] = 1;
      int * v1068 = v981->cache_age;
      int v1069 = v1068[v1160];
      int * v1070 = v981->cache_age;
      int v1071 = v1070[v1123];
      int * v1072 = v981->cache_age;
      int v1194 = v1071 + ((int)((unsigned int)(v1071 - v1069) >> 31));
      v1072[v1123] = v1194;
      int * v1074 = v981->cache_age;
      int v1075 = v1074[v1125];
      int * v1076 = v981->cache_age;
      int v1197 = v1075 + ((int)((unsigned int)(v1075 - v1069) >> 31));
      v1076[v1125] = v1197;
      int * v1078 = v981->cache_age;
      v1078[v1160] = 0;
      v1081 = v1160;
    }
    int * v1082 = v981->cache_vals;
    int v1200 = v1081 * 2;
    int v1083 = v1082[v1200];
    int * v1084 = v981->cache_vals;
    int v1202 = (v1081 * 2) + 1;
    int v1085 = v1084[v1202];
    int * v1086 = v981->cache_vals;
    int v1204 = (((((int)((unsigned int)((int)((unsigned int)v985 >> 2)) >> 1)) & 1) * 2) + ((((v1011 + ((~(((v1013 ^ -1) | (-(v1013 ^ -1))) >> 31)) & 2)) - (v1015 + ((~(((v1017 ^ -1) | (-(v1017 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
    v1086[v1204] = v1083;
    int * v1088 = v981->cache_vals;
    int v1207 = ((((((int)((unsigned int)((int)((unsigned int)v985 >> 2)) >> 1)) & 1) * 2) + ((((v1011 + ((~(((v1013 ^ -1) | (-(v1013 ^ -1))) >> 31)) & 2)) - (v1015 + ((~(((v1017 ^ -1) | (-(v1017 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
    v1088[v1207] = v1085;
    int * v1090 = v981->cache_tags;
    int v1210 = ((((int)((unsigned int)((int)((unsigned int)v985 >> 2)) >> 1)) & 1) * 2) + ((((v1011 + ((~(((v1013 ^ -1) | (-(v1013 ^ -1))) >> 31)) & 2)) - (v1015 + ((~(((v1017 ^ -1) | (-(v1017 ^ -1))) >> 31)) & 2))) >> 31) & 1);
    int v1211 = (int)((unsigned int)((int)((unsigned int)v985 >> 2)) >> 1);
    v1090[v1210] = v1211;
    int * v1092 = v981->cache_dirty;
    v1092[v1210] = 0;
    int * v1094 = v981->cache_age;
    v1094[v1210] = 1;
    int * v1096 = v981->cache_age;
    int v1097 = v1096[v1210];
    int * v1098 = v981->cache_age;
    int v1099 = v1098[v1119];
    int * v1100 = v981->cache_age;
    int v1219 = v1099 + ((int)((unsigned int)(v1099 - v1097) >> 31));
    v1100[v1119] = v1219;
    int * v1102 = v981->cache_age;
    int v1103 = v1102[v1121];
    int * v1104 = v981->cache_age;
    int v1222 = v1103 + ((int)((unsigned int)(v1103 - v1097) >> 31));
    v1104[v1121] = v1222;
    int * v1106 = v981->cache_age;
    v1106[v1210] = 0;
    v1109 = v1210;
  }
  int v1225 = (v1109 * 2) + (((int)((unsigned int)v985 >> 2)) & 1);
  int v1110 = v996[v1225];
  int * v1111 = v981->regs;
  v1111[15] = v1110;
  struct StateT * v1113 = slot_9(v981);
  return v1113;
}

struct StateT * slot_13(struct StateT * v711) {
  int v712 = v711->timer;
  int v722 = v712 + 1;
  v711->timer = v722;
  int * v714 = v711->regs;
  int v715 = v714[11];
  bool v725 = !(v715 == 0);
  struct StateT * v720;
  if (v725) {
    struct StateT * v716 = slot_7(v711);
    v720 = v716;
  } else {
    struct StateT * v718 = slot_14(v711);
    v720 = v718;
  }
  return v720;
}

struct StateT * slot_15(struct StateT * v645) {
  int v646 = v645->timer;
  int v652 = v646 + 1;
  v645->timer = v652;
  int * v648 = v645->regs;
  v648[10] = 0;
  struct StateT * v650 = slot_16(v645);
  return v650;
}

struct StateT * slot_9(struct StateT * v1231) {
  int * v1232 = v1231->saved_regs;
  int * v1233 = v1231->regs;
  int v1234 = v1233[11];
  v1232[11] = v1234;
  int v1236 = v1231->timer;
  int v1298 = v1236 + 1;
  v1231->timer = v1298;
  int * v1238 = v1231->regs;
  int v1239 = v1238[11];
  int * v1240 = v1231->regs;
  int v1301 = v1239 + -1;
  v1240[11] = v1301;
  int v1242 = v1231->timer;
  int v1302 = v1242 + 1;
  v1231->timer = v1302;
  int * v1244 = v1231->regs;
  int v1245 = v1244[12];
  int * v1246 = v1231->regs;
  int v1306 = v1245 + 4;
  v1246[12] = v1306;
  int v1248 = v1231->timer;
  int v1307 = v1248 + 1;
  v1231->timer = v1307;
  int * v1250 = v1231->regs;
  int v1251 = v1250[13];
  int * v1252 = v1231->regs;
  int v1311 = v1251 + 4;
  v1252[13] = v1311;
  int * v1254 = v1231->regs;
  int v1255 = v1254[14];
  int * v1256 = v1231->regs;
  int v1257 = v1256[15];
  bool v1316 = !(v1255 == v1257);
  struct StateT * v1292;
  if (v1316) {
    int v1258 = v1231->timer;
    int v1317 = v1258 + 15;
    v1231->timer = v1317;
    int * v1260 = v1231->saved_regs;
    int v1261 = v1260[12];
    int * v1262 = v1231->regs;
    v1262[12] = v1261;
    int * v1264 = v1231->saved_regs;
    int v1265 = v1264[13];
    int * v1266 = v1231->regs;
    v1266[13] = v1265;
    int * v1268 = v1231->saved_regs;
    int v1269 = v1268[14];
    int * v1270 = v1231->regs;
    v1270[14] = v1269;
    int * v1272 = v1231->saved_regs;
    int v1273 = v1272[15];
    int * v1274 = v1231->regs;
    v1274[15] = v1273;
    int * v1276 = v1231->saved_regs;
    int v1277 = v1276[11];
    int * v1278 = v1231->regs;
    v1278[11] = v1277;
    struct StateT * v1280 = slot_15(v1231);
    v1292 = v1280;
  } else {
    int v1282 = v1231->timer;
    int v1335 = v1282 + 1;
    v1231->timer = v1335;
    int * v1284 = v1231->regs;
    int v1285 = v1284[11];
    bool v1337 = !(v1285 == 0);
    struct StateT * v1290;
    if (v1337) {
      struct StateT * v1286 = slot_7(v1231);
      v1290 = v1286;
    } else {
      struct StateT * v1288 = slot_14(v1231);
      v1290 = v1288;
    }
    v1292 = v1290;
  }
  return v1292;
}

struct StateT * slot_11(struct StateT * v679) {
  int v680 = v679->timer;
  int v688 = v680 + 1;
  v679->timer = v688;
  int * v682 = v679->regs;
  int v683 = v682[12];
  int * v684 = v679->regs;
  int v692 = v683 + 4;
  v684[12] = v692;
  struct StateT * v686 = slot_12(v679);
  return v686;
}

struct StateT * slot_0(struct StateT * v2) {
  int v3 = v2->timer;
  int v11 = v3 + 1;
  v2->timer = v11;
  int * v5 = v2->regs;
  int v6 = v5[10];
  int * v7 = v2->regs;
  v7[11] = v6;
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
  
  int n = bounded(0, 4);
  s1.regs[10] = n;
  s2.regs[10] = n;
  // guess, the attacker's: the same draw in both states
  for (int i=0; i<4; i++) {
    int v = bounded(0, 20);
    s1.mem[4 + i] = v;
    s2.mem[4 + i] = v;
  }
  
  // secret, secret: a different draw in each state
  for (int i=0; i<4; i++) {
    s1.mem[0 + i] = bounded(0, 20);
    s2.mem[0 + i] = bounded(0, 20);
  }
  struct StateT *s1_ = snippet(&s1);
  struct StateT *s2_ = snippet(&s2);
  koika_assert(s1_->timer==s2_->timer, "timing leak");
  return 0;
}