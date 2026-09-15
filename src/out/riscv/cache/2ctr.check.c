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
struct StateT * slot_1(struct StateT * v19);
struct StateT * slot_2(struct StateT * v124);
struct StateT * slot_3(struct StateT * v140);
struct StateT * slot_0(struct StateT * v2);
struct StateT * snippet(struct StateT * v0) {
  struct StateT * v1 = slot_0(v0);
  return v1;
}

struct StateT * slot_1(struct StateT * v19) {
  int v20 = v19->timer;
  int v78 = v20 + 1;
  v19->timer = v78;
  int * v22 = v19->regs;
  int v23 = v22[10];
  int * v24 = v19->cache_keys;
  int v25 = v24[0];
  bool v83 = v25 == ((int)((unsigned int)v23 >> 2));
  int v73;
  if (v83) {
    int * v26 = v19->cache_vals;
    int v27 = v26[0];
    v73 = v27;
  } else {
    int * v29 = v19->cache_keys;
    int v30 = v29[1];
    bool v88 = v30 == ((int)((unsigned int)v23 >> 2));
    int v71;
    if (v88) {
      int * v31 = v19->cache_vals;
      int v32 = v31[1];
      int * v33 = v19->cache_keys;
      int * v34 = v19->cache_keys;
      int v35 = v34[0];
      v33[1] = v35;
      int * v37 = v19->cache_vals;
      int * v38 = v19->cache_vals;
      int v39 = v38[0];
      v37[1] = v39;
      int * v41 = v19->cache_keys;
      int v97 = (int)((unsigned int)v23 >> 2);
      v41[0] = v97;
      int * v43 = v19->cache_vals;
      v43[0] = v32;
      int v45 = v19->timer;
      int v100 = v45 + 1;
      v19->timer = v100;
      v71 = v32;
    } else {
      int * v48 = v19->mem;
      int v102 = (int)((unsigned int)v23 >> 2);
      int v49 = v48[v102];
      int * v50 = v19->mem;
      int * v51 = v19->cache_keys;
      int v52 = v51[1];
      int * v53 = v19->cache_vals;
      int v54 = v53[1];
      v50[v52] = v54;
      int * v56 = v19->cache_keys;
      int * v57 = v19->cache_keys;
      int v58 = v57[0];
      v56[1] = v58;
      int * v60 = v19->cache_vals;
      int * v61 = v19->cache_vals;
      int v62 = v61[0];
      v60[1] = v62;
      int * v64 = v19->cache_keys;
      v64[0] = v102;
      int * v66 = v19->cache_vals;
      v66[0] = v49;
      int v68 = v19->timer;
      int v117 = v68 + 100;
      v19->timer = v117;
      v71 = v49;
    }
    v73 = v71;
  }
  int * v74 = v19->regs;
  v74[11] = v73;
  struct StateT * v76 = slot_2(v19);
  return v76;
}

struct StateT * slot_2(struct StateT * v124) {
  int v125 = v124->timer;
  int v133 = v125 + 1;
  v124->timer = v133;
  int * v127 = v124->regs;
  int v128 = v127[11];
  int * v129 = v124->regs;
  int v137 = v128 << 2;
  v129[11] = v137;
  struct StateT * v131 = slot_3(v124);
  return v131;
}

struct StateT * slot_3(struct StateT * v140) {
  int v141 = v140->timer;
  int v198 = v141 + 1;
  v140->timer = v198;
  int * v143 = v140->regs;
  int v144 = v143[11];
  int * v145 = v140->cache_keys;
  int v146 = v145[0];
  bool v203 = v146 == ((int)((unsigned int)(v144 + 16) >> 2));
  int v194;
  if (v203) {
    int * v147 = v140->cache_vals;
    int v148 = v147[0];
    v194 = v148;
  } else {
    int * v150 = v140->cache_keys;
    int v151 = v150[1];
    bool v208 = v151 == ((int)((unsigned int)(v144 + 16) >> 2));
    int v192;
    if (v208) {
      int * v152 = v140->cache_vals;
      int v153 = v152[1];
      int * v154 = v140->cache_keys;
      int * v155 = v140->cache_keys;
      int v156 = v155[0];
      v154[1] = v156;
      int * v158 = v140->cache_vals;
      int * v159 = v140->cache_vals;
      int v160 = v159[0];
      v158[1] = v160;
      int * v162 = v140->cache_keys;
      int v217 = (int)((unsigned int)(v144 + 16) >> 2);
      v162[0] = v217;
      int * v164 = v140->cache_vals;
      v164[0] = v153;
      int v166 = v140->timer;
      int v220 = v166 + 1;
      v140->timer = v220;
      v192 = v153;
    } else {
      int * v169 = v140->mem;
      int v222 = (int)((unsigned int)(v144 + 16) >> 2);
      int v170 = v169[v222];
      int * v171 = v140->mem;
      int * v172 = v140->cache_keys;
      int v173 = v172[1];
      int * v174 = v140->cache_vals;
      int v175 = v174[1];
      v171[v173] = v175;
      int * v177 = v140->cache_keys;
      int * v178 = v140->cache_keys;
      int v179 = v178[0];
      v177[1] = v179;
      int * v181 = v140->cache_vals;
      int * v182 = v140->cache_vals;
      int v183 = v182[0];
      v181[1] = v183;
      int * v185 = v140->cache_keys;
      v185[0] = v222;
      int * v187 = v140->cache_vals;
      v187[0] = v170;
      int v189 = v140->timer;
      int v237 = v189 + 100;
      v140->timer = v237;
      v192 = v170;
    }
    v194 = v192;
  }
  int * v195 = v140->regs;
  v195[12] = v194;
  return v140;
}

struct StateT * slot_0(struct StateT * v2) {
  int v3 = v2->timer;
  int v12 = v3 + 1;
  v2->timer = v12;
  int * v5 = v2->regs;
  int v6 = v5[10];
  bool v15 = v6 == 0;
  struct StateT * v10;
  if (v15) {
    v10 = v2;
  } else {
    struct StateT * v8 = slot_1(v2);
    v10 = v8;
  }
  return v10;
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
  __CPROVER_assert(s1_->timer==s2_->timer, "timing leak");
  return 0;
}