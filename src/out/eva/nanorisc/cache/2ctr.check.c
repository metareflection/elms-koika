// verify: leak (Eva should report untainted: unknown) [unroll 65]
#define NUM_REGS 8
#define MEM_SIZE 64
#define SECRET_SIZE 10
#define SECRET_OFFSET 20
#define CACHE_ENTRIES 12
#define CACHE_WORDS 24

#ifdef EVA
#include "__fc_builtin.h"
/*@ requires untainted: !\tainted(b);
    assigns \nothing; */
void koika_check(int b);
/*@ assigns *p \from \nothing;
    taints *p; */
void koika_mark(int *p);
#define koika_assert(b, s) koika_check(b)
#define koika_assume(b) do { if (!(b)) Frama_C_abort(); } while (0)
#define koika_draw(x) ((x) = Frama_C_interval(-2147483647-1, 2147483647))
#define koika_secret(x) koika_mark(&(x))
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
struct StateT * slot_1(struct StateT * x19);
struct StateT * slot_2(struct StateT * x219);
struct StateT * slot_0(struct StateT * x2);
struct StateT * snippet(struct StateT * x0) {
  struct StateT * x1 = slot_0(x0);
  return x1;
}

struct StateT * slot_1(struct StateT * x19) {
  int x20 = x19->timer;
  int x130 = x20 + 1;
  x19->timer = x130;
  int * x22 = x19->regs;
  int x23 = x22[0];
  int * x24 = x19->cache_tags;
  int x134 = (((int)((unsigned int)x23 >> 1)) & 1) * 2;
  int x25 = x24[x134];
  int x135 = ((((int)((unsigned int)x23 >> 1)) & 1) * 2) + 1;
  int x26 = x24[x135];
  int x136 = 4 + ((((int)((unsigned int)x23 >> 1)) & 3) * 2);
  int x27 = x24[x136];
  int x137 = (4 + ((((int)((unsigned int)x23 >> 1)) & 3) * 2)) + 1;
  int x28 = x24[x137];
  int x29 = x19->timer;
  int x138 = x29 + ((100 ^ (((~(((x27 ^ ((int)((unsigned int)x23 >> 1))) | (-(x27 ^ ((int)((unsigned int)x23 >> 1))))) >> 31)) | (~(((x28 ^ ((int)((unsigned int)x23 >> 1))) | (-(x28 ^ ((int)((unsigned int)x23 >> 1))))) >> 31))) & 104)) ^ (((~(((x25 ^ ((int)((unsigned int)x23 >> 1))) | (-(x25 ^ ((int)((unsigned int)x23 >> 1))))) >> 31)) | (~(((x26 ^ ((int)((unsigned int)x23 >> 1))) | (-(x26 ^ ((int)((unsigned int)x23 >> 1))))) >> 31))) & (1 ^ (100 ^ (((~(((x27 ^ ((int)((unsigned int)x23 >> 1))) | (-(x27 ^ ((int)((unsigned int)x23 >> 1))))) >> 31)) | (~(((x28 ^ ((int)((unsigned int)x23 >> 1))) | (-(x28 ^ ((int)((unsigned int)x23 >> 1))))) >> 31))) & 104)))));
  x19->timer = x138;
  int * x31 = x19->cache_vals;
  bool x139 = !(((~(((x25 ^ ((int)((unsigned int)x23 >> 1))) | (-(x25 ^ ((int)((unsigned int)x23 >> 1))))) >> 31)) | (~(((x26 ^ ((int)((unsigned int)x23 >> 1))) | (-(x26 ^ ((int)((unsigned int)x23 >> 1))))) >> 31))) == 0);
  int x124;
  if (x139) {
    int * x32 = x19->cache_age;
    int x141 = ((((int)((unsigned int)x23 >> 1)) & 1) * 2) + ((~(((x26 ^ ((int)((unsigned int)x23 >> 1))) | (-(x26 ^ ((int)((unsigned int)x23 >> 1))))) >> 31)) & 1);
    int x33 = x32[x141];
    int x34 = x32[x134];
    int x142 = x34 + ((int)((unsigned int)(x34 - x33) >> 31));
    x32[x134] = x142;
    int * x36 = x19->cache_age;
    int x37 = x36[x135];
    int x144 = x37 + ((int)((unsigned int)(x37 - x33) >> 31));
    x36[x135] = x144;
    int * x39 = x19->cache_age;
    x39[x141] = 0;
    x124 = x141;
  } else {
    int * x42 = x19->cache_age;
    int x147 = (((int)((unsigned int)x23 >> 1)) & 1) * 2;
    int x43 = x42[x147];
    int * x44 = x19->cache_tags;
    int x45 = x44[x147];
    int x46 = x42[x135];
    int x47 = x44[x135];
    bool x149 = !(((~(((x27 ^ ((int)((unsigned int)x23 >> 1))) | (-(x27 ^ ((int)((unsigned int)x23 >> 1))))) >> 31)) | (~(((x28 ^ ((int)((unsigned int)x23 >> 1))) | (-(x28 ^ ((int)((unsigned int)x23 >> 1))))) >> 31))) == 0);
    int x101;
    if (x149) {
      int * x48 = x19->cache_age;
      int x151 = (4 + ((((int)((unsigned int)x23 >> 1)) & 3) * 2)) + ((~(((x28 ^ ((int)((unsigned int)x23 >> 1))) | (-(x28 ^ ((int)((unsigned int)x23 >> 1))))) >> 31)) & 1);
      int x49 = x48[x151];
      int x50 = x48[x136];
      int x152 = x50 + ((int)((unsigned int)(x50 - x49) >> 31));
      x48[x136] = x152;
      int * x52 = x19->cache_age;
      int x53 = x52[x137];
      int x154 = x53 + ((int)((unsigned int)(x53 - x49) >> 31));
      x52[x137] = x154;
      int * x55 = x19->cache_age;
      x55[x151] = 0;
      x101 = x151;
    } else {
      int * x58 = x19->cache_age;
      int x157 = 4 + ((((int)((unsigned int)x23 >> 1)) & 3) * 2);
      int x59 = x58[x157];
      int * x60 = x19->cache_tags;
      int x61 = x60[x157];
      int x62 = x58[x137];
      int x63 = x60[x137];
      int * x64 = x19->cache_dirty;
      int x160 = (4 + ((((int)((unsigned int)x23 >> 1)) & 3) * 2)) + ((((x59 + ((~(((x61 ^ -1) | (-(x61 ^ -1))) >> 31)) & 2)) - (x62 + ((~(((x63 ^ -1) | (-(x63 ^ -1))) >> 31)) & 2))) >> 31) & 1);
      int x65 = x64[x160];
      bool x161 = !(x65 == 0);
      if (x161) {
        int * x66 = x19->cache_tags;
        int x67 = x66[x160];
        int * x68 = x19->cache_vals;
        int x164 = ((4 + ((((int)((unsigned int)x23 >> 1)) & 3) * 2)) + ((((x59 + ((~(((x61 ^ -1) | (-(x61 ^ -1))) >> 31)) & 2)) - (x62 + ((~(((x63 ^ -1) | (-(x63 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
        int x69 = x68[x164];
        int x165 = (((4 + ((((int)((unsigned int)x23 >> 1)) & 3) * 2)) + ((((x59 + ((~(((x61 ^ -1) | (-(x61 ^ -1))) >> 31)) & 2)) - (x62 + ((~(((x63 ^ -1) | (-(x63 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
        int x70 = x68[x165];
        int * x71 = x19->mem;
        int x167 = x67 * 2;
        x71[x167] = x69;
        int * x73 = x19->mem;
        int x170 = (x67 * 2) + 1;
        x73[x170] = x70;
        ;
      } else {
        ;
      }
      int * x78 = x19->mem;
      int x175 = ((int)((unsigned int)x23 >> 1)) * 2;
      int x79 = x78[x175];
      int x176 = (((int)((unsigned int)x23 >> 1)) * 2) + 1;
      int x80 = x78[x176];
      int * x81 = x19->cache_vals;
      int x178 = ((4 + ((((int)((unsigned int)x23 >> 1)) & 3) * 2)) + ((((x59 + ((~(((x61 ^ -1) | (-(x61 ^ -1))) >> 31)) & 2)) - (x62 + ((~(((x63 ^ -1) | (-(x63 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
      x81[x178] = x79;
      int * x83 = x19->cache_vals;
      int x181 = (((4 + ((((int)((unsigned int)x23 >> 1)) & 3) * 2)) + ((((x59 + ((~(((x61 ^ -1) | (-(x61 ^ -1))) >> 31)) & 2)) - (x62 + ((~(((x63 ^ -1) | (-(x63 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
      x83[x181] = x80;
      int * x85 = x19->cache_tags;
      int x184 = (int)((unsigned int)x23 >> 1);
      x85[x160] = x184;
      int * x87 = x19->cache_dirty;
      x87[x160] = 0;
      int * x89 = x19->cache_age;
      x89[x160] = 1;
      int * x91 = x19->cache_age;
      int x92 = x91[x160];
      int x93 = x91[x136];
      int x189 = x93 + ((int)((unsigned int)(x93 - x92) >> 31));
      x91[x136] = x189;
      int * x95 = x19->cache_age;
      int x96 = x95[x137];
      int x191 = x96 + ((int)((unsigned int)(x96 - x92) >> 31));
      x95[x137] = x191;
      int * x98 = x19->cache_age;
      x98[x160] = 0;
      x101 = x160;
    }
    int * x102 = x19->cache_vals;
    int x194 = x101 * 2;
    int x103 = x102[x194];
    int x195 = (x101 * 2) + 1;
    int x104 = x102[x195];
    int x196 = (((((int)((unsigned int)x23 >> 1)) & 1) * 2) + ((((x43 + ((~(((x45 ^ -1) | (-(x45 ^ -1))) >> 31)) & 2)) - (x46 + ((~(((x47 ^ -1) | (-(x47 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
    x102[x196] = x103;
    int * x106 = x19->cache_vals;
    int x199 = ((((((int)((unsigned int)x23 >> 1)) & 1) * 2) + ((((x43 + ((~(((x45 ^ -1) | (-(x45 ^ -1))) >> 31)) & 2)) - (x46 + ((~(((x47 ^ -1) | (-(x47 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
    x106[x199] = x104;
    int * x108 = x19->cache_tags;
    int x202 = ((((int)((unsigned int)x23 >> 1)) & 1) * 2) + ((((x43 + ((~(((x45 ^ -1) | (-(x45 ^ -1))) >> 31)) & 2)) - (x46 + ((~(((x47 ^ -1) | (-(x47 ^ -1))) >> 31)) & 2))) >> 31) & 1);
    int x203 = (int)((unsigned int)x23 >> 1);
    x108[x202] = x203;
    int * x110 = x19->cache_dirty;
    x110[x202] = 0;
    int * x112 = x19->cache_age;
    x112[x202] = 1;
    int * x114 = x19->cache_age;
    int x115 = x114[x202];
    int x116 = x114[x134];
    int x208 = x116 + ((int)((unsigned int)(x116 - x115) >> 31));
    x114[x134] = x208;
    int * x118 = x19->cache_age;
    int x119 = x118[x135];
    int x210 = x119 + ((int)((unsigned int)(x119 - x115) >> 31));
    x118[x135] = x210;
    int * x121 = x19->cache_age;
    x121[x202] = 0;
    x124 = x202;
  }
  int x213 = (x124 * 2) + (x23 & 1);
  int x125 = x31[x213];
  int * x126 = x19->regs;
  x126[1] = x125;
  struct StateT * x128 = slot_2(x19);
  return x128;
}

struct StateT * slot_2(struct StateT * x219) {
  int x220 = x219->timer;
  int x329 = x220 + 1;
  x219->timer = x329;
  int * x222 = x219->regs;
  int x223 = x222[1];
  int * x224 = x219->cache_tags;
  int x333 = (((int)((unsigned int)(x223 + 4) >> 1)) & 1) * 2;
  int x225 = x224[x333];
  int x334 = ((((int)((unsigned int)(x223 + 4) >> 1)) & 1) * 2) + 1;
  int x226 = x224[x334];
  int x335 = 4 + ((((int)((unsigned int)(x223 + 4) >> 1)) & 3) * 2);
  int x227 = x224[x335];
  int x336 = (4 + ((((int)((unsigned int)(x223 + 4) >> 1)) & 3) * 2)) + 1;
  int x228 = x224[x336];
  int x229 = x219->timer;
  int x337 = x229 + ((100 ^ (((~(((x227 ^ ((int)((unsigned int)(x223 + 4) >> 1))) | (-(x227 ^ ((int)((unsigned int)(x223 + 4) >> 1))))) >> 31)) | (~(((x228 ^ ((int)((unsigned int)(x223 + 4) >> 1))) | (-(x228 ^ ((int)((unsigned int)(x223 + 4) >> 1))))) >> 31))) & 104)) ^ (((~(((x225 ^ ((int)((unsigned int)(x223 + 4) >> 1))) | (-(x225 ^ ((int)((unsigned int)(x223 + 4) >> 1))))) >> 31)) | (~(((x226 ^ ((int)((unsigned int)(x223 + 4) >> 1))) | (-(x226 ^ ((int)((unsigned int)(x223 + 4) >> 1))))) >> 31))) & (1 ^ (100 ^ (((~(((x227 ^ ((int)((unsigned int)(x223 + 4) >> 1))) | (-(x227 ^ ((int)((unsigned int)(x223 + 4) >> 1))))) >> 31)) | (~(((x228 ^ ((int)((unsigned int)(x223 + 4) >> 1))) | (-(x228 ^ ((int)((unsigned int)(x223 + 4) >> 1))))) >> 31))) & 104)))));
  x219->timer = x337;
  int * x231 = x219->cache_vals;
  bool x338 = !(((~(((x225 ^ ((int)((unsigned int)(x223 + 4) >> 1))) | (-(x225 ^ ((int)((unsigned int)(x223 + 4) >> 1))))) >> 31)) | (~(((x226 ^ ((int)((unsigned int)(x223 + 4) >> 1))) | (-(x226 ^ ((int)((unsigned int)(x223 + 4) >> 1))))) >> 31))) == 0);
  int x324;
  if (x338) {
    int * x232 = x219->cache_age;
    int x340 = ((((int)((unsigned int)(x223 + 4) >> 1)) & 1) * 2) + ((~(((x226 ^ ((int)((unsigned int)(x223 + 4) >> 1))) | (-(x226 ^ ((int)((unsigned int)(x223 + 4) >> 1))))) >> 31)) & 1);
    int x233 = x232[x340];
    int x234 = x232[x333];
    int x341 = x234 + ((int)((unsigned int)(x234 - x233) >> 31));
    x232[x333] = x341;
    int * x236 = x219->cache_age;
    int x237 = x236[x334];
    int x343 = x237 + ((int)((unsigned int)(x237 - x233) >> 31));
    x236[x334] = x343;
    int * x239 = x219->cache_age;
    x239[x340] = 0;
    x324 = x340;
  } else {
    int * x242 = x219->cache_age;
    int x347 = (((int)((unsigned int)(x223 + 4) >> 1)) & 1) * 2;
    int x243 = x242[x347];
    int * x244 = x219->cache_tags;
    int x245 = x244[x347];
    int x246 = x242[x334];
    int x247 = x244[x334];
    bool x349 = !(((~(((x227 ^ ((int)((unsigned int)(x223 + 4) >> 1))) | (-(x227 ^ ((int)((unsigned int)(x223 + 4) >> 1))))) >> 31)) | (~(((x228 ^ ((int)((unsigned int)(x223 + 4) >> 1))) | (-(x228 ^ ((int)((unsigned int)(x223 + 4) >> 1))))) >> 31))) == 0);
    int x301;
    if (x349) {
      int * x248 = x219->cache_age;
      int x351 = (4 + ((((int)((unsigned int)(x223 + 4) >> 1)) & 3) * 2)) + ((~(((x228 ^ ((int)((unsigned int)(x223 + 4) >> 1))) | (-(x228 ^ ((int)((unsigned int)(x223 + 4) >> 1))))) >> 31)) & 1);
      int x249 = x248[x351];
      int x250 = x248[x335];
      int x352 = x250 + ((int)((unsigned int)(x250 - x249) >> 31));
      x248[x335] = x352;
      int * x252 = x219->cache_age;
      int x253 = x252[x336];
      int x354 = x253 + ((int)((unsigned int)(x253 - x249) >> 31));
      x252[x336] = x354;
      int * x255 = x219->cache_age;
      x255[x351] = 0;
      x301 = x351;
    } else {
      int * x258 = x219->cache_age;
      int x358 = 4 + ((((int)((unsigned int)(x223 + 4) >> 1)) & 3) * 2);
      int x259 = x258[x358];
      int * x260 = x219->cache_tags;
      int x261 = x260[x358];
      int x262 = x258[x336];
      int x263 = x260[x336];
      int * x264 = x219->cache_dirty;
      int x361 = (4 + ((((int)((unsigned int)(x223 + 4) >> 1)) & 3) * 2)) + ((((x259 + ((~(((x261 ^ -1) | (-(x261 ^ -1))) >> 31)) & 2)) - (x262 + ((~(((x263 ^ -1) | (-(x263 ^ -1))) >> 31)) & 2))) >> 31) & 1);
      int x265 = x264[x361];
      bool x362 = !(x265 == 0);
      if (x362) {
        int * x266 = x219->cache_tags;
        int x267 = x266[x361];
        int * x268 = x219->cache_vals;
        int x365 = ((4 + ((((int)((unsigned int)(x223 + 4) >> 1)) & 3) * 2)) + ((((x259 + ((~(((x261 ^ -1) | (-(x261 ^ -1))) >> 31)) & 2)) - (x262 + ((~(((x263 ^ -1) | (-(x263 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
        int x269 = x268[x365];
        int x366 = (((4 + ((((int)((unsigned int)(x223 + 4) >> 1)) & 3) * 2)) + ((((x259 + ((~(((x261 ^ -1) | (-(x261 ^ -1))) >> 31)) & 2)) - (x262 + ((~(((x263 ^ -1) | (-(x263 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
        int x270 = x268[x366];
        int * x271 = x219->mem;
        int x368 = x267 * 2;
        x271[x368] = x269;
        int * x273 = x219->mem;
        int x371 = (x267 * 2) + 1;
        x273[x371] = x270;
        ;
      } else {
        ;
      }
      int * x278 = x219->mem;
      int x376 = ((int)((unsigned int)(x223 + 4) >> 1)) * 2;
      int x279 = x278[x376];
      int x377 = (((int)((unsigned int)(x223 + 4) >> 1)) * 2) + 1;
      int x280 = x278[x377];
      int * x281 = x219->cache_vals;
      int x379 = ((4 + ((((int)((unsigned int)(x223 + 4) >> 1)) & 3) * 2)) + ((((x259 + ((~(((x261 ^ -1) | (-(x261 ^ -1))) >> 31)) & 2)) - (x262 + ((~(((x263 ^ -1) | (-(x263 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
      x281[x379] = x279;
      int * x283 = x219->cache_vals;
      int x382 = (((4 + ((((int)((unsigned int)(x223 + 4) >> 1)) & 3) * 2)) + ((((x259 + ((~(((x261 ^ -1) | (-(x261 ^ -1))) >> 31)) & 2)) - (x262 + ((~(((x263 ^ -1) | (-(x263 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
      x283[x382] = x280;
      int * x285 = x219->cache_tags;
      int x385 = (int)((unsigned int)(x223 + 4) >> 1);
      x285[x361] = x385;
      int * x287 = x219->cache_dirty;
      x287[x361] = 0;
      int * x289 = x219->cache_age;
      x289[x361] = 1;
      int * x291 = x219->cache_age;
      int x292 = x291[x361];
      int x293 = x291[x335];
      int x390 = x293 + ((int)((unsigned int)(x293 - x292) >> 31));
      x291[x335] = x390;
      int * x295 = x219->cache_age;
      int x296 = x295[x336];
      int x392 = x296 + ((int)((unsigned int)(x296 - x292) >> 31));
      x295[x336] = x392;
      int * x298 = x219->cache_age;
      x298[x361] = 0;
      x301 = x361;
    }
    int * x302 = x219->cache_vals;
    int x395 = x301 * 2;
    int x303 = x302[x395];
    int x396 = (x301 * 2) + 1;
    int x304 = x302[x396];
    int x397 = (((((int)((unsigned int)(x223 + 4) >> 1)) & 1) * 2) + ((((x243 + ((~(((x245 ^ -1) | (-(x245 ^ -1))) >> 31)) & 2)) - (x246 + ((~(((x247 ^ -1) | (-(x247 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
    x302[x397] = x303;
    int * x306 = x219->cache_vals;
    int x400 = ((((((int)((unsigned int)(x223 + 4) >> 1)) & 1) * 2) + ((((x243 + ((~(((x245 ^ -1) | (-(x245 ^ -1))) >> 31)) & 2)) - (x246 + ((~(((x247 ^ -1) | (-(x247 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
    x306[x400] = x304;
    int * x308 = x219->cache_tags;
    int x403 = ((((int)((unsigned int)(x223 + 4) >> 1)) & 1) * 2) + ((((x243 + ((~(((x245 ^ -1) | (-(x245 ^ -1))) >> 31)) & 2)) - (x246 + ((~(((x247 ^ -1) | (-(x247 ^ -1))) >> 31)) & 2))) >> 31) & 1);
    int x404 = (int)((unsigned int)(x223 + 4) >> 1);
    x308[x403] = x404;
    int * x310 = x219->cache_dirty;
    x310[x403] = 0;
    int * x312 = x219->cache_age;
    x312[x403] = 1;
    int * x314 = x219->cache_age;
    int x315 = x314[x403];
    int x316 = x314[x333];
    int x409 = x316 + ((int)((unsigned int)(x316 - x315) >> 31));
    x314[x333] = x409;
    int * x318 = x219->cache_age;
    int x319 = x318[x334];
    int x411 = x319 + ((int)((unsigned int)(x319 - x315) >> 31));
    x318[x334] = x411;
    int * x321 = x219->cache_age;
    x321[x403] = 0;
    x324 = x403;
  }
  int x414 = (x324 * 2) + ((x223 + 4) & 1);
  int x325 = x231[x414];
  int * x326 = x219->regs;
  x326[2] = x325;
  return x219;
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