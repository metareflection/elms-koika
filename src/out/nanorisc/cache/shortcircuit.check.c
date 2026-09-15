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

struct StateT * slot_6(struct StateT * x288);
struct StateT * slot_5(struct StateT * x179);
struct StateT * slot_2(struct StateT * x28);
struct StateT * slot_7(struct StateT * x324);
struct StateT * slot_3(struct StateT * x41);
struct StateT * snippet(struct StateT * x0);
struct StateT * slot_10(struct StateT * x340);
struct StateT * slot_1(struct StateT * x15);
struct StateT * slot_8(struct StateT * x345);
struct StateT * slot_4(struct StateT * x71);
struct StateT * slot_9(struct StateT * x312);
struct StateT * slot_11(struct StateT * x61);
struct StateT * slot_0(struct StateT * x2);
struct StateT * slot_6(struct StateT * x288) {
  int x289 = x288->timer;
  int x301 = x289 + 1;
  x288->timer = x301;
  int * x291 = x288->regs;
  int x292 = x291[0];
  int * x293 = x288->regs;
  int x294 = x293[1];
  bool x306 = !(x292 == x294);
  struct StateT * x299;
  if (x306) {
    struct StateT * x295 = slot_9(x288);
    x299 = x295;
  } else {
    struct StateT * x297 = slot_7(x288);
    x299 = x297;
  }
  return x299;
}

struct StateT * slot_5(struct StateT * x179) {
  int x180 = x179->timer;
  int x240 = x180 + 1;
  x179->timer = x240;
  int * x182 = x179->regs;
  int x183 = x182[3];
  int * x184 = x179->regs;
  int x185 = x184[4];
  int * x186 = x179->cache_keys;
  int x187 = x186[0];
  bool x247 = x187 == (x183 + x185);
  int x235;
  if (x247) {
    int * x188 = x179->cache_vals;
    int x189 = x188[0];
    x235 = x189;
  } else {
    int * x191 = x179->cache_keys;
    int x192 = x191[1];
    bool x252 = x192 == (x183 + x185);
    int x233;
    if (x252) {
      int * x193 = x179->cache_vals;
      int x194 = x193[1];
      int * x195 = x179->cache_keys;
      int * x196 = x179->cache_keys;
      int x197 = x196[0];
      x195[1] = x197;
      int * x199 = x179->cache_vals;
      int * x200 = x179->cache_vals;
      int x201 = x200[0];
      x199[1] = x201;
      int * x203 = x179->cache_keys;
      int x261 = x183 + x185;
      x203[0] = x261;
      int * x205 = x179->cache_vals;
      x205[0] = x194;
      int x207 = x179->timer;
      int x264 = x207 + 1;
      x179->timer = x264;
      x233 = x194;
    } else {
      int * x210 = x179->mem;
      int x266 = x183 + x185;
      int x211 = x210[x266];
      int * x212 = x179->mem;
      int * x213 = x179->cache_keys;
      int x214 = x213[1];
      int * x215 = x179->cache_vals;
      int x216 = x215[1];
      x212[x214] = x216;
      int * x218 = x179->cache_keys;
      int * x219 = x179->cache_keys;
      int x220 = x219[0];
      x218[1] = x220;
      int * x222 = x179->cache_vals;
      int * x223 = x179->cache_vals;
      int x224 = x223[0];
      x222[1] = x224;
      int * x226 = x179->cache_keys;
      x226[0] = x266;
      int * x228 = x179->cache_vals;
      x228[0] = x211;
      int x230 = x179->timer;
      int x281 = x230 + 100;
      x179->timer = x281;
      x233 = x211;
    }
    x235 = x233;
  }
  int * x236 = x179->regs;
  x236[1] = x235;
  struct StateT * x238 = slot_6(x179);
  return x238;
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

struct StateT * slot_7(struct StateT * x324) {
  int x325 = x324->timer;
  int x333 = x325 + 1;
  x324->timer = x333;
  int * x327 = x324->regs;
  int x328 = x327[4];
  int * x329 = x324->regs;
  int x337 = x328 + 1;
  x329[4] = x337;
  struct StateT * x331 = slot_8(x324);
  return x331;
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

struct StateT * slot_10(struct StateT * x340) {
  int x341 = x340->timer;
  int x344 = x341 + 1;
  x340->timer = x344;
  return x340;
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

struct StateT * slot_8(struct StateT * x345) {
  int x346 = x345->timer;
  int x350 = x346 + 1;
  x345->timer = x350;
  struct StateT * x348 = slot_3(x345);
  return x348;
}

struct StateT * slot_4(struct StateT * x71) {
  int x72 = x71->timer;
  int x132 = x72 + 1;
  x71->timer = x132;
  int * x74 = x71->regs;
  int x75 = x74[2];
  int * x76 = x71->regs;
  int x77 = x76[4];
  int * x78 = x71->cache_keys;
  int x79 = x78[0];
  bool x139 = x79 == (x75 + x77);
  int x127;
  if (x139) {
    int * x80 = x71->cache_vals;
    int x81 = x80[0];
    x127 = x81;
  } else {
    int * x83 = x71->cache_keys;
    int x84 = x83[1];
    bool x144 = x84 == (x75 + x77);
    int x125;
    if (x144) {
      int * x85 = x71->cache_vals;
      int x86 = x85[1];
      int * x87 = x71->cache_keys;
      int * x88 = x71->cache_keys;
      int x89 = x88[0];
      x87[1] = x89;
      int * x91 = x71->cache_vals;
      int * x92 = x71->cache_vals;
      int x93 = x92[0];
      x91[1] = x93;
      int * x95 = x71->cache_keys;
      int x153 = x75 + x77;
      x95[0] = x153;
      int * x97 = x71->cache_vals;
      x97[0] = x86;
      int x99 = x71->timer;
      int x156 = x99 + 1;
      x71->timer = x156;
      x125 = x86;
    } else {
      int * x102 = x71->mem;
      int x158 = x75 + x77;
      int x103 = x102[x158];
      int * x104 = x71->mem;
      int * x105 = x71->cache_keys;
      int x106 = x105[1];
      int * x107 = x71->cache_vals;
      int x108 = x107[1];
      x104[x106] = x108;
      int * x110 = x71->cache_keys;
      int * x111 = x71->cache_keys;
      int x112 = x111[0];
      x110[1] = x112;
      int * x114 = x71->cache_vals;
      int * x115 = x71->cache_vals;
      int x116 = x115[0];
      x114[1] = x116;
      int * x118 = x71->cache_keys;
      x118[0] = x158;
      int * x120 = x71->cache_vals;
      x120[0] = x103;
      int x122 = x71->timer;
      int x173 = x122 + 100;
      x71->timer = x173;
      x125 = x103;
    }
    x127 = x125;
  }
  int * x128 = x71->regs;
  x128[0] = x127;
  struct StateT * x130 = slot_5(x71);
  return x130;
}

struct StateT * slot_9(struct StateT * x312) {
  int x313 = x312->timer;
  int x319 = x313 + 1;
  x312->timer = x319;
  int * x315 = x312->regs;
  x315[0] = 0;
  struct StateT * x317 = slot_10(x312);
  return x317;
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