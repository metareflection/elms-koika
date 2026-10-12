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

struct StateT * slot_12(struct StateT * v940);
struct StateT * slot_6(struct StateT * v467);
struct StateT * slot_16(struct StateT * v1014);
struct StateT * slot_5(struct StateT * v445);
struct StateT * slot_2(struct StateT * v409);
struct StateT * slot_7(struct StateT * v483);
struct StateT * slot_21(struct StateT * v1417);
struct StateT * slot_3(struct StateT * v421);
struct StateT * slot_10(struct StateT * v714);
struct StateT * slot_1(struct StateT * v205);
struct StateT * slot_19(struct StateT * v1398);
struct StateT * slot_13(struct StateT * v963);
struct StateT * slot_0(struct StateT * v2);
struct StateT * slot_14(struct StateT * v984);
struct StateT * slot_17(struct StateT * v1069);
struct StateT * slot_20(struct StateT * v1412);
struct StateT * snippet(struct StateT * v0);
struct StateT * slot_8(struct StateT * v686);
struct StateT * slot_4(struct StateT * v437);
struct StateT * slot_15(struct StateT * v998);
struct StateT * slot_18(struct StateT * v1083);
struct StateT * slot_9(struct StateT * v700);
struct StateT * slot_11(struct StateT * v737);
struct StateT * slot_12(struct StateT * v940) {
  int * v941 = v940->saved_regs;
  int * v942 = v940->regs;
  int v943 = v942[12];
  v941[12] = v943;
  int v945 = v940->timer;
  int v957 = v945 + 1;
  v940->timer = v957;
  int * v947 = v940->regs;
  int v948 = v947[12];
  int v949 = v947[11];
  int v960 = v948 + v949;
  v947[12] = v960;
  struct StateT * v951 = slot_13(v940);
  return v951;
}

struct StateT * slot_6(struct StateT * v467) {
  int v468 = v467->timer;
  int v476 = v468 + 1;
  v467->timer = v476;
  int * v470 = v467->regs;
  int v471 = v470[11];
  int v472 = v470[14];
  int v480 = v471 + v472;
  v470[14] = v480;
  struct StateT * v474 = slot_7(v467);
  return v474;
}

struct StateT * slot_16(struct StateT * v1014) {
  int * v1015 = v1014->regs;
  int v1016 = v1015[15];
  int * v1017 = v1014->saved_regs;
  int v1018 = v1017[10];
  bool v1047 = (v1016 ^ -2147483648) < (v1018 ^ -2147483648);
  struct StateT * v1041;
  if (v1047) {
    int v1019 = v1014->timer;
    int v1048 = v1019 + 15;
    v1014->timer = v1048;
    int * v1021 = v1014->saved_regs;
    int v1022 = v1021[14];
    int * v1023 = v1014->regs;
    v1023[14] = v1022;
    int * v1025 = v1014->saved_regs;
    int v1026 = v1025[11];
    int * v1027 = v1014->regs;
    v1027[11] = v1026;
    int * v1029 = v1014->saved_regs;
    int v1030 = v1029[12];
    int * v1031 = v1014->regs;
    v1031[12] = v1030;
    int * v1033 = v1014->saved_regs;
    int v1034 = v1033[10];
    int * v1035 = v1014->regs;
    v1035[10] = v1034;
    struct StateT * v1037 = slot_17(v1014);
    v1041 = v1037;
  } else {
    struct StateT * v1039 = slot_18(v1014);
    v1041 = v1039;
  }
  return v1041;
}

struct StateT * slot_5(struct StateT * v445) {
  int * v446 = v445->saved_regs;
  int * v447 = v445->regs;
  int v448 = v447[14];
  v446[14] = v448;
  int v450 = v445->timer;
  int v461 = v450 + 1;
  v445->timer = v461;
  int * v452 = v445->regs;
  int v453 = v452[10];
  int v464 = v453 << 2;
  v452[14] = v464;
  struct StateT * v455 = slot_6(v445);
  return v455;
}

struct StateT * slot_2(struct StateT * v409) {
  int v410 = v409->timer;
  int v416 = v410 + 1;
  v409->timer = v416;
  int * v412 = v409->regs;
  v412[15] = 15;
  struct StateT * v414 = slot_3(v409);
  return v414;
}

struct StateT * slot_7(struct StateT * v483) {
  int v484 = v483->timer;
  int v594 = v484 + 1;
  v483->timer = v594;
  int * v486 = v483->regs;
  int v487 = v486[14];
  int * v488 = v483->cache_tags;
  int v598 = (((int)((unsigned int)((int)((unsigned int)v487 >> 2)) >> 1)) & 1) * 2;
  int v489 = v488[v598];
  int v599 = ((((int)((unsigned int)((int)((unsigned int)v487 >> 2)) >> 1)) & 1) * 2) + 1;
  int v490 = v488[v599];
  int v600 = 4 + ((((int)((unsigned int)((int)((unsigned int)v487 >> 2)) >> 1)) & 3) * 2);
  int v491 = v488[v600];
  int v601 = (4 + ((((int)((unsigned int)((int)((unsigned int)v487 >> 2)) >> 1)) & 3) * 2)) + 1;
  int v492 = v488[v601];
  int v493 = v483->timer;
  int v602 = v493 + ((100 ^ (((~(((v491 ^ ((int)((unsigned int)((int)((unsigned int)v487 >> 2)) >> 1))) | (-(v491 ^ ((int)((unsigned int)((int)((unsigned int)v487 >> 2)) >> 1))))) >> 31)) | (~(((v492 ^ ((int)((unsigned int)((int)((unsigned int)v487 >> 2)) >> 1))) | (-(v492 ^ ((int)((unsigned int)((int)((unsigned int)v487 >> 2)) >> 1))))) >> 31))) & 104)) ^ (((~(((v489 ^ ((int)((unsigned int)((int)((unsigned int)v487 >> 2)) >> 1))) | (-(v489 ^ ((int)((unsigned int)((int)((unsigned int)v487 >> 2)) >> 1))))) >> 31)) | (~(((v490 ^ ((int)((unsigned int)((int)((unsigned int)v487 >> 2)) >> 1))) | (-(v490 ^ ((int)((unsigned int)((int)((unsigned int)v487 >> 2)) >> 1))))) >> 31))) & (1 ^ (100 ^ (((~(((v491 ^ ((int)((unsigned int)((int)((unsigned int)v487 >> 2)) >> 1))) | (-(v491 ^ ((int)((unsigned int)((int)((unsigned int)v487 >> 2)) >> 1))))) >> 31)) | (~(((v492 ^ ((int)((unsigned int)((int)((unsigned int)v487 >> 2)) >> 1))) | (-(v492 ^ ((int)((unsigned int)((int)((unsigned int)v487 >> 2)) >> 1))))) >> 31))) & 104)))));
  v483->timer = v602;
  int * v495 = v483->cache_vals;
  bool v603 = !(((~(((v489 ^ ((int)((unsigned int)((int)((unsigned int)v487 >> 2)) >> 1))) | (-(v489 ^ ((int)((unsigned int)((int)((unsigned int)v487 >> 2)) >> 1))))) >> 31)) | (~(((v490 ^ ((int)((unsigned int)((int)((unsigned int)v487 >> 2)) >> 1))) | (-(v490 ^ ((int)((unsigned int)((int)((unsigned int)v487 >> 2)) >> 1))))) >> 31))) == 0);
  int v588;
  if (v603) {
    int * v496 = v483->cache_age;
    int v605 = ((((int)((unsigned int)((int)((unsigned int)v487 >> 2)) >> 1)) & 1) * 2) + ((~(((v490 ^ ((int)((unsigned int)((int)((unsigned int)v487 >> 2)) >> 1))) | (-(v490 ^ ((int)((unsigned int)((int)((unsigned int)v487 >> 2)) >> 1))))) >> 31)) & 1);
    int v497 = v496[v605];
    int v498 = v496[v598];
    int v606 = v498 + ((int)((unsigned int)(v498 - v497) >> 31));
    v496[v598] = v606;
    int * v500 = v483->cache_age;
    int v501 = v500[v599];
    int v608 = v501 + ((int)((unsigned int)(v501 - v497) >> 31));
    v500[v599] = v608;
    int * v503 = v483->cache_age;
    v503[v605] = 0;
    v588 = v605;
  } else {
    int * v506 = v483->cache_age;
    int v612 = (((int)((unsigned int)((int)((unsigned int)v487 >> 2)) >> 1)) & 1) * 2;
    int v507 = v506[v612];
    int * v508 = v483->cache_tags;
    int v509 = v508[v612];
    int v510 = v506[v599];
    int v511 = v508[v599];
    bool v614 = !(((~(((v491 ^ ((int)((unsigned int)((int)((unsigned int)v487 >> 2)) >> 1))) | (-(v491 ^ ((int)((unsigned int)((int)((unsigned int)v487 >> 2)) >> 1))))) >> 31)) | (~(((v492 ^ ((int)((unsigned int)((int)((unsigned int)v487 >> 2)) >> 1))) | (-(v492 ^ ((int)((unsigned int)((int)((unsigned int)v487 >> 2)) >> 1))))) >> 31))) == 0);
    int v565;
    if (v614) {
      int * v512 = v483->cache_age;
      int v616 = (4 + ((((int)((unsigned int)((int)((unsigned int)v487 >> 2)) >> 1)) & 3) * 2)) + ((~(((v492 ^ ((int)((unsigned int)((int)((unsigned int)v487 >> 2)) >> 1))) | (-(v492 ^ ((int)((unsigned int)((int)((unsigned int)v487 >> 2)) >> 1))))) >> 31)) & 1);
      int v513 = v512[v616];
      int v514 = v512[v600];
      int v617 = v514 + ((int)((unsigned int)(v514 - v513) >> 31));
      v512[v600] = v617;
      int * v516 = v483->cache_age;
      int v517 = v516[v601];
      int v619 = v517 + ((int)((unsigned int)(v517 - v513) >> 31));
      v516[v601] = v619;
      int * v519 = v483->cache_age;
      v519[v616] = 0;
      v565 = v616;
    } else {
      int * v522 = v483->cache_age;
      int v623 = 4 + ((((int)((unsigned int)((int)((unsigned int)v487 >> 2)) >> 1)) & 3) * 2);
      int v523 = v522[v623];
      int * v524 = v483->cache_tags;
      int v525 = v524[v623];
      int v526 = v522[v601];
      int v527 = v524[v601];
      int * v528 = v483->cache_dirty;
      int v626 = (4 + ((((int)((unsigned int)((int)((unsigned int)v487 >> 2)) >> 1)) & 3) * 2)) + ((((v523 + ((~(((v525 ^ -1) | (-(v525 ^ -1))) >> 31)) & 2)) - (v526 + ((~(((v527 ^ -1) | (-(v527 ^ -1))) >> 31)) & 2))) >> 31) & 1);
      int v529 = v528[v626];
      bool v627 = !(v529 == 0);
      if (v627) {
        int * v530 = v483->cache_tags;
        int v531 = v530[v626];
        int * v532 = v483->cache_vals;
        int v630 = ((4 + ((((int)((unsigned int)((int)((unsigned int)v487 >> 2)) >> 1)) & 3) * 2)) + ((((v523 + ((~(((v525 ^ -1) | (-(v525 ^ -1))) >> 31)) & 2)) - (v526 + ((~(((v527 ^ -1) | (-(v527 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
        int v533 = v532[v630];
        int v631 = (((4 + ((((int)((unsigned int)((int)((unsigned int)v487 >> 2)) >> 1)) & 3) * 2)) + ((((v523 + ((~(((v525 ^ -1) | (-(v525 ^ -1))) >> 31)) & 2)) - (v526 + ((~(((v527 ^ -1) | (-(v527 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
        int v534 = v532[v631];
        int * v535 = v483->mem;
        int v633 = v531 * 2;
        v535[v633] = v533;
        int * v537 = v483->mem;
        int v636 = (v531 * 2) + 1;
        v537[v636] = v534;
        ;
      } else {
        ;
      }
      int * v542 = v483->mem;
      int v641 = ((int)((unsigned int)((int)((unsigned int)v487 >> 2)) >> 1)) * 2;
      int v543 = v542[v641];
      int v642 = (((int)((unsigned int)((int)((unsigned int)v487 >> 2)) >> 1)) * 2) + 1;
      int v544 = v542[v642];
      int * v545 = v483->cache_vals;
      int v644 = ((4 + ((((int)((unsigned int)((int)((unsigned int)v487 >> 2)) >> 1)) & 3) * 2)) + ((((v523 + ((~(((v525 ^ -1) | (-(v525 ^ -1))) >> 31)) & 2)) - (v526 + ((~(((v527 ^ -1) | (-(v527 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
      v545[v644] = v543;
      int * v547 = v483->cache_vals;
      int v647 = (((4 + ((((int)((unsigned int)((int)((unsigned int)v487 >> 2)) >> 1)) & 3) * 2)) + ((((v523 + ((~(((v525 ^ -1) | (-(v525 ^ -1))) >> 31)) & 2)) - (v526 + ((~(((v527 ^ -1) | (-(v527 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
      v547[v647] = v544;
      int * v549 = v483->cache_tags;
      int v650 = (int)((unsigned int)((int)((unsigned int)v487 >> 2)) >> 1);
      v549[v626] = v650;
      int * v551 = v483->cache_dirty;
      v551[v626] = 0;
      int * v553 = v483->cache_age;
      v553[v626] = 1;
      int * v555 = v483->cache_age;
      int v556 = v555[v626];
      int v557 = v555[v600];
      int v656 = v557 + ((int)((unsigned int)(v557 - v556) >> 31));
      v555[v600] = v656;
      int * v559 = v483->cache_age;
      int v560 = v559[v601];
      int v658 = v560 + ((int)((unsigned int)(v560 - v556) >> 31));
      v559[v601] = v658;
      int * v562 = v483->cache_age;
      v562[v626] = 0;
      v565 = v626;
    }
    int * v566 = v483->cache_vals;
    int v661 = v565 * 2;
    int v567 = v566[v661];
    int v662 = (v565 * 2) + 1;
    int v568 = v566[v662];
    int v663 = (((((int)((unsigned int)((int)((unsigned int)v487 >> 2)) >> 1)) & 1) * 2) + ((((v507 + ((~(((v509 ^ -1) | (-(v509 ^ -1))) >> 31)) & 2)) - (v510 + ((~(((v511 ^ -1) | (-(v511 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
    v566[v663] = v567;
    int * v570 = v483->cache_vals;
    int v666 = ((((((int)((unsigned int)((int)((unsigned int)v487 >> 2)) >> 1)) & 1) * 2) + ((((v507 + ((~(((v509 ^ -1) | (-(v509 ^ -1))) >> 31)) & 2)) - (v510 + ((~(((v511 ^ -1) | (-(v511 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
    v570[v666] = v568;
    int * v572 = v483->cache_tags;
    int v669 = ((((int)((unsigned int)((int)((unsigned int)v487 >> 2)) >> 1)) & 1) * 2) + ((((v507 + ((~(((v509 ^ -1) | (-(v509 ^ -1))) >> 31)) & 2)) - (v510 + ((~(((v511 ^ -1) | (-(v511 ^ -1))) >> 31)) & 2))) >> 31) & 1);
    int v670 = (int)((unsigned int)((int)((unsigned int)v487 >> 2)) >> 1);
    v572[v669] = v670;
    int * v574 = v483->cache_dirty;
    v574[v669] = 0;
    int * v576 = v483->cache_age;
    v576[v669] = 1;
    int * v578 = v483->cache_age;
    int v579 = v578[v669];
    int v580 = v578[v598];
    int v676 = v580 + ((int)((unsigned int)(v580 - v579) >> 31));
    v578[v598] = v676;
    int * v582 = v483->cache_age;
    int v583 = v582[v599];
    int v678 = v583 + ((int)((unsigned int)(v583 - v579) >> 31));
    v582[v599] = v678;
    int * v585 = v483->cache_age;
    v585[v669] = 0;
    v588 = v669;
  }
  int v681 = (v588 * 2) + (((int)((unsigned int)v487 >> 2)) & 1);
  int v589 = v495[v681];
  int * v590 = v483->regs;
  v590[14] = v589;
  struct StateT * v592 = slot_8(v483);
  return v592;
}

struct StateT * slot_21(struct StateT * v1417) {
  int v1418 = v1417->timer;
  int v1426 = v1418 + 1;
  v1417->timer = v1426;
  int * v1420 = v1417->regs;
  int v1421 = v1420[13];
  int v1422 = v1420[10];
  int v1430 = v1421 + v1422;
  v1420[10] = v1430;
  struct StateT * v1424 = slot_18(v1417);
  return v1424;
}

struct StateT * slot_3(struct StateT * v421) {
  int v422 = v421->timer;
  int v430 = v422 + 1;
  v421->timer = v430;
  int * v424 = v421->regs;
  int v425 = v424[12];
  int v426 = v424[14];
  int v434 = v425 ^ v426;
  v424[12] = v434;
  struct StateT * v428 = slot_4(v421);
  return v428;
}

struct StateT * slot_10(struct StateT * v714) {
  int * v715 = v714->saved_regs;
  int * v716 = v714->regs;
  int v717 = v716[11];
  v715[11] = v717;
  int v719 = v714->timer;
  int v731 = v719 + 1;
  v714->timer = v731;
  int * v721 = v714->regs;
  int v722 = v721[11];
  int v723 = v721[14];
  int v734 = v722 + v723;
  v721[11] = v734;
  struct StateT * v725 = slot_11(v714);
  return v725;
}

struct StateT * slot_1(struct StateT * v205) {
  int v206 = v205->timer;
  int v316 = v206 + 1;
  v205->timer = v316;
  int * v208 = v205->regs;
  int v209 = v208[11];
  int * v210 = v205->cache_tags;
  int v320 = (((int)((unsigned int)((int)((unsigned int)(v209 + 12) >> 2)) >> 1)) & 1) * 2;
  int v211 = v210[v320];
  int v321 = ((((int)((unsigned int)((int)((unsigned int)(v209 + 12) >> 2)) >> 1)) & 1) * 2) + 1;
  int v212 = v210[v321];
  int v322 = 4 + ((((int)((unsigned int)((int)((unsigned int)(v209 + 12) >> 2)) >> 1)) & 3) * 2);
  int v213 = v210[v322];
  int v323 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v209 + 12) >> 2)) >> 1)) & 3) * 2)) + 1;
  int v214 = v210[v323];
  int v215 = v205->timer;
  int v324 = v215 + ((100 ^ (((~(((v213 ^ ((int)((unsigned int)((int)((unsigned int)(v209 + 12) >> 2)) >> 1))) | (-(v213 ^ ((int)((unsigned int)((int)((unsigned int)(v209 + 12) >> 2)) >> 1))))) >> 31)) | (~(((v214 ^ ((int)((unsigned int)((int)((unsigned int)(v209 + 12) >> 2)) >> 1))) | (-(v214 ^ ((int)((unsigned int)((int)((unsigned int)(v209 + 12) >> 2)) >> 1))))) >> 31))) & 104)) ^ (((~(((v211 ^ ((int)((unsigned int)((int)((unsigned int)(v209 + 12) >> 2)) >> 1))) | (-(v211 ^ ((int)((unsigned int)((int)((unsigned int)(v209 + 12) >> 2)) >> 1))))) >> 31)) | (~(((v212 ^ ((int)((unsigned int)((int)((unsigned int)(v209 + 12) >> 2)) >> 1))) | (-(v212 ^ ((int)((unsigned int)((int)((unsigned int)(v209 + 12) >> 2)) >> 1))))) >> 31))) & (1 ^ (100 ^ (((~(((v213 ^ ((int)((unsigned int)((int)((unsigned int)(v209 + 12) >> 2)) >> 1))) | (-(v213 ^ ((int)((unsigned int)((int)((unsigned int)(v209 + 12) >> 2)) >> 1))))) >> 31)) | (~(((v214 ^ ((int)((unsigned int)((int)((unsigned int)(v209 + 12) >> 2)) >> 1))) | (-(v214 ^ ((int)((unsigned int)((int)((unsigned int)(v209 + 12) >> 2)) >> 1))))) >> 31))) & 104)))));
  v205->timer = v324;
  int * v217 = v205->cache_vals;
  bool v325 = !(((~(((v211 ^ ((int)((unsigned int)((int)((unsigned int)(v209 + 12) >> 2)) >> 1))) | (-(v211 ^ ((int)((unsigned int)((int)((unsigned int)(v209 + 12) >> 2)) >> 1))))) >> 31)) | (~(((v212 ^ ((int)((unsigned int)((int)((unsigned int)(v209 + 12) >> 2)) >> 1))) | (-(v212 ^ ((int)((unsigned int)((int)((unsigned int)(v209 + 12) >> 2)) >> 1))))) >> 31))) == 0);
  int v310;
  if (v325) {
    int * v218 = v205->cache_age;
    int v327 = ((((int)((unsigned int)((int)((unsigned int)(v209 + 12) >> 2)) >> 1)) & 1) * 2) + ((~(((v212 ^ ((int)((unsigned int)((int)((unsigned int)(v209 + 12) >> 2)) >> 1))) | (-(v212 ^ ((int)((unsigned int)((int)((unsigned int)(v209 + 12) >> 2)) >> 1))))) >> 31)) & 1);
    int v219 = v218[v327];
    int v220 = v218[v320];
    int v328 = v220 + ((int)((unsigned int)(v220 - v219) >> 31));
    v218[v320] = v328;
    int * v222 = v205->cache_age;
    int v223 = v222[v321];
    int v330 = v223 + ((int)((unsigned int)(v223 - v219) >> 31));
    v222[v321] = v330;
    int * v225 = v205->cache_age;
    v225[v327] = 0;
    v310 = v327;
  } else {
    int * v228 = v205->cache_age;
    int v334 = (((int)((unsigned int)((int)((unsigned int)(v209 + 12) >> 2)) >> 1)) & 1) * 2;
    int v229 = v228[v334];
    int * v230 = v205->cache_tags;
    int v231 = v230[v334];
    int v232 = v228[v321];
    int v233 = v230[v321];
    bool v336 = !(((~(((v213 ^ ((int)((unsigned int)((int)((unsigned int)(v209 + 12) >> 2)) >> 1))) | (-(v213 ^ ((int)((unsigned int)((int)((unsigned int)(v209 + 12) >> 2)) >> 1))))) >> 31)) | (~(((v214 ^ ((int)((unsigned int)((int)((unsigned int)(v209 + 12) >> 2)) >> 1))) | (-(v214 ^ ((int)((unsigned int)((int)((unsigned int)(v209 + 12) >> 2)) >> 1))))) >> 31))) == 0);
    int v287;
    if (v336) {
      int * v234 = v205->cache_age;
      int v338 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v209 + 12) >> 2)) >> 1)) & 3) * 2)) + ((~(((v214 ^ ((int)((unsigned int)((int)((unsigned int)(v209 + 12) >> 2)) >> 1))) | (-(v214 ^ ((int)((unsigned int)((int)((unsigned int)(v209 + 12) >> 2)) >> 1))))) >> 31)) & 1);
      int v235 = v234[v338];
      int v236 = v234[v322];
      int v339 = v236 + ((int)((unsigned int)(v236 - v235) >> 31));
      v234[v322] = v339;
      int * v238 = v205->cache_age;
      int v239 = v238[v323];
      int v341 = v239 + ((int)((unsigned int)(v239 - v235) >> 31));
      v238[v323] = v341;
      int * v241 = v205->cache_age;
      v241[v338] = 0;
      v287 = v338;
    } else {
      int * v244 = v205->cache_age;
      int v345 = 4 + ((((int)((unsigned int)((int)((unsigned int)(v209 + 12) >> 2)) >> 1)) & 3) * 2);
      int v245 = v244[v345];
      int * v246 = v205->cache_tags;
      int v247 = v246[v345];
      int v248 = v244[v323];
      int v249 = v246[v323];
      int * v250 = v205->cache_dirty;
      int v348 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v209 + 12) >> 2)) >> 1)) & 3) * 2)) + ((((v245 + ((~(((v247 ^ -1) | (-(v247 ^ -1))) >> 31)) & 2)) - (v248 + ((~(((v249 ^ -1) | (-(v249 ^ -1))) >> 31)) & 2))) >> 31) & 1);
      int v251 = v250[v348];
      bool v349 = !(v251 == 0);
      if (v349) {
        int * v252 = v205->cache_tags;
        int v253 = v252[v348];
        int * v254 = v205->cache_vals;
        int v352 = ((4 + ((((int)((unsigned int)((int)((unsigned int)(v209 + 12) >> 2)) >> 1)) & 3) * 2)) + ((((v245 + ((~(((v247 ^ -1) | (-(v247 ^ -1))) >> 31)) & 2)) - (v248 + ((~(((v249 ^ -1) | (-(v249 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
        int v255 = v254[v352];
        int v353 = (((4 + ((((int)((unsigned int)((int)((unsigned int)(v209 + 12) >> 2)) >> 1)) & 3) * 2)) + ((((v245 + ((~(((v247 ^ -1) | (-(v247 ^ -1))) >> 31)) & 2)) - (v248 + ((~(((v249 ^ -1) | (-(v249 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
        int v256 = v254[v353];
        int * v257 = v205->mem;
        int v355 = v253 * 2;
        v257[v355] = v255;
        int * v259 = v205->mem;
        int v358 = (v253 * 2) + 1;
        v259[v358] = v256;
        ;
      } else {
        ;
      }
      int * v264 = v205->mem;
      int v363 = ((int)((unsigned int)((int)((unsigned int)(v209 + 12) >> 2)) >> 1)) * 2;
      int v265 = v264[v363];
      int v364 = (((int)((unsigned int)((int)((unsigned int)(v209 + 12) >> 2)) >> 1)) * 2) + 1;
      int v266 = v264[v364];
      int * v267 = v205->cache_vals;
      int v366 = ((4 + ((((int)((unsigned int)((int)((unsigned int)(v209 + 12) >> 2)) >> 1)) & 3) * 2)) + ((((v245 + ((~(((v247 ^ -1) | (-(v247 ^ -1))) >> 31)) & 2)) - (v248 + ((~(((v249 ^ -1) | (-(v249 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
      v267[v366] = v265;
      int * v269 = v205->cache_vals;
      int v369 = (((4 + ((((int)((unsigned int)((int)((unsigned int)(v209 + 12) >> 2)) >> 1)) & 3) * 2)) + ((((v245 + ((~(((v247 ^ -1) | (-(v247 ^ -1))) >> 31)) & 2)) - (v248 + ((~(((v249 ^ -1) | (-(v249 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
      v269[v369] = v266;
      int * v271 = v205->cache_tags;
      int v372 = (int)((unsigned int)((int)((unsigned int)(v209 + 12) >> 2)) >> 1);
      v271[v348] = v372;
      int * v273 = v205->cache_dirty;
      v273[v348] = 0;
      int * v275 = v205->cache_age;
      v275[v348] = 1;
      int * v277 = v205->cache_age;
      int v278 = v277[v348];
      int v279 = v277[v322];
      int v378 = v279 + ((int)((unsigned int)(v279 - v278) >> 31));
      v277[v322] = v378;
      int * v281 = v205->cache_age;
      int v282 = v281[v323];
      int v380 = v282 + ((int)((unsigned int)(v282 - v278) >> 31));
      v281[v323] = v380;
      int * v284 = v205->cache_age;
      v284[v348] = 0;
      v287 = v348;
    }
    int * v288 = v205->cache_vals;
    int v383 = v287 * 2;
    int v289 = v288[v383];
    int v384 = (v287 * 2) + 1;
    int v290 = v288[v384];
    int v385 = (((((int)((unsigned int)((int)((unsigned int)(v209 + 12) >> 2)) >> 1)) & 1) * 2) + ((((v229 + ((~(((v231 ^ -1) | (-(v231 ^ -1))) >> 31)) & 2)) - (v232 + ((~(((v233 ^ -1) | (-(v233 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
    v288[v385] = v289;
    int * v292 = v205->cache_vals;
    int v388 = ((((((int)((unsigned int)((int)((unsigned int)(v209 + 12) >> 2)) >> 1)) & 1) * 2) + ((((v229 + ((~(((v231 ^ -1) | (-(v231 ^ -1))) >> 31)) & 2)) - (v232 + ((~(((v233 ^ -1) | (-(v233 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
    v292[v388] = v290;
    int * v294 = v205->cache_tags;
    int v391 = ((((int)((unsigned int)((int)((unsigned int)(v209 + 12) >> 2)) >> 1)) & 1) * 2) + ((((v229 + ((~(((v231 ^ -1) | (-(v231 ^ -1))) >> 31)) & 2)) - (v232 + ((~(((v233 ^ -1) | (-(v233 ^ -1))) >> 31)) & 2))) >> 31) & 1);
    int v392 = (int)((unsigned int)((int)((unsigned int)(v209 + 12) >> 2)) >> 1);
    v294[v391] = v392;
    int * v296 = v205->cache_dirty;
    v296[v391] = 0;
    int * v298 = v205->cache_age;
    v298[v391] = 1;
    int * v300 = v205->cache_age;
    int v301 = v300[v391];
    int v302 = v300[v320];
    int v398 = v302 + ((int)((unsigned int)(v302 - v301) >> 31));
    v300[v320] = v398;
    int * v304 = v205->cache_age;
    int v305 = v304[v321];
    int v400 = v305 + ((int)((unsigned int)(v305 - v301) >> 31));
    v304[v321] = v400;
    int * v307 = v205->cache_age;
    v307[v391] = 0;
    v310 = v391;
  }
  int v403 = (v310 * 2) + (((int)((unsigned int)(v209 + 12) >> 2)) & 1);
  int v311 = v217[v403];
  int * v312 = v205->regs;
  v312[14] = v311;
  struct StateT * v314 = slot_2(v205);
  return v314;
}

struct StateT * slot_19(struct StateT * v1398) {
  int v1399 = v1398->timer;
  int v1406 = v1399 + 1;
  v1398->timer = v1406;
  int * v1401 = v1398->regs;
  int v1402 = v1401[10];
  int v1409 = v1402 << 2;
  v1401[10] = v1409;
  struct StateT * v1404 = slot_21(v1398);
  return v1404;
}

struct StateT * slot_13(struct StateT * v963) {
  int * v964 = v963->saved_regs;
  int * v965 = v963->regs;
  int v966 = v965[10];
  v964[10] = v966;
  int v968 = v963->timer;
  int v979 = v968 + 1;
  v963->timer = v979;
  int * v970 = v963->regs;
  int v971 = v970[10];
  int v981 = v971 & 7;
  v970[10] = v981;
  struct StateT * v973 = slot_14(v963);
  return v973;
}

struct StateT * slot_0(struct StateT * v2) {
  int v3 = v2->timer;
  int v113 = v3 + 1;
  v2->timer = v113;
  int * v5 = v2->regs;
  int v6 = v5[12];
  int * v7 = v2->cache_tags;
  int v117 = (((int)((unsigned int)((int)((unsigned int)v6 >> 2)) >> 1)) & 1) * 2;
  int v8 = v7[v117];
  int v118 = ((((int)((unsigned int)((int)((unsigned int)v6 >> 2)) >> 1)) & 1) * 2) + 1;
  int v9 = v7[v118];
  int v119 = 4 + ((((int)((unsigned int)((int)((unsigned int)v6 >> 2)) >> 1)) & 3) * 2);
  int v10 = v7[v119];
  int v120 = (4 + ((((int)((unsigned int)((int)((unsigned int)v6 >> 2)) >> 1)) & 3) * 2)) + 1;
  int v11 = v7[v120];
  int v12 = v2->timer;
  int v121 = v12 + ((100 ^ (((~(((v10 ^ ((int)((unsigned int)((int)((unsigned int)v6 >> 2)) >> 1))) | (-(v10 ^ ((int)((unsigned int)((int)((unsigned int)v6 >> 2)) >> 1))))) >> 31)) | (~(((v11 ^ ((int)((unsigned int)((int)((unsigned int)v6 >> 2)) >> 1))) | (-(v11 ^ ((int)((unsigned int)((int)((unsigned int)v6 >> 2)) >> 1))))) >> 31))) & 104)) ^ (((~(((v8 ^ ((int)((unsigned int)((int)((unsigned int)v6 >> 2)) >> 1))) | (-(v8 ^ ((int)((unsigned int)((int)((unsigned int)v6 >> 2)) >> 1))))) >> 31)) | (~(((v9 ^ ((int)((unsigned int)((int)((unsigned int)v6 >> 2)) >> 1))) | (-(v9 ^ ((int)((unsigned int)((int)((unsigned int)v6 >> 2)) >> 1))))) >> 31))) & (1 ^ (100 ^ (((~(((v10 ^ ((int)((unsigned int)((int)((unsigned int)v6 >> 2)) >> 1))) | (-(v10 ^ ((int)((unsigned int)((int)((unsigned int)v6 >> 2)) >> 1))))) >> 31)) | (~(((v11 ^ ((int)((unsigned int)((int)((unsigned int)v6 >> 2)) >> 1))) | (-(v11 ^ ((int)((unsigned int)((int)((unsigned int)v6 >> 2)) >> 1))))) >> 31))) & 104)))));
  v2->timer = v121;
  int * v14 = v2->cache_vals;
  bool v122 = !(((~(((v8 ^ ((int)((unsigned int)((int)((unsigned int)v6 >> 2)) >> 1))) | (-(v8 ^ ((int)((unsigned int)((int)((unsigned int)v6 >> 2)) >> 1))))) >> 31)) | (~(((v9 ^ ((int)((unsigned int)((int)((unsigned int)v6 >> 2)) >> 1))) | (-(v9 ^ ((int)((unsigned int)((int)((unsigned int)v6 >> 2)) >> 1))))) >> 31))) == 0);
  int v107;
  if (v122) {
    int * v15 = v2->cache_age;
    int v124 = ((((int)((unsigned int)((int)((unsigned int)v6 >> 2)) >> 1)) & 1) * 2) + ((~(((v9 ^ ((int)((unsigned int)((int)((unsigned int)v6 >> 2)) >> 1))) | (-(v9 ^ ((int)((unsigned int)((int)((unsigned int)v6 >> 2)) >> 1))))) >> 31)) & 1);
    int v16 = v15[v124];
    int v17 = v15[v117];
    int v125 = v17 + ((int)((unsigned int)(v17 - v16) >> 31));
    v15[v117] = v125;
    int * v19 = v2->cache_age;
    int v20 = v19[v118];
    int v127 = v20 + ((int)((unsigned int)(v20 - v16) >> 31));
    v19[v118] = v127;
    int * v22 = v2->cache_age;
    v22[v124] = 0;
    v107 = v124;
  } else {
    int * v25 = v2->cache_age;
    int v131 = (((int)((unsigned int)((int)((unsigned int)v6 >> 2)) >> 1)) & 1) * 2;
    int v26 = v25[v131];
    int * v27 = v2->cache_tags;
    int v28 = v27[v131];
    int v29 = v25[v118];
    int v30 = v27[v118];
    bool v133 = !(((~(((v10 ^ ((int)((unsigned int)((int)((unsigned int)v6 >> 2)) >> 1))) | (-(v10 ^ ((int)((unsigned int)((int)((unsigned int)v6 >> 2)) >> 1))))) >> 31)) | (~(((v11 ^ ((int)((unsigned int)((int)((unsigned int)v6 >> 2)) >> 1))) | (-(v11 ^ ((int)((unsigned int)((int)((unsigned int)v6 >> 2)) >> 1))))) >> 31))) == 0);
    int v84;
    if (v133) {
      int * v31 = v2->cache_age;
      int v135 = (4 + ((((int)((unsigned int)((int)((unsigned int)v6 >> 2)) >> 1)) & 3) * 2)) + ((~(((v11 ^ ((int)((unsigned int)((int)((unsigned int)v6 >> 2)) >> 1))) | (-(v11 ^ ((int)((unsigned int)((int)((unsigned int)v6 >> 2)) >> 1))))) >> 31)) & 1);
      int v32 = v31[v135];
      int v33 = v31[v119];
      int v136 = v33 + ((int)((unsigned int)(v33 - v32) >> 31));
      v31[v119] = v136;
      int * v35 = v2->cache_age;
      int v36 = v35[v120];
      int v138 = v36 + ((int)((unsigned int)(v36 - v32) >> 31));
      v35[v120] = v138;
      int * v38 = v2->cache_age;
      v38[v135] = 0;
      v84 = v135;
    } else {
      int * v41 = v2->cache_age;
      int v142 = 4 + ((((int)((unsigned int)((int)((unsigned int)v6 >> 2)) >> 1)) & 3) * 2);
      int v42 = v41[v142];
      int * v43 = v2->cache_tags;
      int v44 = v43[v142];
      int v45 = v41[v120];
      int v46 = v43[v120];
      int * v47 = v2->cache_dirty;
      int v145 = (4 + ((((int)((unsigned int)((int)((unsigned int)v6 >> 2)) >> 1)) & 3) * 2)) + ((((v42 + ((~(((v44 ^ -1) | (-(v44 ^ -1))) >> 31)) & 2)) - (v45 + ((~(((v46 ^ -1) | (-(v46 ^ -1))) >> 31)) & 2))) >> 31) & 1);
      int v48 = v47[v145];
      bool v146 = !(v48 == 0);
      if (v146) {
        int * v49 = v2->cache_tags;
        int v50 = v49[v145];
        int * v51 = v2->cache_vals;
        int v149 = ((4 + ((((int)((unsigned int)((int)((unsigned int)v6 >> 2)) >> 1)) & 3) * 2)) + ((((v42 + ((~(((v44 ^ -1) | (-(v44 ^ -1))) >> 31)) & 2)) - (v45 + ((~(((v46 ^ -1) | (-(v46 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
        int v52 = v51[v149];
        int v150 = (((4 + ((((int)((unsigned int)((int)((unsigned int)v6 >> 2)) >> 1)) & 3) * 2)) + ((((v42 + ((~(((v44 ^ -1) | (-(v44 ^ -1))) >> 31)) & 2)) - (v45 + ((~(((v46 ^ -1) | (-(v46 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
        int v53 = v51[v150];
        int * v54 = v2->mem;
        int v152 = v50 * 2;
        v54[v152] = v52;
        int * v56 = v2->mem;
        int v155 = (v50 * 2) + 1;
        v56[v155] = v53;
        ;
      } else {
        ;
      }
      int * v61 = v2->mem;
      int v160 = ((int)((unsigned int)((int)((unsigned int)v6 >> 2)) >> 1)) * 2;
      int v62 = v61[v160];
      int v161 = (((int)((unsigned int)((int)((unsigned int)v6 >> 2)) >> 1)) * 2) + 1;
      int v63 = v61[v161];
      int * v64 = v2->cache_vals;
      int v163 = ((4 + ((((int)((unsigned int)((int)((unsigned int)v6 >> 2)) >> 1)) & 3) * 2)) + ((((v42 + ((~(((v44 ^ -1) | (-(v44 ^ -1))) >> 31)) & 2)) - (v45 + ((~(((v46 ^ -1) | (-(v46 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
      v64[v163] = v62;
      int * v66 = v2->cache_vals;
      int v166 = (((4 + ((((int)((unsigned int)((int)((unsigned int)v6 >> 2)) >> 1)) & 3) * 2)) + ((((v42 + ((~(((v44 ^ -1) | (-(v44 ^ -1))) >> 31)) & 2)) - (v45 + ((~(((v46 ^ -1) | (-(v46 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
      v66[v166] = v63;
      int * v68 = v2->cache_tags;
      int v169 = (int)((unsigned int)((int)((unsigned int)v6 >> 2)) >> 1);
      v68[v145] = v169;
      int * v70 = v2->cache_dirty;
      v70[v145] = 0;
      int * v72 = v2->cache_age;
      v72[v145] = 1;
      int * v74 = v2->cache_age;
      int v75 = v74[v145];
      int v76 = v74[v119];
      int v175 = v76 + ((int)((unsigned int)(v76 - v75) >> 31));
      v74[v119] = v175;
      int * v78 = v2->cache_age;
      int v79 = v78[v120];
      int v177 = v79 + ((int)((unsigned int)(v79 - v75) >> 31));
      v78[v120] = v177;
      int * v81 = v2->cache_age;
      v81[v145] = 0;
      v84 = v145;
    }
    int * v85 = v2->cache_vals;
    int v180 = v84 * 2;
    int v86 = v85[v180];
    int v181 = (v84 * 2) + 1;
    int v87 = v85[v181];
    int v182 = (((((int)((unsigned int)((int)((unsigned int)v6 >> 2)) >> 1)) & 1) * 2) + ((((v26 + ((~(((v28 ^ -1) | (-(v28 ^ -1))) >> 31)) & 2)) - (v29 + ((~(((v30 ^ -1) | (-(v30 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
    v85[v182] = v86;
    int * v89 = v2->cache_vals;
    int v185 = ((((((int)((unsigned int)((int)((unsigned int)v6 >> 2)) >> 1)) & 1) * 2) + ((((v26 + ((~(((v28 ^ -1) | (-(v28 ^ -1))) >> 31)) & 2)) - (v29 + ((~(((v30 ^ -1) | (-(v30 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
    v89[v185] = v87;
    int * v91 = v2->cache_tags;
    int v188 = ((((int)((unsigned int)((int)((unsigned int)v6 >> 2)) >> 1)) & 1) * 2) + ((((v26 + ((~(((v28 ^ -1) | (-(v28 ^ -1))) >> 31)) & 2)) - (v29 + ((~(((v30 ^ -1) | (-(v30 ^ -1))) >> 31)) & 2))) >> 31) & 1);
    int v189 = (int)((unsigned int)((int)((unsigned int)v6 >> 2)) >> 1);
    v91[v188] = v189;
    int * v93 = v2->cache_dirty;
    v93[v188] = 0;
    int * v95 = v2->cache_age;
    v95[v188] = 1;
    int * v97 = v2->cache_age;
    int v98 = v97[v188];
    int v99 = v97[v117];
    int v195 = v99 + ((int)((unsigned int)(v99 - v98) >> 31));
    v97[v117] = v195;
    int * v101 = v2->cache_age;
    int v102 = v101[v118];
    int v197 = v102 + ((int)((unsigned int)(v102 - v98) >> 31));
    v101[v118] = v197;
    int * v104 = v2->cache_age;
    v104[v188] = 0;
    v107 = v188;
  }
  int v200 = (v107 * 2) + (((int)((unsigned int)v6 >> 2)) & 1);
  int v108 = v14[v200];
  int * v109 = v2->regs;
  v109[12] = v108;
  struct StateT * v111 = slot_1(v2);
  return v111;
}

struct StateT * slot_14(struct StateT * v984) {
  int v985 = v984->timer;
  int v992 = v985 + 1;
  v984->timer = v992;
  int * v987 = v984->regs;
  int v988 = v987[10];
  int v995 = v988 << 2;
  v987[10] = v995;
  struct StateT * v990 = slot_15(v984);
  return v990;
}

struct StateT * slot_17(struct StateT * v1069) {
  int v1070 = v1069->timer;
  int v1077 = v1070 + 1;
  v1069->timer = v1077;
  int * v1072 = v1069->regs;
  int v1073 = v1072[10];
  int v1080 = v1073 & 7;
  v1072[10] = v1080;
  struct StateT * v1075 = slot_19(v1069);
  return v1075;
}

struct StateT * slot_20(struct StateT * v1412) {
  int v1413 = v1412->timer;
  int v1416 = v1413 + 1;
  v1412->timer = v1416;
  return v1412;
}

struct StateT * snippet(struct StateT * v0) {
  struct StateT * v1 = slot_0(v0);
  return v1;
}

struct StateT * slot_8(struct StateT * v686) {
  int v687 = v686->timer;
  int v694 = v687 + 1;
  v686->timer = v694;
  int * v689 = v686->regs;
  int v690 = v689[14];
  int v697 = v690 & 15;
  v689[14] = v697;
  struct StateT * v692 = slot_9(v686);
  return v692;
}

struct StateT * slot_4(struct StateT * v437) {
  int v438 = v437->timer;
  int v442 = v438 + 1;
  v437->timer = v442;
  struct StateT * v440 = slot_5(v437);
  return v440;
}

struct StateT * slot_15(struct StateT * v998) {
  int v999 = v998->timer;
  int v1007 = v999 + 1;
  v998->timer = v1007;
  int * v1001 = v998->regs;
  int v1002 = v1001[13];
  int v1003 = v1001[10];
  int v1011 = v1002 + v1003;
  v1001[10] = v1011;
  struct StateT * v1005 = slot_16(v998);
  return v1005;
}

struct StateT * slot_18(struct StateT * v1083) {
  int v1084 = v1083->timer;
  int v1254 = v1084 + 1;
  v1083->timer = v1254;
  int * v1086 = v1083->regs;
  int v1087 = v1086[10];
  int v1088 = v1086[12];
  int * v1089 = v1083->cache_tags;
  int v1259 = (((int)((unsigned int)((int)((unsigned int)v1087 >> 2)) >> 1)) & 1) * 2;
  int v1090 = v1089[v1259];
  int v1260 = ((((int)((unsigned int)((int)((unsigned int)v1087 >> 2)) >> 1)) & 1) * 2) + 1;
  int v1091 = v1089[v1260];
  int v1261 = 4 + ((((int)((unsigned int)((int)((unsigned int)v1087 >> 2)) >> 1)) & 3) * 2);
  int v1092 = v1089[v1261];
  int v1262 = (4 + ((((int)((unsigned int)((int)((unsigned int)v1087 >> 2)) >> 1)) & 3) * 2)) + 1;
  int v1093 = v1089[v1262];
  int v1094 = v1083->timer;
  int v1263 = v1094 + ((100 ^ (((~(((v1092 ^ ((int)((unsigned int)((int)((unsigned int)v1087 >> 2)) >> 1))) | (-(v1092 ^ ((int)((unsigned int)((int)((unsigned int)v1087 >> 2)) >> 1))))) >> 31)) | (~(((v1093 ^ ((int)((unsigned int)((int)((unsigned int)v1087 >> 2)) >> 1))) | (-(v1093 ^ ((int)((unsigned int)((int)((unsigned int)v1087 >> 2)) >> 1))))) >> 31))) & 104)) ^ (((~(((v1090 ^ ((int)((unsigned int)((int)((unsigned int)v1087 >> 2)) >> 1))) | (-(v1090 ^ ((int)((unsigned int)((int)((unsigned int)v1087 >> 2)) >> 1))))) >> 31)) | (~(((v1091 ^ ((int)((unsigned int)((int)((unsigned int)v1087 >> 2)) >> 1))) | (-(v1091 ^ ((int)((unsigned int)((int)((unsigned int)v1087 >> 2)) >> 1))))) >> 31))) & (1 ^ (100 ^ (((~(((v1092 ^ ((int)((unsigned int)((int)((unsigned int)v1087 >> 2)) >> 1))) | (-(v1092 ^ ((int)((unsigned int)((int)((unsigned int)v1087 >> 2)) >> 1))))) >> 31)) | (~(((v1093 ^ ((int)((unsigned int)((int)((unsigned int)v1087 >> 2)) >> 1))) | (-(v1093 ^ ((int)((unsigned int)((int)((unsigned int)v1087 >> 2)) >> 1))))) >> 31))) & 104)))));
  v1083->timer = v1263;
  bool v1264 = !(((~(((v1090 ^ ((int)((unsigned int)((int)((unsigned int)v1087 >> 2)) >> 1))) | (-(v1090 ^ ((int)((unsigned int)((int)((unsigned int)v1087 >> 2)) >> 1))))) >> 31)) | (~(((v1091 ^ ((int)((unsigned int)((int)((unsigned int)v1087 >> 2)) >> 1))) | (-(v1091 ^ ((int)((unsigned int)((int)((unsigned int)v1087 >> 2)) >> 1))))) >> 31))) == 0);
  int v1188;
  if (v1264) {
    int * v1096 = v1083->cache_age;
    int v1266 = ((((int)((unsigned int)((int)((unsigned int)v1087 >> 2)) >> 1)) & 1) * 2) + ((~(((v1091 ^ ((int)((unsigned int)((int)((unsigned int)v1087 >> 2)) >> 1))) | (-(v1091 ^ ((int)((unsigned int)((int)((unsigned int)v1087 >> 2)) >> 1))))) >> 31)) & 1);
    int v1097 = v1096[v1266];
    int v1098 = v1096[v1259];
    int v1267 = v1098 + ((int)((unsigned int)(v1098 - v1097) >> 31));
    v1096[v1259] = v1267;
    int * v1100 = v1083->cache_age;
    int v1101 = v1100[v1260];
    int v1269 = v1101 + ((int)((unsigned int)(v1101 - v1097) >> 31));
    v1100[v1260] = v1269;
    int * v1103 = v1083->cache_age;
    v1103[v1266] = 0;
    v1188 = v1266;
  } else {
    int * v1106 = v1083->cache_age;
    int v1273 = (((int)((unsigned int)((int)((unsigned int)v1087 >> 2)) >> 1)) & 1) * 2;
    int v1107 = v1106[v1273];
    int * v1108 = v1083->cache_tags;
    int v1109 = v1108[v1273];
    int v1110 = v1106[v1260];
    int v1111 = v1108[v1260];
    bool v1275 = !(((~(((v1092 ^ ((int)((unsigned int)((int)((unsigned int)v1087 >> 2)) >> 1))) | (-(v1092 ^ ((int)((unsigned int)((int)((unsigned int)v1087 >> 2)) >> 1))))) >> 31)) | (~(((v1093 ^ ((int)((unsigned int)((int)((unsigned int)v1087 >> 2)) >> 1))) | (-(v1093 ^ ((int)((unsigned int)((int)((unsigned int)v1087 >> 2)) >> 1))))) >> 31))) == 0);
    int v1165;
    if (v1275) {
      int * v1112 = v1083->cache_age;
      int v1277 = (4 + ((((int)((unsigned int)((int)((unsigned int)v1087 >> 2)) >> 1)) & 3) * 2)) + ((~(((v1093 ^ ((int)((unsigned int)((int)((unsigned int)v1087 >> 2)) >> 1))) | (-(v1093 ^ ((int)((unsigned int)((int)((unsigned int)v1087 >> 2)) >> 1))))) >> 31)) & 1);
      int v1113 = v1112[v1277];
      int v1114 = v1112[v1261];
      int v1278 = v1114 + ((int)((unsigned int)(v1114 - v1113) >> 31));
      v1112[v1261] = v1278;
      int * v1116 = v1083->cache_age;
      int v1117 = v1116[v1262];
      int v1280 = v1117 + ((int)((unsigned int)(v1117 - v1113) >> 31));
      v1116[v1262] = v1280;
      int * v1119 = v1083->cache_age;
      v1119[v1277] = 0;
      v1165 = v1277;
    } else {
      int * v1122 = v1083->cache_age;
      int v1284 = 4 + ((((int)((unsigned int)((int)((unsigned int)v1087 >> 2)) >> 1)) & 3) * 2);
      int v1123 = v1122[v1284];
      int * v1124 = v1083->cache_tags;
      int v1125 = v1124[v1284];
      int v1126 = v1122[v1262];
      int v1127 = v1124[v1262];
      int * v1128 = v1083->cache_dirty;
      int v1287 = (4 + ((((int)((unsigned int)((int)((unsigned int)v1087 >> 2)) >> 1)) & 3) * 2)) + ((((v1123 + ((~(((v1125 ^ -1) | (-(v1125 ^ -1))) >> 31)) & 2)) - (v1126 + ((~(((v1127 ^ -1) | (-(v1127 ^ -1))) >> 31)) & 2))) >> 31) & 1);
      int v1129 = v1128[v1287];
      bool v1288 = !(v1129 == 0);
      if (v1288) {
        int * v1130 = v1083->cache_tags;
        int v1131 = v1130[v1287];
        int * v1132 = v1083->cache_vals;
        int v1291 = ((4 + ((((int)((unsigned int)((int)((unsigned int)v1087 >> 2)) >> 1)) & 3) * 2)) + ((((v1123 + ((~(((v1125 ^ -1) | (-(v1125 ^ -1))) >> 31)) & 2)) - (v1126 + ((~(((v1127 ^ -1) | (-(v1127 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
        int v1133 = v1132[v1291];
        int v1292 = (((4 + ((((int)((unsigned int)((int)((unsigned int)v1087 >> 2)) >> 1)) & 3) * 2)) + ((((v1123 + ((~(((v1125 ^ -1) | (-(v1125 ^ -1))) >> 31)) & 2)) - (v1126 + ((~(((v1127 ^ -1) | (-(v1127 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
        int v1134 = v1132[v1292];
        int * v1135 = v1083->mem;
        int v1294 = v1131 * 2;
        v1135[v1294] = v1133;
        int * v1137 = v1083->mem;
        int v1297 = (v1131 * 2) + 1;
        v1137[v1297] = v1134;
        ;
      } else {
        ;
      }
      int * v1142 = v1083->mem;
      int v1302 = ((int)((unsigned int)((int)((unsigned int)v1087 >> 2)) >> 1)) * 2;
      int v1143 = v1142[v1302];
      int v1303 = (((int)((unsigned int)((int)((unsigned int)v1087 >> 2)) >> 1)) * 2) + 1;
      int v1144 = v1142[v1303];
      int * v1145 = v1083->cache_vals;
      int v1305 = ((4 + ((((int)((unsigned int)((int)((unsigned int)v1087 >> 2)) >> 1)) & 3) * 2)) + ((((v1123 + ((~(((v1125 ^ -1) | (-(v1125 ^ -1))) >> 31)) & 2)) - (v1126 + ((~(((v1127 ^ -1) | (-(v1127 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
      v1145[v1305] = v1143;
      int * v1147 = v1083->cache_vals;
      int v1308 = (((4 + ((((int)((unsigned int)((int)((unsigned int)v1087 >> 2)) >> 1)) & 3) * 2)) + ((((v1123 + ((~(((v1125 ^ -1) | (-(v1125 ^ -1))) >> 31)) & 2)) - (v1126 + ((~(((v1127 ^ -1) | (-(v1127 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
      v1147[v1308] = v1144;
      int * v1149 = v1083->cache_tags;
      int v1311 = (int)((unsigned int)((int)((unsigned int)v1087 >> 2)) >> 1);
      v1149[v1287] = v1311;
      int * v1151 = v1083->cache_dirty;
      v1151[v1287] = 0;
      int * v1153 = v1083->cache_age;
      v1153[v1287] = 1;
      int * v1155 = v1083->cache_age;
      int v1156 = v1155[v1287];
      int v1157 = v1155[v1261];
      int v1317 = v1157 + ((int)((unsigned int)(v1157 - v1156) >> 31));
      v1155[v1261] = v1317;
      int * v1159 = v1083->cache_age;
      int v1160 = v1159[v1262];
      int v1319 = v1160 + ((int)((unsigned int)(v1160 - v1156) >> 31));
      v1159[v1262] = v1319;
      int * v1162 = v1083->cache_age;
      v1162[v1287] = 0;
      v1165 = v1287;
    }
    int * v1166 = v1083->cache_vals;
    int v1322 = v1165 * 2;
    int v1167 = v1166[v1322];
    int v1323 = (v1165 * 2) + 1;
    int v1168 = v1166[v1323];
    int v1324 = (((((int)((unsigned int)((int)((unsigned int)v1087 >> 2)) >> 1)) & 1) * 2) + ((((v1107 + ((~(((v1109 ^ -1) | (-(v1109 ^ -1))) >> 31)) & 2)) - (v1110 + ((~(((v1111 ^ -1) | (-(v1111 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
    v1166[v1324] = v1167;
    int * v1170 = v1083->cache_vals;
    int v1327 = ((((((int)((unsigned int)((int)((unsigned int)v1087 >> 2)) >> 1)) & 1) * 2) + ((((v1107 + ((~(((v1109 ^ -1) | (-(v1109 ^ -1))) >> 31)) & 2)) - (v1110 + ((~(((v1111 ^ -1) | (-(v1111 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
    v1170[v1327] = v1168;
    int * v1172 = v1083->cache_tags;
    int v1330 = ((((int)((unsigned int)((int)((unsigned int)v1087 >> 2)) >> 1)) & 1) * 2) + ((((v1107 + ((~(((v1109 ^ -1) | (-(v1109 ^ -1))) >> 31)) & 2)) - (v1110 + ((~(((v1111 ^ -1) | (-(v1111 ^ -1))) >> 31)) & 2))) >> 31) & 1);
    int v1331 = (int)((unsigned int)((int)((unsigned int)v1087 >> 2)) >> 1);
    v1172[v1330] = v1331;
    int * v1174 = v1083->cache_dirty;
    v1174[v1330] = 0;
    int * v1176 = v1083->cache_age;
    v1176[v1330] = 1;
    int * v1178 = v1083->cache_age;
    int v1179 = v1178[v1330];
    int v1180 = v1178[v1259];
    int v1337 = v1180 + ((int)((unsigned int)(v1180 - v1179) >> 31));
    v1178[v1259] = v1337;
    int * v1182 = v1083->cache_age;
    int v1183 = v1182[v1260];
    int v1339 = v1183 + ((int)((unsigned int)(v1183 - v1179) >> 31));
    v1182[v1260] = v1339;
    int * v1185 = v1083->cache_age;
    v1185[v1330] = 0;
    v1188 = v1330;
  }
  int * v1189 = v1083->cache_vals;
  int v1342 = (v1188 * 2) + (((int)((unsigned int)v1087 >> 2)) & 1);
  v1189[v1342] = v1088;
  int * v1191 = v1083->cache_tags;
  int v1192 = v1191[v1261];
  int v1193 = v1191[v1262];
  bool v1345 = !(((~(((v1192 ^ ((int)((unsigned int)((int)((unsigned int)v1087 >> 2)) >> 1))) | (-(v1192 ^ ((int)((unsigned int)((int)((unsigned int)v1087 >> 2)) >> 1))))) >> 31)) | (~(((v1193 ^ ((int)((unsigned int)((int)((unsigned int)v1087 >> 2)) >> 1))) | (-(v1193 ^ ((int)((unsigned int)((int)((unsigned int)v1087 >> 2)) >> 1))))) >> 31))) == 0);
  int v1247;
  if (v1345) {
    int * v1194 = v1083->cache_age;
    int v1347 = (4 + ((((int)((unsigned int)((int)((unsigned int)v1087 >> 2)) >> 1)) & 3) * 2)) + ((~(((v1193 ^ ((int)((unsigned int)((int)((unsigned int)v1087 >> 2)) >> 1))) | (-(v1193 ^ ((int)((unsigned int)((int)((unsigned int)v1087 >> 2)) >> 1))))) >> 31)) & 1);
    int v1195 = v1194[v1347];
    int v1196 = v1194[v1261];
    int v1348 = v1196 + ((int)((unsigned int)(v1196 - v1195) >> 31));
    v1194[v1261] = v1348;
    int * v1198 = v1083->cache_age;
    int v1199 = v1198[v1262];
    int v1350 = v1199 + ((int)((unsigned int)(v1199 - v1195) >> 31));
    v1198[v1262] = v1350;
    int * v1201 = v1083->cache_age;
    v1201[v1347] = 0;
    v1247 = v1347;
  } else {
    int * v1204 = v1083->cache_age;
    int v1354 = 4 + ((((int)((unsigned int)((int)((unsigned int)v1087 >> 2)) >> 1)) & 3) * 2);
    int v1205 = v1204[v1354];
    int * v1206 = v1083->cache_tags;
    int v1207 = v1206[v1354];
    int v1208 = v1204[v1262];
    int v1209 = v1206[v1262];
    int * v1210 = v1083->cache_dirty;
    int v1357 = (4 + ((((int)((unsigned int)((int)((unsigned int)v1087 >> 2)) >> 1)) & 3) * 2)) + ((((v1205 + ((~(((v1207 ^ -1) | (-(v1207 ^ -1))) >> 31)) & 2)) - (v1208 + ((~(((v1209 ^ -1) | (-(v1209 ^ -1))) >> 31)) & 2))) >> 31) & 1);
    int v1211 = v1210[v1357];
    bool v1358 = !(v1211 == 0);
    if (v1358) {
      int * v1212 = v1083->cache_tags;
      int v1213 = v1212[v1357];
      int * v1214 = v1083->cache_vals;
      int v1361 = ((4 + ((((int)((unsigned int)((int)((unsigned int)v1087 >> 2)) >> 1)) & 3) * 2)) + ((((v1205 + ((~(((v1207 ^ -1) | (-(v1207 ^ -1))) >> 31)) & 2)) - (v1208 + ((~(((v1209 ^ -1) | (-(v1209 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
      int v1215 = v1214[v1361];
      int v1362 = (((4 + ((((int)((unsigned int)((int)((unsigned int)v1087 >> 2)) >> 1)) & 3) * 2)) + ((((v1205 + ((~(((v1207 ^ -1) | (-(v1207 ^ -1))) >> 31)) & 2)) - (v1208 + ((~(((v1209 ^ -1) | (-(v1209 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
      int v1216 = v1214[v1362];
      int * v1217 = v1083->mem;
      int v1364 = v1213 * 2;
      v1217[v1364] = v1215;
      int * v1219 = v1083->mem;
      int v1367 = (v1213 * 2) + 1;
      v1219[v1367] = v1216;
      ;
    } else {
      ;
    }
    int * v1224 = v1083->mem;
    int v1372 = ((int)((unsigned int)((int)((unsigned int)v1087 >> 2)) >> 1)) * 2;
    int v1225 = v1224[v1372];
    int v1373 = (((int)((unsigned int)((int)((unsigned int)v1087 >> 2)) >> 1)) * 2) + 1;
    int v1226 = v1224[v1373];
    int * v1227 = v1083->cache_vals;
    int v1375 = ((4 + ((((int)((unsigned int)((int)((unsigned int)v1087 >> 2)) >> 1)) & 3) * 2)) + ((((v1205 + ((~(((v1207 ^ -1) | (-(v1207 ^ -1))) >> 31)) & 2)) - (v1208 + ((~(((v1209 ^ -1) | (-(v1209 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
    v1227[v1375] = v1225;
    int * v1229 = v1083->cache_vals;
    int v1378 = (((4 + ((((int)((unsigned int)((int)((unsigned int)v1087 >> 2)) >> 1)) & 3) * 2)) + ((((v1205 + ((~(((v1207 ^ -1) | (-(v1207 ^ -1))) >> 31)) & 2)) - (v1208 + ((~(((v1209 ^ -1) | (-(v1209 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
    v1229[v1378] = v1226;
    int * v1231 = v1083->cache_tags;
    int v1381 = (int)((unsigned int)((int)((unsigned int)v1087 >> 2)) >> 1);
    v1231[v1357] = v1381;
    int * v1233 = v1083->cache_dirty;
    v1233[v1357] = 0;
    int * v1235 = v1083->cache_age;
    v1235[v1357] = 1;
    int * v1237 = v1083->cache_age;
    int v1238 = v1237[v1357];
    int v1239 = v1237[v1261];
    int v1387 = v1239 + ((int)((unsigned int)(v1239 - v1238) >> 31));
    v1237[v1261] = v1387;
    int * v1241 = v1083->cache_age;
    int v1242 = v1241[v1262];
    int v1389 = v1242 + ((int)((unsigned int)(v1242 - v1238) >> 31));
    v1241[v1262] = v1389;
    int * v1244 = v1083->cache_age;
    v1244[v1357] = 0;
    v1247 = v1357;
  }
  int * v1248 = v1083->cache_vals;
  int v1392 = (v1247 * 2) + (((int)((unsigned int)v1087 >> 2)) & 1);
  v1248[v1392] = v1088;
  int * v1250 = v1083->cache_dirty;
  v1250[v1247] = 1;
  struct StateT * v1252 = slot_20(v1083);
  return v1252;
}

struct StateT * slot_9(struct StateT * v700) {
  int v701 = v700->timer;
  int v708 = v701 + 1;
  v700->timer = v708;
  int * v703 = v700->regs;
  int v704 = v703[14];
  int v711 = v704 << 2;
  v703[14] = v711;
  struct StateT * v706 = slot_10(v700);
  return v706;
}

struct StateT * slot_11(struct StateT * v737) {
  int v738 = v737->timer;
  int v848 = v738 + 1;
  v737->timer = v848;
  int * v740 = v737->regs;
  int v741 = v740[11];
  int * v742 = v737->cache_tags;
  int v852 = (((int)((unsigned int)((int)((unsigned int)v741 >> 2)) >> 1)) & 1) * 2;
  int v743 = v742[v852];
  int v853 = ((((int)((unsigned int)((int)((unsigned int)v741 >> 2)) >> 1)) & 1) * 2) + 1;
  int v744 = v742[v853];
  int v854 = 4 + ((((int)((unsigned int)((int)((unsigned int)v741 >> 2)) >> 1)) & 3) * 2);
  int v745 = v742[v854];
  int v855 = (4 + ((((int)((unsigned int)((int)((unsigned int)v741 >> 2)) >> 1)) & 3) * 2)) + 1;
  int v746 = v742[v855];
  int v747 = v737->timer;
  int v856 = v747 + ((100 ^ (((~(((v745 ^ ((int)((unsigned int)((int)((unsigned int)v741 >> 2)) >> 1))) | (-(v745 ^ ((int)((unsigned int)((int)((unsigned int)v741 >> 2)) >> 1))))) >> 31)) | (~(((v746 ^ ((int)((unsigned int)((int)((unsigned int)v741 >> 2)) >> 1))) | (-(v746 ^ ((int)((unsigned int)((int)((unsigned int)v741 >> 2)) >> 1))))) >> 31))) & 104)) ^ (((~(((v743 ^ ((int)((unsigned int)((int)((unsigned int)v741 >> 2)) >> 1))) | (-(v743 ^ ((int)((unsigned int)((int)((unsigned int)v741 >> 2)) >> 1))))) >> 31)) | (~(((v744 ^ ((int)((unsigned int)((int)((unsigned int)v741 >> 2)) >> 1))) | (-(v744 ^ ((int)((unsigned int)((int)((unsigned int)v741 >> 2)) >> 1))))) >> 31))) & (1 ^ (100 ^ (((~(((v745 ^ ((int)((unsigned int)((int)((unsigned int)v741 >> 2)) >> 1))) | (-(v745 ^ ((int)((unsigned int)((int)((unsigned int)v741 >> 2)) >> 1))))) >> 31)) | (~(((v746 ^ ((int)((unsigned int)((int)((unsigned int)v741 >> 2)) >> 1))) | (-(v746 ^ ((int)((unsigned int)((int)((unsigned int)v741 >> 2)) >> 1))))) >> 31))) & 104)))));
  v737->timer = v856;
  int * v749 = v737->cache_vals;
  bool v857 = !(((~(((v743 ^ ((int)((unsigned int)((int)((unsigned int)v741 >> 2)) >> 1))) | (-(v743 ^ ((int)((unsigned int)((int)((unsigned int)v741 >> 2)) >> 1))))) >> 31)) | (~(((v744 ^ ((int)((unsigned int)((int)((unsigned int)v741 >> 2)) >> 1))) | (-(v744 ^ ((int)((unsigned int)((int)((unsigned int)v741 >> 2)) >> 1))))) >> 31))) == 0);
  int v842;
  if (v857) {
    int * v750 = v737->cache_age;
    int v859 = ((((int)((unsigned int)((int)((unsigned int)v741 >> 2)) >> 1)) & 1) * 2) + ((~(((v744 ^ ((int)((unsigned int)((int)((unsigned int)v741 >> 2)) >> 1))) | (-(v744 ^ ((int)((unsigned int)((int)((unsigned int)v741 >> 2)) >> 1))))) >> 31)) & 1);
    int v751 = v750[v859];
    int v752 = v750[v852];
    int v860 = v752 + ((int)((unsigned int)(v752 - v751) >> 31));
    v750[v852] = v860;
    int * v754 = v737->cache_age;
    int v755 = v754[v853];
    int v862 = v755 + ((int)((unsigned int)(v755 - v751) >> 31));
    v754[v853] = v862;
    int * v757 = v737->cache_age;
    v757[v859] = 0;
    v842 = v859;
  } else {
    int * v760 = v737->cache_age;
    int v866 = (((int)((unsigned int)((int)((unsigned int)v741 >> 2)) >> 1)) & 1) * 2;
    int v761 = v760[v866];
    int * v762 = v737->cache_tags;
    int v763 = v762[v866];
    int v764 = v760[v853];
    int v765 = v762[v853];
    bool v868 = !(((~(((v745 ^ ((int)((unsigned int)((int)((unsigned int)v741 >> 2)) >> 1))) | (-(v745 ^ ((int)((unsigned int)((int)((unsigned int)v741 >> 2)) >> 1))))) >> 31)) | (~(((v746 ^ ((int)((unsigned int)((int)((unsigned int)v741 >> 2)) >> 1))) | (-(v746 ^ ((int)((unsigned int)((int)((unsigned int)v741 >> 2)) >> 1))))) >> 31))) == 0);
    int v819;
    if (v868) {
      int * v766 = v737->cache_age;
      int v870 = (4 + ((((int)((unsigned int)((int)((unsigned int)v741 >> 2)) >> 1)) & 3) * 2)) + ((~(((v746 ^ ((int)((unsigned int)((int)((unsigned int)v741 >> 2)) >> 1))) | (-(v746 ^ ((int)((unsigned int)((int)((unsigned int)v741 >> 2)) >> 1))))) >> 31)) & 1);
      int v767 = v766[v870];
      int v768 = v766[v854];
      int v871 = v768 + ((int)((unsigned int)(v768 - v767) >> 31));
      v766[v854] = v871;
      int * v770 = v737->cache_age;
      int v771 = v770[v855];
      int v873 = v771 + ((int)((unsigned int)(v771 - v767) >> 31));
      v770[v855] = v873;
      int * v773 = v737->cache_age;
      v773[v870] = 0;
      v819 = v870;
    } else {
      int * v776 = v737->cache_age;
      int v877 = 4 + ((((int)((unsigned int)((int)((unsigned int)v741 >> 2)) >> 1)) & 3) * 2);
      int v777 = v776[v877];
      int * v778 = v737->cache_tags;
      int v779 = v778[v877];
      int v780 = v776[v855];
      int v781 = v778[v855];
      int * v782 = v737->cache_dirty;
      int v880 = (4 + ((((int)((unsigned int)((int)((unsigned int)v741 >> 2)) >> 1)) & 3) * 2)) + ((((v777 + ((~(((v779 ^ -1) | (-(v779 ^ -1))) >> 31)) & 2)) - (v780 + ((~(((v781 ^ -1) | (-(v781 ^ -1))) >> 31)) & 2))) >> 31) & 1);
      int v783 = v782[v880];
      bool v881 = !(v783 == 0);
      if (v881) {
        int * v784 = v737->cache_tags;
        int v785 = v784[v880];
        int * v786 = v737->cache_vals;
        int v884 = ((4 + ((((int)((unsigned int)((int)((unsigned int)v741 >> 2)) >> 1)) & 3) * 2)) + ((((v777 + ((~(((v779 ^ -1) | (-(v779 ^ -1))) >> 31)) & 2)) - (v780 + ((~(((v781 ^ -1) | (-(v781 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
        int v787 = v786[v884];
        int v885 = (((4 + ((((int)((unsigned int)((int)((unsigned int)v741 >> 2)) >> 1)) & 3) * 2)) + ((((v777 + ((~(((v779 ^ -1) | (-(v779 ^ -1))) >> 31)) & 2)) - (v780 + ((~(((v781 ^ -1) | (-(v781 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
        int v788 = v786[v885];
        int * v789 = v737->mem;
        int v887 = v785 * 2;
        v789[v887] = v787;
        int * v791 = v737->mem;
        int v890 = (v785 * 2) + 1;
        v791[v890] = v788;
        ;
      } else {
        ;
      }
      int * v796 = v737->mem;
      int v895 = ((int)((unsigned int)((int)((unsigned int)v741 >> 2)) >> 1)) * 2;
      int v797 = v796[v895];
      int v896 = (((int)((unsigned int)((int)((unsigned int)v741 >> 2)) >> 1)) * 2) + 1;
      int v798 = v796[v896];
      int * v799 = v737->cache_vals;
      int v898 = ((4 + ((((int)((unsigned int)((int)((unsigned int)v741 >> 2)) >> 1)) & 3) * 2)) + ((((v777 + ((~(((v779 ^ -1) | (-(v779 ^ -1))) >> 31)) & 2)) - (v780 + ((~(((v781 ^ -1) | (-(v781 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
      v799[v898] = v797;
      int * v801 = v737->cache_vals;
      int v901 = (((4 + ((((int)((unsigned int)((int)((unsigned int)v741 >> 2)) >> 1)) & 3) * 2)) + ((((v777 + ((~(((v779 ^ -1) | (-(v779 ^ -1))) >> 31)) & 2)) - (v780 + ((~(((v781 ^ -1) | (-(v781 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
      v801[v901] = v798;
      int * v803 = v737->cache_tags;
      int v904 = (int)((unsigned int)((int)((unsigned int)v741 >> 2)) >> 1);
      v803[v880] = v904;
      int * v805 = v737->cache_dirty;
      v805[v880] = 0;
      int * v807 = v737->cache_age;
      v807[v880] = 1;
      int * v809 = v737->cache_age;
      int v810 = v809[v880];
      int v811 = v809[v854];
      int v910 = v811 + ((int)((unsigned int)(v811 - v810) >> 31));
      v809[v854] = v910;
      int * v813 = v737->cache_age;
      int v814 = v813[v855];
      int v912 = v814 + ((int)((unsigned int)(v814 - v810) >> 31));
      v813[v855] = v912;
      int * v816 = v737->cache_age;
      v816[v880] = 0;
      v819 = v880;
    }
    int * v820 = v737->cache_vals;
    int v915 = v819 * 2;
    int v821 = v820[v915];
    int v916 = (v819 * 2) + 1;
    int v822 = v820[v916];
    int v917 = (((((int)((unsigned int)((int)((unsigned int)v741 >> 2)) >> 1)) & 1) * 2) + ((((v761 + ((~(((v763 ^ -1) | (-(v763 ^ -1))) >> 31)) & 2)) - (v764 + ((~(((v765 ^ -1) | (-(v765 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
    v820[v917] = v821;
    int * v824 = v737->cache_vals;
    int v920 = ((((((int)((unsigned int)((int)((unsigned int)v741 >> 2)) >> 1)) & 1) * 2) + ((((v761 + ((~(((v763 ^ -1) | (-(v763 ^ -1))) >> 31)) & 2)) - (v764 + ((~(((v765 ^ -1) | (-(v765 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
    v824[v920] = v822;
    int * v826 = v737->cache_tags;
    int v923 = ((((int)((unsigned int)((int)((unsigned int)v741 >> 2)) >> 1)) & 1) * 2) + ((((v761 + ((~(((v763 ^ -1) | (-(v763 ^ -1))) >> 31)) & 2)) - (v764 + ((~(((v765 ^ -1) | (-(v765 ^ -1))) >> 31)) & 2))) >> 31) & 1);
    int v924 = (int)((unsigned int)((int)((unsigned int)v741 >> 2)) >> 1);
    v826[v923] = v924;
    int * v828 = v737->cache_dirty;
    v828[v923] = 0;
    int * v830 = v737->cache_age;
    v830[v923] = 1;
    int * v832 = v737->cache_age;
    int v833 = v832[v923];
    int v834 = v832[v852];
    int v930 = v834 + ((int)((unsigned int)(v834 - v833) >> 31));
    v832[v852] = v930;
    int * v836 = v737->cache_age;
    int v837 = v836[v853];
    int v932 = v837 + ((int)((unsigned int)(v837 - v833) >> 31));
    v836[v853] = v932;
    int * v839 = v737->cache_age;
    v839[v923] = 0;
    v842 = v923;
  }
  int v935 = (v842 * 2) + (((int)((unsigned int)v741 >> 2)) & 1);
  int v843 = v749[v935];
  int * v844 = v737->regs;
  v844[11] = v843;
  struct StateT * v846 = slot_12(v737);
  return v846;
}



/*****************************************
End of C Generated Code
*******************************************/

void init(struct StateT *s) {
  for (int i=0; i<NUM_REGS; i++) {
    s->regs[i] = 0;
    s->saved_regs[i] = 0;
  }
  s->regs[2] = 4 * MEM_SIZE;
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
  
  // a10, public: one draw, written into both states
  int a10 = bounded(0, 23);
  s1.regs[10] = a10;
  s2.regs[10] = a10;
  // a11, 16 words read by the callee: the address is public
  s1.regs[11] = 0;
  s2.regs[11] = 0;
  // its contents, public: the same draw in both states
  for (int i=0; i<16; i++) {
    int v = bounded(0, 20);
    s1.mem[0 + i] = v;
    s2.mem[0 + i] = v;
  }
  // a12, 8 words read by the callee: the address is public
  s1.regs[12] = 64;
  s2.regs[12] = 64;
  // a13, 8 words written by the callee: the address is public
  s1.regs[13] = 96;
  s2.regs[13] = 96;
  
  // a12's contents, secret: a different draw in each state
  for (int i=0; i<8; i++) {
    s1.mem[16 + i] = secret(0, 20);
    s2.mem[16 + i] = secret(0, 20);
  }
  struct StateT *s1_ = snippet(&s1);
  struct StateT *s2_ = snippet(&s2);
  //@ assert untainted_timer: !\tainted(s1_->timer==s2_->timer);
  koika_assert(s1_->timer==s2_->timer, "timing leak");
  return 0;
}