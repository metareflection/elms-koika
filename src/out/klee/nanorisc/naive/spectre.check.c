// verify: clean (KLEE should report no failing assertion) [budget 120s]
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
struct StateT * slot_1(struct StateT * x15);
struct StateT * slot_4(struct StateT * x70);
struct StateT * slot_2(struct StateT * x28);
struct StateT * slot_3(struct StateT * x45);
struct StateT * slot_0(struct StateT * x2);
struct StateT * snippet(struct StateT * x0) {
  struct StateT * x1 = slot_0(x0);
  return x1;
}

struct StateT * slot_1(struct StateT * x15) {
  int x16 = x15->timer;
  int x22 = x16 + 1;
  x15->timer = x22;
  int * x18 = x15->regs;
  x18[0] = 20;
  struct StateT * x20 = slot_2(x15);
  return x20;
}

struct StateT * slot_4(struct StateT * x70) {
  int x71 = x70->timer;
  int x80 = x71 + 1;
  x70->timer = x80;
  int * x73 = x70->regs;
  int x74 = x73[1];
  int * x75 = x70->mem;
  int x76 = x75[x74];
  int * x77 = x70->regs;
  x77[2] = x76;
  return x70;
}

struct StateT * slot_2(struct StateT * x28) {
  int x29 = x28->timer;
  int x38 = x29 + 1;
  x28->timer = x38;
  int * x31 = x28->regs;
  int x32 = x31[0];
  bool x41 = x32 >= 20;
  struct StateT * x36;
  if (x41) {
    x36 = x28;
  } else {
    struct StateT * x34 = slot_3(x28);
    x36 = x34;
  }
  return x36;
}

struct StateT * slot_3(struct StateT * x45) {
  int x46 = x45->timer;
  int x58 = x46 + 1;
  x45->timer = x58;
  int * x48 = x45->regs;
  int x49 = x48[3];
  int * x50 = x45->regs;
  int x51 = x50[0];
  int * x52 = x45->mem;
  int x64 = x49 + x51;
  int x53 = x52[x64];
  int * x54 = x45->regs;
  x54[1] = x53;
  struct StateT * x56 = slot_4(x45);
  return x56;
}

struct StateT * slot_0(struct StateT * x2) {
  int x3 = x2->timer;
  int x9 = x3 + 1;
  x2->timer = x9;
  int * x5 = x2->regs;
  x5[3] = 0;
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
  koika_assert(s1_->timer==s2_->timer, "timing leak");
  return 0;
}