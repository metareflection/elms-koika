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

struct StateT * slot_12(struct StateT * v694);
struct StateT * slot_14(struct StateT * v91);
struct StateT * slot_6(struct StateT * v111);
struct StateT * slot_5(struct StateT * v67);
struct StateT * slot_2(struct StateT * v28);
struct StateT * slot_7(struct StateT * v132);
struct StateT * slot_3(struct StateT * v41);
struct StateT * snippet(struct StateT * v0);
struct StateT * slot_10(struct StateT * v653);
struct StateT * slot_1(struct StateT * v15);
struct StateT * slot_8(struct StateT * v382);
struct StateT * slot_4(struct StateT * v54);
struct StateT * slot_13(struct StateT * v710);
struct StateT * slot_9(struct StateT * v403);
struct StateT * slot_11(struct StateT * v674);
struct StateT * slot_0(struct StateT * v2);
struct StateT * slot_12(struct StateT * v694) {
  int v695 = v694->timer;
  int v703 = v695 + 1;
  v694->timer = v703;
  int * v697 = v694->regs;
  int v698 = v697[14];
  int * v699 = v694->regs;
  int v707 = v698 + 4;
  v699[14] = v707;
  struct StateT * v701 = slot_13(v694);
  return v701;
}

struct StateT * slot_14(struct StateT * v91) {
  int v92 = v91->timer;
  int v102 = v92 + 1;
  v91->timer = v102;
  int * v94 = v91->regs;
  int v95 = v94[5];
  bool v105 = (v95 ^ -2147483648) < -2147483647;
  int v98;
  if (v105) {
    v98 = 1;
  } else {
    v98 = 0;
  }
  int * v99 = v91->regs;
  v99[11] = v98;
  return v91;
}

struct StateT * slot_6(struct StateT * v111) {
  int v112 = v111->timer;
  int v122 = v112 + 1;
  v111->timer = v122;
  int * v114 = v111->regs;
  int v115 = v114[12];
  int * v116 = v111->regs;
  int v117 = v116[14];
  int * v118 = v111->regs;
  int v129 = v115 + v117;
  v118[6] = v129;
  struct StateT * v120 = slot_7(v111);
  return v120;
}

struct StateT * slot_5(struct StateT * v67) {
  int v68 = v67->timer;
  int v80 = v68 + 1;
  v67->timer = v80;
  int * v70 = v67->regs;
  int v71 = v70[14];
  int * v72 = v67->regs;
  int v73 = v72[15];
  bool v85 = v71 >= v73;
  struct StateT * v78;
  if (v85) {
    struct StateT * v74 = slot_14(v67);
    v78 = v74;
  } else {
    struct StateT * v76 = slot_6(v67);
    v78 = v76;
  }
  return v78;
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

struct StateT * slot_7(struct StateT * v132) {
  int v133 = v132->timer;
  int v266 = v133 + 1;
  v132->timer = v266;
  int * v135 = v132->regs;
  int v136 = v135[6];
  int * v137 = v132->cache_tags;
  int v270 = (((int)((unsigned int)((int)((unsigned int)v136 >> 2)) >> 1)) & 1) * 2;
  int v138 = v137[v270];
  int * v139 = v132->cache_tags;
  int v272 = ((((int)((unsigned int)((int)((unsigned int)v136 >> 2)) >> 1)) & 1) * 2) + 1;
  int v140 = v139[v272];
  int * v141 = v132->cache_tags;
  int v274 = 4 + ((((int)((unsigned int)((int)((unsigned int)v136 >> 2)) >> 1)) & 3) * 2);
  int v142 = v141[v274];
  int * v143 = v132->cache_tags;
  int v276 = (4 + ((((int)((unsigned int)((int)((unsigned int)v136 >> 2)) >> 1)) & 3) * 2)) + 1;
  int v144 = v143[v276];
  int v145 = v132->timer;
  int v277 = v145 + ((100 ^ (((~(((v142 ^ ((int)((unsigned int)((int)((unsigned int)v136 >> 2)) >> 1))) | (-(v142 ^ ((int)((unsigned int)((int)((unsigned int)v136 >> 2)) >> 1))))) >> 31)) | (~(((v144 ^ ((int)((unsigned int)((int)((unsigned int)v136 >> 2)) >> 1))) | (-(v144 ^ ((int)((unsigned int)((int)((unsigned int)v136 >> 2)) >> 1))))) >> 31))) & 104)) ^ (((~(((v138 ^ ((int)((unsigned int)((int)((unsigned int)v136 >> 2)) >> 1))) | (-(v138 ^ ((int)((unsigned int)((int)((unsigned int)v136 >> 2)) >> 1))))) >> 31)) | (~(((v140 ^ ((int)((unsigned int)((int)((unsigned int)v136 >> 2)) >> 1))) | (-(v140 ^ ((int)((unsigned int)((int)((unsigned int)v136 >> 2)) >> 1))))) >> 31))) & (1 ^ (100 ^ (((~(((v142 ^ ((int)((unsigned int)((int)((unsigned int)v136 >> 2)) >> 1))) | (-(v142 ^ ((int)((unsigned int)((int)((unsigned int)v136 >> 2)) >> 1))))) >> 31)) | (~(((v144 ^ ((int)((unsigned int)((int)((unsigned int)v136 >> 2)) >> 1))) | (-(v144 ^ ((int)((unsigned int)((int)((unsigned int)v136 >> 2)) >> 1))))) >> 31))) & 104)))));
  v132->timer = v277;
  int * v147 = v132->cache_vals;
  bool v278 = !(((~(((v138 ^ ((int)((unsigned int)((int)((unsigned int)v136 >> 2)) >> 1))) | (-(v138 ^ ((int)((unsigned int)((int)((unsigned int)v136 >> 2)) >> 1))))) >> 31)) | (~(((v140 ^ ((int)((unsigned int)((int)((unsigned int)v136 >> 2)) >> 1))) | (-(v140 ^ ((int)((unsigned int)((int)((unsigned int)v136 >> 2)) >> 1))))) >> 31))) == 0);
  int v260;
  if (v278) {
    int * v148 = v132->cache_age;
    int v280 = ((((int)((unsigned int)((int)((unsigned int)v136 >> 2)) >> 1)) & 1) * 2) + ((~(((v140 ^ ((int)((unsigned int)((int)((unsigned int)v136 >> 2)) >> 1))) | (-(v140 ^ ((int)((unsigned int)((int)((unsigned int)v136 >> 2)) >> 1))))) >> 31)) & 1);
    int v149 = v148[v280];
    int * v150 = v132->cache_age;
    int v151 = v150[v270];
    int * v152 = v132->cache_age;
    int v283 = v151 + ((int)((unsigned int)(v151 - v149) >> 31));
    v152[v270] = v283;
    int * v154 = v132->cache_age;
    int v155 = v154[v272];
    int * v156 = v132->cache_age;
    int v286 = v155 + ((int)((unsigned int)(v155 - v149) >> 31));
    v156[v272] = v286;
    int * v158 = v132->cache_age;
    v158[v280] = 0;
    v260 = v280;
  } else {
    int * v161 = v132->cache_age;
    int v290 = (((int)((unsigned int)((int)((unsigned int)v136 >> 2)) >> 1)) & 1) * 2;
    int v162 = v161[v290];
    int * v163 = v132->cache_tags;
    int v164 = v163[v290];
    int * v165 = v132->cache_age;
    int v166 = v165[v272];
    int * v167 = v132->cache_tags;
    int v168 = v167[v272];
    bool v294 = !(((~(((v142 ^ ((int)((unsigned int)((int)((unsigned int)v136 >> 2)) >> 1))) | (-(v142 ^ ((int)((unsigned int)((int)((unsigned int)v136 >> 2)) >> 1))))) >> 31)) | (~(((v144 ^ ((int)((unsigned int)((int)((unsigned int)v136 >> 2)) >> 1))) | (-(v144 ^ ((int)((unsigned int)((int)((unsigned int)v136 >> 2)) >> 1))))) >> 31))) == 0);
    int v232;
    if (v294) {
      int * v169 = v132->cache_age;
      int v296 = (4 + ((((int)((unsigned int)((int)((unsigned int)v136 >> 2)) >> 1)) & 3) * 2)) + ((~(((v144 ^ ((int)((unsigned int)((int)((unsigned int)v136 >> 2)) >> 1))) | (-(v144 ^ ((int)((unsigned int)((int)((unsigned int)v136 >> 2)) >> 1))))) >> 31)) & 1);
      int v170 = v169[v296];
      int * v171 = v132->cache_age;
      int v172 = v171[v274];
      int * v173 = v132->cache_age;
      int v299 = v172 + ((int)((unsigned int)(v172 - v170) >> 31));
      v173[v274] = v299;
      int * v175 = v132->cache_age;
      int v176 = v175[v276];
      int * v177 = v132->cache_age;
      int v302 = v176 + ((int)((unsigned int)(v176 - v170) >> 31));
      v177[v276] = v302;
      int * v179 = v132->cache_age;
      v179[v296] = 0;
      v232 = v296;
    } else {
      int * v182 = v132->cache_age;
      int v306 = 4 + ((((int)((unsigned int)((int)((unsigned int)v136 >> 2)) >> 1)) & 3) * 2);
      int v183 = v182[v306];
      int * v184 = v132->cache_tags;
      int v185 = v184[v306];
      int * v186 = v132->cache_age;
      int v187 = v186[v276];
      int * v188 = v132->cache_tags;
      int v189 = v188[v276];
      int * v190 = v132->cache_dirty;
      int v311 = (4 + ((((int)((unsigned int)((int)((unsigned int)v136 >> 2)) >> 1)) & 3) * 2)) + ((((v183 + ((~(((v185 ^ -1) | (-(v185 ^ -1))) >> 31)) & 2)) - (v187 + ((~(((v189 ^ -1) | (-(v189 ^ -1))) >> 31)) & 2))) >> 31) & 1);
      int v191 = v190[v311];
      bool v312 = !(v191 == 0);
      if (v312) {
        int * v192 = v132->cache_tags;
        int v193 = v192[v311];
        int * v194 = v132->cache_vals;
        int v315 = ((4 + ((((int)((unsigned int)((int)((unsigned int)v136 >> 2)) >> 1)) & 3) * 2)) + ((((v183 + ((~(((v185 ^ -1) | (-(v185 ^ -1))) >> 31)) & 2)) - (v187 + ((~(((v189 ^ -1) | (-(v189 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
        int v195 = v194[v315];
        int * v196 = v132->cache_vals;
        int v317 = (((4 + ((((int)((unsigned int)((int)((unsigned int)v136 >> 2)) >> 1)) & 3) * 2)) + ((((v183 + ((~(((v185 ^ -1) | (-(v185 ^ -1))) >> 31)) & 2)) - (v187 + ((~(((v189 ^ -1) | (-(v189 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
        int v197 = v196[v317];
        int * v198 = v132->mem;
        int v319 = v193 * 2;
        v198[v319] = v195;
        int * v200 = v132->mem;
        int v322 = (v193 * 2) + 1;
        v200[v322] = v197;
        ;
      } else {
        ;
      }
      int * v205 = v132->mem;
      int v327 = ((int)((unsigned int)((int)((unsigned int)v136 >> 2)) >> 1)) * 2;
      int v206 = v205[v327];
      int * v207 = v132->mem;
      int v329 = (((int)((unsigned int)((int)((unsigned int)v136 >> 2)) >> 1)) * 2) + 1;
      int v208 = v207[v329];
      int * v209 = v132->cache_vals;
      int v331 = ((4 + ((((int)((unsigned int)((int)((unsigned int)v136 >> 2)) >> 1)) & 3) * 2)) + ((((v183 + ((~(((v185 ^ -1) | (-(v185 ^ -1))) >> 31)) & 2)) - (v187 + ((~(((v189 ^ -1) | (-(v189 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
      v209[v331] = v206;
      int * v211 = v132->cache_vals;
      int v334 = (((4 + ((((int)((unsigned int)((int)((unsigned int)v136 >> 2)) >> 1)) & 3) * 2)) + ((((v183 + ((~(((v185 ^ -1) | (-(v185 ^ -1))) >> 31)) & 2)) - (v187 + ((~(((v189 ^ -1) | (-(v189 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
      v211[v334] = v208;
      int * v213 = v132->cache_tags;
      int v337 = (int)((unsigned int)((int)((unsigned int)v136 >> 2)) >> 1);
      v213[v311] = v337;
      int * v215 = v132->cache_dirty;
      v215[v311] = 0;
      int * v217 = v132->cache_age;
      v217[v311] = 1;
      int * v219 = v132->cache_age;
      int v220 = v219[v311];
      int * v221 = v132->cache_age;
      int v222 = v221[v274];
      int * v223 = v132->cache_age;
      int v345 = v222 + ((int)((unsigned int)(v222 - v220) >> 31));
      v223[v274] = v345;
      int * v225 = v132->cache_age;
      int v226 = v225[v276];
      int * v227 = v132->cache_age;
      int v348 = v226 + ((int)((unsigned int)(v226 - v220) >> 31));
      v227[v276] = v348;
      int * v229 = v132->cache_age;
      v229[v311] = 0;
      v232 = v311;
    }
    int * v233 = v132->cache_vals;
    int v351 = v232 * 2;
    int v234 = v233[v351];
    int * v235 = v132->cache_vals;
    int v353 = (v232 * 2) + 1;
    int v236 = v235[v353];
    int * v237 = v132->cache_vals;
    int v355 = (((((int)((unsigned int)((int)((unsigned int)v136 >> 2)) >> 1)) & 1) * 2) + ((((v162 + ((~(((v164 ^ -1) | (-(v164 ^ -1))) >> 31)) & 2)) - (v166 + ((~(((v168 ^ -1) | (-(v168 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
    v237[v355] = v234;
    int * v239 = v132->cache_vals;
    int v358 = ((((((int)((unsigned int)((int)((unsigned int)v136 >> 2)) >> 1)) & 1) * 2) + ((((v162 + ((~(((v164 ^ -1) | (-(v164 ^ -1))) >> 31)) & 2)) - (v166 + ((~(((v168 ^ -1) | (-(v168 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
    v239[v358] = v236;
    int * v241 = v132->cache_tags;
    int v361 = ((((int)((unsigned int)((int)((unsigned int)v136 >> 2)) >> 1)) & 1) * 2) + ((((v162 + ((~(((v164 ^ -1) | (-(v164 ^ -1))) >> 31)) & 2)) - (v166 + ((~(((v168 ^ -1) | (-(v168 ^ -1))) >> 31)) & 2))) >> 31) & 1);
    int v362 = (int)((unsigned int)((int)((unsigned int)v136 >> 2)) >> 1);
    v241[v361] = v362;
    int * v243 = v132->cache_dirty;
    v243[v361] = 0;
    int * v245 = v132->cache_age;
    v245[v361] = 1;
    int * v247 = v132->cache_age;
    int v248 = v247[v361];
    int * v249 = v132->cache_age;
    int v250 = v249[v270];
    int * v251 = v132->cache_age;
    int v370 = v250 + ((int)((unsigned int)(v250 - v248) >> 31));
    v251[v270] = v370;
    int * v253 = v132->cache_age;
    int v254 = v253[v272];
    int * v255 = v132->cache_age;
    int v373 = v254 + ((int)((unsigned int)(v254 - v248) >> 31));
    v255[v272] = v373;
    int * v257 = v132->cache_age;
    v257[v361] = 0;
    v260 = v361;
  }
  int v376 = (v260 * 2) + (((int)((unsigned int)v136 >> 2)) & 1);
  int v261 = v147[v376];
  int * v262 = v132->regs;
  v262[7] = v261;
  struct StateT * v264 = slot_8(v132);
  return v264;
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

struct StateT * slot_10(struct StateT * v653) {
  int v654 = v653->timer;
  int v664 = v654 + 1;
  v653->timer = v664;
  int * v656 = v653->regs;
  int v657 = v656[7];
  int * v658 = v653->regs;
  int v659 = v658[9];
  int * v660 = v653->regs;
  int v671 = v657 ^ v659;
  v660[16] = v671;
  struct StateT * v662 = slot_11(v653);
  return v662;
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

struct StateT * slot_8(struct StateT * v382) {
  int v383 = v382->timer;
  int v393 = v383 + 1;
  v382->timer = v393;
  int * v385 = v382->regs;
  int v386 = v385[13];
  int * v387 = v382->regs;
  int v388 = v387[14];
  int * v389 = v382->regs;
  int v400 = v386 + v388;
  v389[8] = v400;
  struct StateT * v391 = slot_9(v382);
  return v391;
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

struct StateT * slot_13(struct StateT * v710) {
  int v711 = v710->timer;
  int v715 = v711 + 1;
  v710->timer = v715;
  struct StateT * v713 = slot_5(v710);
  return v713;
}

struct StateT * slot_9(struct StateT * v403) {
  int v404 = v403->timer;
  int v537 = v404 + 1;
  v403->timer = v537;
  int * v406 = v403->regs;
  int v407 = v406[8];
  int * v408 = v403->cache_tags;
  int v541 = (((int)((unsigned int)((int)((unsigned int)v407 >> 2)) >> 1)) & 1) * 2;
  int v409 = v408[v541];
  int * v410 = v403->cache_tags;
  int v543 = ((((int)((unsigned int)((int)((unsigned int)v407 >> 2)) >> 1)) & 1) * 2) + 1;
  int v411 = v410[v543];
  int * v412 = v403->cache_tags;
  int v545 = 4 + ((((int)((unsigned int)((int)((unsigned int)v407 >> 2)) >> 1)) & 3) * 2);
  int v413 = v412[v545];
  int * v414 = v403->cache_tags;
  int v547 = (4 + ((((int)((unsigned int)((int)((unsigned int)v407 >> 2)) >> 1)) & 3) * 2)) + 1;
  int v415 = v414[v547];
  int v416 = v403->timer;
  int v548 = v416 + ((100 ^ (((~(((v413 ^ ((int)((unsigned int)((int)((unsigned int)v407 >> 2)) >> 1))) | (-(v413 ^ ((int)((unsigned int)((int)((unsigned int)v407 >> 2)) >> 1))))) >> 31)) | (~(((v415 ^ ((int)((unsigned int)((int)((unsigned int)v407 >> 2)) >> 1))) | (-(v415 ^ ((int)((unsigned int)((int)((unsigned int)v407 >> 2)) >> 1))))) >> 31))) & 104)) ^ (((~(((v409 ^ ((int)((unsigned int)((int)((unsigned int)v407 >> 2)) >> 1))) | (-(v409 ^ ((int)((unsigned int)((int)((unsigned int)v407 >> 2)) >> 1))))) >> 31)) | (~(((v411 ^ ((int)((unsigned int)((int)((unsigned int)v407 >> 2)) >> 1))) | (-(v411 ^ ((int)((unsigned int)((int)((unsigned int)v407 >> 2)) >> 1))))) >> 31))) & (1 ^ (100 ^ (((~(((v413 ^ ((int)((unsigned int)((int)((unsigned int)v407 >> 2)) >> 1))) | (-(v413 ^ ((int)((unsigned int)((int)((unsigned int)v407 >> 2)) >> 1))))) >> 31)) | (~(((v415 ^ ((int)((unsigned int)((int)((unsigned int)v407 >> 2)) >> 1))) | (-(v415 ^ ((int)((unsigned int)((int)((unsigned int)v407 >> 2)) >> 1))))) >> 31))) & 104)))));
  v403->timer = v548;
  int * v418 = v403->cache_vals;
  bool v549 = !(((~(((v409 ^ ((int)((unsigned int)((int)((unsigned int)v407 >> 2)) >> 1))) | (-(v409 ^ ((int)((unsigned int)((int)((unsigned int)v407 >> 2)) >> 1))))) >> 31)) | (~(((v411 ^ ((int)((unsigned int)((int)((unsigned int)v407 >> 2)) >> 1))) | (-(v411 ^ ((int)((unsigned int)((int)((unsigned int)v407 >> 2)) >> 1))))) >> 31))) == 0);
  int v531;
  if (v549) {
    int * v419 = v403->cache_age;
    int v551 = ((((int)((unsigned int)((int)((unsigned int)v407 >> 2)) >> 1)) & 1) * 2) + ((~(((v411 ^ ((int)((unsigned int)((int)((unsigned int)v407 >> 2)) >> 1))) | (-(v411 ^ ((int)((unsigned int)((int)((unsigned int)v407 >> 2)) >> 1))))) >> 31)) & 1);
    int v420 = v419[v551];
    int * v421 = v403->cache_age;
    int v422 = v421[v541];
    int * v423 = v403->cache_age;
    int v554 = v422 + ((int)((unsigned int)(v422 - v420) >> 31));
    v423[v541] = v554;
    int * v425 = v403->cache_age;
    int v426 = v425[v543];
    int * v427 = v403->cache_age;
    int v557 = v426 + ((int)((unsigned int)(v426 - v420) >> 31));
    v427[v543] = v557;
    int * v429 = v403->cache_age;
    v429[v551] = 0;
    v531 = v551;
  } else {
    int * v432 = v403->cache_age;
    int v561 = (((int)((unsigned int)((int)((unsigned int)v407 >> 2)) >> 1)) & 1) * 2;
    int v433 = v432[v561];
    int * v434 = v403->cache_tags;
    int v435 = v434[v561];
    int * v436 = v403->cache_age;
    int v437 = v436[v543];
    int * v438 = v403->cache_tags;
    int v439 = v438[v543];
    bool v565 = !(((~(((v413 ^ ((int)((unsigned int)((int)((unsigned int)v407 >> 2)) >> 1))) | (-(v413 ^ ((int)((unsigned int)((int)((unsigned int)v407 >> 2)) >> 1))))) >> 31)) | (~(((v415 ^ ((int)((unsigned int)((int)((unsigned int)v407 >> 2)) >> 1))) | (-(v415 ^ ((int)((unsigned int)((int)((unsigned int)v407 >> 2)) >> 1))))) >> 31))) == 0);
    int v503;
    if (v565) {
      int * v440 = v403->cache_age;
      int v567 = (4 + ((((int)((unsigned int)((int)((unsigned int)v407 >> 2)) >> 1)) & 3) * 2)) + ((~(((v415 ^ ((int)((unsigned int)((int)((unsigned int)v407 >> 2)) >> 1))) | (-(v415 ^ ((int)((unsigned int)((int)((unsigned int)v407 >> 2)) >> 1))))) >> 31)) & 1);
      int v441 = v440[v567];
      int * v442 = v403->cache_age;
      int v443 = v442[v545];
      int * v444 = v403->cache_age;
      int v570 = v443 + ((int)((unsigned int)(v443 - v441) >> 31));
      v444[v545] = v570;
      int * v446 = v403->cache_age;
      int v447 = v446[v547];
      int * v448 = v403->cache_age;
      int v573 = v447 + ((int)((unsigned int)(v447 - v441) >> 31));
      v448[v547] = v573;
      int * v450 = v403->cache_age;
      v450[v567] = 0;
      v503 = v567;
    } else {
      int * v453 = v403->cache_age;
      int v577 = 4 + ((((int)((unsigned int)((int)((unsigned int)v407 >> 2)) >> 1)) & 3) * 2);
      int v454 = v453[v577];
      int * v455 = v403->cache_tags;
      int v456 = v455[v577];
      int * v457 = v403->cache_age;
      int v458 = v457[v547];
      int * v459 = v403->cache_tags;
      int v460 = v459[v547];
      int * v461 = v403->cache_dirty;
      int v582 = (4 + ((((int)((unsigned int)((int)((unsigned int)v407 >> 2)) >> 1)) & 3) * 2)) + ((((v454 + ((~(((v456 ^ -1) | (-(v456 ^ -1))) >> 31)) & 2)) - (v458 + ((~(((v460 ^ -1) | (-(v460 ^ -1))) >> 31)) & 2))) >> 31) & 1);
      int v462 = v461[v582];
      bool v583 = !(v462 == 0);
      if (v583) {
        int * v463 = v403->cache_tags;
        int v464 = v463[v582];
        int * v465 = v403->cache_vals;
        int v586 = ((4 + ((((int)((unsigned int)((int)((unsigned int)v407 >> 2)) >> 1)) & 3) * 2)) + ((((v454 + ((~(((v456 ^ -1) | (-(v456 ^ -1))) >> 31)) & 2)) - (v458 + ((~(((v460 ^ -1) | (-(v460 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
        int v466 = v465[v586];
        int * v467 = v403->cache_vals;
        int v588 = (((4 + ((((int)((unsigned int)((int)((unsigned int)v407 >> 2)) >> 1)) & 3) * 2)) + ((((v454 + ((~(((v456 ^ -1) | (-(v456 ^ -1))) >> 31)) & 2)) - (v458 + ((~(((v460 ^ -1) | (-(v460 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
        int v468 = v467[v588];
        int * v469 = v403->mem;
        int v590 = v464 * 2;
        v469[v590] = v466;
        int * v471 = v403->mem;
        int v593 = (v464 * 2) + 1;
        v471[v593] = v468;
        ;
      } else {
        ;
      }
      int * v476 = v403->mem;
      int v598 = ((int)((unsigned int)((int)((unsigned int)v407 >> 2)) >> 1)) * 2;
      int v477 = v476[v598];
      int * v478 = v403->mem;
      int v600 = (((int)((unsigned int)((int)((unsigned int)v407 >> 2)) >> 1)) * 2) + 1;
      int v479 = v478[v600];
      int * v480 = v403->cache_vals;
      int v602 = ((4 + ((((int)((unsigned int)((int)((unsigned int)v407 >> 2)) >> 1)) & 3) * 2)) + ((((v454 + ((~(((v456 ^ -1) | (-(v456 ^ -1))) >> 31)) & 2)) - (v458 + ((~(((v460 ^ -1) | (-(v460 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
      v480[v602] = v477;
      int * v482 = v403->cache_vals;
      int v605 = (((4 + ((((int)((unsigned int)((int)((unsigned int)v407 >> 2)) >> 1)) & 3) * 2)) + ((((v454 + ((~(((v456 ^ -1) | (-(v456 ^ -1))) >> 31)) & 2)) - (v458 + ((~(((v460 ^ -1) | (-(v460 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
      v482[v605] = v479;
      int * v484 = v403->cache_tags;
      int v608 = (int)((unsigned int)((int)((unsigned int)v407 >> 2)) >> 1);
      v484[v582] = v608;
      int * v486 = v403->cache_dirty;
      v486[v582] = 0;
      int * v488 = v403->cache_age;
      v488[v582] = 1;
      int * v490 = v403->cache_age;
      int v491 = v490[v582];
      int * v492 = v403->cache_age;
      int v493 = v492[v545];
      int * v494 = v403->cache_age;
      int v616 = v493 + ((int)((unsigned int)(v493 - v491) >> 31));
      v494[v545] = v616;
      int * v496 = v403->cache_age;
      int v497 = v496[v547];
      int * v498 = v403->cache_age;
      int v619 = v497 + ((int)((unsigned int)(v497 - v491) >> 31));
      v498[v547] = v619;
      int * v500 = v403->cache_age;
      v500[v582] = 0;
      v503 = v582;
    }
    int * v504 = v403->cache_vals;
    int v622 = v503 * 2;
    int v505 = v504[v622];
    int * v506 = v403->cache_vals;
    int v624 = (v503 * 2) + 1;
    int v507 = v506[v624];
    int * v508 = v403->cache_vals;
    int v626 = (((((int)((unsigned int)((int)((unsigned int)v407 >> 2)) >> 1)) & 1) * 2) + ((((v433 + ((~(((v435 ^ -1) | (-(v435 ^ -1))) >> 31)) & 2)) - (v437 + ((~(((v439 ^ -1) | (-(v439 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
    v508[v626] = v505;
    int * v510 = v403->cache_vals;
    int v629 = ((((((int)((unsigned int)((int)((unsigned int)v407 >> 2)) >> 1)) & 1) * 2) + ((((v433 + ((~(((v435 ^ -1) | (-(v435 ^ -1))) >> 31)) & 2)) - (v437 + ((~(((v439 ^ -1) | (-(v439 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
    v510[v629] = v507;
    int * v512 = v403->cache_tags;
    int v632 = ((((int)((unsigned int)((int)((unsigned int)v407 >> 2)) >> 1)) & 1) * 2) + ((((v433 + ((~(((v435 ^ -1) | (-(v435 ^ -1))) >> 31)) & 2)) - (v437 + ((~(((v439 ^ -1) | (-(v439 ^ -1))) >> 31)) & 2))) >> 31) & 1);
    int v633 = (int)((unsigned int)((int)((unsigned int)v407 >> 2)) >> 1);
    v512[v632] = v633;
    int * v514 = v403->cache_dirty;
    v514[v632] = 0;
    int * v516 = v403->cache_age;
    v516[v632] = 1;
    int * v518 = v403->cache_age;
    int v519 = v518[v632];
    int * v520 = v403->cache_age;
    int v521 = v520[v541];
    int * v522 = v403->cache_age;
    int v641 = v521 + ((int)((unsigned int)(v521 - v519) >> 31));
    v522[v541] = v641;
    int * v524 = v403->cache_age;
    int v525 = v524[v543];
    int * v526 = v403->cache_age;
    int v644 = v525 + ((int)((unsigned int)(v525 - v519) >> 31));
    v526[v543] = v644;
    int * v528 = v403->cache_age;
    v528[v632] = 0;
    v531 = v632;
  }
  int v647 = (v531 * 2) + (((int)((unsigned int)v407 >> 2)) & 1);
  int v532 = v418[v647];
  int * v533 = v403->regs;
  v533[9] = v532;
  struct StateT * v535 = slot_10(v403);
  return v535;
}

struct StateT * slot_11(struct StateT * v674) {
  int v675 = v674->timer;
  int v685 = v675 + 1;
  v674->timer = v685;
  int * v677 = v674->regs;
  int v678 = v677[5];
  int * v679 = v674->regs;
  int v680 = v679[16];
  int * v681 = v674->regs;
  int v691 = v678 | v680;
  v681[5] = v691;
  struct StateT * v683 = slot_12(v674);
  return v683;
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
    s1.mem[SECRET_OFFSET+i] = bounded(0, 20);
    s2.mem[SECRET_OFFSET+i] = bounded(0, 20);
  }
  struct StateT *s1_ = snippet(&s1);
  struct StateT *s2_ = snippet(&s2);
  koika_assert(s1_->timer==s2_->timer, "timing leak");
  return 0;
}