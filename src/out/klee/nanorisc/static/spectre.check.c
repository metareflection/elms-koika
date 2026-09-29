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

struct StateT * snippet(struct StateT * x0);
struct StateT * slot_1(struct StateT * x15);
struct StateT * slot_5(struct StateT * x546);
struct StateT * slot_4(struct StateT * x291);
struct StateT * slot_2(struct StateT * x28);
struct StateT * slot_3(struct StateT * x36);
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

struct StateT * slot_5(struct StateT * x546) {
  int * x547 = x546->regs;
  int x548 = x547[0];
  bool x565 = x548 >= 20;
  struct StateT * x561;
  if (x565) {
    int x549 = x546->timer;
    int x566 = x549 + 15;
    x546->timer = x566;
    int * x551 = x546->saved_regs;
    int x552 = x551[1];
    int * x553 = x546->regs;
    x553[1] = x552;
    int * x555 = x546->saved_regs;
    int x556 = x555[2];
    int * x557 = x546->regs;
    x557[2] = x556;
    x561 = x546;
  } else {
    x561 = x546;
  }
  return x561;
}

struct StateT * slot_4(struct StateT * x291) {
  int * x292 = x291->saved_regs;
  int * x293 = x291->regs;
  int x294 = x293[2];
  x292[2] = x294;
  int x296 = x291->timer;
  int x433 = x296 + 1;
  x291->timer = x433;
  int * x298 = x291->regs;
  int x299 = x298[1];
  int * x300 = x291->cache_tags;
  int x437 = (((int)((unsigned int)x299 >> 1)) & 1) * 2;
  int x301 = x300[x437];
  int * x302 = x291->cache_tags;
  int x439 = ((((int)((unsigned int)x299 >> 1)) & 1) * 2) + 1;
  int x303 = x302[x439];
  int * x304 = x291->cache_tags;
  int x441 = 4 + ((((int)((unsigned int)x299 >> 1)) & 3) * 2);
  int x305 = x304[x441];
  int * x306 = x291->cache_tags;
  int x443 = (4 + ((((int)((unsigned int)x299 >> 1)) & 3) * 2)) + 1;
  int x307 = x306[x443];
  int x308 = x291->timer;
  int x444 = x308 + ((100 ^ (((~(((x305 ^ ((int)((unsigned int)x299 >> 1))) | (-(x305 ^ ((int)((unsigned int)x299 >> 1))))) >> 31)) | (~(((x307 ^ ((int)((unsigned int)x299 >> 1))) | (-(x307 ^ ((int)((unsigned int)x299 >> 1))))) >> 31))) & 104)) ^ (((~(((x301 ^ ((int)((unsigned int)x299 >> 1))) | (-(x301 ^ ((int)((unsigned int)x299 >> 1))))) >> 31)) | (~(((x303 ^ ((int)((unsigned int)x299 >> 1))) | (-(x303 ^ ((int)((unsigned int)x299 >> 1))))) >> 31))) & (1 ^ (100 ^ (((~(((x305 ^ ((int)((unsigned int)x299 >> 1))) | (-(x305 ^ ((int)((unsigned int)x299 >> 1))))) >> 31)) | (~(((x307 ^ ((int)((unsigned int)x299 >> 1))) | (-(x307 ^ ((int)((unsigned int)x299 >> 1))))) >> 31))) & 104)))));
  x291->timer = x444;
  int * x310 = x291->cache_vals;
  bool x445 = !(((~(((x301 ^ ((int)((unsigned int)x299 >> 1))) | (-(x301 ^ ((int)((unsigned int)x299 >> 1))))) >> 31)) | (~(((x303 ^ ((int)((unsigned int)x299 >> 1))) | (-(x303 ^ ((int)((unsigned int)x299 >> 1))))) >> 31))) == 0);
  int x423;
  if (x445) {
    int * x311 = x291->cache_age;
    int x447 = ((((int)((unsigned int)x299 >> 1)) & 1) * 2) + ((~(((x303 ^ ((int)((unsigned int)x299 >> 1))) | (-(x303 ^ ((int)((unsigned int)x299 >> 1))))) >> 31)) & 1);
    int x312 = x311[x447];
    int * x313 = x291->cache_age;
    int x314 = x313[x437];
    int * x315 = x291->cache_age;
    int x450 = x314 + ((int)((unsigned int)(x314 - x312) >> 31));
    x315[x437] = x450;
    int * x317 = x291->cache_age;
    int x318 = x317[x439];
    int * x319 = x291->cache_age;
    int x453 = x318 + ((int)((unsigned int)(x318 - x312) >> 31));
    x319[x439] = x453;
    int * x321 = x291->cache_age;
    x321[x447] = 0;
    x423 = x447;
  } else {
    int * x324 = x291->cache_age;
    int x457 = (((int)((unsigned int)x299 >> 1)) & 1) * 2;
    int x325 = x324[x457];
    int * x326 = x291->cache_tags;
    int x327 = x326[x457];
    int * x328 = x291->cache_age;
    int x329 = x328[x439];
    int * x330 = x291->cache_tags;
    int x331 = x330[x439];
    bool x461 = !(((~(((x305 ^ ((int)((unsigned int)x299 >> 1))) | (-(x305 ^ ((int)((unsigned int)x299 >> 1))))) >> 31)) | (~(((x307 ^ ((int)((unsigned int)x299 >> 1))) | (-(x307 ^ ((int)((unsigned int)x299 >> 1))))) >> 31))) == 0);
    int x395;
    if (x461) {
      int * x332 = x291->cache_age;
      int x463 = (4 + ((((int)((unsigned int)x299 >> 1)) & 3) * 2)) + ((~(((x307 ^ ((int)((unsigned int)x299 >> 1))) | (-(x307 ^ ((int)((unsigned int)x299 >> 1))))) >> 31)) & 1);
      int x333 = x332[x463];
      int * x334 = x291->cache_age;
      int x335 = x334[x441];
      int * x336 = x291->cache_age;
      int x466 = x335 + ((int)((unsigned int)(x335 - x333) >> 31));
      x336[x441] = x466;
      int * x338 = x291->cache_age;
      int x339 = x338[x443];
      int * x340 = x291->cache_age;
      int x469 = x339 + ((int)((unsigned int)(x339 - x333) >> 31));
      x340[x443] = x469;
      int * x342 = x291->cache_age;
      x342[x463] = 0;
      x395 = x463;
    } else {
      int * x345 = x291->cache_age;
      int x473 = 4 + ((((int)((unsigned int)x299 >> 1)) & 3) * 2);
      int x346 = x345[x473];
      int * x347 = x291->cache_tags;
      int x348 = x347[x473];
      int * x349 = x291->cache_age;
      int x350 = x349[x443];
      int * x351 = x291->cache_tags;
      int x352 = x351[x443];
      int * x353 = x291->cache_dirty;
      int x478 = (4 + ((((int)((unsigned int)x299 >> 1)) & 3) * 2)) + ((((x346 + ((~(((x348 ^ -1) | (-(x348 ^ -1))) >> 31)) & 2)) - (x350 + ((~(((x352 ^ -1) | (-(x352 ^ -1))) >> 31)) & 2))) >> 31) & 1);
      int x354 = x353[x478];
      bool x479 = !(x354 == 0);
      if (x479) {
        int * x355 = x291->cache_tags;
        int x356 = x355[x478];
        int * x357 = x291->cache_vals;
        int x482 = ((4 + ((((int)((unsigned int)x299 >> 1)) & 3) * 2)) + ((((x346 + ((~(((x348 ^ -1) | (-(x348 ^ -1))) >> 31)) & 2)) - (x350 + ((~(((x352 ^ -1) | (-(x352 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
        int x358 = x357[x482];
        int * x359 = x291->cache_vals;
        int x484 = (((4 + ((((int)((unsigned int)x299 >> 1)) & 3) * 2)) + ((((x346 + ((~(((x348 ^ -1) | (-(x348 ^ -1))) >> 31)) & 2)) - (x350 + ((~(((x352 ^ -1) | (-(x352 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
        int x360 = x359[x484];
        int * x361 = x291->mem;
        int x486 = x356 * 2;
        x361[x486] = x358;
        int * x363 = x291->mem;
        int x489 = (x356 * 2) + 1;
        x363[x489] = x360;
        ;
      } else {
        ;
      }
      int * x368 = x291->mem;
      int x494 = ((int)((unsigned int)x299 >> 1)) * 2;
      int x369 = x368[x494];
      int * x370 = x291->mem;
      int x496 = (((int)((unsigned int)x299 >> 1)) * 2) + 1;
      int x371 = x370[x496];
      int * x372 = x291->cache_vals;
      int x498 = ((4 + ((((int)((unsigned int)x299 >> 1)) & 3) * 2)) + ((((x346 + ((~(((x348 ^ -1) | (-(x348 ^ -1))) >> 31)) & 2)) - (x350 + ((~(((x352 ^ -1) | (-(x352 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
      x372[x498] = x369;
      int * x374 = x291->cache_vals;
      int x501 = (((4 + ((((int)((unsigned int)x299 >> 1)) & 3) * 2)) + ((((x346 + ((~(((x348 ^ -1) | (-(x348 ^ -1))) >> 31)) & 2)) - (x350 + ((~(((x352 ^ -1) | (-(x352 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
      x374[x501] = x371;
      int * x376 = x291->cache_tags;
      int x504 = (int)((unsigned int)x299 >> 1);
      x376[x478] = x504;
      int * x378 = x291->cache_dirty;
      x378[x478] = 0;
      int * x380 = x291->cache_age;
      x380[x478] = 1;
      int * x382 = x291->cache_age;
      int x383 = x382[x478];
      int * x384 = x291->cache_age;
      int x385 = x384[x441];
      int * x386 = x291->cache_age;
      int x511 = x385 + ((int)((unsigned int)(x385 - x383) >> 31));
      x386[x441] = x511;
      int * x388 = x291->cache_age;
      int x389 = x388[x443];
      int * x390 = x291->cache_age;
      int x514 = x389 + ((int)((unsigned int)(x389 - x383) >> 31));
      x390[x443] = x514;
      int * x392 = x291->cache_age;
      x392[x478] = 0;
      x395 = x478;
    }
    int * x396 = x291->cache_vals;
    int x517 = x395 * 2;
    int x397 = x396[x517];
    int * x398 = x291->cache_vals;
    int x519 = (x395 * 2) + 1;
    int x399 = x398[x519];
    int * x400 = x291->cache_vals;
    int x521 = (((((int)((unsigned int)x299 >> 1)) & 1) * 2) + ((((x325 + ((~(((x327 ^ -1) | (-(x327 ^ -1))) >> 31)) & 2)) - (x329 + ((~(((x331 ^ -1) | (-(x331 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
    x400[x521] = x397;
    int * x402 = x291->cache_vals;
    int x524 = ((((((int)((unsigned int)x299 >> 1)) & 1) * 2) + ((((x325 + ((~(((x327 ^ -1) | (-(x327 ^ -1))) >> 31)) & 2)) - (x329 + ((~(((x331 ^ -1) | (-(x331 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
    x402[x524] = x399;
    int * x404 = x291->cache_tags;
    int x527 = ((((int)((unsigned int)x299 >> 1)) & 1) * 2) + ((((x325 + ((~(((x327 ^ -1) | (-(x327 ^ -1))) >> 31)) & 2)) - (x329 + ((~(((x331 ^ -1) | (-(x331 ^ -1))) >> 31)) & 2))) >> 31) & 1);
    int x528 = (int)((unsigned int)x299 >> 1);
    x404[x527] = x528;
    int * x406 = x291->cache_dirty;
    x406[x527] = 0;
    int * x408 = x291->cache_age;
    x408[x527] = 1;
    int * x410 = x291->cache_age;
    int x411 = x410[x527];
    int * x412 = x291->cache_age;
    int x413 = x412[x437];
    int * x414 = x291->cache_age;
    int x535 = x413 + ((int)((unsigned int)(x413 - x411) >> 31));
    x414[x437] = x535;
    int * x416 = x291->cache_age;
    int x417 = x416[x439];
    int * x418 = x291->cache_age;
    int x538 = x417 + ((int)((unsigned int)(x417 - x411) >> 31));
    x418[x439] = x538;
    int * x420 = x291->cache_age;
    x420[x527] = 0;
    x423 = x527;
  }
  int x541 = (x423 * 2) + (x299 & 1);
  int x424 = x310[x541];
  int * x425 = x291->regs;
  x425[2] = x424;
  struct StateT * x427 = slot_5(x291);
  return x427;
}

struct StateT * slot_2(struct StateT * x28) {
  int x29 = x28->timer;
  int x33 = x29 + 1;
  x28->timer = x33;
  struct StateT * x31 = slot_3(x28);
  return x31;
}

struct StateT * slot_3(struct StateT * x36) {
  int * x37 = x36->saved_regs;
  int * x38 = x36->regs;
  int x39 = x38[1];
  x37[1] = x39;
  int x41 = x36->timer;
  int x180 = x41 + 1;
  x36->timer = x180;
  int * x43 = x36->regs;
  int x44 = x43[3];
  int * x45 = x36->regs;
  int x46 = x45[0];
  int * x47 = x36->cache_tags;
  int x186 = (((int)((unsigned int)(x44 + x46) >> 1)) & 1) * 2;
  int x48 = x47[x186];
  int * x49 = x36->cache_tags;
  int x188 = ((((int)((unsigned int)(x44 + x46) >> 1)) & 1) * 2) + 1;
  int x50 = x49[x188];
  int * x51 = x36->cache_tags;
  int x190 = 4 + ((((int)((unsigned int)(x44 + x46) >> 1)) & 3) * 2);
  int x52 = x51[x190];
  int * x53 = x36->cache_tags;
  int x192 = (4 + ((((int)((unsigned int)(x44 + x46) >> 1)) & 3) * 2)) + 1;
  int x54 = x53[x192];
  int x55 = x36->timer;
  int x193 = x55 + ((100 ^ (((~(((x52 ^ ((int)((unsigned int)(x44 + x46) >> 1))) | (-(x52 ^ ((int)((unsigned int)(x44 + x46) >> 1))))) >> 31)) | (~(((x54 ^ ((int)((unsigned int)(x44 + x46) >> 1))) | (-(x54 ^ ((int)((unsigned int)(x44 + x46) >> 1))))) >> 31))) & 104)) ^ (((~(((x48 ^ ((int)((unsigned int)(x44 + x46) >> 1))) | (-(x48 ^ ((int)((unsigned int)(x44 + x46) >> 1))))) >> 31)) | (~(((x50 ^ ((int)((unsigned int)(x44 + x46) >> 1))) | (-(x50 ^ ((int)((unsigned int)(x44 + x46) >> 1))))) >> 31))) & (1 ^ (100 ^ (((~(((x52 ^ ((int)((unsigned int)(x44 + x46) >> 1))) | (-(x52 ^ ((int)((unsigned int)(x44 + x46) >> 1))))) >> 31)) | (~(((x54 ^ ((int)((unsigned int)(x44 + x46) >> 1))) | (-(x54 ^ ((int)((unsigned int)(x44 + x46) >> 1))))) >> 31))) & 104)))));
  x36->timer = x193;
  int * x57 = x36->cache_vals;
  bool x194 = !(((~(((x48 ^ ((int)((unsigned int)(x44 + x46) >> 1))) | (-(x48 ^ ((int)((unsigned int)(x44 + x46) >> 1))))) >> 31)) | (~(((x50 ^ ((int)((unsigned int)(x44 + x46) >> 1))) | (-(x50 ^ ((int)((unsigned int)(x44 + x46) >> 1))))) >> 31))) == 0);
  int x170;
  if (x194) {
    int * x58 = x36->cache_age;
    int x196 = ((((int)((unsigned int)(x44 + x46) >> 1)) & 1) * 2) + ((~(((x50 ^ ((int)((unsigned int)(x44 + x46) >> 1))) | (-(x50 ^ ((int)((unsigned int)(x44 + x46) >> 1))))) >> 31)) & 1);
    int x59 = x58[x196];
    int * x60 = x36->cache_age;
    int x61 = x60[x186];
    int * x62 = x36->cache_age;
    int x199 = x61 + ((int)((unsigned int)(x61 - x59) >> 31));
    x62[x186] = x199;
    int * x64 = x36->cache_age;
    int x65 = x64[x188];
    int * x66 = x36->cache_age;
    int x202 = x65 + ((int)((unsigned int)(x65 - x59) >> 31));
    x66[x188] = x202;
    int * x68 = x36->cache_age;
    x68[x196] = 0;
    x170 = x196;
  } else {
    int * x71 = x36->cache_age;
    int x205 = (((int)((unsigned int)(x44 + x46) >> 1)) & 1) * 2;
    int x72 = x71[x205];
    int * x73 = x36->cache_tags;
    int x74 = x73[x205];
    int * x75 = x36->cache_age;
    int x76 = x75[x188];
    int * x77 = x36->cache_tags;
    int x78 = x77[x188];
    bool x209 = !(((~(((x52 ^ ((int)((unsigned int)(x44 + x46) >> 1))) | (-(x52 ^ ((int)((unsigned int)(x44 + x46) >> 1))))) >> 31)) | (~(((x54 ^ ((int)((unsigned int)(x44 + x46) >> 1))) | (-(x54 ^ ((int)((unsigned int)(x44 + x46) >> 1))))) >> 31))) == 0);
    int x142;
    if (x209) {
      int * x79 = x36->cache_age;
      int x211 = (4 + ((((int)((unsigned int)(x44 + x46) >> 1)) & 3) * 2)) + ((~(((x54 ^ ((int)((unsigned int)(x44 + x46) >> 1))) | (-(x54 ^ ((int)((unsigned int)(x44 + x46) >> 1))))) >> 31)) & 1);
      int x80 = x79[x211];
      int * x81 = x36->cache_age;
      int x82 = x81[x190];
      int * x83 = x36->cache_age;
      int x214 = x82 + ((int)((unsigned int)(x82 - x80) >> 31));
      x83[x190] = x214;
      int * x85 = x36->cache_age;
      int x86 = x85[x192];
      int * x87 = x36->cache_age;
      int x217 = x86 + ((int)((unsigned int)(x86 - x80) >> 31));
      x87[x192] = x217;
      int * x89 = x36->cache_age;
      x89[x211] = 0;
      x142 = x211;
    } else {
      int * x92 = x36->cache_age;
      int x220 = 4 + ((((int)((unsigned int)(x44 + x46) >> 1)) & 3) * 2);
      int x93 = x92[x220];
      int * x94 = x36->cache_tags;
      int x95 = x94[x220];
      int * x96 = x36->cache_age;
      int x97 = x96[x192];
      int * x98 = x36->cache_tags;
      int x99 = x98[x192];
      int * x100 = x36->cache_dirty;
      int x225 = (4 + ((((int)((unsigned int)(x44 + x46) >> 1)) & 3) * 2)) + ((((x93 + ((~(((x95 ^ -1) | (-(x95 ^ -1))) >> 31)) & 2)) - (x97 + ((~(((x99 ^ -1) | (-(x99 ^ -1))) >> 31)) & 2))) >> 31) & 1);
      int x101 = x100[x225];
      bool x226 = !(x101 == 0);
      if (x226) {
        int * x102 = x36->cache_tags;
        int x103 = x102[x225];
        int * x104 = x36->cache_vals;
        int x229 = ((4 + ((((int)((unsigned int)(x44 + x46) >> 1)) & 3) * 2)) + ((((x93 + ((~(((x95 ^ -1) | (-(x95 ^ -1))) >> 31)) & 2)) - (x97 + ((~(((x99 ^ -1) | (-(x99 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
        int x105 = x104[x229];
        int * x106 = x36->cache_vals;
        int x231 = (((4 + ((((int)((unsigned int)(x44 + x46) >> 1)) & 3) * 2)) + ((((x93 + ((~(((x95 ^ -1) | (-(x95 ^ -1))) >> 31)) & 2)) - (x97 + ((~(((x99 ^ -1) | (-(x99 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
        int x107 = x106[x231];
        int * x108 = x36->mem;
        int x233 = x103 * 2;
        x108[x233] = x105;
        int * x110 = x36->mem;
        int x236 = (x103 * 2) + 1;
        x110[x236] = x107;
        ;
      } else {
        ;
      }
      int * x115 = x36->mem;
      int x241 = ((int)((unsigned int)(x44 + x46) >> 1)) * 2;
      int x116 = x115[x241];
      int * x117 = x36->mem;
      int x243 = (((int)((unsigned int)(x44 + x46) >> 1)) * 2) + 1;
      int x118 = x117[x243];
      int * x119 = x36->cache_vals;
      int x245 = ((4 + ((((int)((unsigned int)(x44 + x46) >> 1)) & 3) * 2)) + ((((x93 + ((~(((x95 ^ -1) | (-(x95 ^ -1))) >> 31)) & 2)) - (x97 + ((~(((x99 ^ -1) | (-(x99 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
      x119[x245] = x116;
      int * x121 = x36->cache_vals;
      int x248 = (((4 + ((((int)((unsigned int)(x44 + x46) >> 1)) & 3) * 2)) + ((((x93 + ((~(((x95 ^ -1) | (-(x95 ^ -1))) >> 31)) & 2)) - (x97 + ((~(((x99 ^ -1) | (-(x99 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
      x121[x248] = x118;
      int * x123 = x36->cache_tags;
      int x251 = (int)((unsigned int)(x44 + x46) >> 1);
      x123[x225] = x251;
      int * x125 = x36->cache_dirty;
      x125[x225] = 0;
      int * x127 = x36->cache_age;
      x127[x225] = 1;
      int * x129 = x36->cache_age;
      int x130 = x129[x225];
      int * x131 = x36->cache_age;
      int x132 = x131[x190];
      int * x133 = x36->cache_age;
      int x257 = x132 + ((int)((unsigned int)(x132 - x130) >> 31));
      x133[x190] = x257;
      int * x135 = x36->cache_age;
      int x136 = x135[x192];
      int * x137 = x36->cache_age;
      int x260 = x136 + ((int)((unsigned int)(x136 - x130) >> 31));
      x137[x192] = x260;
      int * x139 = x36->cache_age;
      x139[x225] = 0;
      x142 = x225;
    }
    int * x143 = x36->cache_vals;
    int x263 = x142 * 2;
    int x144 = x143[x263];
    int * x145 = x36->cache_vals;
    int x265 = (x142 * 2) + 1;
    int x146 = x145[x265];
    int * x147 = x36->cache_vals;
    int x267 = (((((int)((unsigned int)(x44 + x46) >> 1)) & 1) * 2) + ((((x72 + ((~(((x74 ^ -1) | (-(x74 ^ -1))) >> 31)) & 2)) - (x76 + ((~(((x78 ^ -1) | (-(x78 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
    x147[x267] = x144;
    int * x149 = x36->cache_vals;
    int x270 = ((((((int)((unsigned int)(x44 + x46) >> 1)) & 1) * 2) + ((((x72 + ((~(((x74 ^ -1) | (-(x74 ^ -1))) >> 31)) & 2)) - (x76 + ((~(((x78 ^ -1) | (-(x78 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
    x149[x270] = x146;
    int * x151 = x36->cache_tags;
    int x273 = ((((int)((unsigned int)(x44 + x46) >> 1)) & 1) * 2) + ((((x72 + ((~(((x74 ^ -1) | (-(x74 ^ -1))) >> 31)) & 2)) - (x76 + ((~(((x78 ^ -1) | (-(x78 ^ -1))) >> 31)) & 2))) >> 31) & 1);
    int x274 = (int)((unsigned int)(x44 + x46) >> 1);
    x151[x273] = x274;
    int * x153 = x36->cache_dirty;
    x153[x273] = 0;
    int * x155 = x36->cache_age;
    x155[x273] = 1;
    int * x157 = x36->cache_age;
    int x158 = x157[x273];
    int * x159 = x36->cache_age;
    int x160 = x159[x186];
    int * x161 = x36->cache_age;
    int x280 = x160 + ((int)((unsigned int)(x160 - x158) >> 31));
    x161[x186] = x280;
    int * x163 = x36->cache_age;
    int x164 = x163[x188];
    int * x165 = x36->cache_age;
    int x283 = x164 + ((int)((unsigned int)(x164 - x158) >> 31));
    x165[x188] = x283;
    int * x167 = x36->cache_age;
    x167[x273] = 0;
    x170 = x273;
  }
  int x286 = (x170 * 2) + ((x44 + x46) & 1);
  int x171 = x57[x286];
  int * x172 = x36->regs;
  x172[1] = x171;
  struct StateT * x174 = slot_4(x36);
  return x174;
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
    s1.mem[SECRET_OFFSET+i] = secret(0, 20);
    s2.mem[SECRET_OFFSET+i] = secret(0, 20);
  }
  struct StateT *s1_ = snippet(&s1);
  struct StateT *s2_ = snippet(&s2);
  koika_assert(s1_->timer==s2_->timer, "timing leak");
  return 0;
}