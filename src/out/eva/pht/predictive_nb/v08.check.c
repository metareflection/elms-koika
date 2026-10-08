// verify: leak (Eva should report untainted_timer: unknown) [unroll 65]
#define NUM_REGS 32
#define MEM_SIZE 64
#define SECRET_SIZE 10
#define SECRET_OFFSET 20
#define CACHE_ENTRIES 12
#define CACHE_WORDS 24

#ifdef EVA
#include "__fc_builtin.h"
/*@ assigns *p \from \nothing;
    taints *p; */
void koika_mark(int *p);
#define koika_assert(b, s) ((void)0)
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

struct StateT * slot_12(struct StateT * v629);
struct StateT * slot_6(struct StateT * v316);
struct StateT * slot_16(struct StateT * v708);
struct StateT * slot_5(struct StateT * v295);
struct StateT * slot_2(struct StateT * v225);
struct StateT * slot_7(struct StateT * v337);
struct StateT * slot_21(struct StateT * v1490);
struct StateT * slot_3(struct StateT * v247);
struct StateT * slot_10(struct StateT * v406);
struct StateT * slot_1(struct StateT * v18);
struct StateT * slot_19(struct StateT * v1147);
struct StateT * slot_13(struct StateT * v650);
struct StateT * slot_0(struct StateT * v2);
struct StateT * slot_14(struct StateT * v666);
struct StateT * slot_17(struct StateT * v732);
struct StateT * slot_20(struct StateT * v1171);
struct StateT * snippet(struct StateT * v0);
struct StateT * slot_8(struct StateT * v361);
struct StateT * slot_4(struct StateT * v279);
struct StateT * slot_15(struct StateT * v687);
struct StateT * slot_18(struct StateT * v939);
struct StateT * slot_9(struct StateT * v382);
struct StateT * slot_11(struct StateT * v613);
struct StateT * slot_12(struct StateT * v629) {
  int v630 = v629->timer;
  int v641 = v630 + 1;
  v629->timer = v641;
  int * v632 = v629->reg_ready;
  int v633 = v632[11];
  int * v634 = v629->regs;
  int v635 = v634[11];
  int v645 = (v633 + ((v630 - v633) & (~((v630 - v633) >> 31)))) + 1;
  v632[11] = v645;
  int * v637 = v629->regs;
  int v647 = v635 + 4;
  v637[11] = v647;
  struct StateT * v639 = slot_13(v629);
  return v639;
}

struct StateT * slot_6(struct StateT * v316) {
  int v317 = v316->timer;
  int v328 = v317 + 1;
  v316->timer = v328;
  int * v319 = v316->reg_ready;
  int v320 = v319[10];
  int * v321 = v316->regs;
  int v322 = v321[10];
  int v332 = (v320 + ((v317 - v320) & (~((v317 - v320) >> 31)))) + 1;
  v319[10] = v332;
  int * v324 = v316->regs;
  int v334 = -v322;
  v324[10] = v334;
  struct StateT * v326 = slot_7(v316);
  return v326;
}

struct StateT * slot_16(struct StateT * v708) {
  int v709 = v708->timer;
  int v722 = v709 + 1;
  v708->timer = v722;
  int * v711 = v708->reg_ready;
  int v712 = v711[11];
  int * v713 = v708->regs;
  int v714 = v713[11];
  int v715 = v711[10];
  int v716 = v713[10];
  int v727 = (v715 + (((v712 + ((v709 - v712) & (~((v709 - v712) >> 31)))) - v715) & (~(((v712 + ((v709 - v712) & (~((v709 - v712) >> 31)))) - v715) >> 31)))) + 1;
  v711[10] = v727;
  int * v718 = v708->regs;
  int v729 = v714 + v716;
  v718[10] = v729;
  struct StateT * v720 = slot_17(v708);
  return v720;
}

struct StateT * slot_5(struct StateT * v295) {
  int v296 = v295->timer;
  int v307 = v296 + 1;
  v295->timer = v307;
  int * v298 = v295->reg_ready;
  int v299 = v298[11];
  int * v300 = v295->regs;
  int v301 = v300[11];
  int v311 = (v299 + ((v296 - v299) & (~((v296 - v299) >> 31)))) + 1;
  v298[11] = v311;
  int * v303 = v295->regs;
  int v313 = v301 + 72;
  v303[11] = v313;
  struct StateT * v305 = slot_6(v295);
  return v305;
}

struct StateT * slot_2(struct StateT * v225) {
  int v226 = v225->timer;
  int v237 = v226 + 1;
  v225->timer = v237;
  int * v228 = v225->reg_ready;
  int v229 = v228[10];
  int * v230 = v225->regs;
  int v231 = v230[10];
  int v242 = (v229 + ((v226 - v229) & (~((v226 - v229) >> 31)))) + 1;
  v228[12] = v242;
  int * v233 = v225->regs;
  int v244 = v231 + 1;
  v233[12] = v244;
  struct StateT * v235 = slot_3(v225);
  return v235;
}

struct StateT * slot_7(struct StateT * v337) {
  int v338 = v337->timer;
  int v351 = v338 + 1;
  v337->timer = v351;
  int * v340 = v337->reg_ready;
  int v341 = v340[10];
  int * v342 = v337->regs;
  int v343 = v342[10];
  int v344 = v340[12];
  int v345 = v342[12];
  int v356 = (v344 + (((v341 + ((v338 - v341) & (~((v338 - v341) >> 31)))) - v344) & (~(((v341 + ((v338 - v341) & (~((v338 - v341) >> 31)))) - v344) >> 31)))) + 1;
  v340[10] = v356;
  int * v347 = v337->regs;
  int v358 = v343 & v345;
  v347[10] = v358;
  struct StateT * v349 = slot_8(v337);
  return v349;
}

struct StateT * slot_21(struct StateT * v1490) {
  int v1491 = v1490->timer;
  int v1494 = v1491 + 1;
  v1490->timer = v1494;
  return v1490;
}

struct StateT * slot_3(struct StateT * v247) {
  int v248 = v247->timer;
  int v265 = v248 + 1;
  v247->timer = v265;
  int * v250 = v247->reg_ready;
  int v251 = v250[10];
  int * v252 = v247->regs;
  int v253 = v252[10];
  int v254 = v250[11];
  int v255 = v252[11];
  bool v270 = (v253 ^ -2147483648) < (v255 ^ -2147483648);
  int v258;
  if (v270) {
    v258 = 1;
  } else {
    v258 = 0;
  }
  int * v259 = v247->reg_ready;
  int v274 = (v254 + (((v251 + ((v248 - v251) & (~((v248 - v251) >> 31)))) - v254) & (~(((v251 + ((v248 - v251) & (~((v248 - v251) >> 31)))) - v254) >> 31)))) + 1;
  v259[10] = v274;
  int * v261 = v247->regs;
  v261[10] = v258;
  struct StateT * v263 = slot_4(v247);
  return v263;
}

struct StateT * slot_10(struct StateT * v406) {
  int v407 = v406->timer;
  int v519 = v407 + 1;
  v406->timer = v519;
  int * v409 = v406->reg_ready;
  int v410 = v409[10];
  int * v411 = v406->regs;
  int v412 = v411[10];
  int * v413 = v406->cache_tags;
  int v524 = (((int)((unsigned int)((int)((unsigned int)v412 >> 2)) >> 1)) & 1) * 2;
  int v414 = v413[v524];
  int v525 = ((((int)((unsigned int)((int)((unsigned int)v412 >> 2)) >> 1)) & 1) * 2) + 1;
  int v415 = v413[v525];
  int v526 = 4 + ((((int)((unsigned int)((int)((unsigned int)v412 >> 2)) >> 1)) & 3) * 2);
  int v416 = v413[v526];
  int v527 = (4 + ((((int)((unsigned int)((int)((unsigned int)v412 >> 2)) >> 1)) & 3) * 2)) + 1;
  int v417 = v413[v527];
  int * v418 = v406->cache_vals;
  bool v528 = !(((~(((v414 ^ ((int)((unsigned int)((int)((unsigned int)v412 >> 2)) >> 1))) | (-(v414 ^ ((int)((unsigned int)((int)((unsigned int)v412 >> 2)) >> 1))))) >> 31)) | (~(((v415 ^ ((int)((unsigned int)((int)((unsigned int)v412 >> 2)) >> 1))) | (-(v415 ^ ((int)((unsigned int)((int)((unsigned int)v412 >> 2)) >> 1))))) >> 31))) == 0);
  int v511;
  if (v528) {
    int * v419 = v406->cache_age;
    int v530 = ((((int)((unsigned int)((int)((unsigned int)v412 >> 2)) >> 1)) & 1) * 2) + ((~(((v415 ^ ((int)((unsigned int)((int)((unsigned int)v412 >> 2)) >> 1))) | (-(v415 ^ ((int)((unsigned int)((int)((unsigned int)v412 >> 2)) >> 1))))) >> 31)) & 1);
    int v420 = v419[v530];
    int v421 = v419[v524];
    int v531 = v421 + ((int)((unsigned int)(v421 - v420) >> 31));
    v419[v524] = v531;
    int * v423 = v406->cache_age;
    int v424 = v423[v525];
    int v533 = v424 + ((int)((unsigned int)(v424 - v420) >> 31));
    v423[v525] = v533;
    int * v426 = v406->cache_age;
    v426[v530] = 0;
    v511 = v530;
  } else {
    int * v429 = v406->cache_age;
    int v537 = (((int)((unsigned int)((int)((unsigned int)v412 >> 2)) >> 1)) & 1) * 2;
    int v430 = v429[v537];
    int * v431 = v406->cache_tags;
    int v432 = v431[v537];
    int v433 = v429[v525];
    int v434 = v431[v525];
    bool v539 = !(((~(((v416 ^ ((int)((unsigned int)((int)((unsigned int)v412 >> 2)) >> 1))) | (-(v416 ^ ((int)((unsigned int)((int)((unsigned int)v412 >> 2)) >> 1))))) >> 31)) | (~(((v417 ^ ((int)((unsigned int)((int)((unsigned int)v412 >> 2)) >> 1))) | (-(v417 ^ ((int)((unsigned int)((int)((unsigned int)v412 >> 2)) >> 1))))) >> 31))) == 0);
    int v488;
    if (v539) {
      int * v435 = v406->cache_age;
      int v541 = (4 + ((((int)((unsigned int)((int)((unsigned int)v412 >> 2)) >> 1)) & 3) * 2)) + ((~(((v417 ^ ((int)((unsigned int)((int)((unsigned int)v412 >> 2)) >> 1))) | (-(v417 ^ ((int)((unsigned int)((int)((unsigned int)v412 >> 2)) >> 1))))) >> 31)) & 1);
      int v436 = v435[v541];
      int v437 = v435[v526];
      int v542 = v437 + ((int)((unsigned int)(v437 - v436) >> 31));
      v435[v526] = v542;
      int * v439 = v406->cache_age;
      int v440 = v439[v527];
      int v544 = v440 + ((int)((unsigned int)(v440 - v436) >> 31));
      v439[v527] = v544;
      int * v442 = v406->cache_age;
      v442[v541] = 0;
      v488 = v541;
    } else {
      int * v445 = v406->cache_age;
      int v548 = 4 + ((((int)((unsigned int)((int)((unsigned int)v412 >> 2)) >> 1)) & 3) * 2);
      int v446 = v445[v548];
      int * v447 = v406->cache_tags;
      int v448 = v447[v548];
      int v449 = v445[v527];
      int v450 = v447[v527];
      int * v451 = v406->cache_dirty;
      int v551 = (4 + ((((int)((unsigned int)((int)((unsigned int)v412 >> 2)) >> 1)) & 3) * 2)) + ((((v446 + ((~(((v448 ^ -1) | (-(v448 ^ -1))) >> 31)) & 2)) - (v449 + ((~(((v450 ^ -1) | (-(v450 ^ -1))) >> 31)) & 2))) >> 31) & 1);
      int v452 = v451[v551];
      bool v552 = !(v452 == 0);
      if (v552) {
        int * v453 = v406->cache_tags;
        int v454 = v453[v551];
        int * v455 = v406->cache_vals;
        int v555 = ((4 + ((((int)((unsigned int)((int)((unsigned int)v412 >> 2)) >> 1)) & 3) * 2)) + ((((v446 + ((~(((v448 ^ -1) | (-(v448 ^ -1))) >> 31)) & 2)) - (v449 + ((~(((v450 ^ -1) | (-(v450 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
        int v456 = v455[v555];
        int v556 = (((4 + ((((int)((unsigned int)((int)((unsigned int)v412 >> 2)) >> 1)) & 3) * 2)) + ((((v446 + ((~(((v448 ^ -1) | (-(v448 ^ -1))) >> 31)) & 2)) - (v449 + ((~(((v450 ^ -1) | (-(v450 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
        int v457 = v455[v556];
        int * v458 = v406->mem;
        int v558 = v454 * 2;
        v458[v558] = v456;
        int * v460 = v406->mem;
        int v561 = (v454 * 2) + 1;
        v460[v561] = v457;
        ;
      } else {
        ;
      }
      int * v465 = v406->mem;
      int v566 = ((int)((unsigned int)((int)((unsigned int)v412 >> 2)) >> 1)) * 2;
      int v466 = v465[v566];
      int v567 = (((int)((unsigned int)((int)((unsigned int)v412 >> 2)) >> 1)) * 2) + 1;
      int v467 = v465[v567];
      int * v468 = v406->cache_vals;
      int v569 = ((4 + ((((int)((unsigned int)((int)((unsigned int)v412 >> 2)) >> 1)) & 3) * 2)) + ((((v446 + ((~(((v448 ^ -1) | (-(v448 ^ -1))) >> 31)) & 2)) - (v449 + ((~(((v450 ^ -1) | (-(v450 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
      v468[v569] = v466;
      int * v470 = v406->cache_vals;
      int v572 = (((4 + ((((int)((unsigned int)((int)((unsigned int)v412 >> 2)) >> 1)) & 3) * 2)) + ((((v446 + ((~(((v448 ^ -1) | (-(v448 ^ -1))) >> 31)) & 2)) - (v449 + ((~(((v450 ^ -1) | (-(v450 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
      v470[v572] = v467;
      int * v472 = v406->cache_tags;
      int v575 = (int)((unsigned int)((int)((unsigned int)v412 >> 2)) >> 1);
      v472[v551] = v575;
      int * v474 = v406->cache_dirty;
      v474[v551] = 0;
      int * v476 = v406->cache_age;
      v476[v551] = 1;
      int * v478 = v406->cache_age;
      int v479 = v478[v551];
      int v480 = v478[v526];
      int v581 = v480 + ((int)((unsigned int)(v480 - v479) >> 31));
      v478[v526] = v581;
      int * v482 = v406->cache_age;
      int v483 = v482[v527];
      int v583 = v483 + ((int)((unsigned int)(v483 - v479) >> 31));
      v482[v527] = v583;
      int * v485 = v406->cache_age;
      v485[v551] = 0;
      v488 = v551;
    }
    int * v489 = v406->cache_vals;
    int v586 = v488 * 2;
    int v490 = v489[v586];
    int v587 = (v488 * 2) + 1;
    int v491 = v489[v587];
    int v588 = (((((int)((unsigned int)((int)((unsigned int)v412 >> 2)) >> 1)) & 1) * 2) + ((((v430 + ((~(((v432 ^ -1) | (-(v432 ^ -1))) >> 31)) & 2)) - (v433 + ((~(((v434 ^ -1) | (-(v434 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
    v489[v588] = v490;
    int * v493 = v406->cache_vals;
    int v591 = ((((((int)((unsigned int)((int)((unsigned int)v412 >> 2)) >> 1)) & 1) * 2) + ((((v430 + ((~(((v432 ^ -1) | (-(v432 ^ -1))) >> 31)) & 2)) - (v433 + ((~(((v434 ^ -1) | (-(v434 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
    v493[v591] = v491;
    int * v495 = v406->cache_tags;
    int v594 = ((((int)((unsigned int)((int)((unsigned int)v412 >> 2)) >> 1)) & 1) * 2) + ((((v430 + ((~(((v432 ^ -1) | (-(v432 ^ -1))) >> 31)) & 2)) - (v433 + ((~(((v434 ^ -1) | (-(v434 ^ -1))) >> 31)) & 2))) >> 31) & 1);
    int v595 = (int)((unsigned int)((int)((unsigned int)v412 >> 2)) >> 1);
    v495[v594] = v595;
    int * v497 = v406->cache_dirty;
    v497[v594] = 0;
    int * v499 = v406->cache_age;
    v499[v594] = 1;
    int * v501 = v406->cache_age;
    int v502 = v501[v594];
    int v503 = v501[v524];
    int v601 = v503 + ((int)((unsigned int)(v503 - v502) >> 31));
    v501[v524] = v601;
    int * v505 = v406->cache_age;
    int v506 = v505[v525];
    int v603 = v506 + ((int)((unsigned int)(v506 - v502) >> 31));
    v505[v525] = v603;
    int * v508 = v406->cache_age;
    v508[v594] = 0;
    v511 = v594;
  }
  int v606 = (v511 * 2) + (((int)((unsigned int)v412 >> 2)) & 1);
  int v512 = v418[v606];
  int * v513 = v406->reg_ready;
  int v608 = ((v410 + ((v407 - v410) & (~((v407 - v410) >> 31)))) + 1) + ((100 ^ (((~(((v416 ^ ((int)((unsigned int)((int)((unsigned int)v412 >> 2)) >> 1))) | (-(v416 ^ ((int)((unsigned int)((int)((unsigned int)v412 >> 2)) >> 1))))) >> 31)) | (~(((v417 ^ ((int)((unsigned int)((int)((unsigned int)v412 >> 2)) >> 1))) | (-(v417 ^ ((int)((unsigned int)((int)((unsigned int)v412 >> 2)) >> 1))))) >> 31))) & 104)) ^ (((~(((v414 ^ ((int)((unsigned int)((int)((unsigned int)v412 >> 2)) >> 1))) | (-(v414 ^ ((int)((unsigned int)((int)((unsigned int)v412 >> 2)) >> 1))))) >> 31)) | (~(((v415 ^ ((int)((unsigned int)((int)((unsigned int)v412 >> 2)) >> 1))) | (-(v415 ^ ((int)((unsigned int)((int)((unsigned int)v412 >> 2)) >> 1))))) >> 31))) & (1 ^ (100 ^ (((~(((v416 ^ ((int)((unsigned int)((int)((unsigned int)v412 >> 2)) >> 1))) | (-(v416 ^ ((int)((unsigned int)((int)((unsigned int)v412 >> 2)) >> 1))))) >> 31)) | (~(((v417 ^ ((int)((unsigned int)((int)((unsigned int)v412 >> 2)) >> 1))) | (-(v417 ^ ((int)((unsigned int)((int)((unsigned int)v412 >> 2)) >> 1))))) >> 31))) & 104)))));
  v513[10] = v608;
  int * v515 = v406->regs;
  v515[10] = v512;
  struct StateT * v517 = slot_11(v406);
  return v517;
}

struct StateT * slot_1(struct StateT * v18) {
  int v19 = v18->timer;
  int v131 = v19 + 1;
  v18->timer = v131;
  int * v21 = v18->reg_ready;
  int v22 = v21[11];
  int * v23 = v18->regs;
  int v24 = v23[11];
  int * v25 = v18->cache_tags;
  int v136 = (((int)((unsigned int)((int)((unsigned int)v24 >> 2)) >> 1)) & 1) * 2;
  int v26 = v25[v136];
  int v137 = ((((int)((unsigned int)((int)((unsigned int)v24 >> 2)) >> 1)) & 1) * 2) + 1;
  int v27 = v25[v137];
  int v138 = 4 + ((((int)((unsigned int)((int)((unsigned int)v24 >> 2)) >> 1)) & 3) * 2);
  int v28 = v25[v138];
  int v139 = (4 + ((((int)((unsigned int)((int)((unsigned int)v24 >> 2)) >> 1)) & 3) * 2)) + 1;
  int v29 = v25[v139];
  int * v30 = v18->cache_vals;
  bool v140 = !(((~(((v26 ^ ((int)((unsigned int)((int)((unsigned int)v24 >> 2)) >> 1))) | (-(v26 ^ ((int)((unsigned int)((int)((unsigned int)v24 >> 2)) >> 1))))) >> 31)) | (~(((v27 ^ ((int)((unsigned int)((int)((unsigned int)v24 >> 2)) >> 1))) | (-(v27 ^ ((int)((unsigned int)((int)((unsigned int)v24 >> 2)) >> 1))))) >> 31))) == 0);
  int v123;
  if (v140) {
    int * v31 = v18->cache_age;
    int v142 = ((((int)((unsigned int)((int)((unsigned int)v24 >> 2)) >> 1)) & 1) * 2) + ((~(((v27 ^ ((int)((unsigned int)((int)((unsigned int)v24 >> 2)) >> 1))) | (-(v27 ^ ((int)((unsigned int)((int)((unsigned int)v24 >> 2)) >> 1))))) >> 31)) & 1);
    int v32 = v31[v142];
    int v33 = v31[v136];
    int v143 = v33 + ((int)((unsigned int)(v33 - v32) >> 31));
    v31[v136] = v143;
    int * v35 = v18->cache_age;
    int v36 = v35[v137];
    int v145 = v36 + ((int)((unsigned int)(v36 - v32) >> 31));
    v35[v137] = v145;
    int * v38 = v18->cache_age;
    v38[v142] = 0;
    v123 = v142;
  } else {
    int * v41 = v18->cache_age;
    int v149 = (((int)((unsigned int)((int)((unsigned int)v24 >> 2)) >> 1)) & 1) * 2;
    int v42 = v41[v149];
    int * v43 = v18->cache_tags;
    int v44 = v43[v149];
    int v45 = v41[v137];
    int v46 = v43[v137];
    bool v151 = !(((~(((v28 ^ ((int)((unsigned int)((int)((unsigned int)v24 >> 2)) >> 1))) | (-(v28 ^ ((int)((unsigned int)((int)((unsigned int)v24 >> 2)) >> 1))))) >> 31)) | (~(((v29 ^ ((int)((unsigned int)((int)((unsigned int)v24 >> 2)) >> 1))) | (-(v29 ^ ((int)((unsigned int)((int)((unsigned int)v24 >> 2)) >> 1))))) >> 31))) == 0);
    int v100;
    if (v151) {
      int * v47 = v18->cache_age;
      int v153 = (4 + ((((int)((unsigned int)((int)((unsigned int)v24 >> 2)) >> 1)) & 3) * 2)) + ((~(((v29 ^ ((int)((unsigned int)((int)((unsigned int)v24 >> 2)) >> 1))) | (-(v29 ^ ((int)((unsigned int)((int)((unsigned int)v24 >> 2)) >> 1))))) >> 31)) & 1);
      int v48 = v47[v153];
      int v49 = v47[v138];
      int v154 = v49 + ((int)((unsigned int)(v49 - v48) >> 31));
      v47[v138] = v154;
      int * v51 = v18->cache_age;
      int v52 = v51[v139];
      int v156 = v52 + ((int)((unsigned int)(v52 - v48) >> 31));
      v51[v139] = v156;
      int * v54 = v18->cache_age;
      v54[v153] = 0;
      v100 = v153;
    } else {
      int * v57 = v18->cache_age;
      int v160 = 4 + ((((int)((unsigned int)((int)((unsigned int)v24 >> 2)) >> 1)) & 3) * 2);
      int v58 = v57[v160];
      int * v59 = v18->cache_tags;
      int v60 = v59[v160];
      int v61 = v57[v139];
      int v62 = v59[v139];
      int * v63 = v18->cache_dirty;
      int v163 = (4 + ((((int)((unsigned int)((int)((unsigned int)v24 >> 2)) >> 1)) & 3) * 2)) + ((((v58 + ((~(((v60 ^ -1) | (-(v60 ^ -1))) >> 31)) & 2)) - (v61 + ((~(((v62 ^ -1) | (-(v62 ^ -1))) >> 31)) & 2))) >> 31) & 1);
      int v64 = v63[v163];
      bool v164 = !(v64 == 0);
      if (v164) {
        int * v65 = v18->cache_tags;
        int v66 = v65[v163];
        int * v67 = v18->cache_vals;
        int v167 = ((4 + ((((int)((unsigned int)((int)((unsigned int)v24 >> 2)) >> 1)) & 3) * 2)) + ((((v58 + ((~(((v60 ^ -1) | (-(v60 ^ -1))) >> 31)) & 2)) - (v61 + ((~(((v62 ^ -1) | (-(v62 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
        int v68 = v67[v167];
        int v168 = (((4 + ((((int)((unsigned int)((int)((unsigned int)v24 >> 2)) >> 1)) & 3) * 2)) + ((((v58 + ((~(((v60 ^ -1) | (-(v60 ^ -1))) >> 31)) & 2)) - (v61 + ((~(((v62 ^ -1) | (-(v62 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
        int v69 = v67[v168];
        int * v70 = v18->mem;
        int v170 = v66 * 2;
        v70[v170] = v68;
        int * v72 = v18->mem;
        int v173 = (v66 * 2) + 1;
        v72[v173] = v69;
        ;
      } else {
        ;
      }
      int * v77 = v18->mem;
      int v178 = ((int)((unsigned int)((int)((unsigned int)v24 >> 2)) >> 1)) * 2;
      int v78 = v77[v178];
      int v179 = (((int)((unsigned int)((int)((unsigned int)v24 >> 2)) >> 1)) * 2) + 1;
      int v79 = v77[v179];
      int * v80 = v18->cache_vals;
      int v181 = ((4 + ((((int)((unsigned int)((int)((unsigned int)v24 >> 2)) >> 1)) & 3) * 2)) + ((((v58 + ((~(((v60 ^ -1) | (-(v60 ^ -1))) >> 31)) & 2)) - (v61 + ((~(((v62 ^ -1) | (-(v62 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
      v80[v181] = v78;
      int * v82 = v18->cache_vals;
      int v184 = (((4 + ((((int)((unsigned int)((int)((unsigned int)v24 >> 2)) >> 1)) & 3) * 2)) + ((((v58 + ((~(((v60 ^ -1) | (-(v60 ^ -1))) >> 31)) & 2)) - (v61 + ((~(((v62 ^ -1) | (-(v62 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
      v82[v184] = v79;
      int * v84 = v18->cache_tags;
      int v187 = (int)((unsigned int)((int)((unsigned int)v24 >> 2)) >> 1);
      v84[v163] = v187;
      int * v86 = v18->cache_dirty;
      v86[v163] = 0;
      int * v88 = v18->cache_age;
      v88[v163] = 1;
      int * v90 = v18->cache_age;
      int v91 = v90[v163];
      int v92 = v90[v138];
      int v193 = v92 + ((int)((unsigned int)(v92 - v91) >> 31));
      v90[v138] = v193;
      int * v94 = v18->cache_age;
      int v95 = v94[v139];
      int v195 = v95 + ((int)((unsigned int)(v95 - v91) >> 31));
      v94[v139] = v195;
      int * v97 = v18->cache_age;
      v97[v163] = 0;
      v100 = v163;
    }
    int * v101 = v18->cache_vals;
    int v198 = v100 * 2;
    int v102 = v101[v198];
    int v199 = (v100 * 2) + 1;
    int v103 = v101[v199];
    int v200 = (((((int)((unsigned int)((int)((unsigned int)v24 >> 2)) >> 1)) & 1) * 2) + ((((v42 + ((~(((v44 ^ -1) | (-(v44 ^ -1))) >> 31)) & 2)) - (v45 + ((~(((v46 ^ -1) | (-(v46 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
    v101[v200] = v102;
    int * v105 = v18->cache_vals;
    int v203 = ((((((int)((unsigned int)((int)((unsigned int)v24 >> 2)) >> 1)) & 1) * 2) + ((((v42 + ((~(((v44 ^ -1) | (-(v44 ^ -1))) >> 31)) & 2)) - (v45 + ((~(((v46 ^ -1) | (-(v46 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
    v105[v203] = v103;
    int * v107 = v18->cache_tags;
    int v206 = ((((int)((unsigned int)((int)((unsigned int)v24 >> 2)) >> 1)) & 1) * 2) + ((((v42 + ((~(((v44 ^ -1) | (-(v44 ^ -1))) >> 31)) & 2)) - (v45 + ((~(((v46 ^ -1) | (-(v46 ^ -1))) >> 31)) & 2))) >> 31) & 1);
    int v207 = (int)((unsigned int)((int)((unsigned int)v24 >> 2)) >> 1);
    v107[v206] = v207;
    int * v109 = v18->cache_dirty;
    v109[v206] = 0;
    int * v111 = v18->cache_age;
    v111[v206] = 1;
    int * v113 = v18->cache_age;
    int v114 = v113[v206];
    int v115 = v113[v136];
    int v213 = v115 + ((int)((unsigned int)(v115 - v114) >> 31));
    v113[v136] = v213;
    int * v117 = v18->cache_age;
    int v118 = v117[v137];
    int v215 = v118 + ((int)((unsigned int)(v118 - v114) >> 31));
    v117[v137] = v215;
    int * v120 = v18->cache_age;
    v120[v206] = 0;
    v123 = v206;
  }
  int v218 = (v123 * 2) + (((int)((unsigned int)v24 >> 2)) & 1);
  int v124 = v30[v218];
  int * v125 = v18->reg_ready;
  int v220 = ((v22 + ((v19 - v22) & (~((v19 - v22) >> 31)))) + 1) + ((100 ^ (((~(((v28 ^ ((int)((unsigned int)((int)((unsigned int)v24 >> 2)) >> 1))) | (-(v28 ^ ((int)((unsigned int)((int)((unsigned int)v24 >> 2)) >> 1))))) >> 31)) | (~(((v29 ^ ((int)((unsigned int)((int)((unsigned int)v24 >> 2)) >> 1))) | (-(v29 ^ ((int)((unsigned int)((int)((unsigned int)v24 >> 2)) >> 1))))) >> 31))) & 104)) ^ (((~(((v26 ^ ((int)((unsigned int)((int)((unsigned int)v24 >> 2)) >> 1))) | (-(v26 ^ ((int)((unsigned int)((int)((unsigned int)v24 >> 2)) >> 1))))) >> 31)) | (~(((v27 ^ ((int)((unsigned int)((int)((unsigned int)v24 >> 2)) >> 1))) | (-(v27 ^ ((int)((unsigned int)((int)((unsigned int)v24 >> 2)) >> 1))))) >> 31))) & (1 ^ (100 ^ (((~(((v28 ^ ((int)((unsigned int)((int)((unsigned int)v24 >> 2)) >> 1))) | (-(v28 ^ ((int)((unsigned int)((int)((unsigned int)v24 >> 2)) >> 1))))) >> 31)) | (~(((v29 ^ ((int)((unsigned int)((int)((unsigned int)v24 >> 2)) >> 1))) | (-(v29 ^ ((int)((unsigned int)((int)((unsigned int)v24 >> 2)) >> 1))))) >> 31))) & 104)))));
  v125[11] = v220;
  int * v127 = v18->regs;
  v127[11] = v124;
  struct StateT * v129 = slot_2(v18);
  return v129;
}

struct StateT * slot_19(struct StateT * v1147) {
  int v1148 = v1147->timer;
  int v1161 = v1148 + 1;
  v1147->timer = v1161;
  int * v1150 = v1147->reg_ready;
  int v1151 = v1150[11];
  int * v1152 = v1147->regs;
  int v1153 = v1152[11];
  int v1154 = v1150[10];
  int v1155 = v1152[10];
  int v1166 = (v1154 + (((v1151 + ((v1148 - v1151) & (~((v1148 - v1151) >> 31)))) - v1154) & (~(((v1151 + ((v1148 - v1151) & (~((v1148 - v1151) >> 31)))) - v1154) >> 31)))) + 1;
  v1150[10] = v1166;
  int * v1157 = v1147->regs;
  int v1168 = v1153 & v1155;
  v1157[10] = v1168;
  struct StateT * v1159 = slot_20(v1147);
  return v1159;
}

struct StateT * slot_13(struct StateT * v650) {
  int v651 = v650->timer;
  int v659 = v651 + 1;
  v650->timer = v659;
  int * v653 = v650->reg_ready;
  v653[12] = v659;
  int * v655 = v650->regs;
  v655[12] = 0;
  struct StateT * v657 = slot_14(v650);
  return v657;
}

struct StateT * slot_0(struct StateT * v2) {
  int v3 = v2->timer;
  int v11 = v3 + 1;
  v2->timer = v11;
  int * v5 = v2->reg_ready;
  v5[11] = v11;
  int * v7 = v2->regs;
  v7[11] = 0;
  struct StateT * v9 = slot_1(v2);
  return v9;
}

struct StateT * slot_14(struct StateT * v666) {
  int v667 = v666->timer;
  int v678 = v667 + 1;
  v666->timer = v678;
  int * v669 = v666->reg_ready;
  int v670 = v669[10];
  int * v671 = v666->regs;
  int v672 = v671[10];
  int v682 = (v670 + ((v667 - v670) & (~((v667 - v670) >> 31)))) + 1;
  v669[10] = v682;
  int * v674 = v666->regs;
  int v684 = v672 << 29;
  v674[10] = v684;
  struct StateT * v676 = slot_15(v666);
  return v676;
}

struct StateT * slot_17(struct StateT * v732) {
  int v733 = v732->timer;
  int v845 = v733 + 1;
  v732->timer = v845;
  int * v735 = v732->reg_ready;
  int v736 = v735[10];
  int * v737 = v732->regs;
  int v738 = v737[10];
  int * v739 = v732->cache_tags;
  int v850 = (((int)((unsigned int)((int)((unsigned int)v738 >> 2)) >> 1)) & 1) * 2;
  int v740 = v739[v850];
  int v851 = ((((int)((unsigned int)((int)((unsigned int)v738 >> 2)) >> 1)) & 1) * 2) + 1;
  int v741 = v739[v851];
  int v852 = 4 + ((((int)((unsigned int)((int)((unsigned int)v738 >> 2)) >> 1)) & 3) * 2);
  int v742 = v739[v852];
  int v853 = (4 + ((((int)((unsigned int)((int)((unsigned int)v738 >> 2)) >> 1)) & 3) * 2)) + 1;
  int v743 = v739[v853];
  int * v744 = v732->cache_vals;
  bool v854 = !(((~(((v740 ^ ((int)((unsigned int)((int)((unsigned int)v738 >> 2)) >> 1))) | (-(v740 ^ ((int)((unsigned int)((int)((unsigned int)v738 >> 2)) >> 1))))) >> 31)) | (~(((v741 ^ ((int)((unsigned int)((int)((unsigned int)v738 >> 2)) >> 1))) | (-(v741 ^ ((int)((unsigned int)((int)((unsigned int)v738 >> 2)) >> 1))))) >> 31))) == 0);
  int v837;
  if (v854) {
    int * v745 = v732->cache_age;
    int v856 = ((((int)((unsigned int)((int)((unsigned int)v738 >> 2)) >> 1)) & 1) * 2) + ((~(((v741 ^ ((int)((unsigned int)((int)((unsigned int)v738 >> 2)) >> 1))) | (-(v741 ^ ((int)((unsigned int)((int)((unsigned int)v738 >> 2)) >> 1))))) >> 31)) & 1);
    int v746 = v745[v856];
    int v747 = v745[v850];
    int v857 = v747 + ((int)((unsigned int)(v747 - v746) >> 31));
    v745[v850] = v857;
    int * v749 = v732->cache_age;
    int v750 = v749[v851];
    int v859 = v750 + ((int)((unsigned int)(v750 - v746) >> 31));
    v749[v851] = v859;
    int * v752 = v732->cache_age;
    v752[v856] = 0;
    v837 = v856;
  } else {
    int * v755 = v732->cache_age;
    int v863 = (((int)((unsigned int)((int)((unsigned int)v738 >> 2)) >> 1)) & 1) * 2;
    int v756 = v755[v863];
    int * v757 = v732->cache_tags;
    int v758 = v757[v863];
    int v759 = v755[v851];
    int v760 = v757[v851];
    bool v865 = !(((~(((v742 ^ ((int)((unsigned int)((int)((unsigned int)v738 >> 2)) >> 1))) | (-(v742 ^ ((int)((unsigned int)((int)((unsigned int)v738 >> 2)) >> 1))))) >> 31)) | (~(((v743 ^ ((int)((unsigned int)((int)((unsigned int)v738 >> 2)) >> 1))) | (-(v743 ^ ((int)((unsigned int)((int)((unsigned int)v738 >> 2)) >> 1))))) >> 31))) == 0);
    int v814;
    if (v865) {
      int * v761 = v732->cache_age;
      int v867 = (4 + ((((int)((unsigned int)((int)((unsigned int)v738 >> 2)) >> 1)) & 3) * 2)) + ((~(((v743 ^ ((int)((unsigned int)((int)((unsigned int)v738 >> 2)) >> 1))) | (-(v743 ^ ((int)((unsigned int)((int)((unsigned int)v738 >> 2)) >> 1))))) >> 31)) & 1);
      int v762 = v761[v867];
      int v763 = v761[v852];
      int v868 = v763 + ((int)((unsigned int)(v763 - v762) >> 31));
      v761[v852] = v868;
      int * v765 = v732->cache_age;
      int v766 = v765[v853];
      int v870 = v766 + ((int)((unsigned int)(v766 - v762) >> 31));
      v765[v853] = v870;
      int * v768 = v732->cache_age;
      v768[v867] = 0;
      v814 = v867;
    } else {
      int * v771 = v732->cache_age;
      int v874 = 4 + ((((int)((unsigned int)((int)((unsigned int)v738 >> 2)) >> 1)) & 3) * 2);
      int v772 = v771[v874];
      int * v773 = v732->cache_tags;
      int v774 = v773[v874];
      int v775 = v771[v853];
      int v776 = v773[v853];
      int * v777 = v732->cache_dirty;
      int v877 = (4 + ((((int)((unsigned int)((int)((unsigned int)v738 >> 2)) >> 1)) & 3) * 2)) + ((((v772 + ((~(((v774 ^ -1) | (-(v774 ^ -1))) >> 31)) & 2)) - (v775 + ((~(((v776 ^ -1) | (-(v776 ^ -1))) >> 31)) & 2))) >> 31) & 1);
      int v778 = v777[v877];
      bool v878 = !(v778 == 0);
      if (v878) {
        int * v779 = v732->cache_tags;
        int v780 = v779[v877];
        int * v781 = v732->cache_vals;
        int v881 = ((4 + ((((int)((unsigned int)((int)((unsigned int)v738 >> 2)) >> 1)) & 3) * 2)) + ((((v772 + ((~(((v774 ^ -1) | (-(v774 ^ -1))) >> 31)) & 2)) - (v775 + ((~(((v776 ^ -1) | (-(v776 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
        int v782 = v781[v881];
        int v882 = (((4 + ((((int)((unsigned int)((int)((unsigned int)v738 >> 2)) >> 1)) & 3) * 2)) + ((((v772 + ((~(((v774 ^ -1) | (-(v774 ^ -1))) >> 31)) & 2)) - (v775 + ((~(((v776 ^ -1) | (-(v776 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
        int v783 = v781[v882];
        int * v784 = v732->mem;
        int v884 = v780 * 2;
        v784[v884] = v782;
        int * v786 = v732->mem;
        int v887 = (v780 * 2) + 1;
        v786[v887] = v783;
        ;
      } else {
        ;
      }
      int * v791 = v732->mem;
      int v892 = ((int)((unsigned int)((int)((unsigned int)v738 >> 2)) >> 1)) * 2;
      int v792 = v791[v892];
      int v893 = (((int)((unsigned int)((int)((unsigned int)v738 >> 2)) >> 1)) * 2) + 1;
      int v793 = v791[v893];
      int * v794 = v732->cache_vals;
      int v895 = ((4 + ((((int)((unsigned int)((int)((unsigned int)v738 >> 2)) >> 1)) & 3) * 2)) + ((((v772 + ((~(((v774 ^ -1) | (-(v774 ^ -1))) >> 31)) & 2)) - (v775 + ((~(((v776 ^ -1) | (-(v776 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
      v794[v895] = v792;
      int * v796 = v732->cache_vals;
      int v898 = (((4 + ((((int)((unsigned int)((int)((unsigned int)v738 >> 2)) >> 1)) & 3) * 2)) + ((((v772 + ((~(((v774 ^ -1) | (-(v774 ^ -1))) >> 31)) & 2)) - (v775 + ((~(((v776 ^ -1) | (-(v776 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
      v796[v898] = v793;
      int * v798 = v732->cache_tags;
      int v901 = (int)((unsigned int)((int)((unsigned int)v738 >> 2)) >> 1);
      v798[v877] = v901;
      int * v800 = v732->cache_dirty;
      v800[v877] = 0;
      int * v802 = v732->cache_age;
      v802[v877] = 1;
      int * v804 = v732->cache_age;
      int v805 = v804[v877];
      int v806 = v804[v852];
      int v907 = v806 + ((int)((unsigned int)(v806 - v805) >> 31));
      v804[v852] = v907;
      int * v808 = v732->cache_age;
      int v809 = v808[v853];
      int v909 = v809 + ((int)((unsigned int)(v809 - v805) >> 31));
      v808[v853] = v909;
      int * v811 = v732->cache_age;
      v811[v877] = 0;
      v814 = v877;
    }
    int * v815 = v732->cache_vals;
    int v912 = v814 * 2;
    int v816 = v815[v912];
    int v913 = (v814 * 2) + 1;
    int v817 = v815[v913];
    int v914 = (((((int)((unsigned int)((int)((unsigned int)v738 >> 2)) >> 1)) & 1) * 2) + ((((v756 + ((~(((v758 ^ -1) | (-(v758 ^ -1))) >> 31)) & 2)) - (v759 + ((~(((v760 ^ -1) | (-(v760 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
    v815[v914] = v816;
    int * v819 = v732->cache_vals;
    int v917 = ((((((int)((unsigned int)((int)((unsigned int)v738 >> 2)) >> 1)) & 1) * 2) + ((((v756 + ((~(((v758 ^ -1) | (-(v758 ^ -1))) >> 31)) & 2)) - (v759 + ((~(((v760 ^ -1) | (-(v760 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
    v819[v917] = v817;
    int * v821 = v732->cache_tags;
    int v920 = ((((int)((unsigned int)((int)((unsigned int)v738 >> 2)) >> 1)) & 1) * 2) + ((((v756 + ((~(((v758 ^ -1) | (-(v758 ^ -1))) >> 31)) & 2)) - (v759 + ((~(((v760 ^ -1) | (-(v760 ^ -1))) >> 31)) & 2))) >> 31) & 1);
    int v921 = (int)((unsigned int)((int)((unsigned int)v738 >> 2)) >> 1);
    v821[v920] = v921;
    int * v823 = v732->cache_dirty;
    v823[v920] = 0;
    int * v825 = v732->cache_age;
    v825[v920] = 1;
    int * v827 = v732->cache_age;
    int v828 = v827[v920];
    int v829 = v827[v850];
    int v927 = v829 + ((int)((unsigned int)(v829 - v828) >> 31));
    v827[v850] = v927;
    int * v831 = v732->cache_age;
    int v832 = v831[v851];
    int v929 = v832 + ((int)((unsigned int)(v832 - v828) >> 31));
    v831[v851] = v929;
    int * v834 = v732->cache_age;
    v834[v920] = 0;
    v837 = v920;
  }
  int v932 = (v837 * 2) + (((int)((unsigned int)v738 >> 2)) & 1);
  int v838 = v744[v932];
  int * v839 = v732->reg_ready;
  int v934 = ((v736 + ((v733 - v736) & (~((v733 - v736) >> 31)))) + 1) + ((100 ^ (((~(((v742 ^ ((int)((unsigned int)((int)((unsigned int)v738 >> 2)) >> 1))) | (-(v742 ^ ((int)((unsigned int)((int)((unsigned int)v738 >> 2)) >> 1))))) >> 31)) | (~(((v743 ^ ((int)((unsigned int)((int)((unsigned int)v738 >> 2)) >> 1))) | (-(v743 ^ ((int)((unsigned int)((int)((unsigned int)v738 >> 2)) >> 1))))) >> 31))) & 104)) ^ (((~(((v740 ^ ((int)((unsigned int)((int)((unsigned int)v738 >> 2)) >> 1))) | (-(v740 ^ ((int)((unsigned int)((int)((unsigned int)v738 >> 2)) >> 1))))) >> 31)) | (~(((v741 ^ ((int)((unsigned int)((int)((unsigned int)v738 >> 2)) >> 1))) | (-(v741 ^ ((int)((unsigned int)((int)((unsigned int)v738 >> 2)) >> 1))))) >> 31))) & (1 ^ (100 ^ (((~(((v742 ^ ((int)((unsigned int)((int)((unsigned int)v738 >> 2)) >> 1))) | (-(v742 ^ ((int)((unsigned int)((int)((unsigned int)v738 >> 2)) >> 1))))) >> 31)) | (~(((v743 ^ ((int)((unsigned int)((int)((unsigned int)v738 >> 2)) >> 1))) | (-(v743 ^ ((int)((unsigned int)((int)((unsigned int)v738 >> 2)) >> 1))))) >> 31))) & 104)))));
  v839[10] = v934;
  int * v841 = v732->regs;
  v841[10] = v838;
  struct StateT * v843 = slot_18(v732);
  return v843;
}

struct StateT * slot_20(struct StateT * v1171) {
  int v1172 = v1171->timer;
  int v1345 = v1172 + 1;
  v1171->timer = v1345;
  int * v1174 = v1171->reg_ready;
  int * v1176 = v1171->regs;
  int v1177 = v1176[12];
  int v1179 = v1176[10];
  int * v1180 = v1171->cache_tags;
  int v1351 = (((int)((unsigned int)((int)((unsigned int)(v1177 + 68) >> 2)) >> 1)) & 1) * 2;
  int v1181 = v1180[v1351];
  int v1352 = ((((int)((unsigned int)((int)((unsigned int)(v1177 + 68) >> 2)) >> 1)) & 1) * 2) + 1;
  int v1182 = v1180[v1352];
  int v1353 = 4 + ((((int)((unsigned int)((int)((unsigned int)(v1177 + 68) >> 2)) >> 1)) & 3) * 2);
  int v1183 = v1180[v1353];
  int v1354 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v1177 + 68) >> 2)) >> 1)) & 3) * 2)) + 1;
  int v1184 = v1180[v1354];
  int v1185 = v1171->timer;
  int v1355 = v1185 + ((100 ^ (((~(((v1183 ^ ((int)((unsigned int)((int)((unsigned int)(v1177 + 68) >> 2)) >> 1))) | (-(v1183 ^ ((int)((unsigned int)((int)((unsigned int)(v1177 + 68) >> 2)) >> 1))))) >> 31)) | (~(((v1184 ^ ((int)((unsigned int)((int)((unsigned int)(v1177 + 68) >> 2)) >> 1))) | (-(v1184 ^ ((int)((unsigned int)((int)((unsigned int)(v1177 + 68) >> 2)) >> 1))))) >> 31))) & 104)) ^ (((~(((v1181 ^ ((int)((unsigned int)((int)((unsigned int)(v1177 + 68) >> 2)) >> 1))) | (-(v1181 ^ ((int)((unsigned int)((int)((unsigned int)(v1177 + 68) >> 2)) >> 1))))) >> 31)) | (~(((v1182 ^ ((int)((unsigned int)((int)((unsigned int)(v1177 + 68) >> 2)) >> 1))) | (-(v1182 ^ ((int)((unsigned int)((int)((unsigned int)(v1177 + 68) >> 2)) >> 1))))) >> 31))) & (1 ^ (100 ^ (((~(((v1183 ^ ((int)((unsigned int)((int)((unsigned int)(v1177 + 68) >> 2)) >> 1))) | (-(v1183 ^ ((int)((unsigned int)((int)((unsigned int)(v1177 + 68) >> 2)) >> 1))))) >> 31)) | (~(((v1184 ^ ((int)((unsigned int)((int)((unsigned int)(v1177 + 68) >> 2)) >> 1))) | (-(v1184 ^ ((int)((unsigned int)((int)((unsigned int)(v1177 + 68) >> 2)) >> 1))))) >> 31))) & 104)))));
  v1171->timer = v1355;
  bool v1356 = !(((~(((v1181 ^ ((int)((unsigned int)((int)((unsigned int)(v1177 + 68) >> 2)) >> 1))) | (-(v1181 ^ ((int)((unsigned int)((int)((unsigned int)(v1177 + 68) >> 2)) >> 1))))) >> 31)) | (~(((v1182 ^ ((int)((unsigned int)((int)((unsigned int)(v1177 + 68) >> 2)) >> 1))) | (-(v1182 ^ ((int)((unsigned int)((int)((unsigned int)(v1177 + 68) >> 2)) >> 1))))) >> 31))) == 0);
  int v1279;
  if (v1356) {
    int * v1187 = v1171->cache_age;
    int v1358 = ((((int)((unsigned int)((int)((unsigned int)(v1177 + 68) >> 2)) >> 1)) & 1) * 2) + ((~(((v1182 ^ ((int)((unsigned int)((int)((unsigned int)(v1177 + 68) >> 2)) >> 1))) | (-(v1182 ^ ((int)((unsigned int)((int)((unsigned int)(v1177 + 68) >> 2)) >> 1))))) >> 31)) & 1);
    int v1188 = v1187[v1358];
    int v1189 = v1187[v1351];
    int v1359 = v1189 + ((int)((unsigned int)(v1189 - v1188) >> 31));
    v1187[v1351] = v1359;
    int * v1191 = v1171->cache_age;
    int v1192 = v1191[v1352];
    int v1361 = v1192 + ((int)((unsigned int)(v1192 - v1188) >> 31));
    v1191[v1352] = v1361;
    int * v1194 = v1171->cache_age;
    v1194[v1358] = 0;
    v1279 = v1358;
  } else {
    int * v1197 = v1171->cache_age;
    int v1365 = (((int)((unsigned int)((int)((unsigned int)(v1177 + 68) >> 2)) >> 1)) & 1) * 2;
    int v1198 = v1197[v1365];
    int * v1199 = v1171->cache_tags;
    int v1200 = v1199[v1365];
    int v1201 = v1197[v1352];
    int v1202 = v1199[v1352];
    bool v1367 = !(((~(((v1183 ^ ((int)((unsigned int)((int)((unsigned int)(v1177 + 68) >> 2)) >> 1))) | (-(v1183 ^ ((int)((unsigned int)((int)((unsigned int)(v1177 + 68) >> 2)) >> 1))))) >> 31)) | (~(((v1184 ^ ((int)((unsigned int)((int)((unsigned int)(v1177 + 68) >> 2)) >> 1))) | (-(v1184 ^ ((int)((unsigned int)((int)((unsigned int)(v1177 + 68) >> 2)) >> 1))))) >> 31))) == 0);
    int v1256;
    if (v1367) {
      int * v1203 = v1171->cache_age;
      int v1369 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v1177 + 68) >> 2)) >> 1)) & 3) * 2)) + ((~(((v1184 ^ ((int)((unsigned int)((int)((unsigned int)(v1177 + 68) >> 2)) >> 1))) | (-(v1184 ^ ((int)((unsigned int)((int)((unsigned int)(v1177 + 68) >> 2)) >> 1))))) >> 31)) & 1);
      int v1204 = v1203[v1369];
      int v1205 = v1203[v1353];
      int v1370 = v1205 + ((int)((unsigned int)(v1205 - v1204) >> 31));
      v1203[v1353] = v1370;
      int * v1207 = v1171->cache_age;
      int v1208 = v1207[v1354];
      int v1372 = v1208 + ((int)((unsigned int)(v1208 - v1204) >> 31));
      v1207[v1354] = v1372;
      int * v1210 = v1171->cache_age;
      v1210[v1369] = 0;
      v1256 = v1369;
    } else {
      int * v1213 = v1171->cache_age;
      int v1376 = 4 + ((((int)((unsigned int)((int)((unsigned int)(v1177 + 68) >> 2)) >> 1)) & 3) * 2);
      int v1214 = v1213[v1376];
      int * v1215 = v1171->cache_tags;
      int v1216 = v1215[v1376];
      int v1217 = v1213[v1354];
      int v1218 = v1215[v1354];
      int * v1219 = v1171->cache_dirty;
      int v1379 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v1177 + 68) >> 2)) >> 1)) & 3) * 2)) + ((((v1214 + ((~(((v1216 ^ -1) | (-(v1216 ^ -1))) >> 31)) & 2)) - (v1217 + ((~(((v1218 ^ -1) | (-(v1218 ^ -1))) >> 31)) & 2))) >> 31) & 1);
      int v1220 = v1219[v1379];
      bool v1380 = !(v1220 == 0);
      if (v1380) {
        int * v1221 = v1171->cache_tags;
        int v1222 = v1221[v1379];
        int * v1223 = v1171->cache_vals;
        int v1383 = ((4 + ((((int)((unsigned int)((int)((unsigned int)(v1177 + 68) >> 2)) >> 1)) & 3) * 2)) + ((((v1214 + ((~(((v1216 ^ -1) | (-(v1216 ^ -1))) >> 31)) & 2)) - (v1217 + ((~(((v1218 ^ -1) | (-(v1218 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
        int v1224 = v1223[v1383];
        int v1384 = (((4 + ((((int)((unsigned int)((int)((unsigned int)(v1177 + 68) >> 2)) >> 1)) & 3) * 2)) + ((((v1214 + ((~(((v1216 ^ -1) | (-(v1216 ^ -1))) >> 31)) & 2)) - (v1217 + ((~(((v1218 ^ -1) | (-(v1218 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
        int v1225 = v1223[v1384];
        int * v1226 = v1171->mem;
        int v1386 = v1222 * 2;
        v1226[v1386] = v1224;
        int * v1228 = v1171->mem;
        int v1389 = (v1222 * 2) + 1;
        v1228[v1389] = v1225;
        ;
      } else {
        ;
      }
      int * v1233 = v1171->mem;
      int v1394 = ((int)((unsigned int)((int)((unsigned int)(v1177 + 68) >> 2)) >> 1)) * 2;
      int v1234 = v1233[v1394];
      int v1395 = (((int)((unsigned int)((int)((unsigned int)(v1177 + 68) >> 2)) >> 1)) * 2) + 1;
      int v1235 = v1233[v1395];
      int * v1236 = v1171->cache_vals;
      int v1397 = ((4 + ((((int)((unsigned int)((int)((unsigned int)(v1177 + 68) >> 2)) >> 1)) & 3) * 2)) + ((((v1214 + ((~(((v1216 ^ -1) | (-(v1216 ^ -1))) >> 31)) & 2)) - (v1217 + ((~(((v1218 ^ -1) | (-(v1218 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
      v1236[v1397] = v1234;
      int * v1238 = v1171->cache_vals;
      int v1400 = (((4 + ((((int)((unsigned int)((int)((unsigned int)(v1177 + 68) >> 2)) >> 1)) & 3) * 2)) + ((((v1214 + ((~(((v1216 ^ -1) | (-(v1216 ^ -1))) >> 31)) & 2)) - (v1217 + ((~(((v1218 ^ -1) | (-(v1218 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
      v1238[v1400] = v1235;
      int * v1240 = v1171->cache_tags;
      int v1403 = (int)((unsigned int)((int)((unsigned int)(v1177 + 68) >> 2)) >> 1);
      v1240[v1379] = v1403;
      int * v1242 = v1171->cache_dirty;
      v1242[v1379] = 0;
      int * v1244 = v1171->cache_age;
      v1244[v1379] = 1;
      int * v1246 = v1171->cache_age;
      int v1247 = v1246[v1379];
      int v1248 = v1246[v1353];
      int v1409 = v1248 + ((int)((unsigned int)(v1248 - v1247) >> 31));
      v1246[v1353] = v1409;
      int * v1250 = v1171->cache_age;
      int v1251 = v1250[v1354];
      int v1411 = v1251 + ((int)((unsigned int)(v1251 - v1247) >> 31));
      v1250[v1354] = v1411;
      int * v1253 = v1171->cache_age;
      v1253[v1379] = 0;
      v1256 = v1379;
    }
    int * v1257 = v1171->cache_vals;
    int v1414 = v1256 * 2;
    int v1258 = v1257[v1414];
    int v1415 = (v1256 * 2) + 1;
    int v1259 = v1257[v1415];
    int v1416 = (((((int)((unsigned int)((int)((unsigned int)(v1177 + 68) >> 2)) >> 1)) & 1) * 2) + ((((v1198 + ((~(((v1200 ^ -1) | (-(v1200 ^ -1))) >> 31)) & 2)) - (v1201 + ((~(((v1202 ^ -1) | (-(v1202 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
    v1257[v1416] = v1258;
    int * v1261 = v1171->cache_vals;
    int v1419 = ((((((int)((unsigned int)((int)((unsigned int)(v1177 + 68) >> 2)) >> 1)) & 1) * 2) + ((((v1198 + ((~(((v1200 ^ -1) | (-(v1200 ^ -1))) >> 31)) & 2)) - (v1201 + ((~(((v1202 ^ -1) | (-(v1202 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
    v1261[v1419] = v1259;
    int * v1263 = v1171->cache_tags;
    int v1422 = ((((int)((unsigned int)((int)((unsigned int)(v1177 + 68) >> 2)) >> 1)) & 1) * 2) + ((((v1198 + ((~(((v1200 ^ -1) | (-(v1200 ^ -1))) >> 31)) & 2)) - (v1201 + ((~(((v1202 ^ -1) | (-(v1202 ^ -1))) >> 31)) & 2))) >> 31) & 1);
    int v1423 = (int)((unsigned int)((int)((unsigned int)(v1177 + 68) >> 2)) >> 1);
    v1263[v1422] = v1423;
    int * v1265 = v1171->cache_dirty;
    v1265[v1422] = 0;
    int * v1267 = v1171->cache_age;
    v1267[v1422] = 1;
    int * v1269 = v1171->cache_age;
    int v1270 = v1269[v1422];
    int v1271 = v1269[v1351];
    int v1429 = v1271 + ((int)((unsigned int)(v1271 - v1270) >> 31));
    v1269[v1351] = v1429;
    int * v1273 = v1171->cache_age;
    int v1274 = v1273[v1352];
    int v1431 = v1274 + ((int)((unsigned int)(v1274 - v1270) >> 31));
    v1273[v1352] = v1431;
    int * v1276 = v1171->cache_age;
    v1276[v1422] = 0;
    v1279 = v1422;
  }
  int * v1280 = v1171->cache_vals;
  int v1434 = (v1279 * 2) + (((int)((unsigned int)(v1177 + 68) >> 2)) & 1);
  v1280[v1434] = v1179;
  int * v1282 = v1171->cache_tags;
  int v1283 = v1282[v1353];
  int v1284 = v1282[v1354];
  bool v1437 = !(((~(((v1283 ^ ((int)((unsigned int)((int)((unsigned int)(v1177 + 68) >> 2)) >> 1))) | (-(v1283 ^ ((int)((unsigned int)((int)((unsigned int)(v1177 + 68) >> 2)) >> 1))))) >> 31)) | (~(((v1284 ^ ((int)((unsigned int)((int)((unsigned int)(v1177 + 68) >> 2)) >> 1))) | (-(v1284 ^ ((int)((unsigned int)((int)((unsigned int)(v1177 + 68) >> 2)) >> 1))))) >> 31))) == 0);
  int v1338;
  if (v1437) {
    int * v1285 = v1171->cache_age;
    int v1439 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v1177 + 68) >> 2)) >> 1)) & 3) * 2)) + ((~(((v1284 ^ ((int)((unsigned int)((int)((unsigned int)(v1177 + 68) >> 2)) >> 1))) | (-(v1284 ^ ((int)((unsigned int)((int)((unsigned int)(v1177 + 68) >> 2)) >> 1))))) >> 31)) & 1);
    int v1286 = v1285[v1439];
    int v1287 = v1285[v1353];
    int v1440 = v1287 + ((int)((unsigned int)(v1287 - v1286) >> 31));
    v1285[v1353] = v1440;
    int * v1289 = v1171->cache_age;
    int v1290 = v1289[v1354];
    int v1442 = v1290 + ((int)((unsigned int)(v1290 - v1286) >> 31));
    v1289[v1354] = v1442;
    int * v1292 = v1171->cache_age;
    v1292[v1439] = 0;
    v1338 = v1439;
  } else {
    int * v1295 = v1171->cache_age;
    int v1446 = 4 + ((((int)((unsigned int)((int)((unsigned int)(v1177 + 68) >> 2)) >> 1)) & 3) * 2);
    int v1296 = v1295[v1446];
    int * v1297 = v1171->cache_tags;
    int v1298 = v1297[v1446];
    int v1299 = v1295[v1354];
    int v1300 = v1297[v1354];
    int * v1301 = v1171->cache_dirty;
    int v1449 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v1177 + 68) >> 2)) >> 1)) & 3) * 2)) + ((((v1296 + ((~(((v1298 ^ -1) | (-(v1298 ^ -1))) >> 31)) & 2)) - (v1299 + ((~(((v1300 ^ -1) | (-(v1300 ^ -1))) >> 31)) & 2))) >> 31) & 1);
    int v1302 = v1301[v1449];
    bool v1450 = !(v1302 == 0);
    if (v1450) {
      int * v1303 = v1171->cache_tags;
      int v1304 = v1303[v1449];
      int * v1305 = v1171->cache_vals;
      int v1453 = ((4 + ((((int)((unsigned int)((int)((unsigned int)(v1177 + 68) >> 2)) >> 1)) & 3) * 2)) + ((((v1296 + ((~(((v1298 ^ -1) | (-(v1298 ^ -1))) >> 31)) & 2)) - (v1299 + ((~(((v1300 ^ -1) | (-(v1300 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
      int v1306 = v1305[v1453];
      int v1454 = (((4 + ((((int)((unsigned int)((int)((unsigned int)(v1177 + 68) >> 2)) >> 1)) & 3) * 2)) + ((((v1296 + ((~(((v1298 ^ -1) | (-(v1298 ^ -1))) >> 31)) & 2)) - (v1299 + ((~(((v1300 ^ -1) | (-(v1300 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
      int v1307 = v1305[v1454];
      int * v1308 = v1171->mem;
      int v1456 = v1304 * 2;
      v1308[v1456] = v1306;
      int * v1310 = v1171->mem;
      int v1459 = (v1304 * 2) + 1;
      v1310[v1459] = v1307;
      ;
    } else {
      ;
    }
    int * v1315 = v1171->mem;
    int v1464 = ((int)((unsigned int)((int)((unsigned int)(v1177 + 68) >> 2)) >> 1)) * 2;
    int v1316 = v1315[v1464];
    int v1465 = (((int)((unsigned int)((int)((unsigned int)(v1177 + 68) >> 2)) >> 1)) * 2) + 1;
    int v1317 = v1315[v1465];
    int * v1318 = v1171->cache_vals;
    int v1467 = ((4 + ((((int)((unsigned int)((int)((unsigned int)(v1177 + 68) >> 2)) >> 1)) & 3) * 2)) + ((((v1296 + ((~(((v1298 ^ -1) | (-(v1298 ^ -1))) >> 31)) & 2)) - (v1299 + ((~(((v1300 ^ -1) | (-(v1300 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
    v1318[v1467] = v1316;
    int * v1320 = v1171->cache_vals;
    int v1470 = (((4 + ((((int)((unsigned int)((int)((unsigned int)(v1177 + 68) >> 2)) >> 1)) & 3) * 2)) + ((((v1296 + ((~(((v1298 ^ -1) | (-(v1298 ^ -1))) >> 31)) & 2)) - (v1299 + ((~(((v1300 ^ -1) | (-(v1300 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
    v1320[v1470] = v1317;
    int * v1322 = v1171->cache_tags;
    int v1473 = (int)((unsigned int)((int)((unsigned int)(v1177 + 68) >> 2)) >> 1);
    v1322[v1449] = v1473;
    int * v1324 = v1171->cache_dirty;
    v1324[v1449] = 0;
    int * v1326 = v1171->cache_age;
    v1326[v1449] = 1;
    int * v1328 = v1171->cache_age;
    int v1329 = v1328[v1449];
    int v1330 = v1328[v1353];
    int v1479 = v1330 + ((int)((unsigned int)(v1330 - v1329) >> 31));
    v1328[v1353] = v1479;
    int * v1332 = v1171->cache_age;
    int v1333 = v1332[v1354];
    int v1481 = v1333 + ((int)((unsigned int)(v1333 - v1329) >> 31));
    v1332[v1354] = v1481;
    int * v1335 = v1171->cache_age;
    v1335[v1449] = 0;
    v1338 = v1449;
  }
  int * v1339 = v1171->cache_vals;
  int v1484 = (v1338 * 2) + (((int)((unsigned int)(v1177 + 68) >> 2)) & 1);
  v1339[v1484] = v1179;
  int * v1341 = v1171->cache_dirty;
  v1341[v1338] = 1;
  struct StateT * v1343 = slot_21(v1171);
  return v1343;
}

struct StateT * snippet(struct StateT * v0) {
  struct StateT * v1 = slot_0(v0);
  int v1495 = v1->timer;
  int * v1496 = v1->reg_ready;
  int v1497 = v1496[0];
  int v1628 = v1497 + ((v1495 - v1497) & (~((v1495 - v1497) >> 31)));
  v1->timer = v1628;
  int v1499 = v1->timer;
  int * v1500 = v1->reg_ready;
  int v1501 = v1500[1];
  int v1631 = v1501 + ((v1499 - v1501) & (~((v1499 - v1501) >> 31)));
  v1->timer = v1631;
  int v1503 = v1->timer;
  int * v1504 = v1->reg_ready;
  int v1505 = v1504[2];
  int v1634 = v1505 + ((v1503 - v1505) & (~((v1503 - v1505) >> 31)));
  v1->timer = v1634;
  int v1507 = v1->timer;
  int * v1508 = v1->reg_ready;
  int v1509 = v1508[3];
  int v1637 = v1509 + ((v1507 - v1509) & (~((v1507 - v1509) >> 31)));
  v1->timer = v1637;
  int v1511 = v1->timer;
  int * v1512 = v1->reg_ready;
  int v1513 = v1512[4];
  int v1640 = v1513 + ((v1511 - v1513) & (~((v1511 - v1513) >> 31)));
  v1->timer = v1640;
  int v1515 = v1->timer;
  int * v1516 = v1->reg_ready;
  int v1517 = v1516[5];
  int v1643 = v1517 + ((v1515 - v1517) & (~((v1515 - v1517) >> 31)));
  v1->timer = v1643;
  int v1519 = v1->timer;
  int * v1520 = v1->reg_ready;
  int v1521 = v1520[6];
  int v1646 = v1521 + ((v1519 - v1521) & (~((v1519 - v1521) >> 31)));
  v1->timer = v1646;
  int v1523 = v1->timer;
  int * v1524 = v1->reg_ready;
  int v1525 = v1524[7];
  int v1649 = v1525 + ((v1523 - v1525) & (~((v1523 - v1525) >> 31)));
  v1->timer = v1649;
  int v1527 = v1->timer;
  int * v1528 = v1->reg_ready;
  int v1529 = v1528[8];
  int v1652 = v1529 + ((v1527 - v1529) & (~((v1527 - v1529) >> 31)));
  v1->timer = v1652;
  int v1531 = v1->timer;
  int * v1532 = v1->reg_ready;
  int v1533 = v1532[9];
  int v1655 = v1533 + ((v1531 - v1533) & (~((v1531 - v1533) >> 31)));
  v1->timer = v1655;
  int v1535 = v1->timer;
  int * v1536 = v1->reg_ready;
  int v1537 = v1536[10];
  int v1658 = v1537 + ((v1535 - v1537) & (~((v1535 - v1537) >> 31)));
  v1->timer = v1658;
  int v1539 = v1->timer;
  int * v1540 = v1->reg_ready;
  int v1541 = v1540[11];
  int v1661 = v1541 + ((v1539 - v1541) & (~((v1539 - v1541) >> 31)));
  v1->timer = v1661;
  int v1543 = v1->timer;
  int * v1544 = v1->reg_ready;
  int v1545 = v1544[12];
  int v1664 = v1545 + ((v1543 - v1545) & (~((v1543 - v1545) >> 31)));
  v1->timer = v1664;
  int v1547 = v1->timer;
  int * v1548 = v1->reg_ready;
  int v1549 = v1548[13];
  int v1667 = v1549 + ((v1547 - v1549) & (~((v1547 - v1549) >> 31)));
  v1->timer = v1667;
  int v1551 = v1->timer;
  int * v1552 = v1->reg_ready;
  int v1553 = v1552[14];
  int v1670 = v1553 + ((v1551 - v1553) & (~((v1551 - v1553) >> 31)));
  v1->timer = v1670;
  int v1555 = v1->timer;
  int * v1556 = v1->reg_ready;
  int v1557 = v1556[15];
  int v1673 = v1557 + ((v1555 - v1557) & (~((v1555 - v1557) >> 31)));
  v1->timer = v1673;
  int v1559 = v1->timer;
  int * v1560 = v1->reg_ready;
  int v1561 = v1560[16];
  int v1676 = v1561 + ((v1559 - v1561) & (~((v1559 - v1561) >> 31)));
  v1->timer = v1676;
  int v1563 = v1->timer;
  int * v1564 = v1->reg_ready;
  int v1565 = v1564[17];
  int v1679 = v1565 + ((v1563 - v1565) & (~((v1563 - v1565) >> 31)));
  v1->timer = v1679;
  int v1567 = v1->timer;
  int * v1568 = v1->reg_ready;
  int v1569 = v1568[18];
  int v1682 = v1569 + ((v1567 - v1569) & (~((v1567 - v1569) >> 31)));
  v1->timer = v1682;
  int v1571 = v1->timer;
  int * v1572 = v1->reg_ready;
  int v1573 = v1572[19];
  int v1685 = v1573 + ((v1571 - v1573) & (~((v1571 - v1573) >> 31)));
  v1->timer = v1685;
  int v1575 = v1->timer;
  int * v1576 = v1->reg_ready;
  int v1577 = v1576[20];
  int v1688 = v1577 + ((v1575 - v1577) & (~((v1575 - v1577) >> 31)));
  v1->timer = v1688;
  int v1579 = v1->timer;
  int * v1580 = v1->reg_ready;
  int v1581 = v1580[21];
  int v1691 = v1581 + ((v1579 - v1581) & (~((v1579 - v1581) >> 31)));
  v1->timer = v1691;
  int v1583 = v1->timer;
  int * v1584 = v1->reg_ready;
  int v1585 = v1584[22];
  int v1694 = v1585 + ((v1583 - v1585) & (~((v1583 - v1585) >> 31)));
  v1->timer = v1694;
  int v1587 = v1->timer;
  int * v1588 = v1->reg_ready;
  int v1589 = v1588[23];
  int v1697 = v1589 + ((v1587 - v1589) & (~((v1587 - v1589) >> 31)));
  v1->timer = v1697;
  int v1591 = v1->timer;
  int * v1592 = v1->reg_ready;
  int v1593 = v1592[24];
  int v1700 = v1593 + ((v1591 - v1593) & (~((v1591 - v1593) >> 31)));
  v1->timer = v1700;
  int v1595 = v1->timer;
  int * v1596 = v1->reg_ready;
  int v1597 = v1596[25];
  int v1703 = v1597 + ((v1595 - v1597) & (~((v1595 - v1597) >> 31)));
  v1->timer = v1703;
  int v1599 = v1->timer;
  int * v1600 = v1->reg_ready;
  int v1601 = v1600[26];
  int v1706 = v1601 + ((v1599 - v1601) & (~((v1599 - v1601) >> 31)));
  v1->timer = v1706;
  int v1603 = v1->timer;
  int * v1604 = v1->reg_ready;
  int v1605 = v1604[27];
  int v1709 = v1605 + ((v1603 - v1605) & (~((v1603 - v1605) >> 31)));
  v1->timer = v1709;
  int v1607 = v1->timer;
  int * v1608 = v1->reg_ready;
  int v1609 = v1608[28];
  int v1712 = v1609 + ((v1607 - v1609) & (~((v1607 - v1609) >> 31)));
  v1->timer = v1712;
  int v1611 = v1->timer;
  int * v1612 = v1->reg_ready;
  int v1613 = v1612[29];
  int v1715 = v1613 + ((v1611 - v1613) & (~((v1611 - v1613) >> 31)));
  v1->timer = v1715;
  int v1615 = v1->timer;
  int * v1616 = v1->reg_ready;
  int v1617 = v1616[30];
  int v1718 = v1617 + ((v1615 - v1617) & (~((v1615 - v1617) >> 31)));
  v1->timer = v1718;
  int v1619 = v1->timer;
  int * v1620 = v1->reg_ready;
  int v1621 = v1620[31];
  int v1721 = v1621 + ((v1619 - v1621) & (~((v1619 - v1621) >> 31)));
  v1->timer = v1721;
  return v1;
}

struct StateT * slot_8(struct StateT * v361) {
  int v362 = v361->timer;
  int v373 = v362 + 1;
  v361->timer = v373;
  int * v364 = v361->reg_ready;
  int v365 = v364[10];
  int * v366 = v361->regs;
  int v367 = v366[10];
  int v377 = (v365 + ((v362 - v365) & (~((v362 - v365) >> 31)))) + 1;
  v364[10] = v377;
  int * v369 = v361->regs;
  int v379 = v367 << 2;
  v369[10] = v379;
  struct StateT * v371 = slot_9(v361);
  return v371;
}

struct StateT * slot_4(struct StateT * v279) {
  int v280 = v279->timer;
  int v288 = v280 + 1;
  v279->timer = v288;
  int * v282 = v279->reg_ready;
  v282[11] = v288;
  int * v284 = v279->regs;
  v284[11] = 0;
  struct StateT * v286 = slot_5(v279);
  return v286;
}

struct StateT * slot_15(struct StateT * v687) {
  int v688 = v687->timer;
  int v699 = v688 + 1;
  v687->timer = v699;
  int * v690 = v687->reg_ready;
  int v691 = v690[10];
  int * v692 = v687->regs;
  int v693 = v692[10];
  int v703 = (v691 + ((v688 - v691) & (~((v688 - v691) >> 31)))) + 1;
  v690[10] = v703;
  int * v695 = v687->regs;
  int v705 = (int)((unsigned int)v693 >> 26);
  v695[10] = v705;
  struct StateT * v697 = slot_16(v687);
  return v697;
}

struct StateT * slot_18(struct StateT * v939) {
  int v940 = v939->timer;
  int v1052 = v940 + 1;
  v939->timer = v1052;
  int * v942 = v939->reg_ready;
  int v943 = v942[12];
  int * v944 = v939->regs;
  int v945 = v944[12];
  int * v946 = v939->cache_tags;
  int v1057 = (((int)((unsigned int)((int)((unsigned int)(v945 + 68) >> 2)) >> 1)) & 1) * 2;
  int v947 = v946[v1057];
  int v1058 = ((((int)((unsigned int)((int)((unsigned int)(v945 + 68) >> 2)) >> 1)) & 1) * 2) + 1;
  int v948 = v946[v1058];
  int v1059 = 4 + ((((int)((unsigned int)((int)((unsigned int)(v945 + 68) >> 2)) >> 1)) & 3) * 2);
  int v949 = v946[v1059];
  int v1060 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v945 + 68) >> 2)) >> 1)) & 3) * 2)) + 1;
  int v950 = v946[v1060];
  int * v951 = v939->cache_vals;
  bool v1061 = !(((~(((v947 ^ ((int)((unsigned int)((int)((unsigned int)(v945 + 68) >> 2)) >> 1))) | (-(v947 ^ ((int)((unsigned int)((int)((unsigned int)(v945 + 68) >> 2)) >> 1))))) >> 31)) | (~(((v948 ^ ((int)((unsigned int)((int)((unsigned int)(v945 + 68) >> 2)) >> 1))) | (-(v948 ^ ((int)((unsigned int)((int)((unsigned int)(v945 + 68) >> 2)) >> 1))))) >> 31))) == 0);
  int v1044;
  if (v1061) {
    int * v952 = v939->cache_age;
    int v1063 = ((((int)((unsigned int)((int)((unsigned int)(v945 + 68) >> 2)) >> 1)) & 1) * 2) + ((~(((v948 ^ ((int)((unsigned int)((int)((unsigned int)(v945 + 68) >> 2)) >> 1))) | (-(v948 ^ ((int)((unsigned int)((int)((unsigned int)(v945 + 68) >> 2)) >> 1))))) >> 31)) & 1);
    int v953 = v952[v1063];
    int v954 = v952[v1057];
    int v1064 = v954 + ((int)((unsigned int)(v954 - v953) >> 31));
    v952[v1057] = v1064;
    int * v956 = v939->cache_age;
    int v957 = v956[v1058];
    int v1066 = v957 + ((int)((unsigned int)(v957 - v953) >> 31));
    v956[v1058] = v1066;
    int * v959 = v939->cache_age;
    v959[v1063] = 0;
    v1044 = v1063;
  } else {
    int * v962 = v939->cache_age;
    int v1070 = (((int)((unsigned int)((int)((unsigned int)(v945 + 68) >> 2)) >> 1)) & 1) * 2;
    int v963 = v962[v1070];
    int * v964 = v939->cache_tags;
    int v965 = v964[v1070];
    int v966 = v962[v1058];
    int v967 = v964[v1058];
    bool v1072 = !(((~(((v949 ^ ((int)((unsigned int)((int)((unsigned int)(v945 + 68) >> 2)) >> 1))) | (-(v949 ^ ((int)((unsigned int)((int)((unsigned int)(v945 + 68) >> 2)) >> 1))))) >> 31)) | (~(((v950 ^ ((int)((unsigned int)((int)((unsigned int)(v945 + 68) >> 2)) >> 1))) | (-(v950 ^ ((int)((unsigned int)((int)((unsigned int)(v945 + 68) >> 2)) >> 1))))) >> 31))) == 0);
    int v1021;
    if (v1072) {
      int * v968 = v939->cache_age;
      int v1074 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v945 + 68) >> 2)) >> 1)) & 3) * 2)) + ((~(((v950 ^ ((int)((unsigned int)((int)((unsigned int)(v945 + 68) >> 2)) >> 1))) | (-(v950 ^ ((int)((unsigned int)((int)((unsigned int)(v945 + 68) >> 2)) >> 1))))) >> 31)) & 1);
      int v969 = v968[v1074];
      int v970 = v968[v1059];
      int v1075 = v970 + ((int)((unsigned int)(v970 - v969) >> 31));
      v968[v1059] = v1075;
      int * v972 = v939->cache_age;
      int v973 = v972[v1060];
      int v1077 = v973 + ((int)((unsigned int)(v973 - v969) >> 31));
      v972[v1060] = v1077;
      int * v975 = v939->cache_age;
      v975[v1074] = 0;
      v1021 = v1074;
    } else {
      int * v978 = v939->cache_age;
      int v1081 = 4 + ((((int)((unsigned int)((int)((unsigned int)(v945 + 68) >> 2)) >> 1)) & 3) * 2);
      int v979 = v978[v1081];
      int * v980 = v939->cache_tags;
      int v981 = v980[v1081];
      int v982 = v978[v1060];
      int v983 = v980[v1060];
      int * v984 = v939->cache_dirty;
      int v1084 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v945 + 68) >> 2)) >> 1)) & 3) * 2)) + ((((v979 + ((~(((v981 ^ -1) | (-(v981 ^ -1))) >> 31)) & 2)) - (v982 + ((~(((v983 ^ -1) | (-(v983 ^ -1))) >> 31)) & 2))) >> 31) & 1);
      int v985 = v984[v1084];
      bool v1085 = !(v985 == 0);
      if (v1085) {
        int * v986 = v939->cache_tags;
        int v987 = v986[v1084];
        int * v988 = v939->cache_vals;
        int v1088 = ((4 + ((((int)((unsigned int)((int)((unsigned int)(v945 + 68) >> 2)) >> 1)) & 3) * 2)) + ((((v979 + ((~(((v981 ^ -1) | (-(v981 ^ -1))) >> 31)) & 2)) - (v982 + ((~(((v983 ^ -1) | (-(v983 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
        int v989 = v988[v1088];
        int v1089 = (((4 + ((((int)((unsigned int)((int)((unsigned int)(v945 + 68) >> 2)) >> 1)) & 3) * 2)) + ((((v979 + ((~(((v981 ^ -1) | (-(v981 ^ -1))) >> 31)) & 2)) - (v982 + ((~(((v983 ^ -1) | (-(v983 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
        int v990 = v988[v1089];
        int * v991 = v939->mem;
        int v1091 = v987 * 2;
        v991[v1091] = v989;
        int * v993 = v939->mem;
        int v1094 = (v987 * 2) + 1;
        v993[v1094] = v990;
        ;
      } else {
        ;
      }
      int * v998 = v939->mem;
      int v1099 = ((int)((unsigned int)((int)((unsigned int)(v945 + 68) >> 2)) >> 1)) * 2;
      int v999 = v998[v1099];
      int v1100 = (((int)((unsigned int)((int)((unsigned int)(v945 + 68) >> 2)) >> 1)) * 2) + 1;
      int v1000 = v998[v1100];
      int * v1001 = v939->cache_vals;
      int v1102 = ((4 + ((((int)((unsigned int)((int)((unsigned int)(v945 + 68) >> 2)) >> 1)) & 3) * 2)) + ((((v979 + ((~(((v981 ^ -1) | (-(v981 ^ -1))) >> 31)) & 2)) - (v982 + ((~(((v983 ^ -1) | (-(v983 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
      v1001[v1102] = v999;
      int * v1003 = v939->cache_vals;
      int v1105 = (((4 + ((((int)((unsigned int)((int)((unsigned int)(v945 + 68) >> 2)) >> 1)) & 3) * 2)) + ((((v979 + ((~(((v981 ^ -1) | (-(v981 ^ -1))) >> 31)) & 2)) - (v982 + ((~(((v983 ^ -1) | (-(v983 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
      v1003[v1105] = v1000;
      int * v1005 = v939->cache_tags;
      int v1108 = (int)((unsigned int)((int)((unsigned int)(v945 + 68) >> 2)) >> 1);
      v1005[v1084] = v1108;
      int * v1007 = v939->cache_dirty;
      v1007[v1084] = 0;
      int * v1009 = v939->cache_age;
      v1009[v1084] = 1;
      int * v1011 = v939->cache_age;
      int v1012 = v1011[v1084];
      int v1013 = v1011[v1059];
      int v1114 = v1013 + ((int)((unsigned int)(v1013 - v1012) >> 31));
      v1011[v1059] = v1114;
      int * v1015 = v939->cache_age;
      int v1016 = v1015[v1060];
      int v1116 = v1016 + ((int)((unsigned int)(v1016 - v1012) >> 31));
      v1015[v1060] = v1116;
      int * v1018 = v939->cache_age;
      v1018[v1084] = 0;
      v1021 = v1084;
    }
    int * v1022 = v939->cache_vals;
    int v1119 = v1021 * 2;
    int v1023 = v1022[v1119];
    int v1120 = (v1021 * 2) + 1;
    int v1024 = v1022[v1120];
    int v1121 = (((((int)((unsigned int)((int)((unsigned int)(v945 + 68) >> 2)) >> 1)) & 1) * 2) + ((((v963 + ((~(((v965 ^ -1) | (-(v965 ^ -1))) >> 31)) & 2)) - (v966 + ((~(((v967 ^ -1) | (-(v967 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
    v1022[v1121] = v1023;
    int * v1026 = v939->cache_vals;
    int v1124 = ((((((int)((unsigned int)((int)((unsigned int)(v945 + 68) >> 2)) >> 1)) & 1) * 2) + ((((v963 + ((~(((v965 ^ -1) | (-(v965 ^ -1))) >> 31)) & 2)) - (v966 + ((~(((v967 ^ -1) | (-(v967 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
    v1026[v1124] = v1024;
    int * v1028 = v939->cache_tags;
    int v1127 = ((((int)((unsigned int)((int)((unsigned int)(v945 + 68) >> 2)) >> 1)) & 1) * 2) + ((((v963 + ((~(((v965 ^ -1) | (-(v965 ^ -1))) >> 31)) & 2)) - (v966 + ((~(((v967 ^ -1) | (-(v967 ^ -1))) >> 31)) & 2))) >> 31) & 1);
    int v1128 = (int)((unsigned int)((int)((unsigned int)(v945 + 68) >> 2)) >> 1);
    v1028[v1127] = v1128;
    int * v1030 = v939->cache_dirty;
    v1030[v1127] = 0;
    int * v1032 = v939->cache_age;
    v1032[v1127] = 1;
    int * v1034 = v939->cache_age;
    int v1035 = v1034[v1127];
    int v1036 = v1034[v1057];
    int v1134 = v1036 + ((int)((unsigned int)(v1036 - v1035) >> 31));
    v1034[v1057] = v1134;
    int * v1038 = v939->cache_age;
    int v1039 = v1038[v1058];
    int v1136 = v1039 + ((int)((unsigned int)(v1039 - v1035) >> 31));
    v1038[v1058] = v1136;
    int * v1041 = v939->cache_age;
    v1041[v1127] = 0;
    v1044 = v1127;
  }
  int v1139 = (v1044 * 2) + (((int)((unsigned int)(v945 + 68) >> 2)) & 1);
  int v1045 = v951[v1139];
  int * v1046 = v939->reg_ready;
  int v1142 = ((v943 + ((v940 - v943) & (~((v940 - v943) >> 31)))) + 1) + ((100 ^ (((~(((v949 ^ ((int)((unsigned int)((int)((unsigned int)(v945 + 68) >> 2)) >> 1))) | (-(v949 ^ ((int)((unsigned int)((int)((unsigned int)(v945 + 68) >> 2)) >> 1))))) >> 31)) | (~(((v950 ^ ((int)((unsigned int)((int)((unsigned int)(v945 + 68) >> 2)) >> 1))) | (-(v950 ^ ((int)((unsigned int)((int)((unsigned int)(v945 + 68) >> 2)) >> 1))))) >> 31))) & 104)) ^ (((~(((v947 ^ ((int)((unsigned int)((int)((unsigned int)(v945 + 68) >> 2)) >> 1))) | (-(v947 ^ ((int)((unsigned int)((int)((unsigned int)(v945 + 68) >> 2)) >> 1))))) >> 31)) | (~(((v948 ^ ((int)((unsigned int)((int)((unsigned int)(v945 + 68) >> 2)) >> 1))) | (-(v948 ^ ((int)((unsigned int)((int)((unsigned int)(v945 + 68) >> 2)) >> 1))))) >> 31))) & (1 ^ (100 ^ (((~(((v949 ^ ((int)((unsigned int)((int)((unsigned int)(v945 + 68) >> 2)) >> 1))) | (-(v949 ^ ((int)((unsigned int)((int)((unsigned int)(v945 + 68) >> 2)) >> 1))))) >> 31)) | (~(((v950 ^ ((int)((unsigned int)((int)((unsigned int)(v945 + 68) >> 2)) >> 1))) | (-(v950 ^ ((int)((unsigned int)((int)((unsigned int)(v945 + 68) >> 2)) >> 1))))) >> 31))) & 104)))));
  v1046[11] = v1142;
  int * v1048 = v939->regs;
  v1048[11] = v1045;
  struct StateT * v1050 = slot_19(v939);
  return v1050;
}

struct StateT * slot_9(struct StateT * v382) {
  int v383 = v382->timer;
  int v396 = v383 + 1;
  v382->timer = v396;
  int * v385 = v382->reg_ready;
  int v386 = v385[11];
  int * v387 = v382->regs;
  int v388 = v387[11];
  int v389 = v385[10];
  int v390 = v387[10];
  int v401 = (v389 + (((v386 + ((v383 - v386) & (~((v383 - v386) >> 31)))) - v389) & (~(((v386 + ((v383 - v386) & (~((v383 - v386) >> 31)))) - v389) >> 31)))) + 1;
  v385[10] = v401;
  int * v392 = v382->regs;
  int v403 = v388 + v390;
  v392[10] = v403;
  struct StateT * v394 = slot_10(v382);
  return v394;
}

struct StateT * slot_11(struct StateT * v613) {
  int v614 = v613->timer;
  int v622 = v614 + 1;
  v613->timer = v622;
  int * v616 = v613->reg_ready;
  v616[11] = v622;
  int * v618 = v613->regs;
  v618[11] = 0;
  struct StateT * v620 = slot_12(v613);
  return v620;
}



/*****************************************
End of C Generated Code
*******************************************/

void init(struct StateT *s) {
  for (int i=0; i<NUM_REGS; i++) {
    s->regs[i] = 0;
    s->saved_regs[i] = 0;
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
  
  // public data, where the section headers put it
  s1.mem[0] = 8;
  s2.mem[0] = 8;
  int x = bounded(0, 15);
  s1.regs[10] = x;
  s2.regs[10] = x;
  // probe, the attacker's: the same draw in both states
  for (int i=0; i<16; i++) {
    int v = bounded(0, 20);
    s1.mem[1 + i] = v;
    s2.mem[1 + i] = v;
  }
  // temp, the attacker's: the same draw in both states
  for (int i=0; i<1; i++) {
    int v = bounded(0, 20);
    s1.mem[17 + i] = v;
    s2.mem[17 + i] = v;
  }
  // publicarray, the attacker's: the same draw in both states
  for (int i=0; i<8; i++) {
    int v = bounded(0, 20);
    s1.mem[18 + i] = v;
    s2.mem[18 + i] = v;
  }
  
  // secretarray, secret: a different draw in each state
  for (int i=0; i<8; i++) {
    s1.mem[26 + i] = secret(0, 20);
    s2.mem[26 + i] = secret(0, 20);
  }
  struct StateT *s1_ = snippet(&s1);
  struct StateT *s2_ = snippet(&s2);
  //@ assert untainted_timer: !\tainted(s1_->timer==s2_->timer);
  koika_assert(s1_->timer==s2_->timer, "timing leak");
  return 0;
}