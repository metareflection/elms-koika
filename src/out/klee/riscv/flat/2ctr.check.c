// verify: leak (KLEE should report a failing assertion) [budget 1200s]
#define NUM_REGS 32
#define MEM_SIZE 64
#define SECRET_SIZE 10
#define SECRET_OFFSET 20
#define CACHE_ENTRIES 2
#define CACHE_WORDS 2

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
  int cache_tags[2];
  int cache_dirty[2];
  int cache_age[2];
  int cache_vals[2];
  int timer;
};

struct StateT * snippet(struct StateT * v0);
struct StateT * slot_1(struct StateT * v19);
struct StateT * slot_2(struct StateT * v153);
struct StateT * slot_3(struct StateT * v169);
struct StateT * slot_0(struct StateT * v2);
struct StateT * snippet(struct StateT * v0) {
  struct StateT * v1 = slot_0(v0);
  return v1;
}

struct StateT * slot_1(struct StateT * v19) {
  int v20 = v19->timer;
  int v92 = v20 + 1;
  v19->timer = v92;
  int * v22 = v19->regs;
  int v23 = v22[10];
  int * v24 = v19->cache_tags;
  int v25 = v24[0];
  int * v26 = v19->cache_tags;
  int v27 = v26[1];
  int v28 = v19->timer;
  int v99 = v28 + (100 ^ (((~(((v25 ^ ((int)((unsigned int)v23 >> 2))) | (-(v25 ^ ((int)((unsigned int)v23 >> 2))))) >> 31)) | (~(((v27 ^ ((int)((unsigned int)v23 >> 2))) | (-(v27 ^ ((int)((unsigned int)v23 >> 2))))) >> 31))) & 101));
  v19->timer = v99;
  int * v30 = v19->cache_vals;
  bool v100 = !(((~(((v25 ^ ((int)((unsigned int)v23 >> 2))) | (-(v25 ^ ((int)((unsigned int)v23 >> 2))))) >> 31)) | (~(((v27 ^ ((int)((unsigned int)v23 >> 2))) | (-(v27 ^ ((int)((unsigned int)v23 >> 2))))) >> 31))) == 0);
  int v86;
  if (v100) {
    int * v31 = v19->cache_age;
    int v102 = (~(((v27 ^ ((int)((unsigned int)v23 >> 2))) | (-(v27 ^ ((int)((unsigned int)v23 >> 2))))) >> 31)) & 1;
    int v32 = v31[v102];
    int * v33 = v19->cache_age;
    int v34 = v33[0];
    int * v35 = v19->cache_age;
    int v105 = v34 + ((int)((unsigned int)(v34 - v32) >> 31));
    v35[0] = v105;
    int * v37 = v19->cache_age;
    int v38 = v37[1];
    int * v39 = v19->cache_age;
    int v108 = v38 + ((int)((unsigned int)(v38 - v32) >> 31));
    v39[1] = v108;
    int * v41 = v19->cache_age;
    v41[v102] = 0;
    v86 = v102;
  } else {
    int * v44 = v19->cache_age;
    int v45 = v44[0];
    int * v46 = v19->cache_tags;
    int v47 = v46[0];
    int * v48 = v19->cache_age;
    int v49 = v48[1];
    int * v50 = v19->cache_tags;
    int v51 = v50[1];
    int * v52 = v19->cache_dirty;
    int v117 = (((v45 + ((~(((v47 ^ -1) | (-(v47 ^ -1))) >> 31)) & 2)) - (v49 + ((~(((v51 ^ -1) | (-(v51 ^ -1))) >> 31)) & 2))) >> 31) & 1;
    int v53 = v52[v117];
    bool v118 = !(v53 == 0);
    if (v118) {
      int * v54 = v19->cache_tags;
      int v55 = v54[v117];
      int * v56 = v19->cache_vals;
      int v121 = (((v45 + ((~(((v47 ^ -1) | (-(v47 ^ -1))) >> 31)) & 2)) - (v49 + ((~(((v51 ^ -1) | (-(v51 ^ -1))) >> 31)) & 2))) >> 31) & 1;
      int v57 = v56[v121];
      int * v58 = v19->mem;
      v58[v55] = v57;
      ;
    } else {
      ;
    }
    int * v63 = v19->mem;
    int v128 = (int)((unsigned int)v23 >> 2);
    int v64 = v63[v128];
    int * v65 = v19->cache_vals;
    int v130 = (((v45 + ((~(((v47 ^ -1) | (-(v47 ^ -1))) >> 31)) & 2)) - (v49 + ((~(((v51 ^ -1) | (-(v51 ^ -1))) >> 31)) & 2))) >> 31) & 1;
    v65[v130] = v64;
    int * v67 = v19->cache_tags;
    int v133 = (int)((unsigned int)v23 >> 2);
    v67[v117] = v133;
    int * v69 = v19->cache_dirty;
    v69[v117] = 0;
    int * v71 = v19->cache_age;
    v71[v117] = 1;
    int * v73 = v19->cache_age;
    int v74 = v73[v117];
    int * v75 = v19->cache_age;
    int v76 = v75[0];
    int * v77 = v19->cache_age;
    int v141 = v76 + ((int)((unsigned int)(v76 - v74) >> 31));
    v77[0] = v141;
    int * v79 = v19->cache_age;
    int v80 = v79[1];
    int * v81 = v19->cache_age;
    int v144 = v80 + ((int)((unsigned int)(v80 - v74) >> 31));
    v81[1] = v144;
    int * v83 = v19->cache_age;
    v83[v117] = 0;
    v86 = v117;
  }
  int v87 = v30[v86];
  int * v88 = v19->regs;
  v88[11] = v87;
  struct StateT * v90 = slot_2(v19);
  return v90;
}

struct StateT * slot_2(struct StateT * v153) {
  int v154 = v153->timer;
  int v162 = v154 + 1;
  v153->timer = v162;
  int * v156 = v153->regs;
  int v157 = v156[11];
  int * v158 = v153->regs;
  int v166 = v157 << 2;
  v158[11] = v166;
  struct StateT * v160 = slot_3(v153);
  return v160;
}

struct StateT * slot_3(struct StateT * v169) {
  int v170 = v169->timer;
  int v241 = v170 + 1;
  v169->timer = v241;
  int * v172 = v169->regs;
  int v173 = v172[11];
  int * v174 = v169->cache_tags;
  int v175 = v174[0];
  int * v176 = v169->cache_tags;
  int v177 = v176[1];
  int v178 = v169->timer;
  int v248 = v178 + (100 ^ (((~(((v175 ^ ((int)((unsigned int)(v173 + 16) >> 2))) | (-(v175 ^ ((int)((unsigned int)(v173 + 16) >> 2))))) >> 31)) | (~(((v177 ^ ((int)((unsigned int)(v173 + 16) >> 2))) | (-(v177 ^ ((int)((unsigned int)(v173 + 16) >> 2))))) >> 31))) & 101));
  v169->timer = v248;
  int * v180 = v169->cache_vals;
  bool v249 = !(((~(((v175 ^ ((int)((unsigned int)(v173 + 16) >> 2))) | (-(v175 ^ ((int)((unsigned int)(v173 + 16) >> 2))))) >> 31)) | (~(((v177 ^ ((int)((unsigned int)(v173 + 16) >> 2))) | (-(v177 ^ ((int)((unsigned int)(v173 + 16) >> 2))))) >> 31))) == 0);
  int v236;
  if (v249) {
    int * v181 = v169->cache_age;
    int v251 = (~(((v177 ^ ((int)((unsigned int)(v173 + 16) >> 2))) | (-(v177 ^ ((int)((unsigned int)(v173 + 16) >> 2))))) >> 31)) & 1;
    int v182 = v181[v251];
    int * v183 = v169->cache_age;
    int v184 = v183[0];
    int * v185 = v169->cache_age;
    int v254 = v184 + ((int)((unsigned int)(v184 - v182) >> 31));
    v185[0] = v254;
    int * v187 = v169->cache_age;
    int v188 = v187[1];
    int * v189 = v169->cache_age;
    int v257 = v188 + ((int)((unsigned int)(v188 - v182) >> 31));
    v189[1] = v257;
    int * v191 = v169->cache_age;
    v191[v251] = 0;
    v236 = v251;
  } else {
    int * v194 = v169->cache_age;
    int v195 = v194[0];
    int * v196 = v169->cache_tags;
    int v197 = v196[0];
    int * v198 = v169->cache_age;
    int v199 = v198[1];
    int * v200 = v169->cache_tags;
    int v201 = v200[1];
    int * v202 = v169->cache_dirty;
    int v266 = (((v195 + ((~(((v197 ^ -1) | (-(v197 ^ -1))) >> 31)) & 2)) - (v199 + ((~(((v201 ^ -1) | (-(v201 ^ -1))) >> 31)) & 2))) >> 31) & 1;
    int v203 = v202[v266];
    bool v267 = !(v203 == 0);
    if (v267) {
      int * v204 = v169->cache_tags;
      int v205 = v204[v266];
      int * v206 = v169->cache_vals;
      int v270 = (((v195 + ((~(((v197 ^ -1) | (-(v197 ^ -1))) >> 31)) & 2)) - (v199 + ((~(((v201 ^ -1) | (-(v201 ^ -1))) >> 31)) & 2))) >> 31) & 1;
      int v207 = v206[v270];
      int * v208 = v169->mem;
      v208[v205] = v207;
      ;
    } else {
      ;
    }
    int * v213 = v169->mem;
    int v277 = (int)((unsigned int)(v173 + 16) >> 2);
    int v214 = v213[v277];
    int * v215 = v169->cache_vals;
    int v279 = (((v195 + ((~(((v197 ^ -1) | (-(v197 ^ -1))) >> 31)) & 2)) - (v199 + ((~(((v201 ^ -1) | (-(v201 ^ -1))) >> 31)) & 2))) >> 31) & 1;
    v215[v279] = v214;
    int * v217 = v169->cache_tags;
    int v282 = (int)((unsigned int)(v173 + 16) >> 2);
    v217[v266] = v282;
    int * v219 = v169->cache_dirty;
    v219[v266] = 0;
    int * v221 = v169->cache_age;
    v221[v266] = 1;
    int * v223 = v169->cache_age;
    int v224 = v223[v266];
    int * v225 = v169->cache_age;
    int v226 = v225[0];
    int * v227 = v169->cache_age;
    int v290 = v226 + ((int)((unsigned int)(v226 - v224) >> 31));
    v227[0] = v290;
    int * v229 = v169->cache_age;
    int v230 = v229[1];
    int * v231 = v169->cache_age;
    int v293 = v230 + ((int)((unsigned int)(v230 - v224) >> 31));
    v231[1] = v293;
    int * v233 = v169->cache_age;
    v233[v266] = 0;
    v236 = v266;
  }
  int v237 = v180[v236];
  int * v238 = v169->regs;
  v238[12] = v237;
  return v169;
}

struct StateT * slot_0(struct StateT * v2) {
  int v3 = v2->timer;
  int v12 = v3 + 1;
  v2->timer = v12;
  int * v5 = v2->regs;
  int v6 = v5[10];
  bool v15 = v6 == 0;
  struct StateT * v10;
  if (v15) {
    v10 = v2;
  } else {
    struct StateT * v8 = slot_1(v2);
    v10 = v8;
  }
  return v10;
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