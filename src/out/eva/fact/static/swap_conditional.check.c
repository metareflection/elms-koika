// verify: clean (Eva should report untainted_timer: Valid) [unroll 65]
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

struct StateT * slot_12(struct StateT * v586);
struct StateT * slot_43(struct StateT * v3441);
struct StateT * slot_6(struct StateT * v94);
struct StateT * slot_47(struct StateT * v3881);
struct StateT * slot_29(struct StateT * v2247);
struct StateT * slot_16(struct StateT * v1040);
struct StateT * slot_5(struct StateT * v80);
struct StateT * slot_7(struct StateT * v102);
struct StateT * slot_31(struct StateT * v2279);
struct StateT * slot_26(struct StateT * v2011);
struct StateT * slot_10(struct StateT * v164);
struct StateT * slot_19(struct StateT * v1088);
struct StateT * slot_14(struct StateT * v1008);
struct StateT * slot_44(struct StateT * v3645);
struct StateT * slot_28(struct StateT * v2231);
struct StateT * slot_32(struct StateT * v2295);
struct StateT * slot_17(struct StateT * v1056);
struct StateT * slot_49(struct StateT * v3913);
struct StateT * slot_33(struct StateT * v2311);
struct StateT * slot_50(struct StateT * v3929);
struct StateT * slot_36(struct StateT * v2955);
struct StateT * slot_37(struct StateT * v2963);
struct StateT * slot_40(struct StateT * v3017);
struct StateT * slot_27(struct StateT * v2215);
struct StateT * slot_15(struct StateT * v1024);
struct StateT * slot_48(struct StateT * v3897);
struct StateT * slot_22(struct StateT * v1177);
struct StateT * slot_35(struct StateT * v2941);
struct StateT * slot_34(struct StateT * v2626);
struct StateT * slot_25(struct StateT * v1807);
struct StateT * slot_2(struct StateT * v29);
struct StateT * slot_21(struct StateT * v1172);
struct StateT * slot_3(struct StateT * v45);
struct StateT * slot_45(struct StateT * v3849);
struct StateT * slot_1(struct StateT * v15);
struct StateT * slot_13(struct StateT * v797);
struct StateT * slot_38(struct StateT * v2985);
struct StateT * slot_24(struct StateT * v1492);
struct StateT * slot_0(struct StateT * v2);
struct StateT * slot_42(struct StateT * v3237);
struct StateT * slot_46(struct StateT * v3865);
struct StateT * slot_20(struct StateT * v1104);
struct StateT * snippet(struct StateT * v0);
struct StateT * slot_41(struct StateT * v3033);
struct StateT * slot_39(struct StateT * v3000);
struct StateT * slot_8(struct StateT * v124);
struct StateT * slot_30(struct StateT * v2263);
struct StateT * slot_4(struct StateT * v58);
struct StateT * slot_18(struct StateT * v1072);
struct StateT * slot_9(struct StateT * v148);
struct StateT * slot_11(struct StateT * v375);
struct StateT * slot_12(struct StateT * v586) {
  int * v587 = v586->saved_regs;
  int * v588 = v586->regs;
  int v589 = v588[6];
  v587[6] = v589;
  int v591 = v586->timer;
  int v705 = v591 + 1;
  v586->timer = v705;
  int * v593 = v586->regs;
  int v594 = v593[15];
  int * v595 = v586->cache_tags;
  int v709 = (((int)((unsigned int)((int)((unsigned int)(v594 + 4) >> 2)) >> 1)) & 1) * 2;
  int v596 = v595[v709];
  int v710 = ((((int)((unsigned int)((int)((unsigned int)(v594 + 4) >> 2)) >> 1)) & 1) * 2) + 1;
  int v597 = v595[v710];
  int v711 = 4 + ((((int)((unsigned int)((int)((unsigned int)(v594 + 4) >> 2)) >> 1)) & 3) * 2);
  int v598 = v595[v711];
  int v712 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v594 + 4) >> 2)) >> 1)) & 3) * 2)) + 1;
  int v599 = v595[v712];
  int v600 = v586->timer;
  int v713 = v600 + ((100 ^ (((~(((v598 ^ ((int)((unsigned int)((int)((unsigned int)(v594 + 4) >> 2)) >> 1))) | (-(v598 ^ ((int)((unsigned int)((int)((unsigned int)(v594 + 4) >> 2)) >> 1))))) >> 31)) | (~(((v599 ^ ((int)((unsigned int)((int)((unsigned int)(v594 + 4) >> 2)) >> 1))) | (-(v599 ^ ((int)((unsigned int)((int)((unsigned int)(v594 + 4) >> 2)) >> 1))))) >> 31))) & 104)) ^ (((~(((v596 ^ ((int)((unsigned int)((int)((unsigned int)(v594 + 4) >> 2)) >> 1))) | (-(v596 ^ ((int)((unsigned int)((int)((unsigned int)(v594 + 4) >> 2)) >> 1))))) >> 31)) | (~(((v597 ^ ((int)((unsigned int)((int)((unsigned int)(v594 + 4) >> 2)) >> 1))) | (-(v597 ^ ((int)((unsigned int)((int)((unsigned int)(v594 + 4) >> 2)) >> 1))))) >> 31))) & (1 ^ (100 ^ (((~(((v598 ^ ((int)((unsigned int)((int)((unsigned int)(v594 + 4) >> 2)) >> 1))) | (-(v598 ^ ((int)((unsigned int)((int)((unsigned int)(v594 + 4) >> 2)) >> 1))))) >> 31)) | (~(((v599 ^ ((int)((unsigned int)((int)((unsigned int)(v594 + 4) >> 2)) >> 1))) | (-(v599 ^ ((int)((unsigned int)((int)((unsigned int)(v594 + 4) >> 2)) >> 1))))) >> 31))) & 104)))));
  v586->timer = v713;
  int * v602 = v586->cache_vals;
  bool v714 = !(((~(((v596 ^ ((int)((unsigned int)((int)((unsigned int)(v594 + 4) >> 2)) >> 1))) | (-(v596 ^ ((int)((unsigned int)((int)((unsigned int)(v594 + 4) >> 2)) >> 1))))) >> 31)) | (~(((v597 ^ ((int)((unsigned int)((int)((unsigned int)(v594 + 4) >> 2)) >> 1))) | (-(v597 ^ ((int)((unsigned int)((int)((unsigned int)(v594 + 4) >> 2)) >> 1))))) >> 31))) == 0);
  int v695;
  if (v714) {
    int * v603 = v586->cache_age;
    int v716 = ((((int)((unsigned int)((int)((unsigned int)(v594 + 4) >> 2)) >> 1)) & 1) * 2) + ((~(((v597 ^ ((int)((unsigned int)((int)((unsigned int)(v594 + 4) >> 2)) >> 1))) | (-(v597 ^ ((int)((unsigned int)((int)((unsigned int)(v594 + 4) >> 2)) >> 1))))) >> 31)) & 1);
    int v604 = v603[v716];
    int v605 = v603[v709];
    int v717 = v605 + ((int)((unsigned int)(v605 - v604) >> 31));
    v603[v709] = v717;
    int * v607 = v586->cache_age;
    int v608 = v607[v710];
    int v719 = v608 + ((int)((unsigned int)(v608 - v604) >> 31));
    v607[v710] = v719;
    int * v610 = v586->cache_age;
    v610[v716] = 0;
    v695 = v716;
  } else {
    int * v613 = v586->cache_age;
    int v723 = (((int)((unsigned int)((int)((unsigned int)(v594 + 4) >> 2)) >> 1)) & 1) * 2;
    int v614 = v613[v723];
    int * v615 = v586->cache_tags;
    int v616 = v615[v723];
    int v617 = v613[v710];
    int v618 = v615[v710];
    bool v725 = !(((~(((v598 ^ ((int)((unsigned int)((int)((unsigned int)(v594 + 4) >> 2)) >> 1))) | (-(v598 ^ ((int)((unsigned int)((int)((unsigned int)(v594 + 4) >> 2)) >> 1))))) >> 31)) | (~(((v599 ^ ((int)((unsigned int)((int)((unsigned int)(v594 + 4) >> 2)) >> 1))) | (-(v599 ^ ((int)((unsigned int)((int)((unsigned int)(v594 + 4) >> 2)) >> 1))))) >> 31))) == 0);
    int v672;
    if (v725) {
      int * v619 = v586->cache_age;
      int v727 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v594 + 4) >> 2)) >> 1)) & 3) * 2)) + ((~(((v599 ^ ((int)((unsigned int)((int)((unsigned int)(v594 + 4) >> 2)) >> 1))) | (-(v599 ^ ((int)((unsigned int)((int)((unsigned int)(v594 + 4) >> 2)) >> 1))))) >> 31)) & 1);
      int v620 = v619[v727];
      int v621 = v619[v711];
      int v728 = v621 + ((int)((unsigned int)(v621 - v620) >> 31));
      v619[v711] = v728;
      int * v623 = v586->cache_age;
      int v624 = v623[v712];
      int v730 = v624 + ((int)((unsigned int)(v624 - v620) >> 31));
      v623[v712] = v730;
      int * v626 = v586->cache_age;
      v626[v727] = 0;
      v672 = v727;
    } else {
      int * v629 = v586->cache_age;
      int v734 = 4 + ((((int)((unsigned int)((int)((unsigned int)(v594 + 4) >> 2)) >> 1)) & 3) * 2);
      int v630 = v629[v734];
      int * v631 = v586->cache_tags;
      int v632 = v631[v734];
      int v633 = v629[v712];
      int v634 = v631[v712];
      int * v635 = v586->cache_dirty;
      int v737 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v594 + 4) >> 2)) >> 1)) & 3) * 2)) + ((((v630 + ((~(((v632 ^ -1) | (-(v632 ^ -1))) >> 31)) & 2)) - (v633 + ((~(((v634 ^ -1) | (-(v634 ^ -1))) >> 31)) & 2))) >> 31) & 1);
      int v636 = v635[v737];
      bool v738 = !(v636 == 0);
      if (v738) {
        int * v637 = v586->cache_tags;
        int v638 = v637[v737];
        int * v639 = v586->cache_vals;
        int v741 = ((4 + ((((int)((unsigned int)((int)((unsigned int)(v594 + 4) >> 2)) >> 1)) & 3) * 2)) + ((((v630 + ((~(((v632 ^ -1) | (-(v632 ^ -1))) >> 31)) & 2)) - (v633 + ((~(((v634 ^ -1) | (-(v634 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
        int v640 = v639[v741];
        int v742 = (((4 + ((((int)((unsigned int)((int)((unsigned int)(v594 + 4) >> 2)) >> 1)) & 3) * 2)) + ((((v630 + ((~(((v632 ^ -1) | (-(v632 ^ -1))) >> 31)) & 2)) - (v633 + ((~(((v634 ^ -1) | (-(v634 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
        int v641 = v639[v742];
        int * v642 = v586->mem;
        int v744 = v638 * 2;
        v642[v744] = v640;
        int * v644 = v586->mem;
        int v747 = (v638 * 2) + 1;
        v644[v747] = v641;
        ;
      } else {
        ;
      }
      int * v649 = v586->mem;
      int v752 = ((int)((unsigned int)((int)((unsigned int)(v594 + 4) >> 2)) >> 1)) * 2;
      int v650 = v649[v752];
      int v753 = (((int)((unsigned int)((int)((unsigned int)(v594 + 4) >> 2)) >> 1)) * 2) + 1;
      int v651 = v649[v753];
      int * v652 = v586->cache_vals;
      int v755 = ((4 + ((((int)((unsigned int)((int)((unsigned int)(v594 + 4) >> 2)) >> 1)) & 3) * 2)) + ((((v630 + ((~(((v632 ^ -1) | (-(v632 ^ -1))) >> 31)) & 2)) - (v633 + ((~(((v634 ^ -1) | (-(v634 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
      v652[v755] = v650;
      int * v654 = v586->cache_vals;
      int v758 = (((4 + ((((int)((unsigned int)((int)((unsigned int)(v594 + 4) >> 2)) >> 1)) & 3) * 2)) + ((((v630 + ((~(((v632 ^ -1) | (-(v632 ^ -1))) >> 31)) & 2)) - (v633 + ((~(((v634 ^ -1) | (-(v634 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
      v654[v758] = v651;
      int * v656 = v586->cache_tags;
      int v761 = (int)((unsigned int)((int)((unsigned int)(v594 + 4) >> 2)) >> 1);
      v656[v737] = v761;
      int * v658 = v586->cache_dirty;
      v658[v737] = 0;
      int * v660 = v586->cache_age;
      v660[v737] = 1;
      int * v662 = v586->cache_age;
      int v663 = v662[v737];
      int v664 = v662[v711];
      int v767 = v664 + ((int)((unsigned int)(v664 - v663) >> 31));
      v662[v711] = v767;
      int * v666 = v586->cache_age;
      int v667 = v666[v712];
      int v769 = v667 + ((int)((unsigned int)(v667 - v663) >> 31));
      v666[v712] = v769;
      int * v669 = v586->cache_age;
      v669[v737] = 0;
      v672 = v737;
    }
    int * v673 = v586->cache_vals;
    int v772 = v672 * 2;
    int v674 = v673[v772];
    int v773 = (v672 * 2) + 1;
    int v675 = v673[v773];
    int v774 = (((((int)((unsigned int)((int)((unsigned int)(v594 + 4) >> 2)) >> 1)) & 1) * 2) + ((((v614 + ((~(((v616 ^ -1) | (-(v616 ^ -1))) >> 31)) & 2)) - (v617 + ((~(((v618 ^ -1) | (-(v618 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
    v673[v774] = v674;
    int * v677 = v586->cache_vals;
    int v777 = ((((((int)((unsigned int)((int)((unsigned int)(v594 + 4) >> 2)) >> 1)) & 1) * 2) + ((((v614 + ((~(((v616 ^ -1) | (-(v616 ^ -1))) >> 31)) & 2)) - (v617 + ((~(((v618 ^ -1) | (-(v618 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
    v677[v777] = v675;
    int * v679 = v586->cache_tags;
    int v780 = ((((int)((unsigned int)((int)((unsigned int)(v594 + 4) >> 2)) >> 1)) & 1) * 2) + ((((v614 + ((~(((v616 ^ -1) | (-(v616 ^ -1))) >> 31)) & 2)) - (v617 + ((~(((v618 ^ -1) | (-(v618 ^ -1))) >> 31)) & 2))) >> 31) & 1);
    int v781 = (int)((unsigned int)((int)((unsigned int)(v594 + 4) >> 2)) >> 1);
    v679[v780] = v781;
    int * v681 = v586->cache_dirty;
    v681[v780] = 0;
    int * v683 = v586->cache_age;
    v683[v780] = 1;
    int * v685 = v586->cache_age;
    int v686 = v685[v780];
    int v687 = v685[v709];
    int v787 = v687 + ((int)((unsigned int)(v687 - v686) >> 31));
    v685[v709] = v787;
    int * v689 = v586->cache_age;
    int v690 = v689[v710];
    int v789 = v690 + ((int)((unsigned int)(v690 - v686) >> 31));
    v689[v710] = v789;
    int * v692 = v586->cache_age;
    v692[v780] = 0;
    v695 = v780;
  }
  int v792 = (v695 * 2) + (((int)((unsigned int)(v594 + 4) >> 2)) & 1);
  int v696 = v602[v792];
  int * v697 = v586->regs;
  v697[6] = v696;
  struct StateT * v699 = slot_13(v586);
  return v699;
}

struct StateT * slot_43(struct StateT * v3441) {
  int v3442 = v3441->timer;
  int v3552 = v3442 + 1;
  v3441->timer = v3552;
  int * v3444 = v3441->regs;
  int v3445 = v3444[15];
  int * v3446 = v3441->cache_tags;
  int v3556 = (((int)((unsigned int)((int)((unsigned int)(v3445 + 4) >> 2)) >> 1)) & 1) * 2;
  int v3447 = v3446[v3556];
  int v3557 = ((((int)((unsigned int)((int)((unsigned int)(v3445 + 4) >> 2)) >> 1)) & 1) * 2) + 1;
  int v3448 = v3446[v3557];
  int v3558 = 4 + ((((int)((unsigned int)((int)((unsigned int)(v3445 + 4) >> 2)) >> 1)) & 3) * 2);
  int v3449 = v3446[v3558];
  int v3559 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v3445 + 4) >> 2)) >> 1)) & 3) * 2)) + 1;
  int v3450 = v3446[v3559];
  int v3451 = v3441->timer;
  int v3560 = v3451 + ((100 ^ (((~(((v3449 ^ ((int)((unsigned int)((int)((unsigned int)(v3445 + 4) >> 2)) >> 1))) | (-(v3449 ^ ((int)((unsigned int)((int)((unsigned int)(v3445 + 4) >> 2)) >> 1))))) >> 31)) | (~(((v3450 ^ ((int)((unsigned int)((int)((unsigned int)(v3445 + 4) >> 2)) >> 1))) | (-(v3450 ^ ((int)((unsigned int)((int)((unsigned int)(v3445 + 4) >> 2)) >> 1))))) >> 31))) & 104)) ^ (((~(((v3447 ^ ((int)((unsigned int)((int)((unsigned int)(v3445 + 4) >> 2)) >> 1))) | (-(v3447 ^ ((int)((unsigned int)((int)((unsigned int)(v3445 + 4) >> 2)) >> 1))))) >> 31)) | (~(((v3448 ^ ((int)((unsigned int)((int)((unsigned int)(v3445 + 4) >> 2)) >> 1))) | (-(v3448 ^ ((int)((unsigned int)((int)((unsigned int)(v3445 + 4) >> 2)) >> 1))))) >> 31))) & (1 ^ (100 ^ (((~(((v3449 ^ ((int)((unsigned int)((int)((unsigned int)(v3445 + 4) >> 2)) >> 1))) | (-(v3449 ^ ((int)((unsigned int)((int)((unsigned int)(v3445 + 4) >> 2)) >> 1))))) >> 31)) | (~(((v3450 ^ ((int)((unsigned int)((int)((unsigned int)(v3445 + 4) >> 2)) >> 1))) | (-(v3450 ^ ((int)((unsigned int)((int)((unsigned int)(v3445 + 4) >> 2)) >> 1))))) >> 31))) & 104)))));
  v3441->timer = v3560;
  int * v3453 = v3441->cache_vals;
  bool v3561 = !(((~(((v3447 ^ ((int)((unsigned int)((int)((unsigned int)(v3445 + 4) >> 2)) >> 1))) | (-(v3447 ^ ((int)((unsigned int)((int)((unsigned int)(v3445 + 4) >> 2)) >> 1))))) >> 31)) | (~(((v3448 ^ ((int)((unsigned int)((int)((unsigned int)(v3445 + 4) >> 2)) >> 1))) | (-(v3448 ^ ((int)((unsigned int)((int)((unsigned int)(v3445 + 4) >> 2)) >> 1))))) >> 31))) == 0);
  int v3546;
  if (v3561) {
    int * v3454 = v3441->cache_age;
    int v3563 = ((((int)((unsigned int)((int)((unsigned int)(v3445 + 4) >> 2)) >> 1)) & 1) * 2) + ((~(((v3448 ^ ((int)((unsigned int)((int)((unsigned int)(v3445 + 4) >> 2)) >> 1))) | (-(v3448 ^ ((int)((unsigned int)((int)((unsigned int)(v3445 + 4) >> 2)) >> 1))))) >> 31)) & 1);
    int v3455 = v3454[v3563];
    int v3456 = v3454[v3556];
    int v3564 = v3456 + ((int)((unsigned int)(v3456 - v3455) >> 31));
    v3454[v3556] = v3564;
    int * v3458 = v3441->cache_age;
    int v3459 = v3458[v3557];
    int v3566 = v3459 + ((int)((unsigned int)(v3459 - v3455) >> 31));
    v3458[v3557] = v3566;
    int * v3461 = v3441->cache_age;
    v3461[v3563] = 0;
    v3546 = v3563;
  } else {
    int * v3464 = v3441->cache_age;
    int v3570 = (((int)((unsigned int)((int)((unsigned int)(v3445 + 4) >> 2)) >> 1)) & 1) * 2;
    int v3465 = v3464[v3570];
    int * v3466 = v3441->cache_tags;
    int v3467 = v3466[v3570];
    int v3468 = v3464[v3557];
    int v3469 = v3466[v3557];
    bool v3572 = !(((~(((v3449 ^ ((int)((unsigned int)((int)((unsigned int)(v3445 + 4) >> 2)) >> 1))) | (-(v3449 ^ ((int)((unsigned int)((int)((unsigned int)(v3445 + 4) >> 2)) >> 1))))) >> 31)) | (~(((v3450 ^ ((int)((unsigned int)((int)((unsigned int)(v3445 + 4) >> 2)) >> 1))) | (-(v3450 ^ ((int)((unsigned int)((int)((unsigned int)(v3445 + 4) >> 2)) >> 1))))) >> 31))) == 0);
    int v3523;
    if (v3572) {
      int * v3470 = v3441->cache_age;
      int v3574 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v3445 + 4) >> 2)) >> 1)) & 3) * 2)) + ((~(((v3450 ^ ((int)((unsigned int)((int)((unsigned int)(v3445 + 4) >> 2)) >> 1))) | (-(v3450 ^ ((int)((unsigned int)((int)((unsigned int)(v3445 + 4) >> 2)) >> 1))))) >> 31)) & 1);
      int v3471 = v3470[v3574];
      int v3472 = v3470[v3558];
      int v3575 = v3472 + ((int)((unsigned int)(v3472 - v3471) >> 31));
      v3470[v3558] = v3575;
      int * v3474 = v3441->cache_age;
      int v3475 = v3474[v3559];
      int v3577 = v3475 + ((int)((unsigned int)(v3475 - v3471) >> 31));
      v3474[v3559] = v3577;
      int * v3477 = v3441->cache_age;
      v3477[v3574] = 0;
      v3523 = v3574;
    } else {
      int * v3480 = v3441->cache_age;
      int v3581 = 4 + ((((int)((unsigned int)((int)((unsigned int)(v3445 + 4) >> 2)) >> 1)) & 3) * 2);
      int v3481 = v3480[v3581];
      int * v3482 = v3441->cache_tags;
      int v3483 = v3482[v3581];
      int v3484 = v3480[v3559];
      int v3485 = v3482[v3559];
      int * v3486 = v3441->cache_dirty;
      int v3584 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v3445 + 4) >> 2)) >> 1)) & 3) * 2)) + ((((v3481 + ((~(((v3483 ^ -1) | (-(v3483 ^ -1))) >> 31)) & 2)) - (v3484 + ((~(((v3485 ^ -1) | (-(v3485 ^ -1))) >> 31)) & 2))) >> 31) & 1);
      int v3487 = v3486[v3584];
      bool v3585 = !(v3487 == 0);
      if (v3585) {
        int * v3488 = v3441->cache_tags;
        int v3489 = v3488[v3584];
        int * v3490 = v3441->cache_vals;
        int v3588 = ((4 + ((((int)((unsigned int)((int)((unsigned int)(v3445 + 4) >> 2)) >> 1)) & 3) * 2)) + ((((v3481 + ((~(((v3483 ^ -1) | (-(v3483 ^ -1))) >> 31)) & 2)) - (v3484 + ((~(((v3485 ^ -1) | (-(v3485 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
        int v3491 = v3490[v3588];
        int v3589 = (((4 + ((((int)((unsigned int)((int)((unsigned int)(v3445 + 4) >> 2)) >> 1)) & 3) * 2)) + ((((v3481 + ((~(((v3483 ^ -1) | (-(v3483 ^ -1))) >> 31)) & 2)) - (v3484 + ((~(((v3485 ^ -1) | (-(v3485 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
        int v3492 = v3490[v3589];
        int * v3493 = v3441->mem;
        int v3591 = v3489 * 2;
        v3493[v3591] = v3491;
        int * v3495 = v3441->mem;
        int v3594 = (v3489 * 2) + 1;
        v3495[v3594] = v3492;
        ;
      } else {
        ;
      }
      int * v3500 = v3441->mem;
      int v3599 = ((int)((unsigned int)((int)((unsigned int)(v3445 + 4) >> 2)) >> 1)) * 2;
      int v3501 = v3500[v3599];
      int v3600 = (((int)((unsigned int)((int)((unsigned int)(v3445 + 4) >> 2)) >> 1)) * 2) + 1;
      int v3502 = v3500[v3600];
      int * v3503 = v3441->cache_vals;
      int v3602 = ((4 + ((((int)((unsigned int)((int)((unsigned int)(v3445 + 4) >> 2)) >> 1)) & 3) * 2)) + ((((v3481 + ((~(((v3483 ^ -1) | (-(v3483 ^ -1))) >> 31)) & 2)) - (v3484 + ((~(((v3485 ^ -1) | (-(v3485 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
      v3503[v3602] = v3501;
      int * v3505 = v3441->cache_vals;
      int v3605 = (((4 + ((((int)((unsigned int)((int)((unsigned int)(v3445 + 4) >> 2)) >> 1)) & 3) * 2)) + ((((v3481 + ((~(((v3483 ^ -1) | (-(v3483 ^ -1))) >> 31)) & 2)) - (v3484 + ((~(((v3485 ^ -1) | (-(v3485 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
      v3505[v3605] = v3502;
      int * v3507 = v3441->cache_tags;
      int v3608 = (int)((unsigned int)((int)((unsigned int)(v3445 + 4) >> 2)) >> 1);
      v3507[v3584] = v3608;
      int * v3509 = v3441->cache_dirty;
      v3509[v3584] = 0;
      int * v3511 = v3441->cache_age;
      v3511[v3584] = 1;
      int * v3513 = v3441->cache_age;
      int v3514 = v3513[v3584];
      int v3515 = v3513[v3558];
      int v3614 = v3515 + ((int)((unsigned int)(v3515 - v3514) >> 31));
      v3513[v3558] = v3614;
      int * v3517 = v3441->cache_age;
      int v3518 = v3517[v3559];
      int v3616 = v3518 + ((int)((unsigned int)(v3518 - v3514) >> 31));
      v3517[v3559] = v3616;
      int * v3520 = v3441->cache_age;
      v3520[v3584] = 0;
      v3523 = v3584;
    }
    int * v3524 = v3441->cache_vals;
    int v3619 = v3523 * 2;
    int v3525 = v3524[v3619];
    int v3620 = (v3523 * 2) + 1;
    int v3526 = v3524[v3620];
    int v3621 = (((((int)((unsigned int)((int)((unsigned int)(v3445 + 4) >> 2)) >> 1)) & 1) * 2) + ((((v3465 + ((~(((v3467 ^ -1) | (-(v3467 ^ -1))) >> 31)) & 2)) - (v3468 + ((~(((v3469 ^ -1) | (-(v3469 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
    v3524[v3621] = v3525;
    int * v3528 = v3441->cache_vals;
    int v3624 = ((((((int)((unsigned int)((int)((unsigned int)(v3445 + 4) >> 2)) >> 1)) & 1) * 2) + ((((v3465 + ((~(((v3467 ^ -1) | (-(v3467 ^ -1))) >> 31)) & 2)) - (v3468 + ((~(((v3469 ^ -1) | (-(v3469 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
    v3528[v3624] = v3526;
    int * v3530 = v3441->cache_tags;
    int v3627 = ((((int)((unsigned int)((int)((unsigned int)(v3445 + 4) >> 2)) >> 1)) & 1) * 2) + ((((v3465 + ((~(((v3467 ^ -1) | (-(v3467 ^ -1))) >> 31)) & 2)) - (v3468 + ((~(((v3469 ^ -1) | (-(v3469 ^ -1))) >> 31)) & 2))) >> 31) & 1);
    int v3628 = (int)((unsigned int)((int)((unsigned int)(v3445 + 4) >> 2)) >> 1);
    v3530[v3627] = v3628;
    int * v3532 = v3441->cache_dirty;
    v3532[v3627] = 0;
    int * v3534 = v3441->cache_age;
    v3534[v3627] = 1;
    int * v3536 = v3441->cache_age;
    int v3537 = v3536[v3627];
    int v3538 = v3536[v3556];
    int v3634 = v3538 + ((int)((unsigned int)(v3538 - v3537) >> 31));
    v3536[v3556] = v3634;
    int * v3540 = v3441->cache_age;
    int v3541 = v3540[v3557];
    int v3636 = v3541 + ((int)((unsigned int)(v3541 - v3537) >> 31));
    v3540[v3557] = v3636;
    int * v3543 = v3441->cache_age;
    v3543[v3627] = 0;
    v3546 = v3627;
  }
  int v3639 = (v3546 * 2) + (((int)((unsigned int)(v3445 + 4) >> 2)) & 1);
  int v3547 = v3453[v3639];
  int * v3548 = v3441->regs;
  v3548[6] = v3547;
  struct StateT * v3550 = slot_44(v3441);
  return v3550;
}

struct StateT * slot_6(struct StateT * v94) {
  int v95 = v94->timer;
  int v99 = v95 + 1;
  v94->timer = v99;
  struct StateT * v97 = slot_7(v94);
  return v97;
}

struct StateT * slot_47(struct StateT * v3881) {
  int v3882 = v3881->timer;
  int v3890 = v3882 + 1;
  v3881->timer = v3890;
  int * v3884 = v3881->regs;
  int v3885 = v3884[13];
  int v3886 = v3884[7];
  int v3894 = v3885 & v3886;
  v3884[7] = v3894;
  struct StateT * v3888 = slot_48(v3881);
  return v3888;
}

struct StateT * slot_29(struct StateT * v2247) {
  int v2248 = v2247->timer;
  int v2256 = v2248 + 1;
  v2247->timer = v2256;
  int * v2250 = v2247->regs;
  int v2251 = v2250[13];
  int v2252 = v2250[17];
  int v2260 = v2251 & v2252;
  v2250[17] = v2260;
  struct StateT * v2254 = slot_30(v2247);
  return v2254;
}

struct StateT * slot_16(struct StateT * v1040) {
  int v1041 = v1040->timer;
  int v1049 = v1041 + 1;
  v1040->timer = v1049;
  int * v1043 = v1040->regs;
  int v1044 = v1043[13];
  int v1045 = v1043[7];
  int v1053 = v1044 & v1045;
  v1043[7] = v1053;
  struct StateT * v1047 = slot_17(v1040);
  return v1047;
}

struct StateT * slot_5(struct StateT * v80) {
  int v81 = v80->timer;
  int v88 = v81 + 1;
  v80->timer = v88;
  int * v83 = v80->regs;
  int v84 = v83[13];
  int v91 = v84 + -1;
  v83[13] = v91;
  struct StateT * v86 = slot_6(v80);
  return v86;
}

struct StateT * slot_7(struct StateT * v102) {
  int * v103 = v102->saved_regs;
  int * v104 = v102->regs;
  int v105 = v104[15];
  v103[15] = v105;
  int v107 = v102->timer;
  int v118 = v107 + 1;
  v102->timer = v118;
  int * v109 = v102->regs;
  int v110 = v109[14];
  int v121 = v110 << 3;
  v109[15] = v121;
  struct StateT * v112 = slot_8(v102);
  return v112;
}

struct StateT * slot_31(struct StateT * v2279) {
  int v2280 = v2279->timer;
  int v2288 = v2280 + 1;
  v2279->timer = v2288;
  int * v2282 = v2279->regs;
  int v2283 = v2282[16];
  int v2284 = v2282[5];
  int v2292 = v2283 ^ v2284;
  v2282[16] = v2292;
  struct StateT * v2286 = slot_32(v2279);
  return v2286;
}

struct StateT * slot_26(struct StateT * v2011) {
  int v2012 = v2011->timer;
  int v2122 = v2012 + 1;
  v2011->timer = v2122;
  int * v2014 = v2011->regs;
  int v2015 = v2014[15];
  int * v2016 = v2011->cache_tags;
  int v2126 = (((int)((unsigned int)((int)((unsigned int)v2015 >> 2)) >> 1)) & 1) * 2;
  int v2017 = v2016[v2126];
  int v2127 = ((((int)((unsigned int)((int)((unsigned int)v2015 >> 2)) >> 1)) & 1) * 2) + 1;
  int v2018 = v2016[v2127];
  int v2128 = 4 + ((((int)((unsigned int)((int)((unsigned int)v2015 >> 2)) >> 1)) & 3) * 2);
  int v2019 = v2016[v2128];
  int v2129 = (4 + ((((int)((unsigned int)((int)((unsigned int)v2015 >> 2)) >> 1)) & 3) * 2)) + 1;
  int v2020 = v2016[v2129];
  int v2021 = v2011->timer;
  int v2130 = v2021 + ((100 ^ (((~(((v2019 ^ ((int)((unsigned int)((int)((unsigned int)v2015 >> 2)) >> 1))) | (-(v2019 ^ ((int)((unsigned int)((int)((unsigned int)v2015 >> 2)) >> 1))))) >> 31)) | (~(((v2020 ^ ((int)((unsigned int)((int)((unsigned int)v2015 >> 2)) >> 1))) | (-(v2020 ^ ((int)((unsigned int)((int)((unsigned int)v2015 >> 2)) >> 1))))) >> 31))) & 104)) ^ (((~(((v2017 ^ ((int)((unsigned int)((int)((unsigned int)v2015 >> 2)) >> 1))) | (-(v2017 ^ ((int)((unsigned int)((int)((unsigned int)v2015 >> 2)) >> 1))))) >> 31)) | (~(((v2018 ^ ((int)((unsigned int)((int)((unsigned int)v2015 >> 2)) >> 1))) | (-(v2018 ^ ((int)((unsigned int)((int)((unsigned int)v2015 >> 2)) >> 1))))) >> 31))) & (1 ^ (100 ^ (((~(((v2019 ^ ((int)((unsigned int)((int)((unsigned int)v2015 >> 2)) >> 1))) | (-(v2019 ^ ((int)((unsigned int)((int)((unsigned int)v2015 >> 2)) >> 1))))) >> 31)) | (~(((v2020 ^ ((int)((unsigned int)((int)((unsigned int)v2015 >> 2)) >> 1))) | (-(v2020 ^ ((int)((unsigned int)((int)((unsigned int)v2015 >> 2)) >> 1))))) >> 31))) & 104)))));
  v2011->timer = v2130;
  int * v2023 = v2011->cache_vals;
  bool v2131 = !(((~(((v2017 ^ ((int)((unsigned int)((int)((unsigned int)v2015 >> 2)) >> 1))) | (-(v2017 ^ ((int)((unsigned int)((int)((unsigned int)v2015 >> 2)) >> 1))))) >> 31)) | (~(((v2018 ^ ((int)((unsigned int)((int)((unsigned int)v2015 >> 2)) >> 1))) | (-(v2018 ^ ((int)((unsigned int)((int)((unsigned int)v2015 >> 2)) >> 1))))) >> 31))) == 0);
  int v2116;
  if (v2131) {
    int * v2024 = v2011->cache_age;
    int v2133 = ((((int)((unsigned int)((int)((unsigned int)v2015 >> 2)) >> 1)) & 1) * 2) + ((~(((v2018 ^ ((int)((unsigned int)((int)((unsigned int)v2015 >> 2)) >> 1))) | (-(v2018 ^ ((int)((unsigned int)((int)((unsigned int)v2015 >> 2)) >> 1))))) >> 31)) & 1);
    int v2025 = v2024[v2133];
    int v2026 = v2024[v2126];
    int v2134 = v2026 + ((int)((unsigned int)(v2026 - v2025) >> 31));
    v2024[v2126] = v2134;
    int * v2028 = v2011->cache_age;
    int v2029 = v2028[v2127];
    int v2136 = v2029 + ((int)((unsigned int)(v2029 - v2025) >> 31));
    v2028[v2127] = v2136;
    int * v2031 = v2011->cache_age;
    v2031[v2133] = 0;
    v2116 = v2133;
  } else {
    int * v2034 = v2011->cache_age;
    int v2140 = (((int)((unsigned int)((int)((unsigned int)v2015 >> 2)) >> 1)) & 1) * 2;
    int v2035 = v2034[v2140];
    int * v2036 = v2011->cache_tags;
    int v2037 = v2036[v2140];
    int v2038 = v2034[v2127];
    int v2039 = v2036[v2127];
    bool v2142 = !(((~(((v2019 ^ ((int)((unsigned int)((int)((unsigned int)v2015 >> 2)) >> 1))) | (-(v2019 ^ ((int)((unsigned int)((int)((unsigned int)v2015 >> 2)) >> 1))))) >> 31)) | (~(((v2020 ^ ((int)((unsigned int)((int)((unsigned int)v2015 >> 2)) >> 1))) | (-(v2020 ^ ((int)((unsigned int)((int)((unsigned int)v2015 >> 2)) >> 1))))) >> 31))) == 0);
    int v2093;
    if (v2142) {
      int * v2040 = v2011->cache_age;
      int v2144 = (4 + ((((int)((unsigned int)((int)((unsigned int)v2015 >> 2)) >> 1)) & 3) * 2)) + ((~(((v2020 ^ ((int)((unsigned int)((int)((unsigned int)v2015 >> 2)) >> 1))) | (-(v2020 ^ ((int)((unsigned int)((int)((unsigned int)v2015 >> 2)) >> 1))))) >> 31)) & 1);
      int v2041 = v2040[v2144];
      int v2042 = v2040[v2128];
      int v2145 = v2042 + ((int)((unsigned int)(v2042 - v2041) >> 31));
      v2040[v2128] = v2145;
      int * v2044 = v2011->cache_age;
      int v2045 = v2044[v2129];
      int v2147 = v2045 + ((int)((unsigned int)(v2045 - v2041) >> 31));
      v2044[v2129] = v2147;
      int * v2047 = v2011->cache_age;
      v2047[v2144] = 0;
      v2093 = v2144;
    } else {
      int * v2050 = v2011->cache_age;
      int v2151 = 4 + ((((int)((unsigned int)((int)((unsigned int)v2015 >> 2)) >> 1)) & 3) * 2);
      int v2051 = v2050[v2151];
      int * v2052 = v2011->cache_tags;
      int v2053 = v2052[v2151];
      int v2054 = v2050[v2129];
      int v2055 = v2052[v2129];
      int * v2056 = v2011->cache_dirty;
      int v2154 = (4 + ((((int)((unsigned int)((int)((unsigned int)v2015 >> 2)) >> 1)) & 3) * 2)) + ((((v2051 + ((~(((v2053 ^ -1) | (-(v2053 ^ -1))) >> 31)) & 2)) - (v2054 + ((~(((v2055 ^ -1) | (-(v2055 ^ -1))) >> 31)) & 2))) >> 31) & 1);
      int v2057 = v2056[v2154];
      bool v2155 = !(v2057 == 0);
      if (v2155) {
        int * v2058 = v2011->cache_tags;
        int v2059 = v2058[v2154];
        int * v2060 = v2011->cache_vals;
        int v2158 = ((4 + ((((int)((unsigned int)((int)((unsigned int)v2015 >> 2)) >> 1)) & 3) * 2)) + ((((v2051 + ((~(((v2053 ^ -1) | (-(v2053 ^ -1))) >> 31)) & 2)) - (v2054 + ((~(((v2055 ^ -1) | (-(v2055 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
        int v2061 = v2060[v2158];
        int v2159 = (((4 + ((((int)((unsigned int)((int)((unsigned int)v2015 >> 2)) >> 1)) & 3) * 2)) + ((((v2051 + ((~(((v2053 ^ -1) | (-(v2053 ^ -1))) >> 31)) & 2)) - (v2054 + ((~(((v2055 ^ -1) | (-(v2055 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
        int v2062 = v2060[v2159];
        int * v2063 = v2011->mem;
        int v2161 = v2059 * 2;
        v2063[v2161] = v2061;
        int * v2065 = v2011->mem;
        int v2164 = (v2059 * 2) + 1;
        v2065[v2164] = v2062;
        ;
      } else {
        ;
      }
      int * v2070 = v2011->mem;
      int v2169 = ((int)((unsigned int)((int)((unsigned int)v2015 >> 2)) >> 1)) * 2;
      int v2071 = v2070[v2169];
      int v2170 = (((int)((unsigned int)((int)((unsigned int)v2015 >> 2)) >> 1)) * 2) + 1;
      int v2072 = v2070[v2170];
      int * v2073 = v2011->cache_vals;
      int v2172 = ((4 + ((((int)((unsigned int)((int)((unsigned int)v2015 >> 2)) >> 1)) & 3) * 2)) + ((((v2051 + ((~(((v2053 ^ -1) | (-(v2053 ^ -1))) >> 31)) & 2)) - (v2054 + ((~(((v2055 ^ -1) | (-(v2055 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
      v2073[v2172] = v2071;
      int * v2075 = v2011->cache_vals;
      int v2175 = (((4 + ((((int)((unsigned int)((int)((unsigned int)v2015 >> 2)) >> 1)) & 3) * 2)) + ((((v2051 + ((~(((v2053 ^ -1) | (-(v2053 ^ -1))) >> 31)) & 2)) - (v2054 + ((~(((v2055 ^ -1) | (-(v2055 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
      v2075[v2175] = v2072;
      int * v2077 = v2011->cache_tags;
      int v2178 = (int)((unsigned int)((int)((unsigned int)v2015 >> 2)) >> 1);
      v2077[v2154] = v2178;
      int * v2079 = v2011->cache_dirty;
      v2079[v2154] = 0;
      int * v2081 = v2011->cache_age;
      v2081[v2154] = 1;
      int * v2083 = v2011->cache_age;
      int v2084 = v2083[v2154];
      int v2085 = v2083[v2128];
      int v2184 = v2085 + ((int)((unsigned int)(v2085 - v2084) >> 31));
      v2083[v2128] = v2184;
      int * v2087 = v2011->cache_age;
      int v2088 = v2087[v2129];
      int v2186 = v2088 + ((int)((unsigned int)(v2088 - v2084) >> 31));
      v2087[v2129] = v2186;
      int * v2090 = v2011->cache_age;
      v2090[v2154] = 0;
      v2093 = v2154;
    }
    int * v2094 = v2011->cache_vals;
    int v2189 = v2093 * 2;
    int v2095 = v2094[v2189];
    int v2190 = (v2093 * 2) + 1;
    int v2096 = v2094[v2190];
    int v2191 = (((((int)((unsigned int)((int)((unsigned int)v2015 >> 2)) >> 1)) & 1) * 2) + ((((v2035 + ((~(((v2037 ^ -1) | (-(v2037 ^ -1))) >> 31)) & 2)) - (v2038 + ((~(((v2039 ^ -1) | (-(v2039 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
    v2094[v2191] = v2095;
    int * v2098 = v2011->cache_vals;
    int v2194 = ((((((int)((unsigned int)((int)((unsigned int)v2015 >> 2)) >> 1)) & 1) * 2) + ((((v2035 + ((~(((v2037 ^ -1) | (-(v2037 ^ -1))) >> 31)) & 2)) - (v2038 + ((~(((v2039 ^ -1) | (-(v2039 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
    v2098[v2194] = v2096;
    int * v2100 = v2011->cache_tags;
    int v2197 = ((((int)((unsigned int)((int)((unsigned int)v2015 >> 2)) >> 1)) & 1) * 2) + ((((v2035 + ((~(((v2037 ^ -1) | (-(v2037 ^ -1))) >> 31)) & 2)) - (v2038 + ((~(((v2039 ^ -1) | (-(v2039 ^ -1))) >> 31)) & 2))) >> 31) & 1);
    int v2198 = (int)((unsigned int)((int)((unsigned int)v2015 >> 2)) >> 1);
    v2100[v2197] = v2198;
    int * v2102 = v2011->cache_dirty;
    v2102[v2197] = 0;
    int * v2104 = v2011->cache_age;
    v2104[v2197] = 1;
    int * v2106 = v2011->cache_age;
    int v2107 = v2106[v2197];
    int v2108 = v2106[v2126];
    int v2204 = v2108 + ((int)((unsigned int)(v2108 - v2107) >> 31));
    v2106[v2126] = v2204;
    int * v2110 = v2011->cache_age;
    int v2111 = v2110[v2127];
    int v2206 = v2111 + ((int)((unsigned int)(v2111 - v2107) >> 31));
    v2110[v2127] = v2206;
    int * v2113 = v2011->cache_age;
    v2113[v2197] = 0;
    v2116 = v2197;
  }
  int v2209 = (v2116 * 2) + (((int)((unsigned int)v2015 >> 2)) & 1);
  int v2117 = v2023[v2209];
  int * v2118 = v2011->regs;
  v2118[6] = v2117;
  struct StateT * v2120 = slot_27(v2011);
  return v2120;
}

struct StateT * slot_10(struct StateT * v164) {
  int * v165 = v164->saved_regs;
  int * v166 = v164->regs;
  int v167 = v166[17];
  v165[17] = v167;
  int v169 = v164->timer;
  int v283 = v169 + 1;
  v164->timer = v283;
  int * v171 = v164->regs;
  int v172 = v171[16];
  int * v173 = v164->cache_tags;
  int v287 = (((int)((unsigned int)((int)((unsigned int)v172 >> 2)) >> 1)) & 1) * 2;
  int v174 = v173[v287];
  int v288 = ((((int)((unsigned int)((int)((unsigned int)v172 >> 2)) >> 1)) & 1) * 2) + 1;
  int v175 = v173[v288];
  int v289 = 4 + ((((int)((unsigned int)((int)((unsigned int)v172 >> 2)) >> 1)) & 3) * 2);
  int v176 = v173[v289];
  int v290 = (4 + ((((int)((unsigned int)((int)((unsigned int)v172 >> 2)) >> 1)) & 3) * 2)) + 1;
  int v177 = v173[v290];
  int v178 = v164->timer;
  int v291 = v178 + ((100 ^ (((~(((v176 ^ ((int)((unsigned int)((int)((unsigned int)v172 >> 2)) >> 1))) | (-(v176 ^ ((int)((unsigned int)((int)((unsigned int)v172 >> 2)) >> 1))))) >> 31)) | (~(((v177 ^ ((int)((unsigned int)((int)((unsigned int)v172 >> 2)) >> 1))) | (-(v177 ^ ((int)((unsigned int)((int)((unsigned int)v172 >> 2)) >> 1))))) >> 31))) & 104)) ^ (((~(((v174 ^ ((int)((unsigned int)((int)((unsigned int)v172 >> 2)) >> 1))) | (-(v174 ^ ((int)((unsigned int)((int)((unsigned int)v172 >> 2)) >> 1))))) >> 31)) | (~(((v175 ^ ((int)((unsigned int)((int)((unsigned int)v172 >> 2)) >> 1))) | (-(v175 ^ ((int)((unsigned int)((int)((unsigned int)v172 >> 2)) >> 1))))) >> 31))) & (1 ^ (100 ^ (((~(((v176 ^ ((int)((unsigned int)((int)((unsigned int)v172 >> 2)) >> 1))) | (-(v176 ^ ((int)((unsigned int)((int)((unsigned int)v172 >> 2)) >> 1))))) >> 31)) | (~(((v177 ^ ((int)((unsigned int)((int)((unsigned int)v172 >> 2)) >> 1))) | (-(v177 ^ ((int)((unsigned int)((int)((unsigned int)v172 >> 2)) >> 1))))) >> 31))) & 104)))));
  v164->timer = v291;
  int * v180 = v164->cache_vals;
  bool v292 = !(((~(((v174 ^ ((int)((unsigned int)((int)((unsigned int)v172 >> 2)) >> 1))) | (-(v174 ^ ((int)((unsigned int)((int)((unsigned int)v172 >> 2)) >> 1))))) >> 31)) | (~(((v175 ^ ((int)((unsigned int)((int)((unsigned int)v172 >> 2)) >> 1))) | (-(v175 ^ ((int)((unsigned int)((int)((unsigned int)v172 >> 2)) >> 1))))) >> 31))) == 0);
  int v273;
  if (v292) {
    int * v181 = v164->cache_age;
    int v294 = ((((int)((unsigned int)((int)((unsigned int)v172 >> 2)) >> 1)) & 1) * 2) + ((~(((v175 ^ ((int)((unsigned int)((int)((unsigned int)v172 >> 2)) >> 1))) | (-(v175 ^ ((int)((unsigned int)((int)((unsigned int)v172 >> 2)) >> 1))))) >> 31)) & 1);
    int v182 = v181[v294];
    int v183 = v181[v287];
    int v295 = v183 + ((int)((unsigned int)(v183 - v182) >> 31));
    v181[v287] = v295;
    int * v185 = v164->cache_age;
    int v186 = v185[v288];
    int v297 = v186 + ((int)((unsigned int)(v186 - v182) >> 31));
    v185[v288] = v297;
    int * v188 = v164->cache_age;
    v188[v294] = 0;
    v273 = v294;
  } else {
    int * v191 = v164->cache_age;
    int v301 = (((int)((unsigned int)((int)((unsigned int)v172 >> 2)) >> 1)) & 1) * 2;
    int v192 = v191[v301];
    int * v193 = v164->cache_tags;
    int v194 = v193[v301];
    int v195 = v191[v288];
    int v196 = v193[v288];
    bool v303 = !(((~(((v176 ^ ((int)((unsigned int)((int)((unsigned int)v172 >> 2)) >> 1))) | (-(v176 ^ ((int)((unsigned int)((int)((unsigned int)v172 >> 2)) >> 1))))) >> 31)) | (~(((v177 ^ ((int)((unsigned int)((int)((unsigned int)v172 >> 2)) >> 1))) | (-(v177 ^ ((int)((unsigned int)((int)((unsigned int)v172 >> 2)) >> 1))))) >> 31))) == 0);
    int v250;
    if (v303) {
      int * v197 = v164->cache_age;
      int v305 = (4 + ((((int)((unsigned int)((int)((unsigned int)v172 >> 2)) >> 1)) & 3) * 2)) + ((~(((v177 ^ ((int)((unsigned int)((int)((unsigned int)v172 >> 2)) >> 1))) | (-(v177 ^ ((int)((unsigned int)((int)((unsigned int)v172 >> 2)) >> 1))))) >> 31)) & 1);
      int v198 = v197[v305];
      int v199 = v197[v289];
      int v306 = v199 + ((int)((unsigned int)(v199 - v198) >> 31));
      v197[v289] = v306;
      int * v201 = v164->cache_age;
      int v202 = v201[v290];
      int v308 = v202 + ((int)((unsigned int)(v202 - v198) >> 31));
      v201[v290] = v308;
      int * v204 = v164->cache_age;
      v204[v305] = 0;
      v250 = v305;
    } else {
      int * v207 = v164->cache_age;
      int v312 = 4 + ((((int)((unsigned int)((int)((unsigned int)v172 >> 2)) >> 1)) & 3) * 2);
      int v208 = v207[v312];
      int * v209 = v164->cache_tags;
      int v210 = v209[v312];
      int v211 = v207[v290];
      int v212 = v209[v290];
      int * v213 = v164->cache_dirty;
      int v315 = (4 + ((((int)((unsigned int)((int)((unsigned int)v172 >> 2)) >> 1)) & 3) * 2)) + ((((v208 + ((~(((v210 ^ -1) | (-(v210 ^ -1))) >> 31)) & 2)) - (v211 + ((~(((v212 ^ -1) | (-(v212 ^ -1))) >> 31)) & 2))) >> 31) & 1);
      int v214 = v213[v315];
      bool v316 = !(v214 == 0);
      if (v316) {
        int * v215 = v164->cache_tags;
        int v216 = v215[v315];
        int * v217 = v164->cache_vals;
        int v319 = ((4 + ((((int)((unsigned int)((int)((unsigned int)v172 >> 2)) >> 1)) & 3) * 2)) + ((((v208 + ((~(((v210 ^ -1) | (-(v210 ^ -1))) >> 31)) & 2)) - (v211 + ((~(((v212 ^ -1) | (-(v212 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
        int v218 = v217[v319];
        int v320 = (((4 + ((((int)((unsigned int)((int)((unsigned int)v172 >> 2)) >> 1)) & 3) * 2)) + ((((v208 + ((~(((v210 ^ -1) | (-(v210 ^ -1))) >> 31)) & 2)) - (v211 + ((~(((v212 ^ -1) | (-(v212 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
        int v219 = v217[v320];
        int * v220 = v164->mem;
        int v322 = v216 * 2;
        v220[v322] = v218;
        int * v222 = v164->mem;
        int v325 = (v216 * 2) + 1;
        v222[v325] = v219;
        ;
      } else {
        ;
      }
      int * v227 = v164->mem;
      int v330 = ((int)((unsigned int)((int)((unsigned int)v172 >> 2)) >> 1)) * 2;
      int v228 = v227[v330];
      int v331 = (((int)((unsigned int)((int)((unsigned int)v172 >> 2)) >> 1)) * 2) + 1;
      int v229 = v227[v331];
      int * v230 = v164->cache_vals;
      int v333 = ((4 + ((((int)((unsigned int)((int)((unsigned int)v172 >> 2)) >> 1)) & 3) * 2)) + ((((v208 + ((~(((v210 ^ -1) | (-(v210 ^ -1))) >> 31)) & 2)) - (v211 + ((~(((v212 ^ -1) | (-(v212 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
      v230[v333] = v228;
      int * v232 = v164->cache_vals;
      int v336 = (((4 + ((((int)((unsigned int)((int)((unsigned int)v172 >> 2)) >> 1)) & 3) * 2)) + ((((v208 + ((~(((v210 ^ -1) | (-(v210 ^ -1))) >> 31)) & 2)) - (v211 + ((~(((v212 ^ -1) | (-(v212 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
      v232[v336] = v229;
      int * v234 = v164->cache_tags;
      int v339 = (int)((unsigned int)((int)((unsigned int)v172 >> 2)) >> 1);
      v234[v315] = v339;
      int * v236 = v164->cache_dirty;
      v236[v315] = 0;
      int * v238 = v164->cache_age;
      v238[v315] = 1;
      int * v240 = v164->cache_age;
      int v241 = v240[v315];
      int v242 = v240[v289];
      int v345 = v242 + ((int)((unsigned int)(v242 - v241) >> 31));
      v240[v289] = v345;
      int * v244 = v164->cache_age;
      int v245 = v244[v290];
      int v347 = v245 + ((int)((unsigned int)(v245 - v241) >> 31));
      v244[v290] = v347;
      int * v247 = v164->cache_age;
      v247[v315] = 0;
      v250 = v315;
    }
    int * v251 = v164->cache_vals;
    int v350 = v250 * 2;
    int v252 = v251[v350];
    int v351 = (v250 * 2) + 1;
    int v253 = v251[v351];
    int v352 = (((((int)((unsigned int)((int)((unsigned int)v172 >> 2)) >> 1)) & 1) * 2) + ((((v192 + ((~(((v194 ^ -1) | (-(v194 ^ -1))) >> 31)) & 2)) - (v195 + ((~(((v196 ^ -1) | (-(v196 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
    v251[v352] = v252;
    int * v255 = v164->cache_vals;
    int v355 = ((((((int)((unsigned int)((int)((unsigned int)v172 >> 2)) >> 1)) & 1) * 2) + ((((v192 + ((~(((v194 ^ -1) | (-(v194 ^ -1))) >> 31)) & 2)) - (v195 + ((~(((v196 ^ -1) | (-(v196 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
    v255[v355] = v253;
    int * v257 = v164->cache_tags;
    int v358 = ((((int)((unsigned int)((int)((unsigned int)v172 >> 2)) >> 1)) & 1) * 2) + ((((v192 + ((~(((v194 ^ -1) | (-(v194 ^ -1))) >> 31)) & 2)) - (v195 + ((~(((v196 ^ -1) | (-(v196 ^ -1))) >> 31)) & 2))) >> 31) & 1);
    int v359 = (int)((unsigned int)((int)((unsigned int)v172 >> 2)) >> 1);
    v257[v358] = v359;
    int * v259 = v164->cache_dirty;
    v259[v358] = 0;
    int * v261 = v164->cache_age;
    v261[v358] = 1;
    int * v263 = v164->cache_age;
    int v264 = v263[v358];
    int v265 = v263[v287];
    int v365 = v265 + ((int)((unsigned int)(v265 - v264) >> 31));
    v263[v287] = v365;
    int * v267 = v164->cache_age;
    int v268 = v267[v288];
    int v367 = v268 + ((int)((unsigned int)(v268 - v264) >> 31));
    v267[v288] = v367;
    int * v270 = v164->cache_age;
    v270[v358] = 0;
    v273 = v358;
  }
  int v370 = (v273 * 2) + (((int)((unsigned int)v172 >> 2)) & 1);
  int v274 = v180[v370];
  int * v275 = v164->regs;
  v275[17] = v274;
  struct StateT * v277 = slot_11(v164);
  return v277;
}

struct StateT * slot_19(struct StateT * v1088) {
  int v1089 = v1088->timer;
  int v1097 = v1089 + 1;
  v1088->timer = v1097;
  int * v1091 = v1088->regs;
  int v1092 = v1091[17];
  int v1093 = v1091[7];
  int v1101 = v1092 ^ v1093;
  v1091[7] = v1101;
  struct StateT * v1095 = slot_20(v1088);
  return v1095;
}

struct StateT * slot_14(struct StateT * v1008) {
  int v1009 = v1008->timer;
  int v1017 = v1009 + 1;
  v1008->timer = v1017;
  int * v1011 = v1008->regs;
  int v1012 = v1011[6];
  int v1013 = v1011[5];
  int v1021 = v1012 ^ v1013;
  v1011[6] = v1021;
  struct StateT * v1015 = slot_15(v1008);
  return v1015;
}

struct StateT * slot_44(struct StateT * v3645) {
  int v3646 = v3645->timer;
  int v3756 = v3646 + 1;
  v3645->timer = v3756;
  int * v3648 = v3645->regs;
  int v3649 = v3648[15];
  int * v3650 = v3645->cache_tags;
  int v3760 = (((int)((unsigned int)((int)((unsigned int)v3649 >> 2)) >> 1)) & 1) * 2;
  int v3651 = v3650[v3760];
  int v3761 = ((((int)((unsigned int)((int)((unsigned int)v3649 >> 2)) >> 1)) & 1) * 2) + 1;
  int v3652 = v3650[v3761];
  int v3762 = 4 + ((((int)((unsigned int)((int)((unsigned int)v3649 >> 2)) >> 1)) & 3) * 2);
  int v3653 = v3650[v3762];
  int v3763 = (4 + ((((int)((unsigned int)((int)((unsigned int)v3649 >> 2)) >> 1)) & 3) * 2)) + 1;
  int v3654 = v3650[v3763];
  int v3655 = v3645->timer;
  int v3764 = v3655 + ((100 ^ (((~(((v3653 ^ ((int)((unsigned int)((int)((unsigned int)v3649 >> 2)) >> 1))) | (-(v3653 ^ ((int)((unsigned int)((int)((unsigned int)v3649 >> 2)) >> 1))))) >> 31)) | (~(((v3654 ^ ((int)((unsigned int)((int)((unsigned int)v3649 >> 2)) >> 1))) | (-(v3654 ^ ((int)((unsigned int)((int)((unsigned int)v3649 >> 2)) >> 1))))) >> 31))) & 104)) ^ (((~(((v3651 ^ ((int)((unsigned int)((int)((unsigned int)v3649 >> 2)) >> 1))) | (-(v3651 ^ ((int)((unsigned int)((int)((unsigned int)v3649 >> 2)) >> 1))))) >> 31)) | (~(((v3652 ^ ((int)((unsigned int)((int)((unsigned int)v3649 >> 2)) >> 1))) | (-(v3652 ^ ((int)((unsigned int)((int)((unsigned int)v3649 >> 2)) >> 1))))) >> 31))) & (1 ^ (100 ^ (((~(((v3653 ^ ((int)((unsigned int)((int)((unsigned int)v3649 >> 2)) >> 1))) | (-(v3653 ^ ((int)((unsigned int)((int)((unsigned int)v3649 >> 2)) >> 1))))) >> 31)) | (~(((v3654 ^ ((int)((unsigned int)((int)((unsigned int)v3649 >> 2)) >> 1))) | (-(v3654 ^ ((int)((unsigned int)((int)((unsigned int)v3649 >> 2)) >> 1))))) >> 31))) & 104)))));
  v3645->timer = v3764;
  int * v3657 = v3645->cache_vals;
  bool v3765 = !(((~(((v3651 ^ ((int)((unsigned int)((int)((unsigned int)v3649 >> 2)) >> 1))) | (-(v3651 ^ ((int)((unsigned int)((int)((unsigned int)v3649 >> 2)) >> 1))))) >> 31)) | (~(((v3652 ^ ((int)((unsigned int)((int)((unsigned int)v3649 >> 2)) >> 1))) | (-(v3652 ^ ((int)((unsigned int)((int)((unsigned int)v3649 >> 2)) >> 1))))) >> 31))) == 0);
  int v3750;
  if (v3765) {
    int * v3658 = v3645->cache_age;
    int v3767 = ((((int)((unsigned int)((int)((unsigned int)v3649 >> 2)) >> 1)) & 1) * 2) + ((~(((v3652 ^ ((int)((unsigned int)((int)((unsigned int)v3649 >> 2)) >> 1))) | (-(v3652 ^ ((int)((unsigned int)((int)((unsigned int)v3649 >> 2)) >> 1))))) >> 31)) & 1);
    int v3659 = v3658[v3767];
    int v3660 = v3658[v3760];
    int v3768 = v3660 + ((int)((unsigned int)(v3660 - v3659) >> 31));
    v3658[v3760] = v3768;
    int * v3662 = v3645->cache_age;
    int v3663 = v3662[v3761];
    int v3770 = v3663 + ((int)((unsigned int)(v3663 - v3659) >> 31));
    v3662[v3761] = v3770;
    int * v3665 = v3645->cache_age;
    v3665[v3767] = 0;
    v3750 = v3767;
  } else {
    int * v3668 = v3645->cache_age;
    int v3774 = (((int)((unsigned int)((int)((unsigned int)v3649 >> 2)) >> 1)) & 1) * 2;
    int v3669 = v3668[v3774];
    int * v3670 = v3645->cache_tags;
    int v3671 = v3670[v3774];
    int v3672 = v3668[v3761];
    int v3673 = v3670[v3761];
    bool v3776 = !(((~(((v3653 ^ ((int)((unsigned int)((int)((unsigned int)v3649 >> 2)) >> 1))) | (-(v3653 ^ ((int)((unsigned int)((int)((unsigned int)v3649 >> 2)) >> 1))))) >> 31)) | (~(((v3654 ^ ((int)((unsigned int)((int)((unsigned int)v3649 >> 2)) >> 1))) | (-(v3654 ^ ((int)((unsigned int)((int)((unsigned int)v3649 >> 2)) >> 1))))) >> 31))) == 0);
    int v3727;
    if (v3776) {
      int * v3674 = v3645->cache_age;
      int v3778 = (4 + ((((int)((unsigned int)((int)((unsigned int)v3649 >> 2)) >> 1)) & 3) * 2)) + ((~(((v3654 ^ ((int)((unsigned int)((int)((unsigned int)v3649 >> 2)) >> 1))) | (-(v3654 ^ ((int)((unsigned int)((int)((unsigned int)v3649 >> 2)) >> 1))))) >> 31)) & 1);
      int v3675 = v3674[v3778];
      int v3676 = v3674[v3762];
      int v3779 = v3676 + ((int)((unsigned int)(v3676 - v3675) >> 31));
      v3674[v3762] = v3779;
      int * v3678 = v3645->cache_age;
      int v3679 = v3678[v3763];
      int v3781 = v3679 + ((int)((unsigned int)(v3679 - v3675) >> 31));
      v3678[v3763] = v3781;
      int * v3681 = v3645->cache_age;
      v3681[v3778] = 0;
      v3727 = v3778;
    } else {
      int * v3684 = v3645->cache_age;
      int v3785 = 4 + ((((int)((unsigned int)((int)((unsigned int)v3649 >> 2)) >> 1)) & 3) * 2);
      int v3685 = v3684[v3785];
      int * v3686 = v3645->cache_tags;
      int v3687 = v3686[v3785];
      int v3688 = v3684[v3763];
      int v3689 = v3686[v3763];
      int * v3690 = v3645->cache_dirty;
      int v3788 = (4 + ((((int)((unsigned int)((int)((unsigned int)v3649 >> 2)) >> 1)) & 3) * 2)) + ((((v3685 + ((~(((v3687 ^ -1) | (-(v3687 ^ -1))) >> 31)) & 2)) - (v3688 + ((~(((v3689 ^ -1) | (-(v3689 ^ -1))) >> 31)) & 2))) >> 31) & 1);
      int v3691 = v3690[v3788];
      bool v3789 = !(v3691 == 0);
      if (v3789) {
        int * v3692 = v3645->cache_tags;
        int v3693 = v3692[v3788];
        int * v3694 = v3645->cache_vals;
        int v3792 = ((4 + ((((int)((unsigned int)((int)((unsigned int)v3649 >> 2)) >> 1)) & 3) * 2)) + ((((v3685 + ((~(((v3687 ^ -1) | (-(v3687 ^ -1))) >> 31)) & 2)) - (v3688 + ((~(((v3689 ^ -1) | (-(v3689 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
        int v3695 = v3694[v3792];
        int v3793 = (((4 + ((((int)((unsigned int)((int)((unsigned int)v3649 >> 2)) >> 1)) & 3) * 2)) + ((((v3685 + ((~(((v3687 ^ -1) | (-(v3687 ^ -1))) >> 31)) & 2)) - (v3688 + ((~(((v3689 ^ -1) | (-(v3689 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
        int v3696 = v3694[v3793];
        int * v3697 = v3645->mem;
        int v3795 = v3693 * 2;
        v3697[v3795] = v3695;
        int * v3699 = v3645->mem;
        int v3798 = (v3693 * 2) + 1;
        v3699[v3798] = v3696;
        ;
      } else {
        ;
      }
      int * v3704 = v3645->mem;
      int v3803 = ((int)((unsigned int)((int)((unsigned int)v3649 >> 2)) >> 1)) * 2;
      int v3705 = v3704[v3803];
      int v3804 = (((int)((unsigned int)((int)((unsigned int)v3649 >> 2)) >> 1)) * 2) + 1;
      int v3706 = v3704[v3804];
      int * v3707 = v3645->cache_vals;
      int v3806 = ((4 + ((((int)((unsigned int)((int)((unsigned int)v3649 >> 2)) >> 1)) & 3) * 2)) + ((((v3685 + ((~(((v3687 ^ -1) | (-(v3687 ^ -1))) >> 31)) & 2)) - (v3688 + ((~(((v3689 ^ -1) | (-(v3689 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
      v3707[v3806] = v3705;
      int * v3709 = v3645->cache_vals;
      int v3809 = (((4 + ((((int)((unsigned int)((int)((unsigned int)v3649 >> 2)) >> 1)) & 3) * 2)) + ((((v3685 + ((~(((v3687 ^ -1) | (-(v3687 ^ -1))) >> 31)) & 2)) - (v3688 + ((~(((v3689 ^ -1) | (-(v3689 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
      v3709[v3809] = v3706;
      int * v3711 = v3645->cache_tags;
      int v3812 = (int)((unsigned int)((int)((unsigned int)v3649 >> 2)) >> 1);
      v3711[v3788] = v3812;
      int * v3713 = v3645->cache_dirty;
      v3713[v3788] = 0;
      int * v3715 = v3645->cache_age;
      v3715[v3788] = 1;
      int * v3717 = v3645->cache_age;
      int v3718 = v3717[v3788];
      int v3719 = v3717[v3762];
      int v3818 = v3719 + ((int)((unsigned int)(v3719 - v3718) >> 31));
      v3717[v3762] = v3818;
      int * v3721 = v3645->cache_age;
      int v3722 = v3721[v3763];
      int v3820 = v3722 + ((int)((unsigned int)(v3722 - v3718) >> 31));
      v3721[v3763] = v3820;
      int * v3724 = v3645->cache_age;
      v3724[v3788] = 0;
      v3727 = v3788;
    }
    int * v3728 = v3645->cache_vals;
    int v3823 = v3727 * 2;
    int v3729 = v3728[v3823];
    int v3824 = (v3727 * 2) + 1;
    int v3730 = v3728[v3824];
    int v3825 = (((((int)((unsigned int)((int)((unsigned int)v3649 >> 2)) >> 1)) & 1) * 2) + ((((v3669 + ((~(((v3671 ^ -1) | (-(v3671 ^ -1))) >> 31)) & 2)) - (v3672 + ((~(((v3673 ^ -1) | (-(v3673 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
    v3728[v3825] = v3729;
    int * v3732 = v3645->cache_vals;
    int v3828 = ((((((int)((unsigned int)((int)((unsigned int)v3649 >> 2)) >> 1)) & 1) * 2) + ((((v3669 + ((~(((v3671 ^ -1) | (-(v3671 ^ -1))) >> 31)) & 2)) - (v3672 + ((~(((v3673 ^ -1) | (-(v3673 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
    v3732[v3828] = v3730;
    int * v3734 = v3645->cache_tags;
    int v3831 = ((((int)((unsigned int)((int)((unsigned int)v3649 >> 2)) >> 1)) & 1) * 2) + ((((v3669 + ((~(((v3671 ^ -1) | (-(v3671 ^ -1))) >> 31)) & 2)) - (v3672 + ((~(((v3673 ^ -1) | (-(v3673 ^ -1))) >> 31)) & 2))) >> 31) & 1);
    int v3832 = (int)((unsigned int)((int)((unsigned int)v3649 >> 2)) >> 1);
    v3734[v3831] = v3832;
    int * v3736 = v3645->cache_dirty;
    v3736[v3831] = 0;
    int * v3738 = v3645->cache_age;
    v3738[v3831] = 1;
    int * v3740 = v3645->cache_age;
    int v3741 = v3740[v3831];
    int v3742 = v3740[v3760];
    int v3838 = v3742 + ((int)((unsigned int)(v3742 - v3741) >> 31));
    v3740[v3760] = v3838;
    int * v3744 = v3645->cache_age;
    int v3745 = v3744[v3761];
    int v3840 = v3745 + ((int)((unsigned int)(v3745 - v3741) >> 31));
    v3744[v3761] = v3840;
    int * v3747 = v3645->cache_age;
    v3747[v3831] = 0;
    v3750 = v3831;
  }
  int v3843 = (v3750 * 2) + (((int)((unsigned int)v3649 >> 2)) & 1);
  int v3751 = v3657[v3843];
  int * v3752 = v3645->regs;
  v3752[7] = v3751;
  struct StateT * v3754 = slot_45(v3645);
  return v3754;
}

struct StateT * slot_28(struct StateT * v2231) {
  int v2232 = v2231->timer;
  int v2240 = v2232 + 1;
  v2231->timer = v2240;
  int * v2234 = v2231->regs;
  int v2235 = v2234[17];
  int v2236 = v2234[6];
  int v2244 = v2235 ^ v2236;
  v2234[17] = v2244;
  struct StateT * v2238 = slot_29(v2231);
  return v2238;
}

struct StateT * slot_32(struct StateT * v2295) {
  int v2296 = v2295->timer;
  int v2304 = v2296 + 1;
  v2295->timer = v2304;
  int * v2298 = v2295->regs;
  int v2299 = v2298[6];
  int v2300 = v2298[17];
  int v2308 = v2299 ^ v2300;
  v2298[17] = v2308;
  struct StateT * v2302 = slot_33(v2295);
  return v2302;
}

struct StateT * slot_17(struct StateT * v1056) {
  int v1057 = v1056->timer;
  int v1065 = v1057 + 1;
  v1056->timer = v1065;
  int * v1059 = v1056->regs;
  int v1060 = v1059[13];
  int v1061 = v1059[6];
  int v1069 = v1060 & v1061;
  v1059[6] = v1069;
  struct StateT * v1063 = slot_18(v1056);
  return v1063;
}

struct StateT * slot_49(struct StateT * v3913) {
  int v3914 = v3913->timer;
  int v3922 = v3914 + 1;
  v3913->timer = v3922;
  int * v3916 = v3913->regs;
  int v3917 = v3916[5];
  int v3918 = v3916[6];
  int v3926 = v3917 ^ v3918;
  v3916[6] = v3926;
  struct StateT * v3920 = slot_50(v3913);
  return v3920;
}

struct StateT * slot_33(struct StateT * v2311) {
  int v2312 = v2311->timer;
  int v2482 = v2312 + 1;
  v2311->timer = v2482;
  int * v2314 = v2311->regs;
  int v2315 = v2314[15];
  int v2316 = v2314[17];
  int * v2317 = v2311->cache_tags;
  int v2487 = (((int)((unsigned int)((int)((unsigned int)v2315 >> 2)) >> 1)) & 1) * 2;
  int v2318 = v2317[v2487];
  int v2488 = ((((int)((unsigned int)((int)((unsigned int)v2315 >> 2)) >> 1)) & 1) * 2) + 1;
  int v2319 = v2317[v2488];
  int v2489 = 4 + ((((int)((unsigned int)((int)((unsigned int)v2315 >> 2)) >> 1)) & 3) * 2);
  int v2320 = v2317[v2489];
  int v2490 = (4 + ((((int)((unsigned int)((int)((unsigned int)v2315 >> 2)) >> 1)) & 3) * 2)) + 1;
  int v2321 = v2317[v2490];
  int v2322 = v2311->timer;
  int v2491 = v2322 + ((100 ^ (((~(((v2320 ^ ((int)((unsigned int)((int)((unsigned int)v2315 >> 2)) >> 1))) | (-(v2320 ^ ((int)((unsigned int)((int)((unsigned int)v2315 >> 2)) >> 1))))) >> 31)) | (~(((v2321 ^ ((int)((unsigned int)((int)((unsigned int)v2315 >> 2)) >> 1))) | (-(v2321 ^ ((int)((unsigned int)((int)((unsigned int)v2315 >> 2)) >> 1))))) >> 31))) & 104)) ^ (((~(((v2318 ^ ((int)((unsigned int)((int)((unsigned int)v2315 >> 2)) >> 1))) | (-(v2318 ^ ((int)((unsigned int)((int)((unsigned int)v2315 >> 2)) >> 1))))) >> 31)) | (~(((v2319 ^ ((int)((unsigned int)((int)((unsigned int)v2315 >> 2)) >> 1))) | (-(v2319 ^ ((int)((unsigned int)((int)((unsigned int)v2315 >> 2)) >> 1))))) >> 31))) & (1 ^ (100 ^ (((~(((v2320 ^ ((int)((unsigned int)((int)((unsigned int)v2315 >> 2)) >> 1))) | (-(v2320 ^ ((int)((unsigned int)((int)((unsigned int)v2315 >> 2)) >> 1))))) >> 31)) | (~(((v2321 ^ ((int)((unsigned int)((int)((unsigned int)v2315 >> 2)) >> 1))) | (-(v2321 ^ ((int)((unsigned int)((int)((unsigned int)v2315 >> 2)) >> 1))))) >> 31))) & 104)))));
  v2311->timer = v2491;
  bool v2492 = !(((~(((v2318 ^ ((int)((unsigned int)((int)((unsigned int)v2315 >> 2)) >> 1))) | (-(v2318 ^ ((int)((unsigned int)((int)((unsigned int)v2315 >> 2)) >> 1))))) >> 31)) | (~(((v2319 ^ ((int)((unsigned int)((int)((unsigned int)v2315 >> 2)) >> 1))) | (-(v2319 ^ ((int)((unsigned int)((int)((unsigned int)v2315 >> 2)) >> 1))))) >> 31))) == 0);
  int v2416;
  if (v2492) {
    int * v2324 = v2311->cache_age;
    int v2494 = ((((int)((unsigned int)((int)((unsigned int)v2315 >> 2)) >> 1)) & 1) * 2) + ((~(((v2319 ^ ((int)((unsigned int)((int)((unsigned int)v2315 >> 2)) >> 1))) | (-(v2319 ^ ((int)((unsigned int)((int)((unsigned int)v2315 >> 2)) >> 1))))) >> 31)) & 1);
    int v2325 = v2324[v2494];
    int v2326 = v2324[v2487];
    int v2495 = v2326 + ((int)((unsigned int)(v2326 - v2325) >> 31));
    v2324[v2487] = v2495;
    int * v2328 = v2311->cache_age;
    int v2329 = v2328[v2488];
    int v2497 = v2329 + ((int)((unsigned int)(v2329 - v2325) >> 31));
    v2328[v2488] = v2497;
    int * v2331 = v2311->cache_age;
    v2331[v2494] = 0;
    v2416 = v2494;
  } else {
    int * v2334 = v2311->cache_age;
    int v2501 = (((int)((unsigned int)((int)((unsigned int)v2315 >> 2)) >> 1)) & 1) * 2;
    int v2335 = v2334[v2501];
    int * v2336 = v2311->cache_tags;
    int v2337 = v2336[v2501];
    int v2338 = v2334[v2488];
    int v2339 = v2336[v2488];
    bool v2503 = !(((~(((v2320 ^ ((int)((unsigned int)((int)((unsigned int)v2315 >> 2)) >> 1))) | (-(v2320 ^ ((int)((unsigned int)((int)((unsigned int)v2315 >> 2)) >> 1))))) >> 31)) | (~(((v2321 ^ ((int)((unsigned int)((int)((unsigned int)v2315 >> 2)) >> 1))) | (-(v2321 ^ ((int)((unsigned int)((int)((unsigned int)v2315 >> 2)) >> 1))))) >> 31))) == 0);
    int v2393;
    if (v2503) {
      int * v2340 = v2311->cache_age;
      int v2505 = (4 + ((((int)((unsigned int)((int)((unsigned int)v2315 >> 2)) >> 1)) & 3) * 2)) + ((~(((v2321 ^ ((int)((unsigned int)((int)((unsigned int)v2315 >> 2)) >> 1))) | (-(v2321 ^ ((int)((unsigned int)((int)((unsigned int)v2315 >> 2)) >> 1))))) >> 31)) & 1);
      int v2341 = v2340[v2505];
      int v2342 = v2340[v2489];
      int v2506 = v2342 + ((int)((unsigned int)(v2342 - v2341) >> 31));
      v2340[v2489] = v2506;
      int * v2344 = v2311->cache_age;
      int v2345 = v2344[v2490];
      int v2508 = v2345 + ((int)((unsigned int)(v2345 - v2341) >> 31));
      v2344[v2490] = v2508;
      int * v2347 = v2311->cache_age;
      v2347[v2505] = 0;
      v2393 = v2505;
    } else {
      int * v2350 = v2311->cache_age;
      int v2512 = 4 + ((((int)((unsigned int)((int)((unsigned int)v2315 >> 2)) >> 1)) & 3) * 2);
      int v2351 = v2350[v2512];
      int * v2352 = v2311->cache_tags;
      int v2353 = v2352[v2512];
      int v2354 = v2350[v2490];
      int v2355 = v2352[v2490];
      int * v2356 = v2311->cache_dirty;
      int v2515 = (4 + ((((int)((unsigned int)((int)((unsigned int)v2315 >> 2)) >> 1)) & 3) * 2)) + ((((v2351 + ((~(((v2353 ^ -1) | (-(v2353 ^ -1))) >> 31)) & 2)) - (v2354 + ((~(((v2355 ^ -1) | (-(v2355 ^ -1))) >> 31)) & 2))) >> 31) & 1);
      int v2357 = v2356[v2515];
      bool v2516 = !(v2357 == 0);
      if (v2516) {
        int * v2358 = v2311->cache_tags;
        int v2359 = v2358[v2515];
        int * v2360 = v2311->cache_vals;
        int v2519 = ((4 + ((((int)((unsigned int)((int)((unsigned int)v2315 >> 2)) >> 1)) & 3) * 2)) + ((((v2351 + ((~(((v2353 ^ -1) | (-(v2353 ^ -1))) >> 31)) & 2)) - (v2354 + ((~(((v2355 ^ -1) | (-(v2355 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
        int v2361 = v2360[v2519];
        int v2520 = (((4 + ((((int)((unsigned int)((int)((unsigned int)v2315 >> 2)) >> 1)) & 3) * 2)) + ((((v2351 + ((~(((v2353 ^ -1) | (-(v2353 ^ -1))) >> 31)) & 2)) - (v2354 + ((~(((v2355 ^ -1) | (-(v2355 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
        int v2362 = v2360[v2520];
        int * v2363 = v2311->mem;
        int v2522 = v2359 * 2;
        v2363[v2522] = v2361;
        int * v2365 = v2311->mem;
        int v2525 = (v2359 * 2) + 1;
        v2365[v2525] = v2362;
        ;
      } else {
        ;
      }
      int * v2370 = v2311->mem;
      int v2530 = ((int)((unsigned int)((int)((unsigned int)v2315 >> 2)) >> 1)) * 2;
      int v2371 = v2370[v2530];
      int v2531 = (((int)((unsigned int)((int)((unsigned int)v2315 >> 2)) >> 1)) * 2) + 1;
      int v2372 = v2370[v2531];
      int * v2373 = v2311->cache_vals;
      int v2533 = ((4 + ((((int)((unsigned int)((int)((unsigned int)v2315 >> 2)) >> 1)) & 3) * 2)) + ((((v2351 + ((~(((v2353 ^ -1) | (-(v2353 ^ -1))) >> 31)) & 2)) - (v2354 + ((~(((v2355 ^ -1) | (-(v2355 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
      v2373[v2533] = v2371;
      int * v2375 = v2311->cache_vals;
      int v2536 = (((4 + ((((int)((unsigned int)((int)((unsigned int)v2315 >> 2)) >> 1)) & 3) * 2)) + ((((v2351 + ((~(((v2353 ^ -1) | (-(v2353 ^ -1))) >> 31)) & 2)) - (v2354 + ((~(((v2355 ^ -1) | (-(v2355 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
      v2375[v2536] = v2372;
      int * v2377 = v2311->cache_tags;
      int v2539 = (int)((unsigned int)((int)((unsigned int)v2315 >> 2)) >> 1);
      v2377[v2515] = v2539;
      int * v2379 = v2311->cache_dirty;
      v2379[v2515] = 0;
      int * v2381 = v2311->cache_age;
      v2381[v2515] = 1;
      int * v2383 = v2311->cache_age;
      int v2384 = v2383[v2515];
      int v2385 = v2383[v2489];
      int v2545 = v2385 + ((int)((unsigned int)(v2385 - v2384) >> 31));
      v2383[v2489] = v2545;
      int * v2387 = v2311->cache_age;
      int v2388 = v2387[v2490];
      int v2547 = v2388 + ((int)((unsigned int)(v2388 - v2384) >> 31));
      v2387[v2490] = v2547;
      int * v2390 = v2311->cache_age;
      v2390[v2515] = 0;
      v2393 = v2515;
    }
    int * v2394 = v2311->cache_vals;
    int v2550 = v2393 * 2;
    int v2395 = v2394[v2550];
    int v2551 = (v2393 * 2) + 1;
    int v2396 = v2394[v2551];
    int v2552 = (((((int)((unsigned int)((int)((unsigned int)v2315 >> 2)) >> 1)) & 1) * 2) + ((((v2335 + ((~(((v2337 ^ -1) | (-(v2337 ^ -1))) >> 31)) & 2)) - (v2338 + ((~(((v2339 ^ -1) | (-(v2339 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
    v2394[v2552] = v2395;
    int * v2398 = v2311->cache_vals;
    int v2555 = ((((((int)((unsigned int)((int)((unsigned int)v2315 >> 2)) >> 1)) & 1) * 2) + ((((v2335 + ((~(((v2337 ^ -1) | (-(v2337 ^ -1))) >> 31)) & 2)) - (v2338 + ((~(((v2339 ^ -1) | (-(v2339 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
    v2398[v2555] = v2396;
    int * v2400 = v2311->cache_tags;
    int v2558 = ((((int)((unsigned int)((int)((unsigned int)v2315 >> 2)) >> 1)) & 1) * 2) + ((((v2335 + ((~(((v2337 ^ -1) | (-(v2337 ^ -1))) >> 31)) & 2)) - (v2338 + ((~(((v2339 ^ -1) | (-(v2339 ^ -1))) >> 31)) & 2))) >> 31) & 1);
    int v2559 = (int)((unsigned int)((int)((unsigned int)v2315 >> 2)) >> 1);
    v2400[v2558] = v2559;
    int * v2402 = v2311->cache_dirty;
    v2402[v2558] = 0;
    int * v2404 = v2311->cache_age;
    v2404[v2558] = 1;
    int * v2406 = v2311->cache_age;
    int v2407 = v2406[v2558];
    int v2408 = v2406[v2487];
    int v2565 = v2408 + ((int)((unsigned int)(v2408 - v2407) >> 31));
    v2406[v2487] = v2565;
    int * v2410 = v2311->cache_age;
    int v2411 = v2410[v2488];
    int v2567 = v2411 + ((int)((unsigned int)(v2411 - v2407) >> 31));
    v2410[v2488] = v2567;
    int * v2413 = v2311->cache_age;
    v2413[v2558] = 0;
    v2416 = v2558;
  }
  int * v2417 = v2311->cache_vals;
  int v2570 = (v2416 * 2) + (((int)((unsigned int)v2315 >> 2)) & 1);
  v2417[v2570] = v2316;
  int * v2419 = v2311->cache_tags;
  int v2420 = v2419[v2489];
  int v2421 = v2419[v2490];
  bool v2573 = !(((~(((v2420 ^ ((int)((unsigned int)((int)((unsigned int)v2315 >> 2)) >> 1))) | (-(v2420 ^ ((int)((unsigned int)((int)((unsigned int)v2315 >> 2)) >> 1))))) >> 31)) | (~(((v2421 ^ ((int)((unsigned int)((int)((unsigned int)v2315 >> 2)) >> 1))) | (-(v2421 ^ ((int)((unsigned int)((int)((unsigned int)v2315 >> 2)) >> 1))))) >> 31))) == 0);
  int v2475;
  if (v2573) {
    int * v2422 = v2311->cache_age;
    int v2575 = (4 + ((((int)((unsigned int)((int)((unsigned int)v2315 >> 2)) >> 1)) & 3) * 2)) + ((~(((v2421 ^ ((int)((unsigned int)((int)((unsigned int)v2315 >> 2)) >> 1))) | (-(v2421 ^ ((int)((unsigned int)((int)((unsigned int)v2315 >> 2)) >> 1))))) >> 31)) & 1);
    int v2423 = v2422[v2575];
    int v2424 = v2422[v2489];
    int v2576 = v2424 + ((int)((unsigned int)(v2424 - v2423) >> 31));
    v2422[v2489] = v2576;
    int * v2426 = v2311->cache_age;
    int v2427 = v2426[v2490];
    int v2578 = v2427 + ((int)((unsigned int)(v2427 - v2423) >> 31));
    v2426[v2490] = v2578;
    int * v2429 = v2311->cache_age;
    v2429[v2575] = 0;
    v2475 = v2575;
  } else {
    int * v2432 = v2311->cache_age;
    int v2582 = 4 + ((((int)((unsigned int)((int)((unsigned int)v2315 >> 2)) >> 1)) & 3) * 2);
    int v2433 = v2432[v2582];
    int * v2434 = v2311->cache_tags;
    int v2435 = v2434[v2582];
    int v2436 = v2432[v2490];
    int v2437 = v2434[v2490];
    int * v2438 = v2311->cache_dirty;
    int v2585 = (4 + ((((int)((unsigned int)((int)((unsigned int)v2315 >> 2)) >> 1)) & 3) * 2)) + ((((v2433 + ((~(((v2435 ^ -1) | (-(v2435 ^ -1))) >> 31)) & 2)) - (v2436 + ((~(((v2437 ^ -1) | (-(v2437 ^ -1))) >> 31)) & 2))) >> 31) & 1);
    int v2439 = v2438[v2585];
    bool v2586 = !(v2439 == 0);
    if (v2586) {
      int * v2440 = v2311->cache_tags;
      int v2441 = v2440[v2585];
      int * v2442 = v2311->cache_vals;
      int v2589 = ((4 + ((((int)((unsigned int)((int)((unsigned int)v2315 >> 2)) >> 1)) & 3) * 2)) + ((((v2433 + ((~(((v2435 ^ -1) | (-(v2435 ^ -1))) >> 31)) & 2)) - (v2436 + ((~(((v2437 ^ -1) | (-(v2437 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
      int v2443 = v2442[v2589];
      int v2590 = (((4 + ((((int)((unsigned int)((int)((unsigned int)v2315 >> 2)) >> 1)) & 3) * 2)) + ((((v2433 + ((~(((v2435 ^ -1) | (-(v2435 ^ -1))) >> 31)) & 2)) - (v2436 + ((~(((v2437 ^ -1) | (-(v2437 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
      int v2444 = v2442[v2590];
      int * v2445 = v2311->mem;
      int v2592 = v2441 * 2;
      v2445[v2592] = v2443;
      int * v2447 = v2311->mem;
      int v2595 = (v2441 * 2) + 1;
      v2447[v2595] = v2444;
      ;
    } else {
      ;
    }
    int * v2452 = v2311->mem;
    int v2600 = ((int)((unsigned int)((int)((unsigned int)v2315 >> 2)) >> 1)) * 2;
    int v2453 = v2452[v2600];
    int v2601 = (((int)((unsigned int)((int)((unsigned int)v2315 >> 2)) >> 1)) * 2) + 1;
    int v2454 = v2452[v2601];
    int * v2455 = v2311->cache_vals;
    int v2603 = ((4 + ((((int)((unsigned int)((int)((unsigned int)v2315 >> 2)) >> 1)) & 3) * 2)) + ((((v2433 + ((~(((v2435 ^ -1) | (-(v2435 ^ -1))) >> 31)) & 2)) - (v2436 + ((~(((v2437 ^ -1) | (-(v2437 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
    v2455[v2603] = v2453;
    int * v2457 = v2311->cache_vals;
    int v2606 = (((4 + ((((int)((unsigned int)((int)((unsigned int)v2315 >> 2)) >> 1)) & 3) * 2)) + ((((v2433 + ((~(((v2435 ^ -1) | (-(v2435 ^ -1))) >> 31)) & 2)) - (v2436 + ((~(((v2437 ^ -1) | (-(v2437 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
    v2457[v2606] = v2454;
    int * v2459 = v2311->cache_tags;
    int v2609 = (int)((unsigned int)((int)((unsigned int)v2315 >> 2)) >> 1);
    v2459[v2585] = v2609;
    int * v2461 = v2311->cache_dirty;
    v2461[v2585] = 0;
    int * v2463 = v2311->cache_age;
    v2463[v2585] = 1;
    int * v2465 = v2311->cache_age;
    int v2466 = v2465[v2585];
    int v2467 = v2465[v2489];
    int v2615 = v2467 + ((int)((unsigned int)(v2467 - v2466) >> 31));
    v2465[v2489] = v2615;
    int * v2469 = v2311->cache_age;
    int v2470 = v2469[v2490];
    int v2617 = v2470 + ((int)((unsigned int)(v2470 - v2466) >> 31));
    v2469[v2490] = v2617;
    int * v2472 = v2311->cache_age;
    v2472[v2585] = 0;
    v2475 = v2585;
  }
  int * v2476 = v2311->cache_vals;
  int v2620 = (v2475 * 2) + (((int)((unsigned int)v2315 >> 2)) & 1);
  v2476[v2620] = v2316;
  int * v2478 = v2311->cache_dirty;
  v2478[v2475] = 1;
  struct StateT * v2480 = slot_34(v2311);
  return v2480;
}

struct StateT * slot_50(struct StateT * v3929) {
  int v3930 = v3929->timer;
  int v3938 = v3930 + 1;
  v3929->timer = v3938;
  int * v3932 = v3929->regs;
  int v3933 = v3932[17];
  int v3934 = v3932[7];
  int v3942 = v3933 ^ v3934;
  v3932[7] = v3942;
  struct StateT * v3936 = slot_22(v3929);
  return v3936;
}

struct StateT * slot_36(struct StateT * v2955) {
  int v2956 = v2955->timer;
  int v2960 = v2956 + 1;
  v2955->timer = v2960;
  struct StateT * v2958 = slot_37(v2955);
  return v2958;
}

struct StateT * slot_37(struct StateT * v2963) {
  int * v2964 = v2963->regs;
  int v2965 = v2964[12];
  int v2966 = v2964[14];
  bool v2978 = (v2965 ^ -2147483648) >= (v2966 ^ -2147483648);
  struct StateT * v2973;
  if (v2978) {
    int v2967 = v2963->timer;
    int v2979 = v2967 + 15;
    v2963->timer = v2979;
    struct StateT * v2969 = slot_38(v2963);
    v2973 = v2969;
  } else {
    struct StateT * v2971 = slot_21(v2963);
    v2973 = v2971;
  }
  return v2973;
}

struct StateT * slot_40(struct StateT * v3017) {
  int v3018 = v3017->timer;
  int v3026 = v3018 + 1;
  v3017->timer = v3026;
  int * v3020 = v3017->regs;
  int v3021 = v3020[11];
  int v3022 = v3020[15];
  int v3030 = v3021 + v3022;
  v3020[15] = v3030;
  struct StateT * v3024 = slot_41(v3017);
  return v3024;
}

struct StateT * slot_27(struct StateT * v2215) {
  int v2216 = v2215->timer;
  int v2224 = v2216 + 1;
  v2215->timer = v2224;
  int * v2218 = v2215->regs;
  int v2219 = v2218[5];
  int v2220 = v2218[16];
  int v2228 = v2219 ^ v2220;
  v2218[5] = v2228;
  struct StateT * v2222 = slot_28(v2215);
  return v2222;
}

struct StateT * slot_15(struct StateT * v1024) {
  int v1025 = v1024->timer;
  int v1033 = v1025 + 1;
  v1024->timer = v1033;
  int * v1027 = v1024->regs;
  int v1028 = v1027[7];
  int v1029 = v1027[17];
  int v1037 = v1028 ^ v1029;
  v1027[7] = v1037;
  struct StateT * v1031 = slot_16(v1024);
  return v1031;
}

struct StateT * slot_48(struct StateT * v3897) {
  int v3898 = v3897->timer;
  int v3906 = v3898 + 1;
  v3897->timer = v3906;
  int * v3900 = v3897->regs;
  int v3901 = v3900[13];
  int v3902 = v3900[6];
  int v3910 = v3901 & v3902;
  v3900[6] = v3910;
  struct StateT * v3904 = slot_49(v3897);
  return v3904;
}

struct StateT * slot_22(struct StateT * v1177) {
  int v1178 = v1177->timer;
  int v1348 = v1178 + 1;
  v1177->timer = v1348;
  int * v1180 = v1177->regs;
  int v1181 = v1180[16];
  int v1182 = v1180[7];
  int * v1183 = v1177->cache_tags;
  int v1353 = (((int)((unsigned int)((int)((unsigned int)v1181 >> 2)) >> 1)) & 1) * 2;
  int v1184 = v1183[v1353];
  int v1354 = ((((int)((unsigned int)((int)((unsigned int)v1181 >> 2)) >> 1)) & 1) * 2) + 1;
  int v1185 = v1183[v1354];
  int v1355 = 4 + ((((int)((unsigned int)((int)((unsigned int)v1181 >> 2)) >> 1)) & 3) * 2);
  int v1186 = v1183[v1355];
  int v1356 = (4 + ((((int)((unsigned int)((int)((unsigned int)v1181 >> 2)) >> 1)) & 3) * 2)) + 1;
  int v1187 = v1183[v1356];
  int v1188 = v1177->timer;
  int v1357 = v1188 + ((100 ^ (((~(((v1186 ^ ((int)((unsigned int)((int)((unsigned int)v1181 >> 2)) >> 1))) | (-(v1186 ^ ((int)((unsigned int)((int)((unsigned int)v1181 >> 2)) >> 1))))) >> 31)) | (~(((v1187 ^ ((int)((unsigned int)((int)((unsigned int)v1181 >> 2)) >> 1))) | (-(v1187 ^ ((int)((unsigned int)((int)((unsigned int)v1181 >> 2)) >> 1))))) >> 31))) & 104)) ^ (((~(((v1184 ^ ((int)((unsigned int)((int)((unsigned int)v1181 >> 2)) >> 1))) | (-(v1184 ^ ((int)((unsigned int)((int)((unsigned int)v1181 >> 2)) >> 1))))) >> 31)) | (~(((v1185 ^ ((int)((unsigned int)((int)((unsigned int)v1181 >> 2)) >> 1))) | (-(v1185 ^ ((int)((unsigned int)((int)((unsigned int)v1181 >> 2)) >> 1))))) >> 31))) & (1 ^ (100 ^ (((~(((v1186 ^ ((int)((unsigned int)((int)((unsigned int)v1181 >> 2)) >> 1))) | (-(v1186 ^ ((int)((unsigned int)((int)((unsigned int)v1181 >> 2)) >> 1))))) >> 31)) | (~(((v1187 ^ ((int)((unsigned int)((int)((unsigned int)v1181 >> 2)) >> 1))) | (-(v1187 ^ ((int)((unsigned int)((int)((unsigned int)v1181 >> 2)) >> 1))))) >> 31))) & 104)))));
  v1177->timer = v1357;
  bool v1358 = !(((~(((v1184 ^ ((int)((unsigned int)((int)((unsigned int)v1181 >> 2)) >> 1))) | (-(v1184 ^ ((int)((unsigned int)((int)((unsigned int)v1181 >> 2)) >> 1))))) >> 31)) | (~(((v1185 ^ ((int)((unsigned int)((int)((unsigned int)v1181 >> 2)) >> 1))) | (-(v1185 ^ ((int)((unsigned int)((int)((unsigned int)v1181 >> 2)) >> 1))))) >> 31))) == 0);
  int v1282;
  if (v1358) {
    int * v1190 = v1177->cache_age;
    int v1360 = ((((int)((unsigned int)((int)((unsigned int)v1181 >> 2)) >> 1)) & 1) * 2) + ((~(((v1185 ^ ((int)((unsigned int)((int)((unsigned int)v1181 >> 2)) >> 1))) | (-(v1185 ^ ((int)((unsigned int)((int)((unsigned int)v1181 >> 2)) >> 1))))) >> 31)) & 1);
    int v1191 = v1190[v1360];
    int v1192 = v1190[v1353];
    int v1361 = v1192 + ((int)((unsigned int)(v1192 - v1191) >> 31));
    v1190[v1353] = v1361;
    int * v1194 = v1177->cache_age;
    int v1195 = v1194[v1354];
    int v1363 = v1195 + ((int)((unsigned int)(v1195 - v1191) >> 31));
    v1194[v1354] = v1363;
    int * v1197 = v1177->cache_age;
    v1197[v1360] = 0;
    v1282 = v1360;
  } else {
    int * v1200 = v1177->cache_age;
    int v1367 = (((int)((unsigned int)((int)((unsigned int)v1181 >> 2)) >> 1)) & 1) * 2;
    int v1201 = v1200[v1367];
    int * v1202 = v1177->cache_tags;
    int v1203 = v1202[v1367];
    int v1204 = v1200[v1354];
    int v1205 = v1202[v1354];
    bool v1369 = !(((~(((v1186 ^ ((int)((unsigned int)((int)((unsigned int)v1181 >> 2)) >> 1))) | (-(v1186 ^ ((int)((unsigned int)((int)((unsigned int)v1181 >> 2)) >> 1))))) >> 31)) | (~(((v1187 ^ ((int)((unsigned int)((int)((unsigned int)v1181 >> 2)) >> 1))) | (-(v1187 ^ ((int)((unsigned int)((int)((unsigned int)v1181 >> 2)) >> 1))))) >> 31))) == 0);
    int v1259;
    if (v1369) {
      int * v1206 = v1177->cache_age;
      int v1371 = (4 + ((((int)((unsigned int)((int)((unsigned int)v1181 >> 2)) >> 1)) & 3) * 2)) + ((~(((v1187 ^ ((int)((unsigned int)((int)((unsigned int)v1181 >> 2)) >> 1))) | (-(v1187 ^ ((int)((unsigned int)((int)((unsigned int)v1181 >> 2)) >> 1))))) >> 31)) & 1);
      int v1207 = v1206[v1371];
      int v1208 = v1206[v1355];
      int v1372 = v1208 + ((int)((unsigned int)(v1208 - v1207) >> 31));
      v1206[v1355] = v1372;
      int * v1210 = v1177->cache_age;
      int v1211 = v1210[v1356];
      int v1374 = v1211 + ((int)((unsigned int)(v1211 - v1207) >> 31));
      v1210[v1356] = v1374;
      int * v1213 = v1177->cache_age;
      v1213[v1371] = 0;
      v1259 = v1371;
    } else {
      int * v1216 = v1177->cache_age;
      int v1378 = 4 + ((((int)((unsigned int)((int)((unsigned int)v1181 >> 2)) >> 1)) & 3) * 2);
      int v1217 = v1216[v1378];
      int * v1218 = v1177->cache_tags;
      int v1219 = v1218[v1378];
      int v1220 = v1216[v1356];
      int v1221 = v1218[v1356];
      int * v1222 = v1177->cache_dirty;
      int v1381 = (4 + ((((int)((unsigned int)((int)((unsigned int)v1181 >> 2)) >> 1)) & 3) * 2)) + ((((v1217 + ((~(((v1219 ^ -1) | (-(v1219 ^ -1))) >> 31)) & 2)) - (v1220 + ((~(((v1221 ^ -1) | (-(v1221 ^ -1))) >> 31)) & 2))) >> 31) & 1);
      int v1223 = v1222[v1381];
      bool v1382 = !(v1223 == 0);
      if (v1382) {
        int * v1224 = v1177->cache_tags;
        int v1225 = v1224[v1381];
        int * v1226 = v1177->cache_vals;
        int v1385 = ((4 + ((((int)((unsigned int)((int)((unsigned int)v1181 >> 2)) >> 1)) & 3) * 2)) + ((((v1217 + ((~(((v1219 ^ -1) | (-(v1219 ^ -1))) >> 31)) & 2)) - (v1220 + ((~(((v1221 ^ -1) | (-(v1221 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
        int v1227 = v1226[v1385];
        int v1386 = (((4 + ((((int)((unsigned int)((int)((unsigned int)v1181 >> 2)) >> 1)) & 3) * 2)) + ((((v1217 + ((~(((v1219 ^ -1) | (-(v1219 ^ -1))) >> 31)) & 2)) - (v1220 + ((~(((v1221 ^ -1) | (-(v1221 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
        int v1228 = v1226[v1386];
        int * v1229 = v1177->mem;
        int v1388 = v1225 * 2;
        v1229[v1388] = v1227;
        int * v1231 = v1177->mem;
        int v1391 = (v1225 * 2) + 1;
        v1231[v1391] = v1228;
        ;
      } else {
        ;
      }
      int * v1236 = v1177->mem;
      int v1396 = ((int)((unsigned int)((int)((unsigned int)v1181 >> 2)) >> 1)) * 2;
      int v1237 = v1236[v1396];
      int v1397 = (((int)((unsigned int)((int)((unsigned int)v1181 >> 2)) >> 1)) * 2) + 1;
      int v1238 = v1236[v1397];
      int * v1239 = v1177->cache_vals;
      int v1399 = ((4 + ((((int)((unsigned int)((int)((unsigned int)v1181 >> 2)) >> 1)) & 3) * 2)) + ((((v1217 + ((~(((v1219 ^ -1) | (-(v1219 ^ -1))) >> 31)) & 2)) - (v1220 + ((~(((v1221 ^ -1) | (-(v1221 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
      v1239[v1399] = v1237;
      int * v1241 = v1177->cache_vals;
      int v1402 = (((4 + ((((int)((unsigned int)((int)((unsigned int)v1181 >> 2)) >> 1)) & 3) * 2)) + ((((v1217 + ((~(((v1219 ^ -1) | (-(v1219 ^ -1))) >> 31)) & 2)) - (v1220 + ((~(((v1221 ^ -1) | (-(v1221 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
      v1241[v1402] = v1238;
      int * v1243 = v1177->cache_tags;
      int v1405 = (int)((unsigned int)((int)((unsigned int)v1181 >> 2)) >> 1);
      v1243[v1381] = v1405;
      int * v1245 = v1177->cache_dirty;
      v1245[v1381] = 0;
      int * v1247 = v1177->cache_age;
      v1247[v1381] = 1;
      int * v1249 = v1177->cache_age;
      int v1250 = v1249[v1381];
      int v1251 = v1249[v1355];
      int v1411 = v1251 + ((int)((unsigned int)(v1251 - v1250) >> 31));
      v1249[v1355] = v1411;
      int * v1253 = v1177->cache_age;
      int v1254 = v1253[v1356];
      int v1413 = v1254 + ((int)((unsigned int)(v1254 - v1250) >> 31));
      v1253[v1356] = v1413;
      int * v1256 = v1177->cache_age;
      v1256[v1381] = 0;
      v1259 = v1381;
    }
    int * v1260 = v1177->cache_vals;
    int v1416 = v1259 * 2;
    int v1261 = v1260[v1416];
    int v1417 = (v1259 * 2) + 1;
    int v1262 = v1260[v1417];
    int v1418 = (((((int)((unsigned int)((int)((unsigned int)v1181 >> 2)) >> 1)) & 1) * 2) + ((((v1201 + ((~(((v1203 ^ -1) | (-(v1203 ^ -1))) >> 31)) & 2)) - (v1204 + ((~(((v1205 ^ -1) | (-(v1205 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
    v1260[v1418] = v1261;
    int * v1264 = v1177->cache_vals;
    int v1421 = ((((((int)((unsigned int)((int)((unsigned int)v1181 >> 2)) >> 1)) & 1) * 2) + ((((v1201 + ((~(((v1203 ^ -1) | (-(v1203 ^ -1))) >> 31)) & 2)) - (v1204 + ((~(((v1205 ^ -1) | (-(v1205 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
    v1264[v1421] = v1262;
    int * v1266 = v1177->cache_tags;
    int v1424 = ((((int)((unsigned int)((int)((unsigned int)v1181 >> 2)) >> 1)) & 1) * 2) + ((((v1201 + ((~(((v1203 ^ -1) | (-(v1203 ^ -1))) >> 31)) & 2)) - (v1204 + ((~(((v1205 ^ -1) | (-(v1205 ^ -1))) >> 31)) & 2))) >> 31) & 1);
    int v1425 = (int)((unsigned int)((int)((unsigned int)v1181 >> 2)) >> 1);
    v1266[v1424] = v1425;
    int * v1268 = v1177->cache_dirty;
    v1268[v1424] = 0;
    int * v1270 = v1177->cache_age;
    v1270[v1424] = 1;
    int * v1272 = v1177->cache_age;
    int v1273 = v1272[v1424];
    int v1274 = v1272[v1353];
    int v1431 = v1274 + ((int)((unsigned int)(v1274 - v1273) >> 31));
    v1272[v1353] = v1431;
    int * v1276 = v1177->cache_age;
    int v1277 = v1276[v1354];
    int v1433 = v1277 + ((int)((unsigned int)(v1277 - v1273) >> 31));
    v1276[v1354] = v1433;
    int * v1279 = v1177->cache_age;
    v1279[v1424] = 0;
    v1282 = v1424;
  }
  int * v1283 = v1177->cache_vals;
  int v1436 = (v1282 * 2) + (((int)((unsigned int)v1181 >> 2)) & 1);
  v1283[v1436] = v1182;
  int * v1285 = v1177->cache_tags;
  int v1286 = v1285[v1355];
  int v1287 = v1285[v1356];
  bool v1439 = !(((~(((v1286 ^ ((int)((unsigned int)((int)((unsigned int)v1181 >> 2)) >> 1))) | (-(v1286 ^ ((int)((unsigned int)((int)((unsigned int)v1181 >> 2)) >> 1))))) >> 31)) | (~(((v1287 ^ ((int)((unsigned int)((int)((unsigned int)v1181 >> 2)) >> 1))) | (-(v1287 ^ ((int)((unsigned int)((int)((unsigned int)v1181 >> 2)) >> 1))))) >> 31))) == 0);
  int v1341;
  if (v1439) {
    int * v1288 = v1177->cache_age;
    int v1441 = (4 + ((((int)((unsigned int)((int)((unsigned int)v1181 >> 2)) >> 1)) & 3) * 2)) + ((~(((v1287 ^ ((int)((unsigned int)((int)((unsigned int)v1181 >> 2)) >> 1))) | (-(v1287 ^ ((int)((unsigned int)((int)((unsigned int)v1181 >> 2)) >> 1))))) >> 31)) & 1);
    int v1289 = v1288[v1441];
    int v1290 = v1288[v1355];
    int v1442 = v1290 + ((int)((unsigned int)(v1290 - v1289) >> 31));
    v1288[v1355] = v1442;
    int * v1292 = v1177->cache_age;
    int v1293 = v1292[v1356];
    int v1444 = v1293 + ((int)((unsigned int)(v1293 - v1289) >> 31));
    v1292[v1356] = v1444;
    int * v1295 = v1177->cache_age;
    v1295[v1441] = 0;
    v1341 = v1441;
  } else {
    int * v1298 = v1177->cache_age;
    int v1448 = 4 + ((((int)((unsigned int)((int)((unsigned int)v1181 >> 2)) >> 1)) & 3) * 2);
    int v1299 = v1298[v1448];
    int * v1300 = v1177->cache_tags;
    int v1301 = v1300[v1448];
    int v1302 = v1298[v1356];
    int v1303 = v1300[v1356];
    int * v1304 = v1177->cache_dirty;
    int v1451 = (4 + ((((int)((unsigned int)((int)((unsigned int)v1181 >> 2)) >> 1)) & 3) * 2)) + ((((v1299 + ((~(((v1301 ^ -1) | (-(v1301 ^ -1))) >> 31)) & 2)) - (v1302 + ((~(((v1303 ^ -1) | (-(v1303 ^ -1))) >> 31)) & 2))) >> 31) & 1);
    int v1305 = v1304[v1451];
    bool v1452 = !(v1305 == 0);
    if (v1452) {
      int * v1306 = v1177->cache_tags;
      int v1307 = v1306[v1451];
      int * v1308 = v1177->cache_vals;
      int v1455 = ((4 + ((((int)((unsigned int)((int)((unsigned int)v1181 >> 2)) >> 1)) & 3) * 2)) + ((((v1299 + ((~(((v1301 ^ -1) | (-(v1301 ^ -1))) >> 31)) & 2)) - (v1302 + ((~(((v1303 ^ -1) | (-(v1303 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
      int v1309 = v1308[v1455];
      int v1456 = (((4 + ((((int)((unsigned int)((int)((unsigned int)v1181 >> 2)) >> 1)) & 3) * 2)) + ((((v1299 + ((~(((v1301 ^ -1) | (-(v1301 ^ -1))) >> 31)) & 2)) - (v1302 + ((~(((v1303 ^ -1) | (-(v1303 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
      int v1310 = v1308[v1456];
      int * v1311 = v1177->mem;
      int v1458 = v1307 * 2;
      v1311[v1458] = v1309;
      int * v1313 = v1177->mem;
      int v1461 = (v1307 * 2) + 1;
      v1313[v1461] = v1310;
      ;
    } else {
      ;
    }
    int * v1318 = v1177->mem;
    int v1466 = ((int)((unsigned int)((int)((unsigned int)v1181 >> 2)) >> 1)) * 2;
    int v1319 = v1318[v1466];
    int v1467 = (((int)((unsigned int)((int)((unsigned int)v1181 >> 2)) >> 1)) * 2) + 1;
    int v1320 = v1318[v1467];
    int * v1321 = v1177->cache_vals;
    int v1469 = ((4 + ((((int)((unsigned int)((int)((unsigned int)v1181 >> 2)) >> 1)) & 3) * 2)) + ((((v1299 + ((~(((v1301 ^ -1) | (-(v1301 ^ -1))) >> 31)) & 2)) - (v1302 + ((~(((v1303 ^ -1) | (-(v1303 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
    v1321[v1469] = v1319;
    int * v1323 = v1177->cache_vals;
    int v1472 = (((4 + ((((int)((unsigned int)((int)((unsigned int)v1181 >> 2)) >> 1)) & 3) * 2)) + ((((v1299 + ((~(((v1301 ^ -1) | (-(v1301 ^ -1))) >> 31)) & 2)) - (v1302 + ((~(((v1303 ^ -1) | (-(v1303 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
    v1323[v1472] = v1320;
    int * v1325 = v1177->cache_tags;
    int v1475 = (int)((unsigned int)((int)((unsigned int)v1181 >> 2)) >> 1);
    v1325[v1451] = v1475;
    int * v1327 = v1177->cache_dirty;
    v1327[v1451] = 0;
    int * v1329 = v1177->cache_age;
    v1329[v1451] = 1;
    int * v1331 = v1177->cache_age;
    int v1332 = v1331[v1451];
    int v1333 = v1331[v1355];
    int v1481 = v1333 + ((int)((unsigned int)(v1333 - v1332) >> 31));
    v1331[v1355] = v1481;
    int * v1335 = v1177->cache_age;
    int v1336 = v1335[v1356];
    int v1483 = v1336 + ((int)((unsigned int)(v1336 - v1332) >> 31));
    v1335[v1356] = v1483;
    int * v1338 = v1177->cache_age;
    v1338[v1451] = 0;
    v1341 = v1451;
  }
  int * v1342 = v1177->cache_vals;
  int v1486 = (v1341 * 2) + (((int)((unsigned int)v1181 >> 2)) & 1);
  v1342[v1486] = v1182;
  int * v1344 = v1177->cache_dirty;
  v1344[v1341] = 1;
  struct StateT * v1346 = slot_24(v1177);
  return v1346;
}

struct StateT * slot_35(struct StateT * v2941) {
  int v2942 = v2941->timer;
  int v2949 = v2942 + 1;
  v2941->timer = v2949;
  int * v2944 = v2941->regs;
  int v2945 = v2944[14];
  int v2952 = v2945 + 1;
  v2944[14] = v2952;
  struct StateT * v2947 = slot_36(v2941);
  return v2947;
}

struct StateT * slot_34(struct StateT * v2626) {
  int v2627 = v2626->timer;
  int v2797 = v2627 + 1;
  v2626->timer = v2797;
  int * v2629 = v2626->regs;
  int v2630 = v2629[15];
  int v2631 = v2629[16];
  int * v2632 = v2626->cache_tags;
  int v2802 = (((int)((unsigned int)((int)((unsigned int)(v2630 + 4) >> 2)) >> 1)) & 1) * 2;
  int v2633 = v2632[v2802];
  int v2803 = ((((int)((unsigned int)((int)((unsigned int)(v2630 + 4) >> 2)) >> 1)) & 1) * 2) + 1;
  int v2634 = v2632[v2803];
  int v2804 = 4 + ((((int)((unsigned int)((int)((unsigned int)(v2630 + 4) >> 2)) >> 1)) & 3) * 2);
  int v2635 = v2632[v2804];
  int v2805 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v2630 + 4) >> 2)) >> 1)) & 3) * 2)) + 1;
  int v2636 = v2632[v2805];
  int v2637 = v2626->timer;
  int v2806 = v2637 + ((100 ^ (((~(((v2635 ^ ((int)((unsigned int)((int)((unsigned int)(v2630 + 4) >> 2)) >> 1))) | (-(v2635 ^ ((int)((unsigned int)((int)((unsigned int)(v2630 + 4) >> 2)) >> 1))))) >> 31)) | (~(((v2636 ^ ((int)((unsigned int)((int)((unsigned int)(v2630 + 4) >> 2)) >> 1))) | (-(v2636 ^ ((int)((unsigned int)((int)((unsigned int)(v2630 + 4) >> 2)) >> 1))))) >> 31))) & 104)) ^ (((~(((v2633 ^ ((int)((unsigned int)((int)((unsigned int)(v2630 + 4) >> 2)) >> 1))) | (-(v2633 ^ ((int)((unsigned int)((int)((unsigned int)(v2630 + 4) >> 2)) >> 1))))) >> 31)) | (~(((v2634 ^ ((int)((unsigned int)((int)((unsigned int)(v2630 + 4) >> 2)) >> 1))) | (-(v2634 ^ ((int)((unsigned int)((int)((unsigned int)(v2630 + 4) >> 2)) >> 1))))) >> 31))) & (1 ^ (100 ^ (((~(((v2635 ^ ((int)((unsigned int)((int)((unsigned int)(v2630 + 4) >> 2)) >> 1))) | (-(v2635 ^ ((int)((unsigned int)((int)((unsigned int)(v2630 + 4) >> 2)) >> 1))))) >> 31)) | (~(((v2636 ^ ((int)((unsigned int)((int)((unsigned int)(v2630 + 4) >> 2)) >> 1))) | (-(v2636 ^ ((int)((unsigned int)((int)((unsigned int)(v2630 + 4) >> 2)) >> 1))))) >> 31))) & 104)))));
  v2626->timer = v2806;
  bool v2807 = !(((~(((v2633 ^ ((int)((unsigned int)((int)((unsigned int)(v2630 + 4) >> 2)) >> 1))) | (-(v2633 ^ ((int)((unsigned int)((int)((unsigned int)(v2630 + 4) >> 2)) >> 1))))) >> 31)) | (~(((v2634 ^ ((int)((unsigned int)((int)((unsigned int)(v2630 + 4) >> 2)) >> 1))) | (-(v2634 ^ ((int)((unsigned int)((int)((unsigned int)(v2630 + 4) >> 2)) >> 1))))) >> 31))) == 0);
  int v2731;
  if (v2807) {
    int * v2639 = v2626->cache_age;
    int v2809 = ((((int)((unsigned int)((int)((unsigned int)(v2630 + 4) >> 2)) >> 1)) & 1) * 2) + ((~(((v2634 ^ ((int)((unsigned int)((int)((unsigned int)(v2630 + 4) >> 2)) >> 1))) | (-(v2634 ^ ((int)((unsigned int)((int)((unsigned int)(v2630 + 4) >> 2)) >> 1))))) >> 31)) & 1);
    int v2640 = v2639[v2809];
    int v2641 = v2639[v2802];
    int v2810 = v2641 + ((int)((unsigned int)(v2641 - v2640) >> 31));
    v2639[v2802] = v2810;
    int * v2643 = v2626->cache_age;
    int v2644 = v2643[v2803];
    int v2812 = v2644 + ((int)((unsigned int)(v2644 - v2640) >> 31));
    v2643[v2803] = v2812;
    int * v2646 = v2626->cache_age;
    v2646[v2809] = 0;
    v2731 = v2809;
  } else {
    int * v2649 = v2626->cache_age;
    int v2816 = (((int)((unsigned int)((int)((unsigned int)(v2630 + 4) >> 2)) >> 1)) & 1) * 2;
    int v2650 = v2649[v2816];
    int * v2651 = v2626->cache_tags;
    int v2652 = v2651[v2816];
    int v2653 = v2649[v2803];
    int v2654 = v2651[v2803];
    bool v2818 = !(((~(((v2635 ^ ((int)((unsigned int)((int)((unsigned int)(v2630 + 4) >> 2)) >> 1))) | (-(v2635 ^ ((int)((unsigned int)((int)((unsigned int)(v2630 + 4) >> 2)) >> 1))))) >> 31)) | (~(((v2636 ^ ((int)((unsigned int)((int)((unsigned int)(v2630 + 4) >> 2)) >> 1))) | (-(v2636 ^ ((int)((unsigned int)((int)((unsigned int)(v2630 + 4) >> 2)) >> 1))))) >> 31))) == 0);
    int v2708;
    if (v2818) {
      int * v2655 = v2626->cache_age;
      int v2820 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v2630 + 4) >> 2)) >> 1)) & 3) * 2)) + ((~(((v2636 ^ ((int)((unsigned int)((int)((unsigned int)(v2630 + 4) >> 2)) >> 1))) | (-(v2636 ^ ((int)((unsigned int)((int)((unsigned int)(v2630 + 4) >> 2)) >> 1))))) >> 31)) & 1);
      int v2656 = v2655[v2820];
      int v2657 = v2655[v2804];
      int v2821 = v2657 + ((int)((unsigned int)(v2657 - v2656) >> 31));
      v2655[v2804] = v2821;
      int * v2659 = v2626->cache_age;
      int v2660 = v2659[v2805];
      int v2823 = v2660 + ((int)((unsigned int)(v2660 - v2656) >> 31));
      v2659[v2805] = v2823;
      int * v2662 = v2626->cache_age;
      v2662[v2820] = 0;
      v2708 = v2820;
    } else {
      int * v2665 = v2626->cache_age;
      int v2827 = 4 + ((((int)((unsigned int)((int)((unsigned int)(v2630 + 4) >> 2)) >> 1)) & 3) * 2);
      int v2666 = v2665[v2827];
      int * v2667 = v2626->cache_tags;
      int v2668 = v2667[v2827];
      int v2669 = v2665[v2805];
      int v2670 = v2667[v2805];
      int * v2671 = v2626->cache_dirty;
      int v2830 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v2630 + 4) >> 2)) >> 1)) & 3) * 2)) + ((((v2666 + ((~(((v2668 ^ -1) | (-(v2668 ^ -1))) >> 31)) & 2)) - (v2669 + ((~(((v2670 ^ -1) | (-(v2670 ^ -1))) >> 31)) & 2))) >> 31) & 1);
      int v2672 = v2671[v2830];
      bool v2831 = !(v2672 == 0);
      if (v2831) {
        int * v2673 = v2626->cache_tags;
        int v2674 = v2673[v2830];
        int * v2675 = v2626->cache_vals;
        int v2834 = ((4 + ((((int)((unsigned int)((int)((unsigned int)(v2630 + 4) >> 2)) >> 1)) & 3) * 2)) + ((((v2666 + ((~(((v2668 ^ -1) | (-(v2668 ^ -1))) >> 31)) & 2)) - (v2669 + ((~(((v2670 ^ -1) | (-(v2670 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
        int v2676 = v2675[v2834];
        int v2835 = (((4 + ((((int)((unsigned int)((int)((unsigned int)(v2630 + 4) >> 2)) >> 1)) & 3) * 2)) + ((((v2666 + ((~(((v2668 ^ -1) | (-(v2668 ^ -1))) >> 31)) & 2)) - (v2669 + ((~(((v2670 ^ -1) | (-(v2670 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
        int v2677 = v2675[v2835];
        int * v2678 = v2626->mem;
        int v2837 = v2674 * 2;
        v2678[v2837] = v2676;
        int * v2680 = v2626->mem;
        int v2840 = (v2674 * 2) + 1;
        v2680[v2840] = v2677;
        ;
      } else {
        ;
      }
      int * v2685 = v2626->mem;
      int v2845 = ((int)((unsigned int)((int)((unsigned int)(v2630 + 4) >> 2)) >> 1)) * 2;
      int v2686 = v2685[v2845];
      int v2846 = (((int)((unsigned int)((int)((unsigned int)(v2630 + 4) >> 2)) >> 1)) * 2) + 1;
      int v2687 = v2685[v2846];
      int * v2688 = v2626->cache_vals;
      int v2848 = ((4 + ((((int)((unsigned int)((int)((unsigned int)(v2630 + 4) >> 2)) >> 1)) & 3) * 2)) + ((((v2666 + ((~(((v2668 ^ -1) | (-(v2668 ^ -1))) >> 31)) & 2)) - (v2669 + ((~(((v2670 ^ -1) | (-(v2670 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
      v2688[v2848] = v2686;
      int * v2690 = v2626->cache_vals;
      int v2851 = (((4 + ((((int)((unsigned int)((int)((unsigned int)(v2630 + 4) >> 2)) >> 1)) & 3) * 2)) + ((((v2666 + ((~(((v2668 ^ -1) | (-(v2668 ^ -1))) >> 31)) & 2)) - (v2669 + ((~(((v2670 ^ -1) | (-(v2670 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
      v2690[v2851] = v2687;
      int * v2692 = v2626->cache_tags;
      int v2854 = (int)((unsigned int)((int)((unsigned int)(v2630 + 4) >> 2)) >> 1);
      v2692[v2830] = v2854;
      int * v2694 = v2626->cache_dirty;
      v2694[v2830] = 0;
      int * v2696 = v2626->cache_age;
      v2696[v2830] = 1;
      int * v2698 = v2626->cache_age;
      int v2699 = v2698[v2830];
      int v2700 = v2698[v2804];
      int v2860 = v2700 + ((int)((unsigned int)(v2700 - v2699) >> 31));
      v2698[v2804] = v2860;
      int * v2702 = v2626->cache_age;
      int v2703 = v2702[v2805];
      int v2862 = v2703 + ((int)((unsigned int)(v2703 - v2699) >> 31));
      v2702[v2805] = v2862;
      int * v2705 = v2626->cache_age;
      v2705[v2830] = 0;
      v2708 = v2830;
    }
    int * v2709 = v2626->cache_vals;
    int v2865 = v2708 * 2;
    int v2710 = v2709[v2865];
    int v2866 = (v2708 * 2) + 1;
    int v2711 = v2709[v2866];
    int v2867 = (((((int)((unsigned int)((int)((unsigned int)(v2630 + 4) >> 2)) >> 1)) & 1) * 2) + ((((v2650 + ((~(((v2652 ^ -1) | (-(v2652 ^ -1))) >> 31)) & 2)) - (v2653 + ((~(((v2654 ^ -1) | (-(v2654 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
    v2709[v2867] = v2710;
    int * v2713 = v2626->cache_vals;
    int v2870 = ((((((int)((unsigned int)((int)((unsigned int)(v2630 + 4) >> 2)) >> 1)) & 1) * 2) + ((((v2650 + ((~(((v2652 ^ -1) | (-(v2652 ^ -1))) >> 31)) & 2)) - (v2653 + ((~(((v2654 ^ -1) | (-(v2654 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
    v2713[v2870] = v2711;
    int * v2715 = v2626->cache_tags;
    int v2873 = ((((int)((unsigned int)((int)((unsigned int)(v2630 + 4) >> 2)) >> 1)) & 1) * 2) + ((((v2650 + ((~(((v2652 ^ -1) | (-(v2652 ^ -1))) >> 31)) & 2)) - (v2653 + ((~(((v2654 ^ -1) | (-(v2654 ^ -1))) >> 31)) & 2))) >> 31) & 1);
    int v2874 = (int)((unsigned int)((int)((unsigned int)(v2630 + 4) >> 2)) >> 1);
    v2715[v2873] = v2874;
    int * v2717 = v2626->cache_dirty;
    v2717[v2873] = 0;
    int * v2719 = v2626->cache_age;
    v2719[v2873] = 1;
    int * v2721 = v2626->cache_age;
    int v2722 = v2721[v2873];
    int v2723 = v2721[v2802];
    int v2880 = v2723 + ((int)((unsigned int)(v2723 - v2722) >> 31));
    v2721[v2802] = v2880;
    int * v2725 = v2626->cache_age;
    int v2726 = v2725[v2803];
    int v2882 = v2726 + ((int)((unsigned int)(v2726 - v2722) >> 31));
    v2725[v2803] = v2882;
    int * v2728 = v2626->cache_age;
    v2728[v2873] = 0;
    v2731 = v2873;
  }
  int * v2732 = v2626->cache_vals;
  int v2885 = (v2731 * 2) + (((int)((unsigned int)(v2630 + 4) >> 2)) & 1);
  v2732[v2885] = v2631;
  int * v2734 = v2626->cache_tags;
  int v2735 = v2734[v2804];
  int v2736 = v2734[v2805];
  bool v2888 = !(((~(((v2735 ^ ((int)((unsigned int)((int)((unsigned int)(v2630 + 4) >> 2)) >> 1))) | (-(v2735 ^ ((int)((unsigned int)((int)((unsigned int)(v2630 + 4) >> 2)) >> 1))))) >> 31)) | (~(((v2736 ^ ((int)((unsigned int)((int)((unsigned int)(v2630 + 4) >> 2)) >> 1))) | (-(v2736 ^ ((int)((unsigned int)((int)((unsigned int)(v2630 + 4) >> 2)) >> 1))))) >> 31))) == 0);
  int v2790;
  if (v2888) {
    int * v2737 = v2626->cache_age;
    int v2890 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v2630 + 4) >> 2)) >> 1)) & 3) * 2)) + ((~(((v2736 ^ ((int)((unsigned int)((int)((unsigned int)(v2630 + 4) >> 2)) >> 1))) | (-(v2736 ^ ((int)((unsigned int)((int)((unsigned int)(v2630 + 4) >> 2)) >> 1))))) >> 31)) & 1);
    int v2738 = v2737[v2890];
    int v2739 = v2737[v2804];
    int v2891 = v2739 + ((int)((unsigned int)(v2739 - v2738) >> 31));
    v2737[v2804] = v2891;
    int * v2741 = v2626->cache_age;
    int v2742 = v2741[v2805];
    int v2893 = v2742 + ((int)((unsigned int)(v2742 - v2738) >> 31));
    v2741[v2805] = v2893;
    int * v2744 = v2626->cache_age;
    v2744[v2890] = 0;
    v2790 = v2890;
  } else {
    int * v2747 = v2626->cache_age;
    int v2897 = 4 + ((((int)((unsigned int)((int)((unsigned int)(v2630 + 4) >> 2)) >> 1)) & 3) * 2);
    int v2748 = v2747[v2897];
    int * v2749 = v2626->cache_tags;
    int v2750 = v2749[v2897];
    int v2751 = v2747[v2805];
    int v2752 = v2749[v2805];
    int * v2753 = v2626->cache_dirty;
    int v2900 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v2630 + 4) >> 2)) >> 1)) & 3) * 2)) + ((((v2748 + ((~(((v2750 ^ -1) | (-(v2750 ^ -1))) >> 31)) & 2)) - (v2751 + ((~(((v2752 ^ -1) | (-(v2752 ^ -1))) >> 31)) & 2))) >> 31) & 1);
    int v2754 = v2753[v2900];
    bool v2901 = !(v2754 == 0);
    if (v2901) {
      int * v2755 = v2626->cache_tags;
      int v2756 = v2755[v2900];
      int * v2757 = v2626->cache_vals;
      int v2904 = ((4 + ((((int)((unsigned int)((int)((unsigned int)(v2630 + 4) >> 2)) >> 1)) & 3) * 2)) + ((((v2748 + ((~(((v2750 ^ -1) | (-(v2750 ^ -1))) >> 31)) & 2)) - (v2751 + ((~(((v2752 ^ -1) | (-(v2752 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
      int v2758 = v2757[v2904];
      int v2905 = (((4 + ((((int)((unsigned int)((int)((unsigned int)(v2630 + 4) >> 2)) >> 1)) & 3) * 2)) + ((((v2748 + ((~(((v2750 ^ -1) | (-(v2750 ^ -1))) >> 31)) & 2)) - (v2751 + ((~(((v2752 ^ -1) | (-(v2752 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
      int v2759 = v2757[v2905];
      int * v2760 = v2626->mem;
      int v2907 = v2756 * 2;
      v2760[v2907] = v2758;
      int * v2762 = v2626->mem;
      int v2910 = (v2756 * 2) + 1;
      v2762[v2910] = v2759;
      ;
    } else {
      ;
    }
    int * v2767 = v2626->mem;
    int v2915 = ((int)((unsigned int)((int)((unsigned int)(v2630 + 4) >> 2)) >> 1)) * 2;
    int v2768 = v2767[v2915];
    int v2916 = (((int)((unsigned int)((int)((unsigned int)(v2630 + 4) >> 2)) >> 1)) * 2) + 1;
    int v2769 = v2767[v2916];
    int * v2770 = v2626->cache_vals;
    int v2918 = ((4 + ((((int)((unsigned int)((int)((unsigned int)(v2630 + 4) >> 2)) >> 1)) & 3) * 2)) + ((((v2748 + ((~(((v2750 ^ -1) | (-(v2750 ^ -1))) >> 31)) & 2)) - (v2751 + ((~(((v2752 ^ -1) | (-(v2752 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
    v2770[v2918] = v2768;
    int * v2772 = v2626->cache_vals;
    int v2921 = (((4 + ((((int)((unsigned int)((int)((unsigned int)(v2630 + 4) >> 2)) >> 1)) & 3) * 2)) + ((((v2748 + ((~(((v2750 ^ -1) | (-(v2750 ^ -1))) >> 31)) & 2)) - (v2751 + ((~(((v2752 ^ -1) | (-(v2752 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
    v2772[v2921] = v2769;
    int * v2774 = v2626->cache_tags;
    int v2924 = (int)((unsigned int)((int)((unsigned int)(v2630 + 4) >> 2)) >> 1);
    v2774[v2900] = v2924;
    int * v2776 = v2626->cache_dirty;
    v2776[v2900] = 0;
    int * v2778 = v2626->cache_age;
    v2778[v2900] = 1;
    int * v2780 = v2626->cache_age;
    int v2781 = v2780[v2900];
    int v2782 = v2780[v2804];
    int v2930 = v2782 + ((int)((unsigned int)(v2782 - v2781) >> 31));
    v2780[v2804] = v2930;
    int * v2784 = v2626->cache_age;
    int v2785 = v2784[v2805];
    int v2932 = v2785 + ((int)((unsigned int)(v2785 - v2781) >> 31));
    v2784[v2805] = v2932;
    int * v2787 = v2626->cache_age;
    v2787[v2900] = 0;
    v2790 = v2900;
  }
  int * v2791 = v2626->cache_vals;
  int v2935 = (v2790 * 2) + (((int)((unsigned int)(v2630 + 4) >> 2)) & 1);
  v2791[v2935] = v2631;
  int * v2793 = v2626->cache_dirty;
  v2793[v2790] = 1;
  struct StateT * v2795 = slot_35(v2626);
  return v2795;
}

struct StateT * slot_25(struct StateT * v1807) {
  int v1808 = v1807->timer;
  int v1918 = v1808 + 1;
  v1807->timer = v1918;
  int * v1810 = v1807->regs;
  int v1811 = v1810[15];
  int * v1812 = v1807->cache_tags;
  int v1922 = (((int)((unsigned int)((int)((unsigned int)(v1811 + 4) >> 2)) >> 1)) & 1) * 2;
  int v1813 = v1812[v1922];
  int v1923 = ((((int)((unsigned int)((int)((unsigned int)(v1811 + 4) >> 2)) >> 1)) & 1) * 2) + 1;
  int v1814 = v1812[v1923];
  int v1924 = 4 + ((((int)((unsigned int)((int)((unsigned int)(v1811 + 4) >> 2)) >> 1)) & 3) * 2);
  int v1815 = v1812[v1924];
  int v1925 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v1811 + 4) >> 2)) >> 1)) & 3) * 2)) + 1;
  int v1816 = v1812[v1925];
  int v1817 = v1807->timer;
  int v1926 = v1817 + ((100 ^ (((~(((v1815 ^ ((int)((unsigned int)((int)((unsigned int)(v1811 + 4) >> 2)) >> 1))) | (-(v1815 ^ ((int)((unsigned int)((int)((unsigned int)(v1811 + 4) >> 2)) >> 1))))) >> 31)) | (~(((v1816 ^ ((int)((unsigned int)((int)((unsigned int)(v1811 + 4) >> 2)) >> 1))) | (-(v1816 ^ ((int)((unsigned int)((int)((unsigned int)(v1811 + 4) >> 2)) >> 1))))) >> 31))) & 104)) ^ (((~(((v1813 ^ ((int)((unsigned int)((int)((unsigned int)(v1811 + 4) >> 2)) >> 1))) | (-(v1813 ^ ((int)((unsigned int)((int)((unsigned int)(v1811 + 4) >> 2)) >> 1))))) >> 31)) | (~(((v1814 ^ ((int)((unsigned int)((int)((unsigned int)(v1811 + 4) >> 2)) >> 1))) | (-(v1814 ^ ((int)((unsigned int)((int)((unsigned int)(v1811 + 4) >> 2)) >> 1))))) >> 31))) & (1 ^ (100 ^ (((~(((v1815 ^ ((int)((unsigned int)((int)((unsigned int)(v1811 + 4) >> 2)) >> 1))) | (-(v1815 ^ ((int)((unsigned int)((int)((unsigned int)(v1811 + 4) >> 2)) >> 1))))) >> 31)) | (~(((v1816 ^ ((int)((unsigned int)((int)((unsigned int)(v1811 + 4) >> 2)) >> 1))) | (-(v1816 ^ ((int)((unsigned int)((int)((unsigned int)(v1811 + 4) >> 2)) >> 1))))) >> 31))) & 104)))));
  v1807->timer = v1926;
  int * v1819 = v1807->cache_vals;
  bool v1927 = !(((~(((v1813 ^ ((int)((unsigned int)((int)((unsigned int)(v1811 + 4) >> 2)) >> 1))) | (-(v1813 ^ ((int)((unsigned int)((int)((unsigned int)(v1811 + 4) >> 2)) >> 1))))) >> 31)) | (~(((v1814 ^ ((int)((unsigned int)((int)((unsigned int)(v1811 + 4) >> 2)) >> 1))) | (-(v1814 ^ ((int)((unsigned int)((int)((unsigned int)(v1811 + 4) >> 2)) >> 1))))) >> 31))) == 0);
  int v1912;
  if (v1927) {
    int * v1820 = v1807->cache_age;
    int v1929 = ((((int)((unsigned int)((int)((unsigned int)(v1811 + 4) >> 2)) >> 1)) & 1) * 2) + ((~(((v1814 ^ ((int)((unsigned int)((int)((unsigned int)(v1811 + 4) >> 2)) >> 1))) | (-(v1814 ^ ((int)((unsigned int)((int)((unsigned int)(v1811 + 4) >> 2)) >> 1))))) >> 31)) & 1);
    int v1821 = v1820[v1929];
    int v1822 = v1820[v1922];
    int v1930 = v1822 + ((int)((unsigned int)(v1822 - v1821) >> 31));
    v1820[v1922] = v1930;
    int * v1824 = v1807->cache_age;
    int v1825 = v1824[v1923];
    int v1932 = v1825 + ((int)((unsigned int)(v1825 - v1821) >> 31));
    v1824[v1923] = v1932;
    int * v1827 = v1807->cache_age;
    v1827[v1929] = 0;
    v1912 = v1929;
  } else {
    int * v1830 = v1807->cache_age;
    int v1936 = (((int)((unsigned int)((int)((unsigned int)(v1811 + 4) >> 2)) >> 1)) & 1) * 2;
    int v1831 = v1830[v1936];
    int * v1832 = v1807->cache_tags;
    int v1833 = v1832[v1936];
    int v1834 = v1830[v1923];
    int v1835 = v1832[v1923];
    bool v1938 = !(((~(((v1815 ^ ((int)((unsigned int)((int)((unsigned int)(v1811 + 4) >> 2)) >> 1))) | (-(v1815 ^ ((int)((unsigned int)((int)((unsigned int)(v1811 + 4) >> 2)) >> 1))))) >> 31)) | (~(((v1816 ^ ((int)((unsigned int)((int)((unsigned int)(v1811 + 4) >> 2)) >> 1))) | (-(v1816 ^ ((int)((unsigned int)((int)((unsigned int)(v1811 + 4) >> 2)) >> 1))))) >> 31))) == 0);
    int v1889;
    if (v1938) {
      int * v1836 = v1807->cache_age;
      int v1940 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v1811 + 4) >> 2)) >> 1)) & 3) * 2)) + ((~(((v1816 ^ ((int)((unsigned int)((int)((unsigned int)(v1811 + 4) >> 2)) >> 1))) | (-(v1816 ^ ((int)((unsigned int)((int)((unsigned int)(v1811 + 4) >> 2)) >> 1))))) >> 31)) & 1);
      int v1837 = v1836[v1940];
      int v1838 = v1836[v1924];
      int v1941 = v1838 + ((int)((unsigned int)(v1838 - v1837) >> 31));
      v1836[v1924] = v1941;
      int * v1840 = v1807->cache_age;
      int v1841 = v1840[v1925];
      int v1943 = v1841 + ((int)((unsigned int)(v1841 - v1837) >> 31));
      v1840[v1925] = v1943;
      int * v1843 = v1807->cache_age;
      v1843[v1940] = 0;
      v1889 = v1940;
    } else {
      int * v1846 = v1807->cache_age;
      int v1947 = 4 + ((((int)((unsigned int)((int)((unsigned int)(v1811 + 4) >> 2)) >> 1)) & 3) * 2);
      int v1847 = v1846[v1947];
      int * v1848 = v1807->cache_tags;
      int v1849 = v1848[v1947];
      int v1850 = v1846[v1925];
      int v1851 = v1848[v1925];
      int * v1852 = v1807->cache_dirty;
      int v1950 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v1811 + 4) >> 2)) >> 1)) & 3) * 2)) + ((((v1847 + ((~(((v1849 ^ -1) | (-(v1849 ^ -1))) >> 31)) & 2)) - (v1850 + ((~(((v1851 ^ -1) | (-(v1851 ^ -1))) >> 31)) & 2))) >> 31) & 1);
      int v1853 = v1852[v1950];
      bool v1951 = !(v1853 == 0);
      if (v1951) {
        int * v1854 = v1807->cache_tags;
        int v1855 = v1854[v1950];
        int * v1856 = v1807->cache_vals;
        int v1954 = ((4 + ((((int)((unsigned int)((int)((unsigned int)(v1811 + 4) >> 2)) >> 1)) & 3) * 2)) + ((((v1847 + ((~(((v1849 ^ -1) | (-(v1849 ^ -1))) >> 31)) & 2)) - (v1850 + ((~(((v1851 ^ -1) | (-(v1851 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
        int v1857 = v1856[v1954];
        int v1955 = (((4 + ((((int)((unsigned int)((int)((unsigned int)(v1811 + 4) >> 2)) >> 1)) & 3) * 2)) + ((((v1847 + ((~(((v1849 ^ -1) | (-(v1849 ^ -1))) >> 31)) & 2)) - (v1850 + ((~(((v1851 ^ -1) | (-(v1851 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
        int v1858 = v1856[v1955];
        int * v1859 = v1807->mem;
        int v1957 = v1855 * 2;
        v1859[v1957] = v1857;
        int * v1861 = v1807->mem;
        int v1960 = (v1855 * 2) + 1;
        v1861[v1960] = v1858;
        ;
      } else {
        ;
      }
      int * v1866 = v1807->mem;
      int v1965 = ((int)((unsigned int)((int)((unsigned int)(v1811 + 4) >> 2)) >> 1)) * 2;
      int v1867 = v1866[v1965];
      int v1966 = (((int)((unsigned int)((int)((unsigned int)(v1811 + 4) >> 2)) >> 1)) * 2) + 1;
      int v1868 = v1866[v1966];
      int * v1869 = v1807->cache_vals;
      int v1968 = ((4 + ((((int)((unsigned int)((int)((unsigned int)(v1811 + 4) >> 2)) >> 1)) & 3) * 2)) + ((((v1847 + ((~(((v1849 ^ -1) | (-(v1849 ^ -1))) >> 31)) & 2)) - (v1850 + ((~(((v1851 ^ -1) | (-(v1851 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
      v1869[v1968] = v1867;
      int * v1871 = v1807->cache_vals;
      int v1971 = (((4 + ((((int)((unsigned int)((int)((unsigned int)(v1811 + 4) >> 2)) >> 1)) & 3) * 2)) + ((((v1847 + ((~(((v1849 ^ -1) | (-(v1849 ^ -1))) >> 31)) & 2)) - (v1850 + ((~(((v1851 ^ -1) | (-(v1851 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
      v1871[v1971] = v1868;
      int * v1873 = v1807->cache_tags;
      int v1974 = (int)((unsigned int)((int)((unsigned int)(v1811 + 4) >> 2)) >> 1);
      v1873[v1950] = v1974;
      int * v1875 = v1807->cache_dirty;
      v1875[v1950] = 0;
      int * v1877 = v1807->cache_age;
      v1877[v1950] = 1;
      int * v1879 = v1807->cache_age;
      int v1880 = v1879[v1950];
      int v1881 = v1879[v1924];
      int v1980 = v1881 + ((int)((unsigned int)(v1881 - v1880) >> 31));
      v1879[v1924] = v1980;
      int * v1883 = v1807->cache_age;
      int v1884 = v1883[v1925];
      int v1982 = v1884 + ((int)((unsigned int)(v1884 - v1880) >> 31));
      v1883[v1925] = v1982;
      int * v1886 = v1807->cache_age;
      v1886[v1950] = 0;
      v1889 = v1950;
    }
    int * v1890 = v1807->cache_vals;
    int v1985 = v1889 * 2;
    int v1891 = v1890[v1985];
    int v1986 = (v1889 * 2) + 1;
    int v1892 = v1890[v1986];
    int v1987 = (((((int)((unsigned int)((int)((unsigned int)(v1811 + 4) >> 2)) >> 1)) & 1) * 2) + ((((v1831 + ((~(((v1833 ^ -1) | (-(v1833 ^ -1))) >> 31)) & 2)) - (v1834 + ((~(((v1835 ^ -1) | (-(v1835 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
    v1890[v1987] = v1891;
    int * v1894 = v1807->cache_vals;
    int v1990 = ((((((int)((unsigned int)((int)((unsigned int)(v1811 + 4) >> 2)) >> 1)) & 1) * 2) + ((((v1831 + ((~(((v1833 ^ -1) | (-(v1833 ^ -1))) >> 31)) & 2)) - (v1834 + ((~(((v1835 ^ -1) | (-(v1835 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
    v1894[v1990] = v1892;
    int * v1896 = v1807->cache_tags;
    int v1993 = ((((int)((unsigned int)((int)((unsigned int)(v1811 + 4) >> 2)) >> 1)) & 1) * 2) + ((((v1831 + ((~(((v1833 ^ -1) | (-(v1833 ^ -1))) >> 31)) & 2)) - (v1834 + ((~(((v1835 ^ -1) | (-(v1835 ^ -1))) >> 31)) & 2))) >> 31) & 1);
    int v1994 = (int)((unsigned int)((int)((unsigned int)(v1811 + 4) >> 2)) >> 1);
    v1896[v1993] = v1994;
    int * v1898 = v1807->cache_dirty;
    v1898[v1993] = 0;
    int * v1900 = v1807->cache_age;
    v1900[v1993] = 1;
    int * v1902 = v1807->cache_age;
    int v1903 = v1902[v1993];
    int v1904 = v1902[v1922];
    int v2000 = v1904 + ((int)((unsigned int)(v1904 - v1903) >> 31));
    v1902[v1922] = v2000;
    int * v1906 = v1807->cache_age;
    int v1907 = v1906[v1923];
    int v2002 = v1907 + ((int)((unsigned int)(v1907 - v1903) >> 31));
    v1906[v1923] = v2002;
    int * v1909 = v1807->cache_age;
    v1909[v1993] = 0;
    v1912 = v1993;
  }
  int v2005 = (v1912 * 2) + (((int)((unsigned int)(v1811 + 4) >> 2)) & 1);
  int v1913 = v1819[v2005];
  int * v1914 = v1807->regs;
  v1914[16] = v1913;
  struct StateT * v1916 = slot_26(v1807);
  return v1916;
}

struct StateT * slot_2(struct StateT * v29) {
  int v30 = v29->timer;
  int v38 = v30 + 1;
  v29->timer = v38;
  int * v32 = v29->regs;
  int v33 = v32[12];
  int v34 = v32[13];
  int v42 = v33 | v34;
  v32[13] = v42;
  struct StateT * v36 = slot_3(v29);
  return v36;
}

struct StateT * slot_21(struct StateT * v1172) {
  int v1173 = v1172->timer;
  int v1176 = v1173 + 1;
  v1172->timer = v1176;
  return v1172;
}

struct StateT * slot_3(struct StateT * v45) {
  int v46 = v45->timer;
  int v52 = v46 + 1;
  v45->timer = v52;
  int * v48 = v45->regs;
  v48[12] = 4;
  struct StateT * v50 = slot_4(v45);
  return v50;
}

struct StateT * slot_45(struct StateT * v3849) {
  int v3850 = v3849->timer;
  int v3858 = v3850 + 1;
  v3849->timer = v3858;
  int * v3852 = v3849->regs;
  int v3853 = v3852[6];
  int v3854 = v3852[5];
  int v3862 = v3853 ^ v3854;
  v3852[6] = v3862;
  struct StateT * v3856 = slot_46(v3849);
  return v3856;
}

struct StateT * slot_1(struct StateT * v15) {
  int v16 = v15->timer;
  int v23 = v16 + 1;
  v15->timer = v23;
  int * v18 = v15->regs;
  int v19 = v18[12];
  int v26 = v19 ^ 1;
  v18[12] = v26;
  struct StateT * v21 = slot_2(v15);
  return v21;
}

struct StateT * slot_13(struct StateT * v797) {
  int * v798 = v797->saved_regs;
  int * v799 = v797->regs;
  int v800 = v799[7];
  v798[7] = v800;
  int v802 = v797->timer;
  int v916 = v802 + 1;
  v797->timer = v916;
  int * v804 = v797->regs;
  int v805 = v804[15];
  int * v806 = v797->cache_tags;
  int v920 = (((int)((unsigned int)((int)((unsigned int)v805 >> 2)) >> 1)) & 1) * 2;
  int v807 = v806[v920];
  int v921 = ((((int)((unsigned int)((int)((unsigned int)v805 >> 2)) >> 1)) & 1) * 2) + 1;
  int v808 = v806[v921];
  int v922 = 4 + ((((int)((unsigned int)((int)((unsigned int)v805 >> 2)) >> 1)) & 3) * 2);
  int v809 = v806[v922];
  int v923 = (4 + ((((int)((unsigned int)((int)((unsigned int)v805 >> 2)) >> 1)) & 3) * 2)) + 1;
  int v810 = v806[v923];
  int v811 = v797->timer;
  int v924 = v811 + ((100 ^ (((~(((v809 ^ ((int)((unsigned int)((int)((unsigned int)v805 >> 2)) >> 1))) | (-(v809 ^ ((int)((unsigned int)((int)((unsigned int)v805 >> 2)) >> 1))))) >> 31)) | (~(((v810 ^ ((int)((unsigned int)((int)((unsigned int)v805 >> 2)) >> 1))) | (-(v810 ^ ((int)((unsigned int)((int)((unsigned int)v805 >> 2)) >> 1))))) >> 31))) & 104)) ^ (((~(((v807 ^ ((int)((unsigned int)((int)((unsigned int)v805 >> 2)) >> 1))) | (-(v807 ^ ((int)((unsigned int)((int)((unsigned int)v805 >> 2)) >> 1))))) >> 31)) | (~(((v808 ^ ((int)((unsigned int)((int)((unsigned int)v805 >> 2)) >> 1))) | (-(v808 ^ ((int)((unsigned int)((int)((unsigned int)v805 >> 2)) >> 1))))) >> 31))) & (1 ^ (100 ^ (((~(((v809 ^ ((int)((unsigned int)((int)((unsigned int)v805 >> 2)) >> 1))) | (-(v809 ^ ((int)((unsigned int)((int)((unsigned int)v805 >> 2)) >> 1))))) >> 31)) | (~(((v810 ^ ((int)((unsigned int)((int)((unsigned int)v805 >> 2)) >> 1))) | (-(v810 ^ ((int)((unsigned int)((int)((unsigned int)v805 >> 2)) >> 1))))) >> 31))) & 104)))));
  v797->timer = v924;
  int * v813 = v797->cache_vals;
  bool v925 = !(((~(((v807 ^ ((int)((unsigned int)((int)((unsigned int)v805 >> 2)) >> 1))) | (-(v807 ^ ((int)((unsigned int)((int)((unsigned int)v805 >> 2)) >> 1))))) >> 31)) | (~(((v808 ^ ((int)((unsigned int)((int)((unsigned int)v805 >> 2)) >> 1))) | (-(v808 ^ ((int)((unsigned int)((int)((unsigned int)v805 >> 2)) >> 1))))) >> 31))) == 0);
  int v906;
  if (v925) {
    int * v814 = v797->cache_age;
    int v927 = ((((int)((unsigned int)((int)((unsigned int)v805 >> 2)) >> 1)) & 1) * 2) + ((~(((v808 ^ ((int)((unsigned int)((int)((unsigned int)v805 >> 2)) >> 1))) | (-(v808 ^ ((int)((unsigned int)((int)((unsigned int)v805 >> 2)) >> 1))))) >> 31)) & 1);
    int v815 = v814[v927];
    int v816 = v814[v920];
    int v928 = v816 + ((int)((unsigned int)(v816 - v815) >> 31));
    v814[v920] = v928;
    int * v818 = v797->cache_age;
    int v819 = v818[v921];
    int v930 = v819 + ((int)((unsigned int)(v819 - v815) >> 31));
    v818[v921] = v930;
    int * v821 = v797->cache_age;
    v821[v927] = 0;
    v906 = v927;
  } else {
    int * v824 = v797->cache_age;
    int v934 = (((int)((unsigned int)((int)((unsigned int)v805 >> 2)) >> 1)) & 1) * 2;
    int v825 = v824[v934];
    int * v826 = v797->cache_tags;
    int v827 = v826[v934];
    int v828 = v824[v921];
    int v829 = v826[v921];
    bool v936 = !(((~(((v809 ^ ((int)((unsigned int)((int)((unsigned int)v805 >> 2)) >> 1))) | (-(v809 ^ ((int)((unsigned int)((int)((unsigned int)v805 >> 2)) >> 1))))) >> 31)) | (~(((v810 ^ ((int)((unsigned int)((int)((unsigned int)v805 >> 2)) >> 1))) | (-(v810 ^ ((int)((unsigned int)((int)((unsigned int)v805 >> 2)) >> 1))))) >> 31))) == 0);
    int v883;
    if (v936) {
      int * v830 = v797->cache_age;
      int v938 = (4 + ((((int)((unsigned int)((int)((unsigned int)v805 >> 2)) >> 1)) & 3) * 2)) + ((~(((v810 ^ ((int)((unsigned int)((int)((unsigned int)v805 >> 2)) >> 1))) | (-(v810 ^ ((int)((unsigned int)((int)((unsigned int)v805 >> 2)) >> 1))))) >> 31)) & 1);
      int v831 = v830[v938];
      int v832 = v830[v922];
      int v939 = v832 + ((int)((unsigned int)(v832 - v831) >> 31));
      v830[v922] = v939;
      int * v834 = v797->cache_age;
      int v835 = v834[v923];
      int v941 = v835 + ((int)((unsigned int)(v835 - v831) >> 31));
      v834[v923] = v941;
      int * v837 = v797->cache_age;
      v837[v938] = 0;
      v883 = v938;
    } else {
      int * v840 = v797->cache_age;
      int v945 = 4 + ((((int)((unsigned int)((int)((unsigned int)v805 >> 2)) >> 1)) & 3) * 2);
      int v841 = v840[v945];
      int * v842 = v797->cache_tags;
      int v843 = v842[v945];
      int v844 = v840[v923];
      int v845 = v842[v923];
      int * v846 = v797->cache_dirty;
      int v948 = (4 + ((((int)((unsigned int)((int)((unsigned int)v805 >> 2)) >> 1)) & 3) * 2)) + ((((v841 + ((~(((v843 ^ -1) | (-(v843 ^ -1))) >> 31)) & 2)) - (v844 + ((~(((v845 ^ -1) | (-(v845 ^ -1))) >> 31)) & 2))) >> 31) & 1);
      int v847 = v846[v948];
      bool v949 = !(v847 == 0);
      if (v949) {
        int * v848 = v797->cache_tags;
        int v849 = v848[v948];
        int * v850 = v797->cache_vals;
        int v952 = ((4 + ((((int)((unsigned int)((int)((unsigned int)v805 >> 2)) >> 1)) & 3) * 2)) + ((((v841 + ((~(((v843 ^ -1) | (-(v843 ^ -1))) >> 31)) & 2)) - (v844 + ((~(((v845 ^ -1) | (-(v845 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
        int v851 = v850[v952];
        int v953 = (((4 + ((((int)((unsigned int)((int)((unsigned int)v805 >> 2)) >> 1)) & 3) * 2)) + ((((v841 + ((~(((v843 ^ -1) | (-(v843 ^ -1))) >> 31)) & 2)) - (v844 + ((~(((v845 ^ -1) | (-(v845 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
        int v852 = v850[v953];
        int * v853 = v797->mem;
        int v955 = v849 * 2;
        v853[v955] = v851;
        int * v855 = v797->mem;
        int v958 = (v849 * 2) + 1;
        v855[v958] = v852;
        ;
      } else {
        ;
      }
      int * v860 = v797->mem;
      int v963 = ((int)((unsigned int)((int)((unsigned int)v805 >> 2)) >> 1)) * 2;
      int v861 = v860[v963];
      int v964 = (((int)((unsigned int)((int)((unsigned int)v805 >> 2)) >> 1)) * 2) + 1;
      int v862 = v860[v964];
      int * v863 = v797->cache_vals;
      int v966 = ((4 + ((((int)((unsigned int)((int)((unsigned int)v805 >> 2)) >> 1)) & 3) * 2)) + ((((v841 + ((~(((v843 ^ -1) | (-(v843 ^ -1))) >> 31)) & 2)) - (v844 + ((~(((v845 ^ -1) | (-(v845 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
      v863[v966] = v861;
      int * v865 = v797->cache_vals;
      int v969 = (((4 + ((((int)((unsigned int)((int)((unsigned int)v805 >> 2)) >> 1)) & 3) * 2)) + ((((v841 + ((~(((v843 ^ -1) | (-(v843 ^ -1))) >> 31)) & 2)) - (v844 + ((~(((v845 ^ -1) | (-(v845 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
      v865[v969] = v862;
      int * v867 = v797->cache_tags;
      int v972 = (int)((unsigned int)((int)((unsigned int)v805 >> 2)) >> 1);
      v867[v948] = v972;
      int * v869 = v797->cache_dirty;
      v869[v948] = 0;
      int * v871 = v797->cache_age;
      v871[v948] = 1;
      int * v873 = v797->cache_age;
      int v874 = v873[v948];
      int v875 = v873[v922];
      int v978 = v875 + ((int)((unsigned int)(v875 - v874) >> 31));
      v873[v922] = v978;
      int * v877 = v797->cache_age;
      int v878 = v877[v923];
      int v980 = v878 + ((int)((unsigned int)(v878 - v874) >> 31));
      v877[v923] = v980;
      int * v880 = v797->cache_age;
      v880[v948] = 0;
      v883 = v948;
    }
    int * v884 = v797->cache_vals;
    int v983 = v883 * 2;
    int v885 = v884[v983];
    int v984 = (v883 * 2) + 1;
    int v886 = v884[v984];
    int v985 = (((((int)((unsigned int)((int)((unsigned int)v805 >> 2)) >> 1)) & 1) * 2) + ((((v825 + ((~(((v827 ^ -1) | (-(v827 ^ -1))) >> 31)) & 2)) - (v828 + ((~(((v829 ^ -1) | (-(v829 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
    v884[v985] = v885;
    int * v888 = v797->cache_vals;
    int v988 = ((((((int)((unsigned int)((int)((unsigned int)v805 >> 2)) >> 1)) & 1) * 2) + ((((v825 + ((~(((v827 ^ -1) | (-(v827 ^ -1))) >> 31)) & 2)) - (v828 + ((~(((v829 ^ -1) | (-(v829 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
    v888[v988] = v886;
    int * v890 = v797->cache_tags;
    int v991 = ((((int)((unsigned int)((int)((unsigned int)v805 >> 2)) >> 1)) & 1) * 2) + ((((v825 + ((~(((v827 ^ -1) | (-(v827 ^ -1))) >> 31)) & 2)) - (v828 + ((~(((v829 ^ -1) | (-(v829 ^ -1))) >> 31)) & 2))) >> 31) & 1);
    int v992 = (int)((unsigned int)((int)((unsigned int)v805 >> 2)) >> 1);
    v890[v991] = v992;
    int * v892 = v797->cache_dirty;
    v892[v991] = 0;
    int * v894 = v797->cache_age;
    v894[v991] = 1;
    int * v896 = v797->cache_age;
    int v897 = v896[v991];
    int v898 = v896[v920];
    int v998 = v898 + ((int)((unsigned int)(v898 - v897) >> 31));
    v896[v920] = v998;
    int * v900 = v797->cache_age;
    int v901 = v900[v921];
    int v1000 = v901 + ((int)((unsigned int)(v901 - v897) >> 31));
    v900[v921] = v1000;
    int * v903 = v797->cache_age;
    v903[v991] = 0;
    v906 = v991;
  }
  int v1003 = (v906 * 2) + (((int)((unsigned int)v805 >> 2)) & 1);
  int v907 = v813[v1003];
  int * v908 = v797->regs;
  v908[7] = v907;
  struct StateT * v910 = slot_14(v797);
  return v910;
}

struct StateT * slot_38(struct StateT * v2985) {
  int v2986 = v2985->timer;
  int v2993 = v2986 + 1;
  v2985->timer = v2993;
  int * v2988 = v2985->regs;
  int v2989 = v2988[14];
  int v2997 = v2989 << 3;
  v2988[15] = v2997;
  struct StateT * v2991 = slot_39(v2985);
  return v2991;
}

struct StateT * slot_24(struct StateT * v1492) {
  int v1493 = v1492->timer;
  int v1663 = v1493 + 1;
  v1492->timer = v1663;
  int * v1495 = v1492->regs;
  int v1496 = v1495[16];
  int v1497 = v1495[6];
  int * v1498 = v1492->cache_tags;
  int v1668 = (((int)((unsigned int)((int)((unsigned int)(v1496 + 4) >> 2)) >> 1)) & 1) * 2;
  int v1499 = v1498[v1668];
  int v1669 = ((((int)((unsigned int)((int)((unsigned int)(v1496 + 4) >> 2)) >> 1)) & 1) * 2) + 1;
  int v1500 = v1498[v1669];
  int v1670 = 4 + ((((int)((unsigned int)((int)((unsigned int)(v1496 + 4) >> 2)) >> 1)) & 3) * 2);
  int v1501 = v1498[v1670];
  int v1671 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v1496 + 4) >> 2)) >> 1)) & 3) * 2)) + 1;
  int v1502 = v1498[v1671];
  int v1503 = v1492->timer;
  int v1672 = v1503 + ((100 ^ (((~(((v1501 ^ ((int)((unsigned int)((int)((unsigned int)(v1496 + 4) >> 2)) >> 1))) | (-(v1501 ^ ((int)((unsigned int)((int)((unsigned int)(v1496 + 4) >> 2)) >> 1))))) >> 31)) | (~(((v1502 ^ ((int)((unsigned int)((int)((unsigned int)(v1496 + 4) >> 2)) >> 1))) | (-(v1502 ^ ((int)((unsigned int)((int)((unsigned int)(v1496 + 4) >> 2)) >> 1))))) >> 31))) & 104)) ^ (((~(((v1499 ^ ((int)((unsigned int)((int)((unsigned int)(v1496 + 4) >> 2)) >> 1))) | (-(v1499 ^ ((int)((unsigned int)((int)((unsigned int)(v1496 + 4) >> 2)) >> 1))))) >> 31)) | (~(((v1500 ^ ((int)((unsigned int)((int)((unsigned int)(v1496 + 4) >> 2)) >> 1))) | (-(v1500 ^ ((int)((unsigned int)((int)((unsigned int)(v1496 + 4) >> 2)) >> 1))))) >> 31))) & (1 ^ (100 ^ (((~(((v1501 ^ ((int)((unsigned int)((int)((unsigned int)(v1496 + 4) >> 2)) >> 1))) | (-(v1501 ^ ((int)((unsigned int)((int)((unsigned int)(v1496 + 4) >> 2)) >> 1))))) >> 31)) | (~(((v1502 ^ ((int)((unsigned int)((int)((unsigned int)(v1496 + 4) >> 2)) >> 1))) | (-(v1502 ^ ((int)((unsigned int)((int)((unsigned int)(v1496 + 4) >> 2)) >> 1))))) >> 31))) & 104)))));
  v1492->timer = v1672;
  bool v1673 = !(((~(((v1499 ^ ((int)((unsigned int)((int)((unsigned int)(v1496 + 4) >> 2)) >> 1))) | (-(v1499 ^ ((int)((unsigned int)((int)((unsigned int)(v1496 + 4) >> 2)) >> 1))))) >> 31)) | (~(((v1500 ^ ((int)((unsigned int)((int)((unsigned int)(v1496 + 4) >> 2)) >> 1))) | (-(v1500 ^ ((int)((unsigned int)((int)((unsigned int)(v1496 + 4) >> 2)) >> 1))))) >> 31))) == 0);
  int v1597;
  if (v1673) {
    int * v1505 = v1492->cache_age;
    int v1675 = ((((int)((unsigned int)((int)((unsigned int)(v1496 + 4) >> 2)) >> 1)) & 1) * 2) + ((~(((v1500 ^ ((int)((unsigned int)((int)((unsigned int)(v1496 + 4) >> 2)) >> 1))) | (-(v1500 ^ ((int)((unsigned int)((int)((unsigned int)(v1496 + 4) >> 2)) >> 1))))) >> 31)) & 1);
    int v1506 = v1505[v1675];
    int v1507 = v1505[v1668];
    int v1676 = v1507 + ((int)((unsigned int)(v1507 - v1506) >> 31));
    v1505[v1668] = v1676;
    int * v1509 = v1492->cache_age;
    int v1510 = v1509[v1669];
    int v1678 = v1510 + ((int)((unsigned int)(v1510 - v1506) >> 31));
    v1509[v1669] = v1678;
    int * v1512 = v1492->cache_age;
    v1512[v1675] = 0;
    v1597 = v1675;
  } else {
    int * v1515 = v1492->cache_age;
    int v1682 = (((int)((unsigned int)((int)((unsigned int)(v1496 + 4) >> 2)) >> 1)) & 1) * 2;
    int v1516 = v1515[v1682];
    int * v1517 = v1492->cache_tags;
    int v1518 = v1517[v1682];
    int v1519 = v1515[v1669];
    int v1520 = v1517[v1669];
    bool v1684 = !(((~(((v1501 ^ ((int)((unsigned int)((int)((unsigned int)(v1496 + 4) >> 2)) >> 1))) | (-(v1501 ^ ((int)((unsigned int)((int)((unsigned int)(v1496 + 4) >> 2)) >> 1))))) >> 31)) | (~(((v1502 ^ ((int)((unsigned int)((int)((unsigned int)(v1496 + 4) >> 2)) >> 1))) | (-(v1502 ^ ((int)((unsigned int)((int)((unsigned int)(v1496 + 4) >> 2)) >> 1))))) >> 31))) == 0);
    int v1574;
    if (v1684) {
      int * v1521 = v1492->cache_age;
      int v1686 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v1496 + 4) >> 2)) >> 1)) & 3) * 2)) + ((~(((v1502 ^ ((int)((unsigned int)((int)((unsigned int)(v1496 + 4) >> 2)) >> 1))) | (-(v1502 ^ ((int)((unsigned int)((int)((unsigned int)(v1496 + 4) >> 2)) >> 1))))) >> 31)) & 1);
      int v1522 = v1521[v1686];
      int v1523 = v1521[v1670];
      int v1687 = v1523 + ((int)((unsigned int)(v1523 - v1522) >> 31));
      v1521[v1670] = v1687;
      int * v1525 = v1492->cache_age;
      int v1526 = v1525[v1671];
      int v1689 = v1526 + ((int)((unsigned int)(v1526 - v1522) >> 31));
      v1525[v1671] = v1689;
      int * v1528 = v1492->cache_age;
      v1528[v1686] = 0;
      v1574 = v1686;
    } else {
      int * v1531 = v1492->cache_age;
      int v1693 = 4 + ((((int)((unsigned int)((int)((unsigned int)(v1496 + 4) >> 2)) >> 1)) & 3) * 2);
      int v1532 = v1531[v1693];
      int * v1533 = v1492->cache_tags;
      int v1534 = v1533[v1693];
      int v1535 = v1531[v1671];
      int v1536 = v1533[v1671];
      int * v1537 = v1492->cache_dirty;
      int v1696 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v1496 + 4) >> 2)) >> 1)) & 3) * 2)) + ((((v1532 + ((~(((v1534 ^ -1) | (-(v1534 ^ -1))) >> 31)) & 2)) - (v1535 + ((~(((v1536 ^ -1) | (-(v1536 ^ -1))) >> 31)) & 2))) >> 31) & 1);
      int v1538 = v1537[v1696];
      bool v1697 = !(v1538 == 0);
      if (v1697) {
        int * v1539 = v1492->cache_tags;
        int v1540 = v1539[v1696];
        int * v1541 = v1492->cache_vals;
        int v1700 = ((4 + ((((int)((unsigned int)((int)((unsigned int)(v1496 + 4) >> 2)) >> 1)) & 3) * 2)) + ((((v1532 + ((~(((v1534 ^ -1) | (-(v1534 ^ -1))) >> 31)) & 2)) - (v1535 + ((~(((v1536 ^ -1) | (-(v1536 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
        int v1542 = v1541[v1700];
        int v1701 = (((4 + ((((int)((unsigned int)((int)((unsigned int)(v1496 + 4) >> 2)) >> 1)) & 3) * 2)) + ((((v1532 + ((~(((v1534 ^ -1) | (-(v1534 ^ -1))) >> 31)) & 2)) - (v1535 + ((~(((v1536 ^ -1) | (-(v1536 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
        int v1543 = v1541[v1701];
        int * v1544 = v1492->mem;
        int v1703 = v1540 * 2;
        v1544[v1703] = v1542;
        int * v1546 = v1492->mem;
        int v1706 = (v1540 * 2) + 1;
        v1546[v1706] = v1543;
        ;
      } else {
        ;
      }
      int * v1551 = v1492->mem;
      int v1711 = ((int)((unsigned int)((int)((unsigned int)(v1496 + 4) >> 2)) >> 1)) * 2;
      int v1552 = v1551[v1711];
      int v1712 = (((int)((unsigned int)((int)((unsigned int)(v1496 + 4) >> 2)) >> 1)) * 2) + 1;
      int v1553 = v1551[v1712];
      int * v1554 = v1492->cache_vals;
      int v1714 = ((4 + ((((int)((unsigned int)((int)((unsigned int)(v1496 + 4) >> 2)) >> 1)) & 3) * 2)) + ((((v1532 + ((~(((v1534 ^ -1) | (-(v1534 ^ -1))) >> 31)) & 2)) - (v1535 + ((~(((v1536 ^ -1) | (-(v1536 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
      v1554[v1714] = v1552;
      int * v1556 = v1492->cache_vals;
      int v1717 = (((4 + ((((int)((unsigned int)((int)((unsigned int)(v1496 + 4) >> 2)) >> 1)) & 3) * 2)) + ((((v1532 + ((~(((v1534 ^ -1) | (-(v1534 ^ -1))) >> 31)) & 2)) - (v1535 + ((~(((v1536 ^ -1) | (-(v1536 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
      v1556[v1717] = v1553;
      int * v1558 = v1492->cache_tags;
      int v1720 = (int)((unsigned int)((int)((unsigned int)(v1496 + 4) >> 2)) >> 1);
      v1558[v1696] = v1720;
      int * v1560 = v1492->cache_dirty;
      v1560[v1696] = 0;
      int * v1562 = v1492->cache_age;
      v1562[v1696] = 1;
      int * v1564 = v1492->cache_age;
      int v1565 = v1564[v1696];
      int v1566 = v1564[v1670];
      int v1726 = v1566 + ((int)((unsigned int)(v1566 - v1565) >> 31));
      v1564[v1670] = v1726;
      int * v1568 = v1492->cache_age;
      int v1569 = v1568[v1671];
      int v1728 = v1569 + ((int)((unsigned int)(v1569 - v1565) >> 31));
      v1568[v1671] = v1728;
      int * v1571 = v1492->cache_age;
      v1571[v1696] = 0;
      v1574 = v1696;
    }
    int * v1575 = v1492->cache_vals;
    int v1731 = v1574 * 2;
    int v1576 = v1575[v1731];
    int v1732 = (v1574 * 2) + 1;
    int v1577 = v1575[v1732];
    int v1733 = (((((int)((unsigned int)((int)((unsigned int)(v1496 + 4) >> 2)) >> 1)) & 1) * 2) + ((((v1516 + ((~(((v1518 ^ -1) | (-(v1518 ^ -1))) >> 31)) & 2)) - (v1519 + ((~(((v1520 ^ -1) | (-(v1520 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
    v1575[v1733] = v1576;
    int * v1579 = v1492->cache_vals;
    int v1736 = ((((((int)((unsigned int)((int)((unsigned int)(v1496 + 4) >> 2)) >> 1)) & 1) * 2) + ((((v1516 + ((~(((v1518 ^ -1) | (-(v1518 ^ -1))) >> 31)) & 2)) - (v1519 + ((~(((v1520 ^ -1) | (-(v1520 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
    v1579[v1736] = v1577;
    int * v1581 = v1492->cache_tags;
    int v1739 = ((((int)((unsigned int)((int)((unsigned int)(v1496 + 4) >> 2)) >> 1)) & 1) * 2) + ((((v1516 + ((~(((v1518 ^ -1) | (-(v1518 ^ -1))) >> 31)) & 2)) - (v1519 + ((~(((v1520 ^ -1) | (-(v1520 ^ -1))) >> 31)) & 2))) >> 31) & 1);
    int v1740 = (int)((unsigned int)((int)((unsigned int)(v1496 + 4) >> 2)) >> 1);
    v1581[v1739] = v1740;
    int * v1583 = v1492->cache_dirty;
    v1583[v1739] = 0;
    int * v1585 = v1492->cache_age;
    v1585[v1739] = 1;
    int * v1587 = v1492->cache_age;
    int v1588 = v1587[v1739];
    int v1589 = v1587[v1668];
    int v1746 = v1589 + ((int)((unsigned int)(v1589 - v1588) >> 31));
    v1587[v1668] = v1746;
    int * v1591 = v1492->cache_age;
    int v1592 = v1591[v1669];
    int v1748 = v1592 + ((int)((unsigned int)(v1592 - v1588) >> 31));
    v1591[v1669] = v1748;
    int * v1594 = v1492->cache_age;
    v1594[v1739] = 0;
    v1597 = v1739;
  }
  int * v1598 = v1492->cache_vals;
  int v1751 = (v1597 * 2) + (((int)((unsigned int)(v1496 + 4) >> 2)) & 1);
  v1598[v1751] = v1497;
  int * v1600 = v1492->cache_tags;
  int v1601 = v1600[v1670];
  int v1602 = v1600[v1671];
  bool v1754 = !(((~(((v1601 ^ ((int)((unsigned int)((int)((unsigned int)(v1496 + 4) >> 2)) >> 1))) | (-(v1601 ^ ((int)((unsigned int)((int)((unsigned int)(v1496 + 4) >> 2)) >> 1))))) >> 31)) | (~(((v1602 ^ ((int)((unsigned int)((int)((unsigned int)(v1496 + 4) >> 2)) >> 1))) | (-(v1602 ^ ((int)((unsigned int)((int)((unsigned int)(v1496 + 4) >> 2)) >> 1))))) >> 31))) == 0);
  int v1656;
  if (v1754) {
    int * v1603 = v1492->cache_age;
    int v1756 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v1496 + 4) >> 2)) >> 1)) & 3) * 2)) + ((~(((v1602 ^ ((int)((unsigned int)((int)((unsigned int)(v1496 + 4) >> 2)) >> 1))) | (-(v1602 ^ ((int)((unsigned int)((int)((unsigned int)(v1496 + 4) >> 2)) >> 1))))) >> 31)) & 1);
    int v1604 = v1603[v1756];
    int v1605 = v1603[v1670];
    int v1757 = v1605 + ((int)((unsigned int)(v1605 - v1604) >> 31));
    v1603[v1670] = v1757;
    int * v1607 = v1492->cache_age;
    int v1608 = v1607[v1671];
    int v1759 = v1608 + ((int)((unsigned int)(v1608 - v1604) >> 31));
    v1607[v1671] = v1759;
    int * v1610 = v1492->cache_age;
    v1610[v1756] = 0;
    v1656 = v1756;
  } else {
    int * v1613 = v1492->cache_age;
    int v1763 = 4 + ((((int)((unsigned int)((int)((unsigned int)(v1496 + 4) >> 2)) >> 1)) & 3) * 2);
    int v1614 = v1613[v1763];
    int * v1615 = v1492->cache_tags;
    int v1616 = v1615[v1763];
    int v1617 = v1613[v1671];
    int v1618 = v1615[v1671];
    int * v1619 = v1492->cache_dirty;
    int v1766 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v1496 + 4) >> 2)) >> 1)) & 3) * 2)) + ((((v1614 + ((~(((v1616 ^ -1) | (-(v1616 ^ -1))) >> 31)) & 2)) - (v1617 + ((~(((v1618 ^ -1) | (-(v1618 ^ -1))) >> 31)) & 2))) >> 31) & 1);
    int v1620 = v1619[v1766];
    bool v1767 = !(v1620 == 0);
    if (v1767) {
      int * v1621 = v1492->cache_tags;
      int v1622 = v1621[v1766];
      int * v1623 = v1492->cache_vals;
      int v1770 = ((4 + ((((int)((unsigned int)((int)((unsigned int)(v1496 + 4) >> 2)) >> 1)) & 3) * 2)) + ((((v1614 + ((~(((v1616 ^ -1) | (-(v1616 ^ -1))) >> 31)) & 2)) - (v1617 + ((~(((v1618 ^ -1) | (-(v1618 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
      int v1624 = v1623[v1770];
      int v1771 = (((4 + ((((int)((unsigned int)((int)((unsigned int)(v1496 + 4) >> 2)) >> 1)) & 3) * 2)) + ((((v1614 + ((~(((v1616 ^ -1) | (-(v1616 ^ -1))) >> 31)) & 2)) - (v1617 + ((~(((v1618 ^ -1) | (-(v1618 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
      int v1625 = v1623[v1771];
      int * v1626 = v1492->mem;
      int v1773 = v1622 * 2;
      v1626[v1773] = v1624;
      int * v1628 = v1492->mem;
      int v1776 = (v1622 * 2) + 1;
      v1628[v1776] = v1625;
      ;
    } else {
      ;
    }
    int * v1633 = v1492->mem;
    int v1781 = ((int)((unsigned int)((int)((unsigned int)(v1496 + 4) >> 2)) >> 1)) * 2;
    int v1634 = v1633[v1781];
    int v1782 = (((int)((unsigned int)((int)((unsigned int)(v1496 + 4) >> 2)) >> 1)) * 2) + 1;
    int v1635 = v1633[v1782];
    int * v1636 = v1492->cache_vals;
    int v1784 = ((4 + ((((int)((unsigned int)((int)((unsigned int)(v1496 + 4) >> 2)) >> 1)) & 3) * 2)) + ((((v1614 + ((~(((v1616 ^ -1) | (-(v1616 ^ -1))) >> 31)) & 2)) - (v1617 + ((~(((v1618 ^ -1) | (-(v1618 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
    v1636[v1784] = v1634;
    int * v1638 = v1492->cache_vals;
    int v1787 = (((4 + ((((int)((unsigned int)((int)((unsigned int)(v1496 + 4) >> 2)) >> 1)) & 3) * 2)) + ((((v1614 + ((~(((v1616 ^ -1) | (-(v1616 ^ -1))) >> 31)) & 2)) - (v1617 + ((~(((v1618 ^ -1) | (-(v1618 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
    v1638[v1787] = v1635;
    int * v1640 = v1492->cache_tags;
    int v1790 = (int)((unsigned int)((int)((unsigned int)(v1496 + 4) >> 2)) >> 1);
    v1640[v1766] = v1790;
    int * v1642 = v1492->cache_dirty;
    v1642[v1766] = 0;
    int * v1644 = v1492->cache_age;
    v1644[v1766] = 1;
    int * v1646 = v1492->cache_age;
    int v1647 = v1646[v1766];
    int v1648 = v1646[v1670];
    int v1796 = v1648 + ((int)((unsigned int)(v1648 - v1647) >> 31));
    v1646[v1670] = v1796;
    int * v1650 = v1492->cache_age;
    int v1651 = v1650[v1671];
    int v1798 = v1651 + ((int)((unsigned int)(v1651 - v1647) >> 31));
    v1650[v1671] = v1798;
    int * v1653 = v1492->cache_age;
    v1653[v1766] = 0;
    v1656 = v1766;
  }
  int * v1657 = v1492->cache_vals;
  int v1801 = (v1656 * 2) + (((int)((unsigned int)(v1496 + 4) >> 2)) & 1);
  v1657[v1801] = v1497;
  int * v1659 = v1492->cache_dirty;
  v1659[v1656] = 1;
  struct StateT * v1661 = slot_25(v1492);
  return v1661;
}

struct StateT * slot_0(struct StateT * v2) {
  int v3 = v2->timer;
  int v9 = v3 + 1;
  v2->timer = v9;
  int * v5 = v2->regs;
  v5[14] = 0;
  struct StateT * v7 = slot_1(v2);
  return v7;
}

struct StateT * slot_42(struct StateT * v3237) {
  int v3238 = v3237->timer;
  int v3348 = v3238 + 1;
  v3237->timer = v3348;
  int * v3240 = v3237->regs;
  int v3241 = v3240[16];
  int * v3242 = v3237->cache_tags;
  int v3352 = (((int)((unsigned int)((int)((unsigned int)(v3241 + 4) >> 2)) >> 1)) & 1) * 2;
  int v3243 = v3242[v3352];
  int v3353 = ((((int)((unsigned int)((int)((unsigned int)(v3241 + 4) >> 2)) >> 1)) & 1) * 2) + 1;
  int v3244 = v3242[v3353];
  int v3354 = 4 + ((((int)((unsigned int)((int)((unsigned int)(v3241 + 4) >> 2)) >> 1)) & 3) * 2);
  int v3245 = v3242[v3354];
  int v3355 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v3241 + 4) >> 2)) >> 1)) & 3) * 2)) + 1;
  int v3246 = v3242[v3355];
  int v3247 = v3237->timer;
  int v3356 = v3247 + ((100 ^ (((~(((v3245 ^ ((int)((unsigned int)((int)((unsigned int)(v3241 + 4) >> 2)) >> 1))) | (-(v3245 ^ ((int)((unsigned int)((int)((unsigned int)(v3241 + 4) >> 2)) >> 1))))) >> 31)) | (~(((v3246 ^ ((int)((unsigned int)((int)((unsigned int)(v3241 + 4) >> 2)) >> 1))) | (-(v3246 ^ ((int)((unsigned int)((int)((unsigned int)(v3241 + 4) >> 2)) >> 1))))) >> 31))) & 104)) ^ (((~(((v3243 ^ ((int)((unsigned int)((int)((unsigned int)(v3241 + 4) >> 2)) >> 1))) | (-(v3243 ^ ((int)((unsigned int)((int)((unsigned int)(v3241 + 4) >> 2)) >> 1))))) >> 31)) | (~(((v3244 ^ ((int)((unsigned int)((int)((unsigned int)(v3241 + 4) >> 2)) >> 1))) | (-(v3244 ^ ((int)((unsigned int)((int)((unsigned int)(v3241 + 4) >> 2)) >> 1))))) >> 31))) & (1 ^ (100 ^ (((~(((v3245 ^ ((int)((unsigned int)((int)((unsigned int)(v3241 + 4) >> 2)) >> 1))) | (-(v3245 ^ ((int)((unsigned int)((int)((unsigned int)(v3241 + 4) >> 2)) >> 1))))) >> 31)) | (~(((v3246 ^ ((int)((unsigned int)((int)((unsigned int)(v3241 + 4) >> 2)) >> 1))) | (-(v3246 ^ ((int)((unsigned int)((int)((unsigned int)(v3241 + 4) >> 2)) >> 1))))) >> 31))) & 104)))));
  v3237->timer = v3356;
  int * v3249 = v3237->cache_vals;
  bool v3357 = !(((~(((v3243 ^ ((int)((unsigned int)((int)((unsigned int)(v3241 + 4) >> 2)) >> 1))) | (-(v3243 ^ ((int)((unsigned int)((int)((unsigned int)(v3241 + 4) >> 2)) >> 1))))) >> 31)) | (~(((v3244 ^ ((int)((unsigned int)((int)((unsigned int)(v3241 + 4) >> 2)) >> 1))) | (-(v3244 ^ ((int)((unsigned int)((int)((unsigned int)(v3241 + 4) >> 2)) >> 1))))) >> 31))) == 0);
  int v3342;
  if (v3357) {
    int * v3250 = v3237->cache_age;
    int v3359 = ((((int)((unsigned int)((int)((unsigned int)(v3241 + 4) >> 2)) >> 1)) & 1) * 2) + ((~(((v3244 ^ ((int)((unsigned int)((int)((unsigned int)(v3241 + 4) >> 2)) >> 1))) | (-(v3244 ^ ((int)((unsigned int)((int)((unsigned int)(v3241 + 4) >> 2)) >> 1))))) >> 31)) & 1);
    int v3251 = v3250[v3359];
    int v3252 = v3250[v3352];
    int v3360 = v3252 + ((int)((unsigned int)(v3252 - v3251) >> 31));
    v3250[v3352] = v3360;
    int * v3254 = v3237->cache_age;
    int v3255 = v3254[v3353];
    int v3362 = v3255 + ((int)((unsigned int)(v3255 - v3251) >> 31));
    v3254[v3353] = v3362;
    int * v3257 = v3237->cache_age;
    v3257[v3359] = 0;
    v3342 = v3359;
  } else {
    int * v3260 = v3237->cache_age;
    int v3366 = (((int)((unsigned int)((int)((unsigned int)(v3241 + 4) >> 2)) >> 1)) & 1) * 2;
    int v3261 = v3260[v3366];
    int * v3262 = v3237->cache_tags;
    int v3263 = v3262[v3366];
    int v3264 = v3260[v3353];
    int v3265 = v3262[v3353];
    bool v3368 = !(((~(((v3245 ^ ((int)((unsigned int)((int)((unsigned int)(v3241 + 4) >> 2)) >> 1))) | (-(v3245 ^ ((int)((unsigned int)((int)((unsigned int)(v3241 + 4) >> 2)) >> 1))))) >> 31)) | (~(((v3246 ^ ((int)((unsigned int)((int)((unsigned int)(v3241 + 4) >> 2)) >> 1))) | (-(v3246 ^ ((int)((unsigned int)((int)((unsigned int)(v3241 + 4) >> 2)) >> 1))))) >> 31))) == 0);
    int v3319;
    if (v3368) {
      int * v3266 = v3237->cache_age;
      int v3370 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v3241 + 4) >> 2)) >> 1)) & 3) * 2)) + ((~(((v3246 ^ ((int)((unsigned int)((int)((unsigned int)(v3241 + 4) >> 2)) >> 1))) | (-(v3246 ^ ((int)((unsigned int)((int)((unsigned int)(v3241 + 4) >> 2)) >> 1))))) >> 31)) & 1);
      int v3267 = v3266[v3370];
      int v3268 = v3266[v3354];
      int v3371 = v3268 + ((int)((unsigned int)(v3268 - v3267) >> 31));
      v3266[v3354] = v3371;
      int * v3270 = v3237->cache_age;
      int v3271 = v3270[v3355];
      int v3373 = v3271 + ((int)((unsigned int)(v3271 - v3267) >> 31));
      v3270[v3355] = v3373;
      int * v3273 = v3237->cache_age;
      v3273[v3370] = 0;
      v3319 = v3370;
    } else {
      int * v3276 = v3237->cache_age;
      int v3377 = 4 + ((((int)((unsigned int)((int)((unsigned int)(v3241 + 4) >> 2)) >> 1)) & 3) * 2);
      int v3277 = v3276[v3377];
      int * v3278 = v3237->cache_tags;
      int v3279 = v3278[v3377];
      int v3280 = v3276[v3355];
      int v3281 = v3278[v3355];
      int * v3282 = v3237->cache_dirty;
      int v3380 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v3241 + 4) >> 2)) >> 1)) & 3) * 2)) + ((((v3277 + ((~(((v3279 ^ -1) | (-(v3279 ^ -1))) >> 31)) & 2)) - (v3280 + ((~(((v3281 ^ -1) | (-(v3281 ^ -1))) >> 31)) & 2))) >> 31) & 1);
      int v3283 = v3282[v3380];
      bool v3381 = !(v3283 == 0);
      if (v3381) {
        int * v3284 = v3237->cache_tags;
        int v3285 = v3284[v3380];
        int * v3286 = v3237->cache_vals;
        int v3384 = ((4 + ((((int)((unsigned int)((int)((unsigned int)(v3241 + 4) >> 2)) >> 1)) & 3) * 2)) + ((((v3277 + ((~(((v3279 ^ -1) | (-(v3279 ^ -1))) >> 31)) & 2)) - (v3280 + ((~(((v3281 ^ -1) | (-(v3281 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
        int v3287 = v3286[v3384];
        int v3385 = (((4 + ((((int)((unsigned int)((int)((unsigned int)(v3241 + 4) >> 2)) >> 1)) & 3) * 2)) + ((((v3277 + ((~(((v3279 ^ -1) | (-(v3279 ^ -1))) >> 31)) & 2)) - (v3280 + ((~(((v3281 ^ -1) | (-(v3281 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
        int v3288 = v3286[v3385];
        int * v3289 = v3237->mem;
        int v3387 = v3285 * 2;
        v3289[v3387] = v3287;
        int * v3291 = v3237->mem;
        int v3390 = (v3285 * 2) + 1;
        v3291[v3390] = v3288;
        ;
      } else {
        ;
      }
      int * v3296 = v3237->mem;
      int v3395 = ((int)((unsigned int)((int)((unsigned int)(v3241 + 4) >> 2)) >> 1)) * 2;
      int v3297 = v3296[v3395];
      int v3396 = (((int)((unsigned int)((int)((unsigned int)(v3241 + 4) >> 2)) >> 1)) * 2) + 1;
      int v3298 = v3296[v3396];
      int * v3299 = v3237->cache_vals;
      int v3398 = ((4 + ((((int)((unsigned int)((int)((unsigned int)(v3241 + 4) >> 2)) >> 1)) & 3) * 2)) + ((((v3277 + ((~(((v3279 ^ -1) | (-(v3279 ^ -1))) >> 31)) & 2)) - (v3280 + ((~(((v3281 ^ -1) | (-(v3281 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
      v3299[v3398] = v3297;
      int * v3301 = v3237->cache_vals;
      int v3401 = (((4 + ((((int)((unsigned int)((int)((unsigned int)(v3241 + 4) >> 2)) >> 1)) & 3) * 2)) + ((((v3277 + ((~(((v3279 ^ -1) | (-(v3279 ^ -1))) >> 31)) & 2)) - (v3280 + ((~(((v3281 ^ -1) | (-(v3281 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
      v3301[v3401] = v3298;
      int * v3303 = v3237->cache_tags;
      int v3404 = (int)((unsigned int)((int)((unsigned int)(v3241 + 4) >> 2)) >> 1);
      v3303[v3380] = v3404;
      int * v3305 = v3237->cache_dirty;
      v3305[v3380] = 0;
      int * v3307 = v3237->cache_age;
      v3307[v3380] = 1;
      int * v3309 = v3237->cache_age;
      int v3310 = v3309[v3380];
      int v3311 = v3309[v3354];
      int v3410 = v3311 + ((int)((unsigned int)(v3311 - v3310) >> 31));
      v3309[v3354] = v3410;
      int * v3313 = v3237->cache_age;
      int v3314 = v3313[v3355];
      int v3412 = v3314 + ((int)((unsigned int)(v3314 - v3310) >> 31));
      v3313[v3355] = v3412;
      int * v3316 = v3237->cache_age;
      v3316[v3380] = 0;
      v3319 = v3380;
    }
    int * v3320 = v3237->cache_vals;
    int v3415 = v3319 * 2;
    int v3321 = v3320[v3415];
    int v3416 = (v3319 * 2) + 1;
    int v3322 = v3320[v3416];
    int v3417 = (((((int)((unsigned int)((int)((unsigned int)(v3241 + 4) >> 2)) >> 1)) & 1) * 2) + ((((v3261 + ((~(((v3263 ^ -1) | (-(v3263 ^ -1))) >> 31)) & 2)) - (v3264 + ((~(((v3265 ^ -1) | (-(v3265 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
    v3320[v3417] = v3321;
    int * v3324 = v3237->cache_vals;
    int v3420 = ((((((int)((unsigned int)((int)((unsigned int)(v3241 + 4) >> 2)) >> 1)) & 1) * 2) + ((((v3261 + ((~(((v3263 ^ -1) | (-(v3263 ^ -1))) >> 31)) & 2)) - (v3264 + ((~(((v3265 ^ -1) | (-(v3265 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
    v3324[v3420] = v3322;
    int * v3326 = v3237->cache_tags;
    int v3423 = ((((int)((unsigned int)((int)((unsigned int)(v3241 + 4) >> 2)) >> 1)) & 1) * 2) + ((((v3261 + ((~(((v3263 ^ -1) | (-(v3263 ^ -1))) >> 31)) & 2)) - (v3264 + ((~(((v3265 ^ -1) | (-(v3265 ^ -1))) >> 31)) & 2))) >> 31) & 1);
    int v3424 = (int)((unsigned int)((int)((unsigned int)(v3241 + 4) >> 2)) >> 1);
    v3326[v3423] = v3424;
    int * v3328 = v3237->cache_dirty;
    v3328[v3423] = 0;
    int * v3330 = v3237->cache_age;
    v3330[v3423] = 1;
    int * v3332 = v3237->cache_age;
    int v3333 = v3332[v3423];
    int v3334 = v3332[v3352];
    int v3430 = v3334 + ((int)((unsigned int)(v3334 - v3333) >> 31));
    v3332[v3352] = v3430;
    int * v3336 = v3237->cache_age;
    int v3337 = v3336[v3353];
    int v3432 = v3337 + ((int)((unsigned int)(v3337 - v3333) >> 31));
    v3336[v3353] = v3432;
    int * v3339 = v3237->cache_age;
    v3339[v3423] = 0;
    v3342 = v3423;
  }
  int v3435 = (v3342 * 2) + (((int)((unsigned int)(v3241 + 4) >> 2)) & 1);
  int v3343 = v3249[v3435];
  int * v3344 = v3237->regs;
  v3344[5] = v3343;
  struct StateT * v3346 = slot_43(v3237);
  return v3346;
}

struct StateT * slot_46(struct StateT * v3865) {
  int v3866 = v3865->timer;
  int v3874 = v3866 + 1;
  v3865->timer = v3874;
  int * v3868 = v3865->regs;
  int v3869 = v3868[7];
  int v3870 = v3868[17];
  int v3878 = v3869 ^ v3870;
  v3868[7] = v3878;
  struct StateT * v3872 = slot_47(v3865);
  return v3872;
}

struct StateT * slot_20(struct StateT * v1104) {
  int * v1105 = v1104->regs;
  int v1106 = v1105[12];
  bool v1141 = (v1106 ^ -2147483648) < -2147483648;
  struct StateT * v1137;
  if (v1141) {
    int v1107 = v1104->timer;
    int v1142 = v1107 + 15;
    v1104->timer = v1142;
    int * v1109 = v1104->saved_regs;
    int v1110 = v1109[15];
    int * v1111 = v1104->regs;
    v1111[15] = v1110;
    int * v1113 = v1104->saved_regs;
    int v1114 = v1113[16];
    int * v1115 = v1104->regs;
    v1115[16] = v1114;
    int * v1117 = v1104->saved_regs;
    int v1118 = v1117[17];
    int * v1119 = v1104->regs;
    v1119[17] = v1118;
    int * v1121 = v1104->saved_regs;
    int v1122 = v1121[5];
    int * v1123 = v1104->regs;
    v1123[5] = v1122;
    int * v1125 = v1104->saved_regs;
    int v1126 = v1125[6];
    int * v1127 = v1104->regs;
    v1127[6] = v1126;
    int * v1129 = v1104->saved_regs;
    int v1130 = v1129[7];
    int * v1131 = v1104->regs;
    v1131[7] = v1130;
    struct StateT * v1133 = slot_21(v1104);
    v1137 = v1133;
  } else {
    struct StateT * v1135 = slot_22(v1104);
    v1137 = v1135;
  }
  return v1137;
}

struct StateT * snippet(struct StateT * v0) {
  struct StateT * v1 = slot_0(v0);
  return v1;
}

struct StateT * slot_41(struct StateT * v3033) {
  int v3034 = v3033->timer;
  int v3144 = v3034 + 1;
  v3033->timer = v3144;
  int * v3036 = v3033->regs;
  int v3037 = v3036[16];
  int * v3038 = v3033->cache_tags;
  int v3148 = (((int)((unsigned int)((int)((unsigned int)v3037 >> 2)) >> 1)) & 1) * 2;
  int v3039 = v3038[v3148];
  int v3149 = ((((int)((unsigned int)((int)((unsigned int)v3037 >> 2)) >> 1)) & 1) * 2) + 1;
  int v3040 = v3038[v3149];
  int v3150 = 4 + ((((int)((unsigned int)((int)((unsigned int)v3037 >> 2)) >> 1)) & 3) * 2);
  int v3041 = v3038[v3150];
  int v3151 = (4 + ((((int)((unsigned int)((int)((unsigned int)v3037 >> 2)) >> 1)) & 3) * 2)) + 1;
  int v3042 = v3038[v3151];
  int v3043 = v3033->timer;
  int v3152 = v3043 + ((100 ^ (((~(((v3041 ^ ((int)((unsigned int)((int)((unsigned int)v3037 >> 2)) >> 1))) | (-(v3041 ^ ((int)((unsigned int)((int)((unsigned int)v3037 >> 2)) >> 1))))) >> 31)) | (~(((v3042 ^ ((int)((unsigned int)((int)((unsigned int)v3037 >> 2)) >> 1))) | (-(v3042 ^ ((int)((unsigned int)((int)((unsigned int)v3037 >> 2)) >> 1))))) >> 31))) & 104)) ^ (((~(((v3039 ^ ((int)((unsigned int)((int)((unsigned int)v3037 >> 2)) >> 1))) | (-(v3039 ^ ((int)((unsigned int)((int)((unsigned int)v3037 >> 2)) >> 1))))) >> 31)) | (~(((v3040 ^ ((int)((unsigned int)((int)((unsigned int)v3037 >> 2)) >> 1))) | (-(v3040 ^ ((int)((unsigned int)((int)((unsigned int)v3037 >> 2)) >> 1))))) >> 31))) & (1 ^ (100 ^ (((~(((v3041 ^ ((int)((unsigned int)((int)((unsigned int)v3037 >> 2)) >> 1))) | (-(v3041 ^ ((int)((unsigned int)((int)((unsigned int)v3037 >> 2)) >> 1))))) >> 31)) | (~(((v3042 ^ ((int)((unsigned int)((int)((unsigned int)v3037 >> 2)) >> 1))) | (-(v3042 ^ ((int)((unsigned int)((int)((unsigned int)v3037 >> 2)) >> 1))))) >> 31))) & 104)))));
  v3033->timer = v3152;
  int * v3045 = v3033->cache_vals;
  bool v3153 = !(((~(((v3039 ^ ((int)((unsigned int)((int)((unsigned int)v3037 >> 2)) >> 1))) | (-(v3039 ^ ((int)((unsigned int)((int)((unsigned int)v3037 >> 2)) >> 1))))) >> 31)) | (~(((v3040 ^ ((int)((unsigned int)((int)((unsigned int)v3037 >> 2)) >> 1))) | (-(v3040 ^ ((int)((unsigned int)((int)((unsigned int)v3037 >> 2)) >> 1))))) >> 31))) == 0);
  int v3138;
  if (v3153) {
    int * v3046 = v3033->cache_age;
    int v3155 = ((((int)((unsigned int)((int)((unsigned int)v3037 >> 2)) >> 1)) & 1) * 2) + ((~(((v3040 ^ ((int)((unsigned int)((int)((unsigned int)v3037 >> 2)) >> 1))) | (-(v3040 ^ ((int)((unsigned int)((int)((unsigned int)v3037 >> 2)) >> 1))))) >> 31)) & 1);
    int v3047 = v3046[v3155];
    int v3048 = v3046[v3148];
    int v3156 = v3048 + ((int)((unsigned int)(v3048 - v3047) >> 31));
    v3046[v3148] = v3156;
    int * v3050 = v3033->cache_age;
    int v3051 = v3050[v3149];
    int v3158 = v3051 + ((int)((unsigned int)(v3051 - v3047) >> 31));
    v3050[v3149] = v3158;
    int * v3053 = v3033->cache_age;
    v3053[v3155] = 0;
    v3138 = v3155;
  } else {
    int * v3056 = v3033->cache_age;
    int v3162 = (((int)((unsigned int)((int)((unsigned int)v3037 >> 2)) >> 1)) & 1) * 2;
    int v3057 = v3056[v3162];
    int * v3058 = v3033->cache_tags;
    int v3059 = v3058[v3162];
    int v3060 = v3056[v3149];
    int v3061 = v3058[v3149];
    bool v3164 = !(((~(((v3041 ^ ((int)((unsigned int)((int)((unsigned int)v3037 >> 2)) >> 1))) | (-(v3041 ^ ((int)((unsigned int)((int)((unsigned int)v3037 >> 2)) >> 1))))) >> 31)) | (~(((v3042 ^ ((int)((unsigned int)((int)((unsigned int)v3037 >> 2)) >> 1))) | (-(v3042 ^ ((int)((unsigned int)((int)((unsigned int)v3037 >> 2)) >> 1))))) >> 31))) == 0);
    int v3115;
    if (v3164) {
      int * v3062 = v3033->cache_age;
      int v3166 = (4 + ((((int)((unsigned int)((int)((unsigned int)v3037 >> 2)) >> 1)) & 3) * 2)) + ((~(((v3042 ^ ((int)((unsigned int)((int)((unsigned int)v3037 >> 2)) >> 1))) | (-(v3042 ^ ((int)((unsigned int)((int)((unsigned int)v3037 >> 2)) >> 1))))) >> 31)) & 1);
      int v3063 = v3062[v3166];
      int v3064 = v3062[v3150];
      int v3167 = v3064 + ((int)((unsigned int)(v3064 - v3063) >> 31));
      v3062[v3150] = v3167;
      int * v3066 = v3033->cache_age;
      int v3067 = v3066[v3151];
      int v3169 = v3067 + ((int)((unsigned int)(v3067 - v3063) >> 31));
      v3066[v3151] = v3169;
      int * v3069 = v3033->cache_age;
      v3069[v3166] = 0;
      v3115 = v3166;
    } else {
      int * v3072 = v3033->cache_age;
      int v3173 = 4 + ((((int)((unsigned int)((int)((unsigned int)v3037 >> 2)) >> 1)) & 3) * 2);
      int v3073 = v3072[v3173];
      int * v3074 = v3033->cache_tags;
      int v3075 = v3074[v3173];
      int v3076 = v3072[v3151];
      int v3077 = v3074[v3151];
      int * v3078 = v3033->cache_dirty;
      int v3176 = (4 + ((((int)((unsigned int)((int)((unsigned int)v3037 >> 2)) >> 1)) & 3) * 2)) + ((((v3073 + ((~(((v3075 ^ -1) | (-(v3075 ^ -1))) >> 31)) & 2)) - (v3076 + ((~(((v3077 ^ -1) | (-(v3077 ^ -1))) >> 31)) & 2))) >> 31) & 1);
      int v3079 = v3078[v3176];
      bool v3177 = !(v3079 == 0);
      if (v3177) {
        int * v3080 = v3033->cache_tags;
        int v3081 = v3080[v3176];
        int * v3082 = v3033->cache_vals;
        int v3180 = ((4 + ((((int)((unsigned int)((int)((unsigned int)v3037 >> 2)) >> 1)) & 3) * 2)) + ((((v3073 + ((~(((v3075 ^ -1) | (-(v3075 ^ -1))) >> 31)) & 2)) - (v3076 + ((~(((v3077 ^ -1) | (-(v3077 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
        int v3083 = v3082[v3180];
        int v3181 = (((4 + ((((int)((unsigned int)((int)((unsigned int)v3037 >> 2)) >> 1)) & 3) * 2)) + ((((v3073 + ((~(((v3075 ^ -1) | (-(v3075 ^ -1))) >> 31)) & 2)) - (v3076 + ((~(((v3077 ^ -1) | (-(v3077 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
        int v3084 = v3082[v3181];
        int * v3085 = v3033->mem;
        int v3183 = v3081 * 2;
        v3085[v3183] = v3083;
        int * v3087 = v3033->mem;
        int v3186 = (v3081 * 2) + 1;
        v3087[v3186] = v3084;
        ;
      } else {
        ;
      }
      int * v3092 = v3033->mem;
      int v3191 = ((int)((unsigned int)((int)((unsigned int)v3037 >> 2)) >> 1)) * 2;
      int v3093 = v3092[v3191];
      int v3192 = (((int)((unsigned int)((int)((unsigned int)v3037 >> 2)) >> 1)) * 2) + 1;
      int v3094 = v3092[v3192];
      int * v3095 = v3033->cache_vals;
      int v3194 = ((4 + ((((int)((unsigned int)((int)((unsigned int)v3037 >> 2)) >> 1)) & 3) * 2)) + ((((v3073 + ((~(((v3075 ^ -1) | (-(v3075 ^ -1))) >> 31)) & 2)) - (v3076 + ((~(((v3077 ^ -1) | (-(v3077 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
      v3095[v3194] = v3093;
      int * v3097 = v3033->cache_vals;
      int v3197 = (((4 + ((((int)((unsigned int)((int)((unsigned int)v3037 >> 2)) >> 1)) & 3) * 2)) + ((((v3073 + ((~(((v3075 ^ -1) | (-(v3075 ^ -1))) >> 31)) & 2)) - (v3076 + ((~(((v3077 ^ -1) | (-(v3077 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
      v3097[v3197] = v3094;
      int * v3099 = v3033->cache_tags;
      int v3200 = (int)((unsigned int)((int)((unsigned int)v3037 >> 2)) >> 1);
      v3099[v3176] = v3200;
      int * v3101 = v3033->cache_dirty;
      v3101[v3176] = 0;
      int * v3103 = v3033->cache_age;
      v3103[v3176] = 1;
      int * v3105 = v3033->cache_age;
      int v3106 = v3105[v3176];
      int v3107 = v3105[v3150];
      int v3206 = v3107 + ((int)((unsigned int)(v3107 - v3106) >> 31));
      v3105[v3150] = v3206;
      int * v3109 = v3033->cache_age;
      int v3110 = v3109[v3151];
      int v3208 = v3110 + ((int)((unsigned int)(v3110 - v3106) >> 31));
      v3109[v3151] = v3208;
      int * v3112 = v3033->cache_age;
      v3112[v3176] = 0;
      v3115 = v3176;
    }
    int * v3116 = v3033->cache_vals;
    int v3211 = v3115 * 2;
    int v3117 = v3116[v3211];
    int v3212 = (v3115 * 2) + 1;
    int v3118 = v3116[v3212];
    int v3213 = (((((int)((unsigned int)((int)((unsigned int)v3037 >> 2)) >> 1)) & 1) * 2) + ((((v3057 + ((~(((v3059 ^ -1) | (-(v3059 ^ -1))) >> 31)) & 2)) - (v3060 + ((~(((v3061 ^ -1) | (-(v3061 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
    v3116[v3213] = v3117;
    int * v3120 = v3033->cache_vals;
    int v3216 = ((((((int)((unsigned int)((int)((unsigned int)v3037 >> 2)) >> 1)) & 1) * 2) + ((((v3057 + ((~(((v3059 ^ -1) | (-(v3059 ^ -1))) >> 31)) & 2)) - (v3060 + ((~(((v3061 ^ -1) | (-(v3061 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
    v3120[v3216] = v3118;
    int * v3122 = v3033->cache_tags;
    int v3219 = ((((int)((unsigned int)((int)((unsigned int)v3037 >> 2)) >> 1)) & 1) * 2) + ((((v3057 + ((~(((v3059 ^ -1) | (-(v3059 ^ -1))) >> 31)) & 2)) - (v3060 + ((~(((v3061 ^ -1) | (-(v3061 ^ -1))) >> 31)) & 2))) >> 31) & 1);
    int v3220 = (int)((unsigned int)((int)((unsigned int)v3037 >> 2)) >> 1);
    v3122[v3219] = v3220;
    int * v3124 = v3033->cache_dirty;
    v3124[v3219] = 0;
    int * v3126 = v3033->cache_age;
    v3126[v3219] = 1;
    int * v3128 = v3033->cache_age;
    int v3129 = v3128[v3219];
    int v3130 = v3128[v3148];
    int v3226 = v3130 + ((int)((unsigned int)(v3130 - v3129) >> 31));
    v3128[v3148] = v3226;
    int * v3132 = v3033->cache_age;
    int v3133 = v3132[v3149];
    int v3228 = v3133 + ((int)((unsigned int)(v3133 - v3129) >> 31));
    v3132[v3149] = v3228;
    int * v3135 = v3033->cache_age;
    v3135[v3219] = 0;
    v3138 = v3219;
  }
  int v3231 = (v3138 * 2) + (((int)((unsigned int)v3037 >> 2)) & 1);
  int v3139 = v3045[v3231];
  int * v3140 = v3033->regs;
  v3140[17] = v3139;
  struct StateT * v3142 = slot_42(v3033);
  return v3142;
}

struct StateT * slot_39(struct StateT * v3000) {
  int v3001 = v3000->timer;
  int v3009 = v3001 + 1;
  v3000->timer = v3009;
  int * v3003 = v3000->regs;
  int v3004 = v3003[10];
  int v3005 = v3003[15];
  int v3014 = v3004 + v3005;
  v3003[16] = v3014;
  struct StateT * v3007 = slot_40(v3000);
  return v3007;
}

struct StateT * slot_8(struct StateT * v124) {
  int * v125 = v124->saved_regs;
  int * v126 = v124->regs;
  int v127 = v126[16];
  v125[16] = v127;
  int v129 = v124->timer;
  int v141 = v129 + 1;
  v124->timer = v141;
  int * v131 = v124->regs;
  int v132 = v131[10];
  int v133 = v131[15];
  int v145 = v132 + v133;
  v131[16] = v145;
  struct StateT * v135 = slot_9(v124);
  return v135;
}

struct StateT * slot_30(struct StateT * v2263) {
  int v2264 = v2263->timer;
  int v2272 = v2264 + 1;
  v2263->timer = v2272;
  int * v2266 = v2263->regs;
  int v2267 = v2266[13];
  int v2268 = v2266[5];
  int v2276 = v2267 & v2268;
  v2266[5] = v2276;
  struct StateT * v2270 = slot_31(v2263);
  return v2270;
}

struct StateT * slot_4(struct StateT * v58) {
  int v59 = v58->timer;
  int v70 = v59 + 1;
  v58->timer = v70;
  int * v61 = v58->regs;
  int v62 = v61[13];
  bool v73 = -2147483648 < (v62 ^ -2147483648);
  int v65;
  if (v73) {
    v65 = 1;
  } else {
    v65 = 0;
  }
  int * v66 = v58->regs;
  v66[13] = v65;
  struct StateT * v68 = slot_5(v58);
  return v68;
}

struct StateT * slot_18(struct StateT * v1072) {
  int v1073 = v1072->timer;
  int v1081 = v1073 + 1;
  v1072->timer = v1081;
  int * v1075 = v1072->regs;
  int v1076 = v1075[5];
  int v1077 = v1075[6];
  int v1085 = v1076 ^ v1077;
  v1075[6] = v1085;
  struct StateT * v1079 = slot_19(v1072);
  return v1079;
}

struct StateT * slot_9(struct StateT * v148) {
  int v149 = v148->timer;
  int v157 = v149 + 1;
  v148->timer = v157;
  int * v151 = v148->regs;
  int v152 = v151[11];
  int v153 = v151[15];
  int v161 = v152 + v153;
  v151[15] = v161;
  struct StateT * v155 = slot_10(v148);
  return v155;
}

struct StateT * slot_11(struct StateT * v375) {
  int * v376 = v375->saved_regs;
  int * v377 = v375->regs;
  int v378 = v377[5];
  v376[5] = v378;
  int v380 = v375->timer;
  int v494 = v380 + 1;
  v375->timer = v494;
  int * v382 = v375->regs;
  int v383 = v382[16];
  int * v384 = v375->cache_tags;
  int v498 = (((int)((unsigned int)((int)((unsigned int)(v383 + 4) >> 2)) >> 1)) & 1) * 2;
  int v385 = v384[v498];
  int v499 = ((((int)((unsigned int)((int)((unsigned int)(v383 + 4) >> 2)) >> 1)) & 1) * 2) + 1;
  int v386 = v384[v499];
  int v500 = 4 + ((((int)((unsigned int)((int)((unsigned int)(v383 + 4) >> 2)) >> 1)) & 3) * 2);
  int v387 = v384[v500];
  int v501 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v383 + 4) >> 2)) >> 1)) & 3) * 2)) + 1;
  int v388 = v384[v501];
  int v389 = v375->timer;
  int v502 = v389 + ((100 ^ (((~(((v387 ^ ((int)((unsigned int)((int)((unsigned int)(v383 + 4) >> 2)) >> 1))) | (-(v387 ^ ((int)((unsigned int)((int)((unsigned int)(v383 + 4) >> 2)) >> 1))))) >> 31)) | (~(((v388 ^ ((int)((unsigned int)((int)((unsigned int)(v383 + 4) >> 2)) >> 1))) | (-(v388 ^ ((int)((unsigned int)((int)((unsigned int)(v383 + 4) >> 2)) >> 1))))) >> 31))) & 104)) ^ (((~(((v385 ^ ((int)((unsigned int)((int)((unsigned int)(v383 + 4) >> 2)) >> 1))) | (-(v385 ^ ((int)((unsigned int)((int)((unsigned int)(v383 + 4) >> 2)) >> 1))))) >> 31)) | (~(((v386 ^ ((int)((unsigned int)((int)((unsigned int)(v383 + 4) >> 2)) >> 1))) | (-(v386 ^ ((int)((unsigned int)((int)((unsigned int)(v383 + 4) >> 2)) >> 1))))) >> 31))) & (1 ^ (100 ^ (((~(((v387 ^ ((int)((unsigned int)((int)((unsigned int)(v383 + 4) >> 2)) >> 1))) | (-(v387 ^ ((int)((unsigned int)((int)((unsigned int)(v383 + 4) >> 2)) >> 1))))) >> 31)) | (~(((v388 ^ ((int)((unsigned int)((int)((unsigned int)(v383 + 4) >> 2)) >> 1))) | (-(v388 ^ ((int)((unsigned int)((int)((unsigned int)(v383 + 4) >> 2)) >> 1))))) >> 31))) & 104)))));
  v375->timer = v502;
  int * v391 = v375->cache_vals;
  bool v503 = !(((~(((v385 ^ ((int)((unsigned int)((int)((unsigned int)(v383 + 4) >> 2)) >> 1))) | (-(v385 ^ ((int)((unsigned int)((int)((unsigned int)(v383 + 4) >> 2)) >> 1))))) >> 31)) | (~(((v386 ^ ((int)((unsigned int)((int)((unsigned int)(v383 + 4) >> 2)) >> 1))) | (-(v386 ^ ((int)((unsigned int)((int)((unsigned int)(v383 + 4) >> 2)) >> 1))))) >> 31))) == 0);
  int v484;
  if (v503) {
    int * v392 = v375->cache_age;
    int v505 = ((((int)((unsigned int)((int)((unsigned int)(v383 + 4) >> 2)) >> 1)) & 1) * 2) + ((~(((v386 ^ ((int)((unsigned int)((int)((unsigned int)(v383 + 4) >> 2)) >> 1))) | (-(v386 ^ ((int)((unsigned int)((int)((unsigned int)(v383 + 4) >> 2)) >> 1))))) >> 31)) & 1);
    int v393 = v392[v505];
    int v394 = v392[v498];
    int v506 = v394 + ((int)((unsigned int)(v394 - v393) >> 31));
    v392[v498] = v506;
    int * v396 = v375->cache_age;
    int v397 = v396[v499];
    int v508 = v397 + ((int)((unsigned int)(v397 - v393) >> 31));
    v396[v499] = v508;
    int * v399 = v375->cache_age;
    v399[v505] = 0;
    v484 = v505;
  } else {
    int * v402 = v375->cache_age;
    int v512 = (((int)((unsigned int)((int)((unsigned int)(v383 + 4) >> 2)) >> 1)) & 1) * 2;
    int v403 = v402[v512];
    int * v404 = v375->cache_tags;
    int v405 = v404[v512];
    int v406 = v402[v499];
    int v407 = v404[v499];
    bool v514 = !(((~(((v387 ^ ((int)((unsigned int)((int)((unsigned int)(v383 + 4) >> 2)) >> 1))) | (-(v387 ^ ((int)((unsigned int)((int)((unsigned int)(v383 + 4) >> 2)) >> 1))))) >> 31)) | (~(((v388 ^ ((int)((unsigned int)((int)((unsigned int)(v383 + 4) >> 2)) >> 1))) | (-(v388 ^ ((int)((unsigned int)((int)((unsigned int)(v383 + 4) >> 2)) >> 1))))) >> 31))) == 0);
    int v461;
    if (v514) {
      int * v408 = v375->cache_age;
      int v516 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v383 + 4) >> 2)) >> 1)) & 3) * 2)) + ((~(((v388 ^ ((int)((unsigned int)((int)((unsigned int)(v383 + 4) >> 2)) >> 1))) | (-(v388 ^ ((int)((unsigned int)((int)((unsigned int)(v383 + 4) >> 2)) >> 1))))) >> 31)) & 1);
      int v409 = v408[v516];
      int v410 = v408[v500];
      int v517 = v410 + ((int)((unsigned int)(v410 - v409) >> 31));
      v408[v500] = v517;
      int * v412 = v375->cache_age;
      int v413 = v412[v501];
      int v519 = v413 + ((int)((unsigned int)(v413 - v409) >> 31));
      v412[v501] = v519;
      int * v415 = v375->cache_age;
      v415[v516] = 0;
      v461 = v516;
    } else {
      int * v418 = v375->cache_age;
      int v523 = 4 + ((((int)((unsigned int)((int)((unsigned int)(v383 + 4) >> 2)) >> 1)) & 3) * 2);
      int v419 = v418[v523];
      int * v420 = v375->cache_tags;
      int v421 = v420[v523];
      int v422 = v418[v501];
      int v423 = v420[v501];
      int * v424 = v375->cache_dirty;
      int v526 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v383 + 4) >> 2)) >> 1)) & 3) * 2)) + ((((v419 + ((~(((v421 ^ -1) | (-(v421 ^ -1))) >> 31)) & 2)) - (v422 + ((~(((v423 ^ -1) | (-(v423 ^ -1))) >> 31)) & 2))) >> 31) & 1);
      int v425 = v424[v526];
      bool v527 = !(v425 == 0);
      if (v527) {
        int * v426 = v375->cache_tags;
        int v427 = v426[v526];
        int * v428 = v375->cache_vals;
        int v530 = ((4 + ((((int)((unsigned int)((int)((unsigned int)(v383 + 4) >> 2)) >> 1)) & 3) * 2)) + ((((v419 + ((~(((v421 ^ -1) | (-(v421 ^ -1))) >> 31)) & 2)) - (v422 + ((~(((v423 ^ -1) | (-(v423 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
        int v429 = v428[v530];
        int v531 = (((4 + ((((int)((unsigned int)((int)((unsigned int)(v383 + 4) >> 2)) >> 1)) & 3) * 2)) + ((((v419 + ((~(((v421 ^ -1) | (-(v421 ^ -1))) >> 31)) & 2)) - (v422 + ((~(((v423 ^ -1) | (-(v423 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
        int v430 = v428[v531];
        int * v431 = v375->mem;
        int v533 = v427 * 2;
        v431[v533] = v429;
        int * v433 = v375->mem;
        int v536 = (v427 * 2) + 1;
        v433[v536] = v430;
        ;
      } else {
        ;
      }
      int * v438 = v375->mem;
      int v541 = ((int)((unsigned int)((int)((unsigned int)(v383 + 4) >> 2)) >> 1)) * 2;
      int v439 = v438[v541];
      int v542 = (((int)((unsigned int)((int)((unsigned int)(v383 + 4) >> 2)) >> 1)) * 2) + 1;
      int v440 = v438[v542];
      int * v441 = v375->cache_vals;
      int v544 = ((4 + ((((int)((unsigned int)((int)((unsigned int)(v383 + 4) >> 2)) >> 1)) & 3) * 2)) + ((((v419 + ((~(((v421 ^ -1) | (-(v421 ^ -1))) >> 31)) & 2)) - (v422 + ((~(((v423 ^ -1) | (-(v423 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
      v441[v544] = v439;
      int * v443 = v375->cache_vals;
      int v547 = (((4 + ((((int)((unsigned int)((int)((unsigned int)(v383 + 4) >> 2)) >> 1)) & 3) * 2)) + ((((v419 + ((~(((v421 ^ -1) | (-(v421 ^ -1))) >> 31)) & 2)) - (v422 + ((~(((v423 ^ -1) | (-(v423 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
      v443[v547] = v440;
      int * v445 = v375->cache_tags;
      int v550 = (int)((unsigned int)((int)((unsigned int)(v383 + 4) >> 2)) >> 1);
      v445[v526] = v550;
      int * v447 = v375->cache_dirty;
      v447[v526] = 0;
      int * v449 = v375->cache_age;
      v449[v526] = 1;
      int * v451 = v375->cache_age;
      int v452 = v451[v526];
      int v453 = v451[v500];
      int v556 = v453 + ((int)((unsigned int)(v453 - v452) >> 31));
      v451[v500] = v556;
      int * v455 = v375->cache_age;
      int v456 = v455[v501];
      int v558 = v456 + ((int)((unsigned int)(v456 - v452) >> 31));
      v455[v501] = v558;
      int * v458 = v375->cache_age;
      v458[v526] = 0;
      v461 = v526;
    }
    int * v462 = v375->cache_vals;
    int v561 = v461 * 2;
    int v463 = v462[v561];
    int v562 = (v461 * 2) + 1;
    int v464 = v462[v562];
    int v563 = (((((int)((unsigned int)((int)((unsigned int)(v383 + 4) >> 2)) >> 1)) & 1) * 2) + ((((v403 + ((~(((v405 ^ -1) | (-(v405 ^ -1))) >> 31)) & 2)) - (v406 + ((~(((v407 ^ -1) | (-(v407 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
    v462[v563] = v463;
    int * v466 = v375->cache_vals;
    int v566 = ((((((int)((unsigned int)((int)((unsigned int)(v383 + 4) >> 2)) >> 1)) & 1) * 2) + ((((v403 + ((~(((v405 ^ -1) | (-(v405 ^ -1))) >> 31)) & 2)) - (v406 + ((~(((v407 ^ -1) | (-(v407 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
    v466[v566] = v464;
    int * v468 = v375->cache_tags;
    int v569 = ((((int)((unsigned int)((int)((unsigned int)(v383 + 4) >> 2)) >> 1)) & 1) * 2) + ((((v403 + ((~(((v405 ^ -1) | (-(v405 ^ -1))) >> 31)) & 2)) - (v406 + ((~(((v407 ^ -1) | (-(v407 ^ -1))) >> 31)) & 2))) >> 31) & 1);
    int v570 = (int)((unsigned int)((int)((unsigned int)(v383 + 4) >> 2)) >> 1);
    v468[v569] = v570;
    int * v470 = v375->cache_dirty;
    v470[v569] = 0;
    int * v472 = v375->cache_age;
    v472[v569] = 1;
    int * v474 = v375->cache_age;
    int v475 = v474[v569];
    int v476 = v474[v498];
    int v576 = v476 + ((int)((unsigned int)(v476 - v475) >> 31));
    v474[v498] = v576;
    int * v478 = v375->cache_age;
    int v479 = v478[v499];
    int v578 = v479 + ((int)((unsigned int)(v479 - v475) >> 31));
    v478[v499] = v578;
    int * v481 = v375->cache_age;
    v481[v569] = 0;
    v484 = v569;
  }
  int v581 = (v484 * 2) + (((int)((unsigned int)(v383 + 4) >> 2)) & 1);
  int v485 = v391[v581];
  int * v486 = v375->regs;
  v486[5] = v485;
  struct StateT * v488 = slot_12(v375);
  return v488;
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
  
  // a10, 10 words read by the callee: the address is public
  s1.regs[10] = 0;
  s2.regs[10] = 0;
  // a11, 10 words read by the callee: the address is public
  s1.regs[11] = 40;
  s2.regs[11] = 40;
  
  // a10's contents, secret: a different draw in each state
  for (int i=0; i<10; i++) {
    s1.mem[0 + i] = secret(0, 20);
    s2.mem[0 + i] = secret(0, 20);
  }
  // a11's contents, secret: a different draw in each state
  for (int i=0; i<10; i++) {
    s1.mem[10 + i] = secret(0, 20);
    s2.mem[10 + i] = secret(0, 20);
  }
  // a12 and a13, secret: a uint64's halves, drawn separately
  // in each state
  s1.regs[12] = secret(0, 1);
  s2.regs[12] = secret(0, 1);
  s1.regs[13] = secret(0, 1);
  s2.regs[13] = secret(0, 1);
  struct StateT *s1_ = snippet(&s1);
  struct StateT *s2_ = snippet(&s2);
  //@ assert untainted_timer: !\tainted(s1_->timer==s2_->timer);
  koika_assert(s1_->timer==s2_->timer, "timing leak");
  return 0;
}