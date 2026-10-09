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

struct StateT * slot_12(struct StateT * v287);
struct StateT * slot_6(struct StateT * v159);
struct StateT * slot_16(struct StateT * v354);
struct StateT * slot_23(struct StateT * v209);
struct StateT * slot_5(struct StateT * v126);
struct StateT * slot_2(struct StateT * v33);
struct StateT * slot_7(struct StateT * v191);
struct StateT * slot_21(struct StateT * v140);
struct StateT * slot_3(struct StateT * v68);
struct StateT * slot_10(struct StateT * v260);
struct StateT * slot_1(struct StateT * v15);
struct StateT * slot_19(struct StateT * v82);
struct StateT * slot_13(struct StateT * v301);
struct StateT * slot_24(struct StateT * v241);
struct StateT * slot_0(struct StateT * v2);
struct StateT * slot_14(struct StateT * v317);
struct StateT * slot_17(struct StateT * v370);
struct StateT * slot_20(struct StateT * v108);
struct StateT * snippet(struct StateT * v0);
struct StateT * slot_8(struct StateT * v228);
struct StateT * slot_4(struct StateT * v95);
struct StateT * slot_15(struct StateT * v335);
struct StateT * slot_18(struct StateT * v55);
struct StateT * slot_9(struct StateT * v246);
struct StateT * slot_22(struct StateT * v175);
struct StateT * slot_11(struct StateT * v273);
struct StateT * slot_12(struct StateT * v287) {
  int v288 = v287->timer;
  int v295 = v288 + 1;
  v287->timer = v295;
  int * v290 = v287->regs;
  int v291 = v290[10];
  int v298 = (int)((unsigned int)v291 >> 26);
  v290[10] = v298;
  struct StateT * v293 = slot_13(v287);
  return v293;
}

struct StateT * slot_6(struct StateT * v159) {
  int v160 = v159->timer;
  int v168 = v160 + 1;
  v159->timer = v168;
  int * v162 = v159->regs;
  int v163 = v162[11];
  int v164 = v162[10];
  int v172 = v163 + v164;
  v162[10] = v172;
  struct StateT * v166 = slot_7(v159);
  return v166;
}

struct StateT * slot_16(struct StateT * v354) {
  int v355 = v354->timer;
  int v363 = v355 + 1;
  v354->timer = v363;
  int * v357 = v354->regs;
  int v358 = v357[11];
  int v359 = v357[10];
  int v367 = v358 & v359;
  v357[10] = v367;
  struct StateT * v361 = slot_17(v354);
  return v361;
}

struct StateT * slot_23(struct StateT * v209) {
  int v210 = v209->timer;
  int v219 = v210 + 1;
  v209->timer = v219;
  int * v212 = v209->regs;
  int v213 = v212[11];
  int v214 = v212[10];
  int * v215 = v209->mem;
  int v224 = (int)((unsigned int)(v213 + 68) >> 2);
  v215[v224] = v214;
  struct StateT * v217 = slot_24(v209);
  return v217;
}

struct StateT * slot_5(struct StateT * v126) {
  int v127 = v126->timer;
  int v134 = v127 + 1;
  v126->timer = v134;
  int * v129 = v126->regs;
  int v130 = v129[11];
  int v137 = v130 + 72;
  v129[11] = v137;
  struct StateT * v132 = slot_6(v126);
  return v132;
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

struct StateT * slot_7(struct StateT * v191) {
  int v192 = v191->timer;
  int v201 = v192 + 1;
  v191->timer = v201;
  int * v194 = v191->regs;
  int v195 = v194[10];
  int * v196 = v191->mem;
  int v205 = (int)((unsigned int)v195 >> 2);
  int v197 = v196[v205];
  v194[10] = v197;
  struct StateT * v199 = slot_8(v191);
  return v199;
}

struct StateT * slot_21(struct StateT * v140) {
  int v141 = v140->timer;
  int v150 = v141 + 1;
  v140->timer = v150;
  int * v143 = v140->regs;
  int v144 = v143[11];
  int * v145 = v140->mem;
  int v154 = (int)((unsigned int)(v144 + 68) >> 2);
  int v146 = v145[v154];
  v143[12] = v146;
  struct StateT * v148 = slot_22(v140);
  return v148;
}

struct StateT * slot_3(struct StateT * v68) {
  int v69 = v68->timer;
  int v76 = v69 + 1;
  v68->timer = v76;
  int * v71 = v68->regs;
  int v72 = v71[10];
  int v79 = v72 << 2;
  v71[10] = v79;
  struct StateT * v74 = slot_4(v68);
  return v74;
}

struct StateT * slot_10(struct StateT * v260) {
  int v261 = v260->timer;
  int v267 = v261 + 1;
  v260->timer = v267;
  int * v263 = v260->regs;
  v263[12] = 0;
  struct StateT * v265 = slot_11(v260);
  return v265;
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

struct StateT * slot_19(struct StateT * v82) {
  int v83 = v82->timer;
  int v89 = v83 + 1;
  v82->timer = v89;
  int * v85 = v82->regs;
  v85[11] = 0;
  struct StateT * v87 = slot_20(v82);
  return v87;
}

struct StateT * slot_13(struct StateT * v301) {
  int v302 = v301->timer;
  int v310 = v302 + 1;
  v301->timer = v310;
  int * v304 = v301->regs;
  int v305 = v304[11];
  int v306 = v304[10];
  int v314 = v305 + v306;
  v304[10] = v314;
  struct StateT * v308 = slot_14(v301);
  return v308;
}

struct StateT * slot_24(struct StateT * v241) {
  int v242 = v241->timer;
  int v245 = v242 + 1;
  v241->timer = v245;
  return v241;
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

struct StateT * slot_14(struct StateT * v317) {
  int v318 = v317->timer;
  int v327 = v318 + 1;
  v317->timer = v327;
  int * v320 = v317->regs;
  int v321 = v320[10];
  int * v322 = v317->mem;
  int v331 = (int)((unsigned int)v321 >> 2);
  int v323 = v322[v331];
  v320[10] = v323;
  struct StateT * v325 = slot_15(v317);
  return v325;
}

struct StateT * slot_17(struct StateT * v370) {
  int v371 = v370->timer;
  int v380 = v371 + 1;
  v370->timer = v380;
  int * v373 = v370->regs;
  int v374 = v373[12];
  int v375 = v373[10];
  int * v376 = v370->mem;
  int v385 = (int)((unsigned int)(v374 + 68) >> 2);
  v376[v385] = v375;
  struct StateT * v378 = slot_18(v370);
  return v378;
}

struct StateT * slot_20(struct StateT * v108) {
  int v109 = v108->timer;
  int v118 = v109 + 1;
  v108->timer = v118;
  int * v111 = v108->regs;
  int v112 = v111[10];
  int * v113 = v108->mem;
  int v122 = (int)((unsigned int)(v112 + 4) >> 2);
  int v114 = v113[v122];
  v111[10] = v114;
  struct StateT * v116 = slot_21(v108);
  return v116;
}

struct StateT * snippet(struct StateT * v0) {
  struct StateT * v1 = slot_0(v0);
  return v1;
}

struct StateT * slot_8(struct StateT * v228) {
  int v229 = v228->timer;
  int v235 = v229 + 1;
  v228->timer = v235;
  int * v231 = v228->regs;
  v231[11] = 0;
  struct StateT * v233 = slot_9(v228);
  return v233;
}

struct StateT * slot_4(struct StateT * v95) {
  int v96 = v95->timer;
  int v102 = v96 + 1;
  v95->timer = v102;
  int * v98 = v95->regs;
  v98[11] = 0;
  struct StateT * v100 = slot_5(v95);
  return v100;
}

struct StateT * slot_15(struct StateT * v335) {
  int v336 = v335->timer;
  int v345 = v336 + 1;
  v335->timer = v345;
  int * v338 = v335->regs;
  int v339 = v338[12];
  int * v340 = v335->mem;
  int v349 = (int)((unsigned int)(v339 + 68) >> 2);
  int v341 = v340[v349];
  v338[11] = v341;
  struct StateT * v343 = slot_16(v335);
  return v343;
}

struct StateT * slot_18(struct StateT * v55) {
  int v56 = v55->timer;
  int v62 = v56 + 1;
  v55->timer = v62;
  int * v58 = v55->regs;
  v58[10] = 0;
  struct StateT * v60 = slot_19(v55);
  return v60;
}

struct StateT * slot_9(struct StateT * v246) {
  int v247 = v246->timer;
  int v254 = v247 + 1;
  v246->timer = v254;
  int * v249 = v246->regs;
  int v250 = v249[11];
  int v257 = v250 + 4;
  v249[11] = v257;
  struct StateT * v252 = slot_10(v246);
  return v252;
}

struct StateT * slot_22(struct StateT * v175) {
  int v176 = v175->timer;
  int v184 = v176 + 1;
  v175->timer = v184;
  int * v178 = v175->regs;
  int v179 = v178[12];
  int v180 = v178[10];
  int v188 = v179 & v180;
  v178[10] = v188;
  struct StateT * v182 = slot_23(v175);
  return v182;
}

struct StateT * slot_11(struct StateT * v273) {
  int v274 = v273->timer;
  int v281 = v274 + 1;
  v273->timer = v281;
  int * v276 = v273->regs;
  int v277 = v276[10];
  int v284 = v277 << 29;
  v276[10] = v284;
  struct StateT * v279 = slot_12(v273);
  return v279;
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