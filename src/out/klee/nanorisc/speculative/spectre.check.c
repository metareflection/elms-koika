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

struct StateT * snippet(struct StateT * x0);
struct StateT * slot_1(struct StateT * x15);
struct StateT * slot_2(struct StateT * x28);
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

struct StateT * slot_2(struct StateT * x28) {
  int * x29 = x28->saved_regs;
  int * x30 = x28->regs;
  int x31 = x30[1];
  x29[1] = x31;
  int x33 = x28->timer;
  int x321 = x33 + 1;
  x28->timer = x321;
  int * x35 = x28->regs;
  int x36 = x35[3];
  int * x37 = x28->regs;
  int x38 = x37[0];
  int * x39 = x28->cache_tags;
  int x327 = (((int)((unsigned int)(x36 + x38) >> 1)) & 1) * 2;
  int x40 = x39[x327];
  int * x41 = x28->cache_tags;
  int x329 = ((((int)((unsigned int)(x36 + x38) >> 1)) & 1) * 2) + 1;
  int x42 = x41[x329];
  int * x43 = x28->cache_tags;
  int x331 = 4 + ((((int)((unsigned int)(x36 + x38) >> 1)) & 3) * 2);
  int x44 = x43[x331];
  int * x45 = x28->cache_tags;
  int x333 = (4 + ((((int)((unsigned int)(x36 + x38) >> 1)) & 3) * 2)) + 1;
  int x46 = x45[x333];
  int x47 = x28->timer;
  int x334 = x47 + ((100 ^ (((~(((x44 ^ ((int)((unsigned int)(x36 + x38) >> 1))) | (-(x44 ^ ((int)((unsigned int)(x36 + x38) >> 1))))) >> 31)) | (~(((x46 ^ ((int)((unsigned int)(x36 + x38) >> 1))) | (-(x46 ^ ((int)((unsigned int)(x36 + x38) >> 1))))) >> 31))) & 104)) ^ (((~(((x40 ^ ((int)((unsigned int)(x36 + x38) >> 1))) | (-(x40 ^ ((int)((unsigned int)(x36 + x38) >> 1))))) >> 31)) | (~(((x42 ^ ((int)((unsigned int)(x36 + x38) >> 1))) | (-(x42 ^ ((int)((unsigned int)(x36 + x38) >> 1))))) >> 31))) & (1 ^ (100 ^ (((~(((x44 ^ ((int)((unsigned int)(x36 + x38) >> 1))) | (-(x44 ^ ((int)((unsigned int)(x36 + x38) >> 1))))) >> 31)) | (~(((x46 ^ ((int)((unsigned int)(x36 + x38) >> 1))) | (-(x46 ^ ((int)((unsigned int)(x36 + x38) >> 1))))) >> 31))) & 104)))));
  x28->timer = x334;
  int * x49 = x28->cache_vals;
  bool x335 = !(((~(((x40 ^ ((int)((unsigned int)(x36 + x38) >> 1))) | (-(x40 ^ ((int)((unsigned int)(x36 + x38) >> 1))))) >> 31)) | (~(((x42 ^ ((int)((unsigned int)(x36 + x38) >> 1))) | (-(x42 ^ ((int)((unsigned int)(x36 + x38) >> 1))))) >> 31))) == 0);
  int x162;
  if (x335) {
    int * x50 = x28->cache_age;
    int x337 = ((((int)((unsigned int)(x36 + x38) >> 1)) & 1) * 2) + ((~(((x42 ^ ((int)((unsigned int)(x36 + x38) >> 1))) | (-(x42 ^ ((int)((unsigned int)(x36 + x38) >> 1))))) >> 31)) & 1);
    int x51 = x50[x337];
    int * x52 = x28->cache_age;
    int x53 = x52[x327];
    int * x54 = x28->cache_age;
    int x340 = x53 + ((int)((unsigned int)(x53 - x51) >> 31));
    x54[x327] = x340;
    int * x56 = x28->cache_age;
    int x57 = x56[x329];
    int * x58 = x28->cache_age;
    int x343 = x57 + ((int)((unsigned int)(x57 - x51) >> 31));
    x58[x329] = x343;
    int * x60 = x28->cache_age;
    x60[x337] = 0;
    x162 = x337;
  } else {
    int * x63 = x28->cache_age;
    int x346 = (((int)((unsigned int)(x36 + x38) >> 1)) & 1) * 2;
    int x64 = x63[x346];
    int * x65 = x28->cache_tags;
    int x66 = x65[x346];
    int * x67 = x28->cache_age;
    int x68 = x67[x329];
    int * x69 = x28->cache_tags;
    int x70 = x69[x329];
    bool x350 = !(((~(((x44 ^ ((int)((unsigned int)(x36 + x38) >> 1))) | (-(x44 ^ ((int)((unsigned int)(x36 + x38) >> 1))))) >> 31)) | (~(((x46 ^ ((int)((unsigned int)(x36 + x38) >> 1))) | (-(x46 ^ ((int)((unsigned int)(x36 + x38) >> 1))))) >> 31))) == 0);
    int x134;
    if (x350) {
      int * x71 = x28->cache_age;
      int x352 = (4 + ((((int)((unsigned int)(x36 + x38) >> 1)) & 3) * 2)) + ((~(((x46 ^ ((int)((unsigned int)(x36 + x38) >> 1))) | (-(x46 ^ ((int)((unsigned int)(x36 + x38) >> 1))))) >> 31)) & 1);
      int x72 = x71[x352];
      int * x73 = x28->cache_age;
      int x74 = x73[x331];
      int * x75 = x28->cache_age;
      int x355 = x74 + ((int)((unsigned int)(x74 - x72) >> 31));
      x75[x331] = x355;
      int * x77 = x28->cache_age;
      int x78 = x77[x333];
      int * x79 = x28->cache_age;
      int x358 = x78 + ((int)((unsigned int)(x78 - x72) >> 31));
      x79[x333] = x358;
      int * x81 = x28->cache_age;
      x81[x352] = 0;
      x134 = x352;
    } else {
      int * x84 = x28->cache_age;
      int x361 = 4 + ((((int)((unsigned int)(x36 + x38) >> 1)) & 3) * 2);
      int x85 = x84[x361];
      int * x86 = x28->cache_tags;
      int x87 = x86[x361];
      int * x88 = x28->cache_age;
      int x89 = x88[x333];
      int * x90 = x28->cache_tags;
      int x91 = x90[x333];
      int * x92 = x28->cache_dirty;
      int x366 = (4 + ((((int)((unsigned int)(x36 + x38) >> 1)) & 3) * 2)) + ((((x85 + ((~(((x87 ^ -1) | (-(x87 ^ -1))) >> 31)) & 2)) - (x89 + ((~(((x91 ^ -1) | (-(x91 ^ -1))) >> 31)) & 2))) >> 31) & 1);
      int x93 = x92[x366];
      bool x367 = !(x93 == 0);
      if (x367) {
        int * x94 = x28->cache_tags;
        int x95 = x94[x366];
        int * x96 = x28->cache_vals;
        int x370 = ((4 + ((((int)((unsigned int)(x36 + x38) >> 1)) & 3) * 2)) + ((((x85 + ((~(((x87 ^ -1) | (-(x87 ^ -1))) >> 31)) & 2)) - (x89 + ((~(((x91 ^ -1) | (-(x91 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
        int x97 = x96[x370];
        int * x98 = x28->cache_vals;
        int x372 = (((4 + ((((int)((unsigned int)(x36 + x38) >> 1)) & 3) * 2)) + ((((x85 + ((~(((x87 ^ -1) | (-(x87 ^ -1))) >> 31)) & 2)) - (x89 + ((~(((x91 ^ -1) | (-(x91 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
        int x99 = x98[x372];
        int * x100 = x28->mem;
        int x374 = x95 * 2;
        x100[x374] = x97;
        int * x102 = x28->mem;
        int x377 = (x95 * 2) + 1;
        x102[x377] = x99;
        ;
      } else {
        ;
      }
      int * x107 = x28->mem;
      int x382 = ((int)((unsigned int)(x36 + x38) >> 1)) * 2;
      int x108 = x107[x382];
      int * x109 = x28->mem;
      int x384 = (((int)((unsigned int)(x36 + x38) >> 1)) * 2) + 1;
      int x110 = x109[x384];
      int * x111 = x28->cache_vals;
      int x386 = ((4 + ((((int)((unsigned int)(x36 + x38) >> 1)) & 3) * 2)) + ((((x85 + ((~(((x87 ^ -1) | (-(x87 ^ -1))) >> 31)) & 2)) - (x89 + ((~(((x91 ^ -1) | (-(x91 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
      x111[x386] = x108;
      int * x113 = x28->cache_vals;
      int x389 = (((4 + ((((int)((unsigned int)(x36 + x38) >> 1)) & 3) * 2)) + ((((x85 + ((~(((x87 ^ -1) | (-(x87 ^ -1))) >> 31)) & 2)) - (x89 + ((~(((x91 ^ -1) | (-(x91 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
      x113[x389] = x110;
      int * x115 = x28->cache_tags;
      int x392 = (int)((unsigned int)(x36 + x38) >> 1);
      x115[x366] = x392;
      int * x117 = x28->cache_dirty;
      x117[x366] = 0;
      int * x119 = x28->cache_age;
      x119[x366] = 1;
      int * x121 = x28->cache_age;
      int x122 = x121[x366];
      int * x123 = x28->cache_age;
      int x124 = x123[x331];
      int * x125 = x28->cache_age;
      int x398 = x124 + ((int)((unsigned int)(x124 - x122) >> 31));
      x125[x331] = x398;
      int * x127 = x28->cache_age;
      int x128 = x127[x333];
      int * x129 = x28->cache_age;
      int x401 = x128 + ((int)((unsigned int)(x128 - x122) >> 31));
      x129[x333] = x401;
      int * x131 = x28->cache_age;
      x131[x366] = 0;
      x134 = x366;
    }
    int * x135 = x28->cache_vals;
    int x404 = x134 * 2;
    int x136 = x135[x404];
    int * x137 = x28->cache_vals;
    int x406 = (x134 * 2) + 1;
    int x138 = x137[x406];
    int * x139 = x28->cache_vals;
    int x408 = (((((int)((unsigned int)(x36 + x38) >> 1)) & 1) * 2) + ((((x64 + ((~(((x66 ^ -1) | (-(x66 ^ -1))) >> 31)) & 2)) - (x68 + ((~(((x70 ^ -1) | (-(x70 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
    x139[x408] = x136;
    int * x141 = x28->cache_vals;
    int x411 = ((((((int)((unsigned int)(x36 + x38) >> 1)) & 1) * 2) + ((((x64 + ((~(((x66 ^ -1) | (-(x66 ^ -1))) >> 31)) & 2)) - (x68 + ((~(((x70 ^ -1) | (-(x70 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
    x141[x411] = x138;
    int * x143 = x28->cache_tags;
    int x414 = ((((int)((unsigned int)(x36 + x38) >> 1)) & 1) * 2) + ((((x64 + ((~(((x66 ^ -1) | (-(x66 ^ -1))) >> 31)) & 2)) - (x68 + ((~(((x70 ^ -1) | (-(x70 ^ -1))) >> 31)) & 2))) >> 31) & 1);
    int x415 = (int)((unsigned int)(x36 + x38) >> 1);
    x143[x414] = x415;
    int * x145 = x28->cache_dirty;
    x145[x414] = 0;
    int * x147 = x28->cache_age;
    x147[x414] = 1;
    int * x149 = x28->cache_age;
    int x150 = x149[x414];
    int * x151 = x28->cache_age;
    int x152 = x151[x327];
    int * x153 = x28->cache_age;
    int x421 = x152 + ((int)((unsigned int)(x152 - x150) >> 31));
    x153[x327] = x421;
    int * x155 = x28->cache_age;
    int x156 = x155[x329];
    int * x157 = x28->cache_age;
    int x424 = x156 + ((int)((unsigned int)(x156 - x150) >> 31));
    x157[x329] = x424;
    int * x159 = x28->cache_age;
    x159[x414] = 0;
    x162 = x414;
  }
  int x427 = (x162 * 2) + ((x36 + x38) & 1);
  int x163 = x49[x427];
  int * x164 = x28->regs;
  x164[1] = x163;
  int * x166 = x28->saved_regs;
  int * x167 = x28->regs;
  int x168 = x167[2];
  x166[2] = x168;
  int x170 = x28->timer;
  int x434 = x170 + 1;
  x28->timer = x434;
  int * x172 = x28->regs;
  int x173 = x172[1];
  int * x174 = x28->cache_tags;
  int x437 = (((int)((unsigned int)x173 >> 1)) & 1) * 2;
  int x175 = x174[x437];
  int * x176 = x28->cache_tags;
  int x439 = ((((int)((unsigned int)x173 >> 1)) & 1) * 2) + 1;
  int x177 = x176[x439];
  int * x178 = x28->cache_tags;
  int x441 = 4 + ((((int)((unsigned int)x173 >> 1)) & 3) * 2);
  int x179 = x178[x441];
  int * x180 = x28->cache_tags;
  int x443 = (4 + ((((int)((unsigned int)x173 >> 1)) & 3) * 2)) + 1;
  int x181 = x180[x443];
  int x182 = x28->timer;
  int x444 = x182 + ((100 ^ (((~(((x179 ^ ((int)((unsigned int)x173 >> 1))) | (-(x179 ^ ((int)((unsigned int)x173 >> 1))))) >> 31)) | (~(((x181 ^ ((int)((unsigned int)x173 >> 1))) | (-(x181 ^ ((int)((unsigned int)x173 >> 1))))) >> 31))) & 104)) ^ (((~(((x175 ^ ((int)((unsigned int)x173 >> 1))) | (-(x175 ^ ((int)((unsigned int)x173 >> 1))))) >> 31)) | (~(((x177 ^ ((int)((unsigned int)x173 >> 1))) | (-(x177 ^ ((int)((unsigned int)x173 >> 1))))) >> 31))) & (1 ^ (100 ^ (((~(((x179 ^ ((int)((unsigned int)x173 >> 1))) | (-(x179 ^ ((int)((unsigned int)x173 >> 1))))) >> 31)) | (~(((x181 ^ ((int)((unsigned int)x173 >> 1))) | (-(x181 ^ ((int)((unsigned int)x173 >> 1))))) >> 31))) & 104)))));
  x28->timer = x444;
  int * x184 = x28->cache_vals;
  bool x445 = !(((~(((x175 ^ ((int)((unsigned int)x173 >> 1))) | (-(x175 ^ ((int)((unsigned int)x173 >> 1))))) >> 31)) | (~(((x177 ^ ((int)((unsigned int)x173 >> 1))) | (-(x177 ^ ((int)((unsigned int)x173 >> 1))))) >> 31))) == 0);
  int x297;
  if (x445) {
    int * x185 = x28->cache_age;
    int x447 = ((((int)((unsigned int)x173 >> 1)) & 1) * 2) + ((~(((x177 ^ ((int)((unsigned int)x173 >> 1))) | (-(x177 ^ ((int)((unsigned int)x173 >> 1))))) >> 31)) & 1);
    int x186 = x185[x447];
    int * x187 = x28->cache_age;
    int x188 = x187[x437];
    int * x189 = x28->cache_age;
    int x450 = x188 + ((int)((unsigned int)(x188 - x186) >> 31));
    x189[x437] = x450;
    int * x191 = x28->cache_age;
    int x192 = x191[x439];
    int * x193 = x28->cache_age;
    int x453 = x192 + ((int)((unsigned int)(x192 - x186) >> 31));
    x193[x439] = x453;
    int * x195 = x28->cache_age;
    x195[x447] = 0;
    x297 = x447;
  } else {
    int * x198 = x28->cache_age;
    int x456 = (((int)((unsigned int)x173 >> 1)) & 1) * 2;
    int x199 = x198[x456];
    int * x200 = x28->cache_tags;
    int x201 = x200[x456];
    int * x202 = x28->cache_age;
    int x203 = x202[x439];
    int * x204 = x28->cache_tags;
    int x205 = x204[x439];
    bool x460 = !(((~(((x179 ^ ((int)((unsigned int)x173 >> 1))) | (-(x179 ^ ((int)((unsigned int)x173 >> 1))))) >> 31)) | (~(((x181 ^ ((int)((unsigned int)x173 >> 1))) | (-(x181 ^ ((int)((unsigned int)x173 >> 1))))) >> 31))) == 0);
    int x269;
    if (x460) {
      int * x206 = x28->cache_age;
      int x462 = (4 + ((((int)((unsigned int)x173 >> 1)) & 3) * 2)) + ((~(((x181 ^ ((int)((unsigned int)x173 >> 1))) | (-(x181 ^ ((int)((unsigned int)x173 >> 1))))) >> 31)) & 1);
      int x207 = x206[x462];
      int * x208 = x28->cache_age;
      int x209 = x208[x441];
      int * x210 = x28->cache_age;
      int x465 = x209 + ((int)((unsigned int)(x209 - x207) >> 31));
      x210[x441] = x465;
      int * x212 = x28->cache_age;
      int x213 = x212[x443];
      int * x214 = x28->cache_age;
      int x468 = x213 + ((int)((unsigned int)(x213 - x207) >> 31));
      x214[x443] = x468;
      int * x216 = x28->cache_age;
      x216[x462] = 0;
      x269 = x462;
    } else {
      int * x219 = x28->cache_age;
      int x471 = 4 + ((((int)((unsigned int)x173 >> 1)) & 3) * 2);
      int x220 = x219[x471];
      int * x221 = x28->cache_tags;
      int x222 = x221[x471];
      int * x223 = x28->cache_age;
      int x224 = x223[x443];
      int * x225 = x28->cache_tags;
      int x226 = x225[x443];
      int * x227 = x28->cache_dirty;
      int x476 = (4 + ((((int)((unsigned int)x173 >> 1)) & 3) * 2)) + ((((x220 + ((~(((x222 ^ -1) | (-(x222 ^ -1))) >> 31)) & 2)) - (x224 + ((~(((x226 ^ -1) | (-(x226 ^ -1))) >> 31)) & 2))) >> 31) & 1);
      int x228 = x227[x476];
      bool x477 = !(x228 == 0);
      if (x477) {
        int * x229 = x28->cache_tags;
        int x230 = x229[x476];
        int * x231 = x28->cache_vals;
        int x480 = ((4 + ((((int)((unsigned int)x173 >> 1)) & 3) * 2)) + ((((x220 + ((~(((x222 ^ -1) | (-(x222 ^ -1))) >> 31)) & 2)) - (x224 + ((~(((x226 ^ -1) | (-(x226 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
        int x232 = x231[x480];
        int * x233 = x28->cache_vals;
        int x482 = (((4 + ((((int)((unsigned int)x173 >> 1)) & 3) * 2)) + ((((x220 + ((~(((x222 ^ -1) | (-(x222 ^ -1))) >> 31)) & 2)) - (x224 + ((~(((x226 ^ -1) | (-(x226 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
        int x234 = x233[x482];
        int * x235 = x28->mem;
        int x484 = x230 * 2;
        x235[x484] = x232;
        int * x237 = x28->mem;
        int x487 = (x230 * 2) + 1;
        x237[x487] = x234;
        ;
      } else {
        ;
      }
      int * x242 = x28->mem;
      int x492 = ((int)((unsigned int)x173 >> 1)) * 2;
      int x243 = x242[x492];
      int * x244 = x28->mem;
      int x494 = (((int)((unsigned int)x173 >> 1)) * 2) + 1;
      int x245 = x244[x494];
      int * x246 = x28->cache_vals;
      int x496 = ((4 + ((((int)((unsigned int)x173 >> 1)) & 3) * 2)) + ((((x220 + ((~(((x222 ^ -1) | (-(x222 ^ -1))) >> 31)) & 2)) - (x224 + ((~(((x226 ^ -1) | (-(x226 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
      x246[x496] = x243;
      int * x248 = x28->cache_vals;
      int x499 = (((4 + ((((int)((unsigned int)x173 >> 1)) & 3) * 2)) + ((((x220 + ((~(((x222 ^ -1) | (-(x222 ^ -1))) >> 31)) & 2)) - (x224 + ((~(((x226 ^ -1) | (-(x226 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
      x248[x499] = x245;
      int * x250 = x28->cache_tags;
      int x502 = (int)((unsigned int)x173 >> 1);
      x250[x476] = x502;
      int * x252 = x28->cache_dirty;
      x252[x476] = 0;
      int * x254 = x28->cache_age;
      x254[x476] = 1;
      int * x256 = x28->cache_age;
      int x257 = x256[x476];
      int * x258 = x28->cache_age;
      int x259 = x258[x441];
      int * x260 = x28->cache_age;
      int x508 = x259 + ((int)((unsigned int)(x259 - x257) >> 31));
      x260[x441] = x508;
      int * x262 = x28->cache_age;
      int x263 = x262[x443];
      int * x264 = x28->cache_age;
      int x511 = x263 + ((int)((unsigned int)(x263 - x257) >> 31));
      x264[x443] = x511;
      int * x266 = x28->cache_age;
      x266[x476] = 0;
      x269 = x476;
    }
    int * x270 = x28->cache_vals;
    int x514 = x269 * 2;
    int x271 = x270[x514];
    int * x272 = x28->cache_vals;
    int x516 = (x269 * 2) + 1;
    int x273 = x272[x516];
    int * x274 = x28->cache_vals;
    int x518 = (((((int)((unsigned int)x173 >> 1)) & 1) * 2) + ((((x199 + ((~(((x201 ^ -1) | (-(x201 ^ -1))) >> 31)) & 2)) - (x203 + ((~(((x205 ^ -1) | (-(x205 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
    x274[x518] = x271;
    int * x276 = x28->cache_vals;
    int x521 = ((((((int)((unsigned int)x173 >> 1)) & 1) * 2) + ((((x199 + ((~(((x201 ^ -1) | (-(x201 ^ -1))) >> 31)) & 2)) - (x203 + ((~(((x205 ^ -1) | (-(x205 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
    x276[x521] = x273;
    int * x278 = x28->cache_tags;
    int x524 = ((((int)((unsigned int)x173 >> 1)) & 1) * 2) + ((((x199 + ((~(((x201 ^ -1) | (-(x201 ^ -1))) >> 31)) & 2)) - (x203 + ((~(((x205 ^ -1) | (-(x205 ^ -1))) >> 31)) & 2))) >> 31) & 1);
    int x525 = (int)((unsigned int)x173 >> 1);
    x278[x524] = x525;
    int * x280 = x28->cache_dirty;
    x280[x524] = 0;
    int * x282 = x28->cache_age;
    x282[x524] = 1;
    int * x284 = x28->cache_age;
    int x285 = x284[x524];
    int * x286 = x28->cache_age;
    int x287 = x286[x437];
    int * x288 = x28->cache_age;
    int x531 = x287 + ((int)((unsigned int)(x287 - x285) >> 31));
    x288[x437] = x531;
    int * x290 = x28->cache_age;
    int x291 = x290[x439];
    int * x292 = x28->cache_age;
    int x534 = x291 + ((int)((unsigned int)(x291 - x285) >> 31));
    x292[x439] = x534;
    int * x294 = x28->cache_age;
    x294[x524] = 0;
    x297 = x524;
  }
  int x537 = (x297 * 2) + (x173 & 1);
  int x298 = x184[x537];
  int * x299 = x28->regs;
  x299[2] = x298;
  int * x301 = x28->regs;
  int x302 = x301[0];
  bool x541 = x302 >= 20;
  if (x541) {
    int x303 = x28->timer;
    int x542 = x303 + 15;
    x28->timer = x542;
    int * x305 = x28->saved_regs;
    int x306 = x305[1];
    int * x307 = x28->regs;
    x307[1] = x306;
    int * x309 = x28->saved_regs;
    int x310 = x309[2];
    int * x311 = x28->regs;
    x311[2] = x310;
    ;
  } else {
    ;
  }
  return x28;
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
    s1.mem[SECRET_OFFSET+i] = bounded(0, 20);
    s2.mem[SECRET_OFFSET+i] = bounded(0, 20);
  }
  struct StateT *s1_ = snippet(&s1);
  struct StateT *s2_ = snippet(&s2);
  koika_assert(s1_->timer==s2_->timer, "timing leak");
  return 0;
}