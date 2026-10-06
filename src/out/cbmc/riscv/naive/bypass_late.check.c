// verify: clean (CBMC should report VERIFICATION SUCCESSFUL) [unwind 65]
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
struct StateT * slot_1(struct StateT * v17);
struct StateT * slot_8(struct StateT * v129);
struct StateT * slot_6(struct StateT * v96);
struct StateT * slot_5(struct StateT * v77);
struct StateT * slot_4(struct StateT * v64);
struct StateT * slot_2(struct StateT * v30);
struct StateT * slot_7(struct StateT * v115);
struct StateT * slot_3(struct StateT * v49);
struct StateT * slot_0(struct StateT * v2);
struct StateT * snippet(struct StateT * v0) {
  struct StateT * v1 = slot_0(v0);
  return v1;
}

struct StateT * slot_1(struct StateT * v17) {
  int v18 = v17->timer;
  int v24 = v18 + 1;
  v17->timer = v24;
  int * v20 = v17->regs;
  v20[9] = 32;
  struct StateT * v22 = slot_2(v17);
  return v22;
}

struct StateT * slot_8(struct StateT * v129) {
  int v130 = v129->timer;
  int v138 = v130 + 1;
  v129->timer = v138;
  int * v132 = v129->regs;
  int v133 = v132[11];
  int * v134 = v129->mem;
  int v142 = (int)((unsigned int)v133 >> 2);
  int v135 = v134[v142];
  v132[12] = v135;
  return v129;
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
  v99[11] = v102;
  struct StateT * v104 = slot_7(v96);
  return v104;
}

struct StateT * slot_5(struct StateT * v77) {
  int v78 = v77->timer;
  int v87 = v78 + 1;
  v77->timer = v87;
  int * v80 = v77->regs;
  int v81 = v80[6];
  int v82 = v80[7];
  int * v83 = v77->mem;
  int v92 = (int)((unsigned int)v81 >> 2);
  v83[v92] = v82;
  struct StateT * v85 = slot_6(v77);
  return v85;
}

struct StateT * slot_4(struct StateT * v64) {
  int v65 = v64->timer;
  int v71 = v65 + 1;
  v64->timer = v71;
  int * v67 = v64->regs;
  v67[7] = 0;
  struct StateT * v69 = slot_5(v64);
  return v69;
}

struct StateT * slot_2(struct StateT * v30) {
  int v31 = v30->timer;
  int v41 = v31 + 1;
  v30->timer = v41;
  int * v33 = v30->regs;
  int v34 = v33[5];
  int v35 = v33[9];
  bool v45 = v34 >= v35;
  struct StateT * v39;
  if (v45) {
    v39 = v30;
  } else {
    struct StateT * v37 = slot_3(v30);
    v39 = v37;
  }
  return v39;
}

struct StateT * slot_7(struct StateT * v115) {
  int v116 = v115->timer;
  int v123 = v116 + 1;
  v115->timer = v123;
  int * v118 = v115->regs;
  int v119 = v118[11];
  int v126 = v119 << 2;
  v118[11] = v126;
  struct StateT * v121 = slot_8(v115);
  return v121;
}

struct StateT * slot_3(struct StateT * v49) {
  int v50 = v49->timer;
  int v57 = v50 + 1;
  v49->timer = v57;
  int * v52 = v49->regs;
  int v53 = v52[5];
  int v61 = v53 + 80;
  v52[6] = v61;
  struct StateT * v55 = slot_4(v49);
  return v55;
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