// verify: leak (CBMC should report VERIFICATION FAILED) [unwind 33]

#define NUM_REGS 32
#define MEM_SIZE 30
#define SECRET_SIZE 10
#define SECRET_OFFSET 20
#define CACHE_LRU_SIZE 10
#ifndef CBMC
#define __CPROVER_assert(b,s) 0
#define nondet_uint() 0
#else
int nondet_uint();
#endif
int bounded(int low, int high) {
  int x = nondet_uint();
  __CPROVER_assume(low <= x && x <= high);
  return x;
}

/*****************************************
Emitting C Generated Code
*******************************************/

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

struct StateT2 {
  struct StateT * a;
  struct StateT * b;
};

struct StateT {
  int regs[32];
  int mem[30];
  int saved_regs[32];
  int cache_keys[10];
  int cache_vals[10];
  int timer;
};

void lockstep_assert(bool);
void lockstep_assume(bool);

struct StateT2 * slot_12(struct StateT2 * v231_p);
struct StateT2 * slot_14(struct StateT2 * v52_p);
struct StateT2 * slot_6(struct StateT2 * v99_p);
struct StateT2 * slot_16(struct StateT2 * v210_p);
struct StateT2 * slot_5(struct StateT2 * v86_p);
struct StateT2 * slot_2(struct StateT2 * v32_p);
struct StateT2 * slot_7(struct StateT2 * v115_p);
struct StateT2 * slot_3(struct StateT2 * v57_p);
struct StateT2 * snippet(struct StateT2 * v0_p);
struct StateT2 * slot_10(struct StateT2 * v194_p);
struct StateT2 * slot_1(struct StateT2 * v19_p);
struct StateT2 * slot_8(struct StateT2 * v136_p);
struct StateT2 * slot_4(struct StateT2 * v70_p);
struct StateT2 * slot_13(struct StateT2 * v247_p);
struct StateT2 * slot_15(struct StateT2 * v181_p);
struct StateT2 * slot_9(struct StateT2 * v157_p);
struct StateT2 * slot_11(struct StateT2 * v215_p);
struct StateT2 * slot_0(struct StateT2 * v2_p);
struct StateT2 * slot_12(struct StateT2 * v231_p) {
  lockstep_assert(((v231_p->a)->timer) == ((v231_p->b)->timer));
  lockstep_assume(((v231_p->a)->timer) == ((v231_p->b)->timer));
  int v232_a = (v231_p->a)->timer;
  int v232_b = (v231_p->b)->timer;
  int v240_a = v232_a + 1;
  int v240_b = v232_b + 1;
  (v231_p->a)->timer = v240_a;
  (v231_p->b)->timer = v240_b;
  int * v234_a = (v231_p->a)->regs;
  int * v234_b = (v231_p->b)->regs;
  int v235_a = v234_a[13];
  int v235_b = v234_b[13];
  int * v236_a = (v231_p->a)->regs;
  int * v236_b = (v231_p->b)->regs;
  int v244_a = v235_a + 4;
  int v244_b = v235_b + 4;
  v236_a[13] = v244_a;
  v236_b[13] = v244_b;
  struct StateT2 * v238_p = slot_13(v231_p);
  return v238_p;
}

struct StateT2 * slot_14(struct StateT2 * v52_p) {
  lockstep_assert(((v52_p->a)->timer) == ((v52_p->b)->timer));
  lockstep_assume(((v52_p->a)->timer) == ((v52_p->b)->timer));
  int v53_a = (v52_p->a)->timer;
  int v53_b = (v52_p->b)->timer;
  int v56_a = v53_a + 1;
  int v56_b = v53_b + 1;
  (v52_p->a)->timer = v56_a;
  (v52_p->b)->timer = v56_b;
  return v52_p;
}

struct StateT2 * slot_6(struct StateT2 * v99_p) {
  lockstep_assert(((v99_p->a)->timer) == ((v99_p->b)->timer));
  lockstep_assume(((v99_p->a)->timer) == ((v99_p->b)->timer));
  int v100_a = (v99_p->a)->timer;
  int v100_b = (v99_p->b)->timer;
  int v108_a = v100_a + 1;
  int v108_b = v100_b + 1;
  (v99_p->a)->timer = v108_a;
  (v99_p->b)->timer = v108_b;
  int * v102_a = (v99_p->a)->regs;
  int * v102_b = (v99_p->b)->regs;
  int v103_a = v102_a[13];
  int v103_b = v102_b[13];
  int * v104_a = (v99_p->a)->regs;
  int * v104_b = (v99_p->b)->regs;
  v104_a[13] = v103_a;
  v104_b[13] = v103_b;
  struct StateT2 * v106_p = slot_7(v99_p);
  return v106_p;
}

struct StateT2 * slot_16(struct StateT2 * v210_p) {
  lockstep_assert(((v210_p->a)->timer) == ((v210_p->b)->timer));
  lockstep_assume(((v210_p->a)->timer) == ((v210_p->b)->timer));
  int v211_a = (v210_p->a)->timer;
  int v211_b = (v210_p->b)->timer;
  int v214_a = v211_a + 1;
  int v214_b = v211_b + 1;
  (v210_p->a)->timer = v214_a;
  (v210_p->b)->timer = v214_b;
  return v210_p;
}

struct StateT2 * slot_5(struct StateT2 * v86_p) {
  lockstep_assert(((v86_p->a)->timer) == ((v86_p->b)->timer));
  lockstep_assume(((v86_p->a)->timer) == ((v86_p->b)->timer));
  int v87_a = (v86_p->a)->timer;
  int v87_b = (v86_p->b)->timer;
  int v93_a = v87_a + 1;
  int v93_b = v87_b + 1;
  (v86_p->a)->timer = v93_a;
  (v86_p->b)->timer = v93_b;
  int * v89_a = (v86_p->a)->regs;
  int * v89_b = (v86_p->b)->regs;
  v89_a[13] = 0;
  v89_b[13] = 0;
  struct StateT2 * v91_p = slot_6(v86_p);
  return v91_p;
}

struct StateT2 * slot_2(struct StateT2 * v32_p) {
  lockstep_assert(((v32_p->a)->timer) == ((v32_p->b)->timer));
  lockstep_assume(((v32_p->a)->timer) == ((v32_p->b)->timer));
  int v33_a = (v32_p->a)->timer;
  int v33_b = (v32_p->b)->timer;
  int v43_a = v33_a + 1;
  int v43_b = v33_b + 1;
  (v32_p->a)->timer = v43_a;
  (v32_p->b)->timer = v43_b;
  int * v35_a = (v32_p->a)->regs;
  int * v35_b = (v32_p->b)->regs;
  int v36_a = v35_a[11];
  int v36_b = v35_b[11];
  bool v46_a = 0 >= v36_a;
  bool v46_b = 0 >= v36_b;
  lockstep_assert(v46_a == v46_b);
  lockstep_assume(v46_a == v46_b);
  struct StateT2 * v41_p;
  if (v46_a) {
    struct StateT2 * v37_p = slot_14(v32_p);
    v41_p = v37_p;
  } else {
    struct StateT2 * v39_p = slot_3(v32_p);
    v41_p = v39_p;
  }
  return v41_p;
}

struct StateT2 * slot_7(struct StateT2 * v115_p) {
  lockstep_assert(((v115_p->a)->timer) == ((v115_p->b)->timer));
  lockstep_assume(((v115_p->a)->timer) == ((v115_p->b)->timer));
  int v116_a = (v115_p->a)->timer;
  int v116_b = (v115_p->b)->timer;
  int v126_a = v116_a + 1;
  int v126_b = v116_b + 1;
  (v115_p->a)->timer = v126_a;
  (v115_p->b)->timer = v126_b;
  int * v118_a = (v115_p->a)->regs;
  int * v118_b = (v115_p->b)->regs;
  int v119_a = v118_a[12];
  int v119_b = v118_b[12];
  int * v120_a = (v115_p->a)->mem;
  int * v120_b = (v115_p->b)->mem;
  int v130_a = (int)((unsigned int)v119_a >> 2);
  int v130_b = (int)((unsigned int)v119_b >> 2);
  int v121_a = v120_a[v130_a];
  int v121_b = v120_b[v130_b];
  int * v122_a = (v115_p->a)->regs;
  int * v122_b = (v115_p->b)->regs;
  v122_a[14] = v121_a;
  v122_b[14] = v121_b;
  struct StateT2 * v124_p = slot_8(v115_p);
  return v124_p;
}

struct StateT2 * slot_3(struct StateT2 * v57_p) {
  lockstep_assert(((v57_p->a)->timer) == ((v57_p->b)->timer));
  lockstep_assume(((v57_p->a)->timer) == ((v57_p->b)->timer));
  int v58_a = (v57_p->a)->timer;
  int v58_b = (v57_p->b)->timer;
  int v64_a = v58_a + 1;
  int v64_b = v58_b + 1;
  (v57_p->a)->timer = v64_a;
  (v57_p->b)->timer = v64_b;
  int * v60_a = (v57_p->a)->regs;
  int * v60_b = (v57_p->b)->regs;
  v60_a[12] = 0;
  v60_b[12] = 0;
  struct StateT2 * v62_p = slot_4(v57_p);
  return v62_p;
}

struct StateT2 * snippet(struct StateT2 * v0_p) {
  lockstep_assert(((v0_p->a)->timer) == ((v0_p->b)->timer));
  lockstep_assume(((v0_p->a)->timer) == ((v0_p->b)->timer));
  struct StateT2 * v1_p = slot_0(v0_p);
  return v1_p;
}

struct StateT2 * slot_10(struct StateT2 * v194_p) {
  lockstep_assert(((v194_p->a)->timer) == ((v194_p->b)->timer));
  lockstep_assume(((v194_p->a)->timer) == ((v194_p->b)->timer));
  int v195_a = (v194_p->a)->timer;
  int v195_b = (v194_p->b)->timer;
  int v203_a = v195_a + 1;
  int v203_b = v195_b + 1;
  (v194_p->a)->timer = v203_a;
  (v194_p->b)->timer = v203_b;
  int * v197_a = (v194_p->a)->regs;
  int * v197_b = (v194_p->b)->regs;
  int v198_a = v197_a[11];
  int v198_b = v197_b[11];
  int * v199_a = (v194_p->a)->regs;
  int * v199_b = (v194_p->b)->regs;
  int v207_a = v198_a + -1;
  int v207_b = v198_b + -1;
  v199_a[11] = v207_a;
  v199_b[11] = v207_b;
  struct StateT2 * v201_p = slot_11(v194_p);
  return v201_p;
}

struct StateT2 * slot_1(struct StateT2 * v19_p) {
  lockstep_assert(((v19_p->a)->timer) == ((v19_p->b)->timer));
  lockstep_assume(((v19_p->a)->timer) == ((v19_p->b)->timer));
  int v20_a = (v19_p->a)->timer;
  int v20_b = (v19_p->b)->timer;
  int v26_a = v20_a + 1;
  int v26_b = v20_b + 1;
  (v19_p->a)->timer = v26_a;
  (v19_p->b)->timer = v26_b;
  int * v22_a = (v19_p->a)->regs;
  int * v22_b = (v19_p->b)->regs;
  v22_a[10] = 1;
  v22_b[10] = 1;
  struct StateT2 * v24_p = slot_2(v19_p);
  return v24_p;
}

struct StateT2 * slot_8(struct StateT2 * v136_p) {
  lockstep_assert(((v136_p->a)->timer) == ((v136_p->b)->timer));
  lockstep_assume(((v136_p->a)->timer) == ((v136_p->b)->timer));
  int v137_a = (v136_p->a)->timer;
  int v137_b = (v136_p->b)->timer;
  int v147_a = v137_a + 1;
  int v147_b = v137_b + 1;
  (v136_p->a)->timer = v147_a;
  (v136_p->b)->timer = v147_b;
  int * v139_a = (v136_p->a)->regs;
  int * v139_b = (v136_p->b)->regs;
  int v140_a = v139_a[13];
  int v140_b = v139_b[13];
  int * v141_a = (v136_p->a)->mem;
  int * v141_b = (v136_p->b)->mem;
  int v151_a = (int)((unsigned int)v140_a >> 2);
  int v151_b = (int)((unsigned int)v140_b >> 2);
  int v142_a = v141_a[v151_a];
  int v142_b = v141_b[v151_b];
  int * v143_a = (v136_p->a)->regs;
  int * v143_b = (v136_p->b)->regs;
  v143_a[15] = v142_a;
  v143_b[15] = v142_b;
  struct StateT2 * v145_p = slot_9(v136_p);
  return v145_p;
}

struct StateT2 * slot_4(struct StateT2 * v70_p) {
  lockstep_assert(((v70_p->a)->timer) == ((v70_p->b)->timer));
  lockstep_assume(((v70_p->a)->timer) == ((v70_p->b)->timer));
  int v71_a = (v70_p->a)->timer;
  int v71_b = (v70_p->b)->timer;
  int v79_a = v71_a + 1;
  int v79_b = v71_b + 1;
  (v70_p->a)->timer = v79_a;
  (v70_p->b)->timer = v79_b;
  int * v73_a = (v70_p->a)->regs;
  int * v73_b = (v70_p->b)->regs;
  int v74_a = v73_a[12];
  int v74_b = v73_b[12];
  int * v75_a = (v70_p->a)->regs;
  int * v75_b = (v70_p->b)->regs;
  int v83_a = v74_a + 16;
  int v83_b = v74_b + 16;
  v75_a[12] = v83_a;
  v75_b[12] = v83_b;
  struct StateT2 * v77_p = slot_5(v70_p);
  return v77_p;
}

struct StateT2 * slot_13(struct StateT2 * v247_p) {
  lockstep_assert(((v247_p->a)->timer) == ((v247_p->b)->timer));
  lockstep_assume(((v247_p->a)->timer) == ((v247_p->b)->timer));
  int v248_a = (v247_p->a)->timer;
  int v248_b = (v247_p->b)->timer;
  int v258_a = v248_a + 1;
  int v258_b = v248_b + 1;
  (v247_p->a)->timer = v258_a;
  (v247_p->b)->timer = v258_b;
  int * v250_a = (v247_p->a)->regs;
  int * v250_b = (v247_p->b)->regs;
  int v251_a = v250_a[11];
  int v251_b = v250_b[11];
  bool v261_a = !(v251_a == 0);
  bool v261_b = !(v251_b == 0);
  lockstep_assert(v261_a == v261_b);
  lockstep_assume(v261_a == v261_b);
  struct StateT2 * v256_p;
  if (v261_a) {
    struct StateT2 * v252_p = slot_7(v247_p);
    v256_p = v252_p;
  } else {
    struct StateT2 * v254_p = slot_14(v247_p);
    v256_p = v254_p;
  }
  return v256_p;
}

struct StateT2 * slot_15(struct StateT2 * v181_p) {
  lockstep_assert(((v181_p->a)->timer) == ((v181_p->b)->timer));
  lockstep_assume(((v181_p->a)->timer) == ((v181_p->b)->timer));
  int v182_a = (v181_p->a)->timer;
  int v182_b = (v181_p->b)->timer;
  int v188_a = v182_a + 1;
  int v188_b = v182_b + 1;
  (v181_p->a)->timer = v188_a;
  (v181_p->b)->timer = v188_b;
  int * v184_a = (v181_p->a)->regs;
  int * v184_b = (v181_p->b)->regs;
  v184_a[10] = 0;
  v184_b[10] = 0;
  struct StateT2 * v186_p = slot_16(v181_p);
  return v186_p;
}

struct StateT2 * slot_9(struct StateT2 * v157_p) {
  lockstep_assert(((v157_p->a)->timer) == ((v157_p->b)->timer));
  lockstep_assume(((v157_p->a)->timer) == ((v157_p->b)->timer));
  int v158_a = (v157_p->a)->timer;
  int v158_b = (v157_p->b)->timer;
  int v170_a = v158_a + 1;
  int v170_b = v158_b + 1;
  (v157_p->a)->timer = v170_a;
  (v157_p->b)->timer = v170_b;
  int * v160_a = (v157_p->a)->regs;
  int * v160_b = (v157_p->b)->regs;
  int v161_a = v160_a[14];
  int v161_b = v160_b[14];
  int * v162_a = (v157_p->a)->regs;
  int * v162_b = (v157_p->b)->regs;
  int v163_a = v162_a[15];
  int v163_b = v162_b[15];
  bool v175_a = !(v161_a == v163_a);
  bool v175_b = !(v161_b == v163_b);
  lockstep_assert(v175_a == v175_b);
  lockstep_assume(v175_a == v175_b);
  struct StateT2 * v168_p;
  if (v175_a) {
    struct StateT2 * v164_p = slot_15(v157_p);
    v168_p = v164_p;
  } else {
    struct StateT2 * v166_p = slot_10(v157_p);
    v168_p = v166_p;
  }
  return v168_p;
}

struct StateT2 * slot_11(struct StateT2 * v215_p) {
  lockstep_assert(((v215_p->a)->timer) == ((v215_p->b)->timer));
  lockstep_assume(((v215_p->a)->timer) == ((v215_p->b)->timer));
  int v216_a = (v215_p->a)->timer;
  int v216_b = (v215_p->b)->timer;
  int v224_a = v216_a + 1;
  int v224_b = v216_b + 1;
  (v215_p->a)->timer = v224_a;
  (v215_p->b)->timer = v224_b;
  int * v218_a = (v215_p->a)->regs;
  int * v218_b = (v215_p->b)->regs;
  int v219_a = v218_a[12];
  int v219_b = v218_b[12];
  int * v220_a = (v215_p->a)->regs;
  int * v220_b = (v215_p->b)->regs;
  int v228_a = v219_a + 4;
  int v228_b = v219_b + 4;
  v220_a[12] = v228_a;
  v220_b[12] = v228_b;
  struct StateT2 * v222_p = slot_12(v215_p);
  return v222_p;
}

struct StateT2 * slot_0(struct StateT2 * v2_p) {
  lockstep_assert(((v2_p->a)->timer) == ((v2_p->b)->timer));
  lockstep_assume(((v2_p->a)->timer) == ((v2_p->b)->timer));
  int v3_a = (v2_p->a)->timer;
  int v3_b = (v2_p->b)->timer;
  int v11_a = v3_a + 1;
  int v11_b = v3_b + 1;
  (v2_p->a)->timer = v11_a;
  (v2_p->b)->timer = v11_b;
  int * v5_a = (v2_p->a)->regs;
  int * v5_b = (v2_p->b)->regs;
  int v6_a = v5_a[10];
  int v6_b = v5_b[10];
  int * v7_a = (v2_p->a)->regs;
  int * v7_b = (v2_p->b)->regs;
  v7_a[11] = v6_a;
  v7_b[11] = v6_b;
  struct StateT2 * v9_p = slot_1(v2_p);
  return v9_p;
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

void lockstep_assert(bool c) { __CPROVER_assert(c, "lockstep drift"); }
void lockstep_assume(bool c) { __CPROVER_assume(c); }

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
  struct StateT2 p = { .a = &s1, .b = &s2 };
  struct StateT2 *p_ = snippet(&p);
  __CPROVER_assert(p_->a->timer==p_->b->timer, "timing leak");
  return 0;
}