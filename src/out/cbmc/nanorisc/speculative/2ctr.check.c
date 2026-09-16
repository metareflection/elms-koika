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
  int reg_ready[8];
  int cache_tags[12];
  int cache_dirty[12];
  int cache_age[12];
  int cache_vals[24];
  int timer;
};

struct StateT * snippet(struct StateT * x0);
struct StateT * slot_0(struct StateT * x2);
struct StateT * snippet(struct StateT * x0) {
  struct StateT * x1 = slot_0(x0);
  return x1;
}

struct StateT * slot_0(struct StateT * x2) {
  int * x3 = x2->saved_regs;
  int * x4 = x2->regs;
  int x5 = x4[1];
  x3[1] = x5;
  int x7 = x2->timer;
  int x293 = x7 + 1;
  x2->timer = x293;
  int * x9 = x2->regs;
  int x10 = x9[0];
  int * x11 = x2->cache_tags;
  int x297 = (((int)((unsigned int)x10 >> 1)) & 1) * 2;
  int x12 = x11[x297];
  int * x13 = x2->cache_tags;
  int x299 = ((((int)((unsigned int)x10 >> 1)) & 1) * 2) + 1;
  int x14 = x13[x299];
  int * x15 = x2->cache_tags;
  int x301 = 4 + ((((int)((unsigned int)x10 >> 1)) & 3) * 2);
  int x16 = x15[x301];
  int * x17 = x2->cache_tags;
  int x303 = (4 + ((((int)((unsigned int)x10 >> 1)) & 3) * 2)) + 1;
  int x18 = x17[x303];
  int x19 = x2->timer;
  int x304 = x19 + ((100 ^ (((~(((x16 ^ ((int)((unsigned int)x10 >> 1))) | (-(x16 ^ ((int)((unsigned int)x10 >> 1))))) >> 31)) | (~(((x18 ^ ((int)((unsigned int)x10 >> 1))) | (-(x18 ^ ((int)((unsigned int)x10 >> 1))))) >> 31))) & 104)) ^ (((~(((x12 ^ ((int)((unsigned int)x10 >> 1))) | (-(x12 ^ ((int)((unsigned int)x10 >> 1))))) >> 31)) | (~(((x14 ^ ((int)((unsigned int)x10 >> 1))) | (-(x14 ^ ((int)((unsigned int)x10 >> 1))))) >> 31))) & (1 ^ (100 ^ (((~(((x16 ^ ((int)((unsigned int)x10 >> 1))) | (-(x16 ^ ((int)((unsigned int)x10 >> 1))))) >> 31)) | (~(((x18 ^ ((int)((unsigned int)x10 >> 1))) | (-(x18 ^ ((int)((unsigned int)x10 >> 1))))) >> 31))) & 104)))));
  x2->timer = x304;
  int * x21 = x2->cache_vals;
  bool x305 = !(((~(((x12 ^ ((int)((unsigned int)x10 >> 1))) | (-(x12 ^ ((int)((unsigned int)x10 >> 1))))) >> 31)) | (~(((x14 ^ ((int)((unsigned int)x10 >> 1))) | (-(x14 ^ ((int)((unsigned int)x10 >> 1))))) >> 31))) == 0);
  int x134;
  if (x305) {
    int * x22 = x2->cache_age;
    int x307 = ((((int)((unsigned int)x10 >> 1)) & 1) * 2) + ((~(((x14 ^ ((int)((unsigned int)x10 >> 1))) | (-(x14 ^ ((int)((unsigned int)x10 >> 1))))) >> 31)) & 1);
    int x23 = x22[x307];
    int * x24 = x2->cache_age;
    int x25 = x24[x297];
    int * x26 = x2->cache_age;
    int x310 = x25 + ((int)((unsigned int)(x25 - x23) >> 31));
    x26[x297] = x310;
    int * x28 = x2->cache_age;
    int x29 = x28[x299];
    int * x30 = x2->cache_age;
    int x313 = x29 + ((int)((unsigned int)(x29 - x23) >> 31));
    x30[x299] = x313;
    int * x32 = x2->cache_age;
    x32[x307] = 0;
    x134 = x307;
  } else {
    int * x35 = x2->cache_age;
    int x316 = (((int)((unsigned int)x10 >> 1)) & 1) * 2;
    int x36 = x35[x316];
    int * x37 = x2->cache_tags;
    int x38 = x37[x316];
    int * x39 = x2->cache_age;
    int x40 = x39[x299];
    int * x41 = x2->cache_tags;
    int x42 = x41[x299];
    bool x320 = !(((~(((x16 ^ ((int)((unsigned int)x10 >> 1))) | (-(x16 ^ ((int)((unsigned int)x10 >> 1))))) >> 31)) | (~(((x18 ^ ((int)((unsigned int)x10 >> 1))) | (-(x18 ^ ((int)((unsigned int)x10 >> 1))))) >> 31))) == 0);
    int x106;
    if (x320) {
      int * x43 = x2->cache_age;
      int x322 = (4 + ((((int)((unsigned int)x10 >> 1)) & 3) * 2)) + ((~(((x18 ^ ((int)((unsigned int)x10 >> 1))) | (-(x18 ^ ((int)((unsigned int)x10 >> 1))))) >> 31)) & 1);
      int x44 = x43[x322];
      int * x45 = x2->cache_age;
      int x46 = x45[x301];
      int * x47 = x2->cache_age;
      int x325 = x46 + ((int)((unsigned int)(x46 - x44) >> 31));
      x47[x301] = x325;
      int * x49 = x2->cache_age;
      int x50 = x49[x303];
      int * x51 = x2->cache_age;
      int x328 = x50 + ((int)((unsigned int)(x50 - x44) >> 31));
      x51[x303] = x328;
      int * x53 = x2->cache_age;
      x53[x322] = 0;
      x106 = x322;
    } else {
      int * x56 = x2->cache_age;
      int x331 = 4 + ((((int)((unsigned int)x10 >> 1)) & 3) * 2);
      int x57 = x56[x331];
      int * x58 = x2->cache_tags;
      int x59 = x58[x331];
      int * x60 = x2->cache_age;
      int x61 = x60[x303];
      int * x62 = x2->cache_tags;
      int x63 = x62[x303];
      int * x64 = x2->cache_dirty;
      int x336 = (4 + ((((int)((unsigned int)x10 >> 1)) & 3) * 2)) + ((((x57 + ((~(((x59 ^ -1) | (-(x59 ^ -1))) >> 31)) & 2)) - (x61 + ((~(((x63 ^ -1) | (-(x63 ^ -1))) >> 31)) & 2))) >> 31) & 1);
      int x65 = x64[x336];
      bool x337 = !(x65 == 0);
      if (x337) {
        int * x66 = x2->cache_tags;
        int x67 = x66[x336];
        int * x68 = x2->cache_vals;
        int x340 = ((4 + ((((int)((unsigned int)x10 >> 1)) & 3) * 2)) + ((((x57 + ((~(((x59 ^ -1) | (-(x59 ^ -1))) >> 31)) & 2)) - (x61 + ((~(((x63 ^ -1) | (-(x63 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
        int x69 = x68[x340];
        int * x70 = x2->cache_vals;
        int x342 = (((4 + ((((int)((unsigned int)x10 >> 1)) & 3) * 2)) + ((((x57 + ((~(((x59 ^ -1) | (-(x59 ^ -1))) >> 31)) & 2)) - (x61 + ((~(((x63 ^ -1) | (-(x63 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
        int x71 = x70[x342];
        int * x72 = x2->mem;
        int x344 = x67 * 2;
        x72[x344] = x69;
        int * x74 = x2->mem;
        int x347 = (x67 * 2) + 1;
        x74[x347] = x71;
        ;
      } else {
        ;
      }
      int * x79 = x2->mem;
      int x352 = ((int)((unsigned int)x10 >> 1)) * 2;
      int x80 = x79[x352];
      int * x81 = x2->mem;
      int x354 = (((int)((unsigned int)x10 >> 1)) * 2) + 1;
      int x82 = x81[x354];
      int * x83 = x2->cache_vals;
      int x356 = ((4 + ((((int)((unsigned int)x10 >> 1)) & 3) * 2)) + ((((x57 + ((~(((x59 ^ -1) | (-(x59 ^ -1))) >> 31)) & 2)) - (x61 + ((~(((x63 ^ -1) | (-(x63 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
      x83[x356] = x80;
      int * x85 = x2->cache_vals;
      int x359 = (((4 + ((((int)((unsigned int)x10 >> 1)) & 3) * 2)) + ((((x57 + ((~(((x59 ^ -1) | (-(x59 ^ -1))) >> 31)) & 2)) - (x61 + ((~(((x63 ^ -1) | (-(x63 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
      x85[x359] = x82;
      int * x87 = x2->cache_tags;
      int x362 = (int)((unsigned int)x10 >> 1);
      x87[x336] = x362;
      int * x89 = x2->cache_dirty;
      x89[x336] = 0;
      int * x91 = x2->cache_age;
      x91[x336] = 1;
      int * x93 = x2->cache_age;
      int x94 = x93[x336];
      int * x95 = x2->cache_age;
      int x96 = x95[x301];
      int * x97 = x2->cache_age;
      int x368 = x96 + ((int)((unsigned int)(x96 - x94) >> 31));
      x97[x301] = x368;
      int * x99 = x2->cache_age;
      int x100 = x99[x303];
      int * x101 = x2->cache_age;
      int x371 = x100 + ((int)((unsigned int)(x100 - x94) >> 31));
      x101[x303] = x371;
      int * x103 = x2->cache_age;
      x103[x336] = 0;
      x106 = x336;
    }
    int * x107 = x2->cache_vals;
    int x374 = x106 * 2;
    int x108 = x107[x374];
    int * x109 = x2->cache_vals;
    int x376 = (x106 * 2) + 1;
    int x110 = x109[x376];
    int * x111 = x2->cache_vals;
    int x378 = (((((int)((unsigned int)x10 >> 1)) & 1) * 2) + ((((x36 + ((~(((x38 ^ -1) | (-(x38 ^ -1))) >> 31)) & 2)) - (x40 + ((~(((x42 ^ -1) | (-(x42 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
    x111[x378] = x108;
    int * x113 = x2->cache_vals;
    int x381 = ((((((int)((unsigned int)x10 >> 1)) & 1) * 2) + ((((x36 + ((~(((x38 ^ -1) | (-(x38 ^ -1))) >> 31)) & 2)) - (x40 + ((~(((x42 ^ -1) | (-(x42 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
    x113[x381] = x110;
    int * x115 = x2->cache_tags;
    int x384 = ((((int)((unsigned int)x10 >> 1)) & 1) * 2) + ((((x36 + ((~(((x38 ^ -1) | (-(x38 ^ -1))) >> 31)) & 2)) - (x40 + ((~(((x42 ^ -1) | (-(x42 ^ -1))) >> 31)) & 2))) >> 31) & 1);
    int x385 = (int)((unsigned int)x10 >> 1);
    x115[x384] = x385;
    int * x117 = x2->cache_dirty;
    x117[x384] = 0;
    int * x119 = x2->cache_age;
    x119[x384] = 1;
    int * x121 = x2->cache_age;
    int x122 = x121[x384];
    int * x123 = x2->cache_age;
    int x124 = x123[x297];
    int * x125 = x2->cache_age;
    int x391 = x124 + ((int)((unsigned int)(x124 - x122) >> 31));
    x125[x297] = x391;
    int * x127 = x2->cache_age;
    int x128 = x127[x299];
    int * x129 = x2->cache_age;
    int x394 = x128 + ((int)((unsigned int)(x128 - x122) >> 31));
    x129[x299] = x394;
    int * x131 = x2->cache_age;
    x131[x384] = 0;
    x134 = x384;
  }
  int x397 = (x134 * 2) + (x10 & 1);
  int x135 = x21[x397];
  int * x136 = x2->regs;
  x136[1] = x135;
  int * x138 = x2->saved_regs;
  int * x139 = x2->regs;
  int x140 = x139[2];
  x138[2] = x140;
  int x142 = x2->timer;
  int x404 = x142 + 1;
  x2->timer = x404;
  int * x144 = x2->regs;
  int x145 = x144[1];
  int * x146 = x2->cache_tags;
  int x407 = (((int)((unsigned int)(x145 + 4) >> 1)) & 1) * 2;
  int x147 = x146[x407];
  int * x148 = x2->cache_tags;
  int x409 = ((((int)((unsigned int)(x145 + 4) >> 1)) & 1) * 2) + 1;
  int x149 = x148[x409];
  int * x150 = x2->cache_tags;
  int x411 = 4 + ((((int)((unsigned int)(x145 + 4) >> 1)) & 3) * 2);
  int x151 = x150[x411];
  int * x152 = x2->cache_tags;
  int x413 = (4 + ((((int)((unsigned int)(x145 + 4) >> 1)) & 3) * 2)) + 1;
  int x153 = x152[x413];
  int x154 = x2->timer;
  int x414 = x154 + ((100 ^ (((~(((x151 ^ ((int)((unsigned int)(x145 + 4) >> 1))) | (-(x151 ^ ((int)((unsigned int)(x145 + 4) >> 1))))) >> 31)) | (~(((x153 ^ ((int)((unsigned int)(x145 + 4) >> 1))) | (-(x153 ^ ((int)((unsigned int)(x145 + 4) >> 1))))) >> 31))) & 104)) ^ (((~(((x147 ^ ((int)((unsigned int)(x145 + 4) >> 1))) | (-(x147 ^ ((int)((unsigned int)(x145 + 4) >> 1))))) >> 31)) | (~(((x149 ^ ((int)((unsigned int)(x145 + 4) >> 1))) | (-(x149 ^ ((int)((unsigned int)(x145 + 4) >> 1))))) >> 31))) & (1 ^ (100 ^ (((~(((x151 ^ ((int)((unsigned int)(x145 + 4) >> 1))) | (-(x151 ^ ((int)((unsigned int)(x145 + 4) >> 1))))) >> 31)) | (~(((x153 ^ ((int)((unsigned int)(x145 + 4) >> 1))) | (-(x153 ^ ((int)((unsigned int)(x145 + 4) >> 1))))) >> 31))) & 104)))));
  x2->timer = x414;
  int * x156 = x2->cache_vals;
  bool x415 = !(((~(((x147 ^ ((int)((unsigned int)(x145 + 4) >> 1))) | (-(x147 ^ ((int)((unsigned int)(x145 + 4) >> 1))))) >> 31)) | (~(((x149 ^ ((int)((unsigned int)(x145 + 4) >> 1))) | (-(x149 ^ ((int)((unsigned int)(x145 + 4) >> 1))))) >> 31))) == 0);
  int x269;
  if (x415) {
    int * x157 = x2->cache_age;
    int x417 = ((((int)((unsigned int)(x145 + 4) >> 1)) & 1) * 2) + ((~(((x149 ^ ((int)((unsigned int)(x145 + 4) >> 1))) | (-(x149 ^ ((int)((unsigned int)(x145 + 4) >> 1))))) >> 31)) & 1);
    int x158 = x157[x417];
    int * x159 = x2->cache_age;
    int x160 = x159[x407];
    int * x161 = x2->cache_age;
    int x420 = x160 + ((int)((unsigned int)(x160 - x158) >> 31));
    x161[x407] = x420;
    int * x163 = x2->cache_age;
    int x164 = x163[x409];
    int * x165 = x2->cache_age;
    int x423 = x164 + ((int)((unsigned int)(x164 - x158) >> 31));
    x165[x409] = x423;
    int * x167 = x2->cache_age;
    x167[x417] = 0;
    x269 = x417;
  } else {
    int * x170 = x2->cache_age;
    int x426 = (((int)((unsigned int)(x145 + 4) >> 1)) & 1) * 2;
    int x171 = x170[x426];
    int * x172 = x2->cache_tags;
    int x173 = x172[x426];
    int * x174 = x2->cache_age;
    int x175 = x174[x409];
    int * x176 = x2->cache_tags;
    int x177 = x176[x409];
    bool x430 = !(((~(((x151 ^ ((int)((unsigned int)(x145 + 4) >> 1))) | (-(x151 ^ ((int)((unsigned int)(x145 + 4) >> 1))))) >> 31)) | (~(((x153 ^ ((int)((unsigned int)(x145 + 4) >> 1))) | (-(x153 ^ ((int)((unsigned int)(x145 + 4) >> 1))))) >> 31))) == 0);
    int x241;
    if (x430) {
      int * x178 = x2->cache_age;
      int x432 = (4 + ((((int)((unsigned int)(x145 + 4) >> 1)) & 3) * 2)) + ((~(((x153 ^ ((int)((unsigned int)(x145 + 4) >> 1))) | (-(x153 ^ ((int)((unsigned int)(x145 + 4) >> 1))))) >> 31)) & 1);
      int x179 = x178[x432];
      int * x180 = x2->cache_age;
      int x181 = x180[x411];
      int * x182 = x2->cache_age;
      int x435 = x181 + ((int)((unsigned int)(x181 - x179) >> 31));
      x182[x411] = x435;
      int * x184 = x2->cache_age;
      int x185 = x184[x413];
      int * x186 = x2->cache_age;
      int x438 = x185 + ((int)((unsigned int)(x185 - x179) >> 31));
      x186[x413] = x438;
      int * x188 = x2->cache_age;
      x188[x432] = 0;
      x241 = x432;
    } else {
      int * x191 = x2->cache_age;
      int x441 = 4 + ((((int)((unsigned int)(x145 + 4) >> 1)) & 3) * 2);
      int x192 = x191[x441];
      int * x193 = x2->cache_tags;
      int x194 = x193[x441];
      int * x195 = x2->cache_age;
      int x196 = x195[x413];
      int * x197 = x2->cache_tags;
      int x198 = x197[x413];
      int * x199 = x2->cache_dirty;
      int x446 = (4 + ((((int)((unsigned int)(x145 + 4) >> 1)) & 3) * 2)) + ((((x192 + ((~(((x194 ^ -1) | (-(x194 ^ -1))) >> 31)) & 2)) - (x196 + ((~(((x198 ^ -1) | (-(x198 ^ -1))) >> 31)) & 2))) >> 31) & 1);
      int x200 = x199[x446];
      bool x447 = !(x200 == 0);
      if (x447) {
        int * x201 = x2->cache_tags;
        int x202 = x201[x446];
        int * x203 = x2->cache_vals;
        int x450 = ((4 + ((((int)((unsigned int)(x145 + 4) >> 1)) & 3) * 2)) + ((((x192 + ((~(((x194 ^ -1) | (-(x194 ^ -1))) >> 31)) & 2)) - (x196 + ((~(((x198 ^ -1) | (-(x198 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
        int x204 = x203[x450];
        int * x205 = x2->cache_vals;
        int x452 = (((4 + ((((int)((unsigned int)(x145 + 4) >> 1)) & 3) * 2)) + ((((x192 + ((~(((x194 ^ -1) | (-(x194 ^ -1))) >> 31)) & 2)) - (x196 + ((~(((x198 ^ -1) | (-(x198 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
        int x206 = x205[x452];
        int * x207 = x2->mem;
        int x454 = x202 * 2;
        x207[x454] = x204;
        int * x209 = x2->mem;
        int x457 = (x202 * 2) + 1;
        x209[x457] = x206;
        ;
      } else {
        ;
      }
      int * x214 = x2->mem;
      int x462 = ((int)((unsigned int)(x145 + 4) >> 1)) * 2;
      int x215 = x214[x462];
      int * x216 = x2->mem;
      int x464 = (((int)((unsigned int)(x145 + 4) >> 1)) * 2) + 1;
      int x217 = x216[x464];
      int * x218 = x2->cache_vals;
      int x466 = ((4 + ((((int)((unsigned int)(x145 + 4) >> 1)) & 3) * 2)) + ((((x192 + ((~(((x194 ^ -1) | (-(x194 ^ -1))) >> 31)) & 2)) - (x196 + ((~(((x198 ^ -1) | (-(x198 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
      x218[x466] = x215;
      int * x220 = x2->cache_vals;
      int x469 = (((4 + ((((int)((unsigned int)(x145 + 4) >> 1)) & 3) * 2)) + ((((x192 + ((~(((x194 ^ -1) | (-(x194 ^ -1))) >> 31)) & 2)) - (x196 + ((~(((x198 ^ -1) | (-(x198 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
      x220[x469] = x217;
      int * x222 = x2->cache_tags;
      int x472 = (int)((unsigned int)(x145 + 4) >> 1);
      x222[x446] = x472;
      int * x224 = x2->cache_dirty;
      x224[x446] = 0;
      int * x226 = x2->cache_age;
      x226[x446] = 1;
      int * x228 = x2->cache_age;
      int x229 = x228[x446];
      int * x230 = x2->cache_age;
      int x231 = x230[x411];
      int * x232 = x2->cache_age;
      int x478 = x231 + ((int)((unsigned int)(x231 - x229) >> 31));
      x232[x411] = x478;
      int * x234 = x2->cache_age;
      int x235 = x234[x413];
      int * x236 = x2->cache_age;
      int x481 = x235 + ((int)((unsigned int)(x235 - x229) >> 31));
      x236[x413] = x481;
      int * x238 = x2->cache_age;
      x238[x446] = 0;
      x241 = x446;
    }
    int * x242 = x2->cache_vals;
    int x484 = x241 * 2;
    int x243 = x242[x484];
    int * x244 = x2->cache_vals;
    int x486 = (x241 * 2) + 1;
    int x245 = x244[x486];
    int * x246 = x2->cache_vals;
    int x488 = (((((int)((unsigned int)(x145 + 4) >> 1)) & 1) * 2) + ((((x171 + ((~(((x173 ^ -1) | (-(x173 ^ -1))) >> 31)) & 2)) - (x175 + ((~(((x177 ^ -1) | (-(x177 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
    x246[x488] = x243;
    int * x248 = x2->cache_vals;
    int x491 = ((((((int)((unsigned int)(x145 + 4) >> 1)) & 1) * 2) + ((((x171 + ((~(((x173 ^ -1) | (-(x173 ^ -1))) >> 31)) & 2)) - (x175 + ((~(((x177 ^ -1) | (-(x177 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
    x248[x491] = x245;
    int * x250 = x2->cache_tags;
    int x494 = ((((int)((unsigned int)(x145 + 4) >> 1)) & 1) * 2) + ((((x171 + ((~(((x173 ^ -1) | (-(x173 ^ -1))) >> 31)) & 2)) - (x175 + ((~(((x177 ^ -1) | (-(x177 ^ -1))) >> 31)) & 2))) >> 31) & 1);
    int x495 = (int)((unsigned int)(x145 + 4) >> 1);
    x250[x494] = x495;
    int * x252 = x2->cache_dirty;
    x252[x494] = 0;
    int * x254 = x2->cache_age;
    x254[x494] = 1;
    int * x256 = x2->cache_age;
    int x257 = x256[x494];
    int * x258 = x2->cache_age;
    int x259 = x258[x407];
    int * x260 = x2->cache_age;
    int x501 = x259 + ((int)((unsigned int)(x259 - x257) >> 31));
    x260[x407] = x501;
    int * x262 = x2->cache_age;
    int x263 = x262[x409];
    int * x264 = x2->cache_age;
    int x504 = x263 + ((int)((unsigned int)(x263 - x257) >> 31));
    x264[x409] = x504;
    int * x266 = x2->cache_age;
    x266[x494] = 0;
    x269 = x494;
  }
  int x507 = (x269 * 2) + ((x145 + 4) & 1);
  int x270 = x156[x507];
  int * x271 = x2->regs;
  x271[2] = x270;
  int * x273 = x2->regs;
  int x274 = x273[0];
  bool x511 = x274 == 0;
  if (x511) {
    int x275 = x2->timer;
    int x512 = x275 + 15;
    x2->timer = x512;
    int * x277 = x2->saved_regs;
    int x278 = x277[1];
    int * x279 = x2->regs;
    x279[1] = x278;
    int * x281 = x2->saved_regs;
    int x282 = x281[2];
    int * x283 = x2->regs;
    x283[2] = x282;
    ;
  } else {
    ;
  }
  return x2;
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