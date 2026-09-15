// verify: leak (KLEE should report a failing assertion) [budget 120s]
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
struct StateT * slot_8(struct StateT * v317);
struct StateT * slot_6(struct StateT * v189);
struct StateT * slot_5(struct StateT * v77);
struct StateT * slot_4(struct StateT * v49);
struct StateT * slot_2(struct StateT * v28);
struct StateT * slot_7(struct StateT * v205);
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

struct StateT * slot_8(struct StateT * v317) {
  int * v318 = v317->regs;
  int v319 = v318[10];
  int * v320 = v317->regs;
  int v321 = v320[15];
  bool v344 = v319 >= v321;
  struct StateT * v338;
  if (v344) {
    int v322 = v317->timer;
    int v345 = v322 + 15;
    v317->timer = v345;
    int * v324 = v317->saved_regs;
    int v325 = v324[5];
    int * v326 = v317->regs;
    v326[5] = v325;
    int * v328 = v317->saved_regs;
    int v329 = v328[11];
    int * v330 = v317->regs;
    v330[11] = v329;
    int * v332 = v317->saved_regs;
    int v333 = v332[12];
    int * v334 = v317->regs;
    v334[12] = v333;
    v338 = v317;
  } else {
    v338 = v317;
  }
  return v338;
}

struct StateT * slot_6(struct StateT * v189) {
  int v190 = v189->timer;
  int v198 = v190 + 1;
  v189->timer = v198;
  int * v192 = v189->regs;
  int v193 = v192[11];
  int * v194 = v189->regs;
  int v202 = v193 << 2;
  v194[11] = v202;
  struct StateT * v196 = slot_7(v189);
  return v196;
}

struct StateT * slot_5(struct StateT * v77) {
  int * v78 = v77->saved_regs;
  int * v79 = v77->regs;
  int v80 = v79[11];
  v78[11] = v80;
  int v82 = v77->timer;
  int v144 = v82 + 1;
  v77->timer = v144;
  int * v84 = v77->regs;
  int v85 = v84[5];
  int * v86 = v77->cache_keys;
  int v87 = v86[0];
  bool v149 = v87 == ((int)((unsigned int)v85 >> 2));
  int v135;
  if (v149) {
    int * v88 = v77->cache_vals;
    int v89 = v88[0];
    v135 = v89;
  } else {
    int * v91 = v77->cache_keys;
    int v92 = v91[1];
    bool v154 = v92 == ((int)((unsigned int)v85 >> 2));
    int v133;
    if (v154) {
      int * v93 = v77->cache_vals;
      int v94 = v93[1];
      int * v95 = v77->cache_keys;
      int * v96 = v77->cache_keys;
      int v97 = v96[0];
      v95[1] = v97;
      int * v99 = v77->cache_vals;
      int * v100 = v77->cache_vals;
      int v101 = v100[0];
      v99[1] = v101;
      int * v103 = v77->cache_keys;
      int v163 = (int)((unsigned int)v85 >> 2);
      v103[0] = v163;
      int * v105 = v77->cache_vals;
      v105[0] = v94;
      int v107 = v77->timer;
      int v166 = v107 + 1;
      v77->timer = v166;
      v133 = v94;
    } else {
      int * v110 = v77->mem;
      int v168 = (int)((unsigned int)v85 >> 2);
      int v111 = v110[v168];
      int * v112 = v77->mem;
      int * v113 = v77->cache_keys;
      int v114 = v113[1];
      int * v115 = v77->cache_vals;
      int v116 = v115[1];
      v112[v114] = v116;
      int * v118 = v77->cache_keys;
      int * v119 = v77->cache_keys;
      int v120 = v119[0];
      v118[1] = v120;
      int * v122 = v77->cache_vals;
      int * v123 = v77->cache_vals;
      int v124 = v123[0];
      v122[1] = v124;
      int * v126 = v77->cache_keys;
      v126[0] = v168;
      int * v128 = v77->cache_vals;
      v128[0] = v111;
      int v130 = v77->timer;
      int v183 = v130 + 100;
      v77->timer = v183;
      v133 = v111;
    }
    v135 = v133;
  }
  int * v136 = v77->regs;
  v136[11] = v135;
  struct StateT * v138 = slot_6(v77);
  return v138;
}

struct StateT * slot_4(struct StateT * v49) {
  int * v50 = v49->saved_regs;
  int * v51 = v49->regs;
  int v52 = v51[5];
  v50[5] = v52;
  int v54 = v49->timer;
  int v68 = v54 + 1;
  v49->timer = v68;
  int * v56 = v49->regs;
  int v57 = v56[13];
  int * v58 = v49->regs;
  int v59 = v58[10];
  int * v60 = v49->regs;
  int v74 = v57 + v59;
  v60[5] = v74;
  struct StateT * v62 = slot_5(v49);
  return v62;
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

struct StateT * slot_7(struct StateT * v205) {
  int * v206 = v205->saved_regs;
  int * v207 = v205->regs;
  int v208 = v207[12];
  v206[12] = v208;
  int v210 = v205->timer;
  int v272 = v210 + 1;
  v205->timer = v272;
  int * v212 = v205->regs;
  int v213 = v212[11];
  int * v214 = v205->cache_keys;
  int v215 = v214[0];
  bool v277 = v215 == ((int)((unsigned int)v213 >> 2));
  int v263;
  if (v277) {
    int * v216 = v205->cache_vals;
    int v217 = v216[0];
    v263 = v217;
  } else {
    int * v219 = v205->cache_keys;
    int v220 = v219[1];
    bool v282 = v220 == ((int)((unsigned int)v213 >> 2));
    int v261;
    if (v282) {
      int * v221 = v205->cache_vals;
      int v222 = v221[1];
      int * v223 = v205->cache_keys;
      int * v224 = v205->cache_keys;
      int v225 = v224[0];
      v223[1] = v225;
      int * v227 = v205->cache_vals;
      int * v228 = v205->cache_vals;
      int v229 = v228[0];
      v227[1] = v229;
      int * v231 = v205->cache_keys;
      int v291 = (int)((unsigned int)v213 >> 2);
      v231[0] = v291;
      int * v233 = v205->cache_vals;
      v233[0] = v222;
      int v235 = v205->timer;
      int v294 = v235 + 1;
      v205->timer = v294;
      v261 = v222;
    } else {
      int * v238 = v205->mem;
      int v296 = (int)((unsigned int)v213 >> 2);
      int v239 = v238[v296];
      int * v240 = v205->mem;
      int * v241 = v205->cache_keys;
      int v242 = v241[1];
      int * v243 = v205->cache_vals;
      int v244 = v243[1];
      v240[v242] = v244;
      int * v246 = v205->cache_keys;
      int * v247 = v205->cache_keys;
      int v248 = v247[0];
      v246[1] = v248;
      int * v250 = v205->cache_vals;
      int * v251 = v205->cache_vals;
      int v252 = v251[0];
      v250[1] = v252;
      int * v254 = v205->cache_keys;
      v254[0] = v296;
      int * v256 = v205->cache_vals;
      v256[0] = v239;
      int v258 = v205->timer;
      int v311 = v258 + 100;
      v205->timer = v311;
      v261 = v239;
    }
    v263 = v261;
  }
  int * v264 = v205->regs;
  v264[12] = v263;
  struct StateT * v266 = slot_8(v205);
  return v266;
}

struct StateT * slot_3(struct StateT * v41) {
  int v42 = v41->timer;
  int v46 = v42 + 1;
  v41->timer = v46;
  struct StateT * v44 = slot_4(v41);
  return v44;
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