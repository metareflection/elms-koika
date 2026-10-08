// verify: leak widened (the program is clean; Eva cannot prove it) [unroll 65]
#define NUM_REGS 32
#define MEM_SIZE 64
#define SECRET_SIZE 10
#define SECRET_OFFSET 20
#define CACHE_ENTRIES 12
#define CACHE_WORDS 24

#ifdef EVA
#include "__fc_builtin.h"
/*@ assigns *p \from \nothing;
    taints *p; */
void koika_mark(int *p);
#define koika_assert(b, s) ((void)0)
#define koika_assume(b) do { if (!(b)) Frama_C_abort(); } while (0)
#define koika_draw(x) ((x) = Frama_C_interval(-2147483647-1, 2147483647))
#define koika_secret(x) koika_mark(&(x))
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

struct StateT * slot_12(struct StateT * v201);
struct StateT * slot_14(struct StateT * v236);
struct StateT * slot_6(struct StateT * v101);
struct StateT * slot_5(struct StateT * v87);
struct StateT * slot_2(struct StateT * v33);
struct StateT * slot_7(struct StateT * v117);
struct StateT * slot_3(struct StateT * v60);
struct StateT * snippet(struct StateT * v0);
struct StateT * slot_10(struct StateT * v170);
struct StateT * slot_1(struct StateT * v15);
struct StateT * slot_8(struct StateT * v135);
struct StateT * slot_4(struct StateT * v74);
struct StateT * slot_13(struct StateT * v220);
struct StateT * slot_15(struct StateT * v55);
struct StateT * slot_9(struct StateT * v157);
struct StateT * slot_11(struct StateT * v183);
struct StateT * slot_0(struct StateT * v2);
struct StateT * slot_12(struct StateT * v201) {
  int v202 = v201->timer;
  int v211 = v202 + 1;
  v201->timer = v211;
  int * v204 = v201->regs;
  int v205 = v204[11];
  int * v206 = v201->mem;
  int v215 = (int)((unsigned int)(v205 + 68) >> 2);
  int v207 = v206[v215];
  v204[12] = v207;
  struct StateT * v209 = slot_13(v201);
  return v209;
}

struct StateT * slot_14(struct StateT * v236) {
  int v237 = v236->timer;
  int v246 = v237 + 1;
  v236->timer = v246;
  int * v239 = v236->regs;
  int v240 = v239[11];
  int v241 = v239[10];
  int * v242 = v236->mem;
  int v251 = (int)((unsigned int)(v240 + 68) >> 2);
  v242[v251] = v241;
  struct StateT * v244 = slot_15(v236);
  return v244;
}

struct StateT * slot_6(struct StateT * v101) {
  int v102 = v101->timer;
  int v110 = v102 + 1;
  v101->timer = v110;
  int * v104 = v101->regs;
  int v105 = v104[12];
  int v106 = v104[10];
  int v114 = v105 + v106;
  v104[10] = v114;
  struct StateT * v108 = slot_7(v101);
  return v108;
}

struct StateT * slot_5(struct StateT * v87) {
  int v88 = v87->timer;
  int v95 = v88 + 1;
  v87->timer = v95;
  int * v90 = v87->regs;
  int v91 = v90[12];
  int v98 = v91 + 72;
  v90[12] = v98;
  struct StateT * v93 = slot_6(v87);
  return v93;
}

struct StateT * slot_2(struct StateT * v33) {
  int v34 = v33->timer;
  int v45 = v34 + 1;
  v33->timer = v45;
  int * v36 = v33->regs;
  int v37 = v36[10];
  int v38 = v36[12];
  bool v49 = (v37 ^ -2147483648) >= (v38 ^ -2147483648);
  struct StateT * v43;
  if (v49) {
    struct StateT * v39 = slot_15(v33);
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

struct StateT * slot_10(struct StateT * v170) {
  int v171 = v170->timer;
  int v177 = v171 + 1;
  v170->timer = v177;
  int * v173 = v170->regs;
  v173[11] = 0;
  struct StateT * v175 = slot_11(v170);
  return v175;
}

struct StateT * slot_1(struct StateT * v15) {
  int v16 = v15->timer;
  int v25 = v16 + 1;
  v15->timer = v25;
  int * v18 = v15->regs;
  int v19 = v18[12];
  int * v20 = v15->mem;
  int v29 = (int)((unsigned int)v19 >> 2);
  int v21 = v20[v29];
  v18[12] = v21;
  struct StateT * v23 = slot_2(v15);
  return v23;
}

struct StateT * slot_8(struct StateT * v135) {
  int v136 = v135->timer;
  int v147 = v136 + 1;
  v135->timer = v147;
  int * v138 = v135->regs;
  int v139 = v138[10];
  int v140 = v138[11];
  bool v151 = !(v139 == v140);
  struct StateT * v145;
  if (v151) {
    struct StateT * v141 = slot_15(v135);
    v145 = v141;
  } else {
    struct StateT * v143 = slot_9(v135);
    v145 = v143;
  }
  return v145;
}

struct StateT * slot_4(struct StateT * v74) {
  int v75 = v74->timer;
  int v81 = v75 + 1;
  v74->timer = v81;
  int * v77 = v74->regs;
  v77[12] = 0;
  struct StateT * v79 = slot_5(v74);
  return v79;
}

struct StateT * slot_13(struct StateT * v220) {
  int v221 = v220->timer;
  int v229 = v221 + 1;
  v220->timer = v229;
  int * v223 = v220->regs;
  int v224 = v223[12];
  int v225 = v223[10];
  int v233 = v224 & v225;
  v223[10] = v233;
  struct StateT * v227 = slot_14(v220);
  return v227;
}

struct StateT * slot_15(struct StateT * v55) {
  int v56 = v55->timer;
  int v59 = v56 + 1;
  v55->timer = v59;
  return v55;
}

struct StateT * slot_9(struct StateT * v157) {
  int v158 = v157->timer;
  int v164 = v158 + 1;
  v157->timer = v164;
  int * v160 = v157->regs;
  v160[10] = 0;
  struct StateT * v162 = slot_10(v157);
  return v162;
}

struct StateT * slot_11(struct StateT * v183) {
  int v184 = v183->timer;
  int v193 = v184 + 1;
  v183->timer = v193;
  int * v186 = v183->regs;
  int v187 = v186[10];
  int * v188 = v183->mem;
  int v197 = (int)((unsigned int)(v187 + 4) >> 2);
  int v189 = v188[v197];
  v186[10] = v189;
  struct StateT * v191 = slot_12(v183);
  return v191;
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
  int k = bounded(0, 20);
  s1.regs[11] = k;
  s2.regs[11] = k;
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