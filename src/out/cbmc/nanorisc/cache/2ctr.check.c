// verify: leak (CBMC should report VERIFICATION FAILED) [unwind 31]
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
struct StateT * slot_1(struct StateT * x19);
struct StateT * slot_2(struct StateT * x123);
struct StateT * slot_0(struct StateT * x2);
struct StateT * snippet(struct StateT * x0) {
  struct StateT * x1 = slot_0(x0);
  return x1;
}

struct StateT * slot_1(struct StateT * x19) {
  int x20 = x19->timer;
  int x78 = x20 + 1;
  x19->timer = x78;
  int * x22 = x19->regs;
  int x23 = x22[0];
  int * x24 = x19->cache_keys;
  int x25 = x24[0];
  bool x82 = x25 == x23;
  int x73;
  if (x82) {
    int * x26 = x19->cache_vals;
    int x27 = x26[0];
    x73 = x27;
  } else {
    int * x29 = x19->cache_keys;
    int x30 = x29[1];
    bool x87 = x30 == x23;
    int x71;
    if (x87) {
      int * x31 = x19->cache_vals;
      int x32 = x31[1];
      int * x33 = x19->cache_keys;
      int * x34 = x19->cache_keys;
      int x35 = x34[0];
      x33[1] = x35;
      int * x37 = x19->cache_vals;
      int * x38 = x19->cache_vals;
      int x39 = x38[0];
      x37[1] = x39;
      int * x41 = x19->cache_keys;
      x41[0] = x23;
      int * x43 = x19->cache_vals;
      x43[0] = x32;
      int x45 = x19->timer;
      int x99 = x45 + 1;
      x19->timer = x99;
      x71 = x32;
    } else {
      int * x48 = x19->mem;
      int x49 = x48[x23];
      int * x50 = x19->mem;
      int * x51 = x19->cache_keys;
      int x52 = x51[1];
      int * x53 = x19->cache_vals;
      int x54 = x53[1];
      x50[x52] = x54;
      int * x56 = x19->cache_keys;
      int * x57 = x19->cache_keys;
      int x58 = x57[0];
      x56[1] = x58;
      int * x60 = x19->cache_vals;
      int * x61 = x19->cache_vals;
      int x62 = x61[0];
      x60[1] = x62;
      int * x64 = x19->cache_keys;
      x64[0] = x23;
      int * x66 = x19->cache_vals;
      x66[0] = x49;
      int x68 = x19->timer;
      int x116 = x68 + 100;
      x19->timer = x116;
      x71 = x49;
    }
    x73 = x71;
  }
  int * x74 = x19->regs;
  x74[1] = x73;
  struct StateT * x76 = slot_2(x19);
  return x76;
}

struct StateT * slot_2(struct StateT * x123) {
  int x124 = x123->timer;
  int x181 = x124 + 1;
  x123->timer = x181;
  int * x126 = x123->regs;
  int x127 = x126[1];
  int * x128 = x123->cache_keys;
  int x129 = x128[0];
  bool x186 = x129 == (x127 + 4);
  int x177;
  if (x186) {
    int * x130 = x123->cache_vals;
    int x131 = x130[0];
    x177 = x131;
  } else {
    int * x133 = x123->cache_keys;
    int x134 = x133[1];
    bool x190 = x134 == (x127 + 4);
    int x175;
    if (x190) {
      int * x135 = x123->cache_vals;
      int x136 = x135[1];
      int * x137 = x123->cache_keys;
      int * x138 = x123->cache_keys;
      int x139 = x138[0];
      x137[1] = x139;
      int * x141 = x123->cache_vals;
      int * x142 = x123->cache_vals;
      int x143 = x142[0];
      x141[1] = x143;
      int * x145 = x123->cache_keys;
      int x199 = x127 + 4;
      x145[0] = x199;
      int * x147 = x123->cache_vals;
      x147[0] = x136;
      int x149 = x123->timer;
      int x202 = x149 + 1;
      x123->timer = x202;
      x175 = x136;
    } else {
      int * x152 = x123->mem;
      int x204 = x127 + 4;
      int x153 = x152[x204];
      int * x154 = x123->mem;
      int * x155 = x123->cache_keys;
      int x156 = x155[1];
      int * x157 = x123->cache_vals;
      int x158 = x157[1];
      x154[x156] = x158;
      int * x160 = x123->cache_keys;
      int * x161 = x123->cache_keys;
      int x162 = x161[0];
      x160[1] = x162;
      int * x164 = x123->cache_vals;
      int * x165 = x123->cache_vals;
      int x166 = x165[0];
      x164[1] = x166;
      int * x168 = x123->cache_keys;
      x168[0] = x204;
      int * x170 = x123->cache_vals;
      x170[0] = x153;
      int x172 = x123->timer;
      int x219 = x172 + 100;
      x123->timer = x219;
      x175 = x153;
    }
    x177 = x175;
  }
  int * x178 = x123->regs;
  x178[2] = x177;
  return x123;
}

struct StateT * slot_0(struct StateT * x2) {
  int x3 = x2->timer;
  int x12 = x3 + 1;
  x2->timer = x12;
  int * x5 = x2->regs;
  int x6 = x5[0];
  bool x15 = x6 == 0;
  struct StateT * x10;
  if (x15) {
    x10 = x2;
  } else {
    struct StateT * x8 = slot_1(x2);
    x10 = x8;
  }
  return x10;
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