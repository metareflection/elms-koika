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
  int reg_ready[32];
  int cache_tags[12];
  int cache_dirty[12];
  int cache_age[12];
  int cache_vals[24];
  int timer;
};

struct StateT * snippet(struct StateT * v0);
struct StateT * slot_0(struct StateT * v2);
struct StateT * snippet(struct StateT * v0) {
  struct StateT * v1 = slot_0(v0);
  return v1;
}

struct StateT * slot_0(struct StateT * v2) {
  int * v3 = v2->saved_regs;
  int * v4 = v2->regs;
  int v5 = v4[11];
  v3[11] = v5;
  int v7 = v2->timer;
  int v299 = v7 + 1;
  v2->timer = v299;
  int * v9 = v2->regs;
  int v10 = v9[10];
  int * v11 = v2->cache_tags;
  int v303 = (((int)((unsigned int)((int)((unsigned int)v10 >> 2)) >> 1)) & 1) * 2;
  int v12 = v11[v303];
  int * v13 = v2->cache_tags;
  int v305 = ((((int)((unsigned int)((int)((unsigned int)v10 >> 2)) >> 1)) & 1) * 2) + 1;
  int v14 = v13[v305];
  int * v15 = v2->cache_tags;
  int v307 = 4 + ((((int)((unsigned int)((int)((unsigned int)v10 >> 2)) >> 1)) & 3) * 2);
  int v16 = v15[v307];
  int * v17 = v2->cache_tags;
  int v309 = (4 + ((((int)((unsigned int)((int)((unsigned int)v10 >> 2)) >> 1)) & 3) * 2)) + 1;
  int v18 = v17[v309];
  int v19 = v2->timer;
  int v310 = v19 + ((100 ^ (((~(((v16 ^ ((int)((unsigned int)((int)((unsigned int)v10 >> 2)) >> 1))) | (-(v16 ^ ((int)((unsigned int)((int)((unsigned int)v10 >> 2)) >> 1))))) >> 31)) | (~(((v18 ^ ((int)((unsigned int)((int)((unsigned int)v10 >> 2)) >> 1))) | (-(v18 ^ ((int)((unsigned int)((int)((unsigned int)v10 >> 2)) >> 1))))) >> 31))) & 104)) ^ (((~(((v12 ^ ((int)((unsigned int)((int)((unsigned int)v10 >> 2)) >> 1))) | (-(v12 ^ ((int)((unsigned int)((int)((unsigned int)v10 >> 2)) >> 1))))) >> 31)) | (~(((v14 ^ ((int)((unsigned int)((int)((unsigned int)v10 >> 2)) >> 1))) | (-(v14 ^ ((int)((unsigned int)((int)((unsigned int)v10 >> 2)) >> 1))))) >> 31))) & (1 ^ (100 ^ (((~(((v16 ^ ((int)((unsigned int)((int)((unsigned int)v10 >> 2)) >> 1))) | (-(v16 ^ ((int)((unsigned int)((int)((unsigned int)v10 >> 2)) >> 1))))) >> 31)) | (~(((v18 ^ ((int)((unsigned int)((int)((unsigned int)v10 >> 2)) >> 1))) | (-(v18 ^ ((int)((unsigned int)((int)((unsigned int)v10 >> 2)) >> 1))))) >> 31))) & 104)))));
  v2->timer = v310;
  int * v21 = v2->cache_vals;
  bool v311 = !(((~(((v12 ^ ((int)((unsigned int)((int)((unsigned int)v10 >> 2)) >> 1))) | (-(v12 ^ ((int)((unsigned int)((int)((unsigned int)v10 >> 2)) >> 1))))) >> 31)) | (~(((v14 ^ ((int)((unsigned int)((int)((unsigned int)v10 >> 2)) >> 1))) | (-(v14 ^ ((int)((unsigned int)((int)((unsigned int)v10 >> 2)) >> 1))))) >> 31))) == 0);
  int v134;
  if (v311) {
    int * v22 = v2->cache_age;
    int v313 = ((((int)((unsigned int)((int)((unsigned int)v10 >> 2)) >> 1)) & 1) * 2) + ((~(((v14 ^ ((int)((unsigned int)((int)((unsigned int)v10 >> 2)) >> 1))) | (-(v14 ^ ((int)((unsigned int)((int)((unsigned int)v10 >> 2)) >> 1))))) >> 31)) & 1);
    int v23 = v22[v313];
    int * v24 = v2->cache_age;
    int v25 = v24[v303];
    int * v26 = v2->cache_age;
    int v316 = v25 + ((int)((unsigned int)(v25 - v23) >> 31));
    v26[v303] = v316;
    int * v28 = v2->cache_age;
    int v29 = v28[v305];
    int * v30 = v2->cache_age;
    int v319 = v29 + ((int)((unsigned int)(v29 - v23) >> 31));
    v30[v305] = v319;
    int * v32 = v2->cache_age;
    v32[v313] = 0;
    v134 = v313;
  } else {
    int * v35 = v2->cache_age;
    int v323 = (((int)((unsigned int)((int)((unsigned int)v10 >> 2)) >> 1)) & 1) * 2;
    int v36 = v35[v323];
    int * v37 = v2->cache_tags;
    int v38 = v37[v323];
    int * v39 = v2->cache_age;
    int v40 = v39[v305];
    int * v41 = v2->cache_tags;
    int v42 = v41[v305];
    bool v327 = !(((~(((v16 ^ ((int)((unsigned int)((int)((unsigned int)v10 >> 2)) >> 1))) | (-(v16 ^ ((int)((unsigned int)((int)((unsigned int)v10 >> 2)) >> 1))))) >> 31)) | (~(((v18 ^ ((int)((unsigned int)((int)((unsigned int)v10 >> 2)) >> 1))) | (-(v18 ^ ((int)((unsigned int)((int)((unsigned int)v10 >> 2)) >> 1))))) >> 31))) == 0);
    int v106;
    if (v327) {
      int * v43 = v2->cache_age;
      int v329 = (4 + ((((int)((unsigned int)((int)((unsigned int)v10 >> 2)) >> 1)) & 3) * 2)) + ((~(((v18 ^ ((int)((unsigned int)((int)((unsigned int)v10 >> 2)) >> 1))) | (-(v18 ^ ((int)((unsigned int)((int)((unsigned int)v10 >> 2)) >> 1))))) >> 31)) & 1);
      int v44 = v43[v329];
      int * v45 = v2->cache_age;
      int v46 = v45[v307];
      int * v47 = v2->cache_age;
      int v332 = v46 + ((int)((unsigned int)(v46 - v44) >> 31));
      v47[v307] = v332;
      int * v49 = v2->cache_age;
      int v50 = v49[v309];
      int * v51 = v2->cache_age;
      int v335 = v50 + ((int)((unsigned int)(v50 - v44) >> 31));
      v51[v309] = v335;
      int * v53 = v2->cache_age;
      v53[v329] = 0;
      v106 = v329;
    } else {
      int * v56 = v2->cache_age;
      int v339 = 4 + ((((int)((unsigned int)((int)((unsigned int)v10 >> 2)) >> 1)) & 3) * 2);
      int v57 = v56[v339];
      int * v58 = v2->cache_tags;
      int v59 = v58[v339];
      int * v60 = v2->cache_age;
      int v61 = v60[v309];
      int * v62 = v2->cache_tags;
      int v63 = v62[v309];
      int * v64 = v2->cache_dirty;
      int v344 = (4 + ((((int)((unsigned int)((int)((unsigned int)v10 >> 2)) >> 1)) & 3) * 2)) + ((((v57 + ((~(((v59 ^ -1) | (-(v59 ^ -1))) >> 31)) & 2)) - (v61 + ((~(((v63 ^ -1) | (-(v63 ^ -1))) >> 31)) & 2))) >> 31) & 1);
      int v65 = v64[v344];
      bool v345 = !(v65 == 0);
      if (v345) {
        int * v66 = v2->cache_tags;
        int v67 = v66[v344];
        int * v68 = v2->cache_vals;
        int v348 = ((4 + ((((int)((unsigned int)((int)((unsigned int)v10 >> 2)) >> 1)) & 3) * 2)) + ((((v57 + ((~(((v59 ^ -1) | (-(v59 ^ -1))) >> 31)) & 2)) - (v61 + ((~(((v63 ^ -1) | (-(v63 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
        int v69 = v68[v348];
        int * v70 = v2->cache_vals;
        int v350 = (((4 + ((((int)((unsigned int)((int)((unsigned int)v10 >> 2)) >> 1)) & 3) * 2)) + ((((v57 + ((~(((v59 ^ -1) | (-(v59 ^ -1))) >> 31)) & 2)) - (v61 + ((~(((v63 ^ -1) | (-(v63 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
        int v71 = v70[v350];
        int * v72 = v2->mem;
        int v352 = v67 * 2;
        v72[v352] = v69;
        int * v74 = v2->mem;
        int v355 = (v67 * 2) + 1;
        v74[v355] = v71;
        ;
      } else {
        ;
      }
      int * v79 = v2->mem;
      int v360 = ((int)((unsigned int)((int)((unsigned int)v10 >> 2)) >> 1)) * 2;
      int v80 = v79[v360];
      int * v81 = v2->mem;
      int v362 = (((int)((unsigned int)((int)((unsigned int)v10 >> 2)) >> 1)) * 2) + 1;
      int v82 = v81[v362];
      int * v83 = v2->cache_vals;
      int v364 = ((4 + ((((int)((unsigned int)((int)((unsigned int)v10 >> 2)) >> 1)) & 3) * 2)) + ((((v57 + ((~(((v59 ^ -1) | (-(v59 ^ -1))) >> 31)) & 2)) - (v61 + ((~(((v63 ^ -1) | (-(v63 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
      v83[v364] = v80;
      int * v85 = v2->cache_vals;
      int v367 = (((4 + ((((int)((unsigned int)((int)((unsigned int)v10 >> 2)) >> 1)) & 3) * 2)) + ((((v57 + ((~(((v59 ^ -1) | (-(v59 ^ -1))) >> 31)) & 2)) - (v61 + ((~(((v63 ^ -1) | (-(v63 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
      v85[v367] = v82;
      int * v87 = v2->cache_tags;
      int v370 = (int)((unsigned int)((int)((unsigned int)v10 >> 2)) >> 1);
      v87[v344] = v370;
      int * v89 = v2->cache_dirty;
      v89[v344] = 0;
      int * v91 = v2->cache_age;
      v91[v344] = 1;
      int * v93 = v2->cache_age;
      int v94 = v93[v344];
      int * v95 = v2->cache_age;
      int v96 = v95[v307];
      int * v97 = v2->cache_age;
      int v378 = v96 + ((int)((unsigned int)(v96 - v94) >> 31));
      v97[v307] = v378;
      int * v99 = v2->cache_age;
      int v100 = v99[v309];
      int * v101 = v2->cache_age;
      int v381 = v100 + ((int)((unsigned int)(v100 - v94) >> 31));
      v101[v309] = v381;
      int * v103 = v2->cache_age;
      v103[v344] = 0;
      v106 = v344;
    }
    int * v107 = v2->cache_vals;
    int v384 = v106 * 2;
    int v108 = v107[v384];
    int * v109 = v2->cache_vals;
    int v386 = (v106 * 2) + 1;
    int v110 = v109[v386];
    int * v111 = v2->cache_vals;
    int v388 = (((((int)((unsigned int)((int)((unsigned int)v10 >> 2)) >> 1)) & 1) * 2) + ((((v36 + ((~(((v38 ^ -1) | (-(v38 ^ -1))) >> 31)) & 2)) - (v40 + ((~(((v42 ^ -1) | (-(v42 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
    v111[v388] = v108;
    int * v113 = v2->cache_vals;
    int v391 = ((((((int)((unsigned int)((int)((unsigned int)v10 >> 2)) >> 1)) & 1) * 2) + ((((v36 + ((~(((v38 ^ -1) | (-(v38 ^ -1))) >> 31)) & 2)) - (v40 + ((~(((v42 ^ -1) | (-(v42 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
    v113[v391] = v110;
    int * v115 = v2->cache_tags;
    int v394 = ((((int)((unsigned int)((int)((unsigned int)v10 >> 2)) >> 1)) & 1) * 2) + ((((v36 + ((~(((v38 ^ -1) | (-(v38 ^ -1))) >> 31)) & 2)) - (v40 + ((~(((v42 ^ -1) | (-(v42 ^ -1))) >> 31)) & 2))) >> 31) & 1);
    int v395 = (int)((unsigned int)((int)((unsigned int)v10 >> 2)) >> 1);
    v115[v394] = v395;
    int * v117 = v2->cache_dirty;
    v117[v394] = 0;
    int * v119 = v2->cache_age;
    v119[v394] = 1;
    int * v121 = v2->cache_age;
    int v122 = v121[v394];
    int * v123 = v2->cache_age;
    int v124 = v123[v303];
    int * v125 = v2->cache_age;
    int v403 = v124 + ((int)((unsigned int)(v124 - v122) >> 31));
    v125[v303] = v403;
    int * v127 = v2->cache_age;
    int v128 = v127[v305];
    int * v129 = v2->cache_age;
    int v406 = v128 + ((int)((unsigned int)(v128 - v122) >> 31));
    v129[v305] = v406;
    int * v131 = v2->cache_age;
    v131[v394] = 0;
    v134 = v394;
  }
  int v409 = (v134 * 2) + (((int)((unsigned int)v10 >> 2)) & 1);
  int v135 = v21[v409];
  int * v136 = v2->regs;
  v136[11] = v135;
  int v138 = v2->timer;
  int v412 = v138 + 1;
  v2->timer = v412;
  int * v140 = v2->regs;
  int v141 = v140[11];
  int * v142 = v2->regs;
  int v415 = v141 << 2;
  v142[11] = v415;
  int * v144 = v2->saved_regs;
  int * v145 = v2->regs;
  int v146 = v145[12];
  v144[12] = v146;
  int v148 = v2->timer;
  int v420 = v148 + 1;
  v2->timer = v420;
  int * v150 = v2->regs;
  int v151 = v150[11];
  int * v152 = v2->cache_tags;
  int v423 = (((int)((unsigned int)((int)((unsigned int)(v151 + 16) >> 2)) >> 1)) & 1) * 2;
  int v153 = v152[v423];
  int * v154 = v2->cache_tags;
  int v425 = ((((int)((unsigned int)((int)((unsigned int)(v151 + 16) >> 2)) >> 1)) & 1) * 2) + 1;
  int v155 = v154[v425];
  int * v156 = v2->cache_tags;
  int v427 = 4 + ((((int)((unsigned int)((int)((unsigned int)(v151 + 16) >> 2)) >> 1)) & 3) * 2);
  int v157 = v156[v427];
  int * v158 = v2->cache_tags;
  int v429 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v151 + 16) >> 2)) >> 1)) & 3) * 2)) + 1;
  int v159 = v158[v429];
  int v160 = v2->timer;
  int v430 = v160 + ((100 ^ (((~(((v157 ^ ((int)((unsigned int)((int)((unsigned int)(v151 + 16) >> 2)) >> 1))) | (-(v157 ^ ((int)((unsigned int)((int)((unsigned int)(v151 + 16) >> 2)) >> 1))))) >> 31)) | (~(((v159 ^ ((int)((unsigned int)((int)((unsigned int)(v151 + 16) >> 2)) >> 1))) | (-(v159 ^ ((int)((unsigned int)((int)((unsigned int)(v151 + 16) >> 2)) >> 1))))) >> 31))) & 104)) ^ (((~(((v153 ^ ((int)((unsigned int)((int)((unsigned int)(v151 + 16) >> 2)) >> 1))) | (-(v153 ^ ((int)((unsigned int)((int)((unsigned int)(v151 + 16) >> 2)) >> 1))))) >> 31)) | (~(((v155 ^ ((int)((unsigned int)((int)((unsigned int)(v151 + 16) >> 2)) >> 1))) | (-(v155 ^ ((int)((unsigned int)((int)((unsigned int)(v151 + 16) >> 2)) >> 1))))) >> 31))) & (1 ^ (100 ^ (((~(((v157 ^ ((int)((unsigned int)((int)((unsigned int)(v151 + 16) >> 2)) >> 1))) | (-(v157 ^ ((int)((unsigned int)((int)((unsigned int)(v151 + 16) >> 2)) >> 1))))) >> 31)) | (~(((v159 ^ ((int)((unsigned int)((int)((unsigned int)(v151 + 16) >> 2)) >> 1))) | (-(v159 ^ ((int)((unsigned int)((int)((unsigned int)(v151 + 16) >> 2)) >> 1))))) >> 31))) & 104)))));
  v2->timer = v430;
  int * v162 = v2->cache_vals;
  bool v431 = !(((~(((v153 ^ ((int)((unsigned int)((int)((unsigned int)(v151 + 16) >> 2)) >> 1))) | (-(v153 ^ ((int)((unsigned int)((int)((unsigned int)(v151 + 16) >> 2)) >> 1))))) >> 31)) | (~(((v155 ^ ((int)((unsigned int)((int)((unsigned int)(v151 + 16) >> 2)) >> 1))) | (-(v155 ^ ((int)((unsigned int)((int)((unsigned int)(v151 + 16) >> 2)) >> 1))))) >> 31))) == 0);
  int v275;
  if (v431) {
    int * v163 = v2->cache_age;
    int v433 = ((((int)((unsigned int)((int)((unsigned int)(v151 + 16) >> 2)) >> 1)) & 1) * 2) + ((~(((v155 ^ ((int)((unsigned int)((int)((unsigned int)(v151 + 16) >> 2)) >> 1))) | (-(v155 ^ ((int)((unsigned int)((int)((unsigned int)(v151 + 16) >> 2)) >> 1))))) >> 31)) & 1);
    int v164 = v163[v433];
    int * v165 = v2->cache_age;
    int v166 = v165[v423];
    int * v167 = v2->cache_age;
    int v436 = v166 + ((int)((unsigned int)(v166 - v164) >> 31));
    v167[v423] = v436;
    int * v169 = v2->cache_age;
    int v170 = v169[v425];
    int * v171 = v2->cache_age;
    int v439 = v170 + ((int)((unsigned int)(v170 - v164) >> 31));
    v171[v425] = v439;
    int * v173 = v2->cache_age;
    v173[v433] = 0;
    v275 = v433;
  } else {
    int * v176 = v2->cache_age;
    int v443 = (((int)((unsigned int)((int)((unsigned int)(v151 + 16) >> 2)) >> 1)) & 1) * 2;
    int v177 = v176[v443];
    int * v178 = v2->cache_tags;
    int v179 = v178[v443];
    int * v180 = v2->cache_age;
    int v181 = v180[v425];
    int * v182 = v2->cache_tags;
    int v183 = v182[v425];
    bool v447 = !(((~(((v157 ^ ((int)((unsigned int)((int)((unsigned int)(v151 + 16) >> 2)) >> 1))) | (-(v157 ^ ((int)((unsigned int)((int)((unsigned int)(v151 + 16) >> 2)) >> 1))))) >> 31)) | (~(((v159 ^ ((int)((unsigned int)((int)((unsigned int)(v151 + 16) >> 2)) >> 1))) | (-(v159 ^ ((int)((unsigned int)((int)((unsigned int)(v151 + 16) >> 2)) >> 1))))) >> 31))) == 0);
    int v247;
    if (v447) {
      int * v184 = v2->cache_age;
      int v449 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v151 + 16) >> 2)) >> 1)) & 3) * 2)) + ((~(((v159 ^ ((int)((unsigned int)((int)((unsigned int)(v151 + 16) >> 2)) >> 1))) | (-(v159 ^ ((int)((unsigned int)((int)((unsigned int)(v151 + 16) >> 2)) >> 1))))) >> 31)) & 1);
      int v185 = v184[v449];
      int * v186 = v2->cache_age;
      int v187 = v186[v427];
      int * v188 = v2->cache_age;
      int v452 = v187 + ((int)((unsigned int)(v187 - v185) >> 31));
      v188[v427] = v452;
      int * v190 = v2->cache_age;
      int v191 = v190[v429];
      int * v192 = v2->cache_age;
      int v455 = v191 + ((int)((unsigned int)(v191 - v185) >> 31));
      v192[v429] = v455;
      int * v194 = v2->cache_age;
      v194[v449] = 0;
      v247 = v449;
    } else {
      int * v197 = v2->cache_age;
      int v459 = 4 + ((((int)((unsigned int)((int)((unsigned int)(v151 + 16) >> 2)) >> 1)) & 3) * 2);
      int v198 = v197[v459];
      int * v199 = v2->cache_tags;
      int v200 = v199[v459];
      int * v201 = v2->cache_age;
      int v202 = v201[v429];
      int * v203 = v2->cache_tags;
      int v204 = v203[v429];
      int * v205 = v2->cache_dirty;
      int v464 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v151 + 16) >> 2)) >> 1)) & 3) * 2)) + ((((v198 + ((~(((v200 ^ -1) | (-(v200 ^ -1))) >> 31)) & 2)) - (v202 + ((~(((v204 ^ -1) | (-(v204 ^ -1))) >> 31)) & 2))) >> 31) & 1);
      int v206 = v205[v464];
      bool v465 = !(v206 == 0);
      if (v465) {
        int * v207 = v2->cache_tags;
        int v208 = v207[v464];
        int * v209 = v2->cache_vals;
        int v468 = ((4 + ((((int)((unsigned int)((int)((unsigned int)(v151 + 16) >> 2)) >> 1)) & 3) * 2)) + ((((v198 + ((~(((v200 ^ -1) | (-(v200 ^ -1))) >> 31)) & 2)) - (v202 + ((~(((v204 ^ -1) | (-(v204 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
        int v210 = v209[v468];
        int * v211 = v2->cache_vals;
        int v470 = (((4 + ((((int)((unsigned int)((int)((unsigned int)(v151 + 16) >> 2)) >> 1)) & 3) * 2)) + ((((v198 + ((~(((v200 ^ -1) | (-(v200 ^ -1))) >> 31)) & 2)) - (v202 + ((~(((v204 ^ -1) | (-(v204 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
        int v212 = v211[v470];
        int * v213 = v2->mem;
        int v472 = v208 * 2;
        v213[v472] = v210;
        int * v215 = v2->mem;
        int v475 = (v208 * 2) + 1;
        v215[v475] = v212;
        ;
      } else {
        ;
      }
      int * v220 = v2->mem;
      int v480 = ((int)((unsigned int)((int)((unsigned int)(v151 + 16) >> 2)) >> 1)) * 2;
      int v221 = v220[v480];
      int * v222 = v2->mem;
      int v482 = (((int)((unsigned int)((int)((unsigned int)(v151 + 16) >> 2)) >> 1)) * 2) + 1;
      int v223 = v222[v482];
      int * v224 = v2->cache_vals;
      int v484 = ((4 + ((((int)((unsigned int)((int)((unsigned int)(v151 + 16) >> 2)) >> 1)) & 3) * 2)) + ((((v198 + ((~(((v200 ^ -1) | (-(v200 ^ -1))) >> 31)) & 2)) - (v202 + ((~(((v204 ^ -1) | (-(v204 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
      v224[v484] = v221;
      int * v226 = v2->cache_vals;
      int v487 = (((4 + ((((int)((unsigned int)((int)((unsigned int)(v151 + 16) >> 2)) >> 1)) & 3) * 2)) + ((((v198 + ((~(((v200 ^ -1) | (-(v200 ^ -1))) >> 31)) & 2)) - (v202 + ((~(((v204 ^ -1) | (-(v204 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
      v226[v487] = v223;
      int * v228 = v2->cache_tags;
      int v490 = (int)((unsigned int)((int)((unsigned int)(v151 + 16) >> 2)) >> 1);
      v228[v464] = v490;
      int * v230 = v2->cache_dirty;
      v230[v464] = 0;
      int * v232 = v2->cache_age;
      v232[v464] = 1;
      int * v234 = v2->cache_age;
      int v235 = v234[v464];
      int * v236 = v2->cache_age;
      int v237 = v236[v427];
      int * v238 = v2->cache_age;
      int v498 = v237 + ((int)((unsigned int)(v237 - v235) >> 31));
      v238[v427] = v498;
      int * v240 = v2->cache_age;
      int v241 = v240[v429];
      int * v242 = v2->cache_age;
      int v501 = v241 + ((int)((unsigned int)(v241 - v235) >> 31));
      v242[v429] = v501;
      int * v244 = v2->cache_age;
      v244[v464] = 0;
      v247 = v464;
    }
    int * v248 = v2->cache_vals;
    int v504 = v247 * 2;
    int v249 = v248[v504];
    int * v250 = v2->cache_vals;
    int v506 = (v247 * 2) + 1;
    int v251 = v250[v506];
    int * v252 = v2->cache_vals;
    int v508 = (((((int)((unsigned int)((int)((unsigned int)(v151 + 16) >> 2)) >> 1)) & 1) * 2) + ((((v177 + ((~(((v179 ^ -1) | (-(v179 ^ -1))) >> 31)) & 2)) - (v181 + ((~(((v183 ^ -1) | (-(v183 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
    v252[v508] = v249;
    int * v254 = v2->cache_vals;
    int v511 = ((((((int)((unsigned int)((int)((unsigned int)(v151 + 16) >> 2)) >> 1)) & 1) * 2) + ((((v177 + ((~(((v179 ^ -1) | (-(v179 ^ -1))) >> 31)) & 2)) - (v181 + ((~(((v183 ^ -1) | (-(v183 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
    v254[v511] = v251;
    int * v256 = v2->cache_tags;
    int v514 = ((((int)((unsigned int)((int)((unsigned int)(v151 + 16) >> 2)) >> 1)) & 1) * 2) + ((((v177 + ((~(((v179 ^ -1) | (-(v179 ^ -1))) >> 31)) & 2)) - (v181 + ((~(((v183 ^ -1) | (-(v183 ^ -1))) >> 31)) & 2))) >> 31) & 1);
    int v515 = (int)((unsigned int)((int)((unsigned int)(v151 + 16) >> 2)) >> 1);
    v256[v514] = v515;
    int * v258 = v2->cache_dirty;
    v258[v514] = 0;
    int * v260 = v2->cache_age;
    v260[v514] = 1;
    int * v262 = v2->cache_age;
    int v263 = v262[v514];
    int * v264 = v2->cache_age;
    int v265 = v264[v423];
    int * v266 = v2->cache_age;
    int v523 = v265 + ((int)((unsigned int)(v265 - v263) >> 31));
    v266[v423] = v523;
    int * v268 = v2->cache_age;
    int v269 = v268[v425];
    int * v270 = v2->cache_age;
    int v526 = v269 + ((int)((unsigned int)(v269 - v263) >> 31));
    v270[v425] = v526;
    int * v272 = v2->cache_age;
    v272[v514] = 0;
    v275 = v514;
  }
  int v529 = (v275 * 2) + (((int)((unsigned int)(v151 + 16) >> 2)) & 1);
  int v276 = v162[v529];
  int * v277 = v2->regs;
  v277[12] = v276;
  int * v279 = v2->regs;
  int v280 = v279[10];
  bool v533 = v280 == 0;
  if (v533) {
    int v281 = v2->timer;
    int v534 = v281 + 15;
    v2->timer = v534;
    int * v283 = v2->saved_regs;
    int v284 = v283[11];
    int * v285 = v2->regs;
    v285[11] = v284;
    int * v287 = v2->saved_regs;
    int v288 = v287[12];
    int * v289 = v2->regs;
    v289[12] = v288;
    ;
  } else {
    ;
  }
  return v2;
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
    s1.mem[SECRET_OFFSET+i] = bounded(0, 20);
    s2.mem[SECRET_OFFSET+i] = bounded(0, 20);
  }
  struct StateT *s1_ = snippet(&s1);
  struct StateT *s2_ = snippet(&s2);
  koika_assert(s1_->timer==s2_->timer, "timing leak");
  return 0;
}