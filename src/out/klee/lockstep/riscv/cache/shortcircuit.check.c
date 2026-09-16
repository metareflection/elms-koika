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
  int cache_tags[12];
  int cache_dirty[12];
  int cache_age[12];
  int cache_vals[24];
  int timer;
};

void lockstep_assert(bool);
void lockstep_assume(bool);

struct StateT2 * slot_12(struct StateT2 * v654_p);
struct StateT2 * slot_14(struct StateT2 * v78_p);
struct StateT2 * slot_6(struct StateT2 * v109_p);
struct StateT2 * slot_5(struct StateT2 * v88_p);
struct StateT2 * slot_2(struct StateT2 * v28_p);
struct StateT2 * slot_7(struct StateT2 * v359_p);
struct StateT2 * slot_3(struct StateT2 * v41_p);
struct StateT2 * snippet(struct StateT2 * v0_p);
struct StateT2 * slot_10(struct StateT2 * v667_p);
struct StateT2 * slot_1(struct StateT2 * v15_p);
struct StateT2 * slot_8(struct StateT2 * v380_p);
struct StateT2 * slot_4(struct StateT2 * v54_p);
struct StateT2 * slot_13(struct StateT2 * v683_p);
struct StateT2 * slot_9(struct StateT2 * v630_p);
struct StateT2 * slot_11(struct StateT2 * v688_p);
struct StateT2 * slot_0(struct StateT2 * v2_p);
struct StateT2 * slot_12(struct StateT2 * v654_p) {
  lockstep_assert(((v654_p->a)->timer) == ((v654_p->b)->timer));
  lockstep_assume(((v654_p->a)->timer) == ((v654_p->b)->timer));
  int v655_a = (v654_p->a)->timer;
  int v655_b = (v654_p->b)->timer;
  int v661_a = v655_a + 1;
  int v661_b = v655_b + 1;
  (v654_p->a)->timer = v661_a;
  (v654_p->b)->timer = v661_b;
  int * v657_a = (v654_p->a)->regs;
  int * v657_b = (v654_p->b)->regs;
  v657_a[10] = 0;
  v657_b[10] = 0;
  struct StateT2 * v659_p = slot_13(v654_p);
  return v659_p;
}

struct StateT2 * slot_14(struct StateT2 * v78_p) {
  lockstep_assert(((v78_p->a)->timer) == ((v78_p->b)->timer));
  lockstep_assume(((v78_p->a)->timer) == ((v78_p->b)->timer));
  int v79_a = (v78_p->a)->timer;
  int v79_b = (v78_p->b)->timer;
  int v84_a = v79_a + 1;
  int v84_b = v79_b + 1;
  (v78_p->a)->timer = v84_a;
  (v78_p->b)->timer = v84_b;
  int * v81_a = (v78_p->a)->regs;
  int * v81_b = (v78_p->b)->regs;
  v81_a[10] = 1;
  v81_b[10] = 1;
  return v78_p;
}

struct StateT2 * slot_6(struct StateT2 * v109_p) {
  lockstep_assert(((v109_p->a)->timer) == ((v109_p->b)->timer));
  lockstep_assume(((v109_p->a)->timer) == ((v109_p->b)->timer));
  int v110_a = (v109_p->a)->timer;
  int v110_b = (v109_p->b)->timer;
  int v243_a = v110_a + 1;
  int v243_b = v110_b + 1;
  (v109_p->a)->timer = v243_a;
  (v109_p->b)->timer = v243_b;
  int * v112_a = (v109_p->a)->regs;
  int * v112_b = (v109_p->b)->regs;
  int v113_a = v112_a[5];
  int v113_b = v112_b[5];
  int * v114_a = (v109_p->a)->cache_tags;
  int * v114_b = (v109_p->b)->cache_tags;
  int v247_a = (((int)((unsigned int)((int)((unsigned int)v113_a >> 2)) >> 1)) & 1) * 2;
  int v247_b = (((int)((unsigned int)((int)((unsigned int)v113_b >> 2)) >> 1)) & 1) * 2;
  int v115_a = v114_a[v247_a];
  int v115_b = v114_b[v247_b];
  int * v116_a = (v109_p->a)->cache_tags;
  int * v116_b = (v109_p->b)->cache_tags;
  int v249_a = ((((int)((unsigned int)((int)((unsigned int)v113_a >> 2)) >> 1)) & 1) * 2) + 1;
  int v249_b = ((((int)((unsigned int)((int)((unsigned int)v113_b >> 2)) >> 1)) & 1) * 2) + 1;
  int v117_a = v116_a[v249_a];
  int v117_b = v116_b[v249_b];
  int * v118_a = (v109_p->a)->cache_tags;
  int * v118_b = (v109_p->b)->cache_tags;
  int v251_a = 4 + ((((int)((unsigned int)((int)((unsigned int)v113_a >> 2)) >> 1)) & 3) * 2);
  int v251_b = 4 + ((((int)((unsigned int)((int)((unsigned int)v113_b >> 2)) >> 1)) & 3) * 2);
  int v119_a = v118_a[v251_a];
  int v119_b = v118_b[v251_b];
  int * v120_a = (v109_p->a)->cache_tags;
  int * v120_b = (v109_p->b)->cache_tags;
  int v253_a = (4 + ((((int)((unsigned int)((int)((unsigned int)v113_a >> 2)) >> 1)) & 3) * 2)) + 1;
  int v253_b = (4 + ((((int)((unsigned int)((int)((unsigned int)v113_b >> 2)) >> 1)) & 3) * 2)) + 1;
  int v121_a = v120_a[v253_a];
  int v121_b = v120_b[v253_b];
  int v122_a = (v109_p->a)->timer;
  int v122_b = (v109_p->b)->timer;
  int v254_a = v122_a + ((100 ^ (((~(((v119_a ^ ((int)((unsigned int)((int)((unsigned int)v113_a >> 2)) >> 1))) | (-(v119_a ^ ((int)((unsigned int)((int)((unsigned int)v113_a >> 2)) >> 1))))) >> 31)) | (~(((v121_a ^ ((int)((unsigned int)((int)((unsigned int)v113_a >> 2)) >> 1))) | (-(v121_a ^ ((int)((unsigned int)((int)((unsigned int)v113_a >> 2)) >> 1))))) >> 31))) & 104)) ^ (((~(((v115_a ^ ((int)((unsigned int)((int)((unsigned int)v113_a >> 2)) >> 1))) | (-(v115_a ^ ((int)((unsigned int)((int)((unsigned int)v113_a >> 2)) >> 1))))) >> 31)) | (~(((v117_a ^ ((int)((unsigned int)((int)((unsigned int)v113_a >> 2)) >> 1))) | (-(v117_a ^ ((int)((unsigned int)((int)((unsigned int)v113_a >> 2)) >> 1))))) >> 31))) & (1 ^ (100 ^ (((~(((v119_a ^ ((int)((unsigned int)((int)((unsigned int)v113_a >> 2)) >> 1))) | (-(v119_a ^ ((int)((unsigned int)((int)((unsigned int)v113_a >> 2)) >> 1))))) >> 31)) | (~(((v121_a ^ ((int)((unsigned int)((int)((unsigned int)v113_a >> 2)) >> 1))) | (-(v121_a ^ ((int)((unsigned int)((int)((unsigned int)v113_a >> 2)) >> 1))))) >> 31))) & 104)))));
  int v254_b = v122_b + ((100 ^ (((~(((v119_b ^ ((int)((unsigned int)((int)((unsigned int)v113_b >> 2)) >> 1))) | (-(v119_b ^ ((int)((unsigned int)((int)((unsigned int)v113_b >> 2)) >> 1))))) >> 31)) | (~(((v121_b ^ ((int)((unsigned int)((int)((unsigned int)v113_b >> 2)) >> 1))) | (-(v121_b ^ ((int)((unsigned int)((int)((unsigned int)v113_b >> 2)) >> 1))))) >> 31))) & 104)) ^ (((~(((v115_b ^ ((int)((unsigned int)((int)((unsigned int)v113_b >> 2)) >> 1))) | (-(v115_b ^ ((int)((unsigned int)((int)((unsigned int)v113_b >> 2)) >> 1))))) >> 31)) | (~(((v117_b ^ ((int)((unsigned int)((int)((unsigned int)v113_b >> 2)) >> 1))) | (-(v117_b ^ ((int)((unsigned int)((int)((unsigned int)v113_b >> 2)) >> 1))))) >> 31))) & (1 ^ (100 ^ (((~(((v119_b ^ ((int)((unsigned int)((int)((unsigned int)v113_b >> 2)) >> 1))) | (-(v119_b ^ ((int)((unsigned int)((int)((unsigned int)v113_b >> 2)) >> 1))))) >> 31)) | (~(((v121_b ^ ((int)((unsigned int)((int)((unsigned int)v113_b >> 2)) >> 1))) | (-(v121_b ^ ((int)((unsigned int)((int)((unsigned int)v113_b >> 2)) >> 1))))) >> 31))) & 104)))));
  (v109_p->a)->timer = v254_a;
  (v109_p->b)->timer = v254_b;
  int * v124_a = (v109_p->a)->cache_vals;
  int * v124_b = (v109_p->b)->cache_vals;
  bool v255_a = !(((~(((v115_a ^ ((int)((unsigned int)((int)((unsigned int)v113_a >> 2)) >> 1))) | (-(v115_a ^ ((int)((unsigned int)((int)((unsigned int)v113_a >> 2)) >> 1))))) >> 31)) | (~(((v117_a ^ ((int)((unsigned int)((int)((unsigned int)v113_a >> 2)) >> 1))) | (-(v117_a ^ ((int)((unsigned int)((int)((unsigned int)v113_a >> 2)) >> 1))))) >> 31))) == 0);
  bool v255_b = !(((~(((v115_b ^ ((int)((unsigned int)((int)((unsigned int)v113_b >> 2)) >> 1))) | (-(v115_b ^ ((int)((unsigned int)((int)((unsigned int)v113_b >> 2)) >> 1))))) >> 31)) | (~(((v117_b ^ ((int)((unsigned int)((int)((unsigned int)v113_b >> 2)) >> 1))) | (-(v117_b ^ ((int)((unsigned int)((int)((unsigned int)v113_b >> 2)) >> 1))))) >> 31))) == 0);
  int v237_a;
  if (v255_a) {
    int * v125_a = (v109_p->a)->cache_age;
    int v257_a = ((((int)((unsigned int)((int)((unsigned int)v113_a >> 2)) >> 1)) & 1) * 2) + ((~(((v117_a ^ ((int)((unsigned int)((int)((unsigned int)v113_a >> 2)) >> 1))) | (-(v117_a ^ ((int)((unsigned int)((int)((unsigned int)v113_a >> 2)) >> 1))))) >> 31)) & 1);
    int v126_a = v125_a[v257_a];
    int * v127_a = (v109_p->a)->cache_age;
    int v128_a = v127_a[v247_a];
    int * v129_a = (v109_p->a)->cache_age;
    int v260_a = v128_a + ((int)((unsigned int)(v128_a - v126_a) >> 31));
    v129_a[v247_a] = v260_a;
    int * v131_a = (v109_p->a)->cache_age;
    int v132_a = v131_a[v249_a];
    int * v133_a = (v109_p->a)->cache_age;
    int v263_a = v132_a + ((int)((unsigned int)(v132_a - v126_a) >> 31));
    v133_a[v249_a] = v263_a;
    int * v135_a = (v109_p->a)->cache_age;
    v135_a[v257_a] = 0;
    v237_a = v257_a;
  } else {
    int * v138_a = (v109_p->a)->cache_age;
    int v267_a = (((int)((unsigned int)((int)((unsigned int)v113_a >> 2)) >> 1)) & 1) * 2;
    int v139_a = v138_a[v267_a];
    int * v140_a = (v109_p->a)->cache_tags;
    int v141_a = v140_a[v267_a];
    int * v142_a = (v109_p->a)->cache_age;
    int v143_a = v142_a[v249_a];
    int * v144_a = (v109_p->a)->cache_tags;
    int v145_a = v144_a[v249_a];
    bool v271_a = !(((~(((v119_a ^ ((int)((unsigned int)((int)((unsigned int)v113_a >> 2)) >> 1))) | (-(v119_a ^ ((int)((unsigned int)((int)((unsigned int)v113_a >> 2)) >> 1))))) >> 31)) | (~(((v121_a ^ ((int)((unsigned int)((int)((unsigned int)v113_a >> 2)) >> 1))) | (-(v121_a ^ ((int)((unsigned int)((int)((unsigned int)v113_a >> 2)) >> 1))))) >> 31))) == 0);
    int v209_a;
    if (v271_a) {
      int * v146_a = (v109_p->a)->cache_age;
      int v273_a = (4 + ((((int)((unsigned int)((int)((unsigned int)v113_a >> 2)) >> 1)) & 3) * 2)) + ((~(((v121_a ^ ((int)((unsigned int)((int)((unsigned int)v113_a >> 2)) >> 1))) | (-(v121_a ^ ((int)((unsigned int)((int)((unsigned int)v113_a >> 2)) >> 1))))) >> 31)) & 1);
      int v147_a = v146_a[v273_a];
      int * v148_a = (v109_p->a)->cache_age;
      int v149_a = v148_a[v251_a];
      int * v150_a = (v109_p->a)->cache_age;
      int v276_a = v149_a + ((int)((unsigned int)(v149_a - v147_a) >> 31));
      v150_a[v251_a] = v276_a;
      int * v152_a = (v109_p->a)->cache_age;
      int v153_a = v152_a[v253_a];
      int * v154_a = (v109_p->a)->cache_age;
      int v279_a = v153_a + ((int)((unsigned int)(v153_a - v147_a) >> 31));
      v154_a[v253_a] = v279_a;
      int * v156_a = (v109_p->a)->cache_age;
      v156_a[v273_a] = 0;
      v209_a = v273_a;
    } else {
      int * v159_a = (v109_p->a)->cache_age;
      int v283_a = 4 + ((((int)((unsigned int)((int)((unsigned int)v113_a >> 2)) >> 1)) & 3) * 2);
      int v160_a = v159_a[v283_a];
      int * v161_a = (v109_p->a)->cache_tags;
      int v162_a = v161_a[v283_a];
      int * v163_a = (v109_p->a)->cache_age;
      int v164_a = v163_a[v253_a];
      int * v165_a = (v109_p->a)->cache_tags;
      int v166_a = v165_a[v253_a];
      int * v167_a = (v109_p->a)->cache_dirty;
      int v288_a = (4 + ((((int)((unsigned int)((int)((unsigned int)v113_a >> 2)) >> 1)) & 3) * 2)) + ((((v160_a + ((~(((v162_a ^ -1) | (-(v162_a ^ -1))) >> 31)) & 2)) - (v164_a + ((~(((v166_a ^ -1) | (-(v166_a ^ -1))) >> 31)) & 2))) >> 31) & 1);
      int v168_a = v167_a[v288_a];
      bool v289_a = !(v168_a == 0);
      if (v289_a) {
        int * v169_a = (v109_p->a)->cache_tags;
        int v170_a = v169_a[v288_a];
        int * v171_a = (v109_p->a)->cache_vals;
        int v292_a = ((4 + ((((int)((unsigned int)((int)((unsigned int)v113_a >> 2)) >> 1)) & 3) * 2)) + ((((v160_a + ((~(((v162_a ^ -1) | (-(v162_a ^ -1))) >> 31)) & 2)) - (v164_a + ((~(((v166_a ^ -1) | (-(v166_a ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
        int v172_a = v171_a[v292_a];
        int * v173_a = (v109_p->a)->cache_vals;
        int v294_a = (((4 + ((((int)((unsigned int)((int)((unsigned int)v113_a >> 2)) >> 1)) & 3) * 2)) + ((((v160_a + ((~(((v162_a ^ -1) | (-(v162_a ^ -1))) >> 31)) & 2)) - (v164_a + ((~(((v166_a ^ -1) | (-(v166_a ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
        int v174_a = v173_a[v294_a];
        int * v175_a = (v109_p->a)->mem;
        int v296_a = v170_a * 2;
        v175_a[v296_a] = v172_a;
        int * v177_a = (v109_p->a)->mem;
        int v299_a = (v170_a * 2) + 1;
        v177_a[v299_a] = v174_a;
        ;
      } else {
        ;
      }
      int * v182_a = (v109_p->a)->mem;
      int v304_a = ((int)((unsigned int)((int)((unsigned int)v113_a >> 2)) >> 1)) * 2;
      int v183_a = v182_a[v304_a];
      int * v184_a = (v109_p->a)->mem;
      int v306_a = (((int)((unsigned int)((int)((unsigned int)v113_a >> 2)) >> 1)) * 2) + 1;
      int v185_a = v184_a[v306_a];
      int * v186_a = (v109_p->a)->cache_vals;
      int v308_a = ((4 + ((((int)((unsigned int)((int)((unsigned int)v113_a >> 2)) >> 1)) & 3) * 2)) + ((((v160_a + ((~(((v162_a ^ -1) | (-(v162_a ^ -1))) >> 31)) & 2)) - (v164_a + ((~(((v166_a ^ -1) | (-(v166_a ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
      v186_a[v308_a] = v183_a;
      int * v188_a = (v109_p->a)->cache_vals;
      int v311_a = (((4 + ((((int)((unsigned int)((int)((unsigned int)v113_a >> 2)) >> 1)) & 3) * 2)) + ((((v160_a + ((~(((v162_a ^ -1) | (-(v162_a ^ -1))) >> 31)) & 2)) - (v164_a + ((~(((v166_a ^ -1) | (-(v166_a ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
      v188_a[v311_a] = v185_a;
      int * v190_a = (v109_p->a)->cache_tags;
      int v314_a = (int)((unsigned int)((int)((unsigned int)v113_a >> 2)) >> 1);
      v190_a[v288_a] = v314_a;
      int * v192_a = (v109_p->a)->cache_dirty;
      v192_a[v288_a] = 0;
      int * v194_a = (v109_p->a)->cache_age;
      v194_a[v288_a] = 1;
      int * v196_a = (v109_p->a)->cache_age;
      int v197_a = v196_a[v288_a];
      int * v198_a = (v109_p->a)->cache_age;
      int v199_a = v198_a[v251_a];
      int * v200_a = (v109_p->a)->cache_age;
      int v322_a = v199_a + ((int)((unsigned int)(v199_a - v197_a) >> 31));
      v200_a[v251_a] = v322_a;
      int * v202_a = (v109_p->a)->cache_age;
      int v203_a = v202_a[v253_a];
      int * v204_a = (v109_p->a)->cache_age;
      int v325_a = v203_a + ((int)((unsigned int)(v203_a - v197_a) >> 31));
      v204_a[v253_a] = v325_a;
      int * v206_a = (v109_p->a)->cache_age;
      v206_a[v288_a] = 0;
      v209_a = v288_a;
    }
    int * v210_a = (v109_p->a)->cache_vals;
    int v328_a = v209_a * 2;
    int v211_a = v210_a[v328_a];
    int * v212_a = (v109_p->a)->cache_vals;
    int v330_a = (v209_a * 2) + 1;
    int v213_a = v212_a[v330_a];
    int * v214_a = (v109_p->a)->cache_vals;
    int v332_a = (((((int)((unsigned int)((int)((unsigned int)v113_a >> 2)) >> 1)) & 1) * 2) + ((((v139_a + ((~(((v141_a ^ -1) | (-(v141_a ^ -1))) >> 31)) & 2)) - (v143_a + ((~(((v145_a ^ -1) | (-(v145_a ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
    v214_a[v332_a] = v211_a;
    int * v216_a = (v109_p->a)->cache_vals;
    int v335_a = ((((((int)((unsigned int)((int)((unsigned int)v113_a >> 2)) >> 1)) & 1) * 2) + ((((v139_a + ((~(((v141_a ^ -1) | (-(v141_a ^ -1))) >> 31)) & 2)) - (v143_a + ((~(((v145_a ^ -1) | (-(v145_a ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
    v216_a[v335_a] = v213_a;
    int * v218_a = (v109_p->a)->cache_tags;
    int v338_a = ((((int)((unsigned int)((int)((unsigned int)v113_a >> 2)) >> 1)) & 1) * 2) + ((((v139_a + ((~(((v141_a ^ -1) | (-(v141_a ^ -1))) >> 31)) & 2)) - (v143_a + ((~(((v145_a ^ -1) | (-(v145_a ^ -1))) >> 31)) & 2))) >> 31) & 1);
    int v339_a = (int)((unsigned int)((int)((unsigned int)v113_a >> 2)) >> 1);
    v218_a[v338_a] = v339_a;
    int * v220_a = (v109_p->a)->cache_dirty;
    v220_a[v338_a] = 0;
    int * v222_a = (v109_p->a)->cache_age;
    v222_a[v338_a] = 1;
    int * v224_a = (v109_p->a)->cache_age;
    int v225_a = v224_a[v338_a];
    int * v226_a = (v109_p->a)->cache_age;
    int v227_a = v226_a[v247_a];
    int * v228_a = (v109_p->a)->cache_age;
    int v347_a = v227_a + ((int)((unsigned int)(v227_a - v225_a) >> 31));
    v228_a[v247_a] = v347_a;
    int * v230_a = (v109_p->a)->cache_age;
    int v231_a = v230_a[v249_a];
    int * v232_a = (v109_p->a)->cache_age;
    int v350_a = v231_a + ((int)((unsigned int)(v231_a - v225_a) >> 31));
    v232_a[v249_a] = v350_a;
    int * v234_a = (v109_p->a)->cache_age;
    v234_a[v338_a] = 0;
    v237_a = v338_a;
  }
  int v237_b;
  if (v255_b) {
    int * v125_b = (v109_p->b)->cache_age;
    int v257_b = ((((int)((unsigned int)((int)((unsigned int)v113_b >> 2)) >> 1)) & 1) * 2) + ((~(((v117_b ^ ((int)((unsigned int)((int)((unsigned int)v113_b >> 2)) >> 1))) | (-(v117_b ^ ((int)((unsigned int)((int)((unsigned int)v113_b >> 2)) >> 1))))) >> 31)) & 1);
    int v126_b = v125_b[v257_b];
    int * v127_b = (v109_p->b)->cache_age;
    int v128_b = v127_b[v247_b];
    int * v129_b = (v109_p->b)->cache_age;
    int v260_b = v128_b + ((int)((unsigned int)(v128_b - v126_b) >> 31));
    v129_b[v247_b] = v260_b;
    int * v131_b = (v109_p->b)->cache_age;
    int v132_b = v131_b[v249_b];
    int * v133_b = (v109_p->b)->cache_age;
    int v263_b = v132_b + ((int)((unsigned int)(v132_b - v126_b) >> 31));
    v133_b[v249_b] = v263_b;
    int * v135_b = (v109_p->b)->cache_age;
    v135_b[v257_b] = 0;
    v237_b = v257_b;
  } else {
    int * v138_b = (v109_p->b)->cache_age;
    int v267_b = (((int)((unsigned int)((int)((unsigned int)v113_b >> 2)) >> 1)) & 1) * 2;
    int v139_b = v138_b[v267_b];
    int * v140_b = (v109_p->b)->cache_tags;
    int v141_b = v140_b[v267_b];
    int * v142_b = (v109_p->b)->cache_age;
    int v143_b = v142_b[v249_b];
    int * v144_b = (v109_p->b)->cache_tags;
    int v145_b = v144_b[v249_b];
    bool v271_b = !(((~(((v119_b ^ ((int)((unsigned int)((int)((unsigned int)v113_b >> 2)) >> 1))) | (-(v119_b ^ ((int)((unsigned int)((int)((unsigned int)v113_b >> 2)) >> 1))))) >> 31)) | (~(((v121_b ^ ((int)((unsigned int)((int)((unsigned int)v113_b >> 2)) >> 1))) | (-(v121_b ^ ((int)((unsigned int)((int)((unsigned int)v113_b >> 2)) >> 1))))) >> 31))) == 0);
    int v209_b;
    if (v271_b) {
      int * v146_b = (v109_p->b)->cache_age;
      int v273_b = (4 + ((((int)((unsigned int)((int)((unsigned int)v113_b >> 2)) >> 1)) & 3) * 2)) + ((~(((v121_b ^ ((int)((unsigned int)((int)((unsigned int)v113_b >> 2)) >> 1))) | (-(v121_b ^ ((int)((unsigned int)((int)((unsigned int)v113_b >> 2)) >> 1))))) >> 31)) & 1);
      int v147_b = v146_b[v273_b];
      int * v148_b = (v109_p->b)->cache_age;
      int v149_b = v148_b[v251_b];
      int * v150_b = (v109_p->b)->cache_age;
      int v276_b = v149_b + ((int)((unsigned int)(v149_b - v147_b) >> 31));
      v150_b[v251_b] = v276_b;
      int * v152_b = (v109_p->b)->cache_age;
      int v153_b = v152_b[v253_b];
      int * v154_b = (v109_p->b)->cache_age;
      int v279_b = v153_b + ((int)((unsigned int)(v153_b - v147_b) >> 31));
      v154_b[v253_b] = v279_b;
      int * v156_b = (v109_p->b)->cache_age;
      v156_b[v273_b] = 0;
      v209_b = v273_b;
    } else {
      int * v159_b = (v109_p->b)->cache_age;
      int v283_b = 4 + ((((int)((unsigned int)((int)((unsigned int)v113_b >> 2)) >> 1)) & 3) * 2);
      int v160_b = v159_b[v283_b];
      int * v161_b = (v109_p->b)->cache_tags;
      int v162_b = v161_b[v283_b];
      int * v163_b = (v109_p->b)->cache_age;
      int v164_b = v163_b[v253_b];
      int * v165_b = (v109_p->b)->cache_tags;
      int v166_b = v165_b[v253_b];
      int * v167_b = (v109_p->b)->cache_dirty;
      int v288_b = (4 + ((((int)((unsigned int)((int)((unsigned int)v113_b >> 2)) >> 1)) & 3) * 2)) + ((((v160_b + ((~(((v162_b ^ -1) | (-(v162_b ^ -1))) >> 31)) & 2)) - (v164_b + ((~(((v166_b ^ -1) | (-(v166_b ^ -1))) >> 31)) & 2))) >> 31) & 1);
      int v168_b = v167_b[v288_b];
      bool v289_b = !(v168_b == 0);
      if (v289_b) {
        int * v169_b = (v109_p->b)->cache_tags;
        int v170_b = v169_b[v288_b];
        int * v171_b = (v109_p->b)->cache_vals;
        int v292_b = ((4 + ((((int)((unsigned int)((int)((unsigned int)v113_b >> 2)) >> 1)) & 3) * 2)) + ((((v160_b + ((~(((v162_b ^ -1) | (-(v162_b ^ -1))) >> 31)) & 2)) - (v164_b + ((~(((v166_b ^ -1) | (-(v166_b ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
        int v172_b = v171_b[v292_b];
        int * v173_b = (v109_p->b)->cache_vals;
        int v294_b = (((4 + ((((int)((unsigned int)((int)((unsigned int)v113_b >> 2)) >> 1)) & 3) * 2)) + ((((v160_b + ((~(((v162_b ^ -1) | (-(v162_b ^ -1))) >> 31)) & 2)) - (v164_b + ((~(((v166_b ^ -1) | (-(v166_b ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
        int v174_b = v173_b[v294_b];
        int * v175_b = (v109_p->b)->mem;
        int v296_b = v170_b * 2;
        v175_b[v296_b] = v172_b;
        int * v177_b = (v109_p->b)->mem;
        int v299_b = (v170_b * 2) + 1;
        v177_b[v299_b] = v174_b;
        ;
      } else {
        ;
      }
      int * v182_b = (v109_p->b)->mem;
      int v304_b = ((int)((unsigned int)((int)((unsigned int)v113_b >> 2)) >> 1)) * 2;
      int v183_b = v182_b[v304_b];
      int * v184_b = (v109_p->b)->mem;
      int v306_b = (((int)((unsigned int)((int)((unsigned int)v113_b >> 2)) >> 1)) * 2) + 1;
      int v185_b = v184_b[v306_b];
      int * v186_b = (v109_p->b)->cache_vals;
      int v308_b = ((4 + ((((int)((unsigned int)((int)((unsigned int)v113_b >> 2)) >> 1)) & 3) * 2)) + ((((v160_b + ((~(((v162_b ^ -1) | (-(v162_b ^ -1))) >> 31)) & 2)) - (v164_b + ((~(((v166_b ^ -1) | (-(v166_b ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
      v186_b[v308_b] = v183_b;
      int * v188_b = (v109_p->b)->cache_vals;
      int v311_b = (((4 + ((((int)((unsigned int)((int)((unsigned int)v113_b >> 2)) >> 1)) & 3) * 2)) + ((((v160_b + ((~(((v162_b ^ -1) | (-(v162_b ^ -1))) >> 31)) & 2)) - (v164_b + ((~(((v166_b ^ -1) | (-(v166_b ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
      v188_b[v311_b] = v185_b;
      int * v190_b = (v109_p->b)->cache_tags;
      int v314_b = (int)((unsigned int)((int)((unsigned int)v113_b >> 2)) >> 1);
      v190_b[v288_b] = v314_b;
      int * v192_b = (v109_p->b)->cache_dirty;
      v192_b[v288_b] = 0;
      int * v194_b = (v109_p->b)->cache_age;
      v194_b[v288_b] = 1;
      int * v196_b = (v109_p->b)->cache_age;
      int v197_b = v196_b[v288_b];
      int * v198_b = (v109_p->b)->cache_age;
      int v199_b = v198_b[v251_b];
      int * v200_b = (v109_p->b)->cache_age;
      int v322_b = v199_b + ((int)((unsigned int)(v199_b - v197_b) >> 31));
      v200_b[v251_b] = v322_b;
      int * v202_b = (v109_p->b)->cache_age;
      int v203_b = v202_b[v253_b];
      int * v204_b = (v109_p->b)->cache_age;
      int v325_b = v203_b + ((int)((unsigned int)(v203_b - v197_b) >> 31));
      v204_b[v253_b] = v325_b;
      int * v206_b = (v109_p->b)->cache_age;
      v206_b[v288_b] = 0;
      v209_b = v288_b;
    }
    int * v210_b = (v109_p->b)->cache_vals;
    int v328_b = v209_b * 2;
    int v211_b = v210_b[v328_b];
    int * v212_b = (v109_p->b)->cache_vals;
    int v330_b = (v209_b * 2) + 1;
    int v213_b = v212_b[v330_b];
    int * v214_b = (v109_p->b)->cache_vals;
    int v332_b = (((((int)((unsigned int)((int)((unsigned int)v113_b >> 2)) >> 1)) & 1) * 2) + ((((v139_b + ((~(((v141_b ^ -1) | (-(v141_b ^ -1))) >> 31)) & 2)) - (v143_b + ((~(((v145_b ^ -1) | (-(v145_b ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
    v214_b[v332_b] = v211_b;
    int * v216_b = (v109_p->b)->cache_vals;
    int v335_b = ((((((int)((unsigned int)((int)((unsigned int)v113_b >> 2)) >> 1)) & 1) * 2) + ((((v139_b + ((~(((v141_b ^ -1) | (-(v141_b ^ -1))) >> 31)) & 2)) - (v143_b + ((~(((v145_b ^ -1) | (-(v145_b ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
    v216_b[v335_b] = v213_b;
    int * v218_b = (v109_p->b)->cache_tags;
    int v338_b = ((((int)((unsigned int)((int)((unsigned int)v113_b >> 2)) >> 1)) & 1) * 2) + ((((v139_b + ((~(((v141_b ^ -1) | (-(v141_b ^ -1))) >> 31)) & 2)) - (v143_b + ((~(((v145_b ^ -1) | (-(v145_b ^ -1))) >> 31)) & 2))) >> 31) & 1);
    int v339_b = (int)((unsigned int)((int)((unsigned int)v113_b >> 2)) >> 1);
    v218_b[v338_b] = v339_b;
    int * v220_b = (v109_p->b)->cache_dirty;
    v220_b[v338_b] = 0;
    int * v222_b = (v109_p->b)->cache_age;
    v222_b[v338_b] = 1;
    int * v224_b = (v109_p->b)->cache_age;
    int v225_b = v224_b[v338_b];
    int * v226_b = (v109_p->b)->cache_age;
    int v227_b = v226_b[v247_b];
    int * v228_b = (v109_p->b)->cache_age;
    int v347_b = v227_b + ((int)((unsigned int)(v227_b - v225_b) >> 31));
    v228_b[v247_b] = v347_b;
    int * v230_b = (v109_p->b)->cache_age;
    int v231_b = v230_b[v249_b];
    int * v232_b = (v109_p->b)->cache_age;
    int v350_b = v231_b + ((int)((unsigned int)(v231_b - v225_b) >> 31));
    v232_b[v249_b] = v350_b;
    int * v234_b = (v109_p->b)->cache_age;
    v234_b[v338_b] = 0;
    v237_b = v338_b;
  }
  int v353_a = (v237_a * 2) + (((int)((unsigned int)v113_a >> 2)) & 1);
  int v353_b = (v237_b * 2) + (((int)((unsigned int)v113_b >> 2)) & 1);
  int v238_a = v124_a[v353_a];
  int v238_b = v124_b[v353_b];
  int * v239_a = (v109_p->a)->regs;
  int * v239_b = (v109_p->b)->regs;
  v239_a[10] = v238_a;
  v239_b[10] = v238_b;
  struct StateT2 * v241_p = slot_7(v109_p);
  return v241_p;
}

struct StateT2 * slot_5(struct StateT2 * v88_p) {
  lockstep_assert(((v88_p->a)->timer) == ((v88_p->b)->timer));
  lockstep_assume(((v88_p->a)->timer) == ((v88_p->b)->timer));
  int v89_a = (v88_p->a)->timer;
  int v89_b = (v88_p->b)->timer;
  int v99_a = v89_a + 1;
  int v99_b = v89_b + 1;
  (v88_p->a)->timer = v99_a;
  (v88_p->b)->timer = v99_b;
  int * v91_a = (v88_p->a)->regs;
  int * v91_b = (v88_p->b)->regs;
  int v92_a = v91_a[12];
  int v92_b = v91_b[12];
  int * v93_a = (v88_p->a)->regs;
  int * v93_b = (v88_p->b)->regs;
  int v94_a = v93_a[14];
  int v94_b = v93_b[14];
  int * v95_a = (v88_p->a)->regs;
  int * v95_b = (v88_p->b)->regs;
  int v106_a = v92_a + v94_a;
  int v106_b = v92_b + v94_b;
  v95_a[5] = v106_a;
  v95_b[5] = v106_b;
  struct StateT2 * v97_p = slot_6(v88_p);
  return v97_p;
}

struct StateT2 * slot_2(struct StateT2 * v28_p) {
  lockstep_assert(((v28_p->a)->timer) == ((v28_p->b)->timer));
  lockstep_assume(((v28_p->a)->timer) == ((v28_p->b)->timer));
  int v29_a = (v28_p->a)->timer;
  int v29_b = (v28_p->b)->timer;
  int v35_a = v29_a + 1;
  int v35_b = v29_b + 1;
  (v28_p->a)->timer = v35_a;
  (v28_p->b)->timer = v35_b;
  int * v31_a = (v28_p->a)->regs;
  int * v31_b = (v28_p->b)->regs;
  v31_a[14] = 0;
  v31_b[14] = 0;
  struct StateT2 * v33_p = slot_3(v28_p);
  return v33_p;
}

struct StateT2 * slot_7(struct StateT2 * v359_p) {
  lockstep_assert(((v359_p->a)->timer) == ((v359_p->b)->timer));
  lockstep_assume(((v359_p->a)->timer) == ((v359_p->b)->timer));
  int v360_a = (v359_p->a)->timer;
  int v360_b = (v359_p->b)->timer;
  int v370_a = v360_a + 1;
  int v370_b = v360_b + 1;
  (v359_p->a)->timer = v370_a;
  (v359_p->b)->timer = v370_b;
  int * v362_a = (v359_p->a)->regs;
  int * v362_b = (v359_p->b)->regs;
  int v363_a = v362_a[13];
  int v363_b = v362_b[13];
  int * v364_a = (v359_p->a)->regs;
  int * v364_b = (v359_p->b)->regs;
  int v365_a = v364_a[14];
  int v365_b = v364_b[14];
  int * v366_a = (v359_p->a)->regs;
  int * v366_b = (v359_p->b)->regs;
  int v377_a = v363_a + v365_a;
  int v377_b = v363_b + v365_b;
  v366_a[6] = v377_a;
  v366_b[6] = v377_b;
  struct StateT2 * v368_p = slot_8(v359_p);
  return v368_p;
}

struct StateT2 * slot_3(struct StateT2 * v41_p) {
  lockstep_assert(((v41_p->a)->timer) == ((v41_p->b)->timer));
  lockstep_assume(((v41_p->a)->timer) == ((v41_p->b)->timer));
  int v42_a = (v41_p->a)->timer;
  int v42_b = (v41_p->b)->timer;
  int v48_a = v42_a + 1;
  int v48_b = v42_b + 1;
  (v41_p->a)->timer = v48_a;
  (v41_p->b)->timer = v48_b;
  int * v44_a = (v41_p->a)->regs;
  int * v44_b = (v41_p->b)->regs;
  v44_a[15] = 16;
  v44_b[15] = 16;
  struct StateT2 * v46_p = slot_4(v41_p);
  return v46_p;
}

struct StateT2 * snippet(struct StateT2 * v0_p) {
  lockstep_assert(((v0_p->a)->timer) == ((v0_p->b)->timer));
  lockstep_assume(((v0_p->a)->timer) == ((v0_p->b)->timer));
  struct StateT2 * v1_p = slot_0(v0_p);
  return v1_p;
}

struct StateT2 * slot_10(struct StateT2 * v667_p) {
  lockstep_assert(((v667_p->a)->timer) == ((v667_p->b)->timer));
  lockstep_assume(((v667_p->a)->timer) == ((v667_p->b)->timer));
  int v668_a = (v667_p->a)->timer;
  int v668_b = (v667_p->b)->timer;
  int v676_a = v668_a + 1;
  int v676_b = v668_b + 1;
  (v667_p->a)->timer = v676_a;
  (v667_p->b)->timer = v676_b;
  int * v670_a = (v667_p->a)->regs;
  int * v670_b = (v667_p->b)->regs;
  int v671_a = v670_a[14];
  int v671_b = v670_b[14];
  int * v672_a = (v667_p->a)->regs;
  int * v672_b = (v667_p->b)->regs;
  int v680_a = v671_a + 4;
  int v680_b = v671_b + 4;
  v672_a[14] = v680_a;
  v672_b[14] = v680_b;
  struct StateT2 * v674_p = slot_11(v667_p);
  return v674_p;
}

struct StateT2 * slot_1(struct StateT2 * v15_p) {
  lockstep_assert(((v15_p->a)->timer) == ((v15_p->b)->timer));
  lockstep_assume(((v15_p->a)->timer) == ((v15_p->b)->timer));
  int v16_a = (v15_p->a)->timer;
  int v16_b = (v15_p->b)->timer;
  int v22_a = v16_a + 1;
  int v22_b = v16_b + 1;
  (v15_p->a)->timer = v22_a;
  (v15_p->b)->timer = v22_b;
  int * v18_a = (v15_p->a)->regs;
  int * v18_b = (v15_p->b)->regs;
  v18_a[13] = 80;
  v18_b[13] = 80;
  struct StateT2 * v20_p = slot_2(v15_p);
  return v20_p;
}

struct StateT2 * slot_8(struct StateT2 * v380_p) {
  lockstep_assert(((v380_p->a)->timer) == ((v380_p->b)->timer));
  lockstep_assume(((v380_p->a)->timer) == ((v380_p->b)->timer));
  int v381_a = (v380_p->a)->timer;
  int v381_b = (v380_p->b)->timer;
  int v514_a = v381_a + 1;
  int v514_b = v381_b + 1;
  (v380_p->a)->timer = v514_a;
  (v380_p->b)->timer = v514_b;
  int * v383_a = (v380_p->a)->regs;
  int * v383_b = (v380_p->b)->regs;
  int v384_a = v383_a[6];
  int v384_b = v383_b[6];
  int * v385_a = (v380_p->a)->cache_tags;
  int * v385_b = (v380_p->b)->cache_tags;
  int v518_a = (((int)((unsigned int)((int)((unsigned int)v384_a >> 2)) >> 1)) & 1) * 2;
  int v518_b = (((int)((unsigned int)((int)((unsigned int)v384_b >> 2)) >> 1)) & 1) * 2;
  int v386_a = v385_a[v518_a];
  int v386_b = v385_b[v518_b];
  int * v387_a = (v380_p->a)->cache_tags;
  int * v387_b = (v380_p->b)->cache_tags;
  int v520_a = ((((int)((unsigned int)((int)((unsigned int)v384_a >> 2)) >> 1)) & 1) * 2) + 1;
  int v520_b = ((((int)((unsigned int)((int)((unsigned int)v384_b >> 2)) >> 1)) & 1) * 2) + 1;
  int v388_a = v387_a[v520_a];
  int v388_b = v387_b[v520_b];
  int * v389_a = (v380_p->a)->cache_tags;
  int * v389_b = (v380_p->b)->cache_tags;
  int v522_a = 4 + ((((int)((unsigned int)((int)((unsigned int)v384_a >> 2)) >> 1)) & 3) * 2);
  int v522_b = 4 + ((((int)((unsigned int)((int)((unsigned int)v384_b >> 2)) >> 1)) & 3) * 2);
  int v390_a = v389_a[v522_a];
  int v390_b = v389_b[v522_b];
  int * v391_a = (v380_p->a)->cache_tags;
  int * v391_b = (v380_p->b)->cache_tags;
  int v524_a = (4 + ((((int)((unsigned int)((int)((unsigned int)v384_a >> 2)) >> 1)) & 3) * 2)) + 1;
  int v524_b = (4 + ((((int)((unsigned int)((int)((unsigned int)v384_b >> 2)) >> 1)) & 3) * 2)) + 1;
  int v392_a = v391_a[v524_a];
  int v392_b = v391_b[v524_b];
  int v393_a = (v380_p->a)->timer;
  int v393_b = (v380_p->b)->timer;
  int v525_a = v393_a + ((100 ^ (((~(((v390_a ^ ((int)((unsigned int)((int)((unsigned int)v384_a >> 2)) >> 1))) | (-(v390_a ^ ((int)((unsigned int)((int)((unsigned int)v384_a >> 2)) >> 1))))) >> 31)) | (~(((v392_a ^ ((int)((unsigned int)((int)((unsigned int)v384_a >> 2)) >> 1))) | (-(v392_a ^ ((int)((unsigned int)((int)((unsigned int)v384_a >> 2)) >> 1))))) >> 31))) & 104)) ^ (((~(((v386_a ^ ((int)((unsigned int)((int)((unsigned int)v384_a >> 2)) >> 1))) | (-(v386_a ^ ((int)((unsigned int)((int)((unsigned int)v384_a >> 2)) >> 1))))) >> 31)) | (~(((v388_a ^ ((int)((unsigned int)((int)((unsigned int)v384_a >> 2)) >> 1))) | (-(v388_a ^ ((int)((unsigned int)((int)((unsigned int)v384_a >> 2)) >> 1))))) >> 31))) & (1 ^ (100 ^ (((~(((v390_a ^ ((int)((unsigned int)((int)((unsigned int)v384_a >> 2)) >> 1))) | (-(v390_a ^ ((int)((unsigned int)((int)((unsigned int)v384_a >> 2)) >> 1))))) >> 31)) | (~(((v392_a ^ ((int)((unsigned int)((int)((unsigned int)v384_a >> 2)) >> 1))) | (-(v392_a ^ ((int)((unsigned int)((int)((unsigned int)v384_a >> 2)) >> 1))))) >> 31))) & 104)))));
  int v525_b = v393_b + ((100 ^ (((~(((v390_b ^ ((int)((unsigned int)((int)((unsigned int)v384_b >> 2)) >> 1))) | (-(v390_b ^ ((int)((unsigned int)((int)((unsigned int)v384_b >> 2)) >> 1))))) >> 31)) | (~(((v392_b ^ ((int)((unsigned int)((int)((unsigned int)v384_b >> 2)) >> 1))) | (-(v392_b ^ ((int)((unsigned int)((int)((unsigned int)v384_b >> 2)) >> 1))))) >> 31))) & 104)) ^ (((~(((v386_b ^ ((int)((unsigned int)((int)((unsigned int)v384_b >> 2)) >> 1))) | (-(v386_b ^ ((int)((unsigned int)((int)((unsigned int)v384_b >> 2)) >> 1))))) >> 31)) | (~(((v388_b ^ ((int)((unsigned int)((int)((unsigned int)v384_b >> 2)) >> 1))) | (-(v388_b ^ ((int)((unsigned int)((int)((unsigned int)v384_b >> 2)) >> 1))))) >> 31))) & (1 ^ (100 ^ (((~(((v390_b ^ ((int)((unsigned int)((int)((unsigned int)v384_b >> 2)) >> 1))) | (-(v390_b ^ ((int)((unsigned int)((int)((unsigned int)v384_b >> 2)) >> 1))))) >> 31)) | (~(((v392_b ^ ((int)((unsigned int)((int)((unsigned int)v384_b >> 2)) >> 1))) | (-(v392_b ^ ((int)((unsigned int)((int)((unsigned int)v384_b >> 2)) >> 1))))) >> 31))) & 104)))));
  (v380_p->a)->timer = v525_a;
  (v380_p->b)->timer = v525_b;
  int * v395_a = (v380_p->a)->cache_vals;
  int * v395_b = (v380_p->b)->cache_vals;
  bool v526_a = !(((~(((v386_a ^ ((int)((unsigned int)((int)((unsigned int)v384_a >> 2)) >> 1))) | (-(v386_a ^ ((int)((unsigned int)((int)((unsigned int)v384_a >> 2)) >> 1))))) >> 31)) | (~(((v388_a ^ ((int)((unsigned int)((int)((unsigned int)v384_a >> 2)) >> 1))) | (-(v388_a ^ ((int)((unsigned int)((int)((unsigned int)v384_a >> 2)) >> 1))))) >> 31))) == 0);
  bool v526_b = !(((~(((v386_b ^ ((int)((unsigned int)((int)((unsigned int)v384_b >> 2)) >> 1))) | (-(v386_b ^ ((int)((unsigned int)((int)((unsigned int)v384_b >> 2)) >> 1))))) >> 31)) | (~(((v388_b ^ ((int)((unsigned int)((int)((unsigned int)v384_b >> 2)) >> 1))) | (-(v388_b ^ ((int)((unsigned int)((int)((unsigned int)v384_b >> 2)) >> 1))))) >> 31))) == 0);
  int v508_a;
  if (v526_a) {
    int * v396_a = (v380_p->a)->cache_age;
    int v528_a = ((((int)((unsigned int)((int)((unsigned int)v384_a >> 2)) >> 1)) & 1) * 2) + ((~(((v388_a ^ ((int)((unsigned int)((int)((unsigned int)v384_a >> 2)) >> 1))) | (-(v388_a ^ ((int)((unsigned int)((int)((unsigned int)v384_a >> 2)) >> 1))))) >> 31)) & 1);
    int v397_a = v396_a[v528_a];
    int * v398_a = (v380_p->a)->cache_age;
    int v399_a = v398_a[v518_a];
    int * v400_a = (v380_p->a)->cache_age;
    int v531_a = v399_a + ((int)((unsigned int)(v399_a - v397_a) >> 31));
    v400_a[v518_a] = v531_a;
    int * v402_a = (v380_p->a)->cache_age;
    int v403_a = v402_a[v520_a];
    int * v404_a = (v380_p->a)->cache_age;
    int v534_a = v403_a + ((int)((unsigned int)(v403_a - v397_a) >> 31));
    v404_a[v520_a] = v534_a;
    int * v406_a = (v380_p->a)->cache_age;
    v406_a[v528_a] = 0;
    v508_a = v528_a;
  } else {
    int * v409_a = (v380_p->a)->cache_age;
    int v538_a = (((int)((unsigned int)((int)((unsigned int)v384_a >> 2)) >> 1)) & 1) * 2;
    int v410_a = v409_a[v538_a];
    int * v411_a = (v380_p->a)->cache_tags;
    int v412_a = v411_a[v538_a];
    int * v413_a = (v380_p->a)->cache_age;
    int v414_a = v413_a[v520_a];
    int * v415_a = (v380_p->a)->cache_tags;
    int v416_a = v415_a[v520_a];
    bool v542_a = !(((~(((v390_a ^ ((int)((unsigned int)((int)((unsigned int)v384_a >> 2)) >> 1))) | (-(v390_a ^ ((int)((unsigned int)((int)((unsigned int)v384_a >> 2)) >> 1))))) >> 31)) | (~(((v392_a ^ ((int)((unsigned int)((int)((unsigned int)v384_a >> 2)) >> 1))) | (-(v392_a ^ ((int)((unsigned int)((int)((unsigned int)v384_a >> 2)) >> 1))))) >> 31))) == 0);
    int v480_a;
    if (v542_a) {
      int * v417_a = (v380_p->a)->cache_age;
      int v544_a = (4 + ((((int)((unsigned int)((int)((unsigned int)v384_a >> 2)) >> 1)) & 3) * 2)) + ((~(((v392_a ^ ((int)((unsigned int)((int)((unsigned int)v384_a >> 2)) >> 1))) | (-(v392_a ^ ((int)((unsigned int)((int)((unsigned int)v384_a >> 2)) >> 1))))) >> 31)) & 1);
      int v418_a = v417_a[v544_a];
      int * v419_a = (v380_p->a)->cache_age;
      int v420_a = v419_a[v522_a];
      int * v421_a = (v380_p->a)->cache_age;
      int v547_a = v420_a + ((int)((unsigned int)(v420_a - v418_a) >> 31));
      v421_a[v522_a] = v547_a;
      int * v423_a = (v380_p->a)->cache_age;
      int v424_a = v423_a[v524_a];
      int * v425_a = (v380_p->a)->cache_age;
      int v550_a = v424_a + ((int)((unsigned int)(v424_a - v418_a) >> 31));
      v425_a[v524_a] = v550_a;
      int * v427_a = (v380_p->a)->cache_age;
      v427_a[v544_a] = 0;
      v480_a = v544_a;
    } else {
      int * v430_a = (v380_p->a)->cache_age;
      int v554_a = 4 + ((((int)((unsigned int)((int)((unsigned int)v384_a >> 2)) >> 1)) & 3) * 2);
      int v431_a = v430_a[v554_a];
      int * v432_a = (v380_p->a)->cache_tags;
      int v433_a = v432_a[v554_a];
      int * v434_a = (v380_p->a)->cache_age;
      int v435_a = v434_a[v524_a];
      int * v436_a = (v380_p->a)->cache_tags;
      int v437_a = v436_a[v524_a];
      int * v438_a = (v380_p->a)->cache_dirty;
      int v559_a = (4 + ((((int)((unsigned int)((int)((unsigned int)v384_a >> 2)) >> 1)) & 3) * 2)) + ((((v431_a + ((~(((v433_a ^ -1) | (-(v433_a ^ -1))) >> 31)) & 2)) - (v435_a + ((~(((v437_a ^ -1) | (-(v437_a ^ -1))) >> 31)) & 2))) >> 31) & 1);
      int v439_a = v438_a[v559_a];
      bool v560_a = !(v439_a == 0);
      if (v560_a) {
        int * v440_a = (v380_p->a)->cache_tags;
        int v441_a = v440_a[v559_a];
        int * v442_a = (v380_p->a)->cache_vals;
        int v563_a = ((4 + ((((int)((unsigned int)((int)((unsigned int)v384_a >> 2)) >> 1)) & 3) * 2)) + ((((v431_a + ((~(((v433_a ^ -1) | (-(v433_a ^ -1))) >> 31)) & 2)) - (v435_a + ((~(((v437_a ^ -1) | (-(v437_a ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
        int v443_a = v442_a[v563_a];
        int * v444_a = (v380_p->a)->cache_vals;
        int v565_a = (((4 + ((((int)((unsigned int)((int)((unsigned int)v384_a >> 2)) >> 1)) & 3) * 2)) + ((((v431_a + ((~(((v433_a ^ -1) | (-(v433_a ^ -1))) >> 31)) & 2)) - (v435_a + ((~(((v437_a ^ -1) | (-(v437_a ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
        int v445_a = v444_a[v565_a];
        int * v446_a = (v380_p->a)->mem;
        int v567_a = v441_a * 2;
        v446_a[v567_a] = v443_a;
        int * v448_a = (v380_p->a)->mem;
        int v570_a = (v441_a * 2) + 1;
        v448_a[v570_a] = v445_a;
        ;
      } else {
        ;
      }
      int * v453_a = (v380_p->a)->mem;
      int v575_a = ((int)((unsigned int)((int)((unsigned int)v384_a >> 2)) >> 1)) * 2;
      int v454_a = v453_a[v575_a];
      int * v455_a = (v380_p->a)->mem;
      int v577_a = (((int)((unsigned int)((int)((unsigned int)v384_a >> 2)) >> 1)) * 2) + 1;
      int v456_a = v455_a[v577_a];
      int * v457_a = (v380_p->a)->cache_vals;
      int v579_a = ((4 + ((((int)((unsigned int)((int)((unsigned int)v384_a >> 2)) >> 1)) & 3) * 2)) + ((((v431_a + ((~(((v433_a ^ -1) | (-(v433_a ^ -1))) >> 31)) & 2)) - (v435_a + ((~(((v437_a ^ -1) | (-(v437_a ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
      v457_a[v579_a] = v454_a;
      int * v459_a = (v380_p->a)->cache_vals;
      int v582_a = (((4 + ((((int)((unsigned int)((int)((unsigned int)v384_a >> 2)) >> 1)) & 3) * 2)) + ((((v431_a + ((~(((v433_a ^ -1) | (-(v433_a ^ -1))) >> 31)) & 2)) - (v435_a + ((~(((v437_a ^ -1) | (-(v437_a ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
      v459_a[v582_a] = v456_a;
      int * v461_a = (v380_p->a)->cache_tags;
      int v585_a = (int)((unsigned int)((int)((unsigned int)v384_a >> 2)) >> 1);
      v461_a[v559_a] = v585_a;
      int * v463_a = (v380_p->a)->cache_dirty;
      v463_a[v559_a] = 0;
      int * v465_a = (v380_p->a)->cache_age;
      v465_a[v559_a] = 1;
      int * v467_a = (v380_p->a)->cache_age;
      int v468_a = v467_a[v559_a];
      int * v469_a = (v380_p->a)->cache_age;
      int v470_a = v469_a[v522_a];
      int * v471_a = (v380_p->a)->cache_age;
      int v593_a = v470_a + ((int)((unsigned int)(v470_a - v468_a) >> 31));
      v471_a[v522_a] = v593_a;
      int * v473_a = (v380_p->a)->cache_age;
      int v474_a = v473_a[v524_a];
      int * v475_a = (v380_p->a)->cache_age;
      int v596_a = v474_a + ((int)((unsigned int)(v474_a - v468_a) >> 31));
      v475_a[v524_a] = v596_a;
      int * v477_a = (v380_p->a)->cache_age;
      v477_a[v559_a] = 0;
      v480_a = v559_a;
    }
    int * v481_a = (v380_p->a)->cache_vals;
    int v599_a = v480_a * 2;
    int v482_a = v481_a[v599_a];
    int * v483_a = (v380_p->a)->cache_vals;
    int v601_a = (v480_a * 2) + 1;
    int v484_a = v483_a[v601_a];
    int * v485_a = (v380_p->a)->cache_vals;
    int v603_a = (((((int)((unsigned int)((int)((unsigned int)v384_a >> 2)) >> 1)) & 1) * 2) + ((((v410_a + ((~(((v412_a ^ -1) | (-(v412_a ^ -1))) >> 31)) & 2)) - (v414_a + ((~(((v416_a ^ -1) | (-(v416_a ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
    v485_a[v603_a] = v482_a;
    int * v487_a = (v380_p->a)->cache_vals;
    int v606_a = ((((((int)((unsigned int)((int)((unsigned int)v384_a >> 2)) >> 1)) & 1) * 2) + ((((v410_a + ((~(((v412_a ^ -1) | (-(v412_a ^ -1))) >> 31)) & 2)) - (v414_a + ((~(((v416_a ^ -1) | (-(v416_a ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
    v487_a[v606_a] = v484_a;
    int * v489_a = (v380_p->a)->cache_tags;
    int v609_a = ((((int)((unsigned int)((int)((unsigned int)v384_a >> 2)) >> 1)) & 1) * 2) + ((((v410_a + ((~(((v412_a ^ -1) | (-(v412_a ^ -1))) >> 31)) & 2)) - (v414_a + ((~(((v416_a ^ -1) | (-(v416_a ^ -1))) >> 31)) & 2))) >> 31) & 1);
    int v610_a = (int)((unsigned int)((int)((unsigned int)v384_a >> 2)) >> 1);
    v489_a[v609_a] = v610_a;
    int * v491_a = (v380_p->a)->cache_dirty;
    v491_a[v609_a] = 0;
    int * v493_a = (v380_p->a)->cache_age;
    v493_a[v609_a] = 1;
    int * v495_a = (v380_p->a)->cache_age;
    int v496_a = v495_a[v609_a];
    int * v497_a = (v380_p->a)->cache_age;
    int v498_a = v497_a[v518_a];
    int * v499_a = (v380_p->a)->cache_age;
    int v618_a = v498_a + ((int)((unsigned int)(v498_a - v496_a) >> 31));
    v499_a[v518_a] = v618_a;
    int * v501_a = (v380_p->a)->cache_age;
    int v502_a = v501_a[v520_a];
    int * v503_a = (v380_p->a)->cache_age;
    int v621_a = v502_a + ((int)((unsigned int)(v502_a - v496_a) >> 31));
    v503_a[v520_a] = v621_a;
    int * v505_a = (v380_p->a)->cache_age;
    v505_a[v609_a] = 0;
    v508_a = v609_a;
  }
  int v508_b;
  if (v526_b) {
    int * v396_b = (v380_p->b)->cache_age;
    int v528_b = ((((int)((unsigned int)((int)((unsigned int)v384_b >> 2)) >> 1)) & 1) * 2) + ((~(((v388_b ^ ((int)((unsigned int)((int)((unsigned int)v384_b >> 2)) >> 1))) | (-(v388_b ^ ((int)((unsigned int)((int)((unsigned int)v384_b >> 2)) >> 1))))) >> 31)) & 1);
    int v397_b = v396_b[v528_b];
    int * v398_b = (v380_p->b)->cache_age;
    int v399_b = v398_b[v518_b];
    int * v400_b = (v380_p->b)->cache_age;
    int v531_b = v399_b + ((int)((unsigned int)(v399_b - v397_b) >> 31));
    v400_b[v518_b] = v531_b;
    int * v402_b = (v380_p->b)->cache_age;
    int v403_b = v402_b[v520_b];
    int * v404_b = (v380_p->b)->cache_age;
    int v534_b = v403_b + ((int)((unsigned int)(v403_b - v397_b) >> 31));
    v404_b[v520_b] = v534_b;
    int * v406_b = (v380_p->b)->cache_age;
    v406_b[v528_b] = 0;
    v508_b = v528_b;
  } else {
    int * v409_b = (v380_p->b)->cache_age;
    int v538_b = (((int)((unsigned int)((int)((unsigned int)v384_b >> 2)) >> 1)) & 1) * 2;
    int v410_b = v409_b[v538_b];
    int * v411_b = (v380_p->b)->cache_tags;
    int v412_b = v411_b[v538_b];
    int * v413_b = (v380_p->b)->cache_age;
    int v414_b = v413_b[v520_b];
    int * v415_b = (v380_p->b)->cache_tags;
    int v416_b = v415_b[v520_b];
    bool v542_b = !(((~(((v390_b ^ ((int)((unsigned int)((int)((unsigned int)v384_b >> 2)) >> 1))) | (-(v390_b ^ ((int)((unsigned int)((int)((unsigned int)v384_b >> 2)) >> 1))))) >> 31)) | (~(((v392_b ^ ((int)((unsigned int)((int)((unsigned int)v384_b >> 2)) >> 1))) | (-(v392_b ^ ((int)((unsigned int)((int)((unsigned int)v384_b >> 2)) >> 1))))) >> 31))) == 0);
    int v480_b;
    if (v542_b) {
      int * v417_b = (v380_p->b)->cache_age;
      int v544_b = (4 + ((((int)((unsigned int)((int)((unsigned int)v384_b >> 2)) >> 1)) & 3) * 2)) + ((~(((v392_b ^ ((int)((unsigned int)((int)((unsigned int)v384_b >> 2)) >> 1))) | (-(v392_b ^ ((int)((unsigned int)((int)((unsigned int)v384_b >> 2)) >> 1))))) >> 31)) & 1);
      int v418_b = v417_b[v544_b];
      int * v419_b = (v380_p->b)->cache_age;
      int v420_b = v419_b[v522_b];
      int * v421_b = (v380_p->b)->cache_age;
      int v547_b = v420_b + ((int)((unsigned int)(v420_b - v418_b) >> 31));
      v421_b[v522_b] = v547_b;
      int * v423_b = (v380_p->b)->cache_age;
      int v424_b = v423_b[v524_b];
      int * v425_b = (v380_p->b)->cache_age;
      int v550_b = v424_b + ((int)((unsigned int)(v424_b - v418_b) >> 31));
      v425_b[v524_b] = v550_b;
      int * v427_b = (v380_p->b)->cache_age;
      v427_b[v544_b] = 0;
      v480_b = v544_b;
    } else {
      int * v430_b = (v380_p->b)->cache_age;
      int v554_b = 4 + ((((int)((unsigned int)((int)((unsigned int)v384_b >> 2)) >> 1)) & 3) * 2);
      int v431_b = v430_b[v554_b];
      int * v432_b = (v380_p->b)->cache_tags;
      int v433_b = v432_b[v554_b];
      int * v434_b = (v380_p->b)->cache_age;
      int v435_b = v434_b[v524_b];
      int * v436_b = (v380_p->b)->cache_tags;
      int v437_b = v436_b[v524_b];
      int * v438_b = (v380_p->b)->cache_dirty;
      int v559_b = (4 + ((((int)((unsigned int)((int)((unsigned int)v384_b >> 2)) >> 1)) & 3) * 2)) + ((((v431_b + ((~(((v433_b ^ -1) | (-(v433_b ^ -1))) >> 31)) & 2)) - (v435_b + ((~(((v437_b ^ -1) | (-(v437_b ^ -1))) >> 31)) & 2))) >> 31) & 1);
      int v439_b = v438_b[v559_b];
      bool v560_b = !(v439_b == 0);
      if (v560_b) {
        int * v440_b = (v380_p->b)->cache_tags;
        int v441_b = v440_b[v559_b];
        int * v442_b = (v380_p->b)->cache_vals;
        int v563_b = ((4 + ((((int)((unsigned int)((int)((unsigned int)v384_b >> 2)) >> 1)) & 3) * 2)) + ((((v431_b + ((~(((v433_b ^ -1) | (-(v433_b ^ -1))) >> 31)) & 2)) - (v435_b + ((~(((v437_b ^ -1) | (-(v437_b ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
        int v443_b = v442_b[v563_b];
        int * v444_b = (v380_p->b)->cache_vals;
        int v565_b = (((4 + ((((int)((unsigned int)((int)((unsigned int)v384_b >> 2)) >> 1)) & 3) * 2)) + ((((v431_b + ((~(((v433_b ^ -1) | (-(v433_b ^ -1))) >> 31)) & 2)) - (v435_b + ((~(((v437_b ^ -1) | (-(v437_b ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
        int v445_b = v444_b[v565_b];
        int * v446_b = (v380_p->b)->mem;
        int v567_b = v441_b * 2;
        v446_b[v567_b] = v443_b;
        int * v448_b = (v380_p->b)->mem;
        int v570_b = (v441_b * 2) + 1;
        v448_b[v570_b] = v445_b;
        ;
      } else {
        ;
      }
      int * v453_b = (v380_p->b)->mem;
      int v575_b = ((int)((unsigned int)((int)((unsigned int)v384_b >> 2)) >> 1)) * 2;
      int v454_b = v453_b[v575_b];
      int * v455_b = (v380_p->b)->mem;
      int v577_b = (((int)((unsigned int)((int)((unsigned int)v384_b >> 2)) >> 1)) * 2) + 1;
      int v456_b = v455_b[v577_b];
      int * v457_b = (v380_p->b)->cache_vals;
      int v579_b = ((4 + ((((int)((unsigned int)((int)((unsigned int)v384_b >> 2)) >> 1)) & 3) * 2)) + ((((v431_b + ((~(((v433_b ^ -1) | (-(v433_b ^ -1))) >> 31)) & 2)) - (v435_b + ((~(((v437_b ^ -1) | (-(v437_b ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
      v457_b[v579_b] = v454_b;
      int * v459_b = (v380_p->b)->cache_vals;
      int v582_b = (((4 + ((((int)((unsigned int)((int)((unsigned int)v384_b >> 2)) >> 1)) & 3) * 2)) + ((((v431_b + ((~(((v433_b ^ -1) | (-(v433_b ^ -1))) >> 31)) & 2)) - (v435_b + ((~(((v437_b ^ -1) | (-(v437_b ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
      v459_b[v582_b] = v456_b;
      int * v461_b = (v380_p->b)->cache_tags;
      int v585_b = (int)((unsigned int)((int)((unsigned int)v384_b >> 2)) >> 1);
      v461_b[v559_b] = v585_b;
      int * v463_b = (v380_p->b)->cache_dirty;
      v463_b[v559_b] = 0;
      int * v465_b = (v380_p->b)->cache_age;
      v465_b[v559_b] = 1;
      int * v467_b = (v380_p->b)->cache_age;
      int v468_b = v467_b[v559_b];
      int * v469_b = (v380_p->b)->cache_age;
      int v470_b = v469_b[v522_b];
      int * v471_b = (v380_p->b)->cache_age;
      int v593_b = v470_b + ((int)((unsigned int)(v470_b - v468_b) >> 31));
      v471_b[v522_b] = v593_b;
      int * v473_b = (v380_p->b)->cache_age;
      int v474_b = v473_b[v524_b];
      int * v475_b = (v380_p->b)->cache_age;
      int v596_b = v474_b + ((int)((unsigned int)(v474_b - v468_b) >> 31));
      v475_b[v524_b] = v596_b;
      int * v477_b = (v380_p->b)->cache_age;
      v477_b[v559_b] = 0;
      v480_b = v559_b;
    }
    int * v481_b = (v380_p->b)->cache_vals;
    int v599_b = v480_b * 2;
    int v482_b = v481_b[v599_b];
    int * v483_b = (v380_p->b)->cache_vals;
    int v601_b = (v480_b * 2) + 1;
    int v484_b = v483_b[v601_b];
    int * v485_b = (v380_p->b)->cache_vals;
    int v603_b = (((((int)((unsigned int)((int)((unsigned int)v384_b >> 2)) >> 1)) & 1) * 2) + ((((v410_b + ((~(((v412_b ^ -1) | (-(v412_b ^ -1))) >> 31)) & 2)) - (v414_b + ((~(((v416_b ^ -1) | (-(v416_b ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
    v485_b[v603_b] = v482_b;
    int * v487_b = (v380_p->b)->cache_vals;
    int v606_b = ((((((int)((unsigned int)((int)((unsigned int)v384_b >> 2)) >> 1)) & 1) * 2) + ((((v410_b + ((~(((v412_b ^ -1) | (-(v412_b ^ -1))) >> 31)) & 2)) - (v414_b + ((~(((v416_b ^ -1) | (-(v416_b ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
    v487_b[v606_b] = v484_b;
    int * v489_b = (v380_p->b)->cache_tags;
    int v609_b = ((((int)((unsigned int)((int)((unsigned int)v384_b >> 2)) >> 1)) & 1) * 2) + ((((v410_b + ((~(((v412_b ^ -1) | (-(v412_b ^ -1))) >> 31)) & 2)) - (v414_b + ((~(((v416_b ^ -1) | (-(v416_b ^ -1))) >> 31)) & 2))) >> 31) & 1);
    int v610_b = (int)((unsigned int)((int)((unsigned int)v384_b >> 2)) >> 1);
    v489_b[v609_b] = v610_b;
    int * v491_b = (v380_p->b)->cache_dirty;
    v491_b[v609_b] = 0;
    int * v493_b = (v380_p->b)->cache_age;
    v493_b[v609_b] = 1;
    int * v495_b = (v380_p->b)->cache_age;
    int v496_b = v495_b[v609_b];
    int * v497_b = (v380_p->b)->cache_age;
    int v498_b = v497_b[v518_b];
    int * v499_b = (v380_p->b)->cache_age;
    int v618_b = v498_b + ((int)((unsigned int)(v498_b - v496_b) >> 31));
    v499_b[v518_b] = v618_b;
    int * v501_b = (v380_p->b)->cache_age;
    int v502_b = v501_b[v520_b];
    int * v503_b = (v380_p->b)->cache_age;
    int v621_b = v502_b + ((int)((unsigned int)(v502_b - v496_b) >> 31));
    v503_b[v520_b] = v621_b;
    int * v505_b = (v380_p->b)->cache_age;
    v505_b[v609_b] = 0;
    v508_b = v609_b;
  }
  int v624_a = (v508_a * 2) + (((int)((unsigned int)v384_a >> 2)) & 1);
  int v624_b = (v508_b * 2) + (((int)((unsigned int)v384_b >> 2)) & 1);
  int v509_a = v395_a[v624_a];
  int v509_b = v395_b[v624_b];
  int * v510_a = (v380_p->a)->regs;
  int * v510_b = (v380_p->b)->regs;
  v510_a[11] = v509_a;
  v510_b[11] = v509_b;
  struct StateT2 * v512_p = slot_9(v380_p);
  return v512_p;
}

struct StateT2 * slot_4(struct StateT2 * v54_p) {
  lockstep_assert(((v54_p->a)->timer) == ((v54_p->b)->timer));
  lockstep_assume(((v54_p->a)->timer) == ((v54_p->b)->timer));
  int v55_a = (v54_p->a)->timer;
  int v55_b = (v54_p->b)->timer;
  int v67_a = v55_a + 1;
  int v67_b = v55_b + 1;
  (v54_p->a)->timer = v67_a;
  (v54_p->b)->timer = v67_b;
  int * v57_a = (v54_p->a)->regs;
  int * v57_b = (v54_p->b)->regs;
  int v58_a = v57_a[14];
  int v58_b = v57_b[14];
  int * v59_a = (v54_p->a)->regs;
  int * v59_b = (v54_p->b)->regs;
  int v60_a = v59_a[15];
  int v60_b = v59_b[15];
  bool v72_a = v58_a >= v60_a;
  bool v72_b = v58_b >= v60_b;
  lockstep_assert(v72_a == v72_b);
  lockstep_assume(v72_a == v72_b);
  struct StateT2 * v65_p;
  if (v72_a) {
    struct StateT2 * v61_p = slot_14(v54_p);
    v65_p = v61_p;
  } else {
    struct StateT2 * v63_p = slot_5(v54_p);
    v65_p = v63_p;
  }
  return v65_p;
}

struct StateT2 * slot_13(struct StateT2 * v683_p) {
  lockstep_assert(((v683_p->a)->timer) == ((v683_p->b)->timer));
  lockstep_assume(((v683_p->a)->timer) == ((v683_p->b)->timer));
  int v684_a = (v683_p->a)->timer;
  int v684_b = (v683_p->b)->timer;
  int v687_a = v684_a + 1;
  int v687_b = v684_b + 1;
  (v683_p->a)->timer = v687_a;
  (v683_p->b)->timer = v687_b;
  return v683_p;
}

struct StateT2 * slot_9(struct StateT2 * v630_p) {
  lockstep_assert(((v630_p->a)->timer) == ((v630_p->b)->timer));
  lockstep_assume(((v630_p->a)->timer) == ((v630_p->b)->timer));
  int v631_a = (v630_p->a)->timer;
  int v631_b = (v630_p->b)->timer;
  int v643_a = v631_a + 1;
  int v643_b = v631_b + 1;
  (v630_p->a)->timer = v643_a;
  (v630_p->b)->timer = v643_b;
  int * v633_a = (v630_p->a)->regs;
  int * v633_b = (v630_p->b)->regs;
  int v634_a = v633_a[10];
  int v634_b = v633_b[10];
  int * v635_a = (v630_p->a)->regs;
  int * v635_b = (v630_p->b)->regs;
  int v636_a = v635_a[11];
  int v636_b = v635_b[11];
  bool v648_a = !(v634_a == v636_a);
  bool v648_b = !(v634_b == v636_b);
  lockstep_assert(v648_a == v648_b);
  lockstep_assume(v648_a == v648_b);
  struct StateT2 * v641_p;
  if (v648_a) {
    struct StateT2 * v637_p = slot_12(v630_p);
    v641_p = v637_p;
  } else {
    struct StateT2 * v639_p = slot_10(v630_p);
    v641_p = v639_p;
  }
  return v641_p;
}

struct StateT2 * slot_11(struct StateT2 * v688_p) {
  lockstep_assert(((v688_p->a)->timer) == ((v688_p->b)->timer));
  lockstep_assume(((v688_p->a)->timer) == ((v688_p->b)->timer));
  int v689_a = (v688_p->a)->timer;
  int v689_b = (v688_p->b)->timer;
  int v693_a = v689_a + 1;
  int v693_b = v689_b + 1;
  (v688_p->a)->timer = v693_a;
  (v688_p->b)->timer = v693_b;
  struct StateT2 * v691_p = slot_4(v688_p);
  return v691_p;
}

struct StateT2 * slot_0(struct StateT2 * v2_p) {
  lockstep_assert(((v2_p->a)->timer) == ((v2_p->b)->timer));
  lockstep_assume(((v2_p->a)->timer) == ((v2_p->b)->timer));
  int v3_a = (v2_p->a)->timer;
  int v3_b = (v2_p->b)->timer;
  int v9_a = v3_a + 1;
  int v9_b = v3_b + 1;
  (v2_p->a)->timer = v9_a;
  (v2_p->b)->timer = v9_b;
  int * v5_a = (v2_p->a)->regs;
  int * v5_b = (v2_p->b)->regs;
  v5_a[12] = 0;
  v5_b[12] = 0;
  struct StateT2 * v7_p = slot_1(v2_p);
  return v7_p;
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