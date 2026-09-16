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
struct StateT * slot_6(struct StateT * v112);
struct StateT * slot_5(struct StateT * v95);
struct StateT * slot_4(struct StateT * v78);
struct StateT * slot_2(struct StateT * v26);
struct StateT * slot_7(struct StateT * v117);
struct StateT * slot_3(struct StateT * v50);
struct StateT * slot_0(struct StateT * v2);
struct StateT * snippet(struct StateT * v0) {
  struct StateT * v1 = slot_0(v0);
  return v1;
}

struct StateT * slot_1(struct StateT * v18) {
  int v19 = v18->timer;
  int v23 = v19 + 1;
  v18->timer = v23;
  struct StateT * v21 = slot_2(v18);
  return v21;
}

struct StateT * slot_6(struct StateT * v112) {
  int v113 = v112->timer;
  int v116 = v113 + 1;
  v112->timer = v116;
  return v112;
}

struct StateT * slot_5(struct StateT * v95) {
  int v96 = v95->timer;
  int v104 = v96 + 1;
  v95->timer = v104;
  int * v98 = v95->regs;
  int v99 = v98[12];
  int * v100 = v95->regs;
  v100[10] = v99;
  struct StateT * v102 = slot_7(v95);
  return v102;
}

struct StateT * slot_4(struct StateT * v78) {
  int v79 = v78->timer;
  int v87 = v79 + 1;
  v78->timer = v87;
  int * v81 = v78->regs;
  int v82 = v81[12];
  int * v83 = v78->regs;
  v83[10] = v82;
  struct StateT * v85 = slot_6(v78);
  return v85;
}

struct StateT * slot_2(struct StateT * v26) {
  int * v27 = v26->saved_regs;
  int * v28 = v26->regs;
  int v29 = v28[12];
  v27[12] = v29;
  int v31 = v26->timer;
  int v43 = v31 + 1;
  v26->timer = v43;
  int * v33 = v26->regs;
  int v34 = v33[11];
  int * v35 = v26->regs;
  v35[12] = v34;
  struct StateT * v37 = slot_3(v26);
  return v37;
}

struct StateT * slot_7(struct StateT * v117) {
  int v118 = v117->timer;
  int v121 = v118 + 1;
  v117->timer = v121;
  return v117;
}

struct StateT * slot_3(struct StateT * v50) {
  int * v51 = v50->regs;
  int v52 = v51[10];
  bool v67 = !(v52 == 0);
  struct StateT * v63;
  if (v67) {
    int v53 = v50->timer;
    int v68 = v53 + 15;
    v50->timer = v68;
    int * v55 = v50->saved_regs;
    int v56 = v55[12];
    int * v57 = v50->regs;
    v57[12] = v56;
    struct StateT * v59 = slot_4(v50);
    v63 = v59;
  } else {
    struct StateT * v61 = slot_5(v50);
    v63 = v61;
  }
  return v63;
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