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

struct StateT * slot_12(struct StateT * v189);
struct StateT * slot_14(struct StateT * v219);
struct StateT * slot_6(struct StateT * v101);
struct StateT * slot_16(struct StateT * v256);
struct StateT * slot_5(struct StateT * v87);
struct StateT * slot_17(struct StateT * v272);
struct StateT * slot_2(struct StateT * v33);
struct StateT * slot_7(struct StateT * v117);
struct StateT * slot_3(struct StateT * v60);
struct StateT * snippet(struct StateT * v0);
struct StateT * slot_10(struct StateT * v162);
struct StateT * slot_1(struct StateT * v15);
struct StateT * slot_8(struct StateT * v135);
struct StateT * slot_4(struct StateT * v74);
struct StateT * slot_13(struct StateT * v203);
struct StateT * slot_15(struct StateT * v237);
struct StateT * slot_18(struct StateT * v55);
struct StateT * slot_9(struct StateT * v148);
struct StateT * slot_11(struct StateT * v175);
struct StateT * slot_0(struct StateT * v2);
struct StateT * slot_12(struct StateT * v189) {
  int v190 = v189->timer;
  int v197 = v190 + 1;
  v189->timer = v197;
  int * v192 = v189->regs;
  int v193 = v192[10];
  int v200 = (int)((unsigned int)v193 >> 26);
  v192[10] = v200;
  struct StateT * v195 = slot_13(v189);
  return v195;
}

struct StateT * slot_14(struct StateT * v219) {
  int v220 = v219->timer;
  int v229 = v220 + 1;
  v219->timer = v229;
  int * v222 = v219->regs;
  int v223 = v222[10];
  int * v224 = v219->mem;
  int v233 = (int)((unsigned int)v223 >> 2);
  int v225 = v224[v233];
  v222[10] = v225;
  struct StateT * v227 = slot_15(v219);
  return v227;
}

struct StateT * slot_6(struct StateT * v101) {
  int v102 = v101->timer;
  int v110 = v102 + 1;
  v101->timer = v110;
  int * v104 = v101->regs;
  int v105 = v104[11];
  int v106 = v104[10];
  int v114 = v105 + v106;
  v104[10] = v114;
  struct StateT * v108 = slot_7(v101);
  return v108;
}

struct StateT * slot_16(struct StateT * v256) {
  int v257 = v256->timer;
  int v265 = v257 + 1;
  v256->timer = v265;
  int * v259 = v256->regs;
  int v260 = v259[11];
  int v261 = v259[10];
  int v269 = v260 & v261;
  v259[10] = v269;
  struct StateT * v263 = slot_17(v256);
  return v263;
}

struct StateT * slot_5(struct StateT * v87) {
  int v88 = v87->timer;
  int v95 = v88 + 1;
  v87->timer = v95;
  int * v90 = v87->regs;
  int v91 = v90[11];
  int v98 = v91 + 72;
  v90[11] = v98;
  struct StateT * v93 = slot_6(v87);
  return v93;
}

struct StateT * slot_17(struct StateT * v272) {
  int v273 = v272->timer;
  int v282 = v273 + 1;
  v272->timer = v282;
  int * v275 = v272->regs;
  int v276 = v275[12];
  int v277 = v275[10];
  int * v278 = v272->mem;
  int v287 = (int)((unsigned int)(v276 + 68) >> 2);
  v278[v287] = v277;
  struct StateT * v280 = slot_18(v272);
  return v280;
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
    struct StateT * v39 = slot_18(v33);
    v43 = v39;
  } else {
    struct StateT * v41 = slot_3(v33);
    v43 = v41;
  }
  return v43;
}

struct StateT * slot_7(struct StateT * v117) {
  int v118 = v117->timer;
  int v127 = v118 + 1;
  v117->timer = v127;
  int * v120 = v117->regs;
  int v121 = v120[10];
  int * v122 = v117->mem;
  int v131 = (int)((unsigned int)v121 >> 2);
  int v123 = v122[v131];
  v120[10] = v123;
  struct StateT * v125 = slot_8(v117);
  return v125;
}

struct StateT * slot_3(struct StateT * v60) {
  int v61 = v60->timer;
  int v68 = v61 + 1;
  v60->timer = v68;
  int * v63 = v60->regs;
  int v64 = v63[10];
  int v71 = v64 << 2;
  v63[10] = v71;
  struct StateT * v66 = slot_4(v60);
  return v66;
}

struct StateT * snippet(struct StateT * v0) {
  struct StateT * v1 = slot_0(v0);
  return v1;
}

struct StateT * slot_10(struct StateT * v162) {
  int v163 = v162->timer;
  int v169 = v163 + 1;
  v162->timer = v169;
  int * v165 = v162->regs;
  v165[12] = 0;
  struct StateT * v167 = slot_11(v162);
  return v167;
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

struct StateT * slot_8(struct StateT * v135) {
  int v136 = v135->timer;
  int v142 = v136 + 1;
  v135->timer = v142;
  int * v138 = v135->regs;
  v138[11] = 0;
  struct StateT * v140 = slot_9(v135);
  return v140;
}

struct StateT * slot_4(struct StateT * v74) {
  int v75 = v74->timer;
  int v81 = v75 + 1;
  v74->timer = v81;
  int * v77 = v74->regs;
  v77[11] = 0;
  struct StateT * v79 = slot_5(v74);
  return v79;
}

struct StateT * slot_13(struct StateT * v203) {
  int v204 = v203->timer;
  int v212 = v204 + 1;
  v203->timer = v212;
  int * v206 = v203->regs;
  int v207 = v206[11];
  int v208 = v206[10];
  int v216 = v207 + v208;
  v206[10] = v216;
  struct StateT * v210 = slot_14(v203);
  return v210;
}

struct StateT * slot_15(struct StateT * v237) {
  int v238 = v237->timer;
  int v247 = v238 + 1;
  v237->timer = v247;
  int * v240 = v237->regs;
  int v241 = v240[12];
  int * v242 = v237->mem;
  int v251 = (int)((unsigned int)(v241 + 68) >> 2);
  int v243 = v242[v251];
  v240[11] = v243;
  struct StateT * v245 = slot_16(v237);
  return v245;
}

struct StateT * slot_18(struct StateT * v55) {
  int v56 = v55->timer;
  int v59 = v56 + 1;
  v55->timer = v59;
  return v55;
}

struct StateT * slot_9(struct StateT * v148) {
  int v149 = v148->timer;
  int v156 = v149 + 1;
  v148->timer = v156;
  int * v151 = v148->regs;
  int v152 = v151[11];
  int v159 = v152 + 4;
  v151[11] = v159;
  struct StateT * v154 = slot_10(v148);
  return v154;
}

struct StateT * slot_11(struct StateT * v175) {
  int v176 = v175->timer;
  int v183 = v176 + 1;
  v175->timer = v183;
  int * v178 = v175->regs;
  int v179 = v178[10];
  int v186 = v179 << 29;
  v178[10] = v186;
  struct StateT * v181 = slot_12(v175);
  return v181;
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