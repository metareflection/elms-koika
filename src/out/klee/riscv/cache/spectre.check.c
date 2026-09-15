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

struct StateT * snippet(struct StateT * v0);
struct StateT * slot_1(struct StateT * v15);
struct StateT * slot_6(struct StateT * v188);
struct StateT * slot_5(struct StateT * v83);
struct StateT * slot_4(struct StateT * v62);
struct StateT * slot_2(struct StateT * v28);
struct StateT * slot_7(struct StateT * v204);
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

struct StateT * slot_6(struct StateT * v188) {
  int v189 = v188->timer;
  int v197 = v189 + 1;
  v188->timer = v197;
  int * v191 = v188->regs;
  int v192 = v191[11];
  int * v193 = v188->regs;
  int v201 = v192 << 2;
  v193[11] = v201;
  struct StateT * v195 = slot_7(v188);
  return v195;
}

struct StateT * slot_5(struct StateT * v83) {
  int v84 = v83->timer;
  int v142 = v84 + 1;
  v83->timer = v142;
  int * v86 = v83->regs;
  int v87 = v86[5];
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
  v138[11] = v137;
  struct StateT * v140 = slot_6(v83);
  return v140;
}

struct StateT * slot_4(struct StateT * v62) {
  int v63 = v62->timer;
  int v73 = v63 + 1;
  v62->timer = v73;
  int * v65 = v62->regs;
  int v66 = v65[13];
  int * v67 = v62->regs;
  int v68 = v67[10];
  int * v69 = v62->regs;
  int v80 = v66 + v68;
  v69[5] = v80;
  struct StateT * v71 = slot_5(v62);
  return v71;
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

struct StateT * slot_7(struct StateT * v204) {
  int v205 = v204->timer;
  int v262 = v205 + 1;
  v204->timer = v262;
  int * v207 = v204->regs;
  int v208 = v207[11];
  int * v209 = v204->cache_keys;
  int v210 = v209[0];
  bool v267 = v210 == ((int)((unsigned int)v208 >> 2));
  int v258;
  if (v267) {
    int * v211 = v204->cache_vals;
    int v212 = v211[0];
    v258 = v212;
  } else {
    int * v214 = v204->cache_keys;
    int v215 = v214[1];
    bool v272 = v215 == ((int)((unsigned int)v208 >> 2));
    int v256;
    if (v272) {
      int * v216 = v204->cache_vals;
      int v217 = v216[1];
      int * v218 = v204->cache_keys;
      int * v219 = v204->cache_keys;
      int v220 = v219[0];
      v218[1] = v220;
      int * v222 = v204->cache_vals;
      int * v223 = v204->cache_vals;
      int v224 = v223[0];
      v222[1] = v224;
      int * v226 = v204->cache_keys;
      int v281 = (int)((unsigned int)v208 >> 2);
      v226[0] = v281;
      int * v228 = v204->cache_vals;
      v228[0] = v217;
      int v230 = v204->timer;
      int v284 = v230 + 1;
      v204->timer = v284;
      v256 = v217;
    } else {
      int * v233 = v204->mem;
      int v286 = (int)((unsigned int)v208 >> 2);
      int v234 = v233[v286];
      int * v235 = v204->mem;
      int * v236 = v204->cache_keys;
      int v237 = v236[1];
      int * v238 = v204->cache_vals;
      int v239 = v238[1];
      v235[v237] = v239;
      int * v241 = v204->cache_keys;
      int * v242 = v204->cache_keys;
      int v243 = v242[0];
      v241[1] = v243;
      int * v245 = v204->cache_vals;
      int * v246 = v204->cache_vals;
      int v247 = v246[0];
      v245[1] = v247;
      int * v249 = v204->cache_keys;
      v249[0] = v286;
      int * v251 = v204->cache_vals;
      v251[0] = v234;
      int v253 = v204->timer;
      int v301 = v253 + 100;
      v204->timer = v301;
      v256 = v234;
    }
    v258 = v256;
  }
  int * v259 = v204->regs;
  v259[12] = v258;
  return v204;
}

struct StateT * slot_3(struct StateT * v41) {
  int v42 = v41->timer;
  int v53 = v42 + 1;
  v41->timer = v53;
  int * v44 = v41->regs;
  int v45 = v44[10];
  int * v46 = v41->regs;
  int v47 = v46[15];
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