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

struct StateT * slot_12(struct StateT * v550);
struct StateT * slot_14(struct StateT * v76);
struct StateT * slot_6(struct StateT * v103);
struct StateT * slot_5(struct StateT * v86);
struct StateT * slot_2(struct StateT * v28);
struct StateT * slot_7(struct StateT * v307);
struct StateT * slot_3(struct StateT * v41);
struct StateT * snippet(struct StateT * v0);
struct StateT * slot_10(struct StateT * v563);
struct StateT * slot_1(struct StateT * v15);
struct StateT * slot_8(struct StateT * v324);
struct StateT * slot_4(struct StateT * v54);
struct StateT * slot_13(struct StateT * v577);
struct StateT * slot_9(struct StateT * v528);
struct StateT * slot_11(struct StateT * v582);
struct StateT * slot_0(struct StateT * v2);
struct StateT * slot_12(struct StateT * v550) {
  int v551 = v550->timer;
  int v557 = v551 + 1;
  v550->timer = v557;
  int * v553 = v550->regs;
  v553[10] = 0;
  struct StateT * v555 = slot_13(v550);
  return v555;
}

struct StateT * slot_14(struct StateT * v76) {
  int v77 = v76->timer;
  int v82 = v77 + 1;
  v76->timer = v82;
  int * v79 = v76->regs;
  v79[10] = 1;
  return v76;
}

struct StateT * slot_6(struct StateT * v103) {
  int v104 = v103->timer;
  int v214 = v104 + 1;
  v103->timer = v214;
  int * v106 = v103->regs;
  int v107 = v106[5];
  int * v108 = v103->cache_tags;
  int v218 = (((int)((unsigned int)((int)((unsigned int)v107 >> 2)) >> 1)) & 1) * 2;
  int v109 = v108[v218];
  int v219 = ((((int)((unsigned int)((int)((unsigned int)v107 >> 2)) >> 1)) & 1) * 2) + 1;
  int v110 = v108[v219];
  int v220 = 4 + ((((int)((unsigned int)((int)((unsigned int)v107 >> 2)) >> 1)) & 3) * 2);
  int v111 = v108[v220];
  int v221 = (4 + ((((int)((unsigned int)((int)((unsigned int)v107 >> 2)) >> 1)) & 3) * 2)) + 1;
  int v112 = v108[v221];
  int v113 = v103->timer;
  int v222 = v113 + ((100 ^ (((~(((v111 ^ ((int)((unsigned int)((int)((unsigned int)v107 >> 2)) >> 1))) | (-(v111 ^ ((int)((unsigned int)((int)((unsigned int)v107 >> 2)) >> 1))))) >> 31)) | (~(((v112 ^ ((int)((unsigned int)((int)((unsigned int)v107 >> 2)) >> 1))) | (-(v112 ^ ((int)((unsigned int)((int)((unsigned int)v107 >> 2)) >> 1))))) >> 31))) & 104)) ^ (((~(((v109 ^ ((int)((unsigned int)((int)((unsigned int)v107 >> 2)) >> 1))) | (-(v109 ^ ((int)((unsigned int)((int)((unsigned int)v107 >> 2)) >> 1))))) >> 31)) | (~(((v110 ^ ((int)((unsigned int)((int)((unsigned int)v107 >> 2)) >> 1))) | (-(v110 ^ ((int)((unsigned int)((int)((unsigned int)v107 >> 2)) >> 1))))) >> 31))) & (1 ^ (100 ^ (((~(((v111 ^ ((int)((unsigned int)((int)((unsigned int)v107 >> 2)) >> 1))) | (-(v111 ^ ((int)((unsigned int)((int)((unsigned int)v107 >> 2)) >> 1))))) >> 31)) | (~(((v112 ^ ((int)((unsigned int)((int)((unsigned int)v107 >> 2)) >> 1))) | (-(v112 ^ ((int)((unsigned int)((int)((unsigned int)v107 >> 2)) >> 1))))) >> 31))) & 104)))));
  v103->timer = v222;
  int * v115 = v103->cache_vals;
  bool v223 = !(((~(((v109 ^ ((int)((unsigned int)((int)((unsigned int)v107 >> 2)) >> 1))) | (-(v109 ^ ((int)((unsigned int)((int)((unsigned int)v107 >> 2)) >> 1))))) >> 31)) | (~(((v110 ^ ((int)((unsigned int)((int)((unsigned int)v107 >> 2)) >> 1))) | (-(v110 ^ ((int)((unsigned int)((int)((unsigned int)v107 >> 2)) >> 1))))) >> 31))) == 0);
  int v208;
  if (v223) {
    int * v116 = v103->cache_age;
    int v225 = ((((int)((unsigned int)((int)((unsigned int)v107 >> 2)) >> 1)) & 1) * 2) + ((~(((v110 ^ ((int)((unsigned int)((int)((unsigned int)v107 >> 2)) >> 1))) | (-(v110 ^ ((int)((unsigned int)((int)((unsigned int)v107 >> 2)) >> 1))))) >> 31)) & 1);
    int v117 = v116[v225];
    int v118 = v116[v218];
    int v226 = v118 + ((int)((unsigned int)(v118 - v117) >> 31));
    v116[v218] = v226;
    int * v120 = v103->cache_age;
    int v121 = v120[v219];
    int v228 = v121 + ((int)((unsigned int)(v121 - v117) >> 31));
    v120[v219] = v228;
    int * v123 = v103->cache_age;
    v123[v225] = 0;
    v208 = v225;
  } else {
    int * v126 = v103->cache_age;
    int v232 = (((int)((unsigned int)((int)((unsigned int)v107 >> 2)) >> 1)) & 1) * 2;
    int v127 = v126[v232];
    int * v128 = v103->cache_tags;
    int v129 = v128[v232];
    int v130 = v126[v219];
    int v131 = v128[v219];
    bool v234 = !(((~(((v111 ^ ((int)((unsigned int)((int)((unsigned int)v107 >> 2)) >> 1))) | (-(v111 ^ ((int)((unsigned int)((int)((unsigned int)v107 >> 2)) >> 1))))) >> 31)) | (~(((v112 ^ ((int)((unsigned int)((int)((unsigned int)v107 >> 2)) >> 1))) | (-(v112 ^ ((int)((unsigned int)((int)((unsigned int)v107 >> 2)) >> 1))))) >> 31))) == 0);
    int v185;
    if (v234) {
      int * v132 = v103->cache_age;
      int v236 = (4 + ((((int)((unsigned int)((int)((unsigned int)v107 >> 2)) >> 1)) & 3) * 2)) + ((~(((v112 ^ ((int)((unsigned int)((int)((unsigned int)v107 >> 2)) >> 1))) | (-(v112 ^ ((int)((unsigned int)((int)((unsigned int)v107 >> 2)) >> 1))))) >> 31)) & 1);
      int v133 = v132[v236];
      int v134 = v132[v220];
      int v237 = v134 + ((int)((unsigned int)(v134 - v133) >> 31));
      v132[v220] = v237;
      int * v136 = v103->cache_age;
      int v137 = v136[v221];
      int v239 = v137 + ((int)((unsigned int)(v137 - v133) >> 31));
      v136[v221] = v239;
      int * v139 = v103->cache_age;
      v139[v236] = 0;
      v185 = v236;
    } else {
      int * v142 = v103->cache_age;
      int v243 = 4 + ((((int)((unsigned int)((int)((unsigned int)v107 >> 2)) >> 1)) & 3) * 2);
      int v143 = v142[v243];
      int * v144 = v103->cache_tags;
      int v145 = v144[v243];
      int v146 = v142[v221];
      int v147 = v144[v221];
      int * v148 = v103->cache_dirty;
      int v246 = (4 + ((((int)((unsigned int)((int)((unsigned int)v107 >> 2)) >> 1)) & 3) * 2)) + ((((v143 + ((~(((v145 ^ -1) | (-(v145 ^ -1))) >> 31)) & 2)) - (v146 + ((~(((v147 ^ -1) | (-(v147 ^ -1))) >> 31)) & 2))) >> 31) & 1);
      int v149 = v148[v246];
      bool v247 = !(v149 == 0);
      if (v247) {
        int * v150 = v103->cache_tags;
        int v151 = v150[v246];
        int * v152 = v103->cache_vals;
        int v250 = ((4 + ((((int)((unsigned int)((int)((unsigned int)v107 >> 2)) >> 1)) & 3) * 2)) + ((((v143 + ((~(((v145 ^ -1) | (-(v145 ^ -1))) >> 31)) & 2)) - (v146 + ((~(((v147 ^ -1) | (-(v147 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
        int v153 = v152[v250];
        int v251 = (((4 + ((((int)((unsigned int)((int)((unsigned int)v107 >> 2)) >> 1)) & 3) * 2)) + ((((v143 + ((~(((v145 ^ -1) | (-(v145 ^ -1))) >> 31)) & 2)) - (v146 + ((~(((v147 ^ -1) | (-(v147 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
        int v154 = v152[v251];
        int * v155 = v103->mem;
        int v253 = v151 * 2;
        v155[v253] = v153;
        int * v157 = v103->mem;
        int v256 = (v151 * 2) + 1;
        v157[v256] = v154;
        ;
      } else {
        ;
      }
      int * v162 = v103->mem;
      int v261 = ((int)((unsigned int)((int)((unsigned int)v107 >> 2)) >> 1)) * 2;
      int v163 = v162[v261];
      int v262 = (((int)((unsigned int)((int)((unsigned int)v107 >> 2)) >> 1)) * 2) + 1;
      int v164 = v162[v262];
      int * v165 = v103->cache_vals;
      int v264 = ((4 + ((((int)((unsigned int)((int)((unsigned int)v107 >> 2)) >> 1)) & 3) * 2)) + ((((v143 + ((~(((v145 ^ -1) | (-(v145 ^ -1))) >> 31)) & 2)) - (v146 + ((~(((v147 ^ -1) | (-(v147 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
      v165[v264] = v163;
      int * v167 = v103->cache_vals;
      int v267 = (((4 + ((((int)((unsigned int)((int)((unsigned int)v107 >> 2)) >> 1)) & 3) * 2)) + ((((v143 + ((~(((v145 ^ -1) | (-(v145 ^ -1))) >> 31)) & 2)) - (v146 + ((~(((v147 ^ -1) | (-(v147 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
      v167[v267] = v164;
      int * v169 = v103->cache_tags;
      int v270 = (int)((unsigned int)((int)((unsigned int)v107 >> 2)) >> 1);
      v169[v246] = v270;
      int * v171 = v103->cache_dirty;
      v171[v246] = 0;
      int * v173 = v103->cache_age;
      v173[v246] = 1;
      int * v175 = v103->cache_age;
      int v176 = v175[v246];
      int v177 = v175[v220];
      int v276 = v177 + ((int)((unsigned int)(v177 - v176) >> 31));
      v175[v220] = v276;
      int * v179 = v103->cache_age;
      int v180 = v179[v221];
      int v278 = v180 + ((int)((unsigned int)(v180 - v176) >> 31));
      v179[v221] = v278;
      int * v182 = v103->cache_age;
      v182[v246] = 0;
      v185 = v246;
    }
    int * v186 = v103->cache_vals;
    int v281 = v185 * 2;
    int v187 = v186[v281];
    int v282 = (v185 * 2) + 1;
    int v188 = v186[v282];
    int v283 = (((((int)((unsigned int)((int)((unsigned int)v107 >> 2)) >> 1)) & 1) * 2) + ((((v127 + ((~(((v129 ^ -1) | (-(v129 ^ -1))) >> 31)) & 2)) - (v130 + ((~(((v131 ^ -1) | (-(v131 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
    v186[v283] = v187;
    int * v190 = v103->cache_vals;
    int v286 = ((((((int)((unsigned int)((int)((unsigned int)v107 >> 2)) >> 1)) & 1) * 2) + ((((v127 + ((~(((v129 ^ -1) | (-(v129 ^ -1))) >> 31)) & 2)) - (v130 + ((~(((v131 ^ -1) | (-(v131 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
    v190[v286] = v188;
    int * v192 = v103->cache_tags;
    int v289 = ((((int)((unsigned int)((int)((unsigned int)v107 >> 2)) >> 1)) & 1) * 2) + ((((v127 + ((~(((v129 ^ -1) | (-(v129 ^ -1))) >> 31)) & 2)) - (v130 + ((~(((v131 ^ -1) | (-(v131 ^ -1))) >> 31)) & 2))) >> 31) & 1);
    int v290 = (int)((unsigned int)((int)((unsigned int)v107 >> 2)) >> 1);
    v192[v289] = v290;
    int * v194 = v103->cache_dirty;
    v194[v289] = 0;
    int * v196 = v103->cache_age;
    v196[v289] = 1;
    int * v198 = v103->cache_age;
    int v199 = v198[v289];
    int v200 = v198[v218];
    int v296 = v200 + ((int)((unsigned int)(v200 - v199) >> 31));
    v198[v218] = v296;
    int * v202 = v103->cache_age;
    int v203 = v202[v219];
    int v298 = v203 + ((int)((unsigned int)(v203 - v199) >> 31));
    v202[v219] = v298;
    int * v205 = v103->cache_age;
    v205[v289] = 0;
    v208 = v289;
  }
  int v301 = (v208 * 2) + (((int)((unsigned int)v107 >> 2)) & 1);
  int v209 = v115[v301];
  int * v210 = v103->regs;
  v210[10] = v209;
  struct StateT * v212 = slot_7(v103);
  return v212;
}

struct StateT * slot_5(struct StateT * v86) {
  int v87 = v86->timer;
  int v95 = v87 + 1;
  v86->timer = v95;
  int * v89 = v86->regs;
  int v90 = v89[12];
  int v91 = v89[14];
  int v100 = v90 + v91;
  v89[5] = v100;
  struct StateT * v93 = slot_6(v86);
  return v93;
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

struct StateT * slot_7(struct StateT * v307) {
  int v308 = v307->timer;
  int v316 = v308 + 1;
  v307->timer = v316;
  int * v310 = v307->regs;
  int v311 = v310[13];
  int v312 = v310[14];
  int v321 = v311 + v312;
  v310[6] = v321;
  struct StateT * v314 = slot_8(v307);
  return v314;
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

struct StateT * slot_10(struct StateT * v563) {
  int v564 = v563->timer;
  int v571 = v564 + 1;
  v563->timer = v571;
  int * v566 = v563->regs;
  int v567 = v566[14];
  int v574 = v567 + 4;
  v566[14] = v574;
  struct StateT * v569 = slot_11(v563);
  return v569;
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

struct StateT * slot_8(struct StateT * v324) {
  int v325 = v324->timer;
  int v435 = v325 + 1;
  v324->timer = v435;
  int * v327 = v324->regs;
  int v328 = v327[6];
  int * v329 = v324->cache_tags;
  int v439 = (((int)((unsigned int)((int)((unsigned int)v328 >> 2)) >> 1)) & 1) * 2;
  int v330 = v329[v439];
  int v440 = ((((int)((unsigned int)((int)((unsigned int)v328 >> 2)) >> 1)) & 1) * 2) + 1;
  int v331 = v329[v440];
  int v441 = 4 + ((((int)((unsigned int)((int)((unsigned int)v328 >> 2)) >> 1)) & 3) * 2);
  int v332 = v329[v441];
  int v442 = (4 + ((((int)((unsigned int)((int)((unsigned int)v328 >> 2)) >> 1)) & 3) * 2)) + 1;
  int v333 = v329[v442];
  int v334 = v324->timer;
  int v443 = v334 + ((100 ^ (((~(((v332 ^ ((int)((unsigned int)((int)((unsigned int)v328 >> 2)) >> 1))) | (-(v332 ^ ((int)((unsigned int)((int)((unsigned int)v328 >> 2)) >> 1))))) >> 31)) | (~(((v333 ^ ((int)((unsigned int)((int)((unsigned int)v328 >> 2)) >> 1))) | (-(v333 ^ ((int)((unsigned int)((int)((unsigned int)v328 >> 2)) >> 1))))) >> 31))) & 104)) ^ (((~(((v330 ^ ((int)((unsigned int)((int)((unsigned int)v328 >> 2)) >> 1))) | (-(v330 ^ ((int)((unsigned int)((int)((unsigned int)v328 >> 2)) >> 1))))) >> 31)) | (~(((v331 ^ ((int)((unsigned int)((int)((unsigned int)v328 >> 2)) >> 1))) | (-(v331 ^ ((int)((unsigned int)((int)((unsigned int)v328 >> 2)) >> 1))))) >> 31))) & (1 ^ (100 ^ (((~(((v332 ^ ((int)((unsigned int)((int)((unsigned int)v328 >> 2)) >> 1))) | (-(v332 ^ ((int)((unsigned int)((int)((unsigned int)v328 >> 2)) >> 1))))) >> 31)) | (~(((v333 ^ ((int)((unsigned int)((int)((unsigned int)v328 >> 2)) >> 1))) | (-(v333 ^ ((int)((unsigned int)((int)((unsigned int)v328 >> 2)) >> 1))))) >> 31))) & 104)))));
  v324->timer = v443;
  int * v336 = v324->cache_vals;
  bool v444 = !(((~(((v330 ^ ((int)((unsigned int)((int)((unsigned int)v328 >> 2)) >> 1))) | (-(v330 ^ ((int)((unsigned int)((int)((unsigned int)v328 >> 2)) >> 1))))) >> 31)) | (~(((v331 ^ ((int)((unsigned int)((int)((unsigned int)v328 >> 2)) >> 1))) | (-(v331 ^ ((int)((unsigned int)((int)((unsigned int)v328 >> 2)) >> 1))))) >> 31))) == 0);
  int v429;
  if (v444) {
    int * v337 = v324->cache_age;
    int v446 = ((((int)((unsigned int)((int)((unsigned int)v328 >> 2)) >> 1)) & 1) * 2) + ((~(((v331 ^ ((int)((unsigned int)((int)((unsigned int)v328 >> 2)) >> 1))) | (-(v331 ^ ((int)((unsigned int)((int)((unsigned int)v328 >> 2)) >> 1))))) >> 31)) & 1);
    int v338 = v337[v446];
    int v339 = v337[v439];
    int v447 = v339 + ((int)((unsigned int)(v339 - v338) >> 31));
    v337[v439] = v447;
    int * v341 = v324->cache_age;
    int v342 = v341[v440];
    int v449 = v342 + ((int)((unsigned int)(v342 - v338) >> 31));
    v341[v440] = v449;
    int * v344 = v324->cache_age;
    v344[v446] = 0;
    v429 = v446;
  } else {
    int * v347 = v324->cache_age;
    int v453 = (((int)((unsigned int)((int)((unsigned int)v328 >> 2)) >> 1)) & 1) * 2;
    int v348 = v347[v453];
    int * v349 = v324->cache_tags;
    int v350 = v349[v453];
    int v351 = v347[v440];
    int v352 = v349[v440];
    bool v455 = !(((~(((v332 ^ ((int)((unsigned int)((int)((unsigned int)v328 >> 2)) >> 1))) | (-(v332 ^ ((int)((unsigned int)((int)((unsigned int)v328 >> 2)) >> 1))))) >> 31)) | (~(((v333 ^ ((int)((unsigned int)((int)((unsigned int)v328 >> 2)) >> 1))) | (-(v333 ^ ((int)((unsigned int)((int)((unsigned int)v328 >> 2)) >> 1))))) >> 31))) == 0);
    int v406;
    if (v455) {
      int * v353 = v324->cache_age;
      int v457 = (4 + ((((int)((unsigned int)((int)((unsigned int)v328 >> 2)) >> 1)) & 3) * 2)) + ((~(((v333 ^ ((int)((unsigned int)((int)((unsigned int)v328 >> 2)) >> 1))) | (-(v333 ^ ((int)((unsigned int)((int)((unsigned int)v328 >> 2)) >> 1))))) >> 31)) & 1);
      int v354 = v353[v457];
      int v355 = v353[v441];
      int v458 = v355 + ((int)((unsigned int)(v355 - v354) >> 31));
      v353[v441] = v458;
      int * v357 = v324->cache_age;
      int v358 = v357[v442];
      int v460 = v358 + ((int)((unsigned int)(v358 - v354) >> 31));
      v357[v442] = v460;
      int * v360 = v324->cache_age;
      v360[v457] = 0;
      v406 = v457;
    } else {
      int * v363 = v324->cache_age;
      int v464 = 4 + ((((int)((unsigned int)((int)((unsigned int)v328 >> 2)) >> 1)) & 3) * 2);
      int v364 = v363[v464];
      int * v365 = v324->cache_tags;
      int v366 = v365[v464];
      int v367 = v363[v442];
      int v368 = v365[v442];
      int * v369 = v324->cache_dirty;
      int v467 = (4 + ((((int)((unsigned int)((int)((unsigned int)v328 >> 2)) >> 1)) & 3) * 2)) + ((((v364 + ((~(((v366 ^ -1) | (-(v366 ^ -1))) >> 31)) & 2)) - (v367 + ((~(((v368 ^ -1) | (-(v368 ^ -1))) >> 31)) & 2))) >> 31) & 1);
      int v370 = v369[v467];
      bool v468 = !(v370 == 0);
      if (v468) {
        int * v371 = v324->cache_tags;
        int v372 = v371[v467];
        int * v373 = v324->cache_vals;
        int v471 = ((4 + ((((int)((unsigned int)((int)((unsigned int)v328 >> 2)) >> 1)) & 3) * 2)) + ((((v364 + ((~(((v366 ^ -1) | (-(v366 ^ -1))) >> 31)) & 2)) - (v367 + ((~(((v368 ^ -1) | (-(v368 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
        int v374 = v373[v471];
        int v472 = (((4 + ((((int)((unsigned int)((int)((unsigned int)v328 >> 2)) >> 1)) & 3) * 2)) + ((((v364 + ((~(((v366 ^ -1) | (-(v366 ^ -1))) >> 31)) & 2)) - (v367 + ((~(((v368 ^ -1) | (-(v368 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
        int v375 = v373[v472];
        int * v376 = v324->mem;
        int v474 = v372 * 2;
        v376[v474] = v374;
        int * v378 = v324->mem;
        int v477 = (v372 * 2) + 1;
        v378[v477] = v375;
        ;
      } else {
        ;
      }
      int * v383 = v324->mem;
      int v482 = ((int)((unsigned int)((int)((unsigned int)v328 >> 2)) >> 1)) * 2;
      int v384 = v383[v482];
      int v483 = (((int)((unsigned int)((int)((unsigned int)v328 >> 2)) >> 1)) * 2) + 1;
      int v385 = v383[v483];
      int * v386 = v324->cache_vals;
      int v485 = ((4 + ((((int)((unsigned int)((int)((unsigned int)v328 >> 2)) >> 1)) & 3) * 2)) + ((((v364 + ((~(((v366 ^ -1) | (-(v366 ^ -1))) >> 31)) & 2)) - (v367 + ((~(((v368 ^ -1) | (-(v368 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
      v386[v485] = v384;
      int * v388 = v324->cache_vals;
      int v488 = (((4 + ((((int)((unsigned int)((int)((unsigned int)v328 >> 2)) >> 1)) & 3) * 2)) + ((((v364 + ((~(((v366 ^ -1) | (-(v366 ^ -1))) >> 31)) & 2)) - (v367 + ((~(((v368 ^ -1) | (-(v368 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
      v388[v488] = v385;
      int * v390 = v324->cache_tags;
      int v491 = (int)((unsigned int)((int)((unsigned int)v328 >> 2)) >> 1);
      v390[v467] = v491;
      int * v392 = v324->cache_dirty;
      v392[v467] = 0;
      int * v394 = v324->cache_age;
      v394[v467] = 1;
      int * v396 = v324->cache_age;
      int v397 = v396[v467];
      int v398 = v396[v441];
      int v497 = v398 + ((int)((unsigned int)(v398 - v397) >> 31));
      v396[v441] = v497;
      int * v400 = v324->cache_age;
      int v401 = v400[v442];
      int v499 = v401 + ((int)((unsigned int)(v401 - v397) >> 31));
      v400[v442] = v499;
      int * v403 = v324->cache_age;
      v403[v467] = 0;
      v406 = v467;
    }
    int * v407 = v324->cache_vals;
    int v502 = v406 * 2;
    int v408 = v407[v502];
    int v503 = (v406 * 2) + 1;
    int v409 = v407[v503];
    int v504 = (((((int)((unsigned int)((int)((unsigned int)v328 >> 2)) >> 1)) & 1) * 2) + ((((v348 + ((~(((v350 ^ -1) | (-(v350 ^ -1))) >> 31)) & 2)) - (v351 + ((~(((v352 ^ -1) | (-(v352 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
    v407[v504] = v408;
    int * v411 = v324->cache_vals;
    int v507 = ((((((int)((unsigned int)((int)((unsigned int)v328 >> 2)) >> 1)) & 1) * 2) + ((((v348 + ((~(((v350 ^ -1) | (-(v350 ^ -1))) >> 31)) & 2)) - (v351 + ((~(((v352 ^ -1) | (-(v352 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
    v411[v507] = v409;
    int * v413 = v324->cache_tags;
    int v510 = ((((int)((unsigned int)((int)((unsigned int)v328 >> 2)) >> 1)) & 1) * 2) + ((((v348 + ((~(((v350 ^ -1) | (-(v350 ^ -1))) >> 31)) & 2)) - (v351 + ((~(((v352 ^ -1) | (-(v352 ^ -1))) >> 31)) & 2))) >> 31) & 1);
    int v511 = (int)((unsigned int)((int)((unsigned int)v328 >> 2)) >> 1);
    v413[v510] = v511;
    int * v415 = v324->cache_dirty;
    v415[v510] = 0;
    int * v417 = v324->cache_age;
    v417[v510] = 1;
    int * v419 = v324->cache_age;
    int v420 = v419[v510];
    int v421 = v419[v439];
    int v517 = v421 + ((int)((unsigned int)(v421 - v420) >> 31));
    v419[v439] = v517;
    int * v423 = v324->cache_age;
    int v424 = v423[v440];
    int v519 = v424 + ((int)((unsigned int)(v424 - v420) >> 31));
    v423[v440] = v519;
    int * v426 = v324->cache_age;
    v426[v510] = 0;
    v429 = v510;
  }
  int v522 = (v429 * 2) + (((int)((unsigned int)v328 >> 2)) & 1);
  int v430 = v336[v522];
  int * v431 = v324->regs;
  v431[11] = v430;
  struct StateT * v433 = slot_9(v324);
  return v433;
}

struct StateT * slot_4(struct StateT * v54) {
  int v55 = v54->timer;
  int v66 = v55 + 1;
  v54->timer = v66;
  int * v57 = v54->regs;
  int v58 = v57[14];
  int v59 = v57[15];
  bool v70 = v58 >= v59;
  struct StateT * v64;
  if (v70) {
    struct StateT * v60 = slot_14(v54);
    v64 = v60;
  } else {
    struct StateT * v62 = slot_5(v54);
    v64 = v62;
  }
  return v64;
}

struct StateT * slot_13(struct StateT * v577) {
  int v578 = v577->timer;
  int v581 = v578 + 1;
  v577->timer = v581;
  return v577;
}

struct StateT * slot_9(struct StateT * v528) {
  int v529 = v528->timer;
  int v540 = v529 + 1;
  v528->timer = v540;
  int * v531 = v528->regs;
  int v532 = v531[10];
  int v533 = v531[11];
  bool v544 = !(v532 == v533);
  struct StateT * v538;
  if (v544) {
    struct StateT * v534 = slot_12(v528);
    v538 = v534;
  } else {
    struct StateT * v536 = slot_10(v528);
    v538 = v536;
  }
  return v538;
}

struct StateT * slot_11(struct StateT * v582) {
  int v583 = v582->timer;
  int v587 = v583 + 1;
  v582->timer = v587;
  struct StateT * v585 = slot_4(v582);
  return v585;
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
    s1.mem[SECRET_OFFSET+i] = secret(0, 20);
    s2.mem[SECRET_OFFSET+i] = secret(0, 20);
  }
  struct StateT *s1_ = snippet(&s1);
  struct StateT *s2_ = snippet(&s2);
  //@ assert untainted_timer: !\tainted(s1_->timer==s2_->timer);
  koika_assert(s1_->timer==s2_->timer, "timing leak");
  return 0;
}