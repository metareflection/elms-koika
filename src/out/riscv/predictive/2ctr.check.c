// verify: leak (CBMC should report VERIFICATION FAILED) [unwind 33]

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
struct StateT * slot_1(struct StateT * v10);
struct StateT * slot_4(struct StateT * v250);
struct StateT * slot_2(struct StateT * v122);
struct StateT * slot_3(struct StateT * v138);
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
  int v77 = v15 + 1;
  v10->timer = v77;
  int * v17 = v10->regs;
  int v18 = v17[10];
  int * v19 = v10->cache_keys;
  int v20 = v19[0];
  bool v82 = v20 == ((int)((unsigned int)v18 >> 2));
  int v68;
  if (v82) {
    int * v21 = v10->cache_vals;
    int v22 = v21[0];
    v68 = v22;
  } else {
    int * v24 = v10->cache_keys;
    int v25 = v24[1];
    bool v87 = v25 == ((int)((unsigned int)v18 >> 2));
    int v66;
    if (v87) {
      int * v26 = v10->cache_vals;
      int v27 = v26[1];
      int * v28 = v10->cache_keys;
      int * v29 = v10->cache_keys;
      int v30 = v29[0];
      v28[1] = v30;
      int * v32 = v10->cache_vals;
      int * v33 = v10->cache_vals;
      int v34 = v33[0];
      v32[1] = v34;
      int * v36 = v10->cache_keys;
      int v96 = (int)((unsigned int)v18 >> 2);
      v36[0] = v96;
      int * v38 = v10->cache_vals;
      v38[0] = v27;
      int v40 = v10->timer;
      int v99 = v40 + 1;
      v10->timer = v99;
      v66 = v27;
    } else {
      int * v43 = v10->mem;
      int v101 = (int)((unsigned int)v18 >> 2);
      int v44 = v43[v101];
      int * v45 = v10->mem;
      int * v46 = v10->cache_keys;
      int v47 = v46[1];
      int * v48 = v10->cache_vals;
      int v49 = v48[1];
      v45[v47] = v49;
      int * v51 = v10->cache_keys;
      int * v52 = v10->cache_keys;
      int v53 = v52[0];
      v51[1] = v53;
      int * v55 = v10->cache_vals;
      int * v56 = v10->cache_vals;
      int v57 = v56[0];
      v55[1] = v57;
      int * v59 = v10->cache_keys;
      v59[0] = v101;
      int * v61 = v10->cache_vals;
      v61[0] = v44;
      int v63 = v10->timer;
      int v116 = v63 + 100;
      v10->timer = v116;
      v66 = v44;
    }
    v68 = v66;
  }
  int * v69 = v10->regs;
  v69[11] = v68;
  struct StateT * v71 = slot_2(v10);
  return v71;
}

struct StateT * slot_4(struct StateT * v250) {
  int * v251 = v250->regs;
  int v252 = v251[10];
  bool v269 = v252 == 0;
  struct StateT * v265;
  if (v269) {
    int v253 = v250->timer;
    int v270 = v253 + 15;
    v250->timer = v270;
    int * v255 = v250->saved_regs;
    int v256 = v255[11];
    int * v257 = v250->regs;
    v257[11] = v256;
    int * v259 = v250->saved_regs;
    int v260 = v259[12];
    int * v261 = v250->regs;
    v261[12] = v260;
    v265 = v250;
  } else {
    v265 = v250;
  }
  return v265;
}

struct StateT * slot_2(struct StateT * v122) {
  int v123 = v122->timer;
  int v131 = v123 + 1;
  v122->timer = v131;
  int * v125 = v122->regs;
  int v126 = v125[11];
  int * v127 = v122->regs;
  int v135 = v126 << 2;
  v127[11] = v135;
  struct StateT * v129 = slot_3(v122);
  return v129;
}

struct StateT * slot_3(struct StateT * v138) {
  int * v139 = v138->saved_regs;
  int * v140 = v138->regs;
  int v141 = v140[12];
  v139[12] = v141;
  int v143 = v138->timer;
  int v205 = v143 + 1;
  v138->timer = v205;
  int * v145 = v138->regs;
  int v146 = v145[11];
  int * v147 = v138->cache_keys;
  int v148 = v147[0];
  bool v210 = v148 == ((int)((unsigned int)(v146 + 16) >> 2));
  int v196;
  if (v210) {
    int * v149 = v138->cache_vals;
    int v150 = v149[0];
    v196 = v150;
  } else {
    int * v152 = v138->cache_keys;
    int v153 = v152[1];
    bool v215 = v153 == ((int)((unsigned int)(v146 + 16) >> 2));
    int v194;
    if (v215) {
      int * v154 = v138->cache_vals;
      int v155 = v154[1];
      int * v156 = v138->cache_keys;
      int * v157 = v138->cache_keys;
      int v158 = v157[0];
      v156[1] = v158;
      int * v160 = v138->cache_vals;
      int * v161 = v138->cache_vals;
      int v162 = v161[0];
      v160[1] = v162;
      int * v164 = v138->cache_keys;
      int v224 = (int)((unsigned int)(v146 + 16) >> 2);
      v164[0] = v224;
      int * v166 = v138->cache_vals;
      v166[0] = v155;
      int v168 = v138->timer;
      int v227 = v168 + 1;
      v138->timer = v227;
      v194 = v155;
    } else {
      int * v171 = v138->mem;
      int v229 = (int)((unsigned int)(v146 + 16) >> 2);
      int v172 = v171[v229];
      int * v173 = v138->mem;
      int * v174 = v138->cache_keys;
      int v175 = v174[1];
      int * v176 = v138->cache_vals;
      int v177 = v176[1];
      v173[v175] = v177;
      int * v179 = v138->cache_keys;
      int * v180 = v138->cache_keys;
      int v181 = v180[0];
      v179[1] = v181;
      int * v183 = v138->cache_vals;
      int * v184 = v138->cache_vals;
      int v185 = v184[0];
      v183[1] = v185;
      int * v187 = v138->cache_keys;
      v187[0] = v229;
      int * v189 = v138->cache_vals;
      v189[0] = v172;
      int v191 = v138->timer;
      int v244 = v191 + 100;
      v138->timer = v244;
      v194 = v172;
    }
    v196 = v194;
  }
  int * v197 = v138->regs;
  v197[12] = v196;
  struct StateT * v199 = slot_4(v138);
  return v199;
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