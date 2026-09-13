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

struct StateT * x19(struct StateT * x20);
struct StateT * x25(struct StateT * x26);
struct StateT * x158(struct StateT * x159);
struct StateT * x38(struct StateT * x39);
struct StateT * x195(struct StateT * x196);
struct StateT * x187(struct StateT * x188);
struct StateT * x172(struct StateT * x173);
struct StateT * snippet(struct StateT * x0);
struct StateT * x1(struct StateT * x2);
struct StateT * x7(struct StateT * x8);
struct StateT * x13(struct StateT * x14);
struct StateT * x98(struct StateT * x99);
struct StateT * x166(struct StateT * x167);
struct StateT * x19(struct StateT * x20) {
  int x21 = x20->timer;
  int x332 = x21 + 1;
  x20->timer = x332;
  int * x23 = x20->regs;
  int x24 = x23[4];
  bool x335 = x24 >= 4;
  struct StateT * x330;
  if (x335) {
    struct StateT * x36 = x25(x20);
    x330 = x36;
  } else {
    struct StateT * x328 = x38(x20);
    x330 = x328;
  }
  return x330;
}

struct StateT * x25(struct StateT * x26) {
  int x27 = x26->timer;
  int x32 = x27 + 1;
  x26->timer = x32;
  int * x29 = x26->regs;
  x29[0] = 1;
  return x26;
}

struct StateT * x158(struct StateT * x159) {
  int x160 = x159->timer;
  int x218 = x160 + 1;
  x159->timer = x218;
  int * x162 = x159->regs;
  int x163 = x162[0];
  int * x164 = x159->regs;
  int x165 = x164[1];
  bool x223 = !(x163 == x165);
  struct StateT * x216;
  if (x223) {
    struct StateT * x185 = x166(x159);
    x216 = x185;
  } else {
    struct StateT * x214 = x187(x159);
    x216 = x214;
  }
  return x216;
}

struct StateT * x38(struct StateT * x39) {
  int x40 = x39->timer;
  int x281 = x40 + 1;
  x39->timer = x281;
  int * x42 = x39->regs;
  int x43 = x42[2];
  int * x44 = x39->regs;
  int x45 = x44[4];
  int * x46 = x39->cache_keys;
  int x47 = x46[0];
  bool x288 = x47 == (x43 + x45);
  int x95;
  if (x288) {
    int * x48 = x39->cache_vals;
    int x49 = x48[0];
    x95 = x49;
  } else {
    int * x51 = x39->cache_keys;
    int x52 = x51[1];
    bool x293 = x52 == (x43 + x45);
    int x93;
    if (x293) {
      int * x53 = x39->cache_vals;
      int x54 = x53[1];
      int * x55 = x39->cache_keys;
      int * x56 = x39->cache_keys;
      int x57 = x56[0];
      x55[1] = x57;
      int * x59 = x39->cache_vals;
      int * x60 = x39->cache_vals;
      int x61 = x60[0];
      x59[1] = x61;
      int * x63 = x39->cache_keys;
      int x302 = x43 + x45;
      x63[0] = x302;
      int * x65 = x39->cache_vals;
      x65[0] = x54;
      int x67 = x39->timer;
      int x305 = x67 + 1;
      x39->timer = x305;
      x93 = x54;
    } else {
      int * x70 = x39->mem;
      int x307 = x43 + x45;
      int x71 = x70[x307];
      int * x72 = x39->mem;
      int * x73 = x39->cache_keys;
      int x74 = x73[1];
      int * x75 = x39->cache_vals;
      int x76 = x75[1];
      x72[x74] = x76;
      int * x78 = x39->cache_keys;
      int * x79 = x39->cache_keys;
      int x80 = x79[0];
      x78[1] = x80;
      int * x82 = x39->cache_vals;
      int * x83 = x39->cache_vals;
      int x84 = x83[0];
      x82[1] = x84;
      int * x86 = x39->cache_keys;
      x86[0] = x307;
      int * x88 = x39->cache_vals;
      x88[0] = x71;
      int x90 = x39->timer;
      int x322 = x90 + 100;
      x39->timer = x322;
      x93 = x71;
    }
    x95 = x93;
  }
  int * x96 = x39->regs;
  x96[0] = x95;
  struct StateT * x279 = x98(x39);
  return x279;
}

struct StateT * x195(struct StateT * x196) {
  int x197 = x196->timer;
  int x202 = x197 + 1;
  x196->timer = x202;
  struct StateT * x200 = x19(x196);
  return x200;
}

struct StateT * x187(struct StateT * x188) {
  int x189 = x188->timer;
  int x207 = x189 + 1;
  x188->timer = x207;
  int * x191 = x188->regs;
  int x192 = x191[4];
  int * x193 = x188->regs;
  int x211 = x192 + 1;
  x193[4] = x211;
  struct StateT * x205 = x195(x188);
  return x205;
}

struct StateT * x172(struct StateT * x173) {
  int x174 = x173->timer;
  int x177 = x174 + 1;
  x173->timer = x177;
  return x173;
}

struct StateT * snippet(struct StateT * x0) {
  struct StateT * x365 = x1(x0);
  return x365;
}

struct StateT * x1(struct StateT * x2) {
  int x3 = x2->timer;
  int x359 = x3 + 1;
  x2->timer = x359;
  int * x5 = x2->regs;
  x5[2] = 0;
  struct StateT * x357 = x7(x2);
  return x357;
}

struct StateT * x7(struct StateT * x8) {
  int x9 = x8->timer;
  int x351 = x9 + 1;
  x8->timer = x351;
  int * x11 = x8->regs;
  x11[3] = 20;
  struct StateT * x349 = x13(x8);
  return x349;
}

struct StateT * x13(struct StateT * x14) {
  int x15 = x14->timer;
  int x343 = x15 + 1;
  x14->timer = x343;
  int * x17 = x14->regs;
  x17[4] = 0;
  struct StateT * x341 = x19(x14);
  return x341;
}

struct StateT * x98(struct StateT * x99) {
  int x100 = x99->timer;
  int x231 = x100 + 1;
  x99->timer = x231;
  int * x102 = x99->regs;
  int x103 = x102[3];
  int * x104 = x99->regs;
  int x105 = x104[4];
  int * x106 = x99->cache_keys;
  int x107 = x106[0];
  bool x238 = x107 == (x103 + x105);
  int x155;
  if (x238) {
    int * x108 = x99->cache_vals;
    int x109 = x108[0];
    x155 = x109;
  } else {
    int * x111 = x99->cache_keys;
    int x112 = x111[1];
    bool x243 = x112 == (x103 + x105);
    int x153;
    if (x243) {
      int * x113 = x99->cache_vals;
      int x114 = x113[1];
      int * x115 = x99->cache_keys;
      int * x116 = x99->cache_keys;
      int x117 = x116[0];
      x115[1] = x117;
      int * x119 = x99->cache_vals;
      int * x120 = x99->cache_vals;
      int x121 = x120[0];
      x119[1] = x121;
      int * x123 = x99->cache_keys;
      int x252 = x103 + x105;
      x123[0] = x252;
      int * x125 = x99->cache_vals;
      x125[0] = x114;
      int x127 = x99->timer;
      int x255 = x127 + 1;
      x99->timer = x255;
      x153 = x114;
    } else {
      int * x130 = x99->mem;
      int x257 = x103 + x105;
      int x131 = x130[x257];
      int * x132 = x99->mem;
      int * x133 = x99->cache_keys;
      int x134 = x133[1];
      int * x135 = x99->cache_vals;
      int x136 = x135[1];
      x132[x134] = x136;
      int * x138 = x99->cache_keys;
      int * x139 = x99->cache_keys;
      int x140 = x139[0];
      x138[1] = x140;
      int * x142 = x99->cache_vals;
      int * x143 = x99->cache_vals;
      int x144 = x143[0];
      x142[1] = x144;
      int * x146 = x99->cache_keys;
      x146[0] = x257;
      int * x148 = x99->cache_vals;
      x148[0] = x131;
      int x150 = x99->timer;
      int x272 = x150 + 100;
      x99->timer = x272;
      x153 = x131;
    }
    x155 = x153;
  }
  int * x156 = x99->regs;
  x156[1] = x155;
  struct StateT * x229 = x158(x99);
  return x229;
}

struct StateT * x166(struct StateT * x167) {
  int x168 = x167->timer;
  int x180 = x168 + 1;
  x167->timer = x180;
  int * x170 = x167->regs;
  x170[0] = 0;
  struct StateT * x178 = x172(x167);
  return x178;
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
  __CPROVER_assert(s1_->timer==s2_->timer, "timing leak");
  return 0;
}