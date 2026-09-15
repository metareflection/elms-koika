// verify: clean (KLEE should report no failing assertion) [budget 120s]
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

struct StateT2 * slot_12(struct StateT2 * v404_p);
struct StateT2 * slot_14(struct StateT2 * v91_p);
struct StateT2 * slot_6(struct StateT2 * v111_p);
struct StateT2 * slot_5(struct StateT2 * v67_p);
struct StateT2 * slot_2(struct StateT2 * v28_p);
struct StateT2 * slot_7(struct StateT2 * v132_p);
struct StateT2 * slot_3(struct StateT2 * v41_p);
struct StateT2 * snippet(struct StateT2 * v0_p);
struct StateT2 * slot_10(struct StateT2 * v363_p);
struct StateT2 * slot_1(struct StateT2 * v15_p);
struct StateT2 * slot_8(struct StateT2 * v237_p);
struct StateT2 * slot_4(struct StateT2 * v54_p);
struct StateT2 * slot_13(struct StateT2 * v420_p);
struct StateT2 * slot_9(struct StateT2 * v258_p);
struct StateT2 * slot_11(struct StateT2 * v384_p);
struct StateT2 * slot_0(struct StateT2 * v2_p);
struct StateT2 * slot_12(struct StateT2 * v404_p) {
  lockstep_assert(((v404_p->a)->timer) == ((v404_p->b)->timer));
  lockstep_assume(((v404_p->a)->timer) == ((v404_p->b)->timer));
  int v405_a = (v404_p->a)->timer;
  int v405_b = (v404_p->b)->timer;
  int v413_a = v405_a + 1;
  int v413_b = v405_b + 1;
  (v404_p->a)->timer = v413_a;
  (v404_p->b)->timer = v413_b;
  int * v407_a = (v404_p->a)->regs;
  int * v407_b = (v404_p->b)->regs;
  int v408_a = v407_a[14];
  int v408_b = v407_b[14];
  int * v409_a = (v404_p->a)->regs;
  int * v409_b = (v404_p->b)->regs;
  int v417_a = v408_a + 4;
  int v417_b = v408_b + 4;
  v409_a[14] = v417_a;
  v409_b[14] = v417_b;
  struct StateT2 * v411_p = slot_13(v404_p);
  return v411_p;
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
  int v191_a = v133_a + 1;
  int v191_b = v133_b + 1;
  (v132_p->a)->timer = v191_a;
  (v132_p->b)->timer = v191_b;
  int * v135_a = (v132_p->a)->regs;
  int * v135_b = (v132_p->b)->regs;
  int v136_a = v135_a[6];
  int v136_b = v135_b[6];
  int * v137_a = (v132_p->a)->cache_keys;
  int * v137_b = (v132_p->b)->cache_keys;
  int v138_a = v137_a[0];
  int v138_b = v137_b[0];
  bool v196_a = v138_a == ((int)((unsigned int)v136_a >> 2));
  bool v196_b = v138_b == ((int)((unsigned int)v136_b >> 2));
  int v186_a;
  if (v196_a) {
    int * v139_a = (v132_p->a)->cache_vals;
    int v140_a = v139_a[0];
    v186_a = v140_a;
  } else {
    int * v142_a = (v132_p->a)->cache_keys;
    int v143_a = v142_a[1];
    bool v201_a = v143_a == ((int)((unsigned int)v136_a >> 2));
    int v184_a;
    if (v201_a) {
      int * v144_a = (v132_p->a)->cache_vals;
      int v145_a = v144_a[1];
      int * v146_a = (v132_p->a)->cache_keys;
      int * v147_a = (v132_p->a)->cache_keys;
      int v148_a = v147_a[0];
      v146_a[1] = v148_a;
      int * v150_a = (v132_p->a)->cache_vals;
      int * v151_a = (v132_p->a)->cache_vals;
      int v152_a = v151_a[0];
      v150_a[1] = v152_a;
      int * v154_a = (v132_p->a)->cache_keys;
      int v210_a = (int)((unsigned int)v136_a >> 2);
      v154_a[0] = v210_a;
      int * v156_a = (v132_p->a)->cache_vals;
      v156_a[0] = v145_a;
      int v158_a = (v132_p->a)->timer;
      int v213_a = v158_a + 1;
      (v132_p->a)->timer = v213_a;
      v184_a = v145_a;
    } else {
      int * v161_a = (v132_p->a)->mem;
      int v215_a = (int)((unsigned int)v136_a >> 2);
      int v162_a = v161_a[v215_a];
      int * v163_a = (v132_p->a)->mem;
      int * v164_a = (v132_p->a)->cache_keys;
      int v165_a = v164_a[1];
      int * v166_a = (v132_p->a)->cache_vals;
      int v167_a = v166_a[1];
      v163_a[v165_a] = v167_a;
      int * v169_a = (v132_p->a)->cache_keys;
      int * v170_a = (v132_p->a)->cache_keys;
      int v171_a = v170_a[0];
      v169_a[1] = v171_a;
      int * v173_a = (v132_p->a)->cache_vals;
      int * v174_a = (v132_p->a)->cache_vals;
      int v175_a = v174_a[0];
      v173_a[1] = v175_a;
      int * v177_a = (v132_p->a)->cache_keys;
      v177_a[0] = v215_a;
      int * v179_a = (v132_p->a)->cache_vals;
      v179_a[0] = v162_a;
      int v181_a = (v132_p->a)->timer;
      int v230_a = v181_a + 100;
      (v132_p->a)->timer = v230_a;
      v184_a = v162_a;
    }
    v186_a = v184_a;
  }
  int v186_b;
  if (v196_b) {
    int * v139_b = (v132_p->b)->cache_vals;
    int v140_b = v139_b[0];
    v186_b = v140_b;
  } else {
    int * v142_b = (v132_p->b)->cache_keys;
    int v143_b = v142_b[1];
    bool v201_b = v143_b == ((int)((unsigned int)v136_b >> 2));
    int v184_b;
    if (v201_b) {
      int * v144_b = (v132_p->b)->cache_vals;
      int v145_b = v144_b[1];
      int * v146_b = (v132_p->b)->cache_keys;
      int * v147_b = (v132_p->b)->cache_keys;
      int v148_b = v147_b[0];
      v146_b[1] = v148_b;
      int * v150_b = (v132_p->b)->cache_vals;
      int * v151_b = (v132_p->b)->cache_vals;
      int v152_b = v151_b[0];
      v150_b[1] = v152_b;
      int * v154_b = (v132_p->b)->cache_keys;
      int v210_b = (int)((unsigned int)v136_b >> 2);
      v154_b[0] = v210_b;
      int * v156_b = (v132_p->b)->cache_vals;
      v156_b[0] = v145_b;
      int v158_b = (v132_p->b)->timer;
      int v213_b = v158_b + 1;
      (v132_p->b)->timer = v213_b;
      v184_b = v145_b;
    } else {
      int * v161_b = (v132_p->b)->mem;
      int v215_b = (int)((unsigned int)v136_b >> 2);
      int v162_b = v161_b[v215_b];
      int * v163_b = (v132_p->b)->mem;
      int * v164_b = (v132_p->b)->cache_keys;
      int v165_b = v164_b[1];
      int * v166_b = (v132_p->b)->cache_vals;
      int v167_b = v166_b[1];
      v163_b[v165_b] = v167_b;
      int * v169_b = (v132_p->b)->cache_keys;
      int * v170_b = (v132_p->b)->cache_keys;
      int v171_b = v170_b[0];
      v169_b[1] = v171_b;
      int * v173_b = (v132_p->b)->cache_vals;
      int * v174_b = (v132_p->b)->cache_vals;
      int v175_b = v174_b[0];
      v173_b[1] = v175_b;
      int * v177_b = (v132_p->b)->cache_keys;
      v177_b[0] = v215_b;
      int * v179_b = (v132_p->b)->cache_vals;
      v179_b[0] = v162_b;
      int v181_b = (v132_p->b)->timer;
      int v230_b = v181_b + 100;
      (v132_p->b)->timer = v230_b;
      v184_b = v162_b;
    }
    v186_b = v184_b;
  }
  int * v187_a = (v132_p->a)->regs;
  int * v187_b = (v132_p->b)->regs;
  v187_a[7] = v186_a;
  v187_b[7] = v186_b;
  struct StateT2 * v189_p = slot_8(v132_p);
  return v189_p;
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

struct StateT2 * slot_10(struct StateT2 * v363_p) {
  lockstep_assert(((v363_p->a)->timer) == ((v363_p->b)->timer));
  lockstep_assume(((v363_p->a)->timer) == ((v363_p->b)->timer));
  int v364_a = (v363_p->a)->timer;
  int v364_b = (v363_p->b)->timer;
  int v374_a = v364_a + 1;
  int v374_b = v364_b + 1;
  (v363_p->a)->timer = v374_a;
  (v363_p->b)->timer = v374_b;
  int * v366_a = (v363_p->a)->regs;
  int * v366_b = (v363_p->b)->regs;
  int v367_a = v366_a[7];
  int v367_b = v366_b[7];
  int * v368_a = (v363_p->a)->regs;
  int * v368_b = (v363_p->b)->regs;
  int v369_a = v368_a[9];
  int v369_b = v368_b[9];
  int * v370_a = (v363_p->a)->regs;
  int * v370_b = (v363_p->b)->regs;
  int v381_a = v367_a ^ v369_a;
  int v381_b = v367_b ^ v369_b;
  v370_a[16] = v381_a;
  v370_b[16] = v381_b;
  struct StateT2 * v372_p = slot_11(v363_p);
  return v372_p;
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

struct StateT2 * slot_8(struct StateT2 * v237_p) {
  lockstep_assert(((v237_p->a)->timer) == ((v237_p->b)->timer));
  lockstep_assume(((v237_p->a)->timer) == ((v237_p->b)->timer));
  int v238_a = (v237_p->a)->timer;
  int v238_b = (v237_p->b)->timer;
  int v248_a = v238_a + 1;
  int v248_b = v238_b + 1;
  (v237_p->a)->timer = v248_a;
  (v237_p->b)->timer = v248_b;
  int * v240_a = (v237_p->a)->regs;
  int * v240_b = (v237_p->b)->regs;
  int v241_a = v240_a[13];
  int v241_b = v240_b[13];
  int * v242_a = (v237_p->a)->regs;
  int * v242_b = (v237_p->b)->regs;
  int v243_a = v242_a[14];
  int v243_b = v242_b[14];
  int * v244_a = (v237_p->a)->regs;
  int * v244_b = (v237_p->b)->regs;
  int v255_a = v241_a + v243_a;
  int v255_b = v241_b + v243_b;
  v244_a[8] = v255_a;
  v244_b[8] = v255_b;
  struct StateT2 * v246_p = slot_9(v237_p);
  return v246_p;
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

struct StateT2 * slot_13(struct StateT2 * v420_p) {
  lockstep_assert(((v420_p->a)->timer) == ((v420_p->b)->timer));
  lockstep_assume(((v420_p->a)->timer) == ((v420_p->b)->timer));
  int v421_a = (v420_p->a)->timer;
  int v421_b = (v420_p->b)->timer;
  int v425_a = v421_a + 1;
  int v425_b = v421_b + 1;
  (v420_p->a)->timer = v425_a;
  (v420_p->b)->timer = v425_b;
  struct StateT2 * v423_p = slot_5(v420_p);
  return v423_p;
}

struct StateT2 * slot_9(struct StateT2 * v258_p) {
  lockstep_assert(((v258_p->a)->timer) == ((v258_p->b)->timer));
  lockstep_assume(((v258_p->a)->timer) == ((v258_p->b)->timer));
  int v259_a = (v258_p->a)->timer;
  int v259_b = (v258_p->b)->timer;
  int v317_a = v259_a + 1;
  int v317_b = v259_b + 1;
  (v258_p->a)->timer = v317_a;
  (v258_p->b)->timer = v317_b;
  int * v261_a = (v258_p->a)->regs;
  int * v261_b = (v258_p->b)->regs;
  int v262_a = v261_a[8];
  int v262_b = v261_b[8];
  int * v263_a = (v258_p->a)->cache_keys;
  int * v263_b = (v258_p->b)->cache_keys;
  int v264_a = v263_a[0];
  int v264_b = v263_b[0];
  bool v322_a = v264_a == ((int)((unsigned int)v262_a >> 2));
  bool v322_b = v264_b == ((int)((unsigned int)v262_b >> 2));
  int v312_a;
  if (v322_a) {
    int * v265_a = (v258_p->a)->cache_vals;
    int v266_a = v265_a[0];
    v312_a = v266_a;
  } else {
    int * v268_a = (v258_p->a)->cache_keys;
    int v269_a = v268_a[1];
    bool v327_a = v269_a == ((int)((unsigned int)v262_a >> 2));
    int v310_a;
    if (v327_a) {
      int * v270_a = (v258_p->a)->cache_vals;
      int v271_a = v270_a[1];
      int * v272_a = (v258_p->a)->cache_keys;
      int * v273_a = (v258_p->a)->cache_keys;
      int v274_a = v273_a[0];
      v272_a[1] = v274_a;
      int * v276_a = (v258_p->a)->cache_vals;
      int * v277_a = (v258_p->a)->cache_vals;
      int v278_a = v277_a[0];
      v276_a[1] = v278_a;
      int * v280_a = (v258_p->a)->cache_keys;
      int v336_a = (int)((unsigned int)v262_a >> 2);
      v280_a[0] = v336_a;
      int * v282_a = (v258_p->a)->cache_vals;
      v282_a[0] = v271_a;
      int v284_a = (v258_p->a)->timer;
      int v339_a = v284_a + 1;
      (v258_p->a)->timer = v339_a;
      v310_a = v271_a;
    } else {
      int * v287_a = (v258_p->a)->mem;
      int v341_a = (int)((unsigned int)v262_a >> 2);
      int v288_a = v287_a[v341_a];
      int * v289_a = (v258_p->a)->mem;
      int * v290_a = (v258_p->a)->cache_keys;
      int v291_a = v290_a[1];
      int * v292_a = (v258_p->a)->cache_vals;
      int v293_a = v292_a[1];
      v289_a[v291_a] = v293_a;
      int * v295_a = (v258_p->a)->cache_keys;
      int * v296_a = (v258_p->a)->cache_keys;
      int v297_a = v296_a[0];
      v295_a[1] = v297_a;
      int * v299_a = (v258_p->a)->cache_vals;
      int * v300_a = (v258_p->a)->cache_vals;
      int v301_a = v300_a[0];
      v299_a[1] = v301_a;
      int * v303_a = (v258_p->a)->cache_keys;
      v303_a[0] = v341_a;
      int * v305_a = (v258_p->a)->cache_vals;
      v305_a[0] = v288_a;
      int v307_a = (v258_p->a)->timer;
      int v356_a = v307_a + 100;
      (v258_p->a)->timer = v356_a;
      v310_a = v288_a;
    }
    v312_a = v310_a;
  }
  int v312_b;
  if (v322_b) {
    int * v265_b = (v258_p->b)->cache_vals;
    int v266_b = v265_b[0];
    v312_b = v266_b;
  } else {
    int * v268_b = (v258_p->b)->cache_keys;
    int v269_b = v268_b[1];
    bool v327_b = v269_b == ((int)((unsigned int)v262_b >> 2));
    int v310_b;
    if (v327_b) {
      int * v270_b = (v258_p->b)->cache_vals;
      int v271_b = v270_b[1];
      int * v272_b = (v258_p->b)->cache_keys;
      int * v273_b = (v258_p->b)->cache_keys;
      int v274_b = v273_b[0];
      v272_b[1] = v274_b;
      int * v276_b = (v258_p->b)->cache_vals;
      int * v277_b = (v258_p->b)->cache_vals;
      int v278_b = v277_b[0];
      v276_b[1] = v278_b;
      int * v280_b = (v258_p->b)->cache_keys;
      int v336_b = (int)((unsigned int)v262_b >> 2);
      v280_b[0] = v336_b;
      int * v282_b = (v258_p->b)->cache_vals;
      v282_b[0] = v271_b;
      int v284_b = (v258_p->b)->timer;
      int v339_b = v284_b + 1;
      (v258_p->b)->timer = v339_b;
      v310_b = v271_b;
    } else {
      int * v287_b = (v258_p->b)->mem;
      int v341_b = (int)((unsigned int)v262_b >> 2);
      int v288_b = v287_b[v341_b];
      int * v289_b = (v258_p->b)->mem;
      int * v290_b = (v258_p->b)->cache_keys;
      int v291_b = v290_b[1];
      int * v292_b = (v258_p->b)->cache_vals;
      int v293_b = v292_b[1];
      v289_b[v291_b] = v293_b;
      int * v295_b = (v258_p->b)->cache_keys;
      int * v296_b = (v258_p->b)->cache_keys;
      int v297_b = v296_b[0];
      v295_b[1] = v297_b;
      int * v299_b = (v258_p->b)->cache_vals;
      int * v300_b = (v258_p->b)->cache_vals;
      int v301_b = v300_b[0];
      v299_b[1] = v301_b;
      int * v303_b = (v258_p->b)->cache_keys;
      v303_b[0] = v341_b;
      int * v305_b = (v258_p->b)->cache_vals;
      v305_b[0] = v288_b;
      int v307_b = (v258_p->b)->timer;
      int v356_b = v307_b + 100;
      (v258_p->b)->timer = v356_b;
      v310_b = v288_b;
    }
    v312_b = v310_b;
  }
  int * v313_a = (v258_p->a)->regs;
  int * v313_b = (v258_p->b)->regs;
  v313_a[9] = v312_a;
  v313_b[9] = v312_b;
  struct StateT2 * v315_p = slot_10(v258_p);
  return v315_p;
}

struct StateT2 * slot_11(struct StateT2 * v384_p) {
  lockstep_assert(((v384_p->a)->timer) == ((v384_p->b)->timer));
  lockstep_assume(((v384_p->a)->timer) == ((v384_p->b)->timer));
  int v385_a = (v384_p->a)->timer;
  int v385_b = (v384_p->b)->timer;
  int v395_a = v385_a + 1;
  int v395_b = v385_b + 1;
  (v384_p->a)->timer = v395_a;
  (v384_p->b)->timer = v395_b;
  int * v387_a = (v384_p->a)->regs;
  int * v387_b = (v384_p->b)->regs;
  int v388_a = v387_a[5];
  int v388_b = v387_b[5];
  int * v389_a = (v384_p->a)->regs;
  int * v389_b = (v384_p->b)->regs;
  int v390_a = v389_a[16];
  int v390_b = v389_b[16];
  int * v391_a = (v384_p->a)->regs;
  int * v391_b = (v384_p->b)->regs;
  int v401_a = v388_a | v390_a;
  int v401_b = v388_b | v390_b;
  v391_a[5] = v401_a;
  v391_b[5] = v401_b;
  struct StateT2 * v393_p = slot_12(v384_p);
  return v393_p;
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