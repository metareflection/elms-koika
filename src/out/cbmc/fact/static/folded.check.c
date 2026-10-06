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
#define koika_secret(x) ((void)0)
#else
#define koika_assert(b, s) 0
#define koika_assume(b) 0
#define koika_draw(x) ((x) = 0)
#define koika_secret(x) ((void)0)
#endif
int bounded(int low, int high) {
  int x;
  koika_draw(x);
  koika_assume(low <= x && x <= high);
  return x;
}
// Same draw as `bounded`, said of the secret, so a backend that tracks
// where the secret goes has somewhere to start. Self-composition already
// encodes the split by drawing these twice, which is why the mark is
// nothing under a checker that reads the two runs exactly.
int secret(int low, int high) {
  int x = bounded(low, high);
  koika_secret(x);
  return x;
}

/*****************************************
Emitting C Generated Code
*******************************************/

#include <stdbool.h>

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
struct StateT * slot_1(struct StateT * v16);
struct StateT * slot_5(struct StateT * v89);
struct StateT * slot_4(struct StateT * v74);
struct StateT * slot_2(struct StateT * v24);
struct StateT * slot_3(struct StateT * v46);
struct StateT * slot_0(struct StateT * v2);
struct StateT * snippet(struct StateT * v0) {
  struct StateT * v1 = slot_0(v0);
  return v1;
}

struct StateT * slot_1(struct StateT * v16) {
  int v17 = v16->timer;
  int v21 = v17 + 1;
  v16->timer = v21;
  struct StateT * v19 = slot_2(v16);
  return v19;
}

struct StateT * slot_5(struct StateT * v89) {
  int v90 = v89->timer;
  int v93 = v90 + 1;
  v89->timer = v93;
  return v89;
}

struct StateT * slot_4(struct StateT * v74) {
  int v75 = v74->timer;
  int v82 = v75 + 1;
  v74->timer = v82;
  int * v77 = v74->regs;
  int v78 = v77[12];
  v77[10] = v78;
  struct StateT * v80 = slot_5(v74);
  return v80;
}

struct StateT * slot_2(struct StateT * v24) {
  int * v25 = v24->saved_regs;
  int * v26 = v24->regs;
  int v27 = v26[12];
  v25[12] = v27;
  int v29 = v24->timer;
  int v40 = v29 + 1;
  v24->timer = v40;
  int * v31 = v24->regs;
  int v32 = v31[11];
  v31[12] = v32;
  struct StateT * v34 = slot_3(v24);
  return v34;
}

struct StateT * slot_3(struct StateT * v46) {
  int * v47 = v46->regs;
  int v48 = v47[10];
  bool v63 = !(v48 == 0);
  struct StateT * v59;
  if (v63) {
    int v49 = v46->timer;
    int v64 = v49 + 15;
    v46->timer = v64;
    int * v51 = v46->saved_regs;
    int v52 = v51[12];
    int * v53 = v46->regs;
    v53[12] = v52;
    struct StateT * v55 = slot_4(v46);
    v59 = v55;
  } else {
    struct StateT * v57 = slot_4(v46);
    v59 = v57;
  }
  return v59;
}

struct StateT * slot_0(struct StateT * v2) {
  int v3 = v2->timer;
  int v10 = v3 + 1;
  v2->timer = v10;
  int * v5 = v2->regs;
  int v6 = v5[10];
  int v13 = v6 & 1;
  v5[10] = v13;
  struct StateT * v8 = slot_1(v2);
  return v8;
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
  s1.regs[10] = secret(0, 1);
  s2.regs[10] = secret(0, 1);
  struct StateT *s1_ = snippet(&s1);
  struct StateT *s2_ = snippet(&s2);
  //@ assert untainted_timer: !\tainted(s1_->timer==s2_->timer);
  koika_assert(s1_->timer==s2_->timer, "timing leak");
  return 0;
}