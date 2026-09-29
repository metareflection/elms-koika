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

struct StateT * slot_12(struct StateT * v700);
struct StateT * slot_14(struct StateT * v792);
struct StateT * slot_6(struct StateT * v75);
struct StateT * slot_16(struct StateT * v808);
struct StateT * slot_5(struct StateT * v67);
struct StateT * slot_2(struct StateT * v28);
struct StateT * slot_7(struct StateT * v103);
struct StateT * slot_3(struct StateT * v41);
struct StateT * snippet(struct StateT * v0);
struct StateT * slot_10(struct StateT * v645);
struct StateT * slot_1(struct StateT * v15);
struct StateT * slot_8(struct StateT * v360);
struct StateT * slot_4(struct StateT * v54);
struct StateT * slot_13(struct StateT * v772);
struct StateT * slot_9(struct StateT * v388);
struct StateT * slot_11(struct StateT * v673);
struct StateT * slot_0(struct StateT * v2);
struct StateT * slot_12(struct StateT * v700) {
  int * v701 = v700->regs;
  int v702 = v701[14];
  int * v703 = v700->regs;
  int v704 = v703[15];
  bool v741 = v702 >= v704;
  struct StateT * v735;
  if (v741) {
    int v705 = v700->timer;
    int v742 = v705 + 15;
    v700->timer = v742;
    int * v707 = v700->saved_regs;
    int v708 = v707[6];
    int * v709 = v700->regs;
    v709[6] = v708;
    int * v711 = v700->saved_regs;
    int v712 = v711[7];
    int * v713 = v700->regs;
    v713[7] = v712;
    int * v715 = v700->saved_regs;
    int v716 = v715[8];
    int * v717 = v700->regs;
    v717[8] = v716;
    int * v719 = v700->saved_regs;
    int v720 = v719[9];
    int * v721 = v700->regs;
    v721[9] = v720;
    int * v723 = v700->saved_regs;
    int v724 = v723[16];
    int * v725 = v700->regs;
    v725[16] = v724;
    int * v727 = v700->saved_regs;
    int v728 = v727[5];
    int * v729 = v700->regs;
    v729[5] = v728;
    struct StateT * v731 = slot_13(v700);
    v735 = v731;
  } else {
    struct StateT * v733 = slot_14(v700);
    v735 = v733;
  }
  return v735;
}

struct StateT * slot_14(struct StateT * v792) {
  int v793 = v792->timer;
  int v801 = v793 + 1;
  v792->timer = v801;
  int * v795 = v792->regs;
  int v796 = v795[14];
  int * v797 = v792->regs;
  int v805 = v796 + 4;
  v797[14] = v805;
  struct StateT * v799 = slot_16(v792);
  return v799;
}

struct StateT * slot_6(struct StateT * v75) {
  int * v76 = v75->saved_regs;
  int * v77 = v75->regs;
  int v78 = v77[6];
  v76[6] = v78;
  int v80 = v75->timer;
  int v94 = v80 + 1;
  v75->timer = v94;
  int * v82 = v75->regs;
  int v83 = v82[12];
  int * v84 = v75->regs;
  int v85 = v84[14];
  int * v86 = v75->regs;
  int v100 = v83 + v85;
  v86[6] = v100;
  struct StateT * v88 = slot_7(v75);
  return v88;
}

struct StateT * slot_16(struct StateT * v808) {
  int v809 = v808->timer;
  int v813 = v809 + 1;
  v808->timer = v813;
  struct StateT * v811 = slot_5(v808);
  return v811;
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

struct StateT * slot_7(struct StateT * v103) {
  int * v104 = v103->saved_regs;
  int * v105 = v103->regs;
  int v106 = v105[7];
  v104[7] = v106;
  int v108 = v103->timer;
  int v245 = v108 + 1;
  v103->timer = v245;
  int * v110 = v103->regs;
  int v111 = v110[6];
  int * v112 = v103->cache_tags;
  int v249 = (((int)((unsigned int)((int)((unsigned int)v111 >> 2)) >> 1)) & 1) * 2;
  int v113 = v112[v249];
  int * v114 = v103->cache_tags;
  int v251 = ((((int)((unsigned int)((int)((unsigned int)v111 >> 2)) >> 1)) & 1) * 2) + 1;
  int v115 = v114[v251];
  int * v116 = v103->cache_tags;
  int v253 = 4 + ((((int)((unsigned int)((int)((unsigned int)v111 >> 2)) >> 1)) & 3) * 2);
  int v117 = v116[v253];
  int * v118 = v103->cache_tags;
  int v255 = (4 + ((((int)((unsigned int)((int)((unsigned int)v111 >> 2)) >> 1)) & 3) * 2)) + 1;
  int v119 = v118[v255];
  int v120 = v103->timer;
  int v256 = v120 + ((100 ^ (((~(((v117 ^ ((int)((unsigned int)((int)((unsigned int)v111 >> 2)) >> 1))) | (-(v117 ^ ((int)((unsigned int)((int)((unsigned int)v111 >> 2)) >> 1))))) >> 31)) | (~(((v119 ^ ((int)((unsigned int)((int)((unsigned int)v111 >> 2)) >> 1))) | (-(v119 ^ ((int)((unsigned int)((int)((unsigned int)v111 >> 2)) >> 1))))) >> 31))) & 104)) ^ (((~(((v113 ^ ((int)((unsigned int)((int)((unsigned int)v111 >> 2)) >> 1))) | (-(v113 ^ ((int)((unsigned int)((int)((unsigned int)v111 >> 2)) >> 1))))) >> 31)) | (~(((v115 ^ ((int)((unsigned int)((int)((unsigned int)v111 >> 2)) >> 1))) | (-(v115 ^ ((int)((unsigned int)((int)((unsigned int)v111 >> 2)) >> 1))))) >> 31))) & (1 ^ (100 ^ (((~(((v117 ^ ((int)((unsigned int)((int)((unsigned int)v111 >> 2)) >> 1))) | (-(v117 ^ ((int)((unsigned int)((int)((unsigned int)v111 >> 2)) >> 1))))) >> 31)) | (~(((v119 ^ ((int)((unsigned int)((int)((unsigned int)v111 >> 2)) >> 1))) | (-(v119 ^ ((int)((unsigned int)((int)((unsigned int)v111 >> 2)) >> 1))))) >> 31))) & 104)))));
  v103->timer = v256;
  int * v122 = v103->cache_vals;
  bool v257 = !(((~(((v113 ^ ((int)((unsigned int)((int)((unsigned int)v111 >> 2)) >> 1))) | (-(v113 ^ ((int)((unsigned int)((int)((unsigned int)v111 >> 2)) >> 1))))) >> 31)) | (~(((v115 ^ ((int)((unsigned int)((int)((unsigned int)v111 >> 2)) >> 1))) | (-(v115 ^ ((int)((unsigned int)((int)((unsigned int)v111 >> 2)) >> 1))))) >> 31))) == 0);
  int v235;
  if (v257) {
    int * v123 = v103->cache_age;
    int v259 = ((((int)((unsigned int)((int)((unsigned int)v111 >> 2)) >> 1)) & 1) * 2) + ((~(((v115 ^ ((int)((unsigned int)((int)((unsigned int)v111 >> 2)) >> 1))) | (-(v115 ^ ((int)((unsigned int)((int)((unsigned int)v111 >> 2)) >> 1))))) >> 31)) & 1);
    int v124 = v123[v259];
    int * v125 = v103->cache_age;
    int v126 = v125[v249];
    int * v127 = v103->cache_age;
    int v262 = v126 + ((int)((unsigned int)(v126 - v124) >> 31));
    v127[v249] = v262;
    int * v129 = v103->cache_age;
    int v130 = v129[v251];
    int * v131 = v103->cache_age;
    int v265 = v130 + ((int)((unsigned int)(v130 - v124) >> 31));
    v131[v251] = v265;
    int * v133 = v103->cache_age;
    v133[v259] = 0;
    v235 = v259;
  } else {
    int * v136 = v103->cache_age;
    int v269 = (((int)((unsigned int)((int)((unsigned int)v111 >> 2)) >> 1)) & 1) * 2;
    int v137 = v136[v269];
    int * v138 = v103->cache_tags;
    int v139 = v138[v269];
    int * v140 = v103->cache_age;
    int v141 = v140[v251];
    int * v142 = v103->cache_tags;
    int v143 = v142[v251];
    bool v273 = !(((~(((v117 ^ ((int)((unsigned int)((int)((unsigned int)v111 >> 2)) >> 1))) | (-(v117 ^ ((int)((unsigned int)((int)((unsigned int)v111 >> 2)) >> 1))))) >> 31)) | (~(((v119 ^ ((int)((unsigned int)((int)((unsigned int)v111 >> 2)) >> 1))) | (-(v119 ^ ((int)((unsigned int)((int)((unsigned int)v111 >> 2)) >> 1))))) >> 31))) == 0);
    int v207;
    if (v273) {
      int * v144 = v103->cache_age;
      int v275 = (4 + ((((int)((unsigned int)((int)((unsigned int)v111 >> 2)) >> 1)) & 3) * 2)) + ((~(((v119 ^ ((int)((unsigned int)((int)((unsigned int)v111 >> 2)) >> 1))) | (-(v119 ^ ((int)((unsigned int)((int)((unsigned int)v111 >> 2)) >> 1))))) >> 31)) & 1);
      int v145 = v144[v275];
      int * v146 = v103->cache_age;
      int v147 = v146[v253];
      int * v148 = v103->cache_age;
      int v278 = v147 + ((int)((unsigned int)(v147 - v145) >> 31));
      v148[v253] = v278;
      int * v150 = v103->cache_age;
      int v151 = v150[v255];
      int * v152 = v103->cache_age;
      int v281 = v151 + ((int)((unsigned int)(v151 - v145) >> 31));
      v152[v255] = v281;
      int * v154 = v103->cache_age;
      v154[v275] = 0;
      v207 = v275;
    } else {
      int * v157 = v103->cache_age;
      int v285 = 4 + ((((int)((unsigned int)((int)((unsigned int)v111 >> 2)) >> 1)) & 3) * 2);
      int v158 = v157[v285];
      int * v159 = v103->cache_tags;
      int v160 = v159[v285];
      int * v161 = v103->cache_age;
      int v162 = v161[v255];
      int * v163 = v103->cache_tags;
      int v164 = v163[v255];
      int * v165 = v103->cache_dirty;
      int v290 = (4 + ((((int)((unsigned int)((int)((unsigned int)v111 >> 2)) >> 1)) & 3) * 2)) + ((((v158 + ((~(((v160 ^ -1) | (-(v160 ^ -1))) >> 31)) & 2)) - (v162 + ((~(((v164 ^ -1) | (-(v164 ^ -1))) >> 31)) & 2))) >> 31) & 1);
      int v166 = v165[v290];
      bool v291 = !(v166 == 0);
      if (v291) {
        int * v167 = v103->cache_tags;
        int v168 = v167[v290];
        int * v169 = v103->cache_vals;
        int v294 = ((4 + ((((int)((unsigned int)((int)((unsigned int)v111 >> 2)) >> 1)) & 3) * 2)) + ((((v158 + ((~(((v160 ^ -1) | (-(v160 ^ -1))) >> 31)) & 2)) - (v162 + ((~(((v164 ^ -1) | (-(v164 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
        int v170 = v169[v294];
        int * v171 = v103->cache_vals;
        int v296 = (((4 + ((((int)((unsigned int)((int)((unsigned int)v111 >> 2)) >> 1)) & 3) * 2)) + ((((v158 + ((~(((v160 ^ -1) | (-(v160 ^ -1))) >> 31)) & 2)) - (v162 + ((~(((v164 ^ -1) | (-(v164 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
        int v172 = v171[v296];
        int * v173 = v103->mem;
        int v298 = v168 * 2;
        v173[v298] = v170;
        int * v175 = v103->mem;
        int v301 = (v168 * 2) + 1;
        v175[v301] = v172;
        ;
      } else {
        ;
      }
      int * v180 = v103->mem;
      int v306 = ((int)((unsigned int)((int)((unsigned int)v111 >> 2)) >> 1)) * 2;
      int v181 = v180[v306];
      int * v182 = v103->mem;
      int v308 = (((int)((unsigned int)((int)((unsigned int)v111 >> 2)) >> 1)) * 2) + 1;
      int v183 = v182[v308];
      int * v184 = v103->cache_vals;
      int v310 = ((4 + ((((int)((unsigned int)((int)((unsigned int)v111 >> 2)) >> 1)) & 3) * 2)) + ((((v158 + ((~(((v160 ^ -1) | (-(v160 ^ -1))) >> 31)) & 2)) - (v162 + ((~(((v164 ^ -1) | (-(v164 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
      v184[v310] = v181;
      int * v186 = v103->cache_vals;
      int v313 = (((4 + ((((int)((unsigned int)((int)((unsigned int)v111 >> 2)) >> 1)) & 3) * 2)) + ((((v158 + ((~(((v160 ^ -1) | (-(v160 ^ -1))) >> 31)) & 2)) - (v162 + ((~(((v164 ^ -1) | (-(v164 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
      v186[v313] = v183;
      int * v188 = v103->cache_tags;
      int v316 = (int)((unsigned int)((int)((unsigned int)v111 >> 2)) >> 1);
      v188[v290] = v316;
      int * v190 = v103->cache_dirty;
      v190[v290] = 0;
      int * v192 = v103->cache_age;
      v192[v290] = 1;
      int * v194 = v103->cache_age;
      int v195 = v194[v290];
      int * v196 = v103->cache_age;
      int v197 = v196[v253];
      int * v198 = v103->cache_age;
      int v324 = v197 + ((int)((unsigned int)(v197 - v195) >> 31));
      v198[v253] = v324;
      int * v200 = v103->cache_age;
      int v201 = v200[v255];
      int * v202 = v103->cache_age;
      int v327 = v201 + ((int)((unsigned int)(v201 - v195) >> 31));
      v202[v255] = v327;
      int * v204 = v103->cache_age;
      v204[v290] = 0;
      v207 = v290;
    }
    int * v208 = v103->cache_vals;
    int v330 = v207 * 2;
    int v209 = v208[v330];
    int * v210 = v103->cache_vals;
    int v332 = (v207 * 2) + 1;
    int v211 = v210[v332];
    int * v212 = v103->cache_vals;
    int v334 = (((((int)((unsigned int)((int)((unsigned int)v111 >> 2)) >> 1)) & 1) * 2) + ((((v137 + ((~(((v139 ^ -1) | (-(v139 ^ -1))) >> 31)) & 2)) - (v141 + ((~(((v143 ^ -1) | (-(v143 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
    v212[v334] = v209;
    int * v214 = v103->cache_vals;
    int v337 = ((((((int)((unsigned int)((int)((unsigned int)v111 >> 2)) >> 1)) & 1) * 2) + ((((v137 + ((~(((v139 ^ -1) | (-(v139 ^ -1))) >> 31)) & 2)) - (v141 + ((~(((v143 ^ -1) | (-(v143 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
    v214[v337] = v211;
    int * v216 = v103->cache_tags;
    int v340 = ((((int)((unsigned int)((int)((unsigned int)v111 >> 2)) >> 1)) & 1) * 2) + ((((v137 + ((~(((v139 ^ -1) | (-(v139 ^ -1))) >> 31)) & 2)) - (v141 + ((~(((v143 ^ -1) | (-(v143 ^ -1))) >> 31)) & 2))) >> 31) & 1);
    int v341 = (int)((unsigned int)((int)((unsigned int)v111 >> 2)) >> 1);
    v216[v340] = v341;
    int * v218 = v103->cache_dirty;
    v218[v340] = 0;
    int * v220 = v103->cache_age;
    v220[v340] = 1;
    int * v222 = v103->cache_age;
    int v223 = v222[v340];
    int * v224 = v103->cache_age;
    int v225 = v224[v249];
    int * v226 = v103->cache_age;
    int v349 = v225 + ((int)((unsigned int)(v225 - v223) >> 31));
    v226[v249] = v349;
    int * v228 = v103->cache_age;
    int v229 = v228[v251];
    int * v230 = v103->cache_age;
    int v352 = v229 + ((int)((unsigned int)(v229 - v223) >> 31));
    v230[v251] = v352;
    int * v232 = v103->cache_age;
    v232[v340] = 0;
    v235 = v340;
  }
  int v355 = (v235 * 2) + (((int)((unsigned int)v111 >> 2)) & 1);
  int v236 = v122[v355];
  int * v237 = v103->regs;
  v237[7] = v236;
  struct StateT * v239 = slot_8(v103);
  return v239;
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

struct StateT * slot_10(struct StateT * v645) {
  int * v646 = v645->saved_regs;
  int * v647 = v645->regs;
  int v648 = v647[16];
  v646[16] = v648;
  int v650 = v645->timer;
  int v664 = v650 + 1;
  v645->timer = v664;
  int * v652 = v645->regs;
  int v653 = v652[7];
  int * v654 = v645->regs;
  int v655 = v654[9];
  int * v656 = v645->regs;
  int v670 = v653 ^ v655;
  v656[16] = v670;
  struct StateT * v658 = slot_11(v645);
  return v658;
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

struct StateT * slot_8(struct StateT * v360) {
  int * v361 = v360->saved_regs;
  int * v362 = v360->regs;
  int v363 = v362[8];
  v361[8] = v363;
  int v365 = v360->timer;
  int v379 = v365 + 1;
  v360->timer = v379;
  int * v367 = v360->regs;
  int v368 = v367[13];
  int * v369 = v360->regs;
  int v370 = v369[14];
  int * v371 = v360->regs;
  int v385 = v368 + v370;
  v371[8] = v385;
  struct StateT * v373 = slot_9(v360);
  return v373;
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

struct StateT * slot_13(struct StateT * v772) {
  int v773 = v772->timer;
  int v783 = v773 + 1;
  v772->timer = v783;
  int * v775 = v772->regs;
  int v776 = v775[5];
  bool v786 = (v776 ^ -2147483648) < -2147483647;
  int v779;
  if (v786) {
    v779 = 1;
  } else {
    v779 = 0;
  }
  int * v780 = v772->regs;
  v780[11] = v779;
  return v772;
}

struct StateT * slot_9(struct StateT * v388) {
  int * v389 = v388->saved_regs;
  int * v390 = v388->regs;
  int v391 = v390[9];
  v389[9] = v391;
  int v393 = v388->timer;
  int v530 = v393 + 1;
  v388->timer = v530;
  int * v395 = v388->regs;
  int v396 = v395[8];
  int * v397 = v388->cache_tags;
  int v534 = (((int)((unsigned int)((int)((unsigned int)v396 >> 2)) >> 1)) & 1) * 2;
  int v398 = v397[v534];
  int * v399 = v388->cache_tags;
  int v536 = ((((int)((unsigned int)((int)((unsigned int)v396 >> 2)) >> 1)) & 1) * 2) + 1;
  int v400 = v399[v536];
  int * v401 = v388->cache_tags;
  int v538 = 4 + ((((int)((unsigned int)((int)((unsigned int)v396 >> 2)) >> 1)) & 3) * 2);
  int v402 = v401[v538];
  int * v403 = v388->cache_tags;
  int v540 = (4 + ((((int)((unsigned int)((int)((unsigned int)v396 >> 2)) >> 1)) & 3) * 2)) + 1;
  int v404 = v403[v540];
  int v405 = v388->timer;
  int v541 = v405 + ((100 ^ (((~(((v402 ^ ((int)((unsigned int)((int)((unsigned int)v396 >> 2)) >> 1))) | (-(v402 ^ ((int)((unsigned int)((int)((unsigned int)v396 >> 2)) >> 1))))) >> 31)) | (~(((v404 ^ ((int)((unsigned int)((int)((unsigned int)v396 >> 2)) >> 1))) | (-(v404 ^ ((int)((unsigned int)((int)((unsigned int)v396 >> 2)) >> 1))))) >> 31))) & 104)) ^ (((~(((v398 ^ ((int)((unsigned int)((int)((unsigned int)v396 >> 2)) >> 1))) | (-(v398 ^ ((int)((unsigned int)((int)((unsigned int)v396 >> 2)) >> 1))))) >> 31)) | (~(((v400 ^ ((int)((unsigned int)((int)((unsigned int)v396 >> 2)) >> 1))) | (-(v400 ^ ((int)((unsigned int)((int)((unsigned int)v396 >> 2)) >> 1))))) >> 31))) & (1 ^ (100 ^ (((~(((v402 ^ ((int)((unsigned int)((int)((unsigned int)v396 >> 2)) >> 1))) | (-(v402 ^ ((int)((unsigned int)((int)((unsigned int)v396 >> 2)) >> 1))))) >> 31)) | (~(((v404 ^ ((int)((unsigned int)((int)((unsigned int)v396 >> 2)) >> 1))) | (-(v404 ^ ((int)((unsigned int)((int)((unsigned int)v396 >> 2)) >> 1))))) >> 31))) & 104)))));
  v388->timer = v541;
  int * v407 = v388->cache_vals;
  bool v542 = !(((~(((v398 ^ ((int)((unsigned int)((int)((unsigned int)v396 >> 2)) >> 1))) | (-(v398 ^ ((int)((unsigned int)((int)((unsigned int)v396 >> 2)) >> 1))))) >> 31)) | (~(((v400 ^ ((int)((unsigned int)((int)((unsigned int)v396 >> 2)) >> 1))) | (-(v400 ^ ((int)((unsigned int)((int)((unsigned int)v396 >> 2)) >> 1))))) >> 31))) == 0);
  int v520;
  if (v542) {
    int * v408 = v388->cache_age;
    int v544 = ((((int)((unsigned int)((int)((unsigned int)v396 >> 2)) >> 1)) & 1) * 2) + ((~(((v400 ^ ((int)((unsigned int)((int)((unsigned int)v396 >> 2)) >> 1))) | (-(v400 ^ ((int)((unsigned int)((int)((unsigned int)v396 >> 2)) >> 1))))) >> 31)) & 1);
    int v409 = v408[v544];
    int * v410 = v388->cache_age;
    int v411 = v410[v534];
    int * v412 = v388->cache_age;
    int v547 = v411 + ((int)((unsigned int)(v411 - v409) >> 31));
    v412[v534] = v547;
    int * v414 = v388->cache_age;
    int v415 = v414[v536];
    int * v416 = v388->cache_age;
    int v550 = v415 + ((int)((unsigned int)(v415 - v409) >> 31));
    v416[v536] = v550;
    int * v418 = v388->cache_age;
    v418[v544] = 0;
    v520 = v544;
  } else {
    int * v421 = v388->cache_age;
    int v554 = (((int)((unsigned int)((int)((unsigned int)v396 >> 2)) >> 1)) & 1) * 2;
    int v422 = v421[v554];
    int * v423 = v388->cache_tags;
    int v424 = v423[v554];
    int * v425 = v388->cache_age;
    int v426 = v425[v536];
    int * v427 = v388->cache_tags;
    int v428 = v427[v536];
    bool v558 = !(((~(((v402 ^ ((int)((unsigned int)((int)((unsigned int)v396 >> 2)) >> 1))) | (-(v402 ^ ((int)((unsigned int)((int)((unsigned int)v396 >> 2)) >> 1))))) >> 31)) | (~(((v404 ^ ((int)((unsigned int)((int)((unsigned int)v396 >> 2)) >> 1))) | (-(v404 ^ ((int)((unsigned int)((int)((unsigned int)v396 >> 2)) >> 1))))) >> 31))) == 0);
    int v492;
    if (v558) {
      int * v429 = v388->cache_age;
      int v560 = (4 + ((((int)((unsigned int)((int)((unsigned int)v396 >> 2)) >> 1)) & 3) * 2)) + ((~(((v404 ^ ((int)((unsigned int)((int)((unsigned int)v396 >> 2)) >> 1))) | (-(v404 ^ ((int)((unsigned int)((int)((unsigned int)v396 >> 2)) >> 1))))) >> 31)) & 1);
      int v430 = v429[v560];
      int * v431 = v388->cache_age;
      int v432 = v431[v538];
      int * v433 = v388->cache_age;
      int v563 = v432 + ((int)((unsigned int)(v432 - v430) >> 31));
      v433[v538] = v563;
      int * v435 = v388->cache_age;
      int v436 = v435[v540];
      int * v437 = v388->cache_age;
      int v566 = v436 + ((int)((unsigned int)(v436 - v430) >> 31));
      v437[v540] = v566;
      int * v439 = v388->cache_age;
      v439[v560] = 0;
      v492 = v560;
    } else {
      int * v442 = v388->cache_age;
      int v570 = 4 + ((((int)((unsigned int)((int)((unsigned int)v396 >> 2)) >> 1)) & 3) * 2);
      int v443 = v442[v570];
      int * v444 = v388->cache_tags;
      int v445 = v444[v570];
      int * v446 = v388->cache_age;
      int v447 = v446[v540];
      int * v448 = v388->cache_tags;
      int v449 = v448[v540];
      int * v450 = v388->cache_dirty;
      int v575 = (4 + ((((int)((unsigned int)((int)((unsigned int)v396 >> 2)) >> 1)) & 3) * 2)) + ((((v443 + ((~(((v445 ^ -1) | (-(v445 ^ -1))) >> 31)) & 2)) - (v447 + ((~(((v449 ^ -1) | (-(v449 ^ -1))) >> 31)) & 2))) >> 31) & 1);
      int v451 = v450[v575];
      bool v576 = !(v451 == 0);
      if (v576) {
        int * v452 = v388->cache_tags;
        int v453 = v452[v575];
        int * v454 = v388->cache_vals;
        int v579 = ((4 + ((((int)((unsigned int)((int)((unsigned int)v396 >> 2)) >> 1)) & 3) * 2)) + ((((v443 + ((~(((v445 ^ -1) | (-(v445 ^ -1))) >> 31)) & 2)) - (v447 + ((~(((v449 ^ -1) | (-(v449 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
        int v455 = v454[v579];
        int * v456 = v388->cache_vals;
        int v581 = (((4 + ((((int)((unsigned int)((int)((unsigned int)v396 >> 2)) >> 1)) & 3) * 2)) + ((((v443 + ((~(((v445 ^ -1) | (-(v445 ^ -1))) >> 31)) & 2)) - (v447 + ((~(((v449 ^ -1) | (-(v449 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
        int v457 = v456[v581];
        int * v458 = v388->mem;
        int v583 = v453 * 2;
        v458[v583] = v455;
        int * v460 = v388->mem;
        int v586 = (v453 * 2) + 1;
        v460[v586] = v457;
        ;
      } else {
        ;
      }
      int * v465 = v388->mem;
      int v591 = ((int)((unsigned int)((int)((unsigned int)v396 >> 2)) >> 1)) * 2;
      int v466 = v465[v591];
      int * v467 = v388->mem;
      int v593 = (((int)((unsigned int)((int)((unsigned int)v396 >> 2)) >> 1)) * 2) + 1;
      int v468 = v467[v593];
      int * v469 = v388->cache_vals;
      int v595 = ((4 + ((((int)((unsigned int)((int)((unsigned int)v396 >> 2)) >> 1)) & 3) * 2)) + ((((v443 + ((~(((v445 ^ -1) | (-(v445 ^ -1))) >> 31)) & 2)) - (v447 + ((~(((v449 ^ -1) | (-(v449 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
      v469[v595] = v466;
      int * v471 = v388->cache_vals;
      int v598 = (((4 + ((((int)((unsigned int)((int)((unsigned int)v396 >> 2)) >> 1)) & 3) * 2)) + ((((v443 + ((~(((v445 ^ -1) | (-(v445 ^ -1))) >> 31)) & 2)) - (v447 + ((~(((v449 ^ -1) | (-(v449 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
      v471[v598] = v468;
      int * v473 = v388->cache_tags;
      int v601 = (int)((unsigned int)((int)((unsigned int)v396 >> 2)) >> 1);
      v473[v575] = v601;
      int * v475 = v388->cache_dirty;
      v475[v575] = 0;
      int * v477 = v388->cache_age;
      v477[v575] = 1;
      int * v479 = v388->cache_age;
      int v480 = v479[v575];
      int * v481 = v388->cache_age;
      int v482 = v481[v538];
      int * v483 = v388->cache_age;
      int v609 = v482 + ((int)((unsigned int)(v482 - v480) >> 31));
      v483[v538] = v609;
      int * v485 = v388->cache_age;
      int v486 = v485[v540];
      int * v487 = v388->cache_age;
      int v612 = v486 + ((int)((unsigned int)(v486 - v480) >> 31));
      v487[v540] = v612;
      int * v489 = v388->cache_age;
      v489[v575] = 0;
      v492 = v575;
    }
    int * v493 = v388->cache_vals;
    int v615 = v492 * 2;
    int v494 = v493[v615];
    int * v495 = v388->cache_vals;
    int v617 = (v492 * 2) + 1;
    int v496 = v495[v617];
    int * v497 = v388->cache_vals;
    int v619 = (((((int)((unsigned int)((int)((unsigned int)v396 >> 2)) >> 1)) & 1) * 2) + ((((v422 + ((~(((v424 ^ -1) | (-(v424 ^ -1))) >> 31)) & 2)) - (v426 + ((~(((v428 ^ -1) | (-(v428 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
    v497[v619] = v494;
    int * v499 = v388->cache_vals;
    int v622 = ((((((int)((unsigned int)((int)((unsigned int)v396 >> 2)) >> 1)) & 1) * 2) + ((((v422 + ((~(((v424 ^ -1) | (-(v424 ^ -1))) >> 31)) & 2)) - (v426 + ((~(((v428 ^ -1) | (-(v428 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
    v499[v622] = v496;
    int * v501 = v388->cache_tags;
    int v625 = ((((int)((unsigned int)((int)((unsigned int)v396 >> 2)) >> 1)) & 1) * 2) + ((((v422 + ((~(((v424 ^ -1) | (-(v424 ^ -1))) >> 31)) & 2)) - (v426 + ((~(((v428 ^ -1) | (-(v428 ^ -1))) >> 31)) & 2))) >> 31) & 1);
    int v626 = (int)((unsigned int)((int)((unsigned int)v396 >> 2)) >> 1);
    v501[v625] = v626;
    int * v503 = v388->cache_dirty;
    v503[v625] = 0;
    int * v505 = v388->cache_age;
    v505[v625] = 1;
    int * v507 = v388->cache_age;
    int v508 = v507[v625];
    int * v509 = v388->cache_age;
    int v510 = v509[v534];
    int * v511 = v388->cache_age;
    int v634 = v510 + ((int)((unsigned int)(v510 - v508) >> 31));
    v511[v534] = v634;
    int * v513 = v388->cache_age;
    int v514 = v513[v536];
    int * v515 = v388->cache_age;
    int v637 = v514 + ((int)((unsigned int)(v514 - v508) >> 31));
    v515[v536] = v637;
    int * v517 = v388->cache_age;
    v517[v625] = 0;
    v520 = v625;
  }
  int v640 = (v520 * 2) + (((int)((unsigned int)v396 >> 2)) & 1);
  int v521 = v407[v640];
  int * v522 = v388->regs;
  v522[9] = v521;
  struct StateT * v524 = slot_10(v388);
  return v524;
}

struct StateT * slot_11(struct StateT * v673) {
  int * v674 = v673->saved_regs;
  int * v675 = v673->regs;
  int v676 = v675[5];
  v674[5] = v676;
  int v678 = v673->timer;
  int v692 = v678 + 1;
  v673->timer = v692;
  int * v680 = v673->regs;
  int v681 = v680[5];
  int * v682 = v673->regs;
  int v683 = v682[16];
  int * v684 = v673->regs;
  int v697 = v681 | v683;
  v684[5] = v697;
  struct StateT * v686 = slot_12(v673);
  return v686;
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