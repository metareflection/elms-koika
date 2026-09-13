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
struct StateT * v107(struct StateT * v108);
struct StateT * v23(struct StateT * v24);
struct StateT * v7(struct StateT * v8);
struct StateT * v169(struct StateT * v170);
struct StateT * v37(struct StateT * v38);
struct StateT * v13(struct StateT * v14);
struct StateT * v99(struct StateT * v100);
struct StateT * snippet(struct StateT * v0) {
  struct StateT * v367 = v1(v0);
  return v367;
}

struct StateT * v19(struct StateT * v20) {
  int v21 = v20->timer;
  int v340 = v21 + 1;
  v20->timer = v340;
  struct StateT * v338 = v23(v20);
  return v338;
}

struct StateT * v1(struct StateT * v2) {
  int v3 = v2->timer;
  int v361 = v3 + 1;
  v2->timer = v361;
  int * v5 = v2->regs;
  v5[13] = 0;
  struct StateT * v359 = v7(v2);
  return v359;
}

struct StateT * v107(struct StateT * v108) {
  int * v109 = v108->saved_regs;
  int * v110 = v108->regs;
  int v111 = v110[12];
  v109[12] = v111;
  int v113 = v108->timer;
  int v218 = v113 + 1;
  v108->timer = v218;
  int * v115 = v108->regs;
  int v116 = v115[11];
  int * v117 = v108->cache_keys;
  int v118 = v117[0];
  bool v223 = v118 == ((int)((unsigned int)v116 >> 2));
  int v166;
  if (v223) {
    int * v119 = v108->cache_vals;
    int v120 = v119[0];
    v166 = v120;
  } else {
    int * v122 = v108->cache_keys;
    int v123 = v122[1];
    bool v228 = v123 == ((int)((unsigned int)v116 >> 2));
    int v164;
    if (v228) {
      int * v124 = v108->cache_vals;
      int v125 = v124[1];
      int * v126 = v108->cache_keys;
      int * v127 = v108->cache_keys;
      int v128 = v127[0];
      v126[1] = v128;
      int * v130 = v108->cache_vals;
      int * v131 = v108->cache_vals;
      int v132 = v131[0];
      v130[1] = v132;
      int * v134 = v108->cache_keys;
      int v237 = (int)((unsigned int)v116 >> 2);
      v134[0] = v237;
      int * v136 = v108->cache_vals;
      v136[0] = v125;
      int v138 = v108->timer;
      int v240 = v138 + 1;
      v108->timer = v240;
      v164 = v125;
    } else {
      int * v141 = v108->mem;
      int v242 = (int)((unsigned int)v116 >> 2);
      int v142 = v141[v242];
      int * v143 = v108->mem;
      int * v144 = v108->cache_keys;
      int v145 = v144[1];
      int * v146 = v108->cache_vals;
      int v147 = v146[1];
      v143[v145] = v147;
      int * v149 = v108->cache_keys;
      int * v150 = v108->cache_keys;
      int v151 = v150[0];
      v149[1] = v151;
      int * v153 = v108->cache_vals;
      int * v154 = v108->cache_vals;
      int v155 = v154[0];
      v153[1] = v155;
      int * v157 = v108->cache_keys;
      v157[0] = v242;
      int * v159 = v108->cache_vals;
      v159[0] = v142;
      int v161 = v108->timer;
      int v257 = v161 + 100;
      v108->timer = v257;
      v164 = v142;
    }
    v166 = v164;
  }
  int * v167 = v108->regs;
  v167[12] = v166;
  struct StateT * v212 = v169(v108);
  return v212;
}

struct StateT * v23(struct StateT * v24) {
  int * v25 = v24->saved_regs;
  int * v26 = v24->regs;
  int v27 = v26[5];
  v25[5] = v27;
  int v29 = v24->timer;
  int v329 = v29 + 1;
  v24->timer = v329;
  int * v31 = v24->regs;
  int v32 = v31[13];
  int * v33 = v24->regs;
  int v34 = v33[10];
  int * v35 = v24->regs;
  int v335 = v32 + v34;
  v35[5] = v335;
  struct StateT * v323 = v37(v24);
  return v323;
}

struct StateT * v7(struct StateT * v8) {
  int v9 = v8->timer;
  int v353 = v9 + 1;
  v8->timer = v353;
  int * v11 = v8->regs;
  v11[10] = 80;
  struct StateT * v351 = v13(v8);
  return v351;
}

struct StateT * v169(struct StateT * v170) {
  int * v171 = v170->regs;
  int v172 = v171[10];
  int * v173 = v170->regs;
  int v174 = v173[15];
  bool v197 = v172 >= v174;
  struct StateT * v191;
  if (v197) {
    int v175 = v170->timer;
    int v198 = v175 + 15;
    v170->timer = v198;
    int * v177 = v170->saved_regs;
    int v178 = v177[5];
    int * v179 = v170->regs;
    v179[5] = v178;
    int * v181 = v170->saved_regs;
    int v182 = v181[11];
    int * v183 = v170->regs;
    v183[11] = v182;
    int * v185 = v170->saved_regs;
    int v186 = v185[12];
    int * v187 = v170->regs;
    v187[12] = v186;
    v191 = v170;
  } else {
    v191 = v170;
  }
  return v191;
}

struct StateT * v37(struct StateT * v38) {
  int * v39 = v38->saved_regs;
  int * v40 = v38->regs;
  int v41 = v40[11];
  v39[11] = v41;
  int v43 = v38->timer;
  int v278 = v43 + 1;
  v38->timer = v278;
  int * v45 = v38->regs;
  int v46 = v45[5];
  int * v47 = v38->cache_keys;
  int v48 = v47[0];
  bool v283 = v48 == ((int)((unsigned int)v46 >> 2));
  int v96;
  if (v283) {
    int * v49 = v38->cache_vals;
    int v50 = v49[0];
    v96 = v50;
  } else {
    int * v52 = v38->cache_keys;
    int v53 = v52[1];
    bool v288 = v53 == ((int)((unsigned int)v46 >> 2));
    int v94;
    if (v288) {
      int * v54 = v38->cache_vals;
      int v55 = v54[1];
      int * v56 = v38->cache_keys;
      int * v57 = v38->cache_keys;
      int v58 = v57[0];
      v56[1] = v58;
      int * v60 = v38->cache_vals;
      int * v61 = v38->cache_vals;
      int v62 = v61[0];
      v60[1] = v62;
      int * v64 = v38->cache_keys;
      int v297 = (int)((unsigned int)v46 >> 2);
      v64[0] = v297;
      int * v66 = v38->cache_vals;
      v66[0] = v55;
      int v68 = v38->timer;
      int v300 = v68 + 1;
      v38->timer = v300;
      v94 = v55;
    } else {
      int * v71 = v38->mem;
      int v302 = (int)((unsigned int)v46 >> 2);
      int v72 = v71[v302];
      int * v73 = v38->mem;
      int * v74 = v38->cache_keys;
      int v75 = v74[1];
      int * v76 = v38->cache_vals;
      int v77 = v76[1];
      v73[v75] = v77;
      int * v79 = v38->cache_keys;
      int * v80 = v38->cache_keys;
      int v81 = v80[0];
      v79[1] = v81;
      int * v83 = v38->cache_vals;
      int * v84 = v38->cache_vals;
      int v85 = v84[0];
      v83[1] = v85;
      int * v87 = v38->cache_keys;
      v87[0] = v302;
      int * v89 = v38->cache_vals;
      v89[0] = v72;
      int v91 = v38->timer;
      int v317 = v91 + 100;
      v38->timer = v317;
      v94 = v72;
    }
    v96 = v94;
  }
  int * v97 = v38->regs;
  v97[11] = v96;
  struct StateT * v272 = v99(v38);
  return v272;
}

struct StateT * v13(struct StateT * v14) {
  int v15 = v14->timer;
  int v345 = v15 + 1;
  v14->timer = v345;
  int * v17 = v14->regs;
  v17[15] = 80;
  struct StateT * v343 = v19(v14);
  return v343;
}

struct StateT * v99(struct StateT * v100) {
  int v101 = v100->timer;
  int v265 = v101 + 1;
  v100->timer = v265;
  int * v103 = v100->regs;
  int v104 = v103[11];
  int * v105 = v100->regs;
  int v269 = v104 << 2;
  v105[11] = v269;
  struct StateT * v263 = v107(v100);
  return v263;
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