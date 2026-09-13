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
struct StateT {
  int regs[NUM_REGS];
  int mem[MEM_SIZE];
  int saved_regs[NUM_REGS];
  int cache_keys[CACHE_LRU_SIZE];
  int cache_vals[CACHE_LRU_SIZE];
  int timer;
};

void init(struct StateT *s) {
  for (int i=0; i<NUM_REGS; i++) {
    s->regs[i] = 0;
  }
  s->timer = 0;
  for (int i=0; i<MEM_SIZE; i++) {
    s->mem[i] = 0;
  }
}

/*****************************************
Emitting C Generated Code
*******************************************/

#include <stdbool.h>
#include <stdlib.h>

struct StateT * v124(struct StateT * v125);
struct StateT * v19(struct StateT * v20);
struct StateT * v46(struct StateT * v47);
struct StateT * v25(struct StateT * v26);
struct StateT * v94(struct StateT * v95);
struct StateT * v100(struct StateT * v101);
struct StateT * v86(struct StateT * v87);
struct StateT * snippet(struct StateT * v0);
struct StateT * v1(struct StateT * v2);
struct StateT * v116(struct StateT * v117);
struct StateT * v76(struct StateT * v77);
struct StateT * v56(struct StateT * v57);
struct StateT * v7(struct StateT * v8);
struct StateT * v33(struct StateT * v34);
struct StateT * v13(struct StateT * v14);
struct StateT * v66(struct StateT * v67);
struct StateT * v124(struct StateT * v125) {
  int v126 = v125->timer;
  int v131 = v126 + 1;
  v125->timer = v131;struct StateT * v129 = v25(v125);
  return v129;
}

struct StateT * v19(struct StateT * v20) {
  int v21 = v20->timer;
  int v223 = v21 + 1;
  v20->timer = v223;int * v23 = v20->regs;
  v23[15] = 16;
  struct StateT * v221 = v25(v20);
  return v221;
}

struct StateT * v46(struct StateT * v47) {
  int v48 = v47->timer;
  int v196 = v48 + 1;
  v47->timer = v196;int * v50 = v47->regs;
  int v51 = v50[12];
  int * v52 = v47->regs;
  int v53 = v52[14];
  int * v54 = v47->regs;
  int v203 = v51 + v53;
  v54[5] = v203;
  struct StateT * v194 = v56(v47);
  return v194;
}

struct StateT * v25(struct StateT * v26) {
  int v27 = v26->timer;
  int v210 = v27 + 1;
  v26->timer = v210;int * v29 = v26->regs;
  int v30 = v29[14];
  int * v31 = v26->regs;
  int v32 = v31[15];
  bool v215 = v30 >= v32;
  struct StateT * v208 = (v215 ? ({
    struct StateT * v44 = v33(v26);
    v44;
  }) : ({
    struct StateT * v206 = v46(v26);
    v206;
  }));
  return v208;
}

struct StateT * v94(struct StateT * v95) {
  int v96 = v95->timer;
  int v108 = v96 + 1;
  v95->timer = v108;int * v98 = v95->regs;
  v98[10] = 0;
  struct StateT * v106 = v100(v95);
  return v106;
}

struct StateT * v100(struct StateT * v101) {
  int v102 = v101->timer;
  int v105 = v102 + 1;
  v101->timer = v105;return v101;
}

struct StateT * v86(struct StateT * v87) {
  int v88 = v87->timer;
  int v147 = v88 + 1;
  v87->timer = v147;int * v90 = v87->regs;
  int v91 = v90[10];
  int * v92 = v87->regs;
  int v93 = v92[11];
  bool v152 = !(v91 == v93);
  struct StateT * v145 = (v152 ? ({
    struct StateT * v114 = v94(v87);
    v114;
  }) : ({
    struct StateT * v143 = v116(v87);
    v143;
  }));
  return v145;
}

struct StateT * snippet(struct StateT * v0) {
  struct StateT * v253 = v1(v0);
  return v253;
}

struct StateT * v1(struct StateT * v2) {
  int v3 = v2->timer;
  int v247 = v3 + 1;
  v2->timer = v247;int * v5 = v2->regs;
  v5[12] = 0;
  struct StateT * v245 = v7(v2);
  return v245;
}

struct StateT * v116(struct StateT * v117) {
  int v118 = v117->timer;
  int v136 = v118 + 1;
  v117->timer = v136;int * v120 = v117->regs;
  int v121 = v120[14];
  int * v122 = v117->regs;
  int v140 = v121 + 4;
  v122[14] = v140;
  struct StateT * v134 = v124(v117);
  return v134;
}

struct StateT * v76(struct StateT * v77) {
  int v78 = v77->timer;
  int v160 = v78 + 1;
  v77->timer = v160;int * v80 = v77->regs;
  int v81 = v80[6];
  int * v82 = v77->mem;
  int v164 = (int)((unsigned int)v81 >> 2);
  int v83 = v82[v164];
  int * v84 = v77->regs;
  v84[11] = v83;
  struct StateT * v158 = v86(v77);
  return v158;
}

struct StateT * v56(struct StateT * v57) {
  int v58 = v57->timer;
  int v184 = v58 + 1;
  v57->timer = v184;int * v60 = v57->regs;
  int v61 = v60[5];
  int * v62 = v57->mem;
  int v188 = (int)((unsigned int)v61 >> 2);
  int v63 = v62[v188];
  int * v64 = v57->regs;
  v64[10] = v63;
  struct StateT * v182 = v66(v57);
  return v182;
}

struct StateT * v7(struct StateT * v8) {
  int v9 = v8->timer;
  int v239 = v9 + 1;
  v8->timer = v239;int * v11 = v8->regs;
  v11[13] = 80;
  struct StateT * v237 = v13(v8);
  return v237;
}

struct StateT * v33(struct StateT * v34) {
  int v35 = v34->timer;
  int v40 = v35 + 1;
  v34->timer = v40;int * v37 = v34->regs;
  v37[10] = 1;
  return v34;
}

struct StateT * v13(struct StateT * v14) {
  int v15 = v14->timer;
  int v231 = v15 + 1;
  v14->timer = v231;int * v17 = v14->regs;
  v17[14] = 0;
  struct StateT * v229 = v19(v14);
  return v229;
}

struct StateT * v66(struct StateT * v67) {
  int v68 = v67->timer;
  int v172 = v68 + 1;
  v67->timer = v172;int * v70 = v67->regs;
  int v71 = v70[13];
  int * v72 = v67->regs;
  int v73 = v72[14];
  int * v74 = v67->regs;
  int v179 = v71 + v73;
  v74[6] = v179;
  struct StateT * v170 = v76(v67);
  return v170;
}



/*****************************************
End of C Generated Code
*******************************************/

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