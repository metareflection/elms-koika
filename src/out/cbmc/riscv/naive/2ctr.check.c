// verify: clean (CBMC should report VERIFICATION SUCCESSFUL) [unwind 33]
#define NUM_REGS 32
#define MEM_SIZE 30
#define SECRET_SIZE 10
#define SECRET_OFFSET 20
#define CACHE_LRU_SIZE 10

#ifdef CBMC
int nondet_uint();
#define koika_assert(b, s) __CPROVER_assert(b, s)
#define koika_assume(b) __CPROVER_assume(b)
#define koika_draw(x) ((x) = nondet_uint())
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
struct StateT * slot_1(struct StateT * v19);
struct StateT * slot_2(struct StateT * v40);
struct StateT * slot_3(struct StateT * v56);
struct StateT * slot_0(struct StateT * v2);
struct StateT * snippet(struct StateT * v0) {
  struct StateT * v1 = slot_0(v0);
  return v1;
}

struct StateT * slot_1(struct StateT * v19) {
  int v20 = v19->timer;
  int v30 = v20 + 1;
  v19->timer = v30;
  int * v22 = v19->regs;
  int v23 = v22[10];
  int * v24 = v19->mem;
  int v34 = (int)((unsigned int)v23 >> 2);
  int v25 = v24[v34];
  int * v26 = v19->regs;
  v26[11] = v25;
  struct StateT * v28 = slot_2(v19);
  return v28;
}

struct StateT * slot_2(struct StateT * v40) {
  int v41 = v40->timer;
  int v49 = v41 + 1;
  v40->timer = v49;
  int * v43 = v40->regs;
  int v44 = v43[11];
  int * v45 = v40->regs;
  int v53 = v44 << 2;
  v45[11] = v53;
  struct StateT * v47 = slot_3(v40);
  return v47;
}

struct StateT * slot_3(struct StateT * v56) {
  int v57 = v56->timer;
  int v66 = v57 + 1;
  v56->timer = v66;
  int * v59 = v56->regs;
  int v60 = v59[11];
  int * v61 = v56->mem;
  int v70 = (int)((unsigned int)(v60 + 16) >> 2);
  int v62 = v61[v70];
  int * v63 = v56->regs;
  v63[12] = v62;
  return v56;
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