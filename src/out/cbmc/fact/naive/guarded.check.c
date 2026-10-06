// verify: clean (CBMC should report VERIFICATION SUCCESSFUL) [unwind 65]
#define NUM_REGS 32
#define MEM_SIZE 64
#define SECRET_SIZE 10
#define SECRET_OFFSET 20
#define CACHE_ENTRIES 12
#define CACHE_WORDS 24

#ifdef CBMC
int nondet_uint();
#define koika_assert(b, s) __CPROVER_assert(b, s)
#define koika_assume(b) __CPROVER_assume(b)
#define koika_draw(x) ((x) = nondet_uint())
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

struct StateT * slot_12(struct StateT * v268);
struct StateT * slot_14(struct StateT * v118);
struct StateT * slot_6(struct StateT * v132);
struct StateT * slot_16(struct StateT * v182);
struct StateT * slot_5(struct StateT * v103);
struct StateT * slot_17(struct StateT * v215);
struct StateT * slot_2(struct StateT * v39);
struct StateT * slot_7(struct StateT * v164);
struct StateT * slot_3(struct StateT * v51);
struct StateT * snippet(struct StateT * v0);
struct StateT * slot_10(struct StateT * v234);
struct StateT * slot_1(struct StateT * v20);
struct StateT * slot_8(struct StateT * v201);
struct StateT * slot_4(struct StateT * v67);
struct StateT * slot_13(struct StateT * v89);
struct StateT * slot_15(struct StateT * v148);
struct StateT * slot_9(struct StateT * v220);
struct StateT * slot_11(struct StateT * v250);
struct StateT * slot_0(struct StateT * v2);
struct StateT * slot_12(struct StateT * v268) {
  int v269 = v268->timer;
  int v277 = v269 + 1;
  v268->timer = v277;
  int * v271 = v268->regs;
  int v272 = v271[12];
  int v273 = v271[11];
  int v281 = v272 + v273;
  v271[12] = v281;
  struct StateT * v275 = slot_13(v268);
  return v275;
}

struct StateT * slot_14(struct StateT * v118) {
  int v119 = v118->timer;
  int v126 = v119 + 1;
  v118->timer = v126;
  int * v121 = v118->regs;
  int v122 = v121[10];
  int v129 = v122 << 2;
  v121[10] = v129;
  struct StateT * v124 = slot_15(v118);
  return v124;
}

struct StateT * slot_6(struct StateT * v132) {
  int v133 = v132->timer;
  int v141 = v133 + 1;
  v132->timer = v141;
  int * v135 = v132->regs;
  int v136 = v135[11];
  int v137 = v135[14];
  int v145 = v136 + v137;
  v135[14] = v145;
  struct StateT * v139 = slot_7(v132);
  return v139;
}

struct StateT * slot_16(struct StateT * v182) {
  int v183 = v182->timer;
  int v192 = v183 + 1;
  v182->timer = v192;
  int * v185 = v182->regs;
  int v186 = v185[10];
  int v187 = v185[12];
  int * v188 = v182->mem;
  int v197 = (int)((unsigned int)v186 >> 2);
  v188[v197] = v187;
  struct StateT * v190 = slot_17(v182);
  return v190;
}

struct StateT * slot_5(struct StateT * v103) {
  int v104 = v103->timer;
  int v111 = v104 + 1;
  v103->timer = v111;
  int * v106 = v103->regs;
  int v107 = v106[10];
  int v115 = v107 << 2;
  v106[14] = v115;
  struct StateT * v109 = slot_6(v103);
  return v109;
}

struct StateT * slot_17(struct StateT * v215) {
  int v216 = v215->timer;
  int v219 = v216 + 1;
  v215->timer = v219;
  return v215;
}

struct StateT * slot_2(struct StateT * v39) {
  int v40 = v39->timer;
  int v46 = v40 + 1;
  v39->timer = v46;
  int * v42 = v39->regs;
  v42[15] = 15;
  struct StateT * v44 = slot_3(v39);
  return v44;
}

struct StateT * slot_7(struct StateT * v164) {
  int v165 = v164->timer;
  int v174 = v165 + 1;
  v164->timer = v174;
  int * v167 = v164->regs;
  int v168 = v167[14];
  int * v169 = v164->mem;
  int v178 = (int)((unsigned int)v168 >> 2);
  int v170 = v169[v178];
  v167[14] = v170;
  struct StateT * v172 = slot_8(v164);
  return v172;
}

struct StateT * slot_3(struct StateT * v51) {
  int v52 = v51->timer;
  int v60 = v52 + 1;
  v51->timer = v60;
  int * v54 = v51->regs;
  int v55 = v54[12];
  int v56 = v54[14];
  int v64 = v55 ^ v56;
  v54[12] = v64;
  struct StateT * v58 = slot_4(v51);
  return v58;
}

struct StateT * snippet(struct StateT * v0) {
  struct StateT * v1 = slot_0(v0);
  return v1;
}

struct StateT * slot_10(struct StateT * v234) {
  int v235 = v234->timer;
  int v243 = v235 + 1;
  v234->timer = v243;
  int * v237 = v234->regs;
  int v238 = v237[11];
  int v239 = v237[14];
  int v247 = v238 + v239;
  v237[11] = v247;
  struct StateT * v241 = slot_11(v234);
  return v241;
}

struct StateT * slot_1(struct StateT * v20) {
  int v21 = v20->timer;
  int v30 = v21 + 1;
  v20->timer = v30;
  int * v23 = v20->regs;
  int v24 = v23[11];
  int * v25 = v20->mem;
  int v34 = (int)((unsigned int)(v24 + 12) >> 2);
  int v26 = v25[v34];
  v23[14] = v26;
  struct StateT * v28 = slot_2(v20);
  return v28;
}

struct StateT * slot_8(struct StateT * v201) {
  int v202 = v201->timer;
  int v209 = v202 + 1;
  v201->timer = v209;
  int * v204 = v201->regs;
  int v205 = v204[14];
  int v212 = v205 & 15;
  v204[14] = v212;
  struct StateT * v207 = slot_9(v201);
  return v207;
}

struct StateT * slot_4(struct StateT * v67) {
  int v68 = v67->timer;
  int v79 = v68 + 1;
  v67->timer = v79;
  int * v70 = v67->regs;
  int v71 = v70[15];
  int v72 = v70[10];
  bool v83 = (v71 ^ -2147483648) < (v72 ^ -2147483648);
  struct StateT * v77;
  if (v83) {
    struct StateT * v73 = slot_13(v67);
    v77 = v73;
  } else {
    struct StateT * v75 = slot_5(v67);
    v77 = v75;
  }
  return v77;
}

struct StateT * slot_13(struct StateT * v89) {
  int v90 = v89->timer;
  int v97 = v90 + 1;
  v89->timer = v97;
  int * v92 = v89->regs;
  int v93 = v92[10];
  int v100 = v93 & 7;
  v92[10] = v100;
  struct StateT * v95 = slot_14(v89);
  return v95;
}

struct StateT * slot_15(struct StateT * v148) {
  int v149 = v148->timer;
  int v157 = v149 + 1;
  v148->timer = v157;
  int * v151 = v148->regs;
  int v152 = v151[13];
  int v153 = v151[10];
  int v161 = v152 + v153;
  v151[10] = v161;
  struct StateT * v155 = slot_16(v148);
  return v155;
}

struct StateT * slot_9(struct StateT * v220) {
  int v221 = v220->timer;
  int v228 = v221 + 1;
  v220->timer = v228;
  int * v223 = v220->regs;
  int v224 = v223[14];
  int v231 = v224 << 2;
  v223[14] = v231;
  struct StateT * v226 = slot_10(v220);
  return v226;
}

struct StateT * slot_11(struct StateT * v250) {
  int v251 = v250->timer;
  int v260 = v251 + 1;
  v250->timer = v260;
  int * v253 = v250->regs;
  int v254 = v253[11];
  int * v255 = v250->mem;
  int v264 = (int)((unsigned int)v254 >> 2);
  int v256 = v255[v264];
  v253[11] = v256;
  struct StateT * v258 = slot_12(v250);
  return v258;
}

struct StateT * slot_0(struct StateT * v2) {
  int v3 = v2->timer;
  int v12 = v3 + 1;
  v2->timer = v12;
  int * v5 = v2->regs;
  int v6 = v5[12];
  int * v7 = v2->mem;
  int v16 = (int)((unsigned int)v6 >> 2);
  int v8 = v7[v16];
  v5[12] = v8;
  struct StateT * v10 = slot_1(v2);
  return v10;
}



/*****************************************
End of C Generated Code
*******************************************/

void init(struct StateT *s) {
  for (int i=0; i<NUM_REGS; i++) {
    s->regs[i] = 0;
  }
  s->regs[2] = 4 * MEM_SIZE;
  s->timer = 0;
  for (int i=0; i<MEM_SIZE; i++) {
    s->mem[i] = 0;
  }
}

int main(int argc, char* argv[]) {
  struct StateT s1, s2;
  init(&s1);
  init(&s2);
  
  // a10, public: one draw, written into both states
  int a10 = bounded(0, 23);
  s1.regs[10] = a10;
  s2.regs[10] = a10;
  // a11, 16 words read by the callee: the address is public
  s1.regs[11] = 0;
  s2.regs[11] = 0;
  // its contents, public: the same draw in both states
  for (int i=0; i<16; i++) {
    int v = bounded(0, 20);
    s1.mem[0 + i] = v;
    s2.mem[0 + i] = v;
  }
  // a12, 8 words read by the callee: the address is public
  s1.regs[12] = 64;
  s2.regs[12] = 64;
  // a13, 8 words written by the callee: the address is public
  s1.regs[13] = 96;
  s2.regs[13] = 96;
  
  // a12's contents, secret: a different draw in each state
  for (int i=0; i<8; i++) {
    s1.mem[16 + i] = secret(0, 20);
    s2.mem[16 + i] = secret(0, 20);
  }
  struct StateT *s1_ = snippet(&s1);
  struct StateT *s2_ = snippet(&s2);
  koika_assert(s1_->timer==s2_->timer, "timing leak");
  return 0;
}