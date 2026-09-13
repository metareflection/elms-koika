// verify: leak (CBMC should report VERIFICATION FAILED)

#define NUM_REGS 32
#define MEM_SIZE 30
#define SECRET_SIZE 10
#define SECRET_OFFSET 20
#define CACHE_LRU_SIZE 10
#ifndef CBMC
#define __CPROVER_assert(b,s) 0
#define nondet_uint() 0
#else
int nondet_uint();
#endif
int bounded(int low, int high) {
  int x = nondet_uint();
  __CPROVER_assume(low <= x && x <= high);
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
struct StateT * v1(struct StateT * v2);
struct StateT * v5(struct StateT * v6);
struct StateT * v137(struct StateT * v138);
struct StateT * v75(struct StateT * v76);
struct StateT * v67(struct StateT * v68);
struct StateT * snippet(struct StateT * v0) {
  struct StateT * v284 = v1(v0);
  return v284;
}

struct StateT * v1(struct StateT * v2) {
  int v3 = v2->timer;
  int v281 = v3 + 1;
  v2->timer = v281;
  struct StateT * v279 = v5(v2);
  return v279;
}

struct StateT * v5(struct StateT * v6) {
  int * v7 = v6->saved_regs;
  int * v8 = v6->regs;
  int v9 = v8[11];
  v7[11] = v9;
  int v11 = v6->timer;
  int v234 = v11 + 1;
  v6->timer = v234;
  int * v13 = v6->regs;
  int v14 = v13[10];
  int * v15 = v6->cache_keys;
  int v16 = v15[0];
  bool v239 = v16 == ((int)((unsigned int)v14 >> 2));
  int v64;
  if (v239) {
    int * v17 = v6->cache_vals;
    int v18 = v17[0];
    v64 = v18;
  } else {
    int * v20 = v6->cache_keys;
    int v21 = v20[1];
    bool v244 = v21 == ((int)((unsigned int)v14 >> 2));
    int v62;
    if (v244) {
      int * v22 = v6->cache_vals;
      int v23 = v22[1];
      int * v24 = v6->cache_keys;
      int * v25 = v6->cache_keys;
      int v26 = v25[0];
      v24[1] = v26;
      int * v28 = v6->cache_vals;
      int * v29 = v6->cache_vals;
      int v30 = v29[0];
      v28[1] = v30;
      int * v32 = v6->cache_keys;
      int v253 = (int)((unsigned int)v14 >> 2);
      v32[0] = v253;
      int * v34 = v6->cache_vals;
      v34[0] = v23;
      int v36 = v6->timer;
      int v256 = v36 + 1;
      v6->timer = v256;
      v62 = v23;
    } else {
      int * v39 = v6->mem;
      int v258 = (int)((unsigned int)v14 >> 2);
      int v40 = v39[v258];
      int * v41 = v6->mem;
      int * v42 = v6->cache_keys;
      int v43 = v42[1];
      int * v44 = v6->cache_vals;
      int v45 = v44[1];
      v41[v43] = v45;
      int * v47 = v6->cache_keys;
      int * v48 = v6->cache_keys;
      int v49 = v48[0];
      v47[1] = v49;
      int * v51 = v6->cache_vals;
      int * v52 = v6->cache_vals;
      int v53 = v52[0];
      v51[1] = v53;
      int * v55 = v6->cache_keys;
      v55[0] = v258;
      int * v57 = v6->cache_vals;
      v57[0] = v40;
      int v59 = v6->timer;
      int v273 = v59 + 100;
      v6->timer = v273;
      v62 = v40;
    }
    v64 = v62;
  }
  int * v65 = v6->regs;
  v65[11] = v64;
  struct StateT * v228 = v67(v6);
  return v228;
}

struct StateT * v137(struct StateT * v138) {
  int * v139 = v138->regs;
  int v140 = v139[10];
  bool v157 = v140 == 0;
  struct StateT * v153;
  if (v157) {
    int v141 = v138->timer;
    int v158 = v141 + 15;
    v138->timer = v158;
    int * v143 = v138->saved_regs;
    int v144 = v143[11];
    int * v145 = v138->regs;
    v145[11] = v144;
    int * v147 = v138->saved_regs;
    int v148 = v147[12];
    int * v149 = v138->regs;
    v149[12] = v148;
    v153 = v138;
  } else {
    v153 = v138;
  }
  return v153;
}

struct StateT * v75(struct StateT * v76) {
  int * v77 = v76->saved_regs;
  int * v78 = v76->regs;
  int v79 = v78[12];
  v77[12] = v79;
  int v81 = v76->timer;
  int v174 = v81 + 1;
  v76->timer = v174;
  int * v83 = v76->regs;
  int v84 = v83[11];
  int * v85 = v76->cache_keys;
  int v86 = v85[0];
  bool v179 = v86 == ((int)((unsigned int)(v84 + 16) >> 2));
  int v134;
  if (v179) {
    int * v87 = v76->cache_vals;
    int v88 = v87[0];
    v134 = v88;
  } else {
    int * v90 = v76->cache_keys;
    int v91 = v90[1];
    bool v184 = v91 == ((int)((unsigned int)(v84 + 16) >> 2));
    int v132;
    if (v184) {
      int * v92 = v76->cache_vals;
      int v93 = v92[1];
      int * v94 = v76->cache_keys;
      int * v95 = v76->cache_keys;
      int v96 = v95[0];
      v94[1] = v96;
      int * v98 = v76->cache_vals;
      int * v99 = v76->cache_vals;
      int v100 = v99[0];
      v98[1] = v100;
      int * v102 = v76->cache_keys;
      int v193 = (int)((unsigned int)(v84 + 16) >> 2);
      v102[0] = v193;
      int * v104 = v76->cache_vals;
      v104[0] = v93;
      int v106 = v76->timer;
      int v196 = v106 + 1;
      v76->timer = v196;
      v132 = v93;
    } else {
      int * v109 = v76->mem;
      int v198 = (int)((unsigned int)(v84 + 16) >> 2);
      int v110 = v109[v198];
      int * v111 = v76->mem;
      int * v112 = v76->cache_keys;
      int v113 = v112[1];
      int * v114 = v76->cache_vals;
      int v115 = v114[1];
      v111[v113] = v115;
      int * v117 = v76->cache_keys;
      int * v118 = v76->cache_keys;
      int v119 = v118[0];
      v117[1] = v119;
      int * v121 = v76->cache_vals;
      int * v122 = v76->cache_vals;
      int v123 = v122[0];
      v121[1] = v123;
      int * v125 = v76->cache_keys;
      v125[0] = v198;
      int * v127 = v76->cache_vals;
      v127[0] = v110;
      int v129 = v76->timer;
      int v213 = v129 + 100;
      v76->timer = v213;
      v132 = v110;
    }
    v134 = v132;
  }
  int * v135 = v76->regs;
  v135[12] = v134;
  struct StateT * v168 = v137(v76);
  return v168;
}

struct StateT * v67(struct StateT * v68) {
  int v69 = v68->timer;
  int v221 = v69 + 1;
  v68->timer = v221;
  int * v71 = v68->regs;
  int v72 = v71[11];
  int * v73 = v68->regs;
  int v225 = v72 << 2;
  v73[11] = v225;
  struct StateT * v219 = v75(v68);
  return v219;
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
  __CPROVER_assert(s1_->timer==s2_->timer, "timing leak");
  return 0;
}