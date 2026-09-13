// verify: leak (CBMC should report VERIFICATION FAILED)

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

struct StateT {
  int regs[32];
  int mem[30];
  int saved_regs[32];
  int cache_keys[10];
  int cache_vals[10];
  int timer;
};

struct StateT * slot_12(struct StateT * v196);
struct StateT * slot_14(struct StateT * v78);
struct StateT * slot_6(struct StateT * v109);
struct StateT * slot_5(struct StateT * v88);
struct StateT * slot_2(struct StateT * v28);
struct StateT * slot_7(struct StateT * v130);
struct StateT * slot_3(struct StateT * v41);
struct StateT * snippet(struct StateT * v0);
struct StateT * slot_10(struct StateT * v209);
struct StateT * slot_1(struct StateT * v15);
struct StateT * slot_8(struct StateT * v151);
struct StateT * slot_4(struct StateT * v54);
struct StateT * slot_13(struct StateT * v225);
struct StateT * slot_9(struct StateT * v172);
struct StateT * slot_11(struct StateT * v230);
struct StateT * slot_0(struct StateT * v2);
struct StateT * slot_12(struct StateT * v196) {
  int v197 = v196->timer;
  int v203 = v197 + 1;
  v196->timer = v203;
  int * v199 = v196->regs;
  v199[10] = 0;
  struct StateT * v201 = slot_13(v196);
  return v201;
}

struct StateT * slot_14(struct StateT * v78) {
  int v79 = v78->timer;
  int v84 = v79 + 1;
  v78->timer = v84;
  int * v81 = v78->regs;
  v81[10] = 1;
  return v78;
}

struct StateT * slot_6(struct StateT * v109) {
  int v110 = v109->timer;
  int v120 = v110 + 1;
  v109->timer = v120;
  int * v112 = v109->regs;
  int v113 = v112[5];
  int * v114 = v109->mem;
  int v124 = (int)((unsigned int)v113 >> 2);
  int v115 = v114[v124];
  int * v116 = v109->regs;
  v116[10] = v115;
  struct StateT * v118 = slot_7(v109);
  return v118;
}

struct StateT * slot_5(struct StateT * v88) {
  int v89 = v88->timer;
  int v99 = v89 + 1;
  v88->timer = v99;
  int * v91 = v88->regs;
  int v92 = v91[12];
  int * v93 = v88->regs;
  int v94 = v93[14];
  int * v95 = v88->regs;
  int v106 = v92 + v94;
  v95[5] = v106;
  struct StateT * v97 = slot_6(v88);
  return v97;
}

struct StateT * slot_2(struct StateT * v28) {
  int v29 = v28->timer;
  int v35 = v29 + 1;
  v28->timer = v35;
  int * v31 = v28->regs;
  v31[14] = 0;
  struct StateT * v33 = slot_3(v28);
  return v33;
}

struct StateT * slot_7(struct StateT * v130) {
  int v131 = v130->timer;
  int v141 = v131 + 1;
  v130->timer = v141;
  int * v133 = v130->regs;
  int v134 = v133[13];
  int * v135 = v130->regs;
  int v136 = v135[14];
  int * v137 = v130->regs;
  int v148 = v134 + v136;
  v137[6] = v148;
  struct StateT * v139 = slot_8(v130);
  return v139;
}

struct StateT * slot_3(struct StateT * v41) {
  int v42 = v41->timer;
  int v48 = v42 + 1;
  v41->timer = v48;
  int * v44 = v41->regs;
  v44[15] = 16;
  struct StateT * v46 = slot_4(v41);
  return v46;
}

struct StateT * snippet(struct StateT * v0) {
  struct StateT * v1 = slot_0(v0);
  return v1;
}

struct StateT * slot_10(struct StateT * v209) {
  int v210 = v209->timer;
  int v218 = v210 + 1;
  v209->timer = v218;
  int * v212 = v209->regs;
  int v213 = v212[14];
  int * v214 = v209->regs;
  int v222 = v213 + 4;
  v214[14] = v222;
  struct StateT * v216 = slot_11(v209);
  return v216;
}

struct StateT * slot_1(struct StateT * v15) {
  int v16 = v15->timer;
  int v22 = v16 + 1;
  v15->timer = v22;
  int * v18 = v15->regs;
  v18[13] = 80;
  struct StateT * v20 = slot_2(v15);
  return v20;
}

struct StateT * slot_8(struct StateT * v151) {
  int v152 = v151->timer;
  int v162 = v152 + 1;
  v151->timer = v162;
  int * v154 = v151->regs;
  int v155 = v154[6];
  int * v156 = v151->mem;
  int v166 = (int)((unsigned int)v155 >> 2);
  int v157 = v156[v166];
  int * v158 = v151->regs;
  v158[11] = v157;
  struct StateT * v160 = slot_9(v151);
  return v160;
}

struct StateT * slot_4(struct StateT * v54) {
  int v55 = v54->timer;
  int v67 = v55 + 1;
  v54->timer = v67;
  int * v57 = v54->regs;
  int v58 = v57[14];
  int * v59 = v54->regs;
  int v60 = v59[15];
  bool v72 = v58 >= v60;
  struct StateT * v65;
  if (v72) {
    struct StateT * v61 = slot_14(v54);
    v65 = v61;
  } else {
    struct StateT * v63 = slot_5(v54);
    v65 = v63;
  }
  return v65;
}

struct StateT * slot_13(struct StateT * v225) {
  int v226 = v225->timer;
  int v229 = v226 + 1;
  v225->timer = v229;
  return v225;
}

struct StateT * slot_9(struct StateT * v172) {
  int v173 = v172->timer;
  int v185 = v173 + 1;
  v172->timer = v185;
  int * v175 = v172->regs;
  int v176 = v175[10];
  int * v177 = v172->regs;
  int v178 = v177[11];
  bool v190 = !(v176 == v178);
  struct StateT * v183;
  if (v190) {
    struct StateT * v179 = slot_12(v172);
    v183 = v179;
  } else {
    struct StateT * v181 = slot_10(v172);
    v183 = v181;
  }
  return v183;
}

struct StateT * slot_11(struct StateT * v230) {
  int v231 = v230->timer;
  int v235 = v231 + 1;
  v230->timer = v235;
  struct StateT * v233 = slot_4(v230);
  return v233;
}

struct StateT * slot_0(struct StateT * v2) {
  int v3 = v2->timer;
  int v9 = v3 + 1;
  v2->timer = v9;
  int * v5 = v2->regs;
  v5[12] = 0;
  struct StateT * v7 = slot_1(v2);
  return v7;
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
  
  int x = bounded(0, 80);
  s1.regs[10] = x;
  s2.regs[10] = x;
  
  // initialize secret
  for (int i=0; i<SECRET_SIZE; i++) {
    s1.mem[SECRET_OFFSET+i] = bounded(0, 20);
    s2.mem[SECRET_OFFSET+i] = bounded(0, 20);
  }
  struct StateT *s1_ = snippet(&s1);
  struct StateT *s2_ = snippet(&s2);
  __CPROVER_assert(s1_->timer==s2_->timer, "timing leak");
  return 0;
}