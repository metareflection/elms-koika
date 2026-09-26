// verify: leak (KLEE should report a failing assertion) [budget 1200s]
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
void squared_diverged(bool);

struct StateT2 * snippet(struct StateT2 * v0);
struct StateT2 * slot_1(struct StateT2 * v38);
struct StateT2 * slot_6(struct StateT2 * v179);
struct StateT2 * slot_5(struct StateT2 * v274);
struct StateT2 * slot_4(struct StateT2 * v215);
struct StateT2 * slot_2(struct StateT2 * v90);
struct StateT2 * slot_7(struct StateT2 * v251);
struct StateT2 * slot_3(struct StateT2 * v126);
struct StateT2 * slot_0(struct StateT2 * v2);
struct StateT2 * snippet(struct StateT2 * v0) {
  struct StateT2 * v1 = slot_0(v0);
  return v1;
}

struct StateT2 * slot_1(struct StateT2 * v38) {
  struct StateT * v39 = v38->a;
  int v40 = v39->timer;
  struct StateT * v41 = v38->b;
  int v42 = v41->timer;
  bool v69 = v40 == v42;
  squared_assert(v69);
  squared_assume(v69);
  struct StateT * v45 = v38->a;
  int v46 = v45->timer;
  int v71 = v46 + 1;
  v45->timer = v71;
  struct StateT * v48 = v38->b;
  int v49 = v48->timer;
  int v73 = v49 + 1;
  v48->timer = v73;
  struct StateT * v51 = v38->a;
  int * v52 = v51->regs;
  int v53 = v52[12];
  int * v54 = v51->mem;
  int v78 = (int)((unsigned int)v53 >> 2);
  int v55 = v54[v78];
  int * v56 = v51->regs;
  v56[16] = v55;
  struct StateT * v58 = v38->b;
  int * v59 = v58->regs;
  int v60 = v59[12];
  int * v61 = v58->mem;
  int v85 = (int)((unsigned int)v60 >> 2);
  int v62 = v61[v85];
  int * v63 = v58->regs;
  v63[16] = v62;
  struct StateT2 * v65 = slot_2(v38);
  return v65;
}

struct StateT2 * slot_6(struct StateT2 * v179) {
  struct StateT * v180 = v179->a;
  int v181 = v180->timer;
  struct StateT * v182 = v179->b;
  int v183 = v182->timer;
  bool v202 = v181 == v183;
  squared_assert(v202);
  squared_assume(v202);
  struct StateT * v186 = v179->a;
  int v187 = v186->timer;
  int v204 = v187 + 1;
  v186->timer = v204;
  struct StateT * v189 = v179->b;
  int v190 = v189->timer;
  int v206 = v190 + 1;
  v189->timer = v206;
  struct StateT * v192 = v179->a;
  int * v193 = v192->regs;
  v193[18] = 2;
  struct StateT * v195 = v179->b;
  int * v196 = v195->regs;
  v196[18] = 2;
  struct StateT2 * v198 = slot_7(v179);
  return v198;
}

struct StateT2 * slot_5(struct StateT2 * v274) {
  struct StateT * v275 = v274->a;
  int v276 = v275->timer;
  struct StateT * v277 = v274->b;
  int v278 = v277->timer;
  bool v292 = v276 == v278;
  squared_assert(v292);
  squared_assume(v292);
  struct StateT * v281 = v274->a;
  int v282 = v281->timer;
  int v294 = v282 + 1;
  v281->timer = v294;
  struct StateT * v284 = v274->b;
  int v285 = v284->timer;
  int v296 = v285 + 1;
  v284->timer = v296;
  struct StateT * v287 = v274->a;
  struct StateT * v288 = v274->b;
  return v274;
}

struct StateT2 * slot_4(struct StateT2 * v215) {
  struct StateT * v216 = v215->a;
  int v217 = v216->timer;
  struct StateT * v218 = v215->b;
  int v219 = v218->timer;
  bool v238 = v217 == v219;
  squared_assert(v238);
  squared_assume(v238);
  struct StateT * v222 = v215->a;
  int v223 = v222->timer;
  int v240 = v223 + 1;
  v222->timer = v240;
  struct StateT * v225 = v215->b;
  int v226 = v225->timer;
  int v242 = v226 + 1;
  v225->timer = v242;
  struct StateT * v228 = v215->a;
  int * v229 = v228->regs;
  v229[18] = 1;
  struct StateT * v231 = v215->b;
  int * v232 = v231->regs;
  v232[18] = 1;
  struct StateT2 * v234 = slot_5(v215);
  return v234;
}

struct StateT2 * slot_2(struct StateT2 * v90) {
  struct StateT * v91 = v90->a;
  int v92 = v91->timer;
  struct StateT * v93 = v90->b;
  int v94 = v93->timer;
  bool v113 = v92 == v94;
  squared_assert(v113);
  squared_assume(v113);
  struct StateT * v97 = v90->a;
  int v98 = v97->timer;
  int v115 = v98 + 1;
  v97->timer = v115;
  struct StateT * v100 = v90->b;
  int v101 = v100->timer;
  int v117 = v101 + 1;
  v100->timer = v117;
  struct StateT * v103 = v90->a;
  int * v104 = v103->regs;
  v104[17] = 10;
  struct StateT * v106 = v90->b;
  int * v107 = v106->regs;
  v107[17] = 10;
  struct StateT2 * v109 = slot_3(v90);
  return v109;
}

struct StateT2 * slot_7(struct StateT2 * v251) {
  struct StateT * v252 = v251->a;
  int v253 = v252->timer;
  struct StateT * v254 = v251->b;
  int v255 = v254->timer;
  bool v269 = v253 == v255;
  squared_assert(v269);
  squared_assume(v269);
  struct StateT * v258 = v251->a;
  int v259 = v258->timer;
  int v271 = v259 + 1;
  v258->timer = v271;
  struct StateT * v261 = v251->b;
  int v262 = v261->timer;
  int v273 = v262 + 1;
  v261->timer = v273;
  struct StateT * v264 = v251->a;
  struct StateT * v265 = v251->b;
  return v251;
}

struct StateT2 * slot_3(struct StateT2 * v126) {
  struct StateT * v127 = v126->a;
  int v128 = v127->timer;
  struct StateT * v129 = v126->b;
  int v130 = v129->timer;
  bool v159 = v128 == v130;
  squared_assert(v159);
  squared_assume(v159);
  struct StateT * v133 = v126->a;
  int v134 = v133->timer;
  int v161 = v134 + 1;
  v133->timer = v161;
  struct StateT * v136 = v126->b;
  int v137 = v136->timer;
  int v163 = v137 + 1;
  v136->timer = v163;
  struct StateT * v139 = v126->a;
  int * v140 = v139->regs;
  int v141 = v140[16];
  int * v142 = v139->regs;
  int v143 = v142[17];
  struct StateT * v144 = v126->b;
  int * v145 = v144->regs;
  int v146 = v145[16];
  int * v147 = v144->regs;
  int v148 = v147[17];
  bool v172 = (v141 < v143) == (v146 < v148);
  squared_diverged(v172);
  squared_assume(v172);
  bool v173 = v141 < v143;
  struct StateT2 * v155;
  if (v173) {
    struct StateT2 * v151 = slot_6(v126);
    v155 = v151;
  } else {
    struct StateT2 * v153 = slot_4(v126);
    v155 = v153;
  }
  return v155;
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
    s1.mem[SECRET_OFFSET+i] = bounded(0, 20);
    s2.mem[SECRET_OFFSET+i] = bounded(0, 20);
  }
  struct StateT2 p = { .a = &s1, .b = &s2 };
  struct StateT2 *p_ = snippet(&p);
  koika_assert(p_->a->timer==p_->b->timer, "timing leak");
  return 0;
}