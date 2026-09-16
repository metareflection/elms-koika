// verify: clean (CBMC should report VERIFICATION SUCCESSFUL) [unwind 33]
#define NUM_REGS 32
#define MEM_SIZE 30
#define SECRET_SIZE 10
#define SECRET_OFFSET 20
#define CACHE_LRU_SIZE 10

#ifdef CBMC
int nondet_uint();
#define koika_assert(b, s) __CPROVER_assert(b, s)
#define koika_assume(b) __CPROVER_assume(b)
#define koika_draw(x) ((x) = nondet_uint())
#else
#define koika_assert(b, s) 0
#define koika_assume(b) 0
#define koika_draw(x) ((x) = 0)
#endif
int bounded(int low, int high) {
  int x;
  koika_draw(x);
  koika_assume(low <= x && x <= high);
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
struct StateT * slot_1(struct StateT * v15);
struct StateT * slot_8(struct StateT * v399);
struct StateT * slot_9(struct StateT * v415);
struct StateT * slot_2(struct StateT * v28);
struct StateT * slot_7(struct StateT * v294);
struct StateT * slot_3(struct StateT * v41);
struct StateT * slot_0(struct StateT * v2);
struct StateT * snippet(struct StateT * v0) {
  struct StateT * v1 = slot_0(v0);
  return v1;
}

struct StateT * slot_1(struct StateT * v15) {
  int v16 = v15->timer;
  int v22 = v16 + 1;
  v15->timer = v22;
  int * v18 = v15->regs;
  v18[7] = 16;
  struct StateT * v20 = slot_2(v15);
  return v20;
}

struct StateT * slot_8(struct StateT * v399) {
  int v400 = v399->timer;
  int v408 = v400 + 1;
  v399->timer = v408;
  int * v402 = v399->regs;
  int v403 = v402[6];
  int * v404 = v399->regs;
  int v412 = v403 + 4;
  v404[6] = v412;
  struct StateT * v406 = slot_9(v399);
  return v406;
}

struct StateT * slot_9(struct StateT * v415) {
  int v416 = v415->timer;
  int v420 = v416 + 1;
  v415->timer = v420;
  struct StateT * v418 = slot_3(v415);
  return v418;
}

struct StateT * slot_2(struct StateT * v28) {
  int v29 = v28->timer;
  int v35 = v29 + 1;
  v28->timer = v35;
  int * v31 = v28->regs;
  v31[9] = 80;
  struct StateT * v33 = slot_3(v28);
  return v33;
}

struct StateT * slot_7(struct StateT * v294) {
  int v295 = v294->timer;
  int v353 = v295 + 1;
  v294->timer = v353;
  int * v297 = v294->regs;
  int v298 = v297[6];
  int * v299 = v294->cache_keys;
  int v300 = v299[0];
  bool v358 = v300 == ((int)((unsigned int)v298 >> 2));
  int v348;
  if (v358) {
    int * v301 = v294->cache_vals;
    int v302 = v301[0];
    v348 = v302;
  } else {
    int * v304 = v294->cache_keys;
    int v305 = v304[1];
    bool v363 = v305 == ((int)((unsigned int)v298 >> 2));
    int v346;
    if (v363) {
      int * v306 = v294->cache_vals;
      int v307 = v306[1];
      int * v308 = v294->cache_keys;
      int * v309 = v294->cache_keys;
      int v310 = v309[0];
      v308[1] = v310;
      int * v312 = v294->cache_vals;
      int * v313 = v294->cache_vals;
      int v314 = v313[0];
      v312[1] = v314;
      int * v316 = v294->cache_keys;
      int v372 = (int)((unsigned int)v298 >> 2);
      v316[0] = v372;
      int * v318 = v294->cache_vals;
      v318[0] = v307;
      int v320 = v294->timer;
      int v375 = v320 + 1;
      v294->timer = v375;
      v346 = v307;
    } else {
      int * v323 = v294->mem;
      int v377 = (int)((unsigned int)v298 >> 2);
      int v324 = v323[v377];
      int * v325 = v294->mem;
      int * v326 = v294->cache_keys;
      int v327 = v326[1];
      int * v328 = v294->cache_vals;
      int v329 = v328[1];
      v325[v327] = v329;
      int * v331 = v294->cache_keys;
      int * v332 = v294->cache_keys;
      int v333 = v332[0];
      v331[1] = v333;
      int * v335 = v294->cache_vals;
      int * v336 = v294->cache_vals;
      int v337 = v336[0];
      v335[1] = v337;
      int * v339 = v294->cache_keys;
      v339[0] = v377;
      int * v341 = v294->cache_vals;
      v341[0] = v324;
      int v343 = v294->timer;
      int v392 = v343 + 100;
      v294->timer = v392;
      v346 = v324;
    }
    v348 = v346;
  }
  int * v349 = v294->regs;
  v349[11] = v348;
  struct StateT * v351 = slot_8(v294);
  return v351;
}

struct StateT * slot_3(struct StateT * v41) {
  int * v42 = v41->saved_regs;
  int * v43 = v41->regs;
  int v44 = v43[8];
  v42[8] = v44;
  int v46 = v41->timer;
  int v189 = v46 + 1;
  v41->timer = v189;
  int * v48 = v41->regs;
  int v49 = v48[9];
  int * v50 = v41->regs;
  int v51 = v50[6];
  int * v52 = v41->regs;
  int v195 = v49 + v51;
  v52[8] = v195;
  int * v54 = v41->saved_regs;
  int * v55 = v41->regs;
  int v56 = v55[5];
  v54[5] = v56;
  int v58 = v41->timer;
  int v200 = v58 + 1;
  v41->timer = v200;
  int * v60 = v41->regs;
  int v61 = v60[8];
  int * v62 = v41->cache_keys;
  int v63 = v62[0];
  bool v204 = v63 == ((int)((unsigned int)v61 >> 2));
  int v111;
  if (v204) {
    int * v64 = v41->cache_vals;
    int v65 = v64[0];
    v111 = v65;
  } else {
    int * v67 = v41->cache_keys;
    int v68 = v67[1];
    bool v209 = v68 == ((int)((unsigned int)v61 >> 2));
    int v109;
    if (v209) {
      int * v69 = v41->cache_vals;
      int v70 = v69[1];
      int * v71 = v41->cache_keys;
      int * v72 = v41->cache_keys;
      int v73 = v72[0];
      v71[1] = v73;
      int * v75 = v41->cache_vals;
      int * v76 = v41->cache_vals;
      int v77 = v76[0];
      v75[1] = v77;
      int * v79 = v41->cache_keys;
      int v218 = (int)((unsigned int)v61 >> 2);
      v79[0] = v218;
      int * v81 = v41->cache_vals;
      v81[0] = v70;
      int v83 = v41->timer;
      int v221 = v83 + 1;
      v41->timer = v221;
      v109 = v70;
    } else {
      int * v86 = v41->mem;
      int v223 = (int)((unsigned int)v61 >> 2);
      int v87 = v86[v223];
      int * v88 = v41->mem;
      int * v89 = v41->cache_keys;
      int v90 = v89[1];
      int * v91 = v41->cache_vals;
      int v92 = v91[1];
      v88[v90] = v92;
      int * v94 = v41->cache_keys;
      int * v95 = v41->cache_keys;
      int v96 = v95[0];
      v94[1] = v96;
      int * v98 = v41->cache_vals;
      int * v99 = v41->cache_vals;
      int v100 = v99[0];
      v98[1] = v100;
      int * v102 = v41->cache_keys;
      v102[0] = v223;
      int * v104 = v41->cache_vals;
      v104[0] = v87;
      int v106 = v41->timer;
      int v238 = v106 + 100;
      v41->timer = v238;
      v109 = v87;
    }
    v111 = v109;
  }
  int * v112 = v41->regs;
  v112[5] = v111;
  int * v114 = v41->regs;
  int v115 = v114[6];
  int * v116 = v41->regs;
  int v117 = v116[7];
  bool v245 = v115 >= v117;
  struct StateT * v183;
  if (v245) {
    int v118 = v41->timer;
    int v246 = v118 + 15;
    v41->timer = v246;
    int * v120 = v41->saved_regs;
    int v121 = v120[8];
    int * v122 = v41->regs;
    v122[8] = v121;
    int * v124 = v41->saved_regs;
    int v125 = v124[5];
    int * v126 = v41->regs;
    v126[5] = v125;
    v183 = v41;
  } else {
    int v129 = v41->timer;
    int v253 = v129 + 1;
    v41->timer = v253;
    int * v131 = v41->regs;
    int v132 = v131[6];
    int * v133 = v41->regs;
    int v134 = v133[5];
    int * v135 = v41->cache_keys;
    int v136 = v135[0];
    bool v257 = v136 == ((int)((unsigned int)v132 >> 2));
    int v180;
    if (v257) {
      int * v137 = v41->cache_vals;
      v137[0] = v134;
      v180 = v134;
    } else {
      int * v140 = v41->cache_keys;
      int v141 = v140[1];
      bool v262 = v141 == ((int)((unsigned int)v132 >> 2));
      int v178;
      if (v262) {
        int * v142 = v41->cache_keys;
        int * v143 = v41->cache_keys;
        int v144 = v143[0];
        v142[1] = v144;
        int * v146 = v41->cache_vals;
        int * v147 = v41->cache_vals;
        int v148 = v147[0];
        v146[1] = v148;
        int * v150 = v41->cache_keys;
        int v270 = (int)((unsigned int)v132 >> 2);
        v150[0] = v270;
        int * v152 = v41->cache_vals;
        v152[0] = v134;
        int v154 = v41->timer;
        int v273 = v154 + 1;
        v41->timer = v273;
        v178 = v134;
      } else {
        int * v157 = v41->mem;
        int * v158 = v41->cache_keys;
        int v159 = v158[1];
        int * v160 = v41->cache_vals;
        int v161 = v160[1];
        v157[v159] = v161;
        int * v163 = v41->cache_keys;
        int * v164 = v41->cache_keys;
        int v165 = v164[0];
        v163[1] = v165;
        int * v167 = v41->cache_vals;
        int * v168 = v41->cache_vals;
        int v169 = v168[0];
        v167[1] = v169;
        int * v171 = v41->cache_keys;
        int v286 = (int)((unsigned int)v132 >> 2);
        v171[0] = v286;
        int * v173 = v41->cache_vals;
        v173[0] = v134;
        int v175 = v41->timer;
        int v289 = v175 + 100;
        v41->timer = v289;
        v178 = v134;
      }
      v180 = v178;
    }
    struct StateT * v181 = slot_7(v41);
    v183 = v181;
  }
  return v183;
}

struct StateT * slot_0(struct StateT * v2) {
  int v3 = v2->timer;
  int v9 = v3 + 1;
  v2->timer = v9;
  int * v5 = v2->regs;
  v5[6] = 0;
  struct StateT * v7 = slot_1(v2);
  return v7;
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
  koika_assert(s1_->timer==s2_->timer, "timing leak");
  return 0;
}