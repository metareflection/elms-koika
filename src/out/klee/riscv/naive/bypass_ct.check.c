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
struct StateT * slot_1(struct StateT * v19);
struct StateT * slot_6(struct StateT * v106);
struct StateT * slot_5(struct StateT * v90);
struct StateT * slot_4(struct StateT * v69);
struct StateT * slot_2(struct StateT * v35);
struct StateT * slot_3(struct StateT * v48);
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
  int v23 = v22[6];
  int * v24 = v19->regs;
  int v32 = v23 + 80;
  v24[6] = v32;
  struct StateT * v26 = slot_2(v19);
  return v26;
}

struct StateT * slot_6(struct StateT * v106) {
  int v107 = v106->timer;
  int v116 = v107 + 1;
  v106->timer = v116;
  int * v109 = v106->regs;
  int v110 = v109[6];
  int * v111 = v106->mem;
  int v120 = (int)((unsigned int)v110 >> 2);
  int v112 = v111[v120];
  int * v113 = v106->regs;
  v113[12] = v112;
  return v106;
}

struct StateT * slot_5(struct StateT * v90) {
  int v91 = v90->timer;
  int v99 = v91 + 1;
  v90->timer = v99;
  int * v93 = v90->regs;
  int v94 = v93[11];
  int * v95 = v90->regs;
  int v103 = v94 << 2;
  v95[11] = v103;
  struct StateT * v97 = slot_6(v90);
  return v97;
}

struct StateT * slot_4(struct StateT * v69) {
  int v70 = v69->timer;
  int v80 = v70 + 1;
  v69->timer = v80;
  int * v72 = v69->regs;
  int v73 = v72[6];
  int * v74 = v69->mem;
  int v84 = (int)((unsigned int)v73 >> 2);
  int v75 = v74[v84];
  int * v76 = v69->regs;
  v76[11] = v75;
  struct StateT * v78 = slot_5(v69);
  return v78;
}

struct StateT * slot_2(struct StateT * v35) {
  int v36 = v35->timer;
  int v42 = v36 + 1;
  v35->timer = v42;
  int * v38 = v35->regs;
  v38[7] = 0;
  struct StateT * v40 = slot_3(v35);
  return v40;
}

struct StateT * slot_3(struct StateT * v48) {
  int v49 = v48->timer;
  int v59 = v49 + 1;
  v48->timer = v59;
  int * v51 = v48->regs;
  int v52 = v51[6];
  int * v53 = v48->regs;
  int v54 = v53[7];
  int * v55 = v48->mem;
  int v65 = (int)((unsigned int)v52 >> 2);
  v55[v65] = v54;
  struct StateT * v57 = slot_4(v48);
  return v57;
}

struct StateT * slot_0(struct StateT * v2) {
  int v3 = v2->timer;
  int v11 = v3 + 1;
  v2->timer = v11;
  int * v5 = v2->regs;
  int v6 = v5[10];
  int * v7 = v2->regs;
  int v16 = v6 & 28;
  v7[6] = v16;
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