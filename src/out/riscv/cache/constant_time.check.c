
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

struct StateT * v226(struct StateT * v227);
struct StateT * v19(struct StateT * v20);
struct StateT * v25(struct StateT * v26);
struct StateT * v72(struct StateT * v73);
struct StateT * v218(struct StateT * v219);
struct StateT * v130(struct StateT * v131);
struct StateT * v39(struct StateT * v40);
struct StateT * v208(struct StateT * v209);
struct StateT * snippet(struct StateT * v0);
struct StateT * v31(struct StateT * v32);
struct StateT * v62(struct StateT * v63);
struct StateT * v1(struct StateT * v2);
struct StateT * v140(struct StateT * v141);
struct StateT * v7(struct StateT * v8);
struct StateT * v198(struct StateT * v199);
struct StateT * v13(struct StateT * v14);
struct StateT * v226(struct StateT * v227) {
  int v228 = v227->timer;
  int v233 = v228 + 1;
  v227->timer = v233;struct StateT * v231 = v31(v227);
  return v231;
}

struct StateT * v19(struct StateT * v20) {
  int v21 = v20->timer;
  int v413 = v21 + 1;
  v20->timer = v413;int * v23 = v20->regs;
  v23[15] = 16;
  struct StateT * v411 = v25(v20);
  return v411;
}

struct StateT * v25(struct StateT * v26) {
  int v27 = v26->timer;
  int v405 = v27 + 1;
  v26->timer = v405;int * v29 = v26->regs;
  v29[5] = 0;
  struct StateT * v403 = v31(v26);
  return v403;
}

struct StateT * v72(struct StateT * v73) {
  int v74 = v73->timer;
  int v330 = v74 + 1;
  v73->timer = v330;int * v76 = v73->regs;
  int v77 = v76[6];
  int * v78 = v73->cache_keys;
  int v79 = v78[0];
  bool v335 = v79 == ((int)((unsigned int)v77 >> 2));
  int v127 = (v335 ? ({
    int * v80 = v73->cache_vals;
    int v81 = v80[0];
    v81;
  }) : ({
    int * v83 = v73->cache_keys;
    int v84 = v83[1];
    bool v340 = v84 == ((int)((unsigned int)v77 >> 2));
    int v125 = (v340 ? ({
      int * v85 = v73->cache_vals;
      int v86 = v85[1];
      int * v87 = v73->cache_keys;
      int * v88 = v73->cache_keys;
      int v89 = v88[0];
      v87[1] = v89;
      int * v91 = v73->cache_vals;
      int * v92 = v73->cache_vals;
      int v93 = v92[0];
      v91[1] = v93;
      int * v95 = v73->cache_keys;
      int v349 = (int)((unsigned int)v77 >> 2);
      v95[0] = v349;
      int * v97 = v73->cache_vals;
      v97[0] = v86;
      int v99 = v73->timer;
      int v352 = v99 + 1;
      v73->timer = v352;v86;
    }) : ({
      int * v102 = v73->mem;
      int v354 = (int)((unsigned int)v77 >> 2);
      int v103 = v102[v354];
      int * v104 = v73->mem;
      int * v105 = v73->cache_keys;
      int v106 = v105[1];
      int * v107 = v73->cache_vals;
      int v108 = v107[1];
      v104[v106] = v108;
      int * v110 = v73->cache_keys;
      int * v111 = v73->cache_keys;
      int v112 = v111[0];
      v110[1] = v112;
      int * v114 = v73->cache_vals;
      int * v115 = v73->cache_vals;
      int v116 = v115[0];
      v114[1] = v116;
      int * v118 = v73->cache_keys;
      v118[0] = v354;
      int * v120 = v73->cache_vals;
      v120[0] = v103;
      int v122 = v73->timer;
      int v369 = v122 + 100;
      v73->timer = v369;v103;
    }));
    v125;
  }));
  int * v128 = v73->regs;
  v128[7] = v127;
  struct StateT * v328 = v130(v73);
  return v328;
}

struct StateT * v218(struct StateT * v219) {
  int v220 = v219->timer;
  int v238 = v220 + 1;
  v219->timer = v238;int * v222 = v219->regs;
  int v223 = v222[14];
  int * v224 = v219->regs;
  int v242 = v223 + 4;
  v224[14] = v242;
  struct StateT * v236 = v226(v219);
  return v236;
}

struct StateT * v130(struct StateT * v131) {
  int v132 = v131->timer;
  int v318 = v132 + 1;
  v131->timer = v318;int * v134 = v131->regs;
  int v135 = v134[13];
  int * v136 = v131->regs;
  int v137 = v136[14];
  int * v138 = v131->regs;
  int v325 = v135 + v137;
  v138[8] = v325;
  struct StateT * v316 = v140(v131);
  return v316;
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

struct StateT * v208(struct StateT * v209) {
  int v210 = v209->timer;
  int v247 = v210 + 1;
  v209->timer = v247;int * v212 = v209->regs;
  int v213 = v212[5];
  int * v214 = v209->regs;
  int v215 = v214[16];
  int * v216 = v209->regs;
  int v253 = v213 | v215;
  v216[5] = v253;
  struct StateT * v245 = v218(v209);
  return v245;
}

struct StateT * snippet(struct StateT * v0) {
  struct StateT * v443 = v1(v0);
  return v443;
}

struct StateT * v31(struct StateT * v32) {
  int v33 = v32->timer;
  int v392 = v33 + 1;
  v32->timer = v392;int * v35 = v32->regs;
  int v36 = v35[14];
  int * v37 = v32->regs;
  int v38 = v37[15];
  bool v397 = v36 >= v38;
  struct StateT * v390 = (v397 ? ({
    struct StateT * v60 = v39(v32);
    v60;
  }) : ({
    struct StateT * v388 = v62(v32);
    v388;
  }));
  return v390;
}

struct StateT * v62(struct StateT * v63) {
  int v64 = v63->timer;
  int v378 = v64 + 1;
  v63->timer = v378;int * v66 = v63->regs;
  int v67 = v66[12];
  int * v68 = v63->regs;
  int v69 = v68[14];
  int * v70 = v63->regs;
  int v385 = v67 + v69;
  v70[6] = v385;
  struct StateT * v376 = v72(v63);
  return v376;
}

struct StateT * v1(struct StateT * v2) {
  int v3 = v2->timer;
  int v437 = v3 + 1;
  v2->timer = v437;int * v5 = v2->regs;
  v5[12] = 0;
  struct StateT * v435 = v7(v2);
  return v435;
}

struct StateT * v140(struct StateT * v141) {
  int v142 = v141->timer;
  int v270 = v142 + 1;
  v141->timer = v270;int * v144 = v141->regs;
  int v145 = v144[8];
  int * v146 = v141->cache_keys;
  int v147 = v146[0];
  bool v275 = v147 == ((int)((unsigned int)v145 >> 2));
  int v195 = (v275 ? ({
    int * v148 = v141->cache_vals;
    int v149 = v148[0];
    v149;
  }) : ({
    int * v151 = v141->cache_keys;
    int v152 = v151[1];
    bool v280 = v152 == ((int)((unsigned int)v145 >> 2));
    int v193 = (v280 ? ({
      int * v153 = v141->cache_vals;
      int v154 = v153[1];
      int * v155 = v141->cache_keys;
      int * v156 = v141->cache_keys;
      int v157 = v156[0];
      v155[1] = v157;
      int * v159 = v141->cache_vals;
      int * v160 = v141->cache_vals;
      int v161 = v160[0];
      v159[1] = v161;
      int * v163 = v141->cache_keys;
      int v289 = (int)((unsigned int)v145 >> 2);
      v163[0] = v289;
      int * v165 = v141->cache_vals;
      v165[0] = v154;
      int v167 = v141->timer;
      int v292 = v167 + 1;
      v141->timer = v292;v154;
    }) : ({
      int * v170 = v141->mem;
      int v294 = (int)((unsigned int)v145 >> 2);
      int v171 = v170[v294];
      int * v172 = v141->mem;
      int * v173 = v141->cache_keys;
      int v174 = v173[1];
      int * v175 = v141->cache_vals;
      int v176 = v175[1];
      v172[v174] = v176;
      int * v178 = v141->cache_keys;
      int * v179 = v141->cache_keys;
      int v180 = v179[0];
      v178[1] = v180;
      int * v182 = v141->cache_vals;
      int * v183 = v141->cache_vals;
      int v184 = v183[0];
      v182[1] = v184;
      int * v186 = v141->cache_keys;
      v186[0] = v294;
      int * v188 = v141->cache_vals;
      v188[0] = v171;
      int v190 = v141->timer;
      int v309 = v190 + 100;
      v141->timer = v309;v171;
    }));
    v193;
  }));
  int * v196 = v141->regs;
  v196[9] = v195;
  struct StateT * v268 = v198(v141);
  return v268;
}

struct StateT * v7(struct StateT * v8) {
  int v9 = v8->timer;
  int v429 = v9 + 1;
  v8->timer = v429;int * v11 = v8->regs;
  v11[13] = 80;
  struct StateT * v427 = v13(v8);
  return v427;
}

struct StateT * v198(struct StateT * v199) {
  int v200 = v199->timer;
  int v258 = v200 + 1;
  v199->timer = v258;int * v202 = v199->regs;
  int v203 = v202[7];
  int * v204 = v199->regs;
  int v205 = v204[9];
  int * v206 = v199->regs;
  int v265 = v203 ^ v205;
  v206[16] = v265;
  struct StateT * v256 = v208(v199);
  return v256;
}

struct StateT * v13(struct StateT * v14) {
  int v15 = v14->timer;
  int v421 = v15 + 1;
  v14->timer = v421;int * v17 = v14->regs;
  v17[14] = 0;
  struct StateT * v419 = v19(v14);
  return v419;
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