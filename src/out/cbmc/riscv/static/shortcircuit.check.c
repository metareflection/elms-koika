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

struct StateT * slot_14(struct StateT * v729);
struct StateT * slot_6(struct StateT * v90);
struct StateT * slot_16(struct StateT * v774);
struct StateT * slot_5(struct StateT * v62);
struct StateT * slot_17(struct StateT * v782);
struct StateT * slot_2(struct StateT * v28);
struct StateT * slot_7(struct StateT * v347);
struct StateT * slot_3(struct StateT * v41);
struct StateT * snippet(struct StateT * v0);
struct StateT * slot_10(struct StateT * v688);
struct StateT * slot_1(struct StateT * v15);
struct StateT * slot_8(struct StateT * v375);
struct StateT * slot_4(struct StateT * v54);
struct StateT * slot_13(struct StateT * v706);
struct StateT * slot_15(struct StateT * v761);
struct StateT * slot_9(struct StateT * v632);
struct StateT * slot_11(struct StateT * v698);
struct StateT * slot_0(struct StateT * v2);
struct StateT * slot_14(struct StateT * v729) {
  int * v730 = v729->regs;
  int v731 = v730[10];
  int * v732 = v729->regs;
  int v733 = v732[11];
  bool v750 = !(v731 == v733);
  struct StateT * v744;
  if (v750) {
    int v734 = v729->timer;
    int v751 = v734 + 15;
    v729->timer = v751;
    int * v736 = v729->saved_regs;
    int v737 = v736[14];
    int * v738 = v729->regs;
    v738[14] = v737;
    struct StateT * v740 = slot_15(v729);
    v744 = v740;
  } else {
    struct StateT * v742 = slot_16(v729);
    v744 = v742;
  }
  return v744;
}

struct StateT * slot_6(struct StateT * v90) {
  int * v91 = v90->saved_regs;
  int * v92 = v90->regs;
  int v93 = v92[10];
  v91[10] = v93;
  int v95 = v90->timer;
  int v232 = v95 + 1;
  v90->timer = v232;
  int * v97 = v90->regs;
  int v98 = v97[5];
  int * v99 = v90->cache_tags;
  int v236 = (((int)((unsigned int)((int)((unsigned int)v98 >> 2)) >> 1)) & 1) * 2;
  int v100 = v99[v236];
  int * v101 = v90->cache_tags;
  int v238 = ((((int)((unsigned int)((int)((unsigned int)v98 >> 2)) >> 1)) & 1) * 2) + 1;
  int v102 = v101[v238];
  int * v103 = v90->cache_tags;
  int v240 = 4 + ((((int)((unsigned int)((int)((unsigned int)v98 >> 2)) >> 1)) & 3) * 2);
  int v104 = v103[v240];
  int * v105 = v90->cache_tags;
  int v242 = (4 + ((((int)((unsigned int)((int)((unsigned int)v98 >> 2)) >> 1)) & 3) * 2)) + 1;
  int v106 = v105[v242];
  int v107 = v90->timer;
  int v243 = v107 + ((100 ^ (((~(((v104 ^ ((int)((unsigned int)((int)((unsigned int)v98 >> 2)) >> 1))) | (-(v104 ^ ((int)((unsigned int)((int)((unsigned int)v98 >> 2)) >> 1))))) >> 31)) | (~(((v106 ^ ((int)((unsigned int)((int)((unsigned int)v98 >> 2)) >> 1))) | (-(v106 ^ ((int)((unsigned int)((int)((unsigned int)v98 >> 2)) >> 1))))) >> 31))) & 104)) ^ (((~(((v100 ^ ((int)((unsigned int)((int)((unsigned int)v98 >> 2)) >> 1))) | (-(v100 ^ ((int)((unsigned int)((int)((unsigned int)v98 >> 2)) >> 1))))) >> 31)) | (~(((v102 ^ ((int)((unsigned int)((int)((unsigned int)v98 >> 2)) >> 1))) | (-(v102 ^ ((int)((unsigned int)((int)((unsigned int)v98 >> 2)) >> 1))))) >> 31))) & (1 ^ (100 ^ (((~(((v104 ^ ((int)((unsigned int)((int)((unsigned int)v98 >> 2)) >> 1))) | (-(v104 ^ ((int)((unsigned int)((int)((unsigned int)v98 >> 2)) >> 1))))) >> 31)) | (~(((v106 ^ ((int)((unsigned int)((int)((unsigned int)v98 >> 2)) >> 1))) | (-(v106 ^ ((int)((unsigned int)((int)((unsigned int)v98 >> 2)) >> 1))))) >> 31))) & 104)))));
  v90->timer = v243;
  int * v109 = v90->cache_vals;
  bool v244 = !(((~(((v100 ^ ((int)((unsigned int)((int)((unsigned int)v98 >> 2)) >> 1))) | (-(v100 ^ ((int)((unsigned int)((int)((unsigned int)v98 >> 2)) >> 1))))) >> 31)) | (~(((v102 ^ ((int)((unsigned int)((int)((unsigned int)v98 >> 2)) >> 1))) | (-(v102 ^ ((int)((unsigned int)((int)((unsigned int)v98 >> 2)) >> 1))))) >> 31))) == 0);
  int v222;
  if (v244) {
    int * v110 = v90->cache_age;
    int v246 = ((((int)((unsigned int)((int)((unsigned int)v98 >> 2)) >> 1)) & 1) * 2) + ((~(((v102 ^ ((int)((unsigned int)((int)((unsigned int)v98 >> 2)) >> 1))) | (-(v102 ^ ((int)((unsigned int)((int)((unsigned int)v98 >> 2)) >> 1))))) >> 31)) & 1);
    int v111 = v110[v246];
    int * v112 = v90->cache_age;
    int v113 = v112[v236];
    int * v114 = v90->cache_age;
    int v249 = v113 + ((int)((unsigned int)(v113 - v111) >> 31));
    v114[v236] = v249;
    int * v116 = v90->cache_age;
    int v117 = v116[v238];
    int * v118 = v90->cache_age;
    int v252 = v117 + ((int)((unsigned int)(v117 - v111) >> 31));
    v118[v238] = v252;
    int * v120 = v90->cache_age;
    v120[v246] = 0;
    v222 = v246;
  } else {
    int * v123 = v90->cache_age;
    int v256 = (((int)((unsigned int)((int)((unsigned int)v98 >> 2)) >> 1)) & 1) * 2;
    int v124 = v123[v256];
    int * v125 = v90->cache_tags;
    int v126 = v125[v256];
    int * v127 = v90->cache_age;
    int v128 = v127[v238];
    int * v129 = v90->cache_tags;
    int v130 = v129[v238];
    bool v260 = !(((~(((v104 ^ ((int)((unsigned int)((int)((unsigned int)v98 >> 2)) >> 1))) | (-(v104 ^ ((int)((unsigned int)((int)((unsigned int)v98 >> 2)) >> 1))))) >> 31)) | (~(((v106 ^ ((int)((unsigned int)((int)((unsigned int)v98 >> 2)) >> 1))) | (-(v106 ^ ((int)((unsigned int)((int)((unsigned int)v98 >> 2)) >> 1))))) >> 31))) == 0);
    int v194;
    if (v260) {
      int * v131 = v90->cache_age;
      int v262 = (4 + ((((int)((unsigned int)((int)((unsigned int)v98 >> 2)) >> 1)) & 3) * 2)) + ((~(((v106 ^ ((int)((unsigned int)((int)((unsigned int)v98 >> 2)) >> 1))) | (-(v106 ^ ((int)((unsigned int)((int)((unsigned int)v98 >> 2)) >> 1))))) >> 31)) & 1);
      int v132 = v131[v262];
      int * v133 = v90->cache_age;
      int v134 = v133[v240];
      int * v135 = v90->cache_age;
      int v265 = v134 + ((int)((unsigned int)(v134 - v132) >> 31));
      v135[v240] = v265;
      int * v137 = v90->cache_age;
      int v138 = v137[v242];
      int * v139 = v90->cache_age;
      int v268 = v138 + ((int)((unsigned int)(v138 - v132) >> 31));
      v139[v242] = v268;
      int * v141 = v90->cache_age;
      v141[v262] = 0;
      v194 = v262;
    } else {
      int * v144 = v90->cache_age;
      int v272 = 4 + ((((int)((unsigned int)((int)((unsigned int)v98 >> 2)) >> 1)) & 3) * 2);
      int v145 = v144[v272];
      int * v146 = v90->cache_tags;
      int v147 = v146[v272];
      int * v148 = v90->cache_age;
      int v149 = v148[v242];
      int * v150 = v90->cache_tags;
      int v151 = v150[v242];
      int * v152 = v90->cache_dirty;
      int v277 = (4 + ((((int)((unsigned int)((int)((unsigned int)v98 >> 2)) >> 1)) & 3) * 2)) + ((((v145 + ((~(((v147 ^ -1) | (-(v147 ^ -1))) >> 31)) & 2)) - (v149 + ((~(((v151 ^ -1) | (-(v151 ^ -1))) >> 31)) & 2))) >> 31) & 1);
      int v153 = v152[v277];
      bool v278 = !(v153 == 0);
      if (v278) {
        int * v154 = v90->cache_tags;
        int v155 = v154[v277];
        int * v156 = v90->cache_vals;
        int v281 = ((4 + ((((int)((unsigned int)((int)((unsigned int)v98 >> 2)) >> 1)) & 3) * 2)) + ((((v145 + ((~(((v147 ^ -1) | (-(v147 ^ -1))) >> 31)) & 2)) - (v149 + ((~(((v151 ^ -1) | (-(v151 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
        int v157 = v156[v281];
        int * v158 = v90->cache_vals;
        int v283 = (((4 + ((((int)((unsigned int)((int)((unsigned int)v98 >> 2)) >> 1)) & 3) * 2)) + ((((v145 + ((~(((v147 ^ -1) | (-(v147 ^ -1))) >> 31)) & 2)) - (v149 + ((~(((v151 ^ -1) | (-(v151 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
        int v159 = v158[v283];
        int * v160 = v90->mem;
        int v285 = v155 * 2;
        v160[v285] = v157;
        int * v162 = v90->mem;
        int v288 = (v155 * 2) + 1;
        v162[v288] = v159;
        ;
      } else {
        ;
      }
      int * v167 = v90->mem;
      int v293 = ((int)((unsigned int)((int)((unsigned int)v98 >> 2)) >> 1)) * 2;
      int v168 = v167[v293];
      int * v169 = v90->mem;
      int v295 = (((int)((unsigned int)((int)((unsigned int)v98 >> 2)) >> 1)) * 2) + 1;
      int v170 = v169[v295];
      int * v171 = v90->cache_vals;
      int v297 = ((4 + ((((int)((unsigned int)((int)((unsigned int)v98 >> 2)) >> 1)) & 3) * 2)) + ((((v145 + ((~(((v147 ^ -1) | (-(v147 ^ -1))) >> 31)) & 2)) - (v149 + ((~(((v151 ^ -1) | (-(v151 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
      v171[v297] = v168;
      int * v173 = v90->cache_vals;
      int v300 = (((4 + ((((int)((unsigned int)((int)((unsigned int)v98 >> 2)) >> 1)) & 3) * 2)) + ((((v145 + ((~(((v147 ^ -1) | (-(v147 ^ -1))) >> 31)) & 2)) - (v149 + ((~(((v151 ^ -1) | (-(v151 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
      v173[v300] = v170;
      int * v175 = v90->cache_tags;
      int v303 = (int)((unsigned int)((int)((unsigned int)v98 >> 2)) >> 1);
      v175[v277] = v303;
      int * v177 = v90->cache_dirty;
      v177[v277] = 0;
      int * v179 = v90->cache_age;
      v179[v277] = 1;
      int * v181 = v90->cache_age;
      int v182 = v181[v277];
      int * v183 = v90->cache_age;
      int v184 = v183[v240];
      int * v185 = v90->cache_age;
      int v311 = v184 + ((int)((unsigned int)(v184 - v182) >> 31));
      v185[v240] = v311;
      int * v187 = v90->cache_age;
      int v188 = v187[v242];
      int * v189 = v90->cache_age;
      int v314 = v188 + ((int)((unsigned int)(v188 - v182) >> 31));
      v189[v242] = v314;
      int * v191 = v90->cache_age;
      v191[v277] = 0;
      v194 = v277;
    }
    int * v195 = v90->cache_vals;
    int v317 = v194 * 2;
    int v196 = v195[v317];
    int * v197 = v90->cache_vals;
    int v319 = (v194 * 2) + 1;
    int v198 = v197[v319];
    int * v199 = v90->cache_vals;
    int v321 = (((((int)((unsigned int)((int)((unsigned int)v98 >> 2)) >> 1)) & 1) * 2) + ((((v124 + ((~(((v126 ^ -1) | (-(v126 ^ -1))) >> 31)) & 2)) - (v128 + ((~(((v130 ^ -1) | (-(v130 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
    v199[v321] = v196;
    int * v201 = v90->cache_vals;
    int v324 = ((((((int)((unsigned int)((int)((unsigned int)v98 >> 2)) >> 1)) & 1) * 2) + ((((v124 + ((~(((v126 ^ -1) | (-(v126 ^ -1))) >> 31)) & 2)) - (v128 + ((~(((v130 ^ -1) | (-(v130 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
    v201[v324] = v198;
    int * v203 = v90->cache_tags;
    int v327 = ((((int)((unsigned int)((int)((unsigned int)v98 >> 2)) >> 1)) & 1) * 2) + ((((v124 + ((~(((v126 ^ -1) | (-(v126 ^ -1))) >> 31)) & 2)) - (v128 + ((~(((v130 ^ -1) | (-(v130 ^ -1))) >> 31)) & 2))) >> 31) & 1);
    int v328 = (int)((unsigned int)((int)((unsigned int)v98 >> 2)) >> 1);
    v203[v327] = v328;
    int * v205 = v90->cache_dirty;
    v205[v327] = 0;
    int * v207 = v90->cache_age;
    v207[v327] = 1;
    int * v209 = v90->cache_age;
    int v210 = v209[v327];
    int * v211 = v90->cache_age;
    int v212 = v211[v236];
    int * v213 = v90->cache_age;
    int v336 = v212 + ((int)((unsigned int)(v212 - v210) >> 31));
    v213[v236] = v336;
    int * v215 = v90->cache_age;
    int v216 = v215[v238];
    int * v217 = v90->cache_age;
    int v339 = v216 + ((int)((unsigned int)(v216 - v210) >> 31));
    v217[v238] = v339;
    int * v219 = v90->cache_age;
    v219[v327] = 0;
    v222 = v327;
  }
  int v342 = (v222 * 2) + (((int)((unsigned int)v98 >> 2)) & 1);
  int v223 = v109[v342];
  int * v224 = v90->regs;
  v224[10] = v223;
  struct StateT * v226 = slot_7(v90);
  return v226;
}

struct StateT * slot_16(struct StateT * v774) {
  int v775 = v774->timer;
  int v779 = v775 + 1;
  v774->timer = v779;
  struct StateT * v777 = slot_4(v774);
  return v777;
}

struct StateT * slot_5(struct StateT * v62) {
  int * v63 = v62->saved_regs;
  int * v64 = v62->regs;
  int v65 = v64[5];
  v63[5] = v65;
  int v67 = v62->timer;
  int v81 = v67 + 1;
  v62->timer = v81;
  int * v69 = v62->regs;
  int v70 = v69[12];
  int * v71 = v62->regs;
  int v72 = v71[14];
  int * v73 = v62->regs;
  int v87 = v70 + v72;
  v73[5] = v87;
  struct StateT * v75 = slot_6(v62);
  return v75;
}

struct StateT * slot_17(struct StateT * v782) {
  int v783 = v782->timer;
  int v786 = v783 + 1;
  v782->timer = v786;
  return v782;
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

struct StateT * slot_7(struct StateT * v347) {
  int * v348 = v347->saved_regs;
  int * v349 = v347->regs;
  int v350 = v349[6];
  v348[6] = v350;
  int v352 = v347->timer;
  int v366 = v352 + 1;
  v347->timer = v366;
  int * v354 = v347->regs;
  int v355 = v354[13];
  int * v356 = v347->regs;
  int v357 = v356[14];
  int * v358 = v347->regs;
  int v372 = v355 + v357;
  v358[6] = v372;
  struct StateT * v360 = slot_8(v347);
  return v360;
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

struct StateT * slot_10(struct StateT * v688) {
  int v689 = v688->timer;
  int v694 = v689 + 1;
  v688->timer = v694;
  int * v691 = v688->regs;
  v691[10] = 1;
  return v688;
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

struct StateT * slot_8(struct StateT * v375) {
  int * v376 = v375->saved_regs;
  int * v377 = v375->regs;
  int v378 = v377[11];
  v376[11] = v378;
  int v380 = v375->timer;
  int v517 = v380 + 1;
  v375->timer = v517;
  int * v382 = v375->regs;
  int v383 = v382[6];
  int * v384 = v375->cache_tags;
  int v521 = (((int)((unsigned int)((int)((unsigned int)v383 >> 2)) >> 1)) & 1) * 2;
  int v385 = v384[v521];
  int * v386 = v375->cache_tags;
  int v523 = ((((int)((unsigned int)((int)((unsigned int)v383 >> 2)) >> 1)) & 1) * 2) + 1;
  int v387 = v386[v523];
  int * v388 = v375->cache_tags;
  int v525 = 4 + ((((int)((unsigned int)((int)((unsigned int)v383 >> 2)) >> 1)) & 3) * 2);
  int v389 = v388[v525];
  int * v390 = v375->cache_tags;
  int v527 = (4 + ((((int)((unsigned int)((int)((unsigned int)v383 >> 2)) >> 1)) & 3) * 2)) + 1;
  int v391 = v390[v527];
  int v392 = v375->timer;
  int v528 = v392 + ((100 ^ (((~(((v389 ^ ((int)((unsigned int)((int)((unsigned int)v383 >> 2)) >> 1))) | (-(v389 ^ ((int)((unsigned int)((int)((unsigned int)v383 >> 2)) >> 1))))) >> 31)) | (~(((v391 ^ ((int)((unsigned int)((int)((unsigned int)v383 >> 2)) >> 1))) | (-(v391 ^ ((int)((unsigned int)((int)((unsigned int)v383 >> 2)) >> 1))))) >> 31))) & 104)) ^ (((~(((v385 ^ ((int)((unsigned int)((int)((unsigned int)v383 >> 2)) >> 1))) | (-(v385 ^ ((int)((unsigned int)((int)((unsigned int)v383 >> 2)) >> 1))))) >> 31)) | (~(((v387 ^ ((int)((unsigned int)((int)((unsigned int)v383 >> 2)) >> 1))) | (-(v387 ^ ((int)((unsigned int)((int)((unsigned int)v383 >> 2)) >> 1))))) >> 31))) & (1 ^ (100 ^ (((~(((v389 ^ ((int)((unsigned int)((int)((unsigned int)v383 >> 2)) >> 1))) | (-(v389 ^ ((int)((unsigned int)((int)((unsigned int)v383 >> 2)) >> 1))))) >> 31)) | (~(((v391 ^ ((int)((unsigned int)((int)((unsigned int)v383 >> 2)) >> 1))) | (-(v391 ^ ((int)((unsigned int)((int)((unsigned int)v383 >> 2)) >> 1))))) >> 31))) & 104)))));
  v375->timer = v528;
  int * v394 = v375->cache_vals;
  bool v529 = !(((~(((v385 ^ ((int)((unsigned int)((int)((unsigned int)v383 >> 2)) >> 1))) | (-(v385 ^ ((int)((unsigned int)((int)((unsigned int)v383 >> 2)) >> 1))))) >> 31)) | (~(((v387 ^ ((int)((unsigned int)((int)((unsigned int)v383 >> 2)) >> 1))) | (-(v387 ^ ((int)((unsigned int)((int)((unsigned int)v383 >> 2)) >> 1))))) >> 31))) == 0);
  int v507;
  if (v529) {
    int * v395 = v375->cache_age;
    int v531 = ((((int)((unsigned int)((int)((unsigned int)v383 >> 2)) >> 1)) & 1) * 2) + ((~(((v387 ^ ((int)((unsigned int)((int)((unsigned int)v383 >> 2)) >> 1))) | (-(v387 ^ ((int)((unsigned int)((int)((unsigned int)v383 >> 2)) >> 1))))) >> 31)) & 1);
    int v396 = v395[v531];
    int * v397 = v375->cache_age;
    int v398 = v397[v521];
    int * v399 = v375->cache_age;
    int v534 = v398 + ((int)((unsigned int)(v398 - v396) >> 31));
    v399[v521] = v534;
    int * v401 = v375->cache_age;
    int v402 = v401[v523];
    int * v403 = v375->cache_age;
    int v537 = v402 + ((int)((unsigned int)(v402 - v396) >> 31));
    v403[v523] = v537;
    int * v405 = v375->cache_age;
    v405[v531] = 0;
    v507 = v531;
  } else {
    int * v408 = v375->cache_age;
    int v541 = (((int)((unsigned int)((int)((unsigned int)v383 >> 2)) >> 1)) & 1) * 2;
    int v409 = v408[v541];
    int * v410 = v375->cache_tags;
    int v411 = v410[v541];
    int * v412 = v375->cache_age;
    int v413 = v412[v523];
    int * v414 = v375->cache_tags;
    int v415 = v414[v523];
    bool v545 = !(((~(((v389 ^ ((int)((unsigned int)((int)((unsigned int)v383 >> 2)) >> 1))) | (-(v389 ^ ((int)((unsigned int)((int)((unsigned int)v383 >> 2)) >> 1))))) >> 31)) | (~(((v391 ^ ((int)((unsigned int)((int)((unsigned int)v383 >> 2)) >> 1))) | (-(v391 ^ ((int)((unsigned int)((int)((unsigned int)v383 >> 2)) >> 1))))) >> 31))) == 0);
    int v479;
    if (v545) {
      int * v416 = v375->cache_age;
      int v547 = (4 + ((((int)((unsigned int)((int)((unsigned int)v383 >> 2)) >> 1)) & 3) * 2)) + ((~(((v391 ^ ((int)((unsigned int)((int)((unsigned int)v383 >> 2)) >> 1))) | (-(v391 ^ ((int)((unsigned int)((int)((unsigned int)v383 >> 2)) >> 1))))) >> 31)) & 1);
      int v417 = v416[v547];
      int * v418 = v375->cache_age;
      int v419 = v418[v525];
      int * v420 = v375->cache_age;
      int v550 = v419 + ((int)((unsigned int)(v419 - v417) >> 31));
      v420[v525] = v550;
      int * v422 = v375->cache_age;
      int v423 = v422[v527];
      int * v424 = v375->cache_age;
      int v553 = v423 + ((int)((unsigned int)(v423 - v417) >> 31));
      v424[v527] = v553;
      int * v426 = v375->cache_age;
      v426[v547] = 0;
      v479 = v547;
    } else {
      int * v429 = v375->cache_age;
      int v557 = 4 + ((((int)((unsigned int)((int)((unsigned int)v383 >> 2)) >> 1)) & 3) * 2);
      int v430 = v429[v557];
      int * v431 = v375->cache_tags;
      int v432 = v431[v557];
      int * v433 = v375->cache_age;
      int v434 = v433[v527];
      int * v435 = v375->cache_tags;
      int v436 = v435[v527];
      int * v437 = v375->cache_dirty;
      int v562 = (4 + ((((int)((unsigned int)((int)((unsigned int)v383 >> 2)) >> 1)) & 3) * 2)) + ((((v430 + ((~(((v432 ^ -1) | (-(v432 ^ -1))) >> 31)) & 2)) - (v434 + ((~(((v436 ^ -1) | (-(v436 ^ -1))) >> 31)) & 2))) >> 31) & 1);
      int v438 = v437[v562];
      bool v563 = !(v438 == 0);
      if (v563) {
        int * v439 = v375->cache_tags;
        int v440 = v439[v562];
        int * v441 = v375->cache_vals;
        int v566 = ((4 + ((((int)((unsigned int)((int)((unsigned int)v383 >> 2)) >> 1)) & 3) * 2)) + ((((v430 + ((~(((v432 ^ -1) | (-(v432 ^ -1))) >> 31)) & 2)) - (v434 + ((~(((v436 ^ -1) | (-(v436 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
        int v442 = v441[v566];
        int * v443 = v375->cache_vals;
        int v568 = (((4 + ((((int)((unsigned int)((int)((unsigned int)v383 >> 2)) >> 1)) & 3) * 2)) + ((((v430 + ((~(((v432 ^ -1) | (-(v432 ^ -1))) >> 31)) & 2)) - (v434 + ((~(((v436 ^ -1) | (-(v436 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
        int v444 = v443[v568];
        int * v445 = v375->mem;
        int v570 = v440 * 2;
        v445[v570] = v442;
        int * v447 = v375->mem;
        int v573 = (v440 * 2) + 1;
        v447[v573] = v444;
        ;
      } else {
        ;
      }
      int * v452 = v375->mem;
      int v578 = ((int)((unsigned int)((int)((unsigned int)v383 >> 2)) >> 1)) * 2;
      int v453 = v452[v578];
      int * v454 = v375->mem;
      int v580 = (((int)((unsigned int)((int)((unsigned int)v383 >> 2)) >> 1)) * 2) + 1;
      int v455 = v454[v580];
      int * v456 = v375->cache_vals;
      int v582 = ((4 + ((((int)((unsigned int)((int)((unsigned int)v383 >> 2)) >> 1)) & 3) * 2)) + ((((v430 + ((~(((v432 ^ -1) | (-(v432 ^ -1))) >> 31)) & 2)) - (v434 + ((~(((v436 ^ -1) | (-(v436 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
      v456[v582] = v453;
      int * v458 = v375->cache_vals;
      int v585 = (((4 + ((((int)((unsigned int)((int)((unsigned int)v383 >> 2)) >> 1)) & 3) * 2)) + ((((v430 + ((~(((v432 ^ -1) | (-(v432 ^ -1))) >> 31)) & 2)) - (v434 + ((~(((v436 ^ -1) | (-(v436 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
      v458[v585] = v455;
      int * v460 = v375->cache_tags;
      int v588 = (int)((unsigned int)((int)((unsigned int)v383 >> 2)) >> 1);
      v460[v562] = v588;
      int * v462 = v375->cache_dirty;
      v462[v562] = 0;
      int * v464 = v375->cache_age;
      v464[v562] = 1;
      int * v466 = v375->cache_age;
      int v467 = v466[v562];
      int * v468 = v375->cache_age;
      int v469 = v468[v525];
      int * v470 = v375->cache_age;
      int v596 = v469 + ((int)((unsigned int)(v469 - v467) >> 31));
      v470[v525] = v596;
      int * v472 = v375->cache_age;
      int v473 = v472[v527];
      int * v474 = v375->cache_age;
      int v599 = v473 + ((int)((unsigned int)(v473 - v467) >> 31));
      v474[v527] = v599;
      int * v476 = v375->cache_age;
      v476[v562] = 0;
      v479 = v562;
    }
    int * v480 = v375->cache_vals;
    int v602 = v479 * 2;
    int v481 = v480[v602];
    int * v482 = v375->cache_vals;
    int v604 = (v479 * 2) + 1;
    int v483 = v482[v604];
    int * v484 = v375->cache_vals;
    int v606 = (((((int)((unsigned int)((int)((unsigned int)v383 >> 2)) >> 1)) & 1) * 2) + ((((v409 + ((~(((v411 ^ -1) | (-(v411 ^ -1))) >> 31)) & 2)) - (v413 + ((~(((v415 ^ -1) | (-(v415 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
    v484[v606] = v481;
    int * v486 = v375->cache_vals;
    int v609 = ((((((int)((unsigned int)((int)((unsigned int)v383 >> 2)) >> 1)) & 1) * 2) + ((((v409 + ((~(((v411 ^ -1) | (-(v411 ^ -1))) >> 31)) & 2)) - (v413 + ((~(((v415 ^ -1) | (-(v415 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
    v486[v609] = v483;
    int * v488 = v375->cache_tags;
    int v612 = ((((int)((unsigned int)((int)((unsigned int)v383 >> 2)) >> 1)) & 1) * 2) + ((((v409 + ((~(((v411 ^ -1) | (-(v411 ^ -1))) >> 31)) & 2)) - (v413 + ((~(((v415 ^ -1) | (-(v415 ^ -1))) >> 31)) & 2))) >> 31) & 1);
    int v613 = (int)((unsigned int)((int)((unsigned int)v383 >> 2)) >> 1);
    v488[v612] = v613;
    int * v490 = v375->cache_dirty;
    v490[v612] = 0;
    int * v492 = v375->cache_age;
    v492[v612] = 1;
    int * v494 = v375->cache_age;
    int v495 = v494[v612];
    int * v496 = v375->cache_age;
    int v497 = v496[v521];
    int * v498 = v375->cache_age;
    int v621 = v497 + ((int)((unsigned int)(v497 - v495) >> 31));
    v498[v521] = v621;
    int * v500 = v375->cache_age;
    int v501 = v500[v523];
    int * v502 = v375->cache_age;
    int v624 = v501 + ((int)((unsigned int)(v501 - v495) >> 31));
    v502[v523] = v624;
    int * v504 = v375->cache_age;
    v504[v612] = 0;
    v507 = v612;
  }
  int v627 = (v507 * 2) + (((int)((unsigned int)v383 >> 2)) & 1);
  int v508 = v394[v627];
  int * v509 = v375->regs;
  v509[11] = v508;
  struct StateT * v511 = slot_9(v375);
  return v511;
}

struct StateT * slot_4(struct StateT * v54) {
  int v55 = v54->timer;
  int v59 = v55 + 1;
  v54->timer = v59;
  struct StateT * v57 = slot_5(v54);
  return v57;
}

struct StateT * slot_13(struct StateT * v706) {
  int * v707 = v706->saved_regs;
  int * v708 = v706->regs;
  int v709 = v708[14];
  v707[14] = v709;
  int v711 = v706->timer;
  int v723 = v711 + 1;
  v706->timer = v723;
  int * v713 = v706->regs;
  int v714 = v713[14];
  int * v715 = v706->regs;
  int v726 = v714 + 4;
  v715[14] = v726;
  struct StateT * v717 = slot_14(v706);
  return v717;
}

struct StateT * slot_15(struct StateT * v761) {
  int v762 = v761->timer;
  int v768 = v762 + 1;
  v761->timer = v768;
  int * v764 = v761->regs;
  v764[10] = 0;
  struct StateT * v766 = slot_17(v761);
  return v766;
}

struct StateT * slot_9(struct StateT * v632) {
  int * v633 = v632->regs;
  int v634 = v633[14];
  int * v635 = v632->regs;
  int v636 = v635[15];
  bool v665 = v634 >= v636;
  struct StateT * v659;
  if (v665) {
    int v637 = v632->timer;
    int v666 = v637 + 15;
    v632->timer = v666;
    int * v639 = v632->saved_regs;
    int v640 = v639[5];
    int * v641 = v632->regs;
    v641[5] = v640;
    int * v643 = v632->saved_regs;
    int v644 = v643[10];
    int * v645 = v632->regs;
    v645[10] = v644;
    int * v647 = v632->saved_regs;
    int v648 = v647[6];
    int * v649 = v632->regs;
    v649[6] = v648;
    int * v651 = v632->saved_regs;
    int v652 = v651[11];
    int * v653 = v632->regs;
    v653[11] = v652;
    struct StateT * v655 = slot_10(v632);
    v659 = v655;
  } else {
    struct StateT * v657 = slot_11(v632);
    v659 = v657;
  }
  return v659;
}

struct StateT * slot_11(struct StateT * v698) {
  int v699 = v698->timer;
  int v703 = v699 + 1;
  v698->timer = v703;
  struct StateT * v701 = slot_13(v698);
  return v701;
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
  koika_assert(s1_->timer==s2_->timer, "timing leak");
  return 0;
}