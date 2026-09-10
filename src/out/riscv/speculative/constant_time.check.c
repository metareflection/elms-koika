
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

struct StateT * snippet(struct StateT * v0);
struct StateT * v19(struct StateT * v20);
struct StateT * v31(struct StateT * v32);
struct StateT * v25(struct StateT * v26);
struct StateT * v1(struct StateT * v2);
struct StateT * v231(struct StateT * v232);
struct StateT * v7(struct StateT * v8);
struct StateT * v13(struct StateT * v14);
struct StateT * v260(struct StateT * v261);
struct StateT * snippet(struct StateT * v0) {
  struct StateT * v476 = v1(v0);
  return v476;
}

struct StateT * v19(struct StateT * v20) {
  int v21 = v20->timer;
  int v446 = v21 + 1;
  v20->timer = v446;int * v23 = v20->regs;
  v23[15] = 16;
  struct StateT * v444 = v25(v20);
  return v444;
}

struct StateT * v31(struct StateT * v32) {
  int * v33 = v32->saved_regs;
  int * v34 = v32->regs;
  int v35 = v34[6];
  v33[6] = v35;
  int v37 = v32->timer;
  int v278 = v37 + 1;
  v32->timer = v278;int * v39 = v32->regs;
  int v40 = v39[12];
  int * v41 = v32->regs;
  int v42 = v41[14];
  int * v43 = v32->regs;
  int v284 = v40 + v42;
  v43[6] = v284;
  int * v45 = v32->saved_regs;
  int * v46 = v32->regs;
  int v47 = v46[7];
  v45[7] = v47;
  int v49 = v32->timer;
  int v289 = v49 + 1;
  v32->timer = v289;int * v51 = v32->regs;
  int v52 = v51[6];
  int * v53 = v32->cache_keys;
  int v54 = v53[0];
  bool v293 = v54 == ((int)((unsigned int)v52 >> 2));
  int v102 = (v293 ? ({
    int * v55 = v32->cache_vals;
    int v56 = v55[0];
    v56;
  }) : ({
    int * v58 = v32->cache_keys;
    int v59 = v58[1];
    bool v298 = v59 == ((int)((unsigned int)v52 >> 2));
    int v100 = (v298 ? ({
      int * v60 = v32->cache_vals;
      int v61 = v60[1];
      int * v62 = v32->cache_keys;
      int * v63 = v32->cache_keys;
      int v64 = v63[0];
      v62[1] = v64;
      int * v66 = v32->cache_vals;
      int * v67 = v32->cache_vals;
      int v68 = v67[0];
      v66[1] = v68;
      int * v70 = v32->cache_keys;
      int v307 = (int)((unsigned int)v52 >> 2);
      v70[0] = v307;
      int * v72 = v32->cache_vals;
      v72[0] = v61;
      int v74 = v32->timer;
      int v310 = v74 + 1;
      v32->timer = v310;v61;
    }) : ({
      int * v77 = v32->mem;
      int v312 = (int)((unsigned int)v52 >> 2);
      int v78 = v77[v312];
      int * v79 = v32->mem;
      int * v80 = v32->cache_keys;
      int v81 = v80[1];
      int * v82 = v32->cache_vals;
      int v83 = v82[1];
      v79[v81] = v83;
      int * v85 = v32->cache_keys;
      int * v86 = v32->cache_keys;
      int v87 = v86[0];
      v85[1] = v87;
      int * v89 = v32->cache_vals;
      int * v90 = v32->cache_vals;
      int v91 = v90[0];
      v89[1] = v91;
      int * v93 = v32->cache_keys;
      v93[0] = v312;
      int * v95 = v32->cache_vals;
      v95[0] = v78;
      int v97 = v32->timer;
      int v327 = v97 + 100;
      v32->timer = v327;v78;
    }));
    v100;
  }));
  int * v103 = v32->regs;
  v103[7] = v102;
  int * v105 = v32->saved_regs;
  int * v106 = v32->regs;
  int v107 = v106[8];
  v105[8] = v107;
  int v109 = v32->timer;
  int v335 = v109 + 1;
  v32->timer = v335;int * v111 = v32->regs;
  int v112 = v111[13];
  int * v113 = v32->regs;
  int v114 = v113[14];
  int * v115 = v32->regs;
  int v340 = v112 + v114;
  v115[8] = v340;
  int * v117 = v32->saved_regs;
  int * v118 = v32->regs;
  int v119 = v118[9];
  v117[9] = v119;
  int v121 = v32->timer;
  int v345 = v121 + 1;
  v32->timer = v345;int * v123 = v32->regs;
  int v124 = v123[8];
  int * v125 = v32->cache_keys;
  int v126 = v125[0];
  bool v348 = v126 == ((int)((unsigned int)v124 >> 2));
  int v174 = (v348 ? ({
    int * v127 = v32->cache_vals;
    int v128 = v127[0];
    v128;
  }) : ({
    int * v130 = v32->cache_keys;
    int v131 = v130[1];
    bool v353 = v131 == ((int)((unsigned int)v124 >> 2));
    int v172 = (v353 ? ({
      int * v132 = v32->cache_vals;
      int v133 = v132[1];
      int * v134 = v32->cache_keys;
      int * v135 = v32->cache_keys;
      int v136 = v135[0];
      v134[1] = v136;
      int * v138 = v32->cache_vals;
      int * v139 = v32->cache_vals;
      int v140 = v139[0];
      v138[1] = v140;
      int * v142 = v32->cache_keys;
      int v362 = (int)((unsigned int)v124 >> 2);
      v142[0] = v362;
      int * v144 = v32->cache_vals;
      v144[0] = v133;
      int v146 = v32->timer;
      int v365 = v146 + 1;
      v32->timer = v365;v133;
    }) : ({
      int * v149 = v32->mem;
      int v367 = (int)((unsigned int)v124 >> 2);
      int v150 = v149[v367];
      int * v151 = v32->mem;
      int * v152 = v32->cache_keys;
      int v153 = v152[1];
      int * v154 = v32->cache_vals;
      int v155 = v154[1];
      v151[v153] = v155;
      int * v157 = v32->cache_keys;
      int * v158 = v32->cache_keys;
      int v159 = v158[0];
      v157[1] = v159;
      int * v161 = v32->cache_vals;
      int * v162 = v32->cache_vals;
      int v163 = v162[0];
      v161[1] = v163;
      int * v165 = v32->cache_keys;
      v165[0] = v367;
      int * v167 = v32->cache_vals;
      v167[0] = v150;
      int v169 = v32->timer;
      int v382 = v169 + 100;
      v32->timer = v382;v150;
    }));
    v172;
  }));
  int * v175 = v32->regs;
  v175[9] = v174;
  int * v177 = v32->saved_regs;
  int * v178 = v32->regs;
  int v179 = v178[16];
  v177[16] = v179;
  int v181 = v32->timer;
  int v390 = v181 + 1;
  v32->timer = v390;int * v183 = v32->regs;
  int v184 = v183[7];
  int * v185 = v32->regs;
  int v186 = v185[9];
  int * v187 = v32->regs;
  int v394 = v184 ^ v186;
  v187[16] = v394;
  int * v189 = v32->saved_regs;
  int * v190 = v32->regs;
  int v191 = v190[5];
  v189[5] = v191;
  int v193 = v32->timer;
  int v399 = v193 + 1;
  v32->timer = v399;int * v195 = v32->regs;
  int v196 = v195[5];
  int * v197 = v32->regs;
  int v198 = v197[16];
  int * v199 = v32->regs;
  int v403 = v196 | v198;
  v199[5] = v403;
  int * v201 = v32->regs;
  int v202 = v201[14];
  int * v203 = v32->regs;
  int v204 = v203[15];
  bool v407 = v202 >= v204;
  if (v407) {
    int v205 = v32->timer;
    int v408 = v205 + 15;
    v32->timer = v408;int * v207 = v32->saved_regs;
    int v208 = v207[6];
    int * v209 = v32->regs;
    v209[6] = v208;
    int * v211 = v32->saved_regs;
    int v212 = v211[7];
    int * v213 = v32->regs;
    v213[7] = v212;
    int * v215 = v32->saved_regs;
    int v216 = v215[8];
    int * v217 = v32->regs;
    v217[8] = v216;
    int * v219 = v32->saved_regs;
    int v220 = v219[9];
    int * v221 = v32->regs;
    v221[9] = v220;
    int * v223 = v32->saved_regs;
    int v224 = v223[16];
    int * v225 = v32->regs;
    v225[16] = v224;
    int * v227 = v32->saved_regs;
    int v228 = v227[5];
    int * v229 = v32->regs;
    v229[5] = v228;
    struct StateT * v252 = v231(v32);
    ;
  } else {
    int v254 = v32->timer;
    int v429 = v254 + 1;
    v32->timer = v429;int * v256 = v32->regs;
    int v257 = v256[14];
    int * v258 = v32->regs;
    int v432 = v257 + 4;
    v258[14] = v432;
    struct StateT * v270 = v260(v32);
    ;
  }
  return v270;
}

struct StateT * v25(struct StateT * v26) {
  int v27 = v26->timer;
  int v438 = v27 + 1;
  v26->timer = v438;int * v29 = v26->regs;
  v29[5] = 0;
  struct StateT * v436 = v31(v26);
  return v436;
}

struct StateT * v1(struct StateT * v2) {
  int v3 = v2->timer;
  int v470 = v3 + 1;
  v2->timer = v470;int * v5 = v2->regs;
  v5[12] = 0;
  struct StateT * v468 = v7(v2);
  return v468;
}

struct StateT * v231(struct StateT * v232) {
  int v233 = v232->timer;
  int v243 = v233 + 1;
  v232->timer = v243;int * v235 = v232->regs;
  int v236 = v235[5];
  bool v246 = (v236 ^ -2147483648) < -2147483647;
  int v239 = (v246 ? 1 : 0);
  int * v240 = v232->regs;
  v240[11] = v239;
  return v232;
}

struct StateT * v7(struct StateT * v8) {
  int v9 = v8->timer;
  int v462 = v9 + 1;
  v8->timer = v462;int * v11 = v8->regs;
  v11[13] = 80;
  struct StateT * v460 = v13(v8);
  return v460;
}

struct StateT * v13(struct StateT * v14) {
  int v15 = v14->timer;
  int v454 = v15 + 1;
  v14->timer = v454;int * v17 = v14->regs;
  v17[14] = 0;
  struct StateT * v452 = v19(v14);
  return v452;
}

struct StateT * v260(struct StateT * v261) {
  int v262 = v261->timer;
  int v267 = v262 + 1;
  v261->timer = v267;struct StateT * v265 = v31(v261);
  return v265;
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