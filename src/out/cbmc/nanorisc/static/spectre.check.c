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

struct StateT * snippet(struct StateT * x0);
struct StateT * slot_1(struct StateT * x15);
struct StateT * slot_5(struct StateT * x452);
struct StateT * slot_4(struct StateT * x243);
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

struct StateT * slot_5(struct StateT * x452) {
  int * x453 = x452->regs;
  int x454 = x453[0];
  bool x471 = x454 >= 20;
  struct StateT * x467;
  if (x471) {
    int x455 = x452->timer;
    int x472 = x455 + 15;
    x452->timer = x472;
    int * x457 = x452->saved_regs;
    int x458 = x457[1];
    int * x459 = x452->regs;
    x459[1] = x458;
    int * x461 = x452->saved_regs;
    int x462 = x461[2];
    int * x463 = x452->regs;
    x463[2] = x462;
    x467 = x452;
  } else {
    x467 = x452;
  }
  return x467;
}

struct StateT * slot_4(struct StateT * x243) {
  int * x244 = x243->saved_regs;
  int * x245 = x243->regs;
  int x246 = x245[2];
  x244[2] = x246;
  int x248 = x243->timer;
  int x362 = x248 + 1;
  x243->timer = x362;
  int * x250 = x243->regs;
  int x251 = x250[1];
  int * x252 = x243->cache_tags;
  int x366 = (((int)((unsigned int)x251 >> 1)) & 1) * 2;
  int x253 = x252[x366];
  int x367 = ((((int)((unsigned int)x251 >> 1)) & 1) * 2) + 1;
  int x254 = x252[x367];
  int x368 = 4 + ((((int)((unsigned int)x251 >> 1)) & 3) * 2);
  int x255 = x252[x368];
  int x369 = (4 + ((((int)((unsigned int)x251 >> 1)) & 3) * 2)) + 1;
  int x256 = x252[x369];
  int x257 = x243->timer;
  int x370 = x257 + ((100 ^ (((~(((x255 ^ ((int)((unsigned int)x251 >> 1))) | (-(x255 ^ ((int)((unsigned int)x251 >> 1))))) >> 31)) | (~(((x256 ^ ((int)((unsigned int)x251 >> 1))) | (-(x256 ^ ((int)((unsigned int)x251 >> 1))))) >> 31))) & 104)) ^ (((~(((x253 ^ ((int)((unsigned int)x251 >> 1))) | (-(x253 ^ ((int)((unsigned int)x251 >> 1))))) >> 31)) | (~(((x254 ^ ((int)((unsigned int)x251 >> 1))) | (-(x254 ^ ((int)((unsigned int)x251 >> 1))))) >> 31))) & (1 ^ (100 ^ (((~(((x255 ^ ((int)((unsigned int)x251 >> 1))) | (-(x255 ^ ((int)((unsigned int)x251 >> 1))))) >> 31)) | (~(((x256 ^ ((int)((unsigned int)x251 >> 1))) | (-(x256 ^ ((int)((unsigned int)x251 >> 1))))) >> 31))) & 104)))));
  x243->timer = x370;
  int * x259 = x243->cache_vals;
  bool x371 = !(((~(((x253 ^ ((int)((unsigned int)x251 >> 1))) | (-(x253 ^ ((int)((unsigned int)x251 >> 1))))) >> 31)) | (~(((x254 ^ ((int)((unsigned int)x251 >> 1))) | (-(x254 ^ ((int)((unsigned int)x251 >> 1))))) >> 31))) == 0);
  int x352;
  if (x371) {
    int * x260 = x243->cache_age;
    int x373 = ((((int)((unsigned int)x251 >> 1)) & 1) * 2) + ((~(((x254 ^ ((int)((unsigned int)x251 >> 1))) | (-(x254 ^ ((int)((unsigned int)x251 >> 1))))) >> 31)) & 1);
    int x261 = x260[x373];
    int x262 = x260[x366];
    int x374 = x262 + ((int)((unsigned int)(x262 - x261) >> 31));
    x260[x366] = x374;
    int * x264 = x243->cache_age;
    int x265 = x264[x367];
    int x376 = x265 + ((int)((unsigned int)(x265 - x261) >> 31));
    x264[x367] = x376;
    int * x267 = x243->cache_age;
    x267[x373] = 0;
    x352 = x373;
  } else {
    int * x270 = x243->cache_age;
    int x380 = (((int)((unsigned int)x251 >> 1)) & 1) * 2;
    int x271 = x270[x380];
    int * x272 = x243->cache_tags;
    int x273 = x272[x380];
    int x274 = x270[x367];
    int x275 = x272[x367];
    bool x382 = !(((~(((x255 ^ ((int)((unsigned int)x251 >> 1))) | (-(x255 ^ ((int)((unsigned int)x251 >> 1))))) >> 31)) | (~(((x256 ^ ((int)((unsigned int)x251 >> 1))) | (-(x256 ^ ((int)((unsigned int)x251 >> 1))))) >> 31))) == 0);
    int x329;
    if (x382) {
      int * x276 = x243->cache_age;
      int x384 = (4 + ((((int)((unsigned int)x251 >> 1)) & 3) * 2)) + ((~(((x256 ^ ((int)((unsigned int)x251 >> 1))) | (-(x256 ^ ((int)((unsigned int)x251 >> 1))))) >> 31)) & 1);
      int x277 = x276[x384];
      int x278 = x276[x368];
      int x385 = x278 + ((int)((unsigned int)(x278 - x277) >> 31));
      x276[x368] = x385;
      int * x280 = x243->cache_age;
      int x281 = x280[x369];
      int x387 = x281 + ((int)((unsigned int)(x281 - x277) >> 31));
      x280[x369] = x387;
      int * x283 = x243->cache_age;
      x283[x384] = 0;
      x329 = x384;
    } else {
      int * x286 = x243->cache_age;
      int x391 = 4 + ((((int)((unsigned int)x251 >> 1)) & 3) * 2);
      int x287 = x286[x391];
      int * x288 = x243->cache_tags;
      int x289 = x288[x391];
      int x290 = x286[x369];
      int x291 = x288[x369];
      int * x292 = x243->cache_dirty;
      int x394 = (4 + ((((int)((unsigned int)x251 >> 1)) & 3) * 2)) + ((((x287 + ((~(((x289 ^ -1) | (-(x289 ^ -1))) >> 31)) & 2)) - (x290 + ((~(((x291 ^ -1) | (-(x291 ^ -1))) >> 31)) & 2))) >> 31) & 1);
      int x293 = x292[x394];
      bool x395 = !(x293 == 0);
      if (x395) {
        int * x294 = x243->cache_tags;
        int x295 = x294[x394];
        int * x296 = x243->cache_vals;
        int x398 = ((4 + ((((int)((unsigned int)x251 >> 1)) & 3) * 2)) + ((((x287 + ((~(((x289 ^ -1) | (-(x289 ^ -1))) >> 31)) & 2)) - (x290 + ((~(((x291 ^ -1) | (-(x291 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
        int x297 = x296[x398];
        int x399 = (((4 + ((((int)((unsigned int)x251 >> 1)) & 3) * 2)) + ((((x287 + ((~(((x289 ^ -1) | (-(x289 ^ -1))) >> 31)) & 2)) - (x290 + ((~(((x291 ^ -1) | (-(x291 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
        int x298 = x296[x399];
        int * x299 = x243->mem;
        int x401 = x295 * 2;
        x299[x401] = x297;
        int * x301 = x243->mem;
        int x404 = (x295 * 2) + 1;
        x301[x404] = x298;
        ;
      } else {
        ;
      }
      int * x306 = x243->mem;
      int x409 = ((int)((unsigned int)x251 >> 1)) * 2;
      int x307 = x306[x409];
      int x410 = (((int)((unsigned int)x251 >> 1)) * 2) + 1;
      int x308 = x306[x410];
      int * x309 = x243->cache_vals;
      int x412 = ((4 + ((((int)((unsigned int)x251 >> 1)) & 3) * 2)) + ((((x287 + ((~(((x289 ^ -1) | (-(x289 ^ -1))) >> 31)) & 2)) - (x290 + ((~(((x291 ^ -1) | (-(x291 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
      x309[x412] = x307;
      int * x311 = x243->cache_vals;
      int x415 = (((4 + ((((int)((unsigned int)x251 >> 1)) & 3) * 2)) + ((((x287 + ((~(((x289 ^ -1) | (-(x289 ^ -1))) >> 31)) & 2)) - (x290 + ((~(((x291 ^ -1) | (-(x291 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
      x311[x415] = x308;
      int * x313 = x243->cache_tags;
      int x418 = (int)((unsigned int)x251 >> 1);
      x313[x394] = x418;
      int * x315 = x243->cache_dirty;
      x315[x394] = 0;
      int * x317 = x243->cache_age;
      x317[x394] = 1;
      int * x319 = x243->cache_age;
      int x320 = x319[x394];
      int x321 = x319[x368];
      int x423 = x321 + ((int)((unsigned int)(x321 - x320) >> 31));
      x319[x368] = x423;
      int * x323 = x243->cache_age;
      int x324 = x323[x369];
      int x425 = x324 + ((int)((unsigned int)(x324 - x320) >> 31));
      x323[x369] = x425;
      int * x326 = x243->cache_age;
      x326[x394] = 0;
      x329 = x394;
    }
    int * x330 = x243->cache_vals;
    int x428 = x329 * 2;
    int x331 = x330[x428];
    int x429 = (x329 * 2) + 1;
    int x332 = x330[x429];
    int x430 = (((((int)((unsigned int)x251 >> 1)) & 1) * 2) + ((((x271 + ((~(((x273 ^ -1) | (-(x273 ^ -1))) >> 31)) & 2)) - (x274 + ((~(((x275 ^ -1) | (-(x275 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
    x330[x430] = x331;
    int * x334 = x243->cache_vals;
    int x433 = ((((((int)((unsigned int)x251 >> 1)) & 1) * 2) + ((((x271 + ((~(((x273 ^ -1) | (-(x273 ^ -1))) >> 31)) & 2)) - (x274 + ((~(((x275 ^ -1) | (-(x275 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
    x334[x433] = x332;
    int * x336 = x243->cache_tags;
    int x436 = ((((int)((unsigned int)x251 >> 1)) & 1) * 2) + ((((x271 + ((~(((x273 ^ -1) | (-(x273 ^ -1))) >> 31)) & 2)) - (x274 + ((~(((x275 ^ -1) | (-(x275 ^ -1))) >> 31)) & 2))) >> 31) & 1);
    int x437 = (int)((unsigned int)x251 >> 1);
    x336[x436] = x437;
    int * x338 = x243->cache_dirty;
    x338[x436] = 0;
    int * x340 = x243->cache_age;
    x340[x436] = 1;
    int * x342 = x243->cache_age;
    int x343 = x342[x436];
    int x344 = x342[x366];
    int x442 = x344 + ((int)((unsigned int)(x344 - x343) >> 31));
    x342[x366] = x442;
    int * x346 = x243->cache_age;
    int x347 = x346[x367];
    int x444 = x347 + ((int)((unsigned int)(x347 - x343) >> 31));
    x346[x367] = x444;
    int * x349 = x243->cache_age;
    x349[x436] = 0;
    x352 = x436;
  }
  int x447 = (x352 * 2) + (x251 & 1);
  int x353 = x259[x447];
  int * x354 = x243->regs;
  x354[2] = x353;
  struct StateT * x356 = slot_5(x243);
  return x356;
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
  int x156 = x41 + 1;
  x36->timer = x156;
  int * x43 = x36->regs;
  int x44 = x43[3];
  int x45 = x43[0];
  int * x46 = x36->cache_tags;
  int x161 = (((int)((unsigned int)(x44 + x45) >> 1)) & 1) * 2;
  int x47 = x46[x161];
  int x162 = ((((int)((unsigned int)(x44 + x45) >> 1)) & 1) * 2) + 1;
  int x48 = x46[x162];
  int x163 = 4 + ((((int)((unsigned int)(x44 + x45) >> 1)) & 3) * 2);
  int x49 = x46[x163];
  int x164 = (4 + ((((int)((unsigned int)(x44 + x45) >> 1)) & 3) * 2)) + 1;
  int x50 = x46[x164];
  int x51 = x36->timer;
  int x165 = x51 + ((100 ^ (((~(((x49 ^ ((int)((unsigned int)(x44 + x45) >> 1))) | (-(x49 ^ ((int)((unsigned int)(x44 + x45) >> 1))))) >> 31)) | (~(((x50 ^ ((int)((unsigned int)(x44 + x45) >> 1))) | (-(x50 ^ ((int)((unsigned int)(x44 + x45) >> 1))))) >> 31))) & 104)) ^ (((~(((x47 ^ ((int)((unsigned int)(x44 + x45) >> 1))) | (-(x47 ^ ((int)((unsigned int)(x44 + x45) >> 1))))) >> 31)) | (~(((x48 ^ ((int)((unsigned int)(x44 + x45) >> 1))) | (-(x48 ^ ((int)((unsigned int)(x44 + x45) >> 1))))) >> 31))) & (1 ^ (100 ^ (((~(((x49 ^ ((int)((unsigned int)(x44 + x45) >> 1))) | (-(x49 ^ ((int)((unsigned int)(x44 + x45) >> 1))))) >> 31)) | (~(((x50 ^ ((int)((unsigned int)(x44 + x45) >> 1))) | (-(x50 ^ ((int)((unsigned int)(x44 + x45) >> 1))))) >> 31))) & 104)))));
  x36->timer = x165;
  int * x53 = x36->cache_vals;
  bool x166 = !(((~(((x47 ^ ((int)((unsigned int)(x44 + x45) >> 1))) | (-(x47 ^ ((int)((unsigned int)(x44 + x45) >> 1))))) >> 31)) | (~(((x48 ^ ((int)((unsigned int)(x44 + x45) >> 1))) | (-(x48 ^ ((int)((unsigned int)(x44 + x45) >> 1))))) >> 31))) == 0);
  int x146;
  if (x166) {
    int * x54 = x36->cache_age;
    int x168 = ((((int)((unsigned int)(x44 + x45) >> 1)) & 1) * 2) + ((~(((x48 ^ ((int)((unsigned int)(x44 + x45) >> 1))) | (-(x48 ^ ((int)((unsigned int)(x44 + x45) >> 1))))) >> 31)) & 1);
    int x55 = x54[x168];
    int x56 = x54[x161];
    int x169 = x56 + ((int)((unsigned int)(x56 - x55) >> 31));
    x54[x161] = x169;
    int * x58 = x36->cache_age;
    int x59 = x58[x162];
    int x171 = x59 + ((int)((unsigned int)(x59 - x55) >> 31));
    x58[x162] = x171;
    int * x61 = x36->cache_age;
    x61[x168] = 0;
    x146 = x168;
  } else {
    int * x64 = x36->cache_age;
    int x174 = (((int)((unsigned int)(x44 + x45) >> 1)) & 1) * 2;
    int x65 = x64[x174];
    int * x66 = x36->cache_tags;
    int x67 = x66[x174];
    int x68 = x64[x162];
    int x69 = x66[x162];
    bool x176 = !(((~(((x49 ^ ((int)((unsigned int)(x44 + x45) >> 1))) | (-(x49 ^ ((int)((unsigned int)(x44 + x45) >> 1))))) >> 31)) | (~(((x50 ^ ((int)((unsigned int)(x44 + x45) >> 1))) | (-(x50 ^ ((int)((unsigned int)(x44 + x45) >> 1))))) >> 31))) == 0);
    int x123;
    if (x176) {
      int * x70 = x36->cache_age;
      int x178 = (4 + ((((int)((unsigned int)(x44 + x45) >> 1)) & 3) * 2)) + ((~(((x50 ^ ((int)((unsigned int)(x44 + x45) >> 1))) | (-(x50 ^ ((int)((unsigned int)(x44 + x45) >> 1))))) >> 31)) & 1);
      int x71 = x70[x178];
      int x72 = x70[x163];
      int x179 = x72 + ((int)((unsigned int)(x72 - x71) >> 31));
      x70[x163] = x179;
      int * x74 = x36->cache_age;
      int x75 = x74[x164];
      int x181 = x75 + ((int)((unsigned int)(x75 - x71) >> 31));
      x74[x164] = x181;
      int * x77 = x36->cache_age;
      x77[x178] = 0;
      x123 = x178;
    } else {
      int * x80 = x36->cache_age;
      int x184 = 4 + ((((int)((unsigned int)(x44 + x45) >> 1)) & 3) * 2);
      int x81 = x80[x184];
      int * x82 = x36->cache_tags;
      int x83 = x82[x184];
      int x84 = x80[x164];
      int x85 = x82[x164];
      int * x86 = x36->cache_dirty;
      int x187 = (4 + ((((int)((unsigned int)(x44 + x45) >> 1)) & 3) * 2)) + ((((x81 + ((~(((x83 ^ -1) | (-(x83 ^ -1))) >> 31)) & 2)) - (x84 + ((~(((x85 ^ -1) | (-(x85 ^ -1))) >> 31)) & 2))) >> 31) & 1);
      int x87 = x86[x187];
      bool x188 = !(x87 == 0);
      if (x188) {
        int * x88 = x36->cache_tags;
        int x89 = x88[x187];
        int * x90 = x36->cache_vals;
        int x191 = ((4 + ((((int)((unsigned int)(x44 + x45) >> 1)) & 3) * 2)) + ((((x81 + ((~(((x83 ^ -1) | (-(x83 ^ -1))) >> 31)) & 2)) - (x84 + ((~(((x85 ^ -1) | (-(x85 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
        int x91 = x90[x191];
        int x192 = (((4 + ((((int)((unsigned int)(x44 + x45) >> 1)) & 3) * 2)) + ((((x81 + ((~(((x83 ^ -1) | (-(x83 ^ -1))) >> 31)) & 2)) - (x84 + ((~(((x85 ^ -1) | (-(x85 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
        int x92 = x90[x192];
        int * x93 = x36->mem;
        int x194 = x89 * 2;
        x93[x194] = x91;
        int * x95 = x36->mem;
        int x197 = (x89 * 2) + 1;
        x95[x197] = x92;
        ;
      } else {
        ;
      }
      int * x100 = x36->mem;
      int x202 = ((int)((unsigned int)(x44 + x45) >> 1)) * 2;
      int x101 = x100[x202];
      int x203 = (((int)((unsigned int)(x44 + x45) >> 1)) * 2) + 1;
      int x102 = x100[x203];
      int * x103 = x36->cache_vals;
      int x205 = ((4 + ((((int)((unsigned int)(x44 + x45) >> 1)) & 3) * 2)) + ((((x81 + ((~(((x83 ^ -1) | (-(x83 ^ -1))) >> 31)) & 2)) - (x84 + ((~(((x85 ^ -1) | (-(x85 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
      x103[x205] = x101;
      int * x105 = x36->cache_vals;
      int x208 = (((4 + ((((int)((unsigned int)(x44 + x45) >> 1)) & 3) * 2)) + ((((x81 + ((~(((x83 ^ -1) | (-(x83 ^ -1))) >> 31)) & 2)) - (x84 + ((~(((x85 ^ -1) | (-(x85 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
      x105[x208] = x102;
      int * x107 = x36->cache_tags;
      int x211 = (int)((unsigned int)(x44 + x45) >> 1);
      x107[x187] = x211;
      int * x109 = x36->cache_dirty;
      x109[x187] = 0;
      int * x111 = x36->cache_age;
      x111[x187] = 1;
      int * x113 = x36->cache_age;
      int x114 = x113[x187];
      int x115 = x113[x163];
      int x215 = x115 + ((int)((unsigned int)(x115 - x114) >> 31));
      x113[x163] = x215;
      int * x117 = x36->cache_age;
      int x118 = x117[x164];
      int x217 = x118 + ((int)((unsigned int)(x118 - x114) >> 31));
      x117[x164] = x217;
      int * x120 = x36->cache_age;
      x120[x187] = 0;
      x123 = x187;
    }
    int * x124 = x36->cache_vals;
    int x220 = x123 * 2;
    int x125 = x124[x220];
    int x221 = (x123 * 2) + 1;
    int x126 = x124[x221];
    int x222 = (((((int)((unsigned int)(x44 + x45) >> 1)) & 1) * 2) + ((((x65 + ((~(((x67 ^ -1) | (-(x67 ^ -1))) >> 31)) & 2)) - (x68 + ((~(((x69 ^ -1) | (-(x69 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
    x124[x222] = x125;
    int * x128 = x36->cache_vals;
    int x225 = ((((((int)((unsigned int)(x44 + x45) >> 1)) & 1) * 2) + ((((x65 + ((~(((x67 ^ -1) | (-(x67 ^ -1))) >> 31)) & 2)) - (x68 + ((~(((x69 ^ -1) | (-(x69 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
    x128[x225] = x126;
    int * x130 = x36->cache_tags;
    int x228 = ((((int)((unsigned int)(x44 + x45) >> 1)) & 1) * 2) + ((((x65 + ((~(((x67 ^ -1) | (-(x67 ^ -1))) >> 31)) & 2)) - (x68 + ((~(((x69 ^ -1) | (-(x69 ^ -1))) >> 31)) & 2))) >> 31) & 1);
    int x229 = (int)((unsigned int)(x44 + x45) >> 1);
    x130[x228] = x229;
    int * x132 = x36->cache_dirty;
    x132[x228] = 0;
    int * x134 = x36->cache_age;
    x134[x228] = 1;
    int * x136 = x36->cache_age;
    int x137 = x136[x228];
    int x138 = x136[x161];
    int x233 = x138 + ((int)((unsigned int)(x138 - x137) >> 31));
    x136[x161] = x233;
    int * x140 = x36->cache_age;
    int x141 = x140[x162];
    int x235 = x141 + ((int)((unsigned int)(x141 - x137) >> 31));
    x140[x162] = x235;
    int * x143 = x36->cache_age;
    x143[x228] = 0;
    x146 = x228;
  }
  int x238 = (x146 * 2) + ((x44 + x45) & 1);
  int x147 = x53[x238];
  int * x148 = x36->regs;
  x148[1] = x147;
  struct StateT * x150 = slot_4(x36);
  return x150;
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