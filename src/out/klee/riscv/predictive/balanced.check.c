// verify: leak (KLEE should report a failing assertion) [budget 1200s]
#define NUM_REGS 32
#define MEM_SIZE 64
#define SECRET_SIZE 10
#define SECRET_OFFSET 20
#define CACHE_ENTRIES 12
#define CACHE_WORDS 24

#ifdef KLEE
#include <assert.h>
#include <klee/klee.h>
#define koika_assert(b, s) klee_assert(b)
#define koika_assume(b) klee_assume(b)
#define koika_draw(x) klee_make_symbolic(&(x), sizeof(x), #x)
#define koika_secret(x) ((void)0)
#else
#define koika_assert(b, s) 0
#define koika_assume(b) 0
#define koika_draw(x) ((x) = 0)
#define koika_secret(x) ((void)0)
#endif
int bounded(int low, int high) {
  int x;
  koika_draw(x);
  koika_assume(low <= x && x <= high);
  return x;
}
// Same draw as `bounded`, said of the secret, so a backend that tracks
// where the secret goes has somewhere to start. Self-composition already
// encodes the split by drawing these twice, which is why the mark is
// nothing under a checker that reads the two runs exactly.
int secret(int low, int high) {
  int x = bounded(low, high);
  koika_secret(x);
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
  int mem[64];
  int saved_regs[32];
  int reg_ready[32];
  int cache_tags[12];
  int cache_dirty[12];
  int cache_age[12];
  int cache_vals[24];
  int timer;
};

struct StateT * snippet(struct StateT * v0);
struct StateT * slot_1(struct StateT * v15);
struct StateT * slot_8(struct StateT * v356);
struct StateT * slot_6(struct StateT * v338);
struct StateT * slot_5(struct StateT * v306);
struct StateT * slot_4(struct StateT * v286);
struct StateT * slot_2(struct StateT * v265);
struct StateT * slot_7(struct StateT * v351);
struct StateT * slot_3(struct StateT * v278);
struct StateT * slot_0(struct StateT * v2);
struct StateT * snippet(struct StateT * v0) {
  struct StateT * v1 = slot_0(v0);
  return v1;
}

struct StateT * slot_1(struct StateT * v15) {
  int v16 = v15->timer;
  int v149 = v16 + 1;
  v15->timer = v149;
  int * v18 = v15->regs;
  int v19 = v18[12];
  int * v20 = v15->cache_tags;
  int v153 = (((int)((unsigned int)((int)((unsigned int)v19 >> 2)) >> 1)) & 1) * 2;
  int v21 = v20[v153];
  int * v22 = v15->cache_tags;
  int v155 = ((((int)((unsigned int)((int)((unsigned int)v19 >> 2)) >> 1)) & 1) * 2) + 1;
  int v23 = v22[v155];
  int * v24 = v15->cache_tags;
  int v157 = 4 + ((((int)((unsigned int)((int)((unsigned int)v19 >> 2)) >> 1)) & 3) * 2);
  int v25 = v24[v157];
  int * v26 = v15->cache_tags;
  int v159 = (4 + ((((int)((unsigned int)((int)((unsigned int)v19 >> 2)) >> 1)) & 3) * 2)) + 1;
  int v27 = v26[v159];
  int v28 = v15->timer;
  int v160 = v28 + ((100 ^ (((~(((v25 ^ ((int)((unsigned int)((int)((unsigned int)v19 >> 2)) >> 1))) | (-(v25 ^ ((int)((unsigned int)((int)((unsigned int)v19 >> 2)) >> 1))))) >> 31)) | (~(((v27 ^ ((int)((unsigned int)((int)((unsigned int)v19 >> 2)) >> 1))) | (-(v27 ^ ((int)((unsigned int)((int)((unsigned int)v19 >> 2)) >> 1))))) >> 31))) & 104)) ^ (((~(((v21 ^ ((int)((unsigned int)((int)((unsigned int)v19 >> 2)) >> 1))) | (-(v21 ^ ((int)((unsigned int)((int)((unsigned int)v19 >> 2)) >> 1))))) >> 31)) | (~(((v23 ^ ((int)((unsigned int)((int)((unsigned int)v19 >> 2)) >> 1))) | (-(v23 ^ ((int)((unsigned int)((int)((unsigned int)v19 >> 2)) >> 1))))) >> 31))) & (1 ^ (100 ^ (((~(((v25 ^ ((int)((unsigned int)((int)((unsigned int)v19 >> 2)) >> 1))) | (-(v25 ^ ((int)((unsigned int)((int)((unsigned int)v19 >> 2)) >> 1))))) >> 31)) | (~(((v27 ^ ((int)((unsigned int)((int)((unsigned int)v19 >> 2)) >> 1))) | (-(v27 ^ ((int)((unsigned int)((int)((unsigned int)v19 >> 2)) >> 1))))) >> 31))) & 104)))));
  v15->timer = v160;
  int * v30 = v15->cache_vals;
  bool v161 = !(((~(((v21 ^ ((int)((unsigned int)((int)((unsigned int)v19 >> 2)) >> 1))) | (-(v21 ^ ((int)((unsigned int)((int)((unsigned int)v19 >> 2)) >> 1))))) >> 31)) | (~(((v23 ^ ((int)((unsigned int)((int)((unsigned int)v19 >> 2)) >> 1))) | (-(v23 ^ ((int)((unsigned int)((int)((unsigned int)v19 >> 2)) >> 1))))) >> 31))) == 0);
  int v143;
  if (v161) {
    int * v31 = v15->cache_age;
    int v163 = ((((int)((unsigned int)((int)((unsigned int)v19 >> 2)) >> 1)) & 1) * 2) + ((~(((v23 ^ ((int)((unsigned int)((int)((unsigned int)v19 >> 2)) >> 1))) | (-(v23 ^ ((int)((unsigned int)((int)((unsigned int)v19 >> 2)) >> 1))))) >> 31)) & 1);
    int v32 = v31[v163];
    int * v33 = v15->cache_age;
    int v34 = v33[v153];
    int * v35 = v15->cache_age;
    int v166 = v34 + ((int)((unsigned int)(v34 - v32) >> 31));
    v35[v153] = v166;
    int * v37 = v15->cache_age;
    int v38 = v37[v155];
    int * v39 = v15->cache_age;
    int v169 = v38 + ((int)((unsigned int)(v38 - v32) >> 31));
    v39[v155] = v169;
    int * v41 = v15->cache_age;
    v41[v163] = 0;
    v143 = v163;
  } else {
    int * v44 = v15->cache_age;
    int v173 = (((int)((unsigned int)((int)((unsigned int)v19 >> 2)) >> 1)) & 1) * 2;
    int v45 = v44[v173];
    int * v46 = v15->cache_tags;
    int v47 = v46[v173];
    int * v48 = v15->cache_age;
    int v49 = v48[v155];
    int * v50 = v15->cache_tags;
    int v51 = v50[v155];
    bool v177 = !(((~(((v25 ^ ((int)((unsigned int)((int)((unsigned int)v19 >> 2)) >> 1))) | (-(v25 ^ ((int)((unsigned int)((int)((unsigned int)v19 >> 2)) >> 1))))) >> 31)) | (~(((v27 ^ ((int)((unsigned int)((int)((unsigned int)v19 >> 2)) >> 1))) | (-(v27 ^ ((int)((unsigned int)((int)((unsigned int)v19 >> 2)) >> 1))))) >> 31))) == 0);
    int v115;
    if (v177) {
      int * v52 = v15->cache_age;
      int v179 = (4 + ((((int)((unsigned int)((int)((unsigned int)v19 >> 2)) >> 1)) & 3) * 2)) + ((~(((v27 ^ ((int)((unsigned int)((int)((unsigned int)v19 >> 2)) >> 1))) | (-(v27 ^ ((int)((unsigned int)((int)((unsigned int)v19 >> 2)) >> 1))))) >> 31)) & 1);
      int v53 = v52[v179];
      int * v54 = v15->cache_age;
      int v55 = v54[v157];
      int * v56 = v15->cache_age;
      int v182 = v55 + ((int)((unsigned int)(v55 - v53) >> 31));
      v56[v157] = v182;
      int * v58 = v15->cache_age;
      int v59 = v58[v159];
      int * v60 = v15->cache_age;
      int v185 = v59 + ((int)((unsigned int)(v59 - v53) >> 31));
      v60[v159] = v185;
      int * v62 = v15->cache_age;
      v62[v179] = 0;
      v115 = v179;
    } else {
      int * v65 = v15->cache_age;
      int v189 = 4 + ((((int)((unsigned int)((int)((unsigned int)v19 >> 2)) >> 1)) & 3) * 2);
      int v66 = v65[v189];
      int * v67 = v15->cache_tags;
      int v68 = v67[v189];
      int * v69 = v15->cache_age;
      int v70 = v69[v159];
      int * v71 = v15->cache_tags;
      int v72 = v71[v159];
      int * v73 = v15->cache_dirty;
      int v194 = (4 + ((((int)((unsigned int)((int)((unsigned int)v19 >> 2)) >> 1)) & 3) * 2)) + ((((v66 + ((~(((v68 ^ -1) | (-(v68 ^ -1))) >> 31)) & 2)) - (v70 + ((~(((v72 ^ -1) | (-(v72 ^ -1))) >> 31)) & 2))) >> 31) & 1);
      int v74 = v73[v194];
      bool v195 = !(v74 == 0);
      if (v195) {
        int * v75 = v15->cache_tags;
        int v76 = v75[v194];
        int * v77 = v15->cache_vals;
        int v198 = ((4 + ((((int)((unsigned int)((int)((unsigned int)v19 >> 2)) >> 1)) & 3) * 2)) + ((((v66 + ((~(((v68 ^ -1) | (-(v68 ^ -1))) >> 31)) & 2)) - (v70 + ((~(((v72 ^ -1) | (-(v72 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
        int v78 = v77[v198];
        int * v79 = v15->cache_vals;
        int v200 = (((4 + ((((int)((unsigned int)((int)((unsigned int)v19 >> 2)) >> 1)) & 3) * 2)) + ((((v66 + ((~(((v68 ^ -1) | (-(v68 ^ -1))) >> 31)) & 2)) - (v70 + ((~(((v72 ^ -1) | (-(v72 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
        int v80 = v79[v200];
        int * v81 = v15->mem;
        int v202 = v76 * 2;
        v81[v202] = v78;
        int * v83 = v15->mem;
        int v205 = (v76 * 2) + 1;
        v83[v205] = v80;
        ;
      } else {
        ;
      }
      int * v88 = v15->mem;
      int v210 = ((int)((unsigned int)((int)((unsigned int)v19 >> 2)) >> 1)) * 2;
      int v89 = v88[v210];
      int * v90 = v15->mem;
      int v212 = (((int)((unsigned int)((int)((unsigned int)v19 >> 2)) >> 1)) * 2) + 1;
      int v91 = v90[v212];
      int * v92 = v15->cache_vals;
      int v214 = ((4 + ((((int)((unsigned int)((int)((unsigned int)v19 >> 2)) >> 1)) & 3) * 2)) + ((((v66 + ((~(((v68 ^ -1) | (-(v68 ^ -1))) >> 31)) & 2)) - (v70 + ((~(((v72 ^ -1) | (-(v72 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
      v92[v214] = v89;
      int * v94 = v15->cache_vals;
      int v217 = (((4 + ((((int)((unsigned int)((int)((unsigned int)v19 >> 2)) >> 1)) & 3) * 2)) + ((((v66 + ((~(((v68 ^ -1) | (-(v68 ^ -1))) >> 31)) & 2)) - (v70 + ((~(((v72 ^ -1) | (-(v72 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
      v94[v217] = v91;
      int * v96 = v15->cache_tags;
      int v220 = (int)((unsigned int)((int)((unsigned int)v19 >> 2)) >> 1);
      v96[v194] = v220;
      int * v98 = v15->cache_dirty;
      v98[v194] = 0;
      int * v100 = v15->cache_age;
      v100[v194] = 1;
      int * v102 = v15->cache_age;
      int v103 = v102[v194];
      int * v104 = v15->cache_age;
      int v105 = v104[v157];
      int * v106 = v15->cache_age;
      int v228 = v105 + ((int)((unsigned int)(v105 - v103) >> 31));
      v106[v157] = v228;
      int * v108 = v15->cache_age;
      int v109 = v108[v159];
      int * v110 = v15->cache_age;
      int v231 = v109 + ((int)((unsigned int)(v109 - v103) >> 31));
      v110[v159] = v231;
      int * v112 = v15->cache_age;
      v112[v194] = 0;
      v115 = v194;
    }
    int * v116 = v15->cache_vals;
    int v234 = v115 * 2;
    int v117 = v116[v234];
    int * v118 = v15->cache_vals;
    int v236 = (v115 * 2) + 1;
    int v119 = v118[v236];
    int * v120 = v15->cache_vals;
    int v238 = (((((int)((unsigned int)((int)((unsigned int)v19 >> 2)) >> 1)) & 1) * 2) + ((((v45 + ((~(((v47 ^ -1) | (-(v47 ^ -1))) >> 31)) & 2)) - (v49 + ((~(((v51 ^ -1) | (-(v51 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
    v120[v238] = v117;
    int * v122 = v15->cache_vals;
    int v241 = ((((((int)((unsigned int)((int)((unsigned int)v19 >> 2)) >> 1)) & 1) * 2) + ((((v45 + ((~(((v47 ^ -1) | (-(v47 ^ -1))) >> 31)) & 2)) - (v49 + ((~(((v51 ^ -1) | (-(v51 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
    v122[v241] = v119;
    int * v124 = v15->cache_tags;
    int v244 = ((((int)((unsigned int)((int)((unsigned int)v19 >> 2)) >> 1)) & 1) * 2) + ((((v45 + ((~(((v47 ^ -1) | (-(v47 ^ -1))) >> 31)) & 2)) - (v49 + ((~(((v51 ^ -1) | (-(v51 ^ -1))) >> 31)) & 2))) >> 31) & 1);
    int v245 = (int)((unsigned int)((int)((unsigned int)v19 >> 2)) >> 1);
    v124[v244] = v245;
    int * v126 = v15->cache_dirty;
    v126[v244] = 0;
    int * v128 = v15->cache_age;
    v128[v244] = 1;
    int * v130 = v15->cache_age;
    int v131 = v130[v244];
    int * v132 = v15->cache_age;
    int v133 = v132[v153];
    int * v134 = v15->cache_age;
    int v253 = v133 + ((int)((unsigned int)(v133 - v131) >> 31));
    v134[v153] = v253;
    int * v136 = v15->cache_age;
    int v137 = v136[v155];
    int * v138 = v15->cache_age;
    int v256 = v137 + ((int)((unsigned int)(v137 - v131) >> 31));
    v138[v155] = v256;
    int * v140 = v15->cache_age;
    v140[v244] = 0;
    v143 = v244;
  }
  int v259 = (v143 * 2) + (((int)((unsigned int)v19 >> 2)) & 1);
  int v144 = v30[v259];
  int * v145 = v15->regs;
  v145[16] = v144;
  struct StateT * v147 = slot_2(v15);
  return v147;
}

struct StateT * slot_8(struct StateT * v356) {
  int v357 = v356->timer;
  int v360 = v357 + 1;
  v356->timer = v360;
  return v356;
}

struct StateT * slot_6(struct StateT * v338) {
  int v339 = v338->timer;
  int v345 = v339 + 1;
  v338->timer = v345;
  int * v341 = v338->regs;
  v341[18] = 2;
  struct StateT * v343 = slot_8(v338);
  return v343;
}

struct StateT * slot_5(struct StateT * v306) {
  int * v307 = v306->regs;
  int v308 = v307[16];
  int * v309 = v306->regs;
  int v310 = v309[17];
  bool v327 = v308 < v310;
  struct StateT * v321;
  if (v327) {
    int v311 = v306->timer;
    int v328 = v311 + 15;
    v306->timer = v328;
    int * v313 = v306->saved_regs;
    int v314 = v313[18];
    int * v315 = v306->regs;
    v315[18] = v314;
    struct StateT * v317 = slot_6(v306);
    v321 = v317;
  } else {
    struct StateT * v319 = slot_7(v306);
    v321 = v319;
  }
  return v321;
}

struct StateT * slot_4(struct StateT * v286) {
  int * v287 = v286->saved_regs;
  int * v288 = v286->regs;
  int v289 = v288[18];
  v287[18] = v289;
  int v291 = v286->timer;
  int v301 = v291 + 1;
  v286->timer = v301;
  int * v293 = v286->regs;
  v293[18] = 1;
  struct StateT * v295 = slot_5(v286);
  return v295;
}

struct StateT * slot_2(struct StateT * v265) {
  int v266 = v265->timer;
  int v272 = v266 + 1;
  v265->timer = v272;
  int * v268 = v265->regs;
  v268[17] = 10;
  struct StateT * v270 = slot_3(v265);
  return v270;
}

struct StateT * slot_7(struct StateT * v351) {
  int v352 = v351->timer;
  int v355 = v352 + 1;
  v351->timer = v355;
  return v351;
}

struct StateT * slot_3(struct StateT * v278) {
  int v279 = v278->timer;
  int v283 = v279 + 1;
  v278->timer = v283;
  struct StateT * v281 = slot_4(v278);
  return v281;
}

struct StateT * slot_0(struct StateT * v2) {
  int v3 = v2->timer;
  int v9 = v3 + 1;
  v2->timer = v9;
  int * v5 = v2->regs;
  v5[12] = 80;
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
  for (int i=0; i<CACHE_ENTRIES; i++) {
    s->cache_tags[i] = -1;
    s->cache_dirty[i] = 0;
    s->cache_age[i] = 0;
  }
  for (int i=0; i<CACHE_WORDS; i++) {
    s->cache_vals[i] = 0;
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
    s1.mem[SECRET_OFFSET+i] = secret(0, 20);
    s2.mem[SECRET_OFFSET+i] = secret(0, 20);
  }
  struct StateT *s1_ = snippet(&s1);
  struct StateT *s2_ = snippet(&s2);
  koika_assert(s1_->timer==s2_->timer, "timing leak");
  return 0;
}