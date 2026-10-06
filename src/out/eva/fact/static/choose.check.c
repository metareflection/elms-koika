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
struct StateT * slot_1(struct StateT * v16);
struct StateT * slot_5(struct StateT * v78);
struct StateT * slot_4(struct StateT * v62);
struct StateT * slot_2(struct StateT * v30);
struct StateT * slot_3(struct StateT * v46);
struct StateT * slot_0(struct StateT * v2);
struct StateT * snippet(struct StateT * v0) {
  struct StateT * v1 = slot_0(v0);
  return v1;
}

struct StateT * slot_1(struct StateT * v16) {
  int v17 = v16->timer;
  int v24 = v17 + 1;
  v16->timer = v24;
  int * v19 = v16->regs;
  int v20 = v19[10];
  int v27 = v20 >> 31;
  v19[10] = v27;
  struct StateT * v22 = slot_2(v16);
  return v22;
}

struct StateT * slot_5(struct StateT * v78) {
  int v79 = v78->timer;
  int v82 = v79 + 1;
  v78->timer = v82;
  return v78;
}

struct StateT * slot_4(struct StateT * v62) {
  int v63 = v62->timer;
  int v71 = v63 + 1;
  v62->timer = v71;
  int * v65 = v62->regs;
  int v66 = v65[11];
  int v67 = v65[10];
  int v75 = v66 ^ v67;
  v65[10] = v75;
  struct StateT * v69 = slot_5(v62);
  return v69;
}

struct StateT * slot_2(struct StateT * v30) {
  int v31 = v30->timer;
  int v39 = v31 + 1;
  v30->timer = v39;
  int * v33 = v30->regs;
  int v34 = v33[12];
  int v35 = v33[11];
  int v43 = v34 ^ v35;
  v33[12] = v43;
  struct StateT * v37 = slot_3(v30);
  return v37;
}

struct StateT * slot_3(struct StateT * v46) {
  int v47 = v46->timer;
  int v55 = v47 + 1;
  v46->timer = v55;
  int * v49 = v46->regs;
  int v50 = v49[10];
  int v51 = v49[12];
  int v59 = v50 & v51;
  v49[10] = v59;
  struct StateT * v53 = slot_4(v46);
  return v53;
}

struct StateT * slot_0(struct StateT * v2) {
  int v3 = v2->timer;
  int v10 = v3 + 1;
  v2->timer = v10;
  int * v5 = v2->regs;
  int v6 = v5[10];
  int v13 = v6 << 31;
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