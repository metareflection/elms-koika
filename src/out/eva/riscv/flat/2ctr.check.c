// verify: leak (Eva should report untainted: unknown) [unroll 65]
#define NUM_REGS 32
#define MEM_SIZE 64
#define SECRET_SIZE 10
#define SECRET_OFFSET 20
#define CACHE_ENTRIES 2
#define CACHE_WORDS 2

#ifdef EVA
#include "__fc_builtin.h"
/*@ requires untainted: !\tainted(b);
    assigns \nothing; */
void koika_check(int b);
/*@ assigns *p \from \nothing;
    taints *p; */
void koika_mark(int *p);
#define koika_assert(b, s) koika_check(b)
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
  int cache_tags[2];
  int cache_dirty[2];
  int cache_age[2];
  int cache_vals[2];
  int timer;
};

struct StateT * snippet(struct StateT * v0);
struct StateT * slot_1(struct StateT * v19);
struct StateT * slot_2(struct StateT * v135);
struct StateT * slot_3(struct StateT * v149);
struct StateT * slot_0(struct StateT * v2);
struct StateT * snippet(struct StateT * v0) {
  struct StateT * v1 = slot_0(v0);
  return v1;
}

struct StateT * slot_1(struct StateT * v19) {
  int v20 = v19->timer;
  int v83 = v20 + 1;
  v19->timer = v83;
  int * v22 = v19->regs;
  int v23 = v22[10];
  int * v24 = v19->cache_tags;
  int v25 = v24[0];
  int v26 = v24[1];
  int v27 = v19->timer;
  int v89 = v27 + (100 ^ (((~(((v25 ^ ((int)((unsigned int)v23 >> 2))) | (-(v25 ^ ((int)((unsigned int)v23 >> 2))))) >> 31)) | (~(((v26 ^ ((int)((unsigned int)v23 >> 2))) | (-(v26 ^ ((int)((unsigned int)v23 >> 2))))) >> 31))) & 101));
  v19->timer = v89;
  int * v29 = v19->cache_vals;
  bool v90 = !(((~(((v25 ^ ((int)((unsigned int)v23 >> 2))) | (-(v25 ^ ((int)((unsigned int)v23 >> 2))))) >> 31)) | (~(((v26 ^ ((int)((unsigned int)v23 >> 2))) | (-(v26 ^ ((int)((unsigned int)v23 >> 2))))) >> 31))) == 0);
  int v77;
  if (v90) {
    int * v30 = v19->cache_age;
    int v92 = (~(((v26 ^ ((int)((unsigned int)v23 >> 2))) | (-(v26 ^ ((int)((unsigned int)v23 >> 2))))) >> 31)) & 1;
    int v31 = v30[v92];
    int v32 = v30[0];
    int v93 = v32 + ((int)((unsigned int)(v32 - v31) >> 31));
    v30[0] = v93;
    int * v34 = v19->cache_age;
    int v35 = v34[1];
    int v95 = v35 + ((int)((unsigned int)(v35 - v31) >> 31));
    v34[1] = v95;
    int * v37 = v19->cache_age;
    v37[v92] = 0;
    v77 = v92;
  } else {
    int * v40 = v19->cache_age;
    int v41 = v40[0];
    int * v42 = v19->cache_tags;
    int v43 = v42[0];
    int v44 = v40[1];
    int v45 = v42[1];
    int * v46 = v19->cache_dirty;
    int v102 = (((v41 + ((~(((v43 ^ -1) | (-(v43 ^ -1))) >> 31)) & 2)) - (v44 + ((~(((v45 ^ -1) | (-(v45 ^ -1))) >> 31)) & 2))) >> 31) & 1;
    int v47 = v46[v102];
    bool v103 = !(v47 == 0);
    if (v103) {
      int * v48 = v19->cache_tags;
      int v49 = v48[v102];
      int * v50 = v19->cache_vals;
      int v106 = (((v41 + ((~(((v43 ^ -1) | (-(v43 ^ -1))) >> 31)) & 2)) - (v44 + ((~(((v45 ^ -1) | (-(v45 ^ -1))) >> 31)) & 2))) >> 31) & 1;
      int v51 = v50[v106];
      int * v52 = v19->mem;
      v52[v49] = v51;
      ;
    } else {
      ;
    }
    int * v57 = v19->mem;
    int v113 = (int)((unsigned int)v23 >> 2);
    int v58 = v57[v113];
    int * v59 = v19->cache_vals;
    int v115 = (((v41 + ((~(((v43 ^ -1) | (-(v43 ^ -1))) >> 31)) & 2)) - (v44 + ((~(((v45 ^ -1) | (-(v45 ^ -1))) >> 31)) & 2))) >> 31) & 1;
    v59[v115] = v58;
    int * v61 = v19->cache_tags;
    int v118 = (int)((unsigned int)v23 >> 2);
    v61[v102] = v118;
    int * v63 = v19->cache_dirty;
    v63[v102] = 0;
    int * v65 = v19->cache_age;
    v65[v102] = 1;
    int * v67 = v19->cache_age;
    int v68 = v67[v102];
    int v69 = v67[0];
    int v124 = v69 + ((int)((unsigned int)(v69 - v68) >> 31));
    v67[0] = v124;
    int * v71 = v19->cache_age;
    int v72 = v71[1];
    int v126 = v72 + ((int)((unsigned int)(v72 - v68) >> 31));
    v71[1] = v126;
    int * v74 = v19->cache_age;
    v74[v102] = 0;
    v77 = v102;
  }
  int v78 = v29[v77];
  int * v79 = v19->regs;
  v79[11] = v78;
  struct StateT * v81 = slot_2(v19);
  return v81;
}

struct StateT * slot_2(struct StateT * v135) {
  int v136 = v135->timer;
  int v143 = v136 + 1;
  v135->timer = v143;
  int * v138 = v135->regs;
  int v139 = v138[11];
  int v146 = v139 << 2;
  v138[11] = v146;
  struct StateT * v141 = slot_3(v135);
  return v141;
}

struct StateT * slot_3(struct StateT * v149) {
  int v150 = v149->timer;
  int v212 = v150 + 1;
  v149->timer = v212;
  int * v152 = v149->regs;
  int v153 = v152[11];
  int * v154 = v149->cache_tags;
  int v155 = v154[0];
  int v156 = v154[1];
  int v157 = v149->timer;
  int v218 = v157 + (100 ^ (((~(((v155 ^ ((int)((unsigned int)(v153 + 16) >> 2))) | (-(v155 ^ ((int)((unsigned int)(v153 + 16) >> 2))))) >> 31)) | (~(((v156 ^ ((int)((unsigned int)(v153 + 16) >> 2))) | (-(v156 ^ ((int)((unsigned int)(v153 + 16) >> 2))))) >> 31))) & 101));
  v149->timer = v218;
  int * v159 = v149->cache_vals;
  bool v219 = !(((~(((v155 ^ ((int)((unsigned int)(v153 + 16) >> 2))) | (-(v155 ^ ((int)((unsigned int)(v153 + 16) >> 2))))) >> 31)) | (~(((v156 ^ ((int)((unsigned int)(v153 + 16) >> 2))) | (-(v156 ^ ((int)((unsigned int)(v153 + 16) >> 2))))) >> 31))) == 0);
  int v207;
  if (v219) {
    int * v160 = v149->cache_age;
    int v221 = (~(((v156 ^ ((int)((unsigned int)(v153 + 16) >> 2))) | (-(v156 ^ ((int)((unsigned int)(v153 + 16) >> 2))))) >> 31)) & 1;
    int v161 = v160[v221];
    int v162 = v160[0];
    int v222 = v162 + ((int)((unsigned int)(v162 - v161) >> 31));
    v160[0] = v222;
    int * v164 = v149->cache_age;
    int v165 = v164[1];
    int v224 = v165 + ((int)((unsigned int)(v165 - v161) >> 31));
    v164[1] = v224;
    int * v167 = v149->cache_age;
    v167[v221] = 0;
    v207 = v221;
  } else {
    int * v170 = v149->cache_age;
    int v171 = v170[0];
    int * v172 = v149->cache_tags;
    int v173 = v172[0];
    int v174 = v170[1];
    int v175 = v172[1];
    int * v176 = v149->cache_dirty;
    int v231 = (((v171 + ((~(((v173 ^ -1) | (-(v173 ^ -1))) >> 31)) & 2)) - (v174 + ((~(((v175 ^ -1) | (-(v175 ^ -1))) >> 31)) & 2))) >> 31) & 1;
    int v177 = v176[v231];
    bool v232 = !(v177 == 0);
    if (v232) {
      int * v178 = v149->cache_tags;
      int v179 = v178[v231];
      int * v180 = v149->cache_vals;
      int v235 = (((v171 + ((~(((v173 ^ -1) | (-(v173 ^ -1))) >> 31)) & 2)) - (v174 + ((~(((v175 ^ -1) | (-(v175 ^ -1))) >> 31)) & 2))) >> 31) & 1;
      int v181 = v180[v235];
      int * v182 = v149->mem;
      v182[v179] = v181;
      ;
    } else {
      ;
    }
    int * v187 = v149->mem;
    int v242 = (int)((unsigned int)(v153 + 16) >> 2);
    int v188 = v187[v242];
    int * v189 = v149->cache_vals;
    int v244 = (((v171 + ((~(((v173 ^ -1) | (-(v173 ^ -1))) >> 31)) & 2)) - (v174 + ((~(((v175 ^ -1) | (-(v175 ^ -1))) >> 31)) & 2))) >> 31) & 1;
    v189[v244] = v188;
    int * v191 = v149->cache_tags;
    int v247 = (int)((unsigned int)(v153 + 16) >> 2);
    v191[v231] = v247;
    int * v193 = v149->cache_dirty;
    v193[v231] = 0;
    int * v195 = v149->cache_age;
    v195[v231] = 1;
    int * v197 = v149->cache_age;
    int v198 = v197[v231];
    int v199 = v197[0];
    int v253 = v199 + ((int)((unsigned int)(v199 - v198) >> 31));
    v197[0] = v253;
    int * v201 = v149->cache_age;
    int v202 = v201[1];
    int v255 = v202 + ((int)((unsigned int)(v202 - v198) >> 31));
    v201[1] = v255;
    int * v204 = v149->cache_age;
    v204[v231] = 0;
    v207 = v231;
  }
  int v208 = v159[v207];
  int * v209 = v149->regs;
  v209[12] = v208;
  return v149;
}

struct StateT * slot_0(struct StateT * v2) {
  int v3 = v2->timer;
  int v12 = v3 + 1;
  v2->timer = v12;
  int * v5 = v2->regs;
  int v6 = v5[10];
  bool v15 = v6 == 0;
  struct StateT * v10;
  if (v15) {
    v10 = v2;
  } else {
    struct StateT * v8 = slot_1(v2);
    v10 = v8;
  }
  return v10;
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
  
  int x = bounded(0, 80);
  s1.regs[10] = x;
  s2.regs[10] = x;
  
  // initialize secret
  for (int i=0; i<SECRET_SIZE; i++) {
    s1.mem[SECRET_OFFSET+i] = secret(0, 20);
    s2.mem[SECRET_OFFSET+i] = secret(0, 20);
  }
  struct StateT *s1_ = snippet(&s1);
  struct StateT *s2_ = snippet(&s2);
  koika_assert(s1_->timer==s2_->timer, "timing leak");
  return 0;
}