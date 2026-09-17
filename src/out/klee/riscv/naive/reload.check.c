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

struct StateT * slot_6(struct StateT * v129);
struct StateT * slot_5(struct StateT * v108);
struct StateT * slot_2(struct StateT * v28);
struct StateT * slot_7(struct StateT * v145);
struct StateT * slot_3(struct StateT * v41);
struct StateT * snippet(struct StateT * v0);
struct StateT * slot_1(struct StateT * v15);
struct StateT * slot_8(struct StateT * v65);
struct StateT * slot_4(struct StateT * v73);
struct StateT * slot_9(struct StateT * v94);
struct StateT * slot_0(struct StateT * v2);
struct StateT * slot_6(struct StateT * v129) {
  int v130 = v129->timer;
  int v138 = v130 + 1;
  v129->timer = v138;
  int * v132 = v129->regs;
  int v133 = v132[11];
  int * v134 = v129->regs;
  int v142 = v133 << 2;
  v134[11] = v142;
  struct StateT * v136 = slot_7(v129);
  return v136;
}

struct StateT * slot_5(struct StateT * v108) {
  int v109 = v108->timer;
  int v119 = v109 + 1;
  v108->timer = v119;
  int * v111 = v108->regs;
  int v112 = v111[5];
  int * v113 = v108->mem;
  int v123 = (int)((unsigned int)v112 >> 2);
  int v114 = v113[v123];
  int * v115 = v108->regs;
  v115[11] = v114;
  struct StateT * v117 = slot_6(v108);
  return v117;
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

struct StateT * slot_7(struct StateT * v145) {
  int v146 = v145->timer;
  int v156 = v146 + 1;
  v145->timer = v156;
  int * v148 = v145->regs;
  int v149 = v148[11];
  int * v150 = v145->mem;
  int v160 = (int)((unsigned int)v149 >> 2);
  int v151 = v150[v160];
  int * v152 = v145->regs;
  v152[12] = v151;
  struct StateT * v154 = slot_8(v145);
  return v154;
}

struct StateT * slot_3(struct StateT * v41) {
  int v42 = v41->timer;
  int v54 = v42 + 1;
  v41->timer = v54;
  int * v44 = v41->regs;
  int v45 = v44[10];
  int * v46 = v41->regs;
  int v47 = v46[15];
  bool v59 = v45 >= v47;
  struct StateT * v52;
  if (v59) {
    struct StateT * v48 = slot_8(v41);
    v52 = v48;
  } else {
    struct StateT * v50 = slot_4(v41);
    v52 = v50;
  }
  return v52;
}

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

struct StateT * slot_8(struct StateT * v65) {
  int v66 = v65->timer;
  int v70 = v66 + 1;
  v65->timer = v70;
  struct StateT * v68 = slot_9(v65);
  return v68;
}

struct StateT * slot_4(struct StateT * v73) {
  int v74 = v73->timer;
  int v84 = v74 + 1;
  v73->timer = v84;
  int * v76 = v73->regs;
  int v77 = v76[13];
  int * v78 = v73->regs;
  int v79 = v78[10];
  int * v80 = v73->regs;
  int v91 = v77 + v79;
  v80[5] = v91;
  struct StateT * v82 = slot_5(v73);
  return v82;
}

struct StateT * slot_9(struct StateT * v94) {
  int v95 = v94->timer;
  int v102 = v95 + 1;
  v94->timer = v102;
  int * v97 = v94->mem;
  int v98 = v97[0];
  int * v99 = v94->regs;
  v99[14] = v98;
  return v94;
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