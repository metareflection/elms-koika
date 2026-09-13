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

struct StateT * snippet(struct StateT * v0);
struct StateT * v19(struct StateT * v20);
struct StateT * v1(struct StateT * v2);
struct StateT * v7(struct StateT * v8);
struct StateT * v13(struct StateT * v14);
struct StateT * snippet(struct StateT * v0) {
  struct StateT * v327 = v1(v0);
  return v327;
}

struct StateT * v19(struct StateT * v20) {
  int * v21 = v20->saved_regs;
  int * v22 = v20->regs;
  int v23 = v22[5];
  v21[5] = v23;
  int v25 = v20->timer;
  int v185 = v25 + 1;
  v20->timer = v185;
  int * v27 = v20->regs;
  int v28 = v27[13];
  int * v29 = v20->regs;
  int v30 = v29[10];
  int * v31 = v20->regs;
  int v191 = v28 + v30;
  v31[5] = v191;
  int * v33 = v20->saved_regs;
  int * v34 = v20->regs;
  int v35 = v34[11];
  v33[11] = v35;
  int v37 = v20->timer;
  int v196 = v37 + 1;
  v20->timer = v196;
  int * v39 = v20->regs;
  int v40 = v39[5];
  int * v41 = v20->cache_keys;
  int v42 = v41[0];
  bool v200 = v42 == ((int)((unsigned int)v40 >> 2));
  int v90;
  if (v200) {
    int * v43 = v20->cache_vals;
    int v44 = v43[0];
    v90 = v44;
  } else {
    int * v46 = v20->cache_keys;
    int v47 = v46[1];
    bool v205 = v47 == ((int)((unsigned int)v40 >> 2));
    int v88;
    if (v205) {
      int * v48 = v20->cache_vals;
      int v49 = v48[1];
      int * v50 = v20->cache_keys;
      int * v51 = v20->cache_keys;
      int v52 = v51[0];
      v50[1] = v52;
      int * v54 = v20->cache_vals;
      int * v55 = v20->cache_vals;
      int v56 = v55[0];
      v54[1] = v56;
      int * v58 = v20->cache_keys;
      int v214 = (int)((unsigned int)v40 >> 2);
      v58[0] = v214;
      int * v60 = v20->cache_vals;
      v60[0] = v49;
      int v62 = v20->timer;
      int v217 = v62 + 1;
      v20->timer = v217;
      v88 = v49;
    } else {
      int * v65 = v20->mem;
      int v219 = (int)((unsigned int)v40 >> 2);
      int v66 = v65[v219];
      int * v67 = v20->mem;
      int * v68 = v20->cache_keys;
      int v69 = v68[1];
      int * v70 = v20->cache_vals;
      int v71 = v70[1];
      v67[v69] = v71;
      int * v73 = v20->cache_keys;
      int * v74 = v20->cache_keys;
      int v75 = v74[0];
      v73[1] = v75;
      int * v77 = v20->cache_vals;
      int * v78 = v20->cache_vals;
      int v79 = v78[0];
      v77[1] = v79;
      int * v81 = v20->cache_keys;
      v81[0] = v219;
      int * v83 = v20->cache_vals;
      v83[0] = v66;
      int v85 = v20->timer;
      int v234 = v85 + 100;
      v20->timer = v234;
      v88 = v66;
    }
    v90 = v88;
  }
  int * v91 = v20->regs;
  v91[11] = v90;
  int v93 = v20->timer;
  int v238 = v93 + 1;
  v20->timer = v238;
  int * v95 = v20->regs;
  int v96 = v95[11];
  int * v97 = v20->regs;
  int v241 = v96 << 2;
  v97[11] = v241;
  int * v99 = v20->saved_regs;
  int * v100 = v20->regs;
  int v101 = v100[12];
  v99[12] = v101;
  int v103 = v20->timer;
  int v246 = v103 + 1;
  v20->timer = v246;
  int * v105 = v20->regs;
  int v106 = v105[11];
  int * v107 = v20->cache_keys;
  int v108 = v107[0];
  bool v249 = v108 == ((int)((unsigned int)v106 >> 2));
  int v156;
  if (v249) {
    int * v109 = v20->cache_vals;
    int v110 = v109[0];
    v156 = v110;
  } else {
    int * v112 = v20->cache_keys;
    int v113 = v112[1];
    bool v254 = v113 == ((int)((unsigned int)v106 >> 2));
    int v154;
    if (v254) {
      int * v114 = v20->cache_vals;
      int v115 = v114[1];
      int * v116 = v20->cache_keys;
      int * v117 = v20->cache_keys;
      int v118 = v117[0];
      v116[1] = v118;
      int * v120 = v20->cache_vals;
      int * v121 = v20->cache_vals;
      int v122 = v121[0];
      v120[1] = v122;
      int * v124 = v20->cache_keys;
      int v263 = (int)((unsigned int)v106 >> 2);
      v124[0] = v263;
      int * v126 = v20->cache_vals;
      v126[0] = v115;
      int v128 = v20->timer;
      int v266 = v128 + 1;
      v20->timer = v266;
      v154 = v115;
    } else {
      int * v131 = v20->mem;
      int v268 = (int)((unsigned int)v106 >> 2);
      int v132 = v131[v268];
      int * v133 = v20->mem;
      int * v134 = v20->cache_keys;
      int v135 = v134[1];
      int * v136 = v20->cache_vals;
      int v137 = v136[1];
      v133[v135] = v137;
      int * v139 = v20->cache_keys;
      int * v140 = v20->cache_keys;
      int v141 = v140[0];
      v139[1] = v141;
      int * v143 = v20->cache_vals;
      int * v144 = v20->cache_vals;
      int v145 = v144[0];
      v143[1] = v145;
      int * v147 = v20->cache_keys;
      v147[0] = v268;
      int * v149 = v20->cache_vals;
      v149[0] = v132;
      int v151 = v20->timer;
      int v283 = v151 + 100;
      v20->timer = v283;
      v154 = v132;
    }
    v156 = v154;
  }
  int * v157 = v20->regs;
  v157[12] = v156;
  int * v159 = v20->regs;
  int v160 = v159[10];
  int * v161 = v20->regs;
  int v162 = v161[15];
  bool v290 = v160 >= v162;
  if (v290) {
    int v163 = v20->timer;
    int v291 = v163 + 15;
    v20->timer = v291;
    int * v165 = v20->saved_regs;
    int v166 = v165[5];
    int * v167 = v20->regs;
    v167[5] = v166;
    int * v169 = v20->saved_regs;
    int v170 = v169[11];
    int * v171 = v20->regs;
    v171[11] = v170;
    int * v173 = v20->saved_regs;
    int v174 = v173[12];
    int * v175 = v20->regs;
    v175[12] = v174;
    ;
  } else {
    ;
  }
  return v20;
}

struct StateT * v1(struct StateT * v2) {
  int v3 = v2->timer;
  int v321 = v3 + 1;
  v2->timer = v321;
  int * v5 = v2->regs;
  v5[13] = 0;
  struct StateT * v319 = v7(v2);
  return v319;
}

struct StateT * v7(struct StateT * v8) {
  int v9 = v8->timer;
  int v313 = v9 + 1;
  v8->timer = v313;
  int * v11 = v8->regs;
  v11[10] = 80;
  struct StateT * v311 = v13(v8);
  return v311;
}

struct StateT * v13(struct StateT * v14) {
  int v15 = v14->timer;
  int v305 = v15 + 1;
  v14->timer = v305;
  int * v17 = v14->regs;
  v17[15] = 80;
  struct StateT * v303 = v19(v14);
  return v303;
}



/*****************************************
End of C Generated Code
*******************************************/

void init(struct StateT *s) {
  for (int i=0; i<NUM_REGS; i++) {
    s->regs[i] = 0;
    s->saved_regs[i] = 0;
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