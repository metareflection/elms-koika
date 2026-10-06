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

struct StateT * slot_6(struct StateT * v121);
struct StateT * slot_5(struct StateT * v102);
struct StateT * slot_2(struct StateT * v28);
struct StateT * slot_7(struct StateT * v135);
struct StateT * slot_3(struct StateT * v41);
struct StateT * snippet(struct StateT * v0);
struct StateT * slot_1(struct StateT * v15);
struct StateT * slot_8(struct StateT * v63);
struct StateT * slot_4(struct StateT * v71);
struct StateT * slot_9(struct StateT * v88);
struct StateT * slot_0(struct StateT * v2);
struct StateT * slot_6(struct StateT * v121) {
  int v122 = v121->timer;
  int v129 = v122 + 1;
  v121->timer = v129;
  int * v124 = v121->regs;
  int v125 = v124[11];
  int v132 = v125 << 2;
  v124[11] = v132;
  struct StateT * v127 = slot_7(v121);
  return v127;
}

struct StateT * slot_5(struct StateT * v102) {
  int v103 = v102->timer;
  int v112 = v103 + 1;
  v102->timer = v112;
  int * v105 = v102->regs;
  int v106 = v105[5];
  int * v107 = v102->mem;
  int v116 = (int)((unsigned int)v106 >> 2);
  int v108 = v107[v116];
  v105[11] = v108;
  struct StateT * v110 = slot_6(v102);
  return v110;
}

struct StateT * slot_2(struct StateT * v28) {
  int v29 = v28->timer;
  int v35 = v29 + 1;
  v28->timer = v35;
  int * v31 = v28->regs;
  v31[15] = 80;
  struct StateT * v33 = slot_3(v28);
  return v33;
}

struct StateT * slot_7(struct StateT * v135) {
  int v136 = v135->timer;
  int v145 = v136 + 1;
  v135->timer = v145;
  int * v138 = v135->regs;
  int v139 = v138[11];
  int * v140 = v135->mem;
  int v149 = (int)((unsigned int)v139 >> 2);
  int v141 = v140[v149];
  v138[12] = v141;
  struct StateT * v143 = slot_8(v135);
  return v143;
}

struct StateT * slot_3(struct StateT * v41) {
  int v42 = v41->timer;
  int v53 = v42 + 1;
  v41->timer = v53;
  int * v44 = v41->regs;
  int v45 = v44[10];
  int v46 = v44[15];
  bool v57 = v45 >= v46;
  struct StateT * v51;
  if (v57) {
    struct StateT * v47 = slot_8(v41);
    v51 = v47;
  } else {
    struct StateT * v49 = slot_4(v41);
    v51 = v49;
  }
  return v51;
}

struct StateT * snippet(struct StateT * v0) {
  struct StateT * v1 = slot_0(v0);
  return v1;
}

struct StateT * slot_1(struct StateT * v15) {
  int v16 = v15->timer;
  int v22 = v16 + 1;
  v15->timer = v22;
  int * v18 = v15->regs;
  v18[10] = 80;
  struct StateT * v20 = slot_2(v15);
  return v20;
}

struct StateT * slot_8(struct StateT * v63) {
  int v64 = v63->timer;
  int v68 = v64 + 1;
  v63->timer = v68;
  struct StateT * v66 = slot_9(v63);
  return v66;
}

struct StateT * slot_4(struct StateT * v71) {
  int v72 = v71->timer;
  int v80 = v72 + 1;
  v71->timer = v80;
  int * v74 = v71->regs;
  int v75 = v74[13];
  int v76 = v74[10];
  int v85 = v75 + v76;
  v74[5] = v85;
  struct StateT * v78 = slot_5(v71);
  return v78;
}

struct StateT * slot_9(struct StateT * v88) {
  int v89 = v88->timer;
  int v96 = v89 + 1;
  v88->timer = v96;
  int * v91 = v88->mem;
  int v92 = v91[0];
  int * v93 = v88->regs;
  v93[14] = v92;
  return v88;
}

struct StateT * slot_0(struct StateT * v2) {
  int v3 = v2->timer;
  int v9 = v3 + 1;
  v2->timer = v9;
  int * v5 = v2->regs;
  v5[13] = 0;
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
  koika_assert(s1_->timer==s2_->timer, "timing leak");
  return 0;
}