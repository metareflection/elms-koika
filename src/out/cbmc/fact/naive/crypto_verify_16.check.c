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

struct StateT * slot_12(struct StateT * v219);
struct StateT * slot_14(struct StateT * v252);
struct StateT * slot_6(struct StateT * v112);
struct StateT * slot_16(struct StateT * v282);
struct StateT * slot_5(struct StateT * v90);
struct StateT * slot_17(struct StateT * v73);
struct StateT * slot_2(struct StateT * v28);
struct StateT * slot_7(struct StateT * v129);
struct StateT * slot_3(struct StateT * v41);
struct StateT * snippet(struct StateT * v0);
struct StateT * slot_10(struct StateT * v181);
struct StateT * slot_1(struct StateT * v15);
struct StateT * slot_8(struct StateT * v147);
struct StateT * slot_4(struct StateT * v53);
struct StateT * slot_13(struct StateT * v236);
struct StateT * slot_15(struct StateT * v268);
struct StateT * slot_18(struct StateT * v107);
struct StateT * slot_9(struct StateT * v165);
struct StateT * slot_11(struct StateT * v203);
struct StateT * slot_0(struct StateT * v2);
struct StateT * slot_12(struct StateT * v219) {
  int v220 = v219->timer;
  int v228 = v220 + 1;
  v219->timer = v228;
  int * v222 = v219->regs;
  int v223 = v222[16];
  int v224 = v222[12];
  int v233 = v223 & v224;
  v222[17] = v233;
  struct StateT * v226 = slot_13(v219);
  return v226;
}

struct StateT * slot_14(struct StateT * v252) {
  int v253 = v252->timer;
  int v261 = v253 + 1;
  v252->timer = v261;
  int * v255 = v252->regs;
  int v256 = v255[12];
  int v257 = v255[17];
  int v265 = v256 ^ v257;
  v255[12] = v265;
  struct StateT * v259 = slot_15(v252);
  return v259;
}

struct StateT * slot_6(struct StateT * v112) {
  int v113 = v112->timer;
  int v121 = v113 + 1;
  v112->timer = v121;
  int * v115 = v112->regs;
  int v116 = v115[11];
  int v117 = v115[13];
  int v126 = v116 + v117;
  v115[17] = v126;
  struct StateT * v119 = slot_7(v112);
  return v119;
}

struct StateT * slot_16(struct StateT * v282) {
  int v283 = v282->timer;
  int v294 = v283 + 1;
  v282->timer = v294;
  int * v285 = v282->regs;
  int v286 = v285[15];
  int v287 = v285[13];
  bool v298 = (v286 ^ -2147483648) >= (v287 ^ -2147483648);
  struct StateT * v292;
  if (v298) {
    struct StateT * v288 = slot_5(v282);
    v292 = v288;
  } else {
    struct StateT * v290 = slot_17(v282);
    v292 = v290;
  }
  return v292;
}

struct StateT * slot_5(struct StateT * v90) {
  int v91 = v90->timer;
  int v99 = v91 + 1;
  v90->timer = v99;
  int * v93 = v90->regs;
  int v94 = v93[10];
  int v95 = v93[13];
  int v104 = v94 + v95;
  v93[16] = v104;
  struct StateT * v97 = slot_6(v90);
  return v97;
}

struct StateT * slot_17(struct StateT * v73) {
  int v74 = v73->timer;
  int v82 = v74 + 1;
  v73->timer = v82;
  int * v76 = v73->regs;
  int v77 = v76[14];
  int v78 = v76[12];
  int v87 = v77 | v78;
  v76[10] = v87;
  struct StateT * v80 = slot_18(v73);
  return v80;
}

struct StateT * slot_2(struct StateT * v28) {
  int v29 = v28->timer;
  int v35 = v29 + 1;
  v28->timer = v35;
  int * v31 = v28->regs;
  v31[14] = 1;
  struct StateT * v33 = slot_3(v28);
  return v33;
}

struct StateT * slot_7(struct StateT * v129) {
  int v130 = v129->timer;
  int v139 = v130 + 1;
  v129->timer = v139;
  int * v132 = v129->regs;
  int v133 = v132[16];
  int * v134 = v129->mem;
  int v143 = (int)((unsigned int)v133 >> 2);
  int v135 = v134[v143];
  int v144 = ((int)((unsigned int)v135 >> ((v133 & 3) << 3))) & 255;
  v132[16] = v144;
  struct StateT * v137 = slot_8(v129);
  return v137;
}

struct StateT * slot_3(struct StateT * v41) {
  int v42 = v41->timer;
  int v48 = v42 + 1;
  v41->timer = v48;
  int * v44 = v41->regs;
  v44[15] = 15;
  struct StateT * v46 = slot_4(v41);
  return v46;
}

struct StateT * snippet(struct StateT * v0) {
  struct StateT * v1 = slot_0(v0);
  return v1;
}

struct StateT * slot_10(struct StateT * v181) {
  int v182 = v181->timer;
  int v193 = v182 + 1;
  v181->timer = v193;
  int * v184 = v181->regs;
  int v185 = v184[16];
  bool v196 = -2147483648 < (v185 ^ -2147483648);
  int v188;
  if (v196) {
    v188 = 1;
  } else {
    v188 = 0;
  }
  int * v189 = v181->regs;
  v189[16] = v188;
  struct StateT * v191 = slot_11(v181);
  return v191;
}

struct StateT * slot_1(struct StateT * v15) {
  int v16 = v15->timer;
  int v22 = v16 + 1;
  v15->timer = v22;
  int * v18 = v15->regs;
  v18[13] = 0;
  struct StateT * v20 = slot_2(v15);
  return v20;
}

struct StateT * slot_8(struct StateT * v147) {
  int v148 = v147->timer;
  int v157 = v148 + 1;
  v147->timer = v157;
  int * v150 = v147->regs;
  int v151 = v150[17];
  int * v152 = v147->mem;
  int v161 = (int)((unsigned int)v151 >> 2);
  int v153 = v152[v161];
  int v162 = ((int)((unsigned int)v153 >> ((v151 & 3) << 3))) & 255;
  v150[17] = v162;
  struct StateT * v155 = slot_9(v147);
  return v155;
}

struct StateT * slot_4(struct StateT * v53) {
  int v54 = v53->timer;
  int v64 = v54 + 1;
  v53->timer = v64;
  int * v56 = v53->regs;
  int v57 = v56[15];
  bool v67 = (v57 ^ -2147483648) < -2147483648;
  struct StateT * v62;
  if (v67) {
    struct StateT * v58 = slot_17(v53);
    v62 = v58;
  } else {
    struct StateT * v60 = slot_5(v53);
    v62 = v60;
  }
  return v62;
}

struct StateT * slot_13(struct StateT * v236) {
  int v237 = v236->timer;
  int v245 = v237 + 1;
  v236->timer = v245;
  int * v239 = v236->regs;
  int v240 = v239[14];
  int v241 = v239[16];
  int v249 = v240 ^ v241;
  v239[14] = v249;
  struct StateT * v243 = slot_14(v236);
  return v243;
}

struct StateT * slot_15(struct StateT * v268) {
  int v269 = v268->timer;
  int v276 = v269 + 1;
  v268->timer = v276;
  int * v271 = v268->regs;
  int v272 = v271[13];
  int v279 = v272 + 1;
  v271[13] = v279;
  struct StateT * v274 = slot_16(v268);
  return v274;
}

struct StateT * slot_18(struct StateT * v107) {
  int v108 = v107->timer;
  int v111 = v108 + 1;
  v107->timer = v111;
  return v107;
}

struct StateT * slot_9(struct StateT * v165) {
  int v166 = v165->timer;
  int v174 = v166 + 1;
  v165->timer = v174;
  int * v168 = v165->regs;
  int v169 = v168[16];
  int v170 = v168[17];
  int v178 = v169 ^ v170;
  v168[16] = v178;
  struct StateT * v172 = slot_10(v165);
  return v172;
}

struct StateT * slot_11(struct StateT * v203) {
  int v204 = v203->timer;
  int v212 = v204 + 1;
  v203->timer = v212;
  int * v206 = v203->regs;
  int v207 = v206[16];
  int v208 = v206[14];
  int v216 = v207 & v208;
  v206[16] = v216;
  struct StateT * v210 = slot_12(v203);
  return v210;
}

struct StateT * slot_0(struct StateT * v2) {
  int v3 = v2->timer;
  int v9 = v3 + 1;
  v2->timer = v9;
  int * v5 = v2->regs;
  v5[12] = 0;
  struct StateT * v7 = slot_1(v2);
  return v7;
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
  
  // a10, 4 words read by the callee: the address is public
  s1.regs[10] = 0;
  s2.regs[10] = 0;
  // a11, 4 words read by the callee: the address is public
  s1.regs[11] = 16;
  s2.regs[11] = 16;
  
  // a10's contents, secret: a different draw in each state
  for (int i=0; i<4; i++) {
    s1.mem[0 + i] = secret(0, 20);
    s2.mem[0 + i] = secret(0, 20);
  }
  // a11's contents, secret: a different draw in each state
  for (int i=0; i<4; i++) {
    s1.mem[4 + i] = secret(0, 20);
    s2.mem[4 + i] = secret(0, 20);
  }
  struct StateT *s1_ = snippet(&s1);
  struct StateT *s2_ = snippet(&s2);
  //@ assert untainted_timer: !\tainted(s1_->timer==s2_->timer);
  koika_assert(s1_->timer==s2_->timer, "timing leak");
  return 0;
}