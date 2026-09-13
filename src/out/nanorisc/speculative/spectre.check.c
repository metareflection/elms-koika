// verify: leak (CBMC should report VERIFICATION FAILED)

#define NUM_REGS 8
#define MEM_SIZE 30
#define SECRET_SIZE 10
#define SECRET_OFFSET 20
#define CACHE_LRU_SIZE 10
#ifndef CBMC
#define __CPROVER_assert(b,s) 0
#define nondet_uint() 0
#else
int nondet_uint();
#endif
int bounded(int low, int high) {
  int x = nondet_uint();
  __CPROVER_assume(low <= x && x <= high);
  return x;
}
struct StateT {
  int regs[NUM_REGS];
  int mem[MEM_SIZE];
  int saved_regs[NUM_REGS];
  int cache_keys[CACHE_LRU_SIZE];
  int cache_vals[CACHE_LRU_SIZE];
  int timer;
};

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

/*****************************************
Emitting C Generated Code
*******************************************/

#include <stdbool.h>
#include <stdlib.h>

struct StateT * snippet(struct StateT * x0);
struct StateT * x1(struct StateT * x2);
struct StateT * x7(struct StateT * x8);
struct StateT * x13(struct StateT * x14);
struct StateT * snippet(struct StateT * x0) {
  struct StateT * x271 = x1(x0);
  return x271;
}

struct StateT * x1(struct StateT * x2) {
  int x3 = x2->timer;
  int x265 = x3 + 1;
  x2->timer = x265;int * x5 = x2->regs;
  x5[3] = 0;
  struct StateT * x263 = x7(x2);
  return x263;
}

struct StateT * x7(struct StateT * x8) {
  int x9 = x8->timer;
  int x257 = x9 + 1;
  x8->timer = x257;int * x11 = x8->regs;
  x11[0] = 20;
  struct StateT * x255 = x13(x8);
  return x255;
}

struct StateT * x13(struct StateT * x14) {
  int * x15 = x14->saved_regs;
  int * x16 = x14->regs;
  int x17 = x16[1];
  x15[1] = x17;
  int x19 = x14->timer;
  int x157 = x19 + 1;
  x14->timer = x157;int * x21 = x14->regs;
  int x22 = x21[3];
  int * x23 = x14->regs;
  int x24 = x23[0];
  int * x25 = x14->cache_keys;
  int x26 = x25[0];
  bool x163 = x26 == (x22 + x24);
  int x74 = (x163 ? ({
    int * x27 = x14->cache_vals;
    int x28 = x27[0];
    x28;
  }) : ({
    int * x30 = x14->cache_keys;
    int x31 = x30[1];
    bool x167 = x31 == (x22 + x24);
    int x72 = (x167 ? ({
      int * x32 = x14->cache_vals;
      int x33 = x32[1];
      int * x34 = x14->cache_keys;
      int * x35 = x14->cache_keys;
      int x36 = x35[0];
      x34[1] = x36;
      int * x38 = x14->cache_vals;
      int * x39 = x14->cache_vals;
      int x40 = x39[0];
      x38[1] = x40;
      int * x42 = x14->cache_keys;
      int x176 = x22 + x24;
      x42[0] = x176;
      int * x44 = x14->cache_vals;
      x44[0] = x33;
      int x46 = x14->timer;
      int x179 = x46 + 1;
      x14->timer = x179;x33;
    }) : ({
      int * x49 = x14->mem;
      int x181 = x22 + x24;
      int x50 = x49[x181];
      int * x51 = x14->mem;
      int * x52 = x14->cache_keys;
      int x53 = x52[1];
      int * x54 = x14->cache_vals;
      int x55 = x54[1];
      x51[x53] = x55;
      int * x57 = x14->cache_keys;
      int * x58 = x14->cache_keys;
      int x59 = x58[0];
      x57[1] = x59;
      int * x61 = x14->cache_vals;
      int * x62 = x14->cache_vals;
      int x63 = x62[0];
      x61[1] = x63;
      int * x65 = x14->cache_keys;
      x65[0] = x181;
      int * x67 = x14->cache_vals;
      x67[0] = x50;
      int x69 = x14->timer;
      int x196 = x69 + 100;
      x14->timer = x196;x50;
    }));
    x72;
  }));
  int * x75 = x14->regs;
  x75[1] = x74;
  int * x77 = x14->saved_regs;
  int * x78 = x14->regs;
  int x79 = x78[2];
  x77[2] = x79;
  int x81 = x14->timer;
  int x204 = x81 + 1;
  x14->timer = x204;int * x83 = x14->regs;
  int x84 = x83[1];
  int * x85 = x14->cache_keys;
  int x86 = x85[0];
  bool x207 = x86 == x84;
  int x134 = (x207 ? ({
    int * x87 = x14->cache_vals;
    int x88 = x87[0];
    x88;
  }) : ({
    int * x90 = x14->cache_keys;
    int x91 = x90[1];
    bool x211 = x91 == x84;
    int x132 = (x211 ? ({
      int * x92 = x14->cache_vals;
      int x93 = x92[1];
      int * x94 = x14->cache_keys;
      int * x95 = x14->cache_keys;
      int x96 = x95[0];
      x94[1] = x96;
      int * x98 = x14->cache_vals;
      int * x99 = x14->cache_vals;
      int x100 = x99[0];
      x98[1] = x100;
      int * x102 = x14->cache_keys;
      x102[0] = x84;
      int * x104 = x14->cache_vals;
      x104[0] = x93;
      int x106 = x14->timer;
      int x223 = x106 + 1;
      x14->timer = x223;x93;
    }) : ({
      int * x109 = x14->mem;
      int x110 = x109[x84];
      int * x111 = x14->mem;
      int * x112 = x14->cache_keys;
      int x113 = x112[1];
      int * x114 = x14->cache_vals;
      int x115 = x114[1];
      x111[x113] = x115;
      int * x117 = x14->cache_keys;
      int * x118 = x14->cache_keys;
      int x119 = x118[0];
      x117[1] = x119;
      int * x121 = x14->cache_vals;
      int * x122 = x14->cache_vals;
      int x123 = x122[0];
      x121[1] = x123;
      int * x125 = x14->cache_keys;
      x125[0] = x84;
      int * x127 = x14->cache_vals;
      x127[0] = x110;
      int x129 = x14->timer;
      int x240 = x129 + 100;
      x14->timer = x240;x110;
    }));
    x132;
  }));
  int * x135 = x14->regs;
  x135[2] = x134;
  int * x137 = x14->regs;
  int x138 = x137[0];
  bool x245 = x138 >= 20;
  if (x245) {
    int x139 = x14->timer;
    int x246 = x139 + 15;
    x14->timer = x246;int * x141 = x14->saved_regs;
    int x142 = x141[1];
    int * x143 = x14->regs;
    x143[1] = x142;
    int * x145 = x14->saved_regs;
    int x146 = x145[2];
    int * x147 = x14->regs;
    x147[2] = x146;
    ;
  } else {
    ;
  }
  return x14;
}



/*****************************************
End of C Generated Code
*******************************************/

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
  __CPROVER_assert(s1_->timer==s2_->timer, "timing leak");
  return 0;
}