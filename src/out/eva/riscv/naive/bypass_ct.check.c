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
struct StateT * slot_6(struct StateT * v96);
struct StateT * slot_5(struct StateT * v82);
struct StateT * slot_4(struct StateT * v63);
struct StateT * slot_2(struct StateT * v31);
struct StateT * slot_3(struct StateT * v44);
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

struct StateT * slot_6(struct StateT * v96) {
  int v97 = v96->timer;
  int v105 = v97 + 1;
  v96->timer = v105;
  int * v99 = v96->regs;
  int v100 = v99[6];
  int * v101 = v96->mem;
  int v109 = (int)((unsigned int)v100 >> 2);
  int v102 = v101[v109];
  v99[12] = v102;
  return v96;
}

struct StateT * slot_5(struct StateT * v82) {
  int v83 = v82->timer;
  int v90 = v83 + 1;
  v82->timer = v90;
  int * v85 = v82->regs;
  int v86 = v85[11];
  int v93 = v86 << 2;
  v85[11] = v93;
  struct StateT * v88 = slot_6(v82);
  return v88;
}

struct StateT * slot_4(struct StateT * v63) {
  int v64 = v63->timer;
  int v73 = v64 + 1;
  v63->timer = v73;
  int * v66 = v63->regs;
  int v67 = v66[6];
  int * v68 = v63->mem;
  int v77 = (int)((unsigned int)v67 >> 2);
  int v69 = v68[v77];
  v66[11] = v69;
  struct StateT * v71 = slot_5(v63);
  return v71;
}

struct StateT * slot_2(struct StateT * v31) {
  int v32 = v31->timer;
  int v38 = v32 + 1;
  v31->timer = v38;
  int * v34 = v31->regs;
  v34[7] = 0;
  struct StateT * v36 = slot_3(v31);
  return v36;
}

struct StateT * slot_3(struct StateT * v44) {
  int v45 = v44->timer;
  int v54 = v45 + 1;
  v44->timer = v54;
  int * v47 = v44->regs;
  int v48 = v47[6];
  int v49 = v47[7];
  int * v50 = v44->mem;
  int v59 = (int)((unsigned int)v48 >> 2);
  v50[v59] = v49;
  struct StateT * v52 = slot_4(v44);
  return v52;
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