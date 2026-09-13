// verify: clean (CBMC should report VERIFICATION SUCCESSFUL)

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
struct StateT * slot_1(struct StateT * x19);
struct StateT * slot_2(struct StateT * x40);
struct StateT * slot_0(struct StateT * x2);
struct StateT * snippet(struct StateT * x0) {
  struct StateT * x1 = slot_0(x0);
  return x1;
}

struct StateT * slot_1(struct StateT * x19) {
  int x20 = x19->timer;
  int x30 = x20 + 1;
  x19->timer = x30;
  int * x22 = x19->regs;
  int x23 = x22[0];
  int * x24 = x19->mem;
  int x25 = x24[x23];
  int * x26 = x19->regs;
  x26[1] = x25;
  struct StateT * x28 = slot_2(x19);
  return x28;
}

struct StateT * slot_2(struct StateT * x40) {
  int x41 = x40->timer;
  int x50 = x41 + 1;
  x40->timer = x50;
  int * x43 = x40->regs;
  int x44 = x43[1];
  int * x45 = x40->mem;
  int x54 = x44 + 4;
  int x46 = x45[x54];
  int * x47 = x40->regs;
  x47[2] = x46;
  return x40;
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