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
struct StateT2 * slot_2(struct StateT2 * v223_p);
struct StateT2 * slot_3(struct StateT2 * v237_p);
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
  int v130_a = v20_a + 1;
  int v130_b = v20_b + 1;
  (v19_p->a)->timer = v130_a;
  (v19_p->b)->timer = v130_b;
  int * v22_a = (v19_p->a)->regs;
  int * v22_b = (v19_p->b)->regs;
  int v23_a = v22_a[10];
  int v23_b = v22_b[10];
  int * v24_a = (v19_p->a)->cache_tags;
  int * v24_b = (v19_p->b)->cache_tags;
  int v134_a = (((int)((unsigned int)((int)((unsigned int)v23_a >> 2)) >> 1)) & 1) * 2;
  int v134_b = (((int)((unsigned int)((int)((unsigned int)v23_b >> 2)) >> 1)) & 1) * 2;
  int v25_a = v24_a[v134_a];
  int v25_b = v24_b[v134_b];
  int v135_a = ((((int)((unsigned int)((int)((unsigned int)v23_a >> 2)) >> 1)) & 1) * 2) + 1;
  int v135_b = ((((int)((unsigned int)((int)((unsigned int)v23_b >> 2)) >> 1)) & 1) * 2) + 1;
  int v26_a = v24_a[v135_a];
  int v26_b = v24_b[v135_b];
  int v136_a = 4 + ((((int)((unsigned int)((int)((unsigned int)v23_a >> 2)) >> 1)) & 3) * 2);
  int v136_b = 4 + ((((int)((unsigned int)((int)((unsigned int)v23_b >> 2)) >> 1)) & 3) * 2);
  int v27_a = v24_a[v136_a];
  int v27_b = v24_b[v136_b];
  int v137_a = (4 + ((((int)((unsigned int)((int)((unsigned int)v23_a >> 2)) >> 1)) & 3) * 2)) + 1;
  int v137_b = (4 + ((((int)((unsigned int)((int)((unsigned int)v23_b >> 2)) >> 1)) & 3) * 2)) + 1;
  int v28_a = v24_a[v137_a];
  int v28_b = v24_b[v137_b];
  int v29_a = (v19_p->a)->timer;
  int v29_b = (v19_p->b)->timer;
  int v138_a = v29_a + ((100 ^ (((~(((v27_a ^ ((int)((unsigned int)((int)((unsigned int)v23_a >> 2)) >> 1))) | (-(v27_a ^ ((int)((unsigned int)((int)((unsigned int)v23_a >> 2)) >> 1))))) >> 31)) | (~(((v28_a ^ ((int)((unsigned int)((int)((unsigned int)v23_a >> 2)) >> 1))) | (-(v28_a ^ ((int)((unsigned int)((int)((unsigned int)v23_a >> 2)) >> 1))))) >> 31))) & 104)) ^ (((~(((v25_a ^ ((int)((unsigned int)((int)((unsigned int)v23_a >> 2)) >> 1))) | (-(v25_a ^ ((int)((unsigned int)((int)((unsigned int)v23_a >> 2)) >> 1))))) >> 31)) | (~(((v26_a ^ ((int)((unsigned int)((int)((unsigned int)v23_a >> 2)) >> 1))) | (-(v26_a ^ ((int)((unsigned int)((int)((unsigned int)v23_a >> 2)) >> 1))))) >> 31))) & (1 ^ (100 ^ (((~(((v27_a ^ ((int)((unsigned int)((int)((unsigned int)v23_a >> 2)) >> 1))) | (-(v27_a ^ ((int)((unsigned int)((int)((unsigned int)v23_a >> 2)) >> 1))))) >> 31)) | (~(((v28_a ^ ((int)((unsigned int)((int)((unsigned int)v23_a >> 2)) >> 1))) | (-(v28_a ^ ((int)((unsigned int)((int)((unsigned int)v23_a >> 2)) >> 1))))) >> 31))) & 104)))));
  int v138_b = v29_b + ((100 ^ (((~(((v27_b ^ ((int)((unsigned int)((int)((unsigned int)v23_b >> 2)) >> 1))) | (-(v27_b ^ ((int)((unsigned int)((int)((unsigned int)v23_b >> 2)) >> 1))))) >> 31)) | (~(((v28_b ^ ((int)((unsigned int)((int)((unsigned int)v23_b >> 2)) >> 1))) | (-(v28_b ^ ((int)((unsigned int)((int)((unsigned int)v23_b >> 2)) >> 1))))) >> 31))) & 104)) ^ (((~(((v25_b ^ ((int)((unsigned int)((int)((unsigned int)v23_b >> 2)) >> 1))) | (-(v25_b ^ ((int)((unsigned int)((int)((unsigned int)v23_b >> 2)) >> 1))))) >> 31)) | (~(((v26_b ^ ((int)((unsigned int)((int)((unsigned int)v23_b >> 2)) >> 1))) | (-(v26_b ^ ((int)((unsigned int)((int)((unsigned int)v23_b >> 2)) >> 1))))) >> 31))) & (1 ^ (100 ^ (((~(((v27_b ^ ((int)((unsigned int)((int)((unsigned int)v23_b >> 2)) >> 1))) | (-(v27_b ^ ((int)((unsigned int)((int)((unsigned int)v23_b >> 2)) >> 1))))) >> 31)) | (~(((v28_b ^ ((int)((unsigned int)((int)((unsigned int)v23_b >> 2)) >> 1))) | (-(v28_b ^ ((int)((unsigned int)((int)((unsigned int)v23_b >> 2)) >> 1))))) >> 31))) & 104)))));
  (v19_p->a)->timer = v138_a;
  (v19_p->b)->timer = v138_b;
  int * v31_a = (v19_p->a)->cache_vals;
  int * v31_b = (v19_p->b)->cache_vals;
  bool v139_a = !(((~(((v25_a ^ ((int)((unsigned int)((int)((unsigned int)v23_a >> 2)) >> 1))) | (-(v25_a ^ ((int)((unsigned int)((int)((unsigned int)v23_a >> 2)) >> 1))))) >> 31)) | (~(((v26_a ^ ((int)((unsigned int)((int)((unsigned int)v23_a >> 2)) >> 1))) | (-(v26_a ^ ((int)((unsigned int)((int)((unsigned int)v23_a >> 2)) >> 1))))) >> 31))) == 0);
  bool v139_b = !(((~(((v25_b ^ ((int)((unsigned int)((int)((unsigned int)v23_b >> 2)) >> 1))) | (-(v25_b ^ ((int)((unsigned int)((int)((unsigned int)v23_b >> 2)) >> 1))))) >> 31)) | (~(((v26_b ^ ((int)((unsigned int)((int)((unsigned int)v23_b >> 2)) >> 1))) | (-(v26_b ^ ((int)((unsigned int)((int)((unsigned int)v23_b >> 2)) >> 1))))) >> 31))) == 0);
  int v124_a;
  if (v139_a) {
    int * v32_a = (v19_p->a)->cache_age;
    int v141_a = ((((int)((unsigned int)((int)((unsigned int)v23_a >> 2)) >> 1)) & 1) * 2) + ((~(((v26_a ^ ((int)((unsigned int)((int)((unsigned int)v23_a >> 2)) >> 1))) | (-(v26_a ^ ((int)((unsigned int)((int)((unsigned int)v23_a >> 2)) >> 1))))) >> 31)) & 1);
    int v33_a = v32_a[v141_a];
    int v34_a = v32_a[v134_a];
    int v142_a = v34_a + ((int)((unsigned int)(v34_a - v33_a) >> 31));
    v32_a[v134_a] = v142_a;
    int * v36_a = (v19_p->a)->cache_age;
    int v37_a = v36_a[v135_a];
    int v144_a = v37_a + ((int)((unsigned int)(v37_a - v33_a) >> 31));
    v36_a[v135_a] = v144_a;
    int * v39_a = (v19_p->a)->cache_age;
    v39_a[v141_a] = 0;
    v124_a = v141_a;
  } else {
    int * v42_a = (v19_p->a)->cache_age;
    int v148_a = (((int)((unsigned int)((int)((unsigned int)v23_a >> 2)) >> 1)) & 1) * 2;
    int v43_a = v42_a[v148_a];
    int * v44_a = (v19_p->a)->cache_tags;
    int v45_a = v44_a[v148_a];
    int v46_a = v42_a[v135_a];
    int v47_a = v44_a[v135_a];
    bool v150_a = !(((~(((v27_a ^ ((int)((unsigned int)((int)((unsigned int)v23_a >> 2)) >> 1))) | (-(v27_a ^ ((int)((unsigned int)((int)((unsigned int)v23_a >> 2)) >> 1))))) >> 31)) | (~(((v28_a ^ ((int)((unsigned int)((int)((unsigned int)v23_a >> 2)) >> 1))) | (-(v28_a ^ ((int)((unsigned int)((int)((unsigned int)v23_a >> 2)) >> 1))))) >> 31))) == 0);
    int v101_a;
    if (v150_a) {
      int * v48_a = (v19_p->a)->cache_age;
      int v152_a = (4 + ((((int)((unsigned int)((int)((unsigned int)v23_a >> 2)) >> 1)) & 3) * 2)) + ((~(((v28_a ^ ((int)((unsigned int)((int)((unsigned int)v23_a >> 2)) >> 1))) | (-(v28_a ^ ((int)((unsigned int)((int)((unsigned int)v23_a >> 2)) >> 1))))) >> 31)) & 1);
      int v49_a = v48_a[v152_a];
      int v50_a = v48_a[v136_a];
      int v153_a = v50_a + ((int)((unsigned int)(v50_a - v49_a) >> 31));
      v48_a[v136_a] = v153_a;
      int * v52_a = (v19_p->a)->cache_age;
      int v53_a = v52_a[v137_a];
      int v155_a = v53_a + ((int)((unsigned int)(v53_a - v49_a) >> 31));
      v52_a[v137_a] = v155_a;
      int * v55_a = (v19_p->a)->cache_age;
      v55_a[v152_a] = 0;
      v101_a = v152_a;
    } else {
      int * v58_a = (v19_p->a)->cache_age;
      int v159_a = 4 + ((((int)((unsigned int)((int)((unsigned int)v23_a >> 2)) >> 1)) & 3) * 2);
      int v59_a = v58_a[v159_a];
      int * v60_a = (v19_p->a)->cache_tags;
      int v61_a = v60_a[v159_a];
      int v62_a = v58_a[v137_a];
      int v63_a = v60_a[v137_a];
      int * v64_a = (v19_p->a)->cache_dirty;
      int v162_a = (4 + ((((int)((unsigned int)((int)((unsigned int)v23_a >> 2)) >> 1)) & 3) * 2)) + ((((v59_a + ((~(((v61_a ^ -1) | (-(v61_a ^ -1))) >> 31)) & 2)) - (v62_a + ((~(((v63_a ^ -1) | (-(v63_a ^ -1))) >> 31)) & 2))) >> 31) & 1);
      int v65_a = v64_a[v162_a];
      bool v163_a = !(v65_a == 0);
      if (v163_a) {
        int * v66_a = (v19_p->a)->cache_tags;
        int v67_a = v66_a[v162_a];
        int * v68_a = (v19_p->a)->cache_vals;
        int v166_a = ((4 + ((((int)((unsigned int)((int)((unsigned int)v23_a >> 2)) >> 1)) & 3) * 2)) + ((((v59_a + ((~(((v61_a ^ -1) | (-(v61_a ^ -1))) >> 31)) & 2)) - (v62_a + ((~(((v63_a ^ -1) | (-(v63_a ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
        int v69_a = v68_a[v166_a];
        int v167_a = (((4 + ((((int)((unsigned int)((int)((unsigned int)v23_a >> 2)) >> 1)) & 3) * 2)) + ((((v59_a + ((~(((v61_a ^ -1) | (-(v61_a ^ -1))) >> 31)) & 2)) - (v62_a + ((~(((v63_a ^ -1) | (-(v63_a ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
        int v70_a = v68_a[v167_a];
        int * v71_a = (v19_p->a)->mem;
        int v169_a = v67_a * 2;
        v71_a[v169_a] = v69_a;
        int * v73_a = (v19_p->a)->mem;
        int v172_a = (v67_a * 2) + 1;
        v73_a[v172_a] = v70_a;
        ;
      } else {
        ;
      }
      int * v78_a = (v19_p->a)->mem;
      int v177_a = ((int)((unsigned int)((int)((unsigned int)v23_a >> 2)) >> 1)) * 2;
      int v79_a = v78_a[v177_a];
      int v178_a = (((int)((unsigned int)((int)((unsigned int)v23_a >> 2)) >> 1)) * 2) + 1;
      int v80_a = v78_a[v178_a];
      int * v81_a = (v19_p->a)->cache_vals;
      int v180_a = ((4 + ((((int)((unsigned int)((int)((unsigned int)v23_a >> 2)) >> 1)) & 3) * 2)) + ((((v59_a + ((~(((v61_a ^ -1) | (-(v61_a ^ -1))) >> 31)) & 2)) - (v62_a + ((~(((v63_a ^ -1) | (-(v63_a ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
      v81_a[v180_a] = v79_a;
      int * v83_a = (v19_p->a)->cache_vals;
      int v183_a = (((4 + ((((int)((unsigned int)((int)((unsigned int)v23_a >> 2)) >> 1)) & 3) * 2)) + ((((v59_a + ((~(((v61_a ^ -1) | (-(v61_a ^ -1))) >> 31)) & 2)) - (v62_a + ((~(((v63_a ^ -1) | (-(v63_a ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
      v83_a[v183_a] = v80_a;
      int * v85_a = (v19_p->a)->cache_tags;
      int v186_a = (int)((unsigned int)((int)((unsigned int)v23_a >> 2)) >> 1);
      v85_a[v162_a] = v186_a;
      int * v87_a = (v19_p->a)->cache_dirty;
      v87_a[v162_a] = 0;
      int * v89_a = (v19_p->a)->cache_age;
      v89_a[v162_a] = 1;
      int * v91_a = (v19_p->a)->cache_age;
      int v92_a = v91_a[v162_a];
      int v93_a = v91_a[v136_a];
      int v192_a = v93_a + ((int)((unsigned int)(v93_a - v92_a) >> 31));
      v91_a[v136_a] = v192_a;
      int * v95_a = (v19_p->a)->cache_age;
      int v96_a = v95_a[v137_a];
      int v194_a = v96_a + ((int)((unsigned int)(v96_a - v92_a) >> 31));
      v95_a[v137_a] = v194_a;
      int * v98_a = (v19_p->a)->cache_age;
      v98_a[v162_a] = 0;
      v101_a = v162_a;
    }
    int * v102_a = (v19_p->a)->cache_vals;
    int v197_a = v101_a * 2;
    int v103_a = v102_a[v197_a];
    int v198_a = (v101_a * 2) + 1;
    int v104_a = v102_a[v198_a];
    int v199_a = (((((int)((unsigned int)((int)((unsigned int)v23_a >> 2)) >> 1)) & 1) * 2) + ((((v43_a + ((~(((v45_a ^ -1) | (-(v45_a ^ -1))) >> 31)) & 2)) - (v46_a + ((~(((v47_a ^ -1) | (-(v47_a ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
    v102_a[v199_a] = v103_a;
    int * v106_a = (v19_p->a)->cache_vals;
    int v202_a = ((((((int)((unsigned int)((int)((unsigned int)v23_a >> 2)) >> 1)) & 1) * 2) + ((((v43_a + ((~(((v45_a ^ -1) | (-(v45_a ^ -1))) >> 31)) & 2)) - (v46_a + ((~(((v47_a ^ -1) | (-(v47_a ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
    v106_a[v202_a] = v104_a;
    int * v108_a = (v19_p->a)->cache_tags;
    int v205_a = ((((int)((unsigned int)((int)((unsigned int)v23_a >> 2)) >> 1)) & 1) * 2) + ((((v43_a + ((~(((v45_a ^ -1) | (-(v45_a ^ -1))) >> 31)) & 2)) - (v46_a + ((~(((v47_a ^ -1) | (-(v47_a ^ -1))) >> 31)) & 2))) >> 31) & 1);
    int v206_a = (int)((unsigned int)((int)((unsigned int)v23_a >> 2)) >> 1);
    v108_a[v205_a] = v206_a;
    int * v110_a = (v19_p->a)->cache_dirty;
    v110_a[v205_a] = 0;
    int * v112_a = (v19_p->a)->cache_age;
    v112_a[v205_a] = 1;
    int * v114_a = (v19_p->a)->cache_age;
    int v115_a = v114_a[v205_a];
    int v116_a = v114_a[v134_a];
    int v212_a = v116_a + ((int)((unsigned int)(v116_a - v115_a) >> 31));
    v114_a[v134_a] = v212_a;
    int * v118_a = (v19_p->a)->cache_age;
    int v119_a = v118_a[v135_a];
    int v214_a = v119_a + ((int)((unsigned int)(v119_a - v115_a) >> 31));
    v118_a[v135_a] = v214_a;
    int * v121_a = (v19_p->a)->cache_age;
    v121_a[v205_a] = 0;
    v124_a = v205_a;
  }
  int v124_b;
  if (v139_b) {
    int * v32_b = (v19_p->b)->cache_age;
    int v141_b = ((((int)((unsigned int)((int)((unsigned int)v23_b >> 2)) >> 1)) & 1) * 2) + ((~(((v26_b ^ ((int)((unsigned int)((int)((unsigned int)v23_b >> 2)) >> 1))) | (-(v26_b ^ ((int)((unsigned int)((int)((unsigned int)v23_b >> 2)) >> 1))))) >> 31)) & 1);
    int v33_b = v32_b[v141_b];
    int v34_b = v32_b[v134_b];
    int v142_b = v34_b + ((int)((unsigned int)(v34_b - v33_b) >> 31));
    v32_b[v134_b] = v142_b;
    int * v36_b = (v19_p->b)->cache_age;
    int v37_b = v36_b[v135_b];
    int v144_b = v37_b + ((int)((unsigned int)(v37_b - v33_b) >> 31));
    v36_b[v135_b] = v144_b;
    int * v39_b = (v19_p->b)->cache_age;
    v39_b[v141_b] = 0;
    v124_b = v141_b;
  } else {
    int * v42_b = (v19_p->b)->cache_age;
    int v148_b = (((int)((unsigned int)((int)((unsigned int)v23_b >> 2)) >> 1)) & 1) * 2;
    int v43_b = v42_b[v148_b];
    int * v44_b = (v19_p->b)->cache_tags;
    int v45_b = v44_b[v148_b];
    int v46_b = v42_b[v135_b];
    int v47_b = v44_b[v135_b];
    bool v150_b = !(((~(((v27_b ^ ((int)((unsigned int)((int)((unsigned int)v23_b >> 2)) >> 1))) | (-(v27_b ^ ((int)((unsigned int)((int)((unsigned int)v23_b >> 2)) >> 1))))) >> 31)) | (~(((v28_b ^ ((int)((unsigned int)((int)((unsigned int)v23_b >> 2)) >> 1))) | (-(v28_b ^ ((int)((unsigned int)((int)((unsigned int)v23_b >> 2)) >> 1))))) >> 31))) == 0);
    int v101_b;
    if (v150_b) {
      int * v48_b = (v19_p->b)->cache_age;
      int v152_b = (4 + ((((int)((unsigned int)((int)((unsigned int)v23_b >> 2)) >> 1)) & 3) * 2)) + ((~(((v28_b ^ ((int)((unsigned int)((int)((unsigned int)v23_b >> 2)) >> 1))) | (-(v28_b ^ ((int)((unsigned int)((int)((unsigned int)v23_b >> 2)) >> 1))))) >> 31)) & 1);
      int v49_b = v48_b[v152_b];
      int v50_b = v48_b[v136_b];
      int v153_b = v50_b + ((int)((unsigned int)(v50_b - v49_b) >> 31));
      v48_b[v136_b] = v153_b;
      int * v52_b = (v19_p->b)->cache_age;
      int v53_b = v52_b[v137_b];
      int v155_b = v53_b + ((int)((unsigned int)(v53_b - v49_b) >> 31));
      v52_b[v137_b] = v155_b;
      int * v55_b = (v19_p->b)->cache_age;
      v55_b[v152_b] = 0;
      v101_b = v152_b;
    } else {
      int * v58_b = (v19_p->b)->cache_age;
      int v159_b = 4 + ((((int)((unsigned int)((int)((unsigned int)v23_b >> 2)) >> 1)) & 3) * 2);
      int v59_b = v58_b[v159_b];
      int * v60_b = (v19_p->b)->cache_tags;
      int v61_b = v60_b[v159_b];
      int v62_b = v58_b[v137_b];
      int v63_b = v60_b[v137_b];
      int * v64_b = (v19_p->b)->cache_dirty;
      int v162_b = (4 + ((((int)((unsigned int)((int)((unsigned int)v23_b >> 2)) >> 1)) & 3) * 2)) + ((((v59_b + ((~(((v61_b ^ -1) | (-(v61_b ^ -1))) >> 31)) & 2)) - (v62_b + ((~(((v63_b ^ -1) | (-(v63_b ^ -1))) >> 31)) & 2))) >> 31) & 1);
      int v65_b = v64_b[v162_b];
      bool v163_b = !(v65_b == 0);
      if (v163_b) {
        int * v66_b = (v19_p->b)->cache_tags;
        int v67_b = v66_b[v162_b];
        int * v68_b = (v19_p->b)->cache_vals;
        int v166_b = ((4 + ((((int)((unsigned int)((int)((unsigned int)v23_b >> 2)) >> 1)) & 3) * 2)) + ((((v59_b + ((~(((v61_b ^ -1) | (-(v61_b ^ -1))) >> 31)) & 2)) - (v62_b + ((~(((v63_b ^ -1) | (-(v63_b ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
        int v69_b = v68_b[v166_b];
        int v167_b = (((4 + ((((int)((unsigned int)((int)((unsigned int)v23_b >> 2)) >> 1)) & 3) * 2)) + ((((v59_b + ((~(((v61_b ^ -1) | (-(v61_b ^ -1))) >> 31)) & 2)) - (v62_b + ((~(((v63_b ^ -1) | (-(v63_b ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
        int v70_b = v68_b[v167_b];
        int * v71_b = (v19_p->b)->mem;
        int v169_b = v67_b * 2;
        v71_b[v169_b] = v69_b;
        int * v73_b = (v19_p->b)->mem;
        int v172_b = (v67_b * 2) + 1;
        v73_b[v172_b] = v70_b;
        ;
      } else {
        ;
      }
      int * v78_b = (v19_p->b)->mem;
      int v177_b = ((int)((unsigned int)((int)((unsigned int)v23_b >> 2)) >> 1)) * 2;
      int v79_b = v78_b[v177_b];
      int v178_b = (((int)((unsigned int)((int)((unsigned int)v23_b >> 2)) >> 1)) * 2) + 1;
      int v80_b = v78_b[v178_b];
      int * v81_b = (v19_p->b)->cache_vals;
      int v180_b = ((4 + ((((int)((unsigned int)((int)((unsigned int)v23_b >> 2)) >> 1)) & 3) * 2)) + ((((v59_b + ((~(((v61_b ^ -1) | (-(v61_b ^ -1))) >> 31)) & 2)) - (v62_b + ((~(((v63_b ^ -1) | (-(v63_b ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
      v81_b[v180_b] = v79_b;
      int * v83_b = (v19_p->b)->cache_vals;
      int v183_b = (((4 + ((((int)((unsigned int)((int)((unsigned int)v23_b >> 2)) >> 1)) & 3) * 2)) + ((((v59_b + ((~(((v61_b ^ -1) | (-(v61_b ^ -1))) >> 31)) & 2)) - (v62_b + ((~(((v63_b ^ -1) | (-(v63_b ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
      v83_b[v183_b] = v80_b;
      int * v85_b = (v19_p->b)->cache_tags;
      int v186_b = (int)((unsigned int)((int)((unsigned int)v23_b >> 2)) >> 1);
      v85_b[v162_b] = v186_b;
      int * v87_b = (v19_p->b)->cache_dirty;
      v87_b[v162_b] = 0;
      int * v89_b = (v19_p->b)->cache_age;
      v89_b[v162_b] = 1;
      int * v91_b = (v19_p->b)->cache_age;
      int v92_b = v91_b[v162_b];
      int v93_b = v91_b[v136_b];
      int v192_b = v93_b + ((int)((unsigned int)(v93_b - v92_b) >> 31));
      v91_b[v136_b] = v192_b;
      int * v95_b = (v19_p->b)->cache_age;
      int v96_b = v95_b[v137_b];
      int v194_b = v96_b + ((int)((unsigned int)(v96_b - v92_b) >> 31));
      v95_b[v137_b] = v194_b;
      int * v98_b = (v19_p->b)->cache_age;
      v98_b[v162_b] = 0;
      v101_b = v162_b;
    }
    int * v102_b = (v19_p->b)->cache_vals;
    int v197_b = v101_b * 2;
    int v103_b = v102_b[v197_b];
    int v198_b = (v101_b * 2) + 1;
    int v104_b = v102_b[v198_b];
    int v199_b = (((((int)((unsigned int)((int)((unsigned int)v23_b >> 2)) >> 1)) & 1) * 2) + ((((v43_b + ((~(((v45_b ^ -1) | (-(v45_b ^ -1))) >> 31)) & 2)) - (v46_b + ((~(((v47_b ^ -1) | (-(v47_b ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
    v102_b[v199_b] = v103_b;
    int * v106_b = (v19_p->b)->cache_vals;
    int v202_b = ((((((int)((unsigned int)((int)((unsigned int)v23_b >> 2)) >> 1)) & 1) * 2) + ((((v43_b + ((~(((v45_b ^ -1) | (-(v45_b ^ -1))) >> 31)) & 2)) - (v46_b + ((~(((v47_b ^ -1) | (-(v47_b ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
    v106_b[v202_b] = v104_b;
    int * v108_b = (v19_p->b)->cache_tags;
    int v205_b = ((((int)((unsigned int)((int)((unsigned int)v23_b >> 2)) >> 1)) & 1) * 2) + ((((v43_b + ((~(((v45_b ^ -1) | (-(v45_b ^ -1))) >> 31)) & 2)) - (v46_b + ((~(((v47_b ^ -1) | (-(v47_b ^ -1))) >> 31)) & 2))) >> 31) & 1);
    int v206_b = (int)((unsigned int)((int)((unsigned int)v23_b >> 2)) >> 1);
    v108_b[v205_b] = v206_b;
    int * v110_b = (v19_p->b)->cache_dirty;
    v110_b[v205_b] = 0;
    int * v112_b = (v19_p->b)->cache_age;
    v112_b[v205_b] = 1;
    int * v114_b = (v19_p->b)->cache_age;
    int v115_b = v114_b[v205_b];
    int v116_b = v114_b[v134_b];
    int v212_b = v116_b + ((int)((unsigned int)(v116_b - v115_b) >> 31));
    v114_b[v134_b] = v212_b;
    int * v118_b = (v19_p->b)->cache_age;
    int v119_b = v118_b[v135_b];
    int v214_b = v119_b + ((int)((unsigned int)(v119_b - v115_b) >> 31));
    v118_b[v135_b] = v214_b;
    int * v121_b = (v19_p->b)->cache_age;
    v121_b[v205_b] = 0;
    v124_b = v205_b;
  }
  int v217_a = (v124_a * 2) + (((int)((unsigned int)v23_a >> 2)) & 1);
  int v217_b = (v124_b * 2) + (((int)((unsigned int)v23_b >> 2)) & 1);
  int v125_a = v31_a[v217_a];
  int v125_b = v31_b[v217_b];
  int * v126_a = (v19_p->a)->regs;
  int * v126_b = (v19_p->b)->regs;
  v126_a[11] = v125_a;
  v126_b[11] = v125_b;
  struct StateT2 * v128_p = slot_2(v19_p);
  return v128_p;
}

struct StateT2 * slot_2(struct StateT2 * v223_p) {
  lockstep_assert(((v223_p->a)->timer) == ((v223_p->b)->timer));
  lockstep_assume(((v223_p->a)->timer) == ((v223_p->b)->timer));
  int v224_a = (v223_p->a)->timer;
  int v224_b = (v223_p->b)->timer;
  int v231_a = v224_a + 1;
  int v231_b = v224_b + 1;
  (v223_p->a)->timer = v231_a;
  (v223_p->b)->timer = v231_b;
  int * v226_a = (v223_p->a)->regs;
  int * v226_b = (v223_p->b)->regs;
  int v227_a = v226_a[11];
  int v227_b = v226_b[11];
  int v234_a = v227_a << 2;
  int v234_b = v227_b << 2;
  v226_a[11] = v234_a;
  v226_b[11] = v234_b;
  struct StateT2 * v229_p = slot_3(v223_p);
  return v229_p;
}

struct StateT2 * slot_3(struct StateT2 * v237_p) {
  lockstep_assert(((v237_p->a)->timer) == ((v237_p->b)->timer));
  lockstep_assume(((v237_p->a)->timer) == ((v237_p->b)->timer));
  int v238_a = (v237_p->a)->timer;
  int v238_b = (v237_p->b)->timer;
  int v347_a = v238_a + 1;
  int v347_b = v238_b + 1;
  (v237_p->a)->timer = v347_a;
  (v237_p->b)->timer = v347_b;
  int * v240_a = (v237_p->a)->regs;
  int * v240_b = (v237_p->b)->regs;
  int v241_a = v240_a[11];
  int v241_b = v240_b[11];
  int * v242_a = (v237_p->a)->cache_tags;
  int * v242_b = (v237_p->b)->cache_tags;
  int v351_a = (((int)((unsigned int)((int)((unsigned int)(v241_a + 16) >> 2)) >> 1)) & 1) * 2;
  int v351_b = (((int)((unsigned int)((int)((unsigned int)(v241_b + 16) >> 2)) >> 1)) & 1) * 2;
  int v243_a = v242_a[v351_a];
  int v243_b = v242_b[v351_b];
  int v352_a = ((((int)((unsigned int)((int)((unsigned int)(v241_a + 16) >> 2)) >> 1)) & 1) * 2) + 1;
  int v352_b = ((((int)((unsigned int)((int)((unsigned int)(v241_b + 16) >> 2)) >> 1)) & 1) * 2) + 1;
  int v244_a = v242_a[v352_a];
  int v244_b = v242_b[v352_b];
  int v353_a = 4 + ((((int)((unsigned int)((int)((unsigned int)(v241_a + 16) >> 2)) >> 1)) & 3) * 2);
  int v353_b = 4 + ((((int)((unsigned int)((int)((unsigned int)(v241_b + 16) >> 2)) >> 1)) & 3) * 2);
  int v245_a = v242_a[v353_a];
  int v245_b = v242_b[v353_b];
  int v354_a = (4 + ((((int)((unsigned int)((int)((unsigned int)(v241_a + 16) >> 2)) >> 1)) & 3) * 2)) + 1;
  int v354_b = (4 + ((((int)((unsigned int)((int)((unsigned int)(v241_b + 16) >> 2)) >> 1)) & 3) * 2)) + 1;
  int v246_a = v242_a[v354_a];
  int v246_b = v242_b[v354_b];
  int v247_a = (v237_p->a)->timer;
  int v247_b = (v237_p->b)->timer;
  int v355_a = v247_a + ((100 ^ (((~(((v245_a ^ ((int)((unsigned int)((int)((unsigned int)(v241_a + 16) >> 2)) >> 1))) | (-(v245_a ^ ((int)((unsigned int)((int)((unsigned int)(v241_a + 16) >> 2)) >> 1))))) >> 31)) | (~(((v246_a ^ ((int)((unsigned int)((int)((unsigned int)(v241_a + 16) >> 2)) >> 1))) | (-(v246_a ^ ((int)((unsigned int)((int)((unsigned int)(v241_a + 16) >> 2)) >> 1))))) >> 31))) & 104)) ^ (((~(((v243_a ^ ((int)((unsigned int)((int)((unsigned int)(v241_a + 16) >> 2)) >> 1))) | (-(v243_a ^ ((int)((unsigned int)((int)((unsigned int)(v241_a + 16) >> 2)) >> 1))))) >> 31)) | (~(((v244_a ^ ((int)((unsigned int)((int)((unsigned int)(v241_a + 16) >> 2)) >> 1))) | (-(v244_a ^ ((int)((unsigned int)((int)((unsigned int)(v241_a + 16) >> 2)) >> 1))))) >> 31))) & (1 ^ (100 ^ (((~(((v245_a ^ ((int)((unsigned int)((int)((unsigned int)(v241_a + 16) >> 2)) >> 1))) | (-(v245_a ^ ((int)((unsigned int)((int)((unsigned int)(v241_a + 16) >> 2)) >> 1))))) >> 31)) | (~(((v246_a ^ ((int)((unsigned int)((int)((unsigned int)(v241_a + 16) >> 2)) >> 1))) | (-(v246_a ^ ((int)((unsigned int)((int)((unsigned int)(v241_a + 16) >> 2)) >> 1))))) >> 31))) & 104)))));
  int v355_b = v247_b + ((100 ^ (((~(((v245_b ^ ((int)((unsigned int)((int)((unsigned int)(v241_b + 16) >> 2)) >> 1))) | (-(v245_b ^ ((int)((unsigned int)((int)((unsigned int)(v241_b + 16) >> 2)) >> 1))))) >> 31)) | (~(((v246_b ^ ((int)((unsigned int)((int)((unsigned int)(v241_b + 16) >> 2)) >> 1))) | (-(v246_b ^ ((int)((unsigned int)((int)((unsigned int)(v241_b + 16) >> 2)) >> 1))))) >> 31))) & 104)) ^ (((~(((v243_b ^ ((int)((unsigned int)((int)((unsigned int)(v241_b + 16) >> 2)) >> 1))) | (-(v243_b ^ ((int)((unsigned int)((int)((unsigned int)(v241_b + 16) >> 2)) >> 1))))) >> 31)) | (~(((v244_b ^ ((int)((unsigned int)((int)((unsigned int)(v241_b + 16) >> 2)) >> 1))) | (-(v244_b ^ ((int)((unsigned int)((int)((unsigned int)(v241_b + 16) >> 2)) >> 1))))) >> 31))) & (1 ^ (100 ^ (((~(((v245_b ^ ((int)((unsigned int)((int)((unsigned int)(v241_b + 16) >> 2)) >> 1))) | (-(v245_b ^ ((int)((unsigned int)((int)((unsigned int)(v241_b + 16) >> 2)) >> 1))))) >> 31)) | (~(((v246_b ^ ((int)((unsigned int)((int)((unsigned int)(v241_b + 16) >> 2)) >> 1))) | (-(v246_b ^ ((int)((unsigned int)((int)((unsigned int)(v241_b + 16) >> 2)) >> 1))))) >> 31))) & 104)))));
  (v237_p->a)->timer = v355_a;
  (v237_p->b)->timer = v355_b;
  int * v249_a = (v237_p->a)->cache_vals;
  int * v249_b = (v237_p->b)->cache_vals;
  bool v356_a = !(((~(((v243_a ^ ((int)((unsigned int)((int)((unsigned int)(v241_a + 16) >> 2)) >> 1))) | (-(v243_a ^ ((int)((unsigned int)((int)((unsigned int)(v241_a + 16) >> 2)) >> 1))))) >> 31)) | (~(((v244_a ^ ((int)((unsigned int)((int)((unsigned int)(v241_a + 16) >> 2)) >> 1))) | (-(v244_a ^ ((int)((unsigned int)((int)((unsigned int)(v241_a + 16) >> 2)) >> 1))))) >> 31))) == 0);
  bool v356_b = !(((~(((v243_b ^ ((int)((unsigned int)((int)((unsigned int)(v241_b + 16) >> 2)) >> 1))) | (-(v243_b ^ ((int)((unsigned int)((int)((unsigned int)(v241_b + 16) >> 2)) >> 1))))) >> 31)) | (~(((v244_b ^ ((int)((unsigned int)((int)((unsigned int)(v241_b + 16) >> 2)) >> 1))) | (-(v244_b ^ ((int)((unsigned int)((int)((unsigned int)(v241_b + 16) >> 2)) >> 1))))) >> 31))) == 0);
  int v342_a;
  if (v356_a) {
    int * v250_a = (v237_p->a)->cache_age;
    int v358_a = ((((int)((unsigned int)((int)((unsigned int)(v241_a + 16) >> 2)) >> 1)) & 1) * 2) + ((~(((v244_a ^ ((int)((unsigned int)((int)((unsigned int)(v241_a + 16) >> 2)) >> 1))) | (-(v244_a ^ ((int)((unsigned int)((int)((unsigned int)(v241_a + 16) >> 2)) >> 1))))) >> 31)) & 1);
    int v251_a = v250_a[v358_a];
    int v252_a = v250_a[v351_a];
    int v359_a = v252_a + ((int)((unsigned int)(v252_a - v251_a) >> 31));
    v250_a[v351_a] = v359_a;
    int * v254_a = (v237_p->a)->cache_age;
    int v255_a = v254_a[v352_a];
    int v361_a = v255_a + ((int)((unsigned int)(v255_a - v251_a) >> 31));
    v254_a[v352_a] = v361_a;
    int * v257_a = (v237_p->a)->cache_age;
    v257_a[v358_a] = 0;
    v342_a = v358_a;
  } else {
    int * v260_a = (v237_p->a)->cache_age;
    int v365_a = (((int)((unsigned int)((int)((unsigned int)(v241_a + 16) >> 2)) >> 1)) & 1) * 2;
    int v261_a = v260_a[v365_a];
    int * v262_a = (v237_p->a)->cache_tags;
    int v263_a = v262_a[v365_a];
    int v264_a = v260_a[v352_a];
    int v265_a = v262_a[v352_a];
    bool v367_a = !(((~(((v245_a ^ ((int)((unsigned int)((int)((unsigned int)(v241_a + 16) >> 2)) >> 1))) | (-(v245_a ^ ((int)((unsigned int)((int)((unsigned int)(v241_a + 16) >> 2)) >> 1))))) >> 31)) | (~(((v246_a ^ ((int)((unsigned int)((int)((unsigned int)(v241_a + 16) >> 2)) >> 1))) | (-(v246_a ^ ((int)((unsigned int)((int)((unsigned int)(v241_a + 16) >> 2)) >> 1))))) >> 31))) == 0);
    int v319_a;
    if (v367_a) {
      int * v266_a = (v237_p->a)->cache_age;
      int v369_a = (4 + ((((int)((unsigned int)((int)((unsigned int)(v241_a + 16) >> 2)) >> 1)) & 3) * 2)) + ((~(((v246_a ^ ((int)((unsigned int)((int)((unsigned int)(v241_a + 16) >> 2)) >> 1))) | (-(v246_a ^ ((int)((unsigned int)((int)((unsigned int)(v241_a + 16) >> 2)) >> 1))))) >> 31)) & 1);
      int v267_a = v266_a[v369_a];
      int v268_a = v266_a[v353_a];
      int v370_a = v268_a + ((int)((unsigned int)(v268_a - v267_a) >> 31));
      v266_a[v353_a] = v370_a;
      int * v270_a = (v237_p->a)->cache_age;
      int v271_a = v270_a[v354_a];
      int v372_a = v271_a + ((int)((unsigned int)(v271_a - v267_a) >> 31));
      v270_a[v354_a] = v372_a;
      int * v273_a = (v237_p->a)->cache_age;
      v273_a[v369_a] = 0;
      v319_a = v369_a;
    } else {
      int * v276_a = (v237_p->a)->cache_age;
      int v376_a = 4 + ((((int)((unsigned int)((int)((unsigned int)(v241_a + 16) >> 2)) >> 1)) & 3) * 2);
      int v277_a = v276_a[v376_a];
      int * v278_a = (v237_p->a)->cache_tags;
      int v279_a = v278_a[v376_a];
      int v280_a = v276_a[v354_a];
      int v281_a = v278_a[v354_a];
      int * v282_a = (v237_p->a)->cache_dirty;
      int v379_a = (4 + ((((int)((unsigned int)((int)((unsigned int)(v241_a + 16) >> 2)) >> 1)) & 3) * 2)) + ((((v277_a + ((~(((v279_a ^ -1) | (-(v279_a ^ -1))) >> 31)) & 2)) - (v280_a + ((~(((v281_a ^ -1) | (-(v281_a ^ -1))) >> 31)) & 2))) >> 31) & 1);
      int v283_a = v282_a[v379_a];
      bool v380_a = !(v283_a == 0);
      if (v380_a) {
        int * v284_a = (v237_p->a)->cache_tags;
        int v285_a = v284_a[v379_a];
        int * v286_a = (v237_p->a)->cache_vals;
        int v383_a = ((4 + ((((int)((unsigned int)((int)((unsigned int)(v241_a + 16) >> 2)) >> 1)) & 3) * 2)) + ((((v277_a + ((~(((v279_a ^ -1) | (-(v279_a ^ -1))) >> 31)) & 2)) - (v280_a + ((~(((v281_a ^ -1) | (-(v281_a ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
        int v287_a = v286_a[v383_a];
        int v384_a = (((4 + ((((int)((unsigned int)((int)((unsigned int)(v241_a + 16) >> 2)) >> 1)) & 3) * 2)) + ((((v277_a + ((~(((v279_a ^ -1) | (-(v279_a ^ -1))) >> 31)) & 2)) - (v280_a + ((~(((v281_a ^ -1) | (-(v281_a ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
        int v288_a = v286_a[v384_a];
        int * v289_a = (v237_p->a)->mem;
        int v386_a = v285_a * 2;
        v289_a[v386_a] = v287_a;
        int * v291_a = (v237_p->a)->mem;
        int v389_a = (v285_a * 2) + 1;
        v291_a[v389_a] = v288_a;
        ;
      } else {
        ;
      }
      int * v296_a = (v237_p->a)->mem;
      int v394_a = ((int)((unsigned int)((int)((unsigned int)(v241_a + 16) >> 2)) >> 1)) * 2;
      int v297_a = v296_a[v394_a];
      int v395_a = (((int)((unsigned int)((int)((unsigned int)(v241_a + 16) >> 2)) >> 1)) * 2) + 1;
      int v298_a = v296_a[v395_a];
      int * v299_a = (v237_p->a)->cache_vals;
      int v397_a = ((4 + ((((int)((unsigned int)((int)((unsigned int)(v241_a + 16) >> 2)) >> 1)) & 3) * 2)) + ((((v277_a + ((~(((v279_a ^ -1) | (-(v279_a ^ -1))) >> 31)) & 2)) - (v280_a + ((~(((v281_a ^ -1) | (-(v281_a ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
      v299_a[v397_a] = v297_a;
      int * v301_a = (v237_p->a)->cache_vals;
      int v400_a = (((4 + ((((int)((unsigned int)((int)((unsigned int)(v241_a + 16) >> 2)) >> 1)) & 3) * 2)) + ((((v277_a + ((~(((v279_a ^ -1) | (-(v279_a ^ -1))) >> 31)) & 2)) - (v280_a + ((~(((v281_a ^ -1) | (-(v281_a ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
      v301_a[v400_a] = v298_a;
      int * v303_a = (v237_p->a)->cache_tags;
      int v403_a = (int)((unsigned int)((int)((unsigned int)(v241_a + 16) >> 2)) >> 1);
      v303_a[v379_a] = v403_a;
      int * v305_a = (v237_p->a)->cache_dirty;
      v305_a[v379_a] = 0;
      int * v307_a = (v237_p->a)->cache_age;
      v307_a[v379_a] = 1;
      int * v309_a = (v237_p->a)->cache_age;
      int v310_a = v309_a[v379_a];
      int v311_a = v309_a[v353_a];
      int v409_a = v311_a + ((int)((unsigned int)(v311_a - v310_a) >> 31));
      v309_a[v353_a] = v409_a;
      int * v313_a = (v237_p->a)->cache_age;
      int v314_a = v313_a[v354_a];
      int v411_a = v314_a + ((int)((unsigned int)(v314_a - v310_a) >> 31));
      v313_a[v354_a] = v411_a;
      int * v316_a = (v237_p->a)->cache_age;
      v316_a[v379_a] = 0;
      v319_a = v379_a;
    }
    int * v320_a = (v237_p->a)->cache_vals;
    int v414_a = v319_a * 2;
    int v321_a = v320_a[v414_a];
    int v415_a = (v319_a * 2) + 1;
    int v322_a = v320_a[v415_a];
    int v416_a = (((((int)((unsigned int)((int)((unsigned int)(v241_a + 16) >> 2)) >> 1)) & 1) * 2) + ((((v261_a + ((~(((v263_a ^ -1) | (-(v263_a ^ -1))) >> 31)) & 2)) - (v264_a + ((~(((v265_a ^ -1) | (-(v265_a ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
    v320_a[v416_a] = v321_a;
    int * v324_a = (v237_p->a)->cache_vals;
    int v419_a = ((((((int)((unsigned int)((int)((unsigned int)(v241_a + 16) >> 2)) >> 1)) & 1) * 2) + ((((v261_a + ((~(((v263_a ^ -1) | (-(v263_a ^ -1))) >> 31)) & 2)) - (v264_a + ((~(((v265_a ^ -1) | (-(v265_a ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
    v324_a[v419_a] = v322_a;
    int * v326_a = (v237_p->a)->cache_tags;
    int v422_a = ((((int)((unsigned int)((int)((unsigned int)(v241_a + 16) >> 2)) >> 1)) & 1) * 2) + ((((v261_a + ((~(((v263_a ^ -1) | (-(v263_a ^ -1))) >> 31)) & 2)) - (v264_a + ((~(((v265_a ^ -1) | (-(v265_a ^ -1))) >> 31)) & 2))) >> 31) & 1);
    int v423_a = (int)((unsigned int)((int)((unsigned int)(v241_a + 16) >> 2)) >> 1);
    v326_a[v422_a] = v423_a;
    int * v328_a = (v237_p->a)->cache_dirty;
    v328_a[v422_a] = 0;
    int * v330_a = (v237_p->a)->cache_age;
    v330_a[v422_a] = 1;
    int * v332_a = (v237_p->a)->cache_age;
    int v333_a = v332_a[v422_a];
    int v334_a = v332_a[v351_a];
    int v429_a = v334_a + ((int)((unsigned int)(v334_a - v333_a) >> 31));
    v332_a[v351_a] = v429_a;
    int * v336_a = (v237_p->a)->cache_age;
    int v337_a = v336_a[v352_a];
    int v431_a = v337_a + ((int)((unsigned int)(v337_a - v333_a) >> 31));
    v336_a[v352_a] = v431_a;
    int * v339_a = (v237_p->a)->cache_age;
    v339_a[v422_a] = 0;
    v342_a = v422_a;
  }
  int v342_b;
  if (v356_b) {
    int * v250_b = (v237_p->b)->cache_age;
    int v358_b = ((((int)((unsigned int)((int)((unsigned int)(v241_b + 16) >> 2)) >> 1)) & 1) * 2) + ((~(((v244_b ^ ((int)((unsigned int)((int)((unsigned int)(v241_b + 16) >> 2)) >> 1))) | (-(v244_b ^ ((int)((unsigned int)((int)((unsigned int)(v241_b + 16) >> 2)) >> 1))))) >> 31)) & 1);
    int v251_b = v250_b[v358_b];
    int v252_b = v250_b[v351_b];
    int v359_b = v252_b + ((int)((unsigned int)(v252_b - v251_b) >> 31));
    v250_b[v351_b] = v359_b;
    int * v254_b = (v237_p->b)->cache_age;
    int v255_b = v254_b[v352_b];
    int v361_b = v255_b + ((int)((unsigned int)(v255_b - v251_b) >> 31));
    v254_b[v352_b] = v361_b;
    int * v257_b = (v237_p->b)->cache_age;
    v257_b[v358_b] = 0;
    v342_b = v358_b;
  } else {
    int * v260_b = (v237_p->b)->cache_age;
    int v365_b = (((int)((unsigned int)((int)((unsigned int)(v241_b + 16) >> 2)) >> 1)) & 1) * 2;
    int v261_b = v260_b[v365_b];
    int * v262_b = (v237_p->b)->cache_tags;
    int v263_b = v262_b[v365_b];
    int v264_b = v260_b[v352_b];
    int v265_b = v262_b[v352_b];
    bool v367_b = !(((~(((v245_b ^ ((int)((unsigned int)((int)((unsigned int)(v241_b + 16) >> 2)) >> 1))) | (-(v245_b ^ ((int)((unsigned int)((int)((unsigned int)(v241_b + 16) >> 2)) >> 1))))) >> 31)) | (~(((v246_b ^ ((int)((unsigned int)((int)((unsigned int)(v241_b + 16) >> 2)) >> 1))) | (-(v246_b ^ ((int)((unsigned int)((int)((unsigned int)(v241_b + 16) >> 2)) >> 1))))) >> 31))) == 0);
    int v319_b;
    if (v367_b) {
      int * v266_b = (v237_p->b)->cache_age;
      int v369_b = (4 + ((((int)((unsigned int)((int)((unsigned int)(v241_b + 16) >> 2)) >> 1)) & 3) * 2)) + ((~(((v246_b ^ ((int)((unsigned int)((int)((unsigned int)(v241_b + 16) >> 2)) >> 1))) | (-(v246_b ^ ((int)((unsigned int)((int)((unsigned int)(v241_b + 16) >> 2)) >> 1))))) >> 31)) & 1);
      int v267_b = v266_b[v369_b];
      int v268_b = v266_b[v353_b];
      int v370_b = v268_b + ((int)((unsigned int)(v268_b - v267_b) >> 31));
      v266_b[v353_b] = v370_b;
      int * v270_b = (v237_p->b)->cache_age;
      int v271_b = v270_b[v354_b];
      int v372_b = v271_b + ((int)((unsigned int)(v271_b - v267_b) >> 31));
      v270_b[v354_b] = v372_b;
      int * v273_b = (v237_p->b)->cache_age;
      v273_b[v369_b] = 0;
      v319_b = v369_b;
    } else {
      int * v276_b = (v237_p->b)->cache_age;
      int v376_b = 4 + ((((int)((unsigned int)((int)((unsigned int)(v241_b + 16) >> 2)) >> 1)) & 3) * 2);
      int v277_b = v276_b[v376_b];
      int * v278_b = (v237_p->b)->cache_tags;
      int v279_b = v278_b[v376_b];
      int v280_b = v276_b[v354_b];
      int v281_b = v278_b[v354_b];
      int * v282_b = (v237_p->b)->cache_dirty;
      int v379_b = (4 + ((((int)((unsigned int)((int)((unsigned int)(v241_b + 16) >> 2)) >> 1)) & 3) * 2)) + ((((v277_b + ((~(((v279_b ^ -1) | (-(v279_b ^ -1))) >> 31)) & 2)) - (v280_b + ((~(((v281_b ^ -1) | (-(v281_b ^ -1))) >> 31)) & 2))) >> 31) & 1);
      int v283_b = v282_b[v379_b];
      bool v380_b = !(v283_b == 0);
      if (v380_b) {
        int * v284_b = (v237_p->b)->cache_tags;
        int v285_b = v284_b[v379_b];
        int * v286_b = (v237_p->b)->cache_vals;
        int v383_b = ((4 + ((((int)((unsigned int)((int)((unsigned int)(v241_b + 16) >> 2)) >> 1)) & 3) * 2)) + ((((v277_b + ((~(((v279_b ^ -1) | (-(v279_b ^ -1))) >> 31)) & 2)) - (v280_b + ((~(((v281_b ^ -1) | (-(v281_b ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
        int v287_b = v286_b[v383_b];
        int v384_b = (((4 + ((((int)((unsigned int)((int)((unsigned int)(v241_b + 16) >> 2)) >> 1)) & 3) * 2)) + ((((v277_b + ((~(((v279_b ^ -1) | (-(v279_b ^ -1))) >> 31)) & 2)) - (v280_b + ((~(((v281_b ^ -1) | (-(v281_b ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
        int v288_b = v286_b[v384_b];
        int * v289_b = (v237_p->b)->mem;
        int v386_b = v285_b * 2;
        v289_b[v386_b] = v287_b;
        int * v291_b = (v237_p->b)->mem;
        int v389_b = (v285_b * 2) + 1;
        v291_b[v389_b] = v288_b;
        ;
      } else {
        ;
      }
      int * v296_b = (v237_p->b)->mem;
      int v394_b = ((int)((unsigned int)((int)((unsigned int)(v241_b + 16) >> 2)) >> 1)) * 2;
      int v297_b = v296_b[v394_b];
      int v395_b = (((int)((unsigned int)((int)((unsigned int)(v241_b + 16) >> 2)) >> 1)) * 2) + 1;
      int v298_b = v296_b[v395_b];
      int * v299_b = (v237_p->b)->cache_vals;
      int v397_b = ((4 + ((((int)((unsigned int)((int)((unsigned int)(v241_b + 16) >> 2)) >> 1)) & 3) * 2)) + ((((v277_b + ((~(((v279_b ^ -1) | (-(v279_b ^ -1))) >> 31)) & 2)) - (v280_b + ((~(((v281_b ^ -1) | (-(v281_b ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
      v299_b[v397_b] = v297_b;
      int * v301_b = (v237_p->b)->cache_vals;
      int v400_b = (((4 + ((((int)((unsigned int)((int)((unsigned int)(v241_b + 16) >> 2)) >> 1)) & 3) * 2)) + ((((v277_b + ((~(((v279_b ^ -1) | (-(v279_b ^ -1))) >> 31)) & 2)) - (v280_b + ((~(((v281_b ^ -1) | (-(v281_b ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
      v301_b[v400_b] = v298_b;
      int * v303_b = (v237_p->b)->cache_tags;
      int v403_b = (int)((unsigned int)((int)((unsigned int)(v241_b + 16) >> 2)) >> 1);
      v303_b[v379_b] = v403_b;
      int * v305_b = (v237_p->b)->cache_dirty;
      v305_b[v379_b] = 0;
      int * v307_b = (v237_p->b)->cache_age;
      v307_b[v379_b] = 1;
      int * v309_b = (v237_p->b)->cache_age;
      int v310_b = v309_b[v379_b];
      int v311_b = v309_b[v353_b];
      int v409_b = v311_b + ((int)((unsigned int)(v311_b - v310_b) >> 31));
      v309_b[v353_b] = v409_b;
      int * v313_b = (v237_p->b)->cache_age;
      int v314_b = v313_b[v354_b];
      int v411_b = v314_b + ((int)((unsigned int)(v314_b - v310_b) >> 31));
      v313_b[v354_b] = v411_b;
      int * v316_b = (v237_p->b)->cache_age;
      v316_b[v379_b] = 0;
      v319_b = v379_b;
    }
    int * v320_b = (v237_p->b)->cache_vals;
    int v414_b = v319_b * 2;
    int v321_b = v320_b[v414_b];
    int v415_b = (v319_b * 2) + 1;
    int v322_b = v320_b[v415_b];
    int v416_b = (((((int)((unsigned int)((int)((unsigned int)(v241_b + 16) >> 2)) >> 1)) & 1) * 2) + ((((v261_b + ((~(((v263_b ^ -1) | (-(v263_b ^ -1))) >> 31)) & 2)) - (v264_b + ((~(((v265_b ^ -1) | (-(v265_b ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
    v320_b[v416_b] = v321_b;
    int * v324_b = (v237_p->b)->cache_vals;
    int v419_b = ((((((int)((unsigned int)((int)((unsigned int)(v241_b + 16) >> 2)) >> 1)) & 1) * 2) + ((((v261_b + ((~(((v263_b ^ -1) | (-(v263_b ^ -1))) >> 31)) & 2)) - (v264_b + ((~(((v265_b ^ -1) | (-(v265_b ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
    v324_b[v419_b] = v322_b;
    int * v326_b = (v237_p->b)->cache_tags;
    int v422_b = ((((int)((unsigned int)((int)((unsigned int)(v241_b + 16) >> 2)) >> 1)) & 1) * 2) + ((((v261_b + ((~(((v263_b ^ -1) | (-(v263_b ^ -1))) >> 31)) & 2)) - (v264_b + ((~(((v265_b ^ -1) | (-(v265_b ^ -1))) >> 31)) & 2))) >> 31) & 1);
    int v423_b = (int)((unsigned int)((int)((unsigned int)(v241_b + 16) >> 2)) >> 1);
    v326_b[v422_b] = v423_b;
    int * v328_b = (v237_p->b)->cache_dirty;
    v328_b[v422_b] = 0;
    int * v330_b = (v237_p->b)->cache_age;
    v330_b[v422_b] = 1;
    int * v332_b = (v237_p->b)->cache_age;
    int v333_b = v332_b[v422_b];
    int v334_b = v332_b[v351_b];
    int v429_b = v334_b + ((int)((unsigned int)(v334_b - v333_b) >> 31));
    v332_b[v351_b] = v429_b;
    int * v336_b = (v237_p->b)->cache_age;
    int v337_b = v336_b[v352_b];
    int v431_b = v337_b + ((int)((unsigned int)(v337_b - v333_b) >> 31));
    v336_b[v352_b] = v431_b;
    int * v339_b = (v237_p->b)->cache_age;
    v339_b[v422_b] = 0;
    v342_b = v422_b;
  }
  int v434_a = (v342_a * 2) + (((int)((unsigned int)(v241_a + 16) >> 2)) & 1);
  int v434_b = (v342_b * 2) + (((int)((unsigned int)(v241_b + 16) >> 2)) & 1);
  int v343_a = v249_a[v434_a];
  int v343_b = v249_b[v434_b];
  int * v344_a = (v237_p->a)->regs;
  int * v344_b = (v237_p->b)->regs;
  v344_a[12] = v343_a;
  v344_b[12] = v343_b;
  return v237_p;
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
    s1.mem[SECRET_OFFSET+i] = secret(0, 20);
    s2.mem[SECRET_OFFSET+i] = secret(0, 20);
  }
  struct StateT2 p = { .a = &s1, .b = &s2 };
  struct StateT2 *p_ = snippet(&p);
  //@ assert untainted_timer: !\tainted(p_->a->timer==p_->b->timer);
  koika_assert(p_->a->timer==p_->b->timer, "timing leak");
  return 0;
}