// verify: clean (CBMC should report VERIFICATION SUCCESSFUL) [unwind 129]
#define NUM_REGS 32
#define MEM_SIZE 64
#define SECRET_SIZE 10
#define SECRET_OFFSET 20
#define CACHE_ENTRIES 12
#define CACHE_WORDS 24
#define PHT_ENTRIES 128
#define HISTORY_BITS 4

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

struct StateG {
  int regs[32];
  int mem[64];
  int saved_regs[32];
  int reg_ready[32];
  int cache_tags[12];
  int cache_dirty[12];
  int cache_age[12];
  int cache_vals[24];
  int pht[128];
  int timer;
};

struct StateG * slot_12(struct StateG * v405);
struct StateG * slot_6(struct StateG * v87);
struct StateG * slot_25(struct StateG * v1288);
struct StateG * slot_16(struct StateG * v861);
struct StateG * slot_23(struct StateG * v1254);
struct StateG * slot_5(struct StateG * v67);
struct StateG * slot_2(struct StateG * v28);
struct StateG * slot_7(struct StateG * v117);
struct StateG * slot_21(struct StateG * v1150);
struct StateG * slot_3(struct StateG * v41);
struct StateG * slot_1(struct StateG * v15);
struct StateG * slot_19(struct StateG * v1112);
struct StateG * slot_13(struct StateG * v429);
struct StateG * slot_24(struct StateG * v1268);
struct StateG * slot_0(struct StateG * v2);
struct StateG * slot_14(struct StateG * v633);
struct StateG * slot_17(struct StateG * v885);
struct StateG * slot_20(struct StateG * v1129);
struct StateG * snippet(struct StateG * v0);
struct StateG * slot_8(struct StateG * v141);
struct StateG * slot_4(struct StateG * v54);
struct StateG * slot_15(struct StateG * v844);
struct StateG * slot_18(struct StateG * v1089);
struct StateG * slot_9(struct StateG * v177);
struct StateG * slot_22(struct StateG * v1166);
struct StateG * slot_11(struct StateG * v388);
struct StateG * slot_12(struct StateG * v405) {
  int * v406 = v405->saved_regs;
  int * v407 = v405->regs;
  int v408 = v407[8];
  v406[8] = v408;
  int v410 = v405->timer;
  int v422 = v410 + 1;
  v405->timer = v422;
  int * v412 = v405->regs;
  int v413 = v412[13];
  int v414 = v412[14];
  int v426 = v413 + v414;
  v412[8] = v426;
  struct StateG * v416 = slot_14(v405);
  return v416;
}

struct StateG * slot_6(struct StateG * v87) {
  int * v88 = v87->saved_regs;
  int * v89 = v87->regs;
  int v90 = v89[11];
  v88[11] = v90;
  int v92 = v87->timer;
  int v107 = v92 + 1;
  v87->timer = v107;
  int * v94 = v87->regs;
  int v95 = v94[5];
  bool v110 = (v95 ^ -2147483648) < -2147483647;
  int v98;
  if (v110) {
    v98 = 1;
  } else {
    v98 = 0;
  }
  int * v99 = v87->regs;
  v99[11] = v98;
  struct StateG * v101 = slot_8(v87);
  return v101;
}

struct StateG * slot_25(struct StateG * v1288) {
  int v1289 = v1288->timer;
  int v1293 = v1289 + 1;
  v1288->timer = v1293;
  struct StateG * v1291 = slot_5(v1288);
  return v1291;
}

struct StateG * slot_16(struct StateG * v861) {
  int * v862 = v861->saved_regs;
  int * v863 = v861->regs;
  int v864 = v863[16];
  v862[16] = v864;
  int v866 = v861->timer;
  int v878 = v866 + 1;
  v861->timer = v878;
  int * v868 = v861->regs;
  int v869 = v868[7];
  int v870 = v868[9];
  int v882 = v869 ^ v870;
  v868[16] = v882;
  struct StateG * v872 = slot_18(v861);
  return v872;
}

struct StateG * slot_23(struct StateG * v1254) {
  int v1255 = v1254->timer;
  int v1262 = v1255 + 1;
  v1254->timer = v1262;
  int * v1257 = v1254->regs;
  int v1258 = v1257[14];
  int v1265 = v1258 + 4;
  v1257[14] = v1265;
  struct StateG * v1260 = slot_25(v1254);
  return v1260;
}

struct StateG * slot_5(struct StateG * v67) {
  int v68 = v67->timer;
  int v78 = v68 + 1;
  v67->timer = v78;
  int * v70 = v67->pht;
  int v71 = v70[0];
  bool v81 = !(v71 == 0);
  struct StateG * v76;
  if (v81) {
    struct StateG * v72 = slot_6(v67);
    v76 = v72;
  } else {
    struct StateG * v74 = slot_7(v67);
    v76 = v74;
  }
  return v76;
}

struct StateG * slot_2(struct StateG * v28) {
  int v29 = v28->timer;
  int v35 = v29 + 1;
  v28->timer = v35;
  int * v31 = v28->regs;
  v31[14] = 0;
  struct StateG * v33 = slot_3(v28);
  return v33;
}

struct StateG * slot_7(struct StateG * v117) {
  int * v118 = v117->saved_regs;
  int * v119 = v117->regs;
  int v120 = v119[6];
  v118[6] = v120;
  int v122 = v117->timer;
  int v134 = v122 + 1;
  v117->timer = v134;
  int * v124 = v117->regs;
  int v125 = v124[12];
  int v126 = v124[14];
  int v138 = v125 + v126;
  v124[6] = v138;
  struct StateG * v128 = slot_9(v117);
  return v128;
}

struct StateG * slot_21(struct StateG * v1150) {
  int v1151 = v1150->timer;
  int v1159 = v1151 + 1;
  v1150->timer = v1159;
  int * v1153 = v1150->regs;
  int v1154 = v1153[5];
  int v1155 = v1153[16];
  int v1163 = v1154 | v1155;
  v1153[5] = v1163;
  struct StateG * v1157 = slot_23(v1150);
  return v1157;
}

struct StateG * slot_3(struct StateG * v41) {
  int v42 = v41->timer;
  int v48 = v42 + 1;
  v41->timer = v48;
  int * v44 = v41->regs;
  v44[15] = 16;
  struct StateG * v46 = slot_4(v41);
  return v46;
}

struct StateG * slot_1(struct StateG * v15) {
  int v16 = v15->timer;
  int v22 = v16 + 1;
  v15->timer = v22;
  int * v18 = v15->regs;
  v18[13] = 80;
  struct StateG * v20 = slot_2(v15);
  return v20;
}

struct StateG * slot_19(struct StateG * v1112) {
  int v1113 = v1112->timer;
  int v1121 = v1113 + 1;
  v1112->timer = v1121;
  int * v1115 = v1112->regs;
  int v1116 = v1115[7];
  int v1117 = v1115[9];
  int v1126 = v1116 ^ v1117;
  v1115[16] = v1126;
  struct StateG * v1119 = slot_21(v1112);
  return v1119;
}

struct StateG * slot_13(struct StateG * v429) {
  int v430 = v429->timer;
  int v540 = v430 + 1;
  v429->timer = v540;
  int * v432 = v429->regs;
  int v433 = v432[6];
  int * v434 = v429->cache_tags;
  int v544 = (((int)((unsigned int)((int)((unsigned int)v433 >> 2)) >> 1)) & 1) * 2;
  int v435 = v434[v544];
  int v545 = ((((int)((unsigned int)((int)((unsigned int)v433 >> 2)) >> 1)) & 1) * 2) + 1;
  int v436 = v434[v545];
  int v546 = 4 + ((((int)((unsigned int)((int)((unsigned int)v433 >> 2)) >> 1)) & 3) * 2);
  int v437 = v434[v546];
  int v547 = (4 + ((((int)((unsigned int)((int)((unsigned int)v433 >> 2)) >> 1)) & 3) * 2)) + 1;
  int v438 = v434[v547];
  int v439 = v429->timer;
  int v548 = v439 + ((100 ^ (((~(((v437 ^ ((int)((unsigned int)((int)((unsigned int)v433 >> 2)) >> 1))) | (-(v437 ^ ((int)((unsigned int)((int)((unsigned int)v433 >> 2)) >> 1))))) >> 31)) | (~(((v438 ^ ((int)((unsigned int)((int)((unsigned int)v433 >> 2)) >> 1))) | (-(v438 ^ ((int)((unsigned int)((int)((unsigned int)v433 >> 2)) >> 1))))) >> 31))) & 104)) ^ (((~(((v435 ^ ((int)((unsigned int)((int)((unsigned int)v433 >> 2)) >> 1))) | (-(v435 ^ ((int)((unsigned int)((int)((unsigned int)v433 >> 2)) >> 1))))) >> 31)) | (~(((v436 ^ ((int)((unsigned int)((int)((unsigned int)v433 >> 2)) >> 1))) | (-(v436 ^ ((int)((unsigned int)((int)((unsigned int)v433 >> 2)) >> 1))))) >> 31))) & (1 ^ (100 ^ (((~(((v437 ^ ((int)((unsigned int)((int)((unsigned int)v433 >> 2)) >> 1))) | (-(v437 ^ ((int)((unsigned int)((int)((unsigned int)v433 >> 2)) >> 1))))) >> 31)) | (~(((v438 ^ ((int)((unsigned int)((int)((unsigned int)v433 >> 2)) >> 1))) | (-(v438 ^ ((int)((unsigned int)((int)((unsigned int)v433 >> 2)) >> 1))))) >> 31))) & 104)))));
  v429->timer = v548;
  int * v441 = v429->cache_vals;
  bool v549 = !(((~(((v435 ^ ((int)((unsigned int)((int)((unsigned int)v433 >> 2)) >> 1))) | (-(v435 ^ ((int)((unsigned int)((int)((unsigned int)v433 >> 2)) >> 1))))) >> 31)) | (~(((v436 ^ ((int)((unsigned int)((int)((unsigned int)v433 >> 2)) >> 1))) | (-(v436 ^ ((int)((unsigned int)((int)((unsigned int)v433 >> 2)) >> 1))))) >> 31))) == 0);
  int v534;
  if (v549) {
    int * v442 = v429->cache_age;
    int v551 = ((((int)((unsigned int)((int)((unsigned int)v433 >> 2)) >> 1)) & 1) * 2) + ((~(((v436 ^ ((int)((unsigned int)((int)((unsigned int)v433 >> 2)) >> 1))) | (-(v436 ^ ((int)((unsigned int)((int)((unsigned int)v433 >> 2)) >> 1))))) >> 31)) & 1);
    int v443 = v442[v551];
    int v444 = v442[v544];
    int v552 = v444 + ((int)((unsigned int)(v444 - v443) >> 31));
    v442[v544] = v552;
    int * v446 = v429->cache_age;
    int v447 = v446[v545];
    int v554 = v447 + ((int)((unsigned int)(v447 - v443) >> 31));
    v446[v545] = v554;
    int * v449 = v429->cache_age;
    v449[v551] = 0;
    v534 = v551;
  } else {
    int * v452 = v429->cache_age;
    int v558 = (((int)((unsigned int)((int)((unsigned int)v433 >> 2)) >> 1)) & 1) * 2;
    int v453 = v452[v558];
    int * v454 = v429->cache_tags;
    int v455 = v454[v558];
    int v456 = v452[v545];
    int v457 = v454[v545];
    bool v560 = !(((~(((v437 ^ ((int)((unsigned int)((int)((unsigned int)v433 >> 2)) >> 1))) | (-(v437 ^ ((int)((unsigned int)((int)((unsigned int)v433 >> 2)) >> 1))))) >> 31)) | (~(((v438 ^ ((int)((unsigned int)((int)((unsigned int)v433 >> 2)) >> 1))) | (-(v438 ^ ((int)((unsigned int)((int)((unsigned int)v433 >> 2)) >> 1))))) >> 31))) == 0);
    int v511;
    if (v560) {
      int * v458 = v429->cache_age;
      int v562 = (4 + ((((int)((unsigned int)((int)((unsigned int)v433 >> 2)) >> 1)) & 3) * 2)) + ((~(((v438 ^ ((int)((unsigned int)((int)((unsigned int)v433 >> 2)) >> 1))) | (-(v438 ^ ((int)((unsigned int)((int)((unsigned int)v433 >> 2)) >> 1))))) >> 31)) & 1);
      int v459 = v458[v562];
      int v460 = v458[v546];
      int v563 = v460 + ((int)((unsigned int)(v460 - v459) >> 31));
      v458[v546] = v563;
      int * v462 = v429->cache_age;
      int v463 = v462[v547];
      int v565 = v463 + ((int)((unsigned int)(v463 - v459) >> 31));
      v462[v547] = v565;
      int * v465 = v429->cache_age;
      v465[v562] = 0;
      v511 = v562;
    } else {
      int * v468 = v429->cache_age;
      int v569 = 4 + ((((int)((unsigned int)((int)((unsigned int)v433 >> 2)) >> 1)) & 3) * 2);
      int v469 = v468[v569];
      int * v470 = v429->cache_tags;
      int v471 = v470[v569];
      int v472 = v468[v547];
      int v473 = v470[v547];
      int * v474 = v429->cache_dirty;
      int v572 = (4 + ((((int)((unsigned int)((int)((unsigned int)v433 >> 2)) >> 1)) & 3) * 2)) + ((((v469 + ((~(((v471 ^ -1) | (-(v471 ^ -1))) >> 31)) & 2)) - (v472 + ((~(((v473 ^ -1) | (-(v473 ^ -1))) >> 31)) & 2))) >> 31) & 1);
      int v475 = v474[v572];
      bool v573 = !(v475 == 0);
      if (v573) {
        int * v476 = v429->cache_tags;
        int v477 = v476[v572];
        int * v478 = v429->cache_vals;
        int v576 = ((4 + ((((int)((unsigned int)((int)((unsigned int)v433 >> 2)) >> 1)) & 3) * 2)) + ((((v469 + ((~(((v471 ^ -1) | (-(v471 ^ -1))) >> 31)) & 2)) - (v472 + ((~(((v473 ^ -1) | (-(v473 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
        int v479 = v478[v576];
        int v577 = (((4 + ((((int)((unsigned int)((int)((unsigned int)v433 >> 2)) >> 1)) & 3) * 2)) + ((((v469 + ((~(((v471 ^ -1) | (-(v471 ^ -1))) >> 31)) & 2)) - (v472 + ((~(((v473 ^ -1) | (-(v473 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
        int v480 = v478[v577];
        int * v481 = v429->mem;
        int v579 = v477 * 2;
        v481[v579] = v479;
        int * v483 = v429->mem;
        int v582 = (v477 * 2) + 1;
        v483[v582] = v480;
        ;
      } else {
        ;
      }
      int * v488 = v429->mem;
      int v587 = ((int)((unsigned int)((int)((unsigned int)v433 >> 2)) >> 1)) * 2;
      int v489 = v488[v587];
      int v588 = (((int)((unsigned int)((int)((unsigned int)v433 >> 2)) >> 1)) * 2) + 1;
      int v490 = v488[v588];
      int * v491 = v429->cache_vals;
      int v590 = ((4 + ((((int)((unsigned int)((int)((unsigned int)v433 >> 2)) >> 1)) & 3) * 2)) + ((((v469 + ((~(((v471 ^ -1) | (-(v471 ^ -1))) >> 31)) & 2)) - (v472 + ((~(((v473 ^ -1) | (-(v473 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
      v491[v590] = v489;
      int * v493 = v429->cache_vals;
      int v593 = (((4 + ((((int)((unsigned int)((int)((unsigned int)v433 >> 2)) >> 1)) & 3) * 2)) + ((((v469 + ((~(((v471 ^ -1) | (-(v471 ^ -1))) >> 31)) & 2)) - (v472 + ((~(((v473 ^ -1) | (-(v473 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
      v493[v593] = v490;
      int * v495 = v429->cache_tags;
      int v596 = (int)((unsigned int)((int)((unsigned int)v433 >> 2)) >> 1);
      v495[v572] = v596;
      int * v497 = v429->cache_dirty;
      v497[v572] = 0;
      int * v499 = v429->cache_age;
      v499[v572] = 1;
      int * v501 = v429->cache_age;
      int v502 = v501[v572];
      int v503 = v501[v546];
      int v602 = v503 + ((int)((unsigned int)(v503 - v502) >> 31));
      v501[v546] = v602;
      int * v505 = v429->cache_age;
      int v506 = v505[v547];
      int v604 = v506 + ((int)((unsigned int)(v506 - v502) >> 31));
      v505[v547] = v604;
      int * v508 = v429->cache_age;
      v508[v572] = 0;
      v511 = v572;
    }
    int * v512 = v429->cache_vals;
    int v607 = v511 * 2;
    int v513 = v512[v607];
    int v608 = (v511 * 2) + 1;
    int v514 = v512[v608];
    int v609 = (((((int)((unsigned int)((int)((unsigned int)v433 >> 2)) >> 1)) & 1) * 2) + ((((v453 + ((~(((v455 ^ -1) | (-(v455 ^ -1))) >> 31)) & 2)) - (v456 + ((~(((v457 ^ -1) | (-(v457 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
    v512[v609] = v513;
    int * v516 = v429->cache_vals;
    int v612 = ((((((int)((unsigned int)((int)((unsigned int)v433 >> 2)) >> 1)) & 1) * 2) + ((((v453 + ((~(((v455 ^ -1) | (-(v455 ^ -1))) >> 31)) & 2)) - (v456 + ((~(((v457 ^ -1) | (-(v457 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
    v516[v612] = v514;
    int * v518 = v429->cache_tags;
    int v615 = ((((int)((unsigned int)((int)((unsigned int)v433 >> 2)) >> 1)) & 1) * 2) + ((((v453 + ((~(((v455 ^ -1) | (-(v455 ^ -1))) >> 31)) & 2)) - (v456 + ((~(((v457 ^ -1) | (-(v457 ^ -1))) >> 31)) & 2))) >> 31) & 1);
    int v616 = (int)((unsigned int)((int)((unsigned int)v433 >> 2)) >> 1);
    v518[v615] = v616;
    int * v520 = v429->cache_dirty;
    v520[v615] = 0;
    int * v522 = v429->cache_age;
    v522[v615] = 1;
    int * v524 = v429->cache_age;
    int v525 = v524[v615];
    int v526 = v524[v544];
    int v622 = v526 + ((int)((unsigned int)(v526 - v525) >> 31));
    v524[v544] = v622;
    int * v528 = v429->cache_age;
    int v529 = v528[v545];
    int v624 = v529 + ((int)((unsigned int)(v529 - v525) >> 31));
    v528[v545] = v624;
    int * v531 = v429->cache_age;
    v531[v615] = 0;
    v534 = v615;
  }
  int v627 = (v534 * 2) + (((int)((unsigned int)v433 >> 2)) & 1);
  int v535 = v441[v627];
  int * v536 = v429->regs;
  v536[7] = v535;
  struct StateG * v538 = slot_15(v429);
  return v538;
}

struct StateG * slot_24(struct StateG * v1268) {
  int v1269 = v1268->timer;
  int v1279 = v1269 + 1;
  v1268->timer = v1279;
  int * v1271 = v1268->regs;
  int v1272 = v1271[5];
  bool v1282 = (v1272 ^ -2147483648) < -2147483647;
  int v1275;
  if (v1282) {
    v1275 = 1;
  } else {
    v1275 = 0;
  }
  int * v1276 = v1268->regs;
  v1276[11] = v1275;
  return v1268;
}

struct StateG * slot_0(struct StateG * v2) {
  int v3 = v2->timer;
  int v9 = v3 + 1;
  v2->timer = v9;
  int * v5 = v2->regs;
  v5[12] = 0;
  struct StateG * v7 = slot_1(v2);
  return v7;
}

struct StateG * slot_14(struct StateG * v633) {
  int * v634 = v633->saved_regs;
  int * v635 = v633->regs;
  int v636 = v635[9];
  v634[9] = v636;
  int v638 = v633->timer;
  int v752 = v638 + 1;
  v633->timer = v752;
  int * v640 = v633->regs;
  int v641 = v640[8];
  int * v642 = v633->cache_tags;
  int v756 = (((int)((unsigned int)((int)((unsigned int)v641 >> 2)) >> 1)) & 1) * 2;
  int v643 = v642[v756];
  int v757 = ((((int)((unsigned int)((int)((unsigned int)v641 >> 2)) >> 1)) & 1) * 2) + 1;
  int v644 = v642[v757];
  int v758 = 4 + ((((int)((unsigned int)((int)((unsigned int)v641 >> 2)) >> 1)) & 3) * 2);
  int v645 = v642[v758];
  int v759 = (4 + ((((int)((unsigned int)((int)((unsigned int)v641 >> 2)) >> 1)) & 3) * 2)) + 1;
  int v646 = v642[v759];
  int v647 = v633->timer;
  int v760 = v647 + ((100 ^ (((~(((v645 ^ ((int)((unsigned int)((int)((unsigned int)v641 >> 2)) >> 1))) | (-(v645 ^ ((int)((unsigned int)((int)((unsigned int)v641 >> 2)) >> 1))))) >> 31)) | (~(((v646 ^ ((int)((unsigned int)((int)((unsigned int)v641 >> 2)) >> 1))) | (-(v646 ^ ((int)((unsigned int)((int)((unsigned int)v641 >> 2)) >> 1))))) >> 31))) & 104)) ^ (((~(((v643 ^ ((int)((unsigned int)((int)((unsigned int)v641 >> 2)) >> 1))) | (-(v643 ^ ((int)((unsigned int)((int)((unsigned int)v641 >> 2)) >> 1))))) >> 31)) | (~(((v644 ^ ((int)((unsigned int)((int)((unsigned int)v641 >> 2)) >> 1))) | (-(v644 ^ ((int)((unsigned int)((int)((unsigned int)v641 >> 2)) >> 1))))) >> 31))) & (1 ^ (100 ^ (((~(((v645 ^ ((int)((unsigned int)((int)((unsigned int)v641 >> 2)) >> 1))) | (-(v645 ^ ((int)((unsigned int)((int)((unsigned int)v641 >> 2)) >> 1))))) >> 31)) | (~(((v646 ^ ((int)((unsigned int)((int)((unsigned int)v641 >> 2)) >> 1))) | (-(v646 ^ ((int)((unsigned int)((int)((unsigned int)v641 >> 2)) >> 1))))) >> 31))) & 104)))));
  v633->timer = v760;
  int * v649 = v633->cache_vals;
  bool v761 = !(((~(((v643 ^ ((int)((unsigned int)((int)((unsigned int)v641 >> 2)) >> 1))) | (-(v643 ^ ((int)((unsigned int)((int)((unsigned int)v641 >> 2)) >> 1))))) >> 31)) | (~(((v644 ^ ((int)((unsigned int)((int)((unsigned int)v641 >> 2)) >> 1))) | (-(v644 ^ ((int)((unsigned int)((int)((unsigned int)v641 >> 2)) >> 1))))) >> 31))) == 0);
  int v742;
  if (v761) {
    int * v650 = v633->cache_age;
    int v763 = ((((int)((unsigned int)((int)((unsigned int)v641 >> 2)) >> 1)) & 1) * 2) + ((~(((v644 ^ ((int)((unsigned int)((int)((unsigned int)v641 >> 2)) >> 1))) | (-(v644 ^ ((int)((unsigned int)((int)((unsigned int)v641 >> 2)) >> 1))))) >> 31)) & 1);
    int v651 = v650[v763];
    int v652 = v650[v756];
    int v764 = v652 + ((int)((unsigned int)(v652 - v651) >> 31));
    v650[v756] = v764;
    int * v654 = v633->cache_age;
    int v655 = v654[v757];
    int v766 = v655 + ((int)((unsigned int)(v655 - v651) >> 31));
    v654[v757] = v766;
    int * v657 = v633->cache_age;
    v657[v763] = 0;
    v742 = v763;
  } else {
    int * v660 = v633->cache_age;
    int v770 = (((int)((unsigned int)((int)((unsigned int)v641 >> 2)) >> 1)) & 1) * 2;
    int v661 = v660[v770];
    int * v662 = v633->cache_tags;
    int v663 = v662[v770];
    int v664 = v660[v757];
    int v665 = v662[v757];
    bool v772 = !(((~(((v645 ^ ((int)((unsigned int)((int)((unsigned int)v641 >> 2)) >> 1))) | (-(v645 ^ ((int)((unsigned int)((int)((unsigned int)v641 >> 2)) >> 1))))) >> 31)) | (~(((v646 ^ ((int)((unsigned int)((int)((unsigned int)v641 >> 2)) >> 1))) | (-(v646 ^ ((int)((unsigned int)((int)((unsigned int)v641 >> 2)) >> 1))))) >> 31))) == 0);
    int v719;
    if (v772) {
      int * v666 = v633->cache_age;
      int v774 = (4 + ((((int)((unsigned int)((int)((unsigned int)v641 >> 2)) >> 1)) & 3) * 2)) + ((~(((v646 ^ ((int)((unsigned int)((int)((unsigned int)v641 >> 2)) >> 1))) | (-(v646 ^ ((int)((unsigned int)((int)((unsigned int)v641 >> 2)) >> 1))))) >> 31)) & 1);
      int v667 = v666[v774];
      int v668 = v666[v758];
      int v775 = v668 + ((int)((unsigned int)(v668 - v667) >> 31));
      v666[v758] = v775;
      int * v670 = v633->cache_age;
      int v671 = v670[v759];
      int v777 = v671 + ((int)((unsigned int)(v671 - v667) >> 31));
      v670[v759] = v777;
      int * v673 = v633->cache_age;
      v673[v774] = 0;
      v719 = v774;
    } else {
      int * v676 = v633->cache_age;
      int v781 = 4 + ((((int)((unsigned int)((int)((unsigned int)v641 >> 2)) >> 1)) & 3) * 2);
      int v677 = v676[v781];
      int * v678 = v633->cache_tags;
      int v679 = v678[v781];
      int v680 = v676[v759];
      int v681 = v678[v759];
      int * v682 = v633->cache_dirty;
      int v784 = (4 + ((((int)((unsigned int)((int)((unsigned int)v641 >> 2)) >> 1)) & 3) * 2)) + ((((v677 + ((~(((v679 ^ -1) | (-(v679 ^ -1))) >> 31)) & 2)) - (v680 + ((~(((v681 ^ -1) | (-(v681 ^ -1))) >> 31)) & 2))) >> 31) & 1);
      int v683 = v682[v784];
      bool v785 = !(v683 == 0);
      if (v785) {
        int * v684 = v633->cache_tags;
        int v685 = v684[v784];
        int * v686 = v633->cache_vals;
        int v788 = ((4 + ((((int)((unsigned int)((int)((unsigned int)v641 >> 2)) >> 1)) & 3) * 2)) + ((((v677 + ((~(((v679 ^ -1) | (-(v679 ^ -1))) >> 31)) & 2)) - (v680 + ((~(((v681 ^ -1) | (-(v681 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
        int v687 = v686[v788];
        int v789 = (((4 + ((((int)((unsigned int)((int)((unsigned int)v641 >> 2)) >> 1)) & 3) * 2)) + ((((v677 + ((~(((v679 ^ -1) | (-(v679 ^ -1))) >> 31)) & 2)) - (v680 + ((~(((v681 ^ -1) | (-(v681 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
        int v688 = v686[v789];
        int * v689 = v633->mem;
        int v791 = v685 * 2;
        v689[v791] = v687;
        int * v691 = v633->mem;
        int v794 = (v685 * 2) + 1;
        v691[v794] = v688;
        ;
      } else {
        ;
      }
      int * v696 = v633->mem;
      int v799 = ((int)((unsigned int)((int)((unsigned int)v641 >> 2)) >> 1)) * 2;
      int v697 = v696[v799];
      int v800 = (((int)((unsigned int)((int)((unsigned int)v641 >> 2)) >> 1)) * 2) + 1;
      int v698 = v696[v800];
      int * v699 = v633->cache_vals;
      int v802 = ((4 + ((((int)((unsigned int)((int)((unsigned int)v641 >> 2)) >> 1)) & 3) * 2)) + ((((v677 + ((~(((v679 ^ -1) | (-(v679 ^ -1))) >> 31)) & 2)) - (v680 + ((~(((v681 ^ -1) | (-(v681 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
      v699[v802] = v697;
      int * v701 = v633->cache_vals;
      int v805 = (((4 + ((((int)((unsigned int)((int)((unsigned int)v641 >> 2)) >> 1)) & 3) * 2)) + ((((v677 + ((~(((v679 ^ -1) | (-(v679 ^ -1))) >> 31)) & 2)) - (v680 + ((~(((v681 ^ -1) | (-(v681 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
      v701[v805] = v698;
      int * v703 = v633->cache_tags;
      int v808 = (int)((unsigned int)((int)((unsigned int)v641 >> 2)) >> 1);
      v703[v784] = v808;
      int * v705 = v633->cache_dirty;
      v705[v784] = 0;
      int * v707 = v633->cache_age;
      v707[v784] = 1;
      int * v709 = v633->cache_age;
      int v710 = v709[v784];
      int v711 = v709[v758];
      int v814 = v711 + ((int)((unsigned int)(v711 - v710) >> 31));
      v709[v758] = v814;
      int * v713 = v633->cache_age;
      int v714 = v713[v759];
      int v816 = v714 + ((int)((unsigned int)(v714 - v710) >> 31));
      v713[v759] = v816;
      int * v716 = v633->cache_age;
      v716[v784] = 0;
      v719 = v784;
    }
    int * v720 = v633->cache_vals;
    int v819 = v719 * 2;
    int v721 = v720[v819];
    int v820 = (v719 * 2) + 1;
    int v722 = v720[v820];
    int v821 = (((((int)((unsigned int)((int)((unsigned int)v641 >> 2)) >> 1)) & 1) * 2) + ((((v661 + ((~(((v663 ^ -1) | (-(v663 ^ -1))) >> 31)) & 2)) - (v664 + ((~(((v665 ^ -1) | (-(v665 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
    v720[v821] = v721;
    int * v724 = v633->cache_vals;
    int v824 = ((((((int)((unsigned int)((int)((unsigned int)v641 >> 2)) >> 1)) & 1) * 2) + ((((v661 + ((~(((v663 ^ -1) | (-(v663 ^ -1))) >> 31)) & 2)) - (v664 + ((~(((v665 ^ -1) | (-(v665 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
    v724[v824] = v722;
    int * v726 = v633->cache_tags;
    int v827 = ((((int)((unsigned int)((int)((unsigned int)v641 >> 2)) >> 1)) & 1) * 2) + ((((v661 + ((~(((v663 ^ -1) | (-(v663 ^ -1))) >> 31)) & 2)) - (v664 + ((~(((v665 ^ -1) | (-(v665 ^ -1))) >> 31)) & 2))) >> 31) & 1);
    int v828 = (int)((unsigned int)((int)((unsigned int)v641 >> 2)) >> 1);
    v726[v827] = v828;
    int * v728 = v633->cache_dirty;
    v728[v827] = 0;
    int * v730 = v633->cache_age;
    v730[v827] = 1;
    int * v732 = v633->cache_age;
    int v733 = v732[v827];
    int v734 = v732[v756];
    int v834 = v734 + ((int)((unsigned int)(v734 - v733) >> 31));
    v732[v756] = v834;
    int * v736 = v633->cache_age;
    int v737 = v736[v757];
    int v836 = v737 + ((int)((unsigned int)(v737 - v733) >> 31));
    v736[v757] = v836;
    int * v739 = v633->cache_age;
    v739[v827] = 0;
    v742 = v827;
  }
  int v839 = (v742 * 2) + (((int)((unsigned int)v641 >> 2)) & 1);
  int v743 = v649[v839];
  int * v744 = v633->regs;
  v744[9] = v743;
  struct StateG * v746 = slot_16(v633);
  return v746;
}

struct StateG * slot_17(struct StateG * v885) {
  int v886 = v885->timer;
  int v996 = v886 + 1;
  v885->timer = v996;
  int * v888 = v885->regs;
  int v889 = v888[8];
  int * v890 = v885->cache_tags;
  int v1000 = (((int)((unsigned int)((int)((unsigned int)v889 >> 2)) >> 1)) & 1) * 2;
  int v891 = v890[v1000];
  int v1001 = ((((int)((unsigned int)((int)((unsigned int)v889 >> 2)) >> 1)) & 1) * 2) + 1;
  int v892 = v890[v1001];
  int v1002 = 4 + ((((int)((unsigned int)((int)((unsigned int)v889 >> 2)) >> 1)) & 3) * 2);
  int v893 = v890[v1002];
  int v1003 = (4 + ((((int)((unsigned int)((int)((unsigned int)v889 >> 2)) >> 1)) & 3) * 2)) + 1;
  int v894 = v890[v1003];
  int v895 = v885->timer;
  int v1004 = v895 + ((100 ^ (((~(((v893 ^ ((int)((unsigned int)((int)((unsigned int)v889 >> 2)) >> 1))) | (-(v893 ^ ((int)((unsigned int)((int)((unsigned int)v889 >> 2)) >> 1))))) >> 31)) | (~(((v894 ^ ((int)((unsigned int)((int)((unsigned int)v889 >> 2)) >> 1))) | (-(v894 ^ ((int)((unsigned int)((int)((unsigned int)v889 >> 2)) >> 1))))) >> 31))) & 104)) ^ (((~(((v891 ^ ((int)((unsigned int)((int)((unsigned int)v889 >> 2)) >> 1))) | (-(v891 ^ ((int)((unsigned int)((int)((unsigned int)v889 >> 2)) >> 1))))) >> 31)) | (~(((v892 ^ ((int)((unsigned int)((int)((unsigned int)v889 >> 2)) >> 1))) | (-(v892 ^ ((int)((unsigned int)((int)((unsigned int)v889 >> 2)) >> 1))))) >> 31))) & (1 ^ (100 ^ (((~(((v893 ^ ((int)((unsigned int)((int)((unsigned int)v889 >> 2)) >> 1))) | (-(v893 ^ ((int)((unsigned int)((int)((unsigned int)v889 >> 2)) >> 1))))) >> 31)) | (~(((v894 ^ ((int)((unsigned int)((int)((unsigned int)v889 >> 2)) >> 1))) | (-(v894 ^ ((int)((unsigned int)((int)((unsigned int)v889 >> 2)) >> 1))))) >> 31))) & 104)))));
  v885->timer = v1004;
  int * v897 = v885->cache_vals;
  bool v1005 = !(((~(((v891 ^ ((int)((unsigned int)((int)((unsigned int)v889 >> 2)) >> 1))) | (-(v891 ^ ((int)((unsigned int)((int)((unsigned int)v889 >> 2)) >> 1))))) >> 31)) | (~(((v892 ^ ((int)((unsigned int)((int)((unsigned int)v889 >> 2)) >> 1))) | (-(v892 ^ ((int)((unsigned int)((int)((unsigned int)v889 >> 2)) >> 1))))) >> 31))) == 0);
  int v990;
  if (v1005) {
    int * v898 = v885->cache_age;
    int v1007 = ((((int)((unsigned int)((int)((unsigned int)v889 >> 2)) >> 1)) & 1) * 2) + ((~(((v892 ^ ((int)((unsigned int)((int)((unsigned int)v889 >> 2)) >> 1))) | (-(v892 ^ ((int)((unsigned int)((int)((unsigned int)v889 >> 2)) >> 1))))) >> 31)) & 1);
    int v899 = v898[v1007];
    int v900 = v898[v1000];
    int v1008 = v900 + ((int)((unsigned int)(v900 - v899) >> 31));
    v898[v1000] = v1008;
    int * v902 = v885->cache_age;
    int v903 = v902[v1001];
    int v1010 = v903 + ((int)((unsigned int)(v903 - v899) >> 31));
    v902[v1001] = v1010;
    int * v905 = v885->cache_age;
    v905[v1007] = 0;
    v990 = v1007;
  } else {
    int * v908 = v885->cache_age;
    int v1014 = (((int)((unsigned int)((int)((unsigned int)v889 >> 2)) >> 1)) & 1) * 2;
    int v909 = v908[v1014];
    int * v910 = v885->cache_tags;
    int v911 = v910[v1014];
    int v912 = v908[v1001];
    int v913 = v910[v1001];
    bool v1016 = !(((~(((v893 ^ ((int)((unsigned int)((int)((unsigned int)v889 >> 2)) >> 1))) | (-(v893 ^ ((int)((unsigned int)((int)((unsigned int)v889 >> 2)) >> 1))))) >> 31)) | (~(((v894 ^ ((int)((unsigned int)((int)((unsigned int)v889 >> 2)) >> 1))) | (-(v894 ^ ((int)((unsigned int)((int)((unsigned int)v889 >> 2)) >> 1))))) >> 31))) == 0);
    int v967;
    if (v1016) {
      int * v914 = v885->cache_age;
      int v1018 = (4 + ((((int)((unsigned int)((int)((unsigned int)v889 >> 2)) >> 1)) & 3) * 2)) + ((~(((v894 ^ ((int)((unsigned int)((int)((unsigned int)v889 >> 2)) >> 1))) | (-(v894 ^ ((int)((unsigned int)((int)((unsigned int)v889 >> 2)) >> 1))))) >> 31)) & 1);
      int v915 = v914[v1018];
      int v916 = v914[v1002];
      int v1019 = v916 + ((int)((unsigned int)(v916 - v915) >> 31));
      v914[v1002] = v1019;
      int * v918 = v885->cache_age;
      int v919 = v918[v1003];
      int v1021 = v919 + ((int)((unsigned int)(v919 - v915) >> 31));
      v918[v1003] = v1021;
      int * v921 = v885->cache_age;
      v921[v1018] = 0;
      v967 = v1018;
    } else {
      int * v924 = v885->cache_age;
      int v1025 = 4 + ((((int)((unsigned int)((int)((unsigned int)v889 >> 2)) >> 1)) & 3) * 2);
      int v925 = v924[v1025];
      int * v926 = v885->cache_tags;
      int v927 = v926[v1025];
      int v928 = v924[v1003];
      int v929 = v926[v1003];
      int * v930 = v885->cache_dirty;
      int v1028 = (4 + ((((int)((unsigned int)((int)((unsigned int)v889 >> 2)) >> 1)) & 3) * 2)) + ((((v925 + ((~(((v927 ^ -1) | (-(v927 ^ -1))) >> 31)) & 2)) - (v928 + ((~(((v929 ^ -1) | (-(v929 ^ -1))) >> 31)) & 2))) >> 31) & 1);
      int v931 = v930[v1028];
      bool v1029 = !(v931 == 0);
      if (v1029) {
        int * v932 = v885->cache_tags;
        int v933 = v932[v1028];
        int * v934 = v885->cache_vals;
        int v1032 = ((4 + ((((int)((unsigned int)((int)((unsigned int)v889 >> 2)) >> 1)) & 3) * 2)) + ((((v925 + ((~(((v927 ^ -1) | (-(v927 ^ -1))) >> 31)) & 2)) - (v928 + ((~(((v929 ^ -1) | (-(v929 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
        int v935 = v934[v1032];
        int v1033 = (((4 + ((((int)((unsigned int)((int)((unsigned int)v889 >> 2)) >> 1)) & 3) * 2)) + ((((v925 + ((~(((v927 ^ -1) | (-(v927 ^ -1))) >> 31)) & 2)) - (v928 + ((~(((v929 ^ -1) | (-(v929 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
        int v936 = v934[v1033];
        int * v937 = v885->mem;
        int v1035 = v933 * 2;
        v937[v1035] = v935;
        int * v939 = v885->mem;
        int v1038 = (v933 * 2) + 1;
        v939[v1038] = v936;
        ;
      } else {
        ;
      }
      int * v944 = v885->mem;
      int v1043 = ((int)((unsigned int)((int)((unsigned int)v889 >> 2)) >> 1)) * 2;
      int v945 = v944[v1043];
      int v1044 = (((int)((unsigned int)((int)((unsigned int)v889 >> 2)) >> 1)) * 2) + 1;
      int v946 = v944[v1044];
      int * v947 = v885->cache_vals;
      int v1046 = ((4 + ((((int)((unsigned int)((int)((unsigned int)v889 >> 2)) >> 1)) & 3) * 2)) + ((((v925 + ((~(((v927 ^ -1) | (-(v927 ^ -1))) >> 31)) & 2)) - (v928 + ((~(((v929 ^ -1) | (-(v929 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
      v947[v1046] = v945;
      int * v949 = v885->cache_vals;
      int v1049 = (((4 + ((((int)((unsigned int)((int)((unsigned int)v889 >> 2)) >> 1)) & 3) * 2)) + ((((v925 + ((~(((v927 ^ -1) | (-(v927 ^ -1))) >> 31)) & 2)) - (v928 + ((~(((v929 ^ -1) | (-(v929 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
      v949[v1049] = v946;
      int * v951 = v885->cache_tags;
      int v1052 = (int)((unsigned int)((int)((unsigned int)v889 >> 2)) >> 1);
      v951[v1028] = v1052;
      int * v953 = v885->cache_dirty;
      v953[v1028] = 0;
      int * v955 = v885->cache_age;
      v955[v1028] = 1;
      int * v957 = v885->cache_age;
      int v958 = v957[v1028];
      int v959 = v957[v1002];
      int v1058 = v959 + ((int)((unsigned int)(v959 - v958) >> 31));
      v957[v1002] = v1058;
      int * v961 = v885->cache_age;
      int v962 = v961[v1003];
      int v1060 = v962 + ((int)((unsigned int)(v962 - v958) >> 31));
      v961[v1003] = v1060;
      int * v964 = v885->cache_age;
      v964[v1028] = 0;
      v967 = v1028;
    }
    int * v968 = v885->cache_vals;
    int v1063 = v967 * 2;
    int v969 = v968[v1063];
    int v1064 = (v967 * 2) + 1;
    int v970 = v968[v1064];
    int v1065 = (((((int)((unsigned int)((int)((unsigned int)v889 >> 2)) >> 1)) & 1) * 2) + ((((v909 + ((~(((v911 ^ -1) | (-(v911 ^ -1))) >> 31)) & 2)) - (v912 + ((~(((v913 ^ -1) | (-(v913 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
    v968[v1065] = v969;
    int * v972 = v885->cache_vals;
    int v1068 = ((((((int)((unsigned int)((int)((unsigned int)v889 >> 2)) >> 1)) & 1) * 2) + ((((v909 + ((~(((v911 ^ -1) | (-(v911 ^ -1))) >> 31)) & 2)) - (v912 + ((~(((v913 ^ -1) | (-(v913 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
    v972[v1068] = v970;
    int * v974 = v885->cache_tags;
    int v1071 = ((((int)((unsigned int)((int)((unsigned int)v889 >> 2)) >> 1)) & 1) * 2) + ((((v909 + ((~(((v911 ^ -1) | (-(v911 ^ -1))) >> 31)) & 2)) - (v912 + ((~(((v913 ^ -1) | (-(v913 ^ -1))) >> 31)) & 2))) >> 31) & 1);
    int v1072 = (int)((unsigned int)((int)((unsigned int)v889 >> 2)) >> 1);
    v974[v1071] = v1072;
    int * v976 = v885->cache_dirty;
    v976[v1071] = 0;
    int * v978 = v885->cache_age;
    v978[v1071] = 1;
    int * v980 = v885->cache_age;
    int v981 = v980[v1071];
    int v982 = v980[v1000];
    int v1078 = v982 + ((int)((unsigned int)(v982 - v981) >> 31));
    v980[v1000] = v1078;
    int * v984 = v885->cache_age;
    int v985 = v984[v1001];
    int v1080 = v985 + ((int)((unsigned int)(v985 - v981) >> 31));
    v984[v1001] = v1080;
    int * v987 = v885->cache_age;
    v987[v1071] = 0;
    v990 = v1071;
  }
  int v1083 = (v990 * 2) + (((int)((unsigned int)v889 >> 2)) & 1);
  int v991 = v897[v1083];
  int * v992 = v885->regs;
  v992[9] = v991;
  struct StateG * v994 = slot_19(v885);
  return v994;
}

struct StateG * slot_20(struct StateG * v1129) {
  int * v1130 = v1129->saved_regs;
  int * v1131 = v1129->regs;
  int v1132 = v1131[14];
  v1130[14] = v1132;
  int v1134 = v1129->timer;
  int v1145 = v1134 + 1;
  v1129->timer = v1145;
  int * v1136 = v1129->regs;
  int v1137 = v1136[14];
  int v1147 = v1137 + 4;
  v1136[14] = v1147;
  struct StateG * v1139 = slot_22(v1129);
  return v1139;
}

struct StateG * snippet(struct StateG * v0) {
  struct StateG * v1 = slot_0(v0);
  return v1;
}

struct StateG * slot_8(struct StateG * v141) {
  int * v142 = v141->regs;
  int v143 = v142[14];
  int v144 = v142[15];
  bool v163 = v143 >= v144;
  struct StateG * v158;
  if (v163) {
    int * v145 = v141->pht;
    v145[0] = 1;
    v158 = v141;
  } else {
    int * v148 = v141->pht;
    v148[0] = 0;
    int v150 = v141->timer;
    int v169 = v150 + 15;
    v141->timer = v169;
    int * v152 = v141->saved_regs;
    int v153 = v152[11];
    int * v154 = v141->regs;
    v154[11] = v153;
    struct StateG * v156 = slot_11(v141);
    v158 = v156;
  }
  return v158;
}

struct StateG * slot_4(struct StateG * v54) {
  int v55 = v54->timer;
  int v61 = v55 + 1;
  v54->timer = v61;
  int * v57 = v54->regs;
  v57[5] = 0;
  struct StateG * v59 = slot_5(v54);
  return v59;
}

struct StateG * slot_15(struct StateG * v844) {
  int v845 = v844->timer;
  int v853 = v845 + 1;
  v844->timer = v853;
  int * v847 = v844->regs;
  int v848 = v847[13];
  int v849 = v847[14];
  int v858 = v848 + v849;
  v847[8] = v858;
  struct StateG * v851 = slot_17(v844);
  return v851;
}

struct StateG * slot_18(struct StateG * v1089) {
  int * v1090 = v1089->saved_regs;
  int * v1091 = v1089->regs;
  int v1092 = v1091[5];
  v1090[5] = v1092;
  int v1094 = v1089->timer;
  int v1106 = v1094 + 1;
  v1089->timer = v1106;
  int * v1096 = v1089->regs;
  int v1097 = v1096[5];
  int v1098 = v1096[16];
  int v1109 = v1097 | v1098;
  v1096[5] = v1109;
  struct StateG * v1100 = slot_20(v1089);
  return v1100;
}

struct StateG * slot_9(struct StateG * v177) {
  int * v178 = v177->saved_regs;
  int * v179 = v177->regs;
  int v180 = v179[7];
  v178[7] = v180;
  int v182 = v177->timer;
  int v296 = v182 + 1;
  v177->timer = v296;
  int * v184 = v177->regs;
  int v185 = v184[6];
  int * v186 = v177->cache_tags;
  int v300 = (((int)((unsigned int)((int)((unsigned int)v185 >> 2)) >> 1)) & 1) * 2;
  int v187 = v186[v300];
  int v301 = ((((int)((unsigned int)((int)((unsigned int)v185 >> 2)) >> 1)) & 1) * 2) + 1;
  int v188 = v186[v301];
  int v302 = 4 + ((((int)((unsigned int)((int)((unsigned int)v185 >> 2)) >> 1)) & 3) * 2);
  int v189 = v186[v302];
  int v303 = (4 + ((((int)((unsigned int)((int)((unsigned int)v185 >> 2)) >> 1)) & 3) * 2)) + 1;
  int v190 = v186[v303];
  int v191 = v177->timer;
  int v304 = v191 + ((100 ^ (((~(((v189 ^ ((int)((unsigned int)((int)((unsigned int)v185 >> 2)) >> 1))) | (-(v189 ^ ((int)((unsigned int)((int)((unsigned int)v185 >> 2)) >> 1))))) >> 31)) | (~(((v190 ^ ((int)((unsigned int)((int)((unsigned int)v185 >> 2)) >> 1))) | (-(v190 ^ ((int)((unsigned int)((int)((unsigned int)v185 >> 2)) >> 1))))) >> 31))) & 104)) ^ (((~(((v187 ^ ((int)((unsigned int)((int)((unsigned int)v185 >> 2)) >> 1))) | (-(v187 ^ ((int)((unsigned int)((int)((unsigned int)v185 >> 2)) >> 1))))) >> 31)) | (~(((v188 ^ ((int)((unsigned int)((int)((unsigned int)v185 >> 2)) >> 1))) | (-(v188 ^ ((int)((unsigned int)((int)((unsigned int)v185 >> 2)) >> 1))))) >> 31))) & (1 ^ (100 ^ (((~(((v189 ^ ((int)((unsigned int)((int)((unsigned int)v185 >> 2)) >> 1))) | (-(v189 ^ ((int)((unsigned int)((int)((unsigned int)v185 >> 2)) >> 1))))) >> 31)) | (~(((v190 ^ ((int)((unsigned int)((int)((unsigned int)v185 >> 2)) >> 1))) | (-(v190 ^ ((int)((unsigned int)((int)((unsigned int)v185 >> 2)) >> 1))))) >> 31))) & 104)))));
  v177->timer = v304;
  int * v193 = v177->cache_vals;
  bool v305 = !(((~(((v187 ^ ((int)((unsigned int)((int)((unsigned int)v185 >> 2)) >> 1))) | (-(v187 ^ ((int)((unsigned int)((int)((unsigned int)v185 >> 2)) >> 1))))) >> 31)) | (~(((v188 ^ ((int)((unsigned int)((int)((unsigned int)v185 >> 2)) >> 1))) | (-(v188 ^ ((int)((unsigned int)((int)((unsigned int)v185 >> 2)) >> 1))))) >> 31))) == 0);
  int v286;
  if (v305) {
    int * v194 = v177->cache_age;
    int v307 = ((((int)((unsigned int)((int)((unsigned int)v185 >> 2)) >> 1)) & 1) * 2) + ((~(((v188 ^ ((int)((unsigned int)((int)((unsigned int)v185 >> 2)) >> 1))) | (-(v188 ^ ((int)((unsigned int)((int)((unsigned int)v185 >> 2)) >> 1))))) >> 31)) & 1);
    int v195 = v194[v307];
    int v196 = v194[v300];
    int v308 = v196 + ((int)((unsigned int)(v196 - v195) >> 31));
    v194[v300] = v308;
    int * v198 = v177->cache_age;
    int v199 = v198[v301];
    int v310 = v199 + ((int)((unsigned int)(v199 - v195) >> 31));
    v198[v301] = v310;
    int * v201 = v177->cache_age;
    v201[v307] = 0;
    v286 = v307;
  } else {
    int * v204 = v177->cache_age;
    int v314 = (((int)((unsigned int)((int)((unsigned int)v185 >> 2)) >> 1)) & 1) * 2;
    int v205 = v204[v314];
    int * v206 = v177->cache_tags;
    int v207 = v206[v314];
    int v208 = v204[v301];
    int v209 = v206[v301];
    bool v316 = !(((~(((v189 ^ ((int)((unsigned int)((int)((unsigned int)v185 >> 2)) >> 1))) | (-(v189 ^ ((int)((unsigned int)((int)((unsigned int)v185 >> 2)) >> 1))))) >> 31)) | (~(((v190 ^ ((int)((unsigned int)((int)((unsigned int)v185 >> 2)) >> 1))) | (-(v190 ^ ((int)((unsigned int)((int)((unsigned int)v185 >> 2)) >> 1))))) >> 31))) == 0);
    int v263;
    if (v316) {
      int * v210 = v177->cache_age;
      int v318 = (4 + ((((int)((unsigned int)((int)((unsigned int)v185 >> 2)) >> 1)) & 3) * 2)) + ((~(((v190 ^ ((int)((unsigned int)((int)((unsigned int)v185 >> 2)) >> 1))) | (-(v190 ^ ((int)((unsigned int)((int)((unsigned int)v185 >> 2)) >> 1))))) >> 31)) & 1);
      int v211 = v210[v318];
      int v212 = v210[v302];
      int v319 = v212 + ((int)((unsigned int)(v212 - v211) >> 31));
      v210[v302] = v319;
      int * v214 = v177->cache_age;
      int v215 = v214[v303];
      int v321 = v215 + ((int)((unsigned int)(v215 - v211) >> 31));
      v214[v303] = v321;
      int * v217 = v177->cache_age;
      v217[v318] = 0;
      v263 = v318;
    } else {
      int * v220 = v177->cache_age;
      int v325 = 4 + ((((int)((unsigned int)((int)((unsigned int)v185 >> 2)) >> 1)) & 3) * 2);
      int v221 = v220[v325];
      int * v222 = v177->cache_tags;
      int v223 = v222[v325];
      int v224 = v220[v303];
      int v225 = v222[v303];
      int * v226 = v177->cache_dirty;
      int v328 = (4 + ((((int)((unsigned int)((int)((unsigned int)v185 >> 2)) >> 1)) & 3) * 2)) + ((((v221 + ((~(((v223 ^ -1) | (-(v223 ^ -1))) >> 31)) & 2)) - (v224 + ((~(((v225 ^ -1) | (-(v225 ^ -1))) >> 31)) & 2))) >> 31) & 1);
      int v227 = v226[v328];
      bool v329 = !(v227 == 0);
      if (v329) {
        int * v228 = v177->cache_tags;
        int v229 = v228[v328];
        int * v230 = v177->cache_vals;
        int v332 = ((4 + ((((int)((unsigned int)((int)((unsigned int)v185 >> 2)) >> 1)) & 3) * 2)) + ((((v221 + ((~(((v223 ^ -1) | (-(v223 ^ -1))) >> 31)) & 2)) - (v224 + ((~(((v225 ^ -1) | (-(v225 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
        int v231 = v230[v332];
        int v333 = (((4 + ((((int)((unsigned int)((int)((unsigned int)v185 >> 2)) >> 1)) & 3) * 2)) + ((((v221 + ((~(((v223 ^ -1) | (-(v223 ^ -1))) >> 31)) & 2)) - (v224 + ((~(((v225 ^ -1) | (-(v225 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
        int v232 = v230[v333];
        int * v233 = v177->mem;
        int v335 = v229 * 2;
        v233[v335] = v231;
        int * v235 = v177->mem;
        int v338 = (v229 * 2) + 1;
        v235[v338] = v232;
        ;
      } else {
        ;
      }
      int * v240 = v177->mem;
      int v343 = ((int)((unsigned int)((int)((unsigned int)v185 >> 2)) >> 1)) * 2;
      int v241 = v240[v343];
      int v344 = (((int)((unsigned int)((int)((unsigned int)v185 >> 2)) >> 1)) * 2) + 1;
      int v242 = v240[v344];
      int * v243 = v177->cache_vals;
      int v346 = ((4 + ((((int)((unsigned int)((int)((unsigned int)v185 >> 2)) >> 1)) & 3) * 2)) + ((((v221 + ((~(((v223 ^ -1) | (-(v223 ^ -1))) >> 31)) & 2)) - (v224 + ((~(((v225 ^ -1) | (-(v225 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
      v243[v346] = v241;
      int * v245 = v177->cache_vals;
      int v349 = (((4 + ((((int)((unsigned int)((int)((unsigned int)v185 >> 2)) >> 1)) & 3) * 2)) + ((((v221 + ((~(((v223 ^ -1) | (-(v223 ^ -1))) >> 31)) & 2)) - (v224 + ((~(((v225 ^ -1) | (-(v225 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
      v245[v349] = v242;
      int * v247 = v177->cache_tags;
      int v352 = (int)((unsigned int)((int)((unsigned int)v185 >> 2)) >> 1);
      v247[v328] = v352;
      int * v249 = v177->cache_dirty;
      v249[v328] = 0;
      int * v251 = v177->cache_age;
      v251[v328] = 1;
      int * v253 = v177->cache_age;
      int v254 = v253[v328];
      int v255 = v253[v302];
      int v358 = v255 + ((int)((unsigned int)(v255 - v254) >> 31));
      v253[v302] = v358;
      int * v257 = v177->cache_age;
      int v258 = v257[v303];
      int v360 = v258 + ((int)((unsigned int)(v258 - v254) >> 31));
      v257[v303] = v360;
      int * v260 = v177->cache_age;
      v260[v328] = 0;
      v263 = v328;
    }
    int * v264 = v177->cache_vals;
    int v363 = v263 * 2;
    int v265 = v264[v363];
    int v364 = (v263 * 2) + 1;
    int v266 = v264[v364];
    int v365 = (((((int)((unsigned int)((int)((unsigned int)v185 >> 2)) >> 1)) & 1) * 2) + ((((v205 + ((~(((v207 ^ -1) | (-(v207 ^ -1))) >> 31)) & 2)) - (v208 + ((~(((v209 ^ -1) | (-(v209 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
    v264[v365] = v265;
    int * v268 = v177->cache_vals;
    int v368 = ((((((int)((unsigned int)((int)((unsigned int)v185 >> 2)) >> 1)) & 1) * 2) + ((((v205 + ((~(((v207 ^ -1) | (-(v207 ^ -1))) >> 31)) & 2)) - (v208 + ((~(((v209 ^ -1) | (-(v209 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
    v268[v368] = v266;
    int * v270 = v177->cache_tags;
    int v371 = ((((int)((unsigned int)((int)((unsigned int)v185 >> 2)) >> 1)) & 1) * 2) + ((((v205 + ((~(((v207 ^ -1) | (-(v207 ^ -1))) >> 31)) & 2)) - (v208 + ((~(((v209 ^ -1) | (-(v209 ^ -1))) >> 31)) & 2))) >> 31) & 1);
    int v372 = (int)((unsigned int)((int)((unsigned int)v185 >> 2)) >> 1);
    v270[v371] = v372;
    int * v272 = v177->cache_dirty;
    v272[v371] = 0;
    int * v274 = v177->cache_age;
    v274[v371] = 1;
    int * v276 = v177->cache_age;
    int v277 = v276[v371];
    int v278 = v276[v300];
    int v378 = v278 + ((int)((unsigned int)(v278 - v277) >> 31));
    v276[v300] = v378;
    int * v280 = v177->cache_age;
    int v281 = v280[v301];
    int v380 = v281 + ((int)((unsigned int)(v281 - v277) >> 31));
    v280[v301] = v380;
    int * v283 = v177->cache_age;
    v283[v371] = 0;
    v286 = v371;
  }
  int v383 = (v286 * 2) + (((int)((unsigned int)v185 >> 2)) & 1);
  int v287 = v193[v383];
  int * v288 = v177->regs;
  v288[7] = v287;
  struct StateG * v290 = slot_12(v177);
  return v290;
}

struct StateG * slot_22(struct StateG * v1166) {
  int * v1167 = v1166->saved_regs;
  int v1168 = v1167[14];
  int * v1169 = v1166->regs;
  int v1170 = v1169[15];
  bool v1215 = v1168 >= v1170;
  struct StateG * v1209;
  if (v1215) {
    int * v1171 = v1166->pht;
    v1171[0] = 1;
    int v1173 = v1166->timer;
    int v1219 = v1173 + 15;
    v1166->timer = v1219;
    int * v1175 = v1166->saved_regs;
    int v1176 = v1175[6];
    int * v1177 = v1166->regs;
    v1177[6] = v1176;
    int * v1179 = v1166->saved_regs;
    int v1180 = v1179[7];
    int * v1181 = v1166->regs;
    v1181[7] = v1180;
    int * v1183 = v1166->saved_regs;
    int v1184 = v1183[8];
    int * v1185 = v1166->regs;
    v1185[8] = v1184;
    int * v1187 = v1166->saved_regs;
    int v1188 = v1187[9];
    int * v1189 = v1166->regs;
    v1189[9] = v1188;
    int * v1191 = v1166->saved_regs;
    int v1192 = v1191[16];
    int * v1193 = v1166->regs;
    v1193[16] = v1192;
    int * v1195 = v1166->saved_regs;
    int v1196 = v1195[5];
    int * v1197 = v1166->regs;
    v1197[5] = v1196;
    int * v1199 = v1166->saved_regs;
    int v1200 = v1199[14];
    int * v1201 = v1166->regs;
    v1201[14] = v1200;
    struct StateG * v1203 = slot_24(v1166);
    v1209 = v1203;
  } else {
    int * v1205 = v1166->pht;
    v1205[0] = 0;
    struct StateG * v1207 = slot_25(v1166);
    v1209 = v1207;
  }
  return v1209;
}

struct StateG * slot_11(struct StateG * v388) {
  int v389 = v388->timer;
  int v397 = v389 + 1;
  v388->timer = v397;
  int * v391 = v388->regs;
  int v392 = v391[12];
  int v393 = v391[14];
  int v402 = v392 + v393;
  v391[6] = v402;
  struct StateG * v395 = slot_13(v388);
  return v395;
}



/*****************************************
End of C Generated Code
*******************************************/

void init(struct StateG *s) {
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
  for (int i=0; i<PHT_ENTRIES; i++) {
    s->pht[i] = 0;
  }
}

int main(int argc, char* argv[]) {
  struct StateG s1, s2;
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
  struct StateG *s1_ = snippet(&s1);
  struct StateG *s2_ = snippet(&s2);
  //@ assert untainted_timer: !\tainted(s1_->timer==s2_->timer);
  koika_assert(s1_->timer==s2_->timer, "timing leak");
  return 0;
}