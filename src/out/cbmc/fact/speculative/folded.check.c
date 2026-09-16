// verify: leak (CBMC should report VERIFICATION FAILED) [unwind 65]
#define NUM_REGS 32
#define MEM_SIZE 64
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
  int mem[64];
  int saved_regs[32];
  int cache_keys[10];
  int cache_vals[10];
  int timer;
};

struct StateT * snippet(struct StateT * v0);
struct StateT * slot_1(struct StateT * v18);
struct StateT * slot_4(struct StateT * v78);
struct StateT * slot_3(struct StateT * v61);
struct StateT * slot_0(struct StateT * v2);
struct StateT * snippet(struct StateT * v0) {
  struct StateT * v1 = slot_0(v0);
  return v1;
}

struct StateT * slot_1(struct StateT * v18) {
  int * v19 = v18->saved_regs;
  int * v20 = v18->regs;
  int v21 = v20[12];
  v19[12] = v21;
  int v23 = v18->timer;
  int v46 = v23 + 1;
  v18->timer = v46;
  int * v25 = v18->regs;
  int v26 = v25[11];
  int * v27 = v18->regs;
  v27[12] = v26;
  int * v29 = v18->regs;
  int v30 = v29[10];
  bool v53 = !(v30 == 0);
  if (v53) {
    int v31 = v18->timer;
    int v54 = v31 + 15;
    v18->timer = v54;
    int * v33 = v18->saved_regs;
    int v34 = v33[12];
    int * v35 = v18->regs;
    v35[12] = v34;
    struct StateT * v37 = slot_3(v18);
    ;
  } else {
    ;
  }
  return v18;
}

struct StateT * slot_4(struct StateT * v78) {
  int v79 = v78->timer;
  int v82 = v79 + 1;
  v78->timer = v82;
  return v78;
}

struct StateT * slot_3(struct StateT * v61) {
  int v62 = v61->timer;
  int v70 = v62 + 1;
  v61->timer = v70;
  int * v64 = v61->regs;
  int v65 = v64[12];
  int * v66 = v61->regs;
  v66[10] = v65;
  struct StateT * v68 = slot_4(v61);
  return v68;
}

struct StateT * slot_0(struct StateT * v2) {
  int v3 = v2->timer;
  int v11 = v3 + 1;
  v2->timer = v11;
  int * v5 = v2->regs;
  int v6 = v5[10];
  int * v7 = v2->regs;
  int v15 = v6 & 1;
  v7[10] = v15;
  struct StateT * v9 = slot_1(v2);
  return v9;
}



/*****************************************
End of C Generated Code
*******************************************/

void init(struct StateT *s) {
  for (int i=0; i<NUM_REGS; i++) {
    s->regs[i] = 0;
    s->saved_regs[i] = 0;
  }
  s->regs[2] = 4 * MEM_SIZE;
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
  
  // a11, public: one draw, written into both states
  int a11 = bounded(0, 20);
  s1.regs[11] = a11;
  s2.regs[11] = a11;
  // a12, public: one draw, written into both states
  int a12 = bounded(0, 20);
  s1.regs[12] = a12;
  s2.regs[12] = a12;
  
  // a10, secret: a different draw in each state
  s1.regs[10] = bounded(0, 1);
  s2.regs[10] = bounded(0, 1);
  struct StateT *s1_ = snippet(&s1);
  struct StateT *s2_ = snippet(&s2);
  koika_assert(s1_->timer==s2_->timer, "timing leak");
  return 0;
}