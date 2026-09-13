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

struct StateT * v112(struct StateT * v113);
struct StateT * v19(struct StateT * v20);
struct StateT * v25(struct StateT * v26);
struct StateT * v72(struct StateT * v73);
struct StateT * v130(struct StateT * v131);
struct StateT * v39(struct StateT * v40);
struct StateT * v102(struct StateT * v103);
struct StateT * v92(struct StateT * v93);
struct StateT * snippet(struct StateT * v0);
struct StateT * v31(struct StateT * v32);
struct StateT * v62(struct StateT * v63);
struct StateT * v1(struct StateT * v2);
struct StateT * v82(struct StateT * v83);
struct StateT * v7(struct StateT * v8);
struct StateT * v13(struct StateT * v14);
struct StateT * v122(struct StateT * v123);
struct StateT * v112(struct StateT * v113) {
  int v114 = v113->timer;
  int v151 = v114 + 1;
  v113->timer = v151;int * v116 = v113->regs;
  int v117 = v116[5];
  int * v118 = v113->regs;
  int v119 = v118[16];
  int * v120 = v113->regs;
  int v157 = v117 | v119;
  v120[5] = v157;
  struct StateT * v149 = v122(v113);
  return v149;
}

struct StateT * v19(struct StateT * v20) {
  int v21 = v20->timer;
  int v245 = v21 + 1;
  v20->timer = v245;int * v23 = v20->regs;
  v23[15] = 16;
  struct StateT * v243 = v25(v20);
  return v243;
}

struct StateT * v25(struct StateT * v26) {
  int v27 = v26->timer;
  int v237 = v27 + 1;
  v26->timer = v237;int * v29 = v26->regs;
  v29[5] = 0;
  struct StateT * v235 = v31(v26);
  return v235;
}

struct StateT * v72(struct StateT * v73) {
  int v74 = v73->timer;
  int v198 = v74 + 1;
  v73->timer = v198;int * v76 = v73->regs;
  int v77 = v76[6];
  int * v78 = v73->mem;
  int v202 = (int)((unsigned int)v77 >> 2);
  int v79 = v78[v202];
  int * v80 = v73->regs;
  v80[7] = v79;
  struct StateT * v196 = v82(v73);
  return v196;
}

struct StateT * v130(struct StateT * v131) {
  int v132 = v131->timer;
  int v137 = v132 + 1;
  v131->timer = v137;struct StateT * v135 = v31(v131);
  return v135;
}

struct StateT * v39(struct StateT * v40) {
  int v41 = v40->timer;
  int v51 = v41 + 1;
  v40->timer = v51;int * v43 = v40->regs;
  int v44 = v43[5];
  bool v54 = (v44 ^ -2147483648) < -2147483647;
  int v47 = (v54 ? 1 : 0);
  int * v48 = v40->regs;
  v48[11] = v47;
  return v40;
}

struct StateT * v102(struct StateT * v103) {
  int v104 = v103->timer;
  int v162 = v104 + 1;
  v103->timer = v162;int * v106 = v103->regs;
  int v107 = v106[7];
  int * v108 = v103->regs;
  int v109 = v108[9];
  int * v110 = v103->regs;
  int v169 = v107 ^ v109;
  v110[16] = v169;
  struct StateT * v160 = v112(v103);
  return v160;
}

struct StateT * v92(struct StateT * v93) {
  int v94 = v93->timer;
  int v174 = v94 + 1;
  v93->timer = v174;int * v96 = v93->regs;
  int v97 = v96[8];
  int * v98 = v93->mem;
  int v178 = (int)((unsigned int)v97 >> 2);
  int v99 = v98[v178];
  int * v100 = v93->regs;
  v100[9] = v99;
  struct StateT * v172 = v102(v93);
  return v172;
}

struct StateT * snippet(struct StateT * v0) {
  struct StateT * v275 = v1(v0);
  return v275;
}

struct StateT * v31(struct StateT * v32) {
  int v33 = v32->timer;
  int v224 = v33 + 1;
  v32->timer = v224;int * v35 = v32->regs;
  int v36 = v35[14];
  int * v37 = v32->regs;
  int v38 = v37[15];
  bool v229 = v36 >= v38;
  struct StateT * v222 = (v229 ? ({
    struct StateT * v60 = v39(v32);
    v60;
  }) : ({
    struct StateT * v220 = v62(v32);
    v220;
  }));
  return v222;
}

struct StateT * v62(struct StateT * v63) {
  int v64 = v63->timer;
  int v210 = v64 + 1;
  v63->timer = v210;int * v66 = v63->regs;
  int v67 = v66[12];
  int * v68 = v63->regs;
  int v69 = v68[14];
  int * v70 = v63->regs;
  int v217 = v67 + v69;
  v70[6] = v217;
  struct StateT * v208 = v72(v63);
  return v208;
}

struct StateT * v1(struct StateT * v2) {
  int v3 = v2->timer;
  int v269 = v3 + 1;
  v2->timer = v269;int * v5 = v2->regs;
  v5[12] = 0;
  struct StateT * v267 = v7(v2);
  return v267;
}

struct StateT * v82(struct StateT * v83) {
  int v84 = v83->timer;
  int v186 = v84 + 1;
  v83->timer = v186;int * v86 = v83->regs;
  int v87 = v86[13];
  int * v88 = v83->regs;
  int v89 = v88[14];
  int * v90 = v83->regs;
  int v193 = v87 + v89;
  v90[8] = v193;
  struct StateT * v184 = v92(v83);
  return v184;
}

struct StateT * v7(struct StateT * v8) {
  int v9 = v8->timer;
  int v261 = v9 + 1;
  v8->timer = v261;int * v11 = v8->regs;
  v11[13] = 80;
  struct StateT * v259 = v13(v8);
  return v259;
}

struct StateT * v13(struct StateT * v14) {
  int v15 = v14->timer;
  int v253 = v15 + 1;
  v14->timer = v253;int * v17 = v14->regs;
  v17[14] = 0;
  struct StateT * v251 = v19(v14);
  return v251;
}

struct StateT * v122(struct StateT * v123) {
  int v124 = v123->timer;
  int v142 = v124 + 1;
  v123->timer = v142;int * v126 = v123->regs;
  int v127 = v126[14];
  int * v128 = v123->regs;
  int v146 = v127 + 4;
  v128[14] = v146;
  struct StateT * v140 = v130(v123);
  return v140;
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