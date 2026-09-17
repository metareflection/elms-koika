// verify: clean (KLEE should report no failing assertion) [budget 1200s]
#define NUM_REGS 32
#define MEM_SIZE 64
#define SECRET_SIZE 10
#define SECRET_OFFSET 20
#define CACHE_ENTRIES 12
#define CACHE_WORDS 24

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
  int mem[64];
  int saved_regs[32];
  int reg_ready[32];
  int cache_tags[12];
  int cache_dirty[12];
  int cache_age[12];
  int cache_vals[24];
  int timer;
};

struct StateT * snippet(struct StateT * v0);
struct StateT * slot_1(struct StateT * v18);
struct StateT * slot_5(struct StateT * v94);
struct StateT * slot_4(struct StateT * v74);
struct StateT * slot_2(struct StateT * v34);
struct StateT * slot_3(struct StateT * v54);
struct StateT * slot_0(struct StateT * v2);
struct StateT * snippet(struct StateT * v0) {
  struct StateT * v1 = slot_0(v0);
  return v1;
}

struct StateT * slot_1(struct StateT * v18) {
  int v19 = v18->timer;
  int v27 = v19 + 1;
  v18->timer = v27;
  int * v21 = v18->regs;
  int v22 = v21[10];
  int * v23 = v18->regs;
  int v31 = v22 >> 31;
  v23[10] = v31;
  struct StateT * v25 = slot_2(v18);
  return v25;
}

struct StateT * slot_5(struct StateT * v94) {
  int v95 = v94->timer;
  int v98 = v95 + 1;
  v94->timer = v98;
  return v94;
}

struct StateT * slot_4(struct StateT * v74) {
  int v75 = v74->timer;
  int v85 = v75 + 1;
  v74->timer = v85;
  int * v77 = v74->regs;
  int v78 = v77[11];
  int * v79 = v74->regs;
  int v80 = v79[10];
  int * v81 = v74->regs;
  int v91 = v78 ^ v80;
  v81[10] = v91;
  struct StateT * v83 = slot_5(v74);
  return v83;
}

struct StateT * slot_2(struct StateT * v34) {
  int v35 = v34->timer;
  int v45 = v35 + 1;
  v34->timer = v45;
  int * v37 = v34->regs;
  int v38 = v37[12];
  int * v39 = v34->regs;
  int v40 = v39[11];
  int * v41 = v34->regs;
  int v51 = v38 ^ v40;
  v41[12] = v51;
  struct StateT * v43 = slot_3(v34);
  return v43;
}

struct StateT * slot_3(struct StateT * v54) {
  int v55 = v54->timer;
  int v65 = v55 + 1;
  v54->timer = v65;
  int * v57 = v54->regs;
  int v58 = v57[10];
  int * v59 = v54->regs;
  int v60 = v59[12];
  int * v61 = v54->regs;
  int v71 = v58 & v60;
  v61[10] = v71;
  struct StateT * v63 = slot_4(v54);
  return v63;
}

struct StateT * slot_0(struct StateT * v2) {
  int v3 = v2->timer;
  int v11 = v3 + 1;
  v2->timer = v11;
  int * v5 = v2->regs;
  int v6 = v5[10];
  int * v7 = v2->regs;
  int v15 = v6 << 31;
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
  for (int i=0; i<CACHE_ENTRIES; i++) {
    s->cache_tags[i] = -1;
    s->cache_dirty[i] = 0;
    s->cache_age[i] = 0;
  }
  for (int i=0; i<CACHE_WORDS; i++) {
    s->cache_vals[i] = 0;
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