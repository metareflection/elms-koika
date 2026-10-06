// verify: leak (KLEE should report a failing assertion) [budget 1200s]
#define NUM_REGS 32
#define MEM_SIZE 64
#define SECRET_SIZE 10
#define SECRET_OFFSET 20
#define CACHE_ENTRIES 12
#define CACHE_WORDS 24

#ifdef KLEE
#include <assert.h>
#include <klee/klee.h>
#define koika_assert(b, s) klee_assert(b)
#define koika_assume(b) klee_assume(b)
#define koika_draw(x) klee_make_symbolic(&(x), sizeof(x), #x)
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

struct StateT * slot_12(struct StateT * v215);
struct StateT * slot_14(struct StateT * v50);
struct StateT * slot_6(struct StateT * v95);
struct StateT * slot_5(struct StateT * v82);
struct StateT * slot_2(struct StateT * v30);
struct StateT * slot_7(struct StateT * v109);
struct StateT * slot_3(struct StateT * v55);
struct StateT * snippet(struct StateT * v0);
struct StateT * slot_10(struct StateT * v182);
struct StateT * slot_1(struct StateT * v17);
struct StateT * slot_8(struct StateT * v128);
struct StateT * slot_4(struct StateT * v68);
struct StateT * slot_13(struct StateT * v229);
struct StateT * slot_15(struct StateT * v169);
struct StateT * slot_9(struct StateT * v147);
struct StateT * slot_11(struct StateT * v201);
struct StateT * slot_0(struct StateT * v2);
struct StateT * slot_12(struct StateT * v215) {
  int v216 = v215->timer;
  int v223 = v216 + 1;
  v215->timer = v223;
  int * v218 = v215->regs;
  int v219 = v218[13];
  int v226 = v219 + 4;
  v218[13] = v226;
  struct StateT * v221 = slot_13(v215);
  return v221;
}

struct StateT * slot_14(struct StateT * v50) {
  int v51 = v50->timer;
  int v54 = v51 + 1;
  v50->timer = v54;
  return v50;
}

struct StateT * slot_6(struct StateT * v95) {
  int v96 = v95->timer;
  int v103 = v96 + 1;
  v95->timer = v103;
  int * v98 = v95->regs;
  int v99 = v98[13];
  v98[13] = v99;
  struct StateT * v101 = slot_7(v95);
  return v101;
}

struct StateT * slot_5(struct StateT * v82) {
  int v83 = v82->timer;
  int v89 = v83 + 1;
  v82->timer = v89;
  int * v85 = v82->regs;
  v85[13] = 0;
  struct StateT * v87 = slot_6(v82);
  return v87;
}

struct StateT * slot_2(struct StateT * v30) {
  int v31 = v30->timer;
  int v41 = v31 + 1;
  v30->timer = v41;
  int * v33 = v30->regs;
  int v34 = v33[11];
  bool v44 = 0 >= v34;
  struct StateT * v39;
  if (v44) {
    struct StateT * v35 = slot_14(v30);
    v39 = v35;
  } else {
    struct StateT * v37 = slot_3(v30);
    v39 = v37;
  }
  return v39;
}

struct StateT * slot_7(struct StateT * v109) {
  int v110 = v109->timer;
  int v119 = v110 + 1;
  v109->timer = v119;
  int * v112 = v109->regs;
  int v113 = v112[12];
  int * v114 = v109->mem;
  int v123 = (int)((unsigned int)v113 >> 2);
  int v115 = v114[v123];
  v112[14] = v115;
  struct StateT * v117 = slot_8(v109);
  return v117;
}

struct StateT * slot_3(struct StateT * v55) {
  int v56 = v55->timer;
  int v62 = v56 + 1;
  v55->timer = v62;
  int * v58 = v55->regs;
  v58[12] = 0;
  struct StateT * v60 = slot_4(v55);
  return v60;
}

struct StateT * snippet(struct StateT * v0) {
  struct StateT * v1 = slot_0(v0);
  return v1;
}

struct StateT * slot_10(struct StateT * v182) {
  int v183 = v182->timer;
  int v190 = v183 + 1;
  v182->timer = v190;
  int * v185 = v182->regs;
  int v186 = v185[11];
  int v193 = v186 + -1;
  v185[11] = v193;
  struct StateT * v188 = slot_11(v182);
  return v188;
}

struct StateT * slot_1(struct StateT * v17) {
  int v18 = v17->timer;
  int v24 = v18 + 1;
  v17->timer = v24;
  int * v20 = v17->regs;
  v20[10] = 1;
  struct StateT * v22 = slot_2(v17);
  return v22;
}

struct StateT * slot_8(struct StateT * v128) {
  int v129 = v128->timer;
  int v138 = v129 + 1;
  v128->timer = v138;
  int * v131 = v128->regs;
  int v132 = v131[13];
  int * v133 = v128->mem;
  int v142 = (int)((unsigned int)v132 >> 2);
  int v134 = v133[v142];
  v131[15] = v134;
  struct StateT * v136 = slot_9(v128);
  return v136;
}

struct StateT * slot_4(struct StateT * v68) {
  int v69 = v68->timer;
  int v76 = v69 + 1;
  v68->timer = v76;
  int * v71 = v68->regs;
  int v72 = v71[12];
  int v79 = v72 + 16;
  v71[12] = v79;
  struct StateT * v74 = slot_5(v68);
  return v74;
}

struct StateT * slot_13(struct StateT * v229) {
  int v230 = v229->timer;
  int v240 = v230 + 1;
  v229->timer = v240;
  int * v232 = v229->regs;
  int v233 = v232[11];
  bool v243 = !(v233 == 0);
  struct StateT * v238;
  if (v243) {
    struct StateT * v234 = slot_7(v229);
    v238 = v234;
  } else {
    struct StateT * v236 = slot_14(v229);
    v238 = v236;
  }
  return v238;
}

struct StateT * slot_15(struct StateT * v169) {
  int v170 = v169->timer;
  int v176 = v170 + 1;
  v169->timer = v176;
  int * v172 = v169->regs;
  v172[10] = 0;
  struct StateT * v174 = slot_14(v169);
  return v174;
}

struct StateT * slot_9(struct StateT * v147) {
  int v148 = v147->timer;
  int v159 = v148 + 1;
  v147->timer = v159;
  int * v150 = v147->regs;
  int v151 = v150[14];
  int v152 = v150[15];
  bool v163 = !(v151 == v152);
  struct StateT * v157;
  if (v163) {
    struct StateT * v153 = slot_15(v147);
    v157 = v153;
  } else {
    struct StateT * v155 = slot_10(v147);
    v157 = v155;
  }
  return v157;
}

struct StateT * slot_11(struct StateT * v201) {
  int v202 = v201->timer;
  int v209 = v202 + 1;
  v201->timer = v209;
  int * v204 = v201->regs;
  int v205 = v204[12];
  int v212 = v205 + 4;
  v204[12] = v212;
  struct StateT * v207 = slot_12(v201);
  return v207;
}

struct StateT * slot_0(struct StateT * v2) {
  int v3 = v2->timer;
  int v10 = v3 + 1;
  v2->timer = v10;
  int * v5 = v2->regs;
  int v6 = v5[10];
  v5[11] = v6;
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
  
  int n = bounded(0, 4);
  s1.regs[10] = n;
  s2.regs[10] = n;
  // guess, the attacker's: the same draw in both states
  for (int i=0; i<4; i++) {
    int v = bounded(0, 20);
    s1.mem[4 + i] = v;
    s2.mem[4 + i] = v;
  }
  
  // secret, secret: a different draw in each state
  for (int i=0; i<4; i++) {
    s1.mem[0 + i] = secret(0, 20);
    s2.mem[0 + i] = secret(0, 20);
  }
  struct StateT *s1_ = snippet(&s1);
  struct StateT *s2_ = snippet(&s2);
  koika_assert(s1_->timer==s2_->timer, "timing leak");
  return 0;
}