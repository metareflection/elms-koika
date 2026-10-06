// verify: clean (Eva should report untainted_timer: Valid) [unroll 65]
#define NUM_REGS 32
#define MEM_SIZE 64
#define SECRET_SIZE 10
#define SECRET_OFFSET 20
#define CACHE_ENTRIES 12
#define CACHE_WORDS 24

#ifdef EVA
#include "__fc_builtin.h"
/*@ assigns *p \from \nothing;
    taints *p; */
void koika_mark(int *p);
#define koika_assert(b, s) ((void)0)
#define koika_assume(b) do { if (!(b)) Frama_C_abort(); } while (0)
#define koika_draw(x) ((x) = Frama_C_interval(-2147483647-1, 2147483647))
#define koika_secret(x) koika_mark(&(x))
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

struct StateT * snippet(struct StateT * v0);
struct StateT * slot_1(struct StateT * v15);
struct StateT * slot_6(struct StateT * v281);
struct StateT * slot_5(struct StateT * v77);
struct StateT * slot_4(struct StateT * v60);
struct StateT * slot_2(struct StateT * v28);
struct StateT * slot_7(struct StateT * v295);
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

struct StateT * slot_6(struct StateT * v281) {
  int v282 = v281->timer;
  int v289 = v282 + 1;
  v281->timer = v289;
  int * v284 = v281->regs;
  int v285 = v284[11];
  int v292 = v285 << 2;
  v284[11] = v292;
  struct StateT * v287 = slot_7(v281);
  return v287;
}

struct StateT * slot_5(struct StateT * v77) {
  int v78 = v77->timer;
  int v188 = v78 + 1;
  v77->timer = v188;
  int * v80 = v77->regs;
  int v81 = v80[5];
  int * v82 = v77->cache_tags;
  int v192 = (((int)((unsigned int)((int)((unsigned int)v81 >> 2)) >> 1)) & 1) * 2;
  int v83 = v82[v192];
  int v193 = ((((int)((unsigned int)((int)((unsigned int)v81 >> 2)) >> 1)) & 1) * 2) + 1;
  int v84 = v82[v193];
  int v194 = 4 + ((((int)((unsigned int)((int)((unsigned int)v81 >> 2)) >> 1)) & 3) * 2);
  int v85 = v82[v194];
  int v195 = (4 + ((((int)((unsigned int)((int)((unsigned int)v81 >> 2)) >> 1)) & 3) * 2)) + 1;
  int v86 = v82[v195];
  int v87 = v77->timer;
  int v196 = v87 + ((100 ^ (((~(((v85 ^ ((int)((unsigned int)((int)((unsigned int)v81 >> 2)) >> 1))) | (-(v85 ^ ((int)((unsigned int)((int)((unsigned int)v81 >> 2)) >> 1))))) >> 31)) | (~(((v86 ^ ((int)((unsigned int)((int)((unsigned int)v81 >> 2)) >> 1))) | (-(v86 ^ ((int)((unsigned int)((int)((unsigned int)v81 >> 2)) >> 1))))) >> 31))) & 104)) ^ (((~(((v83 ^ ((int)((unsigned int)((int)((unsigned int)v81 >> 2)) >> 1))) | (-(v83 ^ ((int)((unsigned int)((int)((unsigned int)v81 >> 2)) >> 1))))) >> 31)) | (~(((v84 ^ ((int)((unsigned int)((int)((unsigned int)v81 >> 2)) >> 1))) | (-(v84 ^ ((int)((unsigned int)((int)((unsigned int)v81 >> 2)) >> 1))))) >> 31))) & (1 ^ (100 ^ (((~(((v85 ^ ((int)((unsigned int)((int)((unsigned int)v81 >> 2)) >> 1))) | (-(v85 ^ ((int)((unsigned int)((int)((unsigned int)v81 >> 2)) >> 1))))) >> 31)) | (~(((v86 ^ ((int)((unsigned int)((int)((unsigned int)v81 >> 2)) >> 1))) | (-(v86 ^ ((int)((unsigned int)((int)((unsigned int)v81 >> 2)) >> 1))))) >> 31))) & 104)))));
  v77->timer = v196;
  int * v89 = v77->cache_vals;
  bool v197 = !(((~(((v83 ^ ((int)((unsigned int)((int)((unsigned int)v81 >> 2)) >> 1))) | (-(v83 ^ ((int)((unsigned int)((int)((unsigned int)v81 >> 2)) >> 1))))) >> 31)) | (~(((v84 ^ ((int)((unsigned int)((int)((unsigned int)v81 >> 2)) >> 1))) | (-(v84 ^ ((int)((unsigned int)((int)((unsigned int)v81 >> 2)) >> 1))))) >> 31))) == 0);
  int v182;
  if (v197) {
    int * v90 = v77->cache_age;
    int v199 = ((((int)((unsigned int)((int)((unsigned int)v81 >> 2)) >> 1)) & 1) * 2) + ((~(((v84 ^ ((int)((unsigned int)((int)((unsigned int)v81 >> 2)) >> 1))) | (-(v84 ^ ((int)((unsigned int)((int)((unsigned int)v81 >> 2)) >> 1))))) >> 31)) & 1);
    int v91 = v90[v199];
    int v92 = v90[v192];
    int v200 = v92 + ((int)((unsigned int)(v92 - v91) >> 31));
    v90[v192] = v200;
    int * v94 = v77->cache_age;
    int v95 = v94[v193];
    int v202 = v95 + ((int)((unsigned int)(v95 - v91) >> 31));
    v94[v193] = v202;
    int * v97 = v77->cache_age;
    v97[v199] = 0;
    v182 = v199;
  } else {
    int * v100 = v77->cache_age;
    int v206 = (((int)((unsigned int)((int)((unsigned int)v81 >> 2)) >> 1)) & 1) * 2;
    int v101 = v100[v206];
    int * v102 = v77->cache_tags;
    int v103 = v102[v206];
    int v104 = v100[v193];
    int v105 = v102[v193];
    bool v208 = !(((~(((v85 ^ ((int)((unsigned int)((int)((unsigned int)v81 >> 2)) >> 1))) | (-(v85 ^ ((int)((unsigned int)((int)((unsigned int)v81 >> 2)) >> 1))))) >> 31)) | (~(((v86 ^ ((int)((unsigned int)((int)((unsigned int)v81 >> 2)) >> 1))) | (-(v86 ^ ((int)((unsigned int)((int)((unsigned int)v81 >> 2)) >> 1))))) >> 31))) == 0);
    int v159;
    if (v208) {
      int * v106 = v77->cache_age;
      int v210 = (4 + ((((int)((unsigned int)((int)((unsigned int)v81 >> 2)) >> 1)) & 3) * 2)) + ((~(((v86 ^ ((int)((unsigned int)((int)((unsigned int)v81 >> 2)) >> 1))) | (-(v86 ^ ((int)((unsigned int)((int)((unsigned int)v81 >> 2)) >> 1))))) >> 31)) & 1);
      int v107 = v106[v210];
      int v108 = v106[v194];
      int v211 = v108 + ((int)((unsigned int)(v108 - v107) >> 31));
      v106[v194] = v211;
      int * v110 = v77->cache_age;
      int v111 = v110[v195];
      int v213 = v111 + ((int)((unsigned int)(v111 - v107) >> 31));
      v110[v195] = v213;
      int * v113 = v77->cache_age;
      v113[v210] = 0;
      v159 = v210;
    } else {
      int * v116 = v77->cache_age;
      int v217 = 4 + ((((int)((unsigned int)((int)((unsigned int)v81 >> 2)) >> 1)) & 3) * 2);
      int v117 = v116[v217];
      int * v118 = v77->cache_tags;
      int v119 = v118[v217];
      int v120 = v116[v195];
      int v121 = v118[v195];
      int * v122 = v77->cache_dirty;
      int v220 = (4 + ((((int)((unsigned int)((int)((unsigned int)v81 >> 2)) >> 1)) & 3) * 2)) + ((((v117 + ((~(((v119 ^ -1) | (-(v119 ^ -1))) >> 31)) & 2)) - (v120 + ((~(((v121 ^ -1) | (-(v121 ^ -1))) >> 31)) & 2))) >> 31) & 1);
      int v123 = v122[v220];
      bool v221 = !(v123 == 0);
      if (v221) {
        int * v124 = v77->cache_tags;
        int v125 = v124[v220];
        int * v126 = v77->cache_vals;
        int v224 = ((4 + ((((int)((unsigned int)((int)((unsigned int)v81 >> 2)) >> 1)) & 3) * 2)) + ((((v117 + ((~(((v119 ^ -1) | (-(v119 ^ -1))) >> 31)) & 2)) - (v120 + ((~(((v121 ^ -1) | (-(v121 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
        int v127 = v126[v224];
        int v225 = (((4 + ((((int)((unsigned int)((int)((unsigned int)v81 >> 2)) >> 1)) & 3) * 2)) + ((((v117 + ((~(((v119 ^ -1) | (-(v119 ^ -1))) >> 31)) & 2)) - (v120 + ((~(((v121 ^ -1) | (-(v121 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
        int v128 = v126[v225];
        int * v129 = v77->mem;
        int v227 = v125 * 2;
        v129[v227] = v127;
        int * v131 = v77->mem;
        int v230 = (v125 * 2) + 1;
        v131[v230] = v128;
        ;
      } else {
        ;
      }
      int * v136 = v77->mem;
      int v235 = ((int)((unsigned int)((int)((unsigned int)v81 >> 2)) >> 1)) * 2;
      int v137 = v136[v235];
      int v236 = (((int)((unsigned int)((int)((unsigned int)v81 >> 2)) >> 1)) * 2) + 1;
      int v138 = v136[v236];
      int * v139 = v77->cache_vals;
      int v238 = ((4 + ((((int)((unsigned int)((int)((unsigned int)v81 >> 2)) >> 1)) & 3) * 2)) + ((((v117 + ((~(((v119 ^ -1) | (-(v119 ^ -1))) >> 31)) & 2)) - (v120 + ((~(((v121 ^ -1) | (-(v121 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
      v139[v238] = v137;
      int * v141 = v77->cache_vals;
      int v241 = (((4 + ((((int)((unsigned int)((int)((unsigned int)v81 >> 2)) >> 1)) & 3) * 2)) + ((((v117 + ((~(((v119 ^ -1) | (-(v119 ^ -1))) >> 31)) & 2)) - (v120 + ((~(((v121 ^ -1) | (-(v121 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
      v141[v241] = v138;
      int * v143 = v77->cache_tags;
      int v244 = (int)((unsigned int)((int)((unsigned int)v81 >> 2)) >> 1);
      v143[v220] = v244;
      int * v145 = v77->cache_dirty;
      v145[v220] = 0;
      int * v147 = v77->cache_age;
      v147[v220] = 1;
      int * v149 = v77->cache_age;
      int v150 = v149[v220];
      int v151 = v149[v194];
      int v250 = v151 + ((int)((unsigned int)(v151 - v150) >> 31));
      v149[v194] = v250;
      int * v153 = v77->cache_age;
      int v154 = v153[v195];
      int v252 = v154 + ((int)((unsigned int)(v154 - v150) >> 31));
      v153[v195] = v252;
      int * v156 = v77->cache_age;
      v156[v220] = 0;
      v159 = v220;
    }
    int * v160 = v77->cache_vals;
    int v255 = v159 * 2;
    int v161 = v160[v255];
    int v256 = (v159 * 2) + 1;
    int v162 = v160[v256];
    int v257 = (((((int)((unsigned int)((int)((unsigned int)v81 >> 2)) >> 1)) & 1) * 2) + ((((v101 + ((~(((v103 ^ -1) | (-(v103 ^ -1))) >> 31)) & 2)) - (v104 + ((~(((v105 ^ -1) | (-(v105 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
    v160[v257] = v161;
    int * v164 = v77->cache_vals;
    int v260 = ((((((int)((unsigned int)((int)((unsigned int)v81 >> 2)) >> 1)) & 1) * 2) + ((((v101 + ((~(((v103 ^ -1) | (-(v103 ^ -1))) >> 31)) & 2)) - (v104 + ((~(((v105 ^ -1) | (-(v105 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
    v164[v260] = v162;
    int * v166 = v77->cache_tags;
    int v263 = ((((int)((unsigned int)((int)((unsigned int)v81 >> 2)) >> 1)) & 1) * 2) + ((((v101 + ((~(((v103 ^ -1) | (-(v103 ^ -1))) >> 31)) & 2)) - (v104 + ((~(((v105 ^ -1) | (-(v105 ^ -1))) >> 31)) & 2))) >> 31) & 1);
    int v264 = (int)((unsigned int)((int)((unsigned int)v81 >> 2)) >> 1);
    v166[v263] = v264;
    int * v168 = v77->cache_dirty;
    v168[v263] = 0;
    int * v170 = v77->cache_age;
    v170[v263] = 1;
    int * v172 = v77->cache_age;
    int v173 = v172[v263];
    int v174 = v172[v192];
    int v270 = v174 + ((int)((unsigned int)(v174 - v173) >> 31));
    v172[v192] = v270;
    int * v176 = v77->cache_age;
    int v177 = v176[v193];
    int v272 = v177 + ((int)((unsigned int)(v177 - v173) >> 31));
    v176[v193] = v272;
    int * v179 = v77->cache_age;
    v179[v263] = 0;
    v182 = v263;
  }
  int v275 = (v182 * 2) + (((int)((unsigned int)v81 >> 2)) & 1);
  int v183 = v89[v275];
  int * v184 = v77->regs;
  v184[11] = v183;
  struct StateT * v186 = slot_6(v77);
  return v186;
}

struct StateT * slot_4(struct StateT * v60) {
  int v61 = v60->timer;
  int v69 = v61 + 1;
  v60->timer = v69;
  int * v63 = v60->regs;
  int v64 = v63[13];
  int v65 = v63[10];
  int v74 = v64 + v65;
  v63[5] = v74;
  struct StateT * v67 = slot_5(v60);
  return v67;
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

struct StateT * slot_7(struct StateT * v295) {
  int v296 = v295->timer;
  int v405 = v296 + 1;
  v295->timer = v405;
  int * v298 = v295->regs;
  int v299 = v298[11];
  int * v300 = v295->cache_tags;
  int v409 = (((int)((unsigned int)((int)((unsigned int)v299 >> 2)) >> 1)) & 1) * 2;
  int v301 = v300[v409];
  int v410 = ((((int)((unsigned int)((int)((unsigned int)v299 >> 2)) >> 1)) & 1) * 2) + 1;
  int v302 = v300[v410];
  int v411 = 4 + ((((int)((unsigned int)((int)((unsigned int)v299 >> 2)) >> 1)) & 3) * 2);
  int v303 = v300[v411];
  int v412 = (4 + ((((int)((unsigned int)((int)((unsigned int)v299 >> 2)) >> 1)) & 3) * 2)) + 1;
  int v304 = v300[v412];
  int v305 = v295->timer;
  int v413 = v305 + ((100 ^ (((~(((v303 ^ ((int)((unsigned int)((int)((unsigned int)v299 >> 2)) >> 1))) | (-(v303 ^ ((int)((unsigned int)((int)((unsigned int)v299 >> 2)) >> 1))))) >> 31)) | (~(((v304 ^ ((int)((unsigned int)((int)((unsigned int)v299 >> 2)) >> 1))) | (-(v304 ^ ((int)((unsigned int)((int)((unsigned int)v299 >> 2)) >> 1))))) >> 31))) & 104)) ^ (((~(((v301 ^ ((int)((unsigned int)((int)((unsigned int)v299 >> 2)) >> 1))) | (-(v301 ^ ((int)((unsigned int)((int)((unsigned int)v299 >> 2)) >> 1))))) >> 31)) | (~(((v302 ^ ((int)((unsigned int)((int)((unsigned int)v299 >> 2)) >> 1))) | (-(v302 ^ ((int)((unsigned int)((int)((unsigned int)v299 >> 2)) >> 1))))) >> 31))) & (1 ^ (100 ^ (((~(((v303 ^ ((int)((unsigned int)((int)((unsigned int)v299 >> 2)) >> 1))) | (-(v303 ^ ((int)((unsigned int)((int)((unsigned int)v299 >> 2)) >> 1))))) >> 31)) | (~(((v304 ^ ((int)((unsigned int)((int)((unsigned int)v299 >> 2)) >> 1))) | (-(v304 ^ ((int)((unsigned int)((int)((unsigned int)v299 >> 2)) >> 1))))) >> 31))) & 104)))));
  v295->timer = v413;
  int * v307 = v295->cache_vals;
  bool v414 = !(((~(((v301 ^ ((int)((unsigned int)((int)((unsigned int)v299 >> 2)) >> 1))) | (-(v301 ^ ((int)((unsigned int)((int)((unsigned int)v299 >> 2)) >> 1))))) >> 31)) | (~(((v302 ^ ((int)((unsigned int)((int)((unsigned int)v299 >> 2)) >> 1))) | (-(v302 ^ ((int)((unsigned int)((int)((unsigned int)v299 >> 2)) >> 1))))) >> 31))) == 0);
  int v400;
  if (v414) {
    int * v308 = v295->cache_age;
    int v416 = ((((int)((unsigned int)((int)((unsigned int)v299 >> 2)) >> 1)) & 1) * 2) + ((~(((v302 ^ ((int)((unsigned int)((int)((unsigned int)v299 >> 2)) >> 1))) | (-(v302 ^ ((int)((unsigned int)((int)((unsigned int)v299 >> 2)) >> 1))))) >> 31)) & 1);
    int v309 = v308[v416];
    int v310 = v308[v409];
    int v417 = v310 + ((int)((unsigned int)(v310 - v309) >> 31));
    v308[v409] = v417;
    int * v312 = v295->cache_age;
    int v313 = v312[v410];
    int v419 = v313 + ((int)((unsigned int)(v313 - v309) >> 31));
    v312[v410] = v419;
    int * v315 = v295->cache_age;
    v315[v416] = 0;
    v400 = v416;
  } else {
    int * v318 = v295->cache_age;
    int v423 = (((int)((unsigned int)((int)((unsigned int)v299 >> 2)) >> 1)) & 1) * 2;
    int v319 = v318[v423];
    int * v320 = v295->cache_tags;
    int v321 = v320[v423];
    int v322 = v318[v410];
    int v323 = v320[v410];
    bool v425 = !(((~(((v303 ^ ((int)((unsigned int)((int)((unsigned int)v299 >> 2)) >> 1))) | (-(v303 ^ ((int)((unsigned int)((int)((unsigned int)v299 >> 2)) >> 1))))) >> 31)) | (~(((v304 ^ ((int)((unsigned int)((int)((unsigned int)v299 >> 2)) >> 1))) | (-(v304 ^ ((int)((unsigned int)((int)((unsigned int)v299 >> 2)) >> 1))))) >> 31))) == 0);
    int v377;
    if (v425) {
      int * v324 = v295->cache_age;
      int v427 = (4 + ((((int)((unsigned int)((int)((unsigned int)v299 >> 2)) >> 1)) & 3) * 2)) + ((~(((v304 ^ ((int)((unsigned int)((int)((unsigned int)v299 >> 2)) >> 1))) | (-(v304 ^ ((int)((unsigned int)((int)((unsigned int)v299 >> 2)) >> 1))))) >> 31)) & 1);
      int v325 = v324[v427];
      int v326 = v324[v411];
      int v428 = v326 + ((int)((unsigned int)(v326 - v325) >> 31));
      v324[v411] = v428;
      int * v328 = v295->cache_age;
      int v329 = v328[v412];
      int v430 = v329 + ((int)((unsigned int)(v329 - v325) >> 31));
      v328[v412] = v430;
      int * v331 = v295->cache_age;
      v331[v427] = 0;
      v377 = v427;
    } else {
      int * v334 = v295->cache_age;
      int v434 = 4 + ((((int)((unsigned int)((int)((unsigned int)v299 >> 2)) >> 1)) & 3) * 2);
      int v335 = v334[v434];
      int * v336 = v295->cache_tags;
      int v337 = v336[v434];
      int v338 = v334[v412];
      int v339 = v336[v412];
      int * v340 = v295->cache_dirty;
      int v437 = (4 + ((((int)((unsigned int)((int)((unsigned int)v299 >> 2)) >> 1)) & 3) * 2)) + ((((v335 + ((~(((v337 ^ -1) | (-(v337 ^ -1))) >> 31)) & 2)) - (v338 + ((~(((v339 ^ -1) | (-(v339 ^ -1))) >> 31)) & 2))) >> 31) & 1);
      int v341 = v340[v437];
      bool v438 = !(v341 == 0);
      if (v438) {
        int * v342 = v295->cache_tags;
        int v343 = v342[v437];
        int * v344 = v295->cache_vals;
        int v441 = ((4 + ((((int)((unsigned int)((int)((unsigned int)v299 >> 2)) >> 1)) & 3) * 2)) + ((((v335 + ((~(((v337 ^ -1) | (-(v337 ^ -1))) >> 31)) & 2)) - (v338 + ((~(((v339 ^ -1) | (-(v339 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
        int v345 = v344[v441];
        int v442 = (((4 + ((((int)((unsigned int)((int)((unsigned int)v299 >> 2)) >> 1)) & 3) * 2)) + ((((v335 + ((~(((v337 ^ -1) | (-(v337 ^ -1))) >> 31)) & 2)) - (v338 + ((~(((v339 ^ -1) | (-(v339 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
        int v346 = v344[v442];
        int * v347 = v295->mem;
        int v444 = v343 * 2;
        v347[v444] = v345;
        int * v349 = v295->mem;
        int v447 = (v343 * 2) + 1;
        v349[v447] = v346;
        ;
      } else {
        ;
      }
      int * v354 = v295->mem;
      int v452 = ((int)((unsigned int)((int)((unsigned int)v299 >> 2)) >> 1)) * 2;
      int v355 = v354[v452];
      int v453 = (((int)((unsigned int)((int)((unsigned int)v299 >> 2)) >> 1)) * 2) + 1;
      int v356 = v354[v453];
      int * v357 = v295->cache_vals;
      int v455 = ((4 + ((((int)((unsigned int)((int)((unsigned int)v299 >> 2)) >> 1)) & 3) * 2)) + ((((v335 + ((~(((v337 ^ -1) | (-(v337 ^ -1))) >> 31)) & 2)) - (v338 + ((~(((v339 ^ -1) | (-(v339 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
      v357[v455] = v355;
      int * v359 = v295->cache_vals;
      int v458 = (((4 + ((((int)((unsigned int)((int)((unsigned int)v299 >> 2)) >> 1)) & 3) * 2)) + ((((v335 + ((~(((v337 ^ -1) | (-(v337 ^ -1))) >> 31)) & 2)) - (v338 + ((~(((v339 ^ -1) | (-(v339 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
      v359[v458] = v356;
      int * v361 = v295->cache_tags;
      int v461 = (int)((unsigned int)((int)((unsigned int)v299 >> 2)) >> 1);
      v361[v437] = v461;
      int * v363 = v295->cache_dirty;
      v363[v437] = 0;
      int * v365 = v295->cache_age;
      v365[v437] = 1;
      int * v367 = v295->cache_age;
      int v368 = v367[v437];
      int v369 = v367[v411];
      int v467 = v369 + ((int)((unsigned int)(v369 - v368) >> 31));
      v367[v411] = v467;
      int * v371 = v295->cache_age;
      int v372 = v371[v412];
      int v469 = v372 + ((int)((unsigned int)(v372 - v368) >> 31));
      v371[v412] = v469;
      int * v374 = v295->cache_age;
      v374[v437] = 0;
      v377 = v437;
    }
    int * v378 = v295->cache_vals;
    int v472 = v377 * 2;
    int v379 = v378[v472];
    int v473 = (v377 * 2) + 1;
    int v380 = v378[v473];
    int v474 = (((((int)((unsigned int)((int)((unsigned int)v299 >> 2)) >> 1)) & 1) * 2) + ((((v319 + ((~(((v321 ^ -1) | (-(v321 ^ -1))) >> 31)) & 2)) - (v322 + ((~(((v323 ^ -1) | (-(v323 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
    v378[v474] = v379;
    int * v382 = v295->cache_vals;
    int v477 = ((((((int)((unsigned int)((int)((unsigned int)v299 >> 2)) >> 1)) & 1) * 2) + ((((v319 + ((~(((v321 ^ -1) | (-(v321 ^ -1))) >> 31)) & 2)) - (v322 + ((~(((v323 ^ -1) | (-(v323 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
    v382[v477] = v380;
    int * v384 = v295->cache_tags;
    int v480 = ((((int)((unsigned int)((int)((unsigned int)v299 >> 2)) >> 1)) & 1) * 2) + ((((v319 + ((~(((v321 ^ -1) | (-(v321 ^ -1))) >> 31)) & 2)) - (v322 + ((~(((v323 ^ -1) | (-(v323 ^ -1))) >> 31)) & 2))) >> 31) & 1);
    int v481 = (int)((unsigned int)((int)((unsigned int)v299 >> 2)) >> 1);
    v384[v480] = v481;
    int * v386 = v295->cache_dirty;
    v386[v480] = 0;
    int * v388 = v295->cache_age;
    v388[v480] = 1;
    int * v390 = v295->cache_age;
    int v391 = v390[v480];
    int v392 = v390[v409];
    int v487 = v392 + ((int)((unsigned int)(v392 - v391) >> 31));
    v390[v409] = v487;
    int * v394 = v295->cache_age;
    int v395 = v394[v410];
    int v489 = v395 + ((int)((unsigned int)(v395 - v391) >> 31));
    v394[v410] = v489;
    int * v397 = v295->cache_age;
    v397[v480] = 0;
    v400 = v480;
  }
  int v492 = (v400 * 2) + (((int)((unsigned int)v299 >> 2)) & 1);
  int v401 = v307[v492];
  int * v402 = v295->regs;
  v402[12] = v401;
  return v295;
}

struct StateT * slot_3(struct StateT * v41) {
  int v42 = v41->timer;
  int v52 = v42 + 1;
  v41->timer = v52;
  int * v44 = v41->regs;
  int v45 = v44[10];
  int v46 = v44[15];
  bool v56 = v45 >= v46;
  struct StateT * v50;
  if (v56) {
    v50 = v41;
  } else {
    struct StateT * v48 = slot_4(v41);
    v50 = v48;
  }
  return v50;
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