// verify: leak widened (the program is clean; Eva cannot prove it) [unroll 65]
#define NUM_REGS 32
#define MEM_SIZE 64
#define SECRET_SIZE 10
#define SECRET_OFFSET 20
#define CACHE_ENTRIES 12
#define CACHE_WORDS 24

#ifdef EVA
#include "__fc_builtin.h"
/*@ assigns *p \from \nothing;
    taints *p; */
void koika_mark(int *p);
#define koika_assert(b, s) ((void)0)
#define koika_assume(b) do { if (!(b)) Frama_C_abort(); } while (0)
#define koika_draw(x) ((x) = Frama_C_interval(-2147483647-1, 2147483647))
#define koika_secret(x) koika_mark(&(x))
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
struct StateT * slot_1(struct StateT * v15);
struct StateT * slot_6(struct StateT * v69);
struct StateT * slot_5(struct StateT * v100);
struct StateT * slot_4(struct StateT * v82);
struct StateT * slot_2(struct StateT * v34);
struct StateT * slot_3(struct StateT * v47);
struct StateT * slot_0(struct StateT * v2);
struct StateT * snippet(struct StateT * v0) {
  struct StateT * v1 = slot_0(v0);
  return v1;
}

struct StateT * slot_1(struct StateT * v15) {
  int v16 = v15->timer;
  int v25 = v16 + 1;
  v15->timer = v25;
  int * v18 = v15->regs;
  int v19 = v18[12];
  int * v20 = v15->mem;
  int v29 = (int)((unsigned int)v19 >> 2);
  int v21 = v20[v29];
  v18[16] = v21;
  struct StateT * v23 = slot_2(v15);
  return v23;
}

struct StateT * slot_6(struct StateT * v69) {
  int v70 = v69->timer;
  int v76 = v70 + 1;
  v69->timer = v76;
  int * v72 = v69->regs;
  v72[18] = 2;
  struct StateT * v74 = slot_5(v69);
  return v74;
}

struct StateT * slot_5(struct StateT * v100) {
  int v101 = v100->timer;
  int v104 = v101 + 1;
  v100->timer = v104;
  return v100;
}

struct StateT * slot_4(struct StateT * v82) {
  int v83 = v82->timer;
  int v89 = v83 + 1;
  v82->timer = v89;
  int * v85 = v82->regs;
  v85[18] = 1;
  struct StateT * v87 = slot_5(v82);
  return v87;
}

struct StateT * slot_2(struct StateT * v34) {
  int v35 = v34->timer;
  int v41 = v35 + 1;
  v34->timer = v41;
  int * v37 = v34->regs;
  v37[17] = 10;
  struct StateT * v39 = slot_3(v34);
  return v39;
}

struct StateT * slot_3(struct StateT * v47) {
  int v48 = v47->timer;
  int v59 = v48 + 1;
  v47->timer = v59;
  int * v50 = v47->regs;
  int v51 = v50[16];
  int v52 = v50[17];
  bool v63 = v51 < v52;
  struct StateT * v57;
  if (v63) {
    struct StateT * v53 = slot_6(v47);
    v57 = v53;
  } else {
    struct StateT * v55 = slot_4(v47);
    v57 = v55;
  }
  return v57;
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
    s1.mem[SECRET_OFFSET+i] = secret(0, 20);
    s2.mem[SECRET_OFFSET+i] = secret(0, 20);
  }
  struct StateT *s1_ = snippet(&s1);
  struct StateT *s2_ = snippet(&s2);
  //@ assert untainted_timer: !\tainted(s1_->timer==s2_->timer);
  koika_assert(s1_->timer==s2_->timer, "timing leak");
  return 0;
}