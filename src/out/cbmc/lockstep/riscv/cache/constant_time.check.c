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

struct StateT2 * slot_12(struct StateT2 * v694_p);
struct StateT2 * slot_14(struct StateT2 * v91_p);
struct StateT2 * slot_6(struct StateT2 * v111_p);
struct StateT2 * slot_5(struct StateT2 * v67_p);
struct StateT2 * slot_2(struct StateT2 * v28_p);
struct StateT2 * slot_7(struct StateT2 * v132_p);
struct StateT2 * slot_3(struct StateT2 * v41_p);
struct StateT2 * snippet(struct StateT2 * v0_p);
struct StateT2 * slot_10(struct StateT2 * v653_p);
struct StateT2 * slot_1(struct StateT2 * v15_p);
struct StateT2 * slot_8(struct StateT2 * v382_p);
struct StateT2 * slot_4(struct StateT2 * v54_p);
struct StateT2 * slot_13(struct StateT2 * v710_p);
struct StateT2 * slot_9(struct StateT2 * v403_p);
struct StateT2 * slot_11(struct StateT2 * v674_p);
struct StateT2 * slot_0(struct StateT2 * v2_p);
struct StateT2 * slot_12(struct StateT2 * v694_p) {
  lockstep_assert(((v694_p->a)->timer) == ((v694_p->b)->timer));
  lockstep_assume(((v694_p->a)->timer) == ((v694_p->b)->timer));
  int v695_a = (v694_p->a)->timer;
  int v695_b = (v694_p->b)->timer;
  int v703_a = v695_a + 1;
  int v703_b = v695_b + 1;
  (v694_p->a)->timer = v703_a;
  (v694_p->b)->timer = v703_b;
  int * v697_a = (v694_p->a)->regs;
  int * v697_b = (v694_p->b)->regs;
  int v698_a = v697_a[14];
  int v698_b = v697_b[14];
  int * v699_a = (v694_p->a)->regs;
  int * v699_b = (v694_p->b)->regs;
  int v707_a = v698_a + 4;
  int v707_b = v698_b + 4;
  v699_a[14] = v707_a;
  v699_b[14] = v707_b;
  struct StateT2 * v701_p = slot_13(v694_p);
  return v701_p;
}

struct StateT2 * slot_14(struct StateT2 * v91_p) {
  lockstep_assert(((v91_p->a)->timer) == ((v91_p->b)->timer));
  lockstep_assume(((v91_p->a)->timer) == ((v91_p->b)->timer));
  int v92_a = (v91_p->a)->timer;
  int v92_b = (v91_p->b)->timer;
  int v102_a = v92_a + 1;
  int v102_b = v92_b + 1;
  (v91_p->a)->timer = v102_a;
  (v91_p->b)->timer = v102_b;
  int * v94_a = (v91_p->a)->regs;
  int * v94_b = (v91_p->b)->regs;
  int v95_a = v94_a[5];
  int v95_b = v94_b[5];
  bool v105_a = (v95_a ^ -2147483648) < -2147483647;
  bool v105_b = (v95_b ^ -2147483648) < -2147483647;
  int v98_a;
  if (v105_a) {
    v98_a = 1;
  } else {
    v98_a = 0;
  }
  int v98_b;
  if (v105_b) {
    v98_b = 1;
  } else {
    v98_b = 0;
  }
  int * v99_a = (v91_p->a)->regs;
  int * v99_b = (v91_p->b)->regs;
  v99_a[11] = v98_a;
  v99_b[11] = v98_b;
  return v91_p;
}

struct StateT2 * slot_6(struct StateT2 * v111_p) {
  lockstep_assert(((v111_p->a)->timer) == ((v111_p->b)->timer));
  lockstep_assume(((v111_p->a)->timer) == ((v111_p->b)->timer));
  int v112_a = (v111_p->a)->timer;
  int v112_b = (v111_p->b)->timer;
  int v122_a = v112_a + 1;
  int v122_b = v112_b + 1;
  (v111_p->a)->timer = v122_a;
  (v111_p->b)->timer = v122_b;
  int * v114_a = (v111_p->a)->regs;
  int * v114_b = (v111_p->b)->regs;
  int v115_a = v114_a[12];
  int v115_b = v114_b[12];
  int * v116_a = (v111_p->a)->regs;
  int * v116_b = (v111_p->b)->regs;
  int v117_a = v116_a[14];
  int v117_b = v116_b[14];
  int * v118_a = (v111_p->a)->regs;
  int * v118_b = (v111_p->b)->regs;
  int v129_a = v115_a + v117_a;
  int v129_b = v115_b + v117_b;
  v118_a[6] = v129_a;
  v118_b[6] = v129_b;
  struct StateT2 * v120_p = slot_7(v111_p);
  return v120_p;
}

struct StateT2 * slot_5(struct StateT2 * v67_p) {
  lockstep_assert(((v67_p->a)->timer) == ((v67_p->b)->timer));
  lockstep_assume(((v67_p->a)->timer) == ((v67_p->b)->timer));
  int v68_a = (v67_p->a)->timer;
  int v68_b = (v67_p->b)->timer;
  int v80_a = v68_a + 1;
  int v80_b = v68_b + 1;
  (v67_p->a)->timer = v80_a;
  (v67_p->b)->timer = v80_b;
  int * v70_a = (v67_p->a)->regs;
  int * v70_b = (v67_p->b)->regs;
  int v71_a = v70_a[14];
  int v71_b = v70_b[14];
  int * v72_a = (v67_p->a)->regs;
  int * v72_b = (v67_p->b)->regs;
  int v73_a = v72_a[15];
  int v73_b = v72_b[15];
  bool v85_a = v71_a >= v73_a;
  bool v85_b = v71_b >= v73_b;
  lockstep_assert(v85_a == v85_b);
  lockstep_assume(v85_a == v85_b);
  struct StateT2 * v78_p;
  if (v85_a) {
    struct StateT2 * v74_p = slot_14(v67_p);
    v78_p = v74_p;
  } else {
    struct StateT2 * v76_p = slot_6(v67_p);
    v78_p = v76_p;
  }
  return v78_p;
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

struct StateT2 * slot_7(struct StateT2 * v132_p) {
  lockstep_assert(((v132_p->a)->timer) == ((v132_p->b)->timer));
  lockstep_assume(((v132_p->a)->timer) == ((v132_p->b)->timer));
  int v133_a = (v132_p->a)->timer;
  int v133_b = (v132_p->b)->timer;
  int v266_a = v133_a + 1;
  int v266_b = v133_b + 1;
  (v132_p->a)->timer = v266_a;
  (v132_p->b)->timer = v266_b;
  int * v135_a = (v132_p->a)->regs;
  int * v135_b = (v132_p->b)->regs;
  int v136_a = v135_a[6];
  int v136_b = v135_b[6];
  int * v137_a = (v132_p->a)->cache_tags;
  int * v137_b = (v132_p->b)->cache_tags;
  int v270_a = (((int)((unsigned int)((int)((unsigned int)v136_a >> 2)) >> 1)) & 1) * 2;
  int v270_b = (((int)((unsigned int)((int)((unsigned int)v136_b >> 2)) >> 1)) & 1) * 2;
  int v138_a = v137_a[v270_a];
  int v138_b = v137_b[v270_b];
  int * v139_a = (v132_p->a)->cache_tags;
  int * v139_b = (v132_p->b)->cache_tags;
  int v272_a = ((((int)((unsigned int)((int)((unsigned int)v136_a >> 2)) >> 1)) & 1) * 2) + 1;
  int v272_b = ((((int)((unsigned int)((int)((unsigned int)v136_b >> 2)) >> 1)) & 1) * 2) + 1;
  int v140_a = v139_a[v272_a];
  int v140_b = v139_b[v272_b];
  int * v141_a = (v132_p->a)->cache_tags;
  int * v141_b = (v132_p->b)->cache_tags;
  int v274_a = 4 + ((((int)((unsigned int)((int)((unsigned int)v136_a >> 2)) >> 1)) & 3) * 2);
  int v274_b = 4 + ((((int)((unsigned int)((int)((unsigned int)v136_b >> 2)) >> 1)) & 3) * 2);
  int v142_a = v141_a[v274_a];
  int v142_b = v141_b[v274_b];
  int * v143_a = (v132_p->a)->cache_tags;
  int * v143_b = (v132_p->b)->cache_tags;
  int v276_a = (4 + ((((int)((unsigned int)((int)((unsigned int)v136_a >> 2)) >> 1)) & 3) * 2)) + 1;
  int v276_b = (4 + ((((int)((unsigned int)((int)((unsigned int)v136_b >> 2)) >> 1)) & 3) * 2)) + 1;
  int v144_a = v143_a[v276_a];
  int v144_b = v143_b[v276_b];
  int v145_a = (v132_p->a)->timer;
  int v145_b = (v132_p->b)->timer;
  int v277_a = v145_a + ((100 ^ (((~(((v142_a ^ ((int)((unsigned int)((int)((unsigned int)v136_a >> 2)) >> 1))) | (-(v142_a ^ ((int)((unsigned int)((int)((unsigned int)v136_a >> 2)) >> 1))))) >> 31)) | (~(((v144_a ^ ((int)((unsigned int)((int)((unsigned int)v136_a >> 2)) >> 1))) | (-(v144_a ^ ((int)((unsigned int)((int)((unsigned int)v136_a >> 2)) >> 1))))) >> 31))) & 104)) ^ (((~(((v138_a ^ ((int)((unsigned int)((int)((unsigned int)v136_a >> 2)) >> 1))) | (-(v138_a ^ ((int)((unsigned int)((int)((unsigned int)v136_a >> 2)) >> 1))))) >> 31)) | (~(((v140_a ^ ((int)((unsigned int)((int)((unsigned int)v136_a >> 2)) >> 1))) | (-(v140_a ^ ((int)((unsigned int)((int)((unsigned int)v136_a >> 2)) >> 1))))) >> 31))) & (1 ^ (100 ^ (((~(((v142_a ^ ((int)((unsigned int)((int)((unsigned int)v136_a >> 2)) >> 1))) | (-(v142_a ^ ((int)((unsigned int)((int)((unsigned int)v136_a >> 2)) >> 1))))) >> 31)) | (~(((v144_a ^ ((int)((unsigned int)((int)((unsigned int)v136_a >> 2)) >> 1))) | (-(v144_a ^ ((int)((unsigned int)((int)((unsigned int)v136_a >> 2)) >> 1))))) >> 31))) & 104)))));
  int v277_b = v145_b + ((100 ^ (((~(((v142_b ^ ((int)((unsigned int)((int)((unsigned int)v136_b >> 2)) >> 1))) | (-(v142_b ^ ((int)((unsigned int)((int)((unsigned int)v136_b >> 2)) >> 1))))) >> 31)) | (~(((v144_b ^ ((int)((unsigned int)((int)((unsigned int)v136_b >> 2)) >> 1))) | (-(v144_b ^ ((int)((unsigned int)((int)((unsigned int)v136_b >> 2)) >> 1))))) >> 31))) & 104)) ^ (((~(((v138_b ^ ((int)((unsigned int)((int)((unsigned int)v136_b >> 2)) >> 1))) | (-(v138_b ^ ((int)((unsigned int)((int)((unsigned int)v136_b >> 2)) >> 1))))) >> 31)) | (~(((v140_b ^ ((int)((unsigned int)((int)((unsigned int)v136_b >> 2)) >> 1))) | (-(v140_b ^ ((int)((unsigned int)((int)((unsigned int)v136_b >> 2)) >> 1))))) >> 31))) & (1 ^ (100 ^ (((~(((v142_b ^ ((int)((unsigned int)((int)((unsigned int)v136_b >> 2)) >> 1))) | (-(v142_b ^ ((int)((unsigned int)((int)((unsigned int)v136_b >> 2)) >> 1))))) >> 31)) | (~(((v144_b ^ ((int)((unsigned int)((int)((unsigned int)v136_b >> 2)) >> 1))) | (-(v144_b ^ ((int)((unsigned int)((int)((unsigned int)v136_b >> 2)) >> 1))))) >> 31))) & 104)))));
  (v132_p->a)->timer = v277_a;
  (v132_p->b)->timer = v277_b;
  int * v147_a = (v132_p->a)->cache_vals;
  int * v147_b = (v132_p->b)->cache_vals;
  bool v278_a = !(((~(((v138_a ^ ((int)((unsigned int)((int)((unsigned int)v136_a >> 2)) >> 1))) | (-(v138_a ^ ((int)((unsigned int)((int)((unsigned int)v136_a >> 2)) >> 1))))) >> 31)) | (~(((v140_a ^ ((int)((unsigned int)((int)((unsigned int)v136_a >> 2)) >> 1))) | (-(v140_a ^ ((int)((unsigned int)((int)((unsigned int)v136_a >> 2)) >> 1))))) >> 31))) == 0);
  bool v278_b = !(((~(((v138_b ^ ((int)((unsigned int)((int)((unsigned int)v136_b >> 2)) >> 1))) | (-(v138_b ^ ((int)((unsigned int)((int)((unsigned int)v136_b >> 2)) >> 1))))) >> 31)) | (~(((v140_b ^ ((int)((unsigned int)((int)((unsigned int)v136_b >> 2)) >> 1))) | (-(v140_b ^ ((int)((unsigned int)((int)((unsigned int)v136_b >> 2)) >> 1))))) >> 31))) == 0);
  int v260_a;
  if (v278_a) {
    int * v148_a = (v132_p->a)->cache_age;
    int v280_a = ((((int)((unsigned int)((int)((unsigned int)v136_a >> 2)) >> 1)) & 1) * 2) + ((~(((v140_a ^ ((int)((unsigned int)((int)((unsigned int)v136_a >> 2)) >> 1))) | (-(v140_a ^ ((int)((unsigned int)((int)((unsigned int)v136_a >> 2)) >> 1))))) >> 31)) & 1);
    int v149_a = v148_a[v280_a];
    int * v150_a = (v132_p->a)->cache_age;
    int v151_a = v150_a[v270_a];
    int * v152_a = (v132_p->a)->cache_age;
    int v283_a = v151_a + ((int)((unsigned int)(v151_a - v149_a) >> 31));
    v152_a[v270_a] = v283_a;
    int * v154_a = (v132_p->a)->cache_age;
    int v155_a = v154_a[v272_a];
    int * v156_a = (v132_p->a)->cache_age;
    int v286_a = v155_a + ((int)((unsigned int)(v155_a - v149_a) >> 31));
    v156_a[v272_a] = v286_a;
    int * v158_a = (v132_p->a)->cache_age;
    v158_a[v280_a] = 0;
    v260_a = v280_a;
  } else {
    int * v161_a = (v132_p->a)->cache_age;
    int v290_a = (((int)((unsigned int)((int)((unsigned int)v136_a >> 2)) >> 1)) & 1) * 2;
    int v162_a = v161_a[v290_a];
    int * v163_a = (v132_p->a)->cache_tags;
    int v164_a = v163_a[v290_a];
    int * v165_a = (v132_p->a)->cache_age;
    int v166_a = v165_a[v272_a];
    int * v167_a = (v132_p->a)->cache_tags;
    int v168_a = v167_a[v272_a];
    bool v294_a = !(((~(((v142_a ^ ((int)((unsigned int)((int)((unsigned int)v136_a >> 2)) >> 1))) | (-(v142_a ^ ((int)((unsigned int)((int)((unsigned int)v136_a >> 2)) >> 1))))) >> 31)) | (~(((v144_a ^ ((int)((unsigned int)((int)((unsigned int)v136_a >> 2)) >> 1))) | (-(v144_a ^ ((int)((unsigned int)((int)((unsigned int)v136_a >> 2)) >> 1))))) >> 31))) == 0);
    int v232_a;
    if (v294_a) {
      int * v169_a = (v132_p->a)->cache_age;
      int v296_a = (4 + ((((int)((unsigned int)((int)((unsigned int)v136_a >> 2)) >> 1)) & 3) * 2)) + ((~(((v144_a ^ ((int)((unsigned int)((int)((unsigned int)v136_a >> 2)) >> 1))) | (-(v144_a ^ ((int)((unsigned int)((int)((unsigned int)v136_a >> 2)) >> 1))))) >> 31)) & 1);
      int v170_a = v169_a[v296_a];
      int * v171_a = (v132_p->a)->cache_age;
      int v172_a = v171_a[v274_a];
      int * v173_a = (v132_p->a)->cache_age;
      int v299_a = v172_a + ((int)((unsigned int)(v172_a - v170_a) >> 31));
      v173_a[v274_a] = v299_a;
      int * v175_a = (v132_p->a)->cache_age;
      int v176_a = v175_a[v276_a];
      int * v177_a = (v132_p->a)->cache_age;
      int v302_a = v176_a + ((int)((unsigned int)(v176_a - v170_a) >> 31));
      v177_a[v276_a] = v302_a;
      int * v179_a = (v132_p->a)->cache_age;
      v179_a[v296_a] = 0;
      v232_a = v296_a;
    } else {
      int * v182_a = (v132_p->a)->cache_age;
      int v306_a = 4 + ((((int)((unsigned int)((int)((unsigned int)v136_a >> 2)) >> 1)) & 3) * 2);
      int v183_a = v182_a[v306_a];
      int * v184_a = (v132_p->a)->cache_tags;
      int v185_a = v184_a[v306_a];
      int * v186_a = (v132_p->a)->cache_age;
      int v187_a = v186_a[v276_a];
      int * v188_a = (v132_p->a)->cache_tags;
      int v189_a = v188_a[v276_a];
      int * v190_a = (v132_p->a)->cache_dirty;
      int v311_a = (4 + ((((int)((unsigned int)((int)((unsigned int)v136_a >> 2)) >> 1)) & 3) * 2)) + ((((v183_a + ((~(((v185_a ^ -1) | (-(v185_a ^ -1))) >> 31)) & 2)) - (v187_a + ((~(((v189_a ^ -1) | (-(v189_a ^ -1))) >> 31)) & 2))) >> 31) & 1);
      int v191_a = v190_a[v311_a];
      bool v312_a = !(v191_a == 0);
      if (v312_a) {
        int * v192_a = (v132_p->a)->cache_tags;
        int v193_a = v192_a[v311_a];
        int * v194_a = (v132_p->a)->cache_vals;
        int v315_a = ((4 + ((((int)((unsigned int)((int)((unsigned int)v136_a >> 2)) >> 1)) & 3) * 2)) + ((((v183_a + ((~(((v185_a ^ -1) | (-(v185_a ^ -1))) >> 31)) & 2)) - (v187_a + ((~(((v189_a ^ -1) | (-(v189_a ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
        int v195_a = v194_a[v315_a];
        int * v196_a = (v132_p->a)->cache_vals;
        int v317_a = (((4 + ((((int)((unsigned int)((int)((unsigned int)v136_a >> 2)) >> 1)) & 3) * 2)) + ((((v183_a + ((~(((v185_a ^ -1) | (-(v185_a ^ -1))) >> 31)) & 2)) - (v187_a + ((~(((v189_a ^ -1) | (-(v189_a ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
        int v197_a = v196_a[v317_a];
        int * v198_a = (v132_p->a)->mem;
        int v319_a = v193_a * 2;
        v198_a[v319_a] = v195_a;
        int * v200_a = (v132_p->a)->mem;
        int v322_a = (v193_a * 2) + 1;
        v200_a[v322_a] = v197_a;
        ;
      } else {
        ;
      }
      int * v205_a = (v132_p->a)->mem;
      int v327_a = ((int)((unsigned int)((int)((unsigned int)v136_a >> 2)) >> 1)) * 2;
      int v206_a = v205_a[v327_a];
      int * v207_a = (v132_p->a)->mem;
      int v329_a = (((int)((unsigned int)((int)((unsigned int)v136_a >> 2)) >> 1)) * 2) + 1;
      int v208_a = v207_a[v329_a];
      int * v209_a = (v132_p->a)->cache_vals;
      int v331_a = ((4 + ((((int)((unsigned int)((int)((unsigned int)v136_a >> 2)) >> 1)) & 3) * 2)) + ((((v183_a + ((~(((v185_a ^ -1) | (-(v185_a ^ -1))) >> 31)) & 2)) - (v187_a + ((~(((v189_a ^ -1) | (-(v189_a ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
      v209_a[v331_a] = v206_a;
      int * v211_a = (v132_p->a)->cache_vals;
      int v334_a = (((4 + ((((int)((unsigned int)((int)((unsigned int)v136_a >> 2)) >> 1)) & 3) * 2)) + ((((v183_a + ((~(((v185_a ^ -1) | (-(v185_a ^ -1))) >> 31)) & 2)) - (v187_a + ((~(((v189_a ^ -1) | (-(v189_a ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
      v211_a[v334_a] = v208_a;
      int * v213_a = (v132_p->a)->cache_tags;
      int v337_a = (int)((unsigned int)((int)((unsigned int)v136_a >> 2)) >> 1);
      v213_a[v311_a] = v337_a;
      int * v215_a = (v132_p->a)->cache_dirty;
      v215_a[v311_a] = 0;
      int * v217_a = (v132_p->a)->cache_age;
      v217_a[v311_a] = 1;
      int * v219_a = (v132_p->a)->cache_age;
      int v220_a = v219_a[v311_a];
      int * v221_a = (v132_p->a)->cache_age;
      int v222_a = v221_a[v274_a];
      int * v223_a = (v132_p->a)->cache_age;
      int v345_a = v222_a + ((int)((unsigned int)(v222_a - v220_a) >> 31));
      v223_a[v274_a] = v345_a;
      int * v225_a = (v132_p->a)->cache_age;
      int v226_a = v225_a[v276_a];
      int * v227_a = (v132_p->a)->cache_age;
      int v348_a = v226_a + ((int)((unsigned int)(v226_a - v220_a) >> 31));
      v227_a[v276_a] = v348_a;
      int * v229_a = (v132_p->a)->cache_age;
      v229_a[v311_a] = 0;
      v232_a = v311_a;
    }
    int * v233_a = (v132_p->a)->cache_vals;
    int v351_a = v232_a * 2;
    int v234_a = v233_a[v351_a];
    int * v235_a = (v132_p->a)->cache_vals;
    int v353_a = (v232_a * 2) + 1;
    int v236_a = v235_a[v353_a];
    int * v237_a = (v132_p->a)->cache_vals;
    int v355_a = (((((int)((unsigned int)((int)((unsigned int)v136_a >> 2)) >> 1)) & 1) * 2) + ((((v162_a + ((~(((v164_a ^ -1) | (-(v164_a ^ -1))) >> 31)) & 2)) - (v166_a + ((~(((v168_a ^ -1) | (-(v168_a ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
    v237_a[v355_a] = v234_a;
    int * v239_a = (v132_p->a)->cache_vals;
    int v358_a = ((((((int)((unsigned int)((int)((unsigned int)v136_a >> 2)) >> 1)) & 1) * 2) + ((((v162_a + ((~(((v164_a ^ -1) | (-(v164_a ^ -1))) >> 31)) & 2)) - (v166_a + ((~(((v168_a ^ -1) | (-(v168_a ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
    v239_a[v358_a] = v236_a;
    int * v241_a = (v132_p->a)->cache_tags;
    int v361_a = ((((int)((unsigned int)((int)((unsigned int)v136_a >> 2)) >> 1)) & 1) * 2) + ((((v162_a + ((~(((v164_a ^ -1) | (-(v164_a ^ -1))) >> 31)) & 2)) - (v166_a + ((~(((v168_a ^ -1) | (-(v168_a ^ -1))) >> 31)) & 2))) >> 31) & 1);
    int v362_a = (int)((unsigned int)((int)((unsigned int)v136_a >> 2)) >> 1);
    v241_a[v361_a] = v362_a;
    int * v243_a = (v132_p->a)->cache_dirty;
    v243_a[v361_a] = 0;
    int * v245_a = (v132_p->a)->cache_age;
    v245_a[v361_a] = 1;
    int * v247_a = (v132_p->a)->cache_age;
    int v248_a = v247_a[v361_a];
    int * v249_a = (v132_p->a)->cache_age;
    int v250_a = v249_a[v270_a];
    int * v251_a = (v132_p->a)->cache_age;
    int v370_a = v250_a + ((int)((unsigned int)(v250_a - v248_a) >> 31));
    v251_a[v270_a] = v370_a;
    int * v253_a = (v132_p->a)->cache_age;
    int v254_a = v253_a[v272_a];
    int * v255_a = (v132_p->a)->cache_age;
    int v373_a = v254_a + ((int)((unsigned int)(v254_a - v248_a) >> 31));
    v255_a[v272_a] = v373_a;
    int * v257_a = (v132_p->a)->cache_age;
    v257_a[v361_a] = 0;
    v260_a = v361_a;
  }
  int v260_b;
  if (v278_b) {
    int * v148_b = (v132_p->b)->cache_age;
    int v280_b = ((((int)((unsigned int)((int)((unsigned int)v136_b >> 2)) >> 1)) & 1) * 2) + ((~(((v140_b ^ ((int)((unsigned int)((int)((unsigned int)v136_b >> 2)) >> 1))) | (-(v140_b ^ ((int)((unsigned int)((int)((unsigned int)v136_b >> 2)) >> 1))))) >> 31)) & 1);
    int v149_b = v148_b[v280_b];
    int * v150_b = (v132_p->b)->cache_age;
    int v151_b = v150_b[v270_b];
    int * v152_b = (v132_p->b)->cache_age;
    int v283_b = v151_b + ((int)((unsigned int)(v151_b - v149_b) >> 31));
    v152_b[v270_b] = v283_b;
    int * v154_b = (v132_p->b)->cache_age;
    int v155_b = v154_b[v272_b];
    int * v156_b = (v132_p->b)->cache_age;
    int v286_b = v155_b + ((int)((unsigned int)(v155_b - v149_b) >> 31));
    v156_b[v272_b] = v286_b;
    int * v158_b = (v132_p->b)->cache_age;
    v158_b[v280_b] = 0;
    v260_b = v280_b;
  } else {
    int * v161_b = (v132_p->b)->cache_age;
    int v290_b = (((int)((unsigned int)((int)((unsigned int)v136_b >> 2)) >> 1)) & 1) * 2;
    int v162_b = v161_b[v290_b];
    int * v163_b = (v132_p->b)->cache_tags;
    int v164_b = v163_b[v290_b];
    int * v165_b = (v132_p->b)->cache_age;
    int v166_b = v165_b[v272_b];
    int * v167_b = (v132_p->b)->cache_tags;
    int v168_b = v167_b[v272_b];
    bool v294_b = !(((~(((v142_b ^ ((int)((unsigned int)((int)((unsigned int)v136_b >> 2)) >> 1))) | (-(v142_b ^ ((int)((unsigned int)((int)((unsigned int)v136_b >> 2)) >> 1))))) >> 31)) | (~(((v144_b ^ ((int)((unsigned int)((int)((unsigned int)v136_b >> 2)) >> 1))) | (-(v144_b ^ ((int)((unsigned int)((int)((unsigned int)v136_b >> 2)) >> 1))))) >> 31))) == 0);
    int v232_b;
    if (v294_b) {
      int * v169_b = (v132_p->b)->cache_age;
      int v296_b = (4 + ((((int)((unsigned int)((int)((unsigned int)v136_b >> 2)) >> 1)) & 3) * 2)) + ((~(((v144_b ^ ((int)((unsigned int)((int)((unsigned int)v136_b >> 2)) >> 1))) | (-(v144_b ^ ((int)((unsigned int)((int)((unsigned int)v136_b >> 2)) >> 1))))) >> 31)) & 1);
      int v170_b = v169_b[v296_b];
      int * v171_b = (v132_p->b)->cache_age;
      int v172_b = v171_b[v274_b];
      int * v173_b = (v132_p->b)->cache_age;
      int v299_b = v172_b + ((int)((unsigned int)(v172_b - v170_b) >> 31));
      v173_b[v274_b] = v299_b;
      int * v175_b = (v132_p->b)->cache_age;
      int v176_b = v175_b[v276_b];
      int * v177_b = (v132_p->b)->cache_age;
      int v302_b = v176_b + ((int)((unsigned int)(v176_b - v170_b) >> 31));
      v177_b[v276_b] = v302_b;
      int * v179_b = (v132_p->b)->cache_age;
      v179_b[v296_b] = 0;
      v232_b = v296_b;
    } else {
      int * v182_b = (v132_p->b)->cache_age;
      int v306_b = 4 + ((((int)((unsigned int)((int)((unsigned int)v136_b >> 2)) >> 1)) & 3) * 2);
      int v183_b = v182_b[v306_b];
      int * v184_b = (v132_p->b)->cache_tags;
      int v185_b = v184_b[v306_b];
      int * v186_b = (v132_p->b)->cache_age;
      int v187_b = v186_b[v276_b];
      int * v188_b = (v132_p->b)->cache_tags;
      int v189_b = v188_b[v276_b];
      int * v190_b = (v132_p->b)->cache_dirty;
      int v311_b = (4 + ((((int)((unsigned int)((int)((unsigned int)v136_b >> 2)) >> 1)) & 3) * 2)) + ((((v183_b + ((~(((v185_b ^ -1) | (-(v185_b ^ -1))) >> 31)) & 2)) - (v187_b + ((~(((v189_b ^ -1) | (-(v189_b ^ -1))) >> 31)) & 2))) >> 31) & 1);
      int v191_b = v190_b[v311_b];
      bool v312_b = !(v191_b == 0);
      if (v312_b) {
        int * v192_b = (v132_p->b)->cache_tags;
        int v193_b = v192_b[v311_b];
        int * v194_b = (v132_p->b)->cache_vals;
        int v315_b = ((4 + ((((int)((unsigned int)((int)((unsigned int)v136_b >> 2)) >> 1)) & 3) * 2)) + ((((v183_b + ((~(((v185_b ^ -1) | (-(v185_b ^ -1))) >> 31)) & 2)) - (v187_b + ((~(((v189_b ^ -1) | (-(v189_b ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
        int v195_b = v194_b[v315_b];
        int * v196_b = (v132_p->b)->cache_vals;
        int v317_b = (((4 + ((((int)((unsigned int)((int)((unsigned int)v136_b >> 2)) >> 1)) & 3) * 2)) + ((((v183_b + ((~(((v185_b ^ -1) | (-(v185_b ^ -1))) >> 31)) & 2)) - (v187_b + ((~(((v189_b ^ -1) | (-(v189_b ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
        int v197_b = v196_b[v317_b];
        int * v198_b = (v132_p->b)->mem;
        int v319_b = v193_b * 2;
        v198_b[v319_b] = v195_b;
        int * v200_b = (v132_p->b)->mem;
        int v322_b = (v193_b * 2) + 1;
        v200_b[v322_b] = v197_b;
        ;
      } else {
        ;
      }
      int * v205_b = (v132_p->b)->mem;
      int v327_b = ((int)((unsigned int)((int)((unsigned int)v136_b >> 2)) >> 1)) * 2;
      int v206_b = v205_b[v327_b];
      int * v207_b = (v132_p->b)->mem;
      int v329_b = (((int)((unsigned int)((int)((unsigned int)v136_b >> 2)) >> 1)) * 2) + 1;
      int v208_b = v207_b[v329_b];
      int * v209_b = (v132_p->b)->cache_vals;
      int v331_b = ((4 + ((((int)((unsigned int)((int)((unsigned int)v136_b >> 2)) >> 1)) & 3) * 2)) + ((((v183_b + ((~(((v185_b ^ -1) | (-(v185_b ^ -1))) >> 31)) & 2)) - (v187_b + ((~(((v189_b ^ -1) | (-(v189_b ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
      v209_b[v331_b] = v206_b;
      int * v211_b = (v132_p->b)->cache_vals;
      int v334_b = (((4 + ((((int)((unsigned int)((int)((unsigned int)v136_b >> 2)) >> 1)) & 3) * 2)) + ((((v183_b + ((~(((v185_b ^ -1) | (-(v185_b ^ -1))) >> 31)) & 2)) - (v187_b + ((~(((v189_b ^ -1) | (-(v189_b ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
      v211_b[v334_b] = v208_b;
      int * v213_b = (v132_p->b)->cache_tags;
      int v337_b = (int)((unsigned int)((int)((unsigned int)v136_b >> 2)) >> 1);
      v213_b[v311_b] = v337_b;
      int * v215_b = (v132_p->b)->cache_dirty;
      v215_b[v311_b] = 0;
      int * v217_b = (v132_p->b)->cache_age;
      v217_b[v311_b] = 1;
      int * v219_b = (v132_p->b)->cache_age;
      int v220_b = v219_b[v311_b];
      int * v221_b = (v132_p->b)->cache_age;
      int v222_b = v221_b[v274_b];
      int * v223_b = (v132_p->b)->cache_age;
      int v345_b = v222_b + ((int)((unsigned int)(v222_b - v220_b) >> 31));
      v223_b[v274_b] = v345_b;
      int * v225_b = (v132_p->b)->cache_age;
      int v226_b = v225_b[v276_b];
      int * v227_b = (v132_p->b)->cache_age;
      int v348_b = v226_b + ((int)((unsigned int)(v226_b - v220_b) >> 31));
      v227_b[v276_b] = v348_b;
      int * v229_b = (v132_p->b)->cache_age;
      v229_b[v311_b] = 0;
      v232_b = v311_b;
    }
    int * v233_b = (v132_p->b)->cache_vals;
    int v351_b = v232_b * 2;
    int v234_b = v233_b[v351_b];
    int * v235_b = (v132_p->b)->cache_vals;
    int v353_b = (v232_b * 2) + 1;
    int v236_b = v235_b[v353_b];
    int * v237_b = (v132_p->b)->cache_vals;
    int v355_b = (((((int)((unsigned int)((int)((unsigned int)v136_b >> 2)) >> 1)) & 1) * 2) + ((((v162_b + ((~(((v164_b ^ -1) | (-(v164_b ^ -1))) >> 31)) & 2)) - (v166_b + ((~(((v168_b ^ -1) | (-(v168_b ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
    v237_b[v355_b] = v234_b;
    int * v239_b = (v132_p->b)->cache_vals;
    int v358_b = ((((((int)((unsigned int)((int)((unsigned int)v136_b >> 2)) >> 1)) & 1) * 2) + ((((v162_b + ((~(((v164_b ^ -1) | (-(v164_b ^ -1))) >> 31)) & 2)) - (v166_b + ((~(((v168_b ^ -1) | (-(v168_b ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
    v239_b[v358_b] = v236_b;
    int * v241_b = (v132_p->b)->cache_tags;
    int v361_b = ((((int)((unsigned int)((int)((unsigned int)v136_b >> 2)) >> 1)) & 1) * 2) + ((((v162_b + ((~(((v164_b ^ -1) | (-(v164_b ^ -1))) >> 31)) & 2)) - (v166_b + ((~(((v168_b ^ -1) | (-(v168_b ^ -1))) >> 31)) & 2))) >> 31) & 1);
    int v362_b = (int)((unsigned int)((int)((unsigned int)v136_b >> 2)) >> 1);
    v241_b[v361_b] = v362_b;
    int * v243_b = (v132_p->b)->cache_dirty;
    v243_b[v361_b] = 0;
    int * v245_b = (v132_p->b)->cache_age;
    v245_b[v361_b] = 1;
    int * v247_b = (v132_p->b)->cache_age;
    int v248_b = v247_b[v361_b];
    int * v249_b = (v132_p->b)->cache_age;
    int v250_b = v249_b[v270_b];
    int * v251_b = (v132_p->b)->cache_age;
    int v370_b = v250_b + ((int)((unsigned int)(v250_b - v248_b) >> 31));
    v251_b[v270_b] = v370_b;
    int * v253_b = (v132_p->b)->cache_age;
    int v254_b = v253_b[v272_b];
    int * v255_b = (v132_p->b)->cache_age;
    int v373_b = v254_b + ((int)((unsigned int)(v254_b - v248_b) >> 31));
    v255_b[v272_b] = v373_b;
    int * v257_b = (v132_p->b)->cache_age;
    v257_b[v361_b] = 0;
    v260_b = v361_b;
  }
  int v376_a = (v260_a * 2) + (((int)((unsigned int)v136_a >> 2)) & 1);
  int v376_b = (v260_b * 2) + (((int)((unsigned int)v136_b >> 2)) & 1);
  int v261_a = v147_a[v376_a];
  int v261_b = v147_b[v376_b];
  int * v262_a = (v132_p->a)->regs;
  int * v262_b = (v132_p->b)->regs;
  v262_a[7] = v261_a;
  v262_b[7] = v261_b;
  struct StateT2 * v264_p = slot_8(v132_p);
  return v264_p;
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

struct StateT2 * slot_10(struct StateT2 * v653_p) {
  lockstep_assert(((v653_p->a)->timer) == ((v653_p->b)->timer));
  lockstep_assume(((v653_p->a)->timer) == ((v653_p->b)->timer));
  int v654_a = (v653_p->a)->timer;
  int v654_b = (v653_p->b)->timer;
  int v664_a = v654_a + 1;
  int v664_b = v654_b + 1;
  (v653_p->a)->timer = v664_a;
  (v653_p->b)->timer = v664_b;
  int * v656_a = (v653_p->a)->regs;
  int * v656_b = (v653_p->b)->regs;
  int v657_a = v656_a[7];
  int v657_b = v656_b[7];
  int * v658_a = (v653_p->a)->regs;
  int * v658_b = (v653_p->b)->regs;
  int v659_a = v658_a[9];
  int v659_b = v658_b[9];
  int * v660_a = (v653_p->a)->regs;
  int * v660_b = (v653_p->b)->regs;
  int v671_a = v657_a ^ v659_a;
  int v671_b = v657_b ^ v659_b;
  v660_a[16] = v671_a;
  v660_b[16] = v671_b;
  struct StateT2 * v662_p = slot_11(v653_p);
  return v662_p;
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

struct StateT2 * slot_8(struct StateT2 * v382_p) {
  lockstep_assert(((v382_p->a)->timer) == ((v382_p->b)->timer));
  lockstep_assume(((v382_p->a)->timer) == ((v382_p->b)->timer));
  int v383_a = (v382_p->a)->timer;
  int v383_b = (v382_p->b)->timer;
  int v393_a = v383_a + 1;
  int v393_b = v383_b + 1;
  (v382_p->a)->timer = v393_a;
  (v382_p->b)->timer = v393_b;
  int * v385_a = (v382_p->a)->regs;
  int * v385_b = (v382_p->b)->regs;
  int v386_a = v385_a[13];
  int v386_b = v385_b[13];
  int * v387_a = (v382_p->a)->regs;
  int * v387_b = (v382_p->b)->regs;
  int v388_a = v387_a[14];
  int v388_b = v387_b[14];
  int * v389_a = (v382_p->a)->regs;
  int * v389_b = (v382_p->b)->regs;
  int v400_a = v386_a + v388_a;
  int v400_b = v386_b + v388_b;
  v389_a[8] = v400_a;
  v389_b[8] = v400_b;
  struct StateT2 * v391_p = slot_9(v382_p);
  return v391_p;
}

struct StateT2 * slot_4(struct StateT2 * v54_p) {
  lockstep_assert(((v54_p->a)->timer) == ((v54_p->b)->timer));
  lockstep_assume(((v54_p->a)->timer) == ((v54_p->b)->timer));
  int v55_a = (v54_p->a)->timer;
  int v55_b = (v54_p->b)->timer;
  int v61_a = v55_a + 1;
  int v61_b = v55_b + 1;
  (v54_p->a)->timer = v61_a;
  (v54_p->b)->timer = v61_b;
  int * v57_a = (v54_p->a)->regs;
  int * v57_b = (v54_p->b)->regs;
  v57_a[5] = 0;
  v57_b[5] = 0;
  struct StateT2 * v59_p = slot_5(v54_p);
  return v59_p;
}

struct StateT2 * slot_13(struct StateT2 * v710_p) {
  lockstep_assert(((v710_p->a)->timer) == ((v710_p->b)->timer));
  lockstep_assume(((v710_p->a)->timer) == ((v710_p->b)->timer));
  int v711_a = (v710_p->a)->timer;
  int v711_b = (v710_p->b)->timer;
  int v715_a = v711_a + 1;
  int v715_b = v711_b + 1;
  (v710_p->a)->timer = v715_a;
  (v710_p->b)->timer = v715_b;
  struct StateT2 * v713_p = slot_5(v710_p);
  return v713_p;
}

struct StateT2 * slot_9(struct StateT2 * v403_p) {
  lockstep_assert(((v403_p->a)->timer) == ((v403_p->b)->timer));
  lockstep_assume(((v403_p->a)->timer) == ((v403_p->b)->timer));
  int v404_a = (v403_p->a)->timer;
  int v404_b = (v403_p->b)->timer;
  int v537_a = v404_a + 1;
  int v537_b = v404_b + 1;
  (v403_p->a)->timer = v537_a;
  (v403_p->b)->timer = v537_b;
  int * v406_a = (v403_p->a)->regs;
  int * v406_b = (v403_p->b)->regs;
  int v407_a = v406_a[8];
  int v407_b = v406_b[8];
  int * v408_a = (v403_p->a)->cache_tags;
  int * v408_b = (v403_p->b)->cache_tags;
  int v541_a = (((int)((unsigned int)((int)((unsigned int)v407_a >> 2)) >> 1)) & 1) * 2;
  int v541_b = (((int)((unsigned int)((int)((unsigned int)v407_b >> 2)) >> 1)) & 1) * 2;
  int v409_a = v408_a[v541_a];
  int v409_b = v408_b[v541_b];
  int * v410_a = (v403_p->a)->cache_tags;
  int * v410_b = (v403_p->b)->cache_tags;
  int v543_a = ((((int)((unsigned int)((int)((unsigned int)v407_a >> 2)) >> 1)) & 1) * 2) + 1;
  int v543_b = ((((int)((unsigned int)((int)((unsigned int)v407_b >> 2)) >> 1)) & 1) * 2) + 1;
  int v411_a = v410_a[v543_a];
  int v411_b = v410_b[v543_b];
  int * v412_a = (v403_p->a)->cache_tags;
  int * v412_b = (v403_p->b)->cache_tags;
  int v545_a = 4 + ((((int)((unsigned int)((int)((unsigned int)v407_a >> 2)) >> 1)) & 3) * 2);
  int v545_b = 4 + ((((int)((unsigned int)((int)((unsigned int)v407_b >> 2)) >> 1)) & 3) * 2);
  int v413_a = v412_a[v545_a];
  int v413_b = v412_b[v545_b];
  int * v414_a = (v403_p->a)->cache_tags;
  int * v414_b = (v403_p->b)->cache_tags;
  int v547_a = (4 + ((((int)((unsigned int)((int)((unsigned int)v407_a >> 2)) >> 1)) & 3) * 2)) + 1;
  int v547_b = (4 + ((((int)((unsigned int)((int)((unsigned int)v407_b >> 2)) >> 1)) & 3) * 2)) + 1;
  int v415_a = v414_a[v547_a];
  int v415_b = v414_b[v547_b];
  int v416_a = (v403_p->a)->timer;
  int v416_b = (v403_p->b)->timer;
  int v548_a = v416_a + ((100 ^ (((~(((v413_a ^ ((int)((unsigned int)((int)((unsigned int)v407_a >> 2)) >> 1))) | (-(v413_a ^ ((int)((unsigned int)((int)((unsigned int)v407_a >> 2)) >> 1))))) >> 31)) | (~(((v415_a ^ ((int)((unsigned int)((int)((unsigned int)v407_a >> 2)) >> 1))) | (-(v415_a ^ ((int)((unsigned int)((int)((unsigned int)v407_a >> 2)) >> 1))))) >> 31))) & 104)) ^ (((~(((v409_a ^ ((int)((unsigned int)((int)((unsigned int)v407_a >> 2)) >> 1))) | (-(v409_a ^ ((int)((unsigned int)((int)((unsigned int)v407_a >> 2)) >> 1))))) >> 31)) | (~(((v411_a ^ ((int)((unsigned int)((int)((unsigned int)v407_a >> 2)) >> 1))) | (-(v411_a ^ ((int)((unsigned int)((int)((unsigned int)v407_a >> 2)) >> 1))))) >> 31))) & (1 ^ (100 ^ (((~(((v413_a ^ ((int)((unsigned int)((int)((unsigned int)v407_a >> 2)) >> 1))) | (-(v413_a ^ ((int)((unsigned int)((int)((unsigned int)v407_a >> 2)) >> 1))))) >> 31)) | (~(((v415_a ^ ((int)((unsigned int)((int)((unsigned int)v407_a >> 2)) >> 1))) | (-(v415_a ^ ((int)((unsigned int)((int)((unsigned int)v407_a >> 2)) >> 1))))) >> 31))) & 104)))));
  int v548_b = v416_b + ((100 ^ (((~(((v413_b ^ ((int)((unsigned int)((int)((unsigned int)v407_b >> 2)) >> 1))) | (-(v413_b ^ ((int)((unsigned int)((int)((unsigned int)v407_b >> 2)) >> 1))))) >> 31)) | (~(((v415_b ^ ((int)((unsigned int)((int)((unsigned int)v407_b >> 2)) >> 1))) | (-(v415_b ^ ((int)((unsigned int)((int)((unsigned int)v407_b >> 2)) >> 1))))) >> 31))) & 104)) ^ (((~(((v409_b ^ ((int)((unsigned int)((int)((unsigned int)v407_b >> 2)) >> 1))) | (-(v409_b ^ ((int)((unsigned int)((int)((unsigned int)v407_b >> 2)) >> 1))))) >> 31)) | (~(((v411_b ^ ((int)((unsigned int)((int)((unsigned int)v407_b >> 2)) >> 1))) | (-(v411_b ^ ((int)((unsigned int)((int)((unsigned int)v407_b >> 2)) >> 1))))) >> 31))) & (1 ^ (100 ^ (((~(((v413_b ^ ((int)((unsigned int)((int)((unsigned int)v407_b >> 2)) >> 1))) | (-(v413_b ^ ((int)((unsigned int)((int)((unsigned int)v407_b >> 2)) >> 1))))) >> 31)) | (~(((v415_b ^ ((int)((unsigned int)((int)((unsigned int)v407_b >> 2)) >> 1))) | (-(v415_b ^ ((int)((unsigned int)((int)((unsigned int)v407_b >> 2)) >> 1))))) >> 31))) & 104)))));
  (v403_p->a)->timer = v548_a;
  (v403_p->b)->timer = v548_b;
  int * v418_a = (v403_p->a)->cache_vals;
  int * v418_b = (v403_p->b)->cache_vals;
  bool v549_a = !(((~(((v409_a ^ ((int)((unsigned int)((int)((unsigned int)v407_a >> 2)) >> 1))) | (-(v409_a ^ ((int)((unsigned int)((int)((unsigned int)v407_a >> 2)) >> 1))))) >> 31)) | (~(((v411_a ^ ((int)((unsigned int)((int)((unsigned int)v407_a >> 2)) >> 1))) | (-(v411_a ^ ((int)((unsigned int)((int)((unsigned int)v407_a >> 2)) >> 1))))) >> 31))) == 0);
  bool v549_b = !(((~(((v409_b ^ ((int)((unsigned int)((int)((unsigned int)v407_b >> 2)) >> 1))) | (-(v409_b ^ ((int)((unsigned int)((int)((unsigned int)v407_b >> 2)) >> 1))))) >> 31)) | (~(((v411_b ^ ((int)((unsigned int)((int)((unsigned int)v407_b >> 2)) >> 1))) | (-(v411_b ^ ((int)((unsigned int)((int)((unsigned int)v407_b >> 2)) >> 1))))) >> 31))) == 0);
  int v531_a;
  if (v549_a) {
    int * v419_a = (v403_p->a)->cache_age;
    int v551_a = ((((int)((unsigned int)((int)((unsigned int)v407_a >> 2)) >> 1)) & 1) * 2) + ((~(((v411_a ^ ((int)((unsigned int)((int)((unsigned int)v407_a >> 2)) >> 1))) | (-(v411_a ^ ((int)((unsigned int)((int)((unsigned int)v407_a >> 2)) >> 1))))) >> 31)) & 1);
    int v420_a = v419_a[v551_a];
    int * v421_a = (v403_p->a)->cache_age;
    int v422_a = v421_a[v541_a];
    int * v423_a = (v403_p->a)->cache_age;
    int v554_a = v422_a + ((int)((unsigned int)(v422_a - v420_a) >> 31));
    v423_a[v541_a] = v554_a;
    int * v425_a = (v403_p->a)->cache_age;
    int v426_a = v425_a[v543_a];
    int * v427_a = (v403_p->a)->cache_age;
    int v557_a = v426_a + ((int)((unsigned int)(v426_a - v420_a) >> 31));
    v427_a[v543_a] = v557_a;
    int * v429_a = (v403_p->a)->cache_age;
    v429_a[v551_a] = 0;
    v531_a = v551_a;
  } else {
    int * v432_a = (v403_p->a)->cache_age;
    int v561_a = (((int)((unsigned int)((int)((unsigned int)v407_a >> 2)) >> 1)) & 1) * 2;
    int v433_a = v432_a[v561_a];
    int * v434_a = (v403_p->a)->cache_tags;
    int v435_a = v434_a[v561_a];
    int * v436_a = (v403_p->a)->cache_age;
    int v437_a = v436_a[v543_a];
    int * v438_a = (v403_p->a)->cache_tags;
    int v439_a = v438_a[v543_a];
    bool v565_a = !(((~(((v413_a ^ ((int)((unsigned int)((int)((unsigned int)v407_a >> 2)) >> 1))) | (-(v413_a ^ ((int)((unsigned int)((int)((unsigned int)v407_a >> 2)) >> 1))))) >> 31)) | (~(((v415_a ^ ((int)((unsigned int)((int)((unsigned int)v407_a >> 2)) >> 1))) | (-(v415_a ^ ((int)((unsigned int)((int)((unsigned int)v407_a >> 2)) >> 1))))) >> 31))) == 0);
    int v503_a;
    if (v565_a) {
      int * v440_a = (v403_p->a)->cache_age;
      int v567_a = (4 + ((((int)((unsigned int)((int)((unsigned int)v407_a >> 2)) >> 1)) & 3) * 2)) + ((~(((v415_a ^ ((int)((unsigned int)((int)((unsigned int)v407_a >> 2)) >> 1))) | (-(v415_a ^ ((int)((unsigned int)((int)((unsigned int)v407_a >> 2)) >> 1))))) >> 31)) & 1);
      int v441_a = v440_a[v567_a];
      int * v442_a = (v403_p->a)->cache_age;
      int v443_a = v442_a[v545_a];
      int * v444_a = (v403_p->a)->cache_age;
      int v570_a = v443_a + ((int)((unsigned int)(v443_a - v441_a) >> 31));
      v444_a[v545_a] = v570_a;
      int * v446_a = (v403_p->a)->cache_age;
      int v447_a = v446_a[v547_a];
      int * v448_a = (v403_p->a)->cache_age;
      int v573_a = v447_a + ((int)((unsigned int)(v447_a - v441_a) >> 31));
      v448_a[v547_a] = v573_a;
      int * v450_a = (v403_p->a)->cache_age;
      v450_a[v567_a] = 0;
      v503_a = v567_a;
    } else {
      int * v453_a = (v403_p->a)->cache_age;
      int v577_a = 4 + ((((int)((unsigned int)((int)((unsigned int)v407_a >> 2)) >> 1)) & 3) * 2);
      int v454_a = v453_a[v577_a];
      int * v455_a = (v403_p->a)->cache_tags;
      int v456_a = v455_a[v577_a];
      int * v457_a = (v403_p->a)->cache_age;
      int v458_a = v457_a[v547_a];
      int * v459_a = (v403_p->a)->cache_tags;
      int v460_a = v459_a[v547_a];
      int * v461_a = (v403_p->a)->cache_dirty;
      int v582_a = (4 + ((((int)((unsigned int)((int)((unsigned int)v407_a >> 2)) >> 1)) & 3) * 2)) + ((((v454_a + ((~(((v456_a ^ -1) | (-(v456_a ^ -1))) >> 31)) & 2)) - (v458_a + ((~(((v460_a ^ -1) | (-(v460_a ^ -1))) >> 31)) & 2))) >> 31) & 1);
      int v462_a = v461_a[v582_a];
      bool v583_a = !(v462_a == 0);
      if (v583_a) {
        int * v463_a = (v403_p->a)->cache_tags;
        int v464_a = v463_a[v582_a];
        int * v465_a = (v403_p->a)->cache_vals;
        int v586_a = ((4 + ((((int)((unsigned int)((int)((unsigned int)v407_a >> 2)) >> 1)) & 3) * 2)) + ((((v454_a + ((~(((v456_a ^ -1) | (-(v456_a ^ -1))) >> 31)) & 2)) - (v458_a + ((~(((v460_a ^ -1) | (-(v460_a ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
        int v466_a = v465_a[v586_a];
        int * v467_a = (v403_p->a)->cache_vals;
        int v588_a = (((4 + ((((int)((unsigned int)((int)((unsigned int)v407_a >> 2)) >> 1)) & 3) * 2)) + ((((v454_a + ((~(((v456_a ^ -1) | (-(v456_a ^ -1))) >> 31)) & 2)) - (v458_a + ((~(((v460_a ^ -1) | (-(v460_a ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
        int v468_a = v467_a[v588_a];
        int * v469_a = (v403_p->a)->mem;
        int v590_a = v464_a * 2;
        v469_a[v590_a] = v466_a;
        int * v471_a = (v403_p->a)->mem;
        int v593_a = (v464_a * 2) + 1;
        v471_a[v593_a] = v468_a;
        ;
      } else {
        ;
      }
      int * v476_a = (v403_p->a)->mem;
      int v598_a = ((int)((unsigned int)((int)((unsigned int)v407_a >> 2)) >> 1)) * 2;
      int v477_a = v476_a[v598_a];
      int * v478_a = (v403_p->a)->mem;
      int v600_a = (((int)((unsigned int)((int)((unsigned int)v407_a >> 2)) >> 1)) * 2) + 1;
      int v479_a = v478_a[v600_a];
      int * v480_a = (v403_p->a)->cache_vals;
      int v602_a = ((4 + ((((int)((unsigned int)((int)((unsigned int)v407_a >> 2)) >> 1)) & 3) * 2)) + ((((v454_a + ((~(((v456_a ^ -1) | (-(v456_a ^ -1))) >> 31)) & 2)) - (v458_a + ((~(((v460_a ^ -1) | (-(v460_a ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
      v480_a[v602_a] = v477_a;
      int * v482_a = (v403_p->a)->cache_vals;
      int v605_a = (((4 + ((((int)((unsigned int)((int)((unsigned int)v407_a >> 2)) >> 1)) & 3) * 2)) + ((((v454_a + ((~(((v456_a ^ -1) | (-(v456_a ^ -1))) >> 31)) & 2)) - (v458_a + ((~(((v460_a ^ -1) | (-(v460_a ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
      v482_a[v605_a] = v479_a;
      int * v484_a = (v403_p->a)->cache_tags;
      int v608_a = (int)((unsigned int)((int)((unsigned int)v407_a >> 2)) >> 1);
      v484_a[v582_a] = v608_a;
      int * v486_a = (v403_p->a)->cache_dirty;
      v486_a[v582_a] = 0;
      int * v488_a = (v403_p->a)->cache_age;
      v488_a[v582_a] = 1;
      int * v490_a = (v403_p->a)->cache_age;
      int v491_a = v490_a[v582_a];
      int * v492_a = (v403_p->a)->cache_age;
      int v493_a = v492_a[v545_a];
      int * v494_a = (v403_p->a)->cache_age;
      int v616_a = v493_a + ((int)((unsigned int)(v493_a - v491_a) >> 31));
      v494_a[v545_a] = v616_a;
      int * v496_a = (v403_p->a)->cache_age;
      int v497_a = v496_a[v547_a];
      int * v498_a = (v403_p->a)->cache_age;
      int v619_a = v497_a + ((int)((unsigned int)(v497_a - v491_a) >> 31));
      v498_a[v547_a] = v619_a;
      int * v500_a = (v403_p->a)->cache_age;
      v500_a[v582_a] = 0;
      v503_a = v582_a;
    }
    int * v504_a = (v403_p->a)->cache_vals;
    int v622_a = v503_a * 2;
    int v505_a = v504_a[v622_a];
    int * v506_a = (v403_p->a)->cache_vals;
    int v624_a = (v503_a * 2) + 1;
    int v507_a = v506_a[v624_a];
    int * v508_a = (v403_p->a)->cache_vals;
    int v626_a = (((((int)((unsigned int)((int)((unsigned int)v407_a >> 2)) >> 1)) & 1) * 2) + ((((v433_a + ((~(((v435_a ^ -1) | (-(v435_a ^ -1))) >> 31)) & 2)) - (v437_a + ((~(((v439_a ^ -1) | (-(v439_a ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
    v508_a[v626_a] = v505_a;
    int * v510_a = (v403_p->a)->cache_vals;
    int v629_a = ((((((int)((unsigned int)((int)((unsigned int)v407_a >> 2)) >> 1)) & 1) * 2) + ((((v433_a + ((~(((v435_a ^ -1) | (-(v435_a ^ -1))) >> 31)) & 2)) - (v437_a + ((~(((v439_a ^ -1) | (-(v439_a ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
    v510_a[v629_a] = v507_a;
    int * v512_a = (v403_p->a)->cache_tags;
    int v632_a = ((((int)((unsigned int)((int)((unsigned int)v407_a >> 2)) >> 1)) & 1) * 2) + ((((v433_a + ((~(((v435_a ^ -1) | (-(v435_a ^ -1))) >> 31)) & 2)) - (v437_a + ((~(((v439_a ^ -1) | (-(v439_a ^ -1))) >> 31)) & 2))) >> 31) & 1);
    int v633_a = (int)((unsigned int)((int)((unsigned int)v407_a >> 2)) >> 1);
    v512_a[v632_a] = v633_a;
    int * v514_a = (v403_p->a)->cache_dirty;
    v514_a[v632_a] = 0;
    int * v516_a = (v403_p->a)->cache_age;
    v516_a[v632_a] = 1;
    int * v518_a = (v403_p->a)->cache_age;
    int v519_a = v518_a[v632_a];
    int * v520_a = (v403_p->a)->cache_age;
    int v521_a = v520_a[v541_a];
    int * v522_a = (v403_p->a)->cache_age;
    int v641_a = v521_a + ((int)((unsigned int)(v521_a - v519_a) >> 31));
    v522_a[v541_a] = v641_a;
    int * v524_a = (v403_p->a)->cache_age;
    int v525_a = v524_a[v543_a];
    int * v526_a = (v403_p->a)->cache_age;
    int v644_a = v525_a + ((int)((unsigned int)(v525_a - v519_a) >> 31));
    v526_a[v543_a] = v644_a;
    int * v528_a = (v403_p->a)->cache_age;
    v528_a[v632_a] = 0;
    v531_a = v632_a;
  }
  int v531_b;
  if (v549_b) {
    int * v419_b = (v403_p->b)->cache_age;
    int v551_b = ((((int)((unsigned int)((int)((unsigned int)v407_b >> 2)) >> 1)) & 1) * 2) + ((~(((v411_b ^ ((int)((unsigned int)((int)((unsigned int)v407_b >> 2)) >> 1))) | (-(v411_b ^ ((int)((unsigned int)((int)((unsigned int)v407_b >> 2)) >> 1))))) >> 31)) & 1);
    int v420_b = v419_b[v551_b];
    int * v421_b = (v403_p->b)->cache_age;
    int v422_b = v421_b[v541_b];
    int * v423_b = (v403_p->b)->cache_age;
    int v554_b = v422_b + ((int)((unsigned int)(v422_b - v420_b) >> 31));
    v423_b[v541_b] = v554_b;
    int * v425_b = (v403_p->b)->cache_age;
    int v426_b = v425_b[v543_b];
    int * v427_b = (v403_p->b)->cache_age;
    int v557_b = v426_b + ((int)((unsigned int)(v426_b - v420_b) >> 31));
    v427_b[v543_b] = v557_b;
    int * v429_b = (v403_p->b)->cache_age;
    v429_b[v551_b] = 0;
    v531_b = v551_b;
  } else {
    int * v432_b = (v403_p->b)->cache_age;
    int v561_b = (((int)((unsigned int)((int)((unsigned int)v407_b >> 2)) >> 1)) & 1) * 2;
    int v433_b = v432_b[v561_b];
    int * v434_b = (v403_p->b)->cache_tags;
    int v435_b = v434_b[v561_b];
    int * v436_b = (v403_p->b)->cache_age;
    int v437_b = v436_b[v543_b];
    int * v438_b = (v403_p->b)->cache_tags;
    int v439_b = v438_b[v543_b];
    bool v565_b = !(((~(((v413_b ^ ((int)((unsigned int)((int)((unsigned int)v407_b >> 2)) >> 1))) | (-(v413_b ^ ((int)((unsigned int)((int)((unsigned int)v407_b >> 2)) >> 1))))) >> 31)) | (~(((v415_b ^ ((int)((unsigned int)((int)((unsigned int)v407_b >> 2)) >> 1))) | (-(v415_b ^ ((int)((unsigned int)((int)((unsigned int)v407_b >> 2)) >> 1))))) >> 31))) == 0);
    int v503_b;
    if (v565_b) {
      int * v440_b = (v403_p->b)->cache_age;
      int v567_b = (4 + ((((int)((unsigned int)((int)((unsigned int)v407_b >> 2)) >> 1)) & 3) * 2)) + ((~(((v415_b ^ ((int)((unsigned int)((int)((unsigned int)v407_b >> 2)) >> 1))) | (-(v415_b ^ ((int)((unsigned int)((int)((unsigned int)v407_b >> 2)) >> 1))))) >> 31)) & 1);
      int v441_b = v440_b[v567_b];
      int * v442_b = (v403_p->b)->cache_age;
      int v443_b = v442_b[v545_b];
      int * v444_b = (v403_p->b)->cache_age;
      int v570_b = v443_b + ((int)((unsigned int)(v443_b - v441_b) >> 31));
      v444_b[v545_b] = v570_b;
      int * v446_b = (v403_p->b)->cache_age;
      int v447_b = v446_b[v547_b];
      int * v448_b = (v403_p->b)->cache_age;
      int v573_b = v447_b + ((int)((unsigned int)(v447_b - v441_b) >> 31));
      v448_b[v547_b] = v573_b;
      int * v450_b = (v403_p->b)->cache_age;
      v450_b[v567_b] = 0;
      v503_b = v567_b;
    } else {
      int * v453_b = (v403_p->b)->cache_age;
      int v577_b = 4 + ((((int)((unsigned int)((int)((unsigned int)v407_b >> 2)) >> 1)) & 3) * 2);
      int v454_b = v453_b[v577_b];
      int * v455_b = (v403_p->b)->cache_tags;
      int v456_b = v455_b[v577_b];
      int * v457_b = (v403_p->b)->cache_age;
      int v458_b = v457_b[v547_b];
      int * v459_b = (v403_p->b)->cache_tags;
      int v460_b = v459_b[v547_b];
      int * v461_b = (v403_p->b)->cache_dirty;
      int v582_b = (4 + ((((int)((unsigned int)((int)((unsigned int)v407_b >> 2)) >> 1)) & 3) * 2)) + ((((v454_b + ((~(((v456_b ^ -1) | (-(v456_b ^ -1))) >> 31)) & 2)) - (v458_b + ((~(((v460_b ^ -1) | (-(v460_b ^ -1))) >> 31)) & 2))) >> 31) & 1);
      int v462_b = v461_b[v582_b];
      bool v583_b = !(v462_b == 0);
      if (v583_b) {
        int * v463_b = (v403_p->b)->cache_tags;
        int v464_b = v463_b[v582_b];
        int * v465_b = (v403_p->b)->cache_vals;
        int v586_b = ((4 + ((((int)((unsigned int)((int)((unsigned int)v407_b >> 2)) >> 1)) & 3) * 2)) + ((((v454_b + ((~(((v456_b ^ -1) | (-(v456_b ^ -1))) >> 31)) & 2)) - (v458_b + ((~(((v460_b ^ -1) | (-(v460_b ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
        int v466_b = v465_b[v586_b];
        int * v467_b = (v403_p->b)->cache_vals;
        int v588_b = (((4 + ((((int)((unsigned int)((int)((unsigned int)v407_b >> 2)) >> 1)) & 3) * 2)) + ((((v454_b + ((~(((v456_b ^ -1) | (-(v456_b ^ -1))) >> 31)) & 2)) - (v458_b + ((~(((v460_b ^ -1) | (-(v460_b ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
        int v468_b = v467_b[v588_b];
        int * v469_b = (v403_p->b)->mem;
        int v590_b = v464_b * 2;
        v469_b[v590_b] = v466_b;
        int * v471_b = (v403_p->b)->mem;
        int v593_b = (v464_b * 2) + 1;
        v471_b[v593_b] = v468_b;
        ;
      } else {
        ;
      }
      int * v476_b = (v403_p->b)->mem;
      int v598_b = ((int)((unsigned int)((int)((unsigned int)v407_b >> 2)) >> 1)) * 2;
      int v477_b = v476_b[v598_b];
      int * v478_b = (v403_p->b)->mem;
      int v600_b = (((int)((unsigned int)((int)((unsigned int)v407_b >> 2)) >> 1)) * 2) + 1;
      int v479_b = v478_b[v600_b];
      int * v480_b = (v403_p->b)->cache_vals;
      int v602_b = ((4 + ((((int)((unsigned int)((int)((unsigned int)v407_b >> 2)) >> 1)) & 3) * 2)) + ((((v454_b + ((~(((v456_b ^ -1) | (-(v456_b ^ -1))) >> 31)) & 2)) - (v458_b + ((~(((v460_b ^ -1) | (-(v460_b ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
      v480_b[v602_b] = v477_b;
      int * v482_b = (v403_p->b)->cache_vals;
      int v605_b = (((4 + ((((int)((unsigned int)((int)((unsigned int)v407_b >> 2)) >> 1)) & 3) * 2)) + ((((v454_b + ((~(((v456_b ^ -1) | (-(v456_b ^ -1))) >> 31)) & 2)) - (v458_b + ((~(((v460_b ^ -1) | (-(v460_b ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
      v482_b[v605_b] = v479_b;
      int * v484_b = (v403_p->b)->cache_tags;
      int v608_b = (int)((unsigned int)((int)((unsigned int)v407_b >> 2)) >> 1);
      v484_b[v582_b] = v608_b;
      int * v486_b = (v403_p->b)->cache_dirty;
      v486_b[v582_b] = 0;
      int * v488_b = (v403_p->b)->cache_age;
      v488_b[v582_b] = 1;
      int * v490_b = (v403_p->b)->cache_age;
      int v491_b = v490_b[v582_b];
      int * v492_b = (v403_p->b)->cache_age;
      int v493_b = v492_b[v545_b];
      int * v494_b = (v403_p->b)->cache_age;
      int v616_b = v493_b + ((int)((unsigned int)(v493_b - v491_b) >> 31));
      v494_b[v545_b] = v616_b;
      int * v496_b = (v403_p->b)->cache_age;
      int v497_b = v496_b[v547_b];
      int * v498_b = (v403_p->b)->cache_age;
      int v619_b = v497_b + ((int)((unsigned int)(v497_b - v491_b) >> 31));
      v498_b[v547_b] = v619_b;
      int * v500_b = (v403_p->b)->cache_age;
      v500_b[v582_b] = 0;
      v503_b = v582_b;
    }
    int * v504_b = (v403_p->b)->cache_vals;
    int v622_b = v503_b * 2;
    int v505_b = v504_b[v622_b];
    int * v506_b = (v403_p->b)->cache_vals;
    int v624_b = (v503_b * 2) + 1;
    int v507_b = v506_b[v624_b];
    int * v508_b = (v403_p->b)->cache_vals;
    int v626_b = (((((int)((unsigned int)((int)((unsigned int)v407_b >> 2)) >> 1)) & 1) * 2) + ((((v433_b + ((~(((v435_b ^ -1) | (-(v435_b ^ -1))) >> 31)) & 2)) - (v437_b + ((~(((v439_b ^ -1) | (-(v439_b ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
    v508_b[v626_b] = v505_b;
    int * v510_b = (v403_p->b)->cache_vals;
    int v629_b = ((((((int)((unsigned int)((int)((unsigned int)v407_b >> 2)) >> 1)) & 1) * 2) + ((((v433_b + ((~(((v435_b ^ -1) | (-(v435_b ^ -1))) >> 31)) & 2)) - (v437_b + ((~(((v439_b ^ -1) | (-(v439_b ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
    v510_b[v629_b] = v507_b;
    int * v512_b = (v403_p->b)->cache_tags;
    int v632_b = ((((int)((unsigned int)((int)((unsigned int)v407_b >> 2)) >> 1)) & 1) * 2) + ((((v433_b + ((~(((v435_b ^ -1) | (-(v435_b ^ -1))) >> 31)) & 2)) - (v437_b + ((~(((v439_b ^ -1) | (-(v439_b ^ -1))) >> 31)) & 2))) >> 31) & 1);
    int v633_b = (int)((unsigned int)((int)((unsigned int)v407_b >> 2)) >> 1);
    v512_b[v632_b] = v633_b;
    int * v514_b = (v403_p->b)->cache_dirty;
    v514_b[v632_b] = 0;
    int * v516_b = (v403_p->b)->cache_age;
    v516_b[v632_b] = 1;
    int * v518_b = (v403_p->b)->cache_age;
    int v519_b = v518_b[v632_b];
    int * v520_b = (v403_p->b)->cache_age;
    int v521_b = v520_b[v541_b];
    int * v522_b = (v403_p->b)->cache_age;
    int v641_b = v521_b + ((int)((unsigned int)(v521_b - v519_b) >> 31));
    v522_b[v541_b] = v641_b;
    int * v524_b = (v403_p->b)->cache_age;
    int v525_b = v524_b[v543_b];
    int * v526_b = (v403_p->b)->cache_age;
    int v644_b = v525_b + ((int)((unsigned int)(v525_b - v519_b) >> 31));
    v526_b[v543_b] = v644_b;
    int * v528_b = (v403_p->b)->cache_age;
    v528_b[v632_b] = 0;
    v531_b = v632_b;
  }
  int v647_a = (v531_a * 2) + (((int)((unsigned int)v407_a >> 2)) & 1);
  int v647_b = (v531_b * 2) + (((int)((unsigned int)v407_b >> 2)) & 1);
  int v532_a = v418_a[v647_a];
  int v532_b = v418_b[v647_b];
  int * v533_a = (v403_p->a)->regs;
  int * v533_b = (v403_p->b)->regs;
  v533_a[9] = v532_a;
  v533_b[9] = v532_b;
  struct StateT2 * v535_p = slot_10(v403_p);
  return v535_p;
}

struct StateT2 * slot_11(struct StateT2 * v674_p) {
  lockstep_assert(((v674_p->a)->timer) == ((v674_p->b)->timer));
  lockstep_assume(((v674_p->a)->timer) == ((v674_p->b)->timer));
  int v675_a = (v674_p->a)->timer;
  int v675_b = (v674_p->b)->timer;
  int v685_a = v675_a + 1;
  int v685_b = v675_b + 1;
  (v674_p->a)->timer = v685_a;
  (v674_p->b)->timer = v685_b;
  int * v677_a = (v674_p->a)->regs;
  int * v677_b = (v674_p->b)->regs;
  int v678_a = v677_a[5];
  int v678_b = v677_b[5];
  int * v679_a = (v674_p->a)->regs;
  int * v679_b = (v674_p->b)->regs;
  int v680_a = v679_a[16];
  int v680_b = v679_b[16];
  int * v681_a = (v674_p->a)->regs;
  int * v681_b = (v674_p->b)->regs;
  int v691_a = v678_a | v680_a;
  int v691_b = v678_b | v680_b;
  v681_a[5] = v691_a;
  v681_b[5] = v691_b;
  struct StateT2 * v683_p = slot_12(v674_p);
  return v683_p;
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