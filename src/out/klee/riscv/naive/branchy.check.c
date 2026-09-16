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

struct StateT * slot_12(struct StateT * v212);
struct StateT * slot_6(struct StateT * v101);
struct StateT * slot_16(struct StateT * v281);
struct StateT * slot_5(struct StateT * v85);
struct StateT * slot_2(struct StateT * v32);
struct StateT * slot_7(struct StateT * v122);
struct StateT * slot_21(struct StateT * v371);
struct StateT * slot_3(struct StateT * v52);
struct StateT * slot_10(struct StateT * v175);
struct StateT * slot_1(struct StateT * v15);
struct StateT * slot_19(struct StateT * v339);
struct StateT * slot_13(struct StateT * v232);
struct StateT * slot_0(struct StateT * v2);
struct StateT * slot_14(struct StateT * v249);
struct StateT * slot_17(struct StateT * v302);
struct StateT * slot_20(struct StateT * v355);
struct StateT * snippet(struct StateT * v0);
struct StateT * slot_8(struct StateT * v142);
struct StateT * slot_4(struct StateT * v69);
struct StateT * slot_15(struct StateT * v265);
struct StateT * slot_18(struct StateT * v322);
struct StateT * slot_9(struct StateT * v159);
struct StateT * slot_22(struct StateT * v392);
struct StateT * slot_11(struct StateT * v191);
struct StateT * slot_12(struct StateT * v212) {
  int v213 = v212->timer;
  int v223 = v213 + 1;
  v212->timer = v223;
  int * v215 = v212->regs;
  int v216 = v215[5];
  int * v217 = v212->regs;
  int v218 = v217[7];
  int * v219 = v212->regs;
  int v229 = v216 ^ v218;
  v219[5] = v229;
  struct StateT * v221 = slot_13(v212);
  return v221;
}

struct StateT * slot_6(struct StateT * v101) {
  int v102 = v101->timer;
  int v112 = v102 + 1;
  v101->timer = v112;
  int * v104 = v101->regs;
  int v105 = v104[6];
  int * v106 = v101->mem;
  int v116 = (int)((unsigned int)v105 >> 2);
  int v107 = v106[v116];
  int * v108 = v101->regs;
  v108[7] = v107;
  struct StateT * v110 = slot_7(v101);
  return v110;
}

struct StateT * slot_16(struct StateT * v281) {
  int v282 = v281->timer;
  int v292 = v282 + 1;
  v281->timer = v292;
  int * v284 = v281->regs;
  int v285 = v284[6];
  int * v286 = v281->mem;
  int v296 = (int)((unsigned int)v285 >> 2);
  int v287 = v286[v296];
  int * v288 = v281->regs;
  v288[7] = v287;
  struct StateT * v290 = slot_17(v281);
  return v290;
}

struct StateT * slot_5(struct StateT * v85) {
  int v86 = v85->timer;
  int v94 = v86 + 1;
  v85->timer = v94;
  int * v88 = v85->regs;
  int v89 = v88[6];
  int * v90 = v85->regs;
  int v98 = v89 << 2;
  v90[6] = v98;
  struct StateT * v92 = slot_6(v85);
  return v92;
}

struct StateT * slot_2(struct StateT * v32) {
  int v33 = v32->timer;
  int v43 = v33 + 1;
  v32->timer = v43;
  int * v35 = v32->regs;
  int v36 = v35[5];
  int * v37 = v32->regs;
  int v38 = v37[9];
  int * v39 = v32->regs;
  int v49 = v36 ^ v38;
  v39[5] = v49;
  struct StateT * v41 = slot_3(v32);
  return v41;
}

struct StateT * slot_7(struct StateT * v122) {
  int v123 = v122->timer;
  int v133 = v123 + 1;
  v122->timer = v133;
  int * v125 = v122->regs;
  int v126 = v125[5];
  int * v127 = v122->regs;
  int v128 = v127[7];
  int * v129 = v122->regs;
  int v139 = v126 ^ v128;
  v129[5] = v139;
  struct StateT * v131 = slot_8(v122);
  return v131;
}

struct StateT * slot_21(struct StateT * v371) {
  int v372 = v371->timer;
  int v382 = v372 + 1;
  v371->timer = v382;
  int * v374 = v371->regs;
  int v375 = v374[6];
  int * v376 = v371->mem;
  int v386 = (int)((unsigned int)v375 >> 2);
  int v377 = v376[v386];
  int * v378 = v371->regs;
  v378[7] = v377;
  struct StateT * v380 = slot_22(v371);
  return v380;
}

struct StateT * slot_3(struct StateT * v52) {
  int v53 = v52->timer;
  int v61 = v53 + 1;
  v52->timer = v61;
  int * v55 = v52->regs;
  int v56 = v55[10];
  int * v57 = v52->regs;
  v57[6] = v56;
  struct StateT * v59 = slot_4(v52);
  return v59;
}

struct StateT * slot_10(struct StateT * v175) {
  int v176 = v175->timer;
  int v184 = v176 + 1;
  v175->timer = v184;
  int * v178 = v175->regs;
  int v179 = v178[6];
  int * v180 = v175->regs;
  int v188 = v179 << 2;
  v180[6] = v188;
  struct StateT * v182 = slot_11(v175);
  return v182;
}

struct StateT * slot_1(struct StateT * v15) {
  int v16 = v15->timer;
  int v24 = v16 + 1;
  v15->timer = v24;
  int * v18 = v15->mem;
  int v19 = v18[20];
  int * v20 = v15->regs;
  v20[9] = v19;
  struct StateT * v22 = slot_2(v15);
  return v22;
}

struct StateT * slot_19(struct StateT * v339) {
  int v340 = v339->timer;
  int v348 = v340 + 1;
  v339->timer = v348;
  int * v342 = v339->regs;
  int v343 = v342[6];
  int * v344 = v339->regs;
  int v352 = v343 & 63;
  v344[6] = v352;
  struct StateT * v346 = slot_20(v339);
  return v346;
}

struct StateT * slot_13(struct StateT * v232) {
  int v233 = v232->timer;
  int v241 = v233 + 1;
  v232->timer = v241;
  int * v235 = v232->regs;
  int v236 = v235[10];
  int * v237 = v232->regs;
  int v246 = (int)((unsigned int)v236 >> 16);
  v237[6] = v246;
  struct StateT * v239 = slot_14(v232);
  return v239;
}

struct StateT * slot_0(struct StateT * v2) {
  int v3 = v2->timer;
  int v9 = v3 + 1;
  v2->timer = v9;
  int * v5 = v2->regs;
  v5[5] = 0;
  struct StateT * v7 = slot_1(v2);
  return v7;
}

struct StateT * slot_14(struct StateT * v249) {
  int v250 = v249->timer;
  int v258 = v250 + 1;
  v249->timer = v258;
  int * v252 = v249->regs;
  int v253 = v252[6];
  int * v254 = v249->regs;
  int v262 = v253 & 63;
  v254[6] = v262;
  struct StateT * v256 = slot_15(v249);
  return v256;
}

struct StateT * slot_17(struct StateT * v302) {
  int v303 = v302->timer;
  int v313 = v303 + 1;
  v302->timer = v313;
  int * v305 = v302->regs;
  int v306 = v305[5];
  int * v307 = v302->regs;
  int v308 = v307[7];
  int * v309 = v302->regs;
  int v319 = v306 ^ v308;
  v309[5] = v319;
  struct StateT * v311 = slot_18(v302);
  return v311;
}

struct StateT * slot_20(struct StateT * v355) {
  int v356 = v355->timer;
  int v364 = v356 + 1;
  v355->timer = v364;
  int * v358 = v355->regs;
  int v359 = v358[6];
  int * v360 = v355->regs;
  int v368 = v359 << 2;
  v360[6] = v368;
  struct StateT * v362 = slot_21(v355);
  return v362;
}

struct StateT * snippet(struct StateT * v0) {
  struct StateT * v1 = slot_0(v0);
  return v1;
}

struct StateT * slot_8(struct StateT * v142) {
  int v143 = v142->timer;
  int v151 = v143 + 1;
  v142->timer = v151;
  int * v145 = v142->regs;
  int v146 = v145[10];
  int * v147 = v142->regs;
  int v156 = (int)((unsigned int)v146 >> 8);
  v147[6] = v156;
  struct StateT * v149 = slot_9(v142);
  return v149;
}

struct StateT * slot_4(struct StateT * v69) {
  int v70 = v69->timer;
  int v78 = v70 + 1;
  v69->timer = v78;
  int * v72 = v69->regs;
  int v73 = v72[6];
  int * v74 = v69->regs;
  int v82 = v73 & 63;
  v74[6] = v82;
  struct StateT * v76 = slot_5(v69);
  return v76;
}

struct StateT * slot_15(struct StateT * v265) {
  int v266 = v265->timer;
  int v274 = v266 + 1;
  v265->timer = v274;
  int * v268 = v265->regs;
  int v269 = v268[6];
  int * v270 = v265->regs;
  int v278 = v269 << 2;
  v270[6] = v278;
  struct StateT * v272 = slot_16(v265);
  return v272;
}

struct StateT * slot_18(struct StateT * v322) {
  int v323 = v322->timer;
  int v331 = v323 + 1;
  v322->timer = v331;
  int * v325 = v322->regs;
  int v326 = v325[10];
  int * v327 = v322->regs;
  int v336 = (int)((unsigned int)v326 >> 24);
  v327[6] = v336;
  struct StateT * v329 = slot_19(v322);
  return v329;
}

struct StateT * slot_9(struct StateT * v159) {
  int v160 = v159->timer;
  int v168 = v160 + 1;
  v159->timer = v168;
  int * v162 = v159->regs;
  int v163 = v162[6];
  int * v164 = v159->regs;
  int v172 = v163 & 63;
  v164[6] = v172;
  struct StateT * v166 = slot_10(v159);
  return v166;
}

struct StateT * slot_22(struct StateT * v392) {
  int v393 = v392->timer;
  int v402 = v393 + 1;
  v392->timer = v402;
  int * v395 = v392->regs;
  int v396 = v395[5];
  int * v397 = v392->regs;
  int v398 = v397[7];
  int * v399 = v392->regs;
  int v408 = v396 ^ v398;
  v399[5] = v408;
  return v392;
}

struct StateT * slot_11(struct StateT * v191) {
  int v192 = v191->timer;
  int v202 = v192 + 1;
  v191->timer = v202;
  int * v194 = v191->regs;
  int v195 = v194[6];
  int * v196 = v191->mem;
  int v206 = (int)((unsigned int)v195 >> 2);
  int v197 = v196[v206];
  int * v198 = v191->regs;
  v198[7] = v197;
  struct StateT * v200 = slot_12(v191);
  return v200;
}



/*****************************************
End of C Generated Code
*******************************************/

void init(struct StateT *s) {
  for (int i=0; i<NUM_REGS; i++) {
    s->regs[i] = 0;
    s->saved_regs[i] = 0;
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
  
  // the indices, public: one draw into both states
  int i10 = bounded(0, 1073741823);
  s1.regs[10] = i10;
  s2.regs[10] = i10;
  
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