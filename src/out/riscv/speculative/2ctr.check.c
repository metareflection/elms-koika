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
  int v149 = v7 + 1;
  v2->timer = v149;
  int * v9 = v2->regs;
  int v10 = v9[10];
  int * v11 = v2->cache_keys;
  int v12 = v11[0];
  bool v154 = v12 == ((int)((unsigned int)v10 >> 2));
  int v60;
  if (v154) {
    int * v13 = v2->cache_vals;
    int v14 = v13[0];
    v60 = v14;
  } else {
    int * v16 = v2->cache_keys;
    int v17 = v16[1];
    bool v159 = v17 == ((int)((unsigned int)v10 >> 2));
    int v58;
    if (v159) {
      int * v18 = v2->cache_vals;
      int v19 = v18[1];
      int * v20 = v2->cache_keys;
      int * v21 = v2->cache_keys;
      int v22 = v21[0];
      v20[1] = v22;
      int * v24 = v2->cache_vals;
      int * v25 = v2->cache_vals;
      int v26 = v25[0];
      v24[1] = v26;
      int * v28 = v2->cache_keys;
      int v168 = (int)((unsigned int)v10 >> 2);
      v28[0] = v168;
      int * v30 = v2->cache_vals;
      v30[0] = v19;
      int v32 = v2->timer;
      int v171 = v32 + 1;
      v2->timer = v171;
      v58 = v19;
    } else {
      int * v35 = v2->mem;
      int v173 = (int)((unsigned int)v10 >> 2);
      int v36 = v35[v173];
      int * v37 = v2->mem;
      int * v38 = v2->cache_keys;
      int v39 = v38[1];
      int * v40 = v2->cache_vals;
      int v41 = v40[1];
      v37[v39] = v41;
      int * v43 = v2->cache_keys;
      int * v44 = v2->cache_keys;
      int v45 = v44[0];
      v43[1] = v45;
      int * v47 = v2->cache_vals;
      int * v48 = v2->cache_vals;
      int v49 = v48[0];
      v47[1] = v49;
      int * v51 = v2->cache_keys;
      v51[0] = v173;
      int * v53 = v2->cache_vals;
      v53[0] = v36;
      int v55 = v2->timer;
      int v188 = v55 + 100;
      v2->timer = v188;
      v58 = v36;
    }
    v60 = v58;
  }
  int * v61 = v2->regs;
  v61[11] = v60;
  int v63 = v2->timer;
  int v192 = v63 + 1;
  v2->timer = v192;
  int * v65 = v2->regs;
  int v66 = v65[11];
  int * v67 = v2->regs;
  int v195 = v66 << 2;
  v67[11] = v195;
  int * v69 = v2->saved_regs;
  int * v70 = v2->regs;
  int v71 = v70[12];
  v69[12] = v71;
  int v73 = v2->timer;
  int v200 = v73 + 1;
  v2->timer = v200;
  int * v75 = v2->regs;
  int v76 = v75[11];
  int * v77 = v2->cache_keys;
  int v78 = v77[0];
  bool v203 = v78 == ((int)((unsigned int)(v76 + 16) >> 2));
  int v126;
  if (v203) {
    int * v79 = v2->cache_vals;
    int v80 = v79[0];
    v126 = v80;
  } else {
    int * v82 = v2->cache_keys;
    int v83 = v82[1];
    bool v208 = v83 == ((int)((unsigned int)(v76 + 16) >> 2));
    int v124;
    if (v208) {
      int * v84 = v2->cache_vals;
      int v85 = v84[1];
      int * v86 = v2->cache_keys;
      int * v87 = v2->cache_keys;
      int v88 = v87[0];
      v86[1] = v88;
      int * v90 = v2->cache_vals;
      int * v91 = v2->cache_vals;
      int v92 = v91[0];
      v90[1] = v92;
      int * v94 = v2->cache_keys;
      int v217 = (int)((unsigned int)(v76 + 16) >> 2);
      v94[0] = v217;
      int * v96 = v2->cache_vals;
      v96[0] = v85;
      int v98 = v2->timer;
      int v220 = v98 + 1;
      v2->timer = v220;
      v124 = v85;
    } else {
      int * v101 = v2->mem;
      int v222 = (int)((unsigned int)(v76 + 16) >> 2);
      int v102 = v101[v222];
      int * v103 = v2->mem;
      int * v104 = v2->cache_keys;
      int v105 = v104[1];
      int * v106 = v2->cache_vals;
      int v107 = v106[1];
      v103[v105] = v107;
      int * v109 = v2->cache_keys;
      int * v110 = v2->cache_keys;
      int v111 = v110[0];
      v109[1] = v111;
      int * v113 = v2->cache_vals;
      int * v114 = v2->cache_vals;
      int v115 = v114[0];
      v113[1] = v115;
      int * v117 = v2->cache_keys;
      v117[0] = v222;
      int * v119 = v2->cache_vals;
      v119[0] = v102;
      int v121 = v2->timer;
      int v237 = v121 + 100;
      v2->timer = v237;
      v124 = v102;
    }
    v126 = v124;
  }
  int * v127 = v2->regs;
  v127[12] = v126;
  int * v129 = v2->regs;
  int v130 = v129[10];
  bool v242 = v130 == 0;
  if (v242) {
    int v131 = v2->timer;
    int v243 = v131 + 15;
    v2->timer = v243;
    int * v133 = v2->saved_regs;
    int v134 = v133[11];
    int * v135 = v2->regs;
    v135[11] = v134;
    int * v137 = v2->saved_regs;
    int v138 = v137[12];
    int * v139 = v2->regs;
    v139[12] = v138;
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