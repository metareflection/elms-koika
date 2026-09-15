// verify: leak (CBMC should report VERIFICATION FAILED) [unwind 33]
#define NUM_REGS 32
#define MEM_SIZE 30
#define SECRET_SIZE 10
#define SECRET_OFFSET 20
#define CACHE_LRU_SIZE 10

#ifdef CBMC
int nondet_uint();
#define koika_assert(b, s) __CPROVER_assert(b, s)
#define koika_assume(b) __CPROVER_assume(b)
#define koika_draw(x) ((x) = nondet_uint())
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

struct StateT2 * snippet(struct StateT2 * v0_p);
struct StateT2 * slot_1(struct StateT2 * v19_p);
struct StateT2 * slot_2(struct StateT2 * v124_p);
struct StateT2 * slot_3(struct StateT2 * v140_p);
struct StateT2 * slot_0(struct StateT2 * v2_p);
struct StateT2 * snippet(struct StateT2 * v0_p) {
  lockstep_assert(((v0_p->a)->timer) == ((v0_p->b)->timer));
  lockstep_assume(((v0_p->a)->timer) == ((v0_p->b)->timer));
  struct StateT2 * v1_p = slot_0(v0_p);
  return v1_p;
}

struct StateT2 * slot_1(struct StateT2 * v19_p) {
  lockstep_assert(((v19_p->a)->timer) == ((v19_p->b)->timer));
  lockstep_assume(((v19_p->a)->timer) == ((v19_p->b)->timer));
  int v20_a = (v19_p->a)->timer;
  int v20_b = (v19_p->b)->timer;
  int v78_a = v20_a + 1;
  int v78_b = v20_b + 1;
  (v19_p->a)->timer = v78_a;
  (v19_p->b)->timer = v78_b;
  int * v22_a = (v19_p->a)->regs;
  int * v22_b = (v19_p->b)->regs;
  int v23_a = v22_a[10];
  int v23_b = v22_b[10];
  int * v24_a = (v19_p->a)->cache_keys;
  int * v24_b = (v19_p->b)->cache_keys;
  int v25_a = v24_a[0];
  int v25_b = v24_b[0];
  bool v83_a = v25_a == ((int)((unsigned int)v23_a >> 2));
  bool v83_b = v25_b == ((int)((unsigned int)v23_b >> 2));
  int v73_a;
  if (v83_a) {
    int * v26_a = (v19_p->a)->cache_vals;
    int v27_a = v26_a[0];
    v73_a = v27_a;
  } else {
    int * v29_a = (v19_p->a)->cache_keys;
    int v30_a = v29_a[1];
    bool v88_a = v30_a == ((int)((unsigned int)v23_a >> 2));
    int v71_a;
    if (v88_a) {
      int * v31_a = (v19_p->a)->cache_vals;
      int v32_a = v31_a[1];
      int * v33_a = (v19_p->a)->cache_keys;
      int * v34_a = (v19_p->a)->cache_keys;
      int v35_a = v34_a[0];
      v33_a[1] = v35_a;
      int * v37_a = (v19_p->a)->cache_vals;
      int * v38_a = (v19_p->a)->cache_vals;
      int v39_a = v38_a[0];
      v37_a[1] = v39_a;
      int * v41_a = (v19_p->a)->cache_keys;
      int v97_a = (int)((unsigned int)v23_a >> 2);
      v41_a[0] = v97_a;
      int * v43_a = (v19_p->a)->cache_vals;
      v43_a[0] = v32_a;
      int v45_a = (v19_p->a)->timer;
      int v100_a = v45_a + 1;
      (v19_p->a)->timer = v100_a;
      v71_a = v32_a;
    } else {
      int * v48_a = (v19_p->a)->mem;
      int v102_a = (int)((unsigned int)v23_a >> 2);
      int v49_a = v48_a[v102_a];
      int * v50_a = (v19_p->a)->mem;
      int * v51_a = (v19_p->a)->cache_keys;
      int v52_a = v51_a[1];
      int * v53_a = (v19_p->a)->cache_vals;
      int v54_a = v53_a[1];
      v50_a[v52_a] = v54_a;
      int * v56_a = (v19_p->a)->cache_keys;
      int * v57_a = (v19_p->a)->cache_keys;
      int v58_a = v57_a[0];
      v56_a[1] = v58_a;
      int * v60_a = (v19_p->a)->cache_vals;
      int * v61_a = (v19_p->a)->cache_vals;
      int v62_a = v61_a[0];
      v60_a[1] = v62_a;
      int * v64_a = (v19_p->a)->cache_keys;
      v64_a[0] = v102_a;
      int * v66_a = (v19_p->a)->cache_vals;
      v66_a[0] = v49_a;
      int v68_a = (v19_p->a)->timer;
      int v117_a = v68_a + 100;
      (v19_p->a)->timer = v117_a;
      v71_a = v49_a;
    }
    v73_a = v71_a;
  }
  int v73_b;
  if (v83_b) {
    int * v26_b = (v19_p->b)->cache_vals;
    int v27_b = v26_b[0];
    v73_b = v27_b;
  } else {
    int * v29_b = (v19_p->b)->cache_keys;
    int v30_b = v29_b[1];
    bool v88_b = v30_b == ((int)((unsigned int)v23_b >> 2));
    int v71_b;
    if (v88_b) {
      int * v31_b = (v19_p->b)->cache_vals;
      int v32_b = v31_b[1];
      int * v33_b = (v19_p->b)->cache_keys;
      int * v34_b = (v19_p->b)->cache_keys;
      int v35_b = v34_b[0];
      v33_b[1] = v35_b;
      int * v37_b = (v19_p->b)->cache_vals;
      int * v38_b = (v19_p->b)->cache_vals;
      int v39_b = v38_b[0];
      v37_b[1] = v39_b;
      int * v41_b = (v19_p->b)->cache_keys;
      int v97_b = (int)((unsigned int)v23_b >> 2);
      v41_b[0] = v97_b;
      int * v43_b = (v19_p->b)->cache_vals;
      v43_b[0] = v32_b;
      int v45_b = (v19_p->b)->timer;
      int v100_b = v45_b + 1;
      (v19_p->b)->timer = v100_b;
      v71_b = v32_b;
    } else {
      int * v48_b = (v19_p->b)->mem;
      int v102_b = (int)((unsigned int)v23_b >> 2);
      int v49_b = v48_b[v102_b];
      int * v50_b = (v19_p->b)->mem;
      int * v51_b = (v19_p->b)->cache_keys;
      int v52_b = v51_b[1];
      int * v53_b = (v19_p->b)->cache_vals;
      int v54_b = v53_b[1];
      v50_b[v52_b] = v54_b;
      int * v56_b = (v19_p->b)->cache_keys;
      int * v57_b = (v19_p->b)->cache_keys;
      int v58_b = v57_b[0];
      v56_b[1] = v58_b;
      int * v60_b = (v19_p->b)->cache_vals;
      int * v61_b = (v19_p->b)->cache_vals;
      int v62_b = v61_b[0];
      v60_b[1] = v62_b;
      int * v64_b = (v19_p->b)->cache_keys;
      v64_b[0] = v102_b;
      int * v66_b = (v19_p->b)->cache_vals;
      v66_b[0] = v49_b;
      int v68_b = (v19_p->b)->timer;
      int v117_b = v68_b + 100;
      (v19_p->b)->timer = v117_b;
      v71_b = v49_b;
    }
    v73_b = v71_b;
  }
  int * v74_a = (v19_p->a)->regs;
  int * v74_b = (v19_p->b)->regs;
  v74_a[11] = v73_a;
  v74_b[11] = v73_b;
  struct StateT2 * v76_p = slot_2(v19_p);
  return v76_p;
}

struct StateT2 * slot_2(struct StateT2 * v124_p) {
  lockstep_assert(((v124_p->a)->timer) == ((v124_p->b)->timer));
  lockstep_assume(((v124_p->a)->timer) == ((v124_p->b)->timer));
  int v125_a = (v124_p->a)->timer;
  int v125_b = (v124_p->b)->timer;
  int v133_a = v125_a + 1;
  int v133_b = v125_b + 1;
  (v124_p->a)->timer = v133_a;
  (v124_p->b)->timer = v133_b;
  int * v127_a = (v124_p->a)->regs;
  int * v127_b = (v124_p->b)->regs;
  int v128_a = v127_a[11];
  int v128_b = v127_b[11];
  int * v129_a = (v124_p->a)->regs;
  int * v129_b = (v124_p->b)->regs;
  int v137_a = v128_a << 2;
  int v137_b = v128_b << 2;
  v129_a[11] = v137_a;
  v129_b[11] = v137_b;
  struct StateT2 * v131_p = slot_3(v124_p);
  return v131_p;
}

struct StateT2 * slot_3(struct StateT2 * v140_p) {
  lockstep_assert(((v140_p->a)->timer) == ((v140_p->b)->timer));
  lockstep_assume(((v140_p->a)->timer) == ((v140_p->b)->timer));
  int v141_a = (v140_p->a)->timer;
  int v141_b = (v140_p->b)->timer;
  int v198_a = v141_a + 1;
  int v198_b = v141_b + 1;
  (v140_p->a)->timer = v198_a;
  (v140_p->b)->timer = v198_b;
  int * v143_a = (v140_p->a)->regs;
  int * v143_b = (v140_p->b)->regs;
  int v144_a = v143_a[11];
  int v144_b = v143_b[11];
  int * v145_a = (v140_p->a)->cache_keys;
  int * v145_b = (v140_p->b)->cache_keys;
  int v146_a = v145_a[0];
  int v146_b = v145_b[0];
  bool v203_a = v146_a == ((int)((unsigned int)(v144_a + 16) >> 2));
  bool v203_b = v146_b == ((int)((unsigned int)(v144_b + 16) >> 2));
  int v194_a;
  if (v203_a) {
    int * v147_a = (v140_p->a)->cache_vals;
    int v148_a = v147_a[0];
    v194_a = v148_a;
  } else {
    int * v150_a = (v140_p->a)->cache_keys;
    int v151_a = v150_a[1];
    bool v208_a = v151_a == ((int)((unsigned int)(v144_a + 16) >> 2));
    int v192_a;
    if (v208_a) {
      int * v152_a = (v140_p->a)->cache_vals;
      int v153_a = v152_a[1];
      int * v154_a = (v140_p->a)->cache_keys;
      int * v155_a = (v140_p->a)->cache_keys;
      int v156_a = v155_a[0];
      v154_a[1] = v156_a;
      int * v158_a = (v140_p->a)->cache_vals;
      int * v159_a = (v140_p->a)->cache_vals;
      int v160_a = v159_a[0];
      v158_a[1] = v160_a;
      int * v162_a = (v140_p->a)->cache_keys;
      int v217_a = (int)((unsigned int)(v144_a + 16) >> 2);
      v162_a[0] = v217_a;
      int * v164_a = (v140_p->a)->cache_vals;
      v164_a[0] = v153_a;
      int v166_a = (v140_p->a)->timer;
      int v220_a = v166_a + 1;
      (v140_p->a)->timer = v220_a;
      v192_a = v153_a;
    } else {
      int * v169_a = (v140_p->a)->mem;
      int v222_a = (int)((unsigned int)(v144_a + 16) >> 2);
      int v170_a = v169_a[v222_a];
      int * v171_a = (v140_p->a)->mem;
      int * v172_a = (v140_p->a)->cache_keys;
      int v173_a = v172_a[1];
      int * v174_a = (v140_p->a)->cache_vals;
      int v175_a = v174_a[1];
      v171_a[v173_a] = v175_a;
      int * v177_a = (v140_p->a)->cache_keys;
      int * v178_a = (v140_p->a)->cache_keys;
      int v179_a = v178_a[0];
      v177_a[1] = v179_a;
      int * v181_a = (v140_p->a)->cache_vals;
      int * v182_a = (v140_p->a)->cache_vals;
      int v183_a = v182_a[0];
      v181_a[1] = v183_a;
      int * v185_a = (v140_p->a)->cache_keys;
      v185_a[0] = v222_a;
      int * v187_a = (v140_p->a)->cache_vals;
      v187_a[0] = v170_a;
      int v189_a = (v140_p->a)->timer;
      int v237_a = v189_a + 100;
      (v140_p->a)->timer = v237_a;
      v192_a = v170_a;
    }
    v194_a = v192_a;
  }
  int v194_b;
  if (v203_b) {
    int * v147_b = (v140_p->b)->cache_vals;
    int v148_b = v147_b[0];
    v194_b = v148_b;
  } else {
    int * v150_b = (v140_p->b)->cache_keys;
    int v151_b = v150_b[1];
    bool v208_b = v151_b == ((int)((unsigned int)(v144_b + 16) >> 2));
    int v192_b;
    if (v208_b) {
      int * v152_b = (v140_p->b)->cache_vals;
      int v153_b = v152_b[1];
      int * v154_b = (v140_p->b)->cache_keys;
      int * v155_b = (v140_p->b)->cache_keys;
      int v156_b = v155_b[0];
      v154_b[1] = v156_b;
      int * v158_b = (v140_p->b)->cache_vals;
      int * v159_b = (v140_p->b)->cache_vals;
      int v160_b = v159_b[0];
      v158_b[1] = v160_b;
      int * v162_b = (v140_p->b)->cache_keys;
      int v217_b = (int)((unsigned int)(v144_b + 16) >> 2);
      v162_b[0] = v217_b;
      int * v164_b = (v140_p->b)->cache_vals;
      v164_b[0] = v153_b;
      int v166_b = (v140_p->b)->timer;
      int v220_b = v166_b + 1;
      (v140_p->b)->timer = v220_b;
      v192_b = v153_b;
    } else {
      int * v169_b = (v140_p->b)->mem;
      int v222_b = (int)((unsigned int)(v144_b + 16) >> 2);
      int v170_b = v169_b[v222_b];
      int * v171_b = (v140_p->b)->mem;
      int * v172_b = (v140_p->b)->cache_keys;
      int v173_b = v172_b[1];
      int * v174_b = (v140_p->b)->cache_vals;
      int v175_b = v174_b[1];
      v171_b[v173_b] = v175_b;
      int * v177_b = (v140_p->b)->cache_keys;
      int * v178_b = (v140_p->b)->cache_keys;
      int v179_b = v178_b[0];
      v177_b[1] = v179_b;
      int * v181_b = (v140_p->b)->cache_vals;
      int * v182_b = (v140_p->b)->cache_vals;
      int v183_b = v182_b[0];
      v181_b[1] = v183_b;
      int * v185_b = (v140_p->b)->cache_keys;
      v185_b[0] = v222_b;
      int * v187_b = (v140_p->b)->cache_vals;
      v187_b[0] = v170_b;
      int v189_b = (v140_p->b)->timer;
      int v237_b = v189_b + 100;
      (v140_p->b)->timer = v237_b;
      v192_b = v170_b;
    }
    v194_b = v192_b;
  }
  int * v195_a = (v140_p->a)->regs;
  int * v195_b = (v140_p->b)->regs;
  v195_a[12] = v194_a;
  v195_b[12] = v194_b;
  return v140_p;
}

struct StateT2 * slot_0(struct StateT2 * v2_p) {
  lockstep_assert(((v2_p->a)->timer) == ((v2_p->b)->timer));
  lockstep_assume(((v2_p->a)->timer) == ((v2_p->b)->timer));
  int v3_a = (v2_p->a)->timer;
  int v3_b = (v2_p->b)->timer;
  int v12_a = v3_a + 1;
  int v12_b = v3_b + 1;
  (v2_p->a)->timer = v12_a;
  (v2_p->b)->timer = v12_b;
  int * v5_a = (v2_p->a)->regs;
  int * v5_b = (v2_p->b)->regs;
  int v6_a = v5_a[10];
  int v6_b = v5_b[10];
  bool v15_a = v6_a == 0;
  bool v15_b = v6_b == 0;
  lockstep_assert(v15_a == v15_b);
  lockstep_assume(v15_a == v15_b);
  struct StateT2 * v10_p;
  if (v15_a) {
    v10_p = v2_p;
  } else {
    struct StateT2 * v8_p = slot_1(v2_p);
    v10_p = v8_p;
  }
  return v10_p;
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
  for (int i=0; i<CACHE_LRU_SIZE; i++) {
    s->cache_keys[i] = -1;
    s->cache_vals[i] = -1;
  }
}

void lockstep_assert(bool c) { koika_assert(c, "lockstep drift"); }
void lockstep_assume(bool c) { koika_assume(c); }

int main(int argc, char* argv[]) {
  struct StateT s1, s2;
  init(&s1);
  init(&s2);
  
  int x = bounded(0, 80);
  s1.regs[10] = x;
  s2.regs[10] = x;
  
  // initialize secret
  for (int i=0; i<SECRET_SIZE; i++) {
    s1.mem[SECRET_OFFSET+i] = bounded(0, 20);
    s2.mem[SECRET_OFFSET+i] = bounded(0, 20);
  }
  struct StateT2 p = { .a = &s1, .b = &s2 };
  struct StateT2 *p_ = snippet(&p);
  koika_assert(p_->a->timer==p_->b->timer, "timing leak");
  return 0;
}