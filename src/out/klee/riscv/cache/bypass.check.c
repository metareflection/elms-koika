// verify: clean (KLEE should report no failing assertion) [budget 120s]
#define NUM_REGS 32
#define MEM_SIZE 30
#define SECRET_SIZE 10
#define SECRET_OFFSET 20
#define CACHE_LRU_SIZE 10

#ifdef KLEE
#include <assert.h>
#include <klee/klee.h>
#define koika_assert(b, s) klee_assert(b)
#define koika_assume(b) klee_assume(b)
#define koika_draw(x) klee_make_symbolic(&(x), sizeof(x), #x)
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
struct StateT * slot_1(struct StateT * v19);
struct StateT * slot_6(struct StateT * v267);
struct StateT * slot_5(struct StateT * v251);
struct StateT * slot_4(struct StateT * v146);
struct StateT * slot_2(struct StateT * v35);
struct StateT * slot_3(struct StateT * v48);
struct StateT * slot_0(struct StateT * v2);
struct StateT * snippet(struct StateT * v0) {
  struct StateT * v1 = slot_0(v0);
  return v1;
}

struct StateT * slot_1(struct StateT * v19) {
  int v20 = v19->timer;
  int v28 = v20 + 1;
  v19->timer = v28;
  int * v22 = v19->regs;
  int v23 = v22[6];
  int * v24 = v19->regs;
  int v32 = v23 + 80;
  v24[6] = v32;
  struct StateT * v26 = slot_2(v19);
  return v26;
}

struct StateT * slot_6(struct StateT * v267) {
  int v268 = v267->timer;
  int v325 = v268 + 1;
  v267->timer = v325;
  int * v270 = v267->regs;
  int v271 = v270[11];
  int * v272 = v267->cache_keys;
  int v273 = v272[0];
  bool v330 = v273 == ((int)((unsigned int)v271 >> 2));
  int v321;
  if (v330) {
    int * v274 = v267->cache_vals;
    int v275 = v274[0];
    v321 = v275;
  } else {
    int * v277 = v267->cache_keys;
    int v278 = v277[1];
    bool v335 = v278 == ((int)((unsigned int)v271 >> 2));
    int v319;
    if (v335) {
      int * v279 = v267->cache_vals;
      int v280 = v279[1];
      int * v281 = v267->cache_keys;
      int * v282 = v267->cache_keys;
      int v283 = v282[0];
      v281[1] = v283;
      int * v285 = v267->cache_vals;
      int * v286 = v267->cache_vals;
      int v287 = v286[0];
      v285[1] = v287;
      int * v289 = v267->cache_keys;
      int v344 = (int)((unsigned int)v271 >> 2);
      v289[0] = v344;
      int * v291 = v267->cache_vals;
      v291[0] = v280;
      int v293 = v267->timer;
      int v347 = v293 + 1;
      v267->timer = v347;
      v319 = v280;
    } else {
      int * v296 = v267->mem;
      int v349 = (int)((unsigned int)v271 >> 2);
      int v297 = v296[v349];
      int * v298 = v267->mem;
      int * v299 = v267->cache_keys;
      int v300 = v299[1];
      int * v301 = v267->cache_vals;
      int v302 = v301[1];
      v298[v300] = v302;
      int * v304 = v267->cache_keys;
      int * v305 = v267->cache_keys;
      int v306 = v305[0];
      v304[1] = v306;
      int * v308 = v267->cache_vals;
      int * v309 = v267->cache_vals;
      int v310 = v309[0];
      v308[1] = v310;
      int * v312 = v267->cache_keys;
      v312[0] = v349;
      int * v314 = v267->cache_vals;
      v314[0] = v297;
      int v316 = v267->timer;
      int v364 = v316 + 100;
      v267->timer = v364;
      v319 = v297;
    }
    v321 = v319;
  }
  int * v322 = v267->regs;
  v322[12] = v321;
  return v267;
}

struct StateT * slot_5(struct StateT * v251) {
  int v252 = v251->timer;
  int v260 = v252 + 1;
  v251->timer = v260;
  int * v254 = v251->regs;
  int v255 = v254[11];
  int * v256 = v251->regs;
  int v264 = v255 << 2;
  v256[11] = v264;
  struct StateT * v258 = slot_6(v251);
  return v258;
}

struct StateT * slot_4(struct StateT * v146) {
  int v147 = v146->timer;
  int v205 = v147 + 1;
  v146->timer = v205;
  int * v149 = v146->regs;
  int v150 = v149[6];
  int * v151 = v146->cache_keys;
  int v152 = v151[0];
  bool v210 = v152 == ((int)((unsigned int)v150 >> 2));
  int v200;
  if (v210) {
    int * v153 = v146->cache_vals;
    int v154 = v153[0];
    v200 = v154;
  } else {
    int * v156 = v146->cache_keys;
    int v157 = v156[1];
    bool v215 = v157 == ((int)((unsigned int)v150 >> 2));
    int v198;
    if (v215) {
      int * v158 = v146->cache_vals;
      int v159 = v158[1];
      int * v160 = v146->cache_keys;
      int * v161 = v146->cache_keys;
      int v162 = v161[0];
      v160[1] = v162;
      int * v164 = v146->cache_vals;
      int * v165 = v146->cache_vals;
      int v166 = v165[0];
      v164[1] = v166;
      int * v168 = v146->cache_keys;
      int v224 = (int)((unsigned int)v150 >> 2);
      v168[0] = v224;
      int * v170 = v146->cache_vals;
      v170[0] = v159;
      int v172 = v146->timer;
      int v227 = v172 + 1;
      v146->timer = v227;
      v198 = v159;
    } else {
      int * v175 = v146->mem;
      int v229 = (int)((unsigned int)v150 >> 2);
      int v176 = v175[v229];
      int * v177 = v146->mem;
      int * v178 = v146->cache_keys;
      int v179 = v178[1];
      int * v180 = v146->cache_vals;
      int v181 = v180[1];
      v177[v179] = v181;
      int * v183 = v146->cache_keys;
      int * v184 = v146->cache_keys;
      int v185 = v184[0];
      v183[1] = v185;
      int * v187 = v146->cache_vals;
      int * v188 = v146->cache_vals;
      int v189 = v188[0];
      v187[1] = v189;
      int * v191 = v146->cache_keys;
      v191[0] = v229;
      int * v193 = v146->cache_vals;
      v193[0] = v176;
      int v195 = v146->timer;
      int v244 = v195 + 100;
      v146->timer = v244;
      v198 = v176;
    }
    v200 = v198;
  }
  int * v201 = v146->regs;
  v201[11] = v200;
  struct StateT * v203 = slot_5(v146);
  return v203;
}

struct StateT * slot_2(struct StateT * v35) {
  int v36 = v35->timer;
  int v42 = v36 + 1;
  v35->timer = v42;
  int * v38 = v35->regs;
  v38[7] = 0;
  struct StateT * v40 = slot_3(v35);
  return v40;
}

struct StateT * slot_3(struct StateT * v48) {
  int v49 = v48->timer;
  int v103 = v49 + 1;
  v48->timer = v103;
  int * v51 = v48->regs;
  int v52 = v51[6];
  int * v53 = v48->regs;
  int v54 = v53[7];
  int * v55 = v48->cache_keys;
  int v56 = v55[0];
  bool v110 = v56 == ((int)((unsigned int)v52 >> 2));
  int v100;
  if (v110) {
    int * v57 = v48->cache_vals;
    v57[0] = v54;
    v100 = v54;
  } else {
    int * v60 = v48->cache_keys;
    int v61 = v60[1];
    bool v115 = v61 == ((int)((unsigned int)v52 >> 2));
    int v98;
    if (v115) {
      int * v62 = v48->cache_keys;
      int * v63 = v48->cache_keys;
      int v64 = v63[0];
      v62[1] = v64;
      int * v66 = v48->cache_vals;
      int * v67 = v48->cache_vals;
      int v68 = v67[0];
      v66[1] = v68;
      int * v70 = v48->cache_keys;
      int v123 = (int)((unsigned int)v52 >> 2);
      v70[0] = v123;
      int * v72 = v48->cache_vals;
      v72[0] = v54;
      int v74 = v48->timer;
      int v126 = v74 + 1;
      v48->timer = v126;
      v98 = v54;
    } else {
      int * v77 = v48->mem;
      int * v78 = v48->cache_keys;
      int v79 = v78[1];
      int * v80 = v48->cache_vals;
      int v81 = v80[1];
      v77[v79] = v81;
      int * v83 = v48->cache_keys;
      int * v84 = v48->cache_keys;
      int v85 = v84[0];
      v83[1] = v85;
      int * v87 = v48->cache_vals;
      int * v88 = v48->cache_vals;
      int v89 = v88[0];
      v87[1] = v89;
      int * v91 = v48->cache_keys;
      int v139 = (int)((unsigned int)v52 >> 2);
      v91[0] = v139;
      int * v93 = v48->cache_vals;
      v93[0] = v54;
      int v95 = v48->timer;
      int v142 = v95 + 100;
      v48->timer = v142;
      v98 = v54;
    }
    v100 = v98;
  }
  struct StateT * v101 = slot_4(v48);
  return v101;
}

struct StateT * slot_0(struct StateT * v2) {
  int v3 = v2->timer;
  int v11 = v3 + 1;
  v2->timer = v11;
  int * v5 = v2->regs;
  int v6 = v5[10];
  int * v7 = v2->regs;
  int v16 = v6 & 28;
  v7[6] = v16;
  struct StateT * v9 = slot_1(v2);
  return v9;
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
  koika_assert(s1_->timer==s2_->timer, "timing leak");
  return 0;
}