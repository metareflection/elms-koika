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
  int mem[64];
  int saved_regs[32];
  int reg_ready[32];
  int cache_tags[12];
  int cache_dirty[12];
  int cache_age[12];
  int cache_vals[24];
  int timer;
};

struct StateT * slot_12(struct StateT * v306);
struct StateT * slot_14(struct StateT * v132);
struct StateT * slot_6(struct StateT * v148);
struct StateT * slot_16(struct StateT * v208);
struct StateT * slot_5(struct StateT * v115);
struct StateT * slot_17(struct StateT * v245);
struct StateT * slot_2(struct StateT * v43);
struct StateT * slot_7(struct StateT * v188);
struct StateT * slot_3(struct StateT * v55);
struct StateT * snippet(struct StateT * v0);
struct StateT * slot_10(struct StateT * v266);
struct StateT * slot_1(struct StateT * v22);
struct StateT * slot_8(struct StateT * v229);
struct StateT * slot_4(struct StateT * v75);
struct StateT * slot_13(struct StateT * v99);
struct StateT * slot_15(struct StateT * v168);
struct StateT * slot_9(struct StateT * v250);
struct StateT * slot_11(struct StateT * v286);
struct StateT * slot_0(struct StateT * v2);
struct StateT * slot_12(struct StateT * v306) {
  int v307 = v306->timer;
  int v317 = v307 + 1;
  v306->timer = v317;
  int * v309 = v306->regs;
  int v310 = v309[12];
  int * v311 = v306->regs;
  int v312 = v311[11];
  int * v313 = v306->regs;
  int v323 = v310 + v312;
  v313[12] = v323;
  struct StateT * v315 = slot_13(v306);
  return v315;
}

struct StateT * slot_14(struct StateT * v132) {
  int v133 = v132->timer;
  int v141 = v133 + 1;
  v132->timer = v141;
  int * v135 = v132->regs;
  int v136 = v135[10];
  int * v137 = v132->regs;
  int v145 = v136 << 2;
  v137[10] = v145;
  struct StateT * v139 = slot_15(v132);
  return v139;
}

struct StateT * slot_6(struct StateT * v148) {
  int v149 = v148->timer;
  int v159 = v149 + 1;
  v148->timer = v159;
  int * v151 = v148->regs;
  int v152 = v151[11];
  int * v153 = v148->regs;
  int v154 = v153[14];
  int * v155 = v148->regs;
  int v165 = v152 + v154;
  v155[14] = v165;
  struct StateT * v157 = slot_7(v148);
  return v157;
}

struct StateT * slot_16(struct StateT * v208) {
  int v209 = v208->timer;
  int v219 = v209 + 1;
  v208->timer = v219;
  int * v211 = v208->regs;
  int v212 = v211[10];
  int * v213 = v208->regs;
  int v214 = v213[12];
  int * v215 = v208->mem;
  int v225 = (int)((unsigned int)v212 >> 2);
  v215[v225] = v214;
  struct StateT * v217 = slot_17(v208);
  return v217;
}

struct StateT * slot_5(struct StateT * v115) {
  int v116 = v115->timer;
  int v124 = v116 + 1;
  v115->timer = v124;
  int * v118 = v115->regs;
  int v119 = v118[10];
  int * v120 = v115->regs;
  int v129 = v119 << 2;
  v120[14] = v129;
  struct StateT * v122 = slot_6(v115);
  return v122;
}

struct StateT * slot_17(struct StateT * v245) {
  int v246 = v245->timer;
  int v249 = v246 + 1;
  v245->timer = v249;
  return v245;
}

struct StateT * slot_2(struct StateT * v43) {
  int v44 = v43->timer;
  int v50 = v44 + 1;
  v43->timer = v50;
  int * v46 = v43->regs;
  v46[15] = 15;
  struct StateT * v48 = slot_3(v43);
  return v48;
}

struct StateT * slot_7(struct StateT * v188) {
  int v189 = v188->timer;
  int v199 = v189 + 1;
  v188->timer = v199;
  int * v191 = v188->regs;
  int v192 = v191[14];
  int * v193 = v188->mem;
  int v203 = (int)((unsigned int)v192 >> 2);
  int v194 = v193[v203];
  int * v195 = v188->regs;
  v195[14] = v194;
  struct StateT * v197 = slot_8(v188);
  return v197;
}

struct StateT * slot_3(struct StateT * v55) {
  int v56 = v55->timer;
  int v66 = v56 + 1;
  v55->timer = v66;
  int * v58 = v55->regs;
  int v59 = v58[12];
  int * v60 = v55->regs;
  int v61 = v60[14];
  int * v62 = v55->regs;
  int v72 = v59 ^ v61;
  v62[12] = v72;
  struct StateT * v64 = slot_4(v55);
  return v64;
}

struct StateT * snippet(struct StateT * v0) {
  struct StateT * v1 = slot_0(v0);
  return v1;
}

struct StateT * slot_10(struct StateT * v266) {
  int v267 = v266->timer;
  int v277 = v267 + 1;
  v266->timer = v277;
  int * v269 = v266->regs;
  int v270 = v269[11];
  int * v271 = v266->regs;
  int v272 = v271[14];
  int * v273 = v266->regs;
  int v283 = v270 + v272;
  v273[11] = v283;
  struct StateT * v275 = slot_11(v266);
  return v275;
}

struct StateT * slot_1(struct StateT * v22) {
  int v23 = v22->timer;
  int v33 = v23 + 1;
  v22->timer = v33;
  int * v25 = v22->regs;
  int v26 = v25[11];
  int * v27 = v22->mem;
  int v37 = (int)((unsigned int)(v26 + 12) >> 2);
  int v28 = v27[v37];
  int * v29 = v22->regs;
  v29[14] = v28;
  struct StateT * v31 = slot_2(v22);
  return v31;
}

struct StateT * slot_8(struct StateT * v229) {
  int v230 = v229->timer;
  int v238 = v230 + 1;
  v229->timer = v238;
  int * v232 = v229->regs;
  int v233 = v232[14];
  int * v234 = v229->regs;
  int v242 = v233 & 15;
  v234[14] = v242;
  struct StateT * v236 = slot_9(v229);
  return v236;
}

struct StateT * slot_4(struct StateT * v75) {
  int v76 = v75->timer;
  int v88 = v76 + 1;
  v75->timer = v88;
  int * v78 = v75->regs;
  int v79 = v78[15];
  int * v80 = v75->regs;
  int v81 = v80[10];
  bool v93 = (v79 ^ -2147483648) < (v81 ^ -2147483648);
  struct StateT * v86;
  if (v93) {
    struct StateT * v82 = slot_13(v75);
    v86 = v82;
  } else {
    struct StateT * v84 = slot_5(v75);
    v86 = v84;
  }
  return v86;
}

struct StateT * slot_13(struct StateT * v99) {
  int v100 = v99->timer;
  int v108 = v100 + 1;
  v99->timer = v108;
  int * v102 = v99->regs;
  int v103 = v102[10];
  int * v104 = v99->regs;
  int v112 = v103 & 7;
  v104[10] = v112;
  struct StateT * v106 = slot_14(v99);
  return v106;
}

struct StateT * slot_15(struct StateT * v168) {
  int v169 = v168->timer;
  int v179 = v169 + 1;
  v168->timer = v179;
  int * v171 = v168->regs;
  int v172 = v171[13];
  int * v173 = v168->regs;
  int v174 = v173[10];
  int * v175 = v168->regs;
  int v185 = v172 + v174;
  v175[10] = v185;
  struct StateT * v177 = slot_16(v168);
  return v177;
}

struct StateT * slot_9(struct StateT * v250) {
  int v251 = v250->timer;
  int v259 = v251 + 1;
  v250->timer = v259;
  int * v253 = v250->regs;
  int v254 = v253[14];
  int * v255 = v250->regs;
  int v263 = v254 << 2;
  v255[14] = v263;
  struct StateT * v257 = slot_10(v250);
  return v257;
}

struct StateT * slot_11(struct StateT * v286) {
  int v287 = v286->timer;
  int v297 = v287 + 1;
  v286->timer = v297;
  int * v289 = v286->regs;
  int v290 = v289[11];
  int * v291 = v286->mem;
  int v301 = (int)((unsigned int)v290 >> 2);
  int v292 = v291[v301];
  int * v293 = v286->regs;
  v293[11] = v292;
  struct StateT * v295 = slot_12(v286);
  return v295;
}

struct StateT * slot_0(struct StateT * v2) {
  int v3 = v2->timer;
  int v13 = v3 + 1;
  v2->timer = v13;
  int * v5 = v2->regs;
  int v6 = v5[12];
  int * v7 = v2->mem;
  int v17 = (int)((unsigned int)v6 >> 2);
  int v8 = v7[v17];
  int * v9 = v2->regs;
  v9[12] = v8;
  struct StateT * v11 = slot_1(v2);
  return v11;
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
    s1.mem[16 + i] = bounded(0, 20);
    s2.mem[16 + i] = bounded(0, 20);
  }
  struct StateT *s1_ = snippet(&s1);
  struct StateT *s2_ = snippet(&s2);
  koika_assert(s1_->timer==s2_->timer, "timing leak");
  return 0;
}