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
struct StateT * slot_43(struct StateT * v3038);
struct StateT * slot_70(struct StateT * v5798);
struct StateT * slot_76(struct StateT * v6674);
struct StateT * slot_6(struct StateT * v94);
struct StateT * slot_47(struct StateT * v3854);
struct StateT * slot_29(struct StateT * v2247);
struct StateT * slot_55(struct StateT * v4580);
struct StateT * slot_16(struct StateT * v1040);
struct StateT * slot_5(struct StateT * v80);
struct StateT * slot_7(struct StateT * v102);
struct StateT * slot_31(struct StateT * v2279);
struct StateT * slot_54(struct StateT * v4265);
struct StateT * slot_26(struct StateT * v2011);
struct StateT * slot_65(struct StateT * v5714);
struct StateT * slot_10(struct StateT * v164);
struct StateT * slot_74(struct StateT * v6642);
struct StateT * slot_19(struct StateT * v1088);
struct StateT * slot_58(struct StateT * v5004);
struct StateT * slot_67(struct StateT * v5736);
struct StateT * slot_64(struct StateT * v5399);
struct StateT * slot_14(struct StateT * v1008);
struct StateT * slot_53(struct StateT * v3950);
struct StateT * slot_80(struct StateT * v6738);
struct StateT * slot_44(struct StateT * v3242);
struct StateT * slot_66(struct StateT * v5728);
struct StateT * slot_78(struct StateT * v6706);
struct StateT * slot_28(struct StateT * v2231);
struct StateT * slot_32(struct StateT * v2295);
struct StateT * slot_17(struct StateT * v1056);
struct StateT * slot_49(struct StateT * v3886);
struct StateT * slot_33(struct StateT * v2311);
struct StateT * slot_50(struct StateT * v3902);
struct StateT * slot_36(struct StateT * v2955);
struct StateT * slot_37(struct StateT * v2963);
struct StateT * slot_57(struct StateT * v4988);
struct StateT * slot_68(struct StateT * v5758);
struct StateT * slot_59(struct StateT * v5020);
struct StateT * slot_40(struct StateT * v3005);
struct StateT * slot_27(struct StateT * v2215);
struct StateT * slot_15(struct StateT * v1024);
struct StateT * slot_62(struct StateT * v5068);
struct StateT * slot_48(struct StateT * v3870);
struct StateT * slot_77(struct StateT * v6690);
struct StateT * slot_22(struct StateT * v1177);
struct StateT * slot_35(struct StateT * v2941);
struct StateT * slot_75(struct StateT * v6658);
struct StateT * slot_56(struct StateT * v4784);
struct StateT * slot_72(struct StateT * v6220);
struct StateT * slot_34(struct StateT * v2626);
struct StateT * slot_71(struct StateT * v6009);
struct StateT * slot_51(struct StateT * v3918);
struct StateT * slot_52(struct StateT * v3934);
struct StateT * slot_25(struct StateT * v1807);
struct StateT * slot_2(struct StateT * v29);
struct StateT * slot_21(struct StateT * v1172);
struct StateT * slot_3(struct StateT * v45);
struct StateT * slot_45(struct StateT * v3446);
struct StateT * slot_73(struct StateT * v6431);
struct StateT * slot_1(struct StateT * v15);
struct StateT * slot_69(struct StateT * v5782);
struct StateT * slot_13(struct StateT * v797);
struct StateT * slot_38(struct StateT * v2985);
struct StateT * slot_63(struct StateT * v5084);
struct StateT * slot_24(struct StateT * v1492);
struct StateT * slot_0(struct StateT * v2);
struct StateT * slot_42(struct StateT * v3022);
struct StateT * slot_46(struct StateT * v3650);
struct StateT * slot_20(struct StateT * v1104);
struct StateT * slot_61(struct StateT * v5052);
struct StateT * snippet(struct StateT * v0);
struct StateT * slot_79(struct StateT * v6722);
struct StateT * slot_8(struct StateT * v124);
struct StateT * slot_30(struct StateT * v2263);
struct StateT * slot_60(struct StateT * v5036);
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

struct StateT * slot_43(struct StateT * v3038) {
  int v3039 = v3038->timer;
  int v3149 = v3039 + 1;
  v3038->timer = v3149;
  int * v3041 = v3038->regs;
  int v3042 = v3041[16];
  int * v3043 = v3038->cache_tags;
  int v3153 = (((int)((unsigned int)((int)((unsigned int)v3042 >> 2)) >> 1)) & 1) * 2;
  int v3044 = v3043[v3153];
  int v3154 = ((((int)((unsigned int)((int)((unsigned int)v3042 >> 2)) >> 1)) & 1) * 2) + 1;
  int v3045 = v3043[v3154];
  int v3155 = 4 + ((((int)((unsigned int)((int)((unsigned int)v3042 >> 2)) >> 1)) & 3) * 2);
  int v3046 = v3043[v3155];
  int v3156 = (4 + ((((int)((unsigned int)((int)((unsigned int)v3042 >> 2)) >> 1)) & 3) * 2)) + 1;
  int v3047 = v3043[v3156];
  int v3048 = v3038->timer;
  int v3157 = v3048 + ((100 ^ (((~(((v3046 ^ ((int)((unsigned int)((int)((unsigned int)v3042 >> 2)) >> 1))) | (-(v3046 ^ ((int)((unsigned int)((int)((unsigned int)v3042 >> 2)) >> 1))))) >> 31)) | (~(((v3047 ^ ((int)((unsigned int)((int)((unsigned int)v3042 >> 2)) >> 1))) | (-(v3047 ^ ((int)((unsigned int)((int)((unsigned int)v3042 >> 2)) >> 1))))) >> 31))) & 104)) ^ (((~(((v3044 ^ ((int)((unsigned int)((int)((unsigned int)v3042 >> 2)) >> 1))) | (-(v3044 ^ ((int)((unsigned int)((int)((unsigned int)v3042 >> 2)) >> 1))))) >> 31)) | (~(((v3045 ^ ((int)((unsigned int)((int)((unsigned int)v3042 >> 2)) >> 1))) | (-(v3045 ^ ((int)((unsigned int)((int)((unsigned int)v3042 >> 2)) >> 1))))) >> 31))) & (1 ^ (100 ^ (((~(((v3046 ^ ((int)((unsigned int)((int)((unsigned int)v3042 >> 2)) >> 1))) | (-(v3046 ^ ((int)((unsigned int)((int)((unsigned int)v3042 >> 2)) >> 1))))) >> 31)) | (~(((v3047 ^ ((int)((unsigned int)((int)((unsigned int)v3042 >> 2)) >> 1))) | (-(v3047 ^ ((int)((unsigned int)((int)((unsigned int)v3042 >> 2)) >> 1))))) >> 31))) & 104)))));
  v3038->timer = v3157;
  int * v3050 = v3038->cache_vals;
  bool v3158 = !(((~(((v3044 ^ ((int)((unsigned int)((int)((unsigned int)v3042 >> 2)) >> 1))) | (-(v3044 ^ ((int)((unsigned int)((int)((unsigned int)v3042 >> 2)) >> 1))))) >> 31)) | (~(((v3045 ^ ((int)((unsigned int)((int)((unsigned int)v3042 >> 2)) >> 1))) | (-(v3045 ^ ((int)((unsigned int)((int)((unsigned int)v3042 >> 2)) >> 1))))) >> 31))) == 0);
  int v3143;
  if (v3158) {
    int * v3051 = v3038->cache_age;
    int v3160 = ((((int)((unsigned int)((int)((unsigned int)v3042 >> 2)) >> 1)) & 1) * 2) + ((~(((v3045 ^ ((int)((unsigned int)((int)((unsigned int)v3042 >> 2)) >> 1))) | (-(v3045 ^ ((int)((unsigned int)((int)((unsigned int)v3042 >> 2)) >> 1))))) >> 31)) & 1);
    int v3052 = v3051[v3160];
    int v3053 = v3051[v3153];
    int v3161 = v3053 + ((int)((unsigned int)(v3053 - v3052) >> 31));
    v3051[v3153] = v3161;
    int * v3055 = v3038->cache_age;
    int v3056 = v3055[v3154];
    int v3163 = v3056 + ((int)((unsigned int)(v3056 - v3052) >> 31));
    v3055[v3154] = v3163;
    int * v3058 = v3038->cache_age;
    v3058[v3160] = 0;
    v3143 = v3160;
  } else {
    int * v3061 = v3038->cache_age;
    int v3167 = (((int)((unsigned int)((int)((unsigned int)v3042 >> 2)) >> 1)) & 1) * 2;
    int v3062 = v3061[v3167];
    int * v3063 = v3038->cache_tags;
    int v3064 = v3063[v3167];
    int v3065 = v3061[v3154];
    int v3066 = v3063[v3154];
    bool v3169 = !(((~(((v3046 ^ ((int)((unsigned int)((int)((unsigned int)v3042 >> 2)) >> 1))) | (-(v3046 ^ ((int)((unsigned int)((int)((unsigned int)v3042 >> 2)) >> 1))))) >> 31)) | (~(((v3047 ^ ((int)((unsigned int)((int)((unsigned int)v3042 >> 2)) >> 1))) | (-(v3047 ^ ((int)((unsigned int)((int)((unsigned int)v3042 >> 2)) >> 1))))) >> 31))) == 0);
    int v3120;
    if (v3169) {
      int * v3067 = v3038->cache_age;
      int v3171 = (4 + ((((int)((unsigned int)((int)((unsigned int)v3042 >> 2)) >> 1)) & 3) * 2)) + ((~(((v3047 ^ ((int)((unsigned int)((int)((unsigned int)v3042 >> 2)) >> 1))) | (-(v3047 ^ ((int)((unsigned int)((int)((unsigned int)v3042 >> 2)) >> 1))))) >> 31)) & 1);
      int v3068 = v3067[v3171];
      int v3069 = v3067[v3155];
      int v3172 = v3069 + ((int)((unsigned int)(v3069 - v3068) >> 31));
      v3067[v3155] = v3172;
      int * v3071 = v3038->cache_age;
      int v3072 = v3071[v3156];
      int v3174 = v3072 + ((int)((unsigned int)(v3072 - v3068) >> 31));
      v3071[v3156] = v3174;
      int * v3074 = v3038->cache_age;
      v3074[v3171] = 0;
      v3120 = v3171;
    } else {
      int * v3077 = v3038->cache_age;
      int v3178 = 4 + ((((int)((unsigned int)((int)((unsigned int)v3042 >> 2)) >> 1)) & 3) * 2);
      int v3078 = v3077[v3178];
      int * v3079 = v3038->cache_tags;
      int v3080 = v3079[v3178];
      int v3081 = v3077[v3156];
      int v3082 = v3079[v3156];
      int * v3083 = v3038->cache_dirty;
      int v3181 = (4 + ((((int)((unsigned int)((int)((unsigned int)v3042 >> 2)) >> 1)) & 3) * 2)) + ((((v3078 + ((~(((v3080 ^ -1) | (-(v3080 ^ -1))) >> 31)) & 2)) - (v3081 + ((~(((v3082 ^ -1) | (-(v3082 ^ -1))) >> 31)) & 2))) >> 31) & 1);
      int v3084 = v3083[v3181];
      bool v3182 = !(v3084 == 0);
      if (v3182) {
        int * v3085 = v3038->cache_tags;
        int v3086 = v3085[v3181];
        int * v3087 = v3038->cache_vals;
        int v3185 = ((4 + ((((int)((unsigned int)((int)((unsigned int)v3042 >> 2)) >> 1)) & 3) * 2)) + ((((v3078 + ((~(((v3080 ^ -1) | (-(v3080 ^ -1))) >> 31)) & 2)) - (v3081 + ((~(((v3082 ^ -1) | (-(v3082 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
        int v3088 = v3087[v3185];
        int v3186 = (((4 + ((((int)((unsigned int)((int)((unsigned int)v3042 >> 2)) >> 1)) & 3) * 2)) + ((((v3078 + ((~(((v3080 ^ -1) | (-(v3080 ^ -1))) >> 31)) & 2)) - (v3081 + ((~(((v3082 ^ -1) | (-(v3082 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
        int v3089 = v3087[v3186];
        int * v3090 = v3038->mem;
        int v3188 = v3086 * 2;
        v3090[v3188] = v3088;
        int * v3092 = v3038->mem;
        int v3191 = (v3086 * 2) + 1;
        v3092[v3191] = v3089;
        ;
      } else {
        ;
      }
      int * v3097 = v3038->mem;
      int v3196 = ((int)((unsigned int)((int)((unsigned int)v3042 >> 2)) >> 1)) * 2;
      int v3098 = v3097[v3196];
      int v3197 = (((int)((unsigned int)((int)((unsigned int)v3042 >> 2)) >> 1)) * 2) + 1;
      int v3099 = v3097[v3197];
      int * v3100 = v3038->cache_vals;
      int v3199 = ((4 + ((((int)((unsigned int)((int)((unsigned int)v3042 >> 2)) >> 1)) & 3) * 2)) + ((((v3078 + ((~(((v3080 ^ -1) | (-(v3080 ^ -1))) >> 31)) & 2)) - (v3081 + ((~(((v3082 ^ -1) | (-(v3082 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
      v3100[v3199] = v3098;
      int * v3102 = v3038->cache_vals;
      int v3202 = (((4 + ((((int)((unsigned int)((int)((unsigned int)v3042 >> 2)) >> 1)) & 3) * 2)) + ((((v3078 + ((~(((v3080 ^ -1) | (-(v3080 ^ -1))) >> 31)) & 2)) - (v3081 + ((~(((v3082 ^ -1) | (-(v3082 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
      v3102[v3202] = v3099;
      int * v3104 = v3038->cache_tags;
      int v3205 = (int)((unsigned int)((int)((unsigned int)v3042 >> 2)) >> 1);
      v3104[v3181] = v3205;
      int * v3106 = v3038->cache_dirty;
      v3106[v3181] = 0;
      int * v3108 = v3038->cache_age;
      v3108[v3181] = 1;
      int * v3110 = v3038->cache_age;
      int v3111 = v3110[v3181];
      int v3112 = v3110[v3155];
      int v3211 = v3112 + ((int)((unsigned int)(v3112 - v3111) >> 31));
      v3110[v3155] = v3211;
      int * v3114 = v3038->cache_age;
      int v3115 = v3114[v3156];
      int v3213 = v3115 + ((int)((unsigned int)(v3115 - v3111) >> 31));
      v3114[v3156] = v3213;
      int * v3117 = v3038->cache_age;
      v3117[v3181] = 0;
      v3120 = v3181;
    }
    int * v3121 = v3038->cache_vals;
    int v3216 = v3120 * 2;
    int v3122 = v3121[v3216];
    int v3217 = (v3120 * 2) + 1;
    int v3123 = v3121[v3217];
    int v3218 = (((((int)((unsigned int)((int)((unsigned int)v3042 >> 2)) >> 1)) & 1) * 2) + ((((v3062 + ((~(((v3064 ^ -1) | (-(v3064 ^ -1))) >> 31)) & 2)) - (v3065 + ((~(((v3066 ^ -1) | (-(v3066 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
    v3121[v3218] = v3122;
    int * v3125 = v3038->cache_vals;
    int v3221 = ((((((int)((unsigned int)((int)((unsigned int)v3042 >> 2)) >> 1)) & 1) * 2) + ((((v3062 + ((~(((v3064 ^ -1) | (-(v3064 ^ -1))) >> 31)) & 2)) - (v3065 + ((~(((v3066 ^ -1) | (-(v3066 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
    v3125[v3221] = v3123;
    int * v3127 = v3038->cache_tags;
    int v3224 = ((((int)((unsigned int)((int)((unsigned int)v3042 >> 2)) >> 1)) & 1) * 2) + ((((v3062 + ((~(((v3064 ^ -1) | (-(v3064 ^ -1))) >> 31)) & 2)) - (v3065 + ((~(((v3066 ^ -1) | (-(v3066 ^ -1))) >> 31)) & 2))) >> 31) & 1);
    int v3225 = (int)((unsigned int)((int)((unsigned int)v3042 >> 2)) >> 1);
    v3127[v3224] = v3225;
    int * v3129 = v3038->cache_dirty;
    v3129[v3224] = 0;
    int * v3131 = v3038->cache_age;
    v3131[v3224] = 1;
    int * v3133 = v3038->cache_age;
    int v3134 = v3133[v3224];
    int v3135 = v3133[v3153];
    int v3231 = v3135 + ((int)((unsigned int)(v3135 - v3134) >> 31));
    v3133[v3153] = v3231;
    int * v3137 = v3038->cache_age;
    int v3138 = v3137[v3154];
    int v3233 = v3138 + ((int)((unsigned int)(v3138 - v3134) >> 31));
    v3137[v3154] = v3233;
    int * v3140 = v3038->cache_age;
    v3140[v3224] = 0;
    v3143 = v3224;
  }
  int v3236 = (v3143 * 2) + (((int)((unsigned int)v3042 >> 2)) & 1);
  int v3144 = v3050[v3236];
  int * v3145 = v3038->regs;
  v3145[17] = v3144;
  struct StateT * v3147 = slot_44(v3038);
  return v3147;
}

struct StateT * slot_70(struct StateT * v5798) {
  int * v5799 = v5798->saved_regs;
  int * v5800 = v5798->regs;
  int v5801 = v5800[17];
  v5799[17] = v5801;
  int v5803 = v5798->timer;
  int v5917 = v5803 + 1;
  v5798->timer = v5917;
  int * v5805 = v5798->regs;
  int v5806 = v5805[16];
  int * v5807 = v5798->cache_tags;
  int v5921 = (((int)((unsigned int)((int)((unsigned int)v5806 >> 2)) >> 1)) & 1) * 2;
  int v5808 = v5807[v5921];
  int v5922 = ((((int)((unsigned int)((int)((unsigned int)v5806 >> 2)) >> 1)) & 1) * 2) + 1;
  int v5809 = v5807[v5922];
  int v5923 = 4 + ((((int)((unsigned int)((int)((unsigned int)v5806 >> 2)) >> 1)) & 3) * 2);
  int v5810 = v5807[v5923];
  int v5924 = (4 + ((((int)((unsigned int)((int)((unsigned int)v5806 >> 2)) >> 1)) & 3) * 2)) + 1;
  int v5811 = v5807[v5924];
  int v5812 = v5798->timer;
  int v5925 = v5812 + ((100 ^ (((~(((v5810 ^ ((int)((unsigned int)((int)((unsigned int)v5806 >> 2)) >> 1))) | (-(v5810 ^ ((int)((unsigned int)((int)((unsigned int)v5806 >> 2)) >> 1))))) >> 31)) | (~(((v5811 ^ ((int)((unsigned int)((int)((unsigned int)v5806 >> 2)) >> 1))) | (-(v5811 ^ ((int)((unsigned int)((int)((unsigned int)v5806 >> 2)) >> 1))))) >> 31))) & 104)) ^ (((~(((v5808 ^ ((int)((unsigned int)((int)((unsigned int)v5806 >> 2)) >> 1))) | (-(v5808 ^ ((int)((unsigned int)((int)((unsigned int)v5806 >> 2)) >> 1))))) >> 31)) | (~(((v5809 ^ ((int)((unsigned int)((int)((unsigned int)v5806 >> 2)) >> 1))) | (-(v5809 ^ ((int)((unsigned int)((int)((unsigned int)v5806 >> 2)) >> 1))))) >> 31))) & (1 ^ (100 ^ (((~(((v5810 ^ ((int)((unsigned int)((int)((unsigned int)v5806 >> 2)) >> 1))) | (-(v5810 ^ ((int)((unsigned int)((int)((unsigned int)v5806 >> 2)) >> 1))))) >> 31)) | (~(((v5811 ^ ((int)((unsigned int)((int)((unsigned int)v5806 >> 2)) >> 1))) | (-(v5811 ^ ((int)((unsigned int)((int)((unsigned int)v5806 >> 2)) >> 1))))) >> 31))) & 104)))));
  v5798->timer = v5925;
  int * v5814 = v5798->cache_vals;
  bool v5926 = !(((~(((v5808 ^ ((int)((unsigned int)((int)((unsigned int)v5806 >> 2)) >> 1))) | (-(v5808 ^ ((int)((unsigned int)((int)((unsigned int)v5806 >> 2)) >> 1))))) >> 31)) | (~(((v5809 ^ ((int)((unsigned int)((int)((unsigned int)v5806 >> 2)) >> 1))) | (-(v5809 ^ ((int)((unsigned int)((int)((unsigned int)v5806 >> 2)) >> 1))))) >> 31))) == 0);
  int v5907;
  if (v5926) {
    int * v5815 = v5798->cache_age;
    int v5928 = ((((int)((unsigned int)((int)((unsigned int)v5806 >> 2)) >> 1)) & 1) * 2) + ((~(((v5809 ^ ((int)((unsigned int)((int)((unsigned int)v5806 >> 2)) >> 1))) | (-(v5809 ^ ((int)((unsigned int)((int)((unsigned int)v5806 >> 2)) >> 1))))) >> 31)) & 1);
    int v5816 = v5815[v5928];
    int v5817 = v5815[v5921];
    int v5929 = v5817 + ((int)((unsigned int)(v5817 - v5816) >> 31));
    v5815[v5921] = v5929;
    int * v5819 = v5798->cache_age;
    int v5820 = v5819[v5922];
    int v5931 = v5820 + ((int)((unsigned int)(v5820 - v5816) >> 31));
    v5819[v5922] = v5931;
    int * v5822 = v5798->cache_age;
    v5822[v5928] = 0;
    v5907 = v5928;
  } else {
    int * v5825 = v5798->cache_age;
    int v5935 = (((int)((unsigned int)((int)((unsigned int)v5806 >> 2)) >> 1)) & 1) * 2;
    int v5826 = v5825[v5935];
    int * v5827 = v5798->cache_tags;
    int v5828 = v5827[v5935];
    int v5829 = v5825[v5922];
    int v5830 = v5827[v5922];
    bool v5937 = !(((~(((v5810 ^ ((int)((unsigned int)((int)((unsigned int)v5806 >> 2)) >> 1))) | (-(v5810 ^ ((int)((unsigned int)((int)((unsigned int)v5806 >> 2)) >> 1))))) >> 31)) | (~(((v5811 ^ ((int)((unsigned int)((int)((unsigned int)v5806 >> 2)) >> 1))) | (-(v5811 ^ ((int)((unsigned int)((int)((unsigned int)v5806 >> 2)) >> 1))))) >> 31))) == 0);
    int v5884;
    if (v5937) {
      int * v5831 = v5798->cache_age;
      int v5939 = (4 + ((((int)((unsigned int)((int)((unsigned int)v5806 >> 2)) >> 1)) & 3) * 2)) + ((~(((v5811 ^ ((int)((unsigned int)((int)((unsigned int)v5806 >> 2)) >> 1))) | (-(v5811 ^ ((int)((unsigned int)((int)((unsigned int)v5806 >> 2)) >> 1))))) >> 31)) & 1);
      int v5832 = v5831[v5939];
      int v5833 = v5831[v5923];
      int v5940 = v5833 + ((int)((unsigned int)(v5833 - v5832) >> 31));
      v5831[v5923] = v5940;
      int * v5835 = v5798->cache_age;
      int v5836 = v5835[v5924];
      int v5942 = v5836 + ((int)((unsigned int)(v5836 - v5832) >> 31));
      v5835[v5924] = v5942;
      int * v5838 = v5798->cache_age;
      v5838[v5939] = 0;
      v5884 = v5939;
    } else {
      int * v5841 = v5798->cache_age;
      int v5946 = 4 + ((((int)((unsigned int)((int)((unsigned int)v5806 >> 2)) >> 1)) & 3) * 2);
      int v5842 = v5841[v5946];
      int * v5843 = v5798->cache_tags;
      int v5844 = v5843[v5946];
      int v5845 = v5841[v5924];
      int v5846 = v5843[v5924];
      int * v5847 = v5798->cache_dirty;
      int v5949 = (4 + ((((int)((unsigned int)((int)((unsigned int)v5806 >> 2)) >> 1)) & 3) * 2)) + ((((v5842 + ((~(((v5844 ^ -1) | (-(v5844 ^ -1))) >> 31)) & 2)) - (v5845 + ((~(((v5846 ^ -1) | (-(v5846 ^ -1))) >> 31)) & 2))) >> 31) & 1);
      int v5848 = v5847[v5949];
      bool v5950 = !(v5848 == 0);
      if (v5950) {
        int * v5849 = v5798->cache_tags;
        int v5850 = v5849[v5949];
        int * v5851 = v5798->cache_vals;
        int v5953 = ((4 + ((((int)((unsigned int)((int)((unsigned int)v5806 >> 2)) >> 1)) & 3) * 2)) + ((((v5842 + ((~(((v5844 ^ -1) | (-(v5844 ^ -1))) >> 31)) & 2)) - (v5845 + ((~(((v5846 ^ -1) | (-(v5846 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
        int v5852 = v5851[v5953];
        int v5954 = (((4 + ((((int)((unsigned int)((int)((unsigned int)v5806 >> 2)) >> 1)) & 3) * 2)) + ((((v5842 + ((~(((v5844 ^ -1) | (-(v5844 ^ -1))) >> 31)) & 2)) - (v5845 + ((~(((v5846 ^ -1) | (-(v5846 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
        int v5853 = v5851[v5954];
        int * v5854 = v5798->mem;
        int v5956 = v5850 * 2;
        v5854[v5956] = v5852;
        int * v5856 = v5798->mem;
        int v5959 = (v5850 * 2) + 1;
        v5856[v5959] = v5853;
        ;
      } else {
        ;
      }
      int * v5861 = v5798->mem;
      int v5964 = ((int)((unsigned int)((int)((unsigned int)v5806 >> 2)) >> 1)) * 2;
      int v5862 = v5861[v5964];
      int v5965 = (((int)((unsigned int)((int)((unsigned int)v5806 >> 2)) >> 1)) * 2) + 1;
      int v5863 = v5861[v5965];
      int * v5864 = v5798->cache_vals;
      int v5967 = ((4 + ((((int)((unsigned int)((int)((unsigned int)v5806 >> 2)) >> 1)) & 3) * 2)) + ((((v5842 + ((~(((v5844 ^ -1) | (-(v5844 ^ -1))) >> 31)) & 2)) - (v5845 + ((~(((v5846 ^ -1) | (-(v5846 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
      v5864[v5967] = v5862;
      int * v5866 = v5798->cache_vals;
      int v5970 = (((4 + ((((int)((unsigned int)((int)((unsigned int)v5806 >> 2)) >> 1)) & 3) * 2)) + ((((v5842 + ((~(((v5844 ^ -1) | (-(v5844 ^ -1))) >> 31)) & 2)) - (v5845 + ((~(((v5846 ^ -1) | (-(v5846 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
      v5866[v5970] = v5863;
      int * v5868 = v5798->cache_tags;
      int v5973 = (int)((unsigned int)((int)((unsigned int)v5806 >> 2)) >> 1);
      v5868[v5949] = v5973;
      int * v5870 = v5798->cache_dirty;
      v5870[v5949] = 0;
      int * v5872 = v5798->cache_age;
      v5872[v5949] = 1;
      int * v5874 = v5798->cache_age;
      int v5875 = v5874[v5949];
      int v5876 = v5874[v5923];
      int v5979 = v5876 + ((int)((unsigned int)(v5876 - v5875) >> 31));
      v5874[v5923] = v5979;
      int * v5878 = v5798->cache_age;
      int v5879 = v5878[v5924];
      int v5981 = v5879 + ((int)((unsigned int)(v5879 - v5875) >> 31));
      v5878[v5924] = v5981;
      int * v5881 = v5798->cache_age;
      v5881[v5949] = 0;
      v5884 = v5949;
    }
    int * v5885 = v5798->cache_vals;
    int v5984 = v5884 * 2;
    int v5886 = v5885[v5984];
    int v5985 = (v5884 * 2) + 1;
    int v5887 = v5885[v5985];
    int v5986 = (((((int)((unsigned int)((int)((unsigned int)v5806 >> 2)) >> 1)) & 1) * 2) + ((((v5826 + ((~(((v5828 ^ -1) | (-(v5828 ^ -1))) >> 31)) & 2)) - (v5829 + ((~(((v5830 ^ -1) | (-(v5830 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
    v5885[v5986] = v5886;
    int * v5889 = v5798->cache_vals;
    int v5989 = ((((((int)((unsigned int)((int)((unsigned int)v5806 >> 2)) >> 1)) & 1) * 2) + ((((v5826 + ((~(((v5828 ^ -1) | (-(v5828 ^ -1))) >> 31)) & 2)) - (v5829 + ((~(((v5830 ^ -1) | (-(v5830 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
    v5889[v5989] = v5887;
    int * v5891 = v5798->cache_tags;
    int v5992 = ((((int)((unsigned int)((int)((unsigned int)v5806 >> 2)) >> 1)) & 1) * 2) + ((((v5826 + ((~(((v5828 ^ -1) | (-(v5828 ^ -1))) >> 31)) & 2)) - (v5829 + ((~(((v5830 ^ -1) | (-(v5830 ^ -1))) >> 31)) & 2))) >> 31) & 1);
    int v5993 = (int)((unsigned int)((int)((unsigned int)v5806 >> 2)) >> 1);
    v5891[v5992] = v5993;
    int * v5893 = v5798->cache_dirty;
    v5893[v5992] = 0;
    int * v5895 = v5798->cache_age;
    v5895[v5992] = 1;
    int * v5897 = v5798->cache_age;
    int v5898 = v5897[v5992];
    int v5899 = v5897[v5921];
    int v5999 = v5899 + ((int)((unsigned int)(v5899 - v5898) >> 31));
    v5897[v5921] = v5999;
    int * v5901 = v5798->cache_age;
    int v5902 = v5901[v5922];
    int v6001 = v5902 + ((int)((unsigned int)(v5902 - v5898) >> 31));
    v5901[v5922] = v6001;
    int * v5904 = v5798->cache_age;
    v5904[v5992] = 0;
    v5907 = v5992;
  }
  int v6004 = (v5907 * 2) + (((int)((unsigned int)v5806 >> 2)) & 1);
  int v5908 = v5814[v6004];
  int * v5909 = v5798->regs;
  v5909[17] = v5908;
  struct StateT * v5911 = slot_71(v5798);
  return v5911;
}

struct StateT * slot_76(struct StateT * v6674) {
  int v6675 = v6674->timer;
  int v6683 = v6675 + 1;
  v6674->timer = v6683;
  int * v6677 = v6674->regs;
  int v6678 = v6677[13];
  int v6679 = v6677[7];
  int v6687 = v6678 & v6679;
  v6677[7] = v6687;
  struct StateT * v6681 = slot_77(v6674);
  return v6681;
}

struct StateT * slot_6(struct StateT * v94) {
  int v95 = v94->timer;
  int v99 = v95 + 1;
  v94->timer = v99;
  struct StateT * v97 = slot_7(v94);
  return v97;
}

struct StateT * slot_47(struct StateT * v3854) {
  int v3855 = v3854->timer;
  int v3863 = v3855 + 1;
  v3854->timer = v3863;
  int * v3857 = v3854->regs;
  int v3858 = v3857[6];
  int v3859 = v3857[5];
  int v3867 = v3858 ^ v3859;
  v3857[6] = v3867;
  struct StateT * v3861 = slot_48(v3854);
  return v3861;
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

struct StateT * slot_55(struct StateT * v4580) {
  int v4581 = v4580->timer;
  int v4691 = v4581 + 1;
  v4580->timer = v4691;
  int * v4583 = v4580->regs;
  int v4584 = v4583[15];
  int * v4585 = v4580->cache_tags;
  int v4695 = (((int)((unsigned int)((int)((unsigned int)(v4584 + 4) >> 2)) >> 1)) & 1) * 2;
  int v4586 = v4585[v4695];
  int v4696 = ((((int)((unsigned int)((int)((unsigned int)(v4584 + 4) >> 2)) >> 1)) & 1) * 2) + 1;
  int v4587 = v4585[v4696];
  int v4697 = 4 + ((((int)((unsigned int)((int)((unsigned int)(v4584 + 4) >> 2)) >> 1)) & 3) * 2);
  int v4588 = v4585[v4697];
  int v4698 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v4584 + 4) >> 2)) >> 1)) & 3) * 2)) + 1;
  int v4589 = v4585[v4698];
  int v4590 = v4580->timer;
  int v4699 = v4590 + ((100 ^ (((~(((v4588 ^ ((int)((unsigned int)((int)((unsigned int)(v4584 + 4) >> 2)) >> 1))) | (-(v4588 ^ ((int)((unsigned int)((int)((unsigned int)(v4584 + 4) >> 2)) >> 1))))) >> 31)) | (~(((v4589 ^ ((int)((unsigned int)((int)((unsigned int)(v4584 + 4) >> 2)) >> 1))) | (-(v4589 ^ ((int)((unsigned int)((int)((unsigned int)(v4584 + 4) >> 2)) >> 1))))) >> 31))) & 104)) ^ (((~(((v4586 ^ ((int)((unsigned int)((int)((unsigned int)(v4584 + 4) >> 2)) >> 1))) | (-(v4586 ^ ((int)((unsigned int)((int)((unsigned int)(v4584 + 4) >> 2)) >> 1))))) >> 31)) | (~(((v4587 ^ ((int)((unsigned int)((int)((unsigned int)(v4584 + 4) >> 2)) >> 1))) | (-(v4587 ^ ((int)((unsigned int)((int)((unsigned int)(v4584 + 4) >> 2)) >> 1))))) >> 31))) & (1 ^ (100 ^ (((~(((v4588 ^ ((int)((unsigned int)((int)((unsigned int)(v4584 + 4) >> 2)) >> 1))) | (-(v4588 ^ ((int)((unsigned int)((int)((unsigned int)(v4584 + 4) >> 2)) >> 1))))) >> 31)) | (~(((v4589 ^ ((int)((unsigned int)((int)((unsigned int)(v4584 + 4) >> 2)) >> 1))) | (-(v4589 ^ ((int)((unsigned int)((int)((unsigned int)(v4584 + 4) >> 2)) >> 1))))) >> 31))) & 104)))));
  v4580->timer = v4699;
  int * v4592 = v4580->cache_vals;
  bool v4700 = !(((~(((v4586 ^ ((int)((unsigned int)((int)((unsigned int)(v4584 + 4) >> 2)) >> 1))) | (-(v4586 ^ ((int)((unsigned int)((int)((unsigned int)(v4584 + 4) >> 2)) >> 1))))) >> 31)) | (~(((v4587 ^ ((int)((unsigned int)((int)((unsigned int)(v4584 + 4) >> 2)) >> 1))) | (-(v4587 ^ ((int)((unsigned int)((int)((unsigned int)(v4584 + 4) >> 2)) >> 1))))) >> 31))) == 0);
  int v4685;
  if (v4700) {
    int * v4593 = v4580->cache_age;
    int v4702 = ((((int)((unsigned int)((int)((unsigned int)(v4584 + 4) >> 2)) >> 1)) & 1) * 2) + ((~(((v4587 ^ ((int)((unsigned int)((int)((unsigned int)(v4584 + 4) >> 2)) >> 1))) | (-(v4587 ^ ((int)((unsigned int)((int)((unsigned int)(v4584 + 4) >> 2)) >> 1))))) >> 31)) & 1);
    int v4594 = v4593[v4702];
    int v4595 = v4593[v4695];
    int v4703 = v4595 + ((int)((unsigned int)(v4595 - v4594) >> 31));
    v4593[v4695] = v4703;
    int * v4597 = v4580->cache_age;
    int v4598 = v4597[v4696];
    int v4705 = v4598 + ((int)((unsigned int)(v4598 - v4594) >> 31));
    v4597[v4696] = v4705;
    int * v4600 = v4580->cache_age;
    v4600[v4702] = 0;
    v4685 = v4702;
  } else {
    int * v4603 = v4580->cache_age;
    int v4709 = (((int)((unsigned int)((int)((unsigned int)(v4584 + 4) >> 2)) >> 1)) & 1) * 2;
    int v4604 = v4603[v4709];
    int * v4605 = v4580->cache_tags;
    int v4606 = v4605[v4709];
    int v4607 = v4603[v4696];
    int v4608 = v4605[v4696];
    bool v4711 = !(((~(((v4588 ^ ((int)((unsigned int)((int)((unsigned int)(v4584 + 4) >> 2)) >> 1))) | (-(v4588 ^ ((int)((unsigned int)((int)((unsigned int)(v4584 + 4) >> 2)) >> 1))))) >> 31)) | (~(((v4589 ^ ((int)((unsigned int)((int)((unsigned int)(v4584 + 4) >> 2)) >> 1))) | (-(v4589 ^ ((int)((unsigned int)((int)((unsigned int)(v4584 + 4) >> 2)) >> 1))))) >> 31))) == 0);
    int v4662;
    if (v4711) {
      int * v4609 = v4580->cache_age;
      int v4713 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v4584 + 4) >> 2)) >> 1)) & 3) * 2)) + ((~(((v4589 ^ ((int)((unsigned int)((int)((unsigned int)(v4584 + 4) >> 2)) >> 1))) | (-(v4589 ^ ((int)((unsigned int)((int)((unsigned int)(v4584 + 4) >> 2)) >> 1))))) >> 31)) & 1);
      int v4610 = v4609[v4713];
      int v4611 = v4609[v4697];
      int v4714 = v4611 + ((int)((unsigned int)(v4611 - v4610) >> 31));
      v4609[v4697] = v4714;
      int * v4613 = v4580->cache_age;
      int v4614 = v4613[v4698];
      int v4716 = v4614 + ((int)((unsigned int)(v4614 - v4610) >> 31));
      v4613[v4698] = v4716;
      int * v4616 = v4580->cache_age;
      v4616[v4713] = 0;
      v4662 = v4713;
    } else {
      int * v4619 = v4580->cache_age;
      int v4720 = 4 + ((((int)((unsigned int)((int)((unsigned int)(v4584 + 4) >> 2)) >> 1)) & 3) * 2);
      int v4620 = v4619[v4720];
      int * v4621 = v4580->cache_tags;
      int v4622 = v4621[v4720];
      int v4623 = v4619[v4698];
      int v4624 = v4621[v4698];
      int * v4625 = v4580->cache_dirty;
      int v4723 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v4584 + 4) >> 2)) >> 1)) & 3) * 2)) + ((((v4620 + ((~(((v4622 ^ -1) | (-(v4622 ^ -1))) >> 31)) & 2)) - (v4623 + ((~(((v4624 ^ -1) | (-(v4624 ^ -1))) >> 31)) & 2))) >> 31) & 1);
      int v4626 = v4625[v4723];
      bool v4724 = !(v4626 == 0);
      if (v4724) {
        int * v4627 = v4580->cache_tags;
        int v4628 = v4627[v4723];
        int * v4629 = v4580->cache_vals;
        int v4727 = ((4 + ((((int)((unsigned int)((int)((unsigned int)(v4584 + 4) >> 2)) >> 1)) & 3) * 2)) + ((((v4620 + ((~(((v4622 ^ -1) | (-(v4622 ^ -1))) >> 31)) & 2)) - (v4623 + ((~(((v4624 ^ -1) | (-(v4624 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
        int v4630 = v4629[v4727];
        int v4728 = (((4 + ((((int)((unsigned int)((int)((unsigned int)(v4584 + 4) >> 2)) >> 1)) & 3) * 2)) + ((((v4620 + ((~(((v4622 ^ -1) | (-(v4622 ^ -1))) >> 31)) & 2)) - (v4623 + ((~(((v4624 ^ -1) | (-(v4624 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
        int v4631 = v4629[v4728];
        int * v4632 = v4580->mem;
        int v4730 = v4628 * 2;
        v4632[v4730] = v4630;
        int * v4634 = v4580->mem;
        int v4733 = (v4628 * 2) + 1;
        v4634[v4733] = v4631;
        ;
      } else {
        ;
      }
      int * v4639 = v4580->mem;
      int v4738 = ((int)((unsigned int)((int)((unsigned int)(v4584 + 4) >> 2)) >> 1)) * 2;
      int v4640 = v4639[v4738];
      int v4739 = (((int)((unsigned int)((int)((unsigned int)(v4584 + 4) >> 2)) >> 1)) * 2) + 1;
      int v4641 = v4639[v4739];
      int * v4642 = v4580->cache_vals;
      int v4741 = ((4 + ((((int)((unsigned int)((int)((unsigned int)(v4584 + 4) >> 2)) >> 1)) & 3) * 2)) + ((((v4620 + ((~(((v4622 ^ -1) | (-(v4622 ^ -1))) >> 31)) & 2)) - (v4623 + ((~(((v4624 ^ -1) | (-(v4624 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
      v4642[v4741] = v4640;
      int * v4644 = v4580->cache_vals;
      int v4744 = (((4 + ((((int)((unsigned int)((int)((unsigned int)(v4584 + 4) >> 2)) >> 1)) & 3) * 2)) + ((((v4620 + ((~(((v4622 ^ -1) | (-(v4622 ^ -1))) >> 31)) & 2)) - (v4623 + ((~(((v4624 ^ -1) | (-(v4624 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
      v4644[v4744] = v4641;
      int * v4646 = v4580->cache_tags;
      int v4747 = (int)((unsigned int)((int)((unsigned int)(v4584 + 4) >> 2)) >> 1);
      v4646[v4723] = v4747;
      int * v4648 = v4580->cache_dirty;
      v4648[v4723] = 0;
      int * v4650 = v4580->cache_age;
      v4650[v4723] = 1;
      int * v4652 = v4580->cache_age;
      int v4653 = v4652[v4723];
      int v4654 = v4652[v4697];
      int v4753 = v4654 + ((int)((unsigned int)(v4654 - v4653) >> 31));
      v4652[v4697] = v4753;
      int * v4656 = v4580->cache_age;
      int v4657 = v4656[v4698];
      int v4755 = v4657 + ((int)((unsigned int)(v4657 - v4653) >> 31));
      v4656[v4698] = v4755;
      int * v4659 = v4580->cache_age;
      v4659[v4723] = 0;
      v4662 = v4723;
    }
    int * v4663 = v4580->cache_vals;
    int v4758 = v4662 * 2;
    int v4664 = v4663[v4758];
    int v4759 = (v4662 * 2) + 1;
    int v4665 = v4663[v4759];
    int v4760 = (((((int)((unsigned int)((int)((unsigned int)(v4584 + 4) >> 2)) >> 1)) & 1) * 2) + ((((v4604 + ((~(((v4606 ^ -1) | (-(v4606 ^ -1))) >> 31)) & 2)) - (v4607 + ((~(((v4608 ^ -1) | (-(v4608 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
    v4663[v4760] = v4664;
    int * v4667 = v4580->cache_vals;
    int v4763 = ((((((int)((unsigned int)((int)((unsigned int)(v4584 + 4) >> 2)) >> 1)) & 1) * 2) + ((((v4604 + ((~(((v4606 ^ -1) | (-(v4606 ^ -1))) >> 31)) & 2)) - (v4607 + ((~(((v4608 ^ -1) | (-(v4608 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
    v4667[v4763] = v4665;
    int * v4669 = v4580->cache_tags;
    int v4766 = ((((int)((unsigned int)((int)((unsigned int)(v4584 + 4) >> 2)) >> 1)) & 1) * 2) + ((((v4604 + ((~(((v4606 ^ -1) | (-(v4606 ^ -1))) >> 31)) & 2)) - (v4607 + ((~(((v4608 ^ -1) | (-(v4608 ^ -1))) >> 31)) & 2))) >> 31) & 1);
    int v4767 = (int)((unsigned int)((int)((unsigned int)(v4584 + 4) >> 2)) >> 1);
    v4669[v4766] = v4767;
    int * v4671 = v4580->cache_dirty;
    v4671[v4766] = 0;
    int * v4673 = v4580->cache_age;
    v4673[v4766] = 1;
    int * v4675 = v4580->cache_age;
    int v4676 = v4675[v4766];
    int v4677 = v4675[v4695];
    int v4773 = v4677 + ((int)((unsigned int)(v4677 - v4676) >> 31));
    v4675[v4695] = v4773;
    int * v4679 = v4580->cache_age;
    int v4680 = v4679[v4696];
    int v4775 = v4680 + ((int)((unsigned int)(v4680 - v4676) >> 31));
    v4679[v4696] = v4775;
    int * v4682 = v4580->cache_age;
    v4682[v4766] = 0;
    v4685 = v4766;
  }
  int v4778 = (v4685 * 2) + (((int)((unsigned int)(v4584 + 4) >> 2)) & 1);
  int v4686 = v4592[v4778];
  int * v4687 = v4580->regs;
  v4687[16] = v4686;
  struct StateT * v4689 = slot_56(v4580);
  return v4689;
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

struct StateT * slot_54(struct StateT * v4265) {
  int v4266 = v4265->timer;
  int v4436 = v4266 + 1;
  v4265->timer = v4436;
  int * v4268 = v4265->regs;
  int v4269 = v4268[16];
  int v4270 = v4268[6];
  int * v4271 = v4265->cache_tags;
  int v4441 = (((int)((unsigned int)((int)((unsigned int)(v4269 + 4) >> 2)) >> 1)) & 1) * 2;
  int v4272 = v4271[v4441];
  int v4442 = ((((int)((unsigned int)((int)((unsigned int)(v4269 + 4) >> 2)) >> 1)) & 1) * 2) + 1;
  int v4273 = v4271[v4442];
  int v4443 = 4 + ((((int)((unsigned int)((int)((unsigned int)(v4269 + 4) >> 2)) >> 1)) & 3) * 2);
  int v4274 = v4271[v4443];
  int v4444 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v4269 + 4) >> 2)) >> 1)) & 3) * 2)) + 1;
  int v4275 = v4271[v4444];
  int v4276 = v4265->timer;
  int v4445 = v4276 + ((100 ^ (((~(((v4274 ^ ((int)((unsigned int)((int)((unsigned int)(v4269 + 4) >> 2)) >> 1))) | (-(v4274 ^ ((int)((unsigned int)((int)((unsigned int)(v4269 + 4) >> 2)) >> 1))))) >> 31)) | (~(((v4275 ^ ((int)((unsigned int)((int)((unsigned int)(v4269 + 4) >> 2)) >> 1))) | (-(v4275 ^ ((int)((unsigned int)((int)((unsigned int)(v4269 + 4) >> 2)) >> 1))))) >> 31))) & 104)) ^ (((~(((v4272 ^ ((int)((unsigned int)((int)((unsigned int)(v4269 + 4) >> 2)) >> 1))) | (-(v4272 ^ ((int)((unsigned int)((int)((unsigned int)(v4269 + 4) >> 2)) >> 1))))) >> 31)) | (~(((v4273 ^ ((int)((unsigned int)((int)((unsigned int)(v4269 + 4) >> 2)) >> 1))) | (-(v4273 ^ ((int)((unsigned int)((int)((unsigned int)(v4269 + 4) >> 2)) >> 1))))) >> 31))) & (1 ^ (100 ^ (((~(((v4274 ^ ((int)((unsigned int)((int)((unsigned int)(v4269 + 4) >> 2)) >> 1))) | (-(v4274 ^ ((int)((unsigned int)((int)((unsigned int)(v4269 + 4) >> 2)) >> 1))))) >> 31)) | (~(((v4275 ^ ((int)((unsigned int)((int)((unsigned int)(v4269 + 4) >> 2)) >> 1))) | (-(v4275 ^ ((int)((unsigned int)((int)((unsigned int)(v4269 + 4) >> 2)) >> 1))))) >> 31))) & 104)))));
  v4265->timer = v4445;
  bool v4446 = !(((~(((v4272 ^ ((int)((unsigned int)((int)((unsigned int)(v4269 + 4) >> 2)) >> 1))) | (-(v4272 ^ ((int)((unsigned int)((int)((unsigned int)(v4269 + 4) >> 2)) >> 1))))) >> 31)) | (~(((v4273 ^ ((int)((unsigned int)((int)((unsigned int)(v4269 + 4) >> 2)) >> 1))) | (-(v4273 ^ ((int)((unsigned int)((int)((unsigned int)(v4269 + 4) >> 2)) >> 1))))) >> 31))) == 0);
  int v4370;
  if (v4446) {
    int * v4278 = v4265->cache_age;
    int v4448 = ((((int)((unsigned int)((int)((unsigned int)(v4269 + 4) >> 2)) >> 1)) & 1) * 2) + ((~(((v4273 ^ ((int)((unsigned int)((int)((unsigned int)(v4269 + 4) >> 2)) >> 1))) | (-(v4273 ^ ((int)((unsigned int)((int)((unsigned int)(v4269 + 4) >> 2)) >> 1))))) >> 31)) & 1);
    int v4279 = v4278[v4448];
    int v4280 = v4278[v4441];
    int v4449 = v4280 + ((int)((unsigned int)(v4280 - v4279) >> 31));
    v4278[v4441] = v4449;
    int * v4282 = v4265->cache_age;
    int v4283 = v4282[v4442];
    int v4451 = v4283 + ((int)((unsigned int)(v4283 - v4279) >> 31));
    v4282[v4442] = v4451;
    int * v4285 = v4265->cache_age;
    v4285[v4448] = 0;
    v4370 = v4448;
  } else {
    int * v4288 = v4265->cache_age;
    int v4455 = (((int)((unsigned int)((int)((unsigned int)(v4269 + 4) >> 2)) >> 1)) & 1) * 2;
    int v4289 = v4288[v4455];
    int * v4290 = v4265->cache_tags;
    int v4291 = v4290[v4455];
    int v4292 = v4288[v4442];
    int v4293 = v4290[v4442];
    bool v4457 = !(((~(((v4274 ^ ((int)((unsigned int)((int)((unsigned int)(v4269 + 4) >> 2)) >> 1))) | (-(v4274 ^ ((int)((unsigned int)((int)((unsigned int)(v4269 + 4) >> 2)) >> 1))))) >> 31)) | (~(((v4275 ^ ((int)((unsigned int)((int)((unsigned int)(v4269 + 4) >> 2)) >> 1))) | (-(v4275 ^ ((int)((unsigned int)((int)((unsigned int)(v4269 + 4) >> 2)) >> 1))))) >> 31))) == 0);
    int v4347;
    if (v4457) {
      int * v4294 = v4265->cache_age;
      int v4459 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v4269 + 4) >> 2)) >> 1)) & 3) * 2)) + ((~(((v4275 ^ ((int)((unsigned int)((int)((unsigned int)(v4269 + 4) >> 2)) >> 1))) | (-(v4275 ^ ((int)((unsigned int)((int)((unsigned int)(v4269 + 4) >> 2)) >> 1))))) >> 31)) & 1);
      int v4295 = v4294[v4459];
      int v4296 = v4294[v4443];
      int v4460 = v4296 + ((int)((unsigned int)(v4296 - v4295) >> 31));
      v4294[v4443] = v4460;
      int * v4298 = v4265->cache_age;
      int v4299 = v4298[v4444];
      int v4462 = v4299 + ((int)((unsigned int)(v4299 - v4295) >> 31));
      v4298[v4444] = v4462;
      int * v4301 = v4265->cache_age;
      v4301[v4459] = 0;
      v4347 = v4459;
    } else {
      int * v4304 = v4265->cache_age;
      int v4466 = 4 + ((((int)((unsigned int)((int)((unsigned int)(v4269 + 4) >> 2)) >> 1)) & 3) * 2);
      int v4305 = v4304[v4466];
      int * v4306 = v4265->cache_tags;
      int v4307 = v4306[v4466];
      int v4308 = v4304[v4444];
      int v4309 = v4306[v4444];
      int * v4310 = v4265->cache_dirty;
      int v4469 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v4269 + 4) >> 2)) >> 1)) & 3) * 2)) + ((((v4305 + ((~(((v4307 ^ -1) | (-(v4307 ^ -1))) >> 31)) & 2)) - (v4308 + ((~(((v4309 ^ -1) | (-(v4309 ^ -1))) >> 31)) & 2))) >> 31) & 1);
      int v4311 = v4310[v4469];
      bool v4470 = !(v4311 == 0);
      if (v4470) {
        int * v4312 = v4265->cache_tags;
        int v4313 = v4312[v4469];
        int * v4314 = v4265->cache_vals;
        int v4473 = ((4 + ((((int)((unsigned int)((int)((unsigned int)(v4269 + 4) >> 2)) >> 1)) & 3) * 2)) + ((((v4305 + ((~(((v4307 ^ -1) | (-(v4307 ^ -1))) >> 31)) & 2)) - (v4308 + ((~(((v4309 ^ -1) | (-(v4309 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
        int v4315 = v4314[v4473];
        int v4474 = (((4 + ((((int)((unsigned int)((int)((unsigned int)(v4269 + 4) >> 2)) >> 1)) & 3) * 2)) + ((((v4305 + ((~(((v4307 ^ -1) | (-(v4307 ^ -1))) >> 31)) & 2)) - (v4308 + ((~(((v4309 ^ -1) | (-(v4309 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
        int v4316 = v4314[v4474];
        int * v4317 = v4265->mem;
        int v4476 = v4313 * 2;
        v4317[v4476] = v4315;
        int * v4319 = v4265->mem;
        int v4479 = (v4313 * 2) + 1;
        v4319[v4479] = v4316;
        ;
      } else {
        ;
      }
      int * v4324 = v4265->mem;
      int v4484 = ((int)((unsigned int)((int)((unsigned int)(v4269 + 4) >> 2)) >> 1)) * 2;
      int v4325 = v4324[v4484];
      int v4485 = (((int)((unsigned int)((int)((unsigned int)(v4269 + 4) >> 2)) >> 1)) * 2) + 1;
      int v4326 = v4324[v4485];
      int * v4327 = v4265->cache_vals;
      int v4487 = ((4 + ((((int)((unsigned int)((int)((unsigned int)(v4269 + 4) >> 2)) >> 1)) & 3) * 2)) + ((((v4305 + ((~(((v4307 ^ -1) | (-(v4307 ^ -1))) >> 31)) & 2)) - (v4308 + ((~(((v4309 ^ -1) | (-(v4309 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
      v4327[v4487] = v4325;
      int * v4329 = v4265->cache_vals;
      int v4490 = (((4 + ((((int)((unsigned int)((int)((unsigned int)(v4269 + 4) >> 2)) >> 1)) & 3) * 2)) + ((((v4305 + ((~(((v4307 ^ -1) | (-(v4307 ^ -1))) >> 31)) & 2)) - (v4308 + ((~(((v4309 ^ -1) | (-(v4309 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
      v4329[v4490] = v4326;
      int * v4331 = v4265->cache_tags;
      int v4493 = (int)((unsigned int)((int)((unsigned int)(v4269 + 4) >> 2)) >> 1);
      v4331[v4469] = v4493;
      int * v4333 = v4265->cache_dirty;
      v4333[v4469] = 0;
      int * v4335 = v4265->cache_age;
      v4335[v4469] = 1;
      int * v4337 = v4265->cache_age;
      int v4338 = v4337[v4469];
      int v4339 = v4337[v4443];
      int v4499 = v4339 + ((int)((unsigned int)(v4339 - v4338) >> 31));
      v4337[v4443] = v4499;
      int * v4341 = v4265->cache_age;
      int v4342 = v4341[v4444];
      int v4501 = v4342 + ((int)((unsigned int)(v4342 - v4338) >> 31));
      v4341[v4444] = v4501;
      int * v4344 = v4265->cache_age;
      v4344[v4469] = 0;
      v4347 = v4469;
    }
    int * v4348 = v4265->cache_vals;
    int v4504 = v4347 * 2;
    int v4349 = v4348[v4504];
    int v4505 = (v4347 * 2) + 1;
    int v4350 = v4348[v4505];
    int v4506 = (((((int)((unsigned int)((int)((unsigned int)(v4269 + 4) >> 2)) >> 1)) & 1) * 2) + ((((v4289 + ((~(((v4291 ^ -1) | (-(v4291 ^ -1))) >> 31)) & 2)) - (v4292 + ((~(((v4293 ^ -1) | (-(v4293 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
    v4348[v4506] = v4349;
    int * v4352 = v4265->cache_vals;
    int v4509 = ((((((int)((unsigned int)((int)((unsigned int)(v4269 + 4) >> 2)) >> 1)) & 1) * 2) + ((((v4289 + ((~(((v4291 ^ -1) | (-(v4291 ^ -1))) >> 31)) & 2)) - (v4292 + ((~(((v4293 ^ -1) | (-(v4293 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
    v4352[v4509] = v4350;
    int * v4354 = v4265->cache_tags;
    int v4512 = ((((int)((unsigned int)((int)((unsigned int)(v4269 + 4) >> 2)) >> 1)) & 1) * 2) + ((((v4289 + ((~(((v4291 ^ -1) | (-(v4291 ^ -1))) >> 31)) & 2)) - (v4292 + ((~(((v4293 ^ -1) | (-(v4293 ^ -1))) >> 31)) & 2))) >> 31) & 1);
    int v4513 = (int)((unsigned int)((int)((unsigned int)(v4269 + 4) >> 2)) >> 1);
    v4354[v4512] = v4513;
    int * v4356 = v4265->cache_dirty;
    v4356[v4512] = 0;
    int * v4358 = v4265->cache_age;
    v4358[v4512] = 1;
    int * v4360 = v4265->cache_age;
    int v4361 = v4360[v4512];
    int v4362 = v4360[v4441];
    int v4519 = v4362 + ((int)((unsigned int)(v4362 - v4361) >> 31));
    v4360[v4441] = v4519;
    int * v4364 = v4265->cache_age;
    int v4365 = v4364[v4442];
    int v4521 = v4365 + ((int)((unsigned int)(v4365 - v4361) >> 31));
    v4364[v4442] = v4521;
    int * v4367 = v4265->cache_age;
    v4367[v4512] = 0;
    v4370 = v4512;
  }
  int * v4371 = v4265->cache_vals;
  int v4524 = (v4370 * 2) + (((int)((unsigned int)(v4269 + 4) >> 2)) & 1);
  v4371[v4524] = v4270;
  int * v4373 = v4265->cache_tags;
  int v4374 = v4373[v4443];
  int v4375 = v4373[v4444];
  bool v4527 = !(((~(((v4374 ^ ((int)((unsigned int)((int)((unsigned int)(v4269 + 4) >> 2)) >> 1))) | (-(v4374 ^ ((int)((unsigned int)((int)((unsigned int)(v4269 + 4) >> 2)) >> 1))))) >> 31)) | (~(((v4375 ^ ((int)((unsigned int)((int)((unsigned int)(v4269 + 4) >> 2)) >> 1))) | (-(v4375 ^ ((int)((unsigned int)((int)((unsigned int)(v4269 + 4) >> 2)) >> 1))))) >> 31))) == 0);
  int v4429;
  if (v4527) {
    int * v4376 = v4265->cache_age;
    int v4529 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v4269 + 4) >> 2)) >> 1)) & 3) * 2)) + ((~(((v4375 ^ ((int)((unsigned int)((int)((unsigned int)(v4269 + 4) >> 2)) >> 1))) | (-(v4375 ^ ((int)((unsigned int)((int)((unsigned int)(v4269 + 4) >> 2)) >> 1))))) >> 31)) & 1);
    int v4377 = v4376[v4529];
    int v4378 = v4376[v4443];
    int v4530 = v4378 + ((int)((unsigned int)(v4378 - v4377) >> 31));
    v4376[v4443] = v4530;
    int * v4380 = v4265->cache_age;
    int v4381 = v4380[v4444];
    int v4532 = v4381 + ((int)((unsigned int)(v4381 - v4377) >> 31));
    v4380[v4444] = v4532;
    int * v4383 = v4265->cache_age;
    v4383[v4529] = 0;
    v4429 = v4529;
  } else {
    int * v4386 = v4265->cache_age;
    int v4536 = 4 + ((((int)((unsigned int)((int)((unsigned int)(v4269 + 4) >> 2)) >> 1)) & 3) * 2);
    int v4387 = v4386[v4536];
    int * v4388 = v4265->cache_tags;
    int v4389 = v4388[v4536];
    int v4390 = v4386[v4444];
    int v4391 = v4388[v4444];
    int * v4392 = v4265->cache_dirty;
    int v4539 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v4269 + 4) >> 2)) >> 1)) & 3) * 2)) + ((((v4387 + ((~(((v4389 ^ -1) | (-(v4389 ^ -1))) >> 31)) & 2)) - (v4390 + ((~(((v4391 ^ -1) | (-(v4391 ^ -1))) >> 31)) & 2))) >> 31) & 1);
    int v4393 = v4392[v4539];
    bool v4540 = !(v4393 == 0);
    if (v4540) {
      int * v4394 = v4265->cache_tags;
      int v4395 = v4394[v4539];
      int * v4396 = v4265->cache_vals;
      int v4543 = ((4 + ((((int)((unsigned int)((int)((unsigned int)(v4269 + 4) >> 2)) >> 1)) & 3) * 2)) + ((((v4387 + ((~(((v4389 ^ -1) | (-(v4389 ^ -1))) >> 31)) & 2)) - (v4390 + ((~(((v4391 ^ -1) | (-(v4391 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
      int v4397 = v4396[v4543];
      int v4544 = (((4 + ((((int)((unsigned int)((int)((unsigned int)(v4269 + 4) >> 2)) >> 1)) & 3) * 2)) + ((((v4387 + ((~(((v4389 ^ -1) | (-(v4389 ^ -1))) >> 31)) & 2)) - (v4390 + ((~(((v4391 ^ -1) | (-(v4391 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
      int v4398 = v4396[v4544];
      int * v4399 = v4265->mem;
      int v4546 = v4395 * 2;
      v4399[v4546] = v4397;
      int * v4401 = v4265->mem;
      int v4549 = (v4395 * 2) + 1;
      v4401[v4549] = v4398;
      ;
    } else {
      ;
    }
    int * v4406 = v4265->mem;
    int v4554 = ((int)((unsigned int)((int)((unsigned int)(v4269 + 4) >> 2)) >> 1)) * 2;
    int v4407 = v4406[v4554];
    int v4555 = (((int)((unsigned int)((int)((unsigned int)(v4269 + 4) >> 2)) >> 1)) * 2) + 1;
    int v4408 = v4406[v4555];
    int * v4409 = v4265->cache_vals;
    int v4557 = ((4 + ((((int)((unsigned int)((int)((unsigned int)(v4269 + 4) >> 2)) >> 1)) & 3) * 2)) + ((((v4387 + ((~(((v4389 ^ -1) | (-(v4389 ^ -1))) >> 31)) & 2)) - (v4390 + ((~(((v4391 ^ -1) | (-(v4391 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
    v4409[v4557] = v4407;
    int * v4411 = v4265->cache_vals;
    int v4560 = (((4 + ((((int)((unsigned int)((int)((unsigned int)(v4269 + 4) >> 2)) >> 1)) & 3) * 2)) + ((((v4387 + ((~(((v4389 ^ -1) | (-(v4389 ^ -1))) >> 31)) & 2)) - (v4390 + ((~(((v4391 ^ -1) | (-(v4391 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
    v4411[v4560] = v4408;
    int * v4413 = v4265->cache_tags;
    int v4563 = (int)((unsigned int)((int)((unsigned int)(v4269 + 4) >> 2)) >> 1);
    v4413[v4539] = v4563;
    int * v4415 = v4265->cache_dirty;
    v4415[v4539] = 0;
    int * v4417 = v4265->cache_age;
    v4417[v4539] = 1;
    int * v4419 = v4265->cache_age;
    int v4420 = v4419[v4539];
    int v4421 = v4419[v4443];
    int v4569 = v4421 + ((int)((unsigned int)(v4421 - v4420) >> 31));
    v4419[v4443] = v4569;
    int * v4423 = v4265->cache_age;
    int v4424 = v4423[v4444];
    int v4571 = v4424 + ((int)((unsigned int)(v4424 - v4420) >> 31));
    v4423[v4444] = v4571;
    int * v4426 = v4265->cache_age;
    v4426[v4539] = 0;
    v4429 = v4539;
  }
  int * v4430 = v4265->cache_vals;
  int v4574 = (v4429 * 2) + (((int)((unsigned int)(v4269 + 4) >> 2)) & 1);
  v4430[v4574] = v4270;
  int * v4432 = v4265->cache_dirty;
  v4432[v4429] = 1;
  struct StateT * v4434 = slot_55(v4265);
  return v4434;
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

struct StateT * slot_65(struct StateT * v5714) {
  int v5715 = v5714->timer;
  int v5722 = v5715 + 1;
  v5714->timer = v5722;
  int * v5717 = v5714->regs;
  int v5718 = v5717[14];
  int v5725 = v5718 + 1;
  v5717[14] = v5725;
  struct StateT * v5720 = slot_66(v5714);
  return v5720;
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

struct StateT * slot_74(struct StateT * v6642) {
  int v6643 = v6642->timer;
  int v6651 = v6643 + 1;
  v6642->timer = v6651;
  int * v6645 = v6642->regs;
  int v6646 = v6645[6];
  int v6647 = v6645[5];
  int v6655 = v6646 ^ v6647;
  v6645[6] = v6655;
  struct StateT * v6649 = slot_75(v6642);
  return v6649;
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

struct StateT * slot_58(struct StateT * v5004) {
  int v5005 = v5004->timer;
  int v5013 = v5005 + 1;
  v5004->timer = v5013;
  int * v5007 = v5004->regs;
  int v5008 = v5007[17];
  int v5009 = v5007[6];
  int v5017 = v5008 ^ v5009;
  v5007[17] = v5017;
  struct StateT * v5011 = slot_59(v5004);
  return v5011;
}

struct StateT * slot_67(struct StateT * v5736) {
  int * v5737 = v5736->saved_regs;
  int * v5738 = v5736->regs;
  int v5739 = v5738[15];
  v5737[15] = v5739;
  int v5741 = v5736->timer;
  int v5752 = v5741 + 1;
  v5736->timer = v5752;
  int * v5743 = v5736->regs;
  int v5744 = v5743[14];
  int v5755 = v5744 << 3;
  v5743[15] = v5755;
  struct StateT * v5746 = slot_68(v5736);
  return v5746;
}

struct StateT * slot_64(struct StateT * v5399) {
  int v5400 = v5399->timer;
  int v5570 = v5400 + 1;
  v5399->timer = v5570;
  int * v5402 = v5399->regs;
  int v5403 = v5402[15];
  int v5404 = v5402[16];
  int * v5405 = v5399->cache_tags;
  int v5575 = (((int)((unsigned int)((int)((unsigned int)(v5403 + 4) >> 2)) >> 1)) & 1) * 2;
  int v5406 = v5405[v5575];
  int v5576 = ((((int)((unsigned int)((int)((unsigned int)(v5403 + 4) >> 2)) >> 1)) & 1) * 2) + 1;
  int v5407 = v5405[v5576];
  int v5577 = 4 + ((((int)((unsigned int)((int)((unsigned int)(v5403 + 4) >> 2)) >> 1)) & 3) * 2);
  int v5408 = v5405[v5577];
  int v5578 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v5403 + 4) >> 2)) >> 1)) & 3) * 2)) + 1;
  int v5409 = v5405[v5578];
  int v5410 = v5399->timer;
  int v5579 = v5410 + ((100 ^ (((~(((v5408 ^ ((int)((unsigned int)((int)((unsigned int)(v5403 + 4) >> 2)) >> 1))) | (-(v5408 ^ ((int)((unsigned int)((int)((unsigned int)(v5403 + 4) >> 2)) >> 1))))) >> 31)) | (~(((v5409 ^ ((int)((unsigned int)((int)((unsigned int)(v5403 + 4) >> 2)) >> 1))) | (-(v5409 ^ ((int)((unsigned int)((int)((unsigned int)(v5403 + 4) >> 2)) >> 1))))) >> 31))) & 104)) ^ (((~(((v5406 ^ ((int)((unsigned int)((int)((unsigned int)(v5403 + 4) >> 2)) >> 1))) | (-(v5406 ^ ((int)((unsigned int)((int)((unsigned int)(v5403 + 4) >> 2)) >> 1))))) >> 31)) | (~(((v5407 ^ ((int)((unsigned int)((int)((unsigned int)(v5403 + 4) >> 2)) >> 1))) | (-(v5407 ^ ((int)((unsigned int)((int)((unsigned int)(v5403 + 4) >> 2)) >> 1))))) >> 31))) & (1 ^ (100 ^ (((~(((v5408 ^ ((int)((unsigned int)((int)((unsigned int)(v5403 + 4) >> 2)) >> 1))) | (-(v5408 ^ ((int)((unsigned int)((int)((unsigned int)(v5403 + 4) >> 2)) >> 1))))) >> 31)) | (~(((v5409 ^ ((int)((unsigned int)((int)((unsigned int)(v5403 + 4) >> 2)) >> 1))) | (-(v5409 ^ ((int)((unsigned int)((int)((unsigned int)(v5403 + 4) >> 2)) >> 1))))) >> 31))) & 104)))));
  v5399->timer = v5579;
  bool v5580 = !(((~(((v5406 ^ ((int)((unsigned int)((int)((unsigned int)(v5403 + 4) >> 2)) >> 1))) | (-(v5406 ^ ((int)((unsigned int)((int)((unsigned int)(v5403 + 4) >> 2)) >> 1))))) >> 31)) | (~(((v5407 ^ ((int)((unsigned int)((int)((unsigned int)(v5403 + 4) >> 2)) >> 1))) | (-(v5407 ^ ((int)((unsigned int)((int)((unsigned int)(v5403 + 4) >> 2)) >> 1))))) >> 31))) == 0);
  int v5504;
  if (v5580) {
    int * v5412 = v5399->cache_age;
    int v5582 = ((((int)((unsigned int)((int)((unsigned int)(v5403 + 4) >> 2)) >> 1)) & 1) * 2) + ((~(((v5407 ^ ((int)((unsigned int)((int)((unsigned int)(v5403 + 4) >> 2)) >> 1))) | (-(v5407 ^ ((int)((unsigned int)((int)((unsigned int)(v5403 + 4) >> 2)) >> 1))))) >> 31)) & 1);
    int v5413 = v5412[v5582];
    int v5414 = v5412[v5575];
    int v5583 = v5414 + ((int)((unsigned int)(v5414 - v5413) >> 31));
    v5412[v5575] = v5583;
    int * v5416 = v5399->cache_age;
    int v5417 = v5416[v5576];
    int v5585 = v5417 + ((int)((unsigned int)(v5417 - v5413) >> 31));
    v5416[v5576] = v5585;
    int * v5419 = v5399->cache_age;
    v5419[v5582] = 0;
    v5504 = v5582;
  } else {
    int * v5422 = v5399->cache_age;
    int v5589 = (((int)((unsigned int)((int)((unsigned int)(v5403 + 4) >> 2)) >> 1)) & 1) * 2;
    int v5423 = v5422[v5589];
    int * v5424 = v5399->cache_tags;
    int v5425 = v5424[v5589];
    int v5426 = v5422[v5576];
    int v5427 = v5424[v5576];
    bool v5591 = !(((~(((v5408 ^ ((int)((unsigned int)((int)((unsigned int)(v5403 + 4) >> 2)) >> 1))) | (-(v5408 ^ ((int)((unsigned int)((int)((unsigned int)(v5403 + 4) >> 2)) >> 1))))) >> 31)) | (~(((v5409 ^ ((int)((unsigned int)((int)((unsigned int)(v5403 + 4) >> 2)) >> 1))) | (-(v5409 ^ ((int)((unsigned int)((int)((unsigned int)(v5403 + 4) >> 2)) >> 1))))) >> 31))) == 0);
    int v5481;
    if (v5591) {
      int * v5428 = v5399->cache_age;
      int v5593 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v5403 + 4) >> 2)) >> 1)) & 3) * 2)) + ((~(((v5409 ^ ((int)((unsigned int)((int)((unsigned int)(v5403 + 4) >> 2)) >> 1))) | (-(v5409 ^ ((int)((unsigned int)((int)((unsigned int)(v5403 + 4) >> 2)) >> 1))))) >> 31)) & 1);
      int v5429 = v5428[v5593];
      int v5430 = v5428[v5577];
      int v5594 = v5430 + ((int)((unsigned int)(v5430 - v5429) >> 31));
      v5428[v5577] = v5594;
      int * v5432 = v5399->cache_age;
      int v5433 = v5432[v5578];
      int v5596 = v5433 + ((int)((unsigned int)(v5433 - v5429) >> 31));
      v5432[v5578] = v5596;
      int * v5435 = v5399->cache_age;
      v5435[v5593] = 0;
      v5481 = v5593;
    } else {
      int * v5438 = v5399->cache_age;
      int v5600 = 4 + ((((int)((unsigned int)((int)((unsigned int)(v5403 + 4) >> 2)) >> 1)) & 3) * 2);
      int v5439 = v5438[v5600];
      int * v5440 = v5399->cache_tags;
      int v5441 = v5440[v5600];
      int v5442 = v5438[v5578];
      int v5443 = v5440[v5578];
      int * v5444 = v5399->cache_dirty;
      int v5603 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v5403 + 4) >> 2)) >> 1)) & 3) * 2)) + ((((v5439 + ((~(((v5441 ^ -1) | (-(v5441 ^ -1))) >> 31)) & 2)) - (v5442 + ((~(((v5443 ^ -1) | (-(v5443 ^ -1))) >> 31)) & 2))) >> 31) & 1);
      int v5445 = v5444[v5603];
      bool v5604 = !(v5445 == 0);
      if (v5604) {
        int * v5446 = v5399->cache_tags;
        int v5447 = v5446[v5603];
        int * v5448 = v5399->cache_vals;
        int v5607 = ((4 + ((((int)((unsigned int)((int)((unsigned int)(v5403 + 4) >> 2)) >> 1)) & 3) * 2)) + ((((v5439 + ((~(((v5441 ^ -1) | (-(v5441 ^ -1))) >> 31)) & 2)) - (v5442 + ((~(((v5443 ^ -1) | (-(v5443 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
        int v5449 = v5448[v5607];
        int v5608 = (((4 + ((((int)((unsigned int)((int)((unsigned int)(v5403 + 4) >> 2)) >> 1)) & 3) * 2)) + ((((v5439 + ((~(((v5441 ^ -1) | (-(v5441 ^ -1))) >> 31)) & 2)) - (v5442 + ((~(((v5443 ^ -1) | (-(v5443 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
        int v5450 = v5448[v5608];
        int * v5451 = v5399->mem;
        int v5610 = v5447 * 2;
        v5451[v5610] = v5449;
        int * v5453 = v5399->mem;
        int v5613 = (v5447 * 2) + 1;
        v5453[v5613] = v5450;
        ;
      } else {
        ;
      }
      int * v5458 = v5399->mem;
      int v5618 = ((int)((unsigned int)((int)((unsigned int)(v5403 + 4) >> 2)) >> 1)) * 2;
      int v5459 = v5458[v5618];
      int v5619 = (((int)((unsigned int)((int)((unsigned int)(v5403 + 4) >> 2)) >> 1)) * 2) + 1;
      int v5460 = v5458[v5619];
      int * v5461 = v5399->cache_vals;
      int v5621 = ((4 + ((((int)((unsigned int)((int)((unsigned int)(v5403 + 4) >> 2)) >> 1)) & 3) * 2)) + ((((v5439 + ((~(((v5441 ^ -1) | (-(v5441 ^ -1))) >> 31)) & 2)) - (v5442 + ((~(((v5443 ^ -1) | (-(v5443 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
      v5461[v5621] = v5459;
      int * v5463 = v5399->cache_vals;
      int v5624 = (((4 + ((((int)((unsigned int)((int)((unsigned int)(v5403 + 4) >> 2)) >> 1)) & 3) * 2)) + ((((v5439 + ((~(((v5441 ^ -1) | (-(v5441 ^ -1))) >> 31)) & 2)) - (v5442 + ((~(((v5443 ^ -1) | (-(v5443 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
      v5463[v5624] = v5460;
      int * v5465 = v5399->cache_tags;
      int v5627 = (int)((unsigned int)((int)((unsigned int)(v5403 + 4) >> 2)) >> 1);
      v5465[v5603] = v5627;
      int * v5467 = v5399->cache_dirty;
      v5467[v5603] = 0;
      int * v5469 = v5399->cache_age;
      v5469[v5603] = 1;
      int * v5471 = v5399->cache_age;
      int v5472 = v5471[v5603];
      int v5473 = v5471[v5577];
      int v5633 = v5473 + ((int)((unsigned int)(v5473 - v5472) >> 31));
      v5471[v5577] = v5633;
      int * v5475 = v5399->cache_age;
      int v5476 = v5475[v5578];
      int v5635 = v5476 + ((int)((unsigned int)(v5476 - v5472) >> 31));
      v5475[v5578] = v5635;
      int * v5478 = v5399->cache_age;
      v5478[v5603] = 0;
      v5481 = v5603;
    }
    int * v5482 = v5399->cache_vals;
    int v5638 = v5481 * 2;
    int v5483 = v5482[v5638];
    int v5639 = (v5481 * 2) + 1;
    int v5484 = v5482[v5639];
    int v5640 = (((((int)((unsigned int)((int)((unsigned int)(v5403 + 4) >> 2)) >> 1)) & 1) * 2) + ((((v5423 + ((~(((v5425 ^ -1) | (-(v5425 ^ -1))) >> 31)) & 2)) - (v5426 + ((~(((v5427 ^ -1) | (-(v5427 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
    v5482[v5640] = v5483;
    int * v5486 = v5399->cache_vals;
    int v5643 = ((((((int)((unsigned int)((int)((unsigned int)(v5403 + 4) >> 2)) >> 1)) & 1) * 2) + ((((v5423 + ((~(((v5425 ^ -1) | (-(v5425 ^ -1))) >> 31)) & 2)) - (v5426 + ((~(((v5427 ^ -1) | (-(v5427 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
    v5486[v5643] = v5484;
    int * v5488 = v5399->cache_tags;
    int v5646 = ((((int)((unsigned int)((int)((unsigned int)(v5403 + 4) >> 2)) >> 1)) & 1) * 2) + ((((v5423 + ((~(((v5425 ^ -1) | (-(v5425 ^ -1))) >> 31)) & 2)) - (v5426 + ((~(((v5427 ^ -1) | (-(v5427 ^ -1))) >> 31)) & 2))) >> 31) & 1);
    int v5647 = (int)((unsigned int)((int)((unsigned int)(v5403 + 4) >> 2)) >> 1);
    v5488[v5646] = v5647;
    int * v5490 = v5399->cache_dirty;
    v5490[v5646] = 0;
    int * v5492 = v5399->cache_age;
    v5492[v5646] = 1;
    int * v5494 = v5399->cache_age;
    int v5495 = v5494[v5646];
    int v5496 = v5494[v5575];
    int v5653 = v5496 + ((int)((unsigned int)(v5496 - v5495) >> 31));
    v5494[v5575] = v5653;
    int * v5498 = v5399->cache_age;
    int v5499 = v5498[v5576];
    int v5655 = v5499 + ((int)((unsigned int)(v5499 - v5495) >> 31));
    v5498[v5576] = v5655;
    int * v5501 = v5399->cache_age;
    v5501[v5646] = 0;
    v5504 = v5646;
  }
  int * v5505 = v5399->cache_vals;
  int v5658 = (v5504 * 2) + (((int)((unsigned int)(v5403 + 4) >> 2)) & 1);
  v5505[v5658] = v5404;
  int * v5507 = v5399->cache_tags;
  int v5508 = v5507[v5577];
  int v5509 = v5507[v5578];
  bool v5661 = !(((~(((v5508 ^ ((int)((unsigned int)((int)((unsigned int)(v5403 + 4) >> 2)) >> 1))) | (-(v5508 ^ ((int)((unsigned int)((int)((unsigned int)(v5403 + 4) >> 2)) >> 1))))) >> 31)) | (~(((v5509 ^ ((int)((unsigned int)((int)((unsigned int)(v5403 + 4) >> 2)) >> 1))) | (-(v5509 ^ ((int)((unsigned int)((int)((unsigned int)(v5403 + 4) >> 2)) >> 1))))) >> 31))) == 0);
  int v5563;
  if (v5661) {
    int * v5510 = v5399->cache_age;
    int v5663 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v5403 + 4) >> 2)) >> 1)) & 3) * 2)) + ((~(((v5509 ^ ((int)((unsigned int)((int)((unsigned int)(v5403 + 4) >> 2)) >> 1))) | (-(v5509 ^ ((int)((unsigned int)((int)((unsigned int)(v5403 + 4) >> 2)) >> 1))))) >> 31)) & 1);
    int v5511 = v5510[v5663];
    int v5512 = v5510[v5577];
    int v5664 = v5512 + ((int)((unsigned int)(v5512 - v5511) >> 31));
    v5510[v5577] = v5664;
    int * v5514 = v5399->cache_age;
    int v5515 = v5514[v5578];
    int v5666 = v5515 + ((int)((unsigned int)(v5515 - v5511) >> 31));
    v5514[v5578] = v5666;
    int * v5517 = v5399->cache_age;
    v5517[v5663] = 0;
    v5563 = v5663;
  } else {
    int * v5520 = v5399->cache_age;
    int v5670 = 4 + ((((int)((unsigned int)((int)((unsigned int)(v5403 + 4) >> 2)) >> 1)) & 3) * 2);
    int v5521 = v5520[v5670];
    int * v5522 = v5399->cache_tags;
    int v5523 = v5522[v5670];
    int v5524 = v5520[v5578];
    int v5525 = v5522[v5578];
    int * v5526 = v5399->cache_dirty;
    int v5673 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v5403 + 4) >> 2)) >> 1)) & 3) * 2)) + ((((v5521 + ((~(((v5523 ^ -1) | (-(v5523 ^ -1))) >> 31)) & 2)) - (v5524 + ((~(((v5525 ^ -1) | (-(v5525 ^ -1))) >> 31)) & 2))) >> 31) & 1);
    int v5527 = v5526[v5673];
    bool v5674 = !(v5527 == 0);
    if (v5674) {
      int * v5528 = v5399->cache_tags;
      int v5529 = v5528[v5673];
      int * v5530 = v5399->cache_vals;
      int v5677 = ((4 + ((((int)((unsigned int)((int)((unsigned int)(v5403 + 4) >> 2)) >> 1)) & 3) * 2)) + ((((v5521 + ((~(((v5523 ^ -1) | (-(v5523 ^ -1))) >> 31)) & 2)) - (v5524 + ((~(((v5525 ^ -1) | (-(v5525 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
      int v5531 = v5530[v5677];
      int v5678 = (((4 + ((((int)((unsigned int)((int)((unsigned int)(v5403 + 4) >> 2)) >> 1)) & 3) * 2)) + ((((v5521 + ((~(((v5523 ^ -1) | (-(v5523 ^ -1))) >> 31)) & 2)) - (v5524 + ((~(((v5525 ^ -1) | (-(v5525 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
      int v5532 = v5530[v5678];
      int * v5533 = v5399->mem;
      int v5680 = v5529 * 2;
      v5533[v5680] = v5531;
      int * v5535 = v5399->mem;
      int v5683 = (v5529 * 2) + 1;
      v5535[v5683] = v5532;
      ;
    } else {
      ;
    }
    int * v5540 = v5399->mem;
    int v5688 = ((int)((unsigned int)((int)((unsigned int)(v5403 + 4) >> 2)) >> 1)) * 2;
    int v5541 = v5540[v5688];
    int v5689 = (((int)((unsigned int)((int)((unsigned int)(v5403 + 4) >> 2)) >> 1)) * 2) + 1;
    int v5542 = v5540[v5689];
    int * v5543 = v5399->cache_vals;
    int v5691 = ((4 + ((((int)((unsigned int)((int)((unsigned int)(v5403 + 4) >> 2)) >> 1)) & 3) * 2)) + ((((v5521 + ((~(((v5523 ^ -1) | (-(v5523 ^ -1))) >> 31)) & 2)) - (v5524 + ((~(((v5525 ^ -1) | (-(v5525 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
    v5543[v5691] = v5541;
    int * v5545 = v5399->cache_vals;
    int v5694 = (((4 + ((((int)((unsigned int)((int)((unsigned int)(v5403 + 4) >> 2)) >> 1)) & 3) * 2)) + ((((v5521 + ((~(((v5523 ^ -1) | (-(v5523 ^ -1))) >> 31)) & 2)) - (v5524 + ((~(((v5525 ^ -1) | (-(v5525 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
    v5545[v5694] = v5542;
    int * v5547 = v5399->cache_tags;
    int v5697 = (int)((unsigned int)((int)((unsigned int)(v5403 + 4) >> 2)) >> 1);
    v5547[v5673] = v5697;
    int * v5549 = v5399->cache_dirty;
    v5549[v5673] = 0;
    int * v5551 = v5399->cache_age;
    v5551[v5673] = 1;
    int * v5553 = v5399->cache_age;
    int v5554 = v5553[v5673];
    int v5555 = v5553[v5577];
    int v5703 = v5555 + ((int)((unsigned int)(v5555 - v5554) >> 31));
    v5553[v5577] = v5703;
    int * v5557 = v5399->cache_age;
    int v5558 = v5557[v5578];
    int v5705 = v5558 + ((int)((unsigned int)(v5558 - v5554) >> 31));
    v5557[v5578] = v5705;
    int * v5560 = v5399->cache_age;
    v5560[v5673] = 0;
    v5563 = v5673;
  }
  int * v5564 = v5399->cache_vals;
  int v5708 = (v5563 * 2) + (((int)((unsigned int)(v5403 + 4) >> 2)) & 1);
  v5564[v5708] = v5404;
  int * v5566 = v5399->cache_dirty;
  v5566[v5563] = 1;
  struct StateT * v5568 = slot_65(v5399);
  return v5568;
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

struct StateT * slot_53(struct StateT * v3950) {
  int v3951 = v3950->timer;
  int v4121 = v3951 + 1;
  v3950->timer = v4121;
  int * v3953 = v3950->regs;
  int v3954 = v3953[16];
  int v3955 = v3953[7];
  int * v3956 = v3950->cache_tags;
  int v4126 = (((int)((unsigned int)((int)((unsigned int)v3954 >> 2)) >> 1)) & 1) * 2;
  int v3957 = v3956[v4126];
  int v4127 = ((((int)((unsigned int)((int)((unsigned int)v3954 >> 2)) >> 1)) & 1) * 2) + 1;
  int v3958 = v3956[v4127];
  int v4128 = 4 + ((((int)((unsigned int)((int)((unsigned int)v3954 >> 2)) >> 1)) & 3) * 2);
  int v3959 = v3956[v4128];
  int v4129 = (4 + ((((int)((unsigned int)((int)((unsigned int)v3954 >> 2)) >> 1)) & 3) * 2)) + 1;
  int v3960 = v3956[v4129];
  int v3961 = v3950->timer;
  int v4130 = v3961 + ((100 ^ (((~(((v3959 ^ ((int)((unsigned int)((int)((unsigned int)v3954 >> 2)) >> 1))) | (-(v3959 ^ ((int)((unsigned int)((int)((unsigned int)v3954 >> 2)) >> 1))))) >> 31)) | (~(((v3960 ^ ((int)((unsigned int)((int)((unsigned int)v3954 >> 2)) >> 1))) | (-(v3960 ^ ((int)((unsigned int)((int)((unsigned int)v3954 >> 2)) >> 1))))) >> 31))) & 104)) ^ (((~(((v3957 ^ ((int)((unsigned int)((int)((unsigned int)v3954 >> 2)) >> 1))) | (-(v3957 ^ ((int)((unsigned int)((int)((unsigned int)v3954 >> 2)) >> 1))))) >> 31)) | (~(((v3958 ^ ((int)((unsigned int)((int)((unsigned int)v3954 >> 2)) >> 1))) | (-(v3958 ^ ((int)((unsigned int)((int)((unsigned int)v3954 >> 2)) >> 1))))) >> 31))) & (1 ^ (100 ^ (((~(((v3959 ^ ((int)((unsigned int)((int)((unsigned int)v3954 >> 2)) >> 1))) | (-(v3959 ^ ((int)((unsigned int)((int)((unsigned int)v3954 >> 2)) >> 1))))) >> 31)) | (~(((v3960 ^ ((int)((unsigned int)((int)((unsigned int)v3954 >> 2)) >> 1))) | (-(v3960 ^ ((int)((unsigned int)((int)((unsigned int)v3954 >> 2)) >> 1))))) >> 31))) & 104)))));
  v3950->timer = v4130;
  bool v4131 = !(((~(((v3957 ^ ((int)((unsigned int)((int)((unsigned int)v3954 >> 2)) >> 1))) | (-(v3957 ^ ((int)((unsigned int)((int)((unsigned int)v3954 >> 2)) >> 1))))) >> 31)) | (~(((v3958 ^ ((int)((unsigned int)((int)((unsigned int)v3954 >> 2)) >> 1))) | (-(v3958 ^ ((int)((unsigned int)((int)((unsigned int)v3954 >> 2)) >> 1))))) >> 31))) == 0);
  int v4055;
  if (v4131) {
    int * v3963 = v3950->cache_age;
    int v4133 = ((((int)((unsigned int)((int)((unsigned int)v3954 >> 2)) >> 1)) & 1) * 2) + ((~(((v3958 ^ ((int)((unsigned int)((int)((unsigned int)v3954 >> 2)) >> 1))) | (-(v3958 ^ ((int)((unsigned int)((int)((unsigned int)v3954 >> 2)) >> 1))))) >> 31)) & 1);
    int v3964 = v3963[v4133];
    int v3965 = v3963[v4126];
    int v4134 = v3965 + ((int)((unsigned int)(v3965 - v3964) >> 31));
    v3963[v4126] = v4134;
    int * v3967 = v3950->cache_age;
    int v3968 = v3967[v4127];
    int v4136 = v3968 + ((int)((unsigned int)(v3968 - v3964) >> 31));
    v3967[v4127] = v4136;
    int * v3970 = v3950->cache_age;
    v3970[v4133] = 0;
    v4055 = v4133;
  } else {
    int * v3973 = v3950->cache_age;
    int v4140 = (((int)((unsigned int)((int)((unsigned int)v3954 >> 2)) >> 1)) & 1) * 2;
    int v3974 = v3973[v4140];
    int * v3975 = v3950->cache_tags;
    int v3976 = v3975[v4140];
    int v3977 = v3973[v4127];
    int v3978 = v3975[v4127];
    bool v4142 = !(((~(((v3959 ^ ((int)((unsigned int)((int)((unsigned int)v3954 >> 2)) >> 1))) | (-(v3959 ^ ((int)((unsigned int)((int)((unsigned int)v3954 >> 2)) >> 1))))) >> 31)) | (~(((v3960 ^ ((int)((unsigned int)((int)((unsigned int)v3954 >> 2)) >> 1))) | (-(v3960 ^ ((int)((unsigned int)((int)((unsigned int)v3954 >> 2)) >> 1))))) >> 31))) == 0);
    int v4032;
    if (v4142) {
      int * v3979 = v3950->cache_age;
      int v4144 = (4 + ((((int)((unsigned int)((int)((unsigned int)v3954 >> 2)) >> 1)) & 3) * 2)) + ((~(((v3960 ^ ((int)((unsigned int)((int)((unsigned int)v3954 >> 2)) >> 1))) | (-(v3960 ^ ((int)((unsigned int)((int)((unsigned int)v3954 >> 2)) >> 1))))) >> 31)) & 1);
      int v3980 = v3979[v4144];
      int v3981 = v3979[v4128];
      int v4145 = v3981 + ((int)((unsigned int)(v3981 - v3980) >> 31));
      v3979[v4128] = v4145;
      int * v3983 = v3950->cache_age;
      int v3984 = v3983[v4129];
      int v4147 = v3984 + ((int)((unsigned int)(v3984 - v3980) >> 31));
      v3983[v4129] = v4147;
      int * v3986 = v3950->cache_age;
      v3986[v4144] = 0;
      v4032 = v4144;
    } else {
      int * v3989 = v3950->cache_age;
      int v4151 = 4 + ((((int)((unsigned int)((int)((unsigned int)v3954 >> 2)) >> 1)) & 3) * 2);
      int v3990 = v3989[v4151];
      int * v3991 = v3950->cache_tags;
      int v3992 = v3991[v4151];
      int v3993 = v3989[v4129];
      int v3994 = v3991[v4129];
      int * v3995 = v3950->cache_dirty;
      int v4154 = (4 + ((((int)((unsigned int)((int)((unsigned int)v3954 >> 2)) >> 1)) & 3) * 2)) + ((((v3990 + ((~(((v3992 ^ -1) | (-(v3992 ^ -1))) >> 31)) & 2)) - (v3993 + ((~(((v3994 ^ -1) | (-(v3994 ^ -1))) >> 31)) & 2))) >> 31) & 1);
      int v3996 = v3995[v4154];
      bool v4155 = !(v3996 == 0);
      if (v4155) {
        int * v3997 = v3950->cache_tags;
        int v3998 = v3997[v4154];
        int * v3999 = v3950->cache_vals;
        int v4158 = ((4 + ((((int)((unsigned int)((int)((unsigned int)v3954 >> 2)) >> 1)) & 3) * 2)) + ((((v3990 + ((~(((v3992 ^ -1) | (-(v3992 ^ -1))) >> 31)) & 2)) - (v3993 + ((~(((v3994 ^ -1) | (-(v3994 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
        int v4000 = v3999[v4158];
        int v4159 = (((4 + ((((int)((unsigned int)((int)((unsigned int)v3954 >> 2)) >> 1)) & 3) * 2)) + ((((v3990 + ((~(((v3992 ^ -1) | (-(v3992 ^ -1))) >> 31)) & 2)) - (v3993 + ((~(((v3994 ^ -1) | (-(v3994 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
        int v4001 = v3999[v4159];
        int * v4002 = v3950->mem;
        int v4161 = v3998 * 2;
        v4002[v4161] = v4000;
        int * v4004 = v3950->mem;
        int v4164 = (v3998 * 2) + 1;
        v4004[v4164] = v4001;
        ;
      } else {
        ;
      }
      int * v4009 = v3950->mem;
      int v4169 = ((int)((unsigned int)((int)((unsigned int)v3954 >> 2)) >> 1)) * 2;
      int v4010 = v4009[v4169];
      int v4170 = (((int)((unsigned int)((int)((unsigned int)v3954 >> 2)) >> 1)) * 2) + 1;
      int v4011 = v4009[v4170];
      int * v4012 = v3950->cache_vals;
      int v4172 = ((4 + ((((int)((unsigned int)((int)((unsigned int)v3954 >> 2)) >> 1)) & 3) * 2)) + ((((v3990 + ((~(((v3992 ^ -1) | (-(v3992 ^ -1))) >> 31)) & 2)) - (v3993 + ((~(((v3994 ^ -1) | (-(v3994 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
      v4012[v4172] = v4010;
      int * v4014 = v3950->cache_vals;
      int v4175 = (((4 + ((((int)((unsigned int)((int)((unsigned int)v3954 >> 2)) >> 1)) & 3) * 2)) + ((((v3990 + ((~(((v3992 ^ -1) | (-(v3992 ^ -1))) >> 31)) & 2)) - (v3993 + ((~(((v3994 ^ -1) | (-(v3994 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
      v4014[v4175] = v4011;
      int * v4016 = v3950->cache_tags;
      int v4178 = (int)((unsigned int)((int)((unsigned int)v3954 >> 2)) >> 1);
      v4016[v4154] = v4178;
      int * v4018 = v3950->cache_dirty;
      v4018[v4154] = 0;
      int * v4020 = v3950->cache_age;
      v4020[v4154] = 1;
      int * v4022 = v3950->cache_age;
      int v4023 = v4022[v4154];
      int v4024 = v4022[v4128];
      int v4184 = v4024 + ((int)((unsigned int)(v4024 - v4023) >> 31));
      v4022[v4128] = v4184;
      int * v4026 = v3950->cache_age;
      int v4027 = v4026[v4129];
      int v4186 = v4027 + ((int)((unsigned int)(v4027 - v4023) >> 31));
      v4026[v4129] = v4186;
      int * v4029 = v3950->cache_age;
      v4029[v4154] = 0;
      v4032 = v4154;
    }
    int * v4033 = v3950->cache_vals;
    int v4189 = v4032 * 2;
    int v4034 = v4033[v4189];
    int v4190 = (v4032 * 2) + 1;
    int v4035 = v4033[v4190];
    int v4191 = (((((int)((unsigned int)((int)((unsigned int)v3954 >> 2)) >> 1)) & 1) * 2) + ((((v3974 + ((~(((v3976 ^ -1) | (-(v3976 ^ -1))) >> 31)) & 2)) - (v3977 + ((~(((v3978 ^ -1) | (-(v3978 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
    v4033[v4191] = v4034;
    int * v4037 = v3950->cache_vals;
    int v4194 = ((((((int)((unsigned int)((int)((unsigned int)v3954 >> 2)) >> 1)) & 1) * 2) + ((((v3974 + ((~(((v3976 ^ -1) | (-(v3976 ^ -1))) >> 31)) & 2)) - (v3977 + ((~(((v3978 ^ -1) | (-(v3978 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
    v4037[v4194] = v4035;
    int * v4039 = v3950->cache_tags;
    int v4197 = ((((int)((unsigned int)((int)((unsigned int)v3954 >> 2)) >> 1)) & 1) * 2) + ((((v3974 + ((~(((v3976 ^ -1) | (-(v3976 ^ -1))) >> 31)) & 2)) - (v3977 + ((~(((v3978 ^ -1) | (-(v3978 ^ -1))) >> 31)) & 2))) >> 31) & 1);
    int v4198 = (int)((unsigned int)((int)((unsigned int)v3954 >> 2)) >> 1);
    v4039[v4197] = v4198;
    int * v4041 = v3950->cache_dirty;
    v4041[v4197] = 0;
    int * v4043 = v3950->cache_age;
    v4043[v4197] = 1;
    int * v4045 = v3950->cache_age;
    int v4046 = v4045[v4197];
    int v4047 = v4045[v4126];
    int v4204 = v4047 + ((int)((unsigned int)(v4047 - v4046) >> 31));
    v4045[v4126] = v4204;
    int * v4049 = v3950->cache_age;
    int v4050 = v4049[v4127];
    int v4206 = v4050 + ((int)((unsigned int)(v4050 - v4046) >> 31));
    v4049[v4127] = v4206;
    int * v4052 = v3950->cache_age;
    v4052[v4197] = 0;
    v4055 = v4197;
  }
  int * v4056 = v3950->cache_vals;
  int v4209 = (v4055 * 2) + (((int)((unsigned int)v3954 >> 2)) & 1);
  v4056[v4209] = v3955;
  int * v4058 = v3950->cache_tags;
  int v4059 = v4058[v4128];
  int v4060 = v4058[v4129];
  bool v4212 = !(((~(((v4059 ^ ((int)((unsigned int)((int)((unsigned int)v3954 >> 2)) >> 1))) | (-(v4059 ^ ((int)((unsigned int)((int)((unsigned int)v3954 >> 2)) >> 1))))) >> 31)) | (~(((v4060 ^ ((int)((unsigned int)((int)((unsigned int)v3954 >> 2)) >> 1))) | (-(v4060 ^ ((int)((unsigned int)((int)((unsigned int)v3954 >> 2)) >> 1))))) >> 31))) == 0);
  int v4114;
  if (v4212) {
    int * v4061 = v3950->cache_age;
    int v4214 = (4 + ((((int)((unsigned int)((int)((unsigned int)v3954 >> 2)) >> 1)) & 3) * 2)) + ((~(((v4060 ^ ((int)((unsigned int)((int)((unsigned int)v3954 >> 2)) >> 1))) | (-(v4060 ^ ((int)((unsigned int)((int)((unsigned int)v3954 >> 2)) >> 1))))) >> 31)) & 1);
    int v4062 = v4061[v4214];
    int v4063 = v4061[v4128];
    int v4215 = v4063 + ((int)((unsigned int)(v4063 - v4062) >> 31));
    v4061[v4128] = v4215;
    int * v4065 = v3950->cache_age;
    int v4066 = v4065[v4129];
    int v4217 = v4066 + ((int)((unsigned int)(v4066 - v4062) >> 31));
    v4065[v4129] = v4217;
    int * v4068 = v3950->cache_age;
    v4068[v4214] = 0;
    v4114 = v4214;
  } else {
    int * v4071 = v3950->cache_age;
    int v4221 = 4 + ((((int)((unsigned int)((int)((unsigned int)v3954 >> 2)) >> 1)) & 3) * 2);
    int v4072 = v4071[v4221];
    int * v4073 = v3950->cache_tags;
    int v4074 = v4073[v4221];
    int v4075 = v4071[v4129];
    int v4076 = v4073[v4129];
    int * v4077 = v3950->cache_dirty;
    int v4224 = (4 + ((((int)((unsigned int)((int)((unsigned int)v3954 >> 2)) >> 1)) & 3) * 2)) + ((((v4072 + ((~(((v4074 ^ -1) | (-(v4074 ^ -1))) >> 31)) & 2)) - (v4075 + ((~(((v4076 ^ -1) | (-(v4076 ^ -1))) >> 31)) & 2))) >> 31) & 1);
    int v4078 = v4077[v4224];
    bool v4225 = !(v4078 == 0);
    if (v4225) {
      int * v4079 = v3950->cache_tags;
      int v4080 = v4079[v4224];
      int * v4081 = v3950->cache_vals;
      int v4228 = ((4 + ((((int)((unsigned int)((int)((unsigned int)v3954 >> 2)) >> 1)) & 3) * 2)) + ((((v4072 + ((~(((v4074 ^ -1) | (-(v4074 ^ -1))) >> 31)) & 2)) - (v4075 + ((~(((v4076 ^ -1) | (-(v4076 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
      int v4082 = v4081[v4228];
      int v4229 = (((4 + ((((int)((unsigned int)((int)((unsigned int)v3954 >> 2)) >> 1)) & 3) * 2)) + ((((v4072 + ((~(((v4074 ^ -1) | (-(v4074 ^ -1))) >> 31)) & 2)) - (v4075 + ((~(((v4076 ^ -1) | (-(v4076 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
      int v4083 = v4081[v4229];
      int * v4084 = v3950->mem;
      int v4231 = v4080 * 2;
      v4084[v4231] = v4082;
      int * v4086 = v3950->mem;
      int v4234 = (v4080 * 2) + 1;
      v4086[v4234] = v4083;
      ;
    } else {
      ;
    }
    int * v4091 = v3950->mem;
    int v4239 = ((int)((unsigned int)((int)((unsigned int)v3954 >> 2)) >> 1)) * 2;
    int v4092 = v4091[v4239];
    int v4240 = (((int)((unsigned int)((int)((unsigned int)v3954 >> 2)) >> 1)) * 2) + 1;
    int v4093 = v4091[v4240];
    int * v4094 = v3950->cache_vals;
    int v4242 = ((4 + ((((int)((unsigned int)((int)((unsigned int)v3954 >> 2)) >> 1)) & 3) * 2)) + ((((v4072 + ((~(((v4074 ^ -1) | (-(v4074 ^ -1))) >> 31)) & 2)) - (v4075 + ((~(((v4076 ^ -1) | (-(v4076 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
    v4094[v4242] = v4092;
    int * v4096 = v3950->cache_vals;
    int v4245 = (((4 + ((((int)((unsigned int)((int)((unsigned int)v3954 >> 2)) >> 1)) & 3) * 2)) + ((((v4072 + ((~(((v4074 ^ -1) | (-(v4074 ^ -1))) >> 31)) & 2)) - (v4075 + ((~(((v4076 ^ -1) | (-(v4076 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
    v4096[v4245] = v4093;
    int * v4098 = v3950->cache_tags;
    int v4248 = (int)((unsigned int)((int)((unsigned int)v3954 >> 2)) >> 1);
    v4098[v4224] = v4248;
    int * v4100 = v3950->cache_dirty;
    v4100[v4224] = 0;
    int * v4102 = v3950->cache_age;
    v4102[v4224] = 1;
    int * v4104 = v3950->cache_age;
    int v4105 = v4104[v4224];
    int v4106 = v4104[v4128];
    int v4254 = v4106 + ((int)((unsigned int)(v4106 - v4105) >> 31));
    v4104[v4128] = v4254;
    int * v4108 = v3950->cache_age;
    int v4109 = v4108[v4129];
    int v4256 = v4109 + ((int)((unsigned int)(v4109 - v4105) >> 31));
    v4108[v4129] = v4256;
    int * v4111 = v3950->cache_age;
    v4111[v4224] = 0;
    v4114 = v4224;
  }
  int * v4115 = v3950->cache_vals;
  int v4259 = (v4114 * 2) + (((int)((unsigned int)v3954 >> 2)) & 1);
  v4115[v4259] = v3955;
  int * v4117 = v3950->cache_dirty;
  v4117[v4114] = 1;
  struct StateT * v4119 = slot_54(v3950);
  return v4119;
}

struct StateT * slot_80(struct StateT * v6738) {
  int * v6739 = v6738->regs;
  int v6740 = v6739[12];
  int v6741 = v6739[14];
  bool v6777 = (v6740 ^ -2147483648) >= (v6741 ^ -2147483648);
  struct StateT * v6772;
  if (v6777) {
    struct StateT * v6742 = slot_53(v6738);
    v6772 = v6742;
  } else {
    int v6744 = v6738->timer;
    int v6780 = v6744 + 15;
    v6738->timer = v6780;
    int * v6746 = v6738->saved_regs;
    int v6747 = v6746[15];
    int * v6748 = v6738->regs;
    v6748[15] = v6747;
    int * v6750 = v6738->saved_regs;
    int v6751 = v6750[16];
    int * v6752 = v6738->regs;
    v6752[16] = v6751;
    int * v6754 = v6738->saved_regs;
    int v6755 = v6754[17];
    int * v6756 = v6738->regs;
    v6756[17] = v6755;
    int * v6758 = v6738->saved_regs;
    int v6759 = v6758[5];
    int * v6760 = v6738->regs;
    v6760[5] = v6759;
    int * v6762 = v6738->saved_regs;
    int v6763 = v6762[6];
    int * v6764 = v6738->regs;
    v6764[6] = v6763;
    int * v6766 = v6738->saved_regs;
    int v6767 = v6766[7];
    int * v6768 = v6738->regs;
    v6768[7] = v6767;
    struct StateT * v6770 = slot_21(v6738);
    v6772 = v6770;
  }
  return v6772;
}

struct StateT * slot_44(struct StateT * v3242) {
  int v3243 = v3242->timer;
  int v3353 = v3243 + 1;
  v3242->timer = v3353;
  int * v3245 = v3242->regs;
  int v3246 = v3245[16];
  int * v3247 = v3242->cache_tags;
  int v3357 = (((int)((unsigned int)((int)((unsigned int)(v3246 + 4) >> 2)) >> 1)) & 1) * 2;
  int v3248 = v3247[v3357];
  int v3358 = ((((int)((unsigned int)((int)((unsigned int)(v3246 + 4) >> 2)) >> 1)) & 1) * 2) + 1;
  int v3249 = v3247[v3358];
  int v3359 = 4 + ((((int)((unsigned int)((int)((unsigned int)(v3246 + 4) >> 2)) >> 1)) & 3) * 2);
  int v3250 = v3247[v3359];
  int v3360 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v3246 + 4) >> 2)) >> 1)) & 3) * 2)) + 1;
  int v3251 = v3247[v3360];
  int v3252 = v3242->timer;
  int v3361 = v3252 + ((100 ^ (((~(((v3250 ^ ((int)((unsigned int)((int)((unsigned int)(v3246 + 4) >> 2)) >> 1))) | (-(v3250 ^ ((int)((unsigned int)((int)((unsigned int)(v3246 + 4) >> 2)) >> 1))))) >> 31)) | (~(((v3251 ^ ((int)((unsigned int)((int)((unsigned int)(v3246 + 4) >> 2)) >> 1))) | (-(v3251 ^ ((int)((unsigned int)((int)((unsigned int)(v3246 + 4) >> 2)) >> 1))))) >> 31))) & 104)) ^ (((~(((v3248 ^ ((int)((unsigned int)((int)((unsigned int)(v3246 + 4) >> 2)) >> 1))) | (-(v3248 ^ ((int)((unsigned int)((int)((unsigned int)(v3246 + 4) >> 2)) >> 1))))) >> 31)) | (~(((v3249 ^ ((int)((unsigned int)((int)((unsigned int)(v3246 + 4) >> 2)) >> 1))) | (-(v3249 ^ ((int)((unsigned int)((int)((unsigned int)(v3246 + 4) >> 2)) >> 1))))) >> 31))) & (1 ^ (100 ^ (((~(((v3250 ^ ((int)((unsigned int)((int)((unsigned int)(v3246 + 4) >> 2)) >> 1))) | (-(v3250 ^ ((int)((unsigned int)((int)((unsigned int)(v3246 + 4) >> 2)) >> 1))))) >> 31)) | (~(((v3251 ^ ((int)((unsigned int)((int)((unsigned int)(v3246 + 4) >> 2)) >> 1))) | (-(v3251 ^ ((int)((unsigned int)((int)((unsigned int)(v3246 + 4) >> 2)) >> 1))))) >> 31))) & 104)))));
  v3242->timer = v3361;
  int * v3254 = v3242->cache_vals;
  bool v3362 = !(((~(((v3248 ^ ((int)((unsigned int)((int)((unsigned int)(v3246 + 4) >> 2)) >> 1))) | (-(v3248 ^ ((int)((unsigned int)((int)((unsigned int)(v3246 + 4) >> 2)) >> 1))))) >> 31)) | (~(((v3249 ^ ((int)((unsigned int)((int)((unsigned int)(v3246 + 4) >> 2)) >> 1))) | (-(v3249 ^ ((int)((unsigned int)((int)((unsigned int)(v3246 + 4) >> 2)) >> 1))))) >> 31))) == 0);
  int v3347;
  if (v3362) {
    int * v3255 = v3242->cache_age;
    int v3364 = ((((int)((unsigned int)((int)((unsigned int)(v3246 + 4) >> 2)) >> 1)) & 1) * 2) + ((~(((v3249 ^ ((int)((unsigned int)((int)((unsigned int)(v3246 + 4) >> 2)) >> 1))) | (-(v3249 ^ ((int)((unsigned int)((int)((unsigned int)(v3246 + 4) >> 2)) >> 1))))) >> 31)) & 1);
    int v3256 = v3255[v3364];
    int v3257 = v3255[v3357];
    int v3365 = v3257 + ((int)((unsigned int)(v3257 - v3256) >> 31));
    v3255[v3357] = v3365;
    int * v3259 = v3242->cache_age;
    int v3260 = v3259[v3358];
    int v3367 = v3260 + ((int)((unsigned int)(v3260 - v3256) >> 31));
    v3259[v3358] = v3367;
    int * v3262 = v3242->cache_age;
    v3262[v3364] = 0;
    v3347 = v3364;
  } else {
    int * v3265 = v3242->cache_age;
    int v3371 = (((int)((unsigned int)((int)((unsigned int)(v3246 + 4) >> 2)) >> 1)) & 1) * 2;
    int v3266 = v3265[v3371];
    int * v3267 = v3242->cache_tags;
    int v3268 = v3267[v3371];
    int v3269 = v3265[v3358];
    int v3270 = v3267[v3358];
    bool v3373 = !(((~(((v3250 ^ ((int)((unsigned int)((int)((unsigned int)(v3246 + 4) >> 2)) >> 1))) | (-(v3250 ^ ((int)((unsigned int)((int)((unsigned int)(v3246 + 4) >> 2)) >> 1))))) >> 31)) | (~(((v3251 ^ ((int)((unsigned int)((int)((unsigned int)(v3246 + 4) >> 2)) >> 1))) | (-(v3251 ^ ((int)((unsigned int)((int)((unsigned int)(v3246 + 4) >> 2)) >> 1))))) >> 31))) == 0);
    int v3324;
    if (v3373) {
      int * v3271 = v3242->cache_age;
      int v3375 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v3246 + 4) >> 2)) >> 1)) & 3) * 2)) + ((~(((v3251 ^ ((int)((unsigned int)((int)((unsigned int)(v3246 + 4) >> 2)) >> 1))) | (-(v3251 ^ ((int)((unsigned int)((int)((unsigned int)(v3246 + 4) >> 2)) >> 1))))) >> 31)) & 1);
      int v3272 = v3271[v3375];
      int v3273 = v3271[v3359];
      int v3376 = v3273 + ((int)((unsigned int)(v3273 - v3272) >> 31));
      v3271[v3359] = v3376;
      int * v3275 = v3242->cache_age;
      int v3276 = v3275[v3360];
      int v3378 = v3276 + ((int)((unsigned int)(v3276 - v3272) >> 31));
      v3275[v3360] = v3378;
      int * v3278 = v3242->cache_age;
      v3278[v3375] = 0;
      v3324 = v3375;
    } else {
      int * v3281 = v3242->cache_age;
      int v3382 = 4 + ((((int)((unsigned int)((int)((unsigned int)(v3246 + 4) >> 2)) >> 1)) & 3) * 2);
      int v3282 = v3281[v3382];
      int * v3283 = v3242->cache_tags;
      int v3284 = v3283[v3382];
      int v3285 = v3281[v3360];
      int v3286 = v3283[v3360];
      int * v3287 = v3242->cache_dirty;
      int v3385 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v3246 + 4) >> 2)) >> 1)) & 3) * 2)) + ((((v3282 + ((~(((v3284 ^ -1) | (-(v3284 ^ -1))) >> 31)) & 2)) - (v3285 + ((~(((v3286 ^ -1) | (-(v3286 ^ -1))) >> 31)) & 2))) >> 31) & 1);
      int v3288 = v3287[v3385];
      bool v3386 = !(v3288 == 0);
      if (v3386) {
        int * v3289 = v3242->cache_tags;
        int v3290 = v3289[v3385];
        int * v3291 = v3242->cache_vals;
        int v3389 = ((4 + ((((int)((unsigned int)((int)((unsigned int)(v3246 + 4) >> 2)) >> 1)) & 3) * 2)) + ((((v3282 + ((~(((v3284 ^ -1) | (-(v3284 ^ -1))) >> 31)) & 2)) - (v3285 + ((~(((v3286 ^ -1) | (-(v3286 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
        int v3292 = v3291[v3389];
        int v3390 = (((4 + ((((int)((unsigned int)((int)((unsigned int)(v3246 + 4) >> 2)) >> 1)) & 3) * 2)) + ((((v3282 + ((~(((v3284 ^ -1) | (-(v3284 ^ -1))) >> 31)) & 2)) - (v3285 + ((~(((v3286 ^ -1) | (-(v3286 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
        int v3293 = v3291[v3390];
        int * v3294 = v3242->mem;
        int v3392 = v3290 * 2;
        v3294[v3392] = v3292;
        int * v3296 = v3242->mem;
        int v3395 = (v3290 * 2) + 1;
        v3296[v3395] = v3293;
        ;
      } else {
        ;
      }
      int * v3301 = v3242->mem;
      int v3400 = ((int)((unsigned int)((int)((unsigned int)(v3246 + 4) >> 2)) >> 1)) * 2;
      int v3302 = v3301[v3400];
      int v3401 = (((int)((unsigned int)((int)((unsigned int)(v3246 + 4) >> 2)) >> 1)) * 2) + 1;
      int v3303 = v3301[v3401];
      int * v3304 = v3242->cache_vals;
      int v3403 = ((4 + ((((int)((unsigned int)((int)((unsigned int)(v3246 + 4) >> 2)) >> 1)) & 3) * 2)) + ((((v3282 + ((~(((v3284 ^ -1) | (-(v3284 ^ -1))) >> 31)) & 2)) - (v3285 + ((~(((v3286 ^ -1) | (-(v3286 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
      v3304[v3403] = v3302;
      int * v3306 = v3242->cache_vals;
      int v3406 = (((4 + ((((int)((unsigned int)((int)((unsigned int)(v3246 + 4) >> 2)) >> 1)) & 3) * 2)) + ((((v3282 + ((~(((v3284 ^ -1) | (-(v3284 ^ -1))) >> 31)) & 2)) - (v3285 + ((~(((v3286 ^ -1) | (-(v3286 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
      v3306[v3406] = v3303;
      int * v3308 = v3242->cache_tags;
      int v3409 = (int)((unsigned int)((int)((unsigned int)(v3246 + 4) >> 2)) >> 1);
      v3308[v3385] = v3409;
      int * v3310 = v3242->cache_dirty;
      v3310[v3385] = 0;
      int * v3312 = v3242->cache_age;
      v3312[v3385] = 1;
      int * v3314 = v3242->cache_age;
      int v3315 = v3314[v3385];
      int v3316 = v3314[v3359];
      int v3415 = v3316 + ((int)((unsigned int)(v3316 - v3315) >> 31));
      v3314[v3359] = v3415;
      int * v3318 = v3242->cache_age;
      int v3319 = v3318[v3360];
      int v3417 = v3319 + ((int)((unsigned int)(v3319 - v3315) >> 31));
      v3318[v3360] = v3417;
      int * v3321 = v3242->cache_age;
      v3321[v3385] = 0;
      v3324 = v3385;
    }
    int * v3325 = v3242->cache_vals;
    int v3420 = v3324 * 2;
    int v3326 = v3325[v3420];
    int v3421 = (v3324 * 2) + 1;
    int v3327 = v3325[v3421];
    int v3422 = (((((int)((unsigned int)((int)((unsigned int)(v3246 + 4) >> 2)) >> 1)) & 1) * 2) + ((((v3266 + ((~(((v3268 ^ -1) | (-(v3268 ^ -1))) >> 31)) & 2)) - (v3269 + ((~(((v3270 ^ -1) | (-(v3270 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
    v3325[v3422] = v3326;
    int * v3329 = v3242->cache_vals;
    int v3425 = ((((((int)((unsigned int)((int)((unsigned int)(v3246 + 4) >> 2)) >> 1)) & 1) * 2) + ((((v3266 + ((~(((v3268 ^ -1) | (-(v3268 ^ -1))) >> 31)) & 2)) - (v3269 + ((~(((v3270 ^ -1) | (-(v3270 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
    v3329[v3425] = v3327;
    int * v3331 = v3242->cache_tags;
    int v3428 = ((((int)((unsigned int)((int)((unsigned int)(v3246 + 4) >> 2)) >> 1)) & 1) * 2) + ((((v3266 + ((~(((v3268 ^ -1) | (-(v3268 ^ -1))) >> 31)) & 2)) - (v3269 + ((~(((v3270 ^ -1) | (-(v3270 ^ -1))) >> 31)) & 2))) >> 31) & 1);
    int v3429 = (int)((unsigned int)((int)((unsigned int)(v3246 + 4) >> 2)) >> 1);
    v3331[v3428] = v3429;
    int * v3333 = v3242->cache_dirty;
    v3333[v3428] = 0;
    int * v3335 = v3242->cache_age;
    v3335[v3428] = 1;
    int * v3337 = v3242->cache_age;
    int v3338 = v3337[v3428];
    int v3339 = v3337[v3357];
    int v3435 = v3339 + ((int)((unsigned int)(v3339 - v3338) >> 31));
    v3337[v3357] = v3435;
    int * v3341 = v3242->cache_age;
    int v3342 = v3341[v3358];
    int v3437 = v3342 + ((int)((unsigned int)(v3342 - v3338) >> 31));
    v3341[v3358] = v3437;
    int * v3344 = v3242->cache_age;
    v3344[v3428] = 0;
    v3347 = v3428;
  }
  int v3440 = (v3347 * 2) + (((int)((unsigned int)(v3246 + 4) >> 2)) & 1);
  int v3348 = v3254[v3440];
  int * v3349 = v3242->regs;
  v3349[5] = v3348;
  struct StateT * v3351 = slot_45(v3242);
  return v3351;
}

struct StateT * slot_66(struct StateT * v5728) {
  int v5729 = v5728->timer;
  int v5733 = v5729 + 1;
  v5728->timer = v5733;
  struct StateT * v5731 = slot_67(v5728);
  return v5731;
}

struct StateT * slot_78(struct StateT * v6706) {
  int v6707 = v6706->timer;
  int v6715 = v6707 + 1;
  v6706->timer = v6715;
  int * v6709 = v6706->regs;
  int v6710 = v6709[5];
  int v6711 = v6709[6];
  int v6719 = v6710 ^ v6711;
  v6709[6] = v6719;
  struct StateT * v6713 = slot_79(v6706);
  return v6713;
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

struct StateT * slot_49(struct StateT * v3886) {
  int v3887 = v3886->timer;
  int v3895 = v3887 + 1;
  v3886->timer = v3895;
  int * v3889 = v3886->regs;
  int v3890 = v3889[13];
  int v3891 = v3889[7];
  int v3899 = v3890 & v3891;
  v3889[7] = v3899;
  struct StateT * v3893 = slot_50(v3886);
  return v3893;
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

struct StateT * slot_50(struct StateT * v3902) {
  int v3903 = v3902->timer;
  int v3911 = v3903 + 1;
  v3902->timer = v3911;
  int * v3905 = v3902->regs;
  int v3906 = v3905[13];
  int v3907 = v3905[6];
  int v3915 = v3906 & v3907;
  v3905[6] = v3915;
  struct StateT * v3909 = slot_51(v3902);
  return v3909;
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

struct StateT * slot_57(struct StateT * v4988) {
  int v4989 = v4988->timer;
  int v4997 = v4989 + 1;
  v4988->timer = v4997;
  int * v4991 = v4988->regs;
  int v4992 = v4991[5];
  int v4993 = v4991[16];
  int v5001 = v4992 ^ v4993;
  v4991[5] = v5001;
  struct StateT * v4995 = slot_58(v4988);
  return v4995;
}

struct StateT * slot_68(struct StateT * v5758) {
  int * v5759 = v5758->saved_regs;
  int * v5760 = v5758->regs;
  int v5761 = v5760[16];
  v5759[16] = v5761;
  int v5763 = v5758->timer;
  int v5775 = v5763 + 1;
  v5758->timer = v5775;
  int * v5765 = v5758->regs;
  int v5766 = v5765[10];
  int v5767 = v5765[15];
  int v5779 = v5766 + v5767;
  v5765[16] = v5779;
  struct StateT * v5769 = slot_69(v5758);
  return v5769;
}

struct StateT * slot_59(struct StateT * v5020) {
  int v5021 = v5020->timer;
  int v5029 = v5021 + 1;
  v5020->timer = v5029;
  int * v5023 = v5020->regs;
  int v5024 = v5023[13];
  int v5025 = v5023[17];
  int v5033 = v5024 & v5025;
  v5023[17] = v5033;
  struct StateT * v5027 = slot_60(v5020);
  return v5027;
}

struct StateT * slot_40(struct StateT * v3005) {
  int v3006 = v3005->timer;
  int v3014 = v3006 + 1;
  v3005->timer = v3014;
  int * v3008 = v3005->regs;
  int v3009 = v3008[10];
  int v3010 = v3008[15];
  int v3019 = v3009 + v3010;
  v3008[16] = v3019;
  struct StateT * v3012 = slot_42(v3005);
  return v3012;
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

struct StateT * slot_62(struct StateT * v5068) {
  int v5069 = v5068->timer;
  int v5077 = v5069 + 1;
  v5068->timer = v5077;
  int * v5071 = v5068->regs;
  int v5072 = v5071[6];
  int v5073 = v5071[17];
  int v5081 = v5072 ^ v5073;
  v5071[17] = v5081;
  struct StateT * v5075 = slot_63(v5068);
  return v5075;
}

struct StateT * slot_48(struct StateT * v3870) {
  int v3871 = v3870->timer;
  int v3879 = v3871 + 1;
  v3870->timer = v3879;
  int * v3873 = v3870->regs;
  int v3874 = v3873[7];
  int v3875 = v3873[17];
  int v3883 = v3874 ^ v3875;
  v3873[7] = v3883;
  struct StateT * v3877 = slot_49(v3870);
  return v3877;
}

struct StateT * slot_77(struct StateT * v6690) {
  int v6691 = v6690->timer;
  int v6699 = v6691 + 1;
  v6690->timer = v6699;
  int * v6693 = v6690->regs;
  int v6694 = v6693[13];
  int v6695 = v6693[6];
  int v6703 = v6694 & v6695;
  v6693[6] = v6703;
  struct StateT * v6697 = slot_78(v6690);
  return v6697;
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

struct StateT * slot_75(struct StateT * v6658) {
  int v6659 = v6658->timer;
  int v6667 = v6659 + 1;
  v6658->timer = v6667;
  int * v6661 = v6658->regs;
  int v6662 = v6661[7];
  int v6663 = v6661[17];
  int v6671 = v6662 ^ v6663;
  v6661[7] = v6671;
  struct StateT * v6665 = slot_76(v6658);
  return v6665;
}

struct StateT * slot_56(struct StateT * v4784) {
  int v4785 = v4784->timer;
  int v4895 = v4785 + 1;
  v4784->timer = v4895;
  int * v4787 = v4784->regs;
  int v4788 = v4787[15];
  int * v4789 = v4784->cache_tags;
  int v4899 = (((int)((unsigned int)((int)((unsigned int)v4788 >> 2)) >> 1)) & 1) * 2;
  int v4790 = v4789[v4899];
  int v4900 = ((((int)((unsigned int)((int)((unsigned int)v4788 >> 2)) >> 1)) & 1) * 2) + 1;
  int v4791 = v4789[v4900];
  int v4901 = 4 + ((((int)((unsigned int)((int)((unsigned int)v4788 >> 2)) >> 1)) & 3) * 2);
  int v4792 = v4789[v4901];
  int v4902 = (4 + ((((int)((unsigned int)((int)((unsigned int)v4788 >> 2)) >> 1)) & 3) * 2)) + 1;
  int v4793 = v4789[v4902];
  int v4794 = v4784->timer;
  int v4903 = v4794 + ((100 ^ (((~(((v4792 ^ ((int)((unsigned int)((int)((unsigned int)v4788 >> 2)) >> 1))) | (-(v4792 ^ ((int)((unsigned int)((int)((unsigned int)v4788 >> 2)) >> 1))))) >> 31)) | (~(((v4793 ^ ((int)((unsigned int)((int)((unsigned int)v4788 >> 2)) >> 1))) | (-(v4793 ^ ((int)((unsigned int)((int)((unsigned int)v4788 >> 2)) >> 1))))) >> 31))) & 104)) ^ (((~(((v4790 ^ ((int)((unsigned int)((int)((unsigned int)v4788 >> 2)) >> 1))) | (-(v4790 ^ ((int)((unsigned int)((int)((unsigned int)v4788 >> 2)) >> 1))))) >> 31)) | (~(((v4791 ^ ((int)((unsigned int)((int)((unsigned int)v4788 >> 2)) >> 1))) | (-(v4791 ^ ((int)((unsigned int)((int)((unsigned int)v4788 >> 2)) >> 1))))) >> 31))) & (1 ^ (100 ^ (((~(((v4792 ^ ((int)((unsigned int)((int)((unsigned int)v4788 >> 2)) >> 1))) | (-(v4792 ^ ((int)((unsigned int)((int)((unsigned int)v4788 >> 2)) >> 1))))) >> 31)) | (~(((v4793 ^ ((int)((unsigned int)((int)((unsigned int)v4788 >> 2)) >> 1))) | (-(v4793 ^ ((int)((unsigned int)((int)((unsigned int)v4788 >> 2)) >> 1))))) >> 31))) & 104)))));
  v4784->timer = v4903;
  int * v4796 = v4784->cache_vals;
  bool v4904 = !(((~(((v4790 ^ ((int)((unsigned int)((int)((unsigned int)v4788 >> 2)) >> 1))) | (-(v4790 ^ ((int)((unsigned int)((int)((unsigned int)v4788 >> 2)) >> 1))))) >> 31)) | (~(((v4791 ^ ((int)((unsigned int)((int)((unsigned int)v4788 >> 2)) >> 1))) | (-(v4791 ^ ((int)((unsigned int)((int)((unsigned int)v4788 >> 2)) >> 1))))) >> 31))) == 0);
  int v4889;
  if (v4904) {
    int * v4797 = v4784->cache_age;
    int v4906 = ((((int)((unsigned int)((int)((unsigned int)v4788 >> 2)) >> 1)) & 1) * 2) + ((~(((v4791 ^ ((int)((unsigned int)((int)((unsigned int)v4788 >> 2)) >> 1))) | (-(v4791 ^ ((int)((unsigned int)((int)((unsigned int)v4788 >> 2)) >> 1))))) >> 31)) & 1);
    int v4798 = v4797[v4906];
    int v4799 = v4797[v4899];
    int v4907 = v4799 + ((int)((unsigned int)(v4799 - v4798) >> 31));
    v4797[v4899] = v4907;
    int * v4801 = v4784->cache_age;
    int v4802 = v4801[v4900];
    int v4909 = v4802 + ((int)((unsigned int)(v4802 - v4798) >> 31));
    v4801[v4900] = v4909;
    int * v4804 = v4784->cache_age;
    v4804[v4906] = 0;
    v4889 = v4906;
  } else {
    int * v4807 = v4784->cache_age;
    int v4913 = (((int)((unsigned int)((int)((unsigned int)v4788 >> 2)) >> 1)) & 1) * 2;
    int v4808 = v4807[v4913];
    int * v4809 = v4784->cache_tags;
    int v4810 = v4809[v4913];
    int v4811 = v4807[v4900];
    int v4812 = v4809[v4900];
    bool v4915 = !(((~(((v4792 ^ ((int)((unsigned int)((int)((unsigned int)v4788 >> 2)) >> 1))) | (-(v4792 ^ ((int)((unsigned int)((int)((unsigned int)v4788 >> 2)) >> 1))))) >> 31)) | (~(((v4793 ^ ((int)((unsigned int)((int)((unsigned int)v4788 >> 2)) >> 1))) | (-(v4793 ^ ((int)((unsigned int)((int)((unsigned int)v4788 >> 2)) >> 1))))) >> 31))) == 0);
    int v4866;
    if (v4915) {
      int * v4813 = v4784->cache_age;
      int v4917 = (4 + ((((int)((unsigned int)((int)((unsigned int)v4788 >> 2)) >> 1)) & 3) * 2)) + ((~(((v4793 ^ ((int)((unsigned int)((int)((unsigned int)v4788 >> 2)) >> 1))) | (-(v4793 ^ ((int)((unsigned int)((int)((unsigned int)v4788 >> 2)) >> 1))))) >> 31)) & 1);
      int v4814 = v4813[v4917];
      int v4815 = v4813[v4901];
      int v4918 = v4815 + ((int)((unsigned int)(v4815 - v4814) >> 31));
      v4813[v4901] = v4918;
      int * v4817 = v4784->cache_age;
      int v4818 = v4817[v4902];
      int v4920 = v4818 + ((int)((unsigned int)(v4818 - v4814) >> 31));
      v4817[v4902] = v4920;
      int * v4820 = v4784->cache_age;
      v4820[v4917] = 0;
      v4866 = v4917;
    } else {
      int * v4823 = v4784->cache_age;
      int v4924 = 4 + ((((int)((unsigned int)((int)((unsigned int)v4788 >> 2)) >> 1)) & 3) * 2);
      int v4824 = v4823[v4924];
      int * v4825 = v4784->cache_tags;
      int v4826 = v4825[v4924];
      int v4827 = v4823[v4902];
      int v4828 = v4825[v4902];
      int * v4829 = v4784->cache_dirty;
      int v4927 = (4 + ((((int)((unsigned int)((int)((unsigned int)v4788 >> 2)) >> 1)) & 3) * 2)) + ((((v4824 + ((~(((v4826 ^ -1) | (-(v4826 ^ -1))) >> 31)) & 2)) - (v4827 + ((~(((v4828 ^ -1) | (-(v4828 ^ -1))) >> 31)) & 2))) >> 31) & 1);
      int v4830 = v4829[v4927];
      bool v4928 = !(v4830 == 0);
      if (v4928) {
        int * v4831 = v4784->cache_tags;
        int v4832 = v4831[v4927];
        int * v4833 = v4784->cache_vals;
        int v4931 = ((4 + ((((int)((unsigned int)((int)((unsigned int)v4788 >> 2)) >> 1)) & 3) * 2)) + ((((v4824 + ((~(((v4826 ^ -1) | (-(v4826 ^ -1))) >> 31)) & 2)) - (v4827 + ((~(((v4828 ^ -1) | (-(v4828 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
        int v4834 = v4833[v4931];
        int v4932 = (((4 + ((((int)((unsigned int)((int)((unsigned int)v4788 >> 2)) >> 1)) & 3) * 2)) + ((((v4824 + ((~(((v4826 ^ -1) | (-(v4826 ^ -1))) >> 31)) & 2)) - (v4827 + ((~(((v4828 ^ -1) | (-(v4828 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
        int v4835 = v4833[v4932];
        int * v4836 = v4784->mem;
        int v4934 = v4832 * 2;
        v4836[v4934] = v4834;
        int * v4838 = v4784->mem;
        int v4937 = (v4832 * 2) + 1;
        v4838[v4937] = v4835;
        ;
      } else {
        ;
      }
      int * v4843 = v4784->mem;
      int v4942 = ((int)((unsigned int)((int)((unsigned int)v4788 >> 2)) >> 1)) * 2;
      int v4844 = v4843[v4942];
      int v4943 = (((int)((unsigned int)((int)((unsigned int)v4788 >> 2)) >> 1)) * 2) + 1;
      int v4845 = v4843[v4943];
      int * v4846 = v4784->cache_vals;
      int v4945 = ((4 + ((((int)((unsigned int)((int)((unsigned int)v4788 >> 2)) >> 1)) & 3) * 2)) + ((((v4824 + ((~(((v4826 ^ -1) | (-(v4826 ^ -1))) >> 31)) & 2)) - (v4827 + ((~(((v4828 ^ -1) | (-(v4828 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
      v4846[v4945] = v4844;
      int * v4848 = v4784->cache_vals;
      int v4948 = (((4 + ((((int)((unsigned int)((int)((unsigned int)v4788 >> 2)) >> 1)) & 3) * 2)) + ((((v4824 + ((~(((v4826 ^ -1) | (-(v4826 ^ -1))) >> 31)) & 2)) - (v4827 + ((~(((v4828 ^ -1) | (-(v4828 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
      v4848[v4948] = v4845;
      int * v4850 = v4784->cache_tags;
      int v4951 = (int)((unsigned int)((int)((unsigned int)v4788 >> 2)) >> 1);
      v4850[v4927] = v4951;
      int * v4852 = v4784->cache_dirty;
      v4852[v4927] = 0;
      int * v4854 = v4784->cache_age;
      v4854[v4927] = 1;
      int * v4856 = v4784->cache_age;
      int v4857 = v4856[v4927];
      int v4858 = v4856[v4901];
      int v4957 = v4858 + ((int)((unsigned int)(v4858 - v4857) >> 31));
      v4856[v4901] = v4957;
      int * v4860 = v4784->cache_age;
      int v4861 = v4860[v4902];
      int v4959 = v4861 + ((int)((unsigned int)(v4861 - v4857) >> 31));
      v4860[v4902] = v4959;
      int * v4863 = v4784->cache_age;
      v4863[v4927] = 0;
      v4866 = v4927;
    }
    int * v4867 = v4784->cache_vals;
    int v4962 = v4866 * 2;
    int v4868 = v4867[v4962];
    int v4963 = (v4866 * 2) + 1;
    int v4869 = v4867[v4963];
    int v4964 = (((((int)((unsigned int)((int)((unsigned int)v4788 >> 2)) >> 1)) & 1) * 2) + ((((v4808 + ((~(((v4810 ^ -1) | (-(v4810 ^ -1))) >> 31)) & 2)) - (v4811 + ((~(((v4812 ^ -1) | (-(v4812 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
    v4867[v4964] = v4868;
    int * v4871 = v4784->cache_vals;
    int v4967 = ((((((int)((unsigned int)((int)((unsigned int)v4788 >> 2)) >> 1)) & 1) * 2) + ((((v4808 + ((~(((v4810 ^ -1) | (-(v4810 ^ -1))) >> 31)) & 2)) - (v4811 + ((~(((v4812 ^ -1) | (-(v4812 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
    v4871[v4967] = v4869;
    int * v4873 = v4784->cache_tags;
    int v4970 = ((((int)((unsigned int)((int)((unsigned int)v4788 >> 2)) >> 1)) & 1) * 2) + ((((v4808 + ((~(((v4810 ^ -1) | (-(v4810 ^ -1))) >> 31)) & 2)) - (v4811 + ((~(((v4812 ^ -1) | (-(v4812 ^ -1))) >> 31)) & 2))) >> 31) & 1);
    int v4971 = (int)((unsigned int)((int)((unsigned int)v4788 >> 2)) >> 1);
    v4873[v4970] = v4971;
    int * v4875 = v4784->cache_dirty;
    v4875[v4970] = 0;
    int * v4877 = v4784->cache_age;
    v4877[v4970] = 1;
    int * v4879 = v4784->cache_age;
    int v4880 = v4879[v4970];
    int v4881 = v4879[v4899];
    int v4977 = v4881 + ((int)((unsigned int)(v4881 - v4880) >> 31));
    v4879[v4899] = v4977;
    int * v4883 = v4784->cache_age;
    int v4884 = v4883[v4900];
    int v4979 = v4884 + ((int)((unsigned int)(v4884 - v4880) >> 31));
    v4883[v4900] = v4979;
    int * v4886 = v4784->cache_age;
    v4886[v4970] = 0;
    v4889 = v4970;
  }
  int v4982 = (v4889 * 2) + (((int)((unsigned int)v4788 >> 2)) & 1);
  int v4890 = v4796[v4982];
  int * v4891 = v4784->regs;
  v4891[6] = v4890;
  struct StateT * v4893 = slot_57(v4784);
  return v4893;
}

struct StateT * slot_72(struct StateT * v6220) {
  int * v6221 = v6220->saved_regs;
  int * v6222 = v6220->regs;
  int v6223 = v6222[6];
  v6221[6] = v6223;
  int v6225 = v6220->timer;
  int v6339 = v6225 + 1;
  v6220->timer = v6339;
  int * v6227 = v6220->regs;
  int v6228 = v6227[15];
  int * v6229 = v6220->cache_tags;
  int v6343 = (((int)((unsigned int)((int)((unsigned int)(v6228 + 4) >> 2)) >> 1)) & 1) * 2;
  int v6230 = v6229[v6343];
  int v6344 = ((((int)((unsigned int)((int)((unsigned int)(v6228 + 4) >> 2)) >> 1)) & 1) * 2) + 1;
  int v6231 = v6229[v6344];
  int v6345 = 4 + ((((int)((unsigned int)((int)((unsigned int)(v6228 + 4) >> 2)) >> 1)) & 3) * 2);
  int v6232 = v6229[v6345];
  int v6346 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v6228 + 4) >> 2)) >> 1)) & 3) * 2)) + 1;
  int v6233 = v6229[v6346];
  int v6234 = v6220->timer;
  int v6347 = v6234 + ((100 ^ (((~(((v6232 ^ ((int)((unsigned int)((int)((unsigned int)(v6228 + 4) >> 2)) >> 1))) | (-(v6232 ^ ((int)((unsigned int)((int)((unsigned int)(v6228 + 4) >> 2)) >> 1))))) >> 31)) | (~(((v6233 ^ ((int)((unsigned int)((int)((unsigned int)(v6228 + 4) >> 2)) >> 1))) | (-(v6233 ^ ((int)((unsigned int)((int)((unsigned int)(v6228 + 4) >> 2)) >> 1))))) >> 31))) & 104)) ^ (((~(((v6230 ^ ((int)((unsigned int)((int)((unsigned int)(v6228 + 4) >> 2)) >> 1))) | (-(v6230 ^ ((int)((unsigned int)((int)((unsigned int)(v6228 + 4) >> 2)) >> 1))))) >> 31)) | (~(((v6231 ^ ((int)((unsigned int)((int)((unsigned int)(v6228 + 4) >> 2)) >> 1))) | (-(v6231 ^ ((int)((unsigned int)((int)((unsigned int)(v6228 + 4) >> 2)) >> 1))))) >> 31))) & (1 ^ (100 ^ (((~(((v6232 ^ ((int)((unsigned int)((int)((unsigned int)(v6228 + 4) >> 2)) >> 1))) | (-(v6232 ^ ((int)((unsigned int)((int)((unsigned int)(v6228 + 4) >> 2)) >> 1))))) >> 31)) | (~(((v6233 ^ ((int)((unsigned int)((int)((unsigned int)(v6228 + 4) >> 2)) >> 1))) | (-(v6233 ^ ((int)((unsigned int)((int)((unsigned int)(v6228 + 4) >> 2)) >> 1))))) >> 31))) & 104)))));
  v6220->timer = v6347;
  int * v6236 = v6220->cache_vals;
  bool v6348 = !(((~(((v6230 ^ ((int)((unsigned int)((int)((unsigned int)(v6228 + 4) >> 2)) >> 1))) | (-(v6230 ^ ((int)((unsigned int)((int)((unsigned int)(v6228 + 4) >> 2)) >> 1))))) >> 31)) | (~(((v6231 ^ ((int)((unsigned int)((int)((unsigned int)(v6228 + 4) >> 2)) >> 1))) | (-(v6231 ^ ((int)((unsigned int)((int)((unsigned int)(v6228 + 4) >> 2)) >> 1))))) >> 31))) == 0);
  int v6329;
  if (v6348) {
    int * v6237 = v6220->cache_age;
    int v6350 = ((((int)((unsigned int)((int)((unsigned int)(v6228 + 4) >> 2)) >> 1)) & 1) * 2) + ((~(((v6231 ^ ((int)((unsigned int)((int)((unsigned int)(v6228 + 4) >> 2)) >> 1))) | (-(v6231 ^ ((int)((unsigned int)((int)((unsigned int)(v6228 + 4) >> 2)) >> 1))))) >> 31)) & 1);
    int v6238 = v6237[v6350];
    int v6239 = v6237[v6343];
    int v6351 = v6239 + ((int)((unsigned int)(v6239 - v6238) >> 31));
    v6237[v6343] = v6351;
    int * v6241 = v6220->cache_age;
    int v6242 = v6241[v6344];
    int v6353 = v6242 + ((int)((unsigned int)(v6242 - v6238) >> 31));
    v6241[v6344] = v6353;
    int * v6244 = v6220->cache_age;
    v6244[v6350] = 0;
    v6329 = v6350;
  } else {
    int * v6247 = v6220->cache_age;
    int v6357 = (((int)((unsigned int)((int)((unsigned int)(v6228 + 4) >> 2)) >> 1)) & 1) * 2;
    int v6248 = v6247[v6357];
    int * v6249 = v6220->cache_tags;
    int v6250 = v6249[v6357];
    int v6251 = v6247[v6344];
    int v6252 = v6249[v6344];
    bool v6359 = !(((~(((v6232 ^ ((int)((unsigned int)((int)((unsigned int)(v6228 + 4) >> 2)) >> 1))) | (-(v6232 ^ ((int)((unsigned int)((int)((unsigned int)(v6228 + 4) >> 2)) >> 1))))) >> 31)) | (~(((v6233 ^ ((int)((unsigned int)((int)((unsigned int)(v6228 + 4) >> 2)) >> 1))) | (-(v6233 ^ ((int)((unsigned int)((int)((unsigned int)(v6228 + 4) >> 2)) >> 1))))) >> 31))) == 0);
    int v6306;
    if (v6359) {
      int * v6253 = v6220->cache_age;
      int v6361 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v6228 + 4) >> 2)) >> 1)) & 3) * 2)) + ((~(((v6233 ^ ((int)((unsigned int)((int)((unsigned int)(v6228 + 4) >> 2)) >> 1))) | (-(v6233 ^ ((int)((unsigned int)((int)((unsigned int)(v6228 + 4) >> 2)) >> 1))))) >> 31)) & 1);
      int v6254 = v6253[v6361];
      int v6255 = v6253[v6345];
      int v6362 = v6255 + ((int)((unsigned int)(v6255 - v6254) >> 31));
      v6253[v6345] = v6362;
      int * v6257 = v6220->cache_age;
      int v6258 = v6257[v6346];
      int v6364 = v6258 + ((int)((unsigned int)(v6258 - v6254) >> 31));
      v6257[v6346] = v6364;
      int * v6260 = v6220->cache_age;
      v6260[v6361] = 0;
      v6306 = v6361;
    } else {
      int * v6263 = v6220->cache_age;
      int v6368 = 4 + ((((int)((unsigned int)((int)((unsigned int)(v6228 + 4) >> 2)) >> 1)) & 3) * 2);
      int v6264 = v6263[v6368];
      int * v6265 = v6220->cache_tags;
      int v6266 = v6265[v6368];
      int v6267 = v6263[v6346];
      int v6268 = v6265[v6346];
      int * v6269 = v6220->cache_dirty;
      int v6371 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v6228 + 4) >> 2)) >> 1)) & 3) * 2)) + ((((v6264 + ((~(((v6266 ^ -1) | (-(v6266 ^ -1))) >> 31)) & 2)) - (v6267 + ((~(((v6268 ^ -1) | (-(v6268 ^ -1))) >> 31)) & 2))) >> 31) & 1);
      int v6270 = v6269[v6371];
      bool v6372 = !(v6270 == 0);
      if (v6372) {
        int * v6271 = v6220->cache_tags;
        int v6272 = v6271[v6371];
        int * v6273 = v6220->cache_vals;
        int v6375 = ((4 + ((((int)((unsigned int)((int)((unsigned int)(v6228 + 4) >> 2)) >> 1)) & 3) * 2)) + ((((v6264 + ((~(((v6266 ^ -1) | (-(v6266 ^ -1))) >> 31)) & 2)) - (v6267 + ((~(((v6268 ^ -1) | (-(v6268 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
        int v6274 = v6273[v6375];
        int v6376 = (((4 + ((((int)((unsigned int)((int)((unsigned int)(v6228 + 4) >> 2)) >> 1)) & 3) * 2)) + ((((v6264 + ((~(((v6266 ^ -1) | (-(v6266 ^ -1))) >> 31)) & 2)) - (v6267 + ((~(((v6268 ^ -1) | (-(v6268 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
        int v6275 = v6273[v6376];
        int * v6276 = v6220->mem;
        int v6378 = v6272 * 2;
        v6276[v6378] = v6274;
        int * v6278 = v6220->mem;
        int v6381 = (v6272 * 2) + 1;
        v6278[v6381] = v6275;
        ;
      } else {
        ;
      }
      int * v6283 = v6220->mem;
      int v6386 = ((int)((unsigned int)((int)((unsigned int)(v6228 + 4) >> 2)) >> 1)) * 2;
      int v6284 = v6283[v6386];
      int v6387 = (((int)((unsigned int)((int)((unsigned int)(v6228 + 4) >> 2)) >> 1)) * 2) + 1;
      int v6285 = v6283[v6387];
      int * v6286 = v6220->cache_vals;
      int v6389 = ((4 + ((((int)((unsigned int)((int)((unsigned int)(v6228 + 4) >> 2)) >> 1)) & 3) * 2)) + ((((v6264 + ((~(((v6266 ^ -1) | (-(v6266 ^ -1))) >> 31)) & 2)) - (v6267 + ((~(((v6268 ^ -1) | (-(v6268 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
      v6286[v6389] = v6284;
      int * v6288 = v6220->cache_vals;
      int v6392 = (((4 + ((((int)((unsigned int)((int)((unsigned int)(v6228 + 4) >> 2)) >> 1)) & 3) * 2)) + ((((v6264 + ((~(((v6266 ^ -1) | (-(v6266 ^ -1))) >> 31)) & 2)) - (v6267 + ((~(((v6268 ^ -1) | (-(v6268 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
      v6288[v6392] = v6285;
      int * v6290 = v6220->cache_tags;
      int v6395 = (int)((unsigned int)((int)((unsigned int)(v6228 + 4) >> 2)) >> 1);
      v6290[v6371] = v6395;
      int * v6292 = v6220->cache_dirty;
      v6292[v6371] = 0;
      int * v6294 = v6220->cache_age;
      v6294[v6371] = 1;
      int * v6296 = v6220->cache_age;
      int v6297 = v6296[v6371];
      int v6298 = v6296[v6345];
      int v6401 = v6298 + ((int)((unsigned int)(v6298 - v6297) >> 31));
      v6296[v6345] = v6401;
      int * v6300 = v6220->cache_age;
      int v6301 = v6300[v6346];
      int v6403 = v6301 + ((int)((unsigned int)(v6301 - v6297) >> 31));
      v6300[v6346] = v6403;
      int * v6303 = v6220->cache_age;
      v6303[v6371] = 0;
      v6306 = v6371;
    }
    int * v6307 = v6220->cache_vals;
    int v6406 = v6306 * 2;
    int v6308 = v6307[v6406];
    int v6407 = (v6306 * 2) + 1;
    int v6309 = v6307[v6407];
    int v6408 = (((((int)((unsigned int)((int)((unsigned int)(v6228 + 4) >> 2)) >> 1)) & 1) * 2) + ((((v6248 + ((~(((v6250 ^ -1) | (-(v6250 ^ -1))) >> 31)) & 2)) - (v6251 + ((~(((v6252 ^ -1) | (-(v6252 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
    v6307[v6408] = v6308;
    int * v6311 = v6220->cache_vals;
    int v6411 = ((((((int)((unsigned int)((int)((unsigned int)(v6228 + 4) >> 2)) >> 1)) & 1) * 2) + ((((v6248 + ((~(((v6250 ^ -1) | (-(v6250 ^ -1))) >> 31)) & 2)) - (v6251 + ((~(((v6252 ^ -1) | (-(v6252 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
    v6311[v6411] = v6309;
    int * v6313 = v6220->cache_tags;
    int v6414 = ((((int)((unsigned int)((int)((unsigned int)(v6228 + 4) >> 2)) >> 1)) & 1) * 2) + ((((v6248 + ((~(((v6250 ^ -1) | (-(v6250 ^ -1))) >> 31)) & 2)) - (v6251 + ((~(((v6252 ^ -1) | (-(v6252 ^ -1))) >> 31)) & 2))) >> 31) & 1);
    int v6415 = (int)((unsigned int)((int)((unsigned int)(v6228 + 4) >> 2)) >> 1);
    v6313[v6414] = v6415;
    int * v6315 = v6220->cache_dirty;
    v6315[v6414] = 0;
    int * v6317 = v6220->cache_age;
    v6317[v6414] = 1;
    int * v6319 = v6220->cache_age;
    int v6320 = v6319[v6414];
    int v6321 = v6319[v6343];
    int v6421 = v6321 + ((int)((unsigned int)(v6321 - v6320) >> 31));
    v6319[v6343] = v6421;
    int * v6323 = v6220->cache_age;
    int v6324 = v6323[v6344];
    int v6423 = v6324 + ((int)((unsigned int)(v6324 - v6320) >> 31));
    v6323[v6344] = v6423;
    int * v6326 = v6220->cache_age;
    v6326[v6414] = 0;
    v6329 = v6414;
  }
  int v6426 = (v6329 * 2) + (((int)((unsigned int)(v6228 + 4) >> 2)) & 1);
  int v6330 = v6236[v6426];
  int * v6331 = v6220->regs;
  v6331[6] = v6330;
  struct StateT * v6333 = slot_73(v6220);
  return v6333;
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

struct StateT * slot_71(struct StateT * v6009) {
  int * v6010 = v6009->saved_regs;
  int * v6011 = v6009->regs;
  int v6012 = v6011[5];
  v6010[5] = v6012;
  int v6014 = v6009->timer;
  int v6128 = v6014 + 1;
  v6009->timer = v6128;
  int * v6016 = v6009->regs;
  int v6017 = v6016[16];
  int * v6018 = v6009->cache_tags;
  int v6132 = (((int)((unsigned int)((int)((unsigned int)(v6017 + 4) >> 2)) >> 1)) & 1) * 2;
  int v6019 = v6018[v6132];
  int v6133 = ((((int)((unsigned int)((int)((unsigned int)(v6017 + 4) >> 2)) >> 1)) & 1) * 2) + 1;
  int v6020 = v6018[v6133];
  int v6134 = 4 + ((((int)((unsigned int)((int)((unsigned int)(v6017 + 4) >> 2)) >> 1)) & 3) * 2);
  int v6021 = v6018[v6134];
  int v6135 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v6017 + 4) >> 2)) >> 1)) & 3) * 2)) + 1;
  int v6022 = v6018[v6135];
  int v6023 = v6009->timer;
  int v6136 = v6023 + ((100 ^ (((~(((v6021 ^ ((int)((unsigned int)((int)((unsigned int)(v6017 + 4) >> 2)) >> 1))) | (-(v6021 ^ ((int)((unsigned int)((int)((unsigned int)(v6017 + 4) >> 2)) >> 1))))) >> 31)) | (~(((v6022 ^ ((int)((unsigned int)((int)((unsigned int)(v6017 + 4) >> 2)) >> 1))) | (-(v6022 ^ ((int)((unsigned int)((int)((unsigned int)(v6017 + 4) >> 2)) >> 1))))) >> 31))) & 104)) ^ (((~(((v6019 ^ ((int)((unsigned int)((int)((unsigned int)(v6017 + 4) >> 2)) >> 1))) | (-(v6019 ^ ((int)((unsigned int)((int)((unsigned int)(v6017 + 4) >> 2)) >> 1))))) >> 31)) | (~(((v6020 ^ ((int)((unsigned int)((int)((unsigned int)(v6017 + 4) >> 2)) >> 1))) | (-(v6020 ^ ((int)((unsigned int)((int)((unsigned int)(v6017 + 4) >> 2)) >> 1))))) >> 31))) & (1 ^ (100 ^ (((~(((v6021 ^ ((int)((unsigned int)((int)((unsigned int)(v6017 + 4) >> 2)) >> 1))) | (-(v6021 ^ ((int)((unsigned int)((int)((unsigned int)(v6017 + 4) >> 2)) >> 1))))) >> 31)) | (~(((v6022 ^ ((int)((unsigned int)((int)((unsigned int)(v6017 + 4) >> 2)) >> 1))) | (-(v6022 ^ ((int)((unsigned int)((int)((unsigned int)(v6017 + 4) >> 2)) >> 1))))) >> 31))) & 104)))));
  v6009->timer = v6136;
  int * v6025 = v6009->cache_vals;
  bool v6137 = !(((~(((v6019 ^ ((int)((unsigned int)((int)((unsigned int)(v6017 + 4) >> 2)) >> 1))) | (-(v6019 ^ ((int)((unsigned int)((int)((unsigned int)(v6017 + 4) >> 2)) >> 1))))) >> 31)) | (~(((v6020 ^ ((int)((unsigned int)((int)((unsigned int)(v6017 + 4) >> 2)) >> 1))) | (-(v6020 ^ ((int)((unsigned int)((int)((unsigned int)(v6017 + 4) >> 2)) >> 1))))) >> 31))) == 0);
  int v6118;
  if (v6137) {
    int * v6026 = v6009->cache_age;
    int v6139 = ((((int)((unsigned int)((int)((unsigned int)(v6017 + 4) >> 2)) >> 1)) & 1) * 2) + ((~(((v6020 ^ ((int)((unsigned int)((int)((unsigned int)(v6017 + 4) >> 2)) >> 1))) | (-(v6020 ^ ((int)((unsigned int)((int)((unsigned int)(v6017 + 4) >> 2)) >> 1))))) >> 31)) & 1);
    int v6027 = v6026[v6139];
    int v6028 = v6026[v6132];
    int v6140 = v6028 + ((int)((unsigned int)(v6028 - v6027) >> 31));
    v6026[v6132] = v6140;
    int * v6030 = v6009->cache_age;
    int v6031 = v6030[v6133];
    int v6142 = v6031 + ((int)((unsigned int)(v6031 - v6027) >> 31));
    v6030[v6133] = v6142;
    int * v6033 = v6009->cache_age;
    v6033[v6139] = 0;
    v6118 = v6139;
  } else {
    int * v6036 = v6009->cache_age;
    int v6146 = (((int)((unsigned int)((int)((unsigned int)(v6017 + 4) >> 2)) >> 1)) & 1) * 2;
    int v6037 = v6036[v6146];
    int * v6038 = v6009->cache_tags;
    int v6039 = v6038[v6146];
    int v6040 = v6036[v6133];
    int v6041 = v6038[v6133];
    bool v6148 = !(((~(((v6021 ^ ((int)((unsigned int)((int)((unsigned int)(v6017 + 4) >> 2)) >> 1))) | (-(v6021 ^ ((int)((unsigned int)((int)((unsigned int)(v6017 + 4) >> 2)) >> 1))))) >> 31)) | (~(((v6022 ^ ((int)((unsigned int)((int)((unsigned int)(v6017 + 4) >> 2)) >> 1))) | (-(v6022 ^ ((int)((unsigned int)((int)((unsigned int)(v6017 + 4) >> 2)) >> 1))))) >> 31))) == 0);
    int v6095;
    if (v6148) {
      int * v6042 = v6009->cache_age;
      int v6150 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v6017 + 4) >> 2)) >> 1)) & 3) * 2)) + ((~(((v6022 ^ ((int)((unsigned int)((int)((unsigned int)(v6017 + 4) >> 2)) >> 1))) | (-(v6022 ^ ((int)((unsigned int)((int)((unsigned int)(v6017 + 4) >> 2)) >> 1))))) >> 31)) & 1);
      int v6043 = v6042[v6150];
      int v6044 = v6042[v6134];
      int v6151 = v6044 + ((int)((unsigned int)(v6044 - v6043) >> 31));
      v6042[v6134] = v6151;
      int * v6046 = v6009->cache_age;
      int v6047 = v6046[v6135];
      int v6153 = v6047 + ((int)((unsigned int)(v6047 - v6043) >> 31));
      v6046[v6135] = v6153;
      int * v6049 = v6009->cache_age;
      v6049[v6150] = 0;
      v6095 = v6150;
    } else {
      int * v6052 = v6009->cache_age;
      int v6157 = 4 + ((((int)((unsigned int)((int)((unsigned int)(v6017 + 4) >> 2)) >> 1)) & 3) * 2);
      int v6053 = v6052[v6157];
      int * v6054 = v6009->cache_tags;
      int v6055 = v6054[v6157];
      int v6056 = v6052[v6135];
      int v6057 = v6054[v6135];
      int * v6058 = v6009->cache_dirty;
      int v6160 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v6017 + 4) >> 2)) >> 1)) & 3) * 2)) + ((((v6053 + ((~(((v6055 ^ -1) | (-(v6055 ^ -1))) >> 31)) & 2)) - (v6056 + ((~(((v6057 ^ -1) | (-(v6057 ^ -1))) >> 31)) & 2))) >> 31) & 1);
      int v6059 = v6058[v6160];
      bool v6161 = !(v6059 == 0);
      if (v6161) {
        int * v6060 = v6009->cache_tags;
        int v6061 = v6060[v6160];
        int * v6062 = v6009->cache_vals;
        int v6164 = ((4 + ((((int)((unsigned int)((int)((unsigned int)(v6017 + 4) >> 2)) >> 1)) & 3) * 2)) + ((((v6053 + ((~(((v6055 ^ -1) | (-(v6055 ^ -1))) >> 31)) & 2)) - (v6056 + ((~(((v6057 ^ -1) | (-(v6057 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
        int v6063 = v6062[v6164];
        int v6165 = (((4 + ((((int)((unsigned int)((int)((unsigned int)(v6017 + 4) >> 2)) >> 1)) & 3) * 2)) + ((((v6053 + ((~(((v6055 ^ -1) | (-(v6055 ^ -1))) >> 31)) & 2)) - (v6056 + ((~(((v6057 ^ -1) | (-(v6057 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
        int v6064 = v6062[v6165];
        int * v6065 = v6009->mem;
        int v6167 = v6061 * 2;
        v6065[v6167] = v6063;
        int * v6067 = v6009->mem;
        int v6170 = (v6061 * 2) + 1;
        v6067[v6170] = v6064;
        ;
      } else {
        ;
      }
      int * v6072 = v6009->mem;
      int v6175 = ((int)((unsigned int)((int)((unsigned int)(v6017 + 4) >> 2)) >> 1)) * 2;
      int v6073 = v6072[v6175];
      int v6176 = (((int)((unsigned int)((int)((unsigned int)(v6017 + 4) >> 2)) >> 1)) * 2) + 1;
      int v6074 = v6072[v6176];
      int * v6075 = v6009->cache_vals;
      int v6178 = ((4 + ((((int)((unsigned int)((int)((unsigned int)(v6017 + 4) >> 2)) >> 1)) & 3) * 2)) + ((((v6053 + ((~(((v6055 ^ -1) | (-(v6055 ^ -1))) >> 31)) & 2)) - (v6056 + ((~(((v6057 ^ -1) | (-(v6057 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
      v6075[v6178] = v6073;
      int * v6077 = v6009->cache_vals;
      int v6181 = (((4 + ((((int)((unsigned int)((int)((unsigned int)(v6017 + 4) >> 2)) >> 1)) & 3) * 2)) + ((((v6053 + ((~(((v6055 ^ -1) | (-(v6055 ^ -1))) >> 31)) & 2)) - (v6056 + ((~(((v6057 ^ -1) | (-(v6057 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
      v6077[v6181] = v6074;
      int * v6079 = v6009->cache_tags;
      int v6184 = (int)((unsigned int)((int)((unsigned int)(v6017 + 4) >> 2)) >> 1);
      v6079[v6160] = v6184;
      int * v6081 = v6009->cache_dirty;
      v6081[v6160] = 0;
      int * v6083 = v6009->cache_age;
      v6083[v6160] = 1;
      int * v6085 = v6009->cache_age;
      int v6086 = v6085[v6160];
      int v6087 = v6085[v6134];
      int v6190 = v6087 + ((int)((unsigned int)(v6087 - v6086) >> 31));
      v6085[v6134] = v6190;
      int * v6089 = v6009->cache_age;
      int v6090 = v6089[v6135];
      int v6192 = v6090 + ((int)((unsigned int)(v6090 - v6086) >> 31));
      v6089[v6135] = v6192;
      int * v6092 = v6009->cache_age;
      v6092[v6160] = 0;
      v6095 = v6160;
    }
    int * v6096 = v6009->cache_vals;
    int v6195 = v6095 * 2;
    int v6097 = v6096[v6195];
    int v6196 = (v6095 * 2) + 1;
    int v6098 = v6096[v6196];
    int v6197 = (((((int)((unsigned int)((int)((unsigned int)(v6017 + 4) >> 2)) >> 1)) & 1) * 2) + ((((v6037 + ((~(((v6039 ^ -1) | (-(v6039 ^ -1))) >> 31)) & 2)) - (v6040 + ((~(((v6041 ^ -1) | (-(v6041 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
    v6096[v6197] = v6097;
    int * v6100 = v6009->cache_vals;
    int v6200 = ((((((int)((unsigned int)((int)((unsigned int)(v6017 + 4) >> 2)) >> 1)) & 1) * 2) + ((((v6037 + ((~(((v6039 ^ -1) | (-(v6039 ^ -1))) >> 31)) & 2)) - (v6040 + ((~(((v6041 ^ -1) | (-(v6041 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
    v6100[v6200] = v6098;
    int * v6102 = v6009->cache_tags;
    int v6203 = ((((int)((unsigned int)((int)((unsigned int)(v6017 + 4) >> 2)) >> 1)) & 1) * 2) + ((((v6037 + ((~(((v6039 ^ -1) | (-(v6039 ^ -1))) >> 31)) & 2)) - (v6040 + ((~(((v6041 ^ -1) | (-(v6041 ^ -1))) >> 31)) & 2))) >> 31) & 1);
    int v6204 = (int)((unsigned int)((int)((unsigned int)(v6017 + 4) >> 2)) >> 1);
    v6102[v6203] = v6204;
    int * v6104 = v6009->cache_dirty;
    v6104[v6203] = 0;
    int * v6106 = v6009->cache_age;
    v6106[v6203] = 1;
    int * v6108 = v6009->cache_age;
    int v6109 = v6108[v6203];
    int v6110 = v6108[v6132];
    int v6210 = v6110 + ((int)((unsigned int)(v6110 - v6109) >> 31));
    v6108[v6132] = v6210;
    int * v6112 = v6009->cache_age;
    int v6113 = v6112[v6133];
    int v6212 = v6113 + ((int)((unsigned int)(v6113 - v6109) >> 31));
    v6112[v6133] = v6212;
    int * v6115 = v6009->cache_age;
    v6115[v6203] = 0;
    v6118 = v6203;
  }
  int v6215 = (v6118 * 2) + (((int)((unsigned int)(v6017 + 4) >> 2)) & 1);
  int v6119 = v6025[v6215];
  int * v6120 = v6009->regs;
  v6120[5] = v6119;
  struct StateT * v6122 = slot_72(v6009);
  return v6122;
}

struct StateT * slot_51(struct StateT * v3918) {
  int v3919 = v3918->timer;
  int v3927 = v3919 + 1;
  v3918->timer = v3927;
  int * v3921 = v3918->regs;
  int v3922 = v3921[5];
  int v3923 = v3921[6];
  int v3931 = v3922 ^ v3923;
  v3921[6] = v3931;
  struct StateT * v3925 = slot_52(v3918);
  return v3925;
}

struct StateT * slot_52(struct StateT * v3934) {
  int v3935 = v3934->timer;
  int v3943 = v3935 + 1;
  v3934->timer = v3943;
  int * v3937 = v3934->regs;
  int v3938 = v3937[17];
  int v3939 = v3937[7];
  int v3947 = v3938 ^ v3939;
  v3937[7] = v3947;
  struct StateT * v3941 = slot_53(v3934);
  return v3941;
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

struct StateT * slot_45(struct StateT * v3446) {
  int v3447 = v3446->timer;
  int v3557 = v3447 + 1;
  v3446->timer = v3557;
  int * v3449 = v3446->regs;
  int v3450 = v3449[15];
  int * v3451 = v3446->cache_tags;
  int v3561 = (((int)((unsigned int)((int)((unsigned int)(v3450 + 4) >> 2)) >> 1)) & 1) * 2;
  int v3452 = v3451[v3561];
  int v3562 = ((((int)((unsigned int)((int)((unsigned int)(v3450 + 4) >> 2)) >> 1)) & 1) * 2) + 1;
  int v3453 = v3451[v3562];
  int v3563 = 4 + ((((int)((unsigned int)((int)((unsigned int)(v3450 + 4) >> 2)) >> 1)) & 3) * 2);
  int v3454 = v3451[v3563];
  int v3564 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v3450 + 4) >> 2)) >> 1)) & 3) * 2)) + 1;
  int v3455 = v3451[v3564];
  int v3456 = v3446->timer;
  int v3565 = v3456 + ((100 ^ (((~(((v3454 ^ ((int)((unsigned int)((int)((unsigned int)(v3450 + 4) >> 2)) >> 1))) | (-(v3454 ^ ((int)((unsigned int)((int)((unsigned int)(v3450 + 4) >> 2)) >> 1))))) >> 31)) | (~(((v3455 ^ ((int)((unsigned int)((int)((unsigned int)(v3450 + 4) >> 2)) >> 1))) | (-(v3455 ^ ((int)((unsigned int)((int)((unsigned int)(v3450 + 4) >> 2)) >> 1))))) >> 31))) & 104)) ^ (((~(((v3452 ^ ((int)((unsigned int)((int)((unsigned int)(v3450 + 4) >> 2)) >> 1))) | (-(v3452 ^ ((int)((unsigned int)((int)((unsigned int)(v3450 + 4) >> 2)) >> 1))))) >> 31)) | (~(((v3453 ^ ((int)((unsigned int)((int)((unsigned int)(v3450 + 4) >> 2)) >> 1))) | (-(v3453 ^ ((int)((unsigned int)((int)((unsigned int)(v3450 + 4) >> 2)) >> 1))))) >> 31))) & (1 ^ (100 ^ (((~(((v3454 ^ ((int)((unsigned int)((int)((unsigned int)(v3450 + 4) >> 2)) >> 1))) | (-(v3454 ^ ((int)((unsigned int)((int)((unsigned int)(v3450 + 4) >> 2)) >> 1))))) >> 31)) | (~(((v3455 ^ ((int)((unsigned int)((int)((unsigned int)(v3450 + 4) >> 2)) >> 1))) | (-(v3455 ^ ((int)((unsigned int)((int)((unsigned int)(v3450 + 4) >> 2)) >> 1))))) >> 31))) & 104)))));
  v3446->timer = v3565;
  int * v3458 = v3446->cache_vals;
  bool v3566 = !(((~(((v3452 ^ ((int)((unsigned int)((int)((unsigned int)(v3450 + 4) >> 2)) >> 1))) | (-(v3452 ^ ((int)((unsigned int)((int)((unsigned int)(v3450 + 4) >> 2)) >> 1))))) >> 31)) | (~(((v3453 ^ ((int)((unsigned int)((int)((unsigned int)(v3450 + 4) >> 2)) >> 1))) | (-(v3453 ^ ((int)((unsigned int)((int)((unsigned int)(v3450 + 4) >> 2)) >> 1))))) >> 31))) == 0);
  int v3551;
  if (v3566) {
    int * v3459 = v3446->cache_age;
    int v3568 = ((((int)((unsigned int)((int)((unsigned int)(v3450 + 4) >> 2)) >> 1)) & 1) * 2) + ((~(((v3453 ^ ((int)((unsigned int)((int)((unsigned int)(v3450 + 4) >> 2)) >> 1))) | (-(v3453 ^ ((int)((unsigned int)((int)((unsigned int)(v3450 + 4) >> 2)) >> 1))))) >> 31)) & 1);
    int v3460 = v3459[v3568];
    int v3461 = v3459[v3561];
    int v3569 = v3461 + ((int)((unsigned int)(v3461 - v3460) >> 31));
    v3459[v3561] = v3569;
    int * v3463 = v3446->cache_age;
    int v3464 = v3463[v3562];
    int v3571 = v3464 + ((int)((unsigned int)(v3464 - v3460) >> 31));
    v3463[v3562] = v3571;
    int * v3466 = v3446->cache_age;
    v3466[v3568] = 0;
    v3551 = v3568;
  } else {
    int * v3469 = v3446->cache_age;
    int v3575 = (((int)((unsigned int)((int)((unsigned int)(v3450 + 4) >> 2)) >> 1)) & 1) * 2;
    int v3470 = v3469[v3575];
    int * v3471 = v3446->cache_tags;
    int v3472 = v3471[v3575];
    int v3473 = v3469[v3562];
    int v3474 = v3471[v3562];
    bool v3577 = !(((~(((v3454 ^ ((int)((unsigned int)((int)((unsigned int)(v3450 + 4) >> 2)) >> 1))) | (-(v3454 ^ ((int)((unsigned int)((int)((unsigned int)(v3450 + 4) >> 2)) >> 1))))) >> 31)) | (~(((v3455 ^ ((int)((unsigned int)((int)((unsigned int)(v3450 + 4) >> 2)) >> 1))) | (-(v3455 ^ ((int)((unsigned int)((int)((unsigned int)(v3450 + 4) >> 2)) >> 1))))) >> 31))) == 0);
    int v3528;
    if (v3577) {
      int * v3475 = v3446->cache_age;
      int v3579 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v3450 + 4) >> 2)) >> 1)) & 3) * 2)) + ((~(((v3455 ^ ((int)((unsigned int)((int)((unsigned int)(v3450 + 4) >> 2)) >> 1))) | (-(v3455 ^ ((int)((unsigned int)((int)((unsigned int)(v3450 + 4) >> 2)) >> 1))))) >> 31)) & 1);
      int v3476 = v3475[v3579];
      int v3477 = v3475[v3563];
      int v3580 = v3477 + ((int)((unsigned int)(v3477 - v3476) >> 31));
      v3475[v3563] = v3580;
      int * v3479 = v3446->cache_age;
      int v3480 = v3479[v3564];
      int v3582 = v3480 + ((int)((unsigned int)(v3480 - v3476) >> 31));
      v3479[v3564] = v3582;
      int * v3482 = v3446->cache_age;
      v3482[v3579] = 0;
      v3528 = v3579;
    } else {
      int * v3485 = v3446->cache_age;
      int v3586 = 4 + ((((int)((unsigned int)((int)((unsigned int)(v3450 + 4) >> 2)) >> 1)) & 3) * 2);
      int v3486 = v3485[v3586];
      int * v3487 = v3446->cache_tags;
      int v3488 = v3487[v3586];
      int v3489 = v3485[v3564];
      int v3490 = v3487[v3564];
      int * v3491 = v3446->cache_dirty;
      int v3589 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v3450 + 4) >> 2)) >> 1)) & 3) * 2)) + ((((v3486 + ((~(((v3488 ^ -1) | (-(v3488 ^ -1))) >> 31)) & 2)) - (v3489 + ((~(((v3490 ^ -1) | (-(v3490 ^ -1))) >> 31)) & 2))) >> 31) & 1);
      int v3492 = v3491[v3589];
      bool v3590 = !(v3492 == 0);
      if (v3590) {
        int * v3493 = v3446->cache_tags;
        int v3494 = v3493[v3589];
        int * v3495 = v3446->cache_vals;
        int v3593 = ((4 + ((((int)((unsigned int)((int)((unsigned int)(v3450 + 4) >> 2)) >> 1)) & 3) * 2)) + ((((v3486 + ((~(((v3488 ^ -1) | (-(v3488 ^ -1))) >> 31)) & 2)) - (v3489 + ((~(((v3490 ^ -1) | (-(v3490 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
        int v3496 = v3495[v3593];
        int v3594 = (((4 + ((((int)((unsigned int)((int)((unsigned int)(v3450 + 4) >> 2)) >> 1)) & 3) * 2)) + ((((v3486 + ((~(((v3488 ^ -1) | (-(v3488 ^ -1))) >> 31)) & 2)) - (v3489 + ((~(((v3490 ^ -1) | (-(v3490 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
        int v3497 = v3495[v3594];
        int * v3498 = v3446->mem;
        int v3596 = v3494 * 2;
        v3498[v3596] = v3496;
        int * v3500 = v3446->mem;
        int v3599 = (v3494 * 2) + 1;
        v3500[v3599] = v3497;
        ;
      } else {
        ;
      }
      int * v3505 = v3446->mem;
      int v3604 = ((int)((unsigned int)((int)((unsigned int)(v3450 + 4) >> 2)) >> 1)) * 2;
      int v3506 = v3505[v3604];
      int v3605 = (((int)((unsigned int)((int)((unsigned int)(v3450 + 4) >> 2)) >> 1)) * 2) + 1;
      int v3507 = v3505[v3605];
      int * v3508 = v3446->cache_vals;
      int v3607 = ((4 + ((((int)((unsigned int)((int)((unsigned int)(v3450 + 4) >> 2)) >> 1)) & 3) * 2)) + ((((v3486 + ((~(((v3488 ^ -1) | (-(v3488 ^ -1))) >> 31)) & 2)) - (v3489 + ((~(((v3490 ^ -1) | (-(v3490 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
      v3508[v3607] = v3506;
      int * v3510 = v3446->cache_vals;
      int v3610 = (((4 + ((((int)((unsigned int)((int)((unsigned int)(v3450 + 4) >> 2)) >> 1)) & 3) * 2)) + ((((v3486 + ((~(((v3488 ^ -1) | (-(v3488 ^ -1))) >> 31)) & 2)) - (v3489 + ((~(((v3490 ^ -1) | (-(v3490 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
      v3510[v3610] = v3507;
      int * v3512 = v3446->cache_tags;
      int v3613 = (int)((unsigned int)((int)((unsigned int)(v3450 + 4) >> 2)) >> 1);
      v3512[v3589] = v3613;
      int * v3514 = v3446->cache_dirty;
      v3514[v3589] = 0;
      int * v3516 = v3446->cache_age;
      v3516[v3589] = 1;
      int * v3518 = v3446->cache_age;
      int v3519 = v3518[v3589];
      int v3520 = v3518[v3563];
      int v3619 = v3520 + ((int)((unsigned int)(v3520 - v3519) >> 31));
      v3518[v3563] = v3619;
      int * v3522 = v3446->cache_age;
      int v3523 = v3522[v3564];
      int v3621 = v3523 + ((int)((unsigned int)(v3523 - v3519) >> 31));
      v3522[v3564] = v3621;
      int * v3525 = v3446->cache_age;
      v3525[v3589] = 0;
      v3528 = v3589;
    }
    int * v3529 = v3446->cache_vals;
    int v3624 = v3528 * 2;
    int v3530 = v3529[v3624];
    int v3625 = (v3528 * 2) + 1;
    int v3531 = v3529[v3625];
    int v3626 = (((((int)((unsigned int)((int)((unsigned int)(v3450 + 4) >> 2)) >> 1)) & 1) * 2) + ((((v3470 + ((~(((v3472 ^ -1) | (-(v3472 ^ -1))) >> 31)) & 2)) - (v3473 + ((~(((v3474 ^ -1) | (-(v3474 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
    v3529[v3626] = v3530;
    int * v3533 = v3446->cache_vals;
    int v3629 = ((((((int)((unsigned int)((int)((unsigned int)(v3450 + 4) >> 2)) >> 1)) & 1) * 2) + ((((v3470 + ((~(((v3472 ^ -1) | (-(v3472 ^ -1))) >> 31)) & 2)) - (v3473 + ((~(((v3474 ^ -1) | (-(v3474 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
    v3533[v3629] = v3531;
    int * v3535 = v3446->cache_tags;
    int v3632 = ((((int)((unsigned int)((int)((unsigned int)(v3450 + 4) >> 2)) >> 1)) & 1) * 2) + ((((v3470 + ((~(((v3472 ^ -1) | (-(v3472 ^ -1))) >> 31)) & 2)) - (v3473 + ((~(((v3474 ^ -1) | (-(v3474 ^ -1))) >> 31)) & 2))) >> 31) & 1);
    int v3633 = (int)((unsigned int)((int)((unsigned int)(v3450 + 4) >> 2)) >> 1);
    v3535[v3632] = v3633;
    int * v3537 = v3446->cache_dirty;
    v3537[v3632] = 0;
    int * v3539 = v3446->cache_age;
    v3539[v3632] = 1;
    int * v3541 = v3446->cache_age;
    int v3542 = v3541[v3632];
    int v3543 = v3541[v3561];
    int v3639 = v3543 + ((int)((unsigned int)(v3543 - v3542) >> 31));
    v3541[v3561] = v3639;
    int * v3545 = v3446->cache_age;
    int v3546 = v3545[v3562];
    int v3641 = v3546 + ((int)((unsigned int)(v3546 - v3542) >> 31));
    v3545[v3562] = v3641;
    int * v3548 = v3446->cache_age;
    v3548[v3632] = 0;
    v3551 = v3632;
  }
  int v3644 = (v3551 * 2) + (((int)((unsigned int)(v3450 + 4) >> 2)) & 1);
  int v3552 = v3458[v3644];
  int * v3553 = v3446->regs;
  v3553[6] = v3552;
  struct StateT * v3555 = slot_46(v3446);
  return v3555;
}

struct StateT * slot_73(struct StateT * v6431) {
  int * v6432 = v6431->saved_regs;
  int * v6433 = v6431->regs;
  int v6434 = v6433[7];
  v6432[7] = v6434;
  int v6436 = v6431->timer;
  int v6550 = v6436 + 1;
  v6431->timer = v6550;
  int * v6438 = v6431->regs;
  int v6439 = v6438[15];
  int * v6440 = v6431->cache_tags;
  int v6554 = (((int)((unsigned int)((int)((unsigned int)v6439 >> 2)) >> 1)) & 1) * 2;
  int v6441 = v6440[v6554];
  int v6555 = ((((int)((unsigned int)((int)((unsigned int)v6439 >> 2)) >> 1)) & 1) * 2) + 1;
  int v6442 = v6440[v6555];
  int v6556 = 4 + ((((int)((unsigned int)((int)((unsigned int)v6439 >> 2)) >> 1)) & 3) * 2);
  int v6443 = v6440[v6556];
  int v6557 = (4 + ((((int)((unsigned int)((int)((unsigned int)v6439 >> 2)) >> 1)) & 3) * 2)) + 1;
  int v6444 = v6440[v6557];
  int v6445 = v6431->timer;
  int v6558 = v6445 + ((100 ^ (((~(((v6443 ^ ((int)((unsigned int)((int)((unsigned int)v6439 >> 2)) >> 1))) | (-(v6443 ^ ((int)((unsigned int)((int)((unsigned int)v6439 >> 2)) >> 1))))) >> 31)) | (~(((v6444 ^ ((int)((unsigned int)((int)((unsigned int)v6439 >> 2)) >> 1))) | (-(v6444 ^ ((int)((unsigned int)((int)((unsigned int)v6439 >> 2)) >> 1))))) >> 31))) & 104)) ^ (((~(((v6441 ^ ((int)((unsigned int)((int)((unsigned int)v6439 >> 2)) >> 1))) | (-(v6441 ^ ((int)((unsigned int)((int)((unsigned int)v6439 >> 2)) >> 1))))) >> 31)) | (~(((v6442 ^ ((int)((unsigned int)((int)((unsigned int)v6439 >> 2)) >> 1))) | (-(v6442 ^ ((int)((unsigned int)((int)((unsigned int)v6439 >> 2)) >> 1))))) >> 31))) & (1 ^ (100 ^ (((~(((v6443 ^ ((int)((unsigned int)((int)((unsigned int)v6439 >> 2)) >> 1))) | (-(v6443 ^ ((int)((unsigned int)((int)((unsigned int)v6439 >> 2)) >> 1))))) >> 31)) | (~(((v6444 ^ ((int)((unsigned int)((int)((unsigned int)v6439 >> 2)) >> 1))) | (-(v6444 ^ ((int)((unsigned int)((int)((unsigned int)v6439 >> 2)) >> 1))))) >> 31))) & 104)))));
  v6431->timer = v6558;
  int * v6447 = v6431->cache_vals;
  bool v6559 = !(((~(((v6441 ^ ((int)((unsigned int)((int)((unsigned int)v6439 >> 2)) >> 1))) | (-(v6441 ^ ((int)((unsigned int)((int)((unsigned int)v6439 >> 2)) >> 1))))) >> 31)) | (~(((v6442 ^ ((int)((unsigned int)((int)((unsigned int)v6439 >> 2)) >> 1))) | (-(v6442 ^ ((int)((unsigned int)((int)((unsigned int)v6439 >> 2)) >> 1))))) >> 31))) == 0);
  int v6540;
  if (v6559) {
    int * v6448 = v6431->cache_age;
    int v6561 = ((((int)((unsigned int)((int)((unsigned int)v6439 >> 2)) >> 1)) & 1) * 2) + ((~(((v6442 ^ ((int)((unsigned int)((int)((unsigned int)v6439 >> 2)) >> 1))) | (-(v6442 ^ ((int)((unsigned int)((int)((unsigned int)v6439 >> 2)) >> 1))))) >> 31)) & 1);
    int v6449 = v6448[v6561];
    int v6450 = v6448[v6554];
    int v6562 = v6450 + ((int)((unsigned int)(v6450 - v6449) >> 31));
    v6448[v6554] = v6562;
    int * v6452 = v6431->cache_age;
    int v6453 = v6452[v6555];
    int v6564 = v6453 + ((int)((unsigned int)(v6453 - v6449) >> 31));
    v6452[v6555] = v6564;
    int * v6455 = v6431->cache_age;
    v6455[v6561] = 0;
    v6540 = v6561;
  } else {
    int * v6458 = v6431->cache_age;
    int v6568 = (((int)((unsigned int)((int)((unsigned int)v6439 >> 2)) >> 1)) & 1) * 2;
    int v6459 = v6458[v6568];
    int * v6460 = v6431->cache_tags;
    int v6461 = v6460[v6568];
    int v6462 = v6458[v6555];
    int v6463 = v6460[v6555];
    bool v6570 = !(((~(((v6443 ^ ((int)((unsigned int)((int)((unsigned int)v6439 >> 2)) >> 1))) | (-(v6443 ^ ((int)((unsigned int)((int)((unsigned int)v6439 >> 2)) >> 1))))) >> 31)) | (~(((v6444 ^ ((int)((unsigned int)((int)((unsigned int)v6439 >> 2)) >> 1))) | (-(v6444 ^ ((int)((unsigned int)((int)((unsigned int)v6439 >> 2)) >> 1))))) >> 31))) == 0);
    int v6517;
    if (v6570) {
      int * v6464 = v6431->cache_age;
      int v6572 = (4 + ((((int)((unsigned int)((int)((unsigned int)v6439 >> 2)) >> 1)) & 3) * 2)) + ((~(((v6444 ^ ((int)((unsigned int)((int)((unsigned int)v6439 >> 2)) >> 1))) | (-(v6444 ^ ((int)((unsigned int)((int)((unsigned int)v6439 >> 2)) >> 1))))) >> 31)) & 1);
      int v6465 = v6464[v6572];
      int v6466 = v6464[v6556];
      int v6573 = v6466 + ((int)((unsigned int)(v6466 - v6465) >> 31));
      v6464[v6556] = v6573;
      int * v6468 = v6431->cache_age;
      int v6469 = v6468[v6557];
      int v6575 = v6469 + ((int)((unsigned int)(v6469 - v6465) >> 31));
      v6468[v6557] = v6575;
      int * v6471 = v6431->cache_age;
      v6471[v6572] = 0;
      v6517 = v6572;
    } else {
      int * v6474 = v6431->cache_age;
      int v6579 = 4 + ((((int)((unsigned int)((int)((unsigned int)v6439 >> 2)) >> 1)) & 3) * 2);
      int v6475 = v6474[v6579];
      int * v6476 = v6431->cache_tags;
      int v6477 = v6476[v6579];
      int v6478 = v6474[v6557];
      int v6479 = v6476[v6557];
      int * v6480 = v6431->cache_dirty;
      int v6582 = (4 + ((((int)((unsigned int)((int)((unsigned int)v6439 >> 2)) >> 1)) & 3) * 2)) + ((((v6475 + ((~(((v6477 ^ -1) | (-(v6477 ^ -1))) >> 31)) & 2)) - (v6478 + ((~(((v6479 ^ -1) | (-(v6479 ^ -1))) >> 31)) & 2))) >> 31) & 1);
      int v6481 = v6480[v6582];
      bool v6583 = !(v6481 == 0);
      if (v6583) {
        int * v6482 = v6431->cache_tags;
        int v6483 = v6482[v6582];
        int * v6484 = v6431->cache_vals;
        int v6586 = ((4 + ((((int)((unsigned int)((int)((unsigned int)v6439 >> 2)) >> 1)) & 3) * 2)) + ((((v6475 + ((~(((v6477 ^ -1) | (-(v6477 ^ -1))) >> 31)) & 2)) - (v6478 + ((~(((v6479 ^ -1) | (-(v6479 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
        int v6485 = v6484[v6586];
        int v6587 = (((4 + ((((int)((unsigned int)((int)((unsigned int)v6439 >> 2)) >> 1)) & 3) * 2)) + ((((v6475 + ((~(((v6477 ^ -1) | (-(v6477 ^ -1))) >> 31)) & 2)) - (v6478 + ((~(((v6479 ^ -1) | (-(v6479 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
        int v6486 = v6484[v6587];
        int * v6487 = v6431->mem;
        int v6589 = v6483 * 2;
        v6487[v6589] = v6485;
        int * v6489 = v6431->mem;
        int v6592 = (v6483 * 2) + 1;
        v6489[v6592] = v6486;
        ;
      } else {
        ;
      }
      int * v6494 = v6431->mem;
      int v6597 = ((int)((unsigned int)((int)((unsigned int)v6439 >> 2)) >> 1)) * 2;
      int v6495 = v6494[v6597];
      int v6598 = (((int)((unsigned int)((int)((unsigned int)v6439 >> 2)) >> 1)) * 2) + 1;
      int v6496 = v6494[v6598];
      int * v6497 = v6431->cache_vals;
      int v6600 = ((4 + ((((int)((unsigned int)((int)((unsigned int)v6439 >> 2)) >> 1)) & 3) * 2)) + ((((v6475 + ((~(((v6477 ^ -1) | (-(v6477 ^ -1))) >> 31)) & 2)) - (v6478 + ((~(((v6479 ^ -1) | (-(v6479 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
      v6497[v6600] = v6495;
      int * v6499 = v6431->cache_vals;
      int v6603 = (((4 + ((((int)((unsigned int)((int)((unsigned int)v6439 >> 2)) >> 1)) & 3) * 2)) + ((((v6475 + ((~(((v6477 ^ -1) | (-(v6477 ^ -1))) >> 31)) & 2)) - (v6478 + ((~(((v6479 ^ -1) | (-(v6479 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
      v6499[v6603] = v6496;
      int * v6501 = v6431->cache_tags;
      int v6606 = (int)((unsigned int)((int)((unsigned int)v6439 >> 2)) >> 1);
      v6501[v6582] = v6606;
      int * v6503 = v6431->cache_dirty;
      v6503[v6582] = 0;
      int * v6505 = v6431->cache_age;
      v6505[v6582] = 1;
      int * v6507 = v6431->cache_age;
      int v6508 = v6507[v6582];
      int v6509 = v6507[v6556];
      int v6612 = v6509 + ((int)((unsigned int)(v6509 - v6508) >> 31));
      v6507[v6556] = v6612;
      int * v6511 = v6431->cache_age;
      int v6512 = v6511[v6557];
      int v6614 = v6512 + ((int)((unsigned int)(v6512 - v6508) >> 31));
      v6511[v6557] = v6614;
      int * v6514 = v6431->cache_age;
      v6514[v6582] = 0;
      v6517 = v6582;
    }
    int * v6518 = v6431->cache_vals;
    int v6617 = v6517 * 2;
    int v6519 = v6518[v6617];
    int v6618 = (v6517 * 2) + 1;
    int v6520 = v6518[v6618];
    int v6619 = (((((int)((unsigned int)((int)((unsigned int)v6439 >> 2)) >> 1)) & 1) * 2) + ((((v6459 + ((~(((v6461 ^ -1) | (-(v6461 ^ -1))) >> 31)) & 2)) - (v6462 + ((~(((v6463 ^ -1) | (-(v6463 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
    v6518[v6619] = v6519;
    int * v6522 = v6431->cache_vals;
    int v6622 = ((((((int)((unsigned int)((int)((unsigned int)v6439 >> 2)) >> 1)) & 1) * 2) + ((((v6459 + ((~(((v6461 ^ -1) | (-(v6461 ^ -1))) >> 31)) & 2)) - (v6462 + ((~(((v6463 ^ -1) | (-(v6463 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
    v6522[v6622] = v6520;
    int * v6524 = v6431->cache_tags;
    int v6625 = ((((int)((unsigned int)((int)((unsigned int)v6439 >> 2)) >> 1)) & 1) * 2) + ((((v6459 + ((~(((v6461 ^ -1) | (-(v6461 ^ -1))) >> 31)) & 2)) - (v6462 + ((~(((v6463 ^ -1) | (-(v6463 ^ -1))) >> 31)) & 2))) >> 31) & 1);
    int v6626 = (int)((unsigned int)((int)((unsigned int)v6439 >> 2)) >> 1);
    v6524[v6625] = v6626;
    int * v6526 = v6431->cache_dirty;
    v6526[v6625] = 0;
    int * v6528 = v6431->cache_age;
    v6528[v6625] = 1;
    int * v6530 = v6431->cache_age;
    int v6531 = v6530[v6625];
    int v6532 = v6530[v6554];
    int v6632 = v6532 + ((int)((unsigned int)(v6532 - v6531) >> 31));
    v6530[v6554] = v6632;
    int * v6534 = v6431->cache_age;
    int v6535 = v6534[v6555];
    int v6634 = v6535 + ((int)((unsigned int)(v6535 - v6531) >> 31));
    v6534[v6555] = v6634;
    int * v6537 = v6431->cache_age;
    v6537[v6625] = 0;
    v6540 = v6625;
  }
  int v6637 = (v6540 * 2) + (((int)((unsigned int)v6439 >> 2)) & 1);
  int v6541 = v6447[v6637];
  int * v6542 = v6431->regs;
  v6542[7] = v6541;
  struct StateT * v6544 = slot_74(v6431);
  return v6544;
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

struct StateT * slot_69(struct StateT * v5782) {
  int v5783 = v5782->timer;
  int v5791 = v5783 + 1;
  v5782->timer = v5791;
  int * v5785 = v5782->regs;
  int v5786 = v5785[11];
  int v5787 = v5785[15];
  int v5795 = v5786 + v5787;
  v5785[15] = v5795;
  struct StateT * v5789 = slot_70(v5782);
  return v5789;
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
  struct StateT * v2991 = slot_40(v2985);
  return v2991;
}

struct StateT * slot_63(struct StateT * v5084) {
  int v5085 = v5084->timer;
  int v5255 = v5085 + 1;
  v5084->timer = v5255;
  int * v5087 = v5084->regs;
  int v5088 = v5087[15];
  int v5089 = v5087[17];
  int * v5090 = v5084->cache_tags;
  int v5260 = (((int)((unsigned int)((int)((unsigned int)v5088 >> 2)) >> 1)) & 1) * 2;
  int v5091 = v5090[v5260];
  int v5261 = ((((int)((unsigned int)((int)((unsigned int)v5088 >> 2)) >> 1)) & 1) * 2) + 1;
  int v5092 = v5090[v5261];
  int v5262 = 4 + ((((int)((unsigned int)((int)((unsigned int)v5088 >> 2)) >> 1)) & 3) * 2);
  int v5093 = v5090[v5262];
  int v5263 = (4 + ((((int)((unsigned int)((int)((unsigned int)v5088 >> 2)) >> 1)) & 3) * 2)) + 1;
  int v5094 = v5090[v5263];
  int v5095 = v5084->timer;
  int v5264 = v5095 + ((100 ^ (((~(((v5093 ^ ((int)((unsigned int)((int)((unsigned int)v5088 >> 2)) >> 1))) | (-(v5093 ^ ((int)((unsigned int)((int)((unsigned int)v5088 >> 2)) >> 1))))) >> 31)) | (~(((v5094 ^ ((int)((unsigned int)((int)((unsigned int)v5088 >> 2)) >> 1))) | (-(v5094 ^ ((int)((unsigned int)((int)((unsigned int)v5088 >> 2)) >> 1))))) >> 31))) & 104)) ^ (((~(((v5091 ^ ((int)((unsigned int)((int)((unsigned int)v5088 >> 2)) >> 1))) | (-(v5091 ^ ((int)((unsigned int)((int)((unsigned int)v5088 >> 2)) >> 1))))) >> 31)) | (~(((v5092 ^ ((int)((unsigned int)((int)((unsigned int)v5088 >> 2)) >> 1))) | (-(v5092 ^ ((int)((unsigned int)((int)((unsigned int)v5088 >> 2)) >> 1))))) >> 31))) & (1 ^ (100 ^ (((~(((v5093 ^ ((int)((unsigned int)((int)((unsigned int)v5088 >> 2)) >> 1))) | (-(v5093 ^ ((int)((unsigned int)((int)((unsigned int)v5088 >> 2)) >> 1))))) >> 31)) | (~(((v5094 ^ ((int)((unsigned int)((int)((unsigned int)v5088 >> 2)) >> 1))) | (-(v5094 ^ ((int)((unsigned int)((int)((unsigned int)v5088 >> 2)) >> 1))))) >> 31))) & 104)))));
  v5084->timer = v5264;
  bool v5265 = !(((~(((v5091 ^ ((int)((unsigned int)((int)((unsigned int)v5088 >> 2)) >> 1))) | (-(v5091 ^ ((int)((unsigned int)((int)((unsigned int)v5088 >> 2)) >> 1))))) >> 31)) | (~(((v5092 ^ ((int)((unsigned int)((int)((unsigned int)v5088 >> 2)) >> 1))) | (-(v5092 ^ ((int)((unsigned int)((int)((unsigned int)v5088 >> 2)) >> 1))))) >> 31))) == 0);
  int v5189;
  if (v5265) {
    int * v5097 = v5084->cache_age;
    int v5267 = ((((int)((unsigned int)((int)((unsigned int)v5088 >> 2)) >> 1)) & 1) * 2) + ((~(((v5092 ^ ((int)((unsigned int)((int)((unsigned int)v5088 >> 2)) >> 1))) | (-(v5092 ^ ((int)((unsigned int)((int)((unsigned int)v5088 >> 2)) >> 1))))) >> 31)) & 1);
    int v5098 = v5097[v5267];
    int v5099 = v5097[v5260];
    int v5268 = v5099 + ((int)((unsigned int)(v5099 - v5098) >> 31));
    v5097[v5260] = v5268;
    int * v5101 = v5084->cache_age;
    int v5102 = v5101[v5261];
    int v5270 = v5102 + ((int)((unsigned int)(v5102 - v5098) >> 31));
    v5101[v5261] = v5270;
    int * v5104 = v5084->cache_age;
    v5104[v5267] = 0;
    v5189 = v5267;
  } else {
    int * v5107 = v5084->cache_age;
    int v5274 = (((int)((unsigned int)((int)((unsigned int)v5088 >> 2)) >> 1)) & 1) * 2;
    int v5108 = v5107[v5274];
    int * v5109 = v5084->cache_tags;
    int v5110 = v5109[v5274];
    int v5111 = v5107[v5261];
    int v5112 = v5109[v5261];
    bool v5276 = !(((~(((v5093 ^ ((int)((unsigned int)((int)((unsigned int)v5088 >> 2)) >> 1))) | (-(v5093 ^ ((int)((unsigned int)((int)((unsigned int)v5088 >> 2)) >> 1))))) >> 31)) | (~(((v5094 ^ ((int)((unsigned int)((int)((unsigned int)v5088 >> 2)) >> 1))) | (-(v5094 ^ ((int)((unsigned int)((int)((unsigned int)v5088 >> 2)) >> 1))))) >> 31))) == 0);
    int v5166;
    if (v5276) {
      int * v5113 = v5084->cache_age;
      int v5278 = (4 + ((((int)((unsigned int)((int)((unsigned int)v5088 >> 2)) >> 1)) & 3) * 2)) + ((~(((v5094 ^ ((int)((unsigned int)((int)((unsigned int)v5088 >> 2)) >> 1))) | (-(v5094 ^ ((int)((unsigned int)((int)((unsigned int)v5088 >> 2)) >> 1))))) >> 31)) & 1);
      int v5114 = v5113[v5278];
      int v5115 = v5113[v5262];
      int v5279 = v5115 + ((int)((unsigned int)(v5115 - v5114) >> 31));
      v5113[v5262] = v5279;
      int * v5117 = v5084->cache_age;
      int v5118 = v5117[v5263];
      int v5281 = v5118 + ((int)((unsigned int)(v5118 - v5114) >> 31));
      v5117[v5263] = v5281;
      int * v5120 = v5084->cache_age;
      v5120[v5278] = 0;
      v5166 = v5278;
    } else {
      int * v5123 = v5084->cache_age;
      int v5285 = 4 + ((((int)((unsigned int)((int)((unsigned int)v5088 >> 2)) >> 1)) & 3) * 2);
      int v5124 = v5123[v5285];
      int * v5125 = v5084->cache_tags;
      int v5126 = v5125[v5285];
      int v5127 = v5123[v5263];
      int v5128 = v5125[v5263];
      int * v5129 = v5084->cache_dirty;
      int v5288 = (4 + ((((int)((unsigned int)((int)((unsigned int)v5088 >> 2)) >> 1)) & 3) * 2)) + ((((v5124 + ((~(((v5126 ^ -1) | (-(v5126 ^ -1))) >> 31)) & 2)) - (v5127 + ((~(((v5128 ^ -1) | (-(v5128 ^ -1))) >> 31)) & 2))) >> 31) & 1);
      int v5130 = v5129[v5288];
      bool v5289 = !(v5130 == 0);
      if (v5289) {
        int * v5131 = v5084->cache_tags;
        int v5132 = v5131[v5288];
        int * v5133 = v5084->cache_vals;
        int v5292 = ((4 + ((((int)((unsigned int)((int)((unsigned int)v5088 >> 2)) >> 1)) & 3) * 2)) + ((((v5124 + ((~(((v5126 ^ -1) | (-(v5126 ^ -1))) >> 31)) & 2)) - (v5127 + ((~(((v5128 ^ -1) | (-(v5128 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
        int v5134 = v5133[v5292];
        int v5293 = (((4 + ((((int)((unsigned int)((int)((unsigned int)v5088 >> 2)) >> 1)) & 3) * 2)) + ((((v5124 + ((~(((v5126 ^ -1) | (-(v5126 ^ -1))) >> 31)) & 2)) - (v5127 + ((~(((v5128 ^ -1) | (-(v5128 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
        int v5135 = v5133[v5293];
        int * v5136 = v5084->mem;
        int v5295 = v5132 * 2;
        v5136[v5295] = v5134;
        int * v5138 = v5084->mem;
        int v5298 = (v5132 * 2) + 1;
        v5138[v5298] = v5135;
        ;
      } else {
        ;
      }
      int * v5143 = v5084->mem;
      int v5303 = ((int)((unsigned int)((int)((unsigned int)v5088 >> 2)) >> 1)) * 2;
      int v5144 = v5143[v5303];
      int v5304 = (((int)((unsigned int)((int)((unsigned int)v5088 >> 2)) >> 1)) * 2) + 1;
      int v5145 = v5143[v5304];
      int * v5146 = v5084->cache_vals;
      int v5306 = ((4 + ((((int)((unsigned int)((int)((unsigned int)v5088 >> 2)) >> 1)) & 3) * 2)) + ((((v5124 + ((~(((v5126 ^ -1) | (-(v5126 ^ -1))) >> 31)) & 2)) - (v5127 + ((~(((v5128 ^ -1) | (-(v5128 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
      v5146[v5306] = v5144;
      int * v5148 = v5084->cache_vals;
      int v5309 = (((4 + ((((int)((unsigned int)((int)((unsigned int)v5088 >> 2)) >> 1)) & 3) * 2)) + ((((v5124 + ((~(((v5126 ^ -1) | (-(v5126 ^ -1))) >> 31)) & 2)) - (v5127 + ((~(((v5128 ^ -1) | (-(v5128 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
      v5148[v5309] = v5145;
      int * v5150 = v5084->cache_tags;
      int v5312 = (int)((unsigned int)((int)((unsigned int)v5088 >> 2)) >> 1);
      v5150[v5288] = v5312;
      int * v5152 = v5084->cache_dirty;
      v5152[v5288] = 0;
      int * v5154 = v5084->cache_age;
      v5154[v5288] = 1;
      int * v5156 = v5084->cache_age;
      int v5157 = v5156[v5288];
      int v5158 = v5156[v5262];
      int v5318 = v5158 + ((int)((unsigned int)(v5158 - v5157) >> 31));
      v5156[v5262] = v5318;
      int * v5160 = v5084->cache_age;
      int v5161 = v5160[v5263];
      int v5320 = v5161 + ((int)((unsigned int)(v5161 - v5157) >> 31));
      v5160[v5263] = v5320;
      int * v5163 = v5084->cache_age;
      v5163[v5288] = 0;
      v5166 = v5288;
    }
    int * v5167 = v5084->cache_vals;
    int v5323 = v5166 * 2;
    int v5168 = v5167[v5323];
    int v5324 = (v5166 * 2) + 1;
    int v5169 = v5167[v5324];
    int v5325 = (((((int)((unsigned int)((int)((unsigned int)v5088 >> 2)) >> 1)) & 1) * 2) + ((((v5108 + ((~(((v5110 ^ -1) | (-(v5110 ^ -1))) >> 31)) & 2)) - (v5111 + ((~(((v5112 ^ -1) | (-(v5112 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
    v5167[v5325] = v5168;
    int * v5171 = v5084->cache_vals;
    int v5328 = ((((((int)((unsigned int)((int)((unsigned int)v5088 >> 2)) >> 1)) & 1) * 2) + ((((v5108 + ((~(((v5110 ^ -1) | (-(v5110 ^ -1))) >> 31)) & 2)) - (v5111 + ((~(((v5112 ^ -1) | (-(v5112 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
    v5171[v5328] = v5169;
    int * v5173 = v5084->cache_tags;
    int v5331 = ((((int)((unsigned int)((int)((unsigned int)v5088 >> 2)) >> 1)) & 1) * 2) + ((((v5108 + ((~(((v5110 ^ -1) | (-(v5110 ^ -1))) >> 31)) & 2)) - (v5111 + ((~(((v5112 ^ -1) | (-(v5112 ^ -1))) >> 31)) & 2))) >> 31) & 1);
    int v5332 = (int)((unsigned int)((int)((unsigned int)v5088 >> 2)) >> 1);
    v5173[v5331] = v5332;
    int * v5175 = v5084->cache_dirty;
    v5175[v5331] = 0;
    int * v5177 = v5084->cache_age;
    v5177[v5331] = 1;
    int * v5179 = v5084->cache_age;
    int v5180 = v5179[v5331];
    int v5181 = v5179[v5260];
    int v5338 = v5181 + ((int)((unsigned int)(v5181 - v5180) >> 31));
    v5179[v5260] = v5338;
    int * v5183 = v5084->cache_age;
    int v5184 = v5183[v5261];
    int v5340 = v5184 + ((int)((unsigned int)(v5184 - v5180) >> 31));
    v5183[v5261] = v5340;
    int * v5186 = v5084->cache_age;
    v5186[v5331] = 0;
    v5189 = v5331;
  }
  int * v5190 = v5084->cache_vals;
  int v5343 = (v5189 * 2) + (((int)((unsigned int)v5088 >> 2)) & 1);
  v5190[v5343] = v5089;
  int * v5192 = v5084->cache_tags;
  int v5193 = v5192[v5262];
  int v5194 = v5192[v5263];
  bool v5346 = !(((~(((v5193 ^ ((int)((unsigned int)((int)((unsigned int)v5088 >> 2)) >> 1))) | (-(v5193 ^ ((int)((unsigned int)((int)((unsigned int)v5088 >> 2)) >> 1))))) >> 31)) | (~(((v5194 ^ ((int)((unsigned int)((int)((unsigned int)v5088 >> 2)) >> 1))) | (-(v5194 ^ ((int)((unsigned int)((int)((unsigned int)v5088 >> 2)) >> 1))))) >> 31))) == 0);
  int v5248;
  if (v5346) {
    int * v5195 = v5084->cache_age;
    int v5348 = (4 + ((((int)((unsigned int)((int)((unsigned int)v5088 >> 2)) >> 1)) & 3) * 2)) + ((~(((v5194 ^ ((int)((unsigned int)((int)((unsigned int)v5088 >> 2)) >> 1))) | (-(v5194 ^ ((int)((unsigned int)((int)((unsigned int)v5088 >> 2)) >> 1))))) >> 31)) & 1);
    int v5196 = v5195[v5348];
    int v5197 = v5195[v5262];
    int v5349 = v5197 + ((int)((unsigned int)(v5197 - v5196) >> 31));
    v5195[v5262] = v5349;
    int * v5199 = v5084->cache_age;
    int v5200 = v5199[v5263];
    int v5351 = v5200 + ((int)((unsigned int)(v5200 - v5196) >> 31));
    v5199[v5263] = v5351;
    int * v5202 = v5084->cache_age;
    v5202[v5348] = 0;
    v5248 = v5348;
  } else {
    int * v5205 = v5084->cache_age;
    int v5355 = 4 + ((((int)((unsigned int)((int)((unsigned int)v5088 >> 2)) >> 1)) & 3) * 2);
    int v5206 = v5205[v5355];
    int * v5207 = v5084->cache_tags;
    int v5208 = v5207[v5355];
    int v5209 = v5205[v5263];
    int v5210 = v5207[v5263];
    int * v5211 = v5084->cache_dirty;
    int v5358 = (4 + ((((int)((unsigned int)((int)((unsigned int)v5088 >> 2)) >> 1)) & 3) * 2)) + ((((v5206 + ((~(((v5208 ^ -1) | (-(v5208 ^ -1))) >> 31)) & 2)) - (v5209 + ((~(((v5210 ^ -1) | (-(v5210 ^ -1))) >> 31)) & 2))) >> 31) & 1);
    int v5212 = v5211[v5358];
    bool v5359 = !(v5212 == 0);
    if (v5359) {
      int * v5213 = v5084->cache_tags;
      int v5214 = v5213[v5358];
      int * v5215 = v5084->cache_vals;
      int v5362 = ((4 + ((((int)((unsigned int)((int)((unsigned int)v5088 >> 2)) >> 1)) & 3) * 2)) + ((((v5206 + ((~(((v5208 ^ -1) | (-(v5208 ^ -1))) >> 31)) & 2)) - (v5209 + ((~(((v5210 ^ -1) | (-(v5210 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
      int v5216 = v5215[v5362];
      int v5363 = (((4 + ((((int)((unsigned int)((int)((unsigned int)v5088 >> 2)) >> 1)) & 3) * 2)) + ((((v5206 + ((~(((v5208 ^ -1) | (-(v5208 ^ -1))) >> 31)) & 2)) - (v5209 + ((~(((v5210 ^ -1) | (-(v5210 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
      int v5217 = v5215[v5363];
      int * v5218 = v5084->mem;
      int v5365 = v5214 * 2;
      v5218[v5365] = v5216;
      int * v5220 = v5084->mem;
      int v5368 = (v5214 * 2) + 1;
      v5220[v5368] = v5217;
      ;
    } else {
      ;
    }
    int * v5225 = v5084->mem;
    int v5373 = ((int)((unsigned int)((int)((unsigned int)v5088 >> 2)) >> 1)) * 2;
    int v5226 = v5225[v5373];
    int v5374 = (((int)((unsigned int)((int)((unsigned int)v5088 >> 2)) >> 1)) * 2) + 1;
    int v5227 = v5225[v5374];
    int * v5228 = v5084->cache_vals;
    int v5376 = ((4 + ((((int)((unsigned int)((int)((unsigned int)v5088 >> 2)) >> 1)) & 3) * 2)) + ((((v5206 + ((~(((v5208 ^ -1) | (-(v5208 ^ -1))) >> 31)) & 2)) - (v5209 + ((~(((v5210 ^ -1) | (-(v5210 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
    v5228[v5376] = v5226;
    int * v5230 = v5084->cache_vals;
    int v5379 = (((4 + ((((int)((unsigned int)((int)((unsigned int)v5088 >> 2)) >> 1)) & 3) * 2)) + ((((v5206 + ((~(((v5208 ^ -1) | (-(v5208 ^ -1))) >> 31)) & 2)) - (v5209 + ((~(((v5210 ^ -1) | (-(v5210 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
    v5230[v5379] = v5227;
    int * v5232 = v5084->cache_tags;
    int v5382 = (int)((unsigned int)((int)((unsigned int)v5088 >> 2)) >> 1);
    v5232[v5358] = v5382;
    int * v5234 = v5084->cache_dirty;
    v5234[v5358] = 0;
    int * v5236 = v5084->cache_age;
    v5236[v5358] = 1;
    int * v5238 = v5084->cache_age;
    int v5239 = v5238[v5358];
    int v5240 = v5238[v5262];
    int v5388 = v5240 + ((int)((unsigned int)(v5240 - v5239) >> 31));
    v5238[v5262] = v5388;
    int * v5242 = v5084->cache_age;
    int v5243 = v5242[v5263];
    int v5390 = v5243 + ((int)((unsigned int)(v5243 - v5239) >> 31));
    v5242[v5263] = v5390;
    int * v5245 = v5084->cache_age;
    v5245[v5358] = 0;
    v5248 = v5358;
  }
  int * v5249 = v5084->cache_vals;
  int v5393 = (v5248 * 2) + (((int)((unsigned int)v5088 >> 2)) & 1);
  v5249[v5393] = v5089;
  int * v5251 = v5084->cache_dirty;
  v5251[v5248] = 1;
  struct StateT * v5253 = slot_64(v5084);
  return v5253;
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

struct StateT * slot_42(struct StateT * v3022) {
  int v3023 = v3022->timer;
  int v3031 = v3023 + 1;
  v3022->timer = v3031;
  int * v3025 = v3022->regs;
  int v3026 = v3025[11];
  int v3027 = v3025[15];
  int v3035 = v3026 + v3027;
  v3025[15] = v3035;
  struct StateT * v3029 = slot_43(v3022);
  return v3029;
}

struct StateT * slot_46(struct StateT * v3650) {
  int v3651 = v3650->timer;
  int v3761 = v3651 + 1;
  v3650->timer = v3761;
  int * v3653 = v3650->regs;
  int v3654 = v3653[15];
  int * v3655 = v3650->cache_tags;
  int v3765 = (((int)((unsigned int)((int)((unsigned int)v3654 >> 2)) >> 1)) & 1) * 2;
  int v3656 = v3655[v3765];
  int v3766 = ((((int)((unsigned int)((int)((unsigned int)v3654 >> 2)) >> 1)) & 1) * 2) + 1;
  int v3657 = v3655[v3766];
  int v3767 = 4 + ((((int)((unsigned int)((int)((unsigned int)v3654 >> 2)) >> 1)) & 3) * 2);
  int v3658 = v3655[v3767];
  int v3768 = (4 + ((((int)((unsigned int)((int)((unsigned int)v3654 >> 2)) >> 1)) & 3) * 2)) + 1;
  int v3659 = v3655[v3768];
  int v3660 = v3650->timer;
  int v3769 = v3660 + ((100 ^ (((~(((v3658 ^ ((int)((unsigned int)((int)((unsigned int)v3654 >> 2)) >> 1))) | (-(v3658 ^ ((int)((unsigned int)((int)((unsigned int)v3654 >> 2)) >> 1))))) >> 31)) | (~(((v3659 ^ ((int)((unsigned int)((int)((unsigned int)v3654 >> 2)) >> 1))) | (-(v3659 ^ ((int)((unsigned int)((int)((unsigned int)v3654 >> 2)) >> 1))))) >> 31))) & 104)) ^ (((~(((v3656 ^ ((int)((unsigned int)((int)((unsigned int)v3654 >> 2)) >> 1))) | (-(v3656 ^ ((int)((unsigned int)((int)((unsigned int)v3654 >> 2)) >> 1))))) >> 31)) | (~(((v3657 ^ ((int)((unsigned int)((int)((unsigned int)v3654 >> 2)) >> 1))) | (-(v3657 ^ ((int)((unsigned int)((int)((unsigned int)v3654 >> 2)) >> 1))))) >> 31))) & (1 ^ (100 ^ (((~(((v3658 ^ ((int)((unsigned int)((int)((unsigned int)v3654 >> 2)) >> 1))) | (-(v3658 ^ ((int)((unsigned int)((int)((unsigned int)v3654 >> 2)) >> 1))))) >> 31)) | (~(((v3659 ^ ((int)((unsigned int)((int)((unsigned int)v3654 >> 2)) >> 1))) | (-(v3659 ^ ((int)((unsigned int)((int)((unsigned int)v3654 >> 2)) >> 1))))) >> 31))) & 104)))));
  v3650->timer = v3769;
  int * v3662 = v3650->cache_vals;
  bool v3770 = !(((~(((v3656 ^ ((int)((unsigned int)((int)((unsigned int)v3654 >> 2)) >> 1))) | (-(v3656 ^ ((int)((unsigned int)((int)((unsigned int)v3654 >> 2)) >> 1))))) >> 31)) | (~(((v3657 ^ ((int)((unsigned int)((int)((unsigned int)v3654 >> 2)) >> 1))) | (-(v3657 ^ ((int)((unsigned int)((int)((unsigned int)v3654 >> 2)) >> 1))))) >> 31))) == 0);
  int v3755;
  if (v3770) {
    int * v3663 = v3650->cache_age;
    int v3772 = ((((int)((unsigned int)((int)((unsigned int)v3654 >> 2)) >> 1)) & 1) * 2) + ((~(((v3657 ^ ((int)((unsigned int)((int)((unsigned int)v3654 >> 2)) >> 1))) | (-(v3657 ^ ((int)((unsigned int)((int)((unsigned int)v3654 >> 2)) >> 1))))) >> 31)) & 1);
    int v3664 = v3663[v3772];
    int v3665 = v3663[v3765];
    int v3773 = v3665 + ((int)((unsigned int)(v3665 - v3664) >> 31));
    v3663[v3765] = v3773;
    int * v3667 = v3650->cache_age;
    int v3668 = v3667[v3766];
    int v3775 = v3668 + ((int)((unsigned int)(v3668 - v3664) >> 31));
    v3667[v3766] = v3775;
    int * v3670 = v3650->cache_age;
    v3670[v3772] = 0;
    v3755 = v3772;
  } else {
    int * v3673 = v3650->cache_age;
    int v3779 = (((int)((unsigned int)((int)((unsigned int)v3654 >> 2)) >> 1)) & 1) * 2;
    int v3674 = v3673[v3779];
    int * v3675 = v3650->cache_tags;
    int v3676 = v3675[v3779];
    int v3677 = v3673[v3766];
    int v3678 = v3675[v3766];
    bool v3781 = !(((~(((v3658 ^ ((int)((unsigned int)((int)((unsigned int)v3654 >> 2)) >> 1))) | (-(v3658 ^ ((int)((unsigned int)((int)((unsigned int)v3654 >> 2)) >> 1))))) >> 31)) | (~(((v3659 ^ ((int)((unsigned int)((int)((unsigned int)v3654 >> 2)) >> 1))) | (-(v3659 ^ ((int)((unsigned int)((int)((unsigned int)v3654 >> 2)) >> 1))))) >> 31))) == 0);
    int v3732;
    if (v3781) {
      int * v3679 = v3650->cache_age;
      int v3783 = (4 + ((((int)((unsigned int)((int)((unsigned int)v3654 >> 2)) >> 1)) & 3) * 2)) + ((~(((v3659 ^ ((int)((unsigned int)((int)((unsigned int)v3654 >> 2)) >> 1))) | (-(v3659 ^ ((int)((unsigned int)((int)((unsigned int)v3654 >> 2)) >> 1))))) >> 31)) & 1);
      int v3680 = v3679[v3783];
      int v3681 = v3679[v3767];
      int v3784 = v3681 + ((int)((unsigned int)(v3681 - v3680) >> 31));
      v3679[v3767] = v3784;
      int * v3683 = v3650->cache_age;
      int v3684 = v3683[v3768];
      int v3786 = v3684 + ((int)((unsigned int)(v3684 - v3680) >> 31));
      v3683[v3768] = v3786;
      int * v3686 = v3650->cache_age;
      v3686[v3783] = 0;
      v3732 = v3783;
    } else {
      int * v3689 = v3650->cache_age;
      int v3790 = 4 + ((((int)((unsigned int)((int)((unsigned int)v3654 >> 2)) >> 1)) & 3) * 2);
      int v3690 = v3689[v3790];
      int * v3691 = v3650->cache_tags;
      int v3692 = v3691[v3790];
      int v3693 = v3689[v3768];
      int v3694 = v3691[v3768];
      int * v3695 = v3650->cache_dirty;
      int v3793 = (4 + ((((int)((unsigned int)((int)((unsigned int)v3654 >> 2)) >> 1)) & 3) * 2)) + ((((v3690 + ((~(((v3692 ^ -1) | (-(v3692 ^ -1))) >> 31)) & 2)) - (v3693 + ((~(((v3694 ^ -1) | (-(v3694 ^ -1))) >> 31)) & 2))) >> 31) & 1);
      int v3696 = v3695[v3793];
      bool v3794 = !(v3696 == 0);
      if (v3794) {
        int * v3697 = v3650->cache_tags;
        int v3698 = v3697[v3793];
        int * v3699 = v3650->cache_vals;
        int v3797 = ((4 + ((((int)((unsigned int)((int)((unsigned int)v3654 >> 2)) >> 1)) & 3) * 2)) + ((((v3690 + ((~(((v3692 ^ -1) | (-(v3692 ^ -1))) >> 31)) & 2)) - (v3693 + ((~(((v3694 ^ -1) | (-(v3694 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
        int v3700 = v3699[v3797];
        int v3798 = (((4 + ((((int)((unsigned int)((int)((unsigned int)v3654 >> 2)) >> 1)) & 3) * 2)) + ((((v3690 + ((~(((v3692 ^ -1) | (-(v3692 ^ -1))) >> 31)) & 2)) - (v3693 + ((~(((v3694 ^ -1) | (-(v3694 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
        int v3701 = v3699[v3798];
        int * v3702 = v3650->mem;
        int v3800 = v3698 * 2;
        v3702[v3800] = v3700;
        int * v3704 = v3650->mem;
        int v3803 = (v3698 * 2) + 1;
        v3704[v3803] = v3701;
        ;
      } else {
        ;
      }
      int * v3709 = v3650->mem;
      int v3808 = ((int)((unsigned int)((int)((unsigned int)v3654 >> 2)) >> 1)) * 2;
      int v3710 = v3709[v3808];
      int v3809 = (((int)((unsigned int)((int)((unsigned int)v3654 >> 2)) >> 1)) * 2) + 1;
      int v3711 = v3709[v3809];
      int * v3712 = v3650->cache_vals;
      int v3811 = ((4 + ((((int)((unsigned int)((int)((unsigned int)v3654 >> 2)) >> 1)) & 3) * 2)) + ((((v3690 + ((~(((v3692 ^ -1) | (-(v3692 ^ -1))) >> 31)) & 2)) - (v3693 + ((~(((v3694 ^ -1) | (-(v3694 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
      v3712[v3811] = v3710;
      int * v3714 = v3650->cache_vals;
      int v3814 = (((4 + ((((int)((unsigned int)((int)((unsigned int)v3654 >> 2)) >> 1)) & 3) * 2)) + ((((v3690 + ((~(((v3692 ^ -1) | (-(v3692 ^ -1))) >> 31)) & 2)) - (v3693 + ((~(((v3694 ^ -1) | (-(v3694 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
      v3714[v3814] = v3711;
      int * v3716 = v3650->cache_tags;
      int v3817 = (int)((unsigned int)((int)((unsigned int)v3654 >> 2)) >> 1);
      v3716[v3793] = v3817;
      int * v3718 = v3650->cache_dirty;
      v3718[v3793] = 0;
      int * v3720 = v3650->cache_age;
      v3720[v3793] = 1;
      int * v3722 = v3650->cache_age;
      int v3723 = v3722[v3793];
      int v3724 = v3722[v3767];
      int v3823 = v3724 + ((int)((unsigned int)(v3724 - v3723) >> 31));
      v3722[v3767] = v3823;
      int * v3726 = v3650->cache_age;
      int v3727 = v3726[v3768];
      int v3825 = v3727 + ((int)((unsigned int)(v3727 - v3723) >> 31));
      v3726[v3768] = v3825;
      int * v3729 = v3650->cache_age;
      v3729[v3793] = 0;
      v3732 = v3793;
    }
    int * v3733 = v3650->cache_vals;
    int v3828 = v3732 * 2;
    int v3734 = v3733[v3828];
    int v3829 = (v3732 * 2) + 1;
    int v3735 = v3733[v3829];
    int v3830 = (((((int)((unsigned int)((int)((unsigned int)v3654 >> 2)) >> 1)) & 1) * 2) + ((((v3674 + ((~(((v3676 ^ -1) | (-(v3676 ^ -1))) >> 31)) & 2)) - (v3677 + ((~(((v3678 ^ -1) | (-(v3678 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
    v3733[v3830] = v3734;
    int * v3737 = v3650->cache_vals;
    int v3833 = ((((((int)((unsigned int)((int)((unsigned int)v3654 >> 2)) >> 1)) & 1) * 2) + ((((v3674 + ((~(((v3676 ^ -1) | (-(v3676 ^ -1))) >> 31)) & 2)) - (v3677 + ((~(((v3678 ^ -1) | (-(v3678 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
    v3737[v3833] = v3735;
    int * v3739 = v3650->cache_tags;
    int v3836 = ((((int)((unsigned int)((int)((unsigned int)v3654 >> 2)) >> 1)) & 1) * 2) + ((((v3674 + ((~(((v3676 ^ -1) | (-(v3676 ^ -1))) >> 31)) & 2)) - (v3677 + ((~(((v3678 ^ -1) | (-(v3678 ^ -1))) >> 31)) & 2))) >> 31) & 1);
    int v3837 = (int)((unsigned int)((int)((unsigned int)v3654 >> 2)) >> 1);
    v3739[v3836] = v3837;
    int * v3741 = v3650->cache_dirty;
    v3741[v3836] = 0;
    int * v3743 = v3650->cache_age;
    v3743[v3836] = 1;
    int * v3745 = v3650->cache_age;
    int v3746 = v3745[v3836];
    int v3747 = v3745[v3765];
    int v3843 = v3747 + ((int)((unsigned int)(v3747 - v3746) >> 31));
    v3745[v3765] = v3843;
    int * v3749 = v3650->cache_age;
    int v3750 = v3749[v3766];
    int v3845 = v3750 + ((int)((unsigned int)(v3750 - v3746) >> 31));
    v3749[v3766] = v3845;
    int * v3752 = v3650->cache_age;
    v3752[v3836] = 0;
    v3755 = v3836;
  }
  int v3848 = (v3755 * 2) + (((int)((unsigned int)v3654 >> 2)) & 1);
  int v3756 = v3662[v3848];
  int * v3757 = v3650->regs;
  v3757[7] = v3756;
  struct StateT * v3759 = slot_47(v3650);
  return v3759;
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

struct StateT * slot_61(struct StateT * v5052) {
  int v5053 = v5052->timer;
  int v5061 = v5053 + 1;
  v5052->timer = v5061;
  int * v5055 = v5052->regs;
  int v5056 = v5055[16];
  int v5057 = v5055[5];
  int v5065 = v5056 ^ v5057;
  v5055[16] = v5065;
  struct StateT * v5059 = slot_62(v5052);
  return v5059;
}

struct StateT * snippet(struct StateT * v0) {
  struct StateT * v1 = slot_0(v0);
  return v1;
}

struct StateT * slot_79(struct StateT * v6722) {
  int v6723 = v6722->timer;
  int v6731 = v6723 + 1;
  v6722->timer = v6731;
  int * v6725 = v6722->regs;
  int v6726 = v6725[17];
  int v6727 = v6725[7];
  int v6735 = v6726 ^ v6727;
  v6725[7] = v6735;
  struct StateT * v6729 = slot_80(v6722);
  return v6729;
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

struct StateT * slot_60(struct StateT * v5036) {
  int v5037 = v5036->timer;
  int v5045 = v5037 + 1;
  v5036->timer = v5045;
  int * v5039 = v5036->regs;
  int v5040 = v5039[13];
  int v5041 = v5039[5];
  int v5049 = v5040 & v5041;
  v5039[5] = v5049;
  struct StateT * v5043 = slot_61(v5036);
  return v5043;
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