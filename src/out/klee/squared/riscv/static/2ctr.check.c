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
struct StateT2 * slot_1(struct StateT2 * v26);
struct StateT2 * slot_4(struct StateT2 * v937);
struct StateT2 * slot_2(struct StateT2 * v462);
struct StateT2 * slot_3(struct StateT2 * v501);
struct StateT2 * slot_0(struct StateT2 * v2);
struct StateT2 * snippet(struct StateT2 * v0) {
  struct StateT2 * v1 = slot_0(v0);
  return v1;
}

struct StateT2 * slot_1(struct StateT2 * v26) {
  struct StateT * v27 = v26->a;
  int v28 = v27->timer;
  struct StateT * v29 = v26->b;
  int v30 = v29->timer;
  bool v267 = v28 == v30;
  squared_assert(v267);
  squared_assume(v267);
  struct StateT * v33 = v26->a;
  int * v34 = v33->saved_regs;
  int * v35 = v33->regs;
  int v36 = v35[11];
  v34[11] = v36;
  struct StateT * v38 = v26->b;
  int * v39 = v38->saved_regs;
  int * v40 = v38->regs;
  int v41 = v40[11];
  v39[11] = v41;
  struct StateT * v43 = v26->a;
  int v44 = v43->timer;
  int v278 = v44 + 1;
  v43->timer = v278;
  struct StateT * v46 = v26->b;
  int v47 = v46->timer;
  int v280 = v47 + 1;
  v46->timer = v280;
  struct StateT * v49 = v26->a;
  int * v50 = v49->regs;
  int v51 = v50[10];
  int * v52 = v49->cache_tags;
  int v285 = (((int)((unsigned int)((int)((unsigned int)v51 >> 2)) >> 1)) & 1) * 2;
  int v53 = v52[v285];
  int v286 = ((((int)((unsigned int)((int)((unsigned int)v51 >> 2)) >> 1)) & 1) * 2) + 1;
  int v54 = v52[v286];
  int v287 = 4 + ((((int)((unsigned int)((int)((unsigned int)v51 >> 2)) >> 1)) & 3) * 2);
  int v55 = v52[v287];
  int v288 = (4 + ((((int)((unsigned int)((int)((unsigned int)v51 >> 2)) >> 1)) & 3) * 2)) + 1;
  int v56 = v52[v288];
  int v57 = v49->timer;
  int v289 = v57 + ((100 ^ (((~(((v55 ^ ((int)((unsigned int)((int)((unsigned int)v51 >> 2)) >> 1))) | (-(v55 ^ ((int)((unsigned int)((int)((unsigned int)v51 >> 2)) >> 1))))) >> 31)) | (~(((v56 ^ ((int)((unsigned int)((int)((unsigned int)v51 >> 2)) >> 1))) | (-(v56 ^ ((int)((unsigned int)((int)((unsigned int)v51 >> 2)) >> 1))))) >> 31))) & 104)) ^ (((~(((v53 ^ ((int)((unsigned int)((int)((unsigned int)v51 >> 2)) >> 1))) | (-(v53 ^ ((int)((unsigned int)((int)((unsigned int)v51 >> 2)) >> 1))))) >> 31)) | (~(((v54 ^ ((int)((unsigned int)((int)((unsigned int)v51 >> 2)) >> 1))) | (-(v54 ^ ((int)((unsigned int)((int)((unsigned int)v51 >> 2)) >> 1))))) >> 31))) & (1 ^ (100 ^ (((~(((v55 ^ ((int)((unsigned int)((int)((unsigned int)v51 >> 2)) >> 1))) | (-(v55 ^ ((int)((unsigned int)((int)((unsigned int)v51 >> 2)) >> 1))))) >> 31)) | (~(((v56 ^ ((int)((unsigned int)((int)((unsigned int)v51 >> 2)) >> 1))) | (-(v56 ^ ((int)((unsigned int)((int)((unsigned int)v51 >> 2)) >> 1))))) >> 31))) & 104)))));
  v49->timer = v289;
  int * v59 = v49->cache_vals;
  bool v290 = !(((~(((v53 ^ ((int)((unsigned int)((int)((unsigned int)v51 >> 2)) >> 1))) | (-(v53 ^ ((int)((unsigned int)((int)((unsigned int)v51 >> 2)) >> 1))))) >> 31)) | (~(((v54 ^ ((int)((unsigned int)((int)((unsigned int)v51 >> 2)) >> 1))) | (-(v54 ^ ((int)((unsigned int)((int)((unsigned int)v51 >> 2)) >> 1))))) >> 31))) == 0);
  int v152;
  if (v290) {
    int * v60 = v49->cache_age;
    int v292 = ((((int)((unsigned int)((int)((unsigned int)v51 >> 2)) >> 1)) & 1) * 2) + ((~(((v54 ^ ((int)((unsigned int)((int)((unsigned int)v51 >> 2)) >> 1))) | (-(v54 ^ ((int)((unsigned int)((int)((unsigned int)v51 >> 2)) >> 1))))) >> 31)) & 1);
    int v61 = v60[v292];
    int v62 = v60[v285];
    int v293 = v62 + ((int)((unsigned int)(v62 - v61) >> 31));
    v60[v285] = v293;
    int * v64 = v49->cache_age;
    int v65 = v64[v286];
    int v295 = v65 + ((int)((unsigned int)(v65 - v61) >> 31));
    v64[v286] = v295;
    int * v67 = v49->cache_age;
    v67[v292] = 0;
    v152 = v292;
  } else {
    int * v70 = v49->cache_age;
    int v299 = (((int)((unsigned int)((int)((unsigned int)v51 >> 2)) >> 1)) & 1) * 2;
    int v71 = v70[v299];
    int * v72 = v49->cache_tags;
    int v73 = v72[v299];
    int v74 = v70[v286];
    int v75 = v72[v286];
    bool v301 = !(((~(((v55 ^ ((int)((unsigned int)((int)((unsigned int)v51 >> 2)) >> 1))) | (-(v55 ^ ((int)((unsigned int)((int)((unsigned int)v51 >> 2)) >> 1))))) >> 31)) | (~(((v56 ^ ((int)((unsigned int)((int)((unsigned int)v51 >> 2)) >> 1))) | (-(v56 ^ ((int)((unsigned int)((int)((unsigned int)v51 >> 2)) >> 1))))) >> 31))) == 0);
    int v129;
    if (v301) {
      int * v76 = v49->cache_age;
      int v303 = (4 + ((((int)((unsigned int)((int)((unsigned int)v51 >> 2)) >> 1)) & 3) * 2)) + ((~(((v56 ^ ((int)((unsigned int)((int)((unsigned int)v51 >> 2)) >> 1))) | (-(v56 ^ ((int)((unsigned int)((int)((unsigned int)v51 >> 2)) >> 1))))) >> 31)) & 1);
      int v77 = v76[v303];
      int v78 = v76[v287];
      int v304 = v78 + ((int)((unsigned int)(v78 - v77) >> 31));
      v76[v287] = v304;
      int * v80 = v49->cache_age;
      int v81 = v80[v288];
      int v306 = v81 + ((int)((unsigned int)(v81 - v77) >> 31));
      v80[v288] = v306;
      int * v83 = v49->cache_age;
      v83[v303] = 0;
      v129 = v303;
    } else {
      int * v86 = v49->cache_age;
      int v310 = 4 + ((((int)((unsigned int)((int)((unsigned int)v51 >> 2)) >> 1)) & 3) * 2);
      int v87 = v86[v310];
      int * v88 = v49->cache_tags;
      int v89 = v88[v310];
      int v90 = v86[v288];
      int v91 = v88[v288];
      int * v92 = v49->cache_dirty;
      int v313 = (4 + ((((int)((unsigned int)((int)((unsigned int)v51 >> 2)) >> 1)) & 3) * 2)) + ((((v87 + ((~(((v89 ^ -1) | (-(v89 ^ -1))) >> 31)) & 2)) - (v90 + ((~(((v91 ^ -1) | (-(v91 ^ -1))) >> 31)) & 2))) >> 31) & 1);
      int v93 = v92[v313];
      bool v314 = !(v93 == 0);
      if (v314) {
        int * v94 = v49->cache_tags;
        int v95 = v94[v313];
        int * v96 = v49->cache_vals;
        int v317 = ((4 + ((((int)((unsigned int)((int)((unsigned int)v51 >> 2)) >> 1)) & 3) * 2)) + ((((v87 + ((~(((v89 ^ -1) | (-(v89 ^ -1))) >> 31)) & 2)) - (v90 + ((~(((v91 ^ -1) | (-(v91 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
        int v97 = v96[v317];
        int v318 = (((4 + ((((int)((unsigned int)((int)((unsigned int)v51 >> 2)) >> 1)) & 3) * 2)) + ((((v87 + ((~(((v89 ^ -1) | (-(v89 ^ -1))) >> 31)) & 2)) - (v90 + ((~(((v91 ^ -1) | (-(v91 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
        int v98 = v96[v318];
        int * v99 = v49->mem;
        int v320 = v95 * 2;
        v99[v320] = v97;
        int * v101 = v49->mem;
        int v323 = (v95 * 2) + 1;
        v101[v323] = v98;
        ;
      } else {
        ;
      }
      int * v106 = v49->mem;
      int v328 = ((int)((unsigned int)((int)((unsigned int)v51 >> 2)) >> 1)) * 2;
      int v107 = v106[v328];
      int v329 = (((int)((unsigned int)((int)((unsigned int)v51 >> 2)) >> 1)) * 2) + 1;
      int v108 = v106[v329];
      int * v109 = v49->cache_vals;
      int v331 = ((4 + ((((int)((unsigned int)((int)((unsigned int)v51 >> 2)) >> 1)) & 3) * 2)) + ((((v87 + ((~(((v89 ^ -1) | (-(v89 ^ -1))) >> 31)) & 2)) - (v90 + ((~(((v91 ^ -1) | (-(v91 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
      v109[v331] = v107;
      int * v111 = v49->cache_vals;
      int v334 = (((4 + ((((int)((unsigned int)((int)((unsigned int)v51 >> 2)) >> 1)) & 3) * 2)) + ((((v87 + ((~(((v89 ^ -1) | (-(v89 ^ -1))) >> 31)) & 2)) - (v90 + ((~(((v91 ^ -1) | (-(v91 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
      v111[v334] = v108;
      int * v113 = v49->cache_tags;
      int v337 = (int)((unsigned int)((int)((unsigned int)v51 >> 2)) >> 1);
      v113[v313] = v337;
      int * v115 = v49->cache_dirty;
      v115[v313] = 0;
      int * v117 = v49->cache_age;
      v117[v313] = 1;
      int * v119 = v49->cache_age;
      int v120 = v119[v313];
      int v121 = v119[v287];
      int v343 = v121 + ((int)((unsigned int)(v121 - v120) >> 31));
      v119[v287] = v343;
      int * v123 = v49->cache_age;
      int v124 = v123[v288];
      int v345 = v124 + ((int)((unsigned int)(v124 - v120) >> 31));
      v123[v288] = v345;
      int * v126 = v49->cache_age;
      v126[v313] = 0;
      v129 = v313;
    }
    int * v130 = v49->cache_vals;
    int v348 = v129 * 2;
    int v131 = v130[v348];
    int v349 = (v129 * 2) + 1;
    int v132 = v130[v349];
    int v350 = (((((int)((unsigned int)((int)((unsigned int)v51 >> 2)) >> 1)) & 1) * 2) + ((((v71 + ((~(((v73 ^ -1) | (-(v73 ^ -1))) >> 31)) & 2)) - (v74 + ((~(((v75 ^ -1) | (-(v75 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
    v130[v350] = v131;
    int * v134 = v49->cache_vals;
    int v353 = ((((((int)((unsigned int)((int)((unsigned int)v51 >> 2)) >> 1)) & 1) * 2) + ((((v71 + ((~(((v73 ^ -1) | (-(v73 ^ -1))) >> 31)) & 2)) - (v74 + ((~(((v75 ^ -1) | (-(v75 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
    v134[v353] = v132;
    int * v136 = v49->cache_tags;
    int v356 = ((((int)((unsigned int)((int)((unsigned int)v51 >> 2)) >> 1)) & 1) * 2) + ((((v71 + ((~(((v73 ^ -1) | (-(v73 ^ -1))) >> 31)) & 2)) - (v74 + ((~(((v75 ^ -1) | (-(v75 ^ -1))) >> 31)) & 2))) >> 31) & 1);
    int v357 = (int)((unsigned int)((int)((unsigned int)v51 >> 2)) >> 1);
    v136[v356] = v357;
    int * v138 = v49->cache_dirty;
    v138[v356] = 0;
    int * v140 = v49->cache_age;
    v140[v356] = 1;
    int * v142 = v49->cache_age;
    int v143 = v142[v356];
    int v144 = v142[v285];
    int v363 = v144 + ((int)((unsigned int)(v144 - v143) >> 31));
    v142[v285] = v363;
    int * v146 = v49->cache_age;
    int v147 = v146[v286];
    int v365 = v147 + ((int)((unsigned int)(v147 - v143) >> 31));
    v146[v286] = v365;
    int * v149 = v49->cache_age;
    v149[v356] = 0;
    v152 = v356;
  }
  int v368 = (v152 * 2) + (((int)((unsigned int)v51 >> 2)) & 1);
  int v153 = v59[v368];
  int * v154 = v49->regs;
  v154[11] = v153;
  struct StateT * v156 = v26->b;
  int * v157 = v156->regs;
  int v158 = v157[10];
  int * v159 = v156->cache_tags;
  int v374 = (((int)((unsigned int)((int)((unsigned int)v158 >> 2)) >> 1)) & 1) * 2;
  int v160 = v159[v374];
  int v375 = ((((int)((unsigned int)((int)((unsigned int)v158 >> 2)) >> 1)) & 1) * 2) + 1;
  int v161 = v159[v375];
  int v376 = 4 + ((((int)((unsigned int)((int)((unsigned int)v158 >> 2)) >> 1)) & 3) * 2);
  int v162 = v159[v376];
  int v377 = (4 + ((((int)((unsigned int)((int)((unsigned int)v158 >> 2)) >> 1)) & 3) * 2)) + 1;
  int v163 = v159[v377];
  int v164 = v156->timer;
  int v378 = v164 + ((100 ^ (((~(((v162 ^ ((int)((unsigned int)((int)((unsigned int)v158 >> 2)) >> 1))) | (-(v162 ^ ((int)((unsigned int)((int)((unsigned int)v158 >> 2)) >> 1))))) >> 31)) | (~(((v163 ^ ((int)((unsigned int)((int)((unsigned int)v158 >> 2)) >> 1))) | (-(v163 ^ ((int)((unsigned int)((int)((unsigned int)v158 >> 2)) >> 1))))) >> 31))) & 104)) ^ (((~(((v160 ^ ((int)((unsigned int)((int)((unsigned int)v158 >> 2)) >> 1))) | (-(v160 ^ ((int)((unsigned int)((int)((unsigned int)v158 >> 2)) >> 1))))) >> 31)) | (~(((v161 ^ ((int)((unsigned int)((int)((unsigned int)v158 >> 2)) >> 1))) | (-(v161 ^ ((int)((unsigned int)((int)((unsigned int)v158 >> 2)) >> 1))))) >> 31))) & (1 ^ (100 ^ (((~(((v162 ^ ((int)((unsigned int)((int)((unsigned int)v158 >> 2)) >> 1))) | (-(v162 ^ ((int)((unsigned int)((int)((unsigned int)v158 >> 2)) >> 1))))) >> 31)) | (~(((v163 ^ ((int)((unsigned int)((int)((unsigned int)v158 >> 2)) >> 1))) | (-(v163 ^ ((int)((unsigned int)((int)((unsigned int)v158 >> 2)) >> 1))))) >> 31))) & 104)))));
  v156->timer = v378;
  int * v166 = v156->cache_vals;
  bool v379 = !(((~(((v160 ^ ((int)((unsigned int)((int)((unsigned int)v158 >> 2)) >> 1))) | (-(v160 ^ ((int)((unsigned int)((int)((unsigned int)v158 >> 2)) >> 1))))) >> 31)) | (~(((v161 ^ ((int)((unsigned int)((int)((unsigned int)v158 >> 2)) >> 1))) | (-(v161 ^ ((int)((unsigned int)((int)((unsigned int)v158 >> 2)) >> 1))))) >> 31))) == 0);
  int v259;
  if (v379) {
    int * v167 = v156->cache_age;
    int v381 = ((((int)((unsigned int)((int)((unsigned int)v158 >> 2)) >> 1)) & 1) * 2) + ((~(((v161 ^ ((int)((unsigned int)((int)((unsigned int)v158 >> 2)) >> 1))) | (-(v161 ^ ((int)((unsigned int)((int)((unsigned int)v158 >> 2)) >> 1))))) >> 31)) & 1);
    int v168 = v167[v381];
    int v169 = v167[v374];
    int v382 = v169 + ((int)((unsigned int)(v169 - v168) >> 31));
    v167[v374] = v382;
    int * v171 = v156->cache_age;
    int v172 = v171[v375];
    int v384 = v172 + ((int)((unsigned int)(v172 - v168) >> 31));
    v171[v375] = v384;
    int * v174 = v156->cache_age;
    v174[v381] = 0;
    v259 = v381;
  } else {
    int * v177 = v156->cache_age;
    int v388 = (((int)((unsigned int)((int)((unsigned int)v158 >> 2)) >> 1)) & 1) * 2;
    int v178 = v177[v388];
    int * v179 = v156->cache_tags;
    int v180 = v179[v388];
    int v181 = v177[v375];
    int v182 = v179[v375];
    bool v390 = !(((~(((v162 ^ ((int)((unsigned int)((int)((unsigned int)v158 >> 2)) >> 1))) | (-(v162 ^ ((int)((unsigned int)((int)((unsigned int)v158 >> 2)) >> 1))))) >> 31)) | (~(((v163 ^ ((int)((unsigned int)((int)((unsigned int)v158 >> 2)) >> 1))) | (-(v163 ^ ((int)((unsigned int)((int)((unsigned int)v158 >> 2)) >> 1))))) >> 31))) == 0);
    int v236;
    if (v390) {
      int * v183 = v156->cache_age;
      int v392 = (4 + ((((int)((unsigned int)((int)((unsigned int)v158 >> 2)) >> 1)) & 3) * 2)) + ((~(((v163 ^ ((int)((unsigned int)((int)((unsigned int)v158 >> 2)) >> 1))) | (-(v163 ^ ((int)((unsigned int)((int)((unsigned int)v158 >> 2)) >> 1))))) >> 31)) & 1);
      int v184 = v183[v392];
      int v185 = v183[v376];
      int v393 = v185 + ((int)((unsigned int)(v185 - v184) >> 31));
      v183[v376] = v393;
      int * v187 = v156->cache_age;
      int v188 = v187[v377];
      int v395 = v188 + ((int)((unsigned int)(v188 - v184) >> 31));
      v187[v377] = v395;
      int * v190 = v156->cache_age;
      v190[v392] = 0;
      v236 = v392;
    } else {
      int * v193 = v156->cache_age;
      int v399 = 4 + ((((int)((unsigned int)((int)((unsigned int)v158 >> 2)) >> 1)) & 3) * 2);
      int v194 = v193[v399];
      int * v195 = v156->cache_tags;
      int v196 = v195[v399];
      int v197 = v193[v377];
      int v198 = v195[v377];
      int * v199 = v156->cache_dirty;
      int v402 = (4 + ((((int)((unsigned int)((int)((unsigned int)v158 >> 2)) >> 1)) & 3) * 2)) + ((((v194 + ((~(((v196 ^ -1) | (-(v196 ^ -1))) >> 31)) & 2)) - (v197 + ((~(((v198 ^ -1) | (-(v198 ^ -1))) >> 31)) & 2))) >> 31) & 1);
      int v200 = v199[v402];
      bool v403 = !(v200 == 0);
      if (v403) {
        int * v201 = v156->cache_tags;
        int v202 = v201[v402];
        int * v203 = v156->cache_vals;
        int v406 = ((4 + ((((int)((unsigned int)((int)((unsigned int)v158 >> 2)) >> 1)) & 3) * 2)) + ((((v194 + ((~(((v196 ^ -1) | (-(v196 ^ -1))) >> 31)) & 2)) - (v197 + ((~(((v198 ^ -1) | (-(v198 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
        int v204 = v203[v406];
        int v407 = (((4 + ((((int)((unsigned int)((int)((unsigned int)v158 >> 2)) >> 1)) & 3) * 2)) + ((((v194 + ((~(((v196 ^ -1) | (-(v196 ^ -1))) >> 31)) & 2)) - (v197 + ((~(((v198 ^ -1) | (-(v198 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
        int v205 = v203[v407];
        int * v206 = v156->mem;
        int v409 = v202 * 2;
        v206[v409] = v204;
        int * v208 = v156->mem;
        int v412 = (v202 * 2) + 1;
        v208[v412] = v205;
        ;
      } else {
        ;
      }
      int * v213 = v156->mem;
      int v417 = ((int)((unsigned int)((int)((unsigned int)v158 >> 2)) >> 1)) * 2;
      int v214 = v213[v417];
      int v418 = (((int)((unsigned int)((int)((unsigned int)v158 >> 2)) >> 1)) * 2) + 1;
      int v215 = v213[v418];
      int * v216 = v156->cache_vals;
      int v420 = ((4 + ((((int)((unsigned int)((int)((unsigned int)v158 >> 2)) >> 1)) & 3) * 2)) + ((((v194 + ((~(((v196 ^ -1) | (-(v196 ^ -1))) >> 31)) & 2)) - (v197 + ((~(((v198 ^ -1) | (-(v198 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
      v216[v420] = v214;
      int * v218 = v156->cache_vals;
      int v423 = (((4 + ((((int)((unsigned int)((int)((unsigned int)v158 >> 2)) >> 1)) & 3) * 2)) + ((((v194 + ((~(((v196 ^ -1) | (-(v196 ^ -1))) >> 31)) & 2)) - (v197 + ((~(((v198 ^ -1) | (-(v198 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
      v218[v423] = v215;
      int * v220 = v156->cache_tags;
      int v426 = (int)((unsigned int)((int)((unsigned int)v158 >> 2)) >> 1);
      v220[v402] = v426;
      int * v222 = v156->cache_dirty;
      v222[v402] = 0;
      int * v224 = v156->cache_age;
      v224[v402] = 1;
      int * v226 = v156->cache_age;
      int v227 = v226[v402];
      int v228 = v226[v376];
      int v432 = v228 + ((int)((unsigned int)(v228 - v227) >> 31));
      v226[v376] = v432;
      int * v230 = v156->cache_age;
      int v231 = v230[v377];
      int v434 = v231 + ((int)((unsigned int)(v231 - v227) >> 31));
      v230[v377] = v434;
      int * v233 = v156->cache_age;
      v233[v402] = 0;
      v236 = v402;
    }
    int * v237 = v156->cache_vals;
    int v437 = v236 * 2;
    int v238 = v237[v437];
    int v438 = (v236 * 2) + 1;
    int v239 = v237[v438];
    int v439 = (((((int)((unsigned int)((int)((unsigned int)v158 >> 2)) >> 1)) & 1) * 2) + ((((v178 + ((~(((v180 ^ -1) | (-(v180 ^ -1))) >> 31)) & 2)) - (v181 + ((~(((v182 ^ -1) | (-(v182 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
    v237[v439] = v238;
    int * v241 = v156->cache_vals;
    int v442 = ((((((int)((unsigned int)((int)((unsigned int)v158 >> 2)) >> 1)) & 1) * 2) + ((((v178 + ((~(((v180 ^ -1) | (-(v180 ^ -1))) >> 31)) & 2)) - (v181 + ((~(((v182 ^ -1) | (-(v182 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
    v241[v442] = v239;
    int * v243 = v156->cache_tags;
    int v445 = ((((int)((unsigned int)((int)((unsigned int)v158 >> 2)) >> 1)) & 1) * 2) + ((((v178 + ((~(((v180 ^ -1) | (-(v180 ^ -1))) >> 31)) & 2)) - (v181 + ((~(((v182 ^ -1) | (-(v182 ^ -1))) >> 31)) & 2))) >> 31) & 1);
    int v446 = (int)((unsigned int)((int)((unsigned int)v158 >> 2)) >> 1);
    v243[v445] = v446;
    int * v245 = v156->cache_dirty;
    v245[v445] = 0;
    int * v247 = v156->cache_age;
    v247[v445] = 1;
    int * v249 = v156->cache_age;
    int v250 = v249[v445];
    int v251 = v249[v374];
    int v452 = v251 + ((int)((unsigned int)(v251 - v250) >> 31));
    v249[v374] = v452;
    int * v253 = v156->cache_age;
    int v254 = v253[v375];
    int v454 = v254 + ((int)((unsigned int)(v254 - v250) >> 31));
    v253[v375] = v454;
    int * v256 = v156->cache_age;
    v256[v445] = 0;
    v259 = v445;
  }
  int v457 = (v259 * 2) + (((int)((unsigned int)v158 >> 2)) & 1);
  int v260 = v166[v457];
  int * v261 = v156->regs;
  v261[11] = v260;
  struct StateT2 * v263 = slot_2(v26);
  return v263;
}

struct StateT2 * slot_4(struct StateT2 * v937) {
  struct StateT * v938 = v937->a;
  int v939 = v938->timer;
  struct StateT * v940 = v937->b;
  int v941 = v940->timer;
  bool v980 = v939 == v941;
  squared_assert(v980);
  squared_assume(v980);
  struct StateT * v944 = v937->a;
  int * v945 = v944->regs;
  int v946 = v945[10];
  struct StateT * v947 = v937->b;
  int * v948 = v947->regs;
  int v949 = v948[10];
  bool v986 = (v946 == 0) == (v949 == 0);
  squared_diverged(v986);
  squared_assume(v986);
  bool v987 = v946 == 0;
  struct StateT2 * v976;
  if (v987) {
    struct StateT * v952 = v937->a;
    int v953 = v952->timer;
    int v989 = v953 + 15;
    v952->timer = v989;
    int * v955 = v952->saved_regs;
    int v956 = v955[11];
    int * v957 = v952->regs;
    v957[11] = v956;
    int * v959 = v952->saved_regs;
    int v960 = v959[12];
    int * v961 = v952->regs;
    v961[12] = v960;
    struct StateT * v963 = v937->b;
    int v964 = v963->timer;
    int v999 = v964 + 15;
    v963->timer = v999;
    int * v966 = v963->saved_regs;
    int v967 = v966[11];
    int * v968 = v963->regs;
    v968[11] = v967;
    int * v970 = v963->saved_regs;
    int v971 = v970[12];
    int * v972 = v963->regs;
    v972[12] = v971;
    v976 = v937;
  } else {
    v976 = v937;
  }
  return v976;
}

struct StateT2 * slot_2(struct StateT2 * v462) {
  struct StateT * v463 = v462->a;
  int v464 = v463->timer;
  struct StateT * v465 = v462->b;
  int v466 = v465->timer;
  bool v487 = v464 == v466;
  squared_assert(v487);
  squared_assume(v487);
  struct StateT * v469 = v462->a;
  int v470 = v469->timer;
  int v489 = v470 + 1;
  v469->timer = v489;
  struct StateT * v472 = v462->b;
  int v473 = v472->timer;
  int v491 = v473 + 1;
  v472->timer = v491;
  struct StateT * v475 = v462->a;
  int * v476 = v475->regs;
  int v477 = v476[11];
  int v495 = v477 << 2;
  v476[11] = v495;
  struct StateT * v479 = v462->b;
  int * v480 = v479->regs;
  int v481 = v480[11];
  int v498 = v481 << 2;
  v480[11] = v498;
  struct StateT2 * v483 = slot_3(v462);
  return v483;
}

struct StateT2 * slot_3(struct StateT2 * v501) {
  struct StateT * v502 = v501->a;
  int v503 = v502->timer;
  struct StateT * v504 = v501->b;
  int v505 = v504->timer;
  bool v742 = v503 == v505;
  squared_assert(v742);
  squared_assume(v742);
  struct StateT * v508 = v501->a;
  int * v509 = v508->saved_regs;
  int * v510 = v508->regs;
  int v511 = v510[12];
  v509[12] = v511;
  struct StateT * v513 = v501->b;
  int * v514 = v513->saved_regs;
  int * v515 = v513->regs;
  int v516 = v515[12];
  v514[12] = v516;
  struct StateT * v518 = v501->a;
  int v519 = v518->timer;
  int v753 = v519 + 1;
  v518->timer = v753;
  struct StateT * v521 = v501->b;
  int v522 = v521->timer;
  int v755 = v522 + 1;
  v521->timer = v755;
  struct StateT * v524 = v501->a;
  int * v525 = v524->regs;
  int v526 = v525[11];
  int * v527 = v524->cache_tags;
  int v760 = (((int)((unsigned int)((int)((unsigned int)(v526 + 16) >> 2)) >> 1)) & 1) * 2;
  int v528 = v527[v760];
  int v761 = ((((int)((unsigned int)((int)((unsigned int)(v526 + 16) >> 2)) >> 1)) & 1) * 2) + 1;
  int v529 = v527[v761];
  int v762 = 4 + ((((int)((unsigned int)((int)((unsigned int)(v526 + 16) >> 2)) >> 1)) & 3) * 2);
  int v530 = v527[v762];
  int v763 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v526 + 16) >> 2)) >> 1)) & 3) * 2)) + 1;
  int v531 = v527[v763];
  int v532 = v524->timer;
  int v764 = v532 + ((100 ^ (((~(((v530 ^ ((int)((unsigned int)((int)((unsigned int)(v526 + 16) >> 2)) >> 1))) | (-(v530 ^ ((int)((unsigned int)((int)((unsigned int)(v526 + 16) >> 2)) >> 1))))) >> 31)) | (~(((v531 ^ ((int)((unsigned int)((int)((unsigned int)(v526 + 16) >> 2)) >> 1))) | (-(v531 ^ ((int)((unsigned int)((int)((unsigned int)(v526 + 16) >> 2)) >> 1))))) >> 31))) & 104)) ^ (((~(((v528 ^ ((int)((unsigned int)((int)((unsigned int)(v526 + 16) >> 2)) >> 1))) | (-(v528 ^ ((int)((unsigned int)((int)((unsigned int)(v526 + 16) >> 2)) >> 1))))) >> 31)) | (~(((v529 ^ ((int)((unsigned int)((int)((unsigned int)(v526 + 16) >> 2)) >> 1))) | (-(v529 ^ ((int)((unsigned int)((int)((unsigned int)(v526 + 16) >> 2)) >> 1))))) >> 31))) & (1 ^ (100 ^ (((~(((v530 ^ ((int)((unsigned int)((int)((unsigned int)(v526 + 16) >> 2)) >> 1))) | (-(v530 ^ ((int)((unsigned int)((int)((unsigned int)(v526 + 16) >> 2)) >> 1))))) >> 31)) | (~(((v531 ^ ((int)((unsigned int)((int)((unsigned int)(v526 + 16) >> 2)) >> 1))) | (-(v531 ^ ((int)((unsigned int)((int)((unsigned int)(v526 + 16) >> 2)) >> 1))))) >> 31))) & 104)))));
  v524->timer = v764;
  int * v534 = v524->cache_vals;
  bool v765 = !(((~(((v528 ^ ((int)((unsigned int)((int)((unsigned int)(v526 + 16) >> 2)) >> 1))) | (-(v528 ^ ((int)((unsigned int)((int)((unsigned int)(v526 + 16) >> 2)) >> 1))))) >> 31)) | (~(((v529 ^ ((int)((unsigned int)((int)((unsigned int)(v526 + 16) >> 2)) >> 1))) | (-(v529 ^ ((int)((unsigned int)((int)((unsigned int)(v526 + 16) >> 2)) >> 1))))) >> 31))) == 0);
  int v627;
  if (v765) {
    int * v535 = v524->cache_age;
    int v767 = ((((int)((unsigned int)((int)((unsigned int)(v526 + 16) >> 2)) >> 1)) & 1) * 2) + ((~(((v529 ^ ((int)((unsigned int)((int)((unsigned int)(v526 + 16) >> 2)) >> 1))) | (-(v529 ^ ((int)((unsigned int)((int)((unsigned int)(v526 + 16) >> 2)) >> 1))))) >> 31)) & 1);
    int v536 = v535[v767];
    int v537 = v535[v760];
    int v768 = v537 + ((int)((unsigned int)(v537 - v536) >> 31));
    v535[v760] = v768;
    int * v539 = v524->cache_age;
    int v540 = v539[v761];
    int v770 = v540 + ((int)((unsigned int)(v540 - v536) >> 31));
    v539[v761] = v770;
    int * v542 = v524->cache_age;
    v542[v767] = 0;
    v627 = v767;
  } else {
    int * v545 = v524->cache_age;
    int v774 = (((int)((unsigned int)((int)((unsigned int)(v526 + 16) >> 2)) >> 1)) & 1) * 2;
    int v546 = v545[v774];
    int * v547 = v524->cache_tags;
    int v548 = v547[v774];
    int v549 = v545[v761];
    int v550 = v547[v761];
    bool v776 = !(((~(((v530 ^ ((int)((unsigned int)((int)((unsigned int)(v526 + 16) >> 2)) >> 1))) | (-(v530 ^ ((int)((unsigned int)((int)((unsigned int)(v526 + 16) >> 2)) >> 1))))) >> 31)) | (~(((v531 ^ ((int)((unsigned int)((int)((unsigned int)(v526 + 16) >> 2)) >> 1))) | (-(v531 ^ ((int)((unsigned int)((int)((unsigned int)(v526 + 16) >> 2)) >> 1))))) >> 31))) == 0);
    int v604;
    if (v776) {
      int * v551 = v524->cache_age;
      int v778 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v526 + 16) >> 2)) >> 1)) & 3) * 2)) + ((~(((v531 ^ ((int)((unsigned int)((int)((unsigned int)(v526 + 16) >> 2)) >> 1))) | (-(v531 ^ ((int)((unsigned int)((int)((unsigned int)(v526 + 16) >> 2)) >> 1))))) >> 31)) & 1);
      int v552 = v551[v778];
      int v553 = v551[v762];
      int v779 = v553 + ((int)((unsigned int)(v553 - v552) >> 31));
      v551[v762] = v779;
      int * v555 = v524->cache_age;
      int v556 = v555[v763];
      int v781 = v556 + ((int)((unsigned int)(v556 - v552) >> 31));
      v555[v763] = v781;
      int * v558 = v524->cache_age;
      v558[v778] = 0;
      v604 = v778;
    } else {
      int * v561 = v524->cache_age;
      int v785 = 4 + ((((int)((unsigned int)((int)((unsigned int)(v526 + 16) >> 2)) >> 1)) & 3) * 2);
      int v562 = v561[v785];
      int * v563 = v524->cache_tags;
      int v564 = v563[v785];
      int v565 = v561[v763];
      int v566 = v563[v763];
      int * v567 = v524->cache_dirty;
      int v788 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v526 + 16) >> 2)) >> 1)) & 3) * 2)) + ((((v562 + ((~(((v564 ^ -1) | (-(v564 ^ -1))) >> 31)) & 2)) - (v565 + ((~(((v566 ^ -1) | (-(v566 ^ -1))) >> 31)) & 2))) >> 31) & 1);
      int v568 = v567[v788];
      bool v789 = !(v568 == 0);
      if (v789) {
        int * v569 = v524->cache_tags;
        int v570 = v569[v788];
        int * v571 = v524->cache_vals;
        int v792 = ((4 + ((((int)((unsigned int)((int)((unsigned int)(v526 + 16) >> 2)) >> 1)) & 3) * 2)) + ((((v562 + ((~(((v564 ^ -1) | (-(v564 ^ -1))) >> 31)) & 2)) - (v565 + ((~(((v566 ^ -1) | (-(v566 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
        int v572 = v571[v792];
        int v793 = (((4 + ((((int)((unsigned int)((int)((unsigned int)(v526 + 16) >> 2)) >> 1)) & 3) * 2)) + ((((v562 + ((~(((v564 ^ -1) | (-(v564 ^ -1))) >> 31)) & 2)) - (v565 + ((~(((v566 ^ -1) | (-(v566 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
        int v573 = v571[v793];
        int * v574 = v524->mem;
        int v795 = v570 * 2;
        v574[v795] = v572;
        int * v576 = v524->mem;
        int v798 = (v570 * 2) + 1;
        v576[v798] = v573;
        ;
      } else {
        ;
      }
      int * v581 = v524->mem;
      int v803 = ((int)((unsigned int)((int)((unsigned int)(v526 + 16) >> 2)) >> 1)) * 2;
      int v582 = v581[v803];
      int v804 = (((int)((unsigned int)((int)((unsigned int)(v526 + 16) >> 2)) >> 1)) * 2) + 1;
      int v583 = v581[v804];
      int * v584 = v524->cache_vals;
      int v806 = ((4 + ((((int)((unsigned int)((int)((unsigned int)(v526 + 16) >> 2)) >> 1)) & 3) * 2)) + ((((v562 + ((~(((v564 ^ -1) | (-(v564 ^ -1))) >> 31)) & 2)) - (v565 + ((~(((v566 ^ -1) | (-(v566 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
      v584[v806] = v582;
      int * v586 = v524->cache_vals;
      int v809 = (((4 + ((((int)((unsigned int)((int)((unsigned int)(v526 + 16) >> 2)) >> 1)) & 3) * 2)) + ((((v562 + ((~(((v564 ^ -1) | (-(v564 ^ -1))) >> 31)) & 2)) - (v565 + ((~(((v566 ^ -1) | (-(v566 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
      v586[v809] = v583;
      int * v588 = v524->cache_tags;
      int v812 = (int)((unsigned int)((int)((unsigned int)(v526 + 16) >> 2)) >> 1);
      v588[v788] = v812;
      int * v590 = v524->cache_dirty;
      v590[v788] = 0;
      int * v592 = v524->cache_age;
      v592[v788] = 1;
      int * v594 = v524->cache_age;
      int v595 = v594[v788];
      int v596 = v594[v762];
      int v818 = v596 + ((int)((unsigned int)(v596 - v595) >> 31));
      v594[v762] = v818;
      int * v598 = v524->cache_age;
      int v599 = v598[v763];
      int v820 = v599 + ((int)((unsigned int)(v599 - v595) >> 31));
      v598[v763] = v820;
      int * v601 = v524->cache_age;
      v601[v788] = 0;
      v604 = v788;
    }
    int * v605 = v524->cache_vals;
    int v823 = v604 * 2;
    int v606 = v605[v823];
    int v824 = (v604 * 2) + 1;
    int v607 = v605[v824];
    int v825 = (((((int)((unsigned int)((int)((unsigned int)(v526 + 16) >> 2)) >> 1)) & 1) * 2) + ((((v546 + ((~(((v548 ^ -1) | (-(v548 ^ -1))) >> 31)) & 2)) - (v549 + ((~(((v550 ^ -1) | (-(v550 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
    v605[v825] = v606;
    int * v609 = v524->cache_vals;
    int v828 = ((((((int)((unsigned int)((int)((unsigned int)(v526 + 16) >> 2)) >> 1)) & 1) * 2) + ((((v546 + ((~(((v548 ^ -1) | (-(v548 ^ -1))) >> 31)) & 2)) - (v549 + ((~(((v550 ^ -1) | (-(v550 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
    v609[v828] = v607;
    int * v611 = v524->cache_tags;
    int v831 = ((((int)((unsigned int)((int)((unsigned int)(v526 + 16) >> 2)) >> 1)) & 1) * 2) + ((((v546 + ((~(((v548 ^ -1) | (-(v548 ^ -1))) >> 31)) & 2)) - (v549 + ((~(((v550 ^ -1) | (-(v550 ^ -1))) >> 31)) & 2))) >> 31) & 1);
    int v832 = (int)((unsigned int)((int)((unsigned int)(v526 + 16) >> 2)) >> 1);
    v611[v831] = v832;
    int * v613 = v524->cache_dirty;
    v613[v831] = 0;
    int * v615 = v524->cache_age;
    v615[v831] = 1;
    int * v617 = v524->cache_age;
    int v618 = v617[v831];
    int v619 = v617[v760];
    int v838 = v619 + ((int)((unsigned int)(v619 - v618) >> 31));
    v617[v760] = v838;
    int * v621 = v524->cache_age;
    int v622 = v621[v761];
    int v840 = v622 + ((int)((unsigned int)(v622 - v618) >> 31));
    v621[v761] = v840;
    int * v624 = v524->cache_age;
    v624[v831] = 0;
    v627 = v831;
  }
  int v843 = (v627 * 2) + (((int)((unsigned int)(v526 + 16) >> 2)) & 1);
  int v628 = v534[v843];
  int * v629 = v524->regs;
  v629[12] = v628;
  struct StateT * v631 = v501->b;
  int * v632 = v631->regs;
  int v633 = v632[11];
  int * v634 = v631->cache_tags;
  int v849 = (((int)((unsigned int)((int)((unsigned int)(v633 + 16) >> 2)) >> 1)) & 1) * 2;
  int v635 = v634[v849];
  int v850 = ((((int)((unsigned int)((int)((unsigned int)(v633 + 16) >> 2)) >> 1)) & 1) * 2) + 1;
  int v636 = v634[v850];
  int v851 = 4 + ((((int)((unsigned int)((int)((unsigned int)(v633 + 16) >> 2)) >> 1)) & 3) * 2);
  int v637 = v634[v851];
  int v852 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v633 + 16) >> 2)) >> 1)) & 3) * 2)) + 1;
  int v638 = v634[v852];
  int v639 = v631->timer;
  int v853 = v639 + ((100 ^ (((~(((v637 ^ ((int)((unsigned int)((int)((unsigned int)(v633 + 16) >> 2)) >> 1))) | (-(v637 ^ ((int)((unsigned int)((int)((unsigned int)(v633 + 16) >> 2)) >> 1))))) >> 31)) | (~(((v638 ^ ((int)((unsigned int)((int)((unsigned int)(v633 + 16) >> 2)) >> 1))) | (-(v638 ^ ((int)((unsigned int)((int)((unsigned int)(v633 + 16) >> 2)) >> 1))))) >> 31))) & 104)) ^ (((~(((v635 ^ ((int)((unsigned int)((int)((unsigned int)(v633 + 16) >> 2)) >> 1))) | (-(v635 ^ ((int)((unsigned int)((int)((unsigned int)(v633 + 16) >> 2)) >> 1))))) >> 31)) | (~(((v636 ^ ((int)((unsigned int)((int)((unsigned int)(v633 + 16) >> 2)) >> 1))) | (-(v636 ^ ((int)((unsigned int)((int)((unsigned int)(v633 + 16) >> 2)) >> 1))))) >> 31))) & (1 ^ (100 ^ (((~(((v637 ^ ((int)((unsigned int)((int)((unsigned int)(v633 + 16) >> 2)) >> 1))) | (-(v637 ^ ((int)((unsigned int)((int)((unsigned int)(v633 + 16) >> 2)) >> 1))))) >> 31)) | (~(((v638 ^ ((int)((unsigned int)((int)((unsigned int)(v633 + 16) >> 2)) >> 1))) | (-(v638 ^ ((int)((unsigned int)((int)((unsigned int)(v633 + 16) >> 2)) >> 1))))) >> 31))) & 104)))));
  v631->timer = v853;
  int * v641 = v631->cache_vals;
  bool v854 = !(((~(((v635 ^ ((int)((unsigned int)((int)((unsigned int)(v633 + 16) >> 2)) >> 1))) | (-(v635 ^ ((int)((unsigned int)((int)((unsigned int)(v633 + 16) >> 2)) >> 1))))) >> 31)) | (~(((v636 ^ ((int)((unsigned int)((int)((unsigned int)(v633 + 16) >> 2)) >> 1))) | (-(v636 ^ ((int)((unsigned int)((int)((unsigned int)(v633 + 16) >> 2)) >> 1))))) >> 31))) == 0);
  int v734;
  if (v854) {
    int * v642 = v631->cache_age;
    int v856 = ((((int)((unsigned int)((int)((unsigned int)(v633 + 16) >> 2)) >> 1)) & 1) * 2) + ((~(((v636 ^ ((int)((unsigned int)((int)((unsigned int)(v633 + 16) >> 2)) >> 1))) | (-(v636 ^ ((int)((unsigned int)((int)((unsigned int)(v633 + 16) >> 2)) >> 1))))) >> 31)) & 1);
    int v643 = v642[v856];
    int v644 = v642[v849];
    int v857 = v644 + ((int)((unsigned int)(v644 - v643) >> 31));
    v642[v849] = v857;
    int * v646 = v631->cache_age;
    int v647 = v646[v850];
    int v859 = v647 + ((int)((unsigned int)(v647 - v643) >> 31));
    v646[v850] = v859;
    int * v649 = v631->cache_age;
    v649[v856] = 0;
    v734 = v856;
  } else {
    int * v652 = v631->cache_age;
    int v863 = (((int)((unsigned int)((int)((unsigned int)(v633 + 16) >> 2)) >> 1)) & 1) * 2;
    int v653 = v652[v863];
    int * v654 = v631->cache_tags;
    int v655 = v654[v863];
    int v656 = v652[v850];
    int v657 = v654[v850];
    bool v865 = !(((~(((v637 ^ ((int)((unsigned int)((int)((unsigned int)(v633 + 16) >> 2)) >> 1))) | (-(v637 ^ ((int)((unsigned int)((int)((unsigned int)(v633 + 16) >> 2)) >> 1))))) >> 31)) | (~(((v638 ^ ((int)((unsigned int)((int)((unsigned int)(v633 + 16) >> 2)) >> 1))) | (-(v638 ^ ((int)((unsigned int)((int)((unsigned int)(v633 + 16) >> 2)) >> 1))))) >> 31))) == 0);
    int v711;
    if (v865) {
      int * v658 = v631->cache_age;
      int v867 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v633 + 16) >> 2)) >> 1)) & 3) * 2)) + ((~(((v638 ^ ((int)((unsigned int)((int)((unsigned int)(v633 + 16) >> 2)) >> 1))) | (-(v638 ^ ((int)((unsigned int)((int)((unsigned int)(v633 + 16) >> 2)) >> 1))))) >> 31)) & 1);
      int v659 = v658[v867];
      int v660 = v658[v851];
      int v868 = v660 + ((int)((unsigned int)(v660 - v659) >> 31));
      v658[v851] = v868;
      int * v662 = v631->cache_age;
      int v663 = v662[v852];
      int v870 = v663 + ((int)((unsigned int)(v663 - v659) >> 31));
      v662[v852] = v870;
      int * v665 = v631->cache_age;
      v665[v867] = 0;
      v711 = v867;
    } else {
      int * v668 = v631->cache_age;
      int v874 = 4 + ((((int)((unsigned int)((int)((unsigned int)(v633 + 16) >> 2)) >> 1)) & 3) * 2);
      int v669 = v668[v874];
      int * v670 = v631->cache_tags;
      int v671 = v670[v874];
      int v672 = v668[v852];
      int v673 = v670[v852];
      int * v674 = v631->cache_dirty;
      int v877 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v633 + 16) >> 2)) >> 1)) & 3) * 2)) + ((((v669 + ((~(((v671 ^ -1) | (-(v671 ^ -1))) >> 31)) & 2)) - (v672 + ((~(((v673 ^ -1) | (-(v673 ^ -1))) >> 31)) & 2))) >> 31) & 1);
      int v675 = v674[v877];
      bool v878 = !(v675 == 0);
      if (v878) {
        int * v676 = v631->cache_tags;
        int v677 = v676[v877];
        int * v678 = v631->cache_vals;
        int v881 = ((4 + ((((int)((unsigned int)((int)((unsigned int)(v633 + 16) >> 2)) >> 1)) & 3) * 2)) + ((((v669 + ((~(((v671 ^ -1) | (-(v671 ^ -1))) >> 31)) & 2)) - (v672 + ((~(((v673 ^ -1) | (-(v673 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
        int v679 = v678[v881];
        int v882 = (((4 + ((((int)((unsigned int)((int)((unsigned int)(v633 + 16) >> 2)) >> 1)) & 3) * 2)) + ((((v669 + ((~(((v671 ^ -1) | (-(v671 ^ -1))) >> 31)) & 2)) - (v672 + ((~(((v673 ^ -1) | (-(v673 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
        int v680 = v678[v882];
        int * v681 = v631->mem;
        int v884 = v677 * 2;
        v681[v884] = v679;
        int * v683 = v631->mem;
        int v887 = (v677 * 2) + 1;
        v683[v887] = v680;
        ;
      } else {
        ;
      }
      int * v688 = v631->mem;
      int v892 = ((int)((unsigned int)((int)((unsigned int)(v633 + 16) >> 2)) >> 1)) * 2;
      int v689 = v688[v892];
      int v893 = (((int)((unsigned int)((int)((unsigned int)(v633 + 16) >> 2)) >> 1)) * 2) + 1;
      int v690 = v688[v893];
      int * v691 = v631->cache_vals;
      int v895 = ((4 + ((((int)((unsigned int)((int)((unsigned int)(v633 + 16) >> 2)) >> 1)) & 3) * 2)) + ((((v669 + ((~(((v671 ^ -1) | (-(v671 ^ -1))) >> 31)) & 2)) - (v672 + ((~(((v673 ^ -1) | (-(v673 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
      v691[v895] = v689;
      int * v693 = v631->cache_vals;
      int v898 = (((4 + ((((int)((unsigned int)((int)((unsigned int)(v633 + 16) >> 2)) >> 1)) & 3) * 2)) + ((((v669 + ((~(((v671 ^ -1) | (-(v671 ^ -1))) >> 31)) & 2)) - (v672 + ((~(((v673 ^ -1) | (-(v673 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
      v693[v898] = v690;
      int * v695 = v631->cache_tags;
      int v901 = (int)((unsigned int)((int)((unsigned int)(v633 + 16) >> 2)) >> 1);
      v695[v877] = v901;
      int * v697 = v631->cache_dirty;
      v697[v877] = 0;
      int * v699 = v631->cache_age;
      v699[v877] = 1;
      int * v701 = v631->cache_age;
      int v702 = v701[v877];
      int v703 = v701[v851];
      int v907 = v703 + ((int)((unsigned int)(v703 - v702) >> 31));
      v701[v851] = v907;
      int * v705 = v631->cache_age;
      int v706 = v705[v852];
      int v909 = v706 + ((int)((unsigned int)(v706 - v702) >> 31));
      v705[v852] = v909;
      int * v708 = v631->cache_age;
      v708[v877] = 0;
      v711 = v877;
    }
    int * v712 = v631->cache_vals;
    int v912 = v711 * 2;
    int v713 = v712[v912];
    int v913 = (v711 * 2) + 1;
    int v714 = v712[v913];
    int v914 = (((((int)((unsigned int)((int)((unsigned int)(v633 + 16) >> 2)) >> 1)) & 1) * 2) + ((((v653 + ((~(((v655 ^ -1) | (-(v655 ^ -1))) >> 31)) & 2)) - (v656 + ((~(((v657 ^ -1) | (-(v657 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
    v712[v914] = v713;
    int * v716 = v631->cache_vals;
    int v917 = ((((((int)((unsigned int)((int)((unsigned int)(v633 + 16) >> 2)) >> 1)) & 1) * 2) + ((((v653 + ((~(((v655 ^ -1) | (-(v655 ^ -1))) >> 31)) & 2)) - (v656 + ((~(((v657 ^ -1) | (-(v657 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
    v716[v917] = v714;
    int * v718 = v631->cache_tags;
    int v920 = ((((int)((unsigned int)((int)((unsigned int)(v633 + 16) >> 2)) >> 1)) & 1) * 2) + ((((v653 + ((~(((v655 ^ -1) | (-(v655 ^ -1))) >> 31)) & 2)) - (v656 + ((~(((v657 ^ -1) | (-(v657 ^ -1))) >> 31)) & 2))) >> 31) & 1);
    int v921 = (int)((unsigned int)((int)((unsigned int)(v633 + 16) >> 2)) >> 1);
    v718[v920] = v921;
    int * v720 = v631->cache_dirty;
    v720[v920] = 0;
    int * v722 = v631->cache_age;
    v722[v920] = 1;
    int * v724 = v631->cache_age;
    int v725 = v724[v920];
    int v726 = v724[v849];
    int v927 = v726 + ((int)((unsigned int)(v726 - v725) >> 31));
    v724[v849] = v927;
    int * v728 = v631->cache_age;
    int v729 = v728[v850];
    int v929 = v729 + ((int)((unsigned int)(v729 - v725) >> 31));
    v728[v850] = v929;
    int * v731 = v631->cache_age;
    v731[v920] = 0;
    v734 = v920;
  }
  int v932 = (v734 * 2) + (((int)((unsigned int)(v633 + 16) >> 2)) & 1);
  int v735 = v641[v932];
  int * v736 = v631->regs;
  v736[12] = v735;
  struct StateT2 * v738 = slot_4(v501);
  return v738;
}

struct StateT2 * slot_0(struct StateT2 * v2) {
  struct StateT * v3 = v2->a;
  int v4 = v3->timer;
  struct StateT * v5 = v2->b;
  int v6 = v5->timer;
  bool v19 = v4 == v6;
  squared_assert(v19);
  squared_assume(v19);
  struct StateT * v9 = v2->a;
  int v10 = v9->timer;
  int v21 = v10 + 1;
  v9->timer = v21;
  struct StateT * v12 = v2->b;
  int v13 = v12->timer;
  int v23 = v13 + 1;
  v12->timer = v23;
  struct StateT2 * v15 = slot_1(v2);
  return v15;
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
    s1.mem[SECRET_OFFSET+i] = secret(0, 20);
    s2.mem[SECRET_OFFSET+i] = secret(0, 20);
  }
  struct StateT2 p = { .a = &s1, .b = &s2 };
  struct StateT2 *p_ = snippet(&p);
  //@ assert untainted_timer: !\tainted(p_->a->timer==p_->b->timer);
  koika_assert(p_->a->timer==p_->b->timer, "timing leak");
  return 0;
}