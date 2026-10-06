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

struct StateT * slot_12(struct StateT * v592);
struct StateT * slot_14(struct StateT * v682);
struct StateT * slot_6(struct StateT * v75);
struct StateT * slot_16(struct StateT * v696);
struct StateT * slot_5(struct StateT * v67);
struct StateT * slot_2(struct StateT * v28);
struct StateT * slot_7(struct StateT * v99);
struct StateT * slot_3(struct StateT * v41);
struct StateT * snippet(struct StateT * v0);
struct StateT * slot_10(struct StateT * v545);
struct StateT * slot_1(struct StateT * v15);
struct StateT * slot_8(struct StateT * v310);
struct StateT * slot_4(struct StateT * v54);
struct StateT * slot_13(struct StateT * v662);
struct StateT * slot_9(struct StateT * v334);
struct StateT * slot_11(struct StateT * v569);
struct StateT * slot_0(struct StateT * v2);
struct StateT * slot_12(struct StateT * v592) {
  int * v593 = v592->regs;
  int v594 = v593[14];
  int v595 = v593[15];
  bool v631 = v594 >= v595;
  struct StateT * v626;
  if (v631) {
    int v596 = v592->timer;
    int v632 = v596 + 15;
    v592->timer = v632;
    int * v598 = v592->saved_regs;
    int v599 = v598[6];
    int * v600 = v592->regs;
    v600[6] = v599;
    int * v602 = v592->saved_regs;
    int v603 = v602[7];
    int * v604 = v592->regs;
    v604[7] = v603;
    int * v606 = v592->saved_regs;
    int v607 = v606[8];
    int * v608 = v592->regs;
    v608[8] = v607;
    int * v610 = v592->saved_regs;
    int v611 = v610[9];
    int * v612 = v592->regs;
    v612[9] = v611;
    int * v614 = v592->saved_regs;
    int v615 = v614[16];
    int * v616 = v592->regs;
    v616[16] = v615;
    int * v618 = v592->saved_regs;
    int v619 = v618[5];
    int * v620 = v592->regs;
    v620[5] = v619;
    struct StateT * v622 = slot_13(v592);
    v626 = v622;
  } else {
    struct StateT * v624 = slot_14(v592);
    v626 = v624;
  }
  return v626;
}

struct StateT * slot_14(struct StateT * v682) {
  int v683 = v682->timer;
  int v690 = v683 + 1;
  v682->timer = v690;
  int * v685 = v682->regs;
  int v686 = v685[14];
  int v693 = v686 + 4;
  v685[14] = v693;
  struct StateT * v688 = slot_16(v682);
  return v688;
}

struct StateT * slot_6(struct StateT * v75) {
  int * v76 = v75->saved_regs;
  int * v77 = v75->regs;
  int v78 = v77[6];
  v76[6] = v78;
  int v80 = v75->timer;
  int v92 = v80 + 1;
  v75->timer = v92;
  int * v82 = v75->regs;
  int v83 = v82[12];
  int v84 = v82[14];
  int v96 = v83 + v84;
  v82[6] = v96;
  struct StateT * v86 = slot_7(v75);
  return v86;
}

struct StateT * slot_16(struct StateT * v696) {
  int v697 = v696->timer;
  int v701 = v697 + 1;
  v696->timer = v701;
  struct StateT * v699 = slot_5(v696);
  return v699;
}

struct StateT * slot_5(struct StateT * v67) {
  int v68 = v67->timer;
  int v72 = v68 + 1;
  v67->timer = v72;
  struct StateT * v70 = slot_6(v67);
  return v70;
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

struct StateT * slot_7(struct StateT * v99) {
  int * v100 = v99->saved_regs;
  int * v101 = v99->regs;
  int v102 = v101[7];
  v100[7] = v102;
  int v104 = v99->timer;
  int v218 = v104 + 1;
  v99->timer = v218;
  int * v106 = v99->regs;
  int v107 = v106[6];
  int * v108 = v99->cache_tags;
  int v222 = (((int)((unsigned int)((int)((unsigned int)v107 >> 2)) >> 1)) & 1) * 2;
  int v109 = v108[v222];
  int v223 = ((((int)((unsigned int)((int)((unsigned int)v107 >> 2)) >> 1)) & 1) * 2) + 1;
  int v110 = v108[v223];
  int v224 = 4 + ((((int)((unsigned int)((int)((unsigned int)v107 >> 2)) >> 1)) & 3) * 2);
  int v111 = v108[v224];
  int v225 = (4 + ((((int)((unsigned int)((int)((unsigned int)v107 >> 2)) >> 1)) & 3) * 2)) + 1;
  int v112 = v108[v225];
  int v113 = v99->timer;
  int v226 = v113 + ((100 ^ (((~(((v111 ^ ((int)((unsigned int)((int)((unsigned int)v107 >> 2)) >> 1))) | (-(v111 ^ ((int)((unsigned int)((int)((unsigned int)v107 >> 2)) >> 1))))) >> 31)) | (~(((v112 ^ ((int)((unsigned int)((int)((unsigned int)v107 >> 2)) >> 1))) | (-(v112 ^ ((int)((unsigned int)((int)((unsigned int)v107 >> 2)) >> 1))))) >> 31))) & 104)) ^ (((~(((v109 ^ ((int)((unsigned int)((int)((unsigned int)v107 >> 2)) >> 1))) | (-(v109 ^ ((int)((unsigned int)((int)((unsigned int)v107 >> 2)) >> 1))))) >> 31)) | (~(((v110 ^ ((int)((unsigned int)((int)((unsigned int)v107 >> 2)) >> 1))) | (-(v110 ^ ((int)((unsigned int)((int)((unsigned int)v107 >> 2)) >> 1))))) >> 31))) & (1 ^ (100 ^ (((~(((v111 ^ ((int)((unsigned int)((int)((unsigned int)v107 >> 2)) >> 1))) | (-(v111 ^ ((int)((unsigned int)((int)((unsigned int)v107 >> 2)) >> 1))))) >> 31)) | (~(((v112 ^ ((int)((unsigned int)((int)((unsigned int)v107 >> 2)) >> 1))) | (-(v112 ^ ((int)((unsigned int)((int)((unsigned int)v107 >> 2)) >> 1))))) >> 31))) & 104)))));
  v99->timer = v226;
  int * v115 = v99->cache_vals;
  bool v227 = !(((~(((v109 ^ ((int)((unsigned int)((int)((unsigned int)v107 >> 2)) >> 1))) | (-(v109 ^ ((int)((unsigned int)((int)((unsigned int)v107 >> 2)) >> 1))))) >> 31)) | (~(((v110 ^ ((int)((unsigned int)((int)((unsigned int)v107 >> 2)) >> 1))) | (-(v110 ^ ((int)((unsigned int)((int)((unsigned int)v107 >> 2)) >> 1))))) >> 31))) == 0);
  int v208;
  if (v227) {
    int * v116 = v99->cache_age;
    int v229 = ((((int)((unsigned int)((int)((unsigned int)v107 >> 2)) >> 1)) & 1) * 2) + ((~(((v110 ^ ((int)((unsigned int)((int)((unsigned int)v107 >> 2)) >> 1))) | (-(v110 ^ ((int)((unsigned int)((int)((unsigned int)v107 >> 2)) >> 1))))) >> 31)) & 1);
    int v117 = v116[v229];
    int v118 = v116[v222];
    int v230 = v118 + ((int)((unsigned int)(v118 - v117) >> 31));
    v116[v222] = v230;
    int * v120 = v99->cache_age;
    int v121 = v120[v223];
    int v232 = v121 + ((int)((unsigned int)(v121 - v117) >> 31));
    v120[v223] = v232;
    int * v123 = v99->cache_age;
    v123[v229] = 0;
    v208 = v229;
  } else {
    int * v126 = v99->cache_age;
    int v236 = (((int)((unsigned int)((int)((unsigned int)v107 >> 2)) >> 1)) & 1) * 2;
    int v127 = v126[v236];
    int * v128 = v99->cache_tags;
    int v129 = v128[v236];
    int v130 = v126[v223];
    int v131 = v128[v223];
    bool v238 = !(((~(((v111 ^ ((int)((unsigned int)((int)((unsigned int)v107 >> 2)) >> 1))) | (-(v111 ^ ((int)((unsigned int)((int)((unsigned int)v107 >> 2)) >> 1))))) >> 31)) | (~(((v112 ^ ((int)((unsigned int)((int)((unsigned int)v107 >> 2)) >> 1))) | (-(v112 ^ ((int)((unsigned int)((int)((unsigned int)v107 >> 2)) >> 1))))) >> 31))) == 0);
    int v185;
    if (v238) {
      int * v132 = v99->cache_age;
      int v240 = (4 + ((((int)((unsigned int)((int)((unsigned int)v107 >> 2)) >> 1)) & 3) * 2)) + ((~(((v112 ^ ((int)((unsigned int)((int)((unsigned int)v107 >> 2)) >> 1))) | (-(v112 ^ ((int)((unsigned int)((int)((unsigned int)v107 >> 2)) >> 1))))) >> 31)) & 1);
      int v133 = v132[v240];
      int v134 = v132[v224];
      int v241 = v134 + ((int)((unsigned int)(v134 - v133) >> 31));
      v132[v224] = v241;
      int * v136 = v99->cache_age;
      int v137 = v136[v225];
      int v243 = v137 + ((int)((unsigned int)(v137 - v133) >> 31));
      v136[v225] = v243;
      int * v139 = v99->cache_age;
      v139[v240] = 0;
      v185 = v240;
    } else {
      int * v142 = v99->cache_age;
      int v247 = 4 + ((((int)((unsigned int)((int)((unsigned int)v107 >> 2)) >> 1)) & 3) * 2);
      int v143 = v142[v247];
      int * v144 = v99->cache_tags;
      int v145 = v144[v247];
      int v146 = v142[v225];
      int v147 = v144[v225];
      int * v148 = v99->cache_dirty;
      int v250 = (4 + ((((int)((unsigned int)((int)((unsigned int)v107 >> 2)) >> 1)) & 3) * 2)) + ((((v143 + ((~(((v145 ^ -1) | (-(v145 ^ -1))) >> 31)) & 2)) - (v146 + ((~(((v147 ^ -1) | (-(v147 ^ -1))) >> 31)) & 2))) >> 31) & 1);
      int v149 = v148[v250];
      bool v251 = !(v149 == 0);
      if (v251) {
        int * v150 = v99->cache_tags;
        int v151 = v150[v250];
        int * v152 = v99->cache_vals;
        int v254 = ((4 + ((((int)((unsigned int)((int)((unsigned int)v107 >> 2)) >> 1)) & 3) * 2)) + ((((v143 + ((~(((v145 ^ -1) | (-(v145 ^ -1))) >> 31)) & 2)) - (v146 + ((~(((v147 ^ -1) | (-(v147 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
        int v153 = v152[v254];
        int v255 = (((4 + ((((int)((unsigned int)((int)((unsigned int)v107 >> 2)) >> 1)) & 3) * 2)) + ((((v143 + ((~(((v145 ^ -1) | (-(v145 ^ -1))) >> 31)) & 2)) - (v146 + ((~(((v147 ^ -1) | (-(v147 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
        int v154 = v152[v255];
        int * v155 = v99->mem;
        int v257 = v151 * 2;
        v155[v257] = v153;
        int * v157 = v99->mem;
        int v260 = (v151 * 2) + 1;
        v157[v260] = v154;
        ;
      } else {
        ;
      }
      int * v162 = v99->mem;
      int v265 = ((int)((unsigned int)((int)((unsigned int)v107 >> 2)) >> 1)) * 2;
      int v163 = v162[v265];
      int v266 = (((int)((unsigned int)((int)((unsigned int)v107 >> 2)) >> 1)) * 2) + 1;
      int v164 = v162[v266];
      int * v165 = v99->cache_vals;
      int v268 = ((4 + ((((int)((unsigned int)((int)((unsigned int)v107 >> 2)) >> 1)) & 3) * 2)) + ((((v143 + ((~(((v145 ^ -1) | (-(v145 ^ -1))) >> 31)) & 2)) - (v146 + ((~(((v147 ^ -1) | (-(v147 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
      v165[v268] = v163;
      int * v167 = v99->cache_vals;
      int v271 = (((4 + ((((int)((unsigned int)((int)((unsigned int)v107 >> 2)) >> 1)) & 3) * 2)) + ((((v143 + ((~(((v145 ^ -1) | (-(v145 ^ -1))) >> 31)) & 2)) - (v146 + ((~(((v147 ^ -1) | (-(v147 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
      v167[v271] = v164;
      int * v169 = v99->cache_tags;
      int v274 = (int)((unsigned int)((int)((unsigned int)v107 >> 2)) >> 1);
      v169[v250] = v274;
      int * v171 = v99->cache_dirty;
      v171[v250] = 0;
      int * v173 = v99->cache_age;
      v173[v250] = 1;
      int * v175 = v99->cache_age;
      int v176 = v175[v250];
      int v177 = v175[v224];
      int v280 = v177 + ((int)((unsigned int)(v177 - v176) >> 31));
      v175[v224] = v280;
      int * v179 = v99->cache_age;
      int v180 = v179[v225];
      int v282 = v180 + ((int)((unsigned int)(v180 - v176) >> 31));
      v179[v225] = v282;
      int * v182 = v99->cache_age;
      v182[v250] = 0;
      v185 = v250;
    }
    int * v186 = v99->cache_vals;
    int v285 = v185 * 2;
    int v187 = v186[v285];
    int v286 = (v185 * 2) + 1;
    int v188 = v186[v286];
    int v287 = (((((int)((unsigned int)((int)((unsigned int)v107 >> 2)) >> 1)) & 1) * 2) + ((((v127 + ((~(((v129 ^ -1) | (-(v129 ^ -1))) >> 31)) & 2)) - (v130 + ((~(((v131 ^ -1) | (-(v131 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
    v186[v287] = v187;
    int * v190 = v99->cache_vals;
    int v290 = ((((((int)((unsigned int)((int)((unsigned int)v107 >> 2)) >> 1)) & 1) * 2) + ((((v127 + ((~(((v129 ^ -1) | (-(v129 ^ -1))) >> 31)) & 2)) - (v130 + ((~(((v131 ^ -1) | (-(v131 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
    v190[v290] = v188;
    int * v192 = v99->cache_tags;
    int v293 = ((((int)((unsigned int)((int)((unsigned int)v107 >> 2)) >> 1)) & 1) * 2) + ((((v127 + ((~(((v129 ^ -1) | (-(v129 ^ -1))) >> 31)) & 2)) - (v130 + ((~(((v131 ^ -1) | (-(v131 ^ -1))) >> 31)) & 2))) >> 31) & 1);
    int v294 = (int)((unsigned int)((int)((unsigned int)v107 >> 2)) >> 1);
    v192[v293] = v294;
    int * v194 = v99->cache_dirty;
    v194[v293] = 0;
    int * v196 = v99->cache_age;
    v196[v293] = 1;
    int * v198 = v99->cache_age;
    int v199 = v198[v293];
    int v200 = v198[v222];
    int v300 = v200 + ((int)((unsigned int)(v200 - v199) >> 31));
    v198[v222] = v300;
    int * v202 = v99->cache_age;
    int v203 = v202[v223];
    int v302 = v203 + ((int)((unsigned int)(v203 - v199) >> 31));
    v202[v223] = v302;
    int * v205 = v99->cache_age;
    v205[v293] = 0;
    v208 = v293;
  }
  int v305 = (v208 * 2) + (((int)((unsigned int)v107 >> 2)) & 1);
  int v209 = v115[v305];
  int * v210 = v99->regs;
  v210[7] = v209;
  struct StateT * v212 = slot_8(v99);
  return v212;
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

struct StateT * slot_10(struct StateT * v545) {
  int * v546 = v545->saved_regs;
  int * v547 = v545->regs;
  int v548 = v547[16];
  v546[16] = v548;
  int v550 = v545->timer;
  int v562 = v550 + 1;
  v545->timer = v562;
  int * v552 = v545->regs;
  int v553 = v552[7];
  int v554 = v552[9];
  int v566 = v553 ^ v554;
  v552[16] = v566;
  struct StateT * v556 = slot_11(v545);
  return v556;
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

struct StateT * slot_8(struct StateT * v310) {
  int * v311 = v310->saved_regs;
  int * v312 = v310->regs;
  int v313 = v312[8];
  v311[8] = v313;
  int v315 = v310->timer;
  int v327 = v315 + 1;
  v310->timer = v327;
  int * v317 = v310->regs;
  int v318 = v317[13];
  int v319 = v317[14];
  int v331 = v318 + v319;
  v317[8] = v331;
  struct StateT * v321 = slot_9(v310);
  return v321;
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

struct StateT * slot_13(struct StateT * v662) {
  int v663 = v662->timer;
  int v673 = v663 + 1;
  v662->timer = v673;
  int * v665 = v662->regs;
  int v666 = v665[5];
  bool v676 = (v666 ^ -2147483648) < -2147483647;
  int v669;
  if (v676) {
    v669 = 1;
  } else {
    v669 = 0;
  }
  int * v670 = v662->regs;
  v670[11] = v669;
  return v662;
}

struct StateT * slot_9(struct StateT * v334) {
  int * v335 = v334->saved_regs;
  int * v336 = v334->regs;
  int v337 = v336[9];
  v335[9] = v337;
  int v339 = v334->timer;
  int v453 = v339 + 1;
  v334->timer = v453;
  int * v341 = v334->regs;
  int v342 = v341[8];
  int * v343 = v334->cache_tags;
  int v457 = (((int)((unsigned int)((int)((unsigned int)v342 >> 2)) >> 1)) & 1) * 2;
  int v344 = v343[v457];
  int v458 = ((((int)((unsigned int)((int)((unsigned int)v342 >> 2)) >> 1)) & 1) * 2) + 1;
  int v345 = v343[v458];
  int v459 = 4 + ((((int)((unsigned int)((int)((unsigned int)v342 >> 2)) >> 1)) & 3) * 2);
  int v346 = v343[v459];
  int v460 = (4 + ((((int)((unsigned int)((int)((unsigned int)v342 >> 2)) >> 1)) & 3) * 2)) + 1;
  int v347 = v343[v460];
  int v348 = v334->timer;
  int v461 = v348 + ((100 ^ (((~(((v346 ^ ((int)((unsigned int)((int)((unsigned int)v342 >> 2)) >> 1))) | (-(v346 ^ ((int)((unsigned int)((int)((unsigned int)v342 >> 2)) >> 1))))) >> 31)) | (~(((v347 ^ ((int)((unsigned int)((int)((unsigned int)v342 >> 2)) >> 1))) | (-(v347 ^ ((int)((unsigned int)((int)((unsigned int)v342 >> 2)) >> 1))))) >> 31))) & 104)) ^ (((~(((v344 ^ ((int)((unsigned int)((int)((unsigned int)v342 >> 2)) >> 1))) | (-(v344 ^ ((int)((unsigned int)((int)((unsigned int)v342 >> 2)) >> 1))))) >> 31)) | (~(((v345 ^ ((int)((unsigned int)((int)((unsigned int)v342 >> 2)) >> 1))) | (-(v345 ^ ((int)((unsigned int)((int)((unsigned int)v342 >> 2)) >> 1))))) >> 31))) & (1 ^ (100 ^ (((~(((v346 ^ ((int)((unsigned int)((int)((unsigned int)v342 >> 2)) >> 1))) | (-(v346 ^ ((int)((unsigned int)((int)((unsigned int)v342 >> 2)) >> 1))))) >> 31)) | (~(((v347 ^ ((int)((unsigned int)((int)((unsigned int)v342 >> 2)) >> 1))) | (-(v347 ^ ((int)((unsigned int)((int)((unsigned int)v342 >> 2)) >> 1))))) >> 31))) & 104)))));
  v334->timer = v461;
  int * v350 = v334->cache_vals;
  bool v462 = !(((~(((v344 ^ ((int)((unsigned int)((int)((unsigned int)v342 >> 2)) >> 1))) | (-(v344 ^ ((int)((unsigned int)((int)((unsigned int)v342 >> 2)) >> 1))))) >> 31)) | (~(((v345 ^ ((int)((unsigned int)((int)((unsigned int)v342 >> 2)) >> 1))) | (-(v345 ^ ((int)((unsigned int)((int)((unsigned int)v342 >> 2)) >> 1))))) >> 31))) == 0);
  int v443;
  if (v462) {
    int * v351 = v334->cache_age;
    int v464 = ((((int)((unsigned int)((int)((unsigned int)v342 >> 2)) >> 1)) & 1) * 2) + ((~(((v345 ^ ((int)((unsigned int)((int)((unsigned int)v342 >> 2)) >> 1))) | (-(v345 ^ ((int)((unsigned int)((int)((unsigned int)v342 >> 2)) >> 1))))) >> 31)) & 1);
    int v352 = v351[v464];
    int v353 = v351[v457];
    int v465 = v353 + ((int)((unsigned int)(v353 - v352) >> 31));
    v351[v457] = v465;
    int * v355 = v334->cache_age;
    int v356 = v355[v458];
    int v467 = v356 + ((int)((unsigned int)(v356 - v352) >> 31));
    v355[v458] = v467;
    int * v358 = v334->cache_age;
    v358[v464] = 0;
    v443 = v464;
  } else {
    int * v361 = v334->cache_age;
    int v471 = (((int)((unsigned int)((int)((unsigned int)v342 >> 2)) >> 1)) & 1) * 2;
    int v362 = v361[v471];
    int * v363 = v334->cache_tags;
    int v364 = v363[v471];
    int v365 = v361[v458];
    int v366 = v363[v458];
    bool v473 = !(((~(((v346 ^ ((int)((unsigned int)((int)((unsigned int)v342 >> 2)) >> 1))) | (-(v346 ^ ((int)((unsigned int)((int)((unsigned int)v342 >> 2)) >> 1))))) >> 31)) | (~(((v347 ^ ((int)((unsigned int)((int)((unsigned int)v342 >> 2)) >> 1))) | (-(v347 ^ ((int)((unsigned int)((int)((unsigned int)v342 >> 2)) >> 1))))) >> 31))) == 0);
    int v420;
    if (v473) {
      int * v367 = v334->cache_age;
      int v475 = (4 + ((((int)((unsigned int)((int)((unsigned int)v342 >> 2)) >> 1)) & 3) * 2)) + ((~(((v347 ^ ((int)((unsigned int)((int)((unsigned int)v342 >> 2)) >> 1))) | (-(v347 ^ ((int)((unsigned int)((int)((unsigned int)v342 >> 2)) >> 1))))) >> 31)) & 1);
      int v368 = v367[v475];
      int v369 = v367[v459];
      int v476 = v369 + ((int)((unsigned int)(v369 - v368) >> 31));
      v367[v459] = v476;
      int * v371 = v334->cache_age;
      int v372 = v371[v460];
      int v478 = v372 + ((int)((unsigned int)(v372 - v368) >> 31));
      v371[v460] = v478;
      int * v374 = v334->cache_age;
      v374[v475] = 0;
      v420 = v475;
    } else {
      int * v377 = v334->cache_age;
      int v482 = 4 + ((((int)((unsigned int)((int)((unsigned int)v342 >> 2)) >> 1)) & 3) * 2);
      int v378 = v377[v482];
      int * v379 = v334->cache_tags;
      int v380 = v379[v482];
      int v381 = v377[v460];
      int v382 = v379[v460];
      int * v383 = v334->cache_dirty;
      int v485 = (4 + ((((int)((unsigned int)((int)((unsigned int)v342 >> 2)) >> 1)) & 3) * 2)) + ((((v378 + ((~(((v380 ^ -1) | (-(v380 ^ -1))) >> 31)) & 2)) - (v381 + ((~(((v382 ^ -1) | (-(v382 ^ -1))) >> 31)) & 2))) >> 31) & 1);
      int v384 = v383[v485];
      bool v486 = !(v384 == 0);
      if (v486) {
        int * v385 = v334->cache_tags;
        int v386 = v385[v485];
        int * v387 = v334->cache_vals;
        int v489 = ((4 + ((((int)((unsigned int)((int)((unsigned int)v342 >> 2)) >> 1)) & 3) * 2)) + ((((v378 + ((~(((v380 ^ -1) | (-(v380 ^ -1))) >> 31)) & 2)) - (v381 + ((~(((v382 ^ -1) | (-(v382 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
        int v388 = v387[v489];
        int v490 = (((4 + ((((int)((unsigned int)((int)((unsigned int)v342 >> 2)) >> 1)) & 3) * 2)) + ((((v378 + ((~(((v380 ^ -1) | (-(v380 ^ -1))) >> 31)) & 2)) - (v381 + ((~(((v382 ^ -1) | (-(v382 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
        int v389 = v387[v490];
        int * v390 = v334->mem;
        int v492 = v386 * 2;
        v390[v492] = v388;
        int * v392 = v334->mem;
        int v495 = (v386 * 2) + 1;
        v392[v495] = v389;
        ;
      } else {
        ;
      }
      int * v397 = v334->mem;
      int v500 = ((int)((unsigned int)((int)((unsigned int)v342 >> 2)) >> 1)) * 2;
      int v398 = v397[v500];
      int v501 = (((int)((unsigned int)((int)((unsigned int)v342 >> 2)) >> 1)) * 2) + 1;
      int v399 = v397[v501];
      int * v400 = v334->cache_vals;
      int v503 = ((4 + ((((int)((unsigned int)((int)((unsigned int)v342 >> 2)) >> 1)) & 3) * 2)) + ((((v378 + ((~(((v380 ^ -1) | (-(v380 ^ -1))) >> 31)) & 2)) - (v381 + ((~(((v382 ^ -1) | (-(v382 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
      v400[v503] = v398;
      int * v402 = v334->cache_vals;
      int v506 = (((4 + ((((int)((unsigned int)((int)((unsigned int)v342 >> 2)) >> 1)) & 3) * 2)) + ((((v378 + ((~(((v380 ^ -1) | (-(v380 ^ -1))) >> 31)) & 2)) - (v381 + ((~(((v382 ^ -1) | (-(v382 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
      v402[v506] = v399;
      int * v404 = v334->cache_tags;
      int v509 = (int)((unsigned int)((int)((unsigned int)v342 >> 2)) >> 1);
      v404[v485] = v509;
      int * v406 = v334->cache_dirty;
      v406[v485] = 0;
      int * v408 = v334->cache_age;
      v408[v485] = 1;
      int * v410 = v334->cache_age;
      int v411 = v410[v485];
      int v412 = v410[v459];
      int v515 = v412 + ((int)((unsigned int)(v412 - v411) >> 31));
      v410[v459] = v515;
      int * v414 = v334->cache_age;
      int v415 = v414[v460];
      int v517 = v415 + ((int)((unsigned int)(v415 - v411) >> 31));
      v414[v460] = v517;
      int * v417 = v334->cache_age;
      v417[v485] = 0;
      v420 = v485;
    }
    int * v421 = v334->cache_vals;
    int v520 = v420 * 2;
    int v422 = v421[v520];
    int v521 = (v420 * 2) + 1;
    int v423 = v421[v521];
    int v522 = (((((int)((unsigned int)((int)((unsigned int)v342 >> 2)) >> 1)) & 1) * 2) + ((((v362 + ((~(((v364 ^ -1) | (-(v364 ^ -1))) >> 31)) & 2)) - (v365 + ((~(((v366 ^ -1) | (-(v366 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
    v421[v522] = v422;
    int * v425 = v334->cache_vals;
    int v525 = ((((((int)((unsigned int)((int)((unsigned int)v342 >> 2)) >> 1)) & 1) * 2) + ((((v362 + ((~(((v364 ^ -1) | (-(v364 ^ -1))) >> 31)) & 2)) - (v365 + ((~(((v366 ^ -1) | (-(v366 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
    v425[v525] = v423;
    int * v427 = v334->cache_tags;
    int v528 = ((((int)((unsigned int)((int)((unsigned int)v342 >> 2)) >> 1)) & 1) * 2) + ((((v362 + ((~(((v364 ^ -1) | (-(v364 ^ -1))) >> 31)) & 2)) - (v365 + ((~(((v366 ^ -1) | (-(v366 ^ -1))) >> 31)) & 2))) >> 31) & 1);
    int v529 = (int)((unsigned int)((int)((unsigned int)v342 >> 2)) >> 1);
    v427[v528] = v529;
    int * v429 = v334->cache_dirty;
    v429[v528] = 0;
    int * v431 = v334->cache_age;
    v431[v528] = 1;
    int * v433 = v334->cache_age;
    int v434 = v433[v528];
    int v435 = v433[v457];
    int v535 = v435 + ((int)((unsigned int)(v435 - v434) >> 31));
    v433[v457] = v535;
    int * v437 = v334->cache_age;
    int v438 = v437[v458];
    int v537 = v438 + ((int)((unsigned int)(v438 - v434) >> 31));
    v437[v458] = v537;
    int * v440 = v334->cache_age;
    v440[v528] = 0;
    v443 = v528;
  }
  int v540 = (v443 * 2) + (((int)((unsigned int)v342 >> 2)) & 1);
  int v444 = v350[v540];
  int * v445 = v334->regs;
  v445[9] = v444;
  struct StateT * v447 = slot_10(v334);
  return v447;
}

struct StateT * slot_11(struct StateT * v569) {
  int * v570 = v569->saved_regs;
  int * v571 = v569->regs;
  int v572 = v571[5];
  v570[5] = v572;
  int v574 = v569->timer;
  int v586 = v574 + 1;
  v569->timer = v586;
  int * v576 = v569->regs;
  int v577 = v576[5];
  int v578 = v576[16];
  int v589 = v577 | v578;
  v576[5] = v589;
  struct StateT * v580 = slot_12(v569);
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
  //@ assert untainted_timer: !\tainted(s1_->timer==s2_->timer);
  koika_assert(s1_->timer==s2_->timer, "timing leak");
  return 0;
}