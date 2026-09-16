// verify: leak (CBMC should report VERIFICATION FAILED) [unwind 65]
#define NUM_REGS 8
#define MEM_SIZE 64
#define SECRET_SIZE 10
#define SECRET_OFFSET 20
#define CACHE_ENTRIES 12
#define CACHE_WORDS 24

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
  int mem[64];
  int saved_regs[8];
  int cache_tags[12];
  int cache_dirty[12];
  int cache_age[12];
  int cache_vals[24];
  int timer;
};

struct StateT * slot_6(struct StateT * x579);
struct StateT * slot_5(struct StateT * x325);
struct StateT * slot_2(struct StateT * x28);
struct StateT * slot_7(struct StateT * x615);
struct StateT * slot_3(struct StateT * x41);
struct StateT * snippet(struct StateT * x0);
struct StateT * slot_10(struct StateT * x631);
struct StateT * slot_1(struct StateT * x15);
struct StateT * slot_8(struct StateT * x636);
struct StateT * slot_4(struct StateT * x71);
struct StateT * slot_9(struct StateT * x603);
struct StateT * slot_11(struct StateT * x61);
struct StateT * slot_0(struct StateT * x2);
struct StateT * slot_6(struct StateT * x579) {
  int x580 = x579->timer;
  int x592 = x580 + 1;
  x579->timer = x592;
  int * x582 = x579->regs;
  int x583 = x582[0];
  int * x584 = x579->regs;
  int x585 = x584[1];
  bool x597 = !(x583 == x585);
  struct StateT * x590;
  if (x597) {
    struct StateT * x586 = slot_9(x579);
    x590 = x586;
  } else {
    struct StateT * x588 = slot_7(x579);
    x590 = x588;
  }
  return x590;
}

struct StateT * slot_5(struct StateT * x325) {
  int x326 = x325->timer;
  int x461 = x326 + 1;
  x325->timer = x461;
  int * x328 = x325->regs;
  int x329 = x328[3];
  int * x330 = x325->regs;
  int x331 = x330[4];
  int * x332 = x325->cache_tags;
  int x467 = (((int)((unsigned int)(x329 + x331) >> 1)) & 1) * 2;
  int x333 = x332[x467];
  int * x334 = x325->cache_tags;
  int x469 = ((((int)((unsigned int)(x329 + x331) >> 1)) & 1) * 2) + 1;
  int x335 = x334[x469];
  int * x336 = x325->cache_tags;
  int x471 = 4 + ((((int)((unsigned int)(x329 + x331) >> 1)) & 3) * 2);
  int x337 = x336[x471];
  int * x338 = x325->cache_tags;
  int x473 = (4 + ((((int)((unsigned int)(x329 + x331) >> 1)) & 3) * 2)) + 1;
  int x339 = x338[x473];
  int x340 = x325->timer;
  int x474 = x340 + ((100 ^ (((~(((x337 ^ ((int)((unsigned int)(x329 + x331) >> 1))) | (-(x337 ^ ((int)((unsigned int)(x329 + x331) >> 1))))) >> 31)) | (~(((x339 ^ ((int)((unsigned int)(x329 + x331) >> 1))) | (-(x339 ^ ((int)((unsigned int)(x329 + x331) >> 1))))) >> 31))) & 104)) ^ (((~(((x333 ^ ((int)((unsigned int)(x329 + x331) >> 1))) | (-(x333 ^ ((int)((unsigned int)(x329 + x331) >> 1))))) >> 31)) | (~(((x335 ^ ((int)((unsigned int)(x329 + x331) >> 1))) | (-(x335 ^ ((int)((unsigned int)(x329 + x331) >> 1))))) >> 31))) & (1 ^ (100 ^ (((~(((x337 ^ ((int)((unsigned int)(x329 + x331) >> 1))) | (-(x337 ^ ((int)((unsigned int)(x329 + x331) >> 1))))) >> 31)) | (~(((x339 ^ ((int)((unsigned int)(x329 + x331) >> 1))) | (-(x339 ^ ((int)((unsigned int)(x329 + x331) >> 1))))) >> 31))) & 104)))));
  x325->timer = x474;
  int * x342 = x325->cache_vals;
  bool x475 = !(((~(((x333 ^ ((int)((unsigned int)(x329 + x331) >> 1))) | (-(x333 ^ ((int)((unsigned int)(x329 + x331) >> 1))))) >> 31)) | (~(((x335 ^ ((int)((unsigned int)(x329 + x331) >> 1))) | (-(x335 ^ ((int)((unsigned int)(x329 + x331) >> 1))))) >> 31))) == 0);
  int x455;
  if (x475) {
    int * x343 = x325->cache_age;
    int x477 = ((((int)((unsigned int)(x329 + x331) >> 1)) & 1) * 2) + ((~(((x335 ^ ((int)((unsigned int)(x329 + x331) >> 1))) | (-(x335 ^ ((int)((unsigned int)(x329 + x331) >> 1))))) >> 31)) & 1);
    int x344 = x343[x477];
    int * x345 = x325->cache_age;
    int x346 = x345[x467];
    int * x347 = x325->cache_age;
    int x480 = x346 + ((int)((unsigned int)(x346 - x344) >> 31));
    x347[x467] = x480;
    int * x349 = x325->cache_age;
    int x350 = x349[x469];
    int * x351 = x325->cache_age;
    int x483 = x350 + ((int)((unsigned int)(x350 - x344) >> 31));
    x351[x469] = x483;
    int * x353 = x325->cache_age;
    x353[x477] = 0;
    x455 = x477;
  } else {
    int * x356 = x325->cache_age;
    int x487 = (((int)((unsigned int)(x329 + x331) >> 1)) & 1) * 2;
    int x357 = x356[x487];
    int * x358 = x325->cache_tags;
    int x359 = x358[x487];
    int * x360 = x325->cache_age;
    int x361 = x360[x469];
    int * x362 = x325->cache_tags;
    int x363 = x362[x469];
    bool x491 = !(((~(((x337 ^ ((int)((unsigned int)(x329 + x331) >> 1))) | (-(x337 ^ ((int)((unsigned int)(x329 + x331) >> 1))))) >> 31)) | (~(((x339 ^ ((int)((unsigned int)(x329 + x331) >> 1))) | (-(x339 ^ ((int)((unsigned int)(x329 + x331) >> 1))))) >> 31))) == 0);
    int x427;
    if (x491) {
      int * x364 = x325->cache_age;
      int x493 = (4 + ((((int)((unsigned int)(x329 + x331) >> 1)) & 3) * 2)) + ((~(((x339 ^ ((int)((unsigned int)(x329 + x331) >> 1))) | (-(x339 ^ ((int)((unsigned int)(x329 + x331) >> 1))))) >> 31)) & 1);
      int x365 = x364[x493];
      int * x366 = x325->cache_age;
      int x367 = x366[x471];
      int * x368 = x325->cache_age;
      int x496 = x367 + ((int)((unsigned int)(x367 - x365) >> 31));
      x368[x471] = x496;
      int * x370 = x325->cache_age;
      int x371 = x370[x473];
      int * x372 = x325->cache_age;
      int x499 = x371 + ((int)((unsigned int)(x371 - x365) >> 31));
      x372[x473] = x499;
      int * x374 = x325->cache_age;
      x374[x493] = 0;
      x427 = x493;
    } else {
      int * x377 = x325->cache_age;
      int x503 = 4 + ((((int)((unsigned int)(x329 + x331) >> 1)) & 3) * 2);
      int x378 = x377[x503];
      int * x379 = x325->cache_tags;
      int x380 = x379[x503];
      int * x381 = x325->cache_age;
      int x382 = x381[x473];
      int * x383 = x325->cache_tags;
      int x384 = x383[x473];
      int * x385 = x325->cache_dirty;
      int x508 = (4 + ((((int)((unsigned int)(x329 + x331) >> 1)) & 3) * 2)) + ((((x378 + ((~(((x380 ^ -1) | (-(x380 ^ -1))) >> 31)) & 2)) - (x382 + ((~(((x384 ^ -1) | (-(x384 ^ -1))) >> 31)) & 2))) >> 31) & 1);
      int x386 = x385[x508];
      bool x509 = !(x386 == 0);
      if (x509) {
        int * x387 = x325->cache_tags;
        int x388 = x387[x508];
        int * x389 = x325->cache_vals;
        int x512 = ((4 + ((((int)((unsigned int)(x329 + x331) >> 1)) & 3) * 2)) + ((((x378 + ((~(((x380 ^ -1) | (-(x380 ^ -1))) >> 31)) & 2)) - (x382 + ((~(((x384 ^ -1) | (-(x384 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
        int x390 = x389[x512];
        int * x391 = x325->cache_vals;
        int x514 = (((4 + ((((int)((unsigned int)(x329 + x331) >> 1)) & 3) * 2)) + ((((x378 + ((~(((x380 ^ -1) | (-(x380 ^ -1))) >> 31)) & 2)) - (x382 + ((~(((x384 ^ -1) | (-(x384 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
        int x392 = x391[x514];
        int * x393 = x325->mem;
        int x516 = x388 * 2;
        x393[x516] = x390;
        int * x395 = x325->mem;
        int x519 = (x388 * 2) + 1;
        x395[x519] = x392;
        ;
      } else {
        ;
      }
      int * x400 = x325->mem;
      int x524 = ((int)((unsigned int)(x329 + x331) >> 1)) * 2;
      int x401 = x400[x524];
      int * x402 = x325->mem;
      int x526 = (((int)((unsigned int)(x329 + x331) >> 1)) * 2) + 1;
      int x403 = x402[x526];
      int * x404 = x325->cache_vals;
      int x528 = ((4 + ((((int)((unsigned int)(x329 + x331) >> 1)) & 3) * 2)) + ((((x378 + ((~(((x380 ^ -1) | (-(x380 ^ -1))) >> 31)) & 2)) - (x382 + ((~(((x384 ^ -1) | (-(x384 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
      x404[x528] = x401;
      int * x406 = x325->cache_vals;
      int x531 = (((4 + ((((int)((unsigned int)(x329 + x331) >> 1)) & 3) * 2)) + ((((x378 + ((~(((x380 ^ -1) | (-(x380 ^ -1))) >> 31)) & 2)) - (x382 + ((~(((x384 ^ -1) | (-(x384 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
      x406[x531] = x403;
      int * x408 = x325->cache_tags;
      int x534 = (int)((unsigned int)(x329 + x331) >> 1);
      x408[x508] = x534;
      int * x410 = x325->cache_dirty;
      x410[x508] = 0;
      int * x412 = x325->cache_age;
      x412[x508] = 1;
      int * x414 = x325->cache_age;
      int x415 = x414[x508];
      int * x416 = x325->cache_age;
      int x417 = x416[x471];
      int * x418 = x325->cache_age;
      int x542 = x417 + ((int)((unsigned int)(x417 - x415) >> 31));
      x418[x471] = x542;
      int * x420 = x325->cache_age;
      int x421 = x420[x473];
      int * x422 = x325->cache_age;
      int x545 = x421 + ((int)((unsigned int)(x421 - x415) >> 31));
      x422[x473] = x545;
      int * x424 = x325->cache_age;
      x424[x508] = 0;
      x427 = x508;
    }
    int * x428 = x325->cache_vals;
    int x548 = x427 * 2;
    int x429 = x428[x548];
    int * x430 = x325->cache_vals;
    int x550 = (x427 * 2) + 1;
    int x431 = x430[x550];
    int * x432 = x325->cache_vals;
    int x552 = (((((int)((unsigned int)(x329 + x331) >> 1)) & 1) * 2) + ((((x357 + ((~(((x359 ^ -1) | (-(x359 ^ -1))) >> 31)) & 2)) - (x361 + ((~(((x363 ^ -1) | (-(x363 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
    x432[x552] = x429;
    int * x434 = x325->cache_vals;
    int x555 = ((((((int)((unsigned int)(x329 + x331) >> 1)) & 1) * 2) + ((((x357 + ((~(((x359 ^ -1) | (-(x359 ^ -1))) >> 31)) & 2)) - (x361 + ((~(((x363 ^ -1) | (-(x363 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
    x434[x555] = x431;
    int * x436 = x325->cache_tags;
    int x558 = ((((int)((unsigned int)(x329 + x331) >> 1)) & 1) * 2) + ((((x357 + ((~(((x359 ^ -1) | (-(x359 ^ -1))) >> 31)) & 2)) - (x361 + ((~(((x363 ^ -1) | (-(x363 ^ -1))) >> 31)) & 2))) >> 31) & 1);
    int x559 = (int)((unsigned int)(x329 + x331) >> 1);
    x436[x558] = x559;
    int * x438 = x325->cache_dirty;
    x438[x558] = 0;
    int * x440 = x325->cache_age;
    x440[x558] = 1;
    int * x442 = x325->cache_age;
    int x443 = x442[x558];
    int * x444 = x325->cache_age;
    int x445 = x444[x467];
    int * x446 = x325->cache_age;
    int x567 = x445 + ((int)((unsigned int)(x445 - x443) >> 31));
    x446[x467] = x567;
    int * x448 = x325->cache_age;
    int x449 = x448[x469];
    int * x450 = x325->cache_age;
    int x570 = x449 + ((int)((unsigned int)(x449 - x443) >> 31));
    x450[x469] = x570;
    int * x452 = x325->cache_age;
    x452[x558] = 0;
    x455 = x558;
  }
  int x573 = (x455 * 2) + ((x329 + x331) & 1);
  int x456 = x342[x573];
  int * x457 = x325->regs;
  x457[1] = x456;
  struct StateT * x459 = slot_6(x325);
  return x459;
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

struct StateT * slot_7(struct StateT * x615) {
  int x616 = x615->timer;
  int x624 = x616 + 1;
  x615->timer = x624;
  int * x618 = x615->regs;
  int x619 = x618[4];
  int * x620 = x615->regs;
  int x628 = x619 + 1;
  x620[4] = x628;
  struct StateT * x622 = slot_8(x615);
  return x622;
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

struct StateT * slot_10(struct StateT * x631) {
  int x632 = x631->timer;
  int x635 = x632 + 1;
  x631->timer = x635;
  return x631;
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

struct StateT * slot_8(struct StateT * x636) {
  int x637 = x636->timer;
  int x641 = x637 + 1;
  x636->timer = x641;
  struct StateT * x639 = slot_3(x636);
  return x639;
}

struct StateT * slot_4(struct StateT * x71) {
  int x72 = x71->timer;
  int x207 = x72 + 1;
  x71->timer = x207;
  int * x74 = x71->regs;
  int x75 = x74[2];
  int * x76 = x71->regs;
  int x77 = x76[4];
  int * x78 = x71->cache_tags;
  int x213 = (((int)((unsigned int)(x75 + x77) >> 1)) & 1) * 2;
  int x79 = x78[x213];
  int * x80 = x71->cache_tags;
  int x215 = ((((int)((unsigned int)(x75 + x77) >> 1)) & 1) * 2) + 1;
  int x81 = x80[x215];
  int * x82 = x71->cache_tags;
  int x217 = 4 + ((((int)((unsigned int)(x75 + x77) >> 1)) & 3) * 2);
  int x83 = x82[x217];
  int * x84 = x71->cache_tags;
  int x219 = (4 + ((((int)((unsigned int)(x75 + x77) >> 1)) & 3) * 2)) + 1;
  int x85 = x84[x219];
  int x86 = x71->timer;
  int x220 = x86 + ((100 ^ (((~(((x83 ^ ((int)((unsigned int)(x75 + x77) >> 1))) | (-(x83 ^ ((int)((unsigned int)(x75 + x77) >> 1))))) >> 31)) | (~(((x85 ^ ((int)((unsigned int)(x75 + x77) >> 1))) | (-(x85 ^ ((int)((unsigned int)(x75 + x77) >> 1))))) >> 31))) & 104)) ^ (((~(((x79 ^ ((int)((unsigned int)(x75 + x77) >> 1))) | (-(x79 ^ ((int)((unsigned int)(x75 + x77) >> 1))))) >> 31)) | (~(((x81 ^ ((int)((unsigned int)(x75 + x77) >> 1))) | (-(x81 ^ ((int)((unsigned int)(x75 + x77) >> 1))))) >> 31))) & (1 ^ (100 ^ (((~(((x83 ^ ((int)((unsigned int)(x75 + x77) >> 1))) | (-(x83 ^ ((int)((unsigned int)(x75 + x77) >> 1))))) >> 31)) | (~(((x85 ^ ((int)((unsigned int)(x75 + x77) >> 1))) | (-(x85 ^ ((int)((unsigned int)(x75 + x77) >> 1))))) >> 31))) & 104)))));
  x71->timer = x220;
  int * x88 = x71->cache_vals;
  bool x221 = !(((~(((x79 ^ ((int)((unsigned int)(x75 + x77) >> 1))) | (-(x79 ^ ((int)((unsigned int)(x75 + x77) >> 1))))) >> 31)) | (~(((x81 ^ ((int)((unsigned int)(x75 + x77) >> 1))) | (-(x81 ^ ((int)((unsigned int)(x75 + x77) >> 1))))) >> 31))) == 0);
  int x201;
  if (x221) {
    int * x89 = x71->cache_age;
    int x223 = ((((int)((unsigned int)(x75 + x77) >> 1)) & 1) * 2) + ((~(((x81 ^ ((int)((unsigned int)(x75 + x77) >> 1))) | (-(x81 ^ ((int)((unsigned int)(x75 + x77) >> 1))))) >> 31)) & 1);
    int x90 = x89[x223];
    int * x91 = x71->cache_age;
    int x92 = x91[x213];
    int * x93 = x71->cache_age;
    int x226 = x92 + ((int)((unsigned int)(x92 - x90) >> 31));
    x93[x213] = x226;
    int * x95 = x71->cache_age;
    int x96 = x95[x215];
    int * x97 = x71->cache_age;
    int x229 = x96 + ((int)((unsigned int)(x96 - x90) >> 31));
    x97[x215] = x229;
    int * x99 = x71->cache_age;
    x99[x223] = 0;
    x201 = x223;
  } else {
    int * x102 = x71->cache_age;
    int x233 = (((int)((unsigned int)(x75 + x77) >> 1)) & 1) * 2;
    int x103 = x102[x233];
    int * x104 = x71->cache_tags;
    int x105 = x104[x233];
    int * x106 = x71->cache_age;
    int x107 = x106[x215];
    int * x108 = x71->cache_tags;
    int x109 = x108[x215];
    bool x237 = !(((~(((x83 ^ ((int)((unsigned int)(x75 + x77) >> 1))) | (-(x83 ^ ((int)((unsigned int)(x75 + x77) >> 1))))) >> 31)) | (~(((x85 ^ ((int)((unsigned int)(x75 + x77) >> 1))) | (-(x85 ^ ((int)((unsigned int)(x75 + x77) >> 1))))) >> 31))) == 0);
    int x173;
    if (x237) {
      int * x110 = x71->cache_age;
      int x239 = (4 + ((((int)((unsigned int)(x75 + x77) >> 1)) & 3) * 2)) + ((~(((x85 ^ ((int)((unsigned int)(x75 + x77) >> 1))) | (-(x85 ^ ((int)((unsigned int)(x75 + x77) >> 1))))) >> 31)) & 1);
      int x111 = x110[x239];
      int * x112 = x71->cache_age;
      int x113 = x112[x217];
      int * x114 = x71->cache_age;
      int x242 = x113 + ((int)((unsigned int)(x113 - x111) >> 31));
      x114[x217] = x242;
      int * x116 = x71->cache_age;
      int x117 = x116[x219];
      int * x118 = x71->cache_age;
      int x245 = x117 + ((int)((unsigned int)(x117 - x111) >> 31));
      x118[x219] = x245;
      int * x120 = x71->cache_age;
      x120[x239] = 0;
      x173 = x239;
    } else {
      int * x123 = x71->cache_age;
      int x249 = 4 + ((((int)((unsigned int)(x75 + x77) >> 1)) & 3) * 2);
      int x124 = x123[x249];
      int * x125 = x71->cache_tags;
      int x126 = x125[x249];
      int * x127 = x71->cache_age;
      int x128 = x127[x219];
      int * x129 = x71->cache_tags;
      int x130 = x129[x219];
      int * x131 = x71->cache_dirty;
      int x254 = (4 + ((((int)((unsigned int)(x75 + x77) >> 1)) & 3) * 2)) + ((((x124 + ((~(((x126 ^ -1) | (-(x126 ^ -1))) >> 31)) & 2)) - (x128 + ((~(((x130 ^ -1) | (-(x130 ^ -1))) >> 31)) & 2))) >> 31) & 1);
      int x132 = x131[x254];
      bool x255 = !(x132 == 0);
      if (x255) {
        int * x133 = x71->cache_tags;
        int x134 = x133[x254];
        int * x135 = x71->cache_vals;
        int x258 = ((4 + ((((int)((unsigned int)(x75 + x77) >> 1)) & 3) * 2)) + ((((x124 + ((~(((x126 ^ -1) | (-(x126 ^ -1))) >> 31)) & 2)) - (x128 + ((~(((x130 ^ -1) | (-(x130 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
        int x136 = x135[x258];
        int * x137 = x71->cache_vals;
        int x260 = (((4 + ((((int)((unsigned int)(x75 + x77) >> 1)) & 3) * 2)) + ((((x124 + ((~(((x126 ^ -1) | (-(x126 ^ -1))) >> 31)) & 2)) - (x128 + ((~(((x130 ^ -1) | (-(x130 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
        int x138 = x137[x260];
        int * x139 = x71->mem;
        int x262 = x134 * 2;
        x139[x262] = x136;
        int * x141 = x71->mem;
        int x265 = (x134 * 2) + 1;
        x141[x265] = x138;
        ;
      } else {
        ;
      }
      int * x146 = x71->mem;
      int x270 = ((int)((unsigned int)(x75 + x77) >> 1)) * 2;
      int x147 = x146[x270];
      int * x148 = x71->mem;
      int x272 = (((int)((unsigned int)(x75 + x77) >> 1)) * 2) + 1;
      int x149 = x148[x272];
      int * x150 = x71->cache_vals;
      int x274 = ((4 + ((((int)((unsigned int)(x75 + x77) >> 1)) & 3) * 2)) + ((((x124 + ((~(((x126 ^ -1) | (-(x126 ^ -1))) >> 31)) & 2)) - (x128 + ((~(((x130 ^ -1) | (-(x130 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
      x150[x274] = x147;
      int * x152 = x71->cache_vals;
      int x277 = (((4 + ((((int)((unsigned int)(x75 + x77) >> 1)) & 3) * 2)) + ((((x124 + ((~(((x126 ^ -1) | (-(x126 ^ -1))) >> 31)) & 2)) - (x128 + ((~(((x130 ^ -1) | (-(x130 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
      x152[x277] = x149;
      int * x154 = x71->cache_tags;
      int x280 = (int)((unsigned int)(x75 + x77) >> 1);
      x154[x254] = x280;
      int * x156 = x71->cache_dirty;
      x156[x254] = 0;
      int * x158 = x71->cache_age;
      x158[x254] = 1;
      int * x160 = x71->cache_age;
      int x161 = x160[x254];
      int * x162 = x71->cache_age;
      int x163 = x162[x217];
      int * x164 = x71->cache_age;
      int x288 = x163 + ((int)((unsigned int)(x163 - x161) >> 31));
      x164[x217] = x288;
      int * x166 = x71->cache_age;
      int x167 = x166[x219];
      int * x168 = x71->cache_age;
      int x291 = x167 + ((int)((unsigned int)(x167 - x161) >> 31));
      x168[x219] = x291;
      int * x170 = x71->cache_age;
      x170[x254] = 0;
      x173 = x254;
    }
    int * x174 = x71->cache_vals;
    int x294 = x173 * 2;
    int x175 = x174[x294];
    int * x176 = x71->cache_vals;
    int x296 = (x173 * 2) + 1;
    int x177 = x176[x296];
    int * x178 = x71->cache_vals;
    int x298 = (((((int)((unsigned int)(x75 + x77) >> 1)) & 1) * 2) + ((((x103 + ((~(((x105 ^ -1) | (-(x105 ^ -1))) >> 31)) & 2)) - (x107 + ((~(((x109 ^ -1) | (-(x109 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
    x178[x298] = x175;
    int * x180 = x71->cache_vals;
    int x301 = ((((((int)((unsigned int)(x75 + x77) >> 1)) & 1) * 2) + ((((x103 + ((~(((x105 ^ -1) | (-(x105 ^ -1))) >> 31)) & 2)) - (x107 + ((~(((x109 ^ -1) | (-(x109 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
    x180[x301] = x177;
    int * x182 = x71->cache_tags;
    int x304 = ((((int)((unsigned int)(x75 + x77) >> 1)) & 1) * 2) + ((((x103 + ((~(((x105 ^ -1) | (-(x105 ^ -1))) >> 31)) & 2)) - (x107 + ((~(((x109 ^ -1) | (-(x109 ^ -1))) >> 31)) & 2))) >> 31) & 1);
    int x305 = (int)((unsigned int)(x75 + x77) >> 1);
    x182[x304] = x305;
    int * x184 = x71->cache_dirty;
    x184[x304] = 0;
    int * x186 = x71->cache_age;
    x186[x304] = 1;
    int * x188 = x71->cache_age;
    int x189 = x188[x304];
    int * x190 = x71->cache_age;
    int x191 = x190[x213];
    int * x192 = x71->cache_age;
    int x313 = x191 + ((int)((unsigned int)(x191 - x189) >> 31));
    x192[x213] = x313;
    int * x194 = x71->cache_age;
    int x195 = x194[x215];
    int * x196 = x71->cache_age;
    int x316 = x195 + ((int)((unsigned int)(x195 - x189) >> 31));
    x196[x215] = x316;
    int * x198 = x71->cache_age;
    x198[x304] = 0;
    x201 = x304;
  }
  int x319 = (x201 * 2) + ((x75 + x77) & 1);
  int x202 = x88[x319];
  int * x203 = x71->regs;
  x203[0] = x202;
  struct StateT * x205 = slot_5(x71);
  return x205;
}

struct StateT * slot_9(struct StateT * x603) {
  int x604 = x603->timer;
  int x610 = x604 + 1;
  x603->timer = x610;
  int * x606 = x603->regs;
  x606[0] = 0;
  struct StateT * x608 = slot_10(x603);
  return x608;
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
  for (int i=0; i<CACHE_ENTRIES; i++) {
    s->cache_tags[i] = -1;
    s->cache_dirty[i] = 0;
    s->cache_age[i] = 0;
  }
  for (int i=0; i<CACHE_WORDS; i++) {
    s->cache_vals[i] = 0;
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