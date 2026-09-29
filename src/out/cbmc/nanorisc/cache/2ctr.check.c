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
struct StateT * slot_1(struct StateT * x19);
struct StateT * slot_2(struct StateT * x265);
struct StateT * slot_0(struct StateT * x2);
struct StateT * snippet(struct StateT * x0) {
  struct StateT * x1 = slot_0(x0);
  return x1;
}

struct StateT * slot_1(struct StateT * x19) {
  int x20 = x19->timer;
  int x153 = x20 + 1;
  x19->timer = x153;
  int * x22 = x19->regs;
  int x23 = x22[0];
  int * x24 = x19->cache_tags;
  int x157 = (((int)((unsigned int)x23 >> 1)) & 1) * 2;
  int x25 = x24[x157];
  int * x26 = x19->cache_tags;
  int x159 = ((((int)((unsigned int)x23 >> 1)) & 1) * 2) + 1;
  int x27 = x26[x159];
  int * x28 = x19->cache_tags;
  int x161 = 4 + ((((int)((unsigned int)x23 >> 1)) & 3) * 2);
  int x29 = x28[x161];
  int * x30 = x19->cache_tags;
  int x163 = (4 + ((((int)((unsigned int)x23 >> 1)) & 3) * 2)) + 1;
  int x31 = x30[x163];
  int x32 = x19->timer;
  int x164 = x32 + ((100 ^ (((~(((x29 ^ ((int)((unsigned int)x23 >> 1))) | (-(x29 ^ ((int)((unsigned int)x23 >> 1))))) >> 31)) | (~(((x31 ^ ((int)((unsigned int)x23 >> 1))) | (-(x31 ^ ((int)((unsigned int)x23 >> 1))))) >> 31))) & 104)) ^ (((~(((x25 ^ ((int)((unsigned int)x23 >> 1))) | (-(x25 ^ ((int)((unsigned int)x23 >> 1))))) >> 31)) | (~(((x27 ^ ((int)((unsigned int)x23 >> 1))) | (-(x27 ^ ((int)((unsigned int)x23 >> 1))))) >> 31))) & (1 ^ (100 ^ (((~(((x29 ^ ((int)((unsigned int)x23 >> 1))) | (-(x29 ^ ((int)((unsigned int)x23 >> 1))))) >> 31)) | (~(((x31 ^ ((int)((unsigned int)x23 >> 1))) | (-(x31 ^ ((int)((unsigned int)x23 >> 1))))) >> 31))) & 104)))));
  x19->timer = x164;
  int * x34 = x19->cache_vals;
  bool x165 = !(((~(((x25 ^ ((int)((unsigned int)x23 >> 1))) | (-(x25 ^ ((int)((unsigned int)x23 >> 1))))) >> 31)) | (~(((x27 ^ ((int)((unsigned int)x23 >> 1))) | (-(x27 ^ ((int)((unsigned int)x23 >> 1))))) >> 31))) == 0);
  int x147;
  if (x165) {
    int * x35 = x19->cache_age;
    int x167 = ((((int)((unsigned int)x23 >> 1)) & 1) * 2) + ((~(((x27 ^ ((int)((unsigned int)x23 >> 1))) | (-(x27 ^ ((int)((unsigned int)x23 >> 1))))) >> 31)) & 1);
    int x36 = x35[x167];
    int * x37 = x19->cache_age;
    int x38 = x37[x157];
    int * x39 = x19->cache_age;
    int x170 = x38 + ((int)((unsigned int)(x38 - x36) >> 31));
    x39[x157] = x170;
    int * x41 = x19->cache_age;
    int x42 = x41[x159];
    int * x43 = x19->cache_age;
    int x173 = x42 + ((int)((unsigned int)(x42 - x36) >> 31));
    x43[x159] = x173;
    int * x45 = x19->cache_age;
    x45[x167] = 0;
    x147 = x167;
  } else {
    int * x48 = x19->cache_age;
    int x176 = (((int)((unsigned int)x23 >> 1)) & 1) * 2;
    int x49 = x48[x176];
    int * x50 = x19->cache_tags;
    int x51 = x50[x176];
    int * x52 = x19->cache_age;
    int x53 = x52[x159];
    int * x54 = x19->cache_tags;
    int x55 = x54[x159];
    bool x180 = !(((~(((x29 ^ ((int)((unsigned int)x23 >> 1))) | (-(x29 ^ ((int)((unsigned int)x23 >> 1))))) >> 31)) | (~(((x31 ^ ((int)((unsigned int)x23 >> 1))) | (-(x31 ^ ((int)((unsigned int)x23 >> 1))))) >> 31))) == 0);
    int x119;
    if (x180) {
      int * x56 = x19->cache_age;
      int x182 = (4 + ((((int)((unsigned int)x23 >> 1)) & 3) * 2)) + ((~(((x31 ^ ((int)((unsigned int)x23 >> 1))) | (-(x31 ^ ((int)((unsigned int)x23 >> 1))))) >> 31)) & 1);
      int x57 = x56[x182];
      int * x58 = x19->cache_age;
      int x59 = x58[x161];
      int * x60 = x19->cache_age;
      int x185 = x59 + ((int)((unsigned int)(x59 - x57) >> 31));
      x60[x161] = x185;
      int * x62 = x19->cache_age;
      int x63 = x62[x163];
      int * x64 = x19->cache_age;
      int x188 = x63 + ((int)((unsigned int)(x63 - x57) >> 31));
      x64[x163] = x188;
      int * x66 = x19->cache_age;
      x66[x182] = 0;
      x119 = x182;
    } else {
      int * x69 = x19->cache_age;
      int x191 = 4 + ((((int)((unsigned int)x23 >> 1)) & 3) * 2);
      int x70 = x69[x191];
      int * x71 = x19->cache_tags;
      int x72 = x71[x191];
      int * x73 = x19->cache_age;
      int x74 = x73[x163];
      int * x75 = x19->cache_tags;
      int x76 = x75[x163];
      int * x77 = x19->cache_dirty;
      int x196 = (4 + ((((int)((unsigned int)x23 >> 1)) & 3) * 2)) + ((((x70 + ((~(((x72 ^ -1) | (-(x72 ^ -1))) >> 31)) & 2)) - (x74 + ((~(((x76 ^ -1) | (-(x76 ^ -1))) >> 31)) & 2))) >> 31) & 1);
      int x78 = x77[x196];
      bool x197 = !(x78 == 0);
      if (x197) {
        int * x79 = x19->cache_tags;
        int x80 = x79[x196];
        int * x81 = x19->cache_vals;
        int x200 = ((4 + ((((int)((unsigned int)x23 >> 1)) & 3) * 2)) + ((((x70 + ((~(((x72 ^ -1) | (-(x72 ^ -1))) >> 31)) & 2)) - (x74 + ((~(((x76 ^ -1) | (-(x76 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
        int x82 = x81[x200];
        int * x83 = x19->cache_vals;
        int x202 = (((4 + ((((int)((unsigned int)x23 >> 1)) & 3) * 2)) + ((((x70 + ((~(((x72 ^ -1) | (-(x72 ^ -1))) >> 31)) & 2)) - (x74 + ((~(((x76 ^ -1) | (-(x76 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
        int x84 = x83[x202];
        int * x85 = x19->mem;
        int x204 = x80 * 2;
        x85[x204] = x82;
        int * x87 = x19->mem;
        int x207 = (x80 * 2) + 1;
        x87[x207] = x84;
        ;
      } else {
        ;
      }
      int * x92 = x19->mem;
      int x212 = ((int)((unsigned int)x23 >> 1)) * 2;
      int x93 = x92[x212];
      int * x94 = x19->mem;
      int x214 = (((int)((unsigned int)x23 >> 1)) * 2) + 1;
      int x95 = x94[x214];
      int * x96 = x19->cache_vals;
      int x216 = ((4 + ((((int)((unsigned int)x23 >> 1)) & 3) * 2)) + ((((x70 + ((~(((x72 ^ -1) | (-(x72 ^ -1))) >> 31)) & 2)) - (x74 + ((~(((x76 ^ -1) | (-(x76 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
      x96[x216] = x93;
      int * x98 = x19->cache_vals;
      int x219 = (((4 + ((((int)((unsigned int)x23 >> 1)) & 3) * 2)) + ((((x70 + ((~(((x72 ^ -1) | (-(x72 ^ -1))) >> 31)) & 2)) - (x74 + ((~(((x76 ^ -1) | (-(x76 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
      x98[x219] = x95;
      int * x100 = x19->cache_tags;
      int x222 = (int)((unsigned int)x23 >> 1);
      x100[x196] = x222;
      int * x102 = x19->cache_dirty;
      x102[x196] = 0;
      int * x104 = x19->cache_age;
      x104[x196] = 1;
      int * x106 = x19->cache_age;
      int x107 = x106[x196];
      int * x108 = x19->cache_age;
      int x109 = x108[x161];
      int * x110 = x19->cache_age;
      int x229 = x109 + ((int)((unsigned int)(x109 - x107) >> 31));
      x110[x161] = x229;
      int * x112 = x19->cache_age;
      int x113 = x112[x163];
      int * x114 = x19->cache_age;
      int x232 = x113 + ((int)((unsigned int)(x113 - x107) >> 31));
      x114[x163] = x232;
      int * x116 = x19->cache_age;
      x116[x196] = 0;
      x119 = x196;
    }
    int * x120 = x19->cache_vals;
    int x235 = x119 * 2;
    int x121 = x120[x235];
    int * x122 = x19->cache_vals;
    int x237 = (x119 * 2) + 1;
    int x123 = x122[x237];
    int * x124 = x19->cache_vals;
    int x239 = (((((int)((unsigned int)x23 >> 1)) & 1) * 2) + ((((x49 + ((~(((x51 ^ -1) | (-(x51 ^ -1))) >> 31)) & 2)) - (x53 + ((~(((x55 ^ -1) | (-(x55 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
    x124[x239] = x121;
    int * x126 = x19->cache_vals;
    int x242 = ((((((int)((unsigned int)x23 >> 1)) & 1) * 2) + ((((x49 + ((~(((x51 ^ -1) | (-(x51 ^ -1))) >> 31)) & 2)) - (x53 + ((~(((x55 ^ -1) | (-(x55 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
    x126[x242] = x123;
    int * x128 = x19->cache_tags;
    int x245 = ((((int)((unsigned int)x23 >> 1)) & 1) * 2) + ((((x49 + ((~(((x51 ^ -1) | (-(x51 ^ -1))) >> 31)) & 2)) - (x53 + ((~(((x55 ^ -1) | (-(x55 ^ -1))) >> 31)) & 2))) >> 31) & 1);
    int x246 = (int)((unsigned int)x23 >> 1);
    x128[x245] = x246;
    int * x130 = x19->cache_dirty;
    x130[x245] = 0;
    int * x132 = x19->cache_age;
    x132[x245] = 1;
    int * x134 = x19->cache_age;
    int x135 = x134[x245];
    int * x136 = x19->cache_age;
    int x137 = x136[x157];
    int * x138 = x19->cache_age;
    int x253 = x137 + ((int)((unsigned int)(x137 - x135) >> 31));
    x138[x157] = x253;
    int * x140 = x19->cache_age;
    int x141 = x140[x159];
    int * x142 = x19->cache_age;
    int x256 = x141 + ((int)((unsigned int)(x141 - x135) >> 31));
    x142[x159] = x256;
    int * x144 = x19->cache_age;
    x144[x245] = 0;
    x147 = x245;
  }
  int x259 = (x147 * 2) + (x23 & 1);
  int x148 = x34[x259];
  int * x149 = x19->regs;
  x149[1] = x148;
  struct StateT * x151 = slot_2(x19);
  return x151;
}

struct StateT * slot_2(struct StateT * x265) {
  int x266 = x265->timer;
  int x398 = x266 + 1;
  x265->timer = x398;
  int * x268 = x265->regs;
  int x269 = x268[1];
  int * x270 = x265->cache_tags;
  int x402 = (((int)((unsigned int)(x269 + 4) >> 1)) & 1) * 2;
  int x271 = x270[x402];
  int * x272 = x265->cache_tags;
  int x404 = ((((int)((unsigned int)(x269 + 4) >> 1)) & 1) * 2) + 1;
  int x273 = x272[x404];
  int * x274 = x265->cache_tags;
  int x406 = 4 + ((((int)((unsigned int)(x269 + 4) >> 1)) & 3) * 2);
  int x275 = x274[x406];
  int * x276 = x265->cache_tags;
  int x408 = (4 + ((((int)((unsigned int)(x269 + 4) >> 1)) & 3) * 2)) + 1;
  int x277 = x276[x408];
  int x278 = x265->timer;
  int x409 = x278 + ((100 ^ (((~(((x275 ^ ((int)((unsigned int)(x269 + 4) >> 1))) | (-(x275 ^ ((int)((unsigned int)(x269 + 4) >> 1))))) >> 31)) | (~(((x277 ^ ((int)((unsigned int)(x269 + 4) >> 1))) | (-(x277 ^ ((int)((unsigned int)(x269 + 4) >> 1))))) >> 31))) & 104)) ^ (((~(((x271 ^ ((int)((unsigned int)(x269 + 4) >> 1))) | (-(x271 ^ ((int)((unsigned int)(x269 + 4) >> 1))))) >> 31)) | (~(((x273 ^ ((int)((unsigned int)(x269 + 4) >> 1))) | (-(x273 ^ ((int)((unsigned int)(x269 + 4) >> 1))))) >> 31))) & (1 ^ (100 ^ (((~(((x275 ^ ((int)((unsigned int)(x269 + 4) >> 1))) | (-(x275 ^ ((int)((unsigned int)(x269 + 4) >> 1))))) >> 31)) | (~(((x277 ^ ((int)((unsigned int)(x269 + 4) >> 1))) | (-(x277 ^ ((int)((unsigned int)(x269 + 4) >> 1))))) >> 31))) & 104)))));
  x265->timer = x409;
  int * x280 = x265->cache_vals;
  bool x410 = !(((~(((x271 ^ ((int)((unsigned int)(x269 + 4) >> 1))) | (-(x271 ^ ((int)((unsigned int)(x269 + 4) >> 1))))) >> 31)) | (~(((x273 ^ ((int)((unsigned int)(x269 + 4) >> 1))) | (-(x273 ^ ((int)((unsigned int)(x269 + 4) >> 1))))) >> 31))) == 0);
  int x393;
  if (x410) {
    int * x281 = x265->cache_age;
    int x412 = ((((int)((unsigned int)(x269 + 4) >> 1)) & 1) * 2) + ((~(((x273 ^ ((int)((unsigned int)(x269 + 4) >> 1))) | (-(x273 ^ ((int)((unsigned int)(x269 + 4) >> 1))))) >> 31)) & 1);
    int x282 = x281[x412];
    int * x283 = x265->cache_age;
    int x284 = x283[x402];
    int * x285 = x265->cache_age;
    int x415 = x284 + ((int)((unsigned int)(x284 - x282) >> 31));
    x285[x402] = x415;
    int * x287 = x265->cache_age;
    int x288 = x287[x404];
    int * x289 = x265->cache_age;
    int x418 = x288 + ((int)((unsigned int)(x288 - x282) >> 31));
    x289[x404] = x418;
    int * x291 = x265->cache_age;
    x291[x412] = 0;
    x393 = x412;
  } else {
    int * x294 = x265->cache_age;
    int x422 = (((int)((unsigned int)(x269 + 4) >> 1)) & 1) * 2;
    int x295 = x294[x422];
    int * x296 = x265->cache_tags;
    int x297 = x296[x422];
    int * x298 = x265->cache_age;
    int x299 = x298[x404];
    int * x300 = x265->cache_tags;
    int x301 = x300[x404];
    bool x426 = !(((~(((x275 ^ ((int)((unsigned int)(x269 + 4) >> 1))) | (-(x275 ^ ((int)((unsigned int)(x269 + 4) >> 1))))) >> 31)) | (~(((x277 ^ ((int)((unsigned int)(x269 + 4) >> 1))) | (-(x277 ^ ((int)((unsigned int)(x269 + 4) >> 1))))) >> 31))) == 0);
    int x365;
    if (x426) {
      int * x302 = x265->cache_age;
      int x428 = (4 + ((((int)((unsigned int)(x269 + 4) >> 1)) & 3) * 2)) + ((~(((x277 ^ ((int)((unsigned int)(x269 + 4) >> 1))) | (-(x277 ^ ((int)((unsigned int)(x269 + 4) >> 1))))) >> 31)) & 1);
      int x303 = x302[x428];
      int * x304 = x265->cache_age;
      int x305 = x304[x406];
      int * x306 = x265->cache_age;
      int x431 = x305 + ((int)((unsigned int)(x305 - x303) >> 31));
      x306[x406] = x431;
      int * x308 = x265->cache_age;
      int x309 = x308[x408];
      int * x310 = x265->cache_age;
      int x434 = x309 + ((int)((unsigned int)(x309 - x303) >> 31));
      x310[x408] = x434;
      int * x312 = x265->cache_age;
      x312[x428] = 0;
      x365 = x428;
    } else {
      int * x315 = x265->cache_age;
      int x438 = 4 + ((((int)((unsigned int)(x269 + 4) >> 1)) & 3) * 2);
      int x316 = x315[x438];
      int * x317 = x265->cache_tags;
      int x318 = x317[x438];
      int * x319 = x265->cache_age;
      int x320 = x319[x408];
      int * x321 = x265->cache_tags;
      int x322 = x321[x408];
      int * x323 = x265->cache_dirty;
      int x443 = (4 + ((((int)((unsigned int)(x269 + 4) >> 1)) & 3) * 2)) + ((((x316 + ((~(((x318 ^ -1) | (-(x318 ^ -1))) >> 31)) & 2)) - (x320 + ((~(((x322 ^ -1) | (-(x322 ^ -1))) >> 31)) & 2))) >> 31) & 1);
      int x324 = x323[x443];
      bool x444 = !(x324 == 0);
      if (x444) {
        int * x325 = x265->cache_tags;
        int x326 = x325[x443];
        int * x327 = x265->cache_vals;
        int x447 = ((4 + ((((int)((unsigned int)(x269 + 4) >> 1)) & 3) * 2)) + ((((x316 + ((~(((x318 ^ -1) | (-(x318 ^ -1))) >> 31)) & 2)) - (x320 + ((~(((x322 ^ -1) | (-(x322 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
        int x328 = x327[x447];
        int * x329 = x265->cache_vals;
        int x449 = (((4 + ((((int)((unsigned int)(x269 + 4) >> 1)) & 3) * 2)) + ((((x316 + ((~(((x318 ^ -1) | (-(x318 ^ -1))) >> 31)) & 2)) - (x320 + ((~(((x322 ^ -1) | (-(x322 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
        int x330 = x329[x449];
        int * x331 = x265->mem;
        int x451 = x326 * 2;
        x331[x451] = x328;
        int * x333 = x265->mem;
        int x454 = (x326 * 2) + 1;
        x333[x454] = x330;
        ;
      } else {
        ;
      }
      int * x338 = x265->mem;
      int x459 = ((int)((unsigned int)(x269 + 4) >> 1)) * 2;
      int x339 = x338[x459];
      int * x340 = x265->mem;
      int x461 = (((int)((unsigned int)(x269 + 4) >> 1)) * 2) + 1;
      int x341 = x340[x461];
      int * x342 = x265->cache_vals;
      int x463 = ((4 + ((((int)((unsigned int)(x269 + 4) >> 1)) & 3) * 2)) + ((((x316 + ((~(((x318 ^ -1) | (-(x318 ^ -1))) >> 31)) & 2)) - (x320 + ((~(((x322 ^ -1) | (-(x322 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
      x342[x463] = x339;
      int * x344 = x265->cache_vals;
      int x466 = (((4 + ((((int)((unsigned int)(x269 + 4) >> 1)) & 3) * 2)) + ((((x316 + ((~(((x318 ^ -1) | (-(x318 ^ -1))) >> 31)) & 2)) - (x320 + ((~(((x322 ^ -1) | (-(x322 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
      x344[x466] = x341;
      int * x346 = x265->cache_tags;
      int x469 = (int)((unsigned int)(x269 + 4) >> 1);
      x346[x443] = x469;
      int * x348 = x265->cache_dirty;
      x348[x443] = 0;
      int * x350 = x265->cache_age;
      x350[x443] = 1;
      int * x352 = x265->cache_age;
      int x353 = x352[x443];
      int * x354 = x265->cache_age;
      int x355 = x354[x406];
      int * x356 = x265->cache_age;
      int x476 = x355 + ((int)((unsigned int)(x355 - x353) >> 31));
      x356[x406] = x476;
      int * x358 = x265->cache_age;
      int x359 = x358[x408];
      int * x360 = x265->cache_age;
      int x479 = x359 + ((int)((unsigned int)(x359 - x353) >> 31));
      x360[x408] = x479;
      int * x362 = x265->cache_age;
      x362[x443] = 0;
      x365 = x443;
    }
    int * x366 = x265->cache_vals;
    int x482 = x365 * 2;
    int x367 = x366[x482];
    int * x368 = x265->cache_vals;
    int x484 = (x365 * 2) + 1;
    int x369 = x368[x484];
    int * x370 = x265->cache_vals;
    int x486 = (((((int)((unsigned int)(x269 + 4) >> 1)) & 1) * 2) + ((((x295 + ((~(((x297 ^ -1) | (-(x297 ^ -1))) >> 31)) & 2)) - (x299 + ((~(((x301 ^ -1) | (-(x301 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
    x370[x486] = x367;
    int * x372 = x265->cache_vals;
    int x489 = ((((((int)((unsigned int)(x269 + 4) >> 1)) & 1) * 2) + ((((x295 + ((~(((x297 ^ -1) | (-(x297 ^ -1))) >> 31)) & 2)) - (x299 + ((~(((x301 ^ -1) | (-(x301 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
    x372[x489] = x369;
    int * x374 = x265->cache_tags;
    int x492 = ((((int)((unsigned int)(x269 + 4) >> 1)) & 1) * 2) + ((((x295 + ((~(((x297 ^ -1) | (-(x297 ^ -1))) >> 31)) & 2)) - (x299 + ((~(((x301 ^ -1) | (-(x301 ^ -1))) >> 31)) & 2))) >> 31) & 1);
    int x493 = (int)((unsigned int)(x269 + 4) >> 1);
    x374[x492] = x493;
    int * x376 = x265->cache_dirty;
    x376[x492] = 0;
    int * x378 = x265->cache_age;
    x378[x492] = 1;
    int * x380 = x265->cache_age;
    int x381 = x380[x492];
    int * x382 = x265->cache_age;
    int x383 = x382[x402];
    int * x384 = x265->cache_age;
    int x500 = x383 + ((int)((unsigned int)(x383 - x381) >> 31));
    x384[x402] = x500;
    int * x386 = x265->cache_age;
    int x387 = x386[x404];
    int * x388 = x265->cache_age;
    int x503 = x387 + ((int)((unsigned int)(x387 - x381) >> 31));
    x388[x404] = x503;
    int * x390 = x265->cache_age;
    x390[x492] = 0;
    x393 = x492;
  }
  int x506 = (x393 * 2) + ((x269 + 4) & 1);
  int x394 = x280[x506];
  int * x395 = x265->regs;
  x395[2] = x394;
  return x265;
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