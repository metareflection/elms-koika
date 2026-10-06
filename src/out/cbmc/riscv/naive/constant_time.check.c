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

struct StateT * slot_12(struct StateT * v214);
struct StateT * slot_14(struct StateT * v89);
struct StateT * slot_6(struct StateT * v109);
struct StateT * slot_5(struct StateT * v67);
struct StateT * slot_2(struct StateT * v28);
struct StateT * slot_7(struct StateT * v126);
struct StateT * slot_3(struct StateT * v41);
struct StateT * snippet(struct StateT * v0);
struct StateT * slot_10(struct StateT * v181);
struct StateT * slot_1(struct StateT * v15);
struct StateT * slot_8(struct StateT * v145);
struct StateT * slot_4(struct StateT * v54);
struct StateT * slot_13(struct StateT * v228);
struct StateT * slot_9(struct StateT * v162);
struct StateT * slot_11(struct StateT * v198);
struct StateT * slot_0(struct StateT * v2);
struct StateT * slot_12(struct StateT * v214) {
  int v215 = v214->timer;
  int v222 = v215 + 1;
  v214->timer = v222;
  int * v217 = v214->regs;
  int v218 = v217[14];
  int v225 = v218 + 4;
  v217[14] = v225;
  struct StateT * v220 = slot_13(v214);
  return v220;
}

struct StateT * slot_14(struct StateT * v89) {
  int v90 = v89->timer;
  int v100 = v90 + 1;
  v89->timer = v100;
  int * v92 = v89->regs;
  int v93 = v92[5];
  bool v103 = (v93 ^ -2147483648) < -2147483647;
  int v96;
  if (v103) {
    v96 = 1;
  } else {
    v96 = 0;
  }
  int * v97 = v89->regs;
  v97[11] = v96;
  return v89;
}

struct StateT * slot_6(struct StateT * v109) {
  int v110 = v109->timer;
  int v118 = v110 + 1;
  v109->timer = v118;
  int * v112 = v109->regs;
  int v113 = v112[12];
  int v114 = v112[14];
  int v123 = v113 + v114;
  v112[6] = v123;
  struct StateT * v116 = slot_7(v109);
  return v116;
}

struct StateT * slot_5(struct StateT * v67) {
  int v68 = v67->timer;
  int v79 = v68 + 1;
  v67->timer = v79;
  int * v70 = v67->regs;
  int v71 = v70[14];
  int v72 = v70[15];
  bool v83 = v71 >= v72;
  struct StateT * v77;
  if (v83) {
    struct StateT * v73 = slot_14(v67);
    v77 = v73;
  } else {
    struct StateT * v75 = slot_6(v67);
    v77 = v75;
  }
  return v77;
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

struct StateT * slot_7(struct StateT * v126) {
  int v127 = v126->timer;
  int v136 = v127 + 1;
  v126->timer = v136;
  int * v129 = v126->regs;
  int v130 = v129[6];
  int * v131 = v126->mem;
  int v140 = (int)((unsigned int)v130 >> 2);
  int v132 = v131[v140];
  v129[7] = v132;
  struct StateT * v134 = slot_8(v126);
  return v134;
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

struct StateT * slot_10(struct StateT * v181) {
  int v182 = v181->timer;
  int v190 = v182 + 1;
  v181->timer = v190;
  int * v184 = v181->regs;
  int v185 = v184[7];
  int v186 = v184[9];
  int v195 = v185 ^ v186;
  v184[16] = v195;
  struct StateT * v188 = slot_11(v181);
  return v188;
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

struct StateT * slot_8(struct StateT * v145) {
  int v146 = v145->timer;
  int v154 = v146 + 1;
  v145->timer = v154;
  int * v148 = v145->regs;
  int v149 = v148[13];
  int v150 = v148[14];
  int v159 = v149 + v150;
  v148[8] = v159;
  struct StateT * v152 = slot_9(v145);
  return v152;
}

struct StateT * slot_4(struct StateT * v54) {
  int v55 = v54->timer;
  int v61 = v55 + 1;
  v54->timer = v61;
  int * v57 = v54->regs;
  v57[5] = 0;
  struct StateT * v59 = slot_5(v54);
  return v59;
}

struct StateT * slot_13(struct StateT * v228) {
  int v229 = v228->timer;
  int v233 = v229 + 1;
  v228->timer = v233;
  struct StateT * v231 = slot_5(v228);
  return v231;
}

struct StateT * slot_9(struct StateT * v162) {
  int v163 = v162->timer;
  int v172 = v163 + 1;
  v162->timer = v172;
  int * v165 = v162->regs;
  int v166 = v165[8];
  int * v167 = v162->mem;
  int v176 = (int)((unsigned int)v166 >> 2);
  int v168 = v167[v176];
  v165[9] = v168;
  struct StateT * v170 = slot_10(v162);
  return v170;
}

struct StateT * slot_11(struct StateT * v198) {
  int v199 = v198->timer;
  int v207 = v199 + 1;
  v198->timer = v207;
  int * v201 = v198->regs;
  int v202 = v201[5];
  int v203 = v201[16];
  int v211 = v202 | v203;
  v201[5] = v211;
  struct StateT * v205 = slot_12(v198);
  return v205;
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