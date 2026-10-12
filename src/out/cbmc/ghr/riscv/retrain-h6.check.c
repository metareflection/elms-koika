// verify: clean (CBMC should report VERIFICATION SUCCESSFUL) [unwind 513]
#define NUM_REGS 32
#define MEM_SIZE 64
#define SECRET_SIZE 10
#define SECRET_OFFSET 20
#define CACHE_ENTRIES 12
#define CACHE_WORDS 24
#define PHT_ENTRIES 512
#define HISTORY_BITS 6

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
  int pht[512];
  int timer;
};

void ret_assert(bool);

struct StateG * slot_12(struct StateG * v417);
struct StateG * slot_228(struct StateG * v4060);
struct StateG * slot_143(struct StateG * v2620);
struct StateG * slot_120(struct StateG * v2216);
struct StateG * slot_167(struct StateG * v3400);
struct StateG * slot_152(struct StateG * v2800);
struct StateG * slot_199(struct StateG * v3768);
struct StateG * slot_92(struct StateG * v1854);
struct StateG * slot_31(struct StateG * v784);
struct StateG * slot_160(struct StateG * v3120);
struct StateG * slot_65(struct StateG * v1272);
struct StateG * slot_10(struct StateG * v396);
struct StateG * slot_150(struct StateG * v2760);
struct StateG * slot_74(struct StateG * v1492);
struct StateG * slot_107(struct StateG * v2047);
struct StateG * slot_136(struct StateG * v2480);
struct StateG * slot_84(struct StateG * v1770);
struct StateG * slot_28(struct StateG * v664);
struct StateG * slot_155(struct StateG * v2920);
struct StateG * slot_177(struct StateG * v3532);
struct StateG * slot_17(struct StateG * v479);
struct StateG * slot_207(struct StateG * v3874);
struct StateG * slot_156(struct StateG * v2960);
struct StateG * slot_154(struct StateG * v2880);
struct StateG * slot_68(struct StateG * v1332);
struct StateG * slot_105(struct StateG * v2021);
struct StateG * slot_27(struct StateG * v644);
struct StateG * slot_164(struct StateG * v3280);
struct StateG * slot_15(struct StateG * v452);
struct StateG * slot_133(struct StateG * v2420);
struct StateG * slot_56(struct StateG * v1120);
struct StateG * slot_34(struct StateG * v845);
struct StateG * slot_162(struct StateG * v3200);
struct StateG * slot_21(struct StateG * v531);
struct StateG * slot_118(struct StateG * v2190);
struct StateG * slot_121(struct StateG * v2229);
struct StateG * slot_144(struct StateG * v2640);
struct StateG * slot_94(struct StateG * v1875);
struct StateG * slot_63(struct StateG * v1232);
struct StateG * slot_146(struct StateG * v2680);
struct StateG * slot_24(struct StateG * v584);
struct StateG * slot_0(struct StateG * v2);
struct StateG * slot_125(struct StateG * v2281);
struct StateG * slot_148(struct StateG * v2720);
struct StateG * slot_126(struct StateG * v2294);
struct StateG * slot_79(struct StateG * v1689);
struct StateG * slot_41(struct StateG * v922);
struct StateG * slot_39(struct StateG * v900);
struct StateG * slot_142(struct StateG * v2600);
struct StateG * slot_60(struct StateG * v1172);
struct StateG * slot_112(struct StateG * v2112);
struct StateG * slot_47(struct StateG * v1003);
struct StateG * slot_29(struct StateG * v704);
struct StateG * slot_16(struct StateG * v466);
struct StateG * slot_113(struct StateG * v2125);
struct StateG * slot_151(struct StateG * v2780);
struct StateG * slot_7(struct StateG * v298);
struct StateG * slot_124(struct StateG * v2268);
struct StateG * slot_103(struct StateG * v1994);
struct StateG * slot_128(struct StateG * v2320);
struct StateG * slot_19(struct StateG * v505);
struct StateG * slot_87(struct StateG * v1804);
struct StateG * slot_67(struct StateG * v1312);
struct StateG * slot_81(struct StateG * v1736);
struct StateG * slot_95(struct StateG * v1888);
struct StateG * slot_115(struct StateG * v2151);
struct StateG * slot_78(struct StateG * v1650);
struct StateG * slot_32(struct StateG * v824);
struct StateG * slot_33(struct StateG * v832);
struct StateG * slot_35(struct StateG * v858);
struct StateG * slot_166(struct StateG * v3360);
struct StateG * slot_51(struct StateG * v1055);
struct StateG * slot_52(struct StateG * v1068);
struct StateG * slot_83(struct StateG * v1762);
struct StateG * slot_25(struct StateG * v604);
struct StateG * slot_3(struct StateG * v232);
struct StateG * slot_123(struct StateG * v2255);
struct StateG * slot_73(struct StateG * v1452);
struct StateG * slot_198(struct StateG * v3755);
struct StateG * slot_1(struct StateG * v15);
struct StateG * slot_97(struct StateG * v1910);
struct StateG * slot_38(struct StateG * v887);
struct StateG * slot_106(struct StateG * v2034);
struct StateG * slot_98(struct StateG * v1924);
struct StateG * slot_159(struct StateG * v3080);
struct StateG * slot_46(struct StateG * v990);
struct StateG * slot_132(struct StateG * v2400);
struct StateG * slot_130(struct StateG * v2360);
struct StateG * slot_20(struct StateG * v518);
struct StateG * slot_141(struct StateG * v2580);
struct StateG * slot_61(struct StateG * v1192);
struct StateG * slot_30(struct StateG * v744);
struct StateG * slot_4(struct StateG * v245);
struct StateG * slot_18(struct StateG * v492);
struct StateG * slot_9(struct StateG * v357);
struct StateG * slot_43(struct StateG * v950);
struct StateG * slot_70(struct StateG * v1372);
struct StateG * slot_76(struct StateG * v1572);
struct StateG * slot_6(struct StateG * v278);
struct StateG * slot_55(struct StateG * v1107);
struct StateG * slot_82(struct StateG * v1749);
struct StateG * slot_161(struct StateG * v3160);
struct StateG * slot_91(struct StateG * v1846);
struct StateG * slot_58(struct StateG * v1146);
struct StateG * slot_89(struct StateG * v1820);
struct StateG * slot_66(struct StateG * v1292);
struct StateG * slot_140(struct StateG * v2560);
struct StateG * slot_49(struct StateG * v1029);
struct StateG * slot_50(struct StateG * v1042);
struct StateG * slot_37(struct StateG * v874);
struct StateG * slot_114(struct StateG * v2138);
struct StateG * slot_135(struct StateG * v2460);
struct StateG * slot_59(struct StateG * v1159);
struct StateG * slot_40(struct StateG * v908);
struct StateG * slot_48(struct StateG * v1016);
struct StateG * slot_77(struct StateG * v1611);
struct StateG * slot_85(struct StateG * v1778);
struct StateG * slot_75(struct StateG * v1532);
struct StateG * slot_72(struct StateG * v1412);
struct StateG * slot_119(struct StateG * v2203);
struct StateG * slot_71(struct StateG * v1392);
struct StateG * slot_101(struct StateG * v1966);
struct StateG * slot_108(struct StateG * v2060);
struct StateG * slot_116(struct StateG * v2164);
struct StateG * slot_93(struct StateG * v1862);
struct StateG * slot_88(struct StateG * v1812);
struct StateG * slot_96(struct StateG * v1896);
struct StateG * slot_45(struct StateG * v977);
struct StateG * slot_134(struct StateG * v2440);
struct StateG * slot_69(struct StateG * v1352);
struct StateG * slot_138(struct StateG * v2520);
struct StateG * slot_102(struct StateG * v1980);
struct StateG * slot_145(struct StateG * v2660);
struct StateG * slot_110(struct StateG * v2086);
struct StateG * slot_131(struct StateG * v2380);
struct StateG * slot_8(struct StateG * v318);
struct StateG * slot_157(struct StateG * v3000);
struct StateG * slot_149(struct StateG * v2740);
struct StateG * slot_5(struct StateG * v258);
struct StateG * slot_104(struct StateG * v2008);
struct StateG * slot_54(struct StateG * v1094);
struct StateG * slot_26(struct StateG * v624);
struct StateG * slot_64(struct StateG * v1252);
struct StateG * slot_14(struct StateG * v438);
struct StateG * slot_53(struct StateG * v1081);
struct StateG * slot_80(struct StateG * v1728);
struct StateG * slot_44(struct StateG * v964);
struct StateG * slot_137(struct StateG * v2500);
struct StateG * slot_122(struct StateG * v2242);
struct StateG * slot_99(struct StateG * v1938);
struct StateG * slot_36(struct StateG * v866);
struct StateG * slot_57(struct StateG * v1133);
struct StateG * slot_62(struct StateG * v1212);
struct StateG * slot_22(struct StateG * v544);
struct StateG * slot_139(struct StateG * v2540);
struct StateG * slot_23(struct StateG * v564);
struct StateG * slot_153(struct StateG * v2840);
struct StateG * slot_2(struct StateG * v219);
struct StateG * slot_86(struct StateG * v1791);
struct StateG * slot_129(struct StateG * v2340);
struct StateG * slot_158(struct StateG * v3040);
struct StateG * slot_100(struct StateG * v1952);
struct StateG * slot_127(struct StateG * v2307);
struct StateG * slot_13(struct StateG * v430);
struct StateG * slot_111(struct StateG * v2099);
struct StateG * slot_109(struct StateG * v2073);
struct StateG * slot_147(struct StateG * v2700);
struct StateG * slot_42(struct StateG * v936);
struct StateG * slot_163(struct StateG * v3240);
struct StateG * slot_165(struct StateG * v3320);
struct StateG * snippet(struct StateG * v0);
struct StateG * slot_117(struct StateG * v2177);
struct StateG * slot_90(struct StateG * v1833);
struct StateG * slot_11(struct StateG * v404);
struct StateG * slot_12(struct StateG * v417) {
  int v418 = v417->timer;
  int v424 = v418 + 1;
  v417->timer = v424;
  int * v420 = v417->regs;
  v420[18] = 2;
  struct StateG * v422 = slot_10(v417);
  return v422;
}

struct StateG * slot_228(struct StateG * v4060) {
  int v4061 = v4060->timer;
  int v4064 = v4061 + 1;
  v4060->timer = v4064;
  return v4060;
}

struct StateG * slot_143(struct StateG * v2620) {
  int * v2621 = v2620->saved_regs;
  int * v2622 = v2620->regs;
  int v2623 = v2622[19];
  v2621[19] = v2623;
  int v2625 = v2620->timer;
  int v2635 = v2625 + 1;
  v2620->timer = v2635;
  int * v2627 = v2620->regs;
  v2627[19] = 1;
  struct StateG * v2629 = slot_159(v2620);
  return v2629;
}

struct StateG * slot_120(struct StateG * v2216) {
  int v2217 = v2216->timer;
  int v2223 = v2217 + 1;
  v2216->timer = v2223;
  int * v2219 = v2216->regs;
  v2219[17] = 10;
  struct StateG * v2221 = slot_128(v2216);
  return v2221;
}

struct StateG * slot_167(struct StateG * v3400) {
  int * v3401 = v3400->regs;
  int v3402 = v3401[16];
  int v3403 = v3401[17];
  bool v3423 = v3402 >= v3403;
  struct StateG * v3418;
  if (v3423) {
    int * v3404 = v3400->pht;
    v3404[64] = 1;
    int v3406 = v3400->timer;
    int v3427 = v3406 + 15;
    v3400->timer = v3427;
    int * v3408 = v3400->saved_regs;
    int v3409 = v3408[19];
    int * v3410 = v3400->regs;
    v3410[19] = v3409;
    struct StateG * v3412 = slot_198(v3400);
    v3418 = v3412;
  } else {
    int * v3414 = v3400->pht;
    v3414[64] = 0;
    struct StateG * v3416 = slot_199(v3400);
    v3418 = v3416;
  }
  return v3418;
}

struct StateG * slot_152(struct StateG * v2800) {
  int * v2801 = v2800->regs;
  int v2802 = v2801[16];
  int v2803 = v2801[17];
  bool v2823 = v2802 >= v2803;
  struct StateG * v2818;
  if (v2823) {
    int * v2804 = v2800->pht;
    v2804[71] = 1;
    struct StateG * v2806 = slot_199(v2800);
    v2818 = v2806;
  } else {
    int * v2808 = v2800->pht;
    v2808[71] = 0;
    int v2810 = v2800->timer;
    int v2832 = v2810 + 15;
    v2800->timer = v2832;
    int * v2812 = v2800->saved_regs;
    int v2813 = v2812[19];
    int * v2814 = v2800->regs;
    v2814[19] = v2813;
    struct StateG * v2816 = slot_177(v2800);
    v2818 = v2816;
  }
  return v2818;
}

struct StateG * slot_199(struct StateG * v3768) {
  int v3769 = v3768->timer;
  int v3773 = v3769 + 1;
  v3768->timer = v3773;
  struct StateG * v3771 = slot_207(v3768);
  return v3771;
}

struct StateG * slot_92(struct StateG * v1854) {
  int v1855 = v1854->timer;
  int v1859 = v1855 + 1;
  v1854->timer = v1859;
  struct StateG * v1857 = slot_102(v1854);
  return v1857;
}

struct StateG * slot_31(struct StateG * v784) {
  int * v785 = v784->regs;
  int v786 = v785[16];
  int v787 = v785[17];
  bool v807 = v786 >= v787;
  struct StateG * v802;
  if (v807) {
    int * v788 = v784->pht;
    v788[64] = 1;
    int v790 = v784->timer;
    int v811 = v790 + 15;
    v784->timer = v811;
    int * v792 = v784->saved_regs;
    int v793 = v792[19];
    int * v794 = v784->regs;
    v794[19] = v793;
    struct StateG * v796 = slot_38(v784);
    v802 = v796;
  } else {
    int * v798 = v784->pht;
    v798[64] = 0;
    struct StateG * v800 = slot_39(v784);
    v802 = v800;
  }
  return v802;
}

struct StateG * slot_160(struct StateG * v3120) {
  int * v3121 = v3120->regs;
  int v3122 = v3121[16];
  int v3123 = v3121[17];
  bool v3143 = v3122 >= v3123;
  struct StateG * v3138;
  if (v3143) {
    int * v3124 = v3120->pht;
    v3124[67] = 1;
    struct StateG * v3126 = slot_199(v3120);
    v3138 = v3126;
  } else {
    int * v3128 = v3120->pht;
    v3128[67] = 0;
    int v3130 = v3120->timer;
    int v3152 = v3130 + 15;
    v3120->timer = v3152;
    int * v3132 = v3120->saved_regs;
    int v3133 = v3132[19];
    int * v3134 = v3120->regs;
    v3134[19] = v3133;
    struct StateG * v3136 = slot_177(v3120);
    v3138 = v3136;
  }
  return v3138;
}

struct StateG * slot_65(struct StateG * v1272) {
  int * v1273 = v1272->saved_regs;
  int * v1274 = v1272->regs;
  int v1275 = v1274[18];
  v1273[18] = v1275;
  int v1277 = v1272->timer;
  int v1287 = v1277 + 1;
  v1272->timer = v1287;
  int * v1279 = v1272->regs;
  v1279[18] = 1;
  struct StateG * v1281 = slot_73(v1272);
  return v1281;
}

struct StateG * slot_10(struct StateG * v396) {
  int v397 = v396->timer;
  int v401 = v397 + 1;
  v396->timer = v401;
  struct StateG * v399 = slot_14(v396);
  return v399;
}

struct StateG * slot_150(struct StateG * v2760) {
  int * v2761 = v2760->saved_regs;
  int * v2762 = v2760->regs;
  int v2763 = v2762[19];
  v2761[19] = v2763;
  int v2765 = v2760->timer;
  int v2775 = v2765 + 1;
  v2760->timer = v2775;
  int * v2767 = v2760->regs;
  v2767[19] = 2;
  struct StateG * v2769 = slot_166(v2760);
  return v2769;
}

struct StateG * slot_74(struct StateG * v1492) {
  int * v1493 = v1492->regs;
  int v1494 = v1493[16];
  int v1495 = v1493[17];
  bool v1515 = v1494 < v1495;
  struct StateG * v1510;
  if (v1515) {
    int * v1496 = v1492->pht;
    v1496[2] = 1;
    struct StateG * v1498 = slot_84(v1492);
    v1510 = v1498;
  } else {
    int * v1500 = v1492->pht;
    v1500[2] = 0;
    int v1502 = v1492->timer;
    int v1524 = v1502 + 15;
    v1492->timer = v1524;
    int * v1504 = v1492->saved_regs;
    int v1505 = v1504[18];
    int * v1506 = v1492->regs;
    v1506[18] = v1505;
    struct StateG * v1508 = slot_85(v1492);
    v1510 = v1508;
  }
  return v1510;
}

struct StateG * slot_107(struct StateG * v2047) {
  int v2048 = v2047->timer;
  int v2054 = v2048 + 1;
  v2047->timer = v2054;
  int * v2050 = v2047->regs;
  v2050[1] = 36;
  struct StateG * v2052 = slot_115(v2047);
  return v2052;
}

struct StateG * slot_136(struct StateG * v2480) {
  int * v2481 = v2480->saved_regs;
  int * v2482 = v2480->regs;
  int v2483 = v2482[19];
  v2481[19] = v2483;
  int v2485 = v2480->timer;
  int v2495 = v2485 + 1;
  v2480->timer = v2495;
  int * v2487 = v2480->regs;
  v2487[19] = 2;
  struct StateG * v2489 = slot_152(v2480);
  return v2489;
}

struct StateG * slot_84(struct StateG * v1770) {
  int v1771 = v1770->timer;
  int v1775 = v1771 + 1;
  v1770->timer = v1775;
  struct StateG * v1773 = slot_98(v1770);
  return v1773;
}

struct StateG * slot_28(struct StateG * v664) {
  int * v665 = v664->regs;
  int v666 = v665[16];
  int v667 = v665[17];
  bool v687 = v666 >= v667;
  struct StateG * v682;
  if (v687) {
    int * v668 = v664->pht;
    v668[65] = 1;
    struct StateG * v670 = slot_32(v664);
    v682 = v670;
  } else {
    int * v672 = v664->pht;
    v672[65] = 0;
    int v674 = v664->timer;
    int v696 = v674 + 15;
    v664->timer = v696;
    int * v676 = v664->saved_regs;
    int v677 = v676[19];
    int * v678 = v664->regs;
    v678[19] = v677;
    struct StateG * v680 = slot_33(v664);
    v682 = v680;
  }
  return v682;
}

struct StateG * slot_155(struct StateG * v2920) {
  int * v2921 = v2920->regs;
  int v2922 = v2921[16];
  int v2923 = v2921[17];
  bool v2943 = v2922 >= v2923;
  struct StateG * v2938;
  if (v2943) {
    int * v2924 = v2920->pht;
    v2924[70] = 1;
    int v2926 = v2920->timer;
    int v2947 = v2926 + 15;
    v2920->timer = v2947;
    int * v2928 = v2920->saved_regs;
    int v2929 = v2928[19];
    int * v2930 = v2920->regs;
    v2930[19] = v2929;
    struct StateG * v2932 = slot_198(v2920);
    v2938 = v2932;
  } else {
    int * v2934 = v2920->pht;
    v2934[70] = 0;
    struct StateG * v2936 = slot_199(v2920);
    v2938 = v2936;
  }
  return v2938;
}

struct StateG * slot_177(struct StateG * v3532) {
  int v3533 = v3532->timer;
  int v3539 = v3533 + 1;
  v3532->timer = v3539;
  int * v3535 = v3532->regs;
  v3535[19] = 1;
  struct StateG * v3537 = slot_199(v3532);
  return v3537;
}

struct StateG * slot_17(struct StateG * v479) {
  int v480 = v479->timer;
  int v486 = v480 + 1;
  v479->timer = v486;
  int * v482 = v479->regs;
  v482[1] = 16;
  struct StateG * v484 = slot_19(v479);
  return v484;
}

struct StateG * slot_207(struct StateG * v3874) {
  int v3875 = v3874->timer;
  int v3882 = v3875 + 1;
  v3874->timer = v3882;
  int * v3877 = v3874->regs;
  int v3878 = v3877[1];
  bool v3885 = v3878 == 44;
  ret_assert(v3885);
  struct StateG * v3880 = slot_228(v3874);
  return v3880;
}

struct StateG * slot_156(struct StateG * v2960) {
  int * v2961 = v2960->regs;
  int v2962 = v2961[16];
  int v2963 = v2961[17];
  bool v2983 = v2962 >= v2963;
  struct StateG * v2978;
  if (v2983) {
    int * v2964 = v2960->pht;
    v2964[69] = 1;
    struct StateG * v2966 = slot_199(v2960);
    v2978 = v2966;
  } else {
    int * v2968 = v2960->pht;
    v2968[69] = 0;
    int v2970 = v2960->timer;
    int v2992 = v2970 + 15;
    v2960->timer = v2992;
    int * v2972 = v2960->saved_regs;
    int v2973 = v2972[19];
    int * v2974 = v2960->regs;
    v2974[19] = v2973;
    struct StateG * v2976 = slot_177(v2960);
    v2978 = v2976;
  }
  return v2978;
}

struct StateG * slot_154(struct StateG * v2880) {
  int * v2881 = v2880->regs;
  int v2882 = v2881[16];
  int v2883 = v2881[17];
  bool v2903 = v2882 >= v2883;
  struct StateG * v2898;
  if (v2903) {
    int * v2884 = v2880->pht;
    v2884[70] = 1;
    struct StateG * v2886 = slot_199(v2880);
    v2898 = v2886;
  } else {
    int * v2888 = v2880->pht;
    v2888[70] = 0;
    int v2890 = v2880->timer;
    int v2912 = v2890 + 15;
    v2880->timer = v2912;
    int * v2892 = v2880->saved_regs;
    int v2893 = v2892[19];
    int * v2894 = v2880->regs;
    v2894[19] = v2893;
    struct StateG * v2896 = slot_177(v2880);
    v2898 = v2896;
  }
  return v2898;
}

struct StateG * slot_68(struct StateG * v1332) {
  int * v1333 = v1332->saved_regs;
  int * v1334 = v1332->regs;
  int v1335 = v1334[18];
  v1333[18] = v1335;
  int v1337 = v1332->timer;
  int v1347 = v1337 + 1;
  v1332->timer = v1347;
  int * v1339 = v1332->regs;
  v1339[18] = 2;
  struct StateG * v1341 = slot_76(v1332);
  return v1341;
}

struct StateG * slot_105(struct StateG * v2021) {
  int v2022 = v2021->timer;
  int v2028 = v2022 + 1;
  v2021->timer = v2028;
  int * v2024 = v2021->regs;
  v2024[1] = 36;
  struct StateG * v2026 = slot_113(v2021);
  return v2026;
}

struct StateG * slot_27(struct StateG * v644) {
  int * v645 = v644->saved_regs;
  int * v646 = v644->regs;
  int v647 = v646[19];
  v645[19] = v647;
  int v649 = v644->timer;
  int v659 = v649 + 1;
  v644->timer = v659;
  int * v651 = v644->regs;
  v651[19] = 1;
  struct StateG * v653 = slot_31(v644);
  return v653;
}

struct StateG * slot_164(struct StateG * v3280) {
  int * v3281 = v3280->regs;
  int v3282 = v3281[16];
  int v3283 = v3281[17];
  bool v3303 = v3282 >= v3283;
  struct StateG * v3298;
  if (v3303) {
    int * v3284 = v3280->pht;
    v3284[65] = 1;
    struct StateG * v3286 = slot_199(v3280);
    v3298 = v3286;
  } else {
    int * v3288 = v3280->pht;
    v3288[65] = 0;
    int v3290 = v3280->timer;
    int v3312 = v3290 + 15;
    v3280->timer = v3312;
    int * v3292 = v3280->saved_regs;
    int v3293 = v3292[19];
    int * v3294 = v3280->regs;
    v3294[19] = v3293;
    struct StateG * v3296 = slot_177(v3280);
    v3298 = v3296;
  }
  return v3298;
}

struct StateG * slot_15(struct StateG * v452) {
  int v453 = v452->timer;
  int v460 = v453 + 1;
  v452->timer = v460;
  int * v455 = v452->regs;
  int v456 = v455[1];
  bool v463 = v456 == 16;
  ret_assert(v463);
  struct StateG * v458 = slot_17(v452);
  return v458;
}

struct StateG * slot_133(struct StateG * v2420) {
  int v2421 = v2420->timer;
  int v2431 = v2421 + 1;
  v2420->timer = v2431;
  int * v2423 = v2420->pht;
  int v2424 = v2423[66];
  bool v2434 = !(v2424 == 0);
  struct StateG * v2429;
  if (v2434) {
    struct StateG * v2425 = slot_146(v2420);
    v2429 = v2425;
  } else {
    struct StateG * v2427 = slot_147(v2420);
    v2429 = v2427;
  }
  return v2429;
}

struct StateG * slot_56(struct StateG * v1120) {
  int v1121 = v1120->timer;
  int v1127 = v1121 + 1;
  v1120->timer = v1127;
  int * v1123 = v1120->regs;
  v1123[17] = 10;
  struct StateG * v1125 = slot_60(v1120);
  return v1125;
}

struct StateG * slot_34(struct StateG * v845) {
  int v846 = v845->timer;
  int v852 = v846 + 1;
  v845->timer = v852;
  int * v848 = v845->regs;
  v848[19] = 2;
  struct StateG * v850 = slot_32(v845);
  return v850;
}

struct StateG * slot_162(struct StateG * v3200) {
  int * v3201 = v3200->regs;
  int v3202 = v3201[16];
  int v3203 = v3201[17];
  bool v3223 = v3202 >= v3203;
  struct StateG * v3218;
  if (v3223) {
    int * v3204 = v3200->pht;
    v3204[66] = 1;
    struct StateG * v3206 = slot_199(v3200);
    v3218 = v3206;
  } else {
    int * v3208 = v3200->pht;
    v3208[66] = 0;
    int v3210 = v3200->timer;
    int v3232 = v3210 + 15;
    v3200->timer = v3232;
    int * v3212 = v3200->saved_regs;
    int v3213 = v3212[19];
    int * v3214 = v3200->regs;
    v3214[19] = v3213;
    struct StateG * v3216 = slot_177(v3200);
    v3218 = v3216;
  }
  return v3218;
}

struct StateG * slot_21(struct StateG * v531) {
  int v532 = v531->timer;
  int v538 = v532 + 1;
  v531->timer = v538;
  int * v534 = v531->regs;
  v534[17] = 10;
  struct StateG * v536 = slot_23(v531);
  return v536;
}

struct StateG * slot_118(struct StateG * v2190) {
  int v2191 = v2190->timer;
  int v2197 = v2191 + 1;
  v2190->timer = v2197;
  int * v2193 = v2190->regs;
  v2193[1] = 44;
  struct StateG * v2195 = slot_126(v2190);
  return v2195;
}

struct StateG * slot_121(struct StateG * v2229) {
  int v2230 = v2229->timer;
  int v2236 = v2230 + 1;
  v2229->timer = v2236;
  int * v2232 = v2229->regs;
  v2232[17] = 10;
  struct StateG * v2234 = slot_129(v2229);
  return v2234;
}

struct StateG * slot_144(struct StateG * v2640) {
  int * v2641 = v2640->saved_regs;
  int * v2642 = v2640->regs;
  int v2643 = v2642[19];
  v2641[19] = v2643;
  int v2645 = v2640->timer;
  int v2655 = v2645 + 1;
  v2640->timer = v2655;
  int * v2647 = v2640->regs;
  v2647[19] = 2;
  struct StateG * v2649 = slot_160(v2640);
  return v2649;
}

struct StateG * slot_94(struct StateG * v1875) {
  int v1876 = v1875->timer;
  int v1882 = v1876 + 1;
  v1875->timer = v1882;
  int * v1878 = v1875->regs;
  v1878[18] = 2;
  struct StateG * v1880 = slot_92(v1875);
  return v1880;
}

struct StateG * slot_63(struct StateG * v1232) {
  int v1233 = v1232->timer;
  int v1243 = v1233 + 1;
  v1232->timer = v1243;
  int * v1235 = v1232->pht;
  int v1236 = v1235[0];
  bool v1246 = !(v1236 == 0);
  struct StateG * v1241;
  if (v1246) {
    struct StateG * v1237 = slot_70(v1232);
    v1241 = v1237;
  } else {
    struct StateG * v1239 = slot_71(v1232);
    v1241 = v1239;
  }
  return v1241;
}

struct StateG * slot_146(struct StateG * v2680) {
  int * v2681 = v2680->saved_regs;
  int * v2682 = v2680->regs;
  int v2683 = v2682[19];
  v2681[19] = v2683;
  int v2685 = v2680->timer;
  int v2695 = v2685 + 1;
  v2680->timer = v2695;
  int * v2687 = v2680->regs;
  v2687[19] = 2;
  struct StateG * v2689 = slot_162(v2680);
  return v2689;
}

struct StateG * slot_24(struct StateG * v584) {
  int * v585 = v584->saved_regs;
  int * v586 = v584->regs;
  int v587 = v586[19];
  v585[19] = v587;
  int v589 = v584->timer;
  int v599 = v589 + 1;
  v584->timer = v599;
  int * v591 = v584->regs;
  v591[19] = 2;
  struct StateG * v593 = slot_28(v584);
  return v593;
}

struct StateG * slot_0(struct StateG * v2) {
  int v3 = v2->timer;
  int v9 = v3 + 1;
  v2->timer = v9;
  int * v5 = v2->regs;
  v5[12] = 80;
  struct StateG * v7 = slot_1(v2);
  return v7;
}

struct StateG * slot_125(struct StateG * v2281) {
  int v2282 = v2281->timer;
  int v2288 = v2282 + 1;
  v2281->timer = v2288;
  int * v2284 = v2281->regs;
  v2284[17] = 10;
  struct StateG * v2286 = slot_133(v2281);
  return v2286;
}

struct StateG * slot_148(struct StateG * v2720) {
  int * v2721 = v2720->saved_regs;
  int * v2722 = v2720->regs;
  int v2723 = v2722[19];
  v2721[19] = v2723;
  int v2725 = v2720->timer;
  int v2735 = v2725 + 1;
  v2720->timer = v2735;
  int * v2727 = v2720->regs;
  v2727[19] = 2;
  struct StateG * v2729 = slot_164(v2720);
  return v2729;
}

struct StateG * slot_126(struct StateG * v2294) {
  int v2295 = v2294->timer;
  int v2301 = v2295 + 1;
  v2294->timer = v2301;
  int * v2297 = v2294->regs;
  v2297[17] = 10;
  struct StateG * v2299 = slot_134(v2294);
  return v2299;
}

struct StateG * slot_79(struct StateG * v1689) {
  int * v1690 = v1689->regs;
  int v1691 = v1690[16];
  int v1692 = v1690[17];
  bool v1712 = v1691 < v1692;
  struct StateG * v1707;
  if (v1712) {
    int * v1693 = v1689->pht;
    v1693[0] = 1;
    int v1695 = v1689->timer;
    int v1716 = v1695 + 15;
    v1689->timer = v1716;
    int * v1697 = v1689->saved_regs;
    int v1698 = v1697[18];
    int * v1699 = v1689->regs;
    v1699[18] = v1698;
    struct StateG * v1701 = slot_94(v1689);
    v1707 = v1701;
  } else {
    int * v1703 = v1689->pht;
    v1703[0] = 0;
    struct StateG * v1705 = slot_95(v1689);
    v1707 = v1705;
  }
  return v1707;
}

struct StateG * slot_41(struct StateG * v922) {
  int v923 = v922->timer;
  int v930 = v923 + 1;
  v922->timer = v930;
  int * v925 = v922->regs;
  int v926 = v925[1];
  bool v933 = v926 == 24;
  ret_assert(v933);
  struct StateG * v928 = slot_45(v922);
  return v928;
}

struct StateG * slot_39(struct StateG * v900) {
  int v901 = v900->timer;
  int v905 = v901 + 1;
  v900->timer = v905;
  struct StateG * v903 = slot_43(v900);
  return v903;
}

struct StateG * slot_142(struct StateG * v2600) {
  int * v2601 = v2600->saved_regs;
  int * v2602 = v2600->regs;
  int v2603 = v2602[19];
  v2601[19] = v2603;
  int v2605 = v2600->timer;
  int v2615 = v2605 + 1;
  v2600->timer = v2615;
  int * v2607 = v2600->regs;
  v2607[19] = 2;
  struct StateG * v2609 = slot_158(v2600);
  return v2609;
}

struct StateG * slot_60(struct StateG * v1172) {
  int v1173 = v1172->timer;
  int v1183 = v1173 + 1;
  v1172->timer = v1183;
  int * v1175 = v1172->pht;
  int v1176 = v1175[3];
  bool v1186 = !(v1176 == 0);
  struct StateG * v1181;
  if (v1186) {
    struct StateG * v1177 = slot_64(v1172);
    v1181 = v1177;
  } else {
    struct StateG * v1179 = slot_65(v1172);
    v1181 = v1179;
  }
  return v1181;
}

struct StateG * slot_112(struct StateG * v2112) {
  int v2113 = v2112->timer;
  int v2119 = v2113 + 1;
  v2112->timer = v2119;
  int * v2115 = v2112->regs;
  v2115[1] = 44;
  struct StateG * v2117 = slot_120(v2112);
  return v2117;
}

struct StateG * slot_47(struct StateG * v1003) {
  int v1004 = v1003->timer;
  int v1010 = v1004 + 1;
  v1003->timer = v1010;
  int * v1006 = v1003->regs;
  v1006[16] = 20;
  struct StateG * v1008 = slot_51(v1003);
  return v1008;
}

struct StateG * slot_29(struct StateG * v704) {
  int * v705 = v704->regs;
  int v706 = v705[16];
  int v707 = v705[17];
  bool v727 = v706 >= v707;
  struct StateG * v722;
  if (v727) {
    int * v708 = v704->pht;
    v708[65] = 1;
    int v710 = v704->timer;
    int v731 = v710 + 15;
    v704->timer = v731;
    int * v712 = v704->saved_regs;
    int v713 = v712[19];
    int * v714 = v704->regs;
    v714[19] = v713;
    struct StateG * v716 = slot_34(v704);
    v722 = v716;
  } else {
    int * v718 = v704->pht;
    v718[65] = 0;
    struct StateG * v720 = slot_35(v704);
    v722 = v720;
  }
  return v722;
}

struct StateG * slot_16(struct StateG * v466) {
  int v467 = v466->timer;
  int v473 = v467 + 1;
  v466->timer = v473;
  int * v469 = v466->regs;
  v469[1] = 16;
  struct StateG * v471 = slot_18(v466);
  return v471;
}

struct StateG * slot_113(struct StateG * v2125) {
  int v2126 = v2125->timer;
  int v2132 = v2126 + 1;
  v2125->timer = v2132;
  int * v2128 = v2125->regs;
  v2128[1] = 44;
  struct StateG * v2130 = slot_121(v2125);
  return v2130;
}

struct StateG * slot_151(struct StateG * v2780) {
  int * v2781 = v2780->saved_regs;
  int * v2782 = v2780->regs;
  int v2783 = v2782[19];
  v2781[19] = v2783;
  int v2785 = v2780->timer;
  int v2795 = v2785 + 1;
  v2780->timer = v2795;
  int * v2787 = v2780->regs;
  v2787[19] = 1;
  struct StateG * v2789 = slot_167(v2780);
  return v2789;
}

struct StateG * slot_7(struct StateG * v298) {
  int * v299 = v298->saved_regs;
  int * v300 = v298->regs;
  int v301 = v300[18];
  v299[18] = v301;
  int v303 = v298->timer;
  int v313 = v303 + 1;
  v298->timer = v313;
  int * v305 = v298->regs;
  v305[18] = 1;
  struct StateG * v307 = slot_9(v298);
  return v307;
}

struct StateG * slot_124(struct StateG * v2268) {
  int v2269 = v2268->timer;
  int v2275 = v2269 + 1;
  v2268->timer = v2275;
  int * v2271 = v2268->regs;
  v2271[17] = 10;
  struct StateG * v2273 = slot_132(v2268);
  return v2273;
}

struct StateG * slot_103(struct StateG * v1994) {
  int v1995 = v1994->timer;
  int v2002 = v1995 + 1;
  v1994->timer = v2002;
  int * v1997 = v1994->regs;
  int v1998 = v1997[1];
  bool v2005 = v1998 == 36;
  ret_assert(v2005);
  struct StateG * v2000 = slot_111(v1994);
  return v2000;
}

struct StateG * slot_128(struct StateG * v2320) {
  int v2321 = v2320->timer;
  int v2331 = v2321 + 1;
  v2320->timer = v2331;
  int * v2323 = v2320->pht;
  int v2324 = v2323[71];
  bool v2334 = !(v2324 == 0);
  struct StateG * v2329;
  if (v2334) {
    struct StateG * v2325 = slot_136(v2320);
    v2329 = v2325;
  } else {
    struct StateG * v2327 = slot_137(v2320);
    v2329 = v2327;
  }
  return v2329;
}

struct StateG * slot_19(struct StateG * v505) {
  int v506 = v505->timer;
  int v512 = v506 + 1;
  v505->timer = v512;
  int * v508 = v505->regs;
  v508[1] = 24;
  struct StateG * v510 = slot_21(v505);
  return v510;
}

struct StateG * slot_87(struct StateG * v1804) {
  int v1805 = v1804->timer;
  int v1809 = v1805 + 1;
  v1804->timer = v1809;
  struct StateG * v1807 = slot_99(v1804);
  return v1807;
}

struct StateG * slot_67(struct StateG * v1312) {
  int * v1313 = v1312->saved_regs;
  int * v1314 = v1312->regs;
  int v1315 = v1314[18];
  v1313[18] = v1315;
  int v1317 = v1312->timer;
  int v1327 = v1317 + 1;
  v1312->timer = v1327;
  int * v1319 = v1312->regs;
  v1319[18] = 1;
  struct StateG * v1321 = slot_75(v1312);
  return v1321;
}

struct StateG * slot_81(struct StateG * v1736) {
  int v1737 = v1736->timer;
  int v1743 = v1737 + 1;
  v1736->timer = v1743;
  int * v1739 = v1736->regs;
  v1739[18] = 1;
  struct StateG * v1741 = slot_83(v1736);
  return v1741;
}

struct StateG * slot_95(struct StateG * v1888) {
  int v1889 = v1888->timer;
  int v1893 = v1889 + 1;
  v1888->timer = v1893;
  struct StateG * v1891 = slot_103(v1888);
  return v1891;
}

struct StateG * slot_115(struct StateG * v2151) {
  int v2152 = v2151->timer;
  int v2158 = v2152 + 1;
  v2151->timer = v2158;
  int * v2154 = v2151->regs;
  v2154[1] = 44;
  struct StateG * v2156 = slot_123(v2151);
  return v2156;
}

struct StateG * slot_78(struct StateG * v1650) {
  int * v1651 = v1650->regs;
  int v1652 = v1651[16];
  int v1653 = v1651[17];
  bool v1673 = v1652 < v1653;
  struct StateG * v1668;
  if (v1673) {
    int * v1654 = v1650->pht;
    v1654[0] = 1;
    struct StateG * v1656 = slot_92(v1650);
    v1668 = v1656;
  } else {
    int * v1658 = v1650->pht;
    v1658[0] = 0;
    int v1660 = v1650->timer;
    int v1681 = v1660 + 15;
    v1650->timer = v1681;
    int * v1662 = v1650->saved_regs;
    int v1663 = v1662[18];
    int * v1664 = v1650->regs;
    v1664[18] = v1663;
    struct StateG * v1666 = slot_93(v1650);
    v1668 = v1666;
  }
  return v1668;
}

struct StateG * slot_32(struct StateG * v824) {
  int v825 = v824->timer;
  int v829 = v825 + 1;
  v824->timer = v829;
  struct StateG * v827 = slot_40(v824);
  return v827;
}

struct StateG * slot_33(struct StateG * v832) {
  int v833 = v832->timer;
  int v839 = v833 + 1;
  v832->timer = v839;
  int * v835 = v832->regs;
  v835[19] = 1;
  struct StateG * v837 = slot_35(v832);
  return v837;
}

struct StateG * slot_35(struct StateG * v858) {
  int v859 = v858->timer;
  int v863 = v859 + 1;
  v858->timer = v863;
  struct StateG * v861 = slot_41(v858);
  return v861;
}

struct StateG * slot_166(struct StateG * v3360) {
  int * v3361 = v3360->regs;
  int v3362 = v3361[16];
  int v3363 = v3361[17];
  bool v3383 = v3362 >= v3363;
  struct StateG * v3378;
  if (v3383) {
    int * v3364 = v3360->pht;
    v3364[64] = 1;
    struct StateG * v3366 = slot_199(v3360);
    v3378 = v3366;
  } else {
    int * v3368 = v3360->pht;
    v3368[64] = 0;
    int v3370 = v3360->timer;
    int v3392 = v3370 + 15;
    v3360->timer = v3392;
    int * v3372 = v3360->saved_regs;
    int v3373 = v3372[19];
    int * v3374 = v3360->regs;
    v3374[19] = v3373;
    struct StateG * v3376 = slot_177(v3360);
    v3378 = v3376;
  }
  return v3378;
}

struct StateG * slot_51(struct StateG * v1055) {
  int v1056 = v1055->timer;
  int v1062 = v1056 + 1;
  v1055->timer = v1062;
  int * v1058 = v1055->regs;
  v1058[1] = 28;
  struct StateG * v1060 = slot_55(v1055);
  return v1060;
}

struct StateG * slot_52(struct StateG * v1068) {
  int v1069 = v1068->timer;
  int v1075 = v1069 + 1;
  v1068->timer = v1075;
  int * v1071 = v1068->regs;
  v1071[1] = 36;
  struct StateG * v1073 = slot_56(v1068);
  return v1073;
}

struct StateG * slot_83(struct StateG * v1762) {
  int v1763 = v1762->timer;
  int v1767 = v1763 + 1;
  v1762->timer = v1767;
  struct StateG * v1765 = slot_97(v1762);
  return v1765;
}

struct StateG * slot_25(struct StateG * v604) {
  int * v605 = v604->saved_regs;
  int * v606 = v604->regs;
  int v607 = v606[19];
  v605[19] = v607;
  int v609 = v604->timer;
  int v619 = v609 + 1;
  v604->timer = v619;
  int * v611 = v604->regs;
  v611[19] = 1;
  struct StateG * v613 = slot_29(v604);
  return v613;
}

struct StateG * slot_3(struct StateG * v232) {
  int v233 = v232->timer;
  int v239 = v233 + 1;
  v232->timer = v239;
  int * v235 = v232->regs;
  v235[1] = 16;
  struct StateG * v237 = slot_4(v232);
  return v237;
}

struct StateG * slot_123(struct StateG * v2255) {
  int v2256 = v2255->timer;
  int v2262 = v2256 + 1;
  v2255->timer = v2262;
  int * v2258 = v2255->regs;
  v2258[17] = 10;
  struct StateG * v2260 = slot_131(v2255);
  return v2260;
}

struct StateG * slot_73(struct StateG * v1452) {
  int * v1453 = v1452->regs;
  int v1454 = v1453[16];
  int v1455 = v1453[17];
  bool v1475 = v1454 < v1455;
  struct StateG * v1470;
  if (v1475) {
    int * v1456 = v1452->pht;
    v1456[3] = 1;
    int v1458 = v1452->timer;
    int v1479 = v1458 + 15;
    v1452->timer = v1479;
    int * v1460 = v1452->saved_regs;
    int v1461 = v1460[18];
    int * v1462 = v1452->regs;
    v1462[18] = v1461;
    struct StateG * v1464 = slot_82(v1452);
    v1470 = v1464;
  } else {
    int * v1466 = v1452->pht;
    v1466[3] = 0;
    struct StateG * v1468 = slot_83(v1452);
    v1470 = v1468;
  }
  return v1470;
}

struct StateG * slot_198(struct StateG * v3755) {
  int v3756 = v3755->timer;
  int v3762 = v3756 + 1;
  v3755->timer = v3762;
  int * v3758 = v3755->regs;
  v3758[19] = 2;
  struct StateG * v3760 = slot_199(v3755);
  return v3760;
}

struct StateG * slot_1(struct StateG * v15) {
  int v16 = v15->timer;
  int v126 = v16 + 1;
  v15->timer = v126;
  int * v18 = v15->regs;
  int v19 = v18[12];
  int * v20 = v15->cache_tags;
  int v130 = (((int)((unsigned int)((int)((unsigned int)v19 >> 2)) >> 1)) & 1) * 2;
  int v21 = v20[v130];
  int v131 = ((((int)((unsigned int)((int)((unsigned int)v19 >> 2)) >> 1)) & 1) * 2) + 1;
  int v22 = v20[v131];
  int v132 = 4 + ((((int)((unsigned int)((int)((unsigned int)v19 >> 2)) >> 1)) & 3) * 2);
  int v23 = v20[v132];
  int v133 = (4 + ((((int)((unsigned int)((int)((unsigned int)v19 >> 2)) >> 1)) & 3) * 2)) + 1;
  int v24 = v20[v133];
  int v25 = v15->timer;
  int v134 = v25 + ((100 ^ (((~(((v23 ^ ((int)((unsigned int)((int)((unsigned int)v19 >> 2)) >> 1))) | (-(v23 ^ ((int)((unsigned int)((int)((unsigned int)v19 >> 2)) >> 1))))) >> 31)) | (~(((v24 ^ ((int)((unsigned int)((int)((unsigned int)v19 >> 2)) >> 1))) | (-(v24 ^ ((int)((unsigned int)((int)((unsigned int)v19 >> 2)) >> 1))))) >> 31))) & 104)) ^ (((~(((v21 ^ ((int)((unsigned int)((int)((unsigned int)v19 >> 2)) >> 1))) | (-(v21 ^ ((int)((unsigned int)((int)((unsigned int)v19 >> 2)) >> 1))))) >> 31)) | (~(((v22 ^ ((int)((unsigned int)((int)((unsigned int)v19 >> 2)) >> 1))) | (-(v22 ^ ((int)((unsigned int)((int)((unsigned int)v19 >> 2)) >> 1))))) >> 31))) & (1 ^ (100 ^ (((~(((v23 ^ ((int)((unsigned int)((int)((unsigned int)v19 >> 2)) >> 1))) | (-(v23 ^ ((int)((unsigned int)((int)((unsigned int)v19 >> 2)) >> 1))))) >> 31)) | (~(((v24 ^ ((int)((unsigned int)((int)((unsigned int)v19 >> 2)) >> 1))) | (-(v24 ^ ((int)((unsigned int)((int)((unsigned int)v19 >> 2)) >> 1))))) >> 31))) & 104)))));
  v15->timer = v134;
  int * v27 = v15->cache_vals;
  bool v135 = !(((~(((v21 ^ ((int)((unsigned int)((int)((unsigned int)v19 >> 2)) >> 1))) | (-(v21 ^ ((int)((unsigned int)((int)((unsigned int)v19 >> 2)) >> 1))))) >> 31)) | (~(((v22 ^ ((int)((unsigned int)((int)((unsigned int)v19 >> 2)) >> 1))) | (-(v22 ^ ((int)((unsigned int)((int)((unsigned int)v19 >> 2)) >> 1))))) >> 31))) == 0);
  int v120;
  if (v135) {
    int * v28 = v15->cache_age;
    int v137 = ((((int)((unsigned int)((int)((unsigned int)v19 >> 2)) >> 1)) & 1) * 2) + ((~(((v22 ^ ((int)((unsigned int)((int)((unsigned int)v19 >> 2)) >> 1))) | (-(v22 ^ ((int)((unsigned int)((int)((unsigned int)v19 >> 2)) >> 1))))) >> 31)) & 1);
    int v29 = v28[v137];
    int v30 = v28[v130];
    int v138 = v30 + ((int)((unsigned int)(v30 - v29) >> 31));
    v28[v130] = v138;
    int * v32 = v15->cache_age;
    int v33 = v32[v131];
    int v140 = v33 + ((int)((unsigned int)(v33 - v29) >> 31));
    v32[v131] = v140;
    int * v35 = v15->cache_age;
    v35[v137] = 0;
    v120 = v137;
  } else {
    int * v38 = v15->cache_age;
    int v144 = (((int)((unsigned int)((int)((unsigned int)v19 >> 2)) >> 1)) & 1) * 2;
    int v39 = v38[v144];
    int * v40 = v15->cache_tags;
    int v41 = v40[v144];
    int v42 = v38[v131];
    int v43 = v40[v131];
    bool v146 = !(((~(((v23 ^ ((int)((unsigned int)((int)((unsigned int)v19 >> 2)) >> 1))) | (-(v23 ^ ((int)((unsigned int)((int)((unsigned int)v19 >> 2)) >> 1))))) >> 31)) | (~(((v24 ^ ((int)((unsigned int)((int)((unsigned int)v19 >> 2)) >> 1))) | (-(v24 ^ ((int)((unsigned int)((int)((unsigned int)v19 >> 2)) >> 1))))) >> 31))) == 0);
    int v97;
    if (v146) {
      int * v44 = v15->cache_age;
      int v148 = (4 + ((((int)((unsigned int)((int)((unsigned int)v19 >> 2)) >> 1)) & 3) * 2)) + ((~(((v24 ^ ((int)((unsigned int)((int)((unsigned int)v19 >> 2)) >> 1))) | (-(v24 ^ ((int)((unsigned int)((int)((unsigned int)v19 >> 2)) >> 1))))) >> 31)) & 1);
      int v45 = v44[v148];
      int v46 = v44[v132];
      int v149 = v46 + ((int)((unsigned int)(v46 - v45) >> 31));
      v44[v132] = v149;
      int * v48 = v15->cache_age;
      int v49 = v48[v133];
      int v151 = v49 + ((int)((unsigned int)(v49 - v45) >> 31));
      v48[v133] = v151;
      int * v51 = v15->cache_age;
      v51[v148] = 0;
      v97 = v148;
    } else {
      int * v54 = v15->cache_age;
      int v155 = 4 + ((((int)((unsigned int)((int)((unsigned int)v19 >> 2)) >> 1)) & 3) * 2);
      int v55 = v54[v155];
      int * v56 = v15->cache_tags;
      int v57 = v56[v155];
      int v58 = v54[v133];
      int v59 = v56[v133];
      int * v60 = v15->cache_dirty;
      int v158 = (4 + ((((int)((unsigned int)((int)((unsigned int)v19 >> 2)) >> 1)) & 3) * 2)) + ((((v55 + ((~(((v57 ^ -1) | (-(v57 ^ -1))) >> 31)) & 2)) - (v58 + ((~(((v59 ^ -1) | (-(v59 ^ -1))) >> 31)) & 2))) >> 31) & 1);
      int v61 = v60[v158];
      bool v159 = !(v61 == 0);
      if (v159) {
        int * v62 = v15->cache_tags;
        int v63 = v62[v158];
        int * v64 = v15->cache_vals;
        int v162 = ((4 + ((((int)((unsigned int)((int)((unsigned int)v19 >> 2)) >> 1)) & 3) * 2)) + ((((v55 + ((~(((v57 ^ -1) | (-(v57 ^ -1))) >> 31)) & 2)) - (v58 + ((~(((v59 ^ -1) | (-(v59 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
        int v65 = v64[v162];
        int v163 = (((4 + ((((int)((unsigned int)((int)((unsigned int)v19 >> 2)) >> 1)) & 3) * 2)) + ((((v55 + ((~(((v57 ^ -1) | (-(v57 ^ -1))) >> 31)) & 2)) - (v58 + ((~(((v59 ^ -1) | (-(v59 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
        int v66 = v64[v163];
        int * v67 = v15->mem;
        int v165 = v63 * 2;
        v67[v165] = v65;
        int * v69 = v15->mem;
        int v168 = (v63 * 2) + 1;
        v69[v168] = v66;
        ;
      } else {
        ;
      }
      int * v74 = v15->mem;
      int v173 = ((int)((unsigned int)((int)((unsigned int)v19 >> 2)) >> 1)) * 2;
      int v75 = v74[v173];
      int v174 = (((int)((unsigned int)((int)((unsigned int)v19 >> 2)) >> 1)) * 2) + 1;
      int v76 = v74[v174];
      int * v77 = v15->cache_vals;
      int v176 = ((4 + ((((int)((unsigned int)((int)((unsigned int)v19 >> 2)) >> 1)) & 3) * 2)) + ((((v55 + ((~(((v57 ^ -1) | (-(v57 ^ -1))) >> 31)) & 2)) - (v58 + ((~(((v59 ^ -1) | (-(v59 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
      v77[v176] = v75;
      int * v79 = v15->cache_vals;
      int v179 = (((4 + ((((int)((unsigned int)((int)((unsigned int)v19 >> 2)) >> 1)) & 3) * 2)) + ((((v55 + ((~(((v57 ^ -1) | (-(v57 ^ -1))) >> 31)) & 2)) - (v58 + ((~(((v59 ^ -1) | (-(v59 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
      v79[v179] = v76;
      int * v81 = v15->cache_tags;
      int v182 = (int)((unsigned int)((int)((unsigned int)v19 >> 2)) >> 1);
      v81[v158] = v182;
      int * v83 = v15->cache_dirty;
      v83[v158] = 0;
      int * v85 = v15->cache_age;
      v85[v158] = 1;
      int * v87 = v15->cache_age;
      int v88 = v87[v158];
      int v89 = v87[v132];
      int v188 = v89 + ((int)((unsigned int)(v89 - v88) >> 31));
      v87[v132] = v188;
      int * v91 = v15->cache_age;
      int v92 = v91[v133];
      int v190 = v92 + ((int)((unsigned int)(v92 - v88) >> 31));
      v91[v133] = v190;
      int * v94 = v15->cache_age;
      v94[v158] = 0;
      v97 = v158;
    }
    int * v98 = v15->cache_vals;
    int v193 = v97 * 2;
    int v99 = v98[v193];
    int v194 = (v97 * 2) + 1;
    int v100 = v98[v194];
    int v195 = (((((int)((unsigned int)((int)((unsigned int)v19 >> 2)) >> 1)) & 1) * 2) + ((((v39 + ((~(((v41 ^ -1) | (-(v41 ^ -1))) >> 31)) & 2)) - (v42 + ((~(((v43 ^ -1) | (-(v43 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
    v98[v195] = v99;
    int * v102 = v15->cache_vals;
    int v198 = ((((((int)((unsigned int)((int)((unsigned int)v19 >> 2)) >> 1)) & 1) * 2) + ((((v39 + ((~(((v41 ^ -1) | (-(v41 ^ -1))) >> 31)) & 2)) - (v42 + ((~(((v43 ^ -1) | (-(v43 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
    v102[v198] = v100;
    int * v104 = v15->cache_tags;
    int v201 = ((((int)((unsigned int)((int)((unsigned int)v19 >> 2)) >> 1)) & 1) * 2) + ((((v39 + ((~(((v41 ^ -1) | (-(v41 ^ -1))) >> 31)) & 2)) - (v42 + ((~(((v43 ^ -1) | (-(v43 ^ -1))) >> 31)) & 2))) >> 31) & 1);
    int v202 = (int)((unsigned int)((int)((unsigned int)v19 >> 2)) >> 1);
    v104[v201] = v202;
    int * v106 = v15->cache_dirty;
    v106[v201] = 0;
    int * v108 = v15->cache_age;
    v108[v201] = 1;
    int * v110 = v15->cache_age;
    int v111 = v110[v201];
    int v112 = v110[v130];
    int v208 = v112 + ((int)((unsigned int)(v112 - v111) >> 31));
    v110[v130] = v208;
    int * v114 = v15->cache_age;
    int v115 = v114[v131];
    int v210 = v115 + ((int)((unsigned int)(v115 - v111) >> 31));
    v114[v131] = v210;
    int * v117 = v15->cache_age;
    v117[v201] = 0;
    v120 = v201;
  }
  int v213 = (v120 * 2) + (((int)((unsigned int)v19 >> 2)) & 1);
  int v121 = v27[v213];
  int * v122 = v15->regs;
  v122[16] = v121;
  struct StateG * v124 = slot_2(v15);
  return v124;
}

struct StateG * slot_97(struct StateG * v1910) {
  int v1911 = v1910->timer;
  int v1918 = v1911 + 1;
  v1910->timer = v1918;
  int * v1913 = v1910->regs;
  int v1914 = v1913[1];
  bool v1921 = v1914 == 36;
  ret_assert(v1921);
  struct StateG * v1916 = slot_105(v1910);
  return v1916;
}

struct StateG * slot_38(struct StateG * v887) {
  int v888 = v887->timer;
  int v894 = v888 + 1;
  v887->timer = v894;
  int * v890 = v887->regs;
  v890[19] = 2;
  struct StateG * v892 = slot_36(v887);
  return v892;
}

struct StateG * slot_106(struct StateG * v2034) {
  int v2035 = v2034->timer;
  int v2041 = v2035 + 1;
  v2034->timer = v2041;
  int * v2037 = v2034->regs;
  v2037[1] = 36;
  struct StateG * v2039 = slot_114(v2034);
  return v2039;
}

struct StateG * slot_98(struct StateG * v1924) {
  int v1925 = v1924->timer;
  int v1932 = v1925 + 1;
  v1924->timer = v1932;
  int * v1927 = v1924->regs;
  int v1928 = v1927[1];
  bool v1935 = v1928 == 36;
  ret_assert(v1935);
  struct StateG * v1930 = slot_106(v1924);
  return v1930;
}

struct StateG * slot_159(struct StateG * v3080) {
  int * v3081 = v3080->regs;
  int v3082 = v3081[16];
  int v3083 = v3081[17];
  bool v3103 = v3082 >= v3083;
  struct StateG * v3098;
  if (v3103) {
    int * v3084 = v3080->pht;
    v3084[68] = 1;
    int v3086 = v3080->timer;
    int v3107 = v3086 + 15;
    v3080->timer = v3107;
    int * v3088 = v3080->saved_regs;
    int v3089 = v3088[19];
    int * v3090 = v3080->regs;
    v3090[19] = v3089;
    struct StateG * v3092 = slot_198(v3080);
    v3098 = v3092;
  } else {
    int * v3094 = v3080->pht;
    v3094[68] = 0;
    struct StateG * v3096 = slot_199(v3080);
    v3098 = v3096;
  }
  return v3098;
}

struct StateG * slot_46(struct StateG * v990) {
  int v991 = v990->timer;
  int v997 = v991 + 1;
  v990->timer = v997;
  int * v993 = v990->regs;
  v993[16] = 20;
  struct StateG * v995 = slot_50(v990);
  return v995;
}

struct StateG * slot_132(struct StateG * v2400) {
  int v2401 = v2400->timer;
  int v2411 = v2401 + 1;
  v2400->timer = v2411;
  int * v2403 = v2400->pht;
  int v2404 = v2403[67];
  bool v2414 = !(v2404 == 0);
  struct StateG * v2409;
  if (v2414) {
    struct StateG * v2405 = slot_144(v2400);
    v2409 = v2405;
  } else {
    struct StateG * v2407 = slot_145(v2400);
    v2409 = v2407;
  }
  return v2409;
}

struct StateG * slot_130(struct StateG * v2360) {
  int v2361 = v2360->timer;
  int v2371 = v2361 + 1;
  v2360->timer = v2371;
  int * v2363 = v2360->pht;
  int v2364 = v2363[69];
  bool v2374 = !(v2364 == 0);
  struct StateG * v2369;
  if (v2374) {
    struct StateG * v2365 = slot_140(v2360);
    v2369 = v2365;
  } else {
    struct StateG * v2367 = slot_141(v2360);
    v2369 = v2367;
  }
  return v2369;
}

struct StateG * slot_20(struct StateG * v518) {
  int v519 = v518->timer;
  int v525 = v519 + 1;
  v518->timer = v525;
  int * v521 = v518->regs;
  v521[17] = 10;
  struct StateG * v523 = slot_22(v518);
  return v523;
}

struct StateG * slot_141(struct StateG * v2580) {
  int * v2581 = v2580->saved_regs;
  int * v2582 = v2580->regs;
  int v2583 = v2582[19];
  v2581[19] = v2583;
  int v2585 = v2580->timer;
  int v2595 = v2585 + 1;
  v2580->timer = v2595;
  int * v2587 = v2580->regs;
  v2587[19] = 1;
  struct StateG * v2589 = slot_157(v2580);
  return v2589;
}

struct StateG * slot_61(struct StateG * v1192) {
  int v1193 = v1192->timer;
  int v1203 = v1193 + 1;
  v1192->timer = v1203;
  int * v1195 = v1192->pht;
  int v1196 = v1195[2];
  bool v1206 = !(v1196 == 0);
  struct StateG * v1201;
  if (v1206) {
    struct StateG * v1197 = slot_66(v1192);
    v1201 = v1197;
  } else {
    struct StateG * v1199 = slot_67(v1192);
    v1201 = v1199;
  }
  return v1201;
}

struct StateG * slot_30(struct StateG * v744) {
  int * v745 = v744->regs;
  int v746 = v745[16];
  int v747 = v745[17];
  bool v767 = v746 >= v747;
  struct StateG * v762;
  if (v767) {
    int * v748 = v744->pht;
    v748[64] = 1;
    struct StateG * v750 = slot_36(v744);
    v762 = v750;
  } else {
    int * v752 = v744->pht;
    v752[64] = 0;
    int v754 = v744->timer;
    int v776 = v754 + 15;
    v744->timer = v776;
    int * v756 = v744->saved_regs;
    int v757 = v756[19];
    int * v758 = v744->regs;
    v758[19] = v757;
    struct StateG * v760 = slot_37(v744);
    v762 = v760;
  }
  return v762;
}

struct StateG * slot_4(struct StateG * v245) {
  int v246 = v245->timer;
  int v252 = v246 + 1;
  v245->timer = v252;
  int * v248 = v245->regs;
  v248[17] = 10;
  struct StateG * v250 = slot_5(v245);
  return v250;
}

struct StateG * slot_18(struct StateG * v492) {
  int v493 = v492->timer;
  int v499 = v493 + 1;
  v492->timer = v499;
  int * v495 = v492->regs;
  v495[1] = 24;
  struct StateG * v497 = slot_20(v492);
  return v497;
}

struct StateG * slot_9(struct StateG * v357) {
  int * v358 = v357->regs;
  int v359 = v358[16];
  int v360 = v358[17];
  bool v380 = v359 < v360;
  struct StateG * v375;
  if (v380) {
    int * v361 = v357->pht;
    v361[0] = 1;
    int v363 = v357->timer;
    int v384 = v363 + 15;
    v357->timer = v384;
    int * v365 = v357->saved_regs;
    int v366 = v365[18];
    int * v367 = v357->regs;
    v367[18] = v366;
    struct StateG * v369 = slot_12(v357);
    v375 = v369;
  } else {
    int * v371 = v357->pht;
    v371[0] = 0;
    struct StateG * v373 = slot_13(v357);
    v375 = v373;
  }
  return v375;
}

struct StateG * slot_43(struct StateG * v950) {
  int v951 = v950->timer;
  int v958 = v951 + 1;
  v950->timer = v958;
  int * v953 = v950->regs;
  int v954 = v953[1];
  bool v961 = v954 == 24;
  ret_assert(v961);
  struct StateG * v956 = slot_47(v950);
  return v956;
}

struct StateG * slot_70(struct StateG * v1372) {
  int * v1373 = v1372->saved_regs;
  int * v1374 = v1372->regs;
  int v1375 = v1374[18];
  v1373[18] = v1375;
  int v1377 = v1372->timer;
  int v1387 = v1377 + 1;
  v1372->timer = v1387;
  int * v1379 = v1372->regs;
  v1379[18] = 2;
  struct StateG * v1381 = slot_78(v1372);
  return v1381;
}

struct StateG * slot_76(struct StateG * v1572) {
  int * v1573 = v1572->regs;
  int v1574 = v1573[16];
  int v1575 = v1573[17];
  bool v1595 = v1574 < v1575;
  struct StateG * v1590;
  if (v1595) {
    int * v1576 = v1572->pht;
    v1576[1] = 1;
    struct StateG * v1578 = slot_88(v1572);
    v1590 = v1578;
  } else {
    int * v1580 = v1572->pht;
    v1580[1] = 0;
    int v1582 = v1572->timer;
    int v1603 = v1582 + 15;
    v1572->timer = v1603;
    int * v1584 = v1572->saved_regs;
    int v1585 = v1584[18];
    int * v1586 = v1572->regs;
    v1586[18] = v1585;
    struct StateG * v1588 = slot_89(v1572);
    v1590 = v1588;
  }
  return v1590;
}

struct StateG * slot_6(struct StateG * v278) {
  int * v279 = v278->saved_regs;
  int * v280 = v278->regs;
  int v281 = v280[18];
  v279[18] = v281;
  int v283 = v278->timer;
  int v293 = v283 + 1;
  v278->timer = v293;
  int * v285 = v278->regs;
  v285[18] = 2;
  struct StateG * v287 = slot_8(v278);
  return v287;
}

struct StateG * slot_55(struct StateG * v1107) {
  int v1108 = v1107->timer;
  int v1114 = v1108 + 1;
  v1107->timer = v1114;
  int * v1110 = v1107->regs;
  v1110[1] = 36;
  struct StateG * v1112 = slot_59(v1107);
  return v1112;
}

struct StateG * slot_82(struct StateG * v1749) {
  int v1750 = v1749->timer;
  int v1756 = v1750 + 1;
  v1749->timer = v1756;
  int * v1752 = v1749->regs;
  v1752[18] = 2;
  struct StateG * v1754 = slot_80(v1749);
  return v1754;
}

struct StateG * slot_161(struct StateG * v3160) {
  int * v3161 = v3160->regs;
  int v3162 = v3161[16];
  int v3163 = v3161[17];
  bool v3183 = v3162 >= v3163;
  struct StateG * v3178;
  if (v3183) {
    int * v3164 = v3160->pht;
    v3164[67] = 1;
    int v3166 = v3160->timer;
    int v3187 = v3166 + 15;
    v3160->timer = v3187;
    int * v3168 = v3160->saved_regs;
    int v3169 = v3168[19];
    int * v3170 = v3160->regs;
    v3170[19] = v3169;
    struct StateG * v3172 = slot_198(v3160);
    v3178 = v3172;
  } else {
    int * v3174 = v3160->pht;
    v3174[67] = 0;
    struct StateG * v3176 = slot_199(v3160);
    v3178 = v3176;
  }
  return v3178;
}

struct StateG * slot_91(struct StateG * v1846) {
  int v1847 = v1846->timer;
  int v1851 = v1847 + 1;
  v1846->timer = v1851;
  struct StateG * v1849 = slot_101(v1846);
  return v1849;
}

struct StateG * slot_58(struct StateG * v1146) {
  int v1147 = v1146->timer;
  int v1153 = v1147 + 1;
  v1146->timer = v1153;
  int * v1149 = v1146->regs;
  v1149[17] = 10;
  struct StateG * v1151 = slot_62(v1146);
  return v1151;
}

struct StateG * slot_89(struct StateG * v1820) {
  int v1821 = v1820->timer;
  int v1827 = v1821 + 1;
  v1820->timer = v1827;
  int * v1823 = v1820->regs;
  v1823[18] = 1;
  struct StateG * v1825 = slot_91(v1820);
  return v1825;
}

struct StateG * slot_66(struct StateG * v1292) {
  int * v1293 = v1292->saved_regs;
  int * v1294 = v1292->regs;
  int v1295 = v1294[18];
  v1293[18] = v1295;
  int v1297 = v1292->timer;
  int v1307 = v1297 + 1;
  v1292->timer = v1307;
  int * v1299 = v1292->regs;
  v1299[18] = 2;
  struct StateG * v1301 = slot_74(v1292);
  return v1301;
}

struct StateG * slot_140(struct StateG * v2560) {
  int * v2561 = v2560->saved_regs;
  int * v2562 = v2560->regs;
  int v2563 = v2562[19];
  v2561[19] = v2563;
  int v2565 = v2560->timer;
  int v2575 = v2565 + 1;
  v2560->timer = v2575;
  int * v2567 = v2560->regs;
  v2567[19] = 2;
  struct StateG * v2569 = slot_156(v2560);
  return v2569;
}

struct StateG * slot_49(struct StateG * v1029) {
  int v1030 = v1029->timer;
  int v1036 = v1030 + 1;
  v1029->timer = v1036;
  int * v1032 = v1029->regs;
  v1032[1] = 28;
  struct StateG * v1034 = slot_53(v1029);
  return v1034;
}

struct StateG * slot_50(struct StateG * v1042) {
  int v1043 = v1042->timer;
  int v1049 = v1043 + 1;
  v1042->timer = v1049;
  int * v1045 = v1042->regs;
  v1045[1] = 28;
  struct StateG * v1047 = slot_54(v1042);
  return v1047;
}

struct StateG * slot_37(struct StateG * v874) {
  int v875 = v874->timer;
  int v881 = v875 + 1;
  v874->timer = v881;
  int * v877 = v874->regs;
  v877[19] = 1;
  struct StateG * v879 = slot_39(v874);
  return v879;
}

struct StateG * slot_114(struct StateG * v2138) {
  int v2139 = v2138->timer;
  int v2145 = v2139 + 1;
  v2138->timer = v2145;
  int * v2141 = v2138->regs;
  v2141[1] = 44;
  struct StateG * v2143 = slot_122(v2138);
  return v2143;
}

struct StateG * slot_135(struct StateG * v2460) {
  int v2461 = v2460->timer;
  int v2471 = v2461 + 1;
  v2460->timer = v2471;
  int * v2463 = v2460->pht;
  int v2464 = v2463[64];
  bool v2474 = !(v2464 == 0);
  struct StateG * v2469;
  if (v2474) {
    struct StateG * v2465 = slot_150(v2460);
    v2469 = v2465;
  } else {
    struct StateG * v2467 = slot_151(v2460);
    v2469 = v2467;
  }
  return v2469;
}

struct StateG * slot_59(struct StateG * v1159) {
  int v1160 = v1159->timer;
  int v1166 = v1160 + 1;
  v1159->timer = v1166;
  int * v1162 = v1159->regs;
  v1162[17] = 10;
  struct StateG * v1164 = slot_63(v1159);
  return v1164;
}

struct StateG * slot_40(struct StateG * v908) {
  int v909 = v908->timer;
  int v916 = v909 + 1;
  v908->timer = v916;
  int * v911 = v908->regs;
  int v912 = v911[1];
  bool v919 = v912 == 24;
  ret_assert(v919);
  struct StateG * v914 = slot_44(v908);
  return v914;
}

struct StateG * slot_48(struct StateG * v1016) {
  int v1017 = v1016->timer;
  int v1023 = v1017 + 1;
  v1016->timer = v1023;
  int * v1019 = v1016->regs;
  v1019[1] = 28;
  struct StateG * v1021 = slot_52(v1016);
  return v1021;
}

struct StateG * slot_77(struct StateG * v1611) {
  int * v1612 = v1611->regs;
  int v1613 = v1612[16];
  int v1614 = v1612[17];
  bool v1634 = v1613 < v1614;
  struct StateG * v1629;
  if (v1634) {
    int * v1615 = v1611->pht;
    v1615[1] = 1;
    int v1617 = v1611->timer;
    int v1637 = v1617 + 15;
    v1611->timer = v1637;
    int * v1619 = v1611->saved_regs;
    int v1620 = v1619[18];
    int * v1621 = v1611->regs;
    v1621[18] = v1620;
    struct StateG * v1623 = slot_90(v1611);
    v1629 = v1623;
  } else {
    int * v1625 = v1611->pht;
    v1625[1] = 0;
    struct StateG * v1627 = slot_91(v1611);
    v1629 = v1627;
  }
  return v1629;
}

struct StateG * slot_85(struct StateG * v1778) {
  int v1779 = v1778->timer;
  int v1785 = v1779 + 1;
  v1778->timer = v1785;
  int * v1781 = v1778->regs;
  v1781[18] = 1;
  struct StateG * v1783 = slot_87(v1778);
  return v1783;
}

struct StateG * slot_75(struct StateG * v1532) {
  int * v1533 = v1532->regs;
  int v1534 = v1533[16];
  int v1535 = v1533[17];
  bool v1555 = v1534 < v1535;
  struct StateG * v1550;
  if (v1555) {
    int * v1536 = v1532->pht;
    v1536[2] = 1;
    int v1538 = v1532->timer;
    int v1559 = v1538 + 15;
    v1532->timer = v1559;
    int * v1540 = v1532->saved_regs;
    int v1541 = v1540[18];
    int * v1542 = v1532->regs;
    v1542[18] = v1541;
    struct StateG * v1544 = slot_86(v1532);
    v1550 = v1544;
  } else {
    int * v1546 = v1532->pht;
    v1546[2] = 0;
    struct StateG * v1548 = slot_87(v1532);
    v1550 = v1548;
  }
  return v1550;
}

struct StateG * slot_72(struct StateG * v1412) {
  int * v1413 = v1412->regs;
  int v1414 = v1413[16];
  int v1415 = v1413[17];
  bool v1435 = v1414 < v1415;
  struct StateG * v1430;
  if (v1435) {
    int * v1416 = v1412->pht;
    v1416[3] = 1;
    struct StateG * v1418 = slot_80(v1412);
    v1430 = v1418;
  } else {
    int * v1420 = v1412->pht;
    v1420[3] = 0;
    int v1422 = v1412->timer;
    int v1444 = v1422 + 15;
    v1412->timer = v1444;
    int * v1424 = v1412->saved_regs;
    int v1425 = v1424[18];
    int * v1426 = v1412->regs;
    v1426[18] = v1425;
    struct StateG * v1428 = slot_81(v1412);
    v1430 = v1428;
  }
  return v1430;
}

struct StateG * slot_119(struct StateG * v2203) {
  int v2204 = v2203->timer;
  int v2210 = v2204 + 1;
  v2203->timer = v2210;
  int * v2206 = v2203->regs;
  v2206[1] = 44;
  struct StateG * v2208 = slot_127(v2203);
  return v2208;
}

struct StateG * slot_71(struct StateG * v1392) {
  int * v1393 = v1392->saved_regs;
  int * v1394 = v1392->regs;
  int v1395 = v1394[18];
  v1393[18] = v1395;
  int v1397 = v1392->timer;
  int v1407 = v1397 + 1;
  v1392->timer = v1407;
  int * v1399 = v1392->regs;
  v1399[18] = 1;
  struct StateG * v1401 = slot_79(v1392);
  return v1401;
}

struct StateG * slot_101(struct StateG * v1966) {
  int v1967 = v1966->timer;
  int v1974 = v1967 + 1;
  v1966->timer = v1974;
  int * v1969 = v1966->regs;
  int v1970 = v1969[1];
  bool v1977 = v1970 == 36;
  ret_assert(v1977);
  struct StateG * v1972 = slot_109(v1966);
  return v1972;
}

struct StateG * slot_108(struct StateG * v2060) {
  int v2061 = v2060->timer;
  int v2067 = v2061 + 1;
  v2060->timer = v2067;
  int * v2063 = v2060->regs;
  v2063[1] = 36;
  struct StateG * v2065 = slot_116(v2060);
  return v2065;
}

struct StateG * slot_116(struct StateG * v2164) {
  int v2165 = v2164->timer;
  int v2171 = v2165 + 1;
  v2164->timer = v2171;
  int * v2167 = v2164->regs;
  v2167[1] = 44;
  struct StateG * v2169 = slot_124(v2164);
  return v2169;
}

struct StateG * slot_93(struct StateG * v1862) {
  int v1863 = v1862->timer;
  int v1869 = v1863 + 1;
  v1862->timer = v1869;
  int * v1865 = v1862->regs;
  v1865[18] = 1;
  struct StateG * v1867 = slot_95(v1862);
  return v1867;
}

struct StateG * slot_88(struct StateG * v1812) {
  int v1813 = v1812->timer;
  int v1817 = v1813 + 1;
  v1812->timer = v1817;
  struct StateG * v1815 = slot_100(v1812);
  return v1815;
}

struct StateG * slot_96(struct StateG * v1896) {
  int v1897 = v1896->timer;
  int v1904 = v1897 + 1;
  v1896->timer = v1904;
  int * v1899 = v1896->regs;
  int v1900 = v1899[1];
  bool v1907 = v1900 == 36;
  ret_assert(v1907);
  struct StateG * v1902 = slot_104(v1896);
  return v1902;
}

struct StateG * slot_45(struct StateG * v977) {
  int v978 = v977->timer;
  int v984 = v978 + 1;
  v977->timer = v984;
  int * v980 = v977->regs;
  v980[16] = 20;
  struct StateG * v982 = slot_49(v977);
  return v982;
}

struct StateG * slot_134(struct StateG * v2440) {
  int v2441 = v2440->timer;
  int v2451 = v2441 + 1;
  v2440->timer = v2451;
  int * v2443 = v2440->pht;
  int v2444 = v2443[65];
  bool v2454 = !(v2444 == 0);
  struct StateG * v2449;
  if (v2454) {
    struct StateG * v2445 = slot_148(v2440);
    v2449 = v2445;
  } else {
    struct StateG * v2447 = slot_149(v2440);
    v2449 = v2447;
  }
  return v2449;
}

struct StateG * slot_69(struct StateG * v1352) {
  int * v1353 = v1352->saved_regs;
  int * v1354 = v1352->regs;
  int v1355 = v1354[18];
  v1353[18] = v1355;
  int v1357 = v1352->timer;
  int v1367 = v1357 + 1;
  v1352->timer = v1367;
  int * v1359 = v1352->regs;
  v1359[18] = 1;
  struct StateG * v1361 = slot_77(v1352);
  return v1361;
}

struct StateG * slot_138(struct StateG * v2520) {
  int * v2521 = v2520->saved_regs;
  int * v2522 = v2520->regs;
  int v2523 = v2522[19];
  v2521[19] = v2523;
  int v2525 = v2520->timer;
  int v2535 = v2525 + 1;
  v2520->timer = v2535;
  int * v2527 = v2520->regs;
  v2527[19] = 2;
  struct StateG * v2529 = slot_154(v2520);
  return v2529;
}

struct StateG * slot_102(struct StateG * v1980) {
  int v1981 = v1980->timer;
  int v1988 = v1981 + 1;
  v1980->timer = v1988;
  int * v1983 = v1980->regs;
  int v1984 = v1983[1];
  bool v1991 = v1984 == 36;
  ret_assert(v1991);
  struct StateG * v1986 = slot_110(v1980);
  return v1986;
}

struct StateG * slot_145(struct StateG * v2660) {
  int * v2661 = v2660->saved_regs;
  int * v2662 = v2660->regs;
  int v2663 = v2662[19];
  v2661[19] = v2663;
  int v2665 = v2660->timer;
  int v2675 = v2665 + 1;
  v2660->timer = v2675;
  int * v2667 = v2660->regs;
  v2667[19] = 1;
  struct StateG * v2669 = slot_161(v2660);
  return v2669;
}

struct StateG * slot_110(struct StateG * v2086) {
  int v2087 = v2086->timer;
  int v2093 = v2087 + 1;
  v2086->timer = v2093;
  int * v2089 = v2086->regs;
  v2089[1] = 36;
  struct StateG * v2091 = slot_118(v2086);
  return v2091;
}

struct StateG * slot_131(struct StateG * v2380) {
  int v2381 = v2380->timer;
  int v2391 = v2381 + 1;
  v2380->timer = v2391;
  int * v2383 = v2380->pht;
  int v2384 = v2383[68];
  bool v2394 = !(v2384 == 0);
  struct StateG * v2389;
  if (v2394) {
    struct StateG * v2385 = slot_142(v2380);
    v2389 = v2385;
  } else {
    struct StateG * v2387 = slot_143(v2380);
    v2389 = v2387;
  }
  return v2389;
}

struct StateG * slot_8(struct StateG * v318) {
  int * v319 = v318->regs;
  int v320 = v319[16];
  int v321 = v319[17];
  bool v341 = v320 < v321;
  struct StateG * v336;
  if (v341) {
    int * v322 = v318->pht;
    v322[0] = 1;
    struct StateG * v324 = slot_10(v318);
    v336 = v324;
  } else {
    int * v326 = v318->pht;
    v326[0] = 0;
    int v328 = v318->timer;
    int v349 = v328 + 15;
    v318->timer = v349;
    int * v330 = v318->saved_regs;
    int v331 = v330[18];
    int * v332 = v318->regs;
    v332[18] = v331;
    struct StateG * v334 = slot_11(v318);
    v336 = v334;
  }
  return v336;
}

struct StateG * slot_157(struct StateG * v3000) {
  int * v3001 = v3000->regs;
  int v3002 = v3001[16];
  int v3003 = v3001[17];
  bool v3023 = v3002 >= v3003;
  struct StateG * v3018;
  if (v3023) {
    int * v3004 = v3000->pht;
    v3004[69] = 1;
    int v3006 = v3000->timer;
    int v3027 = v3006 + 15;
    v3000->timer = v3027;
    int * v3008 = v3000->saved_regs;
    int v3009 = v3008[19];
    int * v3010 = v3000->regs;
    v3010[19] = v3009;
    struct StateG * v3012 = slot_198(v3000);
    v3018 = v3012;
  } else {
    int * v3014 = v3000->pht;
    v3014[69] = 0;
    struct StateG * v3016 = slot_199(v3000);
    v3018 = v3016;
  }
  return v3018;
}

struct StateG * slot_149(struct StateG * v2740) {
  int * v2741 = v2740->saved_regs;
  int * v2742 = v2740->regs;
  int v2743 = v2742[19];
  v2741[19] = v2743;
  int v2745 = v2740->timer;
  int v2755 = v2745 + 1;
  v2740->timer = v2755;
  int * v2747 = v2740->regs;
  v2747[19] = 1;
  struct StateG * v2749 = slot_165(v2740);
  return v2749;
}

struct StateG * slot_5(struct StateG * v258) {
  int v259 = v258->timer;
  int v269 = v259 + 1;
  v258->timer = v269;
  int * v261 = v258->pht;
  int v262 = v261[0];
  bool v272 = !(v262 == 0);
  struct StateG * v267;
  if (v272) {
    struct StateG * v263 = slot_6(v258);
    v267 = v263;
  } else {
    struct StateG * v265 = slot_7(v258);
    v267 = v265;
  }
  return v267;
}

struct StateG * slot_104(struct StateG * v2008) {
  int v2009 = v2008->timer;
  int v2015 = v2009 + 1;
  v2008->timer = v2015;
  int * v2011 = v2008->regs;
  v2011[1] = 36;
  struct StateG * v2013 = slot_112(v2008);
  return v2013;
}

struct StateG * slot_54(struct StateG * v1094) {
  int v1095 = v1094->timer;
  int v1101 = v1095 + 1;
  v1094->timer = v1101;
  int * v1097 = v1094->regs;
  v1097[1] = 36;
  struct StateG * v1099 = slot_58(v1094);
  return v1099;
}

struct StateG * slot_26(struct StateG * v624) {
  int * v625 = v624->saved_regs;
  int * v626 = v624->regs;
  int v627 = v626[19];
  v625[19] = v627;
  int v629 = v624->timer;
  int v639 = v629 + 1;
  v624->timer = v639;
  int * v631 = v624->regs;
  v631[19] = 2;
  struct StateG * v633 = slot_30(v624);
  return v633;
}

struct StateG * slot_64(struct StateG * v1252) {
  int * v1253 = v1252->saved_regs;
  int * v1254 = v1252->regs;
  int v1255 = v1254[18];
  v1253[18] = v1255;
  int v1257 = v1252->timer;
  int v1267 = v1257 + 1;
  v1252->timer = v1267;
  int * v1259 = v1252->regs;
  v1259[18] = 2;
  struct StateG * v1261 = slot_72(v1252);
  return v1261;
}

struct StateG * slot_14(struct StateG * v438) {
  int v439 = v438->timer;
  int v446 = v439 + 1;
  v438->timer = v446;
  int * v441 = v438->regs;
  int v442 = v441[1];
  bool v449 = v442 == 16;
  ret_assert(v449);
  struct StateG * v444 = slot_16(v438);
  return v444;
}

struct StateG * slot_53(struct StateG * v1081) {
  int v1082 = v1081->timer;
  int v1088 = v1082 + 1;
  v1081->timer = v1088;
  int * v1084 = v1081->regs;
  v1084[1] = 36;
  struct StateG * v1086 = slot_57(v1081);
  return v1086;
}

struct StateG * slot_80(struct StateG * v1728) {
  int v1729 = v1728->timer;
  int v1733 = v1729 + 1;
  v1728->timer = v1733;
  struct StateG * v1731 = slot_96(v1728);
  return v1731;
}

struct StateG * slot_44(struct StateG * v964) {
  int v965 = v964->timer;
  int v971 = v965 + 1;
  v964->timer = v971;
  int * v967 = v964->regs;
  v967[16] = 20;
  struct StateG * v969 = slot_48(v964);
  return v969;
}

struct StateG * slot_137(struct StateG * v2500) {
  int * v2501 = v2500->saved_regs;
  int * v2502 = v2500->regs;
  int v2503 = v2502[19];
  v2501[19] = v2503;
  int v2505 = v2500->timer;
  int v2515 = v2505 + 1;
  v2500->timer = v2515;
  int * v2507 = v2500->regs;
  v2507[19] = 1;
  struct StateG * v2509 = slot_153(v2500);
  return v2509;
}

struct StateG * slot_122(struct StateG * v2242) {
  int v2243 = v2242->timer;
  int v2249 = v2243 + 1;
  v2242->timer = v2249;
  int * v2245 = v2242->regs;
  v2245[17] = 10;
  struct StateG * v2247 = slot_130(v2242);
  return v2247;
}

struct StateG * slot_99(struct StateG * v1938) {
  int v1939 = v1938->timer;
  int v1946 = v1939 + 1;
  v1938->timer = v1946;
  int * v1941 = v1938->regs;
  int v1942 = v1941[1];
  bool v1949 = v1942 == 36;
  ret_assert(v1949);
  struct StateG * v1944 = slot_107(v1938);
  return v1944;
}

struct StateG * slot_36(struct StateG * v866) {
  int v867 = v866->timer;
  int v871 = v867 + 1;
  v866->timer = v871;
  struct StateG * v869 = slot_42(v866);
  return v869;
}

struct StateG * slot_57(struct StateG * v1133) {
  int v1134 = v1133->timer;
  int v1140 = v1134 + 1;
  v1133->timer = v1140;
  int * v1136 = v1133->regs;
  v1136[17] = 10;
  struct StateG * v1138 = slot_61(v1133);
  return v1138;
}

struct StateG * slot_62(struct StateG * v1212) {
  int v1213 = v1212->timer;
  int v1223 = v1213 + 1;
  v1212->timer = v1223;
  int * v1215 = v1212->pht;
  int v1216 = v1215[1];
  bool v1226 = !(v1216 == 0);
  struct StateG * v1221;
  if (v1226) {
    struct StateG * v1217 = slot_68(v1212);
    v1221 = v1217;
  } else {
    struct StateG * v1219 = slot_69(v1212);
    v1221 = v1219;
  }
  return v1221;
}

struct StateG * slot_22(struct StateG * v544) {
  int v545 = v544->timer;
  int v555 = v545 + 1;
  v544->timer = v555;
  int * v547 = v544->pht;
  int v548 = v547[65];
  bool v558 = !(v548 == 0);
  struct StateG * v553;
  if (v558) {
    struct StateG * v549 = slot_24(v544);
    v553 = v549;
  } else {
    struct StateG * v551 = slot_25(v544);
    v553 = v551;
  }
  return v553;
}

struct StateG * slot_139(struct StateG * v2540) {
  int * v2541 = v2540->saved_regs;
  int * v2542 = v2540->regs;
  int v2543 = v2542[19];
  v2541[19] = v2543;
  int v2545 = v2540->timer;
  int v2555 = v2545 + 1;
  v2540->timer = v2555;
  int * v2547 = v2540->regs;
  v2547[19] = 1;
  struct StateG * v2549 = slot_155(v2540);
  return v2549;
}

struct StateG * slot_23(struct StateG * v564) {
  int v565 = v564->timer;
  int v575 = v565 + 1;
  v564->timer = v575;
  int * v567 = v564->pht;
  int v568 = v567[64];
  bool v578 = !(v568 == 0);
  struct StateG * v573;
  if (v578) {
    struct StateG * v569 = slot_26(v564);
    v573 = v569;
  } else {
    struct StateG * v571 = slot_27(v564);
    v573 = v571;
  }
  return v573;
}

struct StateG * slot_153(struct StateG * v2840) {
  int * v2841 = v2840->regs;
  int v2842 = v2841[16];
  int v2843 = v2841[17];
  bool v2863 = v2842 >= v2843;
  struct StateG * v2858;
  if (v2863) {
    int * v2844 = v2840->pht;
    v2844[71] = 1;
    int v2846 = v2840->timer;
    int v2867 = v2846 + 15;
    v2840->timer = v2867;
    int * v2848 = v2840->saved_regs;
    int v2849 = v2848[19];
    int * v2850 = v2840->regs;
    v2850[19] = v2849;
    struct StateG * v2852 = slot_198(v2840);
    v2858 = v2852;
  } else {
    int * v2854 = v2840->pht;
    v2854[71] = 0;
    struct StateG * v2856 = slot_199(v2840);
    v2858 = v2856;
  }
  return v2858;
}

struct StateG * slot_2(struct StateG * v219) {
  int v220 = v219->timer;
  int v226 = v220 + 1;
  v219->timer = v226;
  int * v222 = v219->regs;
  v222[1] = 8;
  struct StateG * v224 = slot_3(v219);
  return v224;
}

struct StateG * slot_86(struct StateG * v1791) {
  int v1792 = v1791->timer;
  int v1798 = v1792 + 1;
  v1791->timer = v1798;
  int * v1794 = v1791->regs;
  v1794[18] = 2;
  struct StateG * v1796 = slot_84(v1791);
  return v1796;
}

struct StateG * slot_129(struct StateG * v2340) {
  int v2341 = v2340->timer;
  int v2351 = v2341 + 1;
  v2340->timer = v2351;
  int * v2343 = v2340->pht;
  int v2344 = v2343[70];
  bool v2354 = !(v2344 == 0);
  struct StateG * v2349;
  if (v2354) {
    struct StateG * v2345 = slot_138(v2340);
    v2349 = v2345;
  } else {
    struct StateG * v2347 = slot_139(v2340);
    v2349 = v2347;
  }
  return v2349;
}

struct StateG * slot_158(struct StateG * v3040) {
  int * v3041 = v3040->regs;
  int v3042 = v3041[16];
  int v3043 = v3041[17];
  bool v3063 = v3042 >= v3043;
  struct StateG * v3058;
  if (v3063) {
    int * v3044 = v3040->pht;
    v3044[68] = 1;
    struct StateG * v3046 = slot_199(v3040);
    v3058 = v3046;
  } else {
    int * v3048 = v3040->pht;
    v3048[68] = 0;
    int v3050 = v3040->timer;
    int v3072 = v3050 + 15;
    v3040->timer = v3072;
    int * v3052 = v3040->saved_regs;
    int v3053 = v3052[19];
    int * v3054 = v3040->regs;
    v3054[19] = v3053;
    struct StateG * v3056 = slot_177(v3040);
    v3058 = v3056;
  }
  return v3058;
}

struct StateG * slot_100(struct StateG * v1952) {
  int v1953 = v1952->timer;
  int v1960 = v1953 + 1;
  v1952->timer = v1960;
  int * v1955 = v1952->regs;
  int v1956 = v1955[1];
  bool v1963 = v1956 == 36;
  ret_assert(v1963);
  struct StateG * v1958 = slot_108(v1952);
  return v1958;
}

struct StateG * slot_127(struct StateG * v2307) {
  int v2308 = v2307->timer;
  int v2314 = v2308 + 1;
  v2307->timer = v2314;
  int * v2310 = v2307->regs;
  v2310[17] = 10;
  struct StateG * v2312 = slot_135(v2307);
  return v2312;
}

struct StateG * slot_13(struct StateG * v430) {
  int v431 = v430->timer;
  int v435 = v431 + 1;
  v430->timer = v435;
  struct StateG * v433 = slot_15(v430);
  return v433;
}

struct StateG * slot_111(struct StateG * v2099) {
  int v2100 = v2099->timer;
  int v2106 = v2100 + 1;
  v2099->timer = v2106;
  int * v2102 = v2099->regs;
  v2102[1] = 36;
  struct StateG * v2104 = slot_119(v2099);
  return v2104;
}

struct StateG * slot_109(struct StateG * v2073) {
  int v2074 = v2073->timer;
  int v2080 = v2074 + 1;
  v2073->timer = v2080;
  int * v2076 = v2073->regs;
  v2076[1] = 36;
  struct StateG * v2078 = slot_117(v2073);
  return v2078;
}

struct StateG * slot_147(struct StateG * v2700) {
  int * v2701 = v2700->saved_regs;
  int * v2702 = v2700->regs;
  int v2703 = v2702[19];
  v2701[19] = v2703;
  int v2705 = v2700->timer;
  int v2715 = v2705 + 1;
  v2700->timer = v2715;
  int * v2707 = v2700->regs;
  v2707[19] = 1;
  struct StateG * v2709 = slot_163(v2700);
  return v2709;
}

struct StateG * slot_42(struct StateG * v936) {
  int v937 = v936->timer;
  int v944 = v937 + 1;
  v936->timer = v944;
  int * v939 = v936->regs;
  int v940 = v939[1];
  bool v947 = v940 == 24;
  ret_assert(v947);
  struct StateG * v942 = slot_46(v936);
  return v942;
}

struct StateG * slot_163(struct StateG * v3240) {
  int * v3241 = v3240->regs;
  int v3242 = v3241[16];
  int v3243 = v3241[17];
  bool v3263 = v3242 >= v3243;
  struct StateG * v3258;
  if (v3263) {
    int * v3244 = v3240->pht;
    v3244[66] = 1;
    int v3246 = v3240->timer;
    int v3267 = v3246 + 15;
    v3240->timer = v3267;
    int * v3248 = v3240->saved_regs;
    int v3249 = v3248[19];
    int * v3250 = v3240->regs;
    v3250[19] = v3249;
    struct StateG * v3252 = slot_198(v3240);
    v3258 = v3252;
  } else {
    int * v3254 = v3240->pht;
    v3254[66] = 0;
    struct StateG * v3256 = slot_199(v3240);
    v3258 = v3256;
  }
  return v3258;
}

struct StateG * slot_165(struct StateG * v3320) {
  int * v3321 = v3320->regs;
  int v3322 = v3321[16];
  int v3323 = v3321[17];
  bool v3343 = v3322 >= v3323;
  struct StateG * v3338;
  if (v3343) {
    int * v3324 = v3320->pht;
    v3324[65] = 1;
    int v3326 = v3320->timer;
    int v3347 = v3326 + 15;
    v3320->timer = v3347;
    int * v3328 = v3320->saved_regs;
    int v3329 = v3328[19];
    int * v3330 = v3320->regs;
    v3330[19] = v3329;
    struct StateG * v3332 = slot_198(v3320);
    v3338 = v3332;
  } else {
    int * v3334 = v3320->pht;
    v3334[65] = 0;
    struct StateG * v3336 = slot_199(v3320);
    v3338 = v3336;
  }
  return v3338;
}

struct StateG * snippet(struct StateG * v0) {
  struct StateG * v1 = slot_0(v0);
  return v1;
}

struct StateG * slot_117(struct StateG * v2177) {
  int v2178 = v2177->timer;
  int v2184 = v2178 + 1;
  v2177->timer = v2184;
  int * v2180 = v2177->regs;
  v2180[1] = 44;
  struct StateG * v2182 = slot_125(v2177);
  return v2182;
}

struct StateG * slot_90(struct StateG * v1833) {
  int v1834 = v1833->timer;
  int v1840 = v1834 + 1;
  v1833->timer = v1840;
  int * v1836 = v1833->regs;
  v1836[18] = 2;
  struct StateG * v1838 = slot_88(v1833);
  return v1838;
}

struct StateG * slot_11(struct StateG * v404) {
  int v405 = v404->timer;
  int v411 = v405 + 1;
  v404->timer = v411;
  int * v407 = v404->regs;
  v407[18] = 1;
  struct StateG * v409 = slot_13(v404);
  return v409;
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

void ret_assert(bool c) { koika_assert(c, "return address"); }

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