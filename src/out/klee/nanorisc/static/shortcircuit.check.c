// verify: leak (KLEE should report a failing assertion) [budget 1200s]
#define NUM_REGS 8
#define MEM_SIZE 64
#define SECRET_SIZE 10
#define SECRET_OFFSET 20
#define CACHE_ENTRIES 12
#define CACHE_WORDS 24

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
  int mem[64];
  int saved_regs[8];
  int reg_ready[8];
  int cache_tags[12];
  int cache_dirty[12];
  int cache_age[12];
  int cache_vals[24];
  int timer;
};

struct StateT * slot_12(struct StateT * x655);
struct StateT * slot_14(struct StateT * x676);
struct StateT * slot_6(struct StateT * x565);
struct StateT * slot_5(struct StateT * x306);
struct StateT * slot_2(struct StateT * x28);
struct StateT * slot_7(struct StateT * x601);
struct StateT * slot_3(struct StateT * x41);
struct StateT * snippet(struct StateT * x0);
struct StateT * slot_10(struct StateT * x619);
struct StateT * slot_1(struct StateT * x15);
struct StateT * slot_8(struct StateT * x611);
struct StateT * slot_4(struct StateT * x49);
struct StateT * slot_13(struct StateT * x671);
struct StateT * slot_11(struct StateT * x643);
struct StateT * slot_0(struct StateT * x2);
struct StateT * slot_12(struct StateT * x655) {
  int x656 = x655->timer;
  int x664 = x656 + 1;
  x655->timer = x664;
  int * x658 = x655->regs;
  int x659 = x658[4];
  int * x660 = x655->regs;
  int x668 = x659 + 1;
  x660[4] = x668;
  struct StateT * x662 = slot_14(x655);
  return x662;
}

struct StateT * slot_14(struct StateT * x676) {
  int x677 = x676->timer;
  int x681 = x677 + 1;
  x676->timer = x681;
  struct StateT * x679 = slot_3(x676);
  return x679;
}

struct StateT * slot_6(struct StateT * x565) {
  int * x566 = x565->regs;
  int x567 = x566[4];
  bool x586 = x567 >= 4;
  struct StateT * x582;
  if (x586) {
    int x568 = x565->timer;
    int x587 = x568 + 15;
    x565->timer = x587;
    int * x570 = x565->saved_regs;
    int x571 = x570[0];
    int * x572 = x565->regs;
    x572[0] = x571;
    int * x574 = x565->saved_regs;
    int x575 = x574[1];
    int * x576 = x565->regs;
    x576[1] = x575;
    struct StateT * x578 = slot_7(x565);
    x582 = x578;
  } else {
    struct StateT * x580 = slot_8(x565);
    x582 = x580;
  }
  return x582;
}

struct StateT * slot_5(struct StateT * x306) {
  int * x307 = x306->saved_regs;
  int * x308 = x306->regs;
  int x309 = x308[1];
  x307[1] = x309;
  int x311 = x306->timer;
  int x450 = x311 + 1;
  x306->timer = x450;
  int * x313 = x306->regs;
  int x314 = x313[3];
  int * x315 = x306->regs;
  int x316 = x315[4];
  int * x317 = x306->cache_tags;
  int x456 = (((int)((unsigned int)(x314 + x316) >> 1)) & 1) * 2;
  int x318 = x317[x456];
  int * x319 = x306->cache_tags;
  int x458 = ((((int)((unsigned int)(x314 + x316) >> 1)) & 1) * 2) + 1;
  int x320 = x319[x458];
  int * x321 = x306->cache_tags;
  int x460 = 4 + ((((int)((unsigned int)(x314 + x316) >> 1)) & 3) * 2);
  int x322 = x321[x460];
  int * x323 = x306->cache_tags;
  int x462 = (4 + ((((int)((unsigned int)(x314 + x316) >> 1)) & 3) * 2)) + 1;
  int x324 = x323[x462];
  int x325 = x306->timer;
  int x463 = x325 + ((100 ^ (((~(((x322 ^ ((int)((unsigned int)(x314 + x316) >> 1))) | (-(x322 ^ ((int)((unsigned int)(x314 + x316) >> 1))))) >> 31)) | (~(((x324 ^ ((int)((unsigned int)(x314 + x316) >> 1))) | (-(x324 ^ ((int)((unsigned int)(x314 + x316) >> 1))))) >> 31))) & 104)) ^ (((~(((x318 ^ ((int)((unsigned int)(x314 + x316) >> 1))) | (-(x318 ^ ((int)((unsigned int)(x314 + x316) >> 1))))) >> 31)) | (~(((x320 ^ ((int)((unsigned int)(x314 + x316) >> 1))) | (-(x320 ^ ((int)((unsigned int)(x314 + x316) >> 1))))) >> 31))) & (1 ^ (100 ^ (((~(((x322 ^ ((int)((unsigned int)(x314 + x316) >> 1))) | (-(x322 ^ ((int)((unsigned int)(x314 + x316) >> 1))))) >> 31)) | (~(((x324 ^ ((int)((unsigned int)(x314 + x316) >> 1))) | (-(x324 ^ ((int)((unsigned int)(x314 + x316) >> 1))))) >> 31))) & 104)))));
  x306->timer = x463;
  int * x327 = x306->cache_vals;
  bool x464 = !(((~(((x318 ^ ((int)((unsigned int)(x314 + x316) >> 1))) | (-(x318 ^ ((int)((unsigned int)(x314 + x316) >> 1))))) >> 31)) | (~(((x320 ^ ((int)((unsigned int)(x314 + x316) >> 1))) | (-(x320 ^ ((int)((unsigned int)(x314 + x316) >> 1))))) >> 31))) == 0);
  int x440;
  if (x464) {
    int * x328 = x306->cache_age;
    int x466 = ((((int)((unsigned int)(x314 + x316) >> 1)) & 1) * 2) + ((~(((x320 ^ ((int)((unsigned int)(x314 + x316) >> 1))) | (-(x320 ^ ((int)((unsigned int)(x314 + x316) >> 1))))) >> 31)) & 1);
    int x329 = x328[x466];
    int * x330 = x306->cache_age;
    int x331 = x330[x456];
    int * x332 = x306->cache_age;
    int x469 = x331 + ((int)((unsigned int)(x331 - x329) >> 31));
    x332[x456] = x469;
    int * x334 = x306->cache_age;
    int x335 = x334[x458];
    int * x336 = x306->cache_age;
    int x472 = x335 + ((int)((unsigned int)(x335 - x329) >> 31));
    x336[x458] = x472;
    int * x338 = x306->cache_age;
    x338[x466] = 0;
    x440 = x466;
  } else {
    int * x341 = x306->cache_age;
    int x476 = (((int)((unsigned int)(x314 + x316) >> 1)) & 1) * 2;
    int x342 = x341[x476];
    int * x343 = x306->cache_tags;
    int x344 = x343[x476];
    int * x345 = x306->cache_age;
    int x346 = x345[x458];
    int * x347 = x306->cache_tags;
    int x348 = x347[x458];
    bool x480 = !(((~(((x322 ^ ((int)((unsigned int)(x314 + x316) >> 1))) | (-(x322 ^ ((int)((unsigned int)(x314 + x316) >> 1))))) >> 31)) | (~(((x324 ^ ((int)((unsigned int)(x314 + x316) >> 1))) | (-(x324 ^ ((int)((unsigned int)(x314 + x316) >> 1))))) >> 31))) == 0);
    int x412;
    if (x480) {
      int * x349 = x306->cache_age;
      int x482 = (4 + ((((int)((unsigned int)(x314 + x316) >> 1)) & 3) * 2)) + ((~(((x324 ^ ((int)((unsigned int)(x314 + x316) >> 1))) | (-(x324 ^ ((int)((unsigned int)(x314 + x316) >> 1))))) >> 31)) & 1);
      int x350 = x349[x482];
      int * x351 = x306->cache_age;
      int x352 = x351[x460];
      int * x353 = x306->cache_age;
      int x485 = x352 + ((int)((unsigned int)(x352 - x350) >> 31));
      x353[x460] = x485;
      int * x355 = x306->cache_age;
      int x356 = x355[x462];
      int * x357 = x306->cache_age;
      int x488 = x356 + ((int)((unsigned int)(x356 - x350) >> 31));
      x357[x462] = x488;
      int * x359 = x306->cache_age;
      x359[x482] = 0;
      x412 = x482;
    } else {
      int * x362 = x306->cache_age;
      int x492 = 4 + ((((int)((unsigned int)(x314 + x316) >> 1)) & 3) * 2);
      int x363 = x362[x492];
      int * x364 = x306->cache_tags;
      int x365 = x364[x492];
      int * x366 = x306->cache_age;
      int x367 = x366[x462];
      int * x368 = x306->cache_tags;
      int x369 = x368[x462];
      int * x370 = x306->cache_dirty;
      int x497 = (4 + ((((int)((unsigned int)(x314 + x316) >> 1)) & 3) * 2)) + ((((x363 + ((~(((x365 ^ -1) | (-(x365 ^ -1))) >> 31)) & 2)) - (x367 + ((~(((x369 ^ -1) | (-(x369 ^ -1))) >> 31)) & 2))) >> 31) & 1);
      int x371 = x370[x497];
      bool x498 = !(x371 == 0);
      if (x498) {
        int * x372 = x306->cache_tags;
        int x373 = x372[x497];
        int * x374 = x306->cache_vals;
        int x501 = ((4 + ((((int)((unsigned int)(x314 + x316) >> 1)) & 3) * 2)) + ((((x363 + ((~(((x365 ^ -1) | (-(x365 ^ -1))) >> 31)) & 2)) - (x367 + ((~(((x369 ^ -1) | (-(x369 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
        int x375 = x374[x501];
        int * x376 = x306->cache_vals;
        int x503 = (((4 + ((((int)((unsigned int)(x314 + x316) >> 1)) & 3) * 2)) + ((((x363 + ((~(((x365 ^ -1) | (-(x365 ^ -1))) >> 31)) & 2)) - (x367 + ((~(((x369 ^ -1) | (-(x369 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
        int x377 = x376[x503];
        int * x378 = x306->mem;
        int x505 = x373 * 2;
        x378[x505] = x375;
        int * x380 = x306->mem;
        int x508 = (x373 * 2) + 1;
        x380[x508] = x377;
        ;
      } else {
        ;
      }
      int * x385 = x306->mem;
      int x513 = ((int)((unsigned int)(x314 + x316) >> 1)) * 2;
      int x386 = x385[x513];
      int * x387 = x306->mem;
      int x515 = (((int)((unsigned int)(x314 + x316) >> 1)) * 2) + 1;
      int x388 = x387[x515];
      int * x389 = x306->cache_vals;
      int x517 = ((4 + ((((int)((unsigned int)(x314 + x316) >> 1)) & 3) * 2)) + ((((x363 + ((~(((x365 ^ -1) | (-(x365 ^ -1))) >> 31)) & 2)) - (x367 + ((~(((x369 ^ -1) | (-(x369 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
      x389[x517] = x386;
      int * x391 = x306->cache_vals;
      int x520 = (((4 + ((((int)((unsigned int)(x314 + x316) >> 1)) & 3) * 2)) + ((((x363 + ((~(((x365 ^ -1) | (-(x365 ^ -1))) >> 31)) & 2)) - (x367 + ((~(((x369 ^ -1) | (-(x369 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
      x391[x520] = x388;
      int * x393 = x306->cache_tags;
      int x523 = (int)((unsigned int)(x314 + x316) >> 1);
      x393[x497] = x523;
      int * x395 = x306->cache_dirty;
      x395[x497] = 0;
      int * x397 = x306->cache_age;
      x397[x497] = 1;
      int * x399 = x306->cache_age;
      int x400 = x399[x497];
      int * x401 = x306->cache_age;
      int x402 = x401[x460];
      int * x403 = x306->cache_age;
      int x530 = x402 + ((int)((unsigned int)(x402 - x400) >> 31));
      x403[x460] = x530;
      int * x405 = x306->cache_age;
      int x406 = x405[x462];
      int * x407 = x306->cache_age;
      int x533 = x406 + ((int)((unsigned int)(x406 - x400) >> 31));
      x407[x462] = x533;
      int * x409 = x306->cache_age;
      x409[x497] = 0;
      x412 = x497;
    }
    int * x413 = x306->cache_vals;
    int x536 = x412 * 2;
    int x414 = x413[x536];
    int * x415 = x306->cache_vals;
    int x538 = (x412 * 2) + 1;
    int x416 = x415[x538];
    int * x417 = x306->cache_vals;
    int x540 = (((((int)((unsigned int)(x314 + x316) >> 1)) & 1) * 2) + ((((x342 + ((~(((x344 ^ -1) | (-(x344 ^ -1))) >> 31)) & 2)) - (x346 + ((~(((x348 ^ -1) | (-(x348 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
    x417[x540] = x414;
    int * x419 = x306->cache_vals;
    int x543 = ((((((int)((unsigned int)(x314 + x316) >> 1)) & 1) * 2) + ((((x342 + ((~(((x344 ^ -1) | (-(x344 ^ -1))) >> 31)) & 2)) - (x346 + ((~(((x348 ^ -1) | (-(x348 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
    x419[x543] = x416;
    int * x421 = x306->cache_tags;
    int x546 = ((((int)((unsigned int)(x314 + x316) >> 1)) & 1) * 2) + ((((x342 + ((~(((x344 ^ -1) | (-(x344 ^ -1))) >> 31)) & 2)) - (x346 + ((~(((x348 ^ -1) | (-(x348 ^ -1))) >> 31)) & 2))) >> 31) & 1);
    int x547 = (int)((unsigned int)(x314 + x316) >> 1);
    x421[x546] = x547;
    int * x423 = x306->cache_dirty;
    x423[x546] = 0;
    int * x425 = x306->cache_age;
    x425[x546] = 1;
    int * x427 = x306->cache_age;
    int x428 = x427[x546];
    int * x429 = x306->cache_age;
    int x430 = x429[x456];
    int * x431 = x306->cache_age;
    int x554 = x430 + ((int)((unsigned int)(x430 - x428) >> 31));
    x431[x456] = x554;
    int * x433 = x306->cache_age;
    int x434 = x433[x458];
    int * x435 = x306->cache_age;
    int x557 = x434 + ((int)((unsigned int)(x434 - x428) >> 31));
    x435[x458] = x557;
    int * x437 = x306->cache_age;
    x437[x546] = 0;
    x440 = x546;
  }
  int x560 = (x440 * 2) + ((x314 + x316) & 1);
  int x441 = x327[x560];
  int * x442 = x306->regs;
  x442[1] = x441;
  struct StateT * x444 = slot_6(x306);
  return x444;
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

struct StateT * slot_7(struct StateT * x601) {
  int x602 = x601->timer;
  int x607 = x602 + 1;
  x601->timer = x607;
  int * x604 = x601->regs;
  x604[0] = 1;
  return x601;
}

struct StateT * slot_3(struct StateT * x41) {
  int x42 = x41->timer;
  int x46 = x42 + 1;
  x41->timer = x46;
  struct StateT * x44 = slot_4(x41);
  return x44;
}

struct StateT * snippet(struct StateT * x0) {
  struct StateT * x1 = slot_0(x0);
  return x1;
}

struct StateT * slot_10(struct StateT * x619) {
  int * x620 = x619->regs;
  int x621 = x620[0];
  int * x622 = x619->regs;
  int x623 = x622[1];
  bool x636 = !(x621 == x623);
  struct StateT * x630;
  if (x636) {
    int x624 = x619->timer;
    int x637 = x624 + 15;
    x619->timer = x637;
    struct StateT * x626 = slot_11(x619);
    x630 = x626;
  } else {
    struct StateT * x628 = slot_12(x619);
    x630 = x628;
  }
  return x630;
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

struct StateT * slot_8(struct StateT * x611) {
  int x612 = x611->timer;
  int x616 = x612 + 1;
  x611->timer = x616;
  struct StateT * x614 = slot_10(x611);
  return x614;
}

struct StateT * slot_4(struct StateT * x49) {
  int * x50 = x49->saved_regs;
  int * x51 = x49->regs;
  int x52 = x51[0];
  x50[0] = x52;
  int x54 = x49->timer;
  int x193 = x54 + 1;
  x49->timer = x193;
  int * x56 = x49->regs;
  int x57 = x56[2];
  int * x58 = x49->regs;
  int x59 = x58[4];
  int * x60 = x49->cache_tags;
  int x199 = (((int)((unsigned int)(x57 + x59) >> 1)) & 1) * 2;
  int x61 = x60[x199];
  int * x62 = x49->cache_tags;
  int x201 = ((((int)((unsigned int)(x57 + x59) >> 1)) & 1) * 2) + 1;
  int x63 = x62[x201];
  int * x64 = x49->cache_tags;
  int x203 = 4 + ((((int)((unsigned int)(x57 + x59) >> 1)) & 3) * 2);
  int x65 = x64[x203];
  int * x66 = x49->cache_tags;
  int x205 = (4 + ((((int)((unsigned int)(x57 + x59) >> 1)) & 3) * 2)) + 1;
  int x67 = x66[x205];
  int x68 = x49->timer;
  int x206 = x68 + ((100 ^ (((~(((x65 ^ ((int)((unsigned int)(x57 + x59) >> 1))) | (-(x65 ^ ((int)((unsigned int)(x57 + x59) >> 1))))) >> 31)) | (~(((x67 ^ ((int)((unsigned int)(x57 + x59) >> 1))) | (-(x67 ^ ((int)((unsigned int)(x57 + x59) >> 1))))) >> 31))) & 104)) ^ (((~(((x61 ^ ((int)((unsigned int)(x57 + x59) >> 1))) | (-(x61 ^ ((int)((unsigned int)(x57 + x59) >> 1))))) >> 31)) | (~(((x63 ^ ((int)((unsigned int)(x57 + x59) >> 1))) | (-(x63 ^ ((int)((unsigned int)(x57 + x59) >> 1))))) >> 31))) & (1 ^ (100 ^ (((~(((x65 ^ ((int)((unsigned int)(x57 + x59) >> 1))) | (-(x65 ^ ((int)((unsigned int)(x57 + x59) >> 1))))) >> 31)) | (~(((x67 ^ ((int)((unsigned int)(x57 + x59) >> 1))) | (-(x67 ^ ((int)((unsigned int)(x57 + x59) >> 1))))) >> 31))) & 104)))));
  x49->timer = x206;
  int * x70 = x49->cache_vals;
  bool x207 = !(((~(((x61 ^ ((int)((unsigned int)(x57 + x59) >> 1))) | (-(x61 ^ ((int)((unsigned int)(x57 + x59) >> 1))))) >> 31)) | (~(((x63 ^ ((int)((unsigned int)(x57 + x59) >> 1))) | (-(x63 ^ ((int)((unsigned int)(x57 + x59) >> 1))))) >> 31))) == 0);
  int x183;
  if (x207) {
    int * x71 = x49->cache_age;
    int x209 = ((((int)((unsigned int)(x57 + x59) >> 1)) & 1) * 2) + ((~(((x63 ^ ((int)((unsigned int)(x57 + x59) >> 1))) | (-(x63 ^ ((int)((unsigned int)(x57 + x59) >> 1))))) >> 31)) & 1);
    int x72 = x71[x209];
    int * x73 = x49->cache_age;
    int x74 = x73[x199];
    int * x75 = x49->cache_age;
    int x212 = x74 + ((int)((unsigned int)(x74 - x72) >> 31));
    x75[x199] = x212;
    int * x77 = x49->cache_age;
    int x78 = x77[x201];
    int * x79 = x49->cache_age;
    int x215 = x78 + ((int)((unsigned int)(x78 - x72) >> 31));
    x79[x201] = x215;
    int * x81 = x49->cache_age;
    x81[x209] = 0;
    x183 = x209;
  } else {
    int * x84 = x49->cache_age;
    int x218 = (((int)((unsigned int)(x57 + x59) >> 1)) & 1) * 2;
    int x85 = x84[x218];
    int * x86 = x49->cache_tags;
    int x87 = x86[x218];
    int * x88 = x49->cache_age;
    int x89 = x88[x201];
    int * x90 = x49->cache_tags;
    int x91 = x90[x201];
    bool x222 = !(((~(((x65 ^ ((int)((unsigned int)(x57 + x59) >> 1))) | (-(x65 ^ ((int)((unsigned int)(x57 + x59) >> 1))))) >> 31)) | (~(((x67 ^ ((int)((unsigned int)(x57 + x59) >> 1))) | (-(x67 ^ ((int)((unsigned int)(x57 + x59) >> 1))))) >> 31))) == 0);
    int x155;
    if (x222) {
      int * x92 = x49->cache_age;
      int x224 = (4 + ((((int)((unsigned int)(x57 + x59) >> 1)) & 3) * 2)) + ((~(((x67 ^ ((int)((unsigned int)(x57 + x59) >> 1))) | (-(x67 ^ ((int)((unsigned int)(x57 + x59) >> 1))))) >> 31)) & 1);
      int x93 = x92[x224];
      int * x94 = x49->cache_age;
      int x95 = x94[x203];
      int * x96 = x49->cache_age;
      int x227 = x95 + ((int)((unsigned int)(x95 - x93) >> 31));
      x96[x203] = x227;
      int * x98 = x49->cache_age;
      int x99 = x98[x205];
      int * x100 = x49->cache_age;
      int x230 = x99 + ((int)((unsigned int)(x99 - x93) >> 31));
      x100[x205] = x230;
      int * x102 = x49->cache_age;
      x102[x224] = 0;
      x155 = x224;
    } else {
      int * x105 = x49->cache_age;
      int x233 = 4 + ((((int)((unsigned int)(x57 + x59) >> 1)) & 3) * 2);
      int x106 = x105[x233];
      int * x107 = x49->cache_tags;
      int x108 = x107[x233];
      int * x109 = x49->cache_age;
      int x110 = x109[x205];
      int * x111 = x49->cache_tags;
      int x112 = x111[x205];
      int * x113 = x49->cache_dirty;
      int x238 = (4 + ((((int)((unsigned int)(x57 + x59) >> 1)) & 3) * 2)) + ((((x106 + ((~(((x108 ^ -1) | (-(x108 ^ -1))) >> 31)) & 2)) - (x110 + ((~(((x112 ^ -1) | (-(x112 ^ -1))) >> 31)) & 2))) >> 31) & 1);
      int x114 = x113[x238];
      bool x239 = !(x114 == 0);
      if (x239) {
        int * x115 = x49->cache_tags;
        int x116 = x115[x238];
        int * x117 = x49->cache_vals;
        int x242 = ((4 + ((((int)((unsigned int)(x57 + x59) >> 1)) & 3) * 2)) + ((((x106 + ((~(((x108 ^ -1) | (-(x108 ^ -1))) >> 31)) & 2)) - (x110 + ((~(((x112 ^ -1) | (-(x112 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
        int x118 = x117[x242];
        int * x119 = x49->cache_vals;
        int x244 = (((4 + ((((int)((unsigned int)(x57 + x59) >> 1)) & 3) * 2)) + ((((x106 + ((~(((x108 ^ -1) | (-(x108 ^ -1))) >> 31)) & 2)) - (x110 + ((~(((x112 ^ -1) | (-(x112 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
        int x120 = x119[x244];
        int * x121 = x49->mem;
        int x246 = x116 * 2;
        x121[x246] = x118;
        int * x123 = x49->mem;
        int x249 = (x116 * 2) + 1;
        x123[x249] = x120;
        ;
      } else {
        ;
      }
      int * x128 = x49->mem;
      int x254 = ((int)((unsigned int)(x57 + x59) >> 1)) * 2;
      int x129 = x128[x254];
      int * x130 = x49->mem;
      int x256 = (((int)((unsigned int)(x57 + x59) >> 1)) * 2) + 1;
      int x131 = x130[x256];
      int * x132 = x49->cache_vals;
      int x258 = ((4 + ((((int)((unsigned int)(x57 + x59) >> 1)) & 3) * 2)) + ((((x106 + ((~(((x108 ^ -1) | (-(x108 ^ -1))) >> 31)) & 2)) - (x110 + ((~(((x112 ^ -1) | (-(x112 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
      x132[x258] = x129;
      int * x134 = x49->cache_vals;
      int x261 = (((4 + ((((int)((unsigned int)(x57 + x59) >> 1)) & 3) * 2)) + ((((x106 + ((~(((x108 ^ -1) | (-(x108 ^ -1))) >> 31)) & 2)) - (x110 + ((~(((x112 ^ -1) | (-(x112 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
      x134[x261] = x131;
      int * x136 = x49->cache_tags;
      int x264 = (int)((unsigned int)(x57 + x59) >> 1);
      x136[x238] = x264;
      int * x138 = x49->cache_dirty;
      x138[x238] = 0;
      int * x140 = x49->cache_age;
      x140[x238] = 1;
      int * x142 = x49->cache_age;
      int x143 = x142[x238];
      int * x144 = x49->cache_age;
      int x145 = x144[x203];
      int * x146 = x49->cache_age;
      int x271 = x145 + ((int)((unsigned int)(x145 - x143) >> 31));
      x146[x203] = x271;
      int * x148 = x49->cache_age;
      int x149 = x148[x205];
      int * x150 = x49->cache_age;
      int x274 = x149 + ((int)((unsigned int)(x149 - x143) >> 31));
      x150[x205] = x274;
      int * x152 = x49->cache_age;
      x152[x238] = 0;
      x155 = x238;
    }
    int * x156 = x49->cache_vals;
    int x277 = x155 * 2;
    int x157 = x156[x277];
    int * x158 = x49->cache_vals;
    int x279 = (x155 * 2) + 1;
    int x159 = x158[x279];
    int * x160 = x49->cache_vals;
    int x281 = (((((int)((unsigned int)(x57 + x59) >> 1)) & 1) * 2) + ((((x85 + ((~(((x87 ^ -1) | (-(x87 ^ -1))) >> 31)) & 2)) - (x89 + ((~(((x91 ^ -1) | (-(x91 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
    x160[x281] = x157;
    int * x162 = x49->cache_vals;
    int x284 = ((((((int)((unsigned int)(x57 + x59) >> 1)) & 1) * 2) + ((((x85 + ((~(((x87 ^ -1) | (-(x87 ^ -1))) >> 31)) & 2)) - (x89 + ((~(((x91 ^ -1) | (-(x91 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
    x162[x284] = x159;
    int * x164 = x49->cache_tags;
    int x287 = ((((int)((unsigned int)(x57 + x59) >> 1)) & 1) * 2) + ((((x85 + ((~(((x87 ^ -1) | (-(x87 ^ -1))) >> 31)) & 2)) - (x89 + ((~(((x91 ^ -1) | (-(x91 ^ -1))) >> 31)) & 2))) >> 31) & 1);
    int x288 = (int)((unsigned int)(x57 + x59) >> 1);
    x164[x287] = x288;
    int * x166 = x49->cache_dirty;
    x166[x287] = 0;
    int * x168 = x49->cache_age;
    x168[x287] = 1;
    int * x170 = x49->cache_age;
    int x171 = x170[x287];
    int * x172 = x49->cache_age;
    int x173 = x172[x199];
    int * x174 = x49->cache_age;
    int x295 = x173 + ((int)((unsigned int)(x173 - x171) >> 31));
    x174[x199] = x295;
    int * x176 = x49->cache_age;
    int x177 = x176[x201];
    int * x178 = x49->cache_age;
    int x298 = x177 + ((int)((unsigned int)(x177 - x171) >> 31));
    x178[x201] = x298;
    int * x180 = x49->cache_age;
    x180[x287] = 0;
    x183 = x287;
  }
  int x301 = (x183 * 2) + ((x57 + x59) & 1);
  int x184 = x70[x301];
  int * x185 = x49->regs;
  x185[0] = x184;
  struct StateT * x187 = slot_5(x49);
  return x187;
}

struct StateT * slot_13(struct StateT * x671) {
  int x672 = x671->timer;
  int x675 = x672 + 1;
  x671->timer = x675;
  return x671;
}

struct StateT * slot_11(struct StateT * x643) {
  int x644 = x643->timer;
  int x650 = x644 + 1;
  x643->timer = x650;
  int * x646 = x643->regs;
  x646[0] = 0;
  struct StateT * x648 = slot_13(x643);
  return x648;
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