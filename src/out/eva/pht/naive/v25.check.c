// verify: clean (Eva should report untainted_timer: Valid) [unroll 65]
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

struct StateT * slot_12(struct StateT * v120);
struct StateT * slot_6(struct StateT * v192);
struct StateT * slot_16(struct StateT * v236);
struct StateT * slot_5(struct StateT * v166);
struct StateT * slot_2(struct StateT * v62);
struct StateT * slot_7(struct StateT * v220);
struct StateT * slot_21(struct StateT * v327);
struct StateT * slot_3(struct StateT * v98);
struct StateT * slot_10(struct StateT * v48);
struct StateT * slot_1(struct StateT * v35);
struct StateT * slot_19(struct StateT * v292);
struct StateT * slot_13(struct StateT * v152);
struct StateT * slot_0(struct StateT * v2);
struct StateT * slot_14(struct StateT * v179);
struct StateT * slot_17(struct StateT * v258);
struct StateT * slot_20(struct StateT * v311);
struct StateT * snippet(struct StateT * v0);
struct StateT * slot_8(struct StateT * v250);
struct StateT * slot_4(struct StateT * v138);
struct StateT * slot_15(struct StateT * v206);
struct StateT * slot_18(struct StateT * v274);
struct StateT * slot_9(struct StateT * v22);
struct StateT * slot_22(struct StateT * v133);
struct StateT * slot_11(struct StateT * v80);
struct StateT * slot_12(struct StateT * v120) {
  int v121 = v120->timer;
  int v127 = v121 + 1;
  v120->timer = v127;
  int * v123 = v120->regs;
  v123[11] = 0;
  struct StateT * v125 = slot_13(v120);
  return v125;
}

struct StateT * slot_6(struct StateT * v192) {
  int v193 = v192->timer;
  int v200 = v193 + 1;
  v192->timer = v200;
  int * v195 = v192->regs;
  int v196 = v195[11];
  int v203 = v196 + 72;
  v195[11] = v203;
  struct StateT * v198 = slot_7(v192);
  return v198;
}

struct StateT * slot_16(struct StateT * v236) {
  int v237 = v236->timer;
  int v244 = v237 + 1;
  v236->timer = v244;
  int * v239 = v236->regs;
  int v240 = v239[10];
  int v247 = (int)((unsigned int)v240 >> 26);
  v239[10] = v247;
  struct StateT * v242 = slot_17(v236);
  return v242;
}

struct StateT * slot_5(struct StateT * v166) {
  int v167 = v166->timer;
  int v173 = v167 + 1;
  v166->timer = v173;
  int * v169 = v166->regs;
  v169[11] = 0;
  struct StateT * v171 = slot_6(v166);
  return v171;
}

struct StateT * slot_2(struct StateT * v62) {
  int v63 = v62->timer;
  int v72 = v63 + 1;
  v62->timer = v72;
  int * v65 = v62->regs;
  int v66 = v65[11];
  int * v67 = v62->mem;
  int v76 = (int)((unsigned int)v66 >> 2);
  int v68 = v67[v76];
  v65[11] = v68;
  struct StateT * v70 = slot_3(v62);
  return v70;
}

struct StateT * slot_7(struct StateT * v220) {
  int v221 = v220->timer;
  int v229 = v221 + 1;
  v220->timer = v229;
  int * v223 = v220->regs;
  int v224 = v223[11];
  int v225 = v223[10];
  int v233 = v224 + v225;
  v223[10] = v233;
  struct StateT * v227 = slot_8(v220);
  return v227;
}

struct StateT * slot_21(struct StateT * v327) {
  int v328 = v327->timer;
  int v337 = v328 + 1;
  v327->timer = v337;
  int * v330 = v327->regs;
  int v331 = v330[12];
  int v332 = v330[10];
  int * v333 = v327->mem;
  int v342 = (int)((unsigned int)(v331 + 68) >> 2);
  v333[v342] = v332;
  struct StateT * v335 = slot_22(v327);
  return v335;
}

struct StateT * slot_3(struct StateT * v98) {
  int v99 = v98->timer;
  int v110 = v99 + 1;
  v98->timer = v110;
  int * v101 = v98->regs;
  int v102 = v101[10];
  int v103 = v101[11];
  bool v114 = (v102 ^ -2147483648) >= (v103 ^ -2147483648);
  struct StateT * v108;
  if (v114) {
    struct StateT * v104 = slot_22(v98);
    v108 = v104;
  } else {
    struct StateT * v106 = slot_4(v98);
    v108 = v106;
  }
  return v108;
}

struct StateT * slot_10(struct StateT * v48) {
  int v49 = v48->timer;
  int v56 = v49 + 1;
  v48->timer = v56;
  int * v51 = v48->regs;
  int v52 = v51[10];
  int v59 = v52 + 72;
  v51[10] = v59;
  struct StateT * v54 = slot_11(v48);
  return v54;
}

struct StateT * slot_1(struct StateT * v35) {
  int v36 = v35->timer;
  int v42 = v36 + 1;
  v35->timer = v42;
  int * v38 = v35->regs;
  v38[11] = 0;
  struct StateT * v40 = slot_2(v35);
  return v40;
}

struct StateT * slot_19(struct StateT * v292) {
  int v293 = v292->timer;
  int v302 = v293 + 1;
  v292->timer = v302;
  int * v295 = v292->regs;
  int v296 = v295[12];
  int * v297 = v292->mem;
  int v306 = (int)((unsigned int)(v296 + 68) >> 2);
  int v298 = v297[v306];
  v295[11] = v298;
  struct StateT * v300 = slot_20(v292);
  return v300;
}

struct StateT * slot_13(struct StateT * v152) {
  int v153 = v152->timer;
  int v160 = v153 + 1;
  v152->timer = v160;
  int * v155 = v152->regs;
  int v156 = v155[11];
  int v163 = v156 + 4;
  v155[11] = v163;
  struct StateT * v158 = slot_14(v152);
  return v158;
}

struct StateT * slot_0(struct StateT * v2) {
  int v3 = v2->timer;
  int v13 = v3 + 1;
  v2->timer = v13;
  int * v5 = v2->regs;
  int v6 = v5[10];
  bool v16 = v6 == 0;
  struct StateT * v11;
  if (v16) {
    struct StateT * v7 = slot_9(v2);
    v11 = v7;
  } else {
    struct StateT * v9 = slot_1(v2);
    v11 = v9;
  }
  return v11;
}

struct StateT * slot_14(struct StateT * v179) {
  int v180 = v179->timer;
  int v186 = v180 + 1;
  v179->timer = v186;
  int * v182 = v179->regs;
  v182[12] = 0;
  struct StateT * v184 = slot_15(v179);
  return v184;
}

struct StateT * slot_17(struct StateT * v258) {
  int v259 = v258->timer;
  int v267 = v259 + 1;
  v258->timer = v267;
  int * v261 = v258->regs;
  int v262 = v261[11];
  int v263 = v261[10];
  int v271 = v262 + v263;
  v261[10] = v271;
  struct StateT * v265 = slot_18(v258);
  return v265;
}

struct StateT * slot_20(struct StateT * v311) {
  int v312 = v311->timer;
  int v320 = v312 + 1;
  v311->timer = v320;
  int * v314 = v311->regs;
  int v315 = v314[11];
  int v316 = v314[10];
  int v324 = v315 & v316;
  v314[10] = v324;
  struct StateT * v318 = slot_21(v311);
  return v318;
}

struct StateT * snippet(struct StateT * v0) {
  struct StateT * v1 = slot_0(v0);
  return v1;
}

struct StateT * slot_8(struct StateT * v250) {
  int v251 = v250->timer;
  int v255 = v251 + 1;
  v250->timer = v255;
  struct StateT * v253 = slot_11(v250);
  return v253;
}

struct StateT * slot_4(struct StateT * v138) {
  int v139 = v138->timer;
  int v146 = v139 + 1;
  v138->timer = v146;
  int * v141 = v138->regs;
  int v142 = v141[10];
  int v149 = v142 << 2;
  v141[10] = v149;
  struct StateT * v144 = slot_5(v138);
  return v144;
}

struct StateT * slot_15(struct StateT * v206) {
  int v207 = v206->timer;
  int v214 = v207 + 1;
  v206->timer = v214;
  int * v209 = v206->regs;
  int v210 = v209[10];
  int v217 = v210 << 29;
  v209[10] = v217;
  struct StateT * v212 = slot_16(v206);
  return v212;
}

struct StateT * slot_18(struct StateT * v274) {
  int v275 = v274->timer;
  int v284 = v275 + 1;
  v274->timer = v284;
  int * v277 = v274->regs;
  int v278 = v277[10];
  int * v279 = v274->mem;
  int v288 = (int)((unsigned int)v278 >> 2);
  int v280 = v279[v288];
  v277[10] = v280;
  struct StateT * v282 = slot_19(v274);
  return v282;
}

struct StateT * slot_9(struct StateT * v22) {
  int v23 = v22->timer;
  int v29 = v23 + 1;
  v22->timer = v29;
  int * v25 = v22->regs;
  v25[10] = 0;
  struct StateT * v27 = slot_10(v22);
  return v27;
}

struct StateT * slot_22(struct StateT * v133) {
  int v134 = v133->timer;
  int v137 = v134 + 1;
  v133->timer = v137;
  return v133;
}

struct StateT * slot_11(struct StateT * v80) {
  int v81 = v80->timer;
  int v90 = v81 + 1;
  v80->timer = v90;
  int * v83 = v80->regs;
  int v84 = v83[10];
  int * v85 = v80->mem;
  int v94 = (int)((unsigned int)v84 >> 2);
  int v86 = v85[v94];
  v83[10] = v86;
  struct StateT * v88 = slot_12(v80);
  return v88;
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