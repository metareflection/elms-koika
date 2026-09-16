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
  int cache_tags[12];
  int cache_dirty[12];
  int cache_age[12];
  int cache_vals[24];
  int timer;
};

struct StateT * snippet(struct StateT * x0);
struct StateT * slot_10(struct StateT * x630);
struct StateT * slot_1(struct StateT * x15);
struct StateT * slot_8(struct StateT * x635);
struct StateT * slot_9(struct StateT * x602);
struct StateT * slot_2(struct StateT * x28);
struct StateT * slot_7(struct StateT * x614);
struct StateT * slot_3(struct StateT * x41);
struct StateT * slot_11(struct StateT * x592);
struct StateT * slot_0(struct StateT * x2);
struct StateT * snippet(struct StateT * x0) {
  struct StateT * x1 = slot_0(x0);
  return x1;
}

struct StateT * slot_10(struct StateT * x630) {
  int x631 = x630->timer;
  int x634 = x631 + 1;
  x630->timer = x634;
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

struct StateT * slot_8(struct StateT * x635) {
  int x636 = x635->timer;
  int x640 = x636 + 1;
  x635->timer = x640;
  struct StateT * x638 = slot_3(x635);
  return x638;
}

struct StateT * slot_9(struct StateT * x602) {
  int x603 = x602->timer;
  int x609 = x603 + 1;
  x602->timer = x609;
  int * x605 = x602->regs;
  x605[0] = 0;
  struct StateT * x607 = slot_10(x602);
  return x607;
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

struct StateT * slot_7(struct StateT * x614) {
  int x615 = x614->timer;
  int x623 = x615 + 1;
  x614->timer = x623;
  int * x617 = x614->regs;
  int x618 = x617[4];
  int * x619 = x614->regs;
  int x627 = x618 + 1;
  x619[4] = x627;
  struct StateT * x621 = slot_8(x614);
  return x621;
}

struct StateT * slot_3(struct StateT * x41) {
  int * x42 = x41->saved_regs;
  int * x43 = x41->regs;
  int x44 = x43[0];
  x42[0] = x44;
  int x46 = x41->timer;
  int x348 = x46 + 1;
  x41->timer = x348;
  int * x48 = x41->regs;
  int x49 = x48[2];
  int * x50 = x41->regs;
  int x51 = x50[4];
  int * x52 = x41->cache_tags;
  int x354 = (((int)((unsigned int)(x49 + x51) >> 1)) & 1) * 2;
  int x53 = x52[x354];
  int * x54 = x41->cache_tags;
  int x356 = ((((int)((unsigned int)(x49 + x51) >> 1)) & 1) * 2) + 1;
  int x55 = x54[x356];
  int * x56 = x41->cache_tags;
  int x358 = 4 + ((((int)((unsigned int)(x49 + x51) >> 1)) & 3) * 2);
  int x57 = x56[x358];
  int * x58 = x41->cache_tags;
  int x360 = (4 + ((((int)((unsigned int)(x49 + x51) >> 1)) & 3) * 2)) + 1;
  int x59 = x58[x360];
  int x60 = x41->timer;
  int x361 = x60 + ((100 ^ (((~(((x57 ^ ((int)((unsigned int)(x49 + x51) >> 1))) | (-(x57 ^ ((int)((unsigned int)(x49 + x51) >> 1))))) >> 31)) | (~(((x59 ^ ((int)((unsigned int)(x49 + x51) >> 1))) | (-(x59 ^ ((int)((unsigned int)(x49 + x51) >> 1))))) >> 31))) & 104)) ^ (((~(((x53 ^ ((int)((unsigned int)(x49 + x51) >> 1))) | (-(x53 ^ ((int)((unsigned int)(x49 + x51) >> 1))))) >> 31)) | (~(((x55 ^ ((int)((unsigned int)(x49 + x51) >> 1))) | (-(x55 ^ ((int)((unsigned int)(x49 + x51) >> 1))))) >> 31))) & (1 ^ (100 ^ (((~(((x57 ^ ((int)((unsigned int)(x49 + x51) >> 1))) | (-(x57 ^ ((int)((unsigned int)(x49 + x51) >> 1))))) >> 31)) | (~(((x59 ^ ((int)((unsigned int)(x49 + x51) >> 1))) | (-(x59 ^ ((int)((unsigned int)(x49 + x51) >> 1))))) >> 31))) & 104)))));
  x41->timer = x361;
  int * x62 = x41->cache_vals;
  bool x362 = !(((~(((x53 ^ ((int)((unsigned int)(x49 + x51) >> 1))) | (-(x53 ^ ((int)((unsigned int)(x49 + x51) >> 1))))) >> 31)) | (~(((x55 ^ ((int)((unsigned int)(x49 + x51) >> 1))) | (-(x55 ^ ((int)((unsigned int)(x49 + x51) >> 1))))) >> 31))) == 0);
  int x175;
  if (x362) {
    int * x63 = x41->cache_age;
    int x364 = ((((int)((unsigned int)(x49 + x51) >> 1)) & 1) * 2) + ((~(((x55 ^ ((int)((unsigned int)(x49 + x51) >> 1))) | (-(x55 ^ ((int)((unsigned int)(x49 + x51) >> 1))))) >> 31)) & 1);
    int x64 = x63[x364];
    int * x65 = x41->cache_age;
    int x66 = x65[x354];
    int * x67 = x41->cache_age;
    int x367 = x66 + ((int)((unsigned int)(x66 - x64) >> 31));
    x67[x354] = x367;
    int * x69 = x41->cache_age;
    int x70 = x69[x356];
    int * x71 = x41->cache_age;
    int x370 = x70 + ((int)((unsigned int)(x70 - x64) >> 31));
    x71[x356] = x370;
    int * x73 = x41->cache_age;
    x73[x364] = 0;
    x175 = x364;
  } else {
    int * x76 = x41->cache_age;
    int x373 = (((int)((unsigned int)(x49 + x51) >> 1)) & 1) * 2;
    int x77 = x76[x373];
    int * x78 = x41->cache_tags;
    int x79 = x78[x373];
    int * x80 = x41->cache_age;
    int x81 = x80[x356];
    int * x82 = x41->cache_tags;
    int x83 = x82[x356];
    bool x377 = !(((~(((x57 ^ ((int)((unsigned int)(x49 + x51) >> 1))) | (-(x57 ^ ((int)((unsigned int)(x49 + x51) >> 1))))) >> 31)) | (~(((x59 ^ ((int)((unsigned int)(x49 + x51) >> 1))) | (-(x59 ^ ((int)((unsigned int)(x49 + x51) >> 1))))) >> 31))) == 0);
    int x147;
    if (x377) {
      int * x84 = x41->cache_age;
      int x379 = (4 + ((((int)((unsigned int)(x49 + x51) >> 1)) & 3) * 2)) + ((~(((x59 ^ ((int)((unsigned int)(x49 + x51) >> 1))) | (-(x59 ^ ((int)((unsigned int)(x49 + x51) >> 1))))) >> 31)) & 1);
      int x85 = x84[x379];
      int * x86 = x41->cache_age;
      int x87 = x86[x358];
      int * x88 = x41->cache_age;
      int x382 = x87 + ((int)((unsigned int)(x87 - x85) >> 31));
      x88[x358] = x382;
      int * x90 = x41->cache_age;
      int x91 = x90[x360];
      int * x92 = x41->cache_age;
      int x385 = x91 + ((int)((unsigned int)(x91 - x85) >> 31));
      x92[x360] = x385;
      int * x94 = x41->cache_age;
      x94[x379] = 0;
      x147 = x379;
    } else {
      int * x97 = x41->cache_age;
      int x388 = 4 + ((((int)((unsigned int)(x49 + x51) >> 1)) & 3) * 2);
      int x98 = x97[x388];
      int * x99 = x41->cache_tags;
      int x100 = x99[x388];
      int * x101 = x41->cache_age;
      int x102 = x101[x360];
      int * x103 = x41->cache_tags;
      int x104 = x103[x360];
      int * x105 = x41->cache_dirty;
      int x393 = (4 + ((((int)((unsigned int)(x49 + x51) >> 1)) & 3) * 2)) + ((((x98 + ((~(((x100 ^ -1) | (-(x100 ^ -1))) >> 31)) & 2)) - (x102 + ((~(((x104 ^ -1) | (-(x104 ^ -1))) >> 31)) & 2))) >> 31) & 1);
      int x106 = x105[x393];
      bool x394 = !(x106 == 0);
      if (x394) {
        int * x107 = x41->cache_tags;
        int x108 = x107[x393];
        int * x109 = x41->cache_vals;
        int x397 = ((4 + ((((int)((unsigned int)(x49 + x51) >> 1)) & 3) * 2)) + ((((x98 + ((~(((x100 ^ -1) | (-(x100 ^ -1))) >> 31)) & 2)) - (x102 + ((~(((x104 ^ -1) | (-(x104 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
        int x110 = x109[x397];
        int * x111 = x41->cache_vals;
        int x399 = (((4 + ((((int)((unsigned int)(x49 + x51) >> 1)) & 3) * 2)) + ((((x98 + ((~(((x100 ^ -1) | (-(x100 ^ -1))) >> 31)) & 2)) - (x102 + ((~(((x104 ^ -1) | (-(x104 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
        int x112 = x111[x399];
        int * x113 = x41->mem;
        int x401 = x108 * 2;
        x113[x401] = x110;
        int * x115 = x41->mem;
        int x404 = (x108 * 2) + 1;
        x115[x404] = x112;
        ;
      } else {
        ;
      }
      int * x120 = x41->mem;
      int x409 = ((int)((unsigned int)(x49 + x51) >> 1)) * 2;
      int x121 = x120[x409];
      int * x122 = x41->mem;
      int x411 = (((int)((unsigned int)(x49 + x51) >> 1)) * 2) + 1;
      int x123 = x122[x411];
      int * x124 = x41->cache_vals;
      int x413 = ((4 + ((((int)((unsigned int)(x49 + x51) >> 1)) & 3) * 2)) + ((((x98 + ((~(((x100 ^ -1) | (-(x100 ^ -1))) >> 31)) & 2)) - (x102 + ((~(((x104 ^ -1) | (-(x104 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
      x124[x413] = x121;
      int * x126 = x41->cache_vals;
      int x416 = (((4 + ((((int)((unsigned int)(x49 + x51) >> 1)) & 3) * 2)) + ((((x98 + ((~(((x100 ^ -1) | (-(x100 ^ -1))) >> 31)) & 2)) - (x102 + ((~(((x104 ^ -1) | (-(x104 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
      x126[x416] = x123;
      int * x128 = x41->cache_tags;
      int x419 = (int)((unsigned int)(x49 + x51) >> 1);
      x128[x393] = x419;
      int * x130 = x41->cache_dirty;
      x130[x393] = 0;
      int * x132 = x41->cache_age;
      x132[x393] = 1;
      int * x134 = x41->cache_age;
      int x135 = x134[x393];
      int * x136 = x41->cache_age;
      int x137 = x136[x358];
      int * x138 = x41->cache_age;
      int x426 = x137 + ((int)((unsigned int)(x137 - x135) >> 31));
      x138[x358] = x426;
      int * x140 = x41->cache_age;
      int x141 = x140[x360];
      int * x142 = x41->cache_age;
      int x429 = x141 + ((int)((unsigned int)(x141 - x135) >> 31));
      x142[x360] = x429;
      int * x144 = x41->cache_age;
      x144[x393] = 0;
      x147 = x393;
    }
    int * x148 = x41->cache_vals;
    int x432 = x147 * 2;
    int x149 = x148[x432];
    int * x150 = x41->cache_vals;
    int x434 = (x147 * 2) + 1;
    int x151 = x150[x434];
    int * x152 = x41->cache_vals;
    int x436 = (((((int)((unsigned int)(x49 + x51) >> 1)) & 1) * 2) + ((((x77 + ((~(((x79 ^ -1) | (-(x79 ^ -1))) >> 31)) & 2)) - (x81 + ((~(((x83 ^ -1) | (-(x83 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
    x152[x436] = x149;
    int * x154 = x41->cache_vals;
    int x439 = ((((((int)((unsigned int)(x49 + x51) >> 1)) & 1) * 2) + ((((x77 + ((~(((x79 ^ -1) | (-(x79 ^ -1))) >> 31)) & 2)) - (x81 + ((~(((x83 ^ -1) | (-(x83 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
    x154[x439] = x151;
    int * x156 = x41->cache_tags;
    int x442 = ((((int)((unsigned int)(x49 + x51) >> 1)) & 1) * 2) + ((((x77 + ((~(((x79 ^ -1) | (-(x79 ^ -1))) >> 31)) & 2)) - (x81 + ((~(((x83 ^ -1) | (-(x83 ^ -1))) >> 31)) & 2))) >> 31) & 1);
    int x443 = (int)((unsigned int)(x49 + x51) >> 1);
    x156[x442] = x443;
    int * x158 = x41->cache_dirty;
    x158[x442] = 0;
    int * x160 = x41->cache_age;
    x160[x442] = 1;
    int * x162 = x41->cache_age;
    int x163 = x162[x442];
    int * x164 = x41->cache_age;
    int x165 = x164[x354];
    int * x166 = x41->cache_age;
    int x450 = x165 + ((int)((unsigned int)(x165 - x163) >> 31));
    x166[x354] = x450;
    int * x168 = x41->cache_age;
    int x169 = x168[x356];
    int * x170 = x41->cache_age;
    int x453 = x169 + ((int)((unsigned int)(x169 - x163) >> 31));
    x170[x356] = x453;
    int * x172 = x41->cache_age;
    x172[x442] = 0;
    x175 = x442;
  }
  int x456 = (x175 * 2) + ((x49 + x51) & 1);
  int x176 = x62[x456];
  int * x177 = x41->regs;
  x177[0] = x176;
  int * x179 = x41->saved_regs;
  int * x180 = x41->regs;
  int x181 = x180[1];
  x179[1] = x181;
  int x183 = x41->timer;
  int x463 = x183 + 1;
  x41->timer = x463;
  int * x185 = x41->regs;
  int x186 = x185[3];
  int * x187 = x41->regs;
  int x188 = x187[4];
  int * x189 = x41->cache_tags;
  int x468 = (((int)((unsigned int)(x186 + x188) >> 1)) & 1) * 2;
  int x190 = x189[x468];
  int * x191 = x41->cache_tags;
  int x470 = ((((int)((unsigned int)(x186 + x188) >> 1)) & 1) * 2) + 1;
  int x192 = x191[x470];
  int * x193 = x41->cache_tags;
  int x472 = 4 + ((((int)((unsigned int)(x186 + x188) >> 1)) & 3) * 2);
  int x194 = x193[x472];
  int * x195 = x41->cache_tags;
  int x474 = (4 + ((((int)((unsigned int)(x186 + x188) >> 1)) & 3) * 2)) + 1;
  int x196 = x195[x474];
  int x197 = x41->timer;
  int x475 = x197 + ((100 ^ (((~(((x194 ^ ((int)((unsigned int)(x186 + x188) >> 1))) | (-(x194 ^ ((int)((unsigned int)(x186 + x188) >> 1))))) >> 31)) | (~(((x196 ^ ((int)((unsigned int)(x186 + x188) >> 1))) | (-(x196 ^ ((int)((unsigned int)(x186 + x188) >> 1))))) >> 31))) & 104)) ^ (((~(((x190 ^ ((int)((unsigned int)(x186 + x188) >> 1))) | (-(x190 ^ ((int)((unsigned int)(x186 + x188) >> 1))))) >> 31)) | (~(((x192 ^ ((int)((unsigned int)(x186 + x188) >> 1))) | (-(x192 ^ ((int)((unsigned int)(x186 + x188) >> 1))))) >> 31))) & (1 ^ (100 ^ (((~(((x194 ^ ((int)((unsigned int)(x186 + x188) >> 1))) | (-(x194 ^ ((int)((unsigned int)(x186 + x188) >> 1))))) >> 31)) | (~(((x196 ^ ((int)((unsigned int)(x186 + x188) >> 1))) | (-(x196 ^ ((int)((unsigned int)(x186 + x188) >> 1))))) >> 31))) & 104)))));
  x41->timer = x475;
  int * x199 = x41->cache_vals;
  bool x476 = !(((~(((x190 ^ ((int)((unsigned int)(x186 + x188) >> 1))) | (-(x190 ^ ((int)((unsigned int)(x186 + x188) >> 1))))) >> 31)) | (~(((x192 ^ ((int)((unsigned int)(x186 + x188) >> 1))) | (-(x192 ^ ((int)((unsigned int)(x186 + x188) >> 1))))) >> 31))) == 0);
  int x312;
  if (x476) {
    int * x200 = x41->cache_age;
    int x478 = ((((int)((unsigned int)(x186 + x188) >> 1)) & 1) * 2) + ((~(((x192 ^ ((int)((unsigned int)(x186 + x188) >> 1))) | (-(x192 ^ ((int)((unsigned int)(x186 + x188) >> 1))))) >> 31)) & 1);
    int x201 = x200[x478];
    int * x202 = x41->cache_age;
    int x203 = x202[x468];
    int * x204 = x41->cache_age;
    int x481 = x203 + ((int)((unsigned int)(x203 - x201) >> 31));
    x204[x468] = x481;
    int * x206 = x41->cache_age;
    int x207 = x206[x470];
    int * x208 = x41->cache_age;
    int x484 = x207 + ((int)((unsigned int)(x207 - x201) >> 31));
    x208[x470] = x484;
    int * x210 = x41->cache_age;
    x210[x478] = 0;
    x312 = x478;
  } else {
    int * x213 = x41->cache_age;
    int x487 = (((int)((unsigned int)(x186 + x188) >> 1)) & 1) * 2;
    int x214 = x213[x487];
    int * x215 = x41->cache_tags;
    int x216 = x215[x487];
    int * x217 = x41->cache_age;
    int x218 = x217[x470];
    int * x219 = x41->cache_tags;
    int x220 = x219[x470];
    bool x491 = !(((~(((x194 ^ ((int)((unsigned int)(x186 + x188) >> 1))) | (-(x194 ^ ((int)((unsigned int)(x186 + x188) >> 1))))) >> 31)) | (~(((x196 ^ ((int)((unsigned int)(x186 + x188) >> 1))) | (-(x196 ^ ((int)((unsigned int)(x186 + x188) >> 1))))) >> 31))) == 0);
    int x284;
    if (x491) {
      int * x221 = x41->cache_age;
      int x493 = (4 + ((((int)((unsigned int)(x186 + x188) >> 1)) & 3) * 2)) + ((~(((x196 ^ ((int)((unsigned int)(x186 + x188) >> 1))) | (-(x196 ^ ((int)((unsigned int)(x186 + x188) >> 1))))) >> 31)) & 1);
      int x222 = x221[x493];
      int * x223 = x41->cache_age;
      int x224 = x223[x472];
      int * x225 = x41->cache_age;
      int x496 = x224 + ((int)((unsigned int)(x224 - x222) >> 31));
      x225[x472] = x496;
      int * x227 = x41->cache_age;
      int x228 = x227[x474];
      int * x229 = x41->cache_age;
      int x499 = x228 + ((int)((unsigned int)(x228 - x222) >> 31));
      x229[x474] = x499;
      int * x231 = x41->cache_age;
      x231[x493] = 0;
      x284 = x493;
    } else {
      int * x234 = x41->cache_age;
      int x502 = 4 + ((((int)((unsigned int)(x186 + x188) >> 1)) & 3) * 2);
      int x235 = x234[x502];
      int * x236 = x41->cache_tags;
      int x237 = x236[x502];
      int * x238 = x41->cache_age;
      int x239 = x238[x474];
      int * x240 = x41->cache_tags;
      int x241 = x240[x474];
      int * x242 = x41->cache_dirty;
      int x507 = (4 + ((((int)((unsigned int)(x186 + x188) >> 1)) & 3) * 2)) + ((((x235 + ((~(((x237 ^ -1) | (-(x237 ^ -1))) >> 31)) & 2)) - (x239 + ((~(((x241 ^ -1) | (-(x241 ^ -1))) >> 31)) & 2))) >> 31) & 1);
      int x243 = x242[x507];
      bool x508 = !(x243 == 0);
      if (x508) {
        int * x244 = x41->cache_tags;
        int x245 = x244[x507];
        int * x246 = x41->cache_vals;
        int x511 = ((4 + ((((int)((unsigned int)(x186 + x188) >> 1)) & 3) * 2)) + ((((x235 + ((~(((x237 ^ -1) | (-(x237 ^ -1))) >> 31)) & 2)) - (x239 + ((~(((x241 ^ -1) | (-(x241 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
        int x247 = x246[x511];
        int * x248 = x41->cache_vals;
        int x513 = (((4 + ((((int)((unsigned int)(x186 + x188) >> 1)) & 3) * 2)) + ((((x235 + ((~(((x237 ^ -1) | (-(x237 ^ -1))) >> 31)) & 2)) - (x239 + ((~(((x241 ^ -1) | (-(x241 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
        int x249 = x248[x513];
        int * x250 = x41->mem;
        int x515 = x245 * 2;
        x250[x515] = x247;
        int * x252 = x41->mem;
        int x518 = (x245 * 2) + 1;
        x252[x518] = x249;
        ;
      } else {
        ;
      }
      int * x257 = x41->mem;
      int x523 = ((int)((unsigned int)(x186 + x188) >> 1)) * 2;
      int x258 = x257[x523];
      int * x259 = x41->mem;
      int x525 = (((int)((unsigned int)(x186 + x188) >> 1)) * 2) + 1;
      int x260 = x259[x525];
      int * x261 = x41->cache_vals;
      int x527 = ((4 + ((((int)((unsigned int)(x186 + x188) >> 1)) & 3) * 2)) + ((((x235 + ((~(((x237 ^ -1) | (-(x237 ^ -1))) >> 31)) & 2)) - (x239 + ((~(((x241 ^ -1) | (-(x241 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
      x261[x527] = x258;
      int * x263 = x41->cache_vals;
      int x530 = (((4 + ((((int)((unsigned int)(x186 + x188) >> 1)) & 3) * 2)) + ((((x235 + ((~(((x237 ^ -1) | (-(x237 ^ -1))) >> 31)) & 2)) - (x239 + ((~(((x241 ^ -1) | (-(x241 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
      x263[x530] = x260;
      int * x265 = x41->cache_tags;
      int x533 = (int)((unsigned int)(x186 + x188) >> 1);
      x265[x507] = x533;
      int * x267 = x41->cache_dirty;
      x267[x507] = 0;
      int * x269 = x41->cache_age;
      x269[x507] = 1;
      int * x271 = x41->cache_age;
      int x272 = x271[x507];
      int * x273 = x41->cache_age;
      int x274 = x273[x472];
      int * x275 = x41->cache_age;
      int x539 = x274 + ((int)((unsigned int)(x274 - x272) >> 31));
      x275[x472] = x539;
      int * x277 = x41->cache_age;
      int x278 = x277[x474];
      int * x279 = x41->cache_age;
      int x542 = x278 + ((int)((unsigned int)(x278 - x272) >> 31));
      x279[x474] = x542;
      int * x281 = x41->cache_age;
      x281[x507] = 0;
      x284 = x507;
    }
    int * x285 = x41->cache_vals;
    int x545 = x284 * 2;
    int x286 = x285[x545];
    int * x287 = x41->cache_vals;
    int x547 = (x284 * 2) + 1;
    int x288 = x287[x547];
    int * x289 = x41->cache_vals;
    int x549 = (((((int)((unsigned int)(x186 + x188) >> 1)) & 1) * 2) + ((((x214 + ((~(((x216 ^ -1) | (-(x216 ^ -1))) >> 31)) & 2)) - (x218 + ((~(((x220 ^ -1) | (-(x220 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
    x289[x549] = x286;
    int * x291 = x41->cache_vals;
    int x552 = ((((((int)((unsigned int)(x186 + x188) >> 1)) & 1) * 2) + ((((x214 + ((~(((x216 ^ -1) | (-(x216 ^ -1))) >> 31)) & 2)) - (x218 + ((~(((x220 ^ -1) | (-(x220 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
    x291[x552] = x288;
    int * x293 = x41->cache_tags;
    int x555 = ((((int)((unsigned int)(x186 + x188) >> 1)) & 1) * 2) + ((((x214 + ((~(((x216 ^ -1) | (-(x216 ^ -1))) >> 31)) & 2)) - (x218 + ((~(((x220 ^ -1) | (-(x220 ^ -1))) >> 31)) & 2))) >> 31) & 1);
    int x556 = (int)((unsigned int)(x186 + x188) >> 1);
    x293[x555] = x556;
    int * x295 = x41->cache_dirty;
    x295[x555] = 0;
    int * x297 = x41->cache_age;
    x297[x555] = 1;
    int * x299 = x41->cache_age;
    int x300 = x299[x555];
    int * x301 = x41->cache_age;
    int x302 = x301[x468];
    int * x303 = x41->cache_age;
    int x562 = x302 + ((int)((unsigned int)(x302 - x300) >> 31));
    x303[x468] = x562;
    int * x305 = x41->cache_age;
    int x306 = x305[x470];
    int * x307 = x41->cache_age;
    int x565 = x306 + ((int)((unsigned int)(x306 - x300) >> 31));
    x307[x470] = x565;
    int * x309 = x41->cache_age;
    x309[x555] = 0;
    x312 = x555;
  }
  int x568 = (x312 * 2) + ((x186 + x188) & 1);
  int x313 = x199[x568];
  int * x314 = x41->regs;
  x314[1] = x313;
  int * x316 = x41->regs;
  int x317 = x316[4];
  bool x572 = x317 >= 4;
  struct StateT * x342;
  if (x572) {
    int x318 = x41->timer;
    int x573 = x318 + 15;
    x41->timer = x573;
    int * x320 = x41->saved_regs;
    int x321 = x320[0];
    int * x322 = x41->regs;
    x322[0] = x321;
    int * x324 = x41->saved_regs;
    int x325 = x324[1];
    int * x326 = x41->regs;
    x326[1] = x325;
    struct StateT * x328 = slot_11(x41);
    x342 = x328;
  } else {
    int x330 = x41->timer;
    int x582 = x330 + 1;
    x41->timer = x582;
    int * x332 = x41->regs;
    int x333 = x332[0];
    int * x334 = x41->regs;
    int x335 = x334[1];
    bool x585 = !(x333 == x335);
    struct StateT * x340;
    if (x585) {
      struct StateT * x336 = slot_9(x41);
      x340 = x336;
    } else {
      struct StateT * x338 = slot_7(x41);
      x340 = x338;
    }
    x342 = x340;
  }
  return x342;
}

struct StateT * slot_11(struct StateT * x592) {
  int x593 = x592->timer;
  int x598 = x593 + 1;
  x592->timer = x598;
  int * x595 = x592->regs;
  x595[0] = 1;
  return x592;
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