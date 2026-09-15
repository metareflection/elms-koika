// verify: clean (KLEE should report no failing assertion) [budget 120s]
#define NUM_REGS 32
#define MEM_SIZE 30
#define SECRET_SIZE 10
#define SECRET_OFFSET 20
#define CACHE_LRU_SIZE 10

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
  int mem[30];
  int saved_regs[32];
  int cache_keys[10];
  int cache_vals[10];
  int timer;
};

struct StateT * snippet(struct StateT * v0);
struct StateT * slot_1(struct StateT * v15);
struct StateT * slot_6(struct StateT * v104);
struct StateT * slot_5(struct StateT * v83);
struct StateT * slot_4(struct StateT * v62);
struct StateT * slot_2(struct StateT * v28);
struct StateT * slot_7(struct StateT * v120);
struct StateT * slot_3(struct StateT * v41);
struct StateT * slot_0(struct StateT * v2);
struct StateT * snippet(struct StateT * v0) {
  struct StateT * v1 = slot_0(v0);
  return v1;
}

struct StateT * slot_1(struct StateT * v15) {
  int v16 = v15->timer;
  int v22 = v16 + 1;
  v15->timer = v22;
  int * v18 = v15->regs;
  v18[10] = 80;
  struct StateT * v20 = slot_2(v15);
  return v20;
}

struct StateT * slot_6(struct StateT * v104) {
  int v105 = v104->timer;
  int v113 = v105 + 1;
  v104->timer = v113;
  int * v107 = v104->regs;
  int v108 = v107[11];
  int * v109 = v104->regs;
  int v117 = v108 << 2;
  v109[11] = v117;
  struct StateT * v111 = slot_7(v104);
  return v111;
}

struct StateT * slot_5(struct StateT * v83) {
  int v84 = v83->timer;
  int v94 = v84 + 1;
  v83->timer = v94;
  int * v86 = v83->regs;
  int v87 = v86[5];
  int * v88 = v83->mem;
  int v98 = (int)((unsigned int)v87 >> 2);
  int v89 = v88[v98];
  int * v90 = v83->regs;
  v90[11] = v89;
  struct StateT * v92 = slot_6(v83);
  return v92;
}

struct StateT * slot_4(struct StateT * v62) {
  int v63 = v62->timer;
  int v73 = v63 + 1;
  v62->timer = v73;
  int * v65 = v62->regs;
  int v66 = v65[13];
  int * v67 = v62->regs;
  int v68 = v67[10];
  int * v69 = v62->regs;
  int v80 = v66 + v68;
  v69[5] = v80;
  struct StateT * v71 = slot_5(v62);
  return v71;
}

struct StateT * slot_2(struct StateT * v28) {
  int v29 = v28->timer;
  int v35 = v29 + 1;
  v28->timer = v35;
  int * v31 = v28->regs;
  v31[15] = 80;
  struct StateT * v33 = slot_3(v28);
  return v33;
}

struct StateT * slot_7(struct StateT * v120) {
  int v121 = v120->timer;
  int v130 = v121 + 1;
  v120->timer = v130;
  int * v123 = v120->regs;
  int v124 = v123[11];
  int * v125 = v120->mem;
  int v134 = (int)((unsigned int)v124 >> 2);
  int v126 = v125[v134];
  int * v127 = v120->regs;
  v127[12] = v126;
  return v120;
}

struct StateT * slot_3(struct StateT * v41) {
  int v42 = v41->timer;
  int v53 = v42 + 1;
  v41->timer = v53;
  int * v44 = v41->regs;
  int v45 = v44[10];
  int * v46 = v41->regs;
  int v47 = v46[15];
  bool v58 = v45 >= v47;
  struct StateT * v51;
  if (v58) {
    v51 = v41;
  } else {
    struct StateT * v49 = slot_4(v41);
    v51 = v49;
  }
  return v51;
}

struct StateT * slot_0(struct StateT * v2) {
  int v3 = v2->timer;
  int v9 = v3 + 1;
  v2->timer = v9;
  int * v5 = v2->regs;
  v5[13] = 0;
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