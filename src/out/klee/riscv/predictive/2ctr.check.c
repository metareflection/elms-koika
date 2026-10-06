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

struct StateT * snippet(struct StateT * v0);
struct StateT * slot_1(struct StateT * v10);
struct StateT * slot_4(struct StateT * v446);
struct StateT * slot_2(struct StateT * v221);
struct StateT * slot_3(struct StateT * v235);
struct StateT * slot_0(struct StateT * v2);
struct StateT * snippet(struct StateT * v0) {
  struct StateT * v1 = slot_0(v0);
  return v1;
}

struct StateT * slot_1(struct StateT * v10) {
  int * v11 = v10->saved_regs;
  int * v12 = v10->regs;
  int v13 = v12[11];
  v11[11] = v13;
  int v15 = v10->timer;
  int v129 = v15 + 1;
  v10->timer = v129;
  int * v17 = v10->regs;
  int v18 = v17[10];
  int * v19 = v10->cache_tags;
  int v133 = (((int)((unsigned int)((int)((unsigned int)v18 >> 2)) >> 1)) & 1) * 2;
  int v20 = v19[v133];
  int v134 = ((((int)((unsigned int)((int)((unsigned int)v18 >> 2)) >> 1)) & 1) * 2) + 1;
  int v21 = v19[v134];
  int v135 = 4 + ((((int)((unsigned int)((int)((unsigned int)v18 >> 2)) >> 1)) & 3) * 2);
  int v22 = v19[v135];
  int v136 = (4 + ((((int)((unsigned int)((int)((unsigned int)v18 >> 2)) >> 1)) & 3) * 2)) + 1;
  int v23 = v19[v136];
  int v24 = v10->timer;
  int v137 = v24 + ((100 ^ (((~(((v22 ^ ((int)((unsigned int)((int)((unsigned int)v18 >> 2)) >> 1))) | (-(v22 ^ ((int)((unsigned int)((int)((unsigned int)v18 >> 2)) >> 1))))) >> 31)) | (~(((v23 ^ ((int)((unsigned int)((int)((unsigned int)v18 >> 2)) >> 1))) | (-(v23 ^ ((int)((unsigned int)((int)((unsigned int)v18 >> 2)) >> 1))))) >> 31))) & 104)) ^ (((~(((v20 ^ ((int)((unsigned int)((int)((unsigned int)v18 >> 2)) >> 1))) | (-(v20 ^ ((int)((unsigned int)((int)((unsigned int)v18 >> 2)) >> 1))))) >> 31)) | (~(((v21 ^ ((int)((unsigned int)((int)((unsigned int)v18 >> 2)) >> 1))) | (-(v21 ^ ((int)((unsigned int)((int)((unsigned int)v18 >> 2)) >> 1))))) >> 31))) & (1 ^ (100 ^ (((~(((v22 ^ ((int)((unsigned int)((int)((unsigned int)v18 >> 2)) >> 1))) | (-(v22 ^ ((int)((unsigned int)((int)((unsigned int)v18 >> 2)) >> 1))))) >> 31)) | (~(((v23 ^ ((int)((unsigned int)((int)((unsigned int)v18 >> 2)) >> 1))) | (-(v23 ^ ((int)((unsigned int)((int)((unsigned int)v18 >> 2)) >> 1))))) >> 31))) & 104)))));
  v10->timer = v137;
  int * v26 = v10->cache_vals;
  bool v138 = !(((~(((v20 ^ ((int)((unsigned int)((int)((unsigned int)v18 >> 2)) >> 1))) | (-(v20 ^ ((int)((unsigned int)((int)((unsigned int)v18 >> 2)) >> 1))))) >> 31)) | (~(((v21 ^ ((int)((unsigned int)((int)((unsigned int)v18 >> 2)) >> 1))) | (-(v21 ^ ((int)((unsigned int)((int)((unsigned int)v18 >> 2)) >> 1))))) >> 31))) == 0);
  int v119;
  if (v138) {
    int * v27 = v10->cache_age;
    int v140 = ((((int)((unsigned int)((int)((unsigned int)v18 >> 2)) >> 1)) & 1) * 2) + ((~(((v21 ^ ((int)((unsigned int)((int)((unsigned int)v18 >> 2)) >> 1))) | (-(v21 ^ ((int)((unsigned int)((int)((unsigned int)v18 >> 2)) >> 1))))) >> 31)) & 1);
    int v28 = v27[v140];
    int v29 = v27[v133];
    int v141 = v29 + ((int)((unsigned int)(v29 - v28) >> 31));
    v27[v133] = v141;
    int * v31 = v10->cache_age;
    int v32 = v31[v134];
    int v143 = v32 + ((int)((unsigned int)(v32 - v28) >> 31));
    v31[v134] = v143;
    int * v34 = v10->cache_age;
    v34[v140] = 0;
    v119 = v140;
  } else {
    int * v37 = v10->cache_age;
    int v147 = (((int)((unsigned int)((int)((unsigned int)v18 >> 2)) >> 1)) & 1) * 2;
    int v38 = v37[v147];
    int * v39 = v10->cache_tags;
    int v40 = v39[v147];
    int v41 = v37[v134];
    int v42 = v39[v134];
    bool v149 = !(((~(((v22 ^ ((int)((unsigned int)((int)((unsigned int)v18 >> 2)) >> 1))) | (-(v22 ^ ((int)((unsigned int)((int)((unsigned int)v18 >> 2)) >> 1))))) >> 31)) | (~(((v23 ^ ((int)((unsigned int)((int)((unsigned int)v18 >> 2)) >> 1))) | (-(v23 ^ ((int)((unsigned int)((int)((unsigned int)v18 >> 2)) >> 1))))) >> 31))) == 0);
    int v96;
    if (v149) {
      int * v43 = v10->cache_age;
      int v151 = (4 + ((((int)((unsigned int)((int)((unsigned int)v18 >> 2)) >> 1)) & 3) * 2)) + ((~(((v23 ^ ((int)((unsigned int)((int)((unsigned int)v18 >> 2)) >> 1))) | (-(v23 ^ ((int)((unsigned int)((int)((unsigned int)v18 >> 2)) >> 1))))) >> 31)) & 1);
      int v44 = v43[v151];
      int v45 = v43[v135];
      int v152 = v45 + ((int)((unsigned int)(v45 - v44) >> 31));
      v43[v135] = v152;
      int * v47 = v10->cache_age;
      int v48 = v47[v136];
      int v154 = v48 + ((int)((unsigned int)(v48 - v44) >> 31));
      v47[v136] = v154;
      int * v50 = v10->cache_age;
      v50[v151] = 0;
      v96 = v151;
    } else {
      int * v53 = v10->cache_age;
      int v158 = 4 + ((((int)((unsigned int)((int)((unsigned int)v18 >> 2)) >> 1)) & 3) * 2);
      int v54 = v53[v158];
      int * v55 = v10->cache_tags;
      int v56 = v55[v158];
      int v57 = v53[v136];
      int v58 = v55[v136];
      int * v59 = v10->cache_dirty;
      int v161 = (4 + ((((int)((unsigned int)((int)((unsigned int)v18 >> 2)) >> 1)) & 3) * 2)) + ((((v54 + ((~(((v56 ^ -1) | (-(v56 ^ -1))) >> 31)) & 2)) - (v57 + ((~(((v58 ^ -1) | (-(v58 ^ -1))) >> 31)) & 2))) >> 31) & 1);
      int v60 = v59[v161];
      bool v162 = !(v60 == 0);
      if (v162) {
        int * v61 = v10->cache_tags;
        int v62 = v61[v161];
        int * v63 = v10->cache_vals;
        int v165 = ((4 + ((((int)((unsigned int)((int)((unsigned int)v18 >> 2)) >> 1)) & 3) * 2)) + ((((v54 + ((~(((v56 ^ -1) | (-(v56 ^ -1))) >> 31)) & 2)) - (v57 + ((~(((v58 ^ -1) | (-(v58 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
        int v64 = v63[v165];
        int v166 = (((4 + ((((int)((unsigned int)((int)((unsigned int)v18 >> 2)) >> 1)) & 3) * 2)) + ((((v54 + ((~(((v56 ^ -1) | (-(v56 ^ -1))) >> 31)) & 2)) - (v57 + ((~(((v58 ^ -1) | (-(v58 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
        int v65 = v63[v166];
        int * v66 = v10->mem;
        int v168 = v62 * 2;
        v66[v168] = v64;
        int * v68 = v10->mem;
        int v171 = (v62 * 2) + 1;
        v68[v171] = v65;
        ;
      } else {
        ;
      }
      int * v73 = v10->mem;
      int v176 = ((int)((unsigned int)((int)((unsigned int)v18 >> 2)) >> 1)) * 2;
      int v74 = v73[v176];
      int v177 = (((int)((unsigned int)((int)((unsigned int)v18 >> 2)) >> 1)) * 2) + 1;
      int v75 = v73[v177];
      int * v76 = v10->cache_vals;
      int v179 = ((4 + ((((int)((unsigned int)((int)((unsigned int)v18 >> 2)) >> 1)) & 3) * 2)) + ((((v54 + ((~(((v56 ^ -1) | (-(v56 ^ -1))) >> 31)) & 2)) - (v57 + ((~(((v58 ^ -1) | (-(v58 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
      v76[v179] = v74;
      int * v78 = v10->cache_vals;
      int v182 = (((4 + ((((int)((unsigned int)((int)((unsigned int)v18 >> 2)) >> 1)) & 3) * 2)) + ((((v54 + ((~(((v56 ^ -1) | (-(v56 ^ -1))) >> 31)) & 2)) - (v57 + ((~(((v58 ^ -1) | (-(v58 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
      v78[v182] = v75;
      int * v80 = v10->cache_tags;
      int v185 = (int)((unsigned int)((int)((unsigned int)v18 >> 2)) >> 1);
      v80[v161] = v185;
      int * v82 = v10->cache_dirty;
      v82[v161] = 0;
      int * v84 = v10->cache_age;
      v84[v161] = 1;
      int * v86 = v10->cache_age;
      int v87 = v86[v161];
      int v88 = v86[v135];
      int v191 = v88 + ((int)((unsigned int)(v88 - v87) >> 31));
      v86[v135] = v191;
      int * v90 = v10->cache_age;
      int v91 = v90[v136];
      int v193 = v91 + ((int)((unsigned int)(v91 - v87) >> 31));
      v90[v136] = v193;
      int * v93 = v10->cache_age;
      v93[v161] = 0;
      v96 = v161;
    }
    int * v97 = v10->cache_vals;
    int v196 = v96 * 2;
    int v98 = v97[v196];
    int v197 = (v96 * 2) + 1;
    int v99 = v97[v197];
    int v198 = (((((int)((unsigned int)((int)((unsigned int)v18 >> 2)) >> 1)) & 1) * 2) + ((((v38 + ((~(((v40 ^ -1) | (-(v40 ^ -1))) >> 31)) & 2)) - (v41 + ((~(((v42 ^ -1) | (-(v42 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
    v97[v198] = v98;
    int * v101 = v10->cache_vals;
    int v201 = ((((((int)((unsigned int)((int)((unsigned int)v18 >> 2)) >> 1)) & 1) * 2) + ((((v38 + ((~(((v40 ^ -1) | (-(v40 ^ -1))) >> 31)) & 2)) - (v41 + ((~(((v42 ^ -1) | (-(v42 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
    v101[v201] = v99;
    int * v103 = v10->cache_tags;
    int v204 = ((((int)((unsigned int)((int)((unsigned int)v18 >> 2)) >> 1)) & 1) * 2) + ((((v38 + ((~(((v40 ^ -1) | (-(v40 ^ -1))) >> 31)) & 2)) - (v41 + ((~(((v42 ^ -1) | (-(v42 ^ -1))) >> 31)) & 2))) >> 31) & 1);
    int v205 = (int)((unsigned int)((int)((unsigned int)v18 >> 2)) >> 1);
    v103[v204] = v205;
    int * v105 = v10->cache_dirty;
    v105[v204] = 0;
    int * v107 = v10->cache_age;
    v107[v204] = 1;
    int * v109 = v10->cache_age;
    int v110 = v109[v204];
    int v111 = v109[v133];
    int v211 = v111 + ((int)((unsigned int)(v111 - v110) >> 31));
    v109[v133] = v211;
    int * v113 = v10->cache_age;
    int v114 = v113[v134];
    int v213 = v114 + ((int)((unsigned int)(v114 - v110) >> 31));
    v113[v134] = v213;
    int * v116 = v10->cache_age;
    v116[v204] = 0;
    v119 = v204;
  }
  int v216 = (v119 * 2) + (((int)((unsigned int)v18 >> 2)) & 1);
  int v120 = v26[v216];
  int * v121 = v10->regs;
  v121[11] = v120;
  struct StateT * v123 = slot_2(v10);
  return v123;
}

struct StateT * slot_4(struct StateT * v446) {
  int * v447 = v446->regs;
  int v448 = v447[10];
  bool v465 = v448 == 0;
  struct StateT * v461;
  if (v465) {
    int v449 = v446->timer;
    int v466 = v449 + 15;
    v446->timer = v466;
    int * v451 = v446->saved_regs;
    int v452 = v451[11];
    int * v453 = v446->regs;
    v453[11] = v452;
    int * v455 = v446->saved_regs;
    int v456 = v455[12];
    int * v457 = v446->regs;
    v457[12] = v456;
    v461 = v446;
  } else {
    v461 = v446;
  }
  return v461;
}

struct StateT * slot_2(struct StateT * v221) {
  int v222 = v221->timer;
  int v229 = v222 + 1;
  v221->timer = v229;
  int * v224 = v221->regs;
  int v225 = v224[11];
  int v232 = v225 << 2;
  v224[11] = v232;
  struct StateT * v227 = slot_3(v221);
  return v227;
}

struct StateT * slot_3(struct StateT * v235) {
  int * v236 = v235->saved_regs;
  int * v237 = v235->regs;
  int v238 = v237[12];
  v236[12] = v238;
  int v240 = v235->timer;
  int v354 = v240 + 1;
  v235->timer = v354;
  int * v242 = v235->regs;
  int v243 = v242[11];
  int * v244 = v235->cache_tags;
  int v358 = (((int)((unsigned int)((int)((unsigned int)(v243 + 16) >> 2)) >> 1)) & 1) * 2;
  int v245 = v244[v358];
  int v359 = ((((int)((unsigned int)((int)((unsigned int)(v243 + 16) >> 2)) >> 1)) & 1) * 2) + 1;
  int v246 = v244[v359];
  int v360 = 4 + ((((int)((unsigned int)((int)((unsigned int)(v243 + 16) >> 2)) >> 1)) & 3) * 2);
  int v247 = v244[v360];
  int v361 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v243 + 16) >> 2)) >> 1)) & 3) * 2)) + 1;
  int v248 = v244[v361];
  int v249 = v235->timer;
  int v362 = v249 + ((100 ^ (((~(((v247 ^ ((int)((unsigned int)((int)((unsigned int)(v243 + 16) >> 2)) >> 1))) | (-(v247 ^ ((int)((unsigned int)((int)((unsigned int)(v243 + 16) >> 2)) >> 1))))) >> 31)) | (~(((v248 ^ ((int)((unsigned int)((int)((unsigned int)(v243 + 16) >> 2)) >> 1))) | (-(v248 ^ ((int)((unsigned int)((int)((unsigned int)(v243 + 16) >> 2)) >> 1))))) >> 31))) & 104)) ^ (((~(((v245 ^ ((int)((unsigned int)((int)((unsigned int)(v243 + 16) >> 2)) >> 1))) | (-(v245 ^ ((int)((unsigned int)((int)((unsigned int)(v243 + 16) >> 2)) >> 1))))) >> 31)) | (~(((v246 ^ ((int)((unsigned int)((int)((unsigned int)(v243 + 16) >> 2)) >> 1))) | (-(v246 ^ ((int)((unsigned int)((int)((unsigned int)(v243 + 16) >> 2)) >> 1))))) >> 31))) & (1 ^ (100 ^ (((~(((v247 ^ ((int)((unsigned int)((int)((unsigned int)(v243 + 16) >> 2)) >> 1))) | (-(v247 ^ ((int)((unsigned int)((int)((unsigned int)(v243 + 16) >> 2)) >> 1))))) >> 31)) | (~(((v248 ^ ((int)((unsigned int)((int)((unsigned int)(v243 + 16) >> 2)) >> 1))) | (-(v248 ^ ((int)((unsigned int)((int)((unsigned int)(v243 + 16) >> 2)) >> 1))))) >> 31))) & 104)))));
  v235->timer = v362;
  int * v251 = v235->cache_vals;
  bool v363 = !(((~(((v245 ^ ((int)((unsigned int)((int)((unsigned int)(v243 + 16) >> 2)) >> 1))) | (-(v245 ^ ((int)((unsigned int)((int)((unsigned int)(v243 + 16) >> 2)) >> 1))))) >> 31)) | (~(((v246 ^ ((int)((unsigned int)((int)((unsigned int)(v243 + 16) >> 2)) >> 1))) | (-(v246 ^ ((int)((unsigned int)((int)((unsigned int)(v243 + 16) >> 2)) >> 1))))) >> 31))) == 0);
  int v344;
  if (v363) {
    int * v252 = v235->cache_age;
    int v365 = ((((int)((unsigned int)((int)((unsigned int)(v243 + 16) >> 2)) >> 1)) & 1) * 2) + ((~(((v246 ^ ((int)((unsigned int)((int)((unsigned int)(v243 + 16) >> 2)) >> 1))) | (-(v246 ^ ((int)((unsigned int)((int)((unsigned int)(v243 + 16) >> 2)) >> 1))))) >> 31)) & 1);
    int v253 = v252[v365];
    int v254 = v252[v358];
    int v366 = v254 + ((int)((unsigned int)(v254 - v253) >> 31));
    v252[v358] = v366;
    int * v256 = v235->cache_age;
    int v257 = v256[v359];
    int v368 = v257 + ((int)((unsigned int)(v257 - v253) >> 31));
    v256[v359] = v368;
    int * v259 = v235->cache_age;
    v259[v365] = 0;
    v344 = v365;
  } else {
    int * v262 = v235->cache_age;
    int v372 = (((int)((unsigned int)((int)((unsigned int)(v243 + 16) >> 2)) >> 1)) & 1) * 2;
    int v263 = v262[v372];
    int * v264 = v235->cache_tags;
    int v265 = v264[v372];
    int v266 = v262[v359];
    int v267 = v264[v359];
    bool v374 = !(((~(((v247 ^ ((int)((unsigned int)((int)((unsigned int)(v243 + 16) >> 2)) >> 1))) | (-(v247 ^ ((int)((unsigned int)((int)((unsigned int)(v243 + 16) >> 2)) >> 1))))) >> 31)) | (~(((v248 ^ ((int)((unsigned int)((int)((unsigned int)(v243 + 16) >> 2)) >> 1))) | (-(v248 ^ ((int)((unsigned int)((int)((unsigned int)(v243 + 16) >> 2)) >> 1))))) >> 31))) == 0);
    int v321;
    if (v374) {
      int * v268 = v235->cache_age;
      int v376 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v243 + 16) >> 2)) >> 1)) & 3) * 2)) + ((~(((v248 ^ ((int)((unsigned int)((int)((unsigned int)(v243 + 16) >> 2)) >> 1))) | (-(v248 ^ ((int)((unsigned int)((int)((unsigned int)(v243 + 16) >> 2)) >> 1))))) >> 31)) & 1);
      int v269 = v268[v376];
      int v270 = v268[v360];
      int v377 = v270 + ((int)((unsigned int)(v270 - v269) >> 31));
      v268[v360] = v377;
      int * v272 = v235->cache_age;
      int v273 = v272[v361];
      int v379 = v273 + ((int)((unsigned int)(v273 - v269) >> 31));
      v272[v361] = v379;
      int * v275 = v235->cache_age;
      v275[v376] = 0;
      v321 = v376;
    } else {
      int * v278 = v235->cache_age;
      int v383 = 4 + ((((int)((unsigned int)((int)((unsigned int)(v243 + 16) >> 2)) >> 1)) & 3) * 2);
      int v279 = v278[v383];
      int * v280 = v235->cache_tags;
      int v281 = v280[v383];
      int v282 = v278[v361];
      int v283 = v280[v361];
      int * v284 = v235->cache_dirty;
      int v386 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v243 + 16) >> 2)) >> 1)) & 3) * 2)) + ((((v279 + ((~(((v281 ^ -1) | (-(v281 ^ -1))) >> 31)) & 2)) - (v282 + ((~(((v283 ^ -1) | (-(v283 ^ -1))) >> 31)) & 2))) >> 31) & 1);
      int v285 = v284[v386];
      bool v387 = !(v285 == 0);
      if (v387) {
        int * v286 = v235->cache_tags;
        int v287 = v286[v386];
        int * v288 = v235->cache_vals;
        int v390 = ((4 + ((((int)((unsigned int)((int)((unsigned int)(v243 + 16) >> 2)) >> 1)) & 3) * 2)) + ((((v279 + ((~(((v281 ^ -1) | (-(v281 ^ -1))) >> 31)) & 2)) - (v282 + ((~(((v283 ^ -1) | (-(v283 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
        int v289 = v288[v390];
        int v391 = (((4 + ((((int)((unsigned int)((int)((unsigned int)(v243 + 16) >> 2)) >> 1)) & 3) * 2)) + ((((v279 + ((~(((v281 ^ -1) | (-(v281 ^ -1))) >> 31)) & 2)) - (v282 + ((~(((v283 ^ -1) | (-(v283 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
        int v290 = v288[v391];
        int * v291 = v235->mem;
        int v393 = v287 * 2;
        v291[v393] = v289;
        int * v293 = v235->mem;
        int v396 = (v287 * 2) + 1;
        v293[v396] = v290;
        ;
      } else {
        ;
      }
      int * v298 = v235->mem;
      int v401 = ((int)((unsigned int)((int)((unsigned int)(v243 + 16) >> 2)) >> 1)) * 2;
      int v299 = v298[v401];
      int v402 = (((int)((unsigned int)((int)((unsigned int)(v243 + 16) >> 2)) >> 1)) * 2) + 1;
      int v300 = v298[v402];
      int * v301 = v235->cache_vals;
      int v404 = ((4 + ((((int)((unsigned int)((int)((unsigned int)(v243 + 16) >> 2)) >> 1)) & 3) * 2)) + ((((v279 + ((~(((v281 ^ -1) | (-(v281 ^ -1))) >> 31)) & 2)) - (v282 + ((~(((v283 ^ -1) | (-(v283 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
      v301[v404] = v299;
      int * v303 = v235->cache_vals;
      int v407 = (((4 + ((((int)((unsigned int)((int)((unsigned int)(v243 + 16) >> 2)) >> 1)) & 3) * 2)) + ((((v279 + ((~(((v281 ^ -1) | (-(v281 ^ -1))) >> 31)) & 2)) - (v282 + ((~(((v283 ^ -1) | (-(v283 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
      v303[v407] = v300;
      int * v305 = v235->cache_tags;
      int v410 = (int)((unsigned int)((int)((unsigned int)(v243 + 16) >> 2)) >> 1);
      v305[v386] = v410;
      int * v307 = v235->cache_dirty;
      v307[v386] = 0;
      int * v309 = v235->cache_age;
      v309[v386] = 1;
      int * v311 = v235->cache_age;
      int v312 = v311[v386];
      int v313 = v311[v360];
      int v416 = v313 + ((int)((unsigned int)(v313 - v312) >> 31));
      v311[v360] = v416;
      int * v315 = v235->cache_age;
      int v316 = v315[v361];
      int v418 = v316 + ((int)((unsigned int)(v316 - v312) >> 31));
      v315[v361] = v418;
      int * v318 = v235->cache_age;
      v318[v386] = 0;
      v321 = v386;
    }
    int * v322 = v235->cache_vals;
    int v421 = v321 * 2;
    int v323 = v322[v421];
    int v422 = (v321 * 2) + 1;
    int v324 = v322[v422];
    int v423 = (((((int)((unsigned int)((int)((unsigned int)(v243 + 16) >> 2)) >> 1)) & 1) * 2) + ((((v263 + ((~(((v265 ^ -1) | (-(v265 ^ -1))) >> 31)) & 2)) - (v266 + ((~(((v267 ^ -1) | (-(v267 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
    v322[v423] = v323;
    int * v326 = v235->cache_vals;
    int v426 = ((((((int)((unsigned int)((int)((unsigned int)(v243 + 16) >> 2)) >> 1)) & 1) * 2) + ((((v263 + ((~(((v265 ^ -1) | (-(v265 ^ -1))) >> 31)) & 2)) - (v266 + ((~(((v267 ^ -1) | (-(v267 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
    v326[v426] = v324;
    int * v328 = v235->cache_tags;
    int v429 = ((((int)((unsigned int)((int)((unsigned int)(v243 + 16) >> 2)) >> 1)) & 1) * 2) + ((((v263 + ((~(((v265 ^ -1) | (-(v265 ^ -1))) >> 31)) & 2)) - (v266 + ((~(((v267 ^ -1) | (-(v267 ^ -1))) >> 31)) & 2))) >> 31) & 1);
    int v430 = (int)((unsigned int)((int)((unsigned int)(v243 + 16) >> 2)) >> 1);
    v328[v429] = v430;
    int * v330 = v235->cache_dirty;
    v330[v429] = 0;
    int * v332 = v235->cache_age;
    v332[v429] = 1;
    int * v334 = v235->cache_age;
    int v335 = v334[v429];
    int v336 = v334[v358];
    int v436 = v336 + ((int)((unsigned int)(v336 - v335) >> 31));
    v334[v358] = v436;
    int * v338 = v235->cache_age;
    int v339 = v338[v359];
    int v438 = v339 + ((int)((unsigned int)(v339 - v335) >> 31));
    v338[v359] = v438;
    int * v341 = v235->cache_age;
    v341[v429] = 0;
    v344 = v429;
  }
  int v441 = (v344 * 2) + (((int)((unsigned int)(v243 + 16) >> 2)) & 1);
  int v345 = v251[v441];
  int * v346 = v235->regs;
  v346[12] = v345;
  struct StateT * v348 = slot_4(v235);
  return v348;
}

struct StateT * slot_0(struct StateT * v2) {
  int v3 = v2->timer;
  int v7 = v3 + 1;
  v2->timer = v7;
  struct StateT * v5 = slot_1(v2);
  return v5;
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