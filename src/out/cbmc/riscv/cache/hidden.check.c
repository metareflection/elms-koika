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

struct StateT * slot_12(struct StateT * v727);
struct StateT * slot_143(struct StateT * v2561);
struct StateT * slot_120(struct StateT * v2239);
struct StateT * slot_167(struct StateT * v2897);
struct StateT * slot_152(struct StateT * v2687);
struct StateT * slot_199(struct StateT * v3345);
struct StateT * slot_92(struct StateT * v1847);
struct StateT * slot_31(struct StateT * v993);
struct StateT * slot_160(struct StateT * v2799);
struct StateT * slot_65(struct StateT * v1469);
struct StateT * slot_10(struct StateT * v699);
struct StateT * slot_150(struct StateT * v2659);
struct StateT * slot_74(struct StateT * v1595);
struct StateT * slot_107(struct StateT * v2057);
struct StateT * slot_136(struct StateT * v2463);
struct StateT * slot_84(struct StateT * v1735);
struct StateT * slot_28(struct StateT * v951);
struct StateT * slot_155(struct StateT * v2729);
struct StateT * slot_177(struct StateT * v3037);
struct StateT * slot_17(struct StateT * v797);
struct StateT * slot_181(struct StateT * v3093);
struct StateT * slot_197(struct StateT * v3317);
struct StateT * slot_207(struct StateT * v3457);
struct StateT * slot_156(struct StateT * v2743);
struct StateT * slot_154(struct StateT * v2715);
struct StateT * slot_68(struct StateT * v1511);
struct StateT * slot_105(struct StateT * v2029);
struct StateT * slot_27(struct StateT * v937);
struct StateT * slot_164(struct StateT * v2855);
struct StateT * slot_15(struct StateT * v769);
struct StateT * slot_133(struct StateT * v2421);
struct StateT * slot_56(struct StateT * v1343);
struct StateT * slot_222(struct StateT * v3667);
struct StateT * slot_34(struct StateT * v1035);
struct StateT * slot_171(struct StateT * v2953);
struct StateT * slot_162(struct StateT * v2827);
struct StateT * slot_21(struct StateT * v853);
struct StateT * slot_118(struct StateT * v2211);
struct StateT * slot_121(struct StateT * v2253);
struct StateT * slot_144(struct StateT * v2575);
struct StateT * slot_201(struct StateT * v3373);
struct StateT * slot_94(struct StateT * v1875);
struct StateT * slot_63(struct StateT * v1441);
struct StateT * slot_146(struct StateT * v2603);
struct StateT * slot_24(struct StateT * v895);
struct StateT * slot_0(struct StateT * v2);
struct StateT * slot_195(struct StateT * v3289);
struct StateT * slot_125(struct StateT * v2309);
struct StateT * slot_148(struct StateT * v2631);
struct StateT * slot_126(struct StateT * v2323);
struct StateT * slot_223(struct StateT * v3681);
struct StateT * slot_79(struct StateT * v1665);
struct StateT * slot_41(struct StateT * v1133);
struct StateT * slot_39(struct StateT * v1105);
struct StateT * slot_142(struct StateT * v2547);
struct StateT * slot_60(struct StateT * v1399);
struct StateT * slot_112(struct StateT * v2127);
struct StateT * slot_47(struct StateT * v1217);
struct StateT * slot_214(struct StateT * v3555);
struct StateT * slot_29(struct StateT * v965);
struct StateT * slot_16(struct StateT * v783);
struct StateT * slot_113(struct StateT * v2141);
struct StateT * slot_151(struct StateT * v2673);
struct StateT * slot_7(struct StateT * v657);
struct StateT * slot_124(struct StateT * v2295);
struct StateT * slot_191(struct StateT * v3233);
struct StateT * slot_103(struct StateT * v2001);
struct StateT * slot_128(struct StateT * v2351);
struct StateT * slot_19(struct StateT * v825);
struct StateT * slot_87(struct StateT * v1777);
struct StateT * slot_67(struct StateT * v1497);
struct StateT * slot_81(struct StateT * v1693);
struct StateT * slot_95(struct StateT * v1889);
struct StateT * slot_115(struct StateT * v2169);
struct StateT * slot_78(struct StateT * v1651);
struct StateT * slot_32(struct StateT * v1007);
struct StateT * slot_205(struct StateT * v3429);
struct StateT * slot_193(struct StateT * v3261);
struct StateT * slot_176(struct StateT * v3023);
struct StateT * slot_189(struct StateT * v3205);
struct StateT * slot_33(struct StateT * v1021);
struct StateT * slot_35(struct StateT * v1049);
struct StateT * slot_210(struct StateT * v3499);
struct StateT * slot_166(struct StateT * v2883);
struct StateT * slot_51(struct StateT * v1273);
struct StateT * slot_52(struct StateT * v1287);
struct StateT * slot_83(struct StateT * v1721);
struct StateT * slot_25(struct StateT * v909);
struct StateT * slot_209(struct StateT * v3485);
struct StateT * slot_3(struct StateT * v412);
struct StateT * slot_123(struct StateT * v2281);
struct StateT * slot_73(struct StateT * v1581);
struct StateT * slot_198(struct StateT * v3331);
struct StateT * slot_1(struct StateT * v206);
struct StateT * slot_187(struct StateT * v3177);
struct StateT * slot_97(struct StateT * v1917);
struct StateT * slot_182(struct StateT * v3107);
struct StateT * slot_38(struct StateT * v1091);
struct StateT * slot_178(struct StateT * v3051);
struct StateT * slot_106(struct StateT * v2043);
struct StateT * slot_98(struct StateT * v1931);
struct StateT * slot_159(struct StateT * v2785);
struct StateT * slot_46(struct StateT * v1203);
struct StateT * slot_212(struct StateT * v3527);
struct StateT * slot_132(struct StateT * v2407);
struct StateT * slot_130(struct StateT * v2379);
struct StateT * slot_211(struct StateT * v3513);
struct StateT * slot_20(struct StateT * v839);
struct StateT * slot_141(struct StateT * v2533);
struct StateT * slot_61(struct StateT * v1413);
struct StateT * slot_30(struct StateT * v979);
struct StateT * slot_4(struct StateT * v426);
struct StateT * slot_18(struct StateT * v811);
struct StateT * slot_9(struct StateT * v685);
struct StateT * slot_183(struct StateT * v3121);
struct StateT * slot_43(struct StateT * v1161);
struct StateT * slot_70(struct StateT * v1539);
struct StateT * slot_168(struct StateT * v2911);
struct StateT * slot_76(struct StateT * v1623);
struct StateT * slot_6(struct StateT * v643);
struct StateT * slot_225(struct StateT * v3709);
struct StateT * slot_55(struct StateT * v1329);
struct StateT * slot_213(struct StateT * v3541);
struct StateT * slot_82(struct StateT * v1707);
struct StateT * slot_161(struct StateT * v2813);
struct StateT * slot_185(struct StateT * v3149);
struct StateT * slot_91(struct StateT * v1833);
struct StateT * slot_58(struct StateT * v1371);
struct StateT * slot_89(struct StateT * v1805);
struct StateT * slot_66(struct StateT * v1483);
struct StateT * slot_140(struct StateT * v2519);
struct StateT * slot_49(struct StateT * v1245);
struct StateT * slot_216(struct StateT * v3583);
struct StateT * slot_50(struct StateT * v1259);
struct StateT * slot_37(struct StateT * v1077);
struct StateT * slot_114(struct StateT * v2155);
struct StateT * slot_135(struct StateT * v2449);
struct StateT * slot_59(struct StateT * v1385);
struct StateT * slot_192(struct StateT * v3247);
struct StateT * slot_40(struct StateT * v1119);
struct StateT * slot_48(struct StateT * v1231);
struct StateT * slot_77(struct StateT * v1637);
struct StateT * slot_85(struct StateT * v1749);
struct StateT * slot_75(struct StateT * v1609);
struct StateT * slot_72(struct StateT * v1567);
struct StateT * slot_119(struct StateT * v2225);
struct StateT * slot_71(struct StateT * v1553);
struct StateT * slot_101(struct StateT * v1973);
struct StateT * slot_108(struct StateT * v2071);
struct StateT * slot_116(struct StateT * v2183);
struct StateT * slot_93(struct StateT * v1861);
struct StateT * slot_88(struct StateT * v1791);
struct StateT * slot_96(struct StateT * v1903);
struct StateT * slot_215(struct StateT * v3569);
struct StateT * slot_45(struct StateT * v1189);
struct StateT * slot_218(struct StateT * v3611);
struct StateT * slot_220(struct StateT * v3639);
struct StateT * slot_134(struct StateT * v2435);
struct StateT * slot_175(struct StateT * v3009);
struct StateT * slot_69(struct StateT * v1525);
struct StateT * slot_202(struct StateT * v3387);
struct StateT * slot_188(struct StateT * v3191);
struct StateT * slot_138(struct StateT * v2491);
struct StateT * slot_186(struct StateT * v3163);
struct StateT * slot_102(struct StateT * v1987);
struct StateT * slot_145(struct StateT * v2589);
struct StateT * slot_110(struct StateT * v2099);
struct StateT * slot_196(struct StateT * v3303);
struct StateT * slot_208(struct StateT * v3471);
struct StateT * slot_172(struct StateT * v2967);
struct StateT * slot_131(struct StateT * v2393);
struct StateT * slot_8(struct StateT * v671);
struct StateT * slot_180(struct StateT * v3079);
struct StateT * slot_203(struct StateT * v3401);
struct StateT * slot_190(struct StateT * v3219);
struct StateT * slot_157(struct StateT * v2757);
struct StateT * slot_200(struct StateT * v3359);
struct StateT * slot_173(struct StateT * v2981);
struct StateT * slot_149(struct StateT * v2645);
struct StateT * slot_5(struct StateT * v630);
struct StateT * slot_104(struct StateT * v2015);
struct StateT * slot_54(struct StateT * v1315);
struct StateT * slot_26(struct StateT * v923);
struct StateT * slot_206(struct StateT * v3443);
struct StateT * slot_169(struct StateT * v2925);
struct StateT * slot_64(struct StateT * v1455);
struct StateT * slot_170(struct StateT * v2939);
struct StateT * slot_14(struct StateT * v755);
struct StateT * slot_53(struct StateT * v1301);
struct StateT * slot_80(struct StateT * v1679);
struct StateT * slot_44(struct StateT * v1175);
struct StateT * slot_137(struct StateT * v2477);
struct StateT * slot_122(struct StateT * v2267);
struct StateT * slot_99(struct StateT * v1945);
struct StateT * slot_179(struct StateT * v3065);
struct StateT * slot_219(struct StateT * v3625);
struct StateT * slot_36(struct StateT * v1063);
struct StateT * slot_57(struct StateT * v1357);
struct StateT * slot_62(struct StateT * v1427);
struct StateT * slot_22(struct StateT * v867);
struct StateT * slot_139(struct StateT * v2505);
struct StateT * slot_221(struct StateT * v3653);
struct StateT * slot_23(struct StateT * v881);
struct StateT * slot_153(struct StateT * v2701);
struct StateT * slot_2(struct StateT * v398);
struct StateT * slot_86(struct StateT * v1763);
struct StateT * slot_129(struct StateT * v2365);
struct StateT * slot_158(struct StateT * v2771);
struct StateT * slot_100(struct StateT * v1959);
struct StateT * slot_127(struct StateT * v2337);
struct StateT * slot_217(struct StateT * v3597);
struct StateT * slot_13(struct StateT * v741);
struct StateT * slot_111(struct StateT * v2113);
struct StateT * slot_109(struct StateT * v2085);
struct StateT * slot_174(struct StateT * v2995);
struct StateT * slot_147(struct StateT * v2617);
struct StateT * slot_42(struct StateT * v1147);
struct StateT * slot_224(struct StateT * v3695);
struct StateT * slot_163(struct StateT * v2841);
struct StateT * slot_184(struct StateT * v3135);
struct StateT * slot_204(struct StateT * v3415);
struct StateT * slot_194(struct StateT * v3275);
struct StateT * slot_165(struct StateT * v2869);
struct StateT * snippet(struct StateT * v0);
struct StateT * slot_117(struct StateT * v2197);
struct StateT * slot_90(struct StateT * v1819);
struct StateT * slot_11(struct StateT * v713);
struct StateT * slot_12(struct StateT * v727) {
  int v728 = v727->timer;
  int v735 = v728 + 1;
  v727->timer = v735;
  int * v730 = v727->regs;
  int v731 = v730[8];
  int v738 = v731 + 1;
  v730[8] = v738;
  struct StateT * v733 = slot_13(v727);
  return v733;
}

struct StateT * slot_143(struct StateT * v2561) {
  int v2562 = v2561->timer;
  int v2569 = v2562 + 1;
  v2561->timer = v2569;
  int * v2564 = v2561->regs;
  int v2565 = v2564[8];
  int v2572 = v2565 + 1;
  v2564[8] = v2572;
  struct StateT * v2567 = slot_144(v2561);
  return v2567;
}

struct StateT * slot_120(struct StateT * v2239) {
  int v2240 = v2239->timer;
  int v2247 = v2240 + 1;
  v2239->timer = v2247;
  int * v2242 = v2239->regs;
  int v2243 = v2242[8];
  int v2250 = v2243 + 1;
  v2242[8] = v2250;
  struct StateT * v2245 = slot_121(v2239);
  return v2245;
}

struct StateT * slot_167(struct StateT * v2897) {
  int v2898 = v2897->timer;
  int v2905 = v2898 + 1;
  v2897->timer = v2905;
  int * v2900 = v2897->regs;
  int v2901 = v2900[8];
  int v2908 = v2901 + 1;
  v2900[8] = v2908;
  struct StateT * v2903 = slot_168(v2897);
  return v2903;
}

struct StateT * slot_152(struct StateT * v2687) {
  int v2688 = v2687->timer;
  int v2695 = v2688 + 1;
  v2687->timer = v2695;
  int * v2690 = v2687->regs;
  int v2691 = v2690[8];
  int v2698 = v2691 + 1;
  v2690[8] = v2698;
  struct StateT * v2693 = slot_153(v2687);
  return v2693;
}

struct StateT * slot_199(struct StateT * v3345) {
  int v3346 = v3345->timer;
  int v3353 = v3346 + 1;
  v3345->timer = v3353;
  int * v3348 = v3345->regs;
  int v3349 = v3348[8];
  int v3356 = v3349 + 1;
  v3348[8] = v3356;
  struct StateT * v3351 = slot_200(v3345);
  return v3351;
}

struct StateT * slot_92(struct StateT * v1847) {
  int v1848 = v1847->timer;
  int v1855 = v1848 + 1;
  v1847->timer = v1855;
  int * v1850 = v1847->regs;
  int v1851 = v1850[8];
  int v1858 = v1851 + 1;
  v1850[8] = v1858;
  struct StateT * v1853 = slot_93(v1847);
  return v1853;
}

struct StateT * slot_31(struct StateT * v993) {
  int v994 = v993->timer;
  int v1001 = v994 + 1;
  v993->timer = v1001;
  int * v996 = v993->regs;
  int v997 = v996[8];
  int v1004 = v997 + 1;
  v996[8] = v1004;
  struct StateT * v999 = slot_32(v993);
  return v999;
}

struct StateT * slot_160(struct StateT * v2799) {
  int v2800 = v2799->timer;
  int v2807 = v2800 + 1;
  v2799->timer = v2807;
  int * v2802 = v2799->regs;
  int v2803 = v2802[8];
  int v2810 = v2803 + 1;
  v2802[8] = v2810;
  struct StateT * v2805 = slot_161(v2799);
  return v2805;
}

struct StateT * slot_65(struct StateT * v1469) {
  int v1470 = v1469->timer;
  int v1477 = v1470 + 1;
  v1469->timer = v1477;
  int * v1472 = v1469->regs;
  int v1473 = v1472[8];
  int v1480 = v1473 + 1;
  v1472[8] = v1480;
  struct StateT * v1475 = slot_66(v1469);
  return v1475;
}

struct StateT * slot_10(struct StateT * v699) {
  int v700 = v699->timer;
  int v707 = v700 + 1;
  v699->timer = v707;
  int * v702 = v699->regs;
  int v703 = v702[8];
  int v710 = v703 + 1;
  v702[8] = v710;
  struct StateT * v705 = slot_11(v699);
  return v705;
}

struct StateT * slot_150(struct StateT * v2659) {
  int v2660 = v2659->timer;
  int v2667 = v2660 + 1;
  v2659->timer = v2667;
  int * v2662 = v2659->regs;
  int v2663 = v2662[8];
  int v2670 = v2663 + 1;
  v2662[8] = v2670;
  struct StateT * v2665 = slot_151(v2659);
  return v2665;
}

struct StateT * slot_74(struct StateT * v1595) {
  int v1596 = v1595->timer;
  int v1603 = v1596 + 1;
  v1595->timer = v1603;
  int * v1598 = v1595->regs;
  int v1599 = v1598[8];
  int v1606 = v1599 + 1;
  v1598[8] = v1606;
  struct StateT * v1601 = slot_75(v1595);
  return v1601;
}

struct StateT * slot_107(struct StateT * v2057) {
  int v2058 = v2057->timer;
  int v2065 = v2058 + 1;
  v2057->timer = v2065;
  int * v2060 = v2057->regs;
  int v2061 = v2060[8];
  int v2068 = v2061 + 1;
  v2060[8] = v2068;
  struct StateT * v2063 = slot_108(v2057);
  return v2063;
}

struct StateT * slot_136(struct StateT * v2463) {
  int v2464 = v2463->timer;
  int v2471 = v2464 + 1;
  v2463->timer = v2471;
  int * v2466 = v2463->regs;
  int v2467 = v2466[8];
  int v2474 = v2467 + 1;
  v2466[8] = v2474;
  struct StateT * v2469 = slot_137(v2463);
  return v2469;
}

struct StateT * slot_84(struct StateT * v1735) {
  int v1736 = v1735->timer;
  int v1743 = v1736 + 1;
  v1735->timer = v1743;
  int * v1738 = v1735->regs;
  int v1739 = v1738[8];
  int v1746 = v1739 + 1;
  v1738[8] = v1746;
  struct StateT * v1741 = slot_85(v1735);
  return v1741;
}

struct StateT * slot_28(struct StateT * v951) {
  int v952 = v951->timer;
  int v959 = v952 + 1;
  v951->timer = v959;
  int * v954 = v951->regs;
  int v955 = v954[8];
  int v962 = v955 + 1;
  v954[8] = v962;
  struct StateT * v957 = slot_29(v951);
  return v957;
}

struct StateT * slot_155(struct StateT * v2729) {
  int v2730 = v2729->timer;
  int v2737 = v2730 + 1;
  v2729->timer = v2737;
  int * v2732 = v2729->regs;
  int v2733 = v2732[8];
  int v2740 = v2733 + 1;
  v2732[8] = v2740;
  struct StateT * v2735 = slot_156(v2729);
  return v2735;
}

struct StateT * slot_177(struct StateT * v3037) {
  int v3038 = v3037->timer;
  int v3045 = v3038 + 1;
  v3037->timer = v3045;
  int * v3040 = v3037->regs;
  int v3041 = v3040[8];
  int v3048 = v3041 + 1;
  v3040[8] = v3048;
  struct StateT * v3043 = slot_178(v3037);
  return v3043;
}

struct StateT * slot_17(struct StateT * v797) {
  int v798 = v797->timer;
  int v805 = v798 + 1;
  v797->timer = v805;
  int * v800 = v797->regs;
  int v801 = v800[8];
  int v808 = v801 + 1;
  v800[8] = v808;
  struct StateT * v803 = slot_18(v797);
  return v803;
}

struct StateT * slot_181(struct StateT * v3093) {
  int v3094 = v3093->timer;
  int v3101 = v3094 + 1;
  v3093->timer = v3101;
  int * v3096 = v3093->regs;
  int v3097 = v3096[8];
  int v3104 = v3097 + 1;
  v3096[8] = v3104;
  struct StateT * v3099 = slot_182(v3093);
  return v3099;
}

struct StateT * slot_197(struct StateT * v3317) {
  int v3318 = v3317->timer;
  int v3325 = v3318 + 1;
  v3317->timer = v3325;
  int * v3320 = v3317->regs;
  int v3321 = v3320[8];
  int v3328 = v3321 + 1;
  v3320[8] = v3328;
  struct StateT * v3323 = slot_198(v3317);
  return v3323;
}

struct StateT * slot_207(struct StateT * v3457) {
  int v3458 = v3457->timer;
  int v3465 = v3458 + 1;
  v3457->timer = v3465;
  int * v3460 = v3457->regs;
  int v3461 = v3460[8];
  int v3468 = v3461 + 1;
  v3460[8] = v3468;
  struct StateT * v3463 = slot_208(v3457);
  return v3463;
}

struct StateT * slot_156(struct StateT * v2743) {
  int v2744 = v2743->timer;
  int v2751 = v2744 + 1;
  v2743->timer = v2751;
  int * v2746 = v2743->regs;
  int v2747 = v2746[8];
  int v2754 = v2747 + 1;
  v2746[8] = v2754;
  struct StateT * v2749 = slot_157(v2743);
  return v2749;
}

struct StateT * slot_154(struct StateT * v2715) {
  int v2716 = v2715->timer;
  int v2723 = v2716 + 1;
  v2715->timer = v2723;
  int * v2718 = v2715->regs;
  int v2719 = v2718[8];
  int v2726 = v2719 + 1;
  v2718[8] = v2726;
  struct StateT * v2721 = slot_155(v2715);
  return v2721;
}

struct StateT * slot_68(struct StateT * v1511) {
  int v1512 = v1511->timer;
  int v1519 = v1512 + 1;
  v1511->timer = v1519;
  int * v1514 = v1511->regs;
  int v1515 = v1514[8];
  int v1522 = v1515 + 1;
  v1514[8] = v1522;
  struct StateT * v1517 = slot_69(v1511);
  return v1517;
}

struct StateT * slot_105(struct StateT * v2029) {
  int v2030 = v2029->timer;
  int v2037 = v2030 + 1;
  v2029->timer = v2037;
  int * v2032 = v2029->regs;
  int v2033 = v2032[8];
  int v2040 = v2033 + 1;
  v2032[8] = v2040;
  struct StateT * v2035 = slot_106(v2029);
  return v2035;
}

struct StateT * slot_27(struct StateT * v937) {
  int v938 = v937->timer;
  int v945 = v938 + 1;
  v937->timer = v945;
  int * v940 = v937->regs;
  int v941 = v940[8];
  int v948 = v941 + 1;
  v940[8] = v948;
  struct StateT * v943 = slot_28(v937);
  return v943;
}

struct StateT * slot_164(struct StateT * v2855) {
  int v2856 = v2855->timer;
  int v2863 = v2856 + 1;
  v2855->timer = v2863;
  int * v2858 = v2855->regs;
  int v2859 = v2858[8];
  int v2866 = v2859 + 1;
  v2858[8] = v2866;
  struct StateT * v2861 = slot_165(v2855);
  return v2861;
}

struct StateT * slot_15(struct StateT * v769) {
  int v770 = v769->timer;
  int v777 = v770 + 1;
  v769->timer = v777;
  int * v772 = v769->regs;
  int v773 = v772[8];
  int v780 = v773 + 1;
  v772[8] = v780;
  struct StateT * v775 = slot_16(v769);
  return v775;
}

struct StateT * slot_133(struct StateT * v2421) {
  int v2422 = v2421->timer;
  int v2429 = v2422 + 1;
  v2421->timer = v2429;
  int * v2424 = v2421->regs;
  int v2425 = v2424[8];
  int v2432 = v2425 + 1;
  v2424[8] = v2432;
  struct StateT * v2427 = slot_134(v2421);
  return v2427;
}

struct StateT * slot_56(struct StateT * v1343) {
  int v1344 = v1343->timer;
  int v1351 = v1344 + 1;
  v1343->timer = v1351;
  int * v1346 = v1343->regs;
  int v1347 = v1346[8];
  int v1354 = v1347 + 1;
  v1346[8] = v1354;
  struct StateT * v1349 = slot_57(v1343);
  return v1349;
}

struct StateT * slot_222(struct StateT * v3667) {
  int v3668 = v3667->timer;
  int v3675 = v3668 + 1;
  v3667->timer = v3675;
  int * v3670 = v3667->regs;
  int v3671 = v3670[8];
  int v3678 = v3671 + 1;
  v3670[8] = v3678;
  struct StateT * v3673 = slot_223(v3667);
  return v3673;
}

struct StateT * slot_34(struct StateT * v1035) {
  int v1036 = v1035->timer;
  int v1043 = v1036 + 1;
  v1035->timer = v1043;
  int * v1038 = v1035->regs;
  int v1039 = v1038[8];
  int v1046 = v1039 + 1;
  v1038[8] = v1046;
  struct StateT * v1041 = slot_35(v1035);
  return v1041;
}

struct StateT * slot_171(struct StateT * v2953) {
  int v2954 = v2953->timer;
  int v2961 = v2954 + 1;
  v2953->timer = v2961;
  int * v2956 = v2953->regs;
  int v2957 = v2956[8];
  int v2964 = v2957 + 1;
  v2956[8] = v2964;
  struct StateT * v2959 = slot_172(v2953);
  return v2959;
}

struct StateT * slot_162(struct StateT * v2827) {
  int v2828 = v2827->timer;
  int v2835 = v2828 + 1;
  v2827->timer = v2835;
  int * v2830 = v2827->regs;
  int v2831 = v2830[8];
  int v2838 = v2831 + 1;
  v2830[8] = v2838;
  struct StateT * v2833 = slot_163(v2827);
  return v2833;
}

struct StateT * slot_21(struct StateT * v853) {
  int v854 = v853->timer;
  int v861 = v854 + 1;
  v853->timer = v861;
  int * v856 = v853->regs;
  int v857 = v856[8];
  int v864 = v857 + 1;
  v856[8] = v864;
  struct StateT * v859 = slot_22(v853);
  return v859;
}

struct StateT * slot_118(struct StateT * v2211) {
  int v2212 = v2211->timer;
  int v2219 = v2212 + 1;
  v2211->timer = v2219;
  int * v2214 = v2211->regs;
  int v2215 = v2214[8];
  int v2222 = v2215 + 1;
  v2214[8] = v2222;
  struct StateT * v2217 = slot_119(v2211);
  return v2217;
}

struct StateT * slot_121(struct StateT * v2253) {
  int v2254 = v2253->timer;
  int v2261 = v2254 + 1;
  v2253->timer = v2261;
  int * v2256 = v2253->regs;
  int v2257 = v2256[8];
  int v2264 = v2257 + 1;
  v2256[8] = v2264;
  struct StateT * v2259 = slot_122(v2253);
  return v2259;
}

struct StateT * slot_144(struct StateT * v2575) {
  int v2576 = v2575->timer;
  int v2583 = v2576 + 1;
  v2575->timer = v2583;
  int * v2578 = v2575->regs;
  int v2579 = v2578[8];
  int v2586 = v2579 + 1;
  v2578[8] = v2586;
  struct StateT * v2581 = slot_145(v2575);
  return v2581;
}

struct StateT * slot_201(struct StateT * v3373) {
  int v3374 = v3373->timer;
  int v3381 = v3374 + 1;
  v3373->timer = v3381;
  int * v3376 = v3373->regs;
  int v3377 = v3376[8];
  int v3384 = v3377 + 1;
  v3376[8] = v3384;
  struct StateT * v3379 = slot_202(v3373);
  return v3379;
}

struct StateT * slot_94(struct StateT * v1875) {
  int v1876 = v1875->timer;
  int v1883 = v1876 + 1;
  v1875->timer = v1883;
  int * v1878 = v1875->regs;
  int v1879 = v1878[8];
  int v1886 = v1879 + 1;
  v1878[8] = v1886;
  struct StateT * v1881 = slot_95(v1875);
  return v1881;
}

struct StateT * slot_63(struct StateT * v1441) {
  int v1442 = v1441->timer;
  int v1449 = v1442 + 1;
  v1441->timer = v1449;
  int * v1444 = v1441->regs;
  int v1445 = v1444[8];
  int v1452 = v1445 + 1;
  v1444[8] = v1452;
  struct StateT * v1447 = slot_64(v1441);
  return v1447;
}

struct StateT * slot_146(struct StateT * v2603) {
  int v2604 = v2603->timer;
  int v2611 = v2604 + 1;
  v2603->timer = v2611;
  int * v2606 = v2603->regs;
  int v2607 = v2606[8];
  int v2614 = v2607 + 1;
  v2606[8] = v2614;
  struct StateT * v2609 = slot_147(v2603);
  return v2609;
}

struct StateT * slot_24(struct StateT * v895) {
  int v896 = v895->timer;
  int v903 = v896 + 1;
  v895->timer = v903;
  int * v898 = v895->regs;
  int v899 = v898[8];
  int v906 = v899 + 1;
  v898[8] = v906;
  struct StateT * v901 = slot_25(v895);
  return v901;
}

struct StateT * slot_0(struct StateT * v2) {
  int v3 = v2->timer;
  int v113 = v3 + 1;
  v2->timer = v113;
  int * v5 = v2->regs;
  int v6 = v5[10];
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
  v109[5] = v108;
  struct StateT * v111 = slot_1(v2);
  return v111;
}

struct StateT * slot_195(struct StateT * v3289) {
  int v3290 = v3289->timer;
  int v3297 = v3290 + 1;
  v3289->timer = v3297;
  int * v3292 = v3289->regs;
  int v3293 = v3292[8];
  int v3300 = v3293 + 1;
  v3292[8] = v3300;
  struct StateT * v3295 = slot_196(v3289);
  return v3295;
}

struct StateT * slot_125(struct StateT * v2309) {
  int v2310 = v2309->timer;
  int v2317 = v2310 + 1;
  v2309->timer = v2317;
  int * v2312 = v2309->regs;
  int v2313 = v2312[8];
  int v2320 = v2313 + 1;
  v2312[8] = v2320;
  struct StateT * v2315 = slot_126(v2309);
  return v2315;
}

struct StateT * slot_148(struct StateT * v2631) {
  int v2632 = v2631->timer;
  int v2639 = v2632 + 1;
  v2631->timer = v2639;
  int * v2634 = v2631->regs;
  int v2635 = v2634[8];
  int v2642 = v2635 + 1;
  v2634[8] = v2642;
  struct StateT * v2637 = slot_149(v2631);
  return v2637;
}

struct StateT * slot_126(struct StateT * v2323) {
  int v2324 = v2323->timer;
  int v2331 = v2324 + 1;
  v2323->timer = v2331;
  int * v2326 = v2323->regs;
  int v2327 = v2326[8];
  int v2334 = v2327 + 1;
  v2326[8] = v2334;
  struct StateT * v2329 = slot_127(v2323);
  return v2329;
}

struct StateT * slot_223(struct StateT * v3681) {
  int v3682 = v3681->timer;
  int v3689 = v3682 + 1;
  v3681->timer = v3689;
  int * v3684 = v3681->regs;
  int v3685 = v3684[8];
  int v3692 = v3685 + 1;
  v3684[8] = v3692;
  struct StateT * v3687 = slot_224(v3681);
  return v3687;
}

struct StateT * slot_79(struct StateT * v1665) {
  int v1666 = v1665->timer;
  int v1673 = v1666 + 1;
  v1665->timer = v1673;
  int * v1668 = v1665->regs;
  int v1669 = v1668[8];
  int v1676 = v1669 + 1;
  v1668[8] = v1676;
  struct StateT * v1671 = slot_80(v1665);
  return v1671;
}

struct StateT * slot_41(struct StateT * v1133) {
  int v1134 = v1133->timer;
  int v1141 = v1134 + 1;
  v1133->timer = v1141;
  int * v1136 = v1133->regs;
  int v1137 = v1136[8];
  int v1144 = v1137 + 1;
  v1136[8] = v1144;
  struct StateT * v1139 = slot_42(v1133);
  return v1139;
}

struct StateT * slot_39(struct StateT * v1105) {
  int v1106 = v1105->timer;
  int v1113 = v1106 + 1;
  v1105->timer = v1113;
  int * v1108 = v1105->regs;
  int v1109 = v1108[8];
  int v1116 = v1109 + 1;
  v1108[8] = v1116;
  struct StateT * v1111 = slot_40(v1105);
  return v1111;
}

struct StateT * slot_142(struct StateT * v2547) {
  int v2548 = v2547->timer;
  int v2555 = v2548 + 1;
  v2547->timer = v2555;
  int * v2550 = v2547->regs;
  int v2551 = v2550[8];
  int v2558 = v2551 + 1;
  v2550[8] = v2558;
  struct StateT * v2553 = slot_143(v2547);
  return v2553;
}

struct StateT * slot_60(struct StateT * v1399) {
  int v1400 = v1399->timer;
  int v1407 = v1400 + 1;
  v1399->timer = v1407;
  int * v1402 = v1399->regs;
  int v1403 = v1402[8];
  int v1410 = v1403 + 1;
  v1402[8] = v1410;
  struct StateT * v1405 = slot_61(v1399);
  return v1405;
}

struct StateT * slot_112(struct StateT * v2127) {
  int v2128 = v2127->timer;
  int v2135 = v2128 + 1;
  v2127->timer = v2135;
  int * v2130 = v2127->regs;
  int v2131 = v2130[8];
  int v2138 = v2131 + 1;
  v2130[8] = v2138;
  struct StateT * v2133 = slot_113(v2127);
  return v2133;
}

struct StateT * slot_47(struct StateT * v1217) {
  int v1218 = v1217->timer;
  int v1225 = v1218 + 1;
  v1217->timer = v1225;
  int * v1220 = v1217->regs;
  int v1221 = v1220[8];
  int v1228 = v1221 + 1;
  v1220[8] = v1228;
  struct StateT * v1223 = slot_48(v1217);
  return v1223;
}

struct StateT * slot_214(struct StateT * v3555) {
  int v3556 = v3555->timer;
  int v3563 = v3556 + 1;
  v3555->timer = v3563;
  int * v3558 = v3555->regs;
  int v3559 = v3558[8];
  int v3566 = v3559 + 1;
  v3558[8] = v3566;
  struct StateT * v3561 = slot_215(v3555);
  return v3561;
}

struct StateT * slot_29(struct StateT * v965) {
  int v966 = v965->timer;
  int v973 = v966 + 1;
  v965->timer = v973;
  int * v968 = v965->regs;
  int v969 = v968[8];
  int v976 = v969 + 1;
  v968[8] = v976;
  struct StateT * v971 = slot_30(v965);
  return v971;
}

struct StateT * slot_16(struct StateT * v783) {
  int v784 = v783->timer;
  int v791 = v784 + 1;
  v783->timer = v791;
  int * v786 = v783->regs;
  int v787 = v786[8];
  int v794 = v787 + 1;
  v786[8] = v794;
  struct StateT * v789 = slot_17(v783);
  return v789;
}

struct StateT * slot_113(struct StateT * v2141) {
  int v2142 = v2141->timer;
  int v2149 = v2142 + 1;
  v2141->timer = v2149;
  int * v2144 = v2141->regs;
  int v2145 = v2144[8];
  int v2152 = v2145 + 1;
  v2144[8] = v2152;
  struct StateT * v2147 = slot_114(v2141);
  return v2147;
}

struct StateT * slot_151(struct StateT * v2673) {
  int v2674 = v2673->timer;
  int v2681 = v2674 + 1;
  v2673->timer = v2681;
  int * v2676 = v2673->regs;
  int v2677 = v2676[8];
  int v2684 = v2677 + 1;
  v2676[8] = v2684;
  struct StateT * v2679 = slot_152(v2673);
  return v2679;
}

struct StateT * slot_7(struct StateT * v657) {
  int v658 = v657->timer;
  int v665 = v658 + 1;
  v657->timer = v665;
  int * v660 = v657->regs;
  int v661 = v660[8];
  int v668 = v661 + 1;
  v660[8] = v668;
  struct StateT * v663 = slot_8(v657);
  return v663;
}

struct StateT * slot_124(struct StateT * v2295) {
  int v2296 = v2295->timer;
  int v2303 = v2296 + 1;
  v2295->timer = v2303;
  int * v2298 = v2295->regs;
  int v2299 = v2298[8];
  int v2306 = v2299 + 1;
  v2298[8] = v2306;
  struct StateT * v2301 = slot_125(v2295);
  return v2301;
}

struct StateT * slot_191(struct StateT * v3233) {
  int v3234 = v3233->timer;
  int v3241 = v3234 + 1;
  v3233->timer = v3241;
  int * v3236 = v3233->regs;
  int v3237 = v3236[8];
  int v3244 = v3237 + 1;
  v3236[8] = v3244;
  struct StateT * v3239 = slot_192(v3233);
  return v3239;
}

struct StateT * slot_103(struct StateT * v2001) {
  int v2002 = v2001->timer;
  int v2009 = v2002 + 1;
  v2001->timer = v2009;
  int * v2004 = v2001->regs;
  int v2005 = v2004[8];
  int v2012 = v2005 + 1;
  v2004[8] = v2012;
  struct StateT * v2007 = slot_104(v2001);
  return v2007;
}

struct StateT * slot_128(struct StateT * v2351) {
  int v2352 = v2351->timer;
  int v2359 = v2352 + 1;
  v2351->timer = v2359;
  int * v2354 = v2351->regs;
  int v2355 = v2354[8];
  int v2362 = v2355 + 1;
  v2354[8] = v2362;
  struct StateT * v2357 = slot_129(v2351);
  return v2357;
}

struct StateT * slot_19(struct StateT * v825) {
  int v826 = v825->timer;
  int v833 = v826 + 1;
  v825->timer = v833;
  int * v828 = v825->regs;
  int v829 = v828[8];
  int v836 = v829 + 1;
  v828[8] = v836;
  struct StateT * v831 = slot_20(v825);
  return v831;
}

struct StateT * slot_87(struct StateT * v1777) {
  int v1778 = v1777->timer;
  int v1785 = v1778 + 1;
  v1777->timer = v1785;
  int * v1780 = v1777->regs;
  int v1781 = v1780[8];
  int v1788 = v1781 + 1;
  v1780[8] = v1788;
  struct StateT * v1783 = slot_88(v1777);
  return v1783;
}

struct StateT * slot_67(struct StateT * v1497) {
  int v1498 = v1497->timer;
  int v1505 = v1498 + 1;
  v1497->timer = v1505;
  int * v1500 = v1497->regs;
  int v1501 = v1500[8];
  int v1508 = v1501 + 1;
  v1500[8] = v1508;
  struct StateT * v1503 = slot_68(v1497);
  return v1503;
}

struct StateT * slot_81(struct StateT * v1693) {
  int v1694 = v1693->timer;
  int v1701 = v1694 + 1;
  v1693->timer = v1701;
  int * v1696 = v1693->regs;
  int v1697 = v1696[8];
  int v1704 = v1697 + 1;
  v1696[8] = v1704;
  struct StateT * v1699 = slot_82(v1693);
  return v1699;
}

struct StateT * slot_95(struct StateT * v1889) {
  int v1890 = v1889->timer;
  int v1897 = v1890 + 1;
  v1889->timer = v1897;
  int * v1892 = v1889->regs;
  int v1893 = v1892[8];
  int v1900 = v1893 + 1;
  v1892[8] = v1900;
  struct StateT * v1895 = slot_96(v1889);
  return v1895;
}

struct StateT * slot_115(struct StateT * v2169) {
  int v2170 = v2169->timer;
  int v2177 = v2170 + 1;
  v2169->timer = v2177;
  int * v2172 = v2169->regs;
  int v2173 = v2172[8];
  int v2180 = v2173 + 1;
  v2172[8] = v2180;
  struct StateT * v2175 = slot_116(v2169);
  return v2175;
}

struct StateT * slot_78(struct StateT * v1651) {
  int v1652 = v1651->timer;
  int v1659 = v1652 + 1;
  v1651->timer = v1659;
  int * v1654 = v1651->regs;
  int v1655 = v1654[8];
  int v1662 = v1655 + 1;
  v1654[8] = v1662;
  struct StateT * v1657 = slot_79(v1651);
  return v1657;
}

struct StateT * slot_32(struct StateT * v1007) {
  int v1008 = v1007->timer;
  int v1015 = v1008 + 1;
  v1007->timer = v1015;
  int * v1010 = v1007->regs;
  int v1011 = v1010[8];
  int v1018 = v1011 + 1;
  v1010[8] = v1018;
  struct StateT * v1013 = slot_33(v1007);
  return v1013;
}

struct StateT * slot_205(struct StateT * v3429) {
  int v3430 = v3429->timer;
  int v3437 = v3430 + 1;
  v3429->timer = v3437;
  int * v3432 = v3429->regs;
  int v3433 = v3432[8];
  int v3440 = v3433 + 1;
  v3432[8] = v3440;
  struct StateT * v3435 = slot_206(v3429);
  return v3435;
}

struct StateT * slot_193(struct StateT * v3261) {
  int v3262 = v3261->timer;
  int v3269 = v3262 + 1;
  v3261->timer = v3269;
  int * v3264 = v3261->regs;
  int v3265 = v3264[8];
  int v3272 = v3265 + 1;
  v3264[8] = v3272;
  struct StateT * v3267 = slot_194(v3261);
  return v3267;
}

struct StateT * slot_176(struct StateT * v3023) {
  int v3024 = v3023->timer;
  int v3031 = v3024 + 1;
  v3023->timer = v3031;
  int * v3026 = v3023->regs;
  int v3027 = v3026[8];
  int v3034 = v3027 + 1;
  v3026[8] = v3034;
  struct StateT * v3029 = slot_177(v3023);
  return v3029;
}

struct StateT * slot_189(struct StateT * v3205) {
  int v3206 = v3205->timer;
  int v3213 = v3206 + 1;
  v3205->timer = v3213;
  int * v3208 = v3205->regs;
  int v3209 = v3208[8];
  int v3216 = v3209 + 1;
  v3208[8] = v3216;
  struct StateT * v3211 = slot_190(v3205);
  return v3211;
}

struct StateT * slot_33(struct StateT * v1021) {
  int v1022 = v1021->timer;
  int v1029 = v1022 + 1;
  v1021->timer = v1029;
  int * v1024 = v1021->regs;
  int v1025 = v1024[8];
  int v1032 = v1025 + 1;
  v1024[8] = v1032;
  struct StateT * v1027 = slot_34(v1021);
  return v1027;
}

struct StateT * slot_35(struct StateT * v1049) {
  int v1050 = v1049->timer;
  int v1057 = v1050 + 1;
  v1049->timer = v1057;
  int * v1052 = v1049->regs;
  int v1053 = v1052[8];
  int v1060 = v1053 + 1;
  v1052[8] = v1060;
  struct StateT * v1055 = slot_36(v1049);
  return v1055;
}

struct StateT * slot_210(struct StateT * v3499) {
  int v3500 = v3499->timer;
  int v3507 = v3500 + 1;
  v3499->timer = v3507;
  int * v3502 = v3499->regs;
  int v3503 = v3502[8];
  int v3510 = v3503 + 1;
  v3502[8] = v3510;
  struct StateT * v3505 = slot_211(v3499);
  return v3505;
}

struct StateT * slot_166(struct StateT * v2883) {
  int v2884 = v2883->timer;
  int v2891 = v2884 + 1;
  v2883->timer = v2891;
  int * v2886 = v2883->regs;
  int v2887 = v2886[8];
  int v2894 = v2887 + 1;
  v2886[8] = v2894;
  struct StateT * v2889 = slot_167(v2883);
  return v2889;
}

struct StateT * slot_51(struct StateT * v1273) {
  int v1274 = v1273->timer;
  int v1281 = v1274 + 1;
  v1273->timer = v1281;
  int * v1276 = v1273->regs;
  int v1277 = v1276[8];
  int v1284 = v1277 + 1;
  v1276[8] = v1284;
  struct StateT * v1279 = slot_52(v1273);
  return v1279;
}

struct StateT * slot_52(struct StateT * v1287) {
  int v1288 = v1287->timer;
  int v1295 = v1288 + 1;
  v1287->timer = v1295;
  int * v1290 = v1287->regs;
  int v1291 = v1290[8];
  int v1298 = v1291 + 1;
  v1290[8] = v1298;
  struct StateT * v1293 = slot_53(v1287);
  return v1293;
}

struct StateT * slot_83(struct StateT * v1721) {
  int v1722 = v1721->timer;
  int v1729 = v1722 + 1;
  v1721->timer = v1729;
  int * v1724 = v1721->regs;
  int v1725 = v1724[8];
  int v1732 = v1725 + 1;
  v1724[8] = v1732;
  struct StateT * v1727 = slot_84(v1721);
  return v1727;
}

struct StateT * slot_25(struct StateT * v909) {
  int v910 = v909->timer;
  int v917 = v910 + 1;
  v909->timer = v917;
  int * v912 = v909->regs;
  int v913 = v912[8];
  int v920 = v913 + 1;
  v912[8] = v920;
  struct StateT * v915 = slot_26(v909);
  return v915;
}

struct StateT * slot_209(struct StateT * v3485) {
  int v3486 = v3485->timer;
  int v3493 = v3486 + 1;
  v3485->timer = v3493;
  int * v3488 = v3485->regs;
  int v3489 = v3488[8];
  int v3496 = v3489 + 1;
  v3488[8] = v3496;
  struct StateT * v3491 = slot_210(v3485);
  return v3491;
}

struct StateT * slot_3(struct StateT * v412) {
  int v413 = v412->timer;
  int v420 = v413 + 1;
  v412->timer = v420;
  int * v415 = v412->regs;
  int v416 = v415[6];
  int v423 = v416 << 2;
  v415[6] = v423;
  struct StateT * v418 = slot_4(v412);
  return v418;
}

struct StateT * slot_123(struct StateT * v2281) {
  int v2282 = v2281->timer;
  int v2289 = v2282 + 1;
  v2281->timer = v2289;
  int * v2284 = v2281->regs;
  int v2285 = v2284[8];
  int v2292 = v2285 + 1;
  v2284[8] = v2292;
  struct StateT * v2287 = slot_124(v2281);
  return v2287;
}

struct StateT * slot_73(struct StateT * v1581) {
  int v1582 = v1581->timer;
  int v1589 = v1582 + 1;
  v1581->timer = v1589;
  int * v1584 = v1581->regs;
  int v1585 = v1584[8];
  int v1592 = v1585 + 1;
  v1584[8] = v1592;
  struct StateT * v1587 = slot_74(v1581);
  return v1587;
}

struct StateT * slot_198(struct StateT * v3331) {
  int v3332 = v3331->timer;
  int v3339 = v3332 + 1;
  v3331->timer = v3339;
  int * v3334 = v3331->regs;
  int v3335 = v3334[8];
  int v3342 = v3335 + 1;
  v3334[8] = v3342;
  struct StateT * v3337 = slot_199(v3331);
  return v3337;
}

struct StateT * slot_1(struct StateT * v206) {
  int v207 = v206->timer;
  int v315 = v207 + 1;
  v206->timer = v315;
  int * v209 = v206->cache_tags;
  int v210 = v209[0];
  int v211 = v209[1];
  int v212 = v209[8];
  int v213 = v209[9];
  int v214 = v206->timer;
  int v321 = v214 + ((100 ^ (((~(((v212 ^ 10) | (-(v212 ^ 10))) >> 31)) | (~(((v213 ^ 10) | (-(v213 ^ 10))) >> 31))) & 104)) ^ (((~(((v210 ^ 10) | (-(v210 ^ 10))) >> 31)) | (~(((v211 ^ 10) | (-(v211 ^ 10))) >> 31))) & (1 ^ (100 ^ (((~(((v212 ^ 10) | (-(v212 ^ 10))) >> 31)) | (~(((v213 ^ 10) | (-(v213 ^ 10))) >> 31))) & 104)))));
  v206->timer = v321;
  int * v216 = v206->cache_vals;
  bool v322 = !(((~(((v210 ^ 10) | (-(v210 ^ 10))) >> 31)) | (~(((v211 ^ 10) | (-(v211 ^ 10))) >> 31))) == 0);
  int v309;
  if (v322) {
    int * v217 = v206->cache_age;
    int v324 = (~(((v211 ^ 10) | (-(v211 ^ 10))) >> 31)) & 1;
    int v218 = v217[v324];
    int v219 = v217[0];
    int v325 = v219 + ((int)((unsigned int)(v219 - v218) >> 31));
    v217[0] = v325;
    int * v221 = v206->cache_age;
    int v222 = v221[1];
    int v327 = v222 + ((int)((unsigned int)(v222 - v218) >> 31));
    v221[1] = v327;
    int * v224 = v206->cache_age;
    v224[v324] = 0;
    v309 = v324;
  } else {
    int * v227 = v206->cache_age;
    int v228 = v227[0];
    int * v229 = v206->cache_tags;
    int v230 = v229[0];
    int v231 = v227[1];
    int v232 = v229[1];
    bool v331 = !(((~(((v212 ^ 10) | (-(v212 ^ 10))) >> 31)) | (~(((v213 ^ 10) | (-(v213 ^ 10))) >> 31))) == 0);
    int v286;
    if (v331) {
      int * v233 = v206->cache_age;
      int v333 = 8 + ((~(((v213 ^ 10) | (-(v213 ^ 10))) >> 31)) & 1);
      int v234 = v233[v333];
      int v235 = v233[8];
      int v334 = v235 + ((int)((unsigned int)(v235 - v234) >> 31));
      v233[8] = v334;
      int * v237 = v206->cache_age;
      int v238 = v237[9];
      int v336 = v238 + ((int)((unsigned int)(v238 - v234) >> 31));
      v237[9] = v336;
      int * v240 = v206->cache_age;
      v240[v333] = 0;
      v286 = v333;
    } else {
      int * v243 = v206->cache_age;
      int v244 = v243[8];
      int * v245 = v206->cache_tags;
      int v246 = v245[8];
      int v247 = v243[9];
      int v248 = v245[9];
      int * v249 = v206->cache_dirty;
      int v341 = 8 + ((((v244 + ((~(((v246 ^ -1) | (-(v246 ^ -1))) >> 31)) & 2)) - (v247 + ((~(((v248 ^ -1) | (-(v248 ^ -1))) >> 31)) & 2))) >> 31) & 1);
      int v250 = v249[v341];
      bool v342 = !(v250 == 0);
      if (v342) {
        int * v251 = v206->cache_tags;
        int v252 = v251[v341];
        int * v253 = v206->cache_vals;
        int v345 = (8 + ((((v244 + ((~(((v246 ^ -1) | (-(v246 ^ -1))) >> 31)) & 2)) - (v247 + ((~(((v248 ^ -1) | (-(v248 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
        int v254 = v253[v345];
        int v346 = ((8 + ((((v244 + ((~(((v246 ^ -1) | (-(v246 ^ -1))) >> 31)) & 2)) - (v247 + ((~(((v248 ^ -1) | (-(v248 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
        int v255 = v253[v346];
        int * v256 = v206->mem;
        int v348 = v252 * 2;
        v256[v348] = v254;
        int * v258 = v206->mem;
        int v351 = (v252 * 2) + 1;
        v258[v351] = v255;
        ;
      } else {
        ;
      }
      int * v263 = v206->mem;
      int v264 = v263[20];
      int v265 = v263[21];
      int * v266 = v206->cache_vals;
      int v359 = (8 + ((((v244 + ((~(((v246 ^ -1) | (-(v246 ^ -1))) >> 31)) & 2)) - (v247 + ((~(((v248 ^ -1) | (-(v248 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
      v266[v359] = v264;
      int * v268 = v206->cache_vals;
      int v362 = ((8 + ((((v244 + ((~(((v246 ^ -1) | (-(v246 ^ -1))) >> 31)) & 2)) - (v247 + ((~(((v248 ^ -1) | (-(v248 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
      v268[v362] = v265;
      int * v270 = v206->cache_tags;
      v270[v341] = 10;
      int * v272 = v206->cache_dirty;
      v272[v341] = 0;
      int * v274 = v206->cache_age;
      v274[v341] = 1;
      int * v276 = v206->cache_age;
      int v277 = v276[v341];
      int v278 = v276[8];
      int v369 = v278 + ((int)((unsigned int)(v278 - v277) >> 31));
      v276[8] = v369;
      int * v280 = v206->cache_age;
      int v281 = v280[9];
      int v371 = v281 + ((int)((unsigned int)(v281 - v277) >> 31));
      v280[9] = v371;
      int * v283 = v206->cache_age;
      v283[v341] = 0;
      v286 = v341;
    }
    int * v287 = v206->cache_vals;
    int v374 = v286 * 2;
    int v288 = v287[v374];
    int v375 = (v286 * 2) + 1;
    int v289 = v287[v375];
    int v376 = ((((v228 + ((~(((v230 ^ -1) | (-(v230 ^ -1))) >> 31)) & 2)) - (v231 + ((~(((v232 ^ -1) | (-(v232 ^ -1))) >> 31)) & 2))) >> 31) & 1) * 2;
    v287[v376] = v288;
    int * v291 = v206->cache_vals;
    int v379 = (((((v228 + ((~(((v230 ^ -1) | (-(v230 ^ -1))) >> 31)) & 2)) - (v231 + ((~(((v232 ^ -1) | (-(v232 ^ -1))) >> 31)) & 2))) >> 31) & 1) * 2) + 1;
    v291[v379] = v289;
    int * v293 = v206->cache_tags;
    int v382 = (((v228 + ((~(((v230 ^ -1) | (-(v230 ^ -1))) >> 31)) & 2)) - (v231 + ((~(((v232 ^ -1) | (-(v232 ^ -1))) >> 31)) & 2))) >> 31) & 1;
    v293[v382] = 10;
    int * v295 = v206->cache_dirty;
    v295[v382] = 0;
    int * v297 = v206->cache_age;
    v297[v382] = 1;
    int * v299 = v206->cache_age;
    int v300 = v299[v382];
    int v301 = v299[0];
    int v387 = v301 + ((int)((unsigned int)(v301 - v300) >> 31));
    v299[0] = v387;
    int * v303 = v206->cache_age;
    int v304 = v303[1];
    int v389 = v304 + ((int)((unsigned int)(v304 - v300) >> 31));
    v303[1] = v389;
    int * v306 = v206->cache_age;
    v306[v382] = 0;
    v309 = v382;
  }
  int v392 = v309 * 2;
  int v310 = v216[v392];
  int * v311 = v206->regs;
  v311[6] = v310;
  struct StateT * v313 = slot_2(v206);
  return v313;
}

struct StateT * slot_187(struct StateT * v3177) {
  int v3178 = v3177->timer;
  int v3185 = v3178 + 1;
  v3177->timer = v3185;
  int * v3180 = v3177->regs;
  int v3181 = v3180[8];
  int v3188 = v3181 + 1;
  v3180[8] = v3188;
  struct StateT * v3183 = slot_188(v3177);
  return v3183;
}

struct StateT * slot_97(struct StateT * v1917) {
  int v1918 = v1917->timer;
  int v1925 = v1918 + 1;
  v1917->timer = v1925;
  int * v1920 = v1917->regs;
  int v1921 = v1920[8];
  int v1928 = v1921 + 1;
  v1920[8] = v1928;
  struct StateT * v1923 = slot_98(v1917);
  return v1923;
}

struct StateT * slot_182(struct StateT * v3107) {
  int v3108 = v3107->timer;
  int v3115 = v3108 + 1;
  v3107->timer = v3115;
  int * v3110 = v3107->regs;
  int v3111 = v3110[8];
  int v3118 = v3111 + 1;
  v3110[8] = v3118;
  struct StateT * v3113 = slot_183(v3107);
  return v3113;
}

struct StateT * slot_38(struct StateT * v1091) {
  int v1092 = v1091->timer;
  int v1099 = v1092 + 1;
  v1091->timer = v1099;
  int * v1094 = v1091->regs;
  int v1095 = v1094[8];
  int v1102 = v1095 + 1;
  v1094[8] = v1102;
  struct StateT * v1097 = slot_39(v1091);
  return v1097;
}

struct StateT * slot_178(struct StateT * v3051) {
  int v3052 = v3051->timer;
  int v3059 = v3052 + 1;
  v3051->timer = v3059;
  int * v3054 = v3051->regs;
  int v3055 = v3054[8];
  int v3062 = v3055 + 1;
  v3054[8] = v3062;
  struct StateT * v3057 = slot_179(v3051);
  return v3057;
}

struct StateT * slot_106(struct StateT * v2043) {
  int v2044 = v2043->timer;
  int v2051 = v2044 + 1;
  v2043->timer = v2051;
  int * v2046 = v2043->regs;
  int v2047 = v2046[8];
  int v2054 = v2047 + 1;
  v2046[8] = v2054;
  struct StateT * v2049 = slot_107(v2043);
  return v2049;
}

struct StateT * slot_98(struct StateT * v1931) {
  int v1932 = v1931->timer;
  int v1939 = v1932 + 1;
  v1931->timer = v1939;
  int * v1934 = v1931->regs;
  int v1935 = v1934[8];
  int v1942 = v1935 + 1;
  v1934[8] = v1942;
  struct StateT * v1937 = slot_99(v1931);
  return v1937;
}

struct StateT * slot_159(struct StateT * v2785) {
  int v2786 = v2785->timer;
  int v2793 = v2786 + 1;
  v2785->timer = v2793;
  int * v2788 = v2785->regs;
  int v2789 = v2788[8];
  int v2796 = v2789 + 1;
  v2788[8] = v2796;
  struct StateT * v2791 = slot_160(v2785);
  return v2791;
}

struct StateT * slot_46(struct StateT * v1203) {
  int v1204 = v1203->timer;
  int v1211 = v1204 + 1;
  v1203->timer = v1211;
  int * v1206 = v1203->regs;
  int v1207 = v1206[8];
  int v1214 = v1207 + 1;
  v1206[8] = v1214;
  struct StateT * v1209 = slot_47(v1203);
  return v1209;
}

struct StateT * slot_212(struct StateT * v3527) {
  int v3528 = v3527->timer;
  int v3535 = v3528 + 1;
  v3527->timer = v3535;
  int * v3530 = v3527->regs;
  int v3531 = v3530[8];
  int v3538 = v3531 + 1;
  v3530[8] = v3538;
  struct StateT * v3533 = slot_213(v3527);
  return v3533;
}

struct StateT * slot_132(struct StateT * v2407) {
  int v2408 = v2407->timer;
  int v2415 = v2408 + 1;
  v2407->timer = v2415;
  int * v2410 = v2407->regs;
  int v2411 = v2410[8];
  int v2418 = v2411 + 1;
  v2410[8] = v2418;
  struct StateT * v2413 = slot_133(v2407);
  return v2413;
}

struct StateT * slot_130(struct StateT * v2379) {
  int v2380 = v2379->timer;
  int v2387 = v2380 + 1;
  v2379->timer = v2387;
  int * v2382 = v2379->regs;
  int v2383 = v2382[8];
  int v2390 = v2383 + 1;
  v2382[8] = v2390;
  struct StateT * v2385 = slot_131(v2379);
  return v2385;
}

struct StateT * slot_211(struct StateT * v3513) {
  int v3514 = v3513->timer;
  int v3521 = v3514 + 1;
  v3513->timer = v3521;
  int * v3516 = v3513->regs;
  int v3517 = v3516[8];
  int v3524 = v3517 + 1;
  v3516[8] = v3524;
  struct StateT * v3519 = slot_212(v3513);
  return v3519;
}

struct StateT * slot_20(struct StateT * v839) {
  int v840 = v839->timer;
  int v847 = v840 + 1;
  v839->timer = v847;
  int * v842 = v839->regs;
  int v843 = v842[8];
  int v850 = v843 + 1;
  v842[8] = v850;
  struct StateT * v845 = slot_21(v839);
  return v845;
}

struct StateT * slot_141(struct StateT * v2533) {
  int v2534 = v2533->timer;
  int v2541 = v2534 + 1;
  v2533->timer = v2541;
  int * v2536 = v2533->regs;
  int v2537 = v2536[8];
  int v2544 = v2537 + 1;
  v2536[8] = v2544;
  struct StateT * v2539 = slot_142(v2533);
  return v2539;
}

struct StateT * slot_61(struct StateT * v1413) {
  int v1414 = v1413->timer;
  int v1421 = v1414 + 1;
  v1413->timer = v1421;
  int * v1416 = v1413->regs;
  int v1417 = v1416[8];
  int v1424 = v1417 + 1;
  v1416[8] = v1424;
  struct StateT * v1419 = slot_62(v1413);
  return v1419;
}

struct StateT * slot_30(struct StateT * v979) {
  int v980 = v979->timer;
  int v987 = v980 + 1;
  v979->timer = v987;
  int * v982 = v979->regs;
  int v983 = v982[8];
  int v990 = v983 + 1;
  v982[8] = v990;
  struct StateT * v985 = slot_31(v979);
  return v985;
}

struct StateT * slot_4(struct StateT * v426) {
  int v427 = v426->timer;
  int v537 = v427 + 1;
  v426->timer = v537;
  int * v429 = v426->regs;
  int v430 = v429[6];
  int * v431 = v426->cache_tags;
  int v541 = (((int)((unsigned int)((int)((unsigned int)v430 >> 2)) >> 1)) & 1) * 2;
  int v432 = v431[v541];
  int v542 = ((((int)((unsigned int)((int)((unsigned int)v430 >> 2)) >> 1)) & 1) * 2) + 1;
  int v433 = v431[v542];
  int v543 = 4 + ((((int)((unsigned int)((int)((unsigned int)v430 >> 2)) >> 1)) & 3) * 2);
  int v434 = v431[v543];
  int v544 = (4 + ((((int)((unsigned int)((int)((unsigned int)v430 >> 2)) >> 1)) & 3) * 2)) + 1;
  int v435 = v431[v544];
  int v436 = v426->timer;
  int v545 = v436 + ((100 ^ (((~(((v434 ^ ((int)((unsigned int)((int)((unsigned int)v430 >> 2)) >> 1))) | (-(v434 ^ ((int)((unsigned int)((int)((unsigned int)v430 >> 2)) >> 1))))) >> 31)) | (~(((v435 ^ ((int)((unsigned int)((int)((unsigned int)v430 >> 2)) >> 1))) | (-(v435 ^ ((int)((unsigned int)((int)((unsigned int)v430 >> 2)) >> 1))))) >> 31))) & 104)) ^ (((~(((v432 ^ ((int)((unsigned int)((int)((unsigned int)v430 >> 2)) >> 1))) | (-(v432 ^ ((int)((unsigned int)((int)((unsigned int)v430 >> 2)) >> 1))))) >> 31)) | (~(((v433 ^ ((int)((unsigned int)((int)((unsigned int)v430 >> 2)) >> 1))) | (-(v433 ^ ((int)((unsigned int)((int)((unsigned int)v430 >> 2)) >> 1))))) >> 31))) & (1 ^ (100 ^ (((~(((v434 ^ ((int)((unsigned int)((int)((unsigned int)v430 >> 2)) >> 1))) | (-(v434 ^ ((int)((unsigned int)((int)((unsigned int)v430 >> 2)) >> 1))))) >> 31)) | (~(((v435 ^ ((int)((unsigned int)((int)((unsigned int)v430 >> 2)) >> 1))) | (-(v435 ^ ((int)((unsigned int)((int)((unsigned int)v430 >> 2)) >> 1))))) >> 31))) & 104)))));
  v426->timer = v545;
  int * v438 = v426->cache_vals;
  bool v546 = !(((~(((v432 ^ ((int)((unsigned int)((int)((unsigned int)v430 >> 2)) >> 1))) | (-(v432 ^ ((int)((unsigned int)((int)((unsigned int)v430 >> 2)) >> 1))))) >> 31)) | (~(((v433 ^ ((int)((unsigned int)((int)((unsigned int)v430 >> 2)) >> 1))) | (-(v433 ^ ((int)((unsigned int)((int)((unsigned int)v430 >> 2)) >> 1))))) >> 31))) == 0);
  int v531;
  if (v546) {
    int * v439 = v426->cache_age;
    int v548 = ((((int)((unsigned int)((int)((unsigned int)v430 >> 2)) >> 1)) & 1) * 2) + ((~(((v433 ^ ((int)((unsigned int)((int)((unsigned int)v430 >> 2)) >> 1))) | (-(v433 ^ ((int)((unsigned int)((int)((unsigned int)v430 >> 2)) >> 1))))) >> 31)) & 1);
    int v440 = v439[v548];
    int v441 = v439[v541];
    int v549 = v441 + ((int)((unsigned int)(v441 - v440) >> 31));
    v439[v541] = v549;
    int * v443 = v426->cache_age;
    int v444 = v443[v542];
    int v551 = v444 + ((int)((unsigned int)(v444 - v440) >> 31));
    v443[v542] = v551;
    int * v446 = v426->cache_age;
    v446[v548] = 0;
    v531 = v548;
  } else {
    int * v449 = v426->cache_age;
    int v555 = (((int)((unsigned int)((int)((unsigned int)v430 >> 2)) >> 1)) & 1) * 2;
    int v450 = v449[v555];
    int * v451 = v426->cache_tags;
    int v452 = v451[v555];
    int v453 = v449[v542];
    int v454 = v451[v542];
    bool v557 = !(((~(((v434 ^ ((int)((unsigned int)((int)((unsigned int)v430 >> 2)) >> 1))) | (-(v434 ^ ((int)((unsigned int)((int)((unsigned int)v430 >> 2)) >> 1))))) >> 31)) | (~(((v435 ^ ((int)((unsigned int)((int)((unsigned int)v430 >> 2)) >> 1))) | (-(v435 ^ ((int)((unsigned int)((int)((unsigned int)v430 >> 2)) >> 1))))) >> 31))) == 0);
    int v508;
    if (v557) {
      int * v455 = v426->cache_age;
      int v559 = (4 + ((((int)((unsigned int)((int)((unsigned int)v430 >> 2)) >> 1)) & 3) * 2)) + ((~(((v435 ^ ((int)((unsigned int)((int)((unsigned int)v430 >> 2)) >> 1))) | (-(v435 ^ ((int)((unsigned int)((int)((unsigned int)v430 >> 2)) >> 1))))) >> 31)) & 1);
      int v456 = v455[v559];
      int v457 = v455[v543];
      int v560 = v457 + ((int)((unsigned int)(v457 - v456) >> 31));
      v455[v543] = v560;
      int * v459 = v426->cache_age;
      int v460 = v459[v544];
      int v562 = v460 + ((int)((unsigned int)(v460 - v456) >> 31));
      v459[v544] = v562;
      int * v462 = v426->cache_age;
      v462[v559] = 0;
      v508 = v559;
    } else {
      int * v465 = v426->cache_age;
      int v566 = 4 + ((((int)((unsigned int)((int)((unsigned int)v430 >> 2)) >> 1)) & 3) * 2);
      int v466 = v465[v566];
      int * v467 = v426->cache_tags;
      int v468 = v467[v566];
      int v469 = v465[v544];
      int v470 = v467[v544];
      int * v471 = v426->cache_dirty;
      int v569 = (4 + ((((int)((unsigned int)((int)((unsigned int)v430 >> 2)) >> 1)) & 3) * 2)) + ((((v466 + ((~(((v468 ^ -1) | (-(v468 ^ -1))) >> 31)) & 2)) - (v469 + ((~(((v470 ^ -1) | (-(v470 ^ -1))) >> 31)) & 2))) >> 31) & 1);
      int v472 = v471[v569];
      bool v570 = !(v472 == 0);
      if (v570) {
        int * v473 = v426->cache_tags;
        int v474 = v473[v569];
        int * v475 = v426->cache_vals;
        int v573 = ((4 + ((((int)((unsigned int)((int)((unsigned int)v430 >> 2)) >> 1)) & 3) * 2)) + ((((v466 + ((~(((v468 ^ -1) | (-(v468 ^ -1))) >> 31)) & 2)) - (v469 + ((~(((v470 ^ -1) | (-(v470 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
        int v476 = v475[v573];
        int v574 = (((4 + ((((int)((unsigned int)((int)((unsigned int)v430 >> 2)) >> 1)) & 3) * 2)) + ((((v466 + ((~(((v468 ^ -1) | (-(v468 ^ -1))) >> 31)) & 2)) - (v469 + ((~(((v470 ^ -1) | (-(v470 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
        int v477 = v475[v574];
        int * v478 = v426->mem;
        int v576 = v474 * 2;
        v478[v576] = v476;
        int * v480 = v426->mem;
        int v579 = (v474 * 2) + 1;
        v480[v579] = v477;
        ;
      } else {
        ;
      }
      int * v485 = v426->mem;
      int v584 = ((int)((unsigned int)((int)((unsigned int)v430 >> 2)) >> 1)) * 2;
      int v486 = v485[v584];
      int v585 = (((int)((unsigned int)((int)((unsigned int)v430 >> 2)) >> 1)) * 2) + 1;
      int v487 = v485[v585];
      int * v488 = v426->cache_vals;
      int v587 = ((4 + ((((int)((unsigned int)((int)((unsigned int)v430 >> 2)) >> 1)) & 3) * 2)) + ((((v466 + ((~(((v468 ^ -1) | (-(v468 ^ -1))) >> 31)) & 2)) - (v469 + ((~(((v470 ^ -1) | (-(v470 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
      v488[v587] = v486;
      int * v490 = v426->cache_vals;
      int v590 = (((4 + ((((int)((unsigned int)((int)((unsigned int)v430 >> 2)) >> 1)) & 3) * 2)) + ((((v466 + ((~(((v468 ^ -1) | (-(v468 ^ -1))) >> 31)) & 2)) - (v469 + ((~(((v470 ^ -1) | (-(v470 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
      v490[v590] = v487;
      int * v492 = v426->cache_tags;
      int v593 = (int)((unsigned int)((int)((unsigned int)v430 >> 2)) >> 1);
      v492[v569] = v593;
      int * v494 = v426->cache_dirty;
      v494[v569] = 0;
      int * v496 = v426->cache_age;
      v496[v569] = 1;
      int * v498 = v426->cache_age;
      int v499 = v498[v569];
      int v500 = v498[v543];
      int v599 = v500 + ((int)((unsigned int)(v500 - v499) >> 31));
      v498[v543] = v599;
      int * v502 = v426->cache_age;
      int v503 = v502[v544];
      int v601 = v503 + ((int)((unsigned int)(v503 - v499) >> 31));
      v502[v544] = v601;
      int * v505 = v426->cache_age;
      v505[v569] = 0;
      v508 = v569;
    }
    int * v509 = v426->cache_vals;
    int v604 = v508 * 2;
    int v510 = v509[v604];
    int v605 = (v508 * 2) + 1;
    int v511 = v509[v605];
    int v606 = (((((int)((unsigned int)((int)((unsigned int)v430 >> 2)) >> 1)) & 1) * 2) + ((((v450 + ((~(((v452 ^ -1) | (-(v452 ^ -1))) >> 31)) & 2)) - (v453 + ((~(((v454 ^ -1) | (-(v454 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
    v509[v606] = v510;
    int * v513 = v426->cache_vals;
    int v609 = ((((((int)((unsigned int)((int)((unsigned int)v430 >> 2)) >> 1)) & 1) * 2) + ((((v450 + ((~(((v452 ^ -1) | (-(v452 ^ -1))) >> 31)) & 2)) - (v453 + ((~(((v454 ^ -1) | (-(v454 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
    v513[v609] = v511;
    int * v515 = v426->cache_tags;
    int v612 = ((((int)((unsigned int)((int)((unsigned int)v430 >> 2)) >> 1)) & 1) * 2) + ((((v450 + ((~(((v452 ^ -1) | (-(v452 ^ -1))) >> 31)) & 2)) - (v453 + ((~(((v454 ^ -1) | (-(v454 ^ -1))) >> 31)) & 2))) >> 31) & 1);
    int v613 = (int)((unsigned int)((int)((unsigned int)v430 >> 2)) >> 1);
    v515[v612] = v613;
    int * v517 = v426->cache_dirty;
    v517[v612] = 0;
    int * v519 = v426->cache_age;
    v519[v612] = 1;
    int * v521 = v426->cache_age;
    int v522 = v521[v612];
    int v523 = v521[v541];
    int v619 = v523 + ((int)((unsigned int)(v523 - v522) >> 31));
    v521[v541] = v619;
    int * v525 = v426->cache_age;
    int v526 = v525[v542];
    int v621 = v526 + ((int)((unsigned int)(v526 - v522) >> 31));
    v525[v542] = v621;
    int * v528 = v426->cache_age;
    v528[v612] = 0;
    v531 = v612;
  }
  int v624 = (v531 * 2) + (((int)((unsigned int)v430 >> 2)) & 1);
  int v532 = v438[v624];
  int * v533 = v426->regs;
  v533[7] = v532;
  struct StateT * v535 = slot_5(v426);
  return v535;
}

struct StateT * slot_18(struct StateT * v811) {
  int v812 = v811->timer;
  int v819 = v812 + 1;
  v811->timer = v819;
  int * v814 = v811->regs;
  int v815 = v814[8];
  int v822 = v815 + 1;
  v814[8] = v822;
  struct StateT * v817 = slot_19(v811);
  return v817;
}

struct StateT * slot_9(struct StateT * v685) {
  int v686 = v685->timer;
  int v693 = v686 + 1;
  v685->timer = v693;
  int * v688 = v685->regs;
  int v689 = v688[8];
  int v696 = v689 + 1;
  v688[8] = v696;
  struct StateT * v691 = slot_10(v685);
  return v691;
}

struct StateT * slot_183(struct StateT * v3121) {
  int v3122 = v3121->timer;
  int v3129 = v3122 + 1;
  v3121->timer = v3129;
  int * v3124 = v3121->regs;
  int v3125 = v3124[8];
  int v3132 = v3125 + 1;
  v3124[8] = v3132;
  struct StateT * v3127 = slot_184(v3121);
  return v3127;
}

struct StateT * slot_43(struct StateT * v1161) {
  int v1162 = v1161->timer;
  int v1169 = v1162 + 1;
  v1161->timer = v1169;
  int * v1164 = v1161->regs;
  int v1165 = v1164[8];
  int v1172 = v1165 + 1;
  v1164[8] = v1172;
  struct StateT * v1167 = slot_44(v1161);
  return v1167;
}

struct StateT * slot_70(struct StateT * v1539) {
  int v1540 = v1539->timer;
  int v1547 = v1540 + 1;
  v1539->timer = v1547;
  int * v1542 = v1539->regs;
  int v1543 = v1542[8];
  int v1550 = v1543 + 1;
  v1542[8] = v1550;
  struct StateT * v1545 = slot_71(v1539);
  return v1545;
}

struct StateT * slot_168(struct StateT * v2911) {
  int v2912 = v2911->timer;
  int v2919 = v2912 + 1;
  v2911->timer = v2919;
  int * v2914 = v2911->regs;
  int v2915 = v2914[8];
  int v2922 = v2915 + 1;
  v2914[8] = v2922;
  struct StateT * v2917 = slot_169(v2911);
  return v2917;
}

struct StateT * slot_76(struct StateT * v1623) {
  int v1624 = v1623->timer;
  int v1631 = v1624 + 1;
  v1623->timer = v1631;
  int * v1626 = v1623->regs;
  int v1627 = v1626[8];
  int v1634 = v1627 + 1;
  v1626[8] = v1634;
  struct StateT * v1629 = slot_77(v1623);
  return v1629;
}

struct StateT * slot_6(struct StateT * v643) {
  int v644 = v643->timer;
  int v651 = v644 + 1;
  v643->timer = v651;
  int * v646 = v643->regs;
  int v647 = v646[8];
  int v654 = v647 + 1;
  v646[8] = v654;
  struct StateT * v649 = slot_7(v643);
  return v649;
}

struct StateT * slot_225(struct StateT * v3709) {
  int v3710 = v3709->timer;
  int v3716 = v3710 + 1;
  v3709->timer = v3716;
  int * v3712 = v3709->regs;
  int v3713 = v3712[8];
  int v3719 = v3713 + 1;
  v3712[8] = v3719;
  return v3709;
}

struct StateT * slot_55(struct StateT * v1329) {
  int v1330 = v1329->timer;
  int v1337 = v1330 + 1;
  v1329->timer = v1337;
  int * v1332 = v1329->regs;
  int v1333 = v1332[8];
  int v1340 = v1333 + 1;
  v1332[8] = v1340;
  struct StateT * v1335 = slot_56(v1329);
  return v1335;
}

struct StateT * slot_213(struct StateT * v3541) {
  int v3542 = v3541->timer;
  int v3549 = v3542 + 1;
  v3541->timer = v3549;
  int * v3544 = v3541->regs;
  int v3545 = v3544[8];
  int v3552 = v3545 + 1;
  v3544[8] = v3552;
  struct StateT * v3547 = slot_214(v3541);
  return v3547;
}

struct StateT * slot_82(struct StateT * v1707) {
  int v1708 = v1707->timer;
  int v1715 = v1708 + 1;
  v1707->timer = v1715;
  int * v1710 = v1707->regs;
  int v1711 = v1710[8];
  int v1718 = v1711 + 1;
  v1710[8] = v1718;
  struct StateT * v1713 = slot_83(v1707);
  return v1713;
}

struct StateT * slot_161(struct StateT * v2813) {
  int v2814 = v2813->timer;
  int v2821 = v2814 + 1;
  v2813->timer = v2821;
  int * v2816 = v2813->regs;
  int v2817 = v2816[8];
  int v2824 = v2817 + 1;
  v2816[8] = v2824;
  struct StateT * v2819 = slot_162(v2813);
  return v2819;
}

struct StateT * slot_185(struct StateT * v3149) {
  int v3150 = v3149->timer;
  int v3157 = v3150 + 1;
  v3149->timer = v3157;
  int * v3152 = v3149->regs;
  int v3153 = v3152[8];
  int v3160 = v3153 + 1;
  v3152[8] = v3160;
  struct StateT * v3155 = slot_186(v3149);
  return v3155;
}

struct StateT * slot_91(struct StateT * v1833) {
  int v1834 = v1833->timer;
  int v1841 = v1834 + 1;
  v1833->timer = v1841;
  int * v1836 = v1833->regs;
  int v1837 = v1836[8];
  int v1844 = v1837 + 1;
  v1836[8] = v1844;
  struct StateT * v1839 = slot_92(v1833);
  return v1839;
}

struct StateT * slot_58(struct StateT * v1371) {
  int v1372 = v1371->timer;
  int v1379 = v1372 + 1;
  v1371->timer = v1379;
  int * v1374 = v1371->regs;
  int v1375 = v1374[8];
  int v1382 = v1375 + 1;
  v1374[8] = v1382;
  struct StateT * v1377 = slot_59(v1371);
  return v1377;
}

struct StateT * slot_89(struct StateT * v1805) {
  int v1806 = v1805->timer;
  int v1813 = v1806 + 1;
  v1805->timer = v1813;
  int * v1808 = v1805->regs;
  int v1809 = v1808[8];
  int v1816 = v1809 + 1;
  v1808[8] = v1816;
  struct StateT * v1811 = slot_90(v1805);
  return v1811;
}

struct StateT * slot_66(struct StateT * v1483) {
  int v1484 = v1483->timer;
  int v1491 = v1484 + 1;
  v1483->timer = v1491;
  int * v1486 = v1483->regs;
  int v1487 = v1486[8];
  int v1494 = v1487 + 1;
  v1486[8] = v1494;
  struct StateT * v1489 = slot_67(v1483);
  return v1489;
}

struct StateT * slot_140(struct StateT * v2519) {
  int v2520 = v2519->timer;
  int v2527 = v2520 + 1;
  v2519->timer = v2527;
  int * v2522 = v2519->regs;
  int v2523 = v2522[8];
  int v2530 = v2523 + 1;
  v2522[8] = v2530;
  struct StateT * v2525 = slot_141(v2519);
  return v2525;
}

struct StateT * slot_49(struct StateT * v1245) {
  int v1246 = v1245->timer;
  int v1253 = v1246 + 1;
  v1245->timer = v1253;
  int * v1248 = v1245->regs;
  int v1249 = v1248[8];
  int v1256 = v1249 + 1;
  v1248[8] = v1256;
  struct StateT * v1251 = slot_50(v1245);
  return v1251;
}

struct StateT * slot_216(struct StateT * v3583) {
  int v3584 = v3583->timer;
  int v3591 = v3584 + 1;
  v3583->timer = v3591;
  int * v3586 = v3583->regs;
  int v3587 = v3586[8];
  int v3594 = v3587 + 1;
  v3586[8] = v3594;
  struct StateT * v3589 = slot_217(v3583);
  return v3589;
}

struct StateT * slot_50(struct StateT * v1259) {
  int v1260 = v1259->timer;
  int v1267 = v1260 + 1;
  v1259->timer = v1267;
  int * v1262 = v1259->regs;
  int v1263 = v1262[8];
  int v1270 = v1263 + 1;
  v1262[8] = v1270;
  struct StateT * v1265 = slot_51(v1259);
  return v1265;
}

struct StateT * slot_37(struct StateT * v1077) {
  int v1078 = v1077->timer;
  int v1085 = v1078 + 1;
  v1077->timer = v1085;
  int * v1080 = v1077->regs;
  int v1081 = v1080[8];
  int v1088 = v1081 + 1;
  v1080[8] = v1088;
  struct StateT * v1083 = slot_38(v1077);
  return v1083;
}

struct StateT * slot_114(struct StateT * v2155) {
  int v2156 = v2155->timer;
  int v2163 = v2156 + 1;
  v2155->timer = v2163;
  int * v2158 = v2155->regs;
  int v2159 = v2158[8];
  int v2166 = v2159 + 1;
  v2158[8] = v2166;
  struct StateT * v2161 = slot_115(v2155);
  return v2161;
}

struct StateT * slot_135(struct StateT * v2449) {
  int v2450 = v2449->timer;
  int v2457 = v2450 + 1;
  v2449->timer = v2457;
  int * v2452 = v2449->regs;
  int v2453 = v2452[8];
  int v2460 = v2453 + 1;
  v2452[8] = v2460;
  struct StateT * v2455 = slot_136(v2449);
  return v2455;
}

struct StateT * slot_59(struct StateT * v1385) {
  int v1386 = v1385->timer;
  int v1393 = v1386 + 1;
  v1385->timer = v1393;
  int * v1388 = v1385->regs;
  int v1389 = v1388[8];
  int v1396 = v1389 + 1;
  v1388[8] = v1396;
  struct StateT * v1391 = slot_60(v1385);
  return v1391;
}

struct StateT * slot_192(struct StateT * v3247) {
  int v3248 = v3247->timer;
  int v3255 = v3248 + 1;
  v3247->timer = v3255;
  int * v3250 = v3247->regs;
  int v3251 = v3250[8];
  int v3258 = v3251 + 1;
  v3250[8] = v3258;
  struct StateT * v3253 = slot_193(v3247);
  return v3253;
}

struct StateT * slot_40(struct StateT * v1119) {
  int v1120 = v1119->timer;
  int v1127 = v1120 + 1;
  v1119->timer = v1127;
  int * v1122 = v1119->regs;
  int v1123 = v1122[8];
  int v1130 = v1123 + 1;
  v1122[8] = v1130;
  struct StateT * v1125 = slot_41(v1119);
  return v1125;
}

struct StateT * slot_48(struct StateT * v1231) {
  int v1232 = v1231->timer;
  int v1239 = v1232 + 1;
  v1231->timer = v1239;
  int * v1234 = v1231->regs;
  int v1235 = v1234[8];
  int v1242 = v1235 + 1;
  v1234[8] = v1242;
  struct StateT * v1237 = slot_49(v1231);
  return v1237;
}

struct StateT * slot_77(struct StateT * v1637) {
  int v1638 = v1637->timer;
  int v1645 = v1638 + 1;
  v1637->timer = v1645;
  int * v1640 = v1637->regs;
  int v1641 = v1640[8];
  int v1648 = v1641 + 1;
  v1640[8] = v1648;
  struct StateT * v1643 = slot_78(v1637);
  return v1643;
}

struct StateT * slot_85(struct StateT * v1749) {
  int v1750 = v1749->timer;
  int v1757 = v1750 + 1;
  v1749->timer = v1757;
  int * v1752 = v1749->regs;
  int v1753 = v1752[8];
  int v1760 = v1753 + 1;
  v1752[8] = v1760;
  struct StateT * v1755 = slot_86(v1749);
  return v1755;
}

struct StateT * slot_75(struct StateT * v1609) {
  int v1610 = v1609->timer;
  int v1617 = v1610 + 1;
  v1609->timer = v1617;
  int * v1612 = v1609->regs;
  int v1613 = v1612[8];
  int v1620 = v1613 + 1;
  v1612[8] = v1620;
  struct StateT * v1615 = slot_76(v1609);
  return v1615;
}

struct StateT * slot_72(struct StateT * v1567) {
  int v1568 = v1567->timer;
  int v1575 = v1568 + 1;
  v1567->timer = v1575;
  int * v1570 = v1567->regs;
  int v1571 = v1570[8];
  int v1578 = v1571 + 1;
  v1570[8] = v1578;
  struct StateT * v1573 = slot_73(v1567);
  return v1573;
}

struct StateT * slot_119(struct StateT * v2225) {
  int v2226 = v2225->timer;
  int v2233 = v2226 + 1;
  v2225->timer = v2233;
  int * v2228 = v2225->regs;
  int v2229 = v2228[8];
  int v2236 = v2229 + 1;
  v2228[8] = v2236;
  struct StateT * v2231 = slot_120(v2225);
  return v2231;
}

struct StateT * slot_71(struct StateT * v1553) {
  int v1554 = v1553->timer;
  int v1561 = v1554 + 1;
  v1553->timer = v1561;
  int * v1556 = v1553->regs;
  int v1557 = v1556[8];
  int v1564 = v1557 + 1;
  v1556[8] = v1564;
  struct StateT * v1559 = slot_72(v1553);
  return v1559;
}

struct StateT * slot_101(struct StateT * v1973) {
  int v1974 = v1973->timer;
  int v1981 = v1974 + 1;
  v1973->timer = v1981;
  int * v1976 = v1973->regs;
  int v1977 = v1976[8];
  int v1984 = v1977 + 1;
  v1976[8] = v1984;
  struct StateT * v1979 = slot_102(v1973);
  return v1979;
}

struct StateT * slot_108(struct StateT * v2071) {
  int v2072 = v2071->timer;
  int v2079 = v2072 + 1;
  v2071->timer = v2079;
  int * v2074 = v2071->regs;
  int v2075 = v2074[8];
  int v2082 = v2075 + 1;
  v2074[8] = v2082;
  struct StateT * v2077 = slot_109(v2071);
  return v2077;
}

struct StateT * slot_116(struct StateT * v2183) {
  int v2184 = v2183->timer;
  int v2191 = v2184 + 1;
  v2183->timer = v2191;
  int * v2186 = v2183->regs;
  int v2187 = v2186[8];
  int v2194 = v2187 + 1;
  v2186[8] = v2194;
  struct StateT * v2189 = slot_117(v2183);
  return v2189;
}

struct StateT * slot_93(struct StateT * v1861) {
  int v1862 = v1861->timer;
  int v1869 = v1862 + 1;
  v1861->timer = v1869;
  int * v1864 = v1861->regs;
  int v1865 = v1864[8];
  int v1872 = v1865 + 1;
  v1864[8] = v1872;
  struct StateT * v1867 = slot_94(v1861);
  return v1867;
}

struct StateT * slot_88(struct StateT * v1791) {
  int v1792 = v1791->timer;
  int v1799 = v1792 + 1;
  v1791->timer = v1799;
  int * v1794 = v1791->regs;
  int v1795 = v1794[8];
  int v1802 = v1795 + 1;
  v1794[8] = v1802;
  struct StateT * v1797 = slot_89(v1791);
  return v1797;
}

struct StateT * slot_96(struct StateT * v1903) {
  int v1904 = v1903->timer;
  int v1911 = v1904 + 1;
  v1903->timer = v1911;
  int * v1906 = v1903->regs;
  int v1907 = v1906[8];
  int v1914 = v1907 + 1;
  v1906[8] = v1914;
  struct StateT * v1909 = slot_97(v1903);
  return v1909;
}

struct StateT * slot_215(struct StateT * v3569) {
  int v3570 = v3569->timer;
  int v3577 = v3570 + 1;
  v3569->timer = v3577;
  int * v3572 = v3569->regs;
  int v3573 = v3572[8];
  int v3580 = v3573 + 1;
  v3572[8] = v3580;
  struct StateT * v3575 = slot_216(v3569);
  return v3575;
}

struct StateT * slot_45(struct StateT * v1189) {
  int v1190 = v1189->timer;
  int v1197 = v1190 + 1;
  v1189->timer = v1197;
  int * v1192 = v1189->regs;
  int v1193 = v1192[8];
  int v1200 = v1193 + 1;
  v1192[8] = v1200;
  struct StateT * v1195 = slot_46(v1189);
  return v1195;
}

struct StateT * slot_218(struct StateT * v3611) {
  int v3612 = v3611->timer;
  int v3619 = v3612 + 1;
  v3611->timer = v3619;
  int * v3614 = v3611->regs;
  int v3615 = v3614[8];
  int v3622 = v3615 + 1;
  v3614[8] = v3622;
  struct StateT * v3617 = slot_219(v3611);
  return v3617;
}

struct StateT * slot_220(struct StateT * v3639) {
  int v3640 = v3639->timer;
  int v3647 = v3640 + 1;
  v3639->timer = v3647;
  int * v3642 = v3639->regs;
  int v3643 = v3642[8];
  int v3650 = v3643 + 1;
  v3642[8] = v3650;
  struct StateT * v3645 = slot_221(v3639);
  return v3645;
}

struct StateT * slot_134(struct StateT * v2435) {
  int v2436 = v2435->timer;
  int v2443 = v2436 + 1;
  v2435->timer = v2443;
  int * v2438 = v2435->regs;
  int v2439 = v2438[8];
  int v2446 = v2439 + 1;
  v2438[8] = v2446;
  struct StateT * v2441 = slot_135(v2435);
  return v2441;
}

struct StateT * slot_175(struct StateT * v3009) {
  int v3010 = v3009->timer;
  int v3017 = v3010 + 1;
  v3009->timer = v3017;
  int * v3012 = v3009->regs;
  int v3013 = v3012[8];
  int v3020 = v3013 + 1;
  v3012[8] = v3020;
  struct StateT * v3015 = slot_176(v3009);
  return v3015;
}

struct StateT * slot_69(struct StateT * v1525) {
  int v1526 = v1525->timer;
  int v1533 = v1526 + 1;
  v1525->timer = v1533;
  int * v1528 = v1525->regs;
  int v1529 = v1528[8];
  int v1536 = v1529 + 1;
  v1528[8] = v1536;
  struct StateT * v1531 = slot_70(v1525);
  return v1531;
}

struct StateT * slot_202(struct StateT * v3387) {
  int v3388 = v3387->timer;
  int v3395 = v3388 + 1;
  v3387->timer = v3395;
  int * v3390 = v3387->regs;
  int v3391 = v3390[8];
  int v3398 = v3391 + 1;
  v3390[8] = v3398;
  struct StateT * v3393 = slot_203(v3387);
  return v3393;
}

struct StateT * slot_188(struct StateT * v3191) {
  int v3192 = v3191->timer;
  int v3199 = v3192 + 1;
  v3191->timer = v3199;
  int * v3194 = v3191->regs;
  int v3195 = v3194[8];
  int v3202 = v3195 + 1;
  v3194[8] = v3202;
  struct StateT * v3197 = slot_189(v3191);
  return v3197;
}

struct StateT * slot_138(struct StateT * v2491) {
  int v2492 = v2491->timer;
  int v2499 = v2492 + 1;
  v2491->timer = v2499;
  int * v2494 = v2491->regs;
  int v2495 = v2494[8];
  int v2502 = v2495 + 1;
  v2494[8] = v2502;
  struct StateT * v2497 = slot_139(v2491);
  return v2497;
}

struct StateT * slot_186(struct StateT * v3163) {
  int v3164 = v3163->timer;
  int v3171 = v3164 + 1;
  v3163->timer = v3171;
  int * v3166 = v3163->regs;
  int v3167 = v3166[8];
  int v3174 = v3167 + 1;
  v3166[8] = v3174;
  struct StateT * v3169 = slot_187(v3163);
  return v3169;
}

struct StateT * slot_102(struct StateT * v1987) {
  int v1988 = v1987->timer;
  int v1995 = v1988 + 1;
  v1987->timer = v1995;
  int * v1990 = v1987->regs;
  int v1991 = v1990[8];
  int v1998 = v1991 + 1;
  v1990[8] = v1998;
  struct StateT * v1993 = slot_103(v1987);
  return v1993;
}

struct StateT * slot_145(struct StateT * v2589) {
  int v2590 = v2589->timer;
  int v2597 = v2590 + 1;
  v2589->timer = v2597;
  int * v2592 = v2589->regs;
  int v2593 = v2592[8];
  int v2600 = v2593 + 1;
  v2592[8] = v2600;
  struct StateT * v2595 = slot_146(v2589);
  return v2595;
}

struct StateT * slot_110(struct StateT * v2099) {
  int v2100 = v2099->timer;
  int v2107 = v2100 + 1;
  v2099->timer = v2107;
  int * v2102 = v2099->regs;
  int v2103 = v2102[8];
  int v2110 = v2103 + 1;
  v2102[8] = v2110;
  struct StateT * v2105 = slot_111(v2099);
  return v2105;
}

struct StateT * slot_196(struct StateT * v3303) {
  int v3304 = v3303->timer;
  int v3311 = v3304 + 1;
  v3303->timer = v3311;
  int * v3306 = v3303->regs;
  int v3307 = v3306[8];
  int v3314 = v3307 + 1;
  v3306[8] = v3314;
  struct StateT * v3309 = slot_197(v3303);
  return v3309;
}

struct StateT * slot_208(struct StateT * v3471) {
  int v3472 = v3471->timer;
  int v3479 = v3472 + 1;
  v3471->timer = v3479;
  int * v3474 = v3471->regs;
  int v3475 = v3474[8];
  int v3482 = v3475 + 1;
  v3474[8] = v3482;
  struct StateT * v3477 = slot_209(v3471);
  return v3477;
}

struct StateT * slot_172(struct StateT * v2967) {
  int v2968 = v2967->timer;
  int v2975 = v2968 + 1;
  v2967->timer = v2975;
  int * v2970 = v2967->regs;
  int v2971 = v2970[8];
  int v2978 = v2971 + 1;
  v2970[8] = v2978;
  struct StateT * v2973 = slot_173(v2967);
  return v2973;
}

struct StateT * slot_131(struct StateT * v2393) {
  int v2394 = v2393->timer;
  int v2401 = v2394 + 1;
  v2393->timer = v2401;
  int * v2396 = v2393->regs;
  int v2397 = v2396[8];
  int v2404 = v2397 + 1;
  v2396[8] = v2404;
  struct StateT * v2399 = slot_132(v2393);
  return v2399;
}

struct StateT * slot_8(struct StateT * v671) {
  int v672 = v671->timer;
  int v679 = v672 + 1;
  v671->timer = v679;
  int * v674 = v671->regs;
  int v675 = v674[8];
  int v682 = v675 + 1;
  v674[8] = v682;
  struct StateT * v677 = slot_9(v671);
  return v677;
}

struct StateT * slot_180(struct StateT * v3079) {
  int v3080 = v3079->timer;
  int v3087 = v3080 + 1;
  v3079->timer = v3087;
  int * v3082 = v3079->regs;
  int v3083 = v3082[8];
  int v3090 = v3083 + 1;
  v3082[8] = v3090;
  struct StateT * v3085 = slot_181(v3079);
  return v3085;
}

struct StateT * slot_203(struct StateT * v3401) {
  int v3402 = v3401->timer;
  int v3409 = v3402 + 1;
  v3401->timer = v3409;
  int * v3404 = v3401->regs;
  int v3405 = v3404[8];
  int v3412 = v3405 + 1;
  v3404[8] = v3412;
  struct StateT * v3407 = slot_204(v3401);
  return v3407;
}

struct StateT * slot_190(struct StateT * v3219) {
  int v3220 = v3219->timer;
  int v3227 = v3220 + 1;
  v3219->timer = v3227;
  int * v3222 = v3219->regs;
  int v3223 = v3222[8];
  int v3230 = v3223 + 1;
  v3222[8] = v3230;
  struct StateT * v3225 = slot_191(v3219);
  return v3225;
}

struct StateT * slot_157(struct StateT * v2757) {
  int v2758 = v2757->timer;
  int v2765 = v2758 + 1;
  v2757->timer = v2765;
  int * v2760 = v2757->regs;
  int v2761 = v2760[8];
  int v2768 = v2761 + 1;
  v2760[8] = v2768;
  struct StateT * v2763 = slot_158(v2757);
  return v2763;
}

struct StateT * slot_200(struct StateT * v3359) {
  int v3360 = v3359->timer;
  int v3367 = v3360 + 1;
  v3359->timer = v3367;
  int * v3362 = v3359->regs;
  int v3363 = v3362[8];
  int v3370 = v3363 + 1;
  v3362[8] = v3370;
  struct StateT * v3365 = slot_201(v3359);
  return v3365;
}

struct StateT * slot_173(struct StateT * v2981) {
  int v2982 = v2981->timer;
  int v2989 = v2982 + 1;
  v2981->timer = v2989;
  int * v2984 = v2981->regs;
  int v2985 = v2984[8];
  int v2992 = v2985 + 1;
  v2984[8] = v2992;
  struct StateT * v2987 = slot_174(v2981);
  return v2987;
}

struct StateT * slot_149(struct StateT * v2645) {
  int v2646 = v2645->timer;
  int v2653 = v2646 + 1;
  v2645->timer = v2653;
  int * v2648 = v2645->regs;
  int v2649 = v2648[8];
  int v2656 = v2649 + 1;
  v2648[8] = v2656;
  struct StateT * v2651 = slot_150(v2645);
  return v2651;
}

struct StateT * slot_5(struct StateT * v630) {
  int v631 = v630->timer;
  int v637 = v631 + 1;
  v630->timer = v637;
  int * v633 = v630->regs;
  v633[8] = 0;
  struct StateT * v635 = slot_6(v630);
  return v635;
}

struct StateT * slot_104(struct StateT * v2015) {
  int v2016 = v2015->timer;
  int v2023 = v2016 + 1;
  v2015->timer = v2023;
  int * v2018 = v2015->regs;
  int v2019 = v2018[8];
  int v2026 = v2019 + 1;
  v2018[8] = v2026;
  struct StateT * v2021 = slot_105(v2015);
  return v2021;
}

struct StateT * slot_54(struct StateT * v1315) {
  int v1316 = v1315->timer;
  int v1323 = v1316 + 1;
  v1315->timer = v1323;
  int * v1318 = v1315->regs;
  int v1319 = v1318[8];
  int v1326 = v1319 + 1;
  v1318[8] = v1326;
  struct StateT * v1321 = slot_55(v1315);
  return v1321;
}

struct StateT * slot_26(struct StateT * v923) {
  int v924 = v923->timer;
  int v931 = v924 + 1;
  v923->timer = v931;
  int * v926 = v923->regs;
  int v927 = v926[8];
  int v934 = v927 + 1;
  v926[8] = v934;
  struct StateT * v929 = slot_27(v923);
  return v929;
}

struct StateT * slot_206(struct StateT * v3443) {
  int v3444 = v3443->timer;
  int v3451 = v3444 + 1;
  v3443->timer = v3451;
  int * v3446 = v3443->regs;
  int v3447 = v3446[8];
  int v3454 = v3447 + 1;
  v3446[8] = v3454;
  struct StateT * v3449 = slot_207(v3443);
  return v3449;
}

struct StateT * slot_169(struct StateT * v2925) {
  int v2926 = v2925->timer;
  int v2933 = v2926 + 1;
  v2925->timer = v2933;
  int * v2928 = v2925->regs;
  int v2929 = v2928[8];
  int v2936 = v2929 + 1;
  v2928[8] = v2936;
  struct StateT * v2931 = slot_170(v2925);
  return v2931;
}

struct StateT * slot_64(struct StateT * v1455) {
  int v1456 = v1455->timer;
  int v1463 = v1456 + 1;
  v1455->timer = v1463;
  int * v1458 = v1455->regs;
  int v1459 = v1458[8];
  int v1466 = v1459 + 1;
  v1458[8] = v1466;
  struct StateT * v1461 = slot_65(v1455);
  return v1461;
}

struct StateT * slot_170(struct StateT * v2939) {
  int v2940 = v2939->timer;
  int v2947 = v2940 + 1;
  v2939->timer = v2947;
  int * v2942 = v2939->regs;
  int v2943 = v2942[8];
  int v2950 = v2943 + 1;
  v2942[8] = v2950;
  struct StateT * v2945 = slot_171(v2939);
  return v2945;
}

struct StateT * slot_14(struct StateT * v755) {
  int v756 = v755->timer;
  int v763 = v756 + 1;
  v755->timer = v763;
  int * v758 = v755->regs;
  int v759 = v758[8];
  int v766 = v759 + 1;
  v758[8] = v766;
  struct StateT * v761 = slot_15(v755);
  return v761;
}

struct StateT * slot_53(struct StateT * v1301) {
  int v1302 = v1301->timer;
  int v1309 = v1302 + 1;
  v1301->timer = v1309;
  int * v1304 = v1301->regs;
  int v1305 = v1304[8];
  int v1312 = v1305 + 1;
  v1304[8] = v1312;
  struct StateT * v1307 = slot_54(v1301);
  return v1307;
}

struct StateT * slot_80(struct StateT * v1679) {
  int v1680 = v1679->timer;
  int v1687 = v1680 + 1;
  v1679->timer = v1687;
  int * v1682 = v1679->regs;
  int v1683 = v1682[8];
  int v1690 = v1683 + 1;
  v1682[8] = v1690;
  struct StateT * v1685 = slot_81(v1679);
  return v1685;
}

struct StateT * slot_44(struct StateT * v1175) {
  int v1176 = v1175->timer;
  int v1183 = v1176 + 1;
  v1175->timer = v1183;
  int * v1178 = v1175->regs;
  int v1179 = v1178[8];
  int v1186 = v1179 + 1;
  v1178[8] = v1186;
  struct StateT * v1181 = slot_45(v1175);
  return v1181;
}

struct StateT * slot_137(struct StateT * v2477) {
  int v2478 = v2477->timer;
  int v2485 = v2478 + 1;
  v2477->timer = v2485;
  int * v2480 = v2477->regs;
  int v2481 = v2480[8];
  int v2488 = v2481 + 1;
  v2480[8] = v2488;
  struct StateT * v2483 = slot_138(v2477);
  return v2483;
}

struct StateT * slot_122(struct StateT * v2267) {
  int v2268 = v2267->timer;
  int v2275 = v2268 + 1;
  v2267->timer = v2275;
  int * v2270 = v2267->regs;
  int v2271 = v2270[8];
  int v2278 = v2271 + 1;
  v2270[8] = v2278;
  struct StateT * v2273 = slot_123(v2267);
  return v2273;
}

struct StateT * slot_99(struct StateT * v1945) {
  int v1946 = v1945->timer;
  int v1953 = v1946 + 1;
  v1945->timer = v1953;
  int * v1948 = v1945->regs;
  int v1949 = v1948[8];
  int v1956 = v1949 + 1;
  v1948[8] = v1956;
  struct StateT * v1951 = slot_100(v1945);
  return v1951;
}

struct StateT * slot_179(struct StateT * v3065) {
  int v3066 = v3065->timer;
  int v3073 = v3066 + 1;
  v3065->timer = v3073;
  int * v3068 = v3065->regs;
  int v3069 = v3068[8];
  int v3076 = v3069 + 1;
  v3068[8] = v3076;
  struct StateT * v3071 = slot_180(v3065);
  return v3071;
}

struct StateT * slot_219(struct StateT * v3625) {
  int v3626 = v3625->timer;
  int v3633 = v3626 + 1;
  v3625->timer = v3633;
  int * v3628 = v3625->regs;
  int v3629 = v3628[8];
  int v3636 = v3629 + 1;
  v3628[8] = v3636;
  struct StateT * v3631 = slot_220(v3625);
  return v3631;
}

struct StateT * slot_36(struct StateT * v1063) {
  int v1064 = v1063->timer;
  int v1071 = v1064 + 1;
  v1063->timer = v1071;
  int * v1066 = v1063->regs;
  int v1067 = v1066[8];
  int v1074 = v1067 + 1;
  v1066[8] = v1074;
  struct StateT * v1069 = slot_37(v1063);
  return v1069;
}

struct StateT * slot_57(struct StateT * v1357) {
  int v1358 = v1357->timer;
  int v1365 = v1358 + 1;
  v1357->timer = v1365;
  int * v1360 = v1357->regs;
  int v1361 = v1360[8];
  int v1368 = v1361 + 1;
  v1360[8] = v1368;
  struct StateT * v1363 = slot_58(v1357);
  return v1363;
}

struct StateT * slot_62(struct StateT * v1427) {
  int v1428 = v1427->timer;
  int v1435 = v1428 + 1;
  v1427->timer = v1435;
  int * v1430 = v1427->regs;
  int v1431 = v1430[8];
  int v1438 = v1431 + 1;
  v1430[8] = v1438;
  struct StateT * v1433 = slot_63(v1427);
  return v1433;
}

struct StateT * slot_22(struct StateT * v867) {
  int v868 = v867->timer;
  int v875 = v868 + 1;
  v867->timer = v875;
  int * v870 = v867->regs;
  int v871 = v870[8];
  int v878 = v871 + 1;
  v870[8] = v878;
  struct StateT * v873 = slot_23(v867);
  return v873;
}

struct StateT * slot_139(struct StateT * v2505) {
  int v2506 = v2505->timer;
  int v2513 = v2506 + 1;
  v2505->timer = v2513;
  int * v2508 = v2505->regs;
  int v2509 = v2508[8];
  int v2516 = v2509 + 1;
  v2508[8] = v2516;
  struct StateT * v2511 = slot_140(v2505);
  return v2511;
}

struct StateT * slot_221(struct StateT * v3653) {
  int v3654 = v3653->timer;
  int v3661 = v3654 + 1;
  v3653->timer = v3661;
  int * v3656 = v3653->regs;
  int v3657 = v3656[8];
  int v3664 = v3657 + 1;
  v3656[8] = v3664;
  struct StateT * v3659 = slot_222(v3653);
  return v3659;
}

struct StateT * slot_23(struct StateT * v881) {
  int v882 = v881->timer;
  int v889 = v882 + 1;
  v881->timer = v889;
  int * v884 = v881->regs;
  int v885 = v884[8];
  int v892 = v885 + 1;
  v884[8] = v892;
  struct StateT * v887 = slot_24(v881);
  return v887;
}

struct StateT * slot_153(struct StateT * v2701) {
  int v2702 = v2701->timer;
  int v2709 = v2702 + 1;
  v2701->timer = v2709;
  int * v2704 = v2701->regs;
  int v2705 = v2704[8];
  int v2712 = v2705 + 1;
  v2704[8] = v2712;
  struct StateT * v2707 = slot_154(v2701);
  return v2707;
}

struct StateT * slot_2(struct StateT * v398) {
  int v399 = v398->timer;
  int v406 = v399 + 1;
  v398->timer = v406;
  int * v401 = v398->regs;
  int v402 = v401[6];
  int v409 = v402 & 7;
  v401[6] = v409;
  struct StateT * v404 = slot_3(v398);
  return v404;
}

struct StateT * slot_86(struct StateT * v1763) {
  int v1764 = v1763->timer;
  int v1771 = v1764 + 1;
  v1763->timer = v1771;
  int * v1766 = v1763->regs;
  int v1767 = v1766[8];
  int v1774 = v1767 + 1;
  v1766[8] = v1774;
  struct StateT * v1769 = slot_87(v1763);
  return v1769;
}

struct StateT * slot_129(struct StateT * v2365) {
  int v2366 = v2365->timer;
  int v2373 = v2366 + 1;
  v2365->timer = v2373;
  int * v2368 = v2365->regs;
  int v2369 = v2368[8];
  int v2376 = v2369 + 1;
  v2368[8] = v2376;
  struct StateT * v2371 = slot_130(v2365);
  return v2371;
}

struct StateT * slot_158(struct StateT * v2771) {
  int v2772 = v2771->timer;
  int v2779 = v2772 + 1;
  v2771->timer = v2779;
  int * v2774 = v2771->regs;
  int v2775 = v2774[8];
  int v2782 = v2775 + 1;
  v2774[8] = v2782;
  struct StateT * v2777 = slot_159(v2771);
  return v2777;
}

struct StateT * slot_100(struct StateT * v1959) {
  int v1960 = v1959->timer;
  int v1967 = v1960 + 1;
  v1959->timer = v1967;
  int * v1962 = v1959->regs;
  int v1963 = v1962[8];
  int v1970 = v1963 + 1;
  v1962[8] = v1970;
  struct StateT * v1965 = slot_101(v1959);
  return v1965;
}

struct StateT * slot_127(struct StateT * v2337) {
  int v2338 = v2337->timer;
  int v2345 = v2338 + 1;
  v2337->timer = v2345;
  int * v2340 = v2337->regs;
  int v2341 = v2340[8];
  int v2348 = v2341 + 1;
  v2340[8] = v2348;
  struct StateT * v2343 = slot_128(v2337);
  return v2343;
}

struct StateT * slot_217(struct StateT * v3597) {
  int v3598 = v3597->timer;
  int v3605 = v3598 + 1;
  v3597->timer = v3605;
  int * v3600 = v3597->regs;
  int v3601 = v3600[8];
  int v3608 = v3601 + 1;
  v3600[8] = v3608;
  struct StateT * v3603 = slot_218(v3597);
  return v3603;
}

struct StateT * slot_13(struct StateT * v741) {
  int v742 = v741->timer;
  int v749 = v742 + 1;
  v741->timer = v749;
  int * v744 = v741->regs;
  int v745 = v744[8];
  int v752 = v745 + 1;
  v744[8] = v752;
  struct StateT * v747 = slot_14(v741);
  return v747;
}

struct StateT * slot_111(struct StateT * v2113) {
  int v2114 = v2113->timer;
  int v2121 = v2114 + 1;
  v2113->timer = v2121;
  int * v2116 = v2113->regs;
  int v2117 = v2116[8];
  int v2124 = v2117 + 1;
  v2116[8] = v2124;
  struct StateT * v2119 = slot_112(v2113);
  return v2119;
}

struct StateT * slot_109(struct StateT * v2085) {
  int v2086 = v2085->timer;
  int v2093 = v2086 + 1;
  v2085->timer = v2093;
  int * v2088 = v2085->regs;
  int v2089 = v2088[8];
  int v2096 = v2089 + 1;
  v2088[8] = v2096;
  struct StateT * v2091 = slot_110(v2085);
  return v2091;
}

struct StateT * slot_174(struct StateT * v2995) {
  int v2996 = v2995->timer;
  int v3003 = v2996 + 1;
  v2995->timer = v3003;
  int * v2998 = v2995->regs;
  int v2999 = v2998[8];
  int v3006 = v2999 + 1;
  v2998[8] = v3006;
  struct StateT * v3001 = slot_175(v2995);
  return v3001;
}

struct StateT * slot_147(struct StateT * v2617) {
  int v2618 = v2617->timer;
  int v2625 = v2618 + 1;
  v2617->timer = v2625;
  int * v2620 = v2617->regs;
  int v2621 = v2620[8];
  int v2628 = v2621 + 1;
  v2620[8] = v2628;
  struct StateT * v2623 = slot_148(v2617);
  return v2623;
}

struct StateT * slot_42(struct StateT * v1147) {
  int v1148 = v1147->timer;
  int v1155 = v1148 + 1;
  v1147->timer = v1155;
  int * v1150 = v1147->regs;
  int v1151 = v1150[8];
  int v1158 = v1151 + 1;
  v1150[8] = v1158;
  struct StateT * v1153 = slot_43(v1147);
  return v1153;
}

struct StateT * slot_224(struct StateT * v3695) {
  int v3696 = v3695->timer;
  int v3703 = v3696 + 1;
  v3695->timer = v3703;
  int * v3698 = v3695->regs;
  int v3699 = v3698[8];
  int v3706 = v3699 + 1;
  v3698[8] = v3706;
  struct StateT * v3701 = slot_225(v3695);
  return v3701;
}

struct StateT * slot_163(struct StateT * v2841) {
  int v2842 = v2841->timer;
  int v2849 = v2842 + 1;
  v2841->timer = v2849;
  int * v2844 = v2841->regs;
  int v2845 = v2844[8];
  int v2852 = v2845 + 1;
  v2844[8] = v2852;
  struct StateT * v2847 = slot_164(v2841);
  return v2847;
}

struct StateT * slot_184(struct StateT * v3135) {
  int v3136 = v3135->timer;
  int v3143 = v3136 + 1;
  v3135->timer = v3143;
  int * v3138 = v3135->regs;
  int v3139 = v3138[8];
  int v3146 = v3139 + 1;
  v3138[8] = v3146;
  struct StateT * v3141 = slot_185(v3135);
  return v3141;
}

struct StateT * slot_204(struct StateT * v3415) {
  int v3416 = v3415->timer;
  int v3423 = v3416 + 1;
  v3415->timer = v3423;
  int * v3418 = v3415->regs;
  int v3419 = v3418[8];
  int v3426 = v3419 + 1;
  v3418[8] = v3426;
  struct StateT * v3421 = slot_205(v3415);
  return v3421;
}

struct StateT * slot_194(struct StateT * v3275) {
  int v3276 = v3275->timer;
  int v3283 = v3276 + 1;
  v3275->timer = v3283;
  int * v3278 = v3275->regs;
  int v3279 = v3278[8];
  int v3286 = v3279 + 1;
  v3278[8] = v3286;
  struct StateT * v3281 = slot_195(v3275);
  return v3281;
}

struct StateT * slot_165(struct StateT * v2869) {
  int v2870 = v2869->timer;
  int v2877 = v2870 + 1;
  v2869->timer = v2877;
  int * v2872 = v2869->regs;
  int v2873 = v2872[8];
  int v2880 = v2873 + 1;
  v2872[8] = v2880;
  struct StateT * v2875 = slot_166(v2869);
  return v2875;
}

struct StateT * snippet(struct StateT * v0) {
  struct StateT * v1 = slot_0(v0);
  return v1;
}

struct StateT * slot_117(struct StateT * v2197) {
  int v2198 = v2197->timer;
  int v2205 = v2198 + 1;
  v2197->timer = v2205;
  int * v2200 = v2197->regs;
  int v2201 = v2200[8];
  int v2208 = v2201 + 1;
  v2200[8] = v2208;
  struct StateT * v2203 = slot_118(v2197);
  return v2203;
}

struct StateT * slot_90(struct StateT * v1819) {
  int v1820 = v1819->timer;
  int v1827 = v1820 + 1;
  v1819->timer = v1827;
  int * v1822 = v1819->regs;
  int v1823 = v1822[8];
  int v1830 = v1823 + 1;
  v1822[8] = v1830;
  struct StateT * v1825 = slot_91(v1819);
  return v1825;
}

struct StateT * slot_11(struct StateT * v713) {
  int v714 = v713->timer;
  int v721 = v714 + 1;
  v713->timer = v721;
  int * v716 = v713->regs;
  int v717 = v716[8];
  int v724 = v717 + 1;
  v716[8] = v724;
  struct StateT * v719 = slot_12(v713);
  return v719;
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