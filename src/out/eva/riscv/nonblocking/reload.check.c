// verify: clean (Eva should report untainted: Valid) [unroll 65]
#define NUM_REGS 32
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
  int regs[32];
  int mem[64];
  int saved_regs[32];
  int reg_ready[32];
  int cache_tags[12];
  int cache_dirty[12];
  int cache_age[12];
  int cache_vals[24];
  int timer;
};

struct StateT * slot_6(struct StateT * v503);
struct StateT * slot_5(struct StateT * v295);
struct StateT * slot_2(struct StateT * v34);
struct StateT * slot_7(struct StateT * v524);
struct StateT * slot_3(struct StateT * v50);
struct StateT * snippet(struct StateT * v0);
struct StateT * slot_1(struct StateT * v18);
struct StateT * slot_8(struct StateT * v76);
struct StateT * slot_4(struct StateT * v84);
struct StateT * slot_9(struct StateT * v109);
struct StateT * slot_0(struct StateT * v2);
struct StateT * slot_6(struct StateT * v503) {
  int v504 = v503->timer;
  int v515 = v504 + 1;
  v503->timer = v515;
  int * v506 = v503->reg_ready;
  int v507 = v506[11];
  int * v508 = v503->regs;
  int v509 = v508[11];
  int v519 = (v507 + ((v504 - v507) & (~((v504 - v507) >> 31)))) + 1;
  v506[11] = v519;
  int * v511 = v503->regs;
  int v521 = v509 << 2;
  v511[11] = v521;
  struct StateT * v513 = slot_7(v503);
  return v513;
}

struct StateT * slot_5(struct StateT * v295) {
  int v296 = v295->timer;
  int v408 = v296 + 1;
  v295->timer = v408;
  int * v298 = v295->reg_ready;
  int v299 = v298[5];
  int * v300 = v295->regs;
  int v301 = v300[5];
  int * v302 = v295->cache_tags;
  int v413 = (((int)((unsigned int)((int)((unsigned int)v301 >> 2)) >> 1)) & 1) * 2;
  int v303 = v302[v413];
  int v414 = ((((int)((unsigned int)((int)((unsigned int)v301 >> 2)) >> 1)) & 1) * 2) + 1;
  int v304 = v302[v414];
  int v415 = 4 + ((((int)((unsigned int)((int)((unsigned int)v301 >> 2)) >> 1)) & 3) * 2);
  int v305 = v302[v415];
  int v416 = (4 + ((((int)((unsigned int)((int)((unsigned int)v301 >> 2)) >> 1)) & 3) * 2)) + 1;
  int v306 = v302[v416];
  int * v307 = v295->cache_vals;
  bool v417 = !(((~(((v303 ^ ((int)((unsigned int)((int)((unsigned int)v301 >> 2)) >> 1))) | (-(v303 ^ ((int)((unsigned int)((int)((unsigned int)v301 >> 2)) >> 1))))) >> 31)) | (~(((v304 ^ ((int)((unsigned int)((int)((unsigned int)v301 >> 2)) >> 1))) | (-(v304 ^ ((int)((unsigned int)((int)((unsigned int)v301 >> 2)) >> 1))))) >> 31))) == 0);
  int v400;
  if (v417) {
    int * v308 = v295->cache_age;
    int v419 = ((((int)((unsigned int)((int)((unsigned int)v301 >> 2)) >> 1)) & 1) * 2) + ((~(((v304 ^ ((int)((unsigned int)((int)((unsigned int)v301 >> 2)) >> 1))) | (-(v304 ^ ((int)((unsigned int)((int)((unsigned int)v301 >> 2)) >> 1))))) >> 31)) & 1);
    int v309 = v308[v419];
    int v310 = v308[v413];
    int v420 = v310 + ((int)((unsigned int)(v310 - v309) >> 31));
    v308[v413] = v420;
    int * v312 = v295->cache_age;
    int v313 = v312[v414];
    int v422 = v313 + ((int)((unsigned int)(v313 - v309) >> 31));
    v312[v414] = v422;
    int * v315 = v295->cache_age;
    v315[v419] = 0;
    v400 = v419;
  } else {
    int * v318 = v295->cache_age;
    int v426 = (((int)((unsigned int)((int)((unsigned int)v301 >> 2)) >> 1)) & 1) * 2;
    int v319 = v318[v426];
    int * v320 = v295->cache_tags;
    int v321 = v320[v426];
    int v322 = v318[v414];
    int v323 = v320[v414];
    bool v428 = !(((~(((v305 ^ ((int)((unsigned int)((int)((unsigned int)v301 >> 2)) >> 1))) | (-(v305 ^ ((int)((unsigned int)((int)((unsigned int)v301 >> 2)) >> 1))))) >> 31)) | (~(((v306 ^ ((int)((unsigned int)((int)((unsigned int)v301 >> 2)) >> 1))) | (-(v306 ^ ((int)((unsigned int)((int)((unsigned int)v301 >> 2)) >> 1))))) >> 31))) == 0);
    int v377;
    if (v428) {
      int * v324 = v295->cache_age;
      int v430 = (4 + ((((int)((unsigned int)((int)((unsigned int)v301 >> 2)) >> 1)) & 3) * 2)) + ((~(((v306 ^ ((int)((unsigned int)((int)((unsigned int)v301 >> 2)) >> 1))) | (-(v306 ^ ((int)((unsigned int)((int)((unsigned int)v301 >> 2)) >> 1))))) >> 31)) & 1);
      int v325 = v324[v430];
      int v326 = v324[v415];
      int v431 = v326 + ((int)((unsigned int)(v326 - v325) >> 31));
      v324[v415] = v431;
      int * v328 = v295->cache_age;
      int v329 = v328[v416];
      int v433 = v329 + ((int)((unsigned int)(v329 - v325) >> 31));
      v328[v416] = v433;
      int * v331 = v295->cache_age;
      v331[v430] = 0;
      v377 = v430;
    } else {
      int * v334 = v295->cache_age;
      int v437 = 4 + ((((int)((unsigned int)((int)((unsigned int)v301 >> 2)) >> 1)) & 3) * 2);
      int v335 = v334[v437];
      int * v336 = v295->cache_tags;
      int v337 = v336[v437];
      int v338 = v334[v416];
      int v339 = v336[v416];
      int * v340 = v295->cache_dirty;
      int v440 = (4 + ((((int)((unsigned int)((int)((unsigned int)v301 >> 2)) >> 1)) & 3) * 2)) + ((((v335 + ((~(((v337 ^ -1) | (-(v337 ^ -1))) >> 31)) & 2)) - (v338 + ((~(((v339 ^ -1) | (-(v339 ^ -1))) >> 31)) & 2))) >> 31) & 1);
      int v341 = v340[v440];
      bool v441 = !(v341 == 0);
      if (v441) {
        int * v342 = v295->cache_tags;
        int v343 = v342[v440];
        int * v344 = v295->cache_vals;
        int v444 = ((4 + ((((int)((unsigned int)((int)((unsigned int)v301 >> 2)) >> 1)) & 3) * 2)) + ((((v335 + ((~(((v337 ^ -1) | (-(v337 ^ -1))) >> 31)) & 2)) - (v338 + ((~(((v339 ^ -1) | (-(v339 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
        int v345 = v344[v444];
        int v445 = (((4 + ((((int)((unsigned int)((int)((unsigned int)v301 >> 2)) >> 1)) & 3) * 2)) + ((((v335 + ((~(((v337 ^ -1) | (-(v337 ^ -1))) >> 31)) & 2)) - (v338 + ((~(((v339 ^ -1) | (-(v339 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
        int v346 = v344[v445];
        int * v347 = v295->mem;
        int v447 = v343 * 2;
        v347[v447] = v345;
        int * v349 = v295->mem;
        int v450 = (v343 * 2) + 1;
        v349[v450] = v346;
        ;
      } else {
        ;
      }
      int * v354 = v295->mem;
      int v455 = ((int)((unsigned int)((int)((unsigned int)v301 >> 2)) >> 1)) * 2;
      int v355 = v354[v455];
      int v456 = (((int)((unsigned int)((int)((unsigned int)v301 >> 2)) >> 1)) * 2) + 1;
      int v356 = v354[v456];
      int * v357 = v295->cache_vals;
      int v458 = ((4 + ((((int)((unsigned int)((int)((unsigned int)v301 >> 2)) >> 1)) & 3) * 2)) + ((((v335 + ((~(((v337 ^ -1) | (-(v337 ^ -1))) >> 31)) & 2)) - (v338 + ((~(((v339 ^ -1) | (-(v339 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
      v357[v458] = v355;
      int * v359 = v295->cache_vals;
      int v461 = (((4 + ((((int)((unsigned int)((int)((unsigned int)v301 >> 2)) >> 1)) & 3) * 2)) + ((((v335 + ((~(((v337 ^ -1) | (-(v337 ^ -1))) >> 31)) & 2)) - (v338 + ((~(((v339 ^ -1) | (-(v339 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
      v359[v461] = v356;
      int * v361 = v295->cache_tags;
      int v464 = (int)((unsigned int)((int)((unsigned int)v301 >> 2)) >> 1);
      v361[v440] = v464;
      int * v363 = v295->cache_dirty;
      v363[v440] = 0;
      int * v365 = v295->cache_age;
      v365[v440] = 1;
      int * v367 = v295->cache_age;
      int v368 = v367[v440];
      int v369 = v367[v415];
      int v470 = v369 + ((int)((unsigned int)(v369 - v368) >> 31));
      v367[v415] = v470;
      int * v371 = v295->cache_age;
      int v372 = v371[v416];
      int v472 = v372 + ((int)((unsigned int)(v372 - v368) >> 31));
      v371[v416] = v472;
      int * v374 = v295->cache_age;
      v374[v440] = 0;
      v377 = v440;
    }
    int * v378 = v295->cache_vals;
    int v475 = v377 * 2;
    int v379 = v378[v475];
    int v476 = (v377 * 2) + 1;
    int v380 = v378[v476];
    int v477 = (((((int)((unsigned int)((int)((unsigned int)v301 >> 2)) >> 1)) & 1) * 2) + ((((v319 + ((~(((v321 ^ -1) | (-(v321 ^ -1))) >> 31)) & 2)) - (v322 + ((~(((v323 ^ -1) | (-(v323 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
    v378[v477] = v379;
    int * v382 = v295->cache_vals;
    int v480 = ((((((int)((unsigned int)((int)((unsigned int)v301 >> 2)) >> 1)) & 1) * 2) + ((((v319 + ((~(((v321 ^ -1) | (-(v321 ^ -1))) >> 31)) & 2)) - (v322 + ((~(((v323 ^ -1) | (-(v323 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
    v382[v480] = v380;
    int * v384 = v295->cache_tags;
    int v483 = ((((int)((unsigned int)((int)((unsigned int)v301 >> 2)) >> 1)) & 1) * 2) + ((((v319 + ((~(((v321 ^ -1) | (-(v321 ^ -1))) >> 31)) & 2)) - (v322 + ((~(((v323 ^ -1) | (-(v323 ^ -1))) >> 31)) & 2))) >> 31) & 1);
    int v484 = (int)((unsigned int)((int)((unsigned int)v301 >> 2)) >> 1);
    v384[v483] = v484;
    int * v386 = v295->cache_dirty;
    v386[v483] = 0;
    int * v388 = v295->cache_age;
    v388[v483] = 1;
    int * v390 = v295->cache_age;
    int v391 = v390[v483];
    int v392 = v390[v413];
    int v490 = v392 + ((int)((unsigned int)(v392 - v391) >> 31));
    v390[v413] = v490;
    int * v394 = v295->cache_age;
    int v395 = v394[v414];
    int v492 = v395 + ((int)((unsigned int)(v395 - v391) >> 31));
    v394[v414] = v492;
    int * v397 = v295->cache_age;
    v397[v483] = 0;
    v400 = v483;
  }
  int v495 = (v400 * 2) + (((int)((unsigned int)v301 >> 2)) & 1);
  int v401 = v307[v495];
  int * v402 = v295->reg_ready;
  int v498 = ((v299 + ((v296 - v299) & (~((v296 - v299) >> 31)))) + 1) + ((100 ^ (((~(((v305 ^ ((int)((unsigned int)((int)((unsigned int)v301 >> 2)) >> 1))) | (-(v305 ^ ((int)((unsigned int)((int)((unsigned int)v301 >> 2)) >> 1))))) >> 31)) | (~(((v306 ^ ((int)((unsigned int)((int)((unsigned int)v301 >> 2)) >> 1))) | (-(v306 ^ ((int)((unsigned int)((int)((unsigned int)v301 >> 2)) >> 1))))) >> 31))) & 104)) ^ (((~(((v303 ^ ((int)((unsigned int)((int)((unsigned int)v301 >> 2)) >> 1))) | (-(v303 ^ ((int)((unsigned int)((int)((unsigned int)v301 >> 2)) >> 1))))) >> 31)) | (~(((v304 ^ ((int)((unsigned int)((int)((unsigned int)v301 >> 2)) >> 1))) | (-(v304 ^ ((int)((unsigned int)((int)((unsigned int)v301 >> 2)) >> 1))))) >> 31))) & (1 ^ (100 ^ (((~(((v305 ^ ((int)((unsigned int)((int)((unsigned int)v301 >> 2)) >> 1))) | (-(v305 ^ ((int)((unsigned int)((int)((unsigned int)v301 >> 2)) >> 1))))) >> 31)) | (~(((v306 ^ ((int)((unsigned int)((int)((unsigned int)v301 >> 2)) >> 1))) | (-(v306 ^ ((int)((unsigned int)((int)((unsigned int)v301 >> 2)) >> 1))))) >> 31))) & 104)))));
  v402[11] = v498;
  int * v404 = v295->regs;
  v404[11] = v401;
  struct StateT * v406 = slot_6(v295);
  return v406;
}

struct StateT * slot_2(struct StateT * v34) {
  int v35 = v34->timer;
  int v43 = v35 + 1;
  v34->timer = v43;
  int * v37 = v34->reg_ready;
  v37[15] = v43;
  int * v39 = v34->regs;
  v39[15] = 80;
  struct StateT * v41 = slot_3(v34);
  return v41;
}

struct StateT * slot_7(struct StateT * v524) {
  int v525 = v524->timer;
  int v637 = v525 + 1;
  v524->timer = v637;
  int * v527 = v524->reg_ready;
  int v528 = v527[11];
  int * v529 = v524->regs;
  int v530 = v529[11];
  int * v531 = v524->cache_tags;
  int v642 = (((int)((unsigned int)((int)((unsigned int)v530 >> 2)) >> 1)) & 1) * 2;
  int v532 = v531[v642];
  int v643 = ((((int)((unsigned int)((int)((unsigned int)v530 >> 2)) >> 1)) & 1) * 2) + 1;
  int v533 = v531[v643];
  int v644 = 4 + ((((int)((unsigned int)((int)((unsigned int)v530 >> 2)) >> 1)) & 3) * 2);
  int v534 = v531[v644];
  int v645 = (4 + ((((int)((unsigned int)((int)((unsigned int)v530 >> 2)) >> 1)) & 3) * 2)) + 1;
  int v535 = v531[v645];
  int * v536 = v524->cache_vals;
  bool v646 = !(((~(((v532 ^ ((int)((unsigned int)((int)((unsigned int)v530 >> 2)) >> 1))) | (-(v532 ^ ((int)((unsigned int)((int)((unsigned int)v530 >> 2)) >> 1))))) >> 31)) | (~(((v533 ^ ((int)((unsigned int)((int)((unsigned int)v530 >> 2)) >> 1))) | (-(v533 ^ ((int)((unsigned int)((int)((unsigned int)v530 >> 2)) >> 1))))) >> 31))) == 0);
  int v629;
  if (v646) {
    int * v537 = v524->cache_age;
    int v648 = ((((int)((unsigned int)((int)((unsigned int)v530 >> 2)) >> 1)) & 1) * 2) + ((~(((v533 ^ ((int)((unsigned int)((int)((unsigned int)v530 >> 2)) >> 1))) | (-(v533 ^ ((int)((unsigned int)((int)((unsigned int)v530 >> 2)) >> 1))))) >> 31)) & 1);
    int v538 = v537[v648];
    int v539 = v537[v642];
    int v649 = v539 + ((int)((unsigned int)(v539 - v538) >> 31));
    v537[v642] = v649;
    int * v541 = v524->cache_age;
    int v542 = v541[v643];
    int v651 = v542 + ((int)((unsigned int)(v542 - v538) >> 31));
    v541[v643] = v651;
    int * v544 = v524->cache_age;
    v544[v648] = 0;
    v629 = v648;
  } else {
    int * v547 = v524->cache_age;
    int v655 = (((int)((unsigned int)((int)((unsigned int)v530 >> 2)) >> 1)) & 1) * 2;
    int v548 = v547[v655];
    int * v549 = v524->cache_tags;
    int v550 = v549[v655];
    int v551 = v547[v643];
    int v552 = v549[v643];
    bool v657 = !(((~(((v534 ^ ((int)((unsigned int)((int)((unsigned int)v530 >> 2)) >> 1))) | (-(v534 ^ ((int)((unsigned int)((int)((unsigned int)v530 >> 2)) >> 1))))) >> 31)) | (~(((v535 ^ ((int)((unsigned int)((int)((unsigned int)v530 >> 2)) >> 1))) | (-(v535 ^ ((int)((unsigned int)((int)((unsigned int)v530 >> 2)) >> 1))))) >> 31))) == 0);
    int v606;
    if (v657) {
      int * v553 = v524->cache_age;
      int v659 = (4 + ((((int)((unsigned int)((int)((unsigned int)v530 >> 2)) >> 1)) & 3) * 2)) + ((~(((v535 ^ ((int)((unsigned int)((int)((unsigned int)v530 >> 2)) >> 1))) | (-(v535 ^ ((int)((unsigned int)((int)((unsigned int)v530 >> 2)) >> 1))))) >> 31)) & 1);
      int v554 = v553[v659];
      int v555 = v553[v644];
      int v660 = v555 + ((int)((unsigned int)(v555 - v554) >> 31));
      v553[v644] = v660;
      int * v557 = v524->cache_age;
      int v558 = v557[v645];
      int v662 = v558 + ((int)((unsigned int)(v558 - v554) >> 31));
      v557[v645] = v662;
      int * v560 = v524->cache_age;
      v560[v659] = 0;
      v606 = v659;
    } else {
      int * v563 = v524->cache_age;
      int v666 = 4 + ((((int)((unsigned int)((int)((unsigned int)v530 >> 2)) >> 1)) & 3) * 2);
      int v564 = v563[v666];
      int * v565 = v524->cache_tags;
      int v566 = v565[v666];
      int v567 = v563[v645];
      int v568 = v565[v645];
      int * v569 = v524->cache_dirty;
      int v669 = (4 + ((((int)((unsigned int)((int)((unsigned int)v530 >> 2)) >> 1)) & 3) * 2)) + ((((v564 + ((~(((v566 ^ -1) | (-(v566 ^ -1))) >> 31)) & 2)) - (v567 + ((~(((v568 ^ -1) | (-(v568 ^ -1))) >> 31)) & 2))) >> 31) & 1);
      int v570 = v569[v669];
      bool v670 = !(v570 == 0);
      if (v670) {
        int * v571 = v524->cache_tags;
        int v572 = v571[v669];
        int * v573 = v524->cache_vals;
        int v673 = ((4 + ((((int)((unsigned int)((int)((unsigned int)v530 >> 2)) >> 1)) & 3) * 2)) + ((((v564 + ((~(((v566 ^ -1) | (-(v566 ^ -1))) >> 31)) & 2)) - (v567 + ((~(((v568 ^ -1) | (-(v568 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
        int v574 = v573[v673];
        int v674 = (((4 + ((((int)((unsigned int)((int)((unsigned int)v530 >> 2)) >> 1)) & 3) * 2)) + ((((v564 + ((~(((v566 ^ -1) | (-(v566 ^ -1))) >> 31)) & 2)) - (v567 + ((~(((v568 ^ -1) | (-(v568 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
        int v575 = v573[v674];
        int * v576 = v524->mem;
        int v676 = v572 * 2;
        v576[v676] = v574;
        int * v578 = v524->mem;
        int v679 = (v572 * 2) + 1;
        v578[v679] = v575;
        ;
      } else {
        ;
      }
      int * v583 = v524->mem;
      int v684 = ((int)((unsigned int)((int)((unsigned int)v530 >> 2)) >> 1)) * 2;
      int v584 = v583[v684];
      int v685 = (((int)((unsigned int)((int)((unsigned int)v530 >> 2)) >> 1)) * 2) + 1;
      int v585 = v583[v685];
      int * v586 = v524->cache_vals;
      int v687 = ((4 + ((((int)((unsigned int)((int)((unsigned int)v530 >> 2)) >> 1)) & 3) * 2)) + ((((v564 + ((~(((v566 ^ -1) | (-(v566 ^ -1))) >> 31)) & 2)) - (v567 + ((~(((v568 ^ -1) | (-(v568 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
      v586[v687] = v584;
      int * v588 = v524->cache_vals;
      int v690 = (((4 + ((((int)((unsigned int)((int)((unsigned int)v530 >> 2)) >> 1)) & 3) * 2)) + ((((v564 + ((~(((v566 ^ -1) | (-(v566 ^ -1))) >> 31)) & 2)) - (v567 + ((~(((v568 ^ -1) | (-(v568 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
      v588[v690] = v585;
      int * v590 = v524->cache_tags;
      int v693 = (int)((unsigned int)((int)((unsigned int)v530 >> 2)) >> 1);
      v590[v669] = v693;
      int * v592 = v524->cache_dirty;
      v592[v669] = 0;
      int * v594 = v524->cache_age;
      v594[v669] = 1;
      int * v596 = v524->cache_age;
      int v597 = v596[v669];
      int v598 = v596[v644];
      int v699 = v598 + ((int)((unsigned int)(v598 - v597) >> 31));
      v596[v644] = v699;
      int * v600 = v524->cache_age;
      int v601 = v600[v645];
      int v701 = v601 + ((int)((unsigned int)(v601 - v597) >> 31));
      v600[v645] = v701;
      int * v603 = v524->cache_age;
      v603[v669] = 0;
      v606 = v669;
    }
    int * v607 = v524->cache_vals;
    int v704 = v606 * 2;
    int v608 = v607[v704];
    int v705 = (v606 * 2) + 1;
    int v609 = v607[v705];
    int v706 = (((((int)((unsigned int)((int)((unsigned int)v530 >> 2)) >> 1)) & 1) * 2) + ((((v548 + ((~(((v550 ^ -1) | (-(v550 ^ -1))) >> 31)) & 2)) - (v551 + ((~(((v552 ^ -1) | (-(v552 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
    v607[v706] = v608;
    int * v611 = v524->cache_vals;
    int v709 = ((((((int)((unsigned int)((int)((unsigned int)v530 >> 2)) >> 1)) & 1) * 2) + ((((v548 + ((~(((v550 ^ -1) | (-(v550 ^ -1))) >> 31)) & 2)) - (v551 + ((~(((v552 ^ -1) | (-(v552 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
    v611[v709] = v609;
    int * v613 = v524->cache_tags;
    int v712 = ((((int)((unsigned int)((int)((unsigned int)v530 >> 2)) >> 1)) & 1) * 2) + ((((v548 + ((~(((v550 ^ -1) | (-(v550 ^ -1))) >> 31)) & 2)) - (v551 + ((~(((v552 ^ -1) | (-(v552 ^ -1))) >> 31)) & 2))) >> 31) & 1);
    int v713 = (int)((unsigned int)((int)((unsigned int)v530 >> 2)) >> 1);
    v613[v712] = v713;
    int * v615 = v524->cache_dirty;
    v615[v712] = 0;
    int * v617 = v524->cache_age;
    v617[v712] = 1;
    int * v619 = v524->cache_age;
    int v620 = v619[v712];
    int v621 = v619[v642];
    int v719 = v621 + ((int)((unsigned int)(v621 - v620) >> 31));
    v619[v642] = v719;
    int * v623 = v524->cache_age;
    int v624 = v623[v643];
    int v721 = v624 + ((int)((unsigned int)(v624 - v620) >> 31));
    v623[v643] = v721;
    int * v626 = v524->cache_age;
    v626[v712] = 0;
    v629 = v712;
  }
  int v724 = (v629 * 2) + (((int)((unsigned int)v530 >> 2)) & 1);
  int v630 = v536[v724];
  int * v631 = v524->reg_ready;
  int v727 = ((v528 + ((v525 - v528) & (~((v525 - v528) >> 31)))) + 1) + ((100 ^ (((~(((v534 ^ ((int)((unsigned int)((int)((unsigned int)v530 >> 2)) >> 1))) | (-(v534 ^ ((int)((unsigned int)((int)((unsigned int)v530 >> 2)) >> 1))))) >> 31)) | (~(((v535 ^ ((int)((unsigned int)((int)((unsigned int)v530 >> 2)) >> 1))) | (-(v535 ^ ((int)((unsigned int)((int)((unsigned int)v530 >> 2)) >> 1))))) >> 31))) & 104)) ^ (((~(((v532 ^ ((int)((unsigned int)((int)((unsigned int)v530 >> 2)) >> 1))) | (-(v532 ^ ((int)((unsigned int)((int)((unsigned int)v530 >> 2)) >> 1))))) >> 31)) | (~(((v533 ^ ((int)((unsigned int)((int)((unsigned int)v530 >> 2)) >> 1))) | (-(v533 ^ ((int)((unsigned int)((int)((unsigned int)v530 >> 2)) >> 1))))) >> 31))) & (1 ^ (100 ^ (((~(((v534 ^ ((int)((unsigned int)((int)((unsigned int)v530 >> 2)) >> 1))) | (-(v534 ^ ((int)((unsigned int)((int)((unsigned int)v530 >> 2)) >> 1))))) >> 31)) | (~(((v535 ^ ((int)((unsigned int)((int)((unsigned int)v530 >> 2)) >> 1))) | (-(v535 ^ ((int)((unsigned int)((int)((unsigned int)v530 >> 2)) >> 1))))) >> 31))) & 104)))));
  v631[12] = v727;
  int * v633 = v524->regs;
  v633[12] = v630;
  struct StateT * v635 = slot_8(v524);
  return v635;
}

struct StateT * slot_3(struct StateT * v50) {
  int v51 = v50->timer;
  int v65 = v51 + 1;
  v50->timer = v65;
  int * v53 = v50->reg_ready;
  int * v55 = v50->regs;
  int v56 = v55[10];
  int v58 = v55[15];
  bool v70 = v56 >= v58;
  struct StateT * v63;
  if (v70) {
    struct StateT * v59 = slot_8(v50);
    v63 = v59;
  } else {
    struct StateT * v61 = slot_4(v50);
    v63 = v61;
  }
  return v63;
}

struct StateT * snippet(struct StateT * v0) {
  struct StateT * v1 = slot_0(v0);
  int v732 = v1->timer;
  int * v733 = v1->reg_ready;
  int v734 = v733[0];
  int v865 = v734 + ((v732 - v734) & (~((v732 - v734) >> 31)));
  v1->timer = v865;
  int v736 = v1->timer;
  int * v737 = v1->reg_ready;
  int v738 = v737[1];
  int v868 = v738 + ((v736 - v738) & (~((v736 - v738) >> 31)));
  v1->timer = v868;
  int v740 = v1->timer;
  int * v741 = v1->reg_ready;
  int v742 = v741[2];
  int v871 = v742 + ((v740 - v742) & (~((v740 - v742) >> 31)));
  v1->timer = v871;
  int v744 = v1->timer;
  int * v745 = v1->reg_ready;
  int v746 = v745[3];
  int v874 = v746 + ((v744 - v746) & (~((v744 - v746) >> 31)));
  v1->timer = v874;
  int v748 = v1->timer;
  int * v749 = v1->reg_ready;
  int v750 = v749[4];
  int v877 = v750 + ((v748 - v750) & (~((v748 - v750) >> 31)));
  v1->timer = v877;
  int v752 = v1->timer;
  int * v753 = v1->reg_ready;
  int v754 = v753[5];
  int v880 = v754 + ((v752 - v754) & (~((v752 - v754) >> 31)));
  v1->timer = v880;
  int v756 = v1->timer;
  int * v757 = v1->reg_ready;
  int v758 = v757[6];
  int v883 = v758 + ((v756 - v758) & (~((v756 - v758) >> 31)));
  v1->timer = v883;
  int v760 = v1->timer;
  int * v761 = v1->reg_ready;
  int v762 = v761[7];
  int v886 = v762 + ((v760 - v762) & (~((v760 - v762) >> 31)));
  v1->timer = v886;
  int v764 = v1->timer;
  int * v765 = v1->reg_ready;
  int v766 = v765[8];
  int v889 = v766 + ((v764 - v766) & (~((v764 - v766) >> 31)));
  v1->timer = v889;
  int v768 = v1->timer;
  int * v769 = v1->reg_ready;
  int v770 = v769[9];
  int v892 = v770 + ((v768 - v770) & (~((v768 - v770) >> 31)));
  v1->timer = v892;
  int v772 = v1->timer;
  int * v773 = v1->reg_ready;
  int v774 = v773[10];
  int v895 = v774 + ((v772 - v774) & (~((v772 - v774) >> 31)));
  v1->timer = v895;
  int v776 = v1->timer;
  int * v777 = v1->reg_ready;
  int v778 = v777[11];
  int v898 = v778 + ((v776 - v778) & (~((v776 - v778) >> 31)));
  v1->timer = v898;
  int v780 = v1->timer;
  int * v781 = v1->reg_ready;
  int v782 = v781[12];
  int v901 = v782 + ((v780 - v782) & (~((v780 - v782) >> 31)));
  v1->timer = v901;
  int v784 = v1->timer;
  int * v785 = v1->reg_ready;
  int v786 = v785[13];
  int v904 = v786 + ((v784 - v786) & (~((v784 - v786) >> 31)));
  v1->timer = v904;
  int v788 = v1->timer;
  int * v789 = v1->reg_ready;
  int v790 = v789[14];
  int v907 = v790 + ((v788 - v790) & (~((v788 - v790) >> 31)));
  v1->timer = v907;
  int v792 = v1->timer;
  int * v793 = v1->reg_ready;
  int v794 = v793[15];
  int v910 = v794 + ((v792 - v794) & (~((v792 - v794) >> 31)));
  v1->timer = v910;
  int v796 = v1->timer;
  int * v797 = v1->reg_ready;
  int v798 = v797[16];
  int v913 = v798 + ((v796 - v798) & (~((v796 - v798) >> 31)));
  v1->timer = v913;
  int v800 = v1->timer;
  int * v801 = v1->reg_ready;
  int v802 = v801[17];
  int v916 = v802 + ((v800 - v802) & (~((v800 - v802) >> 31)));
  v1->timer = v916;
  int v804 = v1->timer;
  int * v805 = v1->reg_ready;
  int v806 = v805[18];
  int v919 = v806 + ((v804 - v806) & (~((v804 - v806) >> 31)));
  v1->timer = v919;
  int v808 = v1->timer;
  int * v809 = v1->reg_ready;
  int v810 = v809[19];
  int v922 = v810 + ((v808 - v810) & (~((v808 - v810) >> 31)));
  v1->timer = v922;
  int v812 = v1->timer;
  int * v813 = v1->reg_ready;
  int v814 = v813[20];
  int v925 = v814 + ((v812 - v814) & (~((v812 - v814) >> 31)));
  v1->timer = v925;
  int v816 = v1->timer;
  int * v817 = v1->reg_ready;
  int v818 = v817[21];
  int v928 = v818 + ((v816 - v818) & (~((v816 - v818) >> 31)));
  v1->timer = v928;
  int v820 = v1->timer;
  int * v821 = v1->reg_ready;
  int v822 = v821[22];
  int v931 = v822 + ((v820 - v822) & (~((v820 - v822) >> 31)));
  v1->timer = v931;
  int v824 = v1->timer;
  int * v825 = v1->reg_ready;
  int v826 = v825[23];
  int v934 = v826 + ((v824 - v826) & (~((v824 - v826) >> 31)));
  v1->timer = v934;
  int v828 = v1->timer;
  int * v829 = v1->reg_ready;
  int v830 = v829[24];
  int v937 = v830 + ((v828 - v830) & (~((v828 - v830) >> 31)));
  v1->timer = v937;
  int v832 = v1->timer;
  int * v833 = v1->reg_ready;
  int v834 = v833[25];
  int v940 = v834 + ((v832 - v834) & (~((v832 - v834) >> 31)));
  v1->timer = v940;
  int v836 = v1->timer;
  int * v837 = v1->reg_ready;
  int v838 = v837[26];
  int v943 = v838 + ((v836 - v838) & (~((v836 - v838) >> 31)));
  v1->timer = v943;
  int v840 = v1->timer;
  int * v841 = v1->reg_ready;
  int v842 = v841[27];
  int v946 = v842 + ((v840 - v842) & (~((v840 - v842) >> 31)));
  v1->timer = v946;
  int v844 = v1->timer;
  int * v845 = v1->reg_ready;
  int v846 = v845[28];
  int v949 = v846 + ((v844 - v846) & (~((v844 - v846) >> 31)));
  v1->timer = v949;
  int v848 = v1->timer;
  int * v849 = v1->reg_ready;
  int v850 = v849[29];
  int v952 = v850 + ((v848 - v850) & (~((v848 - v850) >> 31)));
  v1->timer = v952;
  int v852 = v1->timer;
  int * v853 = v1->reg_ready;
  int v854 = v853[30];
  int v955 = v854 + ((v852 - v854) & (~((v852 - v854) >> 31)));
  v1->timer = v955;
  int v856 = v1->timer;
  int * v857 = v1->reg_ready;
  int v858 = v857[31];
  int v958 = v858 + ((v856 - v858) & (~((v856 - v858) >> 31)));
  v1->timer = v958;
  return v1;
}

struct StateT * slot_1(struct StateT * v18) {
  int v19 = v18->timer;
  int v27 = v19 + 1;
  v18->timer = v27;
  int * v21 = v18->reg_ready;
  v21[10] = v27;
  int * v23 = v18->regs;
  v23[10] = 80;
  struct StateT * v25 = slot_2(v18);
  return v25;
}

struct StateT * slot_8(struct StateT * v76) {
  int v77 = v76->timer;
  int v81 = v77 + 1;
  v76->timer = v81;
  struct StateT * v79 = slot_9(v76);
  return v79;
}

struct StateT * slot_4(struct StateT * v84) {
  int v85 = v84->timer;
  int v98 = v85 + 1;
  v84->timer = v98;
  int * v87 = v84->reg_ready;
  int v88 = v87[13];
  int * v89 = v84->regs;
  int v90 = v89[13];
  int v91 = v87[10];
  int v92 = v89[10];
  int v104 = (v91 + (((v88 + ((v85 - v88) & (~((v85 - v88) >> 31)))) - v91) & (~(((v88 + ((v85 - v88) & (~((v85 - v88) >> 31)))) - v91) >> 31)))) + 1;
  v87[5] = v104;
  int * v94 = v84->regs;
  int v106 = v90 + v92;
  v94[5] = v106;
  struct StateT * v96 = slot_5(v84);
  return v96;
}

struct StateT * slot_9(struct StateT * v109) {
  int v110 = v109->timer;
  int v217 = v110 + 1;
  v109->timer = v217;
  int * v112 = v109->cache_tags;
  int v113 = v112[0];
  int v114 = v112[1];
  int v115 = v112[4];
  int v116 = v112[5];
  int * v117 = v109->cache_vals;
  bool v223 = !(((~((v113 | (-v113)) >> 31)) | (~((v114 | (-v114)) >> 31))) == 0);
  int v210;
  if (v223) {
    int * v118 = v109->cache_age;
    int v225 = (~((v114 | (-v114)) >> 31)) & 1;
    int v119 = v118[v225];
    int v120 = v118[0];
    int v226 = v120 + ((int)((unsigned int)(v120 - v119) >> 31));
    v118[0] = v226;
    int * v122 = v109->cache_age;
    int v123 = v122[1];
    int v228 = v123 + ((int)((unsigned int)(v123 - v119) >> 31));
    v122[1] = v228;
    int * v125 = v109->cache_age;
    v125[v225] = 0;
    v210 = v225;
  } else {
    int * v128 = v109->cache_age;
    int v129 = v128[0];
    int * v130 = v109->cache_tags;
    int v131 = v130[0];
    int v132 = v128[1];
    int v133 = v130[1];
    bool v232 = !(((~((v115 | (-v115)) >> 31)) | (~((v116 | (-v116)) >> 31))) == 0);
    int v187;
    if (v232) {
      int * v134 = v109->cache_age;
      int v234 = 4 + ((~((v116 | (-v116)) >> 31)) & 1);
      int v135 = v134[v234];
      int v136 = v134[4];
      int v235 = v136 + ((int)((unsigned int)(v136 - v135) >> 31));
      v134[4] = v235;
      int * v138 = v109->cache_age;
      int v139 = v138[5];
      int v237 = v139 + ((int)((unsigned int)(v139 - v135) >> 31));
      v138[5] = v237;
      int * v141 = v109->cache_age;
      v141[v234] = 0;
      v187 = v234;
    } else {
      int * v144 = v109->cache_age;
      int v145 = v144[4];
      int * v146 = v109->cache_tags;
      int v147 = v146[4];
      int v148 = v144[5];
      int v149 = v146[5];
      int * v150 = v109->cache_dirty;
      int v242 = 4 + ((((v145 + ((~(((v147 ^ -1) | (-(v147 ^ -1))) >> 31)) & 2)) - (v148 + ((~(((v149 ^ -1) | (-(v149 ^ -1))) >> 31)) & 2))) >> 31) & 1);
      int v151 = v150[v242];
      bool v243 = !(v151 == 0);
      if (v243) {
        int * v152 = v109->cache_tags;
        int v153 = v152[v242];
        int * v154 = v109->cache_vals;
        int v246 = (4 + ((((v145 + ((~(((v147 ^ -1) | (-(v147 ^ -1))) >> 31)) & 2)) - (v148 + ((~(((v149 ^ -1) | (-(v149 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
        int v155 = v154[v246];
        int v247 = ((4 + ((((v145 + ((~(((v147 ^ -1) | (-(v147 ^ -1))) >> 31)) & 2)) - (v148 + ((~(((v149 ^ -1) | (-(v149 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
        int v156 = v154[v247];
        int * v157 = v109->mem;
        int v249 = v153 * 2;
        v157[v249] = v155;
        int * v159 = v109->mem;
        int v252 = (v153 * 2) + 1;
        v159[v252] = v156;
        ;
      } else {
        ;
      }
      int * v164 = v109->mem;
      int v165 = v164[0];
      int v166 = v164[1];
      int * v167 = v109->cache_vals;
      int v258 = (4 + ((((v145 + ((~(((v147 ^ -1) | (-(v147 ^ -1))) >> 31)) & 2)) - (v148 + ((~(((v149 ^ -1) | (-(v149 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
      v167[v258] = v165;
      int * v169 = v109->cache_vals;
      int v261 = ((4 + ((((v145 + ((~(((v147 ^ -1) | (-(v147 ^ -1))) >> 31)) & 2)) - (v148 + ((~(((v149 ^ -1) | (-(v149 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
      v169[v261] = v166;
      int * v171 = v109->cache_tags;
      v171[v242] = 0;
      int * v173 = v109->cache_dirty;
      v173[v242] = 0;
      int * v175 = v109->cache_age;
      v175[v242] = 1;
      int * v177 = v109->cache_age;
      int v178 = v177[v242];
      int v179 = v177[4];
      int v267 = v179 + ((int)((unsigned int)(v179 - v178) >> 31));
      v177[4] = v267;
      int * v181 = v109->cache_age;
      int v182 = v181[5];
      int v269 = v182 + ((int)((unsigned int)(v182 - v178) >> 31));
      v181[5] = v269;
      int * v184 = v109->cache_age;
      v184[v242] = 0;
      v187 = v242;
    }
    int * v188 = v109->cache_vals;
    int v272 = v187 * 2;
    int v189 = v188[v272];
    int v273 = (v187 * 2) + 1;
    int v190 = v188[v273];
    int v274 = ((((v129 + ((~(((v131 ^ -1) | (-(v131 ^ -1))) >> 31)) & 2)) - (v132 + ((~(((v133 ^ -1) | (-(v133 ^ -1))) >> 31)) & 2))) >> 31) & 1) * 2;
    v188[v274] = v189;
    int * v192 = v109->cache_vals;
    int v277 = (((((v129 + ((~(((v131 ^ -1) | (-(v131 ^ -1))) >> 31)) & 2)) - (v132 + ((~(((v133 ^ -1) | (-(v133 ^ -1))) >> 31)) & 2))) >> 31) & 1) * 2) + 1;
    v192[v277] = v190;
    int * v194 = v109->cache_tags;
    int v280 = (((v129 + ((~(((v131 ^ -1) | (-(v131 ^ -1))) >> 31)) & 2)) - (v132 + ((~(((v133 ^ -1) | (-(v133 ^ -1))) >> 31)) & 2))) >> 31) & 1;
    v194[v280] = 0;
    int * v196 = v109->cache_dirty;
    v196[v280] = 0;
    int * v198 = v109->cache_age;
    v198[v280] = 1;
    int * v200 = v109->cache_age;
    int v201 = v200[v280];
    int v202 = v200[0];
    int v284 = v202 + ((int)((unsigned int)(v202 - v201) >> 31));
    v200[0] = v284;
    int * v204 = v109->cache_age;
    int v205 = v204[1];
    int v286 = v205 + ((int)((unsigned int)(v205 - v201) >> 31));
    v204[1] = v286;
    int * v207 = v109->cache_age;
    v207[v280] = 0;
    v210 = v280;
  }
  int v289 = v210 * 2;
  int v211 = v117[v289];
  int * v212 = v109->reg_ready;
  int v292 = (v110 + 1) + ((100 ^ (((~((v115 | (-v115)) >> 31)) | (~((v116 | (-v116)) >> 31))) & 104)) ^ (((~((v113 | (-v113)) >> 31)) | (~((v114 | (-v114)) >> 31))) & (1 ^ (100 ^ (((~((v115 | (-v115)) >> 31)) | (~((v116 | (-v116)) >> 31))) & 104)))));
  v212[14] = v292;
  int * v214 = v109->regs;
  v214[14] = v211;
  return v109;
}

struct StateT * slot_0(struct StateT * v2) {
  int v3 = v2->timer;
  int v11 = v3 + 1;
  v2->timer = v11;
  int * v5 = v2->reg_ready;
  v5[13] = v11;
  int * v7 = v2->regs;
  v7[13] = 0;
  struct StateT * v9 = slot_1(v2);
  return v9;
}



/*****************************************
End of C Generated Code
*******************************************/

void init(struct StateT *s) {
  for (int i=0; i<NUM_REGS; i++) {
    s->regs[i] = 0;
    s->reg_ready[i] = 0;
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
  
  int x = bounded(0, 80);
  s1.regs[10] = x;
  s2.regs[10] = x;
  
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