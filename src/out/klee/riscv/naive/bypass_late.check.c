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
struct StateT * slot_1(struct StateT * v19);
struct StateT * slot_8(struct StateT * v141);
struct StateT * slot_6(struct StateT * v104);
struct StateT * slot_5(struct StateT * v83);
struct StateT * slot_4(struct StateT * v70);
struct StateT * slot_2(struct StateT * v32);
struct StateT * slot_7(struct StateT * v125);
struct StateT * slot_3(struct StateT * v53);
struct StateT * slot_0(struct StateT * v2);
struct StateT * snippet(struct StateT * v0) {
  struct StateT * v1 = slot_0(v0);
  return v1;
}

struct StateT * slot_1(struct StateT * v19) {
  int v20 = v19->timer;
  int v26 = v20 + 1;
  v19->timer = v26;
  int * v22 = v19->regs;
  v22[9] = 32;
  struct StateT * v24 = slot_2(v19);
  return v24;
}

struct StateT * slot_8(struct StateT * v141) {
  int v142 = v141->timer;
  int v151 = v142 + 1;
  v141->timer = v151;
  int * v144 = v141->regs;
  int v145 = v144[11];
  int * v146 = v141->mem;
  int v155 = (int)((unsigned int)v145 >> 2);
  int v147 = v146[v155];
  int * v148 = v141->regs;
  v148[12] = v147;
  return v141;
}

struct StateT * slot_6(struct StateT * v104) {
  int v105 = v104->timer;
  int v115 = v105 + 1;
  v104->timer = v115;
  int * v107 = v104->regs;
  int v108 = v107[6];
  int * v109 = v104->mem;
  int v119 = (int)((unsigned int)v108 >> 2);
  int v110 = v109[v119];
  int * v111 = v104->regs;
  v111[11] = v110;
  struct StateT * v113 = slot_7(v104);
  return v113;
}

struct StateT * slot_5(struct StateT * v83) {
  int v84 = v83->timer;
  int v94 = v84 + 1;
  v83->timer = v94;
  int * v86 = v83->regs;
  int v87 = v86[6];
  int * v88 = v83->regs;
  int v89 = v88[7];
  int * v90 = v83->mem;
  int v100 = (int)((unsigned int)v87 >> 2);
  v90[v100] = v89;
  struct StateT * v92 = slot_6(v83);
  return v92;
}

struct StateT * slot_4(struct StateT * v70) {
  int v71 = v70->timer;
  int v77 = v71 + 1;
  v70->timer = v77;
  int * v73 = v70->regs;
  v73[7] = 0;
  struct StateT * v75 = slot_5(v70);
  return v75;
}

struct StateT * slot_2(struct StateT * v32) {
  int v33 = v32->timer;
  int v44 = v33 + 1;
  v32->timer = v44;
  int * v35 = v32->regs;
  int v36 = v35[5];
  int * v37 = v32->regs;
  int v38 = v37[9];
  bool v49 = v36 >= v38;
  struct StateT * v42;
  if (v49) {
    v42 = v32;
  } else {
    struct StateT * v40 = slot_3(v32);
    v42 = v40;
  }
  return v42;
}

struct StateT * slot_7(struct StateT * v125) {
  int v126 = v125->timer;
  int v134 = v126 + 1;
  v125->timer = v134;
  int * v128 = v125->regs;
  int v129 = v128[11];
  int * v130 = v125->regs;
  int v138 = v129 << 2;
  v130[11] = v138;
  struct StateT * v132 = slot_8(v125);
  return v132;
}

struct StateT * slot_3(struct StateT * v53) {
  int v54 = v53->timer;
  int v62 = v54 + 1;
  v53->timer = v62;
  int * v56 = v53->regs;
  int v57 = v56[5];
  int * v58 = v53->regs;
  int v67 = v57 + 80;
  v58[6] = v67;
  struct StateT * v60 = slot_4(v53);
  return v60;
}

struct StateT * slot_0(struct StateT * v2) {
  int v3 = v2->timer;
  int v11 = v3 + 1;
  v2->timer = v11;
  int * v5 = v2->regs;
  int v6 = v5[10];
  int * v7 = v2->regs;
  int v16 = v6 & 28;
  v7[5] = v16;
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