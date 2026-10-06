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

struct StateT * snippet(struct StateT * v0);
struct StateT * slot_1(struct StateT * v15);
struct StateT * slot_8(struct StateT * v125);
struct StateT * slot_6(struct StateT * v92);
struct StateT * slot_5(struct StateT * v79);
struct StateT * slot_4(struct StateT * v60);
struct StateT * slot_2(struct StateT * v34);
struct StateT * slot_7(struct StateT * v106);
struct StateT * slot_3(struct StateT * v47);
struct StateT * slot_0(struct StateT * v2);
struct StateT * snippet(struct StateT * v0) {
  struct StateT * v1 = slot_0(v0);
  return v1;
}

struct StateT * slot_1(struct StateT * v15) {
  int v16 = v15->timer;
  int v25 = v16 + 1;
  v15->timer = v25;
  int * v18 = v15->regs;
  int v19 = v18[6];
  int * v20 = v15->mem;
  int v29 = (int)((unsigned int)v19 >> 2);
  int v21 = v20[v29];
  v18[5] = v21;
  struct StateT * v23 = slot_2(v15);
  return v23;
}

struct StateT * slot_8(struct StateT * v125) {
  int v126 = v125->timer;
  int v134 = v126 + 1;
  v125->timer = v134;
  int * v128 = v125->regs;
  int v129 = v128[11];
  int * v130 = v125->mem;
  int v138 = (int)((unsigned int)v129 >> 2);
  int v131 = v130[v138];
  v128[12] = v131;
  return v125;
}

struct StateT * slot_6(struct StateT * v92) {
  int v93 = v92->timer;
  int v100 = v93 + 1;
  v92->timer = v100;
  int * v95 = v92->regs;
  int v96 = v95[7];
  int v103 = v96 + 1;
  v95[7] = v103;
  struct StateT * v98 = slot_7(v92);
  return v98;
}

struct StateT * slot_5(struct StateT * v79) {
  int v80 = v79->timer;
  int v86 = v80 + 1;
  v79->timer = v86;
  int * v82 = v79->regs;
  v82[7] = 0;
  struct StateT * v84 = slot_6(v79);
  return v84;
}

struct StateT * slot_4(struct StateT * v60) {
  int v61 = v60->timer;
  int v70 = v61 + 1;
  v60->timer = v70;
  int * v63 = v60->regs;
  int v64 = v63[8];
  int v65 = v63[5];
  int * v66 = v60->mem;
  int v75 = (int)((unsigned int)v64 >> 2);
  v66[v75] = v65;
  struct StateT * v68 = slot_5(v60);
  return v68;
}

struct StateT * slot_2(struct StateT * v34) {
  int v35 = v34->timer;
  int v41 = v35 + 1;
  v34->timer = v41;
  int * v37 = v34->regs;
  v37[8] = 96;
  struct StateT * v39 = slot_3(v34);
  return v39;
}

struct StateT * slot_7(struct StateT * v106) {
  int v107 = v106->timer;
  int v116 = v107 + 1;
  v106->timer = v116;
  int * v109 = v106->regs;
  int v110 = v109[9];
  int * v111 = v106->mem;
  int v120 = (int)((unsigned int)v110 >> 2);
  int v112 = v111[v120];
  v109[11] = v112;
  struct StateT * v114 = slot_8(v106);
  return v114;
}

struct StateT * slot_3(struct StateT * v47) {
  int v48 = v47->timer;
  int v54 = v48 + 1;
  v47->timer = v54;
  int * v50 = v47->regs;
  v50[9] = 0;
  struct StateT * v52 = slot_4(v47);
  return v52;
}

struct StateT * slot_0(struct StateT * v2) {
  int v3 = v2->timer;
  int v9 = v3 + 1;
  v2->timer = v9;
  int * v5 = v2->regs;
  v5[6] = 80;
  struct StateT * v7 = slot_1(v2);
  return v7;
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
  //@ assert untainted_timer: !\tainted(s1_->timer==s2_->timer);
  koika_assert(s1_->timer==s2_->timer, "timing leak");
  return 0;
}