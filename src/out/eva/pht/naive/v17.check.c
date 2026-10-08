// verify: leak (Eva should report untainted_timer: unknown) [unroll 65]
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

struct StateT * slot_12(struct StateT * v189);
struct StateT * slot_14(struct StateT * v219);
struct StateT * slot_6(struct StateT * v90);
struct StateT * slot_16(struct StateT * v256);
struct StateT * slot_5(struct StateT * v72);
struct StateT * slot_17(struct StateT * v272);
struct StateT * slot_2(struct StateT * v29);
struct StateT * slot_7(struct StateT * v108);
struct StateT * slot_3(struct StateT * v43);
struct StateT * snippet(struct StateT * v0);
struct StateT * slot_10(struct StateT * v162);
struct StateT * slot_1(struct StateT * v16);
struct StateT * slot_8(struct StateT * v135);
struct StateT * slot_4(struct StateT * v59);
struct StateT * slot_13(struct StateT * v203);
struct StateT * slot_15(struct StateT * v237);
struct StateT * slot_18(struct StateT * v130);
struct StateT * slot_9(struct StateT * v149);
struct StateT * slot_11(struct StateT * v176);
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

struct StateT * slot_6(struct StateT * v90) {
  int v91 = v90->timer;
  int v100 = v91 + 1;
  v90->timer = v100;
  int * v93 = v90->regs;
  int v94 = v93[11];
  int * v95 = v90->mem;
  int v104 = (int)((unsigned int)v94 >> 2);
  int v96 = v95[v104];
  v93[11] = v96;
  struct StateT * v98 = slot_7(v90);
  return v98;
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

struct StateT * slot_5(struct StateT * v72) {
  int v73 = v72->timer;
  int v82 = v73 + 1;
  v72->timer = v82;
  int * v75 = v72->regs;
  int v76 = v75[10];
  int * v77 = v72->mem;
  int v86 = (int)((unsigned int)v76 >> 2);
  int v78 = v77[v86];
  v75[10] = v78;
  struct StateT * v80 = slot_6(v72);
  return v80;
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

struct StateT * slot_2(struct StateT * v29) {
  int v30 = v29->timer;
  int v37 = v30 + 1;
  v29->timer = v37;
  int * v32 = v29->regs;
  int v33 = v32[11];
  int v40 = v33 + 72;
  v32[11] = v40;
  struct StateT * v35 = slot_3(v29);
  return v35;
}

struct StateT * slot_7(struct StateT * v108) {
  int v109 = v108->timer;
  int v120 = v109 + 1;
  v108->timer = v120;
  int * v111 = v108->regs;
  int v112 = v111[10];
  int v113 = v111[11];
  bool v124 = (v112 ^ -2147483648) >= (v113 ^ -2147483648);
  struct StateT * v118;
  if (v124) {
    struct StateT * v114 = slot_18(v108);
    v118 = v114;
  } else {
    struct StateT * v116 = slot_8(v108);
    v118 = v116;
  }
  return v118;
}

struct StateT * slot_3(struct StateT * v43) {
  int v44 = v43->timer;
  int v52 = v44 + 1;
  v43->timer = v52;
  int * v46 = v43->regs;
  int v47 = v46[11];
  int v48 = v46[10];
  int v56 = v47 + v48;
  v46[10] = v56;
  struct StateT * v50 = slot_4(v43);
  return v50;
}

struct StateT * snippet(struct StateT * v0) {
  struct StateT * v1 = slot_0(v0);
  return v1;
}

struct StateT * slot_10(struct StateT * v162) {
  int v163 = v162->timer;
  int v170 = v163 + 1;
  v162->timer = v170;
  int * v165 = v162->regs;
  int v166 = v165[11];
  int v173 = v166 + 4;
  v165[11] = v173;
  struct StateT * v168 = slot_11(v162);
  return v168;
}

struct StateT * slot_1(struct StateT * v16) {
  int v17 = v16->timer;
  int v23 = v17 + 1;
  v16->timer = v23;
  int * v19 = v16->regs;
  v19[11] = 0;
  struct StateT * v21 = slot_2(v16);
  return v21;
}

struct StateT * slot_8(struct StateT * v135) {
  int v136 = v135->timer;
  int v143 = v136 + 1;
  v135->timer = v143;
  int * v138 = v135->regs;
  int v139 = v138[10];
  int v146 = v139 << 29;
  v138[10] = v146;
  struct StateT * v141 = slot_9(v135);
  return v141;
}

struct StateT * slot_4(struct StateT * v59) {
  int v60 = v59->timer;
  int v66 = v60 + 1;
  v59->timer = v66;
  int * v62 = v59->regs;
  v62[11] = 0;
  struct StateT * v64 = slot_5(v59);
  return v64;
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

struct StateT * slot_18(struct StateT * v130) {
  int v131 = v130->timer;
  int v134 = v131 + 1;
  v130->timer = v134;
  return v130;
}

struct StateT * slot_9(struct StateT * v149) {
  int v150 = v149->timer;
  int v156 = v150 + 1;
  v149->timer = v156;
  int * v152 = v149->regs;
  v152[11] = 0;
  struct StateT * v154 = slot_10(v149);
  return v154;
}

struct StateT * slot_11(struct StateT * v176) {
  int v177 = v176->timer;
  int v183 = v177 + 1;
  v176->timer = v183;
  int * v179 = v176->regs;
  v179[12] = 0;
  struct StateT * v181 = slot_12(v176);
  return v181;
}

struct StateT * slot_0(struct StateT * v2) {
  int v3 = v2->timer;
  int v10 = v3 + 1;
  v2->timer = v10;
  int * v5 = v2->regs;
  int v6 = v5[10];
  int v13 = v6 << 2;
  v5[10] = v13;
  struct StateT * v8 = slot_1(v2);
  return v8;
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