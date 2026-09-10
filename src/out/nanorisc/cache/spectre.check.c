
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
struct StateT * x20(struct StateT * x21);
struct StateT * x7(struct StateT * x8);
struct StateT * x80(struct StateT * x81);
struct StateT * x13(struct StateT * x14);
struct StateT * snippet(struct StateT * x0) {
  struct StateT * x258 = x1(x0);
  return x258;
}

struct StateT * x1(struct StateT * x2) {
  int x3 = x2->timer;
  int x252 = x3 + 1;
  x2->timer = x252;int * x5 = x2->regs;
  x5[3] = 0;
  struct StateT * x250 = x7(x2);
  return x250;
}

struct StateT * x20(struct StateT * x21) {
  int x22 = x21->timer;
  int x184 = x22 + 1;
  x21->timer = x184;int * x24 = x21->regs;
  int x25 = x24[3];
  int * x26 = x21->regs;
  int x27 = x26[0];
  int * x28 = x21->cache_keys;
  int x29 = x28[0];
  bool x190 = x29 == (x25 + x27);
  int x77 = (x190 ? ({
    int * x30 = x21->cache_vals;
    int x31 = x30[0];
    x31;
  }) : ({
    int * x33 = x21->cache_keys;
    int x34 = x33[1];
    bool x195 = x34 == (x25 + x27);
    int x75 = (x195 ? ({
      int * x35 = x21->cache_vals;
      int x36 = x35[1];
      int * x37 = x21->cache_keys;
      int * x38 = x21->cache_keys;
      int x39 = x38[0];
      x37[1] = x39;
      int * x41 = x21->cache_vals;
      int * x42 = x21->cache_vals;
      int x43 = x42[0];
      x41[1] = x43;
      int * x45 = x21->cache_keys;
      int x204 = x25 + x27;
      x45[0] = x204;
      int * x47 = x21->cache_vals;
      x47[0] = x36;
      int x49 = x21->timer;
      int x207 = x49 + 1;
      x21->timer = x207;x36;
    }) : ({
      int * x52 = x21->mem;
      int x209 = x25 + x27;
      int x53 = x52[x209];
      int * x54 = x21->mem;
      int * x55 = x21->cache_keys;
      int x56 = x55[1];
      int * x57 = x21->cache_vals;
      int x58 = x57[1];
      x54[x56] = x58;
      int * x60 = x21->cache_keys;
      int * x61 = x21->cache_keys;
      int x62 = x61[0];
      x60[1] = x62;
      int * x64 = x21->cache_vals;
      int * x65 = x21->cache_vals;
      int x66 = x65[0];
      x64[1] = x66;
      int * x68 = x21->cache_keys;
      x68[0] = x209;
      int * x70 = x21->cache_vals;
      x70[0] = x53;
      int x72 = x21->timer;
      int x224 = x72 + 100;
      x21->timer = x224;x53;
    }));
    x75;
  }));
  int * x78 = x21->regs;
  x78[1] = x77;
  struct StateT * x182 = x80(x21);
  return x182;
}

struct StateT * x7(struct StateT * x8) {
  int x9 = x8->timer;
  int x244 = x9 + 1;
  x8->timer = x244;int * x11 = x8->regs;
  x11[0] = 20;
  struct StateT * x242 = x13(x8);
  return x242;
}

struct StateT * x80(struct StateT * x81) {
  int x82 = x81->timer;
  int x139 = x82 + 1;
  x81->timer = x139;int * x84 = x81->regs;
  int x85 = x84[1];
  int * x86 = x81->cache_keys;
  int x87 = x86[0];
  bool x144 = x87 == x85;
  int x135 = (x144 ? ({
    int * x88 = x81->cache_vals;
    int x89 = x88[0];
    x89;
  }) : ({
    int * x91 = x81->cache_keys;
    int x92 = x91[1];
    bool x148 = x92 == x85;
    int x133 = (x148 ? ({
      int * x93 = x81->cache_vals;
      int x94 = x93[1];
      int * x95 = x81->cache_keys;
      int * x96 = x81->cache_keys;
      int x97 = x96[0];
      x95[1] = x97;
      int * x99 = x81->cache_vals;
      int * x100 = x81->cache_vals;
      int x101 = x100[0];
      x99[1] = x101;
      int * x103 = x81->cache_keys;
      x103[0] = x85;
      int * x105 = x81->cache_vals;
      x105[0] = x94;
      int x107 = x81->timer;
      int x160 = x107 + 1;
      x81->timer = x160;x94;
    }) : ({
      int * x110 = x81->mem;
      int x111 = x110[x85];
      int * x112 = x81->mem;
      int * x113 = x81->cache_keys;
      int x114 = x113[1];
      int * x115 = x81->cache_vals;
      int x116 = x115[1];
      x112[x114] = x116;
      int * x118 = x81->cache_keys;
      int * x119 = x81->cache_keys;
      int x120 = x119[0];
      x118[1] = x120;
      int * x122 = x81->cache_vals;
      int * x123 = x81->cache_vals;
      int x124 = x123[0];
      x122[1] = x124;
      int * x126 = x81->cache_keys;
      x126[0] = x85;
      int * x128 = x81->cache_vals;
      x128[0] = x111;
      int x130 = x81->timer;
      int x177 = x130 + 100;
      x81->timer = x177;x111;
    }));
    x133;
  }));
  int * x136 = x81->regs;
  x136[2] = x135;
  return x81;
}

struct StateT * x13(struct StateT * x14) {
  int x15 = x14->timer;
  int x235 = x15 + 1;
  x14->timer = x235;int * x17 = x14->regs;
  int x18 = x17[0];
  bool x238 = x18 >= 20;
  struct StateT * x233 = (x238 ? x14 : ({
    struct StateT * x231 = x20(x14);
    x231;
  }));
  return x233;
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