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
struct StateT * slot_1(struct StateT * x10);
struct StateT * slot_2(struct StateT * x261);
struct StateT * slot_3(struct StateT * x516);
struct StateT * slot_0(struct StateT * x2);
struct StateT * snippet(struct StateT * x0) {
  struct StateT * x1 = slot_0(x0);
  return x1;
}

struct StateT * slot_1(struct StateT * x10) {
  int * x11 = x10->saved_regs;
  int * x12 = x10->regs;
  int x13 = x12[1];
  x11[1] = x13;
  int x15 = x10->timer;
  int x152 = x15 + 1;
  x10->timer = x152;
  int * x17 = x10->regs;
  int x18 = x17[0];
  int * x19 = x10->cache_tags;
  int x156 = (((int)((unsigned int)x18 >> 1)) & 1) * 2;
  int x20 = x19[x156];
  int * x21 = x10->cache_tags;
  int x158 = ((((int)((unsigned int)x18 >> 1)) & 1) * 2) + 1;
  int x22 = x21[x158];
  int * x23 = x10->cache_tags;
  int x160 = 4 + ((((int)((unsigned int)x18 >> 1)) & 3) * 2);
  int x24 = x23[x160];
  int * x25 = x10->cache_tags;
  int x162 = (4 + ((((int)((unsigned int)x18 >> 1)) & 3) * 2)) + 1;
  int x26 = x25[x162];
  int x27 = x10->timer;
  int x163 = x27 + ((100 ^ (((~(((x24 ^ ((int)((unsigned int)x18 >> 1))) | (-(x24 ^ ((int)((unsigned int)x18 >> 1))))) >> 31)) | (~(((x26 ^ ((int)((unsigned int)x18 >> 1))) | (-(x26 ^ ((int)((unsigned int)x18 >> 1))))) >> 31))) & 104)) ^ (((~(((x20 ^ ((int)((unsigned int)x18 >> 1))) | (-(x20 ^ ((int)((unsigned int)x18 >> 1))))) >> 31)) | (~(((x22 ^ ((int)((unsigned int)x18 >> 1))) | (-(x22 ^ ((int)((unsigned int)x18 >> 1))))) >> 31))) & (1 ^ (100 ^ (((~(((x24 ^ ((int)((unsigned int)x18 >> 1))) | (-(x24 ^ ((int)((unsigned int)x18 >> 1))))) >> 31)) | (~(((x26 ^ ((int)((unsigned int)x18 >> 1))) | (-(x26 ^ ((int)((unsigned int)x18 >> 1))))) >> 31))) & 104)))));
  x10->timer = x163;
  int * x29 = x10->cache_vals;
  bool x164 = !(((~(((x20 ^ ((int)((unsigned int)x18 >> 1))) | (-(x20 ^ ((int)((unsigned int)x18 >> 1))))) >> 31)) | (~(((x22 ^ ((int)((unsigned int)x18 >> 1))) | (-(x22 ^ ((int)((unsigned int)x18 >> 1))))) >> 31))) == 0);
  int x142;
  if (x164) {
    int * x30 = x10->cache_age;
    int x166 = ((((int)((unsigned int)x18 >> 1)) & 1) * 2) + ((~(((x22 ^ ((int)((unsigned int)x18 >> 1))) | (-(x22 ^ ((int)((unsigned int)x18 >> 1))))) >> 31)) & 1);
    int x31 = x30[x166];
    int * x32 = x10->cache_age;
    int x33 = x32[x156];
    int * x34 = x10->cache_age;
    int x169 = x33 + ((int)((unsigned int)(x33 - x31) >> 31));
    x34[x156] = x169;
    int * x36 = x10->cache_age;
    int x37 = x36[x158];
    int * x38 = x10->cache_age;
    int x172 = x37 + ((int)((unsigned int)(x37 - x31) >> 31));
    x38[x158] = x172;
    int * x40 = x10->cache_age;
    x40[x166] = 0;
    x142 = x166;
  } else {
    int * x43 = x10->cache_age;
    int x175 = (((int)((unsigned int)x18 >> 1)) & 1) * 2;
    int x44 = x43[x175];
    int * x45 = x10->cache_tags;
    int x46 = x45[x175];
    int * x47 = x10->cache_age;
    int x48 = x47[x158];
    int * x49 = x10->cache_tags;
    int x50 = x49[x158];
    bool x179 = !(((~(((x24 ^ ((int)((unsigned int)x18 >> 1))) | (-(x24 ^ ((int)((unsigned int)x18 >> 1))))) >> 31)) | (~(((x26 ^ ((int)((unsigned int)x18 >> 1))) | (-(x26 ^ ((int)((unsigned int)x18 >> 1))))) >> 31))) == 0);
    int x114;
    if (x179) {
      int * x51 = x10->cache_age;
      int x181 = (4 + ((((int)((unsigned int)x18 >> 1)) & 3) * 2)) + ((~(((x26 ^ ((int)((unsigned int)x18 >> 1))) | (-(x26 ^ ((int)((unsigned int)x18 >> 1))))) >> 31)) & 1);
      int x52 = x51[x181];
      int * x53 = x10->cache_age;
      int x54 = x53[x160];
      int * x55 = x10->cache_age;
      int x184 = x54 + ((int)((unsigned int)(x54 - x52) >> 31));
      x55[x160] = x184;
      int * x57 = x10->cache_age;
      int x58 = x57[x162];
      int * x59 = x10->cache_age;
      int x187 = x58 + ((int)((unsigned int)(x58 - x52) >> 31));
      x59[x162] = x187;
      int * x61 = x10->cache_age;
      x61[x181] = 0;
      x114 = x181;
    } else {
      int * x64 = x10->cache_age;
      int x190 = 4 + ((((int)((unsigned int)x18 >> 1)) & 3) * 2);
      int x65 = x64[x190];
      int * x66 = x10->cache_tags;
      int x67 = x66[x190];
      int * x68 = x10->cache_age;
      int x69 = x68[x162];
      int * x70 = x10->cache_tags;
      int x71 = x70[x162];
      int * x72 = x10->cache_dirty;
      int x195 = (4 + ((((int)((unsigned int)x18 >> 1)) & 3) * 2)) + ((((x65 + ((~(((x67 ^ -1) | (-(x67 ^ -1))) >> 31)) & 2)) - (x69 + ((~(((x71 ^ -1) | (-(x71 ^ -1))) >> 31)) & 2))) >> 31) & 1);
      int x73 = x72[x195];
      bool x196 = !(x73 == 0);
      if (x196) {
        int * x74 = x10->cache_tags;
        int x75 = x74[x195];
        int * x76 = x10->cache_vals;
        int x199 = ((4 + ((((int)((unsigned int)x18 >> 1)) & 3) * 2)) + ((((x65 + ((~(((x67 ^ -1) | (-(x67 ^ -1))) >> 31)) & 2)) - (x69 + ((~(((x71 ^ -1) | (-(x71 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
        int x77 = x76[x199];
        int * x78 = x10->cache_vals;
        int x201 = (((4 + ((((int)((unsigned int)x18 >> 1)) & 3) * 2)) + ((((x65 + ((~(((x67 ^ -1) | (-(x67 ^ -1))) >> 31)) & 2)) - (x69 + ((~(((x71 ^ -1) | (-(x71 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
        int x79 = x78[x201];
        int * x80 = x10->mem;
        int x203 = x75 * 2;
        x80[x203] = x77;
        int * x82 = x10->mem;
        int x206 = (x75 * 2) + 1;
        x82[x206] = x79;
        ;
      } else {
        ;
      }
      int * x87 = x10->mem;
      int x211 = ((int)((unsigned int)x18 >> 1)) * 2;
      int x88 = x87[x211];
      int * x89 = x10->mem;
      int x213 = (((int)((unsigned int)x18 >> 1)) * 2) + 1;
      int x90 = x89[x213];
      int * x91 = x10->cache_vals;
      int x215 = ((4 + ((((int)((unsigned int)x18 >> 1)) & 3) * 2)) + ((((x65 + ((~(((x67 ^ -1) | (-(x67 ^ -1))) >> 31)) & 2)) - (x69 + ((~(((x71 ^ -1) | (-(x71 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
      x91[x215] = x88;
      int * x93 = x10->cache_vals;
      int x218 = (((4 + ((((int)((unsigned int)x18 >> 1)) & 3) * 2)) + ((((x65 + ((~(((x67 ^ -1) | (-(x67 ^ -1))) >> 31)) & 2)) - (x69 + ((~(((x71 ^ -1) | (-(x71 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
      x93[x218] = x90;
      int * x95 = x10->cache_tags;
      int x221 = (int)((unsigned int)x18 >> 1);
      x95[x195] = x221;
      int * x97 = x10->cache_dirty;
      x97[x195] = 0;
      int * x99 = x10->cache_age;
      x99[x195] = 1;
      int * x101 = x10->cache_age;
      int x102 = x101[x195];
      int * x103 = x10->cache_age;
      int x104 = x103[x160];
      int * x105 = x10->cache_age;
      int x227 = x104 + ((int)((unsigned int)(x104 - x102) >> 31));
      x105[x160] = x227;
      int * x107 = x10->cache_age;
      int x108 = x107[x162];
      int * x109 = x10->cache_age;
      int x230 = x108 + ((int)((unsigned int)(x108 - x102) >> 31));
      x109[x162] = x230;
      int * x111 = x10->cache_age;
      x111[x195] = 0;
      x114 = x195;
    }
    int * x115 = x10->cache_vals;
    int x233 = x114 * 2;
    int x116 = x115[x233];
    int * x117 = x10->cache_vals;
    int x235 = (x114 * 2) + 1;
    int x118 = x117[x235];
    int * x119 = x10->cache_vals;
    int x237 = (((((int)((unsigned int)x18 >> 1)) & 1) * 2) + ((((x44 + ((~(((x46 ^ -1) | (-(x46 ^ -1))) >> 31)) & 2)) - (x48 + ((~(((x50 ^ -1) | (-(x50 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
    x119[x237] = x116;
    int * x121 = x10->cache_vals;
    int x240 = ((((((int)((unsigned int)x18 >> 1)) & 1) * 2) + ((((x44 + ((~(((x46 ^ -1) | (-(x46 ^ -1))) >> 31)) & 2)) - (x48 + ((~(((x50 ^ -1) | (-(x50 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
    x121[x240] = x118;
    int * x123 = x10->cache_tags;
    int x243 = ((((int)((unsigned int)x18 >> 1)) & 1) * 2) + ((((x44 + ((~(((x46 ^ -1) | (-(x46 ^ -1))) >> 31)) & 2)) - (x48 + ((~(((x50 ^ -1) | (-(x50 ^ -1))) >> 31)) & 2))) >> 31) & 1);
    int x244 = (int)((unsigned int)x18 >> 1);
    x123[x243] = x244;
    int * x125 = x10->cache_dirty;
    x125[x243] = 0;
    int * x127 = x10->cache_age;
    x127[x243] = 1;
    int * x129 = x10->cache_age;
    int x130 = x129[x243];
    int * x131 = x10->cache_age;
    int x132 = x131[x156];
    int * x133 = x10->cache_age;
    int x250 = x132 + ((int)((unsigned int)(x132 - x130) >> 31));
    x133[x156] = x250;
    int * x135 = x10->cache_age;
    int x136 = x135[x158];
    int * x137 = x10->cache_age;
    int x253 = x136 + ((int)((unsigned int)(x136 - x130) >> 31));
    x137[x158] = x253;
    int * x139 = x10->cache_age;
    x139[x243] = 0;
    x142 = x243;
  }
  int x256 = (x142 * 2) + (x18 & 1);
  int x143 = x29[x256];
  int * x144 = x10->regs;
  x144[1] = x143;
  struct StateT * x146 = slot_2(x10);
  return x146;
}

struct StateT * slot_2(struct StateT * x261) {
  int * x262 = x261->saved_regs;
  int * x263 = x261->regs;
  int x264 = x263[2];
  x262[2] = x264;
  int x266 = x261->timer;
  int x403 = x266 + 1;
  x261->timer = x403;
  int * x268 = x261->regs;
  int x269 = x268[1];
  int * x270 = x261->cache_tags;
  int x407 = (((int)((unsigned int)(x269 + 4) >> 1)) & 1) * 2;
  int x271 = x270[x407];
  int * x272 = x261->cache_tags;
  int x409 = ((((int)((unsigned int)(x269 + 4) >> 1)) & 1) * 2) + 1;
  int x273 = x272[x409];
  int * x274 = x261->cache_tags;
  int x411 = 4 + ((((int)((unsigned int)(x269 + 4) >> 1)) & 3) * 2);
  int x275 = x274[x411];
  int * x276 = x261->cache_tags;
  int x413 = (4 + ((((int)((unsigned int)(x269 + 4) >> 1)) & 3) * 2)) + 1;
  int x277 = x276[x413];
  int x278 = x261->timer;
  int x414 = x278 + ((100 ^ (((~(((x275 ^ ((int)((unsigned int)(x269 + 4) >> 1))) | (-(x275 ^ ((int)((unsigned int)(x269 + 4) >> 1))))) >> 31)) | (~(((x277 ^ ((int)((unsigned int)(x269 + 4) >> 1))) | (-(x277 ^ ((int)((unsigned int)(x269 + 4) >> 1))))) >> 31))) & 104)) ^ (((~(((x271 ^ ((int)((unsigned int)(x269 + 4) >> 1))) | (-(x271 ^ ((int)((unsigned int)(x269 + 4) >> 1))))) >> 31)) | (~(((x273 ^ ((int)((unsigned int)(x269 + 4) >> 1))) | (-(x273 ^ ((int)((unsigned int)(x269 + 4) >> 1))))) >> 31))) & (1 ^ (100 ^ (((~(((x275 ^ ((int)((unsigned int)(x269 + 4) >> 1))) | (-(x275 ^ ((int)((unsigned int)(x269 + 4) >> 1))))) >> 31)) | (~(((x277 ^ ((int)((unsigned int)(x269 + 4) >> 1))) | (-(x277 ^ ((int)((unsigned int)(x269 + 4) >> 1))))) >> 31))) & 104)))));
  x261->timer = x414;
  int * x280 = x261->cache_vals;
  bool x415 = !(((~(((x271 ^ ((int)((unsigned int)(x269 + 4) >> 1))) | (-(x271 ^ ((int)((unsigned int)(x269 + 4) >> 1))))) >> 31)) | (~(((x273 ^ ((int)((unsigned int)(x269 + 4) >> 1))) | (-(x273 ^ ((int)((unsigned int)(x269 + 4) >> 1))))) >> 31))) == 0);
  int x393;
  if (x415) {
    int * x281 = x261->cache_age;
    int x417 = ((((int)((unsigned int)(x269 + 4) >> 1)) & 1) * 2) + ((~(((x273 ^ ((int)((unsigned int)(x269 + 4) >> 1))) | (-(x273 ^ ((int)((unsigned int)(x269 + 4) >> 1))))) >> 31)) & 1);
    int x282 = x281[x417];
    int * x283 = x261->cache_age;
    int x284 = x283[x407];
    int * x285 = x261->cache_age;
    int x420 = x284 + ((int)((unsigned int)(x284 - x282) >> 31));
    x285[x407] = x420;
    int * x287 = x261->cache_age;
    int x288 = x287[x409];
    int * x289 = x261->cache_age;
    int x423 = x288 + ((int)((unsigned int)(x288 - x282) >> 31));
    x289[x409] = x423;
    int * x291 = x261->cache_age;
    x291[x417] = 0;
    x393 = x417;
  } else {
    int * x294 = x261->cache_age;
    int x427 = (((int)((unsigned int)(x269 + 4) >> 1)) & 1) * 2;
    int x295 = x294[x427];
    int * x296 = x261->cache_tags;
    int x297 = x296[x427];
    int * x298 = x261->cache_age;
    int x299 = x298[x409];
    int * x300 = x261->cache_tags;
    int x301 = x300[x409];
    bool x431 = !(((~(((x275 ^ ((int)((unsigned int)(x269 + 4) >> 1))) | (-(x275 ^ ((int)((unsigned int)(x269 + 4) >> 1))))) >> 31)) | (~(((x277 ^ ((int)((unsigned int)(x269 + 4) >> 1))) | (-(x277 ^ ((int)((unsigned int)(x269 + 4) >> 1))))) >> 31))) == 0);
    int x365;
    if (x431) {
      int * x302 = x261->cache_age;
      int x433 = (4 + ((((int)((unsigned int)(x269 + 4) >> 1)) & 3) * 2)) + ((~(((x277 ^ ((int)((unsigned int)(x269 + 4) >> 1))) | (-(x277 ^ ((int)((unsigned int)(x269 + 4) >> 1))))) >> 31)) & 1);
      int x303 = x302[x433];
      int * x304 = x261->cache_age;
      int x305 = x304[x411];
      int * x306 = x261->cache_age;
      int x436 = x305 + ((int)((unsigned int)(x305 - x303) >> 31));
      x306[x411] = x436;
      int * x308 = x261->cache_age;
      int x309 = x308[x413];
      int * x310 = x261->cache_age;
      int x439 = x309 + ((int)((unsigned int)(x309 - x303) >> 31));
      x310[x413] = x439;
      int * x312 = x261->cache_age;
      x312[x433] = 0;
      x365 = x433;
    } else {
      int * x315 = x261->cache_age;
      int x443 = 4 + ((((int)((unsigned int)(x269 + 4) >> 1)) & 3) * 2);
      int x316 = x315[x443];
      int * x317 = x261->cache_tags;
      int x318 = x317[x443];
      int * x319 = x261->cache_age;
      int x320 = x319[x413];
      int * x321 = x261->cache_tags;
      int x322 = x321[x413];
      int * x323 = x261->cache_dirty;
      int x448 = (4 + ((((int)((unsigned int)(x269 + 4) >> 1)) & 3) * 2)) + ((((x316 + ((~(((x318 ^ -1) | (-(x318 ^ -1))) >> 31)) & 2)) - (x320 + ((~(((x322 ^ -1) | (-(x322 ^ -1))) >> 31)) & 2))) >> 31) & 1);
      int x324 = x323[x448];
      bool x449 = !(x324 == 0);
      if (x449) {
        int * x325 = x261->cache_tags;
        int x326 = x325[x448];
        int * x327 = x261->cache_vals;
        int x452 = ((4 + ((((int)((unsigned int)(x269 + 4) >> 1)) & 3) * 2)) + ((((x316 + ((~(((x318 ^ -1) | (-(x318 ^ -1))) >> 31)) & 2)) - (x320 + ((~(((x322 ^ -1) | (-(x322 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
        int x328 = x327[x452];
        int * x329 = x261->cache_vals;
        int x454 = (((4 + ((((int)((unsigned int)(x269 + 4) >> 1)) & 3) * 2)) + ((((x316 + ((~(((x318 ^ -1) | (-(x318 ^ -1))) >> 31)) & 2)) - (x320 + ((~(((x322 ^ -1) | (-(x322 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
        int x330 = x329[x454];
        int * x331 = x261->mem;
        int x456 = x326 * 2;
        x331[x456] = x328;
        int * x333 = x261->mem;
        int x459 = (x326 * 2) + 1;
        x333[x459] = x330;
        ;
      } else {
        ;
      }
      int * x338 = x261->mem;
      int x464 = ((int)((unsigned int)(x269 + 4) >> 1)) * 2;
      int x339 = x338[x464];
      int * x340 = x261->mem;
      int x466 = (((int)((unsigned int)(x269 + 4) >> 1)) * 2) + 1;
      int x341 = x340[x466];
      int * x342 = x261->cache_vals;
      int x468 = ((4 + ((((int)((unsigned int)(x269 + 4) >> 1)) & 3) * 2)) + ((((x316 + ((~(((x318 ^ -1) | (-(x318 ^ -1))) >> 31)) & 2)) - (x320 + ((~(((x322 ^ -1) | (-(x322 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
      x342[x468] = x339;
      int * x344 = x261->cache_vals;
      int x471 = (((4 + ((((int)((unsigned int)(x269 + 4) >> 1)) & 3) * 2)) + ((((x316 + ((~(((x318 ^ -1) | (-(x318 ^ -1))) >> 31)) & 2)) - (x320 + ((~(((x322 ^ -1) | (-(x322 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
      x344[x471] = x341;
      int * x346 = x261->cache_tags;
      int x474 = (int)((unsigned int)(x269 + 4) >> 1);
      x346[x448] = x474;
      int * x348 = x261->cache_dirty;
      x348[x448] = 0;
      int * x350 = x261->cache_age;
      x350[x448] = 1;
      int * x352 = x261->cache_age;
      int x353 = x352[x448];
      int * x354 = x261->cache_age;
      int x355 = x354[x411];
      int * x356 = x261->cache_age;
      int x481 = x355 + ((int)((unsigned int)(x355 - x353) >> 31));
      x356[x411] = x481;
      int * x358 = x261->cache_age;
      int x359 = x358[x413];
      int * x360 = x261->cache_age;
      int x484 = x359 + ((int)((unsigned int)(x359 - x353) >> 31));
      x360[x413] = x484;
      int * x362 = x261->cache_age;
      x362[x448] = 0;
      x365 = x448;
    }
    int * x366 = x261->cache_vals;
    int x487 = x365 * 2;
    int x367 = x366[x487];
    int * x368 = x261->cache_vals;
    int x489 = (x365 * 2) + 1;
    int x369 = x368[x489];
    int * x370 = x261->cache_vals;
    int x491 = (((((int)((unsigned int)(x269 + 4) >> 1)) & 1) * 2) + ((((x295 + ((~(((x297 ^ -1) | (-(x297 ^ -1))) >> 31)) & 2)) - (x299 + ((~(((x301 ^ -1) | (-(x301 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
    x370[x491] = x367;
    int * x372 = x261->cache_vals;
    int x494 = ((((((int)((unsigned int)(x269 + 4) >> 1)) & 1) * 2) + ((((x295 + ((~(((x297 ^ -1) | (-(x297 ^ -1))) >> 31)) & 2)) - (x299 + ((~(((x301 ^ -1) | (-(x301 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
    x372[x494] = x369;
    int * x374 = x261->cache_tags;
    int x497 = ((((int)((unsigned int)(x269 + 4) >> 1)) & 1) * 2) + ((((x295 + ((~(((x297 ^ -1) | (-(x297 ^ -1))) >> 31)) & 2)) - (x299 + ((~(((x301 ^ -1) | (-(x301 ^ -1))) >> 31)) & 2))) >> 31) & 1);
    int x498 = (int)((unsigned int)(x269 + 4) >> 1);
    x374[x497] = x498;
    int * x376 = x261->cache_dirty;
    x376[x497] = 0;
    int * x378 = x261->cache_age;
    x378[x497] = 1;
    int * x380 = x261->cache_age;
    int x381 = x380[x497];
    int * x382 = x261->cache_age;
    int x383 = x382[x407];
    int * x384 = x261->cache_age;
    int x505 = x383 + ((int)((unsigned int)(x383 - x381) >> 31));
    x384[x407] = x505;
    int * x386 = x261->cache_age;
    int x387 = x386[x409];
    int * x388 = x261->cache_age;
    int x508 = x387 + ((int)((unsigned int)(x387 - x381) >> 31));
    x388[x409] = x508;
    int * x390 = x261->cache_age;
    x390[x497] = 0;
    x393 = x497;
  }
  int x511 = (x393 * 2) + ((x269 + 4) & 1);
  int x394 = x280[x511];
  int * x395 = x261->regs;
  x395[2] = x394;
  struct StateT * x397 = slot_3(x261);
  return x397;
}

struct StateT * slot_3(struct StateT * x516) {
  int * x517 = x516->regs;
  int x518 = x517[0];
  bool x535 = x518 == 0;
  struct StateT * x531;
  if (x535) {
    int x519 = x516->timer;
    int x536 = x519 + 15;
    x516->timer = x536;
    int * x521 = x516->saved_regs;
    int x522 = x521[1];
    int * x523 = x516->regs;
    x523[1] = x522;
    int * x525 = x516->saved_regs;
    int x526 = x525[2];
    int * x527 = x516->regs;
    x527[2] = x526;
    x531 = x516;
  } else {
    x531 = x516;
  }
  return x531;
}

struct StateT * slot_0(struct StateT * x2) {
  int x3 = x2->timer;
  int x7 = x3 + 1;
  x2->timer = x7;
  struct StateT * x5 = slot_1(x2);
  return x5;
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