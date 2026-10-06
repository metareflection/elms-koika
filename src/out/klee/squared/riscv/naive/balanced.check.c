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
void squared_diverged(bool);

struct StateT2 * snippet(struct StateT2 * v0);
struct StateT2 * slot_1(struct StateT2 * v38);
struct StateT2 * slot_6(struct StateT2 * v171);
struct StateT2 * slot_5(struct StateT2 * v266);
struct StateT2 * slot_4(struct StateT2 * v207);
struct StateT2 * slot_2(struct StateT2 * v86);
struct StateT2 * slot_3(struct StateT2 * v122);
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

struct StateT2 * slot_6(struct StateT2 * v171) {
  struct StateT * v172 = v171->a;
  int v173 = v172->timer;
  struct StateT * v174 = v171->b;
  int v175 = v174->timer;
  bool v194 = v173 == v175;
  squared_assert(v194);
  squared_assume(v194);
  struct StateT * v178 = v171->a;
  int v179 = v178->timer;
  int v196 = v179 + 1;
  v178->timer = v196;
  struct StateT * v181 = v171->b;
  int v182 = v181->timer;
  int v198 = v182 + 1;
  v181->timer = v198;
  struct StateT * v184 = v171->a;
  int * v185 = v184->regs;
  v185[18] = 2;
  struct StateT * v187 = v171->b;
  int * v188 = v187->regs;
  v188[18] = 2;
  struct StateT2 * v190 = slot_5(v171);
  return v190;
}

struct StateT2 * slot_5(struct StateT2 * v266) {
  struct StateT * v267 = v266->a;
  int v268 = v267->timer;
  struct StateT * v269 = v266->b;
  int v270 = v269->timer;
  bool v284 = v268 == v270;
  squared_assert(v284);
  squared_assume(v284);
  struct StateT * v273 = v266->a;
  int v274 = v273->timer;
  int v286 = v274 + 1;
  v273->timer = v286;
  struct StateT * v276 = v266->b;
  int v277 = v276->timer;
  int v288 = v277 + 1;
  v276->timer = v288;
  return v266;
}

struct StateT2 * slot_4(struct StateT2 * v207) {
  struct StateT * v208 = v207->a;
  int v209 = v208->timer;
  struct StateT * v210 = v207->b;
  int v211 = v210->timer;
  bool v230 = v209 == v211;
  squared_assert(v230);
  squared_assume(v230);
  struct StateT * v214 = v207->a;
  int v215 = v214->timer;
  int v232 = v215 + 1;
  v214->timer = v232;
  struct StateT * v217 = v207->b;
  int v218 = v217->timer;
  int v234 = v218 + 1;
  v217->timer = v234;
  struct StateT * v220 = v207->a;
  int * v221 = v220->regs;
  v221[18] = 1;
  struct StateT * v223 = v207->b;
  int * v224 = v223->regs;
  v224[18] = 1;
  struct StateT2 * v226 = slot_5(v207);
  return v226;
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
  bool v153 = v124 == v126;
  squared_assert(v153);
  squared_assume(v153);
  struct StateT * v129 = v122->a;
  int v130 = v129->timer;
  int v155 = v130 + 1;
  v129->timer = v155;
  struct StateT * v132 = v122->b;
  int v133 = v132->timer;
  int v157 = v133 + 1;
  v132->timer = v157;
  struct StateT * v135 = v122->a;
  int * v136 = v135->regs;
  int v137 = v136[16];
  int v138 = v136[17];
  struct StateT * v139 = v122->b;
  int * v140 = v139->regs;
  int v141 = v140[16];
  int v142 = v140[17];
  bool v164 = (v137 < v138) == (v141 < v142);
  squared_diverged(v164);
  squared_assume(v164);
  bool v165 = v137 < v138;
  struct StateT2 * v149;
  if (v165) {
    struct StateT2 * v145 = slot_6(v122);
    v149 = v145;
  } else {
    struct StateT2 * v147 = slot_4(v122);
    v149 = v147;
  }
  return v149;
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