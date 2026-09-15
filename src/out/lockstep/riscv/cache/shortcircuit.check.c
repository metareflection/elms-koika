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

struct StateT2 * slot_12(struct StateT2 * v364_p);
struct StateT2 * slot_14(struct StateT2 * v78_p);
struct StateT2 * slot_6(struct StateT2 * v109_p);
struct StateT2 * slot_5(struct StateT2 * v88_p);
struct StateT2 * slot_2(struct StateT2 * v28_p);
struct StateT2 * slot_7(struct StateT2 * v214_p);
struct StateT2 * slot_3(struct StateT2 * v41_p);
struct StateT2 * snippet(struct StateT2 * v0_p);
struct StateT2 * slot_10(struct StateT2 * v377_p);
struct StateT2 * slot_1(struct StateT2 * v15_p);
struct StateT2 * slot_8(struct StateT2 * v235_p);
struct StateT2 * slot_4(struct StateT2 * v54_p);
struct StateT2 * slot_13(struct StateT2 * v393_p);
struct StateT2 * slot_9(struct StateT2 * v340_p);
struct StateT2 * slot_11(struct StateT2 * v398_p);
struct StateT2 * slot_0(struct StateT2 * v2_p);
struct StateT2 * slot_12(struct StateT2 * v364_p) {
  lockstep_assert(((v364_p->a)->timer) == ((v364_p->b)->timer));
  lockstep_assume(((v364_p->a)->timer) == ((v364_p->b)->timer));
  int v365_a = (v364_p->a)->timer;
  int v365_b = (v364_p->b)->timer;
  int v371_a = v365_a + 1;
  int v371_b = v365_b + 1;
  (v364_p->a)->timer = v371_a;
  (v364_p->b)->timer = v371_b;
  int * v367_a = (v364_p->a)->regs;
  int * v367_b = (v364_p->b)->regs;
  v367_a[10] = 0;
  v367_b[10] = 0;
  struct StateT2 * v369_p = slot_13(v364_p);
  return v369_p;
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
  int v168_a = v110_a + 1;
  int v168_b = v110_b + 1;
  (v109_p->a)->timer = v168_a;
  (v109_p->b)->timer = v168_b;
  int * v112_a = (v109_p->a)->regs;
  int * v112_b = (v109_p->b)->regs;
  int v113_a = v112_a[5];
  int v113_b = v112_b[5];
  int * v114_a = (v109_p->a)->cache_keys;
  int * v114_b = (v109_p->b)->cache_keys;
  int v115_a = v114_a[0];
  int v115_b = v114_b[0];
  bool v173_a = v115_a == ((int)((unsigned int)v113_a >> 2));
  bool v173_b = v115_b == ((int)((unsigned int)v113_b >> 2));
  int v163_a;
  if (v173_a) {
    int * v116_a = (v109_p->a)->cache_vals;
    int v117_a = v116_a[0];
    v163_a = v117_a;
  } else {
    int * v119_a = (v109_p->a)->cache_keys;
    int v120_a = v119_a[1];
    bool v178_a = v120_a == ((int)((unsigned int)v113_a >> 2));
    int v161_a;
    if (v178_a) {
      int * v121_a = (v109_p->a)->cache_vals;
      int v122_a = v121_a[1];
      int * v123_a = (v109_p->a)->cache_keys;
      int * v124_a = (v109_p->a)->cache_keys;
      int v125_a = v124_a[0];
      v123_a[1] = v125_a;
      int * v127_a = (v109_p->a)->cache_vals;
      int * v128_a = (v109_p->a)->cache_vals;
      int v129_a = v128_a[0];
      v127_a[1] = v129_a;
      int * v131_a = (v109_p->a)->cache_keys;
      int v187_a = (int)((unsigned int)v113_a >> 2);
      v131_a[0] = v187_a;
      int * v133_a = (v109_p->a)->cache_vals;
      v133_a[0] = v122_a;
      int v135_a = (v109_p->a)->timer;
      int v190_a = v135_a + 1;
      (v109_p->a)->timer = v190_a;
      v161_a = v122_a;
    } else {
      int * v138_a = (v109_p->a)->mem;
      int v192_a = (int)((unsigned int)v113_a >> 2);
      int v139_a = v138_a[v192_a];
      int * v140_a = (v109_p->a)->mem;
      int * v141_a = (v109_p->a)->cache_keys;
      int v142_a = v141_a[1];
      int * v143_a = (v109_p->a)->cache_vals;
      int v144_a = v143_a[1];
      v140_a[v142_a] = v144_a;
      int * v146_a = (v109_p->a)->cache_keys;
      int * v147_a = (v109_p->a)->cache_keys;
      int v148_a = v147_a[0];
      v146_a[1] = v148_a;
      int * v150_a = (v109_p->a)->cache_vals;
      int * v151_a = (v109_p->a)->cache_vals;
      int v152_a = v151_a[0];
      v150_a[1] = v152_a;
      int * v154_a = (v109_p->a)->cache_keys;
      v154_a[0] = v192_a;
      int * v156_a = (v109_p->a)->cache_vals;
      v156_a[0] = v139_a;
      int v158_a = (v109_p->a)->timer;
      int v207_a = v158_a + 100;
      (v109_p->a)->timer = v207_a;
      v161_a = v139_a;
    }
    v163_a = v161_a;
  }
  int v163_b;
  if (v173_b) {
    int * v116_b = (v109_p->b)->cache_vals;
    int v117_b = v116_b[0];
    v163_b = v117_b;
  } else {
    int * v119_b = (v109_p->b)->cache_keys;
    int v120_b = v119_b[1];
    bool v178_b = v120_b == ((int)((unsigned int)v113_b >> 2));
    int v161_b;
    if (v178_b) {
      int * v121_b = (v109_p->b)->cache_vals;
      int v122_b = v121_b[1];
      int * v123_b = (v109_p->b)->cache_keys;
      int * v124_b = (v109_p->b)->cache_keys;
      int v125_b = v124_b[0];
      v123_b[1] = v125_b;
      int * v127_b = (v109_p->b)->cache_vals;
      int * v128_b = (v109_p->b)->cache_vals;
      int v129_b = v128_b[0];
      v127_b[1] = v129_b;
      int * v131_b = (v109_p->b)->cache_keys;
      int v187_b = (int)((unsigned int)v113_b >> 2);
      v131_b[0] = v187_b;
      int * v133_b = (v109_p->b)->cache_vals;
      v133_b[0] = v122_b;
      int v135_b = (v109_p->b)->timer;
      int v190_b = v135_b + 1;
      (v109_p->b)->timer = v190_b;
      v161_b = v122_b;
    } else {
      int * v138_b = (v109_p->b)->mem;
      int v192_b = (int)((unsigned int)v113_b >> 2);
      int v139_b = v138_b[v192_b];
      int * v140_b = (v109_p->b)->mem;
      int * v141_b = (v109_p->b)->cache_keys;
      int v142_b = v141_b[1];
      int * v143_b = (v109_p->b)->cache_vals;
      int v144_b = v143_b[1];
      v140_b[v142_b] = v144_b;
      int * v146_b = (v109_p->b)->cache_keys;
      int * v147_b = (v109_p->b)->cache_keys;
      int v148_b = v147_b[0];
      v146_b[1] = v148_b;
      int * v150_b = (v109_p->b)->cache_vals;
      int * v151_b = (v109_p->b)->cache_vals;
      int v152_b = v151_b[0];
      v150_b[1] = v152_b;
      int * v154_b = (v109_p->b)->cache_keys;
      v154_b[0] = v192_b;
      int * v156_b = (v109_p->b)->cache_vals;
      v156_b[0] = v139_b;
      int v158_b = (v109_p->b)->timer;
      int v207_b = v158_b + 100;
      (v109_p->b)->timer = v207_b;
      v161_b = v139_b;
    }
    v163_b = v161_b;
  }
  int * v164_a = (v109_p->a)->regs;
  int * v164_b = (v109_p->b)->regs;
  v164_a[10] = v163_a;
  v164_b[10] = v163_b;
  struct StateT2 * v166_p = slot_7(v109_p);
  return v166_p;
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

struct StateT2 * slot_7(struct StateT2 * v214_p) {
  lockstep_assert(((v214_p->a)->timer) == ((v214_p->b)->timer));
  lockstep_assume(((v214_p->a)->timer) == ((v214_p->b)->timer));
  int v215_a = (v214_p->a)->timer;
  int v215_b = (v214_p->b)->timer;
  int v225_a = v215_a + 1;
  int v225_b = v215_b + 1;
  (v214_p->a)->timer = v225_a;
  (v214_p->b)->timer = v225_b;
  int * v217_a = (v214_p->a)->regs;
  int * v217_b = (v214_p->b)->regs;
  int v218_a = v217_a[13];
  int v218_b = v217_b[13];
  int * v219_a = (v214_p->a)->regs;
  int * v219_b = (v214_p->b)->regs;
  int v220_a = v219_a[14];
  int v220_b = v219_b[14];
  int * v221_a = (v214_p->a)->regs;
  int * v221_b = (v214_p->b)->regs;
  int v232_a = v218_a + v220_a;
  int v232_b = v218_b + v220_b;
  v221_a[6] = v232_a;
  v221_b[6] = v232_b;
  struct StateT2 * v223_p = slot_8(v214_p);
  return v223_p;
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

struct StateT2 * slot_10(struct StateT2 * v377_p) {
  lockstep_assert(((v377_p->a)->timer) == ((v377_p->b)->timer));
  lockstep_assume(((v377_p->a)->timer) == ((v377_p->b)->timer));
  int v378_a = (v377_p->a)->timer;
  int v378_b = (v377_p->b)->timer;
  int v386_a = v378_a + 1;
  int v386_b = v378_b + 1;
  (v377_p->a)->timer = v386_a;
  (v377_p->b)->timer = v386_b;
  int * v380_a = (v377_p->a)->regs;
  int * v380_b = (v377_p->b)->regs;
  int v381_a = v380_a[14];
  int v381_b = v380_b[14];
  int * v382_a = (v377_p->a)->regs;
  int * v382_b = (v377_p->b)->regs;
  int v390_a = v381_a + 4;
  int v390_b = v381_b + 4;
  v382_a[14] = v390_a;
  v382_b[14] = v390_b;
  struct StateT2 * v384_p = slot_11(v377_p);
  return v384_p;
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

struct StateT2 * slot_8(struct StateT2 * v235_p) {
  lockstep_assert(((v235_p->a)->timer) == ((v235_p->b)->timer));
  lockstep_assume(((v235_p->a)->timer) == ((v235_p->b)->timer));
  int v236_a = (v235_p->a)->timer;
  int v236_b = (v235_p->b)->timer;
  int v294_a = v236_a + 1;
  int v294_b = v236_b + 1;
  (v235_p->a)->timer = v294_a;
  (v235_p->b)->timer = v294_b;
  int * v238_a = (v235_p->a)->regs;
  int * v238_b = (v235_p->b)->regs;
  int v239_a = v238_a[6];
  int v239_b = v238_b[6];
  int * v240_a = (v235_p->a)->cache_keys;
  int * v240_b = (v235_p->b)->cache_keys;
  int v241_a = v240_a[0];
  int v241_b = v240_b[0];
  bool v299_a = v241_a == ((int)((unsigned int)v239_a >> 2));
  bool v299_b = v241_b == ((int)((unsigned int)v239_b >> 2));
  int v289_a;
  if (v299_a) {
    int * v242_a = (v235_p->a)->cache_vals;
    int v243_a = v242_a[0];
    v289_a = v243_a;
  } else {
    int * v245_a = (v235_p->a)->cache_keys;
    int v246_a = v245_a[1];
    bool v304_a = v246_a == ((int)((unsigned int)v239_a >> 2));
    int v287_a;
    if (v304_a) {
      int * v247_a = (v235_p->a)->cache_vals;
      int v248_a = v247_a[1];
      int * v249_a = (v235_p->a)->cache_keys;
      int * v250_a = (v235_p->a)->cache_keys;
      int v251_a = v250_a[0];
      v249_a[1] = v251_a;
      int * v253_a = (v235_p->a)->cache_vals;
      int * v254_a = (v235_p->a)->cache_vals;
      int v255_a = v254_a[0];
      v253_a[1] = v255_a;
      int * v257_a = (v235_p->a)->cache_keys;
      int v313_a = (int)((unsigned int)v239_a >> 2);
      v257_a[0] = v313_a;
      int * v259_a = (v235_p->a)->cache_vals;
      v259_a[0] = v248_a;
      int v261_a = (v235_p->a)->timer;
      int v316_a = v261_a + 1;
      (v235_p->a)->timer = v316_a;
      v287_a = v248_a;
    } else {
      int * v264_a = (v235_p->a)->mem;
      int v318_a = (int)((unsigned int)v239_a >> 2);
      int v265_a = v264_a[v318_a];
      int * v266_a = (v235_p->a)->mem;
      int * v267_a = (v235_p->a)->cache_keys;
      int v268_a = v267_a[1];
      int * v269_a = (v235_p->a)->cache_vals;
      int v270_a = v269_a[1];
      v266_a[v268_a] = v270_a;
      int * v272_a = (v235_p->a)->cache_keys;
      int * v273_a = (v235_p->a)->cache_keys;
      int v274_a = v273_a[0];
      v272_a[1] = v274_a;
      int * v276_a = (v235_p->a)->cache_vals;
      int * v277_a = (v235_p->a)->cache_vals;
      int v278_a = v277_a[0];
      v276_a[1] = v278_a;
      int * v280_a = (v235_p->a)->cache_keys;
      v280_a[0] = v318_a;
      int * v282_a = (v235_p->a)->cache_vals;
      v282_a[0] = v265_a;
      int v284_a = (v235_p->a)->timer;
      int v333_a = v284_a + 100;
      (v235_p->a)->timer = v333_a;
      v287_a = v265_a;
    }
    v289_a = v287_a;
  }
  int v289_b;
  if (v299_b) {
    int * v242_b = (v235_p->b)->cache_vals;
    int v243_b = v242_b[0];
    v289_b = v243_b;
  } else {
    int * v245_b = (v235_p->b)->cache_keys;
    int v246_b = v245_b[1];
    bool v304_b = v246_b == ((int)((unsigned int)v239_b >> 2));
    int v287_b;
    if (v304_b) {
      int * v247_b = (v235_p->b)->cache_vals;
      int v248_b = v247_b[1];
      int * v249_b = (v235_p->b)->cache_keys;
      int * v250_b = (v235_p->b)->cache_keys;
      int v251_b = v250_b[0];
      v249_b[1] = v251_b;
      int * v253_b = (v235_p->b)->cache_vals;
      int * v254_b = (v235_p->b)->cache_vals;
      int v255_b = v254_b[0];
      v253_b[1] = v255_b;
      int * v257_b = (v235_p->b)->cache_keys;
      int v313_b = (int)((unsigned int)v239_b >> 2);
      v257_b[0] = v313_b;
      int * v259_b = (v235_p->b)->cache_vals;
      v259_b[0] = v248_b;
      int v261_b = (v235_p->b)->timer;
      int v316_b = v261_b + 1;
      (v235_p->b)->timer = v316_b;
      v287_b = v248_b;
    } else {
      int * v264_b = (v235_p->b)->mem;
      int v318_b = (int)((unsigned int)v239_b >> 2);
      int v265_b = v264_b[v318_b];
      int * v266_b = (v235_p->b)->mem;
      int * v267_b = (v235_p->b)->cache_keys;
      int v268_b = v267_b[1];
      int * v269_b = (v235_p->b)->cache_vals;
      int v270_b = v269_b[1];
      v266_b[v268_b] = v270_b;
      int * v272_b = (v235_p->b)->cache_keys;
      int * v273_b = (v235_p->b)->cache_keys;
      int v274_b = v273_b[0];
      v272_b[1] = v274_b;
      int * v276_b = (v235_p->b)->cache_vals;
      int * v277_b = (v235_p->b)->cache_vals;
      int v278_b = v277_b[0];
      v276_b[1] = v278_b;
      int * v280_b = (v235_p->b)->cache_keys;
      v280_b[0] = v318_b;
      int * v282_b = (v235_p->b)->cache_vals;
      v282_b[0] = v265_b;
      int v284_b = (v235_p->b)->timer;
      int v333_b = v284_b + 100;
      (v235_p->b)->timer = v333_b;
      v287_b = v265_b;
    }
    v289_b = v287_b;
  }
  int * v290_a = (v235_p->a)->regs;
  int * v290_b = (v235_p->b)->regs;
  v290_a[11] = v289_a;
  v290_b[11] = v289_b;
  struct StateT2 * v292_p = slot_9(v235_p);
  return v292_p;
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

struct StateT2 * slot_13(struct StateT2 * v393_p) {
  lockstep_assert(((v393_p->a)->timer) == ((v393_p->b)->timer));
  lockstep_assume(((v393_p->a)->timer) == ((v393_p->b)->timer));
  int v394_a = (v393_p->a)->timer;
  int v394_b = (v393_p->b)->timer;
  int v397_a = v394_a + 1;
  int v397_b = v394_b + 1;
  (v393_p->a)->timer = v397_a;
  (v393_p->b)->timer = v397_b;
  return v393_p;
}

struct StateT2 * slot_9(struct StateT2 * v340_p) {
  lockstep_assert(((v340_p->a)->timer) == ((v340_p->b)->timer));
  lockstep_assume(((v340_p->a)->timer) == ((v340_p->b)->timer));
  int v341_a = (v340_p->a)->timer;
  int v341_b = (v340_p->b)->timer;
  int v353_a = v341_a + 1;
  int v353_b = v341_b + 1;
  (v340_p->a)->timer = v353_a;
  (v340_p->b)->timer = v353_b;
  int * v343_a = (v340_p->a)->regs;
  int * v343_b = (v340_p->b)->regs;
  int v344_a = v343_a[10];
  int v344_b = v343_b[10];
  int * v345_a = (v340_p->a)->regs;
  int * v345_b = (v340_p->b)->regs;
  int v346_a = v345_a[11];
  int v346_b = v345_b[11];
  bool v358_a = !(v344_a == v346_a);
  bool v358_b = !(v344_b == v346_b);
  lockstep_assert(v358_a == v358_b);
  lockstep_assume(v358_a == v358_b);
  struct StateT2 * v351_p;
  if (v358_a) {
    struct StateT2 * v347_p = slot_12(v340_p);
    v351_p = v347_p;
  } else {
    struct StateT2 * v349_p = slot_10(v340_p);
    v351_p = v349_p;
  }
  return v351_p;
}

struct StateT2 * slot_11(struct StateT2 * v398_p) {
  lockstep_assert(((v398_p->a)->timer) == ((v398_p->b)->timer));
  lockstep_assume(((v398_p->a)->timer) == ((v398_p->b)->timer));
  int v399_a = (v398_p->a)->timer;
  int v399_b = (v398_p->b)->timer;
  int v403_a = v399_a + 1;
  int v403_b = v399_b + 1;
  (v398_p->a)->timer = v403_a;
  (v398_p->b)->timer = v403_b;
  struct StateT2 * v401_p = slot_4(v398_p);
  return v401_p;
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

void lockstep_assert(bool c) { __CPROVER_assert(c, "lockstep drift"); }
void lockstep_assume(bool c) { __CPROVER_assume(c); }

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
  __CPROVER_assert(p_->a->timer==p_->b->timer, "timing leak");
  return 0;
}