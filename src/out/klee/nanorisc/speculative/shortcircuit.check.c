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
struct StateT * slot_10(struct StateT * x347);
struct StateT * slot_1(struct StateT * x15);
struct StateT * slot_8(struct StateT * x352);
struct StateT * slot_9(struct StateT * x319);
struct StateT * slot_2(struct StateT * x28);
struct StateT * slot_7(struct StateT * x331);
struct StateT * slot_3(struct StateT * x41);
struct StateT * slot_11(struct StateT * x309);
struct StateT * slot_0(struct StateT * x2);
struct StateT * snippet(struct StateT * x0) {
  struct StateT * x1 = slot_0(x0);
  return x1;
}

struct StateT * slot_10(struct StateT * x347) {
  int x348 = x347->timer;
  int x351 = x348 + 1;
  x347->timer = x351;
  return x347;
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

struct StateT * slot_8(struct StateT * x352) {
  int x353 = x352->timer;
  int x357 = x353 + 1;
  x352->timer = x357;
  struct StateT * x355 = slot_3(x352);
  return x355;
}

struct StateT * slot_9(struct StateT * x319) {
  int x320 = x319->timer;
  int x326 = x320 + 1;
  x319->timer = x326;
  int * x322 = x319->regs;
  x322[0] = 0;
  struct StateT * x324 = slot_10(x319);
  return x324;
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

struct StateT * slot_7(struct StateT * x331) {
  int x332 = x331->timer;
  int x340 = x332 + 1;
  x331->timer = x340;
  int * x334 = x331->regs;
  int x335 = x334[4];
  int * x336 = x331->regs;
  int x344 = x335 + 1;
  x336[4] = x344;
  struct StateT * x338 = slot_8(x331);
  return x338;
}

struct StateT * slot_3(struct StateT * x41) {
  int * x42 = x41->saved_regs;
  int * x43 = x41->regs;
  int x44 = x43[0];
  x42[0] = x44;
  int x46 = x41->timer;
  int x198 = x46 + 1;
  x41->timer = x198;
  int * x48 = x41->regs;
  int x49 = x48[2];
  int * x50 = x41->regs;
  int x51 = x50[4];
  int * x52 = x41->cache_keys;
  int x53 = x52[0];
  bool x204 = x53 == (x49 + x51);
  int x101;
  if (x204) {
    int * x54 = x41->cache_vals;
    int x55 = x54[0];
    x101 = x55;
  } else {
    int * x57 = x41->cache_keys;
    int x58 = x57[1];
    bool x209 = x58 == (x49 + x51);
    int x99;
    if (x209) {
      int * x59 = x41->cache_vals;
      int x60 = x59[1];
      int * x61 = x41->cache_keys;
      int * x62 = x41->cache_keys;
      int x63 = x62[0];
      x61[1] = x63;
      int * x65 = x41->cache_vals;
      int * x66 = x41->cache_vals;
      int x67 = x66[0];
      x65[1] = x67;
      int * x69 = x41->cache_keys;
      int x218 = x49 + x51;
      x69[0] = x218;
      int * x71 = x41->cache_vals;
      x71[0] = x60;
      int x73 = x41->timer;
      int x221 = x73 + 1;
      x41->timer = x221;
      x99 = x60;
    } else {
      int * x76 = x41->mem;
      int x223 = x49 + x51;
      int x77 = x76[x223];
      int * x78 = x41->mem;
      int * x79 = x41->cache_keys;
      int x80 = x79[1];
      int * x81 = x41->cache_vals;
      int x82 = x81[1];
      x78[x80] = x82;
      int * x84 = x41->cache_keys;
      int * x85 = x41->cache_keys;
      int x86 = x85[0];
      x84[1] = x86;
      int * x88 = x41->cache_vals;
      int * x89 = x41->cache_vals;
      int x90 = x89[0];
      x88[1] = x90;
      int * x92 = x41->cache_keys;
      x92[0] = x223;
      int * x94 = x41->cache_vals;
      x94[0] = x77;
      int x96 = x41->timer;
      int x238 = x96 + 100;
      x41->timer = x238;
      x99 = x77;
    }
    x101 = x99;
  }
  int * x102 = x41->regs;
  x102[0] = x101;
  int * x104 = x41->saved_regs;
  int * x105 = x41->regs;
  int x106 = x105[1];
  x104[1] = x106;
  int x108 = x41->timer;
  int x246 = x108 + 1;
  x41->timer = x246;
  int * x110 = x41->regs;
  int x111 = x110[3];
  int * x112 = x41->regs;
  int x113 = x112[4];
  int * x114 = x41->cache_keys;
  int x115 = x114[0];
  bool x251 = x115 == (x111 + x113);
  int x163;
  if (x251) {
    int * x116 = x41->cache_vals;
    int x117 = x116[0];
    x163 = x117;
  } else {
    int * x119 = x41->cache_keys;
    int x120 = x119[1];
    bool x255 = x120 == (x111 + x113);
    int x161;
    if (x255) {
      int * x121 = x41->cache_vals;
      int x122 = x121[1];
      int * x123 = x41->cache_keys;
      int * x124 = x41->cache_keys;
      int x125 = x124[0];
      x123[1] = x125;
      int * x127 = x41->cache_vals;
      int * x128 = x41->cache_vals;
      int x129 = x128[0];
      x127[1] = x129;
      int * x131 = x41->cache_keys;
      int x264 = x111 + x113;
      x131[0] = x264;
      int * x133 = x41->cache_vals;
      x133[0] = x122;
      int x135 = x41->timer;
      int x267 = x135 + 1;
      x41->timer = x267;
      x161 = x122;
    } else {
      int * x138 = x41->mem;
      int x269 = x111 + x113;
      int x139 = x138[x269];
      int * x140 = x41->mem;
      int * x141 = x41->cache_keys;
      int x142 = x141[1];
      int * x143 = x41->cache_vals;
      int x144 = x143[1];
      x140[x142] = x144;
      int * x146 = x41->cache_keys;
      int * x147 = x41->cache_keys;
      int x148 = x147[0];
      x146[1] = x148;
      int * x150 = x41->cache_vals;
      int * x151 = x41->cache_vals;
      int x152 = x151[0];
      x150[1] = x152;
      int * x154 = x41->cache_keys;
      x154[0] = x269;
      int * x156 = x41->cache_vals;
      x156[0] = x139;
      int x158 = x41->timer;
      int x284 = x158 + 100;
      x41->timer = x284;
      x161 = x139;
    }
    x163 = x161;
  }
  int * x164 = x41->regs;
  x164[1] = x163;
  int * x166 = x41->regs;
  int x167 = x166[4];
  bool x289 = x167 >= 4;
  struct StateT * x192;
  if (x289) {
    int x168 = x41->timer;
    int x290 = x168 + 15;
    x41->timer = x290;
    int * x170 = x41->saved_regs;
    int x171 = x170[0];
    int * x172 = x41->regs;
    x172[0] = x171;
    int * x174 = x41->saved_regs;
    int x175 = x174[1];
    int * x176 = x41->regs;
    x176[1] = x175;
    struct StateT * x178 = slot_11(x41);
    x192 = x178;
  } else {
    int x180 = x41->timer;
    int x299 = x180 + 1;
    x41->timer = x299;
    int * x182 = x41->regs;
    int x183 = x182[0];
    int * x184 = x41->regs;
    int x185 = x184[1];
    bool x302 = !(x183 == x185);
    struct StateT * x190;
    if (x302) {
      struct StateT * x186 = slot_9(x41);
      x190 = x186;
    } else {
      struct StateT * x188 = slot_7(x41);
      x190 = x188;
    }
    x192 = x190;
  }
  return x192;
}

struct StateT * slot_11(struct StateT * x309) {
  int x310 = x309->timer;
  int x315 = x310 + 1;
  x309->timer = x315;
  int * x312 = x309->regs;
  x312[0] = 1;
  return x309;
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