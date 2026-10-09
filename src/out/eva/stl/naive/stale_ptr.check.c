// verify: clean (Eva should report untainted_timer: Valid) [unroll 65]
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
struct StateT * slot_1(struct StateT * v17);
struct StateT * slot_6(struct StateT * v102);
struct StateT * slot_5(struct StateT * v83);
struct StateT * slot_4(struct StateT * v66);
struct StateT * slot_2(struct StateT * v32);
struct StateT * slot_3(struct StateT * v49);
struct StateT * slot_0(struct StateT * v2);
struct StateT * snippet(struct StateT * v0) {
  struct StateT * v1 = slot_0(v0);
  return v1;
}

struct StateT * slot_1(struct StateT * v17) {
  int v18 = v17->timer;
  int v25 = v18 + 1;
  v17->timer = v25;
  int * v20 = v17->regs;
  int v21 = v20[5];
  int v29 = v21 + 80;
  v20[6] = v29;
  struct StateT * v23 = slot_2(v17);
  return v23;
}

struct StateT * slot_6(struct StateT * v102) {
  int v103 = v102->timer;
  int v111 = v103 + 1;
  v102->timer = v111;
  int * v105 = v102->regs;
  int v106 = v105[11];
  int * v107 = v102->mem;
  int v115 = (int)((unsigned int)v106 >> 2);
  int v108 = v107[v115];
  v105[12] = v108;
  return v102;
}

struct StateT * slot_5(struct StateT * v83) {
  int v84 = v83->timer;
  int v93 = v84 + 1;
  v83->timer = v93;
  int * v86 = v83->regs;
  int v87 = v86[8];
  int * v88 = v83->mem;
  int v97 = (int)((unsigned int)v87 >> 2);
  int v89 = v88[v97];
  v86[11] = v89;
  struct StateT * v91 = slot_6(v83);
  return v91;
}

struct StateT * slot_4(struct StateT * v66) {
  int v67 = v66->timer;
  int v75 = v67 + 1;
  v66->timer = v75;
  int * v69 = v66->mem;
  int v70 = v69[9];
  int * v71 = v66->regs;
  v71[8] = v70;
  struct StateT * v73 = slot_5(v66);
  return v73;
}

struct StateT * slot_2(struct StateT * v32) {
  int v33 = v32->timer;
  int v41 = v33 + 1;
  v32->timer = v41;
  int * v35 = v32->regs;
  int v36 = v35[6];
  int * v37 = v32->mem;
  v37[9] = v36;
  struct StateT * v39 = slot_3(v32);
  return v39;
}

struct StateT * slot_3(struct StateT * v49) {
  int v50 = v49->timer;
  int v58 = v50 + 1;
  v49->timer = v58;
  int * v52 = v49->regs;
  int v53 = v52[5];
  int * v54 = v49->mem;
  v54[9] = v53;
  struct StateT * v56 = slot_4(v49);
  return v56;
}

struct StateT * slot_0(struct StateT * v2) {
  int v3 = v2->timer;
  int v10 = v3 + 1;
  v2->timer = v10;
  int * v5 = v2->regs;
  int v6 = v5[10];
  int v14 = v6 & 28;
  v5[5] = v14;
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