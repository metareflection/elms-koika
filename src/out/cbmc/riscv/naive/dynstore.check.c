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

struct StateT * slot_6(struct StateT * v96);
struct StateT * slot_5(struct StateT * v77);
struct StateT * slot_2(struct StateT * v28);
struct StateT * slot_7(struct StateT * v115);
struct StateT * slot_3(struct StateT * v41);
struct StateT * snippet(struct StateT * v0);
struct StateT * slot_1(struct StateT * v15);
struct StateT * slot_8(struct StateT * v134);
struct StateT * slot_4(struct StateT * v60);
struct StateT * slot_9(struct StateT * v148);
struct StateT * slot_0(struct StateT * v2);
struct StateT * slot_6(struct StateT * v96) {
  int v97 = v96->timer;
  int v106 = v97 + 1;
  v96->timer = v106;
  int * v99 = v96->regs;
  int v100 = v99[6];
  int v101 = v99[5];
  int * v102 = v96->mem;
  int v111 = (int)((unsigned int)v100 >> 2);
  v102[v111] = v101;
  struct StateT * v104 = slot_7(v96);
  return v104;
}

struct StateT * slot_5(struct StateT * v77) {
  int v78 = v77->timer;
  int v87 = v78 + 1;
  v77->timer = v87;
  int * v80 = v77->regs;
  int v81 = v80[8];
  int * v82 = v77->mem;
  int v91 = (int)((unsigned int)v81 >> 2);
  int v83 = v82[v91];
  v80[5] = v83;
  struct StateT * v85 = slot_6(v77);
  return v85;
}

struct StateT * slot_2(struct StateT * v28) {
  int v29 = v28->timer;
  int v35 = v29 + 1;
  v28->timer = v35;
  int * v31 = v28->regs;
  v31[9] = 80;
  struct StateT * v33 = slot_3(v28);
  return v33;
}

struct StateT * slot_7(struct StateT * v115) {
  int v116 = v115->timer;
  int v125 = v116 + 1;
  v115->timer = v125;
  int * v118 = v115->regs;
  int v119 = v118[6];
  int * v120 = v115->mem;
  int v129 = (int)((unsigned int)v119 >> 2);
  int v121 = v120[v129];
  v118[11] = v121;
  struct StateT * v123 = slot_8(v115);
  return v123;
}

struct StateT * slot_3(struct StateT * v41) {
  int v42 = v41->timer;
  int v52 = v42 + 1;
  v41->timer = v52;
  int * v44 = v41->regs;
  int v45 = v44[6];
  int v46 = v44[7];
  bool v56 = v45 >= v46;
  struct StateT * v50;
  if (v56) {
    v50 = v41;
  } else {
    struct StateT * v48 = slot_4(v41);
    v50 = v48;
  }
  return v50;
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
  v18[7] = 16;
  struct StateT * v20 = slot_2(v15);
  return v20;
}

struct StateT * slot_8(struct StateT * v134) {
  int v135 = v134->timer;
  int v142 = v135 + 1;
  v134->timer = v142;
  int * v137 = v134->regs;
  int v138 = v137[6];
  int v145 = v138 + 4;
  v137[6] = v145;
  struct StateT * v140 = slot_9(v134);
  return v140;
}

struct StateT * slot_4(struct StateT * v60) {
  int v61 = v60->timer;
  int v69 = v61 + 1;
  v60->timer = v69;
  int * v63 = v60->regs;
  int v64 = v63[9];
  int v65 = v63[6];
  int v74 = v64 + v65;
  v63[8] = v74;
  struct StateT * v67 = slot_5(v60);
  return v67;
}

struct StateT * slot_9(struct StateT * v148) {
  int v149 = v148->timer;
  int v153 = v149 + 1;
  v148->timer = v153;
  struct StateT * v151 = slot_3(v148);
  return v151;
}

struct StateT * slot_0(struct StateT * v2) {
  int v3 = v2->timer;
  int v9 = v3 + 1;
  v2->timer = v9;
  int * v5 = v2->regs;
  v5[6] = 0;
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