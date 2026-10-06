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

struct StateT * snippet(struct StateT * x0);
struct StateT * slot_1(struct StateT * x10);
struct StateT * slot_2(struct StateT * x215);
struct StateT * slot_3(struct StateT * x424);
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
  int x129 = x15 + 1;
  x10->timer = x129;
  int * x17 = x10->regs;
  int x18 = x17[0];
  int * x19 = x10->cache_tags;
  int x133 = (((int)((unsigned int)x18 >> 1)) & 1) * 2;
  int x20 = x19[x133];
  int x134 = ((((int)((unsigned int)x18 >> 1)) & 1) * 2) + 1;
  int x21 = x19[x134];
  int x135 = 4 + ((((int)((unsigned int)x18 >> 1)) & 3) * 2);
  int x22 = x19[x135];
  int x136 = (4 + ((((int)((unsigned int)x18 >> 1)) & 3) * 2)) + 1;
  int x23 = x19[x136];
  int x24 = x10->timer;
  int x137 = x24 + ((100 ^ (((~(((x22 ^ ((int)((unsigned int)x18 >> 1))) | (-(x22 ^ ((int)((unsigned int)x18 >> 1))))) >> 31)) | (~(((x23 ^ ((int)((unsigned int)x18 >> 1))) | (-(x23 ^ ((int)((unsigned int)x18 >> 1))))) >> 31))) & 104)) ^ (((~(((x20 ^ ((int)((unsigned int)x18 >> 1))) | (-(x20 ^ ((int)((unsigned int)x18 >> 1))))) >> 31)) | (~(((x21 ^ ((int)((unsigned int)x18 >> 1))) | (-(x21 ^ ((int)((unsigned int)x18 >> 1))))) >> 31))) & (1 ^ (100 ^ (((~(((x22 ^ ((int)((unsigned int)x18 >> 1))) | (-(x22 ^ ((int)((unsigned int)x18 >> 1))))) >> 31)) | (~(((x23 ^ ((int)((unsigned int)x18 >> 1))) | (-(x23 ^ ((int)((unsigned int)x18 >> 1))))) >> 31))) & 104)))));
  x10->timer = x137;
  int * x26 = x10->cache_vals;
  bool x138 = !(((~(((x20 ^ ((int)((unsigned int)x18 >> 1))) | (-(x20 ^ ((int)((unsigned int)x18 >> 1))))) >> 31)) | (~(((x21 ^ ((int)((unsigned int)x18 >> 1))) | (-(x21 ^ ((int)((unsigned int)x18 >> 1))))) >> 31))) == 0);
  int x119;
  if (x138) {
    int * x27 = x10->cache_age;
    int x140 = ((((int)((unsigned int)x18 >> 1)) & 1) * 2) + ((~(((x21 ^ ((int)((unsigned int)x18 >> 1))) | (-(x21 ^ ((int)((unsigned int)x18 >> 1))))) >> 31)) & 1);
    int x28 = x27[x140];
    int x29 = x27[x133];
    int x141 = x29 + ((int)((unsigned int)(x29 - x28) >> 31));
    x27[x133] = x141;
    int * x31 = x10->cache_age;
    int x32 = x31[x134];
    int x143 = x32 + ((int)((unsigned int)(x32 - x28) >> 31));
    x31[x134] = x143;
    int * x34 = x10->cache_age;
    x34[x140] = 0;
    x119 = x140;
  } else {
    int * x37 = x10->cache_age;
    int x146 = (((int)((unsigned int)x18 >> 1)) & 1) * 2;
    int x38 = x37[x146];
    int * x39 = x10->cache_tags;
    int x40 = x39[x146];
    int x41 = x37[x134];
    int x42 = x39[x134];
    bool x148 = !(((~(((x22 ^ ((int)((unsigned int)x18 >> 1))) | (-(x22 ^ ((int)((unsigned int)x18 >> 1))))) >> 31)) | (~(((x23 ^ ((int)((unsigned int)x18 >> 1))) | (-(x23 ^ ((int)((unsigned int)x18 >> 1))))) >> 31))) == 0);
    int x96;
    if (x148) {
      int * x43 = x10->cache_age;
      int x150 = (4 + ((((int)((unsigned int)x18 >> 1)) & 3) * 2)) + ((~(((x23 ^ ((int)((unsigned int)x18 >> 1))) | (-(x23 ^ ((int)((unsigned int)x18 >> 1))))) >> 31)) & 1);
      int x44 = x43[x150];
      int x45 = x43[x135];
      int x151 = x45 + ((int)((unsigned int)(x45 - x44) >> 31));
      x43[x135] = x151;
      int * x47 = x10->cache_age;
      int x48 = x47[x136];
      int x153 = x48 + ((int)((unsigned int)(x48 - x44) >> 31));
      x47[x136] = x153;
      int * x50 = x10->cache_age;
      x50[x150] = 0;
      x96 = x150;
    } else {
      int * x53 = x10->cache_age;
      int x156 = 4 + ((((int)((unsigned int)x18 >> 1)) & 3) * 2);
      int x54 = x53[x156];
      int * x55 = x10->cache_tags;
      int x56 = x55[x156];
      int x57 = x53[x136];
      int x58 = x55[x136];
      int * x59 = x10->cache_dirty;
      int x159 = (4 + ((((int)((unsigned int)x18 >> 1)) & 3) * 2)) + ((((x54 + ((~(((x56 ^ -1) | (-(x56 ^ -1))) >> 31)) & 2)) - (x57 + ((~(((x58 ^ -1) | (-(x58 ^ -1))) >> 31)) & 2))) >> 31) & 1);
      int x60 = x59[x159];
      bool x160 = !(x60 == 0);
      if (x160) {
        int * x61 = x10->cache_tags;
        int x62 = x61[x159];
        int * x63 = x10->cache_vals;
        int x163 = ((4 + ((((int)((unsigned int)x18 >> 1)) & 3) * 2)) + ((((x54 + ((~(((x56 ^ -1) | (-(x56 ^ -1))) >> 31)) & 2)) - (x57 + ((~(((x58 ^ -1) | (-(x58 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
        int x64 = x63[x163];
        int x164 = (((4 + ((((int)((unsigned int)x18 >> 1)) & 3) * 2)) + ((((x54 + ((~(((x56 ^ -1) | (-(x56 ^ -1))) >> 31)) & 2)) - (x57 + ((~(((x58 ^ -1) | (-(x58 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
        int x65 = x63[x164];
        int * x66 = x10->mem;
        int x166 = x62 * 2;
        x66[x166] = x64;
        int * x68 = x10->mem;
        int x169 = (x62 * 2) + 1;
        x68[x169] = x65;
        ;
      } else {
        ;
      }
      int * x73 = x10->mem;
      int x174 = ((int)((unsigned int)x18 >> 1)) * 2;
      int x74 = x73[x174];
      int x175 = (((int)((unsigned int)x18 >> 1)) * 2) + 1;
      int x75 = x73[x175];
      int * x76 = x10->cache_vals;
      int x177 = ((4 + ((((int)((unsigned int)x18 >> 1)) & 3) * 2)) + ((((x54 + ((~(((x56 ^ -1) | (-(x56 ^ -1))) >> 31)) & 2)) - (x57 + ((~(((x58 ^ -1) | (-(x58 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
      x76[x177] = x74;
      int * x78 = x10->cache_vals;
      int x180 = (((4 + ((((int)((unsigned int)x18 >> 1)) & 3) * 2)) + ((((x54 + ((~(((x56 ^ -1) | (-(x56 ^ -1))) >> 31)) & 2)) - (x57 + ((~(((x58 ^ -1) | (-(x58 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
      x78[x180] = x75;
      int * x80 = x10->cache_tags;
      int x183 = (int)((unsigned int)x18 >> 1);
      x80[x159] = x183;
      int * x82 = x10->cache_dirty;
      x82[x159] = 0;
      int * x84 = x10->cache_age;
      x84[x159] = 1;
      int * x86 = x10->cache_age;
      int x87 = x86[x159];
      int x88 = x86[x135];
      int x187 = x88 + ((int)((unsigned int)(x88 - x87) >> 31));
      x86[x135] = x187;
      int * x90 = x10->cache_age;
      int x91 = x90[x136];
      int x189 = x91 + ((int)((unsigned int)(x91 - x87) >> 31));
      x90[x136] = x189;
      int * x93 = x10->cache_age;
      x93[x159] = 0;
      x96 = x159;
    }
    int * x97 = x10->cache_vals;
    int x192 = x96 * 2;
    int x98 = x97[x192];
    int x193 = (x96 * 2) + 1;
    int x99 = x97[x193];
    int x194 = (((((int)((unsigned int)x18 >> 1)) & 1) * 2) + ((((x38 + ((~(((x40 ^ -1) | (-(x40 ^ -1))) >> 31)) & 2)) - (x41 + ((~(((x42 ^ -1) | (-(x42 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
    x97[x194] = x98;
    int * x101 = x10->cache_vals;
    int x197 = ((((((int)((unsigned int)x18 >> 1)) & 1) * 2) + ((((x38 + ((~(((x40 ^ -1) | (-(x40 ^ -1))) >> 31)) & 2)) - (x41 + ((~(((x42 ^ -1) | (-(x42 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
    x101[x197] = x99;
    int * x103 = x10->cache_tags;
    int x200 = ((((int)((unsigned int)x18 >> 1)) & 1) * 2) + ((((x38 + ((~(((x40 ^ -1) | (-(x40 ^ -1))) >> 31)) & 2)) - (x41 + ((~(((x42 ^ -1) | (-(x42 ^ -1))) >> 31)) & 2))) >> 31) & 1);
    int x201 = (int)((unsigned int)x18 >> 1);
    x103[x200] = x201;
    int * x105 = x10->cache_dirty;
    x105[x200] = 0;
    int * x107 = x10->cache_age;
    x107[x200] = 1;
    int * x109 = x10->cache_age;
    int x110 = x109[x200];
    int x111 = x109[x133];
    int x205 = x111 + ((int)((unsigned int)(x111 - x110) >> 31));
    x109[x133] = x205;
    int * x113 = x10->cache_age;
    int x114 = x113[x134];
    int x207 = x114 + ((int)((unsigned int)(x114 - x110) >> 31));
    x113[x134] = x207;
    int * x116 = x10->cache_age;
    x116[x200] = 0;
    x119 = x200;
  }
  int x210 = (x119 * 2) + (x18 & 1);
  int x120 = x26[x210];
  int * x121 = x10->regs;
  x121[1] = x120;
  struct StateT * x123 = slot_2(x10);
  return x123;
}

struct StateT * slot_2(struct StateT * x215) {
  int * x216 = x215->saved_regs;
  int * x217 = x215->regs;
  int x218 = x217[2];
  x216[2] = x218;
  int x220 = x215->timer;
  int x334 = x220 + 1;
  x215->timer = x334;
  int * x222 = x215->regs;
  int x223 = x222[1];
  int * x224 = x215->cache_tags;
  int x338 = (((int)((unsigned int)(x223 + 4) >> 1)) & 1) * 2;
  int x225 = x224[x338];
  int x339 = ((((int)((unsigned int)(x223 + 4) >> 1)) & 1) * 2) + 1;
  int x226 = x224[x339];
  int x340 = 4 + ((((int)((unsigned int)(x223 + 4) >> 1)) & 3) * 2);
  int x227 = x224[x340];
  int x341 = (4 + ((((int)((unsigned int)(x223 + 4) >> 1)) & 3) * 2)) + 1;
  int x228 = x224[x341];
  int x229 = x215->timer;
  int x342 = x229 + ((100 ^ (((~(((x227 ^ ((int)((unsigned int)(x223 + 4) >> 1))) | (-(x227 ^ ((int)((unsigned int)(x223 + 4) >> 1))))) >> 31)) | (~(((x228 ^ ((int)((unsigned int)(x223 + 4) >> 1))) | (-(x228 ^ ((int)((unsigned int)(x223 + 4) >> 1))))) >> 31))) & 104)) ^ (((~(((x225 ^ ((int)((unsigned int)(x223 + 4) >> 1))) | (-(x225 ^ ((int)((unsigned int)(x223 + 4) >> 1))))) >> 31)) | (~(((x226 ^ ((int)((unsigned int)(x223 + 4) >> 1))) | (-(x226 ^ ((int)((unsigned int)(x223 + 4) >> 1))))) >> 31))) & (1 ^ (100 ^ (((~(((x227 ^ ((int)((unsigned int)(x223 + 4) >> 1))) | (-(x227 ^ ((int)((unsigned int)(x223 + 4) >> 1))))) >> 31)) | (~(((x228 ^ ((int)((unsigned int)(x223 + 4) >> 1))) | (-(x228 ^ ((int)((unsigned int)(x223 + 4) >> 1))))) >> 31))) & 104)))));
  x215->timer = x342;
  int * x231 = x215->cache_vals;
  bool x343 = !(((~(((x225 ^ ((int)((unsigned int)(x223 + 4) >> 1))) | (-(x225 ^ ((int)((unsigned int)(x223 + 4) >> 1))))) >> 31)) | (~(((x226 ^ ((int)((unsigned int)(x223 + 4) >> 1))) | (-(x226 ^ ((int)((unsigned int)(x223 + 4) >> 1))))) >> 31))) == 0);
  int x324;
  if (x343) {
    int * x232 = x215->cache_age;
    int x345 = ((((int)((unsigned int)(x223 + 4) >> 1)) & 1) * 2) + ((~(((x226 ^ ((int)((unsigned int)(x223 + 4) >> 1))) | (-(x226 ^ ((int)((unsigned int)(x223 + 4) >> 1))))) >> 31)) & 1);
    int x233 = x232[x345];
    int x234 = x232[x338];
    int x346 = x234 + ((int)((unsigned int)(x234 - x233) >> 31));
    x232[x338] = x346;
    int * x236 = x215->cache_age;
    int x237 = x236[x339];
    int x348 = x237 + ((int)((unsigned int)(x237 - x233) >> 31));
    x236[x339] = x348;
    int * x239 = x215->cache_age;
    x239[x345] = 0;
    x324 = x345;
  } else {
    int * x242 = x215->cache_age;
    int x352 = (((int)((unsigned int)(x223 + 4) >> 1)) & 1) * 2;
    int x243 = x242[x352];
    int * x244 = x215->cache_tags;
    int x245 = x244[x352];
    int x246 = x242[x339];
    int x247 = x244[x339];
    bool x354 = !(((~(((x227 ^ ((int)((unsigned int)(x223 + 4) >> 1))) | (-(x227 ^ ((int)((unsigned int)(x223 + 4) >> 1))))) >> 31)) | (~(((x228 ^ ((int)((unsigned int)(x223 + 4) >> 1))) | (-(x228 ^ ((int)((unsigned int)(x223 + 4) >> 1))))) >> 31))) == 0);
    int x301;
    if (x354) {
      int * x248 = x215->cache_age;
      int x356 = (4 + ((((int)((unsigned int)(x223 + 4) >> 1)) & 3) * 2)) + ((~(((x228 ^ ((int)((unsigned int)(x223 + 4) >> 1))) | (-(x228 ^ ((int)((unsigned int)(x223 + 4) >> 1))))) >> 31)) & 1);
      int x249 = x248[x356];
      int x250 = x248[x340];
      int x357 = x250 + ((int)((unsigned int)(x250 - x249) >> 31));
      x248[x340] = x357;
      int * x252 = x215->cache_age;
      int x253 = x252[x341];
      int x359 = x253 + ((int)((unsigned int)(x253 - x249) >> 31));
      x252[x341] = x359;
      int * x255 = x215->cache_age;
      x255[x356] = 0;
      x301 = x356;
    } else {
      int * x258 = x215->cache_age;
      int x363 = 4 + ((((int)((unsigned int)(x223 + 4) >> 1)) & 3) * 2);
      int x259 = x258[x363];
      int * x260 = x215->cache_tags;
      int x261 = x260[x363];
      int x262 = x258[x341];
      int x263 = x260[x341];
      int * x264 = x215->cache_dirty;
      int x366 = (4 + ((((int)((unsigned int)(x223 + 4) >> 1)) & 3) * 2)) + ((((x259 + ((~(((x261 ^ -1) | (-(x261 ^ -1))) >> 31)) & 2)) - (x262 + ((~(((x263 ^ -1) | (-(x263 ^ -1))) >> 31)) & 2))) >> 31) & 1);
      int x265 = x264[x366];
      bool x367 = !(x265 == 0);
      if (x367) {
        int * x266 = x215->cache_tags;
        int x267 = x266[x366];
        int * x268 = x215->cache_vals;
        int x370 = ((4 + ((((int)((unsigned int)(x223 + 4) >> 1)) & 3) * 2)) + ((((x259 + ((~(((x261 ^ -1) | (-(x261 ^ -1))) >> 31)) & 2)) - (x262 + ((~(((x263 ^ -1) | (-(x263 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
        int x269 = x268[x370];
        int x371 = (((4 + ((((int)((unsigned int)(x223 + 4) >> 1)) & 3) * 2)) + ((((x259 + ((~(((x261 ^ -1) | (-(x261 ^ -1))) >> 31)) & 2)) - (x262 + ((~(((x263 ^ -1) | (-(x263 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
        int x270 = x268[x371];
        int * x271 = x215->mem;
        int x373 = x267 * 2;
        x271[x373] = x269;
        int * x273 = x215->mem;
        int x376 = (x267 * 2) + 1;
        x273[x376] = x270;
        ;
      } else {
        ;
      }
      int * x278 = x215->mem;
      int x381 = ((int)((unsigned int)(x223 + 4) >> 1)) * 2;
      int x279 = x278[x381];
      int x382 = (((int)((unsigned int)(x223 + 4) >> 1)) * 2) + 1;
      int x280 = x278[x382];
      int * x281 = x215->cache_vals;
      int x384 = ((4 + ((((int)((unsigned int)(x223 + 4) >> 1)) & 3) * 2)) + ((((x259 + ((~(((x261 ^ -1) | (-(x261 ^ -1))) >> 31)) & 2)) - (x262 + ((~(((x263 ^ -1) | (-(x263 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
      x281[x384] = x279;
      int * x283 = x215->cache_vals;
      int x387 = (((4 + ((((int)((unsigned int)(x223 + 4) >> 1)) & 3) * 2)) + ((((x259 + ((~(((x261 ^ -1) | (-(x261 ^ -1))) >> 31)) & 2)) - (x262 + ((~(((x263 ^ -1) | (-(x263 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
      x283[x387] = x280;
      int * x285 = x215->cache_tags;
      int x390 = (int)((unsigned int)(x223 + 4) >> 1);
      x285[x366] = x390;
      int * x287 = x215->cache_dirty;
      x287[x366] = 0;
      int * x289 = x215->cache_age;
      x289[x366] = 1;
      int * x291 = x215->cache_age;
      int x292 = x291[x366];
      int x293 = x291[x340];
      int x395 = x293 + ((int)((unsigned int)(x293 - x292) >> 31));
      x291[x340] = x395;
      int * x295 = x215->cache_age;
      int x296 = x295[x341];
      int x397 = x296 + ((int)((unsigned int)(x296 - x292) >> 31));
      x295[x341] = x397;
      int * x298 = x215->cache_age;
      x298[x366] = 0;
      x301 = x366;
    }
    int * x302 = x215->cache_vals;
    int x400 = x301 * 2;
    int x303 = x302[x400];
    int x401 = (x301 * 2) + 1;
    int x304 = x302[x401];
    int x402 = (((((int)((unsigned int)(x223 + 4) >> 1)) & 1) * 2) + ((((x243 + ((~(((x245 ^ -1) | (-(x245 ^ -1))) >> 31)) & 2)) - (x246 + ((~(((x247 ^ -1) | (-(x247 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
    x302[x402] = x303;
    int * x306 = x215->cache_vals;
    int x405 = ((((((int)((unsigned int)(x223 + 4) >> 1)) & 1) * 2) + ((((x243 + ((~(((x245 ^ -1) | (-(x245 ^ -1))) >> 31)) & 2)) - (x246 + ((~(((x247 ^ -1) | (-(x247 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
    x306[x405] = x304;
    int * x308 = x215->cache_tags;
    int x408 = ((((int)((unsigned int)(x223 + 4) >> 1)) & 1) * 2) + ((((x243 + ((~(((x245 ^ -1) | (-(x245 ^ -1))) >> 31)) & 2)) - (x246 + ((~(((x247 ^ -1) | (-(x247 ^ -1))) >> 31)) & 2))) >> 31) & 1);
    int x409 = (int)((unsigned int)(x223 + 4) >> 1);
    x308[x408] = x409;
    int * x310 = x215->cache_dirty;
    x310[x408] = 0;
    int * x312 = x215->cache_age;
    x312[x408] = 1;
    int * x314 = x215->cache_age;
    int x315 = x314[x408];
    int x316 = x314[x338];
    int x414 = x316 + ((int)((unsigned int)(x316 - x315) >> 31));
    x314[x338] = x414;
    int * x318 = x215->cache_age;
    int x319 = x318[x339];
    int x416 = x319 + ((int)((unsigned int)(x319 - x315) >> 31));
    x318[x339] = x416;
    int * x321 = x215->cache_age;
    x321[x408] = 0;
    x324 = x408;
  }
  int x419 = (x324 * 2) + ((x223 + 4) & 1);
  int x325 = x231[x419];
  int * x326 = x215->regs;
  x326[2] = x325;
  struct StateT * x328 = slot_3(x215);
  return x328;
}

struct StateT * slot_3(struct StateT * x424) {
  int * x425 = x424->regs;
  int x426 = x425[0];
  bool x443 = x426 == 0;
  struct StateT * x439;
  if (x443) {
    int x427 = x424->timer;
    int x444 = x427 + 15;
    x424->timer = x444;
    int * x429 = x424->saved_regs;
    int x430 = x429[1];
    int * x431 = x424->regs;
    x431[1] = x430;
    int * x433 = x424->saved_regs;
    int x434 = x433[2];
    int * x435 = x424->regs;
    x435[2] = x434;
    x439 = x424;
  } else {
    x439 = x424;
  }
  return x439;
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
  //@ assert untainted_timer: !\tainted(s1_->timer==s2_->timer);
  koika_assert(s1_->timer==s2_->timer, "timing leak");
  return 0;
}