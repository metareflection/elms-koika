// verify: leak (KLEE should report a failing assertion) [budget 120s]
#define NUM_REGS 32
#define MEM_SIZE 30
#define SECRET_SIZE 10
#define SECRET_OFFSET 20
#define CACHE_LRU_SIZE 10

#ifdef KLEE
#include <assert.h>
#include <klee/klee.h>
#define koika_assert(b, s) klee_assert(b)
#define koika_assume(b) klee_assume(b)
#define koika_draw(x) klee_make_symbolic(&(x), sizeof(x), #x)
#else
#define koika_assert(b, s) 0
#define koika_assume(b) 0
#define koika_draw(x) ((x) = 0)
#endif
int bounded(int low, int high) {
  int x;
  koika_draw(x);
  koika_assume(low <= x && x <= high);
  return x;
}

/*****************************************
Emitting C Generated Code
*******************************************/

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

struct StateT {
  int regs[32];
  int mem[30];
  int saved_regs[32];
  int cache_keys[10];
  int cache_vals[10];
  int timer;
};

struct StateT * slot_12(struct StateT * v231);
struct StateT * slot_14(struct StateT * v52);
struct StateT * slot_6(struct StateT * v99);
struct StateT * slot_16(struct StateT * v210);
struct StateT * slot_5(struct StateT * v86);
struct StateT * slot_2(struct StateT * v32);
struct StateT * slot_7(struct StateT * v115);
struct StateT * slot_3(struct StateT * v57);
struct StateT * snippet(struct StateT * v0);
struct StateT * slot_10(struct StateT * v194);
struct StateT * slot_1(struct StateT * v19);
struct StateT * slot_8(struct StateT * v136);
struct StateT * slot_4(struct StateT * v70);
struct StateT * slot_13(struct StateT * v247);
struct StateT * slot_15(struct StateT * v181);
struct StateT * slot_9(struct StateT * v157);
struct StateT * slot_11(struct StateT * v215);
struct StateT * slot_0(struct StateT * v2);
struct StateT * slot_12(struct StateT * v231) {
  int v232 = v231->timer;
  int v240 = v232 + 1;
  v231->timer = v240;
  int * v234 = v231->regs;
  int v235 = v234[13];
  int * v236 = v231->regs;
  int v244 = v235 + 4;
  v236[13] = v244;
  struct StateT * v238 = slot_13(v231);
  return v238;
}

struct StateT * slot_14(struct StateT * v52) {
  int v53 = v52->timer;
  int v56 = v53 + 1;
  v52->timer = v56;
  return v52;
}

struct StateT * slot_6(struct StateT * v99) {
  int v100 = v99->timer;
  int v108 = v100 + 1;
  v99->timer = v108;
  int * v102 = v99->regs;
  int v103 = v102[13];
  int * v104 = v99->regs;
  v104[13] = v103;
  struct StateT * v106 = slot_7(v99);
  return v106;
}

struct StateT * slot_16(struct StateT * v210) {
  int v211 = v210->timer;
  int v214 = v211 + 1;
  v210->timer = v214;
  return v210;
}

struct StateT * slot_5(struct StateT * v86) {
  int v87 = v86->timer;
  int v93 = v87 + 1;
  v86->timer = v93;
  int * v89 = v86->regs;
  v89[13] = 0;
  struct StateT * v91 = slot_6(v86);
  return v91;
}

struct StateT * slot_2(struct StateT * v32) {
  int v33 = v32->timer;
  int v43 = v33 + 1;
  v32->timer = v43;
  int * v35 = v32->regs;
  int v36 = v35[11];
  bool v46 = 0 >= v36;
  struct StateT * v41;
  if (v46) {
    struct StateT * v37 = slot_14(v32);
    v41 = v37;
  } else {
    struct StateT * v39 = slot_3(v32);
    v41 = v39;
  }
  return v41;
}

struct StateT * slot_7(struct StateT * v115) {
  int v116 = v115->timer;
  int v126 = v116 + 1;
  v115->timer = v126;
  int * v118 = v115->regs;
  int v119 = v118[12];
  int * v120 = v115->mem;
  int v130 = (int)((unsigned int)v119 >> 2);
  int v121 = v120[v130];
  int * v122 = v115->regs;
  v122[14] = v121;
  struct StateT * v124 = slot_8(v115);
  return v124;
}

struct StateT * slot_3(struct StateT * v57) {
  int v58 = v57->timer;
  int v64 = v58 + 1;
  v57->timer = v64;
  int * v60 = v57->regs;
  v60[12] = 0;
  struct StateT * v62 = slot_4(v57);
  return v62;
}

struct StateT * snippet(struct StateT * v0) {
  struct StateT * v1 = slot_0(v0);
  return v1;
}

struct StateT * slot_10(struct StateT * v194) {
  int v195 = v194->timer;
  int v203 = v195 + 1;
  v194->timer = v203;
  int * v197 = v194->regs;
  int v198 = v197[11];
  int * v199 = v194->regs;
  int v207 = v198 + -1;
  v199[11] = v207;
  struct StateT * v201 = slot_11(v194);
  return v201;
}

struct StateT * slot_1(struct StateT * v19) {
  int v20 = v19->timer;
  int v26 = v20 + 1;
  v19->timer = v26;
  int * v22 = v19->regs;
  v22[10] = 1;
  struct StateT * v24 = slot_2(v19);
  return v24;
}

struct StateT * slot_8(struct StateT * v136) {
  int v137 = v136->timer;
  int v147 = v137 + 1;
  v136->timer = v147;
  int * v139 = v136->regs;
  int v140 = v139[13];
  int * v141 = v136->mem;
  int v151 = (int)((unsigned int)v140 >> 2);
  int v142 = v141[v151];
  int * v143 = v136->regs;
  v143[15] = v142;
  struct StateT * v145 = slot_9(v136);
  return v145;
}

struct StateT * slot_4(struct StateT * v70) {
  int v71 = v70->timer;
  int v79 = v71 + 1;
  v70->timer = v79;
  int * v73 = v70->regs;
  int v74 = v73[12];
  int * v75 = v70->regs;
  int v83 = v74 + 16;
  v75[12] = v83;
  struct StateT * v77 = slot_5(v70);
  return v77;
}

struct StateT * slot_13(struct StateT * v247) {
  int v248 = v247->timer;
  int v258 = v248 + 1;
  v247->timer = v258;
  int * v250 = v247->regs;
  int v251 = v250[11];
  bool v261 = !(v251 == 0);
  struct StateT * v256;
  if (v261) {
    struct StateT * v252 = slot_7(v247);
    v256 = v252;
  } else {
    struct StateT * v254 = slot_14(v247);
    v256 = v254;
  }
  return v256;
}

struct StateT * slot_15(struct StateT * v181) {
  int v182 = v181->timer;
  int v188 = v182 + 1;
  v181->timer = v188;
  int * v184 = v181->regs;
  v184[10] = 0;
  struct StateT * v186 = slot_16(v181);
  return v186;
}

struct StateT * slot_9(struct StateT * v157) {
  int v158 = v157->timer;
  int v170 = v158 + 1;
  v157->timer = v170;
  int * v160 = v157->regs;
  int v161 = v160[14];
  int * v162 = v157->regs;
  int v163 = v162[15];
  bool v175 = !(v161 == v163);
  struct StateT * v168;
  if (v175) {
    struct StateT * v164 = slot_15(v157);
    v168 = v164;
  } else {
    struct StateT * v166 = slot_10(v157);
    v168 = v166;
  }
  return v168;
}

struct StateT * slot_11(struct StateT * v215) {
  int v216 = v215->timer;
  int v224 = v216 + 1;
  v215->timer = v224;
  int * v218 = v215->regs;
  int v219 = v218[12];
  int * v220 = v215->regs;
  int v228 = v219 + 4;
  v220[12] = v228;
  struct StateT * v222 = slot_12(v215);
  return v222;
}

struct StateT * slot_0(struct StateT * v2) {
  int v3 = v2->timer;
  int v11 = v3 + 1;
  v2->timer = v11;
  int * v5 = v2->regs;
  int v6 = v5[10];
  int * v7 = v2->regs;
  v7[11] = v6;
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
    s1.mem[0 + i] = bounded(0, 20);
    s2.mem[0 + i] = bounded(0, 20);
  }
  struct StateT *s1_ = snippet(&s1);
  struct StateT *s2_ = snippet(&s2);
  koika_assert(s1_->timer==s2_->timer, "timing leak");
  return 0;
}