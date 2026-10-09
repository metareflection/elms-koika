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
struct StateT * slot_8(struct StateT * v99);
struct StateT * slot_6(struct StateT * v72);
struct StateT * slot_5(struct StateT * v64);
struct StateT * slot_4(struct StateT * v56);
struct StateT * slot_2(struct StateT * v31);
struct StateT * slot_7(struct StateT * v80);
struct StateT * slot_3(struct StateT * v48);
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
  int v21 = v20[6];
  int v28 = v21 + 80;
  v20[6] = v28;
  struct StateT * v23 = slot_2(v17);
  return v23;
}

struct StateT * slot_8(struct StateT * v99) {
  int v100 = v99->timer;
  int v108 = v100 + 1;
  v99->timer = v108;
  int * v102 = v99->regs;
  int v103 = v102[11];
  int * v104 = v99->mem;
  int v112 = (int)((unsigned int)v103 >> 2);
  int v105 = v104[v112];
  v102[12] = v105;
  return v99;
}

struct StateT * slot_6(struct StateT * v72) {
  int v73 = v72->timer;
  int v77 = v73 + 1;
  v72->timer = v77;
  struct StateT * v75 = slot_7(v72);
  return v75;
}

struct StateT * slot_5(struct StateT * v64) {
  int v65 = v64->timer;
  int v69 = v65 + 1;
  v64->timer = v69;
  struct StateT * v67 = slot_6(v64);
  return v67;
}

struct StateT * slot_4(struct StateT * v56) {
  int v57 = v56->timer;
  int v61 = v57 + 1;
  v56->timer = v61;
  struct StateT * v59 = slot_5(v56);
  return v59;
}

struct StateT * slot_2(struct StateT * v31) {
  int v32 = v31->timer;
  int v40 = v32 + 1;
  v31->timer = v40;
  int * v34 = v31->regs;
  int v35 = v34[6];
  int * v36 = v31->mem;
  int v44 = (int)((unsigned int)v35 >> 2);
  v36[v44] = 0;
  struct StateT * v38 = slot_3(v31);
  return v38;
}

struct StateT * slot_7(struct StateT * v80) {
  int v81 = v80->timer;
  int v90 = v81 + 1;
  v80->timer = v90;
  int * v83 = v80->regs;
  int v84 = v83[6];
  int * v85 = v80->mem;
  int v94 = (int)((unsigned int)v84 >> 2);
  int v86 = v85[v94];
  v83[11] = v86;
  struct StateT * v88 = slot_8(v80);
  return v88;
}

struct StateT * slot_3(struct StateT * v48) {
  int v49 = v48->timer;
  int v53 = v49 + 1;
  v48->timer = v53;
  struct StateT * v51 = slot_4(v48);
  return v51;
}

struct StateT * slot_0(struct StateT * v2) {
  int v3 = v2->timer;
  int v10 = v3 + 1;
  v2->timer = v10;
  int * v5 = v2->regs;
  int v6 = v5[10];
  int v14 = v6 & 28;
  v5[6] = v14;
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