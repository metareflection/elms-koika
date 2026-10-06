// verify: leak (CBMC should report VERIFICATION FAILED) [unwind 65]
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

struct StateT * slot_12(struct StateT * v180);
struct StateT * slot_14(struct StateT * v76);
struct StateT * slot_6(struct StateT * v103);
struct StateT * slot_5(struct StateT * v86);
struct StateT * slot_2(struct StateT * v28);
struct StateT * slot_7(struct StateT * v122);
struct StateT * slot_3(struct StateT * v41);
struct StateT * snippet(struct StateT * v0);
struct StateT * slot_10(struct StateT * v193);
struct StateT * slot_1(struct StateT * v15);
struct StateT * slot_8(struct StateT * v139);
struct StateT * slot_4(struct StateT * v54);
struct StateT * slot_13(struct StateT * v207);
struct StateT * slot_9(struct StateT * v158);
struct StateT * slot_11(struct StateT * v212);
struct StateT * slot_0(struct StateT * v2);
struct StateT * slot_12(struct StateT * v180) {
  int v181 = v180->timer;
  int v187 = v181 + 1;
  v180->timer = v187;
  int * v183 = v180->regs;
  v183[10] = 0;
  struct StateT * v185 = slot_13(v180);
  return v185;
}

struct StateT * slot_14(struct StateT * v76) {
  int v77 = v76->timer;
  int v82 = v77 + 1;
  v76->timer = v82;
  int * v79 = v76->regs;
  v79[10] = 1;
  return v76;
}

struct StateT * slot_6(struct StateT * v103) {
  int v104 = v103->timer;
  int v113 = v104 + 1;
  v103->timer = v113;
  int * v106 = v103->regs;
  int v107 = v106[5];
  int * v108 = v103->mem;
  int v117 = (int)((unsigned int)v107 >> 2);
  int v109 = v108[v117];
  v106[10] = v109;
  struct StateT * v111 = slot_7(v103);
  return v111;
}

struct StateT * slot_5(struct StateT * v86) {
  int v87 = v86->timer;
  int v95 = v87 + 1;
  v86->timer = v95;
  int * v89 = v86->regs;
  int v90 = v89[12];
  int v91 = v89[14];
  int v100 = v90 + v91;
  v89[5] = v100;
  struct StateT * v93 = slot_6(v86);
  return v93;
}

struct StateT * slot_2(struct StateT * v28) {
  int v29 = v28->timer;
  int v35 = v29 + 1;
  v28->timer = v35;
  int * v31 = v28->regs;
  v31[14] = 0;
  struct StateT * v33 = slot_3(v28);
  return v33;
}

struct StateT * slot_7(struct StateT * v122) {
  int v123 = v122->timer;
  int v131 = v123 + 1;
  v122->timer = v131;
  int * v125 = v122->regs;
  int v126 = v125[13];
  int v127 = v125[14];
  int v136 = v126 + v127;
  v125[6] = v136;
  struct StateT * v129 = slot_8(v122);
  return v129;
}

struct StateT * slot_3(struct StateT * v41) {
  int v42 = v41->timer;
  int v48 = v42 + 1;
  v41->timer = v48;
  int * v44 = v41->regs;
  v44[15] = 16;
  struct StateT * v46 = slot_4(v41);
  return v46;
}

struct StateT * snippet(struct StateT * v0) {
  struct StateT * v1 = slot_0(v0);
  return v1;
}

struct StateT * slot_10(struct StateT * v193) {
  int v194 = v193->timer;
  int v201 = v194 + 1;
  v193->timer = v201;
  int * v196 = v193->regs;
  int v197 = v196[14];
  int v204 = v197 + 4;
  v196[14] = v204;
  struct StateT * v199 = slot_11(v193);
  return v199;
}

struct StateT * slot_1(struct StateT * v15) {
  int v16 = v15->timer;
  int v22 = v16 + 1;
  v15->timer = v22;
  int * v18 = v15->regs;
  v18[13] = 80;
  struct StateT * v20 = slot_2(v15);
  return v20;
}

struct StateT * slot_8(struct StateT * v139) {
  int v140 = v139->timer;
  int v149 = v140 + 1;
  v139->timer = v149;
  int * v142 = v139->regs;
  int v143 = v142[6];
  int * v144 = v139->mem;
  int v153 = (int)((unsigned int)v143 >> 2);
  int v145 = v144[v153];
  v142[11] = v145;
  struct StateT * v147 = slot_9(v139);
  return v147;
}

struct StateT * slot_4(struct StateT * v54) {
  int v55 = v54->timer;
  int v66 = v55 + 1;
  v54->timer = v66;
  int * v57 = v54->regs;
  int v58 = v57[14];
  int v59 = v57[15];
  bool v70 = v58 >= v59;
  struct StateT * v64;
  if (v70) {
    struct StateT * v60 = slot_14(v54);
    v64 = v60;
  } else {
    struct StateT * v62 = slot_5(v54);
    v64 = v62;
  }
  return v64;
}

struct StateT * slot_13(struct StateT * v207) {
  int v208 = v207->timer;
  int v211 = v208 + 1;
  v207->timer = v211;
  return v207;
}

struct StateT * slot_9(struct StateT * v158) {
  int v159 = v158->timer;
  int v170 = v159 + 1;
  v158->timer = v170;
  int * v161 = v158->regs;
  int v162 = v161[10];
  int v163 = v161[11];
  bool v174 = !(v162 == v163);
  struct StateT * v168;
  if (v174) {
    struct StateT * v164 = slot_12(v158);
    v168 = v164;
  } else {
    struct StateT * v166 = slot_10(v158);
    v168 = v166;
  }
  return v168;
}

struct StateT * slot_11(struct StateT * v212) {
  int v213 = v212->timer;
  int v217 = v213 + 1;
  v212->timer = v217;
  struct StateT * v215 = slot_4(v212);
  return v215;
}

struct StateT * slot_0(struct StateT * v2) {
  int v3 = v2->timer;
  int v9 = v3 + 1;
  v2->timer = v9;
  int * v5 = v2->regs;
  v5[12] = 0;
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