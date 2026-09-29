// verify: clean (Eva should report untainted: Valid) [unroll 65]
#define NUM_REGS 32
#define MEM_SIZE 64
#define SECRET_SIZE 10
#define SECRET_OFFSET 20
#define CACHE_ENTRIES 12
#define CACHE_WORDS 24

#ifdef EVA
#include "__fc_builtin.h"
/*@ requires untainted: !\tainted(b);
    assigns \nothing; */
void koika_check(int b);
/*@ assigns *p \from \nothing;
    taints *p; */
void koika_mark(int *p);
#define koika_assert(b, s) koika_check(b)
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
struct StateT * slot_1(struct StateT * v19);
struct StateT * slot_6(struct StateT * v96);
struct StateT * slot_5(struct StateT * v79);
struct StateT * slot_4(struct StateT * v62);
struct StateT * slot_2(struct StateT * v34);
struct StateT * slot_7(struct StateT * v115);
struct StateT * slot_3(struct StateT * v48);
struct StateT * slot_0(struct StateT * v2);
struct StateT * snippet(struct StateT * v0) {
  struct StateT * v1 = slot_0(v0);
  return v1;
}

struct StateT * slot_1(struct StateT * v19) {
  int v20 = v19->timer;
  int v27 = v20 + 1;
  v19->timer = v27;
  int * v22 = v19->regs;
  int v23 = v22[5];
  int v31 = v23 & 1;
  v22[6] = v31;
  struct StateT * v25 = slot_2(v19);
  return v25;
}

struct StateT * slot_6(struct StateT * v96) {
  int v97 = v96->timer;
  int v106 = v97 + 1;
  v96->timer = v106;
  int * v99 = v96->regs;
  int v100 = v99[6];
  int * v101 = v96->mem;
  int v110 = (int)((unsigned int)v100 >> 2);
  int v102 = v101[v110];
  v99[9] = v102;
  struct StateT * v104 = slot_7(v96);
  return v104;
}

struct StateT * slot_5(struct StateT * v79) {
  int v80 = v79->timer;
  int v88 = v80 + 1;
  v79->timer = v88;
  int * v82 = v79->mem;
  int v83 = v82[4];
  int * v84 = v79->regs;
  v84[8] = v83;
  struct StateT * v86 = slot_6(v79);
  return v86;
}

struct StateT * slot_4(struct StateT * v62) {
  int v63 = v62->timer;
  int v71 = v63 + 1;
  v62->timer = v71;
  int * v65 = v62->mem;
  int v66 = v65[0];
  int * v67 = v62->regs;
  v67[7] = v66;
  struct StateT * v69 = slot_5(v62);
  return v69;
}

struct StateT * slot_2(struct StateT * v34) {
  int v35 = v34->timer;
  int v42 = v35 + 1;
  v34->timer = v42;
  int * v37 = v34->regs;
  int v38 = v37[6];
  int v45 = v38 << 3;
  v37[6] = v45;
  struct StateT * v40 = slot_3(v34);
  return v40;
}

struct StateT * slot_7(struct StateT * v115) {
  int v116 = v115->timer;
  int v123 = v116 + 1;
  v115->timer = v123;
  int * v118 = v115->mem;
  int v119 = v118[0];
  int * v120 = v115->regs;
  v120[11] = v119;
  return v115;
}

struct StateT * slot_3(struct StateT * v48) {
  int v49 = v48->timer;
  int v56 = v49 + 1;
  v48->timer = v56;
  int * v51 = v48->regs;
  int v52 = v51[6];
  int v59 = v52 + 32;
  v51[6] = v59;
  struct StateT * v54 = slot_4(v48);
  return v54;
}

struct StateT * slot_0(struct StateT * v2) {
  int v3 = v2->timer;
  int v11 = v3 + 1;
  v2->timer = v11;
  int * v5 = v2->mem;
  int v6 = v5[20];
  int * v7 = v2->regs;
  v7[5] = v6;
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
    s1.mem[SECRET_OFFSET+i] = secret(0, 20);
    s2.mem[SECRET_OFFSET+i] = secret(0, 20);
  }
  struct StateT *s1_ = snippet(&s1);
  struct StateT *s2_ = snippet(&s2);
  koika_assert(s1_->timer==s2_->timer, "timing leak");
  return 0;
}