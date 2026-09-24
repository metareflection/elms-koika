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
void squared_diverged(bool);

struct StateT2 * snippet(struct StateT2 * v0);
struct StateT2 * slot_1(struct StateT2 * v45);
struct StateT2 * slot_2(struct StateT2 * v555);
struct StateT2 * slot_3(struct StateT2 * v598);
struct StateT2 * slot_0(struct StateT2 * v2);
struct StateT2 * snippet(struct StateT2 * v0) {
  struct StateT2 * v1 = slot_0(v0);
  return v1;
}

struct StateT2 * slot_1(struct StateT2 * v45) {
  struct StateT * v46 = v45->a;
  int v47 = v46->timer;
  struct StateT * v48 = v45->b;
  int v49 = v48->timer;
  bool v322 = v47 == v49;
  squared_assert(v322);
  squared_assume(v322);
  struct StateT * v52 = v45->a;
  int v53 = v52->timer;
  int v324 = v53 + 1;
  v52->timer = v324;
  struct StateT * v55 = v45->b;
  int v56 = v55->timer;
  int v326 = v56 + 1;
  v55->timer = v326;
  struct StateT * v58 = v45->a;
  int * v59 = v58->regs;
  int v60 = v59[10];
  int * v61 = v58->cache_tags;
  int v331 = (((int)((unsigned int)((int)((unsigned int)v60 >> 2)) >> 1)) & 1) * 2;
  int v62 = v61[v331];
  int * v63 = v58->cache_tags;
  int v333 = ((((int)((unsigned int)((int)((unsigned int)v60 >> 2)) >> 1)) & 1) * 2) + 1;
  int v64 = v63[v333];
  int * v65 = v58->cache_tags;
  int v335 = 4 + ((((int)((unsigned int)((int)((unsigned int)v60 >> 2)) >> 1)) & 3) * 2);
  int v66 = v65[v335];
  int * v67 = v58->cache_tags;
  int v337 = (4 + ((((int)((unsigned int)((int)((unsigned int)v60 >> 2)) >> 1)) & 3) * 2)) + 1;
  int v68 = v67[v337];
  int v69 = v58->timer;
  int v338 = v69 + ((100 ^ (((~(((v66 ^ ((int)((unsigned int)((int)((unsigned int)v60 >> 2)) >> 1))) | (-(v66 ^ ((int)((unsigned int)((int)((unsigned int)v60 >> 2)) >> 1))))) >> 31)) | (~(((v68 ^ ((int)((unsigned int)((int)((unsigned int)v60 >> 2)) >> 1))) | (-(v68 ^ ((int)((unsigned int)((int)((unsigned int)v60 >> 2)) >> 1))))) >> 31))) & 104)) ^ (((~(((v62 ^ ((int)((unsigned int)((int)((unsigned int)v60 >> 2)) >> 1))) | (-(v62 ^ ((int)((unsigned int)((int)((unsigned int)v60 >> 2)) >> 1))))) >> 31)) | (~(((v64 ^ ((int)((unsigned int)((int)((unsigned int)v60 >> 2)) >> 1))) | (-(v64 ^ ((int)((unsigned int)((int)((unsigned int)v60 >> 2)) >> 1))))) >> 31))) & (1 ^ (100 ^ (((~(((v66 ^ ((int)((unsigned int)((int)((unsigned int)v60 >> 2)) >> 1))) | (-(v66 ^ ((int)((unsigned int)((int)((unsigned int)v60 >> 2)) >> 1))))) >> 31)) | (~(((v68 ^ ((int)((unsigned int)((int)((unsigned int)v60 >> 2)) >> 1))) | (-(v68 ^ ((int)((unsigned int)((int)((unsigned int)v60 >> 2)) >> 1))))) >> 31))) & 104)))));
  v58->timer = v338;
  int * v71 = v58->cache_vals;
  bool v339 = !(((~(((v62 ^ ((int)((unsigned int)((int)((unsigned int)v60 >> 2)) >> 1))) | (-(v62 ^ ((int)((unsigned int)((int)((unsigned int)v60 >> 2)) >> 1))))) >> 31)) | (~(((v64 ^ ((int)((unsigned int)((int)((unsigned int)v60 >> 2)) >> 1))) | (-(v64 ^ ((int)((unsigned int)((int)((unsigned int)v60 >> 2)) >> 1))))) >> 31))) == 0);
  int v184;
  if (v339) {
    int * v72 = v58->cache_age;
    int v341 = ((((int)((unsigned int)((int)((unsigned int)v60 >> 2)) >> 1)) & 1) * 2) + ((~(((v64 ^ ((int)((unsigned int)((int)((unsigned int)v60 >> 2)) >> 1))) | (-(v64 ^ ((int)((unsigned int)((int)((unsigned int)v60 >> 2)) >> 1))))) >> 31)) & 1);
    int v73 = v72[v341];
    int * v74 = v58->cache_age;
    int v75 = v74[v331];
    int * v76 = v58->cache_age;
    int v344 = v75 + ((int)((unsigned int)(v75 - v73) >> 31));
    v76[v331] = v344;
    int * v78 = v58->cache_age;
    int v79 = v78[v333];
    int * v80 = v58->cache_age;
    int v347 = v79 + ((int)((unsigned int)(v79 - v73) >> 31));
    v80[v333] = v347;
    int * v82 = v58->cache_age;
    v82[v341] = 0;
    v184 = v341;
  } else {
    int * v85 = v58->cache_age;
    int v351 = (((int)((unsigned int)((int)((unsigned int)v60 >> 2)) >> 1)) & 1) * 2;
    int v86 = v85[v351];
    int * v87 = v58->cache_tags;
    int v88 = v87[v351];
    int * v89 = v58->cache_age;
    int v90 = v89[v333];
    int * v91 = v58->cache_tags;
    int v92 = v91[v333];
    bool v355 = !(((~(((v66 ^ ((int)((unsigned int)((int)((unsigned int)v60 >> 2)) >> 1))) | (-(v66 ^ ((int)((unsigned int)((int)((unsigned int)v60 >> 2)) >> 1))))) >> 31)) | (~(((v68 ^ ((int)((unsigned int)((int)((unsigned int)v60 >> 2)) >> 1))) | (-(v68 ^ ((int)((unsigned int)((int)((unsigned int)v60 >> 2)) >> 1))))) >> 31))) == 0);
    int v156;
    if (v355) {
      int * v93 = v58->cache_age;
      int v357 = (4 + ((((int)((unsigned int)((int)((unsigned int)v60 >> 2)) >> 1)) & 3) * 2)) + ((~(((v68 ^ ((int)((unsigned int)((int)((unsigned int)v60 >> 2)) >> 1))) | (-(v68 ^ ((int)((unsigned int)((int)((unsigned int)v60 >> 2)) >> 1))))) >> 31)) & 1);
      int v94 = v93[v357];
      int * v95 = v58->cache_age;
      int v96 = v95[v335];
      int * v97 = v58->cache_age;
      int v360 = v96 + ((int)((unsigned int)(v96 - v94) >> 31));
      v97[v335] = v360;
      int * v99 = v58->cache_age;
      int v100 = v99[v337];
      int * v101 = v58->cache_age;
      int v363 = v100 + ((int)((unsigned int)(v100 - v94) >> 31));
      v101[v337] = v363;
      int * v103 = v58->cache_age;
      v103[v357] = 0;
      v156 = v357;
    } else {
      int * v106 = v58->cache_age;
      int v367 = 4 + ((((int)((unsigned int)((int)((unsigned int)v60 >> 2)) >> 1)) & 3) * 2);
      int v107 = v106[v367];
      int * v108 = v58->cache_tags;
      int v109 = v108[v367];
      int * v110 = v58->cache_age;
      int v111 = v110[v337];
      int * v112 = v58->cache_tags;
      int v113 = v112[v337];
      int * v114 = v58->cache_dirty;
      int v372 = (4 + ((((int)((unsigned int)((int)((unsigned int)v60 >> 2)) >> 1)) & 3) * 2)) + ((((v107 + ((~(((v109 ^ -1) | (-(v109 ^ -1))) >> 31)) & 2)) - (v111 + ((~(((v113 ^ -1) | (-(v113 ^ -1))) >> 31)) & 2))) >> 31) & 1);
      int v115 = v114[v372];
      bool v373 = !(v115 == 0);
      if (v373) {
        int * v116 = v58->cache_tags;
        int v117 = v116[v372];
        int * v118 = v58->cache_vals;
        int v376 = ((4 + ((((int)((unsigned int)((int)((unsigned int)v60 >> 2)) >> 1)) & 3) * 2)) + ((((v107 + ((~(((v109 ^ -1) | (-(v109 ^ -1))) >> 31)) & 2)) - (v111 + ((~(((v113 ^ -1) | (-(v113 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
        int v119 = v118[v376];
        int * v120 = v58->cache_vals;
        int v378 = (((4 + ((((int)((unsigned int)((int)((unsigned int)v60 >> 2)) >> 1)) & 3) * 2)) + ((((v107 + ((~(((v109 ^ -1) | (-(v109 ^ -1))) >> 31)) & 2)) - (v111 + ((~(((v113 ^ -1) | (-(v113 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
        int v121 = v120[v378];
        int * v122 = v58->mem;
        int v380 = v117 * 2;
        v122[v380] = v119;
        int * v124 = v58->mem;
        int v383 = (v117 * 2) + 1;
        v124[v383] = v121;
        ;
      } else {
        ;
      }
      int * v129 = v58->mem;
      int v388 = ((int)((unsigned int)((int)((unsigned int)v60 >> 2)) >> 1)) * 2;
      int v130 = v129[v388];
      int * v131 = v58->mem;
      int v390 = (((int)((unsigned int)((int)((unsigned int)v60 >> 2)) >> 1)) * 2) + 1;
      int v132 = v131[v390];
      int * v133 = v58->cache_vals;
      int v392 = ((4 + ((((int)((unsigned int)((int)((unsigned int)v60 >> 2)) >> 1)) & 3) * 2)) + ((((v107 + ((~(((v109 ^ -1) | (-(v109 ^ -1))) >> 31)) & 2)) - (v111 + ((~(((v113 ^ -1) | (-(v113 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
      v133[v392] = v130;
      int * v135 = v58->cache_vals;
      int v395 = (((4 + ((((int)((unsigned int)((int)((unsigned int)v60 >> 2)) >> 1)) & 3) * 2)) + ((((v107 + ((~(((v109 ^ -1) | (-(v109 ^ -1))) >> 31)) & 2)) - (v111 + ((~(((v113 ^ -1) | (-(v113 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
      v135[v395] = v132;
      int * v137 = v58->cache_tags;
      int v398 = (int)((unsigned int)((int)((unsigned int)v60 >> 2)) >> 1);
      v137[v372] = v398;
      int * v139 = v58->cache_dirty;
      v139[v372] = 0;
      int * v141 = v58->cache_age;
      v141[v372] = 1;
      int * v143 = v58->cache_age;
      int v144 = v143[v372];
      int * v145 = v58->cache_age;
      int v146 = v145[v335];
      int * v147 = v58->cache_age;
      int v406 = v146 + ((int)((unsigned int)(v146 - v144) >> 31));
      v147[v335] = v406;
      int * v149 = v58->cache_age;
      int v150 = v149[v337];
      int * v151 = v58->cache_age;
      int v409 = v150 + ((int)((unsigned int)(v150 - v144) >> 31));
      v151[v337] = v409;
      int * v153 = v58->cache_age;
      v153[v372] = 0;
      v156 = v372;
    }
    int * v157 = v58->cache_vals;
    int v412 = v156 * 2;
    int v158 = v157[v412];
    int * v159 = v58->cache_vals;
    int v414 = (v156 * 2) + 1;
    int v160 = v159[v414];
    int * v161 = v58->cache_vals;
    int v416 = (((((int)((unsigned int)((int)((unsigned int)v60 >> 2)) >> 1)) & 1) * 2) + ((((v86 + ((~(((v88 ^ -1) | (-(v88 ^ -1))) >> 31)) & 2)) - (v90 + ((~(((v92 ^ -1) | (-(v92 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
    v161[v416] = v158;
    int * v163 = v58->cache_vals;
    int v419 = ((((((int)((unsigned int)((int)((unsigned int)v60 >> 2)) >> 1)) & 1) * 2) + ((((v86 + ((~(((v88 ^ -1) | (-(v88 ^ -1))) >> 31)) & 2)) - (v90 + ((~(((v92 ^ -1) | (-(v92 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
    v163[v419] = v160;
    int * v165 = v58->cache_tags;
    int v422 = ((((int)((unsigned int)((int)((unsigned int)v60 >> 2)) >> 1)) & 1) * 2) + ((((v86 + ((~(((v88 ^ -1) | (-(v88 ^ -1))) >> 31)) & 2)) - (v90 + ((~(((v92 ^ -1) | (-(v92 ^ -1))) >> 31)) & 2))) >> 31) & 1);
    int v423 = (int)((unsigned int)((int)((unsigned int)v60 >> 2)) >> 1);
    v165[v422] = v423;
    int * v167 = v58->cache_dirty;
    v167[v422] = 0;
    int * v169 = v58->cache_age;
    v169[v422] = 1;
    int * v171 = v58->cache_age;
    int v172 = v171[v422];
    int * v173 = v58->cache_age;
    int v174 = v173[v331];
    int * v175 = v58->cache_age;
    int v431 = v174 + ((int)((unsigned int)(v174 - v172) >> 31));
    v175[v331] = v431;
    int * v177 = v58->cache_age;
    int v178 = v177[v333];
    int * v179 = v58->cache_age;
    int v434 = v178 + ((int)((unsigned int)(v178 - v172) >> 31));
    v179[v333] = v434;
    int * v181 = v58->cache_age;
    v181[v422] = 0;
    v184 = v422;
  }
  int v437 = (v184 * 2) + (((int)((unsigned int)v60 >> 2)) & 1);
  int v185 = v71[v437];
  int * v186 = v58->regs;
  v186[11] = v185;
  struct StateT * v188 = v45->b;
  int * v189 = v188->regs;
  int v190 = v189[10];
  int * v191 = v188->cache_tags;
  int v444 = (((int)((unsigned int)((int)((unsigned int)v190 >> 2)) >> 1)) & 1) * 2;
  int v192 = v191[v444];
  int * v193 = v188->cache_tags;
  int v446 = ((((int)((unsigned int)((int)((unsigned int)v190 >> 2)) >> 1)) & 1) * 2) + 1;
  int v194 = v193[v446];
  int * v195 = v188->cache_tags;
  int v448 = 4 + ((((int)((unsigned int)((int)((unsigned int)v190 >> 2)) >> 1)) & 3) * 2);
  int v196 = v195[v448];
  int * v197 = v188->cache_tags;
  int v450 = (4 + ((((int)((unsigned int)((int)((unsigned int)v190 >> 2)) >> 1)) & 3) * 2)) + 1;
  int v198 = v197[v450];
  int v199 = v188->timer;
  int v451 = v199 + ((100 ^ (((~(((v196 ^ ((int)((unsigned int)((int)((unsigned int)v190 >> 2)) >> 1))) | (-(v196 ^ ((int)((unsigned int)((int)((unsigned int)v190 >> 2)) >> 1))))) >> 31)) | (~(((v198 ^ ((int)((unsigned int)((int)((unsigned int)v190 >> 2)) >> 1))) | (-(v198 ^ ((int)((unsigned int)((int)((unsigned int)v190 >> 2)) >> 1))))) >> 31))) & 104)) ^ (((~(((v192 ^ ((int)((unsigned int)((int)((unsigned int)v190 >> 2)) >> 1))) | (-(v192 ^ ((int)((unsigned int)((int)((unsigned int)v190 >> 2)) >> 1))))) >> 31)) | (~(((v194 ^ ((int)((unsigned int)((int)((unsigned int)v190 >> 2)) >> 1))) | (-(v194 ^ ((int)((unsigned int)((int)((unsigned int)v190 >> 2)) >> 1))))) >> 31))) & (1 ^ (100 ^ (((~(((v196 ^ ((int)((unsigned int)((int)((unsigned int)v190 >> 2)) >> 1))) | (-(v196 ^ ((int)((unsigned int)((int)((unsigned int)v190 >> 2)) >> 1))))) >> 31)) | (~(((v198 ^ ((int)((unsigned int)((int)((unsigned int)v190 >> 2)) >> 1))) | (-(v198 ^ ((int)((unsigned int)((int)((unsigned int)v190 >> 2)) >> 1))))) >> 31))) & 104)))));
  v188->timer = v451;
  int * v201 = v188->cache_vals;
  bool v452 = !(((~(((v192 ^ ((int)((unsigned int)((int)((unsigned int)v190 >> 2)) >> 1))) | (-(v192 ^ ((int)((unsigned int)((int)((unsigned int)v190 >> 2)) >> 1))))) >> 31)) | (~(((v194 ^ ((int)((unsigned int)((int)((unsigned int)v190 >> 2)) >> 1))) | (-(v194 ^ ((int)((unsigned int)((int)((unsigned int)v190 >> 2)) >> 1))))) >> 31))) == 0);
  int v314;
  if (v452) {
    int * v202 = v188->cache_age;
    int v454 = ((((int)((unsigned int)((int)((unsigned int)v190 >> 2)) >> 1)) & 1) * 2) + ((~(((v194 ^ ((int)((unsigned int)((int)((unsigned int)v190 >> 2)) >> 1))) | (-(v194 ^ ((int)((unsigned int)((int)((unsigned int)v190 >> 2)) >> 1))))) >> 31)) & 1);
    int v203 = v202[v454];
    int * v204 = v188->cache_age;
    int v205 = v204[v444];
    int * v206 = v188->cache_age;
    int v457 = v205 + ((int)((unsigned int)(v205 - v203) >> 31));
    v206[v444] = v457;
    int * v208 = v188->cache_age;
    int v209 = v208[v446];
    int * v210 = v188->cache_age;
    int v460 = v209 + ((int)((unsigned int)(v209 - v203) >> 31));
    v210[v446] = v460;
    int * v212 = v188->cache_age;
    v212[v454] = 0;
    v314 = v454;
  } else {
    int * v215 = v188->cache_age;
    int v464 = (((int)((unsigned int)((int)((unsigned int)v190 >> 2)) >> 1)) & 1) * 2;
    int v216 = v215[v464];
    int * v217 = v188->cache_tags;
    int v218 = v217[v464];
    int * v219 = v188->cache_age;
    int v220 = v219[v446];
    int * v221 = v188->cache_tags;
    int v222 = v221[v446];
    bool v468 = !(((~(((v196 ^ ((int)((unsigned int)((int)((unsigned int)v190 >> 2)) >> 1))) | (-(v196 ^ ((int)((unsigned int)((int)((unsigned int)v190 >> 2)) >> 1))))) >> 31)) | (~(((v198 ^ ((int)((unsigned int)((int)((unsigned int)v190 >> 2)) >> 1))) | (-(v198 ^ ((int)((unsigned int)((int)((unsigned int)v190 >> 2)) >> 1))))) >> 31))) == 0);
    int v286;
    if (v468) {
      int * v223 = v188->cache_age;
      int v470 = (4 + ((((int)((unsigned int)((int)((unsigned int)v190 >> 2)) >> 1)) & 3) * 2)) + ((~(((v198 ^ ((int)((unsigned int)((int)((unsigned int)v190 >> 2)) >> 1))) | (-(v198 ^ ((int)((unsigned int)((int)((unsigned int)v190 >> 2)) >> 1))))) >> 31)) & 1);
      int v224 = v223[v470];
      int * v225 = v188->cache_age;
      int v226 = v225[v448];
      int * v227 = v188->cache_age;
      int v473 = v226 + ((int)((unsigned int)(v226 - v224) >> 31));
      v227[v448] = v473;
      int * v229 = v188->cache_age;
      int v230 = v229[v450];
      int * v231 = v188->cache_age;
      int v476 = v230 + ((int)((unsigned int)(v230 - v224) >> 31));
      v231[v450] = v476;
      int * v233 = v188->cache_age;
      v233[v470] = 0;
      v286 = v470;
    } else {
      int * v236 = v188->cache_age;
      int v480 = 4 + ((((int)((unsigned int)((int)((unsigned int)v190 >> 2)) >> 1)) & 3) * 2);
      int v237 = v236[v480];
      int * v238 = v188->cache_tags;
      int v239 = v238[v480];
      int * v240 = v188->cache_age;
      int v241 = v240[v450];
      int * v242 = v188->cache_tags;
      int v243 = v242[v450];
      int * v244 = v188->cache_dirty;
      int v485 = (4 + ((((int)((unsigned int)((int)((unsigned int)v190 >> 2)) >> 1)) & 3) * 2)) + ((((v237 + ((~(((v239 ^ -1) | (-(v239 ^ -1))) >> 31)) & 2)) - (v241 + ((~(((v243 ^ -1) | (-(v243 ^ -1))) >> 31)) & 2))) >> 31) & 1);
      int v245 = v244[v485];
      bool v486 = !(v245 == 0);
      if (v486) {
        int * v246 = v188->cache_tags;
        int v247 = v246[v485];
        int * v248 = v188->cache_vals;
        int v489 = ((4 + ((((int)((unsigned int)((int)((unsigned int)v190 >> 2)) >> 1)) & 3) * 2)) + ((((v237 + ((~(((v239 ^ -1) | (-(v239 ^ -1))) >> 31)) & 2)) - (v241 + ((~(((v243 ^ -1) | (-(v243 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
        int v249 = v248[v489];
        int * v250 = v188->cache_vals;
        int v491 = (((4 + ((((int)((unsigned int)((int)((unsigned int)v190 >> 2)) >> 1)) & 3) * 2)) + ((((v237 + ((~(((v239 ^ -1) | (-(v239 ^ -1))) >> 31)) & 2)) - (v241 + ((~(((v243 ^ -1) | (-(v243 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
        int v251 = v250[v491];
        int * v252 = v188->mem;
        int v493 = v247 * 2;
        v252[v493] = v249;
        int * v254 = v188->mem;
        int v496 = (v247 * 2) + 1;
        v254[v496] = v251;
        ;
      } else {
        ;
      }
      int * v259 = v188->mem;
      int v501 = ((int)((unsigned int)((int)((unsigned int)v190 >> 2)) >> 1)) * 2;
      int v260 = v259[v501];
      int * v261 = v188->mem;
      int v503 = (((int)((unsigned int)((int)((unsigned int)v190 >> 2)) >> 1)) * 2) + 1;
      int v262 = v261[v503];
      int * v263 = v188->cache_vals;
      int v505 = ((4 + ((((int)((unsigned int)((int)((unsigned int)v190 >> 2)) >> 1)) & 3) * 2)) + ((((v237 + ((~(((v239 ^ -1) | (-(v239 ^ -1))) >> 31)) & 2)) - (v241 + ((~(((v243 ^ -1) | (-(v243 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
      v263[v505] = v260;
      int * v265 = v188->cache_vals;
      int v508 = (((4 + ((((int)((unsigned int)((int)((unsigned int)v190 >> 2)) >> 1)) & 3) * 2)) + ((((v237 + ((~(((v239 ^ -1) | (-(v239 ^ -1))) >> 31)) & 2)) - (v241 + ((~(((v243 ^ -1) | (-(v243 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
      v265[v508] = v262;
      int * v267 = v188->cache_tags;
      int v511 = (int)((unsigned int)((int)((unsigned int)v190 >> 2)) >> 1);
      v267[v485] = v511;
      int * v269 = v188->cache_dirty;
      v269[v485] = 0;
      int * v271 = v188->cache_age;
      v271[v485] = 1;
      int * v273 = v188->cache_age;
      int v274 = v273[v485];
      int * v275 = v188->cache_age;
      int v276 = v275[v448];
      int * v277 = v188->cache_age;
      int v519 = v276 + ((int)((unsigned int)(v276 - v274) >> 31));
      v277[v448] = v519;
      int * v279 = v188->cache_age;
      int v280 = v279[v450];
      int * v281 = v188->cache_age;
      int v522 = v280 + ((int)((unsigned int)(v280 - v274) >> 31));
      v281[v450] = v522;
      int * v283 = v188->cache_age;
      v283[v485] = 0;
      v286 = v485;
    }
    int * v287 = v188->cache_vals;
    int v525 = v286 * 2;
    int v288 = v287[v525];
    int * v289 = v188->cache_vals;
    int v527 = (v286 * 2) + 1;
    int v290 = v289[v527];
    int * v291 = v188->cache_vals;
    int v529 = (((((int)((unsigned int)((int)((unsigned int)v190 >> 2)) >> 1)) & 1) * 2) + ((((v216 + ((~(((v218 ^ -1) | (-(v218 ^ -1))) >> 31)) & 2)) - (v220 + ((~(((v222 ^ -1) | (-(v222 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
    v291[v529] = v288;
    int * v293 = v188->cache_vals;
    int v532 = ((((((int)((unsigned int)((int)((unsigned int)v190 >> 2)) >> 1)) & 1) * 2) + ((((v216 + ((~(((v218 ^ -1) | (-(v218 ^ -1))) >> 31)) & 2)) - (v220 + ((~(((v222 ^ -1) | (-(v222 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
    v293[v532] = v290;
    int * v295 = v188->cache_tags;
    int v535 = ((((int)((unsigned int)((int)((unsigned int)v190 >> 2)) >> 1)) & 1) * 2) + ((((v216 + ((~(((v218 ^ -1) | (-(v218 ^ -1))) >> 31)) & 2)) - (v220 + ((~(((v222 ^ -1) | (-(v222 ^ -1))) >> 31)) & 2))) >> 31) & 1);
    int v536 = (int)((unsigned int)((int)((unsigned int)v190 >> 2)) >> 1);
    v295[v535] = v536;
    int * v297 = v188->cache_dirty;
    v297[v535] = 0;
    int * v299 = v188->cache_age;
    v299[v535] = 1;
    int * v301 = v188->cache_age;
    int v302 = v301[v535];
    int * v303 = v188->cache_age;
    int v304 = v303[v444];
    int * v305 = v188->cache_age;
    int v544 = v304 + ((int)((unsigned int)(v304 - v302) >> 31));
    v305[v444] = v544;
    int * v307 = v188->cache_age;
    int v308 = v307[v446];
    int * v309 = v188->cache_age;
    int v547 = v308 + ((int)((unsigned int)(v308 - v302) >> 31));
    v309[v446] = v547;
    int * v311 = v188->cache_age;
    v311[v535] = 0;
    v314 = v535;
  }
  int v550 = (v314 * 2) + (((int)((unsigned int)v190 >> 2)) & 1);
  int v315 = v201[v550];
  int * v316 = v188->regs;
  v316[11] = v315;
  struct StateT2 * v318 = slot_2(v45);
  return v318;
}

struct StateT2 * slot_2(struct StateT2 * v555) {
  struct StateT * v556 = v555->a;
  int v557 = v556->timer;
  struct StateT * v558 = v555->b;
  int v559 = v558->timer;
  bool v582 = v557 == v559;
  squared_assert(v582);
  squared_assume(v582);
  struct StateT * v562 = v555->a;
  int v563 = v562->timer;
  int v584 = v563 + 1;
  v562->timer = v584;
  struct StateT * v565 = v555->b;
  int v566 = v565->timer;
  int v586 = v566 + 1;
  v565->timer = v586;
  struct StateT * v568 = v555->a;
  int * v569 = v568->regs;
  int v570 = v569[11];
  int * v571 = v568->regs;
  int v591 = v570 << 2;
  v571[11] = v591;
  struct StateT * v573 = v555->b;
  int * v574 = v573->regs;
  int v575 = v574[11];
  int * v576 = v573->regs;
  int v595 = v575 << 2;
  v576[11] = v595;
  struct StateT2 * v578 = slot_3(v555);
  return v578;
}

struct StateT2 * slot_3(struct StateT2 * v598) {
  struct StateT * v599 = v598->a;
  int v600 = v599->timer;
  struct StateT * v601 = v598->b;
  int v602 = v601->timer;
  bool v874 = v600 == v602;
  squared_assert(v874);
  squared_assume(v874);
  struct StateT * v605 = v598->a;
  int v606 = v605->timer;
  int v876 = v606 + 1;
  v605->timer = v876;
  struct StateT * v608 = v598->b;
  int v609 = v608->timer;
  int v878 = v609 + 1;
  v608->timer = v878;
  struct StateT * v611 = v598->a;
  int * v612 = v611->regs;
  int v613 = v612[11];
  int * v614 = v611->cache_tags;
  int v883 = (((int)((unsigned int)((int)((unsigned int)(v613 + 16) >> 2)) >> 1)) & 1) * 2;
  int v615 = v614[v883];
  int * v616 = v611->cache_tags;
  int v885 = ((((int)((unsigned int)((int)((unsigned int)(v613 + 16) >> 2)) >> 1)) & 1) * 2) + 1;
  int v617 = v616[v885];
  int * v618 = v611->cache_tags;
  int v887 = 4 + ((((int)((unsigned int)((int)((unsigned int)(v613 + 16) >> 2)) >> 1)) & 3) * 2);
  int v619 = v618[v887];
  int * v620 = v611->cache_tags;
  int v889 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v613 + 16) >> 2)) >> 1)) & 3) * 2)) + 1;
  int v621 = v620[v889];
  int v622 = v611->timer;
  int v890 = v622 + ((100 ^ (((~(((v619 ^ ((int)((unsigned int)((int)((unsigned int)(v613 + 16) >> 2)) >> 1))) | (-(v619 ^ ((int)((unsigned int)((int)((unsigned int)(v613 + 16) >> 2)) >> 1))))) >> 31)) | (~(((v621 ^ ((int)((unsigned int)((int)((unsigned int)(v613 + 16) >> 2)) >> 1))) | (-(v621 ^ ((int)((unsigned int)((int)((unsigned int)(v613 + 16) >> 2)) >> 1))))) >> 31))) & 104)) ^ (((~(((v615 ^ ((int)((unsigned int)((int)((unsigned int)(v613 + 16) >> 2)) >> 1))) | (-(v615 ^ ((int)((unsigned int)((int)((unsigned int)(v613 + 16) >> 2)) >> 1))))) >> 31)) | (~(((v617 ^ ((int)((unsigned int)((int)((unsigned int)(v613 + 16) >> 2)) >> 1))) | (-(v617 ^ ((int)((unsigned int)((int)((unsigned int)(v613 + 16) >> 2)) >> 1))))) >> 31))) & (1 ^ (100 ^ (((~(((v619 ^ ((int)((unsigned int)((int)((unsigned int)(v613 + 16) >> 2)) >> 1))) | (-(v619 ^ ((int)((unsigned int)((int)((unsigned int)(v613 + 16) >> 2)) >> 1))))) >> 31)) | (~(((v621 ^ ((int)((unsigned int)((int)((unsigned int)(v613 + 16) >> 2)) >> 1))) | (-(v621 ^ ((int)((unsigned int)((int)((unsigned int)(v613 + 16) >> 2)) >> 1))))) >> 31))) & 104)))));
  v611->timer = v890;
  int * v624 = v611->cache_vals;
  bool v891 = !(((~(((v615 ^ ((int)((unsigned int)((int)((unsigned int)(v613 + 16) >> 2)) >> 1))) | (-(v615 ^ ((int)((unsigned int)((int)((unsigned int)(v613 + 16) >> 2)) >> 1))))) >> 31)) | (~(((v617 ^ ((int)((unsigned int)((int)((unsigned int)(v613 + 16) >> 2)) >> 1))) | (-(v617 ^ ((int)((unsigned int)((int)((unsigned int)(v613 + 16) >> 2)) >> 1))))) >> 31))) == 0);
  int v737;
  if (v891) {
    int * v625 = v611->cache_age;
    int v893 = ((((int)((unsigned int)((int)((unsigned int)(v613 + 16) >> 2)) >> 1)) & 1) * 2) + ((~(((v617 ^ ((int)((unsigned int)((int)((unsigned int)(v613 + 16) >> 2)) >> 1))) | (-(v617 ^ ((int)((unsigned int)((int)((unsigned int)(v613 + 16) >> 2)) >> 1))))) >> 31)) & 1);
    int v626 = v625[v893];
    int * v627 = v611->cache_age;
    int v628 = v627[v883];
    int * v629 = v611->cache_age;
    int v896 = v628 + ((int)((unsigned int)(v628 - v626) >> 31));
    v629[v883] = v896;
    int * v631 = v611->cache_age;
    int v632 = v631[v885];
    int * v633 = v611->cache_age;
    int v899 = v632 + ((int)((unsigned int)(v632 - v626) >> 31));
    v633[v885] = v899;
    int * v635 = v611->cache_age;
    v635[v893] = 0;
    v737 = v893;
  } else {
    int * v638 = v611->cache_age;
    int v903 = (((int)((unsigned int)((int)((unsigned int)(v613 + 16) >> 2)) >> 1)) & 1) * 2;
    int v639 = v638[v903];
    int * v640 = v611->cache_tags;
    int v641 = v640[v903];
    int * v642 = v611->cache_age;
    int v643 = v642[v885];
    int * v644 = v611->cache_tags;
    int v645 = v644[v885];
    bool v907 = !(((~(((v619 ^ ((int)((unsigned int)((int)((unsigned int)(v613 + 16) >> 2)) >> 1))) | (-(v619 ^ ((int)((unsigned int)((int)((unsigned int)(v613 + 16) >> 2)) >> 1))))) >> 31)) | (~(((v621 ^ ((int)((unsigned int)((int)((unsigned int)(v613 + 16) >> 2)) >> 1))) | (-(v621 ^ ((int)((unsigned int)((int)((unsigned int)(v613 + 16) >> 2)) >> 1))))) >> 31))) == 0);
    int v709;
    if (v907) {
      int * v646 = v611->cache_age;
      int v909 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v613 + 16) >> 2)) >> 1)) & 3) * 2)) + ((~(((v621 ^ ((int)((unsigned int)((int)((unsigned int)(v613 + 16) >> 2)) >> 1))) | (-(v621 ^ ((int)((unsigned int)((int)((unsigned int)(v613 + 16) >> 2)) >> 1))))) >> 31)) & 1);
      int v647 = v646[v909];
      int * v648 = v611->cache_age;
      int v649 = v648[v887];
      int * v650 = v611->cache_age;
      int v912 = v649 + ((int)((unsigned int)(v649 - v647) >> 31));
      v650[v887] = v912;
      int * v652 = v611->cache_age;
      int v653 = v652[v889];
      int * v654 = v611->cache_age;
      int v915 = v653 + ((int)((unsigned int)(v653 - v647) >> 31));
      v654[v889] = v915;
      int * v656 = v611->cache_age;
      v656[v909] = 0;
      v709 = v909;
    } else {
      int * v659 = v611->cache_age;
      int v919 = 4 + ((((int)((unsigned int)((int)((unsigned int)(v613 + 16) >> 2)) >> 1)) & 3) * 2);
      int v660 = v659[v919];
      int * v661 = v611->cache_tags;
      int v662 = v661[v919];
      int * v663 = v611->cache_age;
      int v664 = v663[v889];
      int * v665 = v611->cache_tags;
      int v666 = v665[v889];
      int * v667 = v611->cache_dirty;
      int v924 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v613 + 16) >> 2)) >> 1)) & 3) * 2)) + ((((v660 + ((~(((v662 ^ -1) | (-(v662 ^ -1))) >> 31)) & 2)) - (v664 + ((~(((v666 ^ -1) | (-(v666 ^ -1))) >> 31)) & 2))) >> 31) & 1);
      int v668 = v667[v924];
      bool v925 = !(v668 == 0);
      if (v925) {
        int * v669 = v611->cache_tags;
        int v670 = v669[v924];
        int * v671 = v611->cache_vals;
        int v928 = ((4 + ((((int)((unsigned int)((int)((unsigned int)(v613 + 16) >> 2)) >> 1)) & 3) * 2)) + ((((v660 + ((~(((v662 ^ -1) | (-(v662 ^ -1))) >> 31)) & 2)) - (v664 + ((~(((v666 ^ -1) | (-(v666 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
        int v672 = v671[v928];
        int * v673 = v611->cache_vals;
        int v930 = (((4 + ((((int)((unsigned int)((int)((unsigned int)(v613 + 16) >> 2)) >> 1)) & 3) * 2)) + ((((v660 + ((~(((v662 ^ -1) | (-(v662 ^ -1))) >> 31)) & 2)) - (v664 + ((~(((v666 ^ -1) | (-(v666 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
        int v674 = v673[v930];
        int * v675 = v611->mem;
        int v932 = v670 * 2;
        v675[v932] = v672;
        int * v677 = v611->mem;
        int v935 = (v670 * 2) + 1;
        v677[v935] = v674;
        ;
      } else {
        ;
      }
      int * v682 = v611->mem;
      int v940 = ((int)((unsigned int)((int)((unsigned int)(v613 + 16) >> 2)) >> 1)) * 2;
      int v683 = v682[v940];
      int * v684 = v611->mem;
      int v942 = (((int)((unsigned int)((int)((unsigned int)(v613 + 16) >> 2)) >> 1)) * 2) + 1;
      int v685 = v684[v942];
      int * v686 = v611->cache_vals;
      int v944 = ((4 + ((((int)((unsigned int)((int)((unsigned int)(v613 + 16) >> 2)) >> 1)) & 3) * 2)) + ((((v660 + ((~(((v662 ^ -1) | (-(v662 ^ -1))) >> 31)) & 2)) - (v664 + ((~(((v666 ^ -1) | (-(v666 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
      v686[v944] = v683;
      int * v688 = v611->cache_vals;
      int v947 = (((4 + ((((int)((unsigned int)((int)((unsigned int)(v613 + 16) >> 2)) >> 1)) & 3) * 2)) + ((((v660 + ((~(((v662 ^ -1) | (-(v662 ^ -1))) >> 31)) & 2)) - (v664 + ((~(((v666 ^ -1) | (-(v666 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
      v688[v947] = v685;
      int * v690 = v611->cache_tags;
      int v950 = (int)((unsigned int)((int)((unsigned int)(v613 + 16) >> 2)) >> 1);
      v690[v924] = v950;
      int * v692 = v611->cache_dirty;
      v692[v924] = 0;
      int * v694 = v611->cache_age;
      v694[v924] = 1;
      int * v696 = v611->cache_age;
      int v697 = v696[v924];
      int * v698 = v611->cache_age;
      int v699 = v698[v887];
      int * v700 = v611->cache_age;
      int v958 = v699 + ((int)((unsigned int)(v699 - v697) >> 31));
      v700[v887] = v958;
      int * v702 = v611->cache_age;
      int v703 = v702[v889];
      int * v704 = v611->cache_age;
      int v961 = v703 + ((int)((unsigned int)(v703 - v697) >> 31));
      v704[v889] = v961;
      int * v706 = v611->cache_age;
      v706[v924] = 0;
      v709 = v924;
    }
    int * v710 = v611->cache_vals;
    int v964 = v709 * 2;
    int v711 = v710[v964];
    int * v712 = v611->cache_vals;
    int v966 = (v709 * 2) + 1;
    int v713 = v712[v966];
    int * v714 = v611->cache_vals;
    int v968 = (((((int)((unsigned int)((int)((unsigned int)(v613 + 16) >> 2)) >> 1)) & 1) * 2) + ((((v639 + ((~(((v641 ^ -1) | (-(v641 ^ -1))) >> 31)) & 2)) - (v643 + ((~(((v645 ^ -1) | (-(v645 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
    v714[v968] = v711;
    int * v716 = v611->cache_vals;
    int v971 = ((((((int)((unsigned int)((int)((unsigned int)(v613 + 16) >> 2)) >> 1)) & 1) * 2) + ((((v639 + ((~(((v641 ^ -1) | (-(v641 ^ -1))) >> 31)) & 2)) - (v643 + ((~(((v645 ^ -1) | (-(v645 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
    v716[v971] = v713;
    int * v718 = v611->cache_tags;
    int v974 = ((((int)((unsigned int)((int)((unsigned int)(v613 + 16) >> 2)) >> 1)) & 1) * 2) + ((((v639 + ((~(((v641 ^ -1) | (-(v641 ^ -1))) >> 31)) & 2)) - (v643 + ((~(((v645 ^ -1) | (-(v645 ^ -1))) >> 31)) & 2))) >> 31) & 1);
    int v975 = (int)((unsigned int)((int)((unsigned int)(v613 + 16) >> 2)) >> 1);
    v718[v974] = v975;
    int * v720 = v611->cache_dirty;
    v720[v974] = 0;
    int * v722 = v611->cache_age;
    v722[v974] = 1;
    int * v724 = v611->cache_age;
    int v725 = v724[v974];
    int * v726 = v611->cache_age;
    int v727 = v726[v883];
    int * v728 = v611->cache_age;
    int v983 = v727 + ((int)((unsigned int)(v727 - v725) >> 31));
    v728[v883] = v983;
    int * v730 = v611->cache_age;
    int v731 = v730[v885];
    int * v732 = v611->cache_age;
    int v986 = v731 + ((int)((unsigned int)(v731 - v725) >> 31));
    v732[v885] = v986;
    int * v734 = v611->cache_age;
    v734[v974] = 0;
    v737 = v974;
  }
  int v989 = (v737 * 2) + (((int)((unsigned int)(v613 + 16) >> 2)) & 1);
  int v738 = v624[v989];
  int * v739 = v611->regs;
  v739[12] = v738;
  struct StateT * v741 = v598->b;
  int * v742 = v741->regs;
  int v743 = v742[11];
  int * v744 = v741->cache_tags;
  int v996 = (((int)((unsigned int)((int)((unsigned int)(v743 + 16) >> 2)) >> 1)) & 1) * 2;
  int v745 = v744[v996];
  int * v746 = v741->cache_tags;
  int v998 = ((((int)((unsigned int)((int)((unsigned int)(v743 + 16) >> 2)) >> 1)) & 1) * 2) + 1;
  int v747 = v746[v998];
  int * v748 = v741->cache_tags;
  int v1000 = 4 + ((((int)((unsigned int)((int)((unsigned int)(v743 + 16) >> 2)) >> 1)) & 3) * 2);
  int v749 = v748[v1000];
  int * v750 = v741->cache_tags;
  int v1002 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v743 + 16) >> 2)) >> 1)) & 3) * 2)) + 1;
  int v751 = v750[v1002];
  int v752 = v741->timer;
  int v1003 = v752 + ((100 ^ (((~(((v749 ^ ((int)((unsigned int)((int)((unsigned int)(v743 + 16) >> 2)) >> 1))) | (-(v749 ^ ((int)((unsigned int)((int)((unsigned int)(v743 + 16) >> 2)) >> 1))))) >> 31)) | (~(((v751 ^ ((int)((unsigned int)((int)((unsigned int)(v743 + 16) >> 2)) >> 1))) | (-(v751 ^ ((int)((unsigned int)((int)((unsigned int)(v743 + 16) >> 2)) >> 1))))) >> 31))) & 104)) ^ (((~(((v745 ^ ((int)((unsigned int)((int)((unsigned int)(v743 + 16) >> 2)) >> 1))) | (-(v745 ^ ((int)((unsigned int)((int)((unsigned int)(v743 + 16) >> 2)) >> 1))))) >> 31)) | (~(((v747 ^ ((int)((unsigned int)((int)((unsigned int)(v743 + 16) >> 2)) >> 1))) | (-(v747 ^ ((int)((unsigned int)((int)((unsigned int)(v743 + 16) >> 2)) >> 1))))) >> 31))) & (1 ^ (100 ^ (((~(((v749 ^ ((int)((unsigned int)((int)((unsigned int)(v743 + 16) >> 2)) >> 1))) | (-(v749 ^ ((int)((unsigned int)((int)((unsigned int)(v743 + 16) >> 2)) >> 1))))) >> 31)) | (~(((v751 ^ ((int)((unsigned int)((int)((unsigned int)(v743 + 16) >> 2)) >> 1))) | (-(v751 ^ ((int)((unsigned int)((int)((unsigned int)(v743 + 16) >> 2)) >> 1))))) >> 31))) & 104)))));
  v741->timer = v1003;
  int * v754 = v741->cache_vals;
  bool v1004 = !(((~(((v745 ^ ((int)((unsigned int)((int)((unsigned int)(v743 + 16) >> 2)) >> 1))) | (-(v745 ^ ((int)((unsigned int)((int)((unsigned int)(v743 + 16) >> 2)) >> 1))))) >> 31)) | (~(((v747 ^ ((int)((unsigned int)((int)((unsigned int)(v743 + 16) >> 2)) >> 1))) | (-(v747 ^ ((int)((unsigned int)((int)((unsigned int)(v743 + 16) >> 2)) >> 1))))) >> 31))) == 0);
  int v867;
  if (v1004) {
    int * v755 = v741->cache_age;
    int v1006 = ((((int)((unsigned int)((int)((unsigned int)(v743 + 16) >> 2)) >> 1)) & 1) * 2) + ((~(((v747 ^ ((int)((unsigned int)((int)((unsigned int)(v743 + 16) >> 2)) >> 1))) | (-(v747 ^ ((int)((unsigned int)((int)((unsigned int)(v743 + 16) >> 2)) >> 1))))) >> 31)) & 1);
    int v756 = v755[v1006];
    int * v757 = v741->cache_age;
    int v758 = v757[v996];
    int * v759 = v741->cache_age;
    int v1009 = v758 + ((int)((unsigned int)(v758 - v756) >> 31));
    v759[v996] = v1009;
    int * v761 = v741->cache_age;
    int v762 = v761[v998];
    int * v763 = v741->cache_age;
    int v1012 = v762 + ((int)((unsigned int)(v762 - v756) >> 31));
    v763[v998] = v1012;
    int * v765 = v741->cache_age;
    v765[v1006] = 0;
    v867 = v1006;
  } else {
    int * v768 = v741->cache_age;
    int v1016 = (((int)((unsigned int)((int)((unsigned int)(v743 + 16) >> 2)) >> 1)) & 1) * 2;
    int v769 = v768[v1016];
    int * v770 = v741->cache_tags;
    int v771 = v770[v1016];
    int * v772 = v741->cache_age;
    int v773 = v772[v998];
    int * v774 = v741->cache_tags;
    int v775 = v774[v998];
    bool v1020 = !(((~(((v749 ^ ((int)((unsigned int)((int)((unsigned int)(v743 + 16) >> 2)) >> 1))) | (-(v749 ^ ((int)((unsigned int)((int)((unsigned int)(v743 + 16) >> 2)) >> 1))))) >> 31)) | (~(((v751 ^ ((int)((unsigned int)((int)((unsigned int)(v743 + 16) >> 2)) >> 1))) | (-(v751 ^ ((int)((unsigned int)((int)((unsigned int)(v743 + 16) >> 2)) >> 1))))) >> 31))) == 0);
    int v839;
    if (v1020) {
      int * v776 = v741->cache_age;
      int v1022 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v743 + 16) >> 2)) >> 1)) & 3) * 2)) + ((~(((v751 ^ ((int)((unsigned int)((int)((unsigned int)(v743 + 16) >> 2)) >> 1))) | (-(v751 ^ ((int)((unsigned int)((int)((unsigned int)(v743 + 16) >> 2)) >> 1))))) >> 31)) & 1);
      int v777 = v776[v1022];
      int * v778 = v741->cache_age;
      int v779 = v778[v1000];
      int * v780 = v741->cache_age;
      int v1025 = v779 + ((int)((unsigned int)(v779 - v777) >> 31));
      v780[v1000] = v1025;
      int * v782 = v741->cache_age;
      int v783 = v782[v1002];
      int * v784 = v741->cache_age;
      int v1028 = v783 + ((int)((unsigned int)(v783 - v777) >> 31));
      v784[v1002] = v1028;
      int * v786 = v741->cache_age;
      v786[v1022] = 0;
      v839 = v1022;
    } else {
      int * v789 = v741->cache_age;
      int v1032 = 4 + ((((int)((unsigned int)((int)((unsigned int)(v743 + 16) >> 2)) >> 1)) & 3) * 2);
      int v790 = v789[v1032];
      int * v791 = v741->cache_tags;
      int v792 = v791[v1032];
      int * v793 = v741->cache_age;
      int v794 = v793[v1002];
      int * v795 = v741->cache_tags;
      int v796 = v795[v1002];
      int * v797 = v741->cache_dirty;
      int v1037 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v743 + 16) >> 2)) >> 1)) & 3) * 2)) + ((((v790 + ((~(((v792 ^ -1) | (-(v792 ^ -1))) >> 31)) & 2)) - (v794 + ((~(((v796 ^ -1) | (-(v796 ^ -1))) >> 31)) & 2))) >> 31) & 1);
      int v798 = v797[v1037];
      bool v1038 = !(v798 == 0);
      if (v1038) {
        int * v799 = v741->cache_tags;
        int v800 = v799[v1037];
        int * v801 = v741->cache_vals;
        int v1041 = ((4 + ((((int)((unsigned int)((int)((unsigned int)(v743 + 16) >> 2)) >> 1)) & 3) * 2)) + ((((v790 + ((~(((v792 ^ -1) | (-(v792 ^ -1))) >> 31)) & 2)) - (v794 + ((~(((v796 ^ -1) | (-(v796 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
        int v802 = v801[v1041];
        int * v803 = v741->cache_vals;
        int v1043 = (((4 + ((((int)((unsigned int)((int)((unsigned int)(v743 + 16) >> 2)) >> 1)) & 3) * 2)) + ((((v790 + ((~(((v792 ^ -1) | (-(v792 ^ -1))) >> 31)) & 2)) - (v794 + ((~(((v796 ^ -1) | (-(v796 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
        int v804 = v803[v1043];
        int * v805 = v741->mem;
        int v1045 = v800 * 2;
        v805[v1045] = v802;
        int * v807 = v741->mem;
        int v1048 = (v800 * 2) + 1;
        v807[v1048] = v804;
        ;
      } else {
        ;
      }
      int * v812 = v741->mem;
      int v1053 = ((int)((unsigned int)((int)((unsigned int)(v743 + 16) >> 2)) >> 1)) * 2;
      int v813 = v812[v1053];
      int * v814 = v741->mem;
      int v1055 = (((int)((unsigned int)((int)((unsigned int)(v743 + 16) >> 2)) >> 1)) * 2) + 1;
      int v815 = v814[v1055];
      int * v816 = v741->cache_vals;
      int v1057 = ((4 + ((((int)((unsigned int)((int)((unsigned int)(v743 + 16) >> 2)) >> 1)) & 3) * 2)) + ((((v790 + ((~(((v792 ^ -1) | (-(v792 ^ -1))) >> 31)) & 2)) - (v794 + ((~(((v796 ^ -1) | (-(v796 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
      v816[v1057] = v813;
      int * v818 = v741->cache_vals;
      int v1060 = (((4 + ((((int)((unsigned int)((int)((unsigned int)(v743 + 16) >> 2)) >> 1)) & 3) * 2)) + ((((v790 + ((~(((v792 ^ -1) | (-(v792 ^ -1))) >> 31)) & 2)) - (v794 + ((~(((v796 ^ -1) | (-(v796 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
      v818[v1060] = v815;
      int * v820 = v741->cache_tags;
      int v1063 = (int)((unsigned int)((int)((unsigned int)(v743 + 16) >> 2)) >> 1);
      v820[v1037] = v1063;
      int * v822 = v741->cache_dirty;
      v822[v1037] = 0;
      int * v824 = v741->cache_age;
      v824[v1037] = 1;
      int * v826 = v741->cache_age;
      int v827 = v826[v1037];
      int * v828 = v741->cache_age;
      int v829 = v828[v1000];
      int * v830 = v741->cache_age;
      int v1071 = v829 + ((int)((unsigned int)(v829 - v827) >> 31));
      v830[v1000] = v1071;
      int * v832 = v741->cache_age;
      int v833 = v832[v1002];
      int * v834 = v741->cache_age;
      int v1074 = v833 + ((int)((unsigned int)(v833 - v827) >> 31));
      v834[v1002] = v1074;
      int * v836 = v741->cache_age;
      v836[v1037] = 0;
      v839 = v1037;
    }
    int * v840 = v741->cache_vals;
    int v1077 = v839 * 2;
    int v841 = v840[v1077];
    int * v842 = v741->cache_vals;
    int v1079 = (v839 * 2) + 1;
    int v843 = v842[v1079];
    int * v844 = v741->cache_vals;
    int v1081 = (((((int)((unsigned int)((int)((unsigned int)(v743 + 16) >> 2)) >> 1)) & 1) * 2) + ((((v769 + ((~(((v771 ^ -1) | (-(v771 ^ -1))) >> 31)) & 2)) - (v773 + ((~(((v775 ^ -1) | (-(v775 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
    v844[v1081] = v841;
    int * v846 = v741->cache_vals;
    int v1084 = ((((((int)((unsigned int)((int)((unsigned int)(v743 + 16) >> 2)) >> 1)) & 1) * 2) + ((((v769 + ((~(((v771 ^ -1) | (-(v771 ^ -1))) >> 31)) & 2)) - (v773 + ((~(((v775 ^ -1) | (-(v775 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
    v846[v1084] = v843;
    int * v848 = v741->cache_tags;
    int v1087 = ((((int)((unsigned int)((int)((unsigned int)(v743 + 16) >> 2)) >> 1)) & 1) * 2) + ((((v769 + ((~(((v771 ^ -1) | (-(v771 ^ -1))) >> 31)) & 2)) - (v773 + ((~(((v775 ^ -1) | (-(v775 ^ -1))) >> 31)) & 2))) >> 31) & 1);
    int v1088 = (int)((unsigned int)((int)((unsigned int)(v743 + 16) >> 2)) >> 1);
    v848[v1087] = v1088;
    int * v850 = v741->cache_dirty;
    v850[v1087] = 0;
    int * v852 = v741->cache_age;
    v852[v1087] = 1;
    int * v854 = v741->cache_age;
    int v855 = v854[v1087];
    int * v856 = v741->cache_age;
    int v857 = v856[v996];
    int * v858 = v741->cache_age;
    int v1096 = v857 + ((int)((unsigned int)(v857 - v855) >> 31));
    v858[v996] = v1096;
    int * v860 = v741->cache_age;
    int v861 = v860[v998];
    int * v862 = v741->cache_age;
    int v1099 = v861 + ((int)((unsigned int)(v861 - v855) >> 31));
    v862[v998] = v1099;
    int * v864 = v741->cache_age;
    v864[v1087] = 0;
    v867 = v1087;
  }
  int v1102 = (v867 * 2) + (((int)((unsigned int)(v743 + 16) >> 2)) & 1);
  int v868 = v754[v1102];
  int * v869 = v741->regs;
  v869[12] = v868;
  return v598;
}

struct StateT2 * slot_0(struct StateT2 * v2) {
  struct StateT * v3 = v2->a;
  int v4 = v3->timer;
  struct StateT * v5 = v2->b;
  int v6 = v5->timer;
  bool v30 = v4 == v6;
  squared_assert(v30);
  squared_assume(v30);
  struct StateT * v9 = v2->a;
  int v10 = v9->timer;
  int v32 = v10 + 1;
  v9->timer = v32;
  struct StateT * v12 = v2->b;
  int v13 = v12->timer;
  int v34 = v13 + 1;
  v12->timer = v34;
  struct StateT * v15 = v2->a;
  int * v16 = v15->regs;
  int v17 = v16[10];
  struct StateT * v18 = v2->b;
  int * v19 = v18->regs;
  int v20 = v19[10];
  bool v40 = (v17 == 0) == (v20 == 0);
  squared_diverged(v40);
  squared_assume(v40);
  bool v41 = v17 == 0;
  struct StateT2 * v26;
  if (v41) {
    v26 = v2;
  } else {
    struct StateT2 * v24 = slot_1(v2);
    v26 = v24;
  }
  return v26;
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

void squared_assert(bool c) { koika_assert(c, "timer drift"); }
void squared_diverged(bool c) { koika_assert(c, "control flow diverged"); }
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