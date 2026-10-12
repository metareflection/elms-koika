// verify: clean (CBMC should report VERIFICATION SUCCESSFUL) [unwind 65]
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

struct StateT * slot_12(struct StateT * v586);
struct StateT * slot_43(struct StateT * v3441);
struct StateT * slot_70(struct StateT * v6215);
struct StateT * slot_76(struct StateT * v6701);
struct StateT * slot_6(struct StateT * v94);
struct StateT * slot_47(struct StateT * v3881);
struct StateT * slot_29(struct StateT * v2247);
struct StateT * slot_55(struct StateT * v4983);
struct StateT * slot_16(struct StateT * v1040);
struct StateT * slot_5(struct StateT * v80);
struct StateT * slot_7(struct StateT * v102);
struct StateT * slot_31(struct StateT * v2279);
struct StateT * slot_54(struct StateT * v4779);
struct StateT * slot_26(struct StateT * v2011);
struct StateT * slot_65(struct StateT * v5731);
struct StateT * slot_10(struct StateT * v164);
struct StateT * slot_74(struct StateT * v6669);
struct StateT * slot_19(struct StateT * v1088);
struct StateT * slot_58(struct StateT * v5031);
struct StateT * slot_67(struct StateT * v5777);
struct StateT * slot_64(struct StateT * v5723);
struct StateT * slot_14(struct StateT * v1008);
struct StateT * slot_53(struct StateT * v4575);
struct StateT * slot_44(struct StateT * v3645);
struct StateT * slot_66(struct StateT * v5753);
struct StateT * slot_78(struct StateT * v6733);
struct StateT * slot_28(struct StateT * v2231);
struct StateT * slot_32(struct StateT * v2295);
struct StateT * slot_17(struct StateT * v1056);
struct StateT * slot_49(struct StateT * v3913);
struct StateT * slot_33(struct StateT * v2311);
struct StateT * slot_50(struct StateT * v3929);
struct StateT * slot_36(struct StateT * v2955);
struct StateT * slot_37(struct StateT * v2963);
struct StateT * slot_57(struct StateT * v5015);
struct StateT * slot_68(struct StateT * v5793);
struct StateT * slot_59(struct StateT * v5047);
struct StateT * slot_40(struct StateT * v3017);
struct StateT * slot_27(struct StateT * v2215);
struct StateT * slot_15(struct StateT * v1024);
struct StateT * slot_62(struct StateT * v5394);
struct StateT * slot_48(struct StateT * v3897);
struct StateT * slot_77(struct StateT * v6717);
struct StateT * slot_22(struct StateT * v1177);
struct StateT * slot_35(struct StateT * v2941);
struct StateT * slot_75(struct StateT * v6685);
struct StateT * slot_56(struct StateT * v4999);
struct StateT * slot_72(struct StateT * v6637);
struct StateT * slot_34(struct StateT * v2626);
struct StateT * slot_71(struct StateT * v6426);
struct StateT * slot_51(struct StateT * v3945);
struct StateT * slot_52(struct StateT * v4260);
struct StateT * slot_25(struct StateT * v1807);
struct StateT * slot_2(struct StateT * v29);
struct StateT * slot_21(struct StateT * v1172);
struct StateT * slot_3(struct StateT * v45);
struct StateT * slot_45(struct StateT * v3849);
struct StateT * slot_73(struct StateT * v6653);
struct StateT * slot_1(struct StateT * v15);
struct StateT * slot_69(struct StateT * v6004);
struct StateT * slot_13(struct StateT * v797);
struct StateT * slot_38(struct StateT * v2985);
struct StateT * slot_63(struct StateT * v5709);
struct StateT * slot_24(struct StateT * v1492);
struct StateT * slot_0(struct StateT * v2);
struct StateT * slot_42(struct StateT * v3237);
struct StateT * slot_46(struct StateT * v3865);
struct StateT * slot_20(struct StateT * v1104);
struct StateT * slot_61(struct StateT * v5079);
struct StateT * snippet(struct StateT * v0);
struct StateT * slot_41(struct StateT * v3033);
struct StateT * slot_39(struct StateT * v3000);
struct StateT * slot_8(struct StateT * v124);
struct StateT * slot_30(struct StateT * v2263);
struct StateT * slot_60(struct StateT * v5063);
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

struct StateT * slot_70(struct StateT * v6215) {
  int * v6216 = v6215->saved_regs;
  int * v6217 = v6215->regs;
  int v6218 = v6217[6];
  v6216[6] = v6218;
  int v6220 = v6215->timer;
  int v6334 = v6220 + 1;
  v6215->timer = v6334;
  int * v6222 = v6215->regs;
  int v6223 = v6222[15];
  int * v6224 = v6215->cache_tags;
  int v6338 = (((int)((unsigned int)((int)((unsigned int)(v6223 + 4) >> 2)) >> 1)) & 1) * 2;
  int v6225 = v6224[v6338];
  int v6339 = ((((int)((unsigned int)((int)((unsigned int)(v6223 + 4) >> 2)) >> 1)) & 1) * 2) + 1;
  int v6226 = v6224[v6339];
  int v6340 = 4 + ((((int)((unsigned int)((int)((unsigned int)(v6223 + 4) >> 2)) >> 1)) & 3) * 2);
  int v6227 = v6224[v6340];
  int v6341 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v6223 + 4) >> 2)) >> 1)) & 3) * 2)) + 1;
  int v6228 = v6224[v6341];
  int v6229 = v6215->timer;
  int v6342 = v6229 + ((100 ^ (((~(((v6227 ^ ((int)((unsigned int)((int)((unsigned int)(v6223 + 4) >> 2)) >> 1))) | (-(v6227 ^ ((int)((unsigned int)((int)((unsigned int)(v6223 + 4) >> 2)) >> 1))))) >> 31)) | (~(((v6228 ^ ((int)((unsigned int)((int)((unsigned int)(v6223 + 4) >> 2)) >> 1))) | (-(v6228 ^ ((int)((unsigned int)((int)((unsigned int)(v6223 + 4) >> 2)) >> 1))))) >> 31))) & 104)) ^ (((~(((v6225 ^ ((int)((unsigned int)((int)((unsigned int)(v6223 + 4) >> 2)) >> 1))) | (-(v6225 ^ ((int)((unsigned int)((int)((unsigned int)(v6223 + 4) >> 2)) >> 1))))) >> 31)) | (~(((v6226 ^ ((int)((unsigned int)((int)((unsigned int)(v6223 + 4) >> 2)) >> 1))) | (-(v6226 ^ ((int)((unsigned int)((int)((unsigned int)(v6223 + 4) >> 2)) >> 1))))) >> 31))) & (1 ^ (100 ^ (((~(((v6227 ^ ((int)((unsigned int)((int)((unsigned int)(v6223 + 4) >> 2)) >> 1))) | (-(v6227 ^ ((int)((unsigned int)((int)((unsigned int)(v6223 + 4) >> 2)) >> 1))))) >> 31)) | (~(((v6228 ^ ((int)((unsigned int)((int)((unsigned int)(v6223 + 4) >> 2)) >> 1))) | (-(v6228 ^ ((int)((unsigned int)((int)((unsigned int)(v6223 + 4) >> 2)) >> 1))))) >> 31))) & 104)))));
  v6215->timer = v6342;
  int * v6231 = v6215->cache_vals;
  bool v6343 = !(((~(((v6225 ^ ((int)((unsigned int)((int)((unsigned int)(v6223 + 4) >> 2)) >> 1))) | (-(v6225 ^ ((int)((unsigned int)((int)((unsigned int)(v6223 + 4) >> 2)) >> 1))))) >> 31)) | (~(((v6226 ^ ((int)((unsigned int)((int)((unsigned int)(v6223 + 4) >> 2)) >> 1))) | (-(v6226 ^ ((int)((unsigned int)((int)((unsigned int)(v6223 + 4) >> 2)) >> 1))))) >> 31))) == 0);
  int v6324;
  if (v6343) {
    int * v6232 = v6215->cache_age;
    int v6345 = ((((int)((unsigned int)((int)((unsigned int)(v6223 + 4) >> 2)) >> 1)) & 1) * 2) + ((~(((v6226 ^ ((int)((unsigned int)((int)((unsigned int)(v6223 + 4) >> 2)) >> 1))) | (-(v6226 ^ ((int)((unsigned int)((int)((unsigned int)(v6223 + 4) >> 2)) >> 1))))) >> 31)) & 1);
    int v6233 = v6232[v6345];
    int v6234 = v6232[v6338];
    int v6346 = v6234 + ((int)((unsigned int)(v6234 - v6233) >> 31));
    v6232[v6338] = v6346;
    int * v6236 = v6215->cache_age;
    int v6237 = v6236[v6339];
    int v6348 = v6237 + ((int)((unsigned int)(v6237 - v6233) >> 31));
    v6236[v6339] = v6348;
    int * v6239 = v6215->cache_age;
    v6239[v6345] = 0;
    v6324 = v6345;
  } else {
    int * v6242 = v6215->cache_age;
    int v6352 = (((int)((unsigned int)((int)((unsigned int)(v6223 + 4) >> 2)) >> 1)) & 1) * 2;
    int v6243 = v6242[v6352];
    int * v6244 = v6215->cache_tags;
    int v6245 = v6244[v6352];
    int v6246 = v6242[v6339];
    int v6247 = v6244[v6339];
    bool v6354 = !(((~(((v6227 ^ ((int)((unsigned int)((int)((unsigned int)(v6223 + 4) >> 2)) >> 1))) | (-(v6227 ^ ((int)((unsigned int)((int)((unsigned int)(v6223 + 4) >> 2)) >> 1))))) >> 31)) | (~(((v6228 ^ ((int)((unsigned int)((int)((unsigned int)(v6223 + 4) >> 2)) >> 1))) | (-(v6228 ^ ((int)((unsigned int)((int)((unsigned int)(v6223 + 4) >> 2)) >> 1))))) >> 31))) == 0);
    int v6301;
    if (v6354) {
      int * v6248 = v6215->cache_age;
      int v6356 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v6223 + 4) >> 2)) >> 1)) & 3) * 2)) + ((~(((v6228 ^ ((int)((unsigned int)((int)((unsigned int)(v6223 + 4) >> 2)) >> 1))) | (-(v6228 ^ ((int)((unsigned int)((int)((unsigned int)(v6223 + 4) >> 2)) >> 1))))) >> 31)) & 1);
      int v6249 = v6248[v6356];
      int v6250 = v6248[v6340];
      int v6357 = v6250 + ((int)((unsigned int)(v6250 - v6249) >> 31));
      v6248[v6340] = v6357;
      int * v6252 = v6215->cache_age;
      int v6253 = v6252[v6341];
      int v6359 = v6253 + ((int)((unsigned int)(v6253 - v6249) >> 31));
      v6252[v6341] = v6359;
      int * v6255 = v6215->cache_age;
      v6255[v6356] = 0;
      v6301 = v6356;
    } else {
      int * v6258 = v6215->cache_age;
      int v6363 = 4 + ((((int)((unsigned int)((int)((unsigned int)(v6223 + 4) >> 2)) >> 1)) & 3) * 2);
      int v6259 = v6258[v6363];
      int * v6260 = v6215->cache_tags;
      int v6261 = v6260[v6363];
      int v6262 = v6258[v6341];
      int v6263 = v6260[v6341];
      int * v6264 = v6215->cache_dirty;
      int v6366 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v6223 + 4) >> 2)) >> 1)) & 3) * 2)) + ((((v6259 + ((~(((v6261 ^ -1) | (-(v6261 ^ -1))) >> 31)) & 2)) - (v6262 + ((~(((v6263 ^ -1) | (-(v6263 ^ -1))) >> 31)) & 2))) >> 31) & 1);
      int v6265 = v6264[v6366];
      bool v6367 = !(v6265 == 0);
      if (v6367) {
        int * v6266 = v6215->cache_tags;
        int v6267 = v6266[v6366];
        int * v6268 = v6215->cache_vals;
        int v6370 = ((4 + ((((int)((unsigned int)((int)((unsigned int)(v6223 + 4) >> 2)) >> 1)) & 3) * 2)) + ((((v6259 + ((~(((v6261 ^ -1) | (-(v6261 ^ -1))) >> 31)) & 2)) - (v6262 + ((~(((v6263 ^ -1) | (-(v6263 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
        int v6269 = v6268[v6370];
        int v6371 = (((4 + ((((int)((unsigned int)((int)((unsigned int)(v6223 + 4) >> 2)) >> 1)) & 3) * 2)) + ((((v6259 + ((~(((v6261 ^ -1) | (-(v6261 ^ -1))) >> 31)) & 2)) - (v6262 + ((~(((v6263 ^ -1) | (-(v6263 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
        int v6270 = v6268[v6371];
        int * v6271 = v6215->mem;
        int v6373 = v6267 * 2;
        v6271[v6373] = v6269;
        int * v6273 = v6215->mem;
        int v6376 = (v6267 * 2) + 1;
        v6273[v6376] = v6270;
        ;
      } else {
        ;
      }
      int * v6278 = v6215->mem;
      int v6381 = ((int)((unsigned int)((int)((unsigned int)(v6223 + 4) >> 2)) >> 1)) * 2;
      int v6279 = v6278[v6381];
      int v6382 = (((int)((unsigned int)((int)((unsigned int)(v6223 + 4) >> 2)) >> 1)) * 2) + 1;
      int v6280 = v6278[v6382];
      int * v6281 = v6215->cache_vals;
      int v6384 = ((4 + ((((int)((unsigned int)((int)((unsigned int)(v6223 + 4) >> 2)) >> 1)) & 3) * 2)) + ((((v6259 + ((~(((v6261 ^ -1) | (-(v6261 ^ -1))) >> 31)) & 2)) - (v6262 + ((~(((v6263 ^ -1) | (-(v6263 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
      v6281[v6384] = v6279;
      int * v6283 = v6215->cache_vals;
      int v6387 = (((4 + ((((int)((unsigned int)((int)((unsigned int)(v6223 + 4) >> 2)) >> 1)) & 3) * 2)) + ((((v6259 + ((~(((v6261 ^ -1) | (-(v6261 ^ -1))) >> 31)) & 2)) - (v6262 + ((~(((v6263 ^ -1) | (-(v6263 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
      v6283[v6387] = v6280;
      int * v6285 = v6215->cache_tags;
      int v6390 = (int)((unsigned int)((int)((unsigned int)(v6223 + 4) >> 2)) >> 1);
      v6285[v6366] = v6390;
      int * v6287 = v6215->cache_dirty;
      v6287[v6366] = 0;
      int * v6289 = v6215->cache_age;
      v6289[v6366] = 1;
      int * v6291 = v6215->cache_age;
      int v6292 = v6291[v6366];
      int v6293 = v6291[v6340];
      int v6396 = v6293 + ((int)((unsigned int)(v6293 - v6292) >> 31));
      v6291[v6340] = v6396;
      int * v6295 = v6215->cache_age;
      int v6296 = v6295[v6341];
      int v6398 = v6296 + ((int)((unsigned int)(v6296 - v6292) >> 31));
      v6295[v6341] = v6398;
      int * v6298 = v6215->cache_age;
      v6298[v6366] = 0;
      v6301 = v6366;
    }
    int * v6302 = v6215->cache_vals;
    int v6401 = v6301 * 2;
    int v6303 = v6302[v6401];
    int v6402 = (v6301 * 2) + 1;
    int v6304 = v6302[v6402];
    int v6403 = (((((int)((unsigned int)((int)((unsigned int)(v6223 + 4) >> 2)) >> 1)) & 1) * 2) + ((((v6243 + ((~(((v6245 ^ -1) | (-(v6245 ^ -1))) >> 31)) & 2)) - (v6246 + ((~(((v6247 ^ -1) | (-(v6247 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
    v6302[v6403] = v6303;
    int * v6306 = v6215->cache_vals;
    int v6406 = ((((((int)((unsigned int)((int)((unsigned int)(v6223 + 4) >> 2)) >> 1)) & 1) * 2) + ((((v6243 + ((~(((v6245 ^ -1) | (-(v6245 ^ -1))) >> 31)) & 2)) - (v6246 + ((~(((v6247 ^ -1) | (-(v6247 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
    v6306[v6406] = v6304;
    int * v6308 = v6215->cache_tags;
    int v6409 = ((((int)((unsigned int)((int)((unsigned int)(v6223 + 4) >> 2)) >> 1)) & 1) * 2) + ((((v6243 + ((~(((v6245 ^ -1) | (-(v6245 ^ -1))) >> 31)) & 2)) - (v6246 + ((~(((v6247 ^ -1) | (-(v6247 ^ -1))) >> 31)) & 2))) >> 31) & 1);
    int v6410 = (int)((unsigned int)((int)((unsigned int)(v6223 + 4) >> 2)) >> 1);
    v6308[v6409] = v6410;
    int * v6310 = v6215->cache_dirty;
    v6310[v6409] = 0;
    int * v6312 = v6215->cache_age;
    v6312[v6409] = 1;
    int * v6314 = v6215->cache_age;
    int v6315 = v6314[v6409];
    int v6316 = v6314[v6338];
    int v6416 = v6316 + ((int)((unsigned int)(v6316 - v6315) >> 31));
    v6314[v6338] = v6416;
    int * v6318 = v6215->cache_age;
    int v6319 = v6318[v6339];
    int v6418 = v6319 + ((int)((unsigned int)(v6319 - v6315) >> 31));
    v6318[v6339] = v6418;
    int * v6321 = v6215->cache_age;
    v6321[v6409] = 0;
    v6324 = v6409;
  }
  int v6421 = (v6324 * 2) + (((int)((unsigned int)(v6223 + 4) >> 2)) & 1);
  int v6325 = v6231[v6421];
  int * v6326 = v6215->regs;
  v6326[6] = v6325;
  struct StateT * v6328 = slot_71(v6215);
  return v6328;
}

struct StateT * slot_76(struct StateT * v6701) {
  int v6702 = v6701->timer;
  int v6710 = v6702 + 1;
  v6701->timer = v6710;
  int * v6704 = v6701->regs;
  int v6705 = v6704[5];
  int v6706 = v6704[6];
  int v6714 = v6705 ^ v6706;
  v6704[6] = v6714;
  struct StateT * v6708 = slot_77(v6701);
  return v6708;
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

struct StateT * slot_55(struct StateT * v4983) {
  int v4984 = v4983->timer;
  int v4992 = v4984 + 1;
  v4983->timer = v4992;
  int * v4986 = v4983->regs;
  int v4987 = v4986[5];
  int v4988 = v4986[16];
  int v4996 = v4987 ^ v4988;
  v4986[5] = v4996;
  struct StateT * v4990 = slot_56(v4983);
  return v4990;
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

struct StateT * slot_54(struct StateT * v4779) {
  int v4780 = v4779->timer;
  int v4890 = v4780 + 1;
  v4779->timer = v4890;
  int * v4782 = v4779->regs;
  int v4783 = v4782[15];
  int * v4784 = v4779->cache_tags;
  int v4894 = (((int)((unsigned int)((int)((unsigned int)v4783 >> 2)) >> 1)) & 1) * 2;
  int v4785 = v4784[v4894];
  int v4895 = ((((int)((unsigned int)((int)((unsigned int)v4783 >> 2)) >> 1)) & 1) * 2) + 1;
  int v4786 = v4784[v4895];
  int v4896 = 4 + ((((int)((unsigned int)((int)((unsigned int)v4783 >> 2)) >> 1)) & 3) * 2);
  int v4787 = v4784[v4896];
  int v4897 = (4 + ((((int)((unsigned int)((int)((unsigned int)v4783 >> 2)) >> 1)) & 3) * 2)) + 1;
  int v4788 = v4784[v4897];
  int v4789 = v4779->timer;
  int v4898 = v4789 + ((100 ^ (((~(((v4787 ^ ((int)((unsigned int)((int)((unsigned int)v4783 >> 2)) >> 1))) | (-(v4787 ^ ((int)((unsigned int)((int)((unsigned int)v4783 >> 2)) >> 1))))) >> 31)) | (~(((v4788 ^ ((int)((unsigned int)((int)((unsigned int)v4783 >> 2)) >> 1))) | (-(v4788 ^ ((int)((unsigned int)((int)((unsigned int)v4783 >> 2)) >> 1))))) >> 31))) & 104)) ^ (((~(((v4785 ^ ((int)((unsigned int)((int)((unsigned int)v4783 >> 2)) >> 1))) | (-(v4785 ^ ((int)((unsigned int)((int)((unsigned int)v4783 >> 2)) >> 1))))) >> 31)) | (~(((v4786 ^ ((int)((unsigned int)((int)((unsigned int)v4783 >> 2)) >> 1))) | (-(v4786 ^ ((int)((unsigned int)((int)((unsigned int)v4783 >> 2)) >> 1))))) >> 31))) & (1 ^ (100 ^ (((~(((v4787 ^ ((int)((unsigned int)((int)((unsigned int)v4783 >> 2)) >> 1))) | (-(v4787 ^ ((int)((unsigned int)((int)((unsigned int)v4783 >> 2)) >> 1))))) >> 31)) | (~(((v4788 ^ ((int)((unsigned int)((int)((unsigned int)v4783 >> 2)) >> 1))) | (-(v4788 ^ ((int)((unsigned int)((int)((unsigned int)v4783 >> 2)) >> 1))))) >> 31))) & 104)))));
  v4779->timer = v4898;
  int * v4791 = v4779->cache_vals;
  bool v4899 = !(((~(((v4785 ^ ((int)((unsigned int)((int)((unsigned int)v4783 >> 2)) >> 1))) | (-(v4785 ^ ((int)((unsigned int)((int)((unsigned int)v4783 >> 2)) >> 1))))) >> 31)) | (~(((v4786 ^ ((int)((unsigned int)((int)((unsigned int)v4783 >> 2)) >> 1))) | (-(v4786 ^ ((int)((unsigned int)((int)((unsigned int)v4783 >> 2)) >> 1))))) >> 31))) == 0);
  int v4884;
  if (v4899) {
    int * v4792 = v4779->cache_age;
    int v4901 = ((((int)((unsigned int)((int)((unsigned int)v4783 >> 2)) >> 1)) & 1) * 2) + ((~(((v4786 ^ ((int)((unsigned int)((int)((unsigned int)v4783 >> 2)) >> 1))) | (-(v4786 ^ ((int)((unsigned int)((int)((unsigned int)v4783 >> 2)) >> 1))))) >> 31)) & 1);
    int v4793 = v4792[v4901];
    int v4794 = v4792[v4894];
    int v4902 = v4794 + ((int)((unsigned int)(v4794 - v4793) >> 31));
    v4792[v4894] = v4902;
    int * v4796 = v4779->cache_age;
    int v4797 = v4796[v4895];
    int v4904 = v4797 + ((int)((unsigned int)(v4797 - v4793) >> 31));
    v4796[v4895] = v4904;
    int * v4799 = v4779->cache_age;
    v4799[v4901] = 0;
    v4884 = v4901;
  } else {
    int * v4802 = v4779->cache_age;
    int v4908 = (((int)((unsigned int)((int)((unsigned int)v4783 >> 2)) >> 1)) & 1) * 2;
    int v4803 = v4802[v4908];
    int * v4804 = v4779->cache_tags;
    int v4805 = v4804[v4908];
    int v4806 = v4802[v4895];
    int v4807 = v4804[v4895];
    bool v4910 = !(((~(((v4787 ^ ((int)((unsigned int)((int)((unsigned int)v4783 >> 2)) >> 1))) | (-(v4787 ^ ((int)((unsigned int)((int)((unsigned int)v4783 >> 2)) >> 1))))) >> 31)) | (~(((v4788 ^ ((int)((unsigned int)((int)((unsigned int)v4783 >> 2)) >> 1))) | (-(v4788 ^ ((int)((unsigned int)((int)((unsigned int)v4783 >> 2)) >> 1))))) >> 31))) == 0);
    int v4861;
    if (v4910) {
      int * v4808 = v4779->cache_age;
      int v4912 = (4 + ((((int)((unsigned int)((int)((unsigned int)v4783 >> 2)) >> 1)) & 3) * 2)) + ((~(((v4788 ^ ((int)((unsigned int)((int)((unsigned int)v4783 >> 2)) >> 1))) | (-(v4788 ^ ((int)((unsigned int)((int)((unsigned int)v4783 >> 2)) >> 1))))) >> 31)) & 1);
      int v4809 = v4808[v4912];
      int v4810 = v4808[v4896];
      int v4913 = v4810 + ((int)((unsigned int)(v4810 - v4809) >> 31));
      v4808[v4896] = v4913;
      int * v4812 = v4779->cache_age;
      int v4813 = v4812[v4897];
      int v4915 = v4813 + ((int)((unsigned int)(v4813 - v4809) >> 31));
      v4812[v4897] = v4915;
      int * v4815 = v4779->cache_age;
      v4815[v4912] = 0;
      v4861 = v4912;
    } else {
      int * v4818 = v4779->cache_age;
      int v4919 = 4 + ((((int)((unsigned int)((int)((unsigned int)v4783 >> 2)) >> 1)) & 3) * 2);
      int v4819 = v4818[v4919];
      int * v4820 = v4779->cache_tags;
      int v4821 = v4820[v4919];
      int v4822 = v4818[v4897];
      int v4823 = v4820[v4897];
      int * v4824 = v4779->cache_dirty;
      int v4922 = (4 + ((((int)((unsigned int)((int)((unsigned int)v4783 >> 2)) >> 1)) & 3) * 2)) + ((((v4819 + ((~(((v4821 ^ -1) | (-(v4821 ^ -1))) >> 31)) & 2)) - (v4822 + ((~(((v4823 ^ -1) | (-(v4823 ^ -1))) >> 31)) & 2))) >> 31) & 1);
      int v4825 = v4824[v4922];
      bool v4923 = !(v4825 == 0);
      if (v4923) {
        int * v4826 = v4779->cache_tags;
        int v4827 = v4826[v4922];
        int * v4828 = v4779->cache_vals;
        int v4926 = ((4 + ((((int)((unsigned int)((int)((unsigned int)v4783 >> 2)) >> 1)) & 3) * 2)) + ((((v4819 + ((~(((v4821 ^ -1) | (-(v4821 ^ -1))) >> 31)) & 2)) - (v4822 + ((~(((v4823 ^ -1) | (-(v4823 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
        int v4829 = v4828[v4926];
        int v4927 = (((4 + ((((int)((unsigned int)((int)((unsigned int)v4783 >> 2)) >> 1)) & 3) * 2)) + ((((v4819 + ((~(((v4821 ^ -1) | (-(v4821 ^ -1))) >> 31)) & 2)) - (v4822 + ((~(((v4823 ^ -1) | (-(v4823 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
        int v4830 = v4828[v4927];
        int * v4831 = v4779->mem;
        int v4929 = v4827 * 2;
        v4831[v4929] = v4829;
        int * v4833 = v4779->mem;
        int v4932 = (v4827 * 2) + 1;
        v4833[v4932] = v4830;
        ;
      } else {
        ;
      }
      int * v4838 = v4779->mem;
      int v4937 = ((int)((unsigned int)((int)((unsigned int)v4783 >> 2)) >> 1)) * 2;
      int v4839 = v4838[v4937];
      int v4938 = (((int)((unsigned int)((int)((unsigned int)v4783 >> 2)) >> 1)) * 2) + 1;
      int v4840 = v4838[v4938];
      int * v4841 = v4779->cache_vals;
      int v4940 = ((4 + ((((int)((unsigned int)((int)((unsigned int)v4783 >> 2)) >> 1)) & 3) * 2)) + ((((v4819 + ((~(((v4821 ^ -1) | (-(v4821 ^ -1))) >> 31)) & 2)) - (v4822 + ((~(((v4823 ^ -1) | (-(v4823 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
      v4841[v4940] = v4839;
      int * v4843 = v4779->cache_vals;
      int v4943 = (((4 + ((((int)((unsigned int)((int)((unsigned int)v4783 >> 2)) >> 1)) & 3) * 2)) + ((((v4819 + ((~(((v4821 ^ -1) | (-(v4821 ^ -1))) >> 31)) & 2)) - (v4822 + ((~(((v4823 ^ -1) | (-(v4823 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
      v4843[v4943] = v4840;
      int * v4845 = v4779->cache_tags;
      int v4946 = (int)((unsigned int)((int)((unsigned int)v4783 >> 2)) >> 1);
      v4845[v4922] = v4946;
      int * v4847 = v4779->cache_dirty;
      v4847[v4922] = 0;
      int * v4849 = v4779->cache_age;
      v4849[v4922] = 1;
      int * v4851 = v4779->cache_age;
      int v4852 = v4851[v4922];
      int v4853 = v4851[v4896];
      int v4952 = v4853 + ((int)((unsigned int)(v4853 - v4852) >> 31));
      v4851[v4896] = v4952;
      int * v4855 = v4779->cache_age;
      int v4856 = v4855[v4897];
      int v4954 = v4856 + ((int)((unsigned int)(v4856 - v4852) >> 31));
      v4855[v4897] = v4954;
      int * v4858 = v4779->cache_age;
      v4858[v4922] = 0;
      v4861 = v4922;
    }
    int * v4862 = v4779->cache_vals;
    int v4957 = v4861 * 2;
    int v4863 = v4862[v4957];
    int v4958 = (v4861 * 2) + 1;
    int v4864 = v4862[v4958];
    int v4959 = (((((int)((unsigned int)((int)((unsigned int)v4783 >> 2)) >> 1)) & 1) * 2) + ((((v4803 + ((~(((v4805 ^ -1) | (-(v4805 ^ -1))) >> 31)) & 2)) - (v4806 + ((~(((v4807 ^ -1) | (-(v4807 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
    v4862[v4959] = v4863;
    int * v4866 = v4779->cache_vals;
    int v4962 = ((((((int)((unsigned int)((int)((unsigned int)v4783 >> 2)) >> 1)) & 1) * 2) + ((((v4803 + ((~(((v4805 ^ -1) | (-(v4805 ^ -1))) >> 31)) & 2)) - (v4806 + ((~(((v4807 ^ -1) | (-(v4807 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
    v4866[v4962] = v4864;
    int * v4868 = v4779->cache_tags;
    int v4965 = ((((int)((unsigned int)((int)((unsigned int)v4783 >> 2)) >> 1)) & 1) * 2) + ((((v4803 + ((~(((v4805 ^ -1) | (-(v4805 ^ -1))) >> 31)) & 2)) - (v4806 + ((~(((v4807 ^ -1) | (-(v4807 ^ -1))) >> 31)) & 2))) >> 31) & 1);
    int v4966 = (int)((unsigned int)((int)((unsigned int)v4783 >> 2)) >> 1);
    v4868[v4965] = v4966;
    int * v4870 = v4779->cache_dirty;
    v4870[v4965] = 0;
    int * v4872 = v4779->cache_age;
    v4872[v4965] = 1;
    int * v4874 = v4779->cache_age;
    int v4875 = v4874[v4965];
    int v4876 = v4874[v4894];
    int v4972 = v4876 + ((int)((unsigned int)(v4876 - v4875) >> 31));
    v4874[v4894] = v4972;
    int * v4878 = v4779->cache_age;
    int v4879 = v4878[v4895];
    int v4974 = v4879 + ((int)((unsigned int)(v4879 - v4875) >> 31));
    v4878[v4895] = v4974;
    int * v4881 = v4779->cache_age;
    v4881[v4965] = 0;
    v4884 = v4965;
  }
  int v4977 = (v4884 * 2) + (((int)((unsigned int)v4783 >> 2)) & 1);
  int v4885 = v4791[v4977];
  int * v4886 = v4779->regs;
  v4886[6] = v4885;
  struct StateT * v4888 = slot_55(v4779);
  return v4888;
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

struct StateT * slot_65(struct StateT * v5731) {
  int * v5732 = v5731->saved_regs;
  int * v5733 = v5731->regs;
  int v5734 = v5733[15];
  v5732[15] = v5734;
  int v5736 = v5731->timer;
  int v5747 = v5736 + 1;
  v5731->timer = v5747;
  int * v5738 = v5731->regs;
  int v5739 = v5738[14];
  int v5750 = v5739 << 3;
  v5738[15] = v5750;
  struct StateT * v5741 = slot_66(v5731);
  return v5741;
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

struct StateT * slot_74(struct StateT * v6669) {
  int v6670 = v6669->timer;
  int v6678 = v6670 + 1;
  v6669->timer = v6678;
  int * v6672 = v6669->regs;
  int v6673 = v6672[13];
  int v6674 = v6672[7];
  int v6682 = v6673 & v6674;
  v6672[7] = v6682;
  struct StateT * v6676 = slot_75(v6669);
  return v6676;
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

struct StateT * slot_58(struct StateT * v5031) {
  int v5032 = v5031->timer;
  int v5040 = v5032 + 1;
  v5031->timer = v5040;
  int * v5034 = v5031->regs;
  int v5035 = v5034[13];
  int v5036 = v5034[5];
  int v5044 = v5035 & v5036;
  v5034[5] = v5044;
  struct StateT * v5038 = slot_59(v5031);
  return v5038;
}

struct StateT * slot_67(struct StateT * v5777) {
  int v5778 = v5777->timer;
  int v5786 = v5778 + 1;
  v5777->timer = v5786;
  int * v5780 = v5777->regs;
  int v5781 = v5780[11];
  int v5782 = v5780[15];
  int v5790 = v5781 + v5782;
  v5780[15] = v5790;
  struct StateT * v5784 = slot_68(v5777);
  return v5784;
}

struct StateT * slot_64(struct StateT * v5723) {
  int v5724 = v5723->timer;
  int v5728 = v5724 + 1;
  v5723->timer = v5728;
  struct StateT * v5726 = slot_65(v5723);
  return v5726;
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

struct StateT * slot_53(struct StateT * v4575) {
  int v4576 = v4575->timer;
  int v4686 = v4576 + 1;
  v4575->timer = v4686;
  int * v4578 = v4575->regs;
  int v4579 = v4578[15];
  int * v4580 = v4575->cache_tags;
  int v4690 = (((int)((unsigned int)((int)((unsigned int)(v4579 + 4) >> 2)) >> 1)) & 1) * 2;
  int v4581 = v4580[v4690];
  int v4691 = ((((int)((unsigned int)((int)((unsigned int)(v4579 + 4) >> 2)) >> 1)) & 1) * 2) + 1;
  int v4582 = v4580[v4691];
  int v4692 = 4 + ((((int)((unsigned int)((int)((unsigned int)(v4579 + 4) >> 2)) >> 1)) & 3) * 2);
  int v4583 = v4580[v4692];
  int v4693 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v4579 + 4) >> 2)) >> 1)) & 3) * 2)) + 1;
  int v4584 = v4580[v4693];
  int v4585 = v4575->timer;
  int v4694 = v4585 + ((100 ^ (((~(((v4583 ^ ((int)((unsigned int)((int)((unsigned int)(v4579 + 4) >> 2)) >> 1))) | (-(v4583 ^ ((int)((unsigned int)((int)((unsigned int)(v4579 + 4) >> 2)) >> 1))))) >> 31)) | (~(((v4584 ^ ((int)((unsigned int)((int)((unsigned int)(v4579 + 4) >> 2)) >> 1))) | (-(v4584 ^ ((int)((unsigned int)((int)((unsigned int)(v4579 + 4) >> 2)) >> 1))))) >> 31))) & 104)) ^ (((~(((v4581 ^ ((int)((unsigned int)((int)((unsigned int)(v4579 + 4) >> 2)) >> 1))) | (-(v4581 ^ ((int)((unsigned int)((int)((unsigned int)(v4579 + 4) >> 2)) >> 1))))) >> 31)) | (~(((v4582 ^ ((int)((unsigned int)((int)((unsigned int)(v4579 + 4) >> 2)) >> 1))) | (-(v4582 ^ ((int)((unsigned int)((int)((unsigned int)(v4579 + 4) >> 2)) >> 1))))) >> 31))) & (1 ^ (100 ^ (((~(((v4583 ^ ((int)((unsigned int)((int)((unsigned int)(v4579 + 4) >> 2)) >> 1))) | (-(v4583 ^ ((int)((unsigned int)((int)((unsigned int)(v4579 + 4) >> 2)) >> 1))))) >> 31)) | (~(((v4584 ^ ((int)((unsigned int)((int)((unsigned int)(v4579 + 4) >> 2)) >> 1))) | (-(v4584 ^ ((int)((unsigned int)((int)((unsigned int)(v4579 + 4) >> 2)) >> 1))))) >> 31))) & 104)))));
  v4575->timer = v4694;
  int * v4587 = v4575->cache_vals;
  bool v4695 = !(((~(((v4581 ^ ((int)((unsigned int)((int)((unsigned int)(v4579 + 4) >> 2)) >> 1))) | (-(v4581 ^ ((int)((unsigned int)((int)((unsigned int)(v4579 + 4) >> 2)) >> 1))))) >> 31)) | (~(((v4582 ^ ((int)((unsigned int)((int)((unsigned int)(v4579 + 4) >> 2)) >> 1))) | (-(v4582 ^ ((int)((unsigned int)((int)((unsigned int)(v4579 + 4) >> 2)) >> 1))))) >> 31))) == 0);
  int v4680;
  if (v4695) {
    int * v4588 = v4575->cache_age;
    int v4697 = ((((int)((unsigned int)((int)((unsigned int)(v4579 + 4) >> 2)) >> 1)) & 1) * 2) + ((~(((v4582 ^ ((int)((unsigned int)((int)((unsigned int)(v4579 + 4) >> 2)) >> 1))) | (-(v4582 ^ ((int)((unsigned int)((int)((unsigned int)(v4579 + 4) >> 2)) >> 1))))) >> 31)) & 1);
    int v4589 = v4588[v4697];
    int v4590 = v4588[v4690];
    int v4698 = v4590 + ((int)((unsigned int)(v4590 - v4589) >> 31));
    v4588[v4690] = v4698;
    int * v4592 = v4575->cache_age;
    int v4593 = v4592[v4691];
    int v4700 = v4593 + ((int)((unsigned int)(v4593 - v4589) >> 31));
    v4592[v4691] = v4700;
    int * v4595 = v4575->cache_age;
    v4595[v4697] = 0;
    v4680 = v4697;
  } else {
    int * v4598 = v4575->cache_age;
    int v4704 = (((int)((unsigned int)((int)((unsigned int)(v4579 + 4) >> 2)) >> 1)) & 1) * 2;
    int v4599 = v4598[v4704];
    int * v4600 = v4575->cache_tags;
    int v4601 = v4600[v4704];
    int v4602 = v4598[v4691];
    int v4603 = v4600[v4691];
    bool v4706 = !(((~(((v4583 ^ ((int)((unsigned int)((int)((unsigned int)(v4579 + 4) >> 2)) >> 1))) | (-(v4583 ^ ((int)((unsigned int)((int)((unsigned int)(v4579 + 4) >> 2)) >> 1))))) >> 31)) | (~(((v4584 ^ ((int)((unsigned int)((int)((unsigned int)(v4579 + 4) >> 2)) >> 1))) | (-(v4584 ^ ((int)((unsigned int)((int)((unsigned int)(v4579 + 4) >> 2)) >> 1))))) >> 31))) == 0);
    int v4657;
    if (v4706) {
      int * v4604 = v4575->cache_age;
      int v4708 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v4579 + 4) >> 2)) >> 1)) & 3) * 2)) + ((~(((v4584 ^ ((int)((unsigned int)((int)((unsigned int)(v4579 + 4) >> 2)) >> 1))) | (-(v4584 ^ ((int)((unsigned int)((int)((unsigned int)(v4579 + 4) >> 2)) >> 1))))) >> 31)) & 1);
      int v4605 = v4604[v4708];
      int v4606 = v4604[v4692];
      int v4709 = v4606 + ((int)((unsigned int)(v4606 - v4605) >> 31));
      v4604[v4692] = v4709;
      int * v4608 = v4575->cache_age;
      int v4609 = v4608[v4693];
      int v4711 = v4609 + ((int)((unsigned int)(v4609 - v4605) >> 31));
      v4608[v4693] = v4711;
      int * v4611 = v4575->cache_age;
      v4611[v4708] = 0;
      v4657 = v4708;
    } else {
      int * v4614 = v4575->cache_age;
      int v4715 = 4 + ((((int)((unsigned int)((int)((unsigned int)(v4579 + 4) >> 2)) >> 1)) & 3) * 2);
      int v4615 = v4614[v4715];
      int * v4616 = v4575->cache_tags;
      int v4617 = v4616[v4715];
      int v4618 = v4614[v4693];
      int v4619 = v4616[v4693];
      int * v4620 = v4575->cache_dirty;
      int v4718 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v4579 + 4) >> 2)) >> 1)) & 3) * 2)) + ((((v4615 + ((~(((v4617 ^ -1) | (-(v4617 ^ -1))) >> 31)) & 2)) - (v4618 + ((~(((v4619 ^ -1) | (-(v4619 ^ -1))) >> 31)) & 2))) >> 31) & 1);
      int v4621 = v4620[v4718];
      bool v4719 = !(v4621 == 0);
      if (v4719) {
        int * v4622 = v4575->cache_tags;
        int v4623 = v4622[v4718];
        int * v4624 = v4575->cache_vals;
        int v4722 = ((4 + ((((int)((unsigned int)((int)((unsigned int)(v4579 + 4) >> 2)) >> 1)) & 3) * 2)) + ((((v4615 + ((~(((v4617 ^ -1) | (-(v4617 ^ -1))) >> 31)) & 2)) - (v4618 + ((~(((v4619 ^ -1) | (-(v4619 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
        int v4625 = v4624[v4722];
        int v4723 = (((4 + ((((int)((unsigned int)((int)((unsigned int)(v4579 + 4) >> 2)) >> 1)) & 3) * 2)) + ((((v4615 + ((~(((v4617 ^ -1) | (-(v4617 ^ -1))) >> 31)) & 2)) - (v4618 + ((~(((v4619 ^ -1) | (-(v4619 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
        int v4626 = v4624[v4723];
        int * v4627 = v4575->mem;
        int v4725 = v4623 * 2;
        v4627[v4725] = v4625;
        int * v4629 = v4575->mem;
        int v4728 = (v4623 * 2) + 1;
        v4629[v4728] = v4626;
        ;
      } else {
        ;
      }
      int * v4634 = v4575->mem;
      int v4733 = ((int)((unsigned int)((int)((unsigned int)(v4579 + 4) >> 2)) >> 1)) * 2;
      int v4635 = v4634[v4733];
      int v4734 = (((int)((unsigned int)((int)((unsigned int)(v4579 + 4) >> 2)) >> 1)) * 2) + 1;
      int v4636 = v4634[v4734];
      int * v4637 = v4575->cache_vals;
      int v4736 = ((4 + ((((int)((unsigned int)((int)((unsigned int)(v4579 + 4) >> 2)) >> 1)) & 3) * 2)) + ((((v4615 + ((~(((v4617 ^ -1) | (-(v4617 ^ -1))) >> 31)) & 2)) - (v4618 + ((~(((v4619 ^ -1) | (-(v4619 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
      v4637[v4736] = v4635;
      int * v4639 = v4575->cache_vals;
      int v4739 = (((4 + ((((int)((unsigned int)((int)((unsigned int)(v4579 + 4) >> 2)) >> 1)) & 3) * 2)) + ((((v4615 + ((~(((v4617 ^ -1) | (-(v4617 ^ -1))) >> 31)) & 2)) - (v4618 + ((~(((v4619 ^ -1) | (-(v4619 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
      v4639[v4739] = v4636;
      int * v4641 = v4575->cache_tags;
      int v4742 = (int)((unsigned int)((int)((unsigned int)(v4579 + 4) >> 2)) >> 1);
      v4641[v4718] = v4742;
      int * v4643 = v4575->cache_dirty;
      v4643[v4718] = 0;
      int * v4645 = v4575->cache_age;
      v4645[v4718] = 1;
      int * v4647 = v4575->cache_age;
      int v4648 = v4647[v4718];
      int v4649 = v4647[v4692];
      int v4748 = v4649 + ((int)((unsigned int)(v4649 - v4648) >> 31));
      v4647[v4692] = v4748;
      int * v4651 = v4575->cache_age;
      int v4652 = v4651[v4693];
      int v4750 = v4652 + ((int)((unsigned int)(v4652 - v4648) >> 31));
      v4651[v4693] = v4750;
      int * v4654 = v4575->cache_age;
      v4654[v4718] = 0;
      v4657 = v4718;
    }
    int * v4658 = v4575->cache_vals;
    int v4753 = v4657 * 2;
    int v4659 = v4658[v4753];
    int v4754 = (v4657 * 2) + 1;
    int v4660 = v4658[v4754];
    int v4755 = (((((int)((unsigned int)((int)((unsigned int)(v4579 + 4) >> 2)) >> 1)) & 1) * 2) + ((((v4599 + ((~(((v4601 ^ -1) | (-(v4601 ^ -1))) >> 31)) & 2)) - (v4602 + ((~(((v4603 ^ -1) | (-(v4603 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
    v4658[v4755] = v4659;
    int * v4662 = v4575->cache_vals;
    int v4758 = ((((((int)((unsigned int)((int)((unsigned int)(v4579 + 4) >> 2)) >> 1)) & 1) * 2) + ((((v4599 + ((~(((v4601 ^ -1) | (-(v4601 ^ -1))) >> 31)) & 2)) - (v4602 + ((~(((v4603 ^ -1) | (-(v4603 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
    v4662[v4758] = v4660;
    int * v4664 = v4575->cache_tags;
    int v4761 = ((((int)((unsigned int)((int)((unsigned int)(v4579 + 4) >> 2)) >> 1)) & 1) * 2) + ((((v4599 + ((~(((v4601 ^ -1) | (-(v4601 ^ -1))) >> 31)) & 2)) - (v4602 + ((~(((v4603 ^ -1) | (-(v4603 ^ -1))) >> 31)) & 2))) >> 31) & 1);
    int v4762 = (int)((unsigned int)((int)((unsigned int)(v4579 + 4) >> 2)) >> 1);
    v4664[v4761] = v4762;
    int * v4666 = v4575->cache_dirty;
    v4666[v4761] = 0;
    int * v4668 = v4575->cache_age;
    v4668[v4761] = 1;
    int * v4670 = v4575->cache_age;
    int v4671 = v4670[v4761];
    int v4672 = v4670[v4690];
    int v4768 = v4672 + ((int)((unsigned int)(v4672 - v4671) >> 31));
    v4670[v4690] = v4768;
    int * v4674 = v4575->cache_age;
    int v4675 = v4674[v4691];
    int v4770 = v4675 + ((int)((unsigned int)(v4675 - v4671) >> 31));
    v4674[v4691] = v4770;
    int * v4677 = v4575->cache_age;
    v4677[v4761] = 0;
    v4680 = v4761;
  }
  int v4773 = (v4680 * 2) + (((int)((unsigned int)(v4579 + 4) >> 2)) & 1);
  int v4681 = v4587[v4773];
  int * v4682 = v4575->regs;
  v4682[16] = v4681;
  struct StateT * v4684 = slot_54(v4575);
  return v4684;
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

struct StateT * slot_66(struct StateT * v5753) {
  int * v5754 = v5753->saved_regs;
  int * v5755 = v5753->regs;
  int v5756 = v5755[16];
  v5754[16] = v5756;
  int v5758 = v5753->timer;
  int v5770 = v5758 + 1;
  v5753->timer = v5770;
  int * v5760 = v5753->regs;
  int v5761 = v5760[10];
  int v5762 = v5760[15];
  int v5774 = v5761 + v5762;
  v5760[16] = v5774;
  struct StateT * v5764 = slot_67(v5753);
  return v5764;
}

struct StateT * slot_78(struct StateT * v6733) {
  int * v6734 = v6733->regs;
  int v6735 = v6734[12];
  int v6736 = v6734[14];
  bool v6772 = (v6735 ^ -2147483648) >= (v6736 ^ -2147483648);
  struct StateT * v6767;
  if (v6772) {
    struct StateT * v6737 = slot_51(v6733);
    v6767 = v6737;
  } else {
    int v6739 = v6733->timer;
    int v6775 = v6739 + 15;
    v6733->timer = v6775;
    int * v6741 = v6733->saved_regs;
    int v6742 = v6741[15];
    int * v6743 = v6733->regs;
    v6743[15] = v6742;
    int * v6745 = v6733->saved_regs;
    int v6746 = v6745[16];
    int * v6747 = v6733->regs;
    v6747[16] = v6746;
    int * v6749 = v6733->saved_regs;
    int v6750 = v6749[17];
    int * v6751 = v6733->regs;
    v6751[17] = v6750;
    int * v6753 = v6733->saved_regs;
    int v6754 = v6753[5];
    int * v6755 = v6733->regs;
    v6755[5] = v6754;
    int * v6757 = v6733->saved_regs;
    int v6758 = v6757[6];
    int * v6759 = v6733->regs;
    v6759[6] = v6758;
    int * v6761 = v6733->saved_regs;
    int v6762 = v6761[7];
    int * v6763 = v6733->regs;
    v6763[7] = v6762;
    struct StateT * v6765 = slot_21(v6733);
    v6767 = v6765;
  }
  return v6767;
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
  struct StateT * v3936 = slot_51(v3929);
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

struct StateT * slot_57(struct StateT * v5015) {
  int v5016 = v5015->timer;
  int v5024 = v5016 + 1;
  v5015->timer = v5024;
  int * v5018 = v5015->regs;
  int v5019 = v5018[13];
  int v5020 = v5018[17];
  int v5028 = v5019 & v5020;
  v5018[17] = v5028;
  struct StateT * v5022 = slot_58(v5015);
  return v5022;
}

struct StateT * slot_68(struct StateT * v5793) {
  int * v5794 = v5793->saved_regs;
  int * v5795 = v5793->regs;
  int v5796 = v5795[17];
  v5794[17] = v5796;
  int v5798 = v5793->timer;
  int v5912 = v5798 + 1;
  v5793->timer = v5912;
  int * v5800 = v5793->regs;
  int v5801 = v5800[16];
  int * v5802 = v5793->cache_tags;
  int v5916 = (((int)((unsigned int)((int)((unsigned int)v5801 >> 2)) >> 1)) & 1) * 2;
  int v5803 = v5802[v5916];
  int v5917 = ((((int)((unsigned int)((int)((unsigned int)v5801 >> 2)) >> 1)) & 1) * 2) + 1;
  int v5804 = v5802[v5917];
  int v5918 = 4 + ((((int)((unsigned int)((int)((unsigned int)v5801 >> 2)) >> 1)) & 3) * 2);
  int v5805 = v5802[v5918];
  int v5919 = (4 + ((((int)((unsigned int)((int)((unsigned int)v5801 >> 2)) >> 1)) & 3) * 2)) + 1;
  int v5806 = v5802[v5919];
  int v5807 = v5793->timer;
  int v5920 = v5807 + ((100 ^ (((~(((v5805 ^ ((int)((unsigned int)((int)((unsigned int)v5801 >> 2)) >> 1))) | (-(v5805 ^ ((int)((unsigned int)((int)((unsigned int)v5801 >> 2)) >> 1))))) >> 31)) | (~(((v5806 ^ ((int)((unsigned int)((int)((unsigned int)v5801 >> 2)) >> 1))) | (-(v5806 ^ ((int)((unsigned int)((int)((unsigned int)v5801 >> 2)) >> 1))))) >> 31))) & 104)) ^ (((~(((v5803 ^ ((int)((unsigned int)((int)((unsigned int)v5801 >> 2)) >> 1))) | (-(v5803 ^ ((int)((unsigned int)((int)((unsigned int)v5801 >> 2)) >> 1))))) >> 31)) | (~(((v5804 ^ ((int)((unsigned int)((int)((unsigned int)v5801 >> 2)) >> 1))) | (-(v5804 ^ ((int)((unsigned int)((int)((unsigned int)v5801 >> 2)) >> 1))))) >> 31))) & (1 ^ (100 ^ (((~(((v5805 ^ ((int)((unsigned int)((int)((unsigned int)v5801 >> 2)) >> 1))) | (-(v5805 ^ ((int)((unsigned int)((int)((unsigned int)v5801 >> 2)) >> 1))))) >> 31)) | (~(((v5806 ^ ((int)((unsigned int)((int)((unsigned int)v5801 >> 2)) >> 1))) | (-(v5806 ^ ((int)((unsigned int)((int)((unsigned int)v5801 >> 2)) >> 1))))) >> 31))) & 104)))));
  v5793->timer = v5920;
  int * v5809 = v5793->cache_vals;
  bool v5921 = !(((~(((v5803 ^ ((int)((unsigned int)((int)((unsigned int)v5801 >> 2)) >> 1))) | (-(v5803 ^ ((int)((unsigned int)((int)((unsigned int)v5801 >> 2)) >> 1))))) >> 31)) | (~(((v5804 ^ ((int)((unsigned int)((int)((unsigned int)v5801 >> 2)) >> 1))) | (-(v5804 ^ ((int)((unsigned int)((int)((unsigned int)v5801 >> 2)) >> 1))))) >> 31))) == 0);
  int v5902;
  if (v5921) {
    int * v5810 = v5793->cache_age;
    int v5923 = ((((int)((unsigned int)((int)((unsigned int)v5801 >> 2)) >> 1)) & 1) * 2) + ((~(((v5804 ^ ((int)((unsigned int)((int)((unsigned int)v5801 >> 2)) >> 1))) | (-(v5804 ^ ((int)((unsigned int)((int)((unsigned int)v5801 >> 2)) >> 1))))) >> 31)) & 1);
    int v5811 = v5810[v5923];
    int v5812 = v5810[v5916];
    int v5924 = v5812 + ((int)((unsigned int)(v5812 - v5811) >> 31));
    v5810[v5916] = v5924;
    int * v5814 = v5793->cache_age;
    int v5815 = v5814[v5917];
    int v5926 = v5815 + ((int)((unsigned int)(v5815 - v5811) >> 31));
    v5814[v5917] = v5926;
    int * v5817 = v5793->cache_age;
    v5817[v5923] = 0;
    v5902 = v5923;
  } else {
    int * v5820 = v5793->cache_age;
    int v5930 = (((int)((unsigned int)((int)((unsigned int)v5801 >> 2)) >> 1)) & 1) * 2;
    int v5821 = v5820[v5930];
    int * v5822 = v5793->cache_tags;
    int v5823 = v5822[v5930];
    int v5824 = v5820[v5917];
    int v5825 = v5822[v5917];
    bool v5932 = !(((~(((v5805 ^ ((int)((unsigned int)((int)((unsigned int)v5801 >> 2)) >> 1))) | (-(v5805 ^ ((int)((unsigned int)((int)((unsigned int)v5801 >> 2)) >> 1))))) >> 31)) | (~(((v5806 ^ ((int)((unsigned int)((int)((unsigned int)v5801 >> 2)) >> 1))) | (-(v5806 ^ ((int)((unsigned int)((int)((unsigned int)v5801 >> 2)) >> 1))))) >> 31))) == 0);
    int v5879;
    if (v5932) {
      int * v5826 = v5793->cache_age;
      int v5934 = (4 + ((((int)((unsigned int)((int)((unsigned int)v5801 >> 2)) >> 1)) & 3) * 2)) + ((~(((v5806 ^ ((int)((unsigned int)((int)((unsigned int)v5801 >> 2)) >> 1))) | (-(v5806 ^ ((int)((unsigned int)((int)((unsigned int)v5801 >> 2)) >> 1))))) >> 31)) & 1);
      int v5827 = v5826[v5934];
      int v5828 = v5826[v5918];
      int v5935 = v5828 + ((int)((unsigned int)(v5828 - v5827) >> 31));
      v5826[v5918] = v5935;
      int * v5830 = v5793->cache_age;
      int v5831 = v5830[v5919];
      int v5937 = v5831 + ((int)((unsigned int)(v5831 - v5827) >> 31));
      v5830[v5919] = v5937;
      int * v5833 = v5793->cache_age;
      v5833[v5934] = 0;
      v5879 = v5934;
    } else {
      int * v5836 = v5793->cache_age;
      int v5941 = 4 + ((((int)((unsigned int)((int)((unsigned int)v5801 >> 2)) >> 1)) & 3) * 2);
      int v5837 = v5836[v5941];
      int * v5838 = v5793->cache_tags;
      int v5839 = v5838[v5941];
      int v5840 = v5836[v5919];
      int v5841 = v5838[v5919];
      int * v5842 = v5793->cache_dirty;
      int v5944 = (4 + ((((int)((unsigned int)((int)((unsigned int)v5801 >> 2)) >> 1)) & 3) * 2)) + ((((v5837 + ((~(((v5839 ^ -1) | (-(v5839 ^ -1))) >> 31)) & 2)) - (v5840 + ((~(((v5841 ^ -1) | (-(v5841 ^ -1))) >> 31)) & 2))) >> 31) & 1);
      int v5843 = v5842[v5944];
      bool v5945 = !(v5843 == 0);
      if (v5945) {
        int * v5844 = v5793->cache_tags;
        int v5845 = v5844[v5944];
        int * v5846 = v5793->cache_vals;
        int v5948 = ((4 + ((((int)((unsigned int)((int)((unsigned int)v5801 >> 2)) >> 1)) & 3) * 2)) + ((((v5837 + ((~(((v5839 ^ -1) | (-(v5839 ^ -1))) >> 31)) & 2)) - (v5840 + ((~(((v5841 ^ -1) | (-(v5841 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
        int v5847 = v5846[v5948];
        int v5949 = (((4 + ((((int)((unsigned int)((int)((unsigned int)v5801 >> 2)) >> 1)) & 3) * 2)) + ((((v5837 + ((~(((v5839 ^ -1) | (-(v5839 ^ -1))) >> 31)) & 2)) - (v5840 + ((~(((v5841 ^ -1) | (-(v5841 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
        int v5848 = v5846[v5949];
        int * v5849 = v5793->mem;
        int v5951 = v5845 * 2;
        v5849[v5951] = v5847;
        int * v5851 = v5793->mem;
        int v5954 = (v5845 * 2) + 1;
        v5851[v5954] = v5848;
        ;
      } else {
        ;
      }
      int * v5856 = v5793->mem;
      int v5959 = ((int)((unsigned int)((int)((unsigned int)v5801 >> 2)) >> 1)) * 2;
      int v5857 = v5856[v5959];
      int v5960 = (((int)((unsigned int)((int)((unsigned int)v5801 >> 2)) >> 1)) * 2) + 1;
      int v5858 = v5856[v5960];
      int * v5859 = v5793->cache_vals;
      int v5962 = ((4 + ((((int)((unsigned int)((int)((unsigned int)v5801 >> 2)) >> 1)) & 3) * 2)) + ((((v5837 + ((~(((v5839 ^ -1) | (-(v5839 ^ -1))) >> 31)) & 2)) - (v5840 + ((~(((v5841 ^ -1) | (-(v5841 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
      v5859[v5962] = v5857;
      int * v5861 = v5793->cache_vals;
      int v5965 = (((4 + ((((int)((unsigned int)((int)((unsigned int)v5801 >> 2)) >> 1)) & 3) * 2)) + ((((v5837 + ((~(((v5839 ^ -1) | (-(v5839 ^ -1))) >> 31)) & 2)) - (v5840 + ((~(((v5841 ^ -1) | (-(v5841 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
      v5861[v5965] = v5858;
      int * v5863 = v5793->cache_tags;
      int v5968 = (int)((unsigned int)((int)((unsigned int)v5801 >> 2)) >> 1);
      v5863[v5944] = v5968;
      int * v5865 = v5793->cache_dirty;
      v5865[v5944] = 0;
      int * v5867 = v5793->cache_age;
      v5867[v5944] = 1;
      int * v5869 = v5793->cache_age;
      int v5870 = v5869[v5944];
      int v5871 = v5869[v5918];
      int v5974 = v5871 + ((int)((unsigned int)(v5871 - v5870) >> 31));
      v5869[v5918] = v5974;
      int * v5873 = v5793->cache_age;
      int v5874 = v5873[v5919];
      int v5976 = v5874 + ((int)((unsigned int)(v5874 - v5870) >> 31));
      v5873[v5919] = v5976;
      int * v5876 = v5793->cache_age;
      v5876[v5944] = 0;
      v5879 = v5944;
    }
    int * v5880 = v5793->cache_vals;
    int v5979 = v5879 * 2;
    int v5881 = v5880[v5979];
    int v5980 = (v5879 * 2) + 1;
    int v5882 = v5880[v5980];
    int v5981 = (((((int)((unsigned int)((int)((unsigned int)v5801 >> 2)) >> 1)) & 1) * 2) + ((((v5821 + ((~(((v5823 ^ -1) | (-(v5823 ^ -1))) >> 31)) & 2)) - (v5824 + ((~(((v5825 ^ -1) | (-(v5825 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
    v5880[v5981] = v5881;
    int * v5884 = v5793->cache_vals;
    int v5984 = ((((((int)((unsigned int)((int)((unsigned int)v5801 >> 2)) >> 1)) & 1) * 2) + ((((v5821 + ((~(((v5823 ^ -1) | (-(v5823 ^ -1))) >> 31)) & 2)) - (v5824 + ((~(((v5825 ^ -1) | (-(v5825 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
    v5884[v5984] = v5882;
    int * v5886 = v5793->cache_tags;
    int v5987 = ((((int)((unsigned int)((int)((unsigned int)v5801 >> 2)) >> 1)) & 1) * 2) + ((((v5821 + ((~(((v5823 ^ -1) | (-(v5823 ^ -1))) >> 31)) & 2)) - (v5824 + ((~(((v5825 ^ -1) | (-(v5825 ^ -1))) >> 31)) & 2))) >> 31) & 1);
    int v5988 = (int)((unsigned int)((int)((unsigned int)v5801 >> 2)) >> 1);
    v5886[v5987] = v5988;
    int * v5888 = v5793->cache_dirty;
    v5888[v5987] = 0;
    int * v5890 = v5793->cache_age;
    v5890[v5987] = 1;
    int * v5892 = v5793->cache_age;
    int v5893 = v5892[v5987];
    int v5894 = v5892[v5916];
    int v5994 = v5894 + ((int)((unsigned int)(v5894 - v5893) >> 31));
    v5892[v5916] = v5994;
    int * v5896 = v5793->cache_age;
    int v5897 = v5896[v5917];
    int v5996 = v5897 + ((int)((unsigned int)(v5897 - v5893) >> 31));
    v5896[v5917] = v5996;
    int * v5899 = v5793->cache_age;
    v5899[v5987] = 0;
    v5902 = v5987;
  }
  int v5999 = (v5902 * 2) + (((int)((unsigned int)v5801 >> 2)) & 1);
  int v5903 = v5809[v5999];
  int * v5904 = v5793->regs;
  v5904[17] = v5903;
  struct StateT * v5906 = slot_69(v5793);
  return v5906;
}

struct StateT * slot_59(struct StateT * v5047) {
  int v5048 = v5047->timer;
  int v5056 = v5048 + 1;
  v5047->timer = v5056;
  int * v5050 = v5047->regs;
  int v5051 = v5050[16];
  int v5052 = v5050[5];
  int v5060 = v5051 ^ v5052;
  v5050[16] = v5060;
  struct StateT * v5054 = slot_60(v5047);
  return v5054;
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

struct StateT * slot_62(struct StateT * v5394) {
  int v5395 = v5394->timer;
  int v5565 = v5395 + 1;
  v5394->timer = v5565;
  int * v5397 = v5394->regs;
  int v5398 = v5397[15];
  int v5399 = v5397[16];
  int * v5400 = v5394->cache_tags;
  int v5570 = (((int)((unsigned int)((int)((unsigned int)(v5398 + 4) >> 2)) >> 1)) & 1) * 2;
  int v5401 = v5400[v5570];
  int v5571 = ((((int)((unsigned int)((int)((unsigned int)(v5398 + 4) >> 2)) >> 1)) & 1) * 2) + 1;
  int v5402 = v5400[v5571];
  int v5572 = 4 + ((((int)((unsigned int)((int)((unsigned int)(v5398 + 4) >> 2)) >> 1)) & 3) * 2);
  int v5403 = v5400[v5572];
  int v5573 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v5398 + 4) >> 2)) >> 1)) & 3) * 2)) + 1;
  int v5404 = v5400[v5573];
  int v5405 = v5394->timer;
  int v5574 = v5405 + ((100 ^ (((~(((v5403 ^ ((int)((unsigned int)((int)((unsigned int)(v5398 + 4) >> 2)) >> 1))) | (-(v5403 ^ ((int)((unsigned int)((int)((unsigned int)(v5398 + 4) >> 2)) >> 1))))) >> 31)) | (~(((v5404 ^ ((int)((unsigned int)((int)((unsigned int)(v5398 + 4) >> 2)) >> 1))) | (-(v5404 ^ ((int)((unsigned int)((int)((unsigned int)(v5398 + 4) >> 2)) >> 1))))) >> 31))) & 104)) ^ (((~(((v5401 ^ ((int)((unsigned int)((int)((unsigned int)(v5398 + 4) >> 2)) >> 1))) | (-(v5401 ^ ((int)((unsigned int)((int)((unsigned int)(v5398 + 4) >> 2)) >> 1))))) >> 31)) | (~(((v5402 ^ ((int)((unsigned int)((int)((unsigned int)(v5398 + 4) >> 2)) >> 1))) | (-(v5402 ^ ((int)((unsigned int)((int)((unsigned int)(v5398 + 4) >> 2)) >> 1))))) >> 31))) & (1 ^ (100 ^ (((~(((v5403 ^ ((int)((unsigned int)((int)((unsigned int)(v5398 + 4) >> 2)) >> 1))) | (-(v5403 ^ ((int)((unsigned int)((int)((unsigned int)(v5398 + 4) >> 2)) >> 1))))) >> 31)) | (~(((v5404 ^ ((int)((unsigned int)((int)((unsigned int)(v5398 + 4) >> 2)) >> 1))) | (-(v5404 ^ ((int)((unsigned int)((int)((unsigned int)(v5398 + 4) >> 2)) >> 1))))) >> 31))) & 104)))));
  v5394->timer = v5574;
  bool v5575 = !(((~(((v5401 ^ ((int)((unsigned int)((int)((unsigned int)(v5398 + 4) >> 2)) >> 1))) | (-(v5401 ^ ((int)((unsigned int)((int)((unsigned int)(v5398 + 4) >> 2)) >> 1))))) >> 31)) | (~(((v5402 ^ ((int)((unsigned int)((int)((unsigned int)(v5398 + 4) >> 2)) >> 1))) | (-(v5402 ^ ((int)((unsigned int)((int)((unsigned int)(v5398 + 4) >> 2)) >> 1))))) >> 31))) == 0);
  int v5499;
  if (v5575) {
    int * v5407 = v5394->cache_age;
    int v5577 = ((((int)((unsigned int)((int)((unsigned int)(v5398 + 4) >> 2)) >> 1)) & 1) * 2) + ((~(((v5402 ^ ((int)((unsigned int)((int)((unsigned int)(v5398 + 4) >> 2)) >> 1))) | (-(v5402 ^ ((int)((unsigned int)((int)((unsigned int)(v5398 + 4) >> 2)) >> 1))))) >> 31)) & 1);
    int v5408 = v5407[v5577];
    int v5409 = v5407[v5570];
    int v5578 = v5409 + ((int)((unsigned int)(v5409 - v5408) >> 31));
    v5407[v5570] = v5578;
    int * v5411 = v5394->cache_age;
    int v5412 = v5411[v5571];
    int v5580 = v5412 + ((int)((unsigned int)(v5412 - v5408) >> 31));
    v5411[v5571] = v5580;
    int * v5414 = v5394->cache_age;
    v5414[v5577] = 0;
    v5499 = v5577;
  } else {
    int * v5417 = v5394->cache_age;
    int v5584 = (((int)((unsigned int)((int)((unsigned int)(v5398 + 4) >> 2)) >> 1)) & 1) * 2;
    int v5418 = v5417[v5584];
    int * v5419 = v5394->cache_tags;
    int v5420 = v5419[v5584];
    int v5421 = v5417[v5571];
    int v5422 = v5419[v5571];
    bool v5586 = !(((~(((v5403 ^ ((int)((unsigned int)((int)((unsigned int)(v5398 + 4) >> 2)) >> 1))) | (-(v5403 ^ ((int)((unsigned int)((int)((unsigned int)(v5398 + 4) >> 2)) >> 1))))) >> 31)) | (~(((v5404 ^ ((int)((unsigned int)((int)((unsigned int)(v5398 + 4) >> 2)) >> 1))) | (-(v5404 ^ ((int)((unsigned int)((int)((unsigned int)(v5398 + 4) >> 2)) >> 1))))) >> 31))) == 0);
    int v5476;
    if (v5586) {
      int * v5423 = v5394->cache_age;
      int v5588 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v5398 + 4) >> 2)) >> 1)) & 3) * 2)) + ((~(((v5404 ^ ((int)((unsigned int)((int)((unsigned int)(v5398 + 4) >> 2)) >> 1))) | (-(v5404 ^ ((int)((unsigned int)((int)((unsigned int)(v5398 + 4) >> 2)) >> 1))))) >> 31)) & 1);
      int v5424 = v5423[v5588];
      int v5425 = v5423[v5572];
      int v5589 = v5425 + ((int)((unsigned int)(v5425 - v5424) >> 31));
      v5423[v5572] = v5589;
      int * v5427 = v5394->cache_age;
      int v5428 = v5427[v5573];
      int v5591 = v5428 + ((int)((unsigned int)(v5428 - v5424) >> 31));
      v5427[v5573] = v5591;
      int * v5430 = v5394->cache_age;
      v5430[v5588] = 0;
      v5476 = v5588;
    } else {
      int * v5433 = v5394->cache_age;
      int v5595 = 4 + ((((int)((unsigned int)((int)((unsigned int)(v5398 + 4) >> 2)) >> 1)) & 3) * 2);
      int v5434 = v5433[v5595];
      int * v5435 = v5394->cache_tags;
      int v5436 = v5435[v5595];
      int v5437 = v5433[v5573];
      int v5438 = v5435[v5573];
      int * v5439 = v5394->cache_dirty;
      int v5598 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v5398 + 4) >> 2)) >> 1)) & 3) * 2)) + ((((v5434 + ((~(((v5436 ^ -1) | (-(v5436 ^ -1))) >> 31)) & 2)) - (v5437 + ((~(((v5438 ^ -1) | (-(v5438 ^ -1))) >> 31)) & 2))) >> 31) & 1);
      int v5440 = v5439[v5598];
      bool v5599 = !(v5440 == 0);
      if (v5599) {
        int * v5441 = v5394->cache_tags;
        int v5442 = v5441[v5598];
        int * v5443 = v5394->cache_vals;
        int v5602 = ((4 + ((((int)((unsigned int)((int)((unsigned int)(v5398 + 4) >> 2)) >> 1)) & 3) * 2)) + ((((v5434 + ((~(((v5436 ^ -1) | (-(v5436 ^ -1))) >> 31)) & 2)) - (v5437 + ((~(((v5438 ^ -1) | (-(v5438 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
        int v5444 = v5443[v5602];
        int v5603 = (((4 + ((((int)((unsigned int)((int)((unsigned int)(v5398 + 4) >> 2)) >> 1)) & 3) * 2)) + ((((v5434 + ((~(((v5436 ^ -1) | (-(v5436 ^ -1))) >> 31)) & 2)) - (v5437 + ((~(((v5438 ^ -1) | (-(v5438 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
        int v5445 = v5443[v5603];
        int * v5446 = v5394->mem;
        int v5605 = v5442 * 2;
        v5446[v5605] = v5444;
        int * v5448 = v5394->mem;
        int v5608 = (v5442 * 2) + 1;
        v5448[v5608] = v5445;
        ;
      } else {
        ;
      }
      int * v5453 = v5394->mem;
      int v5613 = ((int)((unsigned int)((int)((unsigned int)(v5398 + 4) >> 2)) >> 1)) * 2;
      int v5454 = v5453[v5613];
      int v5614 = (((int)((unsigned int)((int)((unsigned int)(v5398 + 4) >> 2)) >> 1)) * 2) + 1;
      int v5455 = v5453[v5614];
      int * v5456 = v5394->cache_vals;
      int v5616 = ((4 + ((((int)((unsigned int)((int)((unsigned int)(v5398 + 4) >> 2)) >> 1)) & 3) * 2)) + ((((v5434 + ((~(((v5436 ^ -1) | (-(v5436 ^ -1))) >> 31)) & 2)) - (v5437 + ((~(((v5438 ^ -1) | (-(v5438 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
      v5456[v5616] = v5454;
      int * v5458 = v5394->cache_vals;
      int v5619 = (((4 + ((((int)((unsigned int)((int)((unsigned int)(v5398 + 4) >> 2)) >> 1)) & 3) * 2)) + ((((v5434 + ((~(((v5436 ^ -1) | (-(v5436 ^ -1))) >> 31)) & 2)) - (v5437 + ((~(((v5438 ^ -1) | (-(v5438 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
      v5458[v5619] = v5455;
      int * v5460 = v5394->cache_tags;
      int v5622 = (int)((unsigned int)((int)((unsigned int)(v5398 + 4) >> 2)) >> 1);
      v5460[v5598] = v5622;
      int * v5462 = v5394->cache_dirty;
      v5462[v5598] = 0;
      int * v5464 = v5394->cache_age;
      v5464[v5598] = 1;
      int * v5466 = v5394->cache_age;
      int v5467 = v5466[v5598];
      int v5468 = v5466[v5572];
      int v5628 = v5468 + ((int)((unsigned int)(v5468 - v5467) >> 31));
      v5466[v5572] = v5628;
      int * v5470 = v5394->cache_age;
      int v5471 = v5470[v5573];
      int v5630 = v5471 + ((int)((unsigned int)(v5471 - v5467) >> 31));
      v5470[v5573] = v5630;
      int * v5473 = v5394->cache_age;
      v5473[v5598] = 0;
      v5476 = v5598;
    }
    int * v5477 = v5394->cache_vals;
    int v5633 = v5476 * 2;
    int v5478 = v5477[v5633];
    int v5634 = (v5476 * 2) + 1;
    int v5479 = v5477[v5634];
    int v5635 = (((((int)((unsigned int)((int)((unsigned int)(v5398 + 4) >> 2)) >> 1)) & 1) * 2) + ((((v5418 + ((~(((v5420 ^ -1) | (-(v5420 ^ -1))) >> 31)) & 2)) - (v5421 + ((~(((v5422 ^ -1) | (-(v5422 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
    v5477[v5635] = v5478;
    int * v5481 = v5394->cache_vals;
    int v5638 = ((((((int)((unsigned int)((int)((unsigned int)(v5398 + 4) >> 2)) >> 1)) & 1) * 2) + ((((v5418 + ((~(((v5420 ^ -1) | (-(v5420 ^ -1))) >> 31)) & 2)) - (v5421 + ((~(((v5422 ^ -1) | (-(v5422 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
    v5481[v5638] = v5479;
    int * v5483 = v5394->cache_tags;
    int v5641 = ((((int)((unsigned int)((int)((unsigned int)(v5398 + 4) >> 2)) >> 1)) & 1) * 2) + ((((v5418 + ((~(((v5420 ^ -1) | (-(v5420 ^ -1))) >> 31)) & 2)) - (v5421 + ((~(((v5422 ^ -1) | (-(v5422 ^ -1))) >> 31)) & 2))) >> 31) & 1);
    int v5642 = (int)((unsigned int)((int)((unsigned int)(v5398 + 4) >> 2)) >> 1);
    v5483[v5641] = v5642;
    int * v5485 = v5394->cache_dirty;
    v5485[v5641] = 0;
    int * v5487 = v5394->cache_age;
    v5487[v5641] = 1;
    int * v5489 = v5394->cache_age;
    int v5490 = v5489[v5641];
    int v5491 = v5489[v5570];
    int v5648 = v5491 + ((int)((unsigned int)(v5491 - v5490) >> 31));
    v5489[v5570] = v5648;
    int * v5493 = v5394->cache_age;
    int v5494 = v5493[v5571];
    int v5650 = v5494 + ((int)((unsigned int)(v5494 - v5490) >> 31));
    v5493[v5571] = v5650;
    int * v5496 = v5394->cache_age;
    v5496[v5641] = 0;
    v5499 = v5641;
  }
  int * v5500 = v5394->cache_vals;
  int v5653 = (v5499 * 2) + (((int)((unsigned int)(v5398 + 4) >> 2)) & 1);
  v5500[v5653] = v5399;
  int * v5502 = v5394->cache_tags;
  int v5503 = v5502[v5572];
  int v5504 = v5502[v5573];
  bool v5656 = !(((~(((v5503 ^ ((int)((unsigned int)((int)((unsigned int)(v5398 + 4) >> 2)) >> 1))) | (-(v5503 ^ ((int)((unsigned int)((int)((unsigned int)(v5398 + 4) >> 2)) >> 1))))) >> 31)) | (~(((v5504 ^ ((int)((unsigned int)((int)((unsigned int)(v5398 + 4) >> 2)) >> 1))) | (-(v5504 ^ ((int)((unsigned int)((int)((unsigned int)(v5398 + 4) >> 2)) >> 1))))) >> 31))) == 0);
  int v5558;
  if (v5656) {
    int * v5505 = v5394->cache_age;
    int v5658 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v5398 + 4) >> 2)) >> 1)) & 3) * 2)) + ((~(((v5504 ^ ((int)((unsigned int)((int)((unsigned int)(v5398 + 4) >> 2)) >> 1))) | (-(v5504 ^ ((int)((unsigned int)((int)((unsigned int)(v5398 + 4) >> 2)) >> 1))))) >> 31)) & 1);
    int v5506 = v5505[v5658];
    int v5507 = v5505[v5572];
    int v5659 = v5507 + ((int)((unsigned int)(v5507 - v5506) >> 31));
    v5505[v5572] = v5659;
    int * v5509 = v5394->cache_age;
    int v5510 = v5509[v5573];
    int v5661 = v5510 + ((int)((unsigned int)(v5510 - v5506) >> 31));
    v5509[v5573] = v5661;
    int * v5512 = v5394->cache_age;
    v5512[v5658] = 0;
    v5558 = v5658;
  } else {
    int * v5515 = v5394->cache_age;
    int v5665 = 4 + ((((int)((unsigned int)((int)((unsigned int)(v5398 + 4) >> 2)) >> 1)) & 3) * 2);
    int v5516 = v5515[v5665];
    int * v5517 = v5394->cache_tags;
    int v5518 = v5517[v5665];
    int v5519 = v5515[v5573];
    int v5520 = v5517[v5573];
    int * v5521 = v5394->cache_dirty;
    int v5668 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v5398 + 4) >> 2)) >> 1)) & 3) * 2)) + ((((v5516 + ((~(((v5518 ^ -1) | (-(v5518 ^ -1))) >> 31)) & 2)) - (v5519 + ((~(((v5520 ^ -1) | (-(v5520 ^ -1))) >> 31)) & 2))) >> 31) & 1);
    int v5522 = v5521[v5668];
    bool v5669 = !(v5522 == 0);
    if (v5669) {
      int * v5523 = v5394->cache_tags;
      int v5524 = v5523[v5668];
      int * v5525 = v5394->cache_vals;
      int v5672 = ((4 + ((((int)((unsigned int)((int)((unsigned int)(v5398 + 4) >> 2)) >> 1)) & 3) * 2)) + ((((v5516 + ((~(((v5518 ^ -1) | (-(v5518 ^ -1))) >> 31)) & 2)) - (v5519 + ((~(((v5520 ^ -1) | (-(v5520 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
      int v5526 = v5525[v5672];
      int v5673 = (((4 + ((((int)((unsigned int)((int)((unsigned int)(v5398 + 4) >> 2)) >> 1)) & 3) * 2)) + ((((v5516 + ((~(((v5518 ^ -1) | (-(v5518 ^ -1))) >> 31)) & 2)) - (v5519 + ((~(((v5520 ^ -1) | (-(v5520 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
      int v5527 = v5525[v5673];
      int * v5528 = v5394->mem;
      int v5675 = v5524 * 2;
      v5528[v5675] = v5526;
      int * v5530 = v5394->mem;
      int v5678 = (v5524 * 2) + 1;
      v5530[v5678] = v5527;
      ;
    } else {
      ;
    }
    int * v5535 = v5394->mem;
    int v5683 = ((int)((unsigned int)((int)((unsigned int)(v5398 + 4) >> 2)) >> 1)) * 2;
    int v5536 = v5535[v5683];
    int v5684 = (((int)((unsigned int)((int)((unsigned int)(v5398 + 4) >> 2)) >> 1)) * 2) + 1;
    int v5537 = v5535[v5684];
    int * v5538 = v5394->cache_vals;
    int v5686 = ((4 + ((((int)((unsigned int)((int)((unsigned int)(v5398 + 4) >> 2)) >> 1)) & 3) * 2)) + ((((v5516 + ((~(((v5518 ^ -1) | (-(v5518 ^ -1))) >> 31)) & 2)) - (v5519 + ((~(((v5520 ^ -1) | (-(v5520 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
    v5538[v5686] = v5536;
    int * v5540 = v5394->cache_vals;
    int v5689 = (((4 + ((((int)((unsigned int)((int)((unsigned int)(v5398 + 4) >> 2)) >> 1)) & 3) * 2)) + ((((v5516 + ((~(((v5518 ^ -1) | (-(v5518 ^ -1))) >> 31)) & 2)) - (v5519 + ((~(((v5520 ^ -1) | (-(v5520 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
    v5540[v5689] = v5537;
    int * v5542 = v5394->cache_tags;
    int v5692 = (int)((unsigned int)((int)((unsigned int)(v5398 + 4) >> 2)) >> 1);
    v5542[v5668] = v5692;
    int * v5544 = v5394->cache_dirty;
    v5544[v5668] = 0;
    int * v5546 = v5394->cache_age;
    v5546[v5668] = 1;
    int * v5548 = v5394->cache_age;
    int v5549 = v5548[v5668];
    int v5550 = v5548[v5572];
    int v5698 = v5550 + ((int)((unsigned int)(v5550 - v5549) >> 31));
    v5548[v5572] = v5698;
    int * v5552 = v5394->cache_age;
    int v5553 = v5552[v5573];
    int v5700 = v5553 + ((int)((unsigned int)(v5553 - v5549) >> 31));
    v5552[v5573] = v5700;
    int * v5555 = v5394->cache_age;
    v5555[v5668] = 0;
    v5558 = v5668;
  }
  int * v5559 = v5394->cache_vals;
  int v5703 = (v5558 * 2) + (((int)((unsigned int)(v5398 + 4) >> 2)) & 1);
  v5559[v5703] = v5399;
  int * v5561 = v5394->cache_dirty;
  v5561[v5558] = 1;
  struct StateT * v5563 = slot_63(v5394);
  return v5563;
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

struct StateT * slot_77(struct StateT * v6717) {
  int v6718 = v6717->timer;
  int v6726 = v6718 + 1;
  v6717->timer = v6726;
  int * v6720 = v6717->regs;
  int v6721 = v6720[17];
  int v6722 = v6720[7];
  int v6730 = v6721 ^ v6722;
  v6720[7] = v6730;
  struct StateT * v6724 = slot_78(v6717);
  return v6724;
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

struct StateT * slot_75(struct StateT * v6685) {
  int v6686 = v6685->timer;
  int v6694 = v6686 + 1;
  v6685->timer = v6694;
  int * v6688 = v6685->regs;
  int v6689 = v6688[13];
  int v6690 = v6688[6];
  int v6698 = v6689 & v6690;
  v6688[6] = v6698;
  struct StateT * v6692 = slot_76(v6685);
  return v6692;
}

struct StateT * slot_56(struct StateT * v4999) {
  int v5000 = v4999->timer;
  int v5008 = v5000 + 1;
  v4999->timer = v5008;
  int * v5002 = v4999->regs;
  int v5003 = v5002[17];
  int v5004 = v5002[6];
  int v5012 = v5003 ^ v5004;
  v5002[17] = v5012;
  struct StateT * v5006 = slot_57(v4999);
  return v5006;
}

struct StateT * slot_72(struct StateT * v6637) {
  int v6638 = v6637->timer;
  int v6646 = v6638 + 1;
  v6637->timer = v6646;
  int * v6640 = v6637->regs;
  int v6641 = v6640[6];
  int v6642 = v6640[5];
  int v6650 = v6641 ^ v6642;
  v6640[6] = v6650;
  struct StateT * v6644 = slot_73(v6637);
  return v6644;
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

struct StateT * slot_71(struct StateT * v6426) {
  int * v6427 = v6426->saved_regs;
  int * v6428 = v6426->regs;
  int v6429 = v6428[7];
  v6427[7] = v6429;
  int v6431 = v6426->timer;
  int v6545 = v6431 + 1;
  v6426->timer = v6545;
  int * v6433 = v6426->regs;
  int v6434 = v6433[15];
  int * v6435 = v6426->cache_tags;
  int v6549 = (((int)((unsigned int)((int)((unsigned int)v6434 >> 2)) >> 1)) & 1) * 2;
  int v6436 = v6435[v6549];
  int v6550 = ((((int)((unsigned int)((int)((unsigned int)v6434 >> 2)) >> 1)) & 1) * 2) + 1;
  int v6437 = v6435[v6550];
  int v6551 = 4 + ((((int)((unsigned int)((int)((unsigned int)v6434 >> 2)) >> 1)) & 3) * 2);
  int v6438 = v6435[v6551];
  int v6552 = (4 + ((((int)((unsigned int)((int)((unsigned int)v6434 >> 2)) >> 1)) & 3) * 2)) + 1;
  int v6439 = v6435[v6552];
  int v6440 = v6426->timer;
  int v6553 = v6440 + ((100 ^ (((~(((v6438 ^ ((int)((unsigned int)((int)((unsigned int)v6434 >> 2)) >> 1))) | (-(v6438 ^ ((int)((unsigned int)((int)((unsigned int)v6434 >> 2)) >> 1))))) >> 31)) | (~(((v6439 ^ ((int)((unsigned int)((int)((unsigned int)v6434 >> 2)) >> 1))) | (-(v6439 ^ ((int)((unsigned int)((int)((unsigned int)v6434 >> 2)) >> 1))))) >> 31))) & 104)) ^ (((~(((v6436 ^ ((int)((unsigned int)((int)((unsigned int)v6434 >> 2)) >> 1))) | (-(v6436 ^ ((int)((unsigned int)((int)((unsigned int)v6434 >> 2)) >> 1))))) >> 31)) | (~(((v6437 ^ ((int)((unsigned int)((int)((unsigned int)v6434 >> 2)) >> 1))) | (-(v6437 ^ ((int)((unsigned int)((int)((unsigned int)v6434 >> 2)) >> 1))))) >> 31))) & (1 ^ (100 ^ (((~(((v6438 ^ ((int)((unsigned int)((int)((unsigned int)v6434 >> 2)) >> 1))) | (-(v6438 ^ ((int)((unsigned int)((int)((unsigned int)v6434 >> 2)) >> 1))))) >> 31)) | (~(((v6439 ^ ((int)((unsigned int)((int)((unsigned int)v6434 >> 2)) >> 1))) | (-(v6439 ^ ((int)((unsigned int)((int)((unsigned int)v6434 >> 2)) >> 1))))) >> 31))) & 104)))));
  v6426->timer = v6553;
  int * v6442 = v6426->cache_vals;
  bool v6554 = !(((~(((v6436 ^ ((int)((unsigned int)((int)((unsigned int)v6434 >> 2)) >> 1))) | (-(v6436 ^ ((int)((unsigned int)((int)((unsigned int)v6434 >> 2)) >> 1))))) >> 31)) | (~(((v6437 ^ ((int)((unsigned int)((int)((unsigned int)v6434 >> 2)) >> 1))) | (-(v6437 ^ ((int)((unsigned int)((int)((unsigned int)v6434 >> 2)) >> 1))))) >> 31))) == 0);
  int v6535;
  if (v6554) {
    int * v6443 = v6426->cache_age;
    int v6556 = ((((int)((unsigned int)((int)((unsigned int)v6434 >> 2)) >> 1)) & 1) * 2) + ((~(((v6437 ^ ((int)((unsigned int)((int)((unsigned int)v6434 >> 2)) >> 1))) | (-(v6437 ^ ((int)((unsigned int)((int)((unsigned int)v6434 >> 2)) >> 1))))) >> 31)) & 1);
    int v6444 = v6443[v6556];
    int v6445 = v6443[v6549];
    int v6557 = v6445 + ((int)((unsigned int)(v6445 - v6444) >> 31));
    v6443[v6549] = v6557;
    int * v6447 = v6426->cache_age;
    int v6448 = v6447[v6550];
    int v6559 = v6448 + ((int)((unsigned int)(v6448 - v6444) >> 31));
    v6447[v6550] = v6559;
    int * v6450 = v6426->cache_age;
    v6450[v6556] = 0;
    v6535 = v6556;
  } else {
    int * v6453 = v6426->cache_age;
    int v6563 = (((int)((unsigned int)((int)((unsigned int)v6434 >> 2)) >> 1)) & 1) * 2;
    int v6454 = v6453[v6563];
    int * v6455 = v6426->cache_tags;
    int v6456 = v6455[v6563];
    int v6457 = v6453[v6550];
    int v6458 = v6455[v6550];
    bool v6565 = !(((~(((v6438 ^ ((int)((unsigned int)((int)((unsigned int)v6434 >> 2)) >> 1))) | (-(v6438 ^ ((int)((unsigned int)((int)((unsigned int)v6434 >> 2)) >> 1))))) >> 31)) | (~(((v6439 ^ ((int)((unsigned int)((int)((unsigned int)v6434 >> 2)) >> 1))) | (-(v6439 ^ ((int)((unsigned int)((int)((unsigned int)v6434 >> 2)) >> 1))))) >> 31))) == 0);
    int v6512;
    if (v6565) {
      int * v6459 = v6426->cache_age;
      int v6567 = (4 + ((((int)((unsigned int)((int)((unsigned int)v6434 >> 2)) >> 1)) & 3) * 2)) + ((~(((v6439 ^ ((int)((unsigned int)((int)((unsigned int)v6434 >> 2)) >> 1))) | (-(v6439 ^ ((int)((unsigned int)((int)((unsigned int)v6434 >> 2)) >> 1))))) >> 31)) & 1);
      int v6460 = v6459[v6567];
      int v6461 = v6459[v6551];
      int v6568 = v6461 + ((int)((unsigned int)(v6461 - v6460) >> 31));
      v6459[v6551] = v6568;
      int * v6463 = v6426->cache_age;
      int v6464 = v6463[v6552];
      int v6570 = v6464 + ((int)((unsigned int)(v6464 - v6460) >> 31));
      v6463[v6552] = v6570;
      int * v6466 = v6426->cache_age;
      v6466[v6567] = 0;
      v6512 = v6567;
    } else {
      int * v6469 = v6426->cache_age;
      int v6574 = 4 + ((((int)((unsigned int)((int)((unsigned int)v6434 >> 2)) >> 1)) & 3) * 2);
      int v6470 = v6469[v6574];
      int * v6471 = v6426->cache_tags;
      int v6472 = v6471[v6574];
      int v6473 = v6469[v6552];
      int v6474 = v6471[v6552];
      int * v6475 = v6426->cache_dirty;
      int v6577 = (4 + ((((int)((unsigned int)((int)((unsigned int)v6434 >> 2)) >> 1)) & 3) * 2)) + ((((v6470 + ((~(((v6472 ^ -1) | (-(v6472 ^ -1))) >> 31)) & 2)) - (v6473 + ((~(((v6474 ^ -1) | (-(v6474 ^ -1))) >> 31)) & 2))) >> 31) & 1);
      int v6476 = v6475[v6577];
      bool v6578 = !(v6476 == 0);
      if (v6578) {
        int * v6477 = v6426->cache_tags;
        int v6478 = v6477[v6577];
        int * v6479 = v6426->cache_vals;
        int v6581 = ((4 + ((((int)((unsigned int)((int)((unsigned int)v6434 >> 2)) >> 1)) & 3) * 2)) + ((((v6470 + ((~(((v6472 ^ -1) | (-(v6472 ^ -1))) >> 31)) & 2)) - (v6473 + ((~(((v6474 ^ -1) | (-(v6474 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
        int v6480 = v6479[v6581];
        int v6582 = (((4 + ((((int)((unsigned int)((int)((unsigned int)v6434 >> 2)) >> 1)) & 3) * 2)) + ((((v6470 + ((~(((v6472 ^ -1) | (-(v6472 ^ -1))) >> 31)) & 2)) - (v6473 + ((~(((v6474 ^ -1) | (-(v6474 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
        int v6481 = v6479[v6582];
        int * v6482 = v6426->mem;
        int v6584 = v6478 * 2;
        v6482[v6584] = v6480;
        int * v6484 = v6426->mem;
        int v6587 = (v6478 * 2) + 1;
        v6484[v6587] = v6481;
        ;
      } else {
        ;
      }
      int * v6489 = v6426->mem;
      int v6592 = ((int)((unsigned int)((int)((unsigned int)v6434 >> 2)) >> 1)) * 2;
      int v6490 = v6489[v6592];
      int v6593 = (((int)((unsigned int)((int)((unsigned int)v6434 >> 2)) >> 1)) * 2) + 1;
      int v6491 = v6489[v6593];
      int * v6492 = v6426->cache_vals;
      int v6595 = ((4 + ((((int)((unsigned int)((int)((unsigned int)v6434 >> 2)) >> 1)) & 3) * 2)) + ((((v6470 + ((~(((v6472 ^ -1) | (-(v6472 ^ -1))) >> 31)) & 2)) - (v6473 + ((~(((v6474 ^ -1) | (-(v6474 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
      v6492[v6595] = v6490;
      int * v6494 = v6426->cache_vals;
      int v6598 = (((4 + ((((int)((unsigned int)((int)((unsigned int)v6434 >> 2)) >> 1)) & 3) * 2)) + ((((v6470 + ((~(((v6472 ^ -1) | (-(v6472 ^ -1))) >> 31)) & 2)) - (v6473 + ((~(((v6474 ^ -1) | (-(v6474 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
      v6494[v6598] = v6491;
      int * v6496 = v6426->cache_tags;
      int v6601 = (int)((unsigned int)((int)((unsigned int)v6434 >> 2)) >> 1);
      v6496[v6577] = v6601;
      int * v6498 = v6426->cache_dirty;
      v6498[v6577] = 0;
      int * v6500 = v6426->cache_age;
      v6500[v6577] = 1;
      int * v6502 = v6426->cache_age;
      int v6503 = v6502[v6577];
      int v6504 = v6502[v6551];
      int v6607 = v6504 + ((int)((unsigned int)(v6504 - v6503) >> 31));
      v6502[v6551] = v6607;
      int * v6506 = v6426->cache_age;
      int v6507 = v6506[v6552];
      int v6609 = v6507 + ((int)((unsigned int)(v6507 - v6503) >> 31));
      v6506[v6552] = v6609;
      int * v6509 = v6426->cache_age;
      v6509[v6577] = 0;
      v6512 = v6577;
    }
    int * v6513 = v6426->cache_vals;
    int v6612 = v6512 * 2;
    int v6514 = v6513[v6612];
    int v6613 = (v6512 * 2) + 1;
    int v6515 = v6513[v6613];
    int v6614 = (((((int)((unsigned int)((int)((unsigned int)v6434 >> 2)) >> 1)) & 1) * 2) + ((((v6454 + ((~(((v6456 ^ -1) | (-(v6456 ^ -1))) >> 31)) & 2)) - (v6457 + ((~(((v6458 ^ -1) | (-(v6458 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
    v6513[v6614] = v6514;
    int * v6517 = v6426->cache_vals;
    int v6617 = ((((((int)((unsigned int)((int)((unsigned int)v6434 >> 2)) >> 1)) & 1) * 2) + ((((v6454 + ((~(((v6456 ^ -1) | (-(v6456 ^ -1))) >> 31)) & 2)) - (v6457 + ((~(((v6458 ^ -1) | (-(v6458 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
    v6517[v6617] = v6515;
    int * v6519 = v6426->cache_tags;
    int v6620 = ((((int)((unsigned int)((int)((unsigned int)v6434 >> 2)) >> 1)) & 1) * 2) + ((((v6454 + ((~(((v6456 ^ -1) | (-(v6456 ^ -1))) >> 31)) & 2)) - (v6457 + ((~(((v6458 ^ -1) | (-(v6458 ^ -1))) >> 31)) & 2))) >> 31) & 1);
    int v6621 = (int)((unsigned int)((int)((unsigned int)v6434 >> 2)) >> 1);
    v6519[v6620] = v6621;
    int * v6521 = v6426->cache_dirty;
    v6521[v6620] = 0;
    int * v6523 = v6426->cache_age;
    v6523[v6620] = 1;
    int * v6525 = v6426->cache_age;
    int v6526 = v6525[v6620];
    int v6527 = v6525[v6549];
    int v6627 = v6527 + ((int)((unsigned int)(v6527 - v6526) >> 31));
    v6525[v6549] = v6627;
    int * v6529 = v6426->cache_age;
    int v6530 = v6529[v6550];
    int v6629 = v6530 + ((int)((unsigned int)(v6530 - v6526) >> 31));
    v6529[v6550] = v6629;
    int * v6532 = v6426->cache_age;
    v6532[v6620] = 0;
    v6535 = v6620;
  }
  int v6632 = (v6535 * 2) + (((int)((unsigned int)v6434 >> 2)) & 1);
  int v6536 = v6442[v6632];
  int * v6537 = v6426->regs;
  v6537[7] = v6536;
  struct StateT * v6539 = slot_72(v6426);
  return v6539;
}

struct StateT * slot_51(struct StateT * v3945) {
  int v3946 = v3945->timer;
  int v4116 = v3946 + 1;
  v3945->timer = v4116;
  int * v3948 = v3945->regs;
  int v3949 = v3948[16];
  int v3950 = v3948[7];
  int * v3951 = v3945->cache_tags;
  int v4121 = (((int)((unsigned int)((int)((unsigned int)v3949 >> 2)) >> 1)) & 1) * 2;
  int v3952 = v3951[v4121];
  int v4122 = ((((int)((unsigned int)((int)((unsigned int)v3949 >> 2)) >> 1)) & 1) * 2) + 1;
  int v3953 = v3951[v4122];
  int v4123 = 4 + ((((int)((unsigned int)((int)((unsigned int)v3949 >> 2)) >> 1)) & 3) * 2);
  int v3954 = v3951[v4123];
  int v4124 = (4 + ((((int)((unsigned int)((int)((unsigned int)v3949 >> 2)) >> 1)) & 3) * 2)) + 1;
  int v3955 = v3951[v4124];
  int v3956 = v3945->timer;
  int v4125 = v3956 + ((100 ^ (((~(((v3954 ^ ((int)((unsigned int)((int)((unsigned int)v3949 >> 2)) >> 1))) | (-(v3954 ^ ((int)((unsigned int)((int)((unsigned int)v3949 >> 2)) >> 1))))) >> 31)) | (~(((v3955 ^ ((int)((unsigned int)((int)((unsigned int)v3949 >> 2)) >> 1))) | (-(v3955 ^ ((int)((unsigned int)((int)((unsigned int)v3949 >> 2)) >> 1))))) >> 31))) & 104)) ^ (((~(((v3952 ^ ((int)((unsigned int)((int)((unsigned int)v3949 >> 2)) >> 1))) | (-(v3952 ^ ((int)((unsigned int)((int)((unsigned int)v3949 >> 2)) >> 1))))) >> 31)) | (~(((v3953 ^ ((int)((unsigned int)((int)((unsigned int)v3949 >> 2)) >> 1))) | (-(v3953 ^ ((int)((unsigned int)((int)((unsigned int)v3949 >> 2)) >> 1))))) >> 31))) & (1 ^ (100 ^ (((~(((v3954 ^ ((int)((unsigned int)((int)((unsigned int)v3949 >> 2)) >> 1))) | (-(v3954 ^ ((int)((unsigned int)((int)((unsigned int)v3949 >> 2)) >> 1))))) >> 31)) | (~(((v3955 ^ ((int)((unsigned int)((int)((unsigned int)v3949 >> 2)) >> 1))) | (-(v3955 ^ ((int)((unsigned int)((int)((unsigned int)v3949 >> 2)) >> 1))))) >> 31))) & 104)))));
  v3945->timer = v4125;
  bool v4126 = !(((~(((v3952 ^ ((int)((unsigned int)((int)((unsigned int)v3949 >> 2)) >> 1))) | (-(v3952 ^ ((int)((unsigned int)((int)((unsigned int)v3949 >> 2)) >> 1))))) >> 31)) | (~(((v3953 ^ ((int)((unsigned int)((int)((unsigned int)v3949 >> 2)) >> 1))) | (-(v3953 ^ ((int)((unsigned int)((int)((unsigned int)v3949 >> 2)) >> 1))))) >> 31))) == 0);
  int v4050;
  if (v4126) {
    int * v3958 = v3945->cache_age;
    int v4128 = ((((int)((unsigned int)((int)((unsigned int)v3949 >> 2)) >> 1)) & 1) * 2) + ((~(((v3953 ^ ((int)((unsigned int)((int)((unsigned int)v3949 >> 2)) >> 1))) | (-(v3953 ^ ((int)((unsigned int)((int)((unsigned int)v3949 >> 2)) >> 1))))) >> 31)) & 1);
    int v3959 = v3958[v4128];
    int v3960 = v3958[v4121];
    int v4129 = v3960 + ((int)((unsigned int)(v3960 - v3959) >> 31));
    v3958[v4121] = v4129;
    int * v3962 = v3945->cache_age;
    int v3963 = v3962[v4122];
    int v4131 = v3963 + ((int)((unsigned int)(v3963 - v3959) >> 31));
    v3962[v4122] = v4131;
    int * v3965 = v3945->cache_age;
    v3965[v4128] = 0;
    v4050 = v4128;
  } else {
    int * v3968 = v3945->cache_age;
    int v4135 = (((int)((unsigned int)((int)((unsigned int)v3949 >> 2)) >> 1)) & 1) * 2;
    int v3969 = v3968[v4135];
    int * v3970 = v3945->cache_tags;
    int v3971 = v3970[v4135];
    int v3972 = v3968[v4122];
    int v3973 = v3970[v4122];
    bool v4137 = !(((~(((v3954 ^ ((int)((unsigned int)((int)((unsigned int)v3949 >> 2)) >> 1))) | (-(v3954 ^ ((int)((unsigned int)((int)((unsigned int)v3949 >> 2)) >> 1))))) >> 31)) | (~(((v3955 ^ ((int)((unsigned int)((int)((unsigned int)v3949 >> 2)) >> 1))) | (-(v3955 ^ ((int)((unsigned int)((int)((unsigned int)v3949 >> 2)) >> 1))))) >> 31))) == 0);
    int v4027;
    if (v4137) {
      int * v3974 = v3945->cache_age;
      int v4139 = (4 + ((((int)((unsigned int)((int)((unsigned int)v3949 >> 2)) >> 1)) & 3) * 2)) + ((~(((v3955 ^ ((int)((unsigned int)((int)((unsigned int)v3949 >> 2)) >> 1))) | (-(v3955 ^ ((int)((unsigned int)((int)((unsigned int)v3949 >> 2)) >> 1))))) >> 31)) & 1);
      int v3975 = v3974[v4139];
      int v3976 = v3974[v4123];
      int v4140 = v3976 + ((int)((unsigned int)(v3976 - v3975) >> 31));
      v3974[v4123] = v4140;
      int * v3978 = v3945->cache_age;
      int v3979 = v3978[v4124];
      int v4142 = v3979 + ((int)((unsigned int)(v3979 - v3975) >> 31));
      v3978[v4124] = v4142;
      int * v3981 = v3945->cache_age;
      v3981[v4139] = 0;
      v4027 = v4139;
    } else {
      int * v3984 = v3945->cache_age;
      int v4146 = 4 + ((((int)((unsigned int)((int)((unsigned int)v3949 >> 2)) >> 1)) & 3) * 2);
      int v3985 = v3984[v4146];
      int * v3986 = v3945->cache_tags;
      int v3987 = v3986[v4146];
      int v3988 = v3984[v4124];
      int v3989 = v3986[v4124];
      int * v3990 = v3945->cache_dirty;
      int v4149 = (4 + ((((int)((unsigned int)((int)((unsigned int)v3949 >> 2)) >> 1)) & 3) * 2)) + ((((v3985 + ((~(((v3987 ^ -1) | (-(v3987 ^ -1))) >> 31)) & 2)) - (v3988 + ((~(((v3989 ^ -1) | (-(v3989 ^ -1))) >> 31)) & 2))) >> 31) & 1);
      int v3991 = v3990[v4149];
      bool v4150 = !(v3991 == 0);
      if (v4150) {
        int * v3992 = v3945->cache_tags;
        int v3993 = v3992[v4149];
        int * v3994 = v3945->cache_vals;
        int v4153 = ((4 + ((((int)((unsigned int)((int)((unsigned int)v3949 >> 2)) >> 1)) & 3) * 2)) + ((((v3985 + ((~(((v3987 ^ -1) | (-(v3987 ^ -1))) >> 31)) & 2)) - (v3988 + ((~(((v3989 ^ -1) | (-(v3989 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
        int v3995 = v3994[v4153];
        int v4154 = (((4 + ((((int)((unsigned int)((int)((unsigned int)v3949 >> 2)) >> 1)) & 3) * 2)) + ((((v3985 + ((~(((v3987 ^ -1) | (-(v3987 ^ -1))) >> 31)) & 2)) - (v3988 + ((~(((v3989 ^ -1) | (-(v3989 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
        int v3996 = v3994[v4154];
        int * v3997 = v3945->mem;
        int v4156 = v3993 * 2;
        v3997[v4156] = v3995;
        int * v3999 = v3945->mem;
        int v4159 = (v3993 * 2) + 1;
        v3999[v4159] = v3996;
        ;
      } else {
        ;
      }
      int * v4004 = v3945->mem;
      int v4164 = ((int)((unsigned int)((int)((unsigned int)v3949 >> 2)) >> 1)) * 2;
      int v4005 = v4004[v4164];
      int v4165 = (((int)((unsigned int)((int)((unsigned int)v3949 >> 2)) >> 1)) * 2) + 1;
      int v4006 = v4004[v4165];
      int * v4007 = v3945->cache_vals;
      int v4167 = ((4 + ((((int)((unsigned int)((int)((unsigned int)v3949 >> 2)) >> 1)) & 3) * 2)) + ((((v3985 + ((~(((v3987 ^ -1) | (-(v3987 ^ -1))) >> 31)) & 2)) - (v3988 + ((~(((v3989 ^ -1) | (-(v3989 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
      v4007[v4167] = v4005;
      int * v4009 = v3945->cache_vals;
      int v4170 = (((4 + ((((int)((unsigned int)((int)((unsigned int)v3949 >> 2)) >> 1)) & 3) * 2)) + ((((v3985 + ((~(((v3987 ^ -1) | (-(v3987 ^ -1))) >> 31)) & 2)) - (v3988 + ((~(((v3989 ^ -1) | (-(v3989 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
      v4009[v4170] = v4006;
      int * v4011 = v3945->cache_tags;
      int v4173 = (int)((unsigned int)((int)((unsigned int)v3949 >> 2)) >> 1);
      v4011[v4149] = v4173;
      int * v4013 = v3945->cache_dirty;
      v4013[v4149] = 0;
      int * v4015 = v3945->cache_age;
      v4015[v4149] = 1;
      int * v4017 = v3945->cache_age;
      int v4018 = v4017[v4149];
      int v4019 = v4017[v4123];
      int v4179 = v4019 + ((int)((unsigned int)(v4019 - v4018) >> 31));
      v4017[v4123] = v4179;
      int * v4021 = v3945->cache_age;
      int v4022 = v4021[v4124];
      int v4181 = v4022 + ((int)((unsigned int)(v4022 - v4018) >> 31));
      v4021[v4124] = v4181;
      int * v4024 = v3945->cache_age;
      v4024[v4149] = 0;
      v4027 = v4149;
    }
    int * v4028 = v3945->cache_vals;
    int v4184 = v4027 * 2;
    int v4029 = v4028[v4184];
    int v4185 = (v4027 * 2) + 1;
    int v4030 = v4028[v4185];
    int v4186 = (((((int)((unsigned int)((int)((unsigned int)v3949 >> 2)) >> 1)) & 1) * 2) + ((((v3969 + ((~(((v3971 ^ -1) | (-(v3971 ^ -1))) >> 31)) & 2)) - (v3972 + ((~(((v3973 ^ -1) | (-(v3973 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
    v4028[v4186] = v4029;
    int * v4032 = v3945->cache_vals;
    int v4189 = ((((((int)((unsigned int)((int)((unsigned int)v3949 >> 2)) >> 1)) & 1) * 2) + ((((v3969 + ((~(((v3971 ^ -1) | (-(v3971 ^ -1))) >> 31)) & 2)) - (v3972 + ((~(((v3973 ^ -1) | (-(v3973 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
    v4032[v4189] = v4030;
    int * v4034 = v3945->cache_tags;
    int v4192 = ((((int)((unsigned int)((int)((unsigned int)v3949 >> 2)) >> 1)) & 1) * 2) + ((((v3969 + ((~(((v3971 ^ -1) | (-(v3971 ^ -1))) >> 31)) & 2)) - (v3972 + ((~(((v3973 ^ -1) | (-(v3973 ^ -1))) >> 31)) & 2))) >> 31) & 1);
    int v4193 = (int)((unsigned int)((int)((unsigned int)v3949 >> 2)) >> 1);
    v4034[v4192] = v4193;
    int * v4036 = v3945->cache_dirty;
    v4036[v4192] = 0;
    int * v4038 = v3945->cache_age;
    v4038[v4192] = 1;
    int * v4040 = v3945->cache_age;
    int v4041 = v4040[v4192];
    int v4042 = v4040[v4121];
    int v4199 = v4042 + ((int)((unsigned int)(v4042 - v4041) >> 31));
    v4040[v4121] = v4199;
    int * v4044 = v3945->cache_age;
    int v4045 = v4044[v4122];
    int v4201 = v4045 + ((int)((unsigned int)(v4045 - v4041) >> 31));
    v4044[v4122] = v4201;
    int * v4047 = v3945->cache_age;
    v4047[v4192] = 0;
    v4050 = v4192;
  }
  int * v4051 = v3945->cache_vals;
  int v4204 = (v4050 * 2) + (((int)((unsigned int)v3949 >> 2)) & 1);
  v4051[v4204] = v3950;
  int * v4053 = v3945->cache_tags;
  int v4054 = v4053[v4123];
  int v4055 = v4053[v4124];
  bool v4207 = !(((~(((v4054 ^ ((int)((unsigned int)((int)((unsigned int)v3949 >> 2)) >> 1))) | (-(v4054 ^ ((int)((unsigned int)((int)((unsigned int)v3949 >> 2)) >> 1))))) >> 31)) | (~(((v4055 ^ ((int)((unsigned int)((int)((unsigned int)v3949 >> 2)) >> 1))) | (-(v4055 ^ ((int)((unsigned int)((int)((unsigned int)v3949 >> 2)) >> 1))))) >> 31))) == 0);
  int v4109;
  if (v4207) {
    int * v4056 = v3945->cache_age;
    int v4209 = (4 + ((((int)((unsigned int)((int)((unsigned int)v3949 >> 2)) >> 1)) & 3) * 2)) + ((~(((v4055 ^ ((int)((unsigned int)((int)((unsigned int)v3949 >> 2)) >> 1))) | (-(v4055 ^ ((int)((unsigned int)((int)((unsigned int)v3949 >> 2)) >> 1))))) >> 31)) & 1);
    int v4057 = v4056[v4209];
    int v4058 = v4056[v4123];
    int v4210 = v4058 + ((int)((unsigned int)(v4058 - v4057) >> 31));
    v4056[v4123] = v4210;
    int * v4060 = v3945->cache_age;
    int v4061 = v4060[v4124];
    int v4212 = v4061 + ((int)((unsigned int)(v4061 - v4057) >> 31));
    v4060[v4124] = v4212;
    int * v4063 = v3945->cache_age;
    v4063[v4209] = 0;
    v4109 = v4209;
  } else {
    int * v4066 = v3945->cache_age;
    int v4216 = 4 + ((((int)((unsigned int)((int)((unsigned int)v3949 >> 2)) >> 1)) & 3) * 2);
    int v4067 = v4066[v4216];
    int * v4068 = v3945->cache_tags;
    int v4069 = v4068[v4216];
    int v4070 = v4066[v4124];
    int v4071 = v4068[v4124];
    int * v4072 = v3945->cache_dirty;
    int v4219 = (4 + ((((int)((unsigned int)((int)((unsigned int)v3949 >> 2)) >> 1)) & 3) * 2)) + ((((v4067 + ((~(((v4069 ^ -1) | (-(v4069 ^ -1))) >> 31)) & 2)) - (v4070 + ((~(((v4071 ^ -1) | (-(v4071 ^ -1))) >> 31)) & 2))) >> 31) & 1);
    int v4073 = v4072[v4219];
    bool v4220 = !(v4073 == 0);
    if (v4220) {
      int * v4074 = v3945->cache_tags;
      int v4075 = v4074[v4219];
      int * v4076 = v3945->cache_vals;
      int v4223 = ((4 + ((((int)((unsigned int)((int)((unsigned int)v3949 >> 2)) >> 1)) & 3) * 2)) + ((((v4067 + ((~(((v4069 ^ -1) | (-(v4069 ^ -1))) >> 31)) & 2)) - (v4070 + ((~(((v4071 ^ -1) | (-(v4071 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
      int v4077 = v4076[v4223];
      int v4224 = (((4 + ((((int)((unsigned int)((int)((unsigned int)v3949 >> 2)) >> 1)) & 3) * 2)) + ((((v4067 + ((~(((v4069 ^ -1) | (-(v4069 ^ -1))) >> 31)) & 2)) - (v4070 + ((~(((v4071 ^ -1) | (-(v4071 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
      int v4078 = v4076[v4224];
      int * v4079 = v3945->mem;
      int v4226 = v4075 * 2;
      v4079[v4226] = v4077;
      int * v4081 = v3945->mem;
      int v4229 = (v4075 * 2) + 1;
      v4081[v4229] = v4078;
      ;
    } else {
      ;
    }
    int * v4086 = v3945->mem;
    int v4234 = ((int)((unsigned int)((int)((unsigned int)v3949 >> 2)) >> 1)) * 2;
    int v4087 = v4086[v4234];
    int v4235 = (((int)((unsigned int)((int)((unsigned int)v3949 >> 2)) >> 1)) * 2) + 1;
    int v4088 = v4086[v4235];
    int * v4089 = v3945->cache_vals;
    int v4237 = ((4 + ((((int)((unsigned int)((int)((unsigned int)v3949 >> 2)) >> 1)) & 3) * 2)) + ((((v4067 + ((~(((v4069 ^ -1) | (-(v4069 ^ -1))) >> 31)) & 2)) - (v4070 + ((~(((v4071 ^ -1) | (-(v4071 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
    v4089[v4237] = v4087;
    int * v4091 = v3945->cache_vals;
    int v4240 = (((4 + ((((int)((unsigned int)((int)((unsigned int)v3949 >> 2)) >> 1)) & 3) * 2)) + ((((v4067 + ((~(((v4069 ^ -1) | (-(v4069 ^ -1))) >> 31)) & 2)) - (v4070 + ((~(((v4071 ^ -1) | (-(v4071 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
    v4091[v4240] = v4088;
    int * v4093 = v3945->cache_tags;
    int v4243 = (int)((unsigned int)((int)((unsigned int)v3949 >> 2)) >> 1);
    v4093[v4219] = v4243;
    int * v4095 = v3945->cache_dirty;
    v4095[v4219] = 0;
    int * v4097 = v3945->cache_age;
    v4097[v4219] = 1;
    int * v4099 = v3945->cache_age;
    int v4100 = v4099[v4219];
    int v4101 = v4099[v4123];
    int v4249 = v4101 + ((int)((unsigned int)(v4101 - v4100) >> 31));
    v4099[v4123] = v4249;
    int * v4103 = v3945->cache_age;
    int v4104 = v4103[v4124];
    int v4251 = v4104 + ((int)((unsigned int)(v4104 - v4100) >> 31));
    v4103[v4124] = v4251;
    int * v4106 = v3945->cache_age;
    v4106[v4219] = 0;
    v4109 = v4219;
  }
  int * v4110 = v3945->cache_vals;
  int v4254 = (v4109 * 2) + (((int)((unsigned int)v3949 >> 2)) & 1);
  v4110[v4254] = v3950;
  int * v4112 = v3945->cache_dirty;
  v4112[v4109] = 1;
  struct StateT * v4114 = slot_52(v3945);
  return v4114;
}

struct StateT * slot_52(struct StateT * v4260) {
  int v4261 = v4260->timer;
  int v4431 = v4261 + 1;
  v4260->timer = v4431;
  int * v4263 = v4260->regs;
  int v4264 = v4263[16];
  int v4265 = v4263[6];
  int * v4266 = v4260->cache_tags;
  int v4436 = (((int)((unsigned int)((int)((unsigned int)(v4264 + 4) >> 2)) >> 1)) & 1) * 2;
  int v4267 = v4266[v4436];
  int v4437 = ((((int)((unsigned int)((int)((unsigned int)(v4264 + 4) >> 2)) >> 1)) & 1) * 2) + 1;
  int v4268 = v4266[v4437];
  int v4438 = 4 + ((((int)((unsigned int)((int)((unsigned int)(v4264 + 4) >> 2)) >> 1)) & 3) * 2);
  int v4269 = v4266[v4438];
  int v4439 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v4264 + 4) >> 2)) >> 1)) & 3) * 2)) + 1;
  int v4270 = v4266[v4439];
  int v4271 = v4260->timer;
  int v4440 = v4271 + ((100 ^ (((~(((v4269 ^ ((int)((unsigned int)((int)((unsigned int)(v4264 + 4) >> 2)) >> 1))) | (-(v4269 ^ ((int)((unsigned int)((int)((unsigned int)(v4264 + 4) >> 2)) >> 1))))) >> 31)) | (~(((v4270 ^ ((int)((unsigned int)((int)((unsigned int)(v4264 + 4) >> 2)) >> 1))) | (-(v4270 ^ ((int)((unsigned int)((int)((unsigned int)(v4264 + 4) >> 2)) >> 1))))) >> 31))) & 104)) ^ (((~(((v4267 ^ ((int)((unsigned int)((int)((unsigned int)(v4264 + 4) >> 2)) >> 1))) | (-(v4267 ^ ((int)((unsigned int)((int)((unsigned int)(v4264 + 4) >> 2)) >> 1))))) >> 31)) | (~(((v4268 ^ ((int)((unsigned int)((int)((unsigned int)(v4264 + 4) >> 2)) >> 1))) | (-(v4268 ^ ((int)((unsigned int)((int)((unsigned int)(v4264 + 4) >> 2)) >> 1))))) >> 31))) & (1 ^ (100 ^ (((~(((v4269 ^ ((int)((unsigned int)((int)((unsigned int)(v4264 + 4) >> 2)) >> 1))) | (-(v4269 ^ ((int)((unsigned int)((int)((unsigned int)(v4264 + 4) >> 2)) >> 1))))) >> 31)) | (~(((v4270 ^ ((int)((unsigned int)((int)((unsigned int)(v4264 + 4) >> 2)) >> 1))) | (-(v4270 ^ ((int)((unsigned int)((int)((unsigned int)(v4264 + 4) >> 2)) >> 1))))) >> 31))) & 104)))));
  v4260->timer = v4440;
  bool v4441 = !(((~(((v4267 ^ ((int)((unsigned int)((int)((unsigned int)(v4264 + 4) >> 2)) >> 1))) | (-(v4267 ^ ((int)((unsigned int)((int)((unsigned int)(v4264 + 4) >> 2)) >> 1))))) >> 31)) | (~(((v4268 ^ ((int)((unsigned int)((int)((unsigned int)(v4264 + 4) >> 2)) >> 1))) | (-(v4268 ^ ((int)((unsigned int)((int)((unsigned int)(v4264 + 4) >> 2)) >> 1))))) >> 31))) == 0);
  int v4365;
  if (v4441) {
    int * v4273 = v4260->cache_age;
    int v4443 = ((((int)((unsigned int)((int)((unsigned int)(v4264 + 4) >> 2)) >> 1)) & 1) * 2) + ((~(((v4268 ^ ((int)((unsigned int)((int)((unsigned int)(v4264 + 4) >> 2)) >> 1))) | (-(v4268 ^ ((int)((unsigned int)((int)((unsigned int)(v4264 + 4) >> 2)) >> 1))))) >> 31)) & 1);
    int v4274 = v4273[v4443];
    int v4275 = v4273[v4436];
    int v4444 = v4275 + ((int)((unsigned int)(v4275 - v4274) >> 31));
    v4273[v4436] = v4444;
    int * v4277 = v4260->cache_age;
    int v4278 = v4277[v4437];
    int v4446 = v4278 + ((int)((unsigned int)(v4278 - v4274) >> 31));
    v4277[v4437] = v4446;
    int * v4280 = v4260->cache_age;
    v4280[v4443] = 0;
    v4365 = v4443;
  } else {
    int * v4283 = v4260->cache_age;
    int v4450 = (((int)((unsigned int)((int)((unsigned int)(v4264 + 4) >> 2)) >> 1)) & 1) * 2;
    int v4284 = v4283[v4450];
    int * v4285 = v4260->cache_tags;
    int v4286 = v4285[v4450];
    int v4287 = v4283[v4437];
    int v4288 = v4285[v4437];
    bool v4452 = !(((~(((v4269 ^ ((int)((unsigned int)((int)((unsigned int)(v4264 + 4) >> 2)) >> 1))) | (-(v4269 ^ ((int)((unsigned int)((int)((unsigned int)(v4264 + 4) >> 2)) >> 1))))) >> 31)) | (~(((v4270 ^ ((int)((unsigned int)((int)((unsigned int)(v4264 + 4) >> 2)) >> 1))) | (-(v4270 ^ ((int)((unsigned int)((int)((unsigned int)(v4264 + 4) >> 2)) >> 1))))) >> 31))) == 0);
    int v4342;
    if (v4452) {
      int * v4289 = v4260->cache_age;
      int v4454 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v4264 + 4) >> 2)) >> 1)) & 3) * 2)) + ((~(((v4270 ^ ((int)((unsigned int)((int)((unsigned int)(v4264 + 4) >> 2)) >> 1))) | (-(v4270 ^ ((int)((unsigned int)((int)((unsigned int)(v4264 + 4) >> 2)) >> 1))))) >> 31)) & 1);
      int v4290 = v4289[v4454];
      int v4291 = v4289[v4438];
      int v4455 = v4291 + ((int)((unsigned int)(v4291 - v4290) >> 31));
      v4289[v4438] = v4455;
      int * v4293 = v4260->cache_age;
      int v4294 = v4293[v4439];
      int v4457 = v4294 + ((int)((unsigned int)(v4294 - v4290) >> 31));
      v4293[v4439] = v4457;
      int * v4296 = v4260->cache_age;
      v4296[v4454] = 0;
      v4342 = v4454;
    } else {
      int * v4299 = v4260->cache_age;
      int v4461 = 4 + ((((int)((unsigned int)((int)((unsigned int)(v4264 + 4) >> 2)) >> 1)) & 3) * 2);
      int v4300 = v4299[v4461];
      int * v4301 = v4260->cache_tags;
      int v4302 = v4301[v4461];
      int v4303 = v4299[v4439];
      int v4304 = v4301[v4439];
      int * v4305 = v4260->cache_dirty;
      int v4464 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v4264 + 4) >> 2)) >> 1)) & 3) * 2)) + ((((v4300 + ((~(((v4302 ^ -1) | (-(v4302 ^ -1))) >> 31)) & 2)) - (v4303 + ((~(((v4304 ^ -1) | (-(v4304 ^ -1))) >> 31)) & 2))) >> 31) & 1);
      int v4306 = v4305[v4464];
      bool v4465 = !(v4306 == 0);
      if (v4465) {
        int * v4307 = v4260->cache_tags;
        int v4308 = v4307[v4464];
        int * v4309 = v4260->cache_vals;
        int v4468 = ((4 + ((((int)((unsigned int)((int)((unsigned int)(v4264 + 4) >> 2)) >> 1)) & 3) * 2)) + ((((v4300 + ((~(((v4302 ^ -1) | (-(v4302 ^ -1))) >> 31)) & 2)) - (v4303 + ((~(((v4304 ^ -1) | (-(v4304 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
        int v4310 = v4309[v4468];
        int v4469 = (((4 + ((((int)((unsigned int)((int)((unsigned int)(v4264 + 4) >> 2)) >> 1)) & 3) * 2)) + ((((v4300 + ((~(((v4302 ^ -1) | (-(v4302 ^ -1))) >> 31)) & 2)) - (v4303 + ((~(((v4304 ^ -1) | (-(v4304 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
        int v4311 = v4309[v4469];
        int * v4312 = v4260->mem;
        int v4471 = v4308 * 2;
        v4312[v4471] = v4310;
        int * v4314 = v4260->mem;
        int v4474 = (v4308 * 2) + 1;
        v4314[v4474] = v4311;
        ;
      } else {
        ;
      }
      int * v4319 = v4260->mem;
      int v4479 = ((int)((unsigned int)((int)((unsigned int)(v4264 + 4) >> 2)) >> 1)) * 2;
      int v4320 = v4319[v4479];
      int v4480 = (((int)((unsigned int)((int)((unsigned int)(v4264 + 4) >> 2)) >> 1)) * 2) + 1;
      int v4321 = v4319[v4480];
      int * v4322 = v4260->cache_vals;
      int v4482 = ((4 + ((((int)((unsigned int)((int)((unsigned int)(v4264 + 4) >> 2)) >> 1)) & 3) * 2)) + ((((v4300 + ((~(((v4302 ^ -1) | (-(v4302 ^ -1))) >> 31)) & 2)) - (v4303 + ((~(((v4304 ^ -1) | (-(v4304 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
      v4322[v4482] = v4320;
      int * v4324 = v4260->cache_vals;
      int v4485 = (((4 + ((((int)((unsigned int)((int)((unsigned int)(v4264 + 4) >> 2)) >> 1)) & 3) * 2)) + ((((v4300 + ((~(((v4302 ^ -1) | (-(v4302 ^ -1))) >> 31)) & 2)) - (v4303 + ((~(((v4304 ^ -1) | (-(v4304 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
      v4324[v4485] = v4321;
      int * v4326 = v4260->cache_tags;
      int v4488 = (int)((unsigned int)((int)((unsigned int)(v4264 + 4) >> 2)) >> 1);
      v4326[v4464] = v4488;
      int * v4328 = v4260->cache_dirty;
      v4328[v4464] = 0;
      int * v4330 = v4260->cache_age;
      v4330[v4464] = 1;
      int * v4332 = v4260->cache_age;
      int v4333 = v4332[v4464];
      int v4334 = v4332[v4438];
      int v4494 = v4334 + ((int)((unsigned int)(v4334 - v4333) >> 31));
      v4332[v4438] = v4494;
      int * v4336 = v4260->cache_age;
      int v4337 = v4336[v4439];
      int v4496 = v4337 + ((int)((unsigned int)(v4337 - v4333) >> 31));
      v4336[v4439] = v4496;
      int * v4339 = v4260->cache_age;
      v4339[v4464] = 0;
      v4342 = v4464;
    }
    int * v4343 = v4260->cache_vals;
    int v4499 = v4342 * 2;
    int v4344 = v4343[v4499];
    int v4500 = (v4342 * 2) + 1;
    int v4345 = v4343[v4500];
    int v4501 = (((((int)((unsigned int)((int)((unsigned int)(v4264 + 4) >> 2)) >> 1)) & 1) * 2) + ((((v4284 + ((~(((v4286 ^ -1) | (-(v4286 ^ -1))) >> 31)) & 2)) - (v4287 + ((~(((v4288 ^ -1) | (-(v4288 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
    v4343[v4501] = v4344;
    int * v4347 = v4260->cache_vals;
    int v4504 = ((((((int)((unsigned int)((int)((unsigned int)(v4264 + 4) >> 2)) >> 1)) & 1) * 2) + ((((v4284 + ((~(((v4286 ^ -1) | (-(v4286 ^ -1))) >> 31)) & 2)) - (v4287 + ((~(((v4288 ^ -1) | (-(v4288 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
    v4347[v4504] = v4345;
    int * v4349 = v4260->cache_tags;
    int v4507 = ((((int)((unsigned int)((int)((unsigned int)(v4264 + 4) >> 2)) >> 1)) & 1) * 2) + ((((v4284 + ((~(((v4286 ^ -1) | (-(v4286 ^ -1))) >> 31)) & 2)) - (v4287 + ((~(((v4288 ^ -1) | (-(v4288 ^ -1))) >> 31)) & 2))) >> 31) & 1);
    int v4508 = (int)((unsigned int)((int)((unsigned int)(v4264 + 4) >> 2)) >> 1);
    v4349[v4507] = v4508;
    int * v4351 = v4260->cache_dirty;
    v4351[v4507] = 0;
    int * v4353 = v4260->cache_age;
    v4353[v4507] = 1;
    int * v4355 = v4260->cache_age;
    int v4356 = v4355[v4507];
    int v4357 = v4355[v4436];
    int v4514 = v4357 + ((int)((unsigned int)(v4357 - v4356) >> 31));
    v4355[v4436] = v4514;
    int * v4359 = v4260->cache_age;
    int v4360 = v4359[v4437];
    int v4516 = v4360 + ((int)((unsigned int)(v4360 - v4356) >> 31));
    v4359[v4437] = v4516;
    int * v4362 = v4260->cache_age;
    v4362[v4507] = 0;
    v4365 = v4507;
  }
  int * v4366 = v4260->cache_vals;
  int v4519 = (v4365 * 2) + (((int)((unsigned int)(v4264 + 4) >> 2)) & 1);
  v4366[v4519] = v4265;
  int * v4368 = v4260->cache_tags;
  int v4369 = v4368[v4438];
  int v4370 = v4368[v4439];
  bool v4522 = !(((~(((v4369 ^ ((int)((unsigned int)((int)((unsigned int)(v4264 + 4) >> 2)) >> 1))) | (-(v4369 ^ ((int)((unsigned int)((int)((unsigned int)(v4264 + 4) >> 2)) >> 1))))) >> 31)) | (~(((v4370 ^ ((int)((unsigned int)((int)((unsigned int)(v4264 + 4) >> 2)) >> 1))) | (-(v4370 ^ ((int)((unsigned int)((int)((unsigned int)(v4264 + 4) >> 2)) >> 1))))) >> 31))) == 0);
  int v4424;
  if (v4522) {
    int * v4371 = v4260->cache_age;
    int v4524 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v4264 + 4) >> 2)) >> 1)) & 3) * 2)) + ((~(((v4370 ^ ((int)((unsigned int)((int)((unsigned int)(v4264 + 4) >> 2)) >> 1))) | (-(v4370 ^ ((int)((unsigned int)((int)((unsigned int)(v4264 + 4) >> 2)) >> 1))))) >> 31)) & 1);
    int v4372 = v4371[v4524];
    int v4373 = v4371[v4438];
    int v4525 = v4373 + ((int)((unsigned int)(v4373 - v4372) >> 31));
    v4371[v4438] = v4525;
    int * v4375 = v4260->cache_age;
    int v4376 = v4375[v4439];
    int v4527 = v4376 + ((int)((unsigned int)(v4376 - v4372) >> 31));
    v4375[v4439] = v4527;
    int * v4378 = v4260->cache_age;
    v4378[v4524] = 0;
    v4424 = v4524;
  } else {
    int * v4381 = v4260->cache_age;
    int v4531 = 4 + ((((int)((unsigned int)((int)((unsigned int)(v4264 + 4) >> 2)) >> 1)) & 3) * 2);
    int v4382 = v4381[v4531];
    int * v4383 = v4260->cache_tags;
    int v4384 = v4383[v4531];
    int v4385 = v4381[v4439];
    int v4386 = v4383[v4439];
    int * v4387 = v4260->cache_dirty;
    int v4534 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v4264 + 4) >> 2)) >> 1)) & 3) * 2)) + ((((v4382 + ((~(((v4384 ^ -1) | (-(v4384 ^ -1))) >> 31)) & 2)) - (v4385 + ((~(((v4386 ^ -1) | (-(v4386 ^ -1))) >> 31)) & 2))) >> 31) & 1);
    int v4388 = v4387[v4534];
    bool v4535 = !(v4388 == 0);
    if (v4535) {
      int * v4389 = v4260->cache_tags;
      int v4390 = v4389[v4534];
      int * v4391 = v4260->cache_vals;
      int v4538 = ((4 + ((((int)((unsigned int)((int)((unsigned int)(v4264 + 4) >> 2)) >> 1)) & 3) * 2)) + ((((v4382 + ((~(((v4384 ^ -1) | (-(v4384 ^ -1))) >> 31)) & 2)) - (v4385 + ((~(((v4386 ^ -1) | (-(v4386 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
      int v4392 = v4391[v4538];
      int v4539 = (((4 + ((((int)((unsigned int)((int)((unsigned int)(v4264 + 4) >> 2)) >> 1)) & 3) * 2)) + ((((v4382 + ((~(((v4384 ^ -1) | (-(v4384 ^ -1))) >> 31)) & 2)) - (v4385 + ((~(((v4386 ^ -1) | (-(v4386 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
      int v4393 = v4391[v4539];
      int * v4394 = v4260->mem;
      int v4541 = v4390 * 2;
      v4394[v4541] = v4392;
      int * v4396 = v4260->mem;
      int v4544 = (v4390 * 2) + 1;
      v4396[v4544] = v4393;
      ;
    } else {
      ;
    }
    int * v4401 = v4260->mem;
    int v4549 = ((int)((unsigned int)((int)((unsigned int)(v4264 + 4) >> 2)) >> 1)) * 2;
    int v4402 = v4401[v4549];
    int v4550 = (((int)((unsigned int)((int)((unsigned int)(v4264 + 4) >> 2)) >> 1)) * 2) + 1;
    int v4403 = v4401[v4550];
    int * v4404 = v4260->cache_vals;
    int v4552 = ((4 + ((((int)((unsigned int)((int)((unsigned int)(v4264 + 4) >> 2)) >> 1)) & 3) * 2)) + ((((v4382 + ((~(((v4384 ^ -1) | (-(v4384 ^ -1))) >> 31)) & 2)) - (v4385 + ((~(((v4386 ^ -1) | (-(v4386 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
    v4404[v4552] = v4402;
    int * v4406 = v4260->cache_vals;
    int v4555 = (((4 + ((((int)((unsigned int)((int)((unsigned int)(v4264 + 4) >> 2)) >> 1)) & 3) * 2)) + ((((v4382 + ((~(((v4384 ^ -1) | (-(v4384 ^ -1))) >> 31)) & 2)) - (v4385 + ((~(((v4386 ^ -1) | (-(v4386 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
    v4406[v4555] = v4403;
    int * v4408 = v4260->cache_tags;
    int v4558 = (int)((unsigned int)((int)((unsigned int)(v4264 + 4) >> 2)) >> 1);
    v4408[v4534] = v4558;
    int * v4410 = v4260->cache_dirty;
    v4410[v4534] = 0;
    int * v4412 = v4260->cache_age;
    v4412[v4534] = 1;
    int * v4414 = v4260->cache_age;
    int v4415 = v4414[v4534];
    int v4416 = v4414[v4438];
    int v4564 = v4416 + ((int)((unsigned int)(v4416 - v4415) >> 31));
    v4414[v4438] = v4564;
    int * v4418 = v4260->cache_age;
    int v4419 = v4418[v4439];
    int v4566 = v4419 + ((int)((unsigned int)(v4419 - v4415) >> 31));
    v4418[v4439] = v4566;
    int * v4421 = v4260->cache_age;
    v4421[v4534] = 0;
    v4424 = v4534;
  }
  int * v4425 = v4260->cache_vals;
  int v4569 = (v4424 * 2) + (((int)((unsigned int)(v4264 + 4) >> 2)) & 1);
  v4425[v4569] = v4265;
  int * v4427 = v4260->cache_dirty;
  v4427[v4424] = 1;
  struct StateT * v4429 = slot_53(v4260);
  return v4429;
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

struct StateT * slot_73(struct StateT * v6653) {
  int v6654 = v6653->timer;
  int v6662 = v6654 + 1;
  v6653->timer = v6662;
  int * v6656 = v6653->regs;
  int v6657 = v6656[7];
  int v6658 = v6656[17];
  int v6666 = v6657 ^ v6658;
  v6656[7] = v6666;
  struct StateT * v6660 = slot_74(v6653);
  return v6660;
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

struct StateT * slot_69(struct StateT * v6004) {
  int * v6005 = v6004->saved_regs;
  int * v6006 = v6004->regs;
  int v6007 = v6006[5];
  v6005[5] = v6007;
  int v6009 = v6004->timer;
  int v6123 = v6009 + 1;
  v6004->timer = v6123;
  int * v6011 = v6004->regs;
  int v6012 = v6011[16];
  int * v6013 = v6004->cache_tags;
  int v6127 = (((int)((unsigned int)((int)((unsigned int)(v6012 + 4) >> 2)) >> 1)) & 1) * 2;
  int v6014 = v6013[v6127];
  int v6128 = ((((int)((unsigned int)((int)((unsigned int)(v6012 + 4) >> 2)) >> 1)) & 1) * 2) + 1;
  int v6015 = v6013[v6128];
  int v6129 = 4 + ((((int)((unsigned int)((int)((unsigned int)(v6012 + 4) >> 2)) >> 1)) & 3) * 2);
  int v6016 = v6013[v6129];
  int v6130 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v6012 + 4) >> 2)) >> 1)) & 3) * 2)) + 1;
  int v6017 = v6013[v6130];
  int v6018 = v6004->timer;
  int v6131 = v6018 + ((100 ^ (((~(((v6016 ^ ((int)((unsigned int)((int)((unsigned int)(v6012 + 4) >> 2)) >> 1))) | (-(v6016 ^ ((int)((unsigned int)((int)((unsigned int)(v6012 + 4) >> 2)) >> 1))))) >> 31)) | (~(((v6017 ^ ((int)((unsigned int)((int)((unsigned int)(v6012 + 4) >> 2)) >> 1))) | (-(v6017 ^ ((int)((unsigned int)((int)((unsigned int)(v6012 + 4) >> 2)) >> 1))))) >> 31))) & 104)) ^ (((~(((v6014 ^ ((int)((unsigned int)((int)((unsigned int)(v6012 + 4) >> 2)) >> 1))) | (-(v6014 ^ ((int)((unsigned int)((int)((unsigned int)(v6012 + 4) >> 2)) >> 1))))) >> 31)) | (~(((v6015 ^ ((int)((unsigned int)((int)((unsigned int)(v6012 + 4) >> 2)) >> 1))) | (-(v6015 ^ ((int)((unsigned int)((int)((unsigned int)(v6012 + 4) >> 2)) >> 1))))) >> 31))) & (1 ^ (100 ^ (((~(((v6016 ^ ((int)((unsigned int)((int)((unsigned int)(v6012 + 4) >> 2)) >> 1))) | (-(v6016 ^ ((int)((unsigned int)((int)((unsigned int)(v6012 + 4) >> 2)) >> 1))))) >> 31)) | (~(((v6017 ^ ((int)((unsigned int)((int)((unsigned int)(v6012 + 4) >> 2)) >> 1))) | (-(v6017 ^ ((int)((unsigned int)((int)((unsigned int)(v6012 + 4) >> 2)) >> 1))))) >> 31))) & 104)))));
  v6004->timer = v6131;
  int * v6020 = v6004->cache_vals;
  bool v6132 = !(((~(((v6014 ^ ((int)((unsigned int)((int)((unsigned int)(v6012 + 4) >> 2)) >> 1))) | (-(v6014 ^ ((int)((unsigned int)((int)((unsigned int)(v6012 + 4) >> 2)) >> 1))))) >> 31)) | (~(((v6015 ^ ((int)((unsigned int)((int)((unsigned int)(v6012 + 4) >> 2)) >> 1))) | (-(v6015 ^ ((int)((unsigned int)((int)((unsigned int)(v6012 + 4) >> 2)) >> 1))))) >> 31))) == 0);
  int v6113;
  if (v6132) {
    int * v6021 = v6004->cache_age;
    int v6134 = ((((int)((unsigned int)((int)((unsigned int)(v6012 + 4) >> 2)) >> 1)) & 1) * 2) + ((~(((v6015 ^ ((int)((unsigned int)((int)((unsigned int)(v6012 + 4) >> 2)) >> 1))) | (-(v6015 ^ ((int)((unsigned int)((int)((unsigned int)(v6012 + 4) >> 2)) >> 1))))) >> 31)) & 1);
    int v6022 = v6021[v6134];
    int v6023 = v6021[v6127];
    int v6135 = v6023 + ((int)((unsigned int)(v6023 - v6022) >> 31));
    v6021[v6127] = v6135;
    int * v6025 = v6004->cache_age;
    int v6026 = v6025[v6128];
    int v6137 = v6026 + ((int)((unsigned int)(v6026 - v6022) >> 31));
    v6025[v6128] = v6137;
    int * v6028 = v6004->cache_age;
    v6028[v6134] = 0;
    v6113 = v6134;
  } else {
    int * v6031 = v6004->cache_age;
    int v6141 = (((int)((unsigned int)((int)((unsigned int)(v6012 + 4) >> 2)) >> 1)) & 1) * 2;
    int v6032 = v6031[v6141];
    int * v6033 = v6004->cache_tags;
    int v6034 = v6033[v6141];
    int v6035 = v6031[v6128];
    int v6036 = v6033[v6128];
    bool v6143 = !(((~(((v6016 ^ ((int)((unsigned int)((int)((unsigned int)(v6012 + 4) >> 2)) >> 1))) | (-(v6016 ^ ((int)((unsigned int)((int)((unsigned int)(v6012 + 4) >> 2)) >> 1))))) >> 31)) | (~(((v6017 ^ ((int)((unsigned int)((int)((unsigned int)(v6012 + 4) >> 2)) >> 1))) | (-(v6017 ^ ((int)((unsigned int)((int)((unsigned int)(v6012 + 4) >> 2)) >> 1))))) >> 31))) == 0);
    int v6090;
    if (v6143) {
      int * v6037 = v6004->cache_age;
      int v6145 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v6012 + 4) >> 2)) >> 1)) & 3) * 2)) + ((~(((v6017 ^ ((int)((unsigned int)((int)((unsigned int)(v6012 + 4) >> 2)) >> 1))) | (-(v6017 ^ ((int)((unsigned int)((int)((unsigned int)(v6012 + 4) >> 2)) >> 1))))) >> 31)) & 1);
      int v6038 = v6037[v6145];
      int v6039 = v6037[v6129];
      int v6146 = v6039 + ((int)((unsigned int)(v6039 - v6038) >> 31));
      v6037[v6129] = v6146;
      int * v6041 = v6004->cache_age;
      int v6042 = v6041[v6130];
      int v6148 = v6042 + ((int)((unsigned int)(v6042 - v6038) >> 31));
      v6041[v6130] = v6148;
      int * v6044 = v6004->cache_age;
      v6044[v6145] = 0;
      v6090 = v6145;
    } else {
      int * v6047 = v6004->cache_age;
      int v6152 = 4 + ((((int)((unsigned int)((int)((unsigned int)(v6012 + 4) >> 2)) >> 1)) & 3) * 2);
      int v6048 = v6047[v6152];
      int * v6049 = v6004->cache_tags;
      int v6050 = v6049[v6152];
      int v6051 = v6047[v6130];
      int v6052 = v6049[v6130];
      int * v6053 = v6004->cache_dirty;
      int v6155 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v6012 + 4) >> 2)) >> 1)) & 3) * 2)) + ((((v6048 + ((~(((v6050 ^ -1) | (-(v6050 ^ -1))) >> 31)) & 2)) - (v6051 + ((~(((v6052 ^ -1) | (-(v6052 ^ -1))) >> 31)) & 2))) >> 31) & 1);
      int v6054 = v6053[v6155];
      bool v6156 = !(v6054 == 0);
      if (v6156) {
        int * v6055 = v6004->cache_tags;
        int v6056 = v6055[v6155];
        int * v6057 = v6004->cache_vals;
        int v6159 = ((4 + ((((int)((unsigned int)((int)((unsigned int)(v6012 + 4) >> 2)) >> 1)) & 3) * 2)) + ((((v6048 + ((~(((v6050 ^ -1) | (-(v6050 ^ -1))) >> 31)) & 2)) - (v6051 + ((~(((v6052 ^ -1) | (-(v6052 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
        int v6058 = v6057[v6159];
        int v6160 = (((4 + ((((int)((unsigned int)((int)((unsigned int)(v6012 + 4) >> 2)) >> 1)) & 3) * 2)) + ((((v6048 + ((~(((v6050 ^ -1) | (-(v6050 ^ -1))) >> 31)) & 2)) - (v6051 + ((~(((v6052 ^ -1) | (-(v6052 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
        int v6059 = v6057[v6160];
        int * v6060 = v6004->mem;
        int v6162 = v6056 * 2;
        v6060[v6162] = v6058;
        int * v6062 = v6004->mem;
        int v6165 = (v6056 * 2) + 1;
        v6062[v6165] = v6059;
        ;
      } else {
        ;
      }
      int * v6067 = v6004->mem;
      int v6170 = ((int)((unsigned int)((int)((unsigned int)(v6012 + 4) >> 2)) >> 1)) * 2;
      int v6068 = v6067[v6170];
      int v6171 = (((int)((unsigned int)((int)((unsigned int)(v6012 + 4) >> 2)) >> 1)) * 2) + 1;
      int v6069 = v6067[v6171];
      int * v6070 = v6004->cache_vals;
      int v6173 = ((4 + ((((int)((unsigned int)((int)((unsigned int)(v6012 + 4) >> 2)) >> 1)) & 3) * 2)) + ((((v6048 + ((~(((v6050 ^ -1) | (-(v6050 ^ -1))) >> 31)) & 2)) - (v6051 + ((~(((v6052 ^ -1) | (-(v6052 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
      v6070[v6173] = v6068;
      int * v6072 = v6004->cache_vals;
      int v6176 = (((4 + ((((int)((unsigned int)((int)((unsigned int)(v6012 + 4) >> 2)) >> 1)) & 3) * 2)) + ((((v6048 + ((~(((v6050 ^ -1) | (-(v6050 ^ -1))) >> 31)) & 2)) - (v6051 + ((~(((v6052 ^ -1) | (-(v6052 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
      v6072[v6176] = v6069;
      int * v6074 = v6004->cache_tags;
      int v6179 = (int)((unsigned int)((int)((unsigned int)(v6012 + 4) >> 2)) >> 1);
      v6074[v6155] = v6179;
      int * v6076 = v6004->cache_dirty;
      v6076[v6155] = 0;
      int * v6078 = v6004->cache_age;
      v6078[v6155] = 1;
      int * v6080 = v6004->cache_age;
      int v6081 = v6080[v6155];
      int v6082 = v6080[v6129];
      int v6185 = v6082 + ((int)((unsigned int)(v6082 - v6081) >> 31));
      v6080[v6129] = v6185;
      int * v6084 = v6004->cache_age;
      int v6085 = v6084[v6130];
      int v6187 = v6085 + ((int)((unsigned int)(v6085 - v6081) >> 31));
      v6084[v6130] = v6187;
      int * v6087 = v6004->cache_age;
      v6087[v6155] = 0;
      v6090 = v6155;
    }
    int * v6091 = v6004->cache_vals;
    int v6190 = v6090 * 2;
    int v6092 = v6091[v6190];
    int v6191 = (v6090 * 2) + 1;
    int v6093 = v6091[v6191];
    int v6192 = (((((int)((unsigned int)((int)((unsigned int)(v6012 + 4) >> 2)) >> 1)) & 1) * 2) + ((((v6032 + ((~(((v6034 ^ -1) | (-(v6034 ^ -1))) >> 31)) & 2)) - (v6035 + ((~(((v6036 ^ -1) | (-(v6036 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
    v6091[v6192] = v6092;
    int * v6095 = v6004->cache_vals;
    int v6195 = ((((((int)((unsigned int)((int)((unsigned int)(v6012 + 4) >> 2)) >> 1)) & 1) * 2) + ((((v6032 + ((~(((v6034 ^ -1) | (-(v6034 ^ -1))) >> 31)) & 2)) - (v6035 + ((~(((v6036 ^ -1) | (-(v6036 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
    v6095[v6195] = v6093;
    int * v6097 = v6004->cache_tags;
    int v6198 = ((((int)((unsigned int)((int)((unsigned int)(v6012 + 4) >> 2)) >> 1)) & 1) * 2) + ((((v6032 + ((~(((v6034 ^ -1) | (-(v6034 ^ -1))) >> 31)) & 2)) - (v6035 + ((~(((v6036 ^ -1) | (-(v6036 ^ -1))) >> 31)) & 2))) >> 31) & 1);
    int v6199 = (int)((unsigned int)((int)((unsigned int)(v6012 + 4) >> 2)) >> 1);
    v6097[v6198] = v6199;
    int * v6099 = v6004->cache_dirty;
    v6099[v6198] = 0;
    int * v6101 = v6004->cache_age;
    v6101[v6198] = 1;
    int * v6103 = v6004->cache_age;
    int v6104 = v6103[v6198];
    int v6105 = v6103[v6127];
    int v6205 = v6105 + ((int)((unsigned int)(v6105 - v6104) >> 31));
    v6103[v6127] = v6205;
    int * v6107 = v6004->cache_age;
    int v6108 = v6107[v6128];
    int v6207 = v6108 + ((int)((unsigned int)(v6108 - v6104) >> 31));
    v6107[v6128] = v6207;
    int * v6110 = v6004->cache_age;
    v6110[v6198] = 0;
    v6113 = v6198;
  }
  int v6210 = (v6113 * 2) + (((int)((unsigned int)(v6012 + 4) >> 2)) & 1);
  int v6114 = v6020[v6210];
  int * v6115 = v6004->regs;
  v6115[5] = v6114;
  struct StateT * v6117 = slot_70(v6004);
  return v6117;
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

struct StateT * slot_63(struct StateT * v5709) {
  int v5710 = v5709->timer;
  int v5717 = v5710 + 1;
  v5709->timer = v5717;
  int * v5712 = v5709->regs;
  int v5713 = v5712[14];
  int v5720 = v5713 + 1;
  v5712[14] = v5720;
  struct StateT * v5715 = slot_64(v5709);
  return v5715;
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

struct StateT * slot_61(struct StateT * v5079) {
  int v5080 = v5079->timer;
  int v5250 = v5080 + 1;
  v5079->timer = v5250;
  int * v5082 = v5079->regs;
  int v5083 = v5082[15];
  int v5084 = v5082[17];
  int * v5085 = v5079->cache_tags;
  int v5255 = (((int)((unsigned int)((int)((unsigned int)v5083 >> 2)) >> 1)) & 1) * 2;
  int v5086 = v5085[v5255];
  int v5256 = ((((int)((unsigned int)((int)((unsigned int)v5083 >> 2)) >> 1)) & 1) * 2) + 1;
  int v5087 = v5085[v5256];
  int v5257 = 4 + ((((int)((unsigned int)((int)((unsigned int)v5083 >> 2)) >> 1)) & 3) * 2);
  int v5088 = v5085[v5257];
  int v5258 = (4 + ((((int)((unsigned int)((int)((unsigned int)v5083 >> 2)) >> 1)) & 3) * 2)) + 1;
  int v5089 = v5085[v5258];
  int v5090 = v5079->timer;
  int v5259 = v5090 + ((100 ^ (((~(((v5088 ^ ((int)((unsigned int)((int)((unsigned int)v5083 >> 2)) >> 1))) | (-(v5088 ^ ((int)((unsigned int)((int)((unsigned int)v5083 >> 2)) >> 1))))) >> 31)) | (~(((v5089 ^ ((int)((unsigned int)((int)((unsigned int)v5083 >> 2)) >> 1))) | (-(v5089 ^ ((int)((unsigned int)((int)((unsigned int)v5083 >> 2)) >> 1))))) >> 31))) & 104)) ^ (((~(((v5086 ^ ((int)((unsigned int)((int)((unsigned int)v5083 >> 2)) >> 1))) | (-(v5086 ^ ((int)((unsigned int)((int)((unsigned int)v5083 >> 2)) >> 1))))) >> 31)) | (~(((v5087 ^ ((int)((unsigned int)((int)((unsigned int)v5083 >> 2)) >> 1))) | (-(v5087 ^ ((int)((unsigned int)((int)((unsigned int)v5083 >> 2)) >> 1))))) >> 31))) & (1 ^ (100 ^ (((~(((v5088 ^ ((int)((unsigned int)((int)((unsigned int)v5083 >> 2)) >> 1))) | (-(v5088 ^ ((int)((unsigned int)((int)((unsigned int)v5083 >> 2)) >> 1))))) >> 31)) | (~(((v5089 ^ ((int)((unsigned int)((int)((unsigned int)v5083 >> 2)) >> 1))) | (-(v5089 ^ ((int)((unsigned int)((int)((unsigned int)v5083 >> 2)) >> 1))))) >> 31))) & 104)))));
  v5079->timer = v5259;
  bool v5260 = !(((~(((v5086 ^ ((int)((unsigned int)((int)((unsigned int)v5083 >> 2)) >> 1))) | (-(v5086 ^ ((int)((unsigned int)((int)((unsigned int)v5083 >> 2)) >> 1))))) >> 31)) | (~(((v5087 ^ ((int)((unsigned int)((int)((unsigned int)v5083 >> 2)) >> 1))) | (-(v5087 ^ ((int)((unsigned int)((int)((unsigned int)v5083 >> 2)) >> 1))))) >> 31))) == 0);
  int v5184;
  if (v5260) {
    int * v5092 = v5079->cache_age;
    int v5262 = ((((int)((unsigned int)((int)((unsigned int)v5083 >> 2)) >> 1)) & 1) * 2) + ((~(((v5087 ^ ((int)((unsigned int)((int)((unsigned int)v5083 >> 2)) >> 1))) | (-(v5087 ^ ((int)((unsigned int)((int)((unsigned int)v5083 >> 2)) >> 1))))) >> 31)) & 1);
    int v5093 = v5092[v5262];
    int v5094 = v5092[v5255];
    int v5263 = v5094 + ((int)((unsigned int)(v5094 - v5093) >> 31));
    v5092[v5255] = v5263;
    int * v5096 = v5079->cache_age;
    int v5097 = v5096[v5256];
    int v5265 = v5097 + ((int)((unsigned int)(v5097 - v5093) >> 31));
    v5096[v5256] = v5265;
    int * v5099 = v5079->cache_age;
    v5099[v5262] = 0;
    v5184 = v5262;
  } else {
    int * v5102 = v5079->cache_age;
    int v5269 = (((int)((unsigned int)((int)((unsigned int)v5083 >> 2)) >> 1)) & 1) * 2;
    int v5103 = v5102[v5269];
    int * v5104 = v5079->cache_tags;
    int v5105 = v5104[v5269];
    int v5106 = v5102[v5256];
    int v5107 = v5104[v5256];
    bool v5271 = !(((~(((v5088 ^ ((int)((unsigned int)((int)((unsigned int)v5083 >> 2)) >> 1))) | (-(v5088 ^ ((int)((unsigned int)((int)((unsigned int)v5083 >> 2)) >> 1))))) >> 31)) | (~(((v5089 ^ ((int)((unsigned int)((int)((unsigned int)v5083 >> 2)) >> 1))) | (-(v5089 ^ ((int)((unsigned int)((int)((unsigned int)v5083 >> 2)) >> 1))))) >> 31))) == 0);
    int v5161;
    if (v5271) {
      int * v5108 = v5079->cache_age;
      int v5273 = (4 + ((((int)((unsigned int)((int)((unsigned int)v5083 >> 2)) >> 1)) & 3) * 2)) + ((~(((v5089 ^ ((int)((unsigned int)((int)((unsigned int)v5083 >> 2)) >> 1))) | (-(v5089 ^ ((int)((unsigned int)((int)((unsigned int)v5083 >> 2)) >> 1))))) >> 31)) & 1);
      int v5109 = v5108[v5273];
      int v5110 = v5108[v5257];
      int v5274 = v5110 + ((int)((unsigned int)(v5110 - v5109) >> 31));
      v5108[v5257] = v5274;
      int * v5112 = v5079->cache_age;
      int v5113 = v5112[v5258];
      int v5276 = v5113 + ((int)((unsigned int)(v5113 - v5109) >> 31));
      v5112[v5258] = v5276;
      int * v5115 = v5079->cache_age;
      v5115[v5273] = 0;
      v5161 = v5273;
    } else {
      int * v5118 = v5079->cache_age;
      int v5280 = 4 + ((((int)((unsigned int)((int)((unsigned int)v5083 >> 2)) >> 1)) & 3) * 2);
      int v5119 = v5118[v5280];
      int * v5120 = v5079->cache_tags;
      int v5121 = v5120[v5280];
      int v5122 = v5118[v5258];
      int v5123 = v5120[v5258];
      int * v5124 = v5079->cache_dirty;
      int v5283 = (4 + ((((int)((unsigned int)((int)((unsigned int)v5083 >> 2)) >> 1)) & 3) * 2)) + ((((v5119 + ((~(((v5121 ^ -1) | (-(v5121 ^ -1))) >> 31)) & 2)) - (v5122 + ((~(((v5123 ^ -1) | (-(v5123 ^ -1))) >> 31)) & 2))) >> 31) & 1);
      int v5125 = v5124[v5283];
      bool v5284 = !(v5125 == 0);
      if (v5284) {
        int * v5126 = v5079->cache_tags;
        int v5127 = v5126[v5283];
        int * v5128 = v5079->cache_vals;
        int v5287 = ((4 + ((((int)((unsigned int)((int)((unsigned int)v5083 >> 2)) >> 1)) & 3) * 2)) + ((((v5119 + ((~(((v5121 ^ -1) | (-(v5121 ^ -1))) >> 31)) & 2)) - (v5122 + ((~(((v5123 ^ -1) | (-(v5123 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
        int v5129 = v5128[v5287];
        int v5288 = (((4 + ((((int)((unsigned int)((int)((unsigned int)v5083 >> 2)) >> 1)) & 3) * 2)) + ((((v5119 + ((~(((v5121 ^ -1) | (-(v5121 ^ -1))) >> 31)) & 2)) - (v5122 + ((~(((v5123 ^ -1) | (-(v5123 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
        int v5130 = v5128[v5288];
        int * v5131 = v5079->mem;
        int v5290 = v5127 * 2;
        v5131[v5290] = v5129;
        int * v5133 = v5079->mem;
        int v5293 = (v5127 * 2) + 1;
        v5133[v5293] = v5130;
        ;
      } else {
        ;
      }
      int * v5138 = v5079->mem;
      int v5298 = ((int)((unsigned int)((int)((unsigned int)v5083 >> 2)) >> 1)) * 2;
      int v5139 = v5138[v5298];
      int v5299 = (((int)((unsigned int)((int)((unsigned int)v5083 >> 2)) >> 1)) * 2) + 1;
      int v5140 = v5138[v5299];
      int * v5141 = v5079->cache_vals;
      int v5301 = ((4 + ((((int)((unsigned int)((int)((unsigned int)v5083 >> 2)) >> 1)) & 3) * 2)) + ((((v5119 + ((~(((v5121 ^ -1) | (-(v5121 ^ -1))) >> 31)) & 2)) - (v5122 + ((~(((v5123 ^ -1) | (-(v5123 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
      v5141[v5301] = v5139;
      int * v5143 = v5079->cache_vals;
      int v5304 = (((4 + ((((int)((unsigned int)((int)((unsigned int)v5083 >> 2)) >> 1)) & 3) * 2)) + ((((v5119 + ((~(((v5121 ^ -1) | (-(v5121 ^ -1))) >> 31)) & 2)) - (v5122 + ((~(((v5123 ^ -1) | (-(v5123 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
      v5143[v5304] = v5140;
      int * v5145 = v5079->cache_tags;
      int v5307 = (int)((unsigned int)((int)((unsigned int)v5083 >> 2)) >> 1);
      v5145[v5283] = v5307;
      int * v5147 = v5079->cache_dirty;
      v5147[v5283] = 0;
      int * v5149 = v5079->cache_age;
      v5149[v5283] = 1;
      int * v5151 = v5079->cache_age;
      int v5152 = v5151[v5283];
      int v5153 = v5151[v5257];
      int v5313 = v5153 + ((int)((unsigned int)(v5153 - v5152) >> 31));
      v5151[v5257] = v5313;
      int * v5155 = v5079->cache_age;
      int v5156 = v5155[v5258];
      int v5315 = v5156 + ((int)((unsigned int)(v5156 - v5152) >> 31));
      v5155[v5258] = v5315;
      int * v5158 = v5079->cache_age;
      v5158[v5283] = 0;
      v5161 = v5283;
    }
    int * v5162 = v5079->cache_vals;
    int v5318 = v5161 * 2;
    int v5163 = v5162[v5318];
    int v5319 = (v5161 * 2) + 1;
    int v5164 = v5162[v5319];
    int v5320 = (((((int)((unsigned int)((int)((unsigned int)v5083 >> 2)) >> 1)) & 1) * 2) + ((((v5103 + ((~(((v5105 ^ -1) | (-(v5105 ^ -1))) >> 31)) & 2)) - (v5106 + ((~(((v5107 ^ -1) | (-(v5107 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
    v5162[v5320] = v5163;
    int * v5166 = v5079->cache_vals;
    int v5323 = ((((((int)((unsigned int)((int)((unsigned int)v5083 >> 2)) >> 1)) & 1) * 2) + ((((v5103 + ((~(((v5105 ^ -1) | (-(v5105 ^ -1))) >> 31)) & 2)) - (v5106 + ((~(((v5107 ^ -1) | (-(v5107 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
    v5166[v5323] = v5164;
    int * v5168 = v5079->cache_tags;
    int v5326 = ((((int)((unsigned int)((int)((unsigned int)v5083 >> 2)) >> 1)) & 1) * 2) + ((((v5103 + ((~(((v5105 ^ -1) | (-(v5105 ^ -1))) >> 31)) & 2)) - (v5106 + ((~(((v5107 ^ -1) | (-(v5107 ^ -1))) >> 31)) & 2))) >> 31) & 1);
    int v5327 = (int)((unsigned int)((int)((unsigned int)v5083 >> 2)) >> 1);
    v5168[v5326] = v5327;
    int * v5170 = v5079->cache_dirty;
    v5170[v5326] = 0;
    int * v5172 = v5079->cache_age;
    v5172[v5326] = 1;
    int * v5174 = v5079->cache_age;
    int v5175 = v5174[v5326];
    int v5176 = v5174[v5255];
    int v5333 = v5176 + ((int)((unsigned int)(v5176 - v5175) >> 31));
    v5174[v5255] = v5333;
    int * v5178 = v5079->cache_age;
    int v5179 = v5178[v5256];
    int v5335 = v5179 + ((int)((unsigned int)(v5179 - v5175) >> 31));
    v5178[v5256] = v5335;
    int * v5181 = v5079->cache_age;
    v5181[v5326] = 0;
    v5184 = v5326;
  }
  int * v5185 = v5079->cache_vals;
  int v5338 = (v5184 * 2) + (((int)((unsigned int)v5083 >> 2)) & 1);
  v5185[v5338] = v5084;
  int * v5187 = v5079->cache_tags;
  int v5188 = v5187[v5257];
  int v5189 = v5187[v5258];
  bool v5341 = !(((~(((v5188 ^ ((int)((unsigned int)((int)((unsigned int)v5083 >> 2)) >> 1))) | (-(v5188 ^ ((int)((unsigned int)((int)((unsigned int)v5083 >> 2)) >> 1))))) >> 31)) | (~(((v5189 ^ ((int)((unsigned int)((int)((unsigned int)v5083 >> 2)) >> 1))) | (-(v5189 ^ ((int)((unsigned int)((int)((unsigned int)v5083 >> 2)) >> 1))))) >> 31))) == 0);
  int v5243;
  if (v5341) {
    int * v5190 = v5079->cache_age;
    int v5343 = (4 + ((((int)((unsigned int)((int)((unsigned int)v5083 >> 2)) >> 1)) & 3) * 2)) + ((~(((v5189 ^ ((int)((unsigned int)((int)((unsigned int)v5083 >> 2)) >> 1))) | (-(v5189 ^ ((int)((unsigned int)((int)((unsigned int)v5083 >> 2)) >> 1))))) >> 31)) & 1);
    int v5191 = v5190[v5343];
    int v5192 = v5190[v5257];
    int v5344 = v5192 + ((int)((unsigned int)(v5192 - v5191) >> 31));
    v5190[v5257] = v5344;
    int * v5194 = v5079->cache_age;
    int v5195 = v5194[v5258];
    int v5346 = v5195 + ((int)((unsigned int)(v5195 - v5191) >> 31));
    v5194[v5258] = v5346;
    int * v5197 = v5079->cache_age;
    v5197[v5343] = 0;
    v5243 = v5343;
  } else {
    int * v5200 = v5079->cache_age;
    int v5350 = 4 + ((((int)((unsigned int)((int)((unsigned int)v5083 >> 2)) >> 1)) & 3) * 2);
    int v5201 = v5200[v5350];
    int * v5202 = v5079->cache_tags;
    int v5203 = v5202[v5350];
    int v5204 = v5200[v5258];
    int v5205 = v5202[v5258];
    int * v5206 = v5079->cache_dirty;
    int v5353 = (4 + ((((int)((unsigned int)((int)((unsigned int)v5083 >> 2)) >> 1)) & 3) * 2)) + ((((v5201 + ((~(((v5203 ^ -1) | (-(v5203 ^ -1))) >> 31)) & 2)) - (v5204 + ((~(((v5205 ^ -1) | (-(v5205 ^ -1))) >> 31)) & 2))) >> 31) & 1);
    int v5207 = v5206[v5353];
    bool v5354 = !(v5207 == 0);
    if (v5354) {
      int * v5208 = v5079->cache_tags;
      int v5209 = v5208[v5353];
      int * v5210 = v5079->cache_vals;
      int v5357 = ((4 + ((((int)((unsigned int)((int)((unsigned int)v5083 >> 2)) >> 1)) & 3) * 2)) + ((((v5201 + ((~(((v5203 ^ -1) | (-(v5203 ^ -1))) >> 31)) & 2)) - (v5204 + ((~(((v5205 ^ -1) | (-(v5205 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
      int v5211 = v5210[v5357];
      int v5358 = (((4 + ((((int)((unsigned int)((int)((unsigned int)v5083 >> 2)) >> 1)) & 3) * 2)) + ((((v5201 + ((~(((v5203 ^ -1) | (-(v5203 ^ -1))) >> 31)) & 2)) - (v5204 + ((~(((v5205 ^ -1) | (-(v5205 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
      int v5212 = v5210[v5358];
      int * v5213 = v5079->mem;
      int v5360 = v5209 * 2;
      v5213[v5360] = v5211;
      int * v5215 = v5079->mem;
      int v5363 = (v5209 * 2) + 1;
      v5215[v5363] = v5212;
      ;
    } else {
      ;
    }
    int * v5220 = v5079->mem;
    int v5368 = ((int)((unsigned int)((int)((unsigned int)v5083 >> 2)) >> 1)) * 2;
    int v5221 = v5220[v5368];
    int v5369 = (((int)((unsigned int)((int)((unsigned int)v5083 >> 2)) >> 1)) * 2) + 1;
    int v5222 = v5220[v5369];
    int * v5223 = v5079->cache_vals;
    int v5371 = ((4 + ((((int)((unsigned int)((int)((unsigned int)v5083 >> 2)) >> 1)) & 3) * 2)) + ((((v5201 + ((~(((v5203 ^ -1) | (-(v5203 ^ -1))) >> 31)) & 2)) - (v5204 + ((~(((v5205 ^ -1) | (-(v5205 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
    v5223[v5371] = v5221;
    int * v5225 = v5079->cache_vals;
    int v5374 = (((4 + ((((int)((unsigned int)((int)((unsigned int)v5083 >> 2)) >> 1)) & 3) * 2)) + ((((v5201 + ((~(((v5203 ^ -1) | (-(v5203 ^ -1))) >> 31)) & 2)) - (v5204 + ((~(((v5205 ^ -1) | (-(v5205 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
    v5225[v5374] = v5222;
    int * v5227 = v5079->cache_tags;
    int v5377 = (int)((unsigned int)((int)((unsigned int)v5083 >> 2)) >> 1);
    v5227[v5353] = v5377;
    int * v5229 = v5079->cache_dirty;
    v5229[v5353] = 0;
    int * v5231 = v5079->cache_age;
    v5231[v5353] = 1;
    int * v5233 = v5079->cache_age;
    int v5234 = v5233[v5353];
    int v5235 = v5233[v5257];
    int v5383 = v5235 + ((int)((unsigned int)(v5235 - v5234) >> 31));
    v5233[v5257] = v5383;
    int * v5237 = v5079->cache_age;
    int v5238 = v5237[v5258];
    int v5385 = v5238 + ((int)((unsigned int)(v5238 - v5234) >> 31));
    v5237[v5258] = v5385;
    int * v5240 = v5079->cache_age;
    v5240[v5353] = 0;
    v5243 = v5353;
  }
  int * v5244 = v5079->cache_vals;
  int v5388 = (v5243 * 2) + (((int)((unsigned int)v5083 >> 2)) & 1);
  v5244[v5388] = v5084;
  int * v5246 = v5079->cache_dirty;
  v5246[v5243] = 1;
  struct StateT * v5248 = slot_62(v5079);
  return v5248;
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

struct StateT * slot_60(struct StateT * v5063) {
  int v5064 = v5063->timer;
  int v5072 = v5064 + 1;
  v5063->timer = v5072;
  int * v5066 = v5063->regs;
  int v5067 = v5066[6];
  int v5068 = v5066[17];
  int v5076 = v5067 ^ v5068;
  v5066[17] = v5076;
  struct StateT * v5070 = slot_61(v5063);
  return v5070;
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