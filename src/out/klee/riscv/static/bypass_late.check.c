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

struct StateT * slot_5(struct StateT * v80);
struct StateT * slot_2(struct StateT * v30);
struct StateT * slot_7(struct StateT * v115);
struct StateT * slot_3(struct StateT * v38);
struct StateT * snippet(struct StateT * v0);
struct StateT * slot_10(struct StateT * v648);
struct StateT * slot_1(struct StateT * v17);
struct StateT * slot_8(struct StateT * v430);
struct StateT * slot_4(struct StateT * v60);
struct StateT * slot_9(struct StateT * v634);
struct StateT * slot_0(struct StateT * v2);
struct StateT * slot_5(struct StateT * v80) {
  int * v81 = v80->regs;
  int v82 = v81[5];
  int v83 = v81[9];
  bool v102 = v82 >= v83;
  struct StateT * v97;
  if (v102) {
    int v84 = v80->timer;
    int v103 = v84 + 15;
    v80->timer = v103;
    int * v86 = v80->saved_regs;
    int v87 = v86[6];
    int * v88 = v80->regs;
    v88[6] = v87;
    int * v90 = v80->saved_regs;
    int v91 = v90[7];
    int * v92 = v80->regs;
    v92[7] = v91;
    v97 = v80;
  } else {
    struct StateT * v95 = slot_7(v80);
    v97 = v95;
  }
  return v97;
}

struct StateT * slot_2(struct StateT * v30) {
  int v31 = v30->timer;
  int v35 = v31 + 1;
  v30->timer = v35;
  struct StateT * v33 = slot_3(v30);
  return v33;
}

struct StateT * slot_7(struct StateT * v115) {
  int v116 = v115->timer;
  int v286 = v116 + 1;
  v115->timer = v286;
  int * v118 = v115->regs;
  int v119 = v118[6];
  int v120 = v118[7];
  int * v121 = v115->cache_tags;
  int v291 = (((int)((unsigned int)((int)((unsigned int)v119 >> 2)) >> 1)) & 1) * 2;
  int v122 = v121[v291];
  int v292 = ((((int)((unsigned int)((int)((unsigned int)v119 >> 2)) >> 1)) & 1) * 2) + 1;
  int v123 = v121[v292];
  int v293 = 4 + ((((int)((unsigned int)((int)((unsigned int)v119 >> 2)) >> 1)) & 3) * 2);
  int v124 = v121[v293];
  int v294 = (4 + ((((int)((unsigned int)((int)((unsigned int)v119 >> 2)) >> 1)) & 3) * 2)) + 1;
  int v125 = v121[v294];
  int v126 = v115->timer;
  int v295 = v126 + ((100 ^ (((~(((v124 ^ ((int)((unsigned int)((int)((unsigned int)v119 >> 2)) >> 1))) | (-(v124 ^ ((int)((unsigned int)((int)((unsigned int)v119 >> 2)) >> 1))))) >> 31)) | (~(((v125 ^ ((int)((unsigned int)((int)((unsigned int)v119 >> 2)) >> 1))) | (-(v125 ^ ((int)((unsigned int)((int)((unsigned int)v119 >> 2)) >> 1))))) >> 31))) & 104)) ^ (((~(((v122 ^ ((int)((unsigned int)((int)((unsigned int)v119 >> 2)) >> 1))) | (-(v122 ^ ((int)((unsigned int)((int)((unsigned int)v119 >> 2)) >> 1))))) >> 31)) | (~(((v123 ^ ((int)((unsigned int)((int)((unsigned int)v119 >> 2)) >> 1))) | (-(v123 ^ ((int)((unsigned int)((int)((unsigned int)v119 >> 2)) >> 1))))) >> 31))) & (1 ^ (100 ^ (((~(((v124 ^ ((int)((unsigned int)((int)((unsigned int)v119 >> 2)) >> 1))) | (-(v124 ^ ((int)((unsigned int)((int)((unsigned int)v119 >> 2)) >> 1))))) >> 31)) | (~(((v125 ^ ((int)((unsigned int)((int)((unsigned int)v119 >> 2)) >> 1))) | (-(v125 ^ ((int)((unsigned int)((int)((unsigned int)v119 >> 2)) >> 1))))) >> 31))) & 104)))));
  v115->timer = v295;
  bool v296 = !(((~(((v122 ^ ((int)((unsigned int)((int)((unsigned int)v119 >> 2)) >> 1))) | (-(v122 ^ ((int)((unsigned int)((int)((unsigned int)v119 >> 2)) >> 1))))) >> 31)) | (~(((v123 ^ ((int)((unsigned int)((int)((unsigned int)v119 >> 2)) >> 1))) | (-(v123 ^ ((int)((unsigned int)((int)((unsigned int)v119 >> 2)) >> 1))))) >> 31))) == 0);
  int v220;
  if (v296) {
    int * v128 = v115->cache_age;
    int v298 = ((((int)((unsigned int)((int)((unsigned int)v119 >> 2)) >> 1)) & 1) * 2) + ((~(((v123 ^ ((int)((unsigned int)((int)((unsigned int)v119 >> 2)) >> 1))) | (-(v123 ^ ((int)((unsigned int)((int)((unsigned int)v119 >> 2)) >> 1))))) >> 31)) & 1);
    int v129 = v128[v298];
    int v130 = v128[v291];
    int v299 = v130 + ((int)((unsigned int)(v130 - v129) >> 31));
    v128[v291] = v299;
    int * v132 = v115->cache_age;
    int v133 = v132[v292];
    int v301 = v133 + ((int)((unsigned int)(v133 - v129) >> 31));
    v132[v292] = v301;
    int * v135 = v115->cache_age;
    v135[v298] = 0;
    v220 = v298;
  } else {
    int * v138 = v115->cache_age;
    int v305 = (((int)((unsigned int)((int)((unsigned int)v119 >> 2)) >> 1)) & 1) * 2;
    int v139 = v138[v305];
    int * v140 = v115->cache_tags;
    int v141 = v140[v305];
    int v142 = v138[v292];
    int v143 = v140[v292];
    bool v307 = !(((~(((v124 ^ ((int)((unsigned int)((int)((unsigned int)v119 >> 2)) >> 1))) | (-(v124 ^ ((int)((unsigned int)((int)((unsigned int)v119 >> 2)) >> 1))))) >> 31)) | (~(((v125 ^ ((int)((unsigned int)((int)((unsigned int)v119 >> 2)) >> 1))) | (-(v125 ^ ((int)((unsigned int)((int)((unsigned int)v119 >> 2)) >> 1))))) >> 31))) == 0);
    int v197;
    if (v307) {
      int * v144 = v115->cache_age;
      int v309 = (4 + ((((int)((unsigned int)((int)((unsigned int)v119 >> 2)) >> 1)) & 3) * 2)) + ((~(((v125 ^ ((int)((unsigned int)((int)((unsigned int)v119 >> 2)) >> 1))) | (-(v125 ^ ((int)((unsigned int)((int)((unsigned int)v119 >> 2)) >> 1))))) >> 31)) & 1);
      int v145 = v144[v309];
      int v146 = v144[v293];
      int v310 = v146 + ((int)((unsigned int)(v146 - v145) >> 31));
      v144[v293] = v310;
      int * v148 = v115->cache_age;
      int v149 = v148[v294];
      int v312 = v149 + ((int)((unsigned int)(v149 - v145) >> 31));
      v148[v294] = v312;
      int * v151 = v115->cache_age;
      v151[v309] = 0;
      v197 = v309;
    } else {
      int * v154 = v115->cache_age;
      int v316 = 4 + ((((int)((unsigned int)((int)((unsigned int)v119 >> 2)) >> 1)) & 3) * 2);
      int v155 = v154[v316];
      int * v156 = v115->cache_tags;
      int v157 = v156[v316];
      int v158 = v154[v294];
      int v159 = v156[v294];
      int * v160 = v115->cache_dirty;
      int v319 = (4 + ((((int)((unsigned int)((int)((unsigned int)v119 >> 2)) >> 1)) & 3) * 2)) + ((((v155 + ((~(((v157 ^ -1) | (-(v157 ^ -1))) >> 31)) & 2)) - (v158 + ((~(((v159 ^ -1) | (-(v159 ^ -1))) >> 31)) & 2))) >> 31) & 1);
      int v161 = v160[v319];
      bool v320 = !(v161 == 0);
      if (v320) {
        int * v162 = v115->cache_tags;
        int v163 = v162[v319];
        int * v164 = v115->cache_vals;
        int v323 = ((4 + ((((int)((unsigned int)((int)((unsigned int)v119 >> 2)) >> 1)) & 3) * 2)) + ((((v155 + ((~(((v157 ^ -1) | (-(v157 ^ -1))) >> 31)) & 2)) - (v158 + ((~(((v159 ^ -1) | (-(v159 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
        int v165 = v164[v323];
        int v324 = (((4 + ((((int)((unsigned int)((int)((unsigned int)v119 >> 2)) >> 1)) & 3) * 2)) + ((((v155 + ((~(((v157 ^ -1) | (-(v157 ^ -1))) >> 31)) & 2)) - (v158 + ((~(((v159 ^ -1) | (-(v159 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
        int v166 = v164[v324];
        int * v167 = v115->mem;
        int v326 = v163 * 2;
        v167[v326] = v165;
        int * v169 = v115->mem;
        int v329 = (v163 * 2) + 1;
        v169[v329] = v166;
        ;
      } else {
        ;
      }
      int * v174 = v115->mem;
      int v334 = ((int)((unsigned int)((int)((unsigned int)v119 >> 2)) >> 1)) * 2;
      int v175 = v174[v334];
      int v335 = (((int)((unsigned int)((int)((unsigned int)v119 >> 2)) >> 1)) * 2) + 1;
      int v176 = v174[v335];
      int * v177 = v115->cache_vals;
      int v337 = ((4 + ((((int)((unsigned int)((int)((unsigned int)v119 >> 2)) >> 1)) & 3) * 2)) + ((((v155 + ((~(((v157 ^ -1) | (-(v157 ^ -1))) >> 31)) & 2)) - (v158 + ((~(((v159 ^ -1) | (-(v159 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
      v177[v337] = v175;
      int * v179 = v115->cache_vals;
      int v340 = (((4 + ((((int)((unsigned int)((int)((unsigned int)v119 >> 2)) >> 1)) & 3) * 2)) + ((((v155 + ((~(((v157 ^ -1) | (-(v157 ^ -1))) >> 31)) & 2)) - (v158 + ((~(((v159 ^ -1) | (-(v159 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
      v179[v340] = v176;
      int * v181 = v115->cache_tags;
      int v343 = (int)((unsigned int)((int)((unsigned int)v119 >> 2)) >> 1);
      v181[v319] = v343;
      int * v183 = v115->cache_dirty;
      v183[v319] = 0;
      int * v185 = v115->cache_age;
      v185[v319] = 1;
      int * v187 = v115->cache_age;
      int v188 = v187[v319];
      int v189 = v187[v293];
      int v349 = v189 + ((int)((unsigned int)(v189 - v188) >> 31));
      v187[v293] = v349;
      int * v191 = v115->cache_age;
      int v192 = v191[v294];
      int v351 = v192 + ((int)((unsigned int)(v192 - v188) >> 31));
      v191[v294] = v351;
      int * v194 = v115->cache_age;
      v194[v319] = 0;
      v197 = v319;
    }
    int * v198 = v115->cache_vals;
    int v354 = v197 * 2;
    int v199 = v198[v354];
    int v355 = (v197 * 2) + 1;
    int v200 = v198[v355];
    int v356 = (((((int)((unsigned int)((int)((unsigned int)v119 >> 2)) >> 1)) & 1) * 2) + ((((v139 + ((~(((v141 ^ -1) | (-(v141 ^ -1))) >> 31)) & 2)) - (v142 + ((~(((v143 ^ -1) | (-(v143 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
    v198[v356] = v199;
    int * v202 = v115->cache_vals;
    int v359 = ((((((int)((unsigned int)((int)((unsigned int)v119 >> 2)) >> 1)) & 1) * 2) + ((((v139 + ((~(((v141 ^ -1) | (-(v141 ^ -1))) >> 31)) & 2)) - (v142 + ((~(((v143 ^ -1) | (-(v143 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
    v202[v359] = v200;
    int * v204 = v115->cache_tags;
    int v362 = ((((int)((unsigned int)((int)((unsigned int)v119 >> 2)) >> 1)) & 1) * 2) + ((((v139 + ((~(((v141 ^ -1) | (-(v141 ^ -1))) >> 31)) & 2)) - (v142 + ((~(((v143 ^ -1) | (-(v143 ^ -1))) >> 31)) & 2))) >> 31) & 1);
    int v363 = (int)((unsigned int)((int)((unsigned int)v119 >> 2)) >> 1);
    v204[v362] = v363;
    int * v206 = v115->cache_dirty;
    v206[v362] = 0;
    int * v208 = v115->cache_age;
    v208[v362] = 1;
    int * v210 = v115->cache_age;
    int v211 = v210[v362];
    int v212 = v210[v291];
    int v369 = v212 + ((int)((unsigned int)(v212 - v211) >> 31));
    v210[v291] = v369;
    int * v214 = v115->cache_age;
    int v215 = v214[v292];
    int v371 = v215 + ((int)((unsigned int)(v215 - v211) >> 31));
    v214[v292] = v371;
    int * v217 = v115->cache_age;
    v217[v362] = 0;
    v220 = v362;
  }
  int * v221 = v115->cache_vals;
  int v374 = (v220 * 2) + (((int)((unsigned int)v119 >> 2)) & 1);
  v221[v374] = v120;
  int * v223 = v115->cache_tags;
  int v224 = v223[v293];
  int v225 = v223[v294];
  bool v377 = !(((~(((v224 ^ ((int)((unsigned int)((int)((unsigned int)v119 >> 2)) >> 1))) | (-(v224 ^ ((int)((unsigned int)((int)((unsigned int)v119 >> 2)) >> 1))))) >> 31)) | (~(((v225 ^ ((int)((unsigned int)((int)((unsigned int)v119 >> 2)) >> 1))) | (-(v225 ^ ((int)((unsigned int)((int)((unsigned int)v119 >> 2)) >> 1))))) >> 31))) == 0);
  int v279;
  if (v377) {
    int * v226 = v115->cache_age;
    int v379 = (4 + ((((int)((unsigned int)((int)((unsigned int)v119 >> 2)) >> 1)) & 3) * 2)) + ((~(((v225 ^ ((int)((unsigned int)((int)((unsigned int)v119 >> 2)) >> 1))) | (-(v225 ^ ((int)((unsigned int)((int)((unsigned int)v119 >> 2)) >> 1))))) >> 31)) & 1);
    int v227 = v226[v379];
    int v228 = v226[v293];
    int v380 = v228 + ((int)((unsigned int)(v228 - v227) >> 31));
    v226[v293] = v380;
    int * v230 = v115->cache_age;
    int v231 = v230[v294];
    int v382 = v231 + ((int)((unsigned int)(v231 - v227) >> 31));
    v230[v294] = v382;
    int * v233 = v115->cache_age;
    v233[v379] = 0;
    v279 = v379;
  } else {
    int * v236 = v115->cache_age;
    int v386 = 4 + ((((int)((unsigned int)((int)((unsigned int)v119 >> 2)) >> 1)) & 3) * 2);
    int v237 = v236[v386];
    int * v238 = v115->cache_tags;
    int v239 = v238[v386];
    int v240 = v236[v294];
    int v241 = v238[v294];
    int * v242 = v115->cache_dirty;
    int v389 = (4 + ((((int)((unsigned int)((int)((unsigned int)v119 >> 2)) >> 1)) & 3) * 2)) + ((((v237 + ((~(((v239 ^ -1) | (-(v239 ^ -1))) >> 31)) & 2)) - (v240 + ((~(((v241 ^ -1) | (-(v241 ^ -1))) >> 31)) & 2))) >> 31) & 1);
    int v243 = v242[v389];
    bool v390 = !(v243 == 0);
    if (v390) {
      int * v244 = v115->cache_tags;
      int v245 = v244[v389];
      int * v246 = v115->cache_vals;
      int v393 = ((4 + ((((int)((unsigned int)((int)((unsigned int)v119 >> 2)) >> 1)) & 3) * 2)) + ((((v237 + ((~(((v239 ^ -1) | (-(v239 ^ -1))) >> 31)) & 2)) - (v240 + ((~(((v241 ^ -1) | (-(v241 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
      int v247 = v246[v393];
      int v394 = (((4 + ((((int)((unsigned int)((int)((unsigned int)v119 >> 2)) >> 1)) & 3) * 2)) + ((((v237 + ((~(((v239 ^ -1) | (-(v239 ^ -1))) >> 31)) & 2)) - (v240 + ((~(((v241 ^ -1) | (-(v241 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
      int v248 = v246[v394];
      int * v249 = v115->mem;
      int v396 = v245 * 2;
      v249[v396] = v247;
      int * v251 = v115->mem;
      int v399 = (v245 * 2) + 1;
      v251[v399] = v248;
      ;
    } else {
      ;
    }
    int * v256 = v115->mem;
    int v404 = ((int)((unsigned int)((int)((unsigned int)v119 >> 2)) >> 1)) * 2;
    int v257 = v256[v404];
    int v405 = (((int)((unsigned int)((int)((unsigned int)v119 >> 2)) >> 1)) * 2) + 1;
    int v258 = v256[v405];
    int * v259 = v115->cache_vals;
    int v407 = ((4 + ((((int)((unsigned int)((int)((unsigned int)v119 >> 2)) >> 1)) & 3) * 2)) + ((((v237 + ((~(((v239 ^ -1) | (-(v239 ^ -1))) >> 31)) & 2)) - (v240 + ((~(((v241 ^ -1) | (-(v241 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
    v259[v407] = v257;
    int * v261 = v115->cache_vals;
    int v410 = (((4 + ((((int)((unsigned int)((int)((unsigned int)v119 >> 2)) >> 1)) & 3) * 2)) + ((((v237 + ((~(((v239 ^ -1) | (-(v239 ^ -1))) >> 31)) & 2)) - (v240 + ((~(((v241 ^ -1) | (-(v241 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
    v261[v410] = v258;
    int * v263 = v115->cache_tags;
    int v413 = (int)((unsigned int)((int)((unsigned int)v119 >> 2)) >> 1);
    v263[v389] = v413;
    int * v265 = v115->cache_dirty;
    v265[v389] = 0;
    int * v267 = v115->cache_age;
    v267[v389] = 1;
    int * v269 = v115->cache_age;
    int v270 = v269[v389];
    int v271 = v269[v293];
    int v419 = v271 + ((int)((unsigned int)(v271 - v270) >> 31));
    v269[v293] = v419;
    int * v273 = v115->cache_age;
    int v274 = v273[v294];
    int v421 = v274 + ((int)((unsigned int)(v274 - v270) >> 31));
    v273[v294] = v421;
    int * v276 = v115->cache_age;
    v276[v389] = 0;
    v279 = v389;
  }
  int * v280 = v115->cache_vals;
  int v424 = (v279 * 2) + (((int)((unsigned int)v119 >> 2)) & 1);
  v280[v424] = v120;
  int * v282 = v115->cache_dirty;
  v282[v279] = 1;
  struct StateT * v284 = slot_8(v115);
  return v284;
}

struct StateT * slot_3(struct StateT * v38) {
  int * v39 = v38->saved_regs;
  int * v40 = v38->regs;
  int v41 = v40[6];
  v39[6] = v41;
  int v43 = v38->timer;
  int v54 = v43 + 1;
  v38->timer = v54;
  int * v45 = v38->regs;
  int v46 = v45[5];
  int v57 = v46 + 80;
  v45[6] = v57;
  struct StateT * v48 = slot_4(v38);
  return v48;
}

struct StateT * snippet(struct StateT * v0) {
  struct StateT * v1 = slot_0(v0);
  return v1;
}

struct StateT * slot_10(struct StateT * v648) {
  int v649 = v648->timer;
  int v758 = v649 + 1;
  v648->timer = v758;
  int * v651 = v648->regs;
  int v652 = v651[11];
  int * v653 = v648->cache_tags;
  int v762 = (((int)((unsigned int)((int)((unsigned int)v652 >> 2)) >> 1)) & 1) * 2;
  int v654 = v653[v762];
  int v763 = ((((int)((unsigned int)((int)((unsigned int)v652 >> 2)) >> 1)) & 1) * 2) + 1;
  int v655 = v653[v763];
  int v764 = 4 + ((((int)((unsigned int)((int)((unsigned int)v652 >> 2)) >> 1)) & 3) * 2);
  int v656 = v653[v764];
  int v765 = (4 + ((((int)((unsigned int)((int)((unsigned int)v652 >> 2)) >> 1)) & 3) * 2)) + 1;
  int v657 = v653[v765];
  int v658 = v648->timer;
  int v766 = v658 + ((100 ^ (((~(((v656 ^ ((int)((unsigned int)((int)((unsigned int)v652 >> 2)) >> 1))) | (-(v656 ^ ((int)((unsigned int)((int)((unsigned int)v652 >> 2)) >> 1))))) >> 31)) | (~(((v657 ^ ((int)((unsigned int)((int)((unsigned int)v652 >> 2)) >> 1))) | (-(v657 ^ ((int)((unsigned int)((int)((unsigned int)v652 >> 2)) >> 1))))) >> 31))) & 104)) ^ (((~(((v654 ^ ((int)((unsigned int)((int)((unsigned int)v652 >> 2)) >> 1))) | (-(v654 ^ ((int)((unsigned int)((int)((unsigned int)v652 >> 2)) >> 1))))) >> 31)) | (~(((v655 ^ ((int)((unsigned int)((int)((unsigned int)v652 >> 2)) >> 1))) | (-(v655 ^ ((int)((unsigned int)((int)((unsigned int)v652 >> 2)) >> 1))))) >> 31))) & (1 ^ (100 ^ (((~(((v656 ^ ((int)((unsigned int)((int)((unsigned int)v652 >> 2)) >> 1))) | (-(v656 ^ ((int)((unsigned int)((int)((unsigned int)v652 >> 2)) >> 1))))) >> 31)) | (~(((v657 ^ ((int)((unsigned int)((int)((unsigned int)v652 >> 2)) >> 1))) | (-(v657 ^ ((int)((unsigned int)((int)((unsigned int)v652 >> 2)) >> 1))))) >> 31))) & 104)))));
  v648->timer = v766;
  int * v660 = v648->cache_vals;
  bool v767 = !(((~(((v654 ^ ((int)((unsigned int)((int)((unsigned int)v652 >> 2)) >> 1))) | (-(v654 ^ ((int)((unsigned int)((int)((unsigned int)v652 >> 2)) >> 1))))) >> 31)) | (~(((v655 ^ ((int)((unsigned int)((int)((unsigned int)v652 >> 2)) >> 1))) | (-(v655 ^ ((int)((unsigned int)((int)((unsigned int)v652 >> 2)) >> 1))))) >> 31))) == 0);
  int v753;
  if (v767) {
    int * v661 = v648->cache_age;
    int v769 = ((((int)((unsigned int)((int)((unsigned int)v652 >> 2)) >> 1)) & 1) * 2) + ((~(((v655 ^ ((int)((unsigned int)((int)((unsigned int)v652 >> 2)) >> 1))) | (-(v655 ^ ((int)((unsigned int)((int)((unsigned int)v652 >> 2)) >> 1))))) >> 31)) & 1);
    int v662 = v661[v769];
    int v663 = v661[v762];
    int v770 = v663 + ((int)((unsigned int)(v663 - v662) >> 31));
    v661[v762] = v770;
    int * v665 = v648->cache_age;
    int v666 = v665[v763];
    int v772 = v666 + ((int)((unsigned int)(v666 - v662) >> 31));
    v665[v763] = v772;
    int * v668 = v648->cache_age;
    v668[v769] = 0;
    v753 = v769;
  } else {
    int * v671 = v648->cache_age;
    int v776 = (((int)((unsigned int)((int)((unsigned int)v652 >> 2)) >> 1)) & 1) * 2;
    int v672 = v671[v776];
    int * v673 = v648->cache_tags;
    int v674 = v673[v776];
    int v675 = v671[v763];
    int v676 = v673[v763];
    bool v778 = !(((~(((v656 ^ ((int)((unsigned int)((int)((unsigned int)v652 >> 2)) >> 1))) | (-(v656 ^ ((int)((unsigned int)((int)((unsigned int)v652 >> 2)) >> 1))))) >> 31)) | (~(((v657 ^ ((int)((unsigned int)((int)((unsigned int)v652 >> 2)) >> 1))) | (-(v657 ^ ((int)((unsigned int)((int)((unsigned int)v652 >> 2)) >> 1))))) >> 31))) == 0);
    int v730;
    if (v778) {
      int * v677 = v648->cache_age;
      int v780 = (4 + ((((int)((unsigned int)((int)((unsigned int)v652 >> 2)) >> 1)) & 3) * 2)) + ((~(((v657 ^ ((int)((unsigned int)((int)((unsigned int)v652 >> 2)) >> 1))) | (-(v657 ^ ((int)((unsigned int)((int)((unsigned int)v652 >> 2)) >> 1))))) >> 31)) & 1);
      int v678 = v677[v780];
      int v679 = v677[v764];
      int v781 = v679 + ((int)((unsigned int)(v679 - v678) >> 31));
      v677[v764] = v781;
      int * v681 = v648->cache_age;
      int v682 = v681[v765];
      int v783 = v682 + ((int)((unsigned int)(v682 - v678) >> 31));
      v681[v765] = v783;
      int * v684 = v648->cache_age;
      v684[v780] = 0;
      v730 = v780;
    } else {
      int * v687 = v648->cache_age;
      int v787 = 4 + ((((int)((unsigned int)((int)((unsigned int)v652 >> 2)) >> 1)) & 3) * 2);
      int v688 = v687[v787];
      int * v689 = v648->cache_tags;
      int v690 = v689[v787];
      int v691 = v687[v765];
      int v692 = v689[v765];
      int * v693 = v648->cache_dirty;
      int v790 = (4 + ((((int)((unsigned int)((int)((unsigned int)v652 >> 2)) >> 1)) & 3) * 2)) + ((((v688 + ((~(((v690 ^ -1) | (-(v690 ^ -1))) >> 31)) & 2)) - (v691 + ((~(((v692 ^ -1) | (-(v692 ^ -1))) >> 31)) & 2))) >> 31) & 1);
      int v694 = v693[v790];
      bool v791 = !(v694 == 0);
      if (v791) {
        int * v695 = v648->cache_tags;
        int v696 = v695[v790];
        int * v697 = v648->cache_vals;
        int v794 = ((4 + ((((int)((unsigned int)((int)((unsigned int)v652 >> 2)) >> 1)) & 3) * 2)) + ((((v688 + ((~(((v690 ^ -1) | (-(v690 ^ -1))) >> 31)) & 2)) - (v691 + ((~(((v692 ^ -1) | (-(v692 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
        int v698 = v697[v794];
        int v795 = (((4 + ((((int)((unsigned int)((int)((unsigned int)v652 >> 2)) >> 1)) & 3) * 2)) + ((((v688 + ((~(((v690 ^ -1) | (-(v690 ^ -1))) >> 31)) & 2)) - (v691 + ((~(((v692 ^ -1) | (-(v692 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
        int v699 = v697[v795];
        int * v700 = v648->mem;
        int v797 = v696 * 2;
        v700[v797] = v698;
        int * v702 = v648->mem;
        int v800 = (v696 * 2) + 1;
        v702[v800] = v699;
        ;
      } else {
        ;
      }
      int * v707 = v648->mem;
      int v805 = ((int)((unsigned int)((int)((unsigned int)v652 >> 2)) >> 1)) * 2;
      int v708 = v707[v805];
      int v806 = (((int)((unsigned int)((int)((unsigned int)v652 >> 2)) >> 1)) * 2) + 1;
      int v709 = v707[v806];
      int * v710 = v648->cache_vals;
      int v808 = ((4 + ((((int)((unsigned int)((int)((unsigned int)v652 >> 2)) >> 1)) & 3) * 2)) + ((((v688 + ((~(((v690 ^ -1) | (-(v690 ^ -1))) >> 31)) & 2)) - (v691 + ((~(((v692 ^ -1) | (-(v692 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
      v710[v808] = v708;
      int * v712 = v648->cache_vals;
      int v811 = (((4 + ((((int)((unsigned int)((int)((unsigned int)v652 >> 2)) >> 1)) & 3) * 2)) + ((((v688 + ((~(((v690 ^ -1) | (-(v690 ^ -1))) >> 31)) & 2)) - (v691 + ((~(((v692 ^ -1) | (-(v692 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
      v712[v811] = v709;
      int * v714 = v648->cache_tags;
      int v814 = (int)((unsigned int)((int)((unsigned int)v652 >> 2)) >> 1);
      v714[v790] = v814;
      int * v716 = v648->cache_dirty;
      v716[v790] = 0;
      int * v718 = v648->cache_age;
      v718[v790] = 1;
      int * v720 = v648->cache_age;
      int v721 = v720[v790];
      int v722 = v720[v764];
      int v820 = v722 + ((int)((unsigned int)(v722 - v721) >> 31));
      v720[v764] = v820;
      int * v724 = v648->cache_age;
      int v725 = v724[v765];
      int v822 = v725 + ((int)((unsigned int)(v725 - v721) >> 31));
      v724[v765] = v822;
      int * v727 = v648->cache_age;
      v727[v790] = 0;
      v730 = v790;
    }
    int * v731 = v648->cache_vals;
    int v825 = v730 * 2;
    int v732 = v731[v825];
    int v826 = (v730 * 2) + 1;
    int v733 = v731[v826];
    int v827 = (((((int)((unsigned int)((int)((unsigned int)v652 >> 2)) >> 1)) & 1) * 2) + ((((v672 + ((~(((v674 ^ -1) | (-(v674 ^ -1))) >> 31)) & 2)) - (v675 + ((~(((v676 ^ -1) | (-(v676 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
    v731[v827] = v732;
    int * v735 = v648->cache_vals;
    int v830 = ((((((int)((unsigned int)((int)((unsigned int)v652 >> 2)) >> 1)) & 1) * 2) + ((((v672 + ((~(((v674 ^ -1) | (-(v674 ^ -1))) >> 31)) & 2)) - (v675 + ((~(((v676 ^ -1) | (-(v676 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
    v735[v830] = v733;
    int * v737 = v648->cache_tags;
    int v833 = ((((int)((unsigned int)((int)((unsigned int)v652 >> 2)) >> 1)) & 1) * 2) + ((((v672 + ((~(((v674 ^ -1) | (-(v674 ^ -1))) >> 31)) & 2)) - (v675 + ((~(((v676 ^ -1) | (-(v676 ^ -1))) >> 31)) & 2))) >> 31) & 1);
    int v834 = (int)((unsigned int)((int)((unsigned int)v652 >> 2)) >> 1);
    v737[v833] = v834;
    int * v739 = v648->cache_dirty;
    v739[v833] = 0;
    int * v741 = v648->cache_age;
    v741[v833] = 1;
    int * v743 = v648->cache_age;
    int v744 = v743[v833];
    int v745 = v743[v762];
    int v840 = v745 + ((int)((unsigned int)(v745 - v744) >> 31));
    v743[v762] = v840;
    int * v747 = v648->cache_age;
    int v748 = v747[v763];
    int v842 = v748 + ((int)((unsigned int)(v748 - v744) >> 31));
    v747[v763] = v842;
    int * v750 = v648->cache_age;
    v750[v833] = 0;
    v753 = v833;
  }
  int v845 = (v753 * 2) + (((int)((unsigned int)v652 >> 2)) & 1);
  int v754 = v660[v845];
  int * v755 = v648->regs;
  v755[12] = v754;
  return v648;
}

struct StateT * slot_1(struct StateT * v17) {
  int v18 = v17->timer;
  int v24 = v18 + 1;
  v17->timer = v24;
  int * v20 = v17->regs;
  v20[9] = 32;
  struct StateT * v22 = slot_2(v17);
  return v22;
}

struct StateT * slot_8(struct StateT * v430) {
  int v431 = v430->timer;
  int v541 = v431 + 1;
  v430->timer = v541;
  int * v433 = v430->regs;
  int v434 = v433[6];
  int * v435 = v430->cache_tags;
  int v545 = (((int)((unsigned int)((int)((unsigned int)v434 >> 2)) >> 1)) & 1) * 2;
  int v436 = v435[v545];
  int v546 = ((((int)((unsigned int)((int)((unsigned int)v434 >> 2)) >> 1)) & 1) * 2) + 1;
  int v437 = v435[v546];
  int v547 = 4 + ((((int)((unsigned int)((int)((unsigned int)v434 >> 2)) >> 1)) & 3) * 2);
  int v438 = v435[v547];
  int v548 = (4 + ((((int)((unsigned int)((int)((unsigned int)v434 >> 2)) >> 1)) & 3) * 2)) + 1;
  int v439 = v435[v548];
  int v440 = v430->timer;
  int v549 = v440 + ((100 ^ (((~(((v438 ^ ((int)((unsigned int)((int)((unsigned int)v434 >> 2)) >> 1))) | (-(v438 ^ ((int)((unsigned int)((int)((unsigned int)v434 >> 2)) >> 1))))) >> 31)) | (~(((v439 ^ ((int)((unsigned int)((int)((unsigned int)v434 >> 2)) >> 1))) | (-(v439 ^ ((int)((unsigned int)((int)((unsigned int)v434 >> 2)) >> 1))))) >> 31))) & 104)) ^ (((~(((v436 ^ ((int)((unsigned int)((int)((unsigned int)v434 >> 2)) >> 1))) | (-(v436 ^ ((int)((unsigned int)((int)((unsigned int)v434 >> 2)) >> 1))))) >> 31)) | (~(((v437 ^ ((int)((unsigned int)((int)((unsigned int)v434 >> 2)) >> 1))) | (-(v437 ^ ((int)((unsigned int)((int)((unsigned int)v434 >> 2)) >> 1))))) >> 31))) & (1 ^ (100 ^ (((~(((v438 ^ ((int)((unsigned int)((int)((unsigned int)v434 >> 2)) >> 1))) | (-(v438 ^ ((int)((unsigned int)((int)((unsigned int)v434 >> 2)) >> 1))))) >> 31)) | (~(((v439 ^ ((int)((unsigned int)((int)((unsigned int)v434 >> 2)) >> 1))) | (-(v439 ^ ((int)((unsigned int)((int)((unsigned int)v434 >> 2)) >> 1))))) >> 31))) & 104)))));
  v430->timer = v549;
  int * v442 = v430->cache_vals;
  bool v550 = !(((~(((v436 ^ ((int)((unsigned int)((int)((unsigned int)v434 >> 2)) >> 1))) | (-(v436 ^ ((int)((unsigned int)((int)((unsigned int)v434 >> 2)) >> 1))))) >> 31)) | (~(((v437 ^ ((int)((unsigned int)((int)((unsigned int)v434 >> 2)) >> 1))) | (-(v437 ^ ((int)((unsigned int)((int)((unsigned int)v434 >> 2)) >> 1))))) >> 31))) == 0);
  int v535;
  if (v550) {
    int * v443 = v430->cache_age;
    int v552 = ((((int)((unsigned int)((int)((unsigned int)v434 >> 2)) >> 1)) & 1) * 2) + ((~(((v437 ^ ((int)((unsigned int)((int)((unsigned int)v434 >> 2)) >> 1))) | (-(v437 ^ ((int)((unsigned int)((int)((unsigned int)v434 >> 2)) >> 1))))) >> 31)) & 1);
    int v444 = v443[v552];
    int v445 = v443[v545];
    int v553 = v445 + ((int)((unsigned int)(v445 - v444) >> 31));
    v443[v545] = v553;
    int * v447 = v430->cache_age;
    int v448 = v447[v546];
    int v555 = v448 + ((int)((unsigned int)(v448 - v444) >> 31));
    v447[v546] = v555;
    int * v450 = v430->cache_age;
    v450[v552] = 0;
    v535 = v552;
  } else {
    int * v453 = v430->cache_age;
    int v559 = (((int)((unsigned int)((int)((unsigned int)v434 >> 2)) >> 1)) & 1) * 2;
    int v454 = v453[v559];
    int * v455 = v430->cache_tags;
    int v456 = v455[v559];
    int v457 = v453[v546];
    int v458 = v455[v546];
    bool v561 = !(((~(((v438 ^ ((int)((unsigned int)((int)((unsigned int)v434 >> 2)) >> 1))) | (-(v438 ^ ((int)((unsigned int)((int)((unsigned int)v434 >> 2)) >> 1))))) >> 31)) | (~(((v439 ^ ((int)((unsigned int)((int)((unsigned int)v434 >> 2)) >> 1))) | (-(v439 ^ ((int)((unsigned int)((int)((unsigned int)v434 >> 2)) >> 1))))) >> 31))) == 0);
    int v512;
    if (v561) {
      int * v459 = v430->cache_age;
      int v563 = (4 + ((((int)((unsigned int)((int)((unsigned int)v434 >> 2)) >> 1)) & 3) * 2)) + ((~(((v439 ^ ((int)((unsigned int)((int)((unsigned int)v434 >> 2)) >> 1))) | (-(v439 ^ ((int)((unsigned int)((int)((unsigned int)v434 >> 2)) >> 1))))) >> 31)) & 1);
      int v460 = v459[v563];
      int v461 = v459[v547];
      int v564 = v461 + ((int)((unsigned int)(v461 - v460) >> 31));
      v459[v547] = v564;
      int * v463 = v430->cache_age;
      int v464 = v463[v548];
      int v566 = v464 + ((int)((unsigned int)(v464 - v460) >> 31));
      v463[v548] = v566;
      int * v466 = v430->cache_age;
      v466[v563] = 0;
      v512 = v563;
    } else {
      int * v469 = v430->cache_age;
      int v570 = 4 + ((((int)((unsigned int)((int)((unsigned int)v434 >> 2)) >> 1)) & 3) * 2);
      int v470 = v469[v570];
      int * v471 = v430->cache_tags;
      int v472 = v471[v570];
      int v473 = v469[v548];
      int v474 = v471[v548];
      int * v475 = v430->cache_dirty;
      int v573 = (4 + ((((int)((unsigned int)((int)((unsigned int)v434 >> 2)) >> 1)) & 3) * 2)) + ((((v470 + ((~(((v472 ^ -1) | (-(v472 ^ -1))) >> 31)) & 2)) - (v473 + ((~(((v474 ^ -1) | (-(v474 ^ -1))) >> 31)) & 2))) >> 31) & 1);
      int v476 = v475[v573];
      bool v574 = !(v476 == 0);
      if (v574) {
        int * v477 = v430->cache_tags;
        int v478 = v477[v573];
        int * v479 = v430->cache_vals;
        int v577 = ((4 + ((((int)((unsigned int)((int)((unsigned int)v434 >> 2)) >> 1)) & 3) * 2)) + ((((v470 + ((~(((v472 ^ -1) | (-(v472 ^ -1))) >> 31)) & 2)) - (v473 + ((~(((v474 ^ -1) | (-(v474 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
        int v480 = v479[v577];
        int v578 = (((4 + ((((int)((unsigned int)((int)((unsigned int)v434 >> 2)) >> 1)) & 3) * 2)) + ((((v470 + ((~(((v472 ^ -1) | (-(v472 ^ -1))) >> 31)) & 2)) - (v473 + ((~(((v474 ^ -1) | (-(v474 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
        int v481 = v479[v578];
        int * v482 = v430->mem;
        int v580 = v478 * 2;
        v482[v580] = v480;
        int * v484 = v430->mem;
        int v583 = (v478 * 2) + 1;
        v484[v583] = v481;
        ;
      } else {
        ;
      }
      int * v489 = v430->mem;
      int v588 = ((int)((unsigned int)((int)((unsigned int)v434 >> 2)) >> 1)) * 2;
      int v490 = v489[v588];
      int v589 = (((int)((unsigned int)((int)((unsigned int)v434 >> 2)) >> 1)) * 2) + 1;
      int v491 = v489[v589];
      int * v492 = v430->cache_vals;
      int v591 = ((4 + ((((int)((unsigned int)((int)((unsigned int)v434 >> 2)) >> 1)) & 3) * 2)) + ((((v470 + ((~(((v472 ^ -1) | (-(v472 ^ -1))) >> 31)) & 2)) - (v473 + ((~(((v474 ^ -1) | (-(v474 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
      v492[v591] = v490;
      int * v494 = v430->cache_vals;
      int v594 = (((4 + ((((int)((unsigned int)((int)((unsigned int)v434 >> 2)) >> 1)) & 3) * 2)) + ((((v470 + ((~(((v472 ^ -1) | (-(v472 ^ -1))) >> 31)) & 2)) - (v473 + ((~(((v474 ^ -1) | (-(v474 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
      v494[v594] = v491;
      int * v496 = v430->cache_tags;
      int v597 = (int)((unsigned int)((int)((unsigned int)v434 >> 2)) >> 1);
      v496[v573] = v597;
      int * v498 = v430->cache_dirty;
      v498[v573] = 0;
      int * v500 = v430->cache_age;
      v500[v573] = 1;
      int * v502 = v430->cache_age;
      int v503 = v502[v573];
      int v504 = v502[v547];
      int v603 = v504 + ((int)((unsigned int)(v504 - v503) >> 31));
      v502[v547] = v603;
      int * v506 = v430->cache_age;
      int v507 = v506[v548];
      int v605 = v507 + ((int)((unsigned int)(v507 - v503) >> 31));
      v506[v548] = v605;
      int * v509 = v430->cache_age;
      v509[v573] = 0;
      v512 = v573;
    }
    int * v513 = v430->cache_vals;
    int v608 = v512 * 2;
    int v514 = v513[v608];
    int v609 = (v512 * 2) + 1;
    int v515 = v513[v609];
    int v610 = (((((int)((unsigned int)((int)((unsigned int)v434 >> 2)) >> 1)) & 1) * 2) + ((((v454 + ((~(((v456 ^ -1) | (-(v456 ^ -1))) >> 31)) & 2)) - (v457 + ((~(((v458 ^ -1) | (-(v458 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
    v513[v610] = v514;
    int * v517 = v430->cache_vals;
    int v613 = ((((((int)((unsigned int)((int)((unsigned int)v434 >> 2)) >> 1)) & 1) * 2) + ((((v454 + ((~(((v456 ^ -1) | (-(v456 ^ -1))) >> 31)) & 2)) - (v457 + ((~(((v458 ^ -1) | (-(v458 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
    v517[v613] = v515;
    int * v519 = v430->cache_tags;
    int v616 = ((((int)((unsigned int)((int)((unsigned int)v434 >> 2)) >> 1)) & 1) * 2) + ((((v454 + ((~(((v456 ^ -1) | (-(v456 ^ -1))) >> 31)) & 2)) - (v457 + ((~(((v458 ^ -1) | (-(v458 ^ -1))) >> 31)) & 2))) >> 31) & 1);
    int v617 = (int)((unsigned int)((int)((unsigned int)v434 >> 2)) >> 1);
    v519[v616] = v617;
    int * v521 = v430->cache_dirty;
    v521[v616] = 0;
    int * v523 = v430->cache_age;
    v523[v616] = 1;
    int * v525 = v430->cache_age;
    int v526 = v525[v616];
    int v527 = v525[v545];
    int v623 = v527 + ((int)((unsigned int)(v527 - v526) >> 31));
    v525[v545] = v623;
    int * v529 = v430->cache_age;
    int v530 = v529[v546];
    int v625 = v530 + ((int)((unsigned int)(v530 - v526) >> 31));
    v529[v546] = v625;
    int * v532 = v430->cache_age;
    v532[v616] = 0;
    v535 = v616;
  }
  int v628 = (v535 * 2) + (((int)((unsigned int)v434 >> 2)) & 1);
  int v536 = v442[v628];
  int * v537 = v430->regs;
  v537[11] = v536;
  struct StateT * v539 = slot_9(v430);
  return v539;
}

struct StateT * slot_4(struct StateT * v60) {
  int * v61 = v60->saved_regs;
  int * v62 = v60->regs;
  int v63 = v62[7];
  v61[7] = v63;
  int v65 = v60->timer;
  int v75 = v65 + 1;
  v60->timer = v75;
  int * v67 = v60->regs;
  v67[7] = 0;
  struct StateT * v69 = slot_5(v60);
  return v69;
}

struct StateT * slot_9(struct StateT * v634) {
  int v635 = v634->timer;
  int v642 = v635 + 1;
  v634->timer = v642;
  int * v637 = v634->regs;
  int v638 = v637[11];
  int v645 = v638 << 2;
  v637[11] = v645;
  struct StateT * v640 = slot_10(v634);
  return v640;
}

struct StateT * slot_0(struct StateT * v2) {
  int v3 = v2->timer;
  int v10 = v3 + 1;
  v2->timer = v10;
  int * v5 = v2->regs;
  int v6 = v5[10];
  int v14 = v6 & 28;
  v5[5] = v14;
  struct StateT * v8 = slot_1(v2);
  return v8;
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