// verify: leak (CBMC should report VERIFICATION FAILED) [unwind 33]
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
struct StateT * slot_2(struct StateT * v28);
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
  v18[10] = 80;
  struct StateT * v20 = slot_2(v15);
  return v20;
}

struct StateT * slot_2(struct StateT * v28) {
  int v29 = v28->timer;
  int v35 = v29 + 1;
  v28->timer = v35;
  int * v31 = v28->regs;
  v31[15] = 80;
  struct StateT * v33 = slot_3(v28);
  return v33;
}

struct StateT * slot_3(struct StateT * v41) {
  int * v42 = v41->saved_regs;
  int * v43 = v41->regs;
  int v44 = v43[5];
  v42[5] = v44;
  int v46 = v41->timer;
  int v206 = v46 + 1;
  v41->timer = v206;
  int * v48 = v41->regs;
  int v49 = v48[13];
  int * v50 = v41->regs;
  int v51 = v50[10];
  int * v52 = v41->regs;
  int v212 = v49 + v51;
  v52[5] = v212;
  int * v54 = v41->saved_regs;
  int * v55 = v41->regs;
  int v56 = v55[11];
  v54[11] = v56;
  int v58 = v41->timer;
  int v217 = v58 + 1;
  v41->timer = v217;
  int * v60 = v41->regs;
  int v61 = v60[5];
  int * v62 = v41->cache_keys;
  int v63 = v62[0];
  bool v221 = v63 == ((int)((unsigned int)v61 >> 2));
  int v111;
  if (v221) {
    int * v64 = v41->cache_vals;
    int v65 = v64[0];
    v111 = v65;
  } else {
    int * v67 = v41->cache_keys;
    int v68 = v67[1];
    bool v226 = v68 == ((int)((unsigned int)v61 >> 2));
    int v109;
    if (v226) {
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
      int v235 = (int)((unsigned int)v61 >> 2);
      v79[0] = v235;
      int * v81 = v41->cache_vals;
      v81[0] = v70;
      int v83 = v41->timer;
      int v238 = v83 + 1;
      v41->timer = v238;
      v109 = v70;
    } else {
      int * v86 = v41->mem;
      int v240 = (int)((unsigned int)v61 >> 2);
      int v87 = v86[v240];
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
      v102[0] = v240;
      int * v104 = v41->cache_vals;
      v104[0] = v87;
      int v106 = v41->timer;
      int v255 = v106 + 100;
      v41->timer = v255;
      v109 = v87;
    }
    v111 = v109;
  }
  int * v112 = v41->regs;
  v112[11] = v111;
  int v114 = v41->timer;
  int v259 = v114 + 1;
  v41->timer = v259;
  int * v116 = v41->regs;
  int v117 = v116[11];
  int * v118 = v41->regs;
  int v262 = v117 << 2;
  v118[11] = v262;
  int * v120 = v41->saved_regs;
  int * v121 = v41->regs;
  int v122 = v121[12];
  v120[12] = v122;
  int v124 = v41->timer;
  int v267 = v124 + 1;
  v41->timer = v267;
  int * v126 = v41->regs;
  int v127 = v126[11];
  int * v128 = v41->cache_keys;
  int v129 = v128[0];
  bool v270 = v129 == ((int)((unsigned int)v127 >> 2));
  int v177;
  if (v270) {
    int * v130 = v41->cache_vals;
    int v131 = v130[0];
    v177 = v131;
  } else {
    int * v133 = v41->cache_keys;
    int v134 = v133[1];
    bool v275 = v134 == ((int)((unsigned int)v127 >> 2));
    int v175;
    if (v275) {
      int * v135 = v41->cache_vals;
      int v136 = v135[1];
      int * v137 = v41->cache_keys;
      int * v138 = v41->cache_keys;
      int v139 = v138[0];
      v137[1] = v139;
      int * v141 = v41->cache_vals;
      int * v142 = v41->cache_vals;
      int v143 = v142[0];
      v141[1] = v143;
      int * v145 = v41->cache_keys;
      int v284 = (int)((unsigned int)v127 >> 2);
      v145[0] = v284;
      int * v147 = v41->cache_vals;
      v147[0] = v136;
      int v149 = v41->timer;
      int v287 = v149 + 1;
      v41->timer = v287;
      v175 = v136;
    } else {
      int * v152 = v41->mem;
      int v289 = (int)((unsigned int)v127 >> 2);
      int v153 = v152[v289];
      int * v154 = v41->mem;
      int * v155 = v41->cache_keys;
      int v156 = v155[1];
      int * v157 = v41->cache_vals;
      int v158 = v157[1];
      v154[v156] = v158;
      int * v160 = v41->cache_keys;
      int * v161 = v41->cache_keys;
      int v162 = v161[0];
      v160[1] = v162;
      int * v164 = v41->cache_vals;
      int * v165 = v41->cache_vals;
      int v166 = v165[0];
      v164[1] = v166;
      int * v168 = v41->cache_keys;
      v168[0] = v289;
      int * v170 = v41->cache_vals;
      v170[0] = v153;
      int v172 = v41->timer;
      int v304 = v172 + 100;
      v41->timer = v304;
      v175 = v153;
    }
    v177 = v175;
  }
  int * v178 = v41->regs;
  v178[12] = v177;
  int * v180 = v41->regs;
  int v181 = v180[10];
  int * v182 = v41->regs;
  int v183 = v182[15];
  bool v311 = v181 >= v183;
  if (v311) {
    int v184 = v41->timer;
    int v312 = v184 + 15;
    v41->timer = v312;
    int * v186 = v41->saved_regs;
    int v187 = v186[5];
    int * v188 = v41->regs;
    v188[5] = v187;
    int * v190 = v41->saved_regs;
    int v191 = v190[11];
    int * v192 = v41->regs;
    v192[11] = v191;
    int * v194 = v41->saved_regs;
    int v195 = v194[12];
    int * v196 = v41->regs;
    v196[12] = v195;
    ;
  } else {
    ;
  }
  return v41;
}

struct StateT * slot_0(struct StateT * v2) {
  int v3 = v2->timer;
  int v9 = v3 + 1;
  v2->timer = v9;
  int * v5 = v2->regs;
  v5[13] = 0;
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