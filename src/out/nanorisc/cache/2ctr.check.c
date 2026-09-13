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
struct StateT * x8(struct StateT * x9);
struct StateT * x66(struct StateT * x67);
struct StateT * snippet(struct StateT * x0) {
  struct StateT * x226 = x1(x0);
  return x226;
}

struct StateT * x1(struct StateT * x2) {
  int x3 = x2->timer;
  int x219 = x3 + 1;
  x2->timer = x219;int * x5 = x2->regs;
  int x6 = x5[0];
  bool x222 = x6 == 0;
  struct StateT * x217 = (x222 ? x2 : ({
    struct StateT * x215 = x8(x2);
    x215;
  }));
  return x217;
}

struct StateT * x8(struct StateT * x9) {
  int x10 = x9->timer;
  int x170 = x10 + 1;
  x9->timer = x170;int * x12 = x9->regs;
  int x13 = x12[0];
  int * x14 = x9->cache_keys;
  int x15 = x14[0];
  bool x174 = x15 == x13;
  int x63 = (x174 ? ({
    int * x16 = x9->cache_vals;
    int x17 = x16[0];
    x17;
  }) : ({
    int * x19 = x9->cache_keys;
    int x20 = x19[1];
    bool x179 = x20 == x13;
    int x61 = (x179 ? ({
      int * x21 = x9->cache_vals;
      int x22 = x21[1];
      int * x23 = x9->cache_keys;
      int * x24 = x9->cache_keys;
      int x25 = x24[0];
      x23[1] = x25;
      int * x27 = x9->cache_vals;
      int * x28 = x9->cache_vals;
      int x29 = x28[0];
      x27[1] = x29;
      int * x31 = x9->cache_keys;
      x31[0] = x13;
      int * x33 = x9->cache_vals;
      x33[0] = x22;
      int x35 = x9->timer;
      int x191 = x35 + 1;
      x9->timer = x191;x22;
    }) : ({
      int * x38 = x9->mem;
      int x39 = x38[x13];
      int * x40 = x9->mem;
      int * x41 = x9->cache_keys;
      int x42 = x41[1];
      int * x43 = x9->cache_vals;
      int x44 = x43[1];
      x40[x42] = x44;
      int * x46 = x9->cache_keys;
      int * x47 = x9->cache_keys;
      int x48 = x47[0];
      x46[1] = x48;
      int * x50 = x9->cache_vals;
      int * x51 = x9->cache_vals;
      int x52 = x51[0];
      x50[1] = x52;
      int * x54 = x9->cache_keys;
      x54[0] = x13;
      int * x56 = x9->cache_vals;
      x56[0] = x39;
      int x58 = x9->timer;
      int x208 = x58 + 100;
      x9->timer = x208;x39;
    }));
    x61;
  }));
  int * x64 = x9->regs;
  x64[1] = x63;
  struct StateT * x168 = x66(x9);
  return x168;
}

struct StateT * x66(struct StateT * x67) {
  int x68 = x67->timer;
  int x125 = x68 + 1;
  x67->timer = x125;int * x70 = x67->regs;
  int x71 = x70[1];
  int * x72 = x67->cache_keys;
  int x73 = x72[0];
  bool x130 = x73 == (x71 + 4);
  int x121 = (x130 ? ({
    int * x74 = x67->cache_vals;
    int x75 = x74[0];
    x75;
  }) : ({
    int * x77 = x67->cache_keys;
    int x78 = x77[1];
    bool x134 = x78 == (x71 + 4);
    int x119 = (x134 ? ({
      int * x79 = x67->cache_vals;
      int x80 = x79[1];
      int * x81 = x67->cache_keys;
      int * x82 = x67->cache_keys;
      int x83 = x82[0];
      x81[1] = x83;
      int * x85 = x67->cache_vals;
      int * x86 = x67->cache_vals;
      int x87 = x86[0];
      x85[1] = x87;
      int * x89 = x67->cache_keys;
      int x143 = x71 + 4;
      x89[0] = x143;
      int * x91 = x67->cache_vals;
      x91[0] = x80;
      int x93 = x67->timer;
      int x146 = x93 + 1;
      x67->timer = x146;x80;
    }) : ({
      int * x96 = x67->mem;
      int x148 = x71 + 4;
      int x97 = x96[x148];
      int * x98 = x67->mem;
      int * x99 = x67->cache_keys;
      int x100 = x99[1];
      int * x101 = x67->cache_vals;
      int x102 = x101[1];
      x98[x100] = x102;
      int * x104 = x67->cache_keys;
      int * x105 = x67->cache_keys;
      int x106 = x105[0];
      x104[1] = x106;
      int * x108 = x67->cache_vals;
      int * x109 = x67->cache_vals;
      int x110 = x109[0];
      x108[1] = x110;
      int * x112 = x67->cache_keys;
      x112[0] = x148;
      int * x114 = x67->cache_vals;
      x114[0] = x97;
      int x116 = x67->timer;
      int x163 = x116 + 100;
      x67->timer = x163;x97;
    }));
    x119;
  }));
  int * x122 = x67->regs;
  x122[2] = x121;
  return x67;
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