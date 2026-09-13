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
struct StateT * v74(struct StateT * v75);
struct StateT * v8(struct StateT * v9);
struct StateT * v66(struct StateT * v67);
struct StateT * snippet(struct StateT * v0) {
  struct StateT * v245 = v1(v0);
  return v245;
}

struct StateT * v1(struct StateT * v2) {
  int v3 = v2->timer;
  int v238 = v3 + 1;
  v2->timer = v238;
  int * v5 = v2->regs;
  int v6 = v5[10];
  bool v241 = v6 == 0;
  struct StateT * v236;
  if (v241) {
    v236 = v2;
  } else {
    struct StateT * v234 = v8(v2);
    v236 = v234;
  }
  return v236;
}

struct StateT * v74(struct StateT * v75) {
  int v76 = v75->timer;
  int v133 = v76 + 1;
  v75->timer = v133;
  int * v78 = v75->regs;
  int v79 = v78[11];
  int * v80 = v75->cache_keys;
  int v81 = v80[0];
  bool v138 = v81 == ((int)((unsigned int)(v79 + 16) >> 2));
  int v129;
  if (v138) {
    int * v82 = v75->cache_vals;
    int v83 = v82[0];
    v129 = v83;
  } else {
    int * v85 = v75->cache_keys;
    int v86 = v85[1];
    bool v143 = v86 == ((int)((unsigned int)(v79 + 16) >> 2));
    int v127;
    if (v143) {
      int * v87 = v75->cache_vals;
      int v88 = v87[1];
      int * v89 = v75->cache_keys;
      int * v90 = v75->cache_keys;
      int v91 = v90[0];
      v89[1] = v91;
      int * v93 = v75->cache_vals;
      int * v94 = v75->cache_vals;
      int v95 = v94[0];
      v93[1] = v95;
      int * v97 = v75->cache_keys;
      int v152 = (int)((unsigned int)(v79 + 16) >> 2);
      v97[0] = v152;
      int * v99 = v75->cache_vals;
      v99[0] = v88;
      int v101 = v75->timer;
      int v155 = v101 + 1;
      v75->timer = v155;
      v127 = v88;
    } else {
      int * v104 = v75->mem;
      int v157 = (int)((unsigned int)(v79 + 16) >> 2);
      int v105 = v104[v157];
      int * v106 = v75->mem;
      int * v107 = v75->cache_keys;
      int v108 = v107[1];
      int * v109 = v75->cache_vals;
      int v110 = v109[1];
      v106[v108] = v110;
      int * v112 = v75->cache_keys;
      int * v113 = v75->cache_keys;
      int v114 = v113[0];
      v112[1] = v114;
      int * v116 = v75->cache_vals;
      int * v117 = v75->cache_vals;
      int v118 = v117[0];
      v116[1] = v118;
      int * v120 = v75->cache_keys;
      v120[0] = v157;
      int * v122 = v75->cache_vals;
      v122[0] = v105;
      int v124 = v75->timer;
      int v172 = v124 + 100;
      v75->timer = v172;
      v127 = v105;
    }
    v129 = v127;
  }
  int * v130 = v75->regs;
  v130[12] = v129;
  return v75;
}

struct StateT * v8(struct StateT * v9) {
  int v10 = v9->timer;
  int v188 = v10 + 1;
  v9->timer = v188;
  int * v12 = v9->regs;
  int v13 = v12[10];
  int * v14 = v9->cache_keys;
  int v15 = v14[0];
  bool v193 = v15 == ((int)((unsigned int)v13 >> 2));
  int v63;
  if (v193) {
    int * v16 = v9->cache_vals;
    int v17 = v16[0];
    v63 = v17;
  } else {
    int * v19 = v9->cache_keys;
    int v20 = v19[1];
    bool v198 = v20 == ((int)((unsigned int)v13 >> 2));
    int v61;
    if (v198) {
      int * v21 = v9->cache_vals;
      int v22 = v21[1];
      int * v23 = v9->cache_keys;
      int * v24 = v9->cache_keys;
      int v25 = v24[0];
      v23[1] = v25;
      int * v27 = v9->cache_vals;
      int * v28 = v9->cache_vals;
      int v29 = v28[0];
      v27[1] = v29;
      int * v31 = v9->cache_keys;
      int v207 = (int)((unsigned int)v13 >> 2);
      v31[0] = v207;
      int * v33 = v9->cache_vals;
      v33[0] = v22;
      int v35 = v9->timer;
      int v210 = v35 + 1;
      v9->timer = v210;
      v61 = v22;
    } else {
      int * v38 = v9->mem;
      int v212 = (int)((unsigned int)v13 >> 2);
      int v39 = v38[v212];
      int * v40 = v9->mem;
      int * v41 = v9->cache_keys;
      int v42 = v41[1];
      int * v43 = v9->cache_vals;
      int v44 = v43[1];
      v40[v42] = v44;
      int * v46 = v9->cache_keys;
      int * v47 = v9->cache_keys;
      int v48 = v47[0];
      v46[1] = v48;
      int * v50 = v9->cache_vals;
      int * v51 = v9->cache_vals;
      int v52 = v51[0];
      v50[1] = v52;
      int * v54 = v9->cache_keys;
      v54[0] = v212;
      int * v56 = v9->cache_vals;
      v56[0] = v39;
      int v58 = v9->timer;
      int v227 = v58 + 100;
      v9->timer = v227;
      v61 = v39;
    }
    v63 = v61;
  }
  int * v64 = v9->regs;
  v64[11] = v63;
  struct StateT * v186 = v66(v9);
  return v186;
}

struct StateT * v66(struct StateT * v67) {
  int v68 = v67->timer;
  int v179 = v68 + 1;
  v67->timer = v179;
  int * v70 = v67->regs;
  int v71 = v70[11];
  int * v72 = v67->regs;
  int v183 = v71 << 2;
  v72[11] = v183;
  struct StateT * v177 = v74(v67);
  return v177;
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