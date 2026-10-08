// verify: clean (KLEE should report no failing assertion) [budget 1200s]
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

struct StateT * slot_12(struct StateT * v195);
struct StateT * slot_14(struct StateT * v261);
struct StateT * slot_6(struct StateT * v104);
struct StateT * slot_16(struct StateT * v242);
struct StateT * slot_5(struct StateT * v86);
struct StateT * slot_17(struct StateT * v55);
struct StateT * slot_2(struct StateT * v33);
struct StateT * slot_7(struct StateT * v117);
struct StateT * slot_3(struct StateT * v60);
struct StateT * snippet(struct StateT * v0);
struct StateT * slot_10(struct StateT * v161);
struct StateT * slot_1(struct StateT * v15);
struct StateT * slot_8(struct StateT * v131);
struct StateT * slot_4(struct StateT * v73);
struct StateT * slot_13(struct StateT * v228);
struct StateT * slot_15(struct StateT * v215);
struct StateT * slot_9(struct StateT * v145);
struct StateT * slot_11(struct StateT * v179);
struct StateT * slot_0(struct StateT * v2);
struct StateT * slot_12(struct StateT * v195) {
  int v196 = v195->timer;
  int v206 = v196 + 1;
  v195->timer = v206;
  int * v198 = v195->regs;
  int v199 = v198[13];
  bool v209 = !(v199 == 0);
  struct StateT * v204;
  if (v209) {
    struct StateT * v200 = slot_15(v195);
    v204 = v200;
  } else {
    struct StateT * v202 = slot_13(v195);
    v204 = v202;
  }
  return v204;
}

struct StateT * slot_14(struct StateT * v261) {
  int v262 = v261->timer;
  int v273 = v262 + 1;
  v261->timer = v273;
  int * v264 = v261->regs;
  int v265 = v264[10];
  int v266 = v264[11];
  bool v277 = (v265 ^ -2147483648) < (v266 ^ -2147483648);
  struct StateT * v271;
  if (v277) {
    struct StateT * v267 = slot_8(v261);
    v271 = v267;
  } else {
    struct StateT * v269 = slot_15(v261);
    v271 = v269;
  }
  return v271;
}

struct StateT * slot_6(struct StateT * v104) {
  int v105 = v104->timer;
  int v111 = v105 + 1;
  v104->timer = v111;
  int * v107 = v104->regs;
  v107[14] = 0;
  struct StateT * v109 = slot_7(v104);
  return v109;
}

struct StateT * slot_16(struct StateT * v242) {
  int v243 = v242->timer;
  int v252 = v243 + 1;
  v242->timer = v252;
  int * v245 = v242->regs;
  int v246 = v245[10];
  int v247 = v245[12];
  int * v248 = v242->mem;
  int v257 = (int)((unsigned int)(v246 + 68) >> 2);
  v248[v257] = v247;
  struct StateT * v250 = slot_17(v242);
  return v250;
}

struct StateT * slot_5(struct StateT * v86) {
  int v87 = v86->timer;
  int v96 = v87 + 1;
  v86->timer = v96;
  int * v89 = v86->regs;
  int v90 = v89[12];
  int * v91 = v86->mem;
  int v100 = (int)((unsigned int)(v90 + 68) >> 2);
  int v92 = v91[v100];
  v89[12] = v92;
  struct StateT * v94 = slot_6(v86);
  return v94;
}

struct StateT * slot_17(struct StateT * v55) {
  int v56 = v55->timer;
  int v59 = v56 + 1;
  v55->timer = v59;
  return v55;
}

struct StateT * slot_2(struct StateT * v33) {
  int v34 = v33->timer;
  int v45 = v34 + 1;
  v33->timer = v45;
  int * v36 = v33->regs;
  int v37 = v36[10];
  int v38 = v36[11];
  bool v49 = (v37 ^ -2147483648) >= (v38 ^ -2147483648);
  struct StateT * v43;
  if (v49) {
    struct StateT * v39 = slot_17(v33);
    v43 = v39;
  } else {
    struct StateT * v41 = slot_3(v33);
    v43 = v41;
  }
  return v43;
}

struct StateT * slot_7(struct StateT * v117) {
  int v118 = v117->timer;
  int v125 = v118 + 1;
  v117->timer = v125;
  int * v120 = v117->regs;
  int v121 = v120[14];
  int v128 = v121 + 72;
  v120[14] = v128;
  struct StateT * v123 = slot_8(v117);
  return v123;
}

struct StateT * slot_3(struct StateT * v60) {
  int v61 = v60->timer;
  int v67 = v61 + 1;
  v60->timer = v67;
  int * v63 = v60->regs;
  v63[13] = 0;
  struct StateT * v65 = slot_4(v60);
  return v65;
}

struct StateT * snippet(struct StateT * v0) {
  struct StateT * v1 = slot_0(v0);
  return v1;
}

struct StateT * slot_10(struct StateT * v161) {
  int v162 = v161->timer;
  int v171 = v162 + 1;
  v161->timer = v171;
  int * v164 = v161->regs;
  int v165 = v164[10];
  int * v166 = v161->mem;
  int v175 = (int)((unsigned int)v165 >> 2);
  int v167 = v166[v175];
  v164[10] = v167;
  struct StateT * v169 = slot_11(v161);
  return v169;
}

struct StateT * slot_1(struct StateT * v15) {
  int v16 = v15->timer;
  int v25 = v16 + 1;
  v15->timer = v25;
  int * v18 = v15->regs;
  int v19 = v18[11];
  int * v20 = v15->mem;
  int v29 = (int)((unsigned int)v19 >> 2);
  int v21 = v20[v29];
  v18[11] = v21;
  struct StateT * v23 = slot_2(v15);
  return v23;
}

struct StateT * slot_8(struct StateT * v131) {
  int v132 = v131->timer;
  int v139 = v132 + 1;
  v131->timer = v139;
  int * v134 = v131->regs;
  int v135 = v134[10];
  int v142 = v135 << 2;
  v134[10] = v142;
  struct StateT * v137 = slot_9(v131);
  return v137;
}

struct StateT * slot_4(struct StateT * v73) {
  int v74 = v73->timer;
  int v80 = v74 + 1;
  v73->timer = v80;
  int * v76 = v73->regs;
  v76[12] = 0;
  struct StateT * v78 = slot_5(v73);
  return v78;
}

struct StateT * slot_13(struct StateT * v228) {
  int v229 = v228->timer;
  int v236 = v229 + 1;
  v228->timer = v236;
  int * v231 = v228->regs;
  int v232 = v231[13];
  int v239 = v232 + -1;
  v231[13] = v239;
  struct StateT * v234 = slot_14(v228);
  return v234;
}

struct StateT * slot_15(struct StateT * v215) {
  int v216 = v215->timer;
  int v222 = v216 + 1;
  v215->timer = v222;
  int * v218 = v215->regs;
  v218[10] = 0;
  struct StateT * v220 = slot_16(v215);
  return v220;
}

struct StateT * slot_9(struct StateT * v145) {
  int v146 = v145->timer;
  int v154 = v146 + 1;
  v145->timer = v154;
  int * v148 = v145->regs;
  int v149 = v148[14];
  int v150 = v148[10];
  int v158 = v149 + v150;
  v148[10] = v158;
  struct StateT * v152 = slot_10(v145);
  return v152;
}

struct StateT * slot_11(struct StateT * v179) {
  int v180 = v179->timer;
  int v188 = v180 + 1;
  v179->timer = v188;
  int * v182 = v179->regs;
  int v183 = v182[12];
  int v184 = v182[10];
  int v192 = v183 & v184;
  v182[12] = v192;
  struct StateT * v186 = slot_12(v179);
  return v186;
}

struct StateT * slot_0(struct StateT * v2) {
  int v3 = v2->timer;
  int v9 = v3 + 1;
  v2->timer = v9;
  int * v5 = v2->regs;
  v5[11] = 0;
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
    s->reg_ready[i] = 0;
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
  
  // public data, where the section headers put it
  s1.mem[0] = 8;
  s2.mem[0] = 8;
  int x = bounded(0, 15);
  s1.regs[10] = x;
  s2.regs[10] = x;
  // probe, the attacker's: the same draw in both states
  for (int i=0; i<16; i++) {
    int v = bounded(0, 20);
    s1.mem[1 + i] = v;
    s2.mem[1 + i] = v;
  }
  // temp, the attacker's: the same draw in both states
  for (int i=0; i<1; i++) {
    int v = bounded(0, 20);
    s1.mem[17 + i] = v;
    s2.mem[17 + i] = v;
  }
  // publicarray, the attacker's: the same draw in both states
  for (int i=0; i<8; i++) {
    int v = bounded(0, 20);
    s1.mem[18 + i] = v;
    s2.mem[18 + i] = v;
  }
  
  // secretarray, secret: a different draw in each state
  for (int i=0; i<8; i++) {
    s1.mem[26 + i] = secret(0, 20);
    s2.mem[26 + i] = secret(0, 20);
  }
  struct StateT *s1_ = snippet(&s1);
  struct StateT *s2_ = snippet(&s2);
  //@ assert untainted_timer: !\tainted(s1_->timer==s2_->timer);
  koika_assert(s1_->timer==s2_->timer, "timing leak");
  return 0;
}