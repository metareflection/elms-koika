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
  int cache_tags[12];
  int cache_dirty[12];
  int cache_age[12];
  int cache_vals[24];
  int timer;
};

struct StateT * snippet(struct StateT * v0);
struct StateT * slot_1(struct StateT * v19);
struct StateT * slot_6(struct StateT * v102);
struct StateT * slot_5(struct StateT * v85);
struct StateT * slot_4(struct StateT * v68);
struct StateT * slot_2(struct StateT * v36);
struct StateT * slot_7(struct StateT * v123);
struct StateT * slot_3(struct StateT * v52);
struct StateT * slot_0(struct StateT * v2);
struct StateT * snippet(struct StateT * v0) {
  struct StateT * v1 = slot_0(v0);
  return v1;
}

struct StateT * slot_1(struct StateT * v19) {
  int v20 = v19->timer;
  int v28 = v20 + 1;
  v19->timer = v28;
  int * v22 = v19->regs;
  int v23 = v22[5];
  int * v24 = v19->regs;
  int v33 = v23 & 1;
  v24[6] = v33;
  struct StateT * v26 = slot_2(v19);
  return v26;
}

struct StateT * slot_6(struct StateT * v102) {
  int v103 = v102->timer;
  int v113 = v103 + 1;
  v102->timer = v113;
  int * v105 = v102->regs;
  int v106 = v105[6];
  int * v107 = v102->mem;
  int v117 = (int)((unsigned int)v106 >> 2);
  int v108 = v107[v117];
  int * v109 = v102->regs;
  v109[9] = v108;
  struct StateT * v111 = slot_7(v102);
  return v111;
}

struct StateT * slot_5(struct StateT * v85) {
  int v86 = v85->timer;
  int v94 = v86 + 1;
  v85->timer = v94;
  int * v88 = v85->mem;
  int v89 = v88[4];
  int * v90 = v85->regs;
  v90[8] = v89;
  struct StateT * v92 = slot_6(v85);
  return v92;
}

struct StateT * slot_4(struct StateT * v68) {
  int v69 = v68->timer;
  int v77 = v69 + 1;
  v68->timer = v77;
  int * v71 = v68->mem;
  int v72 = v71[0];
  int * v73 = v68->regs;
  v73[7] = v72;
  struct StateT * v75 = slot_5(v68);
  return v75;
}

struct StateT * slot_2(struct StateT * v36) {
  int v37 = v36->timer;
  int v45 = v37 + 1;
  v36->timer = v45;
  int * v39 = v36->regs;
  int v40 = v39[6];
  int * v41 = v36->regs;
  int v49 = v40 << 3;
  v41[6] = v49;
  struct StateT * v43 = slot_3(v36);
  return v43;
}

struct StateT * slot_7(struct StateT * v123) {
  int v124 = v123->timer;
  int v131 = v124 + 1;
  v123->timer = v131;
  int * v126 = v123->mem;
  int v127 = v126[0];
  int * v128 = v123->regs;
  v128[11] = v127;
  return v123;
}

struct StateT * slot_3(struct StateT * v52) {
  int v53 = v52->timer;
  int v61 = v53 + 1;
  v52->timer = v61;
  int * v55 = v52->regs;
  int v56 = v55[6];
  int * v57 = v52->regs;
  int v65 = v56 + 32;
  v57[6] = v65;
  struct StateT * v59 = slot_4(v52);
  return v59;
}

struct StateT * slot_0(struct StateT * v2) {
  int v3 = v2->timer;
  int v11 = v3 + 1;
  v2->timer = v11;
  int * v5 = v2->mem;
  int v6 = v5[20];
  int * v7 = v2->regs;
  v7[5] = v6;
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