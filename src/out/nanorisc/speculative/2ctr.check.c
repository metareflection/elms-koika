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
struct StateT * x1(struct StateT * x2);
struct StateT * snippet(struct StateT * x0) {
  struct StateT * x239 = x1(x0);
  return x239;
}

struct StateT * x1(struct StateT * x2) {
  int * x3 = x2->saved_regs;
  int * x4 = x2->regs;
  int x5 = x4[1];
  x3[1] = x5;
  int x7 = x2->timer;
  int x143 = x7 + 1;
  x2->timer = x143;
  int * x9 = x2->regs;
  int x10 = x9[0];
  int * x11 = x2->cache_keys;
  int x12 = x11[0];
  bool x147 = x12 == x10;
  int x60;
  if (x147) {
    int * x13 = x2->cache_vals;
    int x14 = x13[0];
    x60 = x14;
  } else {
    int * x16 = x2->cache_keys;
    int x17 = x16[1];
    bool x151 = x17 == x10;
    int x58;
    if (x151) {
      int * x18 = x2->cache_vals;
      int x19 = x18[1];
      int * x20 = x2->cache_keys;
      int * x21 = x2->cache_keys;
      int x22 = x21[0];
      x20[1] = x22;
      int * x24 = x2->cache_vals;
      int * x25 = x2->cache_vals;
      int x26 = x25[0];
      x24[1] = x26;
      int * x28 = x2->cache_keys;
      x28[0] = x10;
      int * x30 = x2->cache_vals;
      x30[0] = x19;
      int x32 = x2->timer;
      int x163 = x32 + 1;
      x2->timer = x163;
      x58 = x19;
    } else {
      int * x35 = x2->mem;
      int x36 = x35[x10];
      int * x37 = x2->mem;
      int * x38 = x2->cache_keys;
      int x39 = x38[1];
      int * x40 = x2->cache_vals;
      int x41 = x40[1];
      x37[x39] = x41;
      int * x43 = x2->cache_keys;
      int * x44 = x2->cache_keys;
      int x45 = x44[0];
      x43[1] = x45;
      int * x47 = x2->cache_vals;
      int * x48 = x2->cache_vals;
      int x49 = x48[0];
      x47[1] = x49;
      int * x51 = x2->cache_keys;
      x51[0] = x10;
      int * x53 = x2->cache_vals;
      x53[0] = x36;
      int x55 = x2->timer;
      int x180 = x55 + 100;
      x2->timer = x180;
      x58 = x36;
    }
    x60 = x58;
  }
  int * x61 = x2->regs;
  x61[1] = x60;
  int * x63 = x2->saved_regs;
  int * x64 = x2->regs;
  int x65 = x64[2];
  x63[2] = x65;
  int x67 = x2->timer;
  int x188 = x67 + 1;
  x2->timer = x188;
  int * x69 = x2->regs;
  int x70 = x69[1];
  int * x71 = x2->cache_keys;
  int x72 = x71[0];
  bool x191 = x72 == (x70 + 4);
  int x120;
  if (x191) {
    int * x73 = x2->cache_vals;
    int x74 = x73[0];
    x120 = x74;
  } else {
    int * x76 = x2->cache_keys;
    int x77 = x76[1];
    bool x195 = x77 == (x70 + 4);
    int x118;
    if (x195) {
      int * x78 = x2->cache_vals;
      int x79 = x78[1];
      int * x80 = x2->cache_keys;
      int * x81 = x2->cache_keys;
      int x82 = x81[0];
      x80[1] = x82;
      int * x84 = x2->cache_vals;
      int * x85 = x2->cache_vals;
      int x86 = x85[0];
      x84[1] = x86;
      int * x88 = x2->cache_keys;
      int x204 = x70 + 4;
      x88[0] = x204;
      int * x90 = x2->cache_vals;
      x90[0] = x79;
      int x92 = x2->timer;
      int x207 = x92 + 1;
      x2->timer = x207;
      x118 = x79;
    } else {
      int * x95 = x2->mem;
      int x209 = x70 + 4;
      int x96 = x95[x209];
      int * x97 = x2->mem;
      int * x98 = x2->cache_keys;
      int x99 = x98[1];
      int * x100 = x2->cache_vals;
      int x101 = x100[1];
      x97[x99] = x101;
      int * x103 = x2->cache_keys;
      int * x104 = x2->cache_keys;
      int x105 = x104[0];
      x103[1] = x105;
      int * x107 = x2->cache_vals;
      int * x108 = x2->cache_vals;
      int x109 = x108[0];
      x107[1] = x109;
      int * x111 = x2->cache_keys;
      x111[0] = x209;
      int * x113 = x2->cache_vals;
      x113[0] = x96;
      int x115 = x2->timer;
      int x224 = x115 + 100;
      x2->timer = x224;
      x118 = x96;
    }
    x120 = x118;
  }
  int * x121 = x2->regs;
  x121[2] = x120;
  int * x123 = x2->regs;
  int x124 = x123[0];
  bool x229 = x124 == 0;
  if (x229) {
    int x125 = x2->timer;
    int x230 = x125 + 15;
    x2->timer = x230;
    int * x127 = x2->saved_regs;
    int x128 = x127[1];
    int * x129 = x2->regs;
    x129[1] = x128;
    int * x131 = x2->saved_regs;
    int x132 = x131[2];
    int * x133 = x2->regs;
    x133[2] = x132;
    ;
  } else {
    ;
  }
  return x2;
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
  __CPROVER_assert(s1_->timer==s2_->timer, "timing leak");
  return 0;
}