
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

/*****************************************
Emitting C Generated Code
*******************************************/

#include <stdbool.h>
#include <stdlib.h>

struct StateT * v19(struct StateT * v20);
struct StateT * v25(struct StateT * v26);
struct StateT * v218(struct StateT * v219);
struct StateT * v193(struct StateT * v194);
struct StateT * snippet(struct StateT * v0);
struct StateT * v212(struct StateT * v213);
struct StateT * v242(struct StateT * v243);
struct StateT * v1(struct StateT * v2);
struct StateT * v7(struct StateT * v8);
struct StateT * v234(struct StateT * v235);
struct StateT * v13(struct StateT * v14);
struct StateT * v19(struct StateT * v20) {
  int v21 = v20->timer;
  int v410 = v21 + 1;
  v20->timer = v410;int * v23 = v20->regs;
  v23[15] = 16;
  struct StateT * v408 = v25(v20);
  return v408;
}

struct StateT * v25(struct StateT * v26) {
  int * v27 = v26->saved_regs;
  int * v28 = v26->regs;
  int v29 = v28[5];
  v27[5] = v29;
  int v31 = v26->timer;
  int v271 = v31 + 1;
  v26->timer = v271;int * v33 = v26->regs;
  int v34 = v33[12];
  int * v35 = v26->regs;
  int v36 = v35[14];
  int * v37 = v26->regs;
  int v277 = v34 + v36;
  v37[5] = v277;
  int * v39 = v26->saved_regs;
  int * v40 = v26->regs;
  int v41 = v40[10];
  v39[10] = v41;
  int v43 = v26->timer;
  int v282 = v43 + 1;
  v26->timer = v282;int * v45 = v26->regs;
  int v46 = v45[5];
  int * v47 = v26->cache_keys;
  int v48 = v47[0];
  bool v286 = v48 == ((int)((unsigned int)v46 >> 2));
  int v96 = (v286 ? ({
    int * v49 = v26->cache_vals;
    int v50 = v49[0];
    v50;
  }) : ({
    int * v52 = v26->cache_keys;
    int v53 = v52[1];
    bool v291 = v53 == ((int)((unsigned int)v46 >> 2));
    int v94 = (v291 ? ({
      int * v54 = v26->cache_vals;
      int v55 = v54[1];
      int * v56 = v26->cache_keys;
      int * v57 = v26->cache_keys;
      int v58 = v57[0];
      v56[1] = v58;
      int * v60 = v26->cache_vals;
      int * v61 = v26->cache_vals;
      int v62 = v61[0];
      v60[1] = v62;
      int * v64 = v26->cache_keys;
      int v300 = (int)((unsigned int)v46 >> 2);
      v64[0] = v300;
      int * v66 = v26->cache_vals;
      v66[0] = v55;
      int v68 = v26->timer;
      int v303 = v68 + 1;
      v26->timer = v303;v55;
    }) : ({
      int * v71 = v26->mem;
      int v305 = (int)((unsigned int)v46 >> 2);
      int v72 = v71[v305];
      int * v73 = v26->mem;
      int * v74 = v26->cache_keys;
      int v75 = v74[1];
      int * v76 = v26->cache_vals;
      int v77 = v76[1];
      v73[v75] = v77;
      int * v79 = v26->cache_keys;
      int * v80 = v26->cache_keys;
      int v81 = v80[0];
      v79[1] = v81;
      int * v83 = v26->cache_vals;
      int * v84 = v26->cache_vals;
      int v85 = v84[0];
      v83[1] = v85;
      int * v87 = v26->cache_keys;
      v87[0] = v305;
      int * v89 = v26->cache_vals;
      v89[0] = v72;
      int v91 = v26->timer;
      int v320 = v91 + 100;
      v26->timer = v320;v72;
    }));
    v94;
  }));
  int * v97 = v26->regs;
  v97[10] = v96;
  int * v99 = v26->saved_regs;
  int * v100 = v26->regs;
  int v101 = v100[6];
  v99[6] = v101;
  int v103 = v26->timer;
  int v328 = v103 + 1;
  v26->timer = v328;int * v105 = v26->regs;
  int v106 = v105[13];
  int * v107 = v26->regs;
  int v108 = v107[14];
  int * v109 = v26->regs;
  int v333 = v106 + v108;
  v109[6] = v333;
  int * v111 = v26->saved_regs;
  int * v112 = v26->regs;
  int v113 = v112[11];
  v111[11] = v113;
  int v115 = v26->timer;
  int v338 = v115 + 1;
  v26->timer = v338;int * v117 = v26->regs;
  int v118 = v117[6];
  int * v119 = v26->cache_keys;
  int v120 = v119[0];
  bool v341 = v120 == ((int)((unsigned int)v118 >> 2));
  int v168 = (v341 ? ({
    int * v121 = v26->cache_vals;
    int v122 = v121[0];
    v122;
  }) : ({
    int * v124 = v26->cache_keys;
    int v125 = v124[1];
    bool v346 = v125 == ((int)((unsigned int)v118 >> 2));
    int v166 = (v346 ? ({
      int * v126 = v26->cache_vals;
      int v127 = v126[1];
      int * v128 = v26->cache_keys;
      int * v129 = v26->cache_keys;
      int v130 = v129[0];
      v128[1] = v130;
      int * v132 = v26->cache_vals;
      int * v133 = v26->cache_vals;
      int v134 = v133[0];
      v132[1] = v134;
      int * v136 = v26->cache_keys;
      int v355 = (int)((unsigned int)v118 >> 2);
      v136[0] = v355;
      int * v138 = v26->cache_vals;
      v138[0] = v127;
      int v140 = v26->timer;
      int v358 = v140 + 1;
      v26->timer = v358;v127;
    }) : ({
      int * v143 = v26->mem;
      int v360 = (int)((unsigned int)v118 >> 2);
      int v144 = v143[v360];
      int * v145 = v26->mem;
      int * v146 = v26->cache_keys;
      int v147 = v146[1];
      int * v148 = v26->cache_vals;
      int v149 = v148[1];
      v145[v147] = v149;
      int * v151 = v26->cache_keys;
      int * v152 = v26->cache_keys;
      int v153 = v152[0];
      v151[1] = v153;
      int * v155 = v26->cache_vals;
      int * v156 = v26->cache_vals;
      int v157 = v156[0];
      v155[1] = v157;
      int * v159 = v26->cache_keys;
      v159[0] = v360;
      int * v161 = v26->cache_vals;
      v161[0] = v144;
      int v163 = v26->timer;
      int v375 = v163 + 100;
      v26->timer = v375;v144;
    }));
    v166;
  }));
  int * v169 = v26->regs;
  v169[11] = v168;
  int * v171 = v26->regs;
  int v172 = v171[14];
  int * v173 = v26->regs;
  int v174 = v173[15];
  bool v382 = v172 >= v174;
  if (v382) {
    int v175 = v26->timer;
    int v383 = v175 + 15;
    v26->timer = v383;int * v177 = v26->saved_regs;
    int v178 = v177[5];
    int * v179 = v26->regs;
    v179[5] = v178;
    int * v181 = v26->saved_regs;
    int v182 = v181[10];
    int * v183 = v26->regs;
    v183[10] = v182;
    int * v185 = v26->saved_regs;
    int v186 = v185[6];
    int * v187 = v26->regs;
    v187[6] = v186;
    int * v189 = v26->saved_regs;
    int v190 = v189[11];
    int * v191 = v26->regs;
    v191[11] = v190;
    struct StateT * v204 = v193(v26);
    ;
  } else {
    int v206 = v26->timer;
    int v398 = v206 + 1;
    v26->timer = v398;int * v208 = v26->regs;
    int v209 = v208[10];
    int * v210 = v26->regs;
    int v211 = v210[11];
    bool v401 = !(v209 == v211);
    struct StateT * v263 = (v401 ? ({
      struct StateT * v232 = v212(v26);
      v232;
    }) : ({
      struct StateT * v261 = v234(v26);
      v261;
    }));
    ;
  }
  return v263;
}

struct StateT * v218(struct StateT * v219) {
  int v220 = v219->timer;
  int v223 = v220 + 1;
  v219->timer = v223;return v219;
}

struct StateT * v193(struct StateT * v194) {
  int v195 = v194->timer;
  int v200 = v195 + 1;
  v194->timer = v200;int * v197 = v194->regs;
  v197[10] = 1;
  return v194;
}

struct StateT * snippet(struct StateT * v0) {
  struct StateT * v440 = v1(v0);
  return v440;
}

struct StateT * v212(struct StateT * v213) {
  int v214 = v213->timer;
  int v226 = v214 + 1;
  v213->timer = v226;int * v216 = v213->regs;
  v216[10] = 0;
  struct StateT * v224 = v218(v213);
  return v224;
}

struct StateT * v242(struct StateT * v243) {
  int v244 = v243->timer;
  int v249 = v244 + 1;
  v243->timer = v249;struct StateT * v247 = v25(v243);
  return v247;
}

struct StateT * v1(struct StateT * v2) {
  int v3 = v2->timer;
  int v434 = v3 + 1;
  v2->timer = v434;int * v5 = v2->regs;
  v5[12] = 0;
  struct StateT * v432 = v7(v2);
  return v432;
}

struct StateT * v7(struct StateT * v8) {
  int v9 = v8->timer;
  int v426 = v9 + 1;
  v8->timer = v426;int * v11 = v8->regs;
  v11[13] = 80;
  struct StateT * v424 = v13(v8);
  return v424;
}

struct StateT * v234(struct StateT * v235) {
  int v236 = v235->timer;
  int v254 = v236 + 1;
  v235->timer = v254;int * v238 = v235->regs;
  int v239 = v238[14];
  int * v240 = v235->regs;
  int v258 = v239 + 4;
  v240[14] = v258;
  struct StateT * v252 = v242(v235);
  return v252;
}

struct StateT * v13(struct StateT * v14) {
  int v15 = v14->timer;
  int v418 = v15 + 1;
  v14->timer = v418;int * v17 = v14->regs;
  v17[14] = 0;
  struct StateT * v416 = v19(v14);
  return v416;
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