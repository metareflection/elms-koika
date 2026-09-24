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
struct StateT * slot_1(struct StateT * v15);
struct StateT * slot_6(struct StateT * v73);
struct StateT * slot_5(struct StateT * v104);
struct StateT * slot_4(struct StateT * v86);
struct StateT * slot_2(struct StateT * v36);
struct StateT * slot_7(struct StateT * v99);
struct StateT * slot_3(struct StateT * v49);
struct StateT * slot_0(struct StateT * v2);
struct StateT * snippet(struct StateT * v0) {
  struct StateT * v1 = slot_0(v0);
  return v1;
}

struct StateT * slot_1(struct StateT * v15) {
  int v16 = v15->timer;
  int v26 = v16 + 1;
  v15->timer = v26;
  int * v18 = v15->regs;
  int v19 = v18[12];
  int * v20 = v15->mem;
  int v30 = (int)((unsigned int)v19 >> 2);
  int v21 = v20[v30];
  int * v22 = v15->regs;
  v22[16] = v21;
  struct StateT * v24 = slot_2(v15);
  return v24;
}

struct StateT * slot_6(struct StateT * v73) {
  int v74 = v73->timer;
  int v80 = v74 + 1;
  v73->timer = v80;
  int * v76 = v73->regs;
  v76[18] = 2;
  struct StateT * v78 = slot_7(v73);
  return v78;
}

struct StateT * slot_5(struct StateT * v104) {
  int v105 = v104->timer;
  int v108 = v105 + 1;
  v104->timer = v108;
  return v104;
}

struct StateT * slot_4(struct StateT * v86) {
  int v87 = v86->timer;
  int v93 = v87 + 1;
  v86->timer = v93;
  int * v89 = v86->regs;
  v89[18] = 1;
  struct StateT * v91 = slot_5(v86);
  return v91;
}

struct StateT * slot_2(struct StateT * v36) {
  int v37 = v36->timer;
  int v43 = v37 + 1;
  v36->timer = v43;
  int * v39 = v36->regs;
  v39[17] = 10;
  struct StateT * v41 = slot_3(v36);
  return v41;
}

struct StateT * slot_7(struct StateT * v99) {
  int v100 = v99->timer;
  int v103 = v100 + 1;
  v99->timer = v103;
  return v99;
}

struct StateT * slot_3(struct StateT * v49) {
  int v50 = v49->timer;
  int v62 = v50 + 1;
  v49->timer = v62;
  int * v52 = v49->regs;
  int v53 = v52[16];
  int * v54 = v49->regs;
  int v55 = v54[17];
  bool v67 = v53 < v55;
  struct StateT * v60;
  if (v67) {
    struct StateT * v56 = slot_6(v49);
    v60 = v56;
  } else {
    struct StateT * v58 = slot_4(v49);
    v60 = v58;
  }
  return v60;
}

struct StateT * slot_0(struct StateT * v2) {
  int v3 = v2->timer;
  int v9 = v3 + 1;
  v2->timer = v9;
  int * v5 = v2->regs;
  v5[12] = 80;
  struct StateT * v7 = slot_1(v2);
  return v7;
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