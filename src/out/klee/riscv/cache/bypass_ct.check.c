// verify: clean (KLEE should report no failing assertion) [budget 1200s]
#define NUM_REGS 32
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

struct StateT * snippet(struct StateT * v0);
struct StateT * slot_1(struct StateT * v17);
struct StateT * slot_6(struct StateT * v577);
struct StateT * slot_5(struct StateT * v563);
struct StateT * slot_4(struct StateT * v359);
struct StateT * slot_2(struct StateT * v31);
struct StateT * slot_3(struct StateT * v44);
struct StateT * slot_0(struct StateT * v2);
struct StateT * snippet(struct StateT * v0) {
  struct StateT * v1 = slot_0(v0);
  return v1;
}

struct StateT * slot_1(struct StateT * v17) {
  int v18 = v17->timer;
  int v25 = v18 + 1;
  v17->timer = v25;
  int * v20 = v17->regs;
  int v21 = v20[6];
  int v28 = v21 + 80;
  v20[6] = v28;
  struct StateT * v23 = slot_2(v17);
  return v23;
}

struct StateT * slot_6(struct StateT * v577) {
  int v578 = v577->timer;
  int v687 = v578 + 1;
  v577->timer = v687;
  int * v580 = v577->regs;
  int v581 = v580[6];
  int * v582 = v577->cache_tags;
  int v691 = (((int)((unsigned int)((int)((unsigned int)v581 >> 2)) >> 1)) & 1) * 2;
  int v583 = v582[v691];
  int v692 = ((((int)((unsigned int)((int)((unsigned int)v581 >> 2)) >> 1)) & 1) * 2) + 1;
  int v584 = v582[v692];
  int v693 = 4 + ((((int)((unsigned int)((int)((unsigned int)v581 >> 2)) >> 1)) & 3) * 2);
  int v585 = v582[v693];
  int v694 = (4 + ((((int)((unsigned int)((int)((unsigned int)v581 >> 2)) >> 1)) & 3) * 2)) + 1;
  int v586 = v582[v694];
  int v587 = v577->timer;
  int v695 = v587 + ((100 ^ (((~(((v585 ^ ((int)((unsigned int)((int)((unsigned int)v581 >> 2)) >> 1))) | (-(v585 ^ ((int)((unsigned int)((int)((unsigned int)v581 >> 2)) >> 1))))) >> 31)) | (~(((v586 ^ ((int)((unsigned int)((int)((unsigned int)v581 >> 2)) >> 1))) | (-(v586 ^ ((int)((unsigned int)((int)((unsigned int)v581 >> 2)) >> 1))))) >> 31))) & 104)) ^ (((~(((v583 ^ ((int)((unsigned int)((int)((unsigned int)v581 >> 2)) >> 1))) | (-(v583 ^ ((int)((unsigned int)((int)((unsigned int)v581 >> 2)) >> 1))))) >> 31)) | (~(((v584 ^ ((int)((unsigned int)((int)((unsigned int)v581 >> 2)) >> 1))) | (-(v584 ^ ((int)((unsigned int)((int)((unsigned int)v581 >> 2)) >> 1))))) >> 31))) & (1 ^ (100 ^ (((~(((v585 ^ ((int)((unsigned int)((int)((unsigned int)v581 >> 2)) >> 1))) | (-(v585 ^ ((int)((unsigned int)((int)((unsigned int)v581 >> 2)) >> 1))))) >> 31)) | (~(((v586 ^ ((int)((unsigned int)((int)((unsigned int)v581 >> 2)) >> 1))) | (-(v586 ^ ((int)((unsigned int)((int)((unsigned int)v581 >> 2)) >> 1))))) >> 31))) & 104)))));
  v577->timer = v695;
  int * v589 = v577->cache_vals;
  bool v696 = !(((~(((v583 ^ ((int)((unsigned int)((int)((unsigned int)v581 >> 2)) >> 1))) | (-(v583 ^ ((int)((unsigned int)((int)((unsigned int)v581 >> 2)) >> 1))))) >> 31)) | (~(((v584 ^ ((int)((unsigned int)((int)((unsigned int)v581 >> 2)) >> 1))) | (-(v584 ^ ((int)((unsigned int)((int)((unsigned int)v581 >> 2)) >> 1))))) >> 31))) == 0);
  int v682;
  if (v696) {
    int * v590 = v577->cache_age;
    int v698 = ((((int)((unsigned int)((int)((unsigned int)v581 >> 2)) >> 1)) & 1) * 2) + ((~(((v584 ^ ((int)((unsigned int)((int)((unsigned int)v581 >> 2)) >> 1))) | (-(v584 ^ ((int)((unsigned int)((int)((unsigned int)v581 >> 2)) >> 1))))) >> 31)) & 1);
    int v591 = v590[v698];
    int v592 = v590[v691];
    int v699 = v592 + ((int)((unsigned int)(v592 - v591) >> 31));
    v590[v691] = v699;
    int * v594 = v577->cache_age;
    int v595 = v594[v692];
    int v701 = v595 + ((int)((unsigned int)(v595 - v591) >> 31));
    v594[v692] = v701;
    int * v597 = v577->cache_age;
    v597[v698] = 0;
    v682 = v698;
  } else {
    int * v600 = v577->cache_age;
    int v705 = (((int)((unsigned int)((int)((unsigned int)v581 >> 2)) >> 1)) & 1) * 2;
    int v601 = v600[v705];
    int * v602 = v577->cache_tags;
    int v603 = v602[v705];
    int v604 = v600[v692];
    int v605 = v602[v692];
    bool v707 = !(((~(((v585 ^ ((int)((unsigned int)((int)((unsigned int)v581 >> 2)) >> 1))) | (-(v585 ^ ((int)((unsigned int)((int)((unsigned int)v581 >> 2)) >> 1))))) >> 31)) | (~(((v586 ^ ((int)((unsigned int)((int)((unsigned int)v581 >> 2)) >> 1))) | (-(v586 ^ ((int)((unsigned int)((int)((unsigned int)v581 >> 2)) >> 1))))) >> 31))) == 0);
    int v659;
    if (v707) {
      int * v606 = v577->cache_age;
      int v709 = (4 + ((((int)((unsigned int)((int)((unsigned int)v581 >> 2)) >> 1)) & 3) * 2)) + ((~(((v586 ^ ((int)((unsigned int)((int)((unsigned int)v581 >> 2)) >> 1))) | (-(v586 ^ ((int)((unsigned int)((int)((unsigned int)v581 >> 2)) >> 1))))) >> 31)) & 1);
      int v607 = v606[v709];
      int v608 = v606[v693];
      int v710 = v608 + ((int)((unsigned int)(v608 - v607) >> 31));
      v606[v693] = v710;
      int * v610 = v577->cache_age;
      int v611 = v610[v694];
      int v712 = v611 + ((int)((unsigned int)(v611 - v607) >> 31));
      v610[v694] = v712;
      int * v613 = v577->cache_age;
      v613[v709] = 0;
      v659 = v709;
    } else {
      int * v616 = v577->cache_age;
      int v716 = 4 + ((((int)((unsigned int)((int)((unsigned int)v581 >> 2)) >> 1)) & 3) * 2);
      int v617 = v616[v716];
      int * v618 = v577->cache_tags;
      int v619 = v618[v716];
      int v620 = v616[v694];
      int v621 = v618[v694];
      int * v622 = v577->cache_dirty;
      int v719 = (4 + ((((int)((unsigned int)((int)((unsigned int)v581 >> 2)) >> 1)) & 3) * 2)) + ((((v617 + ((~(((v619 ^ -1) | (-(v619 ^ -1))) >> 31)) & 2)) - (v620 + ((~(((v621 ^ -1) | (-(v621 ^ -1))) >> 31)) & 2))) >> 31) & 1);
      int v623 = v622[v719];
      bool v720 = !(v623 == 0);
      if (v720) {
        int * v624 = v577->cache_tags;
        int v625 = v624[v719];
        int * v626 = v577->cache_vals;
        int v723 = ((4 + ((((int)((unsigned int)((int)((unsigned int)v581 >> 2)) >> 1)) & 3) * 2)) + ((((v617 + ((~(((v619 ^ -1) | (-(v619 ^ -1))) >> 31)) & 2)) - (v620 + ((~(((v621 ^ -1) | (-(v621 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
        int v627 = v626[v723];
        int v724 = (((4 + ((((int)((unsigned int)((int)((unsigned int)v581 >> 2)) >> 1)) & 3) * 2)) + ((((v617 + ((~(((v619 ^ -1) | (-(v619 ^ -1))) >> 31)) & 2)) - (v620 + ((~(((v621 ^ -1) | (-(v621 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
        int v628 = v626[v724];
        int * v629 = v577->mem;
        int v726 = v625 * 2;
        v629[v726] = v627;
        int * v631 = v577->mem;
        int v729 = (v625 * 2) + 1;
        v631[v729] = v628;
        ;
      } else {
        ;
      }
      int * v636 = v577->mem;
      int v734 = ((int)((unsigned int)((int)((unsigned int)v581 >> 2)) >> 1)) * 2;
      int v637 = v636[v734];
      int v735 = (((int)((unsigned int)((int)((unsigned int)v581 >> 2)) >> 1)) * 2) + 1;
      int v638 = v636[v735];
      int * v639 = v577->cache_vals;
      int v737 = ((4 + ((((int)((unsigned int)((int)((unsigned int)v581 >> 2)) >> 1)) & 3) * 2)) + ((((v617 + ((~(((v619 ^ -1) | (-(v619 ^ -1))) >> 31)) & 2)) - (v620 + ((~(((v621 ^ -1) | (-(v621 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
      v639[v737] = v637;
      int * v641 = v577->cache_vals;
      int v740 = (((4 + ((((int)((unsigned int)((int)((unsigned int)v581 >> 2)) >> 1)) & 3) * 2)) + ((((v617 + ((~(((v619 ^ -1) | (-(v619 ^ -1))) >> 31)) & 2)) - (v620 + ((~(((v621 ^ -1) | (-(v621 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
      v641[v740] = v638;
      int * v643 = v577->cache_tags;
      int v743 = (int)((unsigned int)((int)((unsigned int)v581 >> 2)) >> 1);
      v643[v719] = v743;
      int * v645 = v577->cache_dirty;
      v645[v719] = 0;
      int * v647 = v577->cache_age;
      v647[v719] = 1;
      int * v649 = v577->cache_age;
      int v650 = v649[v719];
      int v651 = v649[v693];
      int v749 = v651 + ((int)((unsigned int)(v651 - v650) >> 31));
      v649[v693] = v749;
      int * v653 = v577->cache_age;
      int v654 = v653[v694];
      int v751 = v654 + ((int)((unsigned int)(v654 - v650) >> 31));
      v653[v694] = v751;
      int * v656 = v577->cache_age;
      v656[v719] = 0;
      v659 = v719;
    }
    int * v660 = v577->cache_vals;
    int v754 = v659 * 2;
    int v661 = v660[v754];
    int v755 = (v659 * 2) + 1;
    int v662 = v660[v755];
    int v756 = (((((int)((unsigned int)((int)((unsigned int)v581 >> 2)) >> 1)) & 1) * 2) + ((((v601 + ((~(((v603 ^ -1) | (-(v603 ^ -1))) >> 31)) & 2)) - (v604 + ((~(((v605 ^ -1) | (-(v605 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
    v660[v756] = v661;
    int * v664 = v577->cache_vals;
    int v759 = ((((((int)((unsigned int)((int)((unsigned int)v581 >> 2)) >> 1)) & 1) * 2) + ((((v601 + ((~(((v603 ^ -1) | (-(v603 ^ -1))) >> 31)) & 2)) - (v604 + ((~(((v605 ^ -1) | (-(v605 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
    v664[v759] = v662;
    int * v666 = v577->cache_tags;
    int v762 = ((((int)((unsigned int)((int)((unsigned int)v581 >> 2)) >> 1)) & 1) * 2) + ((((v601 + ((~(((v603 ^ -1) | (-(v603 ^ -1))) >> 31)) & 2)) - (v604 + ((~(((v605 ^ -1) | (-(v605 ^ -1))) >> 31)) & 2))) >> 31) & 1);
    int v763 = (int)((unsigned int)((int)((unsigned int)v581 >> 2)) >> 1);
    v666[v762] = v763;
    int * v668 = v577->cache_dirty;
    v668[v762] = 0;
    int * v670 = v577->cache_age;
    v670[v762] = 1;
    int * v672 = v577->cache_age;
    int v673 = v672[v762];
    int v674 = v672[v691];
    int v769 = v674 + ((int)((unsigned int)(v674 - v673) >> 31));
    v672[v691] = v769;
    int * v676 = v577->cache_age;
    int v677 = v676[v692];
    int v771 = v677 + ((int)((unsigned int)(v677 - v673) >> 31));
    v676[v692] = v771;
    int * v679 = v577->cache_age;
    v679[v762] = 0;
    v682 = v762;
  }
  int v774 = (v682 * 2) + (((int)((unsigned int)v581 >> 2)) & 1);
  int v683 = v589[v774];
  int * v684 = v577->regs;
  v684[12] = v683;
  return v577;
}

struct StateT * slot_5(struct StateT * v563) {
  int v564 = v563->timer;
  int v571 = v564 + 1;
  v563->timer = v571;
  int * v566 = v563->regs;
  int v567 = v566[11];
  int v574 = v567 << 2;
  v566[11] = v574;
  struct StateT * v569 = slot_6(v563);
  return v569;
}

struct StateT * slot_4(struct StateT * v359) {
  int v360 = v359->timer;
  int v470 = v360 + 1;
  v359->timer = v470;
  int * v362 = v359->regs;
  int v363 = v362[6];
  int * v364 = v359->cache_tags;
  int v474 = (((int)((unsigned int)((int)((unsigned int)v363 >> 2)) >> 1)) & 1) * 2;
  int v365 = v364[v474];
  int v475 = ((((int)((unsigned int)((int)((unsigned int)v363 >> 2)) >> 1)) & 1) * 2) + 1;
  int v366 = v364[v475];
  int v476 = 4 + ((((int)((unsigned int)((int)((unsigned int)v363 >> 2)) >> 1)) & 3) * 2);
  int v367 = v364[v476];
  int v477 = (4 + ((((int)((unsigned int)((int)((unsigned int)v363 >> 2)) >> 1)) & 3) * 2)) + 1;
  int v368 = v364[v477];
  int v369 = v359->timer;
  int v478 = v369 + ((100 ^ (((~(((v367 ^ ((int)((unsigned int)((int)((unsigned int)v363 >> 2)) >> 1))) | (-(v367 ^ ((int)((unsigned int)((int)((unsigned int)v363 >> 2)) >> 1))))) >> 31)) | (~(((v368 ^ ((int)((unsigned int)((int)((unsigned int)v363 >> 2)) >> 1))) | (-(v368 ^ ((int)((unsigned int)((int)((unsigned int)v363 >> 2)) >> 1))))) >> 31))) & 104)) ^ (((~(((v365 ^ ((int)((unsigned int)((int)((unsigned int)v363 >> 2)) >> 1))) | (-(v365 ^ ((int)((unsigned int)((int)((unsigned int)v363 >> 2)) >> 1))))) >> 31)) | (~(((v366 ^ ((int)((unsigned int)((int)((unsigned int)v363 >> 2)) >> 1))) | (-(v366 ^ ((int)((unsigned int)((int)((unsigned int)v363 >> 2)) >> 1))))) >> 31))) & (1 ^ (100 ^ (((~(((v367 ^ ((int)((unsigned int)((int)((unsigned int)v363 >> 2)) >> 1))) | (-(v367 ^ ((int)((unsigned int)((int)((unsigned int)v363 >> 2)) >> 1))))) >> 31)) | (~(((v368 ^ ((int)((unsigned int)((int)((unsigned int)v363 >> 2)) >> 1))) | (-(v368 ^ ((int)((unsigned int)((int)((unsigned int)v363 >> 2)) >> 1))))) >> 31))) & 104)))));
  v359->timer = v478;
  int * v371 = v359->cache_vals;
  bool v479 = !(((~(((v365 ^ ((int)((unsigned int)((int)((unsigned int)v363 >> 2)) >> 1))) | (-(v365 ^ ((int)((unsigned int)((int)((unsigned int)v363 >> 2)) >> 1))))) >> 31)) | (~(((v366 ^ ((int)((unsigned int)((int)((unsigned int)v363 >> 2)) >> 1))) | (-(v366 ^ ((int)((unsigned int)((int)((unsigned int)v363 >> 2)) >> 1))))) >> 31))) == 0);
  int v464;
  if (v479) {
    int * v372 = v359->cache_age;
    int v481 = ((((int)((unsigned int)((int)((unsigned int)v363 >> 2)) >> 1)) & 1) * 2) + ((~(((v366 ^ ((int)((unsigned int)((int)((unsigned int)v363 >> 2)) >> 1))) | (-(v366 ^ ((int)((unsigned int)((int)((unsigned int)v363 >> 2)) >> 1))))) >> 31)) & 1);
    int v373 = v372[v481];
    int v374 = v372[v474];
    int v482 = v374 + ((int)((unsigned int)(v374 - v373) >> 31));
    v372[v474] = v482;
    int * v376 = v359->cache_age;
    int v377 = v376[v475];
    int v484 = v377 + ((int)((unsigned int)(v377 - v373) >> 31));
    v376[v475] = v484;
    int * v379 = v359->cache_age;
    v379[v481] = 0;
    v464 = v481;
  } else {
    int * v382 = v359->cache_age;
    int v488 = (((int)((unsigned int)((int)((unsigned int)v363 >> 2)) >> 1)) & 1) * 2;
    int v383 = v382[v488];
    int * v384 = v359->cache_tags;
    int v385 = v384[v488];
    int v386 = v382[v475];
    int v387 = v384[v475];
    bool v490 = !(((~(((v367 ^ ((int)((unsigned int)((int)((unsigned int)v363 >> 2)) >> 1))) | (-(v367 ^ ((int)((unsigned int)((int)((unsigned int)v363 >> 2)) >> 1))))) >> 31)) | (~(((v368 ^ ((int)((unsigned int)((int)((unsigned int)v363 >> 2)) >> 1))) | (-(v368 ^ ((int)((unsigned int)((int)((unsigned int)v363 >> 2)) >> 1))))) >> 31))) == 0);
    int v441;
    if (v490) {
      int * v388 = v359->cache_age;
      int v492 = (4 + ((((int)((unsigned int)((int)((unsigned int)v363 >> 2)) >> 1)) & 3) * 2)) + ((~(((v368 ^ ((int)((unsigned int)((int)((unsigned int)v363 >> 2)) >> 1))) | (-(v368 ^ ((int)((unsigned int)((int)((unsigned int)v363 >> 2)) >> 1))))) >> 31)) & 1);
      int v389 = v388[v492];
      int v390 = v388[v476];
      int v493 = v390 + ((int)((unsigned int)(v390 - v389) >> 31));
      v388[v476] = v493;
      int * v392 = v359->cache_age;
      int v393 = v392[v477];
      int v495 = v393 + ((int)((unsigned int)(v393 - v389) >> 31));
      v392[v477] = v495;
      int * v395 = v359->cache_age;
      v395[v492] = 0;
      v441 = v492;
    } else {
      int * v398 = v359->cache_age;
      int v499 = 4 + ((((int)((unsigned int)((int)((unsigned int)v363 >> 2)) >> 1)) & 3) * 2);
      int v399 = v398[v499];
      int * v400 = v359->cache_tags;
      int v401 = v400[v499];
      int v402 = v398[v477];
      int v403 = v400[v477];
      int * v404 = v359->cache_dirty;
      int v502 = (4 + ((((int)((unsigned int)((int)((unsigned int)v363 >> 2)) >> 1)) & 3) * 2)) + ((((v399 + ((~(((v401 ^ -1) | (-(v401 ^ -1))) >> 31)) & 2)) - (v402 + ((~(((v403 ^ -1) | (-(v403 ^ -1))) >> 31)) & 2))) >> 31) & 1);
      int v405 = v404[v502];
      bool v503 = !(v405 == 0);
      if (v503) {
        int * v406 = v359->cache_tags;
        int v407 = v406[v502];
        int * v408 = v359->cache_vals;
        int v506 = ((4 + ((((int)((unsigned int)((int)((unsigned int)v363 >> 2)) >> 1)) & 3) * 2)) + ((((v399 + ((~(((v401 ^ -1) | (-(v401 ^ -1))) >> 31)) & 2)) - (v402 + ((~(((v403 ^ -1) | (-(v403 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
        int v409 = v408[v506];
        int v507 = (((4 + ((((int)((unsigned int)((int)((unsigned int)v363 >> 2)) >> 1)) & 3) * 2)) + ((((v399 + ((~(((v401 ^ -1) | (-(v401 ^ -1))) >> 31)) & 2)) - (v402 + ((~(((v403 ^ -1) | (-(v403 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
        int v410 = v408[v507];
        int * v411 = v359->mem;
        int v509 = v407 * 2;
        v411[v509] = v409;
        int * v413 = v359->mem;
        int v512 = (v407 * 2) + 1;
        v413[v512] = v410;
        ;
      } else {
        ;
      }
      int * v418 = v359->mem;
      int v517 = ((int)((unsigned int)((int)((unsigned int)v363 >> 2)) >> 1)) * 2;
      int v419 = v418[v517];
      int v518 = (((int)((unsigned int)((int)((unsigned int)v363 >> 2)) >> 1)) * 2) + 1;
      int v420 = v418[v518];
      int * v421 = v359->cache_vals;
      int v520 = ((4 + ((((int)((unsigned int)((int)((unsigned int)v363 >> 2)) >> 1)) & 3) * 2)) + ((((v399 + ((~(((v401 ^ -1) | (-(v401 ^ -1))) >> 31)) & 2)) - (v402 + ((~(((v403 ^ -1) | (-(v403 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
      v421[v520] = v419;
      int * v423 = v359->cache_vals;
      int v523 = (((4 + ((((int)((unsigned int)((int)((unsigned int)v363 >> 2)) >> 1)) & 3) * 2)) + ((((v399 + ((~(((v401 ^ -1) | (-(v401 ^ -1))) >> 31)) & 2)) - (v402 + ((~(((v403 ^ -1) | (-(v403 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
      v423[v523] = v420;
      int * v425 = v359->cache_tags;
      int v526 = (int)((unsigned int)((int)((unsigned int)v363 >> 2)) >> 1);
      v425[v502] = v526;
      int * v427 = v359->cache_dirty;
      v427[v502] = 0;
      int * v429 = v359->cache_age;
      v429[v502] = 1;
      int * v431 = v359->cache_age;
      int v432 = v431[v502];
      int v433 = v431[v476];
      int v532 = v433 + ((int)((unsigned int)(v433 - v432) >> 31));
      v431[v476] = v532;
      int * v435 = v359->cache_age;
      int v436 = v435[v477];
      int v534 = v436 + ((int)((unsigned int)(v436 - v432) >> 31));
      v435[v477] = v534;
      int * v438 = v359->cache_age;
      v438[v502] = 0;
      v441 = v502;
    }
    int * v442 = v359->cache_vals;
    int v537 = v441 * 2;
    int v443 = v442[v537];
    int v538 = (v441 * 2) + 1;
    int v444 = v442[v538];
    int v539 = (((((int)((unsigned int)((int)((unsigned int)v363 >> 2)) >> 1)) & 1) * 2) + ((((v383 + ((~(((v385 ^ -1) | (-(v385 ^ -1))) >> 31)) & 2)) - (v386 + ((~(((v387 ^ -1) | (-(v387 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
    v442[v539] = v443;
    int * v446 = v359->cache_vals;
    int v542 = ((((((int)((unsigned int)((int)((unsigned int)v363 >> 2)) >> 1)) & 1) * 2) + ((((v383 + ((~(((v385 ^ -1) | (-(v385 ^ -1))) >> 31)) & 2)) - (v386 + ((~(((v387 ^ -1) | (-(v387 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
    v446[v542] = v444;
    int * v448 = v359->cache_tags;
    int v545 = ((((int)((unsigned int)((int)((unsigned int)v363 >> 2)) >> 1)) & 1) * 2) + ((((v383 + ((~(((v385 ^ -1) | (-(v385 ^ -1))) >> 31)) & 2)) - (v386 + ((~(((v387 ^ -1) | (-(v387 ^ -1))) >> 31)) & 2))) >> 31) & 1);
    int v546 = (int)((unsigned int)((int)((unsigned int)v363 >> 2)) >> 1);
    v448[v545] = v546;
    int * v450 = v359->cache_dirty;
    v450[v545] = 0;
    int * v452 = v359->cache_age;
    v452[v545] = 1;
    int * v454 = v359->cache_age;
    int v455 = v454[v545];
    int v456 = v454[v474];
    int v552 = v456 + ((int)((unsigned int)(v456 - v455) >> 31));
    v454[v474] = v552;
    int * v458 = v359->cache_age;
    int v459 = v458[v475];
    int v554 = v459 + ((int)((unsigned int)(v459 - v455) >> 31));
    v458[v475] = v554;
    int * v461 = v359->cache_age;
    v461[v545] = 0;
    v464 = v545;
  }
  int v557 = (v464 * 2) + (((int)((unsigned int)v363 >> 2)) & 1);
  int v465 = v371[v557];
  int * v466 = v359->regs;
  v466[11] = v465;
  struct StateT * v468 = slot_5(v359);
  return v468;
}

struct StateT * slot_2(struct StateT * v31) {
  int v32 = v31->timer;
  int v38 = v32 + 1;
  v31->timer = v38;
  int * v34 = v31->regs;
  v34[7] = 0;
  struct StateT * v36 = slot_3(v31);
  return v36;
}

struct StateT * slot_3(struct StateT * v44) {
  int v45 = v44->timer;
  int v215 = v45 + 1;
  v44->timer = v215;
  int * v47 = v44->regs;
  int v48 = v47[6];
  int v49 = v47[7];
  int * v50 = v44->cache_tags;
  int v220 = (((int)((unsigned int)((int)((unsigned int)v48 >> 2)) >> 1)) & 1) * 2;
  int v51 = v50[v220];
  int v221 = ((((int)((unsigned int)((int)((unsigned int)v48 >> 2)) >> 1)) & 1) * 2) + 1;
  int v52 = v50[v221];
  int v222 = 4 + ((((int)((unsigned int)((int)((unsigned int)v48 >> 2)) >> 1)) & 3) * 2);
  int v53 = v50[v222];
  int v223 = (4 + ((((int)((unsigned int)((int)((unsigned int)v48 >> 2)) >> 1)) & 3) * 2)) + 1;
  int v54 = v50[v223];
  int v55 = v44->timer;
  int v224 = v55 + ((100 ^ (((~(((v53 ^ ((int)((unsigned int)((int)((unsigned int)v48 >> 2)) >> 1))) | (-(v53 ^ ((int)((unsigned int)((int)((unsigned int)v48 >> 2)) >> 1))))) >> 31)) | (~(((v54 ^ ((int)((unsigned int)((int)((unsigned int)v48 >> 2)) >> 1))) | (-(v54 ^ ((int)((unsigned int)((int)((unsigned int)v48 >> 2)) >> 1))))) >> 31))) & 104)) ^ (((~(((v51 ^ ((int)((unsigned int)((int)((unsigned int)v48 >> 2)) >> 1))) | (-(v51 ^ ((int)((unsigned int)((int)((unsigned int)v48 >> 2)) >> 1))))) >> 31)) | (~(((v52 ^ ((int)((unsigned int)((int)((unsigned int)v48 >> 2)) >> 1))) | (-(v52 ^ ((int)((unsigned int)((int)((unsigned int)v48 >> 2)) >> 1))))) >> 31))) & (1 ^ (100 ^ (((~(((v53 ^ ((int)((unsigned int)((int)((unsigned int)v48 >> 2)) >> 1))) | (-(v53 ^ ((int)((unsigned int)((int)((unsigned int)v48 >> 2)) >> 1))))) >> 31)) | (~(((v54 ^ ((int)((unsigned int)((int)((unsigned int)v48 >> 2)) >> 1))) | (-(v54 ^ ((int)((unsigned int)((int)((unsigned int)v48 >> 2)) >> 1))))) >> 31))) & 104)))));
  v44->timer = v224;
  bool v225 = !(((~(((v51 ^ ((int)((unsigned int)((int)((unsigned int)v48 >> 2)) >> 1))) | (-(v51 ^ ((int)((unsigned int)((int)((unsigned int)v48 >> 2)) >> 1))))) >> 31)) | (~(((v52 ^ ((int)((unsigned int)((int)((unsigned int)v48 >> 2)) >> 1))) | (-(v52 ^ ((int)((unsigned int)((int)((unsigned int)v48 >> 2)) >> 1))))) >> 31))) == 0);
  int v149;
  if (v225) {
    int * v57 = v44->cache_age;
    int v227 = ((((int)((unsigned int)((int)((unsigned int)v48 >> 2)) >> 1)) & 1) * 2) + ((~(((v52 ^ ((int)((unsigned int)((int)((unsigned int)v48 >> 2)) >> 1))) | (-(v52 ^ ((int)((unsigned int)((int)((unsigned int)v48 >> 2)) >> 1))))) >> 31)) & 1);
    int v58 = v57[v227];
    int v59 = v57[v220];
    int v228 = v59 + ((int)((unsigned int)(v59 - v58) >> 31));
    v57[v220] = v228;
    int * v61 = v44->cache_age;
    int v62 = v61[v221];
    int v230 = v62 + ((int)((unsigned int)(v62 - v58) >> 31));
    v61[v221] = v230;
    int * v64 = v44->cache_age;
    v64[v227] = 0;
    v149 = v227;
  } else {
    int * v67 = v44->cache_age;
    int v234 = (((int)((unsigned int)((int)((unsigned int)v48 >> 2)) >> 1)) & 1) * 2;
    int v68 = v67[v234];
    int * v69 = v44->cache_tags;
    int v70 = v69[v234];
    int v71 = v67[v221];
    int v72 = v69[v221];
    bool v236 = !(((~(((v53 ^ ((int)((unsigned int)((int)((unsigned int)v48 >> 2)) >> 1))) | (-(v53 ^ ((int)((unsigned int)((int)((unsigned int)v48 >> 2)) >> 1))))) >> 31)) | (~(((v54 ^ ((int)((unsigned int)((int)((unsigned int)v48 >> 2)) >> 1))) | (-(v54 ^ ((int)((unsigned int)((int)((unsigned int)v48 >> 2)) >> 1))))) >> 31))) == 0);
    int v126;
    if (v236) {
      int * v73 = v44->cache_age;
      int v238 = (4 + ((((int)((unsigned int)((int)((unsigned int)v48 >> 2)) >> 1)) & 3) * 2)) + ((~(((v54 ^ ((int)((unsigned int)((int)((unsigned int)v48 >> 2)) >> 1))) | (-(v54 ^ ((int)((unsigned int)((int)((unsigned int)v48 >> 2)) >> 1))))) >> 31)) & 1);
      int v74 = v73[v238];
      int v75 = v73[v222];
      int v239 = v75 + ((int)((unsigned int)(v75 - v74) >> 31));
      v73[v222] = v239;
      int * v77 = v44->cache_age;
      int v78 = v77[v223];
      int v241 = v78 + ((int)((unsigned int)(v78 - v74) >> 31));
      v77[v223] = v241;
      int * v80 = v44->cache_age;
      v80[v238] = 0;
      v126 = v238;
    } else {
      int * v83 = v44->cache_age;
      int v245 = 4 + ((((int)((unsigned int)((int)((unsigned int)v48 >> 2)) >> 1)) & 3) * 2);
      int v84 = v83[v245];
      int * v85 = v44->cache_tags;
      int v86 = v85[v245];
      int v87 = v83[v223];
      int v88 = v85[v223];
      int * v89 = v44->cache_dirty;
      int v248 = (4 + ((((int)((unsigned int)((int)((unsigned int)v48 >> 2)) >> 1)) & 3) * 2)) + ((((v84 + ((~(((v86 ^ -1) | (-(v86 ^ -1))) >> 31)) & 2)) - (v87 + ((~(((v88 ^ -1) | (-(v88 ^ -1))) >> 31)) & 2))) >> 31) & 1);
      int v90 = v89[v248];
      bool v249 = !(v90 == 0);
      if (v249) {
        int * v91 = v44->cache_tags;
        int v92 = v91[v248];
        int * v93 = v44->cache_vals;
        int v252 = ((4 + ((((int)((unsigned int)((int)((unsigned int)v48 >> 2)) >> 1)) & 3) * 2)) + ((((v84 + ((~(((v86 ^ -1) | (-(v86 ^ -1))) >> 31)) & 2)) - (v87 + ((~(((v88 ^ -1) | (-(v88 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
        int v94 = v93[v252];
        int v253 = (((4 + ((((int)((unsigned int)((int)((unsigned int)v48 >> 2)) >> 1)) & 3) * 2)) + ((((v84 + ((~(((v86 ^ -1) | (-(v86 ^ -1))) >> 31)) & 2)) - (v87 + ((~(((v88 ^ -1) | (-(v88 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
        int v95 = v93[v253];
        int * v96 = v44->mem;
        int v255 = v92 * 2;
        v96[v255] = v94;
        int * v98 = v44->mem;
        int v258 = (v92 * 2) + 1;
        v98[v258] = v95;
        ;
      } else {
        ;
      }
      int * v103 = v44->mem;
      int v263 = ((int)((unsigned int)((int)((unsigned int)v48 >> 2)) >> 1)) * 2;
      int v104 = v103[v263];
      int v264 = (((int)((unsigned int)((int)((unsigned int)v48 >> 2)) >> 1)) * 2) + 1;
      int v105 = v103[v264];
      int * v106 = v44->cache_vals;
      int v266 = ((4 + ((((int)((unsigned int)((int)((unsigned int)v48 >> 2)) >> 1)) & 3) * 2)) + ((((v84 + ((~(((v86 ^ -1) | (-(v86 ^ -1))) >> 31)) & 2)) - (v87 + ((~(((v88 ^ -1) | (-(v88 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
      v106[v266] = v104;
      int * v108 = v44->cache_vals;
      int v269 = (((4 + ((((int)((unsigned int)((int)((unsigned int)v48 >> 2)) >> 1)) & 3) * 2)) + ((((v84 + ((~(((v86 ^ -1) | (-(v86 ^ -1))) >> 31)) & 2)) - (v87 + ((~(((v88 ^ -1) | (-(v88 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
      v108[v269] = v105;
      int * v110 = v44->cache_tags;
      int v272 = (int)((unsigned int)((int)((unsigned int)v48 >> 2)) >> 1);
      v110[v248] = v272;
      int * v112 = v44->cache_dirty;
      v112[v248] = 0;
      int * v114 = v44->cache_age;
      v114[v248] = 1;
      int * v116 = v44->cache_age;
      int v117 = v116[v248];
      int v118 = v116[v222];
      int v278 = v118 + ((int)((unsigned int)(v118 - v117) >> 31));
      v116[v222] = v278;
      int * v120 = v44->cache_age;
      int v121 = v120[v223];
      int v280 = v121 + ((int)((unsigned int)(v121 - v117) >> 31));
      v120[v223] = v280;
      int * v123 = v44->cache_age;
      v123[v248] = 0;
      v126 = v248;
    }
    int * v127 = v44->cache_vals;
    int v283 = v126 * 2;
    int v128 = v127[v283];
    int v284 = (v126 * 2) + 1;
    int v129 = v127[v284];
    int v285 = (((((int)((unsigned int)((int)((unsigned int)v48 >> 2)) >> 1)) & 1) * 2) + ((((v68 + ((~(((v70 ^ -1) | (-(v70 ^ -1))) >> 31)) & 2)) - (v71 + ((~(((v72 ^ -1) | (-(v72 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
    v127[v285] = v128;
    int * v131 = v44->cache_vals;
    int v288 = ((((((int)((unsigned int)((int)((unsigned int)v48 >> 2)) >> 1)) & 1) * 2) + ((((v68 + ((~(((v70 ^ -1) | (-(v70 ^ -1))) >> 31)) & 2)) - (v71 + ((~(((v72 ^ -1) | (-(v72 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
    v131[v288] = v129;
    int * v133 = v44->cache_tags;
    int v291 = ((((int)((unsigned int)((int)((unsigned int)v48 >> 2)) >> 1)) & 1) * 2) + ((((v68 + ((~(((v70 ^ -1) | (-(v70 ^ -1))) >> 31)) & 2)) - (v71 + ((~(((v72 ^ -1) | (-(v72 ^ -1))) >> 31)) & 2))) >> 31) & 1);
    int v292 = (int)((unsigned int)((int)((unsigned int)v48 >> 2)) >> 1);
    v133[v291] = v292;
    int * v135 = v44->cache_dirty;
    v135[v291] = 0;
    int * v137 = v44->cache_age;
    v137[v291] = 1;
    int * v139 = v44->cache_age;
    int v140 = v139[v291];
    int v141 = v139[v220];
    int v298 = v141 + ((int)((unsigned int)(v141 - v140) >> 31));
    v139[v220] = v298;
    int * v143 = v44->cache_age;
    int v144 = v143[v221];
    int v300 = v144 + ((int)((unsigned int)(v144 - v140) >> 31));
    v143[v221] = v300;
    int * v146 = v44->cache_age;
    v146[v291] = 0;
    v149 = v291;
  }
  int * v150 = v44->cache_vals;
  int v303 = (v149 * 2) + (((int)((unsigned int)v48 >> 2)) & 1);
  v150[v303] = v49;
  int * v152 = v44->cache_tags;
  int v153 = v152[v222];
  int v154 = v152[v223];
  bool v306 = !(((~(((v153 ^ ((int)((unsigned int)((int)((unsigned int)v48 >> 2)) >> 1))) | (-(v153 ^ ((int)((unsigned int)((int)((unsigned int)v48 >> 2)) >> 1))))) >> 31)) | (~(((v154 ^ ((int)((unsigned int)((int)((unsigned int)v48 >> 2)) >> 1))) | (-(v154 ^ ((int)((unsigned int)((int)((unsigned int)v48 >> 2)) >> 1))))) >> 31))) == 0);
  int v208;
  if (v306) {
    int * v155 = v44->cache_age;
    int v308 = (4 + ((((int)((unsigned int)((int)((unsigned int)v48 >> 2)) >> 1)) & 3) * 2)) + ((~(((v154 ^ ((int)((unsigned int)((int)((unsigned int)v48 >> 2)) >> 1))) | (-(v154 ^ ((int)((unsigned int)((int)((unsigned int)v48 >> 2)) >> 1))))) >> 31)) & 1);
    int v156 = v155[v308];
    int v157 = v155[v222];
    int v309 = v157 + ((int)((unsigned int)(v157 - v156) >> 31));
    v155[v222] = v309;
    int * v159 = v44->cache_age;
    int v160 = v159[v223];
    int v311 = v160 + ((int)((unsigned int)(v160 - v156) >> 31));
    v159[v223] = v311;
    int * v162 = v44->cache_age;
    v162[v308] = 0;
    v208 = v308;
  } else {
    int * v165 = v44->cache_age;
    int v315 = 4 + ((((int)((unsigned int)((int)((unsigned int)v48 >> 2)) >> 1)) & 3) * 2);
    int v166 = v165[v315];
    int * v167 = v44->cache_tags;
    int v168 = v167[v315];
    int v169 = v165[v223];
    int v170 = v167[v223];
    int * v171 = v44->cache_dirty;
    int v318 = (4 + ((((int)((unsigned int)((int)((unsigned int)v48 >> 2)) >> 1)) & 3) * 2)) + ((((v166 + ((~(((v168 ^ -1) | (-(v168 ^ -1))) >> 31)) & 2)) - (v169 + ((~(((v170 ^ -1) | (-(v170 ^ -1))) >> 31)) & 2))) >> 31) & 1);
    int v172 = v171[v318];
    bool v319 = !(v172 == 0);
    if (v319) {
      int * v173 = v44->cache_tags;
      int v174 = v173[v318];
      int * v175 = v44->cache_vals;
      int v322 = ((4 + ((((int)((unsigned int)((int)((unsigned int)v48 >> 2)) >> 1)) & 3) * 2)) + ((((v166 + ((~(((v168 ^ -1) | (-(v168 ^ -1))) >> 31)) & 2)) - (v169 + ((~(((v170 ^ -1) | (-(v170 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
      int v176 = v175[v322];
      int v323 = (((4 + ((((int)((unsigned int)((int)((unsigned int)v48 >> 2)) >> 1)) & 3) * 2)) + ((((v166 + ((~(((v168 ^ -1) | (-(v168 ^ -1))) >> 31)) & 2)) - (v169 + ((~(((v170 ^ -1) | (-(v170 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
      int v177 = v175[v323];
      int * v178 = v44->mem;
      int v325 = v174 * 2;
      v178[v325] = v176;
      int * v180 = v44->mem;
      int v328 = (v174 * 2) + 1;
      v180[v328] = v177;
      ;
    } else {
      ;
    }
    int * v185 = v44->mem;
    int v333 = ((int)((unsigned int)((int)((unsigned int)v48 >> 2)) >> 1)) * 2;
    int v186 = v185[v333];
    int v334 = (((int)((unsigned int)((int)((unsigned int)v48 >> 2)) >> 1)) * 2) + 1;
    int v187 = v185[v334];
    int * v188 = v44->cache_vals;
    int v336 = ((4 + ((((int)((unsigned int)((int)((unsigned int)v48 >> 2)) >> 1)) & 3) * 2)) + ((((v166 + ((~(((v168 ^ -1) | (-(v168 ^ -1))) >> 31)) & 2)) - (v169 + ((~(((v170 ^ -1) | (-(v170 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
    v188[v336] = v186;
    int * v190 = v44->cache_vals;
    int v339 = (((4 + ((((int)((unsigned int)((int)((unsigned int)v48 >> 2)) >> 1)) & 3) * 2)) + ((((v166 + ((~(((v168 ^ -1) | (-(v168 ^ -1))) >> 31)) & 2)) - (v169 + ((~(((v170 ^ -1) | (-(v170 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
    v190[v339] = v187;
    int * v192 = v44->cache_tags;
    int v342 = (int)((unsigned int)((int)((unsigned int)v48 >> 2)) >> 1);
    v192[v318] = v342;
    int * v194 = v44->cache_dirty;
    v194[v318] = 0;
    int * v196 = v44->cache_age;
    v196[v318] = 1;
    int * v198 = v44->cache_age;
    int v199 = v198[v318];
    int v200 = v198[v222];
    int v348 = v200 + ((int)((unsigned int)(v200 - v199) >> 31));
    v198[v222] = v348;
    int * v202 = v44->cache_age;
    int v203 = v202[v223];
    int v350 = v203 + ((int)((unsigned int)(v203 - v199) >> 31));
    v202[v223] = v350;
    int * v205 = v44->cache_age;
    v205[v318] = 0;
    v208 = v318;
  }
  int * v209 = v44->cache_vals;
  int v353 = (v208 * 2) + (((int)((unsigned int)v48 >> 2)) & 1);
  v209[v353] = v49;
  int * v211 = v44->cache_dirty;
  v211[v208] = 1;
  struct StateT * v213 = slot_4(v44);
  return v213;
}

struct StateT * slot_0(struct StateT * v2) {
  int v3 = v2->timer;
  int v10 = v3 + 1;
  v2->timer = v10;
  int * v5 = v2->regs;
  int v6 = v5[10];
  int v14 = v6 & 28;
  v5[6] = v14;
  struct StateT * v8 = slot_1(v2);
  return v8;
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