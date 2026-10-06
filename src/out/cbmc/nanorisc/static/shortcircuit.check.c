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

struct StateT * slot_12(struct StateT * x557);
struct StateT * slot_14(struct StateT * x576);
struct StateT * slot_6(struct StateT * x469);
struct StateT * slot_5(struct StateT * x258);
struct StateT * slot_2(struct StateT * x28);
struct StateT * slot_7(struct StateT * x505);
struct StateT * slot_3(struct StateT * x41);
struct StateT * snippet(struct StateT * x0);
struct StateT * slot_10(struct StateT * x523);
struct StateT * slot_1(struct StateT * x15);
struct StateT * slot_8(struct StateT * x515);
struct StateT * slot_4(struct StateT * x49);
struct StateT * slot_13(struct StateT * x571);
struct StateT * slot_11(struct StateT * x545);
struct StateT * slot_0(struct StateT * x2);
struct StateT * slot_12(struct StateT * x557) {
  int x558 = x557->timer;
  int x565 = x558 + 1;
  x557->timer = x565;
  int * x560 = x557->regs;
  int x561 = x560[4];
  int x568 = x561 + 1;
  x560[4] = x568;
  struct StateT * x563 = slot_14(x557);
  return x563;
}

struct StateT * slot_14(struct StateT * x576) {
  int x577 = x576->timer;
  int x581 = x577 + 1;
  x576->timer = x581;
  struct StateT * x579 = slot_3(x576);
  return x579;
}

struct StateT * slot_6(struct StateT * x469) {
  int * x470 = x469->regs;
  int x471 = x470[4];
  bool x490 = x471 >= 4;
  struct StateT * x486;
  if (x490) {
    int x472 = x469->timer;
    int x491 = x472 + 15;
    x469->timer = x491;
    int * x474 = x469->saved_regs;
    int x475 = x474[0];
    int * x476 = x469->regs;
    x476[0] = x475;
    int * x478 = x469->saved_regs;
    int x479 = x478[1];
    int * x480 = x469->regs;
    x480[1] = x479;
    struct StateT * x482 = slot_7(x469);
    x486 = x482;
  } else {
    struct StateT * x484 = slot_8(x469);
    x486 = x484;
  }
  return x486;
}

struct StateT * slot_5(struct StateT * x258) {
  int * x259 = x258->saved_regs;
  int * x260 = x258->regs;
  int x261 = x260[1];
  x259[1] = x261;
  int x263 = x258->timer;
  int x378 = x263 + 1;
  x258->timer = x378;
  int * x265 = x258->regs;
  int x266 = x265[3];
  int x267 = x265[4];
  int * x268 = x258->cache_tags;
  int x383 = (((int)((unsigned int)(x266 + x267) >> 1)) & 1) * 2;
  int x269 = x268[x383];
  int x384 = ((((int)((unsigned int)(x266 + x267) >> 1)) & 1) * 2) + 1;
  int x270 = x268[x384];
  int x385 = 4 + ((((int)((unsigned int)(x266 + x267) >> 1)) & 3) * 2);
  int x271 = x268[x385];
  int x386 = (4 + ((((int)((unsigned int)(x266 + x267) >> 1)) & 3) * 2)) + 1;
  int x272 = x268[x386];
  int x273 = x258->timer;
  int x387 = x273 + ((100 ^ (((~(((x271 ^ ((int)((unsigned int)(x266 + x267) >> 1))) | (-(x271 ^ ((int)((unsigned int)(x266 + x267) >> 1))))) >> 31)) | (~(((x272 ^ ((int)((unsigned int)(x266 + x267) >> 1))) | (-(x272 ^ ((int)((unsigned int)(x266 + x267) >> 1))))) >> 31))) & 104)) ^ (((~(((x269 ^ ((int)((unsigned int)(x266 + x267) >> 1))) | (-(x269 ^ ((int)((unsigned int)(x266 + x267) >> 1))))) >> 31)) | (~(((x270 ^ ((int)((unsigned int)(x266 + x267) >> 1))) | (-(x270 ^ ((int)((unsigned int)(x266 + x267) >> 1))))) >> 31))) & (1 ^ (100 ^ (((~(((x271 ^ ((int)((unsigned int)(x266 + x267) >> 1))) | (-(x271 ^ ((int)((unsigned int)(x266 + x267) >> 1))))) >> 31)) | (~(((x272 ^ ((int)((unsigned int)(x266 + x267) >> 1))) | (-(x272 ^ ((int)((unsigned int)(x266 + x267) >> 1))))) >> 31))) & 104)))));
  x258->timer = x387;
  int * x275 = x258->cache_vals;
  bool x388 = !(((~(((x269 ^ ((int)((unsigned int)(x266 + x267) >> 1))) | (-(x269 ^ ((int)((unsigned int)(x266 + x267) >> 1))))) >> 31)) | (~(((x270 ^ ((int)((unsigned int)(x266 + x267) >> 1))) | (-(x270 ^ ((int)((unsigned int)(x266 + x267) >> 1))))) >> 31))) == 0);
  int x368;
  if (x388) {
    int * x276 = x258->cache_age;
    int x390 = ((((int)((unsigned int)(x266 + x267) >> 1)) & 1) * 2) + ((~(((x270 ^ ((int)((unsigned int)(x266 + x267) >> 1))) | (-(x270 ^ ((int)((unsigned int)(x266 + x267) >> 1))))) >> 31)) & 1);
    int x277 = x276[x390];
    int x278 = x276[x383];
    int x391 = x278 + ((int)((unsigned int)(x278 - x277) >> 31));
    x276[x383] = x391;
    int * x280 = x258->cache_age;
    int x281 = x280[x384];
    int x393 = x281 + ((int)((unsigned int)(x281 - x277) >> 31));
    x280[x384] = x393;
    int * x283 = x258->cache_age;
    x283[x390] = 0;
    x368 = x390;
  } else {
    int * x286 = x258->cache_age;
    int x397 = (((int)((unsigned int)(x266 + x267) >> 1)) & 1) * 2;
    int x287 = x286[x397];
    int * x288 = x258->cache_tags;
    int x289 = x288[x397];
    int x290 = x286[x384];
    int x291 = x288[x384];
    bool x399 = !(((~(((x271 ^ ((int)((unsigned int)(x266 + x267) >> 1))) | (-(x271 ^ ((int)((unsigned int)(x266 + x267) >> 1))))) >> 31)) | (~(((x272 ^ ((int)((unsigned int)(x266 + x267) >> 1))) | (-(x272 ^ ((int)((unsigned int)(x266 + x267) >> 1))))) >> 31))) == 0);
    int x345;
    if (x399) {
      int * x292 = x258->cache_age;
      int x401 = (4 + ((((int)((unsigned int)(x266 + x267) >> 1)) & 3) * 2)) + ((~(((x272 ^ ((int)((unsigned int)(x266 + x267) >> 1))) | (-(x272 ^ ((int)((unsigned int)(x266 + x267) >> 1))))) >> 31)) & 1);
      int x293 = x292[x401];
      int x294 = x292[x385];
      int x402 = x294 + ((int)((unsigned int)(x294 - x293) >> 31));
      x292[x385] = x402;
      int * x296 = x258->cache_age;
      int x297 = x296[x386];
      int x404 = x297 + ((int)((unsigned int)(x297 - x293) >> 31));
      x296[x386] = x404;
      int * x299 = x258->cache_age;
      x299[x401] = 0;
      x345 = x401;
    } else {
      int * x302 = x258->cache_age;
      int x408 = 4 + ((((int)((unsigned int)(x266 + x267) >> 1)) & 3) * 2);
      int x303 = x302[x408];
      int * x304 = x258->cache_tags;
      int x305 = x304[x408];
      int x306 = x302[x386];
      int x307 = x304[x386];
      int * x308 = x258->cache_dirty;
      int x411 = (4 + ((((int)((unsigned int)(x266 + x267) >> 1)) & 3) * 2)) + ((((x303 + ((~(((x305 ^ -1) | (-(x305 ^ -1))) >> 31)) & 2)) - (x306 + ((~(((x307 ^ -1) | (-(x307 ^ -1))) >> 31)) & 2))) >> 31) & 1);
      int x309 = x308[x411];
      bool x412 = !(x309 == 0);
      if (x412) {
        int * x310 = x258->cache_tags;
        int x311 = x310[x411];
        int * x312 = x258->cache_vals;
        int x415 = ((4 + ((((int)((unsigned int)(x266 + x267) >> 1)) & 3) * 2)) + ((((x303 + ((~(((x305 ^ -1) | (-(x305 ^ -1))) >> 31)) & 2)) - (x306 + ((~(((x307 ^ -1) | (-(x307 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
        int x313 = x312[x415];
        int x416 = (((4 + ((((int)((unsigned int)(x266 + x267) >> 1)) & 3) * 2)) + ((((x303 + ((~(((x305 ^ -1) | (-(x305 ^ -1))) >> 31)) & 2)) - (x306 + ((~(((x307 ^ -1) | (-(x307 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
        int x314 = x312[x416];
        int * x315 = x258->mem;
        int x418 = x311 * 2;
        x315[x418] = x313;
        int * x317 = x258->mem;
        int x421 = (x311 * 2) + 1;
        x317[x421] = x314;
        ;
      } else {
        ;
      }
      int * x322 = x258->mem;
      int x426 = ((int)((unsigned int)(x266 + x267) >> 1)) * 2;
      int x323 = x322[x426];
      int x427 = (((int)((unsigned int)(x266 + x267) >> 1)) * 2) + 1;
      int x324 = x322[x427];
      int * x325 = x258->cache_vals;
      int x429 = ((4 + ((((int)((unsigned int)(x266 + x267) >> 1)) & 3) * 2)) + ((((x303 + ((~(((x305 ^ -1) | (-(x305 ^ -1))) >> 31)) & 2)) - (x306 + ((~(((x307 ^ -1) | (-(x307 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
      x325[x429] = x323;
      int * x327 = x258->cache_vals;
      int x432 = (((4 + ((((int)((unsigned int)(x266 + x267) >> 1)) & 3) * 2)) + ((((x303 + ((~(((x305 ^ -1) | (-(x305 ^ -1))) >> 31)) & 2)) - (x306 + ((~(((x307 ^ -1) | (-(x307 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
      x327[x432] = x324;
      int * x329 = x258->cache_tags;
      int x435 = (int)((unsigned int)(x266 + x267) >> 1);
      x329[x411] = x435;
      int * x331 = x258->cache_dirty;
      x331[x411] = 0;
      int * x333 = x258->cache_age;
      x333[x411] = 1;
      int * x335 = x258->cache_age;
      int x336 = x335[x411];
      int x337 = x335[x385];
      int x440 = x337 + ((int)((unsigned int)(x337 - x336) >> 31));
      x335[x385] = x440;
      int * x339 = x258->cache_age;
      int x340 = x339[x386];
      int x442 = x340 + ((int)((unsigned int)(x340 - x336) >> 31));
      x339[x386] = x442;
      int * x342 = x258->cache_age;
      x342[x411] = 0;
      x345 = x411;
    }
    int * x346 = x258->cache_vals;
    int x445 = x345 * 2;
    int x347 = x346[x445];
    int x446 = (x345 * 2) + 1;
    int x348 = x346[x446];
    int x447 = (((((int)((unsigned int)(x266 + x267) >> 1)) & 1) * 2) + ((((x287 + ((~(((x289 ^ -1) | (-(x289 ^ -1))) >> 31)) & 2)) - (x290 + ((~(((x291 ^ -1) | (-(x291 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
    x346[x447] = x347;
    int * x350 = x258->cache_vals;
    int x450 = ((((((int)((unsigned int)(x266 + x267) >> 1)) & 1) * 2) + ((((x287 + ((~(((x289 ^ -1) | (-(x289 ^ -1))) >> 31)) & 2)) - (x290 + ((~(((x291 ^ -1) | (-(x291 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
    x350[x450] = x348;
    int * x352 = x258->cache_tags;
    int x453 = ((((int)((unsigned int)(x266 + x267) >> 1)) & 1) * 2) + ((((x287 + ((~(((x289 ^ -1) | (-(x289 ^ -1))) >> 31)) & 2)) - (x290 + ((~(((x291 ^ -1) | (-(x291 ^ -1))) >> 31)) & 2))) >> 31) & 1);
    int x454 = (int)((unsigned int)(x266 + x267) >> 1);
    x352[x453] = x454;
    int * x354 = x258->cache_dirty;
    x354[x453] = 0;
    int * x356 = x258->cache_age;
    x356[x453] = 1;
    int * x358 = x258->cache_age;
    int x359 = x358[x453];
    int x360 = x358[x383];
    int x459 = x360 + ((int)((unsigned int)(x360 - x359) >> 31));
    x358[x383] = x459;
    int * x362 = x258->cache_age;
    int x363 = x362[x384];
    int x461 = x363 + ((int)((unsigned int)(x363 - x359) >> 31));
    x362[x384] = x461;
    int * x365 = x258->cache_age;
    x365[x453] = 0;
    x368 = x453;
  }
  int x464 = (x368 * 2) + ((x266 + x267) & 1);
  int x369 = x275[x464];
  int * x370 = x258->regs;
  x370[1] = x369;
  struct StateT * x372 = slot_6(x258);
  return x372;
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

struct StateT * slot_7(struct StateT * x505) {
  int x506 = x505->timer;
  int x511 = x506 + 1;
  x505->timer = x511;
  int * x508 = x505->regs;
  x508[0] = 1;
  return x505;
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

struct StateT * slot_10(struct StateT * x523) {
  int * x524 = x523->regs;
  int x525 = x524[0];
  int x526 = x524[1];
  bool x538 = !(x525 == x526);
  struct StateT * x533;
  if (x538) {
    int x527 = x523->timer;
    int x539 = x527 + 15;
    x523->timer = x539;
    struct StateT * x529 = slot_11(x523);
    x533 = x529;
  } else {
    struct StateT * x531 = slot_12(x523);
    x533 = x531;
  }
  return x533;
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

struct StateT * slot_8(struct StateT * x515) {
  int x516 = x515->timer;
  int x520 = x516 + 1;
  x515->timer = x520;
  struct StateT * x518 = slot_10(x515);
  return x518;
}

struct StateT * slot_4(struct StateT * x49) {
  int * x50 = x49->saved_regs;
  int * x51 = x49->regs;
  int x52 = x51[0];
  x50[0] = x52;
  int x54 = x49->timer;
  int x169 = x54 + 1;
  x49->timer = x169;
  int * x56 = x49->regs;
  int x57 = x56[2];
  int x58 = x56[4];
  int * x59 = x49->cache_tags;
  int x174 = (((int)((unsigned int)(x57 + x58) >> 1)) & 1) * 2;
  int x60 = x59[x174];
  int x175 = ((((int)((unsigned int)(x57 + x58) >> 1)) & 1) * 2) + 1;
  int x61 = x59[x175];
  int x176 = 4 + ((((int)((unsigned int)(x57 + x58) >> 1)) & 3) * 2);
  int x62 = x59[x176];
  int x177 = (4 + ((((int)((unsigned int)(x57 + x58) >> 1)) & 3) * 2)) + 1;
  int x63 = x59[x177];
  int x64 = x49->timer;
  int x178 = x64 + ((100 ^ (((~(((x62 ^ ((int)((unsigned int)(x57 + x58) >> 1))) | (-(x62 ^ ((int)((unsigned int)(x57 + x58) >> 1))))) >> 31)) | (~(((x63 ^ ((int)((unsigned int)(x57 + x58) >> 1))) | (-(x63 ^ ((int)((unsigned int)(x57 + x58) >> 1))))) >> 31))) & 104)) ^ (((~(((x60 ^ ((int)((unsigned int)(x57 + x58) >> 1))) | (-(x60 ^ ((int)((unsigned int)(x57 + x58) >> 1))))) >> 31)) | (~(((x61 ^ ((int)((unsigned int)(x57 + x58) >> 1))) | (-(x61 ^ ((int)((unsigned int)(x57 + x58) >> 1))))) >> 31))) & (1 ^ (100 ^ (((~(((x62 ^ ((int)((unsigned int)(x57 + x58) >> 1))) | (-(x62 ^ ((int)((unsigned int)(x57 + x58) >> 1))))) >> 31)) | (~(((x63 ^ ((int)((unsigned int)(x57 + x58) >> 1))) | (-(x63 ^ ((int)((unsigned int)(x57 + x58) >> 1))))) >> 31))) & 104)))));
  x49->timer = x178;
  int * x66 = x49->cache_vals;
  bool x179 = !(((~(((x60 ^ ((int)((unsigned int)(x57 + x58) >> 1))) | (-(x60 ^ ((int)((unsigned int)(x57 + x58) >> 1))))) >> 31)) | (~(((x61 ^ ((int)((unsigned int)(x57 + x58) >> 1))) | (-(x61 ^ ((int)((unsigned int)(x57 + x58) >> 1))))) >> 31))) == 0);
  int x159;
  if (x179) {
    int * x67 = x49->cache_age;
    int x181 = ((((int)((unsigned int)(x57 + x58) >> 1)) & 1) * 2) + ((~(((x61 ^ ((int)((unsigned int)(x57 + x58) >> 1))) | (-(x61 ^ ((int)((unsigned int)(x57 + x58) >> 1))))) >> 31)) & 1);
    int x68 = x67[x181];
    int x69 = x67[x174];
    int x182 = x69 + ((int)((unsigned int)(x69 - x68) >> 31));
    x67[x174] = x182;
    int * x71 = x49->cache_age;
    int x72 = x71[x175];
    int x184 = x72 + ((int)((unsigned int)(x72 - x68) >> 31));
    x71[x175] = x184;
    int * x74 = x49->cache_age;
    x74[x181] = 0;
    x159 = x181;
  } else {
    int * x77 = x49->cache_age;
    int x187 = (((int)((unsigned int)(x57 + x58) >> 1)) & 1) * 2;
    int x78 = x77[x187];
    int * x79 = x49->cache_tags;
    int x80 = x79[x187];
    int x81 = x77[x175];
    int x82 = x79[x175];
    bool x189 = !(((~(((x62 ^ ((int)((unsigned int)(x57 + x58) >> 1))) | (-(x62 ^ ((int)((unsigned int)(x57 + x58) >> 1))))) >> 31)) | (~(((x63 ^ ((int)((unsigned int)(x57 + x58) >> 1))) | (-(x63 ^ ((int)((unsigned int)(x57 + x58) >> 1))))) >> 31))) == 0);
    int x136;
    if (x189) {
      int * x83 = x49->cache_age;
      int x191 = (4 + ((((int)((unsigned int)(x57 + x58) >> 1)) & 3) * 2)) + ((~(((x63 ^ ((int)((unsigned int)(x57 + x58) >> 1))) | (-(x63 ^ ((int)((unsigned int)(x57 + x58) >> 1))))) >> 31)) & 1);
      int x84 = x83[x191];
      int x85 = x83[x176];
      int x192 = x85 + ((int)((unsigned int)(x85 - x84) >> 31));
      x83[x176] = x192;
      int * x87 = x49->cache_age;
      int x88 = x87[x177];
      int x194 = x88 + ((int)((unsigned int)(x88 - x84) >> 31));
      x87[x177] = x194;
      int * x90 = x49->cache_age;
      x90[x191] = 0;
      x136 = x191;
    } else {
      int * x93 = x49->cache_age;
      int x197 = 4 + ((((int)((unsigned int)(x57 + x58) >> 1)) & 3) * 2);
      int x94 = x93[x197];
      int * x95 = x49->cache_tags;
      int x96 = x95[x197];
      int x97 = x93[x177];
      int x98 = x95[x177];
      int * x99 = x49->cache_dirty;
      int x200 = (4 + ((((int)((unsigned int)(x57 + x58) >> 1)) & 3) * 2)) + ((((x94 + ((~(((x96 ^ -1) | (-(x96 ^ -1))) >> 31)) & 2)) - (x97 + ((~(((x98 ^ -1) | (-(x98 ^ -1))) >> 31)) & 2))) >> 31) & 1);
      int x100 = x99[x200];
      bool x201 = !(x100 == 0);
      if (x201) {
        int * x101 = x49->cache_tags;
        int x102 = x101[x200];
        int * x103 = x49->cache_vals;
        int x204 = ((4 + ((((int)((unsigned int)(x57 + x58) >> 1)) & 3) * 2)) + ((((x94 + ((~(((x96 ^ -1) | (-(x96 ^ -1))) >> 31)) & 2)) - (x97 + ((~(((x98 ^ -1) | (-(x98 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
        int x104 = x103[x204];
        int x205 = (((4 + ((((int)((unsigned int)(x57 + x58) >> 1)) & 3) * 2)) + ((((x94 + ((~(((x96 ^ -1) | (-(x96 ^ -1))) >> 31)) & 2)) - (x97 + ((~(((x98 ^ -1) | (-(x98 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
        int x105 = x103[x205];
        int * x106 = x49->mem;
        int x207 = x102 * 2;
        x106[x207] = x104;
        int * x108 = x49->mem;
        int x210 = (x102 * 2) + 1;
        x108[x210] = x105;
        ;
      } else {
        ;
      }
      int * x113 = x49->mem;
      int x215 = ((int)((unsigned int)(x57 + x58) >> 1)) * 2;
      int x114 = x113[x215];
      int x216 = (((int)((unsigned int)(x57 + x58) >> 1)) * 2) + 1;
      int x115 = x113[x216];
      int * x116 = x49->cache_vals;
      int x218 = ((4 + ((((int)((unsigned int)(x57 + x58) >> 1)) & 3) * 2)) + ((((x94 + ((~(((x96 ^ -1) | (-(x96 ^ -1))) >> 31)) & 2)) - (x97 + ((~(((x98 ^ -1) | (-(x98 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
      x116[x218] = x114;
      int * x118 = x49->cache_vals;
      int x221 = (((4 + ((((int)((unsigned int)(x57 + x58) >> 1)) & 3) * 2)) + ((((x94 + ((~(((x96 ^ -1) | (-(x96 ^ -1))) >> 31)) & 2)) - (x97 + ((~(((x98 ^ -1) | (-(x98 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
      x118[x221] = x115;
      int * x120 = x49->cache_tags;
      int x224 = (int)((unsigned int)(x57 + x58) >> 1);
      x120[x200] = x224;
      int * x122 = x49->cache_dirty;
      x122[x200] = 0;
      int * x124 = x49->cache_age;
      x124[x200] = 1;
      int * x126 = x49->cache_age;
      int x127 = x126[x200];
      int x128 = x126[x176];
      int x229 = x128 + ((int)((unsigned int)(x128 - x127) >> 31));
      x126[x176] = x229;
      int * x130 = x49->cache_age;
      int x131 = x130[x177];
      int x231 = x131 + ((int)((unsigned int)(x131 - x127) >> 31));
      x130[x177] = x231;
      int * x133 = x49->cache_age;
      x133[x200] = 0;
      x136 = x200;
    }
    int * x137 = x49->cache_vals;
    int x234 = x136 * 2;
    int x138 = x137[x234];
    int x235 = (x136 * 2) + 1;
    int x139 = x137[x235];
    int x236 = (((((int)((unsigned int)(x57 + x58) >> 1)) & 1) * 2) + ((((x78 + ((~(((x80 ^ -1) | (-(x80 ^ -1))) >> 31)) & 2)) - (x81 + ((~(((x82 ^ -1) | (-(x82 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
    x137[x236] = x138;
    int * x141 = x49->cache_vals;
    int x239 = ((((((int)((unsigned int)(x57 + x58) >> 1)) & 1) * 2) + ((((x78 + ((~(((x80 ^ -1) | (-(x80 ^ -1))) >> 31)) & 2)) - (x81 + ((~(((x82 ^ -1) | (-(x82 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
    x141[x239] = x139;
    int * x143 = x49->cache_tags;
    int x242 = ((((int)((unsigned int)(x57 + x58) >> 1)) & 1) * 2) + ((((x78 + ((~(((x80 ^ -1) | (-(x80 ^ -1))) >> 31)) & 2)) - (x81 + ((~(((x82 ^ -1) | (-(x82 ^ -1))) >> 31)) & 2))) >> 31) & 1);
    int x243 = (int)((unsigned int)(x57 + x58) >> 1);
    x143[x242] = x243;
    int * x145 = x49->cache_dirty;
    x145[x242] = 0;
    int * x147 = x49->cache_age;
    x147[x242] = 1;
    int * x149 = x49->cache_age;
    int x150 = x149[x242];
    int x151 = x149[x174];
    int x248 = x151 + ((int)((unsigned int)(x151 - x150) >> 31));
    x149[x174] = x248;
    int * x153 = x49->cache_age;
    int x154 = x153[x175];
    int x250 = x154 + ((int)((unsigned int)(x154 - x150) >> 31));
    x153[x175] = x250;
    int * x156 = x49->cache_age;
    x156[x242] = 0;
    x159 = x242;
  }
  int x253 = (x159 * 2) + ((x57 + x58) & 1);
  int x160 = x66[x253];
  int * x161 = x49->regs;
  x161[0] = x160;
  struct StateT * x163 = slot_5(x49);
  return x163;
}

struct StateT * slot_13(struct StateT * x571) {
  int x572 = x571->timer;
  int x575 = x572 + 1;
  x571->timer = x575;
  return x571;
}

struct StateT * slot_11(struct StateT * x545) {
  int x546 = x545->timer;
  int x552 = x546 + 1;
  x545->timer = x552;
  int * x548 = x545->regs;
  x548[0] = 0;
  struct StateT * x550 = slot_13(x545);
  return x550;
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
    s1.mem[SECRET_OFFSET+i] = secret(0, 20);
    s2.mem[SECRET_OFFSET+i] = secret(0, 20);
  }
  struct StateT *s1_ = snippet(&s1);
  struct StateT *s2_ = snippet(&s2);
  //@ assert untainted_timer: !\tainted(s1_->timer==s2_->timer);
  koika_assert(s1_->timer==s2_->timer, "timing leak");
  return 0;
}