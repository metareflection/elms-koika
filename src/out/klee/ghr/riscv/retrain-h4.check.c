// verify: clean (KLEE should report no failing assertion) [budget 1200s]
#define NUM_REGS 32
#define MEM_SIZE 64
#define SECRET_SIZE 10
#define SECRET_OFFSET 20
#define CACHE_ENTRIES 12
#define CACHE_WORDS 24
#define PHT_ENTRIES 512
#define HISTORY_BITS 4

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
struct StateG * slot_228(struct StateG * v4042);
struct StateG * slot_143(struct StateG * v2612);
struct StateG * slot_120(struct StateG * v2208);
struct StateG * slot_167(struct StateG * v3384);
struct StateG * slot_152(struct StateG * v2792);
struct StateG * slot_199(struct StateG * v3750);
struct StateG * slot_92(struct StateG * v1846);
struct StateG * slot_31(struct StateG * v778);
struct StateG * slot_160(struct StateG * v3112);
struct StateG * slot_65(struct StateG * v1264);
struct StateG * slot_10(struct StateG * v396);
struct StateG * slot_150(struct StateG * v2752);
struct StateG * slot_74(struct StateG * v1484);
struct StateG * slot_107(struct StateG * v2039);
struct StateG * slot_136(struct StateG * v2472);
struct StateG * slot_84(struct StateG * v1762);
struct StateG * slot_28(struct StateG * v664);
struct StateG * slot_155(struct StateG * v2912);
struct StateG * slot_177(struct StateG * v3514);
struct StateG * slot_17(struct StateG * v479);
struct StateG * slot_207(struct StateG * v3856);
struct StateG * slot_156(struct StateG * v2952);
struct StateG * slot_154(struct StateG * v2872);
struct StateG * slot_68(struct StateG * v1324);
struct StateG * slot_105(struct StateG * v2013);
struct StateG * slot_27(struct StateG * v644);
struct StateG * slot_164(struct StateG * v3270);
struct StateG * slot_15(struct StateG * v452);
struct StateG * slot_133(struct StateG * v2412);
struct StateG * slot_56(struct StateG * v1112);
struct StateG * slot_34(struct StateG * v837);
struct StateG * slot_162(struct StateG * v3190);
struct StateG * slot_21(struct StateG * v531);
struct StateG * slot_118(struct StateG * v2182);
struct StateG * slot_121(struct StateG * v2221);
struct StateG * slot_144(struct StateG * v2632);
struct StateG * slot_94(struct StateG * v1867);
struct StateG * slot_63(struct StateG * v1224);
struct StateG * slot_146(struct StateG * v2672);
struct StateG * slot_24(struct StateG * v584);
struct StateG * slot_0(struct StateG * v2);
struct StateG * slot_125(struct StateG * v2273);
struct StateG * slot_148(struct StateG * v2712);
struct StateG * slot_126(struct StateG * v2286);
struct StateG * slot_79(struct StateG * v1681);
struct StateG * slot_41(struct StateG * v914);
struct StateG * slot_39(struct StateG * v892);
struct StateG * slot_142(struct StateG * v2592);
struct StateG * slot_60(struct StateG * v1164);
struct StateG * slot_112(struct StateG * v2104);
struct StateG * slot_47(struct StateG * v995);
struct StateG * slot_29(struct StateG * v702);
struct StateG * slot_16(struct StateG * v466);
struct StateG * slot_113(struct StateG * v2117);
struct StateG * slot_151(struct StateG * v2772);
struct StateG * slot_7(struct StateG * v298);
struct StateG * slot_124(struct StateG * v2260);
struct StateG * slot_103(struct StateG * v1986);
struct StateG * slot_128(struct StateG * v2312);
struct StateG * slot_19(struct StateG * v505);
struct StateG * slot_87(struct StateG * v1796);
struct StateG * slot_67(struct StateG * v1304);
struct StateG * slot_81(struct StateG * v1728);
struct StateG * slot_95(struct StateG * v1880);
struct StateG * slot_115(struct StateG * v2143);
struct StateG * slot_78(struct StateG * v1642);
struct StateG * slot_32(struct StateG * v816);
struct StateG * slot_33(struct StateG * v824);
struct StateG * slot_35(struct StateG * v850);
struct StateG * slot_166(struct StateG * v3346);
struct StateG * slot_51(struct StateG * v1047);
struct StateG * slot_52(struct StateG * v1060);
struct StateG * slot_83(struct StateG * v1754);
struct StateG * slot_25(struct StateG * v604);
struct StateG * slot_3(struct StateG * v232);
struct StateG * slot_123(struct StateG * v2247);
struct StateG * slot_73(struct StateG * v1444);
struct StateG * slot_198(struct StateG * v3737);
struct StateG * slot_1(struct StateG * v15);
struct StateG * slot_97(struct StateG * v1902);
struct StateG * slot_38(struct StateG * v879);
struct StateG * slot_106(struct StateG * v2026);
struct StateG * slot_98(struct StateG * v1916);
struct StateG * slot_159(struct StateG * v3072);
struct StateG * slot_46(struct StateG * v982);
struct StateG * slot_132(struct StateG * v2392);
struct StateG * slot_130(struct StateG * v2352);
struct StateG * slot_20(struct StateG * v518);
struct StateG * slot_141(struct StateG * v2572);
struct StateG * slot_61(struct StateG * v1184);
struct StateG * slot_30(struct StateG * v740);
struct StateG * slot_4(struct StateG * v245);
struct StateG * slot_18(struct StateG * v492);
struct StateG * slot_9(struct StateG * v357);
struct StateG * slot_43(struct StateG * v942);
struct StateG * slot_70(struct StateG * v1364);
struct StateG * slot_76(struct StateG * v1564);
struct StateG * slot_6(struct StateG * v278);
struct StateG * slot_55(struct StateG * v1099);
struct StateG * slot_82(struct StateG * v1741);
struct StateG * slot_161(struct StateG * v3151);
struct StateG * slot_91(struct StateG * v1838);
struct StateG * slot_58(struct StateG * v1138);
struct StateG * slot_89(struct StateG * v1812);
struct StateG * slot_66(struct StateG * v1284);
struct StateG * slot_140(struct StateG * v2552);
struct StateG * slot_49(struct StateG * v1021);
struct StateG * slot_50(struct StateG * v1034);
struct StateG * slot_37(struct StateG * v866);
struct StateG * slot_114(struct StateG * v2130);
struct StateG * slot_135(struct StateG * v2452);
struct StateG * slot_59(struct StateG * v1151);
struct StateG * slot_40(struct StateG * v900);
struct StateG * slot_48(struct StateG * v1008);
struct StateG * slot_77(struct StateG * v1603);
struct StateG * slot_85(struct StateG * v1770);
struct StateG * slot_75(struct StateG * v1524);
struct StateG * slot_72(struct StateG * v1404);
struct StateG * slot_119(struct StateG * v2195);
struct StateG * slot_71(struct StateG * v1384);
struct StateG * slot_101(struct StateG * v1958);
struct StateG * slot_108(struct StateG * v2052);
struct StateG * slot_116(struct StateG * v2156);
struct StateG * slot_93(struct StateG * v1854);
struct StateG * slot_88(struct StateG * v1804);
struct StateG * slot_96(struct StateG * v1888);
struct StateG * slot_45(struct StateG * v969);
struct StateG * slot_134(struct StateG * v2432);
struct StateG * slot_69(struct StateG * v1344);
struct StateG * slot_138(struct StateG * v2512);
struct StateG * slot_102(struct StateG * v1972);
struct StateG * slot_145(struct StateG * v2652);
struct StateG * slot_110(struct StateG * v2078);
struct StateG * slot_131(struct StateG * v2372);
struct StateG * slot_8(struct StateG * v318);
struct StateG * slot_157(struct StateG * v2992);
struct StateG * slot_149(struct StateG * v2732);
struct StateG * slot_5(struct StateG * v258);
struct StateG * slot_104(struct StateG * v2000);
struct StateG * slot_54(struct StateG * v1086);
struct StateG * slot_26(struct StateG * v624);
struct StateG * slot_64(struct StateG * v1244);
struct StateG * slot_14(struct StateG * v438);
struct StateG * slot_53(struct StateG * v1073);
struct StateG * slot_80(struct StateG * v1720);
struct StateG * slot_44(struct StateG * v956);
struct StateG * slot_137(struct StateG * v2492);
struct StateG * slot_122(struct StateG * v2234);
struct StateG * slot_99(struct StateG * v1930);
struct StateG * slot_36(struct StateG * v858);
struct StateG * slot_57(struct StateG * v1125);
struct StateG * slot_62(struct StateG * v1204);
struct StateG * slot_22(struct StateG * v544);
struct StateG * slot_139(struct StateG * v2532);
struct StateG * slot_23(struct StateG * v564);
struct StateG * slot_153(struct StateG * v2832);
struct StateG * slot_2(struct StateG * v219);
struct StateG * slot_86(struct StateG * v1783);
struct StateG * slot_129(struct StateG * v2332);
struct StateG * slot_158(struct StateG * v3032);
struct StateG * slot_100(struct StateG * v1944);
struct StateG * slot_127(struct StateG * v2299);
struct StateG * slot_13(struct StateG * v430);
struct StateG * slot_111(struct StateG * v2091);
struct StateG * slot_109(struct StateG * v2065);
struct StateG * slot_147(struct StateG * v2692);
struct StateG * slot_42(struct StateG * v928);
struct StateG * slot_163(struct StateG * v3230);
struct StateG * slot_165(struct StateG * v3308);
struct StateG * snippet(struct StateG * v0);
struct StateG * slot_117(struct StateG * v2169);
struct StateG * slot_90(struct StateG * v1825);
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

struct StateG * slot_228(struct StateG * v4042) {
  int v4043 = v4042->timer;
  int v4046 = v4043 + 1;
  v4042->timer = v4046;
  return v4042;
}

struct StateG * slot_143(struct StateG * v2612) {
  int * v2613 = v2612->saved_regs;
  int * v2614 = v2612->regs;
  int v2615 = v2614[19];
  v2613[19] = v2615;
  int v2617 = v2612->timer;
  int v2627 = v2617 + 1;
  v2612->timer = v2627;
  int * v2619 = v2612->regs;
  v2619[19] = 1;
  struct StateG * v2621 = slot_159(v2612);
  return v2621;
}

struct StateG * slot_120(struct StateG * v2208) {
  int v2209 = v2208->timer;
  int v2215 = v2209 + 1;
  v2208->timer = v2215;
  int * v2211 = v2208->regs;
  v2211[17] = 10;
  struct StateG * v2213 = slot_128(v2208);
  return v2213;
}

struct StateG * slot_167(struct StateG * v3384) {
  int * v3385 = v3384->regs;
  int v3386 = v3385[16];
  int v3387 = v3385[17];
  bool v3407 = v3386 >= v3387;
  struct StateG * v3402;
  if (v3407) {
    int * v3388 = v3384->pht;
    v3388[16] = 1;
    int v3390 = v3384->timer;
    int v3410 = v3390 + 15;
    v3384->timer = v3410;
    int * v3392 = v3384->saved_regs;
    int v3393 = v3392[19];
    int * v3394 = v3384->regs;
    v3394[19] = v3393;
    struct StateG * v3396 = slot_198(v3384);
    v3402 = v3396;
  } else {
    int * v3398 = v3384->pht;
    v3398[16] = 0;
    struct StateG * v3400 = slot_199(v3384);
    v3402 = v3400;
  }
  return v3402;
}

struct StateG * slot_152(struct StateG * v2792) {
  int * v2793 = v2792->regs;
  int v2794 = v2793[16];
  int v2795 = v2793[17];
  bool v2815 = v2794 >= v2795;
  struct StateG * v2810;
  if (v2815) {
    int * v2796 = v2792->pht;
    v2796[23] = 1;
    struct StateG * v2798 = slot_199(v2792);
    v2810 = v2798;
  } else {
    int * v2800 = v2792->pht;
    v2800[23] = 0;
    int v2802 = v2792->timer;
    int v2824 = v2802 + 15;
    v2792->timer = v2824;
    int * v2804 = v2792->saved_regs;
    int v2805 = v2804[19];
    int * v2806 = v2792->regs;
    v2806[19] = v2805;
    struct StateG * v2808 = slot_177(v2792);
    v2810 = v2808;
  }
  return v2810;
}

struct StateG * slot_199(struct StateG * v3750) {
  int v3751 = v3750->timer;
  int v3755 = v3751 + 1;
  v3750->timer = v3755;
  struct StateG * v3753 = slot_207(v3750);
  return v3753;
}

struct StateG * slot_92(struct StateG * v1846) {
  int v1847 = v1846->timer;
  int v1851 = v1847 + 1;
  v1846->timer = v1851;
  struct StateG * v1849 = slot_102(v1846);
  return v1849;
}

struct StateG * slot_31(struct StateG * v778) {
  int * v779 = v778->regs;
  int v780 = v779[16];
  int v781 = v779[17];
  bool v801 = v780 >= v781;
  struct StateG * v796;
  if (v801) {
    int * v782 = v778->pht;
    v782[16] = 1;
    int v784 = v778->timer;
    int v804 = v784 + 15;
    v778->timer = v804;
    int * v786 = v778->saved_regs;
    int v787 = v786[19];
    int * v788 = v778->regs;
    v788[19] = v787;
    struct StateG * v790 = slot_38(v778);
    v796 = v790;
  } else {
    int * v792 = v778->pht;
    v792[16] = 0;
    struct StateG * v794 = slot_39(v778);
    v796 = v794;
  }
  return v796;
}

struct StateG * slot_160(struct StateG * v3112) {
  int * v3113 = v3112->regs;
  int v3114 = v3113[16];
  int v3115 = v3113[17];
  bool v3135 = v3114 >= v3115;
  struct StateG * v3130;
  if (v3135) {
    int * v3116 = v3112->pht;
    v3116[19] = 1;
    struct StateG * v3118 = slot_199(v3112);
    v3130 = v3118;
  } else {
    int * v3120 = v3112->pht;
    v3120[19] = 0;
    int v3122 = v3112->timer;
    int v3144 = v3122 + 15;
    v3112->timer = v3144;
    int * v3124 = v3112->saved_regs;
    int v3125 = v3124[19];
    int * v3126 = v3112->regs;
    v3126[19] = v3125;
    struct StateG * v3128 = slot_177(v3112);
    v3130 = v3128;
  }
  return v3130;
}

struct StateG * slot_65(struct StateG * v1264) {
  int * v1265 = v1264->saved_regs;
  int * v1266 = v1264->regs;
  int v1267 = v1266[18];
  v1265[18] = v1267;
  int v1269 = v1264->timer;
  int v1279 = v1269 + 1;
  v1264->timer = v1279;
  int * v1271 = v1264->regs;
  v1271[18] = 1;
  struct StateG * v1273 = slot_73(v1264);
  return v1273;
}

struct StateG * slot_10(struct StateG * v396) {
  int v397 = v396->timer;
  int v401 = v397 + 1;
  v396->timer = v401;
  struct StateG * v399 = slot_14(v396);
  return v399;
}

struct StateG * slot_150(struct StateG * v2752) {
  int * v2753 = v2752->saved_regs;
  int * v2754 = v2752->regs;
  int v2755 = v2754[19];
  v2753[19] = v2755;
  int v2757 = v2752->timer;
  int v2767 = v2757 + 1;
  v2752->timer = v2767;
  int * v2759 = v2752->regs;
  v2759[19] = 2;
  struct StateG * v2761 = slot_166(v2752);
  return v2761;
}

struct StateG * slot_74(struct StateG * v1484) {
  int * v1485 = v1484->regs;
  int v1486 = v1485[16];
  int v1487 = v1485[17];
  bool v1507 = v1486 < v1487;
  struct StateG * v1502;
  if (v1507) {
    int * v1488 = v1484->pht;
    v1488[2] = 1;
    struct StateG * v1490 = slot_84(v1484);
    v1502 = v1490;
  } else {
    int * v1492 = v1484->pht;
    v1492[2] = 0;
    int v1494 = v1484->timer;
    int v1516 = v1494 + 15;
    v1484->timer = v1516;
    int * v1496 = v1484->saved_regs;
    int v1497 = v1496[18];
    int * v1498 = v1484->regs;
    v1498[18] = v1497;
    struct StateG * v1500 = slot_85(v1484);
    v1502 = v1500;
  }
  return v1502;
}

struct StateG * slot_107(struct StateG * v2039) {
  int v2040 = v2039->timer;
  int v2046 = v2040 + 1;
  v2039->timer = v2046;
  int * v2042 = v2039->regs;
  v2042[1] = 36;
  struct StateG * v2044 = slot_115(v2039);
  return v2044;
}

struct StateG * slot_136(struct StateG * v2472) {
  int * v2473 = v2472->saved_regs;
  int * v2474 = v2472->regs;
  int v2475 = v2474[19];
  v2473[19] = v2475;
  int v2477 = v2472->timer;
  int v2487 = v2477 + 1;
  v2472->timer = v2487;
  int * v2479 = v2472->regs;
  v2479[19] = 2;
  struct StateG * v2481 = slot_152(v2472);
  return v2481;
}

struct StateG * slot_84(struct StateG * v1762) {
  int v1763 = v1762->timer;
  int v1767 = v1763 + 1;
  v1762->timer = v1767;
  struct StateG * v1765 = slot_98(v1762);
  return v1765;
}

struct StateG * slot_28(struct StateG * v664) {
  int * v665 = v664->regs;
  int v666 = v665[16];
  int v667 = v665[17];
  bool v687 = v666 >= v667;
  struct StateG * v682;
  if (v687) {
    int * v668 = v664->pht;
    v668[17] = 1;
    struct StateG * v670 = slot_32(v664);
    v682 = v670;
  } else {
    int * v672 = v664->pht;
    v672[17] = 0;
    int v674 = v664->timer;
    int v694 = v674 + 15;
    v664->timer = v694;
    int * v676 = v664->saved_regs;
    int v677 = v676[19];
    int * v678 = v664->regs;
    v678[19] = v677;
    struct StateG * v680 = slot_33(v664);
    v682 = v680;
  }
  return v682;
}

struct StateG * slot_155(struct StateG * v2912) {
  int * v2913 = v2912->regs;
  int v2914 = v2913[16];
  int v2915 = v2913[17];
  bool v2935 = v2914 >= v2915;
  struct StateG * v2930;
  if (v2935) {
    int * v2916 = v2912->pht;
    v2916[22] = 1;
    int v2918 = v2912->timer;
    int v2939 = v2918 + 15;
    v2912->timer = v2939;
    int * v2920 = v2912->saved_regs;
    int v2921 = v2920[19];
    int * v2922 = v2912->regs;
    v2922[19] = v2921;
    struct StateG * v2924 = slot_198(v2912);
    v2930 = v2924;
  } else {
    int * v2926 = v2912->pht;
    v2926[22] = 0;
    struct StateG * v2928 = slot_199(v2912);
    v2930 = v2928;
  }
  return v2930;
}

struct StateG * slot_177(struct StateG * v3514) {
  int v3515 = v3514->timer;
  int v3521 = v3515 + 1;
  v3514->timer = v3521;
  int * v3517 = v3514->regs;
  v3517[19] = 1;
  struct StateG * v3519 = slot_199(v3514);
  return v3519;
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

struct StateG * slot_207(struct StateG * v3856) {
  int v3857 = v3856->timer;
  int v3864 = v3857 + 1;
  v3856->timer = v3864;
  int * v3859 = v3856->regs;
  int v3860 = v3859[1];
  bool v3867 = v3860 == 44;
  ret_assert(v3867);
  struct StateG * v3862 = slot_228(v3856);
  return v3862;
}

struct StateG * slot_156(struct StateG * v2952) {
  int * v2953 = v2952->regs;
  int v2954 = v2953[16];
  int v2955 = v2953[17];
  bool v2975 = v2954 >= v2955;
  struct StateG * v2970;
  if (v2975) {
    int * v2956 = v2952->pht;
    v2956[21] = 1;
    struct StateG * v2958 = slot_199(v2952);
    v2970 = v2958;
  } else {
    int * v2960 = v2952->pht;
    v2960[21] = 0;
    int v2962 = v2952->timer;
    int v2984 = v2962 + 15;
    v2952->timer = v2984;
    int * v2964 = v2952->saved_regs;
    int v2965 = v2964[19];
    int * v2966 = v2952->regs;
    v2966[19] = v2965;
    struct StateG * v2968 = slot_177(v2952);
    v2970 = v2968;
  }
  return v2970;
}

struct StateG * slot_154(struct StateG * v2872) {
  int * v2873 = v2872->regs;
  int v2874 = v2873[16];
  int v2875 = v2873[17];
  bool v2895 = v2874 >= v2875;
  struct StateG * v2890;
  if (v2895) {
    int * v2876 = v2872->pht;
    v2876[22] = 1;
    struct StateG * v2878 = slot_199(v2872);
    v2890 = v2878;
  } else {
    int * v2880 = v2872->pht;
    v2880[22] = 0;
    int v2882 = v2872->timer;
    int v2904 = v2882 + 15;
    v2872->timer = v2904;
    int * v2884 = v2872->saved_regs;
    int v2885 = v2884[19];
    int * v2886 = v2872->regs;
    v2886[19] = v2885;
    struct StateG * v2888 = slot_177(v2872);
    v2890 = v2888;
  }
  return v2890;
}

struct StateG * slot_68(struct StateG * v1324) {
  int * v1325 = v1324->saved_regs;
  int * v1326 = v1324->regs;
  int v1327 = v1326[18];
  v1325[18] = v1327;
  int v1329 = v1324->timer;
  int v1339 = v1329 + 1;
  v1324->timer = v1339;
  int * v1331 = v1324->regs;
  v1331[18] = 2;
  struct StateG * v1333 = slot_76(v1324);
  return v1333;
}

struct StateG * slot_105(struct StateG * v2013) {
  int v2014 = v2013->timer;
  int v2020 = v2014 + 1;
  v2013->timer = v2020;
  int * v2016 = v2013->regs;
  v2016[1] = 36;
  struct StateG * v2018 = slot_113(v2013);
  return v2018;
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

struct StateG * slot_164(struct StateG * v3270) {
  int * v3271 = v3270->regs;
  int v3272 = v3271[16];
  int v3273 = v3271[17];
  bool v3293 = v3272 >= v3273;
  struct StateG * v3288;
  if (v3293) {
    int * v3274 = v3270->pht;
    v3274[17] = 1;
    struct StateG * v3276 = slot_199(v3270);
    v3288 = v3276;
  } else {
    int * v3278 = v3270->pht;
    v3278[17] = 0;
    int v3280 = v3270->timer;
    int v3300 = v3280 + 15;
    v3270->timer = v3300;
    int * v3282 = v3270->saved_regs;
    int v3283 = v3282[19];
    int * v3284 = v3270->regs;
    v3284[19] = v3283;
    struct StateG * v3286 = slot_177(v3270);
    v3288 = v3286;
  }
  return v3288;
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

struct StateG * slot_133(struct StateG * v2412) {
  int v2413 = v2412->timer;
  int v2423 = v2413 + 1;
  v2412->timer = v2423;
  int * v2415 = v2412->pht;
  int v2416 = v2415[18];
  bool v2426 = !(v2416 == 0);
  struct StateG * v2421;
  if (v2426) {
    struct StateG * v2417 = slot_146(v2412);
    v2421 = v2417;
  } else {
    struct StateG * v2419 = slot_147(v2412);
    v2421 = v2419;
  }
  return v2421;
}

struct StateG * slot_56(struct StateG * v1112) {
  int v1113 = v1112->timer;
  int v1119 = v1113 + 1;
  v1112->timer = v1119;
  int * v1115 = v1112->regs;
  v1115[17] = 10;
  struct StateG * v1117 = slot_60(v1112);
  return v1117;
}

struct StateG * slot_34(struct StateG * v837) {
  int v838 = v837->timer;
  int v844 = v838 + 1;
  v837->timer = v844;
  int * v840 = v837->regs;
  v840[19] = 2;
  struct StateG * v842 = slot_32(v837);
  return v842;
}

struct StateG * slot_162(struct StateG * v3190) {
  int * v3191 = v3190->regs;
  int v3192 = v3191[16];
  int v3193 = v3191[17];
  bool v3213 = v3192 >= v3193;
  struct StateG * v3208;
  if (v3213) {
    int * v3194 = v3190->pht;
    v3194[18] = 1;
    struct StateG * v3196 = slot_199(v3190);
    v3208 = v3196;
  } else {
    int * v3198 = v3190->pht;
    v3198[18] = 0;
    int v3200 = v3190->timer;
    int v3222 = v3200 + 15;
    v3190->timer = v3222;
    int * v3202 = v3190->saved_regs;
    int v3203 = v3202[19];
    int * v3204 = v3190->regs;
    v3204[19] = v3203;
    struct StateG * v3206 = slot_177(v3190);
    v3208 = v3206;
  }
  return v3208;
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

struct StateG * slot_118(struct StateG * v2182) {
  int v2183 = v2182->timer;
  int v2189 = v2183 + 1;
  v2182->timer = v2189;
  int * v2185 = v2182->regs;
  v2185[1] = 44;
  struct StateG * v2187 = slot_126(v2182);
  return v2187;
}

struct StateG * slot_121(struct StateG * v2221) {
  int v2222 = v2221->timer;
  int v2228 = v2222 + 1;
  v2221->timer = v2228;
  int * v2224 = v2221->regs;
  v2224[17] = 10;
  struct StateG * v2226 = slot_129(v2221);
  return v2226;
}

struct StateG * slot_144(struct StateG * v2632) {
  int * v2633 = v2632->saved_regs;
  int * v2634 = v2632->regs;
  int v2635 = v2634[19];
  v2633[19] = v2635;
  int v2637 = v2632->timer;
  int v2647 = v2637 + 1;
  v2632->timer = v2647;
  int * v2639 = v2632->regs;
  v2639[19] = 2;
  struct StateG * v2641 = slot_160(v2632);
  return v2641;
}

struct StateG * slot_94(struct StateG * v1867) {
  int v1868 = v1867->timer;
  int v1874 = v1868 + 1;
  v1867->timer = v1874;
  int * v1870 = v1867->regs;
  v1870[18] = 2;
  struct StateG * v1872 = slot_92(v1867);
  return v1872;
}

struct StateG * slot_63(struct StateG * v1224) {
  int v1225 = v1224->timer;
  int v1235 = v1225 + 1;
  v1224->timer = v1235;
  int * v1227 = v1224->pht;
  int v1228 = v1227[0];
  bool v1238 = !(v1228 == 0);
  struct StateG * v1233;
  if (v1238) {
    struct StateG * v1229 = slot_70(v1224);
    v1233 = v1229;
  } else {
    struct StateG * v1231 = slot_71(v1224);
    v1233 = v1231;
  }
  return v1233;
}

struct StateG * slot_146(struct StateG * v2672) {
  int * v2673 = v2672->saved_regs;
  int * v2674 = v2672->regs;
  int v2675 = v2674[19];
  v2673[19] = v2675;
  int v2677 = v2672->timer;
  int v2687 = v2677 + 1;
  v2672->timer = v2687;
  int * v2679 = v2672->regs;
  v2679[19] = 2;
  struct StateG * v2681 = slot_162(v2672);
  return v2681;
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

struct StateG * slot_125(struct StateG * v2273) {
  int v2274 = v2273->timer;
  int v2280 = v2274 + 1;
  v2273->timer = v2280;
  int * v2276 = v2273->regs;
  v2276[17] = 10;
  struct StateG * v2278 = slot_133(v2273);
  return v2278;
}

struct StateG * slot_148(struct StateG * v2712) {
  int * v2713 = v2712->saved_regs;
  int * v2714 = v2712->regs;
  int v2715 = v2714[19];
  v2713[19] = v2715;
  int v2717 = v2712->timer;
  int v2727 = v2717 + 1;
  v2712->timer = v2727;
  int * v2719 = v2712->regs;
  v2719[19] = 2;
  struct StateG * v2721 = slot_164(v2712);
  return v2721;
}

struct StateG * slot_126(struct StateG * v2286) {
  int v2287 = v2286->timer;
  int v2293 = v2287 + 1;
  v2286->timer = v2293;
  int * v2289 = v2286->regs;
  v2289[17] = 10;
  struct StateG * v2291 = slot_134(v2286);
  return v2291;
}

struct StateG * slot_79(struct StateG * v1681) {
  int * v1682 = v1681->regs;
  int v1683 = v1682[16];
  int v1684 = v1682[17];
  bool v1704 = v1683 < v1684;
  struct StateG * v1699;
  if (v1704) {
    int * v1685 = v1681->pht;
    v1685[0] = 1;
    int v1687 = v1681->timer;
    int v1708 = v1687 + 15;
    v1681->timer = v1708;
    int * v1689 = v1681->saved_regs;
    int v1690 = v1689[18];
    int * v1691 = v1681->regs;
    v1691[18] = v1690;
    struct StateG * v1693 = slot_94(v1681);
    v1699 = v1693;
  } else {
    int * v1695 = v1681->pht;
    v1695[0] = 0;
    struct StateG * v1697 = slot_95(v1681);
    v1699 = v1697;
  }
  return v1699;
}

struct StateG * slot_41(struct StateG * v914) {
  int v915 = v914->timer;
  int v922 = v915 + 1;
  v914->timer = v922;
  int * v917 = v914->regs;
  int v918 = v917[1];
  bool v925 = v918 == 24;
  ret_assert(v925);
  struct StateG * v920 = slot_45(v914);
  return v920;
}

struct StateG * slot_39(struct StateG * v892) {
  int v893 = v892->timer;
  int v897 = v893 + 1;
  v892->timer = v897;
  struct StateG * v895 = slot_43(v892);
  return v895;
}

struct StateG * slot_142(struct StateG * v2592) {
  int * v2593 = v2592->saved_regs;
  int * v2594 = v2592->regs;
  int v2595 = v2594[19];
  v2593[19] = v2595;
  int v2597 = v2592->timer;
  int v2607 = v2597 + 1;
  v2592->timer = v2607;
  int * v2599 = v2592->regs;
  v2599[19] = 2;
  struct StateG * v2601 = slot_158(v2592);
  return v2601;
}

struct StateG * slot_60(struct StateG * v1164) {
  int v1165 = v1164->timer;
  int v1175 = v1165 + 1;
  v1164->timer = v1175;
  int * v1167 = v1164->pht;
  int v1168 = v1167[3];
  bool v1178 = !(v1168 == 0);
  struct StateG * v1173;
  if (v1178) {
    struct StateG * v1169 = slot_64(v1164);
    v1173 = v1169;
  } else {
    struct StateG * v1171 = slot_65(v1164);
    v1173 = v1171;
  }
  return v1173;
}

struct StateG * slot_112(struct StateG * v2104) {
  int v2105 = v2104->timer;
  int v2111 = v2105 + 1;
  v2104->timer = v2111;
  int * v2107 = v2104->regs;
  v2107[1] = 44;
  struct StateG * v2109 = slot_120(v2104);
  return v2109;
}

struct StateG * slot_47(struct StateG * v995) {
  int v996 = v995->timer;
  int v1002 = v996 + 1;
  v995->timer = v1002;
  int * v998 = v995->regs;
  v998[16] = 20;
  struct StateG * v1000 = slot_51(v995);
  return v1000;
}

struct StateG * slot_29(struct StateG * v702) {
  int * v703 = v702->regs;
  int v704 = v703[16];
  int v705 = v703[17];
  bool v725 = v704 >= v705;
  struct StateG * v720;
  if (v725) {
    int * v706 = v702->pht;
    v706[17] = 1;
    int v708 = v702->timer;
    int v728 = v708 + 15;
    v702->timer = v728;
    int * v710 = v702->saved_regs;
    int v711 = v710[19];
    int * v712 = v702->regs;
    v712[19] = v711;
    struct StateG * v714 = slot_34(v702);
    v720 = v714;
  } else {
    int * v716 = v702->pht;
    v716[17] = 0;
    struct StateG * v718 = slot_35(v702);
    v720 = v718;
  }
  return v720;
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

struct StateG * slot_113(struct StateG * v2117) {
  int v2118 = v2117->timer;
  int v2124 = v2118 + 1;
  v2117->timer = v2124;
  int * v2120 = v2117->regs;
  v2120[1] = 44;
  struct StateG * v2122 = slot_121(v2117);
  return v2122;
}

struct StateG * slot_151(struct StateG * v2772) {
  int * v2773 = v2772->saved_regs;
  int * v2774 = v2772->regs;
  int v2775 = v2774[19];
  v2773[19] = v2775;
  int v2777 = v2772->timer;
  int v2787 = v2777 + 1;
  v2772->timer = v2787;
  int * v2779 = v2772->regs;
  v2779[19] = 1;
  struct StateG * v2781 = slot_167(v2772);
  return v2781;
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

struct StateG * slot_124(struct StateG * v2260) {
  int v2261 = v2260->timer;
  int v2267 = v2261 + 1;
  v2260->timer = v2267;
  int * v2263 = v2260->regs;
  v2263[17] = 10;
  struct StateG * v2265 = slot_132(v2260);
  return v2265;
}

struct StateG * slot_103(struct StateG * v1986) {
  int v1987 = v1986->timer;
  int v1994 = v1987 + 1;
  v1986->timer = v1994;
  int * v1989 = v1986->regs;
  int v1990 = v1989[1];
  bool v1997 = v1990 == 36;
  ret_assert(v1997);
  struct StateG * v1992 = slot_111(v1986);
  return v1992;
}

struct StateG * slot_128(struct StateG * v2312) {
  int v2313 = v2312->timer;
  int v2323 = v2313 + 1;
  v2312->timer = v2323;
  int * v2315 = v2312->pht;
  int v2316 = v2315[23];
  bool v2326 = !(v2316 == 0);
  struct StateG * v2321;
  if (v2326) {
    struct StateG * v2317 = slot_136(v2312);
    v2321 = v2317;
  } else {
    struct StateG * v2319 = slot_137(v2312);
    v2321 = v2319;
  }
  return v2321;
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

struct StateG * slot_87(struct StateG * v1796) {
  int v1797 = v1796->timer;
  int v1801 = v1797 + 1;
  v1796->timer = v1801;
  struct StateG * v1799 = slot_99(v1796);
  return v1799;
}

struct StateG * slot_67(struct StateG * v1304) {
  int * v1305 = v1304->saved_regs;
  int * v1306 = v1304->regs;
  int v1307 = v1306[18];
  v1305[18] = v1307;
  int v1309 = v1304->timer;
  int v1319 = v1309 + 1;
  v1304->timer = v1319;
  int * v1311 = v1304->regs;
  v1311[18] = 1;
  struct StateG * v1313 = slot_75(v1304);
  return v1313;
}

struct StateG * slot_81(struct StateG * v1728) {
  int v1729 = v1728->timer;
  int v1735 = v1729 + 1;
  v1728->timer = v1735;
  int * v1731 = v1728->regs;
  v1731[18] = 1;
  struct StateG * v1733 = slot_83(v1728);
  return v1733;
}

struct StateG * slot_95(struct StateG * v1880) {
  int v1881 = v1880->timer;
  int v1885 = v1881 + 1;
  v1880->timer = v1885;
  struct StateG * v1883 = slot_103(v1880);
  return v1883;
}

struct StateG * slot_115(struct StateG * v2143) {
  int v2144 = v2143->timer;
  int v2150 = v2144 + 1;
  v2143->timer = v2150;
  int * v2146 = v2143->regs;
  v2146[1] = 44;
  struct StateG * v2148 = slot_123(v2143);
  return v2148;
}

struct StateG * slot_78(struct StateG * v1642) {
  int * v1643 = v1642->regs;
  int v1644 = v1643[16];
  int v1645 = v1643[17];
  bool v1665 = v1644 < v1645;
  struct StateG * v1660;
  if (v1665) {
    int * v1646 = v1642->pht;
    v1646[0] = 1;
    struct StateG * v1648 = slot_92(v1642);
    v1660 = v1648;
  } else {
    int * v1650 = v1642->pht;
    v1650[0] = 0;
    int v1652 = v1642->timer;
    int v1673 = v1652 + 15;
    v1642->timer = v1673;
    int * v1654 = v1642->saved_regs;
    int v1655 = v1654[18];
    int * v1656 = v1642->regs;
    v1656[18] = v1655;
    struct StateG * v1658 = slot_93(v1642);
    v1660 = v1658;
  }
  return v1660;
}

struct StateG * slot_32(struct StateG * v816) {
  int v817 = v816->timer;
  int v821 = v817 + 1;
  v816->timer = v821;
  struct StateG * v819 = slot_40(v816);
  return v819;
}

struct StateG * slot_33(struct StateG * v824) {
  int v825 = v824->timer;
  int v831 = v825 + 1;
  v824->timer = v831;
  int * v827 = v824->regs;
  v827[19] = 1;
  struct StateG * v829 = slot_35(v824);
  return v829;
}

struct StateG * slot_35(struct StateG * v850) {
  int v851 = v850->timer;
  int v855 = v851 + 1;
  v850->timer = v855;
  struct StateG * v853 = slot_41(v850);
  return v853;
}

struct StateG * slot_166(struct StateG * v3346) {
  int * v3347 = v3346->regs;
  int v3348 = v3347[16];
  int v3349 = v3347[17];
  bool v3369 = v3348 >= v3349;
  struct StateG * v3364;
  if (v3369) {
    int * v3350 = v3346->pht;
    v3350[16] = 1;
    struct StateG * v3352 = slot_199(v3346);
    v3364 = v3352;
  } else {
    int * v3354 = v3346->pht;
    v3354[16] = 0;
    int v3356 = v3346->timer;
    int v3376 = v3356 + 15;
    v3346->timer = v3376;
    int * v3358 = v3346->saved_regs;
    int v3359 = v3358[19];
    int * v3360 = v3346->regs;
    v3360[19] = v3359;
    struct StateG * v3362 = slot_177(v3346);
    v3364 = v3362;
  }
  return v3364;
}

struct StateG * slot_51(struct StateG * v1047) {
  int v1048 = v1047->timer;
  int v1054 = v1048 + 1;
  v1047->timer = v1054;
  int * v1050 = v1047->regs;
  v1050[1] = 28;
  struct StateG * v1052 = slot_55(v1047);
  return v1052;
}

struct StateG * slot_52(struct StateG * v1060) {
  int v1061 = v1060->timer;
  int v1067 = v1061 + 1;
  v1060->timer = v1067;
  int * v1063 = v1060->regs;
  v1063[1] = 36;
  struct StateG * v1065 = slot_56(v1060);
  return v1065;
}

struct StateG * slot_83(struct StateG * v1754) {
  int v1755 = v1754->timer;
  int v1759 = v1755 + 1;
  v1754->timer = v1759;
  struct StateG * v1757 = slot_97(v1754);
  return v1757;
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

struct StateG * slot_123(struct StateG * v2247) {
  int v2248 = v2247->timer;
  int v2254 = v2248 + 1;
  v2247->timer = v2254;
  int * v2250 = v2247->regs;
  v2250[17] = 10;
  struct StateG * v2252 = slot_131(v2247);
  return v2252;
}

struct StateG * slot_73(struct StateG * v1444) {
  int * v1445 = v1444->regs;
  int v1446 = v1445[16];
  int v1447 = v1445[17];
  bool v1467 = v1446 < v1447;
  struct StateG * v1462;
  if (v1467) {
    int * v1448 = v1444->pht;
    v1448[3] = 1;
    int v1450 = v1444->timer;
    int v1471 = v1450 + 15;
    v1444->timer = v1471;
    int * v1452 = v1444->saved_regs;
    int v1453 = v1452[18];
    int * v1454 = v1444->regs;
    v1454[18] = v1453;
    struct StateG * v1456 = slot_82(v1444);
    v1462 = v1456;
  } else {
    int * v1458 = v1444->pht;
    v1458[3] = 0;
    struct StateG * v1460 = slot_83(v1444);
    v1462 = v1460;
  }
  return v1462;
}

struct StateG * slot_198(struct StateG * v3737) {
  int v3738 = v3737->timer;
  int v3744 = v3738 + 1;
  v3737->timer = v3744;
  int * v3740 = v3737->regs;
  v3740[19] = 2;
  struct StateG * v3742 = slot_199(v3737);
  return v3742;
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

struct StateG * slot_97(struct StateG * v1902) {
  int v1903 = v1902->timer;
  int v1910 = v1903 + 1;
  v1902->timer = v1910;
  int * v1905 = v1902->regs;
  int v1906 = v1905[1];
  bool v1913 = v1906 == 36;
  ret_assert(v1913);
  struct StateG * v1908 = slot_105(v1902);
  return v1908;
}

struct StateG * slot_38(struct StateG * v879) {
  int v880 = v879->timer;
  int v886 = v880 + 1;
  v879->timer = v886;
  int * v882 = v879->regs;
  v882[19] = 2;
  struct StateG * v884 = slot_36(v879);
  return v884;
}

struct StateG * slot_106(struct StateG * v2026) {
  int v2027 = v2026->timer;
  int v2033 = v2027 + 1;
  v2026->timer = v2033;
  int * v2029 = v2026->regs;
  v2029[1] = 36;
  struct StateG * v2031 = slot_114(v2026);
  return v2031;
}

struct StateG * slot_98(struct StateG * v1916) {
  int v1917 = v1916->timer;
  int v1924 = v1917 + 1;
  v1916->timer = v1924;
  int * v1919 = v1916->regs;
  int v1920 = v1919[1];
  bool v1927 = v1920 == 36;
  ret_assert(v1927);
  struct StateG * v1922 = slot_106(v1916);
  return v1922;
}

struct StateG * slot_159(struct StateG * v3072) {
  int * v3073 = v3072->regs;
  int v3074 = v3073[16];
  int v3075 = v3073[17];
  bool v3095 = v3074 >= v3075;
  struct StateG * v3090;
  if (v3095) {
    int * v3076 = v3072->pht;
    v3076[20] = 1;
    int v3078 = v3072->timer;
    int v3099 = v3078 + 15;
    v3072->timer = v3099;
    int * v3080 = v3072->saved_regs;
    int v3081 = v3080[19];
    int * v3082 = v3072->regs;
    v3082[19] = v3081;
    struct StateG * v3084 = slot_198(v3072);
    v3090 = v3084;
  } else {
    int * v3086 = v3072->pht;
    v3086[20] = 0;
    struct StateG * v3088 = slot_199(v3072);
    v3090 = v3088;
  }
  return v3090;
}

struct StateG * slot_46(struct StateG * v982) {
  int v983 = v982->timer;
  int v989 = v983 + 1;
  v982->timer = v989;
  int * v985 = v982->regs;
  v985[16] = 20;
  struct StateG * v987 = slot_50(v982);
  return v987;
}

struct StateG * slot_132(struct StateG * v2392) {
  int v2393 = v2392->timer;
  int v2403 = v2393 + 1;
  v2392->timer = v2403;
  int * v2395 = v2392->pht;
  int v2396 = v2395[19];
  bool v2406 = !(v2396 == 0);
  struct StateG * v2401;
  if (v2406) {
    struct StateG * v2397 = slot_144(v2392);
    v2401 = v2397;
  } else {
    struct StateG * v2399 = slot_145(v2392);
    v2401 = v2399;
  }
  return v2401;
}

struct StateG * slot_130(struct StateG * v2352) {
  int v2353 = v2352->timer;
  int v2363 = v2353 + 1;
  v2352->timer = v2363;
  int * v2355 = v2352->pht;
  int v2356 = v2355[21];
  bool v2366 = !(v2356 == 0);
  struct StateG * v2361;
  if (v2366) {
    struct StateG * v2357 = slot_140(v2352);
    v2361 = v2357;
  } else {
    struct StateG * v2359 = slot_141(v2352);
    v2361 = v2359;
  }
  return v2361;
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

struct StateG * slot_141(struct StateG * v2572) {
  int * v2573 = v2572->saved_regs;
  int * v2574 = v2572->regs;
  int v2575 = v2574[19];
  v2573[19] = v2575;
  int v2577 = v2572->timer;
  int v2587 = v2577 + 1;
  v2572->timer = v2587;
  int * v2579 = v2572->regs;
  v2579[19] = 1;
  struct StateG * v2581 = slot_157(v2572);
  return v2581;
}

struct StateG * slot_61(struct StateG * v1184) {
  int v1185 = v1184->timer;
  int v1195 = v1185 + 1;
  v1184->timer = v1195;
  int * v1187 = v1184->pht;
  int v1188 = v1187[2];
  bool v1198 = !(v1188 == 0);
  struct StateG * v1193;
  if (v1198) {
    struct StateG * v1189 = slot_66(v1184);
    v1193 = v1189;
  } else {
    struct StateG * v1191 = slot_67(v1184);
    v1193 = v1191;
  }
  return v1193;
}

struct StateG * slot_30(struct StateG * v740) {
  int * v741 = v740->regs;
  int v742 = v741[16];
  int v743 = v741[17];
  bool v763 = v742 >= v743;
  struct StateG * v758;
  if (v763) {
    int * v744 = v740->pht;
    v744[16] = 1;
    struct StateG * v746 = slot_36(v740);
    v758 = v746;
  } else {
    int * v748 = v740->pht;
    v748[16] = 0;
    int v750 = v740->timer;
    int v770 = v750 + 15;
    v740->timer = v770;
    int * v752 = v740->saved_regs;
    int v753 = v752[19];
    int * v754 = v740->regs;
    v754[19] = v753;
    struct StateG * v756 = slot_37(v740);
    v758 = v756;
  }
  return v758;
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

struct StateG * slot_43(struct StateG * v942) {
  int v943 = v942->timer;
  int v950 = v943 + 1;
  v942->timer = v950;
  int * v945 = v942->regs;
  int v946 = v945[1];
  bool v953 = v946 == 24;
  ret_assert(v953);
  struct StateG * v948 = slot_47(v942);
  return v948;
}

struct StateG * slot_70(struct StateG * v1364) {
  int * v1365 = v1364->saved_regs;
  int * v1366 = v1364->regs;
  int v1367 = v1366[18];
  v1365[18] = v1367;
  int v1369 = v1364->timer;
  int v1379 = v1369 + 1;
  v1364->timer = v1379;
  int * v1371 = v1364->regs;
  v1371[18] = 2;
  struct StateG * v1373 = slot_78(v1364);
  return v1373;
}

struct StateG * slot_76(struct StateG * v1564) {
  int * v1565 = v1564->regs;
  int v1566 = v1565[16];
  int v1567 = v1565[17];
  bool v1587 = v1566 < v1567;
  struct StateG * v1582;
  if (v1587) {
    int * v1568 = v1564->pht;
    v1568[1] = 1;
    struct StateG * v1570 = slot_88(v1564);
    v1582 = v1570;
  } else {
    int * v1572 = v1564->pht;
    v1572[1] = 0;
    int v1574 = v1564->timer;
    int v1595 = v1574 + 15;
    v1564->timer = v1595;
    int * v1576 = v1564->saved_regs;
    int v1577 = v1576[18];
    int * v1578 = v1564->regs;
    v1578[18] = v1577;
    struct StateG * v1580 = slot_89(v1564);
    v1582 = v1580;
  }
  return v1582;
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

struct StateG * slot_55(struct StateG * v1099) {
  int v1100 = v1099->timer;
  int v1106 = v1100 + 1;
  v1099->timer = v1106;
  int * v1102 = v1099->regs;
  v1102[1] = 36;
  struct StateG * v1104 = slot_59(v1099);
  return v1104;
}

struct StateG * slot_82(struct StateG * v1741) {
  int v1742 = v1741->timer;
  int v1748 = v1742 + 1;
  v1741->timer = v1748;
  int * v1744 = v1741->regs;
  v1744[18] = 2;
  struct StateG * v1746 = slot_80(v1741);
  return v1746;
}

struct StateG * slot_161(struct StateG * v3151) {
  int * v3152 = v3151->regs;
  int v3153 = v3152[16];
  int v3154 = v3152[17];
  bool v3174 = v3153 >= v3154;
  struct StateG * v3169;
  if (v3174) {
    int * v3155 = v3151->pht;
    v3155[19] = 1;
    int v3157 = v3151->timer;
    int v3178 = v3157 + 15;
    v3151->timer = v3178;
    int * v3159 = v3151->saved_regs;
    int v3160 = v3159[19];
    int * v3161 = v3151->regs;
    v3161[19] = v3160;
    struct StateG * v3163 = slot_198(v3151);
    v3169 = v3163;
  } else {
    int * v3165 = v3151->pht;
    v3165[19] = 0;
    struct StateG * v3167 = slot_199(v3151);
    v3169 = v3167;
  }
  return v3169;
}

struct StateG * slot_91(struct StateG * v1838) {
  int v1839 = v1838->timer;
  int v1843 = v1839 + 1;
  v1838->timer = v1843;
  struct StateG * v1841 = slot_101(v1838);
  return v1841;
}

struct StateG * slot_58(struct StateG * v1138) {
  int v1139 = v1138->timer;
  int v1145 = v1139 + 1;
  v1138->timer = v1145;
  int * v1141 = v1138->regs;
  v1141[17] = 10;
  struct StateG * v1143 = slot_62(v1138);
  return v1143;
}

struct StateG * slot_89(struct StateG * v1812) {
  int v1813 = v1812->timer;
  int v1819 = v1813 + 1;
  v1812->timer = v1819;
  int * v1815 = v1812->regs;
  v1815[18] = 1;
  struct StateG * v1817 = slot_91(v1812);
  return v1817;
}

struct StateG * slot_66(struct StateG * v1284) {
  int * v1285 = v1284->saved_regs;
  int * v1286 = v1284->regs;
  int v1287 = v1286[18];
  v1285[18] = v1287;
  int v1289 = v1284->timer;
  int v1299 = v1289 + 1;
  v1284->timer = v1299;
  int * v1291 = v1284->regs;
  v1291[18] = 2;
  struct StateG * v1293 = slot_74(v1284);
  return v1293;
}

struct StateG * slot_140(struct StateG * v2552) {
  int * v2553 = v2552->saved_regs;
  int * v2554 = v2552->regs;
  int v2555 = v2554[19];
  v2553[19] = v2555;
  int v2557 = v2552->timer;
  int v2567 = v2557 + 1;
  v2552->timer = v2567;
  int * v2559 = v2552->regs;
  v2559[19] = 2;
  struct StateG * v2561 = slot_156(v2552);
  return v2561;
}

struct StateG * slot_49(struct StateG * v1021) {
  int v1022 = v1021->timer;
  int v1028 = v1022 + 1;
  v1021->timer = v1028;
  int * v1024 = v1021->regs;
  v1024[1] = 28;
  struct StateG * v1026 = slot_53(v1021);
  return v1026;
}

struct StateG * slot_50(struct StateG * v1034) {
  int v1035 = v1034->timer;
  int v1041 = v1035 + 1;
  v1034->timer = v1041;
  int * v1037 = v1034->regs;
  v1037[1] = 28;
  struct StateG * v1039 = slot_54(v1034);
  return v1039;
}

struct StateG * slot_37(struct StateG * v866) {
  int v867 = v866->timer;
  int v873 = v867 + 1;
  v866->timer = v873;
  int * v869 = v866->regs;
  v869[19] = 1;
  struct StateG * v871 = slot_39(v866);
  return v871;
}

struct StateG * slot_114(struct StateG * v2130) {
  int v2131 = v2130->timer;
  int v2137 = v2131 + 1;
  v2130->timer = v2137;
  int * v2133 = v2130->regs;
  v2133[1] = 44;
  struct StateG * v2135 = slot_122(v2130);
  return v2135;
}

struct StateG * slot_135(struct StateG * v2452) {
  int v2453 = v2452->timer;
  int v2463 = v2453 + 1;
  v2452->timer = v2463;
  int * v2455 = v2452->pht;
  int v2456 = v2455[16];
  bool v2466 = !(v2456 == 0);
  struct StateG * v2461;
  if (v2466) {
    struct StateG * v2457 = slot_150(v2452);
    v2461 = v2457;
  } else {
    struct StateG * v2459 = slot_151(v2452);
    v2461 = v2459;
  }
  return v2461;
}

struct StateG * slot_59(struct StateG * v1151) {
  int v1152 = v1151->timer;
  int v1158 = v1152 + 1;
  v1151->timer = v1158;
  int * v1154 = v1151->regs;
  v1154[17] = 10;
  struct StateG * v1156 = slot_63(v1151);
  return v1156;
}

struct StateG * slot_40(struct StateG * v900) {
  int v901 = v900->timer;
  int v908 = v901 + 1;
  v900->timer = v908;
  int * v903 = v900->regs;
  int v904 = v903[1];
  bool v911 = v904 == 24;
  ret_assert(v911);
  struct StateG * v906 = slot_44(v900);
  return v906;
}

struct StateG * slot_48(struct StateG * v1008) {
  int v1009 = v1008->timer;
  int v1015 = v1009 + 1;
  v1008->timer = v1015;
  int * v1011 = v1008->regs;
  v1011[1] = 28;
  struct StateG * v1013 = slot_52(v1008);
  return v1013;
}

struct StateG * slot_77(struct StateG * v1603) {
  int * v1604 = v1603->regs;
  int v1605 = v1604[16];
  int v1606 = v1604[17];
  bool v1626 = v1605 < v1606;
  struct StateG * v1621;
  if (v1626) {
    int * v1607 = v1603->pht;
    v1607[1] = 1;
    int v1609 = v1603->timer;
    int v1629 = v1609 + 15;
    v1603->timer = v1629;
    int * v1611 = v1603->saved_regs;
    int v1612 = v1611[18];
    int * v1613 = v1603->regs;
    v1613[18] = v1612;
    struct StateG * v1615 = slot_90(v1603);
    v1621 = v1615;
  } else {
    int * v1617 = v1603->pht;
    v1617[1] = 0;
    struct StateG * v1619 = slot_91(v1603);
    v1621 = v1619;
  }
  return v1621;
}

struct StateG * slot_85(struct StateG * v1770) {
  int v1771 = v1770->timer;
  int v1777 = v1771 + 1;
  v1770->timer = v1777;
  int * v1773 = v1770->regs;
  v1773[18] = 1;
  struct StateG * v1775 = slot_87(v1770);
  return v1775;
}

struct StateG * slot_75(struct StateG * v1524) {
  int * v1525 = v1524->regs;
  int v1526 = v1525[16];
  int v1527 = v1525[17];
  bool v1547 = v1526 < v1527;
  struct StateG * v1542;
  if (v1547) {
    int * v1528 = v1524->pht;
    v1528[2] = 1;
    int v1530 = v1524->timer;
    int v1551 = v1530 + 15;
    v1524->timer = v1551;
    int * v1532 = v1524->saved_regs;
    int v1533 = v1532[18];
    int * v1534 = v1524->regs;
    v1534[18] = v1533;
    struct StateG * v1536 = slot_86(v1524);
    v1542 = v1536;
  } else {
    int * v1538 = v1524->pht;
    v1538[2] = 0;
    struct StateG * v1540 = slot_87(v1524);
    v1542 = v1540;
  }
  return v1542;
}

struct StateG * slot_72(struct StateG * v1404) {
  int * v1405 = v1404->regs;
  int v1406 = v1405[16];
  int v1407 = v1405[17];
  bool v1427 = v1406 < v1407;
  struct StateG * v1422;
  if (v1427) {
    int * v1408 = v1404->pht;
    v1408[3] = 1;
    struct StateG * v1410 = slot_80(v1404);
    v1422 = v1410;
  } else {
    int * v1412 = v1404->pht;
    v1412[3] = 0;
    int v1414 = v1404->timer;
    int v1436 = v1414 + 15;
    v1404->timer = v1436;
    int * v1416 = v1404->saved_regs;
    int v1417 = v1416[18];
    int * v1418 = v1404->regs;
    v1418[18] = v1417;
    struct StateG * v1420 = slot_81(v1404);
    v1422 = v1420;
  }
  return v1422;
}

struct StateG * slot_119(struct StateG * v2195) {
  int v2196 = v2195->timer;
  int v2202 = v2196 + 1;
  v2195->timer = v2202;
  int * v2198 = v2195->regs;
  v2198[1] = 44;
  struct StateG * v2200 = slot_127(v2195);
  return v2200;
}

struct StateG * slot_71(struct StateG * v1384) {
  int * v1385 = v1384->saved_regs;
  int * v1386 = v1384->regs;
  int v1387 = v1386[18];
  v1385[18] = v1387;
  int v1389 = v1384->timer;
  int v1399 = v1389 + 1;
  v1384->timer = v1399;
  int * v1391 = v1384->regs;
  v1391[18] = 1;
  struct StateG * v1393 = slot_79(v1384);
  return v1393;
}

struct StateG * slot_101(struct StateG * v1958) {
  int v1959 = v1958->timer;
  int v1966 = v1959 + 1;
  v1958->timer = v1966;
  int * v1961 = v1958->regs;
  int v1962 = v1961[1];
  bool v1969 = v1962 == 36;
  ret_assert(v1969);
  struct StateG * v1964 = slot_109(v1958);
  return v1964;
}

struct StateG * slot_108(struct StateG * v2052) {
  int v2053 = v2052->timer;
  int v2059 = v2053 + 1;
  v2052->timer = v2059;
  int * v2055 = v2052->regs;
  v2055[1] = 36;
  struct StateG * v2057 = slot_116(v2052);
  return v2057;
}

struct StateG * slot_116(struct StateG * v2156) {
  int v2157 = v2156->timer;
  int v2163 = v2157 + 1;
  v2156->timer = v2163;
  int * v2159 = v2156->regs;
  v2159[1] = 44;
  struct StateG * v2161 = slot_124(v2156);
  return v2161;
}

struct StateG * slot_93(struct StateG * v1854) {
  int v1855 = v1854->timer;
  int v1861 = v1855 + 1;
  v1854->timer = v1861;
  int * v1857 = v1854->regs;
  v1857[18] = 1;
  struct StateG * v1859 = slot_95(v1854);
  return v1859;
}

struct StateG * slot_88(struct StateG * v1804) {
  int v1805 = v1804->timer;
  int v1809 = v1805 + 1;
  v1804->timer = v1809;
  struct StateG * v1807 = slot_100(v1804);
  return v1807;
}

struct StateG * slot_96(struct StateG * v1888) {
  int v1889 = v1888->timer;
  int v1896 = v1889 + 1;
  v1888->timer = v1896;
  int * v1891 = v1888->regs;
  int v1892 = v1891[1];
  bool v1899 = v1892 == 36;
  ret_assert(v1899);
  struct StateG * v1894 = slot_104(v1888);
  return v1894;
}

struct StateG * slot_45(struct StateG * v969) {
  int v970 = v969->timer;
  int v976 = v970 + 1;
  v969->timer = v976;
  int * v972 = v969->regs;
  v972[16] = 20;
  struct StateG * v974 = slot_49(v969);
  return v974;
}

struct StateG * slot_134(struct StateG * v2432) {
  int v2433 = v2432->timer;
  int v2443 = v2433 + 1;
  v2432->timer = v2443;
  int * v2435 = v2432->pht;
  int v2436 = v2435[17];
  bool v2446 = !(v2436 == 0);
  struct StateG * v2441;
  if (v2446) {
    struct StateG * v2437 = slot_148(v2432);
    v2441 = v2437;
  } else {
    struct StateG * v2439 = slot_149(v2432);
    v2441 = v2439;
  }
  return v2441;
}

struct StateG * slot_69(struct StateG * v1344) {
  int * v1345 = v1344->saved_regs;
  int * v1346 = v1344->regs;
  int v1347 = v1346[18];
  v1345[18] = v1347;
  int v1349 = v1344->timer;
  int v1359 = v1349 + 1;
  v1344->timer = v1359;
  int * v1351 = v1344->regs;
  v1351[18] = 1;
  struct StateG * v1353 = slot_77(v1344);
  return v1353;
}

struct StateG * slot_138(struct StateG * v2512) {
  int * v2513 = v2512->saved_regs;
  int * v2514 = v2512->regs;
  int v2515 = v2514[19];
  v2513[19] = v2515;
  int v2517 = v2512->timer;
  int v2527 = v2517 + 1;
  v2512->timer = v2527;
  int * v2519 = v2512->regs;
  v2519[19] = 2;
  struct StateG * v2521 = slot_154(v2512);
  return v2521;
}

struct StateG * slot_102(struct StateG * v1972) {
  int v1973 = v1972->timer;
  int v1980 = v1973 + 1;
  v1972->timer = v1980;
  int * v1975 = v1972->regs;
  int v1976 = v1975[1];
  bool v1983 = v1976 == 36;
  ret_assert(v1983);
  struct StateG * v1978 = slot_110(v1972);
  return v1978;
}

struct StateG * slot_145(struct StateG * v2652) {
  int * v2653 = v2652->saved_regs;
  int * v2654 = v2652->regs;
  int v2655 = v2654[19];
  v2653[19] = v2655;
  int v2657 = v2652->timer;
  int v2667 = v2657 + 1;
  v2652->timer = v2667;
  int * v2659 = v2652->regs;
  v2659[19] = 1;
  struct StateG * v2661 = slot_161(v2652);
  return v2661;
}

struct StateG * slot_110(struct StateG * v2078) {
  int v2079 = v2078->timer;
  int v2085 = v2079 + 1;
  v2078->timer = v2085;
  int * v2081 = v2078->regs;
  v2081[1] = 36;
  struct StateG * v2083 = slot_118(v2078);
  return v2083;
}

struct StateG * slot_131(struct StateG * v2372) {
  int v2373 = v2372->timer;
  int v2383 = v2373 + 1;
  v2372->timer = v2383;
  int * v2375 = v2372->pht;
  int v2376 = v2375[20];
  bool v2386 = !(v2376 == 0);
  struct StateG * v2381;
  if (v2386) {
    struct StateG * v2377 = slot_142(v2372);
    v2381 = v2377;
  } else {
    struct StateG * v2379 = slot_143(v2372);
    v2381 = v2379;
  }
  return v2381;
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

struct StateG * slot_157(struct StateG * v2992) {
  int * v2993 = v2992->regs;
  int v2994 = v2993[16];
  int v2995 = v2993[17];
  bool v3015 = v2994 >= v2995;
  struct StateG * v3010;
  if (v3015) {
    int * v2996 = v2992->pht;
    v2996[21] = 1;
    int v2998 = v2992->timer;
    int v3019 = v2998 + 15;
    v2992->timer = v3019;
    int * v3000 = v2992->saved_regs;
    int v3001 = v3000[19];
    int * v3002 = v2992->regs;
    v3002[19] = v3001;
    struct StateG * v3004 = slot_198(v2992);
    v3010 = v3004;
  } else {
    int * v3006 = v2992->pht;
    v3006[21] = 0;
    struct StateG * v3008 = slot_199(v2992);
    v3010 = v3008;
  }
  return v3010;
}

struct StateG * slot_149(struct StateG * v2732) {
  int * v2733 = v2732->saved_regs;
  int * v2734 = v2732->regs;
  int v2735 = v2734[19];
  v2733[19] = v2735;
  int v2737 = v2732->timer;
  int v2747 = v2737 + 1;
  v2732->timer = v2747;
  int * v2739 = v2732->regs;
  v2739[19] = 1;
  struct StateG * v2741 = slot_165(v2732);
  return v2741;
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

struct StateG * slot_104(struct StateG * v2000) {
  int v2001 = v2000->timer;
  int v2007 = v2001 + 1;
  v2000->timer = v2007;
  int * v2003 = v2000->regs;
  v2003[1] = 36;
  struct StateG * v2005 = slot_112(v2000);
  return v2005;
}

struct StateG * slot_54(struct StateG * v1086) {
  int v1087 = v1086->timer;
  int v1093 = v1087 + 1;
  v1086->timer = v1093;
  int * v1089 = v1086->regs;
  v1089[1] = 36;
  struct StateG * v1091 = slot_58(v1086);
  return v1091;
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

struct StateG * slot_64(struct StateG * v1244) {
  int * v1245 = v1244->saved_regs;
  int * v1246 = v1244->regs;
  int v1247 = v1246[18];
  v1245[18] = v1247;
  int v1249 = v1244->timer;
  int v1259 = v1249 + 1;
  v1244->timer = v1259;
  int * v1251 = v1244->regs;
  v1251[18] = 2;
  struct StateG * v1253 = slot_72(v1244);
  return v1253;
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

struct StateG * slot_53(struct StateG * v1073) {
  int v1074 = v1073->timer;
  int v1080 = v1074 + 1;
  v1073->timer = v1080;
  int * v1076 = v1073->regs;
  v1076[1] = 36;
  struct StateG * v1078 = slot_57(v1073);
  return v1078;
}

struct StateG * slot_80(struct StateG * v1720) {
  int v1721 = v1720->timer;
  int v1725 = v1721 + 1;
  v1720->timer = v1725;
  struct StateG * v1723 = slot_96(v1720);
  return v1723;
}

struct StateG * slot_44(struct StateG * v956) {
  int v957 = v956->timer;
  int v963 = v957 + 1;
  v956->timer = v963;
  int * v959 = v956->regs;
  v959[16] = 20;
  struct StateG * v961 = slot_48(v956);
  return v961;
}

struct StateG * slot_137(struct StateG * v2492) {
  int * v2493 = v2492->saved_regs;
  int * v2494 = v2492->regs;
  int v2495 = v2494[19];
  v2493[19] = v2495;
  int v2497 = v2492->timer;
  int v2507 = v2497 + 1;
  v2492->timer = v2507;
  int * v2499 = v2492->regs;
  v2499[19] = 1;
  struct StateG * v2501 = slot_153(v2492);
  return v2501;
}

struct StateG * slot_122(struct StateG * v2234) {
  int v2235 = v2234->timer;
  int v2241 = v2235 + 1;
  v2234->timer = v2241;
  int * v2237 = v2234->regs;
  v2237[17] = 10;
  struct StateG * v2239 = slot_130(v2234);
  return v2239;
}

struct StateG * slot_99(struct StateG * v1930) {
  int v1931 = v1930->timer;
  int v1938 = v1931 + 1;
  v1930->timer = v1938;
  int * v1933 = v1930->regs;
  int v1934 = v1933[1];
  bool v1941 = v1934 == 36;
  ret_assert(v1941);
  struct StateG * v1936 = slot_107(v1930);
  return v1936;
}

struct StateG * slot_36(struct StateG * v858) {
  int v859 = v858->timer;
  int v863 = v859 + 1;
  v858->timer = v863;
  struct StateG * v861 = slot_42(v858);
  return v861;
}

struct StateG * slot_57(struct StateG * v1125) {
  int v1126 = v1125->timer;
  int v1132 = v1126 + 1;
  v1125->timer = v1132;
  int * v1128 = v1125->regs;
  v1128[17] = 10;
  struct StateG * v1130 = slot_61(v1125);
  return v1130;
}

struct StateG * slot_62(struct StateG * v1204) {
  int v1205 = v1204->timer;
  int v1215 = v1205 + 1;
  v1204->timer = v1215;
  int * v1207 = v1204->pht;
  int v1208 = v1207[1];
  bool v1218 = !(v1208 == 0);
  struct StateG * v1213;
  if (v1218) {
    struct StateG * v1209 = slot_68(v1204);
    v1213 = v1209;
  } else {
    struct StateG * v1211 = slot_69(v1204);
    v1213 = v1211;
  }
  return v1213;
}

struct StateG * slot_22(struct StateG * v544) {
  int v545 = v544->timer;
  int v555 = v545 + 1;
  v544->timer = v555;
  int * v547 = v544->pht;
  int v548 = v547[17];
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

struct StateG * slot_139(struct StateG * v2532) {
  int * v2533 = v2532->saved_regs;
  int * v2534 = v2532->regs;
  int v2535 = v2534[19];
  v2533[19] = v2535;
  int v2537 = v2532->timer;
  int v2547 = v2537 + 1;
  v2532->timer = v2547;
  int * v2539 = v2532->regs;
  v2539[19] = 1;
  struct StateG * v2541 = slot_155(v2532);
  return v2541;
}

struct StateG * slot_23(struct StateG * v564) {
  int v565 = v564->timer;
  int v575 = v565 + 1;
  v564->timer = v575;
  int * v567 = v564->pht;
  int v568 = v567[16];
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

struct StateG * slot_153(struct StateG * v2832) {
  int * v2833 = v2832->regs;
  int v2834 = v2833[16];
  int v2835 = v2833[17];
  bool v2855 = v2834 >= v2835;
  struct StateG * v2850;
  if (v2855) {
    int * v2836 = v2832->pht;
    v2836[23] = 1;
    int v2838 = v2832->timer;
    int v2859 = v2838 + 15;
    v2832->timer = v2859;
    int * v2840 = v2832->saved_regs;
    int v2841 = v2840[19];
    int * v2842 = v2832->regs;
    v2842[19] = v2841;
    struct StateG * v2844 = slot_198(v2832);
    v2850 = v2844;
  } else {
    int * v2846 = v2832->pht;
    v2846[23] = 0;
    struct StateG * v2848 = slot_199(v2832);
    v2850 = v2848;
  }
  return v2850;
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

struct StateG * slot_86(struct StateG * v1783) {
  int v1784 = v1783->timer;
  int v1790 = v1784 + 1;
  v1783->timer = v1790;
  int * v1786 = v1783->regs;
  v1786[18] = 2;
  struct StateG * v1788 = slot_84(v1783);
  return v1788;
}

struct StateG * slot_129(struct StateG * v2332) {
  int v2333 = v2332->timer;
  int v2343 = v2333 + 1;
  v2332->timer = v2343;
  int * v2335 = v2332->pht;
  int v2336 = v2335[22];
  bool v2346 = !(v2336 == 0);
  struct StateG * v2341;
  if (v2346) {
    struct StateG * v2337 = slot_138(v2332);
    v2341 = v2337;
  } else {
    struct StateG * v2339 = slot_139(v2332);
    v2341 = v2339;
  }
  return v2341;
}

struct StateG * slot_158(struct StateG * v3032) {
  int * v3033 = v3032->regs;
  int v3034 = v3033[16];
  int v3035 = v3033[17];
  bool v3055 = v3034 >= v3035;
  struct StateG * v3050;
  if (v3055) {
    int * v3036 = v3032->pht;
    v3036[20] = 1;
    struct StateG * v3038 = slot_199(v3032);
    v3050 = v3038;
  } else {
    int * v3040 = v3032->pht;
    v3040[20] = 0;
    int v3042 = v3032->timer;
    int v3064 = v3042 + 15;
    v3032->timer = v3064;
    int * v3044 = v3032->saved_regs;
    int v3045 = v3044[19];
    int * v3046 = v3032->regs;
    v3046[19] = v3045;
    struct StateG * v3048 = slot_177(v3032);
    v3050 = v3048;
  }
  return v3050;
}

struct StateG * slot_100(struct StateG * v1944) {
  int v1945 = v1944->timer;
  int v1952 = v1945 + 1;
  v1944->timer = v1952;
  int * v1947 = v1944->regs;
  int v1948 = v1947[1];
  bool v1955 = v1948 == 36;
  ret_assert(v1955);
  struct StateG * v1950 = slot_108(v1944);
  return v1950;
}

struct StateG * slot_127(struct StateG * v2299) {
  int v2300 = v2299->timer;
  int v2306 = v2300 + 1;
  v2299->timer = v2306;
  int * v2302 = v2299->regs;
  v2302[17] = 10;
  struct StateG * v2304 = slot_135(v2299);
  return v2304;
}

struct StateG * slot_13(struct StateG * v430) {
  int v431 = v430->timer;
  int v435 = v431 + 1;
  v430->timer = v435;
  struct StateG * v433 = slot_15(v430);
  return v433;
}

struct StateG * slot_111(struct StateG * v2091) {
  int v2092 = v2091->timer;
  int v2098 = v2092 + 1;
  v2091->timer = v2098;
  int * v2094 = v2091->regs;
  v2094[1] = 36;
  struct StateG * v2096 = slot_119(v2091);
  return v2096;
}

struct StateG * slot_109(struct StateG * v2065) {
  int v2066 = v2065->timer;
  int v2072 = v2066 + 1;
  v2065->timer = v2072;
  int * v2068 = v2065->regs;
  v2068[1] = 36;
  struct StateG * v2070 = slot_117(v2065);
  return v2070;
}

struct StateG * slot_147(struct StateG * v2692) {
  int * v2693 = v2692->saved_regs;
  int * v2694 = v2692->regs;
  int v2695 = v2694[19];
  v2693[19] = v2695;
  int v2697 = v2692->timer;
  int v2707 = v2697 + 1;
  v2692->timer = v2707;
  int * v2699 = v2692->regs;
  v2699[19] = 1;
  struct StateG * v2701 = slot_163(v2692);
  return v2701;
}

struct StateG * slot_42(struct StateG * v928) {
  int v929 = v928->timer;
  int v936 = v929 + 1;
  v928->timer = v936;
  int * v931 = v928->regs;
  int v932 = v931[1];
  bool v939 = v932 == 24;
  ret_assert(v939);
  struct StateG * v934 = slot_46(v928);
  return v934;
}

struct StateG * slot_163(struct StateG * v3230) {
  int * v3231 = v3230->regs;
  int v3232 = v3231[16];
  int v3233 = v3231[17];
  bool v3253 = v3232 >= v3233;
  struct StateG * v3248;
  if (v3253) {
    int * v3234 = v3230->pht;
    v3234[18] = 1;
    int v3236 = v3230->timer;
    int v3257 = v3236 + 15;
    v3230->timer = v3257;
    int * v3238 = v3230->saved_regs;
    int v3239 = v3238[19];
    int * v3240 = v3230->regs;
    v3240[19] = v3239;
    struct StateG * v3242 = slot_198(v3230);
    v3248 = v3242;
  } else {
    int * v3244 = v3230->pht;
    v3244[18] = 0;
    struct StateG * v3246 = slot_199(v3230);
    v3248 = v3246;
  }
  return v3248;
}

struct StateG * slot_165(struct StateG * v3308) {
  int * v3309 = v3308->regs;
  int v3310 = v3309[16];
  int v3311 = v3309[17];
  bool v3331 = v3310 >= v3311;
  struct StateG * v3326;
  if (v3331) {
    int * v3312 = v3308->pht;
    v3312[17] = 1;
    int v3314 = v3308->timer;
    int v3334 = v3314 + 15;
    v3308->timer = v3334;
    int * v3316 = v3308->saved_regs;
    int v3317 = v3316[19];
    int * v3318 = v3308->regs;
    v3318[19] = v3317;
    struct StateG * v3320 = slot_198(v3308);
    v3326 = v3320;
  } else {
    int * v3322 = v3308->pht;
    v3322[17] = 0;
    struct StateG * v3324 = slot_199(v3308);
    v3326 = v3324;
  }
  return v3326;
}

struct StateG * snippet(struct StateG * v0) {
  struct StateG * v1 = slot_0(v0);
  return v1;
}

struct StateG * slot_117(struct StateG * v2169) {
  int v2170 = v2169->timer;
  int v2176 = v2170 + 1;
  v2169->timer = v2176;
  int * v2172 = v2169->regs;
  v2172[1] = 44;
  struct StateG * v2174 = slot_125(v2169);
  return v2174;
}

struct StateG * slot_90(struct StateG * v1825) {
  int v1826 = v1825->timer;
  int v1832 = v1826 + 1;
  v1825->timer = v1832;
  int * v1828 = v1825->regs;
  v1828[18] = 2;
  struct StateG * v1830 = slot_88(v1825);
  return v1830;
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