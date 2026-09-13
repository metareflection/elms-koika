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

struct StateT * v124(struct StateT * v125);
struct StateT * v19(struct StateT * v20);
struct StateT * v46(struct StateT * v47);
struct StateT * v25(struct StateT * v26);
struct StateT * v182(struct StateT * v183);
struct StateT * v114(struct StateT * v115);
struct StateT * v190(struct StateT * v191);
struct StateT * v220(struct StateT * v221);
struct StateT * snippet(struct StateT * v0);
struct StateT * v212(struct StateT * v213);
struct StateT * v1(struct StateT * v2);
struct StateT * v56(struct StateT * v57);
struct StateT * v7(struct StateT * v8);
struct StateT * v33(struct StateT * v34);
struct StateT * v13(struct StateT * v14);
struct StateT * v196(struct StateT * v197);
struct StateT * v124(struct StateT * v125) {
  int v126 = v125->timer;
  int v256 = v126 + 1;
  v125->timer = v256;
  int * v128 = v125->regs;
  int v129 = v128[6];
  int * v130 = v125->cache_keys;
  int v131 = v130[0];
  bool v261 = v131 == ((int)((unsigned int)v129 >> 2));
  int v179;
  if (v261) {
    int * v132 = v125->cache_vals;
    int v133 = v132[0];
    v179 = v133;
  } else {
    int * v135 = v125->cache_keys;
    int v136 = v135[1];
    bool v266 = v136 == ((int)((unsigned int)v129 >> 2));
    int v177;
    if (v266) {
      int * v137 = v125->cache_vals;
      int v138 = v137[1];
      int * v139 = v125->cache_keys;
      int * v140 = v125->cache_keys;
      int v141 = v140[0];
      v139[1] = v141;
      int * v143 = v125->cache_vals;
      int * v144 = v125->cache_vals;
      int v145 = v144[0];
      v143[1] = v145;
      int * v147 = v125->cache_keys;
      int v275 = (int)((unsigned int)v129 >> 2);
      v147[0] = v275;
      int * v149 = v125->cache_vals;
      v149[0] = v138;
      int v151 = v125->timer;
      int v278 = v151 + 1;
      v125->timer = v278;
      v177 = v138;
    } else {
      int * v154 = v125->mem;
      int v280 = (int)((unsigned int)v129 >> 2);
      int v155 = v154[v280];
      int * v156 = v125->mem;
      int * v157 = v125->cache_keys;
      int v158 = v157[1];
      int * v159 = v125->cache_vals;
      int v160 = v159[1];
      v156[v158] = v160;
      int * v162 = v125->cache_keys;
      int * v163 = v125->cache_keys;
      int v164 = v163[0];
      v162[1] = v164;
      int * v166 = v125->cache_vals;
      int * v167 = v125->cache_vals;
      int v168 = v167[0];
      v166[1] = v168;
      int * v170 = v125->cache_keys;
      v170[0] = v280;
      int * v172 = v125->cache_vals;
      v172[0] = v155;
      int v174 = v125->timer;
      int v295 = v174 + 100;
      v125->timer = v295;
      v177 = v155;
    }
    v179 = v177;
  }
  int * v180 = v125->regs;
  v180[11] = v179;
  struct StateT * v254 = v182(v125);
  return v254;
}

struct StateT * v19(struct StateT * v20) {
  int v21 = v20->timer;
  int v391 = v21 + 1;
  v20->timer = v391;
  int * v23 = v20->regs;
  v23[15] = 16;
  struct StateT * v389 = v25(v20);
  return v389;
}

struct StateT * v46(struct StateT * v47) {
  int v48 = v47->timer;
  int v364 = v48 + 1;
  v47->timer = v364;
  int * v50 = v47->regs;
  int v51 = v50[12];
  int * v52 = v47->regs;
  int v53 = v52[14];
  int * v54 = v47->regs;
  int v371 = v51 + v53;
  v54[5] = v371;
  struct StateT * v362 = v56(v47);
  return v362;
}

struct StateT * v25(struct StateT * v26) {
  int v27 = v26->timer;
  int v378 = v27 + 1;
  v26->timer = v378;
  int * v29 = v26->regs;
  int v30 = v29[14];
  int * v31 = v26->regs;
  int v32 = v31[15];
  bool v383 = v30 >= v32;
  struct StateT * v376;
  if (v383) {
    struct StateT * v44 = v33(v26);
    v376 = v44;
  } else {
    struct StateT * v374 = v46(v26);
    v376 = v374;
  }
  return v376;
}

struct StateT * v182(struct StateT * v183) {
  int v184 = v183->timer;
  int v243 = v184 + 1;
  v183->timer = v243;
  int * v186 = v183->regs;
  int v187 = v186[10];
  int * v188 = v183->regs;
  int v189 = v188[11];
  bool v248 = !(v187 == v189);
  struct StateT * v241;
  if (v248) {
    struct StateT * v210 = v190(v183);
    v241 = v210;
  } else {
    struct StateT * v239 = v212(v183);
    v241 = v239;
  }
  return v241;
}

struct StateT * v114(struct StateT * v115) {
  int v116 = v115->timer;
  int v304 = v116 + 1;
  v115->timer = v304;
  int * v118 = v115->regs;
  int v119 = v118[13];
  int * v120 = v115->regs;
  int v121 = v120[14];
  int * v122 = v115->regs;
  int v311 = v119 + v121;
  v122[6] = v311;
  struct StateT * v302 = v124(v115);
  return v302;
}

struct StateT * v190(struct StateT * v191) {
  int v192 = v191->timer;
  int v204 = v192 + 1;
  v191->timer = v204;
  int * v194 = v191->regs;
  v194[10] = 0;
  struct StateT * v202 = v196(v191);
  return v202;
}

struct StateT * v220(struct StateT * v221) {
  int v222 = v221->timer;
  int v227 = v222 + 1;
  v221->timer = v227;
  struct StateT * v225 = v25(v221);
  return v225;
}

struct StateT * snippet(struct StateT * v0) {
  struct StateT * v421 = v1(v0);
  return v421;
}

struct StateT * v212(struct StateT * v213) {
  int v214 = v213->timer;
  int v232 = v214 + 1;
  v213->timer = v232;
  int * v216 = v213->regs;
  int v217 = v216[14];
  int * v218 = v213->regs;
  int v236 = v217 + 4;
  v218[14] = v236;
  struct StateT * v230 = v220(v213);
  return v230;
}

struct StateT * v1(struct StateT * v2) {
  int v3 = v2->timer;
  int v415 = v3 + 1;
  v2->timer = v415;
  int * v5 = v2->regs;
  v5[12] = 0;
  struct StateT * v413 = v7(v2);
  return v413;
}

struct StateT * v56(struct StateT * v57) {
  int v58 = v57->timer;
  int v316 = v58 + 1;
  v57->timer = v316;
  int * v60 = v57->regs;
  int v61 = v60[5];
  int * v62 = v57->cache_keys;
  int v63 = v62[0];
  bool v321 = v63 == ((int)((unsigned int)v61 >> 2));
  int v111;
  if (v321) {
    int * v64 = v57->cache_vals;
    int v65 = v64[0];
    v111 = v65;
  } else {
    int * v67 = v57->cache_keys;
    int v68 = v67[1];
    bool v326 = v68 == ((int)((unsigned int)v61 >> 2));
    int v109;
    if (v326) {
      int * v69 = v57->cache_vals;
      int v70 = v69[1];
      int * v71 = v57->cache_keys;
      int * v72 = v57->cache_keys;
      int v73 = v72[0];
      v71[1] = v73;
      int * v75 = v57->cache_vals;
      int * v76 = v57->cache_vals;
      int v77 = v76[0];
      v75[1] = v77;
      int * v79 = v57->cache_keys;
      int v335 = (int)((unsigned int)v61 >> 2);
      v79[0] = v335;
      int * v81 = v57->cache_vals;
      v81[0] = v70;
      int v83 = v57->timer;
      int v338 = v83 + 1;
      v57->timer = v338;
      v109 = v70;
    } else {
      int * v86 = v57->mem;
      int v340 = (int)((unsigned int)v61 >> 2);
      int v87 = v86[v340];
      int * v88 = v57->mem;
      int * v89 = v57->cache_keys;
      int v90 = v89[1];
      int * v91 = v57->cache_vals;
      int v92 = v91[1];
      v88[v90] = v92;
      int * v94 = v57->cache_keys;
      int * v95 = v57->cache_keys;
      int v96 = v95[0];
      v94[1] = v96;
      int * v98 = v57->cache_vals;
      int * v99 = v57->cache_vals;
      int v100 = v99[0];
      v98[1] = v100;
      int * v102 = v57->cache_keys;
      v102[0] = v340;
      int * v104 = v57->cache_vals;
      v104[0] = v87;
      int v106 = v57->timer;
      int v355 = v106 + 100;
      v57->timer = v355;
      v109 = v87;
    }
    v111 = v109;
  }
  int * v112 = v57->regs;
  v112[10] = v111;
  struct StateT * v314 = v114(v57);
  return v314;
}

struct StateT * v7(struct StateT * v8) {
  int v9 = v8->timer;
  int v407 = v9 + 1;
  v8->timer = v407;
  int * v11 = v8->regs;
  v11[13] = 80;
  struct StateT * v405 = v13(v8);
  return v405;
}

struct StateT * v33(struct StateT * v34) {
  int v35 = v34->timer;
  int v40 = v35 + 1;
  v34->timer = v40;
  int * v37 = v34->regs;
  v37[10] = 1;
  return v34;
}

struct StateT * v13(struct StateT * v14) {
  int v15 = v14->timer;
  int v399 = v15 + 1;
  v14->timer = v399;
  int * v17 = v14->regs;
  v17[14] = 0;
  struct StateT * v397 = v19(v14);
  return v397;
}

struct StateT * v196(struct StateT * v197) {
  int v198 = v197->timer;
  int v201 = v198 + 1;
  v197->timer = v201;
  return v197;
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