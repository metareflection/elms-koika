// verify: leak (KLEE should report a failing assertion) [budget 120s]
#define NUM_REGS 8
#define MEM_SIZE 30
#define SECRET_SIZE 10
#define SECRET_OFFSET 20
#define CACHE_LRU_SIZE 10

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
  int regs[8];
  int mem[30];
  int saved_regs[8];
  int cache_keys[10];
  int cache_vals[10];
  int timer;
};

struct StateT * snippet(struct StateT * x0);
struct StateT * slot_1(struct StateT * x15);
struct StateT * slot_2(struct StateT * x28);
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

struct StateT * slot_2(struct StateT * x28) {
  int * x29 = x28->saved_regs;
  int * x30 = x28->regs;
  int x31 = x30[1];
  x29[1] = x31;
  int x33 = x28->timer;
  int x171 = x33 + 1;
  x28->timer = x171;
  int * x35 = x28->regs;
  int x36 = x35[3];
  int * x37 = x28->regs;
  int x38 = x37[0];
  int * x39 = x28->cache_keys;
  int x40 = x39[0];
  bool x177 = x40 == (x36 + x38);
  int x88;
  if (x177) {
    int * x41 = x28->cache_vals;
    int x42 = x41[0];
    x88 = x42;
  } else {
    int * x44 = x28->cache_keys;
    int x45 = x44[1];
    bool x181 = x45 == (x36 + x38);
    int x86;
    if (x181) {
      int * x46 = x28->cache_vals;
      int x47 = x46[1];
      int * x48 = x28->cache_keys;
      int * x49 = x28->cache_keys;
      int x50 = x49[0];
      x48[1] = x50;
      int * x52 = x28->cache_vals;
      int * x53 = x28->cache_vals;
      int x54 = x53[0];
      x52[1] = x54;
      int * x56 = x28->cache_keys;
      int x190 = x36 + x38;
      x56[0] = x190;
      int * x58 = x28->cache_vals;
      x58[0] = x47;
      int x60 = x28->timer;
      int x193 = x60 + 1;
      x28->timer = x193;
      x86 = x47;
    } else {
      int * x63 = x28->mem;
      int x195 = x36 + x38;
      int x64 = x63[x195];
      int * x65 = x28->mem;
      int * x66 = x28->cache_keys;
      int x67 = x66[1];
      int * x68 = x28->cache_vals;
      int x69 = x68[1];
      x65[x67] = x69;
      int * x71 = x28->cache_keys;
      int * x72 = x28->cache_keys;
      int x73 = x72[0];
      x71[1] = x73;
      int * x75 = x28->cache_vals;
      int * x76 = x28->cache_vals;
      int x77 = x76[0];
      x75[1] = x77;
      int * x79 = x28->cache_keys;
      x79[0] = x195;
      int * x81 = x28->cache_vals;
      x81[0] = x64;
      int x83 = x28->timer;
      int x210 = x83 + 100;
      x28->timer = x210;
      x86 = x64;
    }
    x88 = x86;
  }
  int * x89 = x28->regs;
  x89[1] = x88;
  int * x91 = x28->saved_regs;
  int * x92 = x28->regs;
  int x93 = x92[2];
  x91[2] = x93;
  int x95 = x28->timer;
  int x218 = x95 + 1;
  x28->timer = x218;
  int * x97 = x28->regs;
  int x98 = x97[1];
  int * x99 = x28->cache_keys;
  int x100 = x99[0];
  bool x221 = x100 == x98;
  int x148;
  if (x221) {
    int * x101 = x28->cache_vals;
    int x102 = x101[0];
    x148 = x102;
  } else {
    int * x104 = x28->cache_keys;
    int x105 = x104[1];
    bool x225 = x105 == x98;
    int x146;
    if (x225) {
      int * x106 = x28->cache_vals;
      int x107 = x106[1];
      int * x108 = x28->cache_keys;
      int * x109 = x28->cache_keys;
      int x110 = x109[0];
      x108[1] = x110;
      int * x112 = x28->cache_vals;
      int * x113 = x28->cache_vals;
      int x114 = x113[0];
      x112[1] = x114;
      int * x116 = x28->cache_keys;
      x116[0] = x98;
      int * x118 = x28->cache_vals;
      x118[0] = x107;
      int x120 = x28->timer;
      int x237 = x120 + 1;
      x28->timer = x237;
      x146 = x107;
    } else {
      int * x123 = x28->mem;
      int x124 = x123[x98];
      int * x125 = x28->mem;
      int * x126 = x28->cache_keys;
      int x127 = x126[1];
      int * x128 = x28->cache_vals;
      int x129 = x128[1];
      x125[x127] = x129;
      int * x131 = x28->cache_keys;
      int * x132 = x28->cache_keys;
      int x133 = x132[0];
      x131[1] = x133;
      int * x135 = x28->cache_vals;
      int * x136 = x28->cache_vals;
      int x137 = x136[0];
      x135[1] = x137;
      int * x139 = x28->cache_keys;
      x139[0] = x98;
      int * x141 = x28->cache_vals;
      x141[0] = x124;
      int x143 = x28->timer;
      int x254 = x143 + 100;
      x28->timer = x254;
      x146 = x124;
    }
    x148 = x146;
  }
  int * x149 = x28->regs;
  x149[2] = x148;
  int * x151 = x28->regs;
  int x152 = x151[0];
  bool x259 = x152 >= 20;
  if (x259) {
    int x153 = x28->timer;
    int x260 = x153 + 15;
    x28->timer = x260;
    int * x155 = x28->saved_regs;
    int x156 = x155[1];
    int * x157 = x28->regs;
    x157[1] = x156;
    int * x159 = x28->saved_regs;
    int x160 = x159[2];
    int * x161 = x28->regs;
    x161[2] = x160;
    ;
  } else {
    ;
  }
  return x28;
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
    s->saved_regs[i] = 0;
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