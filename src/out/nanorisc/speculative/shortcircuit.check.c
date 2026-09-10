
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
struct StateT * x19(struct StateT * x20);
struct StateT * x1(struct StateT * x2);
struct StateT * x197(struct StateT * x198);
struct StateT * x205(struct StateT * x206);
struct StateT * x182(struct StateT * x183);
struct StateT * x176(struct StateT * x177);
struct StateT * x7(struct StateT * x8);
struct StateT * x157(struct StateT * x158);
struct StateT * x13(struct StateT * x14);
struct StateT * snippet(struct StateT * x0) {
  struct StateT * x369 = x1(x0);
  return x369;
}

struct StateT * x19(struct StateT * x20) {
  int * x21 = x20->saved_regs;
  int * x22 = x20->regs;
  int x23 = x22[0];
  x21[0] = x23;
  int x25 = x20->timer;
  int x234 = x25 + 1;
  x20->timer = x234;int * x27 = x20->regs;
  int x28 = x27[2];
  int * x29 = x20->regs;
  int x30 = x29[4];
  int * x31 = x20->cache_keys;
  int x32 = x31[0];
  bool x240 = x32 == (x28 + x30);
  int x80 = (x240 ? ({
    int * x33 = x20->cache_vals;
    int x34 = x33[0];
    x34;
  }) : ({
    int * x36 = x20->cache_keys;
    int x37 = x36[1];
    bool x245 = x37 == (x28 + x30);
    int x78 = (x245 ? ({
      int * x38 = x20->cache_vals;
      int x39 = x38[1];
      int * x40 = x20->cache_keys;
      int * x41 = x20->cache_keys;
      int x42 = x41[0];
      x40[1] = x42;
      int * x44 = x20->cache_vals;
      int * x45 = x20->cache_vals;
      int x46 = x45[0];
      x44[1] = x46;
      int * x48 = x20->cache_keys;
      int x254 = x28 + x30;
      x48[0] = x254;
      int * x50 = x20->cache_vals;
      x50[0] = x39;
      int x52 = x20->timer;
      int x257 = x52 + 1;
      x20->timer = x257;x39;
    }) : ({
      int * x55 = x20->mem;
      int x259 = x28 + x30;
      int x56 = x55[x259];
      int * x57 = x20->mem;
      int * x58 = x20->cache_keys;
      int x59 = x58[1];
      int * x60 = x20->cache_vals;
      int x61 = x60[1];
      x57[x59] = x61;
      int * x63 = x20->cache_keys;
      int * x64 = x20->cache_keys;
      int x65 = x64[0];
      x63[1] = x65;
      int * x67 = x20->cache_vals;
      int * x68 = x20->cache_vals;
      int x69 = x68[0];
      x67[1] = x69;
      int * x71 = x20->cache_keys;
      x71[0] = x259;
      int * x73 = x20->cache_vals;
      x73[0] = x56;
      int x75 = x20->timer;
      int x274 = x75 + 100;
      x20->timer = x274;x56;
    }));
    x78;
  }));
  int * x81 = x20->regs;
  x81[0] = x80;
  int * x83 = x20->saved_regs;
  int * x84 = x20->regs;
  int x85 = x84[1];
  x83[1] = x85;
  int x87 = x20->timer;
  int x282 = x87 + 1;
  x20->timer = x282;int * x89 = x20->regs;
  int x90 = x89[3];
  int * x91 = x20->regs;
  int x92 = x91[4];
  int * x93 = x20->cache_keys;
  int x94 = x93[0];
  bool x287 = x94 == (x90 + x92);
  int x142 = (x287 ? ({
    int * x95 = x20->cache_vals;
    int x96 = x95[0];
    x96;
  }) : ({
    int * x98 = x20->cache_keys;
    int x99 = x98[1];
    bool x291 = x99 == (x90 + x92);
    int x140 = (x291 ? ({
      int * x100 = x20->cache_vals;
      int x101 = x100[1];
      int * x102 = x20->cache_keys;
      int * x103 = x20->cache_keys;
      int x104 = x103[0];
      x102[1] = x104;
      int * x106 = x20->cache_vals;
      int * x107 = x20->cache_vals;
      int x108 = x107[0];
      x106[1] = x108;
      int * x110 = x20->cache_keys;
      int x300 = x90 + x92;
      x110[0] = x300;
      int * x112 = x20->cache_vals;
      x112[0] = x101;
      int x114 = x20->timer;
      int x303 = x114 + 1;
      x20->timer = x303;x101;
    }) : ({
      int * x117 = x20->mem;
      int x305 = x90 + x92;
      int x118 = x117[x305];
      int * x119 = x20->mem;
      int * x120 = x20->cache_keys;
      int x121 = x120[1];
      int * x122 = x20->cache_vals;
      int x123 = x122[1];
      x119[x121] = x123;
      int * x125 = x20->cache_keys;
      int * x126 = x20->cache_keys;
      int x127 = x126[0];
      x125[1] = x127;
      int * x129 = x20->cache_vals;
      int * x130 = x20->cache_vals;
      int x131 = x130[0];
      x129[1] = x131;
      int * x133 = x20->cache_keys;
      x133[0] = x305;
      int * x135 = x20->cache_vals;
      x135[0] = x118;
      int x137 = x20->timer;
      int x320 = x137 + 100;
      x20->timer = x320;x118;
    }));
    x140;
  }));
  int * x143 = x20->regs;
  x143[1] = x142;
  int * x145 = x20->regs;
  int x146 = x145[4];
  bool x325 = x146 >= 4;
  struct StateT * x228 = (x325 ? ({
    int x147 = x20->timer;
    int x326 = x147 + 15;
    x20->timer = x326;int * x149 = x20->saved_regs;
    int x150 = x149[0];
    int * x151 = x20->regs;
    x151[0] = x150;
    int * x153 = x20->saved_regs;
    int x154 = x153[1];
    int * x155 = x20->regs;
    x155[1] = x154;
    struct StateT * x168 = x157(x20);
    x168;
  }) : ({
    int x170 = x20->timer;
    int x335 = x170 + 1;
    x20->timer = x335;int * x172 = x20->regs;
    int x173 = x172[0];
    int * x174 = x20->regs;
    int x175 = x174[1];
    bool x338 = !(x173 == x175);
    struct StateT * x226 = (x338 ? ({
      struct StateT * x195 = x176(x20);
      x195;
    }) : ({
      struct StateT * x224 = x197(x20);
      x224;
    }));
    x226;
  }));
  return x228;
}

struct StateT * x1(struct StateT * x2) {
  int x3 = x2->timer;
  int x363 = x3 + 1;
  x2->timer = x363;int * x5 = x2->regs;
  x5[2] = 0;
  struct StateT * x361 = x7(x2);
  return x361;
}

struct StateT * x197(struct StateT * x198) {
  int x199 = x198->timer;
  int x217 = x199 + 1;
  x198->timer = x217;int * x201 = x198->regs;
  int x202 = x201[4];
  int * x203 = x198->regs;
  int x221 = x202 + 1;
  x203[4] = x221;
  struct StateT * x215 = x205(x198);
  return x215;
}

struct StateT * x205(struct StateT * x206) {
  int x207 = x206->timer;
  int x212 = x207 + 1;
  x206->timer = x212;struct StateT * x210 = x19(x206);
  return x210;
}

struct StateT * x182(struct StateT * x183) {
  int x184 = x183->timer;
  int x187 = x184 + 1;
  x183->timer = x187;return x183;
}

struct StateT * x176(struct StateT * x177) {
  int x178 = x177->timer;
  int x190 = x178 + 1;
  x177->timer = x190;int * x180 = x177->regs;
  x180[0] = 0;
  struct StateT * x188 = x182(x177);
  return x188;
}

struct StateT * x7(struct StateT * x8) {
  int x9 = x8->timer;
  int x355 = x9 + 1;
  x8->timer = x355;int * x11 = x8->regs;
  x11[3] = 20;
  struct StateT * x353 = x13(x8);
  return x353;
}

struct StateT * x157(struct StateT * x158) {
  int x159 = x158->timer;
  int x164 = x159 + 1;
  x158->timer = x164;int * x161 = x158->regs;
  x161[0] = 1;
  return x158;
}

struct StateT * x13(struct StateT * x14) {
  int x15 = x14->timer;
  int x347 = x15 + 1;
  x14->timer = x347;int * x17 = x14->regs;
  x17[4] = 0;
  struct StateT * x345 = x19(x14);
  return x345;
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