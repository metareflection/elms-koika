// verify: clean (CBMC should report VERIFICATION SUCCESSFUL) [unwind 65]
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
struct StateT * slot_1(struct StateT * x15);
struct StateT * slot_4(struct StateT * x295);
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

struct StateT * slot_4(struct StateT * x295) {
  int x296 = x295->timer;
  int x428 = x296 + 1;
  x295->timer = x428;
  int * x298 = x295->regs;
  int x299 = x298[1];
  int * x300 = x295->cache_tags;
  int x432 = (((int)((unsigned int)x299 >> 1)) & 1) * 2;
  int x301 = x300[x432];
  int * x302 = x295->cache_tags;
  int x434 = ((((int)((unsigned int)x299 >> 1)) & 1) * 2) + 1;
  int x303 = x302[x434];
  int * x304 = x295->cache_tags;
  int x436 = 4 + ((((int)((unsigned int)x299 >> 1)) & 3) * 2);
  int x305 = x304[x436];
  int * x306 = x295->cache_tags;
  int x438 = (4 + ((((int)((unsigned int)x299 >> 1)) & 3) * 2)) + 1;
  int x307 = x306[x438];
  int x308 = x295->timer;
  int x439 = x308 + ((100 ^ (((~(((x305 ^ ((int)((unsigned int)x299 >> 1))) | (-(x305 ^ ((int)((unsigned int)x299 >> 1))))) >> 31)) | (~(((x307 ^ ((int)((unsigned int)x299 >> 1))) | (-(x307 ^ ((int)((unsigned int)x299 >> 1))))) >> 31))) & 104)) ^ (((~(((x301 ^ ((int)((unsigned int)x299 >> 1))) | (-(x301 ^ ((int)((unsigned int)x299 >> 1))))) >> 31)) | (~(((x303 ^ ((int)((unsigned int)x299 >> 1))) | (-(x303 ^ ((int)((unsigned int)x299 >> 1))))) >> 31))) & (1 ^ (100 ^ (((~(((x305 ^ ((int)((unsigned int)x299 >> 1))) | (-(x305 ^ ((int)((unsigned int)x299 >> 1))))) >> 31)) | (~(((x307 ^ ((int)((unsigned int)x299 >> 1))) | (-(x307 ^ ((int)((unsigned int)x299 >> 1))))) >> 31))) & 104)))));
  x295->timer = x439;
  int * x310 = x295->cache_vals;
  bool x440 = !(((~(((x301 ^ ((int)((unsigned int)x299 >> 1))) | (-(x301 ^ ((int)((unsigned int)x299 >> 1))))) >> 31)) | (~(((x303 ^ ((int)((unsigned int)x299 >> 1))) | (-(x303 ^ ((int)((unsigned int)x299 >> 1))))) >> 31))) == 0);
  int x423;
  if (x440) {
    int * x311 = x295->cache_age;
    int x442 = ((((int)((unsigned int)x299 >> 1)) & 1) * 2) + ((~(((x303 ^ ((int)((unsigned int)x299 >> 1))) | (-(x303 ^ ((int)((unsigned int)x299 >> 1))))) >> 31)) & 1);
    int x312 = x311[x442];
    int * x313 = x295->cache_age;
    int x314 = x313[x432];
    int * x315 = x295->cache_age;
    int x445 = x314 + ((int)((unsigned int)(x314 - x312) >> 31));
    x315[x432] = x445;
    int * x317 = x295->cache_age;
    int x318 = x317[x434];
    int * x319 = x295->cache_age;
    int x448 = x318 + ((int)((unsigned int)(x318 - x312) >> 31));
    x319[x434] = x448;
    int * x321 = x295->cache_age;
    x321[x442] = 0;
    x423 = x442;
  } else {
    int * x324 = x295->cache_age;
    int x452 = (((int)((unsigned int)x299 >> 1)) & 1) * 2;
    int x325 = x324[x452];
    int * x326 = x295->cache_tags;
    int x327 = x326[x452];
    int * x328 = x295->cache_age;
    int x329 = x328[x434];
    int * x330 = x295->cache_tags;
    int x331 = x330[x434];
    bool x456 = !(((~(((x305 ^ ((int)((unsigned int)x299 >> 1))) | (-(x305 ^ ((int)((unsigned int)x299 >> 1))))) >> 31)) | (~(((x307 ^ ((int)((unsigned int)x299 >> 1))) | (-(x307 ^ ((int)((unsigned int)x299 >> 1))))) >> 31))) == 0);
    int x395;
    if (x456) {
      int * x332 = x295->cache_age;
      int x458 = (4 + ((((int)((unsigned int)x299 >> 1)) & 3) * 2)) + ((~(((x307 ^ ((int)((unsigned int)x299 >> 1))) | (-(x307 ^ ((int)((unsigned int)x299 >> 1))))) >> 31)) & 1);
      int x333 = x332[x458];
      int * x334 = x295->cache_age;
      int x335 = x334[x436];
      int * x336 = x295->cache_age;
      int x461 = x335 + ((int)((unsigned int)(x335 - x333) >> 31));
      x336[x436] = x461;
      int * x338 = x295->cache_age;
      int x339 = x338[x438];
      int * x340 = x295->cache_age;
      int x464 = x339 + ((int)((unsigned int)(x339 - x333) >> 31));
      x340[x438] = x464;
      int * x342 = x295->cache_age;
      x342[x458] = 0;
      x395 = x458;
    } else {
      int * x345 = x295->cache_age;
      int x468 = 4 + ((((int)((unsigned int)x299 >> 1)) & 3) * 2);
      int x346 = x345[x468];
      int * x347 = x295->cache_tags;
      int x348 = x347[x468];
      int * x349 = x295->cache_age;
      int x350 = x349[x438];
      int * x351 = x295->cache_tags;
      int x352 = x351[x438];
      int * x353 = x295->cache_dirty;
      int x473 = (4 + ((((int)((unsigned int)x299 >> 1)) & 3) * 2)) + ((((x346 + ((~(((x348 ^ -1) | (-(x348 ^ -1))) >> 31)) & 2)) - (x350 + ((~(((x352 ^ -1) | (-(x352 ^ -1))) >> 31)) & 2))) >> 31) & 1);
      int x354 = x353[x473];
      bool x474 = !(x354 == 0);
      if (x474) {
        int * x355 = x295->cache_tags;
        int x356 = x355[x473];
        int * x357 = x295->cache_vals;
        int x477 = ((4 + ((((int)((unsigned int)x299 >> 1)) & 3) * 2)) + ((((x346 + ((~(((x348 ^ -1) | (-(x348 ^ -1))) >> 31)) & 2)) - (x350 + ((~(((x352 ^ -1) | (-(x352 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
        int x358 = x357[x477];
        int * x359 = x295->cache_vals;
        int x479 = (((4 + ((((int)((unsigned int)x299 >> 1)) & 3) * 2)) + ((((x346 + ((~(((x348 ^ -1) | (-(x348 ^ -1))) >> 31)) & 2)) - (x350 + ((~(((x352 ^ -1) | (-(x352 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
        int x360 = x359[x479];
        int * x361 = x295->mem;
        int x481 = x356 * 2;
        x361[x481] = x358;
        int * x363 = x295->mem;
        int x484 = (x356 * 2) + 1;
        x363[x484] = x360;
        ;
      } else {
        ;
      }
      int * x368 = x295->mem;
      int x489 = ((int)((unsigned int)x299 >> 1)) * 2;
      int x369 = x368[x489];
      int * x370 = x295->mem;
      int x491 = (((int)((unsigned int)x299 >> 1)) * 2) + 1;
      int x371 = x370[x491];
      int * x372 = x295->cache_vals;
      int x493 = ((4 + ((((int)((unsigned int)x299 >> 1)) & 3) * 2)) + ((((x346 + ((~(((x348 ^ -1) | (-(x348 ^ -1))) >> 31)) & 2)) - (x350 + ((~(((x352 ^ -1) | (-(x352 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
      x372[x493] = x369;
      int * x374 = x295->cache_vals;
      int x496 = (((4 + ((((int)((unsigned int)x299 >> 1)) & 3) * 2)) + ((((x346 + ((~(((x348 ^ -1) | (-(x348 ^ -1))) >> 31)) & 2)) - (x350 + ((~(((x352 ^ -1) | (-(x352 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
      x374[x496] = x371;
      int * x376 = x295->cache_tags;
      int x499 = (int)((unsigned int)x299 >> 1);
      x376[x473] = x499;
      int * x378 = x295->cache_dirty;
      x378[x473] = 0;
      int * x380 = x295->cache_age;
      x380[x473] = 1;
      int * x382 = x295->cache_age;
      int x383 = x382[x473];
      int * x384 = x295->cache_age;
      int x385 = x384[x436];
      int * x386 = x295->cache_age;
      int x506 = x385 + ((int)((unsigned int)(x385 - x383) >> 31));
      x386[x436] = x506;
      int * x388 = x295->cache_age;
      int x389 = x388[x438];
      int * x390 = x295->cache_age;
      int x509 = x389 + ((int)((unsigned int)(x389 - x383) >> 31));
      x390[x438] = x509;
      int * x392 = x295->cache_age;
      x392[x473] = 0;
      x395 = x473;
    }
    int * x396 = x295->cache_vals;
    int x512 = x395 * 2;
    int x397 = x396[x512];
    int * x398 = x295->cache_vals;
    int x514 = (x395 * 2) + 1;
    int x399 = x398[x514];
    int * x400 = x295->cache_vals;
    int x516 = (((((int)((unsigned int)x299 >> 1)) & 1) * 2) + ((((x325 + ((~(((x327 ^ -1) | (-(x327 ^ -1))) >> 31)) & 2)) - (x329 + ((~(((x331 ^ -1) | (-(x331 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
    x400[x516] = x397;
    int * x402 = x295->cache_vals;
    int x519 = ((((((int)((unsigned int)x299 >> 1)) & 1) * 2) + ((((x325 + ((~(((x327 ^ -1) | (-(x327 ^ -1))) >> 31)) & 2)) - (x329 + ((~(((x331 ^ -1) | (-(x331 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
    x402[x519] = x399;
    int * x404 = x295->cache_tags;
    int x522 = ((((int)((unsigned int)x299 >> 1)) & 1) * 2) + ((((x325 + ((~(((x327 ^ -1) | (-(x327 ^ -1))) >> 31)) & 2)) - (x329 + ((~(((x331 ^ -1) | (-(x331 ^ -1))) >> 31)) & 2))) >> 31) & 1);
    int x523 = (int)((unsigned int)x299 >> 1);
    x404[x522] = x523;
    int * x406 = x295->cache_dirty;
    x406[x522] = 0;
    int * x408 = x295->cache_age;
    x408[x522] = 1;
    int * x410 = x295->cache_age;
    int x411 = x410[x522];
    int * x412 = x295->cache_age;
    int x413 = x412[x432];
    int * x414 = x295->cache_age;
    int x530 = x413 + ((int)((unsigned int)(x413 - x411) >> 31));
    x414[x432] = x530;
    int * x416 = x295->cache_age;
    int x417 = x416[x434];
    int * x418 = x295->cache_age;
    int x533 = x417 + ((int)((unsigned int)(x417 - x411) >> 31));
    x418[x434] = x533;
    int * x420 = x295->cache_age;
    x420[x522] = 0;
    x423 = x522;
  }
  int x536 = (x423 * 2) + (x299 & 1);
  int x424 = x310[x536];
  int * x425 = x295->regs;
  x425[2] = x424;
  return x295;
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
  int x181 = x46 + 1;
  x45->timer = x181;
  int * x48 = x45->regs;
  int x49 = x48[3];
  int * x50 = x45->regs;
  int x51 = x50[0];
  int * x52 = x45->cache_tags;
  int x187 = (((int)((unsigned int)(x49 + x51) >> 1)) & 1) * 2;
  int x53 = x52[x187];
  int * x54 = x45->cache_tags;
  int x189 = ((((int)((unsigned int)(x49 + x51) >> 1)) & 1) * 2) + 1;
  int x55 = x54[x189];
  int * x56 = x45->cache_tags;
  int x191 = 4 + ((((int)((unsigned int)(x49 + x51) >> 1)) & 3) * 2);
  int x57 = x56[x191];
  int * x58 = x45->cache_tags;
  int x193 = (4 + ((((int)((unsigned int)(x49 + x51) >> 1)) & 3) * 2)) + 1;
  int x59 = x58[x193];
  int x60 = x45->timer;
  int x194 = x60 + ((100 ^ (((~(((x57 ^ ((int)((unsigned int)(x49 + x51) >> 1))) | (-(x57 ^ ((int)((unsigned int)(x49 + x51) >> 1))))) >> 31)) | (~(((x59 ^ ((int)((unsigned int)(x49 + x51) >> 1))) | (-(x59 ^ ((int)((unsigned int)(x49 + x51) >> 1))))) >> 31))) & 104)) ^ (((~(((x53 ^ ((int)((unsigned int)(x49 + x51) >> 1))) | (-(x53 ^ ((int)((unsigned int)(x49 + x51) >> 1))))) >> 31)) | (~(((x55 ^ ((int)((unsigned int)(x49 + x51) >> 1))) | (-(x55 ^ ((int)((unsigned int)(x49 + x51) >> 1))))) >> 31))) & (1 ^ (100 ^ (((~(((x57 ^ ((int)((unsigned int)(x49 + x51) >> 1))) | (-(x57 ^ ((int)((unsigned int)(x49 + x51) >> 1))))) >> 31)) | (~(((x59 ^ ((int)((unsigned int)(x49 + x51) >> 1))) | (-(x59 ^ ((int)((unsigned int)(x49 + x51) >> 1))))) >> 31))) & 104)))));
  x45->timer = x194;
  int * x62 = x45->cache_vals;
  bool x195 = !(((~(((x53 ^ ((int)((unsigned int)(x49 + x51) >> 1))) | (-(x53 ^ ((int)((unsigned int)(x49 + x51) >> 1))))) >> 31)) | (~(((x55 ^ ((int)((unsigned int)(x49 + x51) >> 1))) | (-(x55 ^ ((int)((unsigned int)(x49 + x51) >> 1))))) >> 31))) == 0);
  int x175;
  if (x195) {
    int * x63 = x45->cache_age;
    int x197 = ((((int)((unsigned int)(x49 + x51) >> 1)) & 1) * 2) + ((~(((x55 ^ ((int)((unsigned int)(x49 + x51) >> 1))) | (-(x55 ^ ((int)((unsigned int)(x49 + x51) >> 1))))) >> 31)) & 1);
    int x64 = x63[x197];
    int * x65 = x45->cache_age;
    int x66 = x65[x187];
    int * x67 = x45->cache_age;
    int x200 = x66 + ((int)((unsigned int)(x66 - x64) >> 31));
    x67[x187] = x200;
    int * x69 = x45->cache_age;
    int x70 = x69[x189];
    int * x71 = x45->cache_age;
    int x203 = x70 + ((int)((unsigned int)(x70 - x64) >> 31));
    x71[x189] = x203;
    int * x73 = x45->cache_age;
    x73[x197] = 0;
    x175 = x197;
  } else {
    int * x76 = x45->cache_age;
    int x206 = (((int)((unsigned int)(x49 + x51) >> 1)) & 1) * 2;
    int x77 = x76[x206];
    int * x78 = x45->cache_tags;
    int x79 = x78[x206];
    int * x80 = x45->cache_age;
    int x81 = x80[x189];
    int * x82 = x45->cache_tags;
    int x83 = x82[x189];
    bool x210 = !(((~(((x57 ^ ((int)((unsigned int)(x49 + x51) >> 1))) | (-(x57 ^ ((int)((unsigned int)(x49 + x51) >> 1))))) >> 31)) | (~(((x59 ^ ((int)((unsigned int)(x49 + x51) >> 1))) | (-(x59 ^ ((int)((unsigned int)(x49 + x51) >> 1))))) >> 31))) == 0);
    int x147;
    if (x210) {
      int * x84 = x45->cache_age;
      int x212 = (4 + ((((int)((unsigned int)(x49 + x51) >> 1)) & 3) * 2)) + ((~(((x59 ^ ((int)((unsigned int)(x49 + x51) >> 1))) | (-(x59 ^ ((int)((unsigned int)(x49 + x51) >> 1))))) >> 31)) & 1);
      int x85 = x84[x212];
      int * x86 = x45->cache_age;
      int x87 = x86[x191];
      int * x88 = x45->cache_age;
      int x215 = x87 + ((int)((unsigned int)(x87 - x85) >> 31));
      x88[x191] = x215;
      int * x90 = x45->cache_age;
      int x91 = x90[x193];
      int * x92 = x45->cache_age;
      int x218 = x91 + ((int)((unsigned int)(x91 - x85) >> 31));
      x92[x193] = x218;
      int * x94 = x45->cache_age;
      x94[x212] = 0;
      x147 = x212;
    } else {
      int * x97 = x45->cache_age;
      int x221 = 4 + ((((int)((unsigned int)(x49 + x51) >> 1)) & 3) * 2);
      int x98 = x97[x221];
      int * x99 = x45->cache_tags;
      int x100 = x99[x221];
      int * x101 = x45->cache_age;
      int x102 = x101[x193];
      int * x103 = x45->cache_tags;
      int x104 = x103[x193];
      int * x105 = x45->cache_dirty;
      int x226 = (4 + ((((int)((unsigned int)(x49 + x51) >> 1)) & 3) * 2)) + ((((x98 + ((~(((x100 ^ -1) | (-(x100 ^ -1))) >> 31)) & 2)) - (x102 + ((~(((x104 ^ -1) | (-(x104 ^ -1))) >> 31)) & 2))) >> 31) & 1);
      int x106 = x105[x226];
      bool x227 = !(x106 == 0);
      if (x227) {
        int * x107 = x45->cache_tags;
        int x108 = x107[x226];
        int * x109 = x45->cache_vals;
        int x230 = ((4 + ((((int)((unsigned int)(x49 + x51) >> 1)) & 3) * 2)) + ((((x98 + ((~(((x100 ^ -1) | (-(x100 ^ -1))) >> 31)) & 2)) - (x102 + ((~(((x104 ^ -1) | (-(x104 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
        int x110 = x109[x230];
        int * x111 = x45->cache_vals;
        int x232 = (((4 + ((((int)((unsigned int)(x49 + x51) >> 1)) & 3) * 2)) + ((((x98 + ((~(((x100 ^ -1) | (-(x100 ^ -1))) >> 31)) & 2)) - (x102 + ((~(((x104 ^ -1) | (-(x104 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
        int x112 = x111[x232];
        int * x113 = x45->mem;
        int x234 = x108 * 2;
        x113[x234] = x110;
        int * x115 = x45->mem;
        int x237 = (x108 * 2) + 1;
        x115[x237] = x112;
        ;
      } else {
        ;
      }
      int * x120 = x45->mem;
      int x242 = ((int)((unsigned int)(x49 + x51) >> 1)) * 2;
      int x121 = x120[x242];
      int * x122 = x45->mem;
      int x244 = (((int)((unsigned int)(x49 + x51) >> 1)) * 2) + 1;
      int x123 = x122[x244];
      int * x124 = x45->cache_vals;
      int x246 = ((4 + ((((int)((unsigned int)(x49 + x51) >> 1)) & 3) * 2)) + ((((x98 + ((~(((x100 ^ -1) | (-(x100 ^ -1))) >> 31)) & 2)) - (x102 + ((~(((x104 ^ -1) | (-(x104 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
      x124[x246] = x121;
      int * x126 = x45->cache_vals;
      int x249 = (((4 + ((((int)((unsigned int)(x49 + x51) >> 1)) & 3) * 2)) + ((((x98 + ((~(((x100 ^ -1) | (-(x100 ^ -1))) >> 31)) & 2)) - (x102 + ((~(((x104 ^ -1) | (-(x104 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
      x126[x249] = x123;
      int * x128 = x45->cache_tags;
      int x252 = (int)((unsigned int)(x49 + x51) >> 1);
      x128[x226] = x252;
      int * x130 = x45->cache_dirty;
      x130[x226] = 0;
      int * x132 = x45->cache_age;
      x132[x226] = 1;
      int * x134 = x45->cache_age;
      int x135 = x134[x226];
      int * x136 = x45->cache_age;
      int x137 = x136[x191];
      int * x138 = x45->cache_age;
      int x259 = x137 + ((int)((unsigned int)(x137 - x135) >> 31));
      x138[x191] = x259;
      int * x140 = x45->cache_age;
      int x141 = x140[x193];
      int * x142 = x45->cache_age;
      int x262 = x141 + ((int)((unsigned int)(x141 - x135) >> 31));
      x142[x193] = x262;
      int * x144 = x45->cache_age;
      x144[x226] = 0;
      x147 = x226;
    }
    int * x148 = x45->cache_vals;
    int x265 = x147 * 2;
    int x149 = x148[x265];
    int * x150 = x45->cache_vals;
    int x267 = (x147 * 2) + 1;
    int x151 = x150[x267];
    int * x152 = x45->cache_vals;
    int x269 = (((((int)((unsigned int)(x49 + x51) >> 1)) & 1) * 2) + ((((x77 + ((~(((x79 ^ -1) | (-(x79 ^ -1))) >> 31)) & 2)) - (x81 + ((~(((x83 ^ -1) | (-(x83 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
    x152[x269] = x149;
    int * x154 = x45->cache_vals;
    int x272 = ((((((int)((unsigned int)(x49 + x51) >> 1)) & 1) * 2) + ((((x77 + ((~(((x79 ^ -1) | (-(x79 ^ -1))) >> 31)) & 2)) - (x81 + ((~(((x83 ^ -1) | (-(x83 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
    x154[x272] = x151;
    int * x156 = x45->cache_tags;
    int x275 = ((((int)((unsigned int)(x49 + x51) >> 1)) & 1) * 2) + ((((x77 + ((~(((x79 ^ -1) | (-(x79 ^ -1))) >> 31)) & 2)) - (x81 + ((~(((x83 ^ -1) | (-(x83 ^ -1))) >> 31)) & 2))) >> 31) & 1);
    int x276 = (int)((unsigned int)(x49 + x51) >> 1);
    x156[x275] = x276;
    int * x158 = x45->cache_dirty;
    x158[x275] = 0;
    int * x160 = x45->cache_age;
    x160[x275] = 1;
    int * x162 = x45->cache_age;
    int x163 = x162[x275];
    int * x164 = x45->cache_age;
    int x165 = x164[x187];
    int * x166 = x45->cache_age;
    int x283 = x165 + ((int)((unsigned int)(x165 - x163) >> 31));
    x166[x187] = x283;
    int * x168 = x45->cache_age;
    int x169 = x168[x189];
    int * x170 = x45->cache_age;
    int x286 = x169 + ((int)((unsigned int)(x169 - x163) >> 31));
    x170[x189] = x286;
    int * x172 = x45->cache_age;
    x172[x275] = 0;
    x175 = x275;
  }
  int x289 = (x175 * 2) + ((x49 + x51) & 1);
  int x176 = x62[x289];
  int * x177 = x45->regs;
  x177[1] = x176;
  struct StateT * x179 = slot_4(x45);
  return x179;
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