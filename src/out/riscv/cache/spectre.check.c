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

struct StateT * snippet(struct StateT * v0);
struct StateT * v19(struct StateT * v20);
struct StateT * v104(struct StateT * v105);
struct StateT * v1(struct StateT * v2);
struct StateT * v38(struct StateT * v39);
struct StateT * v7(struct StateT * v8);
struct StateT * v13(struct StateT * v14);
struct StateT * v28(struct StateT * v29);
struct StateT * v96(struct StateT * v97);
struct StateT * snippet(struct StateT * v0) {
  struct StateT * v313 = v1(v0);
  return v313;
}

struct StateT * v19(struct StateT * v20) {
  int v21 = v20->timer;
  int v280 = v21 + 1;
  v20->timer = v280;
  int * v23 = v20->regs;
  int v24 = v23[10];
  int * v25 = v20->regs;
  int v26 = v25[15];
  bool v285 = v24 >= v26;
  struct StateT * v278;
  if (v285) {
    v278 = v20;
  } else {
    struct StateT * v276 = v28(v20);
    v278 = v276;
  }
  return v278;
}

struct StateT * v104(struct StateT * v105) {
  int v106 = v105->timer;
  int v163 = v106 + 1;
  v105->timer = v163;
  int * v108 = v105->regs;
  int v109 = v108[11];
  int * v110 = v105->cache_keys;
  int v111 = v110[0];
  bool v168 = v111 == ((int)((unsigned int)v109 >> 2));
  int v159;
  if (v168) {
    int * v112 = v105->cache_vals;
    int v113 = v112[0];
    v159 = v113;
  } else {
    int * v115 = v105->cache_keys;
    int v116 = v115[1];
    bool v173 = v116 == ((int)((unsigned int)v109 >> 2));
    int v157;
    if (v173) {
      int * v117 = v105->cache_vals;
      int v118 = v117[1];
      int * v119 = v105->cache_keys;
      int * v120 = v105->cache_keys;
      int v121 = v120[0];
      v119[1] = v121;
      int * v123 = v105->cache_vals;
      int * v124 = v105->cache_vals;
      int v125 = v124[0];
      v123[1] = v125;
      int * v127 = v105->cache_keys;
      int v182 = (int)((unsigned int)v109 >> 2);
      v127[0] = v182;
      int * v129 = v105->cache_vals;
      v129[0] = v118;
      int v131 = v105->timer;
      int v185 = v131 + 1;
      v105->timer = v185;
      v157 = v118;
    } else {
      int * v134 = v105->mem;
      int v187 = (int)((unsigned int)v109 >> 2);
      int v135 = v134[v187];
      int * v136 = v105->mem;
      int * v137 = v105->cache_keys;
      int v138 = v137[1];
      int * v139 = v105->cache_vals;
      int v140 = v139[1];
      v136[v138] = v140;
      int * v142 = v105->cache_keys;
      int * v143 = v105->cache_keys;
      int v144 = v143[0];
      v142[1] = v144;
      int * v146 = v105->cache_vals;
      int * v147 = v105->cache_vals;
      int v148 = v147[0];
      v146[1] = v148;
      int * v150 = v105->cache_keys;
      v150[0] = v187;
      int * v152 = v105->cache_vals;
      v152[0] = v135;
      int v154 = v105->timer;
      int v202 = v154 + 100;
      v105->timer = v202;
      v157 = v135;
    }
    v159 = v157;
  }
  int * v160 = v105->regs;
  v160[12] = v159;
  return v105;
}

struct StateT * v1(struct StateT * v2) {
  int v3 = v2->timer;
  int v307 = v3 + 1;
  v2->timer = v307;
  int * v5 = v2->regs;
  v5[13] = 0;
  struct StateT * v305 = v7(v2);
  return v305;
}

struct StateT * v38(struct StateT * v39) {
  int v40 = v39->timer;
  int v218 = v40 + 1;
  v39->timer = v218;
  int * v42 = v39->regs;
  int v43 = v42[5];
  int * v44 = v39->cache_keys;
  int v45 = v44[0];
  bool v223 = v45 == ((int)((unsigned int)v43 >> 2));
  int v93;
  if (v223) {
    int * v46 = v39->cache_vals;
    int v47 = v46[0];
    v93 = v47;
  } else {
    int * v49 = v39->cache_keys;
    int v50 = v49[1];
    bool v228 = v50 == ((int)((unsigned int)v43 >> 2));
    int v91;
    if (v228) {
      int * v51 = v39->cache_vals;
      int v52 = v51[1];
      int * v53 = v39->cache_keys;
      int * v54 = v39->cache_keys;
      int v55 = v54[0];
      v53[1] = v55;
      int * v57 = v39->cache_vals;
      int * v58 = v39->cache_vals;
      int v59 = v58[0];
      v57[1] = v59;
      int * v61 = v39->cache_keys;
      int v237 = (int)((unsigned int)v43 >> 2);
      v61[0] = v237;
      int * v63 = v39->cache_vals;
      v63[0] = v52;
      int v65 = v39->timer;
      int v240 = v65 + 1;
      v39->timer = v240;
      v91 = v52;
    } else {
      int * v68 = v39->mem;
      int v242 = (int)((unsigned int)v43 >> 2);
      int v69 = v68[v242];
      int * v70 = v39->mem;
      int * v71 = v39->cache_keys;
      int v72 = v71[1];
      int * v73 = v39->cache_vals;
      int v74 = v73[1];
      v70[v72] = v74;
      int * v76 = v39->cache_keys;
      int * v77 = v39->cache_keys;
      int v78 = v77[0];
      v76[1] = v78;
      int * v80 = v39->cache_vals;
      int * v81 = v39->cache_vals;
      int v82 = v81[0];
      v80[1] = v82;
      int * v84 = v39->cache_keys;
      v84[0] = v242;
      int * v86 = v39->cache_vals;
      v86[0] = v69;
      int v88 = v39->timer;
      int v257 = v88 + 100;
      v39->timer = v257;
      v91 = v69;
    }
    v93 = v91;
  }
  int * v94 = v39->regs;
  v94[11] = v93;
  struct StateT * v216 = v96(v39);
  return v216;
}

struct StateT * v7(struct StateT * v8) {
  int v9 = v8->timer;
  int v299 = v9 + 1;
  v8->timer = v299;
  int * v11 = v8->regs;
  v11[10] = 80;
  struct StateT * v297 = v13(v8);
  return v297;
}

struct StateT * v13(struct StateT * v14) {
  int v15 = v14->timer;
  int v291 = v15 + 1;
  v14->timer = v291;
  int * v17 = v14->regs;
  v17[15] = 80;
  struct StateT * v289 = v19(v14);
  return v289;
}

struct StateT * v28(struct StateT * v29) {
  int v30 = v29->timer;
  int v266 = v30 + 1;
  v29->timer = v266;
  int * v32 = v29->regs;
  int v33 = v32[13];
  int * v34 = v29->regs;
  int v35 = v34[10];
  int * v36 = v29->regs;
  int v273 = v33 + v35;
  v36[5] = v273;
  struct StateT * v264 = v38(v29);
  return v264;
}

struct StateT * v96(struct StateT * v97) {
  int v98 = v97->timer;
  int v209 = v98 + 1;
  v97->timer = v209;
  int * v100 = v97->regs;
  int v101 = v100[11];
  int * v102 = v97->regs;
  int v213 = v101 << 2;
  v102[11] = v213;
  struct StateT * v207 = v104(v97);
  return v207;
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