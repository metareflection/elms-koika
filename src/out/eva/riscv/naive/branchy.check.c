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

struct StateT * slot_12(struct StateT * v188);
struct StateT * slot_6(struct StateT * v91);
struct StateT * slot_16(struct StateT * v247);
struct StateT * slot_5(struct StateT * v77);
struct StateT * slot_2(struct StateT * v32);
struct StateT * slot_7(struct StateT * v110);
struct StateT * slot_21(struct StateT * v325);
struct StateT * slot_3(struct StateT * v48);
struct StateT * slot_10(struct StateT * v155);
struct StateT * slot_1(struct StateT * v15);
struct StateT * slot_19(struct StateT * v297);
struct StateT * slot_13(struct StateT * v204);
struct StateT * slot_0(struct StateT * v2);
struct StateT * slot_14(struct StateT * v219);
struct StateT * slot_17(struct StateT * v266);
struct StateT * slot_20(struct StateT * v311);
struct StateT * snippet(struct StateT * v0);
struct StateT * slot_8(struct StateT * v126);
struct StateT * slot_4(struct StateT * v63);
struct StateT * slot_15(struct StateT * v233);
struct StateT * slot_18(struct StateT * v282);
struct StateT * slot_9(struct StateT * v141);
struct StateT * slot_22(struct StateT * v344);
struct StateT * slot_11(struct StateT * v169);
struct StateT * slot_12(struct StateT * v188) {
  int v189 = v188->timer;
  int v197 = v189 + 1;
  v188->timer = v197;
  int * v191 = v188->regs;
  int v192 = v191[5];
  int v193 = v191[7];
  int v201 = v192 ^ v193;
  v191[5] = v201;
  struct StateT * v195 = slot_13(v188);
  return v195;
}

struct StateT * slot_6(struct StateT * v91) {
  int v92 = v91->timer;
  int v101 = v92 + 1;
  v91->timer = v101;
  int * v94 = v91->regs;
  int v95 = v94[6];
  int * v96 = v91->mem;
  int v105 = (int)((unsigned int)v95 >> 2);
  int v97 = v96[v105];
  v94[7] = v97;
  struct StateT * v99 = slot_7(v91);
  return v99;
}

struct StateT * slot_16(struct StateT * v247) {
  int v248 = v247->timer;
  int v257 = v248 + 1;
  v247->timer = v257;
  int * v250 = v247->regs;
  int v251 = v250[6];
  int * v252 = v247->mem;
  int v261 = (int)((unsigned int)v251 >> 2);
  int v253 = v252[v261];
  v250[7] = v253;
  struct StateT * v255 = slot_17(v247);
  return v255;
}

struct StateT * slot_5(struct StateT * v77) {
  int v78 = v77->timer;
  int v85 = v78 + 1;
  v77->timer = v85;
  int * v80 = v77->regs;
  int v81 = v80[6];
  int v88 = v81 << 2;
  v80[6] = v88;
  struct StateT * v83 = slot_6(v77);
  return v83;
}

struct StateT * slot_2(struct StateT * v32) {
  int v33 = v32->timer;
  int v41 = v33 + 1;
  v32->timer = v41;
  int * v35 = v32->regs;
  int v36 = v35[5];
  int v37 = v35[9];
  int v45 = v36 ^ v37;
  v35[5] = v45;
  struct StateT * v39 = slot_3(v32);
  return v39;
}

struct StateT * slot_7(struct StateT * v110) {
  int v111 = v110->timer;
  int v119 = v111 + 1;
  v110->timer = v119;
  int * v113 = v110->regs;
  int v114 = v113[5];
  int v115 = v113[7];
  int v123 = v114 ^ v115;
  v113[5] = v123;
  struct StateT * v117 = slot_8(v110);
  return v117;
}

struct StateT * slot_21(struct StateT * v325) {
  int v326 = v325->timer;
  int v335 = v326 + 1;
  v325->timer = v335;
  int * v328 = v325->regs;
  int v329 = v328[6];
  int * v330 = v325->mem;
  int v339 = (int)((unsigned int)v329 >> 2);
  int v331 = v330[v339];
  v328[7] = v331;
  struct StateT * v333 = slot_22(v325);
  return v333;
}

struct StateT * slot_3(struct StateT * v48) {
  int v49 = v48->timer;
  int v56 = v49 + 1;
  v48->timer = v56;
  int * v51 = v48->regs;
  int v52 = v51[10];
  v51[6] = v52;
  struct StateT * v54 = slot_4(v48);
  return v54;
}

struct StateT * slot_10(struct StateT * v155) {
  int v156 = v155->timer;
  int v163 = v156 + 1;
  v155->timer = v163;
  int * v158 = v155->regs;
  int v159 = v158[6];
  int v166 = v159 << 2;
  v158[6] = v166;
  struct StateT * v161 = slot_11(v155);
  return v161;
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

struct StateT * slot_19(struct StateT * v297) {
  int v298 = v297->timer;
  int v305 = v298 + 1;
  v297->timer = v305;
  int * v300 = v297->regs;
  int v301 = v300[6];
  int v308 = v301 & 63;
  v300[6] = v308;
  struct StateT * v303 = slot_20(v297);
  return v303;
}

struct StateT * slot_13(struct StateT * v204) {
  int v205 = v204->timer;
  int v212 = v205 + 1;
  v204->timer = v212;
  int * v207 = v204->regs;
  int v208 = v207[10];
  int v216 = (int)((unsigned int)v208 >> 16);
  v207[6] = v216;
  struct StateT * v210 = slot_14(v204);
  return v210;
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

struct StateT * slot_14(struct StateT * v219) {
  int v220 = v219->timer;
  int v227 = v220 + 1;
  v219->timer = v227;
  int * v222 = v219->regs;
  int v223 = v222[6];
  int v230 = v223 & 63;
  v222[6] = v230;
  struct StateT * v225 = slot_15(v219);
  return v225;
}

struct StateT * slot_17(struct StateT * v266) {
  int v267 = v266->timer;
  int v275 = v267 + 1;
  v266->timer = v275;
  int * v269 = v266->regs;
  int v270 = v269[5];
  int v271 = v269[7];
  int v279 = v270 ^ v271;
  v269[5] = v279;
  struct StateT * v273 = slot_18(v266);
  return v273;
}

struct StateT * slot_20(struct StateT * v311) {
  int v312 = v311->timer;
  int v319 = v312 + 1;
  v311->timer = v319;
  int * v314 = v311->regs;
  int v315 = v314[6];
  int v322 = v315 << 2;
  v314[6] = v322;
  struct StateT * v317 = slot_21(v311);
  return v317;
}

struct StateT * snippet(struct StateT * v0) {
  struct StateT * v1 = slot_0(v0);
  return v1;
}

struct StateT * slot_8(struct StateT * v126) {
  int v127 = v126->timer;
  int v134 = v127 + 1;
  v126->timer = v134;
  int * v129 = v126->regs;
  int v130 = v129[10];
  int v138 = (int)((unsigned int)v130 >> 8);
  v129[6] = v138;
  struct StateT * v132 = slot_9(v126);
  return v132;
}

struct StateT * slot_4(struct StateT * v63) {
  int v64 = v63->timer;
  int v71 = v64 + 1;
  v63->timer = v71;
  int * v66 = v63->regs;
  int v67 = v66[6];
  int v74 = v67 & 63;
  v66[6] = v74;
  struct StateT * v69 = slot_5(v63);
  return v69;
}

struct StateT * slot_15(struct StateT * v233) {
  int v234 = v233->timer;
  int v241 = v234 + 1;
  v233->timer = v241;
  int * v236 = v233->regs;
  int v237 = v236[6];
  int v244 = v237 << 2;
  v236[6] = v244;
  struct StateT * v239 = slot_16(v233);
  return v239;
}

struct StateT * slot_18(struct StateT * v282) {
  int v283 = v282->timer;
  int v290 = v283 + 1;
  v282->timer = v290;
  int * v285 = v282->regs;
  int v286 = v285[10];
  int v294 = (int)((unsigned int)v286 >> 24);
  v285[6] = v294;
  struct StateT * v288 = slot_19(v282);
  return v288;
}

struct StateT * slot_9(struct StateT * v141) {
  int v142 = v141->timer;
  int v149 = v142 + 1;
  v141->timer = v149;
  int * v144 = v141->regs;
  int v145 = v144[6];
  int v152 = v145 & 63;
  v144[6] = v152;
  struct StateT * v147 = slot_10(v141);
  return v147;
}

struct StateT * slot_22(struct StateT * v344) {
  int v345 = v344->timer;
  int v352 = v345 + 1;
  v344->timer = v352;
  int * v347 = v344->regs;
  int v348 = v347[5];
  int v349 = v347[7];
  int v356 = v348 ^ v349;
  v347[5] = v356;
  return v344;
}

struct StateT * slot_11(struct StateT * v169) {
  int v170 = v169->timer;
  int v179 = v170 + 1;
  v169->timer = v179;
  int * v172 = v169->regs;
  int v173 = v172[6];
  int * v174 = v169->mem;
  int v183 = (int)((unsigned int)v173 >> 2);
  int v175 = v174[v183];
  v172[7] = v175;
  struct StateT * v177 = slot_12(v169);
  return v177;
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
  
  // the indices, public: one draw into both states
  int i10 = bounded(0, 1073741823);
  s1.regs[10] = i10;
  s2.regs[10] = i10;
  
  // initialize secret
  for (int i=0; i<SECRET_SIZE; i++) {
    s1.mem[SECRET_OFFSET+i] = secret(0, 20);
    s2.mem[SECRET_OFFSET+i] = secret(0, 20);
  }
  struct StateT *s1_ = snippet(&s1);
  struct StateT *s2_ = snippet(&s2);
  //@ assert untainted_timer: !\tainted(s1_->timer==s2_->timer);
  koika_assert(s1_->timer==s2_->timer, "timing leak");
  return 0;
}