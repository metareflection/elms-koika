// verify: leak (CBMC should report VERIFICATION FAILED) [unwind 65]
#define NUM_REGS 32
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
struct StateT * slot_16(struct StateT * v1037);
struct StateT * slot_23(struct StateT * v1732);
struct StateT * slot_5(struct StateT * v445);
struct StateT * slot_2(struct StateT * v409);
struct StateT * slot_7(struct StateT * v483);
struct StateT * slot_21(struct StateT * v1412);
struct StateT * slot_3(struct StateT * v421);
struct StateT * slot_10(struct StateT * v714);
struct StateT * slot_1(struct StateT * v205);
struct StateT * slot_19(struct StateT * v1081);
struct StateT * slot_13(struct StateT * v963);
struct StateT * slot_0(struct StateT * v2);
struct StateT * slot_14(struct StateT * v1009);
struct StateT * snippet(struct StateT * v0);
struct StateT * slot_8(struct StateT * v686);
struct StateT * slot_4(struct StateT * v437);
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

struct StateT * slot_16(struct StateT * v1037) {
  int v1038 = v1037->timer;
  int v1045 = v1038 + 1;
  v1037->timer = v1045;
  int * v1040 = v1037->regs;
  int v1041 = v1040[10];
  int v1048 = v1041 << 2;
  v1040[10] = v1048;
  struct StateT * v1043 = slot_19(v1037);
  return v1043;
}

struct StateT * slot_23(struct StateT * v1732) {
  int v1733 = v1732->timer;
  int v1736 = v1733 + 1;
  v1732->timer = v1736;
  return v1732;
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

struct StateT * slot_21(struct StateT * v1412) {
  int v1413 = v1412->timer;
  int v1583 = v1413 + 1;
  v1412->timer = v1583;
  int * v1415 = v1412->regs;
  int v1416 = v1415[10];
  int v1417 = v1415[12];
  int * v1418 = v1412->cache_tags;
  int v1588 = (((int)((unsigned int)((int)((unsigned int)v1416 >> 2)) >> 1)) & 1) * 2;
  int v1419 = v1418[v1588];
  int v1589 = ((((int)((unsigned int)((int)((unsigned int)v1416 >> 2)) >> 1)) & 1) * 2) + 1;
  int v1420 = v1418[v1589];
  int v1590 = 4 + ((((int)((unsigned int)((int)((unsigned int)v1416 >> 2)) >> 1)) & 3) * 2);
  int v1421 = v1418[v1590];
  int v1591 = (4 + ((((int)((unsigned int)((int)((unsigned int)v1416 >> 2)) >> 1)) & 3) * 2)) + 1;
  int v1422 = v1418[v1591];
  int v1423 = v1412->timer;
  int v1592 = v1423 + ((100 ^ (((~(((v1421 ^ ((int)((unsigned int)((int)((unsigned int)v1416 >> 2)) >> 1))) | (-(v1421 ^ ((int)((unsigned int)((int)((unsigned int)v1416 >> 2)) >> 1))))) >> 31)) | (~(((v1422 ^ ((int)((unsigned int)((int)((unsigned int)v1416 >> 2)) >> 1))) | (-(v1422 ^ ((int)((unsigned int)((int)((unsigned int)v1416 >> 2)) >> 1))))) >> 31))) & 104)) ^ (((~(((v1419 ^ ((int)((unsigned int)((int)((unsigned int)v1416 >> 2)) >> 1))) | (-(v1419 ^ ((int)((unsigned int)((int)((unsigned int)v1416 >> 2)) >> 1))))) >> 31)) | (~(((v1420 ^ ((int)((unsigned int)((int)((unsigned int)v1416 >> 2)) >> 1))) | (-(v1420 ^ ((int)((unsigned int)((int)((unsigned int)v1416 >> 2)) >> 1))))) >> 31))) & (1 ^ (100 ^ (((~(((v1421 ^ ((int)((unsigned int)((int)((unsigned int)v1416 >> 2)) >> 1))) | (-(v1421 ^ ((int)((unsigned int)((int)((unsigned int)v1416 >> 2)) >> 1))))) >> 31)) | (~(((v1422 ^ ((int)((unsigned int)((int)((unsigned int)v1416 >> 2)) >> 1))) | (-(v1422 ^ ((int)((unsigned int)((int)((unsigned int)v1416 >> 2)) >> 1))))) >> 31))) & 104)))));
  v1412->timer = v1592;
  bool v1593 = !(((~(((v1419 ^ ((int)((unsigned int)((int)((unsigned int)v1416 >> 2)) >> 1))) | (-(v1419 ^ ((int)((unsigned int)((int)((unsigned int)v1416 >> 2)) >> 1))))) >> 31)) | (~(((v1420 ^ ((int)((unsigned int)((int)((unsigned int)v1416 >> 2)) >> 1))) | (-(v1420 ^ ((int)((unsigned int)((int)((unsigned int)v1416 >> 2)) >> 1))))) >> 31))) == 0);
  int v1517;
  if (v1593) {
    int * v1425 = v1412->cache_age;
    int v1595 = ((((int)((unsigned int)((int)((unsigned int)v1416 >> 2)) >> 1)) & 1) * 2) + ((~(((v1420 ^ ((int)((unsigned int)((int)((unsigned int)v1416 >> 2)) >> 1))) | (-(v1420 ^ ((int)((unsigned int)((int)((unsigned int)v1416 >> 2)) >> 1))))) >> 31)) & 1);
    int v1426 = v1425[v1595];
    int v1427 = v1425[v1588];
    int v1596 = v1427 + ((int)((unsigned int)(v1427 - v1426) >> 31));
    v1425[v1588] = v1596;
    int * v1429 = v1412->cache_age;
    int v1430 = v1429[v1589];
    int v1598 = v1430 + ((int)((unsigned int)(v1430 - v1426) >> 31));
    v1429[v1589] = v1598;
    int * v1432 = v1412->cache_age;
    v1432[v1595] = 0;
    v1517 = v1595;
  } else {
    int * v1435 = v1412->cache_age;
    int v1602 = (((int)((unsigned int)((int)((unsigned int)v1416 >> 2)) >> 1)) & 1) * 2;
    int v1436 = v1435[v1602];
    int * v1437 = v1412->cache_tags;
    int v1438 = v1437[v1602];
    int v1439 = v1435[v1589];
    int v1440 = v1437[v1589];
    bool v1604 = !(((~(((v1421 ^ ((int)((unsigned int)((int)((unsigned int)v1416 >> 2)) >> 1))) | (-(v1421 ^ ((int)((unsigned int)((int)((unsigned int)v1416 >> 2)) >> 1))))) >> 31)) | (~(((v1422 ^ ((int)((unsigned int)((int)((unsigned int)v1416 >> 2)) >> 1))) | (-(v1422 ^ ((int)((unsigned int)((int)((unsigned int)v1416 >> 2)) >> 1))))) >> 31))) == 0);
    int v1494;
    if (v1604) {
      int * v1441 = v1412->cache_age;
      int v1606 = (4 + ((((int)((unsigned int)((int)((unsigned int)v1416 >> 2)) >> 1)) & 3) * 2)) + ((~(((v1422 ^ ((int)((unsigned int)((int)((unsigned int)v1416 >> 2)) >> 1))) | (-(v1422 ^ ((int)((unsigned int)((int)((unsigned int)v1416 >> 2)) >> 1))))) >> 31)) & 1);
      int v1442 = v1441[v1606];
      int v1443 = v1441[v1590];
      int v1607 = v1443 + ((int)((unsigned int)(v1443 - v1442) >> 31));
      v1441[v1590] = v1607;
      int * v1445 = v1412->cache_age;
      int v1446 = v1445[v1591];
      int v1609 = v1446 + ((int)((unsigned int)(v1446 - v1442) >> 31));
      v1445[v1591] = v1609;
      int * v1448 = v1412->cache_age;
      v1448[v1606] = 0;
      v1494 = v1606;
    } else {
      int * v1451 = v1412->cache_age;
      int v1613 = 4 + ((((int)((unsigned int)((int)((unsigned int)v1416 >> 2)) >> 1)) & 3) * 2);
      int v1452 = v1451[v1613];
      int * v1453 = v1412->cache_tags;
      int v1454 = v1453[v1613];
      int v1455 = v1451[v1591];
      int v1456 = v1453[v1591];
      int * v1457 = v1412->cache_dirty;
      int v1616 = (4 + ((((int)((unsigned int)((int)((unsigned int)v1416 >> 2)) >> 1)) & 3) * 2)) + ((((v1452 + ((~(((v1454 ^ -1) | (-(v1454 ^ -1))) >> 31)) & 2)) - (v1455 + ((~(((v1456 ^ -1) | (-(v1456 ^ -1))) >> 31)) & 2))) >> 31) & 1);
      int v1458 = v1457[v1616];
      bool v1617 = !(v1458 == 0);
      if (v1617) {
        int * v1459 = v1412->cache_tags;
        int v1460 = v1459[v1616];
        int * v1461 = v1412->cache_vals;
        int v1620 = ((4 + ((((int)((unsigned int)((int)((unsigned int)v1416 >> 2)) >> 1)) & 3) * 2)) + ((((v1452 + ((~(((v1454 ^ -1) | (-(v1454 ^ -1))) >> 31)) & 2)) - (v1455 + ((~(((v1456 ^ -1) | (-(v1456 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
        int v1462 = v1461[v1620];
        int v1621 = (((4 + ((((int)((unsigned int)((int)((unsigned int)v1416 >> 2)) >> 1)) & 3) * 2)) + ((((v1452 + ((~(((v1454 ^ -1) | (-(v1454 ^ -1))) >> 31)) & 2)) - (v1455 + ((~(((v1456 ^ -1) | (-(v1456 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
        int v1463 = v1461[v1621];
        int * v1464 = v1412->mem;
        int v1623 = v1460 * 2;
        v1464[v1623] = v1462;
        int * v1466 = v1412->mem;
        int v1626 = (v1460 * 2) + 1;
        v1466[v1626] = v1463;
        ;
      } else {
        ;
      }
      int * v1471 = v1412->mem;
      int v1631 = ((int)((unsigned int)((int)((unsigned int)v1416 >> 2)) >> 1)) * 2;
      int v1472 = v1471[v1631];
      int v1632 = (((int)((unsigned int)((int)((unsigned int)v1416 >> 2)) >> 1)) * 2) + 1;
      int v1473 = v1471[v1632];
      int * v1474 = v1412->cache_vals;
      int v1634 = ((4 + ((((int)((unsigned int)((int)((unsigned int)v1416 >> 2)) >> 1)) & 3) * 2)) + ((((v1452 + ((~(((v1454 ^ -1) | (-(v1454 ^ -1))) >> 31)) & 2)) - (v1455 + ((~(((v1456 ^ -1) | (-(v1456 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
      v1474[v1634] = v1472;
      int * v1476 = v1412->cache_vals;
      int v1637 = (((4 + ((((int)((unsigned int)((int)((unsigned int)v1416 >> 2)) >> 1)) & 3) * 2)) + ((((v1452 + ((~(((v1454 ^ -1) | (-(v1454 ^ -1))) >> 31)) & 2)) - (v1455 + ((~(((v1456 ^ -1) | (-(v1456 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
      v1476[v1637] = v1473;
      int * v1478 = v1412->cache_tags;
      int v1640 = (int)((unsigned int)((int)((unsigned int)v1416 >> 2)) >> 1);
      v1478[v1616] = v1640;
      int * v1480 = v1412->cache_dirty;
      v1480[v1616] = 0;
      int * v1482 = v1412->cache_age;
      v1482[v1616] = 1;
      int * v1484 = v1412->cache_age;
      int v1485 = v1484[v1616];
      int v1486 = v1484[v1590];
      int v1646 = v1486 + ((int)((unsigned int)(v1486 - v1485) >> 31));
      v1484[v1590] = v1646;
      int * v1488 = v1412->cache_age;
      int v1489 = v1488[v1591];
      int v1648 = v1489 + ((int)((unsigned int)(v1489 - v1485) >> 31));
      v1488[v1591] = v1648;
      int * v1491 = v1412->cache_age;
      v1491[v1616] = 0;
      v1494 = v1616;
    }
    int * v1495 = v1412->cache_vals;
    int v1651 = v1494 * 2;
    int v1496 = v1495[v1651];
    int v1652 = (v1494 * 2) + 1;
    int v1497 = v1495[v1652];
    int v1653 = (((((int)((unsigned int)((int)((unsigned int)v1416 >> 2)) >> 1)) & 1) * 2) + ((((v1436 + ((~(((v1438 ^ -1) | (-(v1438 ^ -1))) >> 31)) & 2)) - (v1439 + ((~(((v1440 ^ -1) | (-(v1440 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
    v1495[v1653] = v1496;
    int * v1499 = v1412->cache_vals;
    int v1656 = ((((((int)((unsigned int)((int)((unsigned int)v1416 >> 2)) >> 1)) & 1) * 2) + ((((v1436 + ((~(((v1438 ^ -1) | (-(v1438 ^ -1))) >> 31)) & 2)) - (v1439 + ((~(((v1440 ^ -1) | (-(v1440 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
    v1499[v1656] = v1497;
    int * v1501 = v1412->cache_tags;
    int v1659 = ((((int)((unsigned int)((int)((unsigned int)v1416 >> 2)) >> 1)) & 1) * 2) + ((((v1436 + ((~(((v1438 ^ -1) | (-(v1438 ^ -1))) >> 31)) & 2)) - (v1439 + ((~(((v1440 ^ -1) | (-(v1440 ^ -1))) >> 31)) & 2))) >> 31) & 1);
    int v1660 = (int)((unsigned int)((int)((unsigned int)v1416 >> 2)) >> 1);
    v1501[v1659] = v1660;
    int * v1503 = v1412->cache_dirty;
    v1503[v1659] = 0;
    int * v1505 = v1412->cache_age;
    v1505[v1659] = 1;
    int * v1507 = v1412->cache_age;
    int v1508 = v1507[v1659];
    int v1509 = v1507[v1588];
    int v1666 = v1509 + ((int)((unsigned int)(v1509 - v1508) >> 31));
    v1507[v1588] = v1666;
    int * v1511 = v1412->cache_age;
    int v1512 = v1511[v1589];
    int v1668 = v1512 + ((int)((unsigned int)(v1512 - v1508) >> 31));
    v1511[v1589] = v1668;
    int * v1514 = v1412->cache_age;
    v1514[v1659] = 0;
    v1517 = v1659;
  }
  int * v1518 = v1412->cache_vals;
  int v1671 = (v1517 * 2) + (((int)((unsigned int)v1416 >> 2)) & 1);
  v1518[v1671] = v1417;
  int * v1520 = v1412->cache_tags;
  int v1521 = v1520[v1590];
  int v1522 = v1520[v1591];
  bool v1674 = !(((~(((v1521 ^ ((int)((unsigned int)((int)((unsigned int)v1416 >> 2)) >> 1))) | (-(v1521 ^ ((int)((unsigned int)((int)((unsigned int)v1416 >> 2)) >> 1))))) >> 31)) | (~(((v1522 ^ ((int)((unsigned int)((int)((unsigned int)v1416 >> 2)) >> 1))) | (-(v1522 ^ ((int)((unsigned int)((int)((unsigned int)v1416 >> 2)) >> 1))))) >> 31))) == 0);
  int v1576;
  if (v1674) {
    int * v1523 = v1412->cache_age;
    int v1676 = (4 + ((((int)((unsigned int)((int)((unsigned int)v1416 >> 2)) >> 1)) & 3) * 2)) + ((~(((v1522 ^ ((int)((unsigned int)((int)((unsigned int)v1416 >> 2)) >> 1))) | (-(v1522 ^ ((int)((unsigned int)((int)((unsigned int)v1416 >> 2)) >> 1))))) >> 31)) & 1);
    int v1524 = v1523[v1676];
    int v1525 = v1523[v1590];
    int v1677 = v1525 + ((int)((unsigned int)(v1525 - v1524) >> 31));
    v1523[v1590] = v1677;
    int * v1527 = v1412->cache_age;
    int v1528 = v1527[v1591];
    int v1679 = v1528 + ((int)((unsigned int)(v1528 - v1524) >> 31));
    v1527[v1591] = v1679;
    int * v1530 = v1412->cache_age;
    v1530[v1676] = 0;
    v1576 = v1676;
  } else {
    int * v1533 = v1412->cache_age;
    int v1683 = 4 + ((((int)((unsigned int)((int)((unsigned int)v1416 >> 2)) >> 1)) & 3) * 2);
    int v1534 = v1533[v1683];
    int * v1535 = v1412->cache_tags;
    int v1536 = v1535[v1683];
    int v1537 = v1533[v1591];
    int v1538 = v1535[v1591];
    int * v1539 = v1412->cache_dirty;
    int v1686 = (4 + ((((int)((unsigned int)((int)((unsigned int)v1416 >> 2)) >> 1)) & 3) * 2)) + ((((v1534 + ((~(((v1536 ^ -1) | (-(v1536 ^ -1))) >> 31)) & 2)) - (v1537 + ((~(((v1538 ^ -1) | (-(v1538 ^ -1))) >> 31)) & 2))) >> 31) & 1);
    int v1540 = v1539[v1686];
    bool v1687 = !(v1540 == 0);
    if (v1687) {
      int * v1541 = v1412->cache_tags;
      int v1542 = v1541[v1686];
      int * v1543 = v1412->cache_vals;
      int v1690 = ((4 + ((((int)((unsigned int)((int)((unsigned int)v1416 >> 2)) >> 1)) & 3) * 2)) + ((((v1534 + ((~(((v1536 ^ -1) | (-(v1536 ^ -1))) >> 31)) & 2)) - (v1537 + ((~(((v1538 ^ -1) | (-(v1538 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
      int v1544 = v1543[v1690];
      int v1691 = (((4 + ((((int)((unsigned int)((int)((unsigned int)v1416 >> 2)) >> 1)) & 3) * 2)) + ((((v1534 + ((~(((v1536 ^ -1) | (-(v1536 ^ -1))) >> 31)) & 2)) - (v1537 + ((~(((v1538 ^ -1) | (-(v1538 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
      int v1545 = v1543[v1691];
      int * v1546 = v1412->mem;
      int v1693 = v1542 * 2;
      v1546[v1693] = v1544;
      int * v1548 = v1412->mem;
      int v1696 = (v1542 * 2) + 1;
      v1548[v1696] = v1545;
      ;
    } else {
      ;
    }
    int * v1553 = v1412->mem;
    int v1701 = ((int)((unsigned int)((int)((unsigned int)v1416 >> 2)) >> 1)) * 2;
    int v1554 = v1553[v1701];
    int v1702 = (((int)((unsigned int)((int)((unsigned int)v1416 >> 2)) >> 1)) * 2) + 1;
    int v1555 = v1553[v1702];
    int * v1556 = v1412->cache_vals;
    int v1704 = ((4 + ((((int)((unsigned int)((int)((unsigned int)v1416 >> 2)) >> 1)) & 3) * 2)) + ((((v1534 + ((~(((v1536 ^ -1) | (-(v1536 ^ -1))) >> 31)) & 2)) - (v1537 + ((~(((v1538 ^ -1) | (-(v1538 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
    v1556[v1704] = v1554;
    int * v1558 = v1412->cache_vals;
    int v1707 = (((4 + ((((int)((unsigned int)((int)((unsigned int)v1416 >> 2)) >> 1)) & 3) * 2)) + ((((v1534 + ((~(((v1536 ^ -1) | (-(v1536 ^ -1))) >> 31)) & 2)) - (v1537 + ((~(((v1538 ^ -1) | (-(v1538 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
    v1558[v1707] = v1555;
    int * v1560 = v1412->cache_tags;
    int v1710 = (int)((unsigned int)((int)((unsigned int)v1416 >> 2)) >> 1);
    v1560[v1686] = v1710;
    int * v1562 = v1412->cache_dirty;
    v1562[v1686] = 0;
    int * v1564 = v1412->cache_age;
    v1564[v1686] = 1;
    int * v1566 = v1412->cache_age;
    int v1567 = v1566[v1686];
    int v1568 = v1566[v1590];
    int v1716 = v1568 + ((int)((unsigned int)(v1568 - v1567) >> 31));
    v1566[v1590] = v1716;
    int * v1570 = v1412->cache_age;
    int v1571 = v1570[v1591];
    int v1718 = v1571 + ((int)((unsigned int)(v1571 - v1567) >> 31));
    v1570[v1591] = v1718;
    int * v1573 = v1412->cache_age;
    v1573[v1686] = 0;
    v1576 = v1686;
  }
  int * v1577 = v1412->cache_vals;
  int v1721 = (v1576 * 2) + (((int)((unsigned int)v1416 >> 2)) & 1);
  v1577[v1721] = v1417;
  int * v1579 = v1412->cache_dirty;
  v1579[v1576] = 1;
  struct StateT * v1581 = slot_23(v1412);
  return v1581;
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

struct StateT * slot_19(struct StateT * v1081) {
  int v1082 = v1081->timer;
  int v1090 = v1082 + 1;
  v1081->timer = v1090;
  int * v1084 = v1081->regs;
  int v1085 = v1084[13];
  int v1086 = v1084[10];
  int v1094 = v1085 + v1086;
  v1084[10] = v1094;
  struct StateT * v1088 = slot_21(v1081);
  return v1088;
}

struct StateT * slot_13(struct StateT * v963) {
  int * v964 = v963->regs;
  int v965 = v964[15];
  int v966 = v964[10];
  bool v990 = (v965 ^ -2147483648) < (v966 ^ -2147483648);
  struct StateT * v985;
  if (v990) {
    int v967 = v963->timer;
    int v991 = v967 + 15;
    v963->timer = v991;
    int * v969 = v963->saved_regs;
    int v970 = v969[14];
    int * v971 = v963->regs;
    v971[14] = v970;
    int * v973 = v963->saved_regs;
    int v974 = v973[11];
    int * v975 = v963->regs;
    v975[11] = v974;
    int * v977 = v963->saved_regs;
    int v978 = v977[12];
    int * v979 = v963->regs;
    v979[12] = v978;
    struct StateT * v981 = slot_14(v963);
    v985 = v981;
  } else {
    struct StateT * v983 = slot_14(v963);
    v985 = v983;
  }
  return v985;
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

struct StateT * slot_14(struct StateT * v1009) {
  int v1010 = v1009->timer;
  int v1017 = v1010 + 1;
  v1009->timer = v1017;
  int * v1012 = v1009->regs;
  int v1013 = v1012[10];
  int v1020 = v1013 & 7;
  v1012[10] = v1020;
  struct StateT * v1015 = slot_16(v1009);
  return v1015;
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
  koika_assert(s1_->timer==s2_->timer, "timing leak");
  return 0;
}