// verify: clean (CBMC should report VERIFICATION SUCCESSFUL)

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
struct StateT * v8(struct StateT * v9);
struct StateT * v18(struct StateT * v19);
struct StateT * v26(struct StateT * v27);
struct StateT * snippet(struct StateT * v0) {
  struct StateT * v77 = v1(v0);
  return v77;
}

struct StateT * v1(struct StateT * v2) {
  int v3 = v2->timer;
  int v70 = v3 + 1;
  v2->timer = v70;
  int * v5 = v2->regs;
  int v6 = v5[10];
  bool v73 = v6 == 0;
  struct StateT * v68;
  if (v73) {
    v68 = v2;
  } else {
    struct StateT * v66 = v8(v2);
    v68 = v66;
  }
  return v68;
}

struct StateT * v8(struct StateT * v9) {
  int v10 = v9->timer;
  int v56 = v10 + 1;
  v9->timer = v56;
  int * v12 = v9->regs;
  int v13 = v12[10];
  int * v14 = v9->mem;
  int v60 = (int)((unsigned int)v13 >> 2);
  int v15 = v14[v60];
  int * v16 = v9->regs;
  v16[11] = v15;
  struct StateT * v54 = v18(v9);
  return v54;
}

struct StateT * v18(struct StateT * v19) {
  int v20 = v19->timer;
  int v47 = v20 + 1;
  v19->timer = v47;
  int * v22 = v19->regs;
  int v23 = v22[11];
  int * v24 = v19->regs;
  int v51 = v23 << 2;
  v24[11] = v51;
  struct StateT * v45 = v26(v19);
  return v45;
}

struct StateT * v26(struct StateT * v27) {
  int v28 = v27->timer;
  int v37 = v28 + 1;
  v27->timer = v37;
  int * v30 = v27->regs;
  int v31 = v30[11];
  int * v32 = v27->mem;
  int v41 = (int)((unsigned int)(v31 + 16) >> 2);
  int v33 = v32[v41];
  int * v34 = v27->regs;
  v34[12] = v33;
  return v27;
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