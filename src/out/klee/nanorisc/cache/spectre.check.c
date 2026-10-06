// verify: clean (KLEE should report no failing assertion) [budget 1200s]
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
struct StateT * slot_1(struct StateT * x15);
struct StateT * slot_4(struct StateT * x247);
struct StateT * slot_2(struct StateT * x28);
struct StateT * slot_3(struct StateT * x45);
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

struct StateT * slot_4(struct StateT * x247) {
  int x248 = x247->timer;
  int x357 = x248 + 1;
  x247->timer = x357;
  int * x250 = x247->regs;
  int x251 = x250[1];
  int * x252 = x247->cache_tags;
  int x361 = (((int)((unsigned int)x251 >> 1)) & 1) * 2;
  int x253 = x252[x361];
  int x362 = ((((int)((unsigned int)x251 >> 1)) & 1) * 2) + 1;
  int x254 = x252[x362];
  int x363 = 4 + ((((int)((unsigned int)x251 >> 1)) & 3) * 2);
  int x255 = x252[x363];
  int x364 = (4 + ((((int)((unsigned int)x251 >> 1)) & 3) * 2)) + 1;
  int x256 = x252[x364];
  int x257 = x247->timer;
  int x365 = x257 + ((100 ^ (((~(((x255 ^ ((int)((unsigned int)x251 >> 1))) | (-(x255 ^ ((int)((unsigned int)x251 >> 1))))) >> 31)) | (~(((x256 ^ ((int)((unsigned int)x251 >> 1))) | (-(x256 ^ ((int)((unsigned int)x251 >> 1))))) >> 31))) & 104)) ^ (((~(((x253 ^ ((int)((unsigned int)x251 >> 1))) | (-(x253 ^ ((int)((unsigned int)x251 >> 1))))) >> 31)) | (~(((x254 ^ ((int)((unsigned int)x251 >> 1))) | (-(x254 ^ ((int)((unsigned int)x251 >> 1))))) >> 31))) & (1 ^ (100 ^ (((~(((x255 ^ ((int)((unsigned int)x251 >> 1))) | (-(x255 ^ ((int)((unsigned int)x251 >> 1))))) >> 31)) | (~(((x256 ^ ((int)((unsigned int)x251 >> 1))) | (-(x256 ^ ((int)((unsigned int)x251 >> 1))))) >> 31))) & 104)))));
  x247->timer = x365;
  int * x259 = x247->cache_vals;
  bool x366 = !(((~(((x253 ^ ((int)((unsigned int)x251 >> 1))) | (-(x253 ^ ((int)((unsigned int)x251 >> 1))))) >> 31)) | (~(((x254 ^ ((int)((unsigned int)x251 >> 1))) | (-(x254 ^ ((int)((unsigned int)x251 >> 1))))) >> 31))) == 0);
  int x352;
  if (x366) {
    int * x260 = x247->cache_age;
    int x368 = ((((int)((unsigned int)x251 >> 1)) & 1) * 2) + ((~(((x254 ^ ((int)((unsigned int)x251 >> 1))) | (-(x254 ^ ((int)((unsigned int)x251 >> 1))))) >> 31)) & 1);
    int x261 = x260[x368];
    int x262 = x260[x361];
    int x369 = x262 + ((int)((unsigned int)(x262 - x261) >> 31));
    x260[x361] = x369;
    int * x264 = x247->cache_age;
    int x265 = x264[x362];
    int x371 = x265 + ((int)((unsigned int)(x265 - x261) >> 31));
    x264[x362] = x371;
    int * x267 = x247->cache_age;
    x267[x368] = 0;
    x352 = x368;
  } else {
    int * x270 = x247->cache_age;
    int x375 = (((int)((unsigned int)x251 >> 1)) & 1) * 2;
    int x271 = x270[x375];
    int * x272 = x247->cache_tags;
    int x273 = x272[x375];
    int x274 = x270[x362];
    int x275 = x272[x362];
    bool x377 = !(((~(((x255 ^ ((int)((unsigned int)x251 >> 1))) | (-(x255 ^ ((int)((unsigned int)x251 >> 1))))) >> 31)) | (~(((x256 ^ ((int)((unsigned int)x251 >> 1))) | (-(x256 ^ ((int)((unsigned int)x251 >> 1))))) >> 31))) == 0);
    int x329;
    if (x377) {
      int * x276 = x247->cache_age;
      int x379 = (4 + ((((int)((unsigned int)x251 >> 1)) & 3) * 2)) + ((~(((x256 ^ ((int)((unsigned int)x251 >> 1))) | (-(x256 ^ ((int)((unsigned int)x251 >> 1))))) >> 31)) & 1);
      int x277 = x276[x379];
      int x278 = x276[x363];
      int x380 = x278 + ((int)((unsigned int)(x278 - x277) >> 31));
      x276[x363] = x380;
      int * x280 = x247->cache_age;
      int x281 = x280[x364];
      int x382 = x281 + ((int)((unsigned int)(x281 - x277) >> 31));
      x280[x364] = x382;
      int * x283 = x247->cache_age;
      x283[x379] = 0;
      x329 = x379;
    } else {
      int * x286 = x247->cache_age;
      int x386 = 4 + ((((int)((unsigned int)x251 >> 1)) & 3) * 2);
      int x287 = x286[x386];
      int * x288 = x247->cache_tags;
      int x289 = x288[x386];
      int x290 = x286[x364];
      int x291 = x288[x364];
      int * x292 = x247->cache_dirty;
      int x389 = (4 + ((((int)((unsigned int)x251 >> 1)) & 3) * 2)) + ((((x287 + ((~(((x289 ^ -1) | (-(x289 ^ -1))) >> 31)) & 2)) - (x290 + ((~(((x291 ^ -1) | (-(x291 ^ -1))) >> 31)) & 2))) >> 31) & 1);
      int x293 = x292[x389];
      bool x390 = !(x293 == 0);
      if (x390) {
        int * x294 = x247->cache_tags;
        int x295 = x294[x389];
        int * x296 = x247->cache_vals;
        int x393 = ((4 + ((((int)((unsigned int)x251 >> 1)) & 3) * 2)) + ((((x287 + ((~(((x289 ^ -1) | (-(x289 ^ -1))) >> 31)) & 2)) - (x290 + ((~(((x291 ^ -1) | (-(x291 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
        int x297 = x296[x393];
        int x394 = (((4 + ((((int)((unsigned int)x251 >> 1)) & 3) * 2)) + ((((x287 + ((~(((x289 ^ -1) | (-(x289 ^ -1))) >> 31)) & 2)) - (x290 + ((~(((x291 ^ -1) | (-(x291 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
        int x298 = x296[x394];
        int * x299 = x247->mem;
        int x396 = x295 * 2;
        x299[x396] = x297;
        int * x301 = x247->mem;
        int x399 = (x295 * 2) + 1;
        x301[x399] = x298;
        ;
      } else {
        ;
      }
      int * x306 = x247->mem;
      int x404 = ((int)((unsigned int)x251 >> 1)) * 2;
      int x307 = x306[x404];
      int x405 = (((int)((unsigned int)x251 >> 1)) * 2) + 1;
      int x308 = x306[x405];
      int * x309 = x247->cache_vals;
      int x407 = ((4 + ((((int)((unsigned int)x251 >> 1)) & 3) * 2)) + ((((x287 + ((~(((x289 ^ -1) | (-(x289 ^ -1))) >> 31)) & 2)) - (x290 + ((~(((x291 ^ -1) | (-(x291 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
      x309[x407] = x307;
      int * x311 = x247->cache_vals;
      int x410 = (((4 + ((((int)((unsigned int)x251 >> 1)) & 3) * 2)) + ((((x287 + ((~(((x289 ^ -1) | (-(x289 ^ -1))) >> 31)) & 2)) - (x290 + ((~(((x291 ^ -1) | (-(x291 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
      x311[x410] = x308;
      int * x313 = x247->cache_tags;
      int x413 = (int)((unsigned int)x251 >> 1);
      x313[x389] = x413;
      int * x315 = x247->cache_dirty;
      x315[x389] = 0;
      int * x317 = x247->cache_age;
      x317[x389] = 1;
      int * x319 = x247->cache_age;
      int x320 = x319[x389];
      int x321 = x319[x363];
      int x418 = x321 + ((int)((unsigned int)(x321 - x320) >> 31));
      x319[x363] = x418;
      int * x323 = x247->cache_age;
      int x324 = x323[x364];
      int x420 = x324 + ((int)((unsigned int)(x324 - x320) >> 31));
      x323[x364] = x420;
      int * x326 = x247->cache_age;
      x326[x389] = 0;
      x329 = x389;
    }
    int * x330 = x247->cache_vals;
    int x423 = x329 * 2;
    int x331 = x330[x423];
    int x424 = (x329 * 2) + 1;
    int x332 = x330[x424];
    int x425 = (((((int)((unsigned int)x251 >> 1)) & 1) * 2) + ((((x271 + ((~(((x273 ^ -1) | (-(x273 ^ -1))) >> 31)) & 2)) - (x274 + ((~(((x275 ^ -1) | (-(x275 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
    x330[x425] = x331;
    int * x334 = x247->cache_vals;
    int x428 = ((((((int)((unsigned int)x251 >> 1)) & 1) * 2) + ((((x271 + ((~(((x273 ^ -1) | (-(x273 ^ -1))) >> 31)) & 2)) - (x274 + ((~(((x275 ^ -1) | (-(x275 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
    x334[x428] = x332;
    int * x336 = x247->cache_tags;
    int x431 = ((((int)((unsigned int)x251 >> 1)) & 1) * 2) + ((((x271 + ((~(((x273 ^ -1) | (-(x273 ^ -1))) >> 31)) & 2)) - (x274 + ((~(((x275 ^ -1) | (-(x275 ^ -1))) >> 31)) & 2))) >> 31) & 1);
    int x432 = (int)((unsigned int)x251 >> 1);
    x336[x431] = x432;
    int * x338 = x247->cache_dirty;
    x338[x431] = 0;
    int * x340 = x247->cache_age;
    x340[x431] = 1;
    int * x342 = x247->cache_age;
    int x343 = x342[x431];
    int x344 = x342[x361];
    int x437 = x344 + ((int)((unsigned int)(x344 - x343) >> 31));
    x342[x361] = x437;
    int * x346 = x247->cache_age;
    int x347 = x346[x362];
    int x439 = x347 + ((int)((unsigned int)(x347 - x343) >> 31));
    x346[x362] = x439;
    int * x349 = x247->cache_age;
    x349[x431] = 0;
    x352 = x431;
  }
  int x442 = (x352 * 2) + (x251 & 1);
  int x353 = x259[x442];
  int * x354 = x247->regs;
  x354[2] = x353;
  return x247;
}

struct StateT * slot_2(struct StateT * x28) {
  int x29 = x28->timer;
  int x38 = x29 + 1;
  x28->timer = x38;
  int * x31 = x28->regs;
  int x32 = x31[0];
  bool x41 = x32 >= 20;
  struct StateT * x36;
  if (x41) {
    x36 = x28;
  } else {
    struct StateT * x34 = slot_3(x28);
    x36 = x34;
  }
  return x36;
}

struct StateT * slot_3(struct StateT * x45) {
  int x46 = x45->timer;
  int x157 = x46 + 1;
  x45->timer = x157;
  int * x48 = x45->regs;
  int x49 = x48[3];
  int x50 = x48[0];
  int * x51 = x45->cache_tags;
  int x162 = (((int)((unsigned int)(x49 + x50) >> 1)) & 1) * 2;
  int x52 = x51[x162];
  int x163 = ((((int)((unsigned int)(x49 + x50) >> 1)) & 1) * 2) + 1;
  int x53 = x51[x163];
  int x164 = 4 + ((((int)((unsigned int)(x49 + x50) >> 1)) & 3) * 2);
  int x54 = x51[x164];
  int x165 = (4 + ((((int)((unsigned int)(x49 + x50) >> 1)) & 3) * 2)) + 1;
  int x55 = x51[x165];
  int x56 = x45->timer;
  int x166 = x56 + ((100 ^ (((~(((x54 ^ ((int)((unsigned int)(x49 + x50) >> 1))) | (-(x54 ^ ((int)((unsigned int)(x49 + x50) >> 1))))) >> 31)) | (~(((x55 ^ ((int)((unsigned int)(x49 + x50) >> 1))) | (-(x55 ^ ((int)((unsigned int)(x49 + x50) >> 1))))) >> 31))) & 104)) ^ (((~(((x52 ^ ((int)((unsigned int)(x49 + x50) >> 1))) | (-(x52 ^ ((int)((unsigned int)(x49 + x50) >> 1))))) >> 31)) | (~(((x53 ^ ((int)((unsigned int)(x49 + x50) >> 1))) | (-(x53 ^ ((int)((unsigned int)(x49 + x50) >> 1))))) >> 31))) & (1 ^ (100 ^ (((~(((x54 ^ ((int)((unsigned int)(x49 + x50) >> 1))) | (-(x54 ^ ((int)((unsigned int)(x49 + x50) >> 1))))) >> 31)) | (~(((x55 ^ ((int)((unsigned int)(x49 + x50) >> 1))) | (-(x55 ^ ((int)((unsigned int)(x49 + x50) >> 1))))) >> 31))) & 104)))));
  x45->timer = x166;
  int * x58 = x45->cache_vals;
  bool x167 = !(((~(((x52 ^ ((int)((unsigned int)(x49 + x50) >> 1))) | (-(x52 ^ ((int)((unsigned int)(x49 + x50) >> 1))))) >> 31)) | (~(((x53 ^ ((int)((unsigned int)(x49 + x50) >> 1))) | (-(x53 ^ ((int)((unsigned int)(x49 + x50) >> 1))))) >> 31))) == 0);
  int x151;
  if (x167) {
    int * x59 = x45->cache_age;
    int x169 = ((((int)((unsigned int)(x49 + x50) >> 1)) & 1) * 2) + ((~(((x53 ^ ((int)((unsigned int)(x49 + x50) >> 1))) | (-(x53 ^ ((int)((unsigned int)(x49 + x50) >> 1))))) >> 31)) & 1);
    int x60 = x59[x169];
    int x61 = x59[x162];
    int x170 = x61 + ((int)((unsigned int)(x61 - x60) >> 31));
    x59[x162] = x170;
    int * x63 = x45->cache_age;
    int x64 = x63[x163];
    int x172 = x64 + ((int)((unsigned int)(x64 - x60) >> 31));
    x63[x163] = x172;
    int * x66 = x45->cache_age;
    x66[x169] = 0;
    x151 = x169;
  } else {
    int * x69 = x45->cache_age;
    int x175 = (((int)((unsigned int)(x49 + x50) >> 1)) & 1) * 2;
    int x70 = x69[x175];
    int * x71 = x45->cache_tags;
    int x72 = x71[x175];
    int x73 = x69[x163];
    int x74 = x71[x163];
    bool x177 = !(((~(((x54 ^ ((int)((unsigned int)(x49 + x50) >> 1))) | (-(x54 ^ ((int)((unsigned int)(x49 + x50) >> 1))))) >> 31)) | (~(((x55 ^ ((int)((unsigned int)(x49 + x50) >> 1))) | (-(x55 ^ ((int)((unsigned int)(x49 + x50) >> 1))))) >> 31))) == 0);
    int x128;
    if (x177) {
      int * x75 = x45->cache_age;
      int x179 = (4 + ((((int)((unsigned int)(x49 + x50) >> 1)) & 3) * 2)) + ((~(((x55 ^ ((int)((unsigned int)(x49 + x50) >> 1))) | (-(x55 ^ ((int)((unsigned int)(x49 + x50) >> 1))))) >> 31)) & 1);
      int x76 = x75[x179];
      int x77 = x75[x164];
      int x180 = x77 + ((int)((unsigned int)(x77 - x76) >> 31));
      x75[x164] = x180;
      int * x79 = x45->cache_age;
      int x80 = x79[x165];
      int x182 = x80 + ((int)((unsigned int)(x80 - x76) >> 31));
      x79[x165] = x182;
      int * x82 = x45->cache_age;
      x82[x179] = 0;
      x128 = x179;
    } else {
      int * x85 = x45->cache_age;
      int x185 = 4 + ((((int)((unsigned int)(x49 + x50) >> 1)) & 3) * 2);
      int x86 = x85[x185];
      int * x87 = x45->cache_tags;
      int x88 = x87[x185];
      int x89 = x85[x165];
      int x90 = x87[x165];
      int * x91 = x45->cache_dirty;
      int x188 = (4 + ((((int)((unsigned int)(x49 + x50) >> 1)) & 3) * 2)) + ((((x86 + ((~(((x88 ^ -1) | (-(x88 ^ -1))) >> 31)) & 2)) - (x89 + ((~(((x90 ^ -1) | (-(x90 ^ -1))) >> 31)) & 2))) >> 31) & 1);
      int x92 = x91[x188];
      bool x189 = !(x92 == 0);
      if (x189) {
        int * x93 = x45->cache_tags;
        int x94 = x93[x188];
        int * x95 = x45->cache_vals;
        int x192 = ((4 + ((((int)((unsigned int)(x49 + x50) >> 1)) & 3) * 2)) + ((((x86 + ((~(((x88 ^ -1) | (-(x88 ^ -1))) >> 31)) & 2)) - (x89 + ((~(((x90 ^ -1) | (-(x90 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
        int x96 = x95[x192];
        int x193 = (((4 + ((((int)((unsigned int)(x49 + x50) >> 1)) & 3) * 2)) + ((((x86 + ((~(((x88 ^ -1) | (-(x88 ^ -1))) >> 31)) & 2)) - (x89 + ((~(((x90 ^ -1) | (-(x90 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
        int x97 = x95[x193];
        int * x98 = x45->mem;
        int x195 = x94 * 2;
        x98[x195] = x96;
        int * x100 = x45->mem;
        int x198 = (x94 * 2) + 1;
        x100[x198] = x97;
        ;
      } else {
        ;
      }
      int * x105 = x45->mem;
      int x203 = ((int)((unsigned int)(x49 + x50) >> 1)) * 2;
      int x106 = x105[x203];
      int x204 = (((int)((unsigned int)(x49 + x50) >> 1)) * 2) + 1;
      int x107 = x105[x204];
      int * x108 = x45->cache_vals;
      int x206 = ((4 + ((((int)((unsigned int)(x49 + x50) >> 1)) & 3) * 2)) + ((((x86 + ((~(((x88 ^ -1) | (-(x88 ^ -1))) >> 31)) & 2)) - (x89 + ((~(((x90 ^ -1) | (-(x90 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
      x108[x206] = x106;
      int * x110 = x45->cache_vals;
      int x209 = (((4 + ((((int)((unsigned int)(x49 + x50) >> 1)) & 3) * 2)) + ((((x86 + ((~(((x88 ^ -1) | (-(x88 ^ -1))) >> 31)) & 2)) - (x89 + ((~(((x90 ^ -1) | (-(x90 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
      x110[x209] = x107;
      int * x112 = x45->cache_tags;
      int x212 = (int)((unsigned int)(x49 + x50) >> 1);
      x112[x188] = x212;
      int * x114 = x45->cache_dirty;
      x114[x188] = 0;
      int * x116 = x45->cache_age;
      x116[x188] = 1;
      int * x118 = x45->cache_age;
      int x119 = x118[x188];
      int x120 = x118[x164];
      int x217 = x120 + ((int)((unsigned int)(x120 - x119) >> 31));
      x118[x164] = x217;
      int * x122 = x45->cache_age;
      int x123 = x122[x165];
      int x219 = x123 + ((int)((unsigned int)(x123 - x119) >> 31));
      x122[x165] = x219;
      int * x125 = x45->cache_age;
      x125[x188] = 0;
      x128 = x188;
    }
    int * x129 = x45->cache_vals;
    int x222 = x128 * 2;
    int x130 = x129[x222];
    int x223 = (x128 * 2) + 1;
    int x131 = x129[x223];
    int x224 = (((((int)((unsigned int)(x49 + x50) >> 1)) & 1) * 2) + ((((x70 + ((~(((x72 ^ -1) | (-(x72 ^ -1))) >> 31)) & 2)) - (x73 + ((~(((x74 ^ -1) | (-(x74 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
    x129[x224] = x130;
    int * x133 = x45->cache_vals;
    int x227 = ((((((int)((unsigned int)(x49 + x50) >> 1)) & 1) * 2) + ((((x70 + ((~(((x72 ^ -1) | (-(x72 ^ -1))) >> 31)) & 2)) - (x73 + ((~(((x74 ^ -1) | (-(x74 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
    x133[x227] = x131;
    int * x135 = x45->cache_tags;
    int x230 = ((((int)((unsigned int)(x49 + x50) >> 1)) & 1) * 2) + ((((x70 + ((~(((x72 ^ -1) | (-(x72 ^ -1))) >> 31)) & 2)) - (x73 + ((~(((x74 ^ -1) | (-(x74 ^ -1))) >> 31)) & 2))) >> 31) & 1);
    int x231 = (int)((unsigned int)(x49 + x50) >> 1);
    x135[x230] = x231;
    int * x137 = x45->cache_dirty;
    x137[x230] = 0;
    int * x139 = x45->cache_age;
    x139[x230] = 1;
    int * x141 = x45->cache_age;
    int x142 = x141[x230];
    int x143 = x141[x162];
    int x236 = x143 + ((int)((unsigned int)(x143 - x142) >> 31));
    x141[x162] = x236;
    int * x145 = x45->cache_age;
    int x146 = x145[x163];
    int x238 = x146 + ((int)((unsigned int)(x146 - x142) >> 31));
    x145[x163] = x238;
    int * x148 = x45->cache_age;
    x148[x230] = 0;
    x151 = x230;
  }
  int x241 = (x151 * 2) + ((x49 + x50) & 1);
  int x152 = x58[x241];
  int * x153 = x45->regs;
  x153[1] = x152;
  struct StateT * x155 = slot_4(x45);
  return x155;
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