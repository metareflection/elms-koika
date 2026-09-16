// verify: clean (KLEE should report no failing assertion) [budget 120s]
#define NUM_REGS 32
#define MEM_SIZE 30
#define SECRET_SIZE 10
#define SECRET_OFFSET 20
#define CACHE_LRU_SIZE 10

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

struct StateT {
  int regs[32];
  int mem[30];
  int saved_regs[32];
  int cache_keys[10];
  int cache_vals[10];
  int timer;
};

struct StateT * slot_6(struct StateT * v188);
struct StateT * slot_5(struct StateT * v83);
struct StateT * slot_2(struct StateT * v28);
struct StateT * slot_7(struct StateT * v286);
struct StateT * slot_3(struct StateT * v41);
struct StateT * snippet(struct StateT * v0);
struct StateT * slot_1(struct StateT * v15);
struct StateT * slot_8(struct StateT * v391);
struct StateT * slot_4(struct StateT * v62);
struct StateT * slot_9(struct StateT * v407);
struct StateT * slot_0(struct StateT * v2);
struct StateT * slot_6(struct StateT * v188) {
  int v189 = v188->timer;
  int v243 = v189 + 1;
  v188->timer = v243;
  int * v191 = v188->regs;
  int v192 = v191[6];
  int * v193 = v188->regs;
  int v194 = v193[5];
  int * v195 = v188->cache_keys;
  int v196 = v195[0];
  bool v250 = v196 == ((int)((unsigned int)v192 >> 2));
  int v240;
  if (v250) {
    int * v197 = v188->cache_vals;
    v197[0] = v194;
    v240 = v194;
  } else {
    int * v200 = v188->cache_keys;
    int v201 = v200[1];
    bool v255 = v201 == ((int)((unsigned int)v192 >> 2));
    int v238;
    if (v255) {
      int * v202 = v188->cache_keys;
      int * v203 = v188->cache_keys;
      int v204 = v203[0];
      v202[1] = v204;
      int * v206 = v188->cache_vals;
      int * v207 = v188->cache_vals;
      int v208 = v207[0];
      v206[1] = v208;
      int * v210 = v188->cache_keys;
      int v263 = (int)((unsigned int)v192 >> 2);
      v210[0] = v263;
      int * v212 = v188->cache_vals;
      v212[0] = v194;
      int v214 = v188->timer;
      int v266 = v214 + 1;
      v188->timer = v266;
      v238 = v194;
    } else {
      int * v217 = v188->mem;
      int * v218 = v188->cache_keys;
      int v219 = v218[1];
      int * v220 = v188->cache_vals;
      int v221 = v220[1];
      v217[v219] = v221;
      int * v223 = v188->cache_keys;
      int * v224 = v188->cache_keys;
      int v225 = v224[0];
      v223[1] = v225;
      int * v227 = v188->cache_vals;
      int * v228 = v188->cache_vals;
      int v229 = v228[0];
      v227[1] = v229;
      int * v231 = v188->cache_keys;
      int v279 = (int)((unsigned int)v192 >> 2);
      v231[0] = v279;
      int * v233 = v188->cache_vals;
      v233[0] = v194;
      int v235 = v188->timer;
      int v282 = v235 + 100;
      v188->timer = v282;
      v238 = v194;
    }
    v240 = v238;
  }
  struct StateT * v241 = slot_7(v188);
  return v241;
}

struct StateT * slot_5(struct StateT * v83) {
  int v84 = v83->timer;
  int v142 = v84 + 1;
  v83->timer = v142;
  int * v86 = v83->regs;
  int v87 = v86[8];
  int * v88 = v83->cache_keys;
  int v89 = v88[0];
  bool v147 = v89 == ((int)((unsigned int)v87 >> 2));
  int v137;
  if (v147) {
    int * v90 = v83->cache_vals;
    int v91 = v90[0];
    v137 = v91;
  } else {
    int * v93 = v83->cache_keys;
    int v94 = v93[1];
    bool v152 = v94 == ((int)((unsigned int)v87 >> 2));
    int v135;
    if (v152) {
      int * v95 = v83->cache_vals;
      int v96 = v95[1];
      int * v97 = v83->cache_keys;
      int * v98 = v83->cache_keys;
      int v99 = v98[0];
      v97[1] = v99;
      int * v101 = v83->cache_vals;
      int * v102 = v83->cache_vals;
      int v103 = v102[0];
      v101[1] = v103;
      int * v105 = v83->cache_keys;
      int v161 = (int)((unsigned int)v87 >> 2);
      v105[0] = v161;
      int * v107 = v83->cache_vals;
      v107[0] = v96;
      int v109 = v83->timer;
      int v164 = v109 + 1;
      v83->timer = v164;
      v135 = v96;
    } else {
      int * v112 = v83->mem;
      int v166 = (int)((unsigned int)v87 >> 2);
      int v113 = v112[v166];
      int * v114 = v83->mem;
      int * v115 = v83->cache_keys;
      int v116 = v115[1];
      int * v117 = v83->cache_vals;
      int v118 = v117[1];
      v114[v116] = v118;
      int * v120 = v83->cache_keys;
      int * v121 = v83->cache_keys;
      int v122 = v121[0];
      v120[1] = v122;
      int * v124 = v83->cache_vals;
      int * v125 = v83->cache_vals;
      int v126 = v125[0];
      v124[1] = v126;
      int * v128 = v83->cache_keys;
      v128[0] = v166;
      int * v130 = v83->cache_vals;
      v130[0] = v113;
      int v132 = v83->timer;
      int v181 = v132 + 100;
      v83->timer = v181;
      v135 = v113;
    }
    v137 = v135;
  }
  int * v138 = v83->regs;
  v138[5] = v137;
  struct StateT * v140 = slot_6(v83);
  return v140;
}

struct StateT * slot_2(struct StateT * v28) {
  int v29 = v28->timer;
  int v35 = v29 + 1;
  v28->timer = v35;
  int * v31 = v28->regs;
  v31[9] = 80;
  struct StateT * v33 = slot_3(v28);
  return v33;
}

struct StateT * slot_7(struct StateT * v286) {
  int v287 = v286->timer;
  int v345 = v287 + 1;
  v286->timer = v345;
  int * v289 = v286->regs;
  int v290 = v289[6];
  int * v291 = v286->cache_keys;
  int v292 = v291[0];
  bool v350 = v292 == ((int)((unsigned int)v290 >> 2));
  int v340;
  if (v350) {
    int * v293 = v286->cache_vals;
    int v294 = v293[0];
    v340 = v294;
  } else {
    int * v296 = v286->cache_keys;
    int v297 = v296[1];
    bool v355 = v297 == ((int)((unsigned int)v290 >> 2));
    int v338;
    if (v355) {
      int * v298 = v286->cache_vals;
      int v299 = v298[1];
      int * v300 = v286->cache_keys;
      int * v301 = v286->cache_keys;
      int v302 = v301[0];
      v300[1] = v302;
      int * v304 = v286->cache_vals;
      int * v305 = v286->cache_vals;
      int v306 = v305[0];
      v304[1] = v306;
      int * v308 = v286->cache_keys;
      int v364 = (int)((unsigned int)v290 >> 2);
      v308[0] = v364;
      int * v310 = v286->cache_vals;
      v310[0] = v299;
      int v312 = v286->timer;
      int v367 = v312 + 1;
      v286->timer = v367;
      v338 = v299;
    } else {
      int * v315 = v286->mem;
      int v369 = (int)((unsigned int)v290 >> 2);
      int v316 = v315[v369];
      int * v317 = v286->mem;
      int * v318 = v286->cache_keys;
      int v319 = v318[1];
      int * v320 = v286->cache_vals;
      int v321 = v320[1];
      v317[v319] = v321;
      int * v323 = v286->cache_keys;
      int * v324 = v286->cache_keys;
      int v325 = v324[0];
      v323[1] = v325;
      int * v327 = v286->cache_vals;
      int * v328 = v286->cache_vals;
      int v329 = v328[0];
      v327[1] = v329;
      int * v331 = v286->cache_keys;
      v331[0] = v369;
      int * v333 = v286->cache_vals;
      v333[0] = v316;
      int v335 = v286->timer;
      int v384 = v335 + 100;
      v286->timer = v384;
      v338 = v316;
    }
    v340 = v338;
  }
  int * v341 = v286->regs;
  v341[11] = v340;
  struct StateT * v343 = slot_8(v286);
  return v343;
}

struct StateT * slot_3(struct StateT * v41) {
  int v42 = v41->timer;
  int v53 = v42 + 1;
  v41->timer = v53;
  int * v44 = v41->regs;
  int v45 = v44[6];
  int * v46 = v41->regs;
  int v47 = v46[7];
  bool v58 = v45 >= v47;
  struct StateT * v51;
  if (v58) {
    v51 = v41;
  } else {
    struct StateT * v49 = slot_4(v41);
    v51 = v49;
  }
  return v51;
}

struct StateT * snippet(struct StateT * v0) {
  struct StateT * v1 = slot_0(v0);
  return v1;
}

struct StateT * slot_1(struct StateT * v15) {
  int v16 = v15->timer;
  int v22 = v16 + 1;
  v15->timer = v22;
  int * v18 = v15->regs;
  v18[7] = 16;
  struct StateT * v20 = slot_2(v15);
  return v20;
}

struct StateT * slot_8(struct StateT * v391) {
  int v392 = v391->timer;
  int v400 = v392 + 1;
  v391->timer = v400;
  int * v394 = v391->regs;
  int v395 = v394[6];
  int * v396 = v391->regs;
  int v404 = v395 + 4;
  v396[6] = v404;
  struct StateT * v398 = slot_9(v391);
  return v398;
}

struct StateT * slot_4(struct StateT * v62) {
  int v63 = v62->timer;
  int v73 = v63 + 1;
  v62->timer = v73;
  int * v65 = v62->regs;
  int v66 = v65[9];
  int * v67 = v62->regs;
  int v68 = v67[6];
  int * v69 = v62->regs;
  int v80 = v66 + v68;
  v69[8] = v80;
  struct StateT * v71 = slot_5(v62);
  return v71;
}

struct StateT * slot_9(struct StateT * v407) {
  int v408 = v407->timer;
  int v412 = v408 + 1;
  v407->timer = v412;
  struct StateT * v410 = slot_3(v407);
  return v410;
}

struct StateT * slot_0(struct StateT * v2) {
  int v3 = v2->timer;
  int v9 = v3 + 1;
  v2->timer = v9;
  int * v5 = v2->regs;
  v5[6] = 0;
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