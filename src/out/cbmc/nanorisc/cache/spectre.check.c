// verify: clean (CBMC should report VERIFICATION SUCCESSFUL) [unwind 31]
#define NUM_REGS 8
#define MEM_SIZE 30
#define SECRET_SIZE 10
#define SECRET_OFFSET 20
#define CACHE_LRU_SIZE 10

#ifdef CBMC
int nondet_uint();
#define koika_assert(b, s) __CPROVER_assert(b, s)
#define koika_assume(b) __CPROVER_assume(b)
#define koika_draw(x) ((x) = nondet_uint())
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
  int regs[8];
  int mem[30];
  int saved_regs[8];
  int cache_keys[10];
  int cache_vals[10];
  int timer;
};

struct StateT * snippet(struct StateT * x0);
struct StateT * slot_1(struct StateT * x15);
struct StateT * slot_4(struct StateT * x153);
struct StateT * slot_2(struct StateT * x28);
struct StateT * slot_3(struct StateT * x45);
struct StateT * slot_0(struct StateT * x2);
struct StateT * snippet(struct StateT * x0) {
  struct StateT * x1 = slot_0(x0);
  return x1;
}

struct StateT * slot_1(struct StateT * x15) {
  int x16 = x15->timer;
  int x22 = x16 + 1;
  x15->timer = x22;
  int * x18 = x15->regs;
  x18[0] = 20;
  struct StateT * x20 = slot_2(x15);
  return x20;
}

struct StateT * slot_4(struct StateT * x153) {
  int x154 = x153->timer;
  int x211 = x154 + 1;
  x153->timer = x211;
  int * x156 = x153->regs;
  int x157 = x156[1];
  int * x158 = x153->cache_keys;
  int x159 = x158[0];
  bool x216 = x159 == x157;
  int x207;
  if (x216) {
    int * x160 = x153->cache_vals;
    int x161 = x160[0];
    x207 = x161;
  } else {
    int * x163 = x153->cache_keys;
    int x164 = x163[1];
    bool x220 = x164 == x157;
    int x205;
    if (x220) {
      int * x165 = x153->cache_vals;
      int x166 = x165[1];
      int * x167 = x153->cache_keys;
      int * x168 = x153->cache_keys;
      int x169 = x168[0];
      x167[1] = x169;
      int * x171 = x153->cache_vals;
      int * x172 = x153->cache_vals;
      int x173 = x172[0];
      x171[1] = x173;
      int * x175 = x153->cache_keys;
      x175[0] = x157;
      int * x177 = x153->cache_vals;
      x177[0] = x166;
      int x179 = x153->timer;
      int x232 = x179 + 1;
      x153->timer = x232;
      x205 = x166;
    } else {
      int * x182 = x153->mem;
      int x183 = x182[x157];
      int * x184 = x153->mem;
      int * x185 = x153->cache_keys;
      int x186 = x185[1];
      int * x187 = x153->cache_vals;
      int x188 = x187[1];
      x184[x186] = x188;
      int * x190 = x153->cache_keys;
      int * x191 = x153->cache_keys;
      int x192 = x191[0];
      x190[1] = x192;
      int * x194 = x153->cache_vals;
      int * x195 = x153->cache_vals;
      int x196 = x195[0];
      x194[1] = x196;
      int * x198 = x153->cache_keys;
      x198[0] = x157;
      int * x200 = x153->cache_vals;
      x200[0] = x183;
      int x202 = x153->timer;
      int x249 = x202 + 100;
      x153->timer = x249;
      x205 = x183;
    }
    x207 = x205;
  }
  int * x208 = x153->regs;
  x208[2] = x207;
  return x153;
}

struct StateT * slot_2(struct StateT * x28) {
  int x29 = x28->timer;
  int x38 = x29 + 1;
  x28->timer = x38;
  int * x31 = x28->regs;
  int x32 = x31[0];
  bool x41 = x32 >= 20;
  struct StateT * x36;
  if (x41) {
    x36 = x28;
  } else {
    struct StateT * x34 = slot_3(x28);
    x36 = x34;
  }
  return x36;
}

struct StateT * slot_3(struct StateT * x45) {
  int x46 = x45->timer;
  int x106 = x46 + 1;
  x45->timer = x106;
  int * x48 = x45->regs;
  int x49 = x48[3];
  int * x50 = x45->regs;
  int x51 = x50[0];
  int * x52 = x45->cache_keys;
  int x53 = x52[0];
  bool x112 = x53 == (x49 + x51);
  int x101;
  if (x112) {
    int * x54 = x45->cache_vals;
    int x55 = x54[0];
    x101 = x55;
  } else {
    int * x57 = x45->cache_keys;
    int x58 = x57[1];
    bool x117 = x58 == (x49 + x51);
    int x99;
    if (x117) {
      int * x59 = x45->cache_vals;
      int x60 = x59[1];
      int * x61 = x45->cache_keys;
      int * x62 = x45->cache_keys;
      int x63 = x62[0];
      x61[1] = x63;
      int * x65 = x45->cache_vals;
      int * x66 = x45->cache_vals;
      int x67 = x66[0];
      x65[1] = x67;
      int * x69 = x45->cache_keys;
      int x126 = x49 + x51;
      x69[0] = x126;
      int * x71 = x45->cache_vals;
      x71[0] = x60;
      int x73 = x45->timer;
      int x129 = x73 + 1;
      x45->timer = x129;
      x99 = x60;
    } else {
      int * x76 = x45->mem;
      int x131 = x49 + x51;
      int x77 = x76[x131];
      int * x78 = x45->mem;
      int * x79 = x45->cache_keys;
      int x80 = x79[1];
      int * x81 = x45->cache_vals;
      int x82 = x81[1];
      x78[x80] = x82;
      int * x84 = x45->cache_keys;
      int * x85 = x45->cache_keys;
      int x86 = x85[0];
      x84[1] = x86;
      int * x88 = x45->cache_vals;
      int * x89 = x45->cache_vals;
      int x90 = x89[0];
      x88[1] = x90;
      int * x92 = x45->cache_keys;
      x92[0] = x131;
      int * x94 = x45->cache_vals;
      x94[0] = x77;
      int x96 = x45->timer;
      int x146 = x96 + 100;
      x45->timer = x146;
      x99 = x77;
    }
    x101 = x99;
  }
  int * x102 = x45->regs;
  x102[1] = x101;
  struct StateT * x104 = slot_4(x45);
  return x104;
}

struct StateT * slot_0(struct StateT * x2) {
  int x3 = x2->timer;
  int x9 = x3 + 1;
  x2->timer = x9;
  int * x5 = x2->regs;
  x5[3] = 0;
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
  for (int i=0; i<CACHE_LRU_SIZE; i++) {
    s->cache_keys[i] = -1;
    s->cache_vals[i] = -1;
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
    s1.mem[SECRET_OFFSET+i] = bounded(0, 20);
    s2.mem[SECRET_OFFSET+i] = bounded(0, 20);
  }
  struct StateT *s1_ = snippet(&s1);
  struct StateT *s2_ = snippet(&s2);
  koika_assert(s1_->timer==s2_->timer, "timing leak");
  return 0;
}