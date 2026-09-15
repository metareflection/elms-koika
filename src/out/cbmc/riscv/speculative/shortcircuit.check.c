// verify: leak (CBMC should report VERIFICATION FAILED) [unwind 33]
#define NUM_REGS 32
#define MEM_SIZE 30
#define SECRET_SIZE 10
#define SECRET_OFFSET 20
#define CACHE_LRU_SIZE 10

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
  int mem[30];
  int saved_regs[32];
  int cache_keys[10];
  int cache_vals[10];
  int timer;
};

struct StateT * slot_12(struct StateT * v388);
struct StateT * slot_14(struct StateT * v378);
struct StateT * slot_2(struct StateT * v28);
struct StateT * slot_3(struct StateT * v41);
struct StateT * snippet(struct StateT * v0);
struct StateT * slot_10(struct StateT * v401);
struct StateT * slot_1(struct StateT * v15);
struct StateT * slot_4(struct StateT * v54);
struct StateT * slot_13(struct StateT * v417);
struct StateT * slot_11(struct StateT * v422);
struct StateT * slot_0(struct StateT * v2);
struct StateT * slot_12(struct StateT * v388) {
  int v389 = v388->timer;
  int v395 = v389 + 1;
  v388->timer = v395;
  int * v391 = v388->regs;
  v391[10] = 0;
  struct StateT * v393 = slot_13(v388);
  return v393;
}

struct StateT * slot_14(struct StateT * v378) {
  int v379 = v378->timer;
  int v384 = v379 + 1;
  v378->timer = v384;
  int * v381 = v378->regs;
  v381[10] = 1;
  return v378;
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

struct StateT * slot_10(struct StateT * v401) {
  int v402 = v401->timer;
  int v410 = v402 + 1;
  v401->timer = v410;
  int * v404 = v401->regs;
  int v405 = v404[14];
  int * v406 = v401->regs;
  int v414 = v405 + 4;
  v406[14] = v414;
  struct StateT * v408 = slot_11(v401);
  return v408;
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

struct StateT * slot_4(struct StateT * v54) {
  int * v55 = v54->saved_regs;
  int * v56 = v54->regs;
  int v57 = v56[5];
  v55[5] = v57;
  int v59 = v54->timer;
  int v241 = v59 + 1;
  v54->timer = v241;
  int * v61 = v54->regs;
  int v62 = v61[12];
  int * v63 = v54->regs;
  int v64 = v63[14];
  int * v65 = v54->regs;
  int v247 = v62 + v64;
  v65[5] = v247;
  int * v67 = v54->saved_regs;
  int * v68 = v54->regs;
  int v69 = v68[10];
  v67[10] = v69;
  int v71 = v54->timer;
  int v252 = v71 + 1;
  v54->timer = v252;
  int * v73 = v54->regs;
  int v74 = v73[5];
  int * v75 = v54->cache_keys;
  int v76 = v75[0];
  bool v256 = v76 == ((int)((unsigned int)v74 >> 2));
  int v124;
  if (v256) {
    int * v77 = v54->cache_vals;
    int v78 = v77[0];
    v124 = v78;
  } else {
    int * v80 = v54->cache_keys;
    int v81 = v80[1];
    bool v261 = v81 == ((int)((unsigned int)v74 >> 2));
    int v122;
    if (v261) {
      int * v82 = v54->cache_vals;
      int v83 = v82[1];
      int * v84 = v54->cache_keys;
      int * v85 = v54->cache_keys;
      int v86 = v85[0];
      v84[1] = v86;
      int * v88 = v54->cache_vals;
      int * v89 = v54->cache_vals;
      int v90 = v89[0];
      v88[1] = v90;
      int * v92 = v54->cache_keys;
      int v270 = (int)((unsigned int)v74 >> 2);
      v92[0] = v270;
      int * v94 = v54->cache_vals;
      v94[0] = v83;
      int v96 = v54->timer;
      int v273 = v96 + 1;
      v54->timer = v273;
      v122 = v83;
    } else {
      int * v99 = v54->mem;
      int v275 = (int)((unsigned int)v74 >> 2);
      int v100 = v99[v275];
      int * v101 = v54->mem;
      int * v102 = v54->cache_keys;
      int v103 = v102[1];
      int * v104 = v54->cache_vals;
      int v105 = v104[1];
      v101[v103] = v105;
      int * v107 = v54->cache_keys;
      int * v108 = v54->cache_keys;
      int v109 = v108[0];
      v107[1] = v109;
      int * v111 = v54->cache_vals;
      int * v112 = v54->cache_vals;
      int v113 = v112[0];
      v111[1] = v113;
      int * v115 = v54->cache_keys;
      v115[0] = v275;
      int * v117 = v54->cache_vals;
      v117[0] = v100;
      int v119 = v54->timer;
      int v290 = v119 + 100;
      v54->timer = v290;
      v122 = v100;
    }
    v124 = v122;
  }
  int * v125 = v54->regs;
  v125[10] = v124;
  int * v127 = v54->saved_regs;
  int * v128 = v54->regs;
  int v129 = v128[6];
  v127[6] = v129;
  int v131 = v54->timer;
  int v298 = v131 + 1;
  v54->timer = v298;
  int * v133 = v54->regs;
  int v134 = v133[13];
  int * v135 = v54->regs;
  int v136 = v135[14];
  int * v137 = v54->regs;
  int v303 = v134 + v136;
  v137[6] = v303;
  int * v139 = v54->saved_regs;
  int * v140 = v54->regs;
  int v141 = v140[11];
  v139[11] = v141;
  int v143 = v54->timer;
  int v308 = v143 + 1;
  v54->timer = v308;
  int * v145 = v54->regs;
  int v146 = v145[6];
  int * v147 = v54->cache_keys;
  int v148 = v147[0];
  bool v311 = v148 == ((int)((unsigned int)v146 >> 2));
  int v196;
  if (v311) {
    int * v149 = v54->cache_vals;
    int v150 = v149[0];
    v196 = v150;
  } else {
    int * v152 = v54->cache_keys;
    int v153 = v152[1];
    bool v316 = v153 == ((int)((unsigned int)v146 >> 2));
    int v194;
    if (v316) {
      int * v154 = v54->cache_vals;
      int v155 = v154[1];
      int * v156 = v54->cache_keys;
      int * v157 = v54->cache_keys;
      int v158 = v157[0];
      v156[1] = v158;
      int * v160 = v54->cache_vals;
      int * v161 = v54->cache_vals;
      int v162 = v161[0];
      v160[1] = v162;
      int * v164 = v54->cache_keys;
      int v325 = (int)((unsigned int)v146 >> 2);
      v164[0] = v325;
      int * v166 = v54->cache_vals;
      v166[0] = v155;
      int v168 = v54->timer;
      int v328 = v168 + 1;
      v54->timer = v328;
      v194 = v155;
    } else {
      int * v171 = v54->mem;
      int v330 = (int)((unsigned int)v146 >> 2);
      int v172 = v171[v330];
      int * v173 = v54->mem;
      int * v174 = v54->cache_keys;
      int v175 = v174[1];
      int * v176 = v54->cache_vals;
      int v177 = v176[1];
      v173[v175] = v177;
      int * v179 = v54->cache_keys;
      int * v180 = v54->cache_keys;
      int v181 = v180[0];
      v179[1] = v181;
      int * v183 = v54->cache_vals;
      int * v184 = v54->cache_vals;
      int v185 = v184[0];
      v183[1] = v185;
      int * v187 = v54->cache_keys;
      v187[0] = v330;
      int * v189 = v54->cache_vals;
      v189[0] = v172;
      int v191 = v54->timer;
      int v345 = v191 + 100;
      v54->timer = v345;
      v194 = v172;
    }
    v196 = v194;
  }
  int * v197 = v54->regs;
  v197[11] = v196;
  int * v199 = v54->regs;
  int v200 = v199[14];
  int * v201 = v54->regs;
  int v202 = v201[15];
  bool v352 = v200 >= v202;
  struct StateT * v235;
  if (v352) {
    int v203 = v54->timer;
    int v353 = v203 + 15;
    v54->timer = v353;
    int * v205 = v54->saved_regs;
    int v206 = v205[5];
    int * v207 = v54->regs;
    v207[5] = v206;
    int * v209 = v54->saved_regs;
    int v210 = v209[10];
    int * v211 = v54->regs;
    v211[10] = v210;
    int * v213 = v54->saved_regs;
    int v214 = v213[6];
    int * v215 = v54->regs;
    v215[6] = v214;
    int * v217 = v54->saved_regs;
    int v218 = v217[11];
    int * v219 = v54->regs;
    v219[11] = v218;
    struct StateT * v221 = slot_14(v54);
    v235 = v221;
  } else {
    int v223 = v54->timer;
    int v368 = v223 + 1;
    v54->timer = v368;
    int * v225 = v54->regs;
    int v226 = v225[10];
    int * v227 = v54->regs;
    int v228 = v227[11];
    bool v371 = !(v226 == v228);
    struct StateT * v233;
    if (v371) {
      struct StateT * v229 = slot_12(v54);
      v233 = v229;
    } else {
      struct StateT * v231 = slot_10(v54);
      v233 = v231;
    }
    v235 = v233;
  }
  return v235;
}

struct StateT * slot_13(struct StateT * v417) {
  int v418 = v417->timer;
  int v421 = v418 + 1;
  v417->timer = v421;
  return v417;
}

struct StateT * slot_11(struct StateT * v422) {
  int v423 = v422->timer;
  int v427 = v423 + 1;
  v422->timer = v427;
  struct StateT * v425 = slot_4(v422);
  return v425;
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
  for (int i=0; i<CACHE_LRU_SIZE; i++) {
    s->cache_keys[i] = -1;
    s->cache_vals[i] = -1;
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