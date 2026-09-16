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
struct StateT * slot_8(struct StateT * v133);
struct StateT * slot_6(struct StateT * v96);
struct StateT * slot_5(struct StateT * v83);
struct StateT * slot_4(struct StateT * v62);
struct StateT * slot_2(struct StateT * v36);
struct StateT * slot_7(struct StateT * v112);
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
  int v19 = v18[6];
  int * v20 = v15->mem;
  int v30 = (int)((unsigned int)v19 >> 2);
  int v21 = v20[v30];
  int * v22 = v15->regs;
  v22[5] = v21;
  struct StateT * v24 = slot_2(v15);
  return v24;
}

struct StateT * slot_8(struct StateT * v133) {
  int v134 = v133->timer;
  int v143 = v134 + 1;
  v133->timer = v143;
  int * v136 = v133->regs;
  int v137 = v136[11];
  int * v138 = v133->mem;
  int v147 = (int)((unsigned int)v137 >> 2);
  int v139 = v138[v147];
  int * v140 = v133->regs;
  v140[12] = v139;
  return v133;
}

struct StateT * slot_6(struct StateT * v96) {
  int v97 = v96->timer;
  int v105 = v97 + 1;
  v96->timer = v105;
  int * v99 = v96->regs;
  int v100 = v99[7];
  int * v101 = v96->regs;
  int v109 = v100 + 1;
  v101[7] = v109;
  struct StateT * v103 = slot_7(v96);
  return v103;
}

struct StateT * slot_5(struct StateT * v83) {
  int v84 = v83->timer;
  int v90 = v84 + 1;
  v83->timer = v90;
  int * v86 = v83->regs;
  v86[7] = 0;
  struct StateT * v88 = slot_6(v83);
  return v88;
}

struct StateT * slot_4(struct StateT * v62) {
  int v63 = v62->timer;
  int v73 = v63 + 1;
  v62->timer = v73;
  int * v65 = v62->regs;
  int v66 = v65[8];
  int * v67 = v62->regs;
  int v68 = v67[5];
  int * v69 = v62->mem;
  int v79 = (int)((unsigned int)v66 >> 2);
  v69[v79] = v68;
  struct StateT * v71 = slot_5(v62);
  return v71;
}

struct StateT * slot_2(struct StateT * v36) {
  int v37 = v36->timer;
  int v43 = v37 + 1;
  v36->timer = v43;
  int * v39 = v36->regs;
  v39[8] = 96;
  struct StateT * v41 = slot_3(v36);
  return v41;
}

struct StateT * slot_7(struct StateT * v112) {
  int v113 = v112->timer;
  int v123 = v113 + 1;
  v112->timer = v123;
  int * v115 = v112->regs;
  int v116 = v115[9];
  int * v117 = v112->mem;
  int v127 = (int)((unsigned int)v116 >> 2);
  int v118 = v117[v127];
  int * v119 = v112->regs;
  v119[11] = v118;
  struct StateT * v121 = slot_8(v112);
  return v121;
}

struct StateT * slot_3(struct StateT * v49) {
  int v50 = v49->timer;
  int v56 = v50 + 1;
  v49->timer = v56;
  int * v52 = v49->regs;
  v52[9] = 0;
  struct StateT * v54 = slot_4(v49);
  return v54;
}

struct StateT * slot_0(struct StateT * v2) {
  int v3 = v2->timer;
  int v9 = v3 + 1;
  v2->timer = v9;
  int * v5 = v2->regs;
  v5[6] = 80;
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