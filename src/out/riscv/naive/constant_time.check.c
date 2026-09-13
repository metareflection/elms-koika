// verify: clean (CBMC should report VERIFICATION SUCCESSFUL)

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

struct StateT * slot_12(struct StateT * v236);
struct StateT * slot_14(struct StateT * v91);
struct StateT * slot_6(struct StateT * v111);
struct StateT * slot_5(struct StateT * v67);
struct StateT * slot_2(struct StateT * v28);
struct StateT * slot_7(struct StateT * v132);
struct StateT * slot_3(struct StateT * v41);
struct StateT * snippet(struct StateT * v0);
struct StateT * slot_10(struct StateT * v195);
struct StateT * slot_1(struct StateT * v15);
struct StateT * slot_8(struct StateT * v153);
struct StateT * slot_4(struct StateT * v54);
struct StateT * slot_13(struct StateT * v252);
struct StateT * slot_9(struct StateT * v174);
struct StateT * slot_11(struct StateT * v216);
struct StateT * slot_0(struct StateT * v2);
struct StateT * slot_12(struct StateT * v236) {
  int v237 = v236->timer;
  int v245 = v237 + 1;
  v236->timer = v245;
  int * v239 = v236->regs;
  int v240 = v239[14];
  int * v241 = v236->regs;
  int v249 = v240 + 4;
  v241[14] = v249;
  struct StateT * v243 = slot_13(v236);
  return v243;
}

struct StateT * slot_14(struct StateT * v91) {
  int v92 = v91->timer;
  int v102 = v92 + 1;
  v91->timer = v102;
  int * v94 = v91->regs;
  int v95 = v94[5];
  bool v105 = (v95 ^ -2147483648) < -2147483647;
  int v98;
  if (v105) {
    v98 = 1;
  } else {
    v98 = 0;
  }
  int * v99 = v91->regs;
  v99[11] = v98;
  return v91;
}

struct StateT * slot_6(struct StateT * v111) {
  int v112 = v111->timer;
  int v122 = v112 + 1;
  v111->timer = v122;
  int * v114 = v111->regs;
  int v115 = v114[12];
  int * v116 = v111->regs;
  int v117 = v116[14];
  int * v118 = v111->regs;
  int v129 = v115 + v117;
  v118[6] = v129;
  struct StateT * v120 = slot_7(v111);
  return v120;
}

struct StateT * slot_5(struct StateT * v67) {
  int v68 = v67->timer;
  int v80 = v68 + 1;
  v67->timer = v80;
  int * v70 = v67->regs;
  int v71 = v70[14];
  int * v72 = v67->regs;
  int v73 = v72[15];
  bool v85 = v71 >= v73;
  struct StateT * v78;
  if (v85) {
    struct StateT * v74 = slot_14(v67);
    v78 = v74;
  } else {
    struct StateT * v76 = slot_6(v67);
    v78 = v76;
  }
  return v78;
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

struct StateT * slot_7(struct StateT * v132) {
  int v133 = v132->timer;
  int v143 = v133 + 1;
  v132->timer = v143;
  int * v135 = v132->regs;
  int v136 = v135[6];
  int * v137 = v132->mem;
  int v147 = (int)((unsigned int)v136 >> 2);
  int v138 = v137[v147];
  int * v139 = v132->regs;
  v139[7] = v138;
  struct StateT * v141 = slot_8(v132);
  return v141;
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

struct StateT * slot_10(struct StateT * v195) {
  int v196 = v195->timer;
  int v206 = v196 + 1;
  v195->timer = v206;
  int * v198 = v195->regs;
  int v199 = v198[7];
  int * v200 = v195->regs;
  int v201 = v200[9];
  int * v202 = v195->regs;
  int v213 = v199 ^ v201;
  v202[16] = v213;
  struct StateT * v204 = slot_11(v195);
  return v204;
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

struct StateT * slot_8(struct StateT * v153) {
  int v154 = v153->timer;
  int v164 = v154 + 1;
  v153->timer = v164;
  int * v156 = v153->regs;
  int v157 = v156[13];
  int * v158 = v153->regs;
  int v159 = v158[14];
  int * v160 = v153->regs;
  int v171 = v157 + v159;
  v160[8] = v171;
  struct StateT * v162 = slot_9(v153);
  return v162;
}

struct StateT * slot_4(struct StateT * v54) {
  int v55 = v54->timer;
  int v61 = v55 + 1;
  v54->timer = v61;
  int * v57 = v54->regs;
  v57[5] = 0;
  struct StateT * v59 = slot_5(v54);
  return v59;
}

struct StateT * slot_13(struct StateT * v252) {
  int v253 = v252->timer;
  int v257 = v253 + 1;
  v252->timer = v257;
  struct StateT * v255 = slot_5(v252);
  return v255;
}

struct StateT * slot_9(struct StateT * v174) {
  int v175 = v174->timer;
  int v185 = v175 + 1;
  v174->timer = v185;
  int * v177 = v174->regs;
  int v178 = v177[8];
  int * v179 = v174->mem;
  int v189 = (int)((unsigned int)v178 >> 2);
  int v180 = v179[v189];
  int * v181 = v174->regs;
  v181[9] = v180;
  struct StateT * v183 = slot_10(v174);
  return v183;
}

struct StateT * slot_11(struct StateT * v216) {
  int v217 = v216->timer;
  int v227 = v217 + 1;
  v216->timer = v227;
  int * v219 = v216->regs;
  int v220 = v219[5];
  int * v221 = v216->regs;
  int v222 = v221[16];
  int * v223 = v216->regs;
  int v233 = v220 | v222;
  v223[5] = v233;
  struct StateT * v225 = slot_12(v216);
  return v225;
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