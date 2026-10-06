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

struct StateT2 {
  struct StateT * a;
  struct StateT * b;
};

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

void squared_assert(bool);
void squared_assume(bool);

struct StateT2 * slot_12(struct StateT2 * v293);
struct StateT2 * slot_14(struct StateT2 * v389);
struct StateT2 * slot_6(struct StateT2 * v188);
struct StateT2 * slot_5(struct StateT2 * v431);
struct StateT2 * slot_2(struct StateT2 * v86);
struct StateT2 * slot_3(struct StateT2 * v122);
struct StateT2 * snippet(struct StateT2 * v0);
struct StateT2 * slot_10(struct StateT2 * v247);
struct StateT2 * slot_1(struct StateT2 * v38);
struct StateT2 * slot_4(struct StateT2 * v316);
struct StateT2 * slot_13(struct StateT2 * v375);
struct StateT2 * slot_9(struct StateT2 * v224);
struct StateT2 * slot_11(struct StateT2 * v270);
struct StateT2 * slot_0(struct StateT2 * v2);
struct StateT2 * slot_12(struct StateT2 * v293) {
  struct StateT * v294 = v293->b;
  int v295 = v294->timer;
  bool v307 = v295 == v295;
  squared_assert(v307);
  squared_assume(v307);
  struct StateT * v298 = v293->b;
  int v299 = v298->timer;
  int v309 = v299 + 1;
  v298->timer = v309;
  struct StateT * v301 = v293->b;
  int * v302 = v301->regs;
  v302[18] = 2;
  struct StateT2 * v304 = slot_14(v293);
  return v304;
}

struct StateT2 * slot_14(struct StateT2 * v389) {
  struct StateT * v390 = v389->b;
  int v391 = v390->timer;
  bool v400 = v391 == v391;
  squared_assert(v400);
  squared_assume(v400);
  struct StateT * v394 = v389->b;
  int v395 = v394->timer;
  int v402 = v395 + 1;
  v394->timer = v402;
  return v389;
}

struct StateT2 * slot_6(struct StateT2 * v188) {
  struct StateT * v189 = v188->a;
  int v190 = v189->timer;
  struct StateT * v191 = v188->b;
  int v192 = v191->timer;
  bool v211 = v190 == v192;
  squared_assert(v211);
  squared_assume(v211);
  struct StateT * v195 = v188->a;
  int v196 = v195->timer;
  int v213 = v196 + 1;
  v195->timer = v213;
  struct StateT * v198 = v188->b;
  int v199 = v198->timer;
  int v215 = v199 + 1;
  v198->timer = v215;
  struct StateT * v201 = v188->a;
  int * v202 = v201->regs;
  v202[18] = 2;
  struct StateT * v204 = v188->b;
  int * v205 = v204->regs;
  v205[18] = 2;
  struct StateT2 * v207 = slot_5(v188);
  return v207;
}

struct StateT2 * slot_5(struct StateT2 * v431) {
  struct StateT * v432 = v431->a;
  int v433 = v432->timer;
  struct StateT * v434 = v431->b;
  int v435 = v434->timer;
  bool v449 = v433 == v435;
  squared_assert(v449);
  squared_assume(v449);
  struct StateT * v438 = v431->a;
  int v439 = v438->timer;
  int v451 = v439 + 1;
  v438->timer = v451;
  struct StateT * v441 = v431->b;
  int v442 = v441->timer;
  int v453 = v442 + 1;
  v441->timer = v453;
  return v431;
}

struct StateT2 * slot_2(struct StateT2 * v86) {
  struct StateT * v87 = v86->a;
  int v88 = v87->timer;
  struct StateT * v89 = v86->b;
  int v90 = v89->timer;
  bool v109 = v88 == v90;
  squared_assert(v109);
  squared_assume(v109);
  struct StateT * v93 = v86->a;
  int v94 = v93->timer;
  int v111 = v94 + 1;
  v93->timer = v111;
  struct StateT * v96 = v86->b;
  int v97 = v96->timer;
  int v113 = v97 + 1;
  v96->timer = v113;
  struct StateT * v99 = v86->a;
  int * v100 = v99->regs;
  v100[17] = 10;
  struct StateT * v102 = v86->b;
  int * v103 = v102->regs;
  v103[17] = 10;
  struct StateT2 * v105 = slot_3(v86);
  return v105;
}

struct StateT2 * slot_3(struct StateT2 * v122) {
  struct StateT * v123 = v122->a;
  int v124 = v123->timer;
  struct StateT * v125 = v122->b;
  int v126 = v125->timer;
  bool v161 = v124 == v126;
  squared_assert(v161);
  squared_assume(v161);
  struct StateT * v129 = v122->a;
  int v130 = v129->timer;
  int v163 = v130 + 1;
  v129->timer = v163;
  struct StateT * v132 = v122->b;
  int v133 = v132->timer;
  int v165 = v133 + 1;
  v132->timer = v165;
  struct StateT * v135 = v122->a;
  int * v136 = v135->regs;
  int v137 = v136[16];
  int v138 = v136[17];
  struct StateT * v139 = v122->b;
  int * v140 = v139->regs;
  int v141 = v140[16];
  int v142 = v140[17];
  bool v172 = v137 < v138;
  struct StateT2 * v157;
  if (v172) {
    bool v173 = v141 < v142;
    struct StateT2 * v148;
    if (v173) {
      struct StateT2 * v143 = slot_6(v122);
      v148 = v143;
    } else {
      struct StateT2 * v145 = slot_9(v122);
      struct StateT2 * v146 = slot_10(v122);
      v148 = v146;
    }
    v157 = v148;
  } else {
    bool v180 = v141 < v142;
    struct StateT2 * v155;
    if (v180) {
      struct StateT2 * v150 = slot_11(v122);
      struct StateT2 * v151 = slot_12(v122);
      v155 = v151;
    } else {
      struct StateT2 * v153 = slot_4(v122);
      v155 = v153;
    }
    v157 = v155;
  }
  return v157;
}

struct StateT2 * snippet(struct StateT2 * v0) {
  struct StateT2 * v1 = slot_0(v0);
  return v1;
}

struct StateT2 * slot_10(struct StateT2 * v247) {
  struct StateT * v248 = v247->b;
  int v249 = v248->timer;
  bool v261 = v249 == v249;
  squared_assert(v261);
  squared_assume(v261);
  struct StateT * v252 = v247->b;
  int v253 = v252->timer;
  int v263 = v253 + 1;
  v252->timer = v263;
  struct StateT * v255 = v247->b;
  int * v256 = v255->regs;
  v256[18] = 1;
  struct StateT2 * v258 = slot_14(v247);
  return v258;
}

struct StateT2 * slot_1(struct StateT2 * v38) {
  struct StateT * v39 = v38->a;
  int v40 = v39->timer;
  struct StateT * v41 = v38->b;
  int v42 = v41->timer;
  bool v67 = v40 == v42;
  squared_assert(v67);
  squared_assume(v67);
  struct StateT * v45 = v38->a;
  int v46 = v45->timer;
  int v69 = v46 + 1;
  v45->timer = v69;
  struct StateT * v48 = v38->b;
  int v49 = v48->timer;
  int v71 = v49 + 1;
  v48->timer = v71;
  struct StateT * v51 = v38->a;
  int * v52 = v51->regs;
  int v53 = v52[12];
  int * v54 = v51->mem;
  int v76 = (int)((unsigned int)v53 >> 2);
  int v55 = v54[v76];
  v52[16] = v55;
  struct StateT * v57 = v38->b;
  int * v58 = v57->regs;
  int v59 = v58[12];
  int * v60 = v57->mem;
  int v82 = (int)((unsigned int)v59 >> 2);
  int v61 = v60[v82];
  v58[16] = v61;
  struct StateT2 * v63 = slot_2(v38);
  return v63;
}

struct StateT2 * slot_4(struct StateT2 * v316) {
  struct StateT * v317 = v316->a;
  int v318 = v317->timer;
  struct StateT * v319 = v316->b;
  int v320 = v319->timer;
  bool v339 = v318 == v320;
  squared_assert(v339);
  squared_assume(v339);
  struct StateT * v323 = v316->a;
  int v324 = v323->timer;
  int v341 = v324 + 1;
  v323->timer = v341;
  struct StateT * v326 = v316->b;
  int v327 = v326->timer;
  int v343 = v327 + 1;
  v326->timer = v343;
  struct StateT * v329 = v316->a;
  int * v330 = v329->regs;
  v330[18] = 1;
  struct StateT * v332 = v316->b;
  int * v333 = v332->regs;
  v333[18] = 1;
  struct StateT2 * v335 = slot_5(v316);
  return v335;
}

struct StateT2 * slot_13(struct StateT2 * v375) {
  struct StateT * v376 = v375->a;
  int v377 = v376->timer;
  bool v386 = v377 == v377;
  squared_assert(v386);
  squared_assume(v386);
  struct StateT * v380 = v375->a;
  int v381 = v380->timer;
  int v388 = v381 + 1;
  v380->timer = v388;
  return v375;
}

struct StateT2 * slot_9(struct StateT2 * v224) {
  struct StateT * v225 = v224->a;
  int v226 = v225->timer;
  bool v238 = v226 == v226;
  squared_assert(v238);
  squared_assume(v238);
  struct StateT * v229 = v224->a;
  int v230 = v229->timer;
  int v240 = v230 + 1;
  v229->timer = v240;
  struct StateT * v232 = v224->a;
  int * v233 = v232->regs;
  v233[18] = 2;
  struct StateT2 * v235 = slot_13(v224);
  return v235;
}

struct StateT2 * slot_11(struct StateT2 * v270) {
  struct StateT * v271 = v270->a;
  int v272 = v271->timer;
  bool v284 = v272 == v272;
  squared_assert(v284);
  squared_assume(v284);
  struct StateT * v275 = v270->a;
  int v276 = v275->timer;
  int v286 = v276 + 1;
  v275->timer = v286;
  struct StateT * v278 = v270->a;
  int * v279 = v278->regs;
  v279[18] = 1;
  struct StateT2 * v281 = slot_13(v270);
  return v281;
}

struct StateT2 * slot_0(struct StateT2 * v2) {
  struct StateT * v3 = v2->a;
  int v4 = v3->timer;
  struct StateT * v5 = v2->b;
  int v6 = v5->timer;
  bool v25 = v4 == v6;
  squared_assert(v25);
  squared_assume(v25);
  struct StateT * v9 = v2->a;
  int v10 = v9->timer;
  int v27 = v10 + 1;
  v9->timer = v27;
  struct StateT * v12 = v2->b;
  int v13 = v12->timer;
  int v29 = v13 + 1;
  v12->timer = v29;
  struct StateT * v15 = v2->a;
  int * v16 = v15->regs;
  v16[12] = 80;
  struct StateT * v18 = v2->b;
  int * v19 = v18->regs;
  v19[12] = 80;
  struct StateT2 * v21 = slot_1(v2);
  return v21;
}



/*****************************************
End of C Generated Code
*******************************************/

void init(struct StateT *s) {
  for (int i=0; i<NUM_REGS; i++) {
    s->regs[i] = 0;
  }
  s->timer = 0;
  for (int i=0; i<MEM_SIZE; i++) {
    s->mem[i] = 0;
  }
}

void squared_assert(bool c) { koika_assert(c, "timer drift"); }
void squared_diverged(bool c) { koika_assert(c, "control flow diverged"); }
void squared_assume(bool c) { koika_assume(c); }

int main(int argc, char* argv[]) {
  struct StateT s1, s2;
  init(&s1);
  init(&s2);
  
  int x = bounded(0, 80);
  s1.regs[10] = x;
  s2.regs[10] = x;
  
  // initialize secret
  for (int i=0; i<SECRET_SIZE; i++) {
    s1.mem[SECRET_OFFSET+i] = secret(0, 20);
    s2.mem[SECRET_OFFSET+i] = secret(0, 20);
  }
  struct StateT2 p = { .a = &s1, .b = &s2 };
  struct StateT2 *p_ = snippet(&p);
  koika_assert(p_->a->timer==p_->b->timer, "timing leak");
  return 0;
}