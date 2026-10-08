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

struct StateT * slot_12(struct StateT * v190);
struct StateT * slot_6(struct StateT * v99);
struct StateT * slot_16(struct StateT * v245);
struct StateT * slot_5(struct StateT * v85);
struct StateT * slot_2(struct StateT * v33);
struct StateT * slot_7(struct StateT * v113);
struct StateT * slot_21(struct StateT * v333);
struct StateT * slot_3(struct StateT * v48);
struct StateT * slot_10(struct StateT * v159);
struct StateT * slot_1(struct StateT * v15);
struct StateT * slot_19(struct StateT * v298);
struct StateT * slot_13(struct StateT * v204);
struct StateT * slot_0(struct StateT * v2);
struct StateT * slot_14(struct StateT * v217);
struct StateT * slot_17(struct StateT * v261);
struct StateT * slot_20(struct StateT * v314);
struct StateT * snippet(struct StateT * v0);
struct StateT * slot_8(struct StateT * v129);
struct StateT * slot_4(struct StateT * v72);
struct StateT * slot_15(struct StateT * v231);
struct StateT * slot_18(struct StateT * v279);
struct StateT * slot_9(struct StateT * v143);
struct StateT * slot_11(struct StateT * v177);
struct StateT * slot_12(struct StateT * v190) {
  int v191 = v190->timer;
  int v198 = v191 + 1;
  v190->timer = v198;
  int * v193 = v190->regs;
  int v194 = v193[11];
  int v201 = v194 + 4;
  v193[11] = v201;
  struct StateT * v196 = slot_13(v190);
  return v196;
}

struct StateT * slot_6(struct StateT * v99) {
  int v100 = v99->timer;
  int v107 = v100 + 1;
  v99->timer = v107;
  int * v102 = v99->regs;
  int v103 = v102[10];
  int v110 = -v103;
  v102[10] = v110;
  struct StateT * v105 = slot_7(v99);
  return v105;
}

struct StateT * slot_16(struct StateT * v245) {
  int v246 = v245->timer;
  int v254 = v246 + 1;
  v245->timer = v254;
  int * v248 = v245->regs;
  int v249 = v248[11];
  int v250 = v248[10];
  int v258 = v249 + v250;
  v248[10] = v258;
  struct StateT * v252 = slot_17(v245);
  return v252;
}

struct StateT * slot_5(struct StateT * v85) {
  int v86 = v85->timer;
  int v93 = v86 + 1;
  v85->timer = v93;
  int * v88 = v85->regs;
  int v89 = v88[11];
  int v96 = v89 + 72;
  v88[11] = v96;
  struct StateT * v91 = slot_6(v85);
  return v91;
}

struct StateT * slot_2(struct StateT * v33) {
  int v34 = v33->timer;
  int v41 = v34 + 1;
  v33->timer = v41;
  int * v36 = v33->regs;
  int v37 = v36[10];
  int v45 = v37 + 1;
  v36[12] = v45;
  struct StateT * v39 = slot_3(v33);
  return v39;
}

struct StateT * slot_7(struct StateT * v113) {
  int v114 = v113->timer;
  int v122 = v114 + 1;
  v113->timer = v122;
  int * v116 = v113->regs;
  int v117 = v116[10];
  int v118 = v116[12];
  int v126 = v117 & v118;
  v116[10] = v126;
  struct StateT * v120 = slot_8(v113);
  return v120;
}

struct StateT * slot_21(struct StateT * v333) {
  int v334 = v333->timer;
  int v337 = v334 + 1;
  v333->timer = v337;
  return v333;
}

struct StateT * slot_3(struct StateT * v48) {
  int v49 = v48->timer;
  int v61 = v49 + 1;
  v48->timer = v61;
  int * v51 = v48->regs;
  int v52 = v51[10];
  int v53 = v51[11];
  bool v65 = (v52 ^ -2147483648) < (v53 ^ -2147483648);
  int v56;
  if (v65) {
    v56 = 1;
  } else {
    v56 = 0;
  }
  int * v57 = v48->regs;
  v57[10] = v56;
  struct StateT * v59 = slot_4(v48);
  return v59;
}

struct StateT * slot_10(struct StateT * v159) {
  int v160 = v159->timer;
  int v169 = v160 + 1;
  v159->timer = v169;
  int * v162 = v159->regs;
  int v163 = v162[10];
  int * v164 = v159->mem;
  int v173 = (int)((unsigned int)v163 >> 2);
  int v165 = v164[v173];
  v162[10] = v165;
  struct StateT * v167 = slot_11(v159);
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

struct StateT * slot_19(struct StateT * v298) {
  int v299 = v298->timer;
  int v307 = v299 + 1;
  v298->timer = v307;
  int * v301 = v298->regs;
  int v302 = v301[11];
  int v303 = v301[10];
  int v311 = v302 & v303;
  v301[10] = v311;
  struct StateT * v305 = slot_20(v298);
  return v305;
}

struct StateT * slot_13(struct StateT * v204) {
  int v205 = v204->timer;
  int v211 = v205 + 1;
  v204->timer = v211;
  int * v207 = v204->regs;
  v207[12] = 0;
  struct StateT * v209 = slot_14(v204);
  return v209;
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

struct StateT * slot_14(struct StateT * v217) {
  int v218 = v217->timer;
  int v225 = v218 + 1;
  v217->timer = v225;
  int * v220 = v217->regs;
  int v221 = v220[10];
  int v228 = v221 << 29;
  v220[10] = v228;
  struct StateT * v223 = slot_15(v217);
  return v223;
}

struct StateT * slot_17(struct StateT * v261) {
  int v262 = v261->timer;
  int v271 = v262 + 1;
  v261->timer = v271;
  int * v264 = v261->regs;
  int v265 = v264[10];
  int * v266 = v261->mem;
  int v275 = (int)((unsigned int)v265 >> 2);
  int v267 = v266[v275];
  v264[10] = v267;
  struct StateT * v269 = slot_18(v261);
  return v269;
}

struct StateT * slot_20(struct StateT * v314) {
  int v315 = v314->timer;
  int v324 = v315 + 1;
  v314->timer = v324;
  int * v317 = v314->regs;
  int v318 = v317[12];
  int v319 = v317[10];
  int * v320 = v314->mem;
  int v329 = (int)((unsigned int)(v318 + 68) >> 2);
  v320[v329] = v319;
  struct StateT * v322 = slot_21(v314);
  return v322;
}

struct StateT * snippet(struct StateT * v0) {
  struct StateT * v1 = slot_0(v0);
  return v1;
}

struct StateT * slot_8(struct StateT * v129) {
  int v130 = v129->timer;
  int v137 = v130 + 1;
  v129->timer = v137;
  int * v132 = v129->regs;
  int v133 = v132[10];
  int v140 = v133 << 2;
  v132[10] = v140;
  struct StateT * v135 = slot_9(v129);
  return v135;
}

struct StateT * slot_4(struct StateT * v72) {
  int v73 = v72->timer;
  int v79 = v73 + 1;
  v72->timer = v79;
  int * v75 = v72->regs;
  v75[11] = 0;
  struct StateT * v77 = slot_5(v72);
  return v77;
}

struct StateT * slot_15(struct StateT * v231) {
  int v232 = v231->timer;
  int v239 = v232 + 1;
  v231->timer = v239;
  int * v234 = v231->regs;
  int v235 = v234[10];
  int v242 = (int)((unsigned int)v235 >> 26);
  v234[10] = v242;
  struct StateT * v237 = slot_16(v231);
  return v237;
}

struct StateT * slot_18(struct StateT * v279) {
  int v280 = v279->timer;
  int v289 = v280 + 1;
  v279->timer = v289;
  int * v282 = v279->regs;
  int v283 = v282[12];
  int * v284 = v279->mem;
  int v293 = (int)((unsigned int)(v283 + 68) >> 2);
  int v285 = v284[v293];
  v282[11] = v285;
  struct StateT * v287 = slot_19(v279);
  return v287;
}

struct StateT * slot_9(struct StateT * v143) {
  int v144 = v143->timer;
  int v152 = v144 + 1;
  v143->timer = v152;
  int * v146 = v143->regs;
  int v147 = v146[11];
  int v148 = v146[10];
  int v156 = v147 + v148;
  v146[10] = v156;
  struct StateT * v150 = slot_10(v143);
  return v150;
}

struct StateT * slot_11(struct StateT * v177) {
  int v178 = v177->timer;
  int v184 = v178 + 1;
  v177->timer = v184;
  int * v180 = v177->regs;
  v180[11] = 0;
  struct StateT * v182 = slot_12(v177);
  return v182;
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