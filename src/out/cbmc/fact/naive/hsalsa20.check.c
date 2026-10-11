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

struct StateT * slot_12(struct StateT * v219);
struct StateT * slot_143(struct StateT * v2632);
struct StateT * slot_120(struct StateT * v2275);
struct StateT * slot_167(struct StateT * v3004);
struct StateT * slot_152(struct StateT * v2770);
struct StateT * slot_199(struct StateT * v716);
struct StateT * slot_92(struct StateT * v1834);
struct StateT * slot_31(struct StateT * v539);
struct StateT * slot_160(struct StateT * v2899);
struct StateT * slot_65(struct StateT * v1413);
struct StateT * slot_10(struct StateT * v187);
struct StateT * slot_150(struct StateT * v2738);
struct StateT * slot_74(struct StateT * v1555);
struct StateT * slot_107(struct StateT * v2068);
struct StateT * slot_136(struct StateT * v2525);
struct StateT * slot_84(struct StateT * v1711);
struct StateT * slot_28(struct StateT * v497);
struct StateT * slot_155(struct StateT * v2820);
struct StateT * slot_177(struct StateT * v3166);
struct StateT * slot_17(struct StateT * v314);
struct StateT * slot_181(struct StateT * v3226);
struct StateT * slot_197(struct StateT * v644);
struct StateT * slot_207(struct StateT * v987);
struct StateT * slot_156(struct StateT * v2837);
struct StateT * slot_154(struct StateT * v2803);
struct StateT * slot_68(struct StateT * v1458);
struct StateT * slot_105(struct StateT * v2037);
struct StateT * slot_27(struct StateT * v482);
struct StateT * slot_164(struct StateT * v2959);
struct StateT * slot_15(struct StateT * v276);
struct StateT * slot_133(struct StateT * v2474);
struct StateT * slot_56(struct StateT * v1277);
struct StateT * slot_34(struct StateT * v627);
struct StateT * slot_171(struct StateT * v3066);
struct StateT * slot_162(struct StateT * v2928);
struct StateT * slot_21(struct StateT * v390);
struct StateT * slot_118(struct StateT * v2245);
struct StateT * slot_121(struct StateT * v2290);
struct StateT * slot_144(struct StateT * v2647);
struct StateT * slot_201(struct StateT * v783);
struct StateT * slot_94(struct StateT * v1867);
struct StateT * slot_63(struct StateT * v1384);
struct StateT * slot_146(struct StateT * v2677);
struct StateT * slot_24(struct StateT * v441);
struct StateT * slot_0(struct StateT * v2);
struct StateT * slot_195(struct StateT * v572);
struct StateT * slot_125(struct StateT * v2349);
struct StateT * slot_148(struct StateT * v2706);
struct StateT * slot_126(struct StateT * v2365);
struct StateT * slot_79(struct StateT * v1635);
struct StateT * slot_41(struct StateT * v871);
struct StateT * slot_39(struct StateT * v802);
struct StateT * slot_142(struct StateT * v2616);
struct StateT * slot_60(struct StateT * v1339);
struct StateT * slot_112(struct StateT * v2146);
struct StateT * slot_47(struct StateT * v1075);
struct StateT * slot_29(struct StateT * v512);
struct StateT * slot_16(struct StateT * v295);
struct StateT * slot_113(struct StateT * v2162);
struct StateT * slot_151(struct StateT * v2754);
struct StateT * slot_7(struct StateT * v130);
struct StateT * slot_124(struct StateT * v2335);
struct StateT * slot_191(struct StateT * v3378);
struct StateT * slot_103(struct StateT * v2008);
struct StateT * slot_128(struct StateT * v2394);
struct StateT * slot_19(struct StateT * v352);
struct StateT * slot_87(struct StateT * v1756);
struct StateT * slot_67(struct StateT * v1444);
struct StateT * slot_81(struct StateT * v1666);
struct StateT * slot_95(struct StateT * v1884);
struct StateT * slot_115(struct StateT * v2196);
struct StateT * slot_78(struct StateT * v1621);
struct StateT * slot_32(struct StateT * v552);
struct StateT * slot_205(struct StateT * v920);
struct StateT * slot_193(struct StateT * v3410);
struct StateT * slot_176(struct StateT * v3149);
struct StateT * slot_189(struct StateT * v3346);
struct StateT * slot_33(struct StateT * v591);
struct StateT * slot_35(struct StateT * v663);
struct StateT * slot_210(struct StateT * v1089);
struct StateT * slot_166(struct StateT * v2989);
struct StateT * slot_51(struct StateT * v1194);
struct StateT * slot_52(struct StateT * v1210);
struct StateT * slot_83(struct StateT * v1696);
struct StateT * slot_25(struct StateT * v454);
struct StateT * slot_209(struct StateT * v1056);
struct StateT * slot_3(struct StateT * v54);
struct StateT * slot_123(struct StateT * v2320);
struct StateT * slot_73(struct StateT * v1538);
struct StateT * slot_198(struct StateT * v680);
struct StateT * slot_1(struct StateT * v16);
struct StateT * slot_187(struct StateT * v3316);
struct StateT * slot_97(struct StateT * v1918);
struct StateT * slot_182(struct StateT * v3240);
struct StateT * slot_38(struct StateT * v769);
struct StateT * slot_178(struct StateT * v3181);
struct StateT * slot_106(struct StateT * v2053);
struct StateT * slot_98(struct StateT * v1933);
struct StateT * slot_159(struct StateT * v2883);
struct StateT * slot_46(struct StateT * v1041);
struct StateT * slot_212(struct StateT * v1159);
struct StateT * slot_132(struct StateT * v2458);
struct StateT * slot_130(struct StateT * v2426);
struct StateT * slot_211(struct StateT * v1124);
struct StateT * slot_20(struct StateT * v371);
struct StateT * slot_141(struct StateT * v2602);
struct StateT * slot_61(struct StateT * v1354);
struct StateT * slot_30(struct StateT * v525);
struct StateT * slot_4(struct StateT * v73);
struct StateT * slot_18(struct StateT * v333);
struct StateT * slot_9(struct StateT * v168);
struct StateT * slot_183(struct StateT * v3256);
struct StateT * slot_43(struct StateT * v939);
struct StateT * slot_70(struct StateT * v1490);
struct StateT * slot_168(struct StateT * v3018);
struct StateT * slot_76(struct StateT * v1589);
struct StateT * slot_6(struct StateT * v111);
struct StateT * slot_55(struct StateT * v1260);
struct StateT * slot_213(struct StateT * v1189);
struct StateT * slot_82(struct StateT * v1680);
struct StateT * slot_161(struct StateT * v2914);
struct StateT * slot_185(struct StateT * v3285);
struct StateT * slot_91(struct StateT * v1818);
struct StateT * slot_58(struct StateT * v1309);
struct StateT * slot_89(struct StateT * v1786);
struct StateT * slot_66(struct StateT * v1429);
struct StateT * slot_140(struct StateT * v2587);
struct StateT * slot_49(struct StateT * v1143);
struct StateT * slot_50(struct StateT * v1173);
struct StateT * slot_37(struct StateT * v735);
struct StateT * slot_114(struct StateT * v2179);
struct StateT * slot_135(struct StateT * v2508);
struct StateT * slot_59(struct StateT * v1323);
struct StateT * slot_192(struct StateT * v3394);
struct StateT * slot_40(struct StateT * v837);
struct StateT * slot_48(struct StateT * v1108);
struct StateT * slot_77(struct StateT * v1606);
struct StateT * slot_85(struct StateT * v1725);
struct StateT * slot_75(struct StateT * v1572);
struct StateT * slot_72(struct StateT * v1522);
struct StateT * slot_119(struct StateT * v2259);
struct StateT * slot_71(struct StateT * v1506);
struct StateT * slot_101(struct StateT * v1978);
struct StateT * slot_108(struct StateT * v2082);
struct StateT * slot_116(struct StateT * v2213);
struct StateT * slot_93(struct StateT * v1850);
struct StateT * slot_88(struct StateT * v1770);
struct StateT * slot_96(struct StateT * v1901);
struct StateT * slot_45(struct StateT * v1006);
struct StateT * slot_134(struct StateT * v2491);
struct StateT * slot_175(struct StateT * v3132);
struct StateT * slot_69(struct StateT * v1474);
struct StateT * slot_202(struct StateT * v818);
struct StateT * slot_188(struct StateT * v3330);
struct StateT * slot_138(struct StateT * v2557);
struct StateT * slot_186(struct StateT * v3301);
struct StateT * slot_102(struct StateT * v1992);
struct StateT * slot_145(struct StateT * v2661);
struct StateT * slot_110(struct StateT * v2114);
struct StateT * slot_196(struct StateT * v608);
struct StateT * slot_208(struct StateT * v1022);
struct StateT * slot_172(struct StateT * v3082);
struct StateT * slot_131(struct StateT * v2442);
struct StateT * slot_8(struct StateT * v149);
struct StateT * slot_180(struct StateT * v3211);
struct StateT * slot_203(struct StateT * v852);
struct StateT * slot_190(struct StateT * v3362);
struct StateT * slot_157(struct StateT * v2854);
struct StateT * slot_200(struct StateT * v750);
struct StateT * slot_173(struct StateT * v3098);
struct StateT * slot_149(struct StateT * v2722);
struct StateT * slot_5(struct StateT * v92);
struct StateT * slot_104(struct StateT * v2023);
struct StateT * slot_54(struct StateT * v1243);
struct StateT * slot_26(struct StateT * v467);
struct StateT * slot_206(struct StateT * v954);
struct StateT * slot_169(struct StateT * v3034);
struct StateT * slot_64(struct StateT * v1399);
struct StateT * slot_170(struct StateT * v3050);
struct StateT * slot_14(struct StateT * v257);
struct StateT * slot_53(struct StateT * v1226);
struct StateT * slot_80(struct StateT * v1651);
struct StateT * slot_44(struct StateT * v973);
struct StateT * slot_137(struct StateT * v2542);
struct StateT * slot_122(struct StateT * v2304);
struct StateT * slot_99(struct StateT * v1947);
struct StateT * slot_179(struct StateT * v3195);
struct StateT * slot_36(struct StateT * v699);
struct StateT * slot_57(struct StateT * v1294);
struct StateT * slot_62(struct StateT * v1368);
struct StateT * slot_22(struct StateT * v409);
struct StateT * slot_139(struct StateT * v2571);
struct StateT * slot_23(struct StateT * v428);
struct StateT * slot_153(struct StateT * v2786);
struct StateT * slot_2(struct StateT * v35);
struct StateT * slot_86(struct StateT * v1741);
struct StateT * slot_129(struct StateT * v2410);
struct StateT * slot_158(struct StateT * v2869);
struct StateT * slot_100(struct StateT * v1963);
struct StateT * slot_127(struct StateT * v2380);
struct StateT * slot_13(struct StateT * v238);
struct StateT * slot_111(struct StateT * v2130);
struct StateT * slot_109(struct StateT * v2098);
struct StateT * slot_174(struct StateT * v3115);
struct StateT * slot_147(struct StateT * v2692);
struct StateT * slot_42(struct StateT * v904);
struct StateT * slot_163(struct StateT * v2944);
struct StateT * slot_184(struct StateT * v3271);
struct StateT * slot_204(struct StateT * v885);
struct StateT * slot_194(struct StateT * v3424);
struct StateT * slot_165(struct StateT * v2973);
struct StateT * snippet(struct StateT * v0);
struct StateT * slot_117(struct StateT * v2230);
struct StateT * slot_90(struct StateT * v1802);
struct StateT * slot_11(struct StateT * v200);
struct StateT * slot_12(struct StateT * v219) {
  int v220 = v219->timer;
  int v229 = v220 + 1;
  v219->timer = v229;
  int * v222 = v219->regs;
  int v223 = v222[12];
  int * v224 = v219->mem;
  int v233 = (int)((unsigned int)(v223 + 4) >> 2);
  int v225 = v224[v233];
  v222[17] = v225;
  struct StateT * v227 = slot_13(v219);
  return v227;
}

struct StateT * slot_143(struct StateT * v2632) {
  int v2633 = v2632->timer;
  int v2640 = v2633 + 1;
  v2632->timer = v2640;
  int * v2635 = v2632->regs;
  int v2636 = v2635[22];
  int v2644 = (int)((unsigned int)v2636 >> 23);
  v2635[24] = v2644;
  struct StateT * v2638 = slot_144(v2632);
  return v2638;
}

struct StateT * slot_120(struct StateT * v2275) {
  int v2276 = v2275->timer;
  int v2283 = v2276 + 1;
  v2275->timer = v2283;
  int * v2278 = v2275->regs;
  int v2279 = v2278[21];
  int v2287 = (int)((unsigned int)v2279 >> 25);
  v2278[24] = v2287;
  struct StateT * v2281 = slot_121(v2275);
  return v2281;
}

struct StateT * slot_167(struct StateT * v3004) {
  int v3005 = v3004->timer;
  int v3012 = v3005 + 1;
  v3004->timer = v3012;
  int * v3007 = v3004->regs;
  int v3008 = v3007[23];
  int v3015 = v3008 << 13;
  v3007[23] = v3015;
  struct StateT * v3010 = slot_168(v3004);
  return v3010;
}

struct StateT * slot_152(struct StateT * v2770) {
  int v2771 = v2770->timer;
  int v2779 = v2771 + 1;
  v2770->timer = v2779;
  int * v2773 = v2770->regs;
  int v2774 = v2773[7];
  int v2775 = v2773[23];
  int v2783 = v2774 ^ v2775;
  v2773[7] = v2783;
  struct StateT * v2777 = slot_153(v2770);
  return v2777;
}

struct StateT * slot_199(struct StateT * v716) {
  int v717 = v716->timer;
  int v726 = v717 + 1;
  v716->timer = v726;
  int * v719 = v716->regs;
  int v720 = v719[10];
  int v721 = v719[12];
  int * v722 = v716->mem;
  int v731 = (int)((unsigned int)(v720 + 16) >> 2);
  v722[v731] = v721;
  struct StateT * v724 = slot_200(v716);
  return v724;
}

struct StateT * slot_92(struct StateT * v1834) {
  int v1835 = v1834->timer;
  int v1843 = v1835 + 1;
  v1834->timer = v1843;
  int * v1837 = v1834->regs;
  int v1838 = v1837[15];
  int v1839 = v1837[23];
  int v1847 = v1838 ^ v1839;
  v1837[15] = v1847;
  struct StateT * v1841 = slot_93(v1834);
  return v1841;
}

struct StateT * slot_31(struct StateT * v539) {
  int v540 = v539->timer;
  int v546 = v540 + 1;
  v539->timer = v546;
  int * v542 = v539->regs;
  v542[11] = 9;
  struct StateT * v544 = slot_32(v539);
  return v544;
}

struct StateT * slot_160(struct StateT * v2899) {
  int v2900 = v2899->timer;
  int v2907 = v2900 + 1;
  v2899->timer = v2907;
  int * v2902 = v2899->regs;
  int v2903 = v2902[21];
  int v2911 = (int)((unsigned int)v2903 >> 19);
  v2902[24] = v2911;
  struct StateT * v2905 = slot_161(v2899);
  return v2905;
}

struct StateT * slot_65(struct StateT * v1413) {
  int v1414 = v1413->timer;
  int v1422 = v1414 + 1;
  v1413->timer = v1422;
  int * v1416 = v1413->regs;
  int v1417 = v1416[22];
  int v1418 = v1416[24];
  int v1426 = v1417 | v1418;
  v1416[22] = v1426;
  struct StateT * v1420 = slot_66(v1413);
  return v1420;
}

struct StateT * slot_10(struct StateT * v187) {
  int v188 = v187->timer;
  int v194 = v188 + 1;
  v187->timer = v194;
  int * v190 = v187->regs;
  v190[13] = 0;
  struct StateT * v192 = slot_11(v187);
  return v192;
}

struct StateT * slot_150(struct StateT * v2738) {
  int v2739 = v2738->timer;
  int v2747 = v2739 + 1;
  v2738->timer = v2747;
  int * v2741 = v2738->regs;
  int v2742 = v2741[5];
  int v2743 = v2741[21];
  int v2751 = v2742 ^ v2743;
  v2741[5] = v2751;
  struct StateT * v2745 = slot_151(v2738);
  return v2745;
}

struct StateT * slot_74(struct StateT * v1555) {
  int v1556 = v1555->timer;
  int v1564 = v1556 + 1;
  v1555->timer = v1564;
  int * v1558 = v1555->regs;
  int v1559 = v1558[7];
  int v1560 = v1558[18];
  int v1569 = v1559 + v1560;
  v1558[21] = v1569;
  struct StateT * v1562 = slot_75(v1555);
  return v1562;
}

struct StateT * slot_107(struct StateT * v2068) {
  int v2069 = v2068->timer;
  int v2076 = v2069 + 1;
  v2068->timer = v2076;
  int * v2071 = v2068->regs;
  int v2072 = v2071[23];
  int v2079 = v2072 << 18;
  v2071[23] = v2079;
  struct StateT * v2074 = slot_108(v2068);
  return v2074;
}

struct StateT * slot_136(struct StateT * v2525) {
  int v2526 = v2525->timer;
  int v2534 = v2526 + 1;
  v2525->timer = v2534;
  int * v2528 = v2525->regs;
  int v2529 = v2528[16];
  int v2530 = v2528[31];
  int v2539 = v2529 + v2530;
  v2528[23] = v2539;
  struct StateT * v2532 = slot_137(v2525);
  return v2532;
}

struct StateT * slot_84(struct StateT * v1711) {
  int v1712 = v1711->timer;
  int v1719 = v1712 + 1;
  v1711->timer = v1719;
  int * v1714 = v1711->regs;
  int v1715 = v1714[22];
  int v1722 = v1715 << 13;
  v1714[22] = v1722;
  struct StateT * v1717 = slot_85(v1711);
  return v1717;
}

struct StateT * slot_28(struct StateT * v497) {
  int v498 = v497->timer;
  int v505 = v498 + 1;
  v497->timer = v505;
  int * v500 = v497->regs;
  int v501 = v500[31];
  int v509 = v501 + -718;
  v500[28] = v509;
  struct StateT * v503 = slot_29(v497);
  return v503;
}

struct StateT * slot_155(struct StateT * v2820) {
  int v2821 = v2820->timer;
  int v2829 = v2821 + 1;
  v2820->timer = v2829;
  int * v2823 = v2820->regs;
  int v2824 = v2823[6];
  int v2825 = v2823[15];
  int v2834 = v2824 + v2825;
  v2823[22] = v2834;
  struct StateT * v2827 = slot_156(v2820);
  return v2827;
}

struct StateT * slot_177(struct StateT * v3166) {
  int v3167 = v3166->timer;
  int v3174 = v3167 + 1;
  v3166->timer = v3174;
  int * v3169 = v3166->regs;
  int v3170 = v3169[20];
  int v3178 = (int)((unsigned int)v3170 >> 14);
  v3169[24] = v3178;
  struct StateT * v3172 = slot_178(v3166);
  return v3172;
}

struct StateT * slot_17(struct StateT * v314) {
  int v315 = v314->timer;
  int v324 = v315 + 1;
  v314->timer = v324;
  int * v317 = v314->regs;
  int v318 = v317[12];
  int * v319 = v314->mem;
  int v328 = (int)((unsigned int)(v318 + 24) >> 2);
  int v320 = v319[v328];
  v317[7] = v320;
  struct StateT * v322 = slot_18(v314);
  return v322;
}

struct StateT * slot_181(struct StateT * v3226) {
  int v3227 = v3226->timer;
  int v3234 = v3227 + 1;
  v3226->timer = v3234;
  int * v3229 = v3226->regs;
  int v3230 = v3229[21];
  int v3237 = v3230 << 18;
  v3229[21] = v3237;
  struct StateT * v3232 = slot_182(v3226);
  return v3232;
}

struct StateT * slot_197(struct StateT * v644) {
  int v645 = v644->timer;
  int v654 = v645 + 1;
  v644->timer = v654;
  int * v647 = v644->regs;
  int v648 = v647[10];
  int v649 = v647[28];
  int * v650 = v644->mem;
  int v659 = (int)((unsigned int)(v648 + 8) >> 2);
  v650[v659] = v649;
  struct StateT * v652 = slot_198(v644);
  return v652;
}

struct StateT * slot_207(struct StateT * v987) {
  int v988 = v987->timer;
  int v997 = v988 + 1;
  v987->timer = v997;
  int * v990 = v987->regs;
  int v991 = v990[2];
  int * v992 = v987->mem;
  int v1001 = (int)((unsigned int)(v991 + 28) >> 2);
  int v993 = v992[v1001];
  v990[20] = v993;
  struct StateT * v995 = slot_208(v987);
  return v995;
}

struct StateT * slot_156(struct StateT * v2837) {
  int v2838 = v2837->timer;
  int v2846 = v2838 + 1;
  v2837->timer = v2846;
  int * v2840 = v2837->regs;
  int v2841 = v2840[7];
  int v2842 = v2840[16];
  int v2851 = v2841 + v2842;
  v2840[23] = v2851;
  struct StateT * v2844 = slot_157(v2837);
  return v2844;
}

struct StateT * slot_154(struct StateT * v2803) {
  int v2804 = v2803->timer;
  int v2812 = v2804 + 1;
  v2803->timer = v2812;
  int * v2806 = v2803->regs;
  int v2807 = v2806[5];
  int v2808 = v2806[12];
  int v2817 = v2807 + v2808;
  v2806[21] = v2817;
  struct StateT * v2810 = slot_155(v2803);
  return v2810;
}

struct StateT * slot_68(struct StateT * v1458) {
  int v1459 = v1458->timer;
  int v1467 = v1459 + 1;
  v1458->timer = v1467;
  int * v1461 = v1458->regs;
  int v1462 = v1461[23];
  int v1463 = v1461[24];
  int v1471 = v1462 | v1463;
  v1461[23] = v1471;
  struct StateT * v1465 = slot_69(v1458);
  return v1465;
}

struct StateT * slot_105(struct StateT * v2037) {
  int v2038 = v2037->timer;
  int v2046 = v2038 + 1;
  v2037->timer = v2046;
  int * v2040 = v2037->regs;
  int v2041 = v2040[22];
  int v2042 = v2040[24];
  int v2050 = v2041 | v2042;
  v2040[22] = v2050;
  struct StateT * v2044 = slot_106(v2037);
  return v2044;
}

struct StateT * slot_27(struct StateT * v482) {
  int v483 = v482->timer;
  int v490 = v483 + 1;
  v482->timer = v490;
  int * v485 = v482->regs;
  int v486 = v485[28];
  int v494 = v486 + 1134;
  v485[29] = v494;
  struct StateT * v488 = slot_28(v482);
  return v488;
}

struct StateT * slot_164(struct StateT * v2959) {
  int v2960 = v2959->timer;
  int v2967 = v2960 + 1;
  v2959->timer = v2967;
  int * v2962 = v2959->regs;
  int v2963 = v2962[22];
  int v2970 = v2963 << 13;
  v2962[22] = v2970;
  struct StateT * v2965 = slot_165(v2959);
  return v2965;
}

struct StateT * slot_15(struct StateT * v276) {
  int v277 = v276->timer;
  int v286 = v277 + 1;
  v276->timer = v286;
  int * v279 = v276->regs;
  int v280 = v279[12];
  int * v281 = v276->mem;
  int v290 = (int)((unsigned int)(v280 + 16) >> 2);
  int v282 = v281[v290];
  v279[15] = v282;
  struct StateT * v284 = slot_16(v276);
  return v284;
}

struct StateT * slot_133(struct StateT * v2474) {
  int v2475 = v2474->timer;
  int v2483 = v2475 + 1;
  v2474->timer = v2483;
  int * v2477 = v2474->regs;
  int v2478 = v2477[14];
  int v2479 = v2477[30];
  int v2488 = v2478 + v2479;
  v2477[20] = v2488;
  struct StateT * v2481 = slot_134(v2474);
  return v2481;
}

struct StateT * slot_56(struct StateT * v1277) {
  int v1278 = v1277->timer;
  int v1286 = v1278 + 1;
  v1277->timer = v1286;
  int * v1280 = v1277->regs;
  int v1281 = v1280[8];
  int v1282 = v1280[31];
  int v1291 = v1281 + v1282;
  v1280[23] = v1291;
  struct StateT * v1284 = slot_57(v1277);
  return v1284;
}

struct StateT * slot_34(struct StateT * v627) {
  int v628 = v627->timer;
  int v636 = v628 + 1;
  v627->timer = v636;
  int * v630 = v627->regs;
  int v631 = v630[29];
  int v632 = v630[14];
  int v641 = v631 + v632;
  v630[21] = v641;
  struct StateT * v634 = slot_35(v627);
  return v634;
}

struct StateT * slot_171(struct StateT * v3066) {
  int v3067 = v3066->timer;
  int v3075 = v3067 + 1;
  v3066->timer = v3075;
  int * v3069 = v3066->regs;
  int v3070 = v3069[18];
  int v3071 = v3069[22];
  int v3079 = v3070 ^ v3071;
  v3069[18] = v3079;
  struct StateT * v3073 = slot_172(v3066);
  return v3073;
}

struct StateT * slot_162(struct StateT * v2928) {
  int v2929 = v2928->timer;
  int v2937 = v2929 + 1;
  v2928->timer = v2937;
  int * v2931 = v2928->regs;
  int v2932 = v2931[21];
  int v2933 = v2931[24];
  int v2941 = v2932 | v2933;
  v2931[21] = v2941;
  struct StateT * v2935 = slot_163(v2928);
  return v2935;
}

struct StateT * slot_21(struct StateT * v390) {
  int v391 = v390->timer;
  int v400 = v391 + 1;
  v390->timer = v400;
  int * v393 = v390->regs;
  int v394 = v393[11];
  int * v395 = v390->mem;
  int v404 = (int)((unsigned int)(v394 + 8) >> 2);
  int v396 = v395[v404];
  v393[6] = v396;
  struct StateT * v398 = slot_22(v390);
  return v398;
}

struct StateT * slot_118(struct StateT * v2245) {
  int v2246 = v2245->timer;
  int v2253 = v2246 + 1;
  v2245->timer = v2253;
  int * v2248 = v2245->regs;
  int v2249 = v2248[20];
  int v2256 = v2249 << 7;
  v2248[20] = v2256;
  struct StateT * v2251 = slot_119(v2245);
  return v2251;
}

struct StateT * slot_121(struct StateT * v2290) {
  int v2291 = v2290->timer;
  int v2298 = v2291 + 1;
  v2290->timer = v2298;
  int * v2293 = v2290->regs;
  int v2294 = v2293[21];
  int v2301 = v2294 << 7;
  v2293[21] = v2301;
  struct StateT * v2296 = slot_122(v2290);
  return v2296;
}

struct StateT * slot_144(struct StateT * v2647) {
  int v2648 = v2647->timer;
  int v2655 = v2648 + 1;
  v2647->timer = v2655;
  int * v2650 = v2647->regs;
  int v2651 = v2650[22];
  int v2658 = v2651 << 9;
  v2650[22] = v2658;
  struct StateT * v2653 = slot_145(v2647);
  return v2653;
}

struct StateT * slot_201(struct StateT * v783) {
  int v784 = v783->timer;
  int v793 = v784 + 1;
  v783->timer = v793;
  int * v786 = v783->regs;
  int v787 = v786[10];
  int v788 = v786[6];
  int * v789 = v783->mem;
  int v798 = (int)((unsigned int)(v787 + 24) >> 2);
  v789[v798] = v788;
  struct StateT * v791 = slot_202(v783);
  return v791;
}

struct StateT * slot_94(struct StateT * v1867) {
  int v1868 = v1867->timer;
  int v1876 = v1868 + 1;
  v1867->timer = v1876;
  int * v1870 = v1867->regs;
  int v1871 = v1870[14];
  int v1872 = v1870[7];
  int v1881 = v1871 + v1872;
  v1870[21] = v1881;
  struct StateT * v1874 = slot_95(v1867);
  return v1874;
}

struct StateT * slot_63(struct StateT * v1384) {
  int v1385 = v1384->timer;
  int v1392 = v1385 + 1;
  v1384->timer = v1392;
  int * v1387 = v1384->regs;
  int v1388 = v1387[22];
  int v1396 = (int)((unsigned int)v1388 >> 23);
  v1387[24] = v1396;
  struct StateT * v1390 = slot_64(v1384);
  return v1390;
}

struct StateT * slot_146(struct StateT * v2677) {
  int v2678 = v2677->timer;
  int v2685 = v2678 + 1;
  v2677->timer = v2685;
  int * v2680 = v2677->regs;
  int v2681 = v2680[23];
  int v2689 = (int)((unsigned int)v2681 >> 23);
  v2680[24] = v2689;
  struct StateT * v2683 = slot_147(v2677);
  return v2683;
}

struct StateT * slot_24(struct StateT * v441) {
  int v442 = v441->timer;
  int v448 = v442 + 1;
  v441->timer = v448;
  int * v444 = v441->regs;
  v444[28] = 857759744;
  struct StateT * v446 = slot_25(v441);
  return v446;
}

struct StateT * slot_0(struct StateT * v2) {
  int v3 = v2->timer;
  int v10 = v3 + 1;
  v2->timer = v10;
  int * v5 = v2->regs;
  int v6 = v5[2];
  int v13 = v6 + -48;
  v5[2] = v13;
  struct StateT * v8 = slot_1(v2);
  return v8;
}

struct StateT * slot_195(struct StateT * v572) {
  int v573 = v572->timer;
  int v582 = v573 + 1;
  v572->timer = v582;
  int * v575 = v572->regs;
  int v576 = v575[10];
  int v577 = v575[30];
  int * v578 = v572->mem;
  int v587 = (int)((unsigned int)v576 >> 2);
  v578[v587] = v577;
  struct StateT * v580 = slot_196(v572);
  return v580;
}

struct StateT * slot_125(struct StateT * v2349) {
  int v2350 = v2349->timer;
  int v2358 = v2350 + 1;
  v2349->timer = v2358;
  int * v2352 = v2349->regs;
  int v2353 = v2352[22];
  int v2354 = v2352[24];
  int v2362 = v2353 | v2354;
  v2352[22] = v2362;
  struct StateT * v2356 = slot_126(v2349);
  return v2356;
}

struct StateT * slot_148(struct StateT * v2706) {
  int v2707 = v2706->timer;
  int v2715 = v2707 + 1;
  v2706->timer = v2715;
  int * v2709 = v2706->regs;
  int v2710 = v2709[23];
  int v2711 = v2709[24];
  int v2719 = v2710 | v2711;
  v2709[23] = v2719;
  struct StateT * v2713 = slot_149(v2706);
  return v2713;
}

struct StateT * slot_126(struct StateT * v2365) {
  int v2366 = v2365->timer;
  int v2373 = v2366 + 1;
  v2365->timer = v2373;
  int * v2368 = v2365->regs;
  int v2369 = v2368[23];
  int v2377 = (int)((unsigned int)v2369 >> 25);
  v2368[24] = v2377;
  struct StateT * v2371 = slot_127(v2365);
  return v2371;
}

struct StateT * slot_79(struct StateT * v1635) {
  int v1636 = v1635->timer;
  int v1644 = v1636 + 1;
  v1635->timer = v1644;
  int * v1638 = v1635->regs;
  int v1639 = v1638[20];
  int v1640 = v1638[24];
  int v1648 = v1639 | v1640;
  v1638[20] = v1648;
  struct StateT * v1642 = slot_80(v1635);
  return v1642;
}

struct StateT * slot_41(struct StateT * v871) {
  int v872 = v871->timer;
  int v879 = v872 + 1;
  v871->timer = v879;
  int * v874 = v871->regs;
  int v875 = v874[21];
  int v882 = v875 << 7;
  v874[21] = v882;
  struct StateT * v877 = slot_42(v871);
  return v877;
}

struct StateT * slot_39(struct StateT * v802) {
  int v803 = v802->timer;
  int v811 = v803 + 1;
  v802->timer = v811;
  int * v805 = v802->regs;
  int v806 = v805[20];
  int v807 = v805[24];
  int v815 = v806 | v807;
  v805[20] = v815;
  struct StateT * v809 = slot_40(v802);
  return v809;
}

struct StateT * slot_142(struct StateT * v2616) {
  int v2617 = v2616->timer;
  int v2625 = v2617 + 1;
  v2616->timer = v2625;
  int * v2619 = v2616->regs;
  int v2620 = v2619[21];
  int v2621 = v2619[24];
  int v2629 = v2620 | v2621;
  v2619[21] = v2629;
  struct StateT * v2623 = slot_143(v2616);
  return v2623;
}

struct StateT * slot_60(struct StateT * v1339) {
  int v1340 = v1339->timer;
  int v1347 = v1340 + 1;
  v1339->timer = v1347;
  int * v1342 = v1339->regs;
  int v1343 = v1342[21];
  int v1351 = (int)((unsigned int)v1343 >> 23);
  v1342[24] = v1351;
  struct StateT * v1345 = slot_61(v1339);
  return v1345;
}

struct StateT * slot_112(struct StateT * v2146) {
  int v2147 = v2146->timer;
  int v2155 = v2147 + 1;
  v2146->timer = v2155;
  int * v2149 = v2146->regs;
  int v2150 = v2149[31];
  int v2151 = v2149[23];
  int v2159 = v2150 ^ v2151;
  v2149[31] = v2159;
  struct StateT * v2153 = slot_113(v2146);
  return v2153;
}

struct StateT * slot_47(struct StateT * v1075) {
  int v1076 = v1075->timer;
  int v1083 = v1076 + 1;
  v1075->timer = v1083;
  int * v1078 = v1075->regs;
  int v1079 = v1078[23];
  int v1086 = v1079 << 7;
  v1078[23] = v1086;
  struct StateT * v1081 = slot_48(v1075);
  return v1081;
}

struct StateT * slot_29(struct StateT * v512) {
  int v513 = v512->timer;
  int v519 = v513 + 1;
  v512->timer = v519;
  int * v515 = v512->regs;
  v515[31] = 1797283840;
  struct StateT * v517 = slot_30(v512);
  return v517;
}

struct StateT * slot_16(struct StateT * v295) {
  int v296 = v295->timer;
  int v305 = v296 + 1;
  v295->timer = v305;
  int * v298 = v295->regs;
  int v299 = v298[12];
  int * v300 = v295->mem;
  int v309 = (int)((unsigned int)(v299 + 20) >> 2);
  int v301 = v300[v309];
  v298[16] = v301;
  struct StateT * v303 = slot_17(v295);
  return v303;
}

struct StateT * slot_113(struct StateT * v2162) {
  int v2163 = v2162->timer;
  int v2171 = v2163 + 1;
  v2162->timer = v2171;
  int * v2165 = v2162->regs;
  int v2166 = v2165[30];
  int v2167 = v2165[8];
  int v2176 = v2166 + v2167;
  v2165[20] = v2176;
  struct StateT * v2169 = slot_114(v2162);
  return v2169;
}

struct StateT * slot_151(struct StateT * v2754) {
  int v2755 = v2754->timer;
  int v2763 = v2755 + 1;
  v2754->timer = v2763;
  int * v2757 = v2754->regs;
  int v2758 = v2757[6];
  int v2759 = v2757[22];
  int v2767 = v2758 ^ v2759;
  v2757[6] = v2767;
  struct StateT * v2761 = slot_152(v2754);
  return v2761;
}

struct StateT * slot_7(struct StateT * v130) {
  int v131 = v130->timer;
  int v140 = v131 + 1;
  v130->timer = v140;
  int * v133 = v130->regs;
  int v134 = v133[2];
  int v135 = v133[22];
  int * v136 = v130->mem;
  int v145 = (int)((unsigned int)(v134 + 20) >> 2);
  v136[v145] = v135;
  struct StateT * v138 = slot_8(v130);
  return v138;
}

struct StateT * slot_124(struct StateT * v2335) {
  int v2336 = v2335->timer;
  int v2343 = v2336 + 1;
  v2335->timer = v2343;
  int * v2338 = v2335->regs;
  int v2339 = v2338[22];
  int v2346 = v2339 << 7;
  v2338[22] = v2346;
  struct StateT * v2341 = slot_125(v2335);
  return v2341;
}

struct StateT * slot_191(struct StateT * v3378) {
  int v3379 = v3378->timer;
  int v3387 = v3379 + 1;
  v3378->timer = v3387;
  int * v3381 = v3378->regs;
  int v3382 = v3381[28];
  int v3383 = v3381[22];
  int v3391 = v3382 ^ v3383;
  v3381[28] = v3391;
  struct StateT * v3385 = slot_192(v3378);
  return v3385;
}

struct StateT * slot_103(struct StateT * v2008) {
  int v2009 = v2008->timer;
  int v2016 = v2009 + 1;
  v2008->timer = v2016;
  int * v2011 = v2008->regs;
  int v2012 = v2011[22];
  int v2020 = (int)((unsigned int)v2012 >> 14);
  v2011[24] = v2020;
  struct StateT * v2014 = slot_104(v2008);
  return v2014;
}

struct StateT * slot_128(struct StateT * v2394) {
  int v2395 = v2394->timer;
  int v2403 = v2395 + 1;
  v2394->timer = v2403;
  int * v2397 = v2394->regs;
  int v2398 = v2397[23];
  int v2399 = v2397[24];
  int v2407 = v2398 | v2399;
  v2397[23] = v2407;
  struct StateT * v2401 = slot_129(v2394);
  return v2401;
}

struct StateT * slot_19(struct StateT * v352) {
  int v353 = v352->timer;
  int v362 = v353 + 1;
  v352->timer = v362;
  int * v355 = v352->regs;
  int v356 = v355[11];
  int * v357 = v352->mem;
  int v366 = (int)((unsigned int)v356 >> 2);
  int v358 = v357[v366];
  v355[12] = v358;
  struct StateT * v360 = slot_20(v352);
  return v360;
}

struct StateT * slot_87(struct StateT * v1756) {
  int v1757 = v1756->timer;
  int v1764 = v1757 + 1;
  v1756->timer = v1764;
  int * v1759 = v1756->regs;
  int v1760 = v1759[23];
  int v1767 = v1760 << 13;
  v1759[23] = v1767;
  struct StateT * v1762 = slot_88(v1756);
  return v1762;
}

struct StateT * slot_67(struct StateT * v1444) {
  int v1445 = v1444->timer;
  int v1452 = v1445 + 1;
  v1444->timer = v1452;
  int * v1447 = v1444->regs;
  int v1448 = v1447[23];
  int v1455 = v1448 << 9;
  v1447[23] = v1455;
  struct StateT * v1450 = slot_68(v1444);
  return v1450;
}

struct StateT * slot_81(struct StateT * v1666) {
  int v1667 = v1666->timer;
  int v1674 = v1667 + 1;
  v1666->timer = v1674;
  int * v1669 = v1666->regs;
  int v1670 = v1669[21];
  int v1677 = v1670 << 13;
  v1669[21] = v1677;
  struct StateT * v1672 = slot_82(v1666);
  return v1672;
}

struct StateT * slot_95(struct StateT * v1884) {
  int v1885 = v1884->timer;
  int v1893 = v1885 + 1;
  v1884->timer = v1893;
  int * v1887 = v1884->regs;
  int v1888 = v1887[12];
  int v1889 = v1887[17];
  int v1898 = v1888 + v1889;
  v1887[22] = v1898;
  struct StateT * v1891 = slot_96(v1884);
  return v1891;
}

struct StateT * slot_115(struct StateT * v2196) {
  int v2197 = v2196->timer;
  int v2205 = v2197 + 1;
  v2196->timer = v2205;
  int * v2199 = v2196->regs;
  int v2200 = v2199[28];
  int v2201 = v2199[18];
  int v2210 = v2200 + v2201;
  v2199[22] = v2210;
  struct StateT * v2203 = slot_116(v2196);
  return v2203;
}

struct StateT * slot_78(struct StateT * v1621) {
  int v1622 = v1621->timer;
  int v1629 = v1622 + 1;
  v1621->timer = v1629;
  int * v1624 = v1621->regs;
  int v1625 = v1624[20];
  int v1632 = v1625 << 13;
  v1624[20] = v1632;
  struct StateT * v1627 = slot_79(v1621);
  return v1627;
}

struct StateT * slot_32(struct StateT * v552) {
  int v553 = v552->timer;
  int v563 = v553 + 1;
  v552->timer = v563;
  int * v555 = v552->regs;
  int v556 = v555[11];
  bool v566 = (v556 ^ -2147483648) < -2147483648;
  struct StateT * v561;
  if (v566) {
    struct StateT * v557 = slot_195(v552);
    v561 = v557;
  } else {
    struct StateT * v559 = slot_33(v552);
    v561 = v559;
  }
  return v561;
}

struct StateT * slot_205(struct StateT * v920) {
  int v921 = v920->timer;
  int v930 = v921 + 1;
  v920->timer = v930;
  int * v923 = v920->regs;
  int v924 = v923[2];
  int * v925 = v920->mem;
  int v934 = (int)((unsigned int)(v924 + 36) >> 2);
  int v926 = v925[v934];
  v923[18] = v926;
  struct StateT * v928 = slot_206(v920);
  return v928;
}

struct StateT * slot_193(struct StateT * v3410) {
  int v3411 = v3410->timer;
  int v3418 = v3411 + 1;
  v3410->timer = v3418;
  int * v3413 = v3410->regs;
  int v3414 = v3413[13];
  int v3421 = v3414 + 1;
  v3413[13] = v3421;
  struct StateT * v3416 = slot_194(v3410);
  return v3416;
}

struct StateT * slot_176(struct StateT * v3149) {
  int v3150 = v3149->timer;
  int v3158 = v3150 + 1;
  v3149->timer = v3158;
  int * v3152 = v3149->regs;
  int v3153 = v3152[19];
  int v3154 = v3152[7];
  int v3163 = v3153 + v3154;
  v3152[23] = v3163;
  struct StateT * v3156 = slot_177(v3149);
  return v3156;
}

struct StateT * slot_189(struct StateT * v3346) {
  int v3347 = v3346->timer;
  int v3355 = v3347 + 1;
  v3346->timer = v3355;
  int * v3349 = v3346->regs;
  int v3350 = v3349[30];
  int v3351 = v3349[20];
  int v3359 = v3350 ^ v3351;
  v3349[30] = v3359;
  struct StateT * v3353 = slot_190(v3346);
  return v3353;
}

struct StateT * slot_33(struct StateT * v591) {
  int v592 = v591->timer;
  int v600 = v592 + 1;
  v591->timer = v600;
  int * v594 = v591->regs;
  int v595 = v594[30];
  int v596 = v594[16];
  int v605 = v595 + v596;
  v594[20] = v605;
  struct StateT * v598 = slot_34(v591);
  return v598;
}

struct StateT * slot_35(struct StateT * v663) {
  int v664 = v663->timer;
  int v672 = v664 + 1;
  v663->timer = v672;
  int * v666 = v663->regs;
  int v667 = v666[28];
  int v668 = v666[12];
  int v677 = v667 + v668;
  v666[22] = v677;
  struct StateT * v670 = slot_36(v663);
  return v670;
}

struct StateT * slot_210(struct StateT * v1089) {
  int v1090 = v1089->timer;
  int v1099 = v1090 + 1;
  v1089->timer = v1099;
  int * v1092 = v1089->regs;
  int v1093 = v1092[2];
  int * v1094 = v1089->mem;
  int v1103 = (int)((unsigned int)(v1093 + 16) >> 2);
  int v1095 = v1094[v1103];
  v1092[23] = v1095;
  struct StateT * v1097 = slot_211(v1089);
  return v1097;
}

struct StateT * slot_166(struct StateT * v2989) {
  int v2990 = v2989->timer;
  int v2997 = v2990 + 1;
  v2989->timer = v2997;
  int * v2992 = v2989->regs;
  int v2993 = v2992[23];
  int v3001 = (int)((unsigned int)v2993 >> 19);
  v2992[24] = v3001;
  struct StateT * v2995 = slot_167(v2989);
  return v2995;
}

struct StateT * slot_51(struct StateT * v1194) {
  int v1195 = v1194->timer;
  int v1203 = v1195 + 1;
  v1194->timer = v1203;
  int * v1197 = v1194->regs;
  int v1198 = v1197[19];
  int v1199 = v1197[22];
  int v1207 = v1198 ^ v1199;
  v1197[19] = v1207;
  struct StateT * v1201 = slot_52(v1194);
  return v1201;
}

struct StateT * slot_52(struct StateT * v1210) {
  int v1211 = v1210->timer;
  int v1219 = v1211 + 1;
  v1210->timer = v1219;
  int * v1213 = v1210->regs;
  int v1214 = v1213[8];
  int v1215 = v1213[23];
  int v1223 = v1214 ^ v1215;
  v1213[8] = v1223;
  struct StateT * v1217 = slot_53(v1210);
  return v1217;
}

struct StateT * slot_83(struct StateT * v1696) {
  int v1697 = v1696->timer;
  int v1704 = v1697 + 1;
  v1696->timer = v1704;
  int * v1699 = v1696->regs;
  int v1700 = v1699[22];
  int v1708 = (int)((unsigned int)v1700 >> 19);
  v1699[24] = v1708;
  struct StateT * v1702 = slot_84(v1696);
  return v1702;
}

struct StateT * slot_25(struct StateT * v454) {
  int v455 = v454->timer;
  int v461 = v455 + 1;
  v454->timer = v461;
  int * v457 = v454->regs;
  v457[31] = 2036477952;
  struct StateT * v459 = slot_26(v454);
  return v459;
}

struct StateT * slot_209(struct StateT * v1056) {
  int v1057 = v1056->timer;
  int v1066 = v1057 + 1;
  v1056->timer = v1066;
  int * v1059 = v1056->regs;
  int v1060 = v1059[2];
  int * v1061 = v1056->mem;
  int v1070 = (int)((unsigned int)(v1060 + 20) >> 2);
  int v1062 = v1061[v1070];
  v1059[22] = v1062;
  struct StateT * v1064 = slot_210(v1056);
  return v1064;
}

struct StateT * slot_3(struct StateT * v54) {
  int v55 = v54->timer;
  int v64 = v55 + 1;
  v54->timer = v64;
  int * v57 = v54->regs;
  int v58 = v57[2];
  int v59 = v57[18];
  int * v60 = v54->mem;
  int v69 = (int)((unsigned int)(v58 + 36) >> 2);
  v60[v69] = v59;
  struct StateT * v62 = slot_4(v54);
  return v62;
}

struct StateT * slot_123(struct StateT * v2320) {
  int v2321 = v2320->timer;
  int v2328 = v2321 + 1;
  v2320->timer = v2328;
  int * v2323 = v2320->regs;
  int v2324 = v2323[22];
  int v2332 = (int)((unsigned int)v2324 >> 25);
  v2323[24] = v2332;
  struct StateT * v2326 = slot_124(v2320);
  return v2326;
}

struct StateT * slot_73(struct StateT * v1538) {
  int v1539 = v1538->timer;
  int v1547 = v1539 + 1;
  v1538->timer = v1547;
  int * v1541 = v1538->regs;
  int v1542 = v1541[6];
  int v1543 = v1541[9];
  int v1552 = v1542 + v1543;
  v1541[20] = v1552;
  struct StateT * v1545 = slot_74(v1538);
  return v1545;
}

struct StateT * slot_198(struct StateT * v680) {
  int v681 = v680->timer;
  int v690 = v681 + 1;
  v680->timer = v690;
  int * v683 = v680->regs;
  int v684 = v683[10];
  int v685 = v683[31];
  int * v686 = v680->mem;
  int v695 = (int)((unsigned int)(v684 + 12) >> 2);
  v686[v695] = v685;
  struct StateT * v688 = slot_199(v680);
  return v688;
}

struct StateT * slot_1(struct StateT * v16) {
  int v17 = v16->timer;
  int v26 = v17 + 1;
  v16->timer = v26;
  int * v19 = v16->regs;
  int v20 = v19[2];
  int v21 = v19[8];
  int * v22 = v16->mem;
  int v31 = (int)((unsigned int)(v20 + 44) >> 2);
  v22[v31] = v21;
  struct StateT * v24 = slot_2(v16);
  return v24;
}

struct StateT * slot_187(struct StateT * v3316) {
  int v3317 = v3316->timer;
  int v3324 = v3317 + 1;
  v3316->timer = v3324;
  int * v3319 = v3316->regs;
  int v3320 = v3319[23];
  int v3327 = v3320 << 18;
  v3319[23] = v3327;
  struct StateT * v3322 = slot_188(v3316);
  return v3322;
}

struct StateT * slot_97(struct StateT * v1918) {
  int v1919 = v1918->timer;
  int v1926 = v1919 + 1;
  v1918->timer = v1926;
  int * v1921 = v1918->regs;
  int v1922 = v1921[20];
  int v1930 = (int)((unsigned int)v1922 >> 14);
  v1921[24] = v1930;
  struct StateT * v1924 = slot_98(v1918);
  return v1924;
}

struct StateT * slot_182(struct StateT * v3240) {
  int v3241 = v3240->timer;
  int v3249 = v3241 + 1;
  v3240->timer = v3249;
  int * v3243 = v3240->regs;
  int v3244 = v3243[21];
  int v3245 = v3243[24];
  int v3253 = v3244 | v3245;
  v3243[21] = v3253;
  struct StateT * v3247 = slot_183(v3240);
  return v3247;
}

struct StateT * slot_38(struct StateT * v769) {
  int v770 = v769->timer;
  int v777 = v770 + 1;
  v769->timer = v777;
  int * v772 = v769->regs;
  int v773 = v772[20];
  int v780 = v773 << 7;
  v772[20] = v780;
  struct StateT * v775 = slot_39(v769);
  return v775;
}

struct StateT * slot_178(struct StateT * v3181) {
  int v3182 = v3181->timer;
  int v3189 = v3182 + 1;
  v3181->timer = v3189;
  int * v3184 = v3181->regs;
  int v3185 = v3184[20];
  int v3192 = v3185 << 18;
  v3184[20] = v3192;
  struct StateT * v3187 = slot_179(v3181);
  return v3187;
}

struct StateT * slot_106(struct StateT * v2053) {
  int v2054 = v2053->timer;
  int v2061 = v2054 + 1;
  v2053->timer = v2061;
  int * v2056 = v2053->regs;
  int v2057 = v2056[23];
  int v2065 = (int)((unsigned int)v2057 >> 14);
  v2056[24] = v2065;
  struct StateT * v2059 = slot_107(v2053);
  return v2059;
}

struct StateT * slot_98(struct StateT * v1933) {
  int v1934 = v1933->timer;
  int v1941 = v1934 + 1;
  v1933->timer = v1941;
  int * v1936 = v1933->regs;
  int v1937 = v1936[20];
  int v1944 = v1937 << 18;
  v1936[20] = v1944;
  struct StateT * v1939 = slot_99(v1933);
  return v1939;
}

struct StateT * slot_159(struct StateT * v2883) {
  int v2884 = v2883->timer;
  int v2892 = v2884 + 1;
  v2883->timer = v2892;
  int * v2886 = v2883->regs;
  int v2887 = v2886[20];
  int v2888 = v2886[24];
  int v2896 = v2887 | v2888;
  v2886[20] = v2896;
  struct StateT * v2890 = slot_160(v2883);
  return v2890;
}

struct StateT * slot_46(struct StateT * v1041) {
  int v1042 = v1041->timer;
  int v1049 = v1042 + 1;
  v1041->timer = v1049;
  int * v1044 = v1041->regs;
  int v1045 = v1044[23];
  int v1053 = (int)((unsigned int)v1045 >> 25);
  v1044[24] = v1053;
  struct StateT * v1047 = slot_47(v1041);
  return v1047;
}

struct StateT * slot_212(struct StateT * v1159) {
  int v1160 = v1159->timer;
  int v1167 = v1160 + 1;
  v1159->timer = v1167;
  int * v1162 = v1159->regs;
  int v1163 = v1162[2];
  int v1170 = v1163 + 48;
  v1162[2] = v1170;
  struct StateT * v1165 = slot_213(v1159);
  return v1165;
}

struct StateT * slot_132(struct StateT * v2458) {
  int v2459 = v2458->timer;
  int v2467 = v2459 + 1;
  v2458->timer = v2467;
  int * v2461 = v2458->regs;
  int v2462 = v2461[16];
  int v2463 = v2461[23];
  int v2471 = v2462 ^ v2463;
  v2461[16] = v2471;
  struct StateT * v2465 = slot_133(v2458);
  return v2465;
}

struct StateT * slot_130(struct StateT * v2426) {
  int v2427 = v2426->timer;
  int v2435 = v2427 + 1;
  v2426->timer = v2435;
  int * v2429 = v2426->regs;
  int v2430 = v2429[12];
  int v2431 = v2429[21];
  int v2439 = v2430 ^ v2431;
  v2429[12] = v2439;
  struct StateT * v2433 = slot_131(v2426);
  return v2433;
}

struct StateT * slot_211(struct StateT * v1124) {
  int v1125 = v1124->timer;
  int v1134 = v1125 + 1;
  v1124->timer = v1134;
  int * v1127 = v1124->regs;
  int v1128 = v1127[2];
  int * v1129 = v1124->mem;
  int v1138 = (int)((unsigned int)(v1128 + 12) >> 2);
  int v1130 = v1129[v1138];
  v1127[24] = v1130;
  struct StateT * v1132 = slot_212(v1124);
  return v1132;
}

struct StateT * slot_20(struct StateT * v371) {
  int v372 = v371->timer;
  int v381 = v372 + 1;
  v371->timer = v381;
  int * v374 = v371->regs;
  int v375 = v374[11];
  int * v376 = v371->mem;
  int v385 = (int)((unsigned int)(v375 + 4) >> 2);
  int v377 = v376[v385];
  v374[5] = v377;
  struct StateT * v379 = slot_21(v371);
  return v379;
}

struct StateT * slot_141(struct StateT * v2602) {
  int v2603 = v2602->timer;
  int v2610 = v2603 + 1;
  v2602->timer = v2610;
  int * v2605 = v2602->regs;
  int v2606 = v2605[21];
  int v2613 = v2606 << 9;
  v2605[21] = v2613;
  struct StateT * v2608 = slot_142(v2602);
  return v2608;
}

struct StateT * slot_61(struct StateT * v1354) {
  int v1355 = v1354->timer;
  int v1362 = v1355 + 1;
  v1354->timer = v1362;
  int * v1357 = v1354->regs;
  int v1358 = v1357[21];
  int v1365 = v1358 << 9;
  v1357[21] = v1365;
  struct StateT * v1360 = slot_62(v1354);
  return v1360;
}

struct StateT * slot_30(struct StateT * v525) {
  int v526 = v525->timer;
  int v533 = v526 + 1;
  v525->timer = v533;
  int * v528 = v525->regs;
  int v529 = v528[31];
  int v536 = v529 + 1396;
  v528[31] = v536;
  struct StateT * v531 = slot_31(v525);
  return v531;
}

struct StateT * slot_4(struct StateT * v73) {
  int v74 = v73->timer;
  int v83 = v74 + 1;
  v73->timer = v83;
  int * v76 = v73->regs;
  int v77 = v76[2];
  int v78 = v76[19];
  int * v79 = v73->mem;
  int v88 = (int)((unsigned int)(v77 + 32) >> 2);
  v79[v88] = v78;
  struct StateT * v81 = slot_5(v73);
  return v81;
}

struct StateT * slot_18(struct StateT * v333) {
  int v334 = v333->timer;
  int v343 = v334 + 1;
  v333->timer = v343;
  int * v336 = v333->regs;
  int v337 = v336[12];
  int * v338 = v333->mem;
  int v347 = (int)((unsigned int)(v337 + 28) >> 2);
  int v339 = v338[v347];
  v336[19] = v339;
  struct StateT * v341 = slot_19(v333);
  return v341;
}

struct StateT * slot_9(struct StateT * v168) {
  int v169 = v168->timer;
  int v178 = v169 + 1;
  v168->timer = v178;
  int * v171 = v168->regs;
  int v172 = v171[2];
  int v173 = v171[24];
  int * v174 = v168->mem;
  int v183 = (int)((unsigned int)(v172 + 12) >> 2);
  v174[v183] = v173;
  struct StateT * v176 = slot_10(v168);
  return v176;
}

struct StateT * slot_183(struct StateT * v3256) {
  int v3257 = v3256->timer;
  int v3264 = v3257 + 1;
  v3256->timer = v3264;
  int * v3259 = v3256->regs;
  int v3260 = v3259[22];
  int v3268 = (int)((unsigned int)v3260 >> 14);
  v3259[24] = v3268;
  struct StateT * v3262 = slot_184(v3256);
  return v3262;
}

struct StateT * slot_43(struct StateT * v939) {
  int v940 = v939->timer;
  int v947 = v940 + 1;
  v939->timer = v947;
  int * v942 = v939->regs;
  int v943 = v942[22];
  int v951 = (int)((unsigned int)v943 >> 25);
  v942[24] = v951;
  struct StateT * v945 = slot_44(v939);
  return v945;
}

struct StateT * slot_70(struct StateT * v1490) {
  int v1491 = v1490->timer;
  int v1499 = v1491 + 1;
  v1490->timer = v1499;
  int * v1493 = v1490->regs;
  int v1494 = v1493[7];
  int v1495 = v1493[21];
  int v1503 = v1494 ^ v1495;
  v1493[7] = v1503;
  struct StateT * v1497 = slot_71(v1490);
  return v1497;
}

struct StateT * slot_168(struct StateT * v3018) {
  int v3019 = v3018->timer;
  int v3027 = v3019 + 1;
  v3018->timer = v3027;
  int * v3021 = v3018->regs;
  int v3022 = v3021[23];
  int v3023 = v3021[24];
  int v3031 = v3022 | v3023;
  v3021[23] = v3031;
  struct StateT * v3025 = slot_169(v3018);
  return v3025;
}

struct StateT * slot_76(struct StateT * v1589) {
  int v1590 = v1589->timer;
  int v1598 = v1590 + 1;
  v1589->timer = v1598;
  int * v1592 = v1589->regs;
  int v1593 = v1592[5];
  int v1594 = v1592[8];
  int v1603 = v1593 + v1594;
  v1592[23] = v1603;
  struct StateT * v1596 = slot_77(v1589);
  return v1596;
}

struct StateT * slot_6(struct StateT * v111) {
  int v112 = v111->timer;
  int v121 = v112 + 1;
  v111->timer = v121;
  int * v114 = v111->regs;
  int v115 = v114[2];
  int v116 = v114[21];
  int * v117 = v111->mem;
  int v126 = (int)((unsigned int)(v115 + 24) >> 2);
  v117[v126] = v116;
  struct StateT * v119 = slot_7(v111);
  return v119;
}

struct StateT * slot_55(struct StateT * v1260) {
  int v1261 = v1260->timer;
  int v1269 = v1261 + 1;
  v1260->timer = v1269;
  int * v1263 = v1260->regs;
  int v1264 = v1263[19];
  int v1265 = v1263[28];
  int v1274 = v1264 + v1265;
  v1263[22] = v1274;
  struct StateT * v1267 = slot_56(v1260);
  return v1267;
}

struct StateT * slot_213(struct StateT * v1189) {
  int v1190 = v1189->timer;
  int v1193 = v1190 + 1;
  v1189->timer = v1193;
  return v1189;
}

struct StateT * slot_82(struct StateT * v1680) {
  int v1681 = v1680->timer;
  int v1689 = v1681 + 1;
  v1680->timer = v1689;
  int * v1683 = v1680->regs;
  int v1684 = v1683[21];
  int v1685 = v1683[24];
  int v1693 = v1684 | v1685;
  v1683[21] = v1693;
  struct StateT * v1687 = slot_83(v1680);
  return v1687;
}

struct StateT * slot_161(struct StateT * v2914) {
  int v2915 = v2914->timer;
  int v2922 = v2915 + 1;
  v2914->timer = v2922;
  int * v2917 = v2914->regs;
  int v2918 = v2917[21];
  int v2925 = v2918 << 13;
  v2917[21] = v2925;
  struct StateT * v2920 = slot_162(v2914);
  return v2920;
}

struct StateT * slot_185(struct StateT * v3285) {
  int v3286 = v3285->timer;
  int v3294 = v3286 + 1;
  v3285->timer = v3294;
  int * v3288 = v3285->regs;
  int v3289 = v3288[22];
  int v3290 = v3288[24];
  int v3298 = v3289 | v3290;
  v3288[22] = v3298;
  struct StateT * v3292 = slot_186(v3285);
  return v3292;
}

struct StateT * slot_91(struct StateT * v1818) {
  int v1819 = v1818->timer;
  int v1827 = v1819 + 1;
  v1818->timer = v1827;
  int * v1821 = v1818->regs;
  int v1822 = v1821[12];
  int v1823 = v1821[22];
  int v1831 = v1822 ^ v1823;
  v1821[12] = v1831;
  struct StateT * v1825 = slot_92(v1818);
  return v1825;
}

struct StateT * slot_58(struct StateT * v1309) {
  int v1310 = v1309->timer;
  int v1317 = v1310 + 1;
  v1309->timer = v1317;
  int * v1312 = v1309->regs;
  int v1313 = v1312[20];
  int v1320 = v1313 << 9;
  v1312[20] = v1320;
  struct StateT * v1315 = slot_59(v1309);
  return v1315;
}

struct StateT * slot_89(struct StateT * v1786) {
  int v1787 = v1786->timer;
  int v1795 = v1787 + 1;
  v1786->timer = v1795;
  int * v1789 = v1786->regs;
  int v1790 = v1789[16];
  int v1791 = v1789[20];
  int v1799 = v1790 ^ v1791;
  v1789[16] = v1799;
  struct StateT * v1793 = slot_90(v1786);
  return v1793;
}

struct StateT * slot_66(struct StateT * v1429) {
  int v1430 = v1429->timer;
  int v1437 = v1430 + 1;
  v1429->timer = v1437;
  int * v1432 = v1429->regs;
  int v1433 = v1432[23];
  int v1441 = (int)((unsigned int)v1433 >> 23);
  v1432[24] = v1441;
  struct StateT * v1435 = slot_67(v1429);
  return v1435;
}

struct StateT * slot_140(struct StateT * v2587) {
  int v2588 = v2587->timer;
  int v2595 = v2588 + 1;
  v2587->timer = v2595;
  int * v2590 = v2587->regs;
  int v2591 = v2590[21];
  int v2599 = (int)((unsigned int)v2591 >> 23);
  v2590[24] = v2599;
  struct StateT * v2593 = slot_141(v2587);
  return v2593;
}

struct StateT * slot_49(struct StateT * v1143) {
  int v1144 = v1143->timer;
  int v1152 = v1144 + 1;
  v1143->timer = v1152;
  int * v1146 = v1143->regs;
  int v1147 = v1146[9];
  int v1148 = v1146[20];
  int v1156 = v1147 ^ v1148;
  v1146[9] = v1156;
  struct StateT * v1150 = slot_50(v1143);
  return v1150;
}

struct StateT * slot_50(struct StateT * v1173) {
  int v1174 = v1173->timer;
  int v1182 = v1174 + 1;
  v1173->timer = v1182;
  int * v1176 = v1173->regs;
  int v1177 = v1176[18];
  int v1178 = v1176[21];
  int v1186 = v1177 ^ v1178;
  v1176[18] = v1186;
  struct StateT * v1180 = slot_51(v1173);
  return v1180;
}

struct StateT * slot_37(struct StateT * v735) {
  int v736 = v735->timer;
  int v743 = v736 + 1;
  v735->timer = v743;
  int * v738 = v735->regs;
  int v739 = v738[20];
  int v747 = (int)((unsigned int)v739 >> 25);
  v738[24] = v747;
  struct StateT * v741 = slot_38(v735);
  return v741;
}

struct StateT * slot_114(struct StateT * v2179) {
  int v2180 = v2179->timer;
  int v2188 = v2180 + 1;
  v2179->timer = v2188;
  int * v2182 = v2179->regs;
  int v2183 = v2182[29];
  int v2184 = v2182[9];
  int v2193 = v2183 + v2184;
  v2182[21] = v2193;
  struct StateT * v2186 = slot_115(v2179);
  return v2186;
}

struct StateT * slot_135(struct StateT * v2508) {
  int v2509 = v2508->timer;
  int v2517 = v2509 + 1;
  v2508->timer = v2517;
  int * v2511 = v2508->regs;
  int v2512 = v2511[15];
  int v2513 = v2511[28];
  int v2522 = v2512 + v2513;
  v2511[22] = v2522;
  struct StateT * v2515 = slot_136(v2508);
  return v2515;
}

struct StateT * slot_59(struct StateT * v1323) {
  int v1324 = v1323->timer;
  int v1332 = v1324 + 1;
  v1323->timer = v1332;
  int * v1326 = v1323->regs;
  int v1327 = v1326[20];
  int v1328 = v1326[24];
  int v1336 = v1327 | v1328;
  v1326[20] = v1336;
  struct StateT * v1330 = slot_60(v1323);
  return v1330;
}

struct StateT * slot_192(struct StateT * v3394) {
  int v3395 = v3394->timer;
  int v3403 = v3395 + 1;
  v3394->timer = v3403;
  int * v3397 = v3394->regs;
  int v3398 = v3397[31];
  int v3399 = v3397[23];
  int v3407 = v3398 ^ v3399;
  v3397[31] = v3407;
  struct StateT * v3401 = slot_193(v3394);
  return v3401;
}

struct StateT * slot_40(struct StateT * v837) {
  int v838 = v837->timer;
  int v845 = v838 + 1;
  v837->timer = v845;
  int * v840 = v837->regs;
  int v841 = v840[21];
  int v849 = (int)((unsigned int)v841 >> 25);
  v840[24] = v849;
  struct StateT * v843 = slot_41(v837);
  return v843;
}

struct StateT * slot_48(struct StateT * v1108) {
  int v1109 = v1108->timer;
  int v1117 = v1109 + 1;
  v1108->timer = v1117;
  int * v1111 = v1108->regs;
  int v1112 = v1111[23];
  int v1113 = v1111[24];
  int v1121 = v1112 | v1113;
  v1111[23] = v1121;
  struct StateT * v1115 = slot_49(v1108);
  return v1115;
}

struct StateT * slot_77(struct StateT * v1606) {
  int v1607 = v1606->timer;
  int v1614 = v1607 + 1;
  v1606->timer = v1614;
  int * v1609 = v1606->regs;
  int v1610 = v1609[20];
  int v1618 = (int)((unsigned int)v1610 >> 19);
  v1609[24] = v1618;
  struct StateT * v1612 = slot_78(v1606);
  return v1612;
}

struct StateT * slot_85(struct StateT * v1725) {
  int v1726 = v1725->timer;
  int v1734 = v1726 + 1;
  v1725->timer = v1734;
  int * v1728 = v1725->regs;
  int v1729 = v1728[22];
  int v1730 = v1728[24];
  int v1738 = v1729 | v1730;
  v1728[22] = v1738;
  struct StateT * v1732 = slot_86(v1725);
  return v1732;
}

struct StateT * slot_75(struct StateT * v1572) {
  int v1573 = v1572->timer;
  int v1581 = v1573 + 1;
  v1572->timer = v1581;
  int * v1575 = v1572->regs;
  int v1576 = v1575[17];
  int v1577 = v1575[19];
  int v1586 = v1576 + v1577;
  v1575[22] = v1586;
  struct StateT * v1579 = slot_76(v1572);
  return v1579;
}

struct StateT * slot_72(struct StateT * v1522) {
  int v1523 = v1522->timer;
  int v1531 = v1523 + 1;
  v1522->timer = v1531;
  int * v1525 = v1522->regs;
  int v1526 = v1525[5];
  int v1527 = v1525[23];
  int v1535 = v1526 ^ v1527;
  v1525[5] = v1535;
  struct StateT * v1529 = slot_73(v1522);
  return v1529;
}

struct StateT * slot_119(struct StateT * v2259) {
  int v2260 = v2259->timer;
  int v2268 = v2260 + 1;
  v2259->timer = v2268;
  int * v2262 = v2259->regs;
  int v2263 = v2262[20];
  int v2264 = v2262[24];
  int v2272 = v2263 | v2264;
  v2262[20] = v2272;
  struct StateT * v2266 = slot_120(v2259);
  return v2266;
}

struct StateT * slot_71(struct StateT * v1506) {
  int v1507 = v1506->timer;
  int v1515 = v1507 + 1;
  v1506->timer = v1515;
  int * v1509 = v1506->regs;
  int v1510 = v1509[17];
  int v1511 = v1509[22];
  int v1519 = v1510 ^ v1511;
  v1509[17] = v1519;
  struct StateT * v1513 = slot_72(v1506);
  return v1513;
}

struct StateT * slot_101(struct StateT * v1978) {
  int v1979 = v1978->timer;
  int v1986 = v1979 + 1;
  v1978->timer = v1986;
  int * v1981 = v1978->regs;
  int v1982 = v1981[21];
  int v1989 = v1982 << 18;
  v1981[21] = v1989;
  struct StateT * v1984 = slot_102(v1978);
  return v1984;
}

struct StateT * slot_108(struct StateT * v2082) {
  int v2083 = v2082->timer;
  int v2091 = v2083 + 1;
  v2082->timer = v2091;
  int * v2085 = v2082->regs;
  int v2086 = v2085[23];
  int v2087 = v2085[24];
  int v2095 = v2086 | v2087;
  v2085[23] = v2095;
  struct StateT * v2089 = slot_109(v2082);
  return v2089;
}

struct StateT * slot_116(struct StateT * v2213) {
  int v2214 = v2213->timer;
  int v2222 = v2214 + 1;
  v2213->timer = v2222;
  int * v2216 = v2213->regs;
  int v2217 = v2216[31];
  int v2218 = v2216[19];
  int v2227 = v2217 + v2218;
  v2216[23] = v2227;
  struct StateT * v2220 = slot_117(v2213);
  return v2220;
}

struct StateT * slot_93(struct StateT * v1850) {
  int v1851 = v1850->timer;
  int v1859 = v1851 + 1;
  v1850->timer = v1859;
  int * v1853 = v1850->regs;
  int v1854 = v1853[16];
  int v1855 = v1853[6];
  int v1864 = v1854 + v1855;
  v1853[20] = v1864;
  struct StateT * v1857 = slot_94(v1850);
  return v1857;
}

struct StateT * slot_88(struct StateT * v1770) {
  int v1771 = v1770->timer;
  int v1779 = v1771 + 1;
  v1770->timer = v1779;
  int * v1773 = v1770->regs;
  int v1774 = v1773[23];
  int v1775 = v1773[24];
  int v1783 = v1774 | v1775;
  v1773[23] = v1783;
  struct StateT * v1777 = slot_89(v1770);
  return v1777;
}

struct StateT * slot_96(struct StateT * v1901) {
  int v1902 = v1901->timer;
  int v1910 = v1902 + 1;
  v1901->timer = v1910;
  int * v1904 = v1901->regs;
  int v1905 = v1904[15];
  int v1906 = v1904[5];
  int v1915 = v1905 + v1906;
  v1904[23] = v1915;
  struct StateT * v1908 = slot_97(v1901);
  return v1908;
}

struct StateT * slot_45(struct StateT * v1006) {
  int v1007 = v1006->timer;
  int v1015 = v1007 + 1;
  v1006->timer = v1015;
  int * v1009 = v1006->regs;
  int v1010 = v1009[22];
  int v1011 = v1009[24];
  int v1019 = v1010 | v1011;
  v1009[22] = v1019;
  struct StateT * v1013 = slot_46(v1006);
  return v1013;
}

struct StateT * slot_134(struct StateT * v2491) {
  int v2492 = v2491->timer;
  int v2500 = v2492 + 1;
  v2491->timer = v2500;
  int * v2494 = v2491->regs;
  int v2495 = v2494[12];
  int v2496 = v2494[29];
  int v2505 = v2495 + v2496;
  v2494[21] = v2505;
  struct StateT * v2498 = slot_135(v2491);
  return v2498;
}

struct StateT * slot_175(struct StateT * v3132) {
  int v3133 = v3132->timer;
  int v3141 = v3133 + 1;
  v3132->timer = v3141;
  int * v3135 = v3132->regs;
  int v3136 = v3135[18];
  int v3137 = v3135[6];
  int v3146 = v3136 + v3137;
  v3135[22] = v3146;
  struct StateT * v3139 = slot_176(v3132);
  return v3139;
}

struct StateT * slot_69(struct StateT * v1474) {
  int v1475 = v1474->timer;
  int v1483 = v1475 + 1;
  v1474->timer = v1483;
  int * v1477 = v1474->regs;
  int v1478 = v1477[6];
  int v1479 = v1477[20];
  int v1487 = v1478 ^ v1479;
  v1477[6] = v1487;
  struct StateT * v1481 = slot_70(v1474);
  return v1481;
}

struct StateT * slot_202(struct StateT * v818) {
  int v819 = v818->timer;
  int v828 = v819 + 1;
  v818->timer = v828;
  int * v821 = v818->regs;
  int v822 = v821[10];
  int v823 = v821[18];
  int * v824 = v818->mem;
  int v833 = (int)((unsigned int)(v822 + 28) >> 2);
  v824[v833] = v823;
  struct StateT * v826 = slot_203(v818);
  return v826;
}

struct StateT * slot_188(struct StateT * v3330) {
  int v3331 = v3330->timer;
  int v3339 = v3331 + 1;
  v3330->timer = v3339;
  int * v3333 = v3330->regs;
  int v3334 = v3333[23];
  int v3335 = v3333[24];
  int v3343 = v3334 | v3335;
  v3333[23] = v3343;
  struct StateT * v3337 = slot_189(v3330);
  return v3337;
}

struct StateT * slot_138(struct StateT * v2557) {
  int v2558 = v2557->timer;
  int v2565 = v2558 + 1;
  v2557->timer = v2565;
  int * v2560 = v2557->regs;
  int v2561 = v2560[20];
  int v2568 = v2561 << 9;
  v2560[20] = v2568;
  struct StateT * v2563 = slot_139(v2557);
  return v2563;
}

struct StateT * slot_186(struct StateT * v3301) {
  int v3302 = v3301->timer;
  int v3309 = v3302 + 1;
  v3301->timer = v3309;
  int * v3304 = v3301->regs;
  int v3305 = v3304[23];
  int v3313 = (int)((unsigned int)v3305 >> 14);
  v3304[24] = v3313;
  struct StateT * v3307 = slot_187(v3301);
  return v3307;
}

struct StateT * slot_102(struct StateT * v1992) {
  int v1993 = v1992->timer;
  int v2001 = v1993 + 1;
  v1992->timer = v2001;
  int * v1995 = v1992->regs;
  int v1996 = v1995[21];
  int v1997 = v1995[24];
  int v2005 = v1996 | v1997;
  v1995[21] = v2005;
  struct StateT * v1999 = slot_103(v1992);
  return v1999;
}

struct StateT * slot_145(struct StateT * v2661) {
  int v2662 = v2661->timer;
  int v2670 = v2662 + 1;
  v2661->timer = v2670;
  int * v2664 = v2661->regs;
  int v2665 = v2664[22];
  int v2666 = v2664[24];
  int v2674 = v2665 | v2666;
  v2664[22] = v2674;
  struct StateT * v2668 = slot_146(v2661);
  return v2668;
}

struct StateT * slot_110(struct StateT * v2114) {
  int v2115 = v2114->timer;
  int v2123 = v2115 + 1;
  v2114->timer = v2123;
  int * v2117 = v2114->regs;
  int v2118 = v2117[29];
  int v2119 = v2117[21];
  int v2127 = v2118 ^ v2119;
  v2117[29] = v2127;
  struct StateT * v2121 = slot_111(v2114);
  return v2121;
}

struct StateT * slot_196(struct StateT * v608) {
  int v609 = v608->timer;
  int v618 = v609 + 1;
  v608->timer = v618;
  int * v611 = v608->regs;
  int v612 = v611[10];
  int v613 = v611[29];
  int * v614 = v608->mem;
  int v623 = (int)((unsigned int)(v612 + 4) >> 2);
  v614[v623] = v613;
  struct StateT * v616 = slot_197(v608);
  return v616;
}

struct StateT * slot_208(struct StateT * v1022) {
  int v1023 = v1022->timer;
  int v1032 = v1023 + 1;
  v1022->timer = v1032;
  int * v1025 = v1022->regs;
  int v1026 = v1025[2];
  int * v1027 = v1022->mem;
  int v1036 = (int)((unsigned int)(v1026 + 24) >> 2);
  int v1028 = v1027[v1036];
  v1025[21] = v1028;
  struct StateT * v1030 = slot_209(v1022);
  return v1030;
}

struct StateT * slot_172(struct StateT * v3082) {
  int v3083 = v3082->timer;
  int v3091 = v3083 + 1;
  v3082->timer = v3091;
  int * v3085 = v3082->regs;
  int v3086 = v3085[19];
  int v3087 = v3085[23];
  int v3095 = v3086 ^ v3087;
  v3085[19] = v3095;
  struct StateT * v3089 = slot_173(v3082);
  return v3089;
}

struct StateT * slot_131(struct StateT * v2442) {
  int v2443 = v2442->timer;
  int v2451 = v2443 + 1;
  v2442->timer = v2451;
  int * v2445 = v2442->regs;
  int v2446 = v2445[15];
  int v2447 = v2445[22];
  int v2455 = v2446 ^ v2447;
  v2445[15] = v2455;
  struct StateT * v2449 = slot_132(v2442);
  return v2449;
}

struct StateT * slot_8(struct StateT * v149) {
  int v150 = v149->timer;
  int v159 = v150 + 1;
  v149->timer = v159;
  int * v152 = v149->regs;
  int v153 = v152[2];
  int v154 = v152[23];
  int * v155 = v149->mem;
  int v164 = (int)((unsigned int)(v153 + 16) >> 2);
  v155[v164] = v154;
  struct StateT * v157 = slot_9(v149);
  return v157;
}

struct StateT * slot_180(struct StateT * v3211) {
  int v3212 = v3211->timer;
  int v3219 = v3212 + 1;
  v3211->timer = v3219;
  int * v3214 = v3211->regs;
  int v3215 = v3214[21];
  int v3223 = (int)((unsigned int)v3215 >> 14);
  v3214[24] = v3223;
  struct StateT * v3217 = slot_181(v3211);
  return v3217;
}

struct StateT * slot_203(struct StateT * v852) {
  int v853 = v852->timer;
  int v862 = v853 + 1;
  v852->timer = v862;
  int * v855 = v852->regs;
  int v856 = v855[2];
  int * v857 = v852->mem;
  int v866 = (int)((unsigned int)(v856 + 44) >> 2);
  int v858 = v857[v866];
  v855[8] = v858;
  struct StateT * v860 = slot_204(v852);
  return v860;
}

struct StateT * slot_190(struct StateT * v3362) {
  int v3363 = v3362->timer;
  int v3371 = v3363 + 1;
  v3362->timer = v3371;
  int * v3365 = v3362->regs;
  int v3366 = v3365[29];
  int v3367 = v3365[21];
  int v3375 = v3366 ^ v3367;
  v3365[29] = v3375;
  struct StateT * v3369 = slot_191(v3362);
  return v3369;
}

struct StateT * slot_157(struct StateT * v2854) {
  int v2855 = v2854->timer;
  int v2862 = v2855 + 1;
  v2854->timer = v2862;
  int * v2857 = v2854->regs;
  int v2858 = v2857[20];
  int v2866 = (int)((unsigned int)v2858 >> 19);
  v2857[24] = v2866;
  struct StateT * v2860 = slot_158(v2854);
  return v2860;
}

struct StateT * slot_200(struct StateT * v750) {
  int v751 = v750->timer;
  int v760 = v751 + 1;
  v750->timer = v760;
  int * v753 = v750->regs;
  int v754 = v753[10];
  int v755 = v753[5];
  int * v756 = v750->mem;
  int v765 = (int)((unsigned int)(v754 + 20) >> 2);
  v756[v765] = v755;
  struct StateT * v758 = slot_201(v750);
  return v758;
}

struct StateT * slot_173(struct StateT * v3098) {
  int v3099 = v3098->timer;
  int v3107 = v3099 + 1;
  v3098->timer = v3107;
  int * v3101 = v3098->regs;
  int v3102 = v3101[8];
  int v3103 = v3101[17];
  int v3112 = v3102 + v3103;
  v3101[20] = v3112;
  struct StateT * v3105 = slot_174(v3098);
  return v3105;
}

struct StateT * slot_149(struct StateT * v2722) {
  int v2723 = v2722->timer;
  int v2731 = v2723 + 1;
  v2722->timer = v2731;
  int * v2725 = v2722->regs;
  int v2726 = v2725[17];
  int v2727 = v2725[20];
  int v2735 = v2726 ^ v2727;
  v2725[17] = v2735;
  struct StateT * v2729 = slot_150(v2722);
  return v2729;
}

struct StateT * slot_5(struct StateT * v92) {
  int v93 = v92->timer;
  int v102 = v93 + 1;
  v92->timer = v102;
  int * v95 = v92->regs;
  int v96 = v95[2];
  int v97 = v95[20];
  int * v98 = v92->mem;
  int v107 = (int)((unsigned int)(v96 + 28) >> 2);
  v98[v107] = v97;
  struct StateT * v100 = slot_6(v92);
  return v100;
}

struct StateT * slot_104(struct StateT * v2023) {
  int v2024 = v2023->timer;
  int v2031 = v2024 + 1;
  v2023->timer = v2031;
  int * v2026 = v2023->regs;
  int v2027 = v2026[22];
  int v2034 = v2027 << 18;
  v2026[22] = v2034;
  struct StateT * v2029 = slot_105(v2023);
  return v2029;
}

struct StateT * slot_54(struct StateT * v1243) {
  int v1244 = v1243->timer;
  int v1252 = v1244 + 1;
  v1243->timer = v1252;
  int * v1246 = v1243->regs;
  int v1247 = v1246[18];
  int v1248 = v1246[29];
  int v1257 = v1247 + v1248;
  v1246[21] = v1257;
  struct StateT * v1250 = slot_55(v1243);
  return v1250;
}

struct StateT * slot_26(struct StateT * v467) {
  int v468 = v467->timer;
  int v475 = v468 + 1;
  v467->timer = v475;
  int * v470 = v467->regs;
  int v471 = v470[11];
  int v479 = v471 + -1947;
  v470[30] = v479;
  struct StateT * v473 = slot_27(v467);
  return v473;
}

struct StateT * slot_206(struct StateT * v954) {
  int v955 = v954->timer;
  int v964 = v955 + 1;
  v954->timer = v964;
  int * v957 = v954->regs;
  int v958 = v957[2];
  int * v959 = v954->mem;
  int v968 = (int)((unsigned int)(v958 + 32) >> 2);
  int v960 = v959[v968];
  v957[19] = v960;
  struct StateT * v962 = slot_207(v954);
  return v962;
}

struct StateT * slot_169(struct StateT * v3034) {
  int v3035 = v3034->timer;
  int v3043 = v3035 + 1;
  v3034->timer = v3043;
  int * v3037 = v3034->regs;
  int v3038 = v3037[8];
  int v3039 = v3037[20];
  int v3047 = v3038 ^ v3039;
  v3037[8] = v3047;
  struct StateT * v3041 = slot_170(v3034);
  return v3041;
}

struct StateT * slot_64(struct StateT * v1399) {
  int v1400 = v1399->timer;
  int v1407 = v1400 + 1;
  v1399->timer = v1407;
  int * v1402 = v1399->regs;
  int v1403 = v1402[22];
  int v1410 = v1403 << 9;
  v1402[22] = v1410;
  struct StateT * v1405 = slot_65(v1399);
  return v1405;
}

struct StateT * slot_170(struct StateT * v3050) {
  int v3051 = v3050->timer;
  int v3059 = v3051 + 1;
  v3050->timer = v3059;
  int * v3053 = v3050->regs;
  int v3054 = v3053[9];
  int v3055 = v3053[21];
  int v3063 = v3054 ^ v3055;
  v3053[9] = v3063;
  struct StateT * v3057 = slot_171(v3050);
  return v3057;
}

struct StateT * slot_14(struct StateT * v257) {
  int v258 = v257->timer;
  int v267 = v258 + 1;
  v257->timer = v267;
  int * v260 = v257->regs;
  int v261 = v260[12];
  int * v262 = v257->mem;
  int v271 = (int)((unsigned int)(v261 + 12) >> 2);
  int v263 = v262[v271];
  v260[9] = v263;
  struct StateT * v265 = slot_15(v257);
  return v265;
}

struct StateT * slot_53(struct StateT * v1226) {
  int v1227 = v1226->timer;
  int v1235 = v1227 + 1;
  v1226->timer = v1235;
  int * v1229 = v1226->regs;
  int v1230 = v1229[9];
  int v1231 = v1229[30];
  int v1240 = v1230 + v1231;
  v1229[20] = v1240;
  struct StateT * v1233 = slot_54(v1226);
  return v1233;
}

struct StateT * slot_80(struct StateT * v1651) {
  int v1652 = v1651->timer;
  int v1659 = v1652 + 1;
  v1651->timer = v1659;
  int * v1654 = v1651->regs;
  int v1655 = v1654[21];
  int v1663 = (int)((unsigned int)v1655 >> 19);
  v1654[24] = v1663;
  struct StateT * v1657 = slot_81(v1651);
  return v1657;
}

struct StateT * slot_44(struct StateT * v973) {
  int v974 = v973->timer;
  int v981 = v974 + 1;
  v973->timer = v981;
  int * v976 = v973->regs;
  int v977 = v976[22];
  int v984 = v977 << 7;
  v976[22] = v984;
  struct StateT * v979 = slot_45(v973);
  return v979;
}

struct StateT * slot_137(struct StateT * v2542) {
  int v2543 = v2542->timer;
  int v2550 = v2543 + 1;
  v2542->timer = v2550;
  int * v2545 = v2542->regs;
  int v2546 = v2545[20];
  int v2554 = (int)((unsigned int)v2546 >> 23);
  v2545[24] = v2554;
  struct StateT * v2548 = slot_138(v2542);
  return v2548;
}

struct StateT * slot_122(struct StateT * v2304) {
  int v2305 = v2304->timer;
  int v2313 = v2305 + 1;
  v2304->timer = v2313;
  int * v2307 = v2304->regs;
  int v2308 = v2307[21];
  int v2309 = v2307[24];
  int v2317 = v2308 | v2309;
  v2307[21] = v2317;
  struct StateT * v2311 = slot_123(v2304);
  return v2311;
}

struct StateT * slot_99(struct StateT * v1947) {
  int v1948 = v1947->timer;
  int v1956 = v1948 + 1;
  v1947->timer = v1956;
  int * v1950 = v1947->regs;
  int v1951 = v1950[20];
  int v1952 = v1950[24];
  int v1960 = v1951 | v1952;
  v1950[20] = v1960;
  struct StateT * v1954 = slot_100(v1947);
  return v1954;
}

struct StateT * slot_179(struct StateT * v3195) {
  int v3196 = v3195->timer;
  int v3204 = v3196 + 1;
  v3195->timer = v3204;
  int * v3198 = v3195->regs;
  int v3199 = v3198[20];
  int v3200 = v3198[24];
  int v3208 = v3199 | v3200;
  v3198[20] = v3208;
  struct StateT * v3202 = slot_180(v3195);
  return v3202;
}

struct StateT * slot_36(struct StateT * v699) {
  int v700 = v699->timer;
  int v708 = v700 + 1;
  v699->timer = v708;
  int * v702 = v699->regs;
  int v703 = v702[31];
  int v704 = v702[15];
  int v713 = v703 + v704;
  v702[23] = v713;
  struct StateT * v706 = slot_37(v699);
  return v706;
}

struct StateT * slot_57(struct StateT * v1294) {
  int v1295 = v1294->timer;
  int v1302 = v1295 + 1;
  v1294->timer = v1302;
  int * v1297 = v1294->regs;
  int v1298 = v1297[20];
  int v1306 = (int)((unsigned int)v1298 >> 23);
  v1297[24] = v1306;
  struct StateT * v1300 = slot_58(v1294);
  return v1300;
}

struct StateT * slot_62(struct StateT * v1368) {
  int v1369 = v1368->timer;
  int v1377 = v1369 + 1;
  v1368->timer = v1377;
  int * v1371 = v1368->regs;
  int v1372 = v1371[21];
  int v1373 = v1371[24];
  int v1381 = v1372 | v1373;
  v1371[21] = v1381;
  struct StateT * v1375 = slot_63(v1368);
  return v1375;
}

struct StateT * slot_22(struct StateT * v409) {
  int v410 = v409->timer;
  int v419 = v410 + 1;
  v409->timer = v419;
  int * v412 = v409->regs;
  int v413 = v412[11];
  int * v414 = v409->mem;
  int v423 = (int)((unsigned int)(v413 + 12) >> 2);
  int v415 = v414[v423];
  v412[18] = v415;
  struct StateT * v417 = slot_23(v409);
  return v417;
}

struct StateT * slot_139(struct StateT * v2571) {
  int v2572 = v2571->timer;
  int v2580 = v2572 + 1;
  v2571->timer = v2580;
  int * v2574 = v2571->regs;
  int v2575 = v2574[20];
  int v2576 = v2574[24];
  int v2584 = v2575 | v2576;
  v2574[20] = v2584;
  struct StateT * v2578 = slot_140(v2571);
  return v2578;
}

struct StateT * slot_23(struct StateT * v428) {
  int v429 = v428->timer;
  int v435 = v429 + 1;
  v428->timer = v435;
  int * v431 = v428->regs;
  v431[11] = 1634762752;
  struct StateT * v433 = slot_24(v428);
  return v433;
}

struct StateT * slot_153(struct StateT * v2786) {
  int v2787 = v2786->timer;
  int v2795 = v2787 + 1;
  v2786->timer = v2795;
  int * v2789 = v2786->regs;
  int v2790 = v2789[17];
  int v2791 = v2789[14];
  int v2800 = v2790 + v2791;
  v2789[20] = v2800;
  struct StateT * v2793 = slot_154(v2786);
  return v2793;
}

struct StateT * slot_2(struct StateT * v35) {
  int v36 = v35->timer;
  int v45 = v36 + 1;
  v35->timer = v45;
  int * v38 = v35->regs;
  int v39 = v38[2];
  int v40 = v38[9];
  int * v41 = v35->mem;
  int v50 = (int)((unsigned int)(v39 + 40) >> 2);
  v41[v50] = v40;
  struct StateT * v43 = slot_3(v35);
  return v43;
}

struct StateT * slot_86(struct StateT * v1741) {
  int v1742 = v1741->timer;
  int v1749 = v1742 + 1;
  v1741->timer = v1749;
  int * v1744 = v1741->regs;
  int v1745 = v1744[23];
  int v1753 = (int)((unsigned int)v1745 >> 19);
  v1744[24] = v1753;
  struct StateT * v1747 = slot_87(v1741);
  return v1747;
}

struct StateT * slot_129(struct StateT * v2410) {
  int v2411 = v2410->timer;
  int v2419 = v2411 + 1;
  v2410->timer = v2419;
  int * v2413 = v2410->regs;
  int v2414 = v2413[14];
  int v2415 = v2413[20];
  int v2423 = v2414 ^ v2415;
  v2413[14] = v2423;
  struct StateT * v2417 = slot_130(v2410);
  return v2417;
}

struct StateT * slot_158(struct StateT * v2869) {
  int v2870 = v2869->timer;
  int v2877 = v2870 + 1;
  v2869->timer = v2877;
  int * v2872 = v2869->regs;
  int v2873 = v2872[20];
  int v2880 = v2873 << 13;
  v2872[20] = v2880;
  struct StateT * v2875 = slot_159(v2869);
  return v2875;
}

struct StateT * slot_100(struct StateT * v1963) {
  int v1964 = v1963->timer;
  int v1971 = v1964 + 1;
  v1963->timer = v1971;
  int * v1966 = v1963->regs;
  int v1967 = v1966[21];
  int v1975 = (int)((unsigned int)v1967 >> 14);
  v1966[24] = v1975;
  struct StateT * v1969 = slot_101(v1963);
  return v1969;
}

struct StateT * slot_127(struct StateT * v2380) {
  int v2381 = v2380->timer;
  int v2388 = v2381 + 1;
  v2380->timer = v2388;
  int * v2383 = v2380->regs;
  int v2384 = v2383[23];
  int v2391 = v2384 << 7;
  v2383[23] = v2391;
  struct StateT * v2386 = slot_128(v2380);
  return v2386;
}

struct StateT * slot_13(struct StateT * v238) {
  int v239 = v238->timer;
  int v248 = v239 + 1;
  v238->timer = v248;
  int * v241 = v238->regs;
  int v242 = v241[12];
  int * v243 = v238->mem;
  int v252 = (int)((unsigned int)(v242 + 8) >> 2);
  int v244 = v243[v252];
  v241[8] = v244;
  struct StateT * v246 = slot_14(v238);
  return v246;
}

struct StateT * slot_111(struct StateT * v2130) {
  int v2131 = v2130->timer;
  int v2139 = v2131 + 1;
  v2130->timer = v2139;
  int * v2133 = v2130->regs;
  int v2134 = v2133[28];
  int v2135 = v2133[22];
  int v2143 = v2134 ^ v2135;
  v2133[28] = v2143;
  struct StateT * v2137 = slot_112(v2130);
  return v2137;
}

struct StateT * slot_109(struct StateT * v2098) {
  int v2099 = v2098->timer;
  int v2107 = v2099 + 1;
  v2098->timer = v2107;
  int * v2101 = v2098->regs;
  int v2102 = v2101[30];
  int v2103 = v2101[20];
  int v2111 = v2102 ^ v2103;
  v2101[30] = v2111;
  struct StateT * v2105 = slot_110(v2098);
  return v2105;
}

struct StateT * slot_174(struct StateT * v3115) {
  int v3116 = v3115->timer;
  int v3124 = v3116 + 1;
  v3115->timer = v3124;
  int * v3118 = v3115->regs;
  int v3119 = v3118[9];
  int v3120 = v3118[5];
  int v3129 = v3119 + v3120;
  v3118[21] = v3129;
  struct StateT * v3122 = slot_175(v3115);
  return v3122;
}

struct StateT * slot_147(struct StateT * v2692) {
  int v2693 = v2692->timer;
  int v2700 = v2693 + 1;
  v2692->timer = v2700;
  int * v2695 = v2692->regs;
  int v2696 = v2695[23];
  int v2703 = v2696 << 9;
  v2695[23] = v2703;
  struct StateT * v2698 = slot_148(v2692);
  return v2698;
}

struct StateT * slot_42(struct StateT * v904) {
  int v905 = v904->timer;
  int v913 = v905 + 1;
  v904->timer = v913;
  int * v907 = v904->regs;
  int v908 = v907[21];
  int v909 = v907[24];
  int v917 = v908 | v909;
  v907[21] = v917;
  struct StateT * v911 = slot_43(v904);
  return v911;
}

struct StateT * slot_163(struct StateT * v2944) {
  int v2945 = v2944->timer;
  int v2952 = v2945 + 1;
  v2944->timer = v2952;
  int * v2947 = v2944->regs;
  int v2948 = v2947[22];
  int v2956 = (int)((unsigned int)v2948 >> 19);
  v2947[24] = v2956;
  struct StateT * v2950 = slot_164(v2944);
  return v2950;
}

struct StateT * slot_184(struct StateT * v3271) {
  int v3272 = v3271->timer;
  int v3279 = v3272 + 1;
  v3271->timer = v3279;
  int * v3274 = v3271->regs;
  int v3275 = v3274[22];
  int v3282 = v3275 << 18;
  v3274[22] = v3282;
  struct StateT * v3277 = slot_185(v3271);
  return v3277;
}

struct StateT * slot_204(struct StateT * v885) {
  int v886 = v885->timer;
  int v895 = v886 + 1;
  v885->timer = v895;
  int * v888 = v885->regs;
  int v889 = v888[2];
  int * v890 = v885->mem;
  int v899 = (int)((unsigned int)(v889 + 40) >> 2);
  int v891 = v890[v899];
  v888[9] = v891;
  struct StateT * v893 = slot_205(v885);
  return v893;
}

struct StateT * slot_194(struct StateT * v3424) {
  int v3425 = v3424->timer;
  int v3436 = v3425 + 1;
  v3424->timer = v3436;
  int * v3427 = v3424->regs;
  int v3428 = v3427[11];
  int v3429 = v3427[13];
  bool v3440 = (v3428 ^ -2147483648) >= (v3429 ^ -2147483648);
  struct StateT * v3434;
  if (v3440) {
    struct StateT * v3430 = slot_33(v3424);
    v3434 = v3430;
  } else {
    struct StateT * v3432 = slot_195(v3424);
    v3434 = v3432;
  }
  return v3434;
}

struct StateT * slot_165(struct StateT * v2973) {
  int v2974 = v2973->timer;
  int v2982 = v2974 + 1;
  v2973->timer = v2982;
  int * v2976 = v2973->regs;
  int v2977 = v2976[22];
  int v2978 = v2976[24];
  int v2986 = v2977 | v2978;
  v2976[22] = v2986;
  struct StateT * v2980 = slot_166(v2973);
  return v2980;
}

struct StateT * snippet(struct StateT * v0) {
  struct StateT * v1 = slot_0(v0);
  return v1;
}

struct StateT * slot_117(struct StateT * v2230) {
  int v2231 = v2230->timer;
  int v2238 = v2231 + 1;
  v2230->timer = v2238;
  int * v2233 = v2230->regs;
  int v2234 = v2233[20];
  int v2242 = (int)((unsigned int)v2234 >> 25);
  v2233[24] = v2242;
  struct StateT * v2236 = slot_118(v2230);
  return v2236;
}

struct StateT * slot_90(struct StateT * v1802) {
  int v1803 = v1802->timer;
  int v1811 = v1803 + 1;
  v1802->timer = v1811;
  int * v1805 = v1802->regs;
  int v1806 = v1805[14];
  int v1807 = v1805[21];
  int v1815 = v1806 ^ v1807;
  v1805[14] = v1815;
  struct StateT * v1809 = slot_91(v1802);
  return v1809;
}

struct StateT * slot_11(struct StateT * v200) {
  int v201 = v200->timer;
  int v210 = v201 + 1;
  v200->timer = v210;
  int * v203 = v200->regs;
  int v204 = v203[12];
  int * v205 = v200->mem;
  int v214 = (int)((unsigned int)v204 >> 2);
  int v206 = v205[v214];
  v203[14] = v206;
  struct StateT * v208 = slot_12(v200);
  return v208;
}



/*****************************************
End of C Generated Code
*******************************************/

void init(struct StateT *s) {
  for (int i=0; i<NUM_REGS; i++) {
    s->regs[i] = 0;
  }
  s->regs[2] = 4 * MEM_SIZE;
  s->timer = 0;
  for (int i=0; i<MEM_SIZE; i++) {
    s->mem[i] = 0;
  }
}

int main(int argc, char* argv[]) {
  struct StateT s1, s2;
  init(&s1);
  init(&s2);
  
  // a10, 8 words written by the callee: the address is public
  s1.regs[10] = 0;
  s2.regs[10] = 0;
  // a11, 4 words read by the callee: the address is public
  s1.regs[11] = 32;
  s2.regs[11] = 32;
  // a12, 8 words read by the callee: the address is public
  s1.regs[12] = 48;
  s2.regs[12] = 48;
  
  // a11's contents, secret: a different draw in each state
  for (int i=0; i<4; i++) {
    s1.mem[8 + i] = secret(0, 20);
    s2.mem[8 + i] = secret(0, 20);
  }
  // a12's contents, secret: a different draw in each state
  for (int i=0; i<8; i++) {
    s1.mem[12 + i] = secret(0, 20);
    s2.mem[12 + i] = secret(0, 20);
  }
  struct StateT *s1_ = snippet(&s1);
  struct StateT *s2_ = snippet(&s2);
  //@ assert untainted_timer: !\tainted(s1_->timer==s2_->timer);
  koika_assert(s1_->timer==s2_->timer, "timing leak");
  return 0;
}