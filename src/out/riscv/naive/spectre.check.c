
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
struct StateT {
  int regs[NUM_REGS];
  int mem[MEM_SIZE];
  int saved_regs[NUM_REGS];
  int cache_keys[CACHE_LRU_SIZE];
  int cache_vals[CACHE_LRU_SIZE];
  int timer;
};

void init(struct StateT *s) {
  for (int i=0; i<NUM_REGS; i++) {
    s->regs[i] = 0;
  }
  s->timer = 0;
  for (int i=0; i<MEM_SIZE; i++) {
    s->mem[i] = 0;
  }
}

/*****************************************
Emitting C Generated Code
*******************************************/

#include <stdbool.h>
#include <stdlib.h>

struct StateT * snippet(struct StateT * v0);
struct StateT * v19(struct StateT * v20);
struct StateT * v1(struct StateT * v2);
struct StateT * v48(struct StateT * v49);
struct StateT * v38(struct StateT * v39);
struct StateT * v56(struct StateT * v57);
struct StateT * v7(struct StateT * v8);
struct StateT * v13(struct StateT * v14);
struct StateT * v28(struct StateT * v29);
struct StateT * snippet(struct StateT * v0) {
  struct StateT * v145 = v1(v0);
  return v145;
}

struct StateT * v19(struct StateT * v20) {
  int v21 = v20->timer;
  int v112 = v21 + 1;
  v20->timer = v112;int * v23 = v20->regs;
  int v24 = v23[10];
  int * v25 = v20->regs;
  int v26 = v25[15];
  bool v117 = v24 >= v26;
  struct StateT * v110 = (v117 ? v20 : ({
    struct StateT * v108 = v28(v20);
    v108;
  }));
  return v110;
}

struct StateT * v1(struct StateT * v2) {
  int v3 = v2->timer;
  int v139 = v3 + 1;
  v2->timer = v139;int * v5 = v2->regs;
  v5[13] = 0;
  struct StateT * v137 = v7(v2);
  return v137;
}

struct StateT * v48(struct StateT * v49) {
  int v50 = v49->timer;
  int v77 = v50 + 1;
  v49->timer = v77;int * v52 = v49->regs;
  int v53 = v52[11];
  int * v54 = v49->regs;
  int v81 = v53 << 2;
  v54[11] = v81;
  struct StateT * v75 = v56(v49);
  return v75;
}

struct StateT * v38(struct StateT * v39) {
  int v40 = v39->timer;
  int v86 = v40 + 1;
  v39->timer = v86;int * v42 = v39->regs;
  int v43 = v42[5];
  int * v44 = v39->mem;
  int v90 = (int)((unsigned int)v43 >> 2);
  int v45 = v44[v90];
  int * v46 = v39->regs;
  v46[11] = v45;
  struct StateT * v84 = v48(v39);
  return v84;
}

struct StateT * v56(struct StateT * v57) {
  int v58 = v57->timer;
  int v67 = v58 + 1;
  v57->timer = v67;int * v60 = v57->regs;
  int v61 = v60[11];
  int * v62 = v57->mem;
  int v71 = (int)((unsigned int)v61 >> 2);
  int v63 = v62[v71];
  int * v64 = v57->regs;
  v64[12] = v63;
  return v57;
}

struct StateT * v7(struct StateT * v8) {
  int v9 = v8->timer;
  int v131 = v9 + 1;
  v8->timer = v131;int * v11 = v8->regs;
  v11[10] = 80;
  struct StateT * v129 = v13(v8);
  return v129;
}

struct StateT * v13(struct StateT * v14) {
  int v15 = v14->timer;
  int v123 = v15 + 1;
  v14->timer = v123;int * v17 = v14->regs;
  v17[15] = 80;
  struct StateT * v121 = v19(v14);
  return v121;
}

struct StateT * v28(struct StateT * v29) {
  int v30 = v29->timer;
  int v98 = v30 + 1;
  v29->timer = v98;int * v32 = v29->regs;
  int v33 = v32[13];
  int * v34 = v29->regs;
  int v35 = v34[10];
  int * v36 = v29->regs;
  int v105 = v33 + v35;
  v36[5] = v105;
  struct StateT * v96 = v38(v29);
  return v96;
}



/*****************************************
End of C Generated Code
*******************************************/

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