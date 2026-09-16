// verify: leak (CBMC should report VERIFICATION FAILED) [unwind 65]
#define NUM_REGS 32
#define MEM_SIZE 64
#define SECRET_SIZE 10
#define SECRET_OFFSET 20
#define CACHE_ENTRIES 12
#define CACHE_WORDS 24

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
  int cache_tags[12];
  int cache_dirty[12];
  int cache_age[12];
  int cache_vals[24];
  int timer;
};

struct StateT * snippet(struct StateT * v0);
struct StateT * slot_1(struct StateT * v18);
struct StateT * slot_4(struct StateT * v72);
struct StateT * slot_2(struct StateT * v55);
struct StateT * slot_3(struct StateT * v38);
struct StateT * slot_0(struct StateT * v2);
struct StateT * snippet(struct StateT * v0) {
  struct StateT * v1 = slot_0(v0);
  return v1;
}

struct StateT * slot_1(struct StateT * v18) {
  int v19 = v18->timer;
  int v29 = v19 + 1;
  v18->timer = v29;
  int * v21 = v18->regs;
  int v22 = v21[10];
  bool v32 = !(v22 == 0);
  struct StateT * v27;
  if (v32) {
    struct StateT * v23 = slot_3(v18);
    v27 = v23;
  } else {
    struct StateT * v25 = slot_2(v18);
    v27 = v25;
  }
  return v27;
}

struct StateT * slot_4(struct StateT * v72) {
  int v73 = v72->timer;
  int v76 = v73 + 1;
  v72->timer = v76;
  return v72;
}

struct StateT * slot_2(struct StateT * v55) {
  int v56 = v55->timer;
  int v64 = v56 + 1;
  v55->timer = v64;
  int * v58 = v55->regs;
  int v59 = v58[11];
  int * v60 = v55->regs;
  v60[12] = v59;
  struct StateT * v62 = slot_3(v55);
  return v62;
}

struct StateT * slot_3(struct StateT * v38) {
  int v39 = v38->timer;
  int v47 = v39 + 1;
  v38->timer = v47;
  int * v41 = v38->regs;
  int v42 = v41[12];
  int * v43 = v38->regs;
  v43[10] = v42;
  struct StateT * v45 = slot_4(v38);
  return v45;
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
  }
  s->regs[2] = 4 * MEM_SIZE;
  s->timer = 0;
  for (int i=0; i<MEM_SIZE; i++) {
    s->mem[i] = 0;
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