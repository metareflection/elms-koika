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
#define koika_secret(x) ((void)0)
#else
#define koika_assert(b, s) 0
#define koika_assume(b) 0
#define koika_draw(x) ((x) = 0)
#define koika_secret(x) ((void)0)
#endif
int bounded(int low, int high) {
  int x;
  koika_draw(x);
  koika_assume(low <= x && x <= high);
  return x;
}
// Same draw as `bounded`, said of the secret, so a backend that tracks
// where the secret goes has somewhere to start. Self-composition already
// encodes the split by drawing these twice, which is why the mark is
// nothing under a checker that reads the two runs exactly.
int secret(int low, int high) {
  int x = bounded(low, high);
  koika_secret(x);
  return x;
}

/*****************************************
Emitting C Generated Code
*******************************************/

#include <stdbool.h>

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

struct StateT * slot_6(struct StateT * x483);
struct StateT * slot_5(struct StateT * x277);
struct StateT * slot_2(struct StateT * x28);
struct StateT * slot_7(struct StateT * x517);
struct StateT * slot_3(struct StateT * x41);
struct StateT * snippet(struct StateT * x0);
struct StateT * slot_10(struct StateT * x531);
struct StateT * slot_1(struct StateT * x15);
struct StateT * slot_8(struct StateT * x536);
struct StateT * slot_4(struct StateT * x71);
struct StateT * slot_9(struct StateT * x505);
struct StateT * slot_11(struct StateT * x61);
struct StateT * slot_0(struct StateT * x2);
struct StateT * slot_6(struct StateT * x483) {
  int x484 = x483->timer;
  int x495 = x484 + 1;
  x483->timer = x495;
  int * x486 = x483->regs;
  int x487 = x486[0];
  int x488 = x486[1];
  bool x499 = !(x487 == x488);
  struct StateT * x493;
  if (x499) {
    struct StateT * x489 = slot_9(x483);
    x493 = x489;
  } else {
    struct StateT * x491 = slot_7(x483);
    x493 = x491;
  }
  return x493;
}

struct StateT * slot_5(struct StateT * x277) {
  int x278 = x277->timer;
  int x389 = x278 + 1;
  x277->timer = x389;
  int * x280 = x277->regs;
  int x281 = x280[3];
  int x282 = x280[4];
  int * x283 = x277->cache_tags;
  int x394 = (((int)((unsigned int)(x281 + x282) >> 1)) & 1) * 2;
  int x284 = x283[x394];
  int x395 = ((((int)((unsigned int)(x281 + x282) >> 1)) & 1) * 2) + 1;
  int x285 = x283[x395];
  int x396 = 4 + ((((int)((unsigned int)(x281 + x282) >> 1)) & 3) * 2);
  int x286 = x283[x396];
  int x397 = (4 + ((((int)((unsigned int)(x281 + x282) >> 1)) & 3) * 2)) + 1;
  int x287 = x283[x397];
  int x288 = x277->timer;
  int x398 = x288 + ((100 ^ (((~(((x286 ^ ((int)((unsigned int)(x281 + x282) >> 1))) | (-(x286 ^ ((int)((unsigned int)(x281 + x282) >> 1))))) >> 31)) | (~(((x287 ^ ((int)((unsigned int)(x281 + x282) >> 1))) | (-(x287 ^ ((int)((unsigned int)(x281 + x282) >> 1))))) >> 31))) & 104)) ^ (((~(((x284 ^ ((int)((unsigned int)(x281 + x282) >> 1))) | (-(x284 ^ ((int)((unsigned int)(x281 + x282) >> 1))))) >> 31)) | (~(((x285 ^ ((int)((unsigned int)(x281 + x282) >> 1))) | (-(x285 ^ ((int)((unsigned int)(x281 + x282) >> 1))))) >> 31))) & (1 ^ (100 ^ (((~(((x286 ^ ((int)((unsigned int)(x281 + x282) >> 1))) | (-(x286 ^ ((int)((unsigned int)(x281 + x282) >> 1))))) >> 31)) | (~(((x287 ^ ((int)((unsigned int)(x281 + x282) >> 1))) | (-(x287 ^ ((int)((unsigned int)(x281 + x282) >> 1))))) >> 31))) & 104)))));
  x277->timer = x398;
  int * x290 = x277->cache_vals;
  bool x399 = !(((~(((x284 ^ ((int)((unsigned int)(x281 + x282) >> 1))) | (-(x284 ^ ((int)((unsigned int)(x281 + x282) >> 1))))) >> 31)) | (~(((x285 ^ ((int)((unsigned int)(x281 + x282) >> 1))) | (-(x285 ^ ((int)((unsigned int)(x281 + x282) >> 1))))) >> 31))) == 0);
  int x383;
  if (x399) {
    int * x291 = x277->cache_age;
    int x401 = ((((int)((unsigned int)(x281 + x282) >> 1)) & 1) * 2) + ((~(((x285 ^ ((int)((unsigned int)(x281 + x282) >> 1))) | (-(x285 ^ ((int)((unsigned int)(x281 + x282) >> 1))))) >> 31)) & 1);
    int x292 = x291[x401];
    int x293 = x291[x394];
    int x402 = x293 + ((int)((unsigned int)(x293 - x292) >> 31));
    x291[x394] = x402;
    int * x295 = x277->cache_age;
    int x296 = x295[x395];
    int x404 = x296 + ((int)((unsigned int)(x296 - x292) >> 31));
    x295[x395] = x404;
    int * x298 = x277->cache_age;
    x298[x401] = 0;
    x383 = x401;
  } else {
    int * x301 = x277->cache_age;
    int x408 = (((int)((unsigned int)(x281 + x282) >> 1)) & 1) * 2;
    int x302 = x301[x408];
    int * x303 = x277->cache_tags;
    int x304 = x303[x408];
    int x305 = x301[x395];
    int x306 = x303[x395];
    bool x410 = !(((~(((x286 ^ ((int)((unsigned int)(x281 + x282) >> 1))) | (-(x286 ^ ((int)((unsigned int)(x281 + x282) >> 1))))) >> 31)) | (~(((x287 ^ ((int)((unsigned int)(x281 + x282) >> 1))) | (-(x287 ^ ((int)((unsigned int)(x281 + x282) >> 1))))) >> 31))) == 0);
    int x360;
    if (x410) {
      int * x307 = x277->cache_age;
      int x412 = (4 + ((((int)((unsigned int)(x281 + x282) >> 1)) & 3) * 2)) + ((~(((x287 ^ ((int)((unsigned int)(x281 + x282) >> 1))) | (-(x287 ^ ((int)((unsigned int)(x281 + x282) >> 1))))) >> 31)) & 1);
      int x308 = x307[x412];
      int x309 = x307[x396];
      int x413 = x309 + ((int)((unsigned int)(x309 - x308) >> 31));
      x307[x396] = x413;
      int * x311 = x277->cache_age;
      int x312 = x311[x397];
      int x415 = x312 + ((int)((unsigned int)(x312 - x308) >> 31));
      x311[x397] = x415;
      int * x314 = x277->cache_age;
      x314[x412] = 0;
      x360 = x412;
    } else {
      int * x317 = x277->cache_age;
      int x419 = 4 + ((((int)((unsigned int)(x281 + x282) >> 1)) & 3) * 2);
      int x318 = x317[x419];
      int * x319 = x277->cache_tags;
      int x320 = x319[x419];
      int x321 = x317[x397];
      int x322 = x319[x397];
      int * x323 = x277->cache_dirty;
      int x422 = (4 + ((((int)((unsigned int)(x281 + x282) >> 1)) & 3) * 2)) + ((((x318 + ((~(((x320 ^ -1) | (-(x320 ^ -1))) >> 31)) & 2)) - (x321 + ((~(((x322 ^ -1) | (-(x322 ^ -1))) >> 31)) & 2))) >> 31) & 1);
      int x324 = x323[x422];
      bool x423 = !(x324 == 0);
      if (x423) {
        int * x325 = x277->cache_tags;
        int x326 = x325[x422];
        int * x327 = x277->cache_vals;
        int x426 = ((4 + ((((int)((unsigned int)(x281 + x282) >> 1)) & 3) * 2)) + ((((x318 + ((~(((x320 ^ -1) | (-(x320 ^ -1))) >> 31)) & 2)) - (x321 + ((~(((x322 ^ -1) | (-(x322 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
        int x328 = x327[x426];
        int x427 = (((4 + ((((int)((unsigned int)(x281 + x282) >> 1)) & 3) * 2)) + ((((x318 + ((~(((x320 ^ -1) | (-(x320 ^ -1))) >> 31)) & 2)) - (x321 + ((~(((x322 ^ -1) | (-(x322 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
        int x329 = x327[x427];
        int * x330 = x277->mem;
        int x429 = x326 * 2;
        x330[x429] = x328;
        int * x332 = x277->mem;
        int x432 = (x326 * 2) + 1;
        x332[x432] = x329;
        ;
      } else {
        ;
      }
      int * x337 = x277->mem;
      int x437 = ((int)((unsigned int)(x281 + x282) >> 1)) * 2;
      int x338 = x337[x437];
      int x438 = (((int)((unsigned int)(x281 + x282) >> 1)) * 2) + 1;
      int x339 = x337[x438];
      int * x340 = x277->cache_vals;
      int x440 = ((4 + ((((int)((unsigned int)(x281 + x282) >> 1)) & 3) * 2)) + ((((x318 + ((~(((x320 ^ -1) | (-(x320 ^ -1))) >> 31)) & 2)) - (x321 + ((~(((x322 ^ -1) | (-(x322 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
      x340[x440] = x338;
      int * x342 = x277->cache_vals;
      int x443 = (((4 + ((((int)((unsigned int)(x281 + x282) >> 1)) & 3) * 2)) + ((((x318 + ((~(((x320 ^ -1) | (-(x320 ^ -1))) >> 31)) & 2)) - (x321 + ((~(((x322 ^ -1) | (-(x322 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
      x342[x443] = x339;
      int * x344 = x277->cache_tags;
      int x446 = (int)((unsigned int)(x281 + x282) >> 1);
      x344[x422] = x446;
      int * x346 = x277->cache_dirty;
      x346[x422] = 0;
      int * x348 = x277->cache_age;
      x348[x422] = 1;
      int * x350 = x277->cache_age;
      int x351 = x350[x422];
      int x352 = x350[x396];
      int x452 = x352 + ((int)((unsigned int)(x352 - x351) >> 31));
      x350[x396] = x452;
      int * x354 = x277->cache_age;
      int x355 = x354[x397];
      int x454 = x355 + ((int)((unsigned int)(x355 - x351) >> 31));
      x354[x397] = x454;
      int * x357 = x277->cache_age;
      x357[x422] = 0;
      x360 = x422;
    }
    int * x361 = x277->cache_vals;
    int x457 = x360 * 2;
    int x362 = x361[x457];
    int x458 = (x360 * 2) + 1;
    int x363 = x361[x458];
    int x459 = (((((int)((unsigned int)(x281 + x282) >> 1)) & 1) * 2) + ((((x302 + ((~(((x304 ^ -1) | (-(x304 ^ -1))) >> 31)) & 2)) - (x305 + ((~(((x306 ^ -1) | (-(x306 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
    x361[x459] = x362;
    int * x365 = x277->cache_vals;
    int x462 = ((((((int)((unsigned int)(x281 + x282) >> 1)) & 1) * 2) + ((((x302 + ((~(((x304 ^ -1) | (-(x304 ^ -1))) >> 31)) & 2)) - (x305 + ((~(((x306 ^ -1) | (-(x306 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
    x365[x462] = x363;
    int * x367 = x277->cache_tags;
    int x465 = ((((int)((unsigned int)(x281 + x282) >> 1)) & 1) * 2) + ((((x302 + ((~(((x304 ^ -1) | (-(x304 ^ -1))) >> 31)) & 2)) - (x305 + ((~(((x306 ^ -1) | (-(x306 ^ -1))) >> 31)) & 2))) >> 31) & 1);
    int x466 = (int)((unsigned int)(x281 + x282) >> 1);
    x367[x465] = x466;
    int * x369 = x277->cache_dirty;
    x369[x465] = 0;
    int * x371 = x277->cache_age;
    x371[x465] = 1;
    int * x373 = x277->cache_age;
    int x374 = x373[x465];
    int x375 = x373[x394];
    int x472 = x375 + ((int)((unsigned int)(x375 - x374) >> 31));
    x373[x394] = x472;
    int * x377 = x277->cache_age;
    int x378 = x377[x395];
    int x474 = x378 + ((int)((unsigned int)(x378 - x374) >> 31));
    x377[x395] = x474;
    int * x380 = x277->cache_age;
    x380[x465] = 0;
    x383 = x465;
  }
  int x477 = (x383 * 2) + ((x281 + x282) & 1);
  int x384 = x290[x477];
  int * x385 = x277->regs;
  x385[1] = x384;
  struct StateT * x387 = slot_6(x277);
  return x387;
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

struct StateT * slot_7(struct StateT * x517) {
  int x518 = x517->timer;
  int x525 = x518 + 1;
  x517->timer = x525;
  int * x520 = x517->regs;
  int x521 = x520[4];
  int x528 = x521 + 1;
  x520[4] = x528;
  struct StateT * x523 = slot_8(x517);
  return x523;
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

struct StateT * slot_10(struct StateT * x531) {
  int x532 = x531->timer;
  int x535 = x532 + 1;
  x531->timer = x535;
  return x531;
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

struct StateT * slot_8(struct StateT * x536) {
  int x537 = x536->timer;
  int x541 = x537 + 1;
  x536->timer = x541;
  struct StateT * x539 = slot_3(x536);
  return x539;
}

struct StateT * slot_4(struct StateT * x71) {
  int x72 = x71->timer;
  int x183 = x72 + 1;
  x71->timer = x183;
  int * x74 = x71->regs;
  int x75 = x74[2];
  int x76 = x74[4];
  int * x77 = x71->cache_tags;
  int x188 = (((int)((unsigned int)(x75 + x76) >> 1)) & 1) * 2;
  int x78 = x77[x188];
  int x189 = ((((int)((unsigned int)(x75 + x76) >> 1)) & 1) * 2) + 1;
  int x79 = x77[x189];
  int x190 = 4 + ((((int)((unsigned int)(x75 + x76) >> 1)) & 3) * 2);
  int x80 = x77[x190];
  int x191 = (4 + ((((int)((unsigned int)(x75 + x76) >> 1)) & 3) * 2)) + 1;
  int x81 = x77[x191];
  int x82 = x71->timer;
  int x192 = x82 + ((100 ^ (((~(((x80 ^ ((int)((unsigned int)(x75 + x76) >> 1))) | (-(x80 ^ ((int)((unsigned int)(x75 + x76) >> 1))))) >> 31)) | (~(((x81 ^ ((int)((unsigned int)(x75 + x76) >> 1))) | (-(x81 ^ ((int)((unsigned int)(x75 + x76) >> 1))))) >> 31))) & 104)) ^ (((~(((x78 ^ ((int)((unsigned int)(x75 + x76) >> 1))) | (-(x78 ^ ((int)((unsigned int)(x75 + x76) >> 1))))) >> 31)) | (~(((x79 ^ ((int)((unsigned int)(x75 + x76) >> 1))) | (-(x79 ^ ((int)((unsigned int)(x75 + x76) >> 1))))) >> 31))) & (1 ^ (100 ^ (((~(((x80 ^ ((int)((unsigned int)(x75 + x76) >> 1))) | (-(x80 ^ ((int)((unsigned int)(x75 + x76) >> 1))))) >> 31)) | (~(((x81 ^ ((int)((unsigned int)(x75 + x76) >> 1))) | (-(x81 ^ ((int)((unsigned int)(x75 + x76) >> 1))))) >> 31))) & 104)))));
  x71->timer = x192;
  int * x84 = x71->cache_vals;
  bool x193 = !(((~(((x78 ^ ((int)((unsigned int)(x75 + x76) >> 1))) | (-(x78 ^ ((int)((unsigned int)(x75 + x76) >> 1))))) >> 31)) | (~(((x79 ^ ((int)((unsigned int)(x75 + x76) >> 1))) | (-(x79 ^ ((int)((unsigned int)(x75 + x76) >> 1))))) >> 31))) == 0);
  int x177;
  if (x193) {
    int * x85 = x71->cache_age;
    int x195 = ((((int)((unsigned int)(x75 + x76) >> 1)) & 1) * 2) + ((~(((x79 ^ ((int)((unsigned int)(x75 + x76) >> 1))) | (-(x79 ^ ((int)((unsigned int)(x75 + x76) >> 1))))) >> 31)) & 1);
    int x86 = x85[x195];
    int x87 = x85[x188];
    int x196 = x87 + ((int)((unsigned int)(x87 - x86) >> 31));
    x85[x188] = x196;
    int * x89 = x71->cache_age;
    int x90 = x89[x189];
    int x198 = x90 + ((int)((unsigned int)(x90 - x86) >> 31));
    x89[x189] = x198;
    int * x92 = x71->cache_age;
    x92[x195] = 0;
    x177 = x195;
  } else {
    int * x95 = x71->cache_age;
    int x202 = (((int)((unsigned int)(x75 + x76) >> 1)) & 1) * 2;
    int x96 = x95[x202];
    int * x97 = x71->cache_tags;
    int x98 = x97[x202];
    int x99 = x95[x189];
    int x100 = x97[x189];
    bool x204 = !(((~(((x80 ^ ((int)((unsigned int)(x75 + x76) >> 1))) | (-(x80 ^ ((int)((unsigned int)(x75 + x76) >> 1))))) >> 31)) | (~(((x81 ^ ((int)((unsigned int)(x75 + x76) >> 1))) | (-(x81 ^ ((int)((unsigned int)(x75 + x76) >> 1))))) >> 31))) == 0);
    int x154;
    if (x204) {
      int * x101 = x71->cache_age;
      int x206 = (4 + ((((int)((unsigned int)(x75 + x76) >> 1)) & 3) * 2)) + ((~(((x81 ^ ((int)((unsigned int)(x75 + x76) >> 1))) | (-(x81 ^ ((int)((unsigned int)(x75 + x76) >> 1))))) >> 31)) & 1);
      int x102 = x101[x206];
      int x103 = x101[x190];
      int x207 = x103 + ((int)((unsigned int)(x103 - x102) >> 31));
      x101[x190] = x207;
      int * x105 = x71->cache_age;
      int x106 = x105[x191];
      int x209 = x106 + ((int)((unsigned int)(x106 - x102) >> 31));
      x105[x191] = x209;
      int * x108 = x71->cache_age;
      x108[x206] = 0;
      x154 = x206;
    } else {
      int * x111 = x71->cache_age;
      int x213 = 4 + ((((int)((unsigned int)(x75 + x76) >> 1)) & 3) * 2);
      int x112 = x111[x213];
      int * x113 = x71->cache_tags;
      int x114 = x113[x213];
      int x115 = x111[x191];
      int x116 = x113[x191];
      int * x117 = x71->cache_dirty;
      int x216 = (4 + ((((int)((unsigned int)(x75 + x76) >> 1)) & 3) * 2)) + ((((x112 + ((~(((x114 ^ -1) | (-(x114 ^ -1))) >> 31)) & 2)) - (x115 + ((~(((x116 ^ -1) | (-(x116 ^ -1))) >> 31)) & 2))) >> 31) & 1);
      int x118 = x117[x216];
      bool x217 = !(x118 == 0);
      if (x217) {
        int * x119 = x71->cache_tags;
        int x120 = x119[x216];
        int * x121 = x71->cache_vals;
        int x220 = ((4 + ((((int)((unsigned int)(x75 + x76) >> 1)) & 3) * 2)) + ((((x112 + ((~(((x114 ^ -1) | (-(x114 ^ -1))) >> 31)) & 2)) - (x115 + ((~(((x116 ^ -1) | (-(x116 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
        int x122 = x121[x220];
        int x221 = (((4 + ((((int)((unsigned int)(x75 + x76) >> 1)) & 3) * 2)) + ((((x112 + ((~(((x114 ^ -1) | (-(x114 ^ -1))) >> 31)) & 2)) - (x115 + ((~(((x116 ^ -1) | (-(x116 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
        int x123 = x121[x221];
        int * x124 = x71->mem;
        int x223 = x120 * 2;
        x124[x223] = x122;
        int * x126 = x71->mem;
        int x226 = (x120 * 2) + 1;
        x126[x226] = x123;
        ;
      } else {
        ;
      }
      int * x131 = x71->mem;
      int x231 = ((int)((unsigned int)(x75 + x76) >> 1)) * 2;
      int x132 = x131[x231];
      int x232 = (((int)((unsigned int)(x75 + x76) >> 1)) * 2) + 1;
      int x133 = x131[x232];
      int * x134 = x71->cache_vals;
      int x234 = ((4 + ((((int)((unsigned int)(x75 + x76) >> 1)) & 3) * 2)) + ((((x112 + ((~(((x114 ^ -1) | (-(x114 ^ -1))) >> 31)) & 2)) - (x115 + ((~(((x116 ^ -1) | (-(x116 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
      x134[x234] = x132;
      int * x136 = x71->cache_vals;
      int x237 = (((4 + ((((int)((unsigned int)(x75 + x76) >> 1)) & 3) * 2)) + ((((x112 + ((~(((x114 ^ -1) | (-(x114 ^ -1))) >> 31)) & 2)) - (x115 + ((~(((x116 ^ -1) | (-(x116 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
      x136[x237] = x133;
      int * x138 = x71->cache_tags;
      int x240 = (int)((unsigned int)(x75 + x76) >> 1);
      x138[x216] = x240;
      int * x140 = x71->cache_dirty;
      x140[x216] = 0;
      int * x142 = x71->cache_age;
      x142[x216] = 1;
      int * x144 = x71->cache_age;
      int x145 = x144[x216];
      int x146 = x144[x190];
      int x246 = x146 + ((int)((unsigned int)(x146 - x145) >> 31));
      x144[x190] = x246;
      int * x148 = x71->cache_age;
      int x149 = x148[x191];
      int x248 = x149 + ((int)((unsigned int)(x149 - x145) >> 31));
      x148[x191] = x248;
      int * x151 = x71->cache_age;
      x151[x216] = 0;
      x154 = x216;
    }
    int * x155 = x71->cache_vals;
    int x251 = x154 * 2;
    int x156 = x155[x251];
    int x252 = (x154 * 2) + 1;
    int x157 = x155[x252];
    int x253 = (((((int)((unsigned int)(x75 + x76) >> 1)) & 1) * 2) + ((((x96 + ((~(((x98 ^ -1) | (-(x98 ^ -1))) >> 31)) & 2)) - (x99 + ((~(((x100 ^ -1) | (-(x100 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
    x155[x253] = x156;
    int * x159 = x71->cache_vals;
    int x256 = ((((((int)((unsigned int)(x75 + x76) >> 1)) & 1) * 2) + ((((x96 + ((~(((x98 ^ -1) | (-(x98 ^ -1))) >> 31)) & 2)) - (x99 + ((~(((x100 ^ -1) | (-(x100 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
    x159[x256] = x157;
    int * x161 = x71->cache_tags;
    int x259 = ((((int)((unsigned int)(x75 + x76) >> 1)) & 1) * 2) + ((((x96 + ((~(((x98 ^ -1) | (-(x98 ^ -1))) >> 31)) & 2)) - (x99 + ((~(((x100 ^ -1) | (-(x100 ^ -1))) >> 31)) & 2))) >> 31) & 1);
    int x260 = (int)((unsigned int)(x75 + x76) >> 1);
    x161[x259] = x260;
    int * x163 = x71->cache_dirty;
    x163[x259] = 0;
    int * x165 = x71->cache_age;
    x165[x259] = 1;
    int * x167 = x71->cache_age;
    int x168 = x167[x259];
    int x169 = x167[x188];
    int x266 = x169 + ((int)((unsigned int)(x169 - x168) >> 31));
    x167[x188] = x266;
    int * x171 = x71->cache_age;
    int x172 = x171[x189];
    int x268 = x172 + ((int)((unsigned int)(x172 - x168) >> 31));
    x171[x189] = x268;
    int * x174 = x71->cache_age;
    x174[x259] = 0;
    x177 = x259;
  }
  int x271 = (x177 * 2) + ((x75 + x76) & 1);
  int x178 = x84[x271];
  int * x179 = x71->regs;
  x179[0] = x178;
  struct StateT * x181 = slot_5(x71);
  return x181;
}

struct StateT * slot_9(struct StateT * x505) {
  int x506 = x505->timer;
  int x512 = x506 + 1;
  x505->timer = x512;
  int * x508 = x505->regs;
  x508[0] = 0;
  struct StateT * x510 = slot_10(x505);
  return x510;
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
    s1.mem[SECRET_OFFSET+i] = secret(0, 20);
    s2.mem[SECRET_OFFSET+i] = secret(0, 20);
  }
  struct StateT *s1_ = snippet(&s1);
  struct StateT *s2_ = snippet(&s2);
  //@ assert untainted_timer: !\tainted(s1_->timer==s2_->timer);
  koika_assert(s1_->timer==s2_->timer, "timing leak");
  return 0;
}