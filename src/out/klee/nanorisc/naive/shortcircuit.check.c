// verify: leak (KLEE should report a failing assertion) [budget 1200s]
#define NUM_REGS 8
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

struct StateT {
  int regs[8];
  int mem[64];
  int saved_regs[8];
  int reg_ready[8];
  int cache_tags[12];
  int cache_dirty[12];
  int cache_age[12];
  int cache_vals[24];
  int timer;
};

struct StateT * slot_6(struct StateT * x113);
struct StateT * slot_5(struct StateT * x92);
struct StateT * slot_2(struct StateT * x28);
struct StateT * slot_7(struct StateT * x147);
struct StateT * slot_3(struct StateT * x41);
struct StateT * snippet(struct StateT * x0);
struct StateT * slot_10(struct StateT * x161);
struct StateT * slot_1(struct StateT * x15);
struct StateT * slot_8(struct StateT * x166);
struct StateT * slot_4(struct StateT * x71);
struct StateT * slot_9(struct StateT * x135);
struct StateT * slot_11(struct StateT * x61);
struct StateT * slot_0(struct StateT * x2);
struct StateT * slot_6(struct StateT * x113) {
  int x114 = x113->timer;
  int x125 = x114 + 1;
  x113->timer = x125;
  int * x116 = x113->regs;
  int x117 = x116[0];
  int x118 = x116[1];
  bool x129 = !(x117 == x118);
  struct StateT * x123;
  if (x129) {
    struct StateT * x119 = slot_9(x113);
    x123 = x119;
  } else {
    struct StateT * x121 = slot_7(x113);
    x123 = x121;
  }
  return x123;
}

struct StateT * slot_5(struct StateT * x92) {
  int x93 = x92->timer;
  int x103 = x93 + 1;
  x92->timer = x103;
  int * x95 = x92->regs;
  int x96 = x95[3];
  int x97 = x95[4];
  int * x98 = x92->mem;
  int x108 = x96 + x97;
  int x99 = x98[x108];
  x95[1] = x99;
  struct StateT * x101 = slot_6(x92);
  return x101;
}

struct StateT * slot_2(struct StateT * x28) {
  int x29 = x28->timer;
  int x35 = x29 + 1;
  x28->timer = x35;
  int * x31 = x28->regs;
  x31[4] = 0;
  struct StateT * x33 = slot_3(x28);
  return x33;
}

struct StateT * slot_7(struct StateT * x147) {
  int x148 = x147->timer;
  int x155 = x148 + 1;
  x147->timer = x155;
  int * x150 = x147->regs;
  int x151 = x150[4];
  int x158 = x151 + 1;
  x150[4] = x158;
  struct StateT * x153 = slot_8(x147);
  return x153;
}

struct StateT * slot_3(struct StateT * x41) {
  int x42 = x41->timer;
  int x52 = x42 + 1;
  x41->timer = x52;
  int * x44 = x41->regs;
  int x45 = x44[4];
  bool x55 = x45 >= 4;
  struct StateT * x50;
  if (x55) {
    struct StateT * x46 = slot_11(x41);
    x50 = x46;
  } else {
    struct StateT * x48 = slot_4(x41);
    x50 = x48;
  }
  return x50;
}

struct StateT * snippet(struct StateT * x0) {
  struct StateT * x1 = slot_0(x0);
  return x1;
}

struct StateT * slot_10(struct StateT * x161) {
  int x162 = x161->timer;
  int x165 = x162 + 1;
  x161->timer = x165;
  return x161;
}

struct StateT * slot_1(struct StateT * x15) {
  int x16 = x15->timer;
  int x22 = x16 + 1;
  x15->timer = x22;
  int * x18 = x15->regs;
  x18[3] = 20;
  struct StateT * x20 = slot_2(x15);
  return x20;
}

struct StateT * slot_8(struct StateT * x166) {
  int x167 = x166->timer;
  int x171 = x167 + 1;
  x166->timer = x171;
  struct StateT * x169 = slot_3(x166);
  return x169;
}

struct StateT * slot_4(struct StateT * x71) {
  int x72 = x71->timer;
  int x82 = x72 + 1;
  x71->timer = x82;
  int * x74 = x71->regs;
  int x75 = x74[2];
  int x76 = x74[4];
  int * x77 = x71->mem;
  int x87 = x75 + x76;
  int x78 = x77[x87];
  x74[0] = x78;
  struct StateT * x80 = slot_5(x71);
  return x80;
}

struct StateT * slot_9(struct StateT * x135) {
  int x136 = x135->timer;
  int x142 = x136 + 1;
  x135->timer = x142;
  int * x138 = x135->regs;
  x138[0] = 0;
  struct StateT * x140 = slot_10(x135);
  return x140;
}

struct StateT * slot_11(struct StateT * x61) {
  int x62 = x61->timer;
  int x67 = x62 + 1;
  x61->timer = x67;
  int * x64 = x61->regs;
  x64[0] = 1;
  return x61;
}

struct StateT * slot_0(struct StateT * x2) {
  int x3 = x2->timer;
  int x9 = x3 + 1;
  x2->timer = x9;
  int * x5 = x2->regs;
  x5[2] = 0;
  struct StateT * x7 = slot_1(x2);
  return x7;
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
  
  int x = bounded(0, 20);
  s1.regs[0] = x;
  s2.regs[0] = x;
  
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