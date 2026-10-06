// verify: leak (Eva should report untainted_timer: unknown) [unroll 65]
#define NUM_REGS 32
#define MEM_SIZE 64
#define SECRET_SIZE 10
#define SECRET_OFFSET 20
#define CACHE_ENTRIES 12
#define CACHE_WORDS 24

#ifdef EVA
#include "__fc_builtin.h"
/*@ assigns *p \from \nothing;
    taints *p; */
void koika_mark(int *p);
#define koika_assert(b, s) ((void)0)
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

#include <stdbool.h>

struct StateT2 {
  struct StateT * a;
  struct StateT * b;
};

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

void lockstep_assert(bool);
void lockstep_assume(bool);

struct StateT2 * slot_12(struct StateT2 * v215_p);
struct StateT2 * slot_14(struct StateT2 * v50_p);
struct StateT2 * slot_6(struct StateT2 * v95_p);
struct StateT2 * slot_5(struct StateT2 * v82_p);
struct StateT2 * slot_2(struct StateT2 * v30_p);
struct StateT2 * slot_7(struct StateT2 * v109_p);
struct StateT2 * slot_3(struct StateT2 * v55_p);
struct StateT2 * snippet(struct StateT2 * v0_p);
struct StateT2 * slot_10(struct StateT2 * v182_p);
struct StateT2 * slot_1(struct StateT2 * v17_p);
struct StateT2 * slot_8(struct StateT2 * v128_p);
struct StateT2 * slot_4(struct StateT2 * v68_p);
struct StateT2 * slot_13(struct StateT2 * v229_p);
struct StateT2 * slot_15(struct StateT2 * v169_p);
struct StateT2 * slot_9(struct StateT2 * v147_p);
struct StateT2 * slot_11(struct StateT2 * v201_p);
struct StateT2 * slot_0(struct StateT2 * v2_p);
struct StateT2 * slot_12(struct StateT2 * v215_p) {
  lockstep_assert(((v215_p->a)->timer) == ((v215_p->b)->timer));
  lockstep_assume(((v215_p->a)->timer) == ((v215_p->b)->timer));
  int v216_a = (v215_p->a)->timer;
  int v216_b = (v215_p->b)->timer;
  int v223_a = v216_a + 1;
  int v223_b = v216_b + 1;
  (v215_p->a)->timer = v223_a;
  (v215_p->b)->timer = v223_b;
  int * v218_a = (v215_p->a)->regs;
  int * v218_b = (v215_p->b)->regs;
  int v219_a = v218_a[13];
  int v219_b = v218_b[13];
  int v226_a = v219_a + 4;
  int v226_b = v219_b + 4;
  v218_a[13] = v226_a;
  v218_b[13] = v226_b;
  struct StateT2 * v221_p = slot_13(v215_p);
  return v221_p;
}

struct StateT2 * slot_14(struct StateT2 * v50_p) {
  lockstep_assert(((v50_p->a)->timer) == ((v50_p->b)->timer));
  lockstep_assume(((v50_p->a)->timer) == ((v50_p->b)->timer));
  int v51_a = (v50_p->a)->timer;
  int v51_b = (v50_p->b)->timer;
  int v54_a = v51_a + 1;
  int v54_b = v51_b + 1;
  (v50_p->a)->timer = v54_a;
  (v50_p->b)->timer = v54_b;
  return v50_p;
}

struct StateT2 * slot_6(struct StateT2 * v95_p) {
  lockstep_assert(((v95_p->a)->timer) == ((v95_p->b)->timer));
  lockstep_assume(((v95_p->a)->timer) == ((v95_p->b)->timer));
  int v96_a = (v95_p->a)->timer;
  int v96_b = (v95_p->b)->timer;
  int v103_a = v96_a + 1;
  int v103_b = v96_b + 1;
  (v95_p->a)->timer = v103_a;
  (v95_p->b)->timer = v103_b;
  int * v98_a = (v95_p->a)->regs;
  int * v98_b = (v95_p->b)->regs;
  int v99_a = v98_a[13];
  int v99_b = v98_b[13];
  v98_a[13] = v99_a;
  v98_b[13] = v99_b;
  struct StateT2 * v101_p = slot_7(v95_p);
  return v101_p;
}

struct StateT2 * slot_5(struct StateT2 * v82_p) {
  lockstep_assert(((v82_p->a)->timer) == ((v82_p->b)->timer));
  lockstep_assume(((v82_p->a)->timer) == ((v82_p->b)->timer));
  int v83_a = (v82_p->a)->timer;
  int v83_b = (v82_p->b)->timer;
  int v89_a = v83_a + 1;
  int v89_b = v83_b + 1;
  (v82_p->a)->timer = v89_a;
  (v82_p->b)->timer = v89_b;
  int * v85_a = (v82_p->a)->regs;
  int * v85_b = (v82_p->b)->regs;
  v85_a[13] = 0;
  v85_b[13] = 0;
  struct StateT2 * v87_p = slot_6(v82_p);
  return v87_p;
}

struct StateT2 * slot_2(struct StateT2 * v30_p) {
  lockstep_assert(((v30_p->a)->timer) == ((v30_p->b)->timer));
  lockstep_assume(((v30_p->a)->timer) == ((v30_p->b)->timer));
  int v31_a = (v30_p->a)->timer;
  int v31_b = (v30_p->b)->timer;
  int v41_a = v31_a + 1;
  int v41_b = v31_b + 1;
  (v30_p->a)->timer = v41_a;
  (v30_p->b)->timer = v41_b;
  int * v33_a = (v30_p->a)->regs;
  int * v33_b = (v30_p->b)->regs;
  int v34_a = v33_a[11];
  int v34_b = v33_b[11];
  bool v44_a = 0 >= v34_a;
  bool v44_b = 0 >= v34_b;
  lockstep_assert(v44_a == v44_b);
  lockstep_assume(v44_a == v44_b);
  struct StateT2 * v39_p;
  if (v44_a) {
    struct StateT2 * v35_p = slot_14(v30_p);
    v39_p = v35_p;
  } else {
    struct StateT2 * v37_p = slot_3(v30_p);
    v39_p = v37_p;
  }
  return v39_p;
}

struct StateT2 * slot_7(struct StateT2 * v109_p) {
  lockstep_assert(((v109_p->a)->timer) == ((v109_p->b)->timer));
  lockstep_assume(((v109_p->a)->timer) == ((v109_p->b)->timer));
  int v110_a = (v109_p->a)->timer;
  int v110_b = (v109_p->b)->timer;
  int v119_a = v110_a + 1;
  int v119_b = v110_b + 1;
  (v109_p->a)->timer = v119_a;
  (v109_p->b)->timer = v119_b;
  int * v112_a = (v109_p->a)->regs;
  int * v112_b = (v109_p->b)->regs;
  int v113_a = v112_a[12];
  int v113_b = v112_b[12];
  int * v114_a = (v109_p->a)->mem;
  int * v114_b = (v109_p->b)->mem;
  int v123_a = (int)((unsigned int)v113_a >> 2);
  int v123_b = (int)((unsigned int)v113_b >> 2);
  int v115_a = v114_a[v123_a];
  int v115_b = v114_b[v123_b];
  v112_a[14] = v115_a;
  v112_b[14] = v115_b;
  struct StateT2 * v117_p = slot_8(v109_p);
  return v117_p;
}

struct StateT2 * slot_3(struct StateT2 * v55_p) {
  lockstep_assert(((v55_p->a)->timer) == ((v55_p->b)->timer));
  lockstep_assume(((v55_p->a)->timer) == ((v55_p->b)->timer));
  int v56_a = (v55_p->a)->timer;
  int v56_b = (v55_p->b)->timer;
  int v62_a = v56_a + 1;
  int v62_b = v56_b + 1;
  (v55_p->a)->timer = v62_a;
  (v55_p->b)->timer = v62_b;
  int * v58_a = (v55_p->a)->regs;
  int * v58_b = (v55_p->b)->regs;
  v58_a[12] = 0;
  v58_b[12] = 0;
  struct StateT2 * v60_p = slot_4(v55_p);
  return v60_p;
}

struct StateT2 * snippet(struct StateT2 * v0_p) {
  lockstep_assert(((v0_p->a)->timer) == ((v0_p->b)->timer));
  lockstep_assume(((v0_p->a)->timer) == ((v0_p->b)->timer));
  struct StateT2 * v1_p = slot_0(v0_p);
  return v1_p;
}

struct StateT2 * slot_10(struct StateT2 * v182_p) {
  lockstep_assert(((v182_p->a)->timer) == ((v182_p->b)->timer));
  lockstep_assume(((v182_p->a)->timer) == ((v182_p->b)->timer));
  int v183_a = (v182_p->a)->timer;
  int v183_b = (v182_p->b)->timer;
  int v190_a = v183_a + 1;
  int v190_b = v183_b + 1;
  (v182_p->a)->timer = v190_a;
  (v182_p->b)->timer = v190_b;
  int * v185_a = (v182_p->a)->regs;
  int * v185_b = (v182_p->b)->regs;
  int v186_a = v185_a[11];
  int v186_b = v185_b[11];
  int v193_a = v186_a + -1;
  int v193_b = v186_b + -1;
  v185_a[11] = v193_a;
  v185_b[11] = v193_b;
  struct StateT2 * v188_p = slot_11(v182_p);
  return v188_p;
}

struct StateT2 * slot_1(struct StateT2 * v17_p) {
  lockstep_assert(((v17_p->a)->timer) == ((v17_p->b)->timer));
  lockstep_assume(((v17_p->a)->timer) == ((v17_p->b)->timer));
  int v18_a = (v17_p->a)->timer;
  int v18_b = (v17_p->b)->timer;
  int v24_a = v18_a + 1;
  int v24_b = v18_b + 1;
  (v17_p->a)->timer = v24_a;
  (v17_p->b)->timer = v24_b;
  int * v20_a = (v17_p->a)->regs;
  int * v20_b = (v17_p->b)->regs;
  v20_a[10] = 1;
  v20_b[10] = 1;
  struct StateT2 * v22_p = slot_2(v17_p);
  return v22_p;
}

struct StateT2 * slot_8(struct StateT2 * v128_p) {
  lockstep_assert(((v128_p->a)->timer) == ((v128_p->b)->timer));
  lockstep_assume(((v128_p->a)->timer) == ((v128_p->b)->timer));
  int v129_a = (v128_p->a)->timer;
  int v129_b = (v128_p->b)->timer;
  int v138_a = v129_a + 1;
  int v138_b = v129_b + 1;
  (v128_p->a)->timer = v138_a;
  (v128_p->b)->timer = v138_b;
  int * v131_a = (v128_p->a)->regs;
  int * v131_b = (v128_p->b)->regs;
  int v132_a = v131_a[13];
  int v132_b = v131_b[13];
  int * v133_a = (v128_p->a)->mem;
  int * v133_b = (v128_p->b)->mem;
  int v142_a = (int)((unsigned int)v132_a >> 2);
  int v142_b = (int)((unsigned int)v132_b >> 2);
  int v134_a = v133_a[v142_a];
  int v134_b = v133_b[v142_b];
  v131_a[15] = v134_a;
  v131_b[15] = v134_b;
  struct StateT2 * v136_p = slot_9(v128_p);
  return v136_p;
}

struct StateT2 * slot_4(struct StateT2 * v68_p) {
  lockstep_assert(((v68_p->a)->timer) == ((v68_p->b)->timer));
  lockstep_assume(((v68_p->a)->timer) == ((v68_p->b)->timer));
  int v69_a = (v68_p->a)->timer;
  int v69_b = (v68_p->b)->timer;
  int v76_a = v69_a + 1;
  int v76_b = v69_b + 1;
  (v68_p->a)->timer = v76_a;
  (v68_p->b)->timer = v76_b;
  int * v71_a = (v68_p->a)->regs;
  int * v71_b = (v68_p->b)->regs;
  int v72_a = v71_a[12];
  int v72_b = v71_b[12];
  int v79_a = v72_a + 16;
  int v79_b = v72_b + 16;
  v71_a[12] = v79_a;
  v71_b[12] = v79_b;
  struct StateT2 * v74_p = slot_5(v68_p);
  return v74_p;
}

struct StateT2 * slot_13(struct StateT2 * v229_p) {
  lockstep_assert(((v229_p->a)->timer) == ((v229_p->b)->timer));
  lockstep_assume(((v229_p->a)->timer) == ((v229_p->b)->timer));
  int v230_a = (v229_p->a)->timer;
  int v230_b = (v229_p->b)->timer;
  int v240_a = v230_a + 1;
  int v240_b = v230_b + 1;
  (v229_p->a)->timer = v240_a;
  (v229_p->b)->timer = v240_b;
  int * v232_a = (v229_p->a)->regs;
  int * v232_b = (v229_p->b)->regs;
  int v233_a = v232_a[11];
  int v233_b = v232_b[11];
  bool v243_a = !(v233_a == 0);
  bool v243_b = !(v233_b == 0);
  lockstep_assert(v243_a == v243_b);
  lockstep_assume(v243_a == v243_b);
  struct StateT2 * v238_p;
  if (v243_a) {
    struct StateT2 * v234_p = slot_7(v229_p);
    v238_p = v234_p;
  } else {
    struct StateT2 * v236_p = slot_14(v229_p);
    v238_p = v236_p;
  }
  return v238_p;
}

struct StateT2 * slot_15(struct StateT2 * v169_p) {
  lockstep_assert(((v169_p->a)->timer) == ((v169_p->b)->timer));
  lockstep_assume(((v169_p->a)->timer) == ((v169_p->b)->timer));
  int v170_a = (v169_p->a)->timer;
  int v170_b = (v169_p->b)->timer;
  int v176_a = v170_a + 1;
  int v176_b = v170_b + 1;
  (v169_p->a)->timer = v176_a;
  (v169_p->b)->timer = v176_b;
  int * v172_a = (v169_p->a)->regs;
  int * v172_b = (v169_p->b)->regs;
  v172_a[10] = 0;
  v172_b[10] = 0;
  struct StateT2 * v174_p = slot_14(v169_p);
  return v174_p;
}

struct StateT2 * slot_9(struct StateT2 * v147_p) {
  lockstep_assert(((v147_p->a)->timer) == ((v147_p->b)->timer));
  lockstep_assume(((v147_p->a)->timer) == ((v147_p->b)->timer));
  int v148_a = (v147_p->a)->timer;
  int v148_b = (v147_p->b)->timer;
  int v159_a = v148_a + 1;
  int v159_b = v148_b + 1;
  (v147_p->a)->timer = v159_a;
  (v147_p->b)->timer = v159_b;
  int * v150_a = (v147_p->a)->regs;
  int * v150_b = (v147_p->b)->regs;
  int v151_a = v150_a[14];
  int v151_b = v150_b[14];
  int v152_a = v150_a[15];
  int v152_b = v150_b[15];
  bool v163_a = !(v151_a == v152_a);
  bool v163_b = !(v151_b == v152_b);
  lockstep_assert(v163_a == v163_b);
  lockstep_assume(v163_a == v163_b);
  struct StateT2 * v157_p;
  if (v163_a) {
    struct StateT2 * v153_p = slot_15(v147_p);
    v157_p = v153_p;
  } else {
    struct StateT2 * v155_p = slot_10(v147_p);
    v157_p = v155_p;
  }
  return v157_p;
}

struct StateT2 * slot_11(struct StateT2 * v201_p) {
  lockstep_assert(((v201_p->a)->timer) == ((v201_p->b)->timer));
  lockstep_assume(((v201_p->a)->timer) == ((v201_p->b)->timer));
  int v202_a = (v201_p->a)->timer;
  int v202_b = (v201_p->b)->timer;
  int v209_a = v202_a + 1;
  int v209_b = v202_b + 1;
  (v201_p->a)->timer = v209_a;
  (v201_p->b)->timer = v209_b;
  int * v204_a = (v201_p->a)->regs;
  int * v204_b = (v201_p->b)->regs;
  int v205_a = v204_a[12];
  int v205_b = v204_b[12];
  int v212_a = v205_a + 4;
  int v212_b = v205_b + 4;
  v204_a[12] = v212_a;
  v204_b[12] = v212_b;
  struct StateT2 * v207_p = slot_12(v201_p);
  return v207_p;
}

struct StateT2 * slot_0(struct StateT2 * v2_p) {
  lockstep_assert(((v2_p->a)->timer) == ((v2_p->b)->timer));
  lockstep_assume(((v2_p->a)->timer) == ((v2_p->b)->timer));
  int v3_a = (v2_p->a)->timer;
  int v3_b = (v2_p->b)->timer;
  int v10_a = v3_a + 1;
  int v10_b = v3_b + 1;
  (v2_p->a)->timer = v10_a;
  (v2_p->b)->timer = v10_b;
  int * v5_a = (v2_p->a)->regs;
  int * v5_b = (v2_p->b)->regs;
  int v6_a = v5_a[10];
  int v6_b = v5_b[10];
  v5_a[11] = v6_a;
  v5_b[11] = v6_b;
  struct StateT2 * v8_p = slot_1(v2_p);
  return v8_p;
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

void lockstep_assert(bool c) { koika_assert(c, "lockstep drift"); }
void lockstep_assume(bool c) { koika_assume(c); }

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
  struct StateT2 p = { .a = &s1, .b = &s2 };
  struct StateT2 *p_ = snippet(&p);
  //@ assert untainted_timer: !\tainted(p_->a->timer==p_->b->timer);
  koika_assert(p_->a->timer==p_->b->timer, "timing leak");
  return 0;
}