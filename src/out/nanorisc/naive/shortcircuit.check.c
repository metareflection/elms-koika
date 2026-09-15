// verify: leak (CBMC should report VERIFICATION FAILED) [unwind 31]

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

struct StateT * slot_6(struct StateT * x121);
struct StateT * slot_5(struct StateT * x96);
struct StateT * slot_2(struct StateT * x28);
struct StateT * slot_7(struct StateT * x157);
struct StateT * slot_3(struct StateT * x41);
struct StateT * snippet(struct StateT * x0);
struct StateT * slot_10(struct StateT * x173);
struct StateT * slot_1(struct StateT * x15);
struct StateT * slot_8(struct StateT * x178);
struct StateT * slot_4(struct StateT * x71);
struct StateT * slot_9(struct StateT * x145);
struct StateT * slot_11(struct StateT * x61);
struct StateT * slot_0(struct StateT * x2);
struct StateT * slot_6(struct StateT * x121) {
  int x122 = x121->timer;
  int x134 = x122 + 1;
  x121->timer = x134;
  int * x124 = x121->regs;
  int x125 = x124[0];
  int * x126 = x121->regs;
  int x127 = x126[1];
  bool x139 = !(x125 == x127);
  struct StateT * x132;
  if (x139) {
    struct StateT * x128 = slot_9(x121);
    x132 = x128;
  } else {
    struct StateT * x130 = slot_7(x121);
    x132 = x130;
  }
  return x132;
}

struct StateT * slot_5(struct StateT * x96) {
  int x97 = x96->timer;
  int x109 = x97 + 1;
  x96->timer = x109;
  int * x99 = x96->regs;
  int x100 = x99[3];
  int * x101 = x96->regs;
  int x102 = x101[4];
  int * x103 = x96->mem;
  int x115 = x100 + x102;
  int x104 = x103[x115];
  int * x105 = x96->regs;
  x105[1] = x104;
  struct StateT * x107 = slot_6(x96);
  return x107;
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

struct StateT * slot_7(struct StateT * x157) {
  int x158 = x157->timer;
  int x166 = x158 + 1;
  x157->timer = x166;
  int * x160 = x157->regs;
  int x161 = x160[4];
  int * x162 = x157->regs;
  int x170 = x161 + 1;
  x162[4] = x170;
  struct StateT * x164 = slot_8(x157);
  return x164;
}

struct StateT * slot_3(struct StateT * x41) {
  int x42 = x41->timer;
  int x52 = x42 + 1;
  x41->timer = x52;
  int * x44 = x41->regs;
  int x45 = x44[4];
  bool x55 = x45 >= 4;
  struct StateT * x50;
  if (x55) {
    struct StateT * x46 = slot_11(x41);
    x50 = x46;
  } else {
    struct StateT * x48 = slot_4(x41);
    x50 = x48;
  }
  return x50;
}

struct StateT * snippet(struct StateT * x0) {
  struct StateT * x1 = slot_0(x0);
  return x1;
}

struct StateT * slot_10(struct StateT * x173) {
  int x174 = x173->timer;
  int x177 = x174 + 1;
  x173->timer = x177;
  return x173;
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

struct StateT * slot_8(struct StateT * x178) {
  int x179 = x178->timer;
  int x183 = x179 + 1;
  x178->timer = x183;
  struct StateT * x181 = slot_3(x178);
  return x181;
}

struct StateT * slot_4(struct StateT * x71) {
  int x72 = x71->timer;
  int x84 = x72 + 1;
  x71->timer = x84;
  int * x74 = x71->regs;
  int x75 = x74[2];
  int * x76 = x71->regs;
  int x77 = x76[4];
  int * x78 = x71->mem;
  int x90 = x75 + x77;
  int x79 = x78[x90];
  int * x80 = x71->regs;
  x80[0] = x79;
  struct StateT * x82 = slot_5(x71);
  return x82;
}

struct StateT * slot_9(struct StateT * x145) {
  int x146 = x145->timer;
  int x152 = x146 + 1;
  x145->timer = x152;
  int * x148 = x145->regs;
  x148[0] = 0;
  struct StateT * x150 = slot_10(x145);
  return x150;
}

struct StateT * slot_11(struct StateT * x61) {
  int x62 = x61->timer;
  int x67 = x62 + 1;
  x61->timer = x67;
  int * x64 = x61->regs;
  x64[0] = 1;
  return x61;
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
  }
  s->timer = 0;
  for (int i=0; i<MEM_SIZE; i++) {
    s->mem[i] = 0;
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