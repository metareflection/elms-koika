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

struct StateT2 * snippet(struct StateT2 * v0_p);
struct StateT2 * slot_1(struct StateT2 * v19_p);
struct StateT2 * slot_2(struct StateT2 * v269_p);
struct StateT2 * slot_3(struct StateT2 * v285_p);
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
  int v153_a = v20_a + 1;
  int v153_b = v20_b + 1;
  (v19_p->a)->timer = v153_a;
  (v19_p->b)->timer = v153_b;
  int * v22_a = (v19_p->a)->regs;
  int * v22_b = (v19_p->b)->regs;
  int v23_a = v22_a[10];
  int v23_b = v22_b[10];
  int * v24_a = (v19_p->a)->cache_tags;
  int * v24_b = (v19_p->b)->cache_tags;
  int v157_a = (((int)((unsigned int)((int)((unsigned int)v23_a >> 2)) >> 1)) & 1) * 2;
  int v157_b = (((int)((unsigned int)((int)((unsigned int)v23_b >> 2)) >> 1)) & 1) * 2;
  int v25_a = v24_a[v157_a];
  int v25_b = v24_b[v157_b];
  int * v26_a = (v19_p->a)->cache_tags;
  int * v26_b = (v19_p->b)->cache_tags;
  int v159_a = ((((int)((unsigned int)((int)((unsigned int)v23_a >> 2)) >> 1)) & 1) * 2) + 1;
  int v159_b = ((((int)((unsigned int)((int)((unsigned int)v23_b >> 2)) >> 1)) & 1) * 2) + 1;
  int v27_a = v26_a[v159_a];
  int v27_b = v26_b[v159_b];
  int * v28_a = (v19_p->a)->cache_tags;
  int * v28_b = (v19_p->b)->cache_tags;
  int v161_a = 4 + ((((int)((unsigned int)((int)((unsigned int)v23_a >> 2)) >> 1)) & 3) * 2);
  int v161_b = 4 + ((((int)((unsigned int)((int)((unsigned int)v23_b >> 2)) >> 1)) & 3) * 2);
  int v29_a = v28_a[v161_a];
  int v29_b = v28_b[v161_b];
  int * v30_a = (v19_p->a)->cache_tags;
  int * v30_b = (v19_p->b)->cache_tags;
  int v163_a = (4 + ((((int)((unsigned int)((int)((unsigned int)v23_a >> 2)) >> 1)) & 3) * 2)) + 1;
  int v163_b = (4 + ((((int)((unsigned int)((int)((unsigned int)v23_b >> 2)) >> 1)) & 3) * 2)) + 1;
  int v31_a = v30_a[v163_a];
  int v31_b = v30_b[v163_b];
  int v32_a = (v19_p->a)->timer;
  int v32_b = (v19_p->b)->timer;
  int v164_a = v32_a + ((100 ^ (((~(((v29_a ^ ((int)((unsigned int)((int)((unsigned int)v23_a >> 2)) >> 1))) | (-(v29_a ^ ((int)((unsigned int)((int)((unsigned int)v23_a >> 2)) >> 1))))) >> 31)) | (~(((v31_a ^ ((int)((unsigned int)((int)((unsigned int)v23_a >> 2)) >> 1))) | (-(v31_a ^ ((int)((unsigned int)((int)((unsigned int)v23_a >> 2)) >> 1))))) >> 31))) & 104)) ^ (((~(((v25_a ^ ((int)((unsigned int)((int)((unsigned int)v23_a >> 2)) >> 1))) | (-(v25_a ^ ((int)((unsigned int)((int)((unsigned int)v23_a >> 2)) >> 1))))) >> 31)) | (~(((v27_a ^ ((int)((unsigned int)((int)((unsigned int)v23_a >> 2)) >> 1))) | (-(v27_a ^ ((int)((unsigned int)((int)((unsigned int)v23_a >> 2)) >> 1))))) >> 31))) & (1 ^ (100 ^ (((~(((v29_a ^ ((int)((unsigned int)((int)((unsigned int)v23_a >> 2)) >> 1))) | (-(v29_a ^ ((int)((unsigned int)((int)((unsigned int)v23_a >> 2)) >> 1))))) >> 31)) | (~(((v31_a ^ ((int)((unsigned int)((int)((unsigned int)v23_a >> 2)) >> 1))) | (-(v31_a ^ ((int)((unsigned int)((int)((unsigned int)v23_a >> 2)) >> 1))))) >> 31))) & 104)))));
  int v164_b = v32_b + ((100 ^ (((~(((v29_b ^ ((int)((unsigned int)((int)((unsigned int)v23_b >> 2)) >> 1))) | (-(v29_b ^ ((int)((unsigned int)((int)((unsigned int)v23_b >> 2)) >> 1))))) >> 31)) | (~(((v31_b ^ ((int)((unsigned int)((int)((unsigned int)v23_b >> 2)) >> 1))) | (-(v31_b ^ ((int)((unsigned int)((int)((unsigned int)v23_b >> 2)) >> 1))))) >> 31))) & 104)) ^ (((~(((v25_b ^ ((int)((unsigned int)((int)((unsigned int)v23_b >> 2)) >> 1))) | (-(v25_b ^ ((int)((unsigned int)((int)((unsigned int)v23_b >> 2)) >> 1))))) >> 31)) | (~(((v27_b ^ ((int)((unsigned int)((int)((unsigned int)v23_b >> 2)) >> 1))) | (-(v27_b ^ ((int)((unsigned int)((int)((unsigned int)v23_b >> 2)) >> 1))))) >> 31))) & (1 ^ (100 ^ (((~(((v29_b ^ ((int)((unsigned int)((int)((unsigned int)v23_b >> 2)) >> 1))) | (-(v29_b ^ ((int)((unsigned int)((int)((unsigned int)v23_b >> 2)) >> 1))))) >> 31)) | (~(((v31_b ^ ((int)((unsigned int)((int)((unsigned int)v23_b >> 2)) >> 1))) | (-(v31_b ^ ((int)((unsigned int)((int)((unsigned int)v23_b >> 2)) >> 1))))) >> 31))) & 104)))));
  (v19_p->a)->timer = v164_a;
  (v19_p->b)->timer = v164_b;
  int * v34_a = (v19_p->a)->cache_vals;
  int * v34_b = (v19_p->b)->cache_vals;
  bool v165_a = !(((~(((v25_a ^ ((int)((unsigned int)((int)((unsigned int)v23_a >> 2)) >> 1))) | (-(v25_a ^ ((int)((unsigned int)((int)((unsigned int)v23_a >> 2)) >> 1))))) >> 31)) | (~(((v27_a ^ ((int)((unsigned int)((int)((unsigned int)v23_a >> 2)) >> 1))) | (-(v27_a ^ ((int)((unsigned int)((int)((unsigned int)v23_a >> 2)) >> 1))))) >> 31))) == 0);
  bool v165_b = !(((~(((v25_b ^ ((int)((unsigned int)((int)((unsigned int)v23_b >> 2)) >> 1))) | (-(v25_b ^ ((int)((unsigned int)((int)((unsigned int)v23_b >> 2)) >> 1))))) >> 31)) | (~(((v27_b ^ ((int)((unsigned int)((int)((unsigned int)v23_b >> 2)) >> 1))) | (-(v27_b ^ ((int)((unsigned int)((int)((unsigned int)v23_b >> 2)) >> 1))))) >> 31))) == 0);
  int v147_a;
  if (v165_a) {
    int * v35_a = (v19_p->a)->cache_age;
    int v167_a = ((((int)((unsigned int)((int)((unsigned int)v23_a >> 2)) >> 1)) & 1) * 2) + ((~(((v27_a ^ ((int)((unsigned int)((int)((unsigned int)v23_a >> 2)) >> 1))) | (-(v27_a ^ ((int)((unsigned int)((int)((unsigned int)v23_a >> 2)) >> 1))))) >> 31)) & 1);
    int v36_a = v35_a[v167_a];
    int * v37_a = (v19_p->a)->cache_age;
    int v38_a = v37_a[v157_a];
    int * v39_a = (v19_p->a)->cache_age;
    int v170_a = v38_a + ((int)((unsigned int)(v38_a - v36_a) >> 31));
    v39_a[v157_a] = v170_a;
    int * v41_a = (v19_p->a)->cache_age;
    int v42_a = v41_a[v159_a];
    int * v43_a = (v19_p->a)->cache_age;
    int v173_a = v42_a + ((int)((unsigned int)(v42_a - v36_a) >> 31));
    v43_a[v159_a] = v173_a;
    int * v45_a = (v19_p->a)->cache_age;
    v45_a[v167_a] = 0;
    v147_a = v167_a;
  } else {
    int * v48_a = (v19_p->a)->cache_age;
    int v177_a = (((int)((unsigned int)((int)((unsigned int)v23_a >> 2)) >> 1)) & 1) * 2;
    int v49_a = v48_a[v177_a];
    int * v50_a = (v19_p->a)->cache_tags;
    int v51_a = v50_a[v177_a];
    int * v52_a = (v19_p->a)->cache_age;
    int v53_a = v52_a[v159_a];
    int * v54_a = (v19_p->a)->cache_tags;
    int v55_a = v54_a[v159_a];
    bool v181_a = !(((~(((v29_a ^ ((int)((unsigned int)((int)((unsigned int)v23_a >> 2)) >> 1))) | (-(v29_a ^ ((int)((unsigned int)((int)((unsigned int)v23_a >> 2)) >> 1))))) >> 31)) | (~(((v31_a ^ ((int)((unsigned int)((int)((unsigned int)v23_a >> 2)) >> 1))) | (-(v31_a ^ ((int)((unsigned int)((int)((unsigned int)v23_a >> 2)) >> 1))))) >> 31))) == 0);
    int v119_a;
    if (v181_a) {
      int * v56_a = (v19_p->a)->cache_age;
      int v183_a = (4 + ((((int)((unsigned int)((int)((unsigned int)v23_a >> 2)) >> 1)) & 3) * 2)) + ((~(((v31_a ^ ((int)((unsigned int)((int)((unsigned int)v23_a >> 2)) >> 1))) | (-(v31_a ^ ((int)((unsigned int)((int)((unsigned int)v23_a >> 2)) >> 1))))) >> 31)) & 1);
      int v57_a = v56_a[v183_a];
      int * v58_a = (v19_p->a)->cache_age;
      int v59_a = v58_a[v161_a];
      int * v60_a = (v19_p->a)->cache_age;
      int v186_a = v59_a + ((int)((unsigned int)(v59_a - v57_a) >> 31));
      v60_a[v161_a] = v186_a;
      int * v62_a = (v19_p->a)->cache_age;
      int v63_a = v62_a[v163_a];
      int * v64_a = (v19_p->a)->cache_age;
      int v189_a = v63_a + ((int)((unsigned int)(v63_a - v57_a) >> 31));
      v64_a[v163_a] = v189_a;
      int * v66_a = (v19_p->a)->cache_age;
      v66_a[v183_a] = 0;
      v119_a = v183_a;
    } else {
      int * v69_a = (v19_p->a)->cache_age;
      int v193_a = 4 + ((((int)((unsigned int)((int)((unsigned int)v23_a >> 2)) >> 1)) & 3) * 2);
      int v70_a = v69_a[v193_a];
      int * v71_a = (v19_p->a)->cache_tags;
      int v72_a = v71_a[v193_a];
      int * v73_a = (v19_p->a)->cache_age;
      int v74_a = v73_a[v163_a];
      int * v75_a = (v19_p->a)->cache_tags;
      int v76_a = v75_a[v163_a];
      int * v77_a = (v19_p->a)->cache_dirty;
      int v198_a = (4 + ((((int)((unsigned int)((int)((unsigned int)v23_a >> 2)) >> 1)) & 3) * 2)) + ((((v70_a + ((~(((v72_a ^ -1) | (-(v72_a ^ -1))) >> 31)) & 2)) - (v74_a + ((~(((v76_a ^ -1) | (-(v76_a ^ -1))) >> 31)) & 2))) >> 31) & 1);
      int v78_a = v77_a[v198_a];
      bool v199_a = !(v78_a == 0);
      if (v199_a) {
        int * v79_a = (v19_p->a)->cache_tags;
        int v80_a = v79_a[v198_a];
        int * v81_a = (v19_p->a)->cache_vals;
        int v202_a = ((4 + ((((int)((unsigned int)((int)((unsigned int)v23_a >> 2)) >> 1)) & 3) * 2)) + ((((v70_a + ((~(((v72_a ^ -1) | (-(v72_a ^ -1))) >> 31)) & 2)) - (v74_a + ((~(((v76_a ^ -1) | (-(v76_a ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
        int v82_a = v81_a[v202_a];
        int * v83_a = (v19_p->a)->cache_vals;
        int v204_a = (((4 + ((((int)((unsigned int)((int)((unsigned int)v23_a >> 2)) >> 1)) & 3) * 2)) + ((((v70_a + ((~(((v72_a ^ -1) | (-(v72_a ^ -1))) >> 31)) & 2)) - (v74_a + ((~(((v76_a ^ -1) | (-(v76_a ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
        int v84_a = v83_a[v204_a];
        int * v85_a = (v19_p->a)->mem;
        int v206_a = v80_a * 2;
        v85_a[v206_a] = v82_a;
        int * v87_a = (v19_p->a)->mem;
        int v209_a = (v80_a * 2) + 1;
        v87_a[v209_a] = v84_a;
        ;
      } else {
        ;
      }
      int * v92_a = (v19_p->a)->mem;
      int v214_a = ((int)((unsigned int)((int)((unsigned int)v23_a >> 2)) >> 1)) * 2;
      int v93_a = v92_a[v214_a];
      int * v94_a = (v19_p->a)->mem;
      int v216_a = (((int)((unsigned int)((int)((unsigned int)v23_a >> 2)) >> 1)) * 2) + 1;
      int v95_a = v94_a[v216_a];
      int * v96_a = (v19_p->a)->cache_vals;
      int v218_a = ((4 + ((((int)((unsigned int)((int)((unsigned int)v23_a >> 2)) >> 1)) & 3) * 2)) + ((((v70_a + ((~(((v72_a ^ -1) | (-(v72_a ^ -1))) >> 31)) & 2)) - (v74_a + ((~(((v76_a ^ -1) | (-(v76_a ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
      v96_a[v218_a] = v93_a;
      int * v98_a = (v19_p->a)->cache_vals;
      int v221_a = (((4 + ((((int)((unsigned int)((int)((unsigned int)v23_a >> 2)) >> 1)) & 3) * 2)) + ((((v70_a + ((~(((v72_a ^ -1) | (-(v72_a ^ -1))) >> 31)) & 2)) - (v74_a + ((~(((v76_a ^ -1) | (-(v76_a ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
      v98_a[v221_a] = v95_a;
      int * v100_a = (v19_p->a)->cache_tags;
      int v224_a = (int)((unsigned int)((int)((unsigned int)v23_a >> 2)) >> 1);
      v100_a[v198_a] = v224_a;
      int * v102_a = (v19_p->a)->cache_dirty;
      v102_a[v198_a] = 0;
      int * v104_a = (v19_p->a)->cache_age;
      v104_a[v198_a] = 1;
      int * v106_a = (v19_p->a)->cache_age;
      int v107_a = v106_a[v198_a];
      int * v108_a = (v19_p->a)->cache_age;
      int v109_a = v108_a[v161_a];
      int * v110_a = (v19_p->a)->cache_age;
      int v232_a = v109_a + ((int)((unsigned int)(v109_a - v107_a) >> 31));
      v110_a[v161_a] = v232_a;
      int * v112_a = (v19_p->a)->cache_age;
      int v113_a = v112_a[v163_a];
      int * v114_a = (v19_p->a)->cache_age;
      int v235_a = v113_a + ((int)((unsigned int)(v113_a - v107_a) >> 31));
      v114_a[v163_a] = v235_a;
      int * v116_a = (v19_p->a)->cache_age;
      v116_a[v198_a] = 0;
      v119_a = v198_a;
    }
    int * v120_a = (v19_p->a)->cache_vals;
    int v238_a = v119_a * 2;
    int v121_a = v120_a[v238_a];
    int * v122_a = (v19_p->a)->cache_vals;
    int v240_a = (v119_a * 2) + 1;
    int v123_a = v122_a[v240_a];
    int * v124_a = (v19_p->a)->cache_vals;
    int v242_a = (((((int)((unsigned int)((int)((unsigned int)v23_a >> 2)) >> 1)) & 1) * 2) + ((((v49_a + ((~(((v51_a ^ -1) | (-(v51_a ^ -1))) >> 31)) & 2)) - (v53_a + ((~(((v55_a ^ -1) | (-(v55_a ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
    v124_a[v242_a] = v121_a;
    int * v126_a = (v19_p->a)->cache_vals;
    int v245_a = ((((((int)((unsigned int)((int)((unsigned int)v23_a >> 2)) >> 1)) & 1) * 2) + ((((v49_a + ((~(((v51_a ^ -1) | (-(v51_a ^ -1))) >> 31)) & 2)) - (v53_a + ((~(((v55_a ^ -1) | (-(v55_a ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
    v126_a[v245_a] = v123_a;
    int * v128_a = (v19_p->a)->cache_tags;
    int v248_a = ((((int)((unsigned int)((int)((unsigned int)v23_a >> 2)) >> 1)) & 1) * 2) + ((((v49_a + ((~(((v51_a ^ -1) | (-(v51_a ^ -1))) >> 31)) & 2)) - (v53_a + ((~(((v55_a ^ -1) | (-(v55_a ^ -1))) >> 31)) & 2))) >> 31) & 1);
    int v249_a = (int)((unsigned int)((int)((unsigned int)v23_a >> 2)) >> 1);
    v128_a[v248_a] = v249_a;
    int * v130_a = (v19_p->a)->cache_dirty;
    v130_a[v248_a] = 0;
    int * v132_a = (v19_p->a)->cache_age;
    v132_a[v248_a] = 1;
    int * v134_a = (v19_p->a)->cache_age;
    int v135_a = v134_a[v248_a];
    int * v136_a = (v19_p->a)->cache_age;
    int v137_a = v136_a[v157_a];
    int * v138_a = (v19_p->a)->cache_age;
    int v257_a = v137_a + ((int)((unsigned int)(v137_a - v135_a) >> 31));
    v138_a[v157_a] = v257_a;
    int * v140_a = (v19_p->a)->cache_age;
    int v141_a = v140_a[v159_a];
    int * v142_a = (v19_p->a)->cache_age;
    int v260_a = v141_a + ((int)((unsigned int)(v141_a - v135_a) >> 31));
    v142_a[v159_a] = v260_a;
    int * v144_a = (v19_p->a)->cache_age;
    v144_a[v248_a] = 0;
    v147_a = v248_a;
  }
  int v147_b;
  if (v165_b) {
    int * v35_b = (v19_p->b)->cache_age;
    int v167_b = ((((int)((unsigned int)((int)((unsigned int)v23_b >> 2)) >> 1)) & 1) * 2) + ((~(((v27_b ^ ((int)((unsigned int)((int)((unsigned int)v23_b >> 2)) >> 1))) | (-(v27_b ^ ((int)((unsigned int)((int)((unsigned int)v23_b >> 2)) >> 1))))) >> 31)) & 1);
    int v36_b = v35_b[v167_b];
    int * v37_b = (v19_p->b)->cache_age;
    int v38_b = v37_b[v157_b];
    int * v39_b = (v19_p->b)->cache_age;
    int v170_b = v38_b + ((int)((unsigned int)(v38_b - v36_b) >> 31));
    v39_b[v157_b] = v170_b;
    int * v41_b = (v19_p->b)->cache_age;
    int v42_b = v41_b[v159_b];
    int * v43_b = (v19_p->b)->cache_age;
    int v173_b = v42_b + ((int)((unsigned int)(v42_b - v36_b) >> 31));
    v43_b[v159_b] = v173_b;
    int * v45_b = (v19_p->b)->cache_age;
    v45_b[v167_b] = 0;
    v147_b = v167_b;
  } else {
    int * v48_b = (v19_p->b)->cache_age;
    int v177_b = (((int)((unsigned int)((int)((unsigned int)v23_b >> 2)) >> 1)) & 1) * 2;
    int v49_b = v48_b[v177_b];
    int * v50_b = (v19_p->b)->cache_tags;
    int v51_b = v50_b[v177_b];
    int * v52_b = (v19_p->b)->cache_age;
    int v53_b = v52_b[v159_b];
    int * v54_b = (v19_p->b)->cache_tags;
    int v55_b = v54_b[v159_b];
    bool v181_b = !(((~(((v29_b ^ ((int)((unsigned int)((int)((unsigned int)v23_b >> 2)) >> 1))) | (-(v29_b ^ ((int)((unsigned int)((int)((unsigned int)v23_b >> 2)) >> 1))))) >> 31)) | (~(((v31_b ^ ((int)((unsigned int)((int)((unsigned int)v23_b >> 2)) >> 1))) | (-(v31_b ^ ((int)((unsigned int)((int)((unsigned int)v23_b >> 2)) >> 1))))) >> 31))) == 0);
    int v119_b;
    if (v181_b) {
      int * v56_b = (v19_p->b)->cache_age;
      int v183_b = (4 + ((((int)((unsigned int)((int)((unsigned int)v23_b >> 2)) >> 1)) & 3) * 2)) + ((~(((v31_b ^ ((int)((unsigned int)((int)((unsigned int)v23_b >> 2)) >> 1))) | (-(v31_b ^ ((int)((unsigned int)((int)((unsigned int)v23_b >> 2)) >> 1))))) >> 31)) & 1);
      int v57_b = v56_b[v183_b];
      int * v58_b = (v19_p->b)->cache_age;
      int v59_b = v58_b[v161_b];
      int * v60_b = (v19_p->b)->cache_age;
      int v186_b = v59_b + ((int)((unsigned int)(v59_b - v57_b) >> 31));
      v60_b[v161_b] = v186_b;
      int * v62_b = (v19_p->b)->cache_age;
      int v63_b = v62_b[v163_b];
      int * v64_b = (v19_p->b)->cache_age;
      int v189_b = v63_b + ((int)((unsigned int)(v63_b - v57_b) >> 31));
      v64_b[v163_b] = v189_b;
      int * v66_b = (v19_p->b)->cache_age;
      v66_b[v183_b] = 0;
      v119_b = v183_b;
    } else {
      int * v69_b = (v19_p->b)->cache_age;
      int v193_b = 4 + ((((int)((unsigned int)((int)((unsigned int)v23_b >> 2)) >> 1)) & 3) * 2);
      int v70_b = v69_b[v193_b];
      int * v71_b = (v19_p->b)->cache_tags;
      int v72_b = v71_b[v193_b];
      int * v73_b = (v19_p->b)->cache_age;
      int v74_b = v73_b[v163_b];
      int * v75_b = (v19_p->b)->cache_tags;
      int v76_b = v75_b[v163_b];
      int * v77_b = (v19_p->b)->cache_dirty;
      int v198_b = (4 + ((((int)((unsigned int)((int)((unsigned int)v23_b >> 2)) >> 1)) & 3) * 2)) + ((((v70_b + ((~(((v72_b ^ -1) | (-(v72_b ^ -1))) >> 31)) & 2)) - (v74_b + ((~(((v76_b ^ -1) | (-(v76_b ^ -1))) >> 31)) & 2))) >> 31) & 1);
      int v78_b = v77_b[v198_b];
      bool v199_b = !(v78_b == 0);
      if (v199_b) {
        int * v79_b = (v19_p->b)->cache_tags;
        int v80_b = v79_b[v198_b];
        int * v81_b = (v19_p->b)->cache_vals;
        int v202_b = ((4 + ((((int)((unsigned int)((int)((unsigned int)v23_b >> 2)) >> 1)) & 3) * 2)) + ((((v70_b + ((~(((v72_b ^ -1) | (-(v72_b ^ -1))) >> 31)) & 2)) - (v74_b + ((~(((v76_b ^ -1) | (-(v76_b ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
        int v82_b = v81_b[v202_b];
        int * v83_b = (v19_p->b)->cache_vals;
        int v204_b = (((4 + ((((int)((unsigned int)((int)((unsigned int)v23_b >> 2)) >> 1)) & 3) * 2)) + ((((v70_b + ((~(((v72_b ^ -1) | (-(v72_b ^ -1))) >> 31)) & 2)) - (v74_b + ((~(((v76_b ^ -1) | (-(v76_b ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
        int v84_b = v83_b[v204_b];
        int * v85_b = (v19_p->b)->mem;
        int v206_b = v80_b * 2;
        v85_b[v206_b] = v82_b;
        int * v87_b = (v19_p->b)->mem;
        int v209_b = (v80_b * 2) + 1;
        v87_b[v209_b] = v84_b;
        ;
      } else {
        ;
      }
      int * v92_b = (v19_p->b)->mem;
      int v214_b = ((int)((unsigned int)((int)((unsigned int)v23_b >> 2)) >> 1)) * 2;
      int v93_b = v92_b[v214_b];
      int * v94_b = (v19_p->b)->mem;
      int v216_b = (((int)((unsigned int)((int)((unsigned int)v23_b >> 2)) >> 1)) * 2) + 1;
      int v95_b = v94_b[v216_b];
      int * v96_b = (v19_p->b)->cache_vals;
      int v218_b = ((4 + ((((int)((unsigned int)((int)((unsigned int)v23_b >> 2)) >> 1)) & 3) * 2)) + ((((v70_b + ((~(((v72_b ^ -1) | (-(v72_b ^ -1))) >> 31)) & 2)) - (v74_b + ((~(((v76_b ^ -1) | (-(v76_b ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
      v96_b[v218_b] = v93_b;
      int * v98_b = (v19_p->b)->cache_vals;
      int v221_b = (((4 + ((((int)((unsigned int)((int)((unsigned int)v23_b >> 2)) >> 1)) & 3) * 2)) + ((((v70_b + ((~(((v72_b ^ -1) | (-(v72_b ^ -1))) >> 31)) & 2)) - (v74_b + ((~(((v76_b ^ -1) | (-(v76_b ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
      v98_b[v221_b] = v95_b;
      int * v100_b = (v19_p->b)->cache_tags;
      int v224_b = (int)((unsigned int)((int)((unsigned int)v23_b >> 2)) >> 1);
      v100_b[v198_b] = v224_b;
      int * v102_b = (v19_p->b)->cache_dirty;
      v102_b[v198_b] = 0;
      int * v104_b = (v19_p->b)->cache_age;
      v104_b[v198_b] = 1;
      int * v106_b = (v19_p->b)->cache_age;
      int v107_b = v106_b[v198_b];
      int * v108_b = (v19_p->b)->cache_age;
      int v109_b = v108_b[v161_b];
      int * v110_b = (v19_p->b)->cache_age;
      int v232_b = v109_b + ((int)((unsigned int)(v109_b - v107_b) >> 31));
      v110_b[v161_b] = v232_b;
      int * v112_b = (v19_p->b)->cache_age;
      int v113_b = v112_b[v163_b];
      int * v114_b = (v19_p->b)->cache_age;
      int v235_b = v113_b + ((int)((unsigned int)(v113_b - v107_b) >> 31));
      v114_b[v163_b] = v235_b;
      int * v116_b = (v19_p->b)->cache_age;
      v116_b[v198_b] = 0;
      v119_b = v198_b;
    }
    int * v120_b = (v19_p->b)->cache_vals;
    int v238_b = v119_b * 2;
    int v121_b = v120_b[v238_b];
    int * v122_b = (v19_p->b)->cache_vals;
    int v240_b = (v119_b * 2) + 1;
    int v123_b = v122_b[v240_b];
    int * v124_b = (v19_p->b)->cache_vals;
    int v242_b = (((((int)((unsigned int)((int)((unsigned int)v23_b >> 2)) >> 1)) & 1) * 2) + ((((v49_b + ((~(((v51_b ^ -1) | (-(v51_b ^ -1))) >> 31)) & 2)) - (v53_b + ((~(((v55_b ^ -1) | (-(v55_b ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
    v124_b[v242_b] = v121_b;
    int * v126_b = (v19_p->b)->cache_vals;
    int v245_b = ((((((int)((unsigned int)((int)((unsigned int)v23_b >> 2)) >> 1)) & 1) * 2) + ((((v49_b + ((~(((v51_b ^ -1) | (-(v51_b ^ -1))) >> 31)) & 2)) - (v53_b + ((~(((v55_b ^ -1) | (-(v55_b ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
    v126_b[v245_b] = v123_b;
    int * v128_b = (v19_p->b)->cache_tags;
    int v248_b = ((((int)((unsigned int)((int)((unsigned int)v23_b >> 2)) >> 1)) & 1) * 2) + ((((v49_b + ((~(((v51_b ^ -1) | (-(v51_b ^ -1))) >> 31)) & 2)) - (v53_b + ((~(((v55_b ^ -1) | (-(v55_b ^ -1))) >> 31)) & 2))) >> 31) & 1);
    int v249_b = (int)((unsigned int)((int)((unsigned int)v23_b >> 2)) >> 1);
    v128_b[v248_b] = v249_b;
    int * v130_b = (v19_p->b)->cache_dirty;
    v130_b[v248_b] = 0;
    int * v132_b = (v19_p->b)->cache_age;
    v132_b[v248_b] = 1;
    int * v134_b = (v19_p->b)->cache_age;
    int v135_b = v134_b[v248_b];
    int * v136_b = (v19_p->b)->cache_age;
    int v137_b = v136_b[v157_b];
    int * v138_b = (v19_p->b)->cache_age;
    int v257_b = v137_b + ((int)((unsigned int)(v137_b - v135_b) >> 31));
    v138_b[v157_b] = v257_b;
    int * v140_b = (v19_p->b)->cache_age;
    int v141_b = v140_b[v159_b];
    int * v142_b = (v19_p->b)->cache_age;
    int v260_b = v141_b + ((int)((unsigned int)(v141_b - v135_b) >> 31));
    v142_b[v159_b] = v260_b;
    int * v144_b = (v19_p->b)->cache_age;
    v144_b[v248_b] = 0;
    v147_b = v248_b;
  }
  int v263_a = (v147_a * 2) + (((int)((unsigned int)v23_a >> 2)) & 1);
  int v263_b = (v147_b * 2) + (((int)((unsigned int)v23_b >> 2)) & 1);
  int v148_a = v34_a[v263_a];
  int v148_b = v34_b[v263_b];
  int * v149_a = (v19_p->a)->regs;
  int * v149_b = (v19_p->b)->regs;
  v149_a[11] = v148_a;
  v149_b[11] = v148_b;
  struct StateT2 * v151_p = slot_2(v19_p);
  return v151_p;
}

struct StateT2 * slot_2(struct StateT2 * v269_p) {
  lockstep_assert(((v269_p->a)->timer) == ((v269_p->b)->timer));
  lockstep_assume(((v269_p->a)->timer) == ((v269_p->b)->timer));
  int v270_a = (v269_p->a)->timer;
  int v270_b = (v269_p->b)->timer;
  int v278_a = v270_a + 1;
  int v278_b = v270_b + 1;
  (v269_p->a)->timer = v278_a;
  (v269_p->b)->timer = v278_b;
  int * v272_a = (v269_p->a)->regs;
  int * v272_b = (v269_p->b)->regs;
  int v273_a = v272_a[11];
  int v273_b = v272_b[11];
  int * v274_a = (v269_p->a)->regs;
  int * v274_b = (v269_p->b)->regs;
  int v282_a = v273_a << 2;
  int v282_b = v273_b << 2;
  v274_a[11] = v282_a;
  v274_b[11] = v282_b;
  struct StateT2 * v276_p = slot_3(v269_p);
  return v276_p;
}

struct StateT2 * slot_3(struct StateT2 * v285_p) {
  lockstep_assert(((v285_p->a)->timer) == ((v285_p->b)->timer));
  lockstep_assume(((v285_p->a)->timer) == ((v285_p->b)->timer));
  int v286_a = (v285_p->a)->timer;
  int v286_b = (v285_p->b)->timer;
  int v418_a = v286_a + 1;
  int v418_b = v286_b + 1;
  (v285_p->a)->timer = v418_a;
  (v285_p->b)->timer = v418_b;
  int * v288_a = (v285_p->a)->regs;
  int * v288_b = (v285_p->b)->regs;
  int v289_a = v288_a[11];
  int v289_b = v288_b[11];
  int * v290_a = (v285_p->a)->cache_tags;
  int * v290_b = (v285_p->b)->cache_tags;
  int v422_a = (((int)((unsigned int)((int)((unsigned int)(v289_a + 16) >> 2)) >> 1)) & 1) * 2;
  int v422_b = (((int)((unsigned int)((int)((unsigned int)(v289_b + 16) >> 2)) >> 1)) & 1) * 2;
  int v291_a = v290_a[v422_a];
  int v291_b = v290_b[v422_b];
  int * v292_a = (v285_p->a)->cache_tags;
  int * v292_b = (v285_p->b)->cache_tags;
  int v424_a = ((((int)((unsigned int)((int)((unsigned int)(v289_a + 16) >> 2)) >> 1)) & 1) * 2) + 1;
  int v424_b = ((((int)((unsigned int)((int)((unsigned int)(v289_b + 16) >> 2)) >> 1)) & 1) * 2) + 1;
  int v293_a = v292_a[v424_a];
  int v293_b = v292_b[v424_b];
  int * v294_a = (v285_p->a)->cache_tags;
  int * v294_b = (v285_p->b)->cache_tags;
  int v426_a = 4 + ((((int)((unsigned int)((int)((unsigned int)(v289_a + 16) >> 2)) >> 1)) & 3) * 2);
  int v426_b = 4 + ((((int)((unsigned int)((int)((unsigned int)(v289_b + 16) >> 2)) >> 1)) & 3) * 2);
  int v295_a = v294_a[v426_a];
  int v295_b = v294_b[v426_b];
  int * v296_a = (v285_p->a)->cache_tags;
  int * v296_b = (v285_p->b)->cache_tags;
  int v428_a = (4 + ((((int)((unsigned int)((int)((unsigned int)(v289_a + 16) >> 2)) >> 1)) & 3) * 2)) + 1;
  int v428_b = (4 + ((((int)((unsigned int)((int)((unsigned int)(v289_b + 16) >> 2)) >> 1)) & 3) * 2)) + 1;
  int v297_a = v296_a[v428_a];
  int v297_b = v296_b[v428_b];
  int v298_a = (v285_p->a)->timer;
  int v298_b = (v285_p->b)->timer;
  int v429_a = v298_a + ((100 ^ (((~(((v295_a ^ ((int)((unsigned int)((int)((unsigned int)(v289_a + 16) >> 2)) >> 1))) | (-(v295_a ^ ((int)((unsigned int)((int)((unsigned int)(v289_a + 16) >> 2)) >> 1))))) >> 31)) | (~(((v297_a ^ ((int)((unsigned int)((int)((unsigned int)(v289_a + 16) >> 2)) >> 1))) | (-(v297_a ^ ((int)((unsigned int)((int)((unsigned int)(v289_a + 16) >> 2)) >> 1))))) >> 31))) & 104)) ^ (((~(((v291_a ^ ((int)((unsigned int)((int)((unsigned int)(v289_a + 16) >> 2)) >> 1))) | (-(v291_a ^ ((int)((unsigned int)((int)((unsigned int)(v289_a + 16) >> 2)) >> 1))))) >> 31)) | (~(((v293_a ^ ((int)((unsigned int)((int)((unsigned int)(v289_a + 16) >> 2)) >> 1))) | (-(v293_a ^ ((int)((unsigned int)((int)((unsigned int)(v289_a + 16) >> 2)) >> 1))))) >> 31))) & (1 ^ (100 ^ (((~(((v295_a ^ ((int)((unsigned int)((int)((unsigned int)(v289_a + 16) >> 2)) >> 1))) | (-(v295_a ^ ((int)((unsigned int)((int)((unsigned int)(v289_a + 16) >> 2)) >> 1))))) >> 31)) | (~(((v297_a ^ ((int)((unsigned int)((int)((unsigned int)(v289_a + 16) >> 2)) >> 1))) | (-(v297_a ^ ((int)((unsigned int)((int)((unsigned int)(v289_a + 16) >> 2)) >> 1))))) >> 31))) & 104)))));
  int v429_b = v298_b + ((100 ^ (((~(((v295_b ^ ((int)((unsigned int)((int)((unsigned int)(v289_b + 16) >> 2)) >> 1))) | (-(v295_b ^ ((int)((unsigned int)((int)((unsigned int)(v289_b + 16) >> 2)) >> 1))))) >> 31)) | (~(((v297_b ^ ((int)((unsigned int)((int)((unsigned int)(v289_b + 16) >> 2)) >> 1))) | (-(v297_b ^ ((int)((unsigned int)((int)((unsigned int)(v289_b + 16) >> 2)) >> 1))))) >> 31))) & 104)) ^ (((~(((v291_b ^ ((int)((unsigned int)((int)((unsigned int)(v289_b + 16) >> 2)) >> 1))) | (-(v291_b ^ ((int)((unsigned int)((int)((unsigned int)(v289_b + 16) >> 2)) >> 1))))) >> 31)) | (~(((v293_b ^ ((int)((unsigned int)((int)((unsigned int)(v289_b + 16) >> 2)) >> 1))) | (-(v293_b ^ ((int)((unsigned int)((int)((unsigned int)(v289_b + 16) >> 2)) >> 1))))) >> 31))) & (1 ^ (100 ^ (((~(((v295_b ^ ((int)((unsigned int)((int)((unsigned int)(v289_b + 16) >> 2)) >> 1))) | (-(v295_b ^ ((int)((unsigned int)((int)((unsigned int)(v289_b + 16) >> 2)) >> 1))))) >> 31)) | (~(((v297_b ^ ((int)((unsigned int)((int)((unsigned int)(v289_b + 16) >> 2)) >> 1))) | (-(v297_b ^ ((int)((unsigned int)((int)((unsigned int)(v289_b + 16) >> 2)) >> 1))))) >> 31))) & 104)))));
  (v285_p->a)->timer = v429_a;
  (v285_p->b)->timer = v429_b;
  int * v300_a = (v285_p->a)->cache_vals;
  int * v300_b = (v285_p->b)->cache_vals;
  bool v430_a = !(((~(((v291_a ^ ((int)((unsigned int)((int)((unsigned int)(v289_a + 16) >> 2)) >> 1))) | (-(v291_a ^ ((int)((unsigned int)((int)((unsigned int)(v289_a + 16) >> 2)) >> 1))))) >> 31)) | (~(((v293_a ^ ((int)((unsigned int)((int)((unsigned int)(v289_a + 16) >> 2)) >> 1))) | (-(v293_a ^ ((int)((unsigned int)((int)((unsigned int)(v289_a + 16) >> 2)) >> 1))))) >> 31))) == 0);
  bool v430_b = !(((~(((v291_b ^ ((int)((unsigned int)((int)((unsigned int)(v289_b + 16) >> 2)) >> 1))) | (-(v291_b ^ ((int)((unsigned int)((int)((unsigned int)(v289_b + 16) >> 2)) >> 1))))) >> 31)) | (~(((v293_b ^ ((int)((unsigned int)((int)((unsigned int)(v289_b + 16) >> 2)) >> 1))) | (-(v293_b ^ ((int)((unsigned int)((int)((unsigned int)(v289_b + 16) >> 2)) >> 1))))) >> 31))) == 0);
  int v413_a;
  if (v430_a) {
    int * v301_a = (v285_p->a)->cache_age;
    int v432_a = ((((int)((unsigned int)((int)((unsigned int)(v289_a + 16) >> 2)) >> 1)) & 1) * 2) + ((~(((v293_a ^ ((int)((unsigned int)((int)((unsigned int)(v289_a + 16) >> 2)) >> 1))) | (-(v293_a ^ ((int)((unsigned int)((int)((unsigned int)(v289_a + 16) >> 2)) >> 1))))) >> 31)) & 1);
    int v302_a = v301_a[v432_a];
    int * v303_a = (v285_p->a)->cache_age;
    int v304_a = v303_a[v422_a];
    int * v305_a = (v285_p->a)->cache_age;
    int v435_a = v304_a + ((int)((unsigned int)(v304_a - v302_a) >> 31));
    v305_a[v422_a] = v435_a;
    int * v307_a = (v285_p->a)->cache_age;
    int v308_a = v307_a[v424_a];
    int * v309_a = (v285_p->a)->cache_age;
    int v438_a = v308_a + ((int)((unsigned int)(v308_a - v302_a) >> 31));
    v309_a[v424_a] = v438_a;
    int * v311_a = (v285_p->a)->cache_age;
    v311_a[v432_a] = 0;
    v413_a = v432_a;
  } else {
    int * v314_a = (v285_p->a)->cache_age;
    int v442_a = (((int)((unsigned int)((int)((unsigned int)(v289_a + 16) >> 2)) >> 1)) & 1) * 2;
    int v315_a = v314_a[v442_a];
    int * v316_a = (v285_p->a)->cache_tags;
    int v317_a = v316_a[v442_a];
    int * v318_a = (v285_p->a)->cache_age;
    int v319_a = v318_a[v424_a];
    int * v320_a = (v285_p->a)->cache_tags;
    int v321_a = v320_a[v424_a];
    bool v446_a = !(((~(((v295_a ^ ((int)((unsigned int)((int)((unsigned int)(v289_a + 16) >> 2)) >> 1))) | (-(v295_a ^ ((int)((unsigned int)((int)((unsigned int)(v289_a + 16) >> 2)) >> 1))))) >> 31)) | (~(((v297_a ^ ((int)((unsigned int)((int)((unsigned int)(v289_a + 16) >> 2)) >> 1))) | (-(v297_a ^ ((int)((unsigned int)((int)((unsigned int)(v289_a + 16) >> 2)) >> 1))))) >> 31))) == 0);
    int v385_a;
    if (v446_a) {
      int * v322_a = (v285_p->a)->cache_age;
      int v448_a = (4 + ((((int)((unsigned int)((int)((unsigned int)(v289_a + 16) >> 2)) >> 1)) & 3) * 2)) + ((~(((v297_a ^ ((int)((unsigned int)((int)((unsigned int)(v289_a + 16) >> 2)) >> 1))) | (-(v297_a ^ ((int)((unsigned int)((int)((unsigned int)(v289_a + 16) >> 2)) >> 1))))) >> 31)) & 1);
      int v323_a = v322_a[v448_a];
      int * v324_a = (v285_p->a)->cache_age;
      int v325_a = v324_a[v426_a];
      int * v326_a = (v285_p->a)->cache_age;
      int v451_a = v325_a + ((int)((unsigned int)(v325_a - v323_a) >> 31));
      v326_a[v426_a] = v451_a;
      int * v328_a = (v285_p->a)->cache_age;
      int v329_a = v328_a[v428_a];
      int * v330_a = (v285_p->a)->cache_age;
      int v454_a = v329_a + ((int)((unsigned int)(v329_a - v323_a) >> 31));
      v330_a[v428_a] = v454_a;
      int * v332_a = (v285_p->a)->cache_age;
      v332_a[v448_a] = 0;
      v385_a = v448_a;
    } else {
      int * v335_a = (v285_p->a)->cache_age;
      int v458_a = 4 + ((((int)((unsigned int)((int)((unsigned int)(v289_a + 16) >> 2)) >> 1)) & 3) * 2);
      int v336_a = v335_a[v458_a];
      int * v337_a = (v285_p->a)->cache_tags;
      int v338_a = v337_a[v458_a];
      int * v339_a = (v285_p->a)->cache_age;
      int v340_a = v339_a[v428_a];
      int * v341_a = (v285_p->a)->cache_tags;
      int v342_a = v341_a[v428_a];
      int * v343_a = (v285_p->a)->cache_dirty;
      int v463_a = (4 + ((((int)((unsigned int)((int)((unsigned int)(v289_a + 16) >> 2)) >> 1)) & 3) * 2)) + ((((v336_a + ((~(((v338_a ^ -1) | (-(v338_a ^ -1))) >> 31)) & 2)) - (v340_a + ((~(((v342_a ^ -1) | (-(v342_a ^ -1))) >> 31)) & 2))) >> 31) & 1);
      int v344_a = v343_a[v463_a];
      bool v464_a = !(v344_a == 0);
      if (v464_a) {
        int * v345_a = (v285_p->a)->cache_tags;
        int v346_a = v345_a[v463_a];
        int * v347_a = (v285_p->a)->cache_vals;
        int v467_a = ((4 + ((((int)((unsigned int)((int)((unsigned int)(v289_a + 16) >> 2)) >> 1)) & 3) * 2)) + ((((v336_a + ((~(((v338_a ^ -1) | (-(v338_a ^ -1))) >> 31)) & 2)) - (v340_a + ((~(((v342_a ^ -1) | (-(v342_a ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
        int v348_a = v347_a[v467_a];
        int * v349_a = (v285_p->a)->cache_vals;
        int v469_a = (((4 + ((((int)((unsigned int)((int)((unsigned int)(v289_a + 16) >> 2)) >> 1)) & 3) * 2)) + ((((v336_a + ((~(((v338_a ^ -1) | (-(v338_a ^ -1))) >> 31)) & 2)) - (v340_a + ((~(((v342_a ^ -1) | (-(v342_a ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
        int v350_a = v349_a[v469_a];
        int * v351_a = (v285_p->a)->mem;
        int v471_a = v346_a * 2;
        v351_a[v471_a] = v348_a;
        int * v353_a = (v285_p->a)->mem;
        int v474_a = (v346_a * 2) + 1;
        v353_a[v474_a] = v350_a;
        ;
      } else {
        ;
      }
      int * v358_a = (v285_p->a)->mem;
      int v479_a = ((int)((unsigned int)((int)((unsigned int)(v289_a + 16) >> 2)) >> 1)) * 2;
      int v359_a = v358_a[v479_a];
      int * v360_a = (v285_p->a)->mem;
      int v481_a = (((int)((unsigned int)((int)((unsigned int)(v289_a + 16) >> 2)) >> 1)) * 2) + 1;
      int v361_a = v360_a[v481_a];
      int * v362_a = (v285_p->a)->cache_vals;
      int v483_a = ((4 + ((((int)((unsigned int)((int)((unsigned int)(v289_a + 16) >> 2)) >> 1)) & 3) * 2)) + ((((v336_a + ((~(((v338_a ^ -1) | (-(v338_a ^ -1))) >> 31)) & 2)) - (v340_a + ((~(((v342_a ^ -1) | (-(v342_a ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
      v362_a[v483_a] = v359_a;
      int * v364_a = (v285_p->a)->cache_vals;
      int v486_a = (((4 + ((((int)((unsigned int)((int)((unsigned int)(v289_a + 16) >> 2)) >> 1)) & 3) * 2)) + ((((v336_a + ((~(((v338_a ^ -1) | (-(v338_a ^ -1))) >> 31)) & 2)) - (v340_a + ((~(((v342_a ^ -1) | (-(v342_a ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
      v364_a[v486_a] = v361_a;
      int * v366_a = (v285_p->a)->cache_tags;
      int v489_a = (int)((unsigned int)((int)((unsigned int)(v289_a + 16) >> 2)) >> 1);
      v366_a[v463_a] = v489_a;
      int * v368_a = (v285_p->a)->cache_dirty;
      v368_a[v463_a] = 0;
      int * v370_a = (v285_p->a)->cache_age;
      v370_a[v463_a] = 1;
      int * v372_a = (v285_p->a)->cache_age;
      int v373_a = v372_a[v463_a];
      int * v374_a = (v285_p->a)->cache_age;
      int v375_a = v374_a[v426_a];
      int * v376_a = (v285_p->a)->cache_age;
      int v497_a = v375_a + ((int)((unsigned int)(v375_a - v373_a) >> 31));
      v376_a[v426_a] = v497_a;
      int * v378_a = (v285_p->a)->cache_age;
      int v379_a = v378_a[v428_a];
      int * v380_a = (v285_p->a)->cache_age;
      int v500_a = v379_a + ((int)((unsigned int)(v379_a - v373_a) >> 31));
      v380_a[v428_a] = v500_a;
      int * v382_a = (v285_p->a)->cache_age;
      v382_a[v463_a] = 0;
      v385_a = v463_a;
    }
    int * v386_a = (v285_p->a)->cache_vals;
    int v503_a = v385_a * 2;
    int v387_a = v386_a[v503_a];
    int * v388_a = (v285_p->a)->cache_vals;
    int v505_a = (v385_a * 2) + 1;
    int v389_a = v388_a[v505_a];
    int * v390_a = (v285_p->a)->cache_vals;
    int v507_a = (((((int)((unsigned int)((int)((unsigned int)(v289_a + 16) >> 2)) >> 1)) & 1) * 2) + ((((v315_a + ((~(((v317_a ^ -1) | (-(v317_a ^ -1))) >> 31)) & 2)) - (v319_a + ((~(((v321_a ^ -1) | (-(v321_a ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
    v390_a[v507_a] = v387_a;
    int * v392_a = (v285_p->a)->cache_vals;
    int v510_a = ((((((int)((unsigned int)((int)((unsigned int)(v289_a + 16) >> 2)) >> 1)) & 1) * 2) + ((((v315_a + ((~(((v317_a ^ -1) | (-(v317_a ^ -1))) >> 31)) & 2)) - (v319_a + ((~(((v321_a ^ -1) | (-(v321_a ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
    v392_a[v510_a] = v389_a;
    int * v394_a = (v285_p->a)->cache_tags;
    int v513_a = ((((int)((unsigned int)((int)((unsigned int)(v289_a + 16) >> 2)) >> 1)) & 1) * 2) + ((((v315_a + ((~(((v317_a ^ -1) | (-(v317_a ^ -1))) >> 31)) & 2)) - (v319_a + ((~(((v321_a ^ -1) | (-(v321_a ^ -1))) >> 31)) & 2))) >> 31) & 1);
    int v514_a = (int)((unsigned int)((int)((unsigned int)(v289_a + 16) >> 2)) >> 1);
    v394_a[v513_a] = v514_a;
    int * v396_a = (v285_p->a)->cache_dirty;
    v396_a[v513_a] = 0;
    int * v398_a = (v285_p->a)->cache_age;
    v398_a[v513_a] = 1;
    int * v400_a = (v285_p->a)->cache_age;
    int v401_a = v400_a[v513_a];
    int * v402_a = (v285_p->a)->cache_age;
    int v403_a = v402_a[v422_a];
    int * v404_a = (v285_p->a)->cache_age;
    int v522_a = v403_a + ((int)((unsigned int)(v403_a - v401_a) >> 31));
    v404_a[v422_a] = v522_a;
    int * v406_a = (v285_p->a)->cache_age;
    int v407_a = v406_a[v424_a];
    int * v408_a = (v285_p->a)->cache_age;
    int v525_a = v407_a + ((int)((unsigned int)(v407_a - v401_a) >> 31));
    v408_a[v424_a] = v525_a;
    int * v410_a = (v285_p->a)->cache_age;
    v410_a[v513_a] = 0;
    v413_a = v513_a;
  }
  int v413_b;
  if (v430_b) {
    int * v301_b = (v285_p->b)->cache_age;
    int v432_b = ((((int)((unsigned int)((int)((unsigned int)(v289_b + 16) >> 2)) >> 1)) & 1) * 2) + ((~(((v293_b ^ ((int)((unsigned int)((int)((unsigned int)(v289_b + 16) >> 2)) >> 1))) | (-(v293_b ^ ((int)((unsigned int)((int)((unsigned int)(v289_b + 16) >> 2)) >> 1))))) >> 31)) & 1);
    int v302_b = v301_b[v432_b];
    int * v303_b = (v285_p->b)->cache_age;
    int v304_b = v303_b[v422_b];
    int * v305_b = (v285_p->b)->cache_age;
    int v435_b = v304_b + ((int)((unsigned int)(v304_b - v302_b) >> 31));
    v305_b[v422_b] = v435_b;
    int * v307_b = (v285_p->b)->cache_age;
    int v308_b = v307_b[v424_b];
    int * v309_b = (v285_p->b)->cache_age;
    int v438_b = v308_b + ((int)((unsigned int)(v308_b - v302_b) >> 31));
    v309_b[v424_b] = v438_b;
    int * v311_b = (v285_p->b)->cache_age;
    v311_b[v432_b] = 0;
    v413_b = v432_b;
  } else {
    int * v314_b = (v285_p->b)->cache_age;
    int v442_b = (((int)((unsigned int)((int)((unsigned int)(v289_b + 16) >> 2)) >> 1)) & 1) * 2;
    int v315_b = v314_b[v442_b];
    int * v316_b = (v285_p->b)->cache_tags;
    int v317_b = v316_b[v442_b];
    int * v318_b = (v285_p->b)->cache_age;
    int v319_b = v318_b[v424_b];
    int * v320_b = (v285_p->b)->cache_tags;
    int v321_b = v320_b[v424_b];
    bool v446_b = !(((~(((v295_b ^ ((int)((unsigned int)((int)((unsigned int)(v289_b + 16) >> 2)) >> 1))) | (-(v295_b ^ ((int)((unsigned int)((int)((unsigned int)(v289_b + 16) >> 2)) >> 1))))) >> 31)) | (~(((v297_b ^ ((int)((unsigned int)((int)((unsigned int)(v289_b + 16) >> 2)) >> 1))) | (-(v297_b ^ ((int)((unsigned int)((int)((unsigned int)(v289_b + 16) >> 2)) >> 1))))) >> 31))) == 0);
    int v385_b;
    if (v446_b) {
      int * v322_b = (v285_p->b)->cache_age;
      int v448_b = (4 + ((((int)((unsigned int)((int)((unsigned int)(v289_b + 16) >> 2)) >> 1)) & 3) * 2)) + ((~(((v297_b ^ ((int)((unsigned int)((int)((unsigned int)(v289_b + 16) >> 2)) >> 1))) | (-(v297_b ^ ((int)((unsigned int)((int)((unsigned int)(v289_b + 16) >> 2)) >> 1))))) >> 31)) & 1);
      int v323_b = v322_b[v448_b];
      int * v324_b = (v285_p->b)->cache_age;
      int v325_b = v324_b[v426_b];
      int * v326_b = (v285_p->b)->cache_age;
      int v451_b = v325_b + ((int)((unsigned int)(v325_b - v323_b) >> 31));
      v326_b[v426_b] = v451_b;
      int * v328_b = (v285_p->b)->cache_age;
      int v329_b = v328_b[v428_b];
      int * v330_b = (v285_p->b)->cache_age;
      int v454_b = v329_b + ((int)((unsigned int)(v329_b - v323_b) >> 31));
      v330_b[v428_b] = v454_b;
      int * v332_b = (v285_p->b)->cache_age;
      v332_b[v448_b] = 0;
      v385_b = v448_b;
    } else {
      int * v335_b = (v285_p->b)->cache_age;
      int v458_b = 4 + ((((int)((unsigned int)((int)((unsigned int)(v289_b + 16) >> 2)) >> 1)) & 3) * 2);
      int v336_b = v335_b[v458_b];
      int * v337_b = (v285_p->b)->cache_tags;
      int v338_b = v337_b[v458_b];
      int * v339_b = (v285_p->b)->cache_age;
      int v340_b = v339_b[v428_b];
      int * v341_b = (v285_p->b)->cache_tags;
      int v342_b = v341_b[v428_b];
      int * v343_b = (v285_p->b)->cache_dirty;
      int v463_b = (4 + ((((int)((unsigned int)((int)((unsigned int)(v289_b + 16) >> 2)) >> 1)) & 3) * 2)) + ((((v336_b + ((~(((v338_b ^ -1) | (-(v338_b ^ -1))) >> 31)) & 2)) - (v340_b + ((~(((v342_b ^ -1) | (-(v342_b ^ -1))) >> 31)) & 2))) >> 31) & 1);
      int v344_b = v343_b[v463_b];
      bool v464_b = !(v344_b == 0);
      if (v464_b) {
        int * v345_b = (v285_p->b)->cache_tags;
        int v346_b = v345_b[v463_b];
        int * v347_b = (v285_p->b)->cache_vals;
        int v467_b = ((4 + ((((int)((unsigned int)((int)((unsigned int)(v289_b + 16) >> 2)) >> 1)) & 3) * 2)) + ((((v336_b + ((~(((v338_b ^ -1) | (-(v338_b ^ -1))) >> 31)) & 2)) - (v340_b + ((~(((v342_b ^ -1) | (-(v342_b ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
        int v348_b = v347_b[v467_b];
        int * v349_b = (v285_p->b)->cache_vals;
        int v469_b = (((4 + ((((int)((unsigned int)((int)((unsigned int)(v289_b + 16) >> 2)) >> 1)) & 3) * 2)) + ((((v336_b + ((~(((v338_b ^ -1) | (-(v338_b ^ -1))) >> 31)) & 2)) - (v340_b + ((~(((v342_b ^ -1) | (-(v342_b ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
        int v350_b = v349_b[v469_b];
        int * v351_b = (v285_p->b)->mem;
        int v471_b = v346_b * 2;
        v351_b[v471_b] = v348_b;
        int * v353_b = (v285_p->b)->mem;
        int v474_b = (v346_b * 2) + 1;
        v353_b[v474_b] = v350_b;
        ;
      } else {
        ;
      }
      int * v358_b = (v285_p->b)->mem;
      int v479_b = ((int)((unsigned int)((int)((unsigned int)(v289_b + 16) >> 2)) >> 1)) * 2;
      int v359_b = v358_b[v479_b];
      int * v360_b = (v285_p->b)->mem;
      int v481_b = (((int)((unsigned int)((int)((unsigned int)(v289_b + 16) >> 2)) >> 1)) * 2) + 1;
      int v361_b = v360_b[v481_b];
      int * v362_b = (v285_p->b)->cache_vals;
      int v483_b = ((4 + ((((int)((unsigned int)((int)((unsigned int)(v289_b + 16) >> 2)) >> 1)) & 3) * 2)) + ((((v336_b + ((~(((v338_b ^ -1) | (-(v338_b ^ -1))) >> 31)) & 2)) - (v340_b + ((~(((v342_b ^ -1) | (-(v342_b ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
      v362_b[v483_b] = v359_b;
      int * v364_b = (v285_p->b)->cache_vals;
      int v486_b = (((4 + ((((int)((unsigned int)((int)((unsigned int)(v289_b + 16) >> 2)) >> 1)) & 3) * 2)) + ((((v336_b + ((~(((v338_b ^ -1) | (-(v338_b ^ -1))) >> 31)) & 2)) - (v340_b + ((~(((v342_b ^ -1) | (-(v342_b ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
      v364_b[v486_b] = v361_b;
      int * v366_b = (v285_p->b)->cache_tags;
      int v489_b = (int)((unsigned int)((int)((unsigned int)(v289_b + 16) >> 2)) >> 1);
      v366_b[v463_b] = v489_b;
      int * v368_b = (v285_p->b)->cache_dirty;
      v368_b[v463_b] = 0;
      int * v370_b = (v285_p->b)->cache_age;
      v370_b[v463_b] = 1;
      int * v372_b = (v285_p->b)->cache_age;
      int v373_b = v372_b[v463_b];
      int * v374_b = (v285_p->b)->cache_age;
      int v375_b = v374_b[v426_b];
      int * v376_b = (v285_p->b)->cache_age;
      int v497_b = v375_b + ((int)((unsigned int)(v375_b - v373_b) >> 31));
      v376_b[v426_b] = v497_b;
      int * v378_b = (v285_p->b)->cache_age;
      int v379_b = v378_b[v428_b];
      int * v380_b = (v285_p->b)->cache_age;
      int v500_b = v379_b + ((int)((unsigned int)(v379_b - v373_b) >> 31));
      v380_b[v428_b] = v500_b;
      int * v382_b = (v285_p->b)->cache_age;
      v382_b[v463_b] = 0;
      v385_b = v463_b;
    }
    int * v386_b = (v285_p->b)->cache_vals;
    int v503_b = v385_b * 2;
    int v387_b = v386_b[v503_b];
    int * v388_b = (v285_p->b)->cache_vals;
    int v505_b = (v385_b * 2) + 1;
    int v389_b = v388_b[v505_b];
    int * v390_b = (v285_p->b)->cache_vals;
    int v507_b = (((((int)((unsigned int)((int)((unsigned int)(v289_b + 16) >> 2)) >> 1)) & 1) * 2) + ((((v315_b + ((~(((v317_b ^ -1) | (-(v317_b ^ -1))) >> 31)) & 2)) - (v319_b + ((~(((v321_b ^ -1) | (-(v321_b ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
    v390_b[v507_b] = v387_b;
    int * v392_b = (v285_p->b)->cache_vals;
    int v510_b = ((((((int)((unsigned int)((int)((unsigned int)(v289_b + 16) >> 2)) >> 1)) & 1) * 2) + ((((v315_b + ((~(((v317_b ^ -1) | (-(v317_b ^ -1))) >> 31)) & 2)) - (v319_b + ((~(((v321_b ^ -1) | (-(v321_b ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
    v392_b[v510_b] = v389_b;
    int * v394_b = (v285_p->b)->cache_tags;
    int v513_b = ((((int)((unsigned int)((int)((unsigned int)(v289_b + 16) >> 2)) >> 1)) & 1) * 2) + ((((v315_b + ((~(((v317_b ^ -1) | (-(v317_b ^ -1))) >> 31)) & 2)) - (v319_b + ((~(((v321_b ^ -1) | (-(v321_b ^ -1))) >> 31)) & 2))) >> 31) & 1);
    int v514_b = (int)((unsigned int)((int)((unsigned int)(v289_b + 16) >> 2)) >> 1);
    v394_b[v513_b] = v514_b;
    int * v396_b = (v285_p->b)->cache_dirty;
    v396_b[v513_b] = 0;
    int * v398_b = (v285_p->b)->cache_age;
    v398_b[v513_b] = 1;
    int * v400_b = (v285_p->b)->cache_age;
    int v401_b = v400_b[v513_b];
    int * v402_b = (v285_p->b)->cache_age;
    int v403_b = v402_b[v422_b];
    int * v404_b = (v285_p->b)->cache_age;
    int v522_b = v403_b + ((int)((unsigned int)(v403_b - v401_b) >> 31));
    v404_b[v422_b] = v522_b;
    int * v406_b = (v285_p->b)->cache_age;
    int v407_b = v406_b[v424_b];
    int * v408_b = (v285_p->b)->cache_age;
    int v525_b = v407_b + ((int)((unsigned int)(v407_b - v401_b) >> 31));
    v408_b[v424_b] = v525_b;
    int * v410_b = (v285_p->b)->cache_age;
    v410_b[v513_b] = 0;
    v413_b = v513_b;
  }
  int v528_a = (v413_a * 2) + (((int)((unsigned int)(v289_a + 16) >> 2)) & 1);
  int v528_b = (v413_b * 2) + (((int)((unsigned int)(v289_b + 16) >> 2)) & 1);
  int v414_a = v300_a[v528_a];
  int v414_b = v300_b[v528_b];
  int * v415_a = (v285_p->a)->regs;
  int * v415_b = (v285_p->b)->regs;
  v415_a[12] = v414_a;
  v415_b[12] = v414_b;
  return v285_p;
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
  for (int i=0; i<CACHE_ENTRIES; i++) {
    s->cache_tags[i] = -1;
    s->cache_dirty[i] = 0;
    s->cache_age[i] = 0;
  }
  for (int i=0; i<CACHE_WORDS; i++) {
    s->cache_vals[i] = 0;
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