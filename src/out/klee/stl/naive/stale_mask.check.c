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
struct StateT * slot_6(struct StateT * v96);
struct StateT * slot_5(struct StateT * v79);
struct StateT * slot_4(struct StateT * v62);
struct StateT * slot_2(struct StateT * v32);
struct StateT * slot_7(struct StateT * v115);
struct StateT * slot_3(struct StateT * v45);
struct StateT * slot_0(struct StateT * v2);
struct StateT * snippet(struct StateT * v0) {
  struct StateT * v1 = slot_0(v0);
  return v1;
}

struct StateT * slot_1(struct StateT * v15) {
  int v16 = v15->timer;
  int v24 = v16 + 1;
  v15->timer = v24;
  int * v18 = v15->regs;
  int v19 = v18[5];
  int * v20 = v15->mem;
  v20[13] = v19;
  struct StateT * v22 = slot_2(v15);
  return v22;
}

struct StateT * slot_6(struct StateT * v96) {
  int v97 = v96->timer;
  int v106 = v97 + 1;
  v96->timer = v106;
  int * v99 = v96->regs;
  int v100 = v99[9];
  int * v101 = v96->mem;
  int v110 = (int)((unsigned int)v100 >> 2);
  int v102 = v101[v110];
  v99[11] = v102;
  struct StateT * v104 = slot_7(v96);
  return v104;
}

struct StateT * slot_5(struct StateT * v79) {
  int v80 = v79->timer;
  int v88 = v80 + 1;
  v79->timer = v88;
  int * v82 = v79->regs;
  int v83 = v82[10];
  int v84 = v82[8];
  int v93 = v83 & v84;
  v82[9] = v93;
  struct StateT * v86 = slot_6(v79);
  return v86;
}

struct StateT * slot_4(struct StateT * v62) {
  int v63 = v62->timer;
  int v71 = v63 + 1;
  v62->timer = v71;
  int * v65 = v62->mem;
  int v66 = v65[13];
  int * v67 = v62->regs;
  v67[8] = v66;
  struct StateT * v69 = slot_5(v62);
  return v69;
}

struct StateT * slot_2(struct StateT * v32) {
  int v33 = v32->timer;
  int v39 = v33 + 1;
  v32->timer = v39;
  int * v35 = v32->regs;
  v35[7] = 28;
  struct StateT * v37 = slot_3(v32);
  return v37;
}

struct StateT * slot_7(struct StateT * v115) {
  int v116 = v115->timer;
  int v124 = v116 + 1;
  v115->timer = v124;
  int * v118 = v115->regs;
  int v119 = v118[11];
  int * v120 = v115->mem;
  int v128 = (int)((unsigned int)v119 >> 2);
  int v121 = v120[v128];
  v118[12] = v121;
  return v115;
}

struct StateT * slot_3(struct StateT * v45) {
  int v46 = v45->timer;
  int v54 = v46 + 1;
  v45->timer = v54;
  int * v48 = v45->regs;
  int v49 = v48[7];
  int * v50 = v45->mem;
  v50[13] = v49;
  struct StateT * v52 = slot_4(v45);
  return v52;
}

struct StateT * slot_0(struct StateT * v2) {
  int v3 = v2->timer;
  int v9 = v3 + 1;
  v2->timer = v9;
  int * v5 = v2->regs;
  v5[5] = -1;
  struct StateT * v7 = slot_1(v2);
  return v7;
}



/*****************************************
End of C Generated Code
*******************************************/

void init(struct StateT *s) {
  for (int i=0; i<NUM_REGS; i++) {
    s->regs[i] = 0;
    s->saved_regs[i] = 0;
    s->reg_ready[i] = 0;
  }
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
  
  int x = bounded(0, 80);
  s1.regs[10] = x;
  s2.regs[10] = x;
  
  // initialize secret
  for (int i=0; i<SECRET_SIZE; i++) {
    s1.mem[SECRET_OFFSET+i] = secret(0, 20);
    s2.mem[SECRET_OFFSET+i] = secret(0, 20);
  }
  struct StateT *s1_ = snippet(&s1);
  struct StateT *s2_ = snippet(&s2);
  //@ assert untainted_timer: !\tainted(s1_->timer==s2_->timer);
  koika_assert(s1_->timer==s2_->timer, "timing leak");
  return 0;
}