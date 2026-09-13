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

struct StateT * v43(struct StateT * v44);
struct StateT * v57(struct StateT * v58);
struct StateT * v15(struct StateT * v16);
struct StateT * v107(struct StateT * v108);
struct StateT * v131(struct StateT * v132);
struct StateT * v123(struct StateT * v124);
struct StateT * v115(struct StateT * v116);
struct StateT * v9(struct StateT * v10);
struct StateT * v91(struct StateT * v92);
struct StateT * snippet(struct StateT * v0);
struct StateT * v1(struct StateT * v2);
struct StateT * v29(struct StateT * v30);
struct StateT * v85(struct StateT * v86);
struct StateT * v77(struct StateT * v78);
struct StateT * v67(struct StateT * v68);
struct StateT * v35(struct StateT * v36);
struct StateT * v21(struct StateT * v22);
struct StateT * v49(struct StateT * v50);
struct StateT * v43(struct StateT * v44) {
  int v45 = v44->timer;
  int v230 = v45 + 1;
  v44->timer = v230;int * v47 = v44->regs;
  v47[13] = 0;
  struct StateT * v228 = v49(v44);
  return v228;
}

struct StateT * v57(struct StateT * v58) {
  int v59 = v58->timer;
  int v209 = v59 + 1;
  v58->timer = v209;int * v61 = v58->regs;
  int v62 = v61[12];
  int * v63 = v58->mem;
  int v213 = (int)((unsigned int)v62 >> 2);
  int v64 = v63[v213];
  int * v65 = v58->regs;
  v65[14] = v64;
  struct StateT * v207 = v67(v58);
  return v207;
}

struct StateT * v15(struct StateT * v16) {
  int v17 = v16->timer;
  int v257 = v17 + 1;
  v16->timer = v257;int * v19 = v16->regs;
  int v20 = v19[11];
  bool v260 = 0 >= v20;
  struct StateT * v255 = (v260 ? ({
    struct StateT * v27 = v21(v16);
    v27;
  }) : ({
    struct StateT * v253 = v29(v16);
    v253;
  }));
  return v255;
}

struct StateT * v107(struct StateT * v108) {
  int v109 = v108->timer;
  int v173 = v109 + 1;
  v108->timer = v173;int * v111 = v108->regs;
  int v112 = v111[11];
  int * v113 = v108->regs;
  int v177 = v112 + -1;
  v113[11] = v177;
  struct StateT * v171 = v115(v108);
  return v171;
}

struct StateT * v131(struct StateT * v132) {
  int v133 = v132->timer;
  int v144 = v133 + 1;
  v132->timer = v144;int * v135 = v132->regs;
  int v136 = v135[11];
  bool v147 = !(v136 == 0);
  struct StateT * v142 = (v147 ? ({
    struct StateT * v138 = v57(v132);
    v138;
  }) : ({
    struct StateT * v140 = v21(v132);
    v140;
  }));
  return v142;
}

struct StateT * v123(struct StateT * v124) {
  int v125 = v124->timer;
  int v155 = v125 + 1;
  v124->timer = v155;int * v127 = v124->regs;
  int v128 = v127[13];
  int * v129 = v124->regs;
  int v159 = v128 + 4;
  v129[13] = v159;
  struct StateT * v153 = v131(v124);
  return v153;
}

struct StateT * v115(struct StateT * v116) {
  int v117 = v116->timer;
  int v164 = v117 + 1;
  v116->timer = v164;int * v119 = v116->regs;
  int v120 = v119[12];
  int * v121 = v116->regs;
  int v168 = v120 + 4;
  v121[12] = v168;
  struct StateT * v162 = v123(v116);
  return v162;
}

struct StateT * v9(struct StateT * v10) {
  int v11 = v10->timer;
  int v268 = v11 + 1;
  v10->timer = v268;int * v13 = v10->regs;
  v13[10] = 1;
  struct StateT * v266 = v15(v10);
  return v266;
}

struct StateT * v91(struct StateT * v92) {
  int v93 = v92->timer;
  int v96 = v93 + 1;
  v92->timer = v96;return v92;
}

struct StateT * snippet(struct StateT * v0) {
  struct StateT * v284 = v1(v0);
  return v284;
}

struct StateT * v1(struct StateT * v2) {
  int v3 = v2->timer;
  int v276 = v3 + 1;
  v2->timer = v276;int * v5 = v2->regs;
  int v6 = v5[10];
  int * v7 = v2->regs;
  v7[11] = v6;
  struct StateT * v274 = v9(v2);
  return v274;
}

struct StateT * v29(struct StateT * v30) {
  int v31 = v30->timer;
  int v247 = v31 + 1;
  v30->timer = v247;int * v33 = v30->regs;
  v33[12] = 0;
  struct StateT * v245 = v35(v30);
  return v245;
}

struct StateT * v85(struct StateT * v86) {
  int v87 = v86->timer;
  int v99 = v87 + 1;
  v86->timer = v99;int * v89 = v86->regs;
  v89[10] = 0;
  struct StateT * v97 = v91(v86);
  return v97;
}

struct StateT * v77(struct StateT * v78) {
  int v79 = v78->timer;
  int v184 = v79 + 1;
  v78->timer = v184;int * v81 = v78->regs;
  int v82 = v81[14];
  int * v83 = v78->regs;
  int v84 = v83[15];
  bool v189 = !(v82 == v84);
  struct StateT * v182 = (v189 ? ({
    struct StateT * v105 = v85(v78);
    v105;
  }) : ({
    struct StateT * v180 = v107(v78);
    v180;
  }));
  return v182;
}

struct StateT * v67(struct StateT * v68) {
  int v69 = v68->timer;
  int v197 = v69 + 1;
  v68->timer = v197;int * v71 = v68->regs;
  int v72 = v71[13];
  int * v73 = v68->mem;
  int v201 = (int)((unsigned int)v72 >> 2);
  int v74 = v73[v201];
  int * v75 = v68->regs;
  v75[15] = v74;
  struct StateT * v195 = v77(v68);
  return v195;
}

struct StateT * v35(struct StateT * v36) {
  int v37 = v36->timer;
  int v238 = v37 + 1;
  v36->timer = v238;int * v39 = v36->regs;
  int v40 = v39[12];
  int * v41 = v36->regs;
  int v242 = v40 + 16;
  v41[12] = v242;
  struct StateT * v236 = v43(v36);
  return v236;
}

struct StateT * v21(struct StateT * v22) {
  int v23 = v22->timer;
  int v26 = v23 + 1;
  v22->timer = v26;return v22;
}

struct StateT * v49(struct StateT * v50) {
  int v51 = v50->timer;
  int v221 = v51 + 1;
  v50->timer = v221;int * v53 = v50->regs;
  int v54 = v53[13];
  int * v55 = v50->regs;
  v55[13] = v54;
  struct StateT * v219 = v57(v50);
  return v219;
}



/*****************************************
End of C Generated Code
*******************************************/

int main(int argc, char* argv[]) {
  struct StateT s1, s2;
  init(&s1);
  init(&s2);
  
  int n = bounded(0, 4);
  s1.regs[10] = n;
  s2.regs[10] = n;
  // guess, the attacker's: the same draw in both states
  for (int i=0; i<4; i++) {
    int v = bounded(0, 20);
    s1.mem[4 + i] = v;
    s2.mem[4 + i] = v;
  }
  
  // secret, secret: a different draw in each state
  for (int i=0; i<4; i++) {
    s1.mem[0 + i] = bounded(0, 20);
    s2.mem[0 + i] = bounded(0, 20);
  }
  struct StateT *s1_ = snippet(&s1);
  struct StateT *s2_ = snippet(&s2);
  __CPROVER_assert(s1_->timer==s2_->timer, "timing leak");
  return 0;
}